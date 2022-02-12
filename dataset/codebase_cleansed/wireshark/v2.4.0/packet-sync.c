static int
dissect_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *item, *type_item;
proto_tree *sync_tree;
guint8 type, spare;
guint16 packet_nr, packet_len1, packet_len2;
guint32 timestamp, total_nr_of_packet;
int offset = 0;
tvbuff_t *next_tvb;
type = tvb_get_guint8(tvb, offset) >> 4;
spare = tvb_get_guint8(tvb, offset) & 0x0F;
#if 0
if ( type > 3 )
return 0;
if ( type == 0 && tvb_captured_length(tvb) < 18) {
return 0;
} else if ( type == 1 && tvb_captured_length(tvb) < 11 ) {
return 0;
} else if ( type == 3 && tvb_captured_length(tvb) < 19 ) {
return 0;
}
if ( (type != 2) && (spare != 0) )
return 0;
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SYNC");
col_set_str(pinfo->cinfo, COL_INFO, "MBMS synchronisation protocol");
packet_nr = tvb_get_ntohs(tvb, offset+3);
switch (type) {
case 0:
ti = proto_tree_add_item(tree, proto_sync, tvb, 0, TYPE_0_LEN, ENC_NA);
break;
case 1:
ti = proto_tree_add_item(tree, proto_sync, tvb, 0, TYPE_1_LEN, ENC_NA);
break;
case 2:
ti = proto_tree_add_item(tree, proto_sync, tvb, 0, TYPE_2_LEN + (spare & 0x01 ? 40 : 20), ENC_NA);
break;
case 3:
ti = proto_tree_add_item(tree, proto_sync, tvb, 0,
TYPE_3_LEN + (gint16)(packet_nr % 2 == 0 ?
1.5*packet_nr : 1.5*(packet_nr-1)+2),
ENC_NA);
break;
default:
ti = proto_tree_add_item(tree, proto_sync, tvb, 0, -1, ENC_NA);
break;
}
sync_tree = proto_item_add_subtree(ti, ett_sync);
type_item = proto_tree_add_item(sync_tree, hf_sync_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sync_tree, hf_sync_spare4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
timestamp = tvb_get_ntohs(tvb, offset) * 10;
proto_tree_add_uint(sync_tree, hf_sync_timestamp, tvb, offset, 2, timestamp);
offset += 2;
proto_tree_add_uint(sync_tree, hf_sync_packet_nr, tvb, offset, 2, packet_nr+1);
offset += 2;
proto_tree_add_item(sync_tree, hf_sync_elapsed_octet_ctr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (type) {
case 0:
proto_tree_add_item(sync_tree, hf_sync_total_nr_of_packet, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(sync_tree, hf_sync_total_nr_of_octet, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(sync_tree, hf_sync_header_crc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 1:
item = proto_tree_add_item(sync_tree, hf_sync_header_crc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sync_tree, hf_sync_payload_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, " [Calculated CRC 0x%x]",
crc6_compute_tvb(tvb, offset));
offset += 2;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case 2:
expert_add_info(pinfo, ti, &ei_sync_pdu_type2);
break;
case 3:
total_nr_of_packet = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(sync_tree, hf_sync_total_nr_of_packet, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(sync_tree, hf_sync_total_nr_of_octet, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(sync_tree, hf_sync_header_crc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sync_tree, hf_sync_payload_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (offset < (gint)tvb_reported_length(tvb)) {
int i;
if (total_nr_of_packet != 0 && packet_nr % 2 == 0) {
for (i = 1; i < packet_nr; i+=2, offset+=3) {
packet_len1 = tvb_get_bits16(tvb, offset*8, 12, ENC_BIG_ENDIAN);
packet_len2 = tvb_get_bits16(tvb, offset*8+12, 12, ENC_BIG_ENDIAN);
proto_tree_add_string_format(sync_tree, hf_sync_length_of_packet, tvb, offset, 2, "", "Length of Packet %u : %hu", i, packet_len1);
proto_tree_add_string_format(sync_tree, hf_sync_length_of_packet, tvb, offset+1, 2, "", "Length of Packet %u : %hu", i+1, packet_len2);
}
} else {
for (i = 1; i < packet_nr; i+=2, offset+=3) {
packet_len1 = tvb_get_bits16(tvb, offset*8, 12, ENC_BIG_ENDIAN);
packet_len2 = tvb_get_bits16(tvb, offset*8+12, 12, ENC_BIG_ENDIAN);
proto_tree_add_string_format(sync_tree, hf_sync_length_of_packet, tvb, offset, 2, "", "Length of Packet %u : %hu", i, packet_len1);
proto_tree_add_string_format(sync_tree, hf_sync_length_of_packet, tvb, offset+1, 2, "", "Length of Packet %u : %hu", i+1, packet_len2);
}
packet_len1 = tvb_get_bits16(tvb, offset*8, 12, ENC_BIG_ENDIAN);
proto_tree_add_string_format(sync_tree, hf_sync_length_of_packet, tvb, offset, 2, "", "Length of Packet %u : %hu", packet_nr, packet_len1);
offset++;
proto_tree_add_item(sync_tree, hf_sync_spare4, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
break;
default:
expert_add_info(pinfo, type_item, &ei_sync_type);
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_sync(void)
{
static hf_register_info hf_sync[] = {
{ &hf_sync_type,
{ "PDU Type", "sync.type",
FT_UINT8, BASE_DEC, VALS(sync_type_vals), 0xF0,
NULL, HFILL }
},
{ &hf_sync_spare4,
{ "Spare", "sync.spare",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_sync_timestamp,
{ "Timestamp", "sync.timestamp",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0x0,
"Relative time value for the starting time of a synchronisation sequence within the synchronisation period.", HFILL }
},
{ &hf_sync_packet_nr,
{ "Packet Number", "sync.packet_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of elapsed SYNC PDUs cumulatively within the synchronisation sequence.", HFILL }
},
{ &hf_sync_elapsed_octet_ctr,
{ "Elapsed Octet Counter", "sync.elapsed_octet_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of elapsed cumulative octets cumulatively within one synchronisation sequence.", HFILL }
},
{ &hf_sync_total_nr_of_packet,
{ "Total Number of Packet", "sync.total_nr_of_packet",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Cumulatively the number of the packets for the MBMS service within one synchronisation period.", HFILL }
},
{ &hf_sync_total_nr_of_octet,
{ "Total Number of Octet", "sync.total_nr_of_octet",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Cumulatively the number of the octets for the MBMS service within one synchronisation period.", HFILL }
},
{ &hf_sync_header_crc,
{ "Header CRC", "sync.header_crc",
FT_UINT8, BASE_HEX, NULL, 0xFC,
NULL, HFILL }
},
{ &hf_sync_payload_crc,
{ "Payload CRC", "sync.payload_crc",
FT_UINT16, BASE_HEX, NULL, 0x3FF,
NULL, HFILL }
},
{ &hf_sync_length_of_packet,
{ "Length of Packet", "sync.length_of_packet",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett_sync_array[] = {
&ett_sync
};
static ei_register_info ei[] = {
{ &ei_sync_pdu_type2, { "sync.pdu_type2", PI_UNDECODED, PI_WARN, "SYNC PDU type 2 unsupported", EXPFILL }},
{ &ei_sync_type, { "sync.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown SYNC PDU type", EXPFILL }},
};
expert_module_t* expert_sync;
proto_sync = proto_register_protocol("MBMS synchronisation protocol", "SYNC", "sync");
proto_register_field_array(proto_sync, hf_sync, array_length(hf_sync));
proto_register_subtree_array(ett_sync_array, array_length(ett_sync_array));
expert_sync = expert_register_protocol(proto_sync);
expert_register_field_array(expert_sync, ei, array_length(ei));
sync_handle = register_dissector("sync", dissect_sync, proto_sync);
}
void
proto_reg_handoff_sync(void)
{
ip_handle = find_dissector_add_dependency("ip", proto_sync);
dissector_add_for_decode_as_with_preference("udp.port", sync_handle);
}
