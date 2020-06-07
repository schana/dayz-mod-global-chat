modded class Chat {
    override void Add (ChatMessageEventParams params) {
        int channel = params.param1;
        if ((channel == CCDirect || channel == 0) && params.param3.IndexOf ("ᐅ") == 0) {
            return;
        }
        super.Add (params);
    }

    void SchanaUpdateSize () {
        foreach (ChatLine line : m_Lines) {
            line.SchanaUpdateSize ();
        }
    }
}