/*
 * entitycache.h
 *
 *  Created on: Nov 7, 2016
 *      Author: nullifiedcat
 */

#ifndef ENTITYCACHE_H_
#define ENTITYCACHE_H_

#include "fixsdk.h"
#include <mathlib/vector.h>

class IClientEntity;
class Color;
struct ESPStringCompound;

#define MAX_STRINGS 16

class CachedEntity {
public:
	CachedEntity();
	~CachedEntity();

	void Update(int idx);
	void AddESPString(Color color, Color background, const char* string, ...);
	ESPStringCompound GetESPString(int idx);
	template<typename T>
	T Var(unsigned offset);

	// Entity fields start here.

	bool m_bNULL;
	bool m_bDormant;
	int m_iClassID;
	float m_flDistance;

	int  m_iTeam;
	bool m_bAlivePlayer;
	bool m_bEnemy;
	int m_iMaxHealth;
	int m_iHealth;

	bool m_bIsVisible;
	unsigned long m_lLastSeen;


	// CBaseEntity
	/*int m_iTeamNum;
	bool m_bEnemy;

	// CBasePlayer
	bool m_bIsAlivePlayer;
	int m_fFlags;
	int m_lifeState;
	int m_iHealth;
	Vector m_vecViewOffset;

	// CBaseCombatCharacter
	int m_hActiveWeapon;
	IClientEntity* m_activeWeapon;

	// CTFPlayer
	bool m_bIsCritBoosted;
	bool m_bIsInvulnerable;

	int m_iCond;
	int m_iCondEx;
	int m_iCondEx2;
	int m_iCondEx3;
	float m_flChargeMeter;
	float m_flEnergyDrinkMeter;
	int m_nNumHealers;*/

	// Players, Buildings, Stickies


	// Entity fields end here.

	int m_IDX;
	IClientEntity* m_pEntity;
	ESPStringCompound* m_Strings;
	int m_nESPStrings;
	Vector m_ESPOrigin;
};

class EntityCache {
public:
	EntityCache();
	~EntityCache();

	void Update();
	CachedEntity* GetEntity(int idx);

	CachedEntity* m_pArray;
	int m_nMax;
};

extern EntityCache gEntityCache;

#endif /* ENTITYCACHE_H_ */
