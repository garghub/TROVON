static void
expert_stat_reset(void *tapdata)
{
gint n;
expert_tapdata_t *etd = (expert_tapdata_t *)tapdata;
g_string_chunk_free(etd->text);
etd->text = g_string_chunk_new(100);
for (n=0; n < max_level; n++) {
g_array_set_size(etd->ei_array[n], 0);
}
}
static gboolean
expert_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_,
const void *pointer)
{
const expert_info_t *ei = (const expert_info_t *)pointer;
expert_tapdata_t *data = (expert_tapdata_t *)tapdata;
severity_level_t severity_level;
expert_entry tmp_entry;
expert_entry *entry;
guint n;
switch (ei->severity) {
case PI_CHAT:
severity_level = chat_level;
break;
case PI_NOTE:
severity_level = note_level;
break;
case PI_WARN:
severity_level = warn_level;
break;
case PI_ERROR:
severity_level = error_level;
break;
default:
g_assert_not_reached();
return FALSE;
}
if (severity_level < lowest_report_level) {
return TRUE;
}
for (n=0; n < data->ei_array[severity_level]->len; n++) {
entry = &g_array_index(data->ei_array[severity_level], expert_entry, n);
if ((strcmp(ei->protocol, entry->protocol) == 0) &&
(strcmp(ei->summary, entry->summary) == 0)) {
entry->frequency++;
return TRUE;
}
}
entry = &tmp_entry;
entry->protocol = g_string_chunk_insert_const(data->text, ei->protocol);
entry->summary = g_string_chunk_insert_const(data->text, ei->summary);
entry->group = ei->group;
entry->frequency = 1;
g_array_append_val(data->ei_array[severity_level], tmp_entry);
return TRUE;
}
static void draw_items_for_severity(GArray *items, const gchar *label)
{
guint n;
expert_entry *ei;
int total = 0;
gchar *tmp_str;
if (items->len == 0) {
return;
}
for (n=0; n < items->len; n++) {
ei = &g_array_index(items, expert_entry, n);
total += ei->frequency;
}
printf("\n%s (%d)\n", label, total);
printf("=============\n");
printf(" Frequency Group Protocol Summary\n");
for (n=0; n < items->len; n++) {
ei = &g_array_index(items, expert_entry, n);
tmp_str = val_to_str_wmem(NULL, ei->group, expert_group_vals, "Unknown (%d)");
printf("%12d %10s %18s %s\n",
ei->frequency,
tmp_str,
ei->protocol, ei->summary);
wmem_free(NULL, tmp_str);
}
}
static void
expert_stat_draw(void *phs _U_)
{
expert_tapdata_t *hs = (expert_tapdata_t *)phs;
draw_items_for_severity(hs->ei_array[error_level], "Errors");
draw_items_for_severity(hs->ei_array[warn_level], "Warns");
draw_items_for_severity(hs->ei_array[note_level], "Notes");
draw_items_for_severity(hs->ei_array[chat_level], "Chats");
}
static void expert_stat_init(const char *opt_arg, void *userdata _U_)
{
const char *args = NULL;
const char *filter = NULL;
GString *error_string;
expert_tapdata_t *hs;
int n;
if (strncmp(opt_arg, "expert", 6) == 0) {
args = opt_arg + 6;
}
else {
lowest_report_level = max_level;
}
if (args != NULL) {
if (g_ascii_strncasecmp(args, ",error", 6) == 0) {
lowest_report_level = error_level;
args += 6;
}
else if (g_ascii_strncasecmp(args, ",warn", 5) == 0) {
lowest_report_level = warn_level;
args += 5;
} else if (g_ascii_strncasecmp(args, ",note", 5) == 0) {
lowest_report_level = note_level;
args += 5;
} else if (g_ascii_strncasecmp(args, ",chat", 5) == 0) {
lowest_report_level = chat_level;
args += 5;
}
}
if (args != NULL) {
if (args[0] == ',') {
filter = args+1;
}
}
hs = g_new0(expert_tapdata_t, 1);
hs->text = g_string_chunk_new(100);
for (n=0; n < max_level; n++) {
hs->ei_array[n] = g_array_sized_new(FALSE, FALSE, sizeof(expert_entry), 1000);
}
error_string = register_tap_listener("expert", hs,
filter, 0,
expert_stat_reset,
expert_stat_packet,
expert_stat_draw);
if (error_string) {
printf("Expert tap error (%s)!\n", error_string->str);
g_string_free(error_string, TRUE);
g_free(hs);
exit(1);
}
}
void
register_tap_listener_expert_info(void)
{
register_stat_tap_ui(&expert_stat_ui, NULL);
}
