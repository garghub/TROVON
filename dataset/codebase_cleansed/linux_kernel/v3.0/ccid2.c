static int ccid2_hc_tx_alloc_seq(struct ccid2_hc_tx_sock *hc)
{
struct ccid2_seq *seqp;
int i;
if (hc->tx_seqbufc >= (sizeof(hc->tx_seqbuf) /
sizeof(struct ccid2_seq *)))
return -ENOMEM;
seqp = kmalloc(CCID2_SEQBUF_LEN * sizeof(struct ccid2_seq), gfp_any());
if (seqp == NULL)
return -ENOMEM;
for (i = 0; i < (CCID2_SEQBUF_LEN - 1); i++) {
seqp[i].ccid2s_next = &seqp[i + 1];
seqp[i + 1].ccid2s_prev = &seqp[i];
}
seqp[CCID2_SEQBUF_LEN - 1].ccid2s_next = seqp;
seqp->ccid2s_prev = &seqp[CCID2_SEQBUF_LEN - 1];
if (hc->tx_seqbufc == 0)
hc->tx_seqh = hc->tx_seqt = seqp;
else {
hc->tx_seqh->ccid2s_next = seqp;
seqp->ccid2s_prev = hc->tx_seqh;
hc->tx_seqt->ccid2s_prev = &seqp[CCID2_SEQBUF_LEN - 1];
seqp[CCID2_SEQBUF_LEN - 1].ccid2s_next = hc->tx_seqt;
}
hc->tx_seqbuf[hc->tx_seqbufc] = seqp;
hc->tx_seqbufc++;
return 0;
}
static int ccid2_hc_tx_send_packet(struct sock *sk, struct sk_buff *skb)
{
if (ccid2_cwnd_network_limited(ccid2_hc_tx_sk(sk)))
return CCID_PACKET_WILL_DEQUEUE_LATER;
return CCID_PACKET_SEND_AT_ONCE;
}
static void ccid2_change_l_ack_ratio(struct sock *sk, u32 val)
{
struct dccp_sock *dp = dccp_sk(sk);
u32 max_ratio = DIV_ROUND_UP(ccid2_hc_tx_sk(sk)->tx_cwnd, 2);
if (val == 0 || val > max_ratio) {
DCCP_WARN("Limiting Ack Ratio (%u) to %u\n", val, max_ratio);
val = max_ratio;
}
if (val > DCCPF_ACK_RATIO_MAX)
val = DCCPF_ACK_RATIO_MAX;
if (val == dp->dccps_l_ack_ratio)
return;
ccid2_pr_debug("changing local ack ratio to %u\n", val);
dp->dccps_l_ack_ratio = val;
}
static void ccid2_hc_tx_rto_expire(unsigned long data)
{
struct sock *sk = (struct sock *)data;
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
const bool sender_was_blocked = ccid2_cwnd_network_limited(hc);
bh_lock_sock(sk);
if (sock_owned_by_user(sk)) {
sk_reset_timer(sk, &hc->tx_rtotimer, jiffies + HZ / 5);
goto out;
}
ccid2_pr_debug("RTO_EXPIRE\n");
hc->tx_rto <<= 1;
if (hc->tx_rto > DCCP_RTO_MAX)
hc->tx_rto = DCCP_RTO_MAX;
hc->tx_ssthresh = hc->tx_cwnd / 2;
if (hc->tx_ssthresh < 2)
hc->tx_ssthresh = 2;
hc->tx_cwnd = 1;
hc->tx_pipe = 0;
hc->tx_seqt = hc->tx_seqh;
hc->tx_packets_acked = 0;
hc->tx_rpseq = 0;
hc->tx_rpdupack = -1;
ccid2_change_l_ack_ratio(sk, 1);
if (sender_was_blocked)
tasklet_schedule(&dccp_sk(sk)->dccps_xmitlet);
sk_reset_timer(sk, &hc->tx_rtotimer, jiffies + hc->tx_rto);
out:
bh_unlock_sock(sk);
sock_put(sk);
}
static void ccid2_hc_tx_packet_sent(struct sock *sk, unsigned int len)
{
struct dccp_sock *dp = dccp_sk(sk);
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
struct ccid2_seq *next;
hc->tx_pipe++;
hc->tx_seqh->ccid2s_seq = dp->dccps_gss;
hc->tx_seqh->ccid2s_acked = 0;
hc->tx_seqh->ccid2s_sent = ccid2_time_stamp;
next = hc->tx_seqh->ccid2s_next;
if (next == hc->tx_seqt) {
if (ccid2_hc_tx_alloc_seq(hc)) {
DCCP_CRIT("packet history - out of memory!");
return;
}
next = hc->tx_seqh->ccid2s_next;
BUG_ON(next == hc->tx_seqt);
}
hc->tx_seqh = next;
ccid2_pr_debug("cwnd=%d pipe=%d\n", hc->tx_cwnd, hc->tx_pipe);
#if 0
hc->tx_arsent++;
if (hc->tx_ackloss) {
if (hc->tx_arsent >= hc->tx_cwnd) {
hc->tx_arsent = 0;
hc->tx_ackloss = 0;
}
} else {
if (dp->dccps_l_ack_ratio > 1) {
int denom = dp->dccps_l_ack_ratio * dp->dccps_l_ack_ratio -
dp->dccps_l_ack_ratio;
denom = hc->tx_cwnd * hc->tx_cwnd / denom;
if (hc->tx_arsent >= denom) {
ccid2_change_l_ack_ratio(sk, dp->dccps_l_ack_ratio - 1);
hc->tx_arsent = 0;
}
} else {
hc->tx_arsent = 0;
}
}
#endif
sk_reset_timer(sk, &hc->tx_rtotimer, jiffies + hc->tx_rto);
#ifdef CONFIG_IP_DCCP_CCID2_DEBUG
do {
struct ccid2_seq *seqp = hc->tx_seqt;
while (seqp != hc->tx_seqh) {
ccid2_pr_debug("out seq=%llu acked=%d time=%u\n",
(unsigned long long)seqp->ccid2s_seq,
seqp->ccid2s_acked, seqp->ccid2s_sent);
seqp = seqp->ccid2s_next;
}
} while (0);
ccid2_pr_debug("=========\n");
#endif
}
static void ccid2_rtt_estimator(struct sock *sk, const long mrtt)
{
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
long m = mrtt ? : 1;
if (hc->tx_srtt == 0) {
hc->tx_srtt = m << 3;
hc->tx_mdev = m << 1;
hc->tx_mdev_max = max(hc->tx_mdev, tcp_rto_min(sk));
hc->tx_rttvar = hc->tx_mdev_max;
hc->tx_rtt_seq = dccp_sk(sk)->dccps_gss;
} else {
m -= (hc->tx_srtt >> 3);
hc->tx_srtt += m;
if (m < 0) {
m = -m;
m -= (hc->tx_mdev >> 2);
if (m > 0)
m >>= 3;
} else {
m -= (hc->tx_mdev >> 2);
}
hc->tx_mdev += m;
if (hc->tx_mdev > hc->tx_mdev_max) {
hc->tx_mdev_max = hc->tx_mdev;
if (hc->tx_mdev_max > hc->tx_rttvar)
hc->tx_rttvar = hc->tx_mdev_max;
}
if (after48(dccp_sk(sk)->dccps_gar, hc->tx_rtt_seq)) {
if (hc->tx_mdev_max < hc->tx_rttvar)
hc->tx_rttvar -= (hc->tx_rttvar -
hc->tx_mdev_max) >> 2;
hc->tx_rtt_seq = dccp_sk(sk)->dccps_gss;
hc->tx_mdev_max = tcp_rto_min(sk);
}
}
hc->tx_rto = (hc->tx_srtt >> 3) + hc->tx_rttvar;
if (hc->tx_rto > DCCP_RTO_MAX)
hc->tx_rto = DCCP_RTO_MAX;
}
static void ccid2_new_ack(struct sock *sk, struct ccid2_seq *seqp,
unsigned int *maxincr)
{
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
if (hc->tx_cwnd < hc->tx_ssthresh) {
if (*maxincr > 0 && ++hc->tx_packets_acked == 2) {
hc->tx_cwnd += 1;
*maxincr -= 1;
hc->tx_packets_acked = 0;
}
} else if (++hc->tx_packets_acked >= hc->tx_cwnd) {
hc->tx_cwnd += 1;
hc->tx_packets_acked = 0;
}
ccid2_rtt_estimator(sk, ccid2_time_stamp - seqp->ccid2s_sent);
}
static void ccid2_congestion_event(struct sock *sk, struct ccid2_seq *seqp)
{
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
if ((s32)(seqp->ccid2s_sent - hc->tx_last_cong) < 0) {
ccid2_pr_debug("Multiple losses in an RTT---treating as one\n");
return;
}
hc->tx_last_cong = ccid2_time_stamp;
hc->tx_cwnd = hc->tx_cwnd / 2 ? : 1U;
hc->tx_ssthresh = max(hc->tx_cwnd, 2U);
if (dccp_sk(sk)->dccps_l_ack_ratio > hc->tx_cwnd)
ccid2_change_l_ack_ratio(sk, hc->tx_cwnd);
}
static int ccid2_hc_tx_parse_options(struct sock *sk, u8 packet_type,
u8 option, u8 *optval, u8 optlen)
{
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
switch (option) {
case DCCPO_ACK_VECTOR_0:
case DCCPO_ACK_VECTOR_1:
return dccp_ackvec_parsed_add(&hc->tx_av_chunks, optval, optlen,
option - DCCPO_ACK_VECTOR_0);
}
return 0;
}
static void ccid2_hc_tx_packet_recv(struct sock *sk, struct sk_buff *skb)
{
struct dccp_sock *dp = dccp_sk(sk);
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
const bool sender_was_blocked = ccid2_cwnd_network_limited(hc);
struct dccp_ackvec_parsed *avp;
u64 ackno, seqno;
struct ccid2_seq *seqp;
int done = 0;
unsigned int maxincr = 0;
seqno = DCCP_SKB_CB(skb)->dccpd_seq;
if (hc->tx_rpdupack == -1) {
hc->tx_rpdupack = 0;
hc->tx_rpseq = seqno;
} else {
if (dccp_delta_seqno(hc->tx_rpseq, seqno) == 1)
hc->tx_rpseq = seqno;
else if (after48(seqno, hc->tx_rpseq)) {
hc->tx_rpdupack++;
if (hc->tx_rpdupack >= NUMDUPACK) {
hc->tx_rpdupack = -1;
hc->tx_rpseq = 0;
ccid2_change_l_ack_ratio(sk, 2 * dp->dccps_l_ack_ratio);
}
}
}
if (dccp_packet_without_ack(skb))
return;
if (hc->tx_seqh == hc->tx_seqt)
goto done;
ackno = DCCP_SKB_CB(skb)->dccpd_ack_seq;
if (after48(ackno, hc->tx_high_ack))
hc->tx_high_ack = ackno;
seqp = hc->tx_seqt;
while (before48(seqp->ccid2s_seq, ackno)) {
seqp = seqp->ccid2s_next;
if (seqp == hc->tx_seqh) {
seqp = hc->tx_seqh->ccid2s_prev;
break;
}
}
if (hc->tx_cwnd < hc->tx_ssthresh)
maxincr = DIV_ROUND_UP(dp->dccps_l_ack_ratio, 2);
list_for_each_entry(avp, &hc->tx_av_chunks, node) {
for (; avp->len--; avp->vec++) {
u64 ackno_end_rl = SUB48(ackno,
dccp_ackvec_runlen(avp->vec));
ccid2_pr_debug("ackvec %llu |%u,%u|\n",
(unsigned long long)ackno,
dccp_ackvec_state(avp->vec) >> 6,
dccp_ackvec_runlen(avp->vec));
while (after48(seqp->ccid2s_seq, ackno)) {
if (seqp == hc->tx_seqt) {
done = 1;
break;
}
seqp = seqp->ccid2s_prev;
}
if (done)
break;
while (between48(seqp->ccid2s_seq,ackno_end_rl,ackno)) {
const u8 state = dccp_ackvec_state(avp->vec);
if (state != DCCPAV_NOT_RECEIVED &&
!seqp->ccid2s_acked) {
if (state == DCCPAV_ECN_MARKED)
ccid2_congestion_event(sk,
seqp);
else
ccid2_new_ack(sk, seqp,
&maxincr);
seqp->ccid2s_acked = 1;
ccid2_pr_debug("Got ack for %llu\n",
(unsigned long long)seqp->ccid2s_seq);
hc->tx_pipe--;
}
if (seqp == hc->tx_seqt) {
done = 1;
break;
}
seqp = seqp->ccid2s_prev;
}
if (done)
break;
ackno = SUB48(ackno_end_rl, 1);
}
if (done)
break;
}
seqp = hc->tx_seqt;
while (before48(seqp->ccid2s_seq, hc->tx_high_ack)) {
seqp = seqp->ccid2s_next;
if (seqp == hc->tx_seqh) {
seqp = hc->tx_seqh->ccid2s_prev;
break;
}
}
done = 0;
while (1) {
if (seqp->ccid2s_acked) {
done++;
if (done == NUMDUPACK)
break;
}
if (seqp == hc->tx_seqt)
break;
seqp = seqp->ccid2s_prev;
}
if (done == NUMDUPACK) {
struct ccid2_seq *last_acked = seqp;
while (1) {
if (!seqp->ccid2s_acked) {
ccid2_pr_debug("Packet lost: %llu\n",
(unsigned long long)seqp->ccid2s_seq);
ccid2_congestion_event(sk, seqp);
hc->tx_pipe--;
}
if (seqp == hc->tx_seqt)
break;
seqp = seqp->ccid2s_prev;
}
hc->tx_seqt = last_acked;
}
while (hc->tx_seqt != hc->tx_seqh) {
if (!hc->tx_seqt->ccid2s_acked)
break;
hc->tx_seqt = hc->tx_seqt->ccid2s_next;
}
if (hc->tx_pipe == 0)
sk_stop_timer(sk, &hc->tx_rtotimer);
else
sk_reset_timer(sk, &hc->tx_rtotimer, jiffies + hc->tx_rto);
done:
if (sender_was_blocked && !ccid2_cwnd_network_limited(hc))
tasklet_schedule(&dccp_sk(sk)->dccps_xmitlet);
dccp_ackvec_parsed_cleanup(&hc->tx_av_chunks);
}
static inline u32 rfc3390_bytes_to_packets(const u32 smss)
{
return smss <= 1095 ? 4 : (smss > 2190 ? 2 : 3);
}
static int ccid2_hc_tx_init(struct ccid *ccid, struct sock *sk)
{
struct ccid2_hc_tx_sock *hc = ccid_priv(ccid);
struct dccp_sock *dp = dccp_sk(sk);
u32 max_ratio;
hc->tx_ssthresh = ~0U;
hc->tx_cwnd = rfc3390_bytes_to_packets(dp->dccps_mss_cache);
max_ratio = DIV_ROUND_UP(hc->tx_cwnd, 2);
if (dp->dccps_l_ack_ratio == 0 || dp->dccps_l_ack_ratio > max_ratio)
dp->dccps_l_ack_ratio = max_ratio;
if (ccid2_hc_tx_alloc_seq(hc))
return -ENOMEM;
hc->tx_rto = DCCP_TIMEOUT_INIT;
hc->tx_rpdupack = -1;
hc->tx_last_cong = ccid2_time_stamp;
setup_timer(&hc->tx_rtotimer, ccid2_hc_tx_rto_expire,
(unsigned long)sk);
INIT_LIST_HEAD(&hc->tx_av_chunks);
return 0;
}
static void ccid2_hc_tx_exit(struct sock *sk)
{
struct ccid2_hc_tx_sock *hc = ccid2_hc_tx_sk(sk);
int i;
sk_stop_timer(sk, &hc->tx_rtotimer);
for (i = 0; i < hc->tx_seqbufc; i++)
kfree(hc->tx_seqbuf[i]);
hc->tx_seqbufc = 0;
}
static void ccid2_hc_rx_packet_recv(struct sock *sk, struct sk_buff *skb)
{
const struct dccp_sock *dp = dccp_sk(sk);
struct ccid2_hc_rx_sock *hc = ccid2_hc_rx_sk(sk);
switch (DCCP_SKB_CB(skb)->dccpd_type) {
case DCCP_PKT_DATA:
case DCCP_PKT_DATAACK:
hc->rx_data++;
if (hc->rx_data >= dp->dccps_r_ack_ratio) {
dccp_send_ack(sk);
hc->rx_data = 0;
}
break;
}
}
