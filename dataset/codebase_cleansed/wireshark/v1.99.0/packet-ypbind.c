static int
dissect_ypbind_domain_v2_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ypbind_domain, offset, NULL);
return offset;
}
static int
dissect_ypbind_domain_v2_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 type;
type=tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_ypbind_resp_type, offset);
switch(type){
case YPBIND_RESP_TYPE_SUCC_VAL:
proto_tree_add_item(tree, hf_ypbind_addr,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree,
hf_ypbind_port, offset);
break;
case YPBIND_RESP_TYPE_FAIL_VAL:
offset = dissect_rpc_uint32(tvb, tree,
hf_ypbind_resp_type, offset);
break;
}
return offset;
}
static int
dissect_ypbind_setdomain_v2_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ypbind_domain, offset, NULL);
proto_tree_add_item(tree, hf_ypbind_addr,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree,
hf_ypbind_port, offset);
offset = dissect_rpc_uint32(tvb, tree,
hf_ypbind_setdom_version, offset);
return offset;
}
void
proto_register_ypbind(void)
{
static hf_register_info hf[] = {
{ &hf_ypbind_procedure_v1, {
"V1 Procedure", "ypbind.procedure_v1", FT_UINT32, BASE_DEC,
VALS(ypbind1_proc_vals), 0, NULL, HFILL }},
{ &hf_ypbind_procedure_v2, {
"V2 Procedure", "ypbind.procedure_v2", FT_UINT32, BASE_DEC,
VALS(ypbind2_proc_vals), 0, NULL, HFILL }},
{ &hf_ypbind_domain, {
"Domain", "ypbind.domain", FT_STRING, BASE_NONE,
NULL, 0, "Name of the NIS/YP Domain", HFILL }},
{ &hf_ypbind_resp_type, {
"Response Type", "ypbind.resp_type", FT_UINT32, BASE_DEC,
VALS(resp_type_vals), 0, NULL, HFILL }},
#if 0
{ &hf_ypbind_error, {
"Error", "ypbind.error", FT_UINT32, BASE_DEC,
VALS(error_vals), 0, "YPBIND Error code", HFILL }},
#endif
{ &hf_ypbind_addr, {
"IP Addr", "ypbind.addr", FT_IPv4, BASE_NONE,
NULL, 0, "IP Address of server", HFILL }},
{ &hf_ypbind_port, {
"Port", "ypbind.port", FT_UINT32, BASE_DEC,
NULL, 0, "Port to use", HFILL }},
{ &hf_ypbind_setdom_version, {
"Version", "ypbind.setdom.version", FT_UINT32, BASE_DEC,
NULL, 0, "Version of setdom", HFILL }},
};
static gint *ett[] = {
&ett_ypbind,
};
proto_ypbind = proto_register_protocol("Yellow Pages Bind",
"YPBIND", "ypbind");
proto_register_field_array(proto_ypbind, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ypbind(void)
{
rpc_init_prog(proto_ypbind, YPBIND_PROGRAM, ett_ypbind);
rpc_init_proc_table(YPBIND_PROGRAM, 1, ypbind1_proc, hf_ypbind_procedure_v1);
rpc_init_proc_table(YPBIND_PROGRAM, 2, ypbind2_proc, hf_ypbind_procedure_v2);
}
