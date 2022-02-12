static inline void sctp_outq_head_data(struct sctp_outq *q,
struct sctp_chunk *ch)
{
list_add(&ch->list, &q->out_chunk_list);
q->out_qlen += ch->skb->len;
}
static inline struct sctp_chunk *sctp_outq_dequeue_data(struct sctp_outq *q)
{
struct sctp_chunk *ch = NULL;
if (!list_empty(&q->out_chunk_list)) {
struct list_head *entry = q->out_chunk_list.next;
ch = list_entry(entry, struct sctp_chunk, list);
list_del_init(entry);
q->out_qlen -= ch->skb->len;
}
return ch;
}
static inline void sctp_outq_tail_data(struct sctp_outq *q,
struct sctp_chunk *ch)
{
list_add_tail(&ch->list, &q->out_chunk_list);
q->out_qlen += ch->skb->len;
}
static inline int sctp_cacc_skip_3_1_d(struct sctp_transport *primary,
struct sctp_transport *transport,
int count_of_newacks)
{
if (count_of_newacks >= 2 && transport != primary)
return 1;
return 0;
}
static inline int sctp_cacc_skip_3_1_f(struct sctp_transport *transport,
int count_of_newacks)
{
if (count_of_newacks < 2 &&
(transport && !transport->cacc.cacc_saw_newack))
return 1;
return 0;
}
static inline int sctp_cacc_skip_3_1(struct sctp_transport *primary,
struct sctp_transport *transport,
int count_of_newacks)
{
if (!primary->cacc.cycling_changeover) {
if (sctp_cacc_skip_3_1_d(primary, transport, count_of_newacks))
return 1;
if (sctp_cacc_skip_3_1_f(transport, count_of_newacks))
return 1;
return 0;
}
return 0;
}
static inline int sctp_cacc_skip_3_2(struct sctp_transport *primary, __u32 tsn)
{
if (primary->cacc.cycling_changeover &&
TSN_lt(tsn, primary->cacc.next_tsn_at_change))
return 1;
return 0;
}
static inline int sctp_cacc_skip(struct sctp_transport *primary,
struct sctp_transport *transport,
int count_of_newacks,
__u32 tsn)
{
if (primary->cacc.changeover_active &&
(sctp_cacc_skip_3_1(primary, transport, count_of_newacks) ||
sctp_cacc_skip_3_2(primary, tsn)))
return 1;
return 0;
}
void sctp_outq_init(struct sctp_association *asoc, struct sctp_outq *q)
{
memset(q, 0, sizeof(struct sctp_outq));
q->asoc = asoc;
INIT_LIST_HEAD(&q->out_chunk_list);
INIT_LIST_HEAD(&q->control_chunk_list);
INIT_LIST_HEAD(&q->retransmit);
INIT_LIST_HEAD(&q->sacked);
INIT_LIST_HEAD(&q->abandoned);
}
static void __sctp_outq_teardown(struct sctp_outq *q)
{
struct sctp_transport *transport;
struct list_head *lchunk, *temp;
struct sctp_chunk *chunk, *tmp;
list_for_each_entry(transport, &q->asoc->peer.transport_addr_list,
transports) {
while ((lchunk = sctp_list_dequeue(&transport->transmitted)) != NULL) {
chunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
sctp_chunk_fail(chunk, q->error);
sctp_chunk_free(chunk);
}
}
list_for_each_safe(lchunk, temp, &q->sacked) {
list_del_init(lchunk);
chunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
sctp_chunk_fail(chunk, q->error);
sctp_chunk_free(chunk);
}
list_for_each_safe(lchunk, temp, &q->retransmit) {
list_del_init(lchunk);
chunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
sctp_chunk_fail(chunk, q->error);
sctp_chunk_free(chunk);
}
list_for_each_safe(lchunk, temp, &q->abandoned) {
list_del_init(lchunk);
chunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
sctp_chunk_fail(chunk, q->error);
sctp_chunk_free(chunk);
}
while ((chunk = sctp_outq_dequeue_data(q)) != NULL) {
sctp_chunk_fail(chunk, q->error);
sctp_chunk_free(chunk);
}
list_for_each_entry_safe(chunk, tmp, &q->control_chunk_list, list) {
list_del_init(&chunk->list);
sctp_chunk_free(chunk);
}
}
void sctp_outq_teardown(struct sctp_outq *q)
{
__sctp_outq_teardown(q);
sctp_outq_init(q->asoc, q);
}
void sctp_outq_free(struct sctp_outq *q)
{
__sctp_outq_teardown(q);
}
int sctp_outq_tail(struct sctp_outq *q, struct sctp_chunk *chunk, gfp_t gfp)
{
struct net *net = sock_net(q->asoc->base.sk);
int error = 0;
pr_debug("%s: outq:%p, chunk:%p[%s]\n", __func__, q, chunk,
chunk && chunk->chunk_hdr ?
sctp_cname(SCTP_ST_CHUNK(chunk->chunk_hdr->type)) :
"illegal chunk");
if (sctp_chunk_is_data(chunk)) {
switch (q->asoc->state) {
case SCTP_STATE_CLOSED:
case SCTP_STATE_SHUTDOWN_PENDING:
case SCTP_STATE_SHUTDOWN_SENT:
case SCTP_STATE_SHUTDOWN_RECEIVED:
case SCTP_STATE_SHUTDOWN_ACK_SENT:
error = -ESHUTDOWN;
break;
default:
pr_debug("%s: outqueueing: outq:%p, chunk:%p[%s])\n",
__func__, q, chunk, chunk && chunk->chunk_hdr ?
sctp_cname(SCTP_ST_CHUNK(chunk->chunk_hdr->type)) :
"illegal chunk");
sctp_chunk_hold(chunk);
sctp_outq_tail_data(q, chunk);
if (chunk->asoc->peer.prsctp_capable &&
SCTP_PR_PRIO_ENABLED(chunk->sinfo.sinfo_flags))
chunk->asoc->sent_cnt_removable++;
if (chunk->chunk_hdr->flags & SCTP_DATA_UNORDERED)
SCTP_INC_STATS(net, SCTP_MIB_OUTUNORDERCHUNKS);
else
SCTP_INC_STATS(net, SCTP_MIB_OUTORDERCHUNKS);
break;
}
} else {
list_add_tail(&chunk->list, &q->control_chunk_list);
SCTP_INC_STATS(net, SCTP_MIB_OUTCTRLCHUNKS);
}
if (error < 0)
return error;
if (!q->cork)
error = sctp_outq_flush(q, 0, gfp);
return error;
}
static void sctp_insert_list(struct list_head *head, struct list_head *new)
{
struct list_head *pos;
struct sctp_chunk *nchunk, *lchunk;
__u32 ntsn, ltsn;
int done = 0;
nchunk = list_entry(new, struct sctp_chunk, transmitted_list);
ntsn = ntohl(nchunk->subh.data_hdr->tsn);
list_for_each(pos, head) {
lchunk = list_entry(pos, struct sctp_chunk, transmitted_list);
ltsn = ntohl(lchunk->subh.data_hdr->tsn);
if (TSN_lt(ntsn, ltsn)) {
list_add(new, pos->prev);
done = 1;
break;
}
}
if (!done)
list_add_tail(new, head);
}
static int sctp_prsctp_prune_sent(struct sctp_association *asoc,
struct sctp_sndrcvinfo *sinfo,
struct list_head *queue, int msg_len)
{
struct sctp_chunk *chk, *temp;
list_for_each_entry_safe(chk, temp, queue, transmitted_list) {
if (!SCTP_PR_PRIO_ENABLED(chk->sinfo.sinfo_flags) ||
chk->sinfo.sinfo_timetolive <= sinfo->sinfo_timetolive)
continue;
list_del_init(&chk->transmitted_list);
sctp_insert_list(&asoc->outqueue.abandoned,
&chk->transmitted_list);
asoc->sent_cnt_removable--;
asoc->abandoned_sent[SCTP_PR_INDEX(PRIO)]++;
if (!chk->tsn_gap_acked) {
if (chk->transport)
chk->transport->flight_size -=
sctp_data_size(chk);
asoc->outqueue.outstanding_bytes -= sctp_data_size(chk);
}
msg_len -= SCTP_DATA_SNDSIZE(chk) +
sizeof(struct sk_buff) +
sizeof(struct sctp_chunk);
if (msg_len <= 0)
break;
}
return msg_len;
}
static int sctp_prsctp_prune_unsent(struct sctp_association *asoc,
struct sctp_sndrcvinfo *sinfo,
struct list_head *queue, int msg_len)
{
struct sctp_chunk *chk, *temp;
list_for_each_entry_safe(chk, temp, queue, list) {
if (!SCTP_PR_PRIO_ENABLED(chk->sinfo.sinfo_flags) ||
chk->sinfo.sinfo_timetolive <= sinfo->sinfo_timetolive)
continue;
list_del_init(&chk->list);
asoc->sent_cnt_removable--;
asoc->abandoned_unsent[SCTP_PR_INDEX(PRIO)]++;
msg_len -= SCTP_DATA_SNDSIZE(chk) +
sizeof(struct sk_buff) +
sizeof(struct sctp_chunk);
sctp_chunk_free(chk);
if (msg_len <= 0)
break;
}
return msg_len;
}
void sctp_prsctp_prune(struct sctp_association *asoc,
struct sctp_sndrcvinfo *sinfo, int msg_len)
{
struct sctp_transport *transport;
if (!asoc->peer.prsctp_capable || !asoc->sent_cnt_removable)
return;
msg_len = sctp_prsctp_prune_sent(asoc, sinfo,
&asoc->outqueue.retransmit,
msg_len);
if (msg_len <= 0)
return;
list_for_each_entry(transport, &asoc->peer.transport_addr_list,
transports) {
msg_len = sctp_prsctp_prune_sent(asoc, sinfo,
&transport->transmitted,
msg_len);
if (msg_len <= 0)
return;
}
sctp_prsctp_prune_unsent(asoc, sinfo,
&asoc->outqueue.out_chunk_list,
msg_len);
}
void sctp_retransmit_mark(struct sctp_outq *q,
struct sctp_transport *transport,
__u8 reason)
{
struct list_head *lchunk, *ltemp;
struct sctp_chunk *chunk;
list_for_each_safe(lchunk, ltemp, &transport->transmitted) {
chunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
if (sctp_chunk_abandoned(chunk)) {
list_del_init(lchunk);
sctp_insert_list(&q->abandoned, lchunk);
if (!chunk->tsn_gap_acked) {
if (chunk->transport)
chunk->transport->flight_size -=
sctp_data_size(chunk);
q->outstanding_bytes -= sctp_data_size(chunk);
q->asoc->peer.rwnd += sctp_data_size(chunk);
}
continue;
}
if ((reason == SCTP_RTXR_FAST_RTX &&
(chunk->fast_retransmit == SCTP_NEED_FRTX)) ||
(reason != SCTP_RTXR_FAST_RTX && !chunk->tsn_gap_acked)) {
q->asoc->peer.rwnd += sctp_data_size(chunk);
q->outstanding_bytes -= sctp_data_size(chunk);
if (chunk->transport)
transport->flight_size -= sctp_data_size(chunk);
chunk->tsn_missing_report = 0;
if (chunk->rtt_in_progress) {
chunk->rtt_in_progress = 0;
transport->rto_pending = 0;
}
chunk->resent = 1;
list_del_init(lchunk);
sctp_insert_list(&q->retransmit, lchunk);
}
}
pr_debug("%s: transport:%p, reason:%d, cwnd:%d, ssthresh:%d, "
"flight_size:%d, pba:%d\n", __func__, transport, reason,
transport->cwnd, transport->ssthresh, transport->flight_size,
transport->partial_bytes_acked);
}
void sctp_retransmit(struct sctp_outq *q, struct sctp_transport *transport,
sctp_retransmit_reason_t reason)
{
struct net *net = sock_net(q->asoc->base.sk);
int error = 0;
switch (reason) {
case SCTP_RTXR_T3_RTX:
SCTP_INC_STATS(net, SCTP_MIB_T3_RETRANSMITS);
sctp_transport_lower_cwnd(transport, SCTP_LOWER_CWND_T3_RTX);
if (transport == transport->asoc->peer.retran_path)
sctp_assoc_update_retran_path(transport->asoc);
transport->asoc->rtx_data_chunks +=
transport->asoc->unack_data;
break;
case SCTP_RTXR_FAST_RTX:
SCTP_INC_STATS(net, SCTP_MIB_FAST_RETRANSMITS);
sctp_transport_lower_cwnd(transport, SCTP_LOWER_CWND_FAST_RTX);
q->fast_rtx = 1;
break;
case SCTP_RTXR_PMTUD:
SCTP_INC_STATS(net, SCTP_MIB_PMTUD_RETRANSMITS);
break;
case SCTP_RTXR_T1_RTX:
SCTP_INC_STATS(net, SCTP_MIB_T1_RETRANSMITS);
transport->asoc->init_retries++;
break;
default:
BUG();
}
sctp_retransmit_mark(q, transport, reason);
if (reason == SCTP_RTXR_T3_RTX)
sctp_generate_fwdtsn(q, q->asoc->ctsn_ack_point);
if (reason != SCTP_RTXR_FAST_RTX)
error = sctp_outq_flush(q, 1, GFP_ATOMIC);
if (error)
q->asoc->base.sk->sk_err = -error;
}
static int sctp_outq_flush_rtx(struct sctp_outq *q, struct sctp_packet *pkt,
int rtx_timeout, int *start_timer)
{
struct list_head *lqueue;
struct sctp_transport *transport = pkt->transport;
sctp_xmit_t status;
struct sctp_chunk *chunk, *chunk1;
int fast_rtx;
int error = 0;
int timer = 0;
int done = 0;
lqueue = &q->retransmit;
fast_rtx = q->fast_rtx;
list_for_each_entry_safe(chunk, chunk1, lqueue, transmitted_list) {
if (sctp_chunk_abandoned(chunk)) {
list_del_init(&chunk->transmitted_list);
sctp_insert_list(&q->abandoned,
&chunk->transmitted_list);
continue;
}
if (chunk->tsn_gap_acked) {
list_move_tail(&chunk->transmitted_list,
&transport->transmitted);
continue;
}
if (fast_rtx && !chunk->fast_retransmit)
continue;
redo:
status = sctp_packet_append_chunk(pkt, chunk);
switch (status) {
case SCTP_XMIT_PMTU_FULL:
if (!pkt->has_data && !pkt->has_cookie_echo) {
sctp_packet_transmit(pkt, GFP_ATOMIC);
goto redo;
}
error = sctp_packet_transmit(pkt, GFP_ATOMIC);
if (rtx_timeout || fast_rtx)
done = 1;
else
goto redo;
break;
case SCTP_XMIT_RWND_FULL:
error = sctp_packet_transmit(pkt, GFP_ATOMIC);
done = 1;
break;
case SCTP_XMIT_DELAY:
error = sctp_packet_transmit(pkt, GFP_ATOMIC);
done = 1;
break;
default:
list_move_tail(&chunk->transmitted_list,
&transport->transmitted);
if (chunk->fast_retransmit == SCTP_NEED_FRTX)
chunk->fast_retransmit = SCTP_DONT_FRTX;
q->asoc->stats.rtxchunks++;
break;
}
if (!error && !timer)
timer = 1;
if (done)
break;
}
if (rtx_timeout || fast_rtx) {
list_for_each_entry(chunk1, lqueue, transmitted_list) {
if (chunk1->fast_retransmit == SCTP_NEED_FRTX)
chunk1->fast_retransmit = SCTP_DONT_FRTX;
}
}
*start_timer = timer;
if (fast_rtx)
q->fast_rtx = 0;
return error;
}
int sctp_outq_uncork(struct sctp_outq *q, gfp_t gfp)
{
if (q->cork)
q->cork = 0;
return sctp_outq_flush(q, 0, gfp);
}
static int sctp_outq_flush(struct sctp_outq *q, int rtx_timeout, gfp_t gfp)
{
struct sctp_packet *packet;
struct sctp_packet singleton;
struct sctp_association *asoc = q->asoc;
__u16 sport = asoc->base.bind_addr.port;
__u16 dport = asoc->peer.port;
__u32 vtag = asoc->peer.i.init_tag;
struct sctp_transport *transport = NULL;
struct sctp_transport *new_transport;
struct sctp_chunk *chunk, *tmp;
sctp_xmit_t status;
int error = 0;
int start_timer = 0;
int one_packet = 0;
struct list_head transport_list;
struct list_head *ltransport;
INIT_LIST_HEAD(&transport_list);
packet = NULL;
list_for_each_entry_safe(chunk, tmp, &q->control_chunk_list, list) {
if (asoc->src_out_of_asoc_ok &&
chunk->chunk_hdr->type != SCTP_CID_ASCONF)
continue;
list_del_init(&chunk->list);
new_transport = chunk->transport;
if (!new_transport) {
if (transport &&
sctp_cmp_addr_exact(&chunk->dest,
&transport->ipaddr))
new_transport = transport;
else
new_transport = sctp_assoc_lookup_paddr(asoc,
&chunk->dest);
if (!new_transport)
new_transport = asoc->peer.active_path;
} else if ((new_transport->state == SCTP_INACTIVE) ||
(new_transport->state == SCTP_UNCONFIRMED) ||
(new_transport->state == SCTP_PF)) {
if (chunk->chunk_hdr->type != SCTP_CID_HEARTBEAT &&
chunk->chunk_hdr->type != SCTP_CID_HEARTBEAT_ACK &&
chunk->chunk_hdr->type != SCTP_CID_ASCONF_ACK)
new_transport = asoc->peer.active_path;
}
if (new_transport != transport) {
transport = new_transport;
if (list_empty(&transport->send_ready)) {
list_add_tail(&transport->send_ready,
&transport_list);
}
packet = &transport->packet;
sctp_packet_config(packet, vtag,
asoc->peer.ecn_capable);
}
switch (chunk->chunk_hdr->type) {
case SCTP_CID_INIT:
case SCTP_CID_INIT_ACK:
case SCTP_CID_SHUTDOWN_COMPLETE:
sctp_packet_init(&singleton, transport, sport, dport);
sctp_packet_config(&singleton, vtag, 0);
sctp_packet_append_chunk(&singleton, chunk);
error = sctp_packet_transmit(&singleton, gfp);
if (error < 0)
return error;
break;
case SCTP_CID_ABORT:
if (sctp_test_T_bit(chunk)) {
packet->vtag = asoc->c.my_vtag;
}
case SCTP_CID_HEARTBEAT_ACK:
case SCTP_CID_SHUTDOWN_ACK:
case SCTP_CID_COOKIE_ACK:
case SCTP_CID_COOKIE_ECHO:
case SCTP_CID_ERROR:
case SCTP_CID_ECN_CWR:
case SCTP_CID_ASCONF_ACK:
one_packet = 1;
case SCTP_CID_SACK:
case SCTP_CID_HEARTBEAT:
case SCTP_CID_SHUTDOWN:
case SCTP_CID_ECN_ECNE:
case SCTP_CID_ASCONF:
case SCTP_CID_FWD_TSN:
status = sctp_packet_transmit_chunk(packet, chunk,
one_packet, gfp);
if (status != SCTP_XMIT_OK) {
list_add(&chunk->list, &q->control_chunk_list);
} else {
asoc->stats.octrlchunks++;
if (chunk->chunk_hdr->type == SCTP_CID_FWD_TSN) {
sctp_transport_reset_t3_rtx(transport);
transport->last_time_sent = jiffies;
}
}
break;
default:
BUG();
}
}
if (q->asoc->src_out_of_asoc_ok)
goto sctp_flush_out;
switch (asoc->state) {
case SCTP_STATE_COOKIE_ECHOED:
if (!packet || !packet->has_cookie_echo)
break;
case SCTP_STATE_ESTABLISHED:
case SCTP_STATE_SHUTDOWN_PENDING:
case SCTP_STATE_SHUTDOWN_RECEIVED:
if (!list_empty(&q->retransmit)) {
if (asoc->peer.retran_path->state == SCTP_UNCONFIRMED)
goto sctp_flush_out;
if (transport == asoc->peer.retran_path)
goto retran;
transport = asoc->peer.retran_path;
if (list_empty(&transport->send_ready)) {
list_add_tail(&transport->send_ready,
&transport_list);
}
packet = &transport->packet;
sctp_packet_config(packet, vtag,
asoc->peer.ecn_capable);
retran:
error = sctp_outq_flush_rtx(q, packet,
rtx_timeout, &start_timer);
if (start_timer) {
sctp_transport_reset_t3_rtx(transport);
transport->last_time_sent = jiffies;
}
if (packet->has_cookie_echo)
goto sctp_flush_out;
if (!list_empty(&q->retransmit))
goto sctp_flush_out;
}
if (transport)
sctp_transport_burst_limited(transport);
while ((chunk = sctp_outq_dequeue_data(q)) != NULL) {
if (chunk->sinfo.sinfo_stream >=
asoc->c.sinit_num_ostreams) {
sctp_chunk_fail(chunk, SCTP_ERROR_INV_STRM);
if (asoc->peer.prsctp_capable &&
SCTP_PR_PRIO_ENABLED(chunk->sinfo.sinfo_flags))
asoc->sent_cnt_removable--;
sctp_chunk_free(chunk);
continue;
}
if (sctp_chunk_abandoned(chunk)) {
sctp_chunk_fail(chunk, 0);
sctp_chunk_free(chunk);
continue;
}
new_transport = chunk->transport;
if (!new_transport ||
((new_transport->state == SCTP_INACTIVE) ||
(new_transport->state == SCTP_UNCONFIRMED) ||
(new_transport->state == SCTP_PF)))
new_transport = asoc->peer.active_path;
if (new_transport->state == SCTP_UNCONFIRMED) {
WARN_ONCE(1, "Atempt to send packet on unconfirmed path.");
sctp_chunk_fail(chunk, 0);
sctp_chunk_free(chunk);
continue;
}
if (new_transport != transport) {
transport = new_transport;
if (list_empty(&transport->send_ready)) {
list_add_tail(&transport->send_ready,
&transport_list);
}
packet = &transport->packet;
sctp_packet_config(packet, vtag,
asoc->peer.ecn_capable);
sctp_transport_burst_limited(transport);
}
pr_debug("%s: outq:%p, chunk:%p[%s], tx-tsn:0x%x skb->head:%p "
"skb->users:%d\n",
__func__, q, chunk, chunk && chunk->chunk_hdr ?
sctp_cname(SCTP_ST_CHUNK(chunk->chunk_hdr->type)) :
"illegal chunk", ntohl(chunk->subh.data_hdr->tsn),
chunk->skb ? chunk->skb->head : NULL, chunk->skb ?
atomic_read(&chunk->skb->users) : -1);
status = sctp_packet_transmit_chunk(packet, chunk, 0, gfp);
switch (status) {
case SCTP_XMIT_PMTU_FULL:
case SCTP_XMIT_RWND_FULL:
case SCTP_XMIT_DELAY:
pr_debug("%s: could not transmit tsn:0x%x, status:%d\n",
__func__, ntohl(chunk->subh.data_hdr->tsn),
status);
sctp_outq_head_data(q, chunk);
goto sctp_flush_out;
case SCTP_XMIT_OK:
if (asoc->state == SCTP_STATE_SHUTDOWN_PENDING)
chunk->chunk_hdr->flags |= SCTP_DATA_SACK_IMM;
if (chunk->chunk_hdr->flags & SCTP_DATA_UNORDERED)
asoc->stats.ouodchunks++;
else
asoc->stats.oodchunks++;
break;
default:
BUG();
}
list_add_tail(&chunk->transmitted_list,
&transport->transmitted);
sctp_transport_reset_t3_rtx(transport);
transport->last_time_sent = jiffies;
if (packet->has_cookie_echo)
goto sctp_flush_out;
}
break;
default:
break;
}
sctp_flush_out:
while ((ltransport = sctp_list_dequeue(&transport_list)) != NULL) {
struct sctp_transport *t = list_entry(ltransport,
struct sctp_transport,
send_ready);
packet = &t->packet;
if (!sctp_packet_empty(packet))
error = sctp_packet_transmit(packet, gfp);
sctp_transport_burst_reset(t);
}
return error;
}
static void sctp_sack_update_unack_data(struct sctp_association *assoc,
struct sctp_sackhdr *sack)
{
sctp_sack_variable_t *frags;
__u16 unack_data;
int i;
unack_data = assoc->next_tsn - assoc->ctsn_ack_point - 1;
frags = sack->variable;
for (i = 0; i < ntohs(sack->num_gap_ack_blocks); i++) {
unack_data -= ((ntohs(frags[i].gab.end) -
ntohs(frags[i].gab.start) + 1));
}
assoc->unack_data = unack_data;
}
int sctp_outq_sack(struct sctp_outq *q, struct sctp_chunk *chunk)
{
struct sctp_association *asoc = q->asoc;
struct sctp_sackhdr *sack = chunk->subh.sack_hdr;
struct sctp_transport *transport;
struct sctp_chunk *tchunk = NULL;
struct list_head *lchunk, *transport_list, *temp;
sctp_sack_variable_t *frags = sack->variable;
__u32 sack_ctsn, ctsn, tsn;
__u32 highest_tsn, highest_new_tsn;
__u32 sack_a_rwnd;
unsigned int outstanding;
struct sctp_transport *primary = asoc->peer.primary_path;
int count_of_newacks = 0;
int gap_ack_blocks;
u8 accum_moved = 0;
transport_list = &asoc->peer.transport_addr_list;
sack_ctsn = ntohl(sack->cum_tsn_ack);
gap_ack_blocks = ntohs(sack->num_gap_ack_blocks);
asoc->stats.gapcnt += gap_ack_blocks;
if (primary->cacc.changeover_active) {
u8 clear_cycling = 0;
if (TSN_lte(primary->cacc.next_tsn_at_change, sack_ctsn)) {
primary->cacc.changeover_active = 0;
clear_cycling = 1;
}
if (clear_cycling || gap_ack_blocks) {
list_for_each_entry(transport, transport_list,
transports) {
if (clear_cycling)
transport->cacc.cycling_changeover = 0;
if (gap_ack_blocks)
transport->cacc.cacc_saw_newack = 0;
}
}
}
highest_tsn = sack_ctsn;
if (gap_ack_blocks)
highest_tsn += ntohs(frags[gap_ack_blocks - 1].gab.end);
if (TSN_lt(asoc->highest_sacked, highest_tsn))
asoc->highest_sacked = highest_tsn;
highest_new_tsn = sack_ctsn;
sctp_check_transmitted(q, &q->retransmit, NULL, NULL, sack, &highest_new_tsn);
list_for_each_entry(transport, transport_list, transports) {
sctp_check_transmitted(q, &transport->transmitted,
transport, &chunk->source, sack,
&highest_new_tsn);
if (transport->cacc.cacc_saw_newack)
count_of_newacks++;
}
if (TSN_lt(asoc->ctsn_ack_point, sack_ctsn)) {
asoc->ctsn_ack_point = sack_ctsn;
accum_moved = 1;
}
if (gap_ack_blocks) {
if (asoc->fast_recovery && accum_moved)
highest_new_tsn = highest_tsn;
list_for_each_entry(transport, transport_list, transports)
sctp_mark_missing(q, &transport->transmitted, transport,
highest_new_tsn, count_of_newacks);
}
sctp_sack_update_unack_data(asoc, sack);
ctsn = asoc->ctsn_ack_point;
list_for_each_safe(lchunk, temp, &q->sacked) {
tchunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
tsn = ntohl(tchunk->subh.data_hdr->tsn);
if (TSN_lte(tsn, ctsn)) {
list_del_init(&tchunk->transmitted_list);
if (asoc->peer.prsctp_capable &&
SCTP_PR_PRIO_ENABLED(chunk->sinfo.sinfo_flags))
asoc->sent_cnt_removable--;
sctp_chunk_free(tchunk);
}
}
sack_a_rwnd = ntohl(sack->a_rwnd);
asoc->peer.zero_window_announced = !sack_a_rwnd;
outstanding = q->outstanding_bytes;
if (outstanding < sack_a_rwnd)
sack_a_rwnd -= outstanding;
else
sack_a_rwnd = 0;
asoc->peer.rwnd = sack_a_rwnd;
sctp_generate_fwdtsn(q, sack_ctsn);
pr_debug("%s: sack cumulative tsn ack:0x%x\n", __func__, sack_ctsn);
pr_debug("%s: cumulative tsn ack of assoc:%p is 0x%x, "
"advertised peer ack point:0x%x\n", __func__, asoc, ctsn,
asoc->adv_peer_ack_point);
return sctp_outq_is_empty(q);
}
int sctp_outq_is_empty(const struct sctp_outq *q)
{
return q->out_qlen == 0 && q->outstanding_bytes == 0 &&
list_empty(&q->retransmit);
}
static void sctp_check_transmitted(struct sctp_outq *q,
struct list_head *transmitted_queue,
struct sctp_transport *transport,
union sctp_addr *saddr,
struct sctp_sackhdr *sack,
__u32 *highest_new_tsn_in_sack)
{
struct list_head *lchunk;
struct sctp_chunk *tchunk;
struct list_head tlist;
__u32 tsn;
__u32 sack_ctsn;
__u32 rtt;
__u8 restart_timer = 0;
int bytes_acked = 0;
int migrate_bytes = 0;
bool forward_progress = false;
sack_ctsn = ntohl(sack->cum_tsn_ack);
INIT_LIST_HEAD(&tlist);
while (NULL != (lchunk = sctp_list_dequeue(transmitted_queue))) {
tchunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
if (sctp_chunk_abandoned(tchunk)) {
sctp_insert_list(&q->abandoned, lchunk);
if (!tchunk->tsn_gap_acked) {
if (tchunk->transport)
tchunk->transport->flight_size -=
sctp_data_size(tchunk);
q->outstanding_bytes -= sctp_data_size(tchunk);
}
continue;
}
tsn = ntohl(tchunk->subh.data_hdr->tsn);
if (sctp_acked(sack, tsn)) {
if (transport) {
if (!tchunk->tsn_gap_acked &&
!tchunk->resent &&
tchunk->rtt_in_progress) {
tchunk->rtt_in_progress = 0;
rtt = jiffies - tchunk->sent_at;
sctp_transport_update_rto(transport,
rtt);
}
}
if (!tchunk->tsn_gap_acked) {
tchunk->tsn_gap_acked = 1;
if (TSN_lt(*highest_new_tsn_in_sack, tsn))
*highest_new_tsn_in_sack = tsn;
bytes_acked += sctp_data_size(tchunk);
if (!tchunk->transport)
migrate_bytes += sctp_data_size(tchunk);
forward_progress = true;
}
if (TSN_lte(tsn, sack_ctsn)) {
restart_timer = 1;
forward_progress = true;
if (!tchunk->tsn_gap_acked) {
if (transport &&
sack->num_gap_ack_blocks &&
q->asoc->peer.primary_path->cacc.
changeover_active)
transport->cacc.cacc_saw_newack
= 1;
}
list_add_tail(&tchunk->transmitted_list,
&q->sacked);
} else {
list_add_tail(lchunk, &tlist);
}
} else {
if (tchunk->tsn_gap_acked) {
pr_debug("%s: receiver reneged on data TSN:0x%x\n",
__func__, tsn);
tchunk->tsn_gap_acked = 0;
if (tchunk->transport)
bytes_acked -= sctp_data_size(tchunk);
restart_timer = 1;
}
list_add_tail(lchunk, &tlist);
}
}
if (transport) {
if (bytes_acked) {
struct sctp_association *asoc = transport->asoc;
bytes_acked -= migrate_bytes;
transport->error_count = 0;
transport->asoc->overall_error_count = 0;
forward_progress = true;
if (asoc->state == SCTP_STATE_SHUTDOWN_PENDING &&
del_timer(&asoc->timers
[SCTP_EVENT_TIMEOUT_T5_SHUTDOWN_GUARD]))
sctp_association_put(asoc);
if ((transport->state == SCTP_INACTIVE ||
transport->state == SCTP_UNCONFIRMED) &&
sctp_cmp_addr_exact(&transport->ipaddr, saddr)) {
sctp_assoc_control_transport(
transport->asoc,
transport,
SCTP_TRANSPORT_UP,
SCTP_RECEIVED_SACK);
}
sctp_transport_raise_cwnd(transport, sack_ctsn,
bytes_acked);
transport->flight_size -= bytes_acked;
if (transport->flight_size == 0)
transport->partial_bytes_acked = 0;
q->outstanding_bytes -= bytes_acked + migrate_bytes;
} else {
if (!q->asoc->peer.rwnd &&
!list_empty(&tlist) &&
(sack_ctsn+2 == q->asoc->next_tsn) &&
q->asoc->state < SCTP_STATE_SHUTDOWN_PENDING) {
pr_debug("%s: sack received for zero window "
"probe:%u\n", __func__, sack_ctsn);
q->asoc->overall_error_count = 0;
transport->error_count = 0;
}
}
if (!transport->flight_size) {
if (del_timer(&transport->T3_rtx_timer))
sctp_transport_put(transport);
} else if (restart_timer) {
if (!mod_timer(&transport->T3_rtx_timer,
jiffies + transport->rto))
sctp_transport_hold(transport);
}
if (forward_progress) {
if (transport->dst)
dst_confirm(transport->dst);
}
}
list_splice(&tlist, transmitted_queue);
}
static void sctp_mark_missing(struct sctp_outq *q,
struct list_head *transmitted_queue,
struct sctp_transport *transport,
__u32 highest_new_tsn_in_sack,
int count_of_newacks)
{
struct sctp_chunk *chunk;
__u32 tsn;
char do_fast_retransmit = 0;
struct sctp_association *asoc = q->asoc;
struct sctp_transport *primary = asoc->peer.primary_path;
list_for_each_entry(chunk, transmitted_queue, transmitted_list) {
tsn = ntohl(chunk->subh.data_hdr->tsn);
if (chunk->fast_retransmit == SCTP_CAN_FRTX &&
!chunk->tsn_gap_acked &&
TSN_lt(tsn, highest_new_tsn_in_sack)) {
if (!transport || !sctp_cacc_skip(primary,
chunk->transport,
count_of_newacks, tsn)) {
chunk->tsn_missing_report++;
pr_debug("%s: tsn:0x%x missing counter:%d\n",
__func__, tsn, chunk->tsn_missing_report);
}
}
if (chunk->tsn_missing_report >= 3) {
chunk->fast_retransmit = SCTP_NEED_FRTX;
do_fast_retransmit = 1;
}
}
if (transport) {
if (do_fast_retransmit)
sctp_retransmit(q, transport, SCTP_RTXR_FAST_RTX);
pr_debug("%s: transport:%p, cwnd:%d, ssthresh:%d, "
"flight_size:%d, pba:%d\n", __func__, transport,
transport->cwnd, transport->ssthresh,
transport->flight_size, transport->partial_bytes_acked);
}
}
static int sctp_acked(struct sctp_sackhdr *sack, __u32 tsn)
{
int i;
sctp_sack_variable_t *frags;
__u16 gap;
__u32 ctsn = ntohl(sack->cum_tsn_ack);
if (TSN_lte(tsn, ctsn))
goto pass;
frags = sack->variable;
gap = tsn - ctsn;
for (i = 0; i < ntohs(sack->num_gap_ack_blocks); ++i) {
if (TSN_lte(ntohs(frags[i].gab.start), gap) &&
TSN_lte(gap, ntohs(frags[i].gab.end)))
goto pass;
}
return 0;
pass:
return 1;
}
static inline int sctp_get_skip_pos(struct sctp_fwdtsn_skip *skiplist,
int nskips, __be16 stream)
{
int i;
for (i = 0; i < nskips; i++) {
if (skiplist[i].stream == stream)
return i;
}
return i;
}
static void sctp_generate_fwdtsn(struct sctp_outq *q, __u32 ctsn)
{
struct sctp_association *asoc = q->asoc;
struct sctp_chunk *ftsn_chunk = NULL;
struct sctp_fwdtsn_skip ftsn_skip_arr[10];
int nskips = 0;
int skip_pos = 0;
__u32 tsn;
struct sctp_chunk *chunk;
struct list_head *lchunk, *temp;
if (!asoc->peer.prsctp_capable)
return;
if (TSN_lt(asoc->adv_peer_ack_point, ctsn))
asoc->adv_peer_ack_point = ctsn;
list_for_each_safe(lchunk, temp, &q->abandoned) {
chunk = list_entry(lchunk, struct sctp_chunk,
transmitted_list);
tsn = ntohl(chunk->subh.data_hdr->tsn);
if (TSN_lte(tsn, ctsn)) {
list_del_init(lchunk);
sctp_chunk_free(chunk);
} else {
if (TSN_lte(tsn, asoc->adv_peer_ack_point+1)) {
asoc->adv_peer_ack_point = tsn;
if (chunk->chunk_hdr->flags &
SCTP_DATA_UNORDERED)
continue;
skip_pos = sctp_get_skip_pos(&ftsn_skip_arr[0],
nskips,
chunk->subh.data_hdr->stream);
ftsn_skip_arr[skip_pos].stream =
chunk->subh.data_hdr->stream;
ftsn_skip_arr[skip_pos].ssn =
chunk->subh.data_hdr->ssn;
if (skip_pos == nskips)
nskips++;
if (nskips == 10)
break;
} else
break;
}
}
if (asoc->adv_peer_ack_point > ctsn)
ftsn_chunk = sctp_make_fwdtsn(asoc, asoc->adv_peer_ack_point,
nskips, &ftsn_skip_arr[0]);
if (ftsn_chunk) {
list_add_tail(&ftsn_chunk->list, &q->control_chunk_list);
SCTP_INC_STATS(sock_net(asoc->base.sk), SCTP_MIB_OUTCTRLCHUNKS);
}
}
