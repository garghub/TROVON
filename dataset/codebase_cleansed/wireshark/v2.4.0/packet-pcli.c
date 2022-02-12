static proto_tree *
dissect_pcli_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int* offset)
{
guint32 cccid;
proto_tree *pcli_tree;
proto_item *pcli_item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCLI");
pcli_item = proto_tree_add_item(tree, proto_pcli, tvb, *offset, 4, ENC_NA);
pcli_tree = proto_item_add_subtree(pcli_item, ett_pcli);
proto_tree_add_item_ret_uint(pcli_tree, hf_pcli_cccid, tvb, *offset, 4, ENC_BIG_ENDIAN, &cccid);
(*offset) += 4;
if (pcli_summary_in_tree) {
proto_item_append_text(pcli_item, ", CCCID: %u", cccid);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "CCCID: %u", cccid);
return pcli_tree;
}
static void
dissect_pcli_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
tvbuff_t * next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint(pcli_subdissector_table, 0, next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
static int
dissect_pcli(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
dissect_pcli_common(tvb, pinfo, tree, &offset);
dissect_pcli_payload(tvb, pinfo, tree, offset);
return tvb_captured_length(tvb);
}
static int
dissect_pcli8(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *pcli_tree;
int offset = 0;
pcli_tree = dissect_pcli_common(tvb, pinfo, tree, &offset);
proto_tree_add_item(pcli_tree, hf_pcli_header, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dissect_pcli_payload(tvb, pinfo, tree, offset);
return tvb_captured_length(tvb);
}
static int
dissect_pcli12(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *pcli_tree;
int offset = 0;
pcli_tree = dissect_pcli_common(tvb, pinfo, tree, &offset);
proto_tree_add_item(pcli_tree, hf_pcli_timestamp, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
dissect_pcli_payload(tvb, pinfo, tree, offset);
return tvb_captured_length(tvb);
}
static int
dissect_pcli20(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *pcli_tree;
int offset = 0;
pcli_tree = dissect_pcli_common(tvb, pinfo, tree, &offset);
proto_tree_add_item(pcli_tree, hf_pcli_timestamp, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(pcli_tree, hf_pcli_case_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
dissect_pcli_payload(tvb, pinfo, tree, offset);
return tvb_captured_length(tvb);
}
static void
pcli_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "PCLI payload as");
}
static gpointer
pcli_value(packet_info *pinfo _U_)
{
return NULL;
}
void
proto_register_pcli(void)
{
static hf_register_info hf[] = {
{ &hf_pcli_cccid,
{ "CCCID", "pcli.cccid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Call Content Connection Identifier", HFILL }},
{ &hf_pcli_header,
{ "CCCID", "pcli.header", FT_UINT32, BASE_HEX, NULL, 0x0,
"Part of 8 byte header (including CCCID?)", HFILL }},
{ &hf_pcli_timestamp,
{ "Timestamp", "pcli.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pcli_case_id,
{ "Case ID", "pcli.case_id", FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_pcli,
};
module_t *pcli_module;
static build_valid_func pcli_payload_da_build_value[1] = {pcli_value};
static decode_as_value_t pcli_payload_da_values = {pcli_prompt, 1, pcli_payload_da_build_value};
static decode_as_t pcli_payload_da = {
"pcli", "PCLI payload", "pcli.payload", 1, 0,
&pcli_payload_da_values, NULL, NULL,
decode_as_default_populate_list,
decode_as_default_reset,
decode_as_default_change,
NULL,
};
proto_pcli = proto_register_protocol("Packet Cable Lawful Intercept", "PCLI", "pcli");
proto_pcli8 = proto_register_protocol_in_name_only("Packet Cable Lawful Intercept (8 byte CCCID)", "PCLI8 (8 byte CCCID)", "pcli8", proto_pcli, FT_PROTOCOL);
proto_pcli12 = proto_register_protocol_in_name_only("Packet Cable Lawful Intercept (timestamp)", "PCLI12 (timestamp)", "pcli12", proto_pcli, FT_PROTOCOL);
proto_pcli20 = proto_register_protocol_in_name_only("Packet Cable Lawful Intercept (timestamp, case ID)", "PCLI20 (timestamp, case ID)", "pcli20", proto_pcli, FT_PROTOCOL);
proto_register_field_array(proto_pcli,hf,array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
pcli_module = prefs_register_protocol(proto_pcli, NULL);
prefs_register_obsolete_preference(pcli_module, "udp_port");
prefs_register_bool_preference(pcli_module, "summary_in_tree",
"Show PCLI summary in protocol tree",
"Whether the PCLI summary line should be shown in the protocol tree",
&pcli_summary_in_tree);
pcli_subdissector_table = register_dissector_table(
"pcli.payload", "PCLI payload dissector",
proto_pcli, FT_UINT32, BASE_DEC);
register_decode_as(&pcli_payload_da);
}
void
proto_reg_handoff_pcli(void)
{
dissector_handle_t pcli_handle, pcli_handle8, pcli_handle12, pcli_handle20;
pcli_handle = create_dissector_handle(dissect_pcli, proto_pcli);
pcli_handle8 = create_dissector_handle(dissect_pcli8, proto_pcli8);
pcli_handle12 = create_dissector_handle(dissect_pcli12, proto_pcli12);
pcli_handle20 = create_dissector_handle(dissect_pcli20, proto_pcli20);
dissector_add_for_decode_as_with_preference("udp.port", pcli_handle);
dissector_add_for_decode_as_with_preference("udp.port", pcli_handle8);
dissector_add_for_decode_as_with_preference("udp.port", pcli_handle12);
dissector_add_for_decode_as_with_preference("udp.port", pcli_handle20);
}
