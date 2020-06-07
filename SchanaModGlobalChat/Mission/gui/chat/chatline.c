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

        if (channel & CCSystem) {
            if (params.param2 != "") {
                SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
            } else {
                SetColour (GetSchanaModGlobalChatSettings ().GetColorGlobal ());
            }
        } else if (channel & CCAdmin) {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        } else if (channel == 0 || channel & CCDirect) {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorDirect ());
        } else {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        }
    }
}