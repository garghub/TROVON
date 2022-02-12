static void packet_range_calc(packet_range_t *range) {
guint32 framenum;
guint32 mark_low;
guint32 mark_high;
guint32 displayed_mark_low;
guint32 displayed_mark_high;
frame_data *packet;
range->selected_packet = 0;
mark_low = 0;
mark_high = 0;
range->mark_range_cnt = 0;
range->ignored_cnt = 0;
range->ignored_marked_cnt = 0;
range->ignored_mark_range_cnt = 0;
range->ignored_user_range_cnt = 0;
displayed_mark_low = 0;
displayed_mark_high = 0;
range->displayed_cnt = 0;
range->displayed_marked_cnt = 0;
range->displayed_mark_range_cnt = 0;
range->displayed_plus_dependents_cnt = 0;
range->displayed_ignored_cnt = 0;
range->displayed_ignored_marked_cnt = 0;
range->displayed_ignored_mark_range_cnt = 0;
range->displayed_ignored_user_range_cnt = 0;
g_assert(range->cf != NULL);
if (range->cf->frames != NULL) {
for(framenum = 1; framenum <= range->cf->count; framenum++) {
packet = frame_data_sequence_find(range->cf->frames, framenum);
if (range->cf->current_frame == packet) {
range->selected_packet = framenum;
}
if (packet->flags.passed_dfilter) {
range->displayed_cnt++;
}
if (packet->flags.passed_dfilter ||
packet->flags.dependent_of_displayed) {
range->displayed_plus_dependents_cnt++;
}
if (packet->flags.marked) {
if (packet->flags.ignored) {
range->ignored_marked_cnt++;
}
if (packet->flags.passed_dfilter) {
range->displayed_marked_cnt++;
if (packet->flags.ignored) {
range->displayed_ignored_marked_cnt++;
}
if (displayed_mark_low == 0) {
displayed_mark_low = framenum;
}
if (framenum > displayed_mark_high) {
displayed_mark_high = framenum;
}
}
if (mark_low == 0) {
mark_low = framenum;
}
if (framenum > mark_high) {
mark_high = framenum;
}
}
if (packet->flags.ignored) {
range->ignored_cnt++;
if (packet->flags.passed_dfilter) {
range->displayed_ignored_cnt++;
}
}
}
for(framenum = 1; framenum <= range->cf->count; framenum++) {
packet = frame_data_sequence_find(range->cf->frames, framenum);
if (framenum >= mark_low &&
framenum <= mark_high)
{
range->mark_range_cnt++;
if (packet->flags.ignored) {
range->ignored_mark_range_cnt++;
}
}
if (framenum >= displayed_mark_low &&
framenum <= displayed_mark_high)
{
if (packet->flags.passed_dfilter) {
range->displayed_mark_range_cnt++;
if (packet->flags.ignored) {
range->displayed_ignored_mark_range_cnt++;
}
}
}
}
#if 0
if (range->cf->marked_count != 0) {
range->mark_range = mark_high - mark_low + 1;
}
if (range->displayed_marked_cnt != 0) {
range->displayed_mark_range = displayed_mark_high - displayed_mark_low + 1;
}
#endif
}
}
static void packet_range_calc_user(packet_range_t *range) {
guint32 framenum;
frame_data *packet;
range->user_range_cnt = 0;
range->ignored_user_range_cnt = 0;
range->displayed_user_range_cnt = 0;
range->displayed_ignored_user_range_cnt = 0;
g_assert(range->cf != NULL);
if (range->cf->frames != NULL) {
for(framenum = 1; framenum <= range->cf->count; framenum++) {
packet = frame_data_sequence_find(range->cf->frames, framenum);
if (value_is_in_range(range->user_range, framenum)) {
range->user_range_cnt++;
if (packet->flags.ignored) {
range->ignored_user_range_cnt++;
}
if (packet->flags.passed_dfilter) {
range->displayed_user_range_cnt++;
if (packet->flags.ignored) {
range->displayed_ignored_user_range_cnt++;
}
}
}
}
}
}
void packet_range_init(packet_range_t *range, capture_file *cf) {
memset(range, 0, sizeof(packet_range_t));
range->process = range_process_all;
range->user_range = NULL;
range->cf = cf;
packet_range_calc(range);
packet_range_calc_user(range);
}
convert_ret_t packet_range_check(packet_range_t *range) {
if (range->process == range_process_user_range && range->user_range == NULL) {
return range->user_range_status;
}
return CVT_NO_ERROR;
}
void packet_range_process_init(packet_range_t *range) {
range->marked_range_active = FALSE;
range->selected_done = FALSE;
if (range->process_filtered == FALSE) {
range->marked_range_left = range->mark_range_cnt;
} else {
range->marked_range_left = range->displayed_mark_range_cnt;
}
}
gboolean packet_range_process_all(packet_range_t *range) {
return range->process == range_process_all && !range->process_filtered && !range->remove_ignored;
}
range_process_e packet_range_process_packet(packet_range_t *range, frame_data *fdata) {
if (range->remove_ignored && fdata->flags.ignored) {
return range_process_next;
}
g_assert(range->cf != NULL);
switch(range->process) {
case(range_process_all):
break;
case(range_process_selected):
if (range->selected_done) {
return range_processing_finished;
}
if (fdata->num != range->cf->current_frame->num) {
return range_process_next;
}
range->selected_done = TRUE;
break;
case(range_process_marked):
if (fdata->flags.marked == FALSE) {
return range_process_next;
}
break;
case(range_process_marked_range):
if (range->marked_range_left == 0) {
return range_processing_finished;
}
if (fdata->flags.marked == TRUE) {
range->marked_range_active = TRUE;
}
if (range->marked_range_active == FALSE ) {
return range_process_next;
}
if (!range->process_filtered ||
(range->process_filtered && fdata->flags.passed_dfilter == TRUE))
{
range->marked_range_left--;
}
break;
case(range_process_user_range):
if (value_is_in_range(range->user_range, fdata->num) == FALSE) {
return range_process_next;
}
break;
default:
g_assert_not_reached();
}
if ((range->process_filtered && fdata->flags.passed_dfilter == FALSE) &&
!(range->include_dependents && fdata->flags.dependent_of_displayed)) {
return range_process_next;
}
return range_process_this;
}
void packet_range_convert_str(packet_range_t *range, const gchar *es)
{
range_t *new_range;
convert_ret_t ret;
if (range->user_range != NULL)
wmem_free(NULL, range->user_range);
g_assert(range->cf != NULL);
ret = range_convert_str(NULL, &new_range, es, range->cf->count);
if (ret != CVT_NO_ERROR) {
range->user_range = NULL;
range->user_range_status = ret;
range->user_range_cnt = 0;
range->ignored_user_range_cnt = 0;
range->displayed_user_range_cnt = 0;
range->displayed_ignored_user_range_cnt = 0;
return;
}
range->user_range = new_range;
packet_range_calc_user(range);
}
