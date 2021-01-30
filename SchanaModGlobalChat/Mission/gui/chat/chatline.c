modded class ChatLine {
    void ChatLine (Widget root_widget) {
        m_RootWidget = GetGame ().GetWorkspace ().CreateWidgets ("SchanaModGlobalChat/GUI/layouts/chatline.layout", root_widget);

        m_NameWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemSenderWidget"));
        m_TextWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemTextWidget"));

        m_NameWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
        m_TextWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
    }

    void SchanaUpdateSize () {
        m_NameWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
        m_TextWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
    }
	
	
	
    override void Set (ChatMessageEventParams params) {
		
        super.Set (params);
        int channel = params.param1;
		int cindex = params.param3.IndexOf (" : ");
		string theName = params.param2;
		string theText = params.param3;
		if (params.param2 == "" && cindex > 0){
			theName = params.param3;
			theName = theName.Substring (0, cindex);
			cindex = cindex + 3;
			int len = theText.Length () - cindex;
			theText = theText.Substring (cindex,len);
		}
        if (channel & CCSystem) {
            if (params.param2 == "" && params.param3.IndexOf (" : ") > 0) {
				if (theName != theText){
					m_NameWidget.SetText (theName + ": ");
				}
				m_TextWidget.SetText (theText);
                SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer ());
            } else {
                SetColour (GetSchanaModGlobalChatSettings ().GetColorAlert ());
            }
        } else if (channel & CCAdmin) {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        } else if (channel == 0 || channel & CCDirect) {
			m_NameWidget.SetText (theName + ": ");
			m_TextWidget.SetText (theText);
            SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorDirect (), GetSchanaModGlobalChatSettings ().GetColorDirectPlayer ());
        } else {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        }
    }
	
	protected void SetSchanaColour (int tcolour, int pcolour)
	{
		m_NameWidget.SetColor (pcolour);
		m_TextWidget.SetColor (tcolour);
	}
}