class SchanaModGlobalChatServerSettings {
	
    protected static string DIR = "$profile:SchanaModGlobalChat";
    protected static string PATH = DIR + "\\server-settings.json";
    static vector DEFAULTColorDirect = "255 255 255"; // white
    static vector DEFAULTColorGlobal = "255 213 79"; // amber 300
    static vector DEFAULTColorServer = "79 195 247"; // light blue 300
    static vector DEFAULTColorAlert = "255 92 71"; // deep orange 300

    ref SchanaColour ColorDirect = new SchanaColour (DEFAULTColorDirect);
    ref SchanaColour ColorDirectPlayer = new SchanaColour (DEFAULTColorDirect);
   	ref SchanaColour ColorGlobal = new SchanaColour (DEFAULTColorGlobal);
    ref SchanaColour ColorGlobalPlayer = new SchanaColour (DEFAULTColorGlobal);
    ref SchanaColour ColorServer = new SchanaColour (DEFAULTColorServer);
    ref SchanaColour ColorAlert = new SchanaColour (DEFAULTColorAlert);


    int GetColorDirect () {
        return ColorDirect.Get ();
    }
	
    int GetColorDirectPlayer () {
        return ColorDirectPlayer.Get ();
    }


    int GetColorGlobal () {
        return ColorGlobal.Get ();
    }
	
    int GetColorGlobalPlayer () {
        return ColorGlobalPlayer.Get ();
    }

    int GetColorServer () {
        return ColorServer.Get ();
    }

    int GetColorAlert () {
        return ColorAlert.Get ();
    }

    void Save () {
        if (GetGame ().IsServer ()) {
            if (!FileExist (DIR)) {
                MakeDirectory (DIR);
            }
            JsonFileLoader<SchanaModGlobalChatServerSettings>.JsonSaveFile (PATH, this);
        }
    }

	void Load (){
		if (FileExist (PATH)) {
    	    JsonFileLoader<SchanaModGlobalChatServerSettings>.JsonLoadFile (PATH, this);
        }
		Save ();
	}
	
	void Debug (){
		Print ("[SchanaChat] ColorDirect");
		Print (ColorDirect.Debug ());
		Print ("[SchanaChat] ColorDirectPlayer");
		Print (ColorDirectPlayer.Debug ());
		Print ("[SchanaChat] ColorGlobal");
		Print (ColorGlobal.Debug ());
		Print ("[SchanaChat] ColorGlobalPlayer");
		Print (ColorGlobalPlayer.Debug ());
		Print ("[SchanaChat] ColorServer");
		Print (ColorServer.Debug ());
		Print ("[SchanaChat] ColorAlert");
		Print (ColorAlert.Debug ());
	}
}

class SchanaColour{
	int R;
	int G;
	int B;
	
	void SchanaColour (vector c){
		float r =c[0];
		float g =c[1];
		float b =c[2];
		R = r;
		G = g;
		B = b;
	}
	
	int Get (){
		return ARGB (255, R, G, B);
	}
	
	string Debug (){
		return "[SchanaChat][DebugColour]R: " + R + " G: " + G + " B: " +  B;
	}
}

ref SchanaModGlobalChatServerSettings g_SchanaModGlobalChatServerSettings;

static ref SchanaModGlobalChatServerSettings GetSchanaModGlobalChatServerSettings () {
    if (!g_SchanaModGlobalChatServerSettings) {
        g_SchanaModGlobalChatServerSettings = new ref SchanaModGlobalChatServerSettings;
		
		if ( GetGame ().IsServer ()){
			g_SchanaModGlobalChatServerSettings.Load ();
		}
    }
    return g_SchanaModGlobalChatServerSettings;
}