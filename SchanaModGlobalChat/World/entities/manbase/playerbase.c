modded class PlayerBase extends ManBase {
    static const int SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL = -44301;

    override void OnRPC (PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL:
                {
                    Param1<string> chatParams;
                    if (!ctx.Read (chatParams)) return;
                    string name = sender.GetName ();
                    string text = name + " : " + chatParams.param1;
                    auto params = new Param1<string> (text);
                    GetGame ().RPCSingleParam (this, ERPCs.RPC_USER_ACTION_MESSAGE, params, true);
                    break;
                }
        }

        super.OnRPC (sender, rpc_type, ctx);
    }
}