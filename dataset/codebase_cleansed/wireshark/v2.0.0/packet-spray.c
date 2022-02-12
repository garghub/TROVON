static int
dissect_get_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item* lock_item = NULL;
proto_tree* lock_tree = NULL;
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree,
hf_spray_counter, offset);
lock_item = proto_tree_add_item(tree, hf_spray_clock, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_spray_clock);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_spray_sec, offset);
offset = dissect_rpc_uint32(tvb, lock_tree,
hf_spray_usec, offset);
return offset;
}
static int
dissect_spray_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return dissect_rpc_data(tvb, tree, hf_spray_sprayarr, 0);
}
void
proto_register_spray(void)
{
static hf_register_info hf[] = {
{ &hf_spray_procedure_v1, {
"V1 Procedure", "spray.procedure_v1", FT_UINT32, BASE_DEC,
VALS(spray1_proc_vals), 0, NULL, HFILL }},
{ &hf_spray_sprayarr, {
"Data", "spray.sprayarr", FT_BYTES, BASE_NONE,
NULL, 0, "Sprayarr data", HFILL }},
{ &hf_spray_counter, {
"counter", "spray.counter", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_spray_clock, {
"clock", "spray.clock", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_spray_sec, {
"sec", "spray.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Seconds", HFILL }},
{ &hf_spray_usec, {
"usec", "spray.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Microseconds", HFILL }}
};
static gint *ett[] = {
&ett_spray,
&ett_spray_clock,
};
proto_spray = proto_register_protocol("SPRAY", "SPRAY", "spray");
proto_register_field_array(proto_spray, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_spray(void)
{
rpc_init_prog(proto_spray, SPRAY_PROGRAM, ett_spray,
G_N_ELEMENTS(spray_vers_info), spray_vers_info);
}
