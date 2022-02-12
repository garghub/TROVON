void inet_twsk_bind_unhash(struct inet_timewait_sock *tw,
struct inet_hashinfo *hashinfo)
{
struct inet_bind_bucket *tb = tw->tw_tb;
if (!tb)
return;
__hlist_del(&tw->tw_bind_node);
tw->tw_tb = NULL;
inet_bind_bucket_destroy(hashinfo->bind_bucket_cachep, tb);
__sock_put((struct sock *)tw);
}
static void inet_twsk_kill(struct inet_timewait_sock *tw)
{
struct inet_hashinfo *hashinfo = tw->tw_dr->hashinfo;
spinlock_t *lock = inet_ehash_lockp(hashinfo, tw->tw_hash);
struct inet_bind_hashbucket *bhead;
spin_lock(lock);
sk_nulls_del_node_init_rcu((struct sock *)tw);
spin_unlock(lock);
bhead = &hashinfo->bhash[inet_bhashfn(twsk_net(tw), tw->tw_num,
hashinfo->bhash_size)];
spin_lock(&bhead->lock);
inet_twsk_bind_unhash(tw, hashinfo);
spin_unlock(&bhead->lock);
atomic_dec(&tw->tw_dr->tw_count);
inet_twsk_put(tw);
}
void inet_twsk_free(struct inet_timewait_sock *tw)
{
struct module *owner = tw->tw_prot->owner;
twsk_destructor((struct sock *)tw);
#ifdef SOCK_REFCNT_DEBUG
pr_debug("%s timewait_sock %p released\n", tw->tw_prot->name, tw);
#endif
kmem_cache_free(tw->tw_prot->twsk_prot->twsk_slab, tw);
module_put(owner);
}
void inet_twsk_put(struct inet_timewait_sock *tw)
{
if (atomic_dec_and_test(&tw->tw_refcnt))
inet_twsk_free(tw);
}
static void inet_twsk_add_node_rcu(struct inet_timewait_sock *tw,
struct hlist_nulls_head *list)
{
hlist_nulls_add_head_rcu(&tw->tw_node, list);
}
static void inet_twsk_add_bind_node(struct inet_timewait_sock *tw,
struct hlist_head *list)
{
hlist_add_head(&tw->tw_bind_node, list);
}
void __inet_twsk_hashdance(struct inet_timewait_sock *tw, struct sock *sk,
struct inet_hashinfo *hashinfo)
{
const struct inet_sock *inet = inet_sk(sk);
const struct inet_connection_sock *icsk = inet_csk(sk);
struct inet_ehash_bucket *ehead = inet_ehash_bucket(hashinfo, sk->sk_hash);
spinlock_t *lock = inet_ehash_lockp(hashinfo, sk->sk_hash);
struct inet_bind_hashbucket *bhead;
bhead = &hashinfo->bhash[inet_bhashfn(twsk_net(tw), inet->inet_num,
hashinfo->bhash_size)];
spin_lock_bh(&bhead->lock);
tw->tw_tb = icsk->icsk_bind_hash;
WARN_ON(!icsk->icsk_bind_hash);
inet_twsk_add_bind_node(tw, &tw->tw_tb->owners);
spin_unlock(&bhead->lock);
spin_lock(lock);
atomic_set(&tw->tw_refcnt, 4);
inet_twsk_add_node_rcu(tw, &ehead->chain);
if (__sk_nulls_del_node_init_rcu(sk))
sock_prot_inuse_add(sock_net(sk), sk->sk_prot, -1);
spin_unlock_bh(lock);
}
static void tw_timer_handler(unsigned long data)
{
struct inet_timewait_sock *tw = (struct inet_timewait_sock *)data;
if (tw->tw_kill)
__NET_INC_STATS(twsk_net(tw), LINUX_MIB_TIMEWAITKILLED);
else
__NET_INC_STATS(twsk_net(tw), LINUX_MIB_TIMEWAITED);
inet_twsk_kill(tw);
}
struct inet_timewait_sock *inet_twsk_alloc(const struct sock *sk,
struct inet_timewait_death_row *dr,
const int state)
{
struct inet_timewait_sock *tw;
if (atomic_read(&dr->tw_count) >= dr->sysctl_max_tw_buckets)
return NULL;
tw = kmem_cache_alloc(sk->sk_prot_creator->twsk_prot->twsk_slab,
GFP_ATOMIC);
if (tw) {
const struct inet_sock *inet = inet_sk(sk);
kmemcheck_annotate_bitfield(tw, flags);
tw->tw_dr = dr;
tw->tw_daddr = inet->inet_daddr;
tw->tw_rcv_saddr = inet->inet_rcv_saddr;
tw->tw_bound_dev_if = sk->sk_bound_dev_if;
tw->tw_tos = inet->tos;
tw->tw_num = inet->inet_num;
tw->tw_state = TCP_TIME_WAIT;
tw->tw_substate = state;
tw->tw_sport = inet->inet_sport;
tw->tw_dport = inet->inet_dport;
tw->tw_family = sk->sk_family;
tw->tw_reuse = sk->sk_reuse;
tw->tw_hash = sk->sk_hash;
tw->tw_ipv6only = 0;
tw->tw_transparent = inet->transparent;
tw->tw_prot = sk->sk_prot_creator;
atomic64_set(&tw->tw_cookie, atomic64_read(&sk->sk_cookie));
twsk_net_set(tw, sock_net(sk));
setup_pinned_timer(&tw->tw_timer, tw_timer_handler,
(unsigned long)tw);
atomic_set(&tw->tw_refcnt, 0);
__module_get(tw->tw_prot->owner);
}
return tw;
}
void inet_twsk_deschedule_put(struct inet_timewait_sock *tw)
{
if (del_timer_sync(&tw->tw_timer))
inet_twsk_kill(tw);
inet_twsk_put(tw);
}
void __inet_twsk_schedule(struct inet_timewait_sock *tw, int timeo, bool rearm)
{
tw->tw_kill = timeo <= 4*HZ;
if (!rearm) {
BUG_ON(mod_timer(&tw->tw_timer, jiffies + timeo));
atomic_inc(&tw->tw_dr->tw_count);
} else {
mod_timer_pending(&tw->tw_timer, jiffies + timeo);
}
}
void inet_twsk_purge(struct inet_hashinfo *hashinfo,
struct inet_timewait_death_row *twdr, int family)
{
struct inet_timewait_sock *tw;
struct sock *sk;
struct hlist_nulls_node *node;
unsigned int slot;
for (slot = 0; slot <= hashinfo->ehash_mask; slot++) {
struct inet_ehash_bucket *head = &hashinfo->ehash[slot];
restart_rcu:
cond_resched();
rcu_read_lock();
restart:
sk_nulls_for_each_rcu(sk, node, &head->chain) {
if (sk->sk_state != TCP_TIME_WAIT)
continue;
tw = inet_twsk(sk);
if ((tw->tw_family != family) ||
atomic_read(&twsk_net(tw)->count))
continue;
if (unlikely(!atomic_inc_not_zero(&tw->tw_refcnt)))
continue;
if (unlikely((tw->tw_family != family) ||
atomic_read(&twsk_net(tw)->count))) {
inet_twsk_put(tw);
goto restart;
}
rcu_read_unlock();
local_bh_disable();
inet_twsk_deschedule_put(tw);
local_bh_enable();
goto restart_rcu;
}
if (get_nulls_value(node) != slot)
goto restart;
rcu_read_unlock();
}
}
