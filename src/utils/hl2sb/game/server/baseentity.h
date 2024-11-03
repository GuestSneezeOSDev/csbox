//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================//

#ifndef BASEENTITY_H
#define BASEENTITY_H
#ifdef _WIN32
#pragma once
#endif

struct edict_t;

// saverestore.h declarations
class CBaseEntity;
class Vector;

/* =========  CBaseEntity  ========

  All objects in the game are derived from this.

a list of all CBaseEntitys is kept in gEntList
================================ */

// creates an entity by string name, but does not spawn it
// If iForceEdictIndex is not -1, then it will use the edict by that index. If the index is
// invalid or there is already an edict using that index, it will error out.
CBaseEntity *CreateEntityByName( const char *className, int iForceEdictIndex = -1 );

// calls the spawn functions for an entity
extern int DispatchSpawn( CBaseEntity *pEntity );

#define SIZE_CBASEENTITY_SETMODEL 74
#define SIG_CBASEENTITY_SETMODEL                                                       \
    "\x56\x8B\x74\x24\x08\x57\x8B\xF9\x8B\x0D\x88\x39\x5D\x10\x8B\x01\x8B\x50\x08\x56" \
    "\xFF\xD2\x8B\x0D\x88\x39\x5D\x10\x8B\x11\x50\x8B\x42\x04\xFF\xD0\x85\xC0\x74\x22" \
    "\x8B\x0D\x88\x39\x5D\x10\x8B\x11\x50\x8B\x42\x24\xFF\xD0\x83\xF8\x01\x74\x0F\x56" \
    "\x68\xFC\x47\x41\x10\xFF\x15\x04\x52\x3E\x10\x83\xC4\x08"
#define MASK_CBASEENTITY_SETMODEL "xxxxxxxx??????xxxxxxxx??????xxxxxxxxxxxx??????xxxxxxxxxxxxxx???????????xxx"

void CBaseEntity_SetModel( CBaseEntity *pEntity, const char *szModelName );

// NOTE: Setting the abs origin or angles will cause the local origin + angles to be set also
#define SIZE_CBASEENTITY_SETABSORIGIN 67
#define SIG_CBASEENTITY_SETABSORIGIN                                                   \
    "\x83\xEC\x3C\x56\x57\x8B\xF1\xE8\x44\xB0\xFF\xFF\xD9\x86\x44\x02\x00\x00\x8B\x7C" \
    "\x24\x48\xD8\x1F\xDF\xE0\xF6\xC4\x44\x7A\x24\xD9\x86\x48\x02\x00\x00\xD8\x5F\x04" \
    "\xDF\xE0\xF6\xC4\x44\x7A\x14\xD9\x86\x4C\x02\x00\x00\xD8\x5F\x08\xDF\xE0\xF6\xC4" \
    "\x44\x0F\x8B\xDC\x00\x00\x00"
#define MASK_CBASEENTITY_SETABSORIGIN "xxxxxxx?????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

void CBaseEntity_SetAbsOrigin( CBaseEntity *pEntity, const Vector &origin );

#define SIZE_CBASEENTITY_INSTANCE 46
#define SIG_CBASEENTITY_INSTANCE                                                       \
    "\x8B\x44\x24\x04\x85\xC0\x75\x13\x8B\x0D\x68\x39\x5D\x10\x8B\x01\x8B\x50\x4C\x6A" \
    "\x00\xFF\xD2\x85\xC0\x74\x10\x8B\x40\x0C\x85\xC0\x74\x09\x8B\x10\x8B\xC8\x8B\x42" \
    "\x14\xFF\xE0\x33\xC0\xC3"
#define MASK_CBASEENTITY_INSTANCE "xxxxxxxx??????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

CBaseEntity *CBaseEntity_Instance( edict_t *pent );

void siginit_CBaseEntity( void );

#endif  // BASEENTITY_H
