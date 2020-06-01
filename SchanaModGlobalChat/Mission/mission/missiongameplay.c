modded class MissionGameplay extends MissionBase {
    private bool m_SchanaChatChannelIsGlobal = true;

    override void OnUpdate (float timeslice) {
        super.OnUpdate (timeslice);

        if (GetUApi ()) {
            UAInput inp = GetUApi ().GetInputByName ("UASchanaChatChannel");

            if (inp && inp.LocalPress ()) {
                m_SchanaChatChannelIsGlobal = !m_SchanaChatChannelIsGlobal;
                GetGame ().Chat ("Channel switched to " + SchanaGetChatChannelName (), "colorAction");
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