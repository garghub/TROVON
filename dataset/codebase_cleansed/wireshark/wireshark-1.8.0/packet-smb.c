static gint
fid_cmp(smb_fid_info_t *fida, smb_fid_info_t *fidb)
{
return (fida->opened_in - fidb->opened_in);
}
static void
smb_trans_reassembly_init(void)
{
fragment_table_init(&smb_trans_fragment_table);
}
static fragment_data *
smb_trans_defragment(proto_tree *tree _U_, packet_info *pinfo, tvbuff_t *tvb,
int offset, int count, int pos, int totlen)
{
fragment_data *fd_head=NULL;
smb_info_t *si;
int more_frags;
if (count > MAX_FRAGMENT_SIZE || count < 0) {
THROW(ReportedBoundsError);
}
more_frags=totlen>(pos+count);
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip == NULL) {
return NULL;
}
if(!pinfo->fd->flags.visited){
fd_head = fragment_add(tvb, offset, pinfo,
si->sip->frame_req, smb_trans_fragment_table,
pos, count, more_frags);
} else {
fd_head = fragment_get(pinfo, si->sip->frame_req, smb_trans_fragment_table);
}
if (!fd_head || !(fd_head->flags&FD_DEFRAGMENTED)){
si->sip->flags |= SMB_SIF_IS_CONTINUED;
} else {
si->sip->flags &= ~SMB_SIF_IS_CONTINUED;
}
if( (pos==0) && fd_head && fd_head->flags&FD_DEFRAGMENTED){
return fd_head;
} else {
return NULL;
}
}
static gint
smb_saved_info_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
register guint32 key1 = GPOINTER_TO_UINT(k1);
register guint32 key2 = GPOINTER_TO_UINT(k2);
return key1==key2;
}
static guint
smb_saved_info_hash_unmatched(gconstpointer k)
{
register guint32 key = GPOINTER_TO_UINT(k);
return key;
}
static gint
smb_saved_info_equal_matched(gconstpointer k1, gconstpointer k2)
{
const smb_saved_info_key_t *key1 = k1;
const smb_saved_info_key_t *key2 = k2;
return key1->frame == key2->frame && key1->pid_mid == key2->pid_mid;
}
static guint
smb_saved_info_hash_matched(gconstpointer k)
{
const smb_saved_info_key_t *key = k;
return key->frame + key->pid_mid;
}
static void
smb_file_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 mask)
{
mask&=0x0000ffff;
if(mask==0x000001ff){
proto_tree_add_text(tree, tvb, offset, 4, "[FULL CONTROL]");
}
proto_tree_add_boolean(tree, hf_smb_file_access_mask_write_attribute, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_read_attribute, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_execute, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_write_ea, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_read_ea, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_append_data, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_write_data, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_file_access_mask_read_data, tvb, offset, 4, mask);
}
static void
smb_dir_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 mask)
{
mask&=0x0000ffff;
if(mask==0x000001ff){
proto_tree_add_text(tree, tvb, offset, 4, "[FULL CONTROL]");
}
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_write_attribute, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_read_attribute, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_delete_child, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_traverse, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_write_ea, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_read_ea, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_add_subdir, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_add_file, tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_dir_access_mask_list, tvb, offset, 4, mask);
}
static int
tm_diff(struct tm *a, struct tm *b)
{
int ay = a->tm_year + (TM_YEAR_BASE - 1);
int by = b->tm_year + (TM_YEAR_BASE - 1);
int intervening_leap_days =
(ay/4 - by/4) - (ay/100 - by/100) + (ay/400 - by/400);
int years = ay - by;
int days =
365*years + intervening_leap_days + (a->tm_yday - b->tm_yday);
int hours = 24*days + (a->tm_hour - b->tm_hour);
int minutes = 60*hours + (a->tm_min - b->tm_min);
int seconds = 60*minutes + (a->tm_sec - b->tm_sec);
return seconds;
}
static int
TimeZone(time_t t)
{
struct tm *tm = gmtime(&t);
struct tm tm_utc;
if (tm == NULL)
return 0;
tm_utc = *tm;
tm = localtime(&t);
if (tm == NULL)
return 0;
return tm_diff(&tm_utc,tm);
}
static int
TimeZoneFaster(time_t t)
{
static struct dst_table {time_t start,end; int zone;} *tdt;
static struct dst_table *dst_table = NULL;
static int table_size = 0;
int i;
int zone = 0;
if (t == 0)
t = time(NULL);
#define MAX_DST_WIDTH (365*24*60*60)
#define MAX_DST_SKIP (7*24*60*60)
for (i = 0; i < table_size; i++) {
if (t >= dst_table[i].start && t <= dst_table[i].end)
break;
}
if (i < table_size) {
zone = dst_table[i].zone;
} else {
time_t low,high;
zone = TimeZone(t);
if (dst_table == NULL)
tdt = g_malloc(sizeof(dst_table[0])*(i+1));
else
tdt = g_realloc(dst_table, sizeof(dst_table[0])*(i+1));
if (tdt == NULL) {
g_free(dst_table);
table_size = 0;
} else {
dst_table = tdt;
table_size++;
dst_table[i].zone = zone;
dst_table[i].start = dst_table[i].end = t;
low = t - MAX_DST_WIDTH/2;
high = t + MAX_DST_WIDTH/2;
while (low+60*60 < dst_table[i].start) {
if (dst_table[i].start - low > MAX_DST_SKIP*2)
t = dst_table[i].start - MAX_DST_SKIP;
else
t = low + (dst_table[i].start-low)/2;
if (TimeZone(t) == zone)
dst_table[i].start = t;
else
low = t;
}
while (high-60*60 > dst_table[i].end) {
if (high - dst_table[i].end > MAX_DST_SKIP*2)
t = dst_table[i].end + MAX_DST_SKIP;
else
t = high - (high-dst_table[i].end)/2;
if (TimeZone(t) == zone)
dst_table[i].end = t;
else
high = t;
}
}
}
return zone;
}
static int
LocTimeDiff(time_t lt)
{
int d = TimeZoneFaster(lt);
time_t t = lt + d;
if (((t < lt) ^ (d < 0)))
t = lt;
return TimeZoneFaster(t);
}
static int
dissect_smb_UTIME(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_date)
{
guint32 timeval;
nstime_t ts;
timeval = tvb_get_letohl(tvb, offset);
if (timeval == 0xffffffff) {
proto_tree_add_text(tree, tvb, offset, 4,
"%s: No time specified (0xffffffff)",
proto_registrar_get_name(hf_date));
offset += 4;
return offset;
}
ts.secs = timeval + LocTimeDiff(timeval);
ts.nsecs = 0;
proto_tree_add_time(tree, hf_date, tvb, offset, 4, &ts);
offset += 4;
return offset;
}
static int
dissect_smb_datetime(tvbuff_t *tvb, proto_tree *parent_tree, int offset,
int hf_date, int hf_dos_date, int hf_dos_time, gboolean time_first)
{
guint16 dos_time, dos_date;
proto_item *item = NULL;
proto_tree *tree = NULL;
struct tm tm;
time_t t;
static const int mday_noleap[12] = {
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
static const int mday_leap[12] = {
31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
#define ISLEAP(y) (((y) % 4) == 0 && (((y) % 100) != 0 || ((y) % 400) == 0))
nstime_t tv;
if (time_first) {
dos_time = tvb_get_letohs(tvb, offset);
dos_date = tvb_get_letohs(tvb, offset+2);
} else {
dos_date = tvb_get_letohs(tvb, offset);
dos_time = tvb_get_letohs(tvb, offset+2);
}
if ((dos_date == 0xffff && dos_time == 0xffff) ||
(dos_date == 0 && dos_time == 0)) {
if(parent_tree){
proto_tree_add_text(parent_tree, tvb, offset, 4,
"%s: No time specified (0x%08x)",
proto_registrar_get_name(hf_date),
(dos_date << 16) | dos_time);
}
offset += 4;
return offset;
}
tm.tm_sec = (dos_time&0x1f)*2;
tm.tm_min = (dos_time>>5)&0x3f;
tm.tm_hour = (dos_time>>11)&0x1f;
tm.tm_mday = dos_date&0x1f;
tm.tm_mon = ((dos_date>>5)&0x0f) - 1;
tm.tm_year = ((dos_date>>9)&0x7f) + 1980 - 1900;
tm.tm_isdst = -1;
if (tm.tm_sec > 59 || tm.tm_min > 59 || tm.tm_hour > 23 ||
tm.tm_mon < 0 || tm.tm_mon > 11 ||
(ISLEAP(tm.tm_year + 1900) ?
tm.tm_mday > mday_leap[tm.tm_mon] :
tm.tm_mday > mday_noleap[tm.tm_mon]) ||
(t = mktime(&tm)) == -1) {
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"%s: Invalid time",
proto_registrar_get_name(hf_date));
tree = proto_item_add_subtree(item, ett_smb_time_date);
if (time_first) {
proto_tree_add_uint_format(tree, hf_dos_time, tvb, offset, 2, dos_time, "DOS Time: %02d:%02d:%02d (0x%04x)", tm.tm_hour, tm.tm_min, tm.tm_sec, dos_time);
proto_tree_add_uint_format(tree, hf_dos_date, tvb, offset+2, 2, dos_date, "DOS Date: %04d-%02d-%02d (0x%04x)", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, dos_date);
} else {
proto_tree_add_uint_format(tree, hf_dos_date, tvb, offset, 2, dos_date, "DOS Date: %04d-%02d-%02d (0x%04x)", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, dos_date);
proto_tree_add_uint_format(tree, hf_dos_time, tvb, offset+2, 2, dos_time, "DOS Time: %02d:%02d:%02d (0x%04x)", tm.tm_hour, tm.tm_min, tm.tm_sec, dos_time);
}
}
offset += 4;
return offset;
}
tv.secs = t;
tv.nsecs = 0;
if(parent_tree){
item = proto_tree_add_time(parent_tree, hf_date, tvb, offset, 4, &tv);
tree = proto_item_add_subtree(item, ett_smb_time_date);
if (time_first) {
proto_tree_add_uint_format(tree, hf_dos_time, tvb, offset, 2, dos_time, "DOS Time: %02d:%02d:%02d (0x%04x)", tm.tm_hour, tm.tm_min, tm.tm_sec, dos_time);
proto_tree_add_uint_format(tree, hf_dos_date, tvb, offset+2, 2, dos_date, "DOS Date: %04d-%02d-%02d (0x%04x)", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, dos_date);
} else {
proto_tree_add_uint_format(tree, hf_dos_date, tvb, offset, 2, dos_date, "DOS Date: %04d-%02d-%02d (0x%04x)", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, dos_date);
proto_tree_add_uint_format(tree, hf_dos_time, tvb, offset+2, 2, dos_time, "DOS Time: %02d:%02d:%02d (0x%04x)", tm.tm_hour, tm.tm_min, tm.tm_sec, dos_time);
}
}
offset += 4;
return offset;
}
static int
dissect_access(tvbuff_t *tvb, proto_tree *parent_tree, int offset, const char *type)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"%s Access: 0x%04x", type, mask);
tree = proto_item_add_subtree(item, ett_smb_desiredaccess);
proto_tree_add_boolean(tree, hf_smb_access_writetru,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_access_caching,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_access_locality,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_access_sharing,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_access_mode,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_file_attributes(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"File Attributes: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_file_attributes);
proto_tree_add_boolean(tree, hf_smb_file_attr_archive_16bit,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_directory_16bit,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_volume_16bit,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_system_16bit,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_hidden_16bit,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_read_only_16bit,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_file_ext_attr_bits(tvbuff_t *tvb, proto_tree *parent_tree, int offset,
int len, guint32 mask)
{
proto_item *item;
proto_tree *tree;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"File Attributes: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_smb_file_attributes);
proto_tree_add_boolean(tree, hf_smb_file_eattr_encrypted,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_not_content_indexed,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_offline,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_compressed,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_reparse,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_sparse,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_temporary,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_normal,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_device,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_archive,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_directory,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_volume,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_system,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_hidden,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_file_eattr_read_only,
tvb, offset, len, mask);
}
offset += len;
return offset;
}
int
dissect_file_ext_attr(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
mask = tvb_get_letohl(tvb, offset);
offset = dissect_file_ext_attr_bits(tvb, parent_tree, offset, 4, mask);
return offset;
}
static int
dissect_dir_info_file_attributes(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint8 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_guint8(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"File Attributes: 0x%02x", mask);
tree = proto_item_add_subtree(item, ett_smb_file_attributes);
proto_tree_add_boolean(tree, hf_smb_file_attr_read_only_8bit,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_hidden_8bit,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_system_8bit,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_volume_8bit,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_directory_8bit,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_file_attr_archive_8bit,
tvb, offset, 1, mask);
}
offset += 1;
return offset;
}
static int
dissect_search_attributes(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Search Attributes: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_search);
proto_tree_add_boolean(tree, hf_smb_search_attribute_read_only,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_search_attribute_hidden,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_search_attribute_system,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_search_attribute_volume,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_search_attribute_directory,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_search_attribute_archive,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_negprot_capabilities(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 4, "Capabilities: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_smb_capabilities);
proto_tree_add_boolean(tree, hf_smb_server_cap_raw_mode,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_mpx_mode,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_unicode,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_large_files,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_nt_smbs,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_rpc_remote_apis,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_nt_status,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_level_ii_oplocks,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_lock_and_read,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_nt_find,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_dfs,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_infolevel_passthru,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_large_readx,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_large_writex,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_lwio,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_unix,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_compressed_data,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_dynamic_reauth,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_server_cap_extended_security,
tvb, offset, 4, mask);
}
return mask;
}
static int
dissect_negprot_rawmode(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2, "Raw Mode: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_rawmode);
proto_tree_add_boolean(tree, hf_smb_rm_read, tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_rm_write, tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_negprot_security_mode(tvbuff_t *tvb, proto_tree *parent_tree, int offset, int wc)
{
guint16 mask = 0;
proto_item *item = NULL;
proto_tree *tree = NULL;
switch(wc){
case 13:
mask = tvb_get_letohs(tvb, offset);
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Security Mode: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_mode);
proto_tree_add_boolean(tree, hf_smb_sm_mode16, tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_sm_password16, tvb, offset, 2, mask);
offset += 2;
break;
case 17:
mask = tvb_get_guint8(tvb, offset);
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"Security Mode: 0x%02x", mask);
tree = proto_item_add_subtree(item, ett_smb_mode);
proto_tree_add_boolean(tree, hf_smb_sm_mode, tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_sm_password, tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_sm_signatures, tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_sm_sig_required, tvb, offset, 1, mask);
offset += 1;
break;
}
return offset;
}
static int
dissect_negprot_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
proto_item *it = NULL;
proto_tree *tr = NULL;
guint16 bc;
guint8 wc;
struct negprot_dialects *dialects = NULL;
smb_info_t *si;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
WORD_COUNT;
BYTE_COUNT;
if(tree){
tvb_ensure_bytes_exist(tvb, offset, bc);
it = proto_tree_add_text(tree, tvb, offset, bc,
"Requested Dialects");
tr = proto_item_add_subtree(it, ett_smb_dialects);
}
if (!pinfo->fd->flags.visited && si->sip) {
dialects = se_alloc(sizeof(struct negprot_dialects));
dialects->num = 0;
si->sip->extra_info_type = SMB_EI_DIALECTS;
si->sip->extra_info = dialects;
}
while(bc){
int len;
const guint8 *str;
proto_item *dit = NULL;
proto_tree *dtr = NULL;
tvb_ensure_bytes_exist(tvb, offset+1, 1);
str = tvb_get_const_stringz(tvb, offset+1, &len);
if(tr){
dit = proto_tree_add_text(tr, tvb, offset, len+1,
"Dialect: %s", str);
dtr = proto_item_add_subtree(dit, ett_smb_dialect);
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(dtr, hf_smb_buffer_format, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(len);
proto_tree_add_string(dtr, hf_smb_dialect_name, tvb, offset,
len, str);
COUNT_BYTES(len);
if (!pinfo->fd->flags.visited && dialects && dialects->num<MAX_DIALECTS) {
dialects->name[dialects->num++] = se_strdup(str);
}
}
END_OF_SMB
return offset;
}
static int
dissect_negprot_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
guint8 wc;
guint16 dialect;
const char *dn;
int dn_len;
guint16 bc;
guint16 ekl=0;
guint32 caps=0;
gint16 tz;
struct negprot_dialects *dialects = NULL;
const char *dialect_name = NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
dialect = tvb_get_letohs(tvb, offset);
if (si->sip && si->sip->extra_info_type==SMB_EI_DIALECTS) {
dialects = si->sip->extra_info;
if (dialect < dialects->num) {
dialect_name = dialects->name[dialect];
}
}
if (!dialect_name) {
dialect_name = "unknown";
}
switch(wc){
case 1:
if(dialect==0xffff){
proto_tree_add_uint_format(tree, hf_smb_dialect_index,
tvb, offset, 2, dialect,
"Selected Index: -1, PC NETWORK PROGRAM 1.0 chosen");
} else {
proto_tree_add_uint(tree, hf_smb_dialect_index,
tvb, offset, 2, dialect);
}
break;
case 13:
proto_tree_add_uint_format(tree, hf_smb_dialect_index,
tvb, offset, 2, dialect,
"Dialect Index: %u, Greater than CORE PROTOCOL and up to LANMAN2.1", dialect);
break;
case 17:
proto_tree_add_uint_format(tree, hf_smb_dialect_index,
tvb, offset, 2, dialect,
"Dialect Index: %u: %s", dialect, dialect_name);
break;
default:
tvb_ensure_bytes_exist(tvb, offset, wc*2);
proto_tree_add_text(tree, tvb, offset, wc*2,
"Words for unknown response format");
offset += wc*2;
goto bytecount;
}
offset += 2;
switch(wc){
case 13:
offset = dissect_negprot_security_mode(tvb, tree, offset, wc);
proto_tree_add_item(tree, hf_smb_max_trans_buf_size,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_max_mpx_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_max_vcs_num,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_negprot_rawmode(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb_session_key,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb_datetime(tvb, tree, offset, hf_smb_server_date_time, hf_smb_server_smb_date, hf_smb_server_smb_time,
TRUE);
tz = tvb_get_letohs(tvb, offset);
proto_tree_add_int_format(tree, hf_smb_server_timezone, tvb, offset, 2, tz, "Server Time Zone: %d min from UTC", tz);
offset += 2;
ekl = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_encryption_key_length, tvb, offset, 2, ekl);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
break;
case 17:
offset = dissect_negprot_security_mode(tvb, tree, offset, wc);
proto_tree_add_item(tree, hf_smb_max_mpx_count,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_max_vcs_num,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_max_trans_buf_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_max_raw_buf_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_session_key,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
caps = dissect_negprot_capabilities(tvb, tree, offset);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_system_time);
tz = tvb_get_letohs(tvb, offset);
proto_tree_add_int_format(tree, hf_smb_server_timezone,
tvb, offset, 2, tz,
"Server Time Zone: %d min from UTC", tz);
offset += 2;
ekl = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_encryption_key_length,
tvb, offset, 1, ekl);
offset += 1;
break;
}
BYTE_COUNT;
switch(wc){
case 13:
if(ekl){
CHECK_BYTE_COUNT(ekl);
proto_tree_add_item(tree, hf_smb_encryption_key, tvb, offset, ekl, ENC_NA);
COUNT_BYTES(ekl);
}
dn = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &dn_len, FALSE, FALSE, &bc);
if (dn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_primary_domain, tvb,
offset, dn_len,dn);
COUNT_BYTES(dn_len);
break;
case 17:
if(!(caps&SERVER_CAP_EXTENDED_SECURITY)){
if(ekl){
CHECK_BYTE_COUNT(ekl);
proto_tree_add_item(tree, hf_smb_encryption_key,
tvb, offset, ekl, ENC_NA);
COUNT_BYTES(ekl);
}
si->unicode = (caps&SERVER_CAP_UNICODE) ||
si->unicode;
dn = get_unicode_or_ascii_string(tvb,
&offset, si->unicode, &dn_len, TRUE, FALSE,
&bc);
if (dn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_primary_domain,
tvb, offset, dn_len, dn);
COUNT_BYTES(dn_len);
dn = get_unicode_or_ascii_string(tvb,
&offset, si->unicode, &dn_len, TRUE, FALSE,
&bc);
if (dn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_server,
tvb, offset, dn_len, dn);
COUNT_BYTES(dn_len);
} else {
proto_item *blob_item;
guint16 sbloblen;
CHECK_BYTE_COUNT(16);
proto_tree_add_item(tree, hf_smb_server_guid,
tvb, offset, 16, ENC_NA);
COUNT_BYTES(16);
sbloblen=bc;
if(sbloblen>tvb_length_remaining(tvb, offset)){
sbloblen=tvb_length_remaining(tvb,offset);
}
blob_item = proto_tree_add_item(
tree, hf_smb_security_blob,
tvb, offset, sbloblen, ENC_NA);
if(bc){
tvbuff_t *gssapi_tvb;
proto_tree *gssapi_tree;
gssapi_tree = proto_item_add_subtree(
blob_item, ett_smb_secblob);
gssapi_tvb = tvb_new_subset(
tvb, offset, sbloblen, bc);
call_dissector(
gssapi_handle, gssapi_tvb, pinfo,
gssapi_tree);
if (si->ct)
si->ct->raw_ntlmssp = 0;
COUNT_BYTES(bc);
}
else {
if (si->ct)
si->ct->raw_ntlmssp = 1;
}
}
break;
}
END_OF_SMB
return offset;
}
static int
dissect_old_dir_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int dn_len;
const char *dn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
dn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &dn_len,
FALSE, FALSE, &bc);
if((!pinfo->fd->flags.visited) && si->sip){
si->sip->extra_info_type=SMB_EI_FILENAME;
si->sip->extra_info=se_strdup(dn);
}
if (dn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_dir_name, tvb, offset, dn_len,
dn);
COUNT_BYTES(dn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Directory: %s",
format_text(dn, strlen(dn)));
}
END_OF_SMB
return offset;
}
static int
dissect_empty(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
smb_info_t *si = pinfo->private_data;
proto_item *item=NULL;
DISSECTOR_ASSERT(si);
if(si->sip && si->sip->extra_info_type==SMB_EI_FILENAME){
item=proto_tree_add_string(tree, hf_smb_file_name, tvb, 0, 0, si->sip->extra_info);
PROTO_ITEM_SET_GENERATED(item);
}
WORD_COUNT;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_rename_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
smb_info_t *si = pinfo->private_data;
proto_item *item=NULL;
DISSECTOR_ASSERT(si);
if(si->sip && si->sip->extra_info_type==SMB_EI_RENAMEDATA){
smb_rename_saved_info_t *rni=si->sip->extra_info;
item=proto_tree_add_string(tree, hf_smb_old_file_name, tvb, 0, 0, rni->old_name);
PROTO_ITEM_SET_GENERATED(item);
item=proto_tree_add_string(tree, hf_smb_file_name, tvb, 0, 0, rni->new_name);
PROTO_ITEM_SET_GENERATED(item);
}
WORD_COUNT;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_echo_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 ec, bc;
guint8 wc;
WORD_COUNT;
ec = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_echo_count, tvb, offset, 2, ec);
offset += 2;
BYTE_COUNT;
if (bc != 0) {
proto_tree_add_item(tree, hf_smb_echo_data, tvb, offset, bc, ENC_NA);
COUNT_BYTES(bc);
}
END_OF_SMB
return offset;
}
static int
dissect_echo_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 bc;
guint8 wc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_echo_seq_num, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
if (bc != 0) {
proto_tree_add_item(tree, hf_smb_echo_data, tvb, offset, bc, ENC_NA);
COUNT_BYTES(bc);
}
END_OF_SMB
return offset;
}
static int
dissect_tree_connect_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int an_len, pwlen;
const char *an;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_path, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(an, strlen(an)));
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
pwlen = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(pwlen);
proto_tree_add_item(tree, hf_smb_password,
tvb, offset, pwlen, ENC_NA);
COUNT_BYTES(pwlen);
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_service, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
END_OF_SMB
return offset;
}
static int
dissect_smb_uid(tvbuff_t *tvb, proto_tree *parent_tree, int offset, smb_info_t *si)
{
proto_item *item, *subitem;
proto_tree *tree;
smb_uid_t *smb_uid=NULL;
item=proto_tree_add_uint(parent_tree, hf_smb_uid, tvb, offset, 2, si->uid);
tree=proto_item_add_subtree(item, ett_smb_uid);
smb_uid=se_tree_lookup32(si->ct->uid_tree, si->uid);
if(smb_uid){
if(smb_uid->domain && smb_uid->account)
proto_item_append_text(item, " (");
if(smb_uid->domain){
proto_item_append_text(item, "%s", smb_uid->domain);
subitem=proto_tree_add_string(tree, hf_smb_primary_domain, tvb, 0, 0, smb_uid->domain);
PROTO_ITEM_SET_GENERATED(subitem);
}
if(smb_uid->account){
proto_item_append_text(item, "\\%s", smb_uid->account);
subitem=proto_tree_add_string(tree, hf_smb_account, tvb, 0, 0, smb_uid->account);
PROTO_ITEM_SET_GENERATED(subitem);
}
if(smb_uid->domain && smb_uid->account)
proto_item_append_text(item, ")");
if(smb_uid->logged_in>0){
subitem=proto_tree_add_uint(tree, hf_smb_logged_in, tvb, 0, 0, smb_uid->logged_in);
PROTO_ITEM_SET_GENERATED(subitem);
}
if(smb_uid->logged_out>0){
subitem=proto_tree_add_uint(tree, hf_smb_logged_out, tvb, 0, 0, smb_uid->logged_out);
PROTO_ITEM_SET_GENERATED(subitem);
}
}
offset += 2;
return offset;
}
static int
dissect_smb_tid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 tid, gboolean is_created, gboolean is_closed)
{
smb_info_t *si = pinfo->private_data;
proto_item *it;
proto_tree *tr;
smb_tid_info_t *tid_info=NULL;
DISSECTOR_ASSERT(si);
it=proto_tree_add_uint(tree, hf_smb_tid, tvb, offset, 2, tid);
tr=proto_item_add_subtree(it, ett_smb_tid);
offset += 2;
if((!pinfo->fd->flags.visited) && is_created){
tid_info=se_alloc(sizeof(smb_tid_info_t));
tid_info->opened_in=pinfo->fd->num;
tid_info->closed_in=0;
tid_info->type=SMB_FID_TYPE_UNKNOWN;
if(si->sip && (si->sip->extra_info_type==SMB_EI_TIDNAME)){
tid_info->filename=si->sip->extra_info;
} else {
tid_info->filename=NULL;
}
se_tree_insert32(si->ct->tid_tree, tid, tid_info);
}
if(!tid_info){
tid_info=se_tree_lookup32_le(si->ct->tid_tree, tid);
}
if(!tid_info){
return offset;
}
if((!pinfo->fd->flags.visited) && is_closed){
tid_info->closed_in=pinfo->fd->num;
}
if(tid_info->opened_in){
if(tid_info->filename){
proto_item_append_text(it, " (%s)", tid_info->filename);
it=proto_tree_add_string(tr, hf_smb_path, tvb, 0, 0, tid_info->filename);
PROTO_ITEM_SET_GENERATED(it);
}
it=proto_tree_add_uint(tr, hf_smb_mapped_in, tvb, 0, 0, tid_info->opened_in);
PROTO_ITEM_SET_GENERATED(it);
}
if(tid_info->closed_in){
it=proto_tree_add_uint(tr, hf_smb_unmapped_in, tvb, 0, 0, tid_info->closed_in);
PROTO_ITEM_SET_GENERATED(it);
}
return offset;
}
static int
dissect_tree_connect_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_max_buf_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset=dissect_smb_tid(tvb, pinfo, tree, offset, tvb_get_letohs(tvb, offset), TRUE, FALSE);
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_open_function(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Open Function: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_openfunction);
}
proto_tree_add_boolean(tree, hf_smb_open_function_create,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_open_function_open,
tvb, offset, 2, mask);
offset += 2;
return offset;
}
static int
dissect_move_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_move_copy_flags);
}
proto_tree_add_boolean(tree, hf_smb_move_flags_verify,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_move_flags_dir,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_move_flags_file,
tvb, offset, 2, mask);
offset += 2;
return offset;
}
static int
dissect_copy_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_move_copy_flags);
}
proto_tree_add_boolean(tree, hf_smb_copy_flags_ea_action,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_copy_flags_tree_copy,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_copy_flags_verify,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_copy_flags_source_mode,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_copy_flags_dest_mode,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_copy_flags_dir,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_copy_flags_file,
tvb, offset, 2, mask);
offset += 2;
return offset;
}
static int
dissect_move_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
guint16 tid;
guint16 bc;
guint8 wc;
const char *fn;
DISSECTOR_ASSERT(si);
WORD_COUNT;
tid = tvb_get_letohs(tvb, offset);
offset=dissect_smb_tid(tvb, pinfo, tree, offset, tid, FALSE, FALSE);
offset = dissect_open_function(tvb, tree, offset);
offset = dissect_move_flags(tvb, tree, offset);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string_format(tree, hf_smb_file_name, tvb, offset,
fn_len, fn, "Old File Name: %s", format_text(fn, strlen(fn)));
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Old Name: %s",
format_text(fn, strlen(fn)));
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string_format(tree, hf_smb_file_name, tvb, offset,
fn_len, fn, "New File Name: %s", format_text(fn, strlen(fn)));
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", New Name: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_copy_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
guint16 tid;
guint16 bc;
guint8 wc;
const char *fn;
DISSECTOR_ASSERT(si);
WORD_COUNT;
tid = tvb_get_letohs(tvb, offset);
offset=dissect_smb_tid(tvb, pinfo, tree, offset, tid, FALSE, FALSE);
offset = dissect_open_function(tvb, tree, offset);
offset = dissect_copy_flags(tvb, tree, offset);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string_format(tree, hf_smb_file_name, tvb, offset,
fn_len, fn, "Source File Name: %s", format_text(fn, strlen(fn)));
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source Name: %s",
format_text(fn, strlen(fn)));
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string_format(tree, hf_smb_file_name, tvb, offset,
fn_len, fn, "Destination File Name: %s",
format_text(fn, strlen(fn)));
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Destination Name: %s", format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_move_copy_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_files_moved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
END_OF_SMB
return offset;
}
static int
dissect_open_file_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
offset = dissect_access(tvb, tree, offset, "Desired");
offset = dissect_search_attributes(tvb, tree, offset);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_nt_create_bits(tvbuff_t *tvb, proto_tree *parent_tree, int offset,
int len, guint32 mask)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_smb_create_flags, tvb, offset, len, mask);
tree = proto_item_add_subtree(item, ett_smb_nt_create_bits);
}
proto_tree_add_boolean(tree, hf_smb_nt_create_bits_ext_resp,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_bits_dir,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_bits_boplock,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_bits_oplock,
tvb, offset, len, mask);
offset += len;
return offset;
}
static int
dissect_smb_access_mask_bits(tvbuff_t *tvb, proto_tree *parent_tree,
int offset, int len, guint32 mask)
{
proto_item *item;
proto_tree *tree;
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_smb_access_mask, tvb, offset, len, mask);
tree = proto_item_add_subtree(item, ett_smb_nt_access_mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_generic_read,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_generic_write,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_generic_execute,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_generic_all,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_maximum_allowed,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_system_security,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_synchronize,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_write_owner,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_write_dac,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_read_control,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_delete,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_write_attributes,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_read_attributes,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_delete_child,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_execute,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_write_ea,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_read_ea,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_append,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_write,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_access_mask_read,
tvb, offset, len, mask);
}
offset += len;
return offset;
}
int
dissect_smb_access_mask(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
mask = tvb_get_letohl(tvb, offset);
offset = dissect_smb_access_mask_bits(tvb, parent_tree, offset, 4, mask);
return offset;
}
static int
dissect_nt_share_access_bits(tvbuff_t *tvb, proto_tree *parent_tree,
int offset, int len, guint32 mask)
{
proto_item *item;
proto_tree *tree;
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_smb_share_access, tvb, offset, len, mask);
tree = proto_item_add_subtree(item, ett_smb_nt_share_access);
proto_tree_add_boolean(tree, hf_smb_nt_share_access_delete,
tvb, offset, len, mask);
if(mask&SHARE_ACCESS_DELETE){
proto_item_append_text(item, " SHARE_DELETE");
}
proto_tree_add_boolean(tree, hf_smb_nt_share_access_write,
tvb, offset, len, mask);
if(mask&SHARE_ACCESS_WRITE){
proto_item_append_text(item, " SHARE_WRITE");
}
proto_tree_add_boolean(tree, hf_smb_nt_share_access_read,
tvb, offset, len, mask);
if(mask&SHARE_ACCESS_READ){
proto_item_append_text(item, " SHARE_READ");
}
}
offset += len;
return offset;
}
int
dissect_nt_share_access(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
mask = tvb_get_letohl(tvb, offset);
offset = dissect_nt_share_access_bits(tvb, parent_tree, offset, 4, mask);
return offset;
}
static int
dissect_nt_create_options_bits(tvbuff_t *tvb, proto_tree *parent_tree,
int offset, int len, guint32 mask)
{
proto_item *item;
proto_tree *tree;
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_smb_create_options, tvb, offset, len, mask);
tree = proto_item_add_subtree(item, ett_smb_nt_create_options);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_directory_file,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_write_through,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_sequential_only,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_no_intermediate_buffering,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_sync_io_alert,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_sync_io_nonalert,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_non_directory_file,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_create_tree_connection,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_complete_if_oplocked,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_no_ea_knowledge,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_eight_dot_three_only,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_random_access,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_delete_on_close,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_open_by_fileid,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_backup_intent,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_no_compression,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_reserve_opfilter,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_open_reparse_point,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_open_no_recall,
tvb, offset, len, mask);
proto_tree_add_boolean(tree, hf_smb_nt_create_options_open_for_free_space_query,
tvb, offset, len, mask);
}
offset += len;
return offset;
}
int
dissect_nt_create_options(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
mask = tvb_get_letohl(tvb, offset);
offset = dissect_nt_create_options_bits(tvb, parent_tree, offset, 4, mask);
return offset;
}
smb_fid_info_t *
dissect_smb_fid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
int len, guint16 fid, gboolean is_created, gboolean is_closed, gboolean is_generated)
{
smb_info_t *si = pinfo->private_data;
smb_saved_info_t *sip = si->sip;
proto_item *it;
proto_tree *tr;
smb_fid_info_t *fid_info=NULL;
smb_fid_info_t *suspect_fid_info=NULL;
GSList *GSL_iterator;
DISSECTOR_ASSERT(si);
it=proto_tree_add_uint(tree, hf_smb_fid, tvb, offset, len, fid);
if(is_generated){
PROTO_ITEM_SET_GENERATED(it);
}
tr=proto_item_add_subtree(it, ett_smb_fid);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", FID: 0x%04x", fid);
if((!pinfo->fd->flags.visited) && is_created){
fid_info=se_alloc(sizeof(smb_fid_info_t));
fid_info->opened_in=pinfo->fd->num;
fid_info->closed_in=0;
fid_info->type=SMB_FID_TYPE_UNKNOWN;
fid_info->fid=fid;
fid_info->tid=si->tid;
if(si->sip && (si->sip->extra_info_type==SMB_EI_FILEDATA)){
fid_info->fsi=si->sip->extra_info;
} else {
fid_info->fsi=NULL;
}
si->ct->GSL_fid_info=g_slist_insert_sorted(
si->ct->GSL_fid_info,
fid_info,
(GCompareFunc)fid_cmp);
}
if(!fid_info){
GSL_iterator = si->ct->GSL_fid_info;
while (GSL_iterator) {
suspect_fid_info=GSL_iterator->data;
if(suspect_fid_info->opened_in > pinfo->fd->num) break;
if(suspect_fid_info->tid==si->tid && suspect_fid_info->fid==fid)
fid_info=suspect_fid_info;
GSL_iterator=g_slist_next(GSL_iterator);
}
}
if(!fid_info){
return NULL;
}
if(sip && (!is_generated) && (!pinfo->fd->flags.visited)) {
sip->fid=fid;
if(si->request){
sip->fid_seen_in_request=TRUE;
} else {
sip->fid_seen_in_request=FALSE;
}
}
if((!pinfo->fd->flags.visited) && is_closed){
fid_info->closed_in=pinfo->fd->num;
}
if(fid_info->opened_in){
it=proto_tree_add_uint(tr, hf_smb_opened_in, tvb, 0, 0, fid_info->opened_in);
PROTO_ITEM_SET_GENERATED(it);
}
if(fid_info->closed_in){
it=proto_tree_add_uint(tr, hf_smb_closed_in, tvb, 0, 0, fid_info->closed_in);
PROTO_ITEM_SET_GENERATED(it);
}
if(fid_info->opened_in){
if(fid_info->fsi && fid_info->fsi->filename){
it=proto_tree_add_string(tr, hf_smb_file_name, tvb, 0, 0, fid_info->fsi->filename);
PROTO_ITEM_SET_GENERATED(it);
proto_item_append_text(tr, " (%s)", fid_info->fsi->filename);
dissect_nt_create_bits(tvb, tr, 0, 0, fid_info->fsi->create_flags);
dissect_smb_access_mask_bits(tvb, tr, 0, 0, fid_info->fsi->access_mask);
dissect_file_ext_attr_bits(tvb, tr, 0, 0, fid_info->fsi->file_attributes);
dissect_nt_share_access_bits(tvb, tr, 0, 0, fid_info->fsi->share_access);
dissect_nt_create_options_bits(tvb, tr, 0, 0, fid_info->fsi->create_options);
it=proto_tree_add_uint(tr, hf_smb_nt_create_disposition, tvb, 0, 0, fid_info->fsi->create_disposition);
PROTO_ITEM_SET_GENERATED(it);
}
}
return fid_info;
}
static int
dissect_open_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_last_write_time);
proto_tree_add_item(tree, hf_smb_file_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_access(tvb, tree, offset, "Granted");
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_query_information2_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_close_print_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, TRUE, FALSE);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_open_print_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_create_new_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_flush_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_create_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_create_file_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_create_time);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_close_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, TRUE, FALSE);
offset += 2;
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_last_write_time);
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_delete_file_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
offset = dissect_search_attributes(tvb, tree, offset);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if((!pinfo->fd->flags.visited) && si->sip){
si->sip->extra_info_type=SMB_EI_FILENAME;
si->sip->extra_info=se_strdup(fn);
}
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_rename_file_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn, *old_name=NULL, *new_name=NULL;
guint8 wc;
guint16 bc;
smb_rename_saved_info_t *rni=NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
offset = dissect_search_attributes(tvb, tree, offset);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
old_name=fn;
proto_tree_add_string(tree, hf_smb_old_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Old Name: %s",
format_text(fn, strlen(fn)));
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
new_name=fn;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", New Name: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
if(si->sip && !pinfo->fd->flags.visited){
rni=se_alloc(sizeof(smb_rename_saved_info_t));
rni->old_name=se_strdup(old_name);
rni->new_name=se_strdup(new_name);
si->sip->extra_info_type=SMB_EI_RENAMEDATA;
si->sip->extra_info=rni;
}
return offset;
}
static int
dissect_nt_rename_file_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
offset = dissect_search_attributes(tvb, tree, offset);
proto_tree_add_uint(tree, hf_smb_nt_rename_level, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_item(tree, hf_smb_cluster_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_old_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Old Name: %s",
format_text(fn, strlen(fn)));
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", New Name: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_query_information_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
guint16 bc;
guint8 wc;
const char *fn;
int fn_len;
DISSECTOR_ASSERT(si);
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_query_information_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 bc;
guint8 wc;
WORD_COUNT;
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_last_write_time);
proto_tree_add_item(tree, hf_smb_file_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 10, ENC_NA);
offset += 10;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_set_information_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_last_write_time);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 10, ENC_NA);
offset += 10;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_read_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 cnt=0, bc;
guint32 ofs=0;
unsigned int fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, (guint16) fid, FALSE, FALSE, FALSE);
offset += 2;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
ofs = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s at offset %u", cnt,
(cnt == 1) ? "" : "s", ofs);
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
int
dissect_file_data(tvbuff_t *tvb, proto_tree *tree, int offset, guint16 bc, guint16 datalen)
{
int tvblen;
if(bc>datalen){
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, bc-datalen,
ENC_NA);
offset += bc-datalen;
bc = datalen;
}
tvblen = tvb_length_remaining(tvb, offset);
if(bc>tvblen){
proto_tree_add_bytes_format(tree, hf_smb_file_data, tvb, offset, tvblen, NULL,"File Data: Incomplete. Only %d of %u bytes", tvblen, bc);
offset += tvblen;
} else {
proto_tree_add_item(tree, hf_smb_file_data, tvb, offset, bc, ENC_NA);
offset += bc;
}
return offset;
}
static int
dissect_file_data_dcerpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *top_tree, int offset, guint16 bc, guint16 datalen, guint16 fid)
{
int tvblen;
tvbuff_t *dcerpc_tvb;
if(bc>datalen){
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, bc-datalen,
ENC_NA);
offset += bc-datalen;
bc = datalen;
}
tvblen = tvb_length_remaining(tvb, offset);
dcerpc_tvb = tvb_new_subset(tvb, offset, tvblen, bc);
dissect_pipe_dcerpc(dcerpc_tvb, pinfo, top_tree, tree, fid);
if(bc>tvblen)
offset += tvblen;
else
offset += bc;
return offset;
}
static int
dissect_file_data_maybe_dcerpc(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, proto_tree *top_tree, int offset, guint16 bc,
guint16 datalen, guint32 ofs, guint16 fid)
{
smb_info_t *si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if( (si->sip && si->sip->flags&SMB_SIF_TID_IS_IPC) && (ofs==0) ){
return dissect_file_data_dcerpc(tvb, pinfo, tree,
top_tree, offset, bc, datalen, fid);
} else {
return dissect_file_data(tvb, tree, offset, bc, datalen);
}
}
static int
dissect_read_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 cnt=0, bc;
guint8 wc;
smb_info_t *si = (smb_info_t *)pinfo->private_data;
int fid=0;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count, tvb, offset, 2, cnt);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 8, ENC_NA);
offset += 8;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(tree, hf_smb_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
if(bc){
offset = dissect_file_data_maybe_dcerpc(tvb, pinfo, tree,
top_tree_global, offset, bc, bc, 0, (guint16) fid);
bc = 0;
}
END_OF_SMB
return offset;
}
static int
dissect_lock_and_read_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 cnt, bc;
guint8 wc;
WORD_COUNT;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count, tvb, offset, 2, cnt);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 8, ENC_NA);
offset += 8;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(tree, hf_smb_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
END_OF_SMB
return offset;
}
static int
dissect_write_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint32 ofs=0;
guint16 cnt=0, bc, fid=0;
guint8 wc;
smb_info_t *si = (smb_info_t *)pinfo->private_data;
rw_info_t *rwi=NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count, tvb, offset, 2, cnt);
offset += 2;
ofs = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s at offset %u", cnt,
(cnt == 1) ? "" : "s", ofs);
if(si->sip && !pinfo->fd->flags.visited){
rwi=se_alloc(sizeof(rw_info_t));
rwi->offset=ofs;
rwi->len=cnt;
rwi->fid=fid;
si->sip->extra_info_type=SMB_EI_RWINFO;
si->sip->extra_info=rwi;
}
if(si->sip && si->sip->extra_info_type==SMB_EI_RWINFO){
rwi=si->sip->extra_info;
}
if(rwi){
proto_item *it;
it=proto_tree_add_uint64(tree, hf_smb_file_rw_offset, tvb, 0, 0, rwi->offset);
PROTO_ITEM_SET_GENERATED(it);
it=proto_tree_add_uint(tree, hf_smb_file_rw_length, tvb, 0, 0, rwi->len);
PROTO_ITEM_SET_GENERATED(it);
}
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(tree, hf_smb_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
if (bc != 0) {
offset = dissect_file_data_maybe_dcerpc(tvb, pinfo, tree,
top_tree_global, offset, bc, bc, ofs, fid);
bc = 0;
}
END_OF_SMB
return offset;
}
static int
dissect_write_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, cnt;
smb_info_t *si = (smb_info_t *)pinfo->private_data;
rw_info_t *rwi=NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s", cnt, (cnt == 1) ? "" : "s");
if(si->sip && si->sip->extra_info_type==SMB_EI_RWINFO){
rwi=si->sip->extra_info;
}
if(rwi){
proto_item *it;
it=proto_tree_add_uint64(tree, hf_smb_file_rw_offset, tvb, 0, 0, rwi->offset);
PROTO_ITEM_SET_GENERATED(it);
it=proto_tree_add_uint(tree, hf_smb_file_rw_length, tvb, 0, 0, rwi->len);
PROTO_ITEM_SET_GENERATED(it);
}
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_lock_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_create_temporary_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_create_time);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_dir_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
return offset;
}
static int
dissect_create_temporary_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc, fid;
DISSECTOR_ASSERT(si);
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
END_OF_SMB
return offset;
}
static int
dissect_seek_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_seek_mode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_seek_file_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_set_information2_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time,
hf_smb_create_dos_date, hf_smb_create_dos_time, FALSE);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_access_time,
hf_smb_access_dos_date, hf_smb_access_dos_time, FALSE);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time,
hf_smb_last_write_dos_date, hf_smb_last_write_dos_time, FALSE);
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_query_information2_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time,
hf_smb_create_dos_date, hf_smb_create_dos_time, FALSE);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_access_time,
hf_smb_access_dos_date, hf_smb_access_dos_time, FALSE);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time,
hf_smb_last_write_dos_date, hf_smb_last_write_dos_time, FALSE);
proto_tree_add_item(tree, hf_smb_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_file_attributes(tvb, tree, offset);
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_write_and_close_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 cnt=0;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, TRUE, FALSE);
offset += 2;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count, tvb, offset, 2, cnt);
offset += 2;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_last_write_time);
if(wc==12){
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 12, ENC_NA);
offset += 12;
}
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, 1, ENC_NA);
COUNT_BYTES(1);
offset = dissect_file_data(tvb, tree, offset, cnt, cnt);
bc = 0;
END_OF_SMB
return offset;
}
static int
dissect_write_and_close_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static gchar *
smbext20_timeout_msecs_to_str(gint32 timeout)
{
gchar *buf;
#define SMBEXT20_TIMEOUT_MSECS_TO_STR_MAXLEN 60
if (timeout <= 0) {
buf=ep_alloc(SMBEXT20_TIMEOUT_MSECS_TO_STR_MAXLEN+1);
if (timeout == 0) {
g_snprintf(buf, SMBEXT20_TIMEOUT_MSECS_TO_STR_MAXLEN+1, "Return immediately (0)");
} else if (timeout == -1) {
g_snprintf(buf, SMBEXT20_TIMEOUT_MSECS_TO_STR_MAXLEN+1, "Wait indefinitely (-1)");
} else if (timeout == -2) {
g_snprintf(buf, SMBEXT20_TIMEOUT_MSECS_TO_STR_MAXLEN+1, "Use default timeout (-2)");
} else {
g_snprintf(buf, SMBEXT20_TIMEOUT_MSECS_TO_STR_MAXLEN+1, "Unknown reserved value (%d)", timeout);
}
return buf;
}
return time_msecs_to_str(timeout);
}
static int
dissect_read_raw_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, fid;
guint32 to;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_max_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_min_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
to = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_smb_timeout, tvb, offset, 4, to, "Timeout: %s", smbext20_timeout_msecs_to_str(to));
offset += 4;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
if(wc==10){
proto_tree_add_item(tree, hf_smb_high_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_query_information_disk_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_units, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_bpu, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_blocksize, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_freeunits, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_read_mpx_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_max_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_min_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 6, ENC_NA);
offset += 6;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_read_mpx_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 datalen=0, bc;
guint8 wc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_smb_dcm, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
datalen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len, tvb, offset, 2, datalen);
offset += 2;
proto_tree_add_item(tree, hf_smb_data_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
offset = dissect_file_data(tvb, tree, offset, bc, datalen);
bc = 0;
END_OF_SMB
return offset;
}
static int
dissect_write_mode(tvbuff_t *tvb, proto_tree *parent_tree, int offset, int bm)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Write Mode: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_rawmode);
if(bm&WRITE_MODE_CONNECTIONLESS){
proto_tree_add_boolean(tree, hf_smb_write_mode_connectionless,
tvb, offset, 2, mask);
}
if(bm&WRITE_MODE_MESSAGE_START){
proto_tree_add_boolean(tree, hf_smb_write_mode_message_start,
tvb, offset, 2, mask);
}
if(bm&WRITE_MODE_RAW){
proto_tree_add_boolean(tree, hf_smb_write_mode_raw,
tvb, offset, 2, mask);
}
if(bm&WRITE_MODE_RETURN_REMAINING){
proto_tree_add_boolean(tree, hf_smb_write_mode_return_remaining,
tvb, offset, 2, mask);
}
if(bm&WRITE_MODE_WRITE_THROUGH){
proto_tree_add_boolean(tree, hf_smb_write_mode_write_through,
tvb, offset, 2, mask);
}
}
offset += 2;
return offset;
}
static int
dissect_write_raw_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint32 to;
guint16 datalen=0, bc, fid;
guint8 wc;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_total_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
to = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_smb_timeout, tvb, offset, 4, to, "Timeout: %s", smbext20_timeout_msecs_to_str(to));
offset += 4;
offset = dissect_write_mode(tvb, tree, offset, 0x0003);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
datalen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len, tvb, offset, 2, datalen);
offset += 2;
proto_tree_add_item(tree, hf_smb_data_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
offset = dissect_file_data(tvb, tree, offset, bc, datalen);
bc = 0;
END_OF_SMB
return offset;
}
static int
dissect_write_raw_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_write_mpx_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint32 to;
guint16 datalen=0, bc, fid;
guint8 wc;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_total_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
to = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_smb_timeout, tvb, offset, 4, to, "Timeout: %s", smbext20_timeout_msecs_to_str(to));
offset += 4;
offset = dissect_write_mode(tvb, tree, offset, 0x0083);
proto_tree_add_item(tree, hf_smb_request_mask, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
datalen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len, tvb, offset, 2, datalen);
offset += 2;
proto_tree_add_item(tree, hf_smb_data_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
offset = dissect_file_data(tvb, tree, offset, bc, datalen);
bc = 0;
END_OF_SMB
return offset;
}
static int
dissect_write_mpx_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_response_mask, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_sid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_search_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_search_resume_key(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent_tree, int offset, guint16 *bcp, gboolean *trunc,
gboolean has_find_id)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
char fname[11+1];
DISSECTOR_ASSERT(si);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 21,
"Resume Key");
tree = proto_item_add_subtree(item, ett_smb_search_resume_key);
}
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
COUNT_BYTES_SUBR(1);
fn_len = 11;
fn = get_unicode_or_ascii_string(tvb, &offset, FALSE, &fn_len,
TRUE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
g_strlcpy(fname, fn, 11+1);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, 11,
fname);
COUNT_BYTES_SUBR(fn_len);
if (has_find_id) {
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_resume_find_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_resume_server_cookie, tvb, offset, 4, ENC_NA);
COUNT_BYTES_SUBR(4);
} else {
CHECK_BYTE_COUNT_SUBR(5);
proto_tree_add_item(tree, hf_smb_resume_server_cookie, tvb, offset, 5, ENC_NA);
COUNT_BYTES_SUBR(5);
}
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_resume_client_cookie, tvb, offset, 4, ENC_NA);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
static int
dissect_search_dir_info(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent_tree, int offset, guint16 *bcp, gboolean *trunc,
gboolean has_find_id)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
char fname[13+1];
DISSECTOR_ASSERT(si);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 46,
"Directory Information");
tree = proto_item_add_subtree(item, ett_smb_search_dir_info);
}
offset = dissect_search_resume_key(tvb, pinfo, tree, offset, bcp,
trunc, has_find_id);
if (*trunc)
return offset;
CHECK_BYTE_COUNT_SUBR(1);
offset = dissect_dir_info_file_attributes(tvb, tree, offset);
*bcp -= 1;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time,
hf_smb_last_write_dos_date, hf_smb_last_write_dos_time,
TRUE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
fn_len = 13;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
TRUE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
g_strlcpy(fname, fn, 13+1);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fname);
COUNT_BYTES_SUBR(fn_len);
*trunc = FALSE;
return offset;
}
static int
dissect_search_find_request(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, proto_tree *smb_tree _U_,
gboolean has_find_id)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint16 rkl;
guint8 wc;
guint16 bc;
gboolean trunc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_max_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_search_attributes(tvb, tree, offset);
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
TRUE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", File: %s",
format_text(fn, strlen(fn)));
}
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
rkl = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_resume_key_len, tvb, offset, 2, rkl);
COUNT_BYTES(2);
if(rkl){
offset = dissect_search_resume_key(tvb, pinfo, tree, offset,
&bc, &trunc, has_find_id);
if (trunc)
goto endofcommand;
}
END_OF_SMB
return offset;
}
static int
dissect_search_dir_request(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
return dissect_search_find_request(tvb, pinfo, tree, offset,
smb_tree, FALSE);
}
static int
dissect_find_request(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
return dissect_search_find_request(tvb, pinfo, tree, offset,
smb_tree, TRUE);
}
static int
dissect_find_close_request(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
return dissect_search_find_request(tvb, pinfo, tree, offset,
smb_tree, TRUE);
}
static int
dissect_search_find_response(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset, proto_tree *smb_tree _U_,
gboolean has_find_id)
{
guint16 count=0;
guint8 wc;
guint16 bc;
gboolean trunc;
WORD_COUNT;
count = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count, tvb, offset, 2, count);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(tree, hf_smb_data_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
while(count--){
offset = dissect_search_dir_info(tvb, pinfo, tree, offset,
&bc, &trunc, has_find_id);
if (trunc)
goto endofcommand;
}
END_OF_SMB
return offset;
}
static int
dissect_search_dir_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
return dissect_search_find_response(tvb, pinfo, tree, offset, smb_tree,
FALSE);
}
static int
dissect_find_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
return dissect_search_find_response(tvb, pinfo, tree, offset, smb_tree,
TRUE);
}
static int
dissect_find_close_response(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
guint16 data_len;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
data_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len, tvb, offset, 2, data_len);
COUNT_BYTES(2);
if (data_len != 0) {
CHECK_BYTE_COUNT(data_len);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset,
data_len, ENC_NA);
COUNT_BYTES(data_len);
}
END_OF_SMB
return offset;
}
static int
dissect_locking_andx_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff, lt=0, ol=0;
guint16 andxoffset=0, un=0, ln=0, bc, fid, num_lock=0, num_unlock=0;
guint32 to;
proto_item *litem = NULL;
proto_tree *ltree = NULL;
proto_item *it = NULL;
proto_tree *tr = NULL;
int old_offset = offset;
smb_info_t *si = pinfo->private_data;
smb_locking_saved_info_t *ld=NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
lt = tvb_get_guint8(tvb, offset);
if(tree){
litem = proto_tree_add_text(tree, tvb, offset, 1,
"Lock Type: 0x%02x", lt);
ltree = proto_item_add_subtree(litem, ett_smb_lock_type);
proto_tree_add_boolean(ltree, hf_smb_lock_type_large,
tvb, offset, 1, lt);
proto_tree_add_boolean(ltree, hf_smb_lock_type_cancel,
tvb, offset, 1, lt);
proto_tree_add_boolean(ltree, hf_smb_lock_type_change,
tvb, offset, 1, lt);
proto_tree_add_boolean(ltree, hf_smb_lock_type_oplock,
tvb, offset, 1, lt);
proto_tree_add_boolean(ltree, hf_smb_lock_type_shared,
tvb, offset, 1, lt);
}
offset += 1;
ol = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_smb_locking_ol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
to = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_smb_timeout, tvb, offset, 4, to, "Timeout: %s", smbext20_timeout_msecs_to_str(to));
offset += 4;
un = tvb_get_letohs(tvb, offset);
num_unlock=un;
proto_tree_add_uint(tree, hf_smb_number_of_unlocks, tvb, offset, 2, un);
offset += 2;
ln = tvb_get_letohs(tvb, offset);
num_lock=ln;
proto_tree_add_uint(tree, hf_smb_number_of_locks, tvb, offset, 2, ln);
offset += 2;
BYTE_COUNT;
if((!pinfo->fd->flags.visited) && si->sip){
ld=se_alloc(sizeof(smb_locking_saved_info_t));
ld->type=lt;
ld->oplock_level= ol;
ld->num_lock=num_lock;
ld->num_unlock=num_unlock;
ld->locks=NULL;
ld->unlocks=NULL;
si->sip->extra_info_type=SMB_EI_LOCKDATA;
si->sip->extra_info=ld;
}
if(un){
old_offset = offset;
it = proto_tree_add_text(tree, tvb, offset, -1,
"Unlocks");
tr = proto_item_add_subtree(it, ett_smb_unlocks);
while(un--){
proto_item *litem_2 = NULL;
proto_tree *ltree_2 = NULL;
if(lt&0x10){
guint64 val;
guint16 lock_pid;
guint64 lock_offset;
guint64 lock_length;
litem_2 = proto_tree_add_text(tr, tvb, offset, 20,
"Unlock");
ltree_2 = proto_item_add_subtree(litem_2, ett_smb_unlock);
CHECK_BYTE_COUNT(2);
lock_pid=tvb_get_letohs(tvb, offset);
proto_tree_add_item(ltree_2, hf_smb_pid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(ltree_2, hf_smb_reserved, tvb, offset, 2, ENC_NA);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(8);
val=((guint64)tvb_get_letohl(tvb, offset)) << 32
| tvb_get_letohl(tvb, offset+4);
lock_offset=val;
proto_tree_add_uint64(ltree_2, hf_smb_lock_long_offset, tvb, offset, 8, val);
COUNT_BYTES(8);
CHECK_BYTE_COUNT(8);
val=((guint64)tvb_get_letohl(tvb, offset)) << 32
| tvb_get_letohl(tvb, offset+4);
lock_length=val;
proto_tree_add_uint64(ltree_2, hf_smb_lock_long_length, tvb, offset, 8, val);
COUNT_BYTES(8);
if(ld){
smb_lock_info_t *li;
li=se_alloc(sizeof(smb_lock_info_t));
li->next=ld->unlocks;
ld->unlocks=li;
li->pid=lock_pid;
li->offset=lock_offset;
li->length=lock_length;
}
} else {
litem_2 = proto_tree_add_text(tr, tvb, offset, 10,
"Unlock");
ltree_2 = proto_item_add_subtree(litem_2, ett_smb_unlock);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(ltree_2, hf_smb_pid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(4);
proto_tree_add_item(ltree_2, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
CHECK_BYTE_COUNT(4);
proto_tree_add_item(ltree_2, hf_smb_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
}
}
proto_item_set_len(it, offset-old_offset);
it = NULL;
}
if(ln){
old_offset = offset;
it = proto_tree_add_text(tree, tvb, offset, -1,
"Locks");
tr = proto_item_add_subtree(it, ett_smb_locks);
while(ln--){
proto_item *litem_2 = NULL;
proto_tree *ltree_2 = NULL;
if(lt&0x10){
guint64 val;
guint16 lock_pid;
guint64 lock_offset;
guint64 lock_length;
litem_2 = proto_tree_add_text(tr, tvb, offset, 20,
"Lock");
ltree_2 = proto_item_add_subtree(litem_2, ett_smb_lock);
CHECK_BYTE_COUNT(2);
lock_pid=tvb_get_letohs(tvb, offset);
proto_tree_add_item(ltree_2, hf_smb_pid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(ltree_2, hf_smb_reserved, tvb, offset, 2, ENC_NA);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(8);
val=((guint64)tvb_get_letohl(tvb, offset)) << 32
| tvb_get_letohl(tvb, offset+4);
lock_offset=val;
proto_tree_add_uint64(ltree_2, hf_smb_lock_long_offset, tvb, offset, 8, val);
COUNT_BYTES(8);
CHECK_BYTE_COUNT(8);
val=((guint64)tvb_get_letohl(tvb, offset)) << 32
| tvb_get_letohl(tvb, offset+4);
lock_length=val;
proto_tree_add_uint64(ltree_2, hf_smb_lock_long_length, tvb, offset, 8, val);
COUNT_BYTES(8);
if(ld){
smb_lock_info_t *li;
li=se_alloc(sizeof(smb_lock_info_t));
li->next=ld->locks;
ld->locks=li;
li->pid=lock_pid;
li->offset=lock_offset;
li->length=lock_length;
}
} else {
litem_2 = proto_tree_add_text(tr, tvb, offset, 10,
"Lock");
ltree_2 = proto_item_add_subtree(litem_2, ett_smb_lock);
CHECK_BYTE_COUNT(2);
proto_tree_add_item(ltree_2, hf_smb_pid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(4);
proto_tree_add_item(ltree_2, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
CHECK_BYTE_COUNT(4);
proto_tree_add_item(ltree_2, hf_smb_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
}
}
proto_item_set_len(it, offset-old_offset);
it = NULL;
}
END_OF_SMB
if (it != NULL) {
proto_item_set_len(it, offset-old_offset);
}
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_locking_andx_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0;
guint16 bc;
smb_info_t *si;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_LOCKDATA) {
smb_locking_saved_info_t *ld;
proto_item *litem = NULL;
proto_tree *ltree = NULL;
ld = si->sip->extra_info;
if (ld != NULL) {
proto_item *lit;
proto_tree *ltr;
smb_lock_info_t *li;
if(tree){
litem = proto_tree_add_text(tree, tvb, 0, 0,
"Lock Type: 0x%02x", ld->type);
PROTO_ITEM_SET_GENERATED(litem);
ltree = proto_item_add_subtree(litem, ett_smb_lock_type);
proto_tree_add_boolean(ltree, hf_smb_lock_type_large, tvb, 0, 0, ld->type);
proto_tree_add_boolean(ltree, hf_smb_lock_type_cancel, tvb, 0, 0, ld->type);
proto_tree_add_boolean(ltree, hf_smb_lock_type_change, tvb, 0, 0, ld->type);
proto_tree_add_boolean(ltree, hf_smb_lock_type_oplock, tvb, 0, 0, ld->type);
proto_tree_add_boolean(ltree, hf_smb_lock_type_shared, tvb, 0, 0, ld->type);
proto_tree_add_uint(ltree, hf_smb_locking_ol, tvb, 0, 0, ld->oplock_level);
proto_tree_add_uint(ltree, hf_smb_number_of_unlocks, tvb, 0, 0, ld->num_unlock);
proto_tree_add_uint(ltree, hf_smb_number_of_locks, tvb, 0, 0, ld->num_lock);
lit = proto_tree_add_text(ltree, tvb, 0, 0, "Locks");
ltr = proto_item_add_subtree(lit, ett_smb_lock);
li=ld->locks;
while(li){
proto_tree_add_uint(ltr, hf_smb_pid, tvb, 0, 0, li->pid);
proto_tree_add_uint64(ltr, hf_smb_lock_long_offset, tvb, 0, 0, li->offset);
proto_tree_add_uint64(ltr, hf_smb_lock_long_length, tvb, 0, 0, li->length);
li=li->next;
}
lit = proto_tree_add_text(ltree, tvb, 0, 0, "Unlocks");
ltr = proto_item_add_subtree(lit, ett_smb_unlock);
li=ld->unlocks;
while(li){
proto_tree_add_uint(ltr, hf_smb_pid, tvb, 0, 0, li->pid);
proto_tree_add_uint64(ltr, hf_smb_lock_long_offset, tvb, 0, 0, li->offset);
proto_tree_add_uint64(ltr, hf_smb_lock_long_length, tvb, 0, 0, li->length);
li=li->next;
}
}
}
}
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
BYTE_COUNT;
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_open_action(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Action: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_open_action);
proto_tree_add_boolean(tree, hf_smb_open_action_lock,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_open_action_open,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_open_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset, int bm)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_open_flags);
if(bm&0x0001){
proto_tree_add_boolean(tree, hf_smb_open_flags_add_info,
tvb, offset, 2, mask);
}
if(bm&0x0002){
proto_tree_add_boolean(tree, hf_smb_open_flags_ex_oplock,
tvb, offset, 2, mask);
}
if(bm&0x0004){
proto_tree_add_boolean(tree, hf_smb_open_flags_batch_oplock,
tvb, offset, 2, mask);
}
if(bm&0x0008){
proto_tree_add_boolean(tree, hf_smb_open_flags_ealen,
tvb, offset, 2, mask);
}
}
offset += 2;
return offset;
}
static int
dissect_open_andx_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc;
guint32 to;
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
offset = dissect_open_flags(tvb, tree, offset, 0x0007);
offset = dissect_access(tvb, tree, offset, "Desired");
offset = dissect_search_attributes(tvb, tree, offset);
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_create_time);
offset = dissect_open_function(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
to = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_smb_timeout, tvb, offset, 4, to, "Timeout: %s", smbext20_timeout_msecs_to_str(to));
offset += 4;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
BYTE_COUNT;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if((!pinfo->fd->flags.visited) && si->sip && fn){
smb_fid_saved_info_t *fsi;
fsi=se_alloc(sizeof(smb_fid_saved_info_t));
fsi->filename=se_strdup(fn);
si->sip->extra_info_type=SMB_EI_FILEDATA;
si->sip->extra_info=fsi;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
int
dissect_ipc_state(tvbuff_t *tvb, proto_tree *parent_tree, int offset,
gboolean setstate_flag)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"IPC State: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_ipc_state);
proto_tree_add_boolean(tree, hf_smb_ipc_state_nonblocking,
tvb, offset, 2, mask);
if (!setstate_flag) {
proto_tree_add_uint(tree, hf_smb_ipc_state_endpoint,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_ipc_state_pipe_type,
tvb, offset, 2, mask);
}
proto_tree_add_uint(tree, hf_smb_ipc_state_read_mode,
tvb, offset, 2, mask);
if (!setstate_flag) {
proto_tree_add_uint(tree, hf_smb_ipc_state_icount,
tvb, offset, 2, mask);
}
}
offset += 2;
return offset;
}
static int
dissect_open_andx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc;
guint16 fid;
guint16 ftype;
guint16 fattr;
smb_fid_info_t *fid_info=NULL;
gboolean isdir=FALSE;
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
fid = tvb_get_letohs(tvb, offset);
fid_info=dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
fattr = tvb_get_letohs(tvb, offset);
isdir = fattr & SMB_FILE_ATTRIBUTE_DIRECTORY;
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_UTIME(tvb, tree, offset, hf_smb_last_write_time);
if (fid_info) {
fid_info->end_of_file=(guint64) tvb_get_letohl(tvb, offset);
}
proto_tree_add_item(tree, hf_smb_file_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_access(tvb, tree, offset, "Granted");
ftype=tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb_file_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (fid_info) {
fid_info->type=SMB_FID_TYPE_UNKNOWN;
}
if(ftype==0){
if(isdir==0){
if(fid_info){
fid_info->type=SMB_FID_TYPE_FILE;
}
} else {
if(fid_info){
fid_info->type=SMB_FID_TYPE_DIR;
}
}
}
if(ftype==2 || ftype==1){
if(fid_info){
fid_info->type=SMB_FID_TYPE_PIPE;
}
}
offset = dissect_ipc_state(tvb, tree, offset, FALSE);
offset = dissect_open_action(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb_server_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
BYTE_COUNT;
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_read_andx_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc, maxcnt_low;
guint32 maxcnt_high;
guint32 maxcnt=0;
guint32 offsetlow, offsethigh=0;
guint64 ofs;
smb_info_t *si= (smb_info_t *)pinfo->private_data;
unsigned int fid;
rw_info_t *rwi=NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, (guint16) fid, FALSE, FALSE, FALSE);
offset += 2;
offsetlow = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
maxcnt_low = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_max_count_low, tvb, offset, 2, maxcnt_low);
offset += 2;
proto_tree_add_item(tree, hf_smb_min_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
maxcnt_high = tvb_get_letohl(tvb, offset);
if(maxcnt_high==0xffffffff){
maxcnt_high=0;
} else {
proto_tree_add_uint(tree, hf_smb_max_count_high, tvb, offset, 4, maxcnt_high);
}
offset += 4;
maxcnt=maxcnt_high;
maxcnt=(maxcnt<<16)|maxcnt_low;
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(wc==12){
offsethigh=tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_high_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
ofs=offsethigh;
ofs=(ofs<<32)|offsetlow;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s at offset %" G_GINT64_MODIFIER "u",
maxcnt, (maxcnt == 1) ? "" : "s", ofs);
if(si->sip && !pinfo->fd->flags.visited){
rwi=se_alloc(sizeof(rw_info_t));
rwi->offset=ofs;
rwi->len=maxcnt;
rwi->fid=fid;
si->sip->extra_info_type=SMB_EI_RWINFO;
si->sip->extra_info=rwi;
}
if(si->sip && si->sip->extra_info_type==SMB_EI_RWINFO){
rwi=si->sip->extra_info;
}
if(rwi){
proto_item *it;
it=proto_tree_add_uint64(tree, hf_smb_file_rw_offset, tvb, 0, 0, rwi->offset);
PROTO_ITEM_SET_GENERATED(it);
it=proto_tree_add_uint(tree, hf_smb_file_rw_length, tvb, 0, 0, rwi->len);
PROTO_ITEM_SET_GENERATED(it);
}
BYTE_COUNT;
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_read_andx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc, datalen_low, dataoffset=0;
guint32 datalen=0, datalen_high;
smb_info_t *si = (smb_info_t *)pinfo->private_data;
rw_info_t *rwi=NULL;
guint16 fid=0;
smb_eo_t *eo_info;
smb_tid_info_t *tid_info=NULL;
smb_fid_info_t *fid_info=NULL;
smb_fid_info_t *suspect_fid_info=NULL;
guint32 tvblen;
tvbuff_t *data_tvb;
GSList *GSL_iterator;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
if(si->sip != NULL && si->sip->frame_req>0 && si->sip->extra_info_type==SMB_EI_FID){
fid=GPOINTER_TO_INT(si->sip->extra_info);
dissect_smb_fid(tvb, pinfo, tree, 0, 0, (guint16) fid, FALSE, FALSE, FALSE);
}
if(si->sip && si->sip->extra_info_type==SMB_EI_RWINFO){
rwi=si->sip->extra_info;
}
if(rwi){
proto_item *it;
it=proto_tree_add_uint64(tree, hf_smb_file_rw_offset, tvb, 0, 0, rwi->offset);
PROTO_ITEM_SET_GENERATED(it);
it=proto_tree_add_uint(tree, hf_smb_file_rw_length, tvb, 0, 0, rwi->len);
PROTO_ITEM_SET_GENERATED(it);
fid=rwi->fid;
}
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_dcm, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
datalen_low = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len_low, tvb, offset, 2, datalen_low);
offset += 2;
dataoffset=tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset, tvb, offset, 2, dataoffset);
offset += 2;
datalen_high = tvb_get_letohl(tvb, offset);
if(datalen_high==0xffffffff){
datalen_high=0;
} else {
proto_tree_add_uint(tree, hf_smb_data_len_high, tvb, offset, 4, datalen_high);
}
offset += 4;
datalen=datalen_high;
datalen=(datalen<<16)|datalen_low;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s", datalen,
(datalen == 1) ? "" : "s");
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 6, ENC_NA);
offset += 6;
BYTE_COUNT;
if(bc){
offset = dissect_file_data_maybe_dcerpc(tvb, pinfo, tree,
top_tree_global, offset, bc, (guint16) datalen, 0, (guint16) fid);
bc = 0;
}
tvblen = tvb_length_remaining(tvb, dataoffset);
if(have_tap_listener(smb_eo_tap) && datalen==tvblen && rwi) {
data_tvb = tvb_new_subset(tvb, dataoffset, datalen, tvblen);
eo_info = ep_alloc(sizeof(smb_eo_t));
if (fid_info==NULL) {
GSL_iterator = si->ct->GSL_fid_info;
while (GSL_iterator) {
suspect_fid_info=GSL_iterator->data;
if(suspect_fid_info->opened_in > pinfo->fd->num) break;
if(suspect_fid_info->tid==si->tid && suspect_fid_info->fid==fid)
fid_info=suspect_fid_info;
GSL_iterator=g_slist_next(GSL_iterator);
}
}
tid_info = se_tree_lookup32(si->ct->tid_tree, si->tid);
if (tid_info) eo_info->hostname = tid_info->filename;
else eo_info->hostname = ep_strdup_printf("\\\\TREEID_%i",si->tid);
if (fid_info) {
eo_info->filename=NULL;
if (fid_info->fsi)
if (fid_info->fsi->filename)
eo_info->filename = (gchar *) fid_info->fsi->filename;
if(!eo_info->filename) eo_info->filename = ep_strdup_printf("\\FILEID_%i",fid);
eo_info->fid_type = fid_info->type;
eo_info->end_of_file = fid_info->end_of_file;
} else {
eo_info->fid_type=SMB_FID_TYPE_UNKNOWN;
eo_info->filename = ep_strdup_printf("\\FILEID_%i",fid);
eo_info->end_of_file = 0;
}
eo_info->fid=fid;
eo_info->tid=si->tid;
eo_info->uid=si->uid;
eo_info->payload_len = datalen;
eo_info->payload_data = tvb_get_ptr(data_tvb, 0, datalen);
eo_info->smb_file_offset=rwi->offset;
eo_info->smb_chunk_len=rwi->len;
eo_info->cmd=SMB_COM_READ_ANDX;
tap_queue_packet(smb_eo_tap, pinfo, eo_info);
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_write_andx_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc, dataoffset=0, datalen_low, datalen_high;
guint32 offsetlow, offsethigh=0;
guint64 ofs;
guint32 datalen=0;
smb_info_t *si = (smb_info_t *)pinfo->private_data;
guint16 fid=0;
guint16 mode = 0;
rw_info_t *rwi=NULL;
smb_eo_t *eo_info;
smb_tid_info_t *tid_info=NULL;
smb_fid_info_t *fid_info=NULL;
smb_fid_info_t *suspect_fid_info=NULL;
guint32 tvblen;
tvbuff_t *data_tvb;
GSList *GSL_iterator;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, (guint16) fid, FALSE, FALSE, FALSE);
offset += 2;
offsetlow = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
mode = tvb_get_letohs(tvb, offset);
offset = dissect_write_mode(tvb, tree, offset, 0x000f);
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
datalen_high = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len_high, tvb, offset, 2, datalen_high);
offset += 2;
datalen_low = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len_low, tvb, offset, 2, datalen_low);
offset += 2;
datalen=datalen_high;
datalen=(datalen<<16)|datalen_low;
dataoffset=tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset, tvb, offset, 2, dataoffset);
offset += 2;
if(wc==14){
offsethigh=tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_high_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
ofs=offsethigh;
ofs=(ofs<<32)|offsetlow;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s at offset %" G_GINT64_MODIFIER "u",
datalen, (datalen == 1) ? "" : "s", ofs);
if(si->sip && !pinfo->fd->flags.visited){
rwi=se_alloc(sizeof(rw_info_t));
rwi->offset=ofs;
rwi->len=datalen;
rwi->fid=fid;
si->sip->extra_info_type=SMB_EI_RWINFO;
si->sip->extra_info=rwi;
}
if(si->sip && si->sip->extra_info_type==SMB_EI_RWINFO){
rwi=si->sip->extra_info;
}
if(rwi){
proto_item *it;
it=proto_tree_add_uint64(tree, hf_smb_file_rw_offset, tvb, 0, 0, rwi->offset);
PROTO_ITEM_SET_GENERATED(it);
it=proto_tree_add_uint(tree, hf_smb_file_rw_length, tvb, 0, 0, rwi->len);
PROTO_ITEM_SET_GENERATED(it);
}
BYTE_COUNT;
if(mode&WRITE_MODE_MESSAGE_START){
if(mode&WRITE_MODE_RAW){
proto_tree_add_item(tree, hf_smb_pipe_write_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
dataoffset += 2;
bc -= 2;
datalen -= 2;
}
if(!pinfo->fd->flags.visited){
if(g_hash_table_lookup(si->ct->tid_service, GUINT_TO_POINTER(si->tid))){
g_hash_table_remove(si->ct->tid_service, GUINT_TO_POINTER(si->tid));
}
g_hash_table_insert(si->ct->tid_service, GUINT_TO_POINTER(si->tid), (void *)TID_IPC);
}
if(si->sip){
si->sip->flags|=SMB_SIF_TID_IS_IPC;
}
}
if (bc != 0) {
offset = dissect_file_data_maybe_dcerpc(tvb, pinfo, tree,
top_tree_global, offset, bc, (guint16) datalen, 0, (guint16) fid);
bc = 0;
}
tvblen = tvb_length_remaining(tvb, dataoffset);
if(have_tap_listener(smb_eo_tap) && datalen==tvblen && rwi) {
data_tvb = tvb_new_subset(tvb, dataoffset, datalen, tvblen);
eo_info = ep_alloc(sizeof(smb_eo_t));
if (fid_info==NULL) {
GSL_iterator = si->ct->GSL_fid_info;
while (GSL_iterator) {
suspect_fid_info=GSL_iterator->data;
if(suspect_fid_info->opened_in > pinfo->fd->num)
break;
if(suspect_fid_info->tid==si->tid && suspect_fid_info->fid==fid)
fid_info=suspect_fid_info;
GSL_iterator=g_slist_next(GSL_iterator);
}
}
tid_info = se_tree_lookup32(si->ct->tid_tree, si->tid);
if (tid_info) eo_info->hostname = tid_info->filename;
else eo_info->hostname = ep_strdup_printf("\\\\TREEID_%i",si->tid);
if (fid_info) {
eo_info->filename=NULL;
if (fid_info->fsi) {
if (fid_info->fsi->filename) {
eo_info->filename = (gchar *) fid_info->fsi->filename;
}
}
if(!eo_info->filename) eo_info->filename = ep_strdup_printf("\\FILEID_%i",fid);
eo_info->fid_type = fid_info->type;
eo_info->end_of_file = fid_info->end_of_file;
} else {
eo_info->fid_type=SMB_FID_TYPE_UNKNOWN;
eo_info->filename = ep_strdup_printf("\\FILEID_%i",fid);
eo_info->end_of_file = 0;
}
eo_info->fid=fid;
eo_info->tid=si->tid;
eo_info->uid=si->uid;
eo_info->payload_len = datalen;
eo_info->payload_data = tvb_get_ptr(data_tvb, 0, datalen);
eo_info->smb_file_offset=rwi->offset;
eo_info->smb_chunk_len=rwi->len;
eo_info->cmd=SMB_COM_WRITE_ANDX;
tap_queue_packet(smb_eo_tap, pinfo, eo_info);
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_write_andx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc, count_low, count_high;
guint32 count=0;
smb_info_t *si = (smb_info_t *)pinfo->private_data;
rw_info_t *rwi=NULL;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
if(si->sip && si->sip->extra_info_type==SMB_EI_RWINFO){
rwi=si->sip->extra_info;
}
if(rwi){
proto_item *it;
it=proto_tree_add_uint64(tree, hf_smb_file_rw_offset, tvb, 0, 0, rwi->offset);
PROTO_ITEM_SET_GENERATED(it);
it=proto_tree_add_uint(tree, hf_smb_file_rw_length, tvb, 0, 0, rwi->len);
PROTO_ITEM_SET_GENERATED(it);
}
count_low = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count_low, tvb, offset, 2, count_low);
offset += 2;
proto_tree_add_item(tree, hf_smb_remaining, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
count_high = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count_high, tvb, offset, 2, count_high);
offset += 2;
count=count_high;
count=(count<<16)|count_low;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
", %u byte%s", count,
(count == 1) ? "" : "s");
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
BYTE_COUNT;
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_setup_action(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Action: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_setup_action);
proto_tree_add_boolean(tree, hf_smb_setup_action_guest,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_session_setup_andx_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 bc;
guint16 andxoffset=0;
smb_info_t *si = pinfo->private_data;
int an_len;
const char *an;
int dn_len;
const char *dn;
guint16 pwlen=0;
guint16 sbloblen=0, sbloblen_short;
guint16 apwlen=0, upwlen=0;
gboolean unicodeflag;
static int ntlmssp_tap_id = 0;
const ntlmssp_header_t *ntlmssph;
if(!ntlmssp_tap_id){
GString *error_string;
error_string=register_tap_listener("ntlmssp", NULL, NULL,
TL_IS_DISSECTOR_HELPER, NULL, NULL, NULL);
if(!error_string){
ntlmssp_tap_id=find_tap_id("ntlmssp");
}
}
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
proto_tree_add_item(tree, hf_smb_max_buf_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_max_mpx_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_vc_num, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_session_key, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
switch (wc) {
case 10:
pwlen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_password_len,
tvb, offset, 2, pwlen);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
break;
case 12:
sbloblen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_security_blob_len, tvb, offset, 2, sbloblen);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
dissect_negprot_capabilities(tvb, tree, offset);
offset += 4;
break;
case 13:
apwlen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_ansi_password_len,
tvb, offset, 2, apwlen);
offset += 2;
upwlen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_unicode_password_len,
tvb, offset, 2, upwlen);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
dissect_negprot_capabilities(tvb, tree, offset);
offset += 4;
break;
}
BYTE_COUNT;
if (wc==12) {
proto_item *blob_item;
sbloblen_short = sbloblen;
if(sbloblen_short>tvb_length_remaining(tvb,offset)){
sbloblen_short=tvb_length_remaining(tvb,offset);
}
blob_item = proto_tree_add_item(tree, hf_smb_security_blob,
tvb, offset, sbloblen_short,
ENC_NA);
if(sbloblen){
tvbuff_t *blob_tvb;
proto_tree *blob_tree;
blob_tree = proto_item_add_subtree(blob_item,
ett_smb_secblob);
CHECK_BYTE_COUNT(sbloblen);
blob_tvb = tvb_new_subset(tvb, offset, sbloblen_short,
sbloblen);
if (si && si->ct && si->ct->raw_ntlmssp &&
tvb_strneql(tvb, offset, "NTLMSSP", 7) == 0) {
call_dissector(ntlmssp_handle, blob_tvb, pinfo,
blob_tree);
}
else {
call_dissector(gssapi_handle, blob_tvb,
pinfo, blob_tree);
}
if(!pinfo->fd->flags.visited && si->sip){
int idx=0;
if((ntlmssph=fetch_tapped_data(ntlmssp_tap_id, idx + 1 )) != NULL){
if(ntlmssph && ntlmssph->type==3){
smb_uid_t *smb_uid;
smb_uid=se_alloc(sizeof(smb_uid_t));
smb_uid->logged_in=-1;
smb_uid->logged_out=-1;
smb_uid->domain=se_strdup(ntlmssph->domain_name);
smb_uid->account=se_strdup(ntlmssph->acct_name);
si->sip->extra_info=smb_uid;
si->sip->extra_info_type=SMB_EI_UID;
}
}
}
COUNT_BYTES(sbloblen);
}
unicodeflag=si->unicode;
if( tvb_strneql(tvb, offset, "Win", 3) == 0 ){
unicodeflag=FALSE;
}
an = get_unicode_or_ascii_string(tvb, &offset,
unicodeflag, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_os, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
unicodeflag=si->unicode;
if( tvb_strneql(tvb, offset, "Win", 3) == 0 ){
unicodeflag=FALSE;
}
an = get_unicode_or_ascii_string(tvb, &offset,
unicodeflag, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_lanman, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
dn = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &dn_len, FALSE, FALSE, &bc);
if (dn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_primary_domain, tvb,
offset, dn_len, dn);
COUNT_BYTES(dn_len);
} else {
switch (wc) {
case 10:
if(pwlen){
CHECK_BYTE_COUNT(pwlen);
proto_tree_add_item(tree, hf_smb_password,
tvb, offset, pwlen, ENC_NA);
COUNT_BYTES(pwlen);
}
break;
case 13:
if(apwlen){
CHECK_BYTE_COUNT(apwlen);
proto_tree_add_item(tree, hf_smb_ansi_password,
tvb, offset, apwlen, ENC_NA);
COUNT_BYTES(apwlen);
}
if(upwlen){
proto_item *item;
CHECK_BYTE_COUNT(upwlen);
item = proto_tree_add_item(tree, hf_smb_unicode_password,
tvb, offset, upwlen, ENC_NA);
if (upwlen > 24) {
proto_tree *subtree;
subtree = proto_item_add_subtree(item, ett_smb_unicode_password);
dissect_ntlmv2_response(
tvb, subtree, offset, upwlen);
}
COUNT_BYTES(upwlen);
}
break;
}
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_account, tvb, offset, an_len,
an);
COUNT_BYTES(an_len);
dn = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &dn_len, FALSE, FALSE, &bc);
if (dn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_primary_domain, tvb,
offset, dn_len, dn);
COUNT_BYTES(dn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_str(pinfo->cinfo, COL_INFO, ", User: ");
if (!dn[0] && !an[0])
col_append_str(pinfo->cinfo, COL_INFO,
"anonymous");
else
col_append_fstr(pinfo->cinfo, COL_INFO,
"%s\\%s",
format_text(dn, strlen(dn)),
format_text(an, strlen(an)));
}
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_os, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_lanman, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
pinfo->private_data = si;
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_session_setup_andx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0, bc;
guint16 sbloblen=0;
smb_info_t *si = pinfo->private_data;
int an_len;
const char *an;
DISSECTOR_ASSERT(si);
WORD_COUNT;
if(!pinfo->fd->flags.visited && si->sip && si->sip->extra_info &&
si->sip->extra_info_type==SMB_EI_UID){
smb_uid_t *smb_uid;
smb_uid=si->sip->extra_info;
smb_uid->logged_in=pinfo->fd->num;
se_tree_insert32(si->ct->uid_tree, si->uid, smb_uid);
}
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
offset = dissect_setup_action(tvb, tree, offset);
if(wc==4){
sbloblen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_security_blob_len, tvb, offset, 2, sbloblen);
offset += 2;
}
BYTE_COUNT;
if(wc==4) {
proto_item *blob_item;
if(sbloblen>tvb_length_remaining(tvb,offset)){
sbloblen=tvb_length_remaining(tvb,offset);
}
blob_item = proto_tree_add_item(tree, hf_smb_security_blob,
tvb, offset, sbloblen, ENC_NA);
if(sbloblen){
tvbuff_t *blob_tvb;
proto_tree *blob_tree;
blob_tree = proto_item_add_subtree(blob_item,
ett_smb_secblob);
CHECK_BYTE_COUNT(sbloblen);
blob_tvb = tvb_new_subset(tvb, offset, sbloblen,
sbloblen);
if (si && si->ct && si->ct->raw_ntlmssp &&
tvb_strneql(tvb, offset, "NTLMSSP", 7) == 0) {
call_dissector(ntlmssp_handle, blob_tvb, pinfo,
blob_tree);
}
else {
call_dissector(gssapi_handle, blob_tvb, pinfo,
blob_tree);
}
COUNT_BYTES(sbloblen);
}
}
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_os, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_lanman, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
if((wc==3)||(wc==4)) {
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_primary_domain, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
pinfo->private_data = si;
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_empty_andx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0;
guint16 bc;
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
BYTE_COUNT;
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_connect_support_bits(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Optional Support: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_connect_support_bits);
proto_tree_add_boolean(tree, hf_smb_connect_support_search,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_connect_support_in_dfs,
tvb, offset, 2, mask);
proto_tree_add_uint(tree, hf_smb_connect_support_csc_mask_vals,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_connect_support_uniquefilename,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_connect_support_extended_signature,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_connect_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_connect_flags);
proto_tree_add_boolean(tree, hf_smb_connect_flags_dtid,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_connect_flags_ext_sig,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_connect_flags_ext_resp,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_tree_connect_andx_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 bc;
guint16 andxoffset=0, pwlen=0;
smb_info_t *si = pinfo->private_data;
int an_len;
const char *an;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
offset = dissect_connect_flags(tvb, tree, offset);
pwlen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_password_len, tvb, offset, 2, pwlen);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(pwlen);
proto_tree_add_item(tree, hf_smb_password,
tvb, offset, pwlen, ENC_NA);
COUNT_BYTES(pwlen);
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_path, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
if((!pinfo->fd->flags.visited) && si->sip && an){
si->sip->extra_info_type=SMB_EI_TIDNAME;
si->sip->extra_info=se_strdup(an);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(an, strlen(an)));
}
an_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(an_len);
an = tvb_get_ephemeral_string(tvb, offset, an_len);
proto_tree_add_string(tree, hf_smb_service, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_tree_connect_andx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, wleft, cmd=0xff;
guint16 andxoffset=0;
guint16 bc;
int an_len;
int count = 0;
proto_item *it = NULL;
proto_tree *tr = NULL;
const char *an;
smb_info_t *si = pinfo->private_data;
DISSECTOR_ASSERT(si);
WORD_COUNT;
wleft = wc;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
wleft--;
if (wleft == 0)
goto bytecount;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
wleft--;
if (wleft == 0)
goto bytecount;
offset = dissect_connect_support_bits(tvb, tree, offset);
wleft--;
while (wleft != 0) {
if (count == 0) {
it = proto_tree_add_text(tree, tvb, offset, 4,
"Maximal Share Access Rights");
} else {
it = proto_tree_add_text(tree, tvb, offset, 4,
"Guest Maximal Share Access Rights");
}
tr = proto_item_add_subtree(it, ett_smb_nt_access_mask);
offset = dissect_smb_access_mask(tvb, tr, offset);
wleft -= 2;
count++;
}
BYTE_COUNT;
an_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(an_len);
an = tvb_get_ephemeral_string(tvb, offset, an_len);
proto_tree_add_string(tree, hf_smb_service, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
if(!pinfo->fd->flags.visited){
if(g_hash_table_lookup(si->ct->tid_service, GUINT_TO_POINTER(si->tid))){
g_hash_table_remove(si->ct->tid_service, GUINT_TO_POINTER(si->tid));
}
if(strcmp(an,"IPC") == 0){
g_hash_table_insert(si->ct->tid_service, GUINT_TO_POINTER(si->tid), (void *)TID_IPC);
} else {
g_hash_table_insert(si->ct->tid_service, GUINT_TO_POINTER(si->tid), (void *)TID_NORMAL);
}
}
if(wc==3){
if (bc != 0) {
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE,
&bc);
if (an == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_fs, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
}
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_nt_security_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint8 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_guint8(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"Security Flags: 0x%02x", mask);
tree = proto_item_add_subtree(item, ett_smb_nt_security_flags);
proto_tree_add_boolean(tree, hf_smb_nt_security_flags_context_tracking,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_nt_security_flags_effective_only,
tvb, offset, 1, mask);
}
offset += 1;
return offset;
}
int
dissect_nt_notify_completion_filter(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Completion Filter: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_smb_nt_notify_completion_filter);
proto_tree_add_boolean(tree, hf_smb_nt_notify_stream_write,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_stream_size,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_stream_name,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_security,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_ea,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_creation,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_last_access,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_last_write,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_size,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_attributes,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_dir_name,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_notify_file_name,
tvb, offset, 4, mask);
}
offset += 4;
return offset;
}
static int
dissect_nt_ioctl_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint8 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_guint8(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"Completion Filter: 0x%02x", mask);
tree = proto_item_add_subtree(item, ett_smb_nt_ioctl_flags);
proto_tree_add_boolean(tree, hf_smb_nt_ioctl_flags_root_handle,
tvb, offset, 1, mask);
}
offset += 1;
return offset;
}
int
dissect_security_information_mask(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Security Information: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_smb_security_information_mask);
proto_tree_add_boolean(tree, hf_smb_nt_qsd_owner,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_qsd_group,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_qsd_dacl,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_nt_qsd_sacl,
tvb, offset, 4, mask);
}
offset += 4;
return offset;
}
static int
dissect_nt_user_quota(tvbuff_t *tvb, proto_tree *tree, int offset, guint16 *bcp)
{
int old_offset, old_sid_offset;
guint32 qsize;
do {
old_offset=offset;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
qsize=tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_user_quota_offset, tvb, offset, 4, qsize);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_text(tree, tvb, offset, 4, "Length of SID: %d", tvb_get_letohl(tvb, offset));
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_unknown, tvb,
offset, 8, ENC_NA);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_user_quota_used, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_soft_quota_limit, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_hard_quota_limit, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
old_sid_offset=offset;
offset = dissect_nt_sid(tvb, offset, tree, "Quota", NULL, -1);
*bcp -= (offset-old_sid_offset);
if(qsize){
offset = old_offset+qsize;
}
}while(qsize);
return offset;
}
static int
dissect_nt_trans_data_request(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *parent_tree, int bc, nt_trans_data *ntd, smb_nt_transact_info_t *nti)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
int old_offset = offset;
guint16 bcp=bc;
struct access_mask_info *ami=NULL;
tvbuff_t *ioctl_tvb;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, bc);
item = proto_tree_add_text(parent_tree, tvb, offset, bc,
"%s Data",
val_to_str_ext(ntd->subcmd, &nt_cmd_vals_ext, "Unknown NT transaction (%u)"));
tree = proto_item_add_subtree(item, ett_smb_nt_trans_data);
}
switch(ntd->subcmd){
case NT_TRANS_CREATE:
if(ntd->sd_len){
offset = dissect_nt_sec_desc(
tvb, offset, pinfo, tree, NULL, TRUE,
ntd->sd_len, NULL);
}
if(ntd->ea_len){
proto_tree_add_item(tree, hf_smb_extended_attributes, tvb, offset, ntd->ea_len, ENC_NA);
offset += ntd->ea_len;
}
break;
case NT_TRANS_IOCTL:
ioctl_tvb=tvb_new_subset(tvb, offset, MIN((int)bc, tvb_length_remaining(tvb, offset)), bc);
if (nti){
dissect_smb2_ioctl_data(ioctl_tvb, pinfo, tree, top_tree_global, nti->ioctl_function, TRUE);
}
offset += bc;
break;
case NT_TRANS_SSD:
if(nti){
switch(nti->fid_type){
case SMB_FID_TYPE_FILE:
ami= &smb_file_access_mask_info;
break;
case SMB_FID_TYPE_DIR:
ami= &smb_dir_access_mask_info;
break;
}
}
offset = dissect_nt_sec_desc(
tvb, offset, pinfo, tree, NULL, TRUE, bc, ami);
break;
case NT_TRANS_NOTIFY:
break;
case NT_TRANS_RENAME:
break;
case NT_TRANS_QSD:
break;
case NT_TRANS_GET_USER_QUOTA:
proto_tree_add_item(tree, hf_smb_unknown, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_text(tree, tvb, offset, 4, "Length of SID: %d", tvb_get_letohl(tvb, offset));
offset +=4;
offset = dissect_nt_sid(tvb, offset, tree, "Quota", NULL, -1);
break;
case NT_TRANS_SET_USER_QUOTA:
offset = dissect_nt_user_quota(tvb, tree, offset, &bcp);
break;
}
if((offset-old_offset) < bc){
proto_tree_add_item(tree, hf_smb_unknown, tvb, offset,
bc - (offset-old_offset), ENC_NA);
offset += bc - (offset-old_offset);
}
return offset;
}
static int
dissect_nt_trans_param_request(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *parent_tree, int len, nt_trans_data *ntd, guint16 bc, smb_nt_transact_info_t *nti)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 fn_len, create_flags, access_mask, share_access, create_options;
const char *fn;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"%s Parameters",
val_to_str_ext(ntd->subcmd, &nt_cmd_vals_ext, "Unknown NT transaction (%u)"));
tree = proto_item_add_subtree(item, ett_smb_nt_trans_param);
}
switch(ntd->subcmd){
case NT_TRANS_CREATE:
create_flags=tvb_get_letohl(tvb, offset);
offset = dissect_nt_create_bits(tvb, tree, offset, 4, create_flags);
bc -= 4;
proto_tree_add_item(tree, hf_smb_root_dir_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
access_mask=tvb_get_letohl(tvb, offset);
offset = dissect_smb_access_mask_bits(tvb, tree, offset, 4, access_mask);
bc -= 4;
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES(8);
offset = dissect_file_ext_attr(tvb, tree, offset);
bc -= 4;
share_access=tvb_get_letohl(tvb, offset);
offset = dissect_nt_share_access_bits(tvb, tree, offset, 4, share_access);
bc -= 4;
proto_tree_add_item(tree, hf_smb_nt_create_disposition, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
create_options=tvb_get_letohl(tvb, offset);
offset = dissect_nt_create_options_bits(tvb, tree, offset, 4, create_options);
bc -= 4;
ntd->sd_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_sd_length, tvb, offset, 4, ntd->sd_len);
COUNT_BYTES(4);
ntd->ea_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_ea_list_length, tvb, offset, 4, ntd->ea_len);
COUNT_BYTES(4);
fn_len = (guint32)tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES(4);
proto_tree_add_item(tree, hf_smb_nt_impersonation_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
offset = dissect_nt_security_flags(tvb, tree, offset);
bc -= 1;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, TRUE, TRUE, &bc);
if (fn != NULL) {
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
}
break;
case NT_TRANS_IOCTL:
break;
case NT_TRANS_SSD: {
guint16 fid;
smb_fid_info_t *fid_info;
fid = tvb_get_letohs(tvb, offset);
fid_info=dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
if(nti){
if(fid_info){
nti->fid_type=fid_info->type;
} else {
nti->fid_type=SMB_FID_TYPE_UNKNOWN;
}
}
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_security_information_mask(tvb, tree, offset);
break;
}
case NT_TRANS_NOTIFY:
break;
case NT_TRANS_RENAME:
break;
case NT_TRANS_QSD: {
guint16 fid;
smb_fid_info_t *fid_info;
fid = tvb_get_letohs(tvb, offset);
fid_info=dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
if(nti){
if(fid_info){
nti->fid_type=fid_info->type;
} else {
nti->fid_type=SMB_FID_TYPE_UNKNOWN;
}
}
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_security_information_mask(tvb, tree, offset);
break;
}
case NT_TRANS_GET_USER_QUOTA:
break;
case NT_TRANS_SET_USER_QUOTA:
break;
}
return offset;
}
static int
dissect_nt_trans_setup_request(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *parent_tree, int len, nt_trans_data *ntd)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_nt_transact_info_t *nti = NULL;
smb_saved_info_t *sip;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
sip = si->sip;
if (sip && sip->extra_info_type == SMB_EI_NTI) {
nti=sip->extra_info;
}
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, len);
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"%s Setup",
val_to_str_ext(ntd->subcmd, &nt_cmd_vals_ext, "Unknown NT transaction (%u)"));
tree = proto_item_add_subtree(item, ett_smb_nt_trans_setup);
}
switch(ntd->subcmd){
case NT_TRANS_CREATE:
offset += len;
break;
case NT_TRANS_IOCTL: {
guint16 fid;
offset = dissect_smb2_ioctl_function(tvb, pinfo, tree, offset, nti ? &nti->ioctl_function : NULL);
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_nt_ioctl_isfsctl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_nt_ioctl_flags(tvb, tree, offset);
break;
}
case NT_TRANS_SSD:
offset += len;
break;
case NT_TRANS_NOTIFY: {
guint16 fid;
offset = dissect_nt_notify_completion_filter(tvb, tree, offset);
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_nt_notify_watch_tree, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
case NT_TRANS_RENAME:
offset += len;
break;
case NT_TRANS_QSD:
break;
case NT_TRANS_GET_USER_QUOTA:
offset += len;
break;
case NT_TRANS_SET_USER_QUOTA:
offset += len;
break;
}
return offset;
}
static int
dissect_nt_transaction_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc, sc;
guint32 pc=0, po=0, dc=0, od=0;
smb_info_t *si;
smb_saved_info_t *sip;
int subcmd;
nt_trans_data ntd;
guint16 bc;
guint32 padcnt;
smb_nt_transact_info_t *nti=NULL;
ntd.subcmd = ntd.sd_len = ntd.ea_len = 0;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
sip = si->sip;
WORD_COUNT;
if(wc>=19){
proto_tree_add_item(tree, hf_smb_max_setup_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
} else {
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 3, ENC_NA);
offset += 3;
}
proto_tree_add_item(tree, hf_smb_total_param_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_total_data_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if(wc>=19){
proto_tree_add_item(tree, hf_smb_max_param_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_max_data_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
pc = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_count32, tvb, offset, 4, pc);
offset += 4;
po = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_offset32, tvb, offset, 4, po);
offset += 4;
if(wc>=19){
} else {
proto_tree_add_item(tree, hf_smb_param_disp32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
dc = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_count32, tvb, offset, 4, dc);
offset += 4;
od = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset32, tvb, offset, 4, od);
offset += 4;
if(wc>=19){
} else {
proto_tree_add_item(tree, hf_smb_data_disp32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
if(wc>=19){
sc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_setup_count, tvb, offset, 1, sc);
offset += 1;
} else {
sc = 0;
}
if(wc>=19){
subcmd = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_nt_trans_subcmd, tvb, offset, 2, subcmd);
if(check_col(pinfo->cinfo, COL_INFO)){
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(subcmd, &nt_cmd_vals_ext, "<unknown>"));
}
ntd.subcmd = subcmd;
if (!si->unidir && sip) {
if(!pinfo->fd->flags.visited){
nti = se_alloc(sizeof(smb_nt_transact_info_t));
nti->subcmd = subcmd;
nti->fid_type=SMB_FID_TYPE_UNKNOWN;
sip->extra_info = nti;
sip->extra_info_type = SMB_EI_NTI;
} else {
if(sip->extra_info_type == SMB_EI_NTI){
nti=sip->extra_info;
}
}
}
} else {
col_append_str(pinfo->cinfo, COL_INFO, " (secondary request)");
}
offset += 2;
if(offset%1){
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, 1, ENC_NA);
offset += 1;
}
if(sc){
dissect_nt_trans_setup_request(tvb, pinfo, offset, tree, sc*2, &ntd);
offset += sc*2;
}
BYTE_COUNT;
if(po>(guint32)offset){
padcnt = po-offset;
if (padcnt > bc)
padcnt = bc;
CHECK_BYTE_COUNT(padcnt);
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(pc){
CHECK_BYTE_COUNT(pc);
dissect_nt_trans_param_request(tvb, pinfo, offset, tree, pc, &ntd, bc, nti);
COUNT_BYTES(pc);
}
if(od>(guint32)offset){
padcnt = od-offset;
if (padcnt > bc)
padcnt = bc;
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(dc){
CHECK_BYTE_COUNT(dc);
dissect_nt_trans_data_request(
tvb, pinfo, offset, tree, dc, &ntd, nti);
COUNT_BYTES(dc);
}
END_OF_SMB
return offset;
}
static int
dissect_nt_trans_data_response(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *parent_tree, int len,
nt_trans_data *ntd _U_,
smb_nt_transact_info_t *nti)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint16 bcp;
struct access_mask_info *ami=NULL;
tvbuff_t *ioctl_tvb;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, len);
if(nti != NULL){
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"%s Data",
val_to_str_ext(nti->subcmd, &nt_cmd_vals_ext, "Unknown NT Transaction (%u)"));
} else {
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"Unknown NT Transaction Data (matching request not seen)");
}
tree = proto_item_add_subtree(item, ett_smb_nt_trans_data);
}
if (nti == NULL) {
offset += len;
return offset;
}
switch(nti->subcmd){
case NT_TRANS_CREATE:
break;
case NT_TRANS_IOCTL:
ioctl_tvb=tvb_new_subset(tvb, offset, MIN((int)len, tvb_length_remaining(tvb, offset)), len);
dissect_smb2_ioctl_data(ioctl_tvb, pinfo, tree, top_tree_global, nti->ioctl_function, FALSE);
offset += len;
break;
case NT_TRANS_SSD:
break;
case NT_TRANS_NOTIFY:
break;
case NT_TRANS_RENAME:
break;
case NT_TRANS_QSD:
if(nti){
switch(nti->fid_type){
case SMB_FID_TYPE_FILE:
ami= &smb_file_access_mask_info;
break;
case SMB_FID_TYPE_DIR:
ami= &smb_dir_access_mask_info;
break;
}
}
offset = dissect_nt_sec_desc(
tvb, offset, pinfo, tree, NULL, TRUE, len, ami);
break;
case NT_TRANS_GET_USER_QUOTA:
bcp=len;
offset = dissect_nt_user_quota(tvb, tree, offset, &bcp);
break;
case NT_TRANS_SET_USER_QUOTA:
break;
}
return offset;
}
static int
dissect_nt_trans_param_response(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *parent_tree,
int len, nt_trans_data *ntd _U_, guint16 bc)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 fn_len;
const char *fn;
smb_info_t *si;
smb_nt_transact_info_t *nti;
guint16 fid;
int old_offset;
guint32 neo;
int padcnt;
smb_fid_info_t *fid_info=NULL;
guint16 ftype;
guint8 isdir;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_NTI)
nti = si->sip->extra_info;
else
nti = NULL;
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, len);
if(nti != NULL){
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"%s Parameters",
val_to_str_ext(nti->subcmd, &nt_cmd_vals_ext, "Unknown NT Transaction (%u)"));
} else {
item = proto_tree_add_text(parent_tree, tvb, offset, len,
"Unknown NT Transaction Parameters (matching request not seen)");
}
tree = proto_item_add_subtree(item, ett_smb_nt_trans_param);
}
if (nti == NULL) {
offset += len;
return offset;
}
switch(nti->subcmd){
case NT_TRANS_CREATE:
proto_tree_add_item(tree, hf_smb_oplock_level, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
fid = tvb_get_letohs(tvb, offset);
fid_info=dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_create_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_smb_ea_error_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_create_time);
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_access_time);
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_last_write_time);
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_change_time);
offset = dissect_file_ext_attr(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
ftype=tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb_file_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_ipc_state(tvb, tree, offset, FALSE);
isdir=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_smb_is_directory, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if(ftype==0){
if(isdir==0){
if(fid_info){
fid_info->type=SMB_FID_TYPE_FILE;
}
} else {
if(fid_info){
fid_info->type=SMB_FID_TYPE_DIR;
}
}
}
if(ftype==2){
if(fid_info){
fid_info->type=SMB_FID_TYPE_PIPE;
}
}
break;
case NT_TRANS_IOCTL:
break;
case NT_TRANS_SSD:
break;
case NT_TRANS_NOTIFY:
while(len){
old_offset = offset;
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES(4);
len -= 4;
if(len<0)break;
proto_tree_add_item(tree, hf_smb_nt_notify_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES(4);
len -= 4;
if(len<0)break;
fn_len = (guint32)tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES(4);
len -= 4;
if(len<0)break;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, TRUE, TRUE, &bc);
if (fn == NULL)
break;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
len -= fn_len;
if(len<0)break;
if (neo == 0)
break;
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
COUNT_BYTES(padcnt);
len -= padcnt;
if(len<0)break;
}
}
break;
case NT_TRANS_RENAME:
break;
case NT_TRANS_QSD:
proto_tree_add_item(tree, hf_smb_sec_desc_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case NT_TRANS_GET_USER_QUOTA:
proto_tree_add_text(tree, tvb, offset, 4, "Size of returned Quota data: %d",
tvb_get_letohl(tvb, offset));
offset += 4;
break;
case NT_TRANS_SET_USER_QUOTA:
break;
}
return offset;
}
static int
dissect_nt_trans_setup_response(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *parent_tree,
int len, nt_trans_data *ntd _U_)
{
smb_info_t *si;
smb_nt_transact_info_t *nti;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_NTI)
nti = si->sip->extra_info;
else
nti = NULL;
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, len);
if(nti != NULL){
proto_tree_add_text(parent_tree, tvb, offset, len,
"%s Setup",
val_to_str_ext(nti->subcmd, &nt_cmd_vals_ext, "Unknown NT Transaction (%u)"));
} else {
proto_tree_add_text(parent_tree, tvb, offset, len,
"Unknown NT Transaction Setup (matching request not seen)");
}
}
if (nti == NULL) {
offset += len;
return offset;
}
switch(nti->subcmd){
case NT_TRANS_CREATE:
break;
case NT_TRANS_IOCTL:
break;
case NT_TRANS_SSD:
break;
case NT_TRANS_NOTIFY:
break;
case NT_TRANS_RENAME:
break;
case NT_TRANS_QSD:
break;
case NT_TRANS_GET_USER_QUOTA:
break;
case NT_TRANS_SET_USER_QUOTA:
break;
}
return offset;
}
static int
dissect_nt_transaction_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc, sc;
guint32 pc=0, po=0, pd=0, dc=0, od=0, dd=0;
guint32 td=0, tp=0;
smb_info_t *si;
smb_nt_transact_info_t *nti=NULL;
static nt_trans_data ntd;
guint16 bc;
gint32 padcnt;
fragment_data *r_fd = NULL;
tvbuff_t *pd_tvb=NULL;
gboolean save_fragmented;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_NTI)
nti = si->sip->extra_info;
else
nti = NULL;
if(nti != NULL){
proto_tree_add_uint(tree, hf_smb_nt_trans_subcmd, tvb, 0, 0, nti->subcmd);
if(check_col(pinfo->cinfo, COL_INFO)){
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(nti->subcmd, &nt_cmd_vals_ext, "<unknown (%u)>"));
}
} else {
proto_tree_add_text(tree, tvb, offset, 0,
"Function: <unknown function - could not find matching request>");
col_append_str(pinfo->cinfo, COL_INFO, ", <unknown>");
}
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 3, ENC_NA);
offset += 3;
tp = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_total_param_count, tvb, offset, 4, tp);
offset += 4;
td = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_total_data_count, tvb, offset, 4, td);
offset += 4;
pc = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_count32, tvb, offset, 4, pc);
offset += 4;
po = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_offset32, tvb, offset, 4, po);
offset += 4;
pd = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_disp32, tvb, offset, 4, pd);
offset += 4;
dc = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_count32, tvb, offset, 4, dc);
offset += 4;
od = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset32, tvb, offset, 4, od);
offset += 4;
dd = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_disp32, tvb, offset, 4, dd);
offset += 4;
sc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_setup_count, tvb, offset, 1, sc);
offset += 1;
if(sc){
dissect_nt_trans_setup_response(tvb, pinfo, offset, tree, sc*2, &ntd);
offset += sc*2;
}
BYTE_COUNT;
save_fragmented = pinfo->fragmented;
if( (td&&(td!=dc)) || (tp&&(tp!=pc)) ){
pinfo->fragmented = TRUE;
if(smb_trans_reassembly){
if(pc && ((unsigned int)tvb_length_remaining(tvb, po)>=pc) ){
r_fd = smb_trans_defragment(tree, pinfo, tvb,
po, pc, pd, td+tp);
}
if((r_fd==NULL) && dc && ((unsigned int)tvb_length_remaining(tvb, od)>=dc) ){
r_fd = smb_trans_defragment(tree, pinfo, tvb,
od, dc, dd+tp, td+tp);
}
}
}
if(r_fd){
proto_item *frag_tree_item;
pd_tvb = tvb_new_child_real_data(tvb, r_fd->data, r_fd->datalen,
r_fd->datalen);
add_new_data_source(pinfo, pd_tvb, "Reassembled SMB");
show_fragment_tree(r_fd, &smb_frag_items, tree, pinfo, pd_tvb, &frag_tree_item);
}
if(pd_tvb){
dissect_nt_trans_param_response(pd_tvb, pinfo, 0, tree, tp,
&ntd, (guint16) tvb_length(pd_tvb));
dissect_nt_trans_data_response(pd_tvb, pinfo, tp, tree, td, &ntd, nti);
} else {
if(po>(guint32)offset){
padcnt = po-offset;
if (padcnt > bc)
padcnt = bc;
CHECK_BYTE_COUNT(padcnt);
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(pc){
CHECK_BYTE_COUNT(pc);
dissect_nt_trans_param_response(tvb, pinfo, offset, tree, pc, &ntd, bc);
COUNT_BYTES(pc);
}
if(od>(guint32)offset){
padcnt = od-offset;
if (padcnt > bc)
padcnt = bc;
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(dc){
CHECK_BYTE_COUNT(dc);
dissect_nt_trans_data_response(tvb, pinfo, offset, tree, dc, &ntd, nti);
COUNT_BYTES(dc);
}
}
pinfo->fragmented = save_fragmented;
END_OF_SMB
return offset;
}
static int
dissect_open_print_file_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint8 wc;
guint16 bc;
DISSECTOR_ASSERT(si);
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_setup_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_print_mode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, TRUE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_print_identifier, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
END_OF_SMB
return offset;
}
static int
dissect_write_print_file_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
int cnt;
guint8 wc;
guint16 bc, fid;
WORD_COUNT;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len, tvb, offset, 2, cnt);
COUNT_BYTES(2);
offset = dissect_file_data(tvb, tree, offset, (guint16) cnt, (guint16) cnt);
END_OF_SMB
return offset;
}
static int
dissect_get_print_queue_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_max_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_smb_start_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_print_queue_element(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent_tree, int offset, guint16 *bcp, gboolean *trunc)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
DISSECTOR_ASSERT(si);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 28,
"Queue entry");
tree = proto_item_add_subtree(item, ett_smb_print_queue_entry);
}
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_print_queue_date,
hf_smb_print_queue_dos_date, hf_smb_print_queue_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_print_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(2);
proto_tree_add_item(tree, hf_smb_print_spool_file_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(2);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_print_spool_file_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
COUNT_BYTES_SUBR(1);
fn_len = 16;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, TRUE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_print_spool_file_name, tvb, offset, 16,
fn);
COUNT_BYTES_SUBR(fn_len);
*trunc = FALSE;
return offset;
}
static int
dissect_get_print_queue_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 cnt=0, len;
guint8 wc;
guint16 bc;
gboolean trunc;
WORD_COUNT;
cnt = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_count, tvb, offset, 2, cnt);
offset += 2;
proto_tree_add_item(tree, hf_smb_restart_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_len, tvb, offset, 2, len);
COUNT_BYTES(2);
while(cnt--){
offset = dissect_print_queue_element(tvb, pinfo, tree, offset,
&bc, &trunc);
if (trunc)
goto endofcommand;
}
END_OF_SMB
return offset;
}
static int
dissect_send_single_block_message_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
int name_len;
guint16 bc;
guint8 wc;
guint16 message_len;
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
name_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(name_len);
proto_tree_add_item(tree, hf_smb_originator_name, tvb, offset,
name_len, ENC_ASCII|ENC_NA);
COUNT_BYTES(name_len);
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
name_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(name_len);
proto_tree_add_item(tree, hf_smb_destination_name, tvb, offset,
name_len, ENC_ASCII|ENC_NA);
COUNT_BYTES(name_len);
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
message_len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_message_len, tvb, offset, 2,
message_len);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(message_len);
proto_tree_add_item(tree, hf_smb_message, tvb, offset, message_len,
ENC_ASCII|ENC_NA);
COUNT_BYTES(message_len);
END_OF_SMB
return offset;
}
static int
dissect_send_multi_block_message_start_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
int name_len;
guint16 bc;
guint8 wc;
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
name_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(name_len);
proto_tree_add_item(tree, hf_smb_originator_name, tvb, offset,
name_len, ENC_ASCII|ENC_NA);
COUNT_BYTES(name_len);
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
name_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(name_len);
proto_tree_add_item(tree, hf_smb_destination_name, tvb, offset,
name_len, ENC_ASCII|ENC_NA);
COUNT_BYTES(name_len);
END_OF_SMB
return offset;
}
static int
dissect_message_group_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 bc;
guint8 wc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_mgid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_send_multi_block_message_text_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint16 bc;
guint8 wc;
guint16 message_len;
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
CHECK_BYTE_COUNT(2);
message_len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_message_len, tvb, offset, 2,
message_len);
COUNT_BYTES(2);
CHECK_BYTE_COUNT(message_len);
proto_tree_add_item(tree, hf_smb_message, tvb, offset, message_len,
ENC_ASCII|ENC_NA);
COUNT_BYTES(message_len);
END_OF_SMB
return offset;
}
static int
dissect_forwarded_name(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
int name_len;
guint16 bc;
guint8 wc;
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
name_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(name_len);
proto_tree_add_item(tree, hf_smb_forwarded_name, tvb, offset,
name_len, ENC_ASCII|ENC_NA);
COUNT_BYTES(name_len);
END_OF_SMB
return offset;
}
static int
dissect_get_machine_name_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
int name_len;
guint16 bc;
guint8 wc;
WORD_COUNT;
BYTE_COUNT;
CHECK_BYTE_COUNT(1);
proto_tree_add_item(tree, hf_smb_buffer_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES(1);
name_len = tvb_strsize(tvb, offset);
CHECK_BYTE_COUNT(name_len);
proto_tree_add_item(tree, hf_smb_machine_name, tvb, offset,
name_len, ENC_ASCII|ENC_NA);
COUNT_BYTES(name_len);
END_OF_SMB
return offset;
}
static int
dissect_nt_create_andx_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0;
guint16 bc;
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint32 create_flags=0, access_mask=0, file_attributes=0, share_access=0, create_options=0, create_disposition=0;
DISSECTOR_ASSERT(si);
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
fn_len = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 2, fn_len);
offset += 2;
create_flags=tvb_get_letohl(tvb, offset);
offset = dissect_nt_create_bits(tvb, tree, offset, 4, create_flags);
proto_tree_add_item(tree, hf_smb_root_dir_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
access_mask=tvb_get_letohl(tvb, offset);
offset = dissect_smb_access_mask_bits(tvb, tree, offset, 4, access_mask);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
file_attributes=tvb_get_letohl(tvb, offset);
offset = dissect_file_ext_attr_bits(tvb, tree, offset, 4, file_attributes);
share_access=tvb_get_letohl(tvb, offset);
offset = dissect_nt_share_access_bits(tvb, tree, offset, 4, share_access);
create_disposition=tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_smb_nt_create_disposition, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
create_options=tvb_get_letohl(tvb, offset);
offset = dissect_nt_create_options_bits(tvb, tree, offset, 4, create_options);
proto_tree_add_item(tree, hf_smb_nt_impersonation_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_security_flags(tvb, tree, offset);
BYTE_COUNT;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
if (fn == NULL)
goto endofcommand;
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES(fn_len);
if((!pinfo->fd->flags.visited) && si->sip && fn){
smb_fid_saved_info_t *fsi;
fsi=se_alloc(sizeof(smb_fid_saved_info_t));
fsi->filename=se_strdup(fn);
fsi->create_flags=create_flags;
fsi->access_mask=access_mask;
fsi->file_attributes=file_attributes;
fsi->share_access=share_access;
fsi->create_options=create_options;
fsi->create_disposition=create_disposition;
si->sip->extra_info_type=SMB_EI_FILEDATA;
si->sip->extra_info=fsi;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
return offset;
}
static int
dissect_nt_create_andx_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree)
{
guint8 wc, cmd=0xff;
guint16 andxoffset=0;
guint16 bc;
guint16 fid=0;
guint16 ftype;
guint8 isdir;
smb_fid_info_t *fid_info=NULL;
smb_info_t *si;
si = pinfo->private_data;
WORD_COUNT;
cmd = tvb_get_guint8(tvb, offset);
if(cmd!=0xff){
proto_tree_add_uint_format(tree, hf_smb_cmd, tvb, offset, 1, cmd, "AndXCommand: %s (0x%02x)", decode_smb_name(cmd), cmd);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "AndXCommand: No further commands (0xff)");
}
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
andxoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_andxoffset, tvb, offset, 2, andxoffset);
offset += 2;
proto_tree_add_item(tree, hf_smb_oplock_level, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
fid = tvb_get_letohs(tvb, offset);
fid_info=dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
proto_tree_add_item(tree, hf_smb_create_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_create_time);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_access_time);
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_last_write_time);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_change_time);
offset = dissect_file_ext_attr(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (fid_info) {
fid_info->end_of_file=tvb_get_letoh64(tvb, offset);
}
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
ftype=tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb_file_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_ipc_state(tvb, tree, offset, FALSE);
isdir=tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_smb_is_directory, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_FILEDATA &&
((smb_fid_saved_info_t *)(si->sip->extra_info))->create_flags & 0x10) {
proto_item *mar = NULL;
proto_item *gmar = NULL;
proto_tree *tr = NULL;
proto_tree_add_item(tree, hf_smb_volume_guid,
tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_smb_file_id_64bit,
tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
mar = proto_tree_add_text(tree, tvb, offset, 4,
"Maximal Access Rights");
tr = proto_item_add_subtree(mar, ett_smb_nt_access_mask);
offset = dissect_smb_access_mask(tvb, tr, offset);
gmar = proto_tree_add_text(tree, tvb, offset, 4,
"Guest Maximal Access Rights");
tr = proto_item_add_subtree(gmar, ett_smb_nt_access_mask);
offset = dissect_smb_access_mask(tvb, tr, offset);
}
if(ftype==0){
if(isdir==0){
if(fid_info){
fid_info->type=SMB_FID_TYPE_FILE;
}
} else {
if(fid_info){
fid_info->type=SMB_FID_TYPE_DIR;
}
}
}
if(ftype==2){
if(fid_info){
fid_info->type=SMB_FID_TYPE_PIPE;
}
}
BYTE_COUNT;
END_OF_SMB
if (cmd != 0xff) {
if (andxoffset < offset)
THROW(ReportedBoundsError);
dissect_smb_command(tvb, pinfo, andxoffset, smb_tree, cmd, FALSE);
}
if(si->nt_status){
dissect_smb_fid(tvb, pinfo, tree, 0, 0, fid, TRUE, TRUE, TRUE);
}
return offset;
}
static int
dissect_nt_cancel_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_ff2_flags(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
mask = tvb_get_letohs(tvb, offset);
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I) {
t2i = si->sip->extra_info;
if (t2i != NULL) {
if (!pinfo->fd->flags.visited)
t2i->resume_keys = (mask & FF2_RESUME);
}
}
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_find_first2_flags);
proto_tree_add_boolean(tree, hf_smb_ff2_backup,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_ff2_continue,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_ff2_resume,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_ff2_close_eos,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_ff2_close,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
int
dissect_get_dfs_request_data(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint16 *bcp)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
guint16 bc = *bcp;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_max_referral_level, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", File: %s",
format_text(fn, strlen(fn)));
}
*bcp = bc;
return offset;
}
static int
dissect_transaction2_request_parameters(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent_tree, int offset, int subcmd, guint16 bc)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
int fn_len;
const char *fn;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I)
t2i = si->sip->extra_info;
else
t2i = NULL;
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, bc);
item = proto_tree_add_text(parent_tree, tvb, offset, bc,
"%s Parameters",
val_to_str_ext(subcmd, &trans2_cmd_vals_ext,
"Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_transaction_params);
}
switch(subcmd){
case 0x0000:
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_open_flags(tvb, tree, offset, 0x000f);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_access(tvb, tree, offset, "Desired");
bc -= 2;
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_search_attributes(tvb, tree, offset);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_file_attributes(tvb, tree, offset);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time,
hf_smb_create_dos_date, hf_smb_create_dos_time,
TRUE);
bc -= 4;
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_open_function(tvb, tree, offset);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(4);
CHECK_BYTE_COUNT_TRANS(10);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 10, ENC_NA);
COUNT_BYTES_TRANS(10);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x0001:
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_search_attributes(tvb, tree, offset);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_search_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_ff2_flags(tvb, pinfo, tree, offset);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_ff2_information_level, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_storage_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
if(t2i && !t2i->name){
t2i->name = se_strdup(fn);
}
proto_tree_add_string(tree, hf_smb_search_pattern, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Pattern: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x0002:
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_search_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_search_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_ff2_information_level, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_resume, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(4);
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_ff2_flags(tvb, pinfo, tree, offset);
bc -= 2;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Continue: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x0003:
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_qfsi_information_level, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(si->info_level, qfsi_vals,
"Unknown (0x%02x)"));
break;
case 0x0004:
CHECK_BYTE_COUNT_TRANS(4);
si->info_level = tvb_get_letohs(tvb, offset+2);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_sfsi_information_level, tvb, offset+2, 2, si->info_level);
COUNT_BYTES_TRANS(4);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(si->info_level, sfsi_vals,
"Unknown (0x%02x)"));
break;
case 0x0005:
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_qpi_loi, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(
pinfo->cinfo, COL_INFO, ", %s",
val_to_str(si->info_level, qpi_loi_vals,
"Unknown (%u)"));
}
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
COUNT_BYTES_TRANS(4);
if(si->unicode)
fn = tvb_get_ephemeral_unicode_stringz(tvb, offset, &fn_len, ENC_LITTLE_ENDIAN);
else
fn = tvb_get_ephemeral_stringz(tvb, offset, &fn_len);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if(t2i && !t2i->name){
t2i->name = se_strdup(fn);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x0006:
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_spi_loi, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
COUNT_BYTES_TRANS(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x0007: {
guint16 fid;
CHECK_BYTE_COUNT_TRANS(2);
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_qpi_loi, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(
pinfo->cinfo, COL_INFO, ", %s",
val_to_str(si->info_level, qpi_loi_vals,
"Unknown (%u)"));
}
break;
}
case 0x0008: {
guint16 fid;
CHECK_BYTE_COUNT_TRANS(2);
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_spi_loi, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
#if 0
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_sfi_ioflag(tvb, tree, offset);
bc -= 2;
#else
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
COUNT_BYTES_TRANS(2);
#endif
break;
}
case 0x0009:
break;
case 0x000a:
break;
case 0x000b:
CHECK_BYTE_COUNT_TRANS(2);
offset = dissect_search_attributes(tvb, tree, offset);
bc -= 2;
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_change_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
si->info_level = tvb_get_letohs(tvb, offset);
if (t2i != NULL && !pinfo->fd->flags.visited)
t2i->info_level = si->info_level;
proto_tree_add_uint(tree, hf_smb_fn_information_level, tvb, offset, 2, si->info_level);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
COUNT_BYTES_TRANS(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Path: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x000c:
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_monitor_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
CHECK_BYTE_COUNT_TRANS(2);
proto_tree_add_item(tree, hf_smb_change_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS(2);
break;
case 0x000d:
CHECK_BYTE_COUNT_TRANS(4);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 4, ENC_NA);
COUNT_BYTES_TRANS(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len,
FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_dir_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dir: %s",
format_text(fn, strlen(fn)));
}
break;
case 0x000e:
break;
case 0x0010:
offset = dissect_get_dfs_request_data(tvb, pinfo, tree, offset, &bc);
break;
case 0x0011:
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", File: %s",
format_text(fn, strlen(fn)));
}
break;
}
if(bc != 0){
proto_tree_add_item(tree, hf_smb_unknown, tvb, offset, bc, ENC_NA);
offset += bc;
}
return offset;
}
static guint16
dissect_transaction_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_transaction_flags);
proto_tree_add_boolean(tree, hf_smb_transaction_flags_owt,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_transaction_flags_dtid,
tvb, offset, 2, mask);
}
return mask;
}
static int
dissect_get_dfs_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_get_dfs_flags);
proto_tree_add_boolean(tree, hf_smb_get_dfs_server_hold_storage,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_get_dfs_fielding,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_dfs_referral_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_dfs_referral_flags);
proto_tree_add_boolean(tree, hf_smb_dfs_referral_flags_name_list_referral,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_dfs_referral_flags_target_set_boundary,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static int
dissect_dfs_inconsistency_data(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint16 *bcp)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_dfs_referral_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_dfs_referral_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_dfs_referral_server_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
offset = dissect_dfs_referral_flags(tvb, tree, offset);
*bcp -= 2;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, bcp);
CHECK_STRING_TRANS_SUBR(fn);
proto_tree_add_string(tree, hf_smb_dfs_referral_node, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS_SUBR(fn_len);
return offset;
}
static int
dissect_dfs_referral_strings(tvbuff_t *tvb, proto_tree *tree, int hfindex,
int nstring, int stroffset, int oldoffset, int offset,
guint16 bc, gboolean unicode, int *end)
{
int istring;
const char *str;
int str_len;
if (stroffset <= oldoffset)
return oldoffset;
bc -= (stroffset - offset);
for (istring=0; istring<nstring; istring++) {
if ((gint16)bc > 0) {
str = get_unicode_or_ascii_string(tvb, &stroffset, unicode, &str_len, FALSE, FALSE, &bc);
CHECK_STRING_TRANS_SUBR(str);
proto_tree_add_string(tree, hfindex, tvb, stroffset, str_len, str);
stroffset += str_len;
bc -= str_len;
if (end && (*end < stroffset))
*end = stroffset;
}
}
return offset;
}
static int
dissect_dfs_referral_string(tvbuff_t *tvb, proto_tree *tree, int hfindex,
int stroffset, int oldoffset, int offset,
guint16 bc, gboolean unicode, int *end)
{
return dissect_dfs_referral_strings(tvb, tree, hfindex,
1, stroffset, oldoffset, offset,
bc, unicode, end);
}
static int
dissect_dfs_referral_entry_v2(tvbuff_t *tvb, proto_tree *tree, int oldoffset, int offset,
guint16 refflags _U_, guint16 *bcp, gboolean unicode, int *ucstring_end)
{
guint16 pathoffset;
guint16 altpathoffset;
guint16 nodeoffset;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_dfs_referral_proximity, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_dfs_referral_ttl, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
pathoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_path_offset, tvb, offset, 2, pathoffset);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
altpathoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_alt_path_offset, tvb, offset, 2, altpathoffset);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
nodeoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_node_offset, tvb, offset, 2, nodeoffset);
COUNT_BYTES_TRANS_SUBR(2);
if (pathoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_path,
pathoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
if (altpathoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_alt_path,
altpathoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
if (nodeoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_node,
nodeoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
return offset;
}
static int
dissect_dfs_referral_entry_v3(tvbuff_t *tvb, proto_tree *tree, int oldoffset, int offset,
guint16 refflags, guint16 *bcp, gboolean unicode, int *ucstring_end)
{
guint16 domoffset;
guint16 nexpnames;
guint16 expoffset;
guint16 pathoffset;
guint16 altpathoffset;
guint16 nodeoffset;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_dfs_referral_ttl, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
if (refflags & REFENT_FLAGS_NAME_LIST_REFERRAL) {
CHECK_BYTE_COUNT_TRANS_SUBR(2);
domoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_domain_offset, tvb, offset, 2, domoffset);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
nexpnames = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_number_of_expnames, tvb, offset, 2, nexpnames);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
expoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_expnames_offset, tvb, offset, 2, expoffset);
COUNT_BYTES_TRANS_SUBR(2);
if (domoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_domain_name,
domoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
if (expoffset) {
proto_item *expitem = NULL;
proto_tree *exptree = NULL;
expitem = proto_tree_add_text(tree, tvb, offset, *bcp, "Expanded Names");
exptree = proto_item_add_subtree(expitem, ett_smb_dfs_referral_expnames);
dissect_dfs_referral_strings(tvb, exptree, hf_smb_dfs_referral_expname,
nexpnames, expoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
} else {
CHECK_BYTE_COUNT_TRANS_SUBR(2);
pathoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_path_offset, tvb, offset, 2, pathoffset);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
altpathoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_alt_path_offset, tvb, offset, 2, altpathoffset);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
nodeoffset = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_referral_node_offset, tvb, offset, 2, nodeoffset);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(16);
proto_tree_add_item(tree, hf_smb_dfs_referral_server_guid, tvb, offset, 16, ENC_NA);
COUNT_BYTES_TRANS_SUBR(16);
if (pathoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_path,
pathoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
if (altpathoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_alt_path,
altpathoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
if (nodeoffset) {
dissect_dfs_referral_string(tvb, tree, hf_smb_dfs_referral_node,
nodeoffset+oldoffset, oldoffset, offset,
*bcp, unicode, ucstring_end);
}
}
return offset;
}
int
dissect_get_dfs_referral_data(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, guint16 *bcp)
{
smb_info_t *si = pinfo->private_data;
guint16 numref;
guint16 refsize;
guint16 refflags;
int fn_len;
const char *fn;
int unklen;
int ucstring_end;
int ucstring_len;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_dfs_path_consumed, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
numref = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_dfs_num_referrals, tvb, offset, 2, numref);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
offset = dissect_get_dfs_flags(tvb, tree, offset);
*bcp -= 2;
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, 2, ENC_NA);
COUNT_BYTES_TRANS_SUBR(2);
if(numref){
proto_item *ref_item = NULL;
proto_tree *ref_tree = NULL;
int old_offset=offset;
if(tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
ref_item = proto_tree_add_text(tree,
tvb, offset, *bcp, "Referrals");
ref_tree = proto_item_add_subtree(ref_item,
ett_smb_dfs_referrals);
}
ucstring_end = -1;
while(numref--){
proto_item *ri = NULL;
proto_tree *rt = NULL;
int old_offset_2=offset;
guint16 version;
if(tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
ri = proto_tree_add_text(ref_tree,
tvb, offset, *bcp, "Referral");
rt = proto_item_add_subtree(ri,
ett_smb_dfs_referral);
}
CHECK_BYTE_COUNT_TRANS_SUBR(2);
version = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(rt, hf_smb_dfs_referral_version,
tvb, offset, 2, version);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
refsize = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(rt, hf_smb_dfs_referral_size, tvb, offset, 2, refsize);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(rt, hf_smb_dfs_referral_server_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
refflags = tvb_get_letohs(tvb, offset);
offset = dissect_dfs_referral_flags(tvb, rt, offset);
*bcp -= 2;
switch(version){
case 1:
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, bcp);
CHECK_STRING_TRANS_SUBR(fn);
proto_tree_add_string(rt, hf_smb_dfs_referral_node, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS_SUBR(fn_len);
break;
case 2:
offset = dissect_dfs_referral_entry_v2(tvb, rt, old_offset_2, offset,
refflags, bcp, si->unicode, &ucstring_end);
break;
case 3:
offset = dissect_dfs_referral_entry_v3(tvb, rt, old_offset_2, offset,
refflags, bcp, si->unicode, &ucstring_end);
break;
case 4:
offset = dissect_dfs_referral_entry_v3(tvb, rt, old_offset_2, offset,
refflags, bcp, si->unicode, &ucstring_end);
break;
}
unklen = (old_offset_2 + refsize) - offset;
if (unklen < 0) {
unklen = 0;
}
if (unklen != 0) {
CHECK_BYTE_COUNT_TRANS_SUBR(unklen);
proto_tree_add_item(rt, hf_smb_unknown, tvb,
offset, unklen, ENC_NA);
COUNT_BYTES_TRANS_SUBR(unklen);
}
proto_item_set_len(ri, offset-old_offset_2);
}
if (ucstring_end > offset) {
ucstring_len = ucstring_end - offset;
if (*bcp < ucstring_len)
ucstring_len = *bcp;
offset += ucstring_len;
*bcp -= ucstring_len;
}
proto_item_set_len(ref_item, offset-old_offset);
}
return offset;
}
static int
dissect_smb_standard_8byte_timestamps(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_create_time);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_access_time);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_last_write_time);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_change_time);
*bcp -= 8;
*trunc = FALSE;
return offset;
}
static int
dissect_qsfi_SMB_INFO_STANDARD(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time, hf_smb_create_dos_date, hf_smb_create_dos_time,
FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_access_time, hf_smb_access_dos_date, hf_smb_access_dos_time,
FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time, hf_smb_last_write_dos_date, hf_smb_last_write_dos_time,
FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(2);
offset = dissect_file_attributes(tvb, tree, offset);
*bcp -= 2;
if (*bcp != 0) {
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset,
4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
}
*trunc = FALSE;
return offset;
}
static int
dissect_qfi_SMB_INFO_QUERY_EA_SIZE(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time, hf_smb_create_dos_date, hf_smb_create_dos_time,
FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_access_time, hf_smb_access_dos_date, hf_smb_access_dos_time,
FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time, hf_smb_last_write_dos_date, hf_smb_last_write_dos_time,
FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(2);
offset = dissect_file_attributes(tvb, tree, offset);
*bcp -= 2;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
static int
dissect_4_2_16_2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
guint8 name_len;
guint16 data_len;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
while (*bcp > 0) {
proto_item *item;
proto_tree *subtree;
int start_offset = offset;
guint8 *name;
item = proto_tree_add_text(
tree, tvb, offset, 0, "Extended Attribute");
subtree = proto_item_add_subtree(item, ett_smb_ea);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(
subtree, hf_smb_ea_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
name_len = tvb_get_guint8(tvb, offset);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(
subtree, hf_smb_ea_name_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
data_len = tvb_get_letohs(tvb, offset);
CHECK_BYTE_COUNT_SUBR(2);
proto_tree_add_item(
subtree, hf_smb_ea_data_length, tvb, offset, 2, ENC_NA);
COUNT_BYTES_SUBR(2);
name = tvb_get_ephemeral_string(tvb, offset, name_len);
proto_item_append_text(item, ": %s", format_text(name, strlen(name)));
CHECK_BYTE_COUNT_SUBR(name_len + 1);
proto_tree_add_item(
subtree, hf_smb_ea_name, tvb, offset, name_len + 1,
ENC_ASCII|ENC_NA);
COUNT_BYTES_SUBR(name_len + 1);
CHECK_BYTE_COUNT_SUBR(data_len);
proto_tree_add_item(
subtree, hf_smb_ea_data, tvb, offset, data_len, ENC_NA);
COUNT_BYTES_SUBR(data_len);
proto_item_set_len(item, offset - start_offset);
}
*trunc = FALSE;
return offset;
}
static int
dissect_4_2_16_3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
DISSECTOR_ASSERT(si);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
*trunc = FALSE;
return offset;
}
static int
dissect_4_2_16_4(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_STANDARD_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_number_of_links, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_delete_pending, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_is_directory, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_INTERNAL_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_index_number, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
*trunc = FALSE;
return offset;
}
int
dissect_qsfi_SMB_FILE_POSITION_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_position, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
*trunc = FALSE;
return offset;
}
int
dissect_qsfi_SMB_FILE_MODE_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_ALIGNMENT_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_t2_alignment, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_EA_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
int
dissect_qsfi_SMB_FILE_ALLOCATION_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
*trunc = FALSE;
return offset;
}
int
dissect_qsfi_SMB_FILE_ENDOFFILE_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_NAME_INFO(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
int fn_len;
const char *fn;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_name_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
*trunc = FALSE;
return offset;
}
static int
dissect_qfi_SMB_FILE_ALL_INFO(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si;
guint32 fn_len;
const char *fn;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
offset+=4;
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_number_of_links, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_delete_pending, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_is_directory, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
offset+=2;
*bcp -= 2;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
fn_len = (guint32)tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(fn_len);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, TRUE, TRUE, bcp);
if (fn != NULL) {
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
}
if (*trunc)
return offset;
return offset;
}
int
dissect_qfi_SMB_FILE_STREAM_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc, int unicode)
{
proto_item *item;
proto_tree *tree;
int old_offset;
guint32 neo;
int fn_len;
const char *fn;
int padcnt;
for (;;) {
old_offset = offset;
CHECK_BYTE_COUNT_SUBR(4);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "Stream Info");
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
} else {
item = NULL;
tree = NULL;
}
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_t2_stream_name_length, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_t2_stream_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
fn = get_unicode_or_ascii_string(tvb, &offset, unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_t2_stream_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
proto_item_append_text(item, ": %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
if (neo == 0)
break;
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_COMPRESSION_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_t2_compressed_file_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(2);
proto_tree_add_item(tree, hf_smb_t2_compressed_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(2);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_t2_compressed_unit_shift,tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_t2_compressed_chunk_shift, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_t2_compressed_cluster_shift, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(3);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 3, ENC_NA);
COUNT_BYTES_SUBR(3);
*trunc = FALSE;
return offset;
}
static int
dissect_4_2_16_12(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_num_bytes, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_last_status);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_last_access);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_last_change);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_uid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_gid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_unix_file_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_dev_major, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_dev_minor, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_unique_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_permissions, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_nlinks, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
*trunc = FALSE;
return offset;
}
static int
dissect_4_2_16_13(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
const char *fn;
int fn_len = 0;
DISSECTOR_ASSERT(si);
fn = get_unicode_or_ascii_string(
tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(
tree, hf_smb_unix_file_link_dest, tvb, offset, fn_len, fn);
COUNT_BYTES_SUBR(fn_len);
*trunc = FALSE;
return offset;
}
static int
dissect_qspi_unix_acl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
guint16 num_file_aces;
static const int *perm_fields[] = {
&hf_smb_posix_ace_perm_read,
&hf_smb_posix_ace_perm_write,
&hf_smb_posix_ace_perm_execute,
NULL
};
CHECK_BYTE_COUNT_SUBR(2);
proto_tree_add_item(tree, hf_smb_posix_acl_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(2);
CHECK_BYTE_COUNT_SUBR(2);
num_file_aces = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_smb_posix_num_file_aces, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(2);
CHECK_BYTE_COUNT_SUBR(2);
proto_tree_add_item(tree, hf_smb_posix_num_def_aces, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(2);
while(num_file_aces--){
proto_item *it;
proto_tree *tr;
int old_offset = offset;
guint8 ace_type;
it = proto_tree_add_text(tree, tvb, offset, 0, "ACE");
tr = proto_item_add_subtree(it, ett_smb_posix_ace);
CHECK_BYTE_COUNT_SUBR(1);
ace_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tr, hf_smb_posix_ace_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_bitmask(tr, tvb, offset, hf_smb_posix_ace_flags, ett_smb_posix_ace_perms, perm_fields, ENC_BIG_ENDIAN);
COUNT_BYTES_SUBR(1);
switch(ace_type){
case POSIX_ACE_TYPE_USER_OBJ:
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tr, hf_smb_posix_ace_perm_owner_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
COUNT_BYTES_SUBR(4);
break;
case POSIX_ACE_TYPE_GROUP_OBJ:
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tr, hf_smb_posix_ace_perm_owner_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
COUNT_BYTES_SUBR(4);
break;
case POSIX_ACE_TYPE_MASK:
case POSIX_ACE_TYPE_OTHER:
CHECK_BYTE_COUNT_SUBR(8);
COUNT_BYTES_SUBR(8);
break;
case POSIX_ACE_TYPE_USER:
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tr, hf_smb_posix_ace_perm_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
COUNT_BYTES_SUBR(4);
break;
case POSIX_ACE_TYPE_GROUP:
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tr, hf_smb_posix_ace_perm_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
COUNT_BYTES_SUBR(4);
break;
default:
proto_tree_add_text(tr, tvb, offset, 0, "Unknown posix ace type");
CHECK_BYTE_COUNT_SUBR(8);
COUNT_BYTES_SUBR(8);
}
proto_item_set_len(it, offset-old_offset);
}
*trunc = FALSE;
return offset;
}
static int
dissect_qspi_unix_xattr(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, guint16 *bcp _U_, gboolean *trunc)
{
proto_tree_add_text(tree, tvb, offset, 0, "Not Implemented yet");
*trunc = FALSE;
return offset;
}
static int
dissect_qspi_unix_attr_flags(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, guint16 *bcp _U_, gboolean *trunc)
{
proto_tree_add_text(tree, tvb, offset, 0, "Not Implemented yet");
*trunc = FALSE;
return offset;
}
static int
dissect_qpi_unix_permissions(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, guint16 *bcp _U_, gboolean *trunc)
{
proto_tree_add_text(tree, tvb, offset, 0, "Not Implemented yet");
*trunc = FALSE;
return offset;
}
static int
dissect_qspi_unix_lock(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, guint16 *bcp _U_, gboolean *trunc)
{
proto_tree_add_text(tree, tvb, offset, 0, "Not Implemented yet");
*trunc = FALSE;
return offset;
}
static int
dissect_qspi_unix_open(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, guint16 *bcp _U_, gboolean *trunc)
{
proto_tree_add_text(tree, tvb, offset, 0, "Not Implemented yet");
*trunc = FALSE;
return offset;
}
static int
dissect_qspi_unix_unlink(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, guint16 *bcp _U_, gboolean *trunc)
{
proto_tree_add_text(tree, tvb, offset, 0, "Not Implemented yet");
*trunc = FALSE;
return offset;
}
static int
dissect_unix_info2_file_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset, int hf)
{
guint32 flags;
proto_item *item = NULL;
proto_tree *tree = NULL;
flags = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf, tvb, offset, 4,
flags);
tree = proto_item_add_subtree(item, ett_smb_info2_file_flags);
}
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_secure_delete,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_enable_undelete,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_synchronous,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_immutable,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_append_only,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_do_not_backup,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_no_update_atime,
tvb, offset, 4, flags);
proto_tree_add_boolean(tree, hf_smb_unix_info2_file_flags_hidden,
tvb, offset, 4, flags);
offset += 4;
return offset;
}
static int
dissect_qspi_unix_info2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_num_bytes, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_last_status);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_last_access);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_last_change);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_uid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_gid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_unix_file_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_dev_major, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_dev_minor, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_unique_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_permissions, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_unix_file_nlinks, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_unix_file_creation_time);
*bcp -= 8;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_unix_info2_file_flags(tvb, tree, offset, hf_smb_unix_info2_file_flags);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_unix_info2_file_flags(tvb, tree, offset, hf_smb_unix_info2_file_flags_mask);
*bcp -= 4;
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_NETWORK_OPEN_INFO(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_network_unknown, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
int
dissect_qfi_SMB_FILE_ATTRIBUTE_TAG_INFO(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_attribute, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_reparse_tag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
*trunc = FALSE;
return offset;
}
static int
dissect_4_2_19_2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_t2_marked_for_deletion, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
*trunc = FALSE;
return offset;
}
static int
dissect_rename_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
const char *fn;
guint32 target_name_len;
int fn_len;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_replace, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_root_dir_handle, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
target_name_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_target_name_len, tvb, offset, 4, target_name_len);
COUNT_BYTES_SUBR(4);
fn_len = target_name_len;
fn = get_unicode_or_ascii_string(
tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(
tree, hf_smb_target_name, tvb, offset, fn_len, fn);
COUNT_BYTES_SUBR(fn_len);
*trunc = FALSE;
return offset;
}
static int
dissect_disposition_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_disposition_delete_on_close, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
*trunc = FALSE;
return offset;
}
int
dissect_sfi_SMB_FILE_PIPE_INFO(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_pipe_info_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(1);
*trunc = FALSE;
return offset;
}
static int
dissect_qpi_loi_vals(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
proto_item *item, int offset, guint16 *bcp)
{
smb_info_t *si;
gboolean trunc = FALSE;
if(!*bcp){
return offset;
}
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->info_level){
case 1:
offset = dissect_qsfi_SMB_INFO_STANDARD(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 2:
offset = dissect_qfi_SMB_INFO_QUERY_EA_SIZE(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 3:
case 4:
offset = dissect_4_2_16_2(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 6:
offset = dissect_4_2_16_3(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0101:
case 1004:
offset = dissect_4_2_16_4(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0102:
case 1005:
offset = dissect_qfi_SMB_FILE_STANDARD_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1006:
offset = dissect_qfi_SMB_FILE_INTERNAL_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0103:
case 1007:
offset = dissect_qfi_SMB_FILE_EA_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0104:
case 1009:
offset = dissect_qfi_SMB_FILE_NAME_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1014:
offset = dissect_qsfi_SMB_FILE_POSITION_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1016:
offset = dissect_qsfi_SMB_FILE_MODE_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1017:
offset = dissect_qfi_SMB_FILE_ALIGNMENT_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0107:
case 1018:
offset = dissect_qfi_SMB_FILE_ALL_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1019:
offset = dissect_qsfi_SMB_FILE_ALLOCATION_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1020:
offset = dissect_qsfi_SMB_FILE_ENDOFFILE_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0108:
case 1021:
offset = dissect_qfi_SMB_FILE_NAME_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1022:
si->unicode = TRUE;
case 0x0109:
offset = dissect_qfi_SMB_FILE_STREAM_INFO(tvb, pinfo, tree, offset, bcp,
&trunc, si->unicode);
break;
case 0x010b:
case 1028:
offset = dissect_qfi_SMB_FILE_COMPRESSION_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1034:
offset = dissect_qfi_SMB_FILE_NETWORK_OPEN_INFO(tvb, pinfo, tree, offset, bcp, &trunc);
break;
case 1035:
offset = dissect_qfi_SMB_FILE_ATTRIBUTE_TAG_INFO(tvb, pinfo, tree, offset, bcp, &trunc);
break;
case 0x0200:
offset = dissect_4_2_16_12(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0201:
offset = dissect_4_2_16_13(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0202:
break;
case 0x0204:
offset = dissect_qspi_unix_acl(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0205:
offset = dissect_qspi_unix_xattr(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0206:
offset = dissect_qspi_unix_attr_flags(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0207:
offset = dissect_qpi_unix_permissions(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0208:
offset = dissect_qspi_unix_lock(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x020b:
offset = dissect_qspi_unix_info2(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
default:
proto_tree_add_text(tree, tvb, offset, *bcp,
"Information level unknown");
offset += *bcp;
*bcp = 0;
trunc = FALSE;
break;
}
if (trunc) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Information level structure goes past the end of the transation data.");
}
return offset;
}
static int
dissect_spi_loi_vals(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
proto_item *item, int offset, guint16 *bcp)
{
smb_info_t *si;
gboolean trunc;
if(!*bcp){
return offset;
}
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->info_level){
case 1:
offset = dissect_qsfi_SMB_INFO_STANDARD(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 2:
offset = dissect_4_2_16_2(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 4:
offset = dissect_4_2_16_2(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0101:
case 1004:
offset = dissect_4_2_16_4(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0102:
offset = dissect_4_2_19_2(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0103:
case 1019:
offset = dissect_qsfi_SMB_FILE_ALLOCATION_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0104:
case 1020:
offset = dissect_qsfi_SMB_FILE_ENDOFFILE_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0200:
offset = dissect_4_2_16_12(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0201:
offset = dissect_4_2_16_13(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0202:
offset = dissect_4_2_16_13(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0204:
offset = dissect_qspi_unix_acl(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0205:
offset = dissect_qspi_unix_xattr(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0206:
offset = dissect_qspi_unix_attr_flags(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0208:
offset = dissect_qspi_unix_lock(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x0209:
offset = dissect_qspi_unix_open(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x020a:
offset = dissect_qspi_unix_unlink(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 0x020b:
offset = dissect_qspi_unix_info2(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1010:
offset = dissect_rename_info(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1013:
offset = dissect_disposition_info(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1014:
offset = dissect_qsfi_SMB_FILE_POSITION_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1016:
offset = dissect_qsfi_SMB_FILE_MODE_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1023:
offset = dissect_sfi_SMB_FILE_PIPE_INFO(tvb, pinfo, tree, offset, bcp,
&trunc);
break;
case 1025:
case 1029:
case 1032:
case 1039:
case 1040:
proto_tree_add_text(tree, tvb, offset, *bcp,
"Information level not understood");
offset += *bcp;
*bcp = 0;
trunc = FALSE;
break;
default:
proto_tree_add_text(tree, tvb, offset, *bcp,
"Information level unknown");
offset += *bcp;
*bcp = 0;
trunc = FALSE;
break;
}
if (trunc) {
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Information level structure goes past the end of the transation data.");
}
return offset;
}
static void
dissect_quota_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint8 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_guint8(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"Quota Flags: 0x%02x %s", mask,
mask?"Enabled":"Disabled");
tree = proto_item_add_subtree(item, ett_smb_quotaflags);
proto_tree_add_boolean(tree, hf_smb_quota_flags_log_limit,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_quota_flags_log_warning,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_quota_flags_deny_disk,
tvb, offset, 1, mask);
if(mask && (!(mask&0x01))){
proto_item *hidden_item;
hidden_item = proto_tree_add_boolean(tree, hf_smb_quota_flags_enabled,
tvb, offset, 1, 0x01);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
proto_tree_add_boolean(tree, hf_smb_quota_flags_enabled,
tvb, offset, 1, mask);
}
}
}
int
dissect_nt_quota(tvbuff_t *tvb, proto_tree *tree, int offset, guint16 *bcp)
{
CHECK_BYTE_COUNT_TRANS_SUBR(24);
proto_tree_add_item(tree, hf_smb_unknown, tvb,
offset, 24, ENC_NA);
COUNT_BYTES_TRANS_SUBR(24);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_soft_quota_limit, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_hard_quota_limit, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(1);
dissect_quota_flags(tvb, tree, offset);
COUNT_BYTES_TRANS_SUBR(1);
CHECK_BYTE_COUNT_TRANS_SUBR(7);
proto_tree_add_item(tree, hf_smb_unknown, tvb,
offset, 7, ENC_NA);
COUNT_BYTES_TRANS_SUBR(7);
return offset;
}
static int
dissect_sfsi_request(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
int offset, guint16 *bcp)
{
smb_info_t *si;
if(!*bcp){
return offset;
}
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->info_level) {
case 0x203: {
proto_item *blob_item;
tvbuff_t *blob_tvb;
proto_tree *blob_tree;
blob_item = proto_tree_add_item(tree, hf_smb_security_blob,
tvb, offset,
tvb_length_remaining(tvb,offset),
ENC_NA);
blob_tree = proto_item_add_subtree(blob_item,
ett_smb_secblob);
blob_tvb = tvb_new_subset(tvb, offset,
tvb_length_remaining(tvb,offset),
tvb_length_remaining(tvb,offset));
if (tvb_strneql(blob_tvb, 0, "NTLMSSP", 7) == 0) {
call_dissector(ntlmssp_handle, blob_tvb, pinfo, blob_tree);
} else {
call_dissector(gssapi_handle, blob_tvb, pinfo, blob_tree);
}
offset += tvb_length_remaining(tvb,offset);
*bcp = 0;
break;
}
case 1006:
offset = dissect_nt_quota(tvb, tree, offset, bcp);
break;
}
return offset;
}
static int
dissect_sfsi_response(tvbuff_t * tvb _U_, packet_info * pinfo, proto_tree * tree _U_,
int offset, guint16 *bcp)
{
smb_info_t *si;
if(!*bcp){
return offset;
}
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->info_level) {
case 0x203: {
proto_item *blob_item;
tvbuff_t *blob_tvb;
proto_tree *blob_tree;
blob_item = proto_tree_add_item(tree, hf_smb_security_blob,
tvb, offset,
tvb_length_remaining(tvb,offset),
ENC_NA);
blob_tree = proto_item_add_subtree(blob_item,
ett_smb_secblob);
blob_tvb = tvb_new_subset(tvb, offset,
tvb_length_remaining(tvb,offset),
tvb_length_remaining(tvb,offset));
if (tvb_strneql(blob_tvb, 0, "NTLMSSP", 7) == 0) {
call_dissector(ntlmssp_handle, blob_tvb, pinfo, blob_tree);
} else {
call_dissector(gssapi_handle, blob_tvb, pinfo, blob_tree);
}
offset += tvb_length_remaining(tvb,offset);
*bcp = 0;
break;
}
case 1006:
break;
}
return offset;
}
static int
dissect_transaction2_request_data(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent_tree, int offset, int subcmd, guint16 dc)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, dc);
item = proto_tree_add_text(parent_tree, tvb, offset, dc,
"%s Data",
val_to_str_ext(subcmd, &trans2_cmd_vals_ext,
"Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_transaction_data);
}
switch(subcmd){
case 0x0000:
break;
case 0x0001:
break;
case 0x0002:
break;
case 0x0003:
break;
case 0x0004:
offset = dissect_sfsi_request(tvb, pinfo, tree, offset, &dc);
break;
case 0x0005:
break;
case 0x0006:
offset = dissect_spi_loi_vals(tvb, pinfo, tree, item, offset, &dc);
break;
case 0x0007:
break;
case 0x0008:
offset = dissect_spi_loi_vals(tvb, pinfo, tree, item, offset, &dc);
break;
case 0x0009:
break;
case 0x000a:
break;
case 0x000b:
break;
case 0x000c:
break;
case 0x000d:
break;
case 0x000e:
break;
case 0x0010:
break;
case 0x0011:
offset = dissect_dfs_inconsistency_data(tvb, pinfo, tree, offset, &dc);
break;
}
if(dc != 0){
proto_tree_add_item(tree, hf_smb_unknown, tvb, offset, dc, ENC_NA);
offset += dc;
}
return offset;
}
static void
dissect_trans_data(tvbuff_t *s_tvb, tvbuff_t *p_tvb, tvbuff_t *d_tvb,
proto_tree *tree)
{
int i;
int offset;
guint length;
if (s_tvb != NULL) {
length = tvb_reported_length(s_tvb);
for (i = 0, offset = 0; length >= 2;
i++, offset += 2, length -= 2) {
proto_tree_add_text(tree, s_tvb, offset, 2,
"Setup Word %d: 0x%04x", i,
tvb_get_letohs(s_tvb, offset));
}
}
if (p_tvb != NULL) {
length = tvb_reported_length(p_tvb);
if (length != 0) {
proto_tree_add_text(tree, p_tvb, 0, length,
"Parameters: %s",
tvb_bytes_to_str(p_tvb, 0, length));
}
}
if (d_tvb != NULL) {
length = tvb_reported_length(d_tvb);
if (length != 0) {
proto_tree_add_text(tree, d_tvb, 0, length,
"Data: %s", tvb_bytes_to_str(d_tvb, 0, length));
}
}
}
static int
dissect_transaction_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc, sc=0;
int so=offset;
int sl=0;
int spo=offset;
int spc=0;
guint16 od=0, po=0, pc=0, dc=0, pd, dd=0;
int subcmd = -1;
guint32 to;
int an_len;
const char *an = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
smb_transact_info_t *tri;
guint16 bc;
int padcnt;
gboolean dissected_trans;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
WORD_COUNT;
if(wc==8){
proto_tree_add_uint(tree, hf_smb_total_param_count, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_uint(tree, hf_smb_total_data_count, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
pc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_count16, tvb, offset, 2, pc);
offset += 2;
po = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_offset16, tvb, offset, 2, po);
offset += 2;
pd = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_disp16, tvb, offset, 2, pd);
offset += 2;
dc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_count16, tvb, offset, 2, dc);
offset += 2;
od = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset16, tvb, offset, 2, od);
offset += 2;
dd = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_disp16, tvb, offset, 2, dd);
offset += 2;
if(si->cmd==SMB_COM_TRANSACTION2){
guint16 fid;
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, FALSE, FALSE, FALSE);
offset += 2;
}
so = offset;
sl = 0;
} else {
proto_tree_add_uint(tree, hf_smb_total_param_count, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_uint(tree, hf_smb_total_data_count, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_uint(tree, hf_smb_max_param_count, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_uint(tree, hf_smb_max_data_count, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_uint(tree, hf_smb_max_setup_count, tvb, offset, 1, tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
dissect_transaction_flags(tvb, tree, offset);
offset += 2;
to = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_smb_timeout, tvb, offset, 4, to, "Timeout: %s", smbext20_timeout_msecs_to_str(to));
offset += 4;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
pc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_count16, tvb, offset, 2, pc);
offset += 2;
po = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_offset16, tvb, offset, 2, po);
offset += 2;
dc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_count16, tvb, offset, 2, dc);
offset += 2;
od = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset16, tvb, offset, 2, od);
offset += 2;
dd = 0;
sc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_setup_count, tvb, offset, 1, sc);
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
so = offset;
sl = sc*2;
if(sc){
switch(si->cmd){
case SMB_COM_TRANSACTION2:
subcmd = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_trans2_subcmd,
tvb, offset, 2, subcmd);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(subcmd, &trans2_cmd_vals_ext,
"Unknown (0x%02x)"));
}
if (!si->unidir) {
if(!pinfo->fd->flags.visited && si->sip){
t2i = se_alloc(sizeof(smb_transact2_info_t));
t2i->subcmd = subcmd;
t2i->info_level = -1;
t2i->resume_keys = FALSE;
t2i->name = NULL;
si->sip->extra_info = t2i;
si->sip->extra_info_type = SMB_EI_T2I;
}
}
break;
case SMB_COM_TRANSACTION:
break;
}
offset += sl;
}
}
BYTE_COUNT;
if(wc!=8){
if(si->cmd == SMB_COM_TRANSACTION){
an = get_unicode_or_ascii_string(tvb, &offset,
si->unicode, &an_len, FALSE, FALSE, &bc);
if (an == NULL)
goto endofcommand;
tvb_ensure_bytes_exist(tvb, offset, an_len);
proto_tree_add_string(tree, hf_smb_trans_name, tvb,
offset, an_len, an);
COUNT_BYTES(an_len);
}
}
spo = so;
spc = offset - spo;
if(po>offset){
padcnt = po-offset;
if (padcnt > bc)
padcnt = bc;
tvb_ensure_bytes_exist(tvb, offset, padcnt);
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(pc){
CHECK_BYTE_COUNT(pc);
switch(si->cmd) {
case SMB_COM_TRANSACTION2:
offset = dissect_transaction2_request_parameters(tvb,
pinfo, tree, offset, subcmd, pc);
bc -= pc;
break;
case SMB_COM_TRANSACTION:
COUNT_BYTES(pc);
break;
}
}
if(od>offset){
padcnt = od-offset;
if (padcnt > bc)
padcnt = bc;
tvb_ensure_bytes_exist(tvb, offset, padcnt);
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(dc){
CHECK_BYTE_COUNT(dc);
switch(si->cmd){
case SMB_COM_TRANSACTION2:
offset = dissect_transaction2_request_data(tvb, pinfo,
tree, offset, subcmd, dc);
bc -= dc;
break;
case SMB_COM_TRANSACTION:
COUNT_BYTES(dc);
break;
}
}
if(si->cmd==SMB_COM_TRANSACTION){
if(dd==0){
tvbuff_t *p_tvb, *d_tvb, *s_tvb;
tvbuff_t *sp_tvb, *pd_tvb;
if(pc>0){
if(pc>tvb_length_remaining(tvb, po)){
p_tvb = tvb_new_subset(tvb, po, tvb_length_remaining(tvb, po), pc);
} else {
p_tvb = tvb_new_subset(tvb, po, pc, pc);
}
} else {
p_tvb = NULL;
}
if(dc>0){
if(dc>tvb_length_remaining(tvb, od)){
d_tvb = tvb_new_subset(tvb, od, tvb_length_remaining(tvb, od), dc);
} else {
d_tvb = tvb_new_subset(tvb, od, dc, dc);
}
} else {
d_tvb = NULL;
}
if(sl){
if(sl>tvb_length_remaining(tvb, so)){
s_tvb = tvb_new_subset(tvb, so, tvb_length_remaining(tvb, so), sl);
} else {
s_tvb = tvb_new_subset(tvb, so, sl, sl);
}
} else {
s_tvb = NULL;
}
if (!si->unidir) {
if(!pinfo->fd->flags.visited && si->sip){
tri = se_alloc(sizeof(smb_transact_info_t));
tri->subcmd = -1;
tri->trans_subcmd = -1;
tri->function = -1;
tri->fid = -1;
tri->lanman_cmd = 0;
tri->param_descrip = NULL;
tri->data_descrip = NULL;
tri->aux_data_descrip = NULL;
tri->info_level = -1;
si->sip->extra_info = tri;
si->sip->extra_info_type = SMB_EI_TRI;
} else {
tri = NULL;
}
} else {
tri = NULL;
}
dissected_trans = FALSE;
if (an == NULL)
goto endofcommand;
if(strncmp("\\PIPE\\", an, 6) == 0){
if (tri != NULL)
tri->subcmd=TRANSACTION_PIPE;
sp_tvb = tvb_new_subset(tvb, spo, spc, spc);
pd_tvb = tvb_new_subset_remaining(tvb, po);
dissected_trans = dissect_pipe_smb(sp_tvb,
s_tvb, pd_tvb, p_tvb, d_tvb, an+6, pinfo,
top_tree_global);
if(g_hash_table_lookup(si->ct->tid_service, GUINT_TO_POINTER(si->tid))){
g_hash_table_remove(si->ct->tid_service, GUINT_TO_POINTER(si->tid));
}
g_hash_table_insert(si->ct->tid_service, GUINT_TO_POINTER(si->tid), (void *)TID_IPC);
} else if(strncmp("\\MAILSLOT\\", an, 10) == 0){
if (tri != NULL)
tri->subcmd=TRANSACTION_MAILSLOT;
sp_tvb = tvb_new_subset(tvb, spo, spc, spc);
dissected_trans = dissect_mailslot_smb(sp_tvb,
s_tvb, d_tvb, an+10, pinfo, top_tree_global);
}
if (!dissected_trans)
dissect_trans_data(s_tvb, p_tvb, d_tvb, tree);
} else {
col_append_str(pinfo->cinfo, COL_INFO,
"[transact continuation]");
}
}
END_OF_SMB
return offset;
}
static int
dissect_4_3_4_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len;
const char *fn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
gboolean resume_keys = FALSE;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I) {
t2i = si->sip->extra_info;
if (t2i != NULL)
resume_keys = t2i->resume_keys;
}
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
if (resume_keys) {
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_resume, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
}
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time,
hf_smb_create_dos_date, hf_smb_create_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_access_time,
hf_smb_access_dos_date, hf_smb_access_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time,
hf_smb_last_write_dos_date, hf_smb_last_write_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(2);
offset = dissect_file_attributes(tvb, tree, offset);
*bcp -= 2;
CHECK_BYTE_COUNT_SUBR(1);
fn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 1, fn_len);
COUNT_BYTES_SUBR(1);
if (si->unicode)
fn_len += 2;
else
fn_len++;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len;
const char *fn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
gboolean resume_keys = FALSE;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I) {
t2i = si->sip->extra_info;
if (t2i != NULL)
resume_keys = t2i->resume_keys;
}
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
if (resume_keys) {
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_resume, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
}
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time,
hf_smb_create_dos_date, hf_smb_create_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_access_time,
hf_smb_access_dos_date, hf_smb_access_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_last_write_time,
hf_smb_last_write_dos_date, hf_smb_last_write_dos_time, FALSE);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_alloc_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(2);
offset = dissect_file_attributes(tvb, tree, offset);
*bcp -= 2;
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(1);
fn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 1, fn_len);
COUNT_BYTES_SUBR(1);
if (si->unicode)
fn_len += 2;
else
fn_len++;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len;
const char *fn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 neo;
int padcnt;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
CHECK_BYTE_COUNT_SUBR(4);
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
if(neo){
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len;
const char *fn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 neo;
int padcnt;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
CHECK_BYTE_COUNT_SUBR(4);
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
if(neo){
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len, sfn_len;
const char *fn, *sfn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 neo;
int padcnt;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
CHECK_BYTE_COUNT_SUBR(4);
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(1);
sfn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_short_file_name_len, tvb, offset, 1, sfn_len);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
COUNT_BYTES_SUBR(1);
sfn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &sfn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(sfn);
proto_tree_add_string(tree, hf_smb_short_file_name, tvb, offset, 24,
sfn);
COUNT_BYTES_SUBR(24);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
if(neo){
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_6full(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len;
const char *fn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 neo;
int padcnt;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
CHECK_BYTE_COUNT_SUBR(4);
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_index_number, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
if(neo){
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_6_id_both(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len, sfn_len;
const char *fn, *sfn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 neo;
int padcnt;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
CHECK_BYTE_COUNT_SUBR(4);
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_smb_standard_8byte_timestamps(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc) {
return offset;
}
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_end_of_file, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
CHECK_BYTE_COUNT_SUBR(4);
offset = dissect_file_ext_attr(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(1);
sfn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_short_file_name_len, tvb, offset, 1, sfn_len);
COUNT_BYTES_SUBR(1);
CHECK_BYTE_COUNT_SUBR(1);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
COUNT_BYTES_SUBR(1);
sfn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &sfn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(sfn);
proto_tree_add_string(tree, hf_smb_short_file_name, tvb, offset, 24,
sfn);
COUNT_BYTES_SUBR(24);
CHECK_BYTE_COUNT_SUBR(2);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
COUNT_BYTES_SUBR(2);
CHECK_BYTE_COUNT_SUBR(8);
proto_tree_add_item(tree, hf_smb_index_number, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(8);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
if(neo){
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_7(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree,
int offset, guint16 *bcp, gboolean *trunc)
{
int fn_len;
const char *fn;
int old_offset = offset;
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
guint32 neo;
int padcnt;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if(parent_tree){
tvb_ensure_bytes_exist(tvb, offset, *bcp);
item = proto_tree_add_text(parent_tree, tvb, offset, *bcp, "%s",
val_to_str(si->info_level, ff2_il_vals, "Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_ff2_data);
}
CHECK_BYTE_COUNT_SUBR(4);
neo = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_next_entry_offset, tvb, offset, 4, neo);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_file_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
fn_len = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_file_name_len, tvb, offset, 4, fn_len);
COUNT_BYTES_SUBR(4);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(tree, hf_smb_file_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_SUBR(fn_len);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
format_text(fn, strlen(fn)));
}
if(neo){
padcnt = (old_offset + neo) - offset;
if (padcnt < 0) {
padcnt = 0;
}
if (padcnt != 0) {
CHECK_BYTE_COUNT_SUBR(padcnt);
COUNT_BYTES_SUBR(padcnt);
}
}
proto_item_append_text(item, " File: %s", format_text(fn, strlen(fn)));
proto_item_set_len(item, offset-old_offset);
*trunc = FALSE;
return offset;
}
static int
dissect_4_3_4_8(tvbuff_t *tvb _U_, packet_info *pinfo _U_,
proto_tree *tree, int offset, guint16 *bcp,
gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
const char *fn;
int fn_len;
int pad;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_unix_find_file_nextoffset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_unix_find_file_resumekey, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_4_2_16_12(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc)
return offset;
fn = get_unicode_or_ascii_string(
tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(
tree, hf_smb_unix_file_name, tvb, offset, fn_len, fn);
COUNT_BYTES_SUBR(fn_len);
if (offset % 4) {
pad = 4 - (offset % 4);
COUNT_BYTES_SUBR(pad);
}
*trunc = FALSE;
return offset;
}
static int
dissect_find_file_unix_info2(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset, guint16 *bcp,
gboolean *trunc)
{
smb_info_t *si = pinfo->private_data;
const char *fn;
guint32 namelen;
int fn_len;
int pad;
DISSECTOR_ASSERT(si);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_unix_find_file_nextoffset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
CHECK_BYTE_COUNT_SUBR(4);
proto_tree_add_item(tree, hf_smb_unix_find_file_resumekey, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_SUBR(4);
offset = dissect_qspi_unix_info2(tvb, pinfo, tree, offset, bcp, trunc);
if (*trunc)
return offset;
CHECK_BYTE_COUNT_SUBR(4);
namelen = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_unix_file_name_length, tvb, offset, 4, namelen);
COUNT_BYTES_SUBR(4);
tvb_ensure_bytes_exist(tvb, offset, namelen);
fn_len = namelen;
fn = get_unicode_or_ascii_string(
tvb, &offset, si->unicode, &fn_len, TRUE, TRUE, bcp);
CHECK_STRING_SUBR(fn);
proto_tree_add_string(
tree, hf_smb_unix_file_name, tvb, offset, fn_len, fn);
COUNT_BYTES_SUBR(fn_len);
if (offset % 4) {
pad = 4 - (offset % 4);
COUNT_BYTES_SUBR(pad);
}
*trunc = FALSE;
return offset;
}
static int
dissect_ff2_response_data(tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree, int offset, guint16 *bcp, gboolean *trunc)
{
smb_info_t *si;
if(!*bcp){
return offset;
}
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->info_level){
case 1:
offset = dissect_4_3_4_1(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 2:
offset = dissect_4_3_4_2(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 3:
offset = dissect_4_3_4_2(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0101:
offset = dissect_4_3_4_4(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0102:
offset = dissect_4_3_4_5(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0103:
offset = dissect_4_3_4_7(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0104:
offset = dissect_4_3_4_6(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0105:
offset = dissect_4_3_4_6full(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0106:
offset = dissect_4_3_4_6_id_both(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x0202:
offset = dissect_4_3_4_8(tvb, pinfo, tree, offset, bcp,
trunc);
break;
case 0x020B:
offset = dissect_find_file_unix_info2(tvb, pinfo, tree, offset, bcp,
trunc);
break;
default:
*trunc = FALSE;
break;
}
return offset;
}
static int
dissect_fs_attributes(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"FS Attributes: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_smb_fs_attributes);
proto_tree_add_boolean(tree, hf_smb_fs_attr_css,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_cpn,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_uod,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_pacls,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_fc,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_vq,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_ssf,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_srp,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_srs,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_sla,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_vic,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_soids,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_se,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_ns,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_fs_attr_rov,
tvb, offset, 4, mask);
}
offset += 4;
return offset;
}
static int
dissect_device_characteristics(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint32 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"Device Characteristics: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_smb_device_characteristics);
proto_tree_add_boolean(tree, hf_smb_device_char_removable,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_device_char_read_only,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_device_char_floppy,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_device_char_write_once,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_device_char_remote,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_device_char_mounted,
tvb, offset, 4, mask);
proto_tree_add_boolean(tree, hf_smb_device_char_virtual,
tvb, offset, 4, mask);
}
offset += 4;
return offset;
}
int
dissect_qfsi_FS_VOLUME_INFO(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, int offset, guint16 *bcp, int unicode)
{
int fn_len, vll;
const char *fn;
CHECK_BYTE_COUNT_TRANS_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_smb_create_time);
*bcp -= 8;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_volume_serial_num, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
vll = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_volume_label_len, tvb, offset, 4, vll);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
COUNT_BYTES_TRANS_SUBR(2);
fn_len = vll;
fn = get_unicode_or_ascii_string(tvb, &offset, unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_TRANS_SUBR(fn);
proto_tree_add_string(tree, hf_smb_volume_label, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS_SUBR(fn_len);
return offset;
}
int
dissect_qfsi_FS_SIZE_INFO(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, int offset, guint16 *bcp)
{
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_free_alloc_units64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_sector_unit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_fs_sector, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
return offset;
}
int
dissect_qfsi_FS_DEVICE_INFO(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, int offset, guint16 *bcp)
{
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_device_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
offset = dissect_device_characteristics(tvb, tree, offset);
*bcp -= 4;
return offset;
}
int
dissect_qfsi_FS_ATTRIBUTE_INFO(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, int offset, guint16 *bcp, int unicode)
{
int fn_len, fnl;
const char *fn;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
offset = dissect_fs_attributes(tvb, tree, offset);
*bcp -= 4;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_max_name_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
fnl = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_fs_name_len, tvb, offset, 4, fnl);
COUNT_BYTES_TRANS_SUBR(4);
fn_len = fnl;
fn = get_unicode_or_ascii_string(tvb, &offset, unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_TRANS_SUBR(fn);
proto_tree_add_string(tree, hf_smb_fs_name, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS_SUBR(fn_len);
return offset;
}
int
dissect_qfsi_FS_OBJECTID_INFO(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, int offset, guint16 *bcp)
{
CHECK_BYTE_COUNT_TRANS_SUBR(64);
dissect_smb2_FILE_OBJECTID_BUFFER(tvb, pinfo, tree, offset);
COUNT_BYTES_TRANS_SUBR(64);
return offset;
}
int
dissect_qfsi_FS_FULL_SIZE_INFO(tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, int offset, guint16 *bcp)
{
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_alloc_size64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_caller_free_alloc_units64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
proto_tree_add_item(tree, hf_smb_actual_free_alloc_units64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(8);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_sector_unit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_fs_sector, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
return offset;
}
static int
dissect_qfsi_vals(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
int offset, guint16 *bcp)
{
smb_info_t *si;
int fn_len, vll;
const char *fn;
guint support = 0;
proto_item *item = NULL;
proto_tree *ti = NULL;
if(!*bcp){
return offset;
}
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->info_level){
case 1:
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_fs_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_sector_unit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_fs_units, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_avail_units, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_uint(tree, hf_smb_fs_sector, tvb, offset, 2, tvb_get_letohs(tvb, offset));
COUNT_BYTES_TRANS_SUBR(2);
break;
case 2:
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_volume_serial_num, tvb, offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(1);
proto_tree_add_uint(tree, hf_smb_volume_label_len, tvb, offset, 1, tvb_get_guint8(tvb, offset));
COUNT_BYTES_TRANS_SUBR(1);
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, FALSE, bcp);
CHECK_STRING_TRANS_SUBR(fn);
proto_tree_add_string(tree, hf_smb_volume_label, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS_SUBR(fn_len);
break;
case 0x0101:
case 1002:
CHECK_BYTE_COUNT_TRANS_SUBR(4);
vll = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_smb_volume_label_len, tvb, offset, 4, vll);
COUNT_BYTES_TRANS_SUBR(4);
fn_len = vll;
fn = get_unicode_or_ascii_string(tvb, &offset, si->unicode, &fn_len, FALSE, TRUE, bcp);
CHECK_STRING_TRANS_SUBR(fn);
proto_tree_add_string(tree, hf_smb_volume_label, tvb, offset, fn_len,
fn);
COUNT_BYTES_TRANS_SUBR(fn_len);
break;
case 0x0102:
case 1001:
offset = dissect_qfsi_FS_VOLUME_INFO(tvb, pinfo, tree, offset, bcp, si->unicode);
break;
case 0x0103:
case 1003:
offset = dissect_qfsi_FS_SIZE_INFO(tvb, pinfo, tree, offset, bcp);
break;
case 0x0104:
case 1004:
offset = dissect_qfsi_FS_DEVICE_INFO(tvb, pinfo, tree, offset, bcp);
break;
case 0x0105:
case 1005:
offset = dissect_qfsi_FS_ATTRIBUTE_INFO(tvb, pinfo, tree, offset, bcp, si->unicode);
break;
case 0x200: {
proto_item *item_2 = NULL;
proto_tree *subtree = NULL;
guint32 caps_lo, caps_hi;
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_unix_major_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(2);
proto_tree_add_item(tree, hf_smb_unix_minor_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(2);
CHECK_BYTE_COUNT_TRANS_SUBR(8);
caps_lo = tvb_get_letohl(tvb, offset);
caps_hi = tvb_get_letohl(tvb, offset + 4);
if (tree) {
item_2 = proto_tree_add_text(
tree, tvb, offset, 8, "Capabilities: 0x%08x%08x",
caps_hi, caps_lo);
subtree = proto_item_add_subtree(
item_2, ett_smb_unix_capabilities);
}
proto_tree_add_boolean(
subtree, hf_smb_unix_capability_fcntl, tvb, offset, 8,
caps_lo);
proto_tree_add_boolean(
subtree, hf_smb_unix_capability_posix_acl, tvb, offset, 8,
caps_lo);
COUNT_BYTES_TRANS_SUBR(8);
break;
}
case 0x301:
CHECK_BYTE_COUNT_TRANS_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_create_time);
*bcp -= 8;
CHECK_BYTE_COUNT_TRANS_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_modify_time);
*bcp -= 8;
CHECK_BYTE_COUNT_TRANS_SUBR(8);
offset = dissect_nt_64bit_time(tvb, tree, offset, hf_smb_backup_time);
*bcp -= 8;
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_alloc_block_count, tvb,
offset,
4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_alloc_block_size, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_free_block_count, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(32);
proto_tree_add_bytes_format(tree, hf_smb_mac_fndrinfo, tvb,
offset, 32, NULL,
"Finder Info: %s",
tvb_format_text(tvb, offset, 32));
COUNT_BYTES_TRANS_SUBR(32);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_root_file_count, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_root_dir_count, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_file_count, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
proto_tree_add_item(tree, hf_smb_mac_dir_count, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
COUNT_BYTES_TRANS_SUBR(4);
CHECK_BYTE_COUNT_TRANS_SUBR(4);
support = tvb_get_letohl(tvb, offset);
item = proto_tree_add_text(tree, tvb, offset, 4,
"Mac Support Flags: 0x%08x", support);
ti = proto_item_add_subtree(item, ett_smb_mac_support_flags);
proto_tree_add_boolean(ti, hf_smb_mac_sup_access_ctrl,
tvb, offset, 4, support);
proto_tree_add_boolean(ti, hf_smb_mac_sup_getset_comments,
tvb, offset, 4, support);
proto_tree_add_boolean(ti, hf_smb_mac_sup_desktopdb_calls,
tvb, offset, 4, support);
proto_tree_add_boolean(ti, hf_smb_mac_sup_unique_ids,
tvb, offset, 4, support);
proto_tree_add_boolean(ti, hf_smb_mac_sup_streams,
tvb, offset, 4, support);
COUNT_BYTES_TRANS_SUBR(4);
break;
case 1006:
offset = dissect_nt_quota(tvb, tree, offset, bcp);
break;
case 1007:
offset = dissect_qfsi_FS_FULL_SIZE_INFO(tvb, pinfo, tree, offset, bcp);
break;
case 1008: {
offset = dissect_qfsi_FS_OBJECTID_INFO(tvb, pinfo, tree, offset, bcp);
break;
}
}
return offset;
}
static int
dissect_transaction2_response_data(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent_tree)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
int count;
gboolean trunc;
int offset = 0;
guint16 dc;
dc = tvb_reported_length(tvb);
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I)
t2i = si->sip->extra_info;
else
t2i = NULL;
if(parent_tree){
if (t2i != NULL && t2i->subcmd != -1) {
item = proto_tree_add_text(parent_tree, tvb, offset, dc,
"%s Data",
val_to_str_ext(t2i->subcmd, &trans2_cmd_vals_ext,
"Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_transaction_data);
} else {
proto_tree_add_text(parent_tree, tvb, offset, dc,
"Unknown Transaction2 Data");
}
}
if (t2i == NULL) {
offset += dc;
return offset;
}
switch(t2i->subcmd){
case 0x0000:
break;
case 0x0001:
count = si->info_count;
if(count == -1) {
break;
}
if (count && check_col(pinfo->cinfo, COL_INFO)) {
col_append_str(pinfo->cinfo, COL_INFO,
", Files:");
}
while(count--){
offset = dissect_ff2_response_data(tvb, pinfo, tree,
offset, &dc, &trunc);
if (trunc)
break;
}
break;
case 0x0002:
count = si->info_count;
if(count == -1) {
break;
}
if (count && check_col(pinfo->cinfo, COL_INFO)) {
col_append_str(pinfo->cinfo, COL_INFO,
", Files:");
}
while(count--){
offset = dissect_ff2_response_data(tvb, pinfo, tree,
offset, &dc, &trunc);
if (trunc)
break;
}
break;
case 0x0003:
offset = dissect_qfsi_vals(tvb, pinfo, tree, offset, &dc);
break;
case 0x0004:
offset = dissect_sfsi_response(tvb, pinfo, tree, offset, &dc);
break;
case 0x0005:
offset = dissect_qpi_loi_vals(tvb, pinfo, tree, item, offset, &dc);
break;
case 0x0006:
break;
case 0x0007:
offset = dissect_qpi_loi_vals(tvb, pinfo, tree, item, offset, &dc);
break;
case 0x0008:
break;
case 0x0009:
break;
case 0x000a:
break;
case 0x000b:
break;
case 0x000c:
break;
case 0x000d:
break;
case 0x000e:
break;
case 0x0010:
offset = dissect_get_dfs_referral_data(tvb, pinfo, tree, offset, &dc);
break;
case 0x0011:
break;
case -1:
offset += dc;
dc = 0;
break;
}
if(dc != 0){
proto_tree_add_item(tree, hf_smb_unknown, tvb, offset, dc, ENC_NA);
offset += dc;
}
return offset;
}
static int
dissect_transaction2_response_parameters(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
smb_info_t *si;
smb_transact2_info_t *t2i;
guint16 fid;
int lno;
int offset = 0;
int pc;
pc = tvb_reported_length(tvb);
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I)
t2i = si->sip->extra_info;
else
t2i = NULL;
if(parent_tree){
if (t2i != NULL && t2i->subcmd != -1) {
item = proto_tree_add_text(parent_tree, tvb, offset, pc,
"%s Parameters",
val_to_str_ext(t2i->subcmd, &trans2_cmd_vals_ext,
"Unknown (0x%02x)"));
tree = proto_item_add_subtree(item, ett_smb_transaction_params);
} else {
proto_tree_add_text(parent_tree, tvb, offset, pc,
"Unknown Transaction2 Parameters");
}
}
if (t2i == NULL) {
offset += pc;
return offset;
}
switch(t2i->subcmd){
case 0x00:
fid = tvb_get_letohs(tvb, offset);
dissect_smb_fid(tvb, pinfo, tree, offset, 2, fid, TRUE, FALSE, FALSE);
offset += 2;
offset = dissect_file_attributes(tvb, tree, offset);
offset = dissect_smb_datetime(tvb, tree, offset,
hf_smb_create_time,
hf_smb_create_dos_date, hf_smb_create_dos_time, TRUE);
proto_tree_add_item(tree, hf_smb_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_access(tvb, tree, offset, "Granted");
proto_tree_add_item(tree, hf_smb_file_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_ipc_state(tvb, tree, offset, FALSE);
offset = dissect_open_action(tvb, tree, offset);
proto_tree_add_item(tree, hf_smb_file_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_item(tree, hf_smb_ea_list_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case 0x01:
proto_tree_add_uint(tree, hf_smb_ff2_information_level, tvb, 0, 0, si->info_level);
proto_tree_add_item(tree, hf_smb_search_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
si->info_count = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_search_count, tvb, offset, 2, si->info_count);
offset += 2;
proto_tree_add_item(tree, hf_smb_end_of_search, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
lno = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_last_name_offset, tvb, offset, 2, lno);
offset += 2;
break;
case 0x02:
si->info_count = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_search_count, tvb, offset, 2, si->info_count);
offset += 2;
proto_tree_add_item(tree, hf_smb_end_of_search, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
lno = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_last_name_offset, tvb, offset, 2, lno);
offset += 2;
break;
case 0x03:
break;
case 0x05:
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x06:
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x07:
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x08:
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x09:
break;
case 0x0a:
break;
case 0x0b:
proto_tree_add_uint(tree, hf_smb_fn_information_level, tvb, 0, 0, si->info_level);
proto_tree_add_item(tree, hf_smb_monitor_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
si->info_count = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_change_count, tvb, offset, 2, si->info_count);
offset += 2;
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x0c:
proto_tree_add_uint(tree, hf_smb_fn_information_level, tvb, 0, 0, si->info_level);
si->info_count = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_change_count, tvb, offset, 2, si->info_count);
offset += 2;
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x0d:
proto_tree_add_uint(tree, hf_smb_ea_error_offset, tvb, offset, 2, tvb_get_letohs(tvb, offset));
offset += 2;
break;
case 0x0e:
break;
case 0x10:
break;
case 0x11:
break;
case -1:
offset += pc;
break;
}
if(offset<pc){
proto_tree_add_item(tree, hf_smb_unknown, tvb, offset, pc-offset, ENC_NA);
offset += pc-offset;
}
return offset;
}
static int
dissect_transaction_response(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 sc, wc;
guint16 od=0, po=0, pc=0, pd=0, dc=0, dd=0, td=0, tp=0;
smb_info_t *si;
smb_transact2_info_t *t2i = NULL;
guint16 bc;
int padcnt;
gboolean dissected_trans;
fragment_data *r_fd = NULL;
tvbuff_t *pd_tvb=NULL, *d_tvb=NULL, *p_tvb=NULL;
tvbuff_t *s_tvb=NULL, *sp_tvb=NULL;
gboolean save_fragmented;
proto_item *item;
si = (smb_info_t *)pinfo->private_data;
DISSECTOR_ASSERT(si);
switch(si->cmd){
case SMB_COM_TRANSACTION2:
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_T2I) {
t2i = si->sip->extra_info;
} else
t2i = NULL;
if (t2i == NULL) {
proto_tree_add_text(tree, tvb, 0, 0,
"Subcommand: <UNKNOWN> since request packet wasn't seen");
col_append_str(pinfo->cinfo, COL_INFO, "<unknown>");
} else {
si->info_level = t2i->info_level;
if (t2i->subcmd == -1) {
proto_tree_add_text(tree, tvb, 0, 0,
"Subcommand: <UNKNOWN> since transaction code wasn't found in request packet");
col_append_str(pinfo->cinfo, COL_INFO, "<unknown>");
} else {
proto_tree_add_uint(tree, hf_smb_trans2_subcmd, tvb, 0, 0, t2i->subcmd);
switch (t2i->subcmd) {
case 0x0001:
if (t2i->info_level == -1)
item=proto_tree_add_text(tree, tvb, 0, 0, "Level of Information: <UNKNOWN> since information level wasn't found in request packet");
else
item=proto_tree_add_uint(tree, hf_smb_ff2_information_level, tvb, 0, 0, t2i->info_level);
PROTO_ITEM_SET_GENERATED(item);
if(t2i->name){
item=proto_tree_add_string(tree, hf_smb_search_pattern, tvb, 0, 0, t2i->name);
PROTO_ITEM_SET_GENERATED(item);
}
break;
case 0x0005:
if (t2i->info_level == -1)
item=proto_tree_add_text(tree, tvb, 0, 0, "Level of Information: <UNKNOWN> since information level wasn't found in request packet");
else
item=proto_tree_add_uint(tree, hf_smb_qpi_loi, tvb, 0, 0, t2i->info_level);
PROTO_ITEM_SET_GENERATED(item);
if(t2i->name){
item=proto_tree_add_string(tree, hf_smb_file_name, tvb, 0, 0, t2i->name);
PROTO_ITEM_SET_GENERATED(item);
}
break;
case 0x0007:
if (t2i->info_level == -1)
item=proto_tree_add_text(tree, tvb, 0, 0, "Level of Information: <UNKNOWN> since information level wasn't found in request packet");
else
item=proto_tree_add_uint(tree, hf_smb_qpi_loi, tvb, 0, 0, t2i->info_level);
PROTO_ITEM_SET_GENERATED(item);
break;
case 0x0003:
if (t2i->info_level == -1)
item=proto_tree_add_text(tree, tvb, 0, 0, "Level of Information: <UNKNOWN> since information level wasn't found in request packet");
else
item=proto_tree_add_uint(tree, hf_smb_qfsi_information_level, tvb, 0, 0, si->info_level);
PROTO_ITEM_SET_GENERATED(item);
break;
case 0x0004:
if (t2i->info_level == -1)
item=proto_tree_add_text(tree, tvb, 0, 0, "Level of Information: <UNKNOWN> since information level wasn't found in request packet");
else
item=proto_tree_add_uint(tree, hf_smb_sfsi_information_level, tvb, 0, 0, si->info_level);
PROTO_ITEM_SET_GENERATED(item);
break;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(t2i->subcmd,
&trans2_cmd_vals_ext,
"<unknown (0x%02x)>"));
}
}
}
break;
}
WORD_COUNT;
tp = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_total_param_count, tvb, offset, 2, tp);
offset += 2;
td = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_total_data_count, tvb, offset, 2, td);
offset += 2;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
pc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_count16, tvb, offset, 2, pc);
offset += 2;
po = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_offset16, tvb, offset, 2, po);
offset += 2;
pd = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_param_disp16, tvb, offset, 2, pd);
offset += 2;
dc = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_count16, tvb, offset, 2, dc);
offset += 2;
od = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_offset16, tvb, offset, 2, od);
offset += 2;
dd = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_smb_data_disp16, tvb, offset, 2, dd);
offset += 2;
sc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smb_setup_count, tvb, offset, 1, sc);
offset += 1;
proto_tree_add_item(tree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
if(sc){
if((2*sc)>tvb_length_remaining(tvb, offset)){
s_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), 2*sc);
} else {
s_tvb = tvb_new_subset(tvb, offset, 2*sc, 2*sc);
}
sp_tvb = tvb_new_subset_remaining(tvb, offset);
} else {
s_tvb = NULL;
sp_tvb=NULL;
}
offset += 2*sc;
BYTE_COUNT;
save_fragmented = pinfo->fragmented;
if( (td!=dc) || (tp!=pc) ){
pinfo->fragmented = TRUE;
if(smb_trans_reassembly){
if(pc && (tvb_length_remaining(tvb, po)>=pc) ){
r_fd = smb_trans_defragment(tree, pinfo, tvb,
po, pc, pd, td+tp);
}
if((r_fd==NULL) && dc && (tvb_length_remaining(tvb, od)>=dc) ){
r_fd = smb_trans_defragment(tree, pinfo, tvb,
od, dc, dd+tp, td+tp);
}
}
}
if(r_fd){
proto_item *frag_tree_item;
pd_tvb = tvb_new_child_real_data(tvb, r_fd->data, r_fd->datalen,
r_fd->datalen);
add_new_data_source(pinfo, pd_tvb, "Reassembled SMB");
show_fragment_tree(r_fd, &smb_frag_items, tree, pinfo, pd_tvb, &frag_tree_item);
}
if(pd_tvb){
if(tp){
p_tvb = tvb_new_subset(pd_tvb, 0, tp, tp);
}
if(td){
d_tvb = tvb_new_subset(pd_tvb, tp, td, td);
}
} else {
if( (pd==0) && (dd==0) ){
int min;
int reported_min;
min = MIN(pc,tvb_length_remaining(tvb,po));
reported_min = MIN(pc,tvb_reported_length_remaining(tvb,po));
if(min && reported_min) {
p_tvb = tvb_new_subset(tvb, po, min, reported_min);
}
min = MIN(dc,tvb_length_remaining(tvb,od));
reported_min = MIN(dc,tvb_reported_length_remaining(tvb,od));
if(min && reported_min) {
d_tvb = tvb_new_subset(tvb, od, min, reported_min);
}
if (tvb_length_remaining(tvb, po)){
pd_tvb = tvb_new_subset_remaining(tvb, po);
}
}
}
if(po>offset){
padcnt = po-offset;
if (padcnt > bc)
padcnt = bc;
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if(si->cmd==SMB_COM_TRANSACTION2 && p_tvb){
dissect_transaction2_response_parameters(p_tvb, pinfo, tree);
}
COUNT_BYTES(pc);
if(od>offset){
padcnt = od-offset;
if (padcnt > bc)
padcnt = bc;
proto_tree_add_item(tree, hf_smb_padding, tvb, offset, padcnt, ENC_NA);
COUNT_BYTES(padcnt);
}
if (dc > bc)
dc = bc;
COUNT_BYTES(dc);
if(si->cmd==SMB_COM_TRANSACTION2 && d_tvb){
dissect_transaction2_response_data(d_tvb, pinfo, tree);
}
if(si->cmd==SMB_COM_TRANSACTION){
smb_transact_info_t *tri;
dissected_trans = FALSE;
if (si->sip != NULL && si->sip->extra_info_type == SMB_EI_TRI)
tri = si->sip->extra_info;
else
tri = NULL;
if (tri != NULL) {
switch(tri->subcmd){
case TRANSACTION_PIPE:
if( pd_tvb) {
dissected_trans = dissect_pipe_smb(
sp_tvb, s_tvb, pd_tvb, p_tvb,
d_tvb, NULL, pinfo, top_tree_global);
}
break;
case TRANSACTION_MAILSLOT:
if(d_tvb){
dissected_trans = dissect_mailslot_smb(
sp_tvb, s_tvb, d_tvb, NULL, pinfo,
top_tree_global);
}
break;
}
}
if (!dissected_trans) {
dissect_trans_data(s_tvb, p_tvb, d_tvb, tree);
}
}
if( (p_tvb==0) && (d_tvb==0) ){
col_append_str(pinfo->cinfo, COL_INFO,
"[transact continuation]");
}
pinfo->fragmented = save_fragmented;
END_OF_SMB
return offset;
}
static int
dissect_find_notify_close(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
proto_tree_add_item(tree, hf_smb_monitor_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
BYTE_COUNT;
END_OF_SMB
return offset;
}
static int
dissect_unknown(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, proto_tree *smb_tree _U_)
{
guint8 wc;
guint16 bc;
WORD_COUNT;
if (wc != 0) {
tvb_ensure_bytes_exist(tvb, offset, wc*2);
proto_tree_add_text(tree, tvb, offset, wc*2, "Word parameters");
offset += wc*2;
}
BYTE_COUNT;
if (bc != 0) {
tvb_ensure_bytes_exist(tvb, offset, bc);
proto_tree_add_text(tree, tvb, offset, bc, "Byte parameters");
offset += bc;
bc = 0;
}
END_OF_SMB
return offset;
}
static int
dissect_smb_command(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *smb_tree, guint8 cmd, gboolean first_pdu)
{
smb_info_t *si;
smb_saved_info_t *sip;
si = pinfo->private_data;
DISSECTOR_ASSERT(si);
if(cmd!=0xff){
proto_item *cmd_item;
proto_tree *cmd_tree;
int (*dissector)(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, proto_tree *smb_tree);
if (check_col(pinfo->cinfo, COL_INFO)) {
if(first_pdu){
col_append_fstr(pinfo->cinfo, COL_INFO,
"%s %s",
decode_smb_name(cmd),
(si->request)? "Request" : "Response");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO,
"; %s",
decode_smb_name(cmd));
}
}
cmd_item = proto_tree_add_text(smb_tree, tvb, offset, -1,
"%s %s (0x%02x)",
decode_smb_name(cmd),
(si->request)?"Request":"Response",
cmd);
cmd_tree = proto_item_add_subtree(cmd_item, ett_smb_command);
sip = si->sip;
if (sip && sip->fid) {
if( (si->request && (!sip->fid_seen_in_request))
||((!si->request) && sip->fid_seen_in_request) ){
dissect_smb_fid(tvb, pinfo, cmd_tree, offset, 0, sip->fid, FALSE, FALSE, TRUE);
}
}
dissector = (si->request)?
smb_dissector[cmd].request:smb_dissector[cmd].response;
offset = (*dissector)(tvb, pinfo, cmd_tree, offset, smb_tree);
proto_item_set_end(cmd_item, tvb, offset);
}
return offset;
}
static const char *decode_smb_name(guint8 cmd)
{
return(smb_cmd_vals[cmd].strptr);
}
static void
free_hash_tables(gpointer ctarg, gpointer user_data _U_)
{
conv_tables_t *ct = ctarg;
if (ct->unmatched)
g_hash_table_destroy(ct->unmatched);
if (ct->matched)
g_hash_table_destroy(ct->matched);
if (ct->tid_service)
g_hash_table_destroy(ct->tid_service);
g_free(ct);
}
static void
smb_init_protocol(void)
{
if (conv_tables) {
g_slist_foreach(conv_tables, free_hash_tables, NULL);
g_slist_free(conv_tables);
conv_tables = NULL;
}
}
static const char *decode_smb_error(guint8 errcls, guint16 errcode)
{
switch (errcls) {
case SMB_SUCCESS:
return("No Error");
case SMB_ERRDOS:
return(val_to_str(errcode, DOS_errors, "Unknown DOS error (%x)"));
case SMB_ERRSRV:
return(val_to_str(errcode, SRV_errors, "Unknown SRV error (%x)"));
case SMB_ERRHRD:
return(val_to_str(errcode, HRD_errors, "Unknown HRD error (%x)"));
default:
return("Unknown error class!");
}
}
static int
dissect_smb_flags(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint8 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_guint8(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"Flags: 0x%02x", mask);
tree = proto_item_add_subtree(item, ett_smb_flags);
proto_tree_add_boolean(tree, hf_smb_flags_response,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_flags_notify,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_flags_oplock,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_flags_canon,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_flags_caseless,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_flags_receive_buffer,
tvb, offset, 1, mask);
proto_tree_add_boolean(tree, hf_smb_flags_lock,
tvb, offset, 1, mask);
}
offset += 1;
return offset;
}
static int
dissect_smb_flags2(tvbuff_t *tvb, proto_tree *parent_tree, int offset)
{
guint16 mask;
proto_item *item;
proto_tree *tree;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Flags2: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_smb_flags2);
proto_tree_add_boolean(tree, hf_smb_flags2_string,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_nt_error,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_roe,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_dfs,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_esn,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_reparse_path,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_long_names_used,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_sec_sig_required,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_compressed,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_sec_sig,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_ea,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_smb_flags2_long_names_allowed,
tvb, offset, 2, mask);
}
offset += 2;
return offset;
}
static void
dissect_smb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
proto_item *item = NULL, *hitem = NULL;
proto_tree *tree = NULL, *htree = NULL;
proto_item *tmp_item=NULL;
guint8 flags;
guint16 flags2;
smb_info_t *si;
smb_saved_info_t *sip = NULL;
smb_saved_info_key_t key;
smb_saved_info_key_t *new_key;
guint8 errclass = 0;
guint16 errcode = 0;
guint32 pid_mid;
conversation_t *conversation;
nstime_t t, deltat;
si=ep_alloc0(sizeof(smb_info_t));
top_tree_global=parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMB");
col_clear(pinfo->cinfo, COL_INFO);
si->cmd = tvb_get_guint8(tvb, offset+4);
flags = tvb_get_guint8(tvb, offset+9);
si->request = !(flags&SMB_FLAGS_DIRN);
flags2 = tvb_get_letohs(tvb, offset+10);
if(flags2 & 0x8000){
si->unicode = TRUE;
} else {
si->unicode = FALSE;
}
si->tid = tvb_get_letohs(tvb, offset+24);
si->pid = tvb_get_letohs(tvb, offset+26);
si->uid = tvb_get_letohs(tvb, offset+28);
si->mid = tvb_get_letohs(tvb, offset+30);
pid_mid = (si->pid << 16) | si->mid;
si->info_level = -1;
si->info_count = -1;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, proto_smb, tvb, offset,
-1, ENC_NA);
tree = proto_item_add_subtree(item, ett_smb);
hitem = proto_tree_add_text(tree, tvb, offset, 32,
"SMB Header");
htree = proto_item_add_subtree(hitem, ett_smb_hdr);
}
proto_tree_add_text(htree, tvb, offset, 4, "Server Component: SMB");
offset += 4;
conversation = find_or_create_conversation(pinfo);
si->ct=conversation_get_proto_data(conversation, proto_smb);
if(!si->ct){
si->ct = g_malloc(sizeof(conv_tables_t));
conv_tables = g_slist_prepend(conv_tables, si->ct);
si->ct->matched= g_hash_table_new(smb_saved_info_hash_matched,
smb_saved_info_equal_matched);
si->ct->unmatched= g_hash_table_new(smb_saved_info_hash_unmatched,
smb_saved_info_equal_unmatched);
si->ct->tid_service=g_hash_table_new(
smb_saved_info_hash_unmatched,
smb_saved_info_equal_unmatched);
si->ct->raw_ntlmssp = 0;
si->ct->fid_tree=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "SMB fid_tree");
si->ct->tid_tree=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "SMB tid_tree");
si->ct->uid_tree=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "SMB uid_tree");
si->ct->GSL_fid_info=NULL;
conversation_add_proto_data(conversation, proto_smb, si->ct);
}
if( (si->request)
&& (si->mid==0)
&& (si->uid==0)
&& (si->pid==0)
&& (si->tid==0) ){
si->unidir = TRUE;
} else if( (si->cmd==SMB_COM_NT_CANCEL)
||(si->cmd==SMB_COM_TRANSACTION_SECONDARY)
||(si->cmd==SMB_COM_TRANSACTION2_SECONDARY)
||(si->cmd==SMB_COM_NT_TRANSACT_SECONDARY)){
si->unidir = TRUE;
if(!pinfo->fd->flags.visited){
sip=g_hash_table_lookup(si->ct->unmatched, GUINT_TO_POINTER(pid_mid));
if(sip!=NULL){
new_key = se_alloc(sizeof(smb_saved_info_key_t));
new_key->frame = pinfo->fd->num;
new_key->pid_mid = pid_mid;
g_hash_table_insert(si->ct->matched, new_key,
sip);
}
} else {
key.frame = pinfo->fd->num;
key.pid_mid = pid_mid;
sip=g_hash_table_lookup(si->ct->matched, &key);
if(sip==NULL){
}
}
if(sip && sip->frame_req){
switch(si->cmd){
case SMB_COM_NT_CANCEL:
tmp_item=proto_tree_add_uint(htree, hf_smb_cancel_to,
tvb, 0, 0, sip->frame_req);
PROTO_ITEM_SET_GENERATED(tmp_item);
break;
case SMB_COM_TRANSACTION_SECONDARY:
case SMB_COM_TRANSACTION2_SECONDARY:
case SMB_COM_NT_TRANSACT_SECONDARY:
tmp_item=proto_tree_add_uint(htree, hf_smb_continuation_to,
tvb, 0, 0, sip->frame_req);
PROTO_ITEM_SET_GENERATED(tmp_item);
break;
}
} else {
switch(si->cmd){
case SMB_COM_NT_CANCEL:
proto_tree_add_text(htree, tvb, 0, 0,
"Cancellation to: <unknown frame>");
break;
case SMB_COM_TRANSACTION_SECONDARY:
case SMB_COM_TRANSACTION2_SECONDARY:
case SMB_COM_NT_TRANSACT_SECONDARY:
proto_tree_add_text(htree, tvb, 0, 0,
"Continuation to: <unknown frame>");
break;
}
}
} else {
si->unidir = FALSE;
if(!pinfo->fd->flags.visited){
sip=g_hash_table_lookup(si->ct->unmatched, GUINT_TO_POINTER(pid_mid));
if(sip!=NULL){
gboolean cmd_match=FALSE;
if(si->cmd==sip->cmd){
cmd_match=TRUE;
}
else if(si->cmd==SMB_COM_NT_CANCEL){
cmd_match=TRUE;
}
else if((si->cmd==SMB_COM_TRANSACTION_SECONDARY)
&& (sip->cmd==SMB_COM_TRANSACTION)){
cmd_match=TRUE;
}
else if((si->cmd==SMB_COM_TRANSACTION2_SECONDARY)
&& (sip->cmd==SMB_COM_TRANSACTION2)){
cmd_match=TRUE;
}
else if((si->cmd==SMB_COM_NT_TRANSACT_SECONDARY)
&& (sip->cmd==SMB_COM_NT_TRANSACT)){
cmd_match=TRUE;
}
if( (si->request) || (!cmd_match) ) {
g_hash_table_remove(si->ct->unmatched, GUINT_TO_POINTER(pid_mid));
sip=NULL;
} else {
if(sip->frame_res==0 ||
sip->flags & SMB_SIF_IS_CONTINUED){
sip->frame_res = pinfo->fd->num;
new_key = se_alloc(sizeof(smb_saved_info_key_t));
new_key->frame = sip->frame_res;
new_key->pid_mid = pid_mid;
g_hash_table_insert(si->ct->matched, new_key, sip);
g_hash_table_remove(si->ct->unmatched, GUINT_TO_POINTER(pid_mid));
} else {
sip=NULL;
}
}
}
if(si->request){
sip = se_alloc(sizeof(smb_saved_info_t));
sip->frame_req = pinfo->fd->num;
sip->frame_res = 0;
sip->req_time = pinfo->fd->abs_ts;
sip->flags = 0;
if(g_hash_table_lookup(si->ct->tid_service, GUINT_TO_POINTER(si->tid))
== (void *)TID_IPC) {
sip->flags |= SMB_SIF_TID_IS_IPC;
}
sip->cmd = si->cmd;
sip->extra_info = NULL;
sip->extra_info_type = SMB_EI_NONE;
sip->fid=0;
sip->fid_seen_in_request=0;
g_hash_table_insert(si->ct->unmatched, GUINT_TO_POINTER(pid_mid), sip);
new_key = se_alloc(sizeof(smb_saved_info_key_t));
new_key->frame = sip->frame_req;
new_key->pid_mid = pid_mid;
g_hash_table_insert(si->ct->matched, new_key, sip);
}
} else {
key.frame = pinfo->fd->num;
key.pid_mid = pid_mid;
sip=g_hash_table_lookup(si->ct->matched, &key);
}
}
si->sip = sip;
if (sip != NULL) {
if(si->request){
if (sip->frame_res != 0) {
tmp_item=proto_tree_add_uint(htree, hf_smb_response_in, tvb, 0, 0, sip->frame_res);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
} else {
if (sip->frame_req != 0) {
tmp_item=proto_tree_add_uint(htree, hf_smb_response_to, tvb, 0, 0, sip->frame_req);
PROTO_ITEM_SET_GENERATED(tmp_item);
t = pinfo->fd->abs_ts;
nstime_delta(&deltat, &t, &sip->req_time);
tmp_item=proto_tree_add_time(htree, hf_smb_time, tvb,
0, 0, &deltat);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
}
proto_tree_add_uint_format(htree, hf_smb_cmd, tvb, offset, 1, si->cmd, "SMB Command: %s (0x%02x)", decode_smb_name(si->cmd), si->cmd);
offset += 1;
if(flags2 & 0x4000){
si->nt_status = tvb_get_letohl(tvb, offset);
proto_tree_add_item(htree, hf_smb_nt_status, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
} else {
errclass = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(htree, hf_smb_error_class, tvb, offset, 1,
errclass);
offset += 1;
proto_tree_add_item(htree, hf_smb_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
errcode = tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(htree, hf_smb_error_code, tvb,
offset, 2, errcode, "Error Code: %s",
decode_smb_error(errclass, errcode));
offset += 2;
}
offset = dissect_smb_flags(tvb, htree, offset);
offset = dissect_smb_flags2(tvb, htree, offset);
proto_tree_add_item(htree, hf_smb_pid_high, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (pinfo->ptype == PT_IPX &&
(pinfo->match_uint == IPX_SOCKET_NWLINK_SMB_SERVER ||
pinfo->match_uint == IPX_SOCKET_NWLINK_SMB_REDIR ||
pinfo->match_uint == IPX_SOCKET_NWLINK_SMB_MESSENGER)) {
proto_tree_add_item(htree, hf_smb_key, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(htree, hf_smb_session_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(htree, hf_smb_sequence_num, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(htree, hf_smb_group_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
} else {
proto_tree_add_item(htree, hf_smb_sig, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(htree, hf_smb_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
}
pinfo->private_data = si;
if(!pinfo->fd->flags.visited && si->cmd==0x75 && !si->request){
offset=dissect_smb_tid(tvb, pinfo, htree, offset, (guint16)si->tid, TRUE, FALSE);
} else {
offset=dissect_smb_tid(tvb, pinfo, htree, offset, (guint16)si->tid, FALSE, FALSE);
}
proto_tree_add_uint(htree, hf_smb_pid, tvb, offset, 2, si->pid);
offset += 2;
offset=dissect_smb_uid(tvb, htree, offset, si);
proto_tree_add_uint(htree, hf_smb_mid, tvb, offset, 2, si->mid);
offset += 2;
tap_queue_packet(smb_tap, pinfo, si);
dissect_smb_command(tvb, pinfo, offset, tree, si->cmd, TRUE);
if (!si->request && check_col(pinfo->cinfo, COL_INFO)) {
if (flags2 & 0x4000) {
if ((si->nt_status & 0xC0000000) == 0xC0000000) {
col_append_fstr(
pinfo->cinfo, COL_INFO, ", Error: %s",
val_to_str(si->nt_status, NT_errors,
"Unknown (0x%08X)"));
}
} else {
if (errclass != SMB_SUCCESS) {
col_append_fstr(
pinfo->cinfo, COL_INFO, ", Error: %s",
decode_smb_error(errclass, errcode));
}
}
}
}
static gboolean
dissect_smb_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
if (tvb_length(tvb) < 4)
return FALSE;
if( (tvb_get_guint8(tvb, 0) != 0xff)
|| (tvb_get_guint8(tvb, 1) != 'S')
|| (tvb_get_guint8(tvb, 2) != 'M')
|| (tvb_get_guint8(tvb, 3) != 'B') ){
return FALSE;
}
dissect_smb(tvb, pinfo, parent_tree);
return TRUE;
}
void
proto_register_smb(void)
{
static hf_register_info hf[] = {
{ &hf_smb_cmd,
{ "SMB Command", "smb.cmd", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&smb_cmd_vals_ext, 0x0, NULL, HFILL }},
{ &hf_smb_trans2_subcmd,
{ "Subcommand", "smb.trans2.cmd", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&trans2_cmd_vals_ext, 0, "Subcommand for TRANSACTION2", HFILL }},
{ &hf_smb_nt_trans_subcmd,
{ "Function", "smb.nt.function", FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&nt_cmd_vals_ext, 0, "Function for NT Transaction", HFILL }},
{ &hf_smb_word_count,
{ "Word Count (WCT)", "smb.wct", FT_UINT8, BASE_DEC,
NULL, 0x0, "Word Count, count of parameter words", HFILL }},
{ &hf_smb_byte_count,
{ "Byte Count (BCC)", "smb.bcc", FT_UINT16, BASE_DEC,
NULL, 0x0, "Byte Count, count of data bytes", HFILL }},
{ &hf_smb_response_to,
{ "Response to", "smb.response_to", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This packet is a response to the packet in this frame", HFILL }},
{ &hf_smb_time,
{ "Time from request", "smb.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time between Request and Response for SMB cmds", HFILL }},
{ &hf_smb_response_in,
{ "Response in", "smb.response_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, "The response to this packet is in this packet", HFILL }},
{ &hf_smb_continuation_to,
{ "Continuation to", "smb.continuation_to", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This packet is a continuation to the packet in this frame", HFILL }},
{ &hf_smb_nt_status,
{ "NT Status", "smb.nt_status", FT_UINT32, BASE_HEX,
VALS(NT_errors), 0, "NT Status code", HFILL }},
{ &hf_smb_error_class,
{ "Error Class", "smb.error_class", FT_UINT8, BASE_HEX,
VALS(errcls_types), 0, "DOS Error Class", HFILL }},
{ &hf_smb_error_code,
{ "Error Code", "smb.error_code", FT_UINT16, BASE_HEX,
NULL, 0, "DOS Error Code", HFILL }},
{ &hf_smb_reserved,
{ "Reserved", "smb.reserved", FT_BYTES, BASE_NONE,
NULL, 0, "Reserved bytes, must be zero", HFILL }},
{ &hf_smb_sig,
{ "Signature", "smb.signature", FT_BYTES, BASE_NONE,
NULL, 0, "Signature bytes", HFILL }},
{ &hf_smb_key,
{ "Key", "smb.key", FT_UINT32, BASE_HEX,
NULL, 0, "SMB-over-IPX Key", HFILL }},
{ &hf_smb_session_id,
{ "Session ID", "smb.sessid", FT_UINT16, BASE_DEC,
NULL, 0, "SMB-over-IPX Session ID", HFILL }},
{ &hf_smb_sequence_num,
{ "Sequence Number", "smb.sequence_num", FT_UINT16, BASE_DEC,
NULL, 0, "SMB-over-IPX Sequence Number", HFILL }},
{ &hf_smb_group_id,
{ "Group ID", "smb.group_id", FT_UINT16, BASE_DEC,
NULL, 0, "SMB-over-IPX Group ID", HFILL }},
{ &hf_smb_pid,
{ "Process ID", "smb.pid", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_pid_high,
{ "Process ID High", "smb.pid.high", FT_UINT16, BASE_DEC,
NULL, 0, "Process ID High Bytes", HFILL }},
{ &hf_smb_tid,
{ "Tree ID", "smb.tid", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_uid,
{ "User ID", "smb.uid", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_mid,
{ "Multiplex ID", "smb.mid", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_flags_lock,
{ "Lock and Read", "smb.flags.lock", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_lock), 0x01, "Are Lock&Read and Write&Unlock operations supported?", HFILL }},
{ &hf_smb_flags_receive_buffer,
{ "Receive Buffer Posted", "smb.flags.receive_buffer", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_receive_buffer), 0x02, "Have receive buffers been reported?", HFILL }},
{ &hf_smb_flags_caseless,
{ "Case Sensitivity", "smb.flags.caseless", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_caseless), 0x08, "Are pathnames caseless or casesensitive?", HFILL }},
{ &hf_smb_flags_canon,
{ "Canonicalized Pathnames", "smb.flags.canon", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_canon), 0x10, "Are pathnames canonicalized?", HFILL }},
{ &hf_smb_flags_oplock,
{ "Oplocks", "smb.flags.oplock", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_oplock), 0x20, "Is an oplock requested/granted?", HFILL }},
{ &hf_smb_flags_notify,
{ "Notify", "smb.flags.notify", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_notify), 0x40, "Notify on open or all?", HFILL }},
{ &hf_smb_flags_response,
{ "Request/Response", "smb.flags.response", FT_BOOLEAN, 8,
TFS(&tfs_smb_flags_response), 0x80, "Is this a request or a response?", HFILL }},
{ &hf_smb_flags2_long_names_allowed,
{ "Long Names Allowed", "smb.flags2.long_names_allowed", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_long_names_allowed), 0x0001, "Are long file names allowed in the response?", HFILL }},
{ &hf_smb_flags2_ea,
{ "Extended Attributes", "smb.flags2.ea", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_ea), 0x0002, "Are extended attributes supported?", HFILL }},
{ &hf_smb_flags2_sec_sig,
{ "Security Signatures", "smb.flags2.sec_sig", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_sec_sig), 0x0004, "Are security signatures supported?", HFILL }},
{ &hf_smb_flags2_compressed,
{ "Compressed", "smb.flags2.compressed", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_compressed), 0x0008, "Is compression requested?", HFILL }},
{ &hf_smb_flags2_sec_sig_required,
{ "Security Signatures Required", "smb.flags2.sec_sig_required", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_sec_sig_required), 0x0010, "Are security signatures required?", HFILL }},
{ &hf_smb_flags2_long_names_used,
{ "Long Names Used", "smb.flags2.long_names_used", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_long_names_used), 0x0040, "Are pathnames in this request long file names?", HFILL }},
{ &hf_smb_flags2_reparse_path,
{ "Reparse Path", "smb.flags2.reparse_path", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_reparse_path), 0x0400, "The request uses a @GMT reparse path", HFILL }},
{ &hf_smb_flags2_esn,
{ "Extended Security Negotiation", "smb.flags2.esn", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_esn), 0x0800, "Is extended security negotiation supported?", HFILL }},
{ &hf_smb_flags2_dfs,
{ "Dfs", "smb.flags2.dfs", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_dfs), 0x1000, "Can pathnames be resolved using Dfs?", HFILL }},
{ &hf_smb_flags2_roe,
{ "Execute-only Reads", "smb.flags2.roe", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_roe), 0x2000, "Will reads be allowed for execute-only files?", HFILL }},
{ &hf_smb_flags2_nt_error,
{ "Error Code Type", "smb.flags2.nt_error", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_nt_error), 0x4000, "Are error codes NT or DOS format?", HFILL }},
{ &hf_smb_flags2_string,
{ "Unicode Strings", "smb.flags2.string", FT_BOOLEAN, 16,
TFS(&tfs_smb_flags2_string), 0x8000, "Are strings ASCII or Unicode?", HFILL }},
{ &hf_smb_buffer_format,
{ "Buffer Format", "smb.buffer_format", FT_UINT8, BASE_DEC,
VALS(buffer_format_vals), 0x0, "Buffer Format, type of buffer", HFILL }},
{ &hf_smb_dialect_name,
{ "Name", "smb.dialect.name", FT_STRING, BASE_NONE,
NULL, 0, "Name of dialect", HFILL }},
{ &hf_smb_dialect_index,
{ "Selected Index", "smb.dialect.index", FT_UINT16, BASE_DEC,
NULL, 0, "Index of selected dialect", HFILL }},
{ &hf_smb_max_trans_buf_size,
{ "Max Buffer Size", "smb.max_bufsize", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum transmit buffer size", HFILL }},
{ &hf_smb_max_mpx_count,
{ "Max Mpx Count", "smb.max_mpx_count", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum pending multiplexed requests", HFILL }},
{ &hf_smb_max_vcs_num,
{ "Max VCs", "smb.max_vcs", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum VCs between client and server", HFILL }},
{ &hf_smb_session_key,
{ "Session Key", "smb.session_key", FT_UINT32, BASE_HEX,
NULL, 0, "Unique token identifying this session", HFILL }},
{ &hf_smb_server_timezone,
{ "Time Zone", "smb.server_timezone", FT_INT16, BASE_DEC,
NULL, 0, "Current timezone at server.", HFILL }},
{ &hf_smb_encryption_key_length,
{ "Key Length", "smb.encryption_key_length", FT_UINT16, BASE_DEC,
NULL, 0, "Encryption key length (must be 0 if not LM2.1 dialect)", HFILL }},
{ &hf_smb_encryption_key,
{ "Encryption Key", "smb.encryption_key", FT_BYTES, BASE_NONE,
NULL, 0, "Challenge/Response Encryption Key (for LM2.1 dialect)", HFILL }},
{ &hf_smb_primary_domain,
{ "Primary Domain", "smb.primary_domain", FT_STRING, BASE_NONE,
NULL, 0, "The server's primary domain", HFILL }},
{ &hf_smb_server,
{ "Server", "smb.server", FT_STRING, BASE_NONE,
NULL, 0, "The name of the DC/server", HFILL }},
{ &hf_smb_max_raw_buf_size,
{ "Max Raw Buffer", "smb.max_raw", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum raw buffer size", HFILL }},
{ &hf_smb_server_guid,
{ "Server GUID", "smb.server_guid", FT_GUID, BASE_NONE,
NULL, 0, "Globally unique identifier for this server", HFILL }},
{ &hf_smb_volume_guid,
{ "Volume GUID", "smb.volume_guid", FT_GUID, BASE_NONE,
NULL, 0, "Globally unique identifer for this volume", HFILL }},
{ &hf_smb_security_blob_len,
{ "Security Blob Length", "smb.security_blob_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_security_blob,
{ "Security Blob", "smb.security_blob", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_sm_mode16,
{ "Mode", "smb.sm.mode", FT_BOOLEAN, 16,
TFS(&tfs_sm_mode), SECURITY_MODE_MODE, "User or Share security mode?", HFILL }},
{ &hf_smb_sm_password16,
{ "Password", "smb.sm.password", FT_BOOLEAN, 16,
TFS(&tfs_sm_password), SECURITY_MODE_PASSWORD, "Encrypted or plaintext passwords?", HFILL }},
{ &hf_smb_sm_mode,
{ "Mode", "smb.sm.mode", FT_BOOLEAN, 8,
TFS(&tfs_sm_mode), SECURITY_MODE_MODE, "User or Share security mode?", HFILL }},
{ &hf_smb_sm_password,
{ "Password", "smb.sm.password", FT_BOOLEAN, 8,
TFS(&tfs_sm_password), SECURITY_MODE_PASSWORD, "Encrypted or plaintext passwords?", HFILL }},
{ &hf_smb_sm_signatures,
{ "Signatures", "smb.sm.signatures", FT_BOOLEAN, 8,
TFS(&tfs_sm_signatures), SECURITY_MODE_SIGNATURES, "Are security signatures enabled?", HFILL }},
{ &hf_smb_sm_sig_required,
{ "Sig Req", "smb.sm.sig_required", FT_BOOLEAN, 8,
TFS(&tfs_sm_sig_required), SECURITY_MODE_SIG_REQUIRED, "Are security signatures required?", HFILL }},
{ &hf_smb_rm_read,
{ "Read Raw", "smb.rm.read", FT_BOOLEAN, 16,
TFS(&tfs_rm_read), RAWMODE_READ, "Is Read Raw supported?", HFILL }},
{ &hf_smb_rm_write,
{ "Write Raw", "smb.rm.write", FT_BOOLEAN, 16,
TFS(&tfs_rm_write), RAWMODE_WRITE, "Is Write Raw supported?", HFILL }},
{ &hf_smb_server_date_time,
{ "Server Date and Time", "smb.server_date_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Current date and time at server", HFILL }},
{ &hf_smb_server_smb_date,
{ "Server Date", "smb.server_date_time.smb_date", FT_UINT16, BASE_HEX,
NULL, 0, "Current date at server, SMB_DATE format", HFILL }},
{ &hf_smb_server_smb_time,
{ "Server Time", "smb.server_date_time.smb_time", FT_UINT16, BASE_HEX,
NULL, 0, "Current time at server, SMB_TIME format", HFILL }},
{ &hf_smb_server_cap_raw_mode,
{ "Raw Mode", "smb.server_cap.raw_mode", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_raw_mode), SERVER_CAP_RAW_MODE, "Are Raw Read and Raw Write supported?", HFILL }},
{ &hf_smb_server_cap_mpx_mode,
{ "MPX Mode", "smb.server_cap.mpx_mode", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_mpx_mode), SERVER_CAP_MPX_MODE, "Are Read Mpx and Write Mpx supported?", HFILL }},
{ &hf_smb_server_cap_unicode,
{ "Unicode", "smb.server_cap.unicode", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_unicode), SERVER_CAP_UNICODE, "Are Unicode strings supported?", HFILL }},
{ &hf_smb_server_cap_large_files,
{ "Large Files", "smb.server_cap.large_files", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_large_files), SERVER_CAP_LARGE_FILES, "Are large files (>4GB) supported?", HFILL }},
{ &hf_smb_server_cap_nt_smbs,
{ "NT SMBs", "smb.server_cap.nt_smbs", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_nt_smbs), SERVER_CAP_NT_SMBS, "Are NT SMBs supported?", HFILL }},
{ &hf_smb_server_cap_rpc_remote_apis,
{ "RPC Remote APIs", "smb.server_cap.rpc_remote_apis", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_rpc_remote_apis), SERVER_CAP_RPC_REMOTE_APIS, "Are RPC Remote APIs supported?", HFILL }},
{ &hf_smb_server_cap_nt_status,
{ "NT Status Codes", "smb.server_cap.nt_status", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_nt_status), SERVER_CAP_STATUS32, "Are NT Status Codes supported?", HFILL }},
{ &hf_smb_server_cap_level_ii_oplocks,
{ "Level 2 Oplocks", "smb.server_cap.level_2_oplocks", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_level_ii_oplocks), SERVER_CAP_LEVEL_II_OPLOCKS, "Are Level 2 oplocks supported?", HFILL }},
{ &hf_smb_server_cap_lock_and_read,
{ "Lock and Read", "smb.server_cap.lock_and_read", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_lock_and_read), SERVER_CAP_LOCK_AND_READ, "Is Lock and Read supported?", HFILL }},
{ &hf_smb_server_cap_nt_find,
{ "NT Find", "smb.server_cap.nt_find", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_nt_find), SERVER_CAP_NT_FIND, "Is NT Find supported?", HFILL }},
{ &hf_smb_server_cap_dfs,
{ "Dfs", "smb.server_cap.dfs", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_dfs), SERVER_CAP_DFS, "Is Dfs supported?", HFILL }},
{ &hf_smb_server_cap_infolevel_passthru,
{ "Infolevel Passthru", "smb.server_cap.infolevel_passthru", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_infolevel_passthru), SERVER_CAP_INFOLEVEL_PASSTHRU, "Is NT information level request passthrough supported?", HFILL }},
{ &hf_smb_server_cap_large_readx,
{ "Large ReadX", "smb.server_cap.large_readx", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_large_readx), SERVER_CAP_LARGE_READX, "Is Large Read andX supported?", HFILL }},
{ &hf_smb_server_cap_large_writex,
{ "Large WriteX", "smb.server_cap.large_writex", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_large_writex), SERVER_CAP_LARGE_WRITEX, "Is Large Write andX supported?", HFILL }},
{ &hf_smb_server_cap_lwio,
{ "LWIO", "smb.server_cap.lwio", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_lwio), SERVER_CAP_LWIO,
"Is IOCTL/FSCTL supported", HFILL }},
{ &hf_smb_server_cap_unix,
{ "UNIX", "smb.server_cap.unix", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_unix), SERVER_CAP_UNIX , "Are UNIX extensions supported?", HFILL }},
{ &hf_smb_server_cap_compressed_data,
{ "Compressed Data", "smb.server_cap.compressed_data", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_compressed_data), SERVER_CAP_COMPRESSED_DATA, "Is compressed data transfer supported?", HFILL }},
{ &hf_smb_server_cap_dynamic_reauth,
{ "Dynamic Reauth", "smb.server_cap.dynamic_reauth", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_dynamic_reauth), SERVER_CAP_DYNAMIC_REAUTH,
"Is dynamic reauth supported?", HFILL }},
{ &hf_smb_server_cap_extended_security,
{ "Extended Security", "smb.server_cap.extended_security", FT_BOOLEAN, 32,
TFS(&tfs_server_cap_extended_security), SERVER_CAP_EXTENDED_SECURITY, "Are Extended security exchanges supported?", HFILL }},
{ &hf_smb_system_time,
{ "System Time", "smb.system.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unknown,
{ "Unknown Data", "smb.unknown_data", FT_BYTES, BASE_NONE,
NULL, 0, "Unknown Data. Should be implemented by someone", HFILL }},
{ &hf_smb_dir_name,
{ "Directory", "smb.dir_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB Directory Name", HFILL }},
{ &hf_smb_echo_count,
{ "Echo Count", "smb.echo.count", FT_UINT16, BASE_DEC,
NULL, 0, "Number of times to echo data back", HFILL }},
{ &hf_smb_echo_data,
{ "Echo Data", "smb.echo.data", FT_BYTES, BASE_NONE,
NULL, 0, "Data for SMB Echo Request/Response", HFILL }},
{ &hf_smb_echo_seq_num,
{ "Echo Seq Num", "smb.echo.seq_num", FT_UINT16, BASE_DEC,
NULL, 0, "Sequence number for this echo response", HFILL }},
{ &hf_smb_max_buf_size,
{ "Max Buffer", "smb.max_buf", FT_UINT16, BASE_DEC,
NULL, 0, "Max client buffer size", HFILL }},
{ &hf_smb_path,
{ "Path", "smb.path", FT_STRING, BASE_NONE,
NULL, 0, "Path. Server name and share name", HFILL }},
{ &hf_smb_service,
{ "Service", "smb.service", FT_STRING, BASE_NONE,
NULL, 0, "Service name", HFILL }},
{ &hf_smb_password,
{ "Password", "smb.password", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ansi_password,
{ "ANSI Password", "smb.ansi_password", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unicode_password,
{ "Unicode Password", "smb.unicode_password", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_move_flags_file,
{ "Must be file", "smb.move.flags.file", FT_BOOLEAN, 16,
TFS(&tfs_mf_file), 0x0001, "Must target be a file?", HFILL }},
{ &hf_smb_move_flags_dir,
{ "Must be directory", "smb.move.flags.dir", FT_BOOLEAN, 16,
TFS(&tfs_mf_dir), 0x0002, "Must target be a directory?", HFILL }},
{ &hf_smb_move_flags_verify,
{ "Verify writes", "smb.move.flags.verify", FT_BOOLEAN, 16,
TFS(&tfs_mf_verify), 0x0010, "Verify all writes?", HFILL }},
{ &hf_smb_files_moved,
{ "Files Moved", "smb.files_moved", FT_UINT16, BASE_DEC,
NULL, 0, "Number of files moved", HFILL }},
{ &hf_smb_copy_flags_file,
{ "Must be file", "smb.copy.flags.file", FT_BOOLEAN, 16,
TFS(&tfs_mf_file), 0x0001, "Must target be a file?", HFILL }},
{ &hf_smb_copy_flags_dir,
{ "Must be directory", "smb.copy.flags.dir", FT_BOOLEAN, 16,
TFS(&tfs_mf_dir), 0x0002, "Must target be a directory?", HFILL }},
{ &hf_smb_copy_flags_dest_mode,
{ "Destination mode", "smb.copy.flags.dest_mode", FT_BOOLEAN, 16,
TFS(&tfs_cf_mode), 0x0004, "Is destination in ASCII?", HFILL }},
{ &hf_smb_copy_flags_source_mode,
{ "Source mode", "smb.copy.flags.source_mode", FT_BOOLEAN, 16,
TFS(&tfs_cf_mode), 0x0008, "Is source in ASCII?", HFILL }},
{ &hf_smb_copy_flags_verify,
{ "Verify writes", "smb.copy.flags.verify", FT_BOOLEAN, 16,
TFS(&tfs_mf_verify), 0x0010, "Verify all writes?", HFILL }},
{ &hf_smb_copy_flags_tree_copy,
{ "Tree copy", "smb.copy.flags.tree_copy", FT_BOOLEAN, 16,
TFS(&tfs_cf_tree_copy), 0x0010, "Is copy a tree copy?", HFILL }},
{ &hf_smb_copy_flags_ea_action,
{ "EA action if EAs not supported on dest", "smb.copy.flags.ea_action", FT_BOOLEAN, 16,
TFS(&tfs_cf_ea_action), 0x0010, "Fail copy if source file has EAs and dest doesn't support EAs?", HFILL }},
{ &hf_smb_count,
{ "Count", "smb.count", FT_UINT32, BASE_DEC,
NULL, 0, "Count number of items/bytes", HFILL }},
{ &hf_smb_count_low,
{ "Count Low", "smb.count_low", FT_UINT16, BASE_DEC,
NULL, 0, "Count number of items/bytes, Low 16 bits", HFILL }},
{ &hf_smb_count_high,
{ "Count High (multiply with 64K)", "smb.count_high", FT_UINT16, BASE_DEC,
NULL, 0, "Count number of items/bytes, High 16 bits", HFILL }},
{ &hf_smb_file_name,
{ "File Name", "smb.file", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_open_function_create,
{ "Create", "smb.open.function.create", FT_BOOLEAN, 16,
TFS(&tfs_of_create), 0x0010, "Create file if it doesn't exist?", HFILL }},
{ &hf_smb_open_function_open,
{ "Open", "smb.open.function.open", FT_UINT16, BASE_DEC,
VALS(of_open), 0x0003, "Action to be taken on open if file exists", HFILL }},
{ &hf_smb_fid,
{ "FID", "smb.fid", FT_UINT16, BASE_HEX,
NULL, 0, "FID: File ID", HFILL }},
{ &hf_smb_file_attr_read_only_16bit,
{ "Read Only", "smb.file_attribute.read_only", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_read_only), SMB_FILE_ATTRIBUTE_READ_ONLY, "READ ONLY file attribute", HFILL }},
{ &hf_smb_file_attr_read_only_8bit,
{ "Read Only", "smb.file_attribute.read_only", FT_BOOLEAN, 8,
TFS(&tfs_file_attribute_read_only), SMB_FILE_ATTRIBUTE_READ_ONLY, "READ ONLY file attribute", HFILL }},
{ &hf_smb_file_attr_hidden_16bit,
{ "Hidden", "smb.file_attribute.hidden", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_hidden), SMB_FILE_ATTRIBUTE_HIDDEN, "HIDDEN file attribute", HFILL }},
{ &hf_smb_file_attr_hidden_8bit,
{ "Hidden", "smb.file_attribute.hidden", FT_BOOLEAN, 8,
TFS(&tfs_file_attribute_hidden), SMB_FILE_ATTRIBUTE_HIDDEN, "HIDDEN file attribute", HFILL }},
{ &hf_smb_file_attr_system_16bit,
{ "System", "smb.file_attribute.system", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_system), SMB_FILE_ATTRIBUTE_SYSTEM, "SYSTEM file attribute", HFILL }},
{ &hf_smb_file_attr_system_8bit,
{ "System", "smb.file_attribute.system", FT_BOOLEAN, 8,
TFS(&tfs_file_attribute_system), SMB_FILE_ATTRIBUTE_SYSTEM, "SYSTEM file attribute", HFILL }},
{ &hf_smb_file_attr_volume_16bit,
{ "Volume ID", "smb.file_attribute.volume", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_volume), SMB_FILE_ATTRIBUTE_VOLUME, "VOLUME file attribute", HFILL }},
{ &hf_smb_file_attr_volume_8bit,
{ "Volume ID", "smb.file_attribute.volume", FT_BOOLEAN, 8,
TFS(&tfs_file_attribute_volume), SMB_FILE_ATTRIBUTE_VOLUME, "VOLUME ID file attribute", HFILL }},
{ &hf_smb_file_attr_directory_16bit,
{ "Directory", "smb.file_attribute.directory", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_directory), SMB_FILE_ATTRIBUTE_DIRECTORY, "DIRECTORY file attribute", HFILL }},
{ &hf_smb_file_attr_directory_8bit,
{ "Directory", "smb.file_attribute.directory", FT_BOOLEAN, 8,
TFS(&tfs_file_attribute_directory), SMB_FILE_ATTRIBUTE_DIRECTORY, "DIRECTORY file attribute", HFILL }},
{ &hf_smb_file_attr_archive_16bit,
{ "Archive", "smb.file_attribute.archive", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_archive), SMB_FILE_ATTRIBUTE_ARCHIVE, "ARCHIVE file attribute", HFILL }},
{ &hf_smb_file_attr_archive_8bit,
{ "Archive", "smb.file_attribute.archive", FT_BOOLEAN, 8,
TFS(&tfs_file_attribute_archive), SMB_FILE_ATTRIBUTE_ARCHIVE, "ARCHIVE file attribute", HFILL }},
{ &hf_smb_file_attr_device,
{ "Device", "smb.file_attribute.device", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_device), SMB_FILE_ATTRIBUTE_DEVICE, "Is this file a device?", HFILL }},
{ &hf_smb_file_attr_normal,
{ "Normal", "smb.file_attribute.normal", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_normal), SMB_FILE_ATTRIBUTE_NORMAL, "Is this a normal file?", HFILL }},
{ &hf_smb_file_attr_temporary,
{ "Temporary", "smb.file_attribute.temporary", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_temporary), SMB_FILE_ATTRIBUTE_TEMPORARY, "Is this a temporary file?", HFILL }},
{ &hf_smb_file_attr_sparse,
{ "Sparse", "smb.file_attribute.sparse", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_sparse), SMB_FILE_ATTRIBUTE_SPARSE, "Is this a sparse file?", HFILL }},
{ &hf_smb_file_attr_reparse,
{ "Reparse Point", "smb.file_attribute.reparse", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_reparse), SMB_FILE_ATTRIBUTE_REPARSE, "Does this file have an associated reparse point?", HFILL }},
{ &hf_smb_file_attr_compressed,
{ "Compressed", "smb.file_attribute.compressed", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_compressed), SMB_FILE_ATTRIBUTE_COMPRESSED, "Is this file compressed?", HFILL }},
{ &hf_smb_file_attr_offline,
{ "Offline", "smb.file_attribute.offline", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_offline), SMB_FILE_ATTRIBUTE_OFFLINE, "Is this file offline?", HFILL }},
{ &hf_smb_file_attr_not_content_indexed,
{ "Content Indexed", "smb.file_attribute.not_content_indexed", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_not_content_indexed), SMB_FILE_ATTRIBUTE_NOT_CONTENT_INDEXED, "May this file be indexed by the content indexing service", HFILL }},
{ &hf_smb_file_attr_encrypted,
{ "Encrypted", "smb.file_attribute.encrypted", FT_BOOLEAN, 16,
TFS(&tfs_file_attribute_encrypted), SMB_FILE_ATTRIBUTE_ENCRYPTED, "Is this file encrypted?", HFILL }},
{ &hf_smb_file_size,
{ "File Size", "smb.file_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_search_attribute_read_only,
{ "Read Only", "smb.search.attribute.read_only", FT_BOOLEAN, 16,
TFS(&tfs_search_attribute_read_only), SMB_FILE_ATTRIBUTE_READ_ONLY, "READ ONLY search attribute", HFILL }},
{ &hf_smb_search_attribute_hidden,
{ "Hidden", "smb.search.attribute.hidden", FT_BOOLEAN, 16,
TFS(&tfs_search_attribute_hidden), SMB_FILE_ATTRIBUTE_HIDDEN, "HIDDEN search attribute", HFILL }},
{ &hf_smb_search_attribute_system,
{ "System", "smb.search.attribute.system", FT_BOOLEAN, 16,
TFS(&tfs_search_attribute_system), SMB_FILE_ATTRIBUTE_SYSTEM, "SYSTEM search attribute", HFILL }},
{ &hf_smb_search_attribute_volume,
{ "Volume ID", "smb.search.attribute.volume", FT_BOOLEAN, 16,
TFS(&tfs_search_attribute_volume), SMB_FILE_ATTRIBUTE_VOLUME, "VOLUME ID search attribute", HFILL }},
{ &hf_smb_search_attribute_directory,
{ "Directory", "smb.search.attribute.directory", FT_BOOLEAN, 16,
TFS(&tfs_search_attribute_directory), SMB_FILE_ATTRIBUTE_DIRECTORY, "DIRECTORY search attribute", HFILL }},
{ &hf_smb_search_attribute_archive,
{ "Archive", "smb.search.attribute.archive", FT_BOOLEAN, 16,
TFS(&tfs_search_attribute_archive), SMB_FILE_ATTRIBUTE_ARCHIVE, "ARCHIVE search attribute", HFILL }},
{ &hf_smb_access_mode,
{ "Access Mode", "smb.access.mode", FT_UINT16, BASE_DEC,
VALS(da_access_vals), 0x0007, NULL, HFILL }},
{ &hf_smb_access_sharing,
{ "Sharing Mode", "smb.access.sharing", FT_UINT16, BASE_DEC,
VALS(da_sharing_vals), 0x0070, NULL, HFILL }},
{ &hf_smb_access_locality,
{ "Locality", "smb.access.locality", FT_UINT16, BASE_DEC,
VALS(da_locality_vals), 0x0700, "Locality of reference", HFILL }},
{ &hf_smb_access_caching,
{ "Caching", "smb.access.caching", FT_BOOLEAN, 16,
TFS(&tfs_da_caching), 0x1000, "Caching mode?", HFILL }},
{ &hf_smb_access_writetru,
{ "Writethrough", "smb.access.writethrough", FT_BOOLEAN, 16,
TFS(&tfs_da_writetru), 0x4000, "Writethrough mode?", HFILL }},
{ &hf_smb_create_time,
{ "Created", "smb.create.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Creation Time", HFILL }},
{ &hf_smb_modify_time,
{ "Modified", "smb.modify.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Modification Time", HFILL }},
{ &hf_smb_backup_time,
{ "Backed-up", "smb.backup.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Backup time", HFILL}},
{ &hf_smb_mac_alloc_block_count,
{ "Allocation Block Count", "smb.alloc.count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb_mac_alloc_block_size,
{ "Allocation Block Count", "smb.alloc.size", FT_UINT32, BASE_DEC,
NULL, 0, "Allocation Block Size", HFILL}},
{ &hf_smb_mac_free_block_count,
{ "Free Block Count", "smb.free_block.count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb_mac_root_file_count,
{ "Root File Count", "smb.root.file.count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb_mac_root_dir_count,
{ "Root Directory Count", "smb.root.dir.count", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb_mac_file_count,
{ "Root File Count", "smb.file.count", FT_UINT32, BASE_DEC,
NULL, 0, "File Count", HFILL}},
{ &hf_smb_mac_dir_count,
{ "Root Directory Count", "smb.dir.count", FT_UINT32, BASE_DEC,
NULL, 0, "Directory Count", HFILL}},
{ &hf_smb_mac_support_flags,
{ "Mac Support Flags", "smb.mac.support.flags", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_smb_mac_sup_access_ctrl,
{ "Mac Access Control", "smb.mac.access_control", FT_BOOLEAN, 32,
TFS(&tfs_smb_mac_access_ctrl), 0x0010, "Are Mac Access Control Supported", HFILL }},
{ &hf_smb_mac_sup_getset_comments,
{ "Get Set Comments", "smb.mac.get_set_comments", FT_BOOLEAN, 32,
TFS(&tfs_smb_mac_getset_comments), 0x0020, "Are Mac Get Set Comments supported?", HFILL }},
{ &hf_smb_mac_sup_desktopdb_calls,
{ "Desktop DB Calls", "smb.mac.desktop_db_calls", FT_BOOLEAN, 32,
TFS(&tfs_smb_mac_desktopdb_calls), 0x0040, "Are Macintosh Desktop DB Calls Supported?", HFILL }},
{ &hf_smb_mac_sup_unique_ids,
{ "Macintosh Unique IDs", "smb.mac.uids", FT_BOOLEAN, 32,
TFS(&tfs_smb_mac_unique_ids), 0x0080, "Are Unique IDs supported", HFILL }},
{ &hf_smb_mac_sup_streams,
{ "Mac Streams", "smb.mac.streams_support", FT_BOOLEAN, 32,
TFS(&tfs_smb_mac_streams), 0x0100, "Are Mac Extensions and streams supported?", HFILL }},
{ &hf_smb_create_dos_date,
{ "Create Date", "smb.create.smb.date", FT_UINT16, BASE_HEX,
NULL, 0, "Create Date, SMB_DATE format", HFILL }},
{ &hf_smb_create_dos_time,
{ "Create Time", "smb.create.smb.time", FT_UINT16, BASE_HEX,
NULL, 0, "Create Time, SMB_TIME format", HFILL }},
{ &hf_smb_last_write_time,
{ "Last Write", "smb.last_write.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time this file was last written to", HFILL }},
{ &hf_smb_last_write_dos_date,
{ "Last Write Date", "smb.last_write.smb.date", FT_UINT16, BASE_HEX,
NULL, 0, "Last Write Date, SMB_DATE format", HFILL }},
{ &hf_smb_last_write_dos_time,
{ "Last Write Time", "smb.last_write.smb.time", FT_UINT16, BASE_HEX,
NULL, 0, "Last Write Time, SMB_TIME format", HFILL }},
{ &hf_smb_old_file_name,
{ "Old File Name", "smb.old_file", FT_STRING, BASE_NONE,
NULL, 0, "Old File Name (When renaming a file)", HFILL }},
{ &hf_smb_offset,
{ "Offset", "smb.offset", FT_UINT32, BASE_DEC,
NULL, 0, "Offset in file", HFILL }},
{ &hf_smb_remaining,
{ "Remaining", "smb.remaining", FT_UINT32, BASE_DEC,
NULL, 0, "Remaining number of bytes", HFILL }},
{ &hf_smb_padding,
{ "Padding", "smb.padding", FT_BYTES, BASE_NONE,
NULL, 0, "Padding or unknown data", HFILL }},
{ &hf_smb_file_data,
{ "File Data", "smb.file_data", FT_BYTES, BASE_NONE,
NULL, 0, "Data read/written to the file", HFILL }},
{ &hf_smb_mac_fndrinfo,
{ "Finder Info", "smb.mac.finderinfo", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_smb_total_data_len,
{ "Total Data Length", "smb.total_data_len", FT_UINT16, BASE_DEC,
NULL, 0, "Total length of data", HFILL }},
{ &hf_smb_data_len,
{ "Data Length", "smb.data_len", FT_UINT16, BASE_DEC,
NULL, 0, "Length of data", HFILL }},
{ &hf_smb_data_len_low,
{ "Data Length Low", "smb.data_len_low", FT_UINT16, BASE_DEC,
NULL, 0, "Length of data, Low 16 bits", HFILL }},
{ &hf_smb_data_len_high,
{ "Data Length High (multiply with 64K)", "smb.data_len_high", FT_UINT16, BASE_DEC,
NULL, 0, "Length of data, High 16 bits", HFILL }},
{ &hf_smb_seek_mode,
{ "Seek Mode", "smb.seek_mode", FT_UINT16, BASE_DEC,
VALS(seek_mode_vals), 0, "Seek Mode, what type of seek", HFILL }},
{ &hf_smb_access_time,
{ "Last Access", "smb.access.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Last Access Time", HFILL }},
{ &hf_smb_access_dos_date,
{ "Last Access Date", "smb.access.smb.date", FT_UINT16, BASE_HEX,
NULL, 0, "Last Access Date, SMB_DATE format", HFILL }},
{ &hf_smb_access_dos_time,
{ "Last Access Time", "smb.access.smb.time", FT_UINT16, BASE_HEX,
NULL, 0, "Last Access Time, SMB_TIME format", HFILL }},
{ &hf_smb_data_size,
{ "Data Size", "smb.data_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_alloc_size,
{ "Allocation Size", "smb.alloc_size", FT_UINT32, BASE_DEC,
NULL, 0, "Number of bytes to reserve on create or truncate", HFILL }},
{ &hf_smb_max_count,
{ "Max Count", "smb.maxcount", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum Count", HFILL }},
{ &hf_smb_max_count_low,
{ "Max Count Low", "smb.maxcount_low", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum Count, Low 16 bits", HFILL }},
{ &hf_smb_max_count_high,
{ "Max Count High (multiply with 64K)", "smb.maxcount_high", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum Count, High 16 bits", HFILL }},
{ &hf_smb_min_count,
{ "Min Count", "smb.mincount", FT_UINT16, BASE_DEC,
NULL, 0, "Minimum Count", HFILL }},
{ &hf_smb_timeout,
{ "Timeout", "smb.timeout", FT_UINT32, BASE_DEC,
NULL, 0, "Timeout in milliseconds", HFILL }},
{ &hf_smb_high_offset,
{ "High Offset", "smb.offset_high", FT_UINT32, BASE_DEC,
NULL, 0, "High 32 Bits Of File Offset", HFILL }},
{ &hf_smb_units,
{ "Total Units", "smb.units", FT_UINT16, BASE_DEC,
NULL, 0, "Total number of units at server", HFILL }},
{ &hf_smb_bpu,
{ "Blocks Per Unit", "smb.bpu", FT_UINT16, BASE_DEC,
NULL, 0, "Blocks per unit at server", HFILL }},
{ &hf_smb_blocksize,
{ "Block Size", "smb.blocksize", FT_UINT16, BASE_DEC,
NULL, 0, "Block size (in bytes) at server", HFILL }},
{ &hf_smb_freeunits,
{ "Free Units", "smb.free_units", FT_UINT16, BASE_DEC,
NULL, 0, "Number of free units at server", HFILL }},
{ &hf_smb_data_offset,
{ "Data Offset", "smb.data_offset", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_dcm,
{ "Data Compaction Mode", "smb.dcm", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_request_mask,
{ "Request Mask", "smb.request.mask", FT_UINT32, BASE_HEX,
NULL, 0, "Connectionless mode mask", HFILL }},
{ &hf_smb_response_mask,
{ "Response Mask", "smb.response.mask", FT_UINT32, BASE_HEX,
NULL, 0, "Connectionless mode mask", HFILL }},
{ &hf_smb_search_id,
{ "Search ID", "smb.search_id", FT_UINT16, BASE_HEX,
NULL, 0, "Search ID, handle for find operations", HFILL }},
{ &hf_smb_write_mode_write_through,
{ "Write Through", "smb.write.mode.write_through", FT_BOOLEAN, 16,
TFS(&tfs_write_mode_write_through), WRITE_MODE_WRITE_THROUGH, "Write through mode requested?", HFILL }},
{ &hf_smb_write_mode_return_remaining,
{ "Return Remaining", "smb.write.mode.return_remaining", FT_BOOLEAN, 16,
TFS(&tfs_write_mode_return_remaining), WRITE_MODE_RETURN_REMAINING, "Return remaining data responses?", HFILL }},
{ &hf_smb_write_mode_raw,
{ "Write Raw", "smb.write.mode.raw", FT_BOOLEAN, 16,
TFS(&tfs_write_mode_raw), WRITE_MODE_RAW, "Use WriteRawNamedPipe?", HFILL }},
{ &hf_smb_write_mode_message_start,
{ "Message Start", "smb.write.mode.message_start", FT_BOOLEAN, 16,
TFS(&tfs_write_mode_message_start), WRITE_MODE_MESSAGE_START, "Is this the start of a message?", HFILL }},
{ &hf_smb_write_mode_connectionless,
{ "Connectionless", "smb.write.mode.connectionless", FT_BOOLEAN, 16,
TFS(&tfs_write_mode_connectionless), WRITE_MODE_CONNECTIONLESS, "Connectionless mode requested?", HFILL }},
{ &hf_smb_resume_key_len,
{ "Resume Key Length", "smb.resume.key_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_resume_find_id,
{ "Find ID", "smb.resume.find_id", FT_UINT8, BASE_HEX,
NULL, 0, "Handle for Find operation", HFILL }},
{ &hf_smb_resume_server_cookie,
{ "Server Cookie", "smb.resume.server.cookie", FT_BYTES, BASE_NONE,
NULL, 0, "Cookie, must not be modified by the client", HFILL }},
{ &hf_smb_resume_client_cookie,
{ "Client Cookie", "smb.resume.client.cookie", FT_BYTES, BASE_NONE,
NULL, 0, "Cookie, must not be modified by the server", HFILL }},
{ &hf_smb_andxoffset,
{ "AndXOffset", "smb.andxoffset", FT_UINT16, BASE_DEC,
NULL, 0, "Offset to next command in this SMB packet", HFILL }},
{ &hf_smb_lock_type_large,
{ "Large Files", "smb.lock.type.large", FT_BOOLEAN, 8,
TFS(&tfs_lock_type_large), 0x10, "Large file locking requested?", HFILL }},
{ &hf_smb_lock_type_cancel,
{ "Cancel", "smb.lock.type.cancel", FT_BOOLEAN, 8,
TFS(&tfs_lock_type_cancel), 0x08, "Cancel outstanding lock requests?", HFILL }},
{ &hf_smb_lock_type_change,
{ "Change", "smb.lock.type.change", FT_BOOLEAN, 8,
TFS(&tfs_lock_type_change), 0x04, "Change type of lock?", HFILL }},
{ &hf_smb_lock_type_oplock,
{ "Oplock Break", "smb.lock.type.oplock_release", FT_BOOLEAN, 8,
TFS(&tfs_lock_type_oplock), 0x02, "Is this a notification of, or a response to, an oplock break?", HFILL }},
{ &hf_smb_lock_type_shared,
{ "Shared", "smb.lock.type.shared", FT_BOOLEAN, 8,
TFS(&tfs_lock_type_shared), 0x01, "Shared or exclusive lock requested?", HFILL }},
{ &hf_smb_locking_ol,
{ "Oplock Level", "smb.locking.oplock.level", FT_UINT8, BASE_DEC,
VALS(locking_ol_vals), 0, "Level of existing oplock at client (if any)", HFILL }},
{ &hf_smb_number_of_locks,
{ "Number of Locks", "smb.locking.num_locks", FT_UINT16, BASE_DEC,
NULL, 0, "Number of lock requests in this request", HFILL }},
{ &hf_smb_number_of_unlocks,
{ "Number of Unlocks", "smb.locking.num_unlocks", FT_UINT16, BASE_DEC,
NULL, 0, "Number of unlock requests in this request", HFILL }},
{ &hf_smb_lock_long_length,
{ "Length", "smb.lock.length", FT_UINT64, BASE_DEC,
NULL, 0, "Length of lock/unlock region", HFILL }},
{ &hf_smb_lock_long_offset,
{ "Offset", "smb.lock.offset", FT_UINT64, BASE_DEC,
NULL, 0, "Offset in the file of lock/unlock region", HFILL }},
{ &hf_smb_file_type,
{ "File Type", "smb.file_type", FT_UINT16, BASE_DEC,
VALS(filetype_vals), 0, "Type of file", HFILL }},
{ &hf_smb_ipc_state_nonblocking,
{ "Nonblocking", "smb.ipc_state.nonblocking", FT_BOOLEAN, 16,
TFS(&tfs_ipc_state_nonblocking), 0x8000, "Is I/O to this pipe nonblocking?", HFILL }},
{ &hf_smb_ipc_state_endpoint,
{ "Endpoint", "smb.ipc_state.endpoint", FT_UINT16, BASE_DEC,
VALS(ipc_state_endpoint_vals), 0x4000, "Which end of the pipe this is", HFILL }},
{ &hf_smb_ipc_state_pipe_type,
{ "Pipe Type", "smb.ipc_state.pipe_type", FT_UINT16, BASE_DEC,
VALS(ipc_state_pipe_type_vals), 0x0c00, "What type of pipe this is", HFILL }},
{ &hf_smb_ipc_state_read_mode,
{ "Read Mode", "smb.ipc_state.read_mode", FT_UINT16, BASE_DEC,
VALS(ipc_state_read_mode_vals), 0x0300, "How this pipe should be read", HFILL }},
{ &hf_smb_ipc_state_icount,
{ "Icount", "smb.ipc_state.icount", FT_UINT16, BASE_DEC,
NULL, 0x00FF, "Count to control pipe instancing", HFILL }},
{ &hf_smb_server_fid,
{ "Server FID", "smb.server_fid", FT_UINT32, BASE_HEX,
NULL, 0, "Server unique File ID", HFILL }},
{ &hf_smb_open_flags_add_info,
{ "Additional Info", "smb.open.flags.add_info", FT_BOOLEAN, 16,
TFS(&tfs_open_flags_add_info), 0x0001, "Additional Information Requested?", HFILL }},
{ &hf_smb_open_flags_ex_oplock,
{ "Exclusive Oplock", "smb.open.flags.ex_oplock", FT_BOOLEAN, 16,
TFS(&tfs_open_flags_ex_oplock), 0x0002, "Exclusive Oplock Requested?", HFILL }},
{ &hf_smb_open_flags_batch_oplock,
{ "Batch Oplock", "smb.open.flags.batch_oplock", FT_BOOLEAN, 16,
TFS(&tfs_open_flags_batch_oplock), 0x0004, "Batch Oplock Requested?", HFILL }},
{ &hf_smb_open_flags_ealen,
{ "Total EA Len", "smb.open.flags.ealen", FT_BOOLEAN, 16,
TFS(&tfs_open_flags_ealen), 0x0008, "Total EA Len Requested?", HFILL }},
{ &hf_smb_open_action_open,
{ "Open Action", "smb.open.action.open", FT_UINT16, BASE_DEC,
VALS(oa_open_vals), 0x0003, "Open Action, how the file was opened", HFILL }},
{ &hf_smb_open_action_lock,
{ "Exclusive Open", "smb.open.action.lock", FT_BOOLEAN, 16,
TFS(&tfs_oa_lock), 0x8000, "Is this file opened by another user?", HFILL }},
{ &hf_smb_vc_num,
{ "VC Number", "smb.vc", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_password_len,
{ "Password Length", "smb.pwlen", FT_UINT16, BASE_DEC,
NULL, 0, "Length of password", HFILL }},
{ &hf_smb_ansi_password_len,
{ "ANSI Password Length", "smb.ansi_pwlen", FT_UINT16, BASE_DEC,
NULL, 0, "Length of ANSI password", HFILL }},
{ &hf_smb_unicode_password_len,
{ "Unicode Password Length", "smb.unicode_pwlen", FT_UINT16, BASE_DEC,
NULL, 0, "Length of Unicode password", HFILL }},
{ &hf_smb_account,
{ "Account", "smb.account", FT_STRING, BASE_NONE,
NULL, 0, "Account, username", HFILL }},
{ &hf_smb_os,
{ "Native OS", "smb.native_os", FT_STRING, BASE_NONE,
NULL, 0, "Which OS we are running", HFILL }},
{ &hf_smb_lanman,
{ "Native LAN Manager", "smb.native_lanman", FT_STRING, BASE_NONE,
NULL, 0, "Which LANMAN protocol we are running", HFILL }},
{ &hf_smb_setup_action_guest,
{ "Guest", "smb.setup.action.guest", FT_BOOLEAN, 16,
TFS(&tfs_setup_action_guest), 0x0001, "Client logged in as GUEST?", HFILL }},
{ &hf_smb_fs,
{ "Native File System", "smb.native_fs", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_connect_flags_dtid,
{ "Disconnect TID", "smb.connect.flags.dtid", FT_BOOLEAN, 16,
TFS(&tfs_disconnect_tid), 0x0001, "Disconnect TID?", HFILL }},
{ &hf_smb_connect_flags_ext_sig,
{ "Extended Signature", "smb.connect.flags.extendedsig", FT_BOOLEAN, 16,
TFS(&tfs_extended_signature), 0x0004, "Extended signature?", HFILL }},
{ &hf_smb_connect_flags_ext_resp,
{ "Extended Response", "smb.connect.flags.extendedresp", FT_BOOLEAN, 16,
TFS(&tfs_extended_response), 0x0008, "Extended response?", HFILL }},
{ &hf_smb_connect_support_search,
{ "Search Bits", "smb.connect.support.search", FT_BOOLEAN, 16,
TFS(&tfs_connect_support_search), 0x0001, "Exclusive Search Bits supported?", HFILL }},
{ &hf_smb_connect_support_in_dfs,
{ "In Dfs", "smb.connect.support.dfs", FT_BOOLEAN, 16,
TFS(&tfs_connect_support_in_dfs), 0x0002, "Is this in a Dfs tree?", HFILL }},
{ &hf_smb_connect_support_csc_mask_vals,
{ "CSC Mask", "smb.connect.support.cscmask", FT_UINT16, BASE_DEC,
VALS(connect_support_csc_mask_vals), 0x000c, "CSC mask?", HFILL }},
{ &hf_smb_connect_support_uniquefilename,
{ "Unique File Name", "smb.connect.support.uniqfilename", FT_BOOLEAN, 16,
TFS(&tfs_connect_support_uniquefilename), 0x0010, "Unique file name supported?", HFILL }},
{ &hf_smb_connect_support_extended_signature,
{ "Extended Signatures", "smb.connect.support.extendedsig", FT_BOOLEAN, 16,
TFS(&tfs_connect_support_extended_signature), 0x0020, "Extended signatures?", HFILL }},
{ &hf_smb_max_setup_count,
{ "Max Setup Count", "smb.msc", FT_UINT8, BASE_DEC,
NULL, 0, "Maximum number of setup words to return", HFILL }},
{ &hf_smb_total_param_count,
{ "Total Parameter Count", "smb.tpc", FT_UINT32, BASE_DEC,
NULL, 0, "Total number of parameter bytes", HFILL }},
{ &hf_smb_total_data_count,
{ "Total Data Count", "smb.tdc", FT_UINT32, BASE_DEC,
NULL, 0, "Total number of data bytes", HFILL }},
{ &hf_smb_max_param_count,
{ "Max Parameter Count", "smb.mpc", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum number of parameter bytes to return", HFILL }},
{ &hf_smb_max_data_count,
{ "Max Data Count", "smb.mdc", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum number of data bytes to return", HFILL }},
{ &hf_smb_param_disp16,
{ "Parameter Displacement", "smb.pd", FT_UINT16, BASE_DEC,
NULL, 0, "Displacement of these parameter bytes", HFILL }},
{ &hf_smb_param_count16,
{ "Parameter Count", "smb.pc", FT_UINT16, BASE_DEC,
NULL, 0, "Number of parameter bytes in this buffer", HFILL }},
{ &hf_smb_param_offset16,
{ "Parameter Offset", "smb.po", FT_UINT16, BASE_DEC,
NULL, 0, "Offset (from header start) to parameters", HFILL }},
{ &hf_smb_param_disp32,
{ "Parameter Displacement", "smb.pd", FT_UINT32, BASE_DEC,
NULL, 0, "Displacement of these parameter bytes", HFILL }},
{ &hf_smb_param_count32,
{ "Parameter Count", "smb.pc", FT_UINT32, BASE_DEC,
NULL, 0, "Number of parameter bytes in this buffer", HFILL }},
{ &hf_smb_param_offset32,
{ "Parameter Offset", "smb.po", FT_UINT32, BASE_DEC,
NULL, 0, "Offset (from header start) to parameters", HFILL }},
{ &hf_smb_data_count16,
{ "Data Count", "smb.dc", FT_UINT16, BASE_DEC,
NULL, 0, "Number of data bytes in this buffer", HFILL }},
{ &hf_smb_data_disp16,
{ "Data Displacement", "smb.data_disp", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_data_offset16,
{ "Data Offset", "smb.data_offset", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_data_count32,
{ "Data Count", "smb.dc", FT_UINT32, BASE_DEC,
NULL, 0, "Number of data bytes in this buffer", HFILL }},
{ &hf_smb_data_disp32,
{ "Data Displacement", "smb.data_disp", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_data_offset32,
{ "Data Offset", "smb.data_offset", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_setup_count,
{ "Setup Count", "smb.sc", FT_UINT8, BASE_DEC,
NULL, 0, "Number of setup words in this buffer", HFILL }},
{ &hf_smb_nt_ioctl_isfsctl,
{ "IsFSctl", "smb.nt.ioctl.isfsctl", FT_UINT8, BASE_DEC,
VALS(nt_ioctl_isfsctl_vals), 0, "Is this a device IOCTL (FALSE) or FS Control (TRUE)", HFILL }},
{ &hf_smb_nt_ioctl_flags_root_handle,
{ "Root Handle", "smb.nt.ioctl.flags.root_handle", FT_BOOLEAN, 8,
TFS(&tfs_nt_ioctl_flags_root_handle), NT_IOCTL_FLAGS_ROOT_HANDLE, "Apply to this share or root Dfs share", HFILL }},
{ &hf_smb_nt_notify_action,
{ "Action", "smb.nt.notify.action", FT_UINT32, BASE_DEC,
VALS(nt_notify_action_vals), 0, "Which action caused this notify response", HFILL }},
{ &hf_smb_nt_notify_watch_tree,
{ "Watch Tree", "smb.nt.notify.watch_tree", FT_UINT8, BASE_DEC,
VALS(watch_tree_vals), 0, "Should Notify watch subdirectories also?", HFILL }},
{ &hf_smb_nt_notify_stream_write,
{ "Stream Write", "smb.nt.notify.stream_write", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_stream_write), NT_NOTIFY_STREAM_WRITE, "Notify on stream write?", HFILL }},
{ &hf_smb_nt_notify_stream_size,
{ "Stream Size Change", "smb.nt.notify.stream_size", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_stream_size), NT_NOTIFY_STREAM_SIZE, "Notify on changes of stream size", HFILL }},
{ &hf_smb_nt_notify_stream_name,
{ "Stream Name Change", "smb.nt.notify.stream_name", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_stream_name), NT_NOTIFY_STREAM_NAME, "Notify on changes to stream name?", HFILL }},
{ &hf_smb_nt_notify_security,
{ "Security Change", "smb.nt.notify.security", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_security), NT_NOTIFY_SECURITY, "Notify on changes to security settings", HFILL }},
{ &hf_smb_nt_notify_ea,
{ "EA Change", "smb.nt.notify.ea", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_ea), NT_NOTIFY_EA, "Notify on changes to Extended Attributes", HFILL }},
{ &hf_smb_nt_notify_creation,
{ "Created Change", "smb.nt.notify.creation", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_creation), NT_NOTIFY_CREATION, "Notify on changes to creation time", HFILL }},
{ &hf_smb_nt_notify_last_access,
{ "Last Access Change", "smb.nt.notify.last_access", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_last_access), NT_NOTIFY_LAST_ACCESS, "Notify on changes to last access", HFILL }},
{ &hf_smb_nt_notify_last_write,
{ "Last Write Change", "smb.nt.notify.last_write", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_last_write), NT_NOTIFY_LAST_WRITE, "Notify on changes to last write", HFILL }},
{ &hf_smb_nt_notify_size,
{ "Size Change", "smb.nt.notify.size", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_size), NT_NOTIFY_SIZE, "Notify on changes to size", HFILL }},
{ &hf_smb_nt_notify_attributes,
{ "Attribute Change", "smb.nt.notify.attributes", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_attributes), NT_NOTIFY_ATTRIBUTES, "Notify on changes to attributes", HFILL }},
{ &hf_smb_nt_notify_dir_name,
{ "Directory Name Change", "smb.nt.notify.dir_name", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_dir_name), NT_NOTIFY_DIR_NAME, "Notify on changes to directory name", HFILL }},
{ &hf_smb_nt_notify_file_name,
{ "File Name Change", "smb.nt.notify.file_name", FT_BOOLEAN, 32,
TFS(&tfs_nt_notify_file_name), NT_NOTIFY_FILE_NAME, "Notify on changes to file name", HFILL }},
{ &hf_smb_root_dir_fid,
{ "Root FID", "smb.rfid", FT_UINT32, BASE_HEX,
NULL, 0, "Open is relative to this FID (if nonzero)", HFILL }},
{ &hf_smb_alloc_size64,
{ "Allocation Size", "smb.alloc_size", FT_UINT64, BASE_DEC,
NULL, 0, "Number of bytes to reserve on create or truncate", HFILL }},
{ &hf_smb_nt_create_disposition,
{ "Disposition", "smb.create.disposition", FT_UINT32, BASE_DEC,
VALS(create_disposition_vals), 0, "Create disposition, what to do if the file does/does not exist", HFILL }},
{ &hf_smb_sd_length,
{ "SD Length", "smb.sd.length", FT_UINT32, BASE_DEC,
NULL, 0, "Total length of security descriptor", HFILL }},
{ &hf_smb_ea_list_length,
{ "EA List Length", "smb.ea.list_length", FT_UINT32, BASE_DEC,
NULL, 0, "Total length of extended attributes", HFILL }},
{ &hf_smb_ea_flags,
{ "EA Flags", "smb.ea.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ea_name_length,
{ "EA Name Length", "smb.ea.name_length", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ea_data_length,
{ "EA Data Length", "smb.ea.data_length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ea_name,
{ "EA Name", "smb.ea.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ea_data,
{ "EA Data", "smb.ea.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_file_name_len,
{ "File Name Len", "smb.file_name_len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of File Name", HFILL }},
{ &hf_smb_nt_impersonation_level,
{ "Impersonation", "smb.impersonation.level", FT_UINT32, BASE_DEC,
VALS(impersonation_level_vals), 0, "Impersonation level", HFILL }},
{ &hf_smb_nt_security_flags_context_tracking,
{ "Context Tracking", "smb.security.flags.context_tracking", FT_BOOLEAN, 8,
TFS(&tfs_nt_security_flags_context_tracking), 0x01, "Is security tracking static or dynamic?", HFILL }},
{ &hf_smb_nt_security_flags_effective_only,
{ "Effective Only", "smb.security.flags.effective_only", FT_BOOLEAN, 8,
TFS(&tfs_nt_security_flags_effective_only), 0x02, "Are only enabled or all aspects uf the users SID available?", HFILL }},
{ &hf_smb_nt_access_mask_generic_read,
{ "Generic Read", "smb.access.generic_read", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_generic_read), 0x80000000, "Is generic read allowed for this object?", HFILL }},
{ &hf_smb_nt_access_mask_generic_write,
{ "Generic Write", "smb.access.generic_write", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_generic_write), 0x40000000, "Is generic write allowed for this object?", HFILL }},
{ &hf_smb_nt_access_mask_generic_execute,
{ "Generic Execute", "smb.access.generic_execute", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_generic_execute), 0x20000000, "Is generic execute allowed for this object?", HFILL }},
{ &hf_smb_nt_access_mask_generic_all,
{ "Generic All", "smb.access.generic_all", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_generic_all), 0x10000000, "Is generic all allowed for this attribute", HFILL }},
{ &hf_smb_nt_access_mask_maximum_allowed,
{ "Maximum Allowed", "smb.access.maximum_allowed", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_maximum_allowed), 0x02000000, "?", HFILL }},
{ &hf_smb_nt_access_mask_system_security,
{ "System Security", "smb.access.system_security", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_system_security), 0x01000000, "Access to a system ACL?", HFILL }},
{ &hf_smb_nt_access_mask_synchronize,
{ "Synchronize", "smb.access.synchronize", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_synchronize), 0x00100000, "Windows NT: synchronize access", HFILL }},
{ &hf_smb_nt_access_mask_write_owner,
{ "Write Owner", "smb.access.write_owner", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_write_owner), 0x00080000, "Can owner write to the object?", HFILL }},
{ &hf_smb_nt_access_mask_write_dac,
{ "Write DAC", "smb.access.write_dac", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_write_dac), 0x00040000, "Is write allowed to the owner group or ACLs?", HFILL }},
{ &hf_smb_nt_access_mask_read_control,
{ "Read Control", "smb.access.read_control", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_read_control), 0x00020000, "Are reads allowed of owner, group and ACL data of the SID?", HFILL }},
{ &hf_smb_nt_access_mask_delete,
{ "Delete", "smb.access.delete", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_delete), 0x00010000, "Can object be deleted", HFILL }},
{ &hf_smb_nt_access_mask_write_attributes,
{ "Write Attributes", "smb.access.write_attributes", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_write_attributes), 0x00000100, "Can object's attributes be written", HFILL }},
{ &hf_smb_nt_access_mask_read_attributes,
{ "Read Attributes", "smb.access.read_attributes", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_read_attributes), 0x00000080, "Can object's attributes be read", HFILL }},
{ &hf_smb_nt_access_mask_delete_child,
{ "Delete Child", "smb.access.delete_child", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_delete_child), 0x00000040, "Can object's subdirectories be deleted", HFILL }},
{ &hf_smb_nt_access_mask_execute,
{ "Execute", "smb.access.execute", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_execute), 0x00000020, "Can object be executed (if file) or traversed (if directory)", HFILL }},
{ &hf_smb_nt_access_mask_write_ea,
{ "Write EA", "smb.access.write_ea", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_write_ea), 0x00000010, "Can object's extended attributes be written", HFILL }},
{ &hf_smb_nt_access_mask_read_ea,
{ "Read EA", "smb.access.read_ea", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_read_ea), 0x00000008, "Can object's extended attributes be read", HFILL }},
{ &hf_smb_nt_access_mask_append,
{ "Append", "smb.access.append", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_append), 0x00000004, "Can object's contents be appended to", HFILL }},
{ &hf_smb_nt_access_mask_write,
{ "Write", "smb.access.write", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_write), 0x00000002, "Can object's contents be written", HFILL }},
{ &hf_smb_nt_access_mask_read,
{ "Read", "smb.access.read", FT_BOOLEAN, 32,
TFS(&tfs_nt_access_mask_read), 0x00000001, "Can object's contents be read", HFILL }},
{ &hf_smb_nt_create_bits_oplock,
{ "Exclusive Oplock", "smb.nt.create.oplock", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_bits_oplock), 0x00000002, "Is an oplock requested", HFILL }},
{ &hf_smb_nt_create_bits_boplock,
{ "Batch Oplock", "smb.nt.create.batch_oplock", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_bits_boplock), 0x00000004, "Is a batch oplock requested?", HFILL }},
{ &hf_smb_nt_create_bits_dir,
{ "Create Directory", "smb.nt.create.dir", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_bits_dir), 0x00000008, "Must target of open be a directory?", HFILL }},
{ &hf_smb_nt_create_bits_ext_resp,
{ "Extended Response", "smb.nt.create.ext", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_bits_ext_resp), 0x00000010, "Extended response required?", HFILL }},
{ &hf_smb_nt_create_options_directory_file,
{ "Directory", "smb.nt.create_options.directory", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_directory), 0x00000001, "Should file being opened/created be a directory?", HFILL }},
{ &hf_smb_nt_create_options_write_through,
{ "Write Through", "smb.nt.create_options.write_through", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_write_through), 0x00000002, "Should writes to the file write buffered data out before completing?", HFILL }},
{ &hf_smb_nt_create_options_sequential_only,
{ "Sequential Only", "smb.nt.create_options.sequential_only", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_sequential_only), 0x00000004, "Will access to this file only be sequential?", HFILL }},
{ &hf_smb_nt_create_options_no_intermediate_buffering,
{ "Intermediate Buffering", "smb.nt.create_options.intermediate_buffering", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_no_intermediate_buffering), 0x00000008, "Is intermediate buffering allowed?", HFILL }},
{ &hf_smb_nt_create_options_sync_io_alert,
{ "Sync I/O Alert", "smb.nt.create_options.sync_io_alert", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_sync_io_alert), 0x00000010, "All operations are performed synchronous", HFILL}},
{ &hf_smb_nt_create_options_sync_io_nonalert,
{ "Sync I/O Nonalert", "smb.nt.create_options.sync_io_nonalert", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_sync_io_nonalert), 0x00000020, "All operations are synchronous and may block", HFILL}},
{ &hf_smb_nt_create_options_non_directory_file,
{ "Non-Directory", "smb.nt.create_options.non_directory", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_non_directory), 0x00000040, "Should file being opened/created be a non-directory?", HFILL }},
{ &hf_smb_nt_create_options_create_tree_connection,
{ "Create Tree Connection", "smb.nt.create_options.create_tree_connection", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_create_tree_connection), 0x00000080, "Create Tree Connection flag", HFILL }},
{ &hf_smb_nt_create_options_complete_if_oplocked,
{ "Complete If Oplocked", "smb.nt.create_options.complete_if_oplocked", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_complete_if_oplocked), 0x00000100, "Complete if oplocked flag", HFILL }},
{ &hf_smb_nt_create_options_no_ea_knowledge,
{ "No EA Knowledge", "smb.nt.create_options.no_ea_knowledge", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_no_ea_knowledge), 0x00000200, "Does the client not understand extended attributes?", HFILL }},
{ &hf_smb_nt_create_options_eight_dot_three_only,
{ "8.3 Only", "smb.nt.create_options.eight_dot_three_only", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_eight_dot_three_only), 0x00000400, "Does the client understand only 8.3 filenames?", HFILL }},
{ &hf_smb_nt_create_options_random_access,
{ "Random Access", "smb.nt.create_options.random_access", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_random_access), 0x00000800, "Will the client be accessing the file randomly?", HFILL }},
{ &hf_smb_nt_create_options_delete_on_close,
{ "Delete On Close", "smb.nt.create_options.delete_on_close", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_delete_on_close), 0x00001000, "Should the file be deleted when closed?", HFILL }},
{ &hf_smb_nt_create_options_open_by_fileid,
{ "Open By FileID", "smb.nt.create_options.open_by_fileid", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_open_by_fileid), 0x00002000, "Open file by inode", HFILL }},
{ &hf_smb_nt_create_options_backup_intent,
{ "Backup Intent", "smb.nt.create_options.backup_intent", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_backup_intent), 0x00004000, "Is this opened by BACKUP ADMIN for backup intent?", HFILL }},
{ &hf_smb_nt_create_options_no_compression,
{ "No Compression", "smb.nt.create_options.no_compression", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_no_compression), 0x00008000, "Is compression allowed?", HFILL }},
{ &hf_smb_nt_create_options_reserve_opfilter,
{ "Reserve Opfilter", "smb.nt.create_options.reserve_opfilter", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_reserve_opfilter), 0x00100000, "Reserve Opfilter flag", HFILL }},
{ &hf_smb_nt_create_options_open_reparse_point,
{ "Open Reparse Point", "smb.nt.create_options.open_reparse_point", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_open_reparse_point), 0x00200000, "Is this an open of a reparse point or of the normal file?", HFILL }},
{ &hf_smb_nt_create_options_open_no_recall,
{ "Open No Recall", "smb.nt.create_options.open_no_recall", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_open_no_recall), 0x00400000, "Open no recall flag", HFILL }},
{ &hf_smb_nt_create_options_open_for_free_space_query,
{ "Open For Free Space query", "smb.nt.create_options.open_for_free_space_query", FT_BOOLEAN, 32,
TFS(&tfs_nt_create_options_open_for_free_space_query), 0x00800000, "Open For Free Space Query flag", HFILL }},
{ &hf_smb_nt_share_access_read,
{ "Read", "smb.share.access.read", FT_BOOLEAN, 32,
TFS(&tfs_nt_share_access_read), SHARE_ACCESS_READ, "Can the object be shared for reading?", HFILL }},
{ &hf_smb_nt_share_access_write,
{ "Write", "smb.share.access.write", FT_BOOLEAN, 32,
TFS(&tfs_nt_share_access_write), SHARE_ACCESS_WRITE, "Can the object be shared for write?", HFILL }},
{ &hf_smb_nt_share_access_delete,
{ "Delete", "smb.share.access.delete", FT_BOOLEAN, 32,
TFS(&tfs_nt_share_access_delete), SHARE_ACCESS_DELETE, NULL, HFILL }},
{ &hf_smb_file_eattr_read_only,
{ "Read Only", "smb.file_attribute.read_only", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_read_only), SMB_FILE_ATTRIBUTE_READ_ONLY, "READ ONLY file attribute", HFILL }},
{ &hf_smb_file_eattr_hidden,
{ "Hidden", "smb.file_attribute.hidden", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_hidden), SMB_FILE_ATTRIBUTE_HIDDEN, "HIDDEN file attribute", HFILL }},
{ &hf_smb_file_eattr_system,
{ "System", "smb.file_attribute.system", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_system), SMB_FILE_ATTRIBUTE_SYSTEM, "SYSTEM file attribute", HFILL }},
{ &hf_smb_file_eattr_volume,
{ "Volume ID", "smb.file_attribute.volume", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_volume), SMB_FILE_ATTRIBUTE_VOLUME, "VOLUME file attribute", HFILL }},
{ &hf_smb_file_eattr_directory,
{ "Directory", "smb.file_attribute.directory", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_directory), SMB_FILE_ATTRIBUTE_DIRECTORY, "DIRECTORY file attribute", HFILL }},
{ &hf_smb_file_eattr_archive,
{ "Archive", "smb.file_attribute.archive", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_archive), SMB_FILE_ATTRIBUTE_ARCHIVE, "ARCHIVE file attribute", HFILL }},
{ &hf_smb_file_eattr_device,
{ "Device", "smb.file_attribute.device", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_device), SMB_FILE_ATTRIBUTE_DEVICE, "Is this file a device?", HFILL }},
{ &hf_smb_file_eattr_normal,
{ "Normal", "smb.file_attribute.normal", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_normal), SMB_FILE_ATTRIBUTE_NORMAL, "Is this a normal file?", HFILL }},
{ &hf_smb_file_eattr_temporary,
{ "Temporary", "smb.file_attribute.temporary", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_temporary), SMB_FILE_ATTRIBUTE_TEMPORARY, "Is this a temporary file?", HFILL }},
{ &hf_smb_file_eattr_sparse,
{ "Sparse", "smb.file_attribute.sparse", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_sparse), SMB_FILE_ATTRIBUTE_SPARSE, "Is this a sparse file?", HFILL }},
{ &hf_smb_file_eattr_reparse,
{ "Reparse Point", "smb.file_attribute.reparse", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_reparse), SMB_FILE_ATTRIBUTE_REPARSE, "Does this file have an associated reparse point?", HFILL }},
{ &hf_smb_file_eattr_compressed,
{ "Compressed", "smb.file_attribute.compressed", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_compressed), SMB_FILE_ATTRIBUTE_COMPRESSED, "Is this file compressed?", HFILL }},
{ &hf_smb_file_eattr_offline,
{ "Offline", "smb.file_attribute.offline", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_offline), SMB_FILE_ATTRIBUTE_OFFLINE, "Is this file offline?", HFILL }},
{ &hf_smb_file_eattr_not_content_indexed,
{ "Content Indexed", "smb.file_attribute.not_content_indexed", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_not_content_indexed), SMB_FILE_ATTRIBUTE_NOT_CONTENT_INDEXED, "May this file be indexed by the content indexing service", HFILL }},
{ &hf_smb_file_eattr_encrypted,
{ "Encrypted", "smb.file_attribute.encrypted", FT_BOOLEAN, 32,
TFS(&tfs_file_attribute_encrypted), SMB_FILE_ATTRIBUTE_ENCRYPTED, "Is this file encrypted?", HFILL }},
{ &hf_smb_sec_desc_len,
{ "NT Security Descriptor Length", "smb.sec_desc_len", FT_UINT32, BASE_DEC,
NULL, 0, "Security Descriptor Length", HFILL }},
{ &hf_smb_nt_qsd_owner,
{ "Owner", "smb.nt_qsd.owner", FT_BOOLEAN, 32,
TFS(&tfs_nt_qsd_owner), NT_QSD_OWNER, "Is owner security information being queried?", HFILL }},
{ &hf_smb_nt_qsd_group,
{ "Group", "smb.nt_qsd.group", FT_BOOLEAN, 32,
TFS(&tfs_nt_qsd_group), NT_QSD_GROUP, "Is group security information being queried?", HFILL }},
{ &hf_smb_nt_qsd_dacl,
{ "DACL", "smb.nt_qsd.dacl", FT_BOOLEAN, 32,
TFS(&tfs_nt_qsd_dacl), NT_QSD_DACL, "Is DACL security information being queried?", HFILL }},
{ &hf_smb_nt_qsd_sacl,
{ "SACL", "smb.nt_qsd.sacl", FT_BOOLEAN, 32,
TFS(&tfs_nt_qsd_sacl), NT_QSD_SACL, "Is SACL security information being queried?", HFILL }},
{ &hf_smb_extended_attributes,
{ "Extended Attributes", "smb.ext_attr", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_oplock_level,
{ "Oplock level", "smb.oplock.level", FT_UINT8, BASE_DEC,
VALS(oplock_level_vals), 0, "Level of oplock granted", HFILL }},
{ &hf_smb_create_action,
{ "Create action", "smb.create.action", FT_UINT32, BASE_DEC,
VALS(oa_open_vals), 0, "Type of action taken", HFILL }},
{ &hf_smb_file_id,
{ "Server unique file ID", "smb.create.file_id", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_file_id_64bit,
{ "Server unique 64-bit file ID", "smb.create.file_id_64b", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ea_error_offset,
{ "EA Error offset", "smb.ea.error_offset", FT_UINT32, BASE_DEC,
NULL, 0, "Offset into EA list if EA error", HFILL }},
{ &hf_smb_end_of_file,
{ "End Of File", "smb.end_of_file", FT_UINT64, BASE_DEC,
NULL, 0, "Offset to the first free byte in the file", HFILL }},
{ &hf_smb_replace,
{ "Replace", "smb.replace", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_smb_replace), 0x0, "Remove target if it exists?", HFILL }},
{ &hf_smb_root_dir_handle,
{ "Root Directory Handle", "smb.root_dir_handle", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_target_name_len,
{ "Target name length", "smb.target_name_len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of target file name", HFILL }},
{ &hf_smb_target_name,
{ "Target name", "smb.target_name", FT_STRING, BASE_NONE,
NULL, 0, "Target file name", HFILL }},
{ &hf_smb_device_type,
{ "Device Type", "smb.device.type", FT_UINT32, BASE_HEX,
VALS(device_type_vals), 0, "Type of device", HFILL }},
{ &hf_smb_is_directory,
{ "Is Directory", "smb.is_directory", FT_UINT8, BASE_DEC,
VALS(is_directory_vals), 0, "Is this object a directory?", HFILL }},
{ &hf_smb_next_entry_offset,
{ "Next Entry Offset", "smb.next_entry_offset", FT_UINT32, BASE_DEC,
NULL, 0, "Offset to next entry", HFILL }},
{ &hf_smb_change_time,
{ "Change", "smb.change.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Last Change Time", HFILL }},
{ &hf_smb_setup_len,
{ "Setup Len", "smb.print.setup.len", FT_UINT16, BASE_DEC,
NULL, 0, "Length of printer setup data", HFILL }},
{ &hf_smb_print_mode,
{ "Mode", "smb.print.mode", FT_UINT16, BASE_DEC,
VALS(print_mode_vals), 0, "Text or Graphics mode", HFILL }},
{ &hf_smb_print_identifier,
{ "Identifier", "smb.print.identifier", FT_STRING, BASE_NONE,
NULL, 0, "Identifier string for this print job", HFILL }},
{ &hf_smb_restart_index,
{ "Restart Index", "smb.print.restart_index", FT_UINT16, BASE_DEC,
NULL, 0, "Index of entry after last returned", HFILL }},
{ &hf_smb_print_queue_date,
{ "Queued", "smb.print.queued.date", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Date when this entry was queued", HFILL }},
{ &hf_smb_print_queue_dos_date,
{ "Queued Date", "smb.print.queued.smb.date", FT_UINT16, BASE_HEX,
NULL, 0, "Date when this print job was queued, SMB_DATE format", HFILL }},
{ &hf_smb_print_queue_dos_time,
{ "Queued Time", "smb.print.queued.smb.time", FT_UINT16, BASE_HEX,
NULL, 0, "Time when this print job was queued, SMB_TIME format", HFILL }},
{ &hf_smb_print_status,
{ "Status", "smb.print.status", FT_UINT8, BASE_HEX,
VALS(print_status_vals), 0, "Status of this entry", HFILL }},
{ &hf_smb_print_spool_file_number,
{ "Spool File Number", "smb.print.spool.file_number", FT_UINT16, BASE_DEC,
NULL, 0, "Spool File Number, assigned by the spooler", HFILL }},
{ &hf_smb_print_spool_file_size,
{ "Spool File Size", "smb.print.spool.file_size", FT_UINT32, BASE_DEC,
NULL, 0, "Number of bytes in spool file", HFILL }},
{ &hf_smb_print_spool_file_name,
{ "Name", "smb.print.spool.name", FT_STRINGZ, BASE_NONE,
NULL, 0, "Name of client that submitted this job", HFILL }},
{ &hf_smb_start_index,
{ "Start Index", "smb.print.start_index", FT_UINT16, BASE_DEC,
NULL, 0, "First queue entry to return", HFILL }},
{ &hf_smb_originator_name,
{ "Originator Name", "smb.originator_name", FT_STRINGZ, BASE_NONE,
NULL, 0, "Name of sender of message", HFILL }},
{ &hf_smb_destination_name,
{ "Destination Name", "smb.destination_name", FT_STRINGZ, BASE_NONE,
NULL, 0, "Name of recipient of message", HFILL }},
{ &hf_smb_message_len,
{ "Message Len", "smb.message.len", FT_UINT16, BASE_DEC,
NULL, 0, "Length of message", HFILL }},
{ &hf_smb_message,
{ "Message", "smb.message", FT_STRING, BASE_NONE,
NULL, 0, "Message text", HFILL }},
{ &hf_smb_mgid,
{ "Message Group ID", "smb.mgid", FT_UINT16, BASE_DEC,
NULL, 0, "Message group ID for multi-block messages", HFILL }},
{ &hf_smb_forwarded_name,
{ "Forwarded Name", "smb.forwarded_name", FT_STRINGZ, BASE_NONE,
NULL, 0, "Recipient name being forwarded", HFILL }},
{ &hf_smb_machine_name,
{ "Machine Name", "smb.machine_name", FT_STRINGZ, BASE_NONE,
NULL, 0, "Name of target machine", HFILL }},
{ &hf_smb_cancel_to,
{ "Cancel to", "smb.cancel_to", FT_FRAMENUM, BASE_NONE,
NULL, 0, "This packet is a cancellation of the packet in this frame", HFILL }},
{ &hf_smb_trans_name,
{ "Transaction Name", "smb.trans_name", FT_STRING, BASE_NONE,
NULL, 0, "Name of transaction", HFILL }},
{ &hf_smb_transaction_flags_dtid,
{ "Disconnect TID", "smb.transaction.flags.dtid", FT_BOOLEAN, 16,
TFS(&tfs_tf_dtid), 0x0001, "Disconnect TID?", HFILL }},
{ &hf_smb_transaction_flags_owt,
{ "One Way Transaction", "smb.transaction.flags.owt", FT_BOOLEAN, 16,
TFS(&tfs_tf_owt), 0x0002, "One Way Transaction (no response)?", HFILL }},
{ &hf_smb_search_count,
{ "Search Count", "smb.search_count", FT_UINT16, BASE_DEC,
NULL, 0, "Maximum number of search entries to return", HFILL }},
{ &hf_smb_search_pattern,
{ "Search Pattern", "smb.search_pattern", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_ff2_backup,
{ "Backup Intent", "smb.find_first2.flags.backup", FT_BOOLEAN, 16,
TFS(&tfs_ff2_backup), 0x0010, "Find with backup intent", HFILL }},
{ &hf_smb_ff2_continue,
{ "Continue", "smb.find_first2.flags.continue", FT_BOOLEAN, 16,
TFS(&tfs_ff2_continue), 0x0008, "Continue search from previous ending place", HFILL }},
{ &hf_smb_ff2_resume,
{ "Resume", "smb.find_first2.flags.resume", FT_BOOLEAN, 16,
TFS(&tfs_ff2_resume), FF2_RESUME, "Return resume keys for each entry found", HFILL }},
{ &hf_smb_ff2_close_eos,
{ "Close on EOS", "smb.find_first2.flags.eos", FT_BOOLEAN, 16,
TFS(&tfs_ff2_close_eos), 0x0002, "Close search if end of search reached", HFILL }},
{ &hf_smb_ff2_close,
{ "Close", "smb.find_first2.flags.close", FT_BOOLEAN, 16,
TFS(&tfs_ff2_close), 0x0001, "Close search after this request", HFILL }},
{ &hf_smb_ff2_information_level,
{ "Level of Interest", "smb.ff2_loi", FT_UINT16, BASE_DEC,
VALS(ff2_il_vals), 0, "Level of interest for FIND_FIRST2 command", HFILL }},
{ &hf_smb_qpi_loi,
{ "Level of Interest", "smb.qpi_loi", FT_UINT16, BASE_DEC,
VALS(qpi_loi_vals), 0, "Level of interest for TRANSACTION[2] QUERY_{FILE,PATH}_INFO commands", HFILL }},
{ &hf_smb_spi_loi,
{ "Level of Interest", "smb.spi_loi", FT_UINT16, BASE_DEC,
VALS(spi_loi_vals), 0, "Level of interest for TRANSACTION[2] SET_{FILE,PATH}_INFO commands", HFILL }},
#if 0
{ &hf_smb_sfi_writetru,
{ "Writethrough", "smb.sfi_writethrough", FT_BOOLEAN, 16,
TFS(&tfs_da_writetru), 0x0010, "Writethrough mode?", HFILL }},
{ &hf_smb_sfi_caching,
{ "Caching", "smb.sfi_caching", FT_BOOLEAN, 16,
TFS(&tfs_da_caching), 0x0020, "Caching mode?", HFILL }},
#endif
{ &hf_smb_storage_type,
{ "Storage Type", "smb.storage_type", FT_UINT32, BASE_DEC,
NULL, 0, "Type of storage", HFILL }},
{ &hf_smb_resume,
{ "Resume Key", "smb.resume", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_max_referral_level,
{ "Max Referral Level", "smb.max_referral_level", FT_UINT16, BASE_DEC,
NULL, 0, "Latest referral version number understood", HFILL }},
{ &hf_smb_qfsi_information_level,
{ "Level of Interest", "smb.qfsi_loi", FT_UINT16, BASE_HEX,
VALS(qfsi_vals), 0, "Level of interest for QUERY_FS_INFORMATION2 command", HFILL }},
{ &hf_smb_sfsi_information_level,
{ "Level of Interest", "smb.sfsi_loi", FT_UINT16, BASE_HEX,
VALS(sfsi_vals), 0, "Level of interest for SET_FS_INFORMATION2 command", HFILL }},
{ &hf_smb_nt_rename_level,
{ "Level of Interest", "smb.ntr_loi", FT_UINT16, BASE_DEC,
VALS(nt_rename_vals), 0, "NT Rename level", HFILL }},
{ &hf_smb_cluster_count,
{ "Cluster count", "smb.ntr_clu", FT_UINT32, BASE_DEC,
NULL, 0, "Number of clusters", HFILL }},
{ &hf_smb_number_of_links,
{ "Link Count", "smb.link_count", FT_UINT32, BASE_DEC,
NULL, 0, "Number of hard links to the file", HFILL }},
{ &hf_smb_delete_pending,
{ "Delete Pending", "smb.delete_pending", FT_UINT16, BASE_DEC,
VALS(delete_pending_vals), 0, "Is this object about to be deleted?", HFILL }},
{ &hf_smb_index_number,
{ "Index Number", "smb.index_number", FT_UINT64, BASE_HEX,
NULL, 0, "File system unique identifier", HFILL }},
{ &hf_smb_position,
{ "Position", "smb.position", FT_UINT64, BASE_DEC,
NULL, 0, "File position", HFILL }},
{ &hf_smb_current_offset,
{ "Current Offset", "smb.offset", FT_UINT64, BASE_DEC,
NULL, 0, "Current offset in the file", HFILL }},
{ &hf_smb_t2_alignment,
{ "Alignment", "smb.alignment", FT_UINT32, BASE_DEC,
VALS(alignment_vals), 0, "What alignment do we require for buffers", HFILL }},
{ &hf_smb_t2_stream_name_length,
{ "Stream Name Length", "smb.stream_name_len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of stream name", HFILL }},
{ &hf_smb_t2_stream_size,
{ "Stream Size", "smb.stream_size", FT_UINT64, BASE_DEC,
NULL, 0, "Size of the stream in number of bytes", HFILL }},
{ &hf_smb_t2_stream_name,
{ "Stream Name", "smb.stream_name", FT_STRING, BASE_NONE,
NULL, 0, "Name of the stream", HFILL }},
{ &hf_smb_t2_compressed_file_size,
{ "Compressed Size", "smb.compressed.file_size", FT_UINT64, BASE_DEC,
NULL, 0, "Size of the compressed file", HFILL }},
{ &hf_smb_t2_compressed_format,
{ "Compression Format", "smb.compressed.format", FT_UINT16, BASE_DEC,
NULL, 0, "Compression algorithm used", HFILL }},
{ &hf_smb_t2_compressed_unit_shift,
{ "Unit Shift", "smb.compressed.unit_shift", FT_UINT8, BASE_DEC,
NULL, 0, "Size of the stream in number of bytes", HFILL }},
{ &hf_smb_t2_compressed_chunk_shift,
{ "Chunk Shift", "smb.compressed.chunk_shift", FT_UINT8, BASE_DEC,
NULL, 0, "Allocated size of the stream in number of bytes", HFILL }},
{ &hf_smb_t2_compressed_cluster_shift,
{ "Cluster Shift", "smb.compressed.cluster_shift", FT_UINT8, BASE_DEC,
NULL, 0, "Allocated size of the stream in number of bytes", HFILL }},
{ &hf_smb_t2_marked_for_deletion,
{ "Marked for Deletion", "smb.marked_for_deletion", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_marked_for_deletion), 0x0, "Marked for deletion?", HFILL }},
{ &hf_smb_dfs_path_consumed,
{ "Path Consumed", "smb.dfs.path_consumed", FT_UINT16, BASE_DEC,
NULL, 0, "Number of RequestFilename bytes client", HFILL }},
{ &hf_smb_dfs_num_referrals,
{ "Num Referrals", "smb.dfs.num_referrals", FT_UINT16, BASE_DEC,
NULL, 0, "Number of referrals in this pdu", HFILL }},
{ &hf_smb_get_dfs_server_hold_storage,
{ "Hold Storage", "smb.dfs.flags.server_hold_storage", FT_BOOLEAN, 16,
TFS(&tfs_get_dfs_server_hold_storage), 0x02, "The servers in referrals should hold storage for the file", HFILL }},
{ &hf_smb_get_dfs_fielding,
{ "Fielding", "smb.dfs.flags.fielding", FT_BOOLEAN, 16,
TFS(&tfs_get_dfs_fielding), 0x01, "The servers in referrals are capable of fielding", HFILL }},
{ &hf_smb_dfs_referral_version,
{ "Version", "smb.dfs.referral.version", FT_UINT16, BASE_DEC,
NULL, 0, "Version of referral element", HFILL }},
{ &hf_smb_dfs_referral_size,
{ "Size", "smb.dfs.referral.size", FT_UINT16, BASE_DEC,
NULL, 0, "Size of referral element", HFILL }},
{ &hf_smb_dfs_referral_server_type,
{ "Server Type", "smb.dfs.referral.server.type", FT_UINT16, BASE_DEC,
VALS(dfs_referral_server_type_vals), 0, "Type of referral server", HFILL }},
{ &hf_smb_dfs_referral_flags_name_list_referral,
{ "NameListReferral", "smb.dfs.referral.flags.name_list_referral", FT_BOOLEAN, 16,
TFS(&tfs_dfs_referral_flags_name_list_referral), REFENT_FLAGS_NAME_LIST_REFERRAL, "Is a domain/DC referral response?", HFILL }},
{ &hf_smb_dfs_referral_flags_target_set_boundary,
{ "TargetSetBoundary", "smb.dfs.referral.flags.target_set_boundary", FT_BOOLEAN, 16,
TFS(&tfs_dfs_referral_flags_target_set_boundary), REFENT_FLAGS_TARGET_SET_BOUNDARY, "Is this a first target in the target set?", HFILL }},
{ &hf_smb_dfs_referral_node_offset,
{ "Node Offset", "smb.dfs.referral.node_offset", FT_UINT16, BASE_DEC,
NULL, 0, "Offset of name of entity to visit next", HFILL }},
{ &hf_smb_dfs_referral_node,
{ "Node", "smb.dfs.referral.node", FT_STRING, BASE_NONE,
NULL, 0, "Name of entity to visit next", HFILL }},
{ &hf_smb_dfs_referral_proximity,
{ "Proximity", "smb.dfs.referral.proximity", FT_UINT32, BASE_DEC,
NULL, 0, "Hint describing proximity of this server to the client", HFILL }},
{ &hf_smb_dfs_referral_ttl,
{ "TTL", "smb.dfs.referral.ttl", FT_UINT32, BASE_DEC,
NULL, 0, "Number of seconds the client can cache this referral", HFILL }},
{ &hf_smb_dfs_referral_path_offset,
{ "Path Offset", "smb.dfs.referral.path_offset", FT_UINT16, BASE_DEC,
NULL, 0, "Offset of Dfs Path that matched pathconsumed", HFILL }},
{ &hf_smb_dfs_referral_path,
{ "Path", "smb.dfs.referral.path", FT_STRING, BASE_NONE,
NULL, 0, "Dfs Path that matched pathconsumed", HFILL }},
{ &hf_smb_dfs_referral_alt_path_offset,
{ "Alt Path Offset", "smb.dfs.referral.alt_path_offset", FT_UINT16, BASE_DEC,
NULL, 0, "Offset of alternative(8.3) Path that matched pathconsumed", HFILL }},
{ &hf_smb_dfs_referral_alt_path,
{ "Alt Path", "smb.dfs.referral.alt_path", FT_STRING, BASE_NONE,
NULL, 0, "Alternative(8.3) Path that matched pathconsumed", HFILL }},
{ &hf_smb_dfs_referral_domain_offset,
{ "Domain Offset", "smb.dfs.referral.domain_offset", FT_UINT16, BASE_DEC,
NULL, 0, "Offset of Dfs Path that matched pathconsumed", HFILL }},
{ &hf_smb_dfs_referral_number_of_expnames,
{ "Number of Expanded Names", "smb.dfs.referral.number_of_expnames", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_dfs_referral_expnames_offset,
{ "Expanded Names Offset", "smb.dfs.referral.expnames_offset", FT_UINT16, BASE_DEC,
NULL, 0, "Offset of Dfs Path that matched pathconsumed", HFILL }},
{ &hf_smb_dfs_referral_domain_name,
{ "Domain Name", "smb.dfs.referral.domain_name", FT_STRING, BASE_NONE,
NULL, 0, "Dfs referral domain name", HFILL }},
{ &hf_smb_dfs_referral_expname,
{ "Expanded Name", "smb.dfs.referral.expname", FT_STRING, BASE_NONE,
NULL, 0, "Dfs expanded name", HFILL }},
{ &hf_smb_dfs_referral_server_guid,
{ "Server GUID", "smb.dfs.referral.server_guid", FT_GUID, BASE_NONE,
NULL, 0, "Globally unique identifier for this server", HFILL }},
{ &hf_smb_end_of_search,
{ "End Of Search", "smb.end_of_search", FT_UINT16, BASE_DEC,
NULL, 0, "Was last entry returned?", HFILL }},
{ &hf_smb_last_name_offset,
{ "Last Name Offset", "smb.last_name_offset", FT_UINT16, BASE_DEC,
NULL, 0, "If non-0 this is the offset into the datablock for the file name of the last entry", HFILL }},
{ &hf_smb_fn_information_level,
{ "Level of Interest", "smb.fn_loi", FT_UINT16, BASE_DEC,
NULL, 0, "Level of interest for FIND_NOTIFY command", HFILL }},
{ &hf_smb_monitor_handle,
{ "Monitor Handle", "smb.monitor_handle", FT_UINT16, BASE_HEX,
NULL, 0, "Handle for Find Notify operations", HFILL }},
{ &hf_smb_change_count,
{ "Change Count", "smb.change_count", FT_UINT16, BASE_DEC,
NULL, 0, "Number of changes to wait for", HFILL }},
{ &hf_smb_file_index,
{ "File Index", "smb.file_index", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_short_file_name,
{ "Short File Name", "smb.short_file", FT_STRING, BASE_NONE,
NULL, 0, "Short (8.3) File Name", HFILL }},
{ &hf_smb_short_file_name_len,
{ "Short File Name Len", "smb.short_file_name_len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of Short (8.3) File Name", HFILL }},
{ &hf_smb_fs_id,
{ "FS Id", "smb.fs_id", FT_UINT32, BASE_DEC,
NULL, 0, "File System ID (NT Server always returns 0)", HFILL }},
{ &hf_smb_sector_unit,
{ "Sectors/Unit", "smb.fs_sector_per_unit", FT_UINT32, BASE_DEC,
NULL, 0, "Sectors per allocation unit", HFILL }},
{ &hf_smb_fs_units,
{ "Total Units", "smb.fs_units", FT_UINT32, BASE_DEC,
NULL, 0, "Total number of units on this filesystem", HFILL }},
{ &hf_smb_fs_sector,
{ "Bytes per Sector", "smb.fs_bytes_per_sector", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_avail_units,
{ "Available Units", "smb.avail.units", FT_UINT32, BASE_DEC,
NULL, 0, "Total number of available units on this filesystem", HFILL }},
{ &hf_smb_volume_serial_num,
{ "Volume Serial Number", "smb.volume.serial", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_volume_label_len,
{ "Label Length", "smb.volume.label.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of volume label", HFILL }},
{ &hf_smb_volume_label,
{ "Label", "smb.volume.label", FT_STRING, BASE_NONE,
NULL, 0, "Volume label", HFILL }},
{ &hf_smb_free_alloc_units64,
{ "Free Units", "smb.free_alloc_units", FT_UINT64, BASE_DEC,
NULL, 0, "Number of free allocation units", HFILL }},
{ &hf_smb_caller_free_alloc_units64,
{ "Caller Free Units", "smb.caller_free_alloc_units", FT_UINT64, BASE_DEC,
NULL, 0, "Number of caller free allocation units", HFILL }},
{ &hf_smb_actual_free_alloc_units64,
{ "Actual Free Units", "smb.actual_free_alloc_units", FT_UINT64, BASE_DEC,
NULL, 0, "Number of actual free allocation units", HFILL }},
{ &hf_smb_soft_quota_limit,
{ "(Soft) Quota Threshold", "smb.quota.soft.default", FT_UINT64, BASE_DEC,
NULL, 0, "Soft Quota threshold", HFILL }},
{ &hf_smb_hard_quota_limit,
{ "(Hard) Quota Limit", "smb.quota.hard.default", FT_UINT64, BASE_DEC,
NULL, 0, "Hard Quota limit", HFILL }},
{ &hf_smb_user_quota_used,
{ "Quota Used", "smb.quota.used", FT_UINT64, BASE_DEC,
NULL, 0, "How much Quota is used by this user", HFILL }},
{ &hf_smb_max_name_len,
{ "Max name length", "smb.fs_max_name_len", FT_UINT32, BASE_DEC,
NULL, 0, "Maximum length of each file name component in number of bytes", HFILL }},
{ &hf_smb_fs_name_len,
{ "Label Length", "smb.fs_name.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of filesystem name in bytes", HFILL }},
{ &hf_smb_fs_name,
{ "FS Name", "smb.fs_name", FT_STRING, BASE_NONE,
NULL, 0, "Name of filesystem", HFILL }},
{ &hf_smb_device_char_removable,
{ "Removable", "smb.device.removable", FT_BOOLEAN, 32,
TFS(&tfs_device_char_removable), 0x00000001, "Is this a removable device", HFILL }},
{ &hf_smb_device_char_read_only,
{ "Read Only", "smb.device.read_only", FT_BOOLEAN, 32,
TFS(&tfs_device_char_read_only), 0x00000002, "Is this a read-only device", HFILL }},
{ &hf_smb_device_char_floppy,
{ "Floppy", "smb.device.floppy", FT_BOOLEAN, 32,
TFS(&tfs_device_char_floppy), 0x00000004, "Is this a floppy disk", HFILL }},
{ &hf_smb_device_char_write_once,
{ "Write Once", "smb.device.write_once", FT_BOOLEAN, 32,
TFS(&tfs_device_char_write_once), 0x00000008, "Is this a write-once device", HFILL }},
{ &hf_smb_device_char_remote,
{ "Remote", "smb.device.remote", FT_BOOLEAN, 32,
TFS(&tfs_device_char_remote), 0x00000010, "Is this a remote device", HFILL }},
{ &hf_smb_device_char_mounted,
{ "Mounted", "smb.device.mounted", FT_BOOLEAN, 32,
TFS(&tfs_device_char_mounted), 0x00000020, "Is this a mounted device", HFILL }},
{ &hf_smb_device_char_virtual,
{ "Virtual", "smb.device.virtual", FT_BOOLEAN, 32,
TFS(&tfs_device_char_virtual), 0x00000040, "Is this a virtual device", HFILL }},
{ &hf_smb_fs_attr_css,
{ "Case Sensitive Search", "smb.fs_attr.css", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_css), 0x00000001, "Does this FS support Case Sensitive Search?", HFILL }},
{ &hf_smb_fs_attr_cpn,
{ "Case Preserving", "smb.fs_attr.cpn", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_cpn), 0x00000002, "Will this FS Preserve Name Case?", HFILL }},
{ &hf_smb_fs_attr_uod,
{ "Unicode On Disk", "smb.fs_attr.uod", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_uod), 0x00000004, "Does this FS support Unicode On Disk?", HFILL }},
{ &hf_smb_fs_attr_pacls,
{ "Persistent ACLs", "smb.fs_attr.pacls", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_pacls), 0x00000008, "Does this FS support Persistent ACLs?", HFILL }},
{ &hf_smb_fs_attr_fc,
{ "Compression", "smb.fs_attr.fc", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_fc), 0x00000010, "Does this FS support File Compression?", HFILL }},
{ &hf_smb_fs_attr_vq,
{ "Volume Quotas", "smb.fs_attr.vq", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_vq), 0x00000020, "Does this FS support Volume Quotas?", HFILL }},
{ &hf_smb_fs_attr_ssf,
{ "Sparse Files", "smb.fs_attr.ssf", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_ssf), 0x00000040, "Does this FS support SPARSE FILES?", HFILL }},
{ &hf_smb_fs_attr_srp,
{ "Reparse Points", "smb.fs_attr.srp", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_srp), 0x00000080, "Does this FS support REPARSE POINTS?", HFILL }},
{ &hf_smb_fs_attr_srs,
{ "Remote Storage", "smb.fs_attr.srs", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_srs), 0x00000100, "Does this FS support REMOTE STORAGE?", HFILL }},
{ &hf_smb_fs_attr_sla,
{ "LFN APIs", "smb.fs_attr.sla", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_sla), 0x00004000, "Does this FS support LFN APIs?", HFILL }},
{ &hf_smb_fs_attr_vic,
{ "Volume Is Compressed", "smb.fs_attr.vis", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_vic), 0x00008000, "Is this FS on a compressed volume?", HFILL }},
{ &hf_smb_fs_attr_soids,
{ "Supports OIDs", "smb.fs_attr.soids", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_soids), 0x00010000, "Does this FS support OIDs?", HFILL }},
{ &hf_smb_fs_attr_se,
{ "Supports Encryption", "smb.fs_attr.se", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_se), 0x00020000, "Does this FS support encryption?", HFILL }},
{ &hf_smb_fs_attr_ns,
{ "Named Streams", "smb.fs_attr.ns", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_ns), 0x00040000, "Does this FS support named streams?", HFILL }},
{ &hf_smb_fs_attr_rov,
{ "Read Only Volume", "smb.fs_attr.rov", FT_BOOLEAN, 32,
TFS(&tfs_fs_attr_rov), 0x00080000, "Is this FS on a read only volume?", HFILL }},
{ &hf_smb_user_quota_offset,
{ "Next Offset", "smb.quota.user.offset", FT_UINT32, BASE_DEC,
NULL, 0, "Relative offset to next user quota structure", HFILL }},
{ &hf_smb_pipe_write_len,
{ "Pipe Write Len", "smb.pipe.write_len", FT_UINT16, BASE_DEC,
NULL, 0, "Number of bytes written to pipe", HFILL }},
{ &hf_smb_quota_flags_deny_disk,
{ "Deny Disk", "smb.quota.flags.deny_disk", FT_BOOLEAN, 8,
TFS(&tfs_quota_flags_deny_disk), 0x02, "Is the default quota limit enforced?", HFILL }},
{ &hf_smb_quota_flags_log_limit,
{ "Log Limit", "smb.quota.flags.log_limit", FT_BOOLEAN, 8,
TFS(&tfs_quota_flags_log_limit), 0x20, "Should the server log an event when the limit is exceeded?", HFILL }},
{ &hf_smb_quota_flags_log_warning,
{ "Log Warning", "smb.quota.flags.log_warning", FT_BOOLEAN, 8,
TFS(&tfs_quota_flags_log_warning), 0x10, "Should the server log an event when the warning level is exceeded?", HFILL }},
{ &hf_smb_quota_flags_enabled,
{ "Enabled", "smb.quota.flags.enabled", FT_BOOLEAN, 8,
TFS(&tfs_quota_flags_enabled), 0x01, "Is quotas enabled of this FS?", HFILL }},
{ &hf_smb_segment_overlap,
{ "Fragment overlap", "smb.segment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_smb_segment_overlap_conflict,
{ "Conflicting data in fragment overlap", "smb.segment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_smb_segment_multiple_tails,
{ "Multiple tail fragments found", "smb.segment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_smb_segment_too_long_fragment,
{ "Fragment too long", "smb.segment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_smb_segment_error,
{ "Defragmentation error", "smb.segment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_smb_segment_count,
{ "Fragment count", "smb.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_smb_reassembled_length,
{ "Reassembled SMB length", "smb.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_smb_opened_in,
{ "Opened in", "smb.fid.opened_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The frame this fid was opened", HFILL }},
{ &hf_smb_closed_in,
{ "Closed in", "smb.fid.closed_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The frame this fid was closed", HFILL }},
{ &hf_smb_mapped_in,
{ "Mapped in", "smb.fid.mapped_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The frame this share was mapped", HFILL }},
{ &hf_smb_unmapped_in,
{ "Unmapped in", "smb.fid.unmapped_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The frame this share was unmapped", HFILL }},
{ &hf_smb_segment,
{ "SMB Segment", "smb.segment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_smb_segments,
{ "SMB Segments", "smb.segment.segments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_smb_unix_major_version,
{ "Major Version", "smb.unix.major_version", FT_UINT16, BASE_DEC,
NULL, 0, "UNIX Major Version", HFILL }},
{ &hf_smb_unix_minor_version,
{ "Minor Version", "smb.unix.minor_version", FT_UINT16, BASE_DEC,
NULL, 0, "UNIX Minor Version", HFILL }},
{ &hf_smb_unix_capability_fcntl,
{ "FCNTL Capability", "smb.unix.capability.fcntl", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000001, NULL, HFILL }},
{ &hf_smb_unix_capability_posix_acl,
{ "POSIX ACL Capability", "smb.unix.capability.posix_acl", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000002, NULL, HFILL }},
{ &hf_smb_file_access_mask_read_data,
{ "Read Data", "smb.file.accessmask.read_data", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000001, NULL, HFILL }},
{ &hf_smb_file_access_mask_write_data,
{ "Write Data", "smb.file.accessmask.write_data", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000002, NULL, HFILL }},
{ &hf_smb_file_access_mask_append_data,
{ "Append Data", "smb.file.accessmask.append_data", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000004, NULL, HFILL }},
{ &hf_smb_file_access_mask_read_ea,
{ "Read EA", "smb.file.accessmask.read_ea", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000008, NULL, HFILL }},
{ &hf_smb_file_access_mask_write_ea,
{ "Write EA", "smb.file.accessmask.write_ea", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000010, NULL, HFILL }},
{ &hf_smb_file_access_mask_execute,
{ "Execute", "smb.file.accessmask.execute", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000020, NULL, HFILL }},
{ &hf_smb_file_access_mask_read_attribute,
{ "Read Attribute", "smb.file.accessmask.read_attribute", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000080, NULL, HFILL }},
{ &hf_smb_file_access_mask_write_attribute,
{ "Write Attribute", "smb.file.accessmask.write_attribute", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000100, NULL, HFILL }},
{ &hf_smb_dir_access_mask_list,
{ "List", "smb.dir.accessmask.list", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000001, NULL, HFILL }},
{ &hf_smb_dir_access_mask_add_file,
{ "Add File", "smb.dir.accessmask.add_file", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000002, NULL, HFILL }},
{ &hf_smb_dir_access_mask_add_subdir,
{ "Add Subdir", "smb.dir.accessmask.add_subdir", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000004, NULL, HFILL }},
{ &hf_smb_dir_access_mask_read_ea,
{ "Read EA", "smb.dir.accessmask.read_ea", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000008, NULL, HFILL }},
{ &hf_smb_dir_access_mask_write_ea,
{ "Write EA", "smb.dir.accessmask.write_ea", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000010, NULL, HFILL }},
{ &hf_smb_dir_access_mask_traverse,
{ "Traverse", "smb.dir.accessmask.traverse", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000020, NULL, HFILL }},
{ &hf_smb_dir_access_mask_delete_child,
{ "Delete Child", "smb.dir.accessmask.delete_child", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000040, NULL, HFILL }},
{ &hf_smb_dir_access_mask_read_attribute,
{ "Read Attribute", "smb.dir.accessmask.read_attribute", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000080, NULL, HFILL }},
{ &hf_smb_dir_access_mask_write_attribute,
{ "Write Attribute", "smb.dir.accessmask.write_attribute", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000100, NULL, HFILL }},
{ &hf_smb_unix_file_link_dest,
{ "Link destination", "smb.unix.file.link_dest", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_size,
{ "File size", "smb.unix.file.size", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_num_bytes,
{ "Number of bytes", "smb.unix.file.num_bytes", FT_UINT64, BASE_DEC,
NULL, 0, "Number of bytes used to store the file", HFILL }},
{ &hf_smb_unix_file_last_status,
{ "Last status change", "smb.unix.file.stime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_last_access,
{ "Last access", "smb.unix.file.atime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_last_change,
{ "Last modification", "smb.unix.file.mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_creation_time,
{ "Creation time", "smb.unix.file.crtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_uid,
{ "UID", "smb.unix.file.uid", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_gid,
{ "GID", "smb.unix.file.gid", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_type,
{ "File type", "smb.unix.file.file_type", FT_UINT32, BASE_DEC,
VALS(unix_file_type_vals), 0, NULL, HFILL }},
{ &hf_smb_unix_file_dev_major,
{ "Major device", "smb.unix.file.dev_major", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_dev_minor,
{ "Minor device", "smb.unix.file.dev_minor", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_unique_id,
{ "Unique ID", "smb.unix.file.unique_id", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_permissions,
{ "File permissions", "smb.unix.file.perms", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_nlinks,
{ "Num links", "smb.unix.file.num_links", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags,
{ "Flags", "smb.unix_info2.file.flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_mask,
{ "Flags mask", "smb.unix_info2.file.flags_mask", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_secure_delete,
{ "Secure delete", "smb.unix_info2.file.flags.secure_delete", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_enable_undelete,
{ "Enable undelete", "smb.unix_info2.file.flags.enable_undelete", FT_BOOLEAN, 32,
NULL, 0x00000002, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_synchronous,
{ "Synchronous", "smb.unix_info2.file.flags.synchronous", FT_BOOLEAN, 32,
NULL, 0x00000004, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_immutable,
{ "Immutable", "smb.unix_info2.file.flags.immutable", FT_BOOLEAN, 32,
NULL, 0x00000008, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_append_only,
{ "Append-only", "smb.unix_info2.file.flags.append_only", FT_BOOLEAN, 32,
NULL, 0x00000010, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_do_not_backup,
{ "Do not backup", "smb.unix_info2.file.flags.do_not_backup", FT_BOOLEAN, 32,
NULL, 0x00000020, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_no_update_atime,
{ "Don't update atime", "smb.unix_info2.file.flags.no_update_atime", FT_BOOLEAN, 32,
NULL, 0x00000040, NULL, HFILL }},
{ &hf_smb_unix_info2_file_flags_hidden,
{ "Hidden", "smb.unix_info2.file.flags.hidden", FT_BOOLEAN, 32,
NULL, 0x00000080, NULL, HFILL }},
{ &hf_smb_unix_file_name_length,
{ "File name length", "smb.unix.file.name_length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_file_name,
{ "File name", "smb.unix.file.name", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_find_file_nextoffset,
{ "Next entry offset", "smb.unix.find_file.next_offset", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_unix_find_file_resumekey,
{ "Resume key", "smb.unix.find_file.resume_key", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_network_unknown,
{ "Unknown field", "smb.unknown_field", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_create_flags,
{ "Create Flags", "smb.create_flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_create_options,
{ "Create Options", "smb.create_options", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_share_access,
{ "Share Access", "smb.share_access", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_access_mask,
{ "Access Mask", "smb.access_mask", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_mode,
{ "Mode", "smb.mode", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_attribute,
{ "Attribute", "smb.attribute", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_reparse_tag,
{ "Reparse Tag", "smb.reparse_tag", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_disposition_delete_on_close,
{ "Delete on close", "smb.disposition.delete_on_close", FT_BOOLEAN, 8,
TFS(&tfs_disposition_delete_on_close), 0x01, NULL, HFILL }},
{ &hf_smb_pipe_info_flag,
{ "Pipe Info", "smb.pipe_info_flag", FT_BOOLEAN, 8,
TFS(&tfs_pipe_info_flag), 0x01, NULL, HFILL }},
{ &hf_smb_logged_in,
{ "Logged In", "smb.logged_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_logged_out,
{ "Logged Out", "smb.logged_out", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_smb_file_rw_offset,
{ "File Offset", "smb.file.rw.offset", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_file_rw_length,
{ "File RW Length", "smb.file.rw.length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_acl_version,
{ "Posix ACL version", "smb.posix_acl.version", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_num_file_aces,
{ "Number of file ACEs", "smb.posix_acl.num_file_aces", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_num_def_aces,
{ "Number of default ACEs", "smb.posix_acl.num_def_aces", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_ace_type,
{ "ACE Type", "smb.posix_acl.ace_type", FT_UINT8, BASE_DEC,
VALS(ace_type_vals), 0, NULL, HFILL }},
{ &hf_smb_posix_ace_flags,
{ "Permissions", "smb.posix_acl.ace_perms", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_ace_perm_read,
{"READ", "smb.posix_acl.ace_perms.read", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL}},
{ &hf_smb_posix_ace_perm_write,
{"WRITE", "smb.posix_acl.ace_perms.write", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_smb_posix_ace_perm_execute,
{"EXECUTE", "smb.posix_acl.ace_perms.execute", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_smb_posix_ace_perm_owner_uid,
{ "Owner UID", "smb.posix_acl.ace_perms.owner_uid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_ace_perm_owner_gid,
{ "Owner GID", "smb.posix_acl.ace_perms.owner_gid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_ace_perm_uid,
{ "UID", "smb.posix_acl.ace_perms.uid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_smb_posix_ace_perm_gid,
{ "GID", "smb.posix_acl.ace_perms.gid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_smb,
&ett_smb_fid,
&ett_smb_tid,
&ett_smb_uid,
&ett_smb_hdr,
&ett_smb_command,
&ett_smb_fileattributes,
&ett_smb_capabilities,
&ett_smb_aflags,
&ett_smb_dialect,
&ett_smb_dialects,
&ett_smb_mode,
&ett_smb_rawmode,
&ett_smb_flags,
&ett_smb_flags2,
&ett_smb_desiredaccess,
&ett_smb_search,
&ett_smb_file,
&ett_smb_openfunction,
&ett_smb_filetype,
&ett_smb_openaction,
&ett_smb_writemode,
&ett_smb_lock_type,
&ett_smb_ssetupandxaction,
&ett_smb_optionsup,
&ett_smb_time_date,
&ett_smb_move_copy_flags,
&ett_smb_file_attributes,
&ett_smb_search_resume_key,
&ett_smb_search_dir_info,
&ett_smb_unlocks,
&ett_smb_unlock,
&ett_smb_locks,
&ett_smb_lock,
&ett_smb_open_flags,
&ett_smb_ipc_state,
&ett_smb_open_action,
&ett_smb_setup_action,
&ett_smb_connect_flags,
&ett_smb_connect_support_bits,
&ett_smb_nt_access_mask,
&ett_smb_nt_create_bits,
&ett_smb_nt_create_options,
&ett_smb_nt_share_access,
&ett_smb_nt_security_flags,
&ett_smb_nt_trans_setup,
&ett_smb_nt_trans_data,
&ett_smb_nt_trans_param,
&ett_smb_nt_notify_completion_filter,
&ett_smb_nt_ioctl_flags,
&ett_smb_security_information_mask,
&ett_smb_print_queue_entry,
&ett_smb_transaction_flags,
&ett_smb_transaction_params,
&ett_smb_find_first2_flags,
#if 0
&ett_smb_ioflag,
#endif
&ett_smb_transaction_data,
&ett_smb_stream_info,
&ett_smb_dfs_referrals,
&ett_smb_dfs_referral,
&ett_smb_dfs_referral_flags,
&ett_smb_dfs_referral_expnames,
&ett_smb_get_dfs_flags,
&ett_smb_ff2_data,
&ett_smb_device_characteristics,
&ett_smb_fs_attributes,
&ett_smb_segments,
&ett_smb_segment,
&ett_smb_quotaflags,
&ett_smb_secblob,
&ett_smb_mac_support_flags,
&ett_smb_unicode_password,
&ett_smb_ea,
&ett_smb_unix_capabilities,
&ett_smb_posix_ace,
&ett_smb_posix_ace_perms,
&ett_smb_info2_file_flags
};
module_t *smb_module;
proto_smb = proto_register_protocol("SMB (Server Message Block Protocol)",
"SMB", "smb");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_smb, hf, array_length(hf));
proto_do_register_windows_common(proto_smb);
register_init_routine(&smb_init_protocol);
smb_module = prefs_register_protocol(proto_smb, NULL);
prefs_register_bool_preference(smb_module, "trans_reassembly",
"Reassemble SMB Transaction payload",
"Whether the dissector should reassemble the payload of SMB Transaction commands spanning multiple SMB PDUs",
&smb_trans_reassembly);
prefs_register_bool_preference(smb_module, "dcerpc_reassembly",
"Reassemble DCERPC over SMB",
"Whether the dissector should reassemble DCERPC over SMB commands",
&smb_dcerpc_reassembly);
prefs_register_bool_preference(smb_module, "sid_name_snooping",
"Snoop SID to Name mappings",
"Whether the dissector should snoop SMB and related CIFS protocols to discover and display Names associated with SIDs",
&sid_name_snooping);
prefs_register_bool_preference(smb_module, "sid_display_hex",
"Display SIDs in Hex",
"Whether the dissector should display SIDs and RIDs in hexadecimal rather than decimal",
&sid_display_hex);
register_init_routine(smb_trans_reassembly_init);
smb_tap = register_tap("smb");
smb_eo_tap = register_tap("smb_eo");
register_dissector("smb", dissect_smb, proto_smb);
}
void
proto_reg_handoff_smb(void)
{
dissector_handle_t smb_handle;
gssapi_handle = find_dissector("gssapi");
ntlmssp_handle = find_dissector("ntlmssp");
heur_dissector_add("netbios", dissect_smb_heur, proto_smb);
heur_dissector_add("cotp", dissect_smb_heur, proto_smb);
heur_dissector_add("vines_spp", dissect_smb_heur, proto_smb);
smb_handle = find_dissector("smb");
dissector_add_uint("ipx.socket", IPX_SOCKET_NWLINK_SMB_SERVER, smb_handle);
dissector_add_uint("ipx.socket", IPX_SOCKET_NWLINK_SMB_REDIR, smb_handle);
dissector_add_uint("ipx.socket", IPX_SOCKET_NWLINK_SMB_MESSENGER, smb_handle);
dissector_add_uint("spp.socket", IDP_SOCKET_SMB, smb_handle);
}
