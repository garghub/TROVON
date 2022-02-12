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
case GMHDR_FTYPE_SRCPORT: {
guint16 pid;
guint32 tv = tvb_get_ntohl(tvb, offset) >> 8;
if (fl != 3) {
expert_add_info_format(pinfo, gmhdr_tree, PI_MALFORMED, PI_ERROR, "Field length %u invalid", fl);
break;
}
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_srcport, tvb, offset, fl, ENC_BIG_ENDIAN);
srcport_tree = proto_item_add_subtree(ti, ett_srcport);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_plfm, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_gid, tvb, offset, fl, ENC_BIG_ENDIAN);
proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_bid, tvb, offset, fl, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(srcport_tree, hf_gmhdr_srcport_pid, tvb, offset, fl, ENC_BIG_ENDIAN);
pid = ((tv & GMHDR_SRCPORT_PID_MASK) >> GMHDR_SRCPORT_PID_SHFT) - 24;
if (pid >= 1 && pid <= 4) {
proto_item_append_text(ti, " (g%d)", pid);
}
break;
}
case GMHDR_FTYPE_PKTSIZE:
if (fl != 2) {
expert_add_info_format(pinfo, gmhdr_tree, PI_MALFORMED, PI_ERROR, "Field length %u invalid", fl);
break;
}
proto_tree_add_item(gmhdr_tree, hf_gmhdr_pktsize, tvb, offset, fl, ENC_BIG_ENDIAN);
break;
case GMHDR_FTYPE_TIMESTAMP_LOCAL:
case GMHDR_FTYPE_TIMESTAMP_NTP:
case GMHDR_FTYPE_TIMESTAMP_GPS:
case GMHDR_FTYPE_TIMESTAMP_1588:
if (fl != 8) {
expert_add_info_format(pinfo, gmhdr_tree, PI_MALFORMED, PI_ERROR, "Field length %u invalid", fl);
break;
}
ti = proto_tree_add_item(gmhdr_tree, hf_gmhdr_timestamp, tvb, offset, fl, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
proto_item_append_text(ti, "; Source: %s", val_to_str(tl>>8, gmhdr_ftype_timestamp, "Unknown"));
break;
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
hf_gmhdr_len, hf_gmhdr_trailer, 0);
} else {
ethertype(encap_proto, tvb, offset, pinfo, tree, gmhdr_tree,
hf_gmhdr_etype, hf_gmhdr_trailer, 0);
}
}
static int
dissect_gmtrailer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *ti;
guint tvblen, length;
proto_tree *gmhdr_tree = NULL;
guint offset;
guint16 cksum, comp_cksum;
tvblen = tvb_length(tvb);
if (tvblen < 5)
return 0;
if (tvb_get_ntohs(tvb, tvblen-4) != ETHERTYPE_GIGAMON)
return 0;
length = tvb_get_guint8(tvb, tvblen-5);
if ((tvblen-5) != length)
return 0;
offset = tvblen - 5 - length;
cksum = tvb_get_ntohs(tvb, tvblen-2);
{
vec_t vec;
vec.len = length + 3;
vec.ptr = tvb_get_ptr(tvb, offset, vec.len);
comp_cksum = in_cksum(&vec, 1);
if (pntohs(&comp_cksum) != cksum) {
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
}
return tvblen;
}
void
proto_register_gmhdr(void)
{
static hf_register_info hf[] = {
{ &hf_gmhdr_srcport, {
"Src Port", "gmhdr.srcport", FT_UINT24, BASE_HEX,
NULL, 0, "Original Source Port", HFILL }},
{ &hf_gmhdr_srcport_plfm, {
"Platform Id", "gmhdr.srcport_plfm", FT_UINT24, BASE_DEC,
VALS(gmhdr_plfm_str), GMHDR_SRCPORT_PLFM_MASK, "Original Platform Id", HFILL }},
{ &hf_gmhdr_srcport_gid, {
"Group Id", "gmhdr.srcport_gid", FT_UINT24, BASE_DEC,
NULL, GMHDR_SRCPORT_GID_MASK, "Original Source Group Id", HFILL }},
{ &hf_gmhdr_srcport_bid, {
"Box Id", "gmhdr.srcport_bid", FT_UINT24, BASE_DEC,
NULL, GMHDR_SRCPORT_BID_MASK, "Original Source Box Id", HFILL }},
{ &hf_gmhdr_srcport_pid, {
"Port Id", "gmhdr.srcport_pid", FT_UINT24, BASE_DEC,
NULL, GMHDR_SRCPORT_PID_MASK, "Original Source Port Id", HFILL }},
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
{ &hf_gmhdr_trailer, {
"Trailer", "gmhdr.trailer", FT_BYTES, BASE_NONE,
NULL, 0x0, "GMHDR Trailer", HFILL }}
};
static gint *ett[] = {
&ett_gmhdr,
&ett_srcport
};
module_t *gmhdr_module;
proto_gmhdr = proto_register_protocol("Gigamon Header", "GMHDR", "gmhdr");
proto_register_field_array(proto_gmhdr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
gmhdr_module = prefs_register_protocol(proto_gmhdr, NULL);
prefs_register_bool_preference(gmhdr_module, "summary_in_tree",
"Show Gigamon header summary in protocol tree",
"Whether the Gigamon header summary line should be shown in the protocol tree",
&gmhdr_summary_in_tree);
}
void
proto_reg_handoff_gmhdr(void)
{
dissector_handle_t gmhdr_handle;
gmhdr_handle = create_dissector_handle(dissect_gmhdr, proto_gmhdr);
dissector_add_uint("ethertype", ETHERTYPE_GIGAMON, gmhdr_handle);
heur_dissector_add("eth.trailer", dissect_gmtrailer, proto_gmhdr);
}
