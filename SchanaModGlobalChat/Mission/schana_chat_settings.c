class SchanaModGlobalChatSettings {
    private static string DIR = "$profile:SchanaModGlobalChat";
    private static string PATH = DIR + "\\config.json";
    private static const int DEFAULT_SIZE = 20;
    private static const int DEFAULT_COLOR_DIRECT = 0xffffff; // white
    private static const int DEFAULT_COLOR_GLOBAL = 0xffd54f; // amber 300
    private static const int DEFAULT_COLOR_SERVER = 0x4fc3f7; // light blue 300
    private static const int DEFAULT_COLOR_ALERT = 0xff8a65; // deep orange 300

    private int size = DEFAULT_SIZE;
    private int color_direct = DEFAULT_COLOR_DIRECT;
    private int color_global = DEFAULT_COLOR_GLOBAL;
    private int color_server = DEFAULT_COLOR_SERVER;
    private int color_alert = DEFAULT_COLOR_ALERT;

    int GetSize () {
        return size;
    }

    void SetSize (int new_size) {
        size = new_size;
        Save ();
    }

    int GetColorDirect () {
        return GetColor (color_direct);
    }

    int GetColorGlobal () {
        return GetColor (color_global);
    }

    int GetColorServer () {
        return GetColor (color_server);
    }

    int GetColorAlert () {
        return GetColor (color_alert);
    }

    private int GetColor (int input_color) {
        return 0xff000000 | input_color;
    }

    void Save () {
        if (GetGame ().IsClient ()) {
            if (!FileExist (DIR)) {
                MakeDirectory (DIR);
            }
            JsonFileLoader<SchanaModGlobalChatSettings>.JsonSaveFile (PATH, this);
        }
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
        if (settings.color_direct == 0) {
            settings.color_direct = DEFAULT_COLOR_DIRECT;
        }
        if (settings.color_global == 0) {
            settings.color_global = DEFAULT_COLOR_GLOBAL;
        }
        if (settings.color_server == 0) {
            settings.color_server = DEFAULT_COLOR_SERVER;
        }
        if (settings.color_alert == 0) {
            settings.color_alert = DEFAULT_COLOR_ALERT;
        }
    }
}

static ref SchanaModGlobalChatSettings g_SchanaModGlobalChatSettings;
static ref SchanaModGlobalChatSettings GetSchanaModGlobalChatSettings () {
    if (g_Game.IsClient () && !g_SchanaModGlobalChatSettings) {
        g_SchanaModGlobalChatSettings = SchanaModGlobalChatSettings.Get ();
        g_SchanaModGlobalChatSettings.Save ();
    }
    return g_SchanaModGlobalChatSettings;
}