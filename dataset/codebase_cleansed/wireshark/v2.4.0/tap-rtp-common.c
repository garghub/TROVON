static gint rtp_stream_info_cmp(gconstpointer aa, gconstpointer bb)
{
const struct _rtp_stream_info* a = (const struct _rtp_stream_info*)aa;
const struct _rtp_stream_info* b = (const struct _rtp_stream_info*)bb;
if (a==b)
return 0;
if (a==NULL || b==NULL)
return 1;
if (addresses_equal(&(a->src_addr), &(b->src_addr))
&& (a->src_port == b->src_port)
&& addresses_equal(&(a->dest_addr), &(b->dest_addr))
&& (a->dest_port == b->dest_port)
&& (a->ssrc == b->ssrc))
return 0;
else
return 1;
}
void rtpstream_reset(rtpstream_tapinfo_t *tapinfo)
{
GList* list;
if (tapinfo->mode == TAP_ANALYSE) {
list = g_list_first(tapinfo->strinfo_list);
while (list)
{
g_free(list->data);
list = g_list_next(list);
}
g_list_free(tapinfo->strinfo_list);
tapinfo->strinfo_list = NULL;
tapinfo->nstreams = 0;
tapinfo->npackets = 0;
}
return;
}
void rtpstream_reset_cb(void *arg)
{
rtpstream_tapinfo_t *ti =(rtpstream_tapinfo_t *)arg;
if (ti->tap_reset) {
ti->tap_reset(ti);
}
rtpstream_reset(ti);
}
void rtp_write_header(rtp_stream_info_t *strinfo, FILE *file)
{
guint32 start_sec;
guint32 start_usec;
guint32 source;
size_t sourcelen;
guint16 port;
guint16 padding;
char* addr_str = address_to_display(NULL, &(strinfo->dest_addr));
fprintf(file, "#!rtpplay%s %s/%u\n", RTPFILE_VERSION,
addr_str,
strinfo->dest_port);
wmem_free(NULL, addr_str);
start_sec = g_htonl(strinfo->start_fd->abs_ts.secs);
start_usec = g_htonl(strinfo->start_fd->abs_ts.nsecs / 1000000);
memset(&source, 0, sizeof source);
sourcelen = strinfo->src_addr.len;
if (sourcelen > sizeof source)
sourcelen = sizeof source;
memcpy(&source, strinfo->src_addr.data, sourcelen);
port = g_htons(strinfo->src_port);
padding = 0;
if (fwrite(&start_sec, 4, 1, file) == 0)
return;
if (fwrite(&start_usec, 4, 1, file) == 0)
return;
if (fwrite(&source, 4, 1, file) == 0)
return;
if (fwrite(&port, 2, 1, file) == 0)
return;
if (fwrite(&padding, 2, 1, file) == 0)
return;
}
static void rtp_write_sample(rtpdump_info_t* rtpdump_info, FILE* file)
{
guint16 length;
guint16 plen;
guint32 offset;
length = g_htons(rtpdump_info->num_samples + 8);
plen = g_htons(rtpdump_info->num_samples);
offset = g_htonl(rtpdump_info->rec_time);
if (fwrite(&length, 2, 1, file) == 0)
return;
if (fwrite(&plen, 2, 1, file) == 0)
return;
if (fwrite(&offset, 4, 1, file) == 0)
return;
if (fwrite(rtpdump_info->samples, rtpdump_info->num_samples, 1, file) == 0)
return;
}
int rtpstream_packet(void *arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *arg2)
{
rtpstream_tapinfo_t *tapinfo = (rtpstream_tapinfo_t *)arg;
const struct _rtp_info *rtpinfo = (const struct _rtp_info *)arg2;
rtp_stream_info_t new_stream_info;
rtp_stream_info_t *stream_info = NULL;
GList* list;
rtpdump_info_t rtpdump_info;
struct _rtp_conversation_info *p_conv_data = NULL;
memset(&new_stream_info, 0, sizeof(rtp_stream_info_t));
copy_address(&(new_stream_info.src_addr), &(pinfo->src));
new_stream_info.src_port = pinfo->srcport;
copy_address(&(new_stream_info.dest_addr), &(pinfo->dst));
new_stream_info.dest_port = pinfo->destport;
new_stream_info.ssrc = rtpinfo->info_sync_src;
new_stream_info.payload_type = rtpinfo->info_payload_type;
new_stream_info.payload_type_name = g_strdup(rtpinfo->info_payload_type_str);
if (tapinfo->mode == TAP_ANALYSE) {
list = g_list_first(tapinfo->strinfo_list);
while (list)
{
if (rtp_stream_info_cmp(&new_stream_info, (rtp_stream_info_t*)(list->data))==0)
{
stream_info = (rtp_stream_info_t*)(list->data);
break;
}
list = g_list_next(list);
}
if (!stream_info) {
new_stream_info.start_fd = pinfo->fd;
new_stream_info.start_rel_time = pinfo->rel_ts;
new_stream_info.rtp_stats.first_packet = TRUE;
new_stream_info.rtp_stats.reg_pt = PT_UNDEFINED;
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_get_id_by_filter_name("rtp"), 0);
if (p_conv_data)
new_stream_info.setup_frame_number = p_conv_data->frame_number;
else
new_stream_info.setup_frame_number = 0xFFFFFFFF;
stream_info = g_new(rtp_stream_info_t,1);
*stream_info = new_stream_info;
tapinfo->strinfo_list = g_list_append(tapinfo->strinfo_list, stream_info);
}
rtp_packet_analyse(&(stream_info->rtp_stats), pinfo, rtpinfo);
if (stream_info->rtp_stats.flags & STAT_FLAG_WRONG_TIMESTAMP
|| stream_info->rtp_stats.flags & STAT_FLAG_WRONG_SEQ)
stream_info->problem = TRUE;
++(stream_info->packet_count);
stream_info->stop_rel_time = pinfo->rel_ts;
++(tapinfo->npackets);
return 1;
}
else if (tapinfo->mode == TAP_SAVE) {
if (rtp_stream_info_cmp(&new_stream_info, tapinfo->filter_stream_fwd)==0) {
rtpdump_info.rec_time = nstime_to_msec(&pinfo->abs_ts) -
nstime_to_msec(&tapinfo->filter_stream_fwd->start_fd->abs_ts);
rtpdump_info.num_samples = rtpinfo->info_data_len;
rtpdump_info.samples = rtpinfo->info_data;
rtp_write_sample(&rtpdump_info, tapinfo->save_file);
}
}
else if (tapinfo->mode == TAP_MARK && tapinfo->tap_mark_packet) {
if (rtp_stream_info_cmp(&new_stream_info, tapinfo->filter_stream_fwd)==0
|| rtp_stream_info_cmp(&new_stream_info, tapinfo->filter_stream_rev)==0)
{
tapinfo->tap_mark_packet(tapinfo, pinfo->fd);
}
}
return 0;
}
static guint32
get_clock_rate(guint32 key)
{
size_t i;
for (i = 0; i < NUM_CLOCK_VALUES; i++) {
if (clock_map[i].key == key)
return clock_map[i].value;
}
return 0;
}
static guint32
get_dyn_pt_clock_rate(const gchar *payload_type_str)
{
int i;
for (i = NUM_DYN_CLOCK_VALUES - 1; i > -1 ; i--) {
if (g_ascii_strncasecmp(mimetype_and_clock_map[i].pt_mime_name_str,payload_type_str,(strlen(mimetype_and_clock_map[i].pt_mime_name_str))) == 0)
return mimetype_and_clock_map[i].value;
}
return 0;
}
void
rtp_packet_analyse(tap_rtp_stat_t *statinfo,
packet_info *pinfo,
const struct _rtp_info *rtpinfo)
{
double current_time;
double current_jitter;
double current_diff = 0;
double nominaltime;
double arrivaltime;
double expected_time;
double absskew;
guint32 clock_rate;
current_time = nstime_to_msec(&pinfo->rel_ts);
if (statinfo->first_packet) {
if( pinfo->dl_src.type == AT_ETHER){
copy_address(&(statinfo->first_packet_mac_addr), &(pinfo->dl_src));
}
statinfo->start_seq_nr = rtpinfo->info_seq_num;
statinfo->stop_seq_nr = rtpinfo->info_seq_num;
statinfo->seq_num = rtpinfo->info_seq_num;
statinfo->start_time = current_time;
statinfo->timestamp = rtpinfo->info_timestamp;
statinfo->first_timestamp = rtpinfo->info_timestamp;
statinfo->time = current_time;
statinfo->lastnominaltime = 0;
statinfo->pt = rtpinfo->info_payload_type;
statinfo->reg_pt = rtpinfo->info_payload_type;
if (pinfo->net_src.type == AT_IPv6) {
statinfo->bw_history[statinfo->bw_index].bytes = rtpinfo->info_data_len + 48;
} else {
statinfo->bw_history[statinfo->bw_index].bytes = rtpinfo->info_data_len + 28;
}
statinfo->bw_history[statinfo->bw_index].time = current_time;
statinfo->bw_index++;
if (pinfo->net_src.type == AT_IPv6) {
statinfo->total_bytes += rtpinfo->info_data_len + 48;
} else {
statinfo->total_bytes += rtpinfo->info_data_len + 28;
}
statinfo->bandwidth = (double)(statinfo->total_bytes*8)/1000;
statinfo->delta = 0;
statinfo->jitter = 0;
statinfo->diff = 0;
statinfo->total_nr++;
statinfo->flags |= STAT_FLAG_FIRST;
if (rtpinfo->info_marker_set) {
statinfo->flags |= STAT_FLAG_MARKER;
}
statinfo->first_packet_num = pinfo->num;
statinfo->first_packet = FALSE;
return;
}
statinfo->flags = 0;
#if 0
*/
if( pinfo->dl_src.type == AT_ETHER){
if(!addresses_equal(&(statinfo->first_packet_mac_addr), &(pinfo->dl_src))){
statinfo->flags |= STAT_FLAG_DUP_PKT;
statinfo->delta = current_time-(statinfo->time);
return;
}
}
#endif
if ((rtpinfo->info_seq_num < statinfo->start_seq_nr) && (statinfo->under == FALSE)){
statinfo->cycles++;
statinfo->under = TRUE;
}
else if ((rtpinfo->info_seq_num == 0) && (statinfo->stop_seq_nr == 65535) &&
(statinfo->under == FALSE)){
statinfo->cycles++;
statinfo->under = TRUE;
}
else if ((rtpinfo->info_seq_num > statinfo->start_seq_nr) && (statinfo->under != FALSE)) {
statinfo->under = FALSE;
}
if ( (statinfo->seq_num+1 == rtpinfo->info_seq_num) || (statinfo->flags & STAT_FLAG_FIRST) )
statinfo->seq_num = rtpinfo->info_seq_num;
else if ( (statinfo->seq_num == 65535) && (rtpinfo->info_seq_num == 0) )
statinfo->seq_num = rtpinfo->info_seq_num;
else if (statinfo->seq_num+1 < rtpinfo->info_seq_num || statinfo->seq_num - rtpinfo->info_seq_num > 0xFF00) {
statinfo->seq_num = rtpinfo->info_seq_num;
statinfo->sequence++;
statinfo->flags |= STAT_FLAG_WRONG_SEQ;
}
else if (statinfo->seq_num+1 > rtpinfo->info_seq_num) {
statinfo->sequence++;
statinfo->flags |= STAT_FLAG_WRONG_SEQ;
}
if (rtpinfo->info_payload_type == PT_CN
|| rtpinfo->info_payload_type == PT_CN_OLD)
statinfo->flags |= STAT_FLAG_PT_CN;
if (statinfo->pt == PT_CN
|| statinfo->pt == PT_CN_OLD)
statinfo->flags |= STAT_FLAG_FOLLOW_PT_CN;
if (rtpinfo->info_payload_type != statinfo->pt)
statinfo->flags |= STAT_FLAG_PT_CHANGE;
statinfo->pt = rtpinfo->info_payload_type;
if (statinfo->pt < 96 ){
clock_rate = get_clock_rate(statinfo->pt);
}else{
if ( rtpinfo->info_payload_type_str != NULL ){
if (g_ascii_strncasecmp("telephone-event",rtpinfo->info_payload_type_str,(strlen("telephone-event")))==0){
clock_rate = 0;
statinfo->flags |= STAT_FLAG_PT_T_EVENT;
}else{
if(rtpinfo->info_payload_rate !=0){
clock_rate = rtpinfo->info_payload_rate;
}else{
clock_rate = get_dyn_pt_clock_rate(rtpinfo->info_payload_type_str);
}
}
}else{
clock_rate = 0;
}
}
arrivaltime = current_time - statinfo->start_time;
nominaltime = (double)(guint32_wraparound_diff(rtpinfo->info_timestamp, statinfo->first_timestamp));
if (clock_rate != 0) {
statinfo->clock_rate = clock_rate;
nominaltime = nominaltime /(clock_rate/1000);
if (!statinfo->first_packet) {
expected_time = statinfo->time + (nominaltime - statinfo->lastnominaltime);
current_diff = fabs(current_time - expected_time);
current_jitter = (15 * statinfo->jitter + current_diff) / 16;
statinfo->delta = current_time-(statinfo->time);
statinfo->jitter = current_jitter;
statinfo->diff = current_diff;
}
statinfo->lastnominaltime = nominaltime;
statinfo->skew = nominaltime - arrivaltime;
absskew = fabs(statinfo->skew);
if(absskew > fabs(statinfo->max_skew)){
statinfo->max_skew = statinfo->skew;
}
#if 0
if (numPackets > 0 && (!hardPayloadType || !alternatePayloadType)) {
double dt;
dt = nominaltime - statinfo->lastnominaltime;
sumdt += 1.0 * dt;
numdt += (dt != 0 ? 1 : 0);
mindt = (dt < mindt ? dt : mindt);
maxdt = (dt > maxdt ? dt : maxdt);
}
#endif
statinfo->sumt += 1.0 * current_time;
statinfo->sumTS += 1.0 * nominaltime;
statinfo->sumt2 += 1.0 * current_time * current_time;
statinfo->sumtTS += 1.0 * current_time * nominaltime;
}
if (pinfo->net_src.type == AT_IPv6) {
statinfo->bw_history[statinfo->bw_index].bytes = rtpinfo->info_data_len + 48;
} else {
statinfo->bw_history[statinfo->bw_index].bytes = rtpinfo->info_data_len + 28;
}
statinfo->bw_history[statinfo->bw_index].time = current_time;
while ((statinfo->bw_history[statinfo->bw_start_index].time+1000)<current_time){
statinfo->total_bytes -= statinfo->bw_history[statinfo->bw_start_index].bytes;
statinfo->bw_start_index++;
if (statinfo->bw_start_index == BUFF_BW) statinfo->bw_start_index=0;
};
if (pinfo->net_src.type == AT_IPv6){
statinfo->total_bytes += rtpinfo->info_data_len + 48;
}else{
statinfo->total_bytes += rtpinfo->info_data_len + 28;
}
statinfo->bandwidth = (double)(statinfo->total_bytes*8)/1000;
statinfo->bw_index++;
if (statinfo->bw_index == BUFF_BW) statinfo->bw_index = 0;
statinfo->delta_timestamp = guint32_wraparound_diff(rtpinfo->info_timestamp, statinfo->timestamp);
if (rtpinfo->info_marker_set) {
statinfo->flags |= STAT_FLAG_MARKER;
}
gint32 tsdelta=rtpinfo->info_timestamp - statinfo->timestamp;
if (tsdelta < 0) {
statinfo->flags |= STAT_FLAG_WRONG_TIMESTAMP;
}
if (!(statinfo->flags & STAT_FLAG_FIRST)
&& !(statinfo->flags & STAT_FLAG_MARKER)
&& !(statinfo->flags & STAT_FLAG_PT_CN)
&& !(statinfo->flags & STAT_FLAG_WRONG_TIMESTAMP)
&& !(statinfo->flags & STAT_FLAG_FOLLOW_PT_CN)) {
if (statinfo->delta > statinfo->max_delta) {
statinfo->max_delta = statinfo->delta;
statinfo->max_nr = pinfo->num;
}
if (clock_rate != 0) {
if (statinfo->jitter > statinfo->max_jitter) {
statinfo->max_jitter = statinfo->jitter;
}
statinfo->mean_jitter = (statinfo->mean_jitter*statinfo->total_nr + current_diff) / (statinfo->total_nr+1);
}
}
if (!(statinfo->flags & STAT_FLAG_FIRST)
&& !(statinfo->flags & STAT_FLAG_PT_CN)) {
if ((statinfo->pt != statinfo->reg_pt)
&& (statinfo->reg_pt != PT_UNDEFINED)) {
statinfo->flags |= STAT_FLAG_REG_PT_CHANGE;
}
}
if (!(statinfo->flags & STAT_FLAG_PT_CN)) {
statinfo->reg_pt = statinfo->pt;
}
statinfo->time = current_time;
statinfo->timestamp = rtpinfo->info_timestamp;
statinfo->stop_seq_nr = rtpinfo->info_seq_num;
statinfo->total_nr++;
statinfo->last_payload_len = rtpinfo->info_payload_len - rtpinfo->info_padding_count;
return;
}
