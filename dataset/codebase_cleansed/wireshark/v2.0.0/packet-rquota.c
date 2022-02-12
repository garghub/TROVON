static int
dissect_rquota(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *lock_item = NULL;
proto_tree *lock_tree = NULL;
lock_item = proto_tree_add_item(tree, hf_rquota_rquota, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_rquota_rquota);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_bsize, offset);
offset = dissect_rpc_bool(tvb, lock_tree,
hf_rquota_active, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_bhardlimit, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_bsoftlimit, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_curblocks, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_fhardlimit, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_fsoftlimit, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_curfiles, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_btimeleft, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_rquota_ftimeleft, offset);
return offset;
}
static int
dissect_getquota_result(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
gint32 status;
int offset = 0;
status = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_rquota_status, offset);
if (status==Q_OK) {
offset = dissect_rquota(tvb, offset, tree);
}
return offset;
}
static int
dissect_getquota_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree,
hf_rquota_pathp, offset, NULL);
offset = dissect_rpc_uint32(tvb, tree,
hf_rquota_uid, offset);
return offset;
}
static int
dissect_getquota2_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree,
hf_rquota_pathp, offset, NULL);
offset = dissect_rpc_uint32(tvb, tree,
hf_rquota_type, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_rquota_id, offset);
return offset;
}
void
proto_register_rquota(void)
{
static struct true_false_string tfs_active = { "Quota is ACTIVE", "Quota is NOT active" };
static hf_register_info hf[] = {
{ &hf_rquota_procedure_v1, {
"V1 Procedure", "rquota.procedure_v1", FT_UINT32, BASE_DEC,
VALS(rquota1_proc_vals), 0, NULL, HFILL }},
{ &hf_rquota_procedure_v2, {
"V2 Procedure", "rquota.procedure_v2", FT_UINT32, BASE_DEC,
VALS(rquota2_proc_vals), 0, NULL, HFILL }},
{ &hf_rquota_uid, {
"uid", "rquota.uid", FT_UINT32, BASE_DEC,
NULL, 0, "User ID", HFILL }},
{ &hf_rquota_type, {
"type", "rquota.type", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rquota_id, {
"id", "rquota.id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_rquota_pathp, {
"pathp", "rquota.pathp", FT_STRING, BASE_NONE,
NULL, 0, "Filesystem of interest", HFILL }},
{ &hf_rquota_status, {
"status", "rquota.status", FT_UINT32, BASE_DEC,
VALS(names_rquota_status), 0, "Status code", HFILL }},
{ &hf_rquota_rquota, {
"rquota", "rquota.rquota", FT_NONE, BASE_NONE,
NULL, 0, "Rquota structure", HFILL }},
{ &hf_rquota_bsize, {
"bsize", "rquota.bsize", FT_UINT32, BASE_DEC,
NULL, 0, "Block size", HFILL }},
{ &hf_rquota_active, {
"active", "rquota.active", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_active), 0x0, "Indicates whether quota is active", HFILL }},
{ &hf_rquota_bhardlimit, {
"bhardlimit", "rquota.bhardlimit", FT_UINT32, BASE_DEC,
NULL, 0, "Hard limit for blocks", HFILL }},
{ &hf_rquota_bsoftlimit, {
"bsoftlimit", "rquota.bsoftlimit", FT_UINT32, BASE_DEC,
NULL, 0, "Soft limit for blocks", HFILL }},
{ &hf_rquota_curblocks, {
"curblocks", "rquota.curblocks", FT_UINT32, BASE_DEC,
NULL, 0, "Current block count", HFILL }},
{ &hf_rquota_fhardlimit, {
"fhardlimit", "rquota.fhardlimit", FT_UINT32, BASE_DEC,
NULL, 0, "Hard limit on allocated files", HFILL }},
{ &hf_rquota_fsoftlimit, {
"fsoftlimit", "rquota.fsoftlimit", FT_UINT32, BASE_DEC,
NULL, 0, "Soft limit of allocated files", HFILL }},
{ &hf_rquota_curfiles, {
"curfiles", "rquota.curfiles", FT_UINT32, BASE_DEC,
NULL, 0, "Current # allocated files", HFILL }},
{ &hf_rquota_btimeleft, {
"btimeleft", "rquota.btimeleft", FT_UINT32, BASE_DEC,
NULL, 0, "Time left for excessive disk use", HFILL }},
{ &hf_rquota_ftimeleft, {
"ftimeleft", "rquota.ftimeleft", FT_UINT32, BASE_DEC,
NULL, 0, "Time left for excessive files", HFILL }},
};
static gint *ett[] = {
&ett_rquota,
&ett_rquota_rquota,
};
proto_rquota = proto_register_protocol("Remote Quota",
"RQUOTA", "rquota");
proto_register_field_array(proto_rquota, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rquota(void)
{
rpc_init_prog(proto_rquota, RQUOTA_PROGRAM, ett_rquota,
G_N_ELEMENTS(rquota_vers_info), rquota_vers_info);
}
