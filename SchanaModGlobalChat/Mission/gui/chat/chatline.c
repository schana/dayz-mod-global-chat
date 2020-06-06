modded class ChatLine {
    private const int GAME_TEXT_COLOUR = ARGB (255, 0xff, 0xd5, 0x4f);

    void ChatLine (Widget root_widget) {
        m_RootWidget = GetGame ().GetWorkspace ().CreateWidgets ("SchanaModGlobalChat/GUI/layouts/chatline.layout", root_widget);

        m_NameWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemSenderWidget"));
        m_TextWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemTextWidget"));
    }
}