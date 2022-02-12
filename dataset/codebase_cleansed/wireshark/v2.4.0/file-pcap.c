static int
dissect_pcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
static const guint8 pcap_big_endian_magic[MAGIC_NUMBER_SIZE] = {
0xa1, 0xb2, 0xc3, 0xd4
};
static const guint8 pcap_little_endian_magic[MAGIC_NUMBER_SIZE] = {
0xd4, 0xc3, 0xb2, 0xa1
};
static const guint8 pcap_nsec_big_endian_magic[MAGIC_NUMBER_SIZE] = {
0xa1, 0xb2, 0x3c, 0xd4
};
static const guint8 pcap_nsec_little_endian_magic[MAGIC_NUMBER_SIZE] = {
0xd4, 0x3c, 0xb2, 0xa1
};
volatile gint offset = 0;
proto_tree *main_tree;
proto_item *main_item;
proto_tree *header_tree;
proto_item *header_item;
proto_item *magic_number_item;
proto_tree *packet_tree;
proto_item *packet_item;
proto_tree *timestamp_tree;
proto_item *timestamp_item;
proto_tree *packet_data_tree;
proto_item *packet_data_item;
volatile guint32 encoding;
volatile guint timestamp_scale_factor;
const char *magic;
guint32 origin_length;
guint32 length;
guint32 link_type;
volatile guint32 frame_number = 1;
nstime_t timestamp;
if (tvb_memeql(tvb, 0, pcap_big_endian_magic, MAGIC_NUMBER_SIZE) == 0) {
encoding = ENC_BIG_ENDIAN;
timestamp_scale_factor = 1000;
magic = "Big-endian";
} else if (tvb_memeql(tvb, 0, pcap_little_endian_magic, MAGIC_NUMBER_SIZE) == 0) {
encoding = ENC_LITTLE_ENDIAN;
timestamp_scale_factor = 1000;
magic = "Little-endian";
} else if (tvb_memeql(tvb, 0, pcap_nsec_big_endian_magic, MAGIC_NUMBER_SIZE) == 0) {
encoding = ENC_BIG_ENDIAN;
timestamp_scale_factor = 1;
magic = "Big-endian, nanosecond resolution";
} else if (tvb_memeql(tvb, 0, pcap_nsec_little_endian_magic, MAGIC_NUMBER_SIZE) == 0) {
encoding = ENC_LITTLE_ENDIAN;
timestamp_scale_factor = 1;
magic = "Little-endian, nanosecond resolution";
} else {
return 0;
}
main_item = proto_tree_add_item(tree, proto_pcap, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_pcap);
header_item = proto_tree_add_item(main_tree, hf_pcap_header , tvb, offset, 24, ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pcap_header);
magic_number_item = proto_tree_add_item(header_tree, hf_pcap_header_magic_number, tvb, offset, 4, ENC_NA);
proto_item_append_text(magic_number_item, " (%s)", magic);
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
timestamp.nsecs = tvb_get_guint32(tvb, offset + 4, encoding) * timestamp_scale_factor;
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
pinfo->num = frame_number;
pinfo->abs_ts = timestamp;
if (pref_dissect_next_layer) {
TRY {
call_dissector_with_data(pcap_pktdata_handle, tvb_new_subset_length_caplen(tvb, offset, length, origin_length), pinfo, packet_data_tree, &link_type);
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
static hf_register_info hf[] = {
{ &hf_pcap_header,
{ "Header", "pcap.header",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_header_magic_number,
{ "Magic Number", "pcap.header.magic_number",
FT_BYTES, BASE_NONE, NULL, 0x00,
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
};
static gint *ett[] = {
&ett_pcap,
&ett_pcap_header,
&ett_pcap_packet,
&ett_pcap_packet_data,
&ett_pcap_timestamp
};
proto_pcap = proto_register_protocol("PCAP File Format", "File-PCAP", "file-pcap");
proto_register_field_array(proto_pcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("file-pcap", dissect_pcap, proto_pcap);
module = prefs_register_protocol(proto_pcap, NULL);
prefs_register_static_text_preference(module, "version",
"PCAP version: >=2.4",
"Version of file-format supported by this dissector.");
prefs_register_bool_preference(module, "dissect_next_layer",
"Dissect next layer",
"Dissect next layer",
&pref_dissect_next_layer);
}
void
proto_reg_handoff_file_pcap(void)
{
heur_dissector_add("wtap_file", dissect_pcap_heur, "PCAP File", "pcap_wtap", proto_pcap, HEURISTIC_ENABLE);
pcap_pktdata_handle = find_dissector_add_dependency("pcap_pktdata", proto_pcap);
}
