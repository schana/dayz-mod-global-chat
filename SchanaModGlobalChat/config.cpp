class CfgPatches
{
	class SchanaModGlobalChat
	{
		requiredAddons[] = { "SchanaModGlobalChatDefine" };
	};
};

class CfgMods
{
	class SchanaModGlobalChat
	{
		name = "SchanaModGlobalChat";
		action = "https://github.com/schana/dayz-mod-global-chat";
		author = "schana";
		type = "mod";
		inputs = "SchanaModGlobalChat/Data/Inputs.xml";
		dependencies[] =
		{
			"Game",
			"Mission",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				files[] =
				{
					"SchanaModGlobalChat/Game"
				};
			};
			class missionScriptModule
			{
				files[] =
				{
					"SchanaModGlobalChat/Mission"
				};
			};
			class worldScriptModule
			{
				files[] =
				{
					"SchanaModGlobalChat/World"
				};
			};
		};
	};
};
