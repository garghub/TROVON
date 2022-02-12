void inet_get_local_port_range(struct net *net, int *low, int *high)
{
unsigned int seq;
do {
seq = read_seqbegin(&net->ipv4.ip_local_ports.lock);
*low = net->ipv4.ip_local_ports.range[0];
*high = net->ipv4.ip_local_ports.range[1];
} while (read_seqretry(&net->ipv4.ip_local_ports.lock, seq));
}
int inet_csk_bind_conflict(const struct sock *sk,
const struct inet_bind_bucket *tb, bool relax)
{
struct sock *sk2;
int reuse = sk->sk_reuse;
int reuseport = sk->sk_reuseport;
kuid_t uid = sock_i_uid((struct sock *)sk);
sk_for_each_bound(sk2, &tb->owners) {
if (sk != sk2 &&
!inet_v6_ipv6only(sk2) &&
(!sk->sk_bound_dev_if ||
!sk2->sk_bound_dev_if ||
sk->sk_bound_dev_if == sk2->sk_bound_dev_if)) {
if ((!reuse || !sk2->sk_reuse ||
sk2->sk_state == TCP_LISTEN) &&
(!reuseport || !sk2->sk_reuseport ||
rcu_access_pointer(sk->sk_reuseport_cb) ||
(sk2->sk_state != TCP_TIME_WAIT &&
!uid_eq(uid, sock_i_uid(sk2))))) {
if (!sk2->sk_rcv_saddr || !sk->sk_rcv_saddr ||
sk2->sk_rcv_saddr == sk->sk_rcv_saddr)
break;
}
if (!relax && reuse && sk2->sk_reuse &&
sk2->sk_state != TCP_LISTEN) {
if (!sk2->sk_rcv_saddr || !sk->sk_rcv_saddr ||
sk2->sk_rcv_saddr == sk->sk_rcv_saddr)
break;
}
}
}
return sk2 != NULL;
}
int inet_csk_get_port(struct sock *sk, unsigned short snum)
{
bool reuse = sk->sk_reuse && sk->sk_state != TCP_LISTEN;
struct inet_hashinfo *hinfo = sk->sk_prot->h.hashinfo;
int ret = 1, attempts = 5, port = snum;
int smallest_size = -1, smallest_port;
struct inet_bind_hashbucket *head;
struct net *net = sock_net(sk);
int i, low, high, attempt_half;
struct inet_bind_bucket *tb;
kuid_t uid = sock_i_uid(sk);
u32 remaining, offset;
if (port) {
have_port:
head = &hinfo->bhash[inet_bhashfn(net, port,
hinfo->bhash_size)];
spin_lock_bh(&head->lock);
inet_bind_bucket_for_each(tb, &head->chain)
if (net_eq(ib_net(tb), net) && tb->port == port)
goto tb_found;
goto tb_not_found;
}
again:
attempt_half = (sk->sk_reuse == SK_CAN_REUSE) ? 1 : 0;
other_half_scan:
inet_get_local_port_range(net, &low, &high);
high++;
if (high - low < 4)
attempt_half = 0;
if (attempt_half) {
int half = low + (((high - low) >> 2) << 1);
if (attempt_half == 1)
high = half;
else
low = half;
}
remaining = high - low;
if (likely(remaining > 1))
remaining &= ~1U;
offset = prandom_u32() % remaining;
offset |= 1U;
smallest_size = -1;
smallest_port = low;
other_parity_scan:
port = low + offset;
for (i = 0; i < remaining; i += 2, port += 2) {
if (unlikely(port >= high))
port -= remaining;
if (inet_is_local_reserved_port(net, port))
continue;
head = &hinfo->bhash[inet_bhashfn(net, port,
hinfo->bhash_size)];
spin_lock_bh(&head->lock);
inet_bind_bucket_for_each(tb, &head->chain)
if (net_eq(ib_net(tb), net) && tb->port == port) {
if (((tb->fastreuse > 0 && reuse) ||
(tb->fastreuseport > 0 &&
sk->sk_reuseport &&
!rcu_access_pointer(sk->sk_reuseport_cb) &&
uid_eq(tb->fastuid, uid))) &&
(tb->num_owners < smallest_size || smallest_size == -1)) {
smallest_size = tb->num_owners;
smallest_port = port;
}
if (!inet_csk(sk)->icsk_af_ops->bind_conflict(sk, tb, false))
goto tb_found;
goto next_port;
}
goto tb_not_found;
next_port:
spin_unlock_bh(&head->lock);
cond_resched();
}
if (smallest_size != -1) {
port = smallest_port;
goto have_port;
}
offset--;
if (!(offset & 1))
goto other_parity_scan;
if (attempt_half == 1) {
attempt_half = 2;
goto other_half_scan;
}
return ret;
tb_not_found:
tb = inet_bind_bucket_create(hinfo->bind_bucket_cachep,
net, head, port);
if (!tb)
goto fail_unlock;
tb_found:
if (!hlist_empty(&tb->owners)) {
if (sk->sk_reuse == SK_FORCE_REUSE)
goto success;
if (((tb->fastreuse > 0 && reuse) ||
(tb->fastreuseport > 0 &&
!rcu_access_pointer(sk->sk_reuseport_cb) &&
sk->sk_reuseport && uid_eq(tb->fastuid, uid))) &&
smallest_size == -1)
goto success;
if (inet_csk(sk)->icsk_af_ops->bind_conflict(sk, tb, true)) {
if ((reuse ||
(tb->fastreuseport > 0 &&
sk->sk_reuseport &&
!rcu_access_pointer(sk->sk_reuseport_cb) &&
uid_eq(tb->fastuid, uid))) &&
smallest_size != -1 && --attempts >= 0) {
spin_unlock_bh(&head->lock);
goto again;
}
goto fail_unlock;
}
if (!reuse)
tb->fastreuse = 0;
if (!sk->sk_reuseport || !uid_eq(tb->fastuid, uid))
tb->fastreuseport = 0;
} else {
tb->fastreuse = reuse;
if (sk->sk_reuseport) {
tb->fastreuseport = 1;
tb->fastuid = uid;
} else {
tb->fastreuseport = 0;
}
}
success:
if (!inet_csk(sk)->icsk_bind_hash)
inet_bind_hash(sk, tb, port);
WARN_ON(inet_csk(sk)->icsk_bind_hash != tb);
ret = 0;
fail_unlock:
spin_unlock_bh(&head->lock);
return ret;
}
static int inet_csk_wait_for_connect(struct sock *sk, long timeo)
{
struct inet_connection_sock *icsk = inet_csk(sk);
DEFINE_WAIT(wait);
int err;
for (;;) {
prepare_to_wait_exclusive(sk_sleep(sk), &wait,
TASK_INTERRUPTIBLE);
release_sock(sk);
if (reqsk_queue_empty(&icsk->icsk_accept_queue))
timeo = schedule_timeout(timeo);
sched_annotate_sleep();
lock_sock(sk);
err = 0;
if (!reqsk_queue_empty(&icsk->icsk_accept_queue))
break;
err = -EINVAL;
if (sk->sk_state != TCP_LISTEN)
break;
err = sock_intr_errno(timeo);
if (signal_pending(current))
break;
err = -EAGAIN;
if (!timeo)
break;
}
finish_wait(sk_sleep(sk), &wait);
return err;
}
struct sock *inet_csk_accept(struct sock *sk, int flags, int *err)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct request_sock_queue *queue = &icsk->icsk_accept_queue;
struct request_sock *req;
struct sock *newsk;
int error;
lock_sock(sk);
error = -EINVAL;
if (sk->sk_state != TCP_LISTEN)
goto out_err;
if (reqsk_queue_empty(queue)) {
long timeo = sock_rcvtimeo(sk, flags & O_NONBLOCK);
error = -EAGAIN;
if (!timeo)
goto out_err;
error = inet_csk_wait_for_connect(sk, timeo);
if (error)
goto out_err;
}
req = reqsk_queue_remove(queue, sk);
newsk = req->sk;
if (sk->sk_protocol == IPPROTO_TCP &&
tcp_rsk(req)->tfo_listener) {
spin_lock_bh(&queue->fastopenq.lock);
if (tcp_rsk(req)->tfo_listener) {
req->sk = NULL;
req = NULL;
}
spin_unlock_bh(&queue->fastopenq.lock);
}
out:
release_sock(sk);
if (req)
reqsk_put(req);
return newsk;
out_err:
newsk = NULL;
req = NULL;
*err = error;
goto out;
}
void inet_csk_init_xmit_timers(struct sock *sk,
void (*retransmit_handler)(unsigned long),
void (*delack_handler)(unsigned long),
void (*keepalive_handler)(unsigned long))
{
struct inet_connection_sock *icsk = inet_csk(sk);
setup_timer(&icsk->icsk_retransmit_timer, retransmit_handler,
(unsigned long)sk);
setup_timer(&icsk->icsk_delack_timer, delack_handler,
(unsigned long)sk);
setup_timer(&sk->sk_timer, keepalive_handler, (unsigned long)sk);
icsk->icsk_pending = icsk->icsk_ack.pending = 0;
}
void inet_csk_clear_xmit_timers(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
icsk->icsk_pending = icsk->icsk_ack.pending = icsk->icsk_ack.blocked = 0;
sk_stop_timer(sk, &icsk->icsk_retransmit_timer);
sk_stop_timer(sk, &icsk->icsk_delack_timer);
sk_stop_timer(sk, &sk->sk_timer);
}
void inet_csk_delete_keepalive_timer(struct sock *sk)
{
sk_stop_timer(sk, &sk->sk_timer);
}
void inet_csk_reset_keepalive_timer(struct sock *sk, unsigned long len)
{
sk_reset_timer(sk, &sk->sk_timer, jiffies + len);
}
struct dst_entry *inet_csk_route_req(const struct sock *sk,
struct flowi4 *fl4,
const struct request_sock *req)
{
const struct inet_request_sock *ireq = inet_rsk(req);
struct net *net = read_pnet(&ireq->ireq_net);
struct ip_options_rcu *opt = ireq->opt;
struct rtable *rt;
flowi4_init_output(fl4, ireq->ir_iif, ireq->ir_mark,
RT_CONN_FLAGS(sk), RT_SCOPE_UNIVERSE,
sk->sk_protocol, inet_sk_flowi_flags(sk),
(opt && opt->opt.srr) ? opt->opt.faddr : ireq->ir_rmt_addr,
ireq->ir_loc_addr, ireq->ir_rmt_port,
htons(ireq->ir_num));
security_req_classify_flow(req, flowi4_to_flowi(fl4));
rt = ip_route_output_flow(net, fl4, sk);
if (IS_ERR(rt))
goto no_route;
if (opt && opt->opt.is_strictroute && rt->rt_uses_gateway)
goto route_err;
return &rt->dst;
route_err:
ip_rt_put(rt);
no_route:
__IP_INC_STATS(net, IPSTATS_MIB_OUTNOROUTES);
return NULL;
}
struct dst_entry *inet_csk_route_child_sock(const struct sock *sk,
struct sock *newsk,
const struct request_sock *req)
{
const struct inet_request_sock *ireq = inet_rsk(req);
struct net *net = read_pnet(&ireq->ireq_net);
struct inet_sock *newinet = inet_sk(newsk);
struct ip_options_rcu *opt;
struct flowi4 *fl4;
struct rtable *rt;
fl4 = &newinet->cork.fl.u.ip4;
rcu_read_lock();
opt = rcu_dereference(newinet->inet_opt);
flowi4_init_output(fl4, ireq->ir_iif, ireq->ir_mark,
RT_CONN_FLAGS(sk), RT_SCOPE_UNIVERSE,
sk->sk_protocol, inet_sk_flowi_flags(sk),
(opt && opt->opt.srr) ? opt->opt.faddr : ireq->ir_rmt_addr,
ireq->ir_loc_addr, ireq->ir_rmt_port,
htons(ireq->ir_num));
security_req_classify_flow(req, flowi4_to_flowi(fl4));
rt = ip_route_output_flow(net, fl4, sk);
if (IS_ERR(rt))
goto no_route;
if (opt && opt->opt.is_strictroute && rt->rt_uses_gateway)
goto route_err;
rcu_read_unlock();
return &rt->dst;
route_err:
ip_rt_put(rt);
no_route:
rcu_read_unlock();
__IP_INC_STATS(net, IPSTATS_MIB_OUTNOROUTES);
return NULL;
}
static inline void syn_ack_recalc(struct request_sock *req, const int thresh,
const int max_retries,
const u8 rskq_defer_accept,
int *expire, int *resend)
{
if (!rskq_defer_accept) {
*expire = req->num_timeout >= thresh;
*resend = 1;
return;
}
*expire = req->num_timeout >= thresh &&
(!inet_rsk(req)->acked || req->num_timeout >= max_retries);
*resend = !inet_rsk(req)->acked ||
req->num_timeout >= rskq_defer_accept - 1;
}
int inet_rtx_syn_ack(const struct sock *parent, struct request_sock *req)
{
int err = req->rsk_ops->rtx_syn_ack(parent, req);
if (!err)
req->num_retrans++;
return err;
}
static bool reqsk_queue_unlink(struct request_sock_queue *queue,
struct request_sock *req)
{
struct inet_hashinfo *hashinfo = req_to_sk(req)->sk_prot->h.hashinfo;
bool found = false;
if (sk_hashed(req_to_sk(req))) {
spinlock_t *lock = inet_ehash_lockp(hashinfo, req->rsk_hash);
spin_lock(lock);
found = __sk_nulls_del_node_init_rcu(req_to_sk(req));
spin_unlock(lock);
}
if (timer_pending(&req->rsk_timer) && del_timer_sync(&req->rsk_timer))
reqsk_put(req);
return found;
}
void inet_csk_reqsk_queue_drop(struct sock *sk, struct request_sock *req)
{
if (reqsk_queue_unlink(&inet_csk(sk)->icsk_accept_queue, req)) {
reqsk_queue_removed(&inet_csk(sk)->icsk_accept_queue, req);
reqsk_put(req);
}
}
void inet_csk_reqsk_queue_drop_and_put(struct sock *sk, struct request_sock *req)
{
inet_csk_reqsk_queue_drop(sk, req);
reqsk_put(req);
}
static void reqsk_timer_handler(unsigned long data)
{
struct request_sock *req = (struct request_sock *)data;
struct sock *sk_listener = req->rsk_listener;
struct net *net = sock_net(sk_listener);
struct inet_connection_sock *icsk = inet_csk(sk_listener);
struct request_sock_queue *queue = &icsk->icsk_accept_queue;
int qlen, expire = 0, resend = 0;
int max_retries, thresh;
u8 defer_accept;
if (sk_state_load(sk_listener) != TCP_LISTEN)
goto drop;
max_retries = icsk->icsk_syn_retries ? : net->ipv4.sysctl_tcp_synack_retries;
thresh = max_retries;
qlen = reqsk_queue_len(queue);
if ((qlen << 1) > max(8U, sk_listener->sk_max_ack_backlog)) {
int young = reqsk_queue_len_young(queue) << 1;
while (thresh > 2) {
if (qlen < young)
break;
thresh--;
young <<= 1;
}
}
defer_accept = READ_ONCE(queue->rskq_defer_accept);
if (defer_accept)
max_retries = defer_accept;
syn_ack_recalc(req, thresh, max_retries, defer_accept,
&expire, &resend);
req->rsk_ops->syn_ack_timeout(req);
if (!expire &&
(!resend ||
!inet_rtx_syn_ack(sk_listener, req) ||
inet_rsk(req)->acked)) {
unsigned long timeo;
if (req->num_timeout++ == 0)
atomic_dec(&queue->young);
timeo = min(TCP_TIMEOUT_INIT << req->num_timeout, TCP_RTO_MAX);
mod_timer(&req->rsk_timer, jiffies + timeo);
return;
}
drop:
inet_csk_reqsk_queue_drop_and_put(sk_listener, req);
}
static void reqsk_queue_hash_req(struct request_sock *req,
unsigned long timeout)
{
req->num_retrans = 0;
req->num_timeout = 0;
req->sk = NULL;
setup_pinned_timer(&req->rsk_timer, reqsk_timer_handler,
(unsigned long)req);
mod_timer(&req->rsk_timer, jiffies + timeout);
inet_ehash_insert(req_to_sk(req), NULL);
smp_wmb();
atomic_set(&req->rsk_refcnt, 2 + 1);
}
void inet_csk_reqsk_queue_hash_add(struct sock *sk, struct request_sock *req,
unsigned long timeout)
{
reqsk_queue_hash_req(req, timeout);
inet_csk_reqsk_queue_added(sk);
}
struct sock *inet_csk_clone_lock(const struct sock *sk,
const struct request_sock *req,
const gfp_t priority)
{
struct sock *newsk = sk_clone_lock(sk, priority);
if (newsk) {
struct inet_connection_sock *newicsk = inet_csk(newsk);
newsk->sk_state = TCP_SYN_RECV;
newicsk->icsk_bind_hash = NULL;
inet_sk(newsk)->inet_dport = inet_rsk(req)->ir_rmt_port;
inet_sk(newsk)->inet_num = inet_rsk(req)->ir_num;
inet_sk(newsk)->inet_sport = htons(inet_rsk(req)->ir_num);
newsk->sk_write_space = sk_stream_write_space;
sock_reset_flag(newsk, SOCK_RCU_FREE);
newsk->sk_mark = inet_rsk(req)->ir_mark;
atomic64_set(&newsk->sk_cookie,
atomic64_read(&inet_rsk(req)->ir_cookie));
newicsk->icsk_retransmits = 0;
newicsk->icsk_backoff = 0;
newicsk->icsk_probes_out = 0;
memset(&newicsk->icsk_accept_queue, 0, sizeof(newicsk->icsk_accept_queue));
security_inet_csk_clone(newsk, req);
}
return newsk;
}
void inet_csk_destroy_sock(struct sock *sk)
{
WARN_ON(sk->sk_state != TCP_CLOSE);
WARN_ON(!sock_flag(sk, SOCK_DEAD));
WARN_ON(!sk_unhashed(sk));
WARN_ON(inet_sk(sk)->inet_num && !inet_csk(sk)->icsk_bind_hash);
sk->sk_prot->destroy(sk);
sk_stream_kill_queues(sk);
xfrm_sk_free_policy(sk);
sk_refcnt_debug_release(sk);
local_bh_disable();
percpu_counter_dec(sk->sk_prot->orphan_count);
local_bh_enable();
sock_put(sk);
}
void inet_csk_prepare_forced_close(struct sock *sk)
__releases(&sk->sk_lock.slock
int inet_csk_listen_start(struct sock *sk, int backlog)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct inet_sock *inet = inet_sk(sk);
int err = -EADDRINUSE;
reqsk_queue_alloc(&icsk->icsk_accept_queue);
sk->sk_max_ack_backlog = backlog;
sk->sk_ack_backlog = 0;
inet_csk_delack_init(sk);
sk_state_store(sk, TCP_LISTEN);
if (!sk->sk_prot->get_port(sk, inet->inet_num)) {
inet->inet_sport = htons(inet->inet_num);
sk_dst_reset(sk);
err = sk->sk_prot->hash(sk);
if (likely(!err))
return 0;
}
sk->sk_state = TCP_CLOSE;
return err;
}
static void inet_child_forget(struct sock *sk, struct request_sock *req,
struct sock *child)
{
sk->sk_prot->disconnect(child, O_NONBLOCK);
sock_orphan(child);
percpu_counter_inc(sk->sk_prot->orphan_count);
if (sk->sk_protocol == IPPROTO_TCP && tcp_rsk(req)->tfo_listener) {
BUG_ON(tcp_sk(child)->fastopen_rsk != req);
BUG_ON(sk != req->rsk_listener);
tcp_sk(child)->fastopen_rsk = NULL;
}
inet_csk_destroy_sock(child);
reqsk_put(req);
}
struct sock *inet_csk_reqsk_queue_add(struct sock *sk,
struct request_sock *req,
struct sock *child)
{
struct request_sock_queue *queue = &inet_csk(sk)->icsk_accept_queue;
spin_lock(&queue->rskq_lock);
if (unlikely(sk->sk_state != TCP_LISTEN)) {
inet_child_forget(sk, req, child);
child = NULL;
} else {
req->sk = child;
req->dl_next = NULL;
if (queue->rskq_accept_head == NULL)
queue->rskq_accept_head = req;
else
queue->rskq_accept_tail->dl_next = req;
queue->rskq_accept_tail = req;
sk_acceptq_added(sk);
}
spin_unlock(&queue->rskq_lock);
return child;
}
struct sock *inet_csk_complete_hashdance(struct sock *sk, struct sock *child,
struct request_sock *req, bool own_req)
{
if (own_req) {
inet_csk_reqsk_queue_drop(sk, req);
reqsk_queue_removed(&inet_csk(sk)->icsk_accept_queue, req);
if (inet_csk_reqsk_queue_add(sk, req, child))
return child;
}
bh_unlock_sock(child);
sock_put(child);
return NULL;
}
void inet_csk_listen_stop(struct sock *sk)
{
struct inet_connection_sock *icsk = inet_csk(sk);
struct request_sock_queue *queue = &icsk->icsk_accept_queue;
struct request_sock *next, *req;
while ((req = reqsk_queue_remove(queue, sk)) != NULL) {
struct sock *child = req->sk;
local_bh_disable();
bh_lock_sock(child);
WARN_ON(sock_owned_by_user(child));
sock_hold(child);
inet_child_forget(sk, req, child);
bh_unlock_sock(child);
local_bh_enable();
sock_put(child);
cond_resched();
}
if (queue->fastopenq.rskq_rst_head) {
spin_lock_bh(&queue->fastopenq.lock);
req = queue->fastopenq.rskq_rst_head;
queue->fastopenq.rskq_rst_head = NULL;
spin_unlock_bh(&queue->fastopenq.lock);
while (req != NULL) {
next = req->dl_next;
reqsk_put(req);
req = next;
}
}
WARN_ON_ONCE(sk->sk_ack_backlog);
}
void inet_csk_addr2sockaddr(struct sock *sk, struct sockaddr *uaddr)
{
struct sockaddr_in *sin = (struct sockaddr_in *)uaddr;
const struct inet_sock *inet = inet_sk(sk);
sin->sin_family = AF_INET;
sin->sin_addr.s_addr = inet->inet_daddr;
sin->sin_port = inet->inet_dport;
}
int inet_csk_compat_getsockopt(struct sock *sk, int level, int optname,
char __user *optval, int __user *optlen)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_af_ops->compat_getsockopt)
return icsk->icsk_af_ops->compat_getsockopt(sk, level, optname,
optval, optlen);
return icsk->icsk_af_ops->getsockopt(sk, level, optname,
optval, optlen);
}
int inet_csk_compat_setsockopt(struct sock *sk, int level, int optname,
char __user *optval, unsigned int optlen)
{
const struct inet_connection_sock *icsk = inet_csk(sk);
if (icsk->icsk_af_ops->compat_setsockopt)
return icsk->icsk_af_ops->compat_setsockopt(sk, level, optname,
optval, optlen);
return icsk->icsk_af_ops->setsockopt(sk, level, optname,
optval, optlen);
}
static struct dst_entry *inet_csk_rebuild_route(struct sock *sk, struct flowi *fl)
{
const struct inet_sock *inet = inet_sk(sk);
const struct ip_options_rcu *inet_opt;
__be32 daddr = inet->inet_daddr;
struct flowi4 *fl4;
struct rtable *rt;
rcu_read_lock();
inet_opt = rcu_dereference(inet->inet_opt);
if (inet_opt && inet_opt->opt.srr)
daddr = inet_opt->opt.faddr;
fl4 = &fl->u.ip4;
rt = ip_route_output_ports(sock_net(sk), fl4, sk, daddr,
inet->inet_saddr, inet->inet_dport,
inet->inet_sport, sk->sk_protocol,
RT_CONN_FLAGS(sk), sk->sk_bound_dev_if);
if (IS_ERR(rt))
rt = NULL;
if (rt)
sk_setup_caps(sk, &rt->dst);
rcu_read_unlock();
return &rt->dst;
}
struct dst_entry *inet_csk_update_pmtu(struct sock *sk, u32 mtu)
{
struct dst_entry *dst = __sk_dst_check(sk, 0);
struct inet_sock *inet = inet_sk(sk);
if (!dst) {
dst = inet_csk_rebuild_route(sk, &inet->cork.fl);
if (!dst)
goto out;
}
dst->ops->update_pmtu(dst, sk, NULL, mtu);
dst = __sk_dst_check(sk, 0);
if (!dst)
dst = inet_csk_rebuild_route(sk, &inet->cork.fl);
out:
return dst;
}
