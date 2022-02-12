static void
dissect_credssp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_credssp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_credssp);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CredSSP");
col_clear(pinfo->cinfo, COL_INFO);
creds_type = -1;
dissect_TSRequest_PDU(tvb, pinfo, tree);
}
static gboolean
dissect_credssp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
asn1_ctx_t asn1_ctx;
int offset = 0;
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 length;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(tvb_length(tvb) > 7) {
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
if((ber_class == BER_CLASS_UNI) && (tag == BER_UNI_TAG_SEQUENCE) && (pc == TRUE)) {
offset = get_ber_length(tvb, offset, NULL, NULL);
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
if((ber_class == BER_CLASS_CON) && (tag == 0)) {
offset = get_ber_length(tvb, offset, NULL, NULL);
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
if((ber_class == BER_CLASS_UNI) && (tag == BER_UNI_TAG_INTEGER)) {
offset = get_ber_length(tvb, offset, &length, NULL);
if((length == 1) && (tvb_get_guint8(tvb, offset) == 2)) {
if (have_tap_listener(exported_pdu_tap)) {
exp_pdu_data_t *exp_pdu_data;
guint8 tags_bit_field;
tags_bit_field = EXP_PDU_TAG_IP_SRC_BIT + EXP_PDU_TAG_IP_DST_BIT + EXP_PDU_TAG_SRC_PORT_BIT+
EXP_PDU_TAG_DST_PORT_BIT + EXP_PDU_TAG_ORIG_FNO_BIT;
exp_pdu_data = load_export_pdu_tags(pinfo, "credssp", -1, &tags_bit_field, 1);
exp_pdu_data->tvb_captured_length = tvb_captured_length(tvb);
exp_pdu_data->tvb_reported_length = tvb_reported_length(tvb);
exp_pdu_data->pdu_tvb = tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
dissect_credssp(tvb, pinfo, parent_tree);
return TRUE;
}
}
}
}
}
return FALSE;
}
void proto_register_credssp(void) {
static hf_register_info hf[] =
{
{ &hf_credssp_TSPasswordCreds,
{ "TSPasswordCreds", "credssp.TSPasswordCreds",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_credssp_TSSmartCardCreds,
{ "TSSmartCardCreds", "credssp.TSSmartCardCreds",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_credssp_TSCredentials,
{ "TSCredentials", "credssp.TSCredentials",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-credssp-hfarr.c"
};
static gint *ett[] = {
&ett_credssp,
#include "packet-credssp-ettarr.c"
};
proto_credssp = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("credssp", dissect_credssp, proto_credssp);
proto_register_field_array(proto_credssp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("credssp", &credssp_heur_subdissector_list);
}
void proto_reg_handoff_credssp(void) {
heur_dissector_add("ssl", dissect_credssp_heur, proto_credssp);
exported_pdu_tap = find_tap_id(EXPORT_PDU_TAP_NAME_LAYER_7);
}
