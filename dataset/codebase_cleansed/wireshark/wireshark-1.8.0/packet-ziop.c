static guint
get_ziop_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint8 flags;
guint message_size;
gboolean stream_is_big_endian;
if ( tvb_memeql(tvb, 0, ZIOP_MAGIC, 4) != 0)
return 0;
flags = tvb_get_guint8(tvb, offset + 6);
stream_is_big_endian = ((flags & 0x1) == 0);
if (stream_is_big_endian)
message_size = tvb_get_ntohl(tvb, offset + 8);
else
message_size = tvb_get_letohl(tvb, offset + 8);
return message_size + ZIOP_HEADER_SIZE;
}
static void
dissect_ziop_tcp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree) {
if ( tvb_memeql(tvb, 0, ZIOP_MAGIC ,4) != 0) {
if ( tvb_memeql(tvb, 0, GIOP_MAGIC ,4) == 0)
dissect_giop(tvb, pinfo, tree);
return;
}
tcp_dissect_pdus(tvb, pinfo, tree, ziop_desegment, ZIOP_HEADER_SIZE,
get_ziop_pdu_len, dissect_ziop);
}
gboolean
dissect_ziop_heur (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree) {
guint tot_len;
conversation_t *conversation;
tot_len = tvb_length(tvb);
if (tot_len < ZIOP_HEADER_SIZE)
{
return FALSE;
}
if ( tvb_memeql(tvb, 0, ZIOP_MAGIC, 4) != 0) {
return FALSE;
}
if ( pinfo->ptype == PT_TCP )
{
if (!pinfo->fd->flags.visited)
{
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, ziop_tcp_handle);
}
dissect_ziop_tcp (tvb, pinfo, tree);
}
else
{
dissect_ziop (tvb, pinfo, tree);
}
return TRUE;
}
static void
dissect_ziop (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree) {
guint offset = 0;
guint8 giop_version_major, giop_version_minor, message_type;
proto_tree *ziop_tree = NULL;
proto_item *ti;
col_set_str (pinfo->cinfo, COL_PROTOCOL, ZIOP_MAGIC);
col_clear(pinfo->cinfo, COL_INFO);
giop_version_major = tvb_get_guint8(tvb, 4);
giop_version_minor = tvb_get_guint8(tvb, 5);
message_type = tvb_get_guint8(tvb, 7);
if ( (giop_version_major < 1) ||
(giop_version_minor < 2) )
{
col_add_fstr (pinfo->cinfo, COL_INFO, "Version %u.%u",
giop_version_major, giop_version_minor);
if (tree)
{
ti = proto_tree_add_item (tree, proto_ziop, tvb, 0, -1, ENC_NA);
ziop_tree = proto_item_add_subtree (ti, ett_ziop);
proto_tree_add_text (ziop_tree, tvb, 4, 2,
"Version %u.%u not supported",
giop_version_major,
giop_version_minor);
}
call_dissector(data_handle, tvb, pinfo, tree);
return;
}
col_add_fstr (pinfo->cinfo, COL_INFO, "ZIOP %u.%u %s",
giop_version_major,
giop_version_minor,
val_to_str(message_type, giop_message_types,
"Unknown message type (0x%02x)")
);
if (tree)
{
guint8 flags;
guint byte_order;
emem_strbuf_t *flags_strbuf = ep_strbuf_new_label("none");
ti = proto_tree_add_item (tree, proto_ziop, tvb, 0, -1, ENC_NA);
ziop_tree = proto_item_add_subtree (ti, ett_ziop);
proto_tree_add_item(ziop_tree, hf_ziop_magic, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(ziop_tree, hf_ziop_giop_version_major, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ziop_tree, hf_ziop_giop_version_minor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
flags = tvb_get_guint8(tvb, offset);
byte_order = (flags & 0x01) ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN;
if (flags & 0x01) {
ep_strbuf_printf(flags_strbuf, "little-endian");
}
proto_tree_add_uint_format_value(ziop_tree, hf_ziop_flags, tvb, offset, 1,
flags, "0x%02x (%s)", flags, flags_strbuf->str);
offset++;
proto_tree_add_item(ziop_tree, hf_ziop_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ziop_tree, hf_ziop_message_size, tvb, offset, 4, byte_order);
offset += 4;
proto_tree_add_item(ziop_tree, hf_ziop_compressor_id, tvb, offset, 2, byte_order);
offset += 4;
proto_tree_add_item(ziop_tree, hf_ziop_original_length, tvb, offset, 4, byte_order);
}
}
void proto_register_ziop (void) {
static hf_register_info hf[] = {
{ &hf_ziop_magic,
{ "Header magic", "ziop.magic", FT_STRING, BASE_NONE, NULL, 0x0,
"ZIOPHeader magic", HFILL }},
{ &hf_ziop_giop_version_major,
{ "Header major version", "ziop.giop_version_major", FT_UINT8, BASE_OCT, NULL, 0x0,
"ZIOPHeader giop_major_version", HFILL }},
{ &hf_ziop_giop_version_minor,
{ "Header minor version", "ziop.giop_version_minor", FT_UINT8, BASE_OCT, NULL, 0x0,
"ZIOPHeader giop_minor_version", HFILL }},
{ &hf_ziop_flags,
{ "Header flags", "ziop.flags", FT_UINT8, BASE_OCT, NULL, 0x0,
"ZIOPHeader flags", HFILL }},
{ &hf_ziop_message_type,
{ "Header type", "ziop.message_type", FT_UINT8, BASE_OCT, VALS(giop_message_types), 0x0,
"ZIOPHeader message_type", HFILL }},
{ &hf_ziop_message_size,
{ "Header size", "ziop.message_size", FT_UINT32, BASE_DEC, NULL, 0x0,
"ZIOPHeader message_size", HFILL }},
{ &hf_ziop_compressor_id,
{ "Header compressor id", "ziop.compressor_id", FT_UINT16, BASE_DEC, VALS(ziop_compressor_ids), 0x0,
"ZIOPHeader compressor_id", HFILL }},
{ &hf_ziop_original_length,
{ "Header original length", "ziop.original_length", FT_UINT32, BASE_DEC, NULL, 0x0,
"ZIOP original_length", HFILL }},
};
static gint *ett[] = {
&ett_ziop,
};
proto_ziop = proto_register_protocol("Zipped Inter-ORB Protocol", "ZIOP",
"ziop");
proto_register_field_array (proto_ziop, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("ziop", dissect_ziop, proto_ziop);
}
void proto_reg_handoff_ziop (void) {
ziop_tcp_handle = create_dissector_handle(dissect_ziop_tcp, proto_ziop);
dissector_add_handle("udp.port", ziop_tcp_handle);
heur_dissector_add("tcp", dissect_ziop_heur, proto_ziop);
data_handle = find_dissector("data");
}
