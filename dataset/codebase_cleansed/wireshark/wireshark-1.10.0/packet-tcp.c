struct tcp_analysis *
init_tcp_conversation_data(packet_info *pinfo)
{
struct tcp_analysis *tcpd;
tcpd=se_new0(struct tcp_analysis);
tcpd->flow1.win_scale=-1;
tcpd->flow1.window = G_MAXUINT32;
tcpd->flow1.multisegment_pdus=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "tcp_multisegment_pdus");
tcpd->flow2.window = G_MAXUINT32;
tcpd->flow2.win_scale=-1;
tcpd->flow2.multisegment_pdus=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "tcp_multisegment_pdus");
tcpd->acked_table=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "tcp_analyze_acked_table");
tcpd->ts_first.secs=pinfo->fd->abs_ts.secs;
tcpd->ts_first.nsecs=pinfo->fd->abs_ts.nsecs;
tcpd->ts_prev.secs=pinfo->fd->abs_ts.secs;
tcpd->ts_prev.nsecs=pinfo->fd->abs_ts.nsecs;
tcpd->flow1.valid_bif = 1;
tcpd->flow2.valid_bif = 1;
tcpd->stream = tcp_stream_index++;
tcpd->server_port = 0;
return tcpd;
}
struct tcp_analysis *
get_tcp_conversation_data(conversation_t *conv, packet_info *pinfo)
{
int direction;
struct tcp_analysis *tcpd;
if( conv==NULL )
conv = find_or_create_conversation(pinfo);
tcpd=(struct tcp_analysis *)conversation_get_proto_data(conv, proto_tcp);
if (!tcpd) {
tcpd = init_tcp_conversation_data(pinfo);
conversation_add_proto_data(conv, proto_tcp, tcpd);
}
if (!tcpd) {
return NULL;
}
direction=CMP_ADDRESS(&pinfo->src, &pinfo->dst);
if(direction==0) {
direction= (pinfo->srcport > pinfo->destport) ? 1 : -1;
}
if(direction>=0) {
tcpd->fwd=&(tcpd->flow1);
tcpd->rev=&(tcpd->flow2);
} else {
tcpd->fwd=&(tcpd->flow2);
tcpd->rev=&(tcpd->flow1);
}
tcpd->ta=NULL;
return tcpd;
}
void
add_tcp_process_info(guint32 frame_num, address *local_addr, address *remote_addr, guint16 local_port, guint16 remote_port, guint32 uid, guint32 pid, gchar *username, gchar *command) {
conversation_t *conv;
struct tcp_analysis *tcpd;
tcp_flow_t *flow = NULL;
conv = find_conversation(frame_num, local_addr, remote_addr, PT_TCP, local_port, remote_port, 0);
if (!conv) {
return;
}
tcpd = (struct tcp_analysis *)conversation_get_proto_data(conv, proto_tcp);
if (!tcpd) {
return;
}
if (CMP_ADDRESS(local_addr, &conv->key_ptr->addr1) == 0 && local_port == conv->key_ptr->port1) {
flow = &tcpd->flow1;
} else if (CMP_ADDRESS(remote_addr, &conv->key_ptr->addr1) == 0 && remote_port == conv->key_ptr->port1) {
flow = &tcpd->flow2;
}
if (!flow || flow->command) {
return;
}
flow->process_uid = uid;
flow->process_pid = pid;
flow->username = se_strdup(username);
flow->command = se_strdup(command);
}
static void
tcp_calculate_timestamps(packet_info *pinfo, struct tcp_analysis *tcpd,
struct tcp_per_packet_data_t *tcppd)
{
if( !tcppd ) {
tcppd = se_new(struct tcp_per_packet_data_t);
p_add_proto_data(pinfo->fd, proto_tcp, 0, tcppd);
}
if (!tcpd)
return;
nstime_delta(&tcppd->ts_del, &pinfo->fd->abs_ts, &tcpd->ts_prev);
tcpd->ts_prev.secs=pinfo->fd->abs_ts.secs;
tcpd->ts_prev.nsecs=pinfo->fd->abs_ts.nsecs;
}
static void
tcp_print_timestamps(packet_info *pinfo, tvbuff_t *tvb, proto_tree *parent_tree, struct tcp_analysis *tcpd, struct tcp_per_packet_data_t *tcppd)
{
proto_item *item;
proto_tree *tree;
nstime_t ts;
if (!tcpd)
return;
item=proto_tree_add_text(parent_tree, tvb, 0, 0, "Timestamps");
PROTO_ITEM_SET_GENERATED(item);
tree=proto_item_add_subtree(item, ett_tcp_timestamps);
nstime_delta(&ts, &pinfo->fd->abs_ts, &tcpd->ts_first);
item = proto_tree_add_time(tree, hf_tcp_ts_relative, tvb, 0, 0, &ts);
PROTO_ITEM_SET_GENERATED(item);
if( !tcppd )
tcppd = (struct tcp_per_packet_data_t *)p_get_proto_data(pinfo->fd, proto_tcp, 0);
if( tcppd ) {
item = proto_tree_add_time(tree, hf_tcp_ts_delta, tvb, 0, 0,
&tcppd->ts_del);
PROTO_ITEM_SET_GENERATED(item);
}
}
static void
print_pdu_tracking_data(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tcp_tree, struct tcp_multisegment_pdu *msp)
{
proto_item *item;
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[Continuation to #%u] ", msp->first_frame);
item=proto_tree_add_uint(tcp_tree, hf_tcp_continuation_to,
tvb, 0, 0, msp->first_frame);
PROTO_ITEM_SET_GENERATED(item);
}
static int
scan_for_next_pdu(tvbuff_t *tvb, proto_tree *tcp_tree, packet_info *pinfo, int offset, guint32 seq, guint32 nxtseq, emem_tree_t *multisegment_pdus)
{
struct tcp_multisegment_pdu *msp=NULL;
if(!pinfo->fd->flags.visited) {
msp=(struct tcp_multisegment_pdu *)se_tree_lookup32_le(multisegment_pdus, seq-1);
if(msp) {
if(seq>msp->seq && seq<msp->nxtpdu) {
msp->last_frame=pinfo->fd->num;
msp->last_frame_time=pinfo->fd->abs_ts;
print_pdu_tracking_data(pinfo, tvb, tcp_tree, msp);
}
if(seq>msp->seq && nxtseq<=msp->nxtpdu) {
return -1;
}
if(seq<msp->nxtpdu && nxtseq>msp->nxtpdu) {
offset+=msp->nxtpdu-seq;
return offset;
}
}
} else {
msp=(struct tcp_multisegment_pdu *)se_tree_lookup32_le(multisegment_pdus, nxtseq-1);
if(msp) {
if(pinfo->fd->num==msp->first_frame) {
proto_item *item;
nstime_t ns;
item=proto_tree_add_uint(tcp_tree, hf_tcp_pdu_last_frame, tvb, 0, 0, msp->last_frame);
PROTO_ITEM_SET_GENERATED(item);
nstime_delta(&ns, &msp->last_frame_time, &pinfo->fd->abs_ts);
item = proto_tree_add_time(tcp_tree, hf_tcp_pdu_time,
tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(item);
}
}
msp=(struct tcp_multisegment_pdu *)se_tree_lookup32_le(multisegment_pdus, seq-1);
if(msp) {
if(seq>msp->seq && nxtseq<=msp->nxtpdu) {
print_pdu_tracking_data(pinfo, tvb, tcp_tree, msp);
return -1;
}
if(seq<msp->nxtpdu && nxtseq>msp->nxtpdu) {
offset+=msp->nxtpdu-seq;
return offset;
}
}
}
return offset;
}
struct tcp_multisegment_pdu *
pdu_store_sequencenumber_of_next_pdu(packet_info *pinfo, guint32 seq, guint32 nxtpdu, emem_tree_t *multisegment_pdus)
{
struct tcp_multisegment_pdu *msp;
msp=se_new(struct tcp_multisegment_pdu);
msp->nxtpdu=nxtpdu;
msp->seq=seq;
msp->first_frame=pinfo->fd->num;
msp->last_frame=pinfo->fd->num;
msp->last_frame_time=pinfo->fd->abs_ts;
msp->flags=0;
se_tree_insert32(multisegment_pdus, seq, (void *)msp);
return msp;
}
static void
verify_tcp_window_scaling(gboolean is_synack, struct tcp_analysis *tcpd)
{
if( tcpd->fwd->win_scale==-1 ) {
tcpd->fwd->win_scale = -2;
tcpd->rev->win_scale = -2;
} else if( is_synack && tcpd->rev->win_scale==-2 ) {
tcpd->fwd->win_scale = -2;
}
}
static void
pdu_store_window_scale_option(guint8 ws, struct tcp_analysis *tcpd)
{
if (tcpd)
tcpd->fwd->win_scale=ws;
}
static void
tcp_analyze_get_acked_struct(guint32 frame, guint32 seq, guint32 ack, gboolean createflag, struct tcp_analysis *tcpd)
{
emem_tree_key_t key[] = {{1, &frame}, {1, &seq}, {1, &ack}, {0, NULL}};
if (!tcpd) {
return;
}
tcpd->ta = (struct tcp_acked *)se_tree_lookup32_array(tcpd->acked_table, key);
if((!tcpd->ta) && createflag) {
tcpd->ta = se_new0(struct tcp_acked);
se_tree_insert32_array(tcpd->acked_table, key, (void *)tcpd->ta);
}
}
static void
tcp_analyze_sequence_number(packet_info *pinfo, guint32 seq, guint32 ack, guint32 seglen, guint16 flags, guint32 window, struct tcp_analysis *tcpd)
{
tcp_unacked_t *ual=NULL;
tcp_unacked_t *prevual=NULL;
guint32 nextseq;
int ackcount;
#if 0
printf("\nanalyze_sequence numbers frame:%u\n",pinfo->fd->num);
printf("FWD list lastflags:0x%04x base_seq:%u:\n",tcpd->fwd->lastsegmentflags,tcpd->fwd->base_seq);
for(ual=tcpd->fwd->segments; ual; ual=ual->next)
printf("Frame:%d Seq:%u Nextseq:%u\n",ual->frame,ual->seq,ual->nextseq);
printf("REV list lastflags:0x%04x base_seq:%u:\n",tcpd->rev->lastsegmentflags,tcpd->rev->base_seq);
for(ual=tcpd->rev->segments; ual; ual=ual->next)
printf("Frame:%d Seq:%u Nextseq:%u\n",ual->frame,ual->seq,ual->nextseq);
#endif
if (!tcpd) {
return;
}
if(tcpd->fwd->base_seq==0) {
tcpd->fwd->base_seq = (flags & TH_SYN) ? seq : seq-1;
}
if( (tcpd->rev->base_seq==0) && (flags & TH_ACK) ) {
tcpd->rev->base_seq = ack-1;
}
if( flags & TH_ACK ) {
tcpd->rev->valid_bif = 1;
}
if( seglen==1
&& seq==tcpd->fwd->nextseq
&& tcpd->rev->window==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_ZERO_WINDOW_PROBE;
goto finished_fwd;
}
if( window==0
&& (flags&(TH_RST|TH_FIN|TH_SYN))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_ZERO_WINDOW;
}
if( tcpd->fwd->nextseq
&& GT_SEQ(seq, tcpd->fwd->nextseq)
&& (flags&(TH_RST))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_LOST_PACKET;
tcpd->fwd->valid_bif = 0;
}
if( (seglen==0||seglen==1)
&& seq==(tcpd->fwd->nextseq-1)
&& (flags&(TH_SYN|TH_FIN|TH_RST))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_KEEP_ALIVE;
}
if( seglen==0
&& window
&& window!=tcpd->fwd->window
&& seq==tcpd->fwd->nextseq
&& ack==tcpd->fwd->lastack
&& (flags&(TH_SYN|TH_FIN|TH_RST))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_WINDOW_UPDATE;
}
if( seglen>0
&& tcpd->rev->win_scale!=-1
&& (seq+seglen)==(tcpd->rev->lastack+(tcpd->rev->window<<(tcpd->rev->win_scale==-2?0:tcpd->rev->win_scale)))
&& (flags&(TH_SYN|TH_FIN|TH_RST))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_WINDOW_FULL;
}
if( seglen==0
&& window
&& window==tcpd->fwd->window
&& seq==tcpd->fwd->nextseq
&& ack==tcpd->fwd->lastack
&& (tcpd->rev->lastsegmentflags&TCP_A_KEEP_ALIVE)
&& (flags&(TH_SYN|TH_FIN|TH_RST))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_KEEP_ALIVE_ACK;
goto finished_fwd;
}
if( seglen==0
&& window==0
&& window==tcpd->fwd->window
&& seq==tcpd->fwd->nextseq
&& ack==tcpd->fwd->lastack
&& (tcpd->rev->lastsegmentflags&TCP_A_ZERO_WINDOW_PROBE)
&& (flags&(TH_SYN|TH_FIN|TH_RST))==0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_ZERO_WINDOW_PROBE_ACK;
goto finished_fwd;
}
if( seglen==0
&& window
&& window==tcpd->fwd->window
&& seq==tcpd->fwd->nextseq
&& ack==tcpd->fwd->lastack
&& (flags&(TH_SYN|TH_FIN|TH_RST))==0 ) {
tcpd->fwd->dupacknum++;
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_DUPLICATE_ACK;
tcpd->ta->dupack_num=tcpd->fwd->dupacknum;
tcpd->ta->dupack_frame=tcpd->fwd->lastnondupack;
}
finished_fwd:
if( (!tcpd->ta) || !(tcpd->ta->flags&TCP_A_DUPLICATE_ACK) ) {
tcpd->fwd->lastnondupack=pinfo->fd->num;
tcpd->fwd->dupacknum=0;
}
if( tcpd->rev->maxseqtobeacked
&& GT_SEQ(ack, tcpd->rev->maxseqtobeacked )
&& (flags&(TH_ACK))!=0 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_ACK_LOST_PACKET;
tcpd->rev->maxseqtobeacked=tcpd->rev->nextseq;
}
if( seglen>0
&& tcpd->fwd->nextseq
&& (LT_SEQ(seq, tcpd->fwd->nextseq)) ) {
guint64 t;
if(tcpd->ta && (tcpd->ta->flags&TCP_A_KEEP_ALIVE) ) {
goto finished_checking_retransmission_type;
}
t=(pinfo->fd->abs_ts.secs-tcpd->rev->lastacktime.secs)*1000000000;
t=t+(pinfo->fd->abs_ts.nsecs)-tcpd->rev->lastacktime.nsecs;
if( tcpd->rev->dupacknum>=2
&& tcpd->rev->lastack==seq
&& t<20000000 ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_FAST_RETRANSMISSION;
goto finished_checking_retransmission_type;
}
t=(pinfo->fd->abs_ts.secs-tcpd->fwd->nextseqtime.secs)*1000000000;
t=t+(pinfo->fd->abs_ts.nsecs)-tcpd->fwd->nextseqtime.nsecs;
if( t<3000000
&& tcpd->fwd->nextseq != seq + seglen ) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_OUT_OF_ORDER;
goto finished_checking_retransmission_type;
}
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->flags|=TCP_A_RETRANSMISSION;
nstime_delta(&tcpd->ta->rto_ts, &pinfo->fd->abs_ts, &tcpd->fwd->nextseqtime);
tcpd->ta->rto_frame=tcpd->fwd->nextseqframe;
}
finished_checking_retransmission_type:
nextseq = seq+seglen;
if (seglen || flags&(TH_SYN|TH_FIN)) {
ual = g_slice_new(tcp_unacked_t);
ual->next=tcpd->fwd->segments;
tcpd->fwd->segments=ual;
ual->frame=pinfo->fd->num;
ual->seq=seq;
ual->ts=pinfo->fd->abs_ts;
if( (flags&(TH_SYN|TH_FIN)) ) {
nextseq+=1;
}
ual->nextseq=nextseq;
}
if(GT_SEQ(nextseq, tcpd->fwd->nextseq) || !tcpd->fwd->nextseq) {
if( !tcpd->ta || !(tcpd->ta->flags&TCP_A_ZERO_WINDOW_PROBE) ) {
tcpd->fwd->nextseq=nextseq;
tcpd->fwd->nextseqframe=pinfo->fd->num;
tcpd->fwd->nextseqtime.secs=pinfo->fd->abs_ts.secs;
tcpd->fwd->nextseqtime.nsecs=pinfo->fd->abs_ts.nsecs;
}
}
if(EQ_SEQ(seq, tcpd->fwd->maxseqtobeacked) || !tcpd->fwd->maxseqtobeacked) {
if( !tcpd->ta || !(tcpd->ta->flags&TCP_A_ZERO_WINDOW_PROBE) ) {
tcpd->fwd->maxseqtobeacked=tcpd->fwd->nextseq;
}
}
tcpd->fwd->window=window;
tcpd->fwd->lastack=ack;
tcpd->fwd->lastacktime.secs=pinfo->fd->abs_ts.secs;
tcpd->fwd->lastacktime.nsecs=pinfo->fd->abs_ts.nsecs;
if(tcpd->ta) {
tcpd->fwd->lastsegmentflags=tcpd->ta->flags;
} else {
tcpd->fwd->lastsegmentflags=0;
}
ackcount=0;
prevual = NULL;
ual = tcpd->rev->segments;
while(ual) {
tcp_unacked_t *tmpual;
if(ack==ual->nextseq) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
tcpd->ta->frame_acked=ual->frame;
nstime_delta(&tcpd->ta->ts, &pinfo->fd->abs_ts, &ual->ts);
}
else if (GT_SEQ(ack, ual->seq) && LE_SEQ(ack, ual->nextseq)) {
ual->seq = ack;
continue;
}
else if (GT_SEQ(ual->nextseq,ack)) {
prevual = ual;
ual = ual->next;
continue;
}
ackcount++;
tmpual=ual->next;
if (tcpd->rev->scps_capable) {
if ((ual->nextseq - ual->seq) > tcpd->fwd->maxsizeacked) {
tcpd->fwd->maxsizeacked = (ual->nextseq - ual->seq);
}
}
if (!prevual) {
tcpd->rev->segments = tmpual;
}
else{
prevual->next = tmpual;
}
g_slice_free(tcp_unacked_t, ual);
ual = tmpual;
}
ual=tcpd->fwd->segments;
if (tcp_track_bytes_in_flight && seglen!=0 && ual && tcpd->fwd->valid_bif) {
guint32 first_seq, last_seq, in_flight;
first_seq = ual->seq - tcpd->fwd->base_seq;
last_seq = ual->nextseq - tcpd->fwd->base_seq;
while (ual) {
if ((ual->nextseq-tcpd->fwd->base_seq)>last_seq) {
last_seq = ual->nextseq-tcpd->fwd->base_seq;
}
if ((ual->seq-tcpd->fwd->base_seq)<first_seq) {
first_seq = ual->seq-tcpd->fwd->base_seq;
}
ual = ual->next;
}
in_flight = last_seq-first_seq;
if (in_flight>0 && in_flight<2000000000) {
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, TRUE, tcpd);
}
tcpd->ta->bytes_in_flight = in_flight;
}
}
}
static void
tcp_sequence_number_analysis_print_retransmission(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (ta->flags & TCP_A_RETRANSMISSION) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_retransmission,
tvb, 0, 0,
"This frame is a (suspected) "
"retransmission"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Retransmission (suspected)");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP Retransmission] ");
if (ta->rto_ts.secs || ta->rto_ts.nsecs) {
flags_item = proto_tree_add_time(flags_tree, hf_tcp_analysis_rto,
tvb, 0, 0, &ta->rto_ts);
PROTO_ITEM_SET_GENERATED(flags_item);
flags_item=proto_tree_add_uint(flags_tree, hf_tcp_analysis_rto_frame,
tvb, 0, 0, ta->rto_frame);
PROTO_ITEM_SET_GENERATED(flags_item);
}
}
if (ta->flags & TCP_A_FAST_RETRANSMISSION) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_fast_retransmission,
tvb, 0, 0,
"This frame is a (suspected) fast"
" retransmission"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Fast retransmission (suspected)");
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_retransmission,
tvb, 0, 0,
"This frame is a (suspected) "
"retransmission"
);
PROTO_ITEM_SET_GENERATED(flags_item);
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO,
"[TCP Fast Retransmission] ");
}
if (ta->flags & TCP_A_OUT_OF_ORDER) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_out_of_order,
tvb, 0, 0,
"This frame is a (suspected) "
"out-of-order segment"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_WARN,
"Out-Of-Order segment");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP Out-Of-Order] ");
}
}
static void
tcp_sequence_number_analysis_print_reused(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (ta->flags & TCP_A_REUSED_PORTS) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_reused_ports,
tvb, 0, 0,
"A new tcp session is started with the same "
"ports as an earlier session in this trace"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"TCP Port numbers reused for new session");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO,
"[TCP Port numbers reused] ");
}
}
static void
tcp_sequence_number_analysis_print_lost(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (ta->flags & TCP_A_LOST_PACKET) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_lost_packet,
tvb, 0, 0,
"A segment before this frame "
"wasn't captured"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_WARN,
"Previous segment not captured (common at capture start)");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO,
"[TCP Previous segment not captured] ");
}
if (ta->flags & TCP_A_ACK_LOST_PACKET) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_ack_lost_packet,
tvb, 0, 0,
"This frame ACKs a segment we have "
"not seen"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_WARN,
"ACKed segment that wasn't captured (common at capture start)");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO,
"[TCP ACKed unseen segment] ");
}
}
static void
tcp_sequence_number_analysis_print_window(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (ta->flags & TCP_A_WINDOW_UPDATE) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_window_update,
tvb, 0, 0,
"This is a tcp window update"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_CHAT,
"Window update");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP Window Update] ");
}
if (ta->flags & TCP_A_WINDOW_FULL) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_window_full,
tvb, 0, 0,
"The transmission window is now "
"completely full"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_WARN,
"Window is full");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP Window Full] ");
}
}
static void
tcp_sequence_number_analysis_print_keepalive(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (ta->flags & TCP_A_KEEP_ALIVE) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_keep_alive,
tvb, 0, 0,
"This is a TCP keep-alive segment"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Keep-Alive");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP Keep-Alive] ");
}
if (ta->flags & TCP_A_KEEP_ALIVE_ACK) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_keep_alive_ack,
tvb, 0, 0,
"This is an ACK to a TCP keep-alive "
"segment"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Keep-Alive ACK");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP Keep-Alive ACK] ");
}
}
static void
tcp_sequence_number_analysis_print_duplicate(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta,
proto_tree * tree
)
{
proto_item * flags_item;
if (ta->dupack_num) {
if (ta->flags & TCP_A_DUPLICATE_ACK ) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_duplicate_ack,
tvb, 0, 0,
"This is a TCP duplicate ack"
);
PROTO_ITEM_SET_GENERATED(flags_item);
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO,
"[TCP Dup ACK %u#%u] ",
ta->dupack_frame,
ta->dupack_num
);
}
flags_item=proto_tree_add_uint(tree, hf_tcp_analysis_duplicate_ack_num,
tvb, 0, 0, ta->dupack_num);
PROTO_ITEM_SET_GENERATED(flags_item);
flags_item=proto_tree_add_uint(tree, hf_tcp_analysis_duplicate_ack_frame,
tvb, 0, 0, ta->dupack_frame);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Duplicate ACK (#%u)",
ta->dupack_num
);
}
}
static void
tcp_sequence_number_analysis_print_zero_window(packet_info * pinfo,
tvbuff_t * tvb,
proto_tree * flags_tree,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (ta->flags & TCP_A_ZERO_WINDOW_PROBE) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_zero_window_probe,
tvb, 0, 0,
"This is a TCP zero-window-probe"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Zero window probe");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP ZeroWindowProbe] ");
}
if (ta->flags&TCP_A_ZERO_WINDOW) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_zero_window,
tvb, 0, 0,
"This is a ZeroWindow segment"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_WARN,
"Zero window");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO, "[TCP ZeroWindow] ");
}
if (ta->flags & TCP_A_ZERO_WINDOW_PROBE_ACK) {
flags_item=proto_tree_add_none_format(flags_tree,
hf_tcp_analysis_zero_window_probe_ack,
tvb, 0, 0,
"This is an ACK to a TCP zero-window-probe"
);
PROTO_ITEM_SET_GENERATED(flags_item);
expert_add_info_format(pinfo, flags_item, PI_SEQUENCE, PI_NOTE,
"Zero window probe ACK");
col_prepend_fence_fstr(pinfo->cinfo, COL_INFO,
"[TCP ZeroWindowProbeAck] ");
}
}
static void
tcp_sequence_number_analysis_print_bytes_in_flight(packet_info * pinfo _U_,
tvbuff_t * tvb _U_,
proto_tree * flags_tree _U_,
struct tcp_acked *ta
)
{
proto_item * flags_item;
if (tcp_track_bytes_in_flight) {
flags_item=proto_tree_add_uint(flags_tree,
hf_tcp_analysis_bytes_in_flight,
tvb, 0, 0, ta->bytes_in_flight);
PROTO_ITEM_SET_GENERATED(flags_item);
}
}
static void
tcp_print_sequence_number_analysis(packet_info *pinfo, tvbuff_t *tvb, proto_tree *parent_tree,
struct tcp_analysis *tcpd, guint32 seq, guint32 ack)
{
struct tcp_acked *ta = NULL;
proto_item *item;
proto_tree *tree;
proto_tree *flags_tree=NULL;
if (!tcpd) {
return;
}
if(!tcpd->ta) {
tcp_analyze_get_acked_struct(pinfo->fd->num, seq, ack, FALSE, tcpd);
}
ta=tcpd->ta;
if(!ta) {
return;
}
item=proto_tree_add_item(parent_tree, hf_tcp_analysis, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
tree=proto_item_add_subtree(item, ett_tcp_analysis);
if(ta->frame_acked) {
item = proto_tree_add_uint(tree, hf_tcp_analysis_acks_frame,
tvb, 0, 0, ta->frame_acked);
PROTO_ITEM_SET_GENERATED(item);
if( ta->ts.secs || ta->ts.nsecs ) {
item = proto_tree_add_time(tree, hf_tcp_analysis_ack_rtt,
tvb, 0, 0, &ta->ts);
PROTO_ITEM_SET_GENERATED(item);
}
}
if(ta->bytes_in_flight) {
tcp_sequence_number_analysis_print_bytes_in_flight(pinfo, tvb, tree, ta);
}
if(ta->flags) {
item = proto_tree_add_item(tree, hf_tcp_analysis_flags, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
flags_tree=proto_item_add_subtree(item, ett_tcp_analysis);
tcp_sequence_number_analysis_print_reused(pinfo, tvb, flags_tree, ta);
tcp_sequence_number_analysis_print_retransmission(pinfo, tvb, flags_tree, ta);
tcp_sequence_number_analysis_print_lost(pinfo, tvb, flags_tree, ta);
tcp_sequence_number_analysis_print_window(pinfo, tvb, flags_tree, ta);
tcp_sequence_number_analysis_print_keepalive(pinfo, tvb, flags_tree, ta);
tcp_sequence_number_analysis_print_duplicate(pinfo, tvb, flags_tree, ta, tree);
tcp_sequence_number_analysis_print_zero_window(pinfo, tvb, flags_tree, ta);
}
}
static void
print_tcp_fragment_tree(fragment_data *ipfd_head, proto_tree *tree, proto_tree *tcp_tree, packet_info *pinfo, tvbuff_t *next_tvb)
{
proto_item *tcp_tree_item, *frag_tree_item;
show_fragment_tree(ipfd_head, &tcp_segment_items,
tree, pinfo, next_tvb, &frag_tree_item);
tcp_tree_item = proto_tree_get_parent(tcp_tree);
if(frag_tree_item && tcp_tree_item) {
proto_tree_move_item(tree, tcp_tree_item, frag_tree_item);
}
}
static void
desegment_tcp(tvbuff_t *tvb, packet_info *pinfo, int offset,
guint32 seq, guint32 nxtseq,
guint32 sport, guint32 dport,
proto_tree *tree, proto_tree *tcp_tree,
struct tcp_analysis *tcpd)
{
struct tcpinfo *tcpinfo = (struct tcpinfo *)pinfo->private_data;
fragment_data *ipfd_head;
int last_fragment_len;
gboolean must_desegment;
gboolean called_dissector;
int another_pdu_follows;
int deseg_offset;
guint32 deseg_seq;
gint nbytes;
proto_item *item;
struct tcp_multisegment_pdu *msp;
gboolean cleared_writable = col_get_writable(pinfo->cinfo);
again:
ipfd_head = NULL;
last_fragment_len = 0;
must_desegment = FALSE;
called_dissector = FALSE;
another_pdu_follows = 0;
msp = NULL;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
deseg_offset = offset;
if (tcpd) {
if ((msp = (struct tcp_multisegment_pdu *)se_tree_lookup32(tcpd->fwd->multisegment_pdus, seq))) {
const char* str;
if (msp->first_frame == PINFO_FD_NUM(pinfo)) {
str = "";
col_set_str(pinfo->cinfo, COL_INFO, "[TCP segment of a reassembled PDU]");
} else {
str = "Retransmitted ";
}
nbytes = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_bytes_format(tcp_tree, hf_tcp_segment_data, tvb, offset,
nbytes, NULL, "%sTCP segment data (%u byte%s)", str, nbytes,
plurality(nbytes, "", "s"));
return;
}
msp = (struct tcp_multisegment_pdu *)se_tree_lookup32_le(tcpd->fwd->multisegment_pdus, seq-1);
}
if (msp && msp->seq <= seq && msp->nxtpdu > seq) {
int len;
if (!PINFO_FD_VISITED(pinfo)) {
msp->last_frame=pinfo->fd->num;
msp->last_frame_time=pinfo->fd->abs_ts;
}
if (msp->flags&MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT) {
len = tvb_length_remaining(tvb, offset);
} else {
len = MIN(nxtseq, msp->nxtpdu) - seq;
}
last_fragment_len = len;
ipfd_head = fragment_add(&tcp_reassembly_table, tvb, offset,
pinfo, msp->first_frame, NULL,
seq - msp->seq, len,
(LT_SEQ (nxtseq,msp->nxtpdu)) );
if (!PINFO_FD_VISITED(pinfo)
&& msp->flags & MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT) {
msp->flags &= (~MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT);
msp->nxtpdu = nxtseq;
}
if( (msp->nxtpdu < nxtseq)
&& (msp->nxtpdu >= seq)
&& (len > 0)) {
another_pdu_follows=msp->nxtpdu - seq;
}
} else {
tcpinfo->seq = seq;
process_tcp_payload(tvb, offset, pinfo, tree, tcp_tree,
sport, dport, 0, 0, FALSE, tcpd);
called_dissector = TRUE;
if(pinfo->desegment_len) {
if (!PINFO_FD_VISITED(pinfo))
must_desegment = TRUE;
deseg_offset = offset + pinfo->desegment_offset;
}
ipfd_head = NULL;
}
if (ipfd_head) {
if(ipfd_head->reassembled_in == pinfo->fd->num) {
tvbuff_t *next_tvb;
int old_len;
next_tvb = tvb_new_child_real_data(tvb, ipfd_head->data,
ipfd_head->datalen,
ipfd_head->datalen);
add_new_data_source(pinfo, next_tvb, "Reassembled TCP");
tcpinfo->seq = msp->seq;
tcpinfo->is_reassembled = TRUE;
process_tcp_payload(next_tvb, 0, pinfo, tree, tcp_tree, sport,
dport, 0, 0, FALSE, tcpd);
called_dissector = TRUE;
old_len = (int)(tvb_reported_length(next_tvb) - last_fragment_len);
if (pinfo->desegment_len &&
pinfo->desegment_offset<=old_len) {
fragment_set_partial_reassembly(&tcp_reassembly_table,
pinfo, msp->first_frame, NULL);
if (pinfo->desegment_len == DESEGMENT_ONE_MORE_SEGMENT) {
msp->nxtpdu = seq + tvb_reported_length_remaining(tvb, offset) + 1;
msp->flags |= MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT;
} else if (pinfo->desegment_len == DESEGMENT_UNTIL_FIN) {
tcpd->fwd->flags |= TCP_FLOW_REASSEMBLE_UNTIL_FIN;
} else {
msp->nxtpdu=seq + last_fragment_len + pinfo->desegment_len;
}
another_pdu_follows = 0;
offset += last_fragment_len;
seq += last_fragment_len;
if (tvb_length_remaining(tvb, offset) > 0)
goto again;
} else {
nbytes = another_pdu_follows > 0
? another_pdu_follows
: tvb_reported_length_remaining(tvb, offset);
proto_tree_add_bytes_format(tcp_tree, hf_tcp_segment_data, tvb, offset,
nbytes, NULL, "TCP segment data (%u byte%s)", nbytes,
plurality(nbytes, "", "s"));
print_tcp_fragment_tree(ipfd_head, tree, tcp_tree, pinfo, next_tvb);
if(pinfo->desegment_len) {
if (!PINFO_FD_VISITED(pinfo))
must_desegment = TRUE;
deseg_offset = ipfd_head->datalen - pinfo->desegment_offset;
deseg_offset = tvb_reported_length(tvb) - deseg_offset;
}
}
}
}
if (must_desegment) {
if (tcpd && pinfo->desegment_len == DESEGMENT_UNTIL_FIN) {
tcpd->fwd->flags |= TCP_FLOW_REASSEMBLE_UNTIL_FIN;
}
deseg_seq = seq + (deseg_offset - offset);
if (tcpd && ((nxtseq - deseg_seq) <= 1024*1024)
&& (!PINFO_FD_VISITED(pinfo))) {
if(pinfo->desegment_len == DESEGMENT_ONE_MORE_SEGMENT) {
msp = pdu_store_sequencenumber_of_next_pdu(pinfo, deseg_seq,
nxtseq+1, tcpd->fwd->multisegment_pdus);
msp->flags |= MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT;
} else {
msp = pdu_store_sequencenumber_of_next_pdu(pinfo,
deseg_seq, nxtseq+pinfo->desegment_len, tcpd->fwd->multisegment_pdus);
}
fragment_add(&tcp_reassembly_table, tvb, deseg_offset,
pinfo, msp->first_frame, NULL,
0, nxtseq - deseg_seq,
LT_SEQ(nxtseq, msp->nxtpdu));
}
}
if (!called_dissector || pinfo->desegment_len != 0) {
if (ipfd_head != NULL && ipfd_head->reassembled_in != 0 &&
!(ipfd_head->flags & FD_PARTIAL_REASSEMBLY)) {
item = proto_tree_add_uint(tcp_tree, hf_tcp_reassembled_in, tvb, 0,
0, ipfd_head->reassembled_in);
PROTO_ITEM_SET_GENERATED(item);
}
if (pinfo->desegment_offset == 0) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCP");
col_set_str(pinfo->cinfo, COL_INFO, "[TCP segment of a reassembled PDU]");
}
nbytes = tvb_reported_length_remaining(tvb, deseg_offset);
proto_tree_add_bytes_format(tcp_tree, hf_tcp_segment_data, tvb, deseg_offset,
-1, NULL, "TCP segment data (%u byte%s)", nbytes,
plurality(nbytes, "", "s"));
}
pinfo->can_desegment = 0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
if(another_pdu_follows) {
pinfo->can_desegment = 2;
col_set_fence(pinfo->cinfo, COL_INFO);
cleared_writable |= col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, FALSE);
offset += another_pdu_follows;
seq += another_pdu_follows;
goto again;
} else {
if(cleared_writable) {
col_set_writable(pinfo->cinfo, TRUE);
}
}
}
void
tcp_dissect_pdus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean proto_desegment, guint fixed_len,
guint (*get_pdu_len)(packet_info *, tvbuff_t *, int),
dissector_t dissect_pdu)
{
volatile int offset = 0;
int offset_before;
guint length_remaining;
guint plen;
guint length;
tvbuff_t *next_tvb;
proto_item *item=NULL;
void *pd_save;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if (proto_desegment && pinfo->can_desegment) {
if (length_remaining < fixed_len) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
plen = (*get_pdu_len)(pinfo, tvb, offset);
if (plen < fixed_len) {
show_reported_bounds_error(tvb, pinfo, tree);
return;
}
if(!pinfo->fd->flags.visited && tcp_analyze_seq) {
guint remaining_bytes;
remaining_bytes=tvb_reported_length_remaining(tvb, offset);
if(plen>remaining_bytes) {
pinfo->want_pdu_tracking=2;
pinfo->bytes_until_next_pdu=plen-remaining_bytes;
}
}
if (proto_desegment && pinfo->can_desegment) {
if (length_remaining < plen) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = plen - length_remaining;
return;
}
}
#if 0
if (length_remaining >= plen || there are more packets)
{
#endif
item=proto_tree_add_uint((proto_tree *)pinfo->tcp_tree,
hf_tcp_pdu_size,
tvb, offset, plen, plen);
PROTO_ITEM_SET_GENERATED(item);
#if 0
} else {
item = proto_tree_add_text(pinfo->tcp_tree, tvb, offset, -1,
"PDU Size: %u cut short at %u",plen,length_remaining);
PROTO_ITEM_SET_GENERATED(item);
}
#endif
length = length_remaining;
if (length > plen)
length = plen;
next_tvb = tvb_new_subset(tvb, offset, length, plen);
pd_save = pinfo->private_data;
TRY {
(*dissect_pdu)(next_tvb, pinfo, tree);
}
CATCH_NONFATAL_ERRORS {
pinfo->private_data = pd_save;
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
offset_before = offset;
offset += plen;
if (offset <= offset_before)
break;
}
}
static void
tcp_info_append_uint(packet_info *pinfo, const char *abbrev, guint32 val)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s=%u", abbrev, val);
}
static void
dissect_tcpopt_exp(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *item;
proto_tree *exp_tree;
proto_item *hidden_item;
guint16 magic;
item = proto_tree_add_item(opt_tree, hf_tcp_option_exp, tvb,
offset, optlen, ENC_NA);
exp_tree = proto_item_add_subtree(item, ett_tcp_option_exp);
proto_tree_add_item(exp_tree, hf_tcp_option_kind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exp_tree, hf_tcp_option_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
if (tcp_exp_options_with_magic && ((optlen - 2) > 0)) {
magic = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(exp_tree, hf_tcp_option_exp_magic_number, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
switch (magic) {
case 0xf989:
hidden_item = proto_tree_add_item(exp_tree, hf_tcp_option_fast_open,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if ((optlen - 2) == 2) {
proto_tree_add_item(exp_tree, hf_tcp_option_fast_open_cookie_request,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " TFO=R");
} else if ((optlen - 2) > 2) {
proto_tree_add_item(exp_tree, hf_tcp_option_fast_open_cookie,
tvb, offset + 4, optlen - 4, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " TFO=C");
}
break;
default:
break;
}
} else {
proto_tree_add_item(exp_tree, hf_tcp_option_exp_data, tvb,
offset + 2, optlen - 2, ENC_NA);
tcp_info_append_uint(pinfo, "Expxx", TRUE);
}
}
static void
dissect_tcpopt_sack_perm(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *item;
proto_tree *exp_tree;
item = proto_tree_add_boolean(opt_tree, hf_tcp_option_sack_perm, tvb, offset,
optlen, TRUE);
exp_tree = proto_item_add_subtree(item, ett_tcp_option_sack_perm);
proto_tree_add_item(exp_tree, hf_tcp_option_kind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exp_tree, hf_tcp_option_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
tcp_info_append_uint(pinfo, "SACK_PERM", TRUE);
}
static void
dissect_tcpopt_mss(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *item;
proto_tree *exp_tree;
guint16 mss;
mss = tvb_get_ntohs(tvb, offset + 2);
item = proto_tree_add_none_format(opt_tree, hf_tcp_option_mss, tvb, offset,
optlen, "%s: %u bytes", optp->name, mss);
exp_tree = proto_item_add_subtree(item, ett_tcp_option_mss);
proto_tree_add_item(exp_tree, hf_tcp_option_kind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exp_tree, hf_tcp_option_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exp_tree, hf_tcp_option_mss_val, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tcp_info_append_uint(pinfo, "MSS", mss);
}
static void
dissect_tcpopt_wscale(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen _U_, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
guint8 val, shift;
proto_item *wscale_pi, *gen_pi;
proto_tree *wscale_tree;
struct tcp_analysis *tcpd=NULL;
tcpd=get_tcp_conversation_data(NULL,pinfo);
wscale_pi = proto_tree_add_text(opt_tree, tvb, offset, 3, "Window scale: ");
wscale_tree = proto_item_add_subtree(wscale_pi, ett_tcp_option_wscale);
proto_tree_add_item(wscale_tree, hf_tcp_option_kind, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(wscale_tree, hf_tcp_option_len, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(wscale_tree, hf_tcp_option_wscale_shift, tvb, offset, 1,
ENC_NA);
shift = tvb_get_guint8(tvb, offset);
gen_pi = proto_tree_add_uint(wscale_tree, hf_tcp_option_wscale_multiplier, tvb,
offset, 1, 1 << shift);
PROTO_ITEM_SET_GENERATED(gen_pi);
val = tvb_get_guint8(tvb, offset);
proto_item_append_text(wscale_pi, "%u (multiply by %u)", val, 1 << shift);
tcp_info_append_uint(pinfo, "WS", 1 << shift);
if(!pinfo->fd->flags.visited) {
pdu_store_window_scale_option(shift, tcpd);
}
}
static void
dissect_tcpopt_sack(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data)
{
proto_tree *field_tree = NULL;
proto_item *tf=NULL;
proto_item *hidden_item;
guint32 leftedge, rightedge;
struct tcp_analysis *tcpd=NULL;
struct tcpheader *tcph = (struct tcpheader *)data;
guint32 base_ack=0;
guint num_sack_ranges = 0;
if(tcp_analyze_seq && tcp_relative_seq) {
tcpd=get_tcp_conversation_data(NULL,pinfo);
if (tcpd) {
base_ack=tcpd->rev->base_seq;
}
}
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s:", optp->name);
offset += 2;
optlen -= 2;
while (optlen > 0) {
if (field_tree == NULL) {
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
hidden_item = proto_tree_add_boolean(field_tree, hf_tcp_option_sack, tvb,
offset, optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (optlen < 4) {
proto_tree_add_text(field_tree, tvb, offset, optlen,
"(suboption would go past end of option)");
break;
}
leftedge = tvb_get_ntohl(tvb, offset)-base_ack;
proto_tree_add_uint_format(field_tree, hf_tcp_option_sack_sle, tvb,
offset, 4, leftedge,
"left edge = %u%s", leftedge,
tcp_relative_seq ? " (relative)" : "");
optlen -= 4;
if (optlen < 4) {
proto_tree_add_text(field_tree, tvb, offset, optlen,
"(suboption would go past end of option)");
break;
}
rightedge = tvb_get_ntohl(tvb, offset + 4)-base_ack;
optlen -= 4;
proto_tree_add_uint_format(field_tree, hf_tcp_option_sack_sre, tvb,
offset+4, 4, rightedge,
"right edge = %u%s", rightedge,
tcp_relative_seq ? " (relative)" : "");
tcp_info_append_uint(pinfo, "SLE", leftedge);
tcp_info_append_uint(pinfo, "SRE", rightedge);
num_sack_ranges++;
if (tcph != NULL && (tcph->num_sack_ranges < MAX_TCP_SACK_RANGES)) {
tcph->sack_left_edge[tcph->num_sack_ranges] = leftedge;
tcph->sack_right_edge[tcph->num_sack_ranges] = rightedge;
tcph->num_sack_ranges++;
}
proto_item_append_text(field_tree, " %u-%u", leftedge, rightedge);
offset += 8;
}
tf = proto_tree_add_uint(field_tree, hf_tcp_option_sack_range_count,
tvb, 0, 0, num_sack_ranges);
PROTO_ITEM_SET_GENERATED(tf);
}
static void
dissect_tcpopt_echo(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *hidden_item;
guint32 echo;
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
echo = tvb_get_ntohl(tvb, offset + 2);
hidden_item = proto_tree_add_boolean(opt_tree, hf_tcp_option_echo, tvb, offset,
optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s: %u", optp->name, echo);
tcp_info_append_uint(pinfo, "ECHO", echo);
}
static void
dissect_tcpopt_timestamp(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen _U_, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *ti;
proto_tree *ts_tree;
guint32 ts_val, ts_ecr;
ti = proto_tree_add_text(opt_tree, tvb, offset, 10, "Timestamps: ");
ts_tree = proto_item_add_subtree(ti, ett_tcp_option_timestamp);
proto_tree_add_item(ts_tree, hf_tcp_option_kind, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ts_tree, hf_tcp_option_len, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(ts_tree, hf_tcp_option_timestamp_tsval, tvb, offset,
4, ENC_BIG_ENDIAN);
ts_val = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(ts_tree, hf_tcp_option_timestamp_tsecr, tvb, offset,
4, ENC_BIG_ENDIAN);
ts_ecr = tvb_get_ntohl(tvb, offset);
proto_item_append_text(ti, "TSval %u, TSecr %u", ts_val, ts_ecr);
if (tcp_ignore_timestamps == FALSE) {
tcp_info_append_uint(pinfo, "TSval", ts_val);
tcp_info_append_uint(pinfo, "TSecr", ts_ecr);
}
}
static void
dissect_tcpopt_mptcp(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo _U_, proto_tree *opt_tree, void *data _U_)
{
proto_item *ti;
proto_tree *mptcp_tree;
proto_tree *mptcp_flags_tree;
guint8 subtype;
guint8 indx;
guint8 flags;
guint8 ipver;
ti = proto_tree_add_text(opt_tree, tvb, offset, optlen, "Multipath TCP");
mptcp_tree = proto_item_add_subtree(ti, ett_tcp_option_mptcp);
proto_tree_add_item(mptcp_tree, hf_tcp_option_kind, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mptcp_tree, hf_tcp_option_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mptcp_tree, hf_tcp_option_mptcp_subtype, tvb,
offset, 1, ENC_BIG_ENDIAN);
subtype = tvb_get_guint8(tvb, offset) >> 4;
proto_item_append_text(ti, ": %s", val_to_str(subtype, mptcp_subtype_vs, "Unknown (%d)"));
switch (subtype) {
case TCPOPT_MPTCP_MP_CAPABLE:
proto_tree_add_item(mptcp_tree, hf_tcp_option_mptcp_version, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
flags = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint(mptcp_tree, hf_tcp_option_mptcp_flags, tvb,
offset, 1, flags);
mptcp_flags_tree = proto_item_add_subtree(ti, ett_tcp_option_mptcp);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_C_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_S_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (optlen == 12 || optlen == 20) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_sender_key, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if (optlen == 20) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_recv_key, tvb, offset, 8, ENC_BIG_ENDIAN);
}
break;
case TCPOPT_MPTCP_MP_JOIN:
switch (optlen) {
case 12:
flags = tvb_get_guint8(tvb, offset) & 0x01;
ti = proto_tree_add_uint(mptcp_tree,
hf_tcp_option_mptcp_flags, tvb,
offset, 1, flags);
mptcp_flags_tree = proto_item_add_subtree(ti,
ett_tcp_option_mptcp);
proto_tree_add_item(mptcp_flags_tree,
hf_tcp_option_mptcp_B_flag, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_address_id, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_recv_token, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_sender_rand, tvb, offset,
4, ENC_BIG_ENDIAN);
break;
case 16:
flags = tvb_get_guint8(tvb, offset) & 0x01;
ti = proto_tree_add_uint(mptcp_tree,
hf_tcp_option_mptcp_flags, tvb,
offset, 1, flags);
mptcp_flags_tree = proto_item_add_subtree(ti,
ett_tcp_option_mptcp);
proto_tree_add_item(mptcp_flags_tree,
hf_tcp_option_mptcp_B_flag, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_address_id, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_sender_trunc_mac, tvb, offset,
8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_sender_rand, tvb, offset,
4, ENC_BIG_ENDIAN);
break;
case 24:
offset += 2;
for (indx = 0; indx < 5; indx++) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_sender_mac, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
default:
break;
}
break;
case TCPOPT_MPTCP_DSS:
offset += 1;
flags = tvb_get_guint8(tvb, offset) & 0x1F;
ti = proto_tree_add_uint(mptcp_tree, hf_tcp_option_mptcp_flags, tvb,
offset, 1, flags);
mptcp_flags_tree = proto_item_add_subtree(ti, ett_tcp_option_mptcp);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_F_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_m_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_M_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_a_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_A_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (flags & 1) {
if (flags & 2) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_data_ack, tvb, offset,
8, ENC_BIG_ENDIAN);
offset += 8;
} else {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_data_ack, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
}
if (flags & 4) {
if (flags & 8) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_data_seq_no, tvb, offset,
8, ENC_BIG_ENDIAN);
offset += 8;
} else {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_data_seq_no, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_subflow_seq_no, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_data_lvl_len, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_checksum, tvb, offset,
2, ENC_BIG_ENDIAN);
}
break;
case TCPOPT_MPTCP_ADD_ADDR:
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_ipver, tvb, offset, 1, ENC_BIG_ENDIAN);
ipver = tvb_get_guint8(tvb, offset) & 0x0F;
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_address_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (ipver) {
case 4:
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 6:
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
break;
default:
break;
}
if (optlen % 4 == 2) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
}
break;
case TCPOPT_MPTCP_REMOVE_ADDR:
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_address_id, tvb, offset,
1, ENC_BIG_ENDIAN);
break;
case TCPOPT_MPTCP_MP_PRIO:
flags = tvb_get_guint8(tvb, offset) & 0x01;
ti = proto_tree_add_uint(mptcp_tree, hf_tcp_option_mptcp_flags, tvb,
offset, 1, flags);
mptcp_flags_tree = proto_item_add_subtree(ti, ett_tcp_option_mptcp);
proto_tree_add_item(mptcp_flags_tree, hf_tcp_option_mptcp_B_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (optlen == 4) {
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_address_id, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case TCPOPT_MPTCP_MP_FAIL:
offset += 1;
offset += 1;
proto_tree_add_item(mptcp_tree,
hf_tcp_option_mptcp_data_seq_no, tvb, offset, 8, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static void
dissect_tcpopt_cc(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *hidden_item;
guint32 cc;
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
cc = tvb_get_ntohl(tvb, offset + 2);
hidden_item = proto_tree_add_boolean(opt_tree, hf_tcp_option_cc, tvb, offset,
optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s: %u", optp->name, cc);
tcp_info_append_uint(pinfo, "CC", cc);
}
static void
dissect_tcpopt_qs(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *hidden_item;
guint8 rate = tvb_get_guint8(tvb, offset + 2) & 0x0f;
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_boolean(opt_tree, hf_tcp_option_qs, tvb, offset,
optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s: Rate response, %s, TTL diff %u ", optp->name,
val_to_str_ext_const(rate, &qs_rate_vals_ext, "Unknown"),
tvb_get_guint8(tvb, offset + 3));
col_append_fstr(pinfo->cinfo, COL_INFO, " QSresp=%s", val_to_str_ext_const(rate, &qs_rate_vals_ext, "Unknown"));
}
static void
dissect_tcpopt_scps(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo,
proto_tree *opt_tree, void *data _U_)
{
struct tcp_analysis *tcpd;
proto_tree *field_tree = NULL;
tcp_flow_t *flow;
int direction;
proto_item *tf = NULL, *hidden_item;
guint8 capvector;
guint8 connid;
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
tcpd = get_tcp_conversation_data(NULL,pinfo);
direction=CMP_ADDRESS(&pinfo->src, &pinfo->dst);
if(direction==0) {
direction= (pinfo->srcport > pinfo->destport) ? 1 : -1;
}
if(direction>=0)
flow =&(tcpd->flow1);
else
flow =&(tcpd->flow2);
if (optlen == 4) {
hidden_item = proto_tree_add_boolean(opt_tree, hf_tcp_option_scps,
tvb, offset, optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
capvector = tvb_get_guint8(tvb, offset + 2);
connid = tvb_get_guint8(tvb, offset + 3);
tf = proto_tree_add_item(opt_tree, hf_tcp_option_scps_vector, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_tcp_option_scps);
proto_tree_add_item(field_tree, hf_tcp_scpsoption_flags_bets, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_scpsoption_flags_snack1, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_scpsoption_flags_snack2, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_scpsoption_flags_compress, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_scpsoption_flags_nlts, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_scpsoption_flags_reserved, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
if (capvector) {
struct capvec
{
guint8 mask;
const gchar *str;
} capvecs[] = {
{0x80, "BETS"},
{0x40, "SNACK1"},
{0x20, "SNACK2"},
{0x10, "COMP"},
{0x08, "NLTS"},
{0x07, "RESERVED"}
};
gboolean anyflag = FALSE;
guint i;
col_append_str(pinfo->cinfo, COL_INFO, " SCPS[");
for (i = 0; i < sizeof(capvecs)/sizeof(struct capvec); i++) {
if (capvector & capvecs[i].mask) {
proto_item_append_text(tf, "%s%s", anyflag ? ", " : " (",
capvecs[i].str);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s",
anyflag ? ", " : "", capvecs[i].str);
anyflag = TRUE;
}
}
col_append_str(pinfo->cinfo, COL_INFO, "]");
proto_item_append_text(tf, ")");
}
proto_tree_add_item(field_tree, hf_tcp_scpsoption_connection_id, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
flow->scps_capable = 1;
if (connid)
tcp_info_append_uint(pinfo, "Connection ID", connid);
} else {
guint8 local_offset = 2;
guint8 binding_space;
guint8 extended_cap_length;
if (flow->scps_capable != 1) {
proto_tree_add_uint_format(opt_tree, hf_tcp_option_scps_vector,
tvb, offset, optlen, 0,
"Illegal SCPS Extended Capabilities (%d bytes)",
optlen);
} else {
tf = proto_tree_add_uint_format(opt_tree, hf_tcp_option_scps_vector,
tvb, offset, optlen, 0,
"SCPS Extended Capabilities (%d bytes)",
optlen);
field_tree=proto_item_add_subtree(tf, ett_tcp_option_scps_extended);
while (optlen > local_offset) {
binding_space = tvb_get_guint8(tvb, (offset + local_offset));
extended_cap_length =
(tvb_get_guint8(tvb, (offset + local_offset + 1)) >> 4);
extended_cap_length = (extended_cap_length << 1);
proto_tree_add_item(field_tree, hf_tcp_option_scps_binding, tvb, offset + local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(field_tree, hf_tcp_option_scps_binding_len, tvb, offset + local_offset + 1, 1, extended_cap_length);
local_offset += 2;
proto_tree_add_text(field_tree, tvb, offset + local_offset,
extended_cap_length,
"Binding Space Data (%u bytes)",
extended_cap_length);
tcp_info_append_uint(pinfo, "EXCAP", binding_space);
local_offset += extended_cap_length;
}
}
}
}
static void
dissect_tcpopt_user_to(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo, proto_tree *opt_tree, void *data _U_)
{
proto_item *hidden_item, *tf;
proto_tree *field_tree;
gboolean g;
guint16 to;
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
g = tvb_get_ntohs(tvb, offset + 2) & 0x8000;
to = tvb_get_ntohs(tvb, offset + 2) & 0x7FFF;
hidden_item = proto_tree_add_boolean(opt_tree, hf_tcp_option_user_to, tvb, offset,
optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
tf = proto_tree_add_uint_format(opt_tree, hf_tcp_option_user_to_val, tvb, offset,
optlen, to, "%s: %u %s", optp->name, to, g ? "minutes" : "seconds");
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
proto_tree_add_item(field_tree, hf_tcp_option_user_to_granularity, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_option_user_to_val, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
tcp_info_append_uint(pinfo, "USER_TO", to);
}
static void
verify_scps(packet_info *pinfo, proto_item *tf_syn, struct tcp_analysis *tcpd)
{
tf_syn = 0x0;
if(tcpd) {
if ((!(tcpd->flow1.scps_capable)) || (!(tcpd->flow2.scps_capable))) {
tcpd->flow1.scps_capable = 0;
tcpd->flow2.scps_capable = 0;
} else {
expert_add_info_format(pinfo, tf_syn, PI_SEQUENCE, PI_NOTE,
"Connection establish request (SYN-ACK): SCPS Capabilities Negotiated");
}
}
}
static void
dissect_tcpopt_snack(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo,
proto_tree *opt_tree, void *data _U_)
{
struct tcp_analysis *tcpd=NULL;
guint16 relative_hole_offset;
guint16 relative_hole_size;
guint16 base_mss = 0;
guint32 ack;
guint32 hole_start;
guint32 hole_end;
char null_modifier[] = "\0";
char relative_modifier[] = "(relative)";
char *modifier = null_modifier;
proto_item *hidden_item;
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(opt_tree, hf_tcp_option_len, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
tcpd = get_tcp_conversation_data(NULL,pinfo);
relative_hole_offset = tvb_get_ntohs(tvb, offset + 2);
relative_hole_size = tvb_get_ntohs(tvb, offset + 4);
hidden_item = proto_tree_add_boolean(opt_tree, hf_tcp_option_snack, tvb,
offset, optlen, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(opt_tree, hf_tcp_option_snack_offset,
tvb, offset, optlen, relative_hole_offset);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(opt_tree, hf_tcp_option_snack_size,
tvb, offset, optlen, relative_hole_size);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s: Offset %u, Size %u", optp->name,
relative_hole_offset, relative_hole_size);
ack = tvb_get_ntohl(tvb, 8);
if (tcp_relative_seq) {
ack -= tcpd->rev->base_seq;
modifier = relative_modifier;
}
base_mss = tcpd->fwd->maxsizeacked;
if (base_mss) {
hole_start = ack + (base_mss * relative_hole_offset);
hole_end = hole_start + (base_mss * relative_hole_size);
hidden_item = proto_tree_add_uint(opt_tree, hf_tcp_option_snack_le,
tvb, offset, optlen, hole_start);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(opt_tree, hf_tcp_option_snack_re,
tvb, offset, optlen, hole_end);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(opt_tree, tvb, offset, optlen,
"\tMissing Sequence %u - %u %s",
hole_start, hole_end, modifier);
tcp_info_append_uint(pinfo, "SNLE", hole_start);
tcp_info_append_uint(pinfo, "SNRE", hole_end);
expert_add_info_format(pinfo, NULL, PI_SEQUENCE, PI_NOTE,
"SNACK Sequence %u - %u %s",
hole_start, hole_end, modifier);
}
}
static void
rvbd_probe_decode_version_type(const guint8 vt, guint8 *ver, guint8 *type)
{
if (vt & PROBE_VERSION_MASK) {
*ver = PROBE_VERSION_1;
*type = vt >> 4;
} else {
*ver = PROBE_VERSION_2;
*type = vt >> 1;
}
}
static void
rvbd_probe_resp_add_info(proto_item *pitem, packet_info *pinfo, guint32 ip, guint16 port)
{
proto_item_append_text(pitem, ", Server Steelhead: %s:%u", ip_to_str((guint8 *)&ip), port);
col_prepend_fstr(pinfo->cinfo, COL_INFO, "SA+, ");
}
static void
dissect_tcpopt_rvbd_probe(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree,
void *data _U_)
{
guint8 ver, type;
proto_tree *field_tree;
proto_item *pitem;
rvbd_probe_decode_version_type(
tvb_get_guint8(tvb, offset + PROBE_VERSION_TYPE_OFFSET),
&ver, &type);
pitem = proto_tree_add_boolean_format_value(
opt_tree, hf_tcp_option_rvbd_probe, tvb, offset, optlen, 1,
"%s", val_to_str_const(type, rvbd_probe_type_vs, "Probe Unknown"));
if (type >= PROBE_TYPE_MAX)
return;
field_tree = proto_item_add_subtree(pitem, ett_tcp_opt_rvbd_probe);
pitem = proto_tree_add_item(field_tree, hf_tcp_option_len, tvb,
offset + PROBE_OPTLEN_OFFSET, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(pitem);
pitem = proto_tree_add_item(field_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(pitem);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_optlen, tvb,
offset + PROBE_OPTLEN_OFFSET, 1, ENC_BIG_ENDIAN);
if (ver == PROBE_VERSION_1) {
guint32 ip;
guint16 port;
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_type1, tvb,
offset + PROBE_VERSION_TYPE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_version1, tvb,
offset + PROBE_VERSION_TYPE_OFFSET, 1, ENC_BIG_ENDIAN);
if (type == PROBE_INTERNAL)
return;
proto_tree_add_text(field_tree, tvb, offset + PROBE_V1_RESERVED_OFFSET,
1, "Reserved");
ip = tvb_get_ipv4(tvb, offset + PROBE_V1_PROBER_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_prober, tvb,
offset + PROBE_V1_PROBER_OFFSET, 4, ENC_BIG_ENDIAN);
switch (type) {
case PROBE_QUERY:
case PROBE_QUERY_SH:
case PROBE_TRACE:
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_appli_ver, tvb,
offset + PROBE_V1_APPLI_VERSION_OFFSET, 2,
ENC_BIG_ENDIAN);
proto_item_append_text(pitem, ", CSH IP: %s", ip_to_str((guint8 *)&ip));
if (check_col(pinfo->cinfo, COL_INFO)) {
#define PROBE_V1_QUERY_LEN 10
const guint8 qinfo_hdr[] = { 0x4c, 0x04, 0x0c };
int not_cfe = 0;
if (tvb_memeql(tvb, offset + PROBE_V1_QUERY_LEN,
qinfo_hdr, sizeof(qinfo_hdr)) == 0) {
not_cfe = tvb_get_guint8(tvb, offset + PROBE_V1_QUERY_LEN +
(int)sizeof(qinfo_hdr)) & RVBD_FLAGS_PROBE_NCFE;
}
col_prepend_fstr(pinfo->cinfo, COL_INFO, "S%s, ",
type == PROBE_TRACE ? "#" :
not_cfe ? "+*" : "+");
}
break;
case PROBE_RESPONSE:
ip = tvb_get_ipv4(tvb, offset + PROBE_V1_PROXY_ADDR_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_proxy, tvb,
offset + PROBE_V1_PROXY_ADDR_OFFSET, 4, ENC_BIG_ENDIAN);
port = tvb_get_ntohs(tvb, offset + PROBE_V1_PROXY_PORT_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_proxy_port, tvb,
offset + PROBE_V1_PROXY_PORT_OFFSET, 2, ENC_BIG_ENDIAN);
rvbd_probe_resp_add_info(pitem, pinfo, ip, port);
break;
case PROBE_RESPONSE_SH:
proto_tree_add_item(field_tree,
hf_tcp_option_rvbd_probe_client, tvb,
offset + PROBE_V1_SH_CLIENT_ADDR_OFFSET, 4,
ENC_BIG_ENDIAN);
ip = tvb_get_ipv4(tvb, offset + PROBE_V1_SH_PROXY_ADDR_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_proxy, tvb,
offset + PROBE_V1_SH_PROXY_ADDR_OFFSET, 4, ENC_BIG_ENDIAN);
port = tvb_get_ntohs(tvb, offset + PROBE_V1_SH_PROXY_PORT_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_proxy_port, tvb,
offset + PROBE_V1_SH_PROXY_PORT_OFFSET, 2, ENC_BIG_ENDIAN);
rvbd_probe_resp_add_info(pitem, pinfo, ip, port);
break;
}
}
else if (ver == PROBE_VERSION_2) {
proto_item *ver_pi;
proto_item *flag_pi;
proto_tree *flag_tree;
guint8 flags;
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_type2, tvb,
offset + PROBE_VERSION_TYPE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(
field_tree, hf_tcp_option_rvbd_probe_version2, tvb,
offset + PROBE_VERSION_TYPE_OFFSET, 1, ver, "%u", ver);
ver_pi = proto_tree_add_uint(field_tree, hf_tcp_option_rvbd_probe_version1, tvb,
offset + PROBE_VERSION_TYPE_OFFSET, 1, ver);
PROTO_ITEM_SET_HIDDEN(ver_pi);
switch (type) {
case PROBE_QUERY_INFO:
case PROBE_QUERY_INFO_SH:
case PROBE_QUERY_INFO_SID:
flags = tvb_get_guint8(tvb, offset + PROBE_V2_INFO_OFFSET);
flag_pi = proto_tree_add_uint(field_tree, hf_tcp_option_rvbd_probe_flags,
tvb, offset + PROBE_V2_INFO_OFFSET,
1, flags);
flag_tree = proto_item_add_subtree(flag_pi, ett_tcp_opt_rvbd_probe_flags);
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_flag_not_cfe,
tvb, offset + PROBE_V2_INFO_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_flag_last_notify,
tvb, offset + PROBE_V2_INFO_OFFSET, 1, ENC_BIG_ENDIAN);
if (type == PROBE_QUERY_INFO_SH)
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_client, tvb,
offset + PROBE_V2_INFO_CLIENT_ADDR_OFFSET,
4, ENC_BIG_ENDIAN);
else if (type == PROBE_QUERY_INFO_SID)
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_storeid, tvb,
offset + PROBE_V2_INFO_STOREID_OFFSET,
4, ENC_BIG_ENDIAN);
if (type != PROBE_QUERY_INFO_SID &&
check_col(pinfo->cinfo, COL_INFO) &&
(tvb_get_guint8(tvb, 13) & (TH_SYN|TH_ACK)) == (TH_SYN|TH_ACK) &&
(flags & RVBD_FLAGS_PROBE_LAST)) {
col_prepend_fstr(pinfo->cinfo, COL_INFO, "SA++, ");
}
break;
case PROBE_RESPONSE_INFO:
flag_pi = proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_flags,
tvb, offset + PROBE_V2_INFO_OFFSET,
1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(flag_pi, ett_tcp_opt_rvbd_probe_flags);
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_flag_probe_cache,
tvb, offset + PROBE_V2_INFO_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_flag_sslcert,
tvb, offset + PROBE_V2_INFO_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree,
hf_tcp_option_rvbd_probe_flag_server_connected,
tvb, offset + PROBE_V2_INFO_OFFSET, 1, ENC_BIG_ENDIAN);
break;
case PROBE_RST:
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_flags,
tvb, offset + PROBE_V2_INFO_OFFSET,
1, ENC_BIG_ENDIAN);
break;
}
}
}
static void
dissect_tcpopt_rvbd_trpy(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo,
proto_tree *opt_tree, void *data _U_)
{
proto_tree *field_tree;
proto_tree *flag_tree;
proto_item *pitem;
proto_item *flag_pi;
guint32 src, dst;
guint16 sport, dport, flags;
col_prepend_fstr(pinfo->cinfo, COL_INFO, "TRPY, ");
pitem = proto_tree_add_boolean_format_value(
opt_tree, hf_tcp_option_rvbd_trpy, tvb, offset, optlen, 1,
"%s", "");
field_tree = proto_item_add_subtree(pitem, ett_tcp_opt_rvbd_trpy);
pitem = proto_tree_add_item(field_tree, hf_tcp_option_len, tvb,
offset + PROBE_OPTLEN_OFFSET, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(pitem);
pitem = proto_tree_add_item(field_tree, hf_tcp_option_kind, tvb,
offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(pitem);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_probe_optlen, tvb,
offset + PROBE_OPTLEN_OFFSET, 1, ENC_BIG_ENDIAN);
flags = tvb_get_ntohs(tvb, offset + TRPY_OPTIONS_OFFSET);
flag_pi = proto_tree_add_item(field_tree, hf_tcp_option_rvbd_trpy_flags,
tvb, offset + TRPY_OPTIONS_OFFSET,
2, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(flag_pi, ett_tcp_opt_rvbd_trpy_flags);
proto_tree_add_item(flag_tree, hf_tcp_option_rvbd_trpy_flag_fw_rst_probe,
tvb, offset + TRPY_OPTIONS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_tcp_option_rvbd_trpy_flag_fw_rst_inner,
tvb, offset + TRPY_OPTIONS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_tcp_option_rvbd_trpy_flag_fw_rst,
tvb, offset + TRPY_OPTIONS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_tcp_option_rvbd_trpy_flag_chksum,
tvb, offset + TRPY_OPTIONS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_tcp_option_rvbd_trpy_flag_oob,
tvb, offset + TRPY_OPTIONS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_tcp_option_rvbd_trpy_flag_mode,
tvb, offset + TRPY_OPTIONS_OFFSET, 2, ENC_BIG_ENDIAN);
src = tvb_get_ipv4(tvb, offset + TRPY_SRC_ADDR_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_trpy_src,
tvb, offset + TRPY_SRC_ADDR_OFFSET, 4, ENC_BIG_ENDIAN);
dst = tvb_get_ipv4(tvb, offset + TRPY_DST_ADDR_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_trpy_dst,
tvb, offset + TRPY_DST_ADDR_OFFSET, 4, ENC_BIG_ENDIAN);
sport = tvb_get_ntohs(tvb, offset + TRPY_SRC_PORT_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_trpy_src_port,
tvb, offset + TRPY_SRC_PORT_OFFSET, 2, ENC_BIG_ENDIAN);
dport = tvb_get_ntohs(tvb, offset + TRPY_DST_PORT_OFFSET);
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_trpy_dst_port,
tvb, offset + TRPY_DST_PORT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, "%s:%u -> %s:%u",
ip_to_str((guint8 *)&src), sport,
ip_to_str((guint8 *)&dst), dport);
if ((flags & RVBD_FLAGS_TRPY_OOB) && (optlen > TCPOLEN_RVBD_TRPY_MIN))
proto_tree_add_item(field_tree, hf_tcp_option_rvbd_trpy_client_port,
tvb, offset + TRPY_CLIENT_PORT_OFFSET, 2, ENC_BIG_ENDIAN);
if (sport_handle != NULL) {
conversation_t *conversation;
conversation = find_conversation(pinfo->fd->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
}
if (conversation->dissector_handle != sport_handle) {
conversation_set_dissector(conversation, sport_handle);
}
} else if (data_handle != NULL) {
conversation_t *conversation;
conversation = find_conversation(pinfo->fd->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
}
if (conversation->dissector_handle != data_handle) {
conversation_set_dissector(conversation, data_handle);
}
}
}
gboolean
decode_tcp_ports(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int src_port, int dst_port,
struct tcp_analysis *tcpd)
{
tvbuff_t *next_tvb;
int low_port, high_port;
int save_desegment_offset;
guint32 save_desegment_len;
if(tcpd && tcpd->ta) {
if(tcpd->ta->flags&TCP_A_KEEP_ALIVE) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
return TRUE;
}
}
if (tcp_no_subdissector_on_error && tcpd && tcpd->ta && tcpd->ta->flags & (TCP_A_RETRANSMISSION | TCP_A_OUT_OF_ORDER)) {
return FALSE;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_conversation_dissector(&pinfo->src, &pinfo->dst, PT_TCP,
src_port, dst_port, next_tvb, pinfo, tree)) {
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return TRUE;
}
if (try_heuristic_first) {
save_desegment_offset = pinfo->desegment_offset;
save_desegment_len = pinfo->desegment_len;
if (dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, tree, NULL)) {
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return TRUE;
}
DISSECTOR_ASSERT(save_desegment_offset == pinfo->desegment_offset &&
save_desegment_len == pinfo->desegment_len);
}
if (tcpd && tcpd->server_port != 0 &&
dissector_try_uint(subdissector_table, tcpd->server_port, next_tvb, pinfo, tree)) {
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return TRUE;
}
if (src_port > dst_port) {
low_port = dst_port;
high_port = src_port;
} else {
low_port = src_port;
high_port = dst_port;
}
if (low_port != 0 &&
dissector_try_uint(subdissector_table, low_port, next_tvb, pinfo, tree)) {
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return TRUE;
}
if (high_port != 0 &&
dissector_try_uint(subdissector_table, high_port, next_tvb, pinfo, tree)) {
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return TRUE;
}
if (!try_heuristic_first) {
save_desegment_offset = pinfo->desegment_offset;
save_desegment_len = pinfo->desegment_len;
if (dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, tree, NULL)) {
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return TRUE;
}
DISSECTOR_ASSERT(save_desegment_offset == pinfo->desegment_offset &&
save_desegment_len == pinfo->desegment_len);
}
call_dissector(data_handle,next_tvb, pinfo, tree);
pinfo->want_pdu_tracking -= !!(pinfo->want_pdu_tracking);
return FALSE;
}
static void
process_tcp_payload(tvbuff_t *tvb, volatile int offset, packet_info *pinfo,
proto_tree *tree, proto_tree *tcp_tree, int src_port, int dst_port,
guint32 seq, guint32 nxtseq, gboolean is_tcp_segment,
struct tcp_analysis *tcpd)
{
pinfo->want_pdu_tracking=0;
TRY {
if(is_tcp_segment) {
if(tcpd && tcp_analyze_seq && (!tcp_desegment)) {
if(seq || nxtseq) {
offset=scan_for_next_pdu(tvb, tcp_tree, pinfo, offset,
seq, nxtseq, tcpd->fwd->multisegment_pdus);
}
}
}
if( (offset!=-1) &&
decode_tcp_ports(tvb, offset, pinfo, tree, src_port,
dst_port, tcpd) ) {
if(is_tcp_segment) {
if(tcpd && (!pinfo->fd->flags.visited) &&
tcp_analyze_seq && pinfo->want_pdu_tracking) {
if(seq || nxtseq) {
pdu_store_sequencenumber_of_next_pdu(
pinfo,
seq,
nxtseq+pinfo->bytes_until_next_pdu,
tcpd->fwd->multisegment_pdus);
}
}
}
}
}
CATCH_ALL {
if(is_tcp_segment) {
if(tcpd && (!pinfo->fd->flags.visited) && tcp_analyze_seq && pinfo->want_pdu_tracking) {
if(seq || nxtseq) {
pdu_store_sequencenumber_of_next_pdu(pinfo,
seq,
nxtseq+pinfo->bytes_until_next_pdu,
tcpd->fwd->multisegment_pdus);
}
}
}
RETHROW;
}
ENDTRY;
}
void
dissect_tcp_payload(tvbuff_t *tvb, packet_info *pinfo, int offset, guint32 seq,
guint32 nxtseq, guint32 sport, guint32 dport,
proto_tree *tree, proto_tree *tcp_tree,
struct tcp_analysis *tcpd)
{
gboolean save_fragmented;
if (pinfo->can_desegment) {
desegment_tcp(tvb, pinfo, offset, seq, nxtseq, sport, dport, tree,
tcp_tree, tcpd);
} else {
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
process_tcp_payload(tvb, offset, pinfo, tree, tcp_tree, sport, dport,
seq, nxtseq, TRUE, tcpd);
pinfo->fragmented = save_fragmented;
}
}
static void
dissect_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 th_off_x2;
guint16 th_sum;
guint32 ack;
guint16 th_urp;
proto_tree *tcp_tree = NULL, *field_tree = NULL;
proto_item *ti = NULL, *tf, *hidden_item;
int offset = 0;
emem_strbuf_t *flags_strbuf = ep_strbuf_new_label("<None>");
const gchar *flags[] = {"FIN", "SYN", "RST", "PSH", "ACK", "URG", "ECN", "CWR", "NS"};
gint i;
guint bpos;
guint optlen;
guint32 nxtseq = 0;
guint reported_len;
vec_t cksum_vec[4];
guint32 phdr[2];
guint16 computed_cksum;
guint16 real_window;
guint length_remaining;
gboolean desegment_ok;
struct tcpinfo tcpinfo;
struct tcpheader *tcph;
proto_item *tf_syn = NULL, *tf_fin = NULL, *tf_rst = NULL, *scaled_pi;
conversation_t *conv=NULL;
struct tcp_analysis *tcpd=NULL;
struct tcp_per_packet_data_t *tcppd=NULL;
proto_item *item;
proto_tree *checksum_tree;
tcph=ep_new(struct tcpheader);
SET_ADDRESS(&tcph->ip_src, pinfo->src.type, pinfo->src.len, pinfo->src.data);
SET_ADDRESS(&tcph->ip_dst, pinfo->dst.type, pinfo->dst.len, pinfo->dst.data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCP");
col_clear(pinfo->cinfo, COL_INFO);
tcph->th_sport = tvb_get_ntohs(tvb, offset);
tcph->th_dport = tvb_get_ntohs(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s > %s",
get_tcp_port(tcph->th_sport), get_tcp_port(tcph->th_dport));
if (tree) {
if (tcp_summary_in_tree) {
ti = proto_tree_add_protocol_format(tree, proto_tcp, tvb, 0, -1,
"Transmission Control Protocol, Src Port: %s (%u), Dst Port: %s (%u)",
get_tcp_port(tcph->th_sport), tcph->th_sport,
get_tcp_port(tcph->th_dport), tcph->th_dport);
}
else {
ti = proto_tree_add_item(tree, proto_tcp, tvb, 0, -1, ENC_NA);
}
tcp_tree = proto_item_add_subtree(ti, ett_tcp);
pinfo->tcp_tree=tcp_tree;
proto_tree_add_uint_format(tcp_tree, hf_tcp_srcport, tvb, offset, 2, tcph->th_sport,
"Source port: %s (%u)", get_tcp_port(tcph->th_sport), tcph->th_sport);
proto_tree_add_uint_format(tcp_tree, hf_tcp_dstport, tvb, offset + 2, 2, tcph->th_dport,
"Destination port: %s (%u)", get_tcp_port(tcph->th_dport), tcph->th_dport);
hidden_item = proto_tree_add_uint(tcp_tree, hf_tcp_port, tvb, offset, 2, tcph->th_sport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(tcp_tree, hf_tcp_port, tvb, offset + 2, 2, tcph->th_dport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (pinfo->layer_names != NULL && pinfo->layer_names->str != NULL) {
if (strstr(pinfo->layer_names->str, "icmp:ip") != NULL)
proto_tree_add_item(tcp_tree, hf_tcp_seq, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
}
}
pinfo->ptype = PT_TCP;
pinfo->srcport = tcph->th_sport;
pinfo->destport = tcph->th_dport;
tcph->th_seq = tvb_get_ntohl(tvb, offset + 4);
tcph->th_ack = tvb_get_ntohl(tvb, offset + 8);
th_off_x2 = tvb_get_guint8(tvb, offset + 12);
tcph->th_flags = tvb_get_ntohs(tvb, offset + 12) & 0x0FFF;
tcph->th_win = tvb_get_ntohs(tvb, offset + 14);
real_window = tcph->th_win;
tcph->th_hlen = hi_nibble(th_off_x2) * 4;
conv=find_or_create_conversation(pinfo);
tcpd=get_tcp_conversation_data(conv,pinfo);
if(tcpd && ((tcph->th_flags&(TH_SYN|TH_ACK))==TH_SYN) &&
(tcpd->fwd->base_seq!=0) &&
(tcph->th_seq!=tcpd->fwd->base_seq) ) {
if (!(pinfo->fd->flags.visited)) {
conv=conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
tcpd=get_tcp_conversation_data(conv,pinfo);
}
if(!tcpd->ta)
tcp_analyze_get_acked_struct(pinfo->fd->num, tcph->th_seq, tcph->th_ack, TRUE, tcpd);
tcpd->ta->flags|=TCP_A_REUSED_PORTS;
}
if (tcpd) {
item = proto_tree_add_uint(tcp_tree, hf_tcp_stream, tvb, offset, 0, tcpd->stream);
PROTO_ITEM_SET_GENERATED(item);
tcph->th_stream = tcpd->stream;
}
if (tcp_calculate_ts) {
tcppd = (struct tcp_per_packet_data_t *)p_get_proto_data(pinfo->fd, proto_tcp, 0);
if (!(pinfo->fd->flags.visited))
tcp_calculate_timestamps(pinfo, tcpd, tcppd);
}
reported_len = tvb_reported_length(tvb);
if (!pinfo->fragmented && !pinfo->flags.in_error_pkt) {
if (reported_len < tcph->th_hlen) {
proto_item *pi;
pi = proto_tree_add_text(tcp_tree, tvb, offset, 0,
"Short segment. Segment/fragment does not contain a full TCP header"
" (might be NMAP or someone else deliberately sending unusual packets)");
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_WARN, "Short segment");
tcph->th_have_seglen = FALSE;
} else {
tcph->th_seglen = reported_len - tcph->th_hlen;
tcph->th_have_seglen = TRUE;
if (tree) {
hidden_item = proto_tree_add_uint(ti, hf_tcp_len, tvb, offset+12, 1, tcph->th_seglen);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if(tcp_analyze_seq) {
if(!(pinfo->fd->flags.visited)) {
tcp_analyze_sequence_number(pinfo, tcph->th_seq, tcph->th_ack, tcph->th_seglen, tcph->th_flags, tcph->th_win, tcpd);
}
if(tcpd && tcp_relative_seq) {
(tcph->th_seq) -= tcpd->fwd->base_seq;
(tcph->th_ack) -= tcpd->rev->base_seq;
}
}
if (!(tcph->th_flags&TH_SYN)) {
if (tcpd && (tcpd->fwd->win_scale>=0)) {
(tcph->th_win)<<=tcpd->fwd->win_scale;
}
else {
if (tcp_default_window_scaling>=0) {
(tcph->th_win)<<=tcp_default_window_scaling;
}
}
}
nxtseq = tcph->th_seq + tcph->th_seglen;
}
} else
tcph->th_have_seglen = FALSE;
if (check_col(pinfo->cinfo, COL_INFO) || tree) {
gboolean first_flag = TRUE;
for (i = 0; i < 9; i++) {
bpos = 1 << i;
if (tcph->th_flags & bpos) {
if (first_flag) {
ep_strbuf_truncate(flags_strbuf, 0);
}
ep_strbuf_append_printf(flags_strbuf, "%s%s", first_flag ? "" : ", ", flags[i]);
first_flag = FALSE;
}
}
if (tcph->th_flags & 0x0E00) {
if (first_flag) {
ep_strbuf_truncate(flags_strbuf, 0);
}
ep_strbuf_append_printf(flags_strbuf, "%sReserved", first_flag ? "" : ", ");
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s] Seq=%u", flags_strbuf->str, tcph->th_seq);
if (tcph->th_flags&TH_ACK) {
col_append_fstr(pinfo->cinfo, COL_INFO, " Ack=%u", tcph->th_ack);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " Win=%u", tcph->th_win);
if (tree) {
if (tcp_summary_in_tree) {
proto_item_append_text(ti, ", Seq: %u", tcph->th_seq);
}
if(tcp_relative_seq) {
proto_tree_add_uint_format(tcp_tree, hf_tcp_seq, tvb, offset + 4, 4, tcph->th_seq, "Sequence number: %u (relative sequence number)", tcph->th_seq);
} else {
proto_tree_add_uint(tcp_tree, hf_tcp_seq, tvb, offset + 4, 4, tcph->th_seq);
}
}
if (tcph->th_hlen < TCPH_MIN_LEN) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", bogus TCP header length (%u, must be at least %u)",
tcph->th_hlen, TCPH_MIN_LEN);
if (tree) {
proto_tree_add_uint_format(tcp_tree, hf_tcp_hdr_len, tvb, offset + 12, 1, tcph->th_hlen,
"Header length: %u bytes (bogus, must be at least %u)", tcph->th_hlen,
TCPH_MIN_LEN);
}
return;
}
if (tree) {
if (tcp_summary_in_tree) {
if(tcph->th_flags&TH_ACK) {
proto_item_append_text(ti, ", Ack: %u", tcph->th_ack);
}
if (tcph->th_have_seglen)
proto_item_append_text(ti, ", Len: %u", tcph->th_seglen);
}
proto_item_set_len(ti, tcph->th_hlen);
if (tcph->th_have_seglen) {
if (nxtseq != tcph->th_seq) {
if(tcp_relative_seq) {
tf=proto_tree_add_uint_format(tcp_tree, hf_tcp_nxtseq, tvb, offset, 0, nxtseq, "Next sequence number: %u (relative sequence number)", nxtseq);
} else {
tf=proto_tree_add_uint(tcp_tree, hf_tcp_nxtseq, tvb, offset, 0, nxtseq);
}
PROTO_ITEM_SET_GENERATED(tf);
}
}
}
if (tcph->th_flags & TH_ACK) {
if (tree) {
if (tcp_relative_seq) {
proto_tree_add_uint_format(tcp_tree, hf_tcp_ack, tvb, offset + 8, 4, tcph->th_ack, "Acknowledgment number: %u (relative ack number)", tcph->th_ack);
} else {
proto_tree_add_uint(tcp_tree, hf_tcp_ack, tvb, offset + 8, 4, tcph->th_ack);
}
}
} else {
ack = tvb_get_ntohl(tvb, offset+8);
if (ack != 0) {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_ack, tvb, offset + 8, 4, ack,
"Acknowledgment Number: 0x%08x [should be 0x00000000 because ACK flag is not set]",
ack);
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN,
"Acknowledgment number: Broken TCP. The acknowledge field is nonzero while the ACK flag is not set");
}
}
if (tree) {
proto_tree_add_uint_format(tcp_tree, hf_tcp_hdr_len, tvb, offset + 12, 1, tcph->th_hlen,
"Header length: %u bytes", tcph->th_hlen);
tf = proto_tree_add_uint_format(tcp_tree, hf_tcp_flags, tvb, offset + 12, 2,
tcph->th_flags, "Flags: 0x%03x (%s)", tcph->th_flags, flags_strbuf->str);
field_tree = proto_item_add_subtree(tf, ett_tcp_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_res, tvb, offset + 12, 1, tcph->th_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_ns, tvb, offset + 12, 1, tcph->th_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_cwr, tvb, offset + 13, 1, tcph->th_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_ecn, tvb, offset + 13, 1, tcph->th_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_urg, tvb, offset + 13, 1, tcph->th_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_ack, tvb, offset + 13, 1, tcph->th_flags);
proto_tree_add_boolean(field_tree, hf_tcp_flags_push, tvb, offset + 13, 1, tcph->th_flags);
tf_rst = proto_tree_add_boolean(field_tree, hf_tcp_flags_reset, tvb, offset + 13, 1, tcph->th_flags);
tf_syn = proto_tree_add_boolean(field_tree, hf_tcp_flags_syn, tvb, offset + 13, 1, tcph->th_flags);
tf_fin = proto_tree_add_boolean(field_tree, hf_tcp_flags_fin, tvb, offset + 13, 1, tcph->th_flags);
proto_tree_add_uint(tcp_tree, hf_tcp_window_size_value, tvb, offset + 14, 2, real_window);
scaled_pi = proto_tree_add_uint(tcp_tree, hf_tcp_window_size, tvb, offset + 14, 2, tcph->th_win);
PROTO_ITEM_SET_GENERATED(scaled_pi);
if( !(tcph->th_flags&TH_SYN) && tcpd ) {
switch (tcpd->fwd->win_scale) {
case -1:
{
gint16 win_scale = tcpd->fwd->win_scale;
gboolean override_with_pref = FALSE;
if (tcp_default_window_scaling != WindowScaling_NotKnown) {
win_scale = tcp_default_window_scaling;
override_with_pref = TRUE;
}
scaled_pi = proto_tree_add_int_format(tcp_tree, hf_tcp_window_size_scalefactor, tvb, offset + 14, 2,
win_scale, "Window size scaling factor: %d (%s)",
win_scale,
(override_with_pref) ? "missing - taken from preference" : "unknown");
PROTO_ITEM_SET_GENERATED(scaled_pi);
}
break;
case -2:
scaled_pi = proto_tree_add_int_format(tcp_tree, hf_tcp_window_size_scalefactor, tvb, offset + 14, 2, tcpd->fwd->win_scale, "Window size scaling factor: %d (no window scaling used)", tcpd->fwd->win_scale);
PROTO_ITEM_SET_GENERATED(scaled_pi);
break;
default:
scaled_pi = proto_tree_add_int_format(tcp_tree, hf_tcp_window_size_scalefactor, tvb, offset + 14, 2, 1<<tcpd->fwd->win_scale, "Window size scaling factor: %d", 1<<tcpd->fwd->win_scale);
PROTO_ITEM_SET_GENERATED(scaled_pi);
}
}
}
if(tcph->th_flags & TH_SYN) {
if(tcph->th_flags & TH_ACK) {
expert_add_info_format(pinfo, tf_syn, PI_SEQUENCE, PI_CHAT, "Connection establish acknowledge (SYN+ACK): server port %s",
get_tcp_port(tcph->th_sport));
tcpd->server_port = tcph->th_sport;
}
else {
expert_add_info_format(pinfo, tf_syn, PI_SEQUENCE, PI_CHAT, "Connection establish request (SYN): server port %s",
get_tcp_port(tcph->th_dport));
tcpd->server_port = tcph->th_dport;
}
}
if(tcph->th_flags & TH_FIN)
expert_add_info_format(pinfo, tf_fin, PI_SEQUENCE, PI_CHAT, "Connection finish (FIN)");
if(tcph->th_flags & TH_RST)
expert_add_info_format(pinfo, tf_rst, PI_SEQUENCE, PI_CHAT, "Connection reset (RST)");
tcpinfo.seq = tcph->th_seq;
tcpinfo.nxtseq = nxtseq;
tcpinfo.lastackseq = tcph->th_ack;
tcpinfo.is_reassembled = FALSE;
pinfo->private_data = &tcpinfo;
pinfo->can_desegment = 0;
th_sum = tvb_get_ntohs(tvb, offset + 16);
if (!pinfo->fragmented && tvb_bytes_exist(tvb, 0, reported_len)) {
if (tcp_check_checksum) {
cksum_vec[0].ptr = (guint8 *)pinfo->src.data;
cksum_vec[0].len = pinfo->src.len;
cksum_vec[1].ptr = (guint8 *)pinfo->dst.data;
cksum_vec[1].len = pinfo->dst.len;
cksum_vec[2].ptr = (const guint8 *)phdr;
switch (pinfo->src.type) {
case AT_IPv4:
phdr[0] = g_htonl((IP_PROTO_TCP<<16) + reported_len);
cksum_vec[2].len = 4;
break;
case AT_IPv6:
phdr[0] = g_htonl(reported_len);
phdr[1] = g_htonl(IP_PROTO_TCP);
cksum_vec[2].len = 8;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
cksum_vec[3].ptr = tvb_get_ptr(tvb, offset, reported_len);
cksum_vec[3].len = reported_len;
computed_cksum = in_cksum(cksum_vec, 4);
if (computed_cksum == 0 && th_sum == 0xffff) {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_checksum, tvb,
offset + 16, 2, th_sum,
"Checksum: 0x%04x [should be 0x0000 (see RFC 1624)]", th_sum);
checksum_tree = proto_item_add_subtree(item, ett_tcp_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_good, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_bad, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info_format(pinfo, item, PI_CHECKSUM, PI_WARN, "TCP Checksum 0xffff instead of 0x0000 (see RFC 1624)");
col_append_str(pinfo->cinfo, COL_INFO, " [TCP CHECKSUM 0xFFFF]");
desegment_ok = TRUE;
} else if (computed_cksum == 0) {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_checksum, tvb,
offset + 16, 2, th_sum, "Checksum: 0x%04x [correct]", th_sum);
checksum_tree = proto_item_add_subtree(item, ett_tcp_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_good, tvb,
offset + 16, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_bad, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
desegment_ok = TRUE;
} else {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_checksum, tvb,
offset + 16, 2, th_sum,
"Checksum: 0x%04x [incorrect, should be 0x%04x (maybe caused by \"TCP checksum offload\"?)]", th_sum,
in_cksum_shouldbe(th_sum, computed_cksum));
checksum_tree = proto_item_add_subtree(item, ett_tcp_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_good, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_bad, tvb,
offset + 16, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info_format(pinfo, item, PI_CHECKSUM, PI_ERROR, "Bad checksum");
col_append_str(pinfo->cinfo, COL_INFO, " [TCP CHECKSUM INCORRECT]");
desegment_ok = FALSE;
pinfo->noreassembly_reason = " [incorrect TCP checksum]";
}
} else {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_checksum, tvb,
offset + 16, 2, th_sum, "Checksum: 0x%04x [validation disabled]", th_sum);
checksum_tree = proto_item_add_subtree(item, ett_tcp_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_good, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_bad, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
desegment_ok = TRUE;
}
} else {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_checksum, tvb,
offset + 16, 2, th_sum, "Checksum: 0x%04x [unchecked, not all data available]", th_sum);
checksum_tree = proto_item_add_subtree(item, ett_tcp_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_good, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_tcp_checksum_bad, tvb,
offset + 16, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
desegment_ok = FALSE;
}
if (desegment_ok) {
if (tcp_desegment) {
if (!pinfo->flags.in_error_pkt) {
pinfo->can_desegment = 2;
}
}
}
th_urp = tvb_get_ntohs(tvb, offset + 18);
if (tcph->th_flags & TH_URG) {
tcpinfo.urgent = TRUE;
tcpinfo.urgent_pointer = th_urp;
col_append_fstr(pinfo->cinfo, COL_INFO, " Urg=%u", th_urp);
if (tcp_tree != NULL)
proto_tree_add_uint(tcp_tree, hf_tcp_urgent_pointer, tvb, offset + 18, 2, th_urp);
} else {
tcpinfo.urgent = FALSE;
if (th_urp) {
item = proto_tree_add_uint_format(tcp_tree, hf_tcp_urgent_pointer, tvb, offset + 18, 2, th_urp,
"Urgent Pointer: 0x%04x [should be 0x0000 because URG flag is not set]",
th_urp);
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN,
"Urgent Pointer: Broken TCP. The urgent pointer field is nonzero while the URG flag is not set");
}
}
if (tcph->th_have_seglen) {
col_append_fstr(pinfo->cinfo, COL_INFO, " Len=%u", tcph->th_seglen);
}
tcph->num_sack_ranges = 0;
if (tcph->th_hlen > TCPH_MIN_LEN) {
optlen = tcph->th_hlen - TCPH_MIN_LEN;
tvb_ensure_bytes_exist(tvb, offset + 20, optlen);
if (tcp_tree != NULL) {
guint8 *p_options = (guint8 *)ep_tvb_memdup(tvb, offset + 20, optlen);
tf = proto_tree_add_bytes_format(tcp_tree, hf_tcp_options, tvb, offset + 20,
optlen, p_options, "Options: (%u bytes)", optlen);
field_tree = proto_item_add_subtree(tf, ett_tcp_options);
} else {
tf = NULL;
field_tree = NULL;
}
dissect_ip_tcp_options(tvb, offset + 20, optlen,
tcpopts, N_TCP_OPTS, TCPOPT_EOL, pinfo, field_tree, tf, tcph);
}
if(!pinfo->fd->flags.visited) {
if((tcph->th_flags & TH_SYN)==TH_SYN) {
verify_tcp_window_scaling((tcph->th_flags&TH_ACK)==TH_ACK,tcpd);
}
if((tcph->th_flags & (TH_SYN|TH_ACK))==(TH_SYN|TH_ACK)) {
if(tcpd && ((tcpd->rev->scps_capable) || (tcpd->fwd->scps_capable))) {
verify_scps(pinfo, tf_syn, tcpd);
}
}
}
offset += tcph->th_hlen;
length_remaining = tvb_length_remaining(tvb, offset);
if (tcph->th_have_seglen) {
if( data_out_file ) {
reassemble_tcp( tcpd->stream,
tcph->th_seq,
tcph->th_ack,
tcph->th_seglen,
(gchar*)tvb_get_ptr(tvb, offset, length_remaining),
length_remaining,
( tcph->th_flags & TH_SYN ),
&pinfo->net_src,
&pinfo->net_dst,
pinfo->srcport,
pinfo->destport);
}
}
if(tcp_analyze_seq) {
guint32 use_seq = tcph->th_seq;
guint32 use_ack = tcph->th_ack;
if (tcp_relative_seq) {
use_seq += tcpd->fwd->base_seq;
use_ack += tcpd->rev->base_seq;
}
tcp_print_sequence_number_analysis(pinfo, tvb, tcp_tree, tcpd, use_seq, use_ack);
}
if(tcp_calculate_ts) {
tcp_print_timestamps(pinfo, tvb, tcp_tree, tcpd, tcppd);
}
tap_queue_packet(tcp_tap, pinfo, tcph);
if(tcph->th_have_seglen && tcpd && (tcph->th_flags & TH_FIN)
&& (tcpd->fwd->flags&TCP_FLOW_REASSEMBLE_UNTIL_FIN) ) {
struct tcp_multisegment_pdu *msp;
if (tcpd->fwd->fin == 0 || tcpd->fwd->fin == pinfo->fd->num) {
tcpd->fwd->fin = pinfo->fd->num;
msp=(struct tcp_multisegment_pdu *)se_tree_lookup32_le(tcpd->fwd->multisegment_pdus, tcph->th_seq-1);
if(msp) {
fragment_data *ipfd_head;
ipfd_head = fragment_add(&tcp_reassembly_table, tvb, offset,
pinfo, msp->first_frame, NULL,
tcph->th_seq - msp->seq,
tcph->th_seglen,
FALSE );
if(ipfd_head) {
tvbuff_t *next_tvb;
next_tvb = tvb_new_child_real_data(tvb, ipfd_head->data, ipfd_head->datalen, ipfd_head->datalen);
add_new_data_source(pinfo, next_tvb, "Reassembled TCP");
print_tcp_fragment_tree(ipfd_head, tree, tcp_tree, pinfo, next_tvb);
pinfo->can_desegment = 0;
process_tcp_payload(next_tvb, 0, pinfo, tree, tcp_tree, tcph->th_sport, tcph->th_dport, tcph->th_seq, nxtseq, FALSE, tcpd);
return;
}
}
} else {
proto_tree_add_text(tcp_tree, tvb, 0, 0, "Retransmission of FIN from frame %u",
tcpd->fwd->fin);
}
}
if (tcpd && ((tcpd->fwd && tcpd->fwd->command) || (tcpd->rev && tcpd->rev->command))) {
ti = proto_tree_add_text(tcp_tree, tvb, offset, 0, "Process Information");
PROTO_ITEM_SET_GENERATED(ti);
field_tree = proto_item_add_subtree(ti, ett_tcp_process_info);
if (tcpd->fwd && tcpd->fwd->command) {
proto_tree_add_uint_format_value(field_tree, hf_tcp_proc_dst_uid, tvb, 0, 0,
tcpd->fwd->process_uid, "%u", tcpd->fwd->process_uid);
proto_tree_add_uint_format_value(field_tree, hf_tcp_proc_dst_pid, tvb, 0, 0,
tcpd->fwd->process_pid, "%u", tcpd->fwd->process_pid);
proto_tree_add_string_format_value(field_tree, hf_tcp_proc_dst_uname, tvb, 0, 0,
tcpd->fwd->username, "%s", tcpd->fwd->username);
proto_tree_add_string_format_value(field_tree, hf_tcp_proc_dst_cmd, tvb, 0, 0,
tcpd->fwd->command, "%s", tcpd->fwd->command);
}
if (tcpd->rev && tcpd->rev->command) {
proto_tree_add_uint_format_value(field_tree, hf_tcp_proc_src_uid, tvb, 0, 0,
tcpd->rev->process_uid, "%u", tcpd->rev->process_uid);
proto_tree_add_uint_format_value(field_tree, hf_tcp_proc_src_pid, tvb, 0, 0,
tcpd->rev->process_pid, "%u", tcpd->rev->process_pid);
proto_tree_add_string_format_value(field_tree, hf_tcp_proc_src_uname, tvb, 0, 0,
tcpd->rev->username, "%s", tcpd->rev->username);
proto_tree_add_string_format_value(field_tree, hf_tcp_proc_src_cmd, tvb, 0, 0,
tcpd->rev->command, "%s", tcpd->rev->command);
}
}
if (length_remaining != 0) {
if (tcph->th_flags & TH_RST) {
proto_tree_add_text(tcp_tree, tvb, offset, length_remaining,
"Reset cause: %s",
tvb_format_text(tvb, offset, length_remaining));
} else {
dissect_tcp_payload(tvb, pinfo, offset, tcph->th_seq, nxtseq,
tcph->th_sport, tcph->th_dport, tree, tcp_tree, tcpd);
}
}
}
static void
tcp_init(void)
{
tcp_stream_index = 0;
reassembly_table_init(&tcp_reassembly_table,
&addresses_ports_reassembly_table_functions);
}
void
proto_register_tcp(void)
{
static hf_register_info hf[] = {
{ &hf_tcp_srcport,
{ "Source Port", "tcp.srcport", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_dstport,
{ "Destination Port", "tcp.dstport", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_port,
{ "Source or Destination Port", "tcp.port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_stream,
{ "Stream index", "tcp.stream", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_seq,
{ "Sequence number", "tcp.seq", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_nxtseq,
{ "Next sequence number", "tcp.nxtseq", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_ack,
{ "Acknowledgment number", "tcp.ack", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_hdr_len,
{ "Header Length", "tcp.hdr_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_flags,
{ "Flags", "tcp.flags", FT_UINT16, BASE_HEX, NULL, TH_MASK,
NULL, HFILL }},
{ &hf_tcp_flags_res,
{ "Reserved", "tcp.flags.res", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_RES,
"Three reserved bits (must be zero)", HFILL }},
{ &hf_tcp_flags_ns,
{ "Nonce", "tcp.flags.ns", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_NS,
"ECN concealment protection (RFC 3540)", HFILL }},
{ &hf_tcp_flags_cwr,
{ "Congestion Window Reduced (CWR)", "tcp.flags.cwr", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_CWR,
NULL, HFILL }},
{ &hf_tcp_flags_ecn,
{ "ECN-Echo", "tcp.flags.ecn", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_ECN,
NULL, HFILL }},
{ &hf_tcp_flags_urg,
{ "Urgent", "tcp.flags.urg", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_URG,
NULL, HFILL }},
{ &hf_tcp_flags_ack,
{ "Acknowledgment", "tcp.flags.ack", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_ACK,
NULL, HFILL }},
{ &hf_tcp_flags_push,
{ "Push", "tcp.flags.push", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_PUSH,
NULL, HFILL }},
{ &hf_tcp_flags_reset,
{ "Reset", "tcp.flags.reset", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_RST,
NULL, HFILL }},
{ &hf_tcp_flags_syn,
{ "Syn", "tcp.flags.syn", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_SYN,
NULL, HFILL }},
{ &hf_tcp_flags_fin,
{ "Fin", "tcp.flags.fin", FT_BOOLEAN, 12, TFS(&tfs_set_notset), TH_FIN,
NULL, HFILL }},
{ &hf_tcp_window_size_value,
{ "Window size value", "tcp.window_size_value", FT_UINT16, BASE_DEC, NULL, 0x0,
"The window size value from the TCP header", HFILL }},
{ &hf_tcp_window_size,
{ "Calculated window size", "tcp.window_size", FT_UINT32, BASE_DEC, NULL, 0x0,
"The scaled window size (if scaling has been used)", HFILL }},
{ &hf_tcp_window_size_scalefactor,
{ "Window size scaling factor", "tcp.window_size_scalefactor", FT_INT32, BASE_DEC, NULL, 0x0,
"The window size scaling factor (-1 when unknown, -2 when no scaling is used)", HFILL }},
{ &hf_tcp_checksum,
{ "Checksum", "tcp.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
"Details at: http://www.wireshark.org/docs/wsug_html_chunked/ChAdvChecksums.html", HFILL }},
{ &hf_tcp_checksum_good,
{ "Good Checksum", "tcp.checksum_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_tcp_checksum_bad,
{ "Bad Checksum", "tcp.checksum_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content or not checked", HFILL }},
{ &hf_tcp_analysis,
{ "SEQ/ACK analysis", "tcp.analysis", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame has some of the TCP analysis shown", HFILL }},
{ &hf_tcp_analysis_flags,
{ "TCP Analysis Flags", "tcp.analysis.flags", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame has some of the TCP analysis flags set", HFILL }},
{ &hf_tcp_analysis_retransmission,
{ "Retransmission", "tcp.analysis.retransmission", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame is a suspected TCP retransmission", HFILL }},
{ &hf_tcp_analysis_fast_retransmission,
{ "Fast Retransmission", "tcp.analysis.fast_retransmission", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame is a suspected TCP fast retransmission", HFILL }},
{ &hf_tcp_analysis_out_of_order,
{ "Out Of Order", "tcp.analysis.out_of_order", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame is a suspected Out-Of-Order segment", HFILL }},
{ &hf_tcp_analysis_reused_ports,
{ "TCP Port numbers reused", "tcp.analysis.reused_ports", FT_NONE, BASE_NONE, NULL, 0x0,
"A new tcp session has started with previously used port numbers", HFILL }},
{ &hf_tcp_analysis_lost_packet,
{ "Previous Segment Unseen", "tcp.analysis.lost_segment", FT_NONE, BASE_NONE, NULL, 0x0,
"We may not have captured a segment before this one", HFILL }},
{ &hf_tcp_analysis_ack_lost_packet,
{ "ACKed Unseen Packet", "tcp.analysis.ack_lost_segment", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame ACKs a segment that may not have been captured", HFILL }},
{ &hf_tcp_analysis_window_update,
{ "Window update", "tcp.analysis.window_update", FT_NONE, BASE_NONE, NULL, 0x0,
"This frame is a tcp window update", HFILL }},
{ &hf_tcp_analysis_window_full,
{ "Window full", "tcp.analysis.window_full", FT_NONE, BASE_NONE, NULL, 0x0,
"This segment has caused the allowed window to become 100% full", HFILL }},
{ &hf_tcp_analysis_keep_alive,
{ "Keep Alive", "tcp.analysis.keep_alive", FT_NONE, BASE_NONE, NULL, 0x0,
"This is a keep-alive segment", HFILL }},
{ &hf_tcp_analysis_keep_alive_ack,
{ "Keep Alive ACK", "tcp.analysis.keep_alive_ack", FT_NONE, BASE_NONE, NULL, 0x0,
"This is an ACK to a keep-alive segment", HFILL }},
{ &hf_tcp_analysis_duplicate_ack,
{ "Duplicate ACK", "tcp.analysis.duplicate_ack", FT_NONE, BASE_NONE, NULL, 0x0,
"This is a duplicate ACK", HFILL }},
{ &hf_tcp_analysis_duplicate_ack_num,
{ "Duplicate ACK #", "tcp.analysis.duplicate_ack_num", FT_UINT32, BASE_DEC, NULL, 0x0,
"This is duplicate ACK number #", HFILL }},
{ &hf_tcp_analysis_duplicate_ack_frame,
{ "Duplicate to the ACK in frame", "tcp.analysis.duplicate_ack_frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a duplicate to the ACK in frame #", HFILL }},
{ &hf_tcp_continuation_to,
{ "This is a continuation to the PDU in frame", "tcp.continuation_to", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a continuation to the PDU in frame #", HFILL }},
{ &hf_tcp_analysis_zero_window_probe,
{ "Zero Window Probe", "tcp.analysis.zero_window_probe", FT_NONE, BASE_NONE, NULL, 0x0,
"This is a zero-window-probe", HFILL }},
{ &hf_tcp_analysis_zero_window_probe_ack,
{ "Zero Window Probe Ack", "tcp.analysis.zero_window_probe_ack", FT_NONE, BASE_NONE, NULL, 0x0,
"This is an ACK to a zero-window-probe", HFILL }},
{ &hf_tcp_analysis_zero_window,
{ "Zero Window", "tcp.analysis.zero_window", FT_NONE, BASE_NONE, NULL, 0x0,
"This is a zero-window", HFILL }},
{ &hf_tcp_len,
{ "TCP Segment Len", "tcp.len", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_analysis_acks_frame,
{ "This is an ACK to the segment in frame", "tcp.analysis.acks_frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Which previous segment is this an ACK for", HFILL}},
{ &hf_tcp_analysis_bytes_in_flight,
{ "Bytes in flight", "tcp.analysis.bytes_in_flight", FT_UINT32, BASE_DEC, NULL, 0x0,
"How many bytes are now in flight for this connection", HFILL}},
{ &hf_tcp_analysis_ack_rtt,
{ "The RTT to ACK the segment was", "tcp.analysis.ack_rtt", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"How long time it took to ACK the segment (RTT)", HFILL}},
{ &hf_tcp_analysis_rto,
{ "The RTO for this segment was", "tcp.analysis.rto", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"How long transmission was delayed before this segment was retransmitted (RTO)", HFILL}},
{ &hf_tcp_analysis_rto_frame,
{ "RTO based on delta from frame", "tcp.analysis.rto_frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is the frame we measure the RTO from", HFILL }},
{ &hf_tcp_urgent_pointer,
{ "Urgent pointer", "tcp.urgent_pointer", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_segment_overlap,
{ "Segment overlap", "tcp.segment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment overlaps with other segments", HFILL }},
{ &hf_tcp_segment_overlap_conflict,
{ "Conflicting data in segment overlap", "tcp.segment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping segments contained conflicting data", HFILL }},
{ &hf_tcp_segment_multiple_tails,
{ "Multiple tail segments found", "tcp.segment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when reassembling the pdu", HFILL }},
{ &hf_tcp_segment_too_long_fragment,
{ "Segment too long", "tcp.segment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of the pdu", HFILL }},
{ &hf_tcp_segment_error,
{ "Reassembling error", "tcp.segment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Reassembling error due to illegal segments", HFILL }},
{ &hf_tcp_segment_count,
{ "Segment count", "tcp.segment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_segment,
{ "TCP Segment", "tcp.segment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tcp_segments,
{ "Reassembled TCP Segments", "tcp.segments", FT_NONE, BASE_NONE, NULL, 0x0,
"TCP Segments", HFILL }},
{ &hf_tcp_reassembled_in,
{ "Reassembled PDU in frame", "tcp.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The PDU that doesn't end in this segment is reassembled in this frame", HFILL }},
{ &hf_tcp_reassembled_length,
{ "Reassembled TCP length", "tcp.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_tcp_reassembled_data,
{ "Reassembled TCP Data", "tcp.reassembled.data", FT_BYTES, BASE_NONE, NULL, 0x0,
"The reassembled payload", HFILL }},
{ &hf_tcp_option_kind,
{ "Kind", "tcp.option_kind", FT_UINT8,
BASE_DEC, VALS(tcp_option_kind_vs), 0x0, "This TCP option's kind", HFILL }},
{ &hf_tcp_option_len,
{ "Length", "tcp.option_len", FT_UINT8,
BASE_DEC, NULL, 0x0, "Length of this TCP option in bytes (including kind and length fields)", HFILL }},
{ &hf_tcp_options,
{ "TCP Options", "tcp.options", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_mss,
{ "TCP MSS Option", "tcp.options.mss", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_mss_val,
{ "MSS Value", "tcp.options.mss_val", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_wscale_shift,
{ "Shift count", "tcp.options.wscale.shift", FT_UINT8,
BASE_DEC, NULL, 0x0, "Logarithmically encoded power of 2 scale factor", HFILL}},
{ &hf_tcp_option_wscale_multiplier,
{ "Multiplier", "tcp.options.wscale.multiplier", FT_UINT8,
BASE_DEC, NULL, 0x0, "Multiply segment window size by this for scaled window size", HFILL}},
{ &hf_tcp_option_exp,
{ "TCP Option - Experimental", "tcp.options.experimental", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_exp_data,
{ "Data", "tcp.options.experimental.data", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_exp_magic_number,
{ "Magic Number", "tcp.options.experimental.magic_number", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_sack_perm,
{ "TCP SACK Permitted Option", "tcp.options.sack_perm",
FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_sack,
{ "TCP SACK Option", "tcp.options.sack", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_sack_sle,
{"TCP SACK Left Edge", "tcp.options.sack_le", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_sack_sre,
{"TCP SACK Right Edge", "tcp.options.sack_re", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_sack_range_count,
{ "TCP SACK Count", "tcp.options.sack.count", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_echo,
{ "TCP Echo Option", "tcp.options.echo", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "TCP Sack Echo", HFILL}},
{ &hf_tcp_option_timestamp_tsval,
{ "Timestamp value", "tcp.options.timestamp.tsval", FT_UINT32,
BASE_DEC, NULL, 0x0, "Value of sending machine's timestamp clock", HFILL}},
{ &hf_tcp_option_timestamp_tsecr,
{ "Timestamp echo reply", "tcp.options.timestamp.tsecr", FT_UINT32,
BASE_DEC, NULL, 0x0, "Echoed timestamp from remote machine", HFILL}},
{ &hf_tcp_option_mptcp_subtype,
{ "Multipath TCP subtype", "tcp.options.mptcp.subtype", FT_UINT8,
BASE_DEC, VALS(mptcp_subtype_vs), 0xF0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_version,
{ "Multipath TCP version", "tcp.options.mptcp.version", FT_UINT8,
BASE_DEC, NULL, 0x0F, NULL, HFILL}},
{ &hf_tcp_option_mptcp_flags,
{ "Multipath TCP flags", "tcp.options.mptcp.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_B_flag,
{ "Backup flag", "tcp.options.mptcp.backup.flag", FT_UINT8,
BASE_DEC, NULL, 0x01, NULL, HFILL}},
{ &hf_tcp_option_mptcp_C_flag,
{ "Checksum required", "tcp.options.mptcp.checksumreq.flags", FT_UINT8,
BASE_DEC, NULL, 0x80, NULL, HFILL}},
{ &hf_tcp_option_mptcp_S_flag,
{ "Use HMAC-SHA1", "tcp.options.mptcp.sha1.flag", FT_UINT8,
BASE_DEC, NULL, 0x01, NULL, HFILL}},
{ &hf_tcp_option_mptcp_F_flag,
{ "DATA_FIN", "tcp.options.mptcp.datafin.flag", FT_UINT8,
BASE_DEC, NULL, 0x10, NULL, HFILL}},
{ &hf_tcp_option_mptcp_m_flag,
{ "Data Sequence Number is 8 octets", "tcp.options.mptcp.dseqn8.flag", FT_UINT8,
BASE_DEC, NULL, 0x08, NULL, HFILL}},
{ &hf_tcp_option_mptcp_M_flag,
{ "Data Sequence Number, Subflow Sequence Number, Data-level Length, Checksum present", "tcp.options.mptcp.dseqnpresent.flag", FT_UINT8,
BASE_DEC, NULL, 0x04, NULL, HFILL}},
{ &hf_tcp_option_mptcp_a_flag,
{ "Data ACK is 8 octets", "tcp.options.mptcp.dataack8.flag", FT_UINT8,
BASE_DEC, NULL, 0x02, NULL, HFILL}},
{ &hf_tcp_option_mptcp_A_flag,
{ "Data ACK is present", "tcp.options.mptcp.dataackpresent.flag", FT_UINT8,
BASE_DEC, NULL, 0x01, NULL, HFILL}},
{ &hf_tcp_option_mptcp_address_id,
{ "Multipath TCP Address ID", "tcp.options.mptcp.addrid", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_sender_key,
{ "Multipath TCP Sender's Key", "tcp.options.mptcp.sendkey", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_recv_key,
{ "Multipath TCP Receiver's Key", "tcp.options.mptcp.recvkey", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_recv_token,
{ "Multipath TCP Receiver's Token", "tcp.options.mptcp.recvtok", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_sender_rand,
{ "Multipath TCP Sender's Random Number", "tcp.options.mptcp.sendrand", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_sender_trunc_mac,
{ "Multipath TCP Sender's Truncated MAC", "tcp.options.mptcp.sendtruncmac", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_sender_mac,
{ "Multipath TCP Sender's MAC", "tcp.options.mptcp.sendmac", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_data_ack,
{ "Multipath TCP Data ACK", "tcp.options.mptcp.dataack", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_data_seq_no,
{ "Multipath TCP Data Sequence Number", "tcp.options.mptcp.dataseqno", FT_UINT64,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_subflow_seq_no,
{ "Multipath TCP Subflow Sequence Number", "tcp.options.mptcp.subflowseqno", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_data_lvl_len,
{ "Multipath TCP Data-level Length", "tcp.options.mptcp.datalvllen", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_checksum,
{ "Multipath TCP Checksum", "tcp.options.mptcp.checksum", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_ipver,
{ "Multipath TCP IPVer", "tcp.options.mptcp.ipver", FT_UINT8,
BASE_DEC, NULL, 0x0F, NULL, HFILL}},
{ &hf_tcp_option_mptcp_ipv4,
{ "Multipath TCP Address", "tcp.options.mptcp.ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_ipv6,
{ "Multipath TCP Address", "tcp.options.mptcp.ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_mptcp_port,
{ "Multipath TCP Port", "tcp.options.mptcp.port", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_cc,
{ "TCP CC Option", "tcp.options.cc", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_qs,
{ "TCP QS Option", "tcp.options.qs", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_option_scps,
{ "TCP SCPS Capabilities Option", "tcp.options.scps",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_option_scps_vector,
{ "TCP SCPS Capabilities Vector", "tcp.options.scps.vector",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_option_scps_binding,
{ "Binding Space (Community) ID",
"tcp.options.scps.binding.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"TCP SCPS Extended Binding Space (Community) ID", HFILL}},
{ &hf_tcp_option_scps_binding_len,
{ "Extended Capability Length",
"tcp.options.scps.binding.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"TCP SCPS Extended Capability Length in bytes", HFILL}},
{ &hf_tcp_option_snack,
{ "TCP Selective Negative Acknowledgment Option",
"tcp.options.snack",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_option_snack_offset,
{ "TCP SNACK Offset", "tcp.options.snack.offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_option_snack_size,
{ "TCP SNACK Size", "tcp.options.snack.size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_option_snack_le,
{ "TCP SNACK Left Edge", "tcp.options.snack.le",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_option_snack_re,
{ "TCP SNACK Right Edge", "tcp.options.snack.re",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_scpsoption_flags_bets,
{ "Partial Reliability Capable (BETS)",
"tcp.options.scpsflags.bets", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_tcp_scpsoption_flags_snack1,
{ "Short Form SNACK Capable (SNACK1)",
"tcp.options.scpsflags.snack1", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_tcp_scpsoption_flags_snack2,
{ "Long Form SNACK Capable (SNACK2)",
"tcp.options.scpsflags.snack2", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_tcp_scpsoption_flags_compress,
{ "Lossless Header Compression (COMP)",
"tcp.options.scpsflags.compress", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_tcp_scpsoption_flags_nlts,
{ "Network Layer Timestamp (NLTS)",
"tcp.options.scpsflags.nlts", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x8, NULL, HFILL }},
{ &hf_tcp_scpsoption_flags_reserved,
{ "Reserved",
"tcp.options.scpsflags.reserved", FT_UINT8, BASE_DEC,
NULL, 0x7, NULL, HFILL }},
{ &hf_tcp_scpsoption_connection_id,
{ "Connection ID",
"tcp.options.scps.binding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"TCP SCPS Connection ID", HFILL}},
{ &hf_tcp_option_user_to,
{ "TCP User Timeout", "tcp.options.user_to", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_user_to_granularity,
{ "Granularity", "tcp.options.user_to_granularity", FT_BOOLEAN,
16, TFS(&tcp_option_user_to_granularity), 0x8000, "TCP User Timeout Granularity", HFILL}},
{ &hf_tcp_option_user_to_val,
{ "User Timeout", "tcp.options.user_to_val", FT_UINT16,
BASE_DEC, NULL, 0x7FFF, "TCP User Timeout Value", HFILL}},
{ &hf_tcp_option_rvbd_probe,
{ "Riverbed Probe", "tcp.options.rvbd.probe", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "RVBD TCP Probe Option", HFILL }},
{ &hf_tcp_option_rvbd_probe_type1,
{ "Type", "tcp.options.rvbd.probe.type1",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_type2,
{ "Type", "tcp.options.rvbd.probe.type2",
FT_UINT8, BASE_DEC, NULL, 0xFE, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_version1,
{ "Version", "tcp.options.rvbd.probe.version",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_version2,
{ "Version", "tcp.options.rvbd.probe.version_raw",
FT_UINT8, BASE_DEC, NULL, 0x01, "Version 2 Raw Value", HFILL }},
{ &hf_tcp_option_rvbd_probe_optlen,
{ "Length", "tcp.options.rvbd.probe.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_prober,
{ "CSH IP", "tcp.options.rvbd.probe.prober",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_proxy,
{ "SSH IP", "tcp.options.rvbd.probe.proxy.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_proxy_port,
{ "SSH Port", "tcp.options.rvbd.probe.proxy.port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_appli_ver,
{ "Application Version", "tcp.options.rvbd.probe.appli_ver",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_client,
{ "Client IP", "tcp.options.rvbd.probe.client.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_storeid,
{ "CFE Store ID", "tcp.options.rvbd.probe.storeid",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_flags,
{ "Probe Flags", "tcp.options.rvbd.probe.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_flag_not_cfe,
{ "Not CFE", "tcp.options.rvbd.probe.flags.notcfe",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), RVBD_FLAGS_PROBE_NCFE,
NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_flag_last_notify,
{ "Last Notify", "tcp.options.rvbd.probe.flags.last",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), RVBD_FLAGS_PROBE_LAST,
NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_flag_probe_cache,
{ "Disable Probe Cache on CSH", "tcp.options.rvbd.probe.flags.probe",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), RVBD_FLAGS_PROBE,
NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_flag_sslcert,
{ "SSL Enabled", "tcp.options.rvbd.probe.flags.ssl",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), RVBD_FLAGS_PROBE_SSLCERT,
NULL, HFILL }},
{ &hf_tcp_option_rvbd_probe_flag_server_connected,
{ "SSH outer to server established", "tcp.options.rvbd.probe.flags.server",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), RVBD_FLAGS_PROBE_SERVER,
NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy,
{ "Riverbed Transparency", "tcp.options.rvbd.trpy",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"RVBD TCP Transparency Option", HFILL }},
{ &hf_tcp_option_rvbd_trpy_flags,
{ "Transparency Options", "tcp.options.rvbd.trpy.flags",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_flag_fw_rst_probe,
{ "Enable FW traversal feature", "tcp.options.rvbd.trpy.flags.fw_rst_probe",
FT_BOOLEAN, 16, TFS(&tfs_set_notset),
RVBD_FLAGS_TRPY_FW_RST_PROBE,
"Reset state created by probe on the nexthop firewall",
HFILL }},
{ &hf_tcp_option_rvbd_trpy_flag_fw_rst_inner,
{ "Enable Inner FW feature on All FWs", "tcp.options.rvbd.trpy.flags.fw_rst_inner",
FT_BOOLEAN, 16, TFS(&tfs_set_notset),
RVBD_FLAGS_TRPY_FW_RST_INNER,
"Reset state created by transparent inner on all firewalls"
" before passing connection through",
HFILL }},
{ &hf_tcp_option_rvbd_trpy_flag_fw_rst,
{ "Enable Transparency FW feature on All FWs", "tcp.options.rvbd.trpy.flags.fw_rst",
FT_BOOLEAN, 16, TFS(&tfs_set_notset),
RVBD_FLAGS_TRPY_FW_RST,
"Reset state created by probe on all firewalls before "
"establishing transparent inner connection", HFILL }},
{ &hf_tcp_option_rvbd_trpy_flag_chksum,
{ "Reserved", "tcp.options.rvbd.trpy.flags.chksum",
FT_BOOLEAN, 16, TFS(&tfs_set_notset),
RVBD_FLAGS_TRPY_CHKSUM, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_flag_oob,
{ "Out of band connection", "tcp.options.rvbd.trpy.flags.oob",
FT_BOOLEAN, 16, TFS(&tfs_set_notset),
RVBD_FLAGS_TRPY_OOB, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_flag_mode,
{ "Transparency Mode", "tcp.options.rvbd.trpy.flags.mode",
FT_BOOLEAN, 16, TFS(&trpy_mode_str),
RVBD_FLAGS_TRPY_MODE, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_src,
{ "Src SH IP Addr", "tcp.options.rvbd.trpy.src.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_dst,
{ "Dst SH IP Addr", "tcp.options.rvbd.trpy.dst.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_src_port,
{ "Src SH Inner Port", "tcp.options.rvbd.trpy.src.port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_dst_port,
{ "Dst SH Inner Port", "tcp.options.rvbd.trpy.dst.port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_rvbd_trpy_client_port,
{ "Out of band connection Client Port", "tcp.options.rvbd.trpy.client.port",
FT_UINT16, BASE_DEC, NULL , 0x0, NULL, HFILL }},
{ &hf_tcp_option_fast_open,
{ "Fast Open", "tcp.options.tfo", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_fast_open_cookie_request,
{ "Fast Open Cookie Request", "tcp.options.tfo.request", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_tcp_option_fast_open_cookie,
{ "Fast Open Cookie", "tcp.options.tfo.cookie", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_tcp_pdu_time,
{ "Time until the last segment of this PDU", "tcp.pdu.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"How long time has passed until the last frame of this PDU", HFILL}},
{ &hf_tcp_pdu_size,
{ "PDU Size", "tcp.pdu.size", FT_UINT32, BASE_DEC, NULL, 0x0,
"The size of this PDU", HFILL}},
{ &hf_tcp_pdu_last_frame,
{ "Last frame of this PDU", "tcp.pdu.last_frame", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is the last frame of the PDU starting in this segment", HFILL }},
{ &hf_tcp_ts_relative,
{ "Time since first frame in this TCP stream", "tcp.time_relative", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Time relative to first frame in this TCP stream", HFILL}},
{ &hf_tcp_ts_delta,
{ "Time since previous frame in this TCP stream", "tcp.time_delta", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Time delta from previous frame in this TCP stream", HFILL}},
{ &hf_tcp_proc_src_uid,
{ "Source process user ID", "tcp.proc.srcuid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_proc_src_pid,
{ "Source process ID", "tcp.proc.srcpid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_proc_src_uname,
{ "Source process user name", "tcp.proc.srcuname", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_proc_src_cmd,
{ "Source process name", "tcp.proc.srccmd", FT_STRING, BASE_NONE, NULL, 0x0,
"Source process command name", HFILL}},
{ &hf_tcp_proc_dst_uid,
{ "Destination process user ID", "tcp.proc.dstuid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_proc_dst_pid,
{ "Destination process ID", "tcp.proc.dstpid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_proc_dst_uname,
{ "Destination process user name", "tcp.proc.dstuname", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_tcp_proc_dst_cmd,
{ "Destination process name", "tcp.proc.dstcmd", FT_STRING, BASE_NONE, NULL, 0x0,
"Destination process command name", HFILL}},
{ &hf_tcp_segment_data,
{ "TCP segment data", "tcp.segment_data", FT_BYTES, BASE_NONE, NULL, 0x0,
"A data segment used in reassembly of a lower-level protocol", HFILL}}
};
static gint *ett[] = {
&ett_tcp,
&ett_tcp_flags,
&ett_tcp_options,
&ett_tcp_option_timestamp,
&ett_tcp_option_mptcp,
&ett_tcp_option_wscale,
&ett_tcp_option_sack,
&ett_tcp_option_scps,
&ett_tcp_option_scps_extended,
&ett_tcp_option_user_to,
&ett_tcp_option_exp,
&ett_tcp_option_sack_perm,
&ett_tcp_option_mss,
&ett_tcp_opt_rvbd_probe,
&ett_tcp_opt_rvbd_probe_flags,
&ett_tcp_opt_rvbd_trpy,
&ett_tcp_opt_rvbd_trpy_flags,
&ett_tcp_analysis_faults,
&ett_tcp_analysis,
&ett_tcp_timestamps,
&ett_tcp_segments,
&ett_tcp_segment,
&ett_tcp_checksum,
&ett_tcp_process_info
};
static const enum_val_t window_scaling_vals[] = {
{"not-known", "Not known", WindowScaling_NotKnown},
{"0", "0 (no scaling)", WindowScaling_0},
{"1", "1 (multiply by 2)", WindowScaling_1},
{"2", "2 (multiply by 4)", WindowScaling_2},
{"3", "3 (multiply by 8)", WindowScaling_3},
{"4", "4 (multiply by 16)", WindowScaling_4},
{"5", "5 (multiply by 32)", WindowScaling_5},
{"6", "6 (multiply by 64)", WindowScaling_6},
{"7", "7 (multiply by 128)", WindowScaling_7},
{"8", "8 (multiply by 256)", WindowScaling_8},
{"9", "9 (multiply by 512)", WindowScaling_9},
{"10", "10 (multiply by 1024)", WindowScaling_10},
{"11", "11 (multiply by 2048)", WindowScaling_11},
{"12", "12 (multiply by 4096)", WindowScaling_12},
{"13", "13 (multiply by 8192)", WindowScaling_13},
{"14", "14 (multiply by 16384)", WindowScaling_14},
{NULL, NULL, -1}
};
module_t *tcp_module;
proto_tcp = proto_register_protocol("Transmission Control Protocol",
"TCP", "tcp");
register_dissector("tcp", dissect_tcp, proto_tcp);
proto_register_field_array(proto_tcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
subdissector_table = register_dissector_table("tcp.port",
"TCP port", FT_UINT16, BASE_DEC);
register_heur_dissector_list("tcp", &heur_subdissector_list);
tcp_module = prefs_register_protocol(proto_tcp, NULL);
prefs_register_bool_preference(tcp_module, "summary_in_tree",
"Show TCP summary in protocol tree",
"Whether the TCP summary line should be shown in the protocol tree",
&tcp_summary_in_tree);
prefs_register_bool_preference(tcp_module, "check_checksum",
"Validate the TCP checksum if possible",
"Whether to validate the TCP checksum or not. "
"(Invalid checksums will cause reassembly, if enabled, to fail.)",
&tcp_check_checksum);
prefs_register_bool_preference(tcp_module, "desegment_tcp_streams",
"Allow subdissector to reassemble TCP streams",
"Whether subdissector can request TCP streams to be reassembled",
&tcp_desegment);
prefs_register_bool_preference(tcp_module, "analyze_sequence_numbers",
"Analyze TCP sequence numbers",
"Make the TCP dissector analyze TCP sequence numbers to find and flag segment retransmissions, missing segments and RTT",
&tcp_analyze_seq);
prefs_register_bool_preference(tcp_module, "relative_sequence_numbers",
"Relative sequence numbers",
"Make the TCP dissector use relative sequence numbers instead of absolute ones. "
"To use this option you must also enable \"Analyze TCP sequence numbers\". ",
&tcp_relative_seq);
prefs_register_enum_preference(tcp_module, "default_window_scaling",
"Scaling factor to use when not available from capture",
"Make the TCP dissector use this scaling factor for streams where the signalled scaling factor "
"is not visible in the capture",
&tcp_default_window_scaling, window_scaling_vals, FALSE);
prefs_register_obsolete_preference(tcp_module, "window_scaling");
prefs_register_bool_preference(tcp_module, "track_bytes_in_flight",
"Track number of bytes in flight",
"Make the TCP dissector track the number on un-ACKed bytes of data are in flight per packet. "
"To use this option you must also enable \"Analyze TCP sequence numbers\". "
"This takes a lot of memory but allows you to track how much data are in flight at a time and graphing it in io-graphs",
&tcp_track_bytes_in_flight);
prefs_register_bool_preference(tcp_module, "calculate_timestamps",
"Calculate conversation timestamps",
"Calculate timestamps relative to the first frame and the previous frame in the tcp conversation",
&tcp_calculate_ts);
prefs_register_bool_preference(tcp_module, "try_heuristic_first",
"Try heuristic sub-dissectors first",
"Try to decode a packet using an heuristic sub-dissector before using a sub-dissector registered to a specific port",
&try_heuristic_first);
prefs_register_bool_preference(tcp_module, "ignore_tcp_timestamps",
"Ignore TCP Timestamps in summary",
"Do not place the TCP Timestamps in the summary line",
&tcp_ignore_timestamps);
prefs_register_bool_preference(tcp_module, "no_subdissector_on_error",
"Do not call subdissectors for error packets",
"Do not call any subdissectors for Retransmitted or OutOfOrder segments",
&tcp_no_subdissector_on_error);
prefs_register_bool_preference(tcp_module, "dissect_experimental_options_with_magic",
"TCP Experimental Options with a Magic Number",
"Assume TCP Experimental Options (253, 254) have a Magic Number and use it for dissection",
&tcp_exp_options_with_magic);
register_init_routine(tcp_init);
}
void
proto_reg_handoff_tcp(void)
{
dissector_handle_t tcp_handle;
tcp_handle = find_dissector("tcp");
dissector_add_uint("ip.proto", IP_PROTO_TCP, tcp_handle);
data_handle = find_dissector("data");
sport_handle = find_dissector("sport");
tcp_tap = register_tap("tcp");
}
