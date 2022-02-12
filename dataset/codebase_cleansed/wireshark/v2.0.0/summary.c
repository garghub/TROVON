static void
tally_frame_data(frame_data *cur_frame, summary_tally *sum_tally)
{
double cur_time;
sum_tally->bytes += cur_frame->pkt_len;
if (cur_frame->flags.passed_dfilter){
sum_tally->filtered_count++;
sum_tally->filtered_bytes += cur_frame->pkt_len;
}
if (cur_frame->flags.marked){
sum_tally->marked_count++;
sum_tally->marked_bytes += cur_frame->pkt_len;
}
if (cur_frame->flags.ignored){
sum_tally->ignored_count++;
}
if (cur_frame->flags.has_ts) {
cur_time = nstime_to_sec(&cur_frame->abs_ts);
sum_tally->packet_count_ts++;
if (cur_time < sum_tally->start_time) {
sum_tally->start_time = cur_time;
}
if (cur_time > sum_tally->stop_time){
sum_tally->stop_time = cur_time;
}
if (cur_frame->flags.passed_dfilter){
sum_tally->filtered_count_ts++;
if (sum_tally->filtered_count == 1){
sum_tally->filtered_start= cur_time;
sum_tally->filtered_stop = cur_time;
} else {
if (cur_time < sum_tally->filtered_start) {
sum_tally->filtered_start = cur_time;
}
if (cur_time > sum_tally->filtered_stop) {
sum_tally->filtered_stop = cur_time;
}
}
}
if (cur_frame->flags.marked){
sum_tally->marked_count_ts++;
if (sum_tally->marked_count == 1){
sum_tally->marked_start= cur_time;
sum_tally->marked_stop = cur_time;
} else {
if (cur_time < sum_tally->marked_start) {
sum_tally->marked_start = cur_time;
}
if (cur_time > sum_tally->marked_stop) {
sum_tally->marked_stop = cur_time;
}
}
}
}
}
void
summary_fill_in(capture_file *cf, summary_tally *st)
{
frame_data *first_frame, *cur_frame;
guint32 framenum;
const wtapng_section_t* shb_inf;
iface_options iface;
guint i;
wtapng_iface_descriptions_t* idb_info;
wtapng_if_descr_t wtapng_if_descr;
wtapng_if_stats_t *if_stats;
st->packet_count_ts = 0;
st->start_time = 0;
st->stop_time = 0;
st->bytes = 0;
st->filtered_count = 0;
st->filtered_count_ts = 0;
st->filtered_start = 0;
st->filtered_stop = 0;
st->filtered_bytes = 0;
st->marked_count = 0;
st->marked_count_ts = 0;
st->marked_start = 0;
st->marked_stop = 0;
st->marked_bytes = 0;
st->ignored_count = 0;
if (cf->count != 0) {
first_frame = frame_data_sequence_find(cf->frames, 1);
st->start_time = nstime_to_sec(&first_frame->abs_ts);
st->stop_time = nstime_to_sec(&first_frame->abs_ts);
for (framenum = 1; framenum <= cf->count; framenum++) {
cur_frame = frame_data_sequence_find(cf->frames, framenum);
tally_frame_data(cur_frame, st);
}
}
st->filename = cf->filename;
st->file_length = cf->f_datalen;
st->file_type = cf->cd_t;
st->iscompressed = cf->iscompressed;
st->is_tempfile = cf->is_tempfile;
st->file_encap_type = cf->lnk_t;
st->packet_encap_types = cf->linktypes;
st->has_snap = cf->has_snap;
st->snap = cf->snap;
st->elapsed_time = nstime_to_sec(&cf->elapsed_time);
st->packet_count = cf->count;
st->drops_known = cf->drops_known;
st->drops = cf->drops;
st->dfilter = cf->dfilter;
shb_inf = wtap_file_get_shb(cf->wth);
if(shb_inf == NULL){
st->opt_comment = NULL;
st->shb_hardware = NULL;
st->shb_os = NULL;
st->shb_user_appl = NULL;
}else{
st->opt_comment = shb_inf->opt_comment;
st->shb_hardware = shb_inf->shb_hardware;
st->shb_os = shb_inf->shb_os;
st->shb_user_appl = shb_inf->shb_user_appl;
}
st->ifaces = g_array_new(FALSE, FALSE, sizeof(iface_options));
idb_info = wtap_file_get_idb_info(cf->wth);
for (i = 0; i < idb_info->interface_data->len; i++) {
wtapng_if_descr = g_array_index(idb_info->interface_data, wtapng_if_descr_t, i);
iface.cfilter = g_strdup(wtapng_if_descr.if_filter_str);
iface.name = g_strdup(wtapng_if_descr.if_name);
iface.descr = g_strdup(wtapng_if_descr.if_description);
iface.drops_known = FALSE;
iface.drops = 0;
iface.snap = wtapng_if_descr.snap_len;
iface.has_snap = (iface.snap != 65535);
iface.encap_type = wtapng_if_descr.wtap_encap;
iface.isb_comment = NULL;
if(wtapng_if_descr.num_stat_entries == 1){
if_stats = &g_array_index(wtapng_if_descr.interface_statistics, wtapng_if_stats_t, 0);
if (if_stats->isb_ifdrop != G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFFFF)) {
iface.drops_known = TRUE;
iface.drops = if_stats->isb_ifdrop;
}
iface.isb_comment = if_stats->opt_comment;
}
g_array_append_val(st->ifaces, iface);
}
g_free(idb_info);
}
void
summary_fill_in_capture(capture_file *cf,capture_options *capture_opts, summary_tally *st)
{
iface_options iface;
interface_t device;
guint i;
if (st->ifaces->len == 0) {
for (i = 0; i < capture_opts->all_ifaces->len; i++) {
device = g_array_index(capture_opts->all_ifaces, interface_t, i);
if (!device.selected) {
continue;
}
iface.cfilter = g_strdup(device.cfilter);
iface.name = g_strdup(device.name);
iface.descr = g_strdup(device.display_name);
iface.drops_known = cf->drops_known;
iface.drops = cf->drops;
iface.has_snap = device.has_snaplen;
iface.snap = device.snaplen;
iface.encap_type = wtap_pcap_encap_to_wtap_encap(device.active_dlt);
g_array_append_val(st->ifaces, iface);
}
}
}
