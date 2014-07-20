jakko_mixon = Creature:new {
	objectName = "",
	customName = "Jakko Mixon",
	socialGroup = "townsperson",
	pvpFaction = "townsperson",
	faction = "townsperson",
	level = 10,
	chanceHit = 0.28,
	damageMin = 90,
	damageMax = 110,
	baseXp = 356,
	baseHAM = 810,
	baseHAMmax = 990,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK,
	optionsBitmask = 136,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_commoner_artisan_bith_male_01.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "blerx_tango_mission_target_convotemplate",
	attacks = {
	}
}
CreatureTemplates:addCreatureTemplate(jakko_mixon, "jakko_mixon")