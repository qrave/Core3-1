/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef DECLARERESIDENCECOMMAND_H_
#define DECLARERESIDENCECOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class DeclareresidenceCommand : public QueueCommand {
public:

	DeclareresidenceCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		Locker _lock(ghost);

		if (ghost == NULL)
			return INVALIDPARAMETERS;

		ManagedReference<SceneObject*> obj = creature->getParentRecursively(SceneObjectType::BUILDING);

		if (obj == NULL)
			return INVALIDTARGET;

		Locker _slock(obj, ghost);

		ManagedReference<BuildingObject*> declaredResidence = ghost->getDeclaredResidence();

		if (declaredResidence != NULL) {
			if (declaredResidence == obj) {
				creature->sendSystemMessage("@player_structure:already_residence"); //This building is already your residence.
				return GENERALERROR;
			}

			Time* cooldownTime = creature->getCooldownTime("declareresidence");

			if (cooldownTime != NULL && cooldownTime->isFuture()) {
				int hours = (int) round((float) abs((float) cooldownTime->miliDifference()) / 3600000.f); //Divided by 1 hour.

				StringIdChatParameter param("@player_structure:change_residence_time"); //You cannot change residence for %NO hours)
				param.setTO(String::valueOf(hours));

				creature->sendSystemMessage(param);

				return GENERALERROR;
			}
		}

		BuildingObject* building = cast<BuildingObject*>( obj.get());

		if (!ghost->isOwnedStructure(building)) {
			creature->sendSystemMessage("@player_structure:declare_must_be_owner"); //You must be the owner of the building to declare residence.
			return INVALIDTARGET;
		}

		ghost->setDeclaredResidence(building);

		creature->addCooldown("declareresidence", 86400000); //24 hours

		creature->sendSystemMessage("@player_structure:change_residence"); //You change your residence to this building.

		//TODO: Make a citizen of the city if in one.

		return SUCCESS;
	}

};

#endif //DECLARERESIDENCECOMMAND_H_
