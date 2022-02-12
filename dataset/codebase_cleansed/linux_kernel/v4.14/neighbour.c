static int neigh_blackhole(struct neighbour *neigh, struct sk_buff *skb)
{
kfree_skb(skb);
return -ENETDOWN;
}
static void neigh_cleanup_and_release(struct neighbour *neigh)
{
if (neigh->parms->neigh_cleanup)
neigh->parms->neigh_cleanup(neigh);
__neigh_notify(neigh, RTM_DELNEIGH, 0, 0);
call_netevent_notifiers(NETEVENT_NEIGH_UPDATE, neigh);
neigh_release(neigh);
}
unsigned long neigh_rand_reach_time(unsigned long base)
{
return base ? (prandom_u32() % base) + (base >> 1) : 0;
}
static bool neigh_del(struct neighbour *n, __u8 state,
struct neighbour __rcu **np, struct neigh_table *tbl)
{
bool retval = false;
write_lock(&n->lock);
if (refcount_read(&n->refcnt) == 1 && !(n->nud_state & state)) {
struct neighbour *neigh;
neigh = rcu_dereference_protected(n->next,
lockdep_is_held(&tbl->lock));
rcu_assign_pointer(*np, neigh);
n->dead = 1;
retval = true;
}
write_unlock(&n->lock);
if (retval)
neigh_cleanup_and_release(n);
return retval;
}
bool neigh_remove_one(struct neighbour *ndel, struct neigh_table *tbl)
{
struct neigh_hash_table *nht;
void *pkey = ndel->primary_key;
u32 hash_val;
struct neighbour *n;
struct neighbour __rcu **np;
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
hash_val = tbl->hash(pkey, ndel->dev, nht->hash_rnd);
hash_val = hash_val >> (32 - nht->hash_shift);
np = &nht->hash_buckets[hash_val];
while ((n = rcu_dereference_protected(*np,
lockdep_is_held(&tbl->lock)))) {
if (n == ndel)
return neigh_del(n, 0, np, tbl);
np = &n->next;
}
return false;
}
static int neigh_forced_gc(struct neigh_table *tbl)
{
int shrunk = 0;
int i;
struct neigh_hash_table *nht;
NEIGH_CACHE_STAT_INC(tbl, forced_gc_runs);
write_lock_bh(&tbl->lock);
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
for (i = 0; i < (1 << nht->hash_shift); i++) {
struct neighbour *n;
struct neighbour __rcu **np;
np = &nht->hash_buckets[i];
while ((n = rcu_dereference_protected(*np,
lockdep_is_held(&tbl->lock))) != NULL) {
if (neigh_del(n, NUD_PERMANENT, np, tbl)) {
shrunk = 1;
continue;
}
np = &n->next;
}
}
tbl->last_flush = jiffies;
write_unlock_bh(&tbl->lock);
return shrunk;
}
static void neigh_add_timer(struct neighbour *n, unsigned long when)
{
neigh_hold(n);
if (unlikely(mod_timer(&n->timer, when))) {
printk("NEIGH: BUG, double timer add, state is %x\n",
n->nud_state);
dump_stack();
}
}
static int neigh_del_timer(struct neighbour *n)
{
if ((n->nud_state & NUD_IN_TIMER) &&
del_timer(&n->timer)) {
neigh_release(n);
return 1;
}
return 0;
}
static void pneigh_queue_purge(struct sk_buff_head *list)
{
struct sk_buff *skb;
while ((skb = skb_dequeue(list)) != NULL) {
dev_put(skb->dev);
kfree_skb(skb);
}
}
static void neigh_flush_dev(struct neigh_table *tbl, struct net_device *dev)
{
int i;
struct neigh_hash_table *nht;
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
for (i = 0; i < (1 << nht->hash_shift); i++) {
struct neighbour *n;
struct neighbour __rcu **np = &nht->hash_buckets[i];
while ((n = rcu_dereference_protected(*np,
lockdep_is_held(&tbl->lock))) != NULL) {
if (dev && n->dev != dev) {
np = &n->next;
continue;
}
rcu_assign_pointer(*np,
rcu_dereference_protected(n->next,
lockdep_is_held(&tbl->lock)));
write_lock(&n->lock);
neigh_del_timer(n);
n->dead = 1;
if (refcount_read(&n->refcnt) != 1) {
__skb_queue_purge(&n->arp_queue);
n->arp_queue_len_bytes = 0;
n->output = neigh_blackhole;
if (n->nud_state & NUD_VALID)
n->nud_state = NUD_NOARP;
else
n->nud_state = NUD_NONE;
neigh_dbg(2, "neigh %p is stray\n", n);
}
write_unlock(&n->lock);
neigh_cleanup_and_release(n);
}
}
}
void neigh_changeaddr(struct neigh_table *tbl, struct net_device *dev)
{
write_lock_bh(&tbl->lock);
neigh_flush_dev(tbl, dev);
write_unlock_bh(&tbl->lock);
}
int neigh_ifdown(struct neigh_table *tbl, struct net_device *dev)
{
write_lock_bh(&tbl->lock);
neigh_flush_dev(tbl, dev);
pneigh_ifdown(tbl, dev);
write_unlock_bh(&tbl->lock);
del_timer_sync(&tbl->proxy_timer);
pneigh_queue_purge(&tbl->proxy_queue);
return 0;
}
static struct neighbour *neigh_alloc(struct neigh_table *tbl, struct net_device *dev)
{
struct neighbour *n = NULL;
unsigned long now = jiffies;
int entries;
entries = atomic_inc_return(&tbl->entries) - 1;
if (entries >= tbl->gc_thresh3 ||
(entries >= tbl->gc_thresh2 &&
time_after(now, tbl->last_flush + 5 * HZ))) {
if (!neigh_forced_gc(tbl) &&
entries >= tbl->gc_thresh3) {
net_info_ratelimited("%s: neighbor table overflow!\n",
tbl->id);
NEIGH_CACHE_STAT_INC(tbl, table_fulls);
goto out_entries;
}
}
n = kzalloc(tbl->entry_size + dev->neigh_priv_len, GFP_ATOMIC);
if (!n)
goto out_entries;
__skb_queue_head_init(&n->arp_queue);
rwlock_init(&n->lock);
seqlock_init(&n->ha_lock);
n->updated = n->used = now;
n->nud_state = NUD_NONE;
n->output = neigh_blackhole;
seqlock_init(&n->hh.hh_lock);
n->parms = neigh_parms_clone(&tbl->parms);
setup_timer(&n->timer, neigh_timer_handler, (unsigned long)n);
NEIGH_CACHE_STAT_INC(tbl, allocs);
n->tbl = tbl;
refcount_set(&n->refcnt, 1);
n->dead = 1;
out:
return n;
out_entries:
atomic_dec(&tbl->entries);
goto out;
}
static void neigh_get_hash_rnd(u32 *x)
{
*x = get_random_u32() | 1;
}
static struct neigh_hash_table *neigh_hash_alloc(unsigned int shift)
{
size_t size = (1 << shift) * sizeof(struct neighbour *);
struct neigh_hash_table *ret;
struct neighbour __rcu **buckets;
int i;
ret = kmalloc(sizeof(*ret), GFP_ATOMIC);
if (!ret)
return NULL;
if (size <= PAGE_SIZE)
buckets = kzalloc(size, GFP_ATOMIC);
else
buckets = (struct neighbour __rcu **)
__get_free_pages(GFP_ATOMIC | __GFP_ZERO,
get_order(size));
if (!buckets) {
kfree(ret);
return NULL;
}
ret->hash_buckets = buckets;
ret->hash_shift = shift;
for (i = 0; i < NEIGH_NUM_HASH_RND; i++)
neigh_get_hash_rnd(&ret->hash_rnd[i]);
return ret;
}
static void neigh_hash_free_rcu(struct rcu_head *head)
{
struct neigh_hash_table *nht = container_of(head,
struct neigh_hash_table,
rcu);
size_t size = (1 << nht->hash_shift) * sizeof(struct neighbour *);
struct neighbour __rcu **buckets = nht->hash_buckets;
if (size <= PAGE_SIZE)
kfree(buckets);
else
free_pages((unsigned long)buckets, get_order(size));
kfree(nht);
}
static struct neigh_hash_table *neigh_hash_grow(struct neigh_table *tbl,
unsigned long new_shift)
{
unsigned int i, hash;
struct neigh_hash_table *new_nht, *old_nht;
NEIGH_CACHE_STAT_INC(tbl, hash_grows);
old_nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
new_nht = neigh_hash_alloc(new_shift);
if (!new_nht)
return old_nht;
for (i = 0; i < (1 << old_nht->hash_shift); i++) {
struct neighbour *n, *next;
for (n = rcu_dereference_protected(old_nht->hash_buckets[i],
lockdep_is_held(&tbl->lock));
n != NULL;
n = next) {
hash = tbl->hash(n->primary_key, n->dev,
new_nht->hash_rnd);
hash >>= (32 - new_nht->hash_shift);
next = rcu_dereference_protected(n->next,
lockdep_is_held(&tbl->lock));
rcu_assign_pointer(n->next,
rcu_dereference_protected(
new_nht->hash_buckets[hash],
lockdep_is_held(&tbl->lock)));
rcu_assign_pointer(new_nht->hash_buckets[hash], n);
}
}
rcu_assign_pointer(tbl->nht, new_nht);
call_rcu(&old_nht->rcu, neigh_hash_free_rcu);
return new_nht;
}
struct neighbour *neigh_lookup(struct neigh_table *tbl, const void *pkey,
struct net_device *dev)
{
struct neighbour *n;
NEIGH_CACHE_STAT_INC(tbl, lookups);
rcu_read_lock_bh();
n = __neigh_lookup_noref(tbl, pkey, dev);
if (n) {
if (!refcount_inc_not_zero(&n->refcnt))
n = NULL;
NEIGH_CACHE_STAT_INC(tbl, hits);
}
rcu_read_unlock_bh();
return n;
}
struct neighbour *neigh_lookup_nodev(struct neigh_table *tbl, struct net *net,
const void *pkey)
{
struct neighbour *n;
int key_len = tbl->key_len;
u32 hash_val;
struct neigh_hash_table *nht;
NEIGH_CACHE_STAT_INC(tbl, lookups);
rcu_read_lock_bh();
nht = rcu_dereference_bh(tbl->nht);
hash_val = tbl->hash(pkey, NULL, nht->hash_rnd) >> (32 - nht->hash_shift);
for (n = rcu_dereference_bh(nht->hash_buckets[hash_val]);
n != NULL;
n = rcu_dereference_bh(n->next)) {
if (!memcmp(n->primary_key, pkey, key_len) &&
net_eq(dev_net(n->dev), net)) {
if (!refcount_inc_not_zero(&n->refcnt))
n = NULL;
NEIGH_CACHE_STAT_INC(tbl, hits);
break;
}
}
rcu_read_unlock_bh();
return n;
}
struct neighbour *__neigh_create(struct neigh_table *tbl, const void *pkey,
struct net_device *dev, bool want_ref)
{
u32 hash_val;
int key_len = tbl->key_len;
int error;
struct neighbour *n1, *rc, *n = neigh_alloc(tbl, dev);
struct neigh_hash_table *nht;
if (!n) {
rc = ERR_PTR(-ENOBUFS);
goto out;
}
memcpy(n->primary_key, pkey, key_len);
n->dev = dev;
dev_hold(dev);
if (tbl->constructor && (error = tbl->constructor(n)) < 0) {
rc = ERR_PTR(error);
goto out_neigh_release;
}
if (dev->netdev_ops->ndo_neigh_construct) {
error = dev->netdev_ops->ndo_neigh_construct(dev, n);
if (error < 0) {
rc = ERR_PTR(error);
goto out_neigh_release;
}
}
if (n->parms->neigh_setup &&
(error = n->parms->neigh_setup(n)) < 0) {
rc = ERR_PTR(error);
goto out_neigh_release;
}
n->confirmed = jiffies - (NEIGH_VAR(n->parms, BASE_REACHABLE_TIME) << 1);
write_lock_bh(&tbl->lock);
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
if (atomic_read(&tbl->entries) > (1 << nht->hash_shift))
nht = neigh_hash_grow(tbl, nht->hash_shift + 1);
hash_val = tbl->hash(pkey, dev, nht->hash_rnd) >> (32 - nht->hash_shift);
if (n->parms->dead) {
rc = ERR_PTR(-EINVAL);
goto out_tbl_unlock;
}
for (n1 = rcu_dereference_protected(nht->hash_buckets[hash_val],
lockdep_is_held(&tbl->lock));
n1 != NULL;
n1 = rcu_dereference_protected(n1->next,
lockdep_is_held(&tbl->lock))) {
if (dev == n1->dev && !memcmp(n1->primary_key, pkey, key_len)) {
if (want_ref)
neigh_hold(n1);
rc = n1;
goto out_tbl_unlock;
}
}
n->dead = 0;
if (want_ref)
neigh_hold(n);
rcu_assign_pointer(n->next,
rcu_dereference_protected(nht->hash_buckets[hash_val],
lockdep_is_held(&tbl->lock)));
rcu_assign_pointer(nht->hash_buckets[hash_val], n);
write_unlock_bh(&tbl->lock);
neigh_dbg(2, "neigh %p is created\n", n);
rc = n;
out:
return rc;
out_tbl_unlock:
write_unlock_bh(&tbl->lock);
out_neigh_release:
neigh_release(n);
goto out;
}
static u32 pneigh_hash(const void *pkey, int key_len)
{
u32 hash_val = *(u32 *)(pkey + key_len - 4);
hash_val ^= (hash_val >> 16);
hash_val ^= hash_val >> 8;
hash_val ^= hash_val >> 4;
hash_val &= PNEIGH_HASHMASK;
return hash_val;
}
static struct pneigh_entry *__pneigh_lookup_1(struct pneigh_entry *n,
struct net *net,
const void *pkey,
int key_len,
struct net_device *dev)
{
while (n) {
if (!memcmp(n->key, pkey, key_len) &&
net_eq(pneigh_net(n), net) &&
(n->dev == dev || !n->dev))
return n;
n = n->next;
}
return NULL;
}
struct pneigh_entry *__pneigh_lookup(struct neigh_table *tbl,
struct net *net, const void *pkey, struct net_device *dev)
{
int key_len = tbl->key_len;
u32 hash_val = pneigh_hash(pkey, key_len);
return __pneigh_lookup_1(tbl->phash_buckets[hash_val],
net, pkey, key_len, dev);
}
struct pneigh_entry * pneigh_lookup(struct neigh_table *tbl,
struct net *net, const void *pkey,
struct net_device *dev, int creat)
{
struct pneigh_entry *n;
int key_len = tbl->key_len;
u32 hash_val = pneigh_hash(pkey, key_len);
read_lock_bh(&tbl->lock);
n = __pneigh_lookup_1(tbl->phash_buckets[hash_val],
net, pkey, key_len, dev);
read_unlock_bh(&tbl->lock);
if (n || !creat)
goto out;
ASSERT_RTNL();
n = kmalloc(sizeof(*n) + key_len, GFP_KERNEL);
if (!n)
goto out;
write_pnet(&n->net, net);
memcpy(n->key, pkey, key_len);
n->dev = dev;
if (dev)
dev_hold(dev);
if (tbl->pconstructor && tbl->pconstructor(n)) {
if (dev)
dev_put(dev);
kfree(n);
n = NULL;
goto out;
}
write_lock_bh(&tbl->lock);
n->next = tbl->phash_buckets[hash_val];
tbl->phash_buckets[hash_val] = n;
write_unlock_bh(&tbl->lock);
out:
return n;
}
int pneigh_delete(struct neigh_table *tbl, struct net *net, const void *pkey,
struct net_device *dev)
{
struct pneigh_entry *n, **np;
int key_len = tbl->key_len;
u32 hash_val = pneigh_hash(pkey, key_len);
write_lock_bh(&tbl->lock);
for (np = &tbl->phash_buckets[hash_val]; (n = *np) != NULL;
np = &n->next) {
if (!memcmp(n->key, pkey, key_len) && n->dev == dev &&
net_eq(pneigh_net(n), net)) {
*np = n->next;
write_unlock_bh(&tbl->lock);
if (tbl->pdestructor)
tbl->pdestructor(n);
if (n->dev)
dev_put(n->dev);
kfree(n);
return 0;
}
}
write_unlock_bh(&tbl->lock);
return -ENOENT;
}
static int pneigh_ifdown(struct neigh_table *tbl, struct net_device *dev)
{
struct pneigh_entry *n, **np;
u32 h;
for (h = 0; h <= PNEIGH_HASHMASK; h++) {
np = &tbl->phash_buckets[h];
while ((n = *np) != NULL) {
if (!dev || n->dev == dev) {
*np = n->next;
if (tbl->pdestructor)
tbl->pdestructor(n);
if (n->dev)
dev_put(n->dev);
kfree(n);
continue;
}
np = &n->next;
}
}
return -ENOENT;
}
static inline void neigh_parms_put(struct neigh_parms *parms)
{
if (refcount_dec_and_test(&parms->refcnt))
neigh_parms_destroy(parms);
}
void neigh_destroy(struct neighbour *neigh)
{
struct net_device *dev = neigh->dev;
NEIGH_CACHE_STAT_INC(neigh->tbl, destroys);
if (!neigh->dead) {
pr_warn("Destroying alive neighbour %p\n", neigh);
dump_stack();
return;
}
if (neigh_del_timer(neigh))
pr_warn("Impossible event\n");
write_lock_bh(&neigh->lock);
__skb_queue_purge(&neigh->arp_queue);
write_unlock_bh(&neigh->lock);
neigh->arp_queue_len_bytes = 0;
if (dev->netdev_ops->ndo_neigh_destroy)
dev->netdev_ops->ndo_neigh_destroy(dev, neigh);
dev_put(dev);
neigh_parms_put(neigh->parms);
neigh_dbg(2, "neigh %p is destroyed\n", neigh);
atomic_dec(&neigh->tbl->entries);
kfree_rcu(neigh, rcu);
}
static void neigh_suspect(struct neighbour *neigh)
{
neigh_dbg(2, "neigh %p is suspected\n", neigh);
neigh->output = neigh->ops->output;
}
static void neigh_connect(struct neighbour *neigh)
{
neigh_dbg(2, "neigh %p is connected\n", neigh);
neigh->output = neigh->ops->connected_output;
}
static void neigh_periodic_work(struct work_struct *work)
{
struct neigh_table *tbl = container_of(work, struct neigh_table, gc_work.work);
struct neighbour *n;
struct neighbour __rcu **np;
unsigned int i;
struct neigh_hash_table *nht;
NEIGH_CACHE_STAT_INC(tbl, periodic_gc_runs);
write_lock_bh(&tbl->lock);
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
if (time_after(jiffies, tbl->last_rand + 300 * HZ)) {
struct neigh_parms *p;
tbl->last_rand = jiffies;
list_for_each_entry(p, &tbl->parms_list, list)
p->reachable_time =
neigh_rand_reach_time(NEIGH_VAR(p, BASE_REACHABLE_TIME));
}
if (atomic_read(&tbl->entries) < tbl->gc_thresh1)
goto out;
for (i = 0 ; i < (1 << nht->hash_shift); i++) {
np = &nht->hash_buckets[i];
while ((n = rcu_dereference_protected(*np,
lockdep_is_held(&tbl->lock))) != NULL) {
unsigned int state;
write_lock(&n->lock);
state = n->nud_state;
if (state & (NUD_PERMANENT | NUD_IN_TIMER)) {
write_unlock(&n->lock);
goto next_elt;
}
if (time_before(n->used, n->confirmed))
n->used = n->confirmed;
if (refcount_read(&n->refcnt) == 1 &&
(state == NUD_FAILED ||
time_after(jiffies, n->used + NEIGH_VAR(n->parms, GC_STALETIME)))) {
*np = n->next;
n->dead = 1;
write_unlock(&n->lock);
neigh_cleanup_and_release(n);
continue;
}
write_unlock(&n->lock);
next_elt:
np = &n->next;
}
write_unlock_bh(&tbl->lock);
cond_resched();
write_lock_bh(&tbl->lock);
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
}
out:
queue_delayed_work(system_power_efficient_wq, &tbl->gc_work,
NEIGH_VAR(&tbl->parms, BASE_REACHABLE_TIME) >> 1);
write_unlock_bh(&tbl->lock);
}
static __inline__ int neigh_max_probes(struct neighbour *n)
{
struct neigh_parms *p = n->parms;
return NEIGH_VAR(p, UCAST_PROBES) + NEIGH_VAR(p, APP_PROBES) +
(n->nud_state & NUD_PROBE ? NEIGH_VAR(p, MCAST_REPROBES) :
NEIGH_VAR(p, MCAST_PROBES));
}
static void neigh_invalidate(struct neighbour *neigh)
__releases(neigh->lock)
__acquires(neigh->lock)
{
struct sk_buff *skb;
NEIGH_CACHE_STAT_INC(neigh->tbl, res_failed);
neigh_dbg(2, "neigh %p is failed\n", neigh);
neigh->updated = jiffies;
while (neigh->nud_state == NUD_FAILED &&
(skb = __skb_dequeue(&neigh->arp_queue)) != NULL) {
write_unlock(&neigh->lock);
neigh->ops->error_report(neigh, skb);
write_lock(&neigh->lock);
}
__skb_queue_purge(&neigh->arp_queue);
neigh->arp_queue_len_bytes = 0;
}
static void neigh_probe(struct neighbour *neigh)
__releases(neigh->lock)
{
struct sk_buff *skb = skb_peek_tail(&neigh->arp_queue);
if (skb)
skb = skb_clone(skb, GFP_ATOMIC);
write_unlock(&neigh->lock);
if (neigh->ops->solicit)
neigh->ops->solicit(neigh, skb);
atomic_inc(&neigh->probes);
kfree_skb(skb);
}
static void neigh_timer_handler(unsigned long arg)
{
unsigned long now, next;
struct neighbour *neigh = (struct neighbour *)arg;
unsigned int state;
int notify = 0;
write_lock(&neigh->lock);
state = neigh->nud_state;
now = jiffies;
next = now + HZ;
if (!(state & NUD_IN_TIMER))
goto out;
if (state & NUD_REACHABLE) {
if (time_before_eq(now,
neigh->confirmed + neigh->parms->reachable_time)) {
neigh_dbg(2, "neigh %p is still alive\n", neigh);
next = neigh->confirmed + neigh->parms->reachable_time;
} else if (time_before_eq(now,
neigh->used +
NEIGH_VAR(neigh->parms, DELAY_PROBE_TIME))) {
neigh_dbg(2, "neigh %p is delayed\n", neigh);
neigh->nud_state = NUD_DELAY;
neigh->updated = jiffies;
neigh_suspect(neigh);
next = now + NEIGH_VAR(neigh->parms, DELAY_PROBE_TIME);
} else {
neigh_dbg(2, "neigh %p is suspected\n", neigh);
neigh->nud_state = NUD_STALE;
neigh->updated = jiffies;
neigh_suspect(neigh);
notify = 1;
}
} else if (state & NUD_DELAY) {
if (time_before_eq(now,
neigh->confirmed +
NEIGH_VAR(neigh->parms, DELAY_PROBE_TIME))) {
neigh_dbg(2, "neigh %p is now reachable\n", neigh);
neigh->nud_state = NUD_REACHABLE;
neigh->updated = jiffies;
neigh_connect(neigh);
notify = 1;
next = neigh->confirmed + neigh->parms->reachable_time;
} else {
neigh_dbg(2, "neigh %p is probed\n", neigh);
neigh->nud_state = NUD_PROBE;
neigh->updated = jiffies;
atomic_set(&neigh->probes, 0);
notify = 1;
next = now + NEIGH_VAR(neigh->parms, RETRANS_TIME);
}
} else {
next = now + NEIGH_VAR(neigh->parms, RETRANS_TIME);
}
if ((neigh->nud_state & (NUD_INCOMPLETE | NUD_PROBE)) &&
atomic_read(&neigh->probes) >= neigh_max_probes(neigh)) {
neigh->nud_state = NUD_FAILED;
notify = 1;
neigh_invalidate(neigh);
goto out;
}
if (neigh->nud_state & NUD_IN_TIMER) {
if (time_before(next, jiffies + HZ/2))
next = jiffies + HZ/2;
if (!mod_timer(&neigh->timer, next))
neigh_hold(neigh);
}
if (neigh->nud_state & (NUD_INCOMPLETE | NUD_PROBE)) {
neigh_probe(neigh);
} else {
out:
write_unlock(&neigh->lock);
}
if (notify)
neigh_update_notify(neigh, 0);
neigh_release(neigh);
}
int __neigh_event_send(struct neighbour *neigh, struct sk_buff *skb)
{
int rc;
bool immediate_probe = false;
write_lock_bh(&neigh->lock);
rc = 0;
if (neigh->nud_state & (NUD_CONNECTED | NUD_DELAY | NUD_PROBE))
goto out_unlock_bh;
if (neigh->dead)
goto out_dead;
if (!(neigh->nud_state & (NUD_STALE | NUD_INCOMPLETE))) {
if (NEIGH_VAR(neigh->parms, MCAST_PROBES) +
NEIGH_VAR(neigh->parms, APP_PROBES)) {
unsigned long next, now = jiffies;
atomic_set(&neigh->probes,
NEIGH_VAR(neigh->parms, UCAST_PROBES));
neigh->nud_state = NUD_INCOMPLETE;
neigh->updated = now;
next = now + max(NEIGH_VAR(neigh->parms, RETRANS_TIME),
HZ/2);
neigh_add_timer(neigh, next);
immediate_probe = true;
} else {
neigh->nud_state = NUD_FAILED;
neigh->updated = jiffies;
write_unlock_bh(&neigh->lock);
kfree_skb(skb);
return 1;
}
} else if (neigh->nud_state & NUD_STALE) {
neigh_dbg(2, "neigh %p is delayed\n", neigh);
neigh->nud_state = NUD_DELAY;
neigh->updated = jiffies;
neigh_add_timer(neigh, jiffies +
NEIGH_VAR(neigh->parms, DELAY_PROBE_TIME));
}
if (neigh->nud_state == NUD_INCOMPLETE) {
if (skb) {
while (neigh->arp_queue_len_bytes + skb->truesize >
NEIGH_VAR(neigh->parms, QUEUE_LEN_BYTES)) {
struct sk_buff *buff;
buff = __skb_dequeue(&neigh->arp_queue);
if (!buff)
break;
neigh->arp_queue_len_bytes -= buff->truesize;
kfree_skb(buff);
NEIGH_CACHE_STAT_INC(neigh->tbl, unres_discards);
}
skb_dst_force(skb);
__skb_queue_tail(&neigh->arp_queue, skb);
neigh->arp_queue_len_bytes += skb->truesize;
}
rc = 1;
}
out_unlock_bh:
if (immediate_probe)
neigh_probe(neigh);
else
write_unlock(&neigh->lock);
local_bh_enable();
return rc;
out_dead:
if (neigh->nud_state & NUD_STALE)
goto out_unlock_bh;
write_unlock_bh(&neigh->lock);
kfree_skb(skb);
return 1;
}
static void neigh_update_hhs(struct neighbour *neigh)
{
struct hh_cache *hh;
void (*update)(struct hh_cache*, const struct net_device*, const unsigned char *)
= NULL;
if (neigh->dev->header_ops)
update = neigh->dev->header_ops->cache_update;
if (update) {
hh = &neigh->hh;
if (hh->hh_len) {
write_seqlock_bh(&hh->hh_lock);
update(hh, neigh->dev, neigh->ha);
write_sequnlock_bh(&hh->hh_lock);
}
}
}
int neigh_update(struct neighbour *neigh, const u8 *lladdr, u8 new,
u32 flags, u32 nlmsg_pid)
{
u8 old;
int err;
int notify = 0;
struct net_device *dev;
int update_isrouter = 0;
write_lock_bh(&neigh->lock);
dev = neigh->dev;
old = neigh->nud_state;
err = -EPERM;
if (!(flags & NEIGH_UPDATE_F_ADMIN) &&
(old & (NUD_NOARP | NUD_PERMANENT)))
goto out;
if (neigh->dead)
goto out;
if (!(new & NUD_VALID)) {
neigh_del_timer(neigh);
if (old & NUD_CONNECTED)
neigh_suspect(neigh);
neigh->nud_state = new;
err = 0;
notify = old & NUD_VALID;
if ((old & (NUD_INCOMPLETE | NUD_PROBE)) &&
(new & NUD_FAILED)) {
neigh_invalidate(neigh);
notify = 1;
}
goto out;
}
if (!dev->addr_len) {
lladdr = neigh->ha;
} else if (lladdr) {
if ((old & NUD_VALID) &&
!memcmp(lladdr, neigh->ha, dev->addr_len))
lladdr = neigh->ha;
} else {
err = -EINVAL;
if (!(old & NUD_VALID))
goto out;
lladdr = neigh->ha;
}
err = 0;
update_isrouter = flags & NEIGH_UPDATE_F_OVERRIDE_ISROUTER;
if (old & NUD_VALID) {
if (lladdr != neigh->ha && !(flags & NEIGH_UPDATE_F_OVERRIDE)) {
update_isrouter = 0;
if ((flags & NEIGH_UPDATE_F_WEAK_OVERRIDE) &&
(old & NUD_CONNECTED)) {
lladdr = neigh->ha;
new = NUD_STALE;
} else
goto out;
} else {
if (lladdr == neigh->ha && new == NUD_STALE &&
!(flags & NEIGH_UPDATE_F_ADMIN))
new = old;
}
}
if (new != old || lladdr != neigh->ha) {
if (new & NUD_CONNECTED)
neigh->confirmed = jiffies;
neigh->updated = jiffies;
}
if (new != old) {
neigh_del_timer(neigh);
if (new & NUD_PROBE)
atomic_set(&neigh->probes, 0);
if (new & NUD_IN_TIMER)
neigh_add_timer(neigh, (jiffies +
((new & NUD_REACHABLE) ?
neigh->parms->reachable_time :
0)));
neigh->nud_state = new;
notify = 1;
}
if (lladdr != neigh->ha) {
write_seqlock(&neigh->ha_lock);
memcpy(&neigh->ha, lladdr, dev->addr_len);
write_sequnlock(&neigh->ha_lock);
neigh_update_hhs(neigh);
if (!(new & NUD_CONNECTED))
neigh->confirmed = jiffies -
(NEIGH_VAR(neigh->parms, BASE_REACHABLE_TIME) << 1);
notify = 1;
}
if (new == old)
goto out;
if (new & NUD_CONNECTED)
neigh_connect(neigh);
else
neigh_suspect(neigh);
if (!(old & NUD_VALID)) {
struct sk_buff *skb;
while (neigh->nud_state & NUD_VALID &&
(skb = __skb_dequeue(&neigh->arp_queue)) != NULL) {
struct dst_entry *dst = skb_dst(skb);
struct neighbour *n2, *n1 = neigh;
write_unlock_bh(&neigh->lock);
rcu_read_lock();
n2 = NULL;
if (dst) {
n2 = dst_neigh_lookup_skb(dst, skb);
if (n2)
n1 = n2;
}
n1->output(n1, skb);
if (n2)
neigh_release(n2);
rcu_read_unlock();
write_lock_bh(&neigh->lock);
}
__skb_queue_purge(&neigh->arp_queue);
neigh->arp_queue_len_bytes = 0;
}
out:
if (update_isrouter) {
neigh->flags = (flags & NEIGH_UPDATE_F_ISROUTER) ?
(neigh->flags | NTF_ROUTER) :
(neigh->flags & ~NTF_ROUTER);
}
write_unlock_bh(&neigh->lock);
if (notify)
neigh_update_notify(neigh, nlmsg_pid);
return err;
}
void __neigh_set_probe_once(struct neighbour *neigh)
{
if (neigh->dead)
return;
neigh->updated = jiffies;
if (!(neigh->nud_state & NUD_FAILED))
return;
neigh->nud_state = NUD_INCOMPLETE;
atomic_set(&neigh->probes, neigh_max_probes(neigh));
neigh_add_timer(neigh,
jiffies + NEIGH_VAR(neigh->parms, RETRANS_TIME));
}
struct neighbour *neigh_event_ns(struct neigh_table *tbl,
u8 *lladdr, void *saddr,
struct net_device *dev)
{
struct neighbour *neigh = __neigh_lookup(tbl, saddr, dev,
lladdr || !dev->addr_len);
if (neigh)
neigh_update(neigh, lladdr, NUD_STALE,
NEIGH_UPDATE_F_OVERRIDE, 0);
return neigh;
}
static void neigh_hh_init(struct neighbour *n)
{
struct net_device *dev = n->dev;
__be16 prot = n->tbl->protocol;
struct hh_cache *hh = &n->hh;
write_lock_bh(&n->lock);
if (!hh->hh_len)
dev->header_ops->cache(n, hh, prot);
write_unlock_bh(&n->lock);
}
int neigh_resolve_output(struct neighbour *neigh, struct sk_buff *skb)
{
int rc = 0;
if (!neigh_event_send(neigh, skb)) {
int err;
struct net_device *dev = neigh->dev;
unsigned int seq;
if (dev->header_ops->cache && !neigh->hh.hh_len)
neigh_hh_init(neigh);
do {
__skb_pull(skb, skb_network_offset(skb));
seq = read_seqbegin(&neigh->ha_lock);
err = dev_hard_header(skb, dev, ntohs(skb->protocol),
neigh->ha, NULL, skb->len);
} while (read_seqretry(&neigh->ha_lock, seq));
if (err >= 0)
rc = dev_queue_xmit(skb);
else
goto out_kfree_skb;
}
out:
return rc;
out_kfree_skb:
rc = -EINVAL;
kfree_skb(skb);
goto out;
}
int neigh_connected_output(struct neighbour *neigh, struct sk_buff *skb)
{
struct net_device *dev = neigh->dev;
unsigned int seq;
int err;
do {
__skb_pull(skb, skb_network_offset(skb));
seq = read_seqbegin(&neigh->ha_lock);
err = dev_hard_header(skb, dev, ntohs(skb->protocol),
neigh->ha, NULL, skb->len);
} while (read_seqretry(&neigh->ha_lock, seq));
if (err >= 0)
err = dev_queue_xmit(skb);
else {
err = -EINVAL;
kfree_skb(skb);
}
return err;
}
int neigh_direct_output(struct neighbour *neigh, struct sk_buff *skb)
{
return dev_queue_xmit(skb);
}
static void neigh_proxy_process(unsigned long arg)
{
struct neigh_table *tbl = (struct neigh_table *)arg;
long sched_next = 0;
unsigned long now = jiffies;
struct sk_buff *skb, *n;
spin_lock(&tbl->proxy_queue.lock);
skb_queue_walk_safe(&tbl->proxy_queue, skb, n) {
long tdif = NEIGH_CB(skb)->sched_next - now;
if (tdif <= 0) {
struct net_device *dev = skb->dev;
__skb_unlink(skb, &tbl->proxy_queue);
if (tbl->proxy_redo && netif_running(dev)) {
rcu_read_lock();
tbl->proxy_redo(skb);
rcu_read_unlock();
} else {
kfree_skb(skb);
}
dev_put(dev);
} else if (!sched_next || tdif < sched_next)
sched_next = tdif;
}
del_timer(&tbl->proxy_timer);
if (sched_next)
mod_timer(&tbl->proxy_timer, jiffies + sched_next);
spin_unlock(&tbl->proxy_queue.lock);
}
void pneigh_enqueue(struct neigh_table *tbl, struct neigh_parms *p,
struct sk_buff *skb)
{
unsigned long now = jiffies;
unsigned long sched_next = now + (prandom_u32() %
NEIGH_VAR(p, PROXY_DELAY));
if (tbl->proxy_queue.qlen > NEIGH_VAR(p, PROXY_QLEN)) {
kfree_skb(skb);
return;
}
NEIGH_CB(skb)->sched_next = sched_next;
NEIGH_CB(skb)->flags |= LOCALLY_ENQUEUED;
spin_lock(&tbl->proxy_queue.lock);
if (del_timer(&tbl->proxy_timer)) {
if (time_before(tbl->proxy_timer.expires, sched_next))
sched_next = tbl->proxy_timer.expires;
}
skb_dst_drop(skb);
dev_hold(skb->dev);
__skb_queue_tail(&tbl->proxy_queue, skb);
mod_timer(&tbl->proxy_timer, sched_next);
spin_unlock(&tbl->proxy_queue.lock);
}
static inline struct neigh_parms *lookup_neigh_parms(struct neigh_table *tbl,
struct net *net, int ifindex)
{
struct neigh_parms *p;
list_for_each_entry(p, &tbl->parms_list, list) {
if ((p->dev && p->dev->ifindex == ifindex && net_eq(neigh_parms_net(p), net)) ||
(!p->dev && !ifindex && net_eq(net, &init_net)))
return p;
}
return NULL;
}
struct neigh_parms *neigh_parms_alloc(struct net_device *dev,
struct neigh_table *tbl)
{
struct neigh_parms *p;
struct net *net = dev_net(dev);
const struct net_device_ops *ops = dev->netdev_ops;
p = kmemdup(&tbl->parms, sizeof(*p), GFP_KERNEL);
if (p) {
p->tbl = tbl;
refcount_set(&p->refcnt, 1);
p->reachable_time =
neigh_rand_reach_time(NEIGH_VAR(p, BASE_REACHABLE_TIME));
dev_hold(dev);
p->dev = dev;
write_pnet(&p->net, net);
p->sysctl_table = NULL;
if (ops->ndo_neigh_setup && ops->ndo_neigh_setup(dev, p)) {
dev_put(dev);
kfree(p);
return NULL;
}
write_lock_bh(&tbl->lock);
list_add(&p->list, &tbl->parms.list);
write_unlock_bh(&tbl->lock);
neigh_parms_data_state_cleanall(p);
}
return p;
}
static void neigh_rcu_free_parms(struct rcu_head *head)
{
struct neigh_parms *parms =
container_of(head, struct neigh_parms, rcu_head);
neigh_parms_put(parms);
}
void neigh_parms_release(struct neigh_table *tbl, struct neigh_parms *parms)
{
if (!parms || parms == &tbl->parms)
return;
write_lock_bh(&tbl->lock);
list_del(&parms->list);
parms->dead = 1;
write_unlock_bh(&tbl->lock);
if (parms->dev)
dev_put(parms->dev);
call_rcu(&parms->rcu_head, neigh_rcu_free_parms);
}
static void neigh_parms_destroy(struct neigh_parms *parms)
{
kfree(parms);
}
void neigh_table_init(int index, struct neigh_table *tbl)
{
unsigned long now = jiffies;
unsigned long phsize;
INIT_LIST_HEAD(&tbl->parms_list);
list_add(&tbl->parms.list, &tbl->parms_list);
write_pnet(&tbl->parms.net, &init_net);
refcount_set(&tbl->parms.refcnt, 1);
tbl->parms.reachable_time =
neigh_rand_reach_time(NEIGH_VAR(&tbl->parms, BASE_REACHABLE_TIME));
tbl->stats = alloc_percpu(struct neigh_statistics);
if (!tbl->stats)
panic("cannot create neighbour cache statistics");
#ifdef CONFIG_PROC_FS
if (!proc_create_data(tbl->id, 0, init_net.proc_net_stat,
&neigh_stat_seq_fops, tbl))
panic("cannot create neighbour proc dir entry");
#endif
RCU_INIT_POINTER(tbl->nht, neigh_hash_alloc(3));
phsize = (PNEIGH_HASHMASK + 1) * sizeof(struct pneigh_entry *);
tbl->phash_buckets = kzalloc(phsize, GFP_KERNEL);
if (!tbl->nht || !tbl->phash_buckets)
panic("cannot allocate neighbour cache hashes");
if (!tbl->entry_size)
tbl->entry_size = ALIGN(offsetof(struct neighbour, primary_key) +
tbl->key_len, NEIGH_PRIV_ALIGN);
else
WARN_ON(tbl->entry_size % NEIGH_PRIV_ALIGN);
rwlock_init(&tbl->lock);
INIT_DEFERRABLE_WORK(&tbl->gc_work, neigh_periodic_work);
queue_delayed_work(system_power_efficient_wq, &tbl->gc_work,
tbl->parms.reachable_time);
setup_timer(&tbl->proxy_timer, neigh_proxy_process, (unsigned long)tbl);
skb_queue_head_init_class(&tbl->proxy_queue,
&neigh_table_proxy_queue_class);
tbl->last_flush = now;
tbl->last_rand = now + tbl->parms.reachable_time * 20;
neigh_tables[index] = tbl;
}
int neigh_table_clear(int index, struct neigh_table *tbl)
{
neigh_tables[index] = NULL;
cancel_delayed_work_sync(&tbl->gc_work);
del_timer_sync(&tbl->proxy_timer);
pneigh_queue_purge(&tbl->proxy_queue);
neigh_ifdown(tbl, NULL);
if (atomic_read(&tbl->entries))
pr_crit("neighbour leakage\n");
call_rcu(&rcu_dereference_protected(tbl->nht, 1)->rcu,
neigh_hash_free_rcu);
tbl->nht = NULL;
kfree(tbl->phash_buckets);
tbl->phash_buckets = NULL;
remove_proc_entry(tbl->id, init_net.proc_net_stat);
free_percpu(tbl->stats);
tbl->stats = NULL;
return 0;
}
static struct neigh_table *neigh_find_table(int family)
{
struct neigh_table *tbl = NULL;
switch (family) {
case AF_INET:
tbl = neigh_tables[NEIGH_ARP_TABLE];
break;
case AF_INET6:
tbl = neigh_tables[NEIGH_ND_TABLE];
break;
case AF_DECnet:
tbl = neigh_tables[NEIGH_DN_TABLE];
break;
}
return tbl;
}
static int neigh_delete(struct sk_buff *skb, struct nlmsghdr *nlh,
struct netlink_ext_ack *extack)
{
struct net *net = sock_net(skb->sk);
struct ndmsg *ndm;
struct nlattr *dst_attr;
struct neigh_table *tbl;
struct neighbour *neigh;
struct net_device *dev = NULL;
int err = -EINVAL;
ASSERT_RTNL();
if (nlmsg_len(nlh) < sizeof(*ndm))
goto out;
dst_attr = nlmsg_find_attr(nlh, sizeof(*ndm), NDA_DST);
if (dst_attr == NULL)
goto out;
ndm = nlmsg_data(nlh);
if (ndm->ndm_ifindex) {
dev = __dev_get_by_index(net, ndm->ndm_ifindex);
if (dev == NULL) {
err = -ENODEV;
goto out;
}
}
tbl = neigh_find_table(ndm->ndm_family);
if (tbl == NULL)
return -EAFNOSUPPORT;
if (nla_len(dst_attr) < tbl->key_len)
goto out;
if (ndm->ndm_flags & NTF_PROXY) {
err = pneigh_delete(tbl, net, nla_data(dst_attr), dev);
goto out;
}
if (dev == NULL)
goto out;
neigh = neigh_lookup(tbl, nla_data(dst_attr), dev);
if (neigh == NULL) {
err = -ENOENT;
goto out;
}
err = neigh_update(neigh, NULL, NUD_FAILED,
NEIGH_UPDATE_F_OVERRIDE |
NEIGH_UPDATE_F_ADMIN,
NETLINK_CB(skb).portid);
write_lock_bh(&tbl->lock);
neigh_release(neigh);
neigh_remove_one(neigh, tbl);
write_unlock_bh(&tbl->lock);
out:
return err;
}
static int neigh_add(struct sk_buff *skb, struct nlmsghdr *nlh,
struct netlink_ext_ack *extack)
{
int flags = NEIGH_UPDATE_F_ADMIN | NEIGH_UPDATE_F_OVERRIDE;
struct net *net = sock_net(skb->sk);
struct ndmsg *ndm;
struct nlattr *tb[NDA_MAX+1];
struct neigh_table *tbl;
struct net_device *dev = NULL;
struct neighbour *neigh;
void *dst, *lladdr;
int err;
ASSERT_RTNL();
err = nlmsg_parse(nlh, sizeof(*ndm), tb, NDA_MAX, NULL, extack);
if (err < 0)
goto out;
err = -EINVAL;
if (tb[NDA_DST] == NULL)
goto out;
ndm = nlmsg_data(nlh);
if (ndm->ndm_ifindex) {
dev = __dev_get_by_index(net, ndm->ndm_ifindex);
if (dev == NULL) {
err = -ENODEV;
goto out;
}
if (tb[NDA_LLADDR] && nla_len(tb[NDA_LLADDR]) < dev->addr_len)
goto out;
}
tbl = neigh_find_table(ndm->ndm_family);
if (tbl == NULL)
return -EAFNOSUPPORT;
if (nla_len(tb[NDA_DST]) < tbl->key_len)
goto out;
dst = nla_data(tb[NDA_DST]);
lladdr = tb[NDA_LLADDR] ? nla_data(tb[NDA_LLADDR]) : NULL;
if (ndm->ndm_flags & NTF_PROXY) {
struct pneigh_entry *pn;
err = -ENOBUFS;
pn = pneigh_lookup(tbl, net, dst, dev, 1);
if (pn) {
pn->flags = ndm->ndm_flags;
err = 0;
}
goto out;
}
if (dev == NULL)
goto out;
neigh = neigh_lookup(tbl, dst, dev);
if (neigh == NULL) {
if (!(nlh->nlmsg_flags & NLM_F_CREATE)) {
err = -ENOENT;
goto out;
}
neigh = __neigh_lookup_errno(tbl, dst, dev);
if (IS_ERR(neigh)) {
err = PTR_ERR(neigh);
goto out;
}
} else {
if (nlh->nlmsg_flags & NLM_F_EXCL) {
err = -EEXIST;
neigh_release(neigh);
goto out;
}
if (!(nlh->nlmsg_flags & NLM_F_REPLACE))
flags &= ~NEIGH_UPDATE_F_OVERRIDE;
}
if (ndm->ndm_flags & NTF_USE) {
neigh_event_send(neigh, NULL);
err = 0;
} else
err = neigh_update(neigh, lladdr, ndm->ndm_state, flags,
NETLINK_CB(skb).portid);
neigh_release(neigh);
out:
return err;
}
static int neightbl_fill_parms(struct sk_buff *skb, struct neigh_parms *parms)
{
struct nlattr *nest;
nest = nla_nest_start(skb, NDTA_PARMS);
if (nest == NULL)
return -ENOBUFS;
if ((parms->dev &&
nla_put_u32(skb, NDTPA_IFINDEX, parms->dev->ifindex)) ||
nla_put_u32(skb, NDTPA_REFCNT, refcount_read(&parms->refcnt)) ||
nla_put_u32(skb, NDTPA_QUEUE_LENBYTES,
NEIGH_VAR(parms, QUEUE_LEN_BYTES)) ||
nla_put_u32(skb, NDTPA_QUEUE_LEN,
NEIGH_VAR(parms, QUEUE_LEN_BYTES) / SKB_TRUESIZE(ETH_FRAME_LEN)) ||
nla_put_u32(skb, NDTPA_PROXY_QLEN, NEIGH_VAR(parms, PROXY_QLEN)) ||
nla_put_u32(skb, NDTPA_APP_PROBES, NEIGH_VAR(parms, APP_PROBES)) ||
nla_put_u32(skb, NDTPA_UCAST_PROBES,
NEIGH_VAR(parms, UCAST_PROBES)) ||
nla_put_u32(skb, NDTPA_MCAST_PROBES,
NEIGH_VAR(parms, MCAST_PROBES)) ||
nla_put_u32(skb, NDTPA_MCAST_REPROBES,
NEIGH_VAR(parms, MCAST_REPROBES)) ||
nla_put_msecs(skb, NDTPA_REACHABLE_TIME, parms->reachable_time,
NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_BASE_REACHABLE_TIME,
NEIGH_VAR(parms, BASE_REACHABLE_TIME), NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_GC_STALETIME,
NEIGH_VAR(parms, GC_STALETIME), NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_DELAY_PROBE_TIME,
NEIGH_VAR(parms, DELAY_PROBE_TIME), NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_RETRANS_TIME,
NEIGH_VAR(parms, RETRANS_TIME), NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_ANYCAST_DELAY,
NEIGH_VAR(parms, ANYCAST_DELAY), NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_PROXY_DELAY,
NEIGH_VAR(parms, PROXY_DELAY), NDTPA_PAD) ||
nla_put_msecs(skb, NDTPA_LOCKTIME,
NEIGH_VAR(parms, LOCKTIME), NDTPA_PAD))
goto nla_put_failure;
return nla_nest_end(skb, nest);
nla_put_failure:
nla_nest_cancel(skb, nest);
return -EMSGSIZE;
}
static int neightbl_fill_info(struct sk_buff *skb, struct neigh_table *tbl,
u32 pid, u32 seq, int type, int flags)
{
struct nlmsghdr *nlh;
struct ndtmsg *ndtmsg;
nlh = nlmsg_put(skb, pid, seq, type, sizeof(*ndtmsg), flags);
if (nlh == NULL)
return -EMSGSIZE;
ndtmsg = nlmsg_data(nlh);
read_lock_bh(&tbl->lock);
ndtmsg->ndtm_family = tbl->family;
ndtmsg->ndtm_pad1 = 0;
ndtmsg->ndtm_pad2 = 0;
if (nla_put_string(skb, NDTA_NAME, tbl->id) ||
nla_put_msecs(skb, NDTA_GC_INTERVAL, tbl->gc_interval, NDTA_PAD) ||
nla_put_u32(skb, NDTA_THRESH1, tbl->gc_thresh1) ||
nla_put_u32(skb, NDTA_THRESH2, tbl->gc_thresh2) ||
nla_put_u32(skb, NDTA_THRESH3, tbl->gc_thresh3))
goto nla_put_failure;
{
unsigned long now = jiffies;
unsigned int flush_delta = now - tbl->last_flush;
unsigned int rand_delta = now - tbl->last_rand;
struct neigh_hash_table *nht;
struct ndt_config ndc = {
.ndtc_key_len = tbl->key_len,
.ndtc_entry_size = tbl->entry_size,
.ndtc_entries = atomic_read(&tbl->entries),
.ndtc_last_flush = jiffies_to_msecs(flush_delta),
.ndtc_last_rand = jiffies_to_msecs(rand_delta),
.ndtc_proxy_qlen = tbl->proxy_queue.qlen,
};
rcu_read_lock_bh();
nht = rcu_dereference_bh(tbl->nht);
ndc.ndtc_hash_rnd = nht->hash_rnd[0];
ndc.ndtc_hash_mask = ((1 << nht->hash_shift) - 1);
rcu_read_unlock_bh();
if (nla_put(skb, NDTA_CONFIG, sizeof(ndc), &ndc))
goto nla_put_failure;
}
{
int cpu;
struct ndt_stats ndst;
memset(&ndst, 0, sizeof(ndst));
for_each_possible_cpu(cpu) {
struct neigh_statistics *st;
st = per_cpu_ptr(tbl->stats, cpu);
ndst.ndts_allocs += st->allocs;
ndst.ndts_destroys += st->destroys;
ndst.ndts_hash_grows += st->hash_grows;
ndst.ndts_res_failed += st->res_failed;
ndst.ndts_lookups += st->lookups;
ndst.ndts_hits += st->hits;
ndst.ndts_rcv_probes_mcast += st->rcv_probes_mcast;
ndst.ndts_rcv_probes_ucast += st->rcv_probes_ucast;
ndst.ndts_periodic_gc_runs += st->periodic_gc_runs;
ndst.ndts_forced_gc_runs += st->forced_gc_runs;
ndst.ndts_table_fulls += st->table_fulls;
}
if (nla_put_64bit(skb, NDTA_STATS, sizeof(ndst), &ndst,
NDTA_PAD))
goto nla_put_failure;
}
BUG_ON(tbl->parms.dev);
if (neightbl_fill_parms(skb, &tbl->parms) < 0)
goto nla_put_failure;
read_unlock_bh(&tbl->lock);
nlmsg_end(skb, nlh);
return 0;
nla_put_failure:
read_unlock_bh(&tbl->lock);
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int neightbl_fill_param_info(struct sk_buff *skb,
struct neigh_table *tbl,
struct neigh_parms *parms,
u32 pid, u32 seq, int type,
unsigned int flags)
{
struct ndtmsg *ndtmsg;
struct nlmsghdr *nlh;
nlh = nlmsg_put(skb, pid, seq, type, sizeof(*ndtmsg), flags);
if (nlh == NULL)
return -EMSGSIZE;
ndtmsg = nlmsg_data(nlh);
read_lock_bh(&tbl->lock);
ndtmsg->ndtm_family = tbl->family;
ndtmsg->ndtm_pad1 = 0;
ndtmsg->ndtm_pad2 = 0;
if (nla_put_string(skb, NDTA_NAME, tbl->id) < 0 ||
neightbl_fill_parms(skb, parms) < 0)
goto errout;
read_unlock_bh(&tbl->lock);
nlmsg_end(skb, nlh);
return 0;
errout:
read_unlock_bh(&tbl->lock);
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int neightbl_set(struct sk_buff *skb, struct nlmsghdr *nlh,
struct netlink_ext_ack *extack)
{
struct net *net = sock_net(skb->sk);
struct neigh_table *tbl;
struct ndtmsg *ndtmsg;
struct nlattr *tb[NDTA_MAX+1];
bool found = false;
int err, tidx;
err = nlmsg_parse(nlh, sizeof(*ndtmsg), tb, NDTA_MAX,
nl_neightbl_policy, extack);
if (err < 0)
goto errout;
if (tb[NDTA_NAME] == NULL) {
err = -EINVAL;
goto errout;
}
ndtmsg = nlmsg_data(nlh);
for (tidx = 0; tidx < NEIGH_NR_TABLES; tidx++) {
tbl = neigh_tables[tidx];
if (!tbl)
continue;
if (ndtmsg->ndtm_family && tbl->family != ndtmsg->ndtm_family)
continue;
if (nla_strcmp(tb[NDTA_NAME], tbl->id) == 0) {
found = true;
break;
}
}
if (!found)
return -ENOENT;
write_lock_bh(&tbl->lock);
if (tb[NDTA_PARMS]) {
struct nlattr *tbp[NDTPA_MAX+1];
struct neigh_parms *p;
int i, ifindex = 0;
err = nla_parse_nested(tbp, NDTPA_MAX, tb[NDTA_PARMS],
nl_ntbl_parm_policy, extack);
if (err < 0)
goto errout_tbl_lock;
if (tbp[NDTPA_IFINDEX])
ifindex = nla_get_u32(tbp[NDTPA_IFINDEX]);
p = lookup_neigh_parms(tbl, net, ifindex);
if (p == NULL) {
err = -ENOENT;
goto errout_tbl_lock;
}
for (i = 1; i <= NDTPA_MAX; i++) {
if (tbp[i] == NULL)
continue;
switch (i) {
case NDTPA_QUEUE_LEN:
NEIGH_VAR_SET(p, QUEUE_LEN_BYTES,
nla_get_u32(tbp[i]) *
SKB_TRUESIZE(ETH_FRAME_LEN));
break;
case NDTPA_QUEUE_LENBYTES:
NEIGH_VAR_SET(p, QUEUE_LEN_BYTES,
nla_get_u32(tbp[i]));
break;
case NDTPA_PROXY_QLEN:
NEIGH_VAR_SET(p, PROXY_QLEN,
nla_get_u32(tbp[i]));
break;
case NDTPA_APP_PROBES:
NEIGH_VAR_SET(p, APP_PROBES,
nla_get_u32(tbp[i]));
break;
case NDTPA_UCAST_PROBES:
NEIGH_VAR_SET(p, UCAST_PROBES,
nla_get_u32(tbp[i]));
break;
case NDTPA_MCAST_PROBES:
NEIGH_VAR_SET(p, MCAST_PROBES,
nla_get_u32(tbp[i]));
break;
case NDTPA_MCAST_REPROBES:
NEIGH_VAR_SET(p, MCAST_REPROBES,
nla_get_u32(tbp[i]));
break;
case NDTPA_BASE_REACHABLE_TIME:
NEIGH_VAR_SET(p, BASE_REACHABLE_TIME,
nla_get_msecs(tbp[i]));
p->reachable_time =
neigh_rand_reach_time(NEIGH_VAR(p, BASE_REACHABLE_TIME));
break;
case NDTPA_GC_STALETIME:
NEIGH_VAR_SET(p, GC_STALETIME,
nla_get_msecs(tbp[i]));
break;
case NDTPA_DELAY_PROBE_TIME:
NEIGH_VAR_SET(p, DELAY_PROBE_TIME,
nla_get_msecs(tbp[i]));
call_netevent_notifiers(NETEVENT_DELAY_PROBE_TIME_UPDATE, p);
break;
case NDTPA_RETRANS_TIME:
NEIGH_VAR_SET(p, RETRANS_TIME,
nla_get_msecs(tbp[i]));
break;
case NDTPA_ANYCAST_DELAY:
NEIGH_VAR_SET(p, ANYCAST_DELAY,
nla_get_msecs(tbp[i]));
break;
case NDTPA_PROXY_DELAY:
NEIGH_VAR_SET(p, PROXY_DELAY,
nla_get_msecs(tbp[i]));
break;
case NDTPA_LOCKTIME:
NEIGH_VAR_SET(p, LOCKTIME,
nla_get_msecs(tbp[i]));
break;
}
}
}
err = -ENOENT;
if ((tb[NDTA_THRESH1] || tb[NDTA_THRESH2] ||
tb[NDTA_THRESH3] || tb[NDTA_GC_INTERVAL]) &&
!net_eq(net, &init_net))
goto errout_tbl_lock;
if (tb[NDTA_THRESH1])
tbl->gc_thresh1 = nla_get_u32(tb[NDTA_THRESH1]);
if (tb[NDTA_THRESH2])
tbl->gc_thresh2 = nla_get_u32(tb[NDTA_THRESH2]);
if (tb[NDTA_THRESH3])
tbl->gc_thresh3 = nla_get_u32(tb[NDTA_THRESH3]);
if (tb[NDTA_GC_INTERVAL])
tbl->gc_interval = nla_get_msecs(tb[NDTA_GC_INTERVAL]);
err = 0;
errout_tbl_lock:
write_unlock_bh(&tbl->lock);
errout:
return err;
}
static int neightbl_dump_info(struct sk_buff *skb, struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
int family, tidx, nidx = 0;
int tbl_skip = cb->args[0];
int neigh_skip = cb->args[1];
struct neigh_table *tbl;
family = ((struct rtgenmsg *) nlmsg_data(cb->nlh))->rtgen_family;
for (tidx = 0; tidx < NEIGH_NR_TABLES; tidx++) {
struct neigh_parms *p;
tbl = neigh_tables[tidx];
if (!tbl)
continue;
if (tidx < tbl_skip || (family && tbl->family != family))
continue;
if (neightbl_fill_info(skb, tbl, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, RTM_NEWNEIGHTBL,
NLM_F_MULTI) < 0)
break;
nidx = 0;
p = list_next_entry(&tbl->parms, list);
list_for_each_entry_from(p, &tbl->parms_list, list) {
if (!net_eq(neigh_parms_net(p), net))
continue;
if (nidx < neigh_skip)
goto next;
if (neightbl_fill_param_info(skb, tbl, p,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RTM_NEWNEIGHTBL,
NLM_F_MULTI) < 0)
goto out;
next:
nidx++;
}
neigh_skip = 0;
}
out:
cb->args[0] = tidx;
cb->args[1] = nidx;
return skb->len;
}
static int neigh_fill_info(struct sk_buff *skb, struct neighbour *neigh,
u32 pid, u32 seq, int type, unsigned int flags)
{
unsigned long now = jiffies;
struct nda_cacheinfo ci;
struct nlmsghdr *nlh;
struct ndmsg *ndm;
nlh = nlmsg_put(skb, pid, seq, type, sizeof(*ndm), flags);
if (nlh == NULL)
return -EMSGSIZE;
ndm = nlmsg_data(nlh);
ndm->ndm_family = neigh->ops->family;
ndm->ndm_pad1 = 0;
ndm->ndm_pad2 = 0;
ndm->ndm_flags = neigh->flags;
ndm->ndm_type = neigh->type;
ndm->ndm_ifindex = neigh->dev->ifindex;
if (nla_put(skb, NDA_DST, neigh->tbl->key_len, neigh->primary_key))
goto nla_put_failure;
read_lock_bh(&neigh->lock);
ndm->ndm_state = neigh->nud_state;
if (neigh->nud_state & NUD_VALID) {
char haddr[MAX_ADDR_LEN];
neigh_ha_snapshot(haddr, neigh, neigh->dev);
if (nla_put(skb, NDA_LLADDR, neigh->dev->addr_len, haddr) < 0) {
read_unlock_bh(&neigh->lock);
goto nla_put_failure;
}
}
ci.ndm_used = jiffies_to_clock_t(now - neigh->used);
ci.ndm_confirmed = jiffies_to_clock_t(now - neigh->confirmed);
ci.ndm_updated = jiffies_to_clock_t(now - neigh->updated);
ci.ndm_refcnt = refcount_read(&neigh->refcnt) - 1;
read_unlock_bh(&neigh->lock);
if (nla_put_u32(skb, NDA_PROBES, atomic_read(&neigh->probes)) ||
nla_put(skb, NDA_CACHEINFO, sizeof(ci), &ci))
goto nla_put_failure;
nlmsg_end(skb, nlh);
return 0;
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int pneigh_fill_info(struct sk_buff *skb, struct pneigh_entry *pn,
u32 pid, u32 seq, int type, unsigned int flags,
struct neigh_table *tbl)
{
struct nlmsghdr *nlh;
struct ndmsg *ndm;
nlh = nlmsg_put(skb, pid, seq, type, sizeof(*ndm), flags);
if (nlh == NULL)
return -EMSGSIZE;
ndm = nlmsg_data(nlh);
ndm->ndm_family = tbl->family;
ndm->ndm_pad1 = 0;
ndm->ndm_pad2 = 0;
ndm->ndm_flags = pn->flags | NTF_PROXY;
ndm->ndm_type = RTN_UNICAST;
ndm->ndm_ifindex = pn->dev ? pn->dev->ifindex : 0;
ndm->ndm_state = NUD_NONE;
if (nla_put(skb, NDA_DST, tbl->key_len, pn->key))
goto nla_put_failure;
nlmsg_end(skb, nlh);
return 0;
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static void neigh_update_notify(struct neighbour *neigh, u32 nlmsg_pid)
{
call_netevent_notifiers(NETEVENT_NEIGH_UPDATE, neigh);
__neigh_notify(neigh, RTM_NEWNEIGH, 0, nlmsg_pid);
}
static bool neigh_master_filtered(struct net_device *dev, int master_idx)
{
struct net_device *master;
if (!master_idx)
return false;
master = netdev_master_upper_dev_get(dev);
if (!master || master->ifindex != master_idx)
return true;
return false;
}
static bool neigh_ifindex_filtered(struct net_device *dev, int filter_idx)
{
if (filter_idx && dev->ifindex != filter_idx)
return true;
return false;
}
static int neigh_dump_table(struct neigh_table *tbl, struct sk_buff *skb,
struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
const struct nlmsghdr *nlh = cb->nlh;
struct nlattr *tb[NDA_MAX + 1];
struct neighbour *n;
int rc, h, s_h = cb->args[1];
int idx, s_idx = idx = cb->args[2];
struct neigh_hash_table *nht;
int filter_master_idx = 0, filter_idx = 0;
unsigned int flags = NLM_F_MULTI;
int err;
err = nlmsg_parse(nlh, sizeof(struct ndmsg), tb, NDA_MAX, NULL, NULL);
if (!err) {
if (tb[NDA_IFINDEX])
filter_idx = nla_get_u32(tb[NDA_IFINDEX]);
if (tb[NDA_MASTER])
filter_master_idx = nla_get_u32(tb[NDA_MASTER]);
if (filter_idx || filter_master_idx)
flags |= NLM_F_DUMP_FILTERED;
}
rcu_read_lock_bh();
nht = rcu_dereference_bh(tbl->nht);
for (h = s_h; h < (1 << nht->hash_shift); h++) {
if (h > s_h)
s_idx = 0;
for (n = rcu_dereference_bh(nht->hash_buckets[h]), idx = 0;
n != NULL;
n = rcu_dereference_bh(n->next)) {
if (idx < s_idx || !net_eq(dev_net(n->dev), net))
goto next;
if (neigh_ifindex_filtered(n->dev, filter_idx) ||
neigh_master_filtered(n->dev, filter_master_idx))
goto next;
if (neigh_fill_info(skb, n, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RTM_NEWNEIGH,
flags) < 0) {
rc = -1;
goto out;
}
next:
idx++;
}
}
rc = skb->len;
out:
rcu_read_unlock_bh();
cb->args[1] = h;
cb->args[2] = idx;
return rc;
}
static int pneigh_dump_table(struct neigh_table *tbl, struct sk_buff *skb,
struct netlink_callback *cb)
{
struct pneigh_entry *n;
struct net *net = sock_net(skb->sk);
int rc, h, s_h = cb->args[3];
int idx, s_idx = idx = cb->args[4];
read_lock_bh(&tbl->lock);
for (h = s_h; h <= PNEIGH_HASHMASK; h++) {
if (h > s_h)
s_idx = 0;
for (n = tbl->phash_buckets[h], idx = 0; n; n = n->next) {
if (idx < s_idx || pneigh_net(n) != net)
goto next;
if (pneigh_fill_info(skb, n, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RTM_NEWNEIGH,
NLM_F_MULTI, tbl) < 0) {
read_unlock_bh(&tbl->lock);
rc = -1;
goto out;
}
next:
idx++;
}
}
read_unlock_bh(&tbl->lock);
rc = skb->len;
out:
cb->args[3] = h;
cb->args[4] = idx;
return rc;
}
static int neigh_dump_info(struct sk_buff *skb, struct netlink_callback *cb)
{
struct neigh_table *tbl;
int t, family, s_t;
int proxy = 0;
int err;
family = ((struct rtgenmsg *) nlmsg_data(cb->nlh))->rtgen_family;
if (nlmsg_len(cb->nlh) >= sizeof(struct ndmsg) &&
((struct ndmsg *) nlmsg_data(cb->nlh))->ndm_flags == NTF_PROXY)
proxy = 1;
s_t = cb->args[0];
for (t = 0; t < NEIGH_NR_TABLES; t++) {
tbl = neigh_tables[t];
if (!tbl)
continue;
if (t < s_t || (family && tbl->family != family))
continue;
if (t > s_t)
memset(&cb->args[1], 0, sizeof(cb->args) -
sizeof(cb->args[0]));
if (proxy)
err = pneigh_dump_table(tbl, skb, cb);
else
err = neigh_dump_table(tbl, skb, cb);
if (err < 0)
break;
}
cb->args[0] = t;
return skb->len;
}
void neigh_for_each(struct neigh_table *tbl, void (*cb)(struct neighbour *, void *), void *cookie)
{
int chain;
struct neigh_hash_table *nht;
rcu_read_lock_bh();
nht = rcu_dereference_bh(tbl->nht);
read_lock(&tbl->lock);
for (chain = 0; chain < (1 << nht->hash_shift); chain++) {
struct neighbour *n;
for (n = rcu_dereference_bh(nht->hash_buckets[chain]);
n != NULL;
n = rcu_dereference_bh(n->next))
cb(n, cookie);
}
read_unlock(&tbl->lock);
rcu_read_unlock_bh();
}
void __neigh_for_each_release(struct neigh_table *tbl,
int (*cb)(struct neighbour *))
{
int chain;
struct neigh_hash_table *nht;
nht = rcu_dereference_protected(tbl->nht,
lockdep_is_held(&tbl->lock));
for (chain = 0; chain < (1 << nht->hash_shift); chain++) {
struct neighbour *n;
struct neighbour __rcu **np;
np = &nht->hash_buckets[chain];
while ((n = rcu_dereference_protected(*np,
lockdep_is_held(&tbl->lock))) != NULL) {
int release;
write_lock(&n->lock);
release = cb(n);
if (release) {
rcu_assign_pointer(*np,
rcu_dereference_protected(n->next,
lockdep_is_held(&tbl->lock)));
n->dead = 1;
} else
np = &n->next;
write_unlock(&n->lock);
if (release)
neigh_cleanup_and_release(n);
}
}
}
int neigh_xmit(int index, struct net_device *dev,
const void *addr, struct sk_buff *skb)
{
int err = -EAFNOSUPPORT;
if (likely(index < NEIGH_NR_TABLES)) {
struct neigh_table *tbl;
struct neighbour *neigh;
tbl = neigh_tables[index];
if (!tbl)
goto out;
rcu_read_lock_bh();
neigh = __neigh_lookup_noref(tbl, addr, dev);
if (!neigh)
neigh = __neigh_create(tbl, addr, dev, false);
err = PTR_ERR(neigh);
if (IS_ERR(neigh)) {
rcu_read_unlock_bh();
goto out_kfree_skb;
}
err = neigh->output(neigh, skb);
rcu_read_unlock_bh();
}
else if (index == NEIGH_LINK_TABLE) {
err = dev_hard_header(skb, dev, ntohs(skb->protocol),
addr, NULL, skb->len);
if (err < 0)
goto out_kfree_skb;
err = dev_queue_xmit(skb);
}
out:
return err;
out_kfree_skb:
kfree_skb(skb);
goto out;
}
static struct neighbour *neigh_get_first(struct seq_file *seq)
{
struct neigh_seq_state *state = seq->private;
struct net *net = seq_file_net(seq);
struct neigh_hash_table *nht = state->nht;
struct neighbour *n = NULL;
int bucket = state->bucket;
state->flags &= ~NEIGH_SEQ_IS_PNEIGH;
for (bucket = 0; bucket < (1 << nht->hash_shift); bucket++) {
n = rcu_dereference_bh(nht->hash_buckets[bucket]);
while (n) {
if (!net_eq(dev_net(n->dev), net))
goto next;
if (state->neigh_sub_iter) {
loff_t fakep = 0;
void *v;
v = state->neigh_sub_iter(state, n, &fakep);
if (!v)
goto next;
}
if (!(state->flags & NEIGH_SEQ_SKIP_NOARP))
break;
if (n->nud_state & ~NUD_NOARP)
break;
next:
n = rcu_dereference_bh(n->next);
}
if (n)
break;
}
state->bucket = bucket;
return n;
}
static struct neighbour *neigh_get_next(struct seq_file *seq,
struct neighbour *n,
loff_t *pos)
{
struct neigh_seq_state *state = seq->private;
struct net *net = seq_file_net(seq);
struct neigh_hash_table *nht = state->nht;
if (state->neigh_sub_iter) {
void *v = state->neigh_sub_iter(state, n, pos);
if (v)
return n;
}
n = rcu_dereference_bh(n->next);
while (1) {
while (n) {
if (!net_eq(dev_net(n->dev), net))
goto next;
if (state->neigh_sub_iter) {
void *v = state->neigh_sub_iter(state, n, pos);
if (v)
return n;
goto next;
}
if (!(state->flags & NEIGH_SEQ_SKIP_NOARP))
break;
if (n->nud_state & ~NUD_NOARP)
break;
next:
n = rcu_dereference_bh(n->next);
}
if (n)
break;
if (++state->bucket >= (1 << nht->hash_shift))
break;
n = rcu_dereference_bh(nht->hash_buckets[state->bucket]);
}
if (n && pos)
--(*pos);
return n;
}
static struct neighbour *neigh_get_idx(struct seq_file *seq, loff_t *pos)
{
struct neighbour *n = neigh_get_first(seq);
if (n) {
--(*pos);
while (*pos) {
n = neigh_get_next(seq, n, pos);
if (!n)
break;
}
}
return *pos ? NULL : n;
}
static struct pneigh_entry *pneigh_get_first(struct seq_file *seq)
{
struct neigh_seq_state *state = seq->private;
struct net *net = seq_file_net(seq);
struct neigh_table *tbl = state->tbl;
struct pneigh_entry *pn = NULL;
int bucket = state->bucket;
state->flags |= NEIGH_SEQ_IS_PNEIGH;
for (bucket = 0; bucket <= PNEIGH_HASHMASK; bucket++) {
pn = tbl->phash_buckets[bucket];
while (pn && !net_eq(pneigh_net(pn), net))
pn = pn->next;
if (pn)
break;
}
state->bucket = bucket;
return pn;
}
static struct pneigh_entry *pneigh_get_next(struct seq_file *seq,
struct pneigh_entry *pn,
loff_t *pos)
{
struct neigh_seq_state *state = seq->private;
struct net *net = seq_file_net(seq);
struct neigh_table *tbl = state->tbl;
do {
pn = pn->next;
} while (pn && !net_eq(pneigh_net(pn), net));
while (!pn) {
if (++state->bucket > PNEIGH_HASHMASK)
break;
pn = tbl->phash_buckets[state->bucket];
while (pn && !net_eq(pneigh_net(pn), net))
pn = pn->next;
if (pn)
break;
}
if (pn && pos)
--(*pos);
return pn;
}
static struct pneigh_entry *pneigh_get_idx(struct seq_file *seq, loff_t *pos)
{
struct pneigh_entry *pn = pneigh_get_first(seq);
if (pn) {
--(*pos);
while (*pos) {
pn = pneigh_get_next(seq, pn, pos);
if (!pn)
break;
}
}
return *pos ? NULL : pn;
}
static void *neigh_get_idx_any(struct seq_file *seq, loff_t *pos)
{
struct neigh_seq_state *state = seq->private;
void *rc;
loff_t idxpos = *pos;
rc = neigh_get_idx(seq, &idxpos);
if (!rc && !(state->flags & NEIGH_SEQ_NEIGH_ONLY))
rc = pneigh_get_idx(seq, &idxpos);
return rc;
}
void *neigh_seq_start(struct seq_file *seq, loff_t *pos, struct neigh_table *tbl, unsigned int neigh_seq_flags)
__acquires(rcu_bh)
{
struct neigh_seq_state *state = seq->private;
state->tbl = tbl;
state->bucket = 0;
state->flags = (neigh_seq_flags & ~NEIGH_SEQ_IS_PNEIGH);
rcu_read_lock_bh();
state->nht = rcu_dereference_bh(tbl->nht);
return *pos ? neigh_get_idx_any(seq, pos) : SEQ_START_TOKEN;
}
void *neigh_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct neigh_seq_state *state;
void *rc;
if (v == SEQ_START_TOKEN) {
rc = neigh_get_first(seq);
goto out;
}
state = seq->private;
if (!(state->flags & NEIGH_SEQ_IS_PNEIGH)) {
rc = neigh_get_next(seq, v, NULL);
if (rc)
goto out;
if (!(state->flags & NEIGH_SEQ_NEIGH_ONLY))
rc = pneigh_get_first(seq);
} else {
BUG_ON(state->flags & NEIGH_SEQ_NEIGH_ONLY);
rc = pneigh_get_next(seq, v, NULL);
}
out:
++(*pos);
return rc;
}
void neigh_seq_stop(struct seq_file *seq, void *v)
__releases(rcu_bh)
{
rcu_read_unlock_bh();
}
static void *neigh_stat_seq_start(struct seq_file *seq, loff_t *pos)
{
struct neigh_table *tbl = seq->private;
int cpu;
if (*pos == 0)
return SEQ_START_TOKEN;
for (cpu = *pos-1; cpu < nr_cpu_ids; ++cpu) {
if (!cpu_possible(cpu))
continue;
*pos = cpu+1;
return per_cpu_ptr(tbl->stats, cpu);
}
return NULL;
}
static void *neigh_stat_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct neigh_table *tbl = seq->private;
int cpu;
for (cpu = *pos; cpu < nr_cpu_ids; ++cpu) {
if (!cpu_possible(cpu))
continue;
*pos = cpu+1;
return per_cpu_ptr(tbl->stats, cpu);
}
return NULL;
}
static void neigh_stat_seq_stop(struct seq_file *seq, void *v)
{
}
static int neigh_stat_seq_show(struct seq_file *seq, void *v)
{
struct neigh_table *tbl = seq->private;
struct neigh_statistics *st = v;
if (v == SEQ_START_TOKEN) {
seq_printf(seq, "entries allocs destroys hash_grows lookups hits res_failed rcv_probes_mcast rcv_probes_ucast periodic_gc_runs forced_gc_runs unresolved_discards table_fulls\n");
return 0;
}
seq_printf(seq, "%08x %08lx %08lx %08lx %08lx %08lx %08lx "
"%08lx %08lx %08lx %08lx %08lx %08lx\n",
atomic_read(&tbl->entries),
st->allocs,
st->destroys,
st->hash_grows,
st->lookups,
st->hits,
st->res_failed,
st->rcv_probes_mcast,
st->rcv_probes_ucast,
st->periodic_gc_runs,
st->forced_gc_runs,
st->unres_discards,
st->table_fulls
);
return 0;
}
static int neigh_stat_seq_open(struct inode *inode, struct file *file)
{
int ret = seq_open(file, &neigh_stat_seq_ops);
if (!ret) {
struct seq_file *sf = file->private_data;
sf->private = PDE_DATA(inode);
}
return ret;
}
static inline size_t neigh_nlmsg_size(void)
{
return NLMSG_ALIGN(sizeof(struct ndmsg))
+ nla_total_size(MAX_ADDR_LEN)
+ nla_total_size(MAX_ADDR_LEN)
+ nla_total_size(sizeof(struct nda_cacheinfo))
+ nla_total_size(4);
}
static void __neigh_notify(struct neighbour *n, int type, int flags,
u32 pid)
{
struct net *net = dev_net(n->dev);
struct sk_buff *skb;
int err = -ENOBUFS;
skb = nlmsg_new(neigh_nlmsg_size(), GFP_ATOMIC);
if (skb == NULL)
goto errout;
err = neigh_fill_info(skb, n, pid, 0, type, flags);
if (err < 0) {
WARN_ON(err == -EMSGSIZE);
kfree_skb(skb);
goto errout;
}
rtnl_notify(skb, net, 0, RTNLGRP_NEIGH, NULL, GFP_ATOMIC);
return;
errout:
if (err < 0)
rtnl_set_sk_err(net, RTNLGRP_NEIGH, err);
}
void neigh_app_ns(struct neighbour *n)
{
__neigh_notify(n, RTM_GETNEIGH, NLM_F_REQUEST, 0);
}
static int proc_unres_qlen(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int size, ret;
struct ctl_table tmp = *ctl;
tmp.extra1 = &zero;
tmp.extra2 = &unres_qlen_max;
tmp.data = &size;
size = *(int *)ctl->data / SKB_TRUESIZE(ETH_FRAME_LEN);
ret = proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
if (write && !ret)
*(int *)ctl->data = size * SKB_TRUESIZE(ETH_FRAME_LEN);
return ret;
}
static struct neigh_parms *neigh_get_dev_parms_rcu(struct net_device *dev,
int family)
{
switch (family) {
case AF_INET:
return __in_dev_arp_parms_get_rcu(dev);
case AF_INET6:
return __in6_dev_nd_parms_get_rcu(dev);
}
return NULL;
}
static void neigh_copy_dflt_parms(struct net *net, struct neigh_parms *p,
int index)
{
struct net_device *dev;
int family = neigh_parms_family(p);
rcu_read_lock();
for_each_netdev_rcu(net, dev) {
struct neigh_parms *dst_p =
neigh_get_dev_parms_rcu(dev, family);
if (dst_p && !test_bit(index, dst_p->data_state))
dst_p->data[index] = p->data[index];
}
rcu_read_unlock();
}
static void neigh_proc_update(struct ctl_table *ctl, int write)
{
struct net_device *dev = ctl->extra1;
struct neigh_parms *p = ctl->extra2;
struct net *net = neigh_parms_net(p);
int index = (int *) ctl->data - p->data;
if (!write)
return;
set_bit(index, p->data_state);
if (index == NEIGH_VAR_DELAY_PROBE_TIME)
call_netevent_notifiers(NETEVENT_DELAY_PROBE_TIME_UPDATE, p);
if (!dev)
neigh_copy_dflt_parms(net, p, index);
}
static int neigh_proc_dointvec_zero_intmax(struct ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
struct ctl_table tmp = *ctl;
int ret;
tmp.extra1 = &zero;
tmp.extra2 = &int_max;
ret = proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
neigh_proc_update(ctl, write);
return ret;
}
int neigh_proc_dointvec(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
neigh_proc_update(ctl, write);
return ret;
}
int neigh_proc_dointvec_jiffies(struct ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret = proc_dointvec_jiffies(ctl, write, buffer, lenp, ppos);
neigh_proc_update(ctl, write);
return ret;
}
static int neigh_proc_dointvec_userhz_jiffies(struct ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret = proc_dointvec_userhz_jiffies(ctl, write, buffer, lenp, ppos);
neigh_proc_update(ctl, write);
return ret;
}
int neigh_proc_dointvec_ms_jiffies(struct ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret = proc_dointvec_ms_jiffies(ctl, write, buffer, lenp, ppos);
neigh_proc_update(ctl, write);
return ret;
}
static int neigh_proc_dointvec_unres_qlen(struct ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret = proc_unres_qlen(ctl, write, buffer, lenp, ppos);
neigh_proc_update(ctl, write);
return ret;
}
static int neigh_proc_base_reachable_time(struct ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
struct neigh_parms *p = ctl->extra2;
int ret;
if (strcmp(ctl->procname, "base_reachable_time") == 0)
ret = neigh_proc_dointvec_jiffies(ctl, write, buffer, lenp, ppos);
else if (strcmp(ctl->procname, "base_reachable_time_ms") == 0)
ret = neigh_proc_dointvec_ms_jiffies(ctl, write, buffer, lenp, ppos);
else
ret = -1;
if (write && ret == 0) {
p->reachable_time =
neigh_rand_reach_time(NEIGH_VAR(p, BASE_REACHABLE_TIME));
}
return ret;
}
int neigh_sysctl_register(struct net_device *dev, struct neigh_parms *p,
proc_handler *handler)
{
int i;
struct neigh_sysctl_table *t;
const char *dev_name_source;
char neigh_path[ sizeof("net//neigh/") + IFNAMSIZ + IFNAMSIZ ];
char *p_name;
t = kmemdup(&neigh_sysctl_template, sizeof(*t), GFP_KERNEL);
if (!t)
goto err;
for (i = 0; i < NEIGH_VAR_GC_INTERVAL; i++) {
t->neigh_vars[i].data += (long) p;
t->neigh_vars[i].extra1 = dev;
t->neigh_vars[i].extra2 = p;
}
if (dev) {
dev_name_source = dev->name;
memset(&t->neigh_vars[NEIGH_VAR_GC_INTERVAL], 0,
sizeof(t->neigh_vars[NEIGH_VAR_GC_INTERVAL]));
} else {
struct neigh_table *tbl = p->tbl;
dev_name_source = "default";
t->neigh_vars[NEIGH_VAR_GC_INTERVAL].data = &tbl->gc_interval;
t->neigh_vars[NEIGH_VAR_GC_THRESH1].data = &tbl->gc_thresh1;
t->neigh_vars[NEIGH_VAR_GC_THRESH2].data = &tbl->gc_thresh2;
t->neigh_vars[NEIGH_VAR_GC_THRESH3].data = &tbl->gc_thresh3;
}
if (handler) {
t->neigh_vars[NEIGH_VAR_RETRANS_TIME].proc_handler = handler;
t->neigh_vars[NEIGH_VAR_BASE_REACHABLE_TIME].proc_handler = handler;
t->neigh_vars[NEIGH_VAR_RETRANS_TIME_MS].proc_handler = handler;
t->neigh_vars[NEIGH_VAR_BASE_REACHABLE_TIME_MS].proc_handler = handler;
} else {
t->neigh_vars[NEIGH_VAR_BASE_REACHABLE_TIME].proc_handler =
neigh_proc_base_reachable_time;
t->neigh_vars[NEIGH_VAR_BASE_REACHABLE_TIME_MS].proc_handler =
neigh_proc_base_reachable_time;
}
if (neigh_parms_net(p)->user_ns != &init_user_ns)
t->neigh_vars[0].procname = NULL;
switch (neigh_parms_family(p)) {
case AF_INET:
p_name = "ipv4";
break;
case AF_INET6:
p_name = "ipv6";
break;
default:
BUG();
}
snprintf(neigh_path, sizeof(neigh_path), "net/%s/neigh/%s",
p_name, dev_name_source);
t->sysctl_header =
register_net_sysctl(neigh_parms_net(p), neigh_path, t->neigh_vars);
if (!t->sysctl_header)
goto free;
p->sysctl_table = t;
return 0;
free:
kfree(t);
err:
return -ENOBUFS;
}
void neigh_sysctl_unregister(struct neigh_parms *p)
{
if (p->sysctl_table) {
struct neigh_sysctl_table *t = p->sysctl_table;
p->sysctl_table = NULL;
unregister_net_sysctl_table(t->sysctl_header);
kfree(t);
}
}
static int __init neigh_init(void)
{
rtnl_register(PF_UNSPEC, RTM_NEWNEIGH, neigh_add, NULL, 0);
rtnl_register(PF_UNSPEC, RTM_DELNEIGH, neigh_delete, NULL, 0);
rtnl_register(PF_UNSPEC, RTM_GETNEIGH, NULL, neigh_dump_info, 0);
rtnl_register(PF_UNSPEC, RTM_GETNEIGHTBL, NULL, neightbl_dump_info,
0);
rtnl_register(PF_UNSPEC, RTM_SETNEIGHTBL, neightbl_set, NULL, 0);
return 0;
}
