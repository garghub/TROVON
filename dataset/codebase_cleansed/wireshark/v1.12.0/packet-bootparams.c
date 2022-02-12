static int
dissect_bp_address(tvbuff_t *tvb, int offset, proto_tree *tree, int hfindex)
{
guint32 type;
guint32 ipaddr;
type = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_bootparams_addresstype, offset);
switch(type){
case 1:
ipaddr = ((tvb_get_guint8(tvb, offset+3 )&0xff)<<24)
|((tvb_get_guint8(tvb, offset+7 )&0xff)<<16)
|((tvb_get_guint8(tvb, offset+11)&0xff)<<8 )
|((tvb_get_guint8(tvb, offset+15)&0xff) );
proto_tree_add_ipv4(tree, hfindex, tvb,
offset, 16, g_ntohl(ipaddr));
offset += 16;
break;
default:
break;
}
return offset;
}
static int
dissect_getfile_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
if ( tree )
{
offset = dissect_rpc_string(tvb, tree, hf_bootparams_host, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_bootparams_fileid, offset, NULL);
}
return offset;
}
static int
dissect_getfile_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
if ( tree )
{
offset = dissect_rpc_string(tvb, tree, hf_bootparams_host, offset, NULL);
offset = dissect_bp_address(tvb, offset, tree, hf_bootparams_hostaddr);
offset = dissect_rpc_string(tvb, tree, hf_bootparams_filepath, offset, NULL);
}
return offset;
}
static int
dissect_whoami_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
if ( tree )
{
offset = dissect_bp_address(tvb, offset, tree, hf_bootparams_hostaddr);
}
return offset;
}
static int
dissect_whoami_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
if ( tree )
{
offset = dissect_rpc_string(tvb, tree, hf_bootparams_host, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_bootparams_domain, offset, NULL);
offset = dissect_bp_address(tvb, offset, tree, hf_bootparams_routeraddr);
}
return offset;
}
void
proto_register_bootparams(void)
{
static hf_register_info hf[] = {
{ &hf_bootparams_procedure_v1, {
"V1 Procedure", "bootparams.procedure_v1", FT_UINT32, BASE_DEC,
VALS(bootparams1_proc_vals), 0, NULL, HFILL }},
{ &hf_bootparams_host, {
"Client Host", "bootparams.host", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_bootparams_domain, {
"Client Domain", "bootparams.domain", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_bootparams_fileid, {
"File ID", "bootparams.fileid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_bootparams_filepath, {
"File Path", "bootparams.filepath", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_bootparams_hostaddr, {
"Client Address", "bootparams.hostaddr", FT_IPv4, BASE_NONE,
NULL, 0, "Address", HFILL }},
{ &hf_bootparams_routeraddr, {
"Router Address", "bootparams.routeraddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_bootparams_addresstype, {
"Address Type", "bootparams.type", FT_UINT32, BASE_DEC,
VALS(addr_type), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_bootparams,
};
proto_bootparams = proto_register_protocol("Boot Parameters",
"BOOTPARAMS", "bootparams");
proto_register_field_array(proto_bootparams, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bootparams(void)
{
rpc_init_prog(proto_bootparams, BOOTPARAMS_PROGRAM, ett_bootparams);
rpc_init_proc_table(BOOTPARAMS_PROGRAM, 1, bootparams1_proc, hf_bootparams_procedure_v1);
}
