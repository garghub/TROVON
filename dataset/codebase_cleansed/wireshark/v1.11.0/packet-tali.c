static guint
get_tali_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 length;
length = tvb_get_letohs(tvb, offset + TALI_SYNC_LENGTH + TALI_OPCODE_LENGTH);
return length+TALI_HEADER_LENGTH;
}
static void
dissect_tali_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
char opcode[TALI_OPCODE_LENGTH+1];
guint16 length;
tvbuff_t *payload_tvb = NULL;
proto_item *tali_item = NULL;
proto_tree *tali_tree = NULL;
tvb_memcpy(tvb, (guint8*)opcode, TALI_SYNC_LENGTH, TALI_OPCODE_LENGTH);
opcode[TALI_OPCODE_LENGTH] = '\0';
length = tvb_get_letohs(tvb, TALI_SYNC_LENGTH + TALI_OPCODE_LENGTH);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TALI");
col_set_str(pinfo->cinfo, COL_INFO, "");
col_append_fstr(pinfo->cinfo, COL_INFO, "[%s] packet, [%u] bytes in payload", opcode, length);
if (tree) {
tali_item = proto_tree_add_item(tree, proto_tali, tvb, 0, TALI_HEADER_LENGTH, ENC_NA);
tali_tree = proto_item_add_subtree(tali_item, ett_tali);
proto_tree_add_string(tali_tree, hf_tali_sync_indicator, tvb, 0, TALI_SYNC_LENGTH, TALI_SYNC);
proto_tree_add_string(tali_tree, hf_tali_opcode_indicator, tvb, TALI_SYNC_LENGTH, TALI_OPCODE_LENGTH, opcode);
proto_tree_add_uint(tali_tree, hf_tali_length_indicator, tvb, TALI_SYNC_LENGTH + TALI_OPCODE_LENGTH, TALI_MSU_LENGTH, length);
}
if (length > 0) {
payload_tvb = tvb_new_subset_remaining(tvb, TALI_HEADER_LENGTH);
if (payload_tvb != NULL && !dissector_try_string(tali_dissector_table, opcode, payload_tvb, pinfo, tree)) {
call_dissector(data_handle, payload_tvb, pinfo, tree);
}
}
}
static void
dissect_tali(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, tali_desegment, TALI_HEADER_LENGTH,
get_tali_pdu_len, dissect_tali_pdu);
}
static gboolean
dissect_tali_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
char opcode[TALI_OPCODE_LENGTH];
if (tvb_reported_length(tvb) < TALI_HEADER_LENGTH)
return FALSE;
if (tvb_strneql(tvb, 0, TALI_SYNC, TALI_SYNC_LENGTH) != 0)
return FALSE;
tvb_memcpy(tvb, (guint8*)opcode, TALI_SYNC_LENGTH, TALI_OPCODE_LENGTH);
if (strncmp(opcode, TALI_TEST, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_ALLO, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_PROH, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_PROA, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_MONI, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_MONA, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_SCCP, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_ISOT, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_MTP3, TALI_OPCODE_LENGTH) != 0 &&
strncmp(opcode, TALI_SAAL, TALI_OPCODE_LENGTH) != 0)
return FALSE;
dissect_tali(tvb, pinfo, tree);
return TRUE;
}
void
proto_register_tali(void)
{
static hf_register_info hf[] = {
{ &hf_tali_sync_indicator,
{ "Sync", "tali.sync", FT_STRING, BASE_NONE, NULL, 0x00, "TALI SYNC", HFILL }},
{ &hf_tali_opcode_indicator,
{ "Opcode", "tali.opcode", FT_STRING, BASE_NONE, NULL, 0x00, "TALI Operation Code", HFILL }},
{ &hf_tali_length_indicator,
{ "Length", "tali.msu_length", FT_UINT16, BASE_DEC, NULL, 0x00, "TALI MSU Length", HFILL }}
};
static gint *ett[] = {
&ett_tali,
&ett_tali_sync,
&ett_tali_opcode,
&ett_tali_msu_length
};
module_t *tali_module;
proto_tali = proto_register_protocol("Transport Adapter Layer Interface v1.0, RFC 3094", "TALI", "tali");
register_dissector("tali", dissect_tali, proto_tali);
proto_register_field_array(proto_tali, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tali_dissector_table = register_dissector_table("tali.opcode", "Tali OPCODE", FT_STRING, BASE_NONE);
tali_module = prefs_register_protocol(proto_tali, NULL);
prefs_register_bool_preference(tali_module, "reassemble",
"Reassemble TALI messages spanning multiple TCP segments",
"Whether the TALI dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&tali_desegment);
}
void
proto_reg_handoff_tali(void)
{
heur_dissector_add("tcp", dissect_tali_heur, proto_tali);
data_handle = find_dissector("data");
}
