/*
 * GuildObjectImplementation.cpp
 *
 *  Created on: Oct 27, 2010
 *      Author: crush
 */

#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/guild/GuildMemberInfo.h"

void GuildObjectImplementation::sendBaselinesTo(SceneObject* player) {
}

void GuildObjectImplementation::broadcastMessage(BaseMessage* msg) {
}

void GuildObjectImplementation::broadcastMessage(CreatureObject* player, BaseMessage* msg, bool sendSelf) {
}

void GuildObjectImplementation::addMember(uint64 playerID) {
	Locker locker(_this.get());

	GuildMemberInfo gmi(playerID);
	guildMembers.put(playerID, gmi);
}

void GuildObjectImplementation::removeMember(uint64 playerID) {
	Locker locker(_this.get());

	guildMembers.drop(playerID);
}

bool GuildObjectImplementation::hasMember(uint64 playerID) {
	Locker locker(_this.get());

	return guildMembers.contains(playerID);
}

bool GuildObjectImplementation::isInWaringGuild(CreatureObject* creature) {
	ManagedReference<GuildObject*> attackerGuild = creature->getGuildObject();

	if (attackerGuild != NULL) {

		try {
			if (isAtWarWith(attackerGuild->getObjectID())) {
				return true;
			}
		} catch (...) {
			error("unreported exception caught in bool GuildObjectImplementation::isInWaringGuild(CreatureObject* creature)");
		}

	}

	return false;
}

bool GuildObjectImplementation::isAtWarWith(unsigned long long guildoid) {
	waringGuildsMutex.rlock();

	bool res = waringGuilds.get(guildoid) == WAR_MUTUAL;

	waringGuildsMutex.runlock();

	return res;
}

uint64 GuildObjectImplementation::getMember(int index) {
	return guildMembers.get(index).getPlayerID();
}

GuildMemberInfo* GuildObjectImplementation::getMember(uint64 playerID) {
	Locker locker(_this.get());

	return &guildMembers.get(playerID);
}

bool GuildObjectImplementation::hasMailPermission(uint64 playerID) {
	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo gmi = guildMembers.get(playerID);

	return gmi.hasPermission(GuildObject::PERMISSION_MAIL);
}

bool GuildObjectImplementation::hasSponsorPermission(uint64 playerID) {
	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_SPONSOR);
}

bool GuildObjectImplementation::hasAcceptPermission(uint64 playerID) {
	Locker locker(_this.get());

	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_ACCEPT);
}

bool GuildObjectImplementation::hasKickPermission(uint64 playerID) {
	Locker locker(_this.get());

	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_KICK);
}

bool GuildObjectImplementation::hasDisbandPermission(uint64 playerID) {
	Locker locker(_this.get());

	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_DISBAND);
}

bool GuildObjectImplementation::hasNamePermission(uint64 playerID) {
	Locker locker(_this.get());

	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_NAME);
}

bool GuildObjectImplementation::hasTitlePermission(uint64 playerID) {
	Locker locker(_this.get());

	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_TITLE);
}

bool GuildObjectImplementation::hasWarPermission(uint64 playerID) {
	Locker locker(_this.get());

	if (!guildMembers.contains(playerID))
		return false;

	GuildMemberInfo* gmi = &guildMembers.get(playerID);

	return gmi->hasPermission(GuildObject::PERMISSION_WAR);
}
