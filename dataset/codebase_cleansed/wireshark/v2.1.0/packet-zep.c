static int dissect_zep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
proto_item *proto_root, *pi;
proto_tree *zep_tree;
guint8 ieee_packet_len;
guint8 zep_header_len;
zep_info zep_data;
dissector_handle_t next_dissector;
if(strcmp(tvb_get_string_enc(wmem_packet_scope(), tvb, 0, 2, ENC_ASCII), ZEP_PREAMBLE)){
return 0;
}
memset(&zep_data, 0, sizeof(zep_data));
zep_data.version = tvb_get_guint8(tvb, 2);
if (zep_data.version == 1) {
zep_header_len = ZEP_V1_HEADER_LEN;
zep_data.type = 0;
zep_data.channel_id = tvb_get_guint8(tvb, 3);
zep_data.device_id = tvb_get_ntohs(tvb, 4);
zep_data.lqi_mode = tvb_get_guint8(tvb, 6)?1:0;
zep_data.lqi = tvb_get_guint8(tvb, 7);
ieee_packet_len = (tvb_get_guint8(tvb, ZEP_V1_HEADER_LEN - 1) & ZEP_LENGTH_MASK);
}
else {
zep_data.type = tvb_get_guint8(tvb, 3);
if (zep_data.type == ZEP_V2_TYPE_ACK) {
zep_header_len = ZEP_V2_ACK_LEN;
zep_data.seqno = tvb_get_ntohl(tvb, 4);
ieee_packet_len = 0;
}
else {
zep_header_len = ZEP_V2_HEADER_LEN;
zep_data.channel_id = tvb_get_guint8(tvb, 4);
zep_data.device_id = tvb_get_ntohs(tvb, 5);
zep_data.lqi_mode = tvb_get_guint8(tvb, 7)?1:0;
zep_data.lqi = tvb_get_guint8(tvb, 8);
ntp_to_nstime(tvb, 9, &(zep_data.ntp_time));
zep_data.seqno = tvb_get_ntohl(tvb, 17);
ieee_packet_len = (tvb_get_guint8(tvb, ZEP_V2_HEADER_LEN - 1) & ZEP_LENGTH_MASK);
}
}
#if 0
if (zep_data.ntp_time.secs && zep_data.ntp_time.nsecs) {
pinfo->abs_ts = zep_data.ntp_time;
}
#endif
if(ieee_packet_len < tvb_reported_length(tvb)-zep_header_len){
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, (zep_data.version==1)?"ZEP":"ZEPv2");
if (!((zep_data.version>=2) && (zep_data.type==ZEP_V2_TYPE_ACK)))
col_add_fstr(pinfo->cinfo, COL_INFO, "Encapsulated ZigBee Packet [Channel]=%i [Length]=%i", zep_data.channel_id, ieee_packet_len);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Ack, Sequence Number: %i", zep_data.seqno);
if(tree){
if (!((zep_data.version>=2) && (zep_data.type==ZEP_V2_TYPE_ACK))) {
proto_root = proto_tree_add_protocol_format(tree, proto_zep, tvb, 0, zep_header_len, "ZigBee Encapsulation Protocol, Channel: %i, Length: %i", zep_data.channel_id, ieee_packet_len);
}
else {
proto_root = proto_tree_add_protocol_format(tree, proto_zep, tvb, 0, zep_header_len, "ZigBee Encapsulation Protocol, Ack");
}
zep_tree = proto_item_add_subtree(proto_root, ett_zep);
proto_tree_add_item(zep_tree, hf_zep_protocol_id, tvb, 0, 2, ENC_NA|ENC_ASCII);
if (zep_data.version==1) {
proto_tree_add_uint(zep_tree, hf_zep_version, tvb, 2, 1, zep_data.version);
proto_tree_add_uint(zep_tree, hf_zep_channel_id, tvb, 3, 1, zep_data.channel_id);
proto_tree_add_uint(zep_tree, hf_zep_device_id, tvb, 4, 2, zep_data.device_id);
proto_tree_add_boolean_format(zep_tree, hf_zep_lqi_mode, tvb, 6, 1, zep_data.lqi_mode, "LQI/CRC Mode: %s", zep_data.lqi_mode?"CRC":"LQI");
if(!(zep_data.lqi_mode)){
proto_tree_add_uint(zep_tree, hf_zep_lqi, tvb, 7, 1, zep_data.lqi);
}
proto_tree_add_item(zep_tree, hf_zep_reserved_field, tvb, 7+((zep_data.lqi_mode)?0:1), 7+((zep_data.lqi_mode)?1:0), ENC_NA);
}
else {
proto_tree_add_uint(zep_tree, hf_zep_version, tvb, 2, 1, zep_data.version);
if (zep_data.type == ZEP_V2_TYPE_ACK) {
proto_tree_add_uint_format_value(zep_tree, hf_zep_type, tvb, 3, 1, zep_data.type, "%i (Ack)", ZEP_V2_TYPE_ACK);
proto_tree_add_uint(zep_tree, hf_zep_seqno, tvb, 4, 4, zep_data.seqno);
}
else {
proto_tree_add_uint_format_value(zep_tree, hf_zep_type, tvb, 3, 1, zep_data.type, "%i (%s)", zep_data.type, (zep_data.type==ZEP_V2_TYPE_DATA)?"Data":"Reserved");
proto_tree_add_uint(zep_tree, hf_zep_channel_id, tvb, 4, 1, zep_data.channel_id);
proto_tree_add_uint(zep_tree, hf_zep_device_id, tvb, 5, 2, zep_data.device_id);
proto_tree_add_boolean_format(zep_tree, hf_zep_lqi_mode, tvb, 7, 1, zep_data.lqi_mode, "LQI/CRC Mode: %s", zep_data.lqi_mode?"CRC":"LQI");
if(!(zep_data.lqi_mode)){
proto_tree_add_uint(zep_tree, hf_zep_lqi, tvb, 8, 1, zep_data.lqi);
}
pi = proto_tree_add_time(zep_tree, hf_zep_timestamp, tvb, 9, 8, &(zep_data.ntp_time));
proto_item_append_text(pi, " (%ld.%09ds)", (long)zep_data.ntp_time.secs, zep_data.ntp_time.nsecs);
proto_tree_add_uint(zep_tree, hf_zep_seqno, tvb, 17, 4, zep_data.seqno);
}
}
if (!((zep_data.version==2) && (zep_data.type==ZEP_V2_TYPE_ACK)))
proto_tree_add_uint_format_value(zep_tree, hf_zep_ieee_length, tvb, zep_header_len - 1, 1, ieee_packet_len, "%i %s", ieee_packet_len, (ieee_packet_len==1)?"Byte":"Bytes");
}
if (zep_data.lqi_mode) {
next_dissector = ieee802154_handle;
}
else {
next_dissector = ieee802154_ccfcs_handle;
}
if (!next_dissector) {
next_dissector = data_handle;
}
if (!((zep_data.version>=2) && (zep_data.type==ZEP_V2_TYPE_ACK))) {
next_tvb = tvb_new_subset_length(tvb, zep_header_len, ieee_packet_len);
call_dissector(next_dissector, next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void proto_register_zep(void)
{
module_t *zep_module;
static hf_register_info hf[] = {
{ &hf_zep_version,
{ "Protocol Version", "zep.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"The version of the sniffer.", HFILL }},
{ &hf_zep_type,
{ "Type", "zep.type", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zep_channel_id,
{ "Channel ID", "zep.channel_id", FT_UINT8, BASE_DEC, NULL, 0x0,
"The logical channel on which this packet was detected.", HFILL }},
{ &hf_zep_device_id,
{ "Device ID", "zep.device_id", FT_UINT16, BASE_DEC, NULL, 0x0,
"The ID of the device that detected this packet.", HFILL }},
{ &hf_zep_lqi_mode,
{ "LQI/CRC Mode", "zep.lqi_mode", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Determines what format the last two bytes of the MAC frame use.", HFILL }},
{ &hf_zep_lqi,
{ "Link Quality Indication", "zep.lqi", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zep_timestamp,
{ "Timestamp", "zep.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL }},
{ &hf_zep_seqno,
{ "Sequence Number", "zep.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zep_ieee_length,
{ "Length", "zep.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The length (in bytes) of the encapsulated IEEE 802.15.4 MAC frame.", HFILL }},
{ &hf_zep_protocol_id,
{ "Protocol ID String", "zep.protocol_id", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zep_reserved_field,
{ "Reserved Fields", "zep.reserved_field", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_zep
};
proto_zep = proto_register_protocol("ZigBee Encapsulation Protocol", "ZEP", "zep");
proto_register_field_array(proto_zep, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
zep_module = prefs_register_protocol(proto_zep, proto_reg_handoff_zep);
prefs_register_uint_preference(zep_module, "udp.port", "ZEP UDP port",
"Set the port for ZEP Protocol\n"
"Default port is 17754",
10, &gPREF_zep_udp_port);
zep_handle = register_dissector("zep", dissect_zep, proto_zep);
}
void proto_reg_handoff_zep(void)
{
static int lastPort;
static gboolean inited = FALSE;
if ( !inited) {
dissector_handle_t h;
if ( !(h = find_dissector("wpan")) ) {
h = find_dissector("ieee802154");
}
ieee802154_handle = h;
if ( !(h = find_dissector("wpan_cc24xx")) ) {
h = find_dissector("ieee802154_ccfcs");
}
ieee802154_ccfcs_handle = h;
data_handle = find_dissector("data");
inited = TRUE;
} else {
dissector_delete_uint("udp.port", lastPort, zep_handle);
}
dissector_add_uint("udp.port", gPREF_zep_udp_port, zep_handle);
lastPort = gPREF_zep_udp_port;
}
