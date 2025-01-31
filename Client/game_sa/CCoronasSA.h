/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CCoronasSA.cpp
 *  PURPOSE:     Header file for corona entity manager class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include <game/CCoronas.h>
#include "CRegisteredCoronaSA.h"

#define FUNC_DoSunAndMoon           0x6FC5A0

#define MAX_CORONAS                 64 // ##SA##
#define MAX_CORONA_TEXTURES         9
#define ARRAY_CORONAS               0xC3E058 // also in CRegisteredCoronasSA.h ##SA##
#define ARRAY_CORONA_TEXTURES       0xC3E000 // ##SA##

class CCoronasSA : public CCoronas
{
private:
    CRegisteredCoronaSA* Coronas[MAX_CORONAS];
    unsigned char m_ucCoronaReflectionsEnabled;

public:
    CCoronasSA();
    ~CCoronasSA();

    CRegisteredCorona* GetCorona(DWORD ID);
    CRegisteredCorona* CreateCorona(DWORD Identifier, CVector* position);
    CRegisteredCorona* FindFreeCorona();
    CRegisteredCorona* FindCorona(DWORD Identifier);
    RwTexture*         GetTexture(eCoronaType type);

    void DisableSunAndMoon(bool bDisabled);

    void SetCoronaReflectionsEnabled(unsigned char ucEnabled);
    unsigned char GetCoronaReflectionsEnabled();
};
