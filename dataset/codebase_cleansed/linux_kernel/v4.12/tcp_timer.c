static void tcp_write_err(struct sock *sk)
{
sk->sk_err = sk->sk_err_soft ? : ETIMEDOUT;
sk->sk_error_report(sk);
tcp_done(sk);
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPABORTONTIMEOUT);
}
static int tcp_out_of_resources(struct sock *sk, bool do_reset)
{
struct tcp_sock *tp = tcp_sk(sk);
int shift = 0;
if ((s32)(tcp_time_stamp - tp->lsndtime) > 2*TCP_RTO_MAX || !do_reset)
shift++;
if (sk->sk_err_soft)
shift++;
if (tcp_check_oom(sk, shift)) {
if ((s32)(tcp_time_stamp - tp->lsndtime) <= TCP_TIMEWAIT_LEN ||
(!tp->snd_wnd && !tp->packets_out))
do_reset = true;
if (do_reset)
tcp_send_active_reset(sk, GFP_ATOMIC);
tcp_done(sk);
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPABORTONMEMORY);
return 1;
}
return 0;
}
static int tcp_orphan_retries(struct sock *sk, bool alive)
{
int retries = sock_net(sk)->ipv4.sysctl_tcp_orphan_retries;
if (sk->sk_err_soft && !alive)
retries = 0;
if (retries == 0 && alive)
retries = 8;
return retries;
}
static void tcp_mtu_probing(struct inet_connection_sock *icsk, struct sock *sk)
{
struct net *net = sock_net(sk);
if (net->ipv4.sysctl_tcp_mtu_probing) {
if (!icsk->icsk_mtup.enabled) {
icsk->icsk_mtup.enabled = 1;
icsk->icsk_mtup.probe_timestamp = tcp_time_stamp;
tcp_sync_mss(sk, icsk->icsk_pmtu_cookie);
} else {
struct net *net = sock_net(sk);
struct tcp_sock *tp = tcp_sk(sk);
int mss;
mss = tcp_mtu_to_mss(sk, icsk->icsk_mtup.search_low) >> 1;
mss = min(net->ipv4.sysctl_tcp_base_mss, mss);
mss = max(mss, 68 - tp->tcp_header_len);
icsk->icsk_mtup.search_low = tcp_mss_to_mtu(sk, mss);
tcp_sync_mss(sk, icsk->icsk_pmtu_cookie);
}
}
}
static bool retransmits_timed_out(struct sock *sk,
unsigned int boundary,
unsigned int timeout,
bool syn_set)
{
unsigned int linear_backoff_thresh, start_ts;
unsigned int rto_base = syn_set ? TCP_TIMEOUT_INIT : TCP_RTO_MIN;
if (!inet_csk(sk)->icsk_retransmits)
return false;
start_ts = tcp_sk(sk)->retrans_stamp;
if (unlikely(!start_ts))
start_ts = tcp_skb_timestamp(tcp_write_queue_head(sk));
if (likely(timeout == 0)) {
linear_backoff_thresh = ilog2(TCP_RTO_MAX/rto_base);
if (boundary <= linear_backoff_thresh)
timeout = ((2 << boundary) - 1) * rto_base;
else
timeout = ((2 << linear_backoff_thresh) - 1) * rto_base +
(boundary - linear_backoff_thresh) * TCP_RTO_MAX;
}
return (tcp_time_stamp - start_ts) >= timeout;
}
static int tcp_write_timeout(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
int retry_until;
bool do_reset, syn_set = false;
if ((1 << sk->sk_state) & (TCPF_SYN_SENT | TCPF_SYN_RECV)) {
if (icsk->icsk_retransmits) {
dst_negative_advice(sk);
if (tp->syn_fastopen || tp->syn_data)
tcp_fastopen_cache_set(sk, 0, NULL, true, 0);
if (tp->syn_data && icsk->icsk_retransmits == 1)
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPFASTOPENACTIVEFAIL);
} else if (!tp->syn_data && !tp->syn_fastopen) {
sk_rethink_txhash(sk);
}
retry_until = icsk->icsk_syn_retries ? : net->ipv4.sysctl_tcp_syn_retries;
syn_set = true;
} else {
if (retransmits_timed_out(sk, net->ipv4.sysctl_tcp_retries1, 0, 0)) {
if (tp->syn_data_acked) {
tcp_fastopen_cache_set(sk, 0, NULL, true, 0);
if (icsk->icsk_retransmits == net->ipv4.sysctl_tcp_retries1)
NET_INC_STATS(sock_net(sk),
LINUX_MIB_TCPFASTOPENACTIVEFAIL);
}
tcp_mtu_probing(icsk, sk);
dst_negative_advice(sk);
} else {
sk_rethink_txhash(sk);
}
retry_until = net->ipv4.sysctl_tcp_retries2;
if (sock_flag(sk, SOCK_DEAD)) {
const bool alive = icsk->icsk_rto < TCP_RTO_MAX;
retry_until = tcp_orphan_retries(sk, alive);
do_reset = alive ||
!retransmits_timed_out(sk, retry_until, 0, 0);
if (tcp_out_of_resources(sk, do_reset))
return 1;
}
}
if (retransmits_timed_out(sk, retry_until,
syn_set ? 0 : icsk->icsk_user_timeout, syn_set)) {
tcp_write_err(sk);
return 1;
}
return 0;
}
void tcp_delack_timer_handler(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
sk_mem_reclaim_partial(sk);
if (((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_LISTEN)) ||
!(icsk->icsk_ack.pending & ICSK_ACK_TIMER))
goto out;
if (time_after(icsk->icsk_ack.timeout, jiffies)) {
sk_reset_timer(sk, &icsk->icsk_delack_timer, icsk->icsk_ack.timeout);
goto out;
}
icsk->icsk_ack.pending &= ~ICSK_ACK_TIMER;
if (!skb_queue_empty(&tp->ucopy.prequeue)) {
struct sk_buff *skb;
__NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPSCHEDULERFAILED);
while ((skb = __skb_dequeue(&tp->ucopy.prequeue)) != NULL)
sk_backlog_rcv(sk, skb);
tp->ucopy.memory = 0;
}
if (inet_csk_ack_scheduled(sk)) {
if (!icsk->icsk_ack.pingpong) {
icsk->icsk_ack.ato = min(icsk->icsk_ack.ato << 1, icsk->icsk_rto);
} else {
icsk->icsk_ack.pingpong = 0;
icsk->icsk_ack.ato = TCP_ATO_MIN;
}
tcp_send_ack(sk);
__NET_INC_STATS(sock_net(sk), LINUX_MIB_DELAYEDACKS);
}
out:
if (tcp_under_memory_pressure(sk))
sk_mem_reclaim(sk);
}
static void tcp_delack_timer(unsigned long data)
{
struct sock *sk = (struct sock *)data;
bh_lock_sock(sk);
if (!sock_owned_by_user(sk)) {
tcp_delack_timer_handler(sk);
} else {
inet_csk(sk)->icsk_ack.blocked = 1;
__NET_INC_STATS(sock_net(sk), LINUX_MIB_DELAYEDACKLOCKED);
if (!test_and_set_bit(TCP_DELACK_TIMER_DEFERRED, &sk->sk_tsq_flags))
sock_hold(sk);
}
bh_unlock_sock(sk);
sock_put(sk);
}
static void tcp_probe_timer(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
int max_probes;
u32 start_ts;
if (tp->packets_out || !tcp_send_head(sk)) {
icsk->icsk_probes_out = 0;
return;
}
start_ts = tcp_skb_timestamp(tcp_send_head(sk));
if (!start_ts)
skb_mstamp_get(&tcp_send_head(sk)->skb_mstamp);
else if (icsk->icsk_user_timeout &&
(s32)(tcp_time_stamp - start_ts) > icsk->icsk_user_timeout)
goto abort;
max_probes = sock_net(sk)->ipv4.sysctl_tcp_retries2;
if (sock_flag(sk, SOCK_DEAD)) {
const bool alive = inet_csk_rto_backoff(icsk, TCP_RTO_MAX) < TCP_RTO_MAX;
max_probes = tcp_orphan_retries(sk, alive);
if (!alive && icsk->icsk_backoff >= max_probes)
goto abort;
if (tcp_out_of_resources(sk, true))
return;
}
if (icsk->icsk_probes_out > max_probes) {
abort: tcp_write_err(sk);
} else {
tcp_send_probe0(sk);
}
}
static void tcp_fastopen_synack_timer(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
int max_retries = icsk->icsk_syn_retries ? :
sock_net(sk)->ipv4.sysctl_tcp_synack_retries + 1;
struct request_sock *req;
req = tcp_sk(sk)->fastopen_rsk;
req->rsk_ops->syn_ack_timeout(req);
if (req->num_timeout >= max_retries) {
tcp_write_err(sk);
return;
}
inet_rtx_syn_ack(sk, req);
req->num_timeout++;
icsk->icsk_retransmits++;
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
TCP_TIMEOUT_INIT << req->num_timeout, TCP_RTO_MAX);
}
void tcp_retransmit_timer(struct sock *sk)
{
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
struct inet_connection_sock *icsk = inet_csk(sk);
if (tp->fastopen_rsk) {
WARN_ON_ONCE(sk->sk_state != TCP_SYN_RECV &&
sk->sk_state != TCP_FIN_WAIT1);
tcp_fastopen_synack_timer(sk);
return;
}
if (!tp->packets_out)
goto out;
WARN_ON(tcp_write_queue_empty(sk));
tp->tlp_high_seq = 0;
if (!tp->snd_wnd && !sock_flag(sk, SOCK_DEAD) &&
!((1 << sk->sk_state) & (TCPF_SYN_SENT | TCPF_SYN_RECV))) {
struct inet_sock *inet = inet_sk(sk);
if (sk->sk_family == AF_INET) {
net_dbg_ratelimited("Peer %pI4:%u/%u unexpectedly shrunk window %u:%u (repaired)\n",
&inet->inet_daddr,
ntohs(inet->inet_dport),
inet->inet_num,
tp->snd_una, tp->snd_nxt);
}
#if IS_ENABLED(CONFIG_IPV6)
else if (sk->sk_family == AF_INET6) {
net_dbg_ratelimited("Peer %pI6:%u/%u unexpectedly shrunk window %u:%u (repaired)\n",
&sk->sk_v6_daddr,
ntohs(inet->inet_dport),
inet->inet_num,
tp->snd_una, tp->snd_nxt);
}
#endif
if (tcp_time_stamp - tp->rcv_tstamp > TCP_RTO_MAX) {
tcp_write_err(sk);
goto out;
}
tcp_enter_loss(sk);
tcp_retransmit_skb(sk, tcp_write_queue_head(sk), 1);
__sk_dst_reset(sk);
goto out_reset_timer;
}
if (tcp_write_timeout(sk))
goto out;
if (icsk->icsk_retransmits == 0) {
int mib_idx;
if (icsk->icsk_ca_state == TCP_CA_Recovery) {
if (tcp_is_sack(tp))
mib_idx = LINUX_MIB_TCPSACKRECOVERYFAIL;
else
mib_idx = LINUX_MIB_TCPRENORECOVERYFAIL;
} else if (icsk->icsk_ca_state == TCP_CA_Loss) {
mib_idx = LINUX_MIB_TCPLOSSFAILURES;
} else if ((icsk->icsk_ca_state == TCP_CA_Disorder) ||
tp->sacked_out) {
if (tcp_is_sack(tp))
mib_idx = LINUX_MIB_TCPSACKFAILURES;
else
mib_idx = LINUX_MIB_TCPRENOFAILURES;
} else {
mib_idx = LINUX_MIB_TCPTIMEOUTS;
}
__NET_INC_STATS(sock_net(sk), mib_idx);
}
tcp_enter_loss(sk);
if (tcp_retransmit_skb(sk, tcp_write_queue_head(sk), 1) > 0) {
if (!icsk->icsk_retransmits)
icsk->icsk_retransmits = 1;
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS,
min(icsk->icsk_rto, TCP_RESOURCE_PROBE_INTERVAL),
TCP_RTO_MAX);
goto out;
}
icsk->icsk_backoff++;
icsk->icsk_retransmits++;
out_reset_timer:
if (sk->sk_state == TCP_ESTABLISHED &&
(tp->thin_lto || sysctl_tcp_thin_linear_timeouts) &&
tcp_stream_is_thin(tp) &&
icsk->icsk_retransmits <= TCP_THIN_LINEAR_RETRIES) {
icsk->icsk_backoff = 0;
icsk->icsk_rto = min(__tcp_set_rto(tp), TCP_RTO_MAX);
} else {
icsk->icsk_rto = min(icsk->icsk_rto << 1, TCP_RTO_MAX);
}
inet_csk_reset_xmit_timer(sk, ICSK_TIME_RETRANS, icsk->icsk_rto, TCP_RTO_MAX);
if (retransmits_timed_out(sk, net->ipv4.sysctl_tcp_retries1 + 1, 0, 0))
__sk_dst_reset(sk);
out:;
}
void tcp_write_timer_handler(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
int event;
if (((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_LISTEN)) ||
!icsk->icsk_pending)
goto out;
if (time_after(icsk->icsk_timeout, jiffies)) {
sk_reset_timer(sk, &icsk->icsk_retransmit_timer, icsk->icsk_timeout);
goto out;
}
event = icsk->icsk_pending;
switch (event) {
case ICSK_TIME_REO_TIMEOUT:
tcp_rack_reo_timeout(sk);
break;
case ICSK_TIME_LOSS_PROBE:
tcp_send_loss_probe(sk);
break;
case ICSK_TIME_RETRANS:
icsk->icsk_pending = 0;
tcp_retransmit_timer(sk);
break;
case ICSK_TIME_PROBE0:
icsk->icsk_pending = 0;
tcp_probe_timer(sk);
break;
}
out:
sk_mem_reclaim(sk);
}
static void tcp_write_timer(unsigned long data)
{
struct sock *sk = (struct sock *)data;
bh_lock_sock(sk);
if (!sock_owned_by_user(sk)) {
tcp_write_timer_handler(sk);
} else {
if (!test_and_set_bit(TCP_WRITE_TIMER_DEFERRED, &sk->sk_tsq_flags))
sock_hold(sk);
}
bh_unlock_sock(sk);
sock_put(sk);
}
void tcp_syn_ack_timeout(const struct request_sock *req)
{
struct net *net = read_pnet(&inet_rsk(req)->ireq_net);
__NET_INC_STATS(net, LINUX_MIB_TCPTIMEOUTS);
}
void tcp_set_keepalive(struct sock *sk, int val)
{
if ((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_LISTEN))
return;
if (val && !sock_flag(sk, SOCK_KEEPOPEN))
inet_csk_reset_keepalive_timer(sk, keepalive_time_when(tcp_sk(sk)));
else if (!val)
inet_csk_delete_keepalive_timer(sk);
}
static void tcp_keepalive_timer (unsigned long data)
{
struct sock *sk = (struct sock *) data;
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_sock *tp = tcp_sk(sk);
u32 elapsed;
bh_lock_sock(sk);
if (sock_owned_by_user(sk)) {
inet_csk_reset_keepalive_timer (sk, HZ/20);
goto out;
}
if (sk->sk_state == TCP_LISTEN) {
pr_err("Hmm... keepalive on a LISTEN ???\n");
goto out;
}
if (sk->sk_state == TCP_FIN_WAIT2 && sock_flag(sk, SOCK_DEAD)) {
if (tp->linger2 >= 0) {
const int tmo = tcp_fin_time(sk) - TCP_TIMEWAIT_LEN;
if (tmo > 0) {
tcp_time_wait(sk, TCP_FIN_WAIT2, tmo);
goto out;
}
}
tcp_send_active_reset(sk, GFP_ATOMIC);
goto death;
}
if (!sock_flag(sk, SOCK_KEEPOPEN) || sk->sk_state == TCP_CLOSE)
goto out;
elapsed = keepalive_time_when(tp);
if (tp->packets_out || tcp_send_head(sk))
goto resched;
elapsed = keepalive_time_elapsed(tp);
if (elapsed >= keepalive_time_when(tp)) {
if ((icsk->icsk_user_timeout != 0 &&
elapsed >= icsk->icsk_user_timeout &&
icsk->icsk_probes_out > 0) ||
(icsk->icsk_user_timeout == 0 &&
icsk->icsk_probes_out >= keepalive_probes(tp))) {
tcp_send_active_reset(sk, GFP_ATOMIC);
tcp_write_err(sk);
goto out;
}
if (tcp_write_wakeup(sk, LINUX_MIB_TCPKEEPALIVE) <= 0) {
icsk->icsk_probes_out++;
elapsed = keepalive_intvl_when(tp);
} else {
elapsed = TCP_RESOURCE_PROBE_INTERVAL;
}
} else {
elapsed = keepalive_time_when(tp) - elapsed;
}
sk_mem_reclaim(sk);
resched:
inet_csk_reset_keepalive_timer (sk, elapsed);
goto out;
death:
tcp_done(sk);
out:
bh_unlock_sock(sk);
sock_put(sk);
}
void tcp_init_xmit_timers(struct sock *sk)
{
inet_csk_init_xmit_timers(sk, &tcp_write_timer, &tcp_delack_timer,
&tcp_keepalive_timer);
}
