static struct tcp_congestion_ops *tcp_ca_find(const char *name)
{
struct tcp_congestion_ops *e;
list_for_each_entry_rcu(e, &tcp_cong_list, list) {
if (strcmp(e->name, name) == 0)
return e;
}
return NULL;
}
static const struct tcp_congestion_ops *__tcp_ca_find_autoload(const char *name)
{
const struct tcp_congestion_ops *ca = tcp_ca_find(name);
#ifdef CONFIG_MODULES
if (!ca && capable(CAP_NET_ADMIN)) {
rcu_read_unlock();
request_module("tcp_%s", name);
rcu_read_lock();
ca = tcp_ca_find(name);
}
#endif
return ca;
}
struct tcp_congestion_ops *tcp_ca_find_key(u32 key)
{
struct tcp_congestion_ops *e;
list_for_each_entry_rcu(e, &tcp_cong_list, list) {
if (e->key == key)
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
ca->key = jhash(ca->name, sizeof(ca->name), strlen(ca->name));
spin_lock(&tcp_cong_list_lock);
if (ca->key == TCP_CA_UNSPEC || tcp_ca_find_key(ca->key)) {
pr_notice("%s already registered or non-unique key\n",
ca->name);
ret = -EEXIST;
} else {
list_add_tail_rcu(&ca->list, &tcp_cong_list);
pr_debug("%s registered\n", ca->name);
}
spin_unlock(&tcp_cong_list_lock);
return ret;
}
void tcp_unregister_congestion_control(struct tcp_congestion_ops *ca)
{
spin_lock(&tcp_cong_list_lock);
list_del_rcu(&ca->list);
spin_unlock(&tcp_cong_list_lock);
synchronize_rcu();
}
u32 tcp_ca_get_key_by_name(const char *name, bool *ecn_ca)
{
const struct tcp_congestion_ops *ca;
u32 key = TCP_CA_UNSPEC;
might_sleep();
rcu_read_lock();
ca = __tcp_ca_find_autoload(name);
if (ca) {
key = ca->key;
*ecn_ca = ca->flags & TCP_CONG_NEEDS_ECN;
}
rcu_read_unlock();
return key;
}
char *tcp_ca_get_name_by_key(u32 key, char *buffer)
{
const struct tcp_congestion_ops *ca;
char *ret = NULL;
rcu_read_lock();
ca = tcp_ca_find_key(key);
if (ca)
ret = strncpy(buffer, ca->name,
TCP_CA_NAME_MAX);
rcu_read_unlock();
return ret;
}
void tcp_assign_congestion_control(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct tcp_congestion_ops *ca;
rcu_read_lock();
list_for_each_entry_rcu(ca, &tcp_cong_list, list) {
if (likely(try_module_get(ca->owner))) {
icsk->icsk_ca_ops = ca;
goto out;
}
}
out:
rcu_read_unlock();
if (ca->get_info)
memset(icsk->icsk_ca_priv, 0, sizeof(icsk->icsk_ca_priv));
if (ca->flags & TCP_CONG_NEEDS_ECN)
INET_ECN_xmit(sk);
else
INET_ECN_dontxmit(sk);
}
void tcp_init_congestion_control(struct sock *sk)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_ca_ops->init)
icsk->icsk_ca_ops->init(sk);
if (tcp_ca_needs_ecn(sk))
INET_ECN_xmit(sk);
else
INET_ECN_dontxmit(sk);
}
static void tcp_reinit_congestion_control(struct sock *sk,
const struct tcp_congestion_ops *ca)
{
struct inet_connection_sock *icsk = inet_csk(sk);
tcp_cleanup_congestion_control(sk);
icsk->icsk_ca_ops = ca;
icsk->icsk_ca_setsockopt = 1;
if (sk->sk_state != TCP_CLOSE)
tcp_init_congestion_control(sk);
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
const struct tcp_congestion_ops *ca;
int err = 0;
if (icsk->icsk_ca_dst_locked)
return -EPERM;
rcu_read_lock();
ca = __tcp_ca_find_autoload(name);
if (ca == icsk->icsk_ca_ops) {
icsk->icsk_ca_setsockopt = 1;
goto out;
}
if (!ca)
err = -ENOENT;
else if (!((ca->flags & TCP_CONG_NON_RESTRICTED) ||
ns_capable(sock_net(sk)->user_ns, CAP_NET_ADMIN)))
err = -EPERM;
else if (!try_module_get(ca->owner))
err = -EBUSY;
else
tcp_reinit_congestion_control(sk, ca);
out:
rcu_read_unlock();
return err;
}
u32 tcp_slow_start(struct tcp_sock *tp, u32 acked)
{
u32 cwnd = min(tp->snd_cwnd + acked, tp->snd_ssthresh);
acked -= cwnd - tp->snd_cwnd;
tp->snd_cwnd = min(cwnd, tp->snd_cwnd_clamp);
return acked;
}
void tcp_cong_avoid_ai(struct tcp_sock *tp, u32 w, u32 acked)
{
if (tp->snd_cwnd_cnt >= w) {
tp->snd_cwnd_cnt = 0;
tp->snd_cwnd++;
}
tp->snd_cwnd_cnt += acked;
if (tp->snd_cwnd_cnt >= w) {
u32 delta = tp->snd_cwnd_cnt / w;
tp->snd_cwnd_cnt -= delta * w;
tp->snd_cwnd += delta;
}
tp->snd_cwnd = min(tp->snd_cwnd, tp->snd_cwnd_clamp);
}
void tcp_reno_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
struct tcp_sock *tp = tcp_sk(sk);
if (!tcp_is_cwnd_limited(sk))
return;
if (tcp_in_slow_start(tp)) {
acked = tcp_slow_start(tp, acked);
if (!acked)
return;
}
tcp_cong_avoid_ai(tp, tp->snd_cwnd, acked);
}
u32 tcp_reno_ssthresh(struct sock *sk)
{
const struct tcp_sock *tp = tcp_sk(sk);
return max(tp->snd_cwnd >> 1U, 2U);
}
