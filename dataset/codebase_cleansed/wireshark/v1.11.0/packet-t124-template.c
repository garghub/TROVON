void
register_t124_ns_dissector(const char *nsKey, dissector_t dissector, int proto)
{
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissector, proto);
dissector_add_string("t124.ns", nsKey, dissector_handle);
}
void register_t124_sd_dissector(packet_info *pinfo _U_, guint32 channelId_param, dissector_t dissector, int proto)
{
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissector, proto);
dissector_add_uint("t124.sd", channelId_param, dissector_handle);
}
guint32 t124_get_last_channelId(void)
{
return channelId;
}
void t124_set_top_tree(proto_tree *tree)
{
top_tree = tree;
}
int dissect_DomainMCSPDU_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_t124_DomainMCSPDU(tvb, offset, &asn1_ctx, tree, hf_t124_DomainMCSPDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_t124_new(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
asn1_ctx_t asn1_ctx;
top_tree = parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "T.124");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_t124, tvb, 0, tvb_length(tvb), ENC_NA);
tree = proto_item_add_subtree(item, ett_t124);
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
dissect_t124_ConnectData(tvb, 0, &asn1_ctx, tree, hf_t124_ConnectData);
return tvb_length(tvb);
}
static void
dissect_t124(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
dissect_t124_new(tvb, pinfo, parent_tree, NULL);
}
static gboolean
dissect_t124_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
asn1_ctx_t asn1_ctx;
gboolean failed = FALSE;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
t124Identifier = NULL;
TRY {
(void) dissect_per_sequence(tvb, 0, &asn1_ctx, NULL, hf_t124_connectGCCPDU, -1, t124Heur_sequence);
} CATCH_BOUNDS_ERRORS {
failed = TRUE;
} ENDTRY;
if (!failed && ((t124Identifier != NULL) &&
(strcmp(t124Identifier, "0.0.20.124.0.1") == 0))) {
dissect_t124(tvb, pinfo, parent_tree);
return TRUE;
}
return FALSE;
}
void proto_register_t124(void) {
static hf_register_info hf[] = {
{ &hf_t124_ConnectData,
{ "ConnectData", "t124.ConnectData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_t124_connectGCCPDU,
{ "connectGCCPDU", "t124.connectGCCPDU",
FT_UINT32, BASE_DEC, VALS(t124_ConnectGCCPDU_vals), 0,
NULL, HFILL }},
{ &hf_t124_DomainMCSPDU_PDU,
{ "DomainMCSPDU", "t124.DomainMCSPDU",
FT_UINT32, BASE_DEC, VALS(t124_DomainMCSPDU_vals), 0,
NULL, HFILL }},
#include "packet-t124-hfarr.c"
};
static gint *ett[] = {
&ett_t124,
&ett_t124_connectGCCPDU,
#include "packet-t124-ettarr.c"
};
proto_t124 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_t124, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
t124_ns_dissector_table = register_dissector_table("t124.ns", "T.124 H.221 Non Standard Dissectors", FT_STRING, BASE_NONE);
t124_sd_dissector_table = register_dissector_table("t124.sd", "T.124 H.221 Send Data Dissectors", FT_UINT32, BASE_HEX);
new_register_dissector("t124", dissect_t124_new, proto_t124);
}
void
proto_reg_handoff_t124(void) {
register_ber_oid_dissector("0.0.20.124.0.1", dissect_t124, proto_t124, "Generic Conference Control");
heur_dissector_add("t125", dissect_t124_heur, proto_t124);
}
