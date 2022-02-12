static int dissect_aim_admin_accnt_info_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *admin_tree)
{
proto_tree_add_item(admin_tree, hf_admin_acctinfo_code, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(admin_tree, hf_admin_acctinfo_unknown, tvb, 2, 2, ENC_BIG_ENDIAN);
return 4;
}
static int dissect_aim_admin_accnt_info_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *admin_tree)
{
int offset = 0;
proto_tree_add_item(admin_tree, hf_admin_acctinfo_permissions, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
return dissect_aim_tlv_list(tvb, pinfo, offset, admin_tree, aim_client_tlvs);
}
static int dissect_aim_admin_info_change_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *admin_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, admin_tree, aim_client_tlvs);
}
static int dissect_aim_admin_cfrm_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *admin_tree)
{
int offset = 0;
proto_tree_add_item(admin_tree, hf_admin_confirm_status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
return dissect_aim_tlv_sequence(tvb, pinfo, offset, admin_tree, aim_client_tlvs);
}
void
proto_register_aim_admin(void)
{
static hf_register_info hf[] = {
{ &hf_admin_acctinfo_code,
{ "Account Information Request Code", "aim_admin.acctinfo.code", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_admin_acctinfo_unknown,
{ "Unknown", "aim_admin.acctinfo.unknown", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_admin_acctinfo_permissions,
{ "Account Permissions", "aim_admin.acctinfo.permissions", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_admin_confirm_status,
{ "Confirmation status", "aim_admin.confirm_status", FT_UINT16, BASE_HEX, VALS(confirm_statusses), 0x0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_aim_admin,
};
proto_aim_admin = proto_register_protocol("AIM Administrative", "AIM Administration", "aim_admin");
proto_register_field_array(proto_aim_admin, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_admin(void)
{
aim_init_family(proto_aim_admin, ett_aim_admin, FAMILY_ADMIN, aim_fnac_family_admin);
}
