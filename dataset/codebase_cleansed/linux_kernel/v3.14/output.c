static void sctp_packet_reset(struct sctp_packet *packet)
{
packet->size = packet->overhead;
packet->has_cookie_echo = 0;
packet->has_sack = 0;
packet->has_data = 0;
packet->has_auth = 0;
packet->ipfragok = 0;
packet->auth = NULL;
}
struct sctp_packet *sctp_packet_config(struct sctp_packet *packet,
__u32 vtag, int ecn_capable)
{
struct sctp_chunk *chunk = NULL;
pr_debug("%s: packet:%p vtag:0x%x\n", __func__, packet, vtag);
packet->vtag = vtag;
if (ecn_capable && sctp_packet_empty(packet)) {
chunk = sctp_get_ecne_prepend(packet->transport->asoc);
if (chunk)
sctp_packet_append_chunk(packet, chunk);
}
return packet;
}
struct sctp_packet *sctp_packet_init(struct sctp_packet *packet,
struct sctp_transport *transport,
__u16 sport, __u16 dport)
{
struct sctp_association *asoc = transport->asoc;
size_t overhead;
pr_debug("%s: packet:%p transport:%p\n", __func__, packet, transport);
packet->transport = transport;
packet->source_port = sport;
packet->destination_port = dport;
INIT_LIST_HEAD(&packet->chunk_list);
if (asoc) {
struct sctp_sock *sp = sctp_sk(asoc->base.sk);
overhead = sp->pf->af->net_header_len;
} else {
overhead = sizeof(struct ipv6hdr);
}
overhead += sizeof(struct sctphdr);
packet->overhead = overhead;
sctp_packet_reset(packet);
packet->vtag = 0;
return packet;
}
void sctp_packet_free(struct sctp_packet *packet)
{
struct sctp_chunk *chunk, *tmp;
pr_debug("%s: packet:%p\n", __func__, packet);
list_for_each_entry_safe(chunk, tmp, &packet->chunk_list, list) {
list_del_init(&chunk->list);
sctp_chunk_free(chunk);
}
}
sctp_xmit_t sctp_packet_transmit_chunk(struct sctp_packet *packet,
struct sctp_chunk *chunk,
int one_packet)
{
sctp_xmit_t retval;
int error = 0;
pr_debug("%s: packet:%p chunk:%p\n", __func__, packet, chunk);
switch ((retval = (sctp_packet_append_chunk(packet, chunk)))) {
case SCTP_XMIT_PMTU_FULL:
if (!packet->has_cookie_echo) {
error = sctp_packet_transmit(packet);
if (error < 0)
chunk->skb->sk->sk_err = -error;
if (!one_packet)
retval = sctp_packet_append_chunk(packet,
chunk);
}
break;
case SCTP_XMIT_RWND_FULL:
case SCTP_XMIT_OK:
case SCTP_XMIT_NAGLE_DELAY:
break;
}
return retval;
}
static sctp_xmit_t sctp_packet_bundle_auth(struct sctp_packet *pkt,
struct sctp_chunk *chunk)
{
struct sctp_association *asoc = pkt->transport->asoc;
struct sctp_chunk *auth;
sctp_xmit_t retval = SCTP_XMIT_OK;
if (!asoc)
return retval;
if (chunk->chunk_hdr->type == SCTP_CID_AUTH || pkt->has_auth)
return retval;
if (!chunk->auth)
return retval;
auth = sctp_make_auth(asoc);
if (!auth)
return retval;
retval = __sctp_packet_append_chunk(pkt, auth);
if (retval != SCTP_XMIT_OK)
sctp_chunk_free(auth);
return retval;
}
static sctp_xmit_t sctp_packet_bundle_sack(struct sctp_packet *pkt,
struct sctp_chunk *chunk)
{
sctp_xmit_t retval = SCTP_XMIT_OK;
if (sctp_chunk_is_data(chunk) && !pkt->has_sack &&
!pkt->has_cookie_echo) {
struct sctp_association *asoc;
struct timer_list *timer;
asoc = pkt->transport->asoc;
timer = &asoc->timers[SCTP_EVENT_TIMEOUT_SACK];
if (timer_pending(timer)) {
struct sctp_chunk *sack;
if (pkt->transport->sack_generation !=
pkt->transport->asoc->peer.sack_generation)
return retval;
asoc->a_rwnd = asoc->rwnd;
sack = sctp_make_sack(asoc);
if (sack) {
retval = __sctp_packet_append_chunk(pkt, sack);
if (retval != SCTP_XMIT_OK) {
sctp_chunk_free(sack);
goto out;
}
asoc->peer.sack_needed = 0;
if (del_timer(timer))
sctp_association_put(asoc);
}
}
}
out:
return retval;
}
static sctp_xmit_t __sctp_packet_append_chunk(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
sctp_xmit_t retval = SCTP_XMIT_OK;
__u16 chunk_len = WORD_ROUND(ntohs(chunk->chunk_hdr->length));
retval = sctp_packet_will_fit(packet, chunk, chunk_len);
if (retval != SCTP_XMIT_OK)
goto finish;
switch (chunk->chunk_hdr->type) {
case SCTP_CID_DATA:
sctp_packet_append_data(packet, chunk);
packet->has_sack = 1;
packet->has_auth = 1;
packet->has_data = 1;
chunk->sent_at = jiffies;
break;
case SCTP_CID_COOKIE_ECHO:
packet->has_cookie_echo = 1;
break;
case SCTP_CID_SACK:
packet->has_sack = 1;
if (chunk->asoc)
chunk->asoc->stats.osacks++;
break;
case SCTP_CID_AUTH:
packet->has_auth = 1;
packet->auth = chunk;
break;
}
list_add_tail(&chunk->list, &packet->chunk_list);
packet->size += chunk_len;
chunk->transport = packet->transport;
finish:
return retval;
}
sctp_xmit_t sctp_packet_append_chunk(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
sctp_xmit_t retval = SCTP_XMIT_OK;
pr_debug("%s: packet:%p chunk:%p\n", __func__, packet, chunk);
if (sctp_chunk_is_data(chunk)) {
retval = sctp_packet_can_append_data(packet, chunk);
if (retval != SCTP_XMIT_OK)
goto finish;
}
retval = sctp_packet_bundle_auth(packet, chunk);
if (retval != SCTP_XMIT_OK)
goto finish;
retval = sctp_packet_bundle_sack(packet, chunk);
if (retval != SCTP_XMIT_OK)
goto finish;
retval = __sctp_packet_append_chunk(packet, chunk);
finish:
return retval;
}
static void sctp_packet_release_owner(struct sk_buff *skb)
{
sk_free(skb->sk);
}
static void sctp_packet_set_owner_w(struct sk_buff *skb, struct sock *sk)
{
skb_orphan(skb);
skb->sk = sk;
skb->destructor = sctp_packet_release_owner;
atomic_inc(&sk->sk_wmem_alloc);
}
int sctp_packet_transmit(struct sctp_packet *packet)
{
struct sctp_transport *tp = packet->transport;
struct sctp_association *asoc = tp->asoc;
struct sctphdr *sh;
struct sk_buff *nskb;
struct sctp_chunk *chunk, *tmp;
struct sock *sk;
int err = 0;
int padding;
__u8 has_data = 0;
struct dst_entry *dst;
unsigned char *auth = NULL;
pr_debug("%s: packet:%p\n", __func__, packet);
if (list_empty(&packet->chunk_list))
return err;
chunk = list_entry(packet->chunk_list.next, struct sctp_chunk, list);
sk = chunk->skb->sk;
nskb = alloc_skb(packet->size + LL_MAX_HEADER, GFP_ATOMIC);
if (!nskb)
goto nomem;
skb_reserve(nskb, packet->overhead + LL_MAX_HEADER);
sctp_packet_set_owner_w(nskb, sk);
if (!sctp_transport_dst_check(tp)) {
sctp_transport_route(tp, NULL, sctp_sk(sk));
if (asoc && (asoc->param_flags & SPP_PMTUD_ENABLE)) {
sctp_assoc_sync_pmtu(sk, asoc);
}
}
dst = dst_clone(tp->dst);
if (!dst)
goto no_route;
skb_dst_set(nskb, dst);
sh = (struct sctphdr *)skb_push(nskb, sizeof(struct sctphdr));
skb_reset_transport_header(nskb);
sh->source = htons(packet->source_port);
sh->dest = htons(packet->destination_port);
sh->vtag = htonl(packet->vtag);
sh->checksum = 0;
pr_debug("***sctp_transmit_packet***\n");
list_for_each_entry_safe(chunk, tmp, &packet->chunk_list, list) {
list_del_init(&chunk->list);
if (sctp_chunk_is_data(chunk)) {
if (!chunk->resent && !tp->rto_pending) {
chunk->rtt_in_progress = 1;
tp->rto_pending = 1;
}
has_data = 1;
}
padding = WORD_ROUND(chunk->skb->len) - chunk->skb->len;
if (padding)
memset(skb_put(chunk->skb, padding), 0, padding);
if (chunk == packet->auth)
auth = skb_tail_pointer(nskb);
memcpy(skb_put(nskb, chunk->skb->len),
chunk->skb->data, chunk->skb->len);
pr_debug("*** Chunk:%p[%s] %s 0x%x, length:%d, chunk->skb->len:%d, "
"rtt_in_progress:%d\n", chunk,
sctp_cname(SCTP_ST_CHUNK(chunk->chunk_hdr->type)),
chunk->has_tsn ? "TSN" : "No TSN",
chunk->has_tsn ? ntohl(chunk->subh.data_hdr->tsn) : 0,
ntohs(chunk->chunk_hdr->length), chunk->skb->len,
chunk->rtt_in_progress);
if (!sctp_chunk_is_data(chunk))
sctp_chunk_free(chunk);
}
if (auth)
sctp_auth_calculate_hmac(asoc, nskb,
(struct sctp_auth_chunk *)auth,
GFP_ATOMIC);
if (!sctp_checksum_disable) {
if (!(dst->dev->features & NETIF_F_SCTP_CSUM) ||
(dst_xfrm(dst) != NULL) || packet->ipfragok) {
sh->checksum = sctp_compute_cksum(nskb, 0);
} else {
nskb->ip_summed = CHECKSUM_PARTIAL;
nskb->csum_start = skb_transport_header(nskb) - nskb->head;
nskb->csum_offset = offsetof(struct sctphdr, checksum);
}
}
tp->af_specific->ecn_capable(nskb->sk);
if (asoc) {
asoc->stats.opackets++;
if (asoc->peer.last_sent_to != tp)
asoc->peer.last_sent_to = tp;
}
if (has_data) {
struct timer_list *timer;
unsigned long timeout;
if (sctp_state(asoc, ESTABLISHED) &&
asoc->timeouts[SCTP_EVENT_TIMEOUT_AUTOCLOSE]) {
timer = &asoc->timers[SCTP_EVENT_TIMEOUT_AUTOCLOSE];
timeout = asoc->timeouts[SCTP_EVENT_TIMEOUT_AUTOCLOSE];
if (!mod_timer(timer, jiffies + timeout))
sctp_association_hold(asoc);
}
}
pr_debug("***sctp_transmit_packet*** skb->len:%d\n", nskb->len);
nskb->local_df = packet->ipfragok;
tp->af_specific->sctp_xmit(nskb, tp);
out:
sctp_packet_reset(packet);
return err;
no_route:
kfree_skb(nskb);
IP_INC_STATS_BH(sock_net(asoc->base.sk), IPSTATS_MIB_OUTNOROUTES);
err:
list_for_each_entry_safe(chunk, tmp, &packet->chunk_list, list) {
list_del_init(&chunk->list);
if (!sctp_chunk_is_data(chunk))
sctp_chunk_free(chunk);
}
goto out;
nomem:
err = -ENOMEM;
goto err;
}
static sctp_xmit_t sctp_packet_can_append_data(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
sctp_xmit_t retval = SCTP_XMIT_OK;
size_t datasize, rwnd, inflight, flight_size;
struct sctp_transport *transport = packet->transport;
struct sctp_association *asoc = transport->asoc;
struct sctp_outq *q = &asoc->outqueue;
rwnd = asoc->peer.rwnd;
inflight = q->outstanding_bytes;
flight_size = transport->flight_size;
datasize = sctp_data_size(chunk);
if (datasize > rwnd) {
if (inflight > 0) {
retval = SCTP_XMIT_RWND_FULL;
goto finish;
}
}
if (chunk->fast_retransmit != SCTP_NEED_FRTX)
if (flight_size >= transport->cwnd) {
retval = SCTP_XMIT_RWND_FULL;
goto finish;
}
if (!sctp_sk(asoc->base.sk)->nodelay && sctp_packet_empty(packet) &&
inflight && sctp_state(asoc, ESTABLISHED)) {
unsigned int max = transport->pathmtu - packet->overhead;
unsigned int len = chunk->skb->len + q->out_qlen;
if ((len < max) && chunk->msg->can_delay) {
retval = SCTP_XMIT_NAGLE_DELAY;
goto finish;
}
}
finish:
return retval;
}
static void sctp_packet_append_data(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
struct sctp_transport *transport = packet->transport;
size_t datasize = sctp_data_size(chunk);
struct sctp_association *asoc = transport->asoc;
u32 rwnd = asoc->peer.rwnd;
transport->flight_size += datasize;
asoc->outqueue.outstanding_bytes += datasize;
if (datasize < rwnd)
rwnd -= datasize;
else
rwnd = 0;
asoc->peer.rwnd = rwnd;
if (!asoc->peer.prsctp_capable)
chunk->msg->can_abandon = 0;
sctp_chunk_assign_tsn(chunk);
sctp_chunk_assign_ssn(chunk);
}
static sctp_xmit_t sctp_packet_will_fit(struct sctp_packet *packet,
struct sctp_chunk *chunk,
u16 chunk_len)
{
size_t psize;
size_t pmtu;
int too_big;
sctp_xmit_t retval = SCTP_XMIT_OK;
psize = packet->size;
pmtu = ((packet->transport->asoc) ?
(packet->transport->asoc->pathmtu) :
(packet->transport->pathmtu));
too_big = (psize + chunk_len > pmtu);
if (too_big) {
if (sctp_packet_empty(packet) || !sctp_chunk_is_data(chunk) ||
(!packet->has_data && chunk->auth)) {
packet->ipfragok = 1;
} else {
retval = SCTP_XMIT_PMTU_FULL;
}
}
return retval;
}
