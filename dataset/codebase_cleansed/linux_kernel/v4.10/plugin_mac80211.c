static void print_string(struct trace_seq *s, struct event_format *event,
const char *name, const void *data)
{
struct format_field *f = pevent_find_field(event, name);
int offset;
int length;
if (!f) {
trace_seq_printf(s, "NOTFOUND:%s", name);
return;
}
offset = f->offset;
length = f->size;
if (!strncmp(f->type, "__data_loc", 10)) {
unsigned long long v;
if (pevent_read_number_field(f, data, &v)) {
trace_seq_printf(s, "invalid_data_loc");
return;
}
offset = v & 0xffff;
length = v >> 16;
}
trace_seq_printf(s, "%.*s", length, (char *)data + offset);
}
static int drv_bss_info_changed(struct trace_seq *s,
struct pevent_record *record,
struct event_format *event, void *context)
{
void *data = record->data;
print_string(s, event, "wiphy_name", data);
trace_seq_printf(s, " vif:");
print_string(s, event, "vif_name", data);
pevent_print_num_field(s, "(%d)", event, "vif_type", record, 1);
trace_seq_printf(s, "\n%*s", INDENT, "");
SF("assoc"); SP();
SF("aid"); SP();
SF("cts"); SP();
SF("shortpre"); SP();
SF("shortslot"); SP();
SF("dtimper"); SP();
trace_seq_printf(s, "\n%*s", INDENT, "");
SF("bcnint"); SP();
SFX("assoc_cap"); SP();
SFX("basic_rates"); SP();
SF("enable_beacon");
trace_seq_printf(s, "\n%*s", INDENT, "");
SF("ht_operation_mode");
return 0;
}
int PEVENT_PLUGIN_LOADER(struct pevent *pevent)
{
pevent_register_event_handler(pevent, -1, "mac80211",
"drv_bss_info_changed",
drv_bss_info_changed, NULL);
return 0;
}
void PEVENT_PLUGIN_UNLOADER(struct pevent *pevent)
{
pevent_unregister_event_handler(pevent, -1, "mac80211",
"drv_bss_info_changed",
drv_bss_info_changed, NULL);
}
