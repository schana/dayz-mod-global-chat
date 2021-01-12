class CfgPatches
{
	class SchanaModGlobalChatDefine
	{
		requiredVersion=0.1;
		requiredAddons[]={
		};
	};
};

class CfgMods
{
	class SchanaModGlobalChatDefine
	{
		dir="SchanaModGlobalChatDefine";
        name="SchanaModGlobalChatDefine";
        credits="schana, daemonforge";
        author="schana";
        authorID="0";
        version="0.1";
        extra=0;
        type="mod";
	    dependencies[]={ "Game", "World", "Mission"};
	    class defs
	    {
			class gameScriptModule
            {
				value = "";
                files[]={
					"SchanaModGlobalChatDefine/scripts/Common"
					};
            };
			
			class worldScriptModule
            {
                value="";
                files[]={ 
					"SchanaModGlobalChatDefine/scripts/Common"
				};
            };
			
	        class missionScriptModule
            {
                value="";
                files[]={
					"SchanaModGlobalChatDefine/scripts/Common"
				};
            };
        };
    };
};