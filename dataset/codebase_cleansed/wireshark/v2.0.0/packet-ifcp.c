static gboolean
ifcp_header_test(tvbuff_t *tvb, int offset)
{
guint16 flen, flen1;
if(tvb_captured_length_remaining(tvb, offset)<iFCP_MIN_HEADER_LEN){
return FALSE;
}
if(tvb_memeql(tvb, offset, ifcp_header_4_bytes, 4) != 0){
return FALSE;
}
flen=tvb_get_ntohs(tvb, offset+12)&0x03FF;
if((flen < 15) || (flen > 545)){
return FALSE;
}
flen1=tvb_get_ntohs(tvb, offset+14)&0x03FF;
if(flen!=((~flen1)&0x03FF)){
return FALSE;
}
return TRUE;
}
static int
dissect_ifcpflags(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
static const int * flags[] = {
&hf_ifcp_flags_ses,
&hf_ifcp_flags_trp,
&hf_ifcp_flags_spc,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_ifcp_flags,
ett_ifcp_flags, flags, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_commonflags(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
static const int * flags[] = {
&hf_ifcp_common_flags_crcv,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_ifcp_common_flags,
ett_ifcp_common_flags, flags, ENC_BIG_ENDIAN);
}
static int
dissect_ifcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
gint offset = 0, frame_len = 0;
guint8 sof = 0, eof = 0;
proto_item *ti;
proto_tree *tree = NULL;
tvbuff_t *next_tvb;
guint8 protocol;
proto_tree *protocol_tree = NULL;
proto_tree *version_tree = NULL;
proto_tree *frame_len_tree = NULL;
proto_tree *sof_tree = NULL;
proto_tree *eof_tree = NULL;
fc_data_t fc_data;
if(tvb_captured_length(tvb)<iFCP_ENCAP_HEADER_LEN){
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "iFCP");
frame_len = (tvb_get_ntohs (tvb, offset+12) & 0x03FF)*4;
if (parent_tree) {
if (tvb_bytes_exist (tvb, offset, frame_len-4)) {
sof = tvb_get_guint8 (tvb, offset+iFCP_ENCAP_HEADER_LEN);
eof = tvb_get_guint8 (tvb, offset+frame_len - 4);
ti = proto_tree_add_protocol_format (parent_tree, proto_ifcp, tvb, offset,
iFCP_ENCAP_HEADER_LEN,
"iFCP (%s/%s)",
val_to_str (sof, ifcp_sof_vals,
"0x%x"),
val_to_str (eof, ifcp_eof_vals,
"0x%x"));
} else {
sof = tvb_get_guint8 (tvb, offset+iFCP_ENCAP_HEADER_LEN);
ti = proto_tree_add_protocol_format (parent_tree, proto_ifcp, tvb, offset,
iFCP_ENCAP_HEADER_LEN,
"iFCP (%s/%s)",
val_to_str (sof, ifcp_sof_vals,
"0x%x"),
"NA");
}
tree = proto_item_add_subtree (ti, ett_ifcp);
}
protocol = tvb_get_guint8 (tvb, offset);
ti=proto_tree_add_item(tree, hf_ifcp_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
protocol_tree=proto_item_add_subtree(ti, ett_ifcp_protocol);
offset++;
ti=proto_tree_add_item(tree, hf_ifcp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
version_tree=proto_item_add_subtree(ti, ett_ifcp_version);
offset++;
proto_tree_add_item(protocol_tree, hf_ifcp_protocol_c, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(version_tree, hf_ifcp_version_c, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset+=4;
if(protocol==FCENCAP_PROTO_iFCP){
proto_tree_add_item(tree, hf_ifcp_ls_command_acc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset=dissect_ifcpflags(tvb, offset, tree);
ti=proto_tree_add_item(tree, hf_ifcp_sof, tvb, offset, 1, ENC_BIG_ENDIAN);
sof_tree=proto_item_add_subtree(ti, ett_ifcp_sof);
offset++;
ti=proto_tree_add_item(tree, hf_ifcp_eof, tvb, offset, 1, ENC_BIG_ENDIAN);
eof_tree=proto_item_add_subtree(ti, ett_ifcp_eof);
offset++;
} else {
offset+=4;
sof_tree=tree;
eof_tree=tree;
}
dissect_commonflags(tvb, offset, tree);
ti=proto_tree_add_item(tree, hf_ifcp_framelen, tvb, offset, 2, ENC_BIG_ENDIAN);
frame_len_tree=proto_item_add_subtree(ti, ett_ifcp_frame_len);
offset+=2;
proto_tree_add_item(frame_len_tree, hf_ifcp_encap_flags_c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(frame_len_tree, hf_ifcp_framelen_c, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_ifcp_tsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_ifcp_tusec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_ifcp_encap_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(sof_tree, hf_ifcp_sof, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sof_tree, hf_ifcp_sof, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sof_tree, hf_ifcp_sof_c, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sof_tree, hf_ifcp_sof_c, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(tvb_bytes_exist(tvb, frame_len-4, 4)) {
proto_tree_add_item(eof_tree, hf_ifcp_eof, tvb, frame_len-4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eof_tree, hf_ifcp_eof, tvb, frame_len-3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eof_tree, hf_ifcp_eof_c, tvb, frame_len-2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eof_tree, hf_ifcp_eof_c, tvb, frame_len-1, 1, ENC_BIG_ENDIAN);
}
fc_data.sof_eof = 0;
switch(sof){
case iFCP_SOFi3:
case iFCP_SOFi2:
case iFCP_SOFi4:
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
break;
case iFCP_SOFf:
fc_data.sof_eof = FC_DATA_SOF_SOFF;
break;
default:
if(sof){
if (eof != iFCP_EOFn) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
} else if (eof != iFCP_EOFt) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
}
}
next_tvb=tvb_new_subset_length(tvb, offset, frame_len-offset-4);
fc_data.ethertype = 0;
if(fc_handle){
call_dissector_with_data(fc_handle, next_tvb, pinfo, parent_tree, &fc_data);
} else if(data_handle){
call_dissector(data_handle, next_tvb, pinfo, parent_tree);
}
return tvb_captured_length(tvb);
}
static guint
get_ifcp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint pdu_len;
if(!ifcp_header_test(tvb, offset)){
return 0;
}
pdu_len=(tvb_get_ntohs(tvb, offset+12)&0x03FF)*4;
return pdu_len;
}
static int
dissect_ifcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, parent_tree, ifcp_desegment, iFCP_MIN_HEADER_LEN, get_ifcp_pdu_len, dissect_ifcp_pdu, data);
return tvb_captured_length(tvb);
}
static int
dissect_ifcp_handle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
return dissect_ifcp(tvb, pinfo, tree, data);
}
static gboolean
dissect_ifcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if(!ifcp_header_test(tvb, 0)){
return FALSE;
}
dissect_ifcp(tvb, pinfo, tree, data);
if(ifcp_handle){
conversation_t* ifcp_conv;
ifcp_conv=find_or_create_conversation(pinfo);
conversation_set_dissector(ifcp_conv, ifcp_handle);
}
return TRUE;
}
void
proto_register_ifcp (void)
{
static hf_register_info hf[] = {
{ &hf_ifcp_protocol,
{"Protocol", "ifcp.encap.proto", FT_UINT8, BASE_DEC, VALS(fcencap_proto_vals), 0,
NULL, HFILL }},
{ &hf_ifcp_protocol_c,
{"Protocol (1's Complement)", "ifcp.encap.protoc", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_version,
{"Version", "ifcp.encap.version", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_version_c,
{"Version (1's Complement)", "ifcp.encap.versionc", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_encap_flags_c,
{"iFCP Encapsulation Flags (1's Complement)", "ifcp.encap_flagsc", FT_UINT8, BASE_HEX, NULL, 0xFC,
NULL, HFILL}},
{ &hf_ifcp_framelen,
{"Frame Length (in Words)", "ifcp.encap.framelen", FT_UINT16, BASE_DEC, NULL, 0x03FF,
NULL, HFILL}},
{ &hf_ifcp_framelen_c,
{"Frame Length (1's Complement)", "ifcp.encap.framelenc", FT_UINT16, BASE_DEC, NULL, 0x03FF,
NULL, HFILL}},
{ &hf_ifcp_tsec,
{"Time (secs)", "ifcp.encap.tsec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_tusec,
{"Time (fraction)", "ifcp.encap.tusec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_encap_crc,
{"CRC", "ifcp.encap.crc", FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_sof,
{"SOF", "ifcp.sof", FT_UINT8, BASE_HEX, VALS (ifcp_sof_vals), 0,
NULL, HFILL}},
{ &hf_ifcp_eof,
{"EOF", "ifcp.eof", FT_UINT8, BASE_HEX, VALS (ifcp_eof_vals), 0,
NULL, HFILL}},
{ &hf_ifcp_sof_c,
{"SOF Compliment", "ifcp.sof_c", FT_UINT8, BASE_HEX, NULL , 0,
NULL, HFILL}},
{ &hf_ifcp_eof_c,
{"EOF Compliment", "ifcp.eof_c", FT_UINT8, BASE_HEX, NULL , 0,
NULL, HFILL}},
{ &hf_ifcp_ls_command_acc,
{"Ls Command Acc", "ifcp.ls_command_acc", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_ifcp_common_flags,
{"Flags", "ifcp.common_flags", FT_UINT8, BASE_HEX , NULL, 0xfc,
NULL, HFILL }},
{ &hf_ifcp_common_flags_crcv,
{"CRC", "ifcp.common_flags.crcv", FT_BOOLEAN, 8, TFS(&tfs_valid_not_valid), IFCP_COMMON_FLAGS_CRCV,
"Is the CRC field valid?", HFILL }},
{ &hf_ifcp_flags,
{"iFCP Flags", "ifcp.flags", FT_UINT8, BASE_HEX , NULL, 0,
NULL, HFILL }},
{ &hf_ifcp_flags_ses,
{"SES", "ifcp.flags.ses", FT_BOOLEAN, 8, TFS(&ifcp_flags_ses_tfs), IFCP_FLAGS_SES,
"Is this a Session control frame", HFILL }},
{ &hf_ifcp_flags_trp,
{"TRP", "ifcp.flags.trp", FT_BOOLEAN, 8, TFS(&ifcp_flags_trp_tfs), IFCP_FLAGS_TRP,
"Is address transparent mode enabled", HFILL }},
{ &hf_ifcp_flags_spc,
{"SPC", "ifcp.flags.spc", FT_BOOLEAN, 8, TFS(&ifcp_flags_spc_tfs), IFCP_FLAGS_SPC,
"Is frame part of link service", HFILL }},
};
static gint *ett[] = {
&ett_ifcp,
&ett_ifcp_sof,
&ett_ifcp_eof,
&ett_ifcp_protocol,
&ett_ifcp_version,
&ett_ifcp_frame_len,
&ett_ifcp_flags,
&ett_ifcp_common_flags,
};
module_t *ifcp_module;
proto_ifcp = proto_register_protocol("iFCP", "iFCP", "ifcp");
proto_register_field_array(proto_ifcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ifcp_module = prefs_register_protocol(proto_ifcp, NULL);
prefs_register_bool_preference(ifcp_module,
"desegment",
"Reassemble iFCP messages spanning multiple TCP segments",
"Whether the iFCP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ifcp_desegment);
prefs_register_obsolete_preference(ifcp_module, "target_port");
}
void
proto_reg_handoff_ifcp (void)
{
heur_dissector_add("tcp", dissect_ifcp_heur, "iFCP over TCP", "ifcp_tcp", proto_ifcp, HEURISTIC_ENABLE);
ifcp_handle = new_create_dissector_handle(dissect_ifcp_handle, proto_ifcp);
dissector_add_for_decode_as("tcp.port", ifcp_handle);
data_handle = find_dissector("data");
fc_handle = find_dissector("fc_ifcp");
}
