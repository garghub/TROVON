static void
destroy_heuristic_dissector_entry(gpointer data, gpointer user_data _U_)
{
g_free(((heur_dtbl_entry_t*)data)->list_name);
g_slice_free(heur_dtbl_entry_t, data);
}
static void
destroy_heuristic_dissector_list(void *data)
{
heur_dissector_list_t dissector_list = (heur_dissector_list_t)data;
GSList **list = &(dissector_list->dissectors);
g_slist_foreach(*list, destroy_heuristic_dissector_entry, NULL);
g_slist_free(*list);
g_slice_free(struct heur_dissector_list, dissector_list);
}
static void
destroy_dissector_table(void *data)
{
struct dissector_table *table = (struct dissector_table *)data;
g_hash_table_destroy(table->hash_table);
g_slist_free(table->dissector_handles);
g_slice_free(struct dissector_table, data);
}
void
packet_init(void)
{
dissector_tables = g_hash_table_new_full(g_str_hash, g_str_equal,
NULL, destroy_dissector_table);
registered_dissectors = g_hash_table_new_full(g_str_hash, g_str_equal,
NULL, NULL);
heur_dissector_lists = g_hash_table_new_full(g_str_hash, g_str_equal,
NULL, destroy_heuristic_dissector_list);
heuristic_short_names = g_hash_table_new(wrs_str_hash, g_str_equal);
}
void
packet_cache_proto_handles(void)
{
frame_handle = find_dissector("frame");
g_assert(frame_handle != NULL);
file_handle = find_dissector("file");
g_assert(file_handle != NULL);
data_handle = find_dissector("data");
g_assert(data_handle != NULL);
proto_malformed = proto_get_id_by_filter_name("_ws.malformed");
g_assert(proto_malformed != -1);
}
void
packet_cleanup(void)
{
g_hash_table_destroy(dissector_tables);
g_hash_table_destroy(registered_dissectors);
g_hash_table_destroy(heur_dissector_lists);
g_hash_table_destroy(heuristic_short_names);
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
init_routines = g_slist_prepend(init_routines, (gpointer)func);
}
void
register_cleanup_routine(void (*func)(void))
{
cleanup_routines = g_slist_prepend(cleanup_routines, (gpointer)func);
}
static void
call_routine(gpointer routine, gpointer dummy _U_)
{
void_func_t func = (void_func_t)routine;
(*func)();
}
void
init_dissection(void)
{
wmem_enter_file_scope();
host_name_lookup_init();
epan_conversation_init();
epan_circuit_init();
g_slist_foreach(init_routines, &call_routine, NULL);
stream_init();
expert_packet_init();
}
void
cleanup_dissection(void)
{
epan_conversation_cleanup();
epan_circuit_cleanup();
g_slist_foreach(cleanup_routines, &call_routine, NULL);
stream_cleanup();
expert_packet_cleanup();
wmem_leave_file_scope();
host_name_lookup_cleanup();
}
void
register_postseq_cleanup_routine(void_func_t func)
{
postseq_cleanup_routines = g_slist_prepend(postseq_cleanup_routines,
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
src = g_slice_new(struct data_source);
src->tvb = tvb;
src->name = g_strdup(name);
pinfo->data_src = g_slist_append(pinfo->data_src, src);
}
void
remove_last_data_source(packet_info *pinfo)
{
struct data_source *src;
GSList *last;
last = g_slist_last(pinfo->data_src);
src = (struct data_source *)last->data;
pinfo->data_src = g_slist_delete_link(pinfo->data_src, last);
g_free(src->name);
g_slice_free(struct data_source, src);
}
char*
get_data_source_name(const struct data_source *src)
{
guint length = tvb_captured_length(src->tvb);
return wmem_strdup_printf(NULL, "%s (%u byte%s)", src->name, length,
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
g_slice_free(struct data_source, src);
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
final_registration_routines = g_slist_prepend(final_registration_routines,
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
dissect_record(epan_dissect_t *edt, int file_type_subtype,
struct wtap_pkthdr *phdr, tvbuff_t *tvb, frame_data *fd, column_info *cinfo)
{
const char *volatile record_type;
frame_data_t frame_dissector_data;
switch (phdr->rec_type) {
case REC_TYPE_PACKET:
record_type = "Frame";
break;
case REC_TYPE_FT_SPECIFIC_EVENT:
record_type = "Event";
break;
case REC_TYPE_FT_SPECIFIC_REPORT:
record_type = "Report";
break;
default:
g_assert_not_reached();
break;
}
if (cinfo != NULL)
col_init(cinfo, edt->session);
edt->pi.epan = edt->session;
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
edt->pi.link_dir = LINK_DIR_UNKNOWN;
edt->pi.layers = wmem_list_new(edt->pi.pool);
edt->tvb = tvb;
frame_delta_abs_time(edt->session, fd, fd->frame_ref_num, &edt->pi.rel_ts);
if (fd->flags.has_user_comment)
frame_dissector_data.pkt_comment = epan_get_user_comment(edt->session, fd);
else if (fd->flags.has_phdr_comment)
frame_dissector_data.pkt_comment = phdr->opt_comment;
else
frame_dissector_data.pkt_comment = NULL;
frame_dissector_data.file_type_subtype = file_type_subtype;
TRY {
add_new_data_source(&edt->pi, edt->tvb, record_type);
call_dissector_with_data(frame_handle, edt->tvb, &edt->pi, edt->tree, &frame_dissector_data);
}
CATCH(BoundsError) {
g_assert_not_reached();
}
CATCH2(FragmentBoundsError, ReportedBoundsError) {
proto_tree_add_protocol_format(edt->tree, proto_malformed, edt->tvb, 0, 0,
"[Malformed %s: Packet Length]",
record_type);
}
ENDTRY;
fd->flags.visited = 1;
}
void
dissect_file(epan_dissect_t *edt, struct wtap_pkthdr *phdr,
tvbuff_t *tvb, frame_data *fd, column_info *cinfo)
{
if (cinfo != NULL)
col_init(cinfo, edt->session);
edt->pi.epan = edt->session;
edt->pi.current_proto = "<Missing Filetype Name>";
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
edt->pi.link_dir = LINK_DIR_UNKNOWN;
edt->pi.layers = wmem_list_new(edt->pi.pool);
edt->tvb = tvb;
frame_delta_abs_time(edt->session, fd, fd->frame_ref_num, &edt->pi.rel_ts);
TRY {
const gchar *pkt_comment;
if (fd->flags.has_user_comment)
pkt_comment = epan_get_user_comment(edt->session, fd);
else if (fd->flags.has_phdr_comment)
pkt_comment = phdr->opt_comment;
else
pkt_comment = NULL;
add_new_data_source(&edt->pi, edt->tvb, "File");
call_dissector_with_data(file_handle, edt->tvb, &edt->pi, edt->tree, (void*)pkt_comment);
}
CATCH(BoundsError) {
g_assert_not_reached();
}
CATCH2(FragmentBoundsError, ReportedBoundsError) {
proto_tree_add_protocol_format(edt->tree, proto_malformed, edt->tvb, 0, 0,
"[Malformed Record: Packet Length]" );
}
ENDTRY;
fd->flags.visited = 1;
}
static int
call_dissector_through_handle(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void *data)
{
const char *saved_proto;
int len;
saved_proto = pinfo->current_proto;
if (handle->protocol != NULL) {
pinfo->current_proto =
proto_get_protocol_short_name(handle->protocol);
}
if (handle->is_new) {
len = (*handle->dissector.new_d)(tvb, pinfo, tree, data);
} else {
(*handle->dissector.old)(tvb, pinfo, tree);
len = tvb_captured_length(tvb);
if (len == 0) {
len = 1;
}
}
pinfo->current_proto = saved_proto;
return len;
}
static int
call_dissector_work(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo_arg,
proto_tree *tree, gboolean add_proto_name, void *data)
{
packet_info *pinfo = pinfo_arg;
const char *saved_proto;
guint16 saved_can_desegment;
int len;
guint saved_layers_len = 0;
if (handle->protocol != NULL &&
!proto_is_protocol_enabled(handle->protocol)) {
return 0;
}
saved_proto = pinfo->current_proto;
saved_can_desegment = pinfo->can_desegment;
saved_layers_len = wmem_list_count(pinfo->layers);
pinfo->saved_can_desegment = saved_can_desegment;
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
if (handle->protocol != NULL) {
pinfo->current_proto =
proto_get_protocol_short_name(handle->protocol);
if (add_proto_name) {
pinfo->curr_layer_num++;
wmem_list_append(pinfo->layers, GINT_TO_POINTER(proto_get_id(handle->protocol)));
}
}
if (pinfo->flags.in_error_pkt) {
len = call_dissector_work_error(handle, tvb, pinfo, tree, data);
} else {
len = call_dissector_through_handle(handle, tvb, pinfo, tree, data);
}
if (len == 0) {
while (wmem_list_count(pinfo->layers) > saved_layers_len) {
wmem_list_remove_frame(pinfo->layers, wmem_list_tail(pinfo->layers));
}
}
pinfo->current_proto = saved_proto;
pinfo->can_desegment = saved_can_desegment;
return len;
}
static int
call_dissector_work_error(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo_arg, proto_tree *tree, void *data)
{
packet_info *pinfo = pinfo_arg;
const char *saved_proto;
guint16 saved_can_desegment;
volatile int len = 0;
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
len = call_dissector_through_handle(handle, tvb,pinfo, tree, data);
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
len = tvb_captured_length(tvb);
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
return len;
}
dissector_table_t
find_dissector_table(const char *name)
{
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
dissector_add_for_decode_as(name, handle);
}
void dissector_add_uint_range(const char *abbrev, range_t *range,
dissector_handle_t handle)
{
guint32 i, j;
if (range) {
for (i = 0; i < range->nranges; i++) {
for (j = range->ranges[i].low; j <= range->ranges[i].high; j++)
dissector_add_uint(abbrev, j, handle);
}
}
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
void dissector_delete_uint_range(const char *abbrev, range_t *range,
dissector_handle_t handle)
{
guint32 i, j;
if (range) {
for (i = 0; i < range->nranges; i++) {
for (j = range->ranges[i].low; j <= range->ranges[i].high; j++)
dissector_delete_uint(abbrev, j, handle);
}
}
}
static gboolean
dissector_delete_all_check (gpointer key _U_, gpointer value, gpointer user_data)
{
dtbl_entry_t *dtbl_entry = (dtbl_entry_t *) value;
dissector_handle_t handle = (dissector_handle_t) user_data;
if (!dtbl_entry->current->protocol) {
return FALSE;
}
return (proto_get_id (dtbl_entry->current->protocol) == proto_get_id (handle->protocol));
}
void dissector_delete_all(const char *name, dissector_handle_t handle)
{
dissector_table_t sub_dissectors = find_dissector_table(name);
g_assert (sub_dissectors);
g_hash_table_foreach_remove (sub_dissectors->hash_table, dissector_delete_all_check, handle);
}
static void
dissector_delete_from_table(gpointer key _U_, gpointer value, gpointer user_data)
{
dissector_table_t sub_dissectors = (dissector_table_t) value;
g_assert (sub_dissectors);
g_hash_table_foreach_remove(sub_dissectors->hash_table, dissector_delete_all_check, user_data);
sub_dissectors->dissector_handles = g_slist_remove(sub_dissectors->dissector_handles, user_data);
}
static void
dissector_delete_from_all_tables(dissector_handle_t handle)
{
g_hash_table_foreach(dissector_tables, dissector_delete_from_table, handle);
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
int
dissector_try_uint_new(dissector_table_t sub_dissectors, const guint32 uint_val,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const gboolean add_proto_name, void *data)
{
dtbl_entry_t *dtbl_entry;
struct dissector_handle *handle;
guint32 saved_match_uint;
int len;
dtbl_entry = find_uint_dtbl_entry(sub_dissectors, uint_val);
if (dtbl_entry != NULL) {
handle = dtbl_entry->current;
if (handle == NULL) {
return 0;
}
saved_match_uint = pinfo->match_uint;
pinfo->match_uint = uint_val;
len = call_dissector_work(handle, tvb, pinfo, tree, add_proto_name, data);
pinfo->match_uint = saved_match_uint;
return len;
}
return 0;
}
int
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
dissector_handle_t
dissector_get_default_uint_handle(const char *name, const guint32 uint_val)
{
dissector_table_t sub_dissectors = find_dissector_table(name);
if (sub_dissectors != NULL) {
dtbl_entry_t *dtbl_entry = find_uint_dtbl_entry(sub_dissectors, uint_val);
if (dtbl_entry != NULL)
return dtbl_entry->initial;
}
return NULL;
}
static dtbl_entry_t *
find_string_dtbl_entry(dissector_table_t const sub_dissectors, const gchar *pattern)
{
dtbl_entry_t *ret;
char *key;
switch (sub_dissectors->type) {
case FT_STRING:
case FT_STRINGZ:
case FT_STRINGZPAD:
break;
default:
g_assert_not_reached();
}
if (sub_dissectors->param == TRUE) {
key = g_ascii_strdown(pattern, -1);
} else {
key = g_strdup(pattern);
}
ret = (dtbl_entry_t *)g_hash_table_lookup(sub_dissectors->hash_table, key);
g_free(key);
return ret;
}
void
dissector_add_string(const char *name, const gchar *pattern,
dissector_handle_t handle)
{
dissector_table_t sub_dissectors = find_dissector_table( name);
dtbl_entry_t *dtbl_entry;
char *key;
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
case FT_STRINGZPAD:
break;
default:
g_assert_not_reached();
}
dtbl_entry = (dtbl_entry_t *)g_malloc(sizeof (dtbl_entry_t));
dtbl_entry->current = handle;
dtbl_entry->initial = dtbl_entry->current;
if (sub_dissectors->param == TRUE) {
key = g_ascii_strdown(pattern, -1);
} else {
key = g_strdup(pattern);
}
g_hash_table_insert( sub_dissectors->hash_table, (gpointer)key,
(gpointer)dtbl_entry);
dissector_add_for_decode_as(name, handle);
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
g_hash_table_insert( sub_dissectors->hash_table, (gpointer)g_strdup(pattern),
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
int
dissector_try_string(dissector_table_t sub_dissectors, const gchar *string,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dtbl_entry_t *dtbl_entry;
struct dissector_handle *handle;
int len;
const gchar *saved_match_string;
if (!string) return 0;
dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
if (dtbl_entry != NULL) {
handle = dtbl_entry->current;
if (handle == NULL) {
return 0;
}
saved_match_string = pinfo->match_string;
pinfo->match_string = string;
len = call_dissector_work(handle, tvb, pinfo, tree, TRUE, data);
pinfo->match_string = saved_match_string;
return len;
}
return 0;
}
dissector_handle_t
dissector_get_string_handle(dissector_table_t sub_dissectors,
const gchar *string)
{
dtbl_entry_t *dtbl_entry;
if (!string) return NULL;
dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
if (dtbl_entry != NULL)
return dtbl_entry->current;
else
return NULL;
}
dissector_handle_t
dissector_get_default_string_handle(const char *name, const gchar *string)
{
dissector_table_t sub_dissectors;
if (!string) return NULL;
sub_dissectors = find_dissector_table(name);
if (sub_dissectors != NULL) {
dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
if (dtbl_entry != NULL)
return dtbl_entry->initial;
}
return NULL;
}
void dissector_add_custom_table_handle(const char *name, void *pattern, dissector_handle_t handle)
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
g_assert(sub_dissectors->type == FT_BYTES);
dtbl_entry = (dtbl_entry_t *)g_malloc(sizeof (dtbl_entry_t));
dtbl_entry->current = handle;
dtbl_entry->initial = dtbl_entry->current;
g_hash_table_insert( sub_dissectors->hash_table, (gpointer)pattern,
(gpointer)dtbl_entry);
dissector_add_for_decode_as(name, handle);
}
dissector_handle_t dissector_get_custom_table_handle(dissector_table_t sub_dissectors, void *key)
{
dtbl_entry_t *dtbl_entry = (dtbl_entry_t *)g_hash_table_lookup(sub_dissectors->hash_table, key);
if (dtbl_entry != NULL)
return dtbl_entry->current;
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
const struct dissector_handle *a = (const struct dissector_handle *)dissector_a;
const struct dissector_handle *b = (const struct dissector_handle *)dissector_b;
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
dissector_add_for_decode_as(const char *name, dissector_handle_t handle)
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
GSList *
dissector_table_get_dissector_handles(dissector_table_t dissector_table) {
if (!dissector_table) return NULL;
return dissector_table->dissector_handles;
}
ftenum_t
dissector_table_get_type(dissector_table_t dissector_table) {
if (!dissector_table) return FT_NONE;
return dissector_table->type;
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
dissector_table_foreach (const char *table_name,
DATFunc func,
gpointer user_data)
{
dissector_foreach_info_t info;
dissector_table_t sub_dissectors = find_dissector_table(table_name);
info.table_name = table_name;
info.selector_type = sub_dissectors->type;
info.caller_func = func;
info.caller_data = user_data;
g_hash_table_foreach(sub_dissectors->hash_table, dissector_table_foreach_func, &info);
}
void
dissector_table_foreach_handle(const char *table_name,
DATFunc_handle func,
gpointer user_data)
{
dissector_table_t sub_dissectors = find_dissector_table(table_name);
GSList *tmp;
for (tmp = sub_dissectors->dissector_handles; tmp != NULL;
tmp = g_slist_next(tmp))
func(table_name, tmp->data, user_data);
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
dissector_table_foreach_changed (const char *table_name,
DATFunc func,
gpointer user_data)
{
dissector_foreach_info_t info;
dissector_table_t sub_dissectors = find_dissector_table(table_name);
info.table_name = table_name;
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
GList *list;
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
const int param)
{
dissector_table_t sub_dissectors;
if(g_hash_table_lookup( dissector_tables, name )) {
g_error("The dissector table %s (%s) is already registered - are you using a buggy plugin?", name, ui_name);
}
sub_dissectors = g_slice_new(struct dissector_table);
switch (type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
sub_dissectors->hash_func = g_direct_hash;
sub_dissectors->hash_table = g_hash_table_new_full( g_direct_hash,
g_direct_equal,
NULL,
&g_free );
break;
case FT_STRING:
case FT_STRINGZ:
case FT_STRINGZPAD:
sub_dissectors->hash_func = g_str_hash;
sub_dissectors->hash_table = g_hash_table_new_full( g_str_hash,
g_str_equal,
&g_free,
&g_free );
break;
default:
g_assert_not_reached();
}
sub_dissectors->dissector_handles = NULL;
sub_dissectors->ui_name = ui_name;
sub_dissectors->type = type;
sub_dissectors->param = param;
g_hash_table_insert( dissector_tables, (gpointer)name, (gpointer) sub_dissectors );
return sub_dissectors;
}
dissector_table_t register_custom_dissector_table(const char *name,
const char *ui_name, GHashFunc hash_func, GEqualFunc key_equal_func)
{
dissector_table_t sub_dissectors;
if(g_hash_table_lookup( dissector_tables, name )) {
g_error("The dissector table %s (%s) is already registered - are you using a buggy plugin?", name, ui_name);
}
sub_dissectors = g_slice_new(struct dissector_table);
sub_dissectors->hash_func = hash_func;
sub_dissectors->hash_table = g_hash_table_new_full(hash_func,
key_equal_func,
&g_free,
&g_free );
sub_dissectors->dissector_handles = NULL;
sub_dissectors->ui_name = ui_name;
sub_dissectors->type = FT_BYTES;
sub_dissectors->param = BASE_NONE;
g_hash_table_insert( dissector_tables, (gpointer)name, (gpointer) sub_dissectors );
return sub_dissectors;
}
void
deregister_dissector_table(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table(name);
if (!sub_dissectors) return;
g_hash_table_remove(dissector_tables, (gpointer)name);
}
const char *
get_dissector_table_ui_name(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table(name);
if (!sub_dissectors) return NULL;
return sub_dissectors->ui_name;
}
ftenum_t
get_dissector_table_selector_type(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table(name);
if (!sub_dissectors) return FT_NONE;
return sub_dissectors->type;
}
int
get_dissector_table_param(const char *name)
{
dissector_table_t sub_dissectors = find_dissector_table(name);
if (!sub_dissectors) return 0;
return sub_dissectors->param;
}
heur_dissector_list_t
find_heur_dissector_list(const char *name)
{
return (heur_dissector_list_t)g_hash_table_lookup(heur_dissector_lists, name);
}
gboolean
has_heur_dissector_list(const gchar *name) {
return (find_heur_dissector_list(name) != NULL);
}
heur_dtbl_entry_t* find_heur_dissector_by_unique_short_name(const char *short_name)
{
return (heur_dtbl_entry_t*)g_hash_table_lookup(heuristic_short_names, (gpointer)short_name);
}
void
heur_dissector_add(const char *name, heur_dissector_t dissector, const char *display_name, const char *short_name, const int proto, heuristic_enable_e enable)
{
heur_dissector_list_t sub_dissectors = find_heur_dissector_list(name);
const char *proto_name;
heur_dtbl_entry_t *hdtbl_entry;
guint i, list_size;
GSList *list_entry;
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
list_size = g_slist_length(sub_dissectors->dissectors);
for (i = 0; i < list_size; i++)
{
list_entry = g_slist_nth(sub_dissectors->dissectors, i);
hdtbl_entry = (heur_dtbl_entry_t *)list_entry->data;
if ((hdtbl_entry->dissector == dissector) &&
(hdtbl_entry->protocol == find_protocol_by_id(proto)))
{
proto_name = proto_get_protocol_name(proto);
if (proto_name != NULL) {
fprintf(stderr, "Protocol %s is already registered in \"%s\" table\n",
proto_name, name);
}
if (getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != NULL)
abort();
return;
}
}
if (g_hash_table_lookup(heuristic_short_names, (gpointer)short_name) != NULL) {
g_error("Duplicate heuristic short_name \"%s\"!"
" This might be caused by an inappropriate plugin or a development error.", short_name);
}
hdtbl_entry = g_slice_new(heur_dtbl_entry_t);
hdtbl_entry->dissector = dissector;
hdtbl_entry->protocol = find_protocol_by_id(proto);
hdtbl_entry->display_name = display_name;
hdtbl_entry->short_name = short_name;
hdtbl_entry->list_name = g_strdup(name);
hdtbl_entry->enabled = (enable == HEURISTIC_ENABLE);
g_hash_table_insert(heuristic_short_names, (gpointer)short_name, hdtbl_entry);
sub_dissectors->dissectors = g_slist_prepend(sub_dissectors->dissectors,
(gpointer)hdtbl_entry);
proto_add_heuristic_dissector(hdtbl_entry->protocol, short_name);
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
heur_dissector_list_t sub_dissectors = find_heur_dissector_list(name);
heur_dtbl_entry_t hdtbl_entry;
GSList *found_entry;
g_assert(sub_dissectors != NULL);
hdtbl_entry.dissector = dissector;
hdtbl_entry.protocol = find_protocol_by_id(proto);
found_entry = g_slist_find_custom(sub_dissectors->dissectors,
(gpointer) &hdtbl_entry, find_matching_heur_dissector);
if (found_entry) {
g_free(((heur_dtbl_entry_t *)(found_entry->data))->list_name);
g_slice_free(heur_dtbl_entry_t, found_entry->data);
sub_dissectors->dissectors = g_slist_delete_link(sub_dissectors->dissectors,
found_entry);
}
}
gboolean
dissector_try_heuristic(heur_dissector_list_t sub_dissectors, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, heur_dtbl_entry_t **heur_dtbl_entry, void *data)
{
gboolean status;
const char *saved_curr_proto;
const char *saved_heur_list_name;
GSList *entry;
guint16 saved_can_desegment;
guint saved_layers_len = 0;
heur_dtbl_entry_t *hdtbl_entry;
int proto_id;
saved_can_desegment = pinfo->can_desegment;
pinfo->saved_can_desegment = saved_can_desegment;
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
status = FALSE;
saved_curr_proto = pinfo->current_proto;
saved_heur_list_name = pinfo->heur_list_name;
saved_layers_len = wmem_list_count(pinfo->layers);
*heur_dtbl_entry = NULL;
for (entry = sub_dissectors->dissectors; entry != NULL;
entry = g_slist_next(entry)) {
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
hdtbl_entry = (heur_dtbl_entry_t *)entry->data;
if (hdtbl_entry->protocol != NULL &&
(!proto_is_protocol_enabled(hdtbl_entry->protocol)||(hdtbl_entry->enabled==FALSE))) {
continue;
}
proto_id = proto_get_id(hdtbl_entry->protocol);
if (hdtbl_entry->protocol != NULL) {
pinfo->current_proto =
proto_get_protocol_short_name(hdtbl_entry->protocol);
wmem_list_append(pinfo->layers, GINT_TO_POINTER(proto_id));
}
pinfo->heur_list_name = hdtbl_entry->list_name;
if ((hdtbl_entry->dissector)(tvb, pinfo, tree, data)) {
*heur_dtbl_entry = hdtbl_entry;
status = TRUE;
break;
} else {
while (wmem_list_count(pinfo->layers) > saved_layers_len) {
wmem_list_remove_frame(pinfo->layers, wmem_list_tail(pinfo->layers));
}
}
}
pinfo->current_proto = saved_curr_proto;
pinfo->heur_list_name = saved_heur_list_name;
pinfo->can_desegment = saved_can_desegment;
return status;
}
static void
heur_dissector_table_foreach_func (gpointer data, gpointer user_data)
{
heur_dissector_foreach_info_t *info;
g_assert(data);
g_assert(user_data);
info = (heur_dissector_foreach_info_t *)user_data;
info->caller_func(info->table_name, (heur_dtbl_entry_t *)data,
info->caller_data);
}
void
heur_dissector_table_foreach (const char *table_name,
DATFunc_heur func,
gpointer user_data)
{
heur_dissector_foreach_info_t info;
heur_dissector_list_t sub_dissectors = find_heur_dissector_list(table_name);
info.table_name = table_name;
info.caller_func = func;
info.caller_data = user_data;
g_slist_foreach(sub_dissectors->dissectors,
heur_dissector_table_foreach_func, &info);
}
static void
dissector_all_heur_tables_foreach_table_func (gpointer key, const gpointer value, const gpointer user_data)
{
heur_dissector_foreach_table_info_t *info;
info = (heur_dissector_foreach_table_info_t *)user_data;
(*info->caller_func)((gchar*)key, (struct heur_dissector_list *)value, info->caller_data);
}
static void
dissector_all_heur_tables_foreach_list_func (gpointer key, gpointer user_data)
{
struct heur_dissector_list *list;
heur_dissector_foreach_table_info_t *info;
list = (struct heur_dissector_list *)g_hash_table_lookup(heur_dissector_lists, key);
info = (heur_dissector_foreach_table_info_t *)user_data;
(*info->caller_func)((gchar*)key, list, info->caller_data);
}
void
dissector_all_heur_tables_foreach_table (DATFunc_heur_table func,
gpointer user_data,
GCompareFunc compare_key_func)
{
heur_dissector_foreach_table_info_t info;
GList *list;
info.caller_data = user_data;
info.caller_func = func;
if (compare_key_func != NULL)
{
list = g_hash_table_get_keys(dissector_tables);
list = g_list_sort(list, compare_key_func);
g_list_foreach(list, dissector_all_heur_tables_foreach_list_func, &info);
g_list_free(list);
}
else
{
g_hash_table_foreach(heur_dissector_lists, dissector_all_heur_tables_foreach_table_func, &info);
}
}
static void
display_heur_dissector_table_entries(const char *table_name,
heur_dtbl_entry_t *hdtbl_entry, gpointer user_data _U_)
{
if (hdtbl_entry->protocol != NULL) {
printf("%s\t%s\t%c\n",
table_name,
proto_get_protocol_filter_name(proto_get_id(hdtbl_entry->protocol)),
(proto_is_protocol_enabled(hdtbl_entry->protocol) && hdtbl_entry->enabled) ? 'T' : 'F');
}
}
static void
dissector_dump_heur_decodes_display(const gchar *table_name, struct heur_dissector_list *listptr _U_, const gpointer user_data _U_)
{
heur_dissector_table_foreach(table_name, display_heur_dissector_table_entries, NULL);
}
void
dissector_dump_heur_decodes(void)
{
dissector_all_heur_tables_foreach_table(dissector_dump_heur_decodes_display, NULL, NULL);
}
heur_dissector_list_t
register_heur_dissector_list(const char *name)
{
heur_dissector_list_t sub_dissectors;
if (g_hash_table_lookup(heur_dissector_lists, name) != NULL) {
g_error("The heuristic dissector list %s is already registered - are you using a buggy plugin?", name);
}
sub_dissectors = g_slice_new(struct heur_dissector_list);
sub_dissectors->dissectors = NULL;
g_hash_table_insert(heur_dissector_lists, (gpointer)name,
(gpointer) sub_dissectors);
return sub_dissectors;
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
GList*
get_dissector_names(void)
{
return g_hash_table_get_keys(registered_dissectors);
}
dissector_handle_t
find_dissector(const char *name)
{
return (dissector_handle_t)g_hash_table_lookup(registered_dissectors, name);
}
const char *
dissector_handle_get_dissector_name(const dissector_handle_t handle)
{
if (handle == NULL) {
return NULL;
}
return handle->name;
}
dissector_handle_t
create_dissector_handle(dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
handle = wmem_new(wmem_epan_scope(), struct dissector_handle);
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
handle = wmem_new(wmem_epan_scope(), struct dissector_handle);
handle->name = NULL;
handle->is_new = TRUE;
handle->dissector.new_d = dissector;
handle->protocol = find_protocol_by_id(proto);
return handle;
}
dissector_handle_t new_create_dissector_handle_with_name(new_dissector_t dissector,
const int proto, const char* name)
{
struct dissector_handle *handle;
handle = wmem_new(wmem_epan_scope(), struct dissector_handle);
handle->name = name;
handle->is_new = TRUE;
handle->dissector.new_d = dissector;
handle->protocol = find_protocol_by_id(proto);
return handle;
}
void
destroy_dissector_handle(dissector_handle_t handle)
{
if (handle == NULL) return;
dissector_delete_from_all_tables(handle);
deregister_postdissector(handle);
wmem_free(wmem_epan_scope(), handle);
}
dissector_handle_t
register_dissector(const char *name, dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
g_assert(g_hash_table_lookup(registered_dissectors, name) == NULL);
handle = wmem_new(wmem_epan_scope(), struct dissector_handle);
handle->name = name;
handle->is_new = FALSE;
handle->dissector.old = dissector;
handle->protocol = find_protocol_by_id(proto);
g_hash_table_insert(registered_dissectors, (gpointer)name,
(gpointer) handle);
return handle;
}
dissector_handle_t
new_register_dissector(const char *name, new_dissector_t dissector, const int proto)
{
struct dissector_handle *handle;
g_assert(g_hash_table_lookup(registered_dissectors, name) == NULL);
handle = wmem_new(wmem_epan_scope(), struct dissector_handle);
handle->name = name;
handle->is_new = TRUE;
handle->dissector.new_d = dissector;
handle->protocol = find_protocol_by_id(proto);
g_hash_table_insert(registered_dissectors, (gpointer)name,
(gpointer) handle);
return handle;
}
void
deregister_dissector(const char *name)
{
dissector_handle_t handle = find_dissector(name);
if (handle == NULL) return;
g_hash_table_remove(registered_dissectors, (gpointer)name);
g_hash_table_remove(heur_dissector_lists, (gpointer)name);
destroy_dissector_handle(handle);
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
g_assert(data_handle->protocol != NULL);
call_dissector_work(data_handle, tvb, pinfo, tree, TRUE, NULL);
return tvb_captured_length(tvb);
}
return ret;
}
int
call_dissector(dissector_handle_t handle, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree)
{
return call_dissector_with_data(handle, tvb, pinfo, tree, NULL);
}
void call_heur_dissector_direct(heur_dtbl_entry_t *heur_dtbl_entry, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void *data)
{
const char *saved_curr_proto;
const char *saved_heur_list_name;
guint16 saved_can_desegment;
g_assert(heur_dtbl_entry);
saved_can_desegment = pinfo->can_desegment;
pinfo->saved_can_desegment = saved_can_desegment;
pinfo->can_desegment = saved_can_desegment-(saved_can_desegment>0);
saved_curr_proto = pinfo->current_proto;
saved_heur_list_name = pinfo->heur_list_name;
if (!heur_dtbl_entry->enabled ||
(heur_dtbl_entry->protocol != NULL && !proto_is_protocol_enabled(heur_dtbl_entry->protocol))) {
g_assert(data_handle->protocol != NULL);
call_dissector_work(data_handle, tvb, pinfo, tree, TRUE, NULL);
return;
}
if (heur_dtbl_entry->protocol != NULL) {
pinfo->current_proto = proto_get_protocol_short_name(heur_dtbl_entry->protocol);
wmem_list_append(pinfo->layers, GINT_TO_POINTER(proto_get_id(heur_dtbl_entry->protocol)));
}
pinfo->heur_list_name = heur_dtbl_entry->list_name;
if(!(*heur_dtbl_entry->dissector)(tvb, pinfo, tree, data))
g_assert_not_reached();
pinfo->can_desegment = saved_can_desegment;
pinfo->current_proto = saved_curr_proto;
pinfo->heur_list_name = saved_heur_list_name;
}
static void
dissector_dump_decodes_display(const gchar *table_name,
ftenum_t selector_type _U_, const gpointer key, const gpointer value,
gpointer user_data _U_)
{
guint32 selector = GPOINTER_TO_UINT (key);
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
static void
dissector_dump_dissector_tables_display (gpointer key, gpointer user_data _U_)
{
const char *table_name = (const char *)key;
dissector_table_t table;
table = (dissector_table_t)g_hash_table_lookup(dissector_tables, key);
printf("%s\t%s\t%s", table_name, table->ui_name, ftype_name(table->type));
switch (table->type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
switch(table->param) {
case BASE_NONE:
printf("\tBASE_NONE");
break;
case BASE_DEC:
printf("\tBASE_DEC");
break;
case BASE_HEX:
printf("\tBASE_HEX");
break;
case BASE_DEC_HEX:
printf("\tBASE_DEC_HEX");
break;
case BASE_HEX_DEC:
printf("\tBASE_HEX_DEC");
break;
default:
printf("\t%d", table->param);
break;
}
break;
default:
break;
}
printf("\n");
}
static gint
compare_dissector_key_name(gconstpointer dissector_a, gconstpointer dissector_b)
{
return strcmp((const char*)dissector_a, (const char*)dissector_b);
}
void
dissector_dump_dissector_tables(void)
{
GList *list;
list = g_hash_table_get_keys(dissector_tables);
list = g_list_sort(list, compare_dissector_key_name);
g_list_foreach(list, dissector_dump_dissector_tables_display, NULL);
g_list_free(list);
}
void
register_postdissector(dissector_handle_t handle)
{
if (!post_dissectors)
post_dissectors = g_ptr_array_new();
g_ptr_array_add(post_dissectors, handle);
num_of_postdissectors++;
}
void
deregister_postdissector(dissector_handle_t handle)
{
if (!post_dissectors) return;
if (g_ptr_array_remove(post_dissectors, handle)) {
num_of_postdissectors--;
}
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
