static GList *insert_in_comp_req_list(GList *list, guint32 fn, guint32 reqid, const gchar * op, giop_sub_handle_t *sh ) {
comp_req_list_entry_t *entry;
entry = wmem_new(wmem_file_scope(), comp_req_list_entry_t);
entry->fn = fn;
entry->reqid = reqid;
entry->subh = sh;
entry->operation = wmem_strdup(wmem_file_scope(), op);
entry->repoid = NULL;
return g_list_append (list, entry);
}
static comp_req_list_entry_t * find_fn_in_list(guint32 fn) {
GList *element;
comp_req_list_entry_t *entry_ptr;
element = g_list_last(giop_complete_request_list);
while (element) {
entry_ptr = (comp_req_list_entry_t *)element->data;
if (entry_ptr->fn == fn) {
return entry_ptr;
}
element = g_list_previous(element);
}
return NULL;
}
static void add_sub_handle_repoid_to_comp_req_list(guint32 fn, giop_sub_handle_t *sh, gchar *repoid ) {
comp_req_list_entry_t * entry = NULL;
entry = find_fn_in_list(fn);
if (entry) {
entry->subh = sh;
entry->repoid = g_strdup(repoid);
}
}
static gint complete_reply_equal_fn(gconstpointer v, gconstpointer w) {
const struct complete_reply_hash_key *mk1 = (const struct complete_reply_hash_key *)v;
const struct complete_reply_hash_key *mk2 = (const struct complete_reply_hash_key *)w;
if (mk1->fn == mk2->fn) {
return 1;
}
return 0;
}
static guint32 complete_reply_hash_fn(gconstpointer v) {
guint32 val;
const struct complete_reply_hash_key *key = (const struct complete_reply_hash_key *)v;
val = key->fn;
return val;
}
static void insert_in_complete_reply_hash(guint32 fn, guint32 mfn) {
struct complete_reply_hash_key key, *new_key;
struct complete_reply_hash_val *val = NULL;
key.fn = fn;
val = (struct complete_reply_hash_val *)g_hash_table_lookup(giop_complete_reply_hash, &key);
if (val) {
return;
}
new_key = wmem_new(wmem_file_scope(), struct complete_reply_hash_key);
new_key->fn = fn;
val = wmem_new(wmem_file_scope(), struct complete_reply_hash_val);
val->mfn = mfn;
g_hash_table_insert(giop_complete_reply_hash, new_key, val);
}
static guint32 get_mfn_from_fn(guint32 fn) {
struct complete_reply_hash_key key;
struct complete_reply_hash_val *val = NULL;
guint32 mfn = fn;
key.fn = fn;
val = (struct complete_reply_hash_val *)g_hash_table_lookup(giop_complete_reply_hash, &key);
if (val) {
mfn = val->mfn;
}
return mfn;
}
static guint32 get_mfn_from_fn_and_reqid(guint32 fn, guint32 reqid) {
GList *element;
comp_req_list_entry_t *entry_ptr = NULL;
element = g_list_last(giop_complete_request_list);
while (element) {
entry_ptr = (comp_req_list_entry_t *)element->data;
if (entry_ptr->reqid == reqid) {
return entry_ptr->fn;
}
element = g_list_previous(element);
}
return fn;
}
static gint giop_hash_module_equal(gconstpointer v, gconstpointer w) {
const struct giop_module_key *mk1 = (const struct giop_module_key *)v;
const struct giop_module_key *mk2 = (const struct giop_module_key *)w;
if (strcmp(mk1->module, mk2->module) == 0) {
return 1;
}
return 0;
}
static guint32 giop_hash_module_hash(gconstpointer v) {
int i, len;
guint32 val = 0;
const struct giop_module_key *key = (const struct giop_module_key *)v;
len = (int)strlen(key->module);
for (i=0; i<len; i++) {
val += (guint8) key->module[i];
}
return val;
}
void register_giop_user_module(giop_sub_dissector_t *sub, const gchar *name, const gchar *module, int sub_proto) {
struct giop_module_key module_key, *new_module_key;
struct giop_module_val *module_val;
module_key.module = module;
module_val = (struct giop_module_val *)g_hash_table_lookup(giop_module_hash, &module_key);
if (module_val) {
return;
}
#if DEBUG
printf("giop:register_module: Adding Module %s to module hash \n", module);
printf("giop:register_module: Module sub dissector name is %s \n", name);
#endif
new_module_key = (struct giop_module_key *)g_malloc(sizeof(struct giop_module_key));
new_module_key->module = module;
module_val = (struct giop_module_val *)g_malloc(sizeof(struct giop_module_val));
module_val->subh = (giop_sub_handle_t *)g_malloc(sizeof (giop_sub_handle_t));
module_val->subh->sub_name = name;
module_val->subh->sub_fn = sub;
module_val->subh->sub_proto = find_protocol_by_id(sub_proto);
g_hash_table_insert(giop_module_hash, new_module_key, module_val);
}
static gint giop_hash_objkey_equal(gconstpointer v, gconstpointer w) {
const struct giop_object_key *v1 = (const struct giop_object_key *)v;
const struct giop_object_key *v2 = (const struct giop_object_key *)w;
if (v1->objkey_len != v2->objkey_len)
return 0;
if (memcmp(v1->objkey, v2->objkey, v1->objkey_len) == 0) {
return 1;
}
#if DEBUG
printf("giop:giop_hash_objkey_equal: Objkey's DO NOT match");
#endif
return 0;
}
static guint32 giop_hash_objkey_hash(gconstpointer v) {
const struct giop_object_key *key = (const struct giop_object_key *)v;
guint32 i;
guint32 val = 0;
#if DEBUG
printf("giop:hash_objkey: Key length = %u \n", key->objkey_len );
#endif
for (i=0; i< key->objkey_len; i++) {
val += (guint8) key->objkey[i];
}
return val;
}
static void insert_in_objkey_hash(GHashTable *hash, const gchar *obj, guint32 len, const gchar *repoid, ior_src_t src) {
struct giop_object_key objkey_key, *new_objkey_key;
struct giop_object_val *objkey_val;
objkey_key.objkey_len = len;
objkey_key.objkey = obj;
objkey_val = (struct giop_object_val *)g_hash_table_lookup(hash, &objkey_key);
if (objkey_val) {
g_hash_table_remove(hash, &objkey_key);
}
new_objkey_key = wmem_new(wmem_file_scope(), struct giop_object_key);
new_objkey_key->objkey_len = len;
new_objkey_key->objkey = (guint8 *) wmem_memdup(wmem_file_scope(), obj, len);
objkey_val = wmem_new(wmem_file_scope(), struct giop_object_val);
objkey_val->repo_id = wmem_strdup(wmem_file_scope(), repoid);
objkey_val->src = src;
#if DEBUG
printf("giop: ******* Inserting Objkey with RepoID = %s and key length = %u into hash \n",
objkey_val->repo_id, new_objkey_key->objkey_len);
#endif
g_hash_table_insert(hash, new_objkey_key, objkey_val);
}
static gint8 hex_char_to_val(guchar c) {
gint8 retval;
if (!isxdigit(c)) {
return -1;
}
if (isdigit(c)) {
retval = c - 48;
return retval;
}
c = toupper(c);
if (c >= 'A' && c <= 'F') {
retval = c - 55;
return retval;
}
else {
return -1;
}
}
static guint32 string_to_IOR(guchar *in, guint32 in_len, guint8 **out) {
gint8 tmpval_lsb;
gint8 tmpval_msb;
gint8 tmpval;
guint32 i;
*out = wmem_alloc0_array(wmem_packet_scope(), guint8, in_len);
if (*out == NULL) {
return 0;
}
for (i=4; i<in_len-1; i+=2) {
if ( isxdigit(in[i]) && isxdigit(in[i+1]) ) {
if ( (tmpval_msb = hex_char_to_val(in[i])) < 0 ) {
g_warning("giop: Invalid value in IOR %i \n", tmpval_msb);
}
if ( (tmpval_lsb = hex_char_to_val(in[i+1])) < 0 ) {
g_warning("giop: Invalid value in IOR %i \n", tmpval_lsb);
}
tmpval = tmpval_msb << 4;
tmpval += tmpval_lsb;
(*out)[(i-4)/2] = (guint8) tmpval;
}
else {
break;
}
}
return (i-4)/2;
}
static int giop_getline(FILE *fp, gchar *line, int maxlen) {
if (fgets(line, maxlen, fp) == NULL)
return 0;
else
return (int)strlen(line);
}
static void read_IOR_strings_from_file(const gchar *name, int max_iorlen) {
guchar *buf;
int len;
int ior_val_len;
FILE *fp;
guint8 *out;
tvbuff_t *tvb;
guint32 my_offset = 0;
gboolean stream_is_big_endian;
fp = ws_fopen(name, "r");
if (fp == NULL) {
if (errno == EACCES)
fprintf(stderr, "Error opening file %s for reading: %s\n", name, g_strerror(errno));
return;
}
buf = (guchar *)wmem_alloc0(wmem_packet_scope(), max_iorlen+1);
while ((len = giop_getline(fp, buf, max_iorlen+1)) > 0) {
my_offset = 0;
ior_val_len = string_to_IOR(buf, len, &out);
if (ior_val_len>0) {
tvb = tvb_new_real_data(out, ior_val_len, ior_val_len);
stream_is_big_endian = !get_CDR_octet(tvb, &my_offset);
decode_IOR(tvb, NULL, NULL, &my_offset, 0, stream_is_big_endian);
tvb_free(tvb);
}
}
fclose(fp);
}
static void giop_init(void) {
if (giop_objkey_hash)
g_hash_table_destroy(giop_objkey_hash);
giop_objkey_hash = g_hash_table_new(giop_hash_objkey_hash, giop_hash_objkey_equal);
if (giop_complete_reply_hash)
g_hash_table_destroy(giop_complete_reply_hash);
giop_complete_reply_hash = g_hash_table_new(complete_reply_hash_fn, complete_reply_equal_fn);
if (giop_complete_request_list) {
g_list_free(giop_complete_request_list);
giop_complete_request_list = NULL;
}
read_IOR_strings_from_file(giop_ior_file, 600);
}
void register_giop_user(giop_sub_dissector_t *sub, const gchar *name, int sub_proto) {
giop_sub_handle_t *subh;
subh = (giop_sub_handle_t *)g_malloc(sizeof (giop_sub_handle_t));
subh->sub_name = name;
subh->sub_fn = sub;
subh->sub_proto = find_protocol_by_id(sub_proto);
giop_sub_list = g_slist_append (giop_sub_list, subh);
}
static gchar * get_repoid_from_objkey(GHashTable *hash, const guint8 *obj, guint32 len) {
struct giop_object_key objkey_key;
struct giop_object_val *objkey_val;
objkey_key.objkey_len = len;
objkey_key.objkey = obj;
objkey_val = (struct giop_object_val *)g_hash_table_lookup(hash, &objkey_key);
if (objkey_val) {
#if DEBUG
printf("Lookup of object key returns RepoId = %s \n", objkey_val->repo_id );
#endif
return objkey_val->repo_id;
}
#if DEBUG
printf("FAILED Lookup of object key \n" );
#endif
return NULL;
}
static gchar * get_modname_from_repoid(gchar *repoid) {
gchar *modname;
gchar c = 'a';
guint8 stop_mod = 0;
const guint8 start_mod = 4;
int i;
if (g_ascii_strncasecmp("IDL:", repoid, 4))
return NULL;
for (i=4; c != '\0'; i++) {
c = repoid[i];
stop_mod = i;
if (c == ':' )
break;
}
modname = g_strndup(repoid+4, stop_mod - start_mod);
return modname;
}
static void display_module_hash(gpointer key, gpointer val, gpointer user_data) {
struct giop_module_val *mv = (struct giop_module_val *) val;
struct giop_module_key *mk = (struct giop_module_key *) key;
printf("giop:module: Key = (%s) , Val = (%s) \n", mk->module, mv->subh->sub_name);
return;
}
static void display_complete_reply_hash(gpointer key, gpointer val, gpointer user_data) {
struct complete_reply_hash_val *mv = (struct complete_reply_hash_val *) val;
struct complete_reply_hash_key *mk = (struct complete_reply_hash_key *) key;
printf("giop:complete_reply: FN (key) = %8u , MFN (val) = %8u \n", mk->fn, mv->mfn);
return;
}
static void display_objkey_hash(gpointer key, gpointer val, gpointer user_data) {
guint32 i;
struct giop_object_val *mv = (struct giop_object_val *) val;
struct giop_object_key *mk = (struct giop_object_key *) key;
printf("giop:objkey: Key->objkey_len = %u, Key->objkey ", mk->objkey_len);
for (i=0; i<mk->objkey_len; i++) {
printf("%.2x ", mk->objkey[i]);
}
if (mv->src == 0) {
printf(", Repo ID = %s \n", mv->repo_id);
}
else {
printf(", Repo ID = %s , (file) \n", mv->repo_id);
}
return;
}
static void display_heuristic_user_list() {
int i;
int len;
giop_sub_handle_t *subh;
len = g_slist_length(giop_sub_list);
if (len == 0)
return;
for (i=0; i<len; i++) {
subh = ( giop_sub_handle_t *) g_slist_nth_data(giop_sub_list, i);
printf("giop:heuristic_user: Element = %i, Val (user) = %s \n", i, subh->sub_name);
}
}
static void display_complete_request_list() {
int i;
int len;
comp_req_list_entry_t *entry;
len = g_list_length(giop_complete_request_list);
if (len == 0)
return;
for (i=0; i<len; i++) {
entry = (comp_req_list_entry_t *) g_list_nth_data(giop_complete_request_list, i);
printf("giop:Index = %8i , FN = %8i, reqid = %8u , operation = %20s , repoid = %30s \n", i, entry->fn,
entry->reqid, entry->operation, entry->repoid);
}
}
static void giop_dump_collection(collection_data_t collection_type) {
switch (collection_type) {
case cd_heuristic_users:
printf("+----------------------------------------------+ \n");
printf("+-------------- Heuristic User (Begin) --------+ \n");
printf("+----------------------------------------------+ \n");
display_heuristic_user_list();
printf("+----------------------------------------------+ \n");
printf("+-------------- Heuristic User (End) ----------+ \n");
printf("+----------------------------------------------+ \n");
break;
case cd_complete_request_list:
printf("+----------------------------------------------+ \n");
printf("+------------- Complete Request List (Begin) --+ \n");
printf("+----------------------------------------------+ \n");
display_complete_request_list();
printf("+----------------------------------------------+ \n");
printf("+------------ Complete Request List (End) -----+ \n");
printf("+----------------------------------------------+ \n");
break;
case cd_module_hash:
printf("+----------------------------------------------+ \n");
printf("+-------------- Module (Begin) ----------------+ \n");
printf("+----------------------------------------------+ \n");
g_hash_table_foreach(giop_module_hash, display_module_hash, NULL);
printf("+----------------------------------------------+ \n");
printf("+-------------- Module ( End) -----------------+ \n");
printf("+----------------------------------------------+ \n\n");
break;
case cd_objkey_hash:
printf("+----------------------------------------------+ \n");
printf("+-------------- Objkey (Begin) ----------------+ \n");
printf("+----------------------------------------------+ \n");
g_hash_table_foreach(giop_objkey_hash, display_objkey_hash, NULL);
printf("+----------------------------------------------+ \n");
printf("+-------------- Objkey (End) ------------------+ \n");
printf("+----------------------------------------------+ \n\n");
break;
case cd_complete_reply_hash:
printf("+----------------------------------------------+ \n");
printf("+-------------- Complete_Reply_Hash (Begin) ---+ \n");
printf("+----------------------------------------------+ \n");
g_hash_table_foreach(giop_complete_reply_hash, display_complete_reply_hash, NULL);
printf("+----------------------------------------------+ \n");
printf("+------------- Complete_Reply_Hash (End) ------+ \n");
printf("+----------------------------------------------+ \n");
break;
default:
printf("giop: giop_dump_collection: Unknown type \n");
}
}
static gboolean try_heuristic_giop_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 *offset,
MessageHeader *header, const gchar *operation ) {
int i, len;
gboolean res = FALSE;
giop_sub_handle_t *subh;
const char *saved_proto;
len = g_slist_length(giop_sub_list);
if (len == 0)
return FALSE;
{
guint32 message_size;
gboolean stream_is_big_endian = is_big_endian (header);
if (stream_is_big_endian)
message_size = pntoh32 (&header->message_size);
else
message_size = pletoh32 (&header->message_size);
if (*offset > message_size)
return FALSE;
}
saved_proto = pinfo->current_proto;
for (i=0; i<len; i++) {
subh = (giop_sub_handle_t *) g_slist_nth_data(giop_sub_list, i);
if (proto_is_protocol_enabled(subh->sub_proto)) {
pinfo->current_proto =
proto_get_protocol_short_name(subh->sub_proto);
res = (subh->sub_fn)(tvb, pinfo, tree, offset, header, operation, NULL);
if (res) {
pinfo->current_proto = saved_proto;
return TRUE;
}
}
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, "GIOP");
pinfo->current_proto = saved_proto;
return res;
}
static gboolean try_explicit_giop_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset,
MessageHeader *header, const gchar *operation, gchar *repoid ) {
giop_sub_handle_t *subdiss;
gboolean res = FALSE;
gchar *modname;
struct giop_module_key module_key;
struct giop_module_val *module_val;
const char *saved_proto;
modname = get_modname_from_repoid(repoid);
if (modname == NULL) {
return res;
}
module_key.module = modname;
module_val = (struct giop_module_val *)g_hash_table_lookup(giop_module_hash, &module_key);
if (module_val == NULL) {
return res;
}
subdiss = (giop_sub_handle_t *) module_val->subh;
if (subdiss) {
if (!pinfo->fd->flags.visited)
add_sub_handle_repoid_to_comp_req_list(pinfo->fd->num, subdiss, repoid);
if (tvb_offset_exists(tvb, *offset)) {
#if DEBUG
printf("giop:try_explicit_dissector calling sub = %s with module = (%s) \n", subdiss->sub_name , modname);
#endif
if (proto_is_protocol_enabled(subdiss->sub_proto)) {
saved_proto = pinfo->current_proto;
pinfo->current_proto =
proto_get_protocol_short_name(subdiss->sub_proto);
res = (subdiss->sub_fn)(tvb, pinfo, tree, offset, header, operation, modname);
pinfo->current_proto = saved_proto;
}
}
}
return res;
}
gchar *make_printable_string (const gchar *in, guint32 len) {
guint32 i;
gchar *print_string;
print_string = (gchar * )wmem_alloc0(wmem_packet_scope(), len + 1);
memcpy(print_string, in, len);
for (i=0; i < len; i++) {
if ( !g_ascii_isprint( (unsigned char)print_string[i] ) )
print_string[i] = '.';
}
return print_string;
}
gboolean is_big_endian (MessageHeader * header) {
gboolean big_endian = FALSE;
switch (header->GIOP_version.minor) {
case 2:
case 1:
if (header->flags & GIOP_MESSAGE_FLAGS_ENDIANNESS)
big_endian = FALSE;
else
big_endian = TRUE;
break;
case 0:
if (header->flags)
big_endian = FALSE;
else
big_endian = TRUE;
break;
default:
break;
}
return big_endian;
}
static void set_new_alignment(int *offset, int delta, int alignment) {
while ( ( (*offset + delta) % alignment) != 0)
++(*offset);
}
static void dissect_data_for_typecode(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_item *item, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header, guint32 data_type ) {
gboolean my_boolean;
gint8 s_octet1;
guint8 u_octet1;
gint16 s_octet2;
guint16 u_octet2;
gint32 s_octet4;
guint32 u_octet4;
gdouble my_double;
gfloat my_float;
const gchar *buf = NULL;
switch (data_type) {
case tk_null:
break;
case tk_void:
break;
case tk_short:
s_octet2 = get_CDR_short(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_int(tree, hf_giop_type_short, tvb, *offset-2, 2, s_octet2);
break;
case tk_long:
s_octet4 = get_CDR_long(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_int(tree, hf_giop_type_long, tvb, *offset-4, 4, s_octet4);
break;
case tk_ushort:
u_octet2 = get_CDR_ushort(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_type_ushort, tvb, *offset-2, 2, u_octet2);
break;
case tk_ulong:
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_type_ulong, tvb, *offset-4, 4, u_octet4);
break;
case tk_float:
my_float = get_CDR_float(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_double(tree, hf_giop_type_float, tvb, *offset-4, 4, my_float);
break;
case tk_double:
my_double = get_CDR_double(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_double(tree, hf_giop_type_double, tvb, *offset-8, 8, my_double);
break;
case tk_boolean:
my_boolean = get_CDR_boolean(tvb, offset);
proto_tree_add_boolean(tree, hf_giop_type_boolean, tvb, *offset-1, 1, my_boolean);
break;
case tk_char:
u_octet1 = get_CDR_char(tvb, offset);
proto_tree_add_uint(tree, hf_giop_type_char, tvb, *offset-1, 1, u_octet1);
break;
case tk_octet:
u_octet1 = get_CDR_octet(tvb, offset);
proto_tree_add_uint(tree, hf_giop_type_octet, tvb, *offset-1, 1, u_octet1);
break;
case tk_any:
get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);
break;
case tk_TypeCode:
get_CDR_typeCode(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header);
break;
case tk_Principal:
break;
case tk_objref:
break;
case tk_struct:
break;
case tk_union:
break;
case tk_enum:
u_octet4 = get_CDR_enum(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_type_enum, tvb, *offset-4, 4, u_octet4);
break;
case tk_string:
u_octet4 = get_CDR_string(tvb, &buf, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_string_length, tvb,
*offset-u_octet4-4, 4, u_octet4);
if (u_octet4 > 0) {
proto_tree_add_string(tree, hf_giop_type_string, tvb,
*offset-u_octet4, u_octet4, buf);
}
break;
case tk_sequence:
break;
case tk_array:
break;
case tk_alias:
break;
case tk_except:
break;
case tk_longlong:
break;
case tk_ulonglong:
break;
case tk_longdouble:
break;
case tk_wchar:
s_octet1 = get_CDR_wchar(tvb, &buf, offset, header);
if (tree) {
if (s_octet1 < 0) {
proto_tree_add_string(tree, hf_giop_type_string, tvb,
*offset+s_octet1, (-s_octet1), buf);
} else {
proto_tree_add_uint(tree, hf_giop_string_length, tvb,
*offset-s_octet1-1, 1, s_octet1);
proto_tree_add_string(tree, hf_giop_type_string, tvb,
*offset-s_octet1, s_octet1, buf);
}
}
break;
case tk_wstring:
u_octet4 = get_CDR_wstring(tvb, &buf, offset, stream_is_big_endian, boundary, header);
if (tree) {
proto_tree_add_uint(tree, hf_giop_string_length, tvb,
*offset-u_octet4-4, 4, u_octet4);
proto_tree_add_string(tree, hf_giop_type_string, tvb,
*offset-u_octet4, u_octet4, buf);
}
break;
case tk_fixed:
break;
case tk_value:
break;
case tk_value_box:
break;
case tk_native:
break;
case tk_abstract_interface:
break;
default:
expert_add_info_format(pinfo, item, &ei_giop_unknown_typecode_datatype, "Unknown typecode data type %u", data_type);
break;
}
}
static void dissect_typecode_string_param(tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean new_stream_is_big_endian, guint32 new_boundary, int hf_id ) {
guint32 u_octet4;
const gchar *buf;
u_octet4 = get_CDR_string(tvb, &buf, offset, new_stream_is_big_endian, new_boundary);
proto_tree_add_uint(tree, hf_giop_string_length, tvb,
*offset-u_octet4-4, 4, u_octet4);
if (u_octet4 > 0) {
proto_tree_add_string(tree, hf_id, tvb, *offset-u_octet4, u_octet4, buf);
}
}
static void dissect_tk_objref_params(tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
}
static void dissect_tk_struct_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header ) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
guint32 count;
guint32 i;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
count = get_CDR_ulong(tvb, offset, new_stream_is_big_endian, new_boundary);
if (tree) {
proto_tree_add_uint(tree, hf_giop_typecode_count, tvb,
*offset-(int)sizeof(count), 4, count);
}
for (i=0; i< count; i++) {
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_member_name);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
}
}
static void dissect_tk_union_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item* item,
gint *offset, gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
guint32 TCKind;
gint32 s_octet4;
guint32 count;
guint32 i;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
TCKind = get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
s_octet4 = get_CDR_long(tvb, offset, new_stream_is_big_endian, new_boundary);
proto_tree_add_int(tree, hf_giop_typecode_default_used, tvb,
*offset-4, 4, s_octet4);
count = get_CDR_ulong(tvb, offset, new_stream_is_big_endian, new_boundary);
proto_tree_add_uint(tree, hf_giop_typecode_count, tvb, *offset-4, 4, count);
for (i=0; i< count; i++) {
dissect_data_for_typecode(tvb, pinfo, tree, item, offset, new_stream_is_big_endian, new_boundary, header, TCKind );
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_member_name);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
}
}
static void dissect_tk_enum_params(tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
guint32 count;
guint32 i;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
count = get_CDR_ulong(tvb, offset, new_stream_is_big_endian, new_boundary);
proto_tree_add_uint(tree, hf_giop_typecode_count, tvb,
*offset-4, 4, count);
for (i=0; i< count; i++) {
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_member_name);
}
}
static void dissect_tk_sequence_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
guint32 u_octet4;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_typecode_max_length, tvb,
*offset-4, 4, u_octet4);
}
static void dissect_tk_array_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
guint32 u_octet4;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_typecode_length, tvb,
*offset-4, 4, u_octet4);
}
static void dissect_tk_alias_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
}
static void dissect_tk_except_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
guint32 count;
guint32 i;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
count = get_CDR_ulong(tvb, offset, new_stream_is_big_endian, new_boundary);
if (tree) {
proto_tree_add_uint(tree, hf_giop_typecode_count, tvb,
*offset-(int)sizeof(count), 4, count);
}
for (i=0; i< count; i++) {
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_member_name);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
}
}
static void dissect_tk_value_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
gint16 s_octet2;
guint32 count;
guint32 i;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
s_octet2 = get_CDR_short(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_int(tree, hf_giop_typecode_ValueModifier, tvb,
*offset-2, 2, s_octet2);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
count = get_CDR_ulong(tvb, offset, new_stream_is_big_endian, new_boundary);
proto_tree_add_uint(tree, hf_giop_typecode_count, tvb,
*offset-4, 4, count);
for (i=0; i< count; i++) {
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_member_name);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
s_octet2 = get_CDR_short(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_int(tree, hf_giop_typecode_Visibility, tvb,
*offset-(int)sizeof(s_octet2), 2, s_octet2);
}
}
}
static void dissect_tk_value_box_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary,
MessageHeader * header) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
get_CDR_typeCode(tvb, pinfo, tree, offset, new_stream_is_big_endian, new_boundary, header);
}
static void dissect_tk_native_params(tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
}
static void dissect_tk_abstract_interface_params(tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian, guint32 boundary) {
guint32 new_boundary;
gboolean new_stream_is_big_endian;
get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_stream_is_big_endian, &new_boundary);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_repoid);
dissect_typecode_string_param(tvb, tree, offset, new_stream_is_big_endian, new_boundary,
hf_giop_typecode_name);
}
guint32 get_CDR_encap_info(tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean old_stream_is_big_endian, guint32 old_boundary,
gboolean *new_stream_is_big_endian_ptr, guint32 *new_boundary_ptr ) {
guint32 seqlen;
guint8 giop_endianness;
seqlen = get_CDR_ulong(tvb, offset, old_stream_is_big_endian, old_boundary);
proto_tree_add_uint(tree, hf_giop_sequence_length, tvb,
*offset-(int)sizeof(seqlen), 4, seqlen);
if (seqlen == 0) {
*new_boundary_ptr = old_boundary;
*new_stream_is_big_endian_ptr = old_stream_is_big_endian;
return seqlen;
}
*new_boundary_ptr = *offset;
giop_endianness = get_CDR_octet(tvb, offset);
*new_stream_is_big_endian_ptr = ! giop_endianness;
proto_tree_add_uint(tree, hf_giop_endianness, tvb,
*offset-1, 1, giop_endianness);
return seqlen;
}
void get_CDR_any(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item,
gint *offset, gboolean stream_is_big_endian, int boundary,
MessageHeader * header ) {
guint32 TCKind;
TCKind = get_CDR_typeCode(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
dissect_data_for_typecode(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header, TCKind );
}
gboolean get_CDR_boolean(tvbuff_t *tvb, int *offset) {
guint8 val;
val = tvb_get_guint8(tvb, *offset);
(*offset)++;
return val;
}
guint8 get_CDR_char(tvbuff_t *tvb, int *offset) {
guint8 val;
val = tvb_get_guint8(tvb, *offset);
(*offset)++;
return val;
}
gdouble get_CDR_double(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
gdouble val;
while ( ( (*offset + boundary) % 8) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntohieee_double (tvb, *offset) :
tvb_get_letohieee_double (tvb, *offset);
*offset += 8;
return val;
}
guint32 get_CDR_enum(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
return get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary );
}
void get_CDR_fixed(tvbuff_t *tvb, packet_info *pinfo, proto_item *item, gchar **seq,
gint *offset, guint32 digits, gint32 scale) {
guint8 sign;
guint32 i ;
guint32 slen;
guint32 sindex = 0;
gchar *tmpbuf;
guint8 tval;
#if DEBUG
printf("giop:get_CDR_fixed() called , digits = %u, scale = %u \n", digits, scale);
#endif
if (scale <0) {
slen = digits - scale;
} else {
slen = digits;
}
#if DEBUG
printf("giop:get_CDR_fixed(): slen = %.2x \n", slen);
#endif
tmpbuf = (gchar *)wmem_alloc0(wmem_packet_scope(), slen);
if (!(digits & 0x01)) {
tval = get_CDR_octet(tvb, offset);
#if DEBUG
printf("giop:get_CDR_fixed():even: octet = %.2x \n", tval);
#endif
tmpbuf[sindex] = (tval & 0x0f) + 0x30;
sindex++;
}
if (digits>2) {
for (i=0; i< ((digits-1)/2 ); i++) {
tval = get_CDR_octet(tvb, offset);
#if DEBUG
printf("giop:get_CDR_fixed():odd: octet = %.2x \n", tval);
#endif
tmpbuf[sindex] = ((tval & 0xf0) >> 4) + 0x30;
sindex++;
tmpbuf[sindex] = (tval & 0x0f) + 0x30;
sindex++;
}
}
#if DEBUG
printf("giop:get_CDR_fixed(): before last digit \n");
#endif
tval = get_CDR_octet(tvb, offset);
#if DEBUG
printf("giop:get_CDR_fixed(): octet = %.2x \n", tval);
#endif
tmpbuf[sindex] = (( tval & 0xf0)>> 4) + 0x30;
sindex++;
sign = tval & 0x0f;
sindex = 0;
*seq = wmem_alloc0_array(wmem_packet_scope(), gchar, slen + 3);
#if DEBUG
printf("giop:get_CDR_fixed(): sign = %.2x \n", sign);
#endif
switch (sign) {
case 0x0c:
(*seq)[sindex] = '+';
break;
case 0x0d:
(*seq)[sindex] = '-';
break;
default:
expert_add_info_format(pinfo, item, &ei_giop_unknown_sign_value,
"Unknown sign value in fixed type %u", sign);
(*seq)[sindex] = '*';
break;
}
sindex++;
if (scale>0) {
for (i=0; i<digits-scale; i++) {
(*seq)[sindex] = tmpbuf[i];
sindex++;
}
(*seq)[sindex] = '.';
sindex++;
for (i=digits-scale; i<digits; i++) {
(*seq)[sindex] = tmpbuf[i];
sindex++;
}
(*seq)[sindex] = '\0';
} else {
for (i=0; i<digits-scale; i++) {
if (i<digits) {
(*seq)[sindex] = tmpbuf[i];
} else {
(*seq)[sindex] = '0';
}
sindex++;
}
(*seq)[sindex] = '\0';
}
#if DEBUG
printf("giop:get_CDR_fixed(): value = %s \n", *seq);
#endif
return;
}
gfloat get_CDR_float(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
gfloat val;
while ( ( (*offset + boundary) % 4) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntohieee_float (tvb, *offset) :
tvb_get_letohieee_float (tvb, *offset);
*offset += 4;
return val;
}
void get_CDR_interface(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset,
gboolean stream_is_big_endian, int boundary) {
decode_IOR(tvb, pinfo, tree, offset, boundary, stream_is_big_endian);
return;
}
gint32 get_CDR_long(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
gint32 val;
while ( ( (*offset + boundary) % 4) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntohl (tvb, *offset) :
tvb_get_letohl (tvb, *offset);
*offset += 4;
return val;
}
gint64 get_CDR_long_long(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
gint64 val;
while ( ( (*offset + boundary) % 8) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntoh64 (tvb, *offset) :
tvb_get_letoh64 (tvb, *offset);
*offset += 8;
return val;
}
void get_CDR_object(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset,
gboolean stream_is_big_endian, int boundary) {
decode_IOR(tvb, pinfo, tree, offset, boundary, stream_is_big_endian);
return;
}
guint8 get_CDR_octet(tvbuff_t *tvb, int *offset) {
guint8 val;
val = tvb_get_guint8(tvb, *offset);
(*offset)++;
return val;
}
void get_CDR_octet_seq(tvbuff_t *tvb, const gchar **seq, int *offset, guint32 len) {
guint8 *seq_buf;
tvb_ensure_bytes_exist(tvb, *offset, len);
seq_buf = wmem_alloc0_array(wmem_packet_scope(), gchar, len + 1);
tvb_memcpy( tvb, seq_buf, *offset, len);
*seq = seq_buf;
*offset += len;
}
gint16 get_CDR_short(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
gint16 val;
while ( ( (*offset + boundary) % 2) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntohs (tvb, *offset) :
tvb_get_letohs (tvb, *offset);
*offset += 2;
return val;
}
void
giop_add_CDR_string(proto_tree *tree, tvbuff_t *tvb, int *offset,
gboolean stream_is_big_endian, int boundary, int hf)
{
guint32 u_octet4;
const gchar *seq = NULL;
u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
proto_tree_add_string(tree, hf, tvb, *offset-u_octet4, u_octet4, (u_octet4 > 0) ? seq : "");
}
guint32 get_CDR_string(tvbuff_t *tvb, const gchar **seq, int *offset, gboolean stream_is_big_endian,
int boundary ) {
guint32 slength;
gint reported_length;
slength = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
#if 0
(*offset)++;
#endif
reported_length = tvb_reported_length_remaining(tvb, *offset-4);
if (slength > (guint32)reported_length) {
get_CDR_octet_seq(tvb, seq, offset, reported_length);
return reported_length;
}
else if (slength > 0) {
get_CDR_octet_seq(tvb, seq, offset, slength);
} else {
*seq = wmem_strdup(wmem_packet_scope(), "");
}
return slength;
}
guint32 get_CDR_typeCode(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree,
gint *offset, gboolean stream_is_big_endian,
int boundary, MessageHeader * header ) {
guint32 val;
gint16 s_octet2;
guint16 u_octet2;
guint32 u_octet4;
proto_item *ti;
val = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
ti = proto_tree_add_uint(tree, hf_giop_TCKind, tvb, *offset-4, 4, val);
switch (val) {
case tk_null:
break;
case tk_void:
break;
case tk_short:
break;
case tk_long:
break;
case tk_ushort:
break;
case tk_ulong:
break;
case tk_float:
break;
case tk_double:
break;
case tk_boolean:
break;
case tk_char:
break;
case tk_octet:
break;
case tk_any:
break;
case tk_TypeCode:
break;
case tk_Principal:
break;
case tk_objref:
dissect_tk_objref_params(tvb, tree, offset, stream_is_big_endian, boundary);
break;
case tk_struct:
dissect_tk_struct_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_union:
dissect_tk_union_params(tvb, pinfo, tree, ti, offset, stream_is_big_endian, boundary, header );
break;
case tk_enum:
dissect_tk_enum_params(tvb, tree, offset, stream_is_big_endian, boundary);
break;
case tk_string:
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_uint(tree, hf_giop_typecode_max_length, tvb,
*offset-(int)sizeof(u_octet4), 4, u_octet4);
}
break;
case tk_sequence:
dissect_tk_sequence_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_array:
dissect_tk_array_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_alias:
dissect_tk_alias_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_except:
dissect_tk_except_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_longlong:
break;
case tk_ulonglong:
break;
case tk_longdouble:
break;
case tk_wchar:
break;
case tk_wstring:
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_uint(tree, hf_giop_typecode_max_length, tvb,
*offset-(int)sizeof(u_octet4), 4, u_octet4);
}
break;
case tk_fixed:
u_octet2 = get_CDR_ushort(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_uint(tree, hf_giop_typecode_digits, tvb,
*offset-(int)sizeof(u_octet2), 2, u_octet2);
}
s_octet2 = get_CDR_short(tvb, offset, stream_is_big_endian, boundary);
if (tree) {
proto_tree_add_int(tree, hf_giop_typecode_scale, tvb,
*offset-(int)sizeof(s_octet2), 2, s_octet2);
}
break;
case tk_value:
dissect_tk_value_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_value_box:
dissect_tk_value_box_params(tvb, pinfo, tree, offset, stream_is_big_endian, boundary, header );
break;
case tk_native:
dissect_tk_native_params(tvb, tree, offset, stream_is_big_endian, boundary);
break;
case tk_abstract_interface:
dissect_tk_abstract_interface_params(tvb, tree, offset, stream_is_big_endian, boundary );
break;
default:
expert_add_info_format(pinfo, ti, &ei_giop_unknown_tckind, "Unknown TCKind %u", val);
break;
}
return val;
}
guint32 get_CDR_ulong(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
guint32 val;
while ( ( (*offset + boundary) % 4) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntohl (tvb, *offset) :
tvb_get_letohl (tvb, *offset);
*offset += 4;
return val;
}
guint64 get_CDR_ulong_long(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
guint64 val;
while ( ( (*offset + boundary) % 8) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntoh64 (tvb, *offset) :
tvb_get_letoh64 (tvb, *offset);
*offset += 8;
return val;
}
guint16 get_CDR_ushort(tvbuff_t *tvb, int *offset, gboolean stream_is_big_endian, int boundary) {
guint16 val;
while ( ( (*offset + boundary) % 2) != 0)
++(*offset);
val = (stream_is_big_endian) ? tvb_get_ntohs (tvb, *offset) :
tvb_get_letohs (tvb, *offset);
*offset += 2;
return val;
}
gint get_CDR_wchar(tvbuff_t *tvb, const gchar **seq, int *offset, MessageHeader * header) {
gint slength;
const gchar *raw_wstring;
*seq = NULL;
slength = 2;
if (header->GIOP_version.minor > 1)
slength = get_CDR_octet(tvb, offset);
if (slength > 0) {
get_CDR_octet_seq(tvb, &raw_wstring, offset, slength);
*seq = make_printable_string(raw_wstring, slength);
}
if (header->GIOP_version.minor < 2)
slength = -slength;
return slength;
}
guint32 get_CDR_wstring(tvbuff_t *tvb, const gchar **seq, int *offset, gboolean stream_is_big_endian,
int boundary, MessageHeader * header) {
guint32 slength;
gint reported_length;
const gchar *raw_wstring;
*seq = NULL;
slength = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
#ifdef DEBUG
if (slength>200) {
fprintf(stderr, "giop:get_CDR_wstring, length %u > 200, truncating to 5 \n", slength);
slength = 5;
}
#endif
if (header->GIOP_version.minor < 2) {
#if 0
(*offset)++;
#endif
slength = slength * 2;
}
reported_length = tvb_reported_length_remaining(tvb, *offset-4);
if (slength > (guint32)reported_length) {
slength = reported_length;
}
if (slength > 0) {
get_CDR_octet_seq(tvb, &raw_wstring, offset, slength);
*seq = make_printable_string(raw_wstring, slength);
}
return slength;
}
static void
dissect_target_address(tvbuff_t * tvb, packet_info *pinfo, int *offset, proto_tree * tree,
gboolean stream_is_big_endian, guint32 *object_key_len,
const gchar **object_key_val)
{
guint16 discriminant;
const gchar *object_key = NULL;
guint32 len = 0;
guint32 u_octet4;
proto_item* ti;
discriminant = get_CDR_ushort(tvb, offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (tree, hf_giop_target_address_discriminant, tvb, *offset -2, 2, discriminant);
switch (discriminant)
{
case 0:
len = get_CDR_ulong(tvb, offset, stream_is_big_endian, GIOP_HEADER_SIZE);
ti = proto_tree_add_uint (tree, hf_giop_target_address_key_addr_len, tvb, *offset -4, 4, len);
if (len > (guint32)tvb_reported_length_remaining(tvb, *offset-4)) {
expert_add_info_format(pinfo, ti, &ei_giop_length_too_big, "KeyAddr key length bigger than packet size");
return;
}
if (len > 0) {
get_CDR_octet_seq(tvb, &object_key, offset, len);
proto_tree_add_string(tree, hf_giop_target_address_key_addr, tvb, *offset - len,
len, make_printable_string( object_key, len ));
if (object_key_len) {
*object_key_len = len;
}
if (object_key_val) {
*object_key_val = object_key;
}
}
break;
case 1:
decode_TaggedProfile(tvb, pinfo, tree, offset, GIOP_HEADER_SIZE,
stream_is_big_endian, NULL);
break;
case 2:
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (tree, hf_giop_target_address_ref_addr_len, tvb, *offset -4, 4, u_octet4);
decode_IOR(tvb, pinfo, tree, offset, GIOP_HEADER_SIZE, stream_is_big_endian);
break;
default:
break;
}
}
static void decode_CodeSetServiceContext(tvbuff_t *tvb, proto_tree *tree,
int *offset, gboolean stream_is_be,
guint32 boundary) {
guint32 code_set_id;
code_set_id = get_CDR_ulong(tvb, offset, stream_is_be, -((gint32) boundary) );
proto_tree_add_uint(tree, hf_giop_char_data, tvb, *offset - 4, 4, code_set_id);
code_set_id = get_CDR_ulong(tvb, offset, stream_is_be, -((gint32) boundary) );
proto_tree_add_uint(tree, hf_giop_wchar_data, tvb, *offset - 4, 4, code_set_id);
}
static void decode_RTCorbaPriority(tvbuff_t *tvb, proto_tree *tree, int *offset,
gboolean stream_is_be, guint32 boundary) {
gint16 rtpriority;
rtpriority = get_CDR_short(tvb, offset, stream_is_be, -((gint32) boundary) );
proto_tree_add_uint(tree, hf_giop_rt_corba_priority, tvb, *offset - 2, 2, rtpriority);
}
static void decode_UnknownServiceContext(tvbuff_t *tvb, proto_tree *tree,
int *offset, gboolean stream_is_be _U_,
guint32 boundary _U_,
guint32 context_data_len) {
const gchar *context_data;
if (context_data_len == 0)
return;
get_CDR_octet_seq(tvb, &context_data, offset, context_data_len);
proto_tree_add_string(tree, hf_giop_context_data, tvb, *offset - context_data_len ,
context_data_len, make_printable_string( context_data, context_data_len));
}
static void decode_ServiceContextList(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *ptree, int *offset,
gboolean stream_is_be, guint32 boundary) {
guint32 seqlen;
guint32 context_data_len;
proto_tree *tree;
proto_item *tf;
proto_item *sc_item;
proto_tree *sc_tree;
guint32 context_id;
guint32 i;
guint32 vscid;
guint32 scid;
gboolean encapsulation_is_be;
guint32 encapsulation_boundary;
int temp_offset;
int start_offset = *offset;
int dissected_len;
tf = proto_tree_add_text (ptree, tvb, *offset, -1, "ServiceContextList");
tree = proto_item_add_subtree (tf, ett_giop_scl);
seqlen = get_CDR_ulong(tvb, offset, stream_is_be, boundary);
proto_tree_add_uint(tree, hf_giop_sequence_length, tvb,
*offset-(int)sizeof(seqlen), 4, seqlen);
if (seqlen == 0) {
if (tf) {
if (*offset - start_offset <= 0)
THROW(ReportedBoundsError);
proto_item_set_len(tf, *offset - start_offset);
}
return;
}
for (i=0; i<seqlen; i++) {
context_id = get_CDR_ulong(tvb, offset, stream_is_be, boundary);
sc_item = proto_tree_add_item(tree, hf_giop_iiop_sc, tvb, *offset-4, -1, ENC_NA);
sc_tree = proto_item_add_subtree (sc_item, ett_giop_sc);
vscid = (context_id & 0xffffff00) >> 8;
scid = context_id & 0x000000ff;
proto_tree_add_uint(sc_tree, hf_giop_iiop_sc_vscid, tvb,
*offset-4, 4, vscid);
if (vscid == 0)
{
proto_tree_add_uint(sc_tree, hf_giop_iiop_sc_omg_scid, tvb,
*offset-4, 4, scid);
}
else
{
proto_tree_add_uint(sc_tree, hf_giop_iiop_sc_vendor_scid, tvb,
*offset-4, 4, scid);
}
temp_offset = *offset;
context_data_len = get_CDR_encap_info(tvb, sc_tree, offset,
stream_is_be, boundary,
&encapsulation_is_be,
&encapsulation_boundary);
if (context_data_len != 0)
{
if ( vscid != 0)
{
decode_UnknownServiceContext(tvb, sc_tree, offset, encapsulation_is_be,
encapsulation_boundary,
context_data_len - 1);
}
else
{
switch (scid)
{
case 0x01:
decode_CodeSetServiceContext(tvb, sc_tree, offset,
encapsulation_is_be,
encapsulation_boundary);
break;
case 0x0a:
decode_RTCorbaPriority(tvb, sc_tree, offset,
encapsulation_is_be, encapsulation_boundary);
break;
default:
decode_UnknownServiceContext(tvb, sc_tree, offset,
encapsulation_is_be,
encapsulation_boundary,
context_data_len - 1);
break;
}
}
}
dissected_len = *offset - (temp_offset + 4);
if ((guint32)dissected_len > context_data_len)
{
*offset = temp_offset + 4 + context_data_len;
}
else if ((guint32)dissected_len < context_data_len)
{
tvb_ensure_bytes_exist(tvb, *offset, context_data_len - dissected_len);
*offset = temp_offset + 4 + context_data_len;
}
proto_item_set_end(sc_item, tvb, *offset);
}
proto_item_set_len(tf, *offset - start_offset);
}
static void
dissect_reply_body (tvbuff_t *tvb, guint offset, packet_info *pinfo,
proto_tree *tree, gboolean stream_is_big_endian,
guint32 reply_status, MessageHeader *header, proto_tree *clnp_tree) {
guint sequence_length;
gboolean exres = FALSE;
gint reply_body_length;
comp_req_list_entry_t *entry = NULL;
guint32 mfn;
switch (reply_status)
{
case SYSTEM_EXCEPTION:
decode_SystemExceptionReplyBody (tvb, tree, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
break;
case USER_EXCEPTION:
sequence_length = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint(tree, hf_giop_exception_len, tvb, offset-4, 4,
sequence_length);
if (sequence_length != 0 && sequence_length < ITEM_LABEL_LENGTH)
{
header->exception_id = tvb_get_stringz(wmem_packet_scope(), tvb, offset, &sequence_length);
proto_tree_add_string(tree, hf_giop_exception_id, tvb, offset,
sequence_length, header->exception_id);
offset += sequence_length;
}
case NO_EXCEPTION:
mfn = get_mfn_from_fn(pinfo->fd->num);
if (mfn == pinfo->fd->num)
return;
entry = find_fn_in_list(mfn);
if (!entry)
return;
if (!strcmp(giop_op_resolve, entry->operation)) {
decode_IOR(tvb, pinfo, tree, &offset, GIOP_HEADER_SIZE, stream_is_big_endian);
return;
}
if (entry->repoid) {
exres = try_explicit_giop_dissector(tvb, pinfo, clnp_tree, &offset, header, entry->operation, entry->repoid );
}
if (! exres) {
exres = try_heuristic_giop_dissector(tvb, pinfo, clnp_tree, &offset, header, entry->operation);
}
if (!exres && !strcmp(giop_op_is_a, entry->operation) && tree) {
proto_tree_add_text(tree, tvb, offset - 1, 1, "Type Id%s matched",
get_CDR_boolean(tvb, &offset) ? "" : " not");
}
if (! exres) {
gint stub_length = tvb_reported_length_remaining(tvb, offset);
if (stub_length >0)
proto_tree_add_item(tree, hf_giop_stub_data, tvb,
offset, stub_length, ENC_NA);
}
break;
case LOCATION_FORWARD:
decode_IOR(tvb, pinfo, tree, &offset, GIOP_HEADER_SIZE, stream_is_big_endian);
break;
case LOCATION_FORWARD_PERM:
decode_IOR(tvb, pinfo, tree, &offset, GIOP_HEADER_SIZE, stream_is_big_endian);
break;
case NEEDS_ADDRESSING_MODE: {
guint16 addr_disp;
addr_disp = get_CDR_ushort(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (tree, hf_giop_address_disp, tvb, offset-2, 2, addr_disp);
break;
}
default:
reply_body_length = tvb_reported_length_remaining(tvb, offset);
if (reply_body_length >0)
proto_tree_add_item(tree, hf_giop_reply_body, tvb,
offset, reply_body_length, ENC_NA);
break;
}
}
static void dissect_giop_reply (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
MessageHeader * header,
gboolean stream_is_big_endian) {
guint32 offset = 0;
guint32 request_id;
guint32 reply_status;
proto_tree *reply_tree;
proto_item *tf;
guint32 mfn;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Protocol Reply");
reply_tree = proto_item_add_subtree (tf, ett_giop_reply);
decode_ServiceContextList(tvb, pinfo, reply_tree, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id );
proto_tree_add_uint(reply_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
reply_status = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str(reply_status, reply_status_types, "Unknown (%u)"));
proto_tree_add_uint(reply_tree, hf_giop_reply_status, tvb,
offset-4, 4, reply_status);
if (! pinfo->fd->flags.visited) {
mfn = get_mfn_from_fn_and_reqid(pinfo->fd->num, request_id);
if (mfn != pinfo->fd->num) {
insert_in_complete_reply_hash(pinfo->fd->num, mfn);
}
}
header->req_id = request_id;
header->rep_status = reply_status;
if (tvb_reported_length_remaining(tvb, offset) > 0)
dissect_reply_body(tvb, offset, pinfo, reply_tree, stream_is_big_endian,
reply_status, header, tree);
}
static void dissect_giop_reply_1_2 (tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree,
MessageHeader * header,
gboolean stream_is_big_endian) {
guint offset = 0;
guint32 request_id;
guint32 reply_status;
proto_tree *reply_tree;
proto_item *tf;
guint32 mfn;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Protocol Reply");
reply_tree = proto_item_add_subtree (tf, ett_giop_reply);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id);
proto_tree_add_uint (reply_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
reply_status = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str(reply_status, reply_status_types, "Unknown (%u)"));
proto_tree_add_uint(reply_tree, hf_giop_reply_status, tvb,
offset-4, 4, reply_status);
decode_ServiceContextList(tvb, pinfo, reply_tree, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
set_new_alignment(&offset, GIOP_HEADER_SIZE, 8);
if (! pinfo->fd->flags.visited) {
mfn = get_mfn_from_fn_and_reqid(pinfo->fd->num, request_id);
if (mfn != pinfo->fd->num) {
insert_in_complete_reply_hash(pinfo->fd->num, mfn);
}
}
header->req_id = request_id;
header->rep_status = reply_status;
dissect_reply_body(tvb, offset, pinfo, reply_tree, stream_is_big_endian,
reply_status, header, tree);
}
static void dissect_giop_cancel_request (tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree,
gboolean stream_is_big_endian) {
guint offset = 0;
guint32 request_id;
proto_tree *cancel_request_tree;
proto_item *tf;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Protocol CancelRequest");
cancel_request_tree = proto_item_add_subtree (tf, ett_giop_cancel_request);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id);
proto_tree_add_uint (cancel_request_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
}
static void
dissect_giop_request_1_1 (tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree,
MessageHeader * header, gboolean stream_is_big_endian)
{
guint32 offset = 0;
guint32 request_id;
guint32 len = 0;
guint32 objkey_len = 0;
const gchar *objkey = NULL;
gboolean exres = FALSE;
const gchar *operation;
const gchar *requesting_principal;
guint8 response_expected;
const gchar *reserved;
gchar miop[4];
proto_tree *request_tree;
proto_item *tf;
gchar *repoid;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Protocol Request");
request_tree = proto_item_add_subtree (tf, ett_giop_request);
decode_ServiceContextList(tvb, pinfo, request_tree, &offset, stream_is_big_endian, 0);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id);
proto_tree_add_uint (request_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
response_expected = tvb_get_guint8( tvb, offset );
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
response_expected ? "two-way" : "one-way");
proto_tree_add_item(request_tree, hf_giop_rsp_expected, tvb, offset, 1, ENC_NA);
offset += 1;
if ( header->GIOP_version.minor > 0)
{
get_CDR_octet_seq( tvb, &reserved, &offset, 3);
proto_tree_add_item(request_tree, hf_giop_reserved, tvb, offset-3, 3, ENC_NA);
}
miop[0] = get_CDR_octet (tvb, &offset);
miop[1] = get_CDR_octet (tvb, &offset);
miop[2] = get_CDR_octet (tvb, &offset);
miop[3] = get_CDR_octet (tvb, &offset);
if (miop[0] == 'M' && miop[1] == 'I' && miop[2] == 'O' && miop[3] == 'P')
{
proto_tree_add_text (request_tree, tvb, offset - 4, 4, "Magic number: MIOP");
decode_TaggedProfile (tvb, pinfo, request_tree, &offset, GIOP_HEADER_SIZE,
stream_is_big_endian, NULL);
}
else
{
offset -= 4;
objkey_len = get_CDR_ulong (tvb, &offset, stream_is_big_endian,
GIOP_HEADER_SIZE);
tf = proto_tree_add_uint (request_tree, hf_giop_objekt_key_len, tvb, offset-4, 4, objkey_len);
if (objkey_len > (guint32)tvb_reported_length_remaining(tvb, offset-4)) {
expert_add_info_format(pinfo, tf, &ei_giop_length_too_big, "Object key length bigger than packet size");
return;
}
if (objkey_len > 0)
{
get_CDR_octet_seq(tvb, &objkey, &offset, objkey_len);
proto_tree_add_item(request_tree, hf_giop_objekt_key, tvb,
offset - objkey_len, objkey_len, ENC_NA);
}
}
len = get_CDR_string(tvb, &operation, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (request_tree, hf_giop_req_operation_len, tvb, offset - 4 - len, 4, len);
if ( len > 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": op=%s", format_text(operation, (size_t)len));
proto_tree_add_string(request_tree, hf_giop_req_operation, tvb, offset - len, len, operation);
}
len = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
tf = proto_tree_add_uint (request_tree, hf_giop_req_principal_len, tvb, offset - 4, 4, len);
if (len > (guint32)tvb_reported_length_remaining(tvb, offset-4)) {
expert_add_info_format(pinfo, tf, &ei_giop_length_too_big, "Requesting Principal length bigger than packet size");
return;
}
if ( len > 0)
{
get_CDR_octet_seq(tvb, &requesting_principal, &offset, len);
proto_tree_add_string(request_tree, hf_giop_req_principal, tvb, offset - len, len,
make_printable_string(requesting_principal, len));
}
if (! pinfo->fd->flags.visited)
giop_complete_request_list = insert_in_comp_req_list(giop_complete_request_list, pinfo->fd->num,
request_id, operation, NULL);
header->req_id = request_id;
repoid = get_repoid_from_objkey(giop_objkey_hash, objkey, objkey_len);
if (repoid) {
exres = try_explicit_giop_dissector(tvb, pinfo, tree, &offset, header, operation, repoid);
}
if (! exres) {
exres = try_heuristic_giop_dissector(tvb, pinfo, tree, &offset, header, operation);
}
if (!exres && !strcmp(giop_op_is_a, operation) && request_tree) {
const gchar *type_id;
len = get_CDR_string(tvb, &type_id, &offset, stream_is_big_endian, 0);
proto_tree_add_uint (request_tree, hf_giop_type_id_len, tvb, offset - 4 - len, 4, len);
proto_tree_add_string(request_tree, hf_giop_type_id, tvb, offset - len, len, type_id);
}
if (! exres) {
gint stub_length = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(request_tree, hf_giop_stub_data, tvb,
offset, stub_length, ENC_NA);
}
}
static void
dissect_giop_request_1_2 (tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree,
MessageHeader * header, gboolean stream_is_big_endian)
{
guint32 offset = 0;
guint32 request_id;
guint32 len = 0;
const gchar *reserved;
const gchar *operation = NULL;
proto_tree *request_tree;
proto_item *tf;
gboolean exres = FALSE;
guint32 objkey_len = 0;
const gchar *objkey = NULL;
gchar *repoid = NULL;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Protocol Request");
request_tree = proto_item_add_subtree (tf, ett_giop_request);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
header->req_id = request_id;
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id);
proto_tree_add_uint (request_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
proto_tree_add_item(request_tree, hf_giop_response_flag, tvb,
offset, 1, ENC_NA);
offset += 1;
get_CDR_octet_seq( tvb, &reserved, &offset, 3);
proto_tree_add_item(request_tree, hf_giop_reserved, tvb, offset-3, 3, ENC_NA);
dissect_target_address(tvb, pinfo, &offset, request_tree, stream_is_big_endian,
&objkey_len, &objkey);
if (objkey) {
repoid = get_repoid_from_objkey(giop_objkey_hash, objkey, objkey_len);
}
len = get_CDR_string(tvb, &operation, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (request_tree, hf_giop_req_operation_len, tvb, offset - 4 - len, 4, len);
if ( len > 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ": op=%s", format_text(operation, (size_t)len));
proto_tree_add_string(request_tree, hf_giop_req_operation, tvb, offset - len, len, operation);
}
decode_ServiceContextList(tvb, pinfo, request_tree, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
set_new_alignment(&offset, GIOP_HEADER_SIZE, 8);
}
if (! pinfo->fd->flags.visited)
giop_complete_request_list = insert_in_comp_req_list(giop_complete_request_list, pinfo->fd->num,
request_id, operation, NULL);
if (repoid) {
exres = try_explicit_giop_dissector(tvb, pinfo, tree, &offset, header, operation, repoid);
}
if (! exres) {
exres = try_heuristic_giop_dissector(tvb, pinfo, tree, &offset, header, operation);
}
if (!exres && !strcmp(giop_op_is_a, operation) && request_tree) {
const gchar *type_id;
len = get_CDR_string(tvb, &type_id, &offset, stream_is_big_endian, 0);
proto_tree_add_uint (request_tree, hf_giop_type_id_len, tvb, offset - 4 - len, 4, len);
proto_tree_add_string(request_tree, hf_giop_type_id, tvb, offset - len, len, type_id);
}
if (! exres) {
gint stub_length = tvb_reported_length_remaining(tvb, offset);
if (stub_length > 0)
proto_tree_add_item(request_tree, hf_giop_stub_data, tvb,
offset, stub_length, ENC_NA);
}
}
static void
dissect_giop_locate_request( tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree, MessageHeader * header,
gboolean stream_is_big_endian)
{
guint32 offset = 0;
guint32 request_id;
guint32 len = 0;
proto_tree *locate_request_tree;
proto_item *tf;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Locate Request");
locate_request_tree = proto_item_add_subtree (tf, ett_giop_locate_request);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u op=LocateRequest", request_id);
proto_tree_add_uint (locate_request_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
if (header->GIOP_version.minor < 2)
{
len = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (locate_request_tree, hf_giop_objekt_key_len, tvb, offset-4, 4, len);
if (len > (guint32)tvb_reported_length_remaining(tvb, offset-4)) {
expert_add_info_format(pinfo, tf, &ei_giop_length_too_big, "Object key length bigger than packet size");
return;
}
if (len > 0) {
proto_tree_add_item(locate_request_tree, hf_giop_objekt_key, tvb, offset-len, len, ENC_NA);
}
}
else
{
dissect_target_address(tvb, pinfo, &offset, locate_request_tree,
stream_is_big_endian, NULL, NULL);
}
}
static void
dissect_giop_locate_reply( tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree, MessageHeader * header,
gboolean stream_is_big_endian)
{
guint32 offset = 0;
guint32 request_id;
guint32 locate_status;
guint16 addr_disp;
proto_tree *locate_reply_tree;
proto_item *tf;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Locate Reply");
locate_reply_tree = proto_item_add_subtree (tf, ett_giop_locate_reply);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id);
proto_tree_add_uint (locate_reply_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
locate_status = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (locate_reply_tree, hf_giop_locale_status, tvb, offset-4, 4, locate_status);
if (header->GIOP_version.minor > 1) {
while ( ( (offset + GIOP_HEADER_SIZE) % 8) != 0)
++(offset);
}
switch (locate_status) {
case OBJECT_FORWARD:
case OBJECT_FORWARD_PERM:
decode_IOR(tvb, pinfo, locate_reply_tree, &offset, GIOP_HEADER_SIZE, stream_is_big_endian);
break;
case LOC_SYSTEM_EXCEPTION:
decode_SystemExceptionReplyBody (tvb, tree, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
break;
case LOC_NEEDS_ADDRESSING_MODE:
addr_disp = get_CDR_ushort(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
proto_tree_add_uint (tree, hf_giop_addressing_disposition, tvb, offset-2, 2, addr_disp);
break;
default:
break;
}
}
static void
dissect_giop_fragment( tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
gboolean stream_is_big_endian)
{
guint32 offset = 0;
guint32 request_id;
proto_tree *fragment_tree;
proto_item *tf;
tf = proto_tree_add_text (tree, tvb, offset, -1, "General Inter-ORB Fragment");
fragment_tree = proto_item_add_subtree (tf, ett_giop_fragment);
request_id = get_CDR_ulong(tvb, &offset, stream_is_big_endian, GIOP_HEADER_SIZE);
col_append_fstr(pinfo->cinfo, COL_INFO, " id=%u", request_id);
proto_tree_add_uint (fragment_tree, hf_giop_req_id, tvb, offset-4, 4, request_id);
}
static int dissect_giop_common (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_) {
guint offset = 0;
MessageHeader header;
tvbuff_t *payload_tvb;
proto_tree *giop_tree, *header_tree, *header_version_tree;
proto_item *ti, *version_item;
guint message_size;
gboolean stream_is_big_endian;
#if DEBUG
giop_dump_collection(cd_module_hash);
giop_dump_collection(cd_objkey_hash);
giop_dump_collection(cd_heuristic_users);
giop_dump_collection(cd_complete_reply_hash);
giop_dump_collection(cd_complete_request_list);
#endif
header.exception_id = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GIOP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item (tree, proto_giop, tvb, 0, -1, ENC_NA);
giop_tree = proto_item_add_subtree (ti, ett_giop);
tvb_memcpy (tvb, (guint8 *)&header, 0, GIOP_HEADER_SIZE );
stream_is_big_endian = is_big_endian (&header);
ti = proto_tree_add_text (giop_tree, tvb, offset, GIOP_HEADER_SIZE, "GIOP Header");
header_tree = proto_item_add_subtree (ti, ett_giop_header);
proto_tree_add_item(header_tree, hf_giop_message_magic, tvb, 0, 4, ENC_NA|ENC_ASCII);
version_item = proto_tree_add_text (header_tree, tvb, 4, 2,
"Version: %u.%u", header.GIOP_version.major, header.GIOP_version.minor);
header_version_tree = proto_item_add_subtree (version_item, ett_giop_header_version);
proto_tree_add_item(header_version_tree, hf_giop_message_major_version, tvb, 4, 1, ENC_NA);
proto_tree_add_item(header_version_tree, hf_giop_message_minor_version, tvb, 5, 1, ENC_NA);
if ((header.GIOP_version.major != GIOP_MAJOR) ||
(header.GIOP_version.minor > GIOP_MINOR))
{
col_add_fstr (pinfo->cinfo, COL_INFO, "Version %u.%u",
header.GIOP_version.major, header.GIOP_version.minor);
expert_add_info_format(pinfo, version_item, &ei_giop_version_not_supported, "Version %u.%u not supported",
header.GIOP_version.major, header.GIOP_version.minor);
payload_tvb = tvb_new_subset_remaining (tvb, GIOP_HEADER_SIZE);
call_dissector(data_handle, payload_tvb, pinfo, tree);
return tvb_length(tvb);
}
switch (header.GIOP_version.minor)
{
case 2:
case 1:
ti = proto_tree_add_bitmask(header_version_tree, tvb, 6,
hf_giop_message_flags, ett_giop_message_flags,
giop_message_flags, ENC_BIG_ENDIAN);
if ((header.flags & GIOP_MESSAGE_FLAGS_ENDIANNESS) == 0)
proto_item_append_text(ti, ", (Big Endian)");
break;
case 0:
proto_tree_add_text (header_version_tree, tvb, 6, 1,
"Byte ordering: %s-endian",
(stream_is_big_endian) ? "big" : "little");
ti = proto_tree_add_boolean(header_tree, hf_giop_message_flags_little_endian, tvb, 6, 1, stream_is_big_endian ? 0 : 1);
PROTO_ITEM_SET_HIDDEN(ti);
break;
}
proto_tree_add_item(header_tree, hf_giop_message_type, tvb, 7, 1, ENC_NA);
if (stream_is_big_endian)
{
message_size = tvb_get_ntohl(tvb, 8);
}
else
{
message_size = tvb_get_letohl(tvb, 8);
}
col_add_fstr (pinfo->cinfo, COL_INFO, "GIOP %u.%u %s, s=%u",
header.GIOP_version.major, header.GIOP_version.minor,
val_to_str(header.message_type, giop_message_types, "Unknown message type (0x%02x)"),
message_size);
ti = proto_tree_add_uint(header_tree, hf_giop_message_size, tvb, 8, 4, message_size);
if (message_size > GIOP_MAX_MESSAGE_SIZE)
{
expert_add_info_format(pinfo, ti, &ei_giop_message_size_too_big,
"Message size %u is too big, perhaps it's an endian issue?", message_size);
return 8;
}
if (header.flags & GIOP_MESSAGE_FLAGS_ZIOP_ENABLED)
{
gint rem_len;
rem_len = tvb_length_remaining(tvb, GIOP_HEADER_SIZE);
if (rem_len <= 0)
return 8;
payload_tvb = tvb_child_uncompress(tvb, tvb, GIOP_HEADER_SIZE, rem_len);
if (payload_tvb) {
add_new_data_source (pinfo, payload_tvb, "decompressed Content");
} else {
return 8;
}
} else {
payload_tvb = tvb_new_subset_remaining (tvb, GIOP_HEADER_SIZE);
}
switch (header.message_type)
{
case Request:
if (header.GIOP_version.minor < 2)
{
dissect_giop_request_1_1 (payload_tvb, pinfo, tree,
&header, stream_is_big_endian);
}
else
{
dissect_giop_request_1_2 (payload_tvb, pinfo, tree,
&header, stream_is_big_endian);
}
break;
case Reply:
if (header.GIOP_version.minor < 2)
{
dissect_giop_reply (payload_tvb, pinfo, tree, &header,
stream_is_big_endian);
}
else
{
dissect_giop_reply_1_2 (payload_tvb, pinfo, tree,
&header, stream_is_big_endian);
}
break;
case CancelRequest:
dissect_giop_cancel_request(payload_tvb, pinfo, tree,
stream_is_big_endian);
break;
case LocateRequest:
dissect_giop_locate_request(payload_tvb, pinfo, tree, &header,
stream_is_big_endian);
break;
case LocateReply:
dissect_giop_locate_reply(payload_tvb, pinfo, tree, &header,
stream_is_big_endian);
break;
case Fragment:
dissect_giop_fragment(payload_tvb, pinfo, tree,
stream_is_big_endian);
break;
default:
break;
}
return tvb_length(tvb);
}
static guint
get_giop_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset _U_)
{
MessageHeader header;
guint message_size;
if (tvb_get_ntohl(tvb, 0) != GIOP_MAGIC_NUMBER)
return 0;
header.GIOP_version.minor = tvb_get_guint8(tvb, 5);
header.flags = tvb_get_guint8(tvb, 6);
if (is_big_endian (&header))
message_size = tvb_get_ntohl(tvb, 8);
else
message_size = tvb_get_letohl(tvb, 8);
if (message_size > GIOP_MAX_MESSAGE_SIZE)
return GIOP_HEADER_SIZE;
return message_size + GIOP_HEADER_SIZE;
}
gboolean dissect_giop(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
return dissect_giop_heur(tvb, pinfo, tree, NULL);
}
static int
dissect_giop_tcp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data) {
if (tvb_get_ntohl(tvb, 0) != GIOP_MAGIC_NUMBER) {
if ( tvb_memeql(tvb, 0, ZIOP_MAGIC , 4) == 0)
if (!dissect_ziop_heur(tvb, pinfo, tree, NULL))
return 0;
return tvb_length(tvb);
}
tcp_dissect_pdus(tvb, pinfo, tree, giop_desegment, GIOP_HEADER_SIZE,
get_giop_pdu_len, dissect_giop_common, data);
return tvb_length(tvb);
}
static gboolean
dissect_giop_heur (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data) {
guint tot_len;
conversation_t *conversation;
tot_len = tvb_length(tvb);
if (tot_len < GIOP_HEADER_SIZE)
{
return FALSE;
}
if (tvb_get_ntohl(tvb, 0) != GIOP_MAGIC_NUMBER)
return FALSE;
if ( pinfo->ptype == PT_TCP )
{
if (!pinfo->fd->flags.visited)
{
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, giop_tcp_handle);
}
dissect_giop_tcp (tvb, pinfo, tree, data);
}
else
{
dissect_giop_common (tvb, pinfo, tree, data);
}
return TRUE;
}
void
proto_register_giop (void)
{
static hf_register_info hf[] = {
{ &hf_giop_message_magic,
{ "Magic", "giop.magic",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_giop_message_major_version,
{ "Major Version", "giop.major_version",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_giop_message_minor_version,
{ "Minor Version", "giop.minor_version",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_giop_message_flags,
{ "Message Flags", "giop.flags",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_giop_message_flags_ziop_enabled,
{ "ZIOP Enabled", "giop.flags.ziop_enabled",
FT_BOOLEAN, 8, NULL, GIOP_MESSAGE_FLAGS_ZIOP_ENABLED, NULL, HFILL }
},
{ &hf_giop_message_flags_ziop_supported,
{ "ZIOP Supported", "giop.flags.ziop_supported",
FT_BOOLEAN, 8, NULL, GIOP_MESSAGE_FLAGS_ZIOP_SUPPORTED, NULL, HFILL }
},
{ &hf_giop_message_flags_fragment,
{ "Fragment", "giop.flags.fragment",
FT_BOOLEAN, 8, NULL, GIOP_MESSAGE_FLAGS_FRAGMENT, NULL, HFILL }
},
{ &hf_giop_message_flags_little_endian,
{ "Little Endian", "giop.flags.little_endian",
FT_BOOLEAN, 8, NULL, GIOP_MESSAGE_FLAGS_ENDIANNESS, NULL, HFILL }
},
{ &hf_giop_message_type,
{ "Message type", "giop.type",
FT_UINT8, BASE_DEC, giop_message_types, 0x0, NULL, HFILL }
},
{ &hf_giop_message_size,
{ "Message size", "giop.len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_repoid,
{ "Repository ID", "giop.repoid",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_string_length,
{ "String Length", "giop.strlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_sequence_length,
{ "Sequence Length", "giop.seqlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_profile_id,
{ "Profile ID", "giop.profid",
FT_UINT32, BASE_DEC, VALS(profile_id_vals), 0x0, NULL, HFILL }
},
{ &hf_giop_type_id,
{ "IOR::type_id", "giop.typeid",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_id_len,
{ "Type Id length", "giop.typeid_len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_iiop_v_maj,
{ "IIOP Major Version", "giop.iiop_vmaj",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
}
,
{ &hf_giop_iiop_v_min,
{ "IIOP Minor Version", "giop.iiop_vmin",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#if 0
{ &hf_giop_compressed,
{ "ZIOP", "giop.compressed",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_giop_endianness,
{ "Endianness", "giop.endianness",
FT_UINT8, BASE_DEC, VALS(giop_endianness_vals), 0x0, NULL, HFILL }
},
{ &hf_giop_locale_status,
{ "Locate status", "giop.locale_status",
FT_UINT32, BASE_DEC, VALS(giop_locate_status_types), 0x0, NULL, HFILL }
},
{ &hf_giop_addressing_disposition,
{ "Addressing Disposition", "giop.addressing_disposition",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_profile_data,
{ "Profile Data", "giop.profile_data",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_component_data,
{ "Component Data", "giop.component_data",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_rt_corba_priority,
{ "RTCorbaPriority", "giop.rt_corba_priority",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_target_address_discriminant,
{ "TargetAddress", "giop.target_address.discriminant",
FT_UINT16, BASE_DEC, VALS(target_address_discriminant_vals), 0x0, NULL, HFILL }
},
{ &hf_giop_target_address_key_addr_len,
{ "Key Address Length", "giop.target_address.key_addr_len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_target_address_key_addr,
{ "Key Address", "giop.target_address.key_addr",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_target_address_ref_addr_len,
{ "Reference Address Length", "giop.target_address.ref_addr_len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_context_data,
{ "Context Data", "giop.context_data",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_char_data,
{ "char data", "giop.char_data",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &giop_code_set_vals_ext, 0x0, NULL, HFILL }
},
{ &hf_giop_wchar_data,
{ "wchar data", "giop.wchar_data",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &giop_code_set_vals_ext, 0x0, NULL, HFILL }
},
{ &hf_giop_IIOP_tag,
{ "IIOP Component TAG", "giop.iioptag",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#if 0
{ &hf_giop_IOR_tag,
{ "IOR Profile TAG", "giop.iortag",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_giop_TCKind,
{ "TypeCode enum", "giop.TCKind",
FT_UINT32, BASE_DEC, VALS(tckind_vals), 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_count,
{ "TypeCode count", "giop.tccount",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_default_used,
{ "default_used", "giop.tcdefault_used",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_digits,
{ "Digits", "giop.tcdigits",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_length,
{ "Length", "giop.tclength",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_max_length,
{ "Maximum length", "giop.tcmaxlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_member_name,
{ "TypeCode member name", "giop.tcmemname",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_name,
{ "TypeCode name", "giop.tcname",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_scale,
{ "Scale", "giop.tcscale",
FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_ValueModifier,
{ "ValueModifier", "giop.tcValueModifier",
FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_typecode_Visibility,
{ "Visibility", "giop.tcVisibility",
FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_boolean,
{ "TypeCode boolean data", "giop.tcboolean",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_char,
{ "TypeCode char data", "giop.tcchar",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_double,
{ "TypeCode double data", "giop.tcdouble",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_enum,
{ "TypeCode enum data", "giop.tcenumdata",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_float,
{ "TypeCode float data", "giop.tcfloat",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_long,
{ "TypeCode long data", "giop.tclongdata",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_octet,
{ "TypeCode octet data", "giop.tcoctet",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_short,
{ "TypeCode short data", "giop.tcshortdata",
FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_string,
{ "TypeCode string data", "giop.tcstring",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_ulong,
{ "TypeCode ulong data", "giop.tculongdata",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_type_ushort,
{ "TypeCode ushort data", "giop.tcushortdata",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_iiop_host,
{ "IIOP::Profile_host", "giop.iiop.host",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_iiop_port,
{ "IIOP::Profile_port", "giop.iiop.port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_iiop_sc,
{ "ServiceContext", "giop.iiop.sc",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_giop_iiop_sc_vscid,
{ "VSCID", "giop.iiop.sc.vscid",
FT_UINT32, BASE_HEX, NULL, 0xffffff00, NULL, HFILL }
},
{ &hf_giop_iiop_sc_omg_scid,
{ "SCID", "giop.iiop.sc.scid",
FT_UINT32, BASE_HEX, VALS(service_context_ids), 0x000000ff, NULL, HFILL }
},
{ &hf_giop_iiop_sc_vendor_scid,
{ "SCID", "giop.iiop.sc.scid",
FT_UINT32, BASE_HEX, NULL, 0x000000ff, NULL, HFILL }
},
{ &hf_giop_req_id,
{ "Request id", "giop.request_id",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_giop_req_operation_len,
{ "Operation length", "giop.request_op_len",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_giop_req_operation,
{ "Request operation", "giop.request_op",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_req_principal_len,
{ "Requesting Principal Length", "giop.request_principal_len",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_giop_req_principal,
{ "Requesting Principal", "giop.request_principal",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_reply_status,
{ "Reply status", "giop.replystatus",
FT_UINT32, BASE_DEC, VALS(reply_status_types), 0x0, NULL, HFILL }
},
{ &hf_giop_exception_len,
{ "Exception length", "giop.exceptionid_len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_exception_id,
{ "Exception id", "giop.exceptionid",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_objekt_key,
{ "Object Key", "giop.objektkey",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_objekt_key_len,
{ "Object Key length", "giop.objektkey_len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_rsp_expected,
{ "Response expected", "giop.rsp_expected",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_response_flag,
{ "Response flags", "giop.response_flag",
FT_UINT8, BASE_DEC, VALS(response_flags_vals), 0x0, NULL, HFILL }
},
{ &hf_giop_reserved,
{ "Reserved", "giop.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_stub_data,
{ "Stub data", "giop.stub_data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_address_disp,
{ "Addressing Disposition", "giop.address_disposition",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_minor_code_value,
{ "Minor code value", "giop.minor_code_value",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_completion_status,
{ "Completion Status", "giop.completion_status",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_giop_reply_body,
{ "Reply body", "giop.reply_body",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_giop,
&ett_giop_header,
&ett_giop_header_version,
&ett_giop_message_flags,
&ett_giop_reply,
&ett_giop_request,
&ett_giop_cancel_request,
&ett_giop_locate_request,
&ett_giop_locate_reply,
&ett_giop_fragment,
&ett_giop_scl,
&ett_giop_sc,
&ett_giop_ior
};
static ei_register_info ei[] = {
{ &ei_giop_unknown_typecode_datatype, { "giop.unknown_typecode_datatype", PI_PROTOCOL, PI_WARN, "Unknown typecode data type", EXPFILL }},
{ &ei_giop_unknown_sign_value, { "giop.unknown_sign_value", PI_PROTOCOL, PI_WARN, "Unknown sign value in fixed type", EXPFILL }},
{ &ei_giop_unknown_tckind, { "giop.unknown_tckind", PI_PROTOCOL, PI_WARN, "Unknown TCKind", EXPFILL }},
{ &ei_giop_length_too_big, { "giop.length_too_big", PI_MALFORMED, PI_ERROR, "length bigger than packet size", EXPFILL }},
{ &ei_giop_version_not_supported, { "giop.version_not_supported", PI_PROTOCOL, PI_WARN, "Version not supported", EXPFILL }},
{ &ei_giop_message_size_too_big, { "giop.message_size_too_big", PI_PROTOCOL, PI_WARN, "Message size is too big", EXPFILL }},
{ &ei_giop_invalid_v_minor, { "giop.invalid_v_minor", PI_PROTOCOL, PI_WARN, "Invalid v_minor value", EXPFILL }},
};
module_t *giop_module;
expert_module_t* expert_giop;
proto_giop = proto_register_protocol("General Inter-ORB Protocol", "GIOP", "giop");
giop_tcp_handle = new_register_dissector("giop", dissect_giop_tcp, proto_giop);
proto_register_field_array (proto_giop, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_giop = expert_register_protocol(proto_giop);
expert_register_field_array(expert_giop, ei, array_length(ei));
register_init_routine( &giop_init);
giop_module = prefs_register_protocol(proto_giop, NULL);
prefs_register_bool_preference(giop_module, "desegment_giop_messages",
"Reassemble GIOP messages spanning multiple TCP segments",
"Whether the GIOP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&giop_desegment);
prefs_register_filename_preference(giop_module, "ior_txt", "Stringified IORs",
"File containing stringified IORs, one per line.", &giop_ior_file);
giop_module_hash = g_hash_table_new(giop_hash_module_hash, giop_hash_module_equal);
}
void proto_reg_handoff_giop (void) {
data_handle = find_dissector("data");
heur_dissector_add("tcp", dissect_giop_heur, proto_giop);
heur_dissector_add("udp", dissect_giop_heur, proto_giop);
dissector_add_handle("tcp.port", giop_tcp_handle);
}
static void decode_IOR(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset,
guint32 boundary, gboolean stream_is_big_endian) {
guint32 seqlen_p;
guint32 u_octet4;
proto_tree *tree;
proto_item *tf;
const gchar *repobuf;
guint32 i;
tf = proto_tree_add_text (ptree, tvb, *offset, -1, "IOR");
tree = proto_item_add_subtree (tf, ett_giop_ior);
u_octet4 = get_CDR_string(tvb, &repobuf, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_string_length, tvb,
*offset-u_octet4-(int)sizeof(u_octet4), 4, u_octet4);
if (u_octet4 > 0) {
proto_tree_add_string(tree, hf_giop_type_id, tvb,
*offset-u_octet4, u_octet4, repobuf);
}
seqlen_p = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_sequence_length, tvb,
*offset-(int)sizeof(seqlen_p), 4, seqlen_p);
for (i=0; i< seqlen_p; i++) {
decode_TaggedProfile(tvb, pinfo, tree, offset, boundary, stream_is_big_endian, repobuf);
}
}
static void decode_TaggedProfile(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset,
guint32 boundary, gboolean stream_is_big_endian, const gchar *repobuf) {
guint32 seqlen_pd;
guint32 pidtag;
const gchar *profile_data;
guint32 new_boundary;
gboolean new_big_endianness;
proto_item *ti;
pidtag = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
ti = proto_tree_add_uint(tree, hf_giop_profile_id, tvb,
*offset-(int)sizeof(pidtag), 4, pidtag);
seqlen_pd = get_CDR_encap_info(tvb, tree, offset,
stream_is_big_endian, boundary,
&new_big_endianness, &new_boundary);
if (seqlen_pd == 0)
return;
switch (pidtag) {
case IOP_TAG_INTERNET_IOP:
decode_IIOP_IOR_profile(tvb, pinfo, tree, offset, new_boundary, new_big_endianness, repobuf, TRUE);
break;
default:
if (seqlen_pd-1 > (guint32)tvb_reported_length_remaining(tvb, *offset-4)) {
expert_add_info_format(pinfo, ti, &ei_giop_length_too_big, "Profile data bigger than packet size");
break;
}
get_CDR_octet_seq(tvb, &profile_data, offset, seqlen_pd -1);
proto_tree_add_string(tree, hf_giop_profile_data, tvb, *offset -seqlen_pd + 1, seqlen_pd - 1,
make_printable_string( profile_data, seqlen_pd -1));
break;
}
}
static void decode_IIOP_IOR_profile(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset,
guint32 boundary, gboolean stream_is_big_endian,
const gchar *repo_id_buf,
gboolean store_flag) {
guint32 i;
guint8 v_major, v_minor;
const gchar *buf;
guint32 u_octet4;
guint16 u_octet2;
guint32 seqlen;
guint32 seqlen1;
const gchar *objkey;
proto_item *ti, *ti_minor;
v_major = get_CDR_octet(tvb, offset);
v_minor = get_CDR_octet(tvb, offset);
proto_tree_add_uint(tree, hf_giop_iiop_v_maj, tvb,
*offset-2, 1, v_major );
ti_minor = proto_tree_add_uint(tree, hf_giop_iiop_v_min, tvb,
*offset-1, 1, v_minor );
u_octet4 = get_CDR_string(tvb, &buf, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_string_length, tvb,
*offset-u_octet4-4, 4, u_octet4);
if (u_octet4 > 0) {
proto_tree_add_string(tree, hf_giop_iiop_host, tvb,
*offset-u_octet4, u_octet4, buf);
}
u_octet2 = get_CDR_ushort(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_iiop_port, tvb,
*offset-2, 2, u_octet2);
seqlen = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
ti = proto_tree_add_uint(tree, hf_giop_sequence_length, tvb,
*offset-4, 4, seqlen);
if (seqlen > (guint32)tvb_reported_length_remaining(tvb, *offset-4)) {
expert_add_info_format(pinfo, ti, &ei_giop_length_too_big, "Sequence length bigger than packet size");
return;
}
if (seqlen > 0) {
get_CDR_octet_seq(tvb, &objkey, offset, seqlen);
if (repo_id_buf) {
if (pinfo) {
if (!pinfo->fd->flags.visited)
insert_in_objkey_hash(giop_objkey_hash, objkey, seqlen, repo_id_buf, ior_src_req_res);
}
else {
if (store_flag)
insert_in_objkey_hash(giop_objkey_hash, objkey, seqlen, repo_id_buf, ior_src_file);
}
}
proto_tree_add_item(tree, hf_giop_objekt_key, tvb, *offset -seqlen, seqlen, ENC_NA);
}
switch (v_minor) {
case 0:
break;
case 1:
case 2:
seqlen = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_sequence_length, tvb,
*offset-4, 4, seqlen);
for (i=0; i< seqlen; i++) {
u_octet4 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_IIOP_tag, tvb, *offset-4, 4, u_octet4);
seqlen1 = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
ti = proto_tree_add_uint(tree, hf_giop_sequence_length, tvb,
*offset-4, 4, seqlen1);
if (seqlen1 > (guint32)tvb_reported_length_remaining(tvb, *offset-4)) {
expert_add_info_format(pinfo, ti, &ei_giop_length_too_big, "Sequence length bigger than packet size");
return;
}
if (seqlen1 > 0) {
get_CDR_octet_seq(tvb, &buf, offset, seqlen1);
proto_tree_add_string(tree, hf_giop_component_data, tvb, *offset -seqlen1, seqlen1,
make_printable_string(buf, seqlen1));
}
}
break;
default:
expert_add_info_format(pinfo, ti_minor, &ei_giop_invalid_v_minor, "Invalid v_minor value = %u", v_minor);
break;
}
}
static void decode_SystemExceptionReplyBody (tvbuff_t *tvb, proto_tree *tree, gint *offset,
gboolean stream_is_big_endian,
guint32 boundary) {
guint32 length;
guint32 minor_code_value;
guint32 completion_status;
const gchar *buf;
length = get_CDR_string(tvb, &buf, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_exception_len, tvb, *offset-4, 4, length);
if (length > 0)
proto_tree_add_string(tree, hf_giop_exception_id, tvb,
*offset - length, length, buf);
minor_code_value = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
completion_status = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
proto_tree_add_uint(tree, hf_giop_minor_code_value, tvb, *offset-8, 4, minor_code_value);
proto_tree_add_uint(tree, hf_giop_completion_status, tvb, *offset-4, 4, completion_status);
}
