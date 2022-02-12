void inet_peer_base_init(struct inet_peer_base *bp)
{
bp->root = peer_avl_empty_rcu;
seqlock_init(&bp->lock);
bp->total = 0;
}
static void inetpeer_gc_worker(struct work_struct *work)
{
struct inet_peer *p, *n, *c;
struct list_head list;
spin_lock_bh(&gc_lock);
list_replace_init(&gc_list, &list);
spin_unlock_bh(&gc_lock);
if (list_empty(&list))
return;
list_for_each_entry_safe(p, n, &list, gc_list) {
if (need_resched())
cond_resched();
c = rcu_dereference_protected(p->avl_left, 1);
if (c != peer_avl_empty) {
list_add_tail(&c->gc_list, &list);
p->avl_left = peer_avl_empty_rcu;
}
c = rcu_dereference_protected(p->avl_right, 1);
if (c != peer_avl_empty) {
list_add_tail(&c->gc_list, &list);
p->avl_right = peer_avl_empty_rcu;
}
n = list_entry(p->gc_list.next, struct inet_peer, gc_list);
if (!atomic_read(&p->refcnt)) {
list_del(&p->gc_list);
kmem_cache_free(peer_cachep, p);
}
}
if (list_empty(&list))
return;
spin_lock_bh(&gc_lock);
list_splice(&list, &gc_list);
spin_unlock_bh(&gc_lock);
schedule_delayed_work(&gc_work, gc_delay);
}
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
INIT_DEFERRABLE_WORK(&gc_work, inetpeer_gc_worker);
}
static struct inet_peer *lookup_rcu(const struct inetpeer_addr *daddr,
struct inet_peer_base *base)
{
struct inet_peer *u = rcu_dereference(base->root);
int count = 0;
while (u != peer_avl_empty) {
int cmp = inetpeer_addr_cmp(daddr, &u->daddr);
if (cmp == 0) {
if (!atomic_add_unless(&u->refcnt, 1, -1))
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
call_rcu(&p->rcu, inetpeer_free_rcu);
}
static int inet_peer_gc(struct inet_peer_base *base,
struct inet_peer __rcu **stack[PEER_MAXDEPTH],
struct inet_peer __rcu ***stackptr)
{
struct inet_peer *p, *gchead = NULL;
__u32 delta, ttl;
int cnt = 0;
if (base->total >= inet_peer_threshold)
ttl = 0;
else
ttl = inet_peer_maxttl
- (inet_peer_maxttl - inet_peer_minttl) / HZ *
base->total / inet_peer_threshold * HZ;
stackptr--;
while (stackptr > stack) {
stackptr--;
p = rcu_deref_locked(**stackptr, base);
if (atomic_read(&p->refcnt) == 0) {
smp_rmb();
delta = (__u32)jiffies - p->dtime;
if (delta >= ttl &&
atomic_cmpxchg(&p->refcnt, 0, -1) == 0) {
p->gc_next = gchead;
gchead = p;
}
}
}
while ((p = gchead) != NULL) {
gchead = p->gc_next;
cnt++;
unlink_from_pool(p, base, stack);
}
return cnt;
}
struct inet_peer *inet_getpeer(struct inet_peer_base *base,
const struct inetpeer_addr *daddr,
int create)
{
struct inet_peer __rcu **stack[PEER_MAXDEPTH], ***stackptr;
struct inet_peer *p;
unsigned int sequence;
int invalidated, gccnt = 0;
rcu_read_lock();
sequence = read_seqbegin(&base->lock);
p = lookup_rcu(daddr, base);
invalidated = read_seqretry(&base->lock, sequence);
rcu_read_unlock();
if (p)
return p;
if (!create && !invalidated)
return NULL;
write_seqlock_bh(&base->lock);
relookup:
p = lookup(daddr, stack, base);
if (p != peer_avl_empty) {
atomic_inc(&p->refcnt);
write_sequnlock_bh(&base->lock);
return p;
}
if (!gccnt) {
gccnt = inet_peer_gc(base, stack, stackptr);
if (gccnt && create)
goto relookup;
}
p = create ? kmem_cache_alloc(peer_cachep, GFP_ATOMIC) : NULL;
if (p) {
p->daddr = *daddr;
atomic_set(&p->refcnt, 1);
atomic_set(&p->rid, 0);
p->metrics[RTAX_LOCK-1] = INETPEER_METRICS_NEW;
p->rate_tokens = 0;
p->rate_last = jiffies - 60*HZ;
INIT_LIST_HEAD(&p->gc_list);
link_to_pool(p, base);
base->total++;
}
write_sequnlock_bh(&base->lock);
return p;
}
void inet_putpeer(struct inet_peer *p)
{
p->dtime = (__u32)jiffies;
smp_mb__before_atomic();
atomic_dec(&p->refcnt);
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
static void inetpeer_inval_rcu(struct rcu_head *head)
{
struct inet_peer *p = container_of(head, struct inet_peer, gc_rcu);
spin_lock_bh(&gc_lock);
list_add_tail(&p->gc_list, &gc_list);
spin_unlock_bh(&gc_lock);
schedule_delayed_work(&gc_work, gc_delay);
}
void inetpeer_invalidate_tree(struct inet_peer_base *base)
{
struct inet_peer *root;
write_seqlock_bh(&base->lock);
root = rcu_deref_locked(base->root, base);
if (root != peer_avl_empty) {
base->root = peer_avl_empty_rcu;
base->total = 0;
call_rcu(&root->gc_rcu, inetpeer_inval_rcu);
}
write_sequnlock_bh(&base->lock);
}
