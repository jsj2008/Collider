// 
//
// IwGame - Cross Platform Multi-purpose Game Engine using the Marmalade SDK
//
// Developed by Matthew Hopwood of Pocketeers Limited - www.pocketeers.co.uk
//
// For updates, tutorials and more details check out my blog at www.drmop.com
//
// This code is provided free of charge and without any warranty whatsoever. The only restriction to its usage is that this header must remain intact and visible in all IwGame engine Inputs.
// If you use this engine in your product then please ensure that you credit IwGame's usage appropriately. Please see http://www.drmop.com/index.php/iwgame-engine/ for licensing details and support
//
//

#include "Marm/IwGamePlatformInputMarm.h"
#include "IwGameInput.h"
#include "s3eOSReadString.h"
#include "IwGeom.h"
#include "s3ePointer.h"
#include "s3eKeyboard.h"
#include "s3eCompass.h"
#include "s3eOSReadString.h"

// 
//
// Input callback handlers
//
//
//
// HandleMultiTouchButtonCB - For multitouch devices the system will call this callback when the user touches the screen. This callback is called once for each screen touch
// 
void HandleMultiTouchButtonCB(s3ePointerTouchEvent* event)
{
	if (IW_GAME_INPUT == NULL)
		return;

	// Check to see if the touch already exists
//	CIwGameTouch* touch = IW_GAME_INPUT->findTouch(event->m_TouchID);
	CIwGameTouch* touch = IW_GAME_INPUT->getTouch(event->m_TouchID);
	if (touch != NULL)
	{
		// Yes it does, so update the touch information
		touch->prev_active = touch->active;
		touch->active = event->m_Pressed != 0; 
		touch->x = event->m_x;
		touch->y = event->m_y;
		touch->px = event->m_x;
		touch->py = event->m_y;
		touch->id = event->m_TouchID;
	}
}
//
// HandleMultiTouchMotionCB - For multitouch devices the system will call this callback when the user moves their finger on the screen. This callback is called once for each screen touch
// 
void HandleMultiTouchMotionCB(s3ePointerTouchMotionEvent* event)
{
	if (IW_GAME_INPUT == NULL)
		return;

	// Check to see if the touch already exists
//	CIwGameTouch* touch = IW_GAME_INPUT->findTouch(event->m_TouchID);
	CIwGameTouch* touch = IW_GAME_INPUT->getTouch(event->m_TouchID);
	if (touch != NULL)
	{
		// Updates the touches positional information
		touch->x = event->m_x;
		touch->y = event->m_y;
	}
}
//
// HandleSingleTouchButtonCB - The system will call this callback when the user touches the screen
// 
void HandleSingleTouchButtonCB(s3ePointerEvent* event)
{
	if (IW_GAME_INPUT == NULL)
		return;

	CIwGameTouch* touch = IW_GAME_INPUT->getTouch(0);
	touch->prev_active = touch->active;
	touch->active = event->m_Pressed != 0;
	touch->x = event->m_x;
	touch->y = event->m_y;
	touch->px = event->m_x;
	touch->py = event->m_y;
}
//
// HandleSingleTouchMotionCB - The system will call this callback when the user moves their finger on the screen
// 
void HandleSingleTouchMotionCB(s3ePointerMotionEvent* event)
{
	if (IW_GAME_INPUT == NULL)
		return;

	CIwGameTouch* touch = IW_GAME_INPUT->getTouch(0);
	touch->x = event->m_x;
	touch->y = event->m_y;
}

//
// Marmalade Input system
//
bool	CIwGamePlatformInputMarm::isPointerAvailable()				{ return s3ePointerGetInt(S3E_POINTER_AVAILABLE) ? true : false; }
bool	CIwGamePlatformInputMarm::isMultiTouch()					{ return s3ePointerGetInt(S3E_POINTER_MULTI_TOUCH_AVAILABLE) ? true : false; }
bool	CIwGamePlatformInputMarm::isKeysAvailable()					{ return ((s3eKeyboardGetInt(S3E_KEYBOARD_HAS_KEYPAD) || s3eKeyboardGetInt(S3E_KEYBOARD_HAS_ALPHA))) ? true : false; }
bool	CIwGamePlatformInputMarm::isOSKeyboardAvailable()			{ return s3eOSReadStringAvailable() == S3E_TRUE; }
bool	CIwGamePlatformInputMarm::isAccelerometerAvailable()		{ return s3eAccelerometerGetInt(S3E_ACCELEROMETER_AVAILABLE) == S3E_TRUE; }
bool	CIwGamePlatformInputMarm::isCompassAvailable()				{ return s3eCompassAvailable() == S3E_TRUE; }
bool	CIwGamePlatformInputMarm::wasBackButtonReleased()			{ return (s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_RELEASED) == S3E_KEY_STATE_RELEASED || (s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_RELEASED) == S3E_KEY_STATE_RELEASED; }
bool	CIwGamePlatformInputMarm::wasMenuButtonReleased()			{ return (s3eKeyboardGetState(s3eKeyMenu) & S3E_KEY_STATE_RELEASED) == S3E_KEY_STATE_RELEASED || (s3eKeyboardGetState(s3eKeyAbsASK) & S3E_KEY_STATE_RELEASED) == S3E_KEY_STATE_RELEASED; }
void	CIwGamePlatformInputMarm::getAccelerometer(CIwVec3& data)	{ data.x = s3eAccelerometerGetX(); data.y = s3eAccelerometerGetY(); data.z = s3eAccelerometerGetZ(); }
float	CIwGamePlatformInputMarm::getCompassDirection()				{ return (float)s3eCompassGet(); }

int		CIwGamePlatformInputMarm::Init()
{
	// For multi-touch devices we handle touch and motion events using different callbacks
	if (isMultiTouch())
	{
		s3ePointerRegister(S3E_POINTER_TOUCH_EVENT, (s3eCallback)HandleMultiTouchButtonCB, NULL);
		s3ePointerRegister(S3E_POINTER_TOUCH_MOTION_EVENT, (s3eCallback)HandleMultiTouchMotionCB, NULL);
	}
	else
	{
		s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)HandleSingleTouchButtonCB, NULL);
		s3ePointerRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)HandleSingleTouchMotionCB, NULL);
	}

	return 1;
}

void	CIwGamePlatformInputMarm::Release()
{
	if (isPointerAvailable())
	{
		// Unregister the pointer system callbacks
		if (isMultiTouch())
		{
			s3ePointerUnRegister(S3E_POINTER_TOUCH_EVENT, (s3eCallback)HandleMultiTouchButtonCB);
			s3ePointerUnRegister(S3E_POINTER_TOUCH_MOTION_EVENT, (s3eCallback)HandleMultiTouchMotionCB);
		}
		else
		{
			s3ePointerUnRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)HandleSingleTouchButtonCB);
			s3ePointerUnRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)HandleSingleTouchMotionCB);
		}
	}
}

bool	CIwGamePlatformInputMarm::Update()
{
	// Update the pointer if it is available
	if (isPointerAvailable())
		s3ePointerUpdate();

	// Update key system if it is available
	s3eKeyboardUpdate();

	return true;
}

bool	CIwGamePlatformInputMarm::startAccelerometer()
{
	if (!isAccelerometerAvailable())
		return false;

	if (s3eAccelerometerStart() == S3E_RESULT_SUCCESS)
		return true;

	return false;
}

void	CIwGamePlatformInputMarm::stopAccelerometer()
{
	if (!isAccelerometerAvailable())
		return;

	s3eAccelerometerStop();
}

bool	CIwGamePlatformInputMarm::startCompass()
{
	if (!isCompassAvailable())
		return false;

	if (s3eCompassStart() == S3E_RESULT_SUCCESS)
		return true;

	return false;
}

void	CIwGamePlatformInputMarm::stopCompass()
{
	if (!isCompassAvailable())
		return;

	s3eCompassStop();
}

bool	CIwGamePlatformInputMarm::getCompassHeading(CIwVec3& data)
{
	s3eCompassHeading heading = { 0, 0, 0 };
	if (s3eCompassGetHeading(&heading) == S3E_RESULT_SUCCESS)
	{
		data.x = heading.m_X;
		data.y = heading.m_Y;
		data.z = heading.m_Z;

		return true;
	}

	return false;
}

const char*	CIwGamePlatformInputMarm::OsKeyboardRead(const char* prompt, const char* default_text, int flags)
{
	if (!isOSKeyboardAvailable())
		return NULL;

	switch (flags)
	{
	case ITH_Text:		flags = 0; break;
	case ITH_Number:	flags = S3E_OSREADSTRING_FLAG_NUMBER; break;
	case ITH_Password:	flags = S3E_OSREADSTRING_FLAG_PASSWORD; break;
	case ITH_Email:		flags = S3E_OSREADSTRING_FLAG_EMAIL; break;
	case ITH_URL:		flags = S3E_OSREADSTRING_FLAG_URL; break;
	}

	// Show on screen keyboard and return the input string
	if (default_text != NULL)
		return s3eOSReadStringUTF8WithDefault(prompt, default_text, flags);
	else
		return s3eOSReadStringUTF8(prompt, flags);
}

bool	CIwGamePlatformInputMarm::isKeyDown(int key)
{
	if (!isKeysAvailable())
		return false;

	return (s3eKeyboardGetState((s3eKey)key) & S3E_KEY_STATE_DOWN) == S3E_KEY_STATE_DOWN;
}

bool	CIwGamePlatformInputMarm::isKeyUp(int key)
{
	if (!isKeysAvailable())
		return false;

	return (s3eKeyboardGetState((s3eKey)key) & S3E_KEY_STATE_UP) == S3E_KEY_STATE_UP;
}

bool	CIwGamePlatformInputMarm::wasKeyPressed(int key)
{
	if (!isKeysAvailable())
		return false;

	return (s3eKeyboardGetState((s3eKey)key) & S3E_KEY_STATE_PRESSED) == S3E_KEY_STATE_PRESSED;
}

bool	CIwGamePlatformInputMarm::wasKeyReleased(int key)
{
	if (!isKeysAvailable())
		return false;

	return (s3eKeyboardGetState((s3eKey)key) & S3E_KEY_STATE_RELEASED) == S3E_KEY_STATE_RELEASED;
}



