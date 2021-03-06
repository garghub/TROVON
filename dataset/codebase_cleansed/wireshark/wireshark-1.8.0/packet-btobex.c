static void
defragment_init(void)
{
fragment_table_init(&fragment_table);
reassembled_table_init(&reassembled_table);
}
static int
is_ascii_str(const guint8 *str, int length)
{
int i;
if ((length < 1) || (str[length-1] != '\0'))
return 0;
for(i=0; i<length-1; i++) {
if ((str[i] < 0x20) && (str[i] != 0x0a))
break;
}
if (i < (length-1))
return 0;
return 1;
}
static int
display_unicode_string(tvbuff_t *tvb, proto_tree *tree, int offset, char **data)
{
char *str, *p;
int len;
int charoffset;
guint16 character;
len = 0;
while (tvb_get_ntohs(tvb, offset + len) != '\0')
len += 2;
len += 2;
str = ep_alloc(len/2);
charoffset = offset;
p = str;
while ((character = tvb_get_ntohs(tvb, charoffset)) != '\0') {
*p++ = (char) character;
charoffset += 2;
}
*p = '\0';
if (!is_ascii_str(str, len/2)) {
*str = '\0';
}
proto_tree_add_string(tree, hf_hdr_val_unicode, tvb, offset, len, str);
if (data)
*data = str;
return offset+len;
}
static int
dissect_headers(proto_tree *tree, tvbuff_t *tvb, int offset, packet_info *pinfo)
{
proto_tree *hdrs_tree = NULL;
proto_tree *hdr_tree = NULL;
proto_item *hdr = NULL;
proto_item *handle_item;
gint item_length = -1;
guint8 hdr_id, i;
if (tvb_length_remaining(tvb, offset) > 0) {
proto_item *hdrs;
hdrs = proto_tree_add_text(tree, tvb, offset, item_length, "Headers");
hdrs_tree = proto_item_add_subtree(hdrs, ett_btobex_hdrs);
}
else {
return offset;
}
while (tvb_length_remaining(tvb, offset) > 0) {
hdr_id = tvb_get_guint8(tvb, offset);
switch(0xC0 & hdr_id)
{
case 0x00:
item_length = tvb_get_ntohs(tvb, offset+1);
break;
case 0x40:
item_length = tvb_get_ntohs(tvb, offset+1);
break;
case 0x80:
item_length = 2;
break;
case 0xc0:
item_length = 5;
break;
}
hdr = proto_tree_add_text(hdrs_tree, tvb, offset, item_length, "%s",
val_to_str_ext_const(hdr_id, &header_id_vals_ext, "Unknown"));
hdr_tree = proto_item_add_subtree(hdr, ett_btobex_hdr);
proto_tree_add_item(hdr_tree, hf_hdr_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(0xC0 & hdr_id)
{
case 0x00:
{
proto_tree_add_item(hdr_tree, hf_hdr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ((item_length - 3) > 0) {
char *str;
display_unicode_string(tvb, hdr_tree, offset, &str);
proto_item_append_text(hdr_tree, " (\"%s\")", str);
col_append_fstr(pinfo->cinfo, COL_INFO, " \"%s\"", str);
}
else {
col_append_str(pinfo->cinfo, COL_INFO, " \"\"");
}
offset += item_length - 3;
}
break;
case 0x40:
proto_tree_add_item(hdr_tree, hf_hdr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
handle_item = proto_tree_add_item(hdr_tree, hf_hdr_val_byte_seq, tvb, offset, item_length - 3, ENC_NA);
if (((hdr_id == 0x46) || (hdr_id == 0x4a)) && (item_length == 19)) {
for(i=0; target_vals[i].strptr != NULL; i++) {
if (tvb_memeql(tvb, offset, target_vals[i].value, 16) == 0) {
proto_item_append_text(handle_item, ": %s", target_vals[i].strptr);
proto_item_append_text(hdr_tree, " (%s)", target_vals[i].strptr);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", target_vals[i].strptr);
}
}
}
if (!tvb_strneql(tvb, offset, "<?xml", 5))
{
tvbuff_t* next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(xml_handle, next_tvb, pinfo, tree);
}
else if (is_ascii_str(tvb_get_ptr(tvb, offset,item_length - 3), item_length - 3))
{
proto_item_append_text(hdr_tree, " (\"%s\")", tvb_get_ephemeral_string(tvb, offset,item_length - 3));
col_append_fstr(pinfo->cinfo, COL_INFO, " \"%s\"", tvb_get_ephemeral_string(tvb, offset,item_length - 3));
}
offset += item_length - 3;
break;
case 0x80:
proto_item_append_text(hdr_tree, " (%i)", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(hdr_tree, hf_hdr_val_byte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 0xc0:
proto_item_append_text(hdr_tree, " (%i)", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(hdr_tree, hf_hdr_val_long, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
default:
break;
}
}
return offset;
}
static void
dissect_btobex(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *st;
fragment_data *frag_msg = NULL;
gboolean save_fragmented, complete;
tvbuff_t* new_tvb = NULL;
tvbuff_t* next_tvb = NULL;
guint32 no_of_segments = 0;
int offset = 0;
save_fragmented = pinfo->fragmented;
frag_msg = NULL;
complete = FALSE;
if (fragment_get(pinfo, pinfo->p2p_dir, fragment_table)) {
frag_msg = fragment_add_seq_next(tvb, 0, pinfo, pinfo->p2p_dir,
fragment_table, reassembled_table, tvb_length(tvb), TRUE);
new_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled Obex packet", frag_msg, &btobex_frag_items, NULL, tree);
pinfo->fragmented = TRUE;
}
else {
if (tvb_length(tvb) < tvb_get_ntohs(tvb, offset+1)) {
no_of_segments = tvb_get_ntohs(tvb, offset+1)/tvb_length(tvb);
if (tvb_get_ntohs(tvb, offset+1) > (no_of_segments * tvb_length(tvb)))
no_of_segments++;
frag_msg = fragment_add_seq_next(tvb, 0, pinfo, pinfo->p2p_dir,
fragment_table, reassembled_table, tvb_length(tvb), TRUE);
fragment_set_tot_len(pinfo, pinfo->p2p_dir, fragment_table, no_of_segments-1);
new_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled Obex packet", frag_msg, &btobex_frag_items, NULL, tree);
pinfo->fragmented = TRUE;
}
else if (tvb_length(tvb) == tvb_get_ntohs(tvb, offset+1)) {
complete = TRUE;
pinfo->fragmented = FALSE;
}
}
if (new_tvb) {
next_tvb = new_tvb;
complete = TRUE;
}
else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (complete) {
guint8 code, final_flag;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OBEX");
ti = proto_tree_add_item(tree, proto_btobex, next_tvb, 0, -1, ENC_NA);
st = proto_item_add_subtree(ti, ett_btobex);
code = tvb_get_guint8(next_tvb, offset) & BTOBEX_CODE_VALS_MASK;
final_flag = tvb_get_guint8(next_tvb, offset) & 0x80;
switch (pinfo->p2p_dir)
{
case P2P_DIR_SENT:
col_add_fstr(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_fstr(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
case P2P_DIR_UNKNOWN:
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str_ext_const(code, &code_vals_ext, "Unknown"));
if ((code < BTOBEX_CODE_VALS_CONTINUE) || (code == BTOBEX_CODE_VALS_ABORT)) {
proto_tree_add_item(st, hf_opcode, next_tvb, offset, 1, ENC_BIG_ENDIAN);
if (pinfo->p2p_dir == P2P_DIR_SENT || pinfo->p2p_dir == P2P_DIR_RECV) {
last_opcode[pinfo->p2p_dir] = code;
}
}
else {
proto_tree_add_item(st, hf_response_code, next_tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(st, hf_final_flag, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(st, hf_length, next_tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch(code)
{
case BTOBEX_CODE_VALS_CONNECT:
proto_tree_add_item(st, hf_version, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(st, hf_flags, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(st, hf_max_pkt_len, next_tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case BTOBEX_CODE_VALS_PUT:
case BTOBEX_CODE_VALS_GET:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", (final_flag == 0x80) ? "final" : "continue");
break;
case BTOBEX_CODE_VALS_SET_PATH:
proto_tree_add_item(st, hf_flags, next_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(st, hf_set_path_flags_0, next_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(st, hf_set_path_flags_1, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(st, hf_constants, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case BTOBEX_CODE_VALS_DISCONNECT:
case BTOBEX_CODE_VALS_ABORT:
break;
default:
{
guint8 response_opcode = last_opcode[(pinfo->p2p_dir + 1) & 0x01];
if (response_opcode == BTOBEX_CODE_VALS_CONNECT) {
proto_tree_add_item(st, hf_version, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(st, hf_flags, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(st, hf_max_pkt_len, next_tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
break;
}
dissect_headers(st, next_tvb, offset, pinfo);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Obex fragment",
(pinfo->p2p_dir==P2P_DIR_SENT) ? "Sent" : "Rcvd");
call_dissector(data_handle, next_tvb, pinfo, tree);
}
pinfo->fragmented = save_fragmented;
}
void
proto_register_btobex(void)
{
static hf_register_info hf[] = {
{ &hf_opcode,
{ "Opcode", "btobex.opcode",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &code_vals_ext, BTOBEX_CODE_VALS_MASK,
"Request Opcode", HFILL}
},
{ &hf_response_code,
{ "Response Code", "btobex.resp_code",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &code_vals_ext, BTOBEX_CODE_VALS_MASK,
NULL, HFILL}
},
{ &hf_final_flag,
{ "Final Flag", "btobex.final_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}
},
{ &hf_length,
{ "Packet Length", "btobex.pkt_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_version,
{ "Version", "btobex.version",
FT_UINT8, BASE_HEX, VALS(version_vals), 0x00,
"Obex Protocol Version", HFILL}
},
{ &hf_flags,
{ "Flags", "btobex.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_constants,
{ "Constants", "btobex.constants",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_max_pkt_len,
{ "Max. Packet Length", "btobex.max_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_set_path_flags_0,
{ "Go back one folder (../) first", "btobex.set_path_flags_0",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_set_path_flags_1,
{ "Do not create folder, if not existing", "btobex.set_path_flags_1",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_hdr_id,
{ "Header Id", "btobex.hdr_id",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &header_id_vals_ext, 0x00,
NULL, HFILL}
},
{ &hf_hdr_length,
{ "Length", "btobex.pkt_hdr_len",
FT_UINT16, BASE_DEC, NULL, 0,
"Header Length", HFILL}
},
{ &hf_hdr_val_unicode,
{ "Value", "btobex.pkt_hdr_val_uc",
FT_STRING, BASE_NONE, NULL, 0,
"Unicode Value", HFILL }
},
{ &hf_hdr_val_byte_seq,
{ "Value", "btobex.hdr_val_byte_seq",
FT_BYTES, BASE_NONE, NULL, 0,
"Byte Value", HFILL}
},
{ &hf_hdr_val_byte,
{ "Value", "btobex.hdr_val_byte",
FT_UINT8, BASE_HEX, NULL, 0,
"Byte Sequence Value", HFILL}
},
{ &hf_hdr_val_long,
{ "Value", "btobex.hdr_val_long",
FT_UINT32, BASE_DEC, NULL, 0,
"4-byte Value", HFILL}
},
{ &hf_btobex_fragment_overlap,
{ "Fragment overlap", "btobex.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }
},
{ &hf_btobex_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "btobex.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }
},
{ &hf_btobex_fragment_multiple_tails,
{ "Multiple tail fragments found", "btobex.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }
},
{ &hf_btobex_fragment_too_long_fragment,
{ "Fragment too long", "btobex.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }
},
{ &hf_btobex_fragment_error,
{ "Defragmentation error", "btobex.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }
},
{ &hf_btobex_fragment_count,
{ "Fragment count", "btobex.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btobex_fragment,
{ "OBEX Fragment", "btobex.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"btobex Fragment", HFILL }
},
{ &hf_btobex_fragments,
{ "OBEX Fragments", "btobex.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
"btobex Fragments", HFILL }
},
{ &hf_btobex_reassembled_in,
{ "Reassembled OBEX in frame", "btobex.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This OBEX frame is reassembled in this frame", HFILL }
},
{ &hf_btobex_reassembled_length,
{ "Reassembled OBEX length", "btobex.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }
}
};
static gint *ett[] = {
&ett_btobex,
&ett_btobex_hdrs,
&ett_btobex_hdr,
&ett_btobex_fragment,
&ett_btobex_fragments
};
proto_btobex = proto_register_protocol("Bluetooth OBEX Protocol", "OBEX", "btobex");
register_dissector("btobex", dissect_btobex, proto_btobex);
proto_register_field_array(proto_btobex, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&defragment_init);
}
void
proto_reg_handoff_btobex(void)
{
dissector_handle_t btobex_handle;
btobex_handle = find_dissector("btobex");
dissector_add_uint("btrfcomm.service", BTSDP_OPP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_FTP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_BPP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_BPP_STATUS_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_BIP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_BIP_RESPONDER_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_BIP_AUTO_ARCH_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_BIP_REF_OBJ_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_PBAP_PCE_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_PBAP_PSE_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_PBAP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_MAP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_MAP_ACCESS_SRV_SERVICE_UUID, btobex_handle);
dissector_add_uint("btrfcomm.service", BTSDP_MAP_NOIYFY_SRV_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_OPP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_FTP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_BPP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_BPP_STATUS_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_BIP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_BIP_RESPONDER_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_BIP_AUTO_ARCH_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_BIP_REF_OBJ_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_PBAP_PCE_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_PBAP_PSE_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_PBAP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_MAP_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_MAP_ACCESS_SRV_SERVICE_UUID, btobex_handle);
dissector_add_uint("btl2cap.service", BTSDP_MAP_NOIYFY_SRV_SERVICE_UUID, btobex_handle);
xml_handle = find_dissector("xml");
data_handle = find_dissector("data");
}
