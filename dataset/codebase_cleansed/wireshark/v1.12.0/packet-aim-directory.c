static int dissect_aim_directory_user_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
while (tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, aim_client_tlvs);
}
return offset;
}
void
proto_register_aim_directory(void)
{
static gint *ett[] = {
&ett_aim_directory
};
proto_aim_directory = proto_register_protocol("AIM Directory Search", "AIM Directory", "aim_dir");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_directory(void)
{
aim_init_family(proto_aim_directory, ett_aim_directory, FAMILY_DIRECTORY, aim_fnac_family_directory);
}
