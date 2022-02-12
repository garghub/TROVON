static int
rs_misc_dissect_login_get_info_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 key_size;
const char *key_t1 = NULL;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
hf_rs_misc_login_get_info_rqst_var, NULL);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
hf_rs_misc_login_get_info_rqst_key_size, &key_size);
if (key_size){
proto_tree_add_item (tree, hf_rs_misc_login_get_info_rqst_key_t, tvb, offset, key_size, ENC_ASCII|ENC_NA);
key_t1 = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, key_size, ENC_ASCII);
offset += key_size;
col_append_fstr(pinfo->cinfo, COL_INFO,
"rs_login_get_info Request for: %s ", key_t1);
} else {
col_append_str(pinfo->cinfo, COL_INFO,
"rs_login_get_info Request (other)");
}
return offset;
}
void
proto_register_rs_misc (void)
{
static hf_register_info hf[] = {
{ &hf_rs_misc_opnum,
{ "Operation", "rs_misc.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_rs_misc_login_get_info_rqst_var,
{ "Var", "rs_misc.login_get_info_rqst_var", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_rs_misc_login_get_info_rqst_key_size,
{ "Key Size", "rs_misc.login_get_info_rqst_key_size", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_rs_misc_login_get_info_rqst_key_t,
{ "Key", "rs_misc.login_get_info_rqst_key_t", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rs_misc,
};
proto_rs_misc = proto_register_protocol ("DCE/RPC RS_MISC", "rs_misc", "rs_misc");
proto_register_field_array (proto_rs_misc, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_misc (void)
{
dcerpc_init_uuid (proto_rs_misc, ett_rs_misc, &uuid_rs_misc, ver_rs_misc, rs_misc_dissectors, hf_rs_misc_opnum);
}
