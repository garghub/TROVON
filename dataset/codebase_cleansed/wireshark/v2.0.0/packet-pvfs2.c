static int dissect_pvfs_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_pvfs_common(tvb, pinfo, tree, FALSE);
return tvb_reported_length(tvb);
}
static guint get_pvfs_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 plen;
plen = tvb_get_letohl(tvb, offset + 16);
return plen+24;
}
static int
dissect_pvfs_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint32 magic_nr, mode;
guint64 size;
if(tvb_reported_length(tvb)<24){
return 0;
}
magic_nr = tvb_get_letohl(tvb, 0);
if(magic_nr!=BMI_MAGIC_NR){
return 0;
}
mode = tvb_get_letohl(tvb, 4);
switch(mode){
case TCP_MODE_IMMED:
case TCP_MODE_UNEXP:
case TCP_MODE_EAGER:
case TCP_MODE_REND:
break;
default:
return 0;
}
size=tvb_get_letohl(tvb, 20);
size<<=32;
size|=tvb_get_letohl(tvb, 16);
if((size>1000000)||(size==0)){
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, pvfs_desegment, 24, get_pvfs_pdu_len,
dissect_pvfs_pdu, data);
return tvb_reported_length(tvb);
}
static int
dissect_pvfs2_error(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
gint32 err;
const char *errmsg = NULL;
err = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_pvfs_error, tvb, offset, 4, -err);
offset += 4;
if (err != 0)
{
errmsg = val_to_str(-err, names_pvfs_error, "Unknown error: %u");
col_append_fstr(pinfo->cinfo, COL_INFO, " Error: %s", errmsg);
}
return offset;
}
static int
dissect_pvfs_credentials(tvbuff_t *tvb, proto_tree *parent_tree,
int offset)
{
proto_tree *hcred_tree;
guint32 uid, gid;
uid = tvb_get_letohl(tvb, offset);
gid = tvb_get_letohl(tvb, offset + 4);
hcred_tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, 8,
ett_pvfs_credentials, NULL, "Credentials (UID: %d, GID: %d)", uid, gid);
proto_tree_add_item(hcred_tree, hf_pvfs_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(hcred_tree, hf_pvfs_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_attrmask(tvbuff_t *tvb, proto_tree *tree, int offset,
guint32 *pattrmask)
{
guint32 attrmask, i;
proto_item *attritem;
proto_tree *attrtree;
attrmask = tvb_get_letohl(tvb, offset);
attritem = proto_tree_add_uint(tree, hf_pvfs_attrmask, tvb, offset, 4, attrmask);
attrtree = proto_item_add_subtree(attritem, ett_pvfs_attrmask);
for (i = 0; i < 32; i++)
{
if (attrmask & (1 << i))
proto_tree_add_uint(attrtree, hf_pvfs_attr, tvb, offset, 4, i);
}
offset += 4;
if (pattrmask)
*pattrmask = attrmask;
return offset;
}
static int
dissect_pvfs2_ds_type(tvbuff_t *tvb, proto_tree *tree, int offset,
int *pds_type)
{
guint32 ds_type;
ds_type = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_pvfs_ds_type, tvb, offset, 4, ds_type);
offset += 4;
if (pds_type)
*pds_type = ds_type;
return offset;
}
static int
dissect_pvfs_opaque_data(tvbuff_t *tvb, int offset,
proto_tree *tree,
packet_info *pinfo _U_,
int hfindex,
gboolean fixed_length, guint32 length,
gboolean string_data, const char **string_buffer_ret)
{
int data_offset;
proto_item *string_item = NULL;
proto_tree *string_tree = NULL;
guint32 string_length;
guint32 string_length_full;
guint32 string_length_packet;
guint32 string_length_captured;
guint32 string_length_copy;
int fill_truncated;
guint32 fill_length;
guint32 fill_length_packet;
guint32 fill_length_captured;
guint32 fill_length_copy;
int exception = 0;
char *string_buffer = NULL;
const char *string_buffer_print = NULL;
if (fixed_length) {
string_length = length;
data_offset = offset;
} else {
string_length = tvb_get_letohl(tvb,offset+0);
data_offset = offset + 4;
if (string_data)
string_length += 1;
}
string_length_captured = tvb_captured_length_remaining(tvb, data_offset);
string_length_packet = tvb_reported_length_remaining(tvb, data_offset);
if (!string_data)
string_length_full = roundup4(string_length);
else
string_length_full = roundup8(4 + string_length);
if (string_length_captured < string_length) {
string_length_copy = string_length_captured;
fill_truncated = 2;
fill_length = 0;
fill_length_copy = 0;
if (string_length_packet < string_length)
exception = ReportedBoundsError;
else
exception = BoundsError;
}
else {
string_length_copy = string_length;
if (!string_data)
fill_length = string_length_full - string_length;
else
fill_length = string_length_full - string_length - 4;
fill_length_captured = tvb_captured_length_remaining(tvb,
data_offset + string_length);
fill_length_packet = tvb_reported_length_remaining(tvb,
data_offset + string_length);
if (fill_length_captured < fill_length) {
fill_length_copy = fill_length_packet;
fill_truncated = 1;
if (fill_length_packet < fill_length)
exception = ReportedBoundsError;
else
exception = BoundsError;
}
else {
fill_length_copy = fill_length;
fill_truncated = 0;
}
}
if (string_data) {
char *tmpstr;
tmpstr = (char *) tvb_get_string_enc(wmem_packet_scope(), tvb, data_offset,
string_length_copy, ENC_ASCII);
string_buffer = (char *)memcpy(wmem_alloc(wmem_packet_scope(), string_length_copy+1), tmpstr, string_length_copy);
} else {
string_buffer = (char *) tvb_memcpy(tvb,
wmem_alloc(wmem_packet_scope(), string_length_copy+1), data_offset, string_length_copy);
}
string_buffer[string_length_copy] = '\0';
if (string_length) {
if (string_length != string_length_copy) {
if (string_data) {
char *formatted;
size_t string_buffer_size = 0;
char *string_buffer_temp;
formatted = format_text((guint8 *)string_buffer,
(int)strlen(string_buffer));
string_buffer_size = strlen(formatted) + 12 + 1;
string_buffer_temp = (char*) wmem_alloc(wmem_packet_scope(), string_buffer_size);
g_snprintf(string_buffer_temp, (gulong)string_buffer_size,
"%s<TRUNCATED>", formatted);
string_buffer_print = string_buffer_temp;
} else {
string_buffer_print="<DATA><TRUNCATED>";
}
} else {
if (string_data) {
string_buffer_print =
wmem_strdup(wmem_packet_scope(), format_text((guint8 *) string_buffer,
(int)strlen(string_buffer)));
} else {
string_buffer_print="<DATA>";
}
}
} else {
string_buffer_print="<EMPTY>";
}
string_item = proto_tree_add_string(tree, hfindex, tvb, offset+0, -1,
string_buffer_print);
string_tree = proto_item_add_subtree(string_item,
ett_pvfs_string);
if (!fixed_length) {
proto_tree_add_uint_format_value(string_tree, hf_pvfs_opaque_length, tvb, offset, 4,
string_length - 1, "%u (excl. NULL terminator)", string_length - 1);
offset += 4;
}
if (string_data) {
proto_tree_add_string_format(string_tree,
hfindex, tvb, offset, string_length_copy,
string_buffer,
"contents: %s", string_buffer_print);
} else {
proto_tree_add_bytes_format(string_tree,
hfindex, tvb, offset, string_length_copy,
(guint8 *) string_buffer,
"contents: %s", string_buffer_print);
}
offset += string_length_copy;
if (fill_length) {
if (string_tree) {
if (fill_truncated) {
proto_tree_add_bytes_format_value(string_tree, hf_pvfs_fill_bytes, tvb,
offset, fill_length_copy, NULL,
"opaque data <TRUNCATED>");
}
else {
proto_tree_add_bytes_format_value(string_tree, hf_pvfs_fill_bytes, tvb,
offset, fill_length_copy, NULL,
"opaque data");
}
}
offset += fill_length_copy;
}
if (string_item)
proto_item_set_end(string_item, tvb, offset);
if (string_buffer_ret != NULL)
*string_buffer_ret = string_buffer_print;
if (exception != 0)
THROW(exception);
return offset;
}
static int
dissect_pvfs_string(tvbuff_t *tvb, proto_tree *tree, int hfindex,
int offset, const char **string_buffer_ret)
{
return dissect_pvfs_opaque_data(tvb, offset, tree, NULL, hfindex,
FALSE, 0, TRUE, string_buffer_ret);
}
static void
dissect_fhandle_data_unknown(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint bytes_left = PVFS2_FH_LENGTH;
proto_tree_add_item(tree, hf_fhandle_data, tvb, offset, bytes_left, ENC_NA);
}
static void
dissect_fhandle_data(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint32 *hash)
{
guint32 fhhash;
guint32 i;
if (!tvb_bytes_exist(tvb, offset, PVFS2_FH_LENGTH))
goto type_ready;
for(fhhash=0,i=0;i<(PVFS2_FH_LENGTH-3);i+=4){
guint32 val;
val = tvb_get_ntohl(tvb, offset+i);
fhhash ^= val;
fhhash += val;
}
proto_tree_add_uint(tree, hf_pvfs_fh_hash, tvb, offset, PVFS2_FH_LENGTH,
fhhash);
if (hash)
*hash = fhhash;
type_ready:
dissect_fhandle_data_unknown(tvb, offset, tree);
}
static int
dissect_pvfs_fh(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, const char *name, guint32 *hash)
{
proto_tree* ftree;
ftree = proto_tree_add_subtree(tree, tvb, offset, PVFS2_FH_LENGTH,
ett_pvfs_fh, NULL, name);
proto_tree_add_uint(ftree, hf_pvfs_fh_length, tvb, offset, 0,
PVFS2_FH_LENGTH);
dissect_fhandle_data(tvb, offset, pinfo, ftree, hash);
offset += PVFS2_FH_LENGTH;
return offset;
}
static int
dissect_pvfs_handle_extent(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo, guint32 nCount)
{
proto_tree *extent_tree;
extent_tree = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_pvfs_extent_item, NULL, "Item %d", nCount);
offset = dissect_pvfs_fh(tvb, offset, pinfo, extent_tree, "first handle",
NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, extent_tree, "last handle",
NULL);
return offset;
}
static int
dissect_pvfs_handle_extent_array(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
guint32 extent_count;
guint32 nCount;
proto_tree *extent_array_tree;
extent_count = tvb_get_letohl(tvb, offset);
extent_array_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4,
ett_pvfs_extent_array_tree, NULL, "Handle Extent Array (count = %d)", extent_count);
offset += 4;
if (extent_count > 0)
{
for (nCount = 0; nCount < extent_count; nCount++)
offset = dissect_pvfs_handle_extent(tvb, extent_array_tree, offset,
pinfo, nCount);
}
return offset;
}
static int
dissect_pvfs_time(tvbuff_t *tvb, proto_tree *tree, int offset,
int hf_time, int hf_time_sec, int hf_time_nsec)
{
guint32 seconds;
guint32 nseconds;
nstime_t ts;
proto_item *time_item;
proto_tree *time_tree;
ts.secs = seconds = tvb_get_letohl(tvb, offset);
ts.nsecs = nseconds = tvb_get_letohl(tvb, offset + 4);
time_item = proto_tree_add_time(tree, hf_time, tvb, offset, 8, &ts);
time_tree = proto_item_add_subtree(time_item, ett_pvfs_time);
proto_tree_add_uint(time_tree, hf_time_sec, tvb, offset, 4, seconds);
proto_tree_add_uint(time_tree, hf_time_nsec, tvb, offset + 4, 4, nseconds);
offset += 8;
return offset;
}
static
int dissect_pvfs_uint64(tvbuff_t *tvb, proto_tree *tree, int offset,
int hfindex, guint64 *pvalue)
{
guint64 val;
val = ((guint64) tvb_get_letohl(tvb, offset + 4)) << 32 |
tvb_get_letohl(tvb, offset);
proto_tree_add_uint64(tree, hfindex, tvb, offset, 8, val);
if (pvalue)
*pvalue = val;
return offset + 8;
}
static int
dissect_pvfs_distribution(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *dist_item = NULL;
proto_tree *dist_tree = NULL;
guint32 distlen = 0;
char *tmpstr = NULL;
guint8 issimplestripe = 0;
distlen = tvb_get_letohl(tvb, offset);
tmpstr = (char *) tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 4, distlen, ENC_ASCII);
if (tree)
{
guint32 total_len;
total_len = roundup8(4 + distlen + 1);
if (((distlen + 1) == PVFS_DIST_SIMPLE_STRIPE_NAME_SIZE) &&
(g_ascii_strncasecmp(tmpstr, PVFS_DIST_SIMPLE_STRIPE_NAME,
distlen) == 0))
{
total_len += 8;
issimplestripe = 1;
}
dist_item = proto_tree_add_string(tree, hf_pvfs_distribution, tvb, offset,
total_len + 8, tmpstr);
dist_tree = proto_item_add_subtree(dist_item, ett_pvfs_distribution);
}
offset = dissect_pvfs_string(tvb, dist_tree, hf_pvfs_io_dist, offset,
NULL);
if (issimplestripe)
offset = dissect_pvfs_uint64(tvb, dist_tree, offset,
hf_pvfs_strip_size, NULL);
offset += 8;
return offset;
}
static int
dissect_pvfs_meta_attr_dfiles(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
guint32 dfile_count, i;
dfile_count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_pvfs_dfile_count, tvb, offset, 4, dfile_count);
offset += 4;
for (i = 0; i < dfile_count; i++)
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs_object_attr(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
gint32 ds_type = 0;
guint32 attrmask = 0;
proto_tree *attr_tree;
attr_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_pvfs_attr_tree, NULL, "Attributes");
proto_tree_add_item(attr_tree, hf_pvfs_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(attr_tree, hf_pvfs_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(attr_tree, hf_pvfs_permissions, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset = dissect_pvfs_time(tvb, attr_tree, offset, hf_pvfs_atime,
hf_pvfs_atime_sec, hf_pvfs_atime_nsec);
offset = dissect_pvfs_time(tvb, attr_tree, offset, hf_pvfs_mtime,
hf_pvfs_mtime_sec, hf_pvfs_mtime_nsec);
offset = dissect_pvfs_time(tvb, attr_tree, offset, hf_pvfs_ctime,
hf_pvfs_ctime_sec, hf_pvfs_ctime_nsec);
offset = dissect_pvfs2_attrmask(tvb, attr_tree, offset, &attrmask);
offset = dissect_pvfs2_ds_type(tvb, attr_tree, offset, &ds_type);
if (attrmask & PVFS_ATTR_META_DIST)
{
offset = dissect_pvfs_distribution(tvb, attr_tree, offset);
offset = dissect_pvfs_meta_attr_dfiles(tvb, attr_tree, offset, pinfo);
}
else
{
if (attrmask & PVFS_ATTR_META_DFILES)
{
offset = dissect_pvfs_meta_attr_dfiles(tvb, attr_tree, offset, pinfo);
}
else
{
if (attrmask & PVFS_ATTR_DATA_SIZE)
{
offset = dissect_pvfs_uint64(tvb, attr_tree, offset, hf_pvfs_size,
NULL);
}
else
{
if (attrmask & PVFS_ATTR_SYMLNK_TARGET)
{
proto_tree_add_item(attr_tree, hf_pvfs_target_path_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset = dissect_pvfs_string(tvb, attr_tree, hf_pvfs_path,
offset, NULL);
}
else
{
if (attrmask & PVFS_ATTR_DIR_DIRENT_COUNT)
{
offset = dissect_pvfs_uint64(tvb, attr_tree, offset,
hf_pvfs_size, NULL);
}
}
}
}
}
return offset;
}
static int
dissect_pvfs_io_type(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_pvfs_io_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs_flowproto_type(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_pvfs_flowproto_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs_server_param(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
guint32 server_param;
proto_item* ti;
server_param = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_pvfs_server_param, tvb, offset, 4,
server_param);
offset += 4;
switch (server_param)
{
case PVFS_SERV_PARAM_MODE:
ti = proto_tree_add_item(tree, hf_pvfs_server_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_set_len(ti, 8);
break;
case PVFS_SERV_PARAM_FSID_CHECK:
proto_tree_add_item(tree, hf_pvfs_fs_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_pvfs_unused, tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
break;
case PVFS_SERV_PARAM_ROOT_CHECK:
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
break;
}
offset += 8;
return offset;
}
static int
dissect_pvfs_fs_id(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_pvfs_fs_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_create_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs2_ds_type(tvb, tree, offset, NULL);
offset += 4;
offset = dissect_pvfs_handle_extent_array(tvb, tree, offset, pinfo);
return offset;
}
static int
dissect_pvfs2_remove_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs_pint_request(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_pvfs_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_num_eregs, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_num_blocks, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_stride, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_ub, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_lb, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_aggregate_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_num_contig_chunks, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_depth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_num_nested_req, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_committed, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_refcount, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_pvfs_ereg, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_sreg, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_io_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_io_type(tvb, tree, offset);
offset = dissect_pvfs_flowproto_type(tvb, tree, offset);
proto_tree_add_item(tree, hf_pvfs_server_nr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_server_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_pvfs_distribution(tvb, tree, offset);
proto_tree_add_item(tree, hf_pvfs_numreq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
dissect_pvfs_pint_request(tvb, tree, offset);
offset = tvb_reported_length(tvb) - 16;
proto_tree_add_item(tree, hf_pvfs_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_pvfs2_getattr_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs2_attrmask(tvb, tree, offset, NULL);
return offset;
}
static int
dissect_pvfs2_setattr_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_object_attr(tvb, tree, offset, pinfo);
return offset;
}
static int
dissect_pvfs2_lookup_path_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_path, offset, NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs2_attrmask(tvb, tree, offset, NULL);
return offset;
}
static int
dissect_pvfs2_crdirent_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_path, offset, NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "file handle", NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "parent handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_atime,
hf_pvfs_atime_sec, hf_pvfs_atime_nsec);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_mtime,
hf_pvfs_mtime_sec, hf_pvfs_mtime_nsec);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_ctime,
hf_pvfs_ctime_sec, hf_pvfs_ctime_nsec);
return offset;
}
static int
dissect_pvfs2_rmdirent_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_path, offset, NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_atime,
hf_pvfs_atime_sec, hf_pvfs_atime_nsec);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_mtime,
hf_pvfs_mtime_sec, hf_pvfs_mtime_nsec);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_ctime,
hf_pvfs_ctime_sec, hf_pvfs_ctime_nsec);
return offset;
}
static int
dissect_pvfs2_chdirent_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_path, offset, NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "new directory handle",
NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "parent handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_parent_atime,
hf_pvfs_parent_atime_sec, hf_pvfs_parent_atime_nsec);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_parent_mtime,
hf_pvfs_parent_mtime_sec, hf_pvfs_parent_mtime_nsec);
offset = dissect_pvfs_time(tvb, tree, offset, hf_pvfs_parent_ctime,
hf_pvfs_parent_ctime_sec, hf_pvfs_parent_ctime_nsec);
return offset;
}
static int
dissect_pvfs2_truncate_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_pvfs_truncate_request_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_mkdir_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
guint count, i;
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_object_attr(tvb, tree, offset, pinfo);
count = tvb_get_letohl(tvb, offset);
offset += 4;
for (i = 0; i < count; i++)
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_readdir_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
proto_tree_add_item(tree, hf_pvfs_ds_position, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_dirent_limit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_flush_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
proto_tree_add_item(tree, hf_pvfs_flush_request_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_mgmt_setparam_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs_server_param(tvb, tree, offset, pinfo);
return offset;
}
static int
dissect_pvfs2_statfs_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo _U_)
{
offset = dissect_pvfs_fs_id(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_mgmt_perf_mon_request(tvbuff_t *tvb _U_, proto_tree *tree _U_,
int offset, packet_info *pinfo _U_)
{
proto_tree_add_item(tree, hf_pvfs_next_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_mgmt_perf_mon_request_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_mgmt_iterate_handles_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_mgmt_dspace_info_list_request(tvbuff_t *tvb,
proto_tree *tree, int offset, packet_info *pinfo)
{
guint32 handle_count, i;
offset = dissect_pvfs_fs_id(tvb, tree, offset);
handle_count = tvb_get_letohl(tvb, offset);
offset += 4;
for (i = 0; i < handle_count; i++)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
}
return offset;
}
static int
dissect_pvfs2_mgmt_event_mon_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo _U_)
{
proto_tree_add_item(tree, hf_pvfs_mgmt_perf_mon_request_event_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_mgmt_remove_object_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_mgmt_remove_dirent_request(tvbuff_t *tvb,
proto_tree *tree, int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_path, offset, NULL);
return offset;
}
static int
dissect_pvfs2_mgmt_get_dirdata_handle_request(tvbuff_t *tvb,
proto_tree *tree, int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs_ds_keyval(tvbuff_t *tvb, proto_tree *tree, int offset)
{
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_attribute_key, offset,
NULL);
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_attribute_value, offset,
NULL);
return offset;
}
static int
dissect_ds_keyval_array(tvbuff_t *tvb, proto_tree *tree, int offset)
{
guint32 nKey, i;
nKey = tvb_get_letohl(tvb, offset);
offset += 4;
for (i = 0; i < nKey; i++)
offset = dissect_pvfs_ds_keyval(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_geteattr_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_ds_keyval_array(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_seteattr_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset += 4;
offset = dissect_ds_keyval_array(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_deleattr_request(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs_ds_keyval(tvb, tree, offset);
return offset;
}
static void
pvfc_fmt_release_num(gchar *result, guint32 release_nr)
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d (%d.%d.%d)",
release_nr,
release_nr / 10000,
(release_nr % 10000) / 100,
(release_nr % 10000) % 100);
}
static int
dissect_pvfs2_common_header(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_pvfs_release_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_encoding, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_server_op, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_pvfs2_request(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo, guint32 server_op)
{
proto_tree_add_item(tree, hf_pvfs_context_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_pvfs_credentials(tvb, tree, offset);
switch (server_op)
{
case PVFS_SERV_CREATE:
offset = dissect_pvfs2_create_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_REMOVE:
offset = dissect_pvfs2_remove_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_IO:
offset = dissect_pvfs2_io_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_GETATTR:
offset = dissect_pvfs2_getattr_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_SETATTR:
offset = dissect_pvfs2_setattr_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_LOOKUP_PATH:
offset = dissect_pvfs2_lookup_path_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_CRDIRENT:
offset = dissect_pvfs2_crdirent_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_RMDIRENT:
offset = dissect_pvfs2_rmdirent_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_CHDIRENT:
offset = dissect_pvfs2_chdirent_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_TRUNCATE:
offset = dissect_pvfs2_truncate_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_MKDIR:
offset = dissect_pvfs2_mkdir_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_READDIR:
offset = dissect_pvfs2_readdir_request(tvb, tree, offset, pinfo);
break;
#if 0
case PVFS_SERV_GETCONFIG:
break;
#endif
#if 0
case PVFS_SERV_WRITE_COMPLETION:
break;
#endif
case PVFS_SERV_FLUSH:
offset = dissect_pvfs2_flush_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_MGMT_SETPARAM:
offset = dissect_pvfs2_mgmt_setparam_request(tvb, tree, offset,
pinfo);
break;
#if 0
case PVFS_SERV_MGMT_NOOP:
break;
#endif
case PVFS_SERV_STATFS:
offset = dissect_pvfs2_statfs_request(tvb, tree, offset, pinfo);
break;
#if 0
case PVFS_SERV_PERF_UPDATE:
break;
#endif
case PVFS_SERV_MGMT_PERF_MON:
offset = dissect_pvfs2_mgmt_perf_mon_request(tvb, tree, offset,
pinfo);
break;
case PVFS_SERV_MGMT_ITERATE_HANDLES:
offset = dissect_pvfs2_mgmt_iterate_handles_request(tvb, tree,
offset, pinfo);
break;
case PVFS_SERV_MGMT_DSPACE_INFO_LIST:
offset = dissect_pvfs2_mgmt_dspace_info_list_request(tvb, tree,
offset, pinfo);
break;
case PVFS_SERV_MGMT_EVENT_MON:
offset = dissect_pvfs2_mgmt_event_mon_request(tvb, tree, offset,
pinfo);
break;
case PVFS_SERV_MGMT_REMOVE_OBJECT:
offset = dissect_pvfs2_mgmt_remove_object_request(tvb, tree, offset,
pinfo);
break;
case PVFS_SERV_MGMT_REMOVE_DIRENT:
offset = dissect_pvfs2_mgmt_remove_dirent_request(tvb, tree, offset,
pinfo);
break;
case PVFS_SERV_MGMT_GET_DIRDATA_HANDLE:
offset = dissect_pvfs2_mgmt_get_dirdata_handle_request(tvb, tree,
offset, pinfo);
break;
#if 0
case PVFS_SERV_JOB_TIMER:
break;
#endif
case PVFS_SERV_PROTO_ERROR:
break;
case PVFS_SERV_GETEATTR:
offset = dissect_pvfs2_geteattr_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_SETEATTR:
offset = dissect_pvfs2_seteattr_request(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_DELEATTR:
offset = dissect_pvfs2_deleattr_request(tvb, tree, offset, pinfo);
break;
default:
break;
}
return offset;
}
static int
dissect_pvfs2_create_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
return dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
}
static int
dissect_pvfs2_io_response(tvbuff_t *tvb, proto_tree *tree, int offset)
{
return dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_size, NULL);
}
static int
dissect_pvfs2_getattr_response(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_object_attr(tvb, tree, offset, pinfo);
return offset;
}
static int
dissect_pvfs2_lookup_path_response(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
guint32 nCount = 0;
guint32 handle_count = 0;
guint32 attr_count = 0;
proto_tree *attr_tree;
offset += 4;
handle_count = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_lookup_path_response_handle_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (nCount = 0; nCount < handle_count; nCount++)
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset += 4;
attr_count = tvb_get_letohl(tvb, offset);
attr_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4,
ett_pvfs_attr, NULL, "Attribute array (total items: %d)", attr_count);
offset += 4;
for (nCount = 0; nCount < attr_count; nCount++)
offset = dissect_pvfs_object_attr(tvb, attr_tree, offset, pinfo);
return offset;
}
static int
dissect_pvfs2_rmdirent_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_chdirent_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_mkdir_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_readdir_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
guint32 dirent_count = 0;
guint32 nCount = 0;
proto_tree_add_item(tree, hf_pvfs_ds_position, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_pvfs_directory_version, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset += 4;
dirent_count = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_dirent_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (nCount = 0; nCount < dirent_count; nCount++)
{
offset = dissect_pvfs_string(tvb, tree, hf_pvfs_path, offset, NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
}
return offset;
}
static int
dissect_pvfs2_getconfig_response(tvbuff_t *tvb, proto_tree *parent_tree,
int offset, packet_info *pinfo)
{
guint32 i;
guint32 total_bytes = 0, total_config_bytes = 0, total_lines = 0;
guint32 bytes_processed = 0;
guint32 length_remaining = 0;
const char *ptr = NULL;
proto_tree *tree, *config_tree = NULL;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 12,
ett_pvfs_server_config, NULL, "Server Config");
total_bytes = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_getconfig_response_total_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (total_bytes < 4)
{
return offset;
}
total_lines = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_getconfig_response_lines, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
total_config_bytes = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_getconfig_response_config_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ptr = tvb_get_ptr(tvb, offset, total_config_bytes);
length_remaining = tvb_captured_length_remaining(tvb, offset);
if (length_remaining < total_config_bytes)
{
total_config_bytes = length_remaining;
}
bytes_processed = 0;
for (i = 0; i < total_lines; i++)
{
guint8 entry[256], *pentry = entry, *tmp_entry = NULL;
guint32 entry_length = 0, tmp_entry_length = 0;
guint32 bufsiz = sizeof(entry);
while ((*ptr != '\n') && (*ptr != '\0') &&
(bytes_processed < total_config_bytes) &&
(entry_length < bufsiz))
{
*pentry++ = *ptr++;
bytes_processed++;
entry_length++;
}
if ((entry_length == bufsiz) &&
((entry[entry_length - 1] != '\n') &&
(entry[entry_length - 1] != '\0')))
{
break;
}
if (bytes_processed == total_config_bytes)
{
break;
}
*pentry= '\0';
tmp_entry = entry;
tmp_entry_length = entry_length;
while ((tmp_entry_length > 0) && (!g_ascii_isalnum(*tmp_entry)) &&
(*tmp_entry != '<'))
{
tmp_entry++;
tmp_entry_length--;
}
if (tmp_entry[0] == '<')
{
if (tmp_entry[tmp_entry_length - 1] == '>')
{
if (tmp_entry[1] != '/')
{
config_tree = proto_tree_add_subtree(tree, tvb, offset,
tmp_entry_length, ett_pvfs_server_config_branch, NULL, tmp_entry);
}
else
{
config_tree = NULL;
}
}
else
{
break;
}
}
else
{
if (config_tree == NULL)
config_tree = tree;
if (tmp_entry_length > 0)
{
proto_tree_add_string_format(config_tree, hf_pvfs_getconfig_response_entry, tvb, offset, tmp_entry_length,
tmp_entry, "%s", tmp_entry);
}
}
offset += entry_length + 1;
ptr++;
bytes_processed++;
}
if (bytes_processed < total_config_bytes)
{
proto_tree_add_expert(config_tree, pinfo, &ei_pvfs_malformed, tvb, offset, -1);
}
return offset;
}
static int
dissect_pvfs2_write_completion_response(tvbuff_t *tvb, proto_tree *tree,
int offset)
{
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_total_completed,
NULL);
return offset;
}
static int
dissect_pvfs2_mgmt_setparam_response(tvbuff_t *tvb, proto_tree *tree,
int offset)
{
proto_tree_add_item(tree, hf_pvfs_prev_value, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_pvfs2_statfs_response(tvbuff_t *tvb, proto_tree *tree, int offset)
{
offset += 4;
offset = dissect_pvfs_fs_id(tvb, tree, offset);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_bytes_available,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_bytes_total,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_ram_bytes_total,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_ram_bytes_free,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_load_average_1s,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_load_average_5s,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_load_average_15s,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_uptime_seconds,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_handles_available,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_handles_total,
NULL);
return offset;
}
static int
dissect_pvfs_mgmt_perf_stat(tvbuff_t *tvb, proto_tree *tree, int offset,
int nItem)
{
proto_tree *stat_tree;
stat_tree = proto_tree_add_subtree_format(tree, tvb, offset, 48,
ett_pvfs_mgmt_perf_stat, NULL, "Stat Array - Element %d", nItem);
proto_tree_add_item(stat_tree, hf_pvfs_mgmt_perf_stat_valid_flag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(stat_tree, hf_pvfs_mgmt_perf_stat_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_pvfs_uint64(tvb, stat_tree, offset, hf_pvfs_start_time_ms,
NULL);
offset = dissect_pvfs_uint64(tvb, stat_tree, offset, hf_pvfs_bytes_written,
NULL);
offset = dissect_pvfs_uint64(tvb, stat_tree, offset, hf_pvfs_bytes_read,
NULL);
offset = dissect_pvfs_uint64(tvb, stat_tree, offset, hf_pvfs_metadata_write,
NULL);
offset = dissect_pvfs_uint64(tvb, stat_tree, offset, hf_pvfs_metadata_read,
NULL);
return offset;
}
static int
dissect_pvfs2_mgmt_perf_mon_response(tvbuff_t *tvb, proto_tree *tree,
int offset)
{
guint32 perf_array_count, i;
proto_tree_add_item(tree, hf_pvfs_mgmt_perf_mon_response_suggested_next_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_end_time_ms, NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_cur_time_ms, NULL);
offset += 4;
perf_array_count = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_mgmt_perf_mon_response_perf_array_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (i = 0; i < perf_array_count; i++)
offset = dissect_pvfs_mgmt_perf_stat(tvb, tree, offset, i);
return offset;
}
static int
dissect_pvfs2_mgmt_iterate_handles_response(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
guint32 handle_count, i;
proto_tree_add_item(tree, hf_pvfs_mgmt_iterate_handles_response_ds_position, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
handle_count = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_mgmt_iterate_handles_response_handle_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (i = 0; i < handle_count; i++)
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_mgmt_dspace_info(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo)
{
offset = dissect_pvfs2_error(tvb, tree, offset, pinfo);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs2_ds_type(tvb, tree, offset, NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_b_size,
NULL);
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_k_size,
NULL);
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_mgmt_dspace_info_list_response(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
guint32 dspace_info_count, i;
proto_tree *arr_tree = NULL;
offset += 4;
dspace_info_count = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_pvfs_mgmt_dspace_info_list_response_dspace_info_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if ((dspace_info_count > 0) && (tree))
{
arr_tree = proto_tree_add_subtree_format(tree, tvb, offset,
dspace_info_count * 40, ett_pvfs_mgmt_dspace_info, NULL, "dspace_info Array (%d items)",
dspace_info_count);
}
for (i = 0; i < dspace_info_count; i++)
offset = dissect_pvfs2_mgmt_dspace_info(tvb, arr_tree, offset, pinfo);
return offset;
}
static int
dissect_pvfs2_mgmt_event_mon_response(tvbuff_t *tvb, proto_tree *tree,
int offset)
{
proto_tree_add_item(tree, hf_pvfs_mgmt_event_mon_response_api, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_mgmt_event_mon_response_operation, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_mgmt_event_mon_response_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_pvfs_uint64(tvb, tree, offset, hf_pvfs_id_gen_t,
NULL);
proto_tree_add_item(tree, hf_pvfs_mgmt_event_mon_response_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_mgmt_event_mon_response_tv_sec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pvfs_mgmt_event_mon_response_tv_usec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
return offset;
}
static int
dissect_pvfs2_mgmt_remove_object_response(tvbuff_t *tvb, proto_tree *tree,
int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
offset = dissect_pvfs_fs_id(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_mgmt_get_dirdata_handle_response(tvbuff_t *tvb,
proto_tree *tree, int offset, packet_info *pinfo)
{
offset = dissect_pvfs_fh(tvb, offset, pinfo, tree, "handle", NULL);
return offset;
}
static int
dissect_pvfs2_geteattr_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo _U_)
{
offset += 4;
offset = dissect_ds_keyval_array(tvb, tree, offset);
return offset;
}
static int
dissect_pvfs2_response(tvbuff_t *tvb, proto_tree *tree, int offset,
packet_info *pinfo, guint32 server_op)
{
offset = dissect_pvfs2_error(tvb, tree, offset, pinfo);
switch (server_op)
{
case PVFS_SERV_CREATE:
offset = dissect_pvfs2_create_response(tvb, tree, offset, pinfo);
break;
#if 0
case PVFS_SERV_REMOVE:
break;
#endif
case PVFS_SERV_IO:
offset = dissect_pvfs2_io_response(tvb, tree, offset);
break;
case PVFS_SERV_GETATTR:
offset = dissect_pvfs2_getattr_response(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_SETATTR:
break;
case PVFS_SERV_LOOKUP_PATH:
offset = dissect_pvfs2_lookup_path_response(tvb, tree, offset, pinfo);
break;
#if 0
case PVFS_SERV_CRDIRENT:
break;
#endif
case PVFS_SERV_RMDIRENT:
offset = dissect_pvfs2_rmdirent_response(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_CHDIRENT:
offset = dissect_pvfs2_chdirent_response(tvb, tree, offset, pinfo);
break;
#if 0
case PVFS_SERV_TRUNCATE:
break;
#endif
case PVFS_SERV_MKDIR:
offset = dissect_pvfs2_mkdir_response(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_READDIR:
offset = dissect_pvfs2_readdir_response(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_GETCONFIG:
offset = dissect_pvfs2_getconfig_response(tvb, tree, offset, pinfo);
break;
case PVFS_SERV_WRITE_COMPLETION:
offset = dissect_pvfs2_write_completion_response(tvb, tree, offset);
break;
#if 0
case PVFS_SERV_FLUSH:
break;
#endif
case PVFS_SERV_MGMT_SETPARAM:
offset = dissect_pvfs2_mgmt_setparam_response(tvb, tree, offset);
break;
#if 0
case PVFS_SERV_MGMT_NOOP:
break;
#endif
case PVFS_SERV_STATFS:
offset = dissect_pvfs2_statfs_response(tvb, tree, offset);
break;
#if 0
case PVFS_SERV_PERF_UPDATE:
break;
#endif
case PVFS_SERV_MGMT_PERF_MON:
offset = dissect_pvfs2_mgmt_perf_mon_response(tvb, tree, offset);
break;
case PVFS_SERV_MGMT_ITERATE_HANDLES:
offset = dissect_pvfs2_mgmt_iterate_handles_response(tvb, tree,
offset, pinfo);
break;
case PVFS_SERV_MGMT_DSPACE_INFO_LIST:
offset = dissect_pvfs2_mgmt_dspace_info_list_response(tvb, tree,
offset, pinfo);
break;
case PVFS_SERV_MGMT_EVENT_MON:
offset = dissect_pvfs2_mgmt_event_mon_response(tvb, tree, offset);
break;
case PVFS_SERV_MGMT_REMOVE_OBJECT:
offset = dissect_pvfs2_mgmt_remove_object_response(tvb, tree, offset,
pinfo);
break;
#if 0
case PVFS_SERV_MGMT_REMOVE_DIRENT:
break;
#endif
case PVFS_SERV_MGMT_GET_DIRDATA_HANDLE:
offset = dissect_pvfs2_mgmt_get_dirdata_handle_response(tvb, tree,
offset, pinfo);
break;
#if 0
case PVFS_SERV_JOB_TIMER:
break;
#endif
case PVFS_SERV_PROTO_ERROR:
break;
case PVFS_SERV_GETEATTR:
offset = dissect_pvfs2_geteattr_response(tvb, tree, offset, pinfo);
break;
#if 0
case PVFS_SERV_SETEATTR:
break;
#endif
#if 0
case PVFS_SERV_DELEATTR:
break;
#endif
default:
break;
}
return offset;
}
static gint
pvfs2_io_tracking_equal(gconstpointer k1, gconstpointer k2)
{
const pvfs2_io_tracking_key_t *key1 = (const pvfs2_io_tracking_key_t *) k1;
const pvfs2_io_tracking_key_t *key2 = (const pvfs2_io_tracking_key_t *) k2;
return (key1->tag == key2->tag);
}
static guint
pvfs2_io_tracking_hash(gconstpointer k)
{
const pvfs2_io_tracking_key_t *key = (const pvfs2_io_tracking_key_t *) k;
return (guint) ((key->tag >> 32) ^ ((guint32) key->tag));
}
static void
pvfs2_io_tracking_init(void)
{
pvfs2_io_tracking_value_table = g_hash_table_new(pvfs2_io_tracking_hash,
pvfs2_io_tracking_equal);
}
static void
pvfs2_io_tracking_cleanup(void)
{
g_hash_table_destroy(pvfs2_io_tracking_value_table);
}
static pvfs2_io_tracking_value_t *
pvfs2_io_tracking_new_with_tag(guint64 tag, guint32 num)
{
pvfs2_io_tracking_value_t *value;
pvfs2_io_tracking_key_t *newkey;
newkey = wmem_new0(wmem_file_scope(), pvfs2_io_tracking_key_t);
newkey->tag = tag;
value = wmem_new0(wmem_file_scope(), pvfs2_io_tracking_value_t);
g_hash_table_insert(pvfs2_io_tracking_value_table, newkey, value);
value->request_frame_num = num;
return value;
}
static gboolean
dissect_pvfs_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
gboolean dissect_other_as_continuation _U_)
{
guint32 mode = 0;
proto_item *item;
proto_tree *pvfs_tree = NULL, *pvfs_htree = NULL;
int offset = 0;
guint64 tag;
guint32 server_op;
pvfs2_io_tracking_value_t *val = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PVFS");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(parent_tree, proto_pvfs, tvb, 0, -1, ENC_NA);
pvfs_tree = proto_item_add_subtree(item, ett_pvfs);
proto_tree_add_item(pvfs_tree, hf_pvfs_version2, tvb, 0, -1, ENC_NA);
pvfs_htree = proto_tree_add_subtree(pvfs_tree, tvb, 0, BMI_HEADER_SIZE,
ett_pvfs_hdr, NULL, "BMI Header");
proto_tree_add_item(pvfs_htree, hf_pvfs_magic_nr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
mode = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(pvfs_htree, hf_pvfs_mode, tvb, offset, 4, mode);
offset += 4;
offset = dissect_pvfs_uint64(tvb, pvfs_htree, offset, hf_pvfs_tag, &tag);
offset = dissect_pvfs_uint64(tvb, pvfs_htree, offset, hf_pvfs_size, NULL);
server_op = tvb_get_letohl(tvb, offset + 8);
if (mode == TCP_MODE_UNEXP)
{
if ((server_op == PVFS_SERV_IO) && !pinfo->fd->flags.visited)
val = pvfs2_io_tracking_new_with_tag(tag, pinfo->fd->num);
}
else
{
pvfs2_io_tracking_key_t key;
memset(&key, 0, sizeof(key));
key.tag = tag;
val = (pvfs2_io_tracking_value_t *)g_hash_table_lookup(pvfs2_io_tracking_value_table, &key);
if (val && !pinfo->fd->flags.visited)
{
if (val->response_frame_num == 0)
val->response_frame_num = pinfo->fd->num;
else
{
if (val->flow_frame_num == 0)
val->flow_frame_num = pinfo->fd->num;
}
}
}
if (val && (val->flow_frame_num == pinfo->fd->num))
{
col_set_str(pinfo->cinfo, COL_INFO, "PVFS flow data");
proto_tree_add_item(pvfs_tree, hf_pvfs_flow_data, tvb, offset, -1, ENC_NA);
return TRUE;
}
offset = dissect_pvfs2_common_header(tvb, pvfs_htree, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(server_op, names_pvfs_server_op, "%u (unknown)"));
col_append_str(pinfo->cinfo, COL_INFO,
(mode == TCP_MODE_UNEXP)? " (request)": " (response)");
if (mode == TCP_MODE_UNEXP)
{
dissect_pvfs2_request(tvb, pvfs_tree, offset, pinfo, server_op);
}
else
{
#if 0
if (mode == TCP_MODE_REND)
{
col_set_str(pinfo->cinfo, COL_INFO, "PVFS2 DATA (request)");
}
else
#endif
{
dissect_pvfs2_response(tvb, pvfs_tree, offset, pinfo,
server_op);
}
}
return TRUE;
}
void
proto_register_pvfs(void)
{
static hf_register_info hf[] = {
{ &hf_pvfs_magic_nr,
{ "Magic Number", "pvfs.magic_nr", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_uid,
{ "UID", "pvfs.uid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_gid,
{ "GID", "pvfs.gid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mode,
{ "Mode", "pvfs.mode", FT_UINT32, BASE_DEC,
VALS(names_pvfs_mode), 0, NULL, HFILL }},
{ &hf_pvfs_tag,
{ "Tag", "pvfs.tag", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_size,
{ "Size", "pvfs.size", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_release_number,
{ "Release Number", "pvfs.release_number", FT_UINT32, BASE_CUSTOM,
CF_FUNC(pvfc_fmt_release_num), 0, NULL, HFILL }},
{ &hf_pvfs_encoding,
{ "Encoding", "pvfs.encoding", FT_UINT32, BASE_DEC,
VALS(names_pvfs_encoding), 0, NULL, HFILL }},
{ &hf_pvfs_server_op,
{ "Server Operation", "pvfs.server_op", FT_UINT32, BASE_DEC,
VALS(names_pvfs_server_op), 0, NULL, HFILL }},
#if 0
{ &hf_pvfs_handle,
{ "Handle", "pvfs.handle", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ &hf_pvfs_fs_id,
{ "fs_id", "pvfs.fs_id", FT_UINT32, BASE_HEX,
NULL, 0, "File System ID", HFILL }},
{ &hf_pvfs_attrmask,
{ "Attribute Mask", "pvfs.attrmask", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_attr,
{ "attr", "pvfs.attribute", FT_UINT32, BASE_HEX,
VALS(names_pvfs_attr), 0, "Attribute", HFILL }},
{ &hf_pvfs_ds_type,
{ "ds_type", "pvfs.ds_type", FT_UINT32, BASE_HEX,
VALS(names_pvfs_ds_type), 0, "Type", HFILL }},
{ &hf_pvfs_error,
{ "Result", "pvfs.error", FT_UINT32, BASE_HEX,
VALS(names_pvfs_error), 0, NULL, HFILL }},
{ &hf_pvfs_atime,
{ "atime", "pvfs.atime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Access Time", HFILL }},
{ &hf_pvfs_atime_sec,
{ "seconds", "pvfs.atime.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Access Time (seconds)", HFILL }},
{ &hf_pvfs_atime_nsec,
{ "microseconds", "pvfs.atime.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Access Time (microseconds)", HFILL }},
{ &hf_pvfs_mtime,
{ "mtime", "pvfs.mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Modify Time", HFILL }},
{ &hf_pvfs_mtime_sec,
{ "seconds", "pvfs.mtime.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Modify Time (seconds)", HFILL }},
{ &hf_pvfs_mtime_nsec,
{ "microseconds", "pvfs.mtime.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Modify Time (microseconds)", HFILL }},
{ &hf_pvfs_ctime,
{ "ctime", "pvfs.ctime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Creation Time", HFILL }},
{ &hf_pvfs_ctime_sec,
{ "seconds", "pvfs.ctime.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Creation Time (seconds)", HFILL }},
{ &hf_pvfs_ctime_nsec,
{ "microseconds", "pvfs.ctime.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Creation Time (microseconds)", HFILL }},
{ &hf_pvfs_parent_atime,
{ "Parent atime", "pvfs.parent_atime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Access Time", HFILL }},
{ &hf_pvfs_parent_atime_sec,
{ "seconds", "pvfs.parent_atime.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Access Time (seconds)", HFILL }},
{ &hf_pvfs_parent_atime_nsec,
{ "microseconds", "pvfs.parent_atime.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Access Time (microseconds)", HFILL }},
{ &hf_pvfs_parent_mtime,
{ "Parent mtime", "pvfs.parent_mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Modify Time", HFILL }},
{ &hf_pvfs_parent_mtime_sec,
{ "seconds", "pvfs.parent_mtime.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Modify Time (seconds)", HFILL }},
{ &hf_pvfs_parent_mtime_nsec,
{ "microseconds", "pvfs.parent_mtime.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Modify Time (microseconds)", HFILL }},
{ &hf_pvfs_parent_ctime,
{ "Parent ctime", "pvfs.parent_ctime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Creation Time", HFILL }},
{ &hf_pvfs_parent_ctime_sec,
{ "seconds", "pvfs.parent_ctime.sec", FT_UINT32, BASE_DEC,
NULL, 0, "Creation Time (seconds)", HFILL }},
{ &hf_pvfs_parent_ctime_nsec,
{ "microseconds", "pvfs.parent_ctime.usec", FT_UINT32, BASE_DEC,
NULL, 0, "Creation Time (microseconds)", HFILL }},
{ &hf_pvfs_dfile_count,
{ "dfile_count", "pvfs.dfile_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_distribution,
{ "Distribution", "pvfs.distribution", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_dirent_count,
{ "Dir Entry Count", "pvfs.dirent_count", FT_UINT32, BASE_DEC,
NULL, 0, "Directory Entry Count", HFILL }},
{ &hf_pvfs_directory_version,
{ "Directory Version", "pvfs.directory_version", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_path,
{ "Path", "pvfs.path", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_total_completed,
{ "Bytes Completed", "pvfs.bytes_completed", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_io_dist,
{ "Name", "pvfs.distribution.name", FT_STRING, BASE_NONE,
NULL, 0, "Distribution Name", HFILL }},
{ &hf_pvfs_aggregate_size,
{ "Aggregate Size", "pvfs.aggregate_size", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_io_type,
{ "I/O Type", "pvfs.io_type", FT_UINT32, BASE_DEC,
VALS(names_pvfs_io_type), 0, NULL, HFILL }},
{ &hf_pvfs_flowproto_type,
{ "Flow Protocol Type", "pvfs.flowproto_type", FT_UINT32, BASE_DEC,
VALS(names_pvfs_flowproto_type), 0, NULL, HFILL }},
{ &hf_pvfs_server_param,
{ "Server Parameter", "pvfs.server_param", FT_UINT32, BASE_DEC,
VALS(names_pvfs_server_param), 0, NULL, HFILL }},
{ &hf_pvfs_prev_value,
{ "Previous Value", "pvfs.prev_value", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
#if 0
{ &hf_pvfs_ram_free_bytes,
{ "RAM Free Bytes", "pvfs.ram.free_bytes", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
#endif
{ &hf_pvfs_bytes_available,
{ "Bytes Available", "pvfs.bytes_available", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_bytes_total,
{ "Bytes Total", "pvfs.bytes_total", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_ram_bytes_total,
{ "RAM Bytes Total", "pvfs.ram_bytes_total", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_ram_bytes_free,
{ "RAM Bytes Free", "pvfs.ram_bytes_free", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_load_average_1s,
{ "Load Average (1s)", "pvfs.load_average.1s", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_load_average_5s,
{ "Load Average (5s)", "pvfs.load_average.5s", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_load_average_15s,
{ "Load Average (15s)", "pvfs.load_average.15s", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_uptime_seconds,
{ "Uptime (seconds)", "pvfs.uptime", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_handles_available,
{ "Handles Available", "pvfs.handles_available", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_handles_total,
{ "Total Handles", "pvfs.total_handles", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_unused,
{ "Unused", "pvfs.unused", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_context_id,
{ "Context ID", "pvfs.context_id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_offset,
{ "Offset", "pvfs.offset", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_stride,
{ "Stride", "pvfs.stride", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_ub,
{ "ub", "pvfs.ub", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_lb,
{ "lb", "pvfs.lb", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_end_time_ms,
{ "end_time_ms", "pvfs.end_time_ms", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_cur_time_ms,
{ "cur_time_ms", "pvfs.cur_time_ms", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_start_time_ms,
{ "start_time_ms", "pvfs.start_time_ms", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_bytes_written,
{ "bytes_written", "pvfs.bytes_written", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_bytes_read,
{ "bytes_read", "pvfs.bytes_read", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_metadata_write,
{ "metadata_write", "pvfs.metadata_write", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_metadata_read,
{ "metadata_read", "pvfs.metadata_read", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_b_size,
{ "Size of bstream (if applicable)", "pvfs.b_size", FT_UINT64,
BASE_DEC, NULL, 0, "Size of bstream", HFILL }},
{ &hf_pvfs_k_size,
{ "Number of keyvals (if applicable)", "pvfs.k_size", FT_UINT64,
BASE_DEC, NULL, 0, "Number of keyvals", HFILL }},
{ &hf_pvfs_id_gen_t,
{ "id_gen_t", "pvfs.id_gen_t", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_attribute_key,
{ "Attribute key", "pvfs.attribute.key", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_attribute_value,
{ "Attribute value", "pvfs.attribute.value", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_strip_size,
{ "Strip size", "pvfs.strip_size", FT_UINT64, BASE_DEC,
NULL, 0, "Strip size (bytes)", HFILL }},
{ &hf_pvfs_ereg,
{ "ereg", "pvfs.ereg", FT_INT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_sreg,
{ "sreg", "pvfs.sreg", FT_INT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_num_eregs,
{ "Number of eregs", "pvfs.num_eregs", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_num_blocks,
{ "Number of blocks", "pvfs.num_blocks", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_num_contig_chunks,
{ "Number of contig_chunks", "pvfs.num_contig_chunks", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_pvfs_server_nr,
{ "Server #", "pvfs.server_nr", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_server_count,
{ "Number of servers", "pvfs.server_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_fh_length,
{ "length", "pvfs.fh.length", FT_UINT32, BASE_DEC,
NULL, 0, "file handle length", HFILL }},
{ &hf_pvfs_fh_hash,
{ "hash", "pvfs.fh.hash", FT_UINT32, BASE_HEX,
NULL, 0, "file handle hash", HFILL }},
{ &hf_pvfs_permissions,
{ "Permissions", "pvfs.permissions", FT_UINT32, BASE_OCT,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_server_mode,
{ "Server Mode", "pvfs.server_mode", FT_UINT32, BASE_DEC,
VALS(names_pvfs_server_mode), 0, NULL, HFILL }},
{ &hf_pvfs_depth,
{ "depth", "pvfs.depth", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_num_nested_req,
{ "num_nested_req", "pvfs.num_nested_req", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_committed,
{ "committed", "pvfs.committed", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_refcount,
{ "refcount", "pvfs.refcount", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_numreq,
{ "numreq", "pvfs.numreq", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_truncate_request_flags,
{ "flags", "pvfs.truncate_request_flags", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_ds_position,
{ "ds_position", "pvfs.ds_position", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_dirent_limit,
{ "dirent_limit", "pvfs.dirent_limit", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_flush_request_flags,
{ "flags", "pvfs.flush_request_flags", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_next_id,
{ "next_id", "pvfs.next_id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_perf_mon_request_count,
{ "count", "pvfs.mgmt_perf_mon_request.count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_perf_mon_request_event_count,
{ "Event count", "pvfs.mgmt_perf_mon_request.event_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_lookup_path_response_handle_count,
{ "Handle Count", "pvfs.lookup_path_response.handle_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_getconfig_response_total_bytes,
{ "Total Bytes", "pvfs.getconfig_response.total_bytes", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_getconfig_response_lines,
{ "Lines", "pvfs.getconfig_response.lines", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_getconfig_response_config_bytes,
{ "Config Bytes", "pvfs.getconfig_response.config_bytes", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_perf_stat_valid_flag,
{ "valid_flag", "pvfs.mgmt_perf_stat.valid_flag", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_perf_stat_id,
{ "id", "pvfs.mgmt_perf_stat.id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_perf_mon_response_suggested_next_id,
{ "suggested_next_id", "pvfs.mgmt_perf_mon_response.suggested_next_id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_perf_mon_response_perf_array_count,
{ "perf_array_count", "pvfs.mgmt_perf_mon_response.perf_array_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_iterate_handles_response_ds_position,
{ "ds_position", "pvfs.mgmt_iterate_handles_response.ds_position", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_iterate_handles_response_handle_count,
{ "handle_count", "pvfs.mgmt_iterate_handles_response.handle_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_dspace_info_list_response_dspace_info_count,
{ "dspace_info_count", "pvfs.mgmt_dspace_info_list_response.dspace_info_count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_event_mon_response_api,
{ "api", "pvfs.mgmt_event_mon_response.api", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_event_mon_response_operation,
{ "operation", "pvfs.mgmt_event_mon_response.operation", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_event_mon_response_value,
{ "value", "pvfs.mgmt_event_mon_response.value", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_event_mon_response_flags,
{ "flags", "pvfs.mgmt_event_mon_response.flags", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_event_mon_response_tv_sec,
{ "tv_sec", "pvfs.mgmt_event_mon_response.tv_sec", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_mgmt_event_mon_response_tv_usec,
{ "tv_usec", "pvfs.mgmt_event_mon_response.tv_usec", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_fill_bytes,
{ "fill_bytes", "pvfs.fill_bytes", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_target_path_len,
{ "target_path_len", "pvfs.target_path_len", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_version2,
{ "Version 2", "pvfs.version2", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_flow_data,
{ "PVFC Flow Data", "pvfs.flow_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_getconfig_response_entry,
{ "GETCONFIG Response entry", "pvfs.getconfig_response_entry", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_fhandle_data,
{ "data", "pvfs.fhandle_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_pvfs_opaque_length,
{ "length", "pvfs.opaque_length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_pvfs,
&ett_pvfs_hdr,
&ett_pvfs_credentials,
&ett_pvfs_server_config,
&ett_pvfs_server_config_branch,
&ett_pvfs_attrmask,
&ett_pvfs_time,
&ett_pvfs_extent_array_tree,
&ett_pvfs_extent_item,
&ett_pvfs_string,
&ett_pvfs_attr_tree,
&ett_pvfs_distribution,
&ett_pvfs_mgmt_perf_stat,
&ett_pvfs_mgmt_dspace_info,
&ett_pvfs_attr,
&ett_pvfs_fh
};
static ei_register_info ei[] = {
{ &ei_pvfs_malformed, { "pvfs.malformed", PI_MALFORMED, PI_ERROR, "MALFORMED OR TRUNCATED DATA", EXPFILL }},
};
module_t *pvfs_module;
expert_module_t* expert_pvfs;
proto_pvfs = proto_register_protocol("Parallel Virtual File System",
"PVFS", "pvfs");
proto_register_field_array(proto_pvfs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pvfs = expert_register_protocol(proto_pvfs);
expert_register_field_array(expert_pvfs, ei, array_length(ei));
register_init_routine(pvfs2_io_tracking_init);
register_cleanup_routine(pvfs2_io_tracking_cleanup);
pvfs_module = prefs_register_protocol(proto_pvfs, NULL);
prefs_register_bool_preference(pvfs_module, "desegment",
"Reassemble PVFS messages spanning multiple TCP segments",
"Whether the PVFS dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&pvfs_desegment);
}
void
proto_reg_handoff_pvfs(void)
{
dissector_handle_t pvfs_handle;
pvfs_handle = new_create_dissector_handle(dissect_pvfs_heur, proto_pvfs);
dissector_add_uint("tcp.port", TCP_PORT_PVFS2, pvfs_handle);
heur_dissector_add("tcp", dissect_pvfs_heur, "PVFS over TCP", "pvfs_tcp", proto_pvfs, HEURISTIC_ENABLE);
}
