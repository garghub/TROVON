static inline struct net *tm_net(struct tcp_metrics_block *tm)
{
return read_pnet(&tm->tcpm_net);
}
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
static void tcp_metric_set(struct tcp_metrics_block *tm,
enum tcp_metric_index idx,
u32 val)
{
tm->tcpm_vals[idx] = val;
}
static bool addr_same(const struct inetpeer_addr *a,
const struct inetpeer_addr *b)
{
return inetpeer_addr_cmp(a, b) == 0;
}
static void tcpm_suck_dst(struct tcp_metrics_block *tm,
const struct dst_entry *dst,
bool fastopen_clear)
{
u32 msval;
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
msval = dst_metric_raw(dst, RTAX_RTT);
tm->tcpm_vals[TCP_METRIC_RTT] = msval * USEC_PER_MSEC;
msval = dst_metric_raw(dst, RTAX_RTTVAR);
tm->tcpm_vals[TCP_METRIC_RTTVAR] = msval * USEC_PER_MSEC;
tm->tcpm_vals[TCP_METRIC_SSTHRESH] = dst_metric_raw(dst, RTAX_SSTHRESH);
tm->tcpm_vals[TCP_METRIC_CWND] = dst_metric_raw(dst, RTAX_CWND);
tm->tcpm_vals[TCP_METRIC_REORDERING] = dst_metric_raw(dst, RTAX_REORDERING);
if (fastopen_clear) {
tm->tcpm_fastopen.mss = 0;
tm->tcpm_fastopen.syn_loss = 0;
tm->tcpm_fastopen.try_exp = 0;
tm->tcpm_fastopen.cookie.exp = false;
tm->tcpm_fastopen.cookie.len = 0;
}
}
static void tcpm_check_stamp(struct tcp_metrics_block *tm, struct dst_entry *dst)
{
if (tm && unlikely(time_after(jiffies, tm->tcpm_stamp + TCP_METRICS_TIMEOUT)))
tcpm_suck_dst(tm, dst, false);
}
static struct tcp_metrics_block *tcpm_new(struct dst_entry *dst,
struct inetpeer_addr *saddr,
struct inetpeer_addr *daddr,
unsigned int hash)
{
struct tcp_metrics_block *tm;
struct net *net;
bool reclaim = false;
spin_lock_bh(&tcp_metrics_lock);
net = dev_net(dst->dev);
tm = __tcp_get_metrics(saddr, daddr, net, hash);
if (tm == TCP_METRICS_RECLAIM_PTR) {
reclaim = true;
tm = NULL;
}
if (tm) {
tcpm_check_stamp(tm, dst);
goto out_unlock;
}
if (unlikely(reclaim)) {
struct tcp_metrics_block *oldest;
oldest = deref_locked(tcp_metrics_hash[hash].chain);
for (tm = deref_locked(oldest->tcpm_next); tm;
tm = deref_locked(tm->tcpm_next)) {
if (time_before(tm->tcpm_stamp, oldest->tcpm_stamp))
oldest = tm;
}
tm = oldest;
} else {
tm = kmalloc(sizeof(*tm), GFP_ATOMIC);
if (!tm)
goto out_unlock;
}
write_pnet(&tm->tcpm_net, net);
tm->tcpm_saddr = *saddr;
tm->tcpm_daddr = *daddr;
tcpm_suck_dst(tm, dst, true);
if (likely(!reclaim)) {
tm->tcpm_next = tcp_metrics_hash[hash].chain;
rcu_assign_pointer(tcp_metrics_hash[hash].chain, tm);
}
out_unlock:
spin_unlock_bh(&tcp_metrics_lock);
return tm;
}
static struct tcp_metrics_block *tcp_get_encode(struct tcp_metrics_block *tm, int depth)
{
if (tm)
return tm;
if (depth > TCP_METRICS_RECLAIM_DEPTH)
return TCP_METRICS_RECLAIM_PTR;
return NULL;
}
static struct tcp_metrics_block *__tcp_get_metrics(const struct inetpeer_addr *saddr,
const struct inetpeer_addr *daddr,
struct net *net, unsigned int hash)
{
struct tcp_metrics_block *tm;
int depth = 0;
for (tm = rcu_dereference(tcp_metrics_hash[hash].chain); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (addr_same(&tm->tcpm_saddr, saddr) &&
addr_same(&tm->tcpm_daddr, daddr) &&
net_eq(tm_net(tm), net))
break;
depth++;
}
return tcp_get_encode(tm, depth);
}
static struct tcp_metrics_block *__tcp_get_metrics_req(struct request_sock *req,
struct dst_entry *dst)
{
struct tcp_metrics_block *tm;
struct inetpeer_addr saddr, daddr;
unsigned int hash;
struct net *net;
saddr.family = req->rsk_ops->family;
daddr.family = req->rsk_ops->family;
switch (daddr.family) {
case AF_INET:
inetpeer_set_addr_v4(&saddr, inet_rsk(req)->ir_loc_addr);
inetpeer_set_addr_v4(&daddr, inet_rsk(req)->ir_rmt_addr);
hash = ipv4_addr_hash(inet_rsk(req)->ir_rmt_addr);
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
inetpeer_set_addr_v6(&saddr, &inet_rsk(req)->ir_v6_loc_addr);
inetpeer_set_addr_v6(&daddr, &inet_rsk(req)->ir_v6_rmt_addr);
hash = ipv6_addr_hash(&inet_rsk(req)->ir_v6_rmt_addr);
break;
#endif
default:
return NULL;
}
net = dev_net(dst->dev);
hash ^= net_hash_mix(net);
hash = hash_32(hash, tcp_metrics_hash_log);
for (tm = rcu_dereference(tcp_metrics_hash[hash].chain); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (addr_same(&tm->tcpm_saddr, &saddr) &&
addr_same(&tm->tcpm_daddr, &daddr) &&
net_eq(tm_net(tm), net))
break;
}
tcpm_check_stamp(tm, dst);
return tm;
}
static struct tcp_metrics_block *tcp_get_metrics(struct sock *sk,
struct dst_entry *dst,
bool create)
{
struct tcp_metrics_block *tm;
struct inetpeer_addr saddr, daddr;
unsigned int hash;
struct net *net;
if (sk->sk_family == AF_INET) {
inetpeer_set_addr_v4(&saddr, inet_sk(sk)->inet_saddr);
inetpeer_set_addr_v4(&daddr, inet_sk(sk)->inet_daddr);
hash = ipv4_addr_hash(inet_sk(sk)->inet_daddr);
}
#if IS_ENABLED(CONFIG_IPV6)
else if (sk->sk_family == AF_INET6) {
if (ipv6_addr_v4mapped(&sk->sk_v6_daddr)) {
inetpeer_set_addr_v4(&saddr, inet_sk(sk)->inet_saddr);
inetpeer_set_addr_v4(&daddr, inet_sk(sk)->inet_daddr);
hash = ipv4_addr_hash(inet_sk(sk)->inet_daddr);
} else {
inetpeer_set_addr_v6(&saddr, &sk->sk_v6_rcv_saddr);
inetpeer_set_addr_v6(&daddr, &sk->sk_v6_daddr);
hash = ipv6_addr_hash(&sk->sk_v6_daddr);
}
}
#endif
else
return NULL;
net = dev_net(dst->dev);
hash ^= net_hash_mix(net);
hash = hash_32(hash, tcp_metrics_hash_log);
tm = __tcp_get_metrics(&saddr, &daddr, net, hash);
if (tm == TCP_METRICS_RECLAIM_PTR)
tm = NULL;
if (!tm && create)
tm = tcpm_new(dst, &saddr, &daddr, hash);
else
tcpm_check_stamp(tm, dst);
return tm;
}
void tcp_update_metrics(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
struct dst_entry *dst = __sk_dst_get(sk);
struct tcp_sock *tp = tcp_sk(sk);
struct net *net = sock_net(sk);
struct tcp_metrics_block *tm;
unsigned long rtt;
u32 val;
int m;
sk_dst_confirm(sk);
if (sysctl_tcp_nometrics_save || !dst)
return;
rcu_read_lock();
if (icsk->icsk_backoff || !tp->srtt_us) {
tm = tcp_get_metrics(sk, dst, false);
if (tm && !tcp_metric_locked(tm, TCP_METRIC_RTT))
tcp_metric_set(tm, TCP_METRIC_RTT, 0);
goto out_unlock;
} else
tm = tcp_get_metrics(sk, dst, true);
if (!tm)
goto out_unlock;
rtt = tcp_metric_get(tm, TCP_METRIC_RTT);
m = rtt - tp->srtt_us;
if (!tcp_metric_locked(tm, TCP_METRIC_RTT)) {
if (m <= 0)
rtt = tp->srtt_us;
else
rtt -= (m >> 3);
tcp_metric_set(tm, TCP_METRIC_RTT, rtt);
}
if (!tcp_metric_locked(tm, TCP_METRIC_RTTVAR)) {
unsigned long var;
if (m < 0)
m = -m;
m >>= 1;
if (m < tp->mdev_us)
m = tp->mdev_us;
var = tcp_metric_get(tm, TCP_METRIC_RTTVAR);
if (m >= var)
var = m;
else
var -= (var - m) >> 2;
tcp_metric_set(tm, TCP_METRIC_RTTVAR, var);
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
} else if (!tcp_in_slow_start(tp) &&
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
tp->reordering != net->ipv4.sysctl_tcp_reordering)
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
u32 val, crtt = 0;
sk_dst_confirm(sk);
if (!dst)
goto reset;
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
tp->reordering = val;
}
crtt = tcp_metric_get(tm, TCP_METRIC_RTT);
rcu_read_unlock();
reset:
if (crtt > tp->srtt_us) {
crtt /= 8 * USEC_PER_SEC / HZ;
inet_csk(sk)->icsk_rto = crtt + max(2 * crtt, tcp_rto_min(sk));
} else if (tp->srtt_us == 0) {
tp->rttvar_us = jiffies_to_usecs(TCP_TIMEOUT_FALLBACK);
tp->mdev_us = tp->mdev_max_us = tp->rttvar_us;
inet_csk(sk)->icsk_rto = TCP_TIMEOUT_FALLBACK;
}
if (tp->total_retrans > 1)
tp->snd_cwnd = 1;
else
tp->snd_cwnd = tcp_init_cwnd(tp, dst);
tp->snd_cwnd_stamp = tcp_time_stamp;
}
bool tcp_peer_is_proven(struct request_sock *req, struct dst_entry *dst)
{
struct tcp_metrics_block *tm;
bool ret;
if (!dst)
return false;
rcu_read_lock();
tm = __tcp_get_metrics_req(req, dst);
if (tm && tcp_metric_get(tm, TCP_METRIC_RTT))
ret = true;
else
ret = false;
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
if (cookie->len <= 0 && tfom->try_exp == 1)
cookie->exp = true;
*syn_loss = tfom->syn_loss;
*last_syn_loss = *syn_loss ? tfom->last_syn_loss : 0;
} while (read_seqretry(&fastopen_seqlock, seq));
}
rcu_read_unlock();
}
void tcp_fastopen_cache_set(struct sock *sk, u16 mss,
struct tcp_fastopen_cookie *cookie, bool syn_lost,
u16 try_exp)
{
struct dst_entry *dst = __sk_dst_get(sk);
struct tcp_metrics_block *tm;
if (!dst)
return;
rcu_read_lock();
tm = tcp_get_metrics(sk, dst, true);
if (tm) {
struct tcp_fastopen_metrics *tfom = &tm->tcpm_fastopen;
write_seqlock_bh(&fastopen_seqlock);
if (mss)
tfom->mss = mss;
if (cookie && cookie->len > 0)
tfom->cookie = *cookie;
else if (try_exp > tfom->try_exp &&
tfom->cookie.len <= 0 && !tfom->cookie.exp)
tfom->try_exp = try_exp;
if (syn_lost) {
++tfom->syn_loss;
tfom->last_syn_loss = jiffies;
} else
tfom->syn_loss = 0;
write_sequnlock_bh(&fastopen_seqlock);
}
rcu_read_unlock();
}
static int tcp_metrics_fill_info(struct sk_buff *msg,
struct tcp_metrics_block *tm)
{
struct nlattr *nest;
int i;
switch (tm->tcpm_daddr.family) {
case AF_INET:
if (nla_put_in_addr(msg, TCP_METRICS_ATTR_ADDR_IPV4,
inetpeer_get_addr_v4(&tm->tcpm_daddr)) < 0)
goto nla_put_failure;
if (nla_put_in_addr(msg, TCP_METRICS_ATTR_SADDR_IPV4,
inetpeer_get_addr_v4(&tm->tcpm_saddr)) < 0)
goto nla_put_failure;
break;
case AF_INET6:
if (nla_put_in6_addr(msg, TCP_METRICS_ATTR_ADDR_IPV6,
inetpeer_get_addr_v6(&tm->tcpm_daddr)) < 0)
goto nla_put_failure;
if (nla_put_in6_addr(msg, TCP_METRICS_ATTR_SADDR_IPV6,
inetpeer_get_addr_v6(&tm->tcpm_saddr)) < 0)
goto nla_put_failure;
break;
default:
return -EAFNOSUPPORT;
}
if (nla_put_msecs(msg, TCP_METRICS_ATTR_AGE,
jiffies - tm->tcpm_stamp,
TCP_METRICS_ATTR_PAD) < 0)
goto nla_put_failure;
{
int n = 0;
nest = nla_nest_start(msg, TCP_METRICS_ATTR_VALS);
if (!nest)
goto nla_put_failure;
for (i = 0; i < TCP_METRIC_MAX_KERNEL + 1; i++) {
u32 val = tm->tcpm_vals[i];
if (!val)
continue;
if (i == TCP_METRIC_RTT) {
if (nla_put_u32(msg, TCP_METRIC_RTT_US + 1,
val) < 0)
goto nla_put_failure;
n++;
val = max(val / 1000, 1U);
}
if (i == TCP_METRIC_RTTVAR) {
if (nla_put_u32(msg, TCP_METRIC_RTTVAR_US + 1,
val) < 0)
goto nla_put_failure;
n++;
val = max(val / 1000, 1U);
}
if (nla_put_u32(msg, i + 1, val) < 0)
goto nla_put_failure;
n++;
}
if (n)
nla_nest_end(msg, nest);
else
nla_nest_cancel(msg, nest);
}
{
struct tcp_fastopen_metrics tfom_copy[1], *tfom;
unsigned int seq;
do {
seq = read_seqbegin(&fastopen_seqlock);
tfom_copy[0] = tm->tcpm_fastopen;
} while (read_seqretry(&fastopen_seqlock, seq));
tfom = tfom_copy;
if (tfom->mss &&
nla_put_u16(msg, TCP_METRICS_ATTR_FOPEN_MSS,
tfom->mss) < 0)
goto nla_put_failure;
if (tfom->syn_loss &&
(nla_put_u16(msg, TCP_METRICS_ATTR_FOPEN_SYN_DROPS,
tfom->syn_loss) < 0 ||
nla_put_msecs(msg, TCP_METRICS_ATTR_FOPEN_SYN_DROP_TS,
jiffies - tfom->last_syn_loss,
TCP_METRICS_ATTR_PAD) < 0))
goto nla_put_failure;
if (tfom->cookie.len > 0 &&
nla_put(msg, TCP_METRICS_ATTR_FOPEN_COOKIE,
tfom->cookie.len, tfom->cookie.val) < 0)
goto nla_put_failure;
}
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int tcp_metrics_dump_info(struct sk_buff *skb,
struct netlink_callback *cb,
struct tcp_metrics_block *tm)
{
void *hdr;
hdr = genlmsg_put(skb, NETLINK_CB(cb->skb).portid, cb->nlh->nlmsg_seq,
&tcp_metrics_nl_family, NLM_F_MULTI,
TCP_METRICS_CMD_GET);
if (!hdr)
return -EMSGSIZE;
if (tcp_metrics_fill_info(skb, tm) < 0)
goto nla_put_failure;
genlmsg_end(skb, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int tcp_metrics_nl_dump(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
unsigned int max_rows = 1U << tcp_metrics_hash_log;
unsigned int row, s_row = cb->args[0];
int s_col = cb->args[1], col = s_col;
for (row = s_row; row < max_rows; row++, s_col = 0) {
struct tcp_metrics_block *tm;
struct tcpm_hash_bucket *hb = tcp_metrics_hash + row;
rcu_read_lock();
for (col = 0, tm = rcu_dereference(hb->chain); tm;
tm = rcu_dereference(tm->tcpm_next), col++) {
if (!net_eq(tm_net(tm), net))
continue;
if (col < s_col)
continue;
if (tcp_metrics_dump_info(skb, cb, tm) < 0) {
rcu_read_unlock();
goto done;
}
}
rcu_read_unlock();
}
done:
cb->args[0] = row;
cb->args[1] = col;
return skb->len;
}
static int __parse_nl_addr(struct genl_info *info, struct inetpeer_addr *addr,
unsigned int *hash, int optional, int v4, int v6)
{
struct nlattr *a;
a = info->attrs[v4];
if (a) {
inetpeer_set_addr_v4(addr, nla_get_in_addr(a));
if (hash)
*hash = ipv4_addr_hash(inetpeer_get_addr_v4(addr));
return 0;
}
a = info->attrs[v6];
if (a) {
struct in6_addr in6;
if (nla_len(a) != sizeof(struct in6_addr))
return -EINVAL;
in6 = nla_get_in6_addr(a);
inetpeer_set_addr_v6(addr, &in6);
if (hash)
*hash = ipv6_addr_hash(inetpeer_get_addr_v6(addr));
return 0;
}
return optional ? 1 : -EAFNOSUPPORT;
}
static int parse_nl_addr(struct genl_info *info, struct inetpeer_addr *addr,
unsigned int *hash, int optional)
{
return __parse_nl_addr(info, addr, hash, optional,
TCP_METRICS_ATTR_ADDR_IPV4,
TCP_METRICS_ATTR_ADDR_IPV6);
}
static int parse_nl_saddr(struct genl_info *info, struct inetpeer_addr *addr)
{
return __parse_nl_addr(info, addr, NULL, 0,
TCP_METRICS_ATTR_SADDR_IPV4,
TCP_METRICS_ATTR_SADDR_IPV6);
}
static int tcp_metrics_nl_cmd_get(struct sk_buff *skb, struct genl_info *info)
{
struct tcp_metrics_block *tm;
struct inetpeer_addr saddr, daddr;
unsigned int hash;
struct sk_buff *msg;
struct net *net = genl_info_net(info);
void *reply;
int ret;
bool src = true;
ret = parse_nl_addr(info, &daddr, &hash, 0);
if (ret < 0)
return ret;
ret = parse_nl_saddr(info, &saddr);
if (ret < 0)
src = false;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
reply = genlmsg_put_reply(msg, info, &tcp_metrics_nl_family, 0,
info->genlhdr->cmd);
if (!reply)
goto nla_put_failure;
hash ^= net_hash_mix(net);
hash = hash_32(hash, tcp_metrics_hash_log);
ret = -ESRCH;
rcu_read_lock();
for (tm = rcu_dereference(tcp_metrics_hash[hash].chain); tm;
tm = rcu_dereference(tm->tcpm_next)) {
if (addr_same(&tm->tcpm_daddr, &daddr) &&
(!src || addr_same(&tm->tcpm_saddr, &saddr)) &&
net_eq(tm_net(tm), net)) {
ret = tcp_metrics_fill_info(msg, tm);
break;
}
}
rcu_read_unlock();
if (ret < 0)
goto out_free;
genlmsg_end(msg, reply);
return genlmsg_reply(msg, info);
nla_put_failure:
ret = -EMSGSIZE;
out_free:
nlmsg_free(msg);
return ret;
}
static void tcp_metrics_flush_all(struct net *net)
{
unsigned int max_rows = 1U << tcp_metrics_hash_log;
struct tcpm_hash_bucket *hb = tcp_metrics_hash;
struct tcp_metrics_block *tm;
unsigned int row;
for (row = 0; row < max_rows; row++, hb++) {
struct tcp_metrics_block __rcu **pp;
spin_lock_bh(&tcp_metrics_lock);
pp = &hb->chain;
for (tm = deref_locked(*pp); tm; tm = deref_locked(*pp)) {
if (net_eq(tm_net(tm), net)) {
*pp = tm->tcpm_next;
kfree_rcu(tm, rcu_head);
} else {
pp = &tm->tcpm_next;
}
}
spin_unlock_bh(&tcp_metrics_lock);
}
}
static int tcp_metrics_nl_cmd_del(struct sk_buff *skb, struct genl_info *info)
{
struct tcpm_hash_bucket *hb;
struct tcp_metrics_block *tm;
struct tcp_metrics_block __rcu **pp;
struct inetpeer_addr saddr, daddr;
unsigned int hash;
struct net *net = genl_info_net(info);
int ret;
bool src = true, found = false;
ret = parse_nl_addr(info, &daddr, &hash, 1);
if (ret < 0)
return ret;
if (ret > 0) {
tcp_metrics_flush_all(net);
return 0;
}
ret = parse_nl_saddr(info, &saddr);
if (ret < 0)
src = false;
hash ^= net_hash_mix(net);
hash = hash_32(hash, tcp_metrics_hash_log);
hb = tcp_metrics_hash + hash;
pp = &hb->chain;
spin_lock_bh(&tcp_metrics_lock);
for (tm = deref_locked(*pp); tm; tm = deref_locked(*pp)) {
if (addr_same(&tm->tcpm_daddr, &daddr) &&
(!src || addr_same(&tm->tcpm_saddr, &saddr)) &&
net_eq(tm_net(tm), net)) {
*pp = tm->tcpm_next;
kfree_rcu(tm, rcu_head);
found = true;
} else {
pp = &tm->tcpm_next;
}
}
spin_unlock_bh(&tcp_metrics_lock);
if (!found)
return -ESRCH;
return 0;
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
if (!net_eq(net, &init_net))
return 0;
slots = tcpmhash_entries;
if (!slots) {
if (totalram_pages >= 128 * 1024)
slots = 16 * 1024;
else
slots = 8 * 1024;
}
tcp_metrics_hash_log = order_base_2(slots);
size = sizeof(struct tcpm_hash_bucket) << tcp_metrics_hash_log;
tcp_metrics_hash = kvzalloc(size, GFP_KERNEL);
if (!tcp_metrics_hash)
return -ENOMEM;
return 0;
}
static void __net_exit tcp_net_metrics_exit(struct net *net)
{
tcp_metrics_flush_all(net);
}
void __init tcp_metrics_init(void)
{
int ret;
ret = register_pernet_subsys(&tcp_net_metrics_ops);
if (ret < 0)
panic("Could not allocate the tcp_metrics hash table\n");
ret = genl_register_family(&tcp_metrics_nl_family);
if (ret < 0)
panic("Could not register tcp_metrics generic netlink\n");
}
