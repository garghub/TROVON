static int
epm_dissect_pointer_IF_ID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, di, drep,
di->hf_index, NULL);
offset = dissect_ndr_uint16 (tvb, offset, pinfo, tree, di, drep,
hf_epm_ver_maj, NULL);
offset = dissect_ndr_uint16 (tvb, offset, pinfo, tree, di, drep,
hf_epm_ver_min, NULL);
return offset;
}
static int
epm_dissect_pointer_UUID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, di, drep,
di->hf_index, NULL);
return offset;
}
static int
epm_dissect_ept_lookup_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_inquiry_type, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_pointer_UUID, NDR_POINTER_PTR,
"Object:", hf_epm_object);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_pointer_IF_ID, NDR_POINTER_PTR,
"Interface:", hf_epm_if_id);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_ver_opt, NULL);
offset = dissect_ndr_ctx_hnd (tvb, offset, pinfo, tree, di, drep,
hf_epm_hnd, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_max_ents, NULL);
return offset;
}
static int
epm_dissect_ept_entry_t(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
dcerpc_info *di, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
guint32 len;
const char *str;
if(di->conformant_run){
return offset;
}
if(parent_tree){
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_epm_entry, &item, "Entry:");
}
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, di, drep,
hf_epm_object, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_tower, NDR_POINTER_PTR,
"Tower pointer:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_ann_offset, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_ann_len, &len);
str=tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII);
proto_tree_add_item(tree, hf_epm_annotation, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
if(str&&str[0]){
if(parent_tree) {
proto_item_append_text(item, " Service:%s ", str);
proto_item_append_text(tree->parent, " Service:%s ", str);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Service:%s", str);
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
epm_dissect_ept_entry_t_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep,
epm_dissect_ept_entry_t);
return offset;
}
static int
epm_dissect_ept_lookup_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ctx_hnd (tvb, offset, pinfo, tree, di, drep,
hf_epm_hnd, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_num_ents, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_ept_entry_t_array, NDR_POINTER_REF,
"Entries:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_rc, NULL);
return offset;
}
static int
epm_dissect_uuid (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, di, drep,
hf_epm_uuid, NULL);
return offset;
}
static int
epm_dissect_tower_data (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep _U_)
{
guint16 num_floors, ii;
const char *uuid_name;
guint8 u8little_endian = DREP_LITTLE_ENDIAN;
if(di->conformant_run){
return offset;
}
num_floors = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_epm_tower_num_floors, tvb, offset, 2, num_floors);
offset += 2;
for(ii=0;ii<num_floors;ii++){
proto_item *it = NULL;
proto_tree *tr = NULL;
int old_offset = offset;
guint16 len;
guint8 proto_id;
e_guid_t uuid;
proto_item *pi;
tr = proto_tree_add_subtree_format(tree, tvb, offset, 0, ett_epm_tower_floor, &it, "Floor %d ", ii+1);
len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tr, hf_epm_tower_lhs_len, tvb, offset, 2, len);
offset += 2;
proto_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tr, hf_epm_tower_proto_id, tvb, offset, 1, proto_id);
switch(proto_id){
case PROTO_ID_UUID:
dcerpc_tvb_get_uuid (tvb, offset+1, &u8little_endian, &uuid);
uuid_name = guids_get_uuid_name(&uuid);
if(uuid_name != NULL) {
proto_tree_add_guid_format (tr, hf_epm_uuid, tvb, offset+1, 16, (e_guid_t *) &uuid,
"UUID: %s (%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x)",
uuid_name,
uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7]);
} else {
proto_tree_add_guid_format (tr, hf_epm_uuid, tvb, offset+1, 16, (e_guid_t *) &uuid,
"UUID: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7]);
}
proto_tree_add_item(tr, hf_epm_uuid_version, tvb, offset+17, 2, ENC_BIG_ENDIAN);
{
guint16 version = tvb_get_ntohs(tvb, offset+17);
const char *service = dcerpc_get_proto_name(&uuid, version);
if (service || uuid_name) {
const char *s = service ? service : uuid_name;
proto_item_append_text(tr, "UUID: %s", s);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", s);
} else {
proto_item_append_text(tr, "UUID: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x Version %d.%d", uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7],
tvb_get_guint8(tvb, offset+17),
tvb_get_guint8(tvb, offset+18));
}
}
break;
}
offset += len;
len = tvb_get_letohs(tvb, offset);
pi = proto_tree_add_uint(tr, hf_epm_tower_rhs_len, tvb, offset, 2, len);
offset += 2;
switch(proto_id){
case PROTO_ID_UUID:
proto_tree_add_item(tr, hf_epm_ver_min, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case PROTO_ID_TCP:
proto_tree_add_item(tr, hf_epm_proto_tcp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(tr, "TCP Port:%d", tvb_get_ntohs(tvb, offset));
break;
case PROTO_ID_UDP:
proto_tree_add_item(tr, hf_epm_proto_udp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(tr, "UDP Port:%d", tvb_get_ntohs(tvb, offset));
break;
case PROTO_ID_IP:
proto_tree_add_item(tr, hf_epm_proto_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tr, "IP:%s", tvb_ip_to_str(tvb, offset));
break;
case PROTO_ID_RPC_CO:
proto_item_append_text(tr, "RPC connection-oriented protocol");
break;
case PROTO_ID_RPC_CL:
proto_item_append_text(tr, "RPC connectionless protocol");
proto_tree_add_item(tr, hf_epm_ver_min, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case PROTO_ID_NAMED_PIPES:
proto_tree_add_item(tr, hf_epm_proto_named_pipes, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(tr, "NamedPipe:%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII));
break;
case PROTO_ID_NAMED_PIPES_2:
proto_tree_add_item(tr, hf_epm_proto_named_pipes, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(tr, "PIPE:%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII));
break;
case PROTO_ID_NETBIOS:
proto_tree_add_item(tr, hf_epm_proto_netbios_name, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(tr, "NetBIOS:%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII));
break;
case PROTO_ID_HTTP:
proto_tree_add_item(tr, hf_epm_proto_http_port, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(tr, "RPC over HTTP Port:%d", tvb_get_ntohs(tvb, offset));
break;
default:
if(len){
expert_add_info_format(pinfo, pi, &ei_epm_proto_undecoded, "RightHandSide not decoded yet for proto_id 0x%x",
proto_id);
}
}
offset += len;
proto_item_set_len(it, offset-old_offset);
}
return offset;
}
static void
epm_fmt_uuid_version( gchar *result, guint32 revision )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%02d", (guint8)(( revision & 0xFF00 ) >> 8), (guint8)(revision & 0xFF) );
}
static int
epm_dissect_tower (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
guint3264 len;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint3264 (tvb, offset, pinfo, tree, di, drep,
hf_epm_tower_length, &len);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_tower_length, NULL);
offset = epm_dissect_tower_data(tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
epm_dissect_tower_pointer (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_tower, NDR_POINTER_PTR,
"Tower pointer:", -1);
return offset;
}
static int
epm_dissect_tower_array (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep,
epm_dissect_tower_pointer);
return offset;
}
static int
epm_dissect_ept_map_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_uuid, NDR_POINTER_PTR,
"UUID pointer:", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_tower, NDR_POINTER_PTR,
"Tower pointer:", -1);
offset = dissect_ndr_ctx_hnd (tvb, offset, pinfo, tree, di, drep,
hf_epm_hnd, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_max_towers, NULL);
return offset;
}
static int
epm_dissect_ept_map_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ctx_hnd (tvb, offset, pinfo, tree, di, drep,
hf_epm_hnd, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_num_towers, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_tower_array, NDR_POINTER_REF,
"Tower array:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_rc, NULL);
return offset;
}
static int
epm_dissect_ept_entry_t_ucarray(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, di, drep,
epm_dissect_ept_entry_t);
return offset;
}
static int
epm_dissect_ept_insert_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_num_ents, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_ept_entry_t_ucarray, NDR_POINTER_REF,
"Entries:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_replace, NULL);
return offset;
}
static int
epm_dissect_ept_insert_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_rc, NULL);
return offset;
}
static int
epm_dissect_ept_delete_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_num_ents, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
epm_dissect_ept_entry_t_ucarray, NDR_POINTER_REF,
"Entries:", -1);
return offset;
}
static int
epm_dissect_ept_delete_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_rc, NULL);
return offset;
}
static int
epm_dissect_ept_lookup_handle_free_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ctx_hnd (tvb, offset, pinfo, tree, di, drep,
hf_epm_hnd, NULL);
return offset;
}
static int
epm_dissect_ept_lookup_handle_free_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ctx_hnd (tvb, offset, pinfo, tree, di, drep,
hf_epm_hnd, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_epm_rc, NULL);
return offset;
}
void
proto_register_epm (void)
{
static hf_register_info hf[] = {
{ &hf_epm_opnum,
{ "Operation", "epm.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_epm_inquiry_type,
{ "Inquiry type", "epm.inq_type", FT_UINT32, BASE_DEC, VALS(ep_service), 0x0, NULL, HFILL }},
{ &hf_epm_object,
{ "Object", "epm.object", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_if_id,
{ "Interface", "epm.if_id", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_ver_maj,
{ "Version Major", "epm.ver_maj", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_ver_min,
{ "Version Minor", "epm.ver_min", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_ver_opt,
{ "Version Option", "epm.ver_opt", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_hnd,
{ "Handle", "epm.hnd", FT_BYTES, BASE_NONE, NULL, 0x0, "Context handle", HFILL }},
{ &hf_epm_max_ents,
{ "Max entries", "epm.max_ents", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_num_ents,
{ "Num entries", "epm.num_ents", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_uuid,
{ "UUID", "epm.uuid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_uuid_version,
{ "Version", "epm.uuid_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(epm_fmt_uuid_version), 0x0, NULL, HFILL }},
{ &hf_epm_annotation,
{ "Annotation", "epm.annotation", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_proto_named_pipes,
{ "Named Pipe", "epm.proto.named_pipe", FT_STRING, BASE_NONE, NULL, 0x0, "Name of the named pipe for this service", HFILL }},
{ &hf_epm_proto_netbios_name,
{ "NetBIOS Name", "epm.proto.netbios_name", FT_STRING, BASE_NONE, NULL, 0x0, "NetBIOS name where this service can be found", HFILL }},
{ &hf_epm_tower_length,
{ "Length", "epm.tower.len", FT_UINT32, BASE_DEC, NULL, 0x0, "Length of tower data", HFILL }},
#if 0
{ &hf_epm_tower_data,
{ "Tower", "epm.tower", FT_BYTES, BASE_NONE, NULL, 0x0, "Tower data", HFILL }},
#endif
{ &hf_epm_max_towers,
{ "Max Towers", "epm.max_towers", FT_UINT32, BASE_DEC, NULL, 0x0, "Maximum number of towers to return", HFILL }},
{ &hf_epm_num_towers,
{ "Num Towers", "epm.num_towers", FT_UINT32, BASE_DEC, NULL, 0x0, "Number number of towers to return", HFILL }},
{ &hf_epm_ann_offset,
{ "Annotation offset", "epm.ann_offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_ann_len,
{ "Annotation length", "epm.ann_len", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_epm_rc,
{ "Return code", "epm.rc", FT_UINT32, BASE_HEX, NULL, 0x0, "EPM return value", HFILL }},
{ &hf_epm_replace,
{ "Replace", "epm.replace", FT_UINT8, BASE_DEC, NULL, 0x0, "Replace existing objects?", HFILL }},
{ &hf_epm_tower_num_floors,
{ "Number of floors", "epm.tower.num_floors", FT_UINT16, BASE_DEC, NULL, 0x0, "Number of floors in tower", HFILL }},
{ &hf_epm_proto_udp_port,
{ "UDP Port", "epm.proto.udp_port", FT_UINT16, BASE_DEC, NULL, 0x0, "UDP Port where this service can be found", HFILL }},
{ &hf_epm_proto_tcp_port,
{ "TCP Port", "epm.proto.tcp_port", FT_UINT16, BASE_DEC, NULL, 0x0, "TCP Port where this service can be found", HFILL }},
{ &hf_epm_proto_http_port,
{ "TCP Port", "epm.proto.http_port", FT_UINT16, BASE_DEC, NULL, 0x0, "TCP Port where this service can be found", HFILL }},
{ &hf_epm_tower_rhs_len,
{ "RHS Length", "epm.tower.rhs.len", FT_UINT16, BASE_DEC, NULL, 0x0, "Length of RHS data", HFILL }},
{ &hf_epm_tower_lhs_len,
{ "LHS Length", "epm.tower.lhs.len", FT_UINT16, BASE_DEC, NULL, 0x0, "Length of LHS data", HFILL }},
{ &hf_epm_proto_ip,
{ "IP", "epm.proto.ip", FT_IPv4, BASE_NONE, NULL, 0x0, "IP address where service is located", HFILL }},
{ &hf_epm_tower_proto_id,
{ "Protocol", "epm.tower.proto_id", FT_UINT8, BASE_HEX, VALS(proto_id_vals), 0x0, "Protocol identifier", HFILL }}
};
static gint *ett[] = {
&ett_epm,
&ett_epm_tower_floor,
&ett_epm_entry
};
static ei_register_info ei[] = {
{ &ei_epm_proto_undecoded, { "epm.proto_id.undecoded", PI_UNDECODED, PI_WARN, "RightHandSide not decoded yet for proto_id", EXPFILL }},
};
expert_module_t* expert_epm3;
proto_epm3 = proto_register_protocol ("DCE/RPC Endpoint Mapper", "EPM", "epm");
proto_register_field_array (proto_epm3, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_epm3 = expert_register_protocol(proto_epm3);
expert_register_field_array(expert_epm3, ei, array_length(ei));
proto_epm4 = proto_register_protocol ("DCE/RPC Endpoint Mapper v4", "EPMv4", "epm4");
}
void
proto_reg_handoff_epm (void)
{
dcerpc_init_uuid (proto_epm3, ett_epm, &uuid_epm, ver_epm3, epm_dissectors, hf_epm_opnum);
dcerpc_init_uuid (proto_epm4, ett_epm, &uuid_epm, ver_epm4, epm_dissectors, hf_epm_opnum);
}
