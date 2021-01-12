modded class MissionGameplay extends MissionBase {
    private bool m_SchanaChatChannelIsGlobal = true;
	
	
	void MissionGameplay (){
        GetRPCManager ().AddRPC ("SchanaChat", "SchanaChatSettingsRPC", this, SingleplayerExecutionType.Both);
		}
	
	override void OnMissionStart (){
		super.OnMissionStart ();
		Print ("[SchanaChat] Requesting settings from server");
		GetRPCManager ().SendRPC ("SchanaChat", "SchanaChatSettingsRPC", new Param1< SchanaModGlobalChatServerSettings >( NULL ), true, NULL);
	}
	
	void SchanaChatSettingsRPC ( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		Param1< SchanaModGlobalChatServerSettings > data  //Player ID, Icon
		if ( !ctx.Read ( data ) ) return;
		
		Print ("[SchanaChat] Receiving settings from server");
		
		g_SchanaModGlobalChatServerSettings = data.param1;
	}

	

    override void OnUpdate (float timeslice) {
        super.OnUpdate (timeslice);

        if (GetUApi () && !m_UIManager.IsMenuOpen (MENU_CHAT_INPUT)) {
            UAInput inp = GetUApi ().GetInputByName ("UASchanaChatChannel");
            if (inp && inp.LocalPress ()) {
                m_SchanaChatChannelIsGlobal = !m_SchanaChatChannelIsGlobal;
                GetGame ().Chat ("Channel switched to " + SchanaGetChatChannelName (), "colorAction");
            }

            inp = GetUApi ().GetInputByName ("UASchanaChatSizeDown");
            if (inp && inp.LocalPress ()) {
                GetSchanaModGlobalChatSettings ().SetSize (Math.Max (12, GetSchanaModGlobalChatSettings ().GetSize () - 1));
                m_Chat.SchanaUpdateSize ();
            }

            inp = GetUApi ().GetInputByName ("UASchanaChatSizeUp");
            if (inp && inp.LocalPress ()) {
                GetSchanaModGlobalChatSettings ().SetSize (Math.Min (30, GetSchanaModGlobalChatSettings ().GetSize () + 1));
                m_Chat.SchanaUpdateSize ();
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