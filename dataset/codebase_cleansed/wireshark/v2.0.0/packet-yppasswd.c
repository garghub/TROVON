static int
dissect_yppasswd_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item *lock_item = NULL;
proto_tree *lock_tree = NULL;
int offset = 0;
offset = dissect_rpc_string(tvb, tree, hf_yppasswd_oldpass,
offset, NULL);
lock_item = proto_tree_add_item(tree, hf_yppasswd_newpw, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_yppasswd_newpw);
offset = dissect_rpc_string(tvb, lock_tree,
hf_yppasswd_newpw_name, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_yppasswd_newpw_passwd, offset, NULL);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_yppasswd_newpw_uid, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_yppasswd_newpw_gid, offset);
offset = dissect_rpc_string(tvb, lock_tree,
hf_yppasswd_newpw_gecos, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_yppasswd_newpw_dir, offset, NULL);
offset = dissect_rpc_string(tvb, lock_tree,
hf_yppasswd_newpw_shell, offset, NULL);
return offset;
}
static int
dissect_yppasswd_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return dissect_rpc_uint32(tvb, tree, hf_yppasswd_status, 0);
}
void
proto_register_yppasswd(void)
{
static hf_register_info hf[] = {
{ &hf_yppasswd_procedure_v1, {
"V1 Procedure", "yppasswd.procedure_v1", FT_UINT32, BASE_DEC,
VALS(yppasswd1_proc_vals), 0, NULL, HFILL }},
{ &hf_yppasswd_status, {
"status", "yppasswd.status", FT_UINT32, BASE_DEC,
NULL, 0, "YPPasswd update status", HFILL }},
{ &hf_yppasswd_oldpass, {
"oldpass", "yppasswd.oldpass", FT_STRING, BASE_NONE,
NULL, 0, "Old encrypted password", HFILL }},
{ &hf_yppasswd_newpw, {
"newpw", "yppasswd.newpw", FT_NONE, BASE_NONE,
NULL, 0, "New passwd entry", HFILL }},
{ &hf_yppasswd_newpw_name, {
"name", "yppasswd.newpw.name", FT_STRING, BASE_NONE,
NULL, 0, "Username", HFILL }},
{ &hf_yppasswd_newpw_passwd, {
"passwd", "yppasswd.newpw.passwd", FT_STRING, BASE_NONE,
NULL, 0, "Encrypted passwd", HFILL }},
{ &hf_yppasswd_newpw_uid, {
"uid", "yppasswd.newpw.uid", FT_UINT32, BASE_DEC,
NULL, 0, "UserID", HFILL }},
{ &hf_yppasswd_newpw_gid, {
"gid", "yppasswd.newpw.gid", FT_UINT32, BASE_DEC,
NULL, 0, "GroupID", HFILL }},
{ &hf_yppasswd_newpw_gecos, {
"gecos", "yppasswd.newpw.gecos", FT_STRING, BASE_NONE,
NULL, 0, "In real life name", HFILL }},
{ &hf_yppasswd_newpw_dir, {
"dir", "yppasswd.newpw.dir", FT_STRING, BASE_NONE,
NULL, 0, "Home Directory", HFILL }},
{ &hf_yppasswd_newpw_shell, {
"shell", "yppasswd.newpw.shell", FT_STRING, BASE_NONE,
NULL, 0, "Default shell", HFILL }},
};
static gint *ett[] = {
&ett_yppasswd,
&ett_yppasswd_newpw,
};
proto_yppasswd = proto_register_protocol("Yellow Pages Passwd",
"YPPASSWD", "yppasswd");
proto_register_field_array(proto_yppasswd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_yppasswd(void)
{
rpc_init_prog(proto_yppasswd, YPPASSWD_PROGRAM, ett_yppasswd,
G_N_ELEMENTS(yppasswd_vers_info), yppasswd_vers_info);
}
