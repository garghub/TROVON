static void
starteam_init(void)
{
iPreviousFrameNumber = -1;
}
static int
dissect_starteam(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "StarTeam");
if(iPreviousFrameNumber != (gint) pinfo->num){
col_clear(pinfo->cinfo, COL_INFO);
} else {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
}
iPreviousFrameNumber = pinfo->num;
if(tvb_captured_length(tvb) >= 16){
guint32 iCommand = 0;
gboolean bRequest = FALSE;
if(tvb_get_ntohl(tvb, offset + 0) == STARTEAM_MAGIC){
bRequest = FALSE;
col_append_fstr(pinfo->cinfo, COL_INFO, "Reply: %d bytes", tvb_reported_length(tvb));
} else if(tvb_captured_length_remaining(tvb, offset) >= 28 && tvb_get_ntohl(tvb, offset + 20) == STARTEAM_MAGIC){
bRequest = TRUE;
if(tvb_captured_length_remaining(tvb, offset) >= 66){
iCommand = tvb_get_letohl(tvb, offset + 62);
}
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(iCommand, &starteam_opcode_vals_ext, "Unknown (0x%02x)"));
}
if(tree){
proto_tree *starteam_tree;
proto_tree *starteamroot_tree;
proto_item *ti;
ti = proto_tree_add_item(tree, proto_starteam, tvb, offset, -1, ENC_NA);
if (bRequest) proto_item_append_text(ti, " (%s)",
val_to_str_ext(iCommand, &starteam_opcode_vals_ext, "Unknown (0x%02x)"));
starteamroot_tree = proto_item_add_subtree(ti, ett_starteam);
if(bRequest){
if(tvb_reported_length_remaining(tvb, offset) >= 20){
starteam_tree = proto_tree_add_subtree(starteamroot_tree, tvb, offset, 20, ett_starteam_mdh, NULL, STARTEAM_TEXT_MDH);
proto_tree_add_item(starteam_tree, hf_starteam_mdh_session_tag, tvb, offset + 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_mdh_ctimestamp, tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_mdh_flags, tvb, offset + 8, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_mdh_keyid, tvb, offset + 12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_mdh_reserved, tvb, offset + 16, 4, ENC_LITTLE_ENDIAN);
offset += 20;
}
}
if(tvb_reported_length_remaining(tvb, offset) >= 16){
starteam_tree = proto_tree_add_subtree(starteamroot_tree, tvb, offset, 16, ett_starteam_ph, NULL, STARTEAM_TEXT_PH);
proto_tree_add_item(starteam_tree, hf_starteam_ph_signature, tvb, offset + 0, 4, ENC_ASCII|ENC_NA);
proto_tree_add_item(starteam_tree, hf_starteam_ph_packet_size, tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_ph_data_size, tvb, offset + 8, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_ph_data_flags, tvb, offset + 12, 4, ENC_LITTLE_ENDIAN);
offset += 16;
if(bRequest){
if(tvb_reported_length_remaining(tvb, offset) >= 38){
starteam_tree = proto_tree_add_subtree(starteamroot_tree, tvb, offset, 38, ett_starteam_id, NULL, STARTEAM_TEXT_ID);
proto_tree_add_item(starteam_tree, hf_starteam_id_revision_level, tvb, offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_id_client, tvb, offset + 2, 16, ENC_ASCII|ENC_NA);
proto_tree_add_item(starteam_tree, hf_starteam_id_connect, tvb, offset + 18, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_id_component, tvb, offset + 22, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_id_command, tvb, offset + 26, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_id_command_time, tvb, offset + 30, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(starteam_tree, hf_starteam_id_command_userid, tvb, offset + 34, 4, ENC_LITTLE_ENDIAN);
offset += 38;
}
}
if(tvb_reported_length_remaining(tvb, offset) > 0){
starteam_tree = proto_tree_add_subtree(starteamroot_tree, tvb, offset, -1, ett_starteam_data, NULL, STARTEAM_TEXT_DATA);
proto_tree_add_item(starteam_tree, hf_starteam_data_data, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
}
}
}
return tvb_captured_length(tvb);
}
static guint
get_starteam_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 iPDULength = 0;
if(tvb_captured_length_remaining(tvb, offset) >= 8 && tvb_get_ntohl(tvb, offset + 0) == STARTEAM_MAGIC){
iPDULength = tvb_get_letohl(tvb, offset + 4) + 16;
} else if(tvb_captured_length_remaining(tvb, offset) >= 28 && tvb_get_ntohl(tvb, offset + 20) == STARTEAM_MAGIC){
iPDULength = tvb_get_letohl(tvb, offset + 24) + 36;
}
return iPDULength;
}
static int
dissect_starteam_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, starteam_desegment, 8, get_starteam_pdu_len, dissect_starteam, data);
return tvb_captured_length(tvb);
}
static gboolean
dissect_starteam_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if(tvb_captured_length(tvb) >= 32){
gint iOffsetLengths = -1;
if(tvb_get_ntohl(tvb, 0) == STARTEAM_MAGIC){
iOffsetLengths = 4;
} else if(tvb_get_ntohl(tvb, 20) == STARTEAM_MAGIC){
iOffsetLengths = 24;
}
if(iOffsetLengths != -1){
guint32 iLengthPacket;
guint32 iLengthData;
iLengthPacket = tvb_get_letohl(tvb, iOffsetLengths);
iLengthData = tvb_get_letohl(tvb, iOffsetLengths + 4);
if(iLengthPacket == iLengthData){
conversation_t *conversation = NULL;
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, starteam_tcp_handle);
dissect_starteam(tvb, pinfo, tree, data);
return TRUE;
}
}
}
return FALSE;
}
void
proto_register_starteam(void)
{
static hf_register_info hf[] = {
{ &hf_starteam_mdh_session_tag,
{ "Session tag", "starteam.mdh.stag", FT_UINT32, BASE_DEC, NULL, 0x0, "MDH session tag", HFILL }},
{ &hf_starteam_mdh_ctimestamp,
{ "Client timestamp", "starteam.mdh.ctimestamp", FT_UINT32, BASE_DEC, NULL, 0x0, "MDH client timestamp", HFILL }},
{ &hf_starteam_mdh_flags,
{ "Flags", "starteam.mdh.flags", FT_UINT32, BASE_HEX, NULL, 0x0, "MDH flags", HFILL }},
{ &hf_starteam_mdh_keyid,
{ "Key ID", "starteam.mdh.keyid", FT_UINT32, BASE_HEX, NULL, 0x0, "MDH key ID", HFILL }},
{ &hf_starteam_mdh_reserved,
{ "Reserved", "starteam.mdh.reserved", FT_UINT32, BASE_HEX, NULL, 0x0, "MDH reserved", HFILL }},
{ &hf_starteam_ph_signature,
{ "Signature", "starteam.ph.signature", FT_STRINGZ, BASE_NONE, NULL, 0x0, "PH signature", HFILL }},
{ &hf_starteam_ph_packet_size,
{ "Packet size", "starteam.ph.psize", FT_UINT32, BASE_DEC, NULL, 0x0, "PH packet size", HFILL }},
{ &hf_starteam_ph_data_size,
{ "Data size", "starteam.ph.dsize", FT_UINT32, BASE_DEC, NULL, 0x0, "PH data size", HFILL }},
{ &hf_starteam_ph_data_flags,
{ "Flags", "starteam.ph.flags", FT_UINT32, BASE_HEX, NULL, 0x0, "PH flags", HFILL }},
{ &hf_starteam_id_revision_level,
{ "Revision level", "starteam.id.level", FT_UINT16, BASE_DEC, NULL, 0x0, "ID revision level", HFILL }},
{ &hf_starteam_id_client,
{ "Client ID", "starteam.id.client", FT_STRINGZ, BASE_NONE, NULL, 0x0, "ID client ID", HFILL }},
{ &hf_starteam_id_connect,
{ "Connect ID", "starteam.id.connect", FT_UINT32, BASE_HEX, NULL, 0x0, "ID connect ID", HFILL }},
{ &hf_starteam_id_component,
{ "Component ID", "starteam.id.component", FT_UINT32, BASE_DEC, NULL, 0x0, "ID component ID", HFILL }},
{ &hf_starteam_id_command,
{ "Command ID", "starteam.id.command", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &starteam_opcode_vals_ext, 0x0, "ID command ID", HFILL }},
{ &hf_starteam_id_command_time,
{ "Command time", "starteam.id.commandtime", FT_UINT32, BASE_HEX, NULL, 0x0, "ID command time", HFILL }},
{ &hf_starteam_id_command_userid,
{ "Command user ID", "starteam.id.commanduserid", FT_UINT32, BASE_HEX, NULL, 0x0, "ID command user ID", HFILL }},
{ &hf_starteam_data_data,
{ "Data", "starteam.data", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_starteam,
&ett_starteam_mdh,
&ett_starteam_ph,
&ett_starteam_id,
&ett_starteam_data
};
module_t *starteam_module;
proto_starteam = proto_register_protocol("StarTeam", "StarTeam", "starteam");
proto_register_field_array(proto_starteam, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
starteam_module = prefs_register_protocol(proto_starteam, NULL);
prefs_register_bool_preference(starteam_module, "desegment",
"Reassemble StarTeam messages spanning multiple TCP segments",
"Whether the StarTeam dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&starteam_desegment);
register_init_routine(&starteam_init);
}
void
proto_reg_handoff_starteam(void)
{
heur_dissector_add("tcp", dissect_starteam_heur, "StarTeam over TCP", "starteam_tcp", proto_starteam, HEURISTIC_ENABLE);
starteam_tcp_handle = create_dissector_handle(dissect_starteam_tcp, proto_starteam);
}
