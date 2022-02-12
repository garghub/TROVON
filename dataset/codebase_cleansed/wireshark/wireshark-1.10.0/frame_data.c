static gint
p_compare(gconstpointer a, gconstpointer b)
{
const frame_proto_data *ap = (const frame_proto_data *)a;
const frame_proto_data *bp = (const frame_proto_data *)b;
if (ap -> proto > bp -> proto){
return 1;
}else if (ap -> proto == bp -> proto){
if (ap -> key > bp -> key){
return 1;
}else if (ap -> key == bp -> key){
return 0;
}
return -1;
}else{
return -1;
}
}
void
p_add_proto_data(frame_data *fd, int proto, guint8 key, void *proto_data)
{
frame_proto_data *p1 = (frame_proto_data *)wmem_alloc(wmem_file_scope(), sizeof(frame_proto_data));
p1->proto = proto;
p1->key = key;
p1->proto_data = proto_data;
fd -> pfd = g_slist_insert_sorted(fd -> pfd,
(gpointer *)p1,
p_compare);
}
void *
p_get_proto_data(frame_data *fd, int proto, guint8 key)
{
frame_proto_data temp, *p1;
GSList *item;
temp.proto = proto;
temp.key = key;
temp.proto_data = NULL;
item = g_slist_find_custom(fd->pfd, (gpointer *)&temp, p_compare);
if (item) {
p1 = (frame_proto_data *)item->data;
return p1->proto_data;
}
return NULL;
}
void
p_remove_proto_data(frame_data *fd, int proto, guint8 key)
{
frame_proto_data temp;
GSList *item;
temp.proto = proto;
temp.key = key;
temp.proto_data = NULL;
item = g_slist_find_custom(fd->pfd, (gpointer *)&temp, p_compare);
if (item) {
fd->pfd = g_slist_remove(fd->pfd, item->data);
}
}
gchar *
p_get_proto_name_and_key(frame_data *fd, guint pfd_index){
frame_proto_data *temp;
temp = (frame_proto_data*)g_slist_nth_data(fd->pfd, pfd_index);
return ep_strdup_printf("[%s, key %u]",proto_get_protocol_name(temp->proto), temp->key);
}
void
frame_delta_abs_time(const frame_data *fdata, const frame_data *prev, nstime_t *delta)
{
if (prev) {
nstime_delta(delta, &fdata->abs_ts, &prev->abs_ts);
} else {
nstime_set_zero(delta);
}
}
static gint
frame_data_time_delta_compare(const frame_data *fdata1, const frame_data *fdata2)
{
nstime_t del_cap_ts1, del_cap_ts2;
frame_delta_abs_time(fdata1, fdata1->prev_cap, &del_cap_ts1);
frame_delta_abs_time(fdata2, fdata2->prev_cap, &del_cap_ts2);
return COMPARE_TS_REAL(del_cap_ts1, del_cap_ts2);
}
static gint
frame_data_time_delta_dis_compare(const frame_data *fdata1, const frame_data *fdata2)
{
nstime_t del_dis_ts1, del_dis_ts2;
frame_delta_abs_time(fdata1, fdata1->prev_dis, &del_dis_ts1);
frame_delta_abs_time(fdata2, fdata2->prev_dis, &del_dis_ts2);
return COMPARE_TS_REAL(del_dis_ts1, del_dis_ts2);
}
gint
frame_data_compare(const frame_data *fdata1, const frame_data *fdata2, int field)
{
switch (field) {
case COL_NUMBER:
return COMPARE_FRAME_NUM();
case COL_CLS_TIME:
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
case TS_ABSOLUTE_WITH_DATE:
case TS_UTC:
case TS_UTC_WITH_DATE:
case TS_EPOCH:
return COMPARE_TS(abs_ts);
case TS_RELATIVE:
return COMPARE_TS(rel_ts);
case TS_DELTA:
return frame_data_time_delta_compare(fdata1, fdata2);
case TS_DELTA_DIS:
return frame_data_time_delta_dis_compare(fdata1, fdata2);
case TS_NOT_SET:
return 0;
}
return 0;
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
return COMPARE_TS(abs_ts);
case COL_REL_TIME:
return COMPARE_TS(rel_ts);
case COL_DELTA_TIME:
return frame_data_time_delta_compare(fdata1, fdata2);
case COL_DELTA_TIME_DIS:
return frame_data_time_delta_dis_compare(fdata1, fdata2);
case COL_PACKET_LENGTH:
return COMPARE_NUM(pkt_len);
case COL_CUMULATIVE_BYTES:
return COMPARE_NUM(cum_bytes);
}
g_return_val_if_reached(0);
}
void
frame_data_init(frame_data *fdata, guint32 num,
const struct wtap_pkthdr *phdr, gint64 offset,
guint32 cum_bytes)
{
fdata->pfd = NULL;
fdata->num = num;
fdata->interface_id = phdr->interface_id;
fdata->pkt_len = phdr->len;
fdata->cum_bytes = cum_bytes + phdr->len;
fdata->cap_len = phdr->caplen;
fdata->file_off = offset;
fdata->subnum = 0;
g_assert(phdr->pkt_encap <= G_MAXINT16);
fdata->lnk_t = (gint16) phdr->pkt_encap;
fdata->pack_flags = phdr->pack_flags;
fdata->flags.passed_dfilter = 0;
fdata->flags.dependent_of_displayed = 0;
fdata->flags.encoding = PACKET_CHAR_ENC_CHAR_ASCII;
fdata->flags.visited = 0;
fdata->flags.marked = 0;
fdata->flags.ref_time = 0;
fdata->flags.ignored = 0;
fdata->flags.has_ts = (phdr->presence_flags & WTAP_HAS_TS) ? 1 : 0;
fdata->flags.has_if_id = (phdr->presence_flags & WTAP_HAS_INTERFACE_ID) ? 1 : 0;
fdata->flags.has_pack_flags = (phdr->presence_flags & WTAP_HAS_PACK_FLAGS) ? 1 : 0;
fdata->color_filter = NULL;
fdata->abs_ts.secs = phdr->ts.secs;
fdata->abs_ts.nsecs = phdr->ts.nsecs;
fdata->shift_offset.secs = 0;
fdata->shift_offset.nsecs = 0;
fdata->rel_ts.secs = 0;
fdata->rel_ts.nsecs = 0;
fdata->prev_dis = NULL;
fdata->prev_cap = NULL;
fdata->opt_comment = phdr->opt_comment;
}
void
frame_data_set_before_dissect(frame_data *fdata,
nstime_t *elapsed_time,
nstime_t *first_ts,
const frame_data *prev_dis,
const frame_data *prev_cap)
{
if (nstime_is_unset(first_ts))
*first_ts = fdata->abs_ts;
if(fdata->flags.ref_time)
*first_ts = fdata->abs_ts;
nstime_delta(&fdata->rel_ts, &fdata->abs_ts, first_ts);
if ((gint32)elapsed_time->secs < fdata->rel_ts.secs
|| ((gint32)elapsed_time->secs == fdata->rel_ts.secs && (gint32)elapsed_time->nsecs < fdata->rel_ts.nsecs)) {
*elapsed_time = fdata->rel_ts;
}
fdata->prev_dis = prev_dis;
fdata->prev_cap = prev_cap;
}
void
frame_data_set_after_dissect(frame_data *fdata,
guint32 *cum_bytes)
{
if(fdata->flags.ref_time){
*cum_bytes = fdata->pkt_len;
fdata->cum_bytes = *cum_bytes;
} else {
*cum_bytes += fdata->pkt_len;
fdata->cum_bytes = *cum_bytes;
}
}
void
frame_data_reset(frame_data *fdata)
{
fdata->flags.visited = 0;
if (fdata->pfd) {
g_slist_free(fdata->pfd);
fdata->pfd = NULL;
}
}
void
frame_data_destroy(frame_data *fdata)
{
if (fdata->pfd) {
g_slist_free(fdata->pfd);
fdata->pfd = NULL;
}
if (fdata->opt_comment) {
g_free(fdata->opt_comment);
fdata->opt_comment = NULL;
}
}
