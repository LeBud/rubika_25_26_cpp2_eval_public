#include "PlayerLaser.h"

#include "ConsoleRenderer.h"
#include "PlayField.h"

#include <string>

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerLaser");
	sprite = RS_PlayerLaser;
}

PlayerLaser::~PlayerLaser()
{
	delete[] m_objType;
}

void PlayerLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y -= 1.f;
	if (pos.y < 0)
	{
		deleted = true;
	}

	for (auto alien : world.GetAliensObjects()) {
		if (pos.IntCmp(alien->pos)) {
			deleted = true;
			if (alien->DecreaseHealth()) {
				world.RemoveObject(alien);
			}
		}
	}
	
	if (deleted)
	{
		world.DespawnLaser(this);
		//delete this;
	}
}