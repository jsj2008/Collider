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

#include "s3eOSExec.h"
#include "IwGameScriptLua.h"
#include "lua/IwGameLuaGen.h"
#include "IwGameActor.h"
#include "IwGameScene.h"
#include "IwGameProgram.h"
#include "IwGameUI.h"
#include "IwGameBrush.h"
#include "IwGame.h"
#include "IwGameTemplates.h"

//
// LUA_FindProgram program-name (string), scene (object, optional)
//
static int LUA_FindProgram(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (lua_gettop(lua) < 1)
	{
        CIwGameError::LogError("Warning: program.find() not enough parameters, expected program-name (string), scene (object, optional)");
		lua_pushnil(lua);
		return 1;
	}

	IIwGameXomlResource* container = NULL;
	const char* name = NULL;

	// Get the programs name
	if (lua_isstring(lua, 1))
		name = lua_tostring(lua, 1);
	if (name == NULL)
	{
        CIwGameError::LogError("Warning: program.find() Invalid name for Param0");
		lua_pushnil(lua);
		return 1;
	}

	// Get the container scene
	if (count > 1)
	{
		if (lua_isuserdata(lua, 2))
			container = (IIwGameXomlResource*)lua_touserdata(lua, 2);
		if (container != NULL && container->getClassTypeHash() != CIwGameXomlNames::Scene_Hash)
		{
			CIwGameError::LogError("Warning: program.find() expected scene for Param1");
			lua_pushnil(lua);
			return 1;
		}
	}
	else
		container = (CIwGameScene*)lua->user_data;

	// Locate program
	CIwGameProgram* program = CIwGameProgramManager::FindProgram(name, container);
	if (program == NULL)
	{
        CIwGameError::LogError("Warning: program.find() progran not found - ", name);
		lua_pushnil(lua);
		return 1;
	}

	// Return the program
	lua_pushlightuserdata(lua, program);

    return 1;
}

//
// LUA_DestroyProgram(program (object))
//
static int LUA_DestroyProgram(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (lua_gettop(lua) < 1)
	{
        CIwGameError::LogError("Warning: program.destroy() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the object
	IIwGameXomlResource* object = NULL;
	if (lua_isuserdata(lua, 1))
		object = (IIwGameXomlResource*)lua_touserdata(lua, 1);
	if (object == NULL || object->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
		CIwGameError::LogError("Warning: program.destroy() invalid object, expected an program (object) in Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	object->getParent()->removeResource(object);

	lua_pushboolean(lua, true);
	return 1;
}

//
// LUA_StartProgram program (object)
//
static int LUA_StartProgram(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 1)
	{
        CIwGameError::LogError("Warning: program.start() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the program
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL || program->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
        CIwGameError::LogError("Warning: program.start() invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	program->start();

	lua_pushboolean(lua, true);
	return 1;
}

//
// LUA_RestartProgram program (object)
//
static int LUA_RestartProgram(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 1)
	{
        CIwGameError::LogError("Warning: program.restart() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the program
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL || program->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
        CIwGameError::LogError("Warning: program.restart() invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	program->restart();

	lua_pushboolean(lua, true);
	return 1;
}

//
// LUA_PauseProgram program (object)
//
static int LUA_PauseProgram(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 1)
	{
        CIwGameError::LogError("Warning: program.pause() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the program
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL || program->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
        CIwGameError::LogError("Warning: program.pause() invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	program->pause();

	lua_pushboolean(lua, true);
	return 1;
}

//
// LUA_NextCommand program (object)
//
static int LUA_NextCommand(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 1)
	{
        CIwGameError::LogError("Warning: program.nextCommand() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the program
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL || program->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
        CIwGameError::LogError("Warning: program.nextCommand() invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	program->nextCommand();

	lua_pushboolean(lua, true);
	return 1;
}

//
// LUA_PriorityProgram program (object)
//
static int LUA_PriorityProgram(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 1)
	{
        CIwGameError::LogError("Warning: program.setPriority() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the program
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL || program->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
        CIwGameError::LogError("Warning: program.setPriority() invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	program->getManager()->setPriorityProgram(program);

	lua_pushboolean(lua, true);
	return 1;
}

//
// LUA_GotoCommand program (object), command-name (string, optional)
//
static int LUA_GotoCommand(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 2)
	{
        CIwGameError::LogError("Warning: program.goto() not enough parameters, expected program (object), command-name (string, optional)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the program
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL || program->getClassTypeHash() == CIwGameXomlNames::Program_Hash)
	{
        CIwGameError::LogError("Warning: program.goto() invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the command name
	const char* cmd_name = NULL;
	if (lua_isstring(lua, 2))
		cmd_name = lua_tostring(lua, 2);
	if (cmd_name == NULL)
	{
		CIwGameError::LogError("Warning: program.goto() invalid target command name, expected string as Param1");
		lua_pushboolean(lua, false);
		return 1;
	}

	IIwGameCommandExecutor* command = program->findCommand(cmd_name);
	if (command != NULL)
		command->gotoCommand();
	else
		CIwGameError::LogError("Warning: program.goto() goto command that does not exist - ", cmd_name);

	lua_pushboolean(lua, true);
	return 1;
}



//
// LUA_isProgramRunning object (program)
//
static int LUA_isProgramRunning(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 1)
	{
        CIwGameError::LogError("Warning: program.running() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the target object
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL)
	{
        CIwGameError::LogError("Warning: program.running() Invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	lua_pushboolean(lua, program->isRunning());
    return 1;
}

//
// LUA_isProgramPaused object (program)
//
static int LUA_isProgramPaused(lua_State *lua)
{
	int count = lua_gettop(lua);
	if (count < 2)
	{
        CIwGameError::LogError("Warning: program.paused() not enough parameters, expected program (object)");
		lua_pushboolean(lua, false);
		return 1;
	}

	// Get the target object
	CIwGameProgram* program = NULL;
	if (lua_isuserdata(lua, 1))
		program = (CIwGameProgram*)lua_touserdata(lua, 1);
	if (program == NULL)
	{
        CIwGameError::LogError("Warning: program.paused() Invalid program object for Param0");
		lua_pushboolean(lua, false);
		return 1;
	}

	lua_pushboolean(lua, program->isPaused());
    return 1;
}


static const luaL_Reg g_programlib[] =
{
	{"find",			LUA_FindProgram}, 
	{"destroy",			LUA_DestroyProgram}, 
	{"start",			LUA_StartProgram}, 
	{"restart",			LUA_RestartProgram}, 
	{"pause",			LUA_PauseProgram}, 
	{"nextCommand",		LUA_NextCommand}, 
	{"setPriority",		LUA_PriorityProgram}, 
	{"goto",			LUA_GotoCommand}, 
	{"running",			LUA_isProgramRunning}, 
	{"paused",			LUA_isProgramPaused}, 
	{NULL, NULL}
};

LUALIB_API int luaopen_program(lua_State *L)
{
  luaL_register(L, "program", g_programlib);
  
  return 1;
}

