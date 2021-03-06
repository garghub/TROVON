static void
dissect_vrrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
gint vrrp_len;
guint8 ver_type;
vec_t cksum_vec[4];
guint32 phdr[2];
gboolean is_ipv6;
is_ipv6 = (pinfo->src.type == AT_IPv6);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VRRP");
col_clear(pinfo->cinfo, COL_INFO);
ver_type = tvb_get_guint8(tvb, 0);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (v%u)",
"Announcement", hi_nibble(ver_type));
}
if (tree) {
proto_item *ti, *tv;
proto_tree *vrrp_tree, *ver_type_tree;
guint8 priority, addr_count = 0, auth_type = VRRP_AUTH_TYPE_NONE;
guint16 cksum, computed_cksum;
guint8 auth_buf[VRRP_AUTH_DATA_LEN + 1];
ti = proto_tree_add_item(tree, proto_vrrp, tvb, 0, -1, ENC_NA);
vrrp_tree = proto_item_add_subtree(ti, ett_vrrp);
tv = proto_tree_add_uint_format(vrrp_tree, hf_vrrp_ver_type,
tvb, offset, 1, ver_type,
"Version %u, Packet type %u (%s)",
hi_nibble(ver_type), lo_nibble(ver_type),
val_to_str(lo_nibble(ver_type), vrrp_type_vals, "Unknown"));
ver_type_tree = proto_item_add_subtree(tv, ett_vrrp_ver_type);
proto_tree_add_uint(ver_type_tree, hf_vrrp_version, tvb,
offset, 1, ver_type);
proto_tree_add_uint(ver_type_tree, hf_vrrp_type, tvb, offset, 1,
ver_type);
offset++;
proto_tree_add_item(vrrp_tree, hf_vrrp_virt_rtr_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
priority = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(vrrp_tree, hf_vrrp_prio, tvb, offset, 1, priority, "Priority: %u (%s)",
priority,
val_to_str(priority, vrrp_prio_vals, "Non-default backup priority"));
offset++;
addr_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vrrp_tree, hf_vrrp_addr_count, tvb,
offset, 1, addr_count);
offset++;
switch(hi_nibble(ver_type)) {
case 3:
proto_tree_add_item(vrrp_tree, hf_vrrp_reserved_mbz, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vrrp_tree, hf_vrrp_short_adver_int, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case 2:
default:
auth_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(vrrp_tree, hf_vrrp_auth_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(vrrp_tree, hf_vrrp_adver_int, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
cksum = tvb_get_ntohs(tvb, offset);
vrrp_len = (gint)tvb_reported_length(tvb);
if (!pinfo->fragmented && (gint)tvb_length(tvb) >= vrrp_len) {
switch(hi_nibble(ver_type)) {
case 3:
cksum_vec[0].ptr = pinfo->src.data;
cksum_vec[0].len = pinfo->src.len;
cksum_vec[1].ptr = pinfo->dst.data;
cksum_vec[1].len = pinfo->dst.len;
cksum_vec[2].ptr = (const guint8 *)&phdr;
phdr[0] = g_htonl(vrrp_len);
phdr[1] = g_htonl(IP_PROTO_VRRP);
cksum_vec[2].len = 8;
cksum_vec[3].ptr = tvb_get_ptr(tvb, 0, vrrp_len);
cksum_vec[3].len = vrrp_len;
computed_cksum = in_cksum(cksum_vec, 4);
break;
case 2:
default:
cksum_vec[0].ptr = tvb_get_ptr(tvb, 0, vrrp_len);
cksum_vec[0].len = vrrp_len;
computed_cksum = in_cksum(&cksum_vec[0], 1);
break;
}
if (computed_cksum == 0) {
proto_tree_add_text(vrrp_tree, tvb, offset, 2,
"Checksum: 0x%04x [correct]",
cksum);
} else {
proto_tree_add_text(vrrp_tree, tvb, offset, 2,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
cksum,
in_cksum_shouldbe(cksum, computed_cksum));
}
} else {
proto_tree_add_text(vrrp_tree, tvb, offset, 2,
"Checksum: 0x%04x", cksum);
}
offset+=2;
while (addr_count > 0) {
if (is_ipv6) {
proto_tree_add_item(vrrp_tree, hf_vrrp_ip6, tvb, offset, 16, ENC_NA);
offset+=16;
} else {
proto_tree_add_item(vrrp_tree, hf_vrrp_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
addr_count--;
}
if (auth_type != VRRP_AUTH_TYPE_SIMPLE_TEXT)
return;
tvb_get_nstringz0(tvb, offset, sizeof auth_buf, auth_buf);
if (auth_buf[0] != '\0')
proto_tree_add_text(vrrp_tree, tvb, offset,
VRRP_AUTH_DATA_LEN,
"Authentication string: `%s'",
auth_buf);
offset+=8;
}
}
void proto_register_vrrp(void)
{
static hf_register_info hf[] = {
{ &hf_vrrp_ver_type,
{"VRRP message version and type", "vrrp.typever",
FT_UINT8, BASE_DEC, NULL, 0x0,
"VRRP version and type", HFILL }},
{ &hf_vrrp_version,
{"VRRP protocol version", "vrrp.version",
FT_UINT8, BASE_DEC, NULL, VRRP_VERSION_MASK,
"VRRP version", HFILL }},
{ &hf_vrrp_type,
{"VRRP packet type", "vrrp.type",
FT_UINT8, BASE_DEC, VALS(vrrp_type_vals), VRRP_TYPE_MASK,
"VRRP type", HFILL }},
{ &hf_vrrp_virt_rtr_id,
{"Virtual Rtr ID", "vrrp.virt_rtr_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Virtual router this packet is reporting status for", HFILL }},
{ &hf_vrrp_prio,
{"Priority", "vrrp.prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Sending VRRP router's priority for the virtual router", HFILL }},
{ &hf_vrrp_addr_count,
{"Addr Count", "vrrp.addr_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of addresses contained in this VRRP advertisement", HFILL }},
{ &hf_vrrp_auth_type,
{"Auth Type", "vrrp.auth_type",
FT_UINT8, BASE_DEC, VALS(vrrp_auth_vals), 0x0,
"The authentication method being utilized", HFILL }},
{ &hf_vrrp_adver_int,
{"Adver Int", "vrrp.adver_int",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Time interval (in seconds) between ADVERTISEMENTS", HFILL }},
{ &hf_vrrp_reserved_mbz,
{"Reserved", "vrrp.reserved_mbz",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Must be zero", HFILL }},
{ &hf_vrrp_short_adver_int,
{"Adver Int", "vrrp.short_adver_int",
FT_UINT16, BASE_DEC, NULL, 0x0FFF,
"Time interval (in centiseconds) between ADVERTISEMENTS", HFILL }},
{ &hf_vrrp_ip,
{"IP Address", "vrrp.ip_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IP address associated with the virtual router", HFILL }},
{ &hf_vrrp_ip6,
{"IPv6 Address", "vrrp.ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address associated with the virtual router", HFILL }},
};
static gint *ett[] = {
&ett_vrrp,
&ett_vrrp_ver_type
};
proto_vrrp = proto_register_protocol("Virtual Router Redundancy Protocol",
"VRRP", "vrrp");
proto_register_field_array(proto_vrrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
return;
}
void
proto_reg_handoff_vrrp(void)
{
dissector_handle_t vrrp_handle;
vrrp_handle = create_dissector_handle(dissect_vrrp, proto_vrrp);
dissector_add_uint("ip.proto", IP_PROTO_VRRP, vrrp_handle);
}
