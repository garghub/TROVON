static gint
mcast_stream_info_cmp(gconstpointer aa, gconstpointer bb)
{
const struct _mcast_stream_info* a = (const struct _mcast_stream_info *)aa;
const struct _mcast_stream_info* b = (const struct _mcast_stream_info *)bb;
if (a==b)
return 0;
if (a==NULL || b==NULL)
return 1;
if (addresses_equal(&(a->src_addr), &(b->src_addr))
&& (a->src_port == b->src_port)
&& addresses_equal(&(a->dest_addr), &(b->dest_addr))
&& (a->dest_port == b->dest_port))
return 0;
else
return 1;
}
void
mcaststream_reset(mcaststream_tapinfo_t *tapinfo)
{
GList* list;
list = g_list_first(tapinfo->strinfo_list);
while (list)
{
g_free(list->data);
list = g_list_next(list);
}
g_list_free(tapinfo->strinfo_list);
tapinfo->strinfo_list = NULL;
g_free(tapinfo->allstreams);
tapinfo->allstreams = NULL;
tapinfo->npackets = 0;
return;
}
static void
mcaststream_reset_cb(void *ti_ptr)
{
mcaststream_tapinfo_t *tapinfo = (mcaststream_tapinfo_t *)ti_ptr;
if (tapinfo) {
if (tapinfo->tap_reset) {
tapinfo->tap_reset(tapinfo);
}
mcaststream_reset(tapinfo);
}
}
static void
mcaststream_draw(void *ti_ptr)
{
mcaststream_tapinfo_t *tapinfo = (mcaststream_tapinfo_t *)ti_ptr;
if (tapinfo && tapinfo->tap_draw) {
tapinfo->tap_draw(tapinfo);
}
return;
}
static gboolean
mcaststream_packet(void *arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *arg2 _U_)
{
mcaststream_tapinfo_t *tapinfo = (mcaststream_tapinfo_t *)arg;
mcast_stream_info_t tmp_strinfo;
mcast_stream_info_t *strinfo = NULL;
GList* list;
nstime_t delta;
double deltatime;
switch (pinfo->net_dst.type) {
case AT_IPv4:
if (pinfo->net_dst.len == 0 || (((const guint8*)pinfo->net_dst.data)[0] & 0xf0) != 0xe0)
return FALSE;
break;
case AT_IPv6:
if (pinfo->net_dst.len == 0 || ((const guint8*)pinfo->net_dst.data)[0] != 0xff)
return FALSE;
break;
default:
return FALSE;
}
copy_address(&(tmp_strinfo.src_addr), &(pinfo->net_src));
tmp_strinfo.src_port = pinfo->srcport;
copy_address(&(tmp_strinfo.dest_addr), &(pinfo->net_dst));
tmp_strinfo.dest_port = pinfo->destport;
list = g_list_first(tapinfo->strinfo_list);
while (list)
{
if (mcast_stream_info_cmp(&tmp_strinfo, (mcast_stream_info_t*)(list->data))==0)
{
strinfo = (mcast_stream_info_t*)(list->data);
break;
}
list = g_list_next(list);
}
if (!strinfo) {
tmp_strinfo.npackets = 0;
tmp_strinfo.apackets = 0;
tmp_strinfo.first_frame_num = pinfo->num;
tmp_strinfo.start_abs = pinfo->abs_ts;
tmp_strinfo.start_rel = pinfo->rel_ts;
tmp_strinfo.vlan_id = 0;
tmp_strinfo.average_bw = 0;
tmp_strinfo.total_bytes = 0;
tmp_strinfo.element.buff = (nstime_t *)g_malloc(buffsize * sizeof(nstime_t));
tmp_strinfo.element.first=0;
tmp_strinfo.element.last=0;
tmp_strinfo.element.burstsize=1;
tmp_strinfo.element.topburstsize=1;
tmp_strinfo.element.numbursts=0;
tmp_strinfo.element.burststatus=0;
tmp_strinfo.element.count=1;
tmp_strinfo.element.buffusage=pinfo->fd->pkt_len;
tmp_strinfo.element.topbuffusage=pinfo->fd->pkt_len;
tmp_strinfo.element.numbuffalarms=0;
tmp_strinfo.element.buffstatus=0;
tmp_strinfo.element.maxbw=0;
strinfo = (mcast_stream_info_t *)g_malloc(sizeof(mcast_stream_info_t));
*strinfo = tmp_strinfo;
tapinfo->strinfo_list = g_list_append(tapinfo->strinfo_list, strinfo);
strinfo->element.buff = (nstime_t *)g_malloc(buffsize * sizeof(nstime_t));
if (tapinfo->npackets == 0) {
tapinfo->allstreams = (mcast_stream_info_t *)g_malloc(sizeof(mcast_stream_info_t));
tapinfo->allstreams->element.buff =
(nstime_t *)g_malloc(buffsize * sizeof(nstime_t));
tapinfo->allstreams->start_rel = pinfo->rel_ts;
tapinfo->allstreams->total_bytes = 0;
tapinfo->allstreams->element.first=0;
tapinfo->allstreams->element.last=0;
tapinfo->allstreams->element.burstsize=1;
tapinfo->allstreams->element.topburstsize=1;
tapinfo->allstreams->element.numbursts=0;
tapinfo->allstreams->element.burststatus=0;
tapinfo->allstreams->element.count=1;
tapinfo->allstreams->element.buffusage=pinfo->fd->pkt_len;
tapinfo->allstreams->element.topbuffusage=pinfo->fd->pkt_len;
tapinfo->allstreams->element.numbuffalarms=0;
tapinfo->allstreams->element.buffstatus=0;
tapinfo->allstreams->element.maxbw=0;
}
}
strinfo->stop_rel = pinfo->rel_ts;
nstime_delta(&delta, &strinfo->stop_rel, &strinfo->start_rel);
deltatime = nstime_to_sec(&delta);
strinfo->total_bytes = strinfo->total_bytes + pinfo->fd->pkt_len;
++(strinfo->npackets);
if (deltatime > 0) {
strinfo->apackets = strinfo->npackets / deltatime;
strinfo->average_bw = ((double)(strinfo->total_bytes*8) / deltatime);
} else {
strinfo->apackets = strinfo->average_bw = 0.0;
}
tapinfo->allstreams->stop_rel = pinfo->rel_ts;
nstime_delta(&delta, &tapinfo->allstreams->stop_rel, &tapinfo->allstreams->start_rel);
deltatime = nstime_to_sec(&delta);
++(tapinfo->npackets);
tapinfo->allstreams->total_bytes = tapinfo->allstreams->total_bytes + pinfo->fd->pkt_len;
if (deltatime > 0)
tapinfo->allstreams->average_bw = ((double)(tapinfo->allstreams->total_bytes*8) / deltatime);
slidingwindow(strinfo, pinfo);
buffusagecalc(strinfo, pinfo, mcast_stream_emptyspeed*1000);
slidingwindow(tapinfo->allstreams, pinfo);
buffusagecalc(tapinfo->allstreams, pinfo, mcast_stream_cumulemptyspeed*1000);
return 1;
}
void
mcaststream_scan(mcaststream_tapinfo_t *tapinfo, capture_file *cap_file)
{
gboolean was_registered;
if (!tapinfo || !cap_file) {
return;
}
was_registered = tapinfo->is_registered;
if (!tapinfo->is_registered)
register_tap_listener_mcast_stream(tapinfo);
cf_retap_packets(cap_file);
if (!was_registered)
remove_tap_listener_mcast_stream(tapinfo);
}
void
remove_tap_listener_mcast_stream(mcaststream_tapinfo_t *tapinfo)
{
if (tapinfo && tapinfo->is_registered) {
remove_tap_listener(tapinfo);
tapinfo->is_registered = FALSE;
}
}
void
register_tap_listener_mcast_stream(mcaststream_tapinfo_t *tapinfo)
{
GString *error_string;
if (!tapinfo) {
return;
}
if (!tapinfo->is_registered) {
error_string = register_tap_listener("udp", tapinfo,
NULL, 0, mcaststream_reset_cb, mcaststream_packet,
mcaststream_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
tapinfo->is_registered = TRUE;
}
}
static guint16
comparetimes(nstime_t *t1, nstime_t *t2, guint16 burstint_lcl)
{
if(((t2->secs - t1->secs)*1000 + (t2->nsecs - t1->nsecs)/1000000) > burstint_lcl){
return 1;
} else{
return 0;
}
}
static void
buffusagecalc(mcast_stream_info_t *strinfo, packet_info *pinfo, double emptyspeed_lcl)
{
gint32 cur, prev;
nstime_t *buffer;
nstime_t delta;
double timeelapsed;
buffer = strinfo->element.buff;
cur = strinfo->element.last;
if(cur == 0){
cur = buffsize - 1;
prev = cur - 1;
} else if(cur == 1){
prev = buffsize - 1;
cur = 0;
} else{
cur=cur-1;
prev=cur-1;
}
nstime_delta(&delta, &buffer[cur], &buffer[prev]);
timeelapsed = nstime_to_sec(&delta);
strinfo->element.buffusage+=pinfo->fd->pkt_len;
strinfo->element.buffusage-= (guint32) (timeelapsed * emptyspeed_lcl / 8);
if(strinfo->element.buffusage < 0) strinfo->element.buffusage=0;
if(strinfo->element.buffusage > strinfo->element.topbuffusage)
strinfo->element.topbuffusage = strinfo->element.buffusage;
if((strinfo->element.buffusage >= mcast_stream_bufferalarm) && (strinfo->element.buffstatus == 0)){
strinfo->element.buffstatus = 1;
strinfo->element.numbuffalarms++;
} else if(strinfo->element.buffusage < mcast_stream_bufferalarm){
strinfo->element.buffstatus = 0;
}
return;
}
static void
slidingwindow(mcast_stream_info_t *strinfo, packet_info *pinfo)
{
nstime_t *buffer;
gint32 diff;
buffer = strinfo->element.buff;
diff = strinfo->element.last - strinfo->element.first;
if(diff < 0) diff+=buffsize;
if(diff >= (buffsize - 2)){
fprintf(stderr, "Warning: capture buffer full\n");
strinfo->element.first++;
if(strinfo->element.first >= buffsize) strinfo->element.first = strinfo->element.first % buffsize;
}
buffer[strinfo->element.last] = pinfo->rel_ts;
while(comparetimes(&buffer[strinfo->element.first],
&buffer[strinfo->element.last], mcast_stream_burstint)){
strinfo->element.first++;
if(strinfo->element.first >= buffsize) strinfo->element.first = strinfo->element.first % buffsize;
diff--;
}
strinfo->element.burstsize = diff;
if(strinfo->element.burstsize > strinfo->element.topburstsize) {
strinfo->element.topburstsize = strinfo->element.burstsize;
strinfo->element.maxbw = (double)(strinfo->element.topburstsize) * 1000 / mcast_stream_burstint * pinfo->fd->pkt_len * 8;
}
strinfo->element.last++;
if(strinfo->element.last >= buffsize) strinfo->element.last = strinfo->element.last % buffsize;
if((strinfo->element.burstsize >= mcast_stream_trigger) && (strinfo->element.burststatus == 0)){
strinfo->element.burststatus = 1;
strinfo->element.numbursts++;
} else if(strinfo->element.burstsize < mcast_stream_trigger){
strinfo->element.burststatus = 0;
}
strinfo->element.count++;
}
