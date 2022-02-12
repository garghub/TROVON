static guint
get_tali_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint16 length;
length = tvb_get_letohs(tvb, offset + TALI_SYNC_LENGTH + TALI_OPCODE_LENGTH);
return length+TALI_HEADER_LENGTH;
}
static int
dissect_tali_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
tali_item = proto_tree_add_item(tree, hfi_tali, tvb, 0, TALI_HEADER_LENGTH, ENC_NA);
tali_tree = proto_item_add_subtree(tali_item, ett_tali);
proto_tree_add_string(tali_tree, &hfi_tali_sync_indicator, tvb, 0, TALI_SYNC_LENGTH, TALI_SYNC);
proto_tree_add_string(tali_tree, &hfi_tali_opcode_indicator, tvb, TALI_SYNC_LENGTH, TALI_OPCODE_LENGTH, opcode);
proto_tree_add_uint(tali_tree, &hfi_tali_length_indicator, tvb, TALI_SYNC_LENGTH + TALI_OPCODE_LENGTH, TALI_MSU_LENGTH, length);
}
if (length > 0) {
payload_tvb = tvb_new_subset_remaining(tvb, TALI_HEADER_LENGTH);
if (payload_tvb != NULL && !dissector_try_string(tali_dissector_table, opcode, payload_tvb, pinfo, tree, NULL)) {
call_data_dissector(payload_tvb, pinfo, tree);
}
}
return tvb_captured_length(tvb);
}
static int
dissect_tali(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, tali_desegment, TALI_HEADER_LENGTH,
get_tali_pdu_len, dissect_tali_pdu, data);
return tvb_captured_length(tvb);
}
static gboolean
dissect_tali_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
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
dissect_tali(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_tali(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_tali_sync_indicator,
&hfi_tali_opcode_indicator,
&hfi_tali_length_indicator
};
#endif
static gint *ett[] = {
&ett_tali,
&ett_tali_sync,
&ett_tali_opcode,
&ett_tali_msu_length
};
module_t *tali_module;
int proto_tali;
proto_tali = proto_register_protocol("Transport Adapter Layer Interface v1.0, RFC 3094", "TALI", "tali");
hfi_tali = proto_registrar_get_nth(proto_tali);
register_dissector("tali", dissect_tali, proto_tali);
proto_register_fields(proto_tali, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
tali_dissector_table = register_dissector_table("tali.opcode", "Tali OPCODE", proto_tali, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
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
heur_dissector_add("tcp", dissect_tali_heur, "Tali over TCP", "tali_tcp", hfi_tali->id, HEURISTIC_ENABLE);
}
