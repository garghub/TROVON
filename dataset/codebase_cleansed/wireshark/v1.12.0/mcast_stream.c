static gint
mcast_stream_info_cmp(gconstpointer aa, gconstpointer bb)
{
const struct _mcast_stream_info* a = (const struct _mcast_stream_info *)aa;
const struct _mcast_stream_info* b = (const struct _mcast_stream_info *)bb;
if (a==b)
return 0;
if (a==NULL || b==NULL)
return 1;
if (ADDRESSES_EQUAL(&(a->src_addr), &(b->src_addr))
&& (a->src_port == b->src_port)
&& ADDRESSES_EQUAL(&(a->dest_addr), &(b->dest_addr))
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
tapinfo->nstreams = 0;
tapinfo->npackets = 0;
++(tapinfo->launch_count);
return;
}
static void
mcaststream_reset_cb(void *arg)
{
mcaststream_reset((mcaststream_tapinfo_t *)arg);
}
static void
mcaststream_draw(void *arg _U_)
{
mcaststream_dlg_update(the_tapinfo_struct.strinfo_list);
return;
}
static int
mcaststream_packet(void *arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *arg2 _U_)
{
mcaststream_tapinfo_t *tapinfo = (mcaststream_tapinfo_t *)arg;
mcast_stream_info_t tmp_strinfo;
mcast_stream_info_t *strinfo = NULL;
GList* list;
float deltatime;
COPY_ADDRESS(&(tmp_strinfo.src_addr), &(pinfo->src));
tmp_strinfo.src_port = pinfo->srcport;
COPY_ADDRESS(&(tmp_strinfo.dest_addr), &(pinfo->dst));
tmp_strinfo.dest_port = pinfo->destport;
if ((pinfo->dl_dst.type != AT_ETHER) ||
((g_ascii_strncasecmp("01005E", bytes_to_ep_str((const guint8 *)pinfo->dl_dst.data, pinfo->dl_dst.len), 6) != 0) &&
(g_ascii_strncasecmp("3333", bytes_to_ep_str((const guint8 *)pinfo->dl_dst.data, pinfo->dl_dst.len), 4) != 0)) )
return 0;
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
tmp_strinfo.first_frame_num = pinfo->fd->num;
tmp_strinfo.start_sec = (guint32) pinfo->fd->abs_ts.secs;
tmp_strinfo.start_usec = pinfo->fd->abs_ts.nsecs/1000;
tmp_strinfo.start_rel_sec = (guint32) pinfo->rel_ts.secs;
tmp_strinfo.start_rel_usec = pinfo->rel_ts.nsecs/1000;
tmp_strinfo.vlan_id = 0;
tmp_strinfo.average_bw = 0;
tmp_strinfo.total_bytes = 0;
tmp_strinfo.element.buff = (struct timeval *)g_malloc(buffsize * sizeof(struct timeval));
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
strinfo->element.buff = (struct timeval *)g_malloc(buffsize * sizeof(struct timeval));
if (tapinfo->npackets == 0) {
tapinfo->allstreams = (mcast_stream_info_t *)g_malloc(sizeof(mcast_stream_info_t));
tapinfo->allstreams->element.buff =
(struct timeval *)g_malloc(buffsize * sizeof(struct timeval));
tapinfo->allstreams->start_rel_sec = (guint32) pinfo->rel_ts.secs;
tapinfo->allstreams->start_rel_usec = pinfo->rel_ts.nsecs/1000;
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
strinfo->stop_rel_sec = (guint32) pinfo->rel_ts.secs;
strinfo->stop_rel_usec = pinfo->rel_ts.nsecs/1000;
deltatime = ((float)((strinfo->stop_rel_sec * 1000000 + strinfo->stop_rel_usec)
- (strinfo->start_rel_sec*1000000 + strinfo->start_rel_usec)))/1000000;
strinfo->total_bytes = strinfo->total_bytes + pinfo->fd->pkt_len;
if (deltatime > 0)
strinfo->average_bw = (((float)(strinfo->total_bytes*8) / deltatime) / 1000000);
++(strinfo->npackets);
strinfo->apackets = (guint32) (strinfo->npackets / deltatime);
tapinfo->allstreams->stop_rel_sec = (guint32) pinfo->rel_ts.secs;
tapinfo->allstreams->stop_rel_usec = pinfo->rel_ts.nsecs/1000;
deltatime = ((float)((tapinfo->allstreams->stop_rel_sec * 1000000 + tapinfo->allstreams->stop_rel_usec)
- (tapinfo->allstreams->start_rel_sec*1000000 + tapinfo->allstreams->start_rel_usec)))/1000000;
++(tapinfo->npackets);
tapinfo->allstreams->total_bytes = tapinfo->allstreams->total_bytes + pinfo->fd->pkt_len;
if (deltatime > 0)
tapinfo->allstreams->average_bw = (((float)(tapinfo->allstreams->total_bytes *8) / deltatime) / 1000000);
slidingwindow(strinfo, pinfo);
buffusagecalc(strinfo, pinfo, mcast_stream_emptyspeed*1000);
slidingwindow(tapinfo->allstreams, pinfo);
buffusagecalc(tapinfo->allstreams, pinfo, mcast_stream_cumulemptyspeed*1000);
return 1;
}
void
mcaststream_scan(void)
{
gboolean was_registered = the_tapinfo_struct.is_registered;
if (!the_tapinfo_struct.is_registered)
register_tap_listener_mcast_stream();
cf_retap_packets(&cfile);
if (!was_registered)
remove_tap_listener_mcast_stream();
}
const mcaststream_tapinfo_t *
mcaststream_get_info(void)
{
return &the_tapinfo_struct;
}
void
remove_tap_listener_mcast_stream(void)
{
if (the_tapinfo_struct.is_registered) {
remove_tap_listener(&the_tapinfo_struct);
the_tapinfo_struct.is_registered = FALSE;
}
}
void
register_tap_listener_mcast_stream(void)
{
GString *error_string;
if (!the_tapinfo_struct.is_registered) {
error_string = register_tap_listener("udp", &the_tapinfo_struct,
NULL, 0, mcaststream_reset_cb, mcaststream_packet,
mcaststream_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
the_tapinfo_struct.is_registered = TRUE;
}
}
static guint16
comparetimes(struct timeval *t1, struct timeval *t2, guint16 burstint_lcl)
{
if(((t2->tv_sec - t1->tv_sec)*1000 + (t2->tv_usec - t1->tv_usec)/1000) > burstint_lcl){
return 1;
} else{
return 0;
}
}
static void
buffusagecalc(mcast_stream_info_t *strinfo, packet_info *pinfo, double emptyspeed_lcl)
{
time_t sec=0;
gint32 usec=0, cur, prev;
struct timeval *buffer;
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
sec = buffer[cur].tv_sec - buffer[prev].tv_sec;
usec = (gint32)buffer[cur].tv_usec - (gint32)buffer[prev].tv_usec;
timeelapsed = (double)usec/1000000 + (double)sec;
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
struct timeval *buffer;
gint32 diff;
buffer = strinfo->element.buff;
diff = strinfo->element.last - strinfo->element.first;
if(diff < 0) diff+=buffsize;
if(diff >= (buffsize - 2)){
fprintf(stderr, "Warning: capture buffer full\n");
strinfo->element.first++;
if(strinfo->element.first >= buffsize) strinfo->element.first = strinfo->element.first % buffsize;
}
buffer[strinfo->element.last].tv_sec = (guint32) pinfo->rel_ts.secs;
buffer[strinfo->element.last].tv_usec = pinfo->rel_ts.nsecs/1000;
while(comparetimes((struct timeval *)&(buffer[strinfo->element.first]),
(struct timeval *)&(buffer[strinfo->element.last]), mcast_stream_burstint)){
strinfo->element.first++;
if(strinfo->element.first >= buffsize) strinfo->element.first = strinfo->element.first % buffsize;
diff--;
}
strinfo->element.burstsize = diff;
if(strinfo->element.burstsize > strinfo->element.topburstsize) {
strinfo->element.topburstsize = strinfo->element.burstsize;
strinfo->element.maxbw = (float)(strinfo->element.topburstsize) * 1000 / mcast_stream_burstint * pinfo->fd->pkt_len * 8 / 1000000;
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
