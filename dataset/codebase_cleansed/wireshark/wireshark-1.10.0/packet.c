void
packet_init(void)
{
frame_handle = find_dissector("frame");
data_handle = find_dissector("data");
proto_malformed = proto_get_id_by_filter_name("malformed");
}
void
packet_cleanup(void)
{
}
void
set_actual_length(tvbuff_t *tvb, const guint specified_len)
{
if (specified_len < tvb_reported_length(tvb)) {
tvb_set_reported_length(tvb, specified_len);
}
}
void
register_init_routine(void (*func)(void))
{
init_routines = g_slist_append(init_routines, (gpointer)func);
}
static void
call_init_routine(gpointer routine, gpointer dummy _U_)
{
void_func_t func = (void_func_t)routine;
(*func)();
}
void
init_dissection(void)
{
se_free_all();
wmem_enter_file_scope();
host_name_lookup_cleanup();
host_name_lookup_init();
epan_conversation_init();
epan_circuit_init();
g_slist_foreach(init_routines, &call_init_routine, NULL);
stream_init();
expert_init();
}
void
cleanup_dissection(void)
{
epan_conversation_cleanup();
se_free_all();
epan_circuit_cleanup();
g_slist_foreach(init_routines, &call_init_routine, NULL);
stream_cleanup();
expert_cleanup();
wmem_leave_file_scope();
host_name_lookup_cleanup();
host_name_lookup_init();
}
void
register_postseq_cleanup_routine(void_func_t func)
{
postseq_cleanup_routines = g_slist_append(postseq_cleanup_routines,
(gpointer)func);
}
static void
call_postseq_cleanup_routine(gpointer routine, gpointer dummy _U_)
{
void_func_t func = (void_func_t)routine;
(*func)();
}
void
postseq_cleanup_all_protocols(void)
{
g_slist_foreach(postseq_cleanup_routines,
&call_postseq_cleanup_routine, NULL);
}
void
add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name)
{
struct data_source *src;
src = (struct data_source *)g_malloc(sizeof(struct data_source));
src->tvb = tvb;
src->name = g_strdup(name);
pinfo->data_src = g_slist_append(pinfo->data_src, src);
}
const char*
get_data_source_name(const struct data_source *src)
{
guint length = tvb_length(src->tvb);
return ep_strdup_printf("%s (%u byte%s)", src->name, length,
plurality(length, "", "s"));
}
tvbuff_t *
get_data_source_tvb(const struct data_source *src)
{
return src->tvb;
}
void
free_data_sources(packet_info *pinfo)
{
if (pinfo->data_src) {
GSList *l;
for (l = pinfo->data_src; l; l = l->next) {
struct data_source *src = (struct data_source *)l->data;
g_free(src->name);
g_free(src);
}
g_slist_free(pinfo->data_src);
pinfo->data_src = NULL;
}
}
void
mark_frame_as_depended_upon(packet_info *pinfo, guint32 frame_num)
{
if (frame_num != PINFO_FD_NUM(pinfo)) {
pinfo->dependent_frames = g_slist_prepend(pinfo->dependent_frames, GUINT_TO_POINTER(frame_num));
}
}
void
register_final_registration_routine(void (*func)(void))
{
final_registration_routines = g_slist_append(final_registration_routines,
(gpointer)func);
}
static void
call_final_registration_routine(gpointer routine, gpointer dummy _U_)
{
void_func_t func = (void_func_t)routine;
(*func)();
}
void
final_registration_all_protocols(void)
{
g_slist_foreach(final_registration_routines,
&call_final_registration_routine, NULL);
}
void
dissect_packet(epan_dissect_t *edt, struct wtap_pkthdr *phdr,
const guchar *pd, frame_data *fd, column_info *cinfo)
{
wmem_allocator_t *tmp = edt->pi.pool;
if (cinfo != NULL)
col_init(cinfo);
memset(&edt->pi, 0, sizeof(edt->pi));
edt->pi.pool = tmp;
edt->pi.current_proto = "<Missing Protocol Name>";
edt->pi.cinfo = cinfo;
edt->pi.fd = fd;
edt->pi.phdr = phdr;
edt->pi.pseudo_header = &phdr->pseudo_header;
edt->pi.dl_src.type = AT_NONE;
edt->pi.dl_dst.type = AT_NONE;
edt->pi.net_src.type = AT_NONE;
edt->pi.net_dst.type = AT_NONE;
edt->pi.src.type = AT_NONE;
edt->pi.dst.type = AT_NONE;
edt->pi.ctype = CT_NONE;
edt->pi.noreassembly_reason = "";
edt->pi.ptype = PT_NONE;
edt->pi.p2p_dir = P2P_DIR_UNKNOWN;
edt->pi.dcetransporttype = -1;
edt->pi.annex_a_used = MTP2_ANNEX_A_USED_UNKNOWN;
edt->pi.dcerpc_procedure_name="";
edt->pi.link_dir = LINK_DIR_UNKNOWN;
edt->tvb = NULL;
edt->pi.ethertype = G_MAXINT;
EP_CHECK_CANARY(("before dissecting frame %d",fd->num));
TRY {
edt->tvb = tvb_new_real_data(pd, fd->cap_len,
fd->pkt_len > G_MAXINT ? G_MAXINT : fd->pkt_len);
add_new_data_source(&edt->pi, edt->tvb, "Frame");
if(frame_handle != NULL)
call_dissector(frame_handle, edt->tvb, &edt->pi, edt->tree);
}
CATCH(BoundsError) {
g_assert_not_reached();
}
CATCH2(FragmentBoundsError, ReportedBoundsError) {
if(proto_malformed != -1){
proto_tree_add_protocol_format(edt->tree, proto_malformed, edt->tvb, 0, 0,
"[Malformed Frame: Packet Length]" );
} else {
g_assert_not_reached();
}
}
ENDTRY;
EP_CHECK_CANARY(("after dissecting frame %d",fd->num));
fd->flags.visited = 1;
}
static int
call_dissector_through_handle(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void *data)
{
const char *saved_proto;
int ret;
saved_proto = pinfo->current_proto;
if (handle->protocol != NULL) {
pinfo->current_proto =
proto_get_protocol_short_name(handle->protocol);
}
if (handle->is_new) {
EP_CHECK_CANARY(("before calling handle->dissector.new_d for %s",handle->name));
ret = (*handle->dissector.new_d)(tvb, pinfo, tree, data);
EP_CHECK_CANARY(("after calling handle->dissector.new_d for %s",handle->name));
} else {
EP_CHECK_CANARY(("before calling handle->dissector.old for %s",handle->name));
(*handle->dissector.old)(tvb, pinfo, tree);
EP_CHECK_CANARY(("after calling handle->dissector.old for %s",handle->name));
ret = tvb_length(tvb);
if (ret == 0) {
ret = 1;
}
}
pinfo->current_proto = saved_proto;
return ret;
}
static int
call_dissector_work(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo_arg,
proto_tree *tree, gboolean add_proto_name, void *data)
{
packet_info *pinfo = pinfo_arg;
const char *saved_proto;
guint16 saved_can_desegment;
int ret;
gint saved_layer_names_len = 0;
if (handle->protocol != NULL &&
!proto_is_protocol_enabled(handle->protocol)) {
return 0;
}
saved_proto = pinfo->current_proto;
saved_can_desegment = pinfo->can_desegment;
if (pinfo->layer_names != NULL)
saved_layer_names_len = (gint) pinfo->layer_names->len;
pinfo->saved_can_desegment = saved_can_desegment;
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
if (handle->protocol != NULL) {
pinfo->current_proto =
proto_get_protocol_short_name(handle->protocol);
if ((pinfo->layer_names)&&(add_proto_name)) {
if (pinfo->layer_names->len > 0)
g_string_append(pinfo->layer_names, ":");
g_string_append(pinfo->layer_names,
proto_get_protocol_filter_name(proto_get_id(handle->protocol)));
}
}
if (pinfo->flags.in_error_pkt) {
ret = call_dissector_work_error(handle, tvb, pinfo, tree, data);
} else {
ret = call_dissector_through_handle(handle, tvb, pinfo, tree, data);
}
if (ret == 0) {
if ((pinfo->layer_names != NULL)&&(add_proto_name)) {
g_string_truncate(pinfo->layer_names, saved_layer_names_len);
}
}
pinfo->current_proto = saved_proto;
pinfo->can_desegment = saved_can_desegment;
return ret;
}
static int
call_dissector_work_error(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo_arg, proto_tree *tree, void *data)
{
packet_info *pinfo = pinfo_arg;
const char *saved_proto;
guint16 saved_can_desegment;
volatile int ret = 0;
gboolean save_writable;
address save_dl_src;
address save_dl_dst;
address save_net_src;
address save_net_dst;
address save_src;
address save_dst;
saved_proto = pinfo->current_proto;
saved_can_desegment = pinfo->can_desegment;
save_writable = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, FALSE);
save_dl_src = pinfo->dl_src;
save_dl_dst = pinfo->dl_dst;
save_net_src = pinfo->net_src;
save_net_dst = pinfo->net_dst;
save_src = pinfo->src;
save_dst = pinfo->dst;
TRY {
ret = call_dissector_through_handle(handle, tvb,pinfo, tree, data);
}
CATCH(BoundsError) {
col_set_writable(pinfo->cinfo, save_writable);
pinfo->dl_src = save_dl_src;
pinfo->dl_dst = save_dl_dst;
pinfo->net_src = save_net_src;
pinfo->net_dst = save_net_dst;
pinfo->src = save_src;
pinfo->dst = save_dst;
pinfo->current_proto = saved_proto;
pinfo->can_desegment = saved_can_desegment;
RETHROW;
}
CATCH2(FragmentBoundsError, ReportedBoundsError) {
ret = tvb_length(tvb);
}
ENDTRY;
col_set_writable(pinfo->cinfo, save_writable);
pinfo->dl_src = save_dl_src;
pinfo->dl_dst = save_dl_dst;
pinfo->net_src = save_net_src;
pinfo->net_dst = save_net_dst;
pinfo->src = save_src;
pinfo->dst = save_dst;
pinfo->want_pdu_tracking = 0;
return ret;
}
dissector_table_t
find_dissector_table(const char *name)
{
g_assert(dissector_tables);
return (dissector_table_t)g_hash_table_lookup( dissector_tables, name );
}
static dtbl_entry_t *
find_uint_dtbl_entry(dissector_table_t sub_dissectors, const guint32 pattern)
{
switch (sub_dissectors->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
break;
default:
g_assert_not_reached();
}
return (dtbl_entry_t *)g_hash_table_lookup(sub_dissectors->hash_table,
GUINT_TO_POINTER(pattern));
}
void
dissector_add_uint(const char *name, const guint32 pattern, dissector_handle_t handle)
{
dissector_table_t sub_dissectors;
dtbl_entry_t *dtbl_entry;
sub_dissectors = find_dissector_table(name);
if (sub_dissectors == NULL) {
fprintf(stderr, "OOPS: dissector table \"%s\" doesn't exist\n",
name);
fprintf(stderr, "Protocol being registered is \"%s\"\n",
proto_get_protocol_long_name(handle->protocol));
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
return;
}
g_assert(handle!=NULL);
switch (sub_dissectors->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
break;
default:
g_assert_not_reached();
}
#if 0
dissector_add_uint_sanity_check(name, pattern, handle, sub_dissectors);
#endif
dtbl_entry = (dtbl_entry_t *)g_malloc(sizeof (dtbl_entry_t));
dtbl_entry->current = handle;
dtbl_entry->initial = dtbl_entry->current;
g_hash_table_insert( sub_dissectors->hash_table,
GUINT_TO_POINTER( pattern), (gpointer)dtbl_entry);
dissector_add_handle(name, handle);
}
void
dissector_delete_uint(const char *name, const guint32 pattern,
dissector_handle_t handle _U_)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
g_assert( sub_dissectors);
dtbl_entry = find_uint_dtbl_entry(sub_dissectors, pattern);
if (dtbl_entry != NULL) {
g_hash_table_remove(sub_dissectors->hash_table,
GUINT_TO_POINTER(pattern));
}
}
void
dissector_change_uint(const char *name, const guint32 pattern, dissector_handle_t handle)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
g_assert( sub_dissectors);
dtbl_entry = find_uint_dtbl_entry(sub_dissectors, pattern);
if (dtbl_entry != NULL) {
dtbl_entry->current = handle;
return;
}
if (handle == NULL)
return;
dtbl_entry = (dtbl_entry_t *)g_malloc(sizeof (dtbl_entry_t));
dtbl_entry->initial = NULL;
dtbl_entry->current = handle;
g_hash_table_insert( sub_dissectors->hash_table,
GUINT_TO_POINTER( pattern), (gpointer)dtbl_entry);
}
void
dissector_reset_uint(const char *name, const guint32 pattern)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
g_assert( sub_dissectors);
dtbl_entry = find_uint_dtbl_entry(sub_dissectors, pattern);
if (dtbl_entry == NULL)
return;
if (dtbl_entry->initial != NULL) {
dtbl_entry->current = dtbl_entry->initial;
} else {
g_hash_table_remove(sub_dissectors->hash_table,
GUINT_TO_POINTER(pattern));
}
}
gboolean
dissector_try_uint_new(dissector_table_t sub_dissectors, const guint32 uint_val,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const gboolean add_proto_name, void *data)
{
dtbl_entry_t *dtbl_entry;
struct dissector_handle *handle;
guint32 saved_match_uint;
int ret;
dtbl_entry = find_uint_dtbl_entry(sub_dissectors, uint_val);
if (dtbl_entry != NULL) {
handle = dtbl_entry->current;
if (handle == NULL) {
return FALSE;
}
saved_match_uint = pinfo->match_uint;
pinfo->match_uint = uint_val;
ret = call_dissector_work(handle, tvb, pinfo, tree, add_proto_name, data);
pinfo->match_uint = saved_match_uint;
return ret != 0;
}
return FALSE;
}
gboolean
dissector_try_uint(dissector_table_t sub_dissectors, const guint32 uint_val,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return dissector_try_uint_new(sub_dissectors, uint_val, tvb, pinfo, tree, TRUE, NULL);
}
dissector_handle_t
dissector_get_uint_handle(dissector_table_t const sub_dissectors, const guint32 uint_val)
{
dtbl_entry_t *dtbl_entry;
dtbl_entry = find_uint_dtbl_entry(sub_dissectors, uint_val);
if (dtbl_entry != NULL)
return dtbl_entry->current;
else
return NULL;
}
static dtbl_entry_t *
find_string_dtbl_entry(dissector_table_t const sub_dissectors, const gchar *pattern)
{
switch (sub_dissectors->type) {
case FT_STRING:
case FT_STRINGZ:
break;
default:
g_assert_not_reached();
}
return (dtbl_entry_t *)g_hash_table_lookup(sub_dissectors->hash_table, pattern);
}
void
dissector_add_string(const char *name, const gchar *pattern,
dissector_handle_t handle)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
if (sub_dissectors == NULL) {
fprintf(stderr, "OOPS: dissector table \"%s\" doesn't exist\n",
name);
fprintf(stderr, "Protocol being registered is \"%s\"\n",
proto_get_protocol_long_name(handle->protocol));
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
return;
}
g_assert(handle!=NULL);
switch (sub_dissectors->type) {
case FT_STRING:
case FT_STRINGZ:
break;
default:
g_assert_not_reached();
}
dtbl_entry = (dtbl_entry_t *)g_malloc(sizeof (dtbl_entry_t));
dtbl_entry->current = handle;
dtbl_entry->initial = dtbl_entry->current;
g_hash_table_insert( sub_dissectors->hash_table, (gpointer)pattern,
(gpointer)dtbl_entry);
dissector_add_handle(name, handle);
}
void
dissector_delete_string(const char *name, const gchar *pattern,
dissector_handle_t handle _U_)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
g_assert( sub_dissectors);
dtbl_entry = find_string_dtbl_entry(sub_dissectors, pattern);
if (dtbl_entry != NULL) {
g_hash_table_remove(sub_dissectors->hash_table, pattern);
}
}
void
dissector_change_string(const char *name, const gchar *pattern,
dissector_handle_t handle)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
g_assert( sub_dissectors);
dtbl_entry = find_string_dtbl_entry(sub_dissectors, pattern);
if (dtbl_entry != NULL) {
dtbl_entry->current = handle;
return;
}
if (handle == NULL)
return;
dtbl_entry = (dtbl_entry_t *)g_malloc(sizeof (dtbl_entry_t));
dtbl_entry->initial = NULL;
dtbl_entry->current = handle;
g_hash_table_insert( sub_dissectors->hash_table, (gpointer)pattern,
(gpointer)dtbl_entry);
}
void
dissector_reset_string(const char *name, const gchar *pattern)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
g_assert( sub_dissectors);
dtbl_entry = find_string_dtbl_entry(sub_dissectors, pattern);
if (dtbl_entry == NULL)
return;
if (dtbl_entry->initial != NULL) {
dtbl_entry->current = dtbl_entry->initial;
} else {
g_hash_table_remove(sub_dissectors->hash_table, pattern);
}
}
gboolean
dissector_try_string(dissector_table_t sub_dissectors, const gchar *string,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dtbl_entry_t *dtbl_entry;
struct dissector_handle *handle;
int ret;
const gchar *saved_match_string;
if (!string) return FALSE;
dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
if (dtbl_entry != NULL) {
handle = dtbl_entry->current;
if (handle == NULL) {
return FALSE;
}
saved_match_string = pinfo->match_string;
pinfo->match_string = string;
ret = call_dissector_work(handle, tvb, pinfo, tree, TRUE, NULL);
pinfo->match_string = saved_match_string;
return ret != 0;
}
return FALSE;
}
dissector_handle_t
dissector_get_string_handle(dissector_table_t sub_dissectors,
const gchar *string)
{
dtbl_entry_t *dtbl_entry;
dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
if (dtbl_entry != NULL)
return dtbl_entry->current;
else
return NULL;
}
dissector_handle_t
dtbl_entry_get_handle (dtbl_entry_t *dtbl_entry)
{
return dtbl_entry->current;
}
static gint
dissector_compare_filter_name(gconstpointer dissector_a, gconstpointer dissector_b)
{
const dissector_handle_t a = (const dissector_handle_t)dissector_a;
const dissector_handle_t b = (const dissector_handle_t)dissector_b;
const char *a_name, *b_name;
gint ret;
if (a->protocol == NULL)
a_name = "";
else
a_name = proto_get_protocol_filter_name(proto_get_id(a->protocol));
if (b->protocol == NULL)
b_name = "";
else
b_name = proto_get_protocol_filter_name(proto_get_id(b->protocol));
ret = strcmp(a_name, b_name);
return ret;
}
void
dissector_add_handle(const char *name, dissector_handle_t handle)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
GSList *entry;
if (sub_dissectors == NULL) {
fprintf(stderr, "OOPS: dissector table \"%s\" doesn't exist\n",
name);
fprintf(stderr, "Protocol being registered is \"%s\"\n",
proto_get_protocol_long_name(handle->protocol));
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
return;
}
entry = g_slist_find(sub_dissectors->dissector_handles, (gpointer)handle);
if (entry != NULL) {
return;
}
sub_dissectors->dissector_handles =
g_slist_insert_sorted(sub_dissectors->dissector_handles, (gpointer)handle, (GCompareFunc)dissector_compare_filter_name);
}
dissector_handle_t
dtbl_entry_get_initial_handle (dtbl_entry_t *dtbl_entry)
{
return dtbl_entry->initial;
}
static void
dissector_table_foreach_func (gpointer key, gpointer value, gpointer user_data)
{
dissector_foreach_info_t *info;
dtbl_entry_t *dtbl_entry;
g_assert(value);
g_assert(user_data);
dtbl_entry = (dtbl_entry_t *)value;
if (dtbl_entry->current == NULL ||
dtbl_entry->current->protocol == NULL) {
return;
}
info = (dissector_foreach_info_t *)user_data;
info->caller_func(info->table_name, info->selector_type, key, value,
info->caller_data);
}
static void
dissector_all_tables_foreach_func (gpointer key, gpointer value, gpointer user_data)
{
dissector_table_t sub_dissectors;
dissector_foreach_info_t *info;
g_assert(value);
g_assert(user_data);
sub_dissectors = (dissector_table_t)value;
info = (dissector_foreach_info_t *)user_data;
info->table_name = (gchar*) key;
info->selector_type = get_dissector_table_selector_type(info->table_name);
g_hash_table_foreach(sub_dissectors->hash_table, info->next_func, info);
}
static void
dissector_all_tables_foreach (DATFunc func,
gpointer user_data)
{
dissector_foreach_info_t info;
info.caller_data = user_data;
info.caller_func = func;
info.next_func = dissector_table_foreach_func;
g_hash_table_foreach(dissector_tables, dissector_all_tables_foreach_func, &info);
}
void
dissector_table_foreach (const char *name,
DATFunc func,
gpointer user_data)
{
dissector_foreach_info_t info;
dissector_table_t sub_dissectors = find_dissector_table( name);
info.table_name = name;
info.selector_type = sub_dissectors->type;
info.caller_func = func;
info.caller_data = user_data;
g_hash_table_foreach(sub_dissectors->hash_table, dissector_table_foreach_func, &info);
}
void
dissector_table_foreach_handle(const char *name,
DATFunc_handle func,
gpointer user_data)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
GSList *tmp;
for (tmp = sub_dissectors->dissector_handles; tmp != NULL;
tmp = g_slist_next(tmp))
func(name, tmp->data, user_data);
}
static void
dissector_table_foreach_changed_func (gpointer key, gpointer value, gpointer user_data)
{
dtbl_entry_t *dtbl_entry;
dissector_foreach_info_t *info;
g_assert(value);
g_assert(user_data);
dtbl_entry = (dtbl_entry_t *)value;
if (dtbl_entry->initial == dtbl_entry->current) {
return;
}
info = (dissector_foreach_info_t *)user_data;
info->caller_func(info->table_name, info->selector_type, key, value,
info->caller_data);
}
void
dissector_all_tables_foreach_changed (DATFunc func,
gpointer user_data)
{
dissector_foreach_info_t info;
info.caller_data = user_data;
info.caller_func = func;
info.next_func = dissector_table_foreach_changed_func;
g_hash_table_foreach(dissector_tables, dissector_all_tables_foreach_func, &info);
}
void
dissector_table_foreach_changed (const char *name,
DATFunc func,
gpointer user_data)
{
dissector_foreach_info_t info;
dissector_table_t sub_dissectors = find_dissector_table( name);
info.table_name = name;
info.selector_type = sub_dissectors->type;
info.caller_func = func;
info.caller_data = user_data;
g_hash_table_foreach(sub_dissectors->hash_table,
dissector_table_foreach_changed_func, &info);
}
static void
dissector_all_tables_foreach_table_func (gpointer key, const gpointer value, const gpointer user_data)
{
dissector_table_t table;
dissector_foreach_table_info_t *info;
table = (dissector_table_t)value;
info = (dissector_foreach_table_info_t *)user_data;
(*info->caller_func)((gchar*)key, table->ui_name, info->caller_data);
}
static void
dissector_all_tables_foreach_list_func (gpointer key, gpointer user_data)
{
dissector_table_t table;
dissector_foreach_table_info_t *info;
table = (dissector_table_t)g_hash_table_lookup( dissector_tables, key );
info = (dissector_foreach_table_info_t *)user_data;
(*info->caller_func)((gchar*)key, table->ui_name, info->caller_data);
}
void
dissector_all_tables_foreach_table (DATFunc_table func,
gpointer user_data,
GCompareFunc compare_key_func)
{
dissector_foreach_table_info_t info;
GList* list;
info.caller_data = user_data;
info.caller_func = func;
if (compare_key_func != NULL)
{
list = g_hash_table_get_keys(dissector_tables);
list = g_list_sort(list, compare_key_func);
g_list_foreach(list, dissector_all_tables_foreach_list_func, &info);
g_list_free(list);
}
else
{
g_hash_table_foreach(dissector_tables, dissector_all_tables_foreach_table_func, &info);
}
}
dissector_table_t
register_dissector_table(const char *name, const char *ui_name, const ftenum_t type,
const int base)
{
dissector_table_t sub_dissectors;
if (!dissector_tables) {
dissector_tables = g_hash_table_new( g_str_hash, g_str_equal );
g_assert(dissector_tables);
}
if(g_hash_table_lookup( dissector_tables, name )) {
g_error("The filter name %s (%s) is already registered - do you use a buggy plugin?", name, ui_name);
}
sub_dissectors = (struct dissector_table *)g_malloc(sizeof (struct dissector_table));
switch (type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
sub_dissectors->hash_table = g_hash_table_new_full( g_direct_hash,
g_direct_equal,
NULL,
&g_free );
break;
case FT_STRING:
case FT_STRINGZ:
sub_dissectors->hash_table = g_hash_table_new_full( g_str_hash,
g_str_equal,
NULL,
&g_free );
break;
default:
g_assert_not_reached();
}
sub_dissectors->dissector_handles = NULL;
sub_dissectors->ui_name = ui_name;
sub_dissectors->type = type;
sub_dissectors->base = base;
g_hash_table_insert( dissector_tables, (gpointer)name, (gpointer) sub_dissectors );
return sub_dissectors;
}
const char *
get_dissector_table_ui_name(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
return sub_dissectors->ui_name;
}
ftenum_t
get_dissector_table_selector_type(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
return sub_dissectors->type;
}
int
get_dissector_table_base(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
return sub_dissectors->base;
}
static heur_dissector_list_t *
find_heur_dissector_list(const char *name)
{
g_assert(heur_dissector_lists != NULL);
return (heur_dissector_list_t *)g_hash_table_lookup(heur_dissector_lists, name);
}
void
heur_dissector_add(const char *name, heur_dissector_t dissector, const int proto)
{
heur_dissector_list_t *sub_dissectors = find_heur_dissector_list(name);
const char *proto_name;
heur_dtbl_entry_t *hdtbl_entry;
if (sub_dissectors == NULL) {
fprintf(stderr, "OOPS: dissector table \"%s\" doesn't exist\n",
name);
proto_name = proto_get_protocol_name(proto);
if (proto_name != NULL) {
fprintf(stderr, "Protocol being registered is \"%s\"\n",
proto_name);
}
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
return;
}
hdtbl_entry = (heur_dtbl_entry_t *)g_malloc(sizeof (heur_dtbl_entry_t));
hdtbl_entry->dissector = dissector;
hdtbl_entry->protocol = find_protocol_by_id(proto);
hdtbl_entry->enabled = TRUE;
*sub_dissectors = g_slist_append(*sub_dissectors, (gpointer)hdtbl_entry);
}
static int
find_matching_heur_dissector( gconstpointer a, gconstpointer b) {
const heur_dtbl_entry_t *hdtbl_entry_a = (const heur_dtbl_entry_t *) a;
const heur_dtbl_entry_t *hdtbl_entry_b = (const heur_dtbl_entry_t *) b;
return (hdtbl_entry_a->dissector == hdtbl_entry_b->dissector) &&
(hdtbl_entry_a->protocol == hdtbl_entry_b->protocol) ? 0 : 1;
}
void
heur_dissector_delete(const char *name, heur_dissector_t dissector, const int proto) {
heur_dissector_list_t *sub_dissectors = find_heur_dissector_list(name);
heur_dtbl_entry_t hdtbl_entry;
GSList *found_entry;
g_assert(sub_dissectors != NULL);
hdtbl_entry.dissector = dissector;
hdtbl_entry.protocol = find_protocol_by_id(proto);
found_entry = g_slist_find_custom(*sub_dissectors, (gpointer) &hdtbl_entry, find_matching_heur_dissector);
if (found_entry) {
*sub_dissectors = g_slist_remove_link(*sub_dissectors, found_entry);
g_free(g_slist_nth_data(found_entry, 1));
g_slist_free_1(found_entry);
}
}
void
heur_dissector_set_enabled(const char *name, heur_dissector_t dissector, const int proto, const gboolean enabled) {
heur_dissector_list_t *sub_dissectors = find_heur_dissector_list(name);
GSList *found_entry;
heur_dtbl_entry_t hdtbl_entry;
g_assert(sub_dissectors != NULL);
hdtbl_entry.dissector = dissector;
hdtbl_entry.protocol = find_protocol_by_id(proto);
found_entry = g_slist_find_custom(*sub_dissectors, (gpointer) &hdtbl_entry, find_matching_heur_dissector);
if (found_entry) {
heur_dtbl_entry_t *hdtbl_entry_p;
hdtbl_entry_p = (heur_dtbl_entry_t *)found_entry->data;
hdtbl_entry_p->enabled = enabled;
}
}
gboolean
dissector_try_heuristic(heur_dissector_list_t sub_dissectors, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void *data)
{
gboolean status;
const char *saved_proto;
GSList *entry;
heur_dtbl_entry_t *hdtbl_entry;
guint16 saved_can_desegment;
gint saved_layer_names_len = 0;
saved_can_desegment = pinfo->can_desegment;
pinfo->saved_can_desegment = saved_can_desegment;
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
status = FALSE;
saved_proto = pinfo->current_proto;
if (pinfo->layer_names != NULL)
saved_layer_names_len = (gint) pinfo->layer_names->len;
for (entry = sub_dissectors; entry != NULL; entry = g_slist_next(entry)) {
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
hdtbl_entry = (heur_dtbl_entry_t *)entry->data;
if (hdtbl_entry->protocol != NULL &&
(!proto_is_protocol_enabled(hdtbl_entry->protocol)||(hdtbl_entry->enabled==FALSE))) {
continue;
}
if (hdtbl_entry->protocol != NULL) {
pinfo->current_proto =
proto_get_protocol_short_name(hdtbl_entry->protocol);
if (pinfo->layer_names) {
if (pinfo->layer_names->len > 0)
g_string_append(pinfo->layer_names, ":");
g_string_append(pinfo->layer_names,
proto_get_protocol_filter_name(proto_get_id(hdtbl_entry->protocol)));
}
}
EP_CHECK_CANARY(("before calling heuristic dissector for protocol: %s",
proto_get_protocol_filter_name(proto_get_id(hdtbl_entry->protocol))));
if ((*hdtbl_entry->dissector)(tvb, pinfo, tree, data)) {
EP_CHECK_CANARY(("after heuristic dissector for protocol: %s has accepted and dissected packet",
proto_get_protocol_filter_name(proto_get_id(hdtbl_entry->protocol))));
status = TRUE;
break;
} else {
EP_CHECK_CANARY(("after heuristic dissector for protocol: %s has returned false",
proto_get_protocol_filter_name(proto_get_id(hdtbl_entry->protocol))));
if (pinfo->layer_names != NULL) {
g_string_truncate(pinfo->layer_names, saved_layer_names_len);
}
}
}
pinfo->current_proto = saved_proto;
pinfo->can_desegment=saved_can_desegment;
return status;
}
static void
dissector_dump_heur_decodes_display(const gchar *table_name, const gpointer value, const gpointer user_data _U_)
{
heur_dissector_list_t sub_dissectors = *(heur_dissector_list_t *)value;
GSList *entry;
heur_dtbl_entry_t *hdtbl_entry;
for (entry = sub_dissectors; entry != NULL; entry = g_slist_next(entry)) {
hdtbl_entry = (heur_dtbl_entry_t *)entry->data;
if (hdtbl_entry->protocol != NULL) {
printf("%s\t%s\t%c\n",
table_name,
proto_get_protocol_filter_name(proto_get_id(hdtbl_entry->protocol)),
(proto_is_protocol_enabled(hdtbl_entry->protocol) && hdtbl_entry->enabled) ? 'T' : 'F');
}
}
}
static void
dissector_all_heur_tables_foreach_table_func (gpointer key, const gpointer value, const gpointer user_data)
{
heur_dissector_foreach_table_info_t *info;
info = (heur_dissector_foreach_table_info_t *)user_data;
(*info->caller_func)((gchar*)key, value, info->caller_data);
}
void
dissector_all_heur_tables_foreach_table (DATFunc_heur_table func,
gpointer user_data)
{
heur_dissector_foreach_table_info_t info;
info.caller_data = user_data;
info.caller_func = func;
g_hash_table_foreach(heur_dissector_lists, dissector_all_heur_tables_foreach_table_func, &info);
}
void
dissector_dump_heur_decodes(void)
{
dissector_all_heur_tables_foreach_table(dissector_dump_heur_decodes_display, NULL);
}
void
register_heur_dissector_list(const char *name, heur_dissector_list_t *sub_dissectors)
{
if (heur_dissector_lists == NULL) {
heur_dissector_lists = g_hash_table_new(g_str_hash, g_str_equal);
g_assert(heur_dissector_lists != NULL);
}
g_assert(g_hash_table_lookup(heur_dissector_lists, name) == NULL);
*sub_dissectors = NULL;
g_hash_table_insert(heur_dissector_lists, (gpointer)name,
(gpointer) sub_dissectors);
}
const char *
dissector_handle_get_long_name(const dissector_handle_t handle)
{
if (handle == NULL || handle->protocol == NULL) {
return NULL;
}
return proto_get_protocol_long_name(handle->protocol);
}
const char *
dissector_handle_get_short_name(const dissector_handle_t handle)
{
if (handle->protocol == NULL) {
return NULL;
}
return proto_get_protocol_short_name(handle->protocol);
}
int
dissector_handle_get_protocol_index(const dissector_handle_t handle)
{
if (handle->protocol == NULL) {
return -1;
}
return proto_get_id(handle->protocol);
}
dissector_handle_t
find_dissector(const char *name)
{
g_assert(registered_dissectors != NULL);
return (dissector_handle_t)g_hash_table_lookup(registered_dissectors, name);
}
dissector_handle_t
create_dissector_handle(dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
handle = (struct dissector_handle *)g_malloc(sizeof (struct dissector_handle));
handle->name = NULL;
handle->is_new = FALSE;
handle->dissector.old = dissector;
handle->protocol = find_protocol_by_id(proto);
return handle;
}
dissector_handle_t
new_create_dissector_handle(new_dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
handle = (struct dissector_handle *)g_malloc(sizeof (struct dissector_handle));
handle->name = NULL;
handle->is_new = TRUE;
handle->dissector.new_d = dissector;
handle->protocol = find_protocol_by_id(proto);
return handle;
}
void
register_dissector(const char *name, dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
if (registered_dissectors == NULL) {
registered_dissectors = g_hash_table_new(g_str_hash, g_str_equal);
g_assert(registered_dissectors != NULL);
}
g_assert(g_hash_table_lookup(registered_dissectors, name) == NULL);
handle = (struct dissector_handle *)g_malloc(sizeof (struct dissector_handle));
handle->name = name;
handle->is_new = FALSE;
handle->dissector.old = dissector;
handle->protocol = find_protocol_by_id(proto);
g_hash_table_insert(registered_dissectors, (gpointer)name,
(gpointer) handle);
}
void
new_register_dissector(const char *name, new_dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
if (registered_dissectors == NULL) {
registered_dissectors = g_hash_table_new(g_str_hash, g_str_equal);
g_assert(registered_dissectors != NULL);
}
g_assert(g_hash_table_lookup(registered_dissectors, name) == NULL);
handle = (struct dissector_handle *)g_malloc(sizeof (struct dissector_handle));
handle->name = name;
handle->is_new = TRUE;
handle->dissector.new_d = dissector;
handle->protocol = find_protocol_by_id(proto);
g_hash_table_insert(registered_dissectors, (gpointer)name,
(gpointer) handle);
}
int
call_dissector_only(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void *data)
{
int ret;
g_assert(handle != NULL);
ret = call_dissector_work(handle, tvb, pinfo, tree, TRUE, data);
return ret;
}
int
call_dissector_with_data(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void *data)
{
int ret;
ret = call_dissector_only(handle, tvb, pinfo, tree, data);
if (ret == 0) {
g_assert(data_handle != NULL);
g_assert(data_handle->protocol != NULL);
call_dissector_work(data_handle, tvb, pinfo, tree, TRUE, NULL);
return tvb_length(tvb);
}
return ret;
}
int
call_dissector(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree)
{
return call_dissector_with_data(handle, tvb, pinfo, tree, NULL);
}
static void
dissector_dump_decodes_display(const gchar *table_name,
ftenum_t selector_type _U_, const gpointer key, const gpointer value,
gpointer user_data _U_)
{
guint32 selector = (guint32)(unsigned long) key;
dissector_table_t sub_dissectors = find_dissector_table(table_name);
dtbl_entry_t *dtbl_entry;
dissector_handle_t handle;
gint proto_id;
const gchar *decode_as;
g_assert(sub_dissectors);
switch (sub_dissectors->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
dtbl_entry = (dtbl_entry_t *)value;
g_assert(dtbl_entry);
handle = dtbl_entry->current;
g_assert(handle);
proto_id = dissector_handle_get_protocol_index(handle);
if (proto_id != -1) {
decode_as = proto_get_protocol_filter_name(proto_id);
g_assert(decode_as != NULL);
printf("%s\t%u\t%s\n", table_name, selector, decode_as);
}
break;
default:
break;
}
}
void
dissector_dump_decodes(void)
{
dissector_all_tables_foreach(dissector_dump_decodes_display, NULL);
}
void
register_postdissector(dissector_handle_t handle)
{
if (!post_dissectors)
post_dissectors = g_ptr_array_new();
g_ptr_array_add(post_dissectors, handle);
num_of_postdissectors++;
}
gboolean
have_postdissector(void)
{
guint i;
dissector_handle_t handle;
for(i = 0; i < num_of_postdissectors; i++) {
handle = (dissector_handle_t) g_ptr_array_index(post_dissectors,i);
if (handle->protocol != NULL
&& proto_is_protocol_enabled(handle->protocol)) {
return TRUE;
}
}
return FALSE;
}
void
call_all_postdissectors(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint i;
for(i = 0; i < num_of_postdissectors; i++) {
call_dissector_only((dissector_handle_t) g_ptr_array_index(post_dissectors,i),
tvb,pinfo,tree, NULL);
}
}
