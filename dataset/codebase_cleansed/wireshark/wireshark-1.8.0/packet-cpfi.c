static void
dissect_cpfi_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 tda;
guint32 src;
guint8 src_instance = 0;
guint8 src_board = 0;
guint8 src_port = 0;
guint32 dst;
guint8 dst_instance = 0;
guint8 dst_board = 0;
guint8 dst_port = 0;
proto_item *extra_item = NULL;
proto_tree *extra_tree = NULL;
proto_item *hidden_item;
if ( tree != NULL)
{
extra_item = proto_tree_add_protocol_format(tree, proto_cpfi, tvb, 0, -1, "Header");
extra_tree = proto_item_add_subtree(extra_item, ett_cpfi_header);
}
word1 = tvb_get_ntohl (tvb, 0);
word2 = tvb_get_ntohl (tvb, sizeof(word1));
tda = (word1 & CPFI_DEST_MASK) >> CPFI_DEST_SHIFT;
if ( tda >= FIRST_TIO_CARD_ADDRESS )
{
g_strlcpy(src_str, " CPFI", sizeof(src_str));
src = 0;
}
else
{
const guint8 *srcmac;
DISSECTOR_ASSERT(pinfo->src.type == AT_ETHER);
srcmac = pinfo->src.data;
src_instance = srcmac[2]-1;
src_board = tda >> 4;
src_port = tda & 0x0f;
src = (1 << 24) + (src_instance << 16) + (src_board << 8) + src_port;
g_snprintf(src_str, sizeof(src_str), "%u.%u.%u", src_instance, src_board, src_port);
}
tda = (word1 & CPFI_SOURCE_MASK) >> CPFI_SOURCE_SHIFT;
if ( tda >= FIRST_TIO_CARD_ADDRESS )
{
g_strlcpy(dst_str, " CPFI", sizeof(dst_str));
dst = 0;
}
else
{
const guint8 *dstmac;
DISSECTOR_ASSERT(pinfo->dst.type == AT_ETHER);
dstmac = pinfo->dst.data;
dst_instance = dstmac[2]-1;
dst_board = tda >> 4;
dst_port = tda & 0x0f;
dst = (1 << 24) + (dst_instance << 16) + (dst_board << 8) + dst_port;
g_snprintf(dst_str, sizeof(dst_str), "%u.%u.%u", dst_instance, dst_board, dst_port);
}
if ( cpfi_arrow_moves && (dst < src) )
{
left = dst_str;
arrow = r_to_l_arrow;
right = src_str;
}
else
{
left = src_str;
arrow = l_to_r_arrow;
right = dst_str;
}
if (extra_tree) {
if ( src != 0 )
{
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_instance, tvb, 0, 1, &src_instance);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_src_instance, tvb, 0, 1, &src_instance);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_board, tvb, 0, 1, &src_board);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_src_board, tvb, 0, 1, &src_board);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_port, tvb, 0, 1, &src_port);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_src_port, tvb, 0, 1, &src_port);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if ( dst != 0 )
{
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_instance, tvb, 0, 1, &dst_instance);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_dst_instance, tvb, 0, 1, &dst_instance);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_board, tvb, 0, 1, &dst_board);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_dst_board, tvb, 0, 1, &dst_board);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_port, tvb, 0, 1, &dst_port);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_bytes(extra_tree, hf_cpfi_t_dst_port, tvb, 0, 1, &dst_port);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_item(extra_tree, hf_cpfi_word_one , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_frame_type, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_source , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_dest , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_SOF_type , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_speed , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_OPM_error , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_from_LCM , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_word_two , tvb, 4, 4, ENC_BIG_ENDIAN);
};
}
static void
dissect_cpfi_footer(tvbuff_t *tvb, proto_tree *tree)
{
proto_item *extra_item = NULL;
proto_tree *extra_tree = NULL;
if ( tree != NULL)
{
extra_item = proto_tree_add_protocol_format(tree, proto_cpfi, tvb, 0, -1, "Footer");
extra_tree = proto_item_add_subtree(extra_item, ett_cpfi_footer);
}
if (extra_tree) {
proto_tree_add_item(extra_tree, hf_cpfi_CRC_32 , tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extra_tree, hf_cpfi_EOF_type, tvb, 4, 4, ENC_BIG_ENDIAN);
}
}
static int
dissect_cpfi(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *header_tvb, *body_tvb, *footer_tvb;
proto_item *cpfi_item = NULL;
proto_tree *cpfi_tree = NULL;
gint length, reported_length, body_length, reported_body_length;
frame_type = (tvb_get_ntohl (message_tvb, 0) & CPFI_FRAME_TYPE_MASK) >> CPFI_FRAME_TYPE_SHIFT;
if ( !((frame_type == 9) && fc_handle) )
return 0;
if (pinfo->dst.type != AT_ETHER || pinfo->src.type != AT_ETHER)
return 0;
length = tvb_length_remaining(message_tvb, 8);
reported_length = tvb_reported_length_remaining(message_tvb, 8);
if (reported_length < 8)
{
return 0;
}
reported_body_length = reported_length - 8;
body_length = length;
if (body_length > reported_body_length)
body_length = reported_body_length;
length = tvb_length_remaining(message_tvb, 8+body_length);
if (length < 0)
{
return 0;
}
if (tree) {
cpfi_item = proto_tree_add_item(tree, proto_cpfi, message_tvb, 0, -1, ENC_NA);
cpfi_tree = proto_item_add_subtree(cpfi_item, ett_cpfi);
}
pinfo->sof_eof = 0;
pinfo->sof_eof = PINFO_SOF_FIRST_FRAME;
pinfo->sof_eof |= PINFO_EOF_LAST_FRAME;
pinfo->sof_eof |= PINFO_EOF_INVALID;
header_tvb = tvb_new_subset(message_tvb, 0, 8, 8);
dissect_cpfi_header(header_tvb, pinfo, cpfi_tree);
body_tvb = tvb_new_subset(message_tvb, 8, body_length, reported_body_length);
call_dissector(fc_handle, body_tvb, pinfo, tree);
proto_item_append_text(cpfi_item, direction_and_port_string, left, arrow, right);
col_prepend_fstr(pinfo->cinfo, COL_INFO, direction_and_port_string, left, arrow, right);
footer_tvb = tvb_new_subset(message_tvb, 8+body_length, length, 8);
dissect_cpfi_footer(footer_tvb, cpfi_tree);
return(tvb_length(message_tvb));
}
void
proto_register_cpfi(void)
{
module_t *cpfi_module;
static hf_register_info hf[] = {
{ &hf_cpfi_word_one,
{ "Word one", "cpfi.word_one",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_cpfi_word_two,
{ "Word two", "cpfi.word_two",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_cpfi_frame_type,
{ "FrmType", "cpfi.frmtype",
FT_UINT32, BASE_HEX, NULL, CPFI_FRAME_TYPE_MASK,
"Frame Type", HFILL}},
{ &hf_cpfi_source,
{ "srcTDA", "cpfi.srcTDA",
FT_UINT32, BASE_HEX, NULL, CPFI_SOURCE_MASK,
"Source TDA (10 bits)", HFILL}},
{ &hf_cpfi_dest,
{ "dstTDA", "cpfi.dstTDA",
FT_UINT32, BASE_HEX, NULL, CPFI_DEST_MASK,
"Source TDA (10 bits)", HFILL}},
{ &hf_cpfi_SOF_type,
{ "SOFtype", "cpfi.SOFtype",
FT_UINT32, BASE_HEX, VALS(sof_type_vals), CPFI_SOF_TYPE_MASK,
"SOF Type", HFILL}},
{ &hf_cpfi_speed,
{ "speed", "cpfi.speed",
FT_UINT32, BASE_HEX, VALS(speed_vals), CPFI_SPEED_MASK,
"SOF Type", HFILL}},
{ &hf_cpfi_OPM_error,
{ "OPMerror", "cpfi.OPMerror",
FT_BOOLEAN, 32, NULL, CPFI_OPM_ERROR_MASK,
"OPM Error?", HFILL}},
{ &hf_cpfi_from_LCM,
{ "fromLCM", "cpfi.fromLCM",
FT_BOOLEAN, 32, NULL, CPFI_FROM_LCM_MASK,
"from LCM?", HFILL}},
{ &hf_cpfi_CRC_32,
{ "CRC-32", "cpfi.crc-32",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_cpfi_EOF_type,
{ "EOFtype", "cpfi.EOFtype",
FT_UINT32, BASE_HEX, VALS(eof_type_vals), CPFI_EOF_TYPE_MASK,
"EOF Type", HFILL}},
{ &hf_cpfi_t_instance,
{ "Instance", "cpfi.instance",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_src_instance,
{ "Source Instance", "cpfi.src_instance",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_dst_instance,
{ "Destination Instance", "cpfi.dst_instance",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_board,
{ "Board", "cpfi.board",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_src_board,
{ "Source Board", "cpfi.src_board",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_dst_board,
{ "Destination Board", "cpfi.dst_board",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_port,
{ "Port", "cpfi.port",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_src_port,
{ "Source Port", "cpfi.src_port",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_cpfi_t_dst_port,
{ "Destination Port", "cpfi.dst_port",
FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_cpfi,
&ett_cpfi_header,
&ett_cpfi_footer
};
proto_cpfi = proto_register_protocol("Cross Point Frame Injector", "CPFI", "cpfi");
proto_register_field_array(proto_cpfi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cpfi_module = prefs_register_protocol(proto_cpfi, proto_reg_handoff_cpfi);
prefs_register_uint_preference(cpfi_module, "udp.port", "CPFI UDP Port",
"Set the port for CPFI messages (if other"
" than the default of 5000)",
10, &gbl_cpfi_udp_port);
prefs_register_uint_preference(cpfi_module, "udp.port2", "InstanceToInstance UDP Port",
"Set the port for InstanceToInstance messages (if other"
" than the default of 5001)",
10, &gbl_cpfi_ttot_udp_port);
prefs_register_bool_preference(cpfi_module, "arrow_ctl",
"Enable Active Arrow Control",
"Control the way the '-->' is displayed."
" When enabled, keeps the 'lowest valued' endpoint of the src-dest pair"
" on the left, and the arrow moves to distinguish source from dest."
" When disabled, keeps the arrow pointing right so the source of the frame"
" is always on the left.",
&cpfi_arrow_moves);
}
void
proto_reg_handoff_cpfi(void)
{
static gboolean cpfi_init_complete = FALSE;
static dissector_handle_t cpfi_handle;
static dissector_handle_t ttot_handle;
static guint cpfi_udp_port;
static guint cpfi_ttot_udp_port;
if ( !cpfi_init_complete )
{
fc_handle = find_dissector("fc");
data_handle = find_dissector("data");
cpfi_handle = new_create_dissector_handle(dissect_cpfi, proto_cpfi);
ttot_handle = new_create_dissector_handle(dissect_cpfi, proto_cpfi);
cpfi_init_complete = TRUE;
}
else
{
dissector_delete_uint("udp.port", cpfi_udp_port, cpfi_handle);
dissector_delete_uint("udp.port", cpfi_ttot_udp_port, ttot_handle);
}
cpfi_udp_port = gbl_cpfi_udp_port;
cpfi_ttot_udp_port = gbl_cpfi_ttot_udp_port;
dissector_add_uint("udp.port", cpfi_udp_port, cpfi_handle);
dissector_add_uint("udp.port", cpfi_ttot_udp_port, ttot_handle);
}
