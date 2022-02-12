ETH_HF
ETH_ETT
static int
ucarray_drsuapi_dissect_DsReplicaSyncRequest1Info_nc_dn(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
static guint32 len;
int old_offset;
if(di->conformant_run){
old_offset=offset;
offset=dissect_dcerpc_uint32(tvb, offset, pinfo, NULL, drep, -1, &len);
di->array_max_count_offset=offset-4;
di->conformant_run=1;
di->conformant_eaten=offset-old_offset;
return offset;
}
ALIGN_TO_2_BYTES;
if (tree && len) {
proto_tree_add_item(tree, hf_drsuapi_DsReplicaSyncRequest1Info_nc_dn, tvb, offset,
len*2, ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
offset+=2*len;
return offset;
}
static int
drsuapi_dissect_a_string(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hf_index, guint32 param _U_)
{
offset=dissect_ndr_vstring(tvb, offset, pinfo, tree, di, drep, 1, hf_index, FALSE, NULL);
return offset;
}
ETH_CODE
void
proto_register_drsuapi(void)
{
static hf_register_info hf[] = {
{ &hf_drsuapi_DsReplicaSyncRequest1Info_nc_dn,
{ "nc_dn", "drsuapi.DsReplicaSyncRequest1Info.nc_dn", FT_STRING, BASE_NONE,
NULL, 0,
NULL, HFILL }},
ETH_HFARR
};
static gint *ett[] = {
ETH_ETTARR
};
proto_drsuapi = proto_register_protocol(
"DRSUAPI",
"DRSUAPI", "drsuapi");
proto_register_field_array(proto_drsuapi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_drsuapi(void)
{
ETH_HANDOFF
}
