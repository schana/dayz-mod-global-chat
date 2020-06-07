modded class ChatLine {
    void ChatLine (Widget root_widget) {
        m_RootWidget = GetGame ().GetWorkspace ().CreateWidgets ("SchanaModGlobalChat/GUI/layouts/chatline.layout", root_widget);

        m_NameWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemSenderWidget"));
        m_TextWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemTextWidget"));

        m_NameWidget.SetTextExactSize (GetSchanaPartySettings ().GetSize ());
        m_TextWidget.SetTextExactSize (GetSchanaPartySettings ().GetSize ());
    }

    void SchanaUpdateSize () {
        m_NameWidget.SetTextExactSize (GetSchanaPartySettings ().GetSize ());
        m_TextWidget.SetTextExactSize (GetSchanaPartySettings ().GetSize ());
    }

    override void Set (ChatMessageEventParams params) {
        super.Set (params);

        int channel = params.param1;

        if (channel & CCSystem) {
            if (params.param2 != "") {
                SetColour (GetSchanaPartySettings ().GetColorServer ());
            } else {
                SetColour (GetSchanaPartySettings ().GetColorGlobal ());
            }
        } else if (channel & CCAdmin) {
            SetColour (GetSchanaPartySettings ().GetColorServer ());
        } else if (channel == 0 || channel & CCDirect) {
            SetColour (GetSchanaPartySettings ().GetColorDirect ());
        } else {
            SetColour (GetSchanaPartySettings ().GetColorServer ());
        }
    }
}