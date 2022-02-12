static void
dissect_gmtlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gmhdr_tree, guint offset, guint16 length)
{
proto_tree *ti;
proto_tree *srcport_tree;
guint16 fl;
while (length > 1) {
guint16 tl = tvb_get_ntohs(tvb, offset);
offset += 2;
length -= 2;
fl = tl & 0xff;
switch (tl >> 8) {
case GMHDR_FTYPE_SRCPORT_G: {
guint16 pid;
guint32 tv = tvb_get_ntohl(tvb, offset) >> 8;
if (fl != 3) {
expert_add_info_format(pinfo, gmhdr_tree, &ei_gmhdr_field_length_invalid, "Field length %u invalid", fl);
break;
}
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_srcport_g, tvb, offset, fl, ENC_BIG_ENDIAN);
srcport_tree = proto_item_add_subtree(ti, ett_srcport);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_g_plfm, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_g_gid, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_g_bid, tvb, offset, fl, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_g_pid, tvb, offset, fl, ENC_BIG_ENDIAN);
pid = ((tv & GMHDR_SRCPORT_G_PID_MASK) >> GMHDR_SRCPORT_G_PID_SHFT) - 24;
if (pid >= 1 && pid <= 4) {
proto_item_append_text(ti, " (g%d)", pid);
}
break;
}
case GMHDR_FTYPE_PKTSIZE:
if (fl != 2) {
expert_add_info_format(pinfo, gmhdr_tree, &ei_gmhdr_field_length_invalid, "Field length %u invalid", fl);
break;
}
proto_tree_add_item(gmhdr_tree, hf_gmhdr_pktsize, tvb, offset, fl, ENC_BIG_ENDIAN);
break;
case GMHDR_FTYPE_TIMESTAMP_LOCAL:
case GMHDR_FTYPE_TIMESTAMP_NTP:
case GMHDR_FTYPE_TIMESTAMP_GPS:
case GMHDR_FTYPE_TIMESTAMP_1588:
if (fl != 8) {
expert_add_info_format(pinfo, gmhdr_tree, &ei_gmhdr_field_length_invalid, "Field length %u invalid", fl);
break;
}
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_timestamp, tvb, offset, fl, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
proto_item_append_text(ti, "; Source: %s", val_to_str_const(tl>>8, gmhdr_ftype_timestamp, "Unknown"));
break;
case GMHDR_FTYPE_FCS: {
if (fl != 4) {
expert_add_info_format(pinfo, gmhdr_tree, &ei_gmhdr_field_length_invalid, "Field length %u invalid", fl);
break;
}
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_origcrc, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", CRC (Not Verified)");
break;
}
case GMHDR_FTYPE_SRCPORT_H: {
if (fl != 4) {
expert_add_info_format(pinfo, gmhdr_tree, &ei_gmhdr_field_length_invalid, "Field length %u invalid", fl);
break;
}
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_srcport_h, tvb, offset, fl, ENC_BIG_ENDIAN);
srcport_tree = proto_item_add_subtree(ti, ett_srcport);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_h_plfm, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_h_gid, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_h_bid, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_h_sid, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_h_pid, tvb, offset, fl, ENC_BIG_ENDIAN);
break;
}
default:
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_generic, tvb, offset, fl, ENC_NA);
proto_item_append_text(ti, " [Id: %u, Length: %u]", tl >> 8, fl);
break;
}
offset += fl;
length -= fl;
}
}
static void
dissect_gmhdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ti;
gint16 length;
volatile guint16 encap_proto;
volatile gboolean is_802_2;
proto_tree *volatile gmhdr_tree = NULL;
volatile guint offset = 0;
length = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_item(tree, proto_gmhdr, tvb, offset, length, ENC_NA);
if (gmhdr_summary_in_tree) {
proto_item_append_text(ti, ", Length: %u", length);
}
gmhdr_tree = proto_item_add_subtree(ti, ett_gmhdr);
dissect_gmtlv(tvb, pinfo, gmhdr_tree, offset+1, length-1);
}
offset += length;
encap_proto = tvb_get_ntohs(tvb, offset);
offset += 2;
if (encap_proto <= IEEE_802_3_MAX_LEN) {
is_802_2 = TRUE;
if (tvb_length_remaining(tvb, offset) >= 2) {
if (tvb_get_ntohs(tvb, offset) == 0xffff) {
is_802_2 = FALSE;
}
}
dissect_802_3(encap_proto, is_802_2, tvb, offset, pinfo, tree, gmhdr_tree,
hf_gmhdr_len, hf_gmhdr_trailer, &ei_gmhdr_len, 0);
} else {
ethertype_data_t ethertype_data;
ethertype_data.etype = encap_proto;
ethertype_data.offset_after_ethertype = offset;
ethertype_data.fh_tree = gmhdr_tree;
ethertype_data.etype_id = hf_gmhdr_etype;
ethertype_data.trailer_id = hf_gmhdr_trailer;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
}
}
static int
dissect_gmtimestamp_trailer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *ti;
guint tvblen, trailer_len = 18;
proto_tree *gmtrailer_tree = NULL;
guint offset = 0;
guint32 orig_crc, new_crc, comp_crc;
guint16 port_num;
nstime_t gmtimev;
struct tm *tm = NULL;
if ( ! gmhdr_decode_timestamp_trailer)
return 0;
tvblen = tvb_length(tvb);
if (tvblen < trailer_len)
return 0;
orig_crc = tvb_get_ntohl(tvb, offset);
new_crc = tvb_get_ntohl(tvb, tvblen - 4);
comp_crc = CRC32C_SWAP(crc32_ccitt_tvb_seed(tvb, 14, CRC32C_SWAP(~orig_crc)));
if (comp_crc != new_crc)
return 0;
if (tree) {
ti = proto_tree_add_item(tree, proto_gmtrailer, tvb, offset, trailer_len - 4, ENC_NA);
if (gmtrailer_summary_in_tree) {
offset += 4;
port_num = tvb_get_ntohs(tvb, offset);
offset += 2;
gmtimev.secs = tvb_get_ntohl(tvb, offset);
offset += 4;
gmtimev.nsecs = tvb_get_ntohl(tvb, offset);
tm = localtime(&gmtimev.secs);
proto_item_append_text(ti, ", Port: %d, Timestamp: %d:%02d:%02d.%09d", port_num, tm->tm_hour, tm->tm_min, tm->tm_sec, gmtimev.nsecs);
}
offset = 0;
gmtrailer_tree = proto_item_add_subtree(ti, ett_gmtrailer);
proto_tree_add_item(gmtrailer_tree, hf_gmtrailer_origcrc, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gmtrailer_tree, hf_gmtrailer_portid, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gmtrailer_tree, hf_gmtrailer_timestamp, tvb, offset+6, 8, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
}
return 14;
}
static int
dissect_gmtrailer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *ti;
guint tvblen, length;
proto_tree *gmhdr_tree = NULL;
guint offset;
guint16 cksum, comp_cksum, extra_trailer;
tvblen = tvb_length(tvb);
if (tvblen < 5)
return 0;
extra_trailer = 0;
if (tvb_get_ntohs(tvb, tvblen-4) != ETHERTYPE_GIGAMON) {
if (tvblen < 10){
return 0;
}
if (tvb_get_ntohs(tvb, tvblen-8) == ETHERTYPE_GIGAMON) {
extra_trailer = 4;
} else {
return 0;
}
}
length = tvb_get_guint8(tvb, tvblen-extra_trailer-5);
if ((tvblen-extra_trailer-5) != length)
return 0;
offset = tvblen - extra_trailer - 5 - length;
cksum = tvb_get_ntohs(tvb, tvblen-extra_trailer-2);
{
vec_t vec;
SET_CKSUM_VEC_TVB(vec, tvb, offset, length + 3);
comp_cksum = in_cksum(&vec, 1);
if (pntoh16(&comp_cksum) != cksum) {
return 0;
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_gmhdr, tvb, offset, length + 5, ENC_NA);
if (gmhdr_summary_in_tree) {
proto_item_append_text(ti, ", Length: %u, Checksum: 0x%x", length, cksum);
}
gmhdr_tree = proto_item_add_subtree(ti, ett_gmhdr);
dissect_gmtlv(tvb, pinfo, gmhdr_tree, offset, length);
if (extra_trailer) {
proto_tree_add_item(tree, hf_gmhdr_trailer, tvb, length + 5, extra_trailer, ENC_NA);
}
}
return tvblen;
}
void
proto_register_gmhdr(void)
{
static hf_register_info hf[] = {
{ &hf_gmhdr_srcport_g, {
"Src Port", "gmhdr.srcport_g", FT_UINT24, BASE_HEX,
NULL, 0, "Original Source Port", HFILL }},
{ &hf_gmhdr_srcport_g_plfm, {
"Platform Id", "gmhdr.srcport_g_plfm", FT_UINT24, BASE_DEC,
VALS(gmhdr_plfm_str), GMHDR_SRCPORT_G_PLFM_MASK, "Original Platform Id", HFILL }},
{ &hf_gmhdr_srcport_g_gid, {
"Group Id", "gmhdr.srcport_g_gid", FT_UINT24, BASE_DEC,
NULL, GMHDR_SRCPORT_G_GID_MASK, "Original Source Group Id", HFILL }},
{ &hf_gmhdr_srcport_g_bid, {
"Box Id", "gmhdr.srcport_g_bid", FT_UINT24, BASE_DEC,
NULL, GMHDR_SRCPORT_G_BID_MASK, "Original Source Box Id", HFILL }},
{ &hf_gmhdr_srcport_g_pid, {
"Port Id", "gmhdr.srcport_g_pid", FT_UINT24, BASE_DEC,
NULL, GMHDR_SRCPORT_G_PID_MASK, "Original Source Port Id", HFILL }},
{ &hf_gmhdr_pktsize, {
"Original Packet Size", "gmhdr.pktsize", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_gmhdr_timestamp, {
"Time Stamp", "gmhdr.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, NULL, HFILL }},
{ &hf_gmhdr_generic, {
"Generic Field", "gmhdr.generic", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_gmhdr_etype, {
"Type", "gmhdr.etype", FT_UINT16, BASE_HEX,
VALS(etype_vals), 0x0, "Ethertype", HFILL }},
{ &hf_gmhdr_len, {
"Length", "gmhdr.len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_gmhdr_origcrc, {
"Original CRC", "gmhdr.crc", FT_UINT32, BASE_HEX,
NULL, 0x0, "Original Packet CRC", HFILL }},
{ &hf_gmhdr_srcport_h, {
"Src Port", "gmhdr.srcport", FT_UINT32, BASE_HEX,
NULL, 0, "Original Source Port", HFILL }},
{ &hf_gmhdr_srcport_h_plfm, {
"Platform Id", "gmhdr.srcport_plfm", FT_UINT32, BASE_DEC,
VALS(gmhdr_plfm_str), GMHDR_SRCPORT_H_PLFM_MASK, "Original Platform Id", HFILL }},
{ &hf_gmhdr_srcport_h_gid, {
"Group Id", "gmhdr.srcport_gid", FT_UINT32, BASE_DEC,
NULL, GMHDR_SRCPORT_H_GID_MASK, "Original Source Group Id", HFILL }},
{ &hf_gmhdr_srcport_h_bid, {
"Box Id", "gmhdr.srcport_bid", FT_UINT32, BASE_DEC,
NULL, GMHDR_SRCPORT_H_BID_MASK, "Original Source Box Id", HFILL }},
{ &hf_gmhdr_srcport_h_sid, {
"Slot Id", "gmhdr.srcport_sid", FT_UINT32, BASE_DEC,
NULL, GMHDR_SRCPORT_H_SID_MASK, "Original Source Slot Id", HFILL }},
{ &hf_gmhdr_srcport_h_pid, {
"Port Id", "gmhdr.srcport_pid", FT_UINT32, BASE_DEC,
NULL, GMHDR_SRCPORT_H_PID_MASK, "Original Source Port Id", HFILL }},
{ &hf_gmhdr_trailer, {
"Trailer", "gmhdr.trailer", FT_BYTES, BASE_NONE,
NULL, 0x0, "GMHDR Trailer", HFILL }},
};
static hf_register_info gmtrailer_hf[] = {
{ &hf_gmtrailer_origcrc, {
"Original CRC", "gmtrailer.crc", FT_UINT32, BASE_HEX,
NULL, 0x0, "Original Packet CRC", HFILL }},
{ &hf_gmtrailer_portid, {
"Src Port", "gmtrailer.portid", FT_UINT16, BASE_HEX,
NULL, 0x0, "Origin Source Port", HFILL }},
{ &hf_gmtrailer_timestamp, {
"Time Stamp", "gmtrailer.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_gmhdr,
&ett_srcport
};
static gint *gmtrailer_ett[] = {
&ett_gmtrailer,
};
static ei_register_info ei[] = {
{ &ei_gmhdr_field_length_invalid, { "gmhdr.field_length_invalid", PI_MALFORMED, PI_ERROR, "Field length invalid", EXPFILL }},
{ &ei_gmhdr_len, { "gmhdr.len.past_end", PI_MALFORMED, PI_ERROR, "Length field value goes past the end of the payload", EXPFILL }},
};
module_t *gmhdr_module;
module_t *gmtrailer_module;
expert_module_t* expert_gmhdr;
proto_gmhdr = proto_register_protocol("Gigamon Header", "GMHDR", "gmhdr");
proto_register_field_array(proto_gmhdr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gmhdr = expert_register_protocol(proto_gmhdr);
expert_register_field_array(expert_gmhdr, ei, array_length(ei));
proto_gmtrailer = proto_register_protocol("Gigamon Trailer", "GMTRAILER", "gmtrailer");
proto_register_field_array(proto_gmtrailer, gmtrailer_hf, array_length(gmtrailer_hf));
proto_register_subtree_array(gmtrailer_ett, array_length(gmtrailer_ett));
gmhdr_module = prefs_register_protocol(proto_gmhdr, NULL);
prefs_register_bool_preference(gmhdr_module, "summary_in_tree",
"Show Gigamon header summary in protocol tree",
"Whether the Gigamon header summary line should be shown in the protocol tree",
&gmhdr_summary_in_tree);
gmtrailer_module = prefs_register_protocol(proto_gmtrailer, NULL);
prefs_register_bool_preference(gmtrailer_module, "summary_in_tree",
"Show Gigamon Trailer summary in protocol tree",
"Whether the Gigamon Trailer summary line should be shown in the protocol tree",
&gmtrailer_summary_in_tree);
prefs_register_bool_preference(gmtrailer_module, "decode_trailer_timestamp",
"Decode Gigamon HW timestamp and source id in trailer",
"Whether the Gigamon trailer containing HW timestamp, source id and original CRC should be decoded",
&gmhdr_decode_timestamp_trailer);
}
void
proto_reg_handoff_gmhdr(void)
{
dissector_handle_t gmhdr_handle;
ethertype_handle = find_dissector("ethertype");
gmhdr_handle = create_dissector_handle(dissect_gmhdr, proto_gmhdr);
dissector_add_uint("ethertype", ETHERTYPE_GIGAMON, gmhdr_handle);
heur_dissector_add("eth.trailer", dissect_gmtrailer, proto_gmhdr);
heur_dissector_add("eth.trailer", dissect_gmtimestamp_trailer, proto_gmtrailer);
}
