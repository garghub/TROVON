void __init inet_initpeers(void)
{
struct sysinfo si;
si_meminfo(&si);
if (si.totalram <= (32768*1024)/PAGE_SIZE)
inet_peer_threshold >>= 1;
if (si.totalram <= (16384*1024)/PAGE_SIZE)
inet_peer_threshold >>= 1;
if (si.totalram <= (8192*1024)/PAGE_SIZE)
inet_peer_threshold >>= 2;
peer_cachep = kmem_cache_create("inet_peer_cache",
sizeof(struct inet_peer),
0, SLAB_HWCACHE_ALIGN | SLAB_PANIC,
NULL);
peer_periodic_timer.expires = jiffies
+ net_random() % inet_peer_gc_maxtime
+ inet_peer_gc_maxtime;
add_timer(&peer_periodic_timer);
}
static void unlink_from_unused(struct inet_peer *p)
{
spin_lock_bh(&unused_peers.lock);
list_del_init(&p->unused);
spin_unlock_bh(&unused_peers.lock);
}
static int addr_compare(const struct inetpeer_addr *a,
const struct inetpeer_addr *b)
{
int i, n = (a->family == AF_INET ? 1 : 4);
for (i = 0; i < n; i++) {
if (a->addr.a6[i] == b->addr.a6[i])
continue;
if (a->addr.a6[i] < b->addr.a6[i])
return -1;
return 1;
}
return 0;
}
static bool atomic_add_unless_return(atomic_t *ptr, int a, int u, int *newv)
{
int cur, old = atomic_read(ptr);
while (old != u) {
*newv = old + a;
cur = atomic_cmpxchg(ptr, old, *newv);
if (cur == old)
return true;
old = cur;
}
return false;
}
static struct inet_peer *lookup_rcu(const struct inetpeer_addr *daddr,
struct inet_peer_base *base,
int *newrefcnt)
{
struct inet_peer *u = rcu_dereference(base->root);
int count = 0;
while (u != peer_avl_empty) {
int cmp = addr_compare(daddr, &u->daddr);
if (cmp == 0) {
if (!atomic_add_unless_return(&u->refcnt, 1, -1, newrefcnt))
u = NULL;
return u;
}
if (cmp == -1)
u = rcu_dereference(u->avl_left);
else
u = rcu_dereference(u->avl_right);
if (unlikely(++count == PEER_MAXDEPTH))
break;
}
return NULL;
}
static void peer_avl_rebalance(struct inet_peer __rcu **stack[],
struct inet_peer __rcu ***stackend,
struct inet_peer_base *base)
{
struct inet_peer __rcu **nodep;
struct inet_peer *node, *l, *r;
int lh, rh;
while (stackend > stack) {
nodep = *--stackend;
node = rcu_deref_locked(*nodep, base);
l = rcu_deref_locked(node->avl_left, base);
r = rcu_deref_locked(node->avl_right, base);
lh = node_height(l);
rh = node_height(r);
if (lh > rh + 1) {
struct inet_peer *ll, *lr, *lrl, *lrr;
int lrh;
ll = rcu_deref_locked(l->avl_left, base);
lr = rcu_deref_locked(l->avl_right, base);
lrh = node_height(lr);
if (lrh <= node_height(ll)) {
RCU_INIT_POINTER(node->avl_left, lr);
RCU_INIT_POINTER(node->avl_right, r);
node->avl_height = lrh + 1;
RCU_INIT_POINTER(l->avl_left, ll);
RCU_INIT_POINTER(l->avl_right, node);
l->avl_height = node->avl_height + 1;
RCU_INIT_POINTER(*nodep, l);
} else {
lrl = rcu_deref_locked(lr->avl_left, base);
lrr = rcu_deref_locked(lr->avl_right, base);
RCU_INIT_POINTER(node->avl_left, lrr);
RCU_INIT_POINTER(node->avl_right, r);
node->avl_height = rh + 1;
RCU_INIT_POINTER(l->avl_left, ll);
RCU_INIT_POINTER(l->avl_right, lrl);
l->avl_height = rh + 1;
RCU_INIT_POINTER(lr->avl_left, l);
RCU_INIT_POINTER(lr->avl_right, node);
lr->avl_height = rh + 2;
RCU_INIT_POINTER(*nodep, lr);
}
} else if (rh > lh + 1) {
struct inet_peer *rr, *rl, *rlr, *rll;
int rlh;
rr = rcu_deref_locked(r->avl_right, base);
rl = rcu_deref_locked(r->avl_left, base);
rlh = node_height(rl);
if (rlh <= node_height(rr)) {
RCU_INIT_POINTER(node->avl_right, rl);
RCU_INIT_POINTER(node->avl_left, l);
node->avl_height = rlh + 1;
RCU_INIT_POINTER(r->avl_right, rr);
RCU_INIT_POINTER(r->avl_left, node);
r->avl_height = node->avl_height + 1;
RCU_INIT_POINTER(*nodep, r);
} else {
rlr = rcu_deref_locked(rl->avl_right, base);
rll = rcu_deref_locked(rl->avl_left, base);
RCU_INIT_POINTER(node->avl_right, rll);
RCU_INIT_POINTER(node->avl_left, l);
node->avl_height = lh + 1;
RCU_INIT_POINTER(r->avl_right, rr);
RCU_INIT_POINTER(r->avl_left, rlr);
r->avl_height = lh + 1;
RCU_INIT_POINTER(rl->avl_right, r);
RCU_INIT_POINTER(rl->avl_left, node);
rl->avl_height = lh + 2;
RCU_INIT_POINTER(*nodep, rl);
}
} else {
node->avl_height = (lh > rh ? lh : rh) + 1;
}
}
}
static void inetpeer_free_rcu(struct rcu_head *head)
{
kmem_cache_free(peer_cachep, container_of(head, struct inet_peer, rcu));
}
static void unlink_from_pool(struct inet_peer *p, struct inet_peer_base *base,
struct inet_peer __rcu **stack[PEER_MAXDEPTH])
{
int do_free;
do_free = 0;
write_seqlock_bh(&base->lock);
if (atomic_cmpxchg(&p->refcnt, 1, -1) == 1) {
struct inet_peer __rcu ***stackptr, ***delp;
if (lookup(&p->daddr, stack, base) != p)
BUG();
delp = stackptr - 1;
if (p->avl_left == peer_avl_empty_rcu) {
*delp[0] = p->avl_right;
--stackptr;
} else {
struct inet_peer *t;
t = lookup_rightempty(p, base);
BUG_ON(rcu_deref_locked(*stackptr[-1], base) != t);
**--stackptr = t->avl_left;
RCU_INIT_POINTER(*delp[0], t);
t->avl_left = p->avl_left;
t->avl_right = p->avl_right;
t->avl_height = p->avl_height;
BUG_ON(delp[1] != &p->avl_left);
delp[1] = &t->avl_left;
}
peer_avl_rebalance(stack, stackptr, base);
base->total--;
do_free = 1;
}
write_sequnlock_bh(&base->lock);
if (do_free)
call_rcu(&p->rcu, inetpeer_free_rcu);
else
inet_putpeer(p);
}
static struct inet_peer_base *family_to_base(int family)
{
return (family == AF_INET ? &v4_peers : &v6_peers);
}
static struct inet_peer_base *peer_to_base(struct inet_peer *p)
{
return family_to_base(p->daddr.family);
}
static int cleanup_once(unsigned long ttl, struct inet_peer __rcu **stack[PEER_MAXDEPTH])
{
struct inet_peer *p = NULL;
spin_lock_bh(&unused_peers.lock);
if (!list_empty(&unused_peers.list)) {
__u32 delta;
p = list_first_entry(&unused_peers.list, struct inet_peer, unused);
delta = (__u32)jiffies - p->dtime;
if (delta < ttl) {
spin_unlock_bh(&unused_peers.lock);
return -1;
}
list_del_init(&p->unused);
atomic_inc(&p->refcnt);
}
spin_unlock_bh(&unused_peers.lock);
if (p == NULL)
return -1;
unlink_from_pool(p, peer_to_base(p), stack);
return 0;
}
struct inet_peer *inet_getpeer(struct inetpeer_addr *daddr, int create)
{
struct inet_peer __rcu **stack[PEER_MAXDEPTH], ***stackptr;
struct inet_peer_base *base = family_to_base(daddr->family);
struct inet_peer *p;
unsigned int sequence;
int invalidated, newrefcnt = 0;
rcu_read_lock();
sequence = read_seqbegin(&base->lock);
p = lookup_rcu(daddr, base, &newrefcnt);
invalidated = read_seqretry(&base->lock, sequence);
rcu_read_unlock();
if (p) {
found:
if (newrefcnt == 1)
unlink_from_unused(p);
return p;
}
if (!create && !invalidated)
return NULL;
write_seqlock_bh(&base->lock);
p = lookup(daddr, stack, base);
if (p != peer_avl_empty) {
newrefcnt = atomic_inc_return(&p->refcnt);
write_sequnlock_bh(&base->lock);
goto found;
}
p = create ? kmem_cache_alloc(peer_cachep, GFP_ATOMIC) : NULL;
if (p) {
p->daddr = *daddr;
atomic_set(&p->refcnt, 1);
atomic_set(&p->rid, 0);
atomic_set(&p->ip_id_count, secure_ip_id(daddr->addr.a4));
p->tcp_ts_stamp = 0;
p->metrics[RTAX_LOCK-1] = INETPEER_METRICS_NEW;
p->rate_tokens = 0;
p->rate_last = 0;
p->pmtu_expires = 0;
p->pmtu_orig = 0;
memset(&p->redirect_learned, 0, sizeof(p->redirect_learned));
INIT_LIST_HEAD(&p->unused);
link_to_pool(p, base);
base->total++;
}
write_sequnlock_bh(&base->lock);
if (base->total >= inet_peer_threshold)
cleanup_once(0, stack);
return p;
}
static int compute_total(void)
{
return v4_peers.total + v6_peers.total;
}
static void peer_check_expire(unsigned long dummy)
{
unsigned long now = jiffies;
int ttl, total;
struct inet_peer __rcu **stack[PEER_MAXDEPTH];
total = compute_total();
if (total >= inet_peer_threshold)
ttl = inet_peer_minttl;
else
ttl = inet_peer_maxttl
- (inet_peer_maxttl - inet_peer_minttl) / HZ *
total / inet_peer_threshold * HZ;
while (!cleanup_once(ttl, stack)) {
if (jiffies != now)
break;
}
total = compute_total();
if (total >= inet_peer_threshold)
peer_periodic_timer.expires = jiffies + inet_peer_gc_mintime;
else
peer_periodic_timer.expires = jiffies
+ inet_peer_gc_maxtime
- (inet_peer_gc_maxtime - inet_peer_gc_mintime) / HZ *
total / inet_peer_threshold * HZ;
add_timer(&peer_periodic_timer);
}
void inet_putpeer(struct inet_peer *p)
{
local_bh_disable();
if (atomic_dec_and_lock(&p->refcnt, &unused_peers.lock)) {
list_add_tail(&p->unused, &unused_peers.list);
p->dtime = (__u32)jiffies;
spin_unlock(&unused_peers.lock);
}
local_bh_enable();
}
bool inet_peer_xrlim_allow(struct inet_peer *peer, int timeout)
{
unsigned long now, token;
bool rc = false;
if (!peer)
return true;
token = peer->rate_tokens;
now = jiffies;
token += now - peer->rate_last;
peer->rate_last = now;
if (token > XRLIM_BURST_FACTOR * timeout)
token = XRLIM_BURST_FACTOR * timeout;
if (token >= timeout) {
token -= timeout;
rc = true;
}
peer->rate_tokens = token;
return rc;
}
