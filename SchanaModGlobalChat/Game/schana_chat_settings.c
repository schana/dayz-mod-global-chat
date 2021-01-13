class SchanaModGlobalChatSettings {
    private static string DIR = "$profile:SchanaModGlobalChat";
    private static string PATH = DIR + "\\settings.json";
    private static const int DEFAULT_SIZE = 20;
    static vector DEFAULTColorServer = "79 195 247"; // light blue 300

	private int size = DEFAULT_SIZE;
	string INFO = "If you wish to edit this you must copy the contents of the sample Color into the specificied color option, then make the perfered changes Google has a great color picker tool (https://www.google.com/search?q=color+picker) Use the RGB numbers having all R G and B equal 0 will also disable the custom colors if you really want black have them all at 1";
    ref SchanaColour ColorSample = new SchanaColour(DEFAULTColorServer);
    ref SchanaColour ColorDirect;
    ref SchanaColour ColorDirectPlayer;
   	ref SchanaColour ColorGlobal;
    ref SchanaColour ColorGlobalPlayer;
    ref SchanaColour ColorServer;
    ref SchanaColour ColorAlert;

	int GetColorDirect () {
		if (ColorDirect && ColorDirect.R != 0 && ColorDirect.G != 0 && ColorDirect.B != 0){
			return ColorDirect.Get ();
		} else {
			return GetSchanaModGlobalChatServerSettings ().GetColorDirect ();
		}
    }
	
    int GetColorDirectPlayer () {
		if (ColorDirectPlayer && ColorDirectPlayer.R != 0 && ColorDirectPlayer.G != 0 && ColorDirectPlayer.B != 0){
			return ColorDirectPlayer.Get ();
		} else {
			return GetSchanaModGlobalChatServerSettings ().GetColorDirectPlayer ();
		}
    }


    int GetColorGlobal () {
		if (ColorGlobal && ColorGlobal.R != 0 && ColorGlobal.G != 0 && ColorGlobal.B != 0){
			return ColorGlobal.Get ();
		} else {
			return GetSchanaModGlobalChatServerSettings ().GetColorGlobal ();
		}
    }
	
    int GetColorGlobalPlayer () {
		if (ColorGlobalPlayer && ColorGlobalPlayer.R != 0 && ColorGlobalPlayer.G != 0 && ColorGlobalPlayer.B != 0){
			return ColorGlobalPlayer.Get ();
		} else {
			return GetSchanaModGlobalChatServerSettings ().GetColorGlobalPlayer ();
		}
    }

    int GetColorServer () {
		if (ColorServer && ColorServer.R != 0 && ColorServer.G != 0 && ColorServer.B != 0){
			return ColorServer.Get ();
		} else {
			return GetSchanaModGlobalChatServerSettings ().GetColorServer ();
		}
    }

    int GetColorAlert () {
		if (ColorAlert && ColorAlert.R != 0 && ColorAlert.G != 0 && ColorAlert.B != 0){
			return ColorAlert.Get ();
		} else {
			return GetSchanaModGlobalChatServerSettings ().GetColorAlert ();
		}
    }


    int GetSize () {
        return size;
    }

    void SetSize (int new_size) {
        size = new_size;
        Save ();
    }

    void Save () {
        if (GetGame ().IsClient ()) {
            if (!FileExist (DIR)) {
                MakeDirectory (DIR);
            }
            JsonFileLoader<SchanaModGlobalChatSettings>.JsonSaveFile (PATH, this);
        }
    }
	
	void Debug (){
		
		Print (" = = = = = = Debug = = = = = = = = = = = = ");
	
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
		
		Print (" = = = = = = Server = = = = = = = = = = = = ");
		GetSchanaModGlobalChatServerSettings ().Debug ();
		
		
		Print (" = = = = = = End = = = = = = = = = = = = ");
	}
	
    static ref SchanaModGlobalChatSettings Get () {
        auto settings = new ref SchanaModGlobalChatSettings ();

        if (FileExist (PATH)) {
            JsonFileLoader<SchanaModGlobalChatSettings>.JsonLoadFile (PATH, settings);
        }

        LoadDefaultsIfMissing (settings);

        return settings;
    }

    static void LoadDefaultsIfMissing (SchanaModGlobalChatSettings settings) {
        if (settings.size == 0) {
            settings.size = DEFAULT_SIZE;
        }
    }
}

static ref SchanaModGlobalChatSettings g_SchanaModGlobalChatSettings;
static ref SchanaModGlobalChatSettings GetSchanaModGlobalChatSettings () {
    if (!g_SchanaModGlobalChatSettings) {
        g_SchanaModGlobalChatSettings = SchanaModGlobalChatSettings.Get ();
		if (GetGame ().IsClient ()){
			g_SchanaModGlobalChatSettings.Save ();
		}
    }
    return g_SchanaModGlobalChatSettings;
}