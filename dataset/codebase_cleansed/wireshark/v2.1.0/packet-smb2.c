static void
smb2stat_init(struct register_srt* srt _U_, GArray* srt_array, srt_gui_init_cb gui_callback, void* gui_data)
{
srt_stat_table *smb2_srt_table;
guint32 i;
smb2_srt_table = init_srt_table("SMB2", NULL, srt_array, SMB2_NUM_PROCEDURES, "Commands", "smb2.cmd", gui_callback, gui_data, NULL);
for (i = 0; i < SMB2_NUM_PROCEDURES; i++)
{
init_srt_table_row(smb2_srt_table, i, val_to_str_ext_const(i, &smb2_cmd_vals_ext, "<unknown>"));
}
}
static int
smb2stat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
guint i = 0;
srt_stat_table *smb2_srt_table;
srt_data_t *data = (srt_data_t *)pss;
const smb2_info_t *si=(const smb2_info_t *)prv;
if(!(si->flags&SMB2_FLAGS_RESPONSE)){
return 0;
}
if(!si->saved){
return 0;
}
if ((si->saved->frame_req == 0) || (si->saved->frame_res != pinfo->num))
return 0;
smb2_srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
add_srt_table_data(smb2_srt_table, si->opcode, &si->saved->req_time, pinfo);
return 1;
}
static gint
smb2_saved_info_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
const smb2_saved_info_t *key1 = (const smb2_saved_info_t *)k1;
const smb2_saved_info_t *key2 = (const smb2_saved_info_t *)k2;
return key1->msg_id == key2->msg_id;
}
static guint
smb2_saved_info_hash_unmatched(gconstpointer k)
{
const smb2_saved_info_t *key = (const smb2_saved_info_t *)k;
guint32 hash;
hash = (guint32) (key->msg_id&0xffffffff);
return hash;
}
static gint
smb2_saved_info_equal_matched(gconstpointer k1, gconstpointer k2)
{
const smb2_saved_info_t *key1 = (const smb2_saved_info_t *)k1;
const smb2_saved_info_t *key2 = (const smb2_saved_info_t *)k2;
return key1->msg_id == key2->msg_id;
}
static guint
smb2_saved_info_hash_matched(gconstpointer k)
{
const smb2_saved_info_t *key = (const smb2_saved_info_t *)k;
guint32 hash;
hash = (guint32) (key->msg_id&0xffffffff);
return hash;
}
static gint
smb2_tid_info_equal(gconstpointer k1, gconstpointer k2)
{
const smb2_tid_info_t *key1 = (const smb2_tid_info_t *)k1;
const smb2_tid_info_t *key2 = (const smb2_tid_info_t *)k2;
return key1->tid == key2->tid;
}
static guint
smb2_tid_info_hash(gconstpointer k)
{
const smb2_tid_info_t *key = (const smb2_tid_info_t *)k;
guint32 hash;
hash = key->tid;
return hash;
}
static gint
smb2_sesid_info_equal(gconstpointer k1, gconstpointer k2)
{
const smb2_sesid_info_t *key1 = (const smb2_sesid_info_t *)k1;
const smb2_sesid_info_t *key2 = (const smb2_sesid_info_t *)k2;
return key1->sesid == key2->sesid;
}
static guint
smb2_sesid_info_hash(gconstpointer k)
{
const smb2_sesid_info_t *key = (const smb2_sesid_info_t *)k;
guint32 hash;
hash = (guint32)( ((key->sesid>>32)&0xffffffff)+((key->sesid)&0xffffffff) );
return hash;
}
static gint
smb2_fid_info_equal(gconstpointer k1, gconstpointer k2)
{
const smb2_fid_info_t *key1 = (const smb2_fid_info_t *)k1;
const smb2_fid_info_t *key2 = (const smb2_fid_info_t *)k2;
if (key1->fid_persistent != key2->fid_persistent) {
return 0;
};
if (key1->fid_volatile != key2->fid_volatile) {
return 0;
};
if (key1->sesid != key2->sesid) {
return 0;
};
if (key1->tid != key2->tid) {
return 0;
};
return 1;
}
static guint
smb2_fid_info_hash(gconstpointer k)
{
const smb2_fid_info_t *key = (const smb2_fid_info_t *)k;
guint32 hash;
if (key->fid_persistent != 0) {
hash = (guint32)( ((key->fid_persistent>>32)&0xffffffff)+((key->fid_persistent)&0xffffffff) );
} else {
hash = (guint32)( ((key->fid_volatile>>32)&0xffffffff)+((key->fid_volatile)&0xffffffff) );
}
return hash;
}
static gboolean
smb2_conv_destroy(wmem_allocator_t *allocator _U_, wmem_cb_event_t event _U_,
void *user_data)
{
smb2_conv_info_t *conv = (smb2_conv_info_t *)user_data;
g_hash_table_destroy(conv->matched);
g_hash_table_destroy(conv->unmatched);
g_hash_table_destroy(conv->fids);
g_hash_table_destroy(conv->sesids);
g_hash_table_destroy(conv->files);
return FALSE;
}
static void smb2_key_derivation(const guint8 *KI _U_, guint32 KI_len _U_,
const guint8 *Label _U_, guint32 Label_len _U_,
const guint8 *Context _U_, guint32 Context_len _U_,
guint8 KO[16])
{
#ifdef HAVE_LIBGCRYPT
gcry_md_hd_t hd = NULL;
guint8 buf[4];
guint8 *digest = NULL;
gcry_md_open(&hd, GCRY_MD_SHA256, GCRY_MD_FLAG_HMAC);
gcry_md_setkey(hd, KI, KI_len);
memset(buf, 0, sizeof(buf));
buf[3] = 1;
gcry_md_write(hd, buf, sizeof(buf));
gcry_md_write(hd, Label, Label_len);
gcry_md_write(hd, buf, 1);
gcry_md_write(hd, Context, Context_len);
buf[3] = 128;
gcry_md_write(hd, buf, sizeof(buf));
digest = gcry_md_read(hd, GCRY_MD_SHA256);
memcpy(KO, digest, 16);
gcry_md_close(hd);
#else
memset(KO, 0, 16);
#endif
}
static gchar *policy_hnd_to_file_id(const e_ctx_hnd *hnd) {
gchar *file_id;
file_id = wmem_strdup_printf(wmem_packet_scope(),
"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
hnd->uuid.data1,
hnd->uuid.data2,
hnd->uuid.data3,
hnd->uuid.data4[0],
hnd->uuid.data4[1],
hnd->uuid.data4[2],
hnd->uuid.data4[3],
hnd->uuid.data4[4],
hnd->uuid.data4[5],
hnd->uuid.data4[6],
hnd->uuid.data4[7]);
return file_id;
}
static guint smb2_eo_files_hash(gconstpointer k) {
return g_str_hash(policy_hnd_to_file_id((const e_ctx_hnd *)k));
}
static gint smb2_eo_files_equal(gconstpointer k1, gconstpointer k2) {
int are_equal;
const e_ctx_hnd *key1 = (const e_ctx_hnd *)k1;
const e_ctx_hnd *key2 = (const e_ctx_hnd *)k2;
are_equal = (key1->uuid.data1==key2->uuid.data1 &&
key1->uuid.data2==key2->uuid.data2 &&
key1->uuid.data3==key2->uuid.data3 &&
key1->uuid.data4[0]==key2->uuid.data4[0] &&
key1->uuid.data4[1]==key2->uuid.data4[1] &&
key1->uuid.data4[2]==key2->uuid.data4[2] &&
key1->uuid.data4[3]==key2->uuid.data4[3] &&
key1->uuid.data4[4]==key2->uuid.data4[4] &&
key1->uuid.data4[5]==key2->uuid.data4[5] &&
key1->uuid.data4[6]==key2->uuid.data4[6] &&
key1->uuid.data4[7]==key2->uuid.data4[7]);
return are_equal;
}
static void
feed_eo_smb2(tvbuff_t * tvb,packet_info *pinfo,smb2_info_t * si, guint16 dataoffset,guint32 length, guint64 file_offset) {
char *fid_name = NULL;
guint32 open_frame = 0, close_frame = 0;
tvbuff_t *data_tvb = NULL;
smb_eo_t *eo_info;
gchar *file_id;
gchar *auxstring;
gchar **aux_string_v;
data_tvb = tvb_new_subset_length(tvb, dataoffset, length);
eo_info = wmem_new(wmem_packet_scope(), smb_eo_t);
eo_info->smbversion=2;
eo_info->cmd=si->opcode;
eo_info->uid=0;
file_id=policy_hnd_to_file_id(&si->saved->policy_hnd);
dcerpc_fetch_polhnd_data(&si->saved->policy_hnd, &fid_name, NULL, &open_frame, &close_frame, pinfo->num);
if (fid_name && g_strcmp0(fid_name,"File: ")!=0) {
auxstring=fid_name;
if (g_str_has_prefix(auxstring, "File: ")) {
aux_string_v = g_strsplit(auxstring, "File: ", -1);
eo_info->filename = wmem_strdup_printf(wmem_packet_scope(), "\\%s",aux_string_v[g_strv_length(aux_string_v)-1]);
g_strfreev(aux_string_v);
} else {
if (g_str_has_prefix(auxstring, "\\")) {
eo_info->filename = wmem_strdup(wmem_packet_scope(), auxstring);
} else {
eo_info->filename = wmem_strdup_printf(wmem_packet_scope(), "\\%s",auxstring);
}
}
} else {
auxstring=wmem_strdup_printf(wmem_packet_scope(), "File_Id_%s", file_id);
eo_info->filename=auxstring;
}
if (eosmb2_take_name_as_fid) {
eo_info->fid = g_str_hash(eo_info->filename);
} else {
eo_info->fid = g_str_hash(file_id);
}
if (si->tree) {
eo_info->tid=si->tree->tid;
if (strlen(si->tree->name)>0 && strlen(si->tree->name)<=256) {
eo_info->hostname = wmem_strdup(wmem_packet_scope(), si->tree->name);
} else {
eo_info->hostname = wmem_strdup_printf(wmem_packet_scope(), "\\\\%s\\TREEID_%i",tree_ip_str(pinfo,si->opcode),si->tree->tid);
}
} else {
eo_info->tid=0;
eo_info->hostname = wmem_strdup_printf(wmem_packet_scope(), "\\\\%s\\TREEID_UNKNOWN",tree_ip_str(pinfo,si->opcode));
}
eo_info->pkt_num = pinfo->num;
if (si->eo_file_info->attr_mask & SMB2_FLAGS_ATTR_DIRECTORY) {
eo_info->fid_type=SMB2_FID_TYPE_DIR;
} else {
if (si->eo_file_info->attr_mask &
(SMB2_FLAGS_ATTR_ARCHIVE | SMB2_FLAGS_ATTR_NORMAL |
SMB2_FLAGS_ATTR_HIDDEN | SMB2_FLAGS_ATTR_READONLY |
SMB2_FLAGS_ATTR_SYSTEM) ) {
eo_info->fid_type=SMB2_FID_TYPE_FILE;
} else {
eo_info->fid_type=SMB2_FID_TYPE_OTHER;
}
}
eo_info->end_of_file=si->eo_file_info->end_of_file;
eo_info->smb_file_offset=file_offset;
eo_info->smb_chunk_len=length;
if (length<si->saved->bytes_moved) {
si->saved->file_offset=si->saved->file_offset+length;
si->saved->bytes_moved=si->saved->bytes_moved-length;
}
eo_info->payload_len = length;
eo_info->payload_data = tvb_get_ptr(data_tvb, 0, length);
tap_queue_packet(smb2_eo_tap, pinfo, eo_info);
}
static int
dissect_smb2_olb_length_offset(tvbuff_t *tvb, int offset, offset_length_buffer_t *olb,
enum offset_length_buffer_offset_size offset_size, int hfindex)
{
olb->hfindex = hfindex;
olb->offset_size = offset_size;
switch (offset_size) {
case OLB_O_UINT16_S_UINT16:
olb->off = tvb_get_letohs(tvb, offset);
olb->off_offset = offset;
offset += 2;
olb->len = tvb_get_letohs(tvb, offset);
olb->len_offset = offset;
offset += 2;
break;
case OLB_O_UINT16_S_UINT32:
olb->off = tvb_get_letohs(tvb, offset);
olb->off_offset = offset;
offset += 2;
olb->len = tvb_get_letohl(tvb, offset);
olb->len_offset = offset;
offset += 4;
break;
case OLB_O_UINT32_S_UINT32:
olb->off = tvb_get_letohl(tvb, offset);
olb->off_offset = offset;
offset += 4;
olb->len = tvb_get_letohl(tvb, offset);
olb->len_offset = offset;
offset += 4;
break;
case OLB_S_UINT32_O_UINT32:
olb->len = tvb_get_letohl(tvb, offset);
olb->len_offset = offset;
offset += 4;
olb->off = tvb_get_letohl(tvb, offset);
olb->off_offset = offset;
offset += 4;
break;
}
return offset;
}
static const char *
dissect_smb2_olb_string(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, offset_length_buffer_t *olb, int type)
{
int len, off;
proto_item *item = NULL;
proto_tree *tree = NULL;
const char *name = NULL;
guint16 bc;
int offset;
offset = olb->off;
len = olb->len;
off = olb->off;
bc = tvb_captured_length_remaining(tvb, offset);
tvb_ensure_bytes_exist(tvb, off, len);
if (((off+len)<off)
|| ((off+len)>(off+tvb_reported_length_remaining(tvb, off)))) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
col_append_str(pinfo->cinfo, COL_INFO, " [Malformed packet]");
return NULL;
}
switch (type) {
case OLB_TYPE_UNICODE_STRING:
name = get_unicode_or_ascii_string(tvb, &off,
TRUE, &len, TRUE, TRUE, &bc);
if (!name) {
name = "";
}
if (parent_tree) {
item = proto_tree_add_string(parent_tree, olb->hfindex, tvb, offset, len, name);
tree = proto_item_add_subtree(item, ett_smb2_olb);
}
break;
case OLB_TYPE_ASCII_STRING:
name = get_unicode_or_ascii_string(tvb, &off,
FALSE, &len, TRUE, TRUE, &bc);
if (!name) {
name = "";
}
if (parent_tree) {
item = proto_tree_add_string(parent_tree, olb->hfindex, tvb, offset, len, name);
tree = proto_item_add_subtree(item, ett_smb2_olb);
}
break;
}
switch (olb->offset_size) {
case OLB_O_UINT16_S_UINT16:
proto_tree_add_item(tree, hf_smb2_olb_offset, tvb, olb->off_offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_olb_length, tvb, olb->len_offset, 2, ENC_LITTLE_ENDIAN);
break;
case OLB_O_UINT16_S_UINT32:
proto_tree_add_item(tree, hf_smb2_olb_offset, tvb, olb->off_offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_olb_length, tvb, olb->len_offset, 4, ENC_LITTLE_ENDIAN);
break;
case OLB_O_UINT32_S_UINT32:
proto_tree_add_item(tree, hf_smb2_olb_offset, tvb, olb->off_offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_olb_length, tvb, olb->len_offset, 4, ENC_LITTLE_ENDIAN);
break;
case OLB_S_UINT32_O_UINT32:
proto_tree_add_item(tree, hf_smb2_olb_length, tvb, olb->len_offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_olb_offset, tvb, olb->off_offset, 4, ENC_LITTLE_ENDIAN);
break;
}
return name;
}
static void
dissect_smb2_olb_buffer(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb,
offset_length_buffer_t *olb, smb2_info_t *si,
void (*dissector)(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si))
{
int len, off;
proto_item *sub_item = NULL;
proto_tree *sub_tree = NULL;
tvbuff_t *sub_tvb = NULL;
int offset;
offset = olb->off;
len = olb->len;
off = olb->off;
tvb_ensure_bytes_exist(tvb, off, len);
if (((off+len)<off)
|| ((off+len)>(off+tvb_reported_length_remaining(tvb, off)))) {
proto_tree_add_expert_format(parent_tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
col_append_str(pinfo->cinfo, COL_INFO, " [Malformed packet]");
return;
}
if (olb->hfindex == -1) {
sub_item = parent_tree;
sub_tree = parent_tree;
} else {
if (parent_tree) {
sub_item = proto_tree_add_item(parent_tree, olb->hfindex, tvb, offset, len, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_smb2_olb);
}
}
switch (olb->offset_size) {
case OLB_O_UINT16_S_UINT16:
proto_tree_add_item(sub_tree, hf_smb2_olb_offset, tvb, olb->off_offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_smb2_olb_length, tvb, olb->len_offset, 2, ENC_LITTLE_ENDIAN);
break;
case OLB_O_UINT16_S_UINT32:
proto_tree_add_item(sub_tree, hf_smb2_olb_offset, tvb, olb->off_offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_smb2_olb_length, tvb, olb->len_offset, 4, ENC_LITTLE_ENDIAN);
break;
case OLB_O_UINT32_S_UINT32:
proto_tree_add_item(sub_tree, hf_smb2_olb_offset, tvb, olb->off_offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_smb2_olb_length, tvb, olb->len_offset, 4, ENC_LITTLE_ENDIAN);
break;
case OLB_S_UINT32_O_UINT32:
proto_tree_add_item(sub_tree, hf_smb2_olb_length, tvb, olb->len_offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_smb2_olb_offset, tvb, olb->off_offset, 4, ENC_LITTLE_ENDIAN);
break;
}
if (off == 0 || len == 0) {
proto_item_append_text(sub_item, ": NO DATA");
return;
}
if (!dissector) {
return;
}
sub_tvb = tvb_new_subset(tvb, off, MIN((int)len, tvb_captured_length_remaining(tvb, off)), len);
dissector(sub_tvb, pinfo, sub_tree, si);
}
static int
dissect_smb2_olb_tvb_max_offset(int offset, offset_length_buffer_t *olb)
{
if (olb->off == 0) {
return offset;
}
return MAX(offset, (int)(olb->off + olb->len));
}
int
dissect_smb2_ioctl_function(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset, guint32 *ioctlfunc)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 ioctl_function;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_ioctl_function, tvb, offset, 4, ENC_LITTLE_ENDIAN);
tree = proto_item_add_subtree(item, ett_smb2_ioctl_function);
}
ioctl_function = tvb_get_letohl(tvb, offset);
if (ioctlfunc)
*ioctlfunc = ioctl_function;
if (ioctl_function) {
const gchar *unknown = "unknown";
const gchar *ioctl_name = val_to_str_ext_const(ioctl_function,
&smb2_ioctl_vals_ext,
unknown);
if (ioctl_name == unknown) {
ioctl_name = NULL;
}
if (ioctl_name != NULL) {
col_append_fstr(
pinfo->cinfo, COL_INFO, " %s", ioctl_name);
}
proto_tree_add_item(tree, hf_smb2_ioctl_function_device, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (ioctl_name == NULL) {
col_append_fstr(
pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext((ioctl_function>>16)&0xffff, &smb2_ioctl_device_vals_ext,
"Unknown (0x%08X)"));
}
proto_tree_add_item(tree, hf_smb2_ioctl_function_access, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_ioctl_function_function, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (ioctl_name == NULL) {
col_append_fstr(
pinfo->cinfo, COL_INFO, " Function:0x%04x",
(ioctl_function>>2)&0x0fff);
}
proto_tree_add_item(tree, hf_smb2_ioctl_function_method, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
offset += 4;
return offset;
}
static int
dissect_smb2_fid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si, int mode)
{
guint8 drep[4] = { 0x10, 0x00, 0x00, 0x00};
static dcerpc_info di;
static dcerpc_call_value call_data;
e_ctx_hnd policy_hnd;
e_ctx_hnd *policy_hnd_hashtablekey;
proto_item *hnd_item = NULL;
char *fid_name;
guint32 open_frame = 0, close_frame = 0;
smb2_eo_file_info_t *eo_file_info;
smb2_fid_info_t sfi_key;
smb2_fid_info_t *sfi = NULL;
sfi_key.fid_persistent = tvb_get_letoh64(tvb, offset);
sfi_key.fid_volatile = tvb_get_letoh64(tvb, offset+8);
sfi_key.sesid = si->sesid;
sfi_key.tid = si->tid;
sfi_key.name = NULL;
di.conformant_run = 0;
di.call_data = &call_data;
switch (mode) {
case FID_MODE_OPEN:
offset = dissect_nt_guid_hnd(tvb, offset, pinfo, tree, &di, drep, hf_smb2_fid, &policy_hnd, &hnd_item, TRUE, FALSE);
if (!pinfo->fd->flags.visited) {
sfi = wmem_new(wmem_file_scope(), smb2_fid_info_t);
*sfi = sfi_key;
if (si->saved && si->saved->extra_info_type == SMB2_EI_FILENAME) {
sfi->name = wmem_strdup(wmem_file_scope(), (char *)si->saved->extra_info);
} else {
sfi->name = wmem_strdup_printf(wmem_file_scope(), "[unknown]");
}
if (si->saved && si->saved->extra_info_type == SMB2_EI_FILENAME) {
fid_name = wmem_strdup_printf(wmem_file_scope(), "File: %s", (char *)si->saved->extra_info);
} else {
fid_name = wmem_strdup_printf(wmem_file_scope(), "File: ");
}
dcerpc_store_polhnd_name(&policy_hnd, pinfo,
fid_name);
g_hash_table_insert(si->conv->fids, sfi, sfi);
si->file = sfi;
if (si->saved) {
si->saved->file = sfi;
si->saved->policy_hnd = policy_hnd;
}
if (si->conv) {
eo_file_info = (smb2_eo_file_info_t *)g_hash_table_lookup(si->conv->files,&policy_hnd);
if (!eo_file_info) {
eo_file_info = wmem_new(wmem_file_scope(), smb2_eo_file_info_t);
policy_hnd_hashtablekey = wmem_new(wmem_file_scope(), e_ctx_hnd);
memcpy(policy_hnd_hashtablekey, &policy_hnd, sizeof(e_ctx_hnd));
eo_file_info->end_of_file=0;
g_hash_table_insert(si->conv->files,policy_hnd_hashtablekey,eo_file_info);
}
si->eo_file_info=eo_file_info;
}
}
break;
case FID_MODE_CLOSE:
offset = dissect_nt_guid_hnd(tvb, offset, pinfo, tree, &di, drep, hf_smb2_fid, &policy_hnd, &hnd_item, FALSE, TRUE);
break;
case FID_MODE_USE:
case FID_MODE_DHNQ:
case FID_MODE_DHNC:
offset = dissect_nt_guid_hnd(tvb, offset, pinfo, tree, &di, drep, hf_smb2_fid, &policy_hnd, &hnd_item, FALSE, FALSE);
break;
}
si->file = (smb2_fid_info_t *)g_hash_table_lookup(si->conv->fids, &sfi_key);
if (si->file) {
if (si->saved) {
si->saved->file = si->file;
}
if (si->file->name) {
if (hnd_item) {
proto_item_append_text(hnd_item, " File: %s", si->file->name);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " File: %s", si->file->name);
}
}
if (dcerpc_fetch_polhnd_data(&policy_hnd, &fid_name, NULL, &open_frame, &close_frame, pinfo->num)) {
if (!si->eo_file_info) {
if (si->saved) { si->saved->policy_hnd = policy_hnd; }
if (si->conv) {
eo_file_info = (smb2_eo_file_info_t *)g_hash_table_lookup(si->conv->files,&policy_hnd);
if (eo_file_info) {
si->eo_file_info=eo_file_info;
} else {
eo_file_info = wmem_new(wmem_file_scope(), smb2_eo_file_info_t);
policy_hnd_hashtablekey = wmem_new(wmem_file_scope(), e_ctx_hnd);
memcpy(policy_hnd_hashtablekey, &policy_hnd, sizeof(e_ctx_hnd));
eo_file_info->end_of_file=0;
g_hash_table_insert(si->conv->files,policy_hnd_hashtablekey,eo_file_info);
}
}
}
}
return offset;
}
static int
dissect_smb2_file_all_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int length;
const char *name = "";
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_all_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_all_info);
}
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
offset = dissect_file_ext_attr(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_nlinks, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_delete_pending, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_smb2_is_directory, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 2;
proto_tree_add_item(tree, hf_smb2_file_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_ea_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb_access_mask(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 16, ENC_NA);
offset += 16;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (length) {
bc = tvb_captured_length_remaining(tvb, offset);
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &length, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, length, name);
}
}
offset += length;
return offset;
}
static int
dissect_smb2_file_allocation_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_allocation_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_allocation_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qsfi_SMB_FILE_ALLOCATION_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_endoffile_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_endoffile_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_endoffile_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qsfi_SMB_FILE_ENDOFFILE_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_alternate_name_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_alternate_name_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_alternate_name_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_NAME_INFO(tvb, pinfo, tree, offset, &bc, &trunc, TRUE);
return offset;
}
static int
dissect_smb2_file_basic_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_basic_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_basic_info);
}
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
offset = dissect_file_ext_attr(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_smb2_file_standard_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_standard_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_standard_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_STANDARD_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_internal_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_internal_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_internal_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_INTERNAL_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_mode_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_mode_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_mode_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qsfi_SMB_FILE_MODE_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_alignment_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_alignment_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_alignment_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_ALIGNMENT_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_position_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_position_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_position_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qsfi_SMB_FILE_POSITION_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_access_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_access_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_access_info);
}
offset = dissect_smb_access_mask(tvb, tree, offset);
return offset;
}
static int
dissect_smb2_file_ea_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_ea_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_ea_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_EA_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_stream_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_stream_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_stream_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_STREAM_INFO(tvb, pinfo, tree, offset, &bc, &trunc, TRUE);
return offset;
}
static int
dissect_smb2_file_pipe_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_pipe_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_pipe_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_sfi_SMB_FILE_PIPE_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_compression_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_compression_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_compression_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_COMPRESSION_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_network_open_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_network_open_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_network_open_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_NETWORK_OPEN_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_attribute_tag_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
gboolean trunc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_attribute_tag_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_attribute_tag_info);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfi_SMB_FILE_ATTRIBUTE_TAG_INFO(tvb, pinfo, tree, offset, &bc, &trunc);
return offset;
}
static int
dissect_smb2_file_disposition_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_disposition_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_disposition_info);
}
proto_tree_add_item(tree, hf_smb2_disposition_delete_on_close, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return offset;
}
static int
dissect_smb2_file_full_ea_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 next_offset;
guint8 ea_name_len;
guint16 ea_data_len;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_full_ea_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_full_ea_info);
}
while (1) {
int length;
const char *name = "";
const char *data = "";
guint16 bc;
int start_offset = offset;
proto_item *ea_item;
proto_tree *ea_tree;
ea_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_ea, &ea_item, "EA:");
next_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ea_tree, hf_smb2_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ea_tree, hf_smb2_ea_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
ea_name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ea_tree, hf_smb2_ea_name_len, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
ea_data_len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(ea_tree, hf_smb2_ea_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
length = ea_name_len;
if (length) {
bc = tvb_captured_length_remaining(tvb, offset);
name = get_unicode_or_ascii_string(tvb, &offset,
FALSE, &length, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(ea_tree, hf_smb2_ea_name, tvb,
offset, length + 1, name);
}
}
offset += ea_name_len + 1;
length = ea_data_len;
if (length) {
bc = tvb_captured_length_remaining(tvb, offset);
data = get_unicode_or_ascii_string(tvb, &offset,
FALSE, &length, TRUE, TRUE, &bc);
proto_tree_add_item(ea_tree, hf_smb2_ea_data, tvb,
offset, length, ENC_NA);
}
offset += ea_data_len;
if (ea_item) {
proto_item_append_text(ea_item, " %s := %s", name, data);
}
proto_item_set_len(ea_item, offset-start_offset);
if (!next_offset) {
break;
}
offset = start_offset+next_offset;
}
return offset;
}
static int
dissect_smb2_file_rename_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int length;
const char *name = "";
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_rename_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_rename_info);
}
proto_tree_add_item(tree, hf_smb2_replace_if, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_smb2_reserved_random, tvb, offset, 7, ENC_NA);
offset += 7;
proto_tree_add_item(tree, hf_smb2_root_directory_mbz, tvb, offset, 8, ENC_NA);
offset += 8;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (length) {
bc = tvb_captured_length_remaining(tvb, offset);
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &length, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, length, name);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " NewName:%s", name);
}
offset += length;
return offset;
}
static int
dissect_smb2_sec_info_00(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_sec_info_00, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_sec_info_00);
}
offset = dissect_nt_sec_desc(tvb, offset, pinfo, tree, NULL, TRUE, tvb_captured_length_remaining(tvb, offset), NULL);
return offset;
}
static int
dissect_smb2_fs_info_05(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_info_05, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_info_05);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfsi_FS_ATTRIBUTE_INFO(tvb, pinfo, tree, offset, &bc, TRUE);
return offset;
}
static int
dissect_smb2_fs_info_06(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_info_06, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_info_06);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_nt_quota(tvb, tree, offset, &bc);
return offset;
}
static int
dissect_smb2_FS_OBJECTID_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_objectid_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_objectid_info);
}
offset = dissect_smb2_FILE_OBJECTID_BUFFER(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_smb2_fs_info_07(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_info_07, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_info_07);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfsi_FS_FULL_SIZE_INFO(tvb, pinfo, tree, offset, &bc);
return offset;
}
static int
dissect_smb2_fs_info_01(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_info_01, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_info_01);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfsi_FS_VOLUME_INFO(tvb, pinfo, tree, offset, &bc, TRUE);
return offset;
}
static int
dissect_smb2_fs_info_03(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_info_03, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_info_03);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfsi_FS_SIZE_INFO(tvb, pinfo, tree, offset, &bc);
return offset;
}
static int
dissect_smb2_fs_info_04(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 bc;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_fs_info_04, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_fs_info_04);
}
bc = tvb_captured_length_remaining(tvb, offset);
offset = dissect_qfsi_FS_DEVICE_INFO(tvb, pinfo, tree, offset, &bc);
return offset;
}
static int
dissect_smb2_oplock(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(parent_tree, hf_smb2_oplock, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_smb2_buffercode(proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 *length)
{
proto_tree *tree;
proto_item *item;
guint16 buffer_code;
buffer_code = tvb_get_letohs(tvb, offset);
item = proto_tree_add_uint(parent_tree, hf_smb2_buffer_code, tvb, offset, 2, buffer_code);
tree = proto_item_add_subtree(item, ett_smb2_buffercode);
proto_tree_add_item(tree, hf_smb2_buffer_code_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_buffer_code_flags_dyn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (length) {
*length = buffer_code;
}
return offset;
}
static int
dissect_smb2_capabilities(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_smb2_cap_dfs,
&hf_smb2_cap_leasing,
&hf_smb2_cap_large_mtu,
&hf_smb2_cap_multi_channel,
&hf_smb2_cap_persistent_handles,
&hf_smb2_cap_directory_leasing,
&hf_smb2_cap_encryption,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_smb2_capabilities, ett_smb2_capabilities, flags, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_smb2_secmode(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_smb2_secmode_flags_sign_enabled,
&hf_smb2_secmode_flags_sign_required,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_smb2_security_mode, ett_smb2_sec_mode, flags, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_smb2_ses_req_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_smb2_ses_req_flags_session_binding,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_smb2_ses_req_flags, ett_smb2_ses_req_flags, flags, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_smb2_ses_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_smb2_ses_flags_guest,
&hf_smb2_ses_flags_null,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hf_smb2_session_flags, ett_smb2_ses_flags, flags, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_smb2_share_flags(proto_tree *tree, tvbuff_t *tvb, int offset)
{
static const int *sf_fields[] = {
&hf_smb2_share_flags_dfs,
&hf_smb2_share_flags_dfs_root,
&hf_smb2_share_flags_restrict_exclusive_opens,
&hf_smb2_share_flags_force_shared_delete,
&hf_smb2_share_flags_allow_namespace_caching,
&hf_smb2_share_flags_access_based_dir_enum,
&hf_smb2_share_flags_force_levelii_oplock,
&hf_smb2_share_flags_enable_hash_v1,
&hf_smb2_share_flags_enable_hash_v2,
&hf_smb2_share_flags_encrypt_data,
NULL
};
proto_item *item;
guint32 cp;
item = proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_share_flags, ett_smb2_share_flags, sf_fields, ENC_LITTLE_ENDIAN);
cp = tvb_get_letohl(tvb, offset);
cp &= 0x00000030;
proto_tree_add_uint_format(item, hf_smb2_share_caching, tvb, offset, 4, cp, "Caching policy: %s (%08x)", val_to_str(cp, share_cache_vals, "Unknown:%u"), cp);
offset += 4;
return offset;
}
static int
dissect_smb2_share_caps(proto_tree *tree, tvbuff_t *tvb, int offset)
{
static const int *sc_fields[] = {
&hf_smb2_share_caps_dfs,
&hf_smb2_share_caps_continuous_availability,
&hf_smb2_share_caps_scaleout,
&hf_smb2_share_caps_cluster,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_share_caps, ett_smb2_share_caps, sc_fields, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static void
dissect_smb2_secblob(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si _U_)
{
if ((tvb_captured_length(tvb)>=7)
&& (!tvb_memeql(tvb, 0, "NTLMSSP", 7))) {
call_dissector(ntlmssp_handle, tvb, pinfo, tree);
} else {
call_dissector(gssapi_handle, tvb, pinfo, tree);
}
}
static int
dissect_smb2_session_setup_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t s_olb;
const ntlmssp_header_t *ntlmssph;
static int ntlmssp_tap_id = 0;
int idx;
if (!ntlmssp_tap_id) {
GString *error_string;
error_string = register_tap_listener("ntlmssp", NULL, NULL,
TL_IS_DISSECTOR_HELPER, NULL, NULL, NULL);
if (!error_string) {
ntlmssp_tap_id = find_tap_id("ntlmssp");
} else {
g_string_free(error_string, TRUE);
}
}
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset = dissect_smb2_ses_req_flags(tree, tvb, offset);
offset = dissect_smb2_secmode(tree, tvb, offset);
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_channel, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_olb_length_offset(tvb, offset, &s_olb, OLB_O_UINT16_S_UINT16, hf_smb2_security_blob);
proto_tree_add_item(tree, hf_smb2_previous_sesid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
dissect_smb2_olb_buffer(pinfo, tree, tvb, &s_olb, si, dissect_smb2_secblob);
offset = dissect_smb2_olb_tvb_max_offset(offset, &s_olb);
if (!pinfo->fd->flags.visited) {
idx = 0;
while ((ntlmssph = (const ntlmssp_header_t *)fetch_tapped_data(ntlmssp_tap_id, idx++)) != NULL) {
if (ntlmssph && ntlmssph->type == NTLMSSP_AUTH) {
smb2_sesid_info_t *sesid;
sesid = wmem_new(wmem_file_scope(), smb2_sesid_info_t);
sesid->sesid = si->sesid;
sesid->acct_name = wmem_strdup(wmem_file_scope(), ntlmssph->acct_name);
sesid->domain_name = wmem_strdup(wmem_file_scope(), ntlmssph->domain_name);
sesid->host_name = wmem_strdup(wmem_file_scope(), ntlmssph->host_name);
if (memcmp(ntlmssph->session_key, zeros, NTLMSSP_KEY_LEN) != 0) {
smb2_key_derivation(ntlmssph->session_key,
NTLMSSP_KEY_LEN,
"SMB2AESCCM", 11,
"ServerIn ", 10,
sesid->server_decryption_key);
smb2_key_derivation(ntlmssph->session_key,
NTLMSSP_KEY_LEN,
"SMB2AESCCM", 11,
"ServerOut", 10,
sesid->client_decryption_key);
} else {
memset(sesid->server_decryption_key, 0,
sizeof(sesid->server_decryption_key));
memset(sesid->client_decryption_key, 0,
sizeof(sesid->client_decryption_key));
}
sesid->server_port = pinfo->destport;
sesid->auth_frame = pinfo->num;
sesid->tids = g_hash_table_new(smb2_tid_info_hash, smb2_tid_info_equal);
g_hash_table_insert(si->conv->sesids, sesid, sesid);
}
}
}
return offset;
}
static int
dissect_smb2_error_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_,
gboolean* continue_dissection)
{
gint byte_count;
guint16 length;
offset = dissect_smb2_buffercode(tree, tvb, offset, &length);
if(length != 9)
{
if(continue_dissection)
*continue_dissection = TRUE;
} else {
if(continue_dissection)
*continue_dissection = FALSE;
proto_tree_add_item(tree, hf_smb2_error_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
byte_count = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_error_byte_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (byte_count == 0) byte_count = 1;
proto_tree_add_item(tree, hf_smb2_error_data, tvb, offset, byte_count, ENC_NA);
offset += byte_count;
}
return offset;
}
static int
dissect_smb2_session_setup_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset_length_buffer_t s_olb;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset = dissect_smb2_ses_flags(tree, tvb, offset);
offset = dissect_smb2_olb_length_offset(tvb, offset, &s_olb, OLB_O_UINT16_S_UINT16, hf_smb2_security_blob);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &s_olb, si, dissect_smb2_secblob);
offset = dissect_smb2_olb_tvb_max_offset(offset, &s_olb);
#ifdef HAVE_KERBEROS
if (!pinfo->fd->flags.visited && si->status == 0) {
enc_key_t *ek;
if (krb_decrypt) {
read_keytab_file_from_preferences();
}
for (ek=enc_key_list;ek;ek=ek->next) {
if (ek->fd_num == (int)pinfo->num) {
break;
}
}
if (ek != NULL) {
smb2_sesid_info_t *sesid;
guint8 session_key[16] = { 0, };
memcpy(session_key, ek->keyvalue, MIN(ek->keylength, 16));
sesid = wmem_new(wmem_file_scope(), smb2_sesid_info_t);
sesid->sesid = si->sesid;
sesid->acct_name = NULL;
sesid->domain_name = NULL;
sesid->host_name = NULL;
smb2_key_derivation(session_key, sizeof(session_key),
"SMB2AESCCM", 11,
"ServerIn ", 10,
sesid->server_decryption_key);
smb2_key_derivation(session_key, sizeof(session_key),
"SMB2AESCCM", 11,
"ServerOut", 10,
sesid->client_decryption_key);
sesid->server_port = pinfo->srcport;
sesid->auth_frame = pinfo->num;
sesid->tids = g_hash_table_new(smb2_tid_info_hash, smb2_tid_info_equal);
g_hash_table_insert(si->conv->sesids, sesid, sesid);
}
}
#endif
return offset;
}
static int
dissect_smb2_tree_connect_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset_length_buffer_t olb;
const char *buf;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset += 2;
offset = dissect_smb2_olb_length_offset(tvb, offset, &olb, OLB_O_UINT16_S_UINT16, hf_smb2_tree);
buf = dissect_smb2_olb_string(pinfo, tree, tvb, &olb, OLB_TYPE_UNICODE_STRING);
offset = dissect_smb2_olb_tvb_max_offset(offset, &olb);
if (!pinfo->fd->flags.visited && si->saved && buf && olb.len) {
si->saved->extra_info_type = SMB2_EI_TREENAME;
si->saved->extra_info = wmem_alloc(wmem_file_scope(), olb.len+1);
g_snprintf((char *)si->saved->extra_info,olb.len+1,"%s",buf);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " Tree: %s", buf);
return offset;
}
static int
dissect_smb2_tree_connect_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
guint16 share_type;
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
share_type = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_share_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
if (!pinfo->fd->flags.visited && si->saved && si->saved->extra_info_type == SMB2_EI_TREENAME && si->session) {
smb2_tid_info_t *tid, tid_key;
tid_key.tid = si->tid;
tid = (smb2_tid_info_t *)g_hash_table_lookup(si->session->tids, &tid_key);
if (tid) {
g_hash_table_remove(si->session->tids, &tid_key);
}
tid = wmem_new(wmem_file_scope(), smb2_tid_info_t);
tid->tid = si->tid;
tid->name = (char *)si->saved->extra_info;
tid->connect_frame = pinfo->num;
tid->share_type = share_type;
g_hash_table_insert(si->session->tids, tid, tid);
si->saved->extra_info_type = SMB2_EI_NONE;
si->saved->extra_info = NULL;
}
offset = dissect_smb2_share_flags(tree, tvb, offset);
offset = dissect_smb2_share_caps(tree, tvb, offset);
offset = dissect_smb_access_mask(tvb, tree, offset);
return offset;
}
static int
dissect_smb2_tree_disconnect_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset += 2;
return offset;
}
static int
dissect_smb2_tree_disconnect_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset += 2;
return offset;
}
static int
dissect_smb2_sessionlogoff_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset += 2;
return offset;
}
static int
dissect_smb2_sessionlogoff_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset += 2;
return offset;
}
static int
dissect_smb2_keepalive_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 2, ENC_NA);
offset += 2;
return offset;
}
static int
dissect_smb2_keepalive_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 2, ENC_NA);
offset += 2;
return offset;
}
static int
dissect_smb2_notify_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
proto_tree *flags_tree = NULL;
proto_item *flags_item = NULL;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
if (tree) {
flags_item = proto_tree_add_item(tree, hf_smb2_notify_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_smb2_notify_flags);
}
proto_tree_add_item(flags_tree, hf_smb2_notify_watch_tree, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb2_output_buffer_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
offset = dissect_nt_notify_completion_filter(tvb, tree, offset);
offset += 4;
return offset;
}
static void
dissect_smb2_notify_data_out(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
proto_tree *tree = NULL;
proto_item *item = NULL;
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 4) {
guint32 start_offset = offset;
guint32 next_offset;
guint32 length;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_notify_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_notify_info);
}
proto_tree_add_item_ret_uint(tree, hf_smb2_notify_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &next_offset);
offset += 4;
proto_tree_add_item(tree, hf_smb2_notify_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN, &length);
offset += 4;
if (length) {
const guchar *name = "";
guint16 bc;
bc = tvb_reported_length_remaining(tvb, offset);
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &length, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename,
tvb, offset, length,
name);
}
offset += length;
}
if (!next_offset) {
break;
}
offset = start_offset+next_offset;
}
}
static int
dissect_smb2_notify_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t olb;
gboolean continue_dissection;
switch (si->status) {
case 0x0000010c:
case 0x00000000:
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset = dissect_smb2_olb_length_offset(tvb, offset, &olb, OLB_O_UINT16_S_UINT32, hf_smb2_notify_out_data);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &olb, si, dissect_smb2_notify_data_out);
offset = dissect_smb2_olb_tvb_max_offset(offset, &olb);
return offset;
}
static int
dissect_smb2_find_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t olb;
const char *buf;
guint8 il;
static const int *f_fields[] = {
&hf_smb2_find_flags_restart_scans,
&hf_smb2_find_flags_single_entry,
&hf_smb2_find_flags_index_specified,
&hf_smb2_find_flags_reopen,
NULL
};
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
il = tvb_get_guint8(tvb, offset);
if (si->saved) {
si->saved->infolevel = il;
}
proto_tree_add_uint(tree, hf_smb2_find_info_level, tvb, offset, 1, il);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_find_flags, ett_smb2_find_flags, f_fields, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_smb2_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
offset = dissect_smb2_olb_length_offset(tvb, offset, &olb, OLB_O_UINT16_S_UINT16, hf_smb2_find_pattern);
proto_tree_add_item(tree, hf_smb2_output_buffer_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
buf = dissect_smb2_olb_string(pinfo, tree, tvb, &olb, OLB_TYPE_UNICODE_STRING);
offset = dissect_smb2_olb_tvb_max_offset(offset, &olb);
if (!pinfo->fd->flags.visited && si->saved && olb.len) {
si->saved->extra_info_type = SMB2_EI_FINDPATTERN;
si->saved->extra_info = g_malloc(olb.len+1);
g_snprintf((char *)si->saved->extra_info,olb.len+1,"%s",buf);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " %s Pattern: %s",
val_to_str(il, smb2_find_info_levels, "(Level:0x%02x)"),
buf);
return offset;
}
static void dissect_smb2_file_directory_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
const char *name = NULL;
guint16 bc;
while (tvb_reported_length_remaining(tvb, offset) > 4) {
int old_offset = offset;
int next_offset;
int file_name_len;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_file_directory_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_file_directory_info);
}
next_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset = dissect_file_ext_attr(tvb, tree, offset);
file_name_len = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (file_name_len) {
bc = file_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &file_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, file_name_len, name);
proto_item_append_text(item, ": %s", name);
}
}
proto_item_set_len(item, offset-old_offset);
if (next_offset == 0) {
return;
}
offset = old_offset+next_offset;
if (offset < old_offset) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
return;
}
}
}
static void dissect_smb2_full_directory_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
const char *name = NULL;
guint16 bc;
while (tvb_reported_length_remaining(tvb, offset) > 4) {
int old_offset = offset;
int next_offset;
int file_name_len;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_full_directory_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_full_directory_info);
}
next_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset = dissect_file_ext_attr(tvb, tree, offset);
file_name_len = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_ea_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (file_name_len) {
bc = file_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &file_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, file_name_len, name);
proto_item_append_text(item, ": %s", name);
}
}
proto_item_set_len(item, offset-old_offset);
if (next_offset == 0) {
return;
}
offset = old_offset+next_offset;
if (offset < old_offset) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
return;
}
}
}
static void dissect_smb2_both_directory_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
const char *name = NULL;
guint16 bc;
while (tvb_reported_length_remaining(tvb, offset) > 4) {
int old_offset = offset;
int next_offset;
int file_name_len;
int short_name_len;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_both_directory_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_both_directory_info);
}
next_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset = dissect_file_ext_attr(tvb, tree, offset);
file_name_len = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_ea_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
short_name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_smb2_short_name_len, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 1;
if (short_name_len) {
bc = short_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &short_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_short_name, tvb,
offset, short_name_len, name);
}
}
offset += 24;
if (file_name_len) {
bc = file_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &file_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, file_name_len, name);
proto_item_append_text(item, ": %s", name);
}
}
proto_item_set_len(item, offset-old_offset);
if (next_offset == 0) {
return;
}
offset = old_offset+next_offset;
if (offset < old_offset) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
return;
}
}
}
static void dissect_smb2_file_name_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
const char *name = NULL;
guint16 bc;
while (tvb_reported_length_remaining(tvb, offset) > 4) {
int old_offset = offset;
int next_offset;
int file_name_len;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_both_directory_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_both_directory_info);
}
next_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
file_name_len = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (file_name_len) {
bc = file_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &file_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, file_name_len, name);
proto_item_append_text(item, ": %s", name);
}
}
proto_item_set_len(item, offset-old_offset);
if (next_offset == 0) {
return;
}
offset = old_offset+next_offset;
if (offset < old_offset) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
return;
}
}
}
static void dissect_smb2_id_both_directory_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
const char *name = NULL;
guint16 bc;
while (tvb_reported_length_remaining(tvb, offset) > 4) {
int old_offset = offset;
int next_offset;
int file_name_len;
int short_name_len;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_id_both_directory_info, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_id_both_directory_info);
}
next_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset = dissect_file_ext_attr(tvb, tree, offset);
file_name_len = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_filename_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_ea_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
short_name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_smb2_short_name_len, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 1;
if (short_name_len) {
bc = short_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &short_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_short_name, tvb,
offset, short_name_len, name);
}
}
offset += 24;
offset += 2;
proto_tree_add_item(tree, hf_smb2_file_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (file_name_len) {
bc = file_name_len;
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &file_name_len, TRUE, TRUE, &bc);
if (name) {
proto_tree_add_string(tree, hf_smb2_filename, tvb,
offset, file_name_len, name);
proto_item_append_text(item, ": %s", name);
}
}
proto_item_set_len(item, offset-old_offset);
if (next_offset == 0) {
return;
}
offset = old_offset+next_offset;
if (offset < old_offset) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_invalid_length, tvb, offset, -1,
"Invalid offset/length. Malformed packet");
return;
}
}
}
static void
dissect_smb2_find_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
smb2_find_dissector_t *dis = smb2_find_dissectors;
while (dis->dissector) {
if (si && si->saved) {
if (dis->level == si->saved->infolevel) {
dis->dissector(tvb, pinfo, tree, si);
return;
}
}
dis++;
}
proto_tree_add_item(tree, hf_smb2_unknown, tvb, 0, tvb_captured_length(tvb), ENC_NA);
}
static int
dissect_smb2_find_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset_length_buffer_t olb;
proto_item *item = NULL;
gboolean continue_dissection;
if (si->saved) {
item = proto_tree_add_uint(tree, hf_smb2_find_info_level, tvb, offset, 0, si->saved->infolevel);
PROTO_ITEM_SET_GENERATED(item);
}
if (!pinfo->fd->flags.visited && si->saved && si->saved->extra_info_type == SMB2_EI_FINDPATTERN) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s Pattern: %s",
val_to_str(si->saved->infolevel, smb2_find_info_levels, "(Level:0x%02x)"),
(const char *)si->saved->extra_info);
g_free(si->saved->extra_info);
si->saved->extra_info_type = SMB2_EI_NONE;
si->saved->extra_info = NULL;
}
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset = dissect_smb2_olb_length_offset(tvb, offset, &olb, OLB_O_UINT16_S_UINT32, hf_smb2_find_info_blob);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &olb, si, dissect_smb2_find_data);
offset = dissect_smb2_olb_tvb_max_offset(offset, &olb);
return offset;
}
static int
dissect_smb2_negotiate_context(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, smb2_info_t *si _U_)
{
int start_offset = offset;
guint16 type;
const gchar *type_str;
guint16 data_length;
proto_item *sub_item;
proto_tree *sub_tree;
tvbuff_t *sub_tvb;
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_smb2_negotiate_context_element, &sub_item, "Negotiate Context");
type = tvb_get_letohl(tvb, offset);
type_str = val_to_str(type, smb2_negotiate_context_types, "Unknown Type: (0x%0x)");
proto_item_append_text(sub_item, ": %s ", type_str);
proto_tree_add_item(sub_tree, hf_smb2_negotiate_context_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
data_length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(sub_tree, hf_smb2_negotiate_context_data_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
sub_tvb = tvb_new_subset_length(tvb, offset, data_length);
offset += data_length;
proto_item_set_len(sub_item, offset - start_offset);
proto_tree_add_item(sub_tree, hf_smb2_unknown, sub_tvb, 0, data_length, ENC_NA);
return offset;
}
static int
dissect_smb2_negotiate_protocol_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
guint16 dc;
guint16 i;
gboolean supports_smb_3_10 = FALSE;
guint32 nco;
guint16 ncc;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
dc = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_dialect_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_smb2_secmode(tree, tvb, offset);
offset++;
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_client_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
nco = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_negotiate_context_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ncc = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_negotiate_context_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
for (i = 0 ; i < dc; i++) {
guint16 d = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_dialect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (d >= 0x310) {
supports_smb_3_10 = TRUE;
}
}
if (!supports_smb_3_10) {
ncc = 0;
}
if (nco != 0) {
guint32 tmp = 0x40 + 36 + dc * 2;
if (nco >= tmp) {
offset += nco - tmp;
} else {
ncc = 0;
}
}
for (i = 0; i < ncc; i++) {
offset = (offset + 7) & ~7;
offset = dissect_smb2_negotiate_context(tvb, pinfo, tree, offset, si);
}
return offset;
}
static int
dissect_smb2_negotiate_protocol_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset_length_buffer_t s_olb;
guint16 d;
guint16 i;
guint32 nco;
guint16 ncc;
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset = dissect_smb2_secmode(tree, tvb, offset);
offset++;
d = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_dialect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ncc = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_negotiate_context_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb2_server_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_max_trans_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_max_read_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_max_write_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_current_time);
offset += 8;
dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_boot_time);
offset += 8;
offset = dissect_smb2_olb_length_offset(tvb, offset, &s_olb, OLB_O_UINT16_S_UINT16, hf_smb2_security_blob);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &s_olb, si, dissect_smb2_secblob);
nco = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_negotiate_context_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_olb_tvb_max_offset(offset, &s_olb);
if (d < 0x310) {
ncc = 0;
}
if (nco != 0) {
guint32 tmp = 0x40 + 64 + s_olb.len;
if (nco >= tmp) {
offset += nco - tmp;
} else {
ncc = 0;
}
}
for (i = 0; i < ncc; i++) {
offset = (offset + 7) & ~7;
offset = dissect_smb2_negotiate_context(tvb, pinfo, tree, offset, si);
}
return offset;
}
static int
dissect_smb2_getinfo_parameters(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si)
{
switch (si->saved->smb2_class) {
case SMB2_CLASS_FILE_INFO:
switch (si->saved->infolevel) {
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 16, ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
case SMB2_CLASS_FS_INFO:
switch (si->saved->infolevel) {
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 16, ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
case SMB2_CLASS_SEC_INFO:
switch (si->saved->infolevel) {
case SMB2_SEC_INFO_00:
dissect_security_information_mask(tvb, tree, offset+8);
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 16, ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 16, ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_smb2_class_infolevel(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree, smb2_info_t *si)
{
guint8 cl, il;
proto_item *item;
int hfindex;
value_string_ext *vsx;
if (si->flags & SMB2_FLAGS_RESPONSE) {
if (!si->saved) {
return offset;
}
cl = si->saved->smb2_class;
il = si->saved->infolevel;
} else {
cl = tvb_get_guint8(tvb, offset);
il = tvb_get_guint8(tvb, offset+1);
if (si->saved) {
si->saved->smb2_class = cl;
si->saved->infolevel = il;
}
}
switch (cl) {
case SMB2_CLASS_FILE_INFO:
hfindex = hf_smb2_infolevel_file_info;
vsx = &smb2_file_info_levels_ext;
break;
case SMB2_CLASS_FS_INFO:
hfindex = hf_smb2_infolevel_fs_info;
vsx = &smb2_fs_info_levels_ext;
break;
case SMB2_CLASS_SEC_INFO:
hfindex = hf_smb2_infolevel_sec_info;
vsx = &smb2_sec_info_levels_ext;
break;
case SMB2_CLASS_POSIX_INFO:
hfindex = hf_smb2_infolevel_posix_info;
vsx = &smb2_posix_info_levels_ext;
break;
default:
hfindex = hf_smb2_infolevel;
vsx = NULL;
}
item = proto_tree_add_uint(tree, hf_smb2_class, tvb, offset, 1, cl);
if (si->flags & SMB2_FLAGS_RESPONSE) {
PROTO_ITEM_SET_GENERATED(item);
}
item = proto_tree_add_uint(tree, hfindex, tvb, offset+1, 1, il);
if (si->flags & SMB2_FLAGS_RESPONSE) {
PROTO_ITEM_SET_GENERATED(item);
}
offset += 2;
if (!(si->flags & SMB2_FLAGS_RESPONSE)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s/%s",
val_to_str(cl, smb2_class_vals, "(Class:0x%02x)"),
val_to_str_ext(il, vsx, "(Level:0x%02x)"));
}
return offset;
}
static int
dissect_smb2_getinfo_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset = dissect_smb2_class_infolevel(pinfo, tvb, offset, tree, si);
proto_tree_add_item(tree, hf_smb2_max_response_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (si->saved) {
dissect_smb2_getinfo_parameters(tvb, pinfo, tree, offset, si);
} else {
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 16, ENC_NA);
}
offset += 16;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
return offset;
}
static int
dissect_smb2_infolevel(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si, guint8 smb2_class, guint8 infolevel)
{
int old_offset = offset;
switch (smb2_class) {
case SMB2_CLASS_FILE_INFO:
switch (infolevel) {
case SMB2_FILE_BASIC_INFO:
offset = dissect_smb2_file_basic_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_STANDARD_INFO:
offset = dissect_smb2_file_standard_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_INTERNAL_INFO:
offset = dissect_smb2_file_internal_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_EA_INFO:
offset = dissect_smb2_file_ea_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ACCESS_INFO:
offset = dissect_smb2_file_access_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_RENAME_INFO:
offset = dissect_smb2_file_rename_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_DISPOSITION_INFO:
offset = dissect_smb2_file_disposition_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_POSITION_INFO:
offset = dissect_smb2_file_position_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_FULL_EA_INFO:
offset = dissect_smb2_file_full_ea_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_MODE_INFO:
offset = dissect_smb2_file_mode_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ALIGNMENT_INFO:
offset = dissect_smb2_file_alignment_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ALL_INFO:
offset = dissect_smb2_file_all_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ALLOCATION_INFO:
offset = dissect_smb2_file_allocation_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ENDOFFILE_INFO:
dissect_smb2_file_endoffile_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ALTERNATE_NAME_INFO:
offset = dissect_smb2_file_alternate_name_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_STREAM_INFO:
offset = dissect_smb2_file_stream_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_PIPE_INFO:
offset = dissect_smb2_file_pipe_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_COMPRESSION_INFO:
offset = dissect_smb2_file_compression_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_NETWORK_OPEN_INFO:
offset = dissect_smb2_file_network_open_info(tvb, pinfo, tree, offset, si);
break;
case SMB2_FILE_ATTRIBUTE_TAG_INFO:
offset = dissect_smb2_file_attribute_tag_info(tvb, pinfo, tree, offset, si);
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
case SMB2_CLASS_FS_INFO:
switch (infolevel) {
case SMB2_FS_INFO_01:
offset = dissect_smb2_fs_info_01(tvb, pinfo, tree, offset, si);
break;
case SMB2_FS_INFO_03:
offset = dissect_smb2_fs_info_03(tvb, pinfo, tree, offset, si);
break;
case SMB2_FS_INFO_04:
offset = dissect_smb2_fs_info_04(tvb, pinfo, tree, offset, si);
break;
case SMB2_FS_INFO_05:
offset = dissect_smb2_fs_info_05(tvb, pinfo, tree, offset, si);
break;
case SMB2_FS_INFO_06:
offset = dissect_smb2_fs_info_06(tvb, pinfo, tree, offset, si);
break;
case SMB2_FS_INFO_07:
offset = dissect_smb2_fs_info_07(tvb, pinfo, tree, offset, si);
break;
case SMB2_FS_OBJECTID_INFO:
offset = dissect_smb2_FS_OBJECTID_INFO(tvb, pinfo, tree, offset, si);
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
case SMB2_CLASS_SEC_INFO:
switch (infolevel) {
case SMB2_SEC_INFO_00:
offset = dissect_smb2_sec_info_00(tvb, pinfo, tree, offset, si);
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
if (si->status == 0x80000005) {
proto_item *item;
item = proto_tree_add_item(tree, hf_smb2_truncated, tvb, old_offset, 0, ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
}
return offset;
}
static void
dissect_smb2_getinfo_response_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
if (si->saved) {
dissect_smb2_infolevel(tvb, pinfo, tree, 0, si, si->saved->smb2_class, si->saved->infolevel);
} else {
proto_tree_add_item(tree, hf_smb2_unknown, tvb, 0, tvb_captured_length(tvb), ENC_NA);
}
}
static int
dissect_smb2_getinfo_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t olb;
gboolean continue_dissection;
dissect_smb2_class_infolevel(pinfo, tvb, offset, tree, si);
switch (si->status) {
case 0x00000000:
case 0x80000005:
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
break;
case 0xc0000023:
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset = dissect_smb2_olb_length_offset(tvb, offset, &olb, OLB_O_UINT16_S_UINT32, -1);
proto_tree_add_item(tree, hf_smb2_required_buffer_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset = dissect_smb2_olb_length_offset(tvb, offset, &olb, OLB_O_UINT16_S_UINT32, -1);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &olb, si, dissect_smb2_getinfo_response_data);
return offset;
}
static int
dissect_smb2_close_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
proto_tree *flags_tree = NULL;
proto_item *flags_item = NULL;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
if (tree) {
flags_item = proto_tree_add_item(tree, hf_smb2_close_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_smb2_close_flags);
}
proto_tree_add_item(flags_tree, hf_smb2_close_pq_attrib, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_CLOSE);
return offset;
}
static int
dissect_smb2_close_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
proto_tree *flags_tree = NULL;
proto_item *flags_item = NULL;
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
if (tree) {
flags_item = proto_tree_add_item(tree, hf_smb2_close_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_smb2_close_flags);
}
proto_tree_add_item(flags_tree, hf_smb2_close_pq_attrib, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset = dissect_file_ext_attr(tvb, tree, offset);
return offset;
}
static int
dissect_smb2_flush_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 6, ENC_NA);
offset += 6;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
return offset;
}
static int
dissect_smb2_flush_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 2, ENC_NA);
offset += 2;
return offset;
}
static int
dissect_smb2_lock_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
guint16 lock_count;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
lock_count = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_lock_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
while (lock_count--) {
proto_item *lock_item = NULL;
proto_tree *lock_tree = NULL;
static const int *lf_fields[] = {
&hf_smb2_lock_flags_shared,
&hf_smb2_lock_flags_exclusive,
&hf_smb2_lock_flags_unlock,
&hf_smb2_lock_flags_fail_immediately,
NULL
};
if (tree) {
lock_item = proto_tree_add_item(tree, hf_smb2_lock_info, tvb, offset, 24, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_smb2_lock_info);
}
proto_tree_add_item(tree, hf_smb2_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(lock_tree, hf_smb2_lock_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_bitmask(lock_tree, tvb, offset, hf_smb2_lock_flags, ett_smb2_lock_flags, lf_fields, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
}
return offset;
}
static int
dissect_smb2_lock_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 2, ENC_NA);
offset += 2;
return offset;
}
static int
dissect_smb2_cancel_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 2, ENC_NA);
offset += 2;
return offset;
}
static const smb2_fid_info_t *
smb2_pipe_get_fid_info(const smb2_info_t *si)
{
smb2_fid_info_t *file = NULL;
if (si == NULL) {
return NULL;
}
if (si->file != NULL) {
file = si->file;
} else if (si->saved != NULL) {
file = si->saved->file;
}
if (file == NULL) {
return NULL;
}
return file;
}
static void
smb2_pipe_set_file_id(packet_info *pinfo, smb2_info_t *si)
{
guint64 persistent;
const smb2_fid_info_t *file = NULL;
file = smb2_pipe_get_fid_info(si);
if (file == NULL) {
return;
}
persistent = GPOINTER_TO_UINT(file);
dcerpc_set_transport_salt(persistent, pinfo);
}
static void
smb2_pipe_reassembly_init(void)
{
reassembly_table_init(&smb2_pipe_reassembly_table,
&addresses_reassembly_table_functions);
}
static int
dissect_file_data_smb2_pipe(tvbuff_t *raw_tvb, packet_info *pinfo, proto_tree *tree _U_, int offset, guint32 datalen, proto_tree *top_tree, void *data)
{
const smb2_info_t *si = (const smb2_info_t *)data;
gboolean result=0;
gboolean save_fragmented;
gint remaining;
guint reported_len;
const smb2_fid_info_t *file = NULL;
guint32 id;
fragment_head *fd_head;
tvbuff_t *tvb;
tvbuff_t *new_tvb;
proto_item *frag_tree_item;
heur_dtbl_entry_t *hdtbl_entry;
file = smb2_pipe_get_fid_info(si);
id = (guint32)(GPOINTER_TO_UINT(file) & G_MAXUINT32);
remaining = tvb_captured_length_remaining(raw_tvb, offset);
tvb = tvb_new_subset(raw_tvb, offset,
MIN((int)datalen, remaining),
datalen);
pinfo->can_desegment = 0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
reported_len = tvb_reported_length(tvb);
if (smb2_pipe_reassembly && tvb_captured_length(tvb) >= reported_len) {
pinfo->can_desegment = 2;
}
save_fragmented = pinfo->fragmented;
if (!pinfo->can_desegment) {
result = dissector_try_heuristic(smb2_pipe_subdissector_list,
tvb, pinfo, top_tree,
&hdtbl_entry, data);
goto clean_up_and_exit;
}
if (!pinfo->fd->flags.visited) {
fd_head = fragment_get(&smb2_pipe_reassembly_table,
pinfo, id, NULL);
if (!fd_head) {
result = dissector_try_heuristic(smb2_pipe_subdissector_list,
tvb, pinfo, top_tree,
&hdtbl_entry, data);
if (!result) {
goto clean_up_and_exit;
}
if (pinfo->desegment_len) {
fragment_add_check(&smb2_pipe_reassembly_table,
tvb, 0, pinfo, id, NULL,
0, reported_len, TRUE);
fragment_set_tot_len(&smb2_pipe_reassembly_table,
pinfo, id, NULL,
pinfo->desegment_len+reported_len);
}
goto clean_up_and_exit;
}
while (fd_head->next) {
fd_head = fd_head->next;
}
fd_head = fragment_add_check(&smb2_pipe_reassembly_table,
tvb, 0, pinfo, id, NULL,
fd_head->offset+fd_head->len,
reported_len, TRUE);
if (fd_head) {
new_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, new_tvb,
"Named Pipe over SMB2");
pinfo->fragmented=FALSE;
tvb = new_tvb;
show_fragment_tree(fd_head, &smb2_pipe_frag_items,
tree, pinfo, tvb, &frag_tree_item);
result = dissector_try_heuristic(smb2_pipe_subdissector_list,
tvb, pinfo, top_tree,
&hdtbl_entry, data);
}
goto clean_up_and_exit;
}
fd_head = fragment_add_check(&smb2_pipe_reassembly_table,
tvb, 0, pinfo, id, NULL, 0, 0, TRUE);
if (!fd_head) {
result = dissector_try_heuristic(smb2_pipe_subdissector_list,
tvb, pinfo, top_tree,
&hdtbl_entry, data);
goto clean_up_and_exit;
}
if (!(fd_head->flags&FD_DEFRAGMENTED)) {
result = dissector_try_heuristic(smb2_pipe_subdissector_list,
tvb, pinfo, top_tree,
&hdtbl_entry, data);
goto clean_up_and_exit;
}
if (pinfo->num != fd_head->reassembled_in) {
proto_item *item;
item = proto_tree_add_uint(top_tree, hf_smb2_pipe_reassembled_in,
tvb, 0, 0, fd_head->reassembled_in);
PROTO_ITEM_SET_GENERATED(item);
goto clean_up_and_exit;
}
new_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, new_tvb,
"Named Pipe over SMB2");
pinfo->fragmented = FALSE;
tvb = new_tvb;
show_fragment_tree(fd_head, &smb2_pipe_frag_items,
top_tree, pinfo, tvb, &frag_tree_item);
result = dissector_try_heuristic(smb2_pipe_subdissector_list,
tvb, pinfo, top_tree,
&hdtbl_entry, data);
clean_up_and_exit:
pinfo->can_desegment=0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
if (!result) {
call_data_dissector(tvb, pinfo, top_tree);
}
pinfo->fragmented = save_fragmented;
offset += datalen;
return offset;
}
static void
dissect_smb2_rdma_v1_blob(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
int len;
int i;
int num;
proto_tree *sub_tree;
proto_item *parent_item;
parent_item = proto_tree_get_parent(parent_tree);
len = tvb_reported_length(tvb);
num = len / 16;
if (parent_item) {
proto_item_append_text(parent_item, ": SMBDirect Buffer Descriptor V1: (%d elements)", num);
}
for (i = 0; i < num; i++) {
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, 8, ett_smb2_rdma_v1, NULL, "RDMA V1");
proto_tree_add_item(sub_tree, hf_smb2_rdma_v1_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_rdma_v1_token, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_rdma_v1_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
}
static int
dissect_smb2_write_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
guint16 dataoffset = 0;
guint32 data_tvb_len;
offset_length_buffer_t c_olb;
guint32 channel;
guint32 length;
guint64 off;
static const int *f_fields[] = {
&hf_smb2_write_flags_write_through,
NULL
};
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
dataoffset=tvb_get_letohs(tvb,offset);
proto_tree_add_item(tree, hf_smb2_data_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_write_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
off = tvb_get_letoh64(tvb, offset);
if (si->saved) si->saved->file_offset=off;
proto_tree_add_item(tree, hf_smb2_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
col_append_fstr(pinfo->cinfo, COL_INFO, " Len:%d Off:%" G_GINT64_MODIFIER "u", length, off);
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
channel = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_channel, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_remaining_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_olb_length_offset(tvb, offset, &c_olb, OLB_O_UINT16_S_UINT16, hf_smb2_channel_info_blob);
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_write_flags, ett_smb2_write_flags, f_fields, ENC_LITTLE_ENDIAN);
offset += 4;
switch (channel) {
case SMB2_CHANNEL_RDMA_V1:
case SMB2_CHANNEL_RDMA_V1_INVALIDATE:
dissect_smb2_olb_buffer(pinfo, tree, tvb, &c_olb, si, dissect_smb2_rdma_v1_blob);
break;
case SMB2_CHANNEL_NONE:
default:
dissect_smb2_olb_buffer(pinfo, tree, tvb, &c_olb, si, NULL);
break;
}
if (length) {
int oldoffset = offset;
smb2_pipe_set_file_id(pinfo, si);
offset = dissect_file_data_smb2_pipe(tvb, pinfo, tree, offset, length, si->top_tree, si);
if (offset != oldoffset) {
return offset;
}
}
proto_tree_add_item(tree, hf_smb2_write_data, tvb, offset, length, ENC_NA);
data_tvb_len=(guint32)tvb_captured_length_remaining(tvb, offset);
offset += MIN(length,(guint32)tvb_captured_length_remaining(tvb, offset));
offset = dissect_smb2_olb_tvb_max_offset(offset, &c_olb);
if (have_tap_listener(smb2_eo_tap) && (data_tvb_len == length)) {
if (si->saved && si->eo_file_info) {
feed_eo_smb2(tvb,pinfo,si,dataoffset,length,off);
}
}
return offset;
}
static int
dissect_smb2_write_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_smb2_write_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_write_remaining, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_channel_info_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb2_channel_info_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_smb2_STORAGE_OFFLOAD_TOKEN(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *sub_tree;
proto_item *sub_item;
guint32 idlen = 0;
guint32 idtype = 0;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 512, ett_smb2_fsctl_odx_token, &sub_item, "Token");
proto_tree_add_item_ret_uint(sub_tree, hf_smb2_fsctl_odx_token_type, tvb, offset, 4, ENC_BIG_ENDIAN, &idtype);
offset += 4;
proto_item_append_text(sub_item, " (IdType 0x%x)", idtype);
proto_tree_add_item(sub_tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item_ret_uint(sub_tree, hf_smb2_fsctl_odx_token_idlen, tvb, offset, 2, ENC_BIG_ENDIAN, &idlen);
offset += 2;
proto_tree_add_bytes_format_value(sub_tree, hf_smb2_fsctl_odx_token_idraw, tvb,
offset, idlen, NULL, "Opaque Data");
offset += 504;
return (offset);
}
static void
dissect_smb2_FSCTL_OFFLOAD_READ(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
int offset,
gboolean in)
{
proto_tree_add_item(tree, hf_smb2_fsctl_odx_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_fsctl_odx_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (in) {
proto_tree_add_item(tree, hf_smb2_fsctl_odx_token_ttl, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_smb2_fsctl_odx_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_fsctl_odx_copy_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_smb2_fsctl_odx_xfer_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
(void) dissect_smb2_STORAGE_OFFLOAD_TOKEN(tvb, pinfo, tree, offset);
}
}
static void
dissect_smb2_FSCTL_OFFLOAD_WRITE(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
int offset,
gboolean in)
{
proto_tree_add_item(tree, hf_smb2_fsctl_odx_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_fsctl_odx_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (in) {
proto_tree_add_item(tree, hf_smb2_fsctl_odx_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_fsctl_odx_copy_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_fsctl_odx_token_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
dissect_smb2_STORAGE_OFFLOAD_TOKEN(tvb, pinfo, tree, offset);
} else {
proto_tree_add_item(tree, hf_smb2_fsctl_odx_xfer_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_smb2_FSCTL_PIPE_TRANSCEIVE(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *top_tree, gboolean data_in _U_, void *data)
{
dissect_file_data_smb2_pipe(tvb, pinfo, tree, offset, tvb_captured_length_remaining(tvb, offset), top_tree, data);
}
static void
dissect_smb2_FSCTL_PIPE_WAIT(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, int offset, proto_tree *top_tree, gboolean data_in _U_)
{
guint8 timeout_specified = tvb_get_guint8(tvb, offset + 12);
guint32 name_len = tvb_get_letohs(tvb, offset + 8);
const gchar *name;
int off = offset + 14;
guint16 bc = tvb_captured_length_remaining(tvb, off);
int len = name_len;
tvb_ensure_bytes_exist(tvb, off, name_len);
name = get_unicode_or_ascii_string(tvb, &off, TRUE, &len, TRUE, TRUE, &bc);
if (name == NULL) {
name = "";
}
col_append_fstr(pinfo->cinfo, COL_INFO, " Pipe: %s", name);
if (top_tree) {
proto_tree_add_string(top_tree, hf_smb2_fsctl_pipe_wait_name, tvb, offset + 14, name_len, name);
if (timeout_specified) {
proto_tree_add_item(top_tree, hf_smb2_fsctl_pipe_wait_timeout, tvb, 0, 8, ENC_LITTLE_ENDIAN);
}
}
}
static int
dissect_smb2_FSCTL_SET_SPARSE(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (!data_in) {
return offset;
}
if (tvb_reported_length_remaining(tvb, offset) >= 1) {
proto_tree_add_item(tree, hf_smb2_fsctl_sparse_flag, tvb, offset, 1, ENC_NA);
offset += 1;
}
return offset;
}
static int
dissect_smb2_FSCTL_SET_ZERO_DATA(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
proto_tree *sub_tree;
proto_item *sub_item;
if (!data_in) {
return offset;
}
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_smb2_fsctl_range_data, &sub_item, "Range");
proto_tree_add_item(sub_tree, hf_smb2_fsctl_range_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_fsctl_range_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
static void
dissect_smb2_FSCTL_QUERY_ALLOCATED_RANGES(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int offset _U_, gboolean data_in)
{
proto_tree *sub_tree;
proto_item *sub_item;
if (data_in) {
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_smb2_fsctl_range_data, &sub_item, "Range");
proto_tree_add_item(sub_tree, hf_smb2_fsctl_range_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_fsctl_range_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
} else {
while (tvb_reported_length_remaining(tvb, offset) >= 16) {
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_smb2_fsctl_range_data, &sub_item, "Range");
proto_tree_add_item(sub_tree, hf_smb2_fsctl_range_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_fsctl_range_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
}
}
static void
dissect_smb2_FSCTL_QUERY_FILE_REGIONS(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int offset _U_, gboolean data_in)
{
if (data_in) {
proto_tree_add_item(tree, hf_smb2_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_qfr_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb2_qfr_usage, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
} else {
guint32 entry_count = 0;
proto_tree_add_item(tree, hf_smb2_qfr_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_qfr_total_region_entry_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_smb2_qfr_region_entry_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &entry_count);
offset += 4;
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
while (entry_count && tvb_reported_length_remaining(tvb, offset)) {
proto_tree *sub_tree;
proto_item *sub_item;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_qfr_entry, &sub_item, "Entry");
proto_tree_add_item(sub_tree, hf_smb2_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_qfr_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_qfr_usage, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
entry_count--;
}
}
}
static void
dissect_smb2_FSCTL_LMR_REQUEST_RESILIENCY(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (!data_in) {
return;
}
proto_tree_add_item(tree, hf_smb2_ioctl_resiliency_timeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_ioctl_resiliency_reserved, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_FSCTL_QUERY_SHARED_VIRTUAL_DISK_SUPPORT(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int offset _U_, gboolean data_in _U_)
{
if (!data_in) {
return;
}
}
static void
dissect_windows_sockaddr_in(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, int len)
{
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *parent_item;
if (len == -1) {
len = 16;
}
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, len, ett_windows_sockaddr, &sub_item, "Socket Address");
parent_item = proto_tree_get_parent(parent_tree);
proto_tree_add_item(sub_tree, hf_windows_sockaddr_family, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_windows_sockaddr_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_windows_sockaddr_in_addr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item, ", IPv4: %s", tvb_ip_to_str(tvb, offset));
proto_item_append_text(parent_item, ", IPv4: %s", tvb_ip_to_str(tvb, offset));
}
static void
dissect_windows_sockaddr_in6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset, int len)
{
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *parent_item;
if (len == -1) {
len = 16;
}
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, len, ett_windows_sockaddr, &sub_item, "Socket Address");
parent_item = proto_tree_get_parent(parent_tree);
proto_tree_add_item(sub_tree, hf_windows_sockaddr_family, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_windows_sockaddr_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_windows_sockaddr_in6_flowinfo, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_windows_sockaddr_in6_addr, tvb, offset, 16, ENC_NA);
proto_item_append_text(sub_item, ", IPv6: %s", tvb_ip6_to_str(tvb, offset));
proto_item_append_text(parent_item, ", IPv6: %s", tvb_ip6_to_str(tvb, offset));
offset += 16;
proto_tree_add_item(sub_tree, hf_windows_sockaddr_in6_scope_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_windows_sockaddr_storage(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
int len = 128;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *parent_item;
guint16 family;
family = tvb_get_letohs(tvb, offset);
switch (family) {
case WINSOCK_AF_INET:
dissect_windows_sockaddr_in(tvb, pinfo, parent_tree, offset, len);
return;
case WINSOCK_AF_INET6:
dissect_windows_sockaddr_in6(tvb, pinfo, parent_tree, offset, len);
return;
}
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, len, ett_windows_sockaddr, &sub_item, "Socket Address");
parent_item = proto_tree_get_parent(parent_tree);
proto_tree_add_item(sub_tree, hf_windows_sockaddr_family, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(sub_item, ", Family: %d (0x%04x)", family, family);
proto_item_append_text(parent_item, ", Family: %d (0x%04x)", family, family);
}
static void
dissect_smb2_NETWORK_INTERFACE_INFO(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
guint32 next_offset;
int offset = 0;
int len = -1;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *item;
guint32 capabilities;
guint64 link_speed;
gfloat val = 0;
const char *unit = NULL;
static const int * capability_flags[] = {
&hf_smb2_ioctl_network_interface_capability_rdma,
&hf_smb2_ioctl_network_interface_capability_rss,
NULL
};
next_offset = tvb_get_letohl(tvb, offset);
if (next_offset) {
len = next_offset;
}
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, len, ett_smb2_ioctl_network_interface, &sub_item, "Network Interface");
item = proto_tree_get_parent(parent_tree);
proto_tree_add_item(sub_tree, hf_smb2_ioctl_network_interface_next_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_ioctl_network_interface_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
capabilities = tvb_get_letohl(tvb, offset);
proto_tree_add_bitmask(sub_tree, tvb, offset, hf_smb2_ioctl_network_interface_capabilities, ett_smb2_ioctl_network_interface_capabilities, capability_flags, ENC_LITTLE_ENDIAN);
if (capabilities != 0) {
proto_item_append_text(item, "%s%s",
(capabilities & NETWORK_INTERFACE_CAP_RDMA)?", RDMA":"",
(capabilities & NETWORK_INTERFACE_CAP_RSS)?", RSS":"");
proto_item_append_text(sub_item, "%s%s",
(capabilities & NETWORK_INTERFACE_CAP_RDMA)?", RDMA":"",
(capabilities & NETWORK_INTERFACE_CAP_RSS)?", RSS":"");
}
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_ioctl_network_interface_rss_queue_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
link_speed = tvb_get_letoh64(tvb, offset);
item = proto_tree_add_item(sub_tree, hf_smb2_ioctl_network_interface_link_speed, tvb, offset, 8, ENC_LITTLE_ENDIAN);
if (link_speed >= (1000*1000*1000)) {
val = (gfloat)(link_speed / (1000*1000*1000));
unit = "G";
} else if (link_speed >= (1000*1000)) {
val = (gfloat)(link_speed / (1000*1000));
unit = "M";
} else if (link_speed >= (1000)) {
val = (gfloat)(link_speed / (1000));
unit = "K";
} else {
val = (gfloat)(link_speed);
unit = "";
}
proto_item_append_text(item, ", %.1f %sBits/s", val, unit);
proto_item_append_text(sub_item, ", %.1f %sBits/s", val, unit);
offset += 8;
dissect_windows_sockaddr_storage(tvb, pinfo, sub_tree, offset);
if (next_offset) {
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, next_offset);
dissect_smb2_NETWORK_INTERFACE_INFO(next_tvb, pinfo, parent_tree);
}
}
static void
dissect_smb2_FSCTL_QUERY_NETWORK_INTERFACE_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset _U_, gboolean data_in)
{
if (data_in) {
return;
}
dissect_smb2_NETWORK_INTERFACE_INFO(tvb, pinfo, tree);
}
static void
dissect_smb2_FSCTL_VALIDATE_NEGOTIATE_INFO_224(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset _U_, gboolean data_in)
{
if (data_in) {
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_client_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
offset = dissect_smb2_secmode(tree, tvb, offset);
offset++;
proto_tree_add_item(tree, hf_smb2_dialect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_server_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
offset = dissect_smb2_secmode(tree, tvb, offset);
offset++;
proto_tree_add_item(tree, hf_smb2_dialect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
}
static void
dissect_smb2_FSCTL_VALIDATE_NEGOTIATE_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset _U_, gboolean data_in)
{
if (data_in) {
guint16 dc;
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_client_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
offset = dissect_smb2_secmode(tree, tvb, offset);
offset++;
dc = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_dialect_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
for ( ; dc>0; dc--) {
proto_tree_add_item(tree, hf_smb2_dialect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
} else {
offset = dissect_smb2_capabilities(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_server_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
offset = dissect_smb2_secmode(tree, tvb, offset);
offset++;
proto_tree_add_item(tree, hf_smb2_dialect, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
}
static void
dissect_smb2_FSCTL_SRV_ENUMERATE_SNAPSHOTS(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
guint32 num_volumes;
if (data_in) {
return;
}
num_volumes = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_ioctl_shadow_copy_num_volumes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_ioctl_shadow_copy_num_labels, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_ioctl_shadow_copy_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
while (num_volumes--) {
const char *name;
guint16 bc;
int len = 0;
int old_offset = offset;
bc = tvb_captured_length_remaining(tvb, offset);
name = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &len, TRUE, FALSE, &bc);
proto_tree_add_string(tree, hf_smb2_ioctl_shadow_copy_label, tvb, old_offset, len, name);
offset = old_offset+len;
if (!len) {
break;
}
}
}
int
dissect_smb2_FILE_OBJECTID_BUFFER(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, int offset)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_smb2_FILE_OBJECTID_BUFFER, tvb, offset, 64, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2_FILE_OBJECTID_BUFFER);
}
proto_tree_add_item(tree, hf_smb2_object_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_smb2_birth_volume_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_smb2_birth_object_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_smb2_domain_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
return offset;
}
static int
dissect_smb2_FSCTL_CREATE_OR_GET_OBJECT_ID(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (data_in) {
return offset;
}
offset = dissect_smb2_FILE_OBJECTID_BUFFER(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_smb2_FSCTL_GET_COMPRESSION(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (data_in) {
return offset;
}
proto_tree_add_item(tree, hf_smb2_compression_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_smb2_FSCTL_SET_COMPRESSION(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (!data_in) {
return offset;
}
proto_tree_add_item(tree, hf_smb2_compression_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_smb2_FSCTL_SET_INTEGRITY_INFORMATION(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
const int *integrity_flags[] = {
&hf_smb2_integrity_flags_enforcement_off,
NULL
};
if (!data_in) {
return offset;
}
proto_tree_add_item(tree, hf_smb2_checksum_algorithm, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb2_integrity_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_integrity_flags, ett_smb2_integrity_flags, integrity_flags, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_smb2_FSCTL_SET_OBJECT_ID(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (!data_in) {
return offset;
}
offset = dissect_smb2_FILE_OBJECTID_BUFFER(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_smb2_FSCTL_SET_OBJECT_ID_EXTENDED(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (!data_in) {
return offset;
}
proto_tree_add_item(tree, hf_smb2_birth_volume_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_smb2_birth_object_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_smb2_domain_id, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
return offset;
}
static int
dissect_smb2_cchunk_RESUME_KEY(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_bytes_format_value(tree, hf_smb2_cchunk_resume_key, tvb,
offset, 24, NULL, "Opaque Data");
offset += 24;
return (offset);
}
static void
dissect_smb2_FSCTL_SRV_REQUEST_RESUME_KEY(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
if (data_in) {
return;
}
offset = dissect_smb2_cchunk_RESUME_KEY(tvb, pinfo, tree, offset);
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
}
static void
dissect_smb2_FSCTL_SRV_COPYCHUNK(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, gboolean data_in)
{
proto_tree *sub_tree;
proto_item *sub_item;
guint32 chunk_count = 0;
if (!data_in) {
proto_tree_add_item(tree, hf_smb2_cchunk_chunks_written, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_cchunk_bytes_written, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_smb2_cchunk_total_written, tvb, offset+8, 4, ENC_LITTLE_ENDIAN);
return;
}
offset = dissect_smb2_cchunk_RESUME_KEY(tvb, pinfo, tree, offset);
proto_tree_add_item_ret_uint(tree, hf_smb2_cchunk_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &chunk_count);
offset += 4;
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
while (chunk_count && tvb_reported_length_remaining(tvb, offset) >= 24) {
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_smb2_cchunk_entry, &sub_item, "Chunk");
proto_tree_add_item(sub_tree, hf_smb2_cchunk_src_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_cchunk_dst_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_cchunk_xfer_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
chunk_count--;
}
}
void
dissect_smb2_ioctl_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *top_tree, guint32 ioctl_function, gboolean data_in, void *private_data _U_)
{
guint16 dc;
dc = tvb_reported_length(tvb);
switch (ioctl_function) {
case 0x00060194:
if (data_in) {
dissect_get_dfs_request_data(tvb, pinfo, tree, 0, &dc, TRUE);
} else {
dissect_get_dfs_referral_data(tvb, pinfo, tree, 0, &dc, TRUE);
}
break;
case 0x000940CF:
dissect_smb2_FSCTL_QUERY_ALLOCATED_RANGES(tvb, pinfo, tree, 0, data_in);
break;
case 0x00094264:
dissect_smb2_FSCTL_OFFLOAD_READ(tvb, pinfo, tree, 0, data_in);
break;
case 0x00098268:
dissect_smb2_FSCTL_OFFLOAD_WRITE(tvb, pinfo, tree, 0, data_in);
break;
case 0x0011c017:
dissect_smb2_FSCTL_PIPE_TRANSCEIVE(tvb, pinfo, tree, 0, top_tree, data_in, private_data);
break;
case 0x00110018:
dissect_smb2_FSCTL_PIPE_WAIT(tvb, pinfo, tree, 0, top_tree, data_in);
break;
case 0x00140078:
dissect_smb2_FSCTL_SRV_REQUEST_RESUME_KEY(tvb, pinfo, tree, 0, data_in);
break;
case 0x001401D4:
dissect_smb2_FSCTL_LMR_REQUEST_RESILIENCY(tvb, pinfo, tree, 0, data_in);
break;
case 0x001401FC:
dissect_smb2_FSCTL_QUERY_NETWORK_INTERFACE_INFO(tvb, pinfo, tree, 0, data_in);
break;
case 0x00140200:
dissect_smb2_FSCTL_VALIDATE_NEGOTIATE_INFO_224(tvb, pinfo, tree, 0, data_in);
break;
case 0x00140204:
dissect_smb2_FSCTL_VALIDATE_NEGOTIATE_INFO(tvb, pinfo, tree, 0, data_in);
break;
case 0x00144064:
dissect_smb2_FSCTL_SRV_ENUMERATE_SNAPSHOTS(tvb, pinfo, tree, 0, data_in);
break;
case 0x001440F2:
case 0x001480F2:
dissect_smb2_FSCTL_SRV_COPYCHUNK(tvb, pinfo, tree, 0, data_in);
break;
case 0x0009009C:
case 0x000900c0:
dissect_smb2_FSCTL_CREATE_OR_GET_OBJECT_ID(tvb, pinfo, tree, 0, data_in);
break;
case 0x000900c4:
dissect_smb2_FSCTL_SET_SPARSE(tvb, pinfo, tree, 0, data_in);
break;
case 0x00098098:
dissect_smb2_FSCTL_SET_OBJECT_ID(tvb, pinfo, tree, 0, data_in);
break;
case 0x000980BC:
dissect_smb2_FSCTL_SET_OBJECT_ID_EXTENDED(tvb, pinfo, tree, 0, data_in);
break;
case 0x000980C8:
dissect_smb2_FSCTL_SET_ZERO_DATA(tvb, pinfo, tree, 0, data_in);
break;
case 0x0009003C:
dissect_smb2_FSCTL_GET_COMPRESSION(tvb, pinfo, tree, 0, data_in);
break;
case 0x00090300:
if (!data_in)
dissect_smb2_FSCTL_QUERY_SHARED_VIRTUAL_DISK_SUPPORT(tvb, pinfo, tree, 0, dc);
break;
case 0x00090304:
call_dissector_with_data(rsvd_handle, tvb, pinfo, top_tree, &data_in);
break;
case 0x0009C040:
dissect_smb2_FSCTL_SET_COMPRESSION(tvb, pinfo, tree, 0, data_in);
break;
case 0x00090284:
dissect_smb2_FSCTL_QUERY_FILE_REGIONS(tvb, pinfo, tree, 0, data_in);
break;
case 0x0009C280:
dissect_smb2_FSCTL_SET_INTEGRITY_INFORMATION(tvb, pinfo, tree, 0, data_in);
break;
default:
proto_tree_add_item(tree, hf_smb2_unknown, tvb, 0, tvb_captured_length(tvb), ENC_NA);
}
}
static void
dissect_smb2_ioctl_data_in(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
smb2_pipe_set_file_id(pinfo, si);
dissect_smb2_ioctl_data(tvb, pinfo, tree, si->top_tree, si->ioctl_function, TRUE, si);
}
static void
dissect_smb2_ioctl_data_out(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
smb2_pipe_set_file_id(pinfo, si);
dissect_smb2_ioctl_data(tvb, pinfo, tree, si->top_tree, si->ioctl_function, FALSE, si);
}
static int
dissect_smb2_ioctl_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t o_olb;
offset_length_buffer_t i_olb;
proto_tree *flags_tree = NULL;
proto_item *flags_item = NULL;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset += 2;
offset = dissect_smb2_ioctl_function(tvb, pinfo, tree, offset, &si->ioctl_function);
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
offset = dissect_smb2_olb_length_offset(tvb, offset, &i_olb, OLB_O_UINT32_S_UINT32, hf_smb2_ioctl_in_data);
proto_tree_add_item(tree, hf_smb2_max_ioctl_in_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_olb_length_offset(tvb, offset, &o_olb, OLB_O_UINT32_S_UINT32, hf_smb2_ioctl_out_data);
proto_tree_add_item(tree, hf_smb2_max_ioctl_out_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (tree) {
flags_item = proto_tree_add_item(tree, hf_smb2_ioctl_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_smb2_ioctl_flags);
}
proto_tree_add_item(flags_tree, hf_smb2_ioctl_is_fsctl, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
if (i_olb.off>o_olb.off) {
dissect_smb2_olb_buffer(pinfo, tree, tvb, &o_olb, si, dissect_smb2_ioctl_data_out);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &i_olb, si, dissect_smb2_ioctl_data_in);
} else {
dissect_smb2_olb_buffer(pinfo, tree, tvb, &i_olb, si, dissect_smb2_ioctl_data_in);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &o_olb, si, dissect_smb2_ioctl_data_out);
}
offset = dissect_smb2_olb_tvb_max_offset(offset, &o_olb);
offset = dissect_smb2_olb_tvb_max_offset(offset, &i_olb);
return offset;
}
static int
dissect_smb2_ioctl_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t o_olb;
offset_length_buffer_t i_olb;
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
case 0x80000005: break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_smb2_ioctl_function(tvb, pinfo, tree, offset, &si->ioctl_function);
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
offset = dissect_smb2_olb_length_offset(tvb, offset, &i_olb, OLB_O_UINT32_S_UINT32, hf_smb2_ioctl_in_data);
offset = dissect_smb2_olb_length_offset(tvb, offset, &o_olb, OLB_O_UINT32_S_UINT32, hf_smb2_ioctl_out_data);
offset += 4;
offset += 4;
if (i_olb.off>o_olb.off) {
dissect_smb2_olb_buffer(pinfo, tree, tvb, &o_olb, si, dissect_smb2_ioctl_data_out);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &i_olb, si, dissect_smb2_ioctl_data_in);
} else {
dissect_smb2_olb_buffer(pinfo, tree, tvb, &i_olb, si, dissect_smb2_ioctl_data_in);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &o_olb, si, dissect_smb2_ioctl_data_out);
}
offset = dissect_smb2_olb_tvb_max_offset(offset, &i_olb);
offset = dissect_smb2_olb_tvb_max_offset(offset, &o_olb);
return offset;
}
static int
dissect_smb2_read_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t c_olb;
guint32 channel;
guint32 len;
guint64 off;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset += 2;
len = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_read_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
off = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(tree, hf_smb2_file_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
col_append_fstr(pinfo->cinfo, COL_INFO, " Len:%d Off:%" G_GINT64_MODIFIER "u", len, off);
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
proto_tree_add_item(tree, hf_smb2_min_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
channel = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_channel, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_remaining_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_olb_length_offset(tvb, offset, &c_olb, OLB_O_UINT16_S_UINT16, hf_smb2_channel_info_blob);
switch (channel) {
case SMB2_CHANNEL_RDMA_V1:
dissect_smb2_olb_buffer(pinfo, tree, tvb, &c_olb, si, dissect_smb2_rdma_v1_blob);
break;
case SMB2_CHANNEL_NONE:
default:
dissect_smb2_olb_buffer(pinfo, tree, tvb, &c_olb, si, NULL);
break;
}
offset = dissect_smb2_olb_tvb_max_offset(offset, &c_olb);
if (si->saved) {
si->saved->file_offset=off;
si->saved->bytes_moved=len;
}
return offset;
}
static int
dissect_smb2_read_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si _U_)
{
guint16 dataoffset = 0;
guint32 data_tvb_len;
guint32 length;
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
dataoffset=tvb_get_letohl(tvb,offset);
proto_tree_add_item(tree, hf_smb2_data_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_read_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_read_remaining, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
if (length) {
int oldoffset = offset;
smb2_pipe_set_file_id(pinfo, si);
offset = dissect_file_data_smb2_pipe(tvb, pinfo, tree, offset, length, si->top_tree, si);
if (offset != oldoffset) {
return offset;
}
}
proto_tree_add_item(tree, hf_smb2_read_data, tvb, offset, length, ENC_NA);
data_tvb_len=(guint32)tvb_captured_length_remaining(tvb, offset);
offset += MIN(length,data_tvb_len);
if (have_tap_listener(smb2_eo_tap) && (data_tvb_len == length)) {
if (si->saved && si->eo_file_info) {
feed_eo_smb2(tvb,pinfo,si,dataoffset,length,si->saved->file_offset);
}
}
return offset;
}
static void
report_create_context_malformed_buffer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, const char *buffer_desc)
{
proto_tree_add_expert_format(tree, pinfo, &ei_smb2_bad_response, tvb, 0, -1,
"%s SHOULD NOT be generated", buffer_desc);
}
static void
dissect_smb2_ExtA_buffer_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
proto_item *item = NULL;
if (tree) {
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": SMB2_FILE_FULL_EA_INFO");
}
dissect_smb2_file_full_ea_info(tvb, pinfo, tree, 0, si);
}
static void
dissect_smb2_ExtA_buffer_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "ExtA Response");
}
static void
dissect_smb2_SecD_buffer_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
proto_item *item = NULL;
if (tree) {
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": SMB2_SEC_INFO_00");
}
dissect_smb2_sec_info_00(tvb, pinfo, tree, 0, si);
}
static void
dissect_smb2_SecD_buffer_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "SecD Response");
}
static void
dissect_smb2_TWrp_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
proto_item *item = NULL;
if (tree) {
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": Timestamp");
}
dissect_nt_64bit_time(tvb, tree, 0, hf_smb2_twrp_timestamp);
}
static void
dissect_smb2_TWrp_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "TWrp Response");
}
static void
dissect_smb2_QFid_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
proto_item *item = NULL;
if (tree) {
item = proto_tree_get_parent(tree);
}
if (item) {
if (tvb_reported_length(tvb) == 0) {
proto_item_append_text(item, ": NO DATA");
} else {
proto_item_append_text(item, ": QFid request should have no data, malformed packet");
}
}
}
static void
dissect_smb2_QFid_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": QFid INFO");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_QFid_buffer, NULL, "QFid INFO");
proto_tree_add_item(sub_tree, hf_smb2_qfid_fid, tvb, offset, 32, ENC_NA);
}
static void
dissect_smb2_AlSi_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, 0, 8, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_AlSi_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "AlSi Response");
}
static void
dissect_smb2_DHnQ_buffer_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
dissect_smb2_fid(tvb, pinfo, tree, 0, si, FID_MODE_DHNQ);
}
static void
dissect_smb2_DHnQ_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
proto_tree_add_item(tree, hf_smb2_dhnq_buffer_reserved, tvb, 0, 8, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_DHnC_buffer_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
dissect_smb2_fid(tvb, pinfo, tree, 0, si, FID_MODE_DHNC);
}
static void
dissect_smb2_DHnC_buffer_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "DHnC Response");
}
static void
dissect_smb2_DH2Q_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
static const int *dh2x_flags_fields[] = {
&hf_smb2_dh2x_buffer_flags_persistent_handle,
NULL
};
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": DH2Q Request");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_DH2Q_buffer, NULL, "DH2Q Request");
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_timeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(sub_tree, tvb, offset, hf_smb2_dh2x_buffer_flags,
ett_smb2_dh2x_flags, dh2x_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_reserved, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_create_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_DH2Q_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": DH2Q Response");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_DH2Q_buffer, NULL, "DH2Q Response");
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_timeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_DH2C_buffer_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": DH2C Request");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_DH2C_buffer, NULL, "DH2C Request");
dissect_smb2_fid(tvb, pinfo, sub_tree, offset, si, FID_MODE_DHNC);
offset += 16;
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_create_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(sub_tree, hf_smb2_dh2x_buffer_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_DH2C_buffer_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "DH2C Response");
}
static void
dissect_smb2_MxAc_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item = NULL;
if (tree) {
item = proto_tree_get_parent(tree);
}
if (tvb_reported_length(tvb) == 0) {
if (item) {
proto_item_append_text(item, ": NO DATA");
}
return;
}
if (item) {
proto_item_append_text(item, ": Timestamp");
}
dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_mxac_timestamp);
}
static void
dissect_smb2_MxAc_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_tree *sub_tree;
item = proto_tree_get_parent(tree);
if (tvb_reported_length(tvb) == 0) {
proto_item_append_text(item, ": NO DATA");
return;
}
proto_item_append_text(item, ": MxAc INFO");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_MxAc_buffer, NULL, "MxAc INFO");
proto_tree_add_item(sub_tree, hf_smb2_mxac_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dissect_smb_access_mask(tvb, sub_tree, offset);
}
static void
dissect_SMB2_CREATE_LEASE_VX(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree, smb2_info_t *si _U_)
{
int offset = 0;
int len;
proto_tree *sub_tree = NULL;
proto_item *parent_item;
parent_item = proto_tree_get_parent(parent_tree);
len = tvb_reported_length(tvb);
switch (len) {
case 32:
proto_item_append_text(parent_item, ": LEASE_V1");
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_smb2_RqLs_buffer, NULL, "LEASE_V1");
break;
case 52:
proto_item_append_text(parent_item, ": LEASE_V2");
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_smb2_RqLs_buffer, NULL, "LEASE_V2");
break;
default:
report_create_context_malformed_buffer(tvb, pinfo, parent_tree, "RqLs");
break;
}
proto_tree_add_item(sub_tree, hf_smb2_lease_key, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_bitmask(sub_tree, tvb, offset, hf_smb2_lease_state,
ett_smb2_lease_state, lease_state_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(sub_tree, tvb, offset, hf_smb2_lease_flags,
ett_smb2_lease_flags, lease_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_lease_duration, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (len < 52) {
return;
}
proto_tree_add_item(sub_tree, hf_smb2_parent_lease_key, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_item(sub_tree, hf_smb2_lease_epoch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_smb2_lease_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_RqLs_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
dissect_SMB2_CREATE_LEASE_VX(tvb, pinfo, tree, si);
}
static void
dissect_smb2_RqLs_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
dissect_SMB2_CREATE_LEASE_VX(tvb, pinfo, tree, si);
}
static void
dissect_smb2_APP_INSTANCE_buffer_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": CREATE APP INSTANCE ID");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_APP_INSTANCE_buffer, NULL, "APP INSTANCE ID");
proto_tree_add_item(sub_tree, hf_smb2_APP_INSTANCE_buffer_struct_size,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_smb2_APP_INSTANCE_buffer_reserved,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_smb2_APP_INSTANCE_buffer_app_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_APP_INSTANCE_buffer_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "APP INSTANCE Response");
}
static void
dissect_smb2_svhdx_open_device_context_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": SVHDX OPEN DEVICE CONTEXT");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_svhdx_open_device_context, NULL, "SVHDX OPEN DEVICE CONTEXT");
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_version,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_has_initiator_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_reserved,
tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_initiator_id,
tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_flags,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_originator_flags,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_open_request_id,
tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_initiator_host_name_len,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_smb2_svhdx_open_device_context_initiator_host_name,
tvb, offset, 126, ENC_ASCII | ENC_NA);
}
static void
dissect_smb2_svhdx_open_device_context_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
report_create_context_malformed_buffer(tvb, pinfo, tree, "SHVXD OPEN DEVICE CONTEXT Response");
}
static void
dissect_smb2_posix_v1_caps_request(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": POSIX V1 CAPS request");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_posix_v1_request, NULL, "POSIX_V1_REQUEST");
proto_tree_add_item(sub_tree, hf_smb2_posix_v1_version,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_posix_v1_request,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_posix_v1_caps_response(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": POSIX V1 CAPS response");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_posix_v1_response, NULL, "POSIX_V1_RESPONSE");
proto_tree_add_item(sub_tree, hf_smb2_posix_v1_version,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(sub_tree, tvb, offset,
hf_smb2_posix_v1_supported_features,
ett_smb2_posix_v1_supported_features,
posix_flags_fields, ENC_LITTLE_ENDIAN);
}
static void
dissect_smb2_AAPL_buffer_request(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
guint32 command_code;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": AAPL Create Context request");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_aapl_create_context_request, NULL, "AAPL Create Context request");
proto_tree_add_item_ret_uint(sub_tree, hf_smb2_aapl_command_code,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &command_code);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_aapl_reserved,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
switch (command_code) {
case SMB2_AAPL_SERVER_QUERY:
proto_tree_add_bitmask(sub_tree, tvb, offset,
hf_smb2_aapl_server_query_bitmask,
ett_smb2_aapl_server_query_bitmask,
aapl_server_query_bitmap_fields,
ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_bitmask(sub_tree, tvb, offset,
hf_smb2_aapl_server_query_caps,
ett_smb2_aapl_server_query_caps,
aapl_server_query_caps_fields,
ENC_LITTLE_ENDIAN);
break;
case SMB2_AAPL_RESOLVE_ID:
proto_tree_add_item(sub_tree, hf_smb2_file_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
break;
default:
break;
}
}
static void
dissect_smb2_AAPL_buffer_response(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, smb2_info_t *si _U_)
{
int offset = 0;
proto_item *item;
proto_item *sub_tree;
guint32 command_code;
guint64 server_query_bitmask;
item = proto_tree_get_parent(tree);
proto_item_append_text(item, ": AAPL Create Context response");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_aapl_create_context_response, NULL, "AAPL Create Context response");
proto_tree_add_item_ret_uint(sub_tree, hf_smb2_aapl_command_code,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &command_code);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_aapl_reserved,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
switch (command_code) {
case SMB2_AAPL_SERVER_QUERY:
proto_tree_add_bitmask_ret_uint64(sub_tree, tvb, offset,
hf_smb2_aapl_server_query_bitmask,
ett_smb2_aapl_server_query_bitmask,
aapl_server_query_bitmap_fields,
ENC_LITTLE_ENDIAN,
&server_query_bitmask);
offset += 8;
if (server_query_bitmask & SMB2_AAPL_SERVER_CAPS) {
proto_tree_add_bitmask(sub_tree, tvb, offset,
hf_smb2_aapl_server_query_caps,
ett_smb2_aapl_server_query_caps,
aapl_server_query_caps_fields,
ENC_LITTLE_ENDIAN);
offset += 8;
}
if (server_query_bitmask & SMB2_AAPL_VOLUME_CAPS) {
proto_tree_add_bitmask(sub_tree, tvb, offset,
hf_smb2_aapl_server_query_volume_caps,
ett_smb2_aapl_server_query_volume_caps,
aapl_server_query_volume_caps_fields,
ENC_LITTLE_ENDIAN);
offset += 8;
}
if (server_query_bitmask & SMB2_AAPL_MODEL_INFO) {
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_aapl_server_query_model_string,
tvb, offset, 4,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
break;
case SMB2_AAPL_RESOLVE_ID:
proto_tree_add_item(sub_tree, hf_smb2_nt_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_smb2_aapl_server_query_server_path,
tvb, offset, 4,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
break;
default:
break;
}
}
static struct create_context_data_tag_dissectors*
get_create_context_data_tag_dissectors(const char *tag)
{
static struct create_context_data_tag_dissectors INVALID = {
NULL, "<invalid>", { NULL, NULL }
};
size_t i;
for (i = 0; i<array_length(create_context_dissectors_array); i++) {
if (!strcmp(tag, create_context_dissectors_array[i].tag))
return &create_context_dissectors_array[i];
}
return &INVALID;
}
static void
dissect_smb2_create_extra_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, smb2_info_t *si)
{
offset_length_buffer_t tag_olb;
offset_length_buffer_t data_olb;
const char *tag;
guint16 chain_offset;
int offset = 0;
int len = -1;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *parent_item = NULL;
create_context_data_dissectors_t *dissectors = NULL;
create_context_data_dissector_t dissector = NULL;
struct create_context_data_tag_dissectors *tag_dissectors;
chain_offset = tvb_get_letohl(tvb, offset);
if (chain_offset) {
len = chain_offset;
}
sub_tree = proto_tree_add_subtree(parent_tree, tvb, offset, len, ett_smb2_create_chain_element, &sub_item, "Chain Element");
parent_item = proto_tree_get_parent(parent_tree);
proto_tree_add_item(sub_tree, hf_smb2_create_chain_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb2_olb_length_offset(tvb, offset, &tag_olb, OLB_O_UINT16_S_UINT32, hf_smb2_tag);
dissect_smb2_olb_length_offset(tvb, offset, &data_olb, OLB_O_UINT16_S_UINT32, hf_smb2_create_chain_data);
if (tag_olb.len == 16) {
e_guid_t tag_guid;
proto_item *tag_item;
proto_tree *tag_tree;
tvb_get_letohguid(tvb, tag_olb.off, &tag_guid);
tag = guid_to_str(wmem_packet_scope(), &tag_guid);
tag_item = proto_tree_add_string(sub_tree, tag_olb.hfindex, tvb, tag_olb.off, tag_olb.len, tag);
tag_tree = proto_item_add_subtree(tag_item, ett_smb2_olb);
proto_tree_add_item(tag_tree, hf_smb2_olb_offset, tvb, tag_olb.off_offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tag_tree, hf_smb2_olb_length, tvb, tag_olb.len_offset, 2, ENC_LITTLE_ENDIAN);
} else {
tag = dissect_smb2_olb_string(pinfo, sub_tree, tvb, &tag_olb, OLB_TYPE_ASCII_STRING);
}
tag_dissectors = get_create_context_data_tag_dissectors(tag);
proto_item_append_text(parent_item, " %s", tag_dissectors->val);
proto_item_append_text(sub_item, ": %s \"%s\"", tag_dissectors->val, tag);
dissectors = &tag_dissectors->dissectors;
if (dissectors)
dissector = (si->flags & SMB2_FLAGS_RESPONSE) ? dissectors->response : dissectors->request;
dissect_smb2_olb_buffer(pinfo, sub_tree, tvb, &data_olb, si, dissector);
if (chain_offset) {
tvbuff_t *chain_tvb;
chain_tvb = tvb_new_subset_remaining(tvb, chain_offset);
dissect_smb2_create_extra_info(chain_tvb, pinfo, parent_tree, si);
}
}
static int
dissect_smb2_create_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
offset_length_buffer_t f_olb, e_olb;
const char *fname;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset++;
offset = dissect_smb2_oplock(tree, tvb, offset);
proto_tree_add_item(tree, hf_smb2_impersonation_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_create_flags, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset += 8;
offset = dissect_smb_access_mask(tvb, tree, offset);
offset = dissect_file_ext_attr(tvb, tree, offset);
offset = dissect_nt_share_access(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb2_create_disposition, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_create_options(tvb, tree, offset);
offset = dissect_smb2_olb_length_offset(tvb, offset, &f_olb, OLB_O_UINT16_S_UINT16, hf_smb2_filename);
offset = dissect_smb2_olb_length_offset(tvb, offset, &e_olb, OLB_O_UINT32_S_UINT32, hf_smb2_extrainfo);
fname = dissect_smb2_olb_string(pinfo, tree, tvb, &f_olb, OLB_TYPE_UNICODE_STRING);
col_append_fstr(pinfo->cinfo, COL_INFO, " File: %s", fname);
if (!pinfo->fd->flags.visited) {
if (si->saved && si->saved->extra_info_type == SMB2_EI_FILENAME) {
g_free(si->saved->extra_info);
si->saved->extra_info = NULL;
si->saved->extra_info_type = SMB2_EI_NONE;
}
if (si->saved && f_olb.len && f_olb.len<256) {
si->saved->extra_info_type = SMB2_EI_FILENAME;
si->saved->extra_info = (gchar *)g_malloc(f_olb.len+1);
g_snprintf((gchar *)si->saved->extra_info, f_olb.len+1, "%s", fname);
}
}
dissect_smb2_olb_buffer(pinfo, tree, tvb, &e_olb, si, dissect_smb2_create_extra_info);
offset = dissect_smb2_olb_tvb_max_offset(offset, &f_olb);
offset = dissect_smb2_olb_tvb_max_offset(offset, &e_olb);
return offset;
}
static int
dissect_smb2_create_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
guint64 end_of_file;
guint32 attr_mask;
offset_length_buffer_t e_olb;
static const int *create_rep_flags_fields[] = {
&hf_smb2_create_rep_flags_reparse_point,
NULL
};
gboolean continue_dissection;
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
offset = dissect_smb2_oplock(tree, tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_create_rep_flags,
ett_smb2_create_rep_flags, create_rep_flags_fields, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_smb2_create_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_create_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_access_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_write_timestamp);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb2_last_change_timestamp);
proto_tree_add_item(tree, hf_smb2_allocation_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
end_of_file = tvb_get_letoh64(tvb, offset);
if (si->eo_file_info) {
si->eo_file_info->end_of_file = tvb_get_letoh64(tvb, offset);
}
proto_tree_add_item(tree, hf_smb2_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
attr_mask=tvb_get_letohl(tvb, offset);
offset = dissect_file_ext_attr(tvb, tree, offset);
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_OPEN);
if (si->eo_file_info) {
si->eo_file_info->end_of_file = end_of_file;
si->eo_file_info->attr_mask = attr_mask;
}
offset = dissect_smb2_olb_length_offset(tvb, offset, &e_olb, OLB_O_UINT32_S_UINT32, hf_smb2_extrainfo);
dissect_smb2_olb_buffer(pinfo, tree, tvb, &e_olb, si, dissect_smb2_create_extra_info);
offset = dissect_smb2_olb_tvb_max_offset(offset, &e_olb);
if (si->saved && si->saved->extra_info_type == SMB2_EI_FILENAME) {
g_free(si->saved->extra_info);
si->saved->extra_info = NULL;
si->saved->extra_info_type = SMB2_EI_NONE;
}
return offset;
}
static int
dissect_smb2_setinfo_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
guint32 setinfo_size;
guint16 setinfo_offset;
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
offset = dissect_smb2_class_infolevel(pinfo, tvb, offset, tree, si);
setinfo_size = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb2_setinfo_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
setinfo_offset = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb2_setinfo_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb2_unknown, tvb, offset, 6, ENC_NA);
offset += 6;
dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
if (si->saved)
dissect_smb2_infolevel(tvb, pinfo, tree, setinfo_offset, si, si->saved->smb2_class, si->saved->infolevel);
offset = setinfo_offset + setinfo_size;
return offset;
}
static int
dissect_smb2_setinfo_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
gboolean continue_dissection;
dissect_smb2_class_infolevel(pinfo, tvb, offset, tree, si);
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
return offset;
}
static int
dissect_smb2_break_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
guint16 buffer_code;
buffer_code = tvb_get_letohs(tvb, offset);
offset = dissect_smb2_buffercode(tree, tvb, offset, NULL);
if (buffer_code == 24) {
offset = dissect_smb2_oplock(tree, tvb, offset);
offset += 1;
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
return offset;
}
if (buffer_code == 36) {
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset +=2;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_flags,
ett_smb2_lease_flags, lease_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_key, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_state,
ett_smb2_lease_state, lease_state_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_duration, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
return offset;
}
static int
dissect_smb2_break_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si)
{
guint16 buffer_code;
gboolean continue_dissection;
buffer_code = tvb_get_letohs(tvb, offset);
switch (si->status) {
case 0x00000000: offset = dissect_smb2_buffercode(tree, tvb, offset, NULL); break;
default: offset = dissect_smb2_error_response(tvb, pinfo, tree, offset, si, &continue_dissection);
if (!continue_dissection) return offset;
}
if (buffer_code == 24) {
offset = dissect_smb2_oplock(tree, tvb, offset);
offset += 1;
offset += 4;
offset = dissect_smb2_fid(tvb, pinfo, tree, offset, si, FID_MODE_USE);
return offset;
}
if (buffer_code == 44) {
proto_item *item;
proto_tree_add_item(tree, hf_smb2_lease_epoch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_flags,
ett_smb2_lease_flags, lease_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_key, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
item = proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_state,
ett_smb2_lease_state, lease_state_fields, ENC_LITTLE_ENDIAN);
if (item) {
proto_item_prepend_text(item, "Current ");
}
offset += 4;
item = proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_state,
ett_smb2_lease_state, lease_state_fields, ENC_LITTLE_ENDIAN);
if (item) {
proto_item_prepend_text(item, "New ");
}
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_break_reason, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_access_mask_hint, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_share_mask_hint, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
if (buffer_code == 36) {
proto_tree_add_item(tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset +=2;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_flags,
ett_smb2_lease_flags, lease_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_key, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_lease_state,
ett_smb2_lease_state, lease_state_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb2_lease_duration, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
return offset;
}
static const char *decode_smb2_name(guint16 cmd)
{
if (cmd > 0xFF) return "unknown";
return(smb2_cmd_vals[cmd & 0xFF].strptr);
}
static int
dissect_smb2_transform_header(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
smb2_transform_info_t *sti,
tvbuff_t **enc_tvb, tvbuff_t **plain_tvb)
{
proto_item *sesid_item = NULL;
proto_tree *sesid_tree = NULL;
smb2_sesid_info_t sesid_key;
int sesid_offset;
guint8 *plain_data = NULL;
#ifdef HAVE_LIBGCRYPT
guint8 *decryption_key = NULL;
#endif
proto_item *item;
static const int *sf_fields[] = {
&hf_smb2_encryption_aes128_ccm,
NULL
};
*enc_tvb = NULL;
*plain_tvb = NULL;
proto_tree_add_item(tree, hf_smb2_transform_signature, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_smb2_transform_nonce, tvb, offset, 16, ENC_NA);
tvb_memcpy(tvb, sti->nonce, offset, 16);
offset += 16;
proto_tree_add_item(tree, hf_smb2_transform_msg_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
sti->size = tvb_get_letohl(tvb, offset);
offset += 4;
proto_tree_add_item(tree, hf_smb2_transform_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_smb2_transform_enc_alg, ett_smb2_transform_enc_alg, sf_fields, ENC_LITTLE_ENDIAN);
sti->alg = tvb_get_letohs(tvb, offset);
offset += 2;
sesid_offset = offset;
sti->sesid = tvb_get_letoh64(tvb, offset);
sesid_item = proto_tree_add_item(tree, hf_smb2_sesid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
sesid_tree = proto_item_add_subtree(sesid_item, ett_smb2_sesid_tree);
offset += 8;
sesid_key.sesid = sti->sesid;
sti->session = (smb2_sesid_info_t *)g_hash_table_lookup(sti->conv->sesids, &sesid_key);
if (sti->session != NULL && sti->session->auth_frame != (guint32)-1) {
item = proto_tree_add_string(sesid_tree, hf_smb2_acct_name, tvb, sesid_offset, 0, sti->session->acct_name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(sesid_item, " Acct:%s", sti->session->acct_name);
item = proto_tree_add_string(sesid_tree, hf_smb2_domain_name, tvb, sesid_offset, 0, sti->session->domain_name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(sesid_item, " Domain:%s", sti->session->domain_name);
item = proto_tree_add_string(sesid_tree, hf_smb2_host_name, tvb, sesid_offset, 0, sti->session->host_name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(sesid_item, " Host:%s", sti->session->host_name);
item = proto_tree_add_uint(sesid_tree, hf_smb2_auth_frame, tvb, sesid_offset, 0, sti->session->auth_frame);
PROTO_ITEM_SET_GENERATED(item);
}
#ifdef HAVE_LIBGCRYPT
if (sti->session != NULL && sti->alg == ENC_ALG_aes128_ccm) {
if (pinfo->destport == sti->session->server_port) {
decryption_key = sti->session->server_decryption_key;
} else {
decryption_key = sti->session->client_decryption_key;
}
if (memcmp(decryption_key, zeros, 16) == 0) {
decryption_key = NULL;
}
}
if (decryption_key != NULL) {
gcry_cipher_hd_t cipher_hd = NULL;
guint8 A_1[16] = {
3, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1
};
memcpy(&A_1[1], sti->nonce, 15 - 4);
plain_data = (guint8 *)tvb_memdup(pinfo->pool, tvb, offset, sti->size);
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CTR, 0)) {
wmem_free(pinfo->pool, plain_data);
plain_data = NULL;
goto done_decryption;
}
if (gcry_cipher_setkey(cipher_hd, decryption_key, 16)) {
gcry_cipher_close(cipher_hd);
wmem_free(pinfo->pool, plain_data);
plain_data = NULL;
goto done_decryption;
}
if (gcry_cipher_setctr(cipher_hd, A_1, 16)) {
gcry_cipher_close(cipher_hd);
wmem_free(pinfo->pool, plain_data);
plain_data = NULL;
goto done_decryption;
}
if (gcry_cipher_encrypt(cipher_hd, plain_data, sti->size, NULL, 0)) {
gcry_cipher_close(cipher_hd);
wmem_free(pinfo->pool, plain_data);
plain_data = NULL;
goto done_decryption;
}
gcry_cipher_close(cipher_hd);
}
done_decryption:
#endif
*enc_tvb = tvb_new_subset_length(tvb, offset, sti->size);
if (plain_data != NULL) {
*plain_tvb = tvb_new_child_real_data(*enc_tvb, plain_data, sti->size, sti->size);
add_new_data_source(pinfo, *plain_tvb, "Decrypted SMB3");
}
offset += sti->size;
return offset;
}
static int
dissect_smb2_command(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, smb2_info_t *si)
{
int (*cmd_dissector)(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, smb2_info_t *si);
proto_item *cmd_item;
proto_tree *cmd_tree;
int old_offset = offset;
cmd_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_smb2_command, &cmd_item, "%s %s (0x%02x)",
decode_smb2_name(si->opcode),
(si->flags & SMB2_FLAGS_RESPONSE)?"Response":"Request",
si->opcode);
cmd_dissector = (si->flags & SMB2_FLAGS_RESPONSE)?
smb2_dissector[si->opcode&0xff].response:
smb2_dissector[si->opcode&0xff].request;
if (cmd_dissector) {
offset = (*cmd_dissector)(tvb, pinfo, cmd_tree, offset, si);
} else {
proto_tree_add_item(cmd_tree, hf_smb2_unknown, tvb, offset, -1, ENC_NA);
offset = tvb_captured_length(tvb);
}
proto_item_set_len(cmd_item, offset-old_offset);
return offset;
}
static int
dissect_smb2_tid_sesid(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, smb2_info_t *si)
{
proto_item *tid_item = NULL;
proto_tree *tid_tree = NULL;
smb2_tid_info_t tid_key;
int tid_offset = 0;
proto_item *sesid_item = NULL;
proto_tree *sesid_tree = NULL;
smb2_sesid_info_t sesid_key;
int sesid_offset;
proto_item *item;
if (si->flags&SMB2_FLAGS_ASYNC_CMD) {
proto_tree_add_item(tree, hf_smb2_aid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
} else {
proto_tree_add_item(tree, hf_smb2_pid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
tid_offset = offset;
si->tid = tvb_get_letohl(tvb, offset);
tid_item = proto_tree_add_item(tree, hf_smb2_tid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
tid_tree = proto_item_add_subtree(tid_item, ett_smb2_tid_tree);
offset += 4;
}
sesid_offset = offset;
si->sesid = tvb_get_letoh64(tvb, offset);
sesid_item = proto_tree_add_item(tree, hf_smb2_sesid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
sesid_tree = proto_item_add_subtree(sesid_item, ett_smb2_sesid_tree);
offset += 8;
sesid_key.sesid = si->sesid;
si->session = (smb2_sesid_info_t *)g_hash_table_lookup(si->conv->sesids, &sesid_key);
if (!si->session) {
if (si->opcode != 0x03) return offset;
si->session = wmem_new0(wmem_file_scope(), smb2_sesid_info_t);
si->session->sesid = si->sesid;
si->session->auth_frame = (guint32)-1;
si->session->tids = g_hash_table_new(smb2_tid_info_hash, smb2_tid_info_equal);
g_hash_table_insert(si->conv->sesids, si->session, si->session);
return offset;
}
if (si->session->auth_frame != (guint32)-1) {
item = proto_tree_add_string(sesid_tree, hf_smb2_acct_name, tvb, sesid_offset, 0, si->session->acct_name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(sesid_item, " Acct:%s", si->session->acct_name);
item = proto_tree_add_string(sesid_tree, hf_smb2_domain_name, tvb, sesid_offset, 0, si->session->domain_name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(sesid_item, " Domain:%s", si->session->domain_name);
item = proto_tree_add_string(sesid_tree, hf_smb2_host_name, tvb, sesid_offset, 0, si->session->host_name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(sesid_item, " Host:%s", si->session->host_name);
item = proto_tree_add_uint(sesid_tree, hf_smb2_auth_frame, tvb, sesid_offset, 0, si->session->auth_frame);
PROTO_ITEM_SET_GENERATED(item);
}
if (!(si->flags&SMB2_FLAGS_ASYNC_CMD)) {
tid_key.tid = si->tid;
si->tree = (smb2_tid_info_t *)g_hash_table_lookup(si->session->tids, &tid_key);
if (!si->tree) return offset;
item = proto_tree_add_string(tid_tree, hf_smb2_tree, tvb, tid_offset, 4, si->tree->name);
PROTO_ITEM_SET_GENERATED(item);
proto_item_append_text(tid_item, " %s", si->tree->name);
item = proto_tree_add_uint(tid_tree, hf_smb2_share_type, tvb, tid_offset, 0, si->tree->share_type);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(tid_tree, hf_smb2_tcon_frame, tvb, tid_offset, 0, si->tree->connect_frame);
PROTO_ITEM_SET_GENERATED(item);
}
return offset;
}
static int
dissect_smb2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, gboolean first_in_chain)
{
gboolean smb2_transform_header = FALSE;
proto_item *msg_id_item;
proto_item *item = NULL;
proto_tree *tree = NULL;
proto_item *header_item = NULL;
proto_tree *header_tree = NULL;
int offset = 0;
int chain_offset = 0;
const char *label = smb_header_label;
conversation_t *conversation;
smb2_saved_info_t *ssi = NULL, ssi_key;
smb2_info_t *si;
smb2_transform_info_t *sti;
char *fid_name;
guint32 open_frame,close_frame;
smb2_eo_file_info_t *eo_file_info;
e_ctx_hnd *policy_hnd_hashtablekey;
sti = wmem_new(wmem_packet_scope(), smb2_transform_info_t);
si = wmem_new0(wmem_packet_scope(), smb2_info_t);
si->top_tree = parent_tree;
if (tvb_get_guint8(tvb, 0) == 0xfd) {
smb2_transform_header = TRUE;
label = smb_transform_header_label;
}
conversation = find_or_create_conversation(pinfo);
si->conv = (smb2_conv_info_t *)conversation_get_proto_data(conversation, proto_smb2);
if (!si->conv) {
si->conv = wmem_new(wmem_file_scope(), smb2_conv_info_t);
si->conv->matched = g_hash_table_new(smb2_saved_info_hash_matched,
smb2_saved_info_equal_matched);
si->conv->unmatched = g_hash_table_new(smb2_saved_info_hash_unmatched,
smb2_saved_info_equal_unmatched);
si->conv->sesids = g_hash_table_new(smb2_sesid_info_hash,
smb2_sesid_info_equal);
si->conv->fids = g_hash_table_new(smb2_fid_info_hash,
smb2_fid_info_equal);
si->conv->files = g_hash_table_new(smb2_eo_files_hash,smb2_eo_files_equal);
wmem_register_callback(wmem_file_scope(), smb2_conv_destroy,
si->conv);
conversation_add_proto_data(conversation, proto_smb2, si->conv);
}
sti->conv = si->conv;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMB2");
if (first_in_chain) {
col_clear(pinfo->cinfo, COL_INFO);
} else {
col_append_str(pinfo->cinfo, COL_INFO, ";");
}
item = proto_tree_add_item(parent_tree, proto_smb2, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb2);
header_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_smb2_header, &header_item, label);
if (!smb2_transform_header) {
proto_tree_add_item(header_tree, hf_smb2_server_component_smb2, tvb, offset, 4, ENC_NA);
offset += 4;
si->flags = tvb_get_letohl(tvb, offset+12);
proto_tree_add_item(header_tree, hf_smb2_header_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(header_tree, hf_smb2_credit_charge, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (si->flags & SMB2_FLAGS_RESPONSE) {
si->status = tvb_get_letohl(tvb, offset);
proto_tree_add_item(header_tree, hf_smb2_nt_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
} else {
si->status = 0;
proto_tree_add_item(header_tree, hf_smb2_channel_sequence, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(header_tree, hf_smb2_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
}
si->opcode = tvb_get_letohs(tvb, offset);
proto_tree_add_item(header_tree, hf_smb2_cmd, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (si->flags & SMB2_FLAGS_RESPONSE) {
proto_tree_add_item(header_tree, hf_smb2_credits_granted, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(header_tree, hf_smb2_credits_requested, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
if (header_tree) {
static const int * flags[] = {
&hf_smb2_flags_response,
&hf_smb2_flags_async_cmd,
&hf_smb2_flags_chained,
&hf_smb2_flags_signature,
&hf_smb2_flags_priority_mask,
&hf_smb2_flags_dfs_op,
&hf_smb2_flags_replay_operation,
NULL
};
proto_tree_add_bitmask(header_tree, tvb, offset, hf_smb2_flags,
ett_smb2_flags, flags, ENC_LITTLE_ENDIAN);
}
offset += 4;
chain_offset = tvb_get_letohl(tvb, offset);
proto_tree_add_item(header_tree, hf_smb2_chain_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
si->msg_id = tvb_get_letoh64(tvb, offset);
ssi_key.msg_id = si->msg_id;
msg_id_item = proto_tree_add_item(header_tree, hf_smb2_msg_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
if (msg_id_item && (si->msg_id == -1)) {
proto_item_append_text(msg_id_item, " (unsolicited response)");
}
offset += 8;
offset = dissect_smb2_tid_sesid(pinfo, header_tree, tvb, offset, si);
proto_tree_add_item(header_tree, hf_smb2_signature, tvb, offset, 16, ENC_NA);
offset += 16;
proto_item_set_len(header_item, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s",
decode_smb2_name(si->opcode),
(si->flags & SMB2_FLAGS_RESPONSE)?"Response":"Request");
if (si->status) {
col_append_fstr(
pinfo->cinfo, COL_INFO, ", Error: %s",
val_to_str_ext(si->status, &NT_errors_ext,
"Unknown (0x%08X)"));
}
if (!pinfo->fd->flags.visited) {
ssi = (smb2_saved_info_t *)g_hash_table_lookup(si->conv->unmatched, &ssi_key);
if (!(si->flags & SMB2_FLAGS_RESPONSE)) {
if (ssi) {
g_hash_table_remove(si->conv->unmatched, ssi);
ssi = NULL;
}
if (!ssi) {
ssi = wmem_new0(wmem_file_scope(), smb2_saved_info_t);
ssi->msg_id = ssi_key.msg_id;
ssi->frame_req = pinfo->num;
ssi->req_time = pinfo->abs_ts;
ssi->extra_info_type = SMB2_EI_NONE;
g_hash_table_insert(si->conv->unmatched, ssi, ssi);
}
} else {
if (!((si->flags & SMB2_FLAGS_ASYNC_CMD)
&& si->status == NT_STATUS_PENDING)
&& ssi) {
ssi->frame_res = pinfo->num;
g_hash_table_remove(si->conv->unmatched, ssi);
g_hash_table_insert(si->conv->matched, ssi, ssi);
}
}
} else {
ssi = (smb2_saved_info_t *)g_hash_table_lookup(si->conv->matched, &ssi_key);
if (!ssi) {
ssi = (smb2_saved_info_t *)g_hash_table_lookup(si->conv->unmatched, &ssi_key);
}
}
if (ssi) {
if (dcerpc_fetch_polhnd_data(&ssi->policy_hnd, &fid_name, NULL, &open_frame, &close_frame, pinfo->num)) {
if (!si->eo_file_info) {
if (si->conv) {
eo_file_info = (smb2_eo_file_info_t *)g_hash_table_lookup(si->conv->files,&ssi->policy_hnd);
if (!eo_file_info) {
eo_file_info = wmem_new(wmem_file_scope(), smb2_eo_file_info_t);
policy_hnd_hashtablekey = wmem_new(wmem_file_scope(), e_ctx_hnd);
memcpy(policy_hnd_hashtablekey, &ssi->policy_hnd, sizeof(e_ctx_hnd));
eo_file_info->end_of_file=0;
g_hash_table_insert(si->conv->files,policy_hnd_hashtablekey,eo_file_info);
}
si->eo_file_info=eo_file_info;
}
}
}
if (!(si->flags & SMB2_FLAGS_RESPONSE)) {
if (ssi->frame_res) {
proto_item *tmp_item;
tmp_item = proto_tree_add_uint(header_tree, hf_smb2_response_in, tvb, 0, 0, ssi->frame_res);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
} else {
if (ssi->frame_req) {
proto_item *tmp_item;
nstime_t t, deltat;
tmp_item = proto_tree_add_uint(header_tree, hf_smb2_response_to, tvb, 0, 0, ssi->frame_req);
PROTO_ITEM_SET_GENERATED(tmp_item);
t = pinfo->abs_ts;
nstime_delta(&deltat, &t, &ssi->req_time);
tmp_item = proto_tree_add_time(header_tree, hf_smb2_time, tvb,
0, 0, &deltat);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
if (si->file != NULL) {
ssi->file = si->file;
} else {
si->file = ssi->file;
}
}
si->saved = ssi;
tap_queue_packet(smb2_tap, pinfo, si);
offset = dissect_smb2_command(pinfo, tree, tvb, offset, si);
} else {
proto_tree *enc_tree;
tvbuff_t *enc_tvb = NULL;
tvbuff_t *plain_tvb = NULL;
proto_tree_add_item(header_tree, hf_smb2_server_component_smb2_transform, tvb, offset, 4, ENC_NA);
offset += 4;
offset = dissect_smb2_transform_header(pinfo, header_tree, tvb, offset, sti,
&enc_tvb, &plain_tvb);
enc_tree = proto_tree_add_subtree(tree, enc_tvb, 0, sti->size, ett_smb2_encrypted, NULL, "Encrypted SMB3 data");
if (plain_tvb != NULL) {
col_append_str(pinfo->cinfo, COL_INFO, "Decrypted SMB3");
dissect_smb2(plain_tvb, pinfo, enc_tree, FALSE);
} else {
col_append_str(pinfo->cinfo, COL_INFO, "Encrypted SMB3");
proto_tree_add_item(enc_tree, hf_smb2_transform_encrypted_data,
enc_tvb, 0, sti->size, ENC_NA);
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
chain_offset = offset;
}
}
if (chain_offset > 0) {
tvbuff_t *next_tvb;
proto_item_set_len(item, chain_offset);
next_tvb = tvb_new_subset_remaining(tvb, chain_offset);
offset = dissect_smb2(next_tvb, pinfo, parent_tree, FALSE);
}
return offset;
}
static gboolean
dissect_smb2_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
if (tvb_captured_length(tvb) < 4)
return FALSE;
if (((tvb_get_guint8(tvb, 0) != 0xfe) && (tvb_get_guint8(tvb, 0) != 0xfd))
|| (tvb_get_guint8(tvb, 1) != 'S')
|| (tvb_get_guint8(tvb, 2) != 'M')
|| (tvb_get_guint8(tvb, 3) != 'B') ) {
return FALSE;
}
dissect_smb2(tvb, pinfo, parent_tree, TRUE);
return TRUE;
}
void
proto_register_smb2(void)
{
module_t *smb2_module;
static hf_register_info hf[] = {
{ &hf_smb2_cmd,
{ "Command", "smb2.cmd", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&smb2_cmd_vals_ext, 0, "SMB2 Command Opcode", HFILL }},
{ &hf_smb2_response_to,
{ "Response to", "smb2.response_to", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This packet is a response to the packet in this frame", HFILL }},
{ &hf_smb2_response_in,
{ "Response in", "smb2.response_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, "The response to this packet is in this packet", HFILL }},
{ &hf_smb2_time,
{ "Time from request", "smb2.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time between Request and Response for SMB2 cmds", HFILL }},
{ &hf_smb2_header_len,
{ "Header Length", "smb2.header_len", FT_UINT16, BASE_DEC,
NULL, 0, "SMB2 Size of Header", HFILL }},
{ &hf_smb2_nt_status,
{ "NT Status", "smb2.nt_status", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&NT_errors_ext, 0, "NT Status code", HFILL }},
{ &hf_smb2_msg_id,
{ "Message ID", "smb2.msg_id", FT_INT64, BASE_DEC,
NULL, 0, "SMB2 Message ID", HFILL }},
{ &hf_smb2_tid,
{ "Tree Id", "smb2.tid", FT_UINT32, BASE_HEX,
NULL, 0, "SMB2 Tree Id", HFILL }},
{ &hf_smb2_aid,
{ "Async Id", "smb2.aid", FT_UINT64, BASE_HEX,
NULL, 0, "SMB2 Async Id", HFILL }},
{ &hf_smb2_sesid,
{ "Session Id", "smb2.sesid", FT_UINT64, BASE_HEX,
NULL, 0, "SMB2 Session Id", HFILL }},
{ &hf_smb2_previous_sesid,
{ "Previous Session Id", "smb2.previous_sesid", FT_UINT64, BASE_HEX,
NULL, 0, "SMB2 Previous Session Id", HFILL }},
{ &hf_smb2_chain_offset,
{ "Chain Offset", "smb2.chain_offset", FT_UINT32, BASE_HEX,
NULL, 0, "SMB2 Chain Offset", HFILL }},
{ &hf_smb2_end_of_file,
{ "End Of File", "smb2.eof", FT_UINT64, BASE_DEC,
NULL, 0, "SMB2 End Of File/File size", HFILL }},
{ &hf_smb2_nlinks,
{ "Number of Links", "smb2.nlinks", FT_UINT32, BASE_DEC,
NULL, 0, "Number of links to this object", HFILL }},
{ &hf_smb2_file_id,
{ "File Id", "smb2.file_id", FT_UINT64, BASE_HEX,
NULL, 0, "SMB2 File Id", HFILL }},
{ &hf_smb2_allocation_size,
{ "Allocation Size", "smb2.allocation_size", FT_UINT64, BASE_DEC,
NULL, 0, "SMB2 Allocation Size for this object", HFILL }},
{ &hf_smb2_max_response_size,
{ "Max Response Size", "smb2.max_response_size", FT_UINT32, BASE_DEC,
NULL, 0, "SMB2 Maximum response size", HFILL }},
{ &hf_smb2_setinfo_size,
{ "Setinfo Size", "smb2.setinfo_size", FT_UINT32, BASE_DEC,
NULL, 0, "SMB2 setinfo size", HFILL }},
{ &hf_smb2_setinfo_offset,
{ "Setinfo Offset", "smb2.setinfo_offset", FT_UINT16, BASE_HEX,
NULL, 0, "SMB2 setinfo offset", HFILL }},
{ &hf_smb2_max_ioctl_out_size,
{ "Max Ioctl Out Size", "smb2.max_ioctl_out_size", FT_UINT32, BASE_DEC,
NULL, 0, "SMB2 Maximum ioctl out size", HFILL }},
{ &hf_smb2_max_ioctl_in_size,
{ "Max Ioctl In Size", "smb2.max_ioctl_in_size", FT_UINT32, BASE_DEC,
NULL, 0, "SMB2 Maximum ioctl out size", HFILL }},
{ &hf_smb2_required_buffer_size,
{ "Required Buffer Size", "smb2.required_size", FT_UINT32, BASE_DEC,
NULL, 0, "SMB2 required buffer size", HFILL }},
{ &hf_smb2_pid,
{ "Process Id", "smb2.pid", FT_UINT32, BASE_HEX,
NULL, 0, "SMB2 Process Id", HFILL }},
{ &hf_smb2_flags,
{ "Flags", "smb2.flags", FT_UINT32, BASE_HEX,
NULL, 0, "SMB2 flags", HFILL }},
{ &hf_smb2_flags_response,
{ "Response", "smb2.flags.response", FT_BOOLEAN, 32,
TFS(&tfs_flags_response), SMB2_FLAGS_RESPONSE, "Whether this is an SMB2 Request or Response", HFILL }},
{ &hf_smb2_flags_async_cmd,
{ "Async command", "smb2.flags.async", FT_BOOLEAN, 32,
TFS(&tfs_flags_async_cmd), SMB2_FLAGS_ASYNC_CMD, NULL, HFILL }},
{ &hf_smb2_flags_dfs_op,
{ "DFS operation", "smb2.flags.dfs", FT_BOOLEAN, 32,
TFS(&tfs_flags_dfs_op), SMB2_FLAGS_DFS_OP, NULL, HFILL }},
{ &hf_smb2_flags_chained,
{ "Chained", "smb2.flags.chained", FT_BOOLEAN, 32,
TFS(&tfs_flags_chained), SMB2_FLAGS_CHAINED, "Whether the pdu continues a chain or not", HFILL }},
{ &hf_smb2_flags_signature,
{ "Signing", "smb2.flags.signature", FT_BOOLEAN, 32,
TFS(&tfs_flags_signature), SMB2_FLAGS_SIGNATURE, "Whether the pdu is signed or not", HFILL }},
{ &hf_smb2_flags_replay_operation,
{ "Replay operation", "smb2.flags.replay", FT_BOOLEAN, 32,
TFS(&tfs_flags_replay_operation), SMB2_FLAGS_REPLAY_OPERATION, "Whether this is a replay operation", HFILL }},
{ &hf_smb2_flags_priority_mask,
{ "Priority", "smb2.flags.priority_mask", FT_BOOLEAN, 32,
TFS(&tfs_flags_priority_mask), SMB2_FLAGS_PRIORITY_MASK, "Priority Mask", HFILL }},
{ &hf_smb2_tree,
{ "Tree", "smb2.tree", FT_STRING, BASE_NONE,
NULL, 0, "Name of the Tree/Share", HFILL }},
{ &hf_smb2_filename,
{ "Filename", "smb2.filename", FT_STRING, BASE_NONE,
NULL, 0, "Name of the file", HFILL }},
{ &hf_smb2_filename_len,
{ "Filename Length", "smb2.filename.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of the file name", HFILL }},
{ &hf_smb2_replace_if,
{ "Replace If", "smb2.rename.replace_if", FT_BOOLEAN, 8,
TFS(&tfs_replace_if_exists), 0xFF, "Whether to replace if the target exists", HFILL }},
{ &hf_smb2_data_offset,
{ "Data Offset", "smb2.data_offset", FT_UINT16, BASE_HEX,
NULL, 0, "Offset to data", HFILL }},
{ &hf_smb2_find_info_level,
{ "Info Level", "smb2.find.infolevel", FT_UINT32, BASE_DEC,
VALS(smb2_find_info_levels), 0, "Find_Info Infolevel", HFILL }},
{ &hf_smb2_find_flags,
{ "Find Flags", "smb2.find.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_find_pattern,
{ "Search Pattern", "smb2.find.pattern", FT_STRING, BASE_NONE,
NULL, 0, "Find pattern", HFILL }},
{ &hf_smb2_find_info_blob,
{ "Info", "smb2.find.info_blob", FT_BYTES, BASE_NONE,
NULL, 0, "Find Info", HFILL }},
{ &hf_smb2_ea_size,
{ "EA Size", "smb2.ea_size", FT_UINT32, BASE_DEC,
NULL, 0, "Size of EA data", HFILL }},
{ &hf_smb2_class,
{ "Class", "smb2.class", FT_UINT8, BASE_HEX,
VALS(smb2_class_vals), 0, "Info class", HFILL }},
{ &hf_smb2_infolevel,
{ "InfoLevel", "smb2.infolevel", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_infolevel_file_info,
{ "InfoLevel", "smb2.file_info.infolevel", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&smb2_file_info_levels_ext, 0, "File_Info Infolevel", HFILL }},
{ &hf_smb2_infolevel_fs_info,
{ "InfoLevel", "smb2.fs_info.infolevel", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&smb2_fs_info_levels_ext, 0, "Fs_Info Infolevel", HFILL }},
{ &hf_smb2_infolevel_sec_info,
{ "InfoLevel", "smb2.sec_info.infolevel", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&smb2_sec_info_levels_ext, 0, "Sec_Info Infolevel", HFILL }},
{ &hf_smb2_infolevel_posix_info,
{ "InfoLevel", "smb2.posix_info.infolevel", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&smb2_posix_info_levels_ext, 0, "Posix_Info Infolevel", HFILL }},
{ &hf_smb2_write_length,
{ "Write Length", "smb2.write_length", FT_UINT32, BASE_DEC,
NULL, 0, "Amount of data to write", HFILL }},
{ &hf_smb2_read_length,
{ "Read Length", "smb2.read_length", FT_UINT32, BASE_DEC,
NULL, 0, "Amount of data to read", HFILL }},
{ &hf_smb2_read_remaining,
{ "Read Remaining", "smb2.read_remaining", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_create_flags,
{ "Create Flags", "smb2.create_flags", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_file_offset,
{ "File Offset", "smb2.file_offset", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_fsctl_range_offset,
{ "File Offset", "smb2.fsctl.range_offset", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_fsctl_range_length,
{ "Length", "smb2.fsctl.range_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_qfr_length,
{ "Length", "smb2.qfr_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_qfr_usage,
{ "Desired Usage", "smb2.qfr_usage", FT_UINT32, BASE_HEX,
VALS(file_region_usage_vals), 0, NULL, HFILL }},
{ &hf_smb2_qfr_flags,
{ "Flags", "smb2.qfr_flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_qfr_total_region_entry_count,
{ "Total Region Entry Count", "smb2.qfr_tot_region_entry_count", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_qfr_region_entry_count,
{ "Region Entry Count", "smb2.qfr_region_entry_count", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_security_blob,
{ "Security Blob", "smb2.security_blob", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ioctl_out_data,
{ "Out Data", "smb2.ioctl.out", FT_NONE, BASE_NONE,
NULL, 0, "Ioctl Out", HFILL }},
{ &hf_smb2_ioctl_in_data,
{ "In Data", "smb2.ioctl.in", FT_NONE, BASE_NONE,
NULL, 0, "Ioctl In", HFILL }},
{ &hf_smb2_server_guid,
{ "Server Guid", "smb2.server_guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_client_guid,
{ "Client Guid", "smb2.client_guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_object_id,
{ "ObjectId", "smb2.object_id", FT_GUID, BASE_NONE,
NULL, 0, "ObjectID for this FID", HFILL }},
{ &hf_smb2_birth_volume_id,
{ "BirthVolumeId", "smb2.birth_volume_id", FT_GUID, BASE_NONE,
NULL, 0, "ObjectID for the volume where this FID was originally created", HFILL }},
{ &hf_smb2_birth_object_id,
{ "BirthObjectId", "smb2.birth_object_id", FT_GUID, BASE_NONE,
NULL, 0, "ObjectID for this FID when it was originally created", HFILL }},
{ &hf_smb2_domain_id,
{ "DomainId", "smb2.domain_id", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_create_timestamp,
{ "Create", "smb2.create.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this object was created", HFILL }},
{ &hf_smb2_fid,
{ "File Id", "smb2.fid", FT_GUID, BASE_NONE,
NULL, 0, "SMB2 File Id", HFILL }},
{ &hf_smb2_write_data,
{ "Write Data", "smb2.write_data", FT_BYTES, BASE_NONE,
NULL, 0, "SMB2 Data to be written", HFILL }},
{ &hf_smb2_write_flags,
{ "Write Flags", "smb2.write.flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_write_flags_write_through,
{ "Write through", "smb2.write.flags.write_through", FT_BOOLEAN, 32,
NULL, SMB2_WRITE_FLAG_WRITE_THROUGH, NULL, HFILL }},
{ &hf_smb2_write_count,
{ "Write Count", "smb2.write.count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_write_remaining,
{ "Write Remaining", "smb2.write.remaining", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_read_data,
{ "Read Data", "smb2.read_data", FT_BYTES, BASE_NONE,
NULL, 0, "SMB2 Data that is read", HFILL }},
{ &hf_smb2_last_access_timestamp,
{ "Last Access", "smb2.last_access.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this object was last accessed", HFILL }},
{ &hf_smb2_last_write_timestamp,
{ "Last Write", "smb2.last_write.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this object was last written to", HFILL }},
{ &hf_smb2_last_change_timestamp,
{ "Last Change", "smb2.last_change.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this object was last changed", HFILL }},
{ &hf_smb2_file_all_info,
{ "SMB2_FILE_ALL_INFO", "smb2.file_all_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ALL_INFO structure", HFILL }},
{ &hf_smb2_file_allocation_info,
{ "SMB2_FILE_ALLOCATION_INFO", "smb2.file_allocation_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ALLOCATION_INFO structure", HFILL }},
{ &hf_smb2_file_endoffile_info,
{ "SMB2_FILE_ENDOFFILE_INFO", "smb2.file_endoffile_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ENDOFFILE_INFO structure", HFILL }},
{ &hf_smb2_file_alternate_name_info,
{ "SMB2_FILE_ALTERNATE_NAME_INFO", "smb2.file_alternate_name_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ALTERNATE_NAME_INFO structure", HFILL }},
{ &hf_smb2_file_stream_info,
{ "SMB2_FILE_STREAM_INFO", "smb2.file_stream_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_STREAM_INFO structure", HFILL }},
{ &hf_smb2_file_pipe_info,
{ "SMB2_FILE_PIPE_INFO", "smb2.file_pipe_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_PIPE_INFO structure", HFILL }},
{ &hf_smb2_file_compression_info,
{ "SMB2_FILE_COMPRESSION_INFO", "smb2.file_compression_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_COMPRESSION_INFO structure", HFILL }},
{ &hf_smb2_file_basic_info,
{ "SMB2_FILE_BASIC_INFO", "smb2.file_basic_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_BASIC_INFO structure", HFILL }},
{ &hf_smb2_file_standard_info,
{ "SMB2_FILE_STANDARD_INFO", "smb2.file_standard_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_STANDARD_INFO structure", HFILL }},
{ &hf_smb2_file_internal_info,
{ "SMB2_FILE_INTERNAL_INFO", "smb2.file_internal_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_INTERNAL_INFO structure", HFILL }},
{ &hf_smb2_file_mode_info,
{ "SMB2_FILE_MODE_INFO", "smb2.file_mode_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_MODE_INFO structure", HFILL }},
{ &hf_smb2_file_alignment_info,
{ "SMB2_FILE_ALIGNMENT_INFO", "smb2.file_alignment_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ALIGNMENT_INFO structure", HFILL }},
{ &hf_smb2_file_position_info,
{ "SMB2_FILE_POSITION_INFO", "smb2.file_position_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_POSITION_INFO structure", HFILL }},
{ &hf_smb2_file_access_info,
{ "SMB2_FILE_ACCESS_INFO", "smb2.file_access_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ACCESS_INFO structure", HFILL }},
{ &hf_smb2_file_ea_info,
{ "SMB2_FILE_EA_INFO", "smb2.file_ea_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_EA_INFO structure", HFILL }},
{ &hf_smb2_file_network_open_info,
{ "SMB2_FILE_NETWORK_OPEN_INFO", "smb2.file_network_open_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_NETWORK_OPEN_INFO structure", HFILL }},
{ &hf_smb2_file_attribute_tag_info,
{ "SMB2_FILE_ATTRIBUTE_TAG_INFO", "smb2.file_attribute_tag_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_ATTRIBUTE_TAG_INFO structure", HFILL }},
{ &hf_smb2_file_disposition_info,
{ "SMB2_FILE_DISPOSITION_INFO", "smb2.file_disposition_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_DISPOSITION_INFO structure", HFILL }},
{ &hf_smb2_file_full_ea_info,
{ "SMB2_FILE_FULL_EA_INFO", "smb2.file_full_ea_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_FULL_EA_INFO structure", HFILL }},
{ &hf_smb2_file_rename_info,
{ "SMB2_FILE_RENAME_INFO", "smb2.file_rename_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FILE_RENAME_INFO structure", HFILL }},
{ &hf_smb2_fs_info_01,
{ "SMB2_FS_INFO_01", "smb2.fs_info_01", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_INFO_01 structure", HFILL }},
{ &hf_smb2_fs_info_03,
{ "SMB2_FS_INFO_03", "smb2.fs_info_03", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_INFO_03 structure", HFILL }},
{ &hf_smb2_fs_info_04,
{ "SMB2_FS_INFO_04", "smb2.fs_info_04", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_INFO_04 structure", HFILL }},
{ &hf_smb2_fs_info_05,
{ "SMB2_FS_INFO_05", "smb2.fs_info_05", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_INFO_05 structure", HFILL }},
{ &hf_smb2_fs_info_06,
{ "SMB2_FS_INFO_06", "smb2.fs_info_06", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_INFO_06 structure", HFILL }},
{ &hf_smb2_fs_info_07,
{ "SMB2_FS_INFO_07", "smb2.fs_info_07", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_INFO_07 structure", HFILL }},
{ &hf_smb2_fs_objectid_info,
{ "SMB2_FS_OBJECTID_INFO", "smb2.fs_objectid_info", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_FS_OBJECTID_INFO structure", HFILL }},
{ &hf_smb2_sec_info_00,
{ "SMB2_SEC_INFO_00", "smb2.sec_info_00", FT_NONE, BASE_NONE,
NULL, 0, "SMB2_SEC_INFO_00 structure", HFILL }},
{ &hf_smb2_disposition_delete_on_close,
{ "Delete on close", "smb2.disposition.delete_on_close", FT_BOOLEAN, 8,
TFS(&tfs_disposition_delete_on_close), 0x01, NULL, HFILL }},
{ &hf_smb2_create_disposition,
{ "Disposition", "smb2.create.disposition", FT_UINT32, BASE_DEC,
VALS(create_disposition_vals), 0, "Create disposition, what to do if the file does/does not exist", HFILL }},
{ &hf_smb2_create_action,
{ "Create Action", "smb2.create.action", FT_UINT32, BASE_DEC,
VALS(oa_open_vals), 0, NULL, HFILL }},
{ &hf_smb2_create_rep_flags,
{ "Response Flags", "smb2.create.rep_flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_create_rep_flags_reparse_point,
{ "ReparsePoint", "smb2.create.rep_flags.reparse_point", FT_BOOLEAN, 8,
NULL, SMB2_CREATE_REP_FLAGS_REPARSE_POINT, NULL, HFILL }},
{ &hf_smb2_extrainfo,
{ "ExtraInfo", "smb2.create.extrainfo", FT_NONE, BASE_NONE,
NULL, 0, "Create ExtraInfo", HFILL }},
{ &hf_smb2_create_chain_offset,
{ "Chain Offset", "smb2.create.chain_offset", FT_UINT32, BASE_HEX,
NULL, 0, "Offset to next entry in chain or 0", HFILL }},
{ &hf_smb2_create_chain_data,
{ "Data", "smb2.create.chain_data", FT_NONE, BASE_NONE,
NULL, 0, "Chain Data", HFILL }},
{ &hf_smb2_FILE_OBJECTID_BUFFER,
{ "FILE_OBJECTID_BUFFER", "smb2.FILE_OBJECTID_BUFFER", FT_NONE, BASE_NONE,
NULL, 0, "A FILE_OBJECTID_BUFFER structure", HFILL }},
{ &hf_smb2_lease_key,
{ "Lease Key", "smb2.lease.lease_key", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_state,
{ "Lease State", "smb2.lease.lease_state", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_state_read_caching,
{ "Read Caching", "smb2.lease.lease_state.read_caching", FT_BOOLEAN, 32,
NULL, SMB2_LEASE_STATE_READ_CACHING, NULL, HFILL }},
{ &hf_smb2_lease_state_handle_caching,
{ "Handle Caching", "smb2.lease.lease_state.handle_caching", FT_BOOLEAN, 32,
NULL, SMB2_LEASE_STATE_HANDLE_CACHING, NULL, HFILL }},
{ &hf_smb2_lease_state_write_caching,
{ "Write Caching", "smb2.lease.lease_state.write_caching", FT_BOOLEAN, 32,
NULL, SMB2_LEASE_STATE_WRITE_CACHING, NULL, HFILL }},
{ &hf_smb2_lease_flags,
{ "Lease Flags", "smb2.lease.lease_flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_flags_break_ack_required,
{ "Break Ack Required", "smb2.lease.lease_state.break_ack_required", FT_BOOLEAN, 32,
NULL, SMB2_LEASE_FLAGS_BREAK_ACK_REQUIRED, NULL, HFILL }},
{ &hf_smb2_lease_flags_break_in_progress,
{ "Break In Progress", "smb2.lease.lease_state.break_in_progress", FT_BOOLEAN, 32,
NULL, SMB2_LEASE_FLAGS_BREAK_IN_PROGRESS, NULL, HFILL }},
{ &hf_smb2_lease_flags_parent_lease_key_set,
{ "Parent Lease Key Set", "smb2.lease.lease_state.parent_lease_key_set", FT_BOOLEAN, 32,
NULL, SMB2_LEASE_FLAGS_PARENT_LEASE_KEY_SET, NULL, HFILL }},
{ &hf_smb2_lease_duration,
{ "Lease Duration", "smb2.lease.lease_duration", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_parent_lease_key,
{ "Parent Lease Key", "smb2.lease.parent_lease_key", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_epoch,
{ "Lease Epoch", "smb2.lease.lease_oplock", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_reserved,
{ "Lease Reserved", "smb2.lease.lease_reserved", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_break_reason,
{ "Lease Break Reason", "smb2.lease.lease_break_reason", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_access_mask_hint,
{ "Access Mask Hint", "smb2.lease.access_mask_hint", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lease_share_mask_hint,
{ "Share Mask Hint", "smb2.lease.share_mask_hint", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_next_offset,
{ "Next Offset", "smb2.next_offset", FT_UINT32, BASE_DEC,
NULL, 0, "Offset to next buffer or 0", HFILL }},
{ &hf_smb2_negotiate_context_type,
{ "Type", "smb2.negotiate_context.type", FT_UINT16, BASE_HEX,
VALS(smb2_negotiate_context_types), 0, "NegotiateContext Type", HFILL }},
{ &hf_smb2_negotiate_context_data_length,
{ "DataLength", "smb2.negotiate_context.data_length", FT_UINT16, BASE_DEC,
NULL, 0, "NegotiateContext DataLength", HFILL }},
{ &hf_smb2_negotiate_context_offset,
{ "NegotiateContextOffset", "smb2.negotiate_context.offset", FT_UINT16, BASE_HEX,
NULL, 0, "NegotiateContext Offset", HFILL }},
{ &hf_smb2_negotiate_context_count,
{ "NegotiateContextCount", "smb2.negotiate_context.count", FT_UINT16, BASE_DEC,
NULL, 0, "NegotiateContext Count", HFILL }},
{ &hf_smb2_current_time,
{ "Current Time", "smb2.current_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Current Time at server", HFILL }},
{ &hf_smb2_boot_time,
{ "Boot Time", "smb2.boot_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Boot Time at server", HFILL }},
{ &hf_smb2_ea_flags,
{ "EA Flags", "smb2.ea.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ea_name_len,
{ "EA Name Length", "smb2.ea.name_len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ea_data_len,
{ "EA Data Length", "smb2.ea.data_len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_delete_pending,
{ "Delete Pending", "smb2.delete_pending", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_is_directory,
{ "Is Directory", "smb2.is_directory", FT_UINT8, BASE_DEC,
NULL, 0, "Is this a directory?", HFILL }},
{ &hf_smb2_oplock,
{ "Oplock", "smb2.create.oplock", FT_UINT8, BASE_HEX,
VALS(oplock_vals), 0, "Oplock type", HFILL }},
{ &hf_smb2_close_flags,
{ "Close Flags", "smb2.close.flags", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_notify_flags,
{ "Notify Flags", "smb2.notify.flags", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_buffer_code,
{ "StructureSize", "smb2.buffer_code", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_buffer_code_len,
{ "Fixed Part Length", "smb2.buffer_code.length", FT_UINT16, BASE_DEC,
NULL, 0xFFFE, "Length of fixed portion of PDU", HFILL }},
{ &hf_smb2_olb_length,
{ "Length", "smb2.olb.length", FT_UINT32, BASE_DEC,
NULL, 0, "Length of the buffer", HFILL }},
{ &hf_smb2_olb_offset,
{ "Offset", "smb2.olb.offset", FT_UINT32, BASE_HEX,
NULL, 0, "Offset to the buffer", HFILL }},
{ &hf_smb2_buffer_code_flags_dyn,
{ "Dynamic Part", "smb2.buffer_code.dynamic", FT_BOOLEAN, 16,
NULL, 0x0001, "Whether a dynamic length blob follows", HFILL }},
{ &hf_smb2_ea_data,
{ "EA Data", "smb2.ea.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ea_name,
{ "EA Name", "smb2.ea.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_impersonation_level,
{ "Impersonation", "smb2.impersonation.level", FT_UINT32, BASE_DEC,
VALS(impersonation_level_vals), 0, "Impersonation level", HFILL }},
{ &hf_smb2_ioctl_function,
{ "Function", "smb2.ioctl.function", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&smb2_ioctl_vals_ext, 0, "Ioctl function", HFILL }},
{ &hf_smb2_ioctl_function_device,
{ "Device", "smb2.ioctl.function.device", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&smb2_ioctl_device_vals_ext, 0xffff0000, "Device for Ioctl", HFILL }},
{ &hf_smb2_ioctl_function_access,
{ "Access", "smb2.ioctl.function.access", FT_UINT32, BASE_HEX,
VALS(smb2_ioctl_access_vals), 0x0000c000, "Access for Ioctl", HFILL }},
{ &hf_smb2_ioctl_function_function,
{ "Function", "smb2.ioctl.function.function", FT_UINT32, BASE_HEX,
NULL, 0x00003ffc, "Function for Ioctl", HFILL }},
{ &hf_smb2_ioctl_function_method,
{ "Method", "smb2.ioctl.function.method", FT_UINT32, BASE_HEX,
VALS(smb2_ioctl_method_vals), 0x00000003, "Method for Ioctl", HFILL }},
{ &hf_smb2_fsctl_pipe_wait_timeout,
{ "Timeout", "smb2.fsctl.wait.timeout", FT_INT64, BASE_DEC,
NULL, 0, "Wait timeout", HFILL }},
{ &hf_smb2_fsctl_pipe_wait_name,
{ "Name", "smb2.fsctl.wait.name", FT_STRING, BASE_NONE,
NULL, 0, "Pipe name", HFILL }},
{ &hf_smb2_fsctl_odx_token_type,
{ "TokenType", "smb2.fsctl.odx.token.type", FT_UINT32, BASE_HEX,
NULL, 0, "Token Type", HFILL }},
{ &hf_smb2_fsctl_odx_token_idlen,
{ "TokenIdLength", "smb2.fsctl.odx.token.idlen", FT_UINT16, BASE_DEC,
NULL, 0, "Token ID Length", HFILL }},
{ &hf_smb2_fsctl_odx_token_idraw,
{ "TokenId", "smb2.fsctl.odx.token.id", FT_BYTES, BASE_NONE,
NULL, 0, "Token ID (opaque)", HFILL }},
{ &hf_smb2_fsctl_odx_token_ttl,
{ "TokenTimeToLive", "smb2.fsctl.odx.token_ttl",
FT_UINT32, BASE_DEC, NULL, 0,
"TTL requested for the token (in milliseconds)", HFILL }},
{ &hf_smb2_fsctl_odx_size,
{ "Size", "smb2.fsctl.odx.size", FT_UINT32, BASE_DEC,
NULL, 0, "Size of this data element", HFILL }},
{ &hf_smb2_fsctl_odx_flags,
{ "Flags", "smb2.fsctl.odx.flags", FT_UINT32, BASE_HEX,
NULL, 0, "Flags for this operation", HFILL }},
{ &hf_smb2_fsctl_odx_file_offset,
{ "FileOffset", "smb2.fsctl.odx.file_offset",
FT_UINT64, BASE_DEC, NULL, 0,
"File offset", HFILL }},
{ &hf_smb2_fsctl_odx_copy_length,
{ "CopyLength", "smb2.fsctl.odx.copy_length",
FT_UINT64, BASE_DEC, NULL, 0,
"Copy length", HFILL }},
{ &hf_smb2_fsctl_odx_xfer_length,
{ "TransferLength", "smb2.fsctl.odx.xfer_length",
FT_UINT64, BASE_DEC, NULL, 0,
"Length Transfered", HFILL }},
{ &hf_smb2_fsctl_odx_token_offset,
{ "TokenOffset", "smb2.fsctl.odx.token_offset",
FT_UINT64, BASE_DEC, NULL, 0,
"Token Offset (relative to start of token)", HFILL }},
{ &hf_smb2_fsctl_sparse_flag,
{ "SetSparse", "smb2.fsctl.set_sparse", FT_BOOLEAN, 8,
NULL, 0xFF, NULL, HFILL }},
{ &hf_smb2_ioctl_resiliency_timeout,
{ "Timeout", "smb2.ioctl.resiliency.timeout", FT_UINT32, BASE_DEC,
NULL, 0, "Resiliency timeout", HFILL }},
{ &hf_smb2_ioctl_resiliency_reserved,
{ "Reserved", "smb2.ioctl.resiliency.reserved", FT_UINT32, BASE_DEC,
NULL, 0, "Resiliency reserved", HFILL }},
{ &hf_windows_sockaddr_family,
{ "Socket Family", "smb2.windows.sockaddr.family", FT_UINT16, BASE_DEC,
NULL, 0, "The socket address family (on windows)", HFILL }},
{ &hf_windows_sockaddr_port,
{ "Socket Port", "smb2.windows.sockaddr.port", FT_UINT16, BASE_DEC,
NULL, 0, "The socket address port", HFILL }},
{ &hf_windows_sockaddr_in_addr,
{ "Socket IPv4", "smb2.windows.sockaddr.in.addr", FT_IPv4, BASE_NONE,
NULL, 0, "The IPv4 address", HFILL }},
{ &hf_windows_sockaddr_in6_flowinfo,
{ "IPv6 Flow Info", "smb2.windows.sockaddr.in6.flow_info", FT_UINT32, BASE_HEX,
NULL, 0, "The socket IPv6 flow info", HFILL }},
{ &hf_windows_sockaddr_in6_addr,
{ "Socket IPv6", "smb2.windows.sockaddr.in6.addr", FT_IPv6, BASE_NONE,
NULL, 0, "The IPv6 address", HFILL }},
{ &hf_windows_sockaddr_in6_scope_id,
{ "IPv6 Scope ID", "smb2.windows.sockaddr.in6.scope_id", FT_UINT32, BASE_DEC,
NULL, 0, "The socket IPv6 scope id", HFILL }},
{ &hf_smb2_ioctl_network_interface_next_offset,
{ "Next Offset", "smb2.ioctl.network_interfaces.next_offset", FT_UINT32, BASE_HEX,
NULL, 0, "Offset to next entry in chain or 0", HFILL }},
{ &hf_smb2_ioctl_network_interface_index,
{ "Interface Index", "smb2.ioctl.network_interfaces.index", FT_UINT32, BASE_DEC,
NULL, 0, "The index of the interface", HFILL }},
{ &hf_smb2_ioctl_network_interface_rss_queue_count,
{ "RSS Queue Count", "smb2.ioctl.network_interfaces.rss_queue_count", FT_UINT32, BASE_DEC,
NULL, 0, "The RSS queue count", HFILL }},
{ &hf_smb2_ioctl_network_interface_capabilities,
{ "Interface Cababilities", "smb2.ioctl.network_interfaces.capabilities", FT_UINT32, BASE_HEX,
NULL, 0, "The RSS queue count", HFILL }},
{ &hf_smb2_ioctl_network_interface_capability_rss,
{ "RSS", "smb2.ioctl.network_interfaces.capabilities.rss", FT_BOOLEAN, 32,
TFS(&tfs_smb2_ioctl_network_interface_capability_rss),
NETWORK_INTERFACE_CAP_RSS, "If the host supports RSS", HFILL }},
{ &hf_smb2_ioctl_network_interface_capability_rdma,
{ "RDMA", "smb2.ioctl.network_interfaces.capabilities.rdma", FT_BOOLEAN, 32,
TFS(&tfs_smb2_ioctl_network_interface_capability_rdma),
NETWORK_INTERFACE_CAP_RDMA, "If the host supports RDMA", HFILL }},
{ &hf_smb2_ioctl_network_interface_link_speed,
{ "Link Speed", "smb2.ioctl.network_interfaces.link_speed", FT_UINT64, BASE_DEC,
NULL, 0, "The link speed of the interface", HFILL }},
{ &hf_smb2_ioctl_shadow_copy_num_volumes,
{ "Num Volumes", "smb2.ioctl.shadow_copy.num_volumes", FT_UINT32, BASE_DEC,
NULL, 0, "Number of shadow copy volumes", HFILL }},
{ &hf_smb2_ioctl_shadow_copy_num_labels,
{ "Num Labels", "smb2.ioctl.shadow_copy.num_labels", FT_UINT32, BASE_DEC,
NULL, 0, "Number of shadow copy labels", HFILL }},
{ &hf_smb2_ioctl_shadow_copy_label,
{ "Label", "smb2.ioctl.shadow_copy.label", FT_STRING, BASE_NONE,
NULL, 0, "Shadow copy label", HFILL }},
{ &hf_smb2_compression_format,
{ "Compression Format", "smb2.compression_format", FT_UINT16, BASE_DEC,
VALS(compression_format_vals), 0, "Compression to use", HFILL }},
{ &hf_smb2_checksum_algorithm,
{ "Checksum Algorithm", "smb2.checksum_algorithm", FT_UINT16, BASE_HEX,
VALS(checksum_algorithm_vals), 0, "Checksum algorithm to use", HFILL}},
{ &hf_smb2_integrity_reserved,
{ "Reserved", "smb2.integrity_reserved", FT_UINT16, BASE_DEC,
NULL, 0, "Reserved Field", HFILL}},
{ &hf_smb2_integrity_flags,
{ "Flags", "smb2.integrity_flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_integrity_flags_enforcement_off,
{ "FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF", "smb2.integrity_flags_enforcement", FT_BOOLEAN, 32,
NULL, 0x1, "If checksum error enforcement is off", HFILL }},
{ &hf_smb2_share_type,
{ "Share Type", "smb2.share_type", FT_UINT8, BASE_HEX,
VALS(smb2_share_type_vals), 0, "Type of share", HFILL }},
{ &hf_smb2_credit_charge,
{ "Credit Charge", "smb2.credit.charge", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_credits_requested,
{ "Credits requested", "smb2.credits.requested", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_credits_granted,
{ "Credits granted", "smb2.credits.granted", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_channel_sequence,
{ "Channel Sequence", "smb2.channel_sequence", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_dialect_count,
{ "Dialect count", "smb2.dialect_count", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_dialect,
{ "Dialect", "smb2.dialect", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_security_mode,
{ "Security mode", "smb2.sec_mode", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_session_flags,
{ "Session Flags", "smb2.session_flags", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lock_count,
{ "Lock Count", "smb2.lock_count", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_capabilities,
{ "Capabilities", "smb2.capabilities", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ioctl_shadow_copy_count,
{ "Count", "smb2.ioctl.shadow_copy.count", FT_UINT32, BASE_DEC,
NULL, 0, "Number of bytes for shadow copy label strings", HFILL }},
{ &hf_smb2_auth_frame,
{ "Authenticated in Frame", "smb2.auth_frame", FT_UINT32, BASE_DEC,
NULL, 0, "Which frame this user was authenticated in", HFILL }},
{ &hf_smb2_tcon_frame,
{ "Connected in Frame", "smb2.tcon_frame", FT_UINT32, BASE_DEC,
NULL, 0, "Which frame this share was connected in", HFILL }},
{ &hf_smb2_tag,
{ "Tag", "smb2.tag", FT_STRING, BASE_NONE,
NULL, 0, "Tag of chain entry", HFILL }},
{ &hf_smb2_acct_name,
{ "Account", "smb2.acct", FT_STRING, BASE_NONE,
NULL, 0, "Account Name", HFILL }},
{ &hf_smb2_domain_name,
{ "Domain", "smb2.domain", FT_STRING, BASE_NONE,
NULL, 0, "Domain Name", HFILL }},
{ &hf_smb2_host_name,
{ "Host", "smb2.host", FT_STRING, BASE_NONE,
NULL, 0, "Host Name", HFILL }},
{ &hf_smb2_signature,
{ "Signature", "smb2.signature", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_unknown,
{ "unknown", "smb2.unknown", FT_BYTES, BASE_NONE,
NULL, 0, "Unknown bytes", HFILL }},
{ &hf_smb2_twrp_timestamp,
{ "Timestamp", "smb2.twrp_timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "TWrp timestamp", HFILL }},
{ &hf_smb2_mxac_timestamp,
{ "Timestamp", "smb2.mxac_timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "MxAc timestamp", HFILL }},
{ &hf_smb2_mxac_status,
{ "Query Status", "smb2.mxac_status", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&NT_errors_ext, 0, "NT Status code", HFILL }},
{ &hf_smb2_qfid_fid,
{ "Opaque File ID", "smb2.qfid_fid", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ses_flags_guest,
{ "Guest", "smb2.ses_flags.guest", FT_BOOLEAN, 16,
NULL, SES_FLAGS_GUEST, NULL, HFILL }},
{ &hf_smb2_ses_flags_null,
{ "Null", "smb2.ses_flags.null", FT_BOOLEAN, 16,
NULL, SES_FLAGS_NULL, NULL, HFILL }},
{ &hf_smb2_secmode_flags_sign_required,
{ "Signing required", "smb2.sec_mode.sign_required", FT_BOOLEAN, 8,
NULL, NEGPROT_SIGN_REQ, "Is signing required", HFILL }},
{ &hf_smb2_secmode_flags_sign_enabled,
{ "Signing enabled", "smb2.sec_mode.sign_enabled", FT_BOOLEAN, 8,
NULL, NEGPROT_SIGN_ENABLED, "Is signing enabled", HFILL }},
{ &hf_smb2_ses_req_flags,
{ "Flags", "smb2.ses_req_flags", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ses_req_flags_session_binding,
{ "Session Binding Request", "smb2.ses_req_flags.session_binding", FT_BOOLEAN, 8,
NULL, SES_REQ_FLAGS_SESSION_BINDING,
"The client wants to bind to an existing session", HFILL }},
{ &hf_smb2_cap_dfs,
{ "DFS", "smb2.capabilities.dfs", FT_BOOLEAN, 32,
TFS(&tfs_cap_dfs), NEGPROT_CAP_DFS, "If the host supports dfs", HFILL }},
{ &hf_smb2_cap_leasing,
{ "LEASING", "smb2.capabilities.leasing", FT_BOOLEAN, 32,
TFS(&tfs_cap_leasing), NEGPROT_CAP_LEASING,
"If the host supports leasing", HFILL }},
{ &hf_smb2_cap_large_mtu,
{ "LARGE MTU", "smb2.capabilities.large_mtu", FT_BOOLEAN, 32,
TFS(&tfs_cap_large_mtu), NEGPROT_CAP_LARGE_MTU,
"If the host supports LARGE MTU", HFILL }},
{ &hf_smb2_cap_multi_channel,
{ "MULTI CHANNEL", "smb2.capabilities.multi_channel", FT_BOOLEAN, 32,
TFS(&tfs_cap_multi_channel), NEGPROT_CAP_MULTI_CHANNEL,
"If the host supports MULTI CHANNEL", HFILL }},
{ &hf_smb2_cap_persistent_handles,
{ "PERSISTENT HANDLES", "smb2.capabilities.persistent_handles", FT_BOOLEAN, 32,
TFS(&tfs_cap_persistent_handles), NEGPROT_CAP_PERSISTENT_HANDLES,
"If the host supports PERSISTENT HANDLES", HFILL }},
{ &hf_smb2_cap_directory_leasing,
{ "DIRECTORY LEASING", "smb2.capabilities.directory_leasing", FT_BOOLEAN, 32,
TFS(&tfs_cap_directory_leasing), NEGPROT_CAP_DIRECTORY_LEASING,
"If the host supports DIRECTORY LEASING", HFILL }},
{ &hf_smb2_cap_encryption,
{ "ENCRYPTION", "smb2.capabilities.encryption", FT_BOOLEAN, 32,
TFS(&tfs_cap_encryption), NEGPROT_CAP_ENCRYPTION,
"If the host supports ENCRYPTION", HFILL }},
{ &hf_smb2_max_trans_size,
{ "Max Transaction Size", "smb2.max_trans_size", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum size of a transaction", HFILL }},
{ &hf_smb2_max_read_size,
{ "Max Read Size", "smb2.max_read_size", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum size of a read", HFILL }},
{ &hf_smb2_max_write_size,
{ "Max Write Size", "smb2.max_write_size", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum size of a write", HFILL }},
{ &hf_smb2_channel,
{ "Channel", "smb2.channel", FT_UINT32, BASE_HEX,
VALS(smb2_channel_vals), 0, NULL, HFILL }},
{ &hf_smb2_rdma_v1_offset,
{ "Offset", "smb2.buffer_descriptor.offset", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_rdma_v1_token,
{ "Token", "smb2.buffer_descriptor.token", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_rdma_v1_length,
{ "Length", "smb2.buffer_descriptor.length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_share_flags,
{ "Share flags", "smb2.share_flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_share_flags_dfs,
{ "DFS", "smb2.share_flags.dfs", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_dfs, "The specified share is present in a Distributed File System (DFS) tree structure", HFILL }},
{ &hf_smb2_share_flags_dfs_root,
{ "DFS root", "smb2.share_flags.dfs_root", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_dfs_root, "The specified share is present in a Distributed File System (DFS) tree structure", HFILL }},
{ &hf_smb2_share_flags_restrict_exclusive_opens,
{ "Restrict exclusive opens", "smb2.share_flags.restrict_exclusive_opens", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_restrict_exclusive_opens, "The specified share disallows exclusive file opens that deny reads to an open file", HFILL }},
{ &hf_smb2_share_flags_force_shared_delete,
{ "Force shared delete", "smb2.share_flags.force_shared_delete", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_force_shared_delete, "Shared files in the specified share can be forcibly deleted", HFILL }},
{ &hf_smb2_share_flags_allow_namespace_caching,
{ "Allow namepsace caching", "smb2.share_flags.allow_namespace_caching", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_allow_namespace_caching, "Clients are allowed to cache the namespace of the specified share", HFILL }},
{ &hf_smb2_share_flags_access_based_dir_enum,
{ "Access based directory enum", "smb2.share_flags.access_based_dir_enum", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_access_based_dir_enum, "The server will filter directory entries based on the access permissions of the client", HFILL }},
{ &hf_smb2_share_flags_force_levelii_oplock,
{ "Force level II oplock", "smb2.share_flags.force_levelii_oplock", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_force_levelii_oplock, "The server will not issue exclusive caching rights on this share", HFILL }},
{ &hf_smb2_share_flags_enable_hash_v1,
{ "Enable hash V1", "smb2.share_flags.enable_hash_v1", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_enable_hash_v1, "The share supports hash generation V1 for branch cache retrieval of data (see also section 2.2.31.2 of MS-SMB2)", HFILL }},
{ &hf_smb2_share_flags_enable_hash_v2,
{ "Enable hash V2", "smb2.share_flags.enable_hash_v2", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_enable_hash_v2, "The share supports hash generation V2 for branch cache retrieval of data (see also section 2.2.31.2 of MS-SMB2)", HFILL }},
{ &hf_smb2_share_flags_encrypt_data,
{ "Encrypted data required", "smb2.share_flags.encrypt_data", FT_BOOLEAN, 32,
NULL, SHARE_FLAGS_encryption_required, "The share require data encryption", HFILL }},
{ &hf_smb2_share_caching,
{ "Caching policy", "smb2.share.caching", FT_UINT32, BASE_HEX,
VALS(share_cache_vals), 0, NULL, HFILL }},
{ &hf_smb2_share_caps,
{ "Share Capabilities", "smb2.share_caps", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_share_caps_dfs,
{ "DFS", "smb2.share_caps.dfs", FT_BOOLEAN, 32,
NULL, SHARE_CAPS_DFS, "The specified share is present in a DFS tree structure", HFILL }},
{ &hf_smb2_share_caps_continuous_availability,
{ "CONTINUOUS AVAILABILITY", "smb2.share_caps.continuous_availability", FT_BOOLEAN, 32,
NULL, SHARE_CAPS_CONTINUOUS_AVAILABILITY,
"The specified share is continuously available", HFILL }},
{ &hf_smb2_share_caps_scaleout,
{ "SCALEOUT", "smb2.share_caps.scaleout", FT_BOOLEAN, 32,
NULL, SHARE_CAPS_SCALEOUT,
"The specified share is a scaleout share", HFILL }},
{ &hf_smb2_share_caps_cluster,
{ "CLUSTER", "smb2.share_caps.cluster", FT_BOOLEAN, 32,
NULL, SHARE_CAPS_CLUSTER,
"The specified share is a cluster share", HFILL }},
{ &hf_smb2_ioctl_flags,
{ "Flags", "smb2.ioctl.flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_min_count,
{ "Min Count", "smb2.min_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_remaining_bytes,
{ "Remaining Bytes", "smb2.remaining_bytes", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_smb2_channel_info_offset,
{ "Channel Info Offset", "smb2.channel_info_offset", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_channel_info_length,
{ "Channel Info Length", "smb2.channel_info_length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_channel_info_blob,
{ "Channel Info Blob", "smb2.channel_info_blob", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_ioctl_is_fsctl,
{ "Is FSCTL", "smb2.ioctl.is_fsctl", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_smb2_output_buffer_len,
{ "Output Buffer Length", "smb2.output_buffer_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_close_pq_attrib,
{ "PostQuery Attrib", "smb2.close.pq_attrib", FT_BOOLEAN, 16,
NULL, 0x0001, NULL, HFILL }},
{ &hf_smb2_notify_watch_tree,
{ "Watch Tree", "smb2.notify.watch_tree", FT_BOOLEAN, 16,
NULL, 0x0001, NULL, HFILL }},
{ &hf_smb2_notify_out_data,
{ "Out Data", "smb2.notify.out", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_notify_info,
{ "Notify Info", "smb2.notify.info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_notify_next_offset,
{ "Next Offset", "smb2.notify.next_offset", FT_UINT32, BASE_HEX,
NULL, 0, "Offset to next entry in chain or 0", HFILL }},
{ &hf_smb2_notify_action,
{ "Action", "smb2.notify.action", FT_UINT32, BASE_HEX,
VALS(notify_action_vals), 0, "Notify Action", HFILL }},
{ &hf_smb2_find_flags_restart_scans,
{ "Restart Scans", "smb2.find.restart_scans", FT_BOOLEAN, 8,
NULL, SMB2_FIND_FLAG_RESTART_SCANS, NULL, HFILL }},
{ &hf_smb2_find_flags_single_entry,
{ "Single Entry", "smb2.find.single_entry", FT_BOOLEAN, 8,
NULL, SMB2_FIND_FLAG_SINGLE_ENTRY, NULL, HFILL }},
{ &hf_smb2_find_flags_index_specified,
{ "Index Specified", "smb2.find.index_specified", FT_BOOLEAN, 8,
NULL, SMB2_FIND_FLAG_INDEX_SPECIFIED, NULL, HFILL }},
{ &hf_smb2_find_flags_reopen,
{ "Reopen", "smb2.find.reopen", FT_BOOLEAN, 8,
NULL, SMB2_FIND_FLAG_REOPEN, NULL, HFILL }},
{ &hf_smb2_file_index,
{ "File Index", "smb2.file_index", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_file_directory_info,
{ "FileDirectoryInfo", "smb2.find.file_directory_info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_full_directory_info,
{ "FullDirectoryInfo", "smb2.find.full_directory_info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_both_directory_info,
{ "FileBothDirectoryInfo", "smb2.find.both_directory_info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_id_both_directory_info,
{ "FileIdBothDirectoryInfo", "smb2.find.id_both_directory_info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_short_name_len,
{ "Short Name Length", "smb2.short_name_len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_short_name,
{ "Short Name", "smb2.shortname", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lock_info,
{ "Lock Info", "smb2.lock_info", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lock_length,
{ "Length", "smb2.lock_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lock_flags,
{ "Flags", "smb2.lock_flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_lock_flags_shared,
{ "Shared", "smb2.lock_flags.shared", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_smb2_lock_flags_exclusive,
{ "Exclusive", "smb2.lock_flags.exclusive", FT_BOOLEAN, 32,
NULL, 0x00000002, NULL, HFILL }},
{ &hf_smb2_lock_flags_unlock,
{ "Unlock", "smb2.lock_flags.unlock", FT_BOOLEAN, 32,
NULL, 0x00000004, NULL, HFILL }},
{ &hf_smb2_lock_flags_fail_immediately,
{ "Fail Immediately", "smb2.lock_flags.fail_immediately", FT_BOOLEAN, 32,
NULL, 0x00000010, NULL, HFILL }},
{ &hf_smb2_error_reserved,
{ "Reserved", "smb2.error.reserved", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_error_byte_count,
{ "Byte Count", "smb2.error.byte_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_error_data,
{ "Error Data", "smb2.error.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_reserved,
{ "Reserved", "smb2.reserved", FT_BYTES, BASE_NONE,
NULL, 0, "Reserved bytes", HFILL }},
{ &hf_smb2_reserved_random,
{ "Reserved (Random)", "smb2.reserved.random", FT_BYTES, BASE_NONE,
NULL, 0, "Reserved bytes, random data", HFILL }},
{ &hf_smb2_root_directory_mbz,
{ "Root Dir Handle (MBZ)", "smb2.root_directory", FT_BYTES, BASE_NONE,
NULL, 0, "Root Directory Handle, mbz", HFILL }},
{ &hf_smb2_dhnq_buffer_reserved,
{ "Reserved", "smb2.dhnq_buffer_reserved", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_dh2x_buffer_timeout,
{ "Timeout", "smb2.dh2x.timeout", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_dh2x_buffer_flags,
{ "Flags", "smb2.dh2x.flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_dh2x_buffer_flags_persistent_handle,
{ "Persistent Handle", "smb2.dh2x.flags.persistent_handle", FT_BOOLEAN, 32,
NULL, SMB2_DH2X_FLAGS_PERSISTENT_HANDLE, NULL, HFILL}},
{ &hf_smb2_dh2x_buffer_reserved,
{ "Reserved", "smb2.dh2x.reserved", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_dh2x_buffer_create_guid,
{ "Create Guid", "smb2.dh2x.create_guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_APP_INSTANCE_buffer_struct_size,
{ "Struct Size", "smb2.app_instance.struct_size", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_APP_INSTANCE_buffer_reserved,
{ "Reserved", "smb2.app_instance.reserved", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_APP_INSTANCE_buffer_app_guid,
{ "Application Guid", "smb2.app_instance.app_guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_svhdx_open_device_context_version,
{ "Version", "smb2.svhdx_open_device_context.version", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb2_svhdx_open_device_context_has_initiator_id,
{ "HasInitiatorId", "smb2.svhdx_open_device_context.initiator_has_id", FT_BOOLEAN, 8,
TFS(&tfs_smb2_svhdx_has_initiator_id), 0, "Whether the host has an intiator", HFILL}},
{ &hf_smb2_svhdx_open_device_context_reserved,
{ "Reserved", "smb2.svhdx_open_device_context.reserved", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_svhdx_open_device_context_initiator_id,
{ "InitiatorId", "smb2.svhdx_open_device_context.initiator_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_svhdx_open_device_context_flags,
{ "Flags", "smb2.svhdx_open_device_context.flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_svhdx_open_device_context_originator_flags,
{ "OriginatorFlags", "smb2.svhdx_open_device_context.originator_flags", FT_UINT32, BASE_HEX,
VALS(originator_flags_vals), 0, "Originator Flags", HFILL }},
{ &hf_smb2_svhdx_open_device_context_open_request_id,
{ "OpenRequestId","smb2.svhxd_open_device_context.open_request_id", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_svhdx_open_device_context_initiator_host_name_len,
{ "HostNameLength", "smb2.svhxd_open_device_context.initiator_host_name_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_svhdx_open_device_context_initiator_host_name,
{ "HostName", "smb2.svhdx_open_device_context.host_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_posix_v1_version,
{ "Version", "smb2.posix_v1_version", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_posix_v1_request,
{ "Request", "smb2.posix_request", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_posix_v1_case_sensitive,
{ "Posix Case Sensitive File Names", "smb2.posix_case_sensitive", FT_UINT32, BASE_HEX,
VALS(posix_case_sensitive_vals), 0x01, NULL, HFILL }},
{ &hf_smb2_posix_v1_posix_lock,
{ "Posix Byte-Range Locks", "smb2.posix_locks", FT_UINT32, BASE_HEX,
VALS(posix_locks_vals), 0x02, NULL, HFILL }},
{ &hf_smb2_posix_v1_posix_file_semantics,
{ "Posix File Semantics", "smb2.posix_file_semantics", FT_UINT32, BASE_HEX,
VALS(posix_file_semantics_vals), 0x04, NULL, HFILL }},
{ &hf_smb2_posix_v1_posix_utf8_paths,
{ "Posix UTF8 Paths", "smb2.posix_utf8_paths", FT_UINT32, BASE_HEX,
VALS(posix_utf8_paths_vals), 0x08, NULL, HFILL }},
{ &hf_smb2_posix_v1_posix_will_convert_nt_acls,
{ "Posix Will Convert NT ACLs", "smb2.will_convert_NTACLs", FT_UINT32, BASE_HEX,
VALS(posix_will_convert_ntacls_vals), 0x10, NULL, HFILL }},
{ &hf_smb2_posix_v1_posix_fileinfo,
{ "Posix Fileinfo", "smb2.posix_fileinfo", FT_UINT32, BASE_HEX,
VALS(posix_fileinfo_vals), 0x20, NULL, HFILL }},
{ &hf_smb2_posix_v1_posix_acls,
{ "Posix ACLs", "smb2.posix_acls", FT_UINT32, BASE_HEX,
VALS(posix_acls_vals), 0x40, NULL, HFILL }},
{ &hf_smb2_posix_v1_rich_acls,
{ "Rich ACLs", "smb2.rich_acls", FT_UINT32, BASE_HEX,
VALS(posix_rich_acls_vals), 0x80, NULL, HFILL }},
{ &hf_smb2_posix_v1_supported_features,
{ "Supported Features", "smb2.posix_supported_features", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_aapl_command_code,
{ "Command code", "smb2.aapl.command_code", FT_UINT32, BASE_DEC,
VALS(aapl_command_code_vals), 0, NULL, HFILL }},
{ &hf_smb2_aapl_reserved,
{ "Reserved", "smb2.aapl.reserved", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_bitmask,
{ "Query bitmask", "smb2.aapl.query_bitmask", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_bitmask_server_caps,
{ "Server capabilities", "smb2.aapl.bitmask.server_caps", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_SERVER_CAPS, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_bitmask_volume_caps,
{ "Volume capabilities", "smb2.aapl.bitmask.volume_caps", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_VOLUME_CAPS, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_bitmask_model_info,
{ "Model information", "smb2.aapl.bitmask.model_info", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_MODEL_INFO, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_caps,
{ "Client/Server capabilities", "smb2.aapl.caps", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_caps_supports_read_dir_attr,
{ "Supports READDIRATTR", "smb2.aapl.caps.supports_read_dir_addr", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_SUPPORTS_READ_DIR_ATTR, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_caps_supports_osx_copyfile,
{ "Supports OS X copyfile", "smb2.aapl.caps.supports_osx_copyfile", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_SUPPORTS_OSX_COPYFILE, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_caps_unix_based,
{ "UNIX-based", "smb2.aapl.caps.unix_based", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_UNIX_BASED, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_caps_supports_nfs_ace,
{ "Supports NFS ACE", "smb2.aapl.supports_nfs_ace", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_SUPPORTS_NFS_ACE, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_volume_caps,
{ "Volume capabilities", "smb2.aapl.volume_caps", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_volume_caps_support_resolve_id,
{ "Supports Resolve ID", "smb2.aapl.volume_caps.supports_resolve_id", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_SUPPORTS_RESOLVE_ID, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_volume_caps_case_sensitive,
{ "Case sensitive", "smb2.aapl.volume_caps.case_sensitive", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_CASE_SENSITIVE, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_volume_caps_supports_full_sync,
{ "Supports full sync", "smb2.aapl.volume_caps.supports_full_sync", FT_BOOLEAN, 64,
NULL, SMB2_AAPL_SUPPORTS_FULL_SYNC, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_model_string,
{ "Model string", "smb2.aapl.model_string", FT_UINT_STRING, STR_UNICODE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_aapl_server_query_server_path,
{ "Server path", "smb2.aapl.server_path", FT_UINT_STRING, STR_UNICODE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_transform_signature,
{ "Signature", "smb2.header.transform.signature", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_transform_nonce,
{ "Nonce", "smb2.header.transform.nonce", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_transform_msg_size,
{ "Message size", "smb2.header.transform.msg_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_transform_reserved,
{ "Reserved", "smb2.header.transform.reserved", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_transform_enc_alg,
{ "Encryption ALG", "smb2.header.transform.encryption_alg", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_encryption_aes128_ccm,
{ "SMB2_ENCRYPTION_AES128_CCM", "smb2.header.transform.enc_aes128_ccm", FT_BOOLEAN, 16,
NULL, ENC_ALG_aes128_ccm, NULL, HFILL }},
{ &hf_smb2_transform_encrypted_data,
{ "Data", "smb2.header.transform.enc_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_server_component_smb2,
{ "Server Component: SMB2", "smb2.server_component_smb2", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_server_component_smb2_transform,
{ "Server Component: SMB2_TRANSFORM", "smb2.server_component_smb2_transform", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_truncated,
{ "Truncated...", "smb2.truncated", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb2_pipe_fragment_overlap,
{ "Fragment overlap", "smb2.pipe.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
{ &hf_smb2_pipe_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "smb2.pipe.fragment.overlap.conflict", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Overlapping fragments contained conflicting data", HFILL }},
{ &hf_smb2_pipe_fragment_multiple_tails,
{ "Multiple tail fragments found", "smb2.pipe.fragment.multipletails", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Several tails were found when defragmenting the packet", HFILL }},
{ &hf_smb2_pipe_fragment_too_long_fragment,
{ "Fragment too long", "smb2.pipe.fragment.toolongfragment", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Fragment contained data past end of packet", HFILL }},
{ &hf_smb2_pipe_fragment_error,
{ "Defragmentation error", "smb2.pipe.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x0, "Defragmentation error due to illegal fragments", HFILL }},
{ &hf_smb2_pipe_fragment_count,
{ "Fragment count", "smb2.pipe.fragment.count", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_pipe_fragment,
{ "Fragment SMB2 Named Pipe", "smb2.pipe.fragment", FT_FRAMENUM,
BASE_NONE, NULL, 0x0, "SMB2 Named Pipe Fragment", HFILL }},
{ &hf_smb2_pipe_fragments,
{ "Reassembled SMB2 Named Pipe fragments", "smb2.pipe.fragments", FT_NONE,
BASE_NONE, NULL, 0x0, "SMB2 Named Pipe Fragments", HFILL }},
{ &hf_smb2_pipe_reassembled_in,
{ "This SMB2 Named Pipe payload is reassembled in frame", "smb2.pipe.reassembled_in", FT_FRAMENUM,
BASE_NONE, NULL, 0x0, "The Named Pipe PDU is completely reassembled in this frame", HFILL }},
{ &hf_smb2_pipe_reassembled_length,
{ "Reassembled SMB2 Named Pipe length", "smb2.pipe.reassembled.length", FT_UINT32,
BASE_DEC, NULL, 0x0, "The total length of the reassembled payload", HFILL }},
{ &hf_smb2_pipe_reassembled_data,
{ "Reassembled SMB2 Named Pipe Data", "smb2.pipe.reassembled.data", FT_BYTES,
BASE_NONE, NULL, 0x0, "The reassembled payload", HFILL }},
{ &hf_smb2_cchunk_resume_key,
{ "ResumeKey", "smb2.fsctl.cchunk.resume_key", FT_BYTES,
BASE_NONE, NULL, 0x0, "Opaque data representing source of copy", HFILL }},
{ &hf_smb2_cchunk_count,
{ "Chunk Count", "smb2.fsctl.cchunk.count", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_cchunk_src_offset,
{ "Source Offset", "smb2.fsctl.cchunk.src_offset", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_cchunk_dst_offset,
{ "Target Offset", "smb2.fsctl.cchunk.dst_offset", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_cchunk_xfer_len,
{ "Transfer Length", "smb2.fsctl.cchunk.xfer_len", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_cchunk_chunks_written,
{ "Chunks Written", "smb2.fsctl.cchunk.chunks_written", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_cchunk_bytes_written,
{ "Chunk Bytes Written", "smb2.fsctl.cchunk.bytes_written", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb2_cchunk_total_written,
{ "Total Bytes Written", "smb2.fsctl.cchunk.total_written", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_smb2,
&ett_smb2_ea,
&ett_smb2_olb,
&ett_smb2_header,
&ett_smb2_encrypted,
&ett_smb2_command,
&ett_smb2_secblob,
&ett_smb2_negotiate_context_element,
&ett_smb2_file_basic_info,
&ett_smb2_file_standard_info,
&ett_smb2_file_internal_info,
&ett_smb2_file_ea_info,
&ett_smb2_file_access_info,
&ett_smb2_file_rename_info,
&ett_smb2_file_disposition_info,
&ett_smb2_file_position_info,
&ett_smb2_file_full_ea_info,
&ett_smb2_file_mode_info,
&ett_smb2_file_alignment_info,
&ett_smb2_file_all_info,
&ett_smb2_file_allocation_info,
&ett_smb2_file_endoffile_info,
&ett_smb2_file_alternate_name_info,
&ett_smb2_file_stream_info,
&ett_smb2_file_pipe_info,
&ett_smb2_file_compression_info,
&ett_smb2_file_network_open_info,
&ett_smb2_file_attribute_tag_info,
&ett_smb2_fs_info_01,
&ett_smb2_fs_info_03,
&ett_smb2_fs_info_04,
&ett_smb2_fs_info_05,
&ett_smb2_fs_info_06,
&ett_smb2_fs_info_07,
&ett_smb2_fs_objectid_info,
&ett_smb2_sec_info_00,
&ett_smb2_tid_tree,
&ett_smb2_sesid_tree,
&ett_smb2_create_chain_element,
&ett_smb2_MxAc_buffer,
&ett_smb2_QFid_buffer,
&ett_smb2_RqLs_buffer,
&ett_smb2_ioctl_function,
&ett_smb2_FILE_OBJECTID_BUFFER,
&ett_smb2_flags,
&ett_smb2_sec_mode,
&ett_smb2_capabilities,
&ett_smb2_ses_req_flags,
&ett_smb2_ses_flags,
&ett_smb2_create_rep_flags,
&ett_smb2_lease_state,
&ett_smb2_lease_flags,
&ett_smb2_share_flags,
&ett_smb2_share_caps,
&ett_smb2_ioctl_flags,
&ett_smb2_ioctl_network_interface,
&ett_smb2_fsctl_range_data,
&ett_windows_sockaddr,
&ett_smb2_close_flags,
&ett_smb2_notify_info,
&ett_smb2_notify_flags,
&ett_smb2_rdma_v1,
&ett_smb2_write_flags,
&ett_smb2_find_flags,
&ett_smb2_file_directory_info,
&ett_smb2_both_directory_info,
&ett_smb2_id_both_directory_info,
&ett_smb2_full_directory_info,
&ett_smb2_file_name_info,
&ett_smb2_lock_info,
&ett_smb2_lock_flags,
&ett_smb2_DH2Q_buffer,
&ett_smb2_DH2C_buffer,
&ett_smb2_dh2x_flags,
&ett_smb2_APP_INSTANCE_buffer,
&ett_smb2_svhdx_open_device_context,
&ett_smb2_posix_v1_request,
&ett_smb2_posix_v1_response,
&ett_smb2_posix_v1_supported_features,
&ett_smb2_aapl_create_context_request,
&ett_smb2_aapl_server_query_bitmask,
&ett_smb2_aapl_server_query_caps,
&ett_smb2_aapl_create_context_response,
&ett_smb2_aapl_server_query_volume_caps,
&ett_smb2_integrity_flags,
&ett_smb2_transform_enc_alg,
&ett_smb2_buffercode,
&ett_smb2_ioctl_network_interface_capabilities,
&ett_qfr_entry,
&ett_smb2_pipe_fragment,
&ett_smb2_pipe_fragments,
&ett_smb2_cchunk_entry,
&ett_smb2_fsctl_odx_token,
};
static ei_register_info ei[] = {
{ &ei_smb2_invalid_length, { "smb2.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_smb2_bad_response, { "smb2.bad_response", PI_MALFORMED, PI_ERROR, "Bad response", EXPFILL }},
};
expert_module_t* expert_smb2;
proto_smb2 = proto_register_protocol("SMB2 (Server Message Block Protocol version 2)",
"SMB2", "smb2");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_smb2, hf, array_length(hf));
expert_smb2 = expert_register_protocol(proto_smb2);
expert_register_field_array(expert_smb2, ei, array_length(ei));
smb2_module = prefs_register_protocol(proto_smb2, NULL);
prefs_register_bool_preference(smb2_module, "eosmb2_take_name_as_fid",
"Use the full file name as File ID when exporting an SMB2 object",
"Whether the export object functionality will take the full path file name as file identifier",
&eosmb2_take_name_as_fid);
prefs_register_bool_preference(smb2_module, "pipe_reassembly",
"Reassemble Named Pipes over SMB2",
"Whether the dissector should reassemble Named Pipes over SMB2 commands",
&smb2_pipe_reassembly);
smb2_pipe_subdissector_list = register_heur_dissector_list("smb2_pipe_subdissectors", proto_smb2);
register_init_routine(smb2_pipe_reassembly_init);
smb2_tap = register_tap("smb2");
smb2_eo_tap = register_tap("smb_eo");
register_srt_table(proto_smb2, NULL, 1, smb2stat_packet, smb2stat_init, NULL);
}
void
proto_reg_handoff_smb2(void)
{
gssapi_handle = find_dissector_add_dependency("gssapi", proto_smb2);
ntlmssp_handle = find_dissector_add_dependency("ntlmssp", proto_smb2);
rsvd_handle = find_dissector_add_dependency("rsvd", proto_smb2);
heur_dissector_add("netbios", dissect_smb2_heur, "SMB2 over Netbios", "smb2_netbios", proto_smb2, HEURISTIC_ENABLE);
heur_dissector_add("smb_direct", dissect_smb2_heur, "SMB2 over SMB Direct", "smb2_smb_direct", proto_smb2, HEURISTIC_ENABLE);
}
