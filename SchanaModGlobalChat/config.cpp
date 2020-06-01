class CfgPatches
{
	class SchanaModGlobalChat
	{
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
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
			"Mission",
			"World"
		};
		class defs
		{
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
