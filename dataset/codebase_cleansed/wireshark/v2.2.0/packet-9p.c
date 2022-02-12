static gint _9p_hash_equal(gconstpointer k1, gconstpointer k2) {
const struct _9p_hashkey *key1 = (const struct _9p_hashkey *)k1, *key2 = (const struct _9p_hashkey *)k2;
return ((key1->conv_index == key2->conv_index) && (key1->tag == key2->tag) && (key1->fid == key2->fid));
}
static guint _9p_hash_hash(gconstpointer k)
{
const struct _9p_hashkey *key = (const struct _9p_hashkey *)k;
return (key->conv_index ^ key->tag ^ key->fid);
}
static struct _9p_hashval *_9p_hash_new_val(gsize len)
{
struct _9p_hashval *val;
val = wmem_new(wmem_file_scope(), struct _9p_hashval);
val->data = wmem_alloc(wmem_file_scope(), len);
val->len = len;
return val;
}
static void _9p_hash_init(void)
{
_9p_hashtable = wmem_map_new(wmem_file_scope(), _9p_hash_hash, _9p_hash_equal);
}
static void _9p_hash_set(packet_info *pinfo, guint16 tag, guint32 fid, struct _9p_hashval *val)
{
struct _9p_hashkey *key;
struct _9p_hashval *oldval;
conversation_t *conv;
conv = find_or_create_conversation(pinfo);
key = wmem_new(wmem_file_scope(), struct _9p_hashkey);
key->conv_index = conv->conv_index;
key->tag = tag;
key->fid = fid;
oldval = (struct _9p_hashval *)wmem_map_lookup(_9p_hashtable, key);
if (oldval) {
wmem_map_remove(_9p_hashtable, key);
}
wmem_map_insert(_9p_hashtable, key, val);
}
static struct _9p_hashval *_9p_hash_get(packet_info *pinfo, guint16 tag, guint32 fid)
{
struct _9p_hashkey key;
conversation_t *conv;
conv = find_or_create_conversation(pinfo);
key.conv_index = conv->conv_index;
key.tag = tag;
key.fid = fid;
return (struct _9p_hashval *)wmem_map_lookup(_9p_hashtable, &key);
}
static void _9p_hash_free(packet_info *pinfo, guint16 tag, guint32 fid)
{
struct _9p_hashkey key;
conversation_t *conv;
conv = find_or_create_conversation(pinfo);
key.conv_index = conv->conv_index;
key.tag = tag;
key.fid = fid;
wmem_map_remove(_9p_hashtable, &key);
}
static void conv_set_version(packet_info *pinfo, enum _9p_version version)
{
struct _9p_hashval *val;
val = _9p_hash_new_val(sizeof(enum _9p_version));
*(enum _9p_version*)val->data = version;
_9p_hash_set(pinfo, _9P_NOTAG, _9P_NOFID, val);
}
static enum _9p_version conv_get_version(packet_info *pinfo)
{
struct _9p_hashval *val;
val = _9p_hash_get(pinfo, _9P_NOTAG, _9P_NOFID);
return val ? *(enum _9p_version*)val->data : _9P;
}
static void conv_set_fid_nocopy(packet_info *pinfo, guint32 fid, const char *path)
{
struct _9p_hashval *val;
if (pinfo->fd->flags.visited || fid == _9P_NOFID)
return;
val = _9p_hash_get(pinfo, _9P_NOTAG, fid);
if (!val) {
val = _9p_hash_new_val(0);
val->data = wmem_tree_new(wmem_file_scope());
_9p_hash_set(pinfo, _9P_NOTAG, fid, val);
}
wmem_tree_insert32((wmem_tree_t *)val->data, pinfo->num, (void *)path);
}
static void conv_set_fid(packet_info *pinfo, guint32 fid, const gchar *path, gsize len)
{
char *str;
if (pinfo->fd->flags.visited || fid == _9P_NOFID || len == 0)
return;
str = (char*)wmem_alloc(wmem_file_scope(), len);
g_strlcpy(str, path, len);
conv_set_fid_nocopy(pinfo, fid, str);
}
static const char *conv_get_fid(packet_info *pinfo, guint32 fid)
{
struct _9p_hashval *val;
if (fid == _9P_NOFID)
return invalid_fid_str;
val = _9p_hash_get(pinfo, _9P_NOTAG, fid);
if (!val)
return invalid_fid_str;
return (char*)wmem_tree_lookup32_le((wmem_tree_t*)val->data, pinfo->num-1);
}
static inline void conv_free_fid(packet_info *pinfo, guint32 fid)
{
conv_set_fid_nocopy(pinfo, fid, invalid_fid_str);
}
static void conv_set_tag(packet_info *pinfo, guint16 tag, enum _9p_msg_t msgtype, guint32 fid, wmem_strbuf_t *fid_path)
{
struct _9p_hashval *val;
struct _9p_taginfo *taginfo;
if (pinfo->fd->flags.visited || tag == _9P_NOTAG)
return;
val = _9p_hash_new_val(sizeof(struct _9p_taginfo));
taginfo = (struct _9p_taginfo*)val->data;
taginfo->msgtype = msgtype;
taginfo->fid = fid;
if (fid_path) {
taginfo->fid_path = (char*)wmem_alloc(wmem_file_scope(), wmem_strbuf_get_len(fid_path)+1);
g_strlcpy(taginfo->fid_path, wmem_strbuf_get_str(fid_path), wmem_strbuf_get_len(fid_path)+1);
} else {
taginfo->fid_path = NULL;
}
_9p_hash_set(pinfo, tag, _9P_NOFID, val);
}
static inline struct _9p_taginfo *conv_get_tag(packet_info *pinfo, guint16 tag)
{
struct _9p_hashval *val;
if (pinfo->fd->flags.visited || tag == _9P_NOTAG)
return NULL;
val = _9p_hash_get(pinfo, tag, _9P_NOFID);
return val ? (struct _9p_taginfo*)val->data : NULL;
}
static inline void conv_free_tag(packet_info *pinfo, guint16 tag)
{
if (pinfo->fd->flags.visited || tag == _9P_NOTAG)
return;
_9p_hash_free(pinfo, tag, _9P_NOFID);
}
static guint _9p_dissect_string(tvbuff_t *tvb, proto_tree *ninep_tree,
guint offset, int hf_string, gint ett_string)
{
guint16 _9p_len;
proto_item *ti;
proto_tree *sub_tree;
_9p_len = tvb_get_letohs(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_string, tvb, offset + 2,
_9p_len, ENC_UTF_8|ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_string);
proto_tree_add_item(sub_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return 2 + _9p_len;
}
static int dissect_9P_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint32 u32, i, fid, dfid, newfid;
guint16 u16, tag, _9p_len;
enum _9p_msg_t ninemsg;
guint offset = 0;
const char *mname, *fid_path;
char *tvb_s;
wmem_strbuf_t *tmppath = NULL;
gint len, reportedlen;
tvbuff_t *next_tvb;
proto_item *ti, *msg_item;
proto_tree *ninep_tree;
struct _9p_taginfo *taginfo;
nstime_t tv;
int _9p_version;
_9p_version = conv_get_version(pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, val_to_str_ext_const(_9p_version, &ninep_version_ext, "9P"));
col_clear(pinfo->cinfo, COL_INFO);
ninemsg = (enum _9p_msg_t)tvb_get_guint8(tvb, offset + 4);
mname = val_to_str_ext_const(ninemsg, &ninep_msg_type_ext, "Unknown");
if(strcmp(mname, "Unknown") == 0) {
col_add_fstr(pinfo->cinfo, COL_INFO, "9P Data (Message type %u)", (guint)ninemsg);
return 0;
}
tag = tvb_get_letohs(tvb, offset+5);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s Tag=%u", mname, (guint)tag);
ti = proto_tree_add_item(tree, proto_9P, tvb, 0, -1, ENC_NA);
ninep_tree = proto_item_add_subtree(ti, ett_9P);
proto_tree_add_item(ninep_tree, hf_9P_msgsz, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+= 4;
msg_item = proto_tree_add_item(ninep_tree, hf_9P_msgtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
proto_tree_add_item(ninep_tree, hf_9P_tag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
switch(ninemsg) {
case _9P_RVERSION:
case _9P_TVERSION:
proto_tree_add_item(ninep_tree, hf_9P_maxsize, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (!pinfo->fd->flags.visited) {
_9p_len = tvb_get_letohs(tvb, offset);
tvb_s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2, _9p_len, ENC_UTF_8|ENC_NA);
if (!strcmp(tvb_s, "9P2000.L")) {
u32 = _9P2000_L;
} else if (!strcmp(tvb_s, "9P2000")) {
u32 = _9P2000;
} else if (!strcmp(tvb_s, "9P2000.u")) {
u32 = _9P2000_u;
} else {
u32 = _9P;
}
conv_set_version(pinfo, (enum _9p_version)u32);
}
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_version, ett_9P_version);
break;
case _9P_TAUTH:
proto_tree_add_item(ninep_tree, hf_9P_afid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
fid = tvb_get_letohl(tvb, offset);
conv_set_fid_nocopy(pinfo, fid, afid_str);
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_uname, ett_9P_uname);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_aname, ett_9P_aname);
conv_set_tag(pinfo, tag, ninemsg, fid, NULL);
break;
case _9P_RERROR:
if (_9p_version == _9P2000_L) {
u32 = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_enum, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", g_strerror(u32));
offset += 4;
} else {
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_ename, ett_9P_ename);
}
taginfo = conv_get_tag(pinfo, tag);
if (taginfo && (taginfo->msgtype == _9P_TWALK || taginfo->msgtype == _9P_TATTACH))
conv_free_fid(pinfo, taginfo->fid);
conv_free_tag(pinfo, tag);
break;
case _9P_TFLUSH:
u16 = tvb_get_letohs(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_oldtag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
conv_free_tag(pinfo, u16);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TATTACH:
fid = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_afid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_uname, ett_9P_uname);
if(!pinfo->fd->flags.visited) {
_9p_len = tvb_get_letohs(tvb, offset);
tvb_s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2, _9p_len, ENC_UTF_8|ENC_NA);
conv_set_fid(pinfo, fid, tvb_s, _9p_len+1);
}
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_aname, ett_9P_aname);
if (_9p_version == _9P2000_u || _9p_version == _9P2000_L) {
proto_tree_add_item(ninep_tree, hf_9P_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
conv_set_tag(pinfo, tag, ninemsg, fid, NULL);
break;
case _9P_TWALK:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
fid_path = conv_get_fid(pinfo, fid);
proto_item_append_text(ti, " (%s)", fid_path);
if (!pinfo->fd->flags.visited) {
tmppath = wmem_strbuf_sized_new(wmem_packet_scope(), 0, MAXPATHLEN);
wmem_strbuf_append(tmppath, fid_path);
}
offset += 4;
fid = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_newfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
u16 = tvb_get_letohs(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_nwalk, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
for(i = 0 ; i < u16; i++) {
if (!pinfo->fd->flags.visited) {
_9p_len = tvb_get_letohs(tvb, offset);
tvb_s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2, _9p_len, ENC_UTF_8|ENC_NA);
wmem_strbuf_append_c(tmppath, '/');
wmem_strbuf_append(tmppath, tvb_s);
}
if (i < 250) {
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
}
}
if(u16 > 250) {
expert_add_info(pinfo, ti, &ei_9P_first_250);
}
if (!pinfo->fd->flags.visited) {
conv_set_fid(pinfo, fid, wmem_strbuf_get_str(tmppath), wmem_strbuf_get_len(tmppath)+1);
}
conv_set_tag(pinfo, tag, ninemsg, fid, NULL);
break;
case _9P_RWALK:
u16 = tvb_get_letohs(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_nqid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(u16 > 250) {
u16 = 250;
}
for(i = 0; i < u16; i++) {
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
}
if (i >= 250) {
expert_add_info(pinfo, ti, &ei_9P_first_250);
}
conv_free_tag(pinfo, tag);
break;
case _9P_TLOPEN:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_lflags(tvb, ti, offset);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TOPEN:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
proto_tree_add_bitmask(ninep_tree, tvb, offset, hf_9P_mode, ett_9P_omode, _9P_modes, ENC_LITTLE_ENDIAN);
offset += 1;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TCREATE:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
fid_path = conv_get_fid(pinfo, fid);
proto_item_append_text(ti, " (%s)", fid_path);
offset += 4;
if (!pinfo->fd->flags.visited) {
_9p_len = tvb_get_letohs(tvb, offset);
tmppath = wmem_strbuf_sized_new(wmem_packet_scope(), 0, MAXPATHLEN);
wmem_strbuf_append(tmppath, fid_path);
wmem_strbuf_append_c(tmppath, '/');
tvb_s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2, _9p_len, ENC_UTF_8|ENC_NA);
wmem_strbuf_append(tmppath, tvb_s);
}
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_filename, ett_9P_filename);
ti = proto_tree_add_item(ninep_tree, hf_9P_perm, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 1);
offset += 4;
proto_tree_add_bitmask(ninep_tree, tvb, offset, hf_9P_mode, ett_9P_omode, _9P_modes, ENC_LITTLE_ENDIAN);
offset += 1;
if (_9p_version == _9P2000_u) {
_9p_len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_extension, tvb, offset+2, 4, ENC_ASCII|ENC_NA);
offset += 2 + _9p_len;
}
conv_set_tag(pinfo, tag, ninemsg, fid, tmppath);
break;
case _9P_TLCREATE:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
fid_path = conv_get_fid(pinfo, fid);
proto_item_append_text(ti, " (%s)", fid_path);
offset += 4;
if (!pinfo->fd->flags.visited) {
_9p_len = tvb_get_letohs(tvb, offset);
tmppath = wmem_strbuf_sized_new(wmem_packet_scope(), 0, MAXPATHLEN);
wmem_strbuf_append(tmppath, fid_path);
wmem_strbuf_append_c(tmppath, '/');
tvb_s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2, _9p_len, ENC_UTF_8|ENC_NA);
wmem_strbuf_append(tmppath, tvb_s);
}
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_filename, ett_9P_filename);
ti = proto_tree_add_item(ninep_tree, hf_9P_lflags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_lflags(tvb, ti, offset);
offset += 4;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, fid, tmppath);
break;
case _9P_TREAD:
case _9P_TREADDIR:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RREAD:
case _9P_RREADDIR:
u32 = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
len = tvb_reported_length_remaining(tvb, offset);
reportedlen = ((gint)u32&0xffff) > len ? len : (gint)u32&0xffff;
next_tvb = tvb_new_subset(tvb, offset, len, reportedlen);
call_data_dissector(next_tvb, pinfo, tree);
offset += len;
conv_free_tag(pinfo, tag);
break;
case _9P_TWRITE:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
u32 = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
len = tvb_reported_length_remaining(tvb, offset);
reportedlen = ((gint)u32&0xffff) > len ? len : (gint)u32&0xffff;
next_tvb = tvb_new_subset(tvb, offset, len, reportedlen);
call_data_dissector(next_tvb, pinfo, tree);
offset += len;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RWRITE:
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_free_tag(pinfo, tag);
break;
case _9P_RSTAT:
proto_tree_add_item(ninep_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ninep_tree, hf_9P_sdlen, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ninep_tree, hf_9P_stattype, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ninep_tree, hf_9P_dev, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
tv.secs = tvb_get_letohl(tvb, offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_atime, tvb, offset, 4, &tv);
offset += 4;
tv.secs = tvb_get_letohl(tvb, offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_mtime, tvb, offset, 4, &tv);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_filename, ett_9P_filename);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_user, ett_9P_user);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_group, ett_9P_group);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_muid, ett_9P_muid);
conv_free_tag(pinfo, tag);
break;
case _9P_TWSTAT:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ninep_tree, hf_9P_sdlen, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ninep_tree, hf_9P_stattype, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ninep_tree, hf_9P_dev, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
tv.secs = tvb_get_letohl(tvb, offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_atime, tvb, offset, 4, &tv);
offset += 4;
tv.secs = tvb_get_letohl(tvb, offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_mtime, tvb, offset, 4, &tv);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_filename, ett_9P_filename);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_user, ett_9P_user);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_group, ett_9P_group);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_muid, ett_9P_muid);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TGETATTR:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
ti = proto_tree_add_item(ninep_tree, hf_9P_getattr_flags, tvb, offset, 8, ENC_LITTLE_ENDIAN);
dissect_9P_getattrflags(tvb, ti, offset);
offset += 8;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RGETATTR:
ti = proto_tree_add_item(ninep_tree, hf_9P_getattr_flags, tvb, offset, 8, ENC_LITTLE_ENDIAN);
dissect_9P_getattrflags(tvb, ti, offset);
offset += 8;
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_nlink, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_rdev, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_blksize, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_blocks, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
tv.secs = (time_t)tvb_get_letoh64(tvb, offset);
tv.nsecs = (guint32)tvb_get_letoh64(tvb, offset+8);
proto_tree_add_time(ninep_tree, hf_9P_atime, tvb, offset, 16, &tv);
offset += 16;
tv.secs = (time_t)tvb_get_letoh64(tvb, offset);
tv.nsecs = (guint32)tvb_get_letoh64(tvb, offset+8);
proto_tree_add_time(ninep_tree, hf_9P_mtime, tvb, offset, 16, &tv);
offset += 16;
tv.secs = (time_t)tvb_get_letoh64(tvb, offset);
tv.nsecs = (guint32)tvb_get_letoh64(tvb, offset+8);
proto_tree_add_time(ninep_tree, hf_9P_ctime, tvb, offset, 16, &tv);
offset += 16;
tv.secs = (time_t)tvb_get_letoh64(tvb, offset);
tv.nsecs = (guint32)tvb_get_letoh64(tvb, offset+8);
proto_tree_add_time(ninep_tree, hf_9P_btime, tvb, offset, 16, &tv);
offset += 16;
proto_tree_add_item(ninep_tree, hf_9P_gen, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_dataversion, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
conv_free_tag(pinfo, tag);
break;
case _9P_TSETATTR:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
ti = proto_tree_add_item(ninep_tree, hf_9P_setattr_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_setattrflags(tvb, ti, offset);
offset += 4;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
tv.secs = (time_t)tvb_get_letoh64(tvb, offset);
tv.nsecs = (guint32)tvb_get_letoh64(tvb, offset+8);
proto_tree_add_time(ninep_tree, hf_9P_atime, tvb, offset, 16, &tv);
offset += 16;
tv.secs = (time_t)tvb_get_letoh64(tvb, offset);
tv.nsecs = (guint32)tvb_get_letoh64(tvb, offset+8);
proto_tree_add_time(ninep_tree, hf_9P_mtime, tvb, offset, 16, &tv);
offset += 16;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RSTATFS:
proto_tree_add_item(ninep_tree, hf_9P_fstype, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_blksize, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_blocks, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_bfree, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_bavail, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_files, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_ffree, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_fsid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_namelen, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_free_tag(pinfo, tag);
break;
case _9P_TSYMLINK:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TMKNOD:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_mknod_major, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_mknod_minor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TRENAME:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
dfid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_dfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
fid_path = conv_get_fid(pinfo, dfid);
proto_item_append_text(ti, " (%s)", fid_path);
offset += 4;
if (!pinfo->fd->flags.visited) {
_9p_len = tvb_get_letohs(tvb, offset);
tmppath = wmem_strbuf_sized_new(wmem_packet_scope(), 0, MAXPATHLEN);
wmem_strbuf_append(tmppath, conv_get_fid(pinfo, dfid));
wmem_strbuf_append_c(tmppath, '/');
tvb_s = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2, _9p_len, ENC_UTF_8|ENC_NA);
wmem_strbuf_append(tmppath, tvb_s);
conv_set_fid(pinfo, fid, wmem_strbuf_get_str(tmppath), wmem_strbuf_get_len(tmppath)+1);
}
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RREADLINK:
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_free_tag(pinfo, tag);
break;
case _9P_TXATTRWALK:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
fid_path = conv_get_fid(pinfo, fid);
proto_item_append_text(ti, " (%s)", fid_path);
offset += 4;
newfid = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ninep_tree, hf_9P_newfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
conv_set_fid_nocopy(pinfo, newfid, fid_path);
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RXATTRWALK:
proto_tree_add_item(ninep_tree, hf_9P_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
conv_free_tag(pinfo, tag);
break;
case _9P_TXATTRCREATE:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
proto_tree_add_item(ninep_tree, hf_9P_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_xattr_flag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TLOCK:
case _9P_TGETLOCK:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_lock_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ninep_tree, hf_9P_lock_flag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_lock_start, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_lock_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_lock_procid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RLOCK:
proto_tree_add_item(ninep_tree, hf_9P_lock_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
conv_free_tag(pinfo, tag);
break;
case _9P_RGETLOCK:
proto_tree_add_item(ninep_tree, hf_9P_lock_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ninep_tree, hf_9P_lock_flag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_lock_start, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_lock_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(ninep_tree, hf_9P_lock_procid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_free_tag(pinfo, tag);
break;
case _9P_TLINK:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_dfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TMKDIR:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb, ti, offset, 0);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TRENAMEAT:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_dfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_newfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TUNLINKAT:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_dfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
offset += 4;
offset += _9p_dissect_string(tvb, ninep_tree, offset, hf_9P_wname, ett_9P_wname);
proto_tree_add_item(ninep_tree, hf_9P_unlinkat_flags, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_TREMOVE:
case _9P_TCLUNK:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
conv_free_fid(pinfo, fid);
conv_set_tag(pinfo, tag, ninemsg, fid, NULL);
break;
case _9P_TSTATFS:
case _9P_TREADLINK:
case _9P_TFSYNC:
case _9P_TSTAT:
fid = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_append_text(ti, " (%s)", conv_get_fid(pinfo, fid));
conv_set_tag(pinfo, tag, ninemsg, _9P_NOFID, NULL);
break;
case _9P_RCREATE:
case _9P_RLCREATE:
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
proto_tree_add_item(ninep_tree, hf_9P_iounit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
taginfo = conv_get_tag(pinfo, tag);
if (taginfo && taginfo->fid_path) {
conv_set_fid_nocopy(pinfo, taginfo->fid, taginfo->fid_path);
}
conv_free_tag(pinfo, tag);
break;
case _9P_ROPEN:
case _9P_RLOPEN:
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
proto_tree_add_item(ninep_tree, hf_9P_iounit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
conv_free_tag(pinfo, tag);
break;
case _9P_RSYMLINK:
case _9P_RMKNOD:
case _9P_RMKDIR:
case _9P_RAUTH:
case _9P_RATTACH:
dissect_9P_qid(tvb, ninep_tree, offset);
offset += 13;
conv_free_tag(pinfo, tag);
break;
case _9P_RRENAME:
case _9P_RSETATTR:
case _9P_RXATTRCREATE:
case _9P_RFSYNC:
case _9P_RLINK:
case _9P_RRENAMEAT:
case _9P_RUNLINKAT:
case _9P_RFLUSH:
case _9P_RCLUNK:
case _9P_RREMOVE:
case _9P_RWSTAT:
case _9P_RLERROR:
conv_free_tag(pinfo, tag);
break;
case _9P_TLERROR:
case _9P_TERROR:
default:
expert_add_info(pinfo, msg_item, &ei_9P_msgtype);
break;
}
if (offset != tvb_captured_length(tvb))
proto_tree_add_item(ninep_tree, hf_9P_unknown_message, tvb, offset, -1, ENC_NA);
return tvb_captured_length(tvb);
}
static guint get_9P_message_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return (guint) tvb_get_letohl(tvb, offset);
}
static int dissect_9P(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4,
get_9P_message_len, dissect_9P_message, data);
return tvb_captured_length(tvb);
}
static void dissect_9P_qid(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *qidtype_item;
proto_tree *qid_tree,*qidtype_tree;
guint64 path;
guint32 vers;
guint8 type;
if(!tree)
return;
type = tvb_get_guint8(tvb, offset);
vers = tvb_get_letohs(tvb, offset+1);
path = tvb_get_letoh64(tvb, offset+1+4);
qid_tree = proto_tree_add_subtree_format(tree, tvb, offset, 13, ett_9P_qid, NULL,
"Qid type=0x%02x vers=%d path=%" G_GINT64_MODIFIER "u", type, vers, path);
qidtype_item = proto_tree_add_item(qid_tree, hf_9P_qidtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
qidtype_tree = proto_item_add_subtree(qidtype_item, ett_9P_qidtype);
proto_tree_add_item(qidtype_tree, hf_9P_qidtype_dir, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qidtype_tree, hf_9P_qidtype_append, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qidtype_tree, hf_9P_qidtype_exclusive, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qidtype_tree, hf_9P_qidtype_mount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qidtype_tree, hf_9P_qidtype_auth_file, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qidtype_tree, hf_9P_qidtype_temp_file, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qid_tree, hf_9P_qidvers, tvb, offset+1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qid_tree, hf_9P_qidpath, tvb, offset+1+4, 8, ENC_LITTLE_ENDIAN);
}
static void dissect_9P_dm(tvbuff_t *tvb, proto_item *item, int offset, int iscreate)
{
proto_item *mode_tree;
mode_tree = proto_item_add_subtree(item, ett_9P_dm);
if(!mode_tree)
return;
proto_tree_add_item(mode_tree, hf_9P_dm_dir, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(!iscreate) {
proto_tree_add_item(mode_tree, hf_9P_dm_append, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_exclusive, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_mount, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_auth_file, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_temp_file, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(mode_tree, hf_9P_dm_read_owner, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_write_owner, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_exec_owner, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_read_group, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_write_group, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_exec_group, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_read_others, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_write_others, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_9P_dm_exec_others, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_9P_getattrflags(tvbuff_t *tvb, proto_item *item, int offset)
{
proto_item *attrmask_tree;
attrmask_tree = proto_item_add_subtree(item, ett_9P_getattr_flags);
if(!attrmask_tree)
return;
proto_tree_add_item(attrmask_tree, hf_9P_getattr_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_nlink, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_rdev, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_atime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_mtime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_ctime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_ino, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_blocks, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_btime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_gen, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_getattr_dataversion, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_9P_setattrflags(tvbuff_t *tvb, proto_item *item, int offset)
{
proto_item *attrmask_tree;
attrmask_tree = proto_item_add_subtree(item, ett_9P_setattr_flags);
if(!attrmask_tree)
return;
proto_tree_add_item(attrmask_tree, hf_9P_setattr_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_gid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_atime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_mtime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_ctime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_atime_set, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_setattr_mtime_set, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_9P_lflags(tvbuff_t *tvb, proto_item *item, int offset)
{
proto_item *attrmask_tree;
attrmask_tree = proto_item_add_subtree(item, ett_9P_lflags);
if(!attrmask_tree)
return;
proto_tree_add_item(attrmask_tree, hf_9P_lflags_rdonly, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_wronly, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_rdwr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_create, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_excl, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_noctty, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_trunc, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_append, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_nonblock, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_dsync, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_fasync, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_direct, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_largefile, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_directory, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_nofollow, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_noatime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_cloexec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(attrmask_tree, hf_9P_lflags_sync, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
void proto_register_9P(void)
{
static hf_register_info hf[] = {
{&hf_9P_msgsz,
{"Msg length", "9p.msglen", FT_UINT32, BASE_DEC, NULL, 0x0,
"9P Message Length", HFILL}},
{&hf_9P_msgtype,
{"Msg Type", "9p.msgtype", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ninep_msg_type_ext, 0x0,
"Message Type", HFILL}},
{&hf_9P_tag,
{"Tag", "9p.tag", FT_UINT16, BASE_DEC, NULL, 0x0,
"9P Tag", HFILL}},
{&hf_9P_oldtag,
{"Old tag", "9p.oldtag", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_parmsz,
{"Param length", "9p.paramsz", FT_UINT16, BASE_DEC, NULL, 0x0,
"Parameter length", HFILL}},
{&hf_9P_maxsize,
{"Max msg size", "9p.maxsize", FT_UINT32, BASE_DEC, NULL, 0x0,
"Max message size", HFILL}},
{&hf_9P_fid,
{"Fid", "9p.fid", FT_UINT32, BASE_DEC, NULL, 0x0,
"File ID", HFILL}},
{&hf_9P_nqid,
{"Nr Qids", "9p.nqid", FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Qid results", HFILL}},
{&hf_9P_mode,
{"Mode", "9p.mode", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_mode_rwx,
{"Open/Create Mode", "9p.mode.rwx", FT_UINT8, BASE_OCT | BASE_EXT_STRING, &ninep_mode_vals_ext, _9P_MODEMASK,
NULL, HFILL}},
{&hf_9P_mode_t,
{"Trunc", "9p.mode.trunc", FT_BOOLEAN, 8, TFS(&tfs_set_notset), _9P_OTRUNC,
"Truncate", HFILL}},
{&hf_9P_mode_c,
{"Remove on close", "9p.mode.orclose", FT_BOOLEAN, 8, TFS(&tfs_set_notset), _9P_ORCLOSE,
NULL, HFILL}},
{&hf_9P_extension,
{"Extension string", "9p.extension", FT_STRING, BASE_NONE, NULL, 0x0,
"Link target for DSYMLINK mode, major+minor for DMDEVICE, empty for normal files", HFILL}},
{&hf_9P_iounit,
{"I/O Unit", "9p.iounit", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_count,
{"Count", "9p.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_offset,
{"Offset", "9p.offset", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_perm,
{"Permissions", "9p.perm", FT_UINT32, BASE_OCT, NULL, 0x0,
"Permission bits", HFILL}},
{&hf_9P_qidpath,
{"Qid path", "9p.qidpath", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_dm_dir,
{"Directory", "9p.dm.dir", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x80000000,
NULL, HFILL}},
{&hf_9P_dm_append,
{"Append only", "9p.dm.append", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x40000000,
NULL, HFILL}},
{&hf_9P_dm_exclusive,
{"Exclusive use", "9p.dm.exclusive", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x20000000,
NULL, HFILL}},
{&hf_9P_dm_mount,
{"Mounted channel", "9p.dm.mount", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x10000000,
NULL, HFILL}},
{&hf_9P_dm_auth_file,
{"Authentication file", "9p.dm.auth_file", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x08000000,
NULL, HFILL}},
{&hf_9P_dm_temp_file,
{"Temporary file (not backed up)", "9p.dm.temp_file", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x04000000,
NULL, HFILL}},
{&hf_9P_dm_read_owner,
{"Read permission for owner", "9p.dm.read_owner", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000400,
NULL, HFILL}},
{&hf_9P_dm_write_owner,
{"Write permission for owner", "9p.dm.write_owner", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000200,
NULL, HFILL}},
{&hf_9P_dm_exec_owner,
{"Execute permission for owner", "9p.dm.exec_owner", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000100,
NULL, HFILL}},
{&hf_9P_dm_read_group,
{"Read permission for group", "9p.dm.read_group", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000040,
NULL, HFILL}},
{&hf_9P_dm_write_group,
{"Write permission for group", "9p.dm.write_group", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000020,
NULL, HFILL}},
{&hf_9P_dm_exec_group,
{"Execute permission for group", "9p.dm.exec_group", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000010,
NULL, HFILL}},
{&hf_9P_dm_read_others,
{"Read permission for others", "9p.dm.read_others", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000004,
NULL, HFILL}},
{&hf_9P_dm_write_others,
{"Write permission for others", "9p.dm.write_others", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000002,
NULL, HFILL}},
{&hf_9P_dm_exec_others,
{"Execute permission for others", "9p.dm.exec_others", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000001,
NULL, HFILL}},
{&hf_9P_qidvers,
{"Qid version", "9p.qidvers", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_qidtype,
{"Qid type", "9p.qidtype", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_qidtype_dir,
{"Directory", "9p.qidtype.dir", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL}},
{&hf_9P_qidtype_append,
{"Append only", "9p.qidtype.append", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL}},
{&hf_9P_qidtype_exclusive,
{"Exclusive use", "9p.qidtype.exclusive", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL}},
{&hf_9P_qidtype_mount,
{"Mounted channel", "9p.qidtype.mount", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL}},
{&hf_9P_qidtype_auth_file,
{"Authentication file", "9p.qidtype.auth_file", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL}},
{&hf_9P_qidtype_temp_file,
{"Temporary file (not backed up)", "9p.qidtype.temp_file", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL}},
{&hf_9P_statmode,
{"Mode", "9p.statmode", FT_UINT32, BASE_OCT, NULL, 0x0,
"File mode flags", HFILL}},
{&hf_9P_stattype,
{"Type", "9p.stattype", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_atime,
{"Atime", "9p.atime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Access Time", HFILL}},
{&hf_9P_mtime,
{"Mtime", "9p.mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Modified Time", HFILL}},
{&hf_9P_ctime,
{"Ctime", "9p.ctime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Creation Time", HFILL}},
{&hf_9P_btime,
{"Btime", "9p.btime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Btime (Synchronization information)", HFILL}},
{&hf_9P_length,
{"Length", "9p.length", FT_UINT64, BASE_DEC, NULL, 0x0,
"File Length", HFILL}},
{&hf_9P_dev,
{"Dev", "9p.dev", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_wname,
{"Wname", "9p.wname", FT_STRING, BASE_NONE, NULL, 0x0,
"Path Name Element", HFILL}},
{&hf_9P_version,
{"Version", "9p.version", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_afid,
{"Afid", "9p.afid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Authenticating FID", HFILL}},
{&hf_9P_uname,
{"Uname", "9p.uname", FT_STRING, BASE_NONE, NULL, 0x0,
"User Name", HFILL}},
{&hf_9P_aname,
{"Aname", "9p.aname", FT_STRING, BASE_NONE, NULL, 0x0,
"Access Name", HFILL}},
{&hf_9P_ename,
{"Ename", "9p.ename", FT_STRING, BASE_NONE, NULL, 0x0,
"Error", HFILL}},
{&hf_9P_enum,
{"Enum", "9p.enum", FT_UINT32, BASE_DEC, NULL, 0x0,
"Error", HFILL}},
#if 0
{&hf_9P_name,
{"Name", "9p.name", FT_STRING, BASE_NONE, NULL, 0x0,
"Name of file", HFILL}},
#endif
{&hf_9P_sdlen,
{"Stat data length", "9p.sdlen", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_filename,
{"File name", "9p.filename", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_user,
{"User", "9p.user", FT_STRING, BASE_NONE, NULL, 0x0,
"User name", HFILL}},
{&hf_9P_group,
{"Group", "9p.group", FT_STRING, BASE_NONE, NULL, 0x0,
"Group name", HFILL}},
{&hf_9P_uid,
{"Uid", "9p.uid", FT_UINT32, BASE_DEC, NULL, 0x0,
"User id", HFILL}},
{&hf_9P_gid,
{"Gid", "9p.gid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Group id", HFILL}},
{&hf_9P_muid,
{"Muid", "9p.muid", FT_STRING, BASE_NONE, NULL, 0x0,
"Last modifiers uid", HFILL}},
{&hf_9P_newfid,
{"New fid", "9p.newfid", FT_UINT32, BASE_DEC, NULL, 0x0,
"New file ID", HFILL}},
{&hf_9P_dfid,
{"Directory fid", "9p.dfid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Directory ID", HFILL}},
{&hf_9P_nwalk,
{"Nr Walks", "9p.nwalk", FT_UINT32, BASE_DEC, NULL, 0x0,
"Nr of walk items", HFILL}},
{&hf_9P_nlink,
{"nlink", "9p.nlink", FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of links", HFILL}},
{&hf_9P_getattr_flags,
{"getattr_flags", "9p.getattr.flags", FT_UINT64, BASE_HEX, NULL, _9P_GETATTR_ALL,
"Getattr flags", HFILL}},
{&hf_9P_getattr_mode,
{"Mode", "9p.getattr.mode", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_MODE,
NULL, HFILL}},
{&hf_9P_getattr_nlink,
{"Nlink", "9p.getattr.nlink", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_NLINK,
NULL, HFILL}},
{&hf_9P_getattr_uid,
{"UID", "9p.getattr.uid", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_UID,
NULL, HFILL}},
{&hf_9P_getattr_gid,
{"GID", "9p.getattr.gid", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_GID,
NULL, HFILL}},
{&hf_9P_getattr_rdev,
{"Rdev", "9p.getattr.rdev", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_RDEV,
NULL, HFILL}},
{&hf_9P_getattr_atime,
{"Atime", "9p.getattr.atime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_ATIME,
NULL, HFILL}},
{&hf_9P_getattr_mtime,
{"Mtime", "9p.getattr.mtime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_MTIME,
NULL, HFILL}},
{&hf_9P_getattr_ctime,
{"Ctime", "9p.getattr.ctime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_CTIME,
NULL, HFILL}},
{&hf_9P_getattr_ino,
{"Inode", "9p.getattr.inode", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_INO,
NULL, HFILL}},
{&hf_9P_getattr_size,
{"Size", "9p.getattr.size", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_SIZE,
NULL, HFILL}},
{&hf_9P_getattr_blocks,
{"Blocks", "9p.getattr.blocks", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_BLOCKS,
NULL, HFILL}},
{&hf_9P_getattr_btime,
{"Btime", "9p.getattr.btime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_BTIME,
NULL, HFILL}},
{&hf_9P_getattr_gen,
{"Gen", "9p.getattr.gen", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_GEN,
NULL, HFILL}},
{&hf_9P_getattr_dataversion,
{"Data version", "9p.getattr.dataversion", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_GETATTR_DATA_VERSION,
NULL, HFILL}},
{&hf_9P_setattr_flags,
{"setattr_flags", "9p.setattr.flags", FT_UINT32, BASE_HEX, NULL, _9P_SETATTR_ALL,
"Setattr flags", HFILL}},
{&hf_9P_setattr_mode,
{"Mode", "9p.setattr.mode", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_MODE,
NULL, HFILL}},
{&hf_9P_setattr_uid,
{"UID", "9p.setattr.uid", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_UID,
NULL, HFILL}},
{&hf_9P_setattr_gid,
{"GID", "9p.setattr.gid", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_GID,
NULL, HFILL}},
{&hf_9P_setattr_size,
{"Size", "9p.setattr.size", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_SIZE,
NULL, HFILL}},
{&hf_9P_setattr_atime,
{"Atime", "9p.setattr.atime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_ATIME,
NULL, HFILL}},
{&hf_9P_setattr_mtime,
{"Mtime", "9p.setattr.mtime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_MTIME,
NULL, HFILL}},
{&hf_9P_setattr_ctime,
{"Ctime", "9p.setattr.ctime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_CTIME,
NULL, HFILL}},
{&hf_9P_setattr_atime_set,
{"Atime set", "9p.setattr.atimeset", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_ATIME_SET,
NULL, HFILL}},
{&hf_9P_setattr_mtime_set,
{"Mtime set", "9p.setattr.mtimeset", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_SETATTR_MTIME_SET,
NULL, HFILL}},
{&hf_9P_unlinkat_flags,
{"unlinkat flags", "9p.unlinkat.flags", FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}},
{&hf_9P_rdev,
{"rdev", "9p.rdev", FT_UINT64, BASE_DEC, NULL, 0x0,
"Device associated with file", HFILL}},
{&hf_9P_size,
{"Size", "9p.size", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_blksize,
{"Blksize", "9p.blksize", FT_UINT64, BASE_DEC, NULL, 0x0,
"Block size", HFILL}},
{&hf_9P_blocks,
{"Blocks", "9p.blocks", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_gen,
{"Gen", "9p.gen", FT_UINT64, BASE_DEC, NULL, 0x0,
"inode generation number", HFILL}},
{&hf_9P_dataversion,
{"Dataversion", "9p.dataversion", FT_UINT64, BASE_DEC, NULL, 0x0,
"Data version", HFILL}},
{&hf_9P_fstype,
{"fstype", "9p.fstype", FT_UINT32, BASE_HEX, NULL, 0x0,
"Filesystem type", HFILL}},
{&hf_9P_bfree,
{"bfree", "9p.bfree", FT_UINT64, BASE_DEC, NULL, 0x0,
"Free blocks", HFILL}},
{&hf_9P_bavail,
{"bavail", "9p.bavail", FT_UINT64, BASE_DEC, NULL, 0x0,
"Available blocks", HFILL}},
{&hf_9P_files,
{"files", "9p.files", FT_UINT64, BASE_DEC, NULL, 0x0,
"Total files", HFILL}},
{&hf_9P_ffree,
{"ffree", "9p.ffree", FT_UINT64, BASE_DEC, NULL, 0x0,
"Free files", HFILL}},
{&hf_9P_fsid,
{"fsid", "9p.fsid", FT_UINT64, BASE_DEC, NULL, 0x0,
"Filesystem id", HFILL}},
{&hf_9P_namelen,
{"namelen", "9p.namelen", FT_UINT32, BASE_DEC, NULL, 0x0,
"Max name length", HFILL}},
{&hf_9P_mknod_major,
{"mknod_major", "9p.mknod.major", FT_UINT32, BASE_DEC, NULL, 0x0,
"Major node number", HFILL}},
{&hf_9P_mknod_minor,
{"mknod_minor", "9p.mknod.minor", FT_UINT32, BASE_DEC, NULL, 0x0,
"Minor node number", HFILL}},
{&hf_9P_lflags,
{"lflags", "9p.lcreate.flags", FT_UINT32, BASE_HEX, NULL, 0x0,
"Lcreate flags", HFILL}},
{&hf_9P_lflags_rdonly,
{"Read only", "9p.lflags.rdonly", FT_BOOLEAN, 32, TFS(&tfs_no_yes), _9P_DOTL_WRONLY|_9P_DOTL_RDWR,
NULL, HFILL}},
{&hf_9P_lflags_wronly,
{"Write only", "9p.lflags.wronly", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_WRONLY,
NULL, HFILL}},
{&hf_9P_lflags_rdwr,
{"Read Write", "9p.lflags.rdwr", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_RDWR,
NULL, HFILL}},
{&hf_9P_lflags_create,
{"Create", "9p.lflags.create", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_CREATE,
NULL, HFILL}},
{&hf_9P_lflags_excl,
{"Exclusive", "9p.lflags.excl", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_EXCL,
NULL, HFILL}},
{&hf_9P_lflags_noctty,
{"noctty", "9p.lflags.noctty", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_NOCTTY,
NULL, HFILL}},
{&hf_9P_lflags_trunc,
{"Truncate", "9p.lflags.trunc", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_TRUNC,
NULL, HFILL}},
{&hf_9P_lflags_append,
{"Append", "9p.lflags.append", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_APPEND,
NULL, HFILL}},
{&hf_9P_lflags_nonblock,
{"Nonblock", "9p.lflags.nonblock", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_NONBLOCK,
NULL, HFILL}},
{&hf_9P_lflags_dsync,
{"dsync", "9p.lflags.dsync", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_DSYNC,
NULL, HFILL}},
{&hf_9P_lflags_fasync,
{"fasync", "9p.lflags.fasync", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_FASYNC,
NULL, HFILL}},
{&hf_9P_lflags_direct,
{"Direct", "9p.lflags.direct", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_DIRECT,
NULL, HFILL}},
{&hf_9P_lflags_largefile,
{"Large File", "9p.lflags.largefile", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_LARGEFILE,
NULL, HFILL}},
{&hf_9P_lflags_directory,
{"Directory", "9p.lflags.directory", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_DIRECTORY,
NULL, HFILL}},
{&hf_9P_lflags_nofollow,
{"No follow", "9p.lflags.nofollow", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_NOFOLLOW,
NULL, HFILL}},
{&hf_9P_lflags_noatime,
{"No atime", "9p.lflags.noatime", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_NOATIME,
NULL, HFILL}},
{&hf_9P_lflags_cloexec,
{"cloexec", "9p.lflags.cloexec", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_CLOEXEC,
NULL, HFILL}},
{&hf_9P_lflags_sync,
{"Sync", "9p.lflags.sync", FT_BOOLEAN, 32, TFS(&tfs_yes_no), _9P_DOTL_SYNC,
NULL, HFILL}},
{&hf_9P_xattr_flag,
{"xattr_flag", "9p.xattr.flag", FT_UINT32, BASE_HEX, NULL, 0x0,
"Xattr flag", HFILL}},
{&hf_9P_lock_type,
{"lock_type", "9p.lock.type", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ninep_lock_type_ext, 0x0,
"Lock type", HFILL}},
{&hf_9P_lock_flag,
{"lock_flag", "9p.lock.flag", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ninep_lock_flag_ext, 0x0,
"Lock flag", HFILL}},
{&hf_9P_lock_start,
{"lock_start", "9p.lock.start", FT_UINT64, BASE_DEC, NULL, 0x0,
"Lock start", HFILL}},
{&hf_9P_lock_length,
{"lock_length", "9p.lock.length", FT_UINT64, BASE_DEC, NULL, 0x0,
"Lock length", HFILL}},
{&hf_9P_lock_procid,
{"lock_procid", "9p.lock.procid", FT_UINT32, BASE_HEX, NULL, 0x0,
"Lock procid", HFILL}},
{&hf_9P_lock_status,
{"lock_status", "9p.lock.status", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ninep_lock_status_ext, 0x0,
"Lock status", HFILL}},
{&hf_9P_unknown_message,
{"Message data", "9p.message_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}}
};
static gint *ett[] = {
&ett_9P,
&ett_9P_omode,
&ett_9P_dm,
&ett_9P_wname,
&ett_9P_aname,
&ett_9P_ename,
&ett_9P_uname,
&ett_9P_user,
&ett_9P_group,
&ett_9P_muid,
&ett_9P_filename,
&ett_9P_version,
&ett_9P_qid,
&ett_9P_qidtype,
&ett_9P_getattr_flags,
&ett_9P_setattr_flags,
&ett_9P_lflags,
};
expert_module_t* expert_9P;
static ei_register_info ei[] = {
{ &ei_9P_first_250, { "9p.first_250", PI_PROTOCOL, PI_NOTE, "Only first 250 items shown", EXPFILL }},
{ &ei_9P_msgtype, { "9p.msgtype.unknown", PI_PROTOCOL, PI_WARN, "This message type should not happen", EXPFILL }},
};
proto_9P = proto_register_protocol("Plan 9", "9P", "9p");
proto_register_field_array(proto_9P, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_9P = expert_register_protocol(proto_9P);
expert_register_field_array(expert_9P, ei, array_length(ei));
register_init_routine(_9p_hash_init);
}
void proto_reg_handoff_9P(void)
{
dissector_handle_t ninep_handle;
ninep_handle = create_dissector_handle(dissect_9P, proto_9P);
dissector_add_uint("tcp.port", NINEPORT, ninep_handle);
}
