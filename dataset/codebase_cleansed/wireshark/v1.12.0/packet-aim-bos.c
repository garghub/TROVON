static int dissect_aim_bos_set_group_perm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bos_tree)
{
int offset = 0;
guint32 userclass = tvb_get_ntohl(tvb, offset);
proto_item *ti = proto_tree_add_uint(bos_tree, hf_aim_bos_class, tvb, offset, 4, userclass);
return dissect_aim_userclass(tvb, offset, 4, ti, userclass);
}
static int dissect_aim_bos_rights(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bos_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, bos_tree, aim_privacy_tlvs);
}
static int dissect_aim_bos_buddyname(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bos_tree)
{
int offset = 0;
while(tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_buddyname(tvb, pinfo, offset, bos_tree);
}
return offset;
}
void
proto_register_aim_bos(void)
{
static hf_register_info hf[] = {
#if 0
{ &hf_aim_bos_data,
{ "Data", "aim_bos.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_aim_bos_class,
{ "User class", "aim_bos.userclass", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_aim_bos,
};
proto_aim_bos = proto_register_protocol("AIM Privacy Management Service", "AIM BOS", "aim_bos");
proto_register_field_array(proto_aim_bos, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_bos(void)
{
aim_init_family(proto_aim_bos, ett_aim_bos, FAMILY_BOS, aim_fnac_family_bos);
}
