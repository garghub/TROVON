static int
dissect_skype_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *skype_tree = NULL;
guint32 offset = 0;
guint32 packet_length;
guint8 packet_type;
packet_type = 255;
packet_length = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(packet_type,
skype_type_vals, "Type 0x%1x"));
if (tree) {
ti = proto_tree_add_item(tree, proto_skype, tvb, offset, -1,
ENC_NA);
skype_tree = proto_item_add_subtree(ti, ett_skype);
switch (packet_type) {
default:
proto_tree_add_item(skype_tree, hf_skype_unknown_packet, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
}
}
return offset;
}
static int
dissect_skype_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *skype_tree = NULL;
guint32 offset = 0;
guint32 packet_length;
guint8 packet_type, packet_unk;
conversation_t *conversation = NULL;
skype_udp_conv_info_t *skype_udp_info;
conversation = find_or_create_conversation(pinfo);
skype_udp_info = (skype_udp_conv_info_t *)conversation_get_proto_data(conversation, proto_skype);
if (!skype_udp_info) {
skype_udp_info = wmem_new(wmem_file_scope(), skype_udp_conv_info_t);
skype_udp_info->global_src_ip = 0;
skype_udp_info->global_dst_ip = 0;
conversation_add_proto_data(conversation, proto_skype,
skype_udp_info);
}
packet_type = tvb_get_guint8(tvb, 2) & SKYPE_SOM_TYPE_MASK;
packet_unk = (tvb_get_guint8(tvb, 2) & SKYPE_SOM_UNK_MASK) >> 4;
packet_length = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(packet_type,
skype_type_vals, "Type 0x%1x"));
if (packet_unk) {
col_append_fstr(pinfo->cinfo, COL_INFO, " Unk: %1x", packet_unk);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_skype, tvb, offset, -1,
ENC_NA);
skype_tree = proto_item_add_subtree(ti, ett_skype);
proto_tree_add_item(skype_tree, hf_skype_som_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(skype_tree, hf_skype_som_unk, tvb, offset, 1,
ENC_NA);
proto_tree_add_item(skype_tree, hf_skype_som_type, tvb, offset, 1,
ENC_NA);
offset += 1;
switch (packet_type) {
case SKYPE_TYPE_UNKNOWN_0:
proto_tree_add_item(skype_tree, hf_skype_unknown_0_unk1, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
case SKYPE_TYPE_PAYLOAD:
proto_tree_add_item(skype_tree, hf_skype_payload_iv, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_payload_crc, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_payload_enc_data, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
case SKYPE_TYPE_FFR:
proto_tree_add_item(skype_tree, hf_skype_ffr_num, tvb, offset, 1,
ENC_NA);
offset += 1;
proto_tree_add_item(skype_tree, hf_skype_ffr_unk1, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_ffr_iv, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_ffr_crc, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_ffr_enc_data, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
case SKYPE_TYPE_NAT_INFO:
proto_tree_add_item(skype_tree, hf_skype_natinfo_srcip, tvb, offset, 4,
ENC_BIG_ENDIAN);
skype_udp_info->global_src_ip = tvb_get_ipv4(tvb, offset);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_natinfo_dstip, tvb, offset, 4,
ENC_BIG_ENDIAN);
skype_udp_info->global_dst_ip = tvb_get_ipv4(tvb, offset);
offset += 4;
break;
case SKYPE_TYPE_NAT_REPEAT:
proto_tree_add_item(skype_tree, hf_skype_natrequest_srcip, tvb, offset, 4,
ENC_BIG_ENDIAN);
skype_udp_info->global_src_ip = tvb_get_ipv4(tvb, offset);
offset += 4;
proto_tree_add_item(skype_tree, hf_skype_natrequest_dstip, tvb, offset, 4,
ENC_BIG_ENDIAN);
skype_udp_info->global_dst_ip = tvb_get_ipv4(tvb, offset);
offset += 4;
break;
case SKYPE_TYPE_AUDIO:
proto_tree_add_item(skype_tree, hf_skype_audio_unk1, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
case SKYPE_TYPE_UNKNOWN_F:
proto_tree_add_item(skype_tree, hf_skype_unknown_f_unk1, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
default:
proto_tree_add_item(skype_tree, hf_skype_unknown_packet, tvb, offset, -1,
ENC_NA);
offset = packet_length;
break;
}
}
return offset;
}
static gboolean
test_skype_udp(tvbuff_t *tvb)
{
guint length = tvb_length(tvb);
guint8 type = tvb_get_guint8(tvb, 2) & 0xF;
if ( length >= 3 &&
( type == 0 ||
type == 2 ||
type == 3 ||
type == 5 ||
type == 7 ||
type == 0xd ||
type == 0xf
)
) {
return TRUE;
}
return FALSE;
}
static gboolean
dissect_skype_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (pinfo->ptype == PT_UDP) {
if ( !test_skype_udp(tvb) ) {
return FALSE;
}
dissect_skype_udp(tvb, pinfo, tree);
}
return TRUE;
}
static int
dissect_skype_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (pinfo->ptype == PT_UDP) {
return dissect_skype_udp(tvb, pinfo, tree);
} else if (pinfo->ptype == PT_UDP) {
return dissect_skype_tcp(tvb, pinfo, tree);
}
return 0;
}
void
proto_register_skype(void)
{
static hf_register_info hf[] = {
{ &hf_skype_som_id,
{ "ID", "skype.som.id", FT_UINT16, BASE_HEX, NULL,
0x0, "Message ID", HFILL }},
{ &hf_skype_som_unk,
{ "Unknown", "skype.som.unk", FT_UINT8, BASE_HEX, NULL,
SKYPE_SOM_UNK_MASK, NULL, HFILL }},
{ &hf_skype_som_type,
{ "Type", "skype.som.type", FT_UINT8, BASE_HEX, VALS(skype_type_vals),
SKYPE_SOM_TYPE_MASK, "Message type", HFILL }},
{ &hf_skype_unknown_0_unk1,
{ "Unknown1", "skype.unknown_0.unk1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_payload_iv,
{ "IV", "skype.payload.iv", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_payload_crc,
{ "CRC", "skype.payload.crc", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_payload_enc_data,
{ "Enc Data", "skype.payload.encdata", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_ffr_num,
{ "Num", "skype.ffr.num", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_ffr_unk1,
{ "Unk1", "skype.ffr.unk1", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_ffr_iv,
{ "IV", "skype.ffr.iv", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_ffr_crc,
{ "CRC", "skype.ffr.crc", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_ffr_enc_data,
{ "Enc Data", "skype.ffr.encdata", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_natinfo_srcip,
{ "Src IP", "skype.natinfo.srcip", FT_IPv4, BASE_NONE, NULL,
0x0, "Global source IP", HFILL }},
{ &hf_skype_natinfo_dstip,
{ "Dst IP", "skype.natinfo.dstip", FT_UINT32, BASE_HEX, NULL,
0x0, "Global destination IP", HFILL }},
{ &hf_skype_natrequest_srcip,
{ "Src IP", "skype.natrequest.srcip", FT_IPv4, BASE_NONE, NULL,
0x0, "Global source IP", HFILL }},
{ &hf_skype_natrequest_dstip,
{ "Dst IP", "skype.natrequest.dstip", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_audio_unk1,
{ "Unknown1", "skype.audio.unk1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_unknown_f_unk1,
{ "Unknown1", "skype.unknown_f.unk1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_skype_unknown_packet,
{ "Unknown Packet", "skype.unknown_packet", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_skype,
};
proto_skype = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "skype");
proto_register_field_array(proto_skype, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_skype(void)
{
dissector_handle_t skype_handle;
skype_handle = new_create_dissector_handle(dissect_skype_static, proto_skype);
dissector_add_for_decode_as("tcp.port", skype_handle);
dissector_add_for_decode_as("udp.port", skype_handle);
#if SKYPE_HEUR
heur_dissector_add("tcp", dissect_skype_heur, proto_skype);
heur_dissector_add("udp", dissect_skype_heur, proto_skype);
#endif
}
