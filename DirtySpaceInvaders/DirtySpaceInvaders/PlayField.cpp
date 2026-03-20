#include "PlayField.h"

#include "GameObject.h"

void PlayField::Update()
{
	// Update list of active objects in the world
	auto tempGO = gameObjects;
	for (auto it : tempGO)
	{
		it->Update(*this);
	}
}

GameObject* PlayField::GetPlayerObject()
{
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](GameObject* in) { return (strcmp(in->m_objType, "PlayerShip") == 0); });
	if (it != gameObjects.end())
		return (*it);

	return nullptr;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		AlienLasers--;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		PlayerLasers--;

	AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		AlienLasers++;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		PlayerLasers++;

	RemoveObject(newObj);
}

void PlayField::AddObject(GameObject* newObj)
{
	gameObjects.push_back(newObj);
	if (strcmp(newObj->m_objType, "AlienShip") == 0)
		aliensObjects.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* in) { return (in == newObj); });
	gameObjects.erase(it);
	if (strcmp(newObj->m_objType, "AlienShip") == 0) {
		auto alienIt = std::find_if(aliensObjects.begin(), aliensObjects.end(), [&](GameObject* in) { return (in == newObj); });
		aliensObjects.erase(alienIt);
	}
	delete newObj;
}

std::vector<GameObject*>& PlayField::GetAliensObjects() {
	return aliensObjects;
}
