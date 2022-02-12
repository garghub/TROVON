void voip_calls_reset(voip_calls_tapinfo_t *tapinfo)
{
voip_calls_info_t *callsinfo;
voip_rtp_tapinfo_t *rtp_tapinfo = &the_tapinfo_rtp_struct;
voip_rtp_stream_info_t *strinfo;
seq_analysis_item_t *graph_item;
GList *list;
#ifdef HAVE_LIBPORTAUDIO
reset_rtp_player();
#endif
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
callsinfo = (voip_calls_info_t *)list->data;
g_free(callsinfo->call_id);
g_free(callsinfo->from_identity);
g_free(callsinfo->to_identity);
g_free((void *)(callsinfo->initial_speaker.data));
g_free(callsinfo->protocol_name);
g_free(callsinfo->call_comment);
if (callsinfo->free_prot_info && callsinfo->prot_info)
callsinfo->free_prot_info(callsinfo->prot_info);
g_free(list->data);
list = g_list_next(list);
}
g_list_free(tapinfo->callsinfo_list);
if(NULL!=tapinfo->callsinfo_hashtable[SIP_HASH])
g_hash_table_remove_all (tapinfo->callsinfo_hashtable[SIP_HASH]);
tapinfo->callsinfo_list = NULL;
tapinfo->ncalls = 0;
tapinfo->npackets = 0;
tapinfo->start_packets = 0;
tapinfo->completed_calls = 0;
tapinfo->rejected_calls = 0;
tapinfo->reversed= 0;
if(NULL!=tapinfo->graph_analysis->ht)
g_hash_table_remove_all(tapinfo->graph_analysis->ht);
list = g_list_first(tapinfo->graph_analysis->list);
while (list)
{
graph_item = (seq_analysis_item_t *)list->data;
g_free(graph_item->frame_label);
g_free(graph_item->comment);
g_free((void *)graph_item->src_addr.data);
g_free((void *)graph_item->dst_addr.data);
g_free(graph_item->time_str);
g_free(list->data);
list = g_list_next(list);
}
g_list_free(tapinfo->graph_analysis->list);
tapinfo->graph_analysis->nconv = 0;
tapinfo->graph_analysis->list = NULL;
++(tapinfo->launch_count);
list = g_list_first(rtp_tapinfo->list);
while(list)
{
strinfo = (voip_rtp_stream_info_t *)list->data;
g_free(strinfo->pt_str);
list = g_list_next(list);
}
g_list_free(rtp_tapinfo->list);
rtp_tapinfo->list = NULL;
return;
}
void graph_analysis_data_init(void) {
the_tapinfo_struct.graph_analysis = (seq_analysis_info_t *)g_malloc(sizeof(seq_analysis_info_t));
the_tapinfo_struct.graph_analysis->nconv = 0;
the_tapinfo_struct.graph_analysis->list = NULL;
the_tapinfo_struct.graph_analysis->ht= g_hash_table_new(g_int_hash, g_int_equal);
}
static void add_to_graph(voip_calls_tapinfo_t *tapinfo _U_, packet_info *pinfo, const gchar *frame_label, const gchar *comment, guint16 call_num, address *src_addr, address *dst_addr, guint16 line_style)
{
seq_analysis_item_t *gai;
gchar time_str[COL_MAX_LEN];
gai = (seq_analysis_item_t *)g_malloc(sizeof(seq_analysis_item_t));
gai->fd = pinfo->fd;
COPY_ADDRESS(&(gai->src_addr),src_addr);
COPY_ADDRESS(&(gai->dst_addr),dst_addr);
gai->port_src=pinfo->srcport;
gai->port_dst=pinfo->destport;
if (frame_label != NULL)
gai->frame_label = g_strdup(frame_label);
else
gai->frame_label = g_strdup("");
if (comment != NULL)
gai->comment = g_strdup(comment);
else
gai->comment = g_strdup("");
gai->conv_num=call_num;
gai->line_style=line_style;
set_fd_time(cfile.epan, gai->fd, time_str);
gai->time_str = g_strdup(time_str);
gai->display=FALSE;
tapinfo->graph_analysis->list = g_list_prepend(tapinfo->graph_analysis->list, gai);
g_hash_table_insert(tapinfo->graph_analysis->ht, &gai->fd->num, gai);
}
static int append_to_frame_graph(voip_calls_tapinfo_t *tapinfo _U_, guint32 frame_num, const gchar *new_frame_label, const gchar *new_comment)
{
seq_analysis_item_t *gai=NULL;
gchar *frame_label = NULL;
gchar *comment = NULL;
if(NULL!=tapinfo->graph_analysis->ht)
gai=(seq_analysis_item_t *)g_hash_table_lookup(tapinfo->graph_analysis->ht, &frame_num);
if(gai) {
frame_label = gai->frame_label;
comment = gai->comment;
if (new_frame_label != NULL) {
gai->frame_label = g_strdup_printf("%s %s", frame_label, new_frame_label);
g_free(frame_label);
}
if (new_comment != NULL) {
gai->comment = g_strdup_printf("%s %s", comment, new_comment);
g_free(comment);
}
}
return gai? 1 : 0;
}
static int change_frame_graph(voip_calls_tapinfo_t *tapinfo _U_, guint32 frame_num, const gchar *new_frame_label, const gchar *new_comment)
{
seq_analysis_item_t *gai=NULL;
gchar *frame_label = NULL;
gchar *comment = NULL;
if(NULL!=tapinfo->graph_analysis->ht)
gai=(seq_analysis_item_t *)g_hash_table_lookup(tapinfo->graph_analysis->ht, &frame_num);
if(gai) {
frame_label = gai->frame_label;
comment = gai->comment;
if (new_frame_label != NULL) {
gai->frame_label = g_strdup(new_frame_label);
g_free(frame_label);
}
if (new_comment != NULL) {
gai->comment = g_strdup(new_comment);
g_free(comment);
}
}
return gai? 1 : 0;
}
static guint change_call_num_graph(voip_calls_tapinfo_t *tapinfo _U_, guint16 call_num, guint16 new_call_num)
{
seq_analysis_item_t *gai;
GList *list;
guint items_changed;
items_changed = 0;
list = g_list_first(tapinfo->graph_analysis->list);
while (list)
{
gai = (seq_analysis_item_t *)list->data;
if (gai->conv_num == call_num) {
gai->conv_num = new_call_num;
items_changed++;
}
list = g_list_next(list);
}
return items_changed;
}
static void insert_to_graph_t38(voip_calls_tapinfo_t *tapinfo _U_, packet_info *pinfo, const gchar *frame_label, const gchar *comment, guint16 call_num, address *src_addr, address *dst_addr, guint16 line_style, guint32 frame_num)
{
seq_analysis_item_t *gai, *new_gai;
GList *list;
guint item_num;
gboolean inserted;
gchar time_str[COL_MAX_LEN];
new_gai = (seq_analysis_item_t *)g_malloc(sizeof(seq_analysis_item_t));
new_gai->fd = packet_list_get_row_data(frame_num);
COPY_ADDRESS(&(new_gai->src_addr),src_addr);
COPY_ADDRESS(&(new_gai->dst_addr),dst_addr);
new_gai->port_src=pinfo->srcport;
new_gai->port_dst=pinfo->destport;
if (frame_label != NULL)
new_gai->frame_label = g_strdup(frame_label);
else
new_gai->frame_label = g_strdup("");
if (comment != NULL)
new_gai->comment = g_strdup(comment);
else
new_gai->comment = g_strdup("");
new_gai->conv_num=call_num;
new_gai->line_style=line_style;
set_fd_time(cfile.epan, new_gai->fd, time_str);
new_gai->time_str = g_strdup(time_str);
new_gai->display=FALSE;
item_num = 0;
inserted = FALSE;
list = g_list_first(tapinfo->graph_analysis->list);
while (list)
{
gai = (seq_analysis_item_t *)list->data;
if (gai->fd->num > frame_num) {
the_tapinfo_struct.graph_analysis->list = g_list_insert(the_tapinfo_struct.graph_analysis->list, new_gai, item_num);
g_hash_table_insert(tapinfo->graph_analysis->ht, &new_gai->fd->num, new_gai);
inserted = TRUE;
break;
}
list = g_list_next(list);
item_num++;
}
if (!inserted) {
tapinfo->graph_analysis->list = g_list_prepend(tapinfo->graph_analysis->list, new_gai);
g_hash_table_insert(tapinfo->graph_analysis->ht, &new_gai->fd->num, new_gai);
}
}
static int
rtp_event_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *rtp_event_info)
{
const struct _rtp_event_info *pi = (const struct _rtp_event_info *)rtp_event_info;
if (pi->info_setup_frame_num == 0) {
return 0;
}
rtp_evt_frame_num = pinfo->fd->num;
rtp_evt = pi->info_rtp_evt;
rtp_evt_end = pi->info_end;
return 0;
}
void
rtp_event_init_tap(void)
{
GString *error_string;
if(have_rtp_event_tap_listener==FALSE)
{
error_string = register_tap_listener("rtpevent", &(the_tapinfo_rtp_struct.rtp_event_dummy),
NULL,
0,
NULL,
rtp_event_packet,
NULL
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_rtp_event_tap_listener=TRUE;
}
}
void
remove_tap_listener_rtp_event(void)
{
remove_tap_listener(&(the_tapinfo_rtp_struct.rtp_event_dummy));
have_rtp_event_tap_listener=FALSE;
}
static void voip_rtp_reset(void *ptr _U_)
{
voip_rtp_tapinfo_t *tapinfo = &the_tapinfo_rtp_struct;
GList *list;
list = g_list_first(tapinfo->list);
while (list)
{
g_free(list->data);
list = g_list_next(list);
}
g_list_free(tapinfo->list);
tapinfo->list = NULL;
tapinfo->nstreams = 0;
return;
}
static int
RTP_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, void const *RTPinfo)
{
voip_rtp_tapinfo_t *tapinfo = &the_tapinfo_rtp_struct;
voip_rtp_stream_info_t *tmp_listinfo;
voip_rtp_stream_info_t *strinfo = NULL;
GList *list;
struct _rtp_conversation_info *p_conv_data = NULL;
const struct _rtp_info *pi = (const struct _rtp_info *)RTPinfo;
if (pi->info_setup_frame_num == 0) {
return 0;
}
#ifdef HAVE_LIBPORTAUDIO
add_rtp_packet(pi, pinfo);
#endif
list = g_list_first(tapinfo->list);
while (list)
{
tmp_listinfo=(voip_rtp_stream_info_t *)list->data;
if ( (tmp_listinfo->setup_frame_number == pi->info_setup_frame_num)
&& (tmp_listinfo->ssrc == pi->info_sync_src) && (tmp_listinfo->end_stream == FALSE)) {
if ( tmp_listinfo->pt != pi->info_payload_type ) {
tmp_listinfo->end_stream = TRUE;
} else {
strinfo = (voip_rtp_stream_info_t*)(list->data);
break;
}
}
list = g_list_next(list);
}
if ((rtp_evt_frame_num == pinfo->fd->num) && !strinfo && (rtp_evt_end == TRUE)) {
return 0;
}
if (strinfo==NULL) {
strinfo = (voip_rtp_stream_info_t *)g_malloc(sizeof(voip_rtp_stream_info_t));
COPY_ADDRESS(&(strinfo->src_addr), &(pinfo->src));
strinfo->src_port = pinfo->srcport;
COPY_ADDRESS(&(strinfo->dest_addr), &(pinfo->dst));
strinfo->dest_port = pinfo->destport;
strinfo->ssrc = pi->info_sync_src;
strinfo->end_stream = FALSE;
strinfo->pt = pi->info_payload_type;
strinfo->pt_str = NULL;
strinfo->is_srtp = pi->info_is_srtp;
if ( (strinfo->pt >= PT_UNDF_96) && (strinfo->pt <= PT_UNDF_127) ) {
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_get_id_by_filter_name("rtp"), 0);
if (p_conv_data && p_conv_data->rtp_dyn_payload) {
const gchar *encoding_name = rtp_dyn_payload_get_name(p_conv_data->rtp_dyn_payload, strinfo->pt);
if (encoding_name) {
strinfo->pt_str = g_strdup(encoding_name);
}
}
}
if (!strinfo->pt_str) strinfo->pt_str = g_strdup(val_to_str_ext(strinfo->pt, &rtp_payload_type_short_vals_ext, "%u"));
strinfo->npackets = 0;
strinfo->start_fd = pinfo->fd;
strinfo->start_rel_ts = pinfo->rel_ts;
strinfo->setup_frame_number = pi->info_setup_frame_num;
strinfo->rtp_event = -1;
tapinfo->list = g_list_prepend(tapinfo->list, strinfo);
}
strinfo->npackets++;
strinfo->stop_fd = pinfo->fd;
strinfo->stop_rel_ts = pinfo->rel_ts;
if (rtp_evt_frame_num == pinfo->fd->num) {
strinfo->rtp_event = rtp_evt;
if (rtp_evt_end == TRUE) {
strinfo->end_stream = TRUE;
}
}
the_tapinfo_struct.redraw = TRUE;
return 1;
}
static void RTP_packet_draw(void *prs _U_)
{
voip_rtp_tapinfo_t *rtp_tapinfo = &the_tapinfo_rtp_struct;
GList *rtp_streams_list;
voip_rtp_stream_info_t *rtp_listinfo;
seq_analysis_item_t *gai;
seq_analysis_item_t *new_gai;
guint16 conv_num;
guint32 duration;
gchar time_str[COL_MAX_LEN];
rtp_streams_list = g_list_first(rtp_tapinfo->list);
while (rtp_streams_list)
{
rtp_listinfo = (voip_rtp_stream_info_t *)rtp_streams_list->data;
gai = (seq_analysis_item_t *)g_hash_table_lookup(the_tapinfo_struct.graph_analysis->ht, &rtp_listinfo->setup_frame_number);
if(gai != NULL) {
conv_num = gai->conv_num;
gai = (seq_analysis_item_t *)g_hash_table_lookup(the_tapinfo_struct.graph_analysis->ht, &rtp_listinfo->start_fd->num);
if(gai != NULL) {
duration = (guint32)(nstime_to_msec(&rtp_listinfo->stop_rel_ts) - nstime_to_msec(&rtp_listinfo->start_rel_ts));
g_free(gai->comment);
gai->comment = g_strdup_printf("%s Num packets:%u Duration:%u.%03us SSRC:0x%X",
(rtp_listinfo->is_srtp)?"SRTP":"RTP", rtp_listinfo->npackets,
duration/1000,(duration%1000), rtp_listinfo->ssrc);
}else {
new_gai = (seq_analysis_item_t *)g_malloc(sizeof(seq_analysis_item_t));
new_gai->fd = rtp_listinfo->start_fd;
COPY_ADDRESS(&(new_gai->src_addr),&(rtp_listinfo->src_addr));
COPY_ADDRESS(&(new_gai->dst_addr),&(rtp_listinfo->dest_addr));
new_gai->port_src = rtp_listinfo->src_port;
new_gai->port_dst = rtp_listinfo->dest_port;
duration = (guint32)(nstime_to_msec(&rtp_listinfo->stop_rel_ts) - nstime_to_msec(&rtp_listinfo->start_rel_ts));
new_gai->frame_label = g_strdup_printf("%s (%s) %s",
(rtp_listinfo->is_srtp)?"SRTP":"RTP",
rtp_listinfo->pt_str,
(rtp_listinfo->rtp_event == -1)?
"":val_to_str_ext_const(rtp_listinfo->rtp_event, &rtp_event_type_values_ext, "Unknown RTP Event"));
new_gai->comment = g_strdup_printf("%s Num packets:%u Duration:%u.%03us SSRC:0x%X",
(rtp_listinfo->is_srtp)?"SRTP":"RTP", rtp_listinfo->npackets,
duration/1000,(duration%1000), rtp_listinfo->ssrc);
new_gai->conv_num = conv_num;
set_fd_time(cfile.epan, new_gai->fd, time_str);
new_gai->time_str = g_strdup(time_str);
new_gai->display=FALSE;
new_gai->line_style = 2;
the_tapinfo_struct.graph_analysis->list = g_list_prepend(the_tapinfo_struct.graph_analysis->list, new_gai);
g_hash_table_insert(the_tapinfo_struct.graph_analysis->ht, &rtp_listinfo->start_fd, new_gai);
}
}
rtp_streams_list = g_list_next(rtp_streams_list);
}
}
void
rtp_init_tap(void)
{
GString *error_string;
if(have_RTP_tap_listener==FALSE)
{
error_string = register_tap_listener("rtp", &(the_tapinfo_rtp_struct.rtp_dummy), NULL,
0,
voip_rtp_reset,
RTP_packet,
RTP_packet_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_RTP_tap_listener=TRUE;
}
}
void
remove_tap_listener_rtp(void)
{
remove_tap_listener(&(the_tapinfo_rtp_struct.rtp_dummy));
have_RTP_tap_listener=FALSE;
}
static int
T38_packet( void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *T38info)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *callsinfo = NULL;
voip_calls_info_t *tmp_listinfo;
GList *voip_calls_graph_list;
GList *list;
gchar *frame_label = NULL;
gchar *comment = NULL;
seq_analysis_item_t *tmp_gai, *gai = NULL;
guint16 line_style = 2;
double duration;
int conv_num = -1;
const t38_packet_info *pi = (const t38_packet_info *)T38info;
if (pi->setup_frame_number != 0) {
voip_calls_graph_list = g_list_first(tapinfo->graph_analysis->list);
while (voip_calls_graph_list)
{
tmp_gai = (seq_analysis_item_t *)voip_calls_graph_list->data;
if (pi->setup_frame_number == tmp_gai->fd->num) {
gai = tmp_gai;
break;
}
voip_calls_graph_list = g_list_next(voip_calls_graph_list);
}
if (gai) conv_num = (int) gai->conv_num;
}
if ( (pi->setup_frame_number == 0) || (gai == NULL) ) {
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == MEDIA_T38) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
list = g_list_next (list);
}
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_UNKNOWN;
callsinfo->from_identity=g_strdup("T38 Media only");
callsinfo->to_identity=g_strdup("T38 Media only");
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd = pinfo->fd;
callsinfo->start_rel_ts = pinfo->rel_ts;
callsinfo->protocol=MEDIA_T38;
callsinfo->prot_info=NULL;
callsinfo->free_prot_info = NULL;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
conv_num = (int) callsinfo->call_num;
}
if (conv_num == -1) {
return 0;
}
if (pi->type_msg == 0) {
frame_label = g_strdup(val_to_str(pi->t30ind_value, t38_T30_indicator_vals, "Ukn (0x%02X)") );
comment = g_strdup_printf("t38:t30 Ind:%s",val_to_str(pi->t30ind_value, t38_T30_indicator_vals, "Ukn (0x%02X)") );
line_style = 1;
} else if (pi->type_msg == 1) {
switch(pi->Data_Field_field_type_value) {
case 0:
break;
case 2:
case 4:
frame_label = g_strdup_printf("%s %s",
val_to_str_ext(pi->t30_Facsimile_Control & 0x7F,
&t30_facsimile_control_field_vals_short_ext,
"Ukn (0x%02X)"),
pi->desc);
comment = g_strdup_printf("t38:%s:HDLC:%s",
val_to_str(pi->data_value,
t38_T30_data_vals,
"Ukn (0x%02X)"),
val_to_str_ext(pi->t30_Facsimile_Control & 0x7F,
&t30_facsimile_control_field_vals_ext,
"Ukn (0x%02X)"));
break;
case 3:
case 5:
frame_label = g_strdup(pi->Data_Field_field_type_value == 3 ? "fcs-BAD" : "fcs-BAD-sig-end");
comment = g_strdup_printf("WARNING: received t38:%s:HDLC:%s",
val_to_str(pi->data_value,
t38_T30_data_vals,
"Ukn (0x%02X)"),
pi->Data_Field_field_type_value == 3 ? "fcs-BAD" : "fcs-BAD-sig-end");
break;
case 7:
duration = nstime_to_sec(&pinfo->rel_ts) - pi->time_first_t4_data;
frame_label = g_strdup_printf("t4-non-ecm-data:%s",
val_to_str(pi->data_value,
t38_T30_data_vals,
"Ukn (0x%02X)") );
comment = g_strdup_printf("t38:t4-non-ecm-data:%s Duration: %.2fs %s",
val_to_str(pi->data_value,
t38_T30_data_vals,
"Ukn (0x%02X)"),
duration, pi->desc_comment );
insert_to_graph_t38(tapinfo, pinfo, frame_label, comment,
(guint16)conv_num, &(pinfo->src), &(pinfo->dst),
line_style, pi->frame_num_first_t4_data);
break;
}
}
if (frame_label && !(pi->Data_Field_field_type_value == 7 && pi->type_msg == 1)) {
add_to_graph(tapinfo, pinfo, frame_label, comment, (guint16)conv_num, &(pinfo->src), &(pinfo->dst), line_style);
}
g_free(comment);
g_free(frame_label);
tapinfo->redraw = TRUE;
return 1;
}
void
t38_init_tap(void)
{
GString *error_string;
if(have_T38_tap_listener==FALSE)
{
error_string = register_tap_listener("t38", &(the_tapinfo_struct.t38_dummy), NULL,
0,
voip_calls_dlg_reset,
T38_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_T38_tap_listener=TRUE;
}
}
void
remove_tap_listener_t38(void)
{
remove_tap_listener(&(the_tapinfo_struct.t38_dummy));
have_T38_tap_listener=FALSE;
}
static void free_sip_info(gpointer p) {
sip_calls_info_t *si = (sip_calls_info_t *)p;
g_free(si->call_identifier);
g_free(si);
}
static int
SIPcalls_packet( void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *SIPinfo)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *callsinfo = NULL;
sip_calls_info_t *tmp_sipinfo = NULL;
address tmp_src, tmp_dst;
gchar *frame_label = NULL;
gchar *comment = NULL;
gchar *key=NULL;
const sip_info_value_t *pi = (const sip_info_value_t *)SIPinfo;
if (pi->tap_call_id ==NULL) {
return 0;
}
key=pi->tap_call_id;
if(NULL==tapinfo->callsinfo_hashtable[SIP_HASH]) {
tapinfo->callsinfo_hashtable[SIP_HASH]=g_hash_table_new_full(g_str_hash,
g_str_equal,
NULL,
NULL);
}
callsinfo = (voip_calls_info_t *)g_hash_table_lookup(tapinfo->callsinfo_hashtable[SIP_HASH], key);
if ((callsinfo==NULL) &&(pi->request_method!=NULL)) {
if (strcmp(pi->request_method,"INVITE")==0) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_CALL_SETUP;
callsinfo->from_identity=g_strdup(pi->tap_from_addr);
callsinfo->to_identity=g_strdup(pi->tap_to_addr);
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_SIP;
callsinfo->prot_info=g_malloc(sizeof(sip_calls_info_t));
callsinfo->free_prot_info = free_sip_info;
tmp_sipinfo = (sip_calls_info_t *)callsinfo->prot_info;
tmp_sipinfo->call_identifier = g_strdup(pi->tap_call_id);
tmp_sipinfo->sip_state = SIP_INVITE_SENT;
tmp_sipinfo->invite_cseq = pi->tap_cseq_number;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
g_hash_table_insert(tapinfo->callsinfo_hashtable[SIP_HASH],
tmp_sipinfo->call_identifier, callsinfo);
}
}
if (callsinfo!=NULL) {
tmp_sipinfo = (sip_calls_info_t *)callsinfo->prot_info;
COPY_ADDRESS(&(tmp_src), &(pinfo->src));
COPY_ADDRESS(&(tmp_dst), &(pinfo->dst));
if (pi->request_method == NULL) {
frame_label = g_strdup_printf("%u %s", pi->response_code, pi->reason_phrase );
comment = g_strdup("SIP Status");
if ((tmp_sipinfo && pi->tap_cseq_number == tmp_sipinfo->invite_cseq)&&(ADDRESSES_EQUAL(&tmp_dst,&(callsinfo->initial_speaker)))) {
if ((pi->response_code > 199) && (pi->response_code<300) && (tmp_sipinfo->sip_state == SIP_INVITE_SENT)) {
tmp_sipinfo->sip_state = SIP_200_REC;
}
else if ((pi->response_code>299)&&(tmp_sipinfo->sip_state == SIP_INVITE_SENT)) {
callsinfo->call_state = VOIP_REJECTED;
tapinfo->rejected_calls++;
}
}
}
else {
frame_label = g_strdup(pi->request_method);
if ((strcmp(pi->request_method,"INVITE")==0)&&(ADDRESSES_EQUAL(&tmp_src,&(callsinfo->initial_speaker)))) {
tmp_sipinfo->invite_cseq = pi->tap_cseq_number;
callsinfo->call_state = VOIP_CALL_SETUP;
comment = g_strdup_printf("SIP From: %s To:%s", callsinfo->from_identity, callsinfo->to_identity);
}
else if ((strcmp(pi->request_method,"ACK")==0)&&(pi->tap_cseq_number == tmp_sipinfo->invite_cseq)
&&(ADDRESSES_EQUAL(&tmp_src,&(callsinfo->initial_speaker)))&&(tmp_sipinfo->sip_state==SIP_200_REC)
&&(callsinfo->call_state == VOIP_CALL_SETUP)) {
callsinfo->call_state = VOIP_IN_CALL;
comment = g_strdup("SIP Request");
}
else if (strcmp(pi->request_method,"BYE")==0) {
callsinfo->call_state = VOIP_COMPLETED;
tapinfo->completed_calls++;
comment = g_strdup("SIP Request");
}
else if ((strcmp(pi->request_method,"CANCEL")==0)&&(pi->tap_cseq_number == tmp_sipinfo->invite_cseq)
&&(ADDRESSES_EQUAL(&tmp_src,&(callsinfo->initial_speaker)))&&(callsinfo->call_state==VOIP_CALL_SETUP)) {
callsinfo->call_state = VOIP_CANCELLED;
tmp_sipinfo->sip_state = SIP_CANCEL_SENT;
comment = g_strdup("SIP Request");
} else {
comment = g_strdup("SIP Request");
}
}
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
g_free(frame_label);
g_free((void *)tmp_src.data);
g_free((void *)tmp_dst.data);
if ( (sdp_summary != NULL) && (sdp_frame_num == pinfo->fd->num) ) {
append_to_frame_graph(tapinfo, pinfo->fd->num, sdp_summary, NULL);
g_free(sdp_summary);
sdp_summary = NULL;
}
}
tapinfo->redraw = TRUE;
return 1;
}
voip_calls_tapinfo_t* voip_calls_get_info(void)
{
return &the_tapinfo_struct;
}
void
sip_calls_init_tap(void)
{
GString *error_string;
if(have_SIP_tap_listener==FALSE)
{
error_string = register_tap_listener("sip", &(the_tapinfo_struct.sip_dummy), NULL,
0,
voip_calls_dlg_reset,
SIPcalls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_SIP_tap_listener=TRUE;
}
}
void
remove_tap_listener_sip_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.sip_dummy));
have_SIP_tap_listener=FALSE;
}
static int
isup_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *isup_info _U_)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
isup_calls_info_t *tmp_isupinfo;
gboolean found = FALSE;
gboolean forward = FALSE;
gboolean right_pair;
GList *list;
gchar *frame_label = NULL;
gchar *comment = NULL;
const isup_tap_rec_t *pi = (const isup_tap_rec_t *)isup_info;
if (mtp3_frame_num != pinfo->fd->num) return 0;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
right_pair = TRUE;
tmp_listinfo=(voip_calls_info_t *)list->data;
if ((tmp_listinfo->protocol == VOIP_ISUP)&&(tmp_listinfo->call_active_state==VOIP_ACTIVE)) {
tmp_isupinfo = (isup_calls_info_t *)tmp_listinfo->prot_info;
if ((tmp_isupinfo->cic == pinfo->circuit_id)&&(tmp_isupinfo->ni == mtp3_ni)) {
if ((tmp_isupinfo->opc == mtp3_opc)&&(tmp_isupinfo->dpc == mtp3_dpc)) {
forward = TRUE;
} else if ((tmp_isupinfo->dpc == mtp3_opc)&&(tmp_isupinfo->opc == mtp3_dpc)) {
forward = FALSE;
} else {
right_pair = FALSE;
}
if (right_pair) {
if (tmp_listinfo->call_state == VOIP_CALL_SETUP) {
found = TRUE;
} else if (pi->message_type != 1) {
found = TRUE;
} else {
tmp_listinfo->call_active_state=VOIP_INACTIVE;
}
}
if (found) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
}
list = g_list_next (list);
}
if ((callsinfo==NULL) &&(pi->message_type==1)) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_UNKNOWN;
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_ISUP;
if (pi->calling_number!=NULL) {
callsinfo->from_identity=g_strdup(pi->calling_number);
}
if (pi->called_number!=NULL) {
callsinfo->to_identity=g_strdup(pi->called_number);
}
callsinfo->prot_info=g_malloc(sizeof(isup_calls_info_t));
callsinfo->free_prot_info = g_free;
tmp_isupinfo=(isup_calls_info_t *)callsinfo->prot_info;
tmp_isupinfo->opc = mtp3_opc;
tmp_isupinfo->dpc = mtp3_dpc;
tmp_isupinfo->ni = mtp3_ni;
tmp_isupinfo->cic = pinfo->circuit_id;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
if (callsinfo!=NULL) {
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
frame_label = g_strdup(val_to_str_ext_const(pi->message_type, &isup_message_type_value_acro_ext, "Unknown"));
if (callsinfo->npackets == 1) {
if ((pi->calling_number!=NULL)&&(pi->called_number !=NULL)) {
comment = g_strdup_printf("Call from %s to %s",
pi->calling_number, pi->called_number);
}
} else if (callsinfo->npackets == 2) {
if (forward) {
comment = g_strdup_printf("%i-%i -> %i-%i. Cic:%i",
mtp3_ni, mtp3_opc,
mtp3_ni, mtp3_dpc, pinfo->circuit_id);
} else {
comment = g_strdup_printf("%i-%i -> %i-%i. Cic:%i",
mtp3_ni, mtp3_dpc,
mtp3_ni, mtp3_opc, pinfo->circuit_id);
}
}
switch(pi->message_type) {
case 1:
callsinfo->call_state=VOIP_CALL_SETUP;
break;
case 7:
case 9:
callsinfo->call_state=VOIP_IN_CALL;
break;
case 12:
if (callsinfo->call_state==VOIP_CALL_SETUP) {
if (forward) {
callsinfo->call_state=VOIP_CANCELLED;
}
else {
callsinfo->call_state=VOIP_REJECTED;
tapinfo->rejected_calls++;
}
}
else if (callsinfo->call_state == VOIP_IN_CALL) {
callsinfo->call_state = VOIP_COMPLETED;
tapinfo->completed_calls++;
}
comment = g_strdup_printf("Cause %i - %s",
pi->cause_value,
val_to_str_ext_const(pi->cause_value, &q931_cause_code_vals_ext, "(Unknown)"));
break;
}
++(tapinfo->npackets);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
g_free(frame_label);
}
tapinfo->redraw = TRUE;
return 1;
}
void
isup_calls_init_tap(void)
{
GString *error_string;
if(have_isup_tap_listener==FALSE)
{
error_string = register_tap_listener("isup", &(the_tapinfo_struct.isup_dummy),
NULL,
0,
voip_calls_dlg_reset,
isup_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_isup_tap_listener=TRUE;
}
}
void
remove_tap_listener_isup_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.isup_dummy));
have_isup_tap_listener=FALSE;
}
static int
mtp3_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *mtp3_info _U_)
{
const mtp3_tap_rec_t *pi = (const mtp3_tap_rec_t *)mtp3_info;
mtp3_opc = pi->addr_opc.pc;
mtp3_dpc = pi->addr_dpc.pc;
mtp3_ni = pi->addr_opc.ni;
mtp3_frame_num = pinfo->fd->num;
return 0;
}
void
mtp3_calls_init_tap(void)
{
GString *error_string;
if(have_mtp3_tap_listener==FALSE)
{
error_string = register_tap_listener("mtp3", &(the_tapinfo_struct.mtp3_dummy),
NULL,
0,
voip_calls_dlg_reset,
mtp3_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_mtp3_tap_listener=TRUE;
}
if(have_m3ua_tap_listener==FALSE)
{
error_string = register_tap_listener("m3ua", &(the_tapinfo_struct.mtp3_dummy),
NULL,
0,
voip_calls_dlg_reset,
mtp3_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_m3ua_tap_listener=TRUE;
}
}
void
remove_tap_listener_mtp3_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.mtp3_dummy));
remove_tap_listener(&(the_tapinfo_struct.m3ua_dummy));
have_mtp3_tap_listener=FALSE;
have_m3ua_tap_listener=FALSE;
}
static int
q931_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *q931_info)
{
GList *list,*list2;
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
h323_calls_info_t *tmp_h323info,*tmp2_h323info;
actrace_isdn_calls_info_t *tmp_actrace_isdn_info;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
h245_address_t *h245_add = NULL;
gchar *comment;
const q931_packet_info *pi = (const q931_packet_info *)q931_info;
g_free(q931_calling_number);
g_free(q931_called_number);
if (pi->calling_number!=NULL)
q931_calling_number = g_strdup(pi->calling_number);
else
q931_calling_number = g_strdup("");
if (pi->called_number!=NULL)
q931_called_number = g_strdup(pi->called_number);
else
q931_called_number = g_strdup("");
q931_cause_value = pi->cause_value;
q931_frame_num = pinfo->fd->num;
q931_crv = pi->crv;
if (h225_frame_num == q931_frame_num) {
tmp_h323info = NULL;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if ( (tmp_listinfo->protocol == VOIP_H323) && (tmp_listinfo->call_num == h225_call_num) ) {
tmp_h323info = (h323_calls_info_t *)tmp_listinfo->prot_info;
callsinfo = (voip_calls_info_t*)(list->data);
if (tmp_h323info->q931_crv == -1) {
tmp_h323info->q931_crv = q931_crv;
} else if (tmp_h323info->q931_crv != q931_crv) {
tmp_h323info->q931_crv2 = q931_crv;
}
break;
}
list = g_list_next (list);
}
if (callsinfo != NULL) {
comment = NULL;
if (h225_cstype == H225_SETUP) {
if (q931_calling_number != NULL) {
g_free(callsinfo->from_identity);
callsinfo->from_identity=g_strdup(q931_calling_number);
}
if (q931_called_number != NULL) {
g_free(callsinfo->to_identity);
callsinfo->to_identity=g_strdup(q931_called_number);
}
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_H323) {
tmp2_h323info = (h323_calls_info_t *)tmp_listinfo->prot_info;
if ( (strcmp(callsinfo->to_identity, tmp_listinfo->to_identity)==0)
&& (memcmp(&tmp2_h323info->guid, &guid_allzero, GUID_LEN) == 0) ) {
callsinfo->npackets += change_call_num_graph(tapinfo, tmp_listinfo->call_num, callsinfo->call_num);
g_free(tmp_listinfo->from_identity);
g_free(tmp_listinfo->to_identity);
DUMP_PTR2(tmp2_h323info->guid);
g_free(tmp2_h323info->guid);
list2 = g_list_first(tmp2_h323info->h245_list);
while (list2)
{
h245_add=(h245_address_t *)list2->data;
g_free((void *)h245_add->h245_address.data);
g_free(list2->data);
list2 = g_list_next(list2);
}
g_list_free(tmp_h323info->h245_list);
tmp_h323info->h245_list = NULL;
g_free(tmp_listinfo->prot_info);
tapinfo->callsinfo_list = g_list_remove(tapinfo->callsinfo_list, tmp_listinfo);
break;
}
}
list = g_list_next (list);
}
comment = g_strdup_printf("H225 From: %s To:%s TunnH245:%s FS:%s", callsinfo->from_identity, callsinfo->to_identity, (tmp_h323info->is_h245Tunneling==TRUE?"on":"off"),
(h225_is_faststart==TRUE?"on":"off"));
} else if (h225_cstype == H225_RELEASE_COMPLET) {
if (q931_cause_value != 0xFF) {
comment = g_strdup_printf("H225 Q931 Rel Cause (%i):%s", q931_cause_value,
val_to_str_ext_const(q931_cause_value, &q931_cause_code_vals_ext, "<unknown>"));
} else {
comment = g_strdup("H225 No Q931 Rel Cause");
}
}
if (comment != NULL) {
change_frame_graph(tapinfo, h225_frame_num, NULL, comment);
g_free(comment);
}
}
h225_frame_num = 0;
} else if (h245_labels.frame_num == q931_frame_num) {
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_H323) {
tmp_h323info = (h323_calls_info_t *)tmp_listinfo->prot_info;
if ( ((tmp_h323info->q931_crv == q931_crv) || (tmp_h323info->q931_crv2 == q931_crv)) && (q931_crv!=-1)) {
if (!append_to_frame_graph(tapinfo, q931_frame_num, NULL, NULL)) {
add_to_graph(tapinfo, pinfo, NULL, NULL, tmp_listinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
++(tmp_listinfo->npackets);
++(tapinfo->npackets);
}
h245_add_to_graph(pinfo->fd->num);
break;
}
}
list = g_list_next (list);
}
} else {
address pstn_add;
comment = NULL;
callsinfo = NULL;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if ( tmp_listinfo->protocol == VOIP_AC_ISDN ) {
tmp_actrace_isdn_info = (actrace_isdn_calls_info_t *)tmp_listinfo->prot_info;
if ( (tmp_actrace_isdn_info->crv == q931_crv) && (tmp_actrace_isdn_info->trunk == actrace_trunk) ) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
SET_ADDRESS(&pstn_add, AT_STRINGZ, 5, g_strdup("PSTN"));
if (!callsinfo) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_CALL_SETUP;
callsinfo->from_identity=g_strdup(q931_calling_number);
callsinfo->to_identity=g_strdup(q931_called_number);
COPY_ADDRESS(&(callsinfo->initial_speaker),actrace_direction?&pstn_add:&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_AC_ISDN;
callsinfo->prot_info=g_malloc(sizeof(actrace_isdn_calls_info_t));
callsinfo->free_prot_info = g_free;
tmp_actrace_isdn_info=(actrace_isdn_calls_info_t *)callsinfo->prot_info;
tmp_actrace_isdn_info->crv=q931_crv;
tmp_actrace_isdn_info->trunk=actrace_trunk;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
switch(pi->message_type) {
case Q931_SETUP:
comment = g_strdup_printf("AC_ISDN trunk:%u Calling: %s Called:%s", actrace_trunk, q931_calling_number, q931_called_number);
callsinfo->call_state=VOIP_CALL_SETUP;
break;
case Q931_CONNECT:
callsinfo->call_state=VOIP_IN_CALL;
break;
case Q931_RELEASE_COMPLETE:
case Q931_RELEASE:
case Q931_DISCONNECT:
if (callsinfo->call_state==VOIP_CALL_SETUP) {
if (ADDRESSES_EQUAL(&(callsinfo->initial_speaker), actrace_direction?&pstn_add:&(pinfo->src) )) {
callsinfo->call_state=VOIP_CANCELLED;
}
else {
callsinfo->call_state=VOIP_REJECTED;
tapinfo->rejected_calls++;
}
} else if ( (callsinfo->call_state!=VOIP_CANCELLED) && (callsinfo->call_state!=VOIP_REJECTED) ) {
callsinfo->call_state=VOIP_COMPLETED;
tapinfo->completed_calls++;
}
if (q931_cause_value != 0xFF) {
comment = g_strdup_printf("AC_ISDN trunk:%u Q931 Rel Cause (%i):%s", actrace_trunk, q931_cause_value,
val_to_str_ext_const(q931_cause_value, &q931_cause_code_vals_ext, "<unknown>"));
} else {
comment = g_strdup("AC_ISDN No Q931 Rel Cause");
}
break;
}
if (!comment)
comment = g_strdup_printf("AC_ISDN trunk:%u", actrace_trunk );
add_to_graph(tapinfo, pinfo, val_to_str(pi->message_type, q931_message_type_vals, "<unknown>") , comment, callsinfo->call_num,
actrace_direction?&pstn_add:&(pinfo->src),
actrace_direction?&(pinfo->src):&pstn_add,
1 );
g_free(comment);
g_free((char *)pstn_add.data);
}
tapinfo->redraw = TRUE;
return 1;
}
void
q931_calls_init_tap(void)
{
GString *error_string;
if(have_q931_tap_listener==FALSE)
{
error_string = register_tap_listener("q931", &(the_tapinfo_struct.q931_dummy),
NULL,
0,
voip_calls_dlg_reset,
q931_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_q931_tap_listener=TRUE;
}
}
void
remove_tap_listener_q931_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.q931_dummy));
have_q931_tap_listener=FALSE;
}
static void add_h245_Address(h323_calls_info_t *h323info, h245_address_t *h245_address)
{
h323info->h245_list = g_list_prepend(h323info->h245_list, h245_address);
}
static void free_h225_info(gpointer p) {
h323_calls_info_t *tmp_h323info = (h323_calls_info_t *)p;
DUMP_PTR2(tmp_h323info->guid);
g_free(tmp_h323info->guid);
if (tmp_h323info->h245_list) {
GList *list2 = g_list_first(tmp_h323info->h245_list);
while (list2)
{
h245_address_t *h245_add=(h245_address_t *)list2->data;
g_free((void *)h245_add->h245_address.data);
g_free(list2->data);
list2 = g_list_next(list2);
}
g_list_free(tmp_h323info->h245_list);
}
g_free(p);
}
static int
H225calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *H225info)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
h323_calls_info_t *tmp_h323info = NULL;
gchar *frame_label;
gchar *comment;
GList *list;
h245_address_t *h245_add = NULL;
const h225_packet_info *pi = (const h225_packet_info *)H225info;
if ((memcmp(&pi->guid, &guid_allzero, GUID_LEN) == 0))
if ( ((pi->msg_type == H225_RAS) && ((pi->msg_tag < 18) || (pi->msg_tag > 20))) || (pi->msg_type != H225_RAS) )
return 0;
if ( (pi->msg_type == H225_RAS) && ((pi->msg_tag == 19) || (pi->msg_tag == 20))) {
if (!pi->request_available) return 0;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
g_assert(tmp_listinfo != NULL);
if (tmp_listinfo->protocol == VOIP_H323) {
tmp_h323info = (h323_calls_info_t *)tmp_listinfo->prot_info;
if (tmp_h323info->requestSeqNum == pi->requestSeqNum) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
} else {
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_H323) {
tmp_h323info = (h323_calls_info_t *)tmp_listinfo->prot_info;
g_assert(tmp_h323info != NULL);
if ( (memcmp(tmp_h323info->guid, &guid_allzero, GUID_LEN) != 0) && (memcmp(tmp_h323info->guid, &pi->guid,GUID_LEN)==0) ) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
}
h225_cstype = pi->cs_type;
h225_is_faststart = pi->is_faststart;
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_UNKNOWN;
callsinfo->from_identity=g_strdup("");
callsinfo->to_identity=g_strdup("");
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_H323;
callsinfo->prot_info=g_malloc(sizeof(h323_calls_info_t));
callsinfo->free_prot_info = free_h225_info;
tmp_h323info = (h323_calls_info_t *)callsinfo->prot_info;
g_assert(tmp_h323info != NULL);
tmp_h323info->guid = (e_guid_t *)g_memdup(&pi->guid, sizeof pi->guid);
DUMP_PTR1(tmp_h323info->guid);
tmp_h323info->h225SetupAddr.type = AT_NONE;
tmp_h323info->h225SetupAddr.len = 0;
tmp_h323info->h245_list = NULL;
tmp_h323info->is_faststart_Setup = FALSE;
tmp_h323info->is_faststart_Proc = FALSE;
tmp_h323info->is_h245Tunneling = FALSE;
tmp_h323info->is_h245 = FALSE;
tmp_h323info->q931_crv = -1;
tmp_h323info->q931_crv2 = -1;
tmp_h323info->requestSeqNum = 0;
callsinfo->call_num = tapinfo->ncalls++;
callsinfo->npackets = 0;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
h225_frame_num = pinfo->fd->num;
h225_call_num = callsinfo->call_num;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
g_assert(tmp_h323info != NULL);
if (pi->msg_type == H225_CS) {
if (pi->is_h245 == TRUE) {
h245_add = (h245_address_t *)g_malloc(sizeof (h245_address_t));
h245_add->h245_address.type=AT_IPv4;
h245_add->h245_address.len=4;
h245_add->h245_address.data = g_malloc(sizeof(pi->h245_address));
memcpy((void *)(h245_add->h245_address.data), &(pi->h245_address), 4);
h245_add->h245_port = pi->h245_port;
add_h245_Address(tmp_h323info, h245_add);
}
if (pi->cs_type != H225_RELEASE_COMPLET) tmp_h323info->is_h245Tunneling = pi->is_h245Tunneling;
frame_label = g_strdup(pi->frame_label);
switch(pi->cs_type) {
case H225_SETUP:
tmp_h323info->is_faststart_Setup = pi->is_faststart;
if (tmp_h323info->h225SetupAddr.type == AT_NONE)
COPY_ADDRESS(&(tmp_h323info->h225SetupAddr), &(pinfo->src));
callsinfo->call_state=VOIP_CALL_SETUP;
comment = g_strdup_printf("H225 TunnH245:%s FS:%s", (tmp_h323info->is_h245Tunneling==TRUE?"on":"off"),
(pi->is_faststart==TRUE?"on":"off"));
break;
case H225_CONNECT:
callsinfo->call_state=VOIP_IN_CALL;
if (pi->is_faststart == TRUE) tmp_h323info->is_faststart_Proc = TRUE;
comment = g_strdup_printf("H225 TunnH245:%s FS:%s", (tmp_h323info->is_h245Tunneling==TRUE?"on":"off"),
(pi->is_faststart==TRUE?"on":"off"));
break;
case H225_RELEASE_COMPLET:
if (callsinfo->call_state==VOIP_CALL_SETUP) {
if (ADDRESSES_EQUAL(&(tmp_h323info->h225SetupAddr),&(pinfo->src))) {
callsinfo->call_state=VOIP_CANCELLED;
}
else {
callsinfo->call_state=VOIP_REJECTED;
tapinfo->rejected_calls++;
}
} else {
callsinfo->call_state=VOIP_COMPLETED;
tapinfo->completed_calls++;
}
comment = g_strdup("H225 No Q931 Rel Cause");
break;
case H225_PROGRESS:
case H225_ALERTING:
case H225_CALL_PROCEDING:
if (pi->is_faststart == TRUE) tmp_h323info->is_faststart_Proc = TRUE;
comment = g_strdup_printf("H225 TunnH245:%s FS:%s", (tmp_h323info->is_h245Tunneling==TRUE?"on":"off"),
(pi->is_faststart==TRUE?"on":"off"));
break;
default:
comment = g_strdup_printf("H225 TunnH245:%s FS:%s", (tmp_h323info->is_h245Tunneling==TRUE?"on":"off"),
(pi->is_faststart==TRUE?"on":"off"));
}
}
else if (pi->msg_type == H225_RAS) {
switch(pi->msg_tag) {
case 18:
if (!pi->is_duplicate) {
g_free(callsinfo->to_identity);
callsinfo->to_identity=g_strdup(pi->dialedDigits);
tmp_h323info->requestSeqNum = pi->requestSeqNum;
}
case 19:
if (strlen(pi->dialedDigits))
comment = g_strdup_printf("H225 RAS dialedDigits: %s", pi->dialedDigits);
else
comment = g_strdup("H225 RAS");
break;
default:
comment = g_strdup("H225 RAS");
}
frame_label = g_strdup(val_to_str_const(pi->msg_tag, h225_RasMessage_vals, "<unknown>"));
} else {
frame_label = g_strdup("H225: Unknown");
comment = NULL;
}
if (!append_to_frame_graph(tapinfo, pinfo->fd->num, pi->frame_label, comment)) {
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
}
h245_add_to_graph(pinfo->fd->num);
g_free(frame_label);
g_free(comment);
tapinfo->redraw = TRUE;
return 1;
}
void
h225_calls_init_tap(void)
{
GString *error_string;
if(have_H225_tap_listener==FALSE)
{
error_string = register_tap_listener("h225", &(the_tapinfo_struct.h225_dummy), NULL,
0,
voip_calls_dlg_reset,
H225calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_H225_tap_listener=TRUE;
}
}
void
remove_tap_listener_h225_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.h225_dummy));
have_H225_tap_listener=FALSE;
}
void h245_add_to_graph(guint32 new_frame_num)
{
gint8 n;
if (new_frame_num != h245_labels.frame_num) return;
for (n=0; n<h245_labels.labels_count; n++) {
append_to_frame_graph(&the_tapinfo_struct, new_frame_num, h245_labels.labels[n].frame_label, h245_labels.labels[n].comment);
g_free(h245_labels.labels[n].frame_label);
h245_labels.labels[n].frame_label = NULL;
g_free(h245_labels.labels[n].comment);
h245_labels.labels[n].comment = NULL;
}
h245_labels.frame_num = 0;
h245_labels.labels_count = 0;
}
static void h245_free_labels(guint32 new_frame_num)
{
gint8 n;
if (new_frame_num == h245_labels.frame_num) return;
for (n=0; n<h245_labels.labels_count; n++) {
g_free(h245_labels.labels[n].frame_label);
h245_labels.labels[n].frame_label = NULL;
g_free(h245_labels.labels[n].comment);
h245_labels.labels[n].comment = NULL;
}
h245_labels.frame_num = 0;
h245_labels.labels_count = 0;
}
static void h245_add_label(guint32 new_frame_num, const gchar *frame_label, const gchar *comment)
{
h245_free_labels(new_frame_num);
h245_labels.frame_num = new_frame_num;
h245_labels.labels[h245_labels.labels_count].frame_label = g_strdup(frame_label);
h245_labels.labels[h245_labels.labels_count].comment = g_strdup(comment);
if (h245_labels.labels_count < (H245_MAX-1))
h245_labels.labels_count++;
}
static int
H245dgcalls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *H245info)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
h323_calls_info_t *tmp_h323info;
GList *list;
GList *list2;
h245_address_t *h245_add = NULL;
const h245_packet_info *pi = (const h245_packet_info *)H245info;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_H323) {
tmp_h323info = (h323_calls_info_t *)tmp_listinfo->prot_info;
list2 = g_list_first(tmp_h323info->h245_list);
while (list2)
{
h245_add=(h245_address_t *)list2->data;
if ( (ADDRESSES_EQUAL(&(h245_add->h245_address),&(pinfo->src)) && (h245_add->h245_port == pinfo->srcport))
|| (ADDRESSES_EQUAL(&(h245_add->h245_address),&(pinfo->dst)) && (h245_add->h245_port == pinfo->destport)) ) {
callsinfo = (voip_calls_info_t*)(list->data);
++(callsinfo->npackets);
++(tapinfo->npackets);
break;
}
list2 = g_list_next(list2);
}
if (callsinfo!=NULL) break;
}
list = g_list_next(list);
}
if (callsinfo!=NULL) {
++(callsinfo->npackets);
++(tapinfo->npackets);
if (!append_to_frame_graph(tapinfo, pinfo->fd->num, pi->frame_label, pi->comment)) {
add_to_graph(tapinfo, pinfo, pi->frame_label, pi->comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
}
} else {
h245_add_label(pinfo->fd->num, (gchar *) pi->frame_label, (gchar *) pi->comment);
}
tapinfo->redraw = TRUE;
return 1;
}
void
h245dg_calls_init_tap(void)
{
GString *error_string;
if(have_H245dg_tap_listener==FALSE)
{
error_string = register_tap_listener("h245dg", &(the_tapinfo_struct.h245dg_dummy), NULL,
0,
voip_calls_dlg_reset,
H245dgcalls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_H245dg_tap_listener=TRUE;
}
}
void
remove_tap_listener_h245dg_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.h245dg_dummy));
have_H245dg_tap_listener=FALSE;
}
static int
SDPcalls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *SDPinfo)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
const sdp_packet_info *pi = (const sdp_packet_info *)SDPinfo;
g_free(sdp_summary);
sdp_frame_num = pinfo->fd->num;
sdp_summary = g_strdup_printf("SDP (%s)", pi->summary_str);
append_to_frame_graph(tapinfo, pinfo->fd->num, sdp_summary, NULL);
tapinfo->redraw = TRUE;
return 1;
}
void
sdp_calls_init_tap(void)
{
GString *error_string;
if(have_sdp_tap_listener==FALSE)
{
error_string = register_tap_listener("sdp", &(the_tapinfo_struct.sdp_dummy), NULL,
0,
voip_calls_dlg_reset,
SDPcalls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_sdp_tap_listener=TRUE;
}
}
void
remove_tap_listener_sdp_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.sdp_dummy));
have_sdp_tap_listener=FALSE;
}
static gboolean isSignal(const gchar *signal_str_p, const gchar *signalStr)
{
gint i;
gchar **resultArray;
if (signalStr == NULL) return FALSE;
if ( (*signal_str_p == '\0') && (*signalStr == '\0') ) return TRUE;
resultArray = g_strsplit(signalStr, ",", 10);
for (i = 0; resultArray[i]; i++) {
g_strstrip(resultArray[i]);
if (strcmp(resultArray[i], signal_str_p) == 0) return TRUE;
}
g_strfreev(resultArray);
return FALSE;
}
static void mgcpCallerID(gchar *signalStr, gchar **callerId)
{
gchar **arrayStr;
if (signalStr == NULL) return;
arrayStr = g_strsplit(signalStr, "\"", 3);
if (g_strv_length(arrayStr) == 3 && strstr(arrayStr[0], "ci(")) {
g_free(*callerId);
*callerId = g_strdup(arrayStr[1]);
}
g_strfreev(arrayStr);
}
static void mgcpDialedDigits(gchar *signalStr, gchar **dialedDigits)
{
gchar *tmpStr;
gchar *resultStr;
gint i,j;
guint resultStrLen = 1;
if (signalStr == NULL) return;
tmpStr = g_strdup(signalStr);
for ( i = 0 ; tmpStr[i] ; i++) {
switch (tmpStr[i]) {
case '0' : case '1' : case '2' : case '3' : case '4' :
case '5' : case '6' : case '7' : case '8' : case '9' :
case '#' : case '*' :
resultStrLen++;
break;
default:
tmpStr[i] = '?';
break;
}
}
if (resultStrLen == 1) {
g_free(tmpStr);
return;
}
resultStr = (gchar *)g_malloc(resultStrLen);
for (i = 0, j = 0; tmpStr[i]; i++) {
if (tmpStr[i] != '?')
resultStr[j++] = tmpStr[i];
}
resultStr[j] = '\0';
g_free(*dialedDigits);
g_free(tmpStr);
*dialedDigits = resultStr;
return;
}
static int
MGCPcalls_packet( void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *MGCPinfo)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
mgcp_calls_info_t *tmp_mgcpinfo = NULL;
GList *list;
GList *listGraph;
gchar *frame_label = NULL;
gchar *comment = NULL;
seq_analysis_item_t *gai;
gboolean newcall = FALSE;
gboolean fromEndpoint = FALSE;
gdouble diff_time;
const mgcp_info_t *pi = (const mgcp_info_t *)MGCPinfo;
if ((pi->mgcp_type == MGCP_REQUEST) && !pi->is_duplicate ) {
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if ((tmp_listinfo->protocol == VOIP_MGCP) && (tmp_listinfo->call_active_state == VOIP_ACTIVE)) {
tmp_mgcpinfo = (mgcp_calls_info_t *)tmp_listinfo->prot_info;
if (pi->endpointId != NULL) {
if (g_ascii_strcasecmp(tmp_mgcpinfo->endpointId,pi->endpointId) == 0) {
diff_time = nstime_to_sec(&pinfo->rel_ts) - nstime_to_sec(&tmp_listinfo->stop_rel_ts);
if ( ((tmp_listinfo->call_state == VOIP_CANCELLED) ||
(tmp_listinfo->call_state == VOIP_COMPLETED) ||
(tmp_listinfo->call_state == VOIP_REJECTED)) &&
(diff_time > 2) )
{
tmp_listinfo->call_active_state = VOIP_INACTIVE;
} else {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
}
}
list = g_list_next (list);
}
if (callsinfo == NULL) {
if ( (strcmp(pi->code, "NTFY") == 0) && isSignal("hd", pi->observedEvents) ) {
fromEndpoint = TRUE;
newcall = TRUE;
} else if (strcmp(pi->code, "CRCX") == 0) {
fromEndpoint = FALSE;
newcall = TRUE;
}
if (!newcall) return 0;
}
} else if ( ((pi->mgcp_type == MGCP_RESPONSE) && pi->request_available) ||
((pi->mgcp_type == MGCP_REQUEST) && pi->is_duplicate) ) {
listGraph = g_list_first(tapinfo->graph_analysis->list);
while (listGraph)
{
gai = (seq_analysis_item_t *)listGraph->data;
if (gai->fd->num == pi->req_num) {
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_MGCP) {
if (tmp_listinfo->call_num == gai->conv_num) {
tmp_mgcpinfo = (mgcp_calls_info_t *)tmp_listinfo->prot_info;
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
if (callsinfo != NULL) break;
}
listGraph = g_list_next(listGraph);
}
if (callsinfo == NULL) return 0;
} else return 0;
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_CALL_SETUP;
if (fromEndpoint) {
callsinfo->from_identity=g_strdup(pi->endpointId);
callsinfo->to_identity=g_strdup("");
} else {
callsinfo->from_identity=g_strdup("");
callsinfo->to_identity=g_strdup(pi->endpointId);
}
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_MGCP;
callsinfo->prot_info=g_malloc(sizeof(mgcp_calls_info_t));
callsinfo->free_prot_info = g_free;
tmp_mgcpinfo=(mgcp_calls_info_t *)callsinfo->prot_info;
tmp_mgcpinfo->endpointId = g_strdup(pi->endpointId);
tmp_mgcpinfo->fromEndpoint = fromEndpoint;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
g_assert(tmp_mgcpinfo != NULL);
switch (pi->mgcp_type)
{
case MGCP_REQUEST:
if ( (strcmp(pi->code, "NTFY") == 0) && (pi->observedEvents != NULL) ) {
frame_label = g_strdup_printf("%s ObsEvt:%s",pi->code, pi->observedEvents);
if (tmp_mgcpinfo->fromEndpoint) {
if (callsinfo->to_identity[0] == '\0') mgcpDialedDigits(pi->observedEvents, &(callsinfo->to_identity));
} else if (isSignal("hd", pi->observedEvents))
callsinfo->call_state=VOIP_IN_CALL;
if (isSignal("hu", pi->observedEvents)) {
if ((callsinfo->call_state == VOIP_CALL_SETUP) || (callsinfo->call_state == VOIP_RINGING)) {
callsinfo->call_state = VOIP_CANCELLED;
} else {
callsinfo->call_state = VOIP_COMPLETED;
}
}
} else if (strcmp(pi->code, "RQNT") == 0) {
if ( tmp_mgcpinfo->fromEndpoint && isSignal("", pi->signalReq) && (callsinfo->call_state == VOIP_RINGING) ) {
callsinfo->call_state = VOIP_IN_CALL;
}
if ( isSignal("rg", pi->signalReq) || isSignal("rt", pi->signalReq) ) {
callsinfo->call_state = VOIP_RINGING;
}
if ( (isSignal("ro", pi->signalReq) || isSignal("bz", pi->signalReq)) && ((callsinfo->call_state == VOIP_CALL_SETUP) || (callsinfo->call_state == VOIP_RINGING)) ) {
callsinfo->call_state = VOIP_REJECTED;
}
if (pi->signalReq != NULL)
frame_label = g_strdup_printf("%s%sSigReq:%s",pi->code, (pi->hasDigitMap == TRUE)?" DigitMap ":"", pi->signalReq);
else
frame_label = g_strdup_printf("%s%s",pi->code, (pi->hasDigitMap == TRUE)?" DigitMap ":"");
if (!tmp_mgcpinfo->fromEndpoint) mgcpCallerID(pi->signalReq, &(callsinfo->from_identity));
} else if (strcmp(pi->code, "DLCX") == 0) {
if (!tmp_mgcpinfo->fromEndpoint) {
if ((callsinfo->call_state == VOIP_CALL_SETUP) || (callsinfo->call_state == VOIP_RINGING)) {
callsinfo->call_state = VOIP_CANCELLED;
}
}
}
if (frame_label == NULL) frame_label = g_strdup(pi->code);
break;
case MGCP_RESPONSE:
frame_label = g_strdup_printf("%u (%s)",pi->rspcode, pi->code);
break;
case MGCP_OTHERS:
break;
}
comment = g_strdup_printf("MGCP %s %s%s", tmp_mgcpinfo->endpointId, (pi->mgcp_type == MGCP_REQUEST)?"Request":"Response", pi->is_duplicate?" Duplicate":"");
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
g_free(frame_label);
if ( (sdp_summary != NULL) && (sdp_frame_num == pinfo->fd->num) ) {
append_to_frame_graph(tapinfo, pinfo->fd->num, sdp_summary, NULL);
g_free(sdp_summary);
sdp_summary = NULL;
}
tapinfo->redraw = TRUE;
return 1;
}
void
mgcp_calls_init_tap(void)
{
GString *error_string;
if(have_MGCP_tap_listener==FALSE)
{
error_string = register_tap_listener("mgcp",
&(the_tapinfo_struct.mgcp_dummy),
NULL,
TL_REQUIRES_PROTO_TREE,
voip_calls_dlg_reset,
MGCPcalls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_MGCP_tap_listener=TRUE;
}
}
void
remove_tap_listener_mgcp_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.mgcp_dummy));
have_MGCP_tap_listener=FALSE;
}
static int
ACTRACEcalls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *ACTRACEinfo)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
const actrace_info_t *pi = (const actrace_info_t *)ACTRACEinfo;
GList *list;
actrace_cas_calls_info_t *tmp_actrace_cas_info;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
actrace_frame_num = pinfo->fd->num;
actrace_trunk = pi->trunk;
actrace_direction = pi->direction;
if (pi->type == 1) {
address pstn_add;
gchar *comment = NULL;
callsinfo = NULL;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
tmp_listinfo=(voip_calls_info_t *)list->data;
if ( tmp_listinfo->protocol == VOIP_AC_CAS ) {
tmp_actrace_cas_info = (actrace_cas_calls_info_t *)tmp_listinfo->prot_info;
if ( (tmp_actrace_cas_info->bchannel == pi->cas_bchannel) && (tmp_actrace_cas_info->trunk == actrace_trunk) ) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
SET_ADDRESS(&pstn_add, AT_STRINGZ, 5, "PSTN");
if (!callsinfo) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_CALL_SETUP;
callsinfo->from_identity=g_strdup("N/A");
callsinfo->to_identity=g_strdup("N/A");
COPY_ADDRESS(&(callsinfo->initial_speaker),actrace_direction?&pstn_add:&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_AC_CAS;
callsinfo->prot_info=g_malloc(sizeof(actrace_cas_calls_info_t));
callsinfo->free_prot_info = g_free;
tmp_actrace_cas_info=(actrace_cas_calls_info_t *)callsinfo->prot_info;
tmp_actrace_cas_info->bchannel=pi->cas_bchannel;
tmp_actrace_cas_info->trunk=actrace_trunk;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
comment = g_strdup_printf("AC_CAS trunk:%u", actrace_trunk);
add_to_graph(tapinfo, pinfo, pi->cas_frame_label, comment, callsinfo->call_num,
actrace_direction?&pstn_add:&(pinfo->src),
actrace_direction?&(pinfo->src):&pstn_add,
1 );
g_free(comment);
}
tapinfo->redraw = TRUE;
return 1;
}
void
actrace_calls_init_tap(void)
{
GString *error_string;
if(have_actrace_tap_listener==FALSE)
{
error_string = register_tap_listener("actrace", &(the_tapinfo_struct.actrace_dummy), NULL,
0,
voip_calls_dlg_reset,
ACTRACEcalls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_actrace_tap_listener=TRUE;
}
}
void
remove_tap_listener_actrace_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.actrace_dummy));
have_actrace_tap_listener=FALSE;
}
static int h248_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prot_info) {
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
const gcp_cmd_t *cmd = (const gcp_cmd_t *)prot_info;
GList *list;
voip_calls_info_t *callsinfo = NULL;
address *mgw;
address *mgc;
gchar mgw_addr[128];
if (cmd->ctx->id == NULL_CONTEXT || cmd->ctx->id == ALL_CONTEXTS ) {
return 0;
}
if ( gcp_is_req(cmd->type) ) {
mgw = &(pinfo->dst);
mgc = &(pinfo->src);
} else {
mgc = &(pinfo->dst);
mgw = &(pinfo->src);
}
address_to_str_buf(mgw, mgw_addr, 128);
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
voip_calls_info_t* tmp_listinfo = (voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == TEL_H248) {
if (tmp_listinfo->prot_info == cmd->ctx) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_state = VOIP_NO_STATE;
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->from_identity = g_strdup_printf("%s : %.8x", mgw_addr, cmd->ctx->id);
callsinfo->to_identity = g_strdup("");
callsinfo->prot_info = cmd->ctx;
callsinfo->free_prot_info = NULL;
callsinfo->npackets = 1;
COPY_ADDRESS(&(callsinfo->initial_speaker), mgc);
callsinfo->protocol = TEL_H248;
callsinfo->call_num = tapinfo->ncalls++;
callsinfo->start_fd = pinfo->fd;
callsinfo->start_rel_ts = pinfo->rel_ts;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
callsinfo->selected = FALSE;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
} else {
GString *s = g_string_new("");
gcp_terms_t *ctx_term;
g_free(callsinfo->from_identity);
callsinfo->from_identity = g_strdup_printf("%s : %.8x", mgw_addr, ((gcp_ctx_t*)callsinfo->prot_info)->id);
g_free(callsinfo->to_identity);
for (ctx_term = ((gcp_ctx_t*)callsinfo->prot_info)->terms.next;
ctx_term;
ctx_term = ctx_term->next ) {
if ( ctx_term->term && ctx_term->term->str) {
g_string_append_printf(s," %s",ctx_term->term->str);
}
}
callsinfo->to_identity = s->str;
g_string_free(s,FALSE);
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
}
add_to_graph(tapinfo, pinfo, cmd->str ? cmd->str : "unknown Msg",
ep_strdup_printf("TrxId = %u, CtxId = %.8x",cmd->trx->id,cmd->ctx->id),
callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
++(tapinfo->npackets);
tapinfo->redraw = TRUE;
return 1;
}
void h248_calls_init_tap(void)
{
GString *error_string;
if(have_megaco_tap_listener==FALSE)
{
error_string = register_tap_listener("megaco", &(the_tapinfo_struct.megaco_dummy),
NULL,
0,
voip_calls_dlg_reset,
h248_calls_packet,
voip_calls_dlg_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_megaco_tap_listener=TRUE;
}
if(have_h248_tap_listener==FALSE)
{
error_string = register_tap_listener("h248", &(the_tapinfo_struct.h248_dummy),
NULL,
0,
voip_calls_dlg_reset,
h248_calls_packet,
voip_calls_dlg_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_h248_tap_listener=TRUE;
}
}
void
remove_tap_listener_h248_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.h248_dummy));
remove_tap_listener(&(the_tapinfo_struct.megaco_dummy));
have_megaco_tap_listener=FALSE;
have_h248_tap_listener=FALSE;
}
static int sccp_calls(packet_info *pinfo, const void *prot_info) {
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
const sccp_msg_info_t* msg = (const sccp_msg_info_t *)prot_info;
sccp_assoc_info_t* assoc = msg->data.co.assoc;
GList *list;
voip_calls_info_t *callsinfo = NULL;
const gchar *label = NULL;
const gchar *comment = NULL;
for(list = g_list_first(tapinfo->callsinfo_list) ; list ; list = g_list_next (list) ) {
if ( ((voip_calls_info_t*)(list->data))->prot_info == assoc ) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_state = VOIP_CALL_SETUP;
callsinfo->call_active_state = VOIP_ACTIVE;
if ( assoc->calling_party ) {
callsinfo->from_identity = g_strdup(assoc->calling_party);
} else {
callsinfo->from_identity = g_strdup("Unknown");
}
if ( assoc->called_party ) {
callsinfo->to_identity = g_strdup(assoc->called_party);
} else {
callsinfo->to_identity = g_strdup("Unknown");
}
callsinfo->prot_info = (void*)assoc;
callsinfo->free_prot_info = NULL;
callsinfo->npackets = 1;
COPY_ADDRESS(&(callsinfo->initial_speaker), &(pinfo->src));
callsinfo->protocol = SP2VP(assoc->payload);
callsinfo->start_fd = pinfo->fd;
callsinfo->start_rel_ts = pinfo->rel_ts;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
callsinfo->selected = FALSE;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
} else {
if ( assoc->calling_party ) {
g_free(callsinfo->from_identity);
callsinfo->from_identity = g_strdup(assoc->calling_party);
}
if ( assoc->called_party ) {
g_free(callsinfo->to_identity);
callsinfo->to_identity = g_strdup(assoc->called_party);
}
callsinfo->protocol = SP2VP(assoc->payload);
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
switch (msg->type) {
case SCCP_MSG_TYPE_CC:
callsinfo->call_state = VOIP_IN_CALL;
break;
case SCCP_MSG_TYPE_RLC:
callsinfo->call_state = VOIP_COMPLETED;
callsinfo->call_active_state = VOIP_INACTIVE;
break;
default:
break;
}
}
if (msg->data.co.label) {
label = msg->data.co.label;
} else {
label = val_to_str(msg->type, sccp_payload_values, "Unknown(%d)");
}
if (msg->data.co.comment) {
comment = msg->data.co.comment;
} else {
comment = NULL;
}
add_to_graph(tapinfo, pinfo, label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
++(tapinfo->npackets);
tapinfo->redraw = TRUE;
return 1;
}
static int sccp_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prot_info) {
sccp_payload_values = sccp_message_type_acro_values;
return sccp_calls(pinfo, prot_info);
}
static int sua_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prot_info) {
sccp_payload_values = sua_co_class_type_acro_values;
return sccp_calls(pinfo, prot_info);
}
void sccp_calls_init_tap(void)
{
GString *error_string;
if(have_sccp_tap_listener==FALSE)
{
error_string = register_tap_listener("sccp", &(the_tapinfo_struct.sccp_dummy),
NULL,
0,
voip_calls_dlg_reset,
sccp_calls_packet,
voip_calls_dlg_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_sccp_tap_listener=TRUE;
}
if(have_sua_tap_listener==FALSE)
{
error_string = register_tap_listener("sua", &(the_tapinfo_struct.sua_dummy),
NULL,
0,
voip_calls_dlg_reset,
sua_calls_packet,
voip_calls_dlg_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_sua_tap_listener=TRUE;
}
}
void
remove_tap_listener_sccp_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.sccp_dummy));
have_sccp_tap_listener=FALSE;
have_sua_tap_listener=FALSE;
}
static int
unistim_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *unistim_info)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *tmp_listinfo;
voip_calls_info_t *callsinfo = NULL;
unistim_info_t *tmp_unistim_info = NULL;
GList *list = NULL;
GString *g_tmp = NULL;
const gchar *frame_label = NULL;
gchar *comment = NULL;
const unistim_info_t *pi = (const unistim_info_t *)unistim_info;
g_tmp = g_string_new(NULL);
list = g_list_first(tapinfo->callsinfo_list);
while(list)
{
tmp_listinfo = (voip_calls_info_t *)list->data;
if(tmp_listinfo->protocol == VOIP_UNISTIM) {
tmp_unistim_info = (unistim_info_t *)tmp_listinfo->prot_info;
if(pi->termid != 0) {
if(tmp_unistim_info->termid == pi->termid) {
if(tmp_listinfo->call_state == VOIP_COMPLETED || tmp_listinfo->call_state == VOIP_UNKNOWN) {
} else {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
} else {
if(ADDRESSES_EQUAL(&tmp_unistim_info->it_ip, &pinfo->dst) && ADDRESSES_EQUAL(&tmp_unistim_info->ni_ip,&pinfo->src) && (tmp_unistim_info->it_port == pinfo->destport)) {
if(tmp_listinfo->call_state == VOIP_COMPLETED || tmp_listinfo->call_state == VOIP_UNKNOWN) {
} else {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
else if(ADDRESSES_EQUAL(&tmp_unistim_info->it_ip, &pinfo->src) && ADDRESSES_EQUAL(&tmp_unistim_info->ni_ip,&pinfo->dst) && (tmp_unistim_info->it_port == pinfo->srcport)) {
if(tmp_listinfo->call_state == VOIP_COMPLETED || tmp_listinfo->call_state == VOIP_UNKNOWN) {
} else {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
}
}
list = g_list_next(list);
}
if(pi->payload_type == 2 || pi->payload_type == 1) {
if(pi->key_state == 1 || pi->hook_state == 1) {
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_CALL_SETUP;
callsinfo->from_identity=g_strdup_printf("%x",pi->termid);
callsinfo->to_identity=g_strdup("UNKNOWN");
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_UNISTIM;
callsinfo->prot_info=g_malloc(sizeof(unistim_info_t));
tmp_unistim_info = (unistim_info_t *)callsinfo->prot_info;
tmp_unistim_info->rudp_type = 0;
tmp_unistim_info->payload_type = 0;
tmp_unistim_info->sequence = pi->sequence;
tmp_unistim_info->termid = pi->termid;
tmp_unistim_info->key_val = -1;
tmp_unistim_info->key_state = -1;
tmp_unistim_info->hook_state = -1;
tmp_unistim_info->stream_connect = -1;
tmp_unistim_info->trans_connect = -1;
tmp_unistim_info->set_termid = -1;
tmp_unistim_info->string_data = NULL;
tmp_unistim_info->key_buffer = NULL;
COPY_ADDRESS(&(tmp_unistim_info->it_ip),&(pi->it_ip));
COPY_ADDRESS(&(tmp_unistim_info->ni_ip),&(pi->ni_ip));
tmp_unistim_info->it_port = pi->it_port;
callsinfo->free_prot_info = g_free;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
} else {
tmp_unistim_info = (unistim_info_t *)callsinfo->prot_info;
tmp_unistim_info->sequence = pi->sequence;
}
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
if(pi->key_val >= 0 && pi->key_val <= 11) {
if(tmp_unistim_info->key_buffer != NULL) {
g_string_assign(g_tmp,tmp_unistim_info->key_buffer);
if(pi->key_val == 10) {
tmp_unistim_info->key_buffer = g_strdup_printf("%s*",g_tmp->str);
} else if(pi->key_val == 11) {
tmp_unistim_info->key_buffer = g_strdup_printf("%s#",g_tmp->str);
} else {
tmp_unistim_info->key_buffer = g_strdup_printf("%s%d",g_tmp->str,pi->key_val);
}
} else {
if(pi->key_val == 10) {
tmp_unistim_info->key_buffer = g_strdup("*");
} else if(pi->key_val == 11) {
tmp_unistim_info->key_buffer = g_strdup("#");
} else {
tmp_unistim_info->key_buffer = g_strdup_printf("%d",pi->key_val);
}
}
if(pi->key_val == 10) {
comment = g_strdup_printf("Key Input Sent: * (%d)", pi->sequence);
} else if(pi->key_val == 11) {
comment = g_strdup_printf("Key Input Sent: # (%d)", pi->sequence);
} else {
comment = g_strdup_printf("Key Input Sent: %d (%d)",pi->key_val, pi->sequence);
}
} else if(pi->key_val == 12) {
comment = g_strdup_printf("Key Input Sent: UP (%d)", pi->sequence);
} else if(pi->key_val == 13) {
comment = g_strdup_printf("Key Input Sent: DOWN (%d)", pi->sequence);
} else if(pi->key_val == 14) {
comment = g_strdup_printf("Key Input Sent: RIGHT (%d)", pi->sequence);
} else if(pi->key_val == 15) {
if(pi->key_buffer != NULL) {
g_string_assign(g_tmp,pi->key_buffer);
g_string_truncate(g_tmp,g_tmp->len-1);
tmp_unistim_info->key_buffer = g_strdup(g_tmp->str);
}
comment = g_strdup_printf("Key Input Sent: LEFT (%d)", pi->sequence);
} else if(pi->key_val == 20) {
comment = g_strdup_printf("Key Input Sent: S0 (%d)", pi->sequence);
} else if(pi->key_val == 21) {
comment = g_strdup_printf("Key Input Sent: S1 (%d)", pi->sequence);
} else if(pi->key_val == 22) {
if(pi->key_buffer != NULL) {
g_string_assign(g_tmp,pi->key_buffer);
g_string_truncate(g_tmp,g_tmp->len-1);
tmp_unistim_info->key_buffer = g_strdup(g_tmp->str);
}
comment = g_strdup_printf("Key Input Sent: S2 (%d)", pi->sequence);
} else if(pi->key_val == 28) {
comment = g_strdup_printf("Key Input Sent: Release (%d)", pi->sequence);
} else if(pi->key_val == 23) {
tmp_unistim_info->key_buffer = g_strdup("\n");
comment = g_strdup_printf("Key Input Sent: S3 (%d)", pi->sequence);
} else if(pi->key_val == 27) {
comment = g_strdup_printf("Key Input Sent: Hold (%d)", pi->sequence);
} else if(pi->key_val == 29) {
comment = g_strdup_printf("Key Input Sent: Mute (%d)", pi->sequence);
} else if(pi->key_val == 30) {
comment = g_strdup_printf("Key Input Sent: Headset (%d)", pi->sequence);
} else if(pi->key_val == 31) {
comment = g_strdup_printf("Key Input Sent: Handsfree (%d)", pi->sequence);
} else if(pi->key_val >= 32 && pi->key_val <= 56) {
comment = g_strdup_printf("Key Input Sent: Prog%d (%d)", (pi->key_val & 31), pi->sequence);
}
if(pi->key_val != -1) {
frame_label = "KEY INPUT";
if (comment == NULL)
comment = g_strdup_printf("Key Input Sent: UNKNOWN - %d (%d)", pi->key_val, pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
}
if(pi->hook_state == 1) {
frame_label = "OFF HOOK";
comment = g_strdup_printf("Off Hook (%d)", pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
} else if(pi->hook_state == 0) {
frame_label = "ON HOOK";
comment = g_strdup_printf("On Hook (%d)", pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
}
}
if(pi->stream_connect == 1 && callsinfo != NULL) {
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
if(tmp_unistim_info->key_buffer != NULL) {
callsinfo->to_identity = g_strdup_printf("?? %s",tmp_unistim_info->key_buffer);
}
tmp_unistim_info->sequence = pi->sequence;
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_IN_CALL;
frame_label = "STREAM OPENED";
comment = g_strdup_printf("Stream Opened (%d)",pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
} else if(pi->stream_connect == 1 && callsinfo == NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_CALL_SETUP;
callsinfo->from_identity=g_strdup("UNKNOWN");
callsinfo->to_identity=g_strdup("UNKNOWN");
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_UNISTIM;
callsinfo->prot_info=g_malloc(sizeof(unistim_info_t));
tmp_unistim_info = (unistim_info_t *)callsinfo->prot_info;
tmp_unistim_info->rudp_type = 0;
tmp_unistim_info->payload_type = 0;
tmp_unistim_info->sequence = pi->sequence;
tmp_unistim_info->termid = 0;
tmp_unistim_info->key_val = -1;
tmp_unistim_info->key_state = -1;
tmp_unistim_info->hook_state = -1;
tmp_unistim_info->stream_connect = -1;
tmp_unistim_info->trans_connect = -1;
tmp_unistim_info->set_termid = -1;
tmp_unistim_info->string_data = NULL;
tmp_unistim_info->key_buffer = NULL;
COPY_ADDRESS(&(tmp_unistim_info->it_ip),&(pi->it_ip));
COPY_ADDRESS(&(tmp_unistim_info->ni_ip),&(pi->ni_ip));
tmp_unistim_info->it_port = pi->it_port;
callsinfo->free_prot_info = g_free;
callsinfo->npackets = 0;
callsinfo->call_num = tapinfo->ncalls++;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
if(tmp_unistim_info->key_buffer != NULL) {
callsinfo->to_identity = g_strdup_printf("?? %s",tmp_unistim_info->key_buffer);
}
tmp_unistim_info->sequence = pi->sequence;
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->call_state = VOIP_IN_CALL;
frame_label = "STREAM OPENED";
comment = g_strdup_printf("Stream Opened (%d)",pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
} else if(pi->stream_connect == 0 && callsinfo != NULL) {
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
tmp_unistim_info->sequence = pi->sequence;
if(callsinfo->call_state == VOIP_IN_CALL) {
callsinfo->call_active_state = VOIP_INACTIVE;
callsinfo->call_state = VOIP_COMPLETED;
} else {
callsinfo->call_state = VOIP_UNKNOWN;
callsinfo->call_active_state = VOIP_INACTIVE;
}
frame_label = "STREAM CLOSED";
comment = g_strdup_printf("Stream Closed (%d)",pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
} else
comment = NULL;
} else if(pi->rudp_type == 1 && callsinfo != NULL) {
if(tmp_unistim_info->sequence == pi->sequence) {
frame_label = "ACK";
comment = g_strdup_printf("ACK for sequence %d",pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
}
} else if(pi->rudp_type == 0 && callsinfo != NULL) {
frame_label = "NAK";
comment = g_strdup_printf("NAK for sequence %d",pi->sequence);
add_to_graph(tapinfo, pinfo, frame_label, comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
}
g_free(comment);
tapinfo->redraw = TRUE;
return 1;
}
void
unistim_calls_init_tap(void) {
GString *error_string;
if(have_unistim_tap_listener==FALSE) {
error_string = register_tap_listener("unistim", &(the_tapinfo_struct.unistim_dummy),
NULL,
0,
voip_calls_dlg_reset,
unistim_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_unistim_tap_listener=TRUE;
}
}
void
remove_tap_listener_unistim_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.unistim_dummy));
have_unistim_tap_listener=FALSE;
}
static int
skinny_calls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *skinny_info)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
GList* list;
voip_calls_info_t *callsinfo = NULL;
address* phone;
const skinny_info_t *si = (const skinny_info_t *)skinny_info;
skinny_calls_info_t *tmp_skinnyinfo;
gchar *comment;
if (si == NULL || (si->callId == 0 && si->passThruId == 0))
return 0;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
voip_calls_info_t* tmp_listinfo = (voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_SKINNY) {
tmp_skinnyinfo = (skinny_calls_info_t *)tmp_listinfo->prot_info;
if (tmp_skinnyinfo->callId == si->callId ||
tmp_skinnyinfo->callId == si->passThruId) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
if (si->messId >= 256)
phone = &(pinfo->dst);
else
phone = &(pinfo->src);
if (callsinfo==NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_state = VOIP_NO_STATE;
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->from_identity = g_strdup("");
callsinfo->to_identity = g_strdup("");
callsinfo->prot_info = g_malloc(sizeof(skinny_calls_info_t));
callsinfo->free_prot_info = g_free;
tmp_skinnyinfo = (skinny_calls_info_t *)callsinfo->prot_info;
tmp_skinnyinfo->callId = si->callId ? si->callId : si->passThruId;
callsinfo->npackets = 1;
COPY_ADDRESS(&(callsinfo->initial_speaker), phone);
callsinfo->protocol = VOIP_SKINNY;
callsinfo->call_num = tapinfo->ncalls++;
callsinfo->start_fd = pinfo->fd;
callsinfo->start_rel_ts = pinfo->rel_ts;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
callsinfo->selected = FALSE;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
} else {
if (si->callingParty) {
g_free(callsinfo->from_identity);
callsinfo->from_identity = g_strdup(si->callingParty);
}
if (si->calledParty) {
g_free(callsinfo->to_identity);
callsinfo->to_identity = g_strdup(si->calledParty);
}
if ((si->callState > 0) && (si->callState < (sizeof(skinny_tap_voip_state)/sizeof(skinny_tap_voip_state[0]))))
callsinfo->call_state = skinny_tap_voip_state[si->callState];
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
}
if (si->callId) {
if (si->passThruId)
comment = g_strdup_printf("CallId = %u, PTId = %u", si->callId, si->passThruId);
else
comment = g_strdup_printf("CallId = %u, LineId = %u", si->callId, si->lineId);
} else {
if (si->passThruId)
comment = g_strdup_printf("PTId = %u", si->passThruId);
else
comment = NULL;
}
add_to_graph(tapinfo, pinfo, si->messageName, comment,
callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
g_free(comment);
return 1;
}
void
skinny_calls_init_tap(void)
{
GString *error_string;
if(have_skinny_tap_listener==FALSE)
{
error_string = register_tap_listener("skinny",
&(the_tapinfo_struct.skinny_dummy),
NULL,
TL_REQUIRES_PROTO_TREE,
voip_calls_dlg_reset,
skinny_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_skinny_tap_listener=TRUE;
}
}
void
remove_tap_listener_skinny_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.skinny_dummy));
have_skinny_tap_listener=FALSE;
}
static void free_iax2_info(gpointer p) {
iax2_info_t *ii = (iax2_info_t *)p;
g_free(ii);
}
static int
iax2_calls_packet( void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *iax2_info)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
GList* list;
voip_calls_info_t *callsinfo = NULL;
address* phone;
const iax2_info_t *ii = (const iax2_info_t *)iax2_info;
iax2_info_t *tmp_iax2info;
if (ii == NULL || ii->ptype != IAX2_FULL_PACKET || (ii->scallno == 0 && ii->dcallno == 0))
return 0;
list = g_list_first(tapinfo->callsinfo_list);
while (list)
{
voip_calls_info_t* tmp_listinfo = (voip_calls_info_t *)list->data;
if (tmp_listinfo->protocol == VOIP_IAX2) {
tmp_iax2info = (iax2_info_t *)tmp_listinfo->prot_info;
if (tmp_iax2info->scallno == ii->scallno ||
tmp_iax2info->scallno == ii->dcallno) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next (list);
}
phone = &(pinfo->src);
if (callsinfo==NULL) {
if (ii->ftype != AST_FRAME_IAX || ii->csub != IAX_COMMAND_NEW)
return 0;
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_state = VOIP_NO_STATE;
callsinfo->call_active_state = VOIP_ACTIVE;
callsinfo->prot_info=g_malloc(sizeof(iax2_info_t));
callsinfo->free_prot_info = free_iax2_info;
tmp_iax2info = (iax2_info_t *)callsinfo->prot_info;
tmp_iax2info->scallno = ii->scallno;
if (tmp_iax2info->scallno == 0) tmp_iax2info->scallno = ii->dcallno;
tmp_iax2info->callState = ii->callState;
callsinfo->npackets = 1;
COPY_ADDRESS(&(callsinfo->initial_speaker), phone);
callsinfo->from_identity = g_strdup(ii->callingParty);
callsinfo->to_identity = g_strdup(ii->calledParty);
callsinfo->protocol = VOIP_IAX2;
callsinfo->call_num = tapinfo->ncalls++;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
callsinfo->selected = FALSE;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
} else {
callsinfo->call_state = ii->callState;
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
}
add_to_graph(tapinfo, pinfo, ii->messageName, "",
callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
return 1;
}
void
iax2_calls_init_tap(void)
{
GString *error_string;
if(have_iax2_tap_listener==FALSE)
{
error_string = register_tap_listener("IAX2",
&(the_tapinfo_struct.iax2_dummy),
NULL,
TL_REQUIRES_PROTO_TREE,
voip_calls_dlg_reset,
iax2_calls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_iax2_tap_listener=TRUE;
}
}
void
remove_tap_listener_iax2_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.iax2_dummy));
have_iax2_tap_listener=FALSE;
}
static int
VoIPcalls_packet(void *ptr _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *VoIPinfo)
{
voip_calls_tapinfo_t *tapinfo = &the_tapinfo_struct;
voip_calls_info_t *callsinfo = NULL;
voip_calls_info_t *tmp_listinfo;
GList *list = NULL;
const voip_packet_info_t *pi = (const voip_packet_info_t *)VoIPinfo;
if (pi->call_id)
list = g_list_first(tapinfo->callsinfo_list);
while (list) {
tmp_listinfo = (voip_calls_info_t *)list->data;
if ( tmp_listinfo->protocol == VOIP_COMMON ) {
if (!strcmp(pi->call_id, tmp_listinfo->call_id)) {
callsinfo = (voip_calls_info_t*)(list->data);
break;
}
}
list = g_list_next(list);
}
if (callsinfo == NULL) {
callsinfo = (voip_calls_info_t *)g_malloc0(sizeof(voip_calls_info_t));
callsinfo->call_active_state = pi->call_active_state;
callsinfo->call_state = pi->call_state;
callsinfo->call_id=g_strdup((pi->call_id)?pi->call_id:"");
callsinfo->from_identity = g_strdup((pi->from_identity)?pi->from_identity:"");
callsinfo->to_identity = g_strdup((pi->to_identity)?pi->to_identity:"");
COPY_ADDRESS(&(callsinfo->initial_speaker),&(pinfo->src));
callsinfo->selected=FALSE;
callsinfo->start_fd=pinfo->fd;
callsinfo->start_rel_ts=pinfo->rel_ts;
callsinfo->protocol=VOIP_COMMON;
callsinfo->protocol_name=g_strdup((pi->protocol_name)?pi->protocol_name:"");
callsinfo->call_comment=g_strdup((pi->call_comment)?pi->call_comment:"");
callsinfo->prot_info=NULL;
callsinfo->free_prot_info = NULL;
callsinfo->call_num = tapinfo->ncalls++;
callsinfo->npackets = 0;
tapinfo->callsinfo_list = g_list_prepend(tapinfo->callsinfo_list, callsinfo);
}
callsinfo->call_active_state = pi->call_active_state;
if ((callsinfo->call_state != VOIP_COMPLETED) && (pi->call_state == VOIP_COMPLETED))
tapinfo->completed_calls++;
if (pi->call_state != VOIP_NO_STATE)
callsinfo->call_state = pi->call_state;
if (pi->call_comment) {
g_free(callsinfo->call_comment);
callsinfo->call_comment=g_strdup(pi->call_comment);
}
callsinfo->stop_fd = pinfo->fd;
callsinfo->stop_rel_ts = pinfo->rel_ts;
++(callsinfo->npackets);
++(tapinfo->npackets);
add_to_graph(tapinfo, pinfo, (pi->frame_label)?pi->frame_label:"VoIP msg", pi->frame_comment, callsinfo->call_num, &(pinfo->src), &(pinfo->dst), 1);
tapinfo->redraw = TRUE;
return 1;
}
void
VoIPcalls_init_tap(void)
{
GString *error_string;
if(have_voip_tap_listener==FALSE)
{
error_string = register_tap_listener("voip", &(the_tapinfo_struct.voip_dummy),
NULL,
0,
voip_calls_dlg_reset,
VoIPcalls_packet,
voip_calls_dlg_draw
);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%s", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
have_voip_tap_listener=TRUE;
}
}
void
remove_tap_listener_voip_calls(void)
{
remove_tap_listener(&(the_tapinfo_struct.voip_dummy));
have_voip_tap_listener=FALSE;
}
