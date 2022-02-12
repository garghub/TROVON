static int dissect_auto_rp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 ver_type, rp_count;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Auto-RP");
col_clear(pinfo->cinfo, COL_INFO);
ver_type = tvb_get_guint8(tvb, 0);
rp_count = tvb_get_guint8(tvb, 1);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (v%s) for %u RP%s",
val_to_str_const(lo_nibble(ver_type), auto_rp_type_vals, "Unknown"),
val_to_str_const(hi_nibble(ver_type), auto_rp_ver_vals, "Unknown"),
rp_count, plurality(rp_count, "", "s"));
if (tree) {
proto_item *ti;
proto_tree *auto_rp_tree, *ver_type_tree;
int i, offset;
guint16 holdtime;
offset = 0;
ti = proto_tree_add_item(tree, proto_auto_rp, tvb, offset, -1, ENC_NA);
auto_rp_tree = proto_item_add_subtree(ti, ett_auto_rp);
ver_type_tree = proto_tree_add_subtree_format(auto_rp_tree, tvb, offset, 1,
ett_auto_rp_ver_type, NULL, "Version: %s, Packet type: %s",
val_to_str_const(hi_nibble(ver_type), auto_rp_ver_vals, "Unknown"),
val_to_str_const(lo_nibble(ver_type), auto_rp_type_vals, "Unknown"));
proto_tree_add_uint(ver_type_tree, hf_auto_rp_version, tvb, offset, 1, ver_type);
proto_tree_add_uint(ver_type_tree, hf_auto_rp_type, tvb, offset, 1, ver_type);
offset++;
proto_tree_add_uint(auto_rp_tree, hf_auto_rp_count, tvb, offset, 1, rp_count);
offset++;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(auto_rp_tree, hf_auto_rp_holdtime, tvb, offset, 2, holdtime,
"%u second%s", holdtime, plurality(holdtime, "", "s"));
offset+=2;
proto_tree_add_item(auto_rp_tree, hf_auto_rp_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
for (i = 0; i < rp_count; i++)
offset = do_auto_rp_map(tvb, offset, auto_rp_tree);
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_auto_rp_trailing_junk, tvb, offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int do_auto_rp_map(tvbuff_t *tvb, int offset, proto_tree *auto_rp_tree)
{
proto_tree *map_tree;
guint8 group_count;
int i;
group_count = tvb_get_guint8(tvb, offset + 5);
map_tree = proto_tree_add_subtree_format(auto_rp_tree, tvb, offset, 6 + group_count * 6,
ett_auto_rp_map, NULL,
"RP %s: %u group%s", tvb_ip_to_str(tvb, offset),
group_count, plurality(group_count, "", "s"));
proto_tree_add_item(map_tree, hf_auto_rp_rp_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(map_tree, hf_auto_rp_pim_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_uint(map_tree, hf_auto_rp_group_num, tvb, offset, 1, group_count);
offset++;
for (i = 0; i < group_count; i++) {
proto_tree *grp_tree;
guint8 sign, mask_len;
sign = tvb_get_guint8(tvb, offset);
mask_len = tvb_get_guint8(tvb, offset + 1);
grp_tree = proto_tree_add_subtree_format(map_tree, tvb, offset, 6,
ett_auto_rp_group, NULL, "Group %s/%u (%s)",
tvb_ip_to_str(tvb, offset + 2), mask_len,
val_to_str_const(sign&AUTO_RP_SIGN_MASK, auto_rp_mask_sign_vals, ""));
proto_tree_add_uint(grp_tree, hf_auto_rp_prefix_sgn, tvb, offset, 1, sign);
offset++;
proto_tree_add_uint(grp_tree, hf_auto_rp_mask_len, tvb, offset, 1, mask_len);
offset++;
proto_tree_add_item(grp_tree, hf_auto_rp_group_prefix, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
void proto_register_auto_rp(void)
{
static hf_register_info hf[] = {
{ &hf_auto_rp_version,
{"Protocol version", "auto_rp.version",
FT_UINT8, BASE_DEC, VALS(auto_rp_ver_vals), AUTO_RP_VERSION_MASK,
"Auto-RP protocol version", HFILL }},
{ &hf_auto_rp_type,
{"Packet type", "auto_rp.type",
FT_UINT8, BASE_DEC, VALS(auto_rp_type_vals), AUTO_RP_TYPE_MASK,
"Auto-RP packet type", HFILL }},
{ &hf_auto_rp_count,
{"RP count", "auto_rp.rp_count",
FT_UINT8, BASE_DEC, NULL, 0,
"The number of RP addresses contained in this message", HFILL }},
{ &hf_auto_rp_group_num,
{"Number of groups this RP maps to", "auto_rp.group_num",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_auto_rp_holdtime,
{"Holdtime", "auto_rp.holdtime",
FT_UINT16, BASE_DEC, NULL, 0,
"The amount of time in seconds this announcement is valid", HFILL }},
{ &hf_auto_rp_pim_ver,
{"Version", "auto_rp.pim_ver",
FT_UINT8, BASE_DEC, VALS(auto_rp_pim_ver_vals), AUTO_RP_PIM_VER_MASK,
"RP's highest PIM version", HFILL }},
{ &hf_auto_rp_rp_addr,
{"RP address", "auto_rp.rp_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"The unicast IP address of the RP", HFILL }},
{ &hf_auto_rp_prefix_sgn,
{"Sign", "auto_rp.prefix_sign",
FT_UINT8, BASE_DEC, VALS(auto_rp_mask_sign_vals), AUTO_RP_SIGN_MASK,
"Group prefix sign", HFILL }},
{ &hf_auto_rp_mask_len,
{"Mask length", "auto_rp.mask_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of group prefix", HFILL }},
{ &hf_auto_rp_group_prefix,
{"Prefix", "auto_rp.group_prefix",
FT_IPv4, BASE_NONE, NULL, 0,
"Group prefix", HFILL }},
{ &hf_auto_rp_reserved,
{"Reserved", "auto_rp.reserved",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_auto_rp_trailing_junk,
{"Trailing junk", "auto_rp.trailing_junk",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_auto_rp,
&ett_auto_rp_ver_type,
&ett_auto_rp_map,
&ett_auto_rp_group
};
proto_auto_rp = proto_register_protocol("Cisco Auto-RP", "Auto-RP", "auto_rp");
proto_register_field_array(proto_auto_rp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_auto_rp(void)
{
dissector_handle_t auto_rp_handle;
auto_rp_handle = create_dissector_handle(dissect_auto_rp, proto_auto_rp);
dissector_add_uint_with_preference("udp.port", UDP_PORT_PIM_RP_DISC, auto_rp_handle);
}
