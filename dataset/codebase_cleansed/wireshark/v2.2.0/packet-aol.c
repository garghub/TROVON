static guint dissect_aol_init(tvbuff_t *tvb, packet_info *pinfo _U_, guint offset, proto_tree *tree) {
proto_item *data_item;
proto_tree *data_tree;
guint16 dos_ver = 0;
guint16 win_ver = 0;
data_item = proto_tree_add_item(tree,hf_aol_init,tvb,offset,tvb_reported_length_remaining(tvb,offset)-1,ENC_NA);
data_tree = proto_item_add_subtree(data_item,ett_aol_data);
proto_tree_add_item(data_tree,hf_aol_platform, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_version, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_subversion, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_unused, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_machine_mem, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_app_mem, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_pc_type, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(data_tree,hf_aol_rel_month, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_rel_day, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_cust_class, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(data_tree,hf_aol_udo_timestamp,tvb,offset,4,ENC_LITTLE_ENDIAN); offset += 4;
dos_ver = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format_value(data_tree,hf_aol_dos_ver,tvb,offset,2,dos_ver,"%d.%d",(dos_ver & 0xFF00) >> 8,dos_ver & 0xFF);
offset += 2;
proto_tree_add_item(data_tree,hf_aol_sess_flags, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(data_tree,hf_aol_video_type, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_cpu_type, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_media_type, tvb,offset,4,ENC_LITTLE_ENDIAN); offset += 4;
win_ver = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format_value(data_tree,hf_aol_win_ver,tvb,offset,2,dos_ver,"%d.%d",(win_ver & 0xFF00) >> 8,win_ver & 0xFF);
offset += 4;
proto_tree_add_item(data_tree,hf_aol_wmem_mode, tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(data_tree,hf_aol_horiz_res, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(data_tree,hf_aol_vert_res, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(data_tree,hf_aol_num_colors, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
if (tvb_reported_length_remaining(tvb,offset) <= 13) {
if (tvb_reported_length_remaining(tvb,offset) == 13) {
proto_tree_add_item(data_tree,hf_aol_filler,tvb,offset,1,ENC_BIG_ENDIAN); offset += 1;
}
proto_tree_add_item(data_tree,hf_aol_region, tvb,offset,2,ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(data_tree,hf_aol_lang, tvb,offset,8,ENC_LITTLE_ENDIAN); offset += 8;
proto_tree_add_item(data_tree,hf_aol_conn_spd,tvb,offset,1,ENC_NA); offset += 1;
} else {
;
}
return offset;
}
static guint get_aol_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint16 plen;
plen = tvb_get_ntohs(tvb,offset+3);
return plen + 6;
}
static int dissect_aol_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
proto_item *ti;
proto_tree *aol_tree;
guint offset = 0;
guint16 pdu_len;
guint8 pdu_type = 0;
col_set_str(pinfo->cinfo,COL_PROTOCOL,"AOL");
col_set_str(pinfo->cinfo,COL_INFO,"America Online");
ti = proto_tree_add_item(tree,proto_aol,tvb,0,-1,ENC_NA);
aol_tree = proto_item_add_subtree(ti,ett_aol);
pdu_len = tvb_get_ntohs(tvb,3);
proto_tree_add_item(aol_tree,hf_aol_start,tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_checksum(aol_tree, tvb, offset, hf_aol_crc, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS); offset += 2;
proto_tree_add_item(aol_tree,hf_aol_len, tvb,offset,2,ENC_BIG_ENDIAN); offset += 2;
if (pdu_len >= 2) {
proto_tree_add_item(aol_tree,hf_aol_tx_seq,tvb,offset,1,ENC_NA); offset += 1;
proto_tree_add_item(aol_tree,hf_aol_rx_seq,tvb,offset,1,ENC_NA); offset += 1;
pdu_len -= 2;
}
if (pdu_len >= 1) {
pdu_type = tvb_get_guint8(tvb,offset) & 0x3f;
col_append_fstr(pinfo->cinfo,COL_INFO," [Type: %s]",val_to_str_const(pdu_type,aol_p3_types,"Unknown"));
proto_item_append_text(ti," [Type: %s]",val_to_str_const(pdu_type,aol_p3_types,"Unknown"));
proto_tree_add_uint(aol_tree,hf_aol_type,tvb,offset,1,pdu_type);
offset += 1; pdu_len -= 1;
}
if (pdu_len > 0) {
guint old_offset = offset;
if (tvb_reported_length_remaining(tvb,offset) > pdu_len) {
if (pdu_type == AOL_P3_TYPE_INIT) {
offset = dissect_aol_init(tvb,pinfo,offset,aol_tree);
} else {
if (pdu_len >= 2) {
guint16 token;
token = tvb_get_ntohs(tvb,offset);
col_append_fstr(pinfo->cinfo,COL_INFO," [Token: '%c%c']",(token & 0xFF00) >> 8,token & 0xFF);
proto_item_append_text(ti," [Token: '%c%c']",(token & 0xFF00) >> 8,token & 0xFF);
proto_tree_add_uint_format_value(aol_tree,hf_aol_token,tvb,offset,2,token,"'%c%c'",(token & 0xFF00) >> 8,token & 0xFF);
offset += 2; pdu_len -= 2;
}
if (pdu_len > 0) {
proto_tree_add_item(aol_tree,hf_aol_data,tvb,offset,pdu_len,ENC_NA);
offset += pdu_len;
}
}
if (offset < (old_offset + pdu_len)) {
proto_tree_add_item(aol_tree,hf_aol_udata,tvb,offset,(old_offset+pdu_len)-offset,ENC_NA);
offset = old_offset + pdu_len;
}
} else {
expert_add_info(pinfo,ti,&ei_aol_pdu_length_bad);
}
}
if (tvb_reported_length_remaining(tvb,offset) >= 1) {
proto_tree_add_item(aol_tree,hf_aol_end,tvb,offset,1,ENC_NA);
} else {
expert_add_info(pinfo,ti,&ei_aol_end_missing);
}
return tvb_reported_length(tvb);
}
static int dissect_aol(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
if (tvb_reported_length(tvb) >= 1 && tvb_get_guint8(tvb,0) != AOL_P3_FRAME_START) return 0;
tcp_dissect_pdus(tvb,pinfo,tree,aol_desegment,9,get_aol_pdu_len,dissect_aol_pdu,data);
return tvb_reported_length(tvb);
}
void proto_register_aol(void) {
static hf_register_info hf[] = {
{ &hf_aol_udata, { "Unparsed Data", "aol.udata", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_init, { "AOL 'INIT' Data", "aol.init_data",FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_start, { "Start of Frame", "aol.start", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_crc, { "Checksum", "aol.checksum", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_len, { "Length", "aol.len", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_tx_seq, { "Tx Sequence", "aol.tx_seq", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_rx_seq, { "Rx Sequence", "aol.rx_seq", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_type, { "Type", "aol.type", FT_UINT8, BASE_HEX, VALS(aol_p3_types), 0x00, NULL, HFILL }},
{ &hf_aol_token, { "Token", "aol.token", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_data, { "Data", "aol.data", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_end, { "End of Frame", "aol.end", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_platform, { "Platform", "aol.init.platform", FT_UINT8, BASE_HEX, VALS(aol_platforms),0x00, NULL, HFILL }},
{ &hf_aol_version, { "Client Version", "aol.init.version", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_subversion, { "Client Subversion","aol.init.subversion", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_unused, { "Unused", "aol.init.unused", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_machine_mem, { "Machine Memory", "aol.init.memory", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_app_mem, { "App Memory", "aol.init.app_memory", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_pc_type, { "PC Type", "aol.init.pc_type", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_rel_month, { "Release Month", "aol.init.rel_month", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_rel_day, { "Release Day", "aol.init.rel_day", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_cust_class, { "Customer Class", "aol.init.cust_class", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_udo_timestamp,{ "UDO Timestamp", "aol.init.udo_ts", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_dos_ver, { "DOS Version", "aol.init.dos_ver", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_sess_flags, { "Session Flags", "aol.init.sess_flags", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_video_type, { "Video Type", "aol.init.video_type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_cpu_type, { "CPU Type", "aol.init.cpu_type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_media_type, { "Media Type", "aol.init.media_type", FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_win_ver, { "Windows Version", "aol.init.win_ver", FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_wmem_mode, { "Windows Mem Type", "aol.init.wmem_mode", FT_UINT8, BASE_DEC, VALS(aol_wmem_mode),0x00, NULL, HFILL }},
{ &hf_aol_horiz_res, { "Horizontal Res", "aol.init.horiz_res", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_vert_res, { "Vertical Res", "aol.init.vert_res", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_num_colors, { "Colors", "aol.init.colors", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_filler, { "Filler Byte", "aol.init.filler", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_region, { "AOL Region", "aol.init.region", FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_lang, { "AOL Language(s)", "aol.init.langs", FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_aol_conn_spd, { "Connection Speed", "aol.init.conn_spd", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
};
static gint *ett[] = {
&ett_aol,
&ett_aol_data
};
static ei_register_info ei[] = {
{ &ei_aol_pdu_length_bad, { "aol.pdu_length_bad", PI_MALFORMED, PI_ERROR, "pdu length > tvb length", EXPFILL }},
{ &ei_aol_end_missing, { "aol.end_missing", PI_PROTOCOL, PI_WARN, "End of frame marker expected", EXPFILL }},
};
module_t *aol_module;
expert_module_t* expert_aol;
proto_aol = proto_register_protocol("America Online","AOL","aol");
proto_register_field_array(proto_aol,hf,array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
expert_aol = expert_register_protocol(proto_aol);
expert_register_field_array(expert_aol, ei, array_length(ei));
aol_module = prefs_register_protocol(proto_aol,NULL);
prefs_register_bool_preference(aol_module,"desegment",
"Reassemble AOL messages spanning multiple TCP segments",
"Whether the AOL dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" "
"in the TCP protocol settings.",&aol_desegment);
}
void proto_reg_handoff_aol(void) {
static dissector_handle_t aol_handle;
aol_handle = create_dissector_handle(dissect_aol,proto_aol);
dissector_add_uint("tcp.port",AOL_PORT,aol_handle);
}
