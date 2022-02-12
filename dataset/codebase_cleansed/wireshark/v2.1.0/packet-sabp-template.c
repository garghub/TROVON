static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(sabp_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static void
dissect_sabp_cb_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *cbs_page_item;
proto_tree *subtree;
tvbuff_t *page_tvb, *unpacked_tvb;
int offset = 0;
int n;
guint8 nr_pages, len, cb_inf_msg_len;
nr_pages = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_sabp_no_of_pages, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(nr_pages > 15){
return;
}
for (n = 0; n < nr_pages; n++) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 83, ett_sabp_cbs_page, NULL,
"CB page %u data", n+1);
cbs_page_item = proto_tree_add_item(subtree, hf_sabp_cb_msg_inf_page, tvb, offset, 82, ENC_NA);
cb_inf_msg_len = tvb_get_guint8(tvb,offset+82);
page_tvb = tvb_new_subset_length(tvb, offset, cb_inf_msg_len);
unpacked_tvb = dissect_cbs_data(sms_encoding, page_tvb, subtree, pinfo, 0);
len = tvb_captured_length(unpacked_tvb);
if (unpacked_tvb != NULL){
if (tree != NULL){
proto_tree *cbs_page_subtree = proto_item_add_subtree(cbs_page_item, ett_sabp_cbs_page_content);
proto_tree_add_item(cbs_page_subtree, hf_sabp_cbs_page_content, unpacked_tvb, 0, len, ENC_UTF_8|ENC_NA);
}
}
offset = offset+82;
proto_tree_add_item(subtree, hf_sabp_cb_inf_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
static guint
get_sabp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint32 type_length;
int bit_offset;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = offset + 3;
bit_offset = offset<<3;
dissect_per_length_determinant(tvb, bit_offset, &asn1_ctx, NULL, -1, &type_length);
if (type_length < 128)
return type_length+4;
return type_length+5;
}
static int
dissect_sabp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *sabp_item = NULL;
proto_tree *sabp_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
sabp_item = proto_tree_add_item(tree, proto_sabp, tvb, 0, -1, ENC_NA);
sabp_tree = proto_item_add_subtree(sabp_item, ett_sabp);
dissect_SABP_PDU_PDU(tvb, pinfo, sabp_tree, NULL);
return tvb_captured_length(tvb);
}
static int
dissect_sabp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, gbl_sabp_desegment, 5,
get_sabp_pdu_len, dissect_sabp, data);
return tvb_captured_length(tvb);
}
void proto_register_sabp(void) {
static hf_register_info hf[] = {
{ &hf_sabp_no_of_pages,
{ "Number-of-Pages", "sabp.no_of_pages",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cb_msg_inf_page,
{ "CBS-Message-Information-Page", "sabp.cb_msg_inf_page",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cbs_page_content,
{ "CBS Page Content", "sabp.cb_page_content",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_sabp_cb_inf_len,
{ "CBS-Message-Information-Length", "sabp.cb_inf_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
#include "packet-sabp-hfarr.c"
};
static gint *ett[] = {
&ett_sabp,
&ett_sabp_e212,
&ett_sabp_cbs_data_coding,
&ett_sabp_bcast_msg,
&ett_sabp_cbs_serial_number,
&ett_sabp_cbs_new_serial_number,
&ett_sabp_cbs_page,
&ett_sabp_cbs_page_content,
#include "packet-sabp-ettarr.c"
};
proto_sabp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_sabp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sabp", dissect_sabp, proto_sabp);
register_dissector("sabp.tcp", dissect_sabp_tcp, proto_sabp);
sabp_ies_dissector_table = register_dissector_table("sabp.ies", "SABP-PROTOCOL-IES", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_extension_dissector_table = register_dissector_table("sabp.extension", "SABP-PROTOCOL-EXTENSION", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_proc_imsg_dissector_table = register_dissector_table("sabp.proc.imsg", "SABP-ELEMENTARY-PROCEDURE InitiatingMessage", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_proc_sout_dissector_table = register_dissector_table("sabp.proc.sout", "SABP-ELEMENTARY-PROCEDURE SuccessfulOutcome", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
sabp_proc_uout_dissector_table = register_dissector_table("sabp.proc.uout", "SABP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", proto_sabp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_sabp(void)
{
dissector_handle_t sabp_handle;
dissector_handle_t sabp_tcp_handle;
sabp_handle = find_dissector("sabp");
sabp_tcp_handle = find_dissector("sabp.tcp");
dissector_add_uint("udp.port", 3452, sabp_handle);
dissector_add_uint("tcp.port", 3452, sabp_tcp_handle);
dissector_add_uint("sctp.ppi", SABP_PAYLOAD_PROTOCOL_ID, sabp_handle);
#include "packet-sabp-dis-tab.c"
}
