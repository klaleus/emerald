Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy::
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_RematchNob::
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy::
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro:
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

Route115_EventScript_BirchIntro::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HOENN_STARTERS, Route115_EventScript_BirchExit
	msgbox Route115_Text_BirchIntro, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ge VAR_RESULT, 5, Route115_EventScript_BirchFailure
	setflag FLAG_RECEIVED_HOENN_STARTERS
	switch VAR_STARTER_MON
	case 0, Route115_EventScript_BirchStarterWasTreecko
	case 1, Route115_EventScript_BirchStarterWasTorchic
	case 2, Route115_EventScript_BirchStarterWasMudkip
	end

Route115_EventScript_BirchStarterWasTreecko::
	call Route115_EventScript_GiveTorchic
	call Route115_EventScript_GiveMudkip
	goto Route115_EventScript_BirchExit
	end

Route115_EventScript_BirchStarterWasTorchic::
	call Route115_EventScript_GiveTreecko
	call Route115_EventScript_GiveMudkip
	goto Route115_EventScript_BirchExit
	end

Route115_EventScript_BirchStarterWasMudkip::
	call Route115_EventScript_GiveTreecko
	call Route115_EventScript_GiveTorchic
	goto Route115_EventScript_BirchExit
	end

Route115_EventScript_GiveTreecko::
	givemon SPECIES_TREECKO, 10
	playfanfare MUS_OBTAIN_ITEM
	message Route115_Text_ReceiveTreecko
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	goto Route115_EventScript_Nickname
	end

Route115_EventScript_GiveTorchic::
	givemon SPECIES_TORCHIC, 10
	playfanfare MUS_OBTAIN_ITEM
	message Route115_Text_ReceiveTorchic
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	goto Route115_EventScript_Nickname
	end

Route115_EventScript_GiveMudkip::
	givemon SPECIES_MUDKIP, 10
	playfanfare MUS_OBTAIN_ITEM
	message Route115_Text_ReceiveMudkip
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	goto Route115_EventScript_Nickname
	end

Route115_EventScript_Nickname::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_Return
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return

Route115_EventScript_BirchFailure::
	msgbox Route115_Text_BirchFailure, MSGBOX_DEFAULT
	closemessage
	release
	end

Route115_EventScript_BirchExit::
	msgbox Route115_Text_BirchExit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route115_Text_BirchIntro:
	.string "Look who it is!\n"
	.string "Nice to see you, {PLAYER}.\p"
	.string "I'm out here doing some field work.\n"
	.string "That's what I do best, after all!\p"
	.string "Thanks again for saving me back on\n"
	.string "ROUTE 101.\p"
	.string "I want to give you the other two\n"
	.string "POKéMON from my briefcase.$"

Route115_Text_BirchFailure:
	.string "Come back for them when you have room\n"
	.string "for two more POKéMON in your party.$"

Route115_Text_ReceiveTreecko::
	.string "{PLAYER} received TREECKO!$"

Route115_Text_ReceiveTorchic::
	.string "{PLAYER} received TORCHIC!$"

Route115_Text_ReceiveMudkip::
	.string "{PLAYER} received MUDKIP!$"

Route115_Text_BirchExit:
	.string "Good luck filling in your POKéDEX!\n"
	.string "Say hello to my kid for me.\p"
	.string "(Now, what was I doing…?)$"