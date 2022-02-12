static int
my_id_len(tvbuff_t *tvb, int offset)
{
int len;
len = tvb_get_ntohl(tvb, offset);
if(len&0x03)
len = (len&0xfc)+4;
len += 16;
return len;
}
static int
mon_id_len(tvbuff_t *tvb, int offset)
{
int len;
len = tvb_get_ntohl(tvb, offset);
if(len&0x03){
len = (len&0xfc)+4;
}
len += 4;
return len+my_id_len(tvb,offset+len);
}
static int
dissect_stat_stat(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
if (tree)
{
offset = dissect_rpc_string(tvb,tree,hfi_stat_mon_name.id,offset,NULL);
}
return offset;
}
static int
dissect_stat_stat_res(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item* sub_item = NULL;
proto_tree* sub_tree = NULL;
gint32 res;
if (tree) {
sub_item = proto_tree_add_item(tree, &hfi_stat_stat_res, tvb,
offset, -1, ENC_NA);
if (sub_item)
sub_tree = proto_item_add_subtree(sub_item, ett_stat_stat_res);
}
res = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb,sub_tree,hfi_stat_stat_res_res.id,offset);
if (res==STAT_SUCC) {
offset = dissect_rpc_uint32(tvb,sub_tree,hfi_stat_stat_res_state.id,offset);
} else {
offset += 4;
}
return offset;
}
static int
dissect_stat_my_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item* sub_item = NULL;
proto_tree* sub_tree = NULL;
if (tree) {
sub_item = proto_tree_add_item(tree, &hfi_stat_my_id, tvb,
offset, my_id_len(tvb,offset), ENC_NA);
if (sub_item)
sub_tree = proto_item_add_subtree(sub_item, ett_stat_my_id);
}
offset = dissect_rpc_string(tvb,sub_tree,hfi_stat_my_id_hostname.id,offset,NULL);
offset = dissect_rpc_uint32(tvb,sub_tree,hfi_stat_my_id_prog.id,offset);
offset = dissect_rpc_uint32(tvb,sub_tree,hfi_stat_my_id_vers.id,offset);
offset = dissect_rpc_uint32(tvb,sub_tree,hfi_stat_my_id_proc.id,offset);
return offset;
}
static int
dissect_stat_mon_id(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item* sub_item = NULL;
proto_tree* sub_tree = NULL;
if (tree) {
sub_item = proto_tree_add_item(tree, &hfi_stat_mon, tvb,
offset, mon_id_len(tvb,offset), ENC_NA);
if (sub_item)
sub_tree = proto_item_add_subtree(sub_item, ett_stat_mon);
}
offset = dissect_rpc_string(tvb,sub_tree,hfi_stat_mon_id_name.id,offset,NULL);
offset = dissect_stat_my_id(tvb,offset,sub_tree);
return offset;
}
static int
dissect_stat_priv(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, &hfi_stat_priv, tvb, offset, 16, ENC_NA);
offset += 16;
return offset;
}
static int
dissect_stat_mon(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_stat_mon_id(tvb,offset,pinfo,tree,data);
offset = dissect_stat_priv(tvb,offset,tree);
return offset;
}
static int
dissect_stat_state(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_uint32(tvb,tree,hfi_stat_state.id,offset);
return offset;
}
static int
dissect_stat_notify(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item* sub_item = NULL;
proto_tree* sub_tree = NULL;
int start_offset = offset;
if (tree) {
sub_item = proto_tree_add_item(tree, &hfi_stat_stat_chge, tvb,
offset, -1, ENC_NA);
if (sub_item)
sub_tree = proto_item_add_subtree(sub_item, ett_stat_stat_chge);
}
offset = dissect_rpc_string(tvb,sub_tree,hfi_stat_mon_id_name.id,offset,NULL);
offset = dissect_rpc_uint32(tvb,tree,hfi_stat_state.id,offset);
if(sub_item)
proto_item_set_len(sub_item, offset - start_offset);
return offset;
}
static int
dissect_stat_umon_all(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_stat_my_id(tvb,offset,tree);
return offset;
}
void
proto_register_stat(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_stat_procedure_v1,
&hfi_stat_mon_name,
&hfi_stat_stat_res,
&hfi_stat_stat_res_res,
&hfi_stat_stat_res_state,
&hfi_stat_mon,
&hfi_stat_mon_id_name,
&hfi_stat_my_id,
&hfi_stat_my_id_hostname,
&hfi_stat_my_id_prog,
&hfi_stat_my_id_vers,
&hfi_stat_my_id_proc,
&hfi_stat_priv,
&hfi_stat_state,
&hfi_stat_stat_chge,
};
#endif
static gint *ett[] = {
&ett_stat,
&ett_stat_stat_res,
&ett_stat_mon,
&ett_stat_my_id,
&ett_stat_stat_chge,
};
int proto_stat;
proto_stat = proto_register_protocol("Network Status Monitor Protocol", "STAT", "stat");
hfi_stat = proto_registrar_get_nth(proto_stat);
proto_register_fields(proto_stat, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_stat(void)
{
rpc_init_prog(hfi_stat->id, STAT_PROGRAM, ett_stat);
rpc_init_proc_table(STAT_PROGRAM, 1, stat1_proc, hfi_stat_procedure_v1.id);
}
