static void
cf_callback_invoke(int event, gpointer data)
{
cf_callback_data_t *cb;
GList *cb_item = cf_callbacks;
g_assert(cb_item != NULL);
while (cb_item != NULL) {
cb = (cf_callback_data_t *)cb_item->data;
cb->cb_fct(event, data, cb->user_data);
cb_item = g_list_next(cb_item);
}
}
void
cf_callback_add(cf_callback_t func, gpointer user_data)
{
cf_callback_data_t *cb;
cb = g_new(cf_callback_data_t,1);
cb->cb_fct = func;
cb->user_data = user_data;
cf_callbacks = g_list_prepend(cf_callbacks, cb);
}
void
cf_callback_remove(cf_callback_t func, gpointer user_data)
{
cf_callback_data_t *cb;
GList *cb_item = cf_callbacks;
while (cb_item != NULL) {
cb = (cf_callback_data_t *)cb_item->data;
if (cb->cb_fct == func && cb->user_data == user_data) {
cf_callbacks = g_list_remove(cf_callbacks, cb);
g_free(cb);
return;
}
cb_item = g_list_next(cb_item);
}
g_assert_not_reached();
}
void
cf_timestamp_auto_precision(capture_file *cf)
{
int i;
if (cf->state == FILE_CLOSED) {
return;
}
for (i = 0; i < cf->cinfo.num_cols; i++) {
if (col_has_time_fmt(&cf->cinfo, i)) {
packet_list_resize_column(i);
}
}
}
gulong
cf_get_computed_elapsed(capture_file *cf)
{
return cf->computed_elapsed;
}
static void compute_elapsed(capture_file *cf, GTimeVal *start_time)
{
gdouble delta_time;
GTimeVal time_now;
g_get_current_time(&time_now);
delta_time = (time_now.tv_sec - start_time->tv_sec) * 1e6 +
time_now.tv_usec - start_time->tv_usec;
cf->computed_elapsed = (gulong) (delta_time / 1000);
}
static const nstime_t *
ws_get_frame_ts(void *data, guint32 frame_num)
{
capture_file *cf = (capture_file *) data;
if (cf->prev_dis && cf->prev_dis->num == frame_num)
return &cf->prev_dis->abs_ts;
if (cf->prev_cap && cf->prev_cap->num == frame_num)
return &cf->prev_cap->abs_ts;
if (cf->frames) {
frame_data *fd = frame_data_sequence_find(cf->frames, frame_num);
return (fd) ? &fd->abs_ts : NULL;
}
return NULL;
}
static const char *
ws_get_user_comment(void *data, const frame_data *fd)
{
capture_file *cf = (capture_file *) data;
return cf_get_user_packet_comment(cf, fd);
}
static epan_t *
ws_epan_new(capture_file *cf)
{
epan_t *epan = epan_new();
epan->data = cf;
epan->get_frame_ts = ws_get_frame_ts;
epan->get_interface_name = cap_file_get_interface_name;
epan->get_user_comment = ws_get_user_comment;
return epan;
}
cf_status_t
cf_open(capture_file *cf, const char *fname, unsigned int type, gboolean is_tempfile, int *err)
{
wtap *wth;
gchar *err_info;
wth = wtap_open_offline(fname, type, err, &err_info, TRUE);
if (wth == NULL)
goto fail;
cf_close(cf);
wtap_phdr_init(&cf->phdr);
ws_buffer_init(&cf->buf, 1500);
cf->epan = ws_epan_new(cf);
cf->state = FILE_READ_IN_PROGRESS;
cf->wth = wth;
cf->f_datalen = 0;
cf->filename = g_strdup(fname);
cf->is_tempfile = is_tempfile;
cf->unsaved_changes = FALSE;
cf->computed_elapsed = 0;
cf->cd_t = wtap_file_type_subtype(cf->wth);
cf->open_type = type;
cf->linktypes = g_array_sized_new(FALSE, FALSE, (guint) sizeof(int), 1);
cf->count = 0;
cf->packet_comment_count = 0;
cf->displayed_count = 0;
cf->marked_count = 0;
cf->ignored_count = 0;
cf->ref_time_count = 0;
cf->drops_known = FALSE;
cf->drops = 0;
cf->snap = wtap_snapshot_length(cf->wth);
if (cf->snap == 0) {
cf->has_snap = FALSE;
cf->snap = WTAP_MAX_PACKET_SIZE;
} else
cf->has_snap = TRUE;
cf->frames = new_frame_data_sequence();
nstime_set_zero(&cf->elapsed_time);
cf->ref = NULL;
cf->prev_dis = NULL;
cf->prev_cap = NULL;
cf->cum_bytes = 0;
cf_timestamp_auto_precision(cf);
packet_list_queue_draw();
cf_callback_invoke(cf_cb_file_opened, cf);
if (cf->cd_t == WTAP_FILE_TYPE_SUBTYPE_BER) {
ber_set_filename(cf->filename);
}
wtap_set_cb_new_ipv4(cf->wth, add_ipv4_name);
wtap_set_cb_new_ipv6(cf->wth, (wtap_new_ipv6_callback_t) add_ipv6_name);
return CF_OK;
fail:
cf_open_failure_alert_box(fname, *err, err_info, FALSE, 0);
return CF_ERROR;
}
static void
cf_add_encapsulation_type(capture_file *cf, int encap)
{
guint i;
for (i = 0; i < cf->linktypes->len; i++) {
if (g_array_index(cf->linktypes, gint, i) == encap)
return;
}
g_array_append_val(cf->linktypes, encap);
}
void
cf_close(capture_file *cf)
{
cf->stop_flag = FALSE;
if (cf->state == FILE_CLOSED)
return;
g_assert(cf->state != FILE_READ_IN_PROGRESS);
cf_callback_invoke(cf_cb_file_closing, cf);
color_filters_cleanup();
if (cf->wth) {
wtap_close(cf->wth);
cf->wth = NULL;
}
if (cf->filename != NULL) {
if (cf->is_tempfile)
ws_unlink(cf->filename);
g_free(cf->filename);
cf->filename = NULL;
}
cf->unsaved_changes = FALSE;
cf->open_type = WTAP_TYPE_AUTO;
wtap_phdr_cleanup(&cf->phdr);
ws_buffer_free(&cf->buf);
dfilter_free(cf->rfcode);
cf->rfcode = NULL;
if (cf->frames != NULL) {
free_frame_data_sequence(cf->frames);
cf->frames = NULL;
}
#ifdef WANT_PACKET_EDITOR
if (cf->edited_frames) {
g_tree_destroy(cf->edited_frames);
cf->edited_frames = NULL;
}
#endif
if (cf->frames_user_comments) {
g_tree_destroy(cf->frames_user_comments);
cf->frames_user_comments = NULL;
}
cf_unselect_packet(cf);
cf->first_displayed = 0;
cf->last_displayed = 0;
cf->count = 0;
cf->current_frame = 0;
cf->current_row = 0;
cf->finfo_selected = NULL;
if (cf->linktypes != NULL) {
g_array_free(cf->linktypes, TRUE);
cf->linktypes = NULL;
}
packet_list_freeze();
packet_list_clear();
packet_list_thaw();
cf->f_datalen = 0;
nstime_set_zero(&cf->elapsed_time);
reset_tap_listeners();
epan_free(cf->epan);
cf->epan = NULL;
cf->state = FILE_CLOSED;
cf_callback_invoke(cf_cb_file_closed, cf);
}
static float
calc_progbar_val(capture_file *cf, gint64 size, gint64 file_pos, gchar *status_str, gulong status_size)
{
float progbar_val;
progbar_val = (gfloat) file_pos / (gfloat) size;
if (progbar_val > 1.0) {
size = wtap_file_size(cf->wth, NULL);
if (size >= 0)
progbar_val = (gfloat) file_pos / (gfloat) size;
if (progbar_val > 1.0f)
progbar_val = 1.0f;
}
g_snprintf(status_str, status_size,
"%" G_GINT64_MODIFIER "dKB of %" G_GINT64_MODIFIER "dKB",
file_pos / 1024, size / 1024);
return progbar_val;
}
cf_read_status_t
cf_read(capture_file *cf, gboolean reloading)
{
int err;
gchar *err_info;
gchar *name_ptr;
progdlg_t *progbar = NULL;
GTimeVal start_time;
epan_dissect_t edt;
dfilter_t *dfcode;
volatile gboolean create_proto_tree;
guint tap_flags;
gboolean compiled;
compiled = dfilter_compile(cf->dfilter, &dfcode, NULL);
g_assert(!cf->dfilter || (compiled && dfcode));
tap_flags = union_of_tap_listener_flags();
create_proto_tree =
(dfcode != NULL || have_filtering_tap_listeners() || (tap_flags & TL_REQUIRES_PROTO_TREE));
reset_tap_listeners();
name_ptr = g_filename_display_basename(cf->filename);
if (reloading)
cf_callback_invoke(cf_cb_file_reload_started, cf);
else
cf_callback_invoke(cf_cb_file_read_started, cf);
cf->iscompressed = wtap_iscompressed(cf->wth);
packet_list_freeze();
cf->stop_flag = FALSE;
g_get_current_time(&start_time);
epan_dissect_init(&edt, cf->epan, create_proto_tree, FALSE);
TRY {
#ifdef HAVE_LIBPCAP
int displayed_once = 0;
#endif
int count = 0;
gint64 size;
gint64 file_pos;
gint64 data_offset;
gint64 progbar_quantum;
gint64 progbar_nextstep;
float progbar_val;
gchar status_str[100];
column_info *cinfo;
cinfo = (tap_flags & TL_REQUIRES_COLUMNS) ? &cf->cinfo : NULL;
size = wtap_file_size(cf->wth, NULL);
progbar_nextstep = 0;
if (size >= 0) {
progbar_quantum = size/N_PROGBAR_UPDATES;
if (progbar_quantum < MIN_QUANTUM)
progbar_quantum = MIN_QUANTUM;
}else
progbar_quantum = 0;
while ((wtap_read(cf->wth, &err, &err_info, &data_offset))) {
if (size >= 0) {
count++;
file_pos = wtap_read_so_far(cf->wth);
if ((progbar == NULL) && !(count % MIN_NUMBER_OF_PACKET)) {
progbar_val = calc_progbar_val(cf, size, file_pos, status_str, sizeof(status_str));
if (reloading)
progbar = delayed_create_progress_dlg(cf->window, "Reloading", name_ptr,
TRUE, &cf->stop_flag, &start_time, progbar_val);
else
progbar = delayed_create_progress_dlg(cf->window, "Loading", name_ptr,
TRUE, &cf->stop_flag, &start_time, progbar_val);
}
if (file_pos >= progbar_nextstep) {
if (progbar != NULL) {
progbar_val = calc_progbar_val(cf, size, file_pos, status_str, sizeof(status_str));
#ifdef HAVE_LIBPCAP
if (progbar_quantum > 500000 || displayed_once == 0) {
if ((auto_scroll_live || displayed_once == 0 || cf->displayed_count < 1000) && cf->count != 0) {
displayed_once = 1;
packets_bar_update();
}
}
#endif
update_progress_dlg(progbar, progbar_val, status_str);
}
progbar_nextstep += progbar_quantum;
}
}
if (cf->stop_flag) {
break;
}
read_packet(cf, dfcode, &edt, cinfo, data_offset);
}
}
CATCH(OutOfMemoryError) {
simple_message_box(ESD_TYPE_ERROR, NULL,
"More information and workarounds can be found at\n"
"https://wiki.wireshark.org/KnownBugs/OutOfMemory",
"Sorry, but Wireshark has run out of memory and has to terminate now.");
#if 0
#else
exit(1);
#endif
}
ENDTRY;
g_free(name_ptr);
if (dfcode != NULL) {
dfilter_free(dfcode);
}
epan_dissect_cleanup(&edt);
if (progbar != NULL)
destroy_progress_dlg(progbar);
cf->state = FILE_READ_DONE;
wtap_sequential_close(cf->wth);
postseq_cleanup_all_protocols();
compute_elapsed(cf, &start_time);
cf->lnk_t = wtap_file_encap(cf->wth);
cf->current_frame = frame_data_sequence_find(cf->frames, cf->first_displayed);
cf->current_row = 0;
packet_list_thaw();
if (reloading)
cf_callback_invoke(cf_cb_file_reload_finished, cf);
else
cf_callback_invoke(cf_cb_file_read_finished, cf);
if (cf->first_displayed != 0) {
packet_list_select_first_row();
}
if (cf->stop_flag) {
simple_message_box(ESD_TYPE_WARN, NULL,
"The remaining packets in the file were discarded.\n"
"\n"
"As a lot of packets from the original file will be missing,\n"
"remember to be careful when saving the current content to a file.\n",
"File loading was cancelled.");
return CF_READ_ERROR;
}
if (err != 0) {
switch (err) {
case WTAP_ERR_UNSUPPORTED:
simple_error_message_box(
"The capture file contains record data that Wireshark doesn't support.\n(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_SHORT_READ:
simple_error_message_box(
"The capture file appears to have been cut short"
" in the middle of a packet.");
break;
case WTAP_ERR_BAD_FILE:
simple_error_message_box(
"The capture file appears to be damaged or corrupt.\n(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_DECOMPRESS:
simple_error_message_box(
"The compressed capture file appears to be damaged or corrupt.\n(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
simple_error_message_box(
"An error occurred while reading the"
" capture file: %s.", wtap_strerror(err));
break;
}
return CF_READ_ERROR;
} else
return CF_READ_OK;
}
cf_read_status_t
cf_continue_tail(capture_file *cf, volatile int to_read, int *err)
{
gchar *err_info;
volatile int newly_displayed_packets = 0;
dfilter_t *dfcode;
epan_dissect_t edt;
gboolean create_proto_tree;
guint tap_flags;
gboolean compiled;
compiled = dfilter_compile(cf->dfilter, &dfcode, NULL);
g_assert(!cf->dfilter || (compiled && dfcode));
tap_flags = union_of_tap_listener_flags();
create_proto_tree =
(dfcode != NULL || have_filtering_tap_listeners() || (tap_flags & TL_REQUIRES_PROTO_TREE));
*err = 0;
packet_list_check_end();
epan_dissect_init(&edt, cf->epan, create_proto_tree, FALSE);
TRY {
gint64 data_offset = 0;
column_info *cinfo;
cinfo = (tap_flags & TL_REQUIRES_COLUMNS) ? &cf->cinfo : NULL;
while (to_read != 0) {
wtap_cleareof(cf->wth);
if (!wtap_read(cf->wth, err, &err_info, &data_offset)) {
break;
}
if (cf->state == FILE_READ_ABORTED) {
break;
}
if (read_packet(cf, dfcode, &edt, (column_info *) cinfo, data_offset) != -1) {
newly_displayed_packets++;
}
to_read--;
}
}
CATCH(OutOfMemoryError) {
simple_message_box(ESD_TYPE_ERROR, NULL,
"More information and workarounds can be found at\n"
"https://wiki.wireshark.org/KnownBugs/OutOfMemory",
"Sorry, but Wireshark has run out of memory and has to terminate now.");
#if 0
return CF_READ_ABORTED;
#else
exit(1);
#endif
}
ENDTRY;
cf->lnk_t = wtap_file_encap(cf->wth);
if (dfcode != NULL) {
dfilter_free(dfcode);
}
epan_dissect_cleanup(&edt);
if (!cf->current_frame)
packet_list_select_first_row();
if (newly_displayed_packets && auto_scroll_live && cf->count != 0)
packet_list_moveto_end();
if (cf->state == FILE_READ_ABORTED) {
return CF_READ_ABORTED;
} else if (*err != 0) {
if (err_info != NULL) {
g_warning("Error \"%s\" while reading \"%s\" (\"%s\")",
wtap_strerror(*err), cf->filename, err_info);
g_free(err_info);
} else {
g_warning("Error \"%s\" while reading \"%s\"",
wtap_strerror(*err), cf->filename);
}
return CF_READ_ERROR;
} else
return CF_READ_OK;
}
void
cf_fake_continue_tail(capture_file *cf) {
cf->state = FILE_READ_DONE;
}
cf_read_status_t
cf_finish_tail(capture_file *cf, int *err)
{
gchar *err_info;
gint64 data_offset;
dfilter_t *dfcode;
column_info *cinfo;
epan_dissect_t edt;
gboolean create_proto_tree;
guint tap_flags;
gboolean compiled;
compiled = dfilter_compile(cf->dfilter, &dfcode, NULL);
g_assert(!cf->dfilter || (compiled && dfcode));
tap_flags = union_of_tap_listener_flags();
cinfo = (tap_flags & TL_REQUIRES_COLUMNS) ? &cf->cinfo : NULL;
create_proto_tree =
(dfcode != NULL || have_filtering_tap_listeners() || (tap_flags & TL_REQUIRES_PROTO_TREE));
if (cf->wth == NULL) {
cf_close(cf);
return CF_READ_ERROR;
}
packet_list_check_end();
epan_dissect_init(&edt, cf->epan, create_proto_tree, FALSE);
while ((wtap_read(cf->wth, err, &err_info, &data_offset))) {
if (cf->state == FILE_READ_ABORTED) {
break;
}
read_packet(cf, dfcode, &edt, cinfo, data_offset);
}
if (dfcode != NULL) {
dfilter_free(dfcode);
}
epan_dissect_cleanup(&edt);
if (cf->state == FILE_READ_ABORTED) {
cf_close(cf);
return CF_READ_ABORTED;
}
if (auto_scroll_live && cf->count != 0)
packet_list_moveto_end();
cf->state = FILE_READ_DONE;
wtap_sequential_close(cf->wth);
postseq_cleanup_all_protocols();
cf->lnk_t = wtap_file_encap(cf->wth);
fileset_update_file(cf->filename);
if (*err != 0) {
if (err_info != NULL) {
g_warning("Error \"%s\" while reading \"%s\" (\"%s\")",
wtap_strerror(*err), cf->filename, err_info);
g_free(err_info);
} else {
g_warning("Error \"%s\" while reading \"%s\"",
wtap_strerror(*err), cf->filename);
}
return CF_READ_ERROR;
} else {
return CF_READ_OK;
}
}
gchar *
cf_get_display_name(capture_file *cf)
{
gchar *displayname;
if (!cf->is_tempfile) {
if (cf->filename) {
displayname = g_filename_display_basename(cf->filename);
} else {
displayname=g_strdup("(No file)");
}
} else {
if (cf->source) {
displayname = g_strdup(cf->source);
} else {
displayname = g_strdup("(Untitled)");
}
}
return displayname;
}
void cf_set_tempfile_source(capture_file *cf, gchar *source) {
if (cf->source) {
g_free(cf->source);
}
if (source) {
cf->source = g_strdup(source);
} else {
cf->source = g_strdup("");
}
}
const gchar *cf_get_tempfile_source(capture_file *cf) {
if (!cf->source) {
return "";
}
return cf->source;
}
int
cf_get_packet_count(capture_file *cf)
{
return cf->count;
}
gboolean
cf_is_tempfile(capture_file *cf)
{
return cf->is_tempfile;
}
void cf_set_tempfile(capture_file *cf, gboolean is_tempfile)
{
cf->is_tempfile = is_tempfile;
}
void cf_set_drops_known(capture_file *cf, gboolean drops_known)
{
cf->drops_known = drops_known;
}
void cf_set_drops(capture_file *cf, guint32 drops)
{
cf->drops = drops;
}
gboolean cf_get_drops_known(capture_file *cf)
{
return cf->drops_known;
}
guint32 cf_get_drops(capture_file *cf)
{
return cf->drops;
}
void cf_set_rfcode(capture_file *cf, dfilter_t *rfcode)
{
cf->rfcode = rfcode;
}
static int
add_packet_to_packet_list(frame_data *fdata, capture_file *cf,
epan_dissect_t *edt, dfilter_t *dfcode, column_info *cinfo,
struct wtap_pkthdr *phdr, const guint8 *buf, gboolean add_to_packet_list)
{
gint row = -1;
frame_data_set_before_dissect(fdata, &cf->elapsed_time,
&cf->ref, cf->prev_dis);
cf->prev_cap = fdata;
if (dfcode != NULL) {
epan_dissect_prime_dfilter(edt, dfcode);
}
epan_dissect_run_with_taps(edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, buf), fdata, cinfo);
if (dfcode != NULL) {
fdata->flags.passed_dfilter = dfilter_apply_edt(dfcode, edt) ? 1 : 0;
if (fdata->flags.passed_dfilter) {
g_slist_foreach(edt->pi.dependent_frames, find_and_mark_frame_depended_upon, cf->frames);
}
} else
fdata->flags.passed_dfilter = 1;
if (fdata->flags.passed_dfilter || fdata->flags.ref_time)
cf->displayed_count++;
if (add_to_packet_list) {
row = packet_list_append(cinfo, fdata);
}
if (fdata->flags.passed_dfilter || fdata->flags.ref_time)
{
frame_data_set_after_dissect(fdata, &cf->cum_bytes);
cf->prev_dis = fdata;
if (cf->first_displayed == 0)
cf->first_displayed = fdata->num;
cf->last_displayed = fdata->num;
}
epan_dissect_reset(edt);
return row;
}
static int
read_packet(capture_file *cf, dfilter_t *dfcode, epan_dissect_t *edt,
column_info *cinfo, gint64 offset)
{
struct wtap_pkthdr *phdr = wtap_phdr(cf->wth);
const guint8 *buf = wtap_buf_ptr(cf->wth);
frame_data fdlocal;
guint32 framenum;
frame_data *fdata;
gboolean passed;
int row = -1;
cf_add_encapsulation_type(cf, phdr->pkt_encap);
framenum = cf->count + 1;
frame_data_init(&fdlocal, framenum, phdr, offset, cf->cum_bytes);
passed = TRUE;
if (cf->rfcode) {
epan_dissect_t rf_edt;
epan_dissect_init(&rf_edt, cf->epan, TRUE, FALSE);
epan_dissect_prime_dfilter(&rf_edt, cf->rfcode);
epan_dissect_run(&rf_edt, cf->cd_t, phdr, frame_tvbuff_new(&fdlocal, buf), &fdlocal, NULL);
passed = dfilter_apply_edt(cf->rfcode, &rf_edt);
epan_dissect_cleanup(&rf_edt);
}
if (passed) {
fdata = frame_data_sequence_add(cf->frames, &fdlocal);
cf->count++;
if (phdr->opt_comment != NULL)
cf->packet_comment_count++;
cf->f_datalen = offset + fdlocal.cap_len;
if (!cf->redissecting) {
row = add_packet_to_packet_list(fdata, cf, edt, dfcode,
cinfo, phdr, buf, TRUE);
}
}
return row;
}
static gboolean
merge_callback(merge_event event, int num _U_,
const merge_in_file_t in_files[], const guint in_file_count,
void *data)
{
guint i;
callback_data_t *cb_data = (callback_data_t*) data;
g_assert(cb_data != NULL);
switch (event) {
case MERGE_EVENT_INPUT_FILES_OPENED:
break;
case MERGE_EVENT_FRAME_TYPE_SELECTED:
break;
case MERGE_EVENT_READY_TO_MERGE:
for (i = 0; i < in_file_count; i++)
cb_data->f_len += in_files[i].size;
cb_data->progbar_quantum = cb_data->f_len / N_PROGBAR_UPDATES;
g_get_current_time(&cb_data->start_time);
break;
case MERGE_EVENT_PACKET_WAS_READ:
{
gint64 data_offset = 0;
data_offset = 0;
for (i = 0; i < in_file_count; i++)
data_offset += in_files[i].data_offset;
if (cb_data->progbar == NULL) {
cb_data->progbar = delayed_create_progress_dlg(NULL, "Merging", "files",
FALSE, &cb_data->stop_flag, &cb_data->start_time, 0.0f);
}
if (data_offset >= cb_data->progbar_nextstep) {
float progbar_val;
gint64 file_pos = 0;
for (i = 0; i < in_file_count; i++)
file_pos += wtap_read_so_far(in_files[i].wth);
progbar_val = (gfloat) file_pos / (gfloat) cb_data->f_len;
if (progbar_val > 1.0f) {
progbar_val = 1.0f;
}
if (cb_data->progbar != NULL) {
gchar status_str[100];
g_snprintf(status_str, sizeof(status_str),
"%" G_GINT64_MODIFIER "dKB of %" G_GINT64_MODIFIER "dKB",
file_pos / 1024, cb_data->f_len / 1024);
update_progress_dlg(cb_data->progbar, progbar_val, status_str);
}
cb_data->progbar_nextstep += cb_data->progbar_quantum;
}
}
break;
case MERGE_EVENT_DONE:
if (cb_data->progbar != NULL)
destroy_progress_dlg(cb_data->progbar);
break;
}
return cb_data->stop_flag;
}
cf_status_t
cf_merge_files(char **out_filenamep, int in_file_count,
char *const *in_filenames, int file_type, gboolean do_append)
{
char *out_filename;
char *tmpname;
int out_fd;
int err = 0;
gchar *err_info = NULL;
int err_fileno;
merge_result status;
merge_progress_callback_t cb;
if (*out_filenamep != NULL) {
out_filename = *out_filenamep;
out_fd = ws_open(out_filename, O_CREAT|O_TRUNC|O_BINARY, 0600);
if (out_fd == -1)
err = errno;
} else {
out_fd = create_tempfile(&tmpname, "wireshark");
if (out_fd == -1)
err = errno;
out_filename = g_strdup(tmpname);
*out_filenamep = out_filename;
}
if (out_fd == -1) {
cf_open_failure_alert_box(out_filename, err, NULL, TRUE, file_type);
return CF_ERROR;
}
cb.callback_func = merge_callback;
cb.data = g_malloc0(sizeof(callback_data_t));
status = merge_files(out_fd, out_filename, file_type,
(const char *const *) in_filenames, in_file_count,
do_append, IDB_MERGE_MODE_ALL_SAME, 0 ,
"Wireshark", &cb, &err, &err_info, &err_fileno);
g_free(cb.data);
switch (status) {
case MERGE_OK:
break;
case MERGE_USER_ABORTED:
break;
case MERGE_ERR_CANT_OPEN_INFILE:
cf_open_failure_alert_box(in_filenames[err_fileno], err, err_info,
FALSE, 0);
ws_close(out_fd);
break;
case MERGE_ERR_CANT_OPEN_OUTFILE:
cf_open_failure_alert_box(out_filename, err, err_info, TRUE,
file_type);
ws_close(out_fd);
break;
case MERGE_ERR_CANT_READ_INFILE:
case MERGE_ERR_BAD_PHDR_INTERFACE_ID:
case MERGE_ERR_CANT_WRITE_OUTFILE:
case MERGE_ERR_CANT_CLOSE_OUTFILE:
default:
simple_error_message_box("%s", err_info ? err_info : "unknown error");
break;
}
g_free(err_info);
if (status != MERGE_OK) {
return CF_ERROR;
} else
return CF_OK;
}
cf_status_t
cf_filter_packets(capture_file *cf, gchar *dftext, gboolean force)
{
const char *filter_new = dftext ? dftext : "";
const char *filter_old = cf->dfilter ? cf->dfilter : "";
dfilter_t *dfcode;
gchar *err_msg;
GTimeVal start_time;
if (!force && strcmp(filter_new, filter_old) == 0) {
return CF_OK;
}
dfcode=NULL;
if (dftext == NULL) {
} else {
dftext = g_strdup(dftext);
if (!dfilter_compile(dftext, &dfcode, &err_msg)) {
simple_message_box(ESD_TYPE_ERROR, NULL,
"See the help for a description of the display filter syntax.",
"\"%s\" isn't a valid display filter: %s",
dftext, err_msg);
g_free(err_msg);
g_free(dftext);
return CF_ERROR;
}
if (dfcode == NULL) {
g_free(dftext);
dftext = NULL;
}
}
g_free(cf->dfilter);
cf->dfilter = dftext;
g_get_current_time(&start_time);
if (cf->state != FILE_CLOSED) {
if (dftext == NULL) {
rescan_packets(cf, "Resetting", "Filter", FALSE);
} else {
rescan_packets(cf, "Filtering", dftext, FALSE);
}
}
dfilter_free(dfcode);
return CF_OK;
}
void
cf_reftime_packets(capture_file *cf)
{
ref_time_packets(cf);
}
void
cf_redissect_packets(capture_file *cf)
{
if (cf->state != FILE_CLOSED) {
rescan_packets(cf, "Reprocessing", "all packets", TRUE);
}
}
gboolean
cf_read_record_r(capture_file *cf, const frame_data *fdata,
struct wtap_pkthdr *phdr, Buffer *buf)
{
int err;
gchar *err_info;
gchar *display_basename;
#ifdef WANT_PACKET_EDITOR
if (G_UNLIKELY(fdata->file_off == -1)) {
const modified_frame_data *frame = (const modified_frame_data *) g_tree_lookup(cf->edited_frames, GINT_TO_POINTER(fdata->num));
if (!frame) {
simple_error_message_box("fdata->file_off == -1, but can't find modified frame.");
return FALSE;
}
*phdr = frame->phdr;
ws_buffer_assure_space(buf, frame->phdr.caplen);
memcpy(ws_buffer_start_ptr(buf), frame->pd, frame->phdr.caplen);
return TRUE;
}
#endif
if (!wtap_seek_read(cf->wth, fdata->file_off, phdr, buf, &err, &err_info)) {
display_basename = g_filename_display_basename(cf->filename);
switch (err) {
case WTAP_ERR_BAD_FILE:
simple_error_message_box("An error occurred while reading from the file \"%s\": %s.\n(%s)",
display_basename, wtap_strerror(err),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
simple_error_message_box(
"An error occurred while reading from the file \"%s\": %s.",
display_basename, wtap_strerror(err));
break;
}
g_free(display_basename);
return FALSE;
}
return TRUE;
}
gboolean
cf_read_record(capture_file *cf, frame_data *fdata)
{
return cf_read_record_r(cf, fdata, &cf->phdr, &cf->buf);
}
static void
rescan_packets(capture_file *cf, const char *action, const char *action_item, gboolean redissect)
{
guint32 framenum;
frame_data *fdata;
progdlg_t *progbar = NULL;
int count;
frame_data *selected_frame, *preceding_frame, *following_frame, *prev_frame;
int selected_frame_num, preceding_frame_num, following_frame_num, prev_frame_num;
gboolean selected_frame_seen;
float progbar_val;
GTimeVal start_time;
gchar status_str[100];
int progbar_nextstep;
int progbar_quantum;
epan_dissect_t edt;
dfilter_t *dfcode;
column_info *cinfo;
gboolean create_proto_tree;
guint tap_flags;
gboolean add_to_packet_list = FALSE;
gboolean compiled;
guint32 frames_count;
compiled = dfilter_compile(cf->dfilter, &dfcode, NULL);
g_assert(!cf->dfilter || (compiled && dfcode));
tap_flags = union_of_tap_listener_flags();
cinfo = (tap_flags & TL_REQUIRES_COLUMNS) ? &cf->cinfo : NULL;
create_proto_tree =
(dfcode != NULL || have_filtering_tap_listeners() || (tap_flags & TL_REQUIRES_PROTO_TREE));
reset_tap_listeners();
selected_frame = cf->current_frame;
selected_frame_num = -1;
packet_list_freeze();
if (redissect) {
cf->redissecting = TRUE;
epan_free(cf->epan);
cf->epan = ws_epan_new(cf);
cf->cinfo.epan = cf->epan;
packet_list_clear();
add_to_packet_list = TRUE;
}
cf->first_displayed = 0;
cf->last_displayed = 0;
cf->displayed_count = 0;
cf->ref = NULL;
cf->prev_dis = NULL;
cf->prev_cap = NULL;
cf->cum_bytes = 0;
cf_callback_invoke(cf_cb_file_rescan_started, cf);
progbar_nextstep = 0;
progbar_quantum = cf->count/N_PROGBAR_UPDATES;
count = 0;
progbar_val = 0.0f;
cf->stop_flag = FALSE;
g_get_current_time(&start_time);
prev_frame_num = -1;
prev_frame = NULL;
preceding_frame_num = -1;
preceding_frame = NULL;
following_frame_num = -1;
following_frame = NULL;
selected_frame_seen = FALSE;
frames_count = cf->count;
epan_dissect_init(&edt, cf->epan, create_proto_tree, FALSE);
for (framenum = 1; framenum <= frames_count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
if (progbar == NULL)
progbar = delayed_create_progress_dlg(cf->window, action, action_item, TRUE,
&cf->stop_flag,
&start_time,
progbar_val);
if (count >= progbar_nextstep) {
g_assert(cf->count > 0);
progbar_val = (gfloat) count / frames_count;
if (progbar != NULL) {
g_snprintf(status_str, sizeof(status_str),
"%4u of %u frames", count, frames_count);
update_progress_dlg(progbar, progbar_val, status_str);
}
progbar_nextstep += progbar_quantum;
}
if (cf->stop_flag) {
break;
}
count++;
if (redissect) {
frame_data_reset(fdata);
frames_count = cf->count;
}
fdata->flags.dependent_of_displayed = 0;
if (!cf_read_record(cf, fdata))
break;
if (prev_frame_num != -1 && !selected_frame_seen && prev_frame->flags.passed_dfilter) {
preceding_frame_num = prev_frame_num;
preceding_frame = prev_frame;
}
add_packet_to_packet_list(fdata, cf, &edt, dfcode,
cinfo, &cf->phdr,
ws_buffer_start_ptr(&cf->buf),
add_to_packet_list);
if (fdata->flags.passed_dfilter && selected_frame_seen && following_frame_num == -1) {
following_frame_num = fdata->num;
following_frame = fdata;
}
if (fdata == selected_frame) {
selected_frame_seen = TRUE;
if (fdata->flags.passed_dfilter)
selected_frame_num = fdata->num;
}
prev_frame_num = fdata->num;
prev_frame = fdata;
}
epan_dissect_cleanup(&edt);
cf->redissecting = FALSE;
if (redissect) {
frames_count = cf->count;
for (; framenum <= frames_count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
frame_data_reset(fdata);
}
}
if (progbar != NULL)
destroy_progress_dlg(progbar);
if (!add_to_packet_list)
packet_list_recreate_visible_rows();
compute_elapsed(cf, &start_time);
packet_list_thaw();
cf_callback_invoke(cf_cb_file_rescan_finished, cf);
if (selected_frame_num == -1) {
if (selected_frame == NULL) {
selected_frame_num = 0;
} else {
g_assert(following_frame == NULL ||
following_frame->num >= selected_frame->num);
g_assert(preceding_frame == NULL ||
preceding_frame->num <= selected_frame->num);
if (following_frame == NULL) {
selected_frame_num = preceding_frame_num;
selected_frame = preceding_frame;
} else if (preceding_frame == NULL) {
selected_frame_num = following_frame_num;
selected_frame = following_frame;
} else {
selected_frame_num = preceding_frame_num;
selected_frame = preceding_frame;
}
}
}
if (selected_frame_num == -1) {
cf_unselect_packet(cf);
} else {
cf->current_row = -1;
if (selected_frame_num == 0) {
packet_list_select_first_row();
}else{
if (!packet_list_select_row_from_data(selected_frame)) {
simple_message_box(ESD_TYPE_INFO, NULL,
"The capture file is probably not fully dissected.",
"End of capture exceeded.");
}
}
}
dfilter_free(dfcode);
}
static void
ref_time_packets(capture_file *cf)
{
guint32 framenum;
frame_data *fdata;
nstime_t rel_ts;
cf->ref = NULL;
cf->prev_dis = NULL;
cf->cum_bytes = 0;
for (framenum = 1; framenum <= cf->count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
fdata->cum_bytes = cf->cum_bytes + fdata->pkt_len;
if (cf->ref == NULL)
cf->ref = fdata;
if (fdata->flags.ref_time)
cf->ref = fdata;
if (cf->prev_dis == NULL) {
cf->prev_dis = fdata;
}
fdata->frame_ref_num = (fdata != cf->ref) ? cf->ref->num : 0;
nstime_delta(&rel_ts, &fdata->abs_ts, &cf->ref->abs_ts);
if ((gint32)cf->elapsed_time.secs < rel_ts.secs
|| ((gint32)cf->elapsed_time.secs == rel_ts.secs && (gint32)cf->elapsed_time.nsecs < rel_ts.nsecs)) {
cf->elapsed_time = rel_ts;
}
if ( fdata->flags.passed_dfilter ) {
fdata->prev_dis_num = cf->prev_dis->num;
cf->prev_dis = fdata;
}
if ( (fdata->flags.passed_dfilter) || (fdata->flags.ref_time) ) {
if (fdata->flags.ref_time) {
cf->cum_bytes = fdata->pkt_len;
fdata->cum_bytes = cf->cum_bytes;
} else {
cf->cum_bytes += fdata->pkt_len;
}
}
}
}
static psp_return_t
process_specified_records(capture_file *cf, packet_range_t *range,
const char *string1, const char *string2, gboolean terminate_is_stop,
gboolean (*callback)(capture_file *, frame_data *,
struct wtap_pkthdr *, const guint8 *, void *),
void *callback_args)
{
guint32 framenum;
frame_data *fdata;
Buffer buf;
psp_return_t ret = PSP_FINISHED;
progdlg_t *progbar = NULL;
int progbar_count;
float progbar_val;
GTimeVal progbar_start_time;
gchar progbar_status_str[100];
int progbar_nextstep;
int progbar_quantum;
range_process_e process_this;
struct wtap_pkthdr phdr;
wtap_phdr_init(&phdr);
ws_buffer_init(&buf, 1500);
progbar_nextstep = 0;
progbar_quantum = cf->count/N_PROGBAR_UPDATES;
progbar_count = 0;
progbar_val = 0.0f;
cf->stop_flag = FALSE;
g_get_current_time(&progbar_start_time);
if (range != NULL)
packet_range_process_init(range);
for (framenum = 1; framenum <= cf->count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
if (progbar == NULL)
progbar = delayed_create_progress_dlg(cf->window, string1, string2,
terminate_is_stop,
&cf->stop_flag,
&progbar_start_time,
progbar_val);
if (progbar_count >= progbar_nextstep) {
g_assert(cf->count > 0);
progbar_val = (gfloat) progbar_count / cf->count;
if (progbar != NULL) {
g_snprintf(progbar_status_str, sizeof(progbar_status_str),
"%4u of %u packets", progbar_count, cf->count);
update_progress_dlg(progbar, progbar_val, progbar_status_str);
}
progbar_nextstep += progbar_quantum;
}
if (cf->stop_flag) {
ret = PSP_STOPPED;
break;
}
progbar_count++;
if (range != NULL) {
process_this = packet_range_process_packet(range, fdata);
if (process_this == range_process_next) {
continue;
} else if (process_this == range_processing_finished) {
break;
}
}
if (!cf_read_record_r(cf, fdata, &phdr, &buf)) {
ret = PSP_FAILED;
break;
}
if (!callback(cf, fdata, &phdr, ws_buffer_start_ptr(&buf), callback_args)) {
ret = PSP_FAILED;
break;
}
}
if (progbar != NULL)
destroy_progress_dlg(progbar);
wtap_phdr_cleanup(&phdr);
ws_buffer_free(&buf);
return ret;
}
static gboolean
retap_packet(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr, const guint8 *pd,
void *argsp)
{
retap_callback_args_t *args = (retap_callback_args_t *)argsp;
epan_dissect_run_with_taps(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, args->cinfo);
epan_dissect_reset(&args->edt);
return TRUE;
}
cf_read_status_t
cf_retap_packets(capture_file *cf)
{
packet_range_t range;
retap_callback_args_t callback_args;
gboolean construct_protocol_tree;
gboolean filtering_tap_listeners;
guint tap_flags;
psp_return_t ret;
if (cf == NULL) {
return CF_READ_ABORTED;
}
cf_callback_invoke(cf_cb_file_retap_started, cf);
filtering_tap_listeners = have_filtering_tap_listeners();
tap_flags = union_of_tap_listener_flags();
construct_protocol_tree = filtering_tap_listeners ||
(tap_flags & TL_REQUIRES_PROTO_TREE);
callback_args.cinfo = (tap_flags & TL_REQUIRES_COLUMNS) ? &cf->cinfo : NULL;
reset_tap_listeners();
epan_dissect_init(&callback_args.edt, cf->epan, construct_protocol_tree, FALSE);
packet_range_init(&range, cf);
packet_range_process_init(&range);
ret = process_specified_records(cf, &range, "Recalculating statistics on",
"all packets", TRUE, retap_packet,
&callback_args);
epan_dissect_cleanup(&callback_args.edt);
cf_callback_invoke(cf_cb_file_retap_finished, cf);
switch (ret) {
case PSP_FINISHED:
return CF_READ_OK;
case PSP_STOPPED:
return CF_READ_ABORTED;
case PSP_FAILED:
return CF_READ_ERROR;
}
g_assert_not_reached();
return CF_READ_OK;
}
static gboolean
print_packet(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr, const guint8 *pd,
void *argsp)
{
print_callback_args_t *args = (print_callback_args_t *)argsp;
int i;
char *cp;
int line_len;
int column_len;
int cp_off;
char bookmark_name[9+10+1];
char bookmark_title[6+10+1];
col_item_t* col_item;
if (args->print_args->print_summary) {
col_custom_prime_edt(&args->edt, &cf->cinfo);
epan_dissect_run(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, &cf->cinfo);
epan_dissect_fill_in_columns(&args->edt, FALSE, TRUE);
} else
epan_dissect_run(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, NULL);
if (args->print_formfeed) {
if (!new_page(args->print_args->stream))
goto fail;
} else {
if (args->print_separator) {
if (!print_line(args->print_args->stream, 0, ""))
goto fail;
}
}
g_snprintf(bookmark_name, sizeof bookmark_name, "__frame%u__", fdata->num);
if (args->print_args->print_summary) {
if (!args->print_args->print_col_headings)
args->print_header_line = FALSE;
if (args->print_header_line) {
if (!print_line(args->print_args->stream, 0, args->header_line_buf))
goto fail;
args->print_header_line = FALSE;
}
cp = &args->line_buf[0];
line_len = 0;
for (i = 0; i < args->num_visible_cols; i++) {
col_item = &cf->cinfo.columns[args->visible_cols[i]];
column_len = (int) strlen(col_item->col_data);
if (args->col_widths[i] > column_len)
column_len = args->col_widths[i];
line_len += column_len + 1;
if (line_len > args->line_buf_len) {
cp_off = (int) (cp - args->line_buf);
args->line_buf_len = 2 * line_len;
args->line_buf = (char *)g_realloc(args->line_buf, args->line_buf_len + 1);
cp = args->line_buf + cp_off;
}
if (col_item->col_fmt == COL_NUMBER)
g_snprintf(cp, column_len+1, "%*s", args->col_widths[i], col_item->col_data);
else
g_snprintf(cp, column_len+1, "%-*s", args->col_widths[i], col_item->col_data);
cp += column_len;
if (i != args->num_visible_cols - 1)
*cp++ = ' ';
}
*cp = '\0';
if (!print_bookmark(args->print_args->stream, bookmark_name,
args->line_buf))
goto fail;
if (!print_line(args->print_args->stream, 0, args->line_buf))
goto fail;
} else {
g_snprintf(bookmark_title, sizeof bookmark_title, "Frame %u", fdata->num);
if (!print_bookmark(args->print_args->stream, bookmark_name,
bookmark_title))
goto fail;
}
if (args->print_args->print_dissections != print_dissections_none) {
if (args->print_args->print_summary) {
if (!print_line(args->print_args->stream, 0, ""))
goto fail;
}
if (!proto_tree_print(args->print_args, &args->edt, NULL, args->print_args->stream))
goto fail;
args->print_separator = TRUE;
if (args->print_args->print_col_headings)
args->print_header_line = TRUE;
}
if (args->print_args->print_hex) {
if (args->print_args->print_summary || (args->print_args->print_dissections != print_dissections_none)) {
if (!print_line(args->print_args->stream, 0, ""))
goto fail;
}
if (!print_hex_data(args->print_args->stream, &args->edt))
goto fail;
args->print_separator = TRUE;
if (args->print_args->print_col_headings)
args->print_header_line = TRUE;
}
epan_dissect_reset(&args->edt);
if (args->print_args->print_formfeed) {
args->print_formfeed = TRUE;
}
return TRUE;
fail:
epan_dissect_reset(&args->edt);
return FALSE;
}
cf_print_status_t
cf_print_packets(capture_file *cf, print_args_t *print_args)
{
print_callback_args_t callback_args;
gint data_width;
char *cp;
int i, cp_off, column_len, line_len;
int num_visible_col = 0, last_visible_col = 0, visible_col_count;
psp_return_t ret;
GList *clp;
fmt_data *cfmt;
gboolean proto_tree_needed;
callback_args.print_args = print_args;
callback_args.print_header_line = print_args->print_col_headings;
callback_args.header_line_buf = NULL;
callback_args.header_line_buf_len = 256;
callback_args.print_formfeed = FALSE;
callback_args.print_separator = FALSE;
callback_args.line_buf = NULL;
callback_args.line_buf_len = 256;
callback_args.col_widths = NULL;
callback_args.num_visible_cols = 0;
callback_args.visible_cols = NULL;
if (!print_preamble(print_args->stream, cf->filename, get_ws_vcs_version_info())) {
destroy_print_stream(print_args->stream);
return CF_PRINT_WRITE_ERROR;
}
if (print_args->print_summary) {
callback_args.header_line_buf = (char *)g_malloc(callback_args.header_line_buf_len + 1);
for (i = 0; i < prefs.num_cols; i++) {
clp = g_list_nth(prefs.col_list, i);
if (clp == NULL)
continue;
cfmt = (fmt_data *) clp->data;
if (cfmt->visible) {
num_visible_col++;
last_visible_col = i;
}
}
callback_args.num_visible_cols = num_visible_col;
callback_args.col_widths = (gint *) g_malloc(sizeof(gint) * num_visible_col);
callback_args.visible_cols = (gint *) g_malloc(sizeof(gint) * num_visible_col);
cp = &callback_args.header_line_buf[0];
line_len = 0;
visible_col_count = 0;
for (i = 0; i < cf->cinfo.num_cols; i++) {
clp = g_list_nth(prefs.col_list, i);
if (clp == NULL)
continue;
cfmt = (fmt_data *) clp->data;
if (cfmt->visible == FALSE)
continue;
callback_args.visible_cols[visible_col_count] = i;
if (i == last_visible_col)
callback_args.col_widths[visible_col_count] = 0;
else {
callback_args.col_widths[visible_col_count] = (gint) strlen(cf->cinfo.columns[i].col_title);
data_width = get_column_char_width(get_column_format(i));
if (data_width > callback_args.col_widths[visible_col_count])
callback_args.col_widths[visible_col_count] = data_width;
}
column_len = (int) strlen(cf->cinfo.columns[i].col_title);
if (callback_args.col_widths[i] > column_len)
column_len = callback_args.col_widths[visible_col_count];
line_len += column_len + 1;
if (line_len > callback_args.header_line_buf_len) {
cp_off = (int) (cp - callback_args.header_line_buf);
callback_args.header_line_buf_len = 2 * line_len;
callback_args.header_line_buf = (char *)g_realloc(callback_args.header_line_buf,
callback_args.header_line_buf_len + 1);
cp = callback_args.header_line_buf + cp_off;
}
g_snprintf(cp, column_len+1, "%-*s", callback_args.col_widths[visible_col_count], cf->cinfo.columns[i].col_title);
cp += column_len;
if (i != cf->cinfo.num_cols - 1)
*cp++ = ' ';
visible_col_count++;
}
*cp = '\0';
callback_args.line_buf_len = callback_args.header_line_buf_len;
callback_args.line_buf = (char *)g_malloc(callback_args.line_buf_len + 1);
}
proto_tree_needed =
callback_args.print_args->print_dissections != print_dissections_none ||
callback_args.print_args->print_hex ||
have_custom_cols(&cf->cinfo);
epan_dissect_init(&callback_args.edt, cf->epan, proto_tree_needed, proto_tree_needed);
ret = process_specified_records(cf, &print_args->range, "Printing",
"selected packets", TRUE, print_packet,
&callback_args);
epan_dissect_cleanup(&callback_args.edt);
g_free(callback_args.header_line_buf);
g_free(callback_args.line_buf);
g_free(callback_args.col_widths);
g_free(callback_args.visible_cols);
switch (ret) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
break;
case PSP_FAILED:
destroy_print_stream(print_args->stream);
return CF_PRINT_WRITE_ERROR;
}
if (!print_finale(print_args->stream)) {
destroy_print_stream(print_args->stream);
return CF_PRINT_WRITE_ERROR;
}
if (!destroy_print_stream(print_args->stream))
return CF_PRINT_WRITE_ERROR;
return CF_PRINT_OK;
}
static gboolean
write_pdml_packet(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr, const guint8 *pd,
void *argsp)
{
write_packet_callback_args_t *args = (write_packet_callback_args_t *)argsp;
epan_dissect_run(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, NULL);
write_pdml_proto_tree(&args->edt, args->fh);
epan_dissect_reset(&args->edt);
return !ferror(args->fh);
}
cf_print_status_t
cf_write_pdml_packets(capture_file *cf, print_args_t *print_args)
{
write_packet_callback_args_t callback_args;
FILE *fh;
psp_return_t ret;
fh = ws_fopen(print_args->file, "w");
if (fh == NULL)
return CF_PRINT_OPEN_ERROR;
write_pdml_preamble(fh, cf->filename);
if (ferror(fh)) {
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
callback_args.fh = fh;
epan_dissect_init(&callback_args.edt, cf->epan, TRUE, TRUE);
ret = process_specified_records(cf, &print_args->range, "Writing PDML",
"selected packets", TRUE,
write_pdml_packet, &callback_args);
epan_dissect_cleanup(&callback_args.edt);
switch (ret) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
break;
case PSP_FAILED:
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
write_pdml_finale(fh);
if (ferror(fh)) {
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
fclose(fh);
return CF_PRINT_OK;
}
static gboolean
write_psml_packet(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr, const guint8 *pd,
void *argsp)
{
write_packet_callback_args_t *args = (write_packet_callback_args_t *)argsp;
col_custom_prime_edt(&args->edt, &cf->cinfo);
epan_dissect_run(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, &cf->cinfo);
epan_dissect_fill_in_columns(&args->edt, FALSE, TRUE);
write_psml_columns(&args->edt, args->fh);
epan_dissect_reset(&args->edt);
return !ferror(args->fh);
}
cf_print_status_t
cf_write_psml_packets(capture_file *cf, print_args_t *print_args)
{
write_packet_callback_args_t callback_args;
FILE *fh;
psp_return_t ret;
gboolean proto_tree_needed;
fh = ws_fopen(print_args->file, "w");
if (fh == NULL)
return CF_PRINT_OPEN_ERROR;
write_psml_preamble(&cf->cinfo, fh);
if (ferror(fh)) {
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
callback_args.fh = fh;
proto_tree_needed = have_custom_cols(&cf->cinfo);
epan_dissect_init(&callback_args.edt, cf->epan, proto_tree_needed, proto_tree_needed);
ret = process_specified_records(cf, &print_args->range, "Writing PSML",
"selected packets", TRUE,
write_psml_packet, &callback_args);
epan_dissect_cleanup(&callback_args.edt);
switch (ret) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
break;
case PSP_FAILED:
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
write_psml_finale(fh);
if (ferror(fh)) {
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
fclose(fh);
return CF_PRINT_OK;
}
static gboolean
write_csv_packet(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr, const guint8 *pd,
void *argsp)
{
write_packet_callback_args_t *args = (write_packet_callback_args_t *)argsp;
col_custom_prime_edt(&args->edt, &cf->cinfo);
epan_dissect_run(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, &cf->cinfo);
epan_dissect_fill_in_columns(&args->edt, FALSE, TRUE);
write_csv_columns(&args->edt, args->fh);
epan_dissect_reset(&args->edt);
return !ferror(args->fh);
}
cf_print_status_t
cf_write_csv_packets(capture_file *cf, print_args_t *print_args)
{
write_packet_callback_args_t callback_args;
gboolean proto_tree_needed;
FILE *fh;
psp_return_t ret;
fh = ws_fopen(print_args->file, "w");
if (fh == NULL)
return CF_PRINT_OPEN_ERROR;
write_csv_column_titles(&cf->cinfo, fh);
if (ferror(fh)) {
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
callback_args.fh = fh;
proto_tree_needed = have_custom_cols(&cf->cinfo);
epan_dissect_init(&callback_args.edt, cf->epan, proto_tree_needed, proto_tree_needed);
ret = process_specified_records(cf, &print_args->range, "Writing CSV",
"selected packets", TRUE,
write_csv_packet, &callback_args);
epan_dissect_cleanup(&callback_args.edt);
switch (ret) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
break;
case PSP_FAILED:
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
fclose(fh);
return CF_PRINT_OK;
}
static gboolean
carrays_write_packet(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr,
const guint8 *pd, void *argsp)
{
write_packet_callback_args_t *args = (write_packet_callback_args_t *)argsp;
epan_dissect_run(&args->edt, cf->cd_t, phdr, frame_tvbuff_new(fdata, pd), fdata, NULL);
write_carrays_hex_data(fdata->num, args->fh, &args->edt);
epan_dissect_reset(&args->edt);
return !ferror(args->fh);
}
cf_print_status_t
cf_write_carrays_packets(capture_file *cf, print_args_t *print_args)
{
write_packet_callback_args_t callback_args;
FILE *fh;
psp_return_t ret;
fh = ws_fopen(print_args->file, "w");
if (fh == NULL)
return CF_PRINT_OPEN_ERROR;
if (ferror(fh)) {
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
callback_args.fh = fh;
epan_dissect_init(&callback_args.edt, cf->epan, TRUE, TRUE);
ret = process_specified_records(cf, &print_args->range,
"Writing C Arrays",
"selected packets", TRUE,
carrays_write_packet, &callback_args);
epan_dissect_cleanup(&callback_args.edt);
switch (ret) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
break;
case PSP_FAILED:
fclose(fh);
return CF_PRINT_WRITE_ERROR;
}
fclose(fh);
return CF_PRINT_OK;
}
gboolean
cf_find_packet_protocol_tree(capture_file *cf, const char *string,
search_direction dir)
{
match_data mdata;
mdata.string = string;
mdata.string_len = strlen(string);
return find_packet(cf, match_protocol_tree, &mdata, dir);
}
gboolean
cf_find_string_protocol_tree(capture_file *cf, proto_tree *tree, match_data *mdata)
{
mdata->frame_matched = FALSE;
mdata->string = convert_string_case(cf->sfilter, cf->case_type);
mdata->string_len = strlen(mdata->string);
mdata->cf = cf;
proto_tree_children_foreach(tree, match_subtree_text, mdata);
return mdata->frame_matched ? MR_MATCHED : MR_NOTMATCHED;
}
static match_result
match_protocol_tree(capture_file *cf, frame_data *fdata, void *criterion)
{
match_data *mdata = (match_data *)criterion;
epan_dissect_t edt;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
epan_dissect_init(&edt, cf->epan, TRUE, TRUE);
epan_dissect_run(&edt, cf->cd_t, &cf->phdr, frame_tvbuff_new_buffer(fdata, &cf->buf), fdata, NULL);
mdata->cf = cf;
mdata->frame_matched = FALSE;
proto_tree_children_foreach(edt.tree, match_subtree_text, mdata);
epan_dissect_cleanup(&edt);
return mdata->frame_matched ? MR_MATCHED : MR_NOTMATCHED;
}
static void
match_subtree_text(proto_node *node, gpointer data)
{
match_data *mdata = (match_data *) data;
const gchar *string = mdata->string;
size_t string_len = mdata->string_len;
capture_file *cf = mdata->cf;
field_info *fi = PNODE_FINFO(node);
gchar label_str[ITEM_LABEL_LENGTH];
gchar *label_ptr;
size_t label_len;
guint32 i;
guint8 c_char;
size_t c_match = 0;
g_assert(fi);
if (mdata->frame_matched) {
return;
}
if (PROTO_ITEM_IS_HIDDEN(node))
return;
if (fi->rep) {
label_ptr = fi->rep->representation;
} else {
label_ptr = label_str;
proto_item_fill_label(fi, label_str);
}
label_len = strlen(label_ptr);
for (i = 0; i < label_len; i++) {
c_char = label_ptr[i];
if (cf->case_type)
c_char = g_ascii_toupper(c_char);
if (c_char == string[c_match]) {
c_match++;
if (c_match == string_len) {
mdata->frame_matched = TRUE;
mdata->finfo = fi;
return;
}
} else
c_match = 0;
}
if (node->first_child != NULL)
proto_tree_children_foreach(node, match_subtree_text, mdata);
}
gboolean
cf_find_packet_summary_line(capture_file *cf, const char *string,
search_direction dir)
{
match_data mdata;
mdata.string = string;
mdata.string_len = strlen(string);
return find_packet(cf, match_summary_line, &mdata, dir);
}
static match_result
match_summary_line(capture_file *cf, frame_data *fdata, void *criterion)
{
match_data *mdata = (match_data *)criterion;
const gchar *string = mdata->string;
size_t string_len = mdata->string_len;
epan_dissect_t edt;
const char *info_column;
size_t info_column_len;
match_result result = MR_NOTMATCHED;
gint colx;
guint32 i;
guint8 c_char;
size_t c_match = 0;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
epan_dissect_init(&edt, cf->epan, FALSE, FALSE);
epan_dissect_run(&edt, cf->cd_t, &cf->phdr, frame_tvbuff_new_buffer(fdata, &cf->buf), fdata,
&cf->cinfo);
for (colx = 0; colx < cf->cinfo.num_cols; colx++) {
if (cf->cinfo.columns[colx].fmt_matx[COL_INFO]) {
info_column = edt.pi.cinfo->columns[colx].col_data;
info_column_len = strlen(info_column);
for (i = 0; i < info_column_len; i++) {
c_char = info_column[i];
if (cf->case_type)
c_char = g_ascii_toupper(c_char);
if (c_char == string[c_match]) {
c_match++;
if (c_match == string_len) {
result = MR_MATCHED;
break;
}
} else
c_match = 0;
}
break;
}
}
epan_dissect_cleanup(&edt);
return result;
}
gboolean
cf_find_packet_data(capture_file *cf, const guint8 *string, size_t string_size,
search_direction dir)
{
cbs_t info;
info.data = string;
info.data_len = string_size;
if (cf->string) {
switch (cf->scs_type) {
case SCS_NARROW_AND_WIDE:
return find_packet(cf, match_narrow_and_wide, &info, dir);
case SCS_NARROW:
return find_packet(cf, match_narrow, &info, dir);
case SCS_WIDE:
return find_packet(cf, match_wide, &info, dir);
default:
g_assert_not_reached();
return FALSE;
}
} else
return find_packet(cf, match_binary, &info, dir);
}
static match_result
match_narrow_and_wide(capture_file *cf, frame_data *fdata, void *criterion)
{
cbs_t *info = (cbs_t *)criterion;
const guint8 *ascii_text = info->data;
size_t textlen = info->data_len;
match_result result;
guint32 buf_len;
guint8 *pd;
guint32 i;
guint8 c_char;
size_t c_match = 0;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
result = MR_NOTMATCHED;
buf_len = fdata->cap_len;
pd = ws_buffer_start_ptr(&cf->buf);
i = 0;
while (i < buf_len) {
c_char = pd[i];
if (cf->case_type)
c_char = g_ascii_toupper(c_char);
if (c_char != '\0') {
if (c_char == ascii_text[c_match]) {
c_match += 1;
if (c_match == textlen) {
result = MR_MATCHED;
cf->search_pos = i;
break;
}
}
else {
g_assert(i>=c_match);
i -= (guint32)c_match;
c_match = 0;
}
}
i += 1;
}
return result;
}
static match_result
match_narrow(capture_file *cf, frame_data *fdata, void *criterion)
{
guint8 *pd;
cbs_t *info = (cbs_t *)criterion;
const guint8 *ascii_text = info->data;
size_t textlen = info->data_len;
match_result result;
guint32 buf_len;
guint32 i;
guint8 c_char;
size_t c_match = 0;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
result = MR_NOTMATCHED;
buf_len = fdata->cap_len;
pd = ws_buffer_start_ptr(&cf->buf);
i = 0;
while (i < buf_len) {
c_char = pd[i];
if (cf->case_type)
c_char = g_ascii_toupper(c_char);
if (c_char == ascii_text[c_match]) {
c_match += 1;
if (c_match == textlen) {
result = MR_MATCHED;
cf->search_pos = i;
break;
}
}
else {
g_assert(i>=c_match);
i -= (guint32)c_match;
c_match = 0;
}
i += 1;
}
return result;
}
static match_result
match_wide(capture_file *cf, frame_data *fdata, void *criterion)
{
cbs_t *info = (cbs_t *)criterion;
const guint8 *ascii_text = info->data;
size_t textlen = info->data_len;
match_result result;
guint32 buf_len;
guint8 *pd;
guint32 i;
guint8 c_char;
size_t c_match = 0;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
result = MR_NOTMATCHED;
buf_len = fdata->cap_len;
pd = ws_buffer_start_ptr(&cf->buf);
i = 0;
while (i < buf_len) {
c_char = pd[i];
if (cf->case_type)
c_char = g_ascii_toupper(c_char);
if (c_char == ascii_text[c_match]) {
c_match += 1;
if (c_match == textlen) {
result = MR_MATCHED;
cf->search_pos = i;
break;
}
i += 1;
}
else {
g_assert(i>=(c_match*2));
i -= (guint32)c_match*2;
c_match = 0;
}
i += 1;
}
return result;
}
static match_result
match_binary(capture_file *cf, frame_data *fdata, void *criterion)
{
cbs_t *info = (cbs_t *)criterion;
const guint8 *binary_data = info->data;
size_t datalen = info->data_len;
match_result result;
guint32 buf_len;
guint8 *pd;
guint32 i;
size_t c_match = 0;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
result = MR_NOTMATCHED;
buf_len = fdata->cap_len;
pd = ws_buffer_start_ptr(&cf->buf);
i = 0;
while (i < buf_len) {
if (pd[i] == binary_data[c_match]) {
c_match += 1;
if (c_match == datalen) {
result = MR_MATCHED;
cf->search_pos = i;
break;
}
}
else {
g_assert(i>=c_match);
i -= (guint32)c_match;
c_match = 0;
}
i += 1;
}
return result;
}
gboolean
cf_find_packet_dfilter(capture_file *cf, dfilter_t *sfcode,
search_direction dir)
{
return find_packet(cf, match_dfilter, sfcode, dir);
}
gboolean
cf_find_packet_dfilter_string(capture_file *cf, const char *filter,
search_direction dir)
{
dfilter_t *sfcode;
gboolean result;
if (!dfilter_compile(filter, &sfcode, NULL)) {
return FALSE;
}
if (sfcode == NULL) {
return FALSE;
}
result = find_packet(cf, match_dfilter, sfcode, dir);
dfilter_free(sfcode);
return result;
}
static match_result
match_dfilter(capture_file *cf, frame_data *fdata, void *criterion)
{
dfilter_t *sfcode = (dfilter_t *)criterion;
epan_dissect_t edt;
match_result result;
if (!cf_read_record(cf, fdata)) {
return MR_ERROR;
}
epan_dissect_init(&edt, cf->epan, TRUE, FALSE);
epan_dissect_prime_dfilter(&edt, sfcode);
epan_dissect_run(&edt, cf->cd_t, &cf->phdr, frame_tvbuff_new_buffer(fdata, &cf->buf), fdata, NULL);
result = dfilter_apply_edt(sfcode, &edt) ? MR_MATCHED : MR_NOTMATCHED;
epan_dissect_cleanup(&edt);
return result;
}
gboolean
cf_find_packet_marked(capture_file *cf, search_direction dir)
{
return find_packet(cf, match_marked, NULL, dir);
}
static match_result
match_marked(capture_file *cf _U_, frame_data *fdata, void *criterion _U_)
{
return fdata->flags.marked ? MR_MATCHED : MR_NOTMATCHED;
}
gboolean
cf_find_packet_time_reference(capture_file *cf, search_direction dir)
{
return find_packet(cf, match_time_reference, NULL, dir);
}
static match_result
match_time_reference(capture_file *cf _U_, frame_data *fdata, void *criterion _U_)
{
return fdata->flags.ref_time ? MR_MATCHED : MR_NOTMATCHED;
}
static gboolean
find_packet(capture_file *cf,
match_result (*match_function)(capture_file *, frame_data *, void *),
void *criterion, search_direction dir)
{
frame_data *start_fd;
guint32 framenum;
frame_data *fdata;
frame_data *new_fd = NULL;
progdlg_t *progbar = NULL;
int count;
gboolean found;
float progbar_val;
GTimeVal start_time;
gchar status_str[100];
int progbar_nextstep;
int progbar_quantum;
const char *title;
match_result result;
start_fd = cf->current_frame;
if (start_fd != NULL) {
count = 0;
framenum = start_fd->num;
progbar_nextstep = 0;
progbar_quantum = cf->count/N_PROGBAR_UPDATES;
progbar_val = 0.0f;
cf->stop_flag = FALSE;
g_get_current_time(&start_time);
title = cf->sfilter?cf->sfilter:"";
for (;;) {
if (progbar == NULL)
progbar = delayed_create_progress_dlg(cf->window, "Searching", title,
FALSE, &cf->stop_flag, &start_time, progbar_val);
if (count >= progbar_nextstep) {
g_assert(cf->count > 0);
progbar_val = (gfloat) count / cf->count;
if (progbar != NULL) {
g_snprintf(status_str, sizeof(status_str),
"%4u of %u packets", count, cf->count);
update_progress_dlg(progbar, progbar_val, status_str);
}
progbar_nextstep += progbar_quantum;
}
if (cf->stop_flag) {
new_fd = start_fd;
break;
}
if (dir == SD_BACKWARD) {
if (framenum == 1) {
if (prefs.gui_find_wrap)
{
statusbar_push_temporary_msg("Search reached the beginning. Continuing at end.");
framenum = cf->count;
}
else
{
statusbar_push_temporary_msg("Search reached the beginning.");
framenum = start_fd->num;
}
} else
framenum--;
} else {
if (framenum == cf->count) {
if (prefs.gui_find_wrap)
{
statusbar_push_temporary_msg("Search reached the end. Continuing at beginning.");
framenum = 1;
}
else
{
statusbar_push_temporary_msg("Search reached the end.");
framenum = start_fd->num;
}
} else
framenum++;
}
fdata = frame_data_sequence_find(cf->frames, framenum);
count++;
if (fdata->flags.passed_dfilter) {
result = (*match_function)(cf, fdata, criterion);
if (result == MR_ERROR) {
new_fd = start_fd;
break;
} else if (result == MR_MATCHED) {
new_fd = fdata;
break;
}
}
if (fdata == start_fd) {
break;
}
}
if (progbar != NULL)
destroy_progress_dlg(progbar);
}
if (new_fd != NULL) {
cf->search_in_progress = TRUE;
found = packet_list_select_row_from_data(new_fd);
cf->search_in_progress = FALSE;
cf->search_pos = 0;
if (!found) {
simple_message_box(ESD_TYPE_INFO, NULL,
"The capture file is probably not fully dissected.",
"End of capture exceeded.");
return FALSE;
}
return TRUE;
} else
return FALSE;
}
gboolean
cf_goto_frame(capture_file *cf, guint fnumber)
{
frame_data *fdata;
fdata = frame_data_sequence_find(cf->frames, fnumber);
if (fdata == NULL) {
statusbar_push_temporary_msg("There is no packet number %u.", fnumber);
return FALSE;
}
if (!fdata->flags.passed_dfilter) {
statusbar_push_temporary_msg("Packet number %u isn't displayed.", fnumber);
return FALSE;
}
if (!packet_list_select_row_from_data(fdata)) {
simple_message_box(ESD_TYPE_INFO, NULL,
"The capture file is probably not fully dissected.",
"End of capture exceeded.");
return FALSE;
}
return TRUE;
}
gboolean
cf_goto_top_frame(void)
{
packet_list_select_first_row();
return TRUE;
}
gboolean
cf_goto_bottom_frame(void)
{
packet_list_select_last_row();
return TRUE;
}
gboolean
cf_goto_framenum(capture_file *cf)
{
header_field_info *hfinfo;
guint32 framenum;
if (cf->finfo_selected) {
hfinfo = cf->finfo_selected->hfinfo;
g_assert(hfinfo);
if (hfinfo->type == FT_FRAMENUM) {
framenum = fvalue_get_uinteger(&cf->finfo_selected->value);
if (framenum != 0)
return cf_goto_frame(cf, framenum);
}
}
return FALSE;
}
void
cf_select_packet(capture_file *cf, int row)
{
epan_dissect_t *old_edt;
frame_data *fdata;
fdata = packet_list_get_row_data(row);
if (fdata == NULL) {
if (row == 0 && cf->first_displayed == cf->last_displayed)
fdata = frame_data_sequence_find(cf->frames, cf->first_displayed);
}
if (fdata == NULL) {
return;
}
if (!cf_read_record (cf, fdata)) {
return;
}
cf->current_frame = fdata;
cf->current_row = row;
old_edt = cf->edt;
cf->edt = epan_dissect_new(cf->epan, TRUE, TRUE);
tap_build_interesting(cf->edt);
epan_dissect_run(cf->edt, cf->cd_t, &cf->phdr, frame_tvbuff_new_buffer(cf->current_frame, &cf->buf),
cf->current_frame, NULL);
dfilter_macro_build_ftv_cache(cf->edt->tree);
cf_callback_invoke(cf_cb_packet_selected, cf);
if (old_edt != NULL)
epan_dissect_free(old_edt);
}
void
cf_unselect_packet(capture_file *cf)
{
epan_dissect_t *old_edt = cf->edt;
cf->edt = NULL;
cf->current_frame = NULL;
cf->current_row = 0;
cf_callback_invoke(cf_cb_packet_unselected, cf);
cf_unselect_field(cf);
if (old_edt != NULL)
epan_dissect_free(old_edt);
}
void
cf_unselect_field(capture_file *cf)
{
cf->finfo_selected = NULL;
cf_callback_invoke(cf_cb_field_unselected, cf);
}
void
cf_mark_frame(capture_file *cf, frame_data *frame)
{
if (! frame->flags.marked) {
frame->flags.marked = TRUE;
if (cf->count > cf->marked_count)
cf->marked_count++;
}
}
void
cf_unmark_frame(capture_file *cf, frame_data *frame)
{
if (frame->flags.marked) {
frame->flags.marked = FALSE;
if (cf->marked_count > 0)
cf->marked_count--;
}
}
void
cf_ignore_frame(capture_file *cf, frame_data *frame)
{
if (! frame->flags.ignored) {
frame->flags.ignored = TRUE;
if (cf->count > cf->ignored_count)
cf->ignored_count++;
}
}
void
cf_unignore_frame(capture_file *cf, frame_data *frame)
{
if (frame->flags.ignored) {
frame->flags.ignored = FALSE;
if (cf->ignored_count > 0)
cf->ignored_count--;
}
}
const gchar *
cf_read_shb_comment(capture_file *cf)
{
return wtap_file_get_shb_comment(cf->wth);
}
void
cf_update_capture_comment(capture_file *cf, gchar *comment)
{
const gchar *shb_comment;
shb_comment = wtap_file_get_shb_comment(cf->wth);
if (shb_comment) {
if (strcmp(shb_comment, comment) == 0) {
g_free(comment);
return;
}
}
wtap_write_shb_comment(cf->wth, comment);
cf->unsaved_changes = TRUE;
}
static const char *
cf_get_user_packet_comment(capture_file *cf, const frame_data *fd)
{
if (cf->frames_user_comments)
return (const char *)g_tree_lookup(cf->frames_user_comments, fd);
return NULL;
}
char *
cf_get_comment(capture_file *cf, const frame_data *fd)
{
char *comment;
if (fd->flags.has_user_comment)
return g_strdup(cf_get_user_packet_comment(cf, fd));
if (fd->flags.has_phdr_comment) {
struct wtap_pkthdr phdr;
Buffer buf;
wtap_phdr_init(&phdr);
ws_buffer_init(&buf, 1500);
if (!cf_read_record_r(cf, fd, &phdr, &buf))
{ }
comment = phdr.opt_comment;
wtap_phdr_cleanup(&phdr);
ws_buffer_free(&buf);
return comment;
}
return NULL;
}
static int
frame_cmp(gconstpointer a, gconstpointer b, gpointer user_data _U_)
{
const frame_data *fdata1 = (const frame_data *) a;
const frame_data *fdata2 = (const frame_data *) b;
return (fdata1->num < fdata2->num) ? -1 :
(fdata1->num > fdata2->num) ? 1 :
0;
}
gboolean
cf_set_user_packet_comment(capture_file *cf, frame_data *fd, const gchar *new_comment)
{
char *pkt_comment = cf_get_comment(cf, fd);
if (!g_strcmp0(pkt_comment, new_comment)) {
g_free(pkt_comment);
return FALSE;
}
g_free(pkt_comment);
if (pkt_comment)
cf->packet_comment_count--;
if (new_comment)
cf->packet_comment_count++;
fd->flags.has_user_comment = TRUE;
if (!cf->frames_user_comments)
cf->frames_user_comments = g_tree_new_full(frame_cmp, NULL, NULL, g_free);
g_tree_replace(cf->frames_user_comments, fd, g_strdup(new_comment));
expert_update_comment_count(cf->packet_comment_count);
cf->unsaved_changes = TRUE;
return TRUE;
}
guint32
cf_comment_types(capture_file *cf)
{
guint32 comment_types = 0;
if (cf_read_shb_comment(cf) != NULL)
comment_types |= WTAP_COMMENT_PER_SECTION;
if (cf->packet_comment_count != 0)
comment_types |= WTAP_COMMENT_PER_PACKET;
return comment_types;
}
static gint
g_direct_compare_func(gconstpointer a, gconstpointer b, gpointer user_data _U_)
{
if (a > b)
return 1;
else if (a < b)
return -1;
else
return 0;
}
static void
modified_frame_data_free(gpointer data)
{
modified_frame_data *mfd = (modified_frame_data *)data;
g_free(mfd->pd);
g_free(mfd);
}
void
cf_set_frame_edited(capture_file *cf, frame_data *fd,
struct wtap_pkthdr *phdr, guint8 *pd)
{
modified_frame_data *mfd = (modified_frame_data *)g_malloc(sizeof(modified_frame_data));
mfd->phdr = *phdr;
mfd->pd = pd;
if (cf->edited_frames == NULL)
cf->edited_frames = g_tree_new_full(g_direct_compare_func, NULL, NULL,
modified_frame_data_free);
g_tree_insert(cf->edited_frames, GINT_TO_POINTER(fd->num), mfd);
fd->file_off = -1;
cf->unsaved_changes = TRUE;
}
static gboolean
save_record(capture_file *cf, frame_data *fdata,
struct wtap_pkthdr *phdr, const guint8 *pd,
void *argsp)
{
save_callback_args_t *args = (save_callback_args_t *)argsp;
struct wtap_pkthdr hdr;
int err;
gchar *err_info;
gchar *display_basename;
const char *pkt_comment;
if (fdata->flags.has_user_comment)
pkt_comment = cf_get_user_packet_comment(cf, fdata);
else
pkt_comment = phdr->opt_comment;
hdr.rec_type = phdr->rec_type;
hdr.presence_flags = 0;
if (fdata->flags.has_ts)
hdr.presence_flags |= WTAP_HAS_TS;
if (phdr->presence_flags & WTAP_HAS_INTERFACE_ID)
hdr.presence_flags |= WTAP_HAS_INTERFACE_ID;
if (phdr->presence_flags & WTAP_HAS_PACK_FLAGS)
hdr.presence_flags |= WTAP_HAS_PACK_FLAGS;
hdr.ts.secs = fdata->abs_ts.secs;
hdr.ts.nsecs = fdata->abs_ts.nsecs;
hdr.caplen = phdr->caplen;
hdr.len = phdr->len;
hdr.pkt_encap = fdata->lnk_t;
hdr.interface_id = phdr->interface_id;
hdr.pack_flags = phdr->pack_flags;
hdr.opt_comment = g_strdup(pkt_comment);
hdr.pseudo_header = phdr->pseudo_header;
#if 0
hdr.drop_count =
hdr.pack_flags =
#endif
if (!wtap_dump(args->pdh, &hdr, pd, &err, &err_info)) {
if (err < 0) {
switch (err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
simple_error_message_box(
"Frame %u has a network type that can't be saved in a \"%s\" file.",
fdata->num, wtap_file_type_subtype_string(args->file_type));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
simple_error_message_box(
"Frame %u is larger than Wireshark supports in a \"%s\" file.",
fdata->num, wtap_file_type_subtype_string(args->file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
simple_error_message_box(
"Record %u has a record type that can't be saved in a \"%s\" file.",
fdata->num, wtap_file_type_subtype_string(args->file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
simple_error_message_box(
"Record %u has data that can't be saved in a \"%s\" file.\n(%s)",
fdata->num, wtap_file_type_subtype_string(args->file_type),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
display_basename = g_filename_display_basename(args->fname);
simple_error_message_box(
"An error occurred while writing to the file \"%s\": %s.",
display_basename, wtap_strerror(err));
g_free(display_basename);
break;
}
} else {
write_failure_alert_box(args->fname, err);
}
return FALSE;
}
g_free(hdr.opt_comment);
return TRUE;
}
gboolean
cf_can_write_with_wiretap(capture_file *cf)
{
return wtap_dump_can_write(cf->linktypes, 0);
}
gboolean
cf_can_save(capture_file *cf)
{
if (cf->unsaved_changes && wtap_dump_can_write(cf->linktypes, 0)) {
return TRUE;
}
if (cf->is_tempfile && !cf->unsaved_changes) {
return TRUE;
}
return FALSE;
}
gboolean
cf_can_save_as(capture_file *cf)
{
if (wtap_dump_can_write(cf->linktypes, 0)) {
return TRUE;
}
if (cf->is_tempfile && !cf->unsaved_changes) {
return TRUE;
}
return FALSE;
}
gboolean
cf_has_unsaved_data(capture_file *cf)
{
return (cf->is_tempfile && cf->count>0) || cf->unsaved_changes;
}
static cf_read_status_t
rescan_file(capture_file *cf, const char *fname, gboolean is_tempfile, int *err)
{
const struct wtap_pkthdr *phdr;
gchar *err_info;
gchar *name_ptr;
gint64 data_offset;
progdlg_t *progbar = NULL;
gint64 size;
float progbar_val;
GTimeVal start_time;
gchar status_str[100];
gint64 progbar_nextstep;
gint64 progbar_quantum;
guint32 framenum;
frame_data *fdata;
int count = 0;
#ifdef HAVE_LIBPCAP
int displayed_once = 0;
#endif
wtap_close(cf->wth);
cf->wth = wtap_open_offline(fname, WTAP_TYPE_AUTO, err, &err_info, TRUE);
if (cf->wth == NULL) {
cf_open_failure_alert_box(fname, *err, err_info, FALSE, 0);
return CF_READ_ERROR;
}
cf->f_datalen = 0;
cf->filename = g_strdup(fname);
cf->is_tempfile = is_tempfile;
cf->unsaved_changes = FALSE;
cf->cd_t = wtap_file_type_subtype(cf->wth);
cf->linktypes = g_array_sized_new(FALSE, FALSE, (guint) sizeof(int), 1);
cf->snap = wtap_snapshot_length(cf->wth);
if (cf->snap == 0) {
cf->has_snap = FALSE;
cf->snap = WTAP_MAX_PACKET_SIZE;
} else
cf->has_snap = TRUE;
name_ptr = g_filename_display_basename(cf->filename);
cf_callback_invoke(cf_cb_file_rescan_started, cf);
cf->iscompressed = wtap_iscompressed(cf->wth);
size = wtap_file_size(cf->wth, NULL);
progbar_nextstep = 0;
if (size >= 0) {
progbar_quantum = size/N_PROGBAR_UPDATES;
if (progbar_quantum < MIN_QUANTUM)
progbar_quantum = MIN_QUANTUM;
}else
progbar_quantum = 0;
cf->stop_flag = FALSE;
g_get_current_time(&start_time);
framenum = 0;
phdr = wtap_phdr(cf->wth);
while ((wtap_read(cf->wth, err, &err_info, &data_offset))) {
framenum++;
fdata = frame_data_sequence_find(cf->frames, framenum);
fdata->file_off = data_offset;
if (size >= 0) {
count++;
cf->f_datalen = wtap_read_so_far(cf->wth);
if ((progbar == NULL) && !(count % MIN_NUMBER_OF_PACKET)) {
progbar_val = calc_progbar_val(cf, size, cf->f_datalen, status_str, sizeof(status_str));
progbar = delayed_create_progress_dlg(cf->window, "Rescanning", name_ptr,
TRUE, &cf->stop_flag, &start_time, progbar_val);
}
if (cf->f_datalen >= progbar_nextstep) {
if (progbar != NULL) {
progbar_val = calc_progbar_val(cf, size, cf->f_datalen, status_str, sizeof(status_str));
#ifdef HAVE_LIBPCAP
if (progbar_quantum > 500000 || displayed_once == 0) {
if ((auto_scroll_live || displayed_once == 0 || cf->displayed_count < 1000) && cf->count != 0) {
displayed_once = 1;
packets_bar_update();
}
}
#endif
update_progress_dlg(progbar, progbar_val, status_str);
}
progbar_nextstep += progbar_quantum;
}
}
if (cf->stop_flag) {
break;
}
cf_add_encapsulation_type(cf, phdr->pkt_encap);
}
g_free(name_ptr);
if (progbar != NULL)
destroy_progress_dlg(progbar);
cf->state = FILE_READ_DONE;
wtap_sequential_close(cf->wth);
compute_elapsed(cf, &start_time);
cf->lnk_t = wtap_file_encap(cf->wth);
cf_callback_invoke(cf_cb_file_rescan_finished, cf);
if (cf->stop_flag) {
return CF_READ_ABORTED;
}
if (*err != 0) {
switch (*err) {
case WTAP_ERR_UNSUPPORTED:
simple_error_message_box(
"The capture file contains record data that Wireshark doesn't support.\n(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_SHORT_READ:
simple_error_message_box(
"The capture file appears to have been cut short"
" in the middle of a packet.");
break;
case WTAP_ERR_BAD_FILE:
simple_error_message_box(
"The capture file appears to be damaged or corrupt.\n(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_DECOMPRESS:
simple_error_message_box(
"The compressed capture file appears to be damaged or corrupt.\n"
"(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
simple_error_message_box(
"An error occurred while reading the"
" capture file: %s.", wtap_strerror(*err));
break;
}
return CF_READ_ERROR;
} else
return CF_READ_OK;
}
cf_write_status_t
cf_save_records(capture_file *cf, const char *fname, guint save_format,
gboolean compressed, gboolean discard_comments,
gboolean dont_reopen)
{
gchar *err_info;
gchar *fname_new = NULL;
wtap_dumper *pdh;
frame_data *fdata;
addrinfo_lists_t *addr_lists;
guint framenum;
int err;
#ifdef _WIN32
gchar *display_basename;
#endif
enum {
SAVE_WITH_MOVE,
SAVE_WITH_COPY,
SAVE_WITH_WTAP
} how_to_save;
save_callback_args_t callback_args;
cf_callback_invoke(cf_cb_file_save_started, (gpointer)fname);
addr_lists = get_addrinfo_list();
if (save_format == cf->cd_t && compressed == cf->iscompressed
&& !discard_comments && !cf->unsaved_changes
&& !(addr_lists && wtap_dump_has_name_resolution(save_format))) {
if (cf->is_tempfile) {
#ifndef _WIN32
if (ws_rename(cf->filename, fname) == 0) {
how_to_save = SAVE_WITH_MOVE;
} else {
if (errno == EXDEV) {
how_to_save = SAVE_WITH_COPY;
} else {
cf_rename_failure_alert_box(fname, errno);
goto fail;
}
}
#else
how_to_save = SAVE_WITH_COPY;
#endif
} else {
how_to_save = SAVE_WITH_COPY;
}
if (how_to_save == SAVE_WITH_COPY) {
if (file_exists(fname)) {
fname_new = g_strdup_printf("%s~", fname);
if (!copy_file_binary_mode(cf->filename, fname_new))
goto fail;
} else {
if (!copy_file_binary_mode(cf->filename, fname))
goto fail;
}
}
} else {
wtapng_section_t *shb_hdr = NULL;
wtapng_iface_descriptions_t *idb_inf = NULL;
wtapng_name_res_t *nrb_hdr = NULL;
int encap;
shb_hdr = wtap_file_get_shb_for_new_file(cf->wth);
idb_inf = wtap_file_get_idb_info(cf->wth);
nrb_hdr = wtap_file_get_nrb_for_new_file(cf->wth);
encap = wtap_dump_file_encap_type(cf->linktypes);
if (file_exists(fname)) {
fname_new = g_strdup_printf("%s~", fname);
pdh = wtap_dump_open_ng(fname_new, save_format, encap, cf->snap,
compressed, shb_hdr, idb_inf, nrb_hdr, &err);
} else {
pdh = wtap_dump_open_ng(fname, save_format, encap, cf->snap,
compressed, shb_hdr, idb_inf, nrb_hdr, &err);
}
g_free(idb_inf);
idb_inf = NULL;
if (pdh == NULL) {
cf_open_failure_alert_box(fname, err, NULL, TRUE, save_format);
goto fail;
}
wtap_dump_set_addrinfo_list(pdh, addr_lists);
callback_args.pdh = pdh;
callback_args.fname = fname;
callback_args.file_type = save_format;
switch (process_specified_records(cf, NULL, "Saving", "packets",
TRUE, save_record, &callback_args)) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
wtap_dump_close(pdh, &err);
if (fname_new != NULL)
ws_unlink(fname_new);
cf_callback_invoke(cf_cb_file_save_stopped, NULL);
return CF_WRITE_ABORTED;
case PSP_FAILED:
if (fname_new != NULL)
ws_unlink(fname_new);
wtap_dump_close(pdh, &err);
goto fail;
}
if (!wtap_dump_close(pdh, &err)) {
cf_close_failure_alert_box(fname, err);
goto fail;
}
how_to_save = SAVE_WITH_WTAP;
}
if (fname_new != NULL) {
#ifdef _WIN32
wtap_fdclose(cf->wth);
#endif
if (ws_rename(fname_new, fname) == -1) {
cf_rename_failure_alert_box(fname, errno);
#ifdef _WIN32
if (!wtap_fdreopen(cf->wth, cf->filename, &err)) {
display_basename = g_filename_display_basename(cf->filename);
simple_error_message_box(
file_open_error_message(err, FALSE), display_basename);
g_free(display_basename);
}
#endif
goto fail;
}
}
cf_callback_invoke(cf_cb_file_save_finished, NULL);
cf->unsaved_changes = FALSE;
if (!dont_reopen) {
switch (how_to_save) {
case SAVE_WITH_MOVE:
g_free(cf->filename);
cf->filename = g_strdup(fname);
cf->is_tempfile = FALSE;
cf_callback_invoke(cf_cb_file_fast_save_finished, cf);
break;
case SAVE_WITH_COPY:
wtap_close(cf->wth);
cf->open_type = WTAP_TYPE_AUTO;
cf->wth = wtap_open_offline(fname, WTAP_TYPE_AUTO, &err, &err_info, TRUE);
if (cf->wth == NULL) {
cf_open_failure_alert_box(fname, err, err_info, FALSE, 0);
cf_close(cf);
} else {
g_free(cf->filename);
cf->filename = g_strdup(fname);
cf->is_tempfile = FALSE;
}
cf_callback_invoke(cf_cb_file_fast_save_finished, cf);
break;
case SAVE_WITH_WTAP:
cf->open_type = WTAP_TYPE_AUTO;
if (rescan_file(cf, fname, FALSE, &err) != CF_READ_OK) {
cf_close(cf);
}
break;
}
if (discard_comments) {
wtap_write_shb_comment(cf->wth, NULL);
for (framenum = 1; framenum <= cf->count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
fdata->flags.has_phdr_comment = FALSE;
fdata->flags.has_user_comment = FALSE;
}
if (cf->frames_user_comments) {
g_tree_destroy(cf->frames_user_comments);
cf->frames_user_comments = NULL;
}
cf->packet_comment_count = 0;
}
}
return CF_WRITE_OK;
fail:
if (fname_new != NULL) {
ws_unlink(fname_new);
g_free(fname_new);
}
cf_callback_invoke(cf_cb_file_save_failed, NULL);
return CF_WRITE_ERROR;
}
cf_write_status_t
cf_export_specified_packets(capture_file *cf, const char *fname,
packet_range_t *range, guint save_format,
gboolean compressed)
{
gchar *fname_new = NULL;
int err;
wtap_dumper *pdh;
save_callback_args_t callback_args;
wtapng_section_t *shb_hdr = NULL;
wtapng_iface_descriptions_t *idb_inf = NULL;
wtapng_name_res_t *nrb_hdr = NULL;
int encap;
cf_callback_invoke(cf_cb_file_export_specified_packets_started, (gpointer)fname);
packet_range_process_init(range);
shb_hdr = wtap_file_get_shb_for_new_file(cf->wth);
idb_inf = wtap_file_get_idb_info(cf->wth);
nrb_hdr = wtap_file_get_nrb_for_new_file(cf->wth);
encap = wtap_dump_file_encap_type(cf->linktypes);
if (file_exists(fname)) {
fname_new = g_strdup_printf("%s~", fname);
pdh = wtap_dump_open_ng(fname_new, save_format, encap, cf->snap,
compressed, shb_hdr, idb_inf, nrb_hdr, &err);
} else {
pdh = wtap_dump_open_ng(fname, save_format, encap, cf->snap,
compressed, shb_hdr, idb_inf, nrb_hdr, &err);
}
g_free(idb_inf);
idb_inf = NULL;
if (pdh == NULL) {
cf_open_failure_alert_box(fname, err, NULL, TRUE, save_format);
goto fail;
}
wtap_dump_set_addrinfo_list(pdh, get_addrinfo_list());
callback_args.pdh = pdh;
callback_args.fname = fname;
callback_args.file_type = save_format;
switch (process_specified_records(cf, range, "Writing", "specified records",
TRUE, save_record, &callback_args)) {
case PSP_FINISHED:
break;
case PSP_STOPPED:
wtap_dump_close(pdh, &err);
if (fname_new != NULL)
ws_unlink(fname_new);
cf_callback_invoke(cf_cb_file_export_specified_packets_stopped, NULL);
return CF_WRITE_ABORTED;
break;
case PSP_FAILED:
if (fname_new != NULL)
ws_unlink(fname_new);
wtap_dump_close(pdh, &err);
goto fail;
}
if (!wtap_dump_close(pdh, &err)) {
cf_close_failure_alert_box(fname, err);
goto fail;
}
if (fname_new != NULL) {
if (ws_rename(fname_new, fname) == -1) {
cf_rename_failure_alert_box(fname, errno);
goto fail;
}
}
cf_callback_invoke(cf_cb_file_export_specified_packets_finished, NULL);
return CF_WRITE_OK;
fail:
if (fname_new != NULL) {
ws_unlink(fname_new);
g_free(fname_new);
}
cf_callback_invoke(cf_cb_file_export_specified_packets_failed, NULL);
return CF_WRITE_ERROR;
}
static void
cf_open_failure_alert_box(const char *filename, int err, gchar *err_info,
gboolean for_writing, int file_type)
{
gchar *display_basename;
if (err < 0) {
display_basename = g_filename_display_basename(filename);
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
simple_error_message_box(
"The file \"%s\" is a \"special file\" or socket or other non-regular file.",
display_basename);
break;
case WTAP_ERR_RANDOM_OPEN_PIPE:
simple_error_message_box(
"The file \"%s\" is a pipe or FIFO; Wireshark can't read pipe or FIFO files.\n"
"To capture from a pipe or FIFO use wireshark -i -",
display_basename);
break;
case WTAP_ERR_FILE_UNKNOWN_FORMAT:
simple_error_message_box(
"The file \"%s\" isn't a capture file in a format Wireshark understands.",
display_basename);
break;
case WTAP_ERR_UNSUPPORTED:
simple_error_message_box(
"The file \"%s\" contains record data that Wireshark doesn't support.\n"
"(%s)",
display_basename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_CANT_WRITE_TO_PIPE:
simple_error_message_box(
"The file \"%s\" is a pipe, and %s capture files can't be "
"written to a pipe.",
display_basename, wtap_file_type_subtype_string(file_type));
break;
case WTAP_ERR_UNWRITABLE_FILE_TYPE:
simple_error_message_box(
"Wireshark doesn't support writing capture files in that format.");
break;
case WTAP_ERR_UNWRITABLE_ENCAP:
simple_error_message_box("Wireshark can't save this capture in that format.");
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
if (for_writing) {
simple_error_message_box(
"Wireshark can't save this capture in that format.");
} else {
simple_error_message_box(
"The file \"%s\" is a capture for a network type that Wireshark doesn't support.",
display_basename);
}
break;
case WTAP_ERR_BAD_FILE:
simple_error_message_box(
"The file \"%s\" appears to be damaged or corrupt.\n"
"(%s)",
display_basename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_CANT_OPEN:
if (for_writing) {
simple_error_message_box(
"The file \"%s\" could not be created for some unknown reason.",
display_basename);
} else {
simple_error_message_box(
"The file \"%s\" could not be opened for some unknown reason.",
display_basename);
}
break;
case WTAP_ERR_SHORT_READ:
simple_error_message_box(
"The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.",
display_basename);
break;
case WTAP_ERR_SHORT_WRITE:
simple_error_message_box(
"A full header couldn't be written to the file \"%s\".",
display_basename);
break;
case WTAP_ERR_COMPRESSION_NOT_SUPPORTED:
simple_error_message_box(
"This file type cannot be written as a compressed file.");
break;
case WTAP_ERR_DECOMPRESS:
simple_error_message_box(
"The compressed file \"%s\" appears to be damaged or corrupt.\n"
"(%s)", display_basename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
simple_error_message_box(
"The file \"%s\" could not be %s: %s.",
display_basename,
for_writing ? "created" : "opened",
wtap_strerror(err));
break;
}
g_free(display_basename);
} else {
open_failure_alert_box(filename, err, for_writing);
}
}
static void
cf_rename_failure_alert_box(const char *filename, int err)
{
gchar *display_basename;
display_basename = g_filename_display_basename(filename);
switch (err) {
case ENOENT:
simple_error_message_box("The path to the file \"%s\" doesn't exist.",
display_basename);
break;
case EACCES:
simple_error_message_box("You don't have permission to move the capture file to \"%s\".",
display_basename);
break;
default:
simple_error_message_box("The file \"%s\" could not be moved: %s.",
display_basename, wtap_strerror(err));
break;
}
g_free(display_basename);
}
static void
cf_close_failure_alert_box(const char *filename, int err)
{
gchar *display_basename;
if (err < 0) {
display_basename = g_filename_display_basename(filename);
switch (err) {
case WTAP_ERR_CANT_CLOSE:
simple_error_message_box(
"The file \"%s\" couldn't be closed for some unknown reason.",
display_basename);
break;
case WTAP_ERR_SHORT_WRITE:
simple_error_message_box(
"Not all the packets could be written to the file \"%s\".",
display_basename);
break;
default:
simple_error_message_box(
"An error occurred while closing the file \"%s\": %s.",
display_basename, wtap_strerror(err));
break;
}
g_free(display_basename);
} else {
write_failure_alert_box(filename, err);
}
}
void
cf_reload(capture_file *cf) {
gchar *filename;
gboolean is_tempfile;
int err;
filename = g_strdup(cf->filename);
is_tempfile = cf->is_tempfile;
cf->is_tempfile = FALSE;
if (cf_open(cf, filename, cf->open_type, is_tempfile, &err) == CF_OK) {
switch (cf_read(cf, TRUE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
g_free(filename);
return;
}
} else {
cf->is_tempfile = is_tempfile;
}
g_free(filename);
}
