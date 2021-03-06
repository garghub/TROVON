static bool tcp_metric_locked(struct tcp_metrics_block *tm,
enum tcp_metric_index idx)
{
return tm->tcpm_lock & (1 << idx);
}
static u32 tcp_metric_get(struct tcp_metrics_block *tm,
enum tcp_metric_index idx)
{
return tm->tcpm_vals[idx];
}
static u32 tcp_metric_get_jiffies(struct tcp_metrics_block *tm,
enum tcp_metric_index idx)
{
return msecs_to_jiffies(tm->tcpm_vals[idx]);
}
static void tcp_metric_set(struct tcp_metrics_block *tm,
enum tcp_metric_index idx,
u32 val)
{
tm->tcpm_vals[idx] = val;
}
static void tcp_metric_set_msecs(struct tcp_metrics_block *tm,
enum tcp_metric_index idx,
u32 val)
{
tm->tcpm_vals[idx] = jiffies_to_msecs(val);
}
static bool addr_same(const struct inetpeer_addr *a,
const struct inetpeer_addr *b)
{
const struct in6_addr *a6, *b6;
if (a->family != b->family)
return false;
if (a->family == AF_INET)
return a->addr.a4 == b->addr.a4;
a6 = (const struct in6_addr *) &a->addr.a6[0];
b6 = (const struct in6_addr *) &b->addr.a6[0];
return ipv6_addr_equal(a6, b6);
}
static void tcpm_suck_dst(struct tcp_metrics_block *tm, struct dst_entry *dst)
{
u32 val;
tm->tcpm_stamp = jiffies;
val = 0;
if (dst_metric_locked(dst, RTAX_RTT))
val |= 1 << TCP_METRIC_RTT;
if (dst_metric_locked(dst, RTAX_RTTVAR))
val |= 1 << TCP_METRIC_RTTVAR;
if (dst_metric_locked(dst, RTAX_SSTHRESH))
val |= 1 << TCP_METRIC_SSTHRESH;
if (dst_metric_locked(dst, RTAX_CWND))
val |= 1 << TCP_METRIC_CWND;
if (dst_metric_locked(dst, RTAX_REORDERING))
val |= 1 << TCP_METRIC_REORDERING;
tm->tcpm_lock = val;
tm->tcpm_vals[TCP_METRIC_RTT] = dst_metric_raw(dst, RTAX_RTT);
tm->tcpm_vals[TCP_METRIC_RTTVAR] = dst_metric_raw(dst, RTAX_RTTVAR);
tm->tcpm_vals[TCP_METRIC_SSTHRESH] = dst_metric_raw(dst, RTAX_SSTHRESH);
tm->tcpm_vals[TCP_METRIC_CWND] = dst_metric_raw(dst, RTAX_CWND);
tm->tcpm_vals[TCP_METRIC_REORDERING] = dst_metric_raw(dst, RTAX_REORDERING);
tm->tcpm_ts = 0;
tm->tcpm_ts_stamp = 0;
tm->tcpm_fastopen.mss = 0;
tm->tcpm_fastopen.syn_loss = 0;
tm->tcpm_fastopen.cookie.len = 0;
}
static struct tcp_metrics_block *tcpm_new(struct dst_entry *dst,
struct inetpeer_addr *addr,
unsigned int hash,
bool reclaim)
{
struct tcp_metrics_block *tm;
struct net *net;
spin_lock_bh(&tcp_metrics_lock);
net = dev_net(dst->dev);
if (unlikely(reclaim)) {
struct tcp_metrics_block *oldest;
oldest = rcu_dereference(net->ipv4.tcp_metrics_hash[hash].chain);
for (tm = rcu_dereference(oldest->tcpm_next); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (time_before(tm->tcpm_stamp, oldest->tcpm_stamp))
oldest = tm;
}
tm = oldest;
} else {
tm = kmalloc(sizeof(*tm), GFP_ATOMIC);
if (!tm)
goto out_unlock;
}
tm->tcpm_addr = *addr;
tcpm_suck_dst(tm, dst);
if (likely(!reclaim)) {
tm->tcpm_next = net->ipv4.tcp_metrics_hash[hash].chain;
rcu_assign_pointer(net->ipv4.tcp_metrics_hash[hash].chain, tm);
}
out_unlock:
spin_unlock_bh(&tcp_metrics_lock);
return tm;
}
static void tcpm_check_stamp(struct tcp_metrics_block *tm, struct dst_entry *dst)
{
if (tm && unlikely(time_after(jiffies, tm->tcpm_stamp + TCP_METRICS_TIMEOUT)))
tcpm_suck_dst(tm, dst);
}
static struct tcp_metrics_block *tcp_get_encode(struct tcp_metrics_block *tm, int depth)
{
if (tm)
return tm;
if (depth > TCP_METRICS_RECLAIM_DEPTH)
return TCP_METRICS_RECLAIM_PTR;
return NULL;
}
static struct tcp_metrics_block *__tcp_get_metrics(const struct inetpeer_addr *addr,
struct net *net, unsigned int hash)
{
struct tcp_metrics_block *tm;
int depth = 0;
for (tm = rcu_dereference(net->ipv4.tcp_metrics_hash[hash].chain); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (addr_same(&tm->tcpm_addr, addr))
break;
depth++;
}
return tcp_get_encode(tm, depth);
}
static struct tcp_metrics_block *__tcp_get_metrics_req(struct request_sock *req,
struct dst_entry *dst)
{
struct tcp_metrics_block *tm;
struct inetpeer_addr addr;
unsigned int hash;
struct net *net;
addr.family = req->rsk_ops->family;
switch (addr.family) {
case AF_INET:
addr.addr.a4 = inet_rsk(req)->rmt_addr;
hash = (__force unsigned int) addr.addr.a4;
break;
case AF_INET6:
*(struct in6_addr *)addr.addr.a6 = inet6_rsk(req)->rmt_addr;
hash = ipv6_addr_hash(&inet6_rsk(req)->rmt_addr);
break;
default:
return NULL;
}
net = dev_net(dst->dev);
hash = hash_32(hash, net->ipv4.tcp_metrics_hash_log);
for (tm = rcu_dereference(net->ipv4.tcp_metrics_hash[hash].chain); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (addr_same(&tm->tcpm_addr, &addr))
break;
}
tcpm_check_stamp(tm, dst);
return tm;
}
static struct tcp_metrics_block *__tcp_get_metrics_tw(struct inet_timewait_sock *tw)
{
struct inet6_timewait_sock *tw6;
struct tcp_metrics_block *tm;
struct inetpeer_addr addr;
unsigned int hash;
struct net *net;
addr.family = tw->tw_family;
switch (addr.family) {
case AF_INET:
addr.addr.a4 = tw->tw_daddr;
hash = (__force unsigned int) addr.addr.a4;
break;
case AF_INET6:
tw6 = inet6_twsk((struct sock *)tw);
*(struct in6_addr *)addr.addr.a6 = tw6->tw_v6_daddr;
hash = ipv6_addr_hash(&tw6->tw_v6_daddr);
break;
default:
return NULL;
}
net = twsk_net(tw);
hash = hash_32(hash, net->ipv4.tcp_metrics_hash_log);
for (tm = rcu_dereference(net->ipv4.tcp_metrics_hash[hash].chain); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (addr_same(&tm->tcpm_addr, &addr))
break;
}
return tm;
}
static struct tcp_metrics_block *tcp_get_metrics(struct sock *sk,
struct dst_entry *dst,
bool create)
{
struct tcp_metrics_block *tm;
struct inetpeer_addr addr;
unsigned int hash;
struct net *net;
bool reclaim;
addr.family = sk->sk_family;
switch (addr.family) {
case AF_INET:
addr.addr.a4 = inet_sk(sk)->inet_daddr;
hash = (__force unsigned int) addr.addr.a4;
break;
case AF_INET6:
*(struct in6_addr *)addr.addr.a6 = inet6_sk(sk)->daddr;
hash = ipv6_addr_hash(&inet6_sk(sk)->daddr);
break;
default:
return NULL;
}
net = dev_net(dst->dev);
hash = hash_32(hash, net->ipv4.tcp_metrics_hash_log);
tm = __tcp_get_metrics(&addr, net, hash);
reclaim = false;
if (tm == TCP_METRICS_RECLAIM_PTR) {
reclaim = true;
tm = NULL;
}
if (!tm && create)
tm = tcpm_new(dst, &addr, hash, reclaim);
else
tcpm_check_stamp(tm, dst);
return tm;
}
void tcp_update_metrics(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct dst_entry *dst = __sk_dst_get(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_metrics_block *tm;
unsigned long rtt;
u32 val;
int m;
if (sysctl_tcp_nometrics_save || !dst)
return;
if (dst->flags & DST_HOST)
dst_confirm(dst);
rcu_read_lock();
if (icsk->icsk_backoff || !tp->srtt) {
tm = tcp_get_metrics(sk, dst, false);
if (tm && !tcp_metric_locked(tm, TCP_METRIC_RTT))
tcp_metric_set(tm, TCP_METRIC_RTT, 0);
goto out_unlock;
} else
tm = tcp_get_metrics(sk, dst, true);
if (!tm)
goto out_unlock;
rtt = tcp_metric_get_jiffies(tm, TCP_METRIC_RTT);
m = rtt - tp->srtt;
if (!tcp_metric_locked(tm, TCP_METRIC_RTT)) {
if (m <= 0)
rtt = tp->srtt;
else
rtt -= (m >> 3);
tcp_metric_set_msecs(tm, TCP_METRIC_RTT, rtt);
}
if (!tcp_metric_locked(tm, TCP_METRIC_RTTVAR)) {
unsigned long var;
if (m < 0)
m = -m;
m >>= 1;
if (m < tp->mdev)
m = tp->mdev;
var = tcp_metric_get_jiffies(tm, TCP_METRIC_RTTVAR);
if (m >= var)
var = m;
else
var -= (var - m) >> 2;
tcp_metric_set_msecs(tm, TCP_METRIC_RTTVAR, var);
}
if (tcp_in_initial_slowstart(tp)) {
if (!tcp_metric_locked(tm, TCP_METRIC_SSTHRESH)) {
val = tcp_metric_get(tm, TCP_METRIC_SSTHRESH);
if (val && (tp->snd_cwnd >> 1) > val)
tcp_metric_set(tm, TCP_METRIC_SSTHRESH,
tp->snd_cwnd >> 1);
}
if (!tcp_metric_locked(tm, TCP_METRIC_CWND)) {
val = tcp_metric_get(tm, TCP_METRIC_CWND);
if (tp->snd_cwnd > val)
tcp_metric_set(tm, TCP_METRIC_CWND,
tp->snd_cwnd);
}
} else if (tp->snd_cwnd > tp->snd_ssthresh &&
icsk->icsk_ca_state == TCP_CA_Open) {
if (!tcp_metric_locked(tm, TCP_METRIC_SSTHRESH))
tcp_metric_set(tm, TCP_METRIC_SSTHRESH,
max(tp->snd_cwnd >> 1, tp->snd_ssthresh));
if (!tcp_metric_locked(tm, TCP_METRIC_CWND)) {
val = tcp_metric_get(tm, TCP_METRIC_CWND);
tcp_metric_set(tm, TCP_METRIC_CWND, (val + tp->snd_cwnd) >> 1);
}
} else {
if (!tcp_metric_locked(tm, TCP_METRIC_CWND)) {
val = tcp_metric_get(tm, TCP_METRIC_CWND);
tcp_metric_set(tm, TCP_METRIC_CWND,
(val + tp->snd_ssthresh) >> 1);
}
if (!tcp_metric_locked(tm, TCP_METRIC_SSTHRESH)) {
val = tcp_metric_get(tm, TCP_METRIC_SSTHRESH);
if (val && tp->snd_ssthresh > val)
tcp_metric_set(tm, TCP_METRIC_SSTHRESH,
tp->snd_ssthresh);
}
if (!tcp_metric_locked(tm, TCP_METRIC_REORDERING)) {
val = tcp_metric_get(tm, TCP_METRIC_REORDERING);
if (val < tp->reordering &&
tp->reordering != sysctl_tcp_reordering)
tcp_metric_set(tm, TCP_METRIC_REORDERING,
tp->reordering);
}
}
tm->tcpm_stamp = jiffies;
out_unlock:
rcu_read_unlock();
}
void tcp_init_metrics(struct sock *sk)
{
struct dst_entry *dst = __sk_dst_get(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct tcp_metrics_block *tm;
u32 val;
if (dst == NULL)
goto reset;
dst_confirm(dst);
rcu_read_lock();
tm = tcp_get_metrics(sk, dst, true);
if (!tm) {
rcu_read_unlock();
goto reset;
}
if (tcp_metric_locked(tm, TCP_METRIC_CWND))
tp->snd_cwnd_clamp = tcp_metric_get(tm, TCP_METRIC_CWND);
val = tcp_metric_get(tm, TCP_METRIC_SSTHRESH);
if (val) {
tp->snd_ssthresh = val;
if (tp->snd_ssthresh > tp->snd_cwnd_clamp)
tp->snd_ssthresh = tp->snd_cwnd_clamp;
} else {
tp->snd_ssthresh = TCP_INFINITE_SSTHRESH;
}
val = tcp_metric_get(tm, TCP_METRIC_REORDERING);
if (val && tp->reordering != val) {
tcp_disable_fack(tp);
tcp_disable_early_retrans(tp);
tp->reordering = val;
}
val = tcp_metric_get(tm, TCP_METRIC_RTT);
if (val == 0 || tp->srtt == 0) {
rcu_read_unlock();
goto reset;
}
val = msecs_to_jiffies(val);
if (val > tp->srtt) {
tp->srtt = val;
tp->rtt_seq = tp->snd_nxt;
}
val = tcp_metric_get_jiffies(tm, TCP_METRIC_RTTVAR);
if (val > tp->mdev) {
tp->mdev = val;
tp->mdev_max = tp->rttvar = max(tp->mdev, tcp_rto_min(sk));
}
rcu_read_unlock();
tcp_set_rto(sk);
reset:
if (tp->srtt == 0) {
tp->mdev = tp->mdev_max = tp->rttvar = TCP_TIMEOUT_FALLBACK;
inet_csk(sk)->icsk_rto = TCP_TIMEOUT_FALLBACK;
}
if (tp->total_retrans > 1)
tp->snd_cwnd = 1;
else
tp->snd_cwnd = tcp_init_cwnd(tp, dst);
tp->snd_cwnd_stamp = tcp_time_stamp;
}
bool tcp_peer_is_proven(struct request_sock *req, struct dst_entry *dst, bool paws_check)
{
struct tcp_metrics_block *tm;
bool ret;
if (!dst)
return false;
rcu_read_lock();
tm = __tcp_get_metrics_req(req, dst);
if (paws_check) {
if (tm &&
(u32)get_seconds() - tm->tcpm_ts_stamp < TCP_PAWS_MSL &&
(s32)(tm->tcpm_ts - req->ts_recent) > TCP_PAWS_WINDOW)
ret = false;
else
ret = true;
} else {
if (tm && tcp_metric_get(tm, TCP_METRIC_RTT) && tm->tcpm_ts_stamp)
ret = true;
else
ret = false;
}
rcu_read_unlock();
return ret;
}
void tcp_fetch_timewait_stamp(struct sock *sk, struct dst_entry *dst)
{
struct tcp_metrics_block *tm;
rcu_read_lock();
tm = tcp_get_metrics(sk, dst, true);
if (tm) {
struct tcp_sock *tp = tcp_sk(sk);
if ((u32)get_seconds() - tm->tcpm_ts_stamp <= TCP_PAWS_MSL) {
tp->rx_opt.ts_recent_stamp = tm->tcpm_ts_stamp;
tp->rx_opt.ts_recent = tm->tcpm_ts;
}
}
rcu_read_unlock();
}
bool tcp_remember_stamp(struct sock *sk)
{
struct dst_entry *dst = __sk_dst_get(sk);
bool ret = false;
if (dst) {
struct tcp_metrics_block *tm;
rcu_read_lock();
tm = tcp_get_metrics(sk, dst, true);
if (tm) {
struct tcp_sock *tp = tcp_sk(sk);
if ((s32)(tm->tcpm_ts - tp->rx_opt.ts_recent) <= 0 ||
((u32)get_seconds() - tm->tcpm_ts_stamp > TCP_PAWS_MSL &&
tm->tcpm_ts_stamp <= (u32)tp->rx_opt.ts_recent_stamp)) {
tm->tcpm_ts_stamp = (u32)tp->rx_opt.ts_recent_stamp;
tm->tcpm_ts = tp->rx_opt.ts_recent;
}
ret = true;
}
rcu_read_unlock();
}
return ret;
}
bool tcp_tw_remember_stamp(struct inet_timewait_sock *tw)
{
struct tcp_metrics_block *tm;
bool ret = false;
rcu_read_lock();
tm = __tcp_get_metrics_tw(tw);
if (tm) {
const struct tcp_timewait_sock *tcptw;
struct sock *sk = (struct sock *) tw;
tcptw = tcp_twsk(sk);
if ((s32)(tm->tcpm_ts - tcptw->tw_ts_recent) <= 0 ||
((u32)get_seconds() - tm->tcpm_ts_stamp > TCP_PAWS_MSL &&
tm->tcpm_ts_stamp <= (u32)tcptw->tw_ts_recent_stamp)) {
tm->tcpm_ts_stamp = (u32)tcptw->tw_ts_recent_stamp;
tm->tcpm_ts = tcptw->tw_ts_recent;
}
ret = true;
}
rcu_read_unlock();
return ret;
}
void tcp_fastopen_cache_get(struct sock *sk, u16 *mss,
struct tcp_fastopen_cookie *cookie,
int *syn_loss, unsigned long *last_syn_loss)
{
struct tcp_metrics_block *tm;
rcu_read_lock();
tm = tcp_get_metrics(sk, __sk_dst_get(sk), false);
if (tm) {
struct tcp_fastopen_metrics *tfom = &tm->tcpm_fastopen;
unsigned int seq;
do {
seq = read_seqbegin(&fastopen_seqlock);
if (tfom->mss)
*mss = tfom->mss;
*cookie = tfom->cookie;
*syn_loss = tfom->syn_loss;
*last_syn_loss = *syn_loss ? tfom->last_syn_loss : 0;
} while (read_seqretry(&fastopen_seqlock, seq));
}
rcu_read_unlock();
}
void tcp_fastopen_cache_set(struct sock *sk, u16 mss,
struct tcp_fastopen_cookie *cookie, bool syn_lost)
{
struct tcp_metrics_block *tm;
rcu_read_lock();
tm = tcp_get_metrics(sk, __sk_dst_get(sk), true);
if (tm) {
struct tcp_fastopen_metrics *tfom = &tm->tcpm_fastopen;
write_seqlock_bh(&fastopen_seqlock);
tfom->mss = mss;
if (cookie->len > 0)
tfom->cookie = *cookie;
if (syn_lost) {
++tfom->syn_loss;
tfom->last_syn_loss = jiffies;
} else
tfom->syn_loss = 0;
write_sequnlock_bh(&fastopen_seqlock);
}
rcu_read_unlock();
}
static int __init set_tcpmhash_entries(char *str)
{
ssize_t ret;
if (!str)
return 0;
ret = kstrtouint(str, 0, &tcpmhash_entries);
if (ret)
return 0;
return 1;
}
static int __net_init tcp_net_metrics_init(struct net *net)
{
size_t size;
unsigned int slots;
slots = tcpmhash_entries;
if (!slots) {
if (totalram_pages >= 128 * 1024)
slots = 16 * 1024;
else
slots = 8 * 1024;
}
net->ipv4.tcp_metrics_hash_log = order_base_2(slots);
size = sizeof(struct tcpm_hash_bucket) << net->ipv4.tcp_metrics_hash_log;
net->ipv4.tcp_metrics_hash = kzalloc(size, GFP_KERNEL);
if (!net->ipv4.tcp_metrics_hash)
return -ENOMEM;
return 0;
}
static void __net_exit tcp_net_metrics_exit(struct net *net)
{
unsigned int i;
for (i = 0; i < (1U << net->ipv4.tcp_metrics_hash_log) ; i++) {
struct tcp_metrics_block *tm, *next;
tm = rcu_dereference_protected(net->ipv4.tcp_metrics_hash[i].chain, 1);
while (tm) {
next = rcu_dereference_protected(tm->tcpm_next, 1);
kfree(tm);
tm = next;
}
}
kfree(net->ipv4.tcp_metrics_hash);
}
void __init tcp_metrics_init(void)
{
register_pernet_subsys(&tcp_net_metrics_ops);
}
