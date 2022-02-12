static int
rpriv_dissect_get_eptgt_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 authn_svc, authz_svc, key_size, key_size2, var1;
const char *key_t1 = NULL;
const char *key_t2 = NULL;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_rpriv_get_eptgt_rqst_authn_svc, &authn_svc);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_rpriv_get_eptgt_rqst_authz_svc, &authz_svc);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_rpriv_get_eptgt_rqst_var1, &var1);
offset += 276;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_rpriv_get_eptgt_rqst_key_size2, &key_size);
proto_tree_add_item (tree, hf_rpriv_get_eptgt_rqst_key_t, tvb, offset, key_size, ENC_ASCII|ENC_NA);
key_t1 = tvb_get_ephemeral_string(tvb, offset, key_size);
offset += key_size;
offset += 8;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_rpriv_get_eptgt_rqst_key_size2, &key_size2);
proto_tree_add_item (tree, hf_rpriv_get_eptgt_rqst_key_t2, tvb, offset, key_size2, ENC_ASCII|ENC_NA);
key_t2 = tvb_get_ephemeral_string(tvb, offset, key_size2);
offset += key_size2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO,
" Request for: %s in %s ", key_t2, key_t1);
}
return offset;
}
void
proto_register_rpriv (void)
{
static hf_register_info hf[] = {
{ &hf_rpriv_opnum,
{ "Operation", "rpriv.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rpriv_get_eptgt_rqst_authn_svc,
{ "Authn_Svc", "rpriv.get_eptgt_rqst_authn_svc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rpriv_get_eptgt_rqst_authz_svc,
{ "Authz_Svc", "rpriv.get_eptgt_rqst_authz_svc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_rpriv_get_eptgt_rqst_key_size,
{ "Key_Size", "rpriv.get_eptgt_rqst_key_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_rpriv_get_eptgt_rqst_var1,
{ "Var1", "rpriv.get_eptgt_rqst_var1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rpriv_get_eptgt_rqst_key_size2,
{ "Key_Size", "rpriv.get_eptgt_rqst_key_size2", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rpriv_get_eptgt_rqst_key_t,
{ "Key_t", "rpriv.get_eptgt_rqst_key_t", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rpriv_get_eptgt_rqst_key_t2,
{ "Key_t2", "rpriv.get_eptgt_rqst_key_t2", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rpriv,
};
proto_rpriv = proto_register_protocol ("Privilege Server operations", "rpriv", "rpriv");
proto_register_field_array (proto_rpriv, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rpriv (void)
{
dcerpc_init_uuid (proto_rpriv, ett_rpriv, &uuid_rpriv, ver_rpriv, rpriv_dissectors, hf_rpriv_opnum);
}
