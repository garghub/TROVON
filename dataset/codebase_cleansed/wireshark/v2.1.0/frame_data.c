void
frame_delta_abs_time(const struct epan_session *epan, const frame_data *fdata, guint32 prev_num, nstime_t *delta)
{
const nstime_t *prev_abs_ts = (prev_num) ? epan_get_frame_ts(epan, prev_num) : NULL;
if (prev_abs_ts) {
nstime_delta(delta, &fdata->abs_ts, prev_abs_ts);
} else {
nstime_set_zero(delta);
}
}
static gint
frame_data_time_delta_compare(const struct epan_session *epan, const frame_data *fdata1, const frame_data *fdata2)
{
nstime_t del_cap_ts1, del_cap_ts2;
frame_delta_abs_time(epan, fdata1, fdata1->num - 1, &del_cap_ts1);
frame_delta_abs_time(epan, fdata2, fdata2->num - 1, &del_cap_ts2);
return COMPARE_TS_REAL(del_cap_ts1, del_cap_ts2);
}
static gint
frame_data_time_delta_rel_compare(const struct epan_session *epan, const frame_data *fdata1, const frame_data *fdata2)
{
nstime_t del_rel_ts1, del_rel_ts2;
frame_delta_abs_time(epan, fdata1, fdata1->frame_ref_num, &del_rel_ts1);
frame_delta_abs_time(epan, fdata2, fdata2->frame_ref_num, &del_rel_ts2);
return COMPARE_TS_REAL(del_rel_ts1, del_rel_ts2);
}
static gint
frame_data_time_delta_dis_compare(const struct epan_session *epan, const frame_data *fdata1, const frame_data *fdata2)
{
nstime_t del_dis_ts1, del_dis_ts2;
frame_delta_abs_time(epan, fdata1, fdata1->prev_dis_num, &del_dis_ts1);
frame_delta_abs_time(epan, fdata2, fdata2->prev_dis_num, &del_dis_ts2);
return COMPARE_TS_REAL(del_dis_ts1, del_dis_ts2);
}
gint
frame_data_compare(const struct epan_session *epan, const frame_data *fdata1, const frame_data *fdata2, int field)
{
switch (field) {
case COL_NUMBER:
return COMPARE_FRAME_NUM();
case COL_CLS_TIME:
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
case TS_ABSOLUTE_WITH_YMD:
case TS_ABSOLUTE_WITH_YDOY:
case TS_UTC:
case TS_UTC_WITH_YMD:
case TS_UTC_WITH_YDOY:
case TS_EPOCH:
return COMPARE_TS(abs_ts);
case TS_RELATIVE:
return frame_data_time_delta_rel_compare(epan, fdata1, fdata2);
case TS_DELTA:
return frame_data_time_delta_compare(epan, fdata1, fdata2);
case TS_DELTA_DIS:
return frame_data_time_delta_dis_compare(epan, fdata1, fdata2);
case TS_NOT_SET:
return 0;
}
return 0;
case COL_ABS_TIME:
case COL_ABS_YMD_TIME:
case COL_ABS_YDOY_TIME:
case COL_UTC_TIME:
case COL_UTC_YMD_TIME:
case COL_UTC_YDOY_TIME:
return COMPARE_TS(abs_ts);
case COL_REL_TIME:
return frame_data_time_delta_rel_compare(epan, fdata1, fdata2);
case COL_DELTA_TIME:
return frame_data_time_delta_compare(epan, fdata1, fdata2);
case COL_DELTA_TIME_DIS:
return frame_data_time_delta_dis_compare(epan, fdata1, fdata2);
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
fdata->pkt_len = phdr->len;
fdata->cum_bytes = cum_bytes + phdr->len;
fdata->cap_len = phdr->caplen;
fdata->file_off = offset;
fdata->subnum = 0;
g_assert(phdr->pkt_encap <= G_MAXINT16);
fdata->flags.passed_dfilter = 0;
fdata->flags.dependent_of_displayed = 0;
fdata->flags.encoding = PACKET_CHAR_ENC_CHAR_ASCII;
fdata->flags.visited = 0;
fdata->flags.marked = 0;
fdata->flags.ref_time = 0;
fdata->flags.ignored = 0;
fdata->flags.has_ts = (phdr->presence_flags & WTAP_HAS_TS) ? 1 : 0;
fdata->flags.has_phdr_comment = (phdr->opt_comment != NULL);
fdata->flags.has_user_comment = 0;
fdata->flags.need_colorize = 0;
fdata->tsprec = (gint16)phdr->pkt_tsprec;
fdata->color_filter = NULL;
fdata->abs_ts = phdr->ts;
fdata->shift_offset.secs = 0;
fdata->shift_offset.nsecs = 0;
fdata->frame_ref_num = 0;
fdata->prev_dis_num = 0;
}
void
frame_data_set_before_dissect(frame_data *fdata,
nstime_t *elapsed_time,
const frame_data **frame_ref,
const frame_data *prev_dis)
{
nstime_t rel_ts;
if (*frame_ref == NULL)
*frame_ref = fdata;
if(fdata->flags.ref_time)
*frame_ref = fdata;
nstime_delta(&rel_ts, &fdata->abs_ts, &(*frame_ref)->abs_ts);
if ((gint32)elapsed_time->secs < rel_ts.secs
|| ((gint32)elapsed_time->secs == rel_ts.secs && (gint32)elapsed_time->nsecs < rel_ts.nsecs)) {
*elapsed_time = rel_ts;
}
fdata->frame_ref_num = (*frame_ref != fdata) ? (*frame_ref)->num : 0;
fdata->prev_dis_num = (prev_dis) ? prev_dis->num : 0;
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
fdata->subnum = 0;
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
}
