// 
//
// IwGame - Cross Platform Multi-purpose Game Engine using the Marmalade SDK
//
// Developed by Matthew Hopwood of Pocketeers Limited - www.pocketeers.co.uk
//
// For updates, tutorials and more details check out my blog at www.drmop.com
//
// This code is provided free of charge and without any warranty whatsoever. You must ensure that this whole notice is present in all files and derivatives, so the reader knows its origin.
// If you use this engine in your product then please ensure that you credit IwGame's usage appropriately. Please see http://www.drmop.com/index.php/iwgame-engine/ for licensing details and support
//
//

#include "IwGameVideo.h"
#include "IwGameActor.h"

//
//
//
//
// CIwGameVideo implementation
//
//
//
//
CIwGameVideo::~CIwGameVideo()
{
	SAFE_DELETE(File)
	SAFE_DELETE(VideoData)
}

bool CIwGameVideo::Init(const char* filename, bool preload, bool blocking, s3eVideoCodec codec)
{
	if (!s3eVideoIsCodecSupported(codec))
	{
		CIwGameError::LogError("Error: Video playback is not supported on this OS");
		return false;
	}

	Filename = filename;
	Codec = codec;
	File = new CIwGameFile(filename);

	if (preload)
		return Load(blocking);
	if (Rect.w == 0)
	{
		Rect.x = 0;
		Rect.y = 0;
		Rect.w = IwGxGetScreenWidth();
		Rect.h = IwGxGetScreenHeight();
	}

	return true;
}

bool CIwGameVideo::Init(char* video_data, uint32 video_data_len, s3eVideoCodec codec)
{
	if (!s3eVideoIsCodecSupported(codec))
		return false;

	VideoDataLen = video_data_len;
	VideoData = video_data;
	Codec = codec;
	State = State_Loaded;
	if (Rect.w == 0)
	{
		Rect.x = 0;
		Rect.y = 0;
		Rect.w = IwGxGetScreenWidth();
		Rect.h = IwGxGetScreenHeight();
	}

	return true;
}

int32 CIwGameVideo_FileRetrievedAsyncCallback(void* caller, void* data)
{
	CIwGameVideo* video = (CIwGameVideo*)data;
	video->FinishLoad();

	return 0;
}

bool CIwGameVideo::Load(bool blocking)
{
	if (!s3eVideoIsCodecSupported(Codec))
		return false;

	// Local video files are played from file and not pre-loaded, so only continue if remote based
	if (!CIwGameFile::isHttp(Filename.c_str(), Filename.GetLength()))
	{
		State = State_Loaded;
		return true;
	}

	// Video is file based
	if (File != NULL)
	{
		File->setFileAvailableCallback(CIwGameVideo_FileRetrievedAsyncCallback, this);
		if (File->Open(NULL, "rb", blocking))
			return true;
		else
			return false;
	}

	return false;
}

void CIwGameVideo::FinishLoad()
{
	if (File != NULL)
	{
		if (CIwGameFile::isHttp(File->getFilename().c_str(), File->getFilename().GetLength()))
		{
			if (File->isFileAvailable() && File->getError() == CIwGameFile::ErrorNone)
			{
				VideoDataLen = File->getContentLength();
				VideoData = new char [VideoDataLen];
				memcpy(VideoData, File->getContent(), VideoDataLen);
			}
			else
			{
				State = State_Invalid;
				return;
			}
		}
		else
		{
			VideoDataLen = File->getFileSize();
			VideoData = new char [VideoDataLen];
			File->Read(VideoData, VideoDataLen);
		}
		State = State_Loaded;
		SAFE_DELETE(File)
	}
}

bool CIwGameVideo::Play()
{
	if (State != State_Loaded)
		Load(true);
	if (State != State_Loaded)
		return false;

	bool success = false;

	if (VideoData != NULL)
		success = IW_GAME_VIDEO->PlayFromMemory(VideoData, VideoDataLen, Rect, RepeatCount, Codec);
	else
	if (!Filename.IsEmpty())
		success = IW_GAME_VIDEO->Play(Filename.c_str(), Rect, RepeatCount, Codec);

	if (success)
		IW_GAME_VIDEO->setVolume(Volume);

	return success;
}

bool CIwGameVideo::LoadFromXoml(IIwGameXomlResource* parent, bool load_children, CIwGameXmlNode* node)
{
	// Process image attributes
	CIwGameString* name = NULL;
	CIwGameString* location = NULL;
	bool preload = false;
	bool blocking = false;
	CIwGameString* condition = NULL;
	s3eVideoCodec codec = S3E_VIDEO_CODEC_MPEG4;
	int repeat = 1;

	CIwGameScene* scene = NULL;
	if (parent != NULL && parent->getClassTypeHash() == CIwGameXomlNames::Actor_Hash)
		scene = ((CIwGameActor*)parent)->getScene();
	else
	if (parent != NULL && parent->getClassTypeHash() == CIwGameXomlNames::Scene_Hash)
		scene = (CIwGameScene*)parent;

	for (CIwGameXmlNode::_AttribIterator it = node->attribs_begin(); it != node->attribs_end(); it++)
	{
		unsigned int name_hash = (*it)->getName().getHash();

		if (name_hash == CIwGameXomlNames::Name_Hash)
		{
			name = &(*it)->GetValue();
			setName(name->c_str());
		}
		else
		if (name_hash == CIwGameXomlNames::Tag_Hash)
			setTag((*it)->GetValue().c_str());
		else
		if (name_hash == CIwGameXomlNames::Location_Hash)
			location = &(*it)->GetValue();
		else
 		if (name_hash == CIwGameXomlNames::Preload_Hash)
			preload = (*it)->GetValueAsBool();
		else
 		if (name_hash == CIwGameXomlNames::Blocking_Hash)
			blocking = (*it)->GetValueAsBool();
		else
		if (name_hash == CIwGameXomlNames::Condition_Hash)
			condition = &(*it)->GetValue();
		else
 		if (name_hash == CIwGameXomlNames::Repeat_Hash)
			repeat = (*it)->GetValueAsInt();
		else
		if (name_hash == CIwGameXomlNames::Codec_Hash)
		{
			unsigned int format_hash = (*it)->GetValue().getHash();
			if (format_hash == IW_GAME_HASH("MPEG4"))
				codec = S3E_VIDEO_CODEC_MPEG4;
			else
			if (format_hash == IW_GAME_HASH("3GPP"))
				codec = S3E_VIDEO_CODEC_3GPP;
			else
			if (format_hash == IW_GAME_HASH("3GPP_VIDEO_H263"))
				codec = S3E_VIDEO_CODEC_3GPP_VIDEO_H263;
			else
			if (format_hash == IW_GAME_HASH("3GPP_VIDEO_H264"))
				codec = S3E_VIDEO_CODEC_3GPP_VIDEO_H264;
			else
			if (format_hash == IW_GAME_HASH("3GPP_AUDIO_AMR"))
				codec = S3E_VIDEO_CODEC_3GPP_AUDIO_AMR;
			else
			if (format_hash == IW_GAME_HASH("3GPP_AUDIO_AAC"))
				codec = S3E_VIDEO_CODEC_3GPP_AUDIO_AAC;
			else
			if (format_hash == IW_GAME_HASH("MPEG4_VIDEO_MPEG4"))
				codec = S3E_VIDEO_CODEC_MPEG4_VIDEO_MPEG4;
			else
			if (format_hash == IW_GAME_HASH("MPEG4_VIDEO_H264"))
				codec = S3E_VIDEO_CODEC_MPEG4_VIDEO_H264;
			else
			if (format_hash == IW_GAME_HASH("MPEG4_AUDIO_AAC"))
				codec = S3E_VIDEO_CODEC_MPEG4_AUDIO_AAC;
			else
			if (format_hash == IW_GAME_HASH("SWF"))
				codec = S3E_VIDEO_CODEC_SWF;
		}
	}

	if (location == NULL || name == NULL)
	{
		CIwGameError::LogError("Error: A video requires a location and a name to be specified");
		return false;
	}

	if (condition != NULL)
	{
		// Find the condition variable
		bool condition_not = false;
		CIwGameXomlVariable* var = NULL;
		if (*(condition->c_str()) == '!')
		{
			condition_not = true;
			CIwGameString cond = condition->c_str() + 1;
			var = CIwGameXomlVariable::GetVariable(cond, scene);
		}
		else
			var = CIwGameXomlVariable::GetVariable(*condition, scene);
		if (var != NULL)
		{
			bool res = var->isTrue();
			if (condition_not)
				res = !res;
			if (!res)
			{
				IW_GAME_XOML->setExitOnError(false);
				return false;
			}
		}
#if defined (_DEBUG)
		else
			CIwGameError::LogError("Warning: condition variable not found - ", condition->c_str());
#endif // _DEBUG 
	}

	// If codec is not supported or a video of the same name already exists then delete
	CIwGameVideo* video = (CIwGameVideo*)CIwGameXomlResourceManager::FindResource(Name.c_str(), CIwGameXomlNames::Video_Hash, scene);
	if (!s3eVideoIsCodecSupported(codec) || video != NULL)
	{
		IW_GAME_XOML->setExitOnError(false);
		return false;
	}

	// Initialise the video
	Init(location->c_str(), preload, blocking, codec);
	setRepeatCount(repeat);

	// If we are declared inside a scene then image is local to the scene
	if (scene != NULL)
		return scene->getResourceManager()->addResource(this);
	else
		return IW_GAME_GLOBAL_RESOURCES->getResourceManager()->addResource(this);

	return true;
}

//
//
//
//
// CIwGameVideoPlayer implementation
//
//
//
//
CDECLARE_SINGLETON(CIwGameVideoPlayer)

void CIwGameVideoPlayer::Init()
{

}

void CIwGameVideoPlayer::Release()
{
	Stop();
}

bool CIwGameVideoPlayer::isPlaying() const
{
	return s3eVideoIsPlaying() == S3E_TRUE;
}

void CIwGameVideoPlayer::setVolume(float volume)
{
	s3eVideoSetInt(S3E_VIDEO_VOLUME, (int)(volume * S3E_VIDEO_MAX_VOLUME));
}

float CIwGameVideoPlayer::getVolume() const
{
	return (float)s3eVideoGetInt(S3E_VIDEO_VOLUME) / S3E_VIDEO_MAX_VOLUME;
}

bool CIwGameVideoPlayer::Play(const char* filename, CIwRect& rect, int repeat_count, s3eVideoCodec codec)
{
	if (s3eVideoIsCodecSupported(codec))
	{
		s3eResult res = s3eVideoPlay(filename, repeat_count, rect.x, rect.y, rect.w, rect.h);
		if (res != S3E_RESULT_SUCCESS)
			CIwGameError::LogError("Error: Could not play the video file - ", filename);

		return res == S3E_RESULT_SUCCESS;
	}
	else
		CIwGameError::LogError("Error: Codec not suported - ", filename);

	return false;
}

bool CIwGameVideoPlayer::PlayFromMemory(char* mem, uint32 len, CIwRect& rect, int repeat_count, s3eVideoCodec codec)
{
	if (s3eVideoIsCodecSupported(codec))
		return s3eVideoPlayFromBuffer(mem, len, repeat_count, rect.x, rect.y, rect.w, rect.h) == S3E_RESULT_SUCCESS;

	return false;
}

void CIwGameVideoPlayer::Stop()
{
	if (isPlaying())
		s3eVideoStop();
}

void CIwGameVideoPlayer::Pause()
{
	s3eVideoPause();
}

void CIwGameVideoPlayer::Resume()
{
	s3eVideoResume();
}

int CIwGameVideoPlayer::getPlayPosition() const
{
	return s3eVideoGetInt(S3E_VIDEO_POSITION);
}

bool CIwGameVideoPlayer::isCodecSupported(s3eVideoCodec codec)
{
	return s3eVideoIsCodecSupported(codec) == S3E_TRUE;
}

bool CIwGameVideoPlayer::isCodecSupported(unsigned int codec_hash, bool &found)
{
	s3eVideoCodec codec;

	if (codec_hash == IW_GAME_HASH("MPEG4"))
		codec = S3E_VIDEO_CODEC_MPEG4;
	else
	if (codec_hash == IW_GAME_HASH("3GPP"))
		codec = S3E_VIDEO_CODEC_3GPP;
	else
	if (codec_hash == IW_GAME_HASH("3GPP_VIDEO_H263"))
		codec = S3E_VIDEO_CODEC_3GPP_VIDEO_H263;
	else
	if (codec_hash == IW_GAME_HASH("3GPP_VIDEO_H264"))
		codec = S3E_VIDEO_CODEC_3GPP_VIDEO_H264;
	else
	if (codec_hash == IW_GAME_HASH("3GPP_AUDIO_AMR"))
		codec = S3E_VIDEO_CODEC_3GPP_AUDIO_AMR;
	else
	if (codec_hash == IW_GAME_HASH("3GPP_AUDIO_AAC"))
		codec = S3E_VIDEO_CODEC_3GPP_AUDIO_AAC;
	else
	if (codec_hash == IW_GAME_HASH("MPEG4_VIDEO_MPEG4"))
		codec = S3E_VIDEO_CODEC_MPEG4_VIDEO_MPEG4;
	else
	if (codec_hash == IW_GAME_HASH("MPEG4_VIDEO_H264"))
		codec = S3E_VIDEO_CODEC_MPEG4_VIDEO_H264;
	else
	if (codec_hash == IW_GAME_HASH("MPEG4_AUDIO_AAC"))
		codec = S3E_VIDEO_CODEC_MPEG4_AUDIO_AAC;
	else
	if (codec_hash == IW_GAME_HASH("SWF"))
		codec = S3E_VIDEO_CODEC_SWF;
	else
	{
		found = false;
		return false;
	}

	found = true;

	return s3eVideoIsCodecSupported(codec) == S3E_TRUE;
}



