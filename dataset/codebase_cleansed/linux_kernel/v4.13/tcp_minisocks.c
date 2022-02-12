static bool tcp_in_window(u32 seq, u32 end_seq, u32 s_win, u32 e_win)
{
if (seq == s_win)
return true;
if (after(end_seq, s_win) && before(seq, e_win))
return true;
return seq == e_win && seq == end_seq;
}
static enum tcp_tw_status
tcp_timewait_check_oow_rate_limit(struct inet_timewait_sock *tw,
const struct sk_buff *skb, int mib_idx)
{
struct tcp_timewait_sock *tcptw = tcp_twsk((struct sock *)tw);
if (!tcp_oow_rate_limited(twsk_net(tw), skb, mib_idx,
&tcptw->tw_last_oow_ack_time)) {
return TCP_TW_ACK;
}
inet_twsk_put(tw);
return TCP_TW_SUCCESS;
}
enum tcp_tw_status
tcp_timewait_state_process(struct inet_timewait_sock *tw, struct sk_buff *skb,
const struct tcphdr *th)
{
struct tcp_options_received tmp_opt;
struct tcp_timewait_sock *tcptw = tcp_twsk((struct sock *)tw);
bool paws_reject = false;
tmp_opt.saw_tstamp = 0;
if (th->doff > (sizeof(*th) >> 2) && tcptw->tw_ts_recent_stamp) {
tcp_parse_options(twsk_net(tw), skb, &tmp_opt, 0, NULL);
if (tmp_opt.saw_tstamp) {
if (tmp_opt.rcv_tsecr)
tmp_opt.rcv_tsecr -= tcptw->tw_ts_offset;
tmp_opt.ts_recent = tcptw->tw_ts_recent;
tmp_opt.ts_recent_stamp = tcptw->tw_ts_recent_stamp;
paws_reject = tcp_paws_reject(&tmp_opt, th->rst);
}
}
if (tw->tw_substate == TCP_FIN_WAIT2) {
if (paws_reject ||
!tcp_in_window(TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb)->end_seq,
tcptw->tw_rcv_nxt,
tcptw->tw_rcv_nxt + tcptw->tw_rcv_wnd))
return tcp_timewait_check_oow_rate_limit(
tw, skb, LINUX_MIB_TCPACKSKIPPEDFINWAIT2);
if (th->rst)
goto kill;
if (th->syn && !before(TCP_SKB_CB(skb)->seq, tcptw->tw_rcv_nxt))
return TCP_TW_RST;
if (!th->ack ||
!after(TCP_SKB_CB(skb)->end_seq, tcptw->tw_rcv_nxt) ||
TCP_SKB_CB(skb)->end_seq == TCP_SKB_CB(skb)->seq) {
inet_twsk_put(tw);
return TCP_TW_SUCCESS;
}
if (!th->fin ||
TCP_SKB_CB(skb)->end_seq != tcptw->tw_rcv_nxt + 1)
return TCP_TW_RST;
tw->tw_substate = TCP_TIME_WAIT;
tcptw->tw_rcv_nxt = TCP_SKB_CB(skb)->end_seq;
if (tmp_opt.saw_tstamp) {
tcptw->tw_ts_recent_stamp = get_seconds();
tcptw->tw_ts_recent = tmp_opt.rcv_tsval;
}
inet_twsk_reschedule(tw, TCP_TIMEWAIT_LEN);
return TCP_TW_ACK;
}
if (!paws_reject &&
(TCP_SKB_CB(skb)->seq == tcptw->tw_rcv_nxt &&
(TCP_SKB_CB(skb)->seq == TCP_SKB_CB(skb)->end_seq || th->rst))) {
if (th->rst) {
if (sysctl_tcp_rfc1337 == 0) {
kill:
inet_twsk_deschedule_put(tw);
return TCP_TW_SUCCESS;
}
}
inet_twsk_reschedule(tw, TCP_TIMEWAIT_LEN);
if (tmp_opt.saw_tstamp) {
tcptw->tw_ts_recent = tmp_opt.rcv_tsval;
tcptw->tw_ts_recent_stamp = get_seconds();
}
inet_twsk_put(tw);
return TCP_TW_SUCCESS;
}
if (th->syn && !th->rst && !th->ack && !paws_reject &&
(after(TCP_SKB_CB(skb)->seq, tcptw->tw_rcv_nxt) ||
(tmp_opt.saw_tstamp &&
(s32)(tcptw->tw_ts_recent - tmp_opt.rcv_tsval) < 0))) {
u32 isn = tcptw->tw_snd_nxt + 65535 + 2;
if (isn == 0)
isn++;
TCP_SKB_CB(skb)->tcp_tw_isn = isn;
return TCP_TW_SYN;
}
if (paws_reject)
__NET_INC_STATS(twsk_net(tw), LINUX_MIB_PAWSESTABREJECTED);
if (!th->rst) {
if (paws_reject || th->ack)
inet_twsk_reschedule(tw, TCP_TIMEWAIT_LEN);
return tcp_timewait_check_oow_rate_limit(
tw, skb, LINUX_MIB_TCPACKSKIPPEDTIMEWAIT);
}
inet_twsk_put(tw);
return TCP_TW_SUCCESS;
}
void tcp_time_wait(struct sock *sk, int state, int timeo)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
const struct tcp_sock *tp = tcp_sk(sk);
struct inet_timewait_sock *tw;
struct inet_timewait_death_row *tcp_death_row = &sock_net(sk)->ipv4.tcp_death_row;
tw = inet_twsk_alloc(sk, tcp_death_row, state);
if (tw) {
struct tcp_timewait_sock *tcptw = tcp_twsk((struct sock *)tw);
const int rto = (icsk->icsk_rto << 2) - (icsk->icsk_rto >> 1);
struct inet_sock *inet = inet_sk(sk);
tw->tw_transparent = inet->transparent;
tw->tw_rcv_wscale = tp->rx_opt.rcv_wscale;
tcptw->tw_rcv_nxt = tp->rcv_nxt;
tcptw->tw_snd_nxt = tp->snd_nxt;
tcptw->tw_rcv_wnd = tcp_receive_window(tp);
tcptw->tw_ts_recent = tp->rx_opt.ts_recent;
tcptw->tw_ts_recent_stamp = tp->rx_opt.ts_recent_stamp;
tcptw->tw_ts_offset = tp->tsoffset;
tcptw->tw_last_oow_ack_time = 0;
#if IS_ENABLED(CONFIG_IPV6)
if (tw->tw_family == PF_INET6) {
struct ipv6_pinfo *np = inet6_sk(sk);
tw->tw_v6_daddr = sk->sk_v6_daddr;
tw->tw_v6_rcv_saddr = sk->sk_v6_rcv_saddr;
tw->tw_tclass = np->tclass;
tw->tw_flowlabel = be32_to_cpu(np->flow_label & IPV6_FLOWLABEL_MASK);
tw->tw_ipv6only = sk->sk_ipv6only;
}
#endif
#ifdef CONFIG_TCP_MD5SIG
do {
struct tcp_md5sig_key *key;
tcptw->tw_md5_key = NULL;
key = tp->af_specific->md5_lookup(sk, sk);
if (key) {
tcptw->tw_md5_key = kmemdup(key, sizeof(*key), GFP_ATOMIC);
if (tcptw->tw_md5_key && !tcp_alloc_md5sig_pool())
BUG();
}
} while (0);
#endif
if (timeo < rto)
timeo = rto;
tw->tw_timeout = TCP_TIMEWAIT_LEN;
if (state == TCP_TIME_WAIT)
timeo = TCP_TIMEWAIT_LEN;
inet_twsk_schedule(tw, timeo);
__inet_twsk_hashdance(tw, sk, &tcp_hashinfo);
inet_twsk_put(tw);
} else {
NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPTIMEWAITOVERFLOW);
}
tcp_update_metrics(sk);
tcp_done(sk);
}
void tcp_twsk_destructor(struct sock *sk)
{
#ifdef CONFIG_TCP_MD5SIG
struct tcp_timewait_sock *twsk = tcp_twsk(sk);
if (twsk->tw_md5_key)
kfree_rcu(twsk->tw_md5_key, rcu);
#endif
}
void tcp_openreq_init_rwin(struct request_sock *req,
const struct sock *sk_listener,
const struct dst_entry *dst)
{
struct inet_request_sock *ireq = inet_rsk(req);
const struct tcp_sock *tp = tcp_sk(sk_listener);
int full_space = tcp_full_space(sk_listener);
u32 window_clamp;
__u8 rcv_wscale;
u32 rcv_wnd;
int mss;
mss = tcp_mss_clamp(tp, dst_metric_advmss(dst));
window_clamp = READ_ONCE(tp->window_clamp);
req->rsk_window_clamp = window_clamp ? : dst_metric(dst, RTAX_WINDOW);
if (sk_listener->sk_userlocks & SOCK_RCVBUF_LOCK &&
(req->rsk_window_clamp > full_space || req->rsk_window_clamp == 0))
req->rsk_window_clamp = full_space;
rcv_wnd = tcp_rwnd_init_bpf((struct sock *)req);
if (rcv_wnd == 0)
rcv_wnd = dst_metric(dst, RTAX_INITRWND);
else if (full_space < rcv_wnd * mss)
full_space = rcv_wnd * mss;
tcp_select_initial_window(full_space,
mss - (ireq->tstamp_ok ? TCPOLEN_TSTAMP_ALIGNED : 0),
&req->rsk_rcv_wnd,
&req->rsk_window_clamp,
ireq->wscale_ok,
&rcv_wscale,
rcv_wnd);
ireq->rcv_wscale = rcv_wscale;
}
static void tcp_ecn_openreq_child(struct tcp_sock *tp,
const struct request_sock *req)
{
tp->ecn_flags = inet_rsk(req)->ecn_ok ? TCP_ECN_OK : 0;
}
void tcp_ca_openreq_child(struct sock *sk, const struct dst_entry *dst)
{
struct inet_connection_sock *icsk = inet_csk(sk);
u32 ca_key = dst_metric(dst, RTAX_CC_ALGO);
bool ca_got_dst = false;
if (ca_key != TCP_CA_UNSPEC) {
const struct tcp_congestion_ops *ca;
rcu_read_lock();
ca = tcp_ca_find_key(ca_key);
if (likely(ca && try_module_get(ca->owner))) {
icsk->icsk_ca_dst_locked = tcp_ca_dst_locked(dst);
icsk->icsk_ca_ops = ca;
ca_got_dst = true;
}
rcu_read_unlock();
}
if (!ca_got_dst &&
(!icsk->icsk_ca_setsockopt ||
!try_module_get(icsk->icsk_ca_ops->owner)))
tcp_assign_congestion_control(sk);
tcp_set_ca_state(sk, TCP_CA_Open);
}
struct sock *tcp_create_openreq_child(const struct sock *sk,
struct request_sock *req,
struct sk_buff *skb)
{
struct sock *newsk = inet_csk_clone_lock(sk, req, GFP_ATOMIC);
if (newsk) {
const struct inet_request_sock *ireq = inet_rsk(req);
struct tcp_request_sock *treq = tcp_rsk(req);
struct inet_connection_sock *newicsk = inet_csk(newsk);
struct tcp_sock *newtp = tcp_sk(newsk);
newtp->pred_flags = 0;
newtp->rcv_wup = newtp->copied_seq =
newtp->rcv_nxt = treq->rcv_isn + 1;
newtp->segs_in = 1;
newtp->snd_sml = newtp->snd_una =
newtp->snd_nxt = newtp->snd_up = treq->snt_isn + 1;
tcp_prequeue_init(newtp);
INIT_LIST_HEAD(&newtp->tsq_node);
tcp_init_wl(newtp, treq->rcv_isn);
newtp->srtt_us = 0;
newtp->mdev_us = jiffies_to_usecs(TCP_TIMEOUT_INIT);
minmax_reset(&newtp->rtt_min, tcp_jiffies32, ~0U);
newicsk->icsk_rto = TCP_TIMEOUT_INIT;
newicsk->icsk_ack.lrcvtime = tcp_jiffies32;
newtp->packets_out = 0;
newtp->retrans_out = 0;
newtp->sacked_out = 0;
newtp->fackets_out = 0;
newtp->snd_ssthresh = TCP_INFINITE_SSTHRESH;
newtp->tlp_high_seq = 0;
newtp->lsndtime = tcp_jiffies32;
newsk->sk_txhash = treq->txhash;
newtp->last_oow_ack_time = 0;
newtp->total_retrans = req->num_retrans;
newtp->snd_cwnd = TCP_INIT_CWND;
newtp->snd_cwnd_cnt = 0;
newtp->app_limited = ~0U;
tcp_init_xmit_timers(newsk);
newtp->write_seq = newtp->pushed_seq = treq->snt_isn + 1;
newtp->rx_opt.saw_tstamp = 0;
newtp->rx_opt.dsack = 0;
newtp->rx_opt.num_sacks = 0;
newtp->urg_data = 0;
if (sock_flag(newsk, SOCK_KEEPOPEN))
inet_csk_reset_keepalive_timer(newsk,
keepalive_time_when(newtp));
newtp->rx_opt.tstamp_ok = ireq->tstamp_ok;
if ((newtp->rx_opt.sack_ok = ireq->sack_ok) != 0) {
if (sysctl_tcp_fack)
tcp_enable_fack(newtp);
}
newtp->window_clamp = req->rsk_window_clamp;
newtp->rcv_ssthresh = req->rsk_rcv_wnd;
newtp->rcv_wnd = req->rsk_rcv_wnd;
newtp->rx_opt.wscale_ok = ireq->wscale_ok;
if (newtp->rx_opt.wscale_ok) {
newtp->rx_opt.snd_wscale = ireq->snd_wscale;
newtp->rx_opt.rcv_wscale = ireq->rcv_wscale;
} else {
newtp->rx_opt.snd_wscale = newtp->rx_opt.rcv_wscale = 0;
newtp->window_clamp = min(newtp->window_clamp, 65535U);
}
newtp->snd_wnd = (ntohs(tcp_hdr(skb)->window) <<
newtp->rx_opt.snd_wscale);
newtp->max_window = newtp->snd_wnd;
if (newtp->rx_opt.tstamp_ok) {
newtp->rx_opt.ts_recent = req->ts_recent;
newtp->rx_opt.ts_recent_stamp = get_seconds();
newtp->tcp_header_len = sizeof(struct tcphdr) + TCPOLEN_TSTAMP_ALIGNED;
} else {
newtp->rx_opt.ts_recent_stamp = 0;
newtp->tcp_header_len = sizeof(struct tcphdr);
}
newtp->tsoffset = treq->ts_off;
#ifdef CONFIG_TCP_MD5SIG
newtp->md5sig_info = NULL;
if (newtp->af_specific->md5_lookup(sk, newsk))
newtp->tcp_header_len += TCPOLEN_MD5SIG_ALIGNED;
#endif
if (skb->len >= TCP_MSS_DEFAULT + newtp->tcp_header_len)
newicsk->icsk_ack.last_seg_size = skb->len - newtp->tcp_header_len;
newtp->rx_opt.mss_clamp = req->mss;
tcp_ecn_openreq_child(newtp, req);
newtp->fastopen_req = NULL;
newtp->fastopen_rsk = NULL;
newtp->syn_data_acked = 0;
newtp->rack.mstamp = 0;
newtp->rack.advanced = 0;
__TCP_INC_STATS(sock_net(sk), TCP_MIB_PASSIVEOPENS);
}
return newsk;
}
struct sock *tcp_check_req(struct sock *sk, struct sk_buff *skb,
struct request_sock *req,
bool fastopen)
{
struct tcp_options_received tmp_opt;
struct sock *child;
const struct tcphdr *th = tcp_hdr(skb);
__be32 flg = tcp_flag_word(th) & (TCP_FLAG_RST|TCP_FLAG_SYN|TCP_FLAG_ACK);
bool paws_reject = false;
bool own_req;
tmp_opt.saw_tstamp = 0;
if (th->doff > (sizeof(struct tcphdr)>>2)) {
tcp_parse_options(sock_net(sk), skb, &tmp_opt, 0, NULL);
if (tmp_opt.saw_tstamp) {
tmp_opt.ts_recent = req->ts_recent;
if (tmp_opt.rcv_tsecr)
tmp_opt.rcv_tsecr -= tcp_rsk(req)->ts_off;
tmp_opt.ts_recent_stamp = get_seconds() - ((TCP_TIMEOUT_INIT/HZ)<<req->num_timeout);
paws_reject = tcp_paws_reject(&tmp_opt, th->rst);
}
}
if (TCP_SKB_CB(skb)->seq == tcp_rsk(req)->rcv_isn &&
flg == TCP_FLAG_SYN &&
!paws_reject) {
if (!tcp_oow_rate_limited(sock_net(sk), skb,
LINUX_MIB_TCPACKSKIPPEDSYNRECV,
&tcp_rsk(req)->last_oow_ack_time) &&
!inet_rtx_syn_ack(sk, req)) {
unsigned long expires = jiffies;
expires += min(TCP_TIMEOUT_INIT << req->num_timeout,
TCP_RTO_MAX);
if (!fastopen)
mod_timer_pending(&req->rsk_timer, expires);
else
req->rsk_timer.expires = expires;
}
return NULL;
}
if ((flg & TCP_FLAG_ACK) && !fastopen &&
(TCP_SKB_CB(skb)->ack_seq !=
tcp_rsk(req)->snt_isn + 1))
return sk;
if (paws_reject || !tcp_in_window(TCP_SKB_CB(skb)->seq, TCP_SKB_CB(skb)->end_seq,
tcp_rsk(req)->rcv_nxt, tcp_rsk(req)->rcv_nxt + req->rsk_rcv_wnd)) {
if (!(flg & TCP_FLAG_RST) &&
!tcp_oow_rate_limited(sock_net(sk), skb,
LINUX_MIB_TCPACKSKIPPEDSYNRECV,
&tcp_rsk(req)->last_oow_ack_time))
req->rsk_ops->send_ack(sk, skb, req);
if (paws_reject)
__NET_INC_STATS(sock_net(sk), LINUX_MIB_PAWSESTABREJECTED);
return NULL;
}
if (tmp_opt.saw_tstamp && !after(TCP_SKB_CB(skb)->seq, tcp_rsk(req)->rcv_nxt))
req->ts_recent = tmp_opt.rcv_tsval;
if (TCP_SKB_CB(skb)->seq == tcp_rsk(req)->rcv_isn) {
flg &= ~TCP_FLAG_SYN;
}
if (flg & (TCP_FLAG_RST|TCP_FLAG_SYN)) {
__TCP_INC_STATS(sock_net(sk), TCP_MIB_ATTEMPTFAILS);
goto embryonic_reset;
}
if (!(flg & TCP_FLAG_ACK))
return NULL;
if (fastopen)
return sk;
if (req->num_timeout < inet_csk(sk)->icsk_accept_queue.rskq_defer_accept &&
TCP_SKB_CB(skb)->end_seq == tcp_rsk(req)->rcv_isn + 1) {
inet_rsk(req)->acked = 1;
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPDEFERACCEPTDROP);
return NULL;
}
child = inet_csk(sk)->icsk_af_ops->syn_recv_sock(sk, skb, req, NULL,
req, &own_req);
if (!child)
goto listen_overflow;
sock_rps_save_rxhash(child, skb);
tcp_synack_rtt_meas(child, req);
return inet_csk_complete_hashdance(sk, child, req, own_req);
listen_overflow:
if (!sysctl_tcp_abort_on_overflow) {
inet_rsk(req)->acked = 1;
return NULL;
}
embryonic_reset:
if (!(flg & TCP_FLAG_RST)) {
req->rsk_ops->send_reset(sk, skb);
} else if (fastopen) {
reqsk_fastopen_remove(sk, req, true);
tcp_reset(sk);
}
if (!fastopen) {
inet_csk_reqsk_queue_drop(sk, req);
__NET_INC_STATS(sock_net(sk), LINUX_MIB_EMBRYONICRSTS);
}
return NULL;
}
int tcp_child_process(struct sock *parent, struct sock *child,
struct sk_buff *skb)
{
int ret = 0;
int state = child->sk_state;
sk_mark_napi_id(child, skb);
tcp_segs_in(tcp_sk(child), skb);
if (!sock_owned_by_user(child)) {
ret = tcp_rcv_state_process(child, skb);
if (state == TCP_SYN_RECV && child->sk_state != state)
parent->sk_data_ready(parent);
} else {
__sk_add_backlog(child, skb);
}
bh_unlock_sock(child);
sock_put(child);
return ret;
}
