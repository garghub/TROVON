int llc_sap_ev_activation_req(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
return ev->type == LLC_SAP_EV_TYPE_SIMPLE &&
ev->prim_type == LLC_SAP_EV_ACTIVATION_REQ ? 0 : 1;
}
int llc_sap_ev_rx_ui(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_CMD(pdu) &&
LLC_PDU_TYPE_IS_U(pdu) &&
LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_UI ? 0 : 1;
}
int llc_sap_ev_unitdata_req(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
return ev->type == LLC_SAP_EV_TYPE_PRIM &&
ev->prim == LLC_DATAUNIT_PRIM &&
ev->prim_type == LLC_PRIM_TYPE_REQ ? 0 : 1;
}
int llc_sap_ev_xid_req(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
return ev->type == LLC_SAP_EV_TYPE_PRIM &&
ev->prim == LLC_XID_PRIM &&
ev->prim_type == LLC_PRIM_TYPE_REQ ? 0 : 1;
}
int llc_sap_ev_rx_xid_c(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_CMD(pdu) &&
LLC_PDU_TYPE_IS_U(pdu) &&
LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_XID ? 0 : 1;
}
int llc_sap_ev_rx_xid_r(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_RSP(pdu) &&
LLC_PDU_TYPE_IS_U(pdu) &&
LLC_U_PDU_RSP(pdu) == LLC_1_PDU_CMD_XID ? 0 : 1;
}
int llc_sap_ev_test_req(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
return ev->type == LLC_SAP_EV_TYPE_PRIM &&
ev->prim == LLC_TEST_PRIM &&
ev->prim_type == LLC_PRIM_TYPE_REQ ? 0 : 1;
}
int llc_sap_ev_rx_test_c(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_CMD(pdu) &&
LLC_PDU_TYPE_IS_U(pdu) &&
LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_TEST ? 0 : 1;
}
int llc_sap_ev_rx_test_r(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
return ev->type == LLC_SAP_EV_TYPE_PDU && LLC_PDU_IS_RSP(pdu) &&
LLC_PDU_TYPE_IS_U(pdu) &&
LLC_U_PDU_RSP(pdu) == LLC_1_PDU_CMD_TEST ? 0 : 1;
}
int llc_sap_ev_deactivation_req(struct llc_sap *sap, struct sk_buff *skb)
{
struct llc_sap_state_ev *ev = llc_sap_ev(skb);
return ev->type == LLC_SAP_EV_TYPE_SIMPLE &&
ev->prim_type == LLC_SAP_EV_DEACTIVATION_REQ ? 0 : 1;
}
