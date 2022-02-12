static int dissect_aim_sst_buddy_down_req (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = dissect_aim_buddyname(tvb, pinfo, 0, tree);
guint8 md5_size;
proto_tree_add_item(tree, hf_aim_sst_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_aim_sst_md5_hash_size, tvb, offset, 1, ENC_BIG_ENDIAN);
md5_size = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_aim_sst_md5_hash, tvb, offset, md5_size, ENC_NA);
offset+=md5_size;
return offset;
}
static int dissect_aim_sst_buddy_down_repl (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = dissect_aim_buddyname(tvb, pinfo, 0, tree);
guint8 md5_size;
guint16 icon_size;
proto_tree_add_item(tree, hf_aim_sst_unknown, tvb, offset, 3, ENC_NA);
offset+=3;
proto_tree_add_item(tree, hf_aim_sst_md5_hash_size, tvb, offset, 1, ENC_BIG_ENDIAN);
md5_size = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_aim_sst_md5_hash, tvb, offset, md5_size, ENC_NA);
offset+=md5_size;
proto_tree_add_item(tree, hf_aim_sst_icon_size, tvb, offset, 2, ENC_BIG_ENDIAN);
icon_size = tvb_get_ntohs(tvb, offset);
offset+=2;
if (icon_size)
{
proto_tree_add_item(tree, hf_aim_sst_icon, tvb, offset, icon_size, ENC_NA);
}
offset+=icon_size;
return offset;
}
static int dissect_aim_sst_buddy_up_repl (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 md5_size;
proto_tree_add_item(tree, hf_aim_sst_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_aim_sst_md5_hash_size, tvb, offset, 1, ENC_BIG_ENDIAN);
md5_size = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_aim_sst_md5_hash, tvb, offset, md5_size, ENC_NA);
offset+=md5_size;
return offset;
}
static int dissect_aim_sst_buddy_up_req (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 icon_size;
proto_tree_add_item(tree, hf_aim_sst_ref_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_aim_sst_icon_size, tvb, offset, 2, ENC_BIG_ENDIAN);
icon_size = tvb_get_ntohs(tvb, offset);
offset+=2;
if (icon_size)
{
proto_tree_add_item(tree, hf_aim_sst_icon, tvb, offset, icon_size, ENC_NA);
}
offset+=icon_size;
return offset;
}
void
proto_register_aim_sst(void)
{
static hf_register_info hf[] = {
{ &hf_aim_sst_md5_hash,
{ "MD5 Hash", "aim_sst.md5", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_md5_hash_size,
{ "MD5 Hash Size", "aim_sst.md5.size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_unknown,
{ "Unknown Data", "aim_sst.unknown", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_ref_num,
{ "Reference Number", "aim_sst.ref_num", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_icon_size,
{ "Icon Size", "aim_sst.icon_size", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_icon,
{ "Icon", "aim_sst.icon", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_aim_sst,
};
proto_aim_sst = proto_register_protocol("AIM Server Side Themes", "AIM SST", "aim_sst");
proto_register_field_array(proto_aim_sst, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_sst(void)
{
aim_init_family(proto_aim_sst, ett_aim_sst, FAMILY_SST, aim_fnac_family_sst);
}
