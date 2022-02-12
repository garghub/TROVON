static int
dissect_vrrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
gint vrrp_len;
guint8 ver_type;
vec_t cksum_vec[4];
guint32 phdr[2];
gboolean is_ipv6;
proto_item *ti, *tv, *hidden_item, *checksum_item;
proto_tree *vrrp_tree, *ver_type_tree;
guint8 priority, addr_count = 0, auth_type = VRRP_AUTH_TYPE_NONE;
guint16 cksum, computed_cksum;
is_ipv6 = (pinfo->src.type == AT_IPv6);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VRRP");
col_clear(pinfo->cinfo, COL_INFO);
ver_type = tvb_get_guint8(tvb, 0);
col_add_fstr(pinfo->cinfo, COL_INFO, "Announcement (v%u)",
hi_nibble(ver_type));
ti = proto_tree_add_item(tree, proto_vrrp, tvb, 0, -1, ENC_NA);
vrrp_tree = proto_item_add_subtree(ti, ett_vrrp);
priority = tvb_get_guint8(tvb, 2);
addr_count = tvb_get_guint8(tvb, 3);
tv = proto_tree_add_uint_format(vrrp_tree, hf_vrrp_ver_type,
tvb, offset, 1, ver_type,
"Version %u, Packet type %u (%s)",
hi_nibble(ver_type), lo_nibble(ver_type),
val_to_str_const(lo_nibble(ver_type), vrrp_type_vals, "Unknown"));
ver_type_tree = proto_item_add_subtree(tv, ett_vrrp_ver_type);
if(ver_type_tree){
proto_tree_add_uint(ver_type_tree, hf_vrrp_version, tvb,
offset, 1, ver_type);
proto_tree_add_uint(ver_type_tree, hf_vrrp_type, tvb, offset, 1, ver_type);
offset += 1;
proto_tree_add_item(vrrp_tree, hf_vrrp_virt_rtr_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint_format(vrrp_tree, hf_vrrp_prio, tvb, offset, 1, priority, "Priority: %u (%s)",
priority,
val_to_str_const(priority, vrrp_prio_vals, "Non-default backup priority"));
offset += 1;
proto_tree_add_uint(vrrp_tree, hf_vrrp_addr_count, tvb,
offset, 1, addr_count);
offset += 1;
switch(hi_nibble(ver_type)) {
case 3:
proto_tree_add_item(vrrp_tree, hf_vrrp_reserved_mbz, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vrrp_tree, hf_vrrp_short_adver_int, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 2:
default:
auth_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(vrrp_tree, hf_vrrp_auth_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(vrrp_tree, hf_vrrp_adver_int, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
}else{
offset += 6;
}
checksum_item = proto_tree_add_item(vrrp_tree, hf_vrrp_checksum, tvb, offset, 2, ENC_BIG_ENDIAN);
cksum = tvb_get_ntohs(tvb, offset);
vrrp_len = (gint)tvb_reported_length(tvb);
if (!pinfo->fragmented && (gint)tvb_captured_length(tvb) >= vrrp_len) {
switch(hi_nibble(ver_type)) {
case 3:
if((g_vrrp_v3_checksum_as_in_v2 == FALSE)||(pinfo->src.type == AT_IPv6)){
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)pinfo->src.data, pinfo->src.len);
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)pinfo->dst.data, pinfo->dst.len);
phdr[0] = g_htonl(vrrp_len);
phdr[1] = g_htonl(IP_PROTO_VRRP);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *)&phdr, 8);
SET_CKSUM_VEC_TVB(cksum_vec[3], tvb, 0, vrrp_len);
computed_cksum = in_cksum(cksum_vec, 4);
break;
}
case 2:
default:
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, vrrp_len);
computed_cksum = in_cksum(&cksum_vec[0], 1);
break;
}
if (computed_cksum == 0) {
hidden_item = proto_tree_add_boolean(vrrp_tree, hf_vrrp_checksum_bad, tvb, offset, 2, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_item_append_text(checksum_item, " [correct]");
} else {
hidden_item = proto_tree_add_boolean(vrrp_tree, hf_vrrp_checksum_bad, tvb, offset, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if(hi_nibble(ver_type)==3){
proto_item_append_text(checksum_item, " [incorrect, should be 0x%04x(check preferences)]", in_cksum_shouldbe(cksum, computed_cksum));
} else {
proto_item_append_text(checksum_item, " [incorrect, should be 0x%04x]", in_cksum_shouldbe(cksum, computed_cksum));
}
expert_add_info_format(pinfo, checksum_item, &ei_vrrp_checksum,
"VRRP Checksum Incorrect, should be 0x%04x", in_cksum_shouldbe(cksum, computed_cksum));
}
}
offset += 2;
while (addr_count > 0) {
if (is_ipv6) {
proto_tree_add_item(vrrp_tree, hf_vrrp_ip6, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
proto_tree_add_item(vrrp_tree, hf_vrrp_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
addr_count--;
}
if (auth_type == VRRP_AUTH_TYPE_SIMPLE_TEXT) {
proto_tree_add_item(vrrp_tree, hf_vrrp_auth_string, tvb, offset, VRRP_AUTH_DATA_LEN, ENC_ASCII|ENC_NA);
offset += VRRP_AUTH_DATA_LEN;
}
return offset;
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
{ &hf_vrrp_checksum,
{ "Checksum", "vrrp.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Used to detect data corruption in the VRRP message", HFILL }},
{ &hf_vrrp_checksum_bad,
{ "Bad Checksum", "vrrp.checksum_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
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
{ &hf_vrrp_auth_string,
{"Authentification String", "vrrp.auth_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_vrrp,
&ett_vrrp_ver_type
};
static ei_register_info ei[] = {
{ &ei_vrrp_checksum, { "vrrp.checksum_bad.expert", PI_CHECKSUM, PI_WARN, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_vrrp;
module_t *vrrp_module;
proto_vrrp = proto_register_protocol("Virtual Router Redundancy Protocol",
"VRRP", "vrrp");
proto_register_field_array(proto_vrrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_vrrp = expert_register_protocol(proto_vrrp);
expert_register_field_array(expert_vrrp, ei, array_length(ei));
vrrp_module = prefs_register_protocol(proto_vrrp, NULL);
prefs_register_bool_preference(vrrp_module, "v3_checksum_as_in_v2",
"Calculate V3 checksum as in V2 for IPv4 packets",
"There is some ambigiousy on how to calculate V3 checksums"
"As in V3 will use a pseudo header(which may only be implemented for IPv6 by some manufacturers)",
&g_vrrp_v3_checksum_as_in_v2);
}
void
proto_reg_handoff_vrrp(void)
{
dissector_handle_t vrrp_handle;
vrrp_handle = new_create_dissector_handle(dissect_vrrp, proto_vrrp);
dissector_add_uint("ip.proto", IP_PROTO_VRRP, vrrp_handle);
}
