static itl_nexus_t *
get_itl_nexus(packet_info *pinfo, gboolean create_new)
{
itl_nexus_t *itl;
if(create_new || !(itl=(itl_nexus_t *)wmem_tree_lookup32_le(ndmp_conv_data->itl, pinfo->fd->num))){
itl=wmem_new(wmem_file_scope(), itl_nexus_t);
itl->cmdset=0xff;
itl->conversation=ndmp_conv_data->conversation;
wmem_tree_insert32(ndmp_conv_data->itl, pinfo->fd->num, itl);
}
return itl;
}
static guint8
get_ndmp_protocol_version(void)
{
if(!ndmp_conv_data || (ndmp_conv_data->version==NDMP_PROTOCOL_UNKNOWN)){
return ndmp_default_protocol_version;
}
return ndmp_conv_data->version;
}
static gboolean
check_ndmp_rm(tvbuff_t *tvb, packet_info *pinfo)
{
guint len;
guint32 tmp;
if ((pinfo->srcport!=TCP_PORT_NDMP)&&(pinfo->destport!=TCP_PORT_NDMP)) {
return FALSE;
}
len=tvb_length(tvb);
if(len>=4){
tmp=(tvb_get_ntohl(tvb, 0)&RPC_RM_FRAGLEN);
if( (tmp<1)||(tmp>1000000) ){
return FALSE;
}
}
return TRUE;
}
static gboolean
check_ndmp_hdr(tvbuff_t *tvb )
{
guint len;
guint32 tmp;
len=tvb_length(tvb);
if (len<24){
return FALSE;
}
if(len>=8){
tmp=tvb_get_ntohl(tvb, 4);
if( (tmp<0x12ceec50)||(tmp>0x70dc1ed0) ){
return FALSE;
}
}
if(len>=12){
tmp=tvb_get_ntohl(tvb, 8);
if( tmp>1 ){
return FALSE;
}
}
if(len>=16){
tmp=tvb_get_ntohl(tvb, 12);
if( (tmp>0xa09) || (tmp==0) ){
return FALSE;
}
}
if(len>=24){
tmp=tvb_get_ntohl(tvb, 20);
if( (tmp>0x17) ){
return FALSE;
}
}
return TRUE;
}
static int
dissect_connect_open_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
guint32 version;
proto_tree_add_item(tree, hf_ndmp_version, tvb, offset, 4, ENC_BIG_ENDIAN);
version=tvb_get_ntohl(tvb, offset);
ndmp_conv_data->version=version;
offset += 4;
return offset;
}
static int
dissect_error(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
guint32 err;
err=tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_ndmp_error, tvb, offset, 4, ENC_BIG_ENDIAN);
if(err) {
col_append_fstr(pinfo->cinfo, COL_INFO,
" NDMP Error:%s ",
val_to_str(err, error_vals,
"Unknown NDMP error code %#x"));
}
offset += 4;
return offset;
}
static int
dissect_ndmp_get_host_info_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_hostname, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_os_type, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_os_vers, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_hostid, offset, NULL);
return offset;
}
static int
dissect_ndmp_addr_type(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
proto_tree_add_item(tree, hf_ndmp_addr_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_ndmp_addr_msg(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
return dissect_ndmp_addr_type(tvb, offset, pinfo, tree, NULL);
}
static int
dissect_ndmp_config_get_connection_type_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_ndmp_addr_type, hf_ndmp_addr_types);
return offset;
}
static int
dissect_auth_type(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
proto_tree_add_item(tree, hf_ndmp_auth_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_get_auth_type_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
return dissect_auth_type(tvb, offset, pinfo, tree, NULL);
}
static int
dissect_auth_attr_msg(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
guint type;
type=tvb_get_ntohl(tvb,offset);
proto_tree_add_item(tree, hf_ndmp_auth_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(type){
case NDMP_AUTH_NONE:
break;
case NDMP_AUTH_TEXT:
break;
case NDMP_AUTH_MD5:
proto_tree_add_item(tree, hf_ndmp_auth_challenge,
tvb, offset, 64, ENC_NA);
offset+=64;
}
return offset;
}
static int
dissect_ndmp_config_get_auth_attr_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint32 seq)
{
offset = dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_auth_attr_msg(tvb, offset, pinfo, tree, seq);
return offset;
}
static int
dissect_default_env(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_butype_env_name, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_butype_env_value, offset, NULL);
return offset;
}
static int
dissect_butype_attrs(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Attributes: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_butype_attrs);
}
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_recover_utf8,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_backup_utf8,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_recover_incremental,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_backup_incremental,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_recover_direct,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_backup_direct,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_recover_filelist,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_backup_filelist,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_butype_attr_backup_file_history,
tvb, offset, 4, flags);
offset += 4;
return offset;
}
static int
dissect_butype_info(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_butype_name, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_default_env, hf_ndmp_butype_default_env);
offset = dissect_butype_attrs(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_get_butype_info_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_butype_info, hf_ndmp_butype_info);
return offset;
}
static int
dissect_fs_invalid(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Invalids: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_fs_invalid);
}
proto_tree_add_boolean(tree, hf_ndmp_fs_invalid_used_inodes,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_fs_invalid_total_inodes,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_fs_invalid_avail_size,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_fs_invalid_used_size,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_fs_invalid_total_size,
tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int
dissect_fs_env(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_fs_env_name, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_fs_env_value, offset, NULL);
return offset;
}
static int
dissect_fs_info(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset=dissect_fs_invalid(tvb, offset, pinfo, tree);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_fs_fs_type, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_fs_logical_device, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_fs_physical_device, offset, NULL);
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_fs_total_size,
offset);
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_fs_used_size,
offset);
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_fs_avail_size,
offset);
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_fs_total_inodes,
offset);
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_fs_used_inodes,
offset);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_fs_env, hf_ndmp_fs_env);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_fs_status, offset, NULL);
return offset;
}
static int
dissect_get_fs_info_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_fs_info, hf_ndmp_fs_info);
return offset;
}
static int
dissect_tape_attr(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Attributes: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_tape_attr);
}
proto_tree_add_boolean(tree, hf_ndmp_tape_attr_unload,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_attr_rewind,
tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int
dissect_tape_capability(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tape_capability_name, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tape_capability_value, offset, NULL);
return offset;
}
static int
dissect_tape_dev_cap(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tape_device, offset, NULL);
offset = dissect_tape_attr(tvb, offset, pinfo, tree);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_tape_capability, hf_ndmp_tape_capability);
return offset;
}
static int
dissect_tape_info(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tape_model, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_tape_dev_cap, hf_ndmp_tape_dev_cap);
return offset;
}
static int
dissect_get_tape_info_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_tape_info, hf_ndmp_tape_info);
return offset;
}
static int
dissect_scsi_info(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_scsi_model, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_tape_dev_cap, hf_ndmp_tape_dev_cap);
return offset;
}
static int
dissect_get_scsi_info_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_scsi_info, hf_ndmp_scsi_info);
return offset;
}
static int
dissect_get_server_info_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_server_vendor, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_server_product, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_server_revision, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_auth_type, hf_ndmp_auth_types);
return offset;
}
static int
dissect_ext_version(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_) {
proto_tree_add_item(tree, hf_ndmp_ext_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_class_list(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_) {
proto_tree_add_item(tree, hf_ndmp_ex_class_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_ext_version, hf_ndmp_ext_version_list);
return offset;
}
static int
dissect_get_ext_list_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_class_list, hf_ndmp_class_list);
return offset;
}
static int
dissect_class_version(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_) {
proto_tree_add_item(tree, hf_ndmp_ex_class_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_ex_class_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_set_ext_list_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_class_version, hf_ndmp_class_version);
return offset;
}
static int
dissect_set_ext_list_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
return offset;
}
static int
dissect_scsi_open_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_scsi_device, offset, NULL);
if(!pinfo->fd->flags.visited){
get_itl_nexus(pinfo, TRUE);
}
return offset;
}
static int
dissect_scsi_get_state_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
proto_tree_add_item(tree, hf_ndmp_scsi_controller, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_scsi_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_scsi_lun, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_scsi_set_state_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_scsi_device, offset, NULL);
proto_tree_add_item(tree, hf_ndmp_scsi_controller, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_scsi_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_scsi_lun, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_execute_cdb_flags(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags = tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Flags: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_execute_cdb_flags);
}
proto_tree_add_boolean(tree, hf_ndmp_execute_cdb_flags_data_in,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_execute_cdb_flags_data_out,
tvb, offset, 4, flags);
offset += 4;
return offset;
}
static int
dissect_execute_cdb_cdb(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *parent_tree, gint devtype)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 cdb_len;
guint32 cdb_len_full;
cdb_len = tvb_get_ntohl(tvb, offset);
cdb_len_full = rpc_roundup(cdb_len);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset,
4+cdb_len_full, "CDB");
tree = proto_item_add_subtree(item, ett_ndmp_execute_cdb_cdb);
}
proto_tree_add_uint(tree, hf_ndmp_execute_cdb_cdb_len, tvb, offset, 4,
cdb_len);
offset += 4;
if (cdb_len != 0) {
tvbuff_t *cdb_tvb;
int tvb_len, tvb_rlen;
tvb_len=tvb_length_remaining(tvb, offset);
if(tvb_len>16)
tvb_len=16;
tvb_rlen=tvb_reported_length_remaining(tvb, offset);
if(tvb_rlen>16)
tvb_rlen=16;
cdb_tvb=tvb_new_subset(tvb, offset, tvb_len, tvb_rlen);
if(ndmp_conv_data->task && !ndmp_conv_data->task->itlq){
ndmp_conv_data->task->itlq=wmem_new(wmem_file_scope(), itlq_nexus_t);
ndmp_conv_data->task->itlq->lun=0xffff;
ndmp_conv_data->task->itlq->first_exchange_frame=pinfo->fd->num;
ndmp_conv_data->task->itlq->last_exchange_frame=0;
ndmp_conv_data->task->itlq->scsi_opcode=0xffff;
ndmp_conv_data->task->itlq->task_flags=0;
ndmp_conv_data->task->itlq->data_length=0;
ndmp_conv_data->task->itlq->bidir_data_length=0;
ndmp_conv_data->task->itlq->flags=0;
ndmp_conv_data->task->itlq->alloc_len=0;
ndmp_conv_data->task->itlq->fc_time=pinfo->fd->abs_ts;
ndmp_conv_data->task->itlq->extra_data=NULL;
}
if(ndmp_conv_data->task && ndmp_conv_data->task->itlq){
dissect_scsi_cdb(cdb_tvb, pinfo, top_tree, devtype, ndmp_conv_data->task->itlq, get_itl_nexus(pinfo, FALSE));
}
offset += cdb_len_full;
}
return offset;
}
static int
dissect_execute_cdb_payload(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree,
const char *name, int hf_len, gboolean isreq)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 payload_len;
guint32 payload_len_full;
payload_len = tvb_get_ntohl(tvb, offset);
payload_len_full = rpc_roundup(payload_len);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset,
4+payload_len_full, "%s", name);
tree = proto_item_add_subtree(item,
ett_ndmp_execute_cdb_payload);
}
proto_tree_add_uint(tree, hf_len, tvb, offset, 4, payload_len);
offset += 4;
if ((int) payload_len > 0) {
tvbuff_t *data_tvb;
int tvb_len, tvb_rlen;
tvb_len=tvb_length_remaining(tvb, offset);
if(tvb_len>(int)payload_len)
tvb_len=payload_len;
tvb_rlen=tvb_reported_length_remaining(tvb, offset);
if(tvb_rlen>(int)payload_len)
tvb_rlen=payload_len;
data_tvb=tvb_new_subset(tvb, offset, tvb_len, tvb_rlen);
if(ndmp_conv_data->task && ndmp_conv_data->task->itlq){
ndmp_conv_data->task->itlq->task_flags=SCSI_DATA_READ|SCSI_DATA_WRITE;
ndmp_conv_data->task->itlq->data_length=payload_len;
ndmp_conv_data->task->itlq->bidir_data_length=payload_len;
dissect_scsi_payload(data_tvb, pinfo, top_tree, isreq,
ndmp_conv_data->task->itlq,
get_itl_nexus(pinfo, FALSE),
0);
}
offset += payload_len_full;
}
return offset;
}
static int
dissect_execute_cdb_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_, gint devtype)
{
offset = dissect_execute_cdb_flags(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_ndmp_execute_cdb_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_execute_cdb_datain_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_execute_cdb_cdb(tvb, offset, pinfo, tree, devtype);
offset = dissect_execute_cdb_payload(tvb, offset, pinfo, tree,
"Data out", hf_ndmp_execute_cdb_dataout_len, TRUE);
return offset;
}
static int
dissect_execute_cdb_request_mc(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
return dissect_execute_cdb_request(tvb, offset, pinfo, tree, seq,
SCSI_DEV_SMC);
}
static int
dissect_execute_cdb_request_tape(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
return dissect_execute_cdb_request(tvb, offset, pinfo, tree, seq,
SCSI_DEV_SSC);
}
static int
dissect_execute_cdb_sns(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 sns_len;
guint32 sns_len_full;
sns_len = tvb_get_ntohl(tvb, offset);
sns_len_full = rpc_roundup(sns_len);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset,
4+sns_len_full, "Sense data");
tree = proto_item_add_subtree(item, ett_ndmp_execute_cdb_sns);
}
proto_tree_add_uint(tree, hf_ndmp_execute_cdb_sns_len, tvb, offset, 4,
sns_len);
offset += 4;
if (sns_len != 0) {
if(ndmp_conv_data->task && ndmp_conv_data->task->itlq){
dissect_scsi_snsinfo(tvb, pinfo, top_tree, offset, sns_len, ndmp_conv_data->task->itlq, get_itl_nexus(pinfo, FALSE));
}
offset += sns_len_full;
}
return offset;
}
static int
dissect_execute_cdb_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
guint32 status;
offset=dissect_error(tvb, offset, pinfo, tree, seq);
proto_tree_add_item(tree, hf_ndmp_execute_cdb_status, tvb, offset, 4, ENC_BIG_ENDIAN);
status=tvb_get_ntohl(tvb, offset);
if(ndmp_conv_data->task && ndmp_conv_data->task->itlq){
dissect_scsi_rsp(tvb, pinfo, top_tree, ndmp_conv_data->task->itlq, get_itl_nexus(pinfo, FALSE), (guint8)status);
}
offset += 4;
proto_tree_add_item(tree, hf_ndmp_execute_cdb_dataout_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_execute_cdb_payload(tvb, offset, pinfo, tree,
"Data in", hf_ndmp_execute_cdb_datain_len, FALSE);
offset = dissect_execute_cdb_sns(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_tape_open_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tape_device, offset, NULL);
proto_tree_add_item(tree, hf_ndmp_tape_open_mode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(!pinfo->fd->flags.visited){
get_itl_nexus(pinfo, TRUE);
}
return offset;
}
static int
dissect_tape_invalid(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Invalids: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_tape_invalid);
}
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_partition,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_space_remain,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_total_space,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_block_no,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_block_size,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_soft_errors,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_invalid_file_num,
tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int
dissect_tape_flags(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Flags: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_tape_flags);
}
proto_tree_add_boolean(tree, hf_ndmp_tape_flags_unload,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_flags_error,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_flags_write_protect,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_tape_flags_no_rewind,
tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int
dissect_tape_get_state_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_tape_invalid(tvb, offset, pinfo, tree);
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset=dissect_tape_flags(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_ndmp_tape_file_num, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_tape_soft_errors, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_tape_block_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_tape_block_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint64(tvb, tree,hf_ndmp_tape_total_space,
offset);
offset = dissect_rpc_uint64(tvb, tree,hf_ndmp_tape_space_remain,
offset);
if (get_ndmp_protocol_version() == NDMP_PROTOCOL_V4)
return offset;
proto_tree_add_item(tree, hf_ndmp_tape_partition, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_tape_mtio_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_tape_mtio_op, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_tape_mtio_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
proto_tree_add_item(tree, hf_ndmp_resid_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_tcp_env(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tcp_env_name, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_tcp_env_value, offset, NULL);
return offset;
}
static int
dissect_ndmp_v4_tcp_addr(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree_add_item(tree, hf_ndmp_addr_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_ndmp_addr_tcp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_tcp_env, hf_ndmp_tcp_default_env);
return offset;
}
static int
dissect_ndmp_addr(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 type;
type=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Type: %s ", val_to_str(type, addr_type_vals,"Unknown addr type (0x%02x)") );
tree = proto_item_add_subtree(item, ett_ndmp_addr);
}
proto_tree_add_item(tree, hf_ndmp_addr_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(type){
case NDMP_ADDR_LOCAL:
break;
case NDMP_ADDR_TCP:
if(get_ndmp_protocol_version()<NDMP_PROTOCOL_V4){
proto_tree_add_item(tree, hf_ndmp_addr_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_ndmp_addr_tcp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
} else {
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_ndmp_v4_tcp_addr, hf_ndmp_tcp_addr_list);
}
break;
case NDMP_ADDR_FC:
proto_tree_add_item(tree, hf_ndmp_addr_fcal_loop_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case NDMP_ADDR_IPC:
offset = dissect_rpc_data(tvb, tree, hf_ndmp_addr_ipc, offset);
break;
}
return offset;
}
static int
dissect_data_connect_msg(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset=dissect_ndmp_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_mover_get_state_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
if(get_ndmp_protocol_version()>=NDMP_PROTOCOL_V4){
proto_tree_add_item(tree, hf_ndmp_mover_mode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_ndmp_mover_state, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_mover_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_halt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_record_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_record_num, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_data_written, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_seek_position, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_bytes_left_to_read, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_window_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_window_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
if(get_ndmp_protocol_version()==NDMP_PROTOCOL_V2){
return offset;
}
offset=dissect_ndmp_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_mover_listen_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_mover_mode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_addr_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_mover_listen_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset=dissect_ndmp_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_mover_set_window_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_window_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_window_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_mover_set_record_size_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_record_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_mover_connect_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_mover_mode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset=dissect_ndmp_addr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_log_file_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_file_name, offset, NULL);
offset=dissect_error(tvb, offset, pinfo, tree, seq);
return offset;
}
static int
dissect_log_message_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_log_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_log_message_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_log_message, offset, NULL);
return offset;
}
static int
dissect_notify_data_halted_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_halt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(get_ndmp_protocol_version()){
case NDMP_PROTOCOL_V2:
case NDMP_PROTOCOL_V3:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_halt_reason, offset, NULL);
break;
}
return offset;
}
static int
dissect_notify_mover_halted_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_halt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(get_ndmp_protocol_version()){
case NDMP_PROTOCOL_V2:
case NDMP_PROTOCOL_V3:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_halt_reason, offset, NULL);
break;
}
return offset;
}
static int
dissect_notify_connected_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_connected, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_connected_reason, offset, NULL);
return offset;
}
static int
dissect_notify_mover_paused_request(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_mover_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_seek_position, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_auth_data(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint type;
type=tvb_get_ntohl(tvb,offset);
proto_tree_add_item(tree, hf_ndmp_auth_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(type){
case NDMP_AUTH_NONE:
break;
case NDMP_AUTH_TEXT:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_auth_id, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_auth_password, offset, NULL);
break;
case NDMP_AUTH_MD5:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_auth_id, offset, NULL);
proto_tree_add_item(tree, hf_ndmp_auth_digest,
tvb, offset, 16, ENC_NA);
offset+=16;
}
return offset;
}
static int
dissect_connect_client_auth_request(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint32 seq _U_)
{
return dissect_auth_data(tvb, offset, pinfo, tree);
}
static int
dissect_connect_server_auth_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_auth_data(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_tape_write_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_data(tvb, tree, hf_ndmp_data, offset);
return offset;
}
static int
dissect_tape_write_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
proto_tree_add_item(tree, hf_ndmp_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_tape_read_request(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 seq _U_)
{
proto_tree_add_item(tree, hf_ndmp_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_tape_read_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_data(tvb, tree, hf_ndmp_data, offset);
return offset;
}
static int
dissect_file_name(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
int old_offset=offset;
guint32 type;
const char *name;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1,
"File");
tree = proto_item_add_subtree(item, ett_ndmp_file_name);
}
type=tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_ndmp_file_fs_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(type){
case NDMP_FS_UNIX:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_file_name, offset, &name);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
break;
case NDMP_FS_NT:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_nt_file_name, offset, &name);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_dos_file_name, offset, NULL);
break;
default:
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_file_name, offset, &name);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_const(type, file_fs_type_vals, "Unknown type") );
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_file_invalids(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Invalids: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_file_invalids);
}
proto_tree_add_boolean(tree, hf_ndmp_file_invalid_group,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_file_invalid_ctime,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_file_invalid_atime,
tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int
dissect_file_stats(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
int old_offset=offset;
nstime_t ns;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1,
"Stats:");
tree = proto_item_add_subtree(item, ett_ndmp_file_stats);
}
offset = dissect_file_invalids(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_ndmp_file_fs_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_file_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ns.secs=tvb_get_ntohl(tvb, offset);
ns.nsecs=0;
proto_tree_add_time(tree, hf_ndmp_file_mtime, tvb, offset, 4, &ns);
offset += 4;
ns.secs=tvb_get_ntohl(tvb, offset);
ns.nsecs=0;
proto_tree_add_time(tree, hf_ndmp_file_atime, tvb, offset, 4, &ns);
offset += 4;
ns.secs=tvb_get_ntohl(tvb, offset);
ns.nsecs=0;
proto_tree_add_time(tree, hf_ndmp_file_ctime, tvb, offset, 4, &ns);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_file_owner, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_file_group, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_file_fattr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_file_size,
offset);
proto_tree_add_item(tree, hf_ndmp_file_links, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_ndmp_file(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
int old_offset=offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1,
"File:");
tree = proto_item_add_subtree(item, ett_ndmp_file);
}
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_file_name, hf_ndmp_file_names);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_file_stats, hf_ndmp_file_stats);
proto_tree_add_item(tree, hf_ndmp_file_node, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_file_fh_info, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_fh_add_file_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_ndmp_file, hf_ndmp_files);
return offset;
}
static int
dissect_dir(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_file_name, hf_ndmp_file_names);
proto_tree_add_item(tree, hf_ndmp_file_node, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_file_parent, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_fh_add_dir_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_dir, hf_ndmp_dirs);
return offset;
}
static int
dissect_node(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_file_stats, hf_ndmp_file_stats);
proto_tree_add_item(tree, hf_ndmp_file_node, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_file_fh_info, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_fh_add_node_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_node, hf_ndmp_nodes);
return offset;
}
static int
dissect_data_start_backup_request(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_butype_name, offset, NULL);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_default_env, hf_ndmp_butype_default_env);
return offset;
}
static int
dissect_nlist(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_bu_original_path, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_bu_destination_dir, offset, NULL);
if(get_ndmp_protocol_version()==NDMP_PROTOCOL_V2){
offset += 4;
} else {
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_bu_new_name, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_bu_other_name, offset, NULL);
proto_tree_add_item(tree, hf_ndmp_file_node, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
proto_tree_add_item(tree, hf_ndmp_file_fh_info, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_data_start_recover_request(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint32 seq _U_)
{
if(get_ndmp_protocol_version()==NDMP_PROTOCOL_V2){
offset=dissect_ndmp_addr(tvb, offset, pinfo, tree);
}
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_default_env, hf_ndmp_butype_default_env);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_nlist, hf_ndmp_nlist);
offset = dissect_rpc_string(tvb, tree,
hf_ndmp_butype_name, offset, NULL);
return offset;
}
static int
dissect_data_get_env_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
offset=dissect_error(tvb, offset, pinfo, tree, seq);
offset = dissect_rpc_array(tvb, pinfo, tree, offset,
dissect_default_env, hf_ndmp_butype_default_env);
return offset;
}
static int
dissect_state_invalids(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *parent_tree)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
guint32 flags;
flags=tvb_get_ntohl(tvb, offset);
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Invalids: 0x%08x", flags);
tree = proto_item_add_subtree(item, ett_ndmp_state_invalids);
}
proto_tree_add_boolean(tree, hf_ndmp_state_invalid_etr,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_ndmp_state_invalid_ebr,
tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int
dissect_data_get_state_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint32 seq)
{
nstime_t ns;
offset = dissect_state_invalids(tvb, offset, pinfo, tree);
offset=dissect_error(tvb, offset, pinfo, tree, seq);
proto_tree_add_item(tree, hf_ndmp_bu_operation, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_data_state, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_ndmp_data_halted, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_data_bytes_processed,
offset);
offset = dissect_rpc_uint64(tvb, tree, hf_ndmp_data_est_bytes_remain,
offset);
ns.secs=tvb_get_ntohl(tvb, offset);
ns.nsecs=0;
proto_tree_add_time(tree, hf_ndmp_data_est_time_remain, tvb, offset, 4, &ns);
offset += 4;
offset=dissect_ndmp_addr(tvb, offset, pinfo, tree);
proto_tree_add_item(tree, hf_ndmp_window_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_ndmp_window_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_ndmp_header(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, struct ndmp_header *nh)
{
proto_item* item = NULL;
proto_tree* tree = NULL;
nstime_t ns;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_ndmp_header, tvb,
offset, 24, ENC_NA);
tree = proto_item_add_subtree(item, ett_ndmp_header);
}
proto_tree_add_uint(tree, hf_ndmp_sequence, tvb, offset, 4, nh->seq);
offset += 4;
ns.secs=nh->time;
ns.nsecs=0;
proto_tree_add_time(tree, hf_ndmp_timestamp, tvb, offset, 4, &ns);
offset += 4;
proto_tree_add_uint(tree, hf_ndmp_msgtype, tvb, offset, 4, nh->type);
offset += 4;
proto_tree_add_uint(tree, hf_ndmp_msg, tvb, offset, 4, nh->msg);
offset += 4;
proto_tree_add_uint(tree, hf_ndmp_reply_sequence, tvb, offset, 4, nh->rep_seq);
offset += 4;
offset=dissect_error(tvb, offset, pinfo, tree, nh->seq);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s ",
val_to_str(nh->msg, msg_vals, "Unknown Message (0x%02x)"),
val_to_str(nh->type, msg_type_vals, "Unknown Type (0x%02x)")
);
return offset;
}
static int
dissect_ndmp_cmd(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, struct ndmp_header *nh)
{
int i;
proto_item *cmd_item=NULL;
proto_tree *cmd_tree=NULL;
offset=dissect_ndmp_header(tvb, offset, pinfo, tree, nh);
for(i=0;ndmp_commands[i].cmd!=0;i++){
if(ndmp_commands[i].cmd==nh->msg){
break;
}
}
if(ndmp_commands[i].cmd==0){
proto_tree_add_text(tree, tvb, offset, -1, "Unknown type of NDMP message: 0x%02x", nh->msg);
offset+=tvb_length_remaining(tvb, offset);
return offset;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
if(tree){
cmd_item = proto_tree_add_text(tree, tvb, offset, -1, "%s",
msg_vals[i].strptr);
cmd_tree = proto_item_add_subtree(cmd_item, ett_ndmp);
}
}
if(nh->type==NDMP_MESSAGE_REQUEST){
if(ndmp_commands[i].request){
offset=ndmp_commands[i].request(tvb, offset, pinfo, cmd_tree,
nh->seq);
}
} else {
if(ndmp_commands[i].response){
offset=ndmp_commands[i].response(tvb, offset, pinfo, cmd_tree,
nh->rep_seq);
}
}
return offset;
}
static int
dissect_ndmp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
int offset = 0;
guint32 ndmp_rm;
struct ndmp_header nh;
guint32 size;
guint32 seq, len, nxt, frag_num;
gint nbytes;
int direction;
struct tcpinfo *tcpinfo;
ndmp_frag_info* nfi;
proto_item *ndmp_item = NULL;
proto_tree *ndmp_tree = NULL;
proto_item *hdr_item = NULL;
proto_tree *hdr_tree = NULL;
wmem_map_t *frags;
conversation_t *conversation;
proto_item *vers_item;
gboolean save_fragmented, save_writable;
gboolean do_frag = TRUE;
tvbuff_t* new_tvb = NULL;
fragment_head *frag_msg = NULL;
if (data == NULL && ndmp_defragment && ndmp_desegment)
return 0;
top_tree=tree;
conversation = find_or_create_conversation(pinfo);
ndmp_conv_data=(ndmp_conv_data_t *)conversation_get_proto_data(conversation, proto_ndmp);
if(!ndmp_conv_data){
ndmp_conv_data=wmem_new(wmem_file_scope(), ndmp_conv_data_t);
ndmp_conv_data->version = NDMP_PROTOCOL_UNKNOWN;
ndmp_conv_data->tasks = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
ndmp_conv_data->itl = wmem_tree_new(wmem_file_scope());
ndmp_conv_data->conversation = conversation;
ndmp_conv_data->fragsA = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
ndmp_conv_data->fragsB = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(conversation, proto_ndmp, ndmp_conv_data);
conversation_set_dissector(conversation, ndmp_handle);
}
ndmp_rm=tvb_get_ntohl(tvb, offset);
save_fragmented = pinfo->fragmented;
if (ndmp_defragment && ndmp_desegment)
{
direction=CMP_ADDRESS(&pinfo->src, &pinfo->dst);
if(direction==0) {
direction= (pinfo->srcport > pinfo->destport) ? 1 : -1;
}
if(direction>=0){
frags = ndmp_conv_data->fragsA;
} else {
frags = ndmp_conv_data->fragsB;
}
tcpinfo = (struct tcpinfo *)data;
seq = tcpinfo->seq;
len = (ndmp_rm & RPC_RM_FRAGLEN) + 4;
nxt = seq + len;
tcpinfo->seq = nxt;
nfi = (ndmp_frag_info *)wmem_map_lookup(frags, GUINT_TO_POINTER(seq));
if (!nfi)
{
frag_num = 0;
if ( !(ndmp_rm & RPC_RM_LASTFRAG))
{
if ( !(pinfo->fd->flags.visited))
{
nfi=wmem_new(wmem_file_scope(), ndmp_frag_info);
nfi->first_seq = seq;
nfi->offset = 1;
wmem_map_insert(frags, GUINT_TO_POINTER(nxt), (void *)nfi);
}
}
else
{
do_frag = FALSE;
new_tvb = tvb_new_subset_remaining(tvb, 4);
}
}
else
{
frag_num = nfi->offset;
seq = nfi->first_seq;
if ( !(ndmp_rm & RPC_RM_LASTFRAG))
{
if ( !(pinfo->fd->flags.visited))
{
nfi=wmem_new(wmem_file_scope(), ndmp_frag_info);
nfi->first_seq = seq;
nfi->offset = frag_num+1;
wmem_map_insert(frags, GUINT_TO_POINTER(nxt), (void *)nfi);
}
}
}
if (do_frag)
{
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&ndmp_reassembly_table,
tvb, 4, pinfo, seq, NULL,
frag_num,
tvb_length_remaining(tvb, offset)-4,
!(ndmp_rm & RPC_RM_LASTFRAG));
new_tvb = process_reassembled_data(tvb, 4, pinfo, "Reassembled NDMP", frag_msg, &ndmp_frag_items, NULL, tree);
}
if (!(ndmp_rm & RPC_RM_LASTFRAG)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NDMP");
col_set_str(pinfo->cinfo, COL_INFO, "[NDMP fragment] ");
if (tree) {
ndmp_item = proto_tree_add_item(tree, proto_ndmp, tvb, 0, -1, ENC_NA);
ndmp_tree = proto_item_add_subtree(ndmp_item, ett_ndmp);
}
hdr_item = proto_tree_add_text(ndmp_tree, tvb, 0, 4,
"Fragment header: %s%u %s",
(ndmp_rm & RPC_RM_LASTFRAG) ? "Last fragment, " : "",
ndmp_rm & RPC_RM_FRAGLEN, plurality(ndmp_rm & RPC_RM_FRAGLEN, "byte", "bytes"));
hdr_tree = proto_item_add_subtree(hdr_item, ett_ndmp_fraghdr);
proto_tree_add_boolean(hdr_tree, hf_ndmp_lastfrag, tvb, 0, 4, ndmp_rm);
proto_tree_add_uint(hdr_tree, hf_ndmp_fraglen, tvb, 0, 4, ndmp_rm);
nbytes = tvb_reported_length_remaining(tvb, 4);
proto_tree_add_text(ndmp_tree, tvb, 4, nbytes, "NDMP fragment data (%u byte%s)", nbytes, plurality(nbytes, "", "s"));
pinfo->fragmented = save_fragmented;
return tvb_length(tvb);
}
}
else
{
new_tvb = tvb_new_subset_remaining(tvb, 4);
}
size = tvb_length_remaining(new_tvb, offset);
if (size < 24) {
pinfo->fragmented = save_fragmented;
return tvb_length(tvb);
}
if (!check_ndmp_hdr(new_tvb))
{
pinfo->fragmented = save_fragmented;
return tvb_length(tvb);
}
nh.seq = tvb_get_ntohl(new_tvb, offset);
nh.time = tvb_get_ntohl(new_tvb, offset+4);
nh.type = tvb_get_ntohl(new_tvb, offset+8);
nh.msg = tvb_get_ntohl(new_tvb, offset+12);
nh.rep_seq = tvb_get_ntohl(new_tvb, offset+16);
nh.err = tvb_get_ntohl(new_tvb, offset+20);
save_writable = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, TRUE);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NDMP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ndmp_item = proto_tree_add_item(tree, proto_ndmp, tvb, 0, -1, ENC_NA);
ndmp_tree = proto_item_add_subtree(ndmp_item, ett_ndmp);
}
if(ndmp_conv_data->version!=NDMP_PROTOCOL_UNKNOWN){
vers_item=proto_tree_add_uint(ndmp_tree, hf_ndmp_version, new_tvb, offset, 0, ndmp_conv_data->version);
} else {
vers_item=proto_tree_add_uint_format(ndmp_tree, hf_ndmp_version, new_tvb, offset, 0, ndmp_default_protocol_version, "Unknown NDMP version, using default:%d", ndmp_default_protocol_version);
}
PROTO_ITEM_SET_GENERATED(vers_item);
ndmp_conv_data->task=NULL;
switch(nh.type){
case NDMP_MESSAGE_REQUEST:
if(!pinfo->fd->flags.visited){
ndmp_conv_data->task=wmem_new(wmem_file_scope(), ndmp_task_data_t);
ndmp_conv_data->task->request_frame=pinfo->fd->num;
ndmp_conv_data->task->response_frame=0;
ndmp_conv_data->task->ndmp_time=pinfo->fd->abs_ts;
ndmp_conv_data->task->itlq=NULL;
wmem_map_insert(ndmp_conv_data->tasks, GUINT_TO_POINTER(nh.seq), ndmp_conv_data->task);
} else {
ndmp_conv_data->task=(ndmp_task_data_t *)wmem_map_lookup(ndmp_conv_data->tasks, GUINT_TO_POINTER(nh.seq));
}
if(ndmp_conv_data->task && ndmp_conv_data->task->response_frame){
proto_item *it;
it=proto_tree_add_uint(ndmp_tree, hf_ndmp_response_frame, new_tvb, 0, 0, ndmp_conv_data->task->response_frame);
PROTO_ITEM_SET_GENERATED(it);
}
break;
case NDMP_MESSAGE_REPLY:
ndmp_conv_data->task=(ndmp_task_data_t *)wmem_map_lookup(ndmp_conv_data->tasks, GUINT_TO_POINTER(nh.rep_seq));
if(ndmp_conv_data->task && !pinfo->fd->flags.visited){
ndmp_conv_data->task->response_frame=pinfo->fd->num;
if(ndmp_conv_data->task->itlq){
ndmp_conv_data->task->itlq->last_exchange_frame=pinfo->fd->num;
}
}
if(ndmp_conv_data->task && ndmp_conv_data->task->request_frame){
proto_item *it;
nstime_t delta_ts;
it=proto_tree_add_uint(ndmp_tree, hf_ndmp_request_frame, new_tvb, 0, 0, ndmp_conv_data->task->request_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&delta_ts, &pinfo->fd->abs_ts, &ndmp_conv_data->task->ndmp_time);
it=proto_tree_add_time(ndmp_tree, hf_ndmp_time, new_tvb, 0, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(it);
}
break;
}
hdr_item = proto_tree_add_text(ndmp_tree, tvb, 0, 4,
"Fragment header: %s%u %s",
(ndmp_rm & RPC_RM_LASTFRAG) ? "Last fragment, " : "",
ndmp_rm & RPC_RM_FRAGLEN, plurality(ndmp_rm & RPC_RM_FRAGLEN, "byte", "bytes"));
hdr_tree = proto_item_add_subtree(hdr_item, ett_ndmp_fraghdr);
proto_tree_add_boolean(hdr_tree, hf_ndmp_lastfrag, tvb, 0, 4, ndmp_rm);
proto_tree_add_uint(hdr_tree, hf_ndmp_fraglen, tvb, 0, 4, ndmp_rm);
dissect_ndmp_cmd(new_tvb, offset, pinfo, ndmp_tree, &nh);
pinfo->fragmented = save_fragmented;
col_set_writable(pinfo->cinfo, save_writable);
return tvb_length(tvb);
}
static guint
get_ndmp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint len;
len=tvb_get_ntohl(tvb, offset)&0x7fffffff;
return len+4;
}
gboolean
check_if_ndmp(tvbuff_t *tvb, packet_info *pinfo)
{
guint len;
guint32 tmp;
if ((pinfo->srcport!=TCP_PORT_NDMP)&&(pinfo->destport!=TCP_PORT_NDMP)) {
return FALSE;
}
len=tvb_length(tvb);
if(len>=4){
tmp=(tvb_get_ntohl(tvb, 0)&RPC_RM_FRAGLEN);
if( (tmp<24)||(tmp>1000000) ){
return FALSE;
}
}
if(len>=12){
tmp=tvb_get_ntohl(tvb, 8);
if( (tmp<0x12ceec50)||(tmp>0x70dc1ed0) ){
return FALSE;
}
}
if(len>=16){
tmp=tvb_get_ntohl(tvb, 12);
if( tmp>1 ){
return FALSE;
}
}
if(len>=20){
tmp=tvb_get_ntohl(tvb, 16);
if( (tmp>0xa09) || (tmp==0) ){
return FALSE;
}
}
if(len>=28){
tmp=tvb_get_ntohl(tvb, 24);
if( (tmp>0x17) ){
return FALSE;
}
}
return TRUE;
}
static int
dissect_ndmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if(ndmp_defragment && !check_ndmp_rm(tvb, pinfo)) {
return 0;
}
if(!(ndmp_desegment && ndmp_defragment) && !check_if_ndmp(tvb, pinfo)) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, ndmp_desegment, 4,
get_ndmp_pdu_len, dissect_ndmp_message, data);
return tvb_length(tvb);
}
static int
dissect_ndmp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (tvb_length(tvb) < 28)
return 0;
if (!check_if_ndmp(tvb, pinfo))
return 0;
tcp_dissect_pdus(tvb, pinfo, tree, ndmp_desegment, 28,
get_ndmp_pdu_len, dissect_ndmp_message, data);
return tvb_length(tvb);
}
static void
ndmp_init(void)
{
reassembly_table_init(&ndmp_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_ndmp(void)
{
static hf_register_info hf_ndmp[] = {
{ &hf_ndmp_header, {
"NDMP Header", "ndmp.header", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_response_frame, {
"Response In", "ndmp.response_frame", FT_FRAMENUM, BASE_NONE,
NULL, 0, "The response to this NDMP command is in this frame", HFILL }},
{ &hf_ndmp_time,
{ "Time from request", "ndmp.time", FT_RELATIVE_TIME, BASE_NONE, NULL,
0, "Time since the request packet", HFILL }},
{ &hf_ndmp_request_frame, {
"Request In", "ndmp.request_frame", FT_FRAMENUM, BASE_NONE,
NULL, 0, "The request to this NDMP command is in this frame", HFILL }},
{ &hf_ndmp_sequence, {
"Sequence", "ndmp.sequence", FT_UINT32, BASE_DEC,
NULL, 0, "Sequence number for NDMP PDU", HFILL }},
{ &hf_ndmp_reply_sequence, {
"Reply Sequence", "ndmp.reply_sequence", FT_UINT32, BASE_DEC,
NULL, 0, "Reply Sequence number for NDMP PDU", HFILL }},
{ &hf_ndmp_timestamp, {
"Time", "ndmp.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Timestamp for this NDMP PDU", HFILL }},
{ &hf_ndmp_msgtype, {
"Type", "ndmp.msg_type", FT_UINT32, BASE_DEC,
VALS(msg_type_vals), 0, "Is this a Request or Response?", HFILL }},
{ &hf_ndmp_msg, {
"Message", "ndmp.msg", FT_UINT32, BASE_HEX,
VALS(msg_vals), 0, "Type of NDMP PDU", HFILL }},
{ &hf_ndmp_error, {
"Error", "ndmp.error", FT_UINT32, BASE_DEC,
VALS(error_vals), 0, "Error code for this NDMP PDU", HFILL }},
{ &hf_ndmp_version, {
"Version", "ndmp.version", FT_UINT32, BASE_DEC,
NULL, 0, "Version of NDMP protocol", HFILL }},
{ &hf_ndmp_hostname, {
"Hostname", "ndmp.hostname", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_hostid, {
"HostID", "ndmp.hostid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_os_type, {
"OS Type", "ndmp.os.type", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_os_vers, {
"OS Version", "ndmp.os.version", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_addr_types, {
"Addr Types", "ndmp.addr_types", FT_NONE, BASE_NONE,
NULL, 0, "List Of Address Types", HFILL }},
{ &hf_ndmp_addr_type, {
"Addr Type", "ndmp.addr_type", FT_UINT32, BASE_DEC,
VALS(addr_type_vals), 0, "Address Type", HFILL }},
{ &hf_ndmp_auth_type, {
"Auth Type", "ndmp.auth_type", FT_UINT32, BASE_DEC,
VALS(auth_type_vals), 0, "Authentication Type", HFILL }},
{ &hf_ndmp_auth_challenge, {
"Challenge", "ndmp.auth.challenge", FT_BYTES, BASE_NONE,
NULL, 0, "Authentication Challenge", HFILL }},
{ &hf_ndmp_auth_digest, {
"Digest", "ndmp.auth.digest", FT_BYTES, BASE_NONE,
NULL, 0, "Authentication Digest", HFILL }},
{ &hf_ndmp_butype_info, {
"Butype Info", "ndmp.butype.info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_butype_name, {
"Butype Name", "ndmp.butype.name", FT_STRING, BASE_NONE,
NULL, 0, "Name of Butype", HFILL }},
{ &hf_ndmp_butype_default_env, {
"Default Env", "ndmp.butype.default_env", FT_NONE, BASE_NONE,
NULL, 0, "Default Env's for this Butype Info", HFILL }},
{ &hf_ndmp_tcp_addr_list, {
"TCP Ports", "ndmp.tcp.port_list", FT_NONE, BASE_NONE,
NULL, 0, "List of TCP ports", HFILL }},
{ &hf_ndmp_tcp_default_env, {
"Default Env", "ndmp.tcp.default_env", FT_NONE, BASE_NONE,
NULL, 0, "Default Env's for this Butype Info", HFILL }},
{ &hf_ndmp_butype_attr_backup_file_history, {
"Backup file history", "ndmp.butype.attr.backup_file_history", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_backup_file_history), 0x00000001, "backup_file_history", HFILL }},
{ &hf_ndmp_butype_attr_backup_filelist, {
"Backup file list", "ndmp.butype.attr.backup_filelist", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_backup_filelist), 0x00000002, "backup_filelist", HFILL }},
{ &hf_ndmp_butype_attr_recover_filelist, {
"Recover file list", "ndmp.butype.attr.recover_filelist", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_recover_filelist), 0x00000004, "recover_filelist", HFILL }},
{ &hf_ndmp_butype_attr_backup_direct, {
"Backup direct", "ndmp.butype.attr.backup_direct", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_backup_direct), 0x00000008, "backup_direct", HFILL }},
{ &hf_ndmp_butype_attr_recover_direct, {
"Recover direct", "ndmp.butype.attr.recover_direct", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_recover_direct), 0x00000010, "recover_direct", HFILL }},
{ &hf_ndmp_butype_attr_backup_incremental, {
"Backup incremental", "ndmp.butype.attr.backup_incremental", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_backup_incremental), 0x00000020, "backup_incremental", HFILL }},
{ &hf_ndmp_butype_attr_recover_incremental, {
"Recover incremental", "ndmp.butype.attr.recover_incremental", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_recover_incremental), 0x00000040, "recover_incremental", HFILL }},
{ &hf_ndmp_butype_attr_backup_utf8, {
"Backup UTF8", "ndmp.butype.attr.backup_utf8", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_backup_utf8), 0x00000080, "backup_utf8", HFILL }},
{ &hf_ndmp_butype_attr_recover_utf8, {
"Recover UTF8", "ndmp.butype.attr.recover_utf8", FT_BOOLEAN, 32,
TFS(&tfs_butype_attr_recover_utf8), 0x00000100, "recover_utf8", HFILL }},
{ &hf_ndmp_butype_env_name, {
"Name", "ndmp.butype.env.name", FT_STRING, BASE_NONE,
NULL, 0, "Name for this env-variable", HFILL }},
{ &hf_ndmp_butype_env_value, {
"Value", "ndmp.butype.env.value", FT_STRING, BASE_NONE,
NULL, 0, "Value for this env-variable", HFILL }},
{ &hf_ndmp_tcp_env_name, {
"Name", "ndmp.tcp.env.name", FT_STRING, BASE_NONE,
NULL, 0, "Name for this env-variable", HFILL }},
{ &hf_ndmp_tcp_env_value, {
"Value", "ndmp.tcp.env.value", FT_STRING, BASE_NONE,
NULL, 0, "Value for this env-variable", HFILL }},
{ &hf_ndmp_fs_info, {
"FS Info", "ndmp.fs.info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_fs_invalid_total_size, {
"Total size invalid", "ndmp.fs.invalid.total_size", FT_BOOLEAN, 32,
TFS(&tfs_fs_invalid_total_size), 0x00000001, "If total size is invalid", HFILL }},
{ &hf_ndmp_fs_invalid_used_size, {
"Used size invalid", "ndmp.fs.invalid.used_size", FT_BOOLEAN, 32,
TFS(&tfs_fs_invalid_used_size), 0x00000002, "If used size is invalid", HFILL }},
{ &hf_ndmp_fs_invalid_avail_size, {
"Available size invalid", "ndmp.fs.invalid.avail_size", FT_BOOLEAN, 32,
TFS(&tfs_fs_invalid_avail_size), 0x00000004, "If available size is invalid", HFILL }},
{ &hf_ndmp_fs_invalid_total_inodes, {
"Total number of inodes invalid", "ndmp.fs.invalid.total_inodes", FT_BOOLEAN, 32,
TFS(&tfs_fs_invalid_total_inodes), 0x00000008, "If total number of inodes is invalid", HFILL }},
{ &hf_ndmp_fs_invalid_used_inodes, {
"Used number of inodes is invalid", "ndmp.fs.invalid.used_inodes", FT_BOOLEAN, 32,
TFS(&tfs_fs_invalid_used_inodes), 0x00000010, "If used number of inodes is invalid", HFILL }},
{ &hf_ndmp_fs_fs_type, {
"Type", "ndmp.fs.type", FT_STRING, BASE_NONE,
NULL, 0, "Type of FS", HFILL }},
{ &hf_ndmp_fs_logical_device, {
"Logical Device", "ndmp.fs.logical_device", FT_STRING, BASE_NONE,
NULL, 0, "Name of logical device", HFILL }},
{ &hf_ndmp_fs_physical_device, {
"Physical Device", "ndmp.fs.physical_device", FT_STRING, BASE_NONE,
NULL, 0, "Name of physical device", HFILL }},
{ &hf_ndmp_fs_total_size, {
"Total Size", "ndmp.fs.total_size", FT_UINT64, BASE_DEC,
NULL, 0, "Total size of FS", HFILL }},
{ &hf_ndmp_fs_used_size, {
"Used Size", "ndmp.fs.used_size", FT_UINT64, BASE_DEC,
NULL, 0, "Total used size of FS", HFILL }},
{ &hf_ndmp_fs_avail_size, {
"Avail Size", "ndmp.fs.avail_size", FT_UINT64, BASE_DEC,
NULL, 0, "Total available size on FS", HFILL }},
{ &hf_ndmp_fs_total_inodes, {
"Total Inodes", "ndmp.fs.total_inodes", FT_UINT64, BASE_DEC,
NULL, 0, "Total number of inodes on FS", HFILL }},
{ &hf_ndmp_fs_used_inodes, {
"Used Inodes", "ndmp.fs.used_inodes", FT_UINT64, BASE_DEC,
NULL, 0, "Number of used inodes on FS", HFILL }},
{ &hf_ndmp_fs_env, {
"Env variables", "ndmp.fs.env", FT_NONE, BASE_NONE,
NULL, 0, "Environment variables for FS", HFILL }},
{ &hf_ndmp_fs_env_name, {
"Name", "ndmp.fs.env.name", FT_STRING, BASE_NONE,
NULL, 0, "Name for this env-variable", HFILL }},
{ &hf_ndmp_fs_env_value, {
"Value", "ndmp.fs.env.value", FT_STRING, BASE_NONE,
NULL, 0, "Value for this env-variable", HFILL }},
{ &hf_ndmp_fs_status, {
"Status", "ndmp.fs.status", FT_STRING, BASE_NONE,
NULL, 0, "Status for this FS", HFILL }},
{ &hf_ndmp_tape_info, {
"Tape Info", "ndmp.tape.info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_model, {
"Model", "ndmp.tape.model", FT_STRING, BASE_NONE,
NULL, 0, "Model of the TAPE drive", HFILL }},
{ &hf_ndmp_tape_dev_cap, {
"Device Capability", "ndmp.tape.dev_cap", FT_NONE, BASE_NONE,
NULL, 0, "Tape Device Capability", HFILL }},
{ &hf_ndmp_tape_device, {
"Device", "ndmp.tape.device", FT_STRING, BASE_NONE,
NULL, 0, "Name of TAPE Device", HFILL }},
{ &hf_ndmp_tape_attr_rewind, {
"Device supports rewind", "ndmp.tape.attr.rewind", FT_BOOLEAN, 32,
TFS(&tfs_tape_attr_rewind), 0x00000001, "If this device supports rewind", HFILL }},
{ &hf_ndmp_tape_attr_unload, {
"Device supports unload", "ndmp.tape.attr.unload", FT_BOOLEAN, 32,
TFS(&tfs_tape_attr_unload), 0x00000002, "If this device supports unload", HFILL }},
{ &hf_ndmp_tape_capability, {
"Tape Capabilities", "ndmp.tape.capability", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_capability_name, {
"Name", "ndmp.tape.cap.name", FT_STRING, BASE_NONE,
NULL, 0, "Name for this env-variable", HFILL }},
{ &hf_ndmp_tape_capability_value, {
"Value", "ndmp.tape.cap.value", FT_STRING, BASE_NONE,
NULL, 0, "Value for this env-variable", HFILL }},
{ &hf_ndmp_scsi_info, {
"SCSI Info", "ndmp.scsi.info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_scsi_model, {
"Model", "ndmp.scsi.model", FT_STRING, BASE_NONE,
NULL, 0, "Model of the SCSI device", HFILL }},
{ &hf_ndmp_server_vendor, {
"Vendor", "ndmp.server.vendor", FT_STRING, BASE_NONE,
NULL, 0, "Name of vendor", HFILL }},
{ &hf_ndmp_server_product, {
"Product", "ndmp.server.product", FT_STRING, BASE_NONE,
NULL, 0, "Name of product", HFILL }},
{ &hf_ndmp_server_revision, {
"Revision", "ndmp.server.revision", FT_STRING, BASE_NONE,
NULL, 0, "Revision of this product", HFILL }},
{ &hf_ndmp_auth_types, {
"Auth types", "ndmp.auth.types", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_scsi_device, {
"Device", "ndmp.scsi.device", FT_STRING, BASE_NONE,
NULL, 0, "Name of SCSI Device", HFILL }},
{ &hf_ndmp_scsi_controller, {
"Controller", "ndmp.scsi.controller", FT_UINT32, BASE_DEC,
NULL, 0, "Target Controller", HFILL }},
{ &hf_ndmp_scsi_id, {
"ID", "ndmp.scsi.id", FT_UINT32, BASE_DEC,
NULL, 0, "Target ID", HFILL }},
{ &hf_ndmp_scsi_lun, {
"LUN", "ndmp.scsi.lun", FT_UINT32, BASE_DEC,
NULL, 0, "Target LUN", HFILL }},
{ &hf_ndmp_execute_cdb_flags_data_in, {
"DATA_IN", "ndmp.execute_cdb.flags.data_in", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_ndmp_execute_cdb_flags_data_out, {
"DATA_OUT", "ndmp.execute_cdb.flags.data_out", FT_BOOLEAN, 32,
NULL, 0x00000002, NULL, HFILL }},
{ &hf_ndmp_execute_cdb_timeout, {
"Timeout", "ndmp.execute_cdb.timeout", FT_UINT32, BASE_DEC,
NULL, 0, "Reselect timeout, in milliseconds", HFILL }},
{ &hf_ndmp_execute_cdb_datain_len, {
"Data in length", "ndmp.execute_cdb.datain_len", FT_UINT32, BASE_DEC,
NULL, 0, "Expected length of data bytes to read", HFILL }},
{ &hf_ndmp_execute_cdb_cdb_len, {
"CDB length", "ndmp.execute_cdb.cdb_len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of CDB", HFILL }},
#if 0
{ &hf_ndmp_execute_cdb_dataout, {
"Data out", "ndmp.execute_cdb.dataout", FT_BYTES, BASE_NONE,
NULL, 0, "Data to be transferred to the SCSI device", HFILL }},
#endif
{ &hf_ndmp_execute_cdb_status, {
"Status", "ndmp.execute_cdb.status", FT_UINT8, BASE_DEC,
VALS(scsi_status_val), 0, "SCSI status", HFILL }},
{ &hf_ndmp_execute_cdb_dataout_len, {
"Data out length", "ndmp.execute_cdb.dataout_len", FT_UINT32, BASE_DEC,
NULL, 0, "Number of bytes transferred to the device", HFILL }},
#if 0
{ &hf_ndmp_execute_cdb_datain, {
"Data in", "ndmp.execute_cdb.datain", FT_BYTES, BASE_NONE,
NULL, 0, "Data transferred from the SCSI device", HFILL }},
#endif
{ &hf_ndmp_execute_cdb_sns_len, {
"Sense data length", "ndmp.execute_cdb.sns_len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of sense data", HFILL }},
{ &hf_ndmp_tape_open_mode, {
"Mode", "ndmp.tape.open_mode", FT_UINT32, BASE_DEC,
VALS(tape_open_mode_vals), 0, "Mode to open tape in", HFILL }},
{ &hf_ndmp_tape_invalid_file_num, {
"Invalid file num", "ndmp.tape.invalid.file_num", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_file_num), 0x00000001, "invalid_file_num", HFILL }},
{ &hf_ndmp_tape_invalid_soft_errors, {
"Soft errors", "ndmp.tape.invalid.soft_errors", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_soft_errors), 0x00000002, "soft_errors", HFILL }},
{ &hf_ndmp_tape_invalid_block_size, {
"Block size", "ndmp.tape.invalid.block_size", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_block_size), 0x00000004, "block_size", HFILL }},
{ &hf_ndmp_tape_invalid_block_no, {
"Block no", "ndmp.tape.invalid.block_no", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_block_no), 0x00000008, "block_no", HFILL }},
{ &hf_ndmp_tape_invalid_total_space, {
"Total space", "ndmp.tape.invalid.total_space", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_total_space), 0x00000010, "total_space", HFILL }},
{ &hf_ndmp_tape_invalid_space_remain, {
"Space remain", "ndmp.tape.invalid.space_remain", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_space_remain), 0x00000020, "space_remain", HFILL }},
{ &hf_ndmp_tape_invalid_partition, {
"Invalid partition", "ndmp.tape.invalid.partition", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_invalid_partition), 0x00000040, "partition", HFILL }},
{ &hf_ndmp_tape_flags_no_rewind, {
"No rewind", "ndmp.tape.flags.no_rewind", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_flags_no_rewind), 0x00000008, "no_rewind", HFILL, }},
{ &hf_ndmp_tape_flags_write_protect, {
"Write protect", "ndmp.tape.flags.write_protect", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_flags_write_protect), 0x00000010, "write_protect", HFILL, }},
{ &hf_ndmp_tape_flags_error, {
"Error", "ndmp.tape.flags.error", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_flags_error), 0x00000020, NULL, HFILL, }},
{ &hf_ndmp_tape_flags_unload, {
"Unload", "ndmp.tape.flags.unload", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_tape_flags_unload), 0x00000040, NULL, HFILL, }},
{ &hf_ndmp_tape_file_num, {
"file_num", "ndmp.tape.status.file_num", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_soft_errors, {
"soft_errors", "ndmp.tape.status.soft_errors", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_block_size, {
"block_size", "ndmp.tape.status.block_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_block_no, {
"block_no", "ndmp.tape.status.block_no", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_total_space, {
"total_space", "ndmp.tape.status.total_space", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_space_remain, {
"space_remain", "ndmp.tape.status.space_remain", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_partition, {
"partition", "ndmp.tape.status.partition", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_tape_mtio_op, {
"Operation", "ndmp.tape.mtio.op", FT_UINT32, BASE_DEC,
VALS(tape_mtio_vals), 0, "MTIO Operation", HFILL }},
{ &hf_ndmp_count, {
"Count", "ndmp.count", FT_UINT32, BASE_DEC,
NULL, 0, "Number of bytes/objects/operations", HFILL }},
{ &hf_ndmp_resid_count, {
"Resid Count", "ndmp.resid_count", FT_UINT32, BASE_DEC,
NULL, 0, "Number of remaining bytes/objects/operations", HFILL }},
{ &hf_ndmp_mover_state, {
"State", "ndmp.mover.state", FT_UINT32, BASE_DEC,
VALS(mover_state_vals), 0, "State of the selected mover", HFILL }},
{ &hf_ndmp_mover_pause, {
"Pause", "ndmp.mover.pause", FT_UINT32, BASE_DEC,
VALS(mover_pause_vals), 0, "Reason why the mover paused", HFILL }},
{ &hf_ndmp_halt, {
"Halt", "ndmp.halt", FT_UINT32, BASE_DEC,
VALS(halt_vals), 0, "Reason why it halted", HFILL }},
{ &hf_ndmp_record_size, {
"Record Size", "ndmp.record.size", FT_UINT32, BASE_DEC,
NULL, 0, "Record size in bytes", HFILL }},
{ &hf_ndmp_record_num, {
"Record Num", "ndmp.record.num", FT_UINT32, BASE_DEC,
NULL, 0, "Number of records", HFILL }},
{ &hf_ndmp_data_written, {
"Data Written", "ndmp.data.written", FT_UINT64, BASE_DEC,
NULL, 0, "Number of data bytes written", HFILL }},
{ &hf_ndmp_seek_position, {
"Seek Position", "ndmp.seek.position", FT_UINT64, BASE_DEC,
NULL, 0, "Current seek position on device", HFILL }},
{ &hf_ndmp_bytes_left_to_read, {
"Bytes left to read", "ndmp.bytes_left_to_read", FT_UINT64, BASE_DEC,
NULL, 0, "Number of bytes left to be read from the device", HFILL }},
{ &hf_ndmp_window_offset, {
"Window Offset", "ndmp.window.offset", FT_UINT64, BASE_DEC,
NULL, 0, "Offset to window in bytes", HFILL }},
{ &hf_ndmp_window_length, {
"Window Length", "ndmp.window.length", FT_UINT64, BASE_DEC,
NULL, 0, "Size of window in bytes", HFILL }},
{ &hf_ndmp_addr_ip, {
"IP Address", "ndmp.addr.ip", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_addr_tcp, {
"TCP Port", "ndmp.addr.tcp_port", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_addr_fcal_loop_id, {
"Loop ID", "ndmp.addr.loop_id", FT_UINT32, BASE_HEX,
NULL, 0, "FCAL Loop ID", HFILL }},
{ &hf_ndmp_addr_ipc, {
"IPC", "ndmp.addr.ipc", FT_BYTES, BASE_NONE,
NULL, 0, "IPC identifier", HFILL }},
{ &hf_ndmp_mover_mode, {
"Mode", "ndmp.mover.mode", FT_UINT32, BASE_HEX,
VALS(mover_mode_vals), 0, "Mover Mode", HFILL }},
{ &hf_ndmp_file_name, {
"File", "ndmp.file", FT_STRING, BASE_NONE,
NULL, 0, "Name of File", HFILL }},
{ &hf_ndmp_nt_file_name, {
"NT File", "ndmp.file", FT_STRING, BASE_NONE,
NULL, 0, "NT Name of File", HFILL }},
{ &hf_ndmp_dos_file_name, {
"DOS File", "ndmp.file", FT_STRING, BASE_NONE,
NULL, 0, "DOS Name of File", HFILL }},
{ &hf_ndmp_log_type, {
"Type", "ndmp.log.type", FT_UINT32, BASE_HEX,
VALS(log_type_vals), 0, "Type of log entry", HFILL }},
{ &hf_ndmp_log_message_id, {
"Message ID", "ndmp.log.message.id", FT_UINT32, BASE_DEC,
NULL, 0, "ID of this log entry", HFILL }},
{ &hf_ndmp_log_message, {
"Message", "ndmp.log.message", FT_STRING, BASE_NONE,
NULL, 0, "Log entry", HFILL }},
{ &hf_ndmp_halt_reason, {
"Reason", "ndmp.halt.reason", FT_STRING, BASE_NONE,
NULL, 0, "Textual reason for why it halted", HFILL }},
{ &hf_ndmp_connected, {
"Connected", "ndmp.connected", FT_UINT32, BASE_DEC,
VALS(connected_vals), 0, "Status of connection", HFILL }},
{ &hf_ndmp_connected_reason, {
"Reason", "ndmp.connected.reason", FT_STRING, BASE_NONE,
NULL, 0, "Textual description of the connection status", HFILL }},
{ &hf_ndmp_auth_id, {
"ID", "ndmp.auth.id", FT_STRING, BASE_NONE,
NULL, 0, "ID of client authenticating", HFILL }},
{ &hf_ndmp_auth_password, {
"Password", "ndmp.auth.password", FT_STRING, BASE_NONE,
NULL, 0, "Password of client authenticating", HFILL }},
{ &hf_ndmp_data, {
"Data", "ndmp.data", FT_BYTES, BASE_NONE,
NULL, 0, "Data written/read", HFILL }},
{ &hf_ndmp_files, {
"Files", "ndmp.files", FT_NONE, BASE_NONE,
NULL, 0, "List of files", HFILL }},
{ &hf_ndmp_file_names, {
"File Names", "ndmp.file.names", FT_NONE, BASE_NONE,
NULL, 0, "List of file names", HFILL }},
{ &hf_ndmp_file_fs_type, {
"File FS Type", "ndmp.file.fs_type", FT_UINT32, BASE_DEC,
VALS(file_fs_type_vals), 0, "Type of file permissions (UNIX or NT)", HFILL }},
{ &hf_ndmp_file_type, {
"File Type", "ndmp.file.type", FT_UINT32, BASE_DEC,
VALS(file_type_vals), 0, "Type of file", HFILL }},
{ &hf_ndmp_file_stats, {
"File Stats", "ndmp.file.stats", FT_NONE, BASE_NONE,
NULL, 0, "List of file stats", HFILL }},
{ &hf_ndmp_file_node, {
"Node", "ndmp.file.node", FT_UINT64, BASE_DEC,
NULL, 0, "Node used for direct access", HFILL }},
{ &hf_ndmp_file_parent, {
"Parent", "ndmp.file.parent", FT_UINT64, BASE_DEC,
NULL, 0, "Parent node(directory) for this node", HFILL }},
{ &hf_ndmp_file_fh_info, {
"FH Info", "ndmp.file.fh_info", FT_UINT64, BASE_DEC,
NULL, 0, "FH Info used for direct access", HFILL }},
{ &hf_ndmp_file_invalid_atime, {
"Invalid atime", "ndmp.file.invalid_atime", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_file_invalid_atime), 0x00000001, "invalid_atime", HFILL, }},
{ &hf_ndmp_file_invalid_ctime, {
"Invalid ctime", "ndmp.file.invalid_ctime", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_file_invalid_ctime), 0x00000002, "invalid_ctime", HFILL, }},
{ &hf_ndmp_file_invalid_group, {
"Invalid group", "ndmp.file.invalid_group", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_file_invalid_group), 0x00000004, "invalid_group", HFILL, }},
{ &hf_ndmp_file_mtime, {
"mtime", "ndmp.file.mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Timestamp for mtime for this file", HFILL }},
{ &hf_ndmp_file_atime, {
"atime", "ndmp.file.atime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Timestamp for atime for this file", HFILL }},
{ &hf_ndmp_file_ctime, {
"ctime", "ndmp.file.ctime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Timestamp for ctime for this file", HFILL }},
{ &hf_ndmp_file_owner, {
"Owner", "ndmp.file.owner", FT_UINT32, BASE_DEC,
NULL, 0, "UID for UNIX, owner for NT", HFILL }},
{ &hf_ndmp_file_group, {
"Group", "ndmp.file.group", FT_UINT32, BASE_DEC,
NULL, 0, "GID for UNIX, NA for NT", HFILL }},
{ &hf_ndmp_file_fattr, {
"Fattr", "ndmp.file.fattr", FT_UINT32, BASE_HEX,
NULL, 0, "Mode for UNIX, fattr for NT", HFILL }},
{ &hf_ndmp_file_size, {
"Size", "ndmp.file.size", FT_UINT64, BASE_DEC,
NULL, 0, "File Size", HFILL }},
{ &hf_ndmp_file_links, {
"Links", "ndmp.file.links", FT_UINT32, BASE_DEC,
NULL, 0, "Number of links to this file", HFILL }},
{ &hf_ndmp_dirs, {
"Dirs", "ndmp.dirs", FT_NONE, BASE_NONE,
NULL, 0, "List of directories", HFILL }},
{ &hf_ndmp_nodes, {
"Nodes", "ndmp.nodes", FT_NONE, BASE_NONE,
NULL, 0, "List of nodes", HFILL }},
{ &hf_ndmp_nlist, {
"Nlist", "ndmp.nlist", FT_NONE, BASE_NONE,
NULL, 0, "List of names", HFILL }},
{ &hf_ndmp_bu_original_path, {
"Original Path", "ndmp.bu.original_path", FT_STRING, BASE_NONE,
NULL, 0, "Original path where backup was created", HFILL }},
{ &hf_ndmp_bu_destination_dir, {
"Destination Dir", "ndmp.bu.destination_dir", FT_STRING, BASE_NONE,
NULL, 0, "Destination directory to restore backup to", HFILL }},
{ &hf_ndmp_bu_new_name, {
"New Name", "ndmp.bu.new_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_bu_other_name, {
"Other Name", "ndmp.bu.other_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_state_invalid_ebr, {
"EstimatedBytesLeft valid", "ndmp.bu.state.invalid_ebr", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_state_invalid_ebr), 0x00000001, "Whether EstimatedBytesLeft is valid or not", HFILL, }},
{ &hf_ndmp_state_invalid_etr, {
"EstimatedTimeLeft valid", "ndmp.bu.state.invalid_etr", FT_BOOLEAN, 32,
TFS(&tfs_ndmp_state_invalid_etr), 0x00000002, "Whether EstimatedTimeLeft is valid or not", HFILL, }},
{ &hf_ndmp_bu_operation, {
"Operation", "ndmp.bu.operation", FT_UINT32, BASE_DEC,
VALS(bu_operation_vals), 0, "BU Operation", HFILL, }},
{ &hf_ndmp_data_state, {
"State", "ndmp.data.state", FT_UINT32, BASE_DEC,
VALS(data_state_vals), 0, "Data state", HFILL, }},
{ &hf_ndmp_data_halted, {
"Halted Reason", "ndmp.data.halted", FT_UINT32, BASE_DEC,
VALS(data_halted_vals), 0, "Data halted reason", HFILL, }},
{ &hf_ndmp_data_bytes_processed, {
"Bytes Processed", "ndmp.data.bytes_processed", FT_UINT64, BASE_DEC,
NULL, 0, "Number of bytes processed", HFILL }},
{ &hf_ndmp_data_est_bytes_remain, {
"Est Bytes Remain", "ndmp.data.est_bytes_remain", FT_UINT64, BASE_DEC,
NULL, 0, "Estimated number of bytes remaining", HFILL }},
{ &hf_ndmp_data_est_time_remain, {
"Est Time Remain", "ndmp.data.est_time_remain", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Estimated time remaining", HFILL }},
{ &hf_ndmp_lastfrag, {
"Last Fragment", "ndmp.lastfrag", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), RPC_RM_LASTFRAG, NULL, HFILL }},
{ &hf_ndmp_fraglen, {
"Fragment Length", "ndmp.fraglen", FT_UINT32, BASE_DEC,
NULL, RPC_RM_FRAGLEN, NULL, HFILL }},
{ &hf_ndmp_class_list, {
"Ext Class List", "ndmp.class_list", FT_NONE, BASE_NONE,
NULL, 0, "List of extension classes", HFILL }},
{ &hf_ndmp_ex_class_id, {
"Class ID", "ndmp.class.id", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_ext_version_list, {
"Ext Version List", "ndmp.ext_version_list", FT_NONE, BASE_NONE,
NULL, 0, "List of extension versions", HFILL }},
{ &hf_ndmp_ext_version, {
"Ext Version", "ndmp.ext_version_list.version", FT_UINT32, BASE_HEX,
NULL, 0, "Extension version", HFILL }},
{ &hf_ndmp_class_version, {
"Class and version", "ndmp.ext_version", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ndmp_ex_class_version, {
"Class Version", "ndmp.class.version", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{&hf_ndmp_fragments, {
"NDMP fragments", "ndmp.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment,
{"NDMP fragment", "ndmp.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment_overlap,
{"NDMP fragment overlap", "ndmp.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment_overlap_conflicts,
{"NDMP fragment overlapping with conflicting data",
"ndmp.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment_multiple_tails,
{"NDMP has multiple tail fragments",
"ndmp.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment_too_long_fragment,
{"NDMP fragment too long", "ndmp.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment_error,
{"NDMP defragmentation error", "ndmp.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_fragment_count,
{"NDMP fragment count", "ndmp.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_reassembled_in,
{"Reassembled in", "ndmp.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_ndmp_reassembled_length,
{"Reassembled NDMP length", "ndmp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
};
static gint *ett[] = {
&ett_ndmp,
&ett_ndmp_fraghdr,
&ett_ndmp_header,
&ett_ndmp_butype_attrs,
&ett_ndmp_fs_invalid,
&ett_ndmp_tape_attr,
&ett_ndmp_execute_cdb_flags,
&ett_ndmp_execute_cdb_cdb,
&ett_ndmp_execute_cdb_sns,
&ett_ndmp_execute_cdb_payload,
&ett_ndmp_tape_invalid,
&ett_ndmp_tape_flags,
&ett_ndmp_addr,
&ett_ndmp_file,
&ett_ndmp_file_name,
&ett_ndmp_file_stats,
&ett_ndmp_file_invalids,
&ett_ndmp_state_invalids,
&ett_ndmp_fragment,
&ett_ndmp_fragments,
};
module_t *ndmp_module;
proto_ndmp = proto_register_protocol("Network Data Management Protocol", "NDMP", "ndmp");
proto_register_field_array(proto_ndmp, hf_ndmp, array_length(hf_ndmp));
proto_register_subtree_array(ett, array_length(ett));
ndmp_module = prefs_register_protocol(proto_ndmp, NULL);
prefs_register_obsolete_preference(ndmp_module, "protocol_version");
prefs_register_enum_preference(ndmp_module,
"default_protocol_version",
"Default protocol version",
"Version of the NDMP protocol to assume if the version can not be automatically detected from the capture",
&ndmp_default_protocol_version,
ndmp_protocol_versions,
FALSE);
prefs_register_bool_preference(ndmp_module, "desegment",
"Reassemble NDMP messages spanning multiple TCP segments",
"Whether the NDMP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ndmp_desegment);
prefs_register_bool_preference(ndmp_module, "defragment",
"Reassemble fragmented NDMP messages spanning multiple packets",
"Whether the dissector should defragment NDMP messages spanning multiple packets.",
&ndmp_defragment);
register_init_routine(ndmp_init);
}
void
proto_reg_handoff_ndmp(void)
{
ndmp_handle = new_create_dissector_handle(dissect_ndmp, proto_ndmp);
dissector_add_uint("tcp.port",TCP_PORT_NDMP, ndmp_handle);
heur_dissector_add("tcp", dissect_ndmp_heur, proto_ndmp);
}
