static int
dissect_timestamp_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKIXTSP");
col_set_str(pinfo->cinfo, COL_INFO, "Reply");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_pkixtsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_pkixtsp);
}
return dissect_pkixtsp_TimeStampResp(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static int
dissect_timestamp_query(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKIXTSP");
col_set_str(pinfo->cinfo, COL_INFO, "Query");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_pkixtsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_pkixtsp);
}
return dissect_pkixtsp_TimeStampReq(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
void proto_register_pkixtsp(void) {
static hf_register_info hf[] = {
#include "packet-pkixtsp-hfarr.c"
};
static gint *ett[] = {
&ett_pkixtsp,
#include "packet-pkixtsp-ettarr.c"
};
proto_pkixtsp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkixtsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pkixtsp(void) {
dissector_handle_t timestamp_reply_handle;
dissector_handle_t timestamp_query_handle;
timestamp_reply_handle = new_create_dissector_handle(dissect_timestamp_reply, proto_pkixtsp);
dissector_add_string("media_type", "application/timestamp-reply", timestamp_reply_handle);
timestamp_query_handle = new_create_dissector_handle(dissect_timestamp_query, proto_pkixtsp);
dissector_add_string("media_type", "application/timestamp-query", timestamp_query_handle);
#include "packet-pkixtsp-dis-tab.c"
}
