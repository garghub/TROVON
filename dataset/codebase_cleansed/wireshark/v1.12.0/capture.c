static void
capture_callback_invoke(int event, capture_session *cap_session)
{
capture_callback_data_t *cb;
GList *cb_item = capture_callbacks;
g_assert(cb_item != NULL);
while(cb_item != NULL) {
cb = (capture_callback_data_t *)cb_item->data;
cb->cb_fct(event, cap_session, cb->user_data);
cb_item = g_list_next(cb_item);
}
}
void
capture_callback_add(capture_callback_t func, gpointer user_data)
{
capture_callback_data_t *cb;
cb = (capture_callback_data_t *)g_malloc(sizeof(capture_callback_data_t));
cb->cb_fct = func;
cb->user_data = user_data;
capture_callbacks = g_list_append(capture_callbacks, cb);
}
void
capture_callback_remove(capture_callback_t func)
{
capture_callback_data_t *cb;
GList *cb_item = capture_callbacks;
while(cb_item != NULL) {
cb = (capture_callback_data_t *)cb_item->data;
if(cb->cb_fct == func) {
capture_callbacks = g_list_remove(capture_callbacks, cb);
g_free(cb);
return;
}
cb_item = g_list_next(cb_item);
}
g_assert_not_reached();
}
void
capture_stop(capture_session *cap_session)
{
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Stop ...");
capture_callback_invoke(capture_cb_capture_stopping, cap_session);
sync_pipe_stop(cap_session);
}
void
capture_restart(capture_session *cap_session)
{
capture_options *capture_opts = cap_session->capture_opts;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Restart");
capture_opts->restart = TRUE;
capture_stop(cap_session);
}
void
capture_kill_child(capture_session *cap_session)
{
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_INFO, "Capture Kill");
sync_pipe_kill(cap_session->fork_child);
}
static gboolean
capture_input_read_all(capture_session *cap_session, gboolean is_tempfile,
gboolean drops_known, guint32 drops)
{
capture_options *capture_opts = cap_session->capture_opts;
int err;
if (cf_open((capture_file *)cap_session->cf, capture_opts->save_file, WTAP_TYPE_AUTO, is_tempfile, &err) != CF_OK) {
return FALSE;
}
cf_set_rfcode((capture_file *)cap_session->cf, NULL);
if (drops_known) {
cf_set_drops_known((capture_file *)cap_session->cf, TRUE);
cf_set_drops((capture_file *)cap_session->cf, drops);
}
switch (cf_read((capture_file *)cap_session->cf, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
main_window_nested_quit();
return FALSE;
}
if(cf_get_packet_count((capture_file *)cap_session->cf) == 0 && !capture_opts->restart) {
simple_dialog(ESD_TYPE_INFO, ESD_BTN_OK,
"%sNo packets captured!%s\n"
"\n"
"As no data was captured, closing the %scapture file!\n"
"\n"
"\n"
"Help about capturing can be found at:\n"
"\n"
" http://wiki.wireshark.org/CaptureSetup"
#ifdef _WIN32
"\n\n"
"Wireless (Wi-Fi/WLAN):\n"
"Try to switch off promiscuous mode in the Capture Options!"
#endif
"",
simple_dialog_primary_start(), simple_dialog_primary_end(),
(cf_is_tempfile((capture_file *)cap_session->cf)) ? "temporary " : "");
cf_close((capture_file *)cap_session->cf);
}
return TRUE;
}
gboolean
capture_input_new_file(capture_session *cap_session, gchar *new_file)
{
capture_options *capture_opts = cap_session->capture_opts;
gboolean is_tempfile;
int err;
if(cap_session->state == CAPTURE_PREPARING) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture started!");
}
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "File: \"%s\"", new_file);
g_assert(cap_session->state == CAPTURE_PREPARING || cap_session->state == CAPTURE_RUNNING);
if(capture_opts->save_file != NULL) {
if( ((capture_file *) cap_session->cf)->state != FILE_CLOSED) {
if(capture_opts->real_time_mode) {
capture_callback_invoke(capture_cb_capture_update_finished, cap_session);
cf_finish_tail((capture_file *)cap_session->cf, &err);
cf_close((capture_file *)cap_session->cf);
} else {
capture_callback_invoke(capture_cb_capture_fixed_finished, cap_session);
}
}
g_free(capture_opts->save_file);
is_tempfile = FALSE;
cf_set_tempfile((capture_file *)cap_session->cf, FALSE);
} else {
is_tempfile = TRUE;
cf_set_tempfile((capture_file *)cap_session->cf, TRUE);
}
capture_opts->save_file = g_strdup(new_file);
if(capture_opts->real_time_mode) {
switch(cf_open((capture_file *)cap_session->cf, capture_opts->save_file, WTAP_TYPE_AUTO, is_tempfile, &err)) {
case CF_OK:
break;
case CF_ERROR:
g_free(capture_opts->save_file);
capture_opts->save_file = NULL;
return FALSE;
}
} else {
capture_callback_invoke(capture_cb_capture_prepared, cap_session);
}
if(capture_opts->show_info) {
if (!capture_info_new_file(new_file))
return FALSE;
}
if(capture_opts->real_time_mode) {
capture_callback_invoke(capture_cb_capture_update_started, cap_session);
} else {
capture_callback_invoke(capture_cb_capture_fixed_started, cap_session);
}
cap_session->state = CAPTURE_RUNNING;
return TRUE;
}
void
capture_input_new_packets(capture_session *cap_session, int to_read)
{
capture_options *capture_opts = cap_session->capture_opts;
int err;
g_assert(capture_opts->save_file);
if(capture_opts->real_time_mode) {
switch (cf_continue_tail((capture_file *)cap_session->cf, to_read, &err)) {
case CF_READ_OK:
case CF_READ_ERROR:
capture_callback_invoke(capture_cb_capture_update_continue, cap_session);
break;
case CF_READ_ABORTED:
capture_kill_child(cap_session);
break;
}
} else {
cf_set_packet_count((capture_file *)cap_session->cf,
cf_get_packet_count((capture_file *)cap_session->cf) + to_read);
cf_fake_continue_tail((capture_file *)cap_session->cf);
capture_callback_invoke(capture_cb_capture_fixed_continue, cap_session);
}
#ifndef _WIN32
main_window_update();
#endif
if(capture_opts->show_info)
capture_info_new_packets(to_read);
}
void
capture_input_drops(capture_session *cap_session, guint32 dropped)
{
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_INFO, "%u packet%s dropped", dropped, plurality(dropped, "", "s"));
g_assert(cap_session->state == CAPTURE_RUNNING);
cf_set_drops_known((capture_file *)cap_session->cf, TRUE);
cf_set_drops((capture_file *)cap_session->cf, dropped);
}
void
capture_input_error_message(capture_session *cap_session, char *error_msg,
char *secondary_error_msg)
{
gchar *safe_error_msg;
gchar *safe_secondary_error_msg;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Error message from child: \"%s\", \"%s\"",
error_msg, secondary_error_msg);
g_assert(cap_session->state == CAPTURE_PREPARING || cap_session->state == CAPTURE_RUNNING);
safe_error_msg = simple_dialog_format_message(error_msg);
if (*secondary_error_msg != '\0') {
safe_secondary_error_msg = simple_dialog_format_message(secondary_error_msg);
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s%s%s\n\n%s",
simple_dialog_primary_start(), safe_error_msg,
simple_dialog_primary_end(), safe_secondary_error_msg);
g_free(safe_secondary_error_msg);
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s%s%s",
simple_dialog_primary_start(), safe_error_msg,
simple_dialog_primary_end());
}
g_free(safe_error_msg);
}
void
capture_input_cfilter_error_message(capture_session *cap_session, guint i,
char *error_message)
{
capture_options *capture_opts = cap_session->capture_opts;
dfilter_t *rfcode = NULL;
gchar *safe_cfilter;
gchar *safe_descr;
gchar *safe_cfilter_error_msg;
interface_options interface_opts;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture filter error message from child: \"%s\"", error_message);
g_assert(cap_session->state == CAPTURE_PREPARING || cap_session->state == CAPTURE_RUNNING);
g_assert(i < capture_opts->ifaces->len);
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
safe_cfilter = simple_dialog_format_message(interface_opts.cfilter);
safe_descr = simple_dialog_format_message(interface_opts.descr);
safe_cfilter_error_msg = simple_dialog_format_message(error_message);
if (dfilter_compile(interface_opts.cfilter, &rfcode) && rfcode != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sInvalid capture filter \"%s\" for interface %s!%s\n"
"\n"
"That string looks like a valid display filter; however, it isn't a valid\n"
"capture filter (%s).\n"
"\n"
"Note that display filters and capture filters don't have the same syntax,\n"
"so you can't use most display filter expressions as capture filters.\n"
"\n"
"See the User's Guide for a description of the capture filter syntax.",
simple_dialog_primary_start(), safe_cfilter, safe_descr,
simple_dialog_primary_end(), safe_cfilter_error_msg);
dfilter_free(rfcode);
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sInvalid capture filter \"%s\" for interface %s!%s\n"
"\n"
"That string isn't a valid capture filter (%s).\n"
"See the User's Guide for a description of the capture filter syntax.",
simple_dialog_primary_start(), safe_cfilter, safe_descr,
simple_dialog_primary_end(), safe_cfilter_error_msg);
}
g_free(safe_cfilter_error_msg);
g_free(safe_descr);
g_free(safe_cfilter);
}
void
capture_input_closed(capture_session *cap_session, gchar *msg)
{
capture_options *capture_opts = cap_session->capture_opts;
int err;
int packet_count_save;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture stopped!");
g_assert(cap_session->state == CAPTURE_PREPARING || cap_session->state == CAPTURE_RUNNING);
if (msg != NULL)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", msg);
if(cap_session->state == CAPTURE_PREPARING) {
capture_callback_invoke(capture_cb_capture_failed, cap_session);
} else {
if(capture_opts->real_time_mode) {
cf_read_status_t status;
status = cf_finish_tail((capture_file *)cap_session->cf, &err);
packet_count_save = cf_get_packet_count((capture_file *)cap_session->cf);
capture_callback_invoke(capture_cb_capture_update_finished, cap_session);
switch (status) {
case CF_READ_OK:
if ((packet_count_save == 0) && !capture_opts->restart) {
simple_dialog(ESD_TYPE_INFO, ESD_BTN_OK,
"%sNo packets captured!%s\n"
"\n"
"As no data was captured, closing the %scapture file!\n"
"\n"
"\n"
"Help about capturing can be found at:\n"
"\n"
" http://wiki.wireshark.org/CaptureSetup"
#ifdef _WIN32
"\n\n"
"Wireless (Wi-Fi/WLAN):\n"
"Try to switch off promiscuous mode in the Capture Options!"
#endif
"",
simple_dialog_primary_start(), simple_dialog_primary_end(),
cf_is_tempfile((capture_file *)cap_session->cf) ? "temporary " : "");
cf_close((capture_file *)cap_session->cf);
}
break;
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
main_window_quit();
break;
}
} else {
capture_callback_invoke(capture_cb_capture_fixed_finished, cap_session);
if(capture_opts->save_file != NULL) {
capture_input_read_all(cap_session, cf_is_tempfile((capture_file *)cap_session->cf),
cf_get_drops_known((capture_file *)cap_session->cf), cf_get_drops((capture_file *)cap_session->cf));
}
}
}
if(capture_opts->show_info)
capture_info_close();
cap_session->state = CAPTURE_STOPPED;
if(capture_opts->save_file == NULL) {
cf_close((capture_file *)cap_session->cf);
return;
}
if(capture_opts->restart) {
capture_opts->restart = FALSE;
ws_unlink(capture_opts->save_file);
if ((capture_opts->multi_files_on) && (capture_opts->orig_save_file != NULL)) {
g_free(capture_opts->save_file);
capture_opts->save_file = g_strdup(capture_opts->orig_save_file);
}
if(cf_is_tempfile((capture_file *)cap_session->cf)) {
g_free(capture_opts->save_file);
capture_opts->save_file = NULL;
}
if (capture_opts->ifaces->len == 0) {
collect_ifaces(capture_opts);
}
cf_close((capture_file *)cap_session->cf);
capture_start(capture_opts, cap_session,NULL);
} else {
g_free(capture_opts->save_file);
capture_opts->save_file = NULL;
}
}
if_stat_cache_t *
capture_stat_start(capture_options *capture_opts) {
int stat_fd, fork_child;
gchar *msg;
if_stat_cache_t *sc = NULL;
if_stat_cache_item_t *sc_item;
guint i;
interface_t device;
if (sync_interface_stats_open(&stat_fd, &fork_child, &msg, NULL) == 0) {
sc = (if_stat_cache_t *)g_malloc(sizeof(if_stat_cache_t));
sc->stat_fd = stat_fd;
sc->fork_child = fork_child;
sc->cache_list = NULL;
for (i = 0; i < capture_opts->all_ifaces->len; i++) {
device = g_array_index(capture_opts->all_ifaces, interface_t, i);
if (device.type != IF_PIPE && &(device.if_info)) {
sc_item = (if_stat_cache_item_t *)g_malloc0(sizeof(if_stat_cache_item_t));
sc_item->name = g_strdup(device.if_info.name);
sc->cache_list = g_list_append(sc->cache_list, sc_item);
}
}
}
return sc;
}
static void
capture_stat_cache_update(if_stat_cache_t *sc) {
gchar stat_line[MAX_STAT_LINE_LEN] = "";
gchar **stat_parts;
GList *sc_entry;
if_stat_cache_item_t *sc_item;
if (!sc)
return;
while (sync_pipe_gets_nonblock(sc->stat_fd, stat_line, MAX_STAT_LINE_LEN) > 0) {
g_strstrip(stat_line);
stat_parts = g_strsplit(stat_line, "\t", 3);
if (stat_parts[0] == NULL || stat_parts[1] == NULL ||
stat_parts[2] == NULL) {
g_strfreev(stat_parts);
continue;
}
for (sc_entry = sc->cache_list; sc_entry != NULL; sc_entry = g_list_next(sc_entry)) {
sc_item = (if_stat_cache_item_t *)sc_entry->data;
if (strcmp(sc_item->name, stat_parts[0]) == 0) {
sc_item->ps.ps_recv = (u_int) strtoul(stat_parts[1], NULL, 10);
sc_item->ps.ps_drop = (u_int) strtoul(stat_parts[2], NULL, 10);
}
}
g_strfreev(stat_parts);
}
}
gboolean
capture_stats(if_stat_cache_t *sc, char *ifname, struct pcap_stat *ps) {
GList *sc_entry;
if_stat_cache_item_t *sc_item;
if (!sc || !ifname || !ps) {
return FALSE;
}
capture_stat_cache_update(sc);
for (sc_entry = sc->cache_list; sc_entry != NULL; sc_entry = g_list_next(sc_entry)) {
sc_item = (if_stat_cache_item_t *)sc_entry->data;
if (strcmp(sc_item->name, ifname) == 0) {
memcpy(ps, &sc_item->ps, sizeof(struct pcap_stat));
return TRUE;
}
}
return FALSE;
}
void
capture_stat_stop(if_stat_cache_t *sc) {
GList *sc_entry;
if_stat_cache_item_t *sc_item;
int ret;
gchar *msg;
if (!sc)
return;
ret = sync_interface_stats_close(&sc->stat_fd, &sc->fork_child, &msg);
if (ret == -1) {
g_free(msg);
}
for (sc_entry = sc->cache_list; sc_entry != NULL; sc_entry = g_list_next(sc_entry)) {
sc_item = (if_stat_cache_item_t *)sc_entry->data;
g_free(sc_item->name);
g_free(sc_item);
}
g_free(sc);
}
