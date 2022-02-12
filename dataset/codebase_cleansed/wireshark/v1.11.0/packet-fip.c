static void
fip_desc_type_len(proto_tree *tree, tvbuff_t *tvb)
{
proto_tree_add_item(tree, hf_fip_desc_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fip_desc_len, tvb, 1, 1, ENC_BIG_ENDIAN);
}
static void
fip_desc_fc4f(tvbuff_t *tvb, proto_tree *tree, proto_item *item)
{
guint mask;
guint offset;
static const int *types_word0[] = {
&hf_fip_type_ip,
&hf_fip_type_fcp,
NULL
};
static const int *types_word1[] = {
&hf_fip_type_gs3,
NULL
};
static const int *fcp_feat[] = {
&hf_fip_fcp_feat_t,
&hf_fip_fcp_feat_i,
NULL
};
offset = 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_fip_desc_fc4f_types,
ett_fip_dt_fc4f_types, types_word0, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_fip_desc_fc4f_types,
ett_fip_dt_fc4f_types, types_word1, ENC_BIG_ENDIAN);
offset += 256 / 8 - 4;
offset += 8 / 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_fip_desc_fcp_feat,
ett_fip_dt_fcp_feat, fcp_feat, ENC_BIG_ENDIAN);
mask = tvb_get_ntohl(tvb, offset);
if (mask & 1) {
proto_item_append_text(item, "FCP Target ");
}
if (mask & 2) {
proto_item_append_text(item, "FCP Initiator ");
}
}
static void
dissect_fip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint op;
guint sub;
guint rlen;
proto_item *ti;
proto_item *item;
proto_tree *fip_tree;
proto_tree *subtree;
guint dtype;
guint dlen;
guint desc_offset;
guint val;
tvbuff_t *desc_tvb;
const char *info;
const char *text;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FIP");
col_clear(pinfo->cinfo, COL_INFO);
if (!tvb_bytes_exist(tvb, 0, FIP_HEADER_LEN)) {
col_set_str(pinfo->cinfo, COL_INFO, "[packet too short]");
if (tree)
proto_tree_add_protocol_format(tree, proto_fip, tvb, 0,
-1, "FIP [packet too short]");
return;
}
op = tvb_get_ntohs(tvb, 2);
sub = tvb_get_guint8(tvb, 5);
switch (op) {
case FIP_OP_DISC:
info = val_to_str(sub, fip_disc_subcodes, "Discovery 0x%x");
break;
case FIP_OP_LS:
info = val_to_str(sub, fip_ls_subcodes, "Link Service 0x%x");
break;
case FIP_OP_CTRL:
info = val_to_str(sub, fip_ctrl_subcodes, "Control 0x%x");
break;
case FIP_OP_VLAN:
info = val_to_str(sub, fip_vlan_subcodes, "VLAN 0x%x");
break;
case FIP_OP_VN2VN:
info = val_to_str(sub, fip_vn2vn_subcodes, "VN2VN 0x%x");
break;
default:
info = val_to_str(op, fip_opcodes, "Unknown op 0x%x");
break;
}
col_add_str(pinfo->cinfo, COL_INFO, info);
rlen = tvb_get_ntohs(tvb, 6);
ti = proto_tree_add_protocol_format(tree, proto_fip, tvb, 0,
FIP_HEADER_LEN + rlen * FIP_BPW,
"FIP %s", info);
fip_tree = proto_item_add_subtree(ti, ett_fip);
proto_tree_add_item(fip_tree, hf_fip_ver, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fip_tree, hf_fip_op, tvb, 2, 2, ENC_BIG_ENDIAN);
switch (op) {
case FIP_OP_DISC:
proto_tree_add_item(fip_tree, hf_fip_disc_subcode, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
case FIP_OP_LS:
proto_tree_add_item(fip_tree, hf_fip_ls_subcode, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
case FIP_OP_CTRL:
proto_tree_add_item(fip_tree, hf_fip_ctrl_subcode, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
case FIP_OP_VLAN:
proto_tree_add_item(fip_tree, hf_fip_vlan_subcode, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
case FIP_OP_VN2VN:
proto_tree_add_item(fip_tree, hf_fip_vn2vn_subcode, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(fip_tree, hf_fip_hex_subcode, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(fip_tree, hf_fip_dlen, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(fip_tree, tvb, 8, hf_fip_flags,
ett_fip_flags, hf_fip_flags_fields, ENC_BIG_ENDIAN);
desc_offset = FIP_HEADER_LEN;
rlen *= FIP_BPW;
proto_tree_add_text(fip_tree, tvb, desc_offset, rlen, "Descriptors:");
while ((rlen > 0) && tvb_bytes_exist(tvb, desc_offset, 2)) {
dlen = tvb_get_guint8(tvb, desc_offset + 1) * FIP_BPW;
if (!dlen) {
proto_tree_add_text(fip_tree, tvb, desc_offset, -1,
"Descriptor [length error]");
break;
}
if (!tvb_bytes_exist(tvb, desc_offset, dlen) || dlen > rlen) {
break;
}
desc_tvb = tvb_new_subset(tvb, desc_offset, dlen, -1);
dtype = tvb_get_guint8(desc_tvb, 0);
desc_offset += dlen;
rlen -= dlen;
item = proto_tree_add_text(fip_tree, desc_tvb, 0, -1, "Descriptor: %s ",
val_to_str(dtype, fip_desc_types, "Unknown 0x%x"));
switch (dtype) {
case FIP_DT_PRI:
subtree = proto_item_add_subtree(item, ett_fip_dt_pri);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_pri, desc_tvb,
3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%u", tvb_get_guint8(desc_tvb, 3));
break;
case FIP_DT_MAC:
subtree = proto_item_add_subtree(item, ett_fip_dt_mac);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_mac, desc_tvb,
2, 6, ENC_NA);
proto_item_append_text(item, "%s",
tvb_bytes_to_str_punct(desc_tvb, 2, 6, ':'));
break;
case FIP_DT_MAP_OUI:
subtree = proto_item_add_subtree(item, ett_fip_dt_map);
fip_desc_type_len(subtree, desc_tvb);
text = tvb_fc_to_str(desc_tvb, 5);
proto_tree_add_string(subtree, hf_fip_desc_map, desc_tvb,
5, 3, text);
proto_item_append_text(item, "%s", text);
break;
case FIP_DT_NAME:
subtree = proto_item_add_subtree(item, ett_fip_dt_name);
fip_desc_type_len(subtree, desc_tvb);
text = tvb_fcwwn_to_str(desc_tvb, 4);
proto_tree_add_string(subtree, hf_fip_desc_name,
desc_tvb, 4, 8, text);
proto_item_append_text(item, "%s", text);
break;
case FIP_DT_FAB:
subtree = proto_item_add_subtree(item, ett_fip_dt_fab);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_fab_vfid, desc_tvb,
2, 2, ENC_BIG_ENDIAN);
text = tvb_fc_to_str(desc_tvb, 5);
proto_tree_add_string(subtree, hf_fip_desc_fab_map, desc_tvb,
5, 3, text);
text = tvb_fcwwn_to_str(desc_tvb, 8);
proto_tree_add_string(subtree, hf_fip_desc_fab_name,
desc_tvb, 8, 8, text);
proto_item_append_text(item, "%s", text);
break;
case FIP_DT_FCOE_SIZE:
subtree = proto_item_add_subtree(item, ett_fip_dt_mdl);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_fcoe_size, desc_tvb,
2, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%u", tvb_get_ntohs(desc_tvb, 2));
break;
case FIP_DT_FLOGI:
case FIP_DT_FDISC:
case FIP_DT_LOGO:
case FIP_DT_ELP: {
tvbuff_t *ls_tvb;
subtree = proto_item_add_subtree(item, ett_fip_dt_caps);
fip_desc_type_len(subtree, desc_tvb);
ls_tvb = tvb_new_subset(desc_tvb, 4, dlen - 4, -1);
call_dissector(fc_handle, ls_tvb, pinfo, subtree);
proto_item_append_text(item, "%u bytes", dlen - 4);
}
break;
case FIP_DT_VN:
subtree = proto_item_add_subtree(item, ett_fip_dt_vn);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_vn_mac, desc_tvb,
2, 6, ENC_NA);
proto_tree_add_item(subtree, hf_fip_desc_vn_fid, desc_tvb,
9, 3, ENC_BIG_ENDIAN);
text = tvb_fcwwn_to_str(desc_tvb, 12);
proto_tree_add_string(subtree, hf_fip_desc_vn_wwpn,
desc_tvb, 12, 8, text);
proto_item_append_text(item, "MAC %s FC_ID %6.6x",
tvb_bytes_to_str_punct(desc_tvb, 2, 6, ':'),
tvb_get_ntoh24(desc_tvb, 9));
break;
case FIP_DT_FKA:
subtree = proto_item_add_subtree(item, ett_fip_dt_fka);
fip_desc_type_len(subtree, desc_tvb);
val = tvb_get_ntohl(desc_tvb, 4);
proto_tree_add_uint_format_value(subtree, hf_fip_desc_fka,
desc_tvb, 4, 4, val, "%u ms", val);
proto_item_append_text(item, "%u ms", val);
break;
case FIP_DT_VEND:
subtree = proto_item_add_subtree(item, ett_fip_dt_vend);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_vend, desc_tvb,
4, 8, ENC_NA);
if (tvb_bytes_exist(desc_tvb, 9, -1)) {
proto_tree_add_item(subtree, hf_fip_desc_vend_data,
desc_tvb, 9, -1, ENC_NA);
}
break;
case FIP_DT_VLAN:
subtree = proto_item_add_subtree(item, ett_fip_dt_vlan);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_vlan, desc_tvb,
2, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%u", tvb_get_ntohs(desc_tvb, 2));
break;
case FIP_DT_FC4F:
subtree = proto_item_add_subtree(item, ett_fip_dt_fc4f);
fip_desc_type_len(subtree, desc_tvb);
fip_desc_fc4f(desc_tvb, subtree, item);
break;
default:
subtree = proto_item_add_subtree(item, ett_fip_dt_unk);
fip_desc_type_len(subtree, desc_tvb);
proto_tree_add_item(subtree, hf_fip_desc_unk, desc_tvb,
2, -1, ENC_NA);
break;
}
}
}
void
proto_register_fip(void)
{
static hf_register_info hf[] = {
{ &hf_fip_ver,
{ "Version", "fip.ver",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}},
{ &hf_fip_op,
{ "Opcode", "fip.opcode",
FT_UINT16, BASE_HEX, VALS(fip_opcodes), 0,
NULL, HFILL}},
{ &hf_fip_disc_subcode,
{ "Discovery Subcode", "fip.disc_subcode",
FT_UINT8, BASE_HEX, VALS(fip_disc_subcodes), 0,
NULL, HFILL}},
{ &hf_fip_ls_subcode,
{ "Link Service Subcode", "fip.ls.subcode",
FT_UINT8, BASE_HEX, VALS(fip_ls_subcodes), 0,
NULL, HFILL}},
{ &hf_fip_ctrl_subcode,
{ "Control Subcode", "fip.ctrl_subcode",
FT_UINT8, BASE_HEX, VALS(fip_ctrl_subcodes), 0,
NULL, HFILL}},
{ &hf_fip_vlan_subcode,
{ "VLAN Subcode", "fip.vlan_subcode",
FT_UINT8, BASE_HEX, VALS(fip_vlan_subcodes), 0,
NULL, HFILL}},
{ &hf_fip_vn2vn_subcode,
{ "VN2VN Subcode", "fip.vn2vn_subcode",
FT_UINT8, BASE_HEX, VALS(fip_vn2vn_subcodes), 0,
NULL, HFILL}},
{ &hf_fip_hex_subcode,
{ "Unknown Subcode", "fip.subcode",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_fip_dlen,
{ "Length of Descriptors (words)", "fip.dl_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_flags,
{ "Flags", "fip.flags",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_fip_flag_fpma,
{ "Fabric Provided MAC addr", "fip.flags.fpma",
FT_BOOLEAN, 16, NULL, FIP_FL_FPMA,
NULL, HFILL}},
{ &hf_fip_flag_spma,
{ "Server Provided MAC addr", "fip.flags.spma",
FT_BOOLEAN, 16, NULL, FIP_FL_SPMA,
NULL, HFILL}},
{ &hf_fip_flag_rec_p2p,
{ "REC/P2P", "fip.flags.rec_p2p",
FT_BOOLEAN, 16, NULL, FIP_FL_REC_P2P,
NULL, HFILL}},
{ &hf_fip_flag_avail,
{ "Available", "fip.flags.available",
FT_BOOLEAN, 16, NULL, FIP_FL_AVAIL,
NULL, HFILL}},
{ &hf_fip_flag_sol,
{ "Solicited", "fip.flags.sol",
FT_BOOLEAN, 16, NULL, FIP_FL_SOL,
NULL, HFILL}},
{ &hf_fip_flag_fport,
{ "F_Port", "fip.flags.fport",
FT_BOOLEAN, 16, NULL, FIP_FL_FPORT,
NULL, HFILL}},
{ &hf_fip_desc_type,
{ "Descriptor Type", "fip.desc_type",
FT_UINT8, BASE_HEX, VALS(fip_desc_types), 0,
NULL, HFILL}},
{ &hf_fip_desc_len,
{ "Descriptor Length (words)", "fip.desc_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_pri,
{ "Priority", "fip.pri",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_mac,
{ "MAC Address", "fip.mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_map,
{ "FC-MAP-OUI", "fip.map",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_name,
{ "Switch or Node Name", "fip.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fab_vfid,
{ "VFID", "fip.fab.vfid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fab_map,
{ "FC-MAP", "fip.fab.map",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fab_name,
{ "Fabric Name", "fip.fab.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fcoe_size,
{ "Max FCoE frame size", "fip.fcoe_size",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_vn_mac,
{ "VN_Port MAC Address", "fip.vn.mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_vn_fid,
{ "VN_Port FC_ID", "fip.vn.fc_id",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_vn_wwpn,
{ "Port Name", "fip.vn.pwwn",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fka,
{ "FKA_ADV_Period", "fip.fka",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_vend,
{ "Vendor-ID", "fip.vendor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_vend_data,
{ "Vendor-specific data", "fip.vendor.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_vlan,
{ "VLAN", "fip.vlan",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fc4f_types,
{ "FC4 Types", "fip.fc4f.types",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_fip_desc_fcp_feat,
{ "FCP Features", "fip.fc4f.feat.fcp",
FT_UINT32, BASE_HEX, NULL, 0xf,
NULL, HFILL}},
{ &hf_fip_type_ip,
{ "IP", "fip.fc4f.ip",
FT_BOOLEAN, 32, NULL, 1 << 5,
NULL, HFILL}},
{ &hf_fip_type_fcp,
{ "FCP", "fip.fc4f.fcp",
FT_BOOLEAN, 32, NULL, 1 << 8,
NULL, HFILL}},
{ &hf_fip_type_gs3,
{ "GS3", "fip.fc4f.gs3",
FT_BOOLEAN, 32, NULL, 1 << 0,
NULL, HFILL}},
{ &hf_fip_fcp_feat_t,
{ "FCP Target", "fip.fc4f.feat.fcp.target",
FT_BOOLEAN, 32, NULL, 1,
NULL, HFILL}},
{ &hf_fip_fcp_feat_i,
{ "FCP Initiator", "fip.fc4f.feat.fcp.initiator",
FT_BOOLEAN, 32, NULL, 2,
NULL, HFILL}},
{ &hf_fip_desc_unk,
{ "Unknown Descriptor", "fip.desc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}}
};
static gint *ett[] = {
&ett_fip,
&ett_fip_flags,
&ett_fip_dt_pri,
&ett_fip_dt_mac,
&ett_fip_dt_map,
&ett_fip_dt_name,
&ett_fip_dt_fab,
&ett_fip_dt_mdl,
&ett_fip_dt_caps,
&ett_fip_dt_vn,
&ett_fip_dt_fka,
&ett_fip_dt_vend,
&ett_fip_dt_vlan,
&ett_fip_dt_fc4f,
&ett_fip_dt_fc4f_types,
&ett_fip_dt_fcp_feat,
&ett_fip_dt_unk
};
proto_fip = proto_register_protocol("FCoE Initialization Protocol",
"FIP", "fip");
proto_register_field_array(proto_fip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_fip(void)
{
dissector_handle_t fip_handle;
fip_handle = create_dissector_handle(dissect_fip, proto_fip);
dissector_add_uint("ethertype", ETHERTYPE_FIP, fip_handle);
fc_handle = find_dissector("fc");
}
