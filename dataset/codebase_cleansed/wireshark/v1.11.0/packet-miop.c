static gboolean
dissect_miop_heur (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data _U_) {
guint tot_len;
guint32 magic;
tot_len = tvb_length(tvb);
if (tot_len < MIOP_HEADER_SIZE)
{
return FALSE;
}
magic = tvb_get_ntohl(tvb,0);
if(magic != MIOP_MAGIC){
return FALSE;
}
if (pinfo->ptype != PT_UDP)
return FALSE;
dissect_miop (tvb, pinfo, tree);
return TRUE;
}
static void dissect_miop (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree) {
guint offset = 0;
proto_tree *miop_tree = NULL;
proto_item *ti;
guint8 hdr_version;
guint version_major;
guint version_minor;
guint8 flags;
guint16 packet_length;
guint packet_number;
guint number_of_packets;
guint byte_order;
guint32 unique_id_len;
wmem_strbuf_t *flags_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
wmem_strbuf_append(flags_strbuf, "none");
col_set_str (pinfo->cinfo, COL_PROTOCOL, "MIOP");
col_clear(pinfo->cinfo, COL_INFO);
hdr_version = tvb_get_guint8(tvb, 4);
version_major = ((hdr_version & 0xf0) >> 4);
version_minor = (hdr_version & 0x0f);
if (hdr_version != 16)
{
col_add_fstr (pinfo->cinfo, COL_INFO, "Version %u.%u",
version_major, version_minor);
ti = proto_tree_add_item (tree, proto_miop, tvb, 0, -1, ENC_NA);
miop_tree = proto_item_add_subtree (ti, ett_miop);
proto_tree_add_expert_format(miop_tree, pinfo, &ei_miop_version_not_supported,
tvb, 0, -1,
"MIOP version %u.%u not supported",
version_major, version_minor);
return;
}
flags = tvb_get_guint8(tvb, 5);
byte_order = (flags & 0x01) ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN;
if (byte_order == ENC_BIG_ENDIAN) {
packet_length = tvb_get_ntohs(tvb, 6);
packet_number = tvb_get_ntohl(tvb, 8);
number_of_packets = tvb_get_ntohl(tvb, 12);
unique_id_len = tvb_get_ntohl(tvb, 16);
}
else {
packet_length = tvb_get_letohs(tvb, 6);
packet_number = tvb_get_letohl(tvb, 8);
number_of_packets = tvb_get_letohl(tvb, 12);
unique_id_len = tvb_get_letohl(tvb, 16);
}
col_add_fstr (pinfo->cinfo, COL_INFO, "MIOP %u.%u Packet s=%d (%u of %u)",
version_major, version_minor, packet_length,
packet_number + 1,
number_of_packets);
if (tree)
{
ti = proto_tree_add_item (tree, proto_miop, tvb, 0, -1, ENC_NA);
miop_tree = proto_item_add_subtree (ti, ett_miop);
proto_tree_add_item(miop_tree, hf_miop_magic, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_uint_format_value(miop_tree, hf_miop_hdr_version, tvb, offset, 1, hdr_version,
"%u.%u", version_major, version_minor);
offset++;
if (flags & 0x01) {
wmem_strbuf_truncate(flags_strbuf, 0);
wmem_strbuf_append(flags_strbuf, "little-endian");
}
if (flags & 0x02) {
wmem_strbuf_append_printf(flags_strbuf, "%s%s",
wmem_strbuf_get_len(flags_strbuf) ? ", " : "", "last message");
}
proto_tree_add_uint_format_value(miop_tree, hf_miop_flags, tvb, offset, 1,
flags, "0x%02x (%s)", flags, wmem_strbuf_get_str(flags_strbuf));
offset++;
proto_tree_add_item(miop_tree, hf_miop_packet_length, tvb, offset, 2, byte_order);
offset += 2;
proto_tree_add_item(miop_tree, hf_miop_packet_number, tvb, offset, 4, byte_order);
offset += 4;
proto_tree_add_item(miop_tree, hf_miop_number_of_packets, tvb, offset, 4, byte_order);
offset += 4;
ti = proto_tree_add_item(miop_tree, hf_miop_unique_id_len, tvb, offset, 4, byte_order);
if (unique_id_len >= MIOP_MAX_UNIQUE_ID_LENGTH) {
expert_add_info_format(pinfo, ti, &ei_miop_unique_id_len_exceed_max_value,
"Unique Id length (%u) exceeds max value (%u)",
unique_id_len, MIOP_MAX_UNIQUE_ID_LENGTH);
return;
}
offset += 4;
proto_tree_add_item(miop_tree, hf_miop_unique_id, tvb, offset, unique_id_len,
byte_order);
if (packet_number == 0) {
tvbuff_t *payload_tvb;
offset += unique_id_len;
payload_tvb = tvb_new_subset_remaining (tvb, offset);
dissect_giop(payload_tvb, pinfo, tree);
}
}
}
void proto_register_miop (void) {
static hf_register_info hf[] = {
{ &hf_miop_magic,
{ "Magic", "miop.magic", FT_STRING, BASE_NONE, NULL, 0x0,
"PacketHeader magic", HFILL }},
{ &hf_miop_hdr_version,
{ "Version", "miop.hdr_version", FT_UINT8, BASE_HEX, NULL, 0x0,
"PacketHeader hdr_version", HFILL }},
{ &hf_miop_flags,
{ "Flags", "miop.flags", FT_UINT8, BASE_OCT, NULL, 0x0,
"PacketHeader flags", HFILL }},
{ &hf_miop_packet_length,
{ "Length", "miop.packet_length", FT_UINT16, BASE_DEC, NULL, 0x0,
"PacketHeader packet_length", HFILL }},
{ &hf_miop_packet_number,
{ "PacketNumber", "miop.packet_number", FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketHeader packet_number", HFILL }},
{ &hf_miop_number_of_packets,
{ "NumberOfPackets", "miop.number_of_packets", FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketHeader number_of_packets", HFILL }},
{ &hf_miop_unique_id_len,
{ "UniqueIdLength", "miop.unique_id_len", FT_UINT32, BASE_DEC, NULL, 0x0,
"UniqueId length", HFILL }},
{ &hf_miop_unique_id,
{ "UniqueId", "miop.unique_id", FT_BYTES, BASE_NONE, NULL, 0x0,
"UniqueId id", HFILL }},
};
static gint *ett[] = {
&ett_miop
};
static ei_register_info ei[] = {
{ &ei_miop_version_not_supported, { "miop.version.not_supported", PI_UNDECODED, PI_WARN, "MIOP version not supported", EXPFILL }},
{ &ei_miop_unique_id_len_exceed_max_value, { "miop.unique_id_len.exceed_max_value", PI_MALFORMED, PI_WARN, "Unique Id length exceeds max value", EXPFILL }},
};
expert_module_t* expert_miop;
proto_miop = proto_register_protocol("Unreliable Multicast Inter-ORB Protocol", "MIOP", "miop");
proto_register_field_array (proto_miop, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_miop = expert_register_protocol(proto_miop);
expert_register_field_array(expert_miop, ei, array_length(ei));
register_dissector("miop", dissect_miop, proto_miop);
}
void proto_reg_handoff_miop (void) {
dissector_handle_t miop_handle;
miop_handle = find_dissector("miop");
dissector_add_handle("udp.port", miop_handle);
heur_dissector_add("udp", dissect_miop_heur, proto_miop);
}
