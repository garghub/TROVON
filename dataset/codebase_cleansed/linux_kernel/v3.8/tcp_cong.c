static struct tcp_congestion_ops *tcp_ca_find(const char *name)
{
struct tcp_congestion_ops *e;
list_for_each_entry_rcu(e, &tcp_cong_list, list) {
if (strcmp(e->name, name) == 0)
return e;
}
return NULL;
}
int tcp_register_congestion_control(struct tcp_congestion_ops *ca)
{
int ret = 0;
if (!ca->ssthresh || !ca->cong_avoid) {
pr_err("%s does not implement required ops\n", ca->name);
return -EINVAL;
}
spin_lock(&tcp_cong_list_lock);
if (tcp_ca_find(ca->name)) {
pr_notice("%s already registered\n", ca->name);
ret = -EEXIST;
} else {
list_add_tail_rcu(&ca->list, &tcp_cong_list);
pr_info("%s registered\n", ca->name);
}
spin_unlock(&tcp_cong_list_lock);
return ret;
}
void tcp_unregister_congestion_control(struct tcp_congestion_ops *ca)
{
spin_lock(&tcp_cong_list_lock);
list_del_rcu(&ca->list);
spin_unlock(&tcp_cong_list_lock);
}
void tcp_init_congestion_control(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_congestion_ops *ca;
if (icsk->icsk_ca_ops == &tcp_init_congestion_ops) {
rcu_read_lock();
list_for_each_entry_rcu(ca, &tcp_cong_list, list) {
if (try_module_get(ca->owner)) {
icsk->icsk_ca_ops = ca;
break;
}
}
rcu_read_unlock();
}
if (icsk->icsk_ca_ops->init)
icsk->icsk_ca_ops->init(sk);
}
void tcp_cleanup_congestion_control(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_ca_ops->release)
icsk->icsk_ca_ops->release(sk);
module_put(icsk->icsk_ca_ops->owner);
}
int tcp_set_default_congestion_control(const char *name)
{
struct tcp_congestion_ops *ca;
int ret = -ENOENT;
spin_lock(&tcp_cong_list_lock);
ca = tcp_ca_find(name);
#ifdef CONFIG_MODULES
if (!ca && capable(CAP_NET_ADMIN)) {
spin_unlock(&tcp_cong_list_lock);
request_module("tcp_%s", name);
spin_lock(&tcp_cong_list_lock);
ca = tcp_ca_find(name);
}
#endif
if (ca) {
ca->flags |= TCP_CONG_NON_RESTRICTED;
list_move(&ca->list, &tcp_cong_list);
ret = 0;
}
spin_unlock(&tcp_cong_list_lock);
return ret;
}
static int __init tcp_congestion_default(void)
{
return tcp_set_default_congestion_control(CONFIG_DEFAULT_TCP_CONG);
}
void tcp_get_available_congestion_control(char *buf, size_t maxlen)
{
struct tcp_congestion_ops *ca;
size_t offs = 0;
rcu_read_lock();
list_for_each_entry_rcu(ca, &tcp_cong_list, list) {
offs += snprintf(buf + offs, maxlen - offs,
"%s%s",
offs == 0 ? "" : " ", ca->name);
}
rcu_read_unlock();
}
void tcp_get_default_congestion_control(char *name)
{
struct tcp_congestion_ops *ca;
BUG_ON(list_empty(&tcp_cong_list));
rcu_read_lock();
ca = list_entry(tcp_cong_list.next, struct tcp_congestion_ops, list);
strncpy(name, ca->name, TCP_CA_NAME_MAX);
rcu_read_unlock();
}
void tcp_get_allowed_congestion_control(char *buf, size_t maxlen)
{
struct tcp_congestion_ops *ca;
size_t offs = 0;
*buf = '\0';
rcu_read_lock();
list_for_each_entry_rcu(ca, &tcp_cong_list, list) {
if (!(ca->flags & TCP_CONG_NON_RESTRICTED))
continue;
offs += snprintf(buf + offs, maxlen - offs,
"%s%s",
offs == 0 ? "" : " ", ca->name);
}
rcu_read_unlock();
}
int tcp_set_allowed_congestion_control(char *val)
{
struct tcp_congestion_ops *ca;
char *saved_clone, *clone, *name;
int ret = 0;
saved_clone = clone = kstrdup(val, GFP_USER);
if (!clone)
return -ENOMEM;
spin_lock(&tcp_cong_list_lock);
while ((name = strsep(&clone, " ")) && *name) {
ca = tcp_ca_find(name);
if (!ca) {
ret = -ENOENT;
goto out;
}
}
list_for_each_entry_rcu(ca, &tcp_cong_list, list)
ca->flags &= ~TCP_CONG_NON_RESTRICTED;
while ((name = strsep(&val, " ")) && *name) {
ca = tcp_ca_find(name);
WARN_ON(!ca);
if (ca)
ca->flags |= TCP_CONG_NON_RESTRICTED;
}
out:
spin_unlock(&tcp_cong_list_lock);
kfree(saved_clone);
return ret;
}
int tcp_set_congestion_control(struct sock *sk, const char *name)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_congestion_ops *ca;
int err = 0;
rcu_read_lock();
ca = tcp_ca_find(name);
if (ca == icsk->icsk_ca_ops)
goto out;
#ifdef CONFIG_MODULES
if (!ca && capable(CAP_NET_ADMIN)) {
rcu_read_unlock();
request_module("tcp_%s", name);
rcu_read_lock();
ca = tcp_ca_find(name);
}
#endif
if (!ca)
err = -ENOENT;
else if (!((ca->flags & TCP_CONG_NON_RESTRICTED) ||
ns_capable(sock_net(sk)->user_ns, CAP_NET_ADMIN)))
err = -EPERM;
else if (!try_module_get(ca->owner))
err = -EBUSY;
else {
tcp_cleanup_congestion_control(sk);
icsk->icsk_ca_ops = ca;
if (sk->sk_state != TCP_CLOSE && icsk->icsk_ca_ops->init)
icsk->icsk_ca_ops->init(sk);
}
out:
rcu_read_unlock();
return err;
}
bool tcp_is_cwnd_limited(const struct sock *sk, u32 in_flight)
{
const struct tcp_sock *tp = tcp_sk(sk);
u32 left;
if (in_flight >= tp->snd_cwnd)
return true;
left = tp->snd_cwnd - in_flight;
if (sk_can_gso(sk) &&
left * sysctl_tcp_tso_win_divisor < tp->snd_cwnd &&
left * tp->mss_cache < sk->sk_gso_max_size &&
left < sk->sk_gso_max_segs)
return true;
return left <= tcp_max_tso_deferred_mss(tp);
}
void tcp_slow_start(struct tcp_sock *tp)
{
int cnt;
unsigned int delta = 0;
u32 snd_cwnd = tp->snd_cwnd;
if (unlikely(!snd_cwnd)) {
pr_err_once("snd_cwnd is nul, please report this bug.\n");
snd_cwnd = 1U;
}
if (sysctl_tcp_abc && tp->bytes_acked < tp->mss_cache)
return;
if (sysctl_tcp_max_ssthresh > 0 && tp->snd_cwnd > sysctl_tcp_max_ssthresh)
cnt = sysctl_tcp_max_ssthresh >> 1;
else
cnt = snd_cwnd;
if (sysctl_tcp_abc > 1 && tp->bytes_acked >= 2*tp->mss_cache)
cnt <<= 1;
tp->bytes_acked = 0;
tp->snd_cwnd_cnt += cnt;
while (tp->snd_cwnd_cnt >= snd_cwnd) {
tp->snd_cwnd_cnt -= snd_cwnd;
delta++;
}
tp->snd_cwnd = min(snd_cwnd + delta, tp->snd_cwnd_clamp);
}
void tcp_cong_avoid_ai(struct tcp_sock *tp, u32 w)
{
if (tp->snd_cwnd_cnt >= w) {
if (tp->snd_cwnd < tp->snd_cwnd_clamp)
tp->snd_cwnd++;
tp->snd_cwnd_cnt = 0;
} else {
tp->snd_cwnd_cnt++;
}
}
void tcp_reno_cong_avoid(struct sock *sk, u32 ack, u32 in_flight)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!tcp_is_cwnd_limited(sk, in_flight))
return;
if (tp->snd_cwnd <= tp->snd_ssthresh)
tcp_slow_start(tp);
else if (sysctl_tcp_abc) {
if (tp->bytes_acked >= tp->snd_cwnd*tp->mss_cache) {
tp->bytes_acked -= tp->snd_cwnd*tp->mss_cache;
if (tp->snd_cwnd < tp->snd_cwnd_clamp)
tp->snd_cwnd++;
}
} else {
tcp_cong_avoid_ai(tp, tp->snd_cwnd);
}
}
u32 tcp_reno_ssthresh(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
return max(tp->snd_cwnd >> 1U, 2U);
}
u32 tcp_reno_min_cwnd(const struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
return tp->snd_ssthresh/2;
}
