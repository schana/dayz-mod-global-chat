modded class MissionGameplay extends MissionBase {
    private bool m_SchanaChatChannelIsGlobal = true;

    override void OnUpdate (float timeslice) {
        super.OnUpdate (timeslice);

        if (GetUApi ()) {
            UAInput inp = GetUApi ().GetInputByName ("UASchanaChatChannel");
            if (inp && inp.LocalPress ()) {
                if (!m_UIManager.IsMenuOpen (MENU_CHAT_INPUT)) {
                    m_SchanaChatChannelIsGlobal = !m_SchanaChatChannelIsGlobal;
                    GetGame ().Chat ("Channel switched to " + SchanaGetChatChannelName (), "colorAction");
                }
            }

            inp = GetUApi ().GetInputByName ("UASchanaChatSizeDown");
            if (inp && inp.LocalPress ()) {
                if (!m_UIManager.IsMenuOpen (MENU_CHAT_INPUT)) {
                    GetSchanaPartySettings ().SetSize (Math.Max (8, GetSchanaPartySettings ().GetSize () - 1));
                    m_Chat.SchanaUpdateSize ();
                }
            }

            inp = GetUApi ().GetInputByName ("UASchanaChatSizeUp");
            if (inp && inp.LocalPress ()) {
                if (!m_UIManager.IsMenuOpen (MENU_CHAT_INPUT)) {
                    GetSchanaPartySettings ().SetSize (Math.Min (25, GetSchanaPartySettings ().GetSize () + 1));
                    m_Chat.SchanaUpdateSize ();
                }
            }
        }
    }

    bool SchanaGetIsChatChannelGlobal () {
        return m_SchanaChatChannelIsGlobal;
    }

    string SchanaGetChatChannelName () {
        if (m_SchanaChatChannelIsGlobal) {
            return "Global";
        } else {
            return "Direct";
        }
    }
}