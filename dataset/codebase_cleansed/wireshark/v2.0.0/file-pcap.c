static int
dissect_pcap_pseudoheader(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
guint32 *link_type;
guint32 length = 0;
tvbuff_t *next_tvb;
proto_item *pseudoheader_item;
proto_tree *pseudoheader_tree = NULL;
proto_item *packet_item;
proto_tree *packet_tree;
DISSECTOR_ASSERT(data);
link_type = (guint32 *) data;
pinfo->phdr->pkt_encap = wtap_pcap_encap_to_wtap_encap(*link_type);
switch (*link_type) {
case 139:
break;
case 196:
length = 5;
break;
case 197:
break;
case 201:
length = 4;
break;
case 204:
length = 1;
break;
case 205:
length = 1;
break;
case 206:
length = 1;
break;
case 209:
length = 6;
break;
case 226:
length = 24;
break;
case 227:
break;
case 240:
case 241:
length = 4;
break;
case 244:
length = 20;
break;
case 245:
length = 20;
break;
}
if (length > 0) {
pseudoheader_item = proto_tree_add_item(tree, hf_pcap_packet_data_pseudoheader, tvb, offset, length, ENC_NA);
pseudoheader_tree = proto_item_add_subtree(pseudoheader_item, ett_pcap_pseudoheader);
}
switch (*link_type) {
case 201:
proto_tree_add_item(pseudoheader_tree, hf_pcap_packet_data_pseudoheader_bluetooth_direction, tvb, offset, 4, ENC_BIG_ENDIAN);
if (tvb_get_guint32(tvb, offset, ENC_BIG_ENDIAN) == 0)
pinfo->p2p_dir = P2P_DIR_SENT;
else if (tvb_get_guint32(tvb, offset, ENC_BIG_ENDIAN) == 1)
pinfo->p2p_dir = P2P_DIR_RECV;
else
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
offset += 4;
break;
default:
offset += length;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
packet_item = proto_tree_add_item(tree, hf_pcap_packet_data_data, tvb, offset, tvb_reported_length(next_tvb), ENC_NA);
packet_tree = proto_item_add_subtree(packet_item, ett_pcap_packet_data);
offset = dissector_try_uint_new(wtap_encap_table, pinfo->phdr->pkt_encap, next_tvb, pinfo, packet_tree, TRUE, NULL);
return offset;
}
static int
dissect_pcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
static const guint8 pcap_magic[] = { 0xA1, 0xB2, 0xC3, 0xD4 };
static const guint8 pcap_swapped_magic[] = { 0xD4, 0xC3, 0xB2, 0xA1 };
volatile gint offset = 0;
proto_tree *main_tree;
proto_item *main_item;
proto_tree *header_tree;
proto_item *header_item;
proto_tree *packet_tree;
proto_item *packet_item;
proto_tree *timestamp_tree;
proto_item *timestamp_item;
proto_tree *packet_data_tree;
proto_item *packet_data_item;
volatile guint32 encoding;
guint32 origin_length;
guint32 length;
guint32 link_type;
volatile guint32 frame_number = 1;
nstime_t timestamp;
if (tvb_memeql(tvb, 0, pcap_magic, sizeof(pcap_magic)) &&
tvb_memeql(tvb, 0, pcap_swapped_magic, sizeof(pcap_swapped_magic)))
return 0;
main_item = proto_tree_add_item(tree, proto_pcap, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_pcap);
header_item = proto_tree_add_item(main_tree, hf_pcap_header , tvb, offset, 24, ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pcap_header);
proto_tree_add_item(header_tree, hf_pcap_header_magic_number, tvb, offset, 4, ENC_HOST_ENDIAN);
encoding = tvb_get_guint32(tvb, offset, ENC_HOST_ENDIAN);
if (encoding == 0xA1B2C3D4) {
encoding = ENC_LITTLE_ENDIAN;
} else if (encoding == 0xD4C3B2A1) {
encoding = ENC_BIG_ENDIAN;
} else {
expert_add_info(pinfo, main_item, &ei_unknown_encoding);
return offset;
}
offset += 4;
proto_tree_add_item(header_tree, hf_pcap_header_version_major, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(header_tree, hf_pcap_header_version_minor, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(header_tree, hf_pcap_header_this_zone, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(header_tree, hf_pcap_header_sigfigs, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(header_tree, hf_pcap_header_snapshot_length, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(header_tree, hf_pcap_header_link_type, tvb, offset, 4, encoding);
link_type = tvb_get_guint32(tvb, offset, encoding);
offset += 4;
while (offset < (gint) tvb_reported_length(tvb)) {
packet_item = proto_tree_add_item(main_tree, hf_pcap_packet, tvb, offset, 4 * 4, ENC_NA);
packet_tree = proto_item_add_subtree(packet_item, ett_pcap_packet);
proto_item_append_text(packet_item, " %u", frame_number);
timestamp.secs = tvb_get_guint32(tvb, offset, encoding);
timestamp.nsecs = tvb_get_guint32(tvb, offset + 4, encoding) * 1000;
timestamp_item = proto_tree_add_time(packet_tree, hf_pcap_packet_timestamp, tvb, offset, 8, &timestamp);
timestamp_tree = proto_item_add_subtree(timestamp_item, ett_pcap_timestamp);
proto_tree_add_item(timestamp_tree, hf_pcap_packet_timestamp_sec, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(timestamp_tree, hf_pcap_packet_timestamp_usec, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item_ret_uint(packet_tree, hf_pcap_packet_included_length, tvb, offset, 4, encoding, &length);
offset += 4;
proto_tree_add_item_ret_uint(packet_tree, hf_pcap_packet_origin_length, tvb, offset, 4, encoding, &origin_length);
offset += 4;
packet_data_item = proto_tree_add_item(packet_tree, hf_pcap_packet_data, tvb, offset, length, ENC_NA);
packet_data_tree = proto_item_add_subtree(packet_data_item, ett_pcap_packet_data);
pinfo->fd->num = frame_number;
pinfo->fd->abs_ts = timestamp;
if (pref_dissect_next_layer) {
TRY {
call_dissector_with_data(pcap_pseudoheader_handle, tvb_new_subset(tvb, offset, length, origin_length), pinfo, packet_data_tree, &link_type);
}
CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, packet_data_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
}
offset += length;
proto_item_set_len(packet_item, 4 * 4 + length);
frame_number += 1;
}
return offset;
}
static gboolean
dissect_pcap_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_pcap(tvb, pinfo, tree, NULL) > 0;
}
void
proto_register_file_pcap(void)
{
module_t *module;
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_pcap_header,
{ "Header", "pcap.header",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_magic_number,
{ "Magic Bytes", "pcap.header.magic_bytes",
FT_UINT32, BASE_HEX, VALS(magic_number_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_version_major,
{ "Version Major", "pcap.header.version.major",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_version_minor,
{ "Version Minor", "pcap.header.version.minor",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_this_zone,
{ "This Zone", "pcap.header.this_zone",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_sigfigs,
{ "Sigfigs", "pcap.header.sigfigs",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_snapshot_length,
{ "Snapshot Length", "pcap.header.snapshot_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_link_type,
{ "Link Type", "pcap.header.link_type",
FT_UINT32, BASE_DEC_HEX, VALS(link_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet,
{ "Packet", "pcap.packet",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_timestamp,
{ "Timestamp", "pcap.packet.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_timestamp_sec,
{ "Timestamp sec", "pcap.packet.timestamp.sec",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_timestamp_usec,
{ "Timestamp usec", "pcap.packet.timestamp.usec",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_included_length,
{ "Included Length", "pcap.packet.included_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_origin_length,
{ "Origin Length", "pcap.packet.origin_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_data,
{ "Data", "pcap.packet.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_data_pseudoheader,
{ "Pseudoheader", "pcap.packet.data.pseudoheader",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_data_pseudoheader_bluetooth_direction,
{ "Direction", "pcap.packet.data.pseudoheader.bluetooth.direction",
FT_UINT32, BASE_HEX, VALS(pseudoheader_bluetooth_direction_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcap_packet_data_data,
{ "Data", "pcap.packet.data.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_unknown_encoding, { "pcap.unknown_encoding", PI_PROTOCOL, PI_ERROR, "Unknown Encoding", EXPFILL }}
};
static gint *ett[] = {
&ett_pcap,
&ett_pcap_header,
&ett_pcap_packet,
&ett_pcap_packet_data,
&ett_pcap_pseudoheader,
&ett_pcap_timestamp
};
proto_pcap = proto_register_protocol("PCAP File Format", "File-PCAP", "file-pcap");
proto_register_field_array(proto_pcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pcap_handle = new_register_dissector("file-pcap", dissect_pcap, proto_pcap);
pcap_pseudoheader_handle = new_create_dissector_handle(dissect_pcap_pseudoheader, proto_pcap);
module = prefs_register_protocol(proto_pcap, NULL);
prefs_register_static_text_preference(module, "version",
"PCAP version: >=2.4",
"Version of file-format supported by this dissector.");
prefs_register_bool_preference(module, "dissect_next_layer",
"Dissect next layer",
"Dissect next layer",
&pref_dissect_next_layer);
expert_module = expert_register_protocol(proto_pcap);
expert_register_field_array(expert_module, ei, array_length(ei));
}
void
proto_reg_handoff_file_pcap(void)
{
heur_dissector_add("wtap_file", dissect_pcap_heur, "PCAP File", "pcap_wtap", proto_pcap, HEURISTIC_ENABLE);
wtap_encap_table = find_dissector_table("wtap_encap");
}
