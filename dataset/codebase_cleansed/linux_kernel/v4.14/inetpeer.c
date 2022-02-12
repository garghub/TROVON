void inet_peer_base_init(struct inet_peer_base *bp)
{
bp->rb_root = RB_ROOT;
seqlock_init(&bp->lock);
bp->total = 0;
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
}
static struct inet_peer *lookup(const struct inetpeer_addr *daddr,
struct inet_peer_base *base,
unsigned int seq,
struct inet_peer *gc_stack[],
unsigned int *gc_cnt,
struct rb_node **parent_p,
struct rb_node ***pp_p)
{
struct rb_node **pp, *parent, *next;
struct inet_peer *p;
pp = &base->rb_root.rb_node;
parent = NULL;
while (1) {
int cmp;
next = rcu_dereference_raw(*pp);
if (!next)
break;
parent = next;
p = rb_entry(parent, struct inet_peer, rb_node);
cmp = inetpeer_addr_cmp(daddr, &p->daddr);
if (cmp == 0) {
if (!refcount_inc_not_zero(&p->refcnt))
break;
return p;
}
if (gc_stack) {
if (*gc_cnt < PEER_MAX_GC)
gc_stack[(*gc_cnt)++] = p;
} else if (unlikely(read_seqretry(&base->lock, seq))) {
break;
}
if (cmp == -1)
pp = &next->rb_left;
else
pp = &next->rb_right;
}
*parent_p = parent;
*pp_p = pp;
return NULL;
}
static void inetpeer_free_rcu(struct rcu_head *head)
{
kmem_cache_free(peer_cachep, container_of(head, struct inet_peer, rcu));
}
static void inet_peer_gc(struct inet_peer_base *base,
struct inet_peer *gc_stack[],
unsigned int gc_cnt)
{
struct inet_peer *p;
__u32 delta, ttl;
int i;
if (base->total >= inet_peer_threshold)
ttl = 0;
else
ttl = inet_peer_maxttl
- (inet_peer_maxttl - inet_peer_minttl) / HZ *
base->total / inet_peer_threshold * HZ;
for (i = 0; i < gc_cnt; i++) {
p = gc_stack[i];
delta = (__u32)jiffies - p->dtime;
if (delta < ttl || !refcount_dec_if_one(&p->refcnt))
gc_stack[i] = NULL;
}
for (i = 0; i < gc_cnt; i++) {
p = gc_stack[i];
if (p) {
rb_erase(&p->rb_node, &base->rb_root);
base->total--;
call_rcu(&p->rcu, inetpeer_free_rcu);
}
}
}
struct inet_peer *inet_getpeer(struct inet_peer_base *base,
const struct inetpeer_addr *daddr,
int create)
{
struct inet_peer *p, *gc_stack[PEER_MAX_GC];
struct rb_node **pp, *parent;
unsigned int gc_cnt, seq;
int invalidated;
rcu_read_lock();
seq = read_seqbegin(&base->lock);
p = lookup(daddr, base, seq, NULL, &gc_cnt, &parent, &pp);
invalidated = read_seqretry(&base->lock, seq);
rcu_read_unlock();
if (p)
return p;
if (!create && !invalidated)
return NULL;
parent = NULL;
write_seqlock_bh(&base->lock);
gc_cnt = 0;
p = lookup(daddr, base, seq, gc_stack, &gc_cnt, &parent, &pp);
if (!p && create) {
p = kmem_cache_alloc(peer_cachep, GFP_ATOMIC);
if (p) {
p->daddr = *daddr;
refcount_set(&p->refcnt, 2);
atomic_set(&p->rid, 0);
p->metrics[RTAX_LOCK-1] = INETPEER_METRICS_NEW;
p->rate_tokens = 0;
p->rate_last = jiffies - 60*HZ;
rb_link_node(&p->rb_node, parent, pp);
rb_insert_color(&p->rb_node, &base->rb_root);
base->total++;
}
}
if (gc_cnt)
inet_peer_gc(base, gc_stack, gc_cnt);
write_sequnlock_bh(&base->lock);
return p;
}
void inet_putpeer(struct inet_peer *p)
{
p->dtime = (__u32)jiffies;
if (refcount_dec_and_test(&p->refcnt))
call_rcu(&p->rcu, inetpeer_free_rcu);
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
void inetpeer_invalidate_tree(struct inet_peer_base *base)
{
struct inet_peer *p, *n;
rbtree_postorder_for_each_entry_safe(p, n, &base->rb_root, rb_node) {
inet_putpeer(p);
cond_resched();
}
base->rb_root = RB_ROOT;
base->total = 0;
}
