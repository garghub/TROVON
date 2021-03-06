int get_rtd_proto_id(register_rtd_t* rtd)
{
if (!rtd) {
return -1;
}
return rtd->proto_id;
}
const char* get_rtd_tap_listener_name(register_rtd_t* rtd)
{
return rtd->tap_listen_str;
}
tap_packet_cb get_rtd_packet_func(register_rtd_t* rtd)
{
return rtd->rtd_func;
}
guint get_rtd_num_tables(register_rtd_t* rtd) {
return rtd->num_tables;
}
const value_string* get_rtd_value_string(register_rtd_t* rtd)
{
return rtd->vs_type;
}
static gint
insert_sorted_by_table_name(gconstpointer aparam, gconstpointer bparam)
{
const register_rtd_t *a = (register_rtd_t *)aparam;
const register_rtd_t *b = (register_rtd_t *)bparam;
return g_ascii_strcasecmp(proto_get_protocol_short_name(find_protocol_by_id(a->proto_id)), proto_get_protocol_short_name(find_protocol_by_id(b->proto_id)));
}
void
register_rtd_table(const int proto_id, const char* tap_listener, guint num_tables, guint num_timestats, const value_string* vs_type,
tap_packet_cb rtd_packet_func, rtd_filter_check_cb filter_check_cb)
{
register_rtd_t *table;
DISSECTOR_ASSERT(rtd_packet_func);
table = g_new(register_rtd_t,1);
table->proto_id = proto_id;
if (tap_listener != NULL)
table->tap_listen_str = tap_listener;
else
table->tap_listen_str = proto_get_protocol_filter_name(proto_id);
table->rtd_func = rtd_packet_func;
table->num_tables = num_tables;
table->num_timestats = num_timestats;
table->vs_type = vs_type;
table->filter_check = filter_check_cb;
registered_rtd_tables = g_slist_insert_sorted(registered_rtd_tables, table, insert_sorted_by_table_name);
}
void free_rtd_table(rtd_stat_table* table, rtd_gui_free_cb gui_callback, void *callback_data)
{
guint i;
for (i = 0; i < table->num_rtds; i++)
{
g_free(table->time_stats[i].rtd);
}
g_free(table->time_stats);
table->time_stats = NULL;
table->num_rtds = 0;
if (gui_callback)
gui_callback(table, callback_data);
}
void reset_rtd_table(rtd_stat_table* table, rtd_gui_reset_cb gui_callback, void *callback_data)
{
guint i = 0;
for (i = 0; i < table->num_rtds; i++)
memset(table->time_stats[i].rtd, 0, sizeof(timestat_t)*table->time_stats[i].num_timestat);
if (gui_callback)
gui_callback(table, callback_data);
}
register_rtd_t* get_rtd_table_by_name(const char* name)
{
guint i, size = g_slist_length(registered_rtd_tables);
register_rtd_t* rtd;
GSList *slist;
for (i = 0; i < size; i++) {
slist = g_slist_nth(registered_rtd_tables, i);
rtd = (register_rtd_t*)slist->data;
if (strcmp(name, proto_get_protocol_filter_name(rtd->proto_id)) == 0)
return rtd;
}
return NULL;
}
gchar* rtd_table_get_tap_string(register_rtd_t* rtd)
{
GString *cmd_str = g_string_new(proto_get_protocol_filter_name(rtd->proto_id));
g_string_append(cmd_str, ",rtd");
return g_string_free(cmd_str, FALSE);
}
void rtd_table_get_filter(register_rtd_t* rtd, const char *opt_arg, const char **filter, char** err)
{
gchar* cmd_str = rtd_table_get_tap_string(rtd);
guint len = (guint) strlen(cmd_str);
*filter=NULL;
*err=NULL;
if (!strncmp(opt_arg, cmd_str, len))
{
if (opt_arg[len] == ',')
{
*filter = opt_arg + len+1;
}
}
if (rtd->filter_check)
rtd->filter_check(opt_arg, filter, err);
g_free(cmd_str);
}
void rtd_table_dissector_init(register_rtd_t* rtd, rtd_stat_table* table, rtd_gui_init_cb gui_callback, void *callback_data)
{
guint i;
table->num_rtds = rtd->num_tables;
table->time_stats = g_new0(rtd_timestat, rtd->num_tables);
for (i = 0; i < table->num_rtds; i++)
{
table->time_stats[i].num_timestat = rtd->num_timestats;
table->time_stats[i].rtd = g_new0(timestat_t, rtd->num_timestats);
}
if (gui_callback)
gui_callback(table, callback_data);
}
void rtd_table_iterate_tables(GFunc func, gpointer user_data)
{
g_slist_foreach(registered_rtd_tables, func, user_data);
}
