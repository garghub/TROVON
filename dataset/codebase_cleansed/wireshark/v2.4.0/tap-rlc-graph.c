int compare_rlc_headers(guint16 ueid1, guint16 channelType1, guint16 channelId1, guint8 rlcMode1, guint8 direction1,
guint16 ueid2, guint16 channelType2, guint16 channelId2, guint8 rlcMode2, guint8 direction2,
gboolean frameIsControl)
{
if (!frameIsControl) {
return (direction1 == direction2) &&
(ueid1 == ueid2) &&
(channelType1 == channelType2) &&
(channelId1 == channelId2) &&
(rlcMode1 == rlcMode2);
}
else {
if (frameIsControl && (rlcMode1 == RLC_AM_MODE) && (rlcMode2 == RLC_AM_MODE)) {
return ((direction1 != direction2) &&
(ueid1 == ueid2) &&
(channelType1 == channelType2) &&
(channelId1 == channelId2));
}
else {
return FALSE;
}
}
}
static int
tap_lte_rlc_packet(void *pct, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *vip)
{
int n;
gboolean is_unique = TRUE;
th_t *th = (th_t *)pct;
const rlc_lte_tap_info *header = (const rlc_lte_tap_info*)vip;
for (n=0; n < th->num_hdrs; n++) {
rlc_lte_tap_info *stored = th->rlchdrs[n];
if (compare_rlc_headers(stored->ueid, stored->channelType, stored->channelId, stored->rlcMode, stored->direction,
header->ueid, header->channelType, header->channelId, header->rlcMode, header->direction,
header->isControlPDU)) {
is_unique = FALSE;
break;
}
}
if (is_unique && (th->num_hdrs < MAX_SUPPORTED_CHANNELS)) {
th->rlchdrs[th->num_hdrs] = g_new(rlc_lte_tap_info,1);
*(th->rlchdrs[th->num_hdrs]) = *header;
if (th->rlchdrs[th->num_hdrs]->isControlPDU) {
th->rlchdrs[th->num_hdrs]->direction = !th->rlchdrs[th->num_hdrs]->direction;
}
th->num_hdrs++;
}
return 0;
}
rlc_lte_tap_info *select_rlc_lte_session(capture_file *cf,
struct rlc_segment *hdrs,
gchar **err_msg)
{
frame_data *fdata;
epan_dissect_t edt;
dfilter_t *sfcode;
GString *error_string;
nstime_t rel_ts;
th_t th = {0, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}};
if (cf->state == FILE_CLOSED) {
return NULL;
}
fdata = cf->current_frame;
if (!dfilter_compile("rlc-lte", &sfcode, err_msg)) {
return NULL;
}
if (!cf_read_record(cf, fdata)) {
return NULL;
}
error_string = register_tap_listener("rlc-lte", &th, NULL, 0, NULL, tap_lte_rlc_packet, NULL);
if (error_string){
fprintf(stderr, "wireshark: Couldn't register rlc_lte_graph tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
epan_dissect_init(&edt, cf->epan, TRUE, FALSE);
epan_dissect_prime_with_dfilter(&edt, sfcode);
epan_dissect_run_with_taps(&edt, cf->cd_t, &cf->phdr, frame_tvbuff_new_buffer(fdata, &cf->buf), fdata, NULL);
rel_ts = edt.pi.rel_ts;
epan_dissect_cleanup(&edt);
remove_tap_listener(&th);
if (th.num_hdrs == 0){
*err_msg = g_strdup("Selected packet doesn't have an RLC PDU");
return NULL;
}
if (th.num_hdrs>1){
*err_msg = g_strdup("The selected packet has more than one LTE RLC channel in it.");
return NULL;
}
hdrs->num = fdata->num;
hdrs->rel_secs = (guint32) rel_ts.secs;
hdrs->rel_usecs = rel_ts.nsecs/1000;
hdrs->abs_secs = (guint32) fdata->abs_ts.secs;
hdrs->abs_usecs = fdata->abs_ts.nsecs/1000;
hdrs->ueid = th.rlchdrs[0]->ueid;
hdrs->channelType = th.rlchdrs[0]->channelType;
hdrs->channelId = th.rlchdrs[0]->channelId;
hdrs->rlcMode = th.rlchdrs[0]->rlcMode;
hdrs->isControlPDU = th.rlchdrs[0]->isControlPDU;
hdrs->direction = !hdrs->isControlPDU ? th.rlchdrs[0]->direction : !th.rlchdrs[0]->direction;
return th.rlchdrs[0];
}
int rlc_lte_tap_for_graph_data(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
struct rlc_graph *graph = (struct rlc_graph *)pct;
const rlc_lte_tap_info *rlchdr = (const rlc_lte_tap_info*)vip;
if (compare_rlc_headers(graph->ueid, graph->channelType, graph->channelId, graph->rlcMode, graph->direction,
rlchdr->ueid, rlchdr->channelType, rlchdr->channelId, rlchdr->rlcMode, rlchdr->direction,
rlchdr->isControlPDU)) {
struct rlc_segment *segment = (struct rlc_segment *)g_malloc(sizeof(struct rlc_segment));
segment->next = NULL;
segment->num = pinfo->num;
segment->rel_secs = (guint32) pinfo->rel_ts.secs;
segment->rel_usecs = pinfo->rel_ts.nsecs/1000;
segment->abs_secs = (guint32) pinfo->abs_ts.secs;
segment->abs_usecs = pinfo->abs_ts.nsecs/1000;
segment->ueid = rlchdr->ueid;
segment->channelType = rlchdr->channelType;
segment->channelId = rlchdr->channelId;
segment->direction = rlchdr->direction;
segment->rlcMode = rlchdr->rlcMode;
segment->isControlPDU = rlchdr->isControlPDU;
if (!rlchdr->isControlPDU) {
segment->SN = rlchdr->sequenceNumber;
segment->isResegmented = rlchdr->isResegmented;
segment->pduLength = rlchdr->pduLength;
}
else {
gint n;
segment->ACKNo = rlchdr->ACKNo;
segment->noOfNACKs = rlchdr->noOfNACKs;
for (n=0; n < rlchdr->noOfNACKs; n++) {
segment->NACKs[n] = rlchdr->NACKs[n];
}
}
if (graph->segments) {
graph->last_segment->next = segment;
} else {
graph->segments = segment;
}
graph->last_segment = segment;
}
return 0;
}
gboolean rlc_graph_segment_list_get(capture_file *cf, struct rlc_graph *g, gboolean stream_known,
char **err_string)
{
struct rlc_segment current;
GString *error_string;
g_log(NULL, G_LOG_LEVEL_DEBUG, "graph_segment_list_get()");
if (!cf || !g) {
return FALSE;
}
if (!stream_known) {
struct rlc_lte_tap_info *header = select_rlc_lte_session(cf, &current, err_string);
if (!header) {
return FALSE;
}
g->channelSet = TRUE;
g->ueid = header->ueid;
g->channelType = header->channelType;
g->channelId = header->channelId;
g->rlcMode = header->rlcMode;
g->direction = header->direction;
}
g->last_segment = NULL;
error_string = register_tap_listener("rlc-lte", g, "rlc-lte", 0, NULL, rlc_lte_tap_for_graph_data, NULL);
if (error_string) {
fprintf(stderr, "wireshark: Couldn't register rlc_graph tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
cf_retap_packets(cf);
remove_tap_listener(g);
if (g->last_segment == NULL) {
*err_string = g_strdup("No packets found");
return FALSE;
}
return TRUE;
}
void rlc_graph_segment_list_free(struct rlc_graph * g)
{
struct rlc_segment *segment;
while (g->segments) {
segment = g->segments->next;
g_free(g->segments);
g->segments = segment;
}
g->segments = NULL;
}
