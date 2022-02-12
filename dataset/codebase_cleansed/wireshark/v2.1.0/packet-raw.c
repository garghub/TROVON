static gboolean
capture_raw(const guchar *pd, int offset _U_, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
if (BYTES_ARE_IN_FRAME(0,len,2) && pd[0] == 0xff && pd[1] == 0x03) {
return capture_ppp_hdlc(pd, 0, len, cpinfo, pseudo_header);
}
else if (BYTES_ARE_IN_FRAME(0,len,8) && pd[6] == 0xff && pd[7] == 0x03) {
return capture_ppp_hdlc(pd, 6, len, cpinfo, pseudo_header);
}
else if (BYTES_ARE_IN_FRAME(0,len,3) && pd[1] == 0xff && pd[2] == 0x03) {
return capture_ppp_hdlc(pd, 1, len, cpinfo, pseudo_header);
}
else if (BYTES_ARE_IN_FRAME(0,len,10) && memcmp(pd, zeroes, 10) == 0) {
return capture_ip(pd, 10, len, cpinfo, pseudo_header);
}
else {
if (BYTES_ARE_IN_FRAME(0,len,1)) {
switch (pd[0] & 0xF0) {
case 0x40:
return capture_ip(pd, 0, len, cpinfo, pseudo_header);
#if 0
case 0x60:
return capture_ipv6(pd, 0, len, cpinfo, pseudo_header);
#endif
}
}
}
return FALSE;
}
static int
dissect_raw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "N/A");
col_set_str(pinfo->cinfo, COL_INFO, "Raw packet data");
proto_tree_add_item(tree, proto_raw, tvb, 0, tvb_captured_length(tvb), ENC_NA);
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
call_data_dissector(tvb, pinfo, tree);
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_raw(void)
{
static gint *ett[] = {
&ett_raw,
};
proto_raw = proto_register_protocol("Raw packet data", "Raw", "raw");
proto_register_subtree_array(ett, array_length(ett));
raw_handle = register_dissector("raw_ip", dissect_raw, proto_raw);
}
void
proto_reg_handoff_raw(void)
{
ip_handle = find_dissector_add_dependency("ip", proto_raw);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_raw);
ppp_hdlc_handle = find_dissector_add_dependency("ppp_hdlc", proto_raw);
dissector_add_uint("wtap_encap", WTAP_ENCAP_RAW_IP, raw_handle);
register_capture_dissector("wtap_encap", WTAP_ENCAP_RAW_IP, capture_raw, proto_raw);
}
