void
capture_raw(const guchar *pd, int len, packet_counts *ld)
{
if (BYTES_ARE_IN_FRAME(0,len,2) && pd[0] == 0xff && pd[1] == 0x03) {
capture_ppp_hdlc(pd, 0, len, ld);
}
else if (BYTES_ARE_IN_FRAME(0,len,8) && pd[6] == 0xff && pd[7] == 0x03) {
capture_ppp_hdlc(pd, 6, len, ld);
}
else if (BYTES_ARE_IN_FRAME(0,len,3) && pd[1] == 0xff && pd[2] == 0x03) {
capture_ppp_hdlc(pd, 1, len, ld);
}
else if (BYTES_ARE_IN_FRAME(0,len,10) && memcmp(pd, zeroes, 10) == 0) {
capture_ip(pd, 10, len, ld);
}
else {
if (BYTES_ARE_IN_FRAME(0,len,1)) {
switch (pd[0] & 0xF0) {
case 0x40:
capture_ip(pd, 0, len, ld);
break;
#if 0
case 0x60:
capture_ipv6(pd, 0, len, ld);
break;
#endif
}
}
}
}
static void
dissect_raw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree;
proto_item *ti;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "N/A");
col_set_str(pinfo->cinfo, COL_INFO, "Raw packet data");
if (tree) {
ti = proto_tree_add_item(tree, proto_raw, tvb, 0, 0, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_raw);
proto_tree_add_text(fh_tree, tvb, 0, 0, "No link information available");
}
if (pinfo->fd->lnk_t == WTAP_ENCAP_RAW_IP4) {
call_dissector(ip_handle, tvb, pinfo, tree);
}
else if (pinfo->fd->lnk_t == WTAP_ENCAP_RAW_IP6) {
call_dissector(ipv6_handle, tvb, pinfo, tree);
}
else
if (tvb_get_ntohs(tvb, 0) == 0xff03) {
call_dissector(ppp_hdlc_handle, tvb, pinfo, tree);
}
else if (tvb_get_ntohs(tvb, 6) == 0xff03) {
next_tvb = tvb_new_subset_remaining(tvb, 6);
call_dissector(ppp_hdlc_handle, next_tvb, pinfo, tree);
}
else if (tvb_get_ntohs(tvb, 1) == 0xff03) {
next_tvb = tvb_new_subset_remaining(tvb, 1);
call_dissector(ppp_hdlc_handle, next_tvb, pinfo, tree);
}
else if (tvb_memeql(tvb, 0, zeroes,10) == 0) {
next_tvb = tvb_new_subset_remaining(tvb, 10);
call_dissector(ip_handle, next_tvb, pinfo, tree);
}
else {
switch (tvb_get_guint8(tvb, 0) & 0xF0) {
case 0x40:
call_dissector(ip_handle, tvb, pinfo, tree);
break;
case 0x60:
call_dissector(ipv6_handle, tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, tvb, pinfo, tree);
break;
}
}
}
void
proto_register_raw(void)
{
static gint *ett[] = {
&ett_raw,
};
proto_raw = proto_register_protocol("Raw packet data", "Raw", "raw");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_raw(void)
{
dissector_handle_t raw_handle;
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
data_handle = find_dissector("data");
ppp_hdlc_handle = find_dissector("ppp_hdlc");
raw_handle = create_dissector_handle(dissect_raw, proto_raw);
dissector_add_uint("wtap_encap", WTAP_ENCAP_RAW_IP, raw_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_RAW_IP4, raw_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_RAW_IP6, raw_handle);
}
