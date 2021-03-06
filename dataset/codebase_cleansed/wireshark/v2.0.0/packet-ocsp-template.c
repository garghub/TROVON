static int
dissect_ocsp_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OCSP");
col_set_str(pinfo->cinfo, COL_INFO, "Request");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_ocsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_ocsp);
}
return dissect_ocsp_OCSPRequest(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static int
dissect_ocsp_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OCSP");
col_set_str(pinfo->cinfo, COL_INFO, "Response");
if(parent_tree){
item=proto_tree_add_item(parent_tree, proto_ocsp, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_ocsp);
}
return dissect_ocsp_OCSPResponse(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
void proto_register_ocsp(void) {
static hf_register_info hf[] = {
{ &hf_ocsp_responseType_id,
{ "ResponseType Id", "ocsp.responseType.id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-ocsp-hfarr.c"
};
static gint *ett[] = {
&ett_ocsp,
#include "packet-ocsp-ettarr.c"
};
proto_ocsp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ocsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ocsp(void) {
dissector_handle_t ocsp_request_handle;
dissector_handle_t ocsp_response_handle;
ocsp_request_handle = new_create_dissector_handle(dissect_ocsp_request, proto_ocsp);
ocsp_response_handle = new_create_dissector_handle(dissect_ocsp_response, proto_ocsp);
dissector_add_string("media_type", "application/ocsp-request", ocsp_request_handle);
dissector_add_string("media_type", "application/ocsp-response", ocsp_response_handle);
#include "packet-ocsp-dis-tab.c"
}
