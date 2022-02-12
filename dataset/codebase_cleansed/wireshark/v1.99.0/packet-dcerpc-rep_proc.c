void
proto_register_rep_proc (void)
{
static hf_register_info hf[] = {
{ &hf_rep_proc_opnum,
{ "Operation", "rep_proc.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rep_proc,
};
proto_rep_proc = proto_register_protocol ("DCE DFS Replication Server", "REP_PROC", "rep_proc");
proto_register_field_array (proto_rep_proc, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rep_proc (void)
{
dcerpc_init_uuid (proto_rep_proc, ett_rep_proc, &uuid_rep_proc, ver_rep_proc, rep_proc_dissectors, hf_rep_proc_opnum);
}
