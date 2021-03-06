static void
rtp_key_destroy(gpointer key)
{
g_free(key);
key = NULL;
}
static void
rtp_channel_value_destroy(gpointer rci_arg)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)rci_arg;
g_array_free(rci->samples, TRUE);
g_free(rci);
rci = NULL;
}
static void
rtp_stream_value_destroy(gpointer rsi_arg)
{
rtp_stream_info_t *rsi = (rtp_stream_info_t *)rsi_arg;
GList* rtp_packet_list;
rtp_packet_t *rp;
rtp_packet_list = g_list_first(rsi->rtp_packet_list);
while (rtp_packet_list)
{
rp = (rtp_packet_t *)rtp_packet_list->data;
g_free(rp->info);
g_free(rp->payload_data);
g_free(rp);
rp = NULL;
rtp_packet_list = g_list_next(rtp_packet_list);
}
free_address(&rsi->src_addr);
free_address(&rsi->dest_addr);
g_free(rsi);
rsi = NULL;
}
static void
set_sensitive_check_bt(gchar *key _U_ , rtp_channel_info_t *rci, guint *stop_p )
{
gtk_widget_set_sensitive(rci->check_bt, !(*stop_p));
}
static void
bt_state(gboolean decode, gboolean play_state, gboolean pause_state, gboolean stop_state)
{
gboolean new_jitter_value = FALSE;
gboolean false_val = FALSE;
gtk_widget_set_sensitive(bt_decode, decode);
gtk_widget_set_sensitive(cb_use_jitter_buffer, decode);
gtk_widget_set_sensitive(cb_use_rtp_timestamp, decode);
gtk_widget_set_sensitive(cb_use_uninterrupted_mode, decode);
gtk_widget_set_sensitive(cb_view_as_time_of_day, decode);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_use_jitter_buffer))) {
gtk_widget_set_sensitive(jitter_spinner, decode);
} else {
gtk_widget_set_sensitive(jitter_spinner, FALSE);
}
if (new_jitter_buff != (int) gtk_spin_button_get_value((GtkSpinButton * )jitter_spinner)) {
new_jitter_value = TRUE;
}
if ( play_state && (rtp_channels->rci[0] || rtp_channels->rci[1]) && !new_jitter_value) {
gtk_widget_set_sensitive(bt_play, TRUE);
} else {
gtk_widget_set_sensitive(bt_play, FALSE);
}
if (!new_jitter_value) {
gtk_widget_set_sensitive(bt_pause, pause_state);
gtk_widget_set_sensitive(bt_stop, stop_state);
if (rtp_channels_hash)
g_hash_table_foreach( rtp_channels_hash, (GHFunc)set_sensitive_check_bt, &stop_state);
} else {
gtk_widget_set_sensitive(bt_pause, FALSE);
gtk_widget_set_sensitive(bt_stop, FALSE);
if (rtp_channels_hash)
g_hash_table_foreach( rtp_channels_hash, (GHFunc)set_sensitive_check_bt, &false_val);
}
}
void
add_rtp_packet(const struct _rtp_info *rtp_info, packet_info *pinfo)
{
rtp_stream_info_t *stream_info = NULL;
rtp_packet_t *new_rtp_packet;
GString *key_str = NULL;
if (!rtp_streams_hash)
rtp_streams_hash = g_hash_table_new_full( g_str_hash, g_str_equal, rtp_key_destroy, rtp_stream_value_destroy);
key_str = g_string_new("");
g_string_printf(key_str, "%s:%d %s:%d %d", address_to_display(pinfo->pool, &(pinfo->src)),
pinfo->srcport, address_to_display(pinfo->pool, &(pinfo->dst)),
pinfo->destport, rtp_info->info_sync_src );
stream_info = (rtp_stream_info_t *)g_hash_table_lookup( rtp_streams_hash, key_str->str);
if (stream_info==NULL) {
stream_info = g_new0(rtp_stream_info_t, 1);
copy_address(&(stream_info->src_addr), &(pinfo->src));
stream_info->src_port = pinfo->srcport;
copy_address(&(stream_info->dest_addr), &(pinfo->dst));
stream_info->dest_port = pinfo->destport;
stream_info->ssrc = rtp_info->info_sync_src;
stream_info->start_fd = pinfo->fd;
stream_info->start_rel_time = pinfo->rel_ts;
g_hash_table_insert(rtp_streams_hash, g_strdup(key_str->str), stream_info);
rtp_streams_list = g_list_append(rtp_streams_list, stream_info);
}
stream_info->packet_count++;
new_rtp_packet = g_new0(rtp_packet_t, 1);
new_rtp_packet->info = (struct _rtp_info *)g_malloc(sizeof(struct _rtp_info));
memcpy(new_rtp_packet->info, rtp_info, sizeof(struct _rtp_info));
new_rtp_packet->arrive_offset = nstime_to_msec(&pinfo->rel_ts) - nstime_to_msec(&stream_info->start_rel_time);
if (rtp_info->info_all_data_present && (rtp_info->info_payload_len != 0)) {
new_rtp_packet->payload_data = (guint8 *)g_malloc(rtp_info->info_payload_len);
memcpy(new_rtp_packet->payload_data, &(rtp_info->info_data[rtp_info->info_payload_offset]), rtp_info->info_payload_len);
} else {
new_rtp_packet->payload_data = NULL;
}
stream_info->rtp_packet_list = g_list_append(stream_info->rtp_packet_list, new_rtp_packet);
g_string_free(key_str, TRUE);
}
static void
mark_rtp_stream_to_play(gchar *key _U_ , rtp_stream_info_t *rsi, gpointer ptr _U_)
{
GList* graph_list;
seq_analysis_item_t *graph_item;
GList* voip_calls_list;
voip_calls_info_t *tmp_voip_call;
rsi->decode = FALSE;
graph_list = g_queue_peek_nth_link(voip_calls->graph_analysis->items, 0);
while (graph_list)
{
graph_item = (seq_analysis_item_t *)graph_list->data;
if (rsi->start_fd->num == graph_item->frame_number) {
rsi->call_num = graph_item->conv_num;
voip_calls_list = g_queue_peek_nth_link(voip_calls->callsinfos, 0);
while (voip_calls_list)
{
tmp_voip_call = (voip_calls_info_t *)voip_calls_list->data;
if ( (tmp_voip_call->call_num == rsi->call_num) && (tmp_voip_call->selected == TRUE) ) {
rsi->decode = TRUE;
total_packets += rsi->packet_count;
break;
}
voip_calls_list = g_list_next(voip_calls_list);
}
break;
}
graph_list = g_list_next(graph_list);
}
}
static void
mark_all_rtp_stream_to_decode(gchar *key _U_ , rtp_stream_info_t *rsi, gpointer ptr _U_)
{
rsi->decode = TRUE;
total_packets += rsi->packet_count;
}
static void
update_progress_bar(gfloat fraction)
{
if (GTK_IS_PROGRESS_BAR(progress_bar))
gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), fraction);
while (gtk_events_pending())
gtk_main_iteration();
}
static void
decode_rtp_stream(rtp_stream_info_t *rsi, gpointer ptr)
{
GString *key_str = NULL;
rtp_channel_info_t *rci;
gboolean first = TRUE;
GList* rtp_packet_list;
rtp_packet_t *rp;
size_t i;
gint32 j;
double rtp_time;
double rtp_time_prev;
double arrive_time;
double arrive_time_prev;
double start_time;
double start_rtp_time = 0;
double diff;
double pack_period;
gint32 silence_frames;
int seq;
#ifdef DEBUG
double total_time;
double mean_delay;
double variation;
#endif
char *src_addr, *dst_addr;
size_t decoded_bytes;
size_t decoded_bytes_prev;
int jitter_buff;
SAMPLE *out_buff = NULL;
sample_t silence;
sample_t sample;
nstime_t sample_delta;
guint8 status;
guint32 start_timestamp;
GHashTable *decoders_hash = NULL;
guint32 progbar_nextstep;
int progbar_quantum;
gfloat progbar_val;
data_info *info = (data_info *) ptr;
silence.val = 0;
silence.status = S_NORMAL;
if (rsi->decode == FALSE) {
return;
}
jitter_buff = (int) gtk_spin_button_get_value((GtkSpinButton * )jitter_spinner);
key_str = g_string_new("");
src_addr = address_to_display(NULL, &(rsi->src_addr));
dst_addr = address_to_display(NULL, &(rsi->dest_addr));
g_string_printf(key_str, "%s:%d %s:%d %d %u", src_addr,
rsi->src_port, dst_addr,
rsi->dest_port, rsi->call_num, info->current_channel);
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
if (!rtp_channels_hash) {
rtp_channels_hash = g_hash_table_new_full( g_str_hash, g_str_equal, rtp_key_destroy, rtp_channel_value_destroy);
}
rci = (rtp_channel_info_t *)g_hash_table_lookup( rtp_channels_hash, key_str->str);
if (rci == NULL) {
rci = g_new0(rtp_channel_info_t, 1);
rci->call_num = rsi->call_num;
rci->start_time_abs = rsi->start_fd->abs_ts;
rci->stop_time_abs = rsi->start_fd->abs_ts;
rci->samples = g_array_new (FALSE, FALSE, sizeof(sample_t));
rci->first_stream = rsi;
rci->num_packets = rsi->packet_count;
g_hash_table_insert(rtp_channels_hash, g_strdup(key_str->str), rci);
} else {
silence_frames = (gint32)((nstime_to_msec(&rsi->start_fd->abs_ts) - nstime_to_msec(&rci->stop_time_abs)) * sample_rate);
for (j = 0; j < silence_frames; j++) {
g_array_append_val(rci->samples, silence);
}
rci->num_packets += rsi->packet_count;
}
first = TRUE;
rtp_time_prev = 0;
decoded_bytes_prev = 0;
start_time = 0;
arrive_time_prev = 0;
pack_period = 0;
#ifdef DEBUG
total_time = 0;
mean_delay = 0;
variation = 0;
#endif
seq = 0;
start_timestamp = 0;
decoders_hash = rtp_decoder_hash_table_new();
progbar_nextstep = 0;
progbar_quantum = total_packets/100;
status = S_NORMAL;
rtp_packet_list = g_list_first(rsi->rtp_packet_list);
while (rtp_packet_list)
{
if (progbar_count >= progbar_nextstep) {
g_assert(total_packets > 0);
progbar_val = (gfloat) progbar_count / total_packets;
update_progress_bar(progbar_val);
progbar_nextstep += progbar_quantum;
}
rp = (rtp_packet_t *)rtp_packet_list->data;
if (first == TRUE) {
start_timestamp = rp->info->info_timestamp;
start_rtp_time = 0;
rtp_time_prev = start_rtp_time;
first = FALSE;
seq = rp->info->info_seq_num - 1;
}
decoded_bytes = decode_rtp_packet(rp, &out_buff, decoders_hash, &channels, &sample_rate);
if (decoded_bytes == 0) {
seq = rp->info->info_seq_num;
}
rtp_time = (double)(rp->info->info_timestamp-start_timestamp)/sample_rate - start_rtp_time;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_use_rtp_timestamp))) {
arrive_time = rtp_time;
} else {
arrive_time = (double)rp->arrive_offset/1000 - start_time;
}
if (rp->info->info_seq_num != seq+1){
rci->out_of_seq++;
status = S_WRONG_SEQ;
}
seq = rp->info->info_seq_num;
diff = arrive_time - rtp_time;
if (diff<0) diff = -diff;
#ifdef DEBUG
total_time = (double)rp->arrive_offset/1000;
printf("seq = %d arr = %f abs_diff = %f index = %d tim = %f ji=%d jb=%f\n",rp->info->info_seq_num,
total_time, diff, rci->samples->len, ((double)rci->samples->len / sample_rate - total_time) * 1000, 0,
(mean_delay + 4 * variation) * 1000);
fflush(stdout);
#endif
if ( diff*1000 > jitter_buff && !gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_use_uninterrupted_mode))) {
#ifdef DEBUG
printf("Packet drop by jitter buffer exceeded\n");
#endif
rci->drop_by_jitter_buff++;
status = S_DROP_BY_JITT;
if ( (rtp_time - rtp_time_prev) > pack_period*2 ){
#ifdef DEBUG
printf("Resync...\n");
#endif
silence_frames = (gint32)((arrive_time - arrive_time_prev)*sample_rate - decoded_bytes_prev / sizeof(SAMPLE));
#define MAX_SILENCE_FRAMES 240000
if (silence_frames > MAX_SILENCE_FRAMES)
silence_frames = MAX_SILENCE_FRAMES;
for (j = 0; j < silence_frames; j++) {
silence.status = status;
g_array_append_val(rci->samples, silence);
status = S_NORMAL;
}
decoded_bytes_prev = 0;
start_timestamp = rp->info->info_timestamp;
start_rtp_time = 0;
start_time = (double)rp->arrive_offset/1000;
rtp_time_prev = 0;
}
} else {
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_use_uninterrupted_mode))) {
silence_frames = 0;
} else {
silence_frames = (gint32)((rtp_time - rtp_time_prev)*sample_rate - decoded_bytes_prev / sizeof(SAMPLE));
}
if (silence_frames != 0) {
rci->wrong_timestamp++;
status = S_WRONG_TIMESTAMP;
}
if (silence_frames > MAX_SILENCE_FRAMES)
silence_frames = MAX_SILENCE_FRAMES;
for (j = 0; j < silence_frames; j++) {
silence.status = status;
g_array_append_val(rci->samples, silence);
status = S_NORMAL;
}
if (silence_frames > 0) {
silence_frames = 0;
}
for (i = -silence_frames + ((info->current_channel) ? 1 : 0); i < decoded_bytes / (int) sizeof(SAMPLE); i += channels) {
if(out_buff)
sample.val = out_buff[i];
sample.status = status;
g_array_append_val(rci->samples, sample);
status = S_NORMAL;
}
rtp_time_prev = rtp_time;
pack_period = (double) decoded_bytes / sizeof(SAMPLE) / sample_rate;
decoded_bytes_prev = decoded_bytes;
arrive_time_prev = arrive_time;
}
if (out_buff) {
g_free(out_buff);
out_buff = NULL;
}
rtp_packet_list = g_list_next (rtp_packet_list);
progbar_count++;
}
rci->max_frame_index = rci->samples->len;
sample_delta.secs = rci->samples->len / sample_rate;
sample_delta.nsecs = (rci->samples->len % sample_rate) * 1000000000;
nstime_sum(&rci->stop_time_abs, &rci->start_time_abs, &sample_delta);
g_string_free(key_str, TRUE);
g_hash_table_destroy(decoders_hash);
}
static PaTime
getMonoTime(PaStream *stream _U_)
{
#if GLIB_CHECK_VERSION(2, 28, 0)
return g_get_monotonic_time() * 1e-6;
#else
return Pa_GetStreamTime(stream);
#endif
}
static gint
h_scrollbar_changed(GtkWidget *widget _U_, gpointer user_data)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)user_data;
rci->cursor_catch = TRUE;
return TRUE;
}
static void
stop_channels(void)
{
PaError err;
GtkWidget *dialog;
g_assert(rtp_channels->stop == FALSE);
rtp_channels->stop = TRUE;
draw_cursors(NULL);
err = Pa_StopStream(pa_stream);
if( err != paNoError ) {
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not Stop Stream in PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
return;
}
err = Pa_CloseStream(pa_stream);
if( err != paNoError ) {
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not Close Stream in PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
return;
}
pa_stream = NULL;
rtp_channels->start_index[0] = 0;
rtp_channels->start_index[1] = 0;
rtp_channels->end_index[0] = 0;
rtp_channels->end_index[1] = 0;
rtp_channels->max_frame_index = 0;
rtp_channels->frame_index = 0;
rtp_channels->pause = FALSE;
rtp_channels->pause_duration = 0;
rtp_channels->stop = TRUE;
rtp_channels->out_diff_time = 10000;
if (rtp_channels->rci[0]) rtp_channels->rci[0]->frame_index = 0;
if (rtp_channels->rci[1]) rtp_channels->rci[1]->frame_index = 0;
bt_state(TRUE, TRUE, FALSE, FALSE);
}
static void
draw_channel_cursor(rtp_channel_info_t *rci, guint32 start_index)
{
#if PORTAUDIO_API_1
PaTimestamp idx;
#else
PaTime idx;
#endif
int i;
GtkAllocation widget_alloc;
cairo_t *cr;
if (!rci || !pa_stream) return;
#if PORTAUDIO_API_1
idx = Pa_StreamTime( pa_stream ) - rtp_channels->pause_duration - rtp_channels->out_diff_time - start_index;
#else
idx = (guint32) sample_rate
* (getCurrentTime(pa_stream) - rtp_channels->pa_start_time
- rtp_channels->out_diff_time);
idx -= rtp_channels->pause_duration;
idx -= start_index;
#endif
if ( (rtp_channels && (!rtp_channels->stop) && (!rtp_channels->pause)) && (idx > rtp_channels->max_frame_index) ) {
stop_channels();
return;
}
if (idx > rci->max_frame_index) {
return;
}
gtk_widget_get_allocation(rci->draw_area, &widget_alloc);
if (rci->cursor_pixbuf && (rci->cursor_prev>=0)) {
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (rci->surface);
#else
cr = gdk_cairo_create (rci->pixmap);
#endif
gdk_cairo_set_source_pixbuf (cr, rci->cursor_pixbuf, 0, 0);
cairo_pattern_set_extend (cairo_get_source (cr), CAIRO_EXTEND_REPEAT);
cairo_rectangle (cr, rci->cursor_prev/MULT, 0, -1, -1);
cairo_fill (cr);
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface (cr, rci->surface, idx/MULT, 0);
#else
gdk_cairo_set_source_pixmap (cr, rci->pixmap,idx/MULT, 0);
#endif
cairo_pattern_set_extend (cairo_get_source (cr), CAIRO_EXTEND_REPEAT);
cairo_rectangle (cr, rci->cursor_prev/MULT, 0, 1, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_fill (cr);
cairo_destroy (cr);
g_object_unref(rci->cursor_pixbuf);
rci->cursor_pixbuf = NULL;
}
if (idx>0 && (rci->cursor_prev>=0)) {
#if GTK_CHECK_VERSION(2,22,0)
rci->cursor_pixbuf = gdk_pixbuf_get_from_surface (rci->surface,0, 0, 1, widget_alloc.height-HEIGHT_TIME_LABEL);
cr = cairo_create (rci->surface);
#else
rci->cursor_pixbuf = gdk_pixbuf_get_from_drawable(NULL, rci->pixmap, NULL, (int) (idx/MULT), 0, 0, 0, 1, widget_alloc.height-HEIGHT_TIME_LABEL);
cr = gdk_cairo_create (rci->pixmap);
#endif
if (cr != NULL) {
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, idx/MULT, 0);
cairo_line_to(cr, idx/MULT, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_stroke(cr);
cairo_destroy(cr);
}
cr = gdk_cairo_create (gtk_widget_get_window(rci->draw_area));
if (cr != NULL) {
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface (cr, rci->surface, idx/MULT, 0);
#else
gdk_cairo_set_source_pixmap (cr, rci->pixmap, idx/MULT, 0);
#endif
cairo_pattern_set_extend (cairo_get_source (cr), CAIRO_EXTEND_REPEAT);
cairo_rectangle (cr, idx/MULT, 0, 1, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_fill (cr);
cairo_destroy (cr);
}
}
g_signal_handlers_disconnect_by_func(rci->h_scrollbar_adjustment, h_scrollbar_changed, rci);
#if 0
if ( (rci->cursor_prev/MULT < (rci->h_scrollbar_adjustment->value+rci->h_scrollbar_adjustment->page_increment)) &&
(idx/MULT >= (rci->h_scrollbar_adjustment->value+rci->h_scrollbar_adjustment->page_increment)) ){
for (i=1; i<10; i++) {
rci->h_scrollbar_adjustment->value += rci->h_scrollbar_adjustment->page_size/10;
gtk_adjustment_value_changed(rci->h_scrollbar_adjustment);
}
}
#endif
if (!rci->cursor_catch) {
if (idx/MULT < gtk_adjustment_get_page_size(rci->h_scrollbar_adjustment)/2) {
gtk_adjustment_set_value(rci->h_scrollbar_adjustment, gtk_adjustment_get_lower(rci->h_scrollbar_adjustment));
} else if (idx/MULT > (gtk_adjustment_get_upper(rci->h_scrollbar_adjustment) - gtk_adjustment_get_page_size(rci->h_scrollbar_adjustment)/2)) {
gtk_adjustment_set_value(rci->h_scrollbar_adjustment, gtk_adjustment_get_upper(rci->h_scrollbar_adjustment) - gtk_adjustment_get_page_size(rci->h_scrollbar_adjustment));
} else {
gtk_adjustment_set_value(rci->h_scrollbar_adjustment, idx/MULT - gtk_adjustment_get_page_size(rci->h_scrollbar_adjustment)/2);
}
gtk_adjustment_value_changed(rci->h_scrollbar_adjustment);
} else if ( (rci->cursor_prev/MULT < gtk_adjustment_get_value(rci->h_scrollbar_adjustment)+gtk_adjustment_get_page_increment(rci->h_scrollbar_adjustment)) &&
(idx/MULT >= gtk_adjustment_get_value(rci->h_scrollbar_adjustment) + gtk_adjustment_get_page_increment(rci->h_scrollbar_adjustment)) ){
rci->cursor_catch = FALSE;
for (i=1; i<10; i++) {
gtk_adjustment_set_value(rci->h_scrollbar_adjustment, MIN(gtk_adjustment_get_upper(rci->h_scrollbar_adjustment)-gtk_adjustment_get_page_size(rci->h_scrollbar_adjustment), gtk_adjustment_get_value(rci->h_scrollbar_adjustment) + gtk_adjustment_get_page_size(rci->h_scrollbar_adjustment)/20));
gtk_adjustment_value_changed(rci->h_scrollbar_adjustment);
}
}
g_signal_connect(rci->h_scrollbar_adjustment, "value_changed", G_CALLBACK(h_scrollbar_changed), rci);
#if 0
if (idx/MULT < rci->h_scrollbar_adjustment->page_increment) {
rci->h_scrollbar_adjustment->value = rci->h_scrollbar_adjustment->lower;
} else if (idx/MULT > (rci->h_scrollbar_adjustment->upper - rci->h_scrollbar_adjustment->page_size + rci->h_scrollbar_adjustment->page_increment)) {
rci->h_scrollbar_adjustment->value = rci->h_scrollbar_adjustment->upper - rci->h_scrollbar_adjustment->page_size;
} else {
if ( (idx/MULT < rci->h_scrollbar_adjustment->value) || (idx/MULT > (rci->h_scrollbar_adjustment->value+rci->h_scrollbar_adjustment->page_increment)) ){
rci->h_scrollbar_adjustment->value = idx/MULT;
}
}
#endif
#if 0
if (idx/MULT < rci->h_scrollbar_adjustment->page_size/2) {
rci->h_scrollbar_adjustment->value = rci->h_scrollbar_adjustment->lower;
} else if (idx/MULT > (rci->h_scrollbar_adjustment->upper - rci->h_scrollbar_adjustment->page_size/2)) {
rci->h_scrollbar_adjustment->value = rci->h_scrollbar_adjustment->upper - rci->h_scrollbar_adjustment->page_size;
} else {
rci->h_scrollbar_adjustment->value = idx/MULT - rci->h_scrollbar_adjustment->page_size/2;
}
#endif
#if 0
gtk_adjustment_value_changed(rci->h_scrollbar_adjustment);
#endif
rci->cursor_prev = idx;
}
static gboolean
draw_cursors(gpointer data _U_)
{
if (!rtp_channels) return FALSE;
draw_channel_cursor(rtp_channels->rci[0], rtp_channels->start_index[0]);
draw_channel_cursor(rtp_channels->rci[1], rtp_channels->start_index[1]);
if ((rtp_channels->stop) || (rtp_channels->pause)) return FALSE;
return TRUE;
}
static void
init_rtp_channels_vals(void)
{
rtp_play_channels_t *rpci = rtp_channels;
if (rpci->rci[0] == NULL) {
rpci->max_frame_index = rpci->rci[1] ? rpci->rci[1]->max_frame_index: 0;
rpci->start_index[0] = rpci->max_frame_index;
rpci->start_index[1] = 0;
rpci->end_index[0] = rpci->max_frame_index;
rpci->end_index[1] = rpci->max_frame_index;
} else if (rpci->rci[1] == NULL) {
rpci->max_frame_index = rpci->rci[0]->max_frame_index;
rpci->start_index[1] = rpci->max_frame_index;
rpci->start_index[0] = 0;
rpci->end_index[0] = rpci->max_frame_index;
rpci->end_index[1] = rpci->max_frame_index;
} else {
double start_time_0 = nstime_to_msec(&rpci->rci[0]->start_time_abs);
double start_time_1 = nstime_to_msec(&rpci->rci[1]->start_time_abs);
double stop_time_0 = nstime_to_msec(&rpci->rci[0]->stop_time_abs);
double stop_time_1 = nstime_to_msec(&rpci->rci[1]->stop_time_abs);
rpci->max_frame_index = (guint32)(sample_rate/1000) * (guint32)(MAX(stop_time_0, stop_time_1) -
(guint32)MIN(start_time_0, start_time_1));
if (nstime_cmp(&rpci->rci[0]->start_time_abs, &rpci->rci[1]->start_time_abs) < 0) {
rpci->start_index[0] = 0;
rpci->start_index[1] = (guint32)(sample_rate/1000) * (guint32)(start_time_1 - start_time_0);
} else {
rpci->start_index[1] = 0;
rpci->start_index[0] = (guint32)(sample_rate/1000) * (guint32)(start_time_0 - start_time_1);
}
if (nstime_cmp(&rpci->rci[0]->stop_time_abs, &rpci->rci[1]->stop_time_abs) < 0) {
rpci->end_index[0] = rpci->max_frame_index - ((guint32)(sample_rate/1000) * (guint32)(stop_time_1 - stop_time_0));
rpci->end_index[1] = rpci->max_frame_index;
} else {
rpci->end_index[1] = rpci->max_frame_index - ((guint32)(sample_rate/1000) * (guint32)(stop_time_0 - stop_time_1));
rpci->end_index[0] = rpci->max_frame_index;
}
}
}
static int paCallback( const void *inputBuffer _U_, void *outputBuffer,
unsigned long framesPerBuffer,
const PaStreamCallbackTimeInfo* outTime,
PaStreamCallbackFlags statusFlags _U_,
void *userData)
{
#endif
rtp_play_channels_t *rpci = (rtp_play_channels_t *)userData;
SAMPLE *wptr = (SAMPLE*)outputBuffer;
sample_t sample;
unsigned long i;
int finished;
unsigned long framesLeft;
unsigned long framesToPlay;
if (rtp_channels->pause) {
for(i=0; i<framesPerBuffer; i++ ) {
*wptr++ = 0;
*wptr++ = 0;
}
rtp_channels->pause_duration += framesPerBuffer;
return 0;
}
#if PORTAUDIO_API_1
rpci->out_diff_time = outTime - Pa_StreamTime(pa_stream);
#else
rpci->out_diff_time = outTime->outputBufferDacTime - outTime->currentTime;
#endif
if (rpci->max_frame_index == 0) {
init_rtp_channels_vals();
}
framesLeft = rpci->max_frame_index - rpci->frame_index;
if( framesLeft < framesPerBuffer )
{
framesToPlay = framesLeft;
finished = 1;
}
else
{
framesToPlay = framesPerBuffer;
finished = 0;
}
for( i=0; i<(unsigned int)framesToPlay; i++ )
{
if (rpci->rci[0] && ( (rpci->frame_index >= rpci->start_index[0]) && (rpci->frame_index <= rpci->end_index[0]) )) {
sample = g_array_index(rpci->rci[0]->samples, sample_t, rpci->rci[0]->frame_index++);
*wptr++ = sample.val;
} else {
*wptr++ = 0;
}
if (rpci->rci[1] && ( (rpci->frame_index >= rpci->start_index[1]) && (rpci->frame_index <= rpci->end_index[1]) )) {
sample = g_array_index(rpci->rci[1]->samples, sample_t, rpci->rci[1]->frame_index++);
*wptr++ = sample.val;
} else {
*wptr++ = 0;
}
}
for( ; i<framesPerBuffer; i++ )
{
*wptr++ = 0;
*wptr++ = 0;
}
rpci->frame_index += framesToPlay;
return finished;
}
static void
on_bt_check_clicked(GtkButton *button _U_, gpointer user_data)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)user_data;
if (rci->selected) {
if (rtp_channels->rci[0] == rci) {
rtp_channels->rci[0] = NULL;
rtp_channels->channel = 0;
} else {
rtp_channels->rci[1] = NULL;
rtp_channels->channel = 1;
}
} else {
if (rtp_channels->rci[rtp_channels->channel]) {
g_signal_handlers_disconnect_by_func(rtp_channels->rci[rtp_channels->channel]->check_bt, on_bt_check_clicked, rtp_channels->rci[rtp_channels->channel]);
gtk_toggle_button_set_active((GtkToggleButton *)rtp_channels->rci[rtp_channels->channel]->check_bt, FALSE);
g_signal_connect(rtp_channels->rci[rtp_channels->channel]->check_bt, "clicked", G_CALLBACK(on_bt_check_clicked), rtp_channels->rci[rtp_channels->channel]);
rtp_channels->rci[rtp_channels->channel]->selected = FALSE;
}
rtp_channels->rci[rtp_channels->channel] = rci;
rtp_channels->channel = !(rtp_channels->channel);
}
rci->selected = !(rci->selected);
bt_state(TRUE, TRUE, FALSE, FALSE);
}
static void
channel_draw(rtp_channel_info_t *rci)
{
int i, imax;
int j;
sample_t sample;
SAMPLE min, max;
PangoLayout *small_layout;
guint32 label_width, label_height;
char label_string[MAX_TIME_LABEL];
double offset;
guint32 progbar_nextstep;
int progbar_quantum;
gfloat progbar_val;
guint status;
GdkRGBA red_color = {1.0, 0.0, 0.1, 1.0};
GdkRGBA amber_color = {1.0, 0.75, 0.0, 1.0};
GdkRGBA white_color = {1.0, 1.0, 1.0, 1.0 };
GdkRGBA black_color = {0.0, 0.0, 0.0, 1.0};
GdkRGBA *draw_color_p;
time_t seconds;
struct tm *timestamp;
GtkAllocation widget_alloc;
cairo_t *cr;
#if GTK_CHECK_VERSION(2,22,0)
gtk_widget_get_allocation(rci->draw_area, &widget_alloc);
cr = cairo_create (rci->surface);
gdk_cairo_set_source_rgba (cr, &rci->bg_color[1+rci->call_num%MAX_NUM_COL_CONV]);
cairo_rectangle (cr, 0, 0, widget_alloc.width,widget_alloc.height);
cairo_fill (cr);
cairo_destroy (cr);
cr = NULL;
small_layout = gtk_widget_create_pango_layout(rci->draw_area, NULL);
pango_layout_set_font_description(small_layout, pango_font_description_from_string("Helvetica,Sans,Bold 7"));
offset = (nstime_to_sec(&rci->start_time_abs) - floor(nstime_to_sec(&rci->start_time_abs)))*sample_rate/MULT;
cr = cairo_create (rci->surface);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, 0, widget_alloc.height-HEIGHT_TIME_LABEL+0.5);
cairo_line_to(cr, widget_alloc.width, widget_alloc.height-HEIGHT_TIME_LABEL+0.5);
cairo_stroke(cr);
cairo_destroy(cr);
cr = NULL;
imax = MIN(widget_alloc.width,(gint)(rci->samples->len/MULT));
progbar_nextstep = 0;
progbar_quantum = imax/100;
for (i=0; i< imax; i++) {
sample.val = 0;
status = S_NORMAL;
max=(SAMPLE)0xFFFF;
min=(SAMPLE)0x7FFF;
if (progbar_count >= progbar_nextstep) {
g_assert(total_frames > 0);
progbar_val = (gfloat) i / imax;
update_progress_bar(progbar_val);
progbar_nextstep += progbar_quantum;
}
for (j=0; j<MULT; j++) {
sample = g_array_index(rci->samples, sample_t, i*MULT+j);
max = MAX(max, sample.val);
min = MIN(min, sample.val);
if (sample.status == S_DROP_BY_JITT) status = S_DROP_BY_JITT;
if (sample.status == S_WRONG_TIMESTAMP) status = S_WRONG_TIMESTAMP;
if (sample.status == S_SILENCE) status = S_SILENCE;
}
if (status == S_DROP_BY_JITT) {
draw_color_p = &red_color;
} else if (status == S_WRONG_TIMESTAMP) {
draw_color_p = &amber_color;
} else if (status == S_SILENCE) {
draw_color_p = &white_color;
} else {
draw_color_p = &black_color;
}
if ((status == S_DROP_BY_JITT) || (status == S_WRONG_TIMESTAMP) || (status == S_SILENCE)) {
cr = cairo_create (rci->surface);
cairo_set_line_width (cr, 1.0);
gdk_cairo_set_source_rgba (cr, draw_color_p);
cairo_move_to(cr, i+0.5, 0);
cairo_line_to(cr, i+0.5, (widget_alloc.height-HEIGHT_TIME_LABEL)-1);
cairo_stroke(cr);
cairo_destroy(cr);
cr=NULL;
if (status == S_DROP_BY_JITT) g_snprintf(label_string, MAX_TIME_LABEL,"D");
if (status == S_WRONG_TIMESTAMP) g_snprintf(label_string, MAX_TIME_LABEL, "W");
if (status == S_SILENCE) g_snprintf(label_string, MAX_TIME_LABEL, "S");
pango_layout_set_text(small_layout, label_string, -1);
pango_layout_get_pixel_size(small_layout, &label_width, &label_height);
cr = cairo_create (rci->surface);
gdk_cairo_set_source_rgba (cr, draw_color_p);
cairo_move_to (cr, i, 0);
pango_cairo_show_layout (cr, small_layout);
cairo_destroy (cr);
cr = NULL;
} else {
cr = cairo_create (rci->surface);
cairo_set_line_width (cr, 1.0);
gdk_cairo_set_source_rgba (cr, draw_color_p);
cairo_move_to(cr, i+0.5, ( (0x7FFF+min) * (widget_alloc.height-HEIGHT_TIME_LABEL))/0xFFFF);
cairo_line_to(cr, i+0.5, ( (0x7FFF+max) * (widget_alloc.height-HEIGHT_TIME_LABEL))/0xFFFF);
cairo_stroke(cr);
cairo_destroy(cr);
}
if ( !((i*MULT)%(sample_rate)) ) {
cr = cairo_create (rci->surface);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, i - offset+0.5, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_line_to(cr, i+0.5, widget_alloc.height-HEIGHT_TIME_LABEL+4);
cairo_stroke(cr);
cairo_destroy(cr);
cr=NULL;
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_view_as_time_of_day))) {
seconds = rci->start_time_abs.secs + i * MULT / sample_rate;
timestamp = localtime(&seconds);
g_snprintf(label_string, MAX_TIME_LABEL, "%02d:%02d:%02d", timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec);
} else {
g_snprintf(label_string, MAX_TIME_LABEL, "%.0f s", floor(nstime_to_sec(&rci->start_time_abs)) + i*MULT/sample_rate);
}
pango_layout_set_text(small_layout, label_string, -1);
pango_layout_get_pixel_size(small_layout, &label_width, &label_height);
cr = cairo_create (rci->surface);
cairo_move_to (cr, i - offset - label_width/2, widget_alloc.height - label_height);
pango_cairo_show_layout (cr, small_layout);
cairo_destroy (cr);
cr = NULL;
} else if ( !((i*MULT)%(sample_rate/2)) ) {
cr = cairo_create (rci->surface);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr,i - offset+0.5, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_line_to(cr, (i - offset)+0.5, widget_alloc.height-HEIGHT_TIME_LABEL+2);
cairo_stroke(cr);
cairo_destroy(cr);
cr=NULL;
}
progbar_count++;
}
g_object_unref(G_OBJECT(small_layout));
#else
if (GDK_IS_DRAWABLE(rci->pixmap)) {
gtk_widget_get_allocation(rci->draw_area, &widget_alloc);
cr = gdk_cairo_create (rci->pixmap);
gdk_cairo_set_source_rgba (cr, &rci->bg_color[1+rci->call_num%MAX_NUM_COL_CONV]);
cairo_rectangle (cr, 0, 0, widget_alloc.width,widget_alloc.height);
cairo_fill (cr);
cairo_destroy (cr);
cr = NULL;
small_layout = gtk_widget_create_pango_layout(rci->draw_area, NULL);
pango_layout_set_font_description(small_layout, pango_font_description_from_string("Helvetica,Sans,Bold 7"));
offset = (nstime_to_sec(&rci->start_time_abs) - floor(nstime_to_sec(&rci->start_time_abs)))*sample_rate/MULT;
cr = gdk_cairo_create (rci->pixmap);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, 0, widget_alloc.height-HEIGHT_TIME_LABEL+0.5);
cairo_line_to(cr, widget_alloc.width, widget_alloc.height-HEIGHT_TIME_LABEL+0.5);
cairo_stroke(cr);
cairo_destroy(cr);
cr = NULL;
imax = MIN(widget_alloc.width,(gint)(rci->samples->len/MULT));
progbar_nextstep = 0;
progbar_quantum = imax/100;
for (i=0; i< imax; i++) {
sample.val = 0;
status = S_NORMAL;
max=(SAMPLE)0xFFFF;
min=(SAMPLE)0x7FFF;
if (progbar_count >= progbar_nextstep) {
g_assert(total_frames > 0);
progbar_val = (gfloat) i / imax;
update_progress_bar(progbar_val);
progbar_nextstep += progbar_quantum;
}
for (j=0; j<MULT; j++) {
sample = g_array_index(rci->samples, sample_t, i*MULT+j);
max = MAX(max, sample.val);
min = MIN(min, sample.val);
if (sample.status == S_DROP_BY_JITT) status = S_DROP_BY_JITT;
if (sample.status == S_WRONG_TIMESTAMP) status = S_WRONG_TIMESTAMP;
if (sample.status == S_SILENCE) status = S_SILENCE;
}
if (status == S_DROP_BY_JITT) {
draw_color_p = &red_color;
} else if (status == S_WRONG_TIMESTAMP) {
draw_color_p = &amber_color;
} else if (status == S_SILENCE) {
draw_color_p = &white_color;
} else {
draw_color_p = &black_color;
}
if ((status == S_DROP_BY_JITT) || (status == S_WRONG_TIMESTAMP) || (status == S_SILENCE)) {
cr = gdk_cairo_create (rci->pixmap);
cairo_set_line_width (cr, 1.0);
gdk_cairo_set_source_rgba (cr, draw_color_p);
cairo_move_to(cr, i+0.5, 0);
cairo_line_to(cr, i+0.5, (widget_alloc.height-HEIGHT_TIME_LABEL)-1);
cairo_stroke(cr);
cairo_destroy(cr);
cr=NULL;
if (status == S_DROP_BY_JITT) g_snprintf(label_string, MAX_TIME_LABEL,"D");
if (status == S_WRONG_TIMESTAMP) g_snprintf(label_string, MAX_TIME_LABEL, "W");
if (status == S_SILENCE) g_snprintf(label_string, MAX_TIME_LABEL, "S");
pango_layout_set_text(small_layout, label_string, -1);
pango_layout_get_pixel_size(small_layout, &label_width, &label_height);
cr = gdk_cairo_create (rci->pixmap);
gdk_cairo_set_source_rgba (cr, draw_color_p);
cairo_move_to (cr, i, 0);
pango_cairo_show_layout (cr, small_layout);
cairo_destroy (cr);
cr = NULL;
} else {
cr = gdk_cairo_create (rci->pixmap);
cairo_set_line_width (cr, 1.0);
gdk_cairo_set_source_rgba (cr, draw_color_p);
cairo_move_to(cr, i+0.5, ( (0x7FFF+min) * (widget_alloc.height-HEIGHT_TIME_LABEL))/0xFFFF);
cairo_line_to(cr, i+0.5, ( (0x7FFF+max) * (widget_alloc.height-HEIGHT_TIME_LABEL))/0xFFFF);
cairo_stroke(cr);
cairo_destroy(cr);
}
if ( !((i*MULT)%(sample_rate)) ) {
cr = gdk_cairo_create (rci->pixmap);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, i - offset+0.5, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_line_to(cr, i+0.5, widget_alloc.height-HEIGHT_TIME_LABEL+4);
cairo_stroke(cr);
cairo_destroy(cr);
cr=NULL;
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_view_as_time_of_day))) {
seconds = rci->start_time_abs.secs + i * MULT / sample_rate;
timestamp = localtime(&seconds);
g_snprintf(label_string, MAX_TIME_LABEL, "%02d:%02d:%02d", timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec);
} else {
g_snprintf(label_string, MAX_TIME_LABEL, "%.0f s", floor(nstime_to_sec(&rci->start_time_abs)) + i*MULT/sample_rate);
}
pango_layout_set_text(small_layout, label_string, -1);
pango_layout_get_pixel_size(small_layout, &label_width, &label_height);
cr = gdk_cairo_create (rci->pixmap);
cairo_move_to (cr, i - offset - label_width/2, widget_alloc.height - label_height);
pango_cairo_show_layout (cr, small_layout);
cairo_destroy (cr);
cr = NULL;
} else if ( !((i*MULT)%(sample_rate/2)) ) {
cr = gdk_cairo_create (rci->pixmap);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr,i - offset+0.5, widget_alloc.height-HEIGHT_TIME_LABEL);
cairo_line_to(cr, (i - offset)+0.5, widget_alloc.height-HEIGHT_TIME_LABEL+2);
cairo_stroke(cr);
cairo_destroy(cr);
cr=NULL;
}
progbar_count++;
}
g_object_unref(G_OBJECT(small_layout));
}
#endif
}
static gboolean draw_channels(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)user_data;
GtkAllocation allocation;
gtk_widget_get_allocation (widget, &allocation);
cairo_set_source_surface (cr, rci->surface, 0, 0);
cairo_rectangle (cr, 0, 0, allocation.width, allocation.width);
cairo_fill (cr);
return FALSE;
}
static gboolean expose_event_channels(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)user_data;
cairo_t *cr;
if (gtk_widget_is_drawable(widget)){
cr = gdk_cairo_create (gtk_widget_get_window(widget));
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface (cr, rci->surface, 0, 0);
#else
gdk_cairo_set_source_pixmap (cr, rci->pixmap, event->area.x, event->area.y);
#endif
cairo_rectangle (cr, event->area.x,event->area.y, event->area.width, event->area.height);
cairo_fill (cr);
cairo_destroy(cr);
cr = NULL;
}
return FALSE;
}
static gboolean
configure_event_channels(GtkWidget *widget, GdkEventConfigure *event _U_, gpointer user_data)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)user_data;
int i;
GtkAllocation widget_alloc;
cairo_t *cr;
#if 0
static GdkColor col[MAX_NUM_COL_CONV+1] = {
{0, 0x00FF, 0x00FF, 0xFFFF},
{0, 0x90FF, 0xEEFF, 0x90FF},
{0, 0xFFFF, 0xA0FF, 0x7AFF},
{0, 0xFFFF, 0xB6FF, 0xC1FF},
{0, 0xFAFF, 0xFAFF, 0xD2FF},
{0, 0xFFFF, 0xFFFF, 0x33FF},
{0, 0x66FF, 0xCDFF, 0xAAFF},
{0, 0xE0FF, 0xFFFF, 0xFFFF},
{0, 0xB0FF, 0xC4FF, 0xDEFF},
{0, 0x87FF, 0xCEFF, 0xFAFF},
{0, 0xD3FF, 0xD3FF, 0xD3FF}
};
#endif
static GdkRGBA col[MAX_NUM_COL_CONV+1] = {
{0.0039, 0.0039, 1.0000, 1.0},
{0.5664, 0.6289, 0.5664, 1.0},
{1.0000, 0.6289, 0.4805, 1.0},
{1.0000, 0.7148, 0.7578, 1.0},
{0.9805, 0.9805, 0.8242, 1.0},
{1.0000, 1.0000, 0.2031, 1.0},
{0.4023, 0.8046, 0.6680, 1.0},
{0.8789, 1.0000, 1.0000, 1.0},
{0.6914, 0.7695, 0.8710, 1.0},
{0.8281, 0.8281, 0.8281, 1.0},
};
#if GTK_CHECK_VERSION(2,22,0)
if(rci->surface){
cairo_surface_destroy (rci->surface);
rci->surface=NULL;
}
gtk_widget_get_allocation(widget, &widget_alloc);
#if !defined(_WIN32)
if (widget_alloc.width > G_MAXINT16-1) {
widget_alloc.width = G_MAXINT16-1;
report_failure("Channel graph truncated to 32k samples");
}
#endif
rci->surface = gdk_window_create_similar_surface (gtk_widget_get_window(widget),
CAIRO_CONTENT_COLOR,
widget_alloc.width,
widget_alloc.height);
cr = cairo_create (rci->surface);
cairo_set_source_rgb (cr, 1, 1, 1);
cairo_rectangle (cr, 0, 0, widget_alloc.width,widget_alloc.height);
cairo_fill (cr);
cairo_destroy (cr);
#else
if(rci->pixmap){
g_object_unref(rci->pixmap);
rci->pixmap=NULL;
}
gtk_widget_get_allocation(widget, &widget_alloc);
#if !defined(_WIN32)
if (widget_alloc.width > G_MAXINT16-1) {
widget_alloc.width = G_MAXINT16-1;
report_failure("Channel graph truncated to 32k samples");
}
#endif
rci->pixmap = gdk_pixmap_new(gtk_widget_get_window(widget),
widget_alloc.width,
widget_alloc.height,
-1);
if ( GDK_IS_DRAWABLE(rci->pixmap) ){
cr = gdk_cairo_create (rci->pixmap);
cairo_set_source_rgb (cr, 1, 1, 1);
cairo_rectangle (cr, 0, 0, widget_alloc.width,widget_alloc.height);
cairo_fill (cr);
cairo_destroy (cr);
}
#endif
for (i=0; i<MAX_NUM_COL_CONV+1; i++){
rci->bg_color[i].alpha=col[i].alpha;
rci->bg_color[i].red=col[i].red;
rci->bg_color[i].green=col[i].green;
rci->bg_color[i].blue=col[i].blue;
}
channel_draw(rci);
return TRUE;
}
static gboolean
button_press_event_channel(GtkWidget *widget _U_, GdkEventButton *event _U_, gpointer user_data)
{
rtp_channel_info_t *rci = (rtp_channel_info_t *)user_data;
int this_channel;
unsigned long prev_index;
if (!rci->selected) {
if (!rtp_channels->stop) return 0;
if (rtp_channels->rci[rtp_channels->channel]) {
g_signal_handlers_disconnect_by_func(rtp_channels->rci[rtp_channels->channel]->check_bt, on_bt_check_clicked, rtp_channels->rci[rtp_channels->channel]);
gtk_toggle_button_set_active((GtkToggleButton *) rtp_channels->rci[rtp_channels->channel]->check_bt, FALSE);
g_signal_connect(rtp_channels->rci[rtp_channels->channel]->check_bt, "clicked", G_CALLBACK(on_bt_check_clicked), rtp_channels->rci[rtp_channels->channel]);
rtp_channels->rci[rtp_channels->channel]->selected = FALSE;
}
g_signal_handlers_disconnect_by_func(rci->check_bt, on_bt_check_clicked, rci);
gtk_toggle_button_set_active((GtkToggleButton *) rci->check_bt, TRUE);
g_signal_connect(rci->check_bt, "clicked", G_CALLBACK(on_bt_check_clicked), rci);
rtp_channels->rci[rtp_channels->channel] = rci;
rtp_channels->channel = !(rtp_channels->channel);
rci->selected = TRUE;
bt_state(TRUE, TRUE, FALSE, FALSE);
}
if (rci == rtp_channels->rci[0]) {
this_channel = 0;
} else {
this_channel = 1;
}
rci->frame_index = (unsigned int) (event->x * MULT);
prev_index = rtp_channels->frame_index;
rtp_channels->frame_index = rtp_channels->start_index[this_channel] + rci->frame_index;
rtp_channels->pause_duration += prev_index - rtp_channels->frame_index;
if (rtp_channels->rci[!this_channel]) {
init_rtp_channels_vals();
if (rtp_channels->frame_index < rtp_channels->start_index[!this_channel]) {
rtp_channels->rci[!this_channel]->frame_index = 0;
} else if (rtp_channels->frame_index > rtp_channels->end_index[!this_channel]) {
rtp_channels->rci[!this_channel]->frame_index = rtp_channels->rci[!this_channel]->max_frame_index;
} else {
rtp_channels->rci[!this_channel]->frame_index = rtp_channels->frame_index - rtp_channels->start_index[!this_channel];
}
} else {
init_rtp_channels_vals();
}
rtp_channels->out_diff_time = 0;
rci->cursor_catch = TRUE;
draw_cursors(NULL);
return TRUE;
}
static void
add_channel_to_window(gchar *key _U_ , rtp_channel_info_t *rci, guint *counter)
{
GString *label;
GtkWidget *viewport;
char *src_addr, *dst_addr;
rci->draw_area=gtk_drawing_area_new();
rci->scroll_window=gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (rci->scroll_window), GTK_POLICY_ALWAYS, GTK_POLICY_NEVER);
rci->h_scrollbar_adjustment = gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(rci->scroll_window));
gtk_widget_set_size_request(rci->draw_area, (gint)(rci->samples->len/MULT), CHANNEL_HEIGHT);
viewport = gtk_viewport_new(rci->h_scrollbar_adjustment, gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(rci->scroll_window)));
gtk_container_add(GTK_CONTAINER(viewport), rci->draw_area);
gtk_container_add(GTK_CONTAINER(rci->scroll_window), viewport);
gtk_viewport_set_shadow_type(GTK_VIEWPORT(viewport), GTK_SHADOW_NONE);
gtk_widget_add_events (rci->draw_area, GDK_BUTTON_PRESS_MASK);
gtk_widget_set_can_focus(rci->draw_area, TRUE);
gtk_widget_grab_focus(rci->draw_area);
gtk_box_pack_start(GTK_BOX (channels_vb), rci->scroll_window, FALSE, FALSE, 0);
#if GTK_CHECK_VERSION(3,0,0)
g_signal_connect(rci->draw_area, "draw", G_CALLBACK(draw_channels), rci);
#else
g_signal_connect(rci->draw_area, "expose_event", G_CALLBACK(expose_event_channels), rci);
#endif
g_signal_connect(rci->draw_area, "configure_event", G_CALLBACK(configure_event_channels), rci);
gtk_widget_add_events (rci->draw_area, GDK_BUTTON_PRESS_MASK);
g_signal_connect(rci->draw_area, "button_press_event", G_CALLBACK(button_press_event_channel), rci);
g_signal_connect(rci->h_scrollbar_adjustment, "value_changed", G_CALLBACK(h_scrollbar_changed), rci);
label = g_string_new("");
src_addr = address_to_display(NULL, &(rci->first_stream->src_addr));
dst_addr = address_to_display(NULL, &(rci->first_stream->dest_addr));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb_use_rtp_timestamp))) {
g_string_printf(label, "From %s:%d to %s:%d Duration:%.2f Out of Seq: %d(%.1f%%) Wrong Timestamp: %d(%.1f%%)",
src_addr, rci->first_stream->src_port,
dst_addr, rci->first_stream->dest_port,
(double)rci->samples->len/sample_rate,
rci->out_of_seq, (double)rci->out_of_seq * 100 / (double)rci->num_packets,
rci->wrong_timestamp, (double)rci->wrong_timestamp * 100 / (double)rci->num_packets);
} else {
g_string_printf(label, "From %s:%d to %s:%d Duration:%.2f Drop by Jitter Buff:%d(%.1f%%) Out of Seq: %d(%.1f%%) Wrong Timestamp: %d(%.1f%%)",
src_addr, rci->first_stream->src_port,
dst_addr, rci->first_stream->dest_port,
(double)rci->samples->len/sample_rate,
rci->drop_by_jitter_buff, (double)rci->drop_by_jitter_buff * 100 / (double)rci->num_packets,
rci->out_of_seq, (double)rci->out_of_seq * 100 / (double)rci->num_packets,
rci->wrong_timestamp, (double)rci->wrong_timestamp * 100 / (double)rci->num_packets);
}
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
rci->check_bt = gtk_check_button_new_with_label(label->str);
gtk_box_pack_start(GTK_BOX (channels_vb), rci->check_bt, FALSE, FALSE, 1);
(*counter)++;
if (*counter < g_hash_table_size(rtp_channels_hash)) {
rci->separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX (channels_vb), rci->separator, FALSE, FALSE, 5);
}
g_signal_connect(rci->check_bt, "clicked", G_CALLBACK(on_bt_check_clicked), rci);
g_string_free(label, TRUE);
}
static void
count_channel_frames(gchar *key _U_ , rtp_channel_info_t *rci, gpointer ptr _U_ )
{
total_frames += rci->samples->len;
}
static void
play_channels(void)
{
PaError err;
GtkWidget *dialog;
g_assert(rtp_channels->stop || rtp_channels->pause);
if (rtp_channels->pause) {
rtp_channels->pause = FALSE;
bt_state(FALSE, FALSE, TRUE, TRUE);
} else {
#if PORTAUDIO_API_1
assert(output_channels <= INT_MAX);
err = Pa_OpenStream(
&pa_stream,
paNoDevice,
0,
PA_SAMPLE_TYPE,
NULL,
Pa_GetDefaultOutputDeviceID(),
(int)output_channels,
PA_SAMPLE_TYPE,
NULL,
sample_rate,
FRAMES_PER_BUFFER,
0,
paClipOff,
paCallback,
rtp_channels );
if( err != paNoError ) {
const char *deviceName = "No Device";
PaDeviceID device = Pa_GetDefaultOutputDeviceID();
if (device != paNoDevice)
{
const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo( device );
if (deviceInfo)
deviceName = deviceInfo->name;
else
deviceName = "(No device info)";
}
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Got this info from PortAudio Library:\n"
" Default deviceName: %s (%d)", deviceName, device);
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not Open Stream in PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
return;
}
#else
if (Pa_GetDefaultOutputDevice() != paNoDevice) {
assert(output_channels <= INT_MAX);
err = Pa_OpenDefaultStream(
&pa_stream,
0,
(int)output_channels,
PA_SAMPLE_TYPE,
sample_rate,
FRAMES_PER_BUFFER,
paCallback,
rtp_channels );
} else {
PaHostApiIndex host_api_count = Pa_GetHostApiCount();
PaHostApiIndex default_host_api_index = Pa_GetDefaultHostApi();
PaHostApiIndex host_api_index;
const PaHostApiInfo *host_api_info = NULL;
for (host_api_index=0; host_api_index<host_api_count; host_api_index++)
{
if (host_api_index == default_host_api_index)
continue;
host_api_info = Pa_GetHostApiInfo(host_api_index);
if (host_api_info->deviceCount > 0)
break;
}
if (host_api_index<host_api_count)
{
PaStreamParameters stream_parameters;
stream_parameters.device = host_api_info->defaultOutputDevice;
stream_parameters.channelCount = channels;
stream_parameters.sampleFormat = PA_SAMPLE_TYPE;
stream_parameters.suggestedLatency = 0;
stream_parameters.hostApiSpecificStreamInfo = NULL;
#ifdef DEBUG
g_print("Trying Host API: %s\n", host_api_info->name);
#endif
err = Pa_OpenStream(
&pa_stream,
NULL,
&stream_parameters,
sample_rate,
FRAMES_PER_BUFFER,
paClipOff,
paCallback,
rtp_channels );
}
else
{
err = paNoDevice;
}
}
if( err != paNoError ) {
PaHostApiIndex hostApi = Pa_GetDefaultHostApi();
if (hostApi < 0)
{
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not even get the default host API from PortAudio Library.\n Error: %s",
Pa_GetErrorText( hostApi ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}
else
{
const PaHostApiInfo *hostApiInfo = Pa_GetHostApiInfo( hostApi );
if ( !hostApiInfo )
{
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not even get the host API info from PortAudio Library.");
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}
else
{
const char *hostApiName = hostApiInfo->name;
const char *deviceName = "No Device";
PaDeviceIndex device = hostApiInfo->defaultOutputDevice;
if (device != paNoDevice)
{
const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo( device );
if (deviceInfo)
deviceName = deviceInfo->name;
else
deviceName = "(No device info)";
}
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Got this info from PortAudio Library:\n"
" Default hostApiName: %s\n"
" Default deviceName: %s (%d)", hostApiName, deviceName, device);
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}
}
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not Open Stream in PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
return;
}
#endif
err = Pa_StartStream( pa_stream );
if( err != paNoError ) {
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not Start Stream in PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
return;
}
#if !PORTAUDIO_API_1
rtp_channels->pa_start_time = Pa_GetStreamTime(pa_stream);
if (rtp_channels->pa_start_time == 0) {
getCurrentTime = getMonoTime;
rtp_channels->pa_start_time = getCurrentTime(pa_stream);
} else {
getCurrentTime = Pa_GetStreamTime;
}
#endif
rtp_channels->stop = FALSE;
bt_state(FALSE, FALSE, TRUE, TRUE);
}
g_timeout_add_full(G_PRIORITY_DEFAULT_IDLE, MULT*1000/sample_rate, draw_cursors, NULL, NULL);
}
static void
pause_channels(void)
{
rtp_channels->pause = !(rtp_channels->pause);
if (!rtp_channels->pause) {
g_timeout_add_full(G_PRIORITY_DEFAULT_IDLE, MULT*1000/sample_rate, draw_cursors, NULL, NULL);
}
bt_state(FALSE, TRUE, FALSE, TRUE);
}
static void
reset_rtp_channels(void)
{
rtp_channels->channel = 0;
rtp_channels->rci[0] = NULL;
rtp_channels->rci[1] = NULL;
rtp_channels->start_index[0] = 0;
rtp_channels->start_index[1] = 0;
rtp_channels->end_index[0] = 0;
rtp_channels->end_index[1] = 0;
rtp_channels->max_frame_index = 0;
rtp_channels->frame_index = 0;
rtp_channels->pause = FALSE;
rtp_channels->pause_duration = 0;
rtp_channels->stop = TRUE;
rtp_channels->out_diff_time = 10000;
}
static void
remove_channel_to_window(gchar *key _U_ , rtp_channel_info_t *rci, gpointer ptr _U_ )
{
#if GTK_CHECK_VERSION(2,22,0)
if(rci->surface){
cairo_surface_destroy (rci->surface);
rci->surface=NULL;
}
#else
g_object_unref(rci->pixmap);
#endif
gtk_widget_destroy(rci->draw_area);
gtk_widget_destroy(rci->scroll_window);
gtk_widget_destroy(rci->check_bt);
if (rci->separator)
gtk_widget_destroy(rci->separator);
}
static void
reset_channels(void)
{
if (rtp_channels_hash) {
g_hash_table_foreach( rtp_channels_hash, (GHFunc)remove_channel_to_window, NULL);
g_hash_table_destroy(rtp_channels_hash);
rtp_channels_hash = NULL;
}
if (rtp_channels) {
reset_rtp_channels();
}
}
void
reset_rtp_player(void)
{
reset_channels();
if (rtp_streams_hash) {
g_hash_table_destroy(rtp_streams_hash);
rtp_streams_hash = NULL;
}
if (rtp_streams_list) {
g_list_free (rtp_streams_list);
rtp_streams_list = NULL;
}
}
static void
decode_streams(void)
{
guint statusbar_context;
guint counter;
data_info info;
bt_state(FALSE, FALSE, FALSE, FALSE);
reset_channels();
progress_bar = gtk_progress_bar_new();
gtk_widget_set_size_request(progress_bar, 100, -1);
gtk_box_pack_start(GTK_BOX (stat_hbox), progress_bar, FALSE, FALSE, 2);
gtk_widget_show(progress_bar);
statusbar_context = gtk_statusbar_get_context_id((GtkStatusbar *) info_bar, "main");
gtk_statusbar_push((GtkStatusbar *) info_bar, statusbar_context, " Decoding RTP packets...");
#if !GTK_CHECK_VERSION(3,0,0)
gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(info_bar), FALSE);
#endif
total_packets = 0;
progbar_count = 0;
if (rtp_streams_hash) {
if (voip_calls)
g_hash_table_foreach( rtp_streams_hash, (GHFunc)mark_rtp_stream_to_play, NULL);
else
g_hash_table_foreach( rtp_streams_hash, (GHFunc)mark_all_rtp_stream_to_decode, NULL);
}
info.current_channel = 0;
g_list_foreach(rtp_streams_list, (GFunc) decode_rtp_stream, &info);
if (channels > 1) {
info.current_channel = 1;
g_list_foreach(rtp_streams_list, (GFunc) decode_rtp_stream, &info);
}
total_frames = 0;
if (rtp_channels_hash)
g_hash_table_foreach( rtp_channels_hash, (GHFunc)count_channel_frames, NULL);
progbar_count = 0;
gtk_statusbar_pop((GtkStatusbar *) info_bar, statusbar_context);
gtk_statusbar_push((GtkStatusbar *) info_bar, statusbar_context, " Creating channels view...");
counter = 0;
if (rtp_channels_hash)
g_hash_table_foreach( rtp_channels_hash, (GHFunc)add_channel_to_window, &counter);
if (prefs.rtp_player_max_visible < 1 || prefs.rtp_player_max_visible > 10)
prefs.rtp_player_max_visible = RTP_PLAYER_DEFAULT_VISIBLE;
gtk_widget_set_size_request(main_scrolled_window, CHANNEL_WIDTH,
MIN(counter, prefs.rtp_player_max_visible) * (CHANNEL_HEIGHT+60));
gtk_widget_show_all(main_scrolled_window);
gtk_widget_destroy(progress_bar);
progress_bar = NULL;
#if !GTK_CHECK_VERSION(3,0,0)
gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(info_bar), TRUE);
#endif
gtk_statusbar_pop((GtkStatusbar *) info_bar, statusbar_context);
gtk_statusbar_pop((GtkStatusbar *) info_bar, statusbar_context);
bt_state(TRUE, FALSE, FALSE, FALSE);
new_jitter_buff = (int) gtk_spin_button_get_value((GtkSpinButton * )jitter_spinner);
}
static void
on_cb_view_as_time_of_day_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
decode_streams();
}
static void
on_cb_use_method_group_clicked(GtkToggleButton *button _U_, gpointer user_data _U_)
{
bt_state(TRUE, FALSE, FALSE, FALSE);
}
static void
on_bt_decode_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
decode_streams();
}
static void
on_bt_play_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
play_channels();
}
static void
on_bt_pause_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
pause_channels();
}
static void
on_bt_stop_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
stop_channels();
}
static void
rtp_player_on_destroy(GObject *object _U_, gpointer user_data _U_)
{
PaError err;
GtkWidget *dialog;
if(rtp_channels && (!rtp_channels->stop)){
stop_channels();
}
reset_channels();
g_free(rtp_channels);
rtp_channels = NULL;
err = Pa_Terminate();
initialized = FALSE;
if( err != paNoError ) {
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not terminate the PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}
gtk_widget_destroy(rtp_player_dlg_w);
main_scrolled_window = NULL;
rtp_player_dlg_w = NULL;
}
static void
jitter_spinner_value_changed (GtkSpinButton *spinner _U_, gpointer user_data _U_)
{
bt_state(TRUE, TRUE, FALSE, FALSE);
}
static void
rtp_player_dlg_create(void)
{
GtkWidget *main_vb;
GtkWidget *hbuttonbox;
GtkWidget *timestamp_hb;
GtkWidget *h_jitter_buttons_box;
GtkWidget *bt_close;
GtkAdjustment *jitter_spinner_adj;
GtkWidget *label;
gchar *title_name_ptr;
gchar *win_name;
title_name_ptr = cf_get_display_name(&cfile);
win_name = g_strdup_printf("%s - RTP Player", title_name_ptr);
g_free(title_name_ptr);
rtp_player_dlg_w = dlg_window_new(win_name);
gtk_window_set_destroy_with_parent (GTK_WINDOW(rtp_player_dlg_w), TRUE);
gtk_window_set_position(GTK_WINDOW(rtp_player_dlg_w), GTK_WIN_POS_NONE);
gtk_window_set_default_size(GTK_WINDOW(rtp_player_dlg_w), 400, 50);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(rtp_player_dlg_w), main_vb);
gtk_container_set_border_width (GTK_CONTAINER (main_vb), 2);
main_scrolled_window=gtk_scrolled_window_new(NULL, NULL);
gtk_container_set_border_width (GTK_CONTAINER (main_scrolled_window), 4);
gtk_widget_set_size_request(main_scrolled_window, CHANNEL_WIDTH, 0);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (main_scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_box_pack_start(GTK_BOX(main_vb), main_scrolled_window, TRUE, TRUE, 0);
channels_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (channels_vb), 2);
#if ! GTK_CHECK_VERSION(3,8,0)
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW (main_scrolled_window), channels_vb);
#else
gtk_container_add(GTK_CONTAINER (main_scrolled_window), channels_vb);
#endif
timestamp_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), timestamp_hb, FALSE, FALSE, 0);
cb_view_as_time_of_day = gtk_check_button_new_with_label("View as time of day");
gtk_box_pack_start(GTK_BOX(timestamp_hb), cb_view_as_time_of_day, TRUE, FALSE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb_view_as_time_of_day), FALSE);
gtk_widget_set_tooltip_text(cb_view_as_time_of_day, "View the timestamps as time of day instead of seconds since beginning of capture");
g_signal_connect(cb_view_as_time_of_day, "toggled", G_CALLBACK(on_cb_view_as_time_of_day_clicked), NULL);
h_jitter_buttons_box = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (h_jitter_buttons_box), 10);
gtk_box_pack_start (GTK_BOX(main_vb), h_jitter_buttons_box, FALSE, FALSE, 0);
label = gtk_label_new("Jitter buffer [ms] ");
gtk_box_pack_start(GTK_BOX(h_jitter_buttons_box), label, FALSE, FALSE, 0);
jitter_spinner_adj = (GtkAdjustment *) gtk_adjustment_new (50, 0, 500, 5, 10, 0);
jitter_spinner = gtk_spin_button_new (jitter_spinner_adj, 5, 0);
gtk_box_pack_start(GTK_BOX(h_jitter_buttons_box), jitter_spinner, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text (jitter_spinner, "The simulated jitter buffer in [ms]");
g_signal_connect(G_OBJECT (jitter_spinner_adj), "value_changed", G_CALLBACK(jitter_spinner_value_changed), NULL);
cb_use_jitter_buffer = gtk_radio_button_new_with_label(NULL, "Jitter buffer");
gtk_box_pack_start(GTK_BOX(h_jitter_buttons_box), cb_use_jitter_buffer, FALSE, FALSE, 10);
g_signal_connect(cb_use_jitter_buffer, "toggled", G_CALLBACK(on_cb_use_method_group_clicked), NULL);
gtk_widget_set_tooltip_text(cb_use_jitter_buffer, "Use jitter buffer to heard RTP stream as end user");
cb_use_rtp_timestamp = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(cb_use_jitter_buffer)), "Use RTP timestamp");
gtk_box_pack_start(GTK_BOX(h_jitter_buttons_box), cb_use_rtp_timestamp, FALSE, FALSE, 10);
g_signal_connect(cb_use_rtp_timestamp, "toggled", G_CALLBACK(on_cb_use_method_group_clicked), NULL);
gtk_widget_set_tooltip_text(cb_use_rtp_timestamp, "Use RTP Timestamp instead of the arriving packet time. This will not reproduce the RTP stream as the user heard it, but is useful when the RTP is being tunneled and the original packet timing is missing");
cb_use_uninterrupted_mode = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(cb_use_jitter_buffer)), "Uninterrupted mode");
gtk_box_pack_start(GTK_BOX(h_jitter_buttons_box), cb_use_uninterrupted_mode, FALSE, FALSE, 10);
g_signal_connect(cb_use_uninterrupted_mode, "toggled", G_CALLBACK(on_cb_use_method_group_clicked), NULL);
gtk_widget_set_tooltip_text(cb_use_uninterrupted_mode, "Ignore RTP Timestamp. Play stream as it is completed. It is useful when the RTP timestamp is missing.");
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start (GTK_BOX (h_jitter_buttons_box), hbuttonbox, TRUE, TRUE, 0);
gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing (GTK_BOX (hbuttonbox), 10);
bt_decode = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DECODE);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_decode);
g_signal_connect(bt_decode, "clicked", G_CALLBACK(on_bt_decode_clicked), NULL);
gtk_widget_set_tooltip_text (bt_decode, "Decode the RTP stream(s)");
bt_play = ws_gtk_button_new_from_stock(GTK_STOCK_MEDIA_PLAY);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_play);
g_signal_connect(bt_play, "clicked", G_CALLBACK(on_bt_play_clicked), NULL);
gtk_widget_set_tooltip_text (bt_play, "Play the RTP channel(s)");
bt_pause = ws_gtk_button_new_from_stock(GTK_STOCK_MEDIA_PAUSE);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_pause);
g_signal_connect(bt_pause, "clicked", G_CALLBACK(on_bt_pause_clicked), NULL);
gtk_widget_set_tooltip_text (bt_pause, "Pause the RTP channel(s)");
bt_stop = ws_gtk_button_new_from_stock(GTK_STOCK_MEDIA_STOP);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_stop);
g_signal_connect(bt_stop, "clicked", G_CALLBACK(on_bt_stop_clicked), NULL);
gtk_widget_set_tooltip_text (bt_stop, "Stop the RTP channel(s)");
bt_close = ws_gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_close);
gtk_widget_set_can_default(bt_close, TRUE);
gtk_widget_set_tooltip_text (bt_close, "Close this dialog");
window_set_cancel_button(rtp_player_dlg_w, bt_close, window_cancel_button_cb);
g_signal_connect(rtp_player_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rtp_player_dlg_w, "destroy", G_CALLBACK(rtp_player_on_destroy), NULL);
stat_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(stat_hbox), 0);
info_bar = gtk_statusbar_new();
#if !GTK_CHECK_VERSION(3,0,0)
gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(info_bar), TRUE);
#endif
gtk_box_pack_start(GTK_BOX(stat_hbox), info_bar, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(main_vb), stat_hbox, FALSE, TRUE, 0);
bt_state(TRUE, FALSE, FALSE, FALSE);
gtk_widget_show_all(rtp_player_dlg_w);
while (g_main_context_iteration(NULL, FALSE));
g_free(win_name);
}
void
rtp_player_init(voip_calls_tapinfo_t *voip_calls_tap)
{
PaError err;
GtkWidget *dialog;
if (initialized) return;
initialized = TRUE;
voip_calls = voip_calls_tap;
err = Pa_Initialize();
if( err != paNoError ) {
dialog = gtk_message_dialog_new ((GtkWindow *) rtp_player_dlg_w,
GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,
"Can not Initialize the PortAudio Library.\n Error: %s", Pa_GetErrorText( err ));
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
initialized = FALSE;
return;
}
new_jitter_buff = -1;
if (!rtp_channels) {
rtp_channels = g_new(rtp_play_channels_t,1);
}
reset_rtp_channels();
#ifdef DEBUG
g_print("Pa_GetHostApiCount() = %d\n", Pa_GetHostApiCount());
g_print("Pa_GetDefaultHostApi() = %d\n", Pa_GetDefaultHostApi());
if ((Pa_GetHostApiCount() >= 0) && (Pa_GetDefaultHostApi() >= 0))
{
unsigned int i;
PaHostApiIndex api_index;
const PaHostApiInfo *api_info = Pa_GetHostApiInfo( (unsigned int)Pa_GetDefaultHostApi() );
g_print("Default PaHostApiInfo.type = %d (%s)\n", api_info->type, api_info->name);
for (i=0; i<(unsigned int)Pa_GetHostApiCount(); i++)
{
api_info = Pa_GetHostApiInfo( i );
g_print("PaHostApiInfo[%u].type = %d (%s)\n", i, api_info->type, api_info->name);
}
api_index = Pa_HostApiTypeIdToHostApiIndex( paALSA );
if (api_index < 0)
{
g_print("api_index for paALSA not found (%d)\n", api_index);
}
else
{
api_info = Pa_GetHostApiInfo( (unsigned int)api_index );
g_print("This should be ALSA: %s\n", api_info->name);
}
}
#endif
rtp_player_dlg_create();
}
