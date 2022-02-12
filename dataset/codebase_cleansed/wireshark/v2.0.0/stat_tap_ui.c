static gint
sort_by_name(gconstpointer a, gconstpointer b)
{
return strcmp(((const stat_cmd_arg *)a)->cmd, ((const stat_cmd_arg *)b)->cmd);
}
void
register_stat_tap_ui(stat_tap_ui *ui, void *userdata)
{
stat_cmd_arg *newsca;
newsca=(stat_cmd_arg *)g_malloc(sizeof(stat_cmd_arg));
newsca->cmd=ui->cli_string;
newsca->func=ui->tap_init_cb;
newsca->userdata=userdata;
stat_cmd_arg_list=g_list_insert_sorted(stat_cmd_arg_list, newsca, sort_by_name);
}
gboolean
process_stat_cmd_arg(char *optstr)
{
GList *entry;
stat_cmd_arg *sca;
stat_requested *tr;
for(entry=g_list_last(stat_cmd_arg_list);entry;entry=g_list_previous(entry)){
sca=(stat_cmd_arg *)entry->data;
if(!strncmp(sca->cmd,optstr,strlen(sca->cmd))){
tr=(stat_requested *)g_malloc(sizeof (stat_requested));
tr->sca = sca;
tr->arg=g_strdup(optstr);
stats_requested=g_slist_append(stats_requested, tr);
return TRUE;
}
}
return FALSE;
}
void
list_stat_cmd_args(void)
{
GList *entry;
stat_cmd_arg *sca;
for(entry=stat_cmd_arg_list;entry;entry=g_list_next(entry)){
sca=(stat_cmd_arg *)entry->data;
fprintf(stderr," %s\n",sca->cmd);
}
}
void
start_requested_stats(void)
{
stat_requested *sr;
while(stats_requested){
sr=(stat_requested *)stats_requested->data;
(*sr->sca->func)(sr->arg,sr->sca->userdata);
g_free(sr->arg);
g_free(sr);
stats_requested=g_slist_remove(stats_requested, sr);
}
}
static gint
insert_sorted_by_cli_string(gconstpointer aparam, gconstpointer bparam)
{
const new_stat_tap_ui *a = (new_stat_tap_ui *)aparam;
const new_stat_tap_ui *b = (new_stat_tap_ui *)bparam;
return g_ascii_strcasecmp(a->cli_string, b->cli_string);
}
void register_new_stat_tap_ui(new_stat_tap_ui *ui)
{
registered_stat_tables = g_slist_insert_sorted(registered_stat_tables, ui, insert_sorted_by_cli_string);
}
void new_stat_tap_iterate_tables(GFunc func, gpointer user_data)
{
g_slist_foreach(registered_stat_tables, func, user_data);
}
void new_stat_tap_get_filter(new_stat_tap_ui* new_stat, const char *opt_arg, const char **filter, char** err)
{
guint len = (guint) strlen(new_stat->cli_string);
*filter=NULL;
*err=NULL;
if (!strncmp(opt_arg, new_stat->cli_string, len))
{
if (opt_arg[len] == ',')
{
*filter = opt_arg + len+1;
}
}
if (new_stat->new_stat_filter_check_cb)
new_stat->new_stat_filter_check_cb(opt_arg, filter, err);
}
new_stat_tap_table* new_stat_tap_init_table(const char *name, int num_fields, int num_elements,
const char *filter_string, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
new_stat_tap_table* new_table = g_new0(new_stat_tap_table, 1);
new_table->title = name;
new_table->num_elements = num_elements;
new_table->num_fields = num_fields;
new_table->filter_string = filter_string;
new_table->elements = g_new0(stat_tap_table_item_type*, num_elements);
if (gui_callback)
gui_callback(new_table, gui_data);
return new_table;
}
void new_stat_tap_add_table(new_stat_tap_ui* new_stat, new_stat_tap_table* table)
{
if (new_stat->tables == NULL)
new_stat->tables = g_array_new(FALSE, TRUE, sizeof(new_stat_tap_table*));
g_array_insert_val(new_stat->tables, new_stat->tables->len, table);
}
void new_stat_tap_init_table_row(new_stat_tap_table *stat_table, guint table_index, guint num_fields, const stat_tap_table_item_type* fields)
{
if(table_index>=stat_table->num_elements){
guint old_num_elements=stat_table->num_elements;
guint i;
stat_table->num_elements=table_index+1;
stat_table->elements = (stat_tap_table_item_type**)g_realloc(stat_table->elements, sizeof(stat_tap_table_item_type*)*(stat_table->num_elements));
for(i=old_num_elements;i<stat_table->num_elements;i++){
stat_table->elements[i] = g_new0(stat_tap_table_item_type, stat_table->num_fields);
}
}
memcpy(stat_table->elements[table_index], fields, num_fields*sizeof(stat_tap_table_item_type));
}
stat_tap_table_item_type* new_stat_tap_get_field_data(const new_stat_tap_table *stat_table, guint table_index, guint field_index)
{
stat_tap_table_item_type* field_value;
g_assert(table_index < stat_table->num_elements);
field_value = stat_table->elements[table_index];
g_assert(field_index < stat_table->num_fields);
return &field_value[field_index];
}
void new_stat_tap_set_field_data(new_stat_tap_table *stat_table, guint table_index, guint field_index, stat_tap_table_item_type* field_data)
{
stat_tap_table_item_type* field_value;
g_assert(table_index < stat_table->num_elements);
field_value = stat_table->elements[table_index];
g_assert(field_index < stat_table->num_fields);
field_value[field_index] = *field_data;
}
void reset_stat_table(new_stat_tap_ui* new_stat, new_stat_tap_gui_reset_cb gui_callback, void *callback_data)
{
guint i = 0;
new_stat_tap_table *stat_table;
for (i = 0; i < new_stat->tables->len; i++)
{
stat_table = g_array_index(new_stat->tables, new_stat_tap_table*, i);
if (gui_callback)
gui_callback(stat_table, callback_data);
if (new_stat->stat_tap_reset_table_cb)
new_stat->stat_tap_reset_table_cb(stat_table);
}
}
void free_stat_tables(new_stat_tap_ui* new_stat, new_stat_tap_gui_free_cb gui_callback, void *callback_data)
{
guint i = 0, element, field_index;
new_stat_tap_table *stat_table;
stat_tap_table_item_type* field_data;
for (i = 0; i < new_stat->tables->len; i++)
{
stat_table = g_array_index(new_stat->tables, new_stat_tap_table*, i);
if (gui_callback)
gui_callback(stat_table, callback_data);
for (element = 0; element < stat_table->num_elements; element++)
{
for (field_index = 0; field_index < stat_table->num_fields; field_index++)
{
field_data = new_stat_tap_get_field_data(stat_table, element, field_index);
if (new_stat->stat_tap_free_table_item_cb)
new_stat->stat_tap_free_table_item_cb(stat_table, element, field_index, field_data);
}
g_free(stat_table->elements[element]);
}
g_free(stat_table->elements);
g_free(stat_table);
}
g_array_set_size(new_stat->tables, 0);
}
