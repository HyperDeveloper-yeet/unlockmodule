/* hi yes */

// this is cool hi roblox! 

#include <windows.h>
#include "yourrlua.hpp"


namespace Functions
{
  int LockModule(DWORD rL);
  int UnlockModule(DWORD rL)
}


int Functions::UnlockModule(DWORD rL)
{
	DWORD Module = *(DWORD*)r_lua_touserdata(rL, -1);
	r_lua_xmove(rL, RBLX->rL, 1);

	*(DWORD*)(Module + 240) = 1;

	return 0;
}

int Functions::LockModule(DWORD rL)
{
	DWORD Module = *(DWORD*)r_lua_touserdata(rL, -1);
	r_lua_xmove(rL, RBLX->rL, 1);
	*(DWORD*)(Module + 240) = 0;
	
	return 1;
}
