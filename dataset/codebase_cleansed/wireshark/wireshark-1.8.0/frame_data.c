static gint p_compare(gconstpointer a, gconstpointer b)
{
const frame_proto_data *ap = (const frame_proto_data *)a;
const frame_proto_data *bp = (const frame_proto_data *)b;
if (ap -> proto > bp -> proto)
return 1;
else if (ap -> proto == bp -> proto)
return 0;
else
return -1;
}
void
p_add_proto_data(frame_data *fd, int proto, void *proto_data)
{
frame_proto_data *p1 = se_alloc(sizeof(frame_proto_data));
p1->proto = proto;
p1->proto_data = proto_data;
fd -> pfd = g_slist_insert_sorted(fd -> pfd,
(gpointer *)p1,
p_compare);
}
void *
p_get_proto_data(frame_data *fd, int proto)
{
frame_proto_data temp, *p1;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(fd->pfd, (gpointer *)&temp, p_compare);
if (item) {
p1 = (frame_proto_data *)item->data;
return p1->proto_data;
}
return NULL;
}
void
p_remove_proto_data(frame_data *fd, int proto)
{
frame_proto_data temp;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(fd->pfd, (gpointer *)&temp, p_compare);
if (item) {
fd->pfd = g_slist_remove(fd->pfd, item->data);
}
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
return COMPARE_TS(del_cap_ts);
case TS_DELTA_DIS:
return COMPARE_TS(del_dis_ts);
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
return COMPARE_TS(del_cap_ts);
case COL_DELTA_TIME_DIS:
return COMPARE_TS(del_dis_ts);
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
fdata->flags.passed_dfilter = 0;
fdata->flags.dependent_of_displayed = 0;
fdata->flags.encoding = PACKET_CHAR_ENC_CHAR_ASCII;
fdata->flags.visited = 0;
fdata->flags.marked = 0;
fdata->flags.ref_time = 0;
fdata->flags.ignored = 0;
fdata->flags.has_ts = (phdr->presence_flags & WTAP_HAS_TS) ? 1 : 0;
fdata->flags.has_if_id = (phdr->presence_flags & WTAP_HAS_INTERFACE_ID) ? 1 : 0;
fdata->color_filter = NULL;
fdata->abs_ts.secs = phdr->ts.secs;
fdata->abs_ts.nsecs = phdr->ts.nsecs;
fdata->shift_offset.secs = 0;
fdata->shift_offset.nsecs = 0;
fdata->rel_ts.secs = 0;
fdata->rel_ts.nsecs = 0;
fdata->del_dis_ts.secs = 0;
fdata->del_dis_ts.nsecs = 0;
fdata->del_cap_ts.secs = 0;
fdata->del_cap_ts.nsecs = 0;
fdata->opt_comment = phdr->opt_comment;
}
void
frame_data_set_before_dissect(frame_data *fdata,
nstime_t *elapsed_time,
nstime_t *first_ts,
nstime_t *prev_dis_ts,
nstime_t *prev_cap_ts)
{
if (nstime_is_unset(first_ts))
*first_ts = fdata->abs_ts;
if(fdata->flags.ref_time)
*first_ts = fdata->abs_ts;
if (nstime_is_unset(prev_cap_ts))
*prev_cap_ts = fdata->abs_ts;
nstime_delta(&fdata->rel_ts, &fdata->abs_ts, first_ts);
if ((gint32)elapsed_time->secs < fdata->rel_ts.secs
|| ((gint32)elapsed_time->secs == fdata->rel_ts.secs && (gint32)elapsed_time->nsecs < fdata->rel_ts.nsecs)) {
*elapsed_time = fdata->rel_ts;
}
if (nstime_is_unset(prev_dis_ts))
nstime_set_zero(&fdata->del_dis_ts);
else
nstime_delta(&fdata->del_dis_ts, &fdata->abs_ts, prev_dis_ts);
nstime_delta(&fdata->del_cap_ts, &fdata->abs_ts, prev_cap_ts);
*prev_cap_ts = fdata->abs_ts;
}
void
frame_data_set_after_dissect(frame_data *fdata,
guint32 *cum_bytes,
nstime_t *prev_dis_ts)
{
if(fdata->flags.ref_time){
*cum_bytes = fdata->pkt_len;
fdata->cum_bytes = *cum_bytes;
} else {
*cum_bytes += fdata->pkt_len;
fdata->cum_bytes = *cum_bytes;
}
*prev_dis_ts = fdata->abs_ts;
}
void
frame_data_cleanup(frame_data *fdata)
{
if (fdata->pfd)
g_slist_free(fdata->pfd);
fdata->pfd = NULL;
}
