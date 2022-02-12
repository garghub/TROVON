static const char* embedded_time_to_string ( int coarse_time, int fine_time )
{
static int utcdiff = 0;
nstime_t t;
int yr;
int fraction;
int multiplier = 1000;
if ( 0 == utcdiff )
{
for ( yr = 1970; yr < 1980; ++yr )
{
utcdiff += ( Leap(yr) ? 366 : 365 ) * 24 * 60 * 60;
}
utcdiff += 5 * 24 * 60 * 60;
}
t.secs = coarse_time + utcdiff;
fraction = ( multiplier * ( (int)fine_time & 0xff ) ) / 256;
t.nsecs = fraction*1000000;
return abs_time_to_str(wmem_packet_scope(), &t, ABSOLUTE_TIME_DOY_UTC, TRUE);
}
static int
dissect_ccsds(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item *ccsds_packet;
proto_tree *ccsds_tree;
proto_item *primary_header;
proto_tree *primary_header_tree;
guint16 first_word;
guint32 coarse_time;
guint8 fine_time;
proto_item *secondary_header;
proto_tree *secondary_header_tree;
const char *time_string;
gint ccsds_length;
gint length = 0;
gint reported_length;
guint8 checkword_flag = 0;
gint counter = 0;
proto_item *item, *checkword_item = NULL;
proto_tree *checkword_tree;
guint16 checkword_field = 0;
guint16 checkword_sum = 0;
tvbuff_t *next_tvb;
static const int * header_flags[] = {
&hf_ccsds_version,
&hf_ccsds_type,
&hf_ccsds_secheader,
&hf_ccsds_apid,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CCSDS");
col_set_str(pinfo->cinfo, COL_INFO, "CCSDS Packet");
first_word = tvb_get_ntohs(tvb, 0);
col_add_fstr(pinfo->cinfo, COL_INFO, "APID %4d (0x%03X)", first_word&HDR_APID, first_word&HDR_APID);
reported_length = tvb_reported_length_remaining(tvb, 0);
ccsds_length = tvb_get_ntohs(tvb, 4) + CCSDS_PRIMARY_HEADER_LENGTH + 1;
if (ccsds_length > reported_length)
length = reported_length;
else if (ccsds_length < CCSDS_PRIMARY_HEADER_LENGTH + CCSDS_SECONDARY_HEADER_LENGTH)
length = CCSDS_PRIMARY_HEADER_LENGTH + CCSDS_SECONDARY_HEADER_LENGTH;
else
length = ccsds_length;
ccsds_packet = proto_tree_add_item(tree, proto_ccsds, tvb, 0, length, ENC_NA);
ccsds_tree = proto_item_add_subtree(ccsds_packet, ett_ccsds);
primary_header_tree = proto_tree_add_subtree(ccsds_tree, tvb, offset, CCSDS_PRIMARY_HEADER_LENGTH,
ett_ccsds_primary_header, &primary_header, "Primary CCSDS Header");
proto_tree_add_bitmask(primary_header_tree, tvb, offset, hf_ccsds_header_flags,
ett_ccsds_primary_header_flags, header_flags, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(primary_header_tree, hf_ccsds_seqflag, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(primary_header_tree, hf_ccsds_seqnum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
item = proto_tree_add_item(primary_header_tree, hf_ccsds_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if (ccsds_length > reported_length) {
expert_add_info(pinfo, item, &ei_ccsds_length_error);
}
offset += 2;
proto_item_set_end(primary_header, tvb, offset);
if ( first_word & HDR_SECHDR )
{
secondary_header_tree = proto_tree_add_subtree(ccsds_tree, tvb, offset, CCSDS_SECONDARY_HEADER_LENGTH,
ett_ccsds_secondary_header, &secondary_header, "Secondary CCSDS Header");
coarse_time = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(secondary_header_tree, hf_ccsds_coarse_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
fine_time = tvb_get_guint8(tvb, offset);
proto_tree_add_item(secondary_header_tree, hf_ccsds_fine_time, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
time_string = embedded_time_to_string ( coarse_time, fine_time );
proto_tree_add_string(secondary_header_tree, hf_ccsds_embedded_time, tvb, offset-5, 5, time_string);
proto_tree_add_item(secondary_header_tree, hf_ccsds_timeid, tvb, offset, 1, ENC_BIG_ENDIAN);
checkword_item = proto_tree_add_item(secondary_header_tree, hf_ccsds_checkword_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (global_dissect_checkword) {
case 0:
checkword_flag = 0;
break;
case 1:
checkword_flag = 1;
break;
default:
checkword_flag = (tvb_get_guint8(tvb, offset)&0x20) >> 5;
break;
}
if ( first_word & HDR_TYPE )
{
proto_tree_add_item(secondary_header_tree, hf_ccsds_zoe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(secondary_header_tree, hf_ccsds_packet_type_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(secondary_header_tree, hf_ccsds_vid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(secondary_header_tree, hf_ccsds_dcc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
proto_tree_add_item(secondary_header_tree, hf_ccsds_packet_type, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(secondary_header_tree, hf_ccsds_element_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(secondary_header_tree, hf_ccsds_cmd_data_packet, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(secondary_header_tree, hf_ccsds_format_version_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(secondary_header_tree, hf_ccsds_extended_format_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
++offset;
proto_tree_add_item(secondary_header_tree, hf_ccsds_frame_id, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
}
proto_item_set_end(secondary_header, tvb, offset);
}
if (reported_length < ccsds_length || ccsds_length < CCSDS_PRIMARY_HEADER_LENGTH + CCSDS_SECONDARY_HEADER_LENGTH) {
if (length > offset)
proto_tree_add_item(ccsds_tree, hf_ccsds_user_data, tvb, offset, length-offset, ENC_NA);
offset += length-offset;
if (checkword_flag == 1)
expert_add_info(pinfo, checkword_item, &ei_ccsds_checkword);
}
else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint(ccsds_dissector_table, first_word&HDR_APID, next_tvb, pinfo, tree)) {
proto_tree_add_item(ccsds_tree, hf_ccsds_user_data, tvb, offset, length-offset-2*checkword_flag, ENC_NA);
}
offset += length-offset-2*checkword_flag;
if (checkword_flag == 1) {
while (counter < ccsds_length-2) {
checkword_sum += tvb_get_ntohs(tvb, counter);
counter += 2;
}
checkword_field = tvb_get_ntohs(tvb, offset);
if (checkword_sum == checkword_field) {
item = proto_tree_add_uint_format_value(ccsds_tree, hf_ccsds_checkword, tvb, offset, 2, checkword_field,
"0x%04x [correct]", checkword_field);
checkword_tree = proto_item_add_subtree(item, ett_ccsds_checkword);
item = proto_tree_add_boolean(checkword_tree, hf_ccsds_checkword_good, tvb, offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checkword_tree, hf_ccsds_checkword_bad, tvb, offset, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
item = proto_tree_add_uint_format_value(ccsds_tree, hf_ccsds_checkword, tvb, offset, 2, checkword_field,
"0x%04x [incorrect, should be 0x%04x]", checkword_field, checkword_sum);
checkword_tree = proto_item_add_subtree(item, ett_ccsds_checkword);
item = proto_tree_add_boolean(checkword_tree, hf_ccsds_checkword_good, tvb, offset, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checkword_tree, hf_ccsds_checkword_bad, tvb, offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
}
offset += 2;
}
}
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_ccsds(void)
{
static hf_register_info hf[] = {
{ &hf_ccsds_header_flags,
{ "Header Flags", "ccsds.header_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ccsds_version,
{ "Version", "ccsds.version",
FT_UINT16, BASE_DEC, NULL, HDR_VERSION,
NULL, HFILL }
},
{ &hf_ccsds_type,
{ "Type", "ccsds.type",
FT_UINT16, BASE_DEC, VALS(ccsds_secondary_header_type), HDR_TYPE,
NULL, HFILL }
},
{ &hf_ccsds_secheader,
{ "Secondary Header", "ccsds.secheader",
FT_BOOLEAN, 16, NULL, HDR_SECHDR,
"Secondary Header Present", HFILL }
},
{ &hf_ccsds_apid,
{ "APID", "ccsds.apid",
FT_UINT16, BASE_DEC, NULL, HDR_APID,
NULL, HFILL }
},
{ &hf_ccsds_seqflag,
{ "Sequence Flags", "ccsds.seqflag",
FT_UINT16, BASE_DEC, VALS(ccsds_primary_header_sequence_flags), 0xc000,
NULL, HFILL }
},
{ &hf_ccsds_seqnum,
{ "Sequence Number", "ccsds.seqnum",
FT_UINT16, BASE_DEC, NULL, 0x3fff,
NULL, HFILL }
},
{ &hf_ccsds_length,
{ "Packet Length", "ccsds.length",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ccsds_coarse_time,
{ "Coarse Time", "ccsds.coarse_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ccsds_fine_time,
{ "Fine Time", "ccsds.fine_time",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ccsds_timeid,
{ "Time Identifier", "ccsds.timeid",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_ccsds_checkword_flag,
{ "Checkword Indicator", "ccsds.checkword_flag",
FT_BOOLEAN, 8, NULL, 0x20,
"Checkword present", HFILL }
},
{ &hf_ccsds_zoe,
{ "ZOE TLM", "ccsds.zoe",
FT_UINT8, BASE_DEC, NULL, 0x10,
"Contains S-band ZOE Packets", HFILL }
},
{ &hf_ccsds_packet_type_unused,
{ "Packet Type (unused for Ku-band)", "ccsds.packet_type",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ccsds_vid,
{ "Version Identifier", "ccsds.vid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ccsds_dcc,
{ "Data Cycle Counter", "ccsds.dcc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ccsds_spare1,
{ "Spare Bit 1", "ccsds.spare1",
FT_UINT8, BASE_DEC, NULL, 0x10,
"unused spare bit 1", HFILL }
},
#endif
{ &hf_ccsds_packet_type,
{ "Packet Type", "ccsds.packet_type",
FT_UINT8, BASE_DEC, VALS(ccsds_secondary_header_packet_type), 0x0f,
NULL, HFILL }
},
#if 0
{ &hf_ccsds_spare2,
{ "Spare Bit 2", "ccsds.spare2",
FT_UINT16, BASE_DEC, NULL, 0x8000,
NULL, HFILL }
},
#endif
{ &hf_ccsds_element_id,
{ "Element ID", "ccsds.element_id",
FT_UINT16, BASE_DEC, VALS(ccsds_secondary_header_element_id), 0x7800,
NULL, HFILL }
},
{ &hf_ccsds_cmd_data_packet,
{ "Cmd/Data Packet Indicator", "ccsds.cmd_data_packet",
FT_UINT16, BASE_DEC, VALS(ccsds_secondary_header_cmd_data_packet), 0x0400,
NULL, HFILL }
},
{ &hf_ccsds_format_version_id,
{ "Format Version ID", "ccsds.format_version_id",
FT_UINT16, BASE_DEC, NULL, 0x03c0,
NULL, HFILL }
},
{ &hf_ccsds_extended_format_id,
{ "Extended Format ID", "ccsds.extended_format_id",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &ccsds_secondary_header_format_id_ext, 0x003f,
NULL, HFILL }
},
#if 0
{ &hf_ccsds_spare3,
{ "Spare Bits 3", "ccsds.spare3",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
#endif
{ &hf_ccsds_frame_id,
{ "Frame ID", "ccsds.frame_id",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ccsds_embedded_time,
{ "Embedded Time", "ccsds.embedded_time",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ccsds_user_data,
{ "User Data", "ccsds.user_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ccsds_checkword,
{ "CCSDS checkword", "ccsds.checkword",
FT_UINT16, BASE_HEX, NULL, 0x0,
"CCSDS checkword: 16-bit running sum of all bytes excluding the checkword", HFILL }
},
{ &hf_ccsds_checkword_good,
{ "Good", "ccsds.checkword_good",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checkword matches packet content; False: doesn't match content", HFILL }
},
{ &hf_ccsds_checkword_bad,
{ "Bad", "ccsds.checkword_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checkword doesn't match packet content; False: matches content", HFILL }
}
};
static gint *ett[] = {
&ett_ccsds_primary_header_flags,
&ett_ccsds,
&ett_ccsds_primary_header,
&ett_ccsds_secondary_header,
&ett_ccsds_checkword
};
static ei_register_info ei[] = {
{ &ei_ccsds_length_error, { "ccsds.length.error", PI_MALFORMED, PI_ERROR, "Length field value is greater than the packet seen on the wire", EXPFILL }},
{ &ei_ccsds_checkword, { "ccsds.no_checkword", PI_PROTOCOL, PI_WARN, "Packet does not contain a Checkword", EXPFILL }},
};
module_t *ccsds_module;
expert_module_t* expert_ccsds;
proto_ccsds = proto_register_protocol("CCSDS", "CCSDS", "ccsds");
proto_register_field_array(proto_ccsds, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ccsds = expert_register_protocol(proto_ccsds);
expert_register_field_array(expert_ccsds, ei, array_length(ei));
ccsds_handle = register_dissector ( "ccsds", dissect_ccsds, proto_ccsds );
ccsds_module = prefs_register_protocol(proto_ccsds, NULL);
prefs_register_enum_preference(ccsds_module, "global_pref_checkword",
"How to handle the CCSDS checkword",
"Specify how the dissector should handle the CCSDS checkword",
&global_dissect_checkword, dissect_checkword, FALSE);
ccsds_dissector_table = register_dissector_table("ccsds.apid", "CCSDS apid", proto_ccsds, FT_UINT16, BASE_DEC);
}
void
proto_reg_handoff_ccsds(void)
{
dissector_add_for_decode_as_with_preference( "udp.port", ccsds_handle);
}
