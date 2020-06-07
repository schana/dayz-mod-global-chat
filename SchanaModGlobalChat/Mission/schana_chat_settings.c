class SchanaModGlobalChatSettings {
    private static string DIR = "$profile:SchanaModGlobalChat";
    private static string PATH = DIR + "\\config.json";

    private int size = 20;
    private int color_direct = 0xffffff;
    private int color_global = 0xffd54f;
    private int color_server = 0x4fc3f7;

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

        return settings;
    }
}

static ref SchanaModGlobalChatSettings g_SchanaModGlobalChatSettings;
static ref SchanaModGlobalChatSettings GetSchanaPartySettings () {
    if (g_Game.IsClient () && !g_SchanaModGlobalChatSettings) {
        g_SchanaModGlobalChatSettings = SchanaModGlobalChatSettings.Get ();
        g_SchanaModGlobalChatSettings.Save ();
    }
    return g_SchanaModGlobalChatSettings;
}