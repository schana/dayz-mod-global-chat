modded class ChatInputMenu extends UIScriptedMenu {
    override bool OnChange (Widget w, int x, int y, bool finished) {
        // super call manually because inheritance is weird
        if (UIScriptedWindow.GetActiveWindows ()) {
            for (int i = 0; i < UIScriptedWindow.GetActiveWindows ().Count (); i++) {
                if (UIScriptedWindow.GetActiveWindows ().GetElement (i).OnChange (w, x, y, finished)) { }
            }
        }

        if (!finished) return false;

        string text = m_edit_box.GetText ();

        if (text != "") {
            MissionGameplay mission = MissionGameplay.Cast (GetGame ().GetMission ());
            if (text.IndexOf ("#") != 0 && text.IndexOf ("!") != 0 && mission.SchanaGetIsChatChannelGlobal ()) {
                auto params = new Param1<string> (text);
                PlayerBase player = PlayerBase.Cast (GetGame ().GetPlayer ());
                GetGame ().RPCSingleParam (player, PlayerBase.SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL, params, true);
                GetGame ().ChatPlayer ("ᐅ " + text);
            } else {
                GetGame ().ChatPlayer (text);
            }
            if (!GetGame ().IsMultiplayer ()) {
                string name;
                GetGame ().GetPlayerName (name);
                ChatMessageEventParams chat_params = new ChatMessageEventParams (CCDirect, name, text, "");
                MissionGameplay.Cast (GetGame ().GetMission ()).m_Chat.Add (chat_params);
            }
        }

        m_close_timer.Run (0.1, this, "Close");

        GetUApi ().GetInputByName ("UAPersonView").Supress ();

        return true;
    }
}