static int
dissect_holder(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
lock_item = proto_tree_add_item(tree, hf_klm_holder, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_klm_holder);
offset = dissect_rpc_bool( tvb, lock_tree,
hf_klm_exclusive, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_klm_pid, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_klm_offset, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_klm_len, offset);
return offset;
}
static int
dissect_lock(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset, rpc_call_info_value *civ)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
lock_item = proto_tree_add_item(tree, hf_klm_lock, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_klm_lock);
offset = dissect_rpc_string(tvb, lock_tree,
hf_klm_servername, offset, NULL);
offset = dissect_nfs3_fh(tvb, offset, pinfo, lock_tree,"fh", NULL, civ);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_klm_pid, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_klm_offset, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_klm_len, offset);
return offset;
}
static int
dissect_klm_unlock_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
offset = dissect_lock(tvb, pinfo, tree, offset, (rpc_call_info_value*)data);
return offset;
}
static int
dissect_klm_stat_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_uint32(tvb, tree,
hf_klm_stats, offset);
return offset;
}
static int
dissect_klm_lock_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
offset = dissect_rpc_bool( tvb, tree,
hf_klm_block, offset);
offset = dissect_rpc_bool( tvb, tree,
hf_klm_exclusive, offset);
offset = dissect_lock(tvb, pinfo, tree, offset, (rpc_call_info_value*)data);
return offset;
}
static int
dissect_klm_test_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
gint32 stats;
stats = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_klm_stats, offset);
if (stats == KLM_DENIED) {
offset = dissect_holder(tvb, tree, offset);
}
return offset;
}
static int
dissect_klm_test_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
offset = dissect_rpc_bool( tvb, tree,
hf_klm_exclusive, offset);
offset = dissect_lock(tvb, pinfo, tree, offset, (rpc_call_info_value*)data);
return offset;
}
void
proto_register_klm(void)
{
static struct true_false_string tfs_exclusive = { "Exclusive", "Not exclusive" };
static struct true_false_string tfs_block = { "Block", "Do not block" };
static hf_register_info hf[] = {
{ &hf_klm_procedure_v1, {
"V1 Procedure", "klm.procedure_v1", FT_UINT32, BASE_DEC,
VALS(klm1_proc_vals), 0, NULL, HFILL }},
{ &hf_klm_exclusive, {
"exclusive", "klm.exclusive", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_exclusive), 0x0, "Exclusive lock", HFILL }},
{ &hf_klm_lock, {
"lock", "klm.lock", FT_NONE, BASE_NONE,
NULL, 0, "KLM lock structure", HFILL }},
{ &hf_klm_servername, {
"server name", "klm.servername", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_klm_pid, {
"pid", "klm.pid", FT_UINT32, BASE_DEC,
NULL, 0, "ProcessID", HFILL }},
{ &hf_klm_offset, {
"offset", "klm.offset", FT_UINT32, BASE_DEC,
NULL, 0, "File offset", HFILL }},
{ &hf_klm_len, {
"length", "klm.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of lock region", HFILL }},
{ &hf_klm_stats, {
"stats", "klm.stats", FT_UINT32, BASE_DEC,
VALS(names_klm_stats), 0, NULL, HFILL }},
{ &hf_klm_holder, {
"holder", "klm.holder", FT_NONE, BASE_NONE,
NULL, 0, "KLM lock holder", HFILL }},
{ &hf_klm_block, {
"block", "klm.block", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_block), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_klm,
&ett_klm_lock,
&ett_klm_holder,
};
proto_klm = proto_register_protocol("Kernel Lock Manager",
"KLM", "klm");
proto_register_field_array(proto_klm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_klm(void)
{
rpc_init_prog(proto_klm, KLM_PROGRAM, ett_klm);
rpc_init_proc_table(KLM_PROGRAM, 1, klm1_proc, hf_klm_procedure_v1);
}
