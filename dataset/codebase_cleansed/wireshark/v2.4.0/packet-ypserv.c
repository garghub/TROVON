static int
dissect_ypserv_status(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, gint32 *rstatus)
{
gint32 status;
const char *err;
status=tvb_get_ntohl(tvb, offset);
if(rstatus){
*rstatus=status;
}
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_status, offset);
if(status<0){
err=val_to_str(status, ypstat, "Unknown error:%u");
col_append_fstr(pinfo->cinfo, COL_INFO," %s", err);
proto_item_append_text(tree, " Error:%s", err);
}
return offset;
}
static int
dissect_domain_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item_append_text(tree, " DOMAIN call");
return dissect_rpc_string(tvb,tree,hf_ypserv_domain,0,NULL);
}
static int
dissect_domain_nonack_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item_append_text(tree, " DOMAIN_NONACK call");
return dissect_rpc_string(tvb,tree,hf_ypserv_domain,0,NULL);
}
static int
dissect_maplist_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item_append_text(tree, " MAPLIST call");
return dissect_rpc_string(tvb,tree,hf_ypserv_domain,0,NULL);
}
static int
dissect_domain_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " DOMAIN reply");
proto_tree_add_item(tree, hf_ypserv_servesdomain, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_domain_nonack_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " DOMAIN_NONACK reply");
proto_tree_add_item(tree, hf_ypserv_servesdomain, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_match_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
const char *str;
int offset = 0;
proto_item_append_text(tree, " MATCH call");
offset = dissect_rpc_string(tvb, tree, hf_ypserv_domain, offset, &str);
col_append_fstr(pinfo->cinfo, COL_INFO," %s/", str);
proto_item_append_text(tree, " %s/", str);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, &str);
col_append_fstr(pinfo->cinfo, COL_INFO,"%s/", str);
proto_item_append_text(tree, "%s/", str);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_key, offset, &str);
col_append_str(pinfo->cinfo, COL_INFO, str);
proto_item_append_text(tree, "%s", str);
return offset;
}
static int
dissect_match_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint32 status;
const char *str;
int offset = 0;
proto_item_append_text(tree, " MATCH reply");
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, &status);
if(status>=0){
offset = dissect_rpc_string(tvb, tree, hf_ypserv_value,offset, &str);
col_append_fstr(pinfo->cinfo, COL_INFO," %s", str);
proto_item_append_text(tree, " %s", str);
} else {
offset = dissect_rpc_string(tvb, tree, hf_ypserv_value,offset, NULL);
}
return offset;
}
static int
dissect_first_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " FIRST call");
offset = dissect_rpc_string(tvb, tree, hf_ypserv_domain, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, NULL);
return offset;
}
static int
dissect_first_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " FIRST reply");
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_value, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_key, offset, NULL);
return offset;
}
static int
dissect_next_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " NEXT reply");
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_value, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_key, offset, NULL);
return offset;
}
static int
dissect_next_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " NEXT call");
offset = dissect_rpc_string(tvb, tree, hf_ypserv_domain, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_key, offset, NULL);
return offset;
}
static int
dissect_xfr_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item *sub_item=NULL;
proto_tree *sub_tree=NULL;
int offset = 0;
int start_offset = offset;
proto_item_append_text(tree, " XFR call");
if(tree){
sub_item = proto_tree_add_item(tree, hf_ypserv_map_parms, tvb,
offset, -1, ENC_NA);
if(sub_item)
sub_tree = proto_item_add_subtree(sub_item, ett_ypserv_map_parms);
}
offset = dissect_rpc_string(tvb, sub_tree, hf_ypserv_domain, offset, NULL);
offset = dissect_rpc_string(tvb, sub_tree, hf_ypserv_map, offset, NULL);
offset = dissect_rpc_uint32(tvb, sub_tree, hf_ypserv_ordernum, offset);
offset = dissect_rpc_string(tvb, sub_tree, hf_ypserv_peer, offset, NULL);
proto_tree_add_item(tree, hf_ypserv_transid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_prog, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_port, offset);
if(sub_item)
proto_item_set_len(sub_item, offset - start_offset);
return offset;
}
static int
dissect_clear_call(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " CLEAR call");
return offset;
}
static int
dissect_clear_reply(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item_append_text(tree, " CLEAR reply");
return 0;
}
static int
dissect_xfr_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " XFR reply");
proto_tree_add_item(tree, hf_ypserv_transid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_xfrstat, offset);
return offset;
}
static int
dissect_order_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
const char *str;
int offset = 0;
proto_item_append_text(tree, " ORDER call");
offset = dissect_rpc_string(tvb, tree, hf_ypserv_domain, offset, &str);
col_append_fstr(pinfo->cinfo, COL_INFO," %s/", str);
proto_item_append_text(tree, " %s/", str);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, &str);
col_append_str(pinfo->cinfo, COL_INFO, str);
proto_item_append_text(tree, "%s", str);
return offset;
}
static int
dissect_all_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " ALL call");
offset = dissect_rpc_string(tvb, tree, hf_ypserv_domain, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, NULL);
return offset;
}
static int
dissect_master_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " MASTER call");
offset = dissect_rpc_string(tvb, tree, hf_ypserv_domain, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, NULL);
return offset;
}
static int
dissect_all_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 more;
int offset = 0;
proto_item_append_text(tree, " ALL reply");
for (;;) {
more = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_more, offset);
if (!more)
break;
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_value, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_key, offset, NULL);
}
return offset;
}
static int
dissect_master_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " MASTER reply");
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, NULL);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_peer, offset, NULL);
return offset;
}
static int
dissect_order_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 num;
int offset = 0;
proto_item_append_text(tree, " ORDER reply");
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, NULL);
num=tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_ordernum, offset);
col_append_fstr(pinfo->cinfo, COL_INFO," 0x%08x", num);
proto_item_append_text(tree, " 0x%08x", num);
return offset;
}
static int
dissect_maplist_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item_append_text(tree, " MAPLIST reply");
offset = dissect_ypserv_status(tvb, offset, pinfo, tree, NULL);
while(tvb_get_ntohl(tvb,offset)){
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_more, offset);
offset = dissect_rpc_string(tvb, tree, hf_ypserv_map, offset, NULL);
}
offset = dissect_rpc_uint32(tvb, tree, hf_ypserv_more, offset);
return offset;
}
void
proto_register_ypserv(void)
{
static hf_register_info hf[] = {
{ &hf_ypserv_procedure_v1, {
"V1 Procedure", "ypserv.procedure_v1", FT_UINT32, BASE_DEC,
VALS(ypserv1_proc_vals), 0, NULL, HFILL }},
{ &hf_ypserv_procedure_v2, {
"V2 Procedure", "ypserv.procedure_v2", FT_UINT32, BASE_DEC,
VALS(ypserv2_proc_vals), 0, NULL, HFILL }},
{ &hf_ypserv_domain, {
"Domain", "ypserv.domain", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ypserv_servesdomain, {
"Serves Domain", "ypserv.servesdomain", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_ypserv_map, {
"Map Name", "ypserv.map", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ypserv_peer, {
"Peer Name", "ypserv.peer", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ypserv_more, {
"More", "ypserv.more", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_ypserv_ordernum, {
"Order Number", "ypserv.ordernum", FT_UINT32, BASE_DEC,
NULL, 0, "Order Number for XFR", HFILL }},
{ &hf_ypserv_transid, {
"Host Transport ID", "ypserv.transid", FT_IPv4, BASE_NONE,
NULL, 0, "Host Transport ID to use for XFR Callback", HFILL }},
{ &hf_ypserv_prog, {
"Program Number", "ypserv.prog", FT_UINT32, BASE_DEC,
NULL, 0, "Program Number to use for XFR Callback", HFILL }},
{ &hf_ypserv_port, {
"Port", "ypserv.port", FT_UINT32, BASE_DEC,
NULL, 0, "Port to use for XFR Callback", HFILL }},
{ &hf_ypserv_key, {
"Key", "ypserv.key", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ypserv_value, {
"Value", "ypserv.value", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ypserv_status, {
"Status", "ypserv.status", FT_INT32, BASE_DEC,
VALS(ypstat) , 0, NULL, HFILL }},
{ &hf_ypserv_map_parms, {
"YP Map Parameters", "ypserv.map_parms", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ypserv_xfrstat, {
"Xfrstat", "ypserv.xfrstat", FT_INT32, BASE_DEC,
VALS(xfrstat), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ypserv,
&ett_ypserv_map_parms,
};
proto_ypserv = proto_register_protocol("Yellow Pages Service",
"YPSERV", "ypserv");
proto_register_field_array(proto_ypserv, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ypserv(void)
{
rpc_init_prog(proto_ypserv, YPSERV_PROGRAM, ett_ypserv,
G_N_ELEMENTS(ypserv_vers_info), ypserv_vers_info);
}
