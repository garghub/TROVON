static guint8
CRC_Calc_Header(
guint8 dataValue,
guint8 crcValue)
{
guint16 crc;
crc = crcValue ^ dataValue;
crc = crc ^ (crc << 1) ^ (crc << 2) ^ (crc << 3)
^ (crc << 4) ^ (crc << 5) ^ (crc << 6)
^ (crc << 7);
return (crc & 0xfe) ^ ((crc >> 8) & 1);
}
static guint16
CRC_Calc_Data(
guint8 dataValue,
guint16 crcValue)
{
guint16 crcLow;
crcLow = (crcValue & 0xff) ^ dataValue;
return (crcValue >> 8) ^ (crcLow << 8) ^ (crcLow << 3)
^ (crcLow << 12) ^ (crcLow >> 4)
^ (crcLow & 0x0f) ^ ((crcLow & 0x0f) << 7);
}
const gchar *
mstp_frame_type_text(guint32 val)
{
return val_to_str(val,
bacnet_mstp_frame_type_name,
"Unknown Frame Type (%u)");
}
void
dissect_mstp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *subtree, gint offset)
{
guint8 mstp_frame_type = 0;
guint16 mstp_frame_pdu_len = 0;
guint16 mstp_tvb_pdu_len = 0;
guint16 vendorid = 0;
tvbuff_t *next_tvb = NULL;
proto_item *item;
#if defined(BACNET_MSTP_CHECKSUM_VALIDATE)
guint8 crc8 = 0xFF, framecrc8;
guint16 crc16 = 0xFFFF, framecrc16;
guint8 crcdata;
guint16 i;
guint16 max_len = 0;
proto_tree *checksum_tree;
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BACnet");
col_set_str(pinfo->cinfo, COL_INFO, "BACnet MS/TP");
mstp_frame_type = tvb_get_guint8(tvb, offset);
mstp_frame_pdu_len = tvb_get_ntohs(tvb, offset+3);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
mstp_frame_type_text(mstp_frame_type));
}
proto_tree_add_item(subtree, hf_mstp_frame_type, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_mstp_frame_destination, tvb,
offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_mstp_frame_source, tvb,
offset+2, 1, ENC_LITTLE_ENDIAN);
item = proto_tree_add_item(subtree, hf_mstp_frame_pdu_len, tvb,
offset+3, 2, ENC_BIG_ENDIAN);
mstp_tvb_pdu_len = tvb_length_remaining(tvb, offset+6);
if (mstp_tvb_pdu_len > 2) {
if (mstp_frame_pdu_len > (mstp_tvb_pdu_len-2)) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Length field value goes past the end of the payload");
}
}
#if defined(BACNET_MSTP_CHECKSUM_VALIDATE)
for (i = 0; i < 5; i++) {
crcdata = tvb_get_guint8(tvb, offset+i);
crc8 = CRC_Calc_Header(crcdata, crc8);
}
crc8 = ~crc8;
framecrc8 = tvb_get_guint8(tvb, offset+5);
if (framecrc8 == crc8) {
item = proto_tree_add_uint_format(subtree, hf_mstp_frame_crc8,
tvb, offset+5, 1, framecrc8,
"Header CRC: 0x%02x [correct]", framecrc8);
checksum_tree = proto_item_add_subtree(item, ett_bacnet_mstp_checksum);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_good,
tvb, offset+5, 1, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_bad,
tvb, offset+5, 1, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
item = proto_tree_add_uint_format(subtree, hf_mstp_frame_crc8,
tvb, offset+5, 1, framecrc8,
"Header CRC: 0x%02x [incorrect, should be 0x%02x]",
framecrc8, crc8);
checksum_tree = proto_item_add_subtree(item, ett_bacnet_mstp_checksum);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_good,
tvb, offset+5, 1, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_bad,
tvb, offset+5, 1, TRUE);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info_format(pinfo, item, PI_CHECKSUM, PI_ERROR,
"Bad Checksum");
}
#else
proto_tree_add_item(subtree, hf_mstp_frame_crc8,
tvb, offset+5, 1, ENC_LITTLE_ENDIAN);
#endif
offset += 6;
if (mstp_tvb_pdu_len > 2) {
mstp_tvb_pdu_len -= 2;
if (mstp_frame_type < 128) {
vendorid = 0;
next_tvb = tvb_new_subset(tvb, offset,
mstp_tvb_pdu_len, mstp_frame_pdu_len);
} else {
vendorid = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_mstp_frame_vendor_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, offset+2,
mstp_tvb_pdu_len-2, mstp_frame_pdu_len);
}
if (!(dissector_try_uint(subdissector_table, (vendorid<<16) + mstp_frame_type,
next_tvb, pinfo, tree))) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
#if defined(BACNET_MSTP_CHECKSUM_VALIDATE)
max_len = MIN(mstp_frame_pdu_len, mstp_tvb_pdu_len);
for (i = 0; i < max_len; i++) {
crcdata = tvb_get_guint8(tvb, offset+i);
crc16 = CRC_Calc_Data(crcdata, crc16);
}
crc16 = ~crc16;
crc16 = g_htons(crc16);
framecrc16 = tvb_get_ntohs(tvb, offset+mstp_frame_pdu_len);
if (framecrc16 == crc16) {
item = proto_tree_add_uint_format(subtree, hf_mstp_frame_crc16,
tvb, offset+mstp_frame_pdu_len, 2, framecrc16,
"Data CRC: 0x%04x [correct]", framecrc16);
checksum_tree = proto_item_add_subtree(item,
ett_bacnet_mstp_checksum);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_good,
tvb, offset+mstp_frame_pdu_len, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_bad,
tvb, offset+mstp_frame_pdu_len, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
item = proto_tree_add_uint_format(subtree, hf_mstp_frame_crc16,
tvb, offset+mstp_frame_pdu_len, 2, framecrc16,
"Data CRC: 0x%04x [incorrect, should be 0x%04x]",
framecrc16, crc16);
checksum_tree = proto_item_add_subtree(item,
ett_bacnet_mstp_checksum);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_good,
tvb, offset+mstp_frame_pdu_len, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree,
hf_mstp_frame_checksum_bad,
tvb, offset+mstp_frame_pdu_len, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info_format(pinfo, item, PI_CHECKSUM, PI_ERROR,
"Bad Checksum");
}
#else
proto_tree_add_item(subtree, hf_mstp_frame_crc16,
tvb, offset+mstp_frame_pdu_len, 2, ENC_LITTLE_ENDIAN);
#endif
}
}
static void
dissect_mstp_wtap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *subtree;
gint offset = 0;
#ifdef BACNET_MSTP_SUMMARY_IN_TREE
guint8 mstp_frame_type = 0;
guint8 mstp_frame_source = 0;
guint8 mstp_frame_destination = 0;
#endif
TVB_SET_ADDRESS(&pinfo->dl_dst, AT_ARCNET, tvb, offset+3, 1);
TVB_SET_ADDRESS(&pinfo->dst, AT_ARCNET, tvb, offset+3, 1);
TVB_SET_ADDRESS(&pinfo->dl_src, AT_ARCNET, tvb, offset+4, 1);
TVB_SET_ADDRESS(&pinfo->src, AT_ARCNET, tvb, offset+4, 1);
#ifdef BACNET_MSTP_SUMMARY_IN_TREE
mstp_frame_type = tvb_get_guint8(tvb, offset+2);
mstp_frame_destination = tvb_get_guint8(tvb, offset+3);
mstp_frame_source = tvb_get_guint8(tvb, offset+4);
ti = proto_tree_add_protocol_format(tree, proto_mstp, tvb, offset, 8,
"BACnet MS/TP, Src (%u), Dst (%u), %s",
mstp_frame_source, mstp_frame_destination,
mstp_frame_type_text(mstp_frame_type));
#else
ti = proto_tree_add_item(tree, proto_mstp, tvb, offset, 8, ENC_NA);
#endif
subtree = proto_item_add_subtree(ti, ett_bacnet_mstp);
proto_tree_add_item(subtree, hf_mstp_preamble_55, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_mstp_preamble_FF, tvb,
offset+1, 1, ENC_LITTLE_ENDIAN);
dissect_mstp(tvb, pinfo, tree, subtree, offset+2);
}
void
proto_register_mstp(void)
{
static hf_register_info hf[] = {
{ &hf_mstp_preamble_55,
{ "Preamble 55", "mstp.preamble_55",
FT_UINT8, BASE_HEX, NULL, 0,
"MS/TP Preamble 55", HFILL }
},
{ &hf_mstp_preamble_FF,
{ "Preamble FF", "mstp.preamble_FF",
FT_UINT8, BASE_HEX, NULL, 0,
"MS/TP Preamble FF", HFILL }
},
{ &hf_mstp_frame_type,
{ "Frame Type", "mstp.frame_type",
FT_UINT8, BASE_DEC, VALS(bacnet_mstp_frame_type_name), 0,
"MS/TP Frame Type", HFILL }
},
{ &hf_mstp_frame_destination,
{ "Destination Address", "mstp.dst",
FT_UINT8, BASE_DEC, NULL, 0,
"Destination MS/TP MAC Address", HFILL }
},
{ &hf_mstp_frame_source,
{ "Source Address", "mstp.src",
FT_UINT8, BASE_DEC, NULL, 0,
"Source MS/TP MAC Address", HFILL }
},
{ &hf_mstp_frame_vendor_id,
{ "VendorID", "mstp.vendorid",
FT_UINT16, BASE_DEC, NULL, 0,
"MS/TP Vendor ID of proprietary frametypes", HFILL }
},
{ &hf_mstp_frame_pdu_len,
{ "Length", "mstp.len",
FT_UINT16, BASE_DEC, NULL, 0,
"MS/TP Data Length", HFILL }
},
{ &hf_mstp_frame_crc8,
{ "Header CRC", "mstp.hdr_crc",
FT_UINT8, BASE_HEX, NULL, 0,
"MS/TP Header CRC", HFILL }
},
{ &hf_mstp_frame_crc16,
{ "Data CRC", "mstp.data_crc",
FT_UINT16, BASE_HEX, NULL, 0,
"MS/TP Data CRC", HFILL }
},
{ &hf_mstp_frame_checksum_bad,
{ "Bad", "mstp.checksum_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content or not checked", HFILL }
},
{ &hf_mstp_frame_checksum_good,
{ "Good", "mstp.checksum_good",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }
}
};
static gint *ett[] = {
&ett_bacnet_mstp,
&ett_bacnet_mstp_checksum
};
proto_mstp = proto_register_protocol("BACnet MS/TP",
"BACnet MS/TP", "mstp");
proto_register_field_array(proto_mstp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mstp", dissect_mstp_wtap, proto_mstp);
subdissector_table = register_dissector_table("mstp.vendor_frame_type",
"MSTP Vendor specific Frametypes", FT_UINT24, BASE_DEC);
}
void
proto_reg_handoff_mstp(void)
{
dissector_handle_t mstp_handle;
dissector_handle_t bacnet_handle;
mstp_handle = find_dissector("mstp");
dissector_add_uint("wtap_encap", WTAP_ENCAP_BACNET_MS_TP, mstp_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BACNET_MS_TP_WITH_PHDR, mstp_handle);
bacnet_handle = find_dissector("bacnet");
data_handle = find_dissector("data");
dissector_add_uint("mstp.vendor_frame_type", (0 << 16) + MSTP_BACNET_DATA_EXPECTING_REPLY, bacnet_handle);
dissector_add_uint("mstp.vendor_frame_type", (0 << 16) + MSTP_BACNET_DATA_NOT_EXPECTING_REPLY, bacnet_handle);
}
