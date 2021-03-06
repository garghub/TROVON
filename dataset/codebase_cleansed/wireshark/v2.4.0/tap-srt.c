static void
draw_srt_table_data(srt_stat_table *rst, gboolean draw_footer)
{
int i;
guint64 td;
guint64 sum;
if (rst->num_procs > 0) {
printf("Filter: %s\n", rst->filter_string ? rst->filter_string : "");
printf("Index %-22s Calls Min SRT Max SRT Avg SRT Sum SRT\n", (rst->proc_column_name != NULL) ? rst->proc_column_name : "Procedure");
}
for(i=0;i<rst->num_procs;i++){
if(rst->procedures[i].stats.num==0){
continue;
}
td = ((guint64)(rst->procedures[i].stats.tot.secs))*NANOSECS_PER_SEC + rst->procedures[i].stats.tot.nsecs;
sum = (td + 500) / 1000;
td = ((td / rst->procedures[i].stats.num) + 500) / 1000;
printf("%5d %-22s %6u %3d.%06d %3d.%06d %3d.%06d %3d.%06d\n",
i, rst->procedures[i].procedure,
rst->procedures[i].stats.num,
(int)rst->procedures[i].stats.min.secs, (rst->procedures[i].stats.min.nsecs+500)/1000,
(int)rst->procedures[i].stats.max.secs, (rst->procedures[i].stats.max.nsecs+500)/1000,
(int)(td/1000000), (int)(td%1000000),
(int)(sum/1000000), (int)(sum%1000000)
);
}
if (draw_footer)
printf("==================================================================\n");
}
static void
srt_draw(void *arg)
{
guint i = 0;
srt_data_t* data = (srt_data_t*)arg;
srt_t *ui = (srt_t *)data->user_data;
srt_stat_table *srt_table;
gboolean need_newline = FALSE;
printf("\n");
printf("===================================================================\n");
printf("%s SRT Statistics:\n", ui->type);
srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
draw_srt_table_data(srt_table, data->srt_array->len == 1);
if (srt_table->num_procs > 0) {
need_newline = TRUE;
}
for (i = 1; i < data->srt_array->len; i++)
{
if (need_newline)
{
printf("\n");
need_newline = FALSE;
}
srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
draw_srt_table_data(srt_table, i == data->srt_array->len-1);
if (srt_table->num_procs > 0) {
need_newline = TRUE;
}
}
}
static void
init_srt_tables(register_srt_t* srt, const char *filter)
{
srt_t *ui;
GString *error_string;
ui = g_new0(srt_t, 1);
ui->type = proto_get_protocol_short_name(find_protocol_by_id(get_srt_proto_id(srt)));
ui->filter = g_strdup(filter);
ui->data.srt_array = global_srt_array;
ui->data.user_data = ui;
error_string = register_tap_listener(get_srt_tap_listener_name(srt), &ui->data, filter, 0, NULL, get_srt_packet_func(srt), srt_draw);
if (error_string) {
free_srt_table(srt, global_srt_array, NULL, NULL);
g_free(ui);
fprintf(stderr, "tshark: Couldn't register srt tap: %s\n", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
static void
dissector_srt_init(const char *opt_arg, void* userdata)
{
register_srt_t *srt = (register_srt_t*)userdata;
const char *filter=NULL;
char* err;
srt_table_get_filter(srt, opt_arg, &filter, &err);
if (err != NULL)
{
gchar* cmd_str = srt_table_get_tap_string(srt);
fprintf(stderr, "tshark: invalid \"-z %s,%s\" argument\n", cmd_str, err);
g_free(cmd_str);
g_free(err);
exit(1);
}
global_srt_array = g_array_new(FALSE, TRUE, sizeof(srt_stat_table*));
srt_table_dissector_init(srt, global_srt_array, NULL, NULL);
init_srt_tables(srt, filter);
}
gboolean
register_srt_tables(const void *key _U_, void *value, void *userdata _U_)
{
register_srt_t *srt = (register_srt_t*)value;
const char* short_name = proto_get_protocol_short_name(find_protocol_by_id(get_srt_proto_id(srt)));
stat_tap_ui ui_info;
if (strcmp(short_name, "CAMEL") == 0)
return FALSE;
ui_info.group = REGISTER_STAT_GROUP_RESPONSE_TIME;
ui_info.title = NULL;
ui_info.cli_string = srt_table_get_tap_string(srt);
ui_info.tap_init_cb = dissector_srt_init;
ui_info.nparams = 0;
ui_info.params = NULL;
register_stat_tap_ui(&ui_info, srt);
g_free((char*)ui_info.cli_string);
return FALSE;
}
