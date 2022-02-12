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
void sctp_packet_config(struct sctp_packet *packet, __u32 vtag,
int ecn_capable)
{
struct sctp_transport *tp = packet->transport;
struct sctp_association *asoc = tp->asoc;
struct sock *sk;
pr_debug("%s: packet:%p vtag:0x%x\n", __func__, packet, vtag);
packet->vtag = vtag;
if (!sctp_packet_empty(packet))
return;
packet->max_size = tp->pathmtu;
if (!asoc)
return;
sk = asoc->base.sk;
if (!sctp_transport_dst_check(tp)) {
sctp_transport_route(tp, NULL, sctp_sk(sk));
if (asoc->param_flags & SPP_PMTUD_ENABLE)
sctp_assoc_sync_pmtu(asoc);
} else if (!sctp_transport_pmtu_check(tp)) {
if (asoc->param_flags & SPP_PMTUD_ENABLE)
sctp_assoc_sync_pmtu(asoc);
}
if (ecn_capable) {
struct sctp_chunk *chunk = sctp_get_ecne_prepend(asoc);
if (chunk)
sctp_packet_append_chunk(packet, chunk);
}
if (!tp->dst)
return;
rcu_read_lock();
if (__sk_dst_get(sk) != tp->dst) {
dst_hold(tp->dst);
sk_setup_caps(sk, tp->dst);
}
packet->max_size = sk_can_gso(sk) ? tp->dst->dev->gso_max_size
: asoc->pathmtu;
rcu_read_unlock();
}
void sctp_packet_init(struct sctp_packet *packet,
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
enum sctp_xmit sctp_packet_transmit_chunk(struct sctp_packet *packet,
struct sctp_chunk *chunk,
int one_packet, gfp_t gfp)
{
enum sctp_xmit retval;
pr_debug("%s: packet:%p size:%zu chunk:%p size:%d\n", __func__,
packet, packet->size, chunk, chunk->skb ? chunk->skb->len : -1);
switch ((retval = (sctp_packet_append_chunk(packet, chunk)))) {
case SCTP_XMIT_PMTU_FULL:
if (!packet->has_cookie_echo) {
int error = 0;
error = sctp_packet_transmit(packet, gfp);
if (error < 0)
chunk->skb->sk->sk_err = -error;
if (!one_packet)
retval = sctp_packet_append_chunk(packet,
chunk);
}
break;
case SCTP_XMIT_RWND_FULL:
case SCTP_XMIT_OK:
case SCTP_XMIT_DELAY:
break;
}
return retval;
}
static enum sctp_xmit sctp_packet_bundle_auth(struct sctp_packet *pkt,
struct sctp_chunk *chunk)
{
struct sctp_association *asoc = pkt->transport->asoc;
enum sctp_xmit retval = SCTP_XMIT_OK;
struct sctp_chunk *auth;
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
static enum sctp_xmit sctp_packet_bundle_sack(struct sctp_packet *pkt,
struct sctp_chunk *chunk)
{
enum sctp_xmit retval = SCTP_XMIT_OK;
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
static enum sctp_xmit __sctp_packet_append_chunk(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
__u16 chunk_len = SCTP_PAD4(ntohs(chunk->chunk_hdr->length));
enum sctp_xmit retval = SCTP_XMIT_OK;
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
chunk->sent_count++;
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
enum sctp_xmit sctp_packet_append_chunk(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
enum sctp_xmit retval = SCTP_XMIT_OK;
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
refcount_inc(&sk->sk_wmem_alloc);
}
static int sctp_packet_pack(struct sctp_packet *packet,
struct sk_buff *head, int gso, gfp_t gfp)
{
struct sctp_transport *tp = packet->transport;
struct sctp_auth_chunk *auth = NULL;
struct sctp_chunk *chunk, *tmp;
int pkt_count = 0, pkt_size;
struct sock *sk = head->sk;
struct sk_buff *nskb;
int auth_len = 0;
if (gso) {
skb_shinfo(head)->gso_type = sk->sk_gso_type;
NAPI_GRO_CB(head)->last = head;
} else {
nskb = head;
pkt_size = packet->size;
goto merge;
}
do {
pkt_size = packet->overhead;
list_for_each_entry_safe(chunk, tmp, &packet->chunk_list,
list) {
int padded = SCTP_PAD4(chunk->skb->len);
if (chunk == packet->auth)
auth_len = padded;
else if (auth_len + padded + packet->overhead >
tp->pathmtu)
return 0;
else if (pkt_size + padded > tp->pathmtu)
break;
pkt_size += padded;
}
nskb = alloc_skb(pkt_size + MAX_HEADER, gfp);
if (!nskb)
return 0;
skb_reserve(nskb, packet->overhead + MAX_HEADER);
merge:
pkt_size -= packet->overhead;
list_for_each_entry_safe(chunk, tmp, &packet->chunk_list, list) {
int padding;
list_del_init(&chunk->list);
if (sctp_chunk_is_data(chunk)) {
if (!sctp_chunk_retransmitted(chunk) &&
!tp->rto_pending) {
chunk->rtt_in_progress = 1;
tp->rto_pending = 1;
}
}
padding = SCTP_PAD4(chunk->skb->len) - chunk->skb->len;
if (padding)
skb_put_zero(chunk->skb, padding);
if (chunk == packet->auth)
auth = (struct sctp_auth_chunk *)
skb_tail_pointer(nskb);
skb_put_data(nskb, chunk->skb->data, chunk->skb->len);
pr_debug("*** Chunk:%p[%s] %s 0x%x, length:%d, chunk->skb->len:%d, rtt_in_progress:%d\n",
chunk,
sctp_cname(SCTP_ST_CHUNK(chunk->chunk_hdr->type)),
chunk->has_tsn ? "TSN" : "No TSN",
chunk->has_tsn ? ntohl(chunk->subh.data_hdr->tsn) : 0,
ntohs(chunk->chunk_hdr->length), chunk->skb->len,
chunk->rtt_in_progress);
pkt_size -= SCTP_PAD4(chunk->skb->len);
if (!sctp_chunk_is_data(chunk) && chunk != packet->auth)
sctp_chunk_free(chunk);
if (!pkt_size)
break;
}
if (auth) {
sctp_auth_calculate_hmac(tp->asoc, nskb, auth, gfp);
if (list_empty(&packet->chunk_list))
sctp_chunk_free(packet->auth);
else
list_add(&packet->auth->list,
&packet->chunk_list);
}
if (gso) {
if (skb_gro_receive(&head, nskb)) {
kfree_skb(nskb);
return 0;
}
if (WARN_ON_ONCE(skb_shinfo(head)->gso_segs >=
sk->sk_gso_max_segs))
return 0;
}
pkt_count++;
} while (!list_empty(&packet->chunk_list));
if (gso) {
memset(head->cb, 0, max(sizeof(struct inet_skb_parm),
sizeof(struct inet6_skb_parm)));
skb_shinfo(head)->gso_segs = pkt_count;
skb_shinfo(head)->gso_size = GSO_BY_FRAGS;
rcu_read_lock();
if (skb_dst(head) != tp->dst) {
dst_hold(tp->dst);
sk_setup_caps(sk, tp->dst);
}
rcu_read_unlock();
goto chksum;
}
if (sctp_checksum_disable)
return 1;
if (!(skb_dst(head)->dev->features & NETIF_F_SCTP_CRC) ||
dst_xfrm(skb_dst(head)) || packet->ipfragok) {
struct sctphdr *sh =
(struct sctphdr *)skb_transport_header(head);
sh->checksum = sctp_compute_cksum(head, 0);
} else {
chksum:
head->ip_summed = CHECKSUM_PARTIAL;
head->csum_not_inet = 1;
head->csum_start = skb_transport_header(head) - head->head;
head->csum_offset = offsetof(struct sctphdr, checksum);
}
return pkt_count;
}
int sctp_packet_transmit(struct sctp_packet *packet, gfp_t gfp)
{
struct sctp_transport *tp = packet->transport;
struct sctp_association *asoc = tp->asoc;
struct sctp_chunk *chunk, *tmp;
int pkt_count, gso = 0;
struct dst_entry *dst;
struct sk_buff *head;
struct sctphdr *sh;
struct sock *sk;
pr_debug("%s: packet:%p\n", __func__, packet);
if (list_empty(&packet->chunk_list))
return 0;
chunk = list_entry(packet->chunk_list.next, struct sctp_chunk, list);
sk = chunk->skb->sk;
if (packet->size > tp->pathmtu && !packet->ipfragok) {
if (!sk_can_gso(sk)) {
pr_err_once("Trying to GSO but underlying device doesn't support it.");
goto out;
}
gso = 1;
}
head = alloc_skb((gso ? packet->overhead : packet->size) +
MAX_HEADER, gfp);
if (!head)
goto out;
skb_reserve(head, packet->overhead + MAX_HEADER);
sctp_packet_set_owner_w(head, sk);
sh = skb_push(head, sizeof(struct sctphdr));
skb_reset_transport_header(head);
sh->source = htons(packet->source_port);
sh->dest = htons(packet->destination_port);
sh->vtag = htonl(packet->vtag);
sh->checksum = 0;
dst = dst_clone(tp->dst);
if (!dst) {
IP_INC_STATS(sock_net(sk), IPSTATS_MIB_OUTNOROUTES);
kfree_skb(head);
goto out;
}
skb_dst_set(head, dst);
pkt_count = sctp_packet_pack(packet, head, gso, gfp);
if (!pkt_count) {
kfree_skb(head);
goto out;
}
pr_debug("***sctp_transmit_packet*** skb->len:%d\n", head->len);
if (packet->has_data && sctp_state(asoc, ESTABLISHED) &&
asoc->timeouts[SCTP_EVENT_TIMEOUT_AUTOCLOSE]) {
struct timer_list *timer =
&asoc->timers[SCTP_EVENT_TIMEOUT_AUTOCLOSE];
unsigned long timeout =
asoc->timeouts[SCTP_EVENT_TIMEOUT_AUTOCLOSE];
if (!mod_timer(timer, jiffies + timeout))
sctp_association_hold(asoc);
}
tp->af_specific->ecn_capable(sk);
if (asoc) {
asoc->stats.opackets += pkt_count;
if (asoc->peer.last_sent_to != tp)
asoc->peer.last_sent_to = tp;
}
head->ignore_df = packet->ipfragok;
if (tp->dst_pending_confirm)
skb_set_dst_pending_confirm(head, 1);
if (tp->af_specific->sctp_xmit(head, tp) >= 0 &&
tp->dst_pending_confirm)
tp->dst_pending_confirm = 0;
out:
list_for_each_entry_safe(chunk, tmp, &packet->chunk_list, list) {
list_del_init(&chunk->list);
if (!sctp_chunk_is_data(chunk))
sctp_chunk_free(chunk);
}
sctp_packet_reset(packet);
return 0;
}
static enum sctp_xmit sctp_packet_can_append_data(struct sctp_packet *packet,
struct sctp_chunk *chunk)
{
size_t datasize, rwnd, inflight, flight_size;
struct sctp_transport *transport = packet->transport;
struct sctp_association *asoc = transport->asoc;
struct sctp_outq *q = &asoc->outqueue;
rwnd = asoc->peer.rwnd;
inflight = q->outstanding_bytes;
flight_size = transport->flight_size;
datasize = sctp_data_size(chunk);
if (datasize > rwnd && inflight > 0)
return SCTP_XMIT_RWND_FULL;
if (chunk->fast_retransmit != SCTP_NEED_FRTX &&
flight_size >= transport->cwnd)
return SCTP_XMIT_RWND_FULL;
if ((sctp_sk(asoc->base.sk)->nodelay || inflight == 0) &&
!asoc->force_delay)
return SCTP_XMIT_OK;
if (!sctp_packet_empty(packet))
return SCTP_XMIT_OK;
if (!sctp_state(asoc, ESTABLISHED))
return SCTP_XMIT_OK;
if (chunk->skb->len + q->out_qlen > transport->pathmtu -
packet->overhead - sizeof(struct sctp_data_chunk) - 4)
return SCTP_XMIT_OK;
if (!chunk->msg->can_delay)
return SCTP_XMIT_OK;
return SCTP_XMIT_DELAY;
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
sctp_chunk_assign_tsn(chunk);
sctp_chunk_assign_ssn(chunk);
}
static enum sctp_xmit sctp_packet_will_fit(struct sctp_packet *packet,
struct sctp_chunk *chunk,
u16 chunk_len)
{
enum sctp_xmit retval = SCTP_XMIT_OK;
size_t psize, pmtu, maxsize;
psize = packet->size;
if (packet->transport->asoc)
pmtu = packet->transport->asoc->pathmtu;
else
pmtu = packet->transport->pathmtu;
if (psize + chunk_len > pmtu) {
if (sctp_packet_empty(packet) ||
(!packet->has_data && chunk->auth)) {
packet->ipfragok = 1;
goto out;
}
maxsize = pmtu - packet->overhead;
if (packet->auth)
maxsize -= SCTP_PAD4(packet->auth->skb->len);
if (chunk_len > maxsize)
retval = SCTP_XMIT_PMTU_FULL;
if (!sctp_chunk_is_data(chunk) && packet->has_data)
retval = SCTP_XMIT_PMTU_FULL;
if (psize + chunk_len > packet->max_size)
retval = SCTP_XMIT_PMTU_FULL;
if (!packet->transport->burst_limited &&
psize + chunk_len > (packet->transport->cwnd >> 1))
retval = SCTP_XMIT_PMTU_FULL;
if (packet->transport->burst_limited &&
psize + chunk_len > (packet->transport->burst_limited >> 1))
retval = SCTP_XMIT_PMTU_FULL;
}
out:
return retval;
}
