static inline void
cfs_hash_nl_lock(union cfs_hash_lock *lock, int exclusive) {}
static inline void
cfs_hash_nl_unlock(union cfs_hash_lock *lock, int exclusive) {}
static inline void
cfs_hash_spin_lock(union cfs_hash_lock *lock, int exclusive)
__acquires(&lock->spin
static inline void
cfs_hash_spin_unlock(union cfs_hash_lock *lock, int exclusive)
__releases(&lock->spin
static inline void
cfs_hash_rw_lock(union cfs_hash_lock *lock, int exclusive)
__acquires(&lock->rw
static inline void
cfs_hash_rw_unlock(union cfs_hash_lock *lock, int exclusive)
__releases(&lock->rw
static void
cfs_hash_lock_setup(struct cfs_hash *hs)
{
if (cfs_hash_with_no_lock(hs)) {
hs->hs_lops = &cfs_hash_nl_lops;
} else if (cfs_hash_with_no_bktlock(hs)) {
hs->hs_lops = &cfs_hash_nbl_lops;
spin_lock_init(&hs->hs_lock.spin);
} else if (cfs_hash_with_rehash(hs)) {
rwlock_init(&hs->hs_lock.rw);
if (cfs_hash_with_rw_bktlock(hs))
hs->hs_lops = &cfs_hash_bkt_rw_lops;
else if (cfs_hash_with_spin_bktlock(hs))
hs->hs_lops = &cfs_hash_bkt_spin_lops;
else
LBUG();
} else {
if (cfs_hash_with_rw_bktlock(hs))
hs->hs_lops = &cfs_hash_nr_bkt_rw_lops;
else if (cfs_hash_with_spin_bktlock(hs))
hs->hs_lops = &cfs_hash_nr_bkt_spin_lops;
else
LBUG();
}
}
static int
cfs_hash_hh_hhead_size(struct cfs_hash *hs)
{
return sizeof(struct cfs_hash_head);
}
static struct hlist_head *
cfs_hash_hh_hhead(struct cfs_hash *hs, struct cfs_hash_bd *bd)
{
struct cfs_hash_head *head;
head = (struct cfs_hash_head *)&bd->bd_bucket->hsb_head[0];
return &head[bd->bd_offset].hh_head;
}
static int
cfs_hash_hh_hnode_add(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
hlist_add_head(hnode, cfs_hash_hh_hhead(hs, bd));
return -1;
}
static int
cfs_hash_hh_hnode_del(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
hlist_del_init(hnode);
return -1;
}
static int
cfs_hash_hd_hhead_size(struct cfs_hash *hs)
{
return sizeof(struct cfs_hash_head_dep);
}
static struct hlist_head *
cfs_hash_hd_hhead(struct cfs_hash *hs, struct cfs_hash_bd *bd)
{
struct cfs_hash_head_dep *head;
head = (struct cfs_hash_head_dep *)&bd->bd_bucket->hsb_head[0];
return &head[bd->bd_offset].hd_head;
}
static int
cfs_hash_hd_hnode_add(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
struct cfs_hash_head_dep *hh;
hh = container_of(cfs_hash_hd_hhead(hs, bd),
struct cfs_hash_head_dep, hd_head);
hlist_add_head(hnode, &hh->hd_head);
return ++hh->hd_depth;
}
static int
cfs_hash_hd_hnode_del(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
struct cfs_hash_head_dep *hh;
hh = container_of(cfs_hash_hd_hhead(hs, bd),
struct cfs_hash_head_dep, hd_head);
hlist_del_init(hnode);
return --hh->hd_depth;
}
static int
cfs_hash_dh_hhead_size(struct cfs_hash *hs)
{
return sizeof(struct cfs_hash_dhead);
}
static struct hlist_head *
cfs_hash_dh_hhead(struct cfs_hash *hs, struct cfs_hash_bd *bd)
{
struct cfs_hash_dhead *head;
head = (struct cfs_hash_dhead *)&bd->bd_bucket->hsb_head[0];
return &head[bd->bd_offset].dh_head;
}
static int
cfs_hash_dh_hnode_add(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
struct cfs_hash_dhead *dh;
dh = container_of(cfs_hash_dh_hhead(hs, bd),
struct cfs_hash_dhead, dh_head);
if (dh->dh_tail != NULL)
hlist_add_behind(hnode, dh->dh_tail);
else
hlist_add_head(hnode, &dh->dh_head);
dh->dh_tail = hnode;
return -1;
}
static int
cfs_hash_dh_hnode_del(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnd)
{
struct cfs_hash_dhead *dh;
dh = container_of(cfs_hash_dh_hhead(hs, bd),
struct cfs_hash_dhead, dh_head);
if (hnd->next == NULL) {
dh->dh_tail = (hnd->pprev == &dh->dh_head.first) ? NULL :
container_of(hnd->pprev, struct hlist_node, next);
}
hlist_del_init(hnd);
return -1;
}
static int
cfs_hash_dd_hhead_size(struct cfs_hash *hs)
{
return sizeof(struct cfs_hash_dhead_dep);
}
static struct hlist_head *
cfs_hash_dd_hhead(struct cfs_hash *hs, struct cfs_hash_bd *bd)
{
struct cfs_hash_dhead_dep *head;
head = (struct cfs_hash_dhead_dep *)&bd->bd_bucket->hsb_head[0];
return &head[bd->bd_offset].dd_head;
}
static int
cfs_hash_dd_hnode_add(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
struct cfs_hash_dhead_dep *dh;
dh = container_of(cfs_hash_dd_hhead(hs, bd),
struct cfs_hash_dhead_dep, dd_head);
if (dh->dd_tail != NULL)
hlist_add_behind(hnode, dh->dd_tail);
else
hlist_add_head(hnode, &dh->dd_head);
dh->dd_tail = hnode;
return ++dh->dd_depth;
}
static int
cfs_hash_dd_hnode_del(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnd)
{
struct cfs_hash_dhead_dep *dh;
dh = container_of(cfs_hash_dd_hhead(hs, bd),
struct cfs_hash_dhead_dep, dd_head);
if (hnd->next == NULL) {
dh->dd_tail = (hnd->pprev == &dh->dd_head.first) ? NULL :
container_of(hnd->pprev, struct hlist_node, next);
}
hlist_del_init(hnd);
return --dh->dd_depth;
}
static void
cfs_hash_hlist_setup(struct cfs_hash *hs)
{
if (cfs_hash_with_add_tail(hs)) {
hs->hs_hops = cfs_hash_with_depth(hs) ?
&cfs_hash_dd_hops : &cfs_hash_dh_hops;
} else {
hs->hs_hops = cfs_hash_with_depth(hs) ?
&cfs_hash_hd_hops : &cfs_hash_hh_hops;
}
}
static void
cfs_hash_bd_from_key(struct cfs_hash *hs, struct cfs_hash_bucket **bkts,
unsigned int bits, const void *key, struct cfs_hash_bd *bd)
{
unsigned int index = cfs_hash_id(hs, key, (1U << bits) - 1);
LASSERT(bits == hs->hs_cur_bits || bits == hs->hs_rehash_bits);
bd->bd_bucket = bkts[index & ((1U << (bits - hs->hs_bkt_bits)) - 1)];
bd->bd_offset = index >> (bits - hs->hs_bkt_bits);
}
void
cfs_hash_bd_get(struct cfs_hash *hs, const void *key, struct cfs_hash_bd *bd)
{
if (likely(hs->hs_rehash_buckets == NULL)) {
cfs_hash_bd_from_key(hs, hs->hs_buckets,
hs->hs_cur_bits, key, bd);
} else {
LASSERT(hs->hs_rehash_bits != 0);
cfs_hash_bd_from_key(hs, hs->hs_rehash_buckets,
hs->hs_rehash_bits, key, bd);
}
}
static inline void
cfs_hash_bd_dep_record(struct cfs_hash *hs, struct cfs_hash_bd *bd, int dep_cur)
{
if (likely(dep_cur <= bd->bd_bucket->hsb_depmax))
return;
bd->bd_bucket->hsb_depmax = dep_cur;
# if CFS_HASH_DEBUG_LEVEL >= CFS_HASH_DEBUG_1
if (likely(warn_on_depth == 0 ||
max(warn_on_depth, hs->hs_dep_max) >= dep_cur))
return;
spin_lock(&hs->hs_dep_lock);
hs->hs_dep_max = dep_cur;
hs->hs_dep_bkt = bd->bd_bucket->hsb_index;
hs->hs_dep_off = bd->bd_offset;
hs->hs_dep_bits = hs->hs_cur_bits;
spin_unlock(&hs->hs_dep_lock);
cfs_wi_schedule(cfs_sched_rehash, &hs->hs_dep_wi);
# endif
}
void
cfs_hash_bd_add_locked(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
int rc;
rc = hs->hs_hops->hop_hnode_add(hs, bd, hnode);
cfs_hash_bd_dep_record(hs, bd, rc);
bd->bd_bucket->hsb_version++;
if (unlikely(bd->bd_bucket->hsb_version == 0))
bd->bd_bucket->hsb_version++;
bd->bd_bucket->hsb_count++;
if (cfs_hash_with_counter(hs))
atomic_inc(&hs->hs_count);
if (!cfs_hash_with_no_itemref(hs))
cfs_hash_get(hs, hnode);
}
void
cfs_hash_bd_del_locked(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode)
{
hs->hs_hops->hop_hnode_del(hs, bd, hnode);
LASSERT(bd->bd_bucket->hsb_count > 0);
bd->bd_bucket->hsb_count--;
bd->bd_bucket->hsb_version++;
if (unlikely(bd->bd_bucket->hsb_version == 0))
bd->bd_bucket->hsb_version++;
if (cfs_hash_with_counter(hs)) {
LASSERT(atomic_read(&hs->hs_count) > 0);
atomic_dec(&hs->hs_count);
}
if (!cfs_hash_with_no_itemref(hs))
cfs_hash_put_locked(hs, hnode);
}
void
cfs_hash_bd_move_locked(struct cfs_hash *hs, struct cfs_hash_bd *bd_old,
struct cfs_hash_bd *bd_new, struct hlist_node *hnode)
{
struct cfs_hash_bucket *obkt = bd_old->bd_bucket;
struct cfs_hash_bucket *nbkt = bd_new->bd_bucket;
int rc;
if (cfs_hash_bd_compare(bd_old, bd_new) == 0)
return;
hs->hs_hops->hop_hnode_del(hs, bd_old, hnode);
rc = hs->hs_hops->hop_hnode_add(hs, bd_new, hnode);
cfs_hash_bd_dep_record(hs, bd_new, rc);
LASSERT(obkt->hsb_count > 0);
obkt->hsb_count--;
obkt->hsb_version++;
if (unlikely(obkt->hsb_version == 0))
obkt->hsb_version++;
nbkt->hsb_count++;
nbkt->hsb_version++;
if (unlikely(nbkt->hsb_version == 0))
nbkt->hsb_version++;
}
static struct hlist_node *
cfs_hash_bd_lookup_intent(struct cfs_hash *hs, struct cfs_hash_bd *bd,
const void *key, struct hlist_node *hnode,
enum cfs_hash_lookup_intent intent)
{
struct hlist_head *hhead = cfs_hash_bd_hhead(hs, bd);
struct hlist_node *ehnode;
struct hlist_node *match;
int intent_add = (intent & CFS_HS_LOOKUP_MASK_ADD) != 0;
match = intent_add ? NULL : hnode;
hlist_for_each(ehnode, hhead) {
if (!cfs_hash_keycmp(hs, key, ehnode))
continue;
if (match != NULL && match != ehnode)
continue;
if ((intent & CFS_HS_LOOKUP_MASK_DEL) != 0) {
cfs_hash_bd_del_locked(hs, bd, ehnode);
return ehnode;
}
if ((intent & CFS_HS_LOOKUP_MASK_REF) != 0)
cfs_hash_get(hs, ehnode);
return ehnode;
}
if (!intent_add)
return NULL;
LASSERT(hnode != NULL);
cfs_hash_bd_add_locked(hs, bd, hnode);
return hnode;
}
struct hlist_node *
cfs_hash_bd_lookup_locked(struct cfs_hash *hs, struct cfs_hash_bd *bd,
const void *key)
{
return cfs_hash_bd_lookup_intent(hs, bd, key, NULL,
CFS_HS_LOOKUP_IT_FIND);
}
struct hlist_node *
cfs_hash_bd_peek_locked(struct cfs_hash *hs, struct cfs_hash_bd *bd,
const void *key)
{
return cfs_hash_bd_lookup_intent(hs, bd, key, NULL,
CFS_HS_LOOKUP_IT_PEEK);
}
static void
cfs_hash_multi_bd_lock(struct cfs_hash *hs, struct cfs_hash_bd *bds,
unsigned n, int excl)
{
struct cfs_hash_bucket *prev = NULL;
int i;
cfs_hash_for_each_bd(bds, n, i) {
if (prev == bds[i].bd_bucket)
continue;
LASSERT(prev == NULL ||
prev->hsb_index < bds[i].bd_bucket->hsb_index);
cfs_hash_bd_lock(hs, &bds[i], excl);
prev = bds[i].bd_bucket;
}
}
static void
cfs_hash_multi_bd_unlock(struct cfs_hash *hs, struct cfs_hash_bd *bds,
unsigned n, int excl)
{
struct cfs_hash_bucket *prev = NULL;
int i;
cfs_hash_for_each_bd(bds, n, i) {
if (prev != bds[i].bd_bucket) {
cfs_hash_bd_unlock(hs, &bds[i], excl);
prev = bds[i].bd_bucket;
}
}
}
static struct hlist_node *
cfs_hash_multi_bd_lookup_locked(struct cfs_hash *hs, struct cfs_hash_bd *bds,
unsigned n, const void *key)
{
struct hlist_node *ehnode;
unsigned i;
cfs_hash_for_each_bd(bds, n, i) {
ehnode = cfs_hash_bd_lookup_intent(hs, &bds[i], key, NULL,
CFS_HS_LOOKUP_IT_FIND);
if (ehnode != NULL)
return ehnode;
}
return NULL;
}
static struct hlist_node *
cfs_hash_multi_bd_findadd_locked(struct cfs_hash *hs, struct cfs_hash_bd *bds,
unsigned n, const void *key,
struct hlist_node *hnode, int noref)
{
struct hlist_node *ehnode;
int intent;
unsigned i;
LASSERT(hnode != NULL);
intent = (!noref * CFS_HS_LOOKUP_MASK_REF) | CFS_HS_LOOKUP_IT_PEEK;
cfs_hash_for_each_bd(bds, n, i) {
ehnode = cfs_hash_bd_lookup_intent(hs, &bds[i], key,
NULL, intent);
if (ehnode != NULL)
return ehnode;
}
if (i == 1) {
cfs_hash_bd_add_locked(hs, &bds[0], hnode);
} else {
struct cfs_hash_bd mybd;
cfs_hash_bd_get(hs, key, &mybd);
cfs_hash_bd_add_locked(hs, &mybd, hnode);
}
return hnode;
}
static struct hlist_node *
cfs_hash_multi_bd_finddel_locked(struct cfs_hash *hs, struct cfs_hash_bd *bds,
unsigned n, const void *key,
struct hlist_node *hnode)
{
struct hlist_node *ehnode;
unsigned int i;
cfs_hash_for_each_bd(bds, n, i) {
ehnode = cfs_hash_bd_lookup_intent(hs, &bds[i], key, hnode,
CFS_HS_LOOKUP_IT_FINDDEL);
if (ehnode != NULL)
return ehnode;
}
return NULL;
}
static void
cfs_hash_bd_order(struct cfs_hash_bd *bd1, struct cfs_hash_bd *bd2)
{
int rc;
if (bd2->bd_bucket == NULL)
return;
if (bd1->bd_bucket == NULL) {
*bd1 = *bd2;
bd2->bd_bucket = NULL;
return;
}
rc = cfs_hash_bd_compare(bd1, bd2);
if (rc == 0) {
bd2->bd_bucket = NULL;
} else if (rc > 0) {
struct cfs_hash_bd tmp;
tmp = *bd2;
*bd2 = *bd1;
*bd1 = tmp;
}
}
void
cfs_hash_dual_bd_get(struct cfs_hash *hs, const void *key,
struct cfs_hash_bd *bds)
{
cfs_hash_bd_from_key(hs, hs->hs_buckets,
hs->hs_cur_bits, key, &bds[0]);
if (likely(hs->hs_rehash_buckets == NULL)) {
bds[1].bd_bucket = NULL;
return;
}
LASSERT(hs->hs_rehash_bits != 0);
cfs_hash_bd_from_key(hs, hs->hs_rehash_buckets,
hs->hs_rehash_bits, key, &bds[1]);
cfs_hash_bd_order(&bds[0], &bds[1]);
}
void
cfs_hash_dual_bd_lock(struct cfs_hash *hs, struct cfs_hash_bd *bds, int excl)
{
cfs_hash_multi_bd_lock(hs, bds, 2, excl);
}
void
cfs_hash_dual_bd_unlock(struct cfs_hash *hs, struct cfs_hash_bd *bds, int excl)
{
cfs_hash_multi_bd_unlock(hs, bds, 2, excl);
}
struct hlist_node *
cfs_hash_dual_bd_lookup_locked(struct cfs_hash *hs, struct cfs_hash_bd *bds,
const void *key)
{
return cfs_hash_multi_bd_lookup_locked(hs, bds, 2, key);
}
struct hlist_node *
cfs_hash_dual_bd_findadd_locked(struct cfs_hash *hs, struct cfs_hash_bd *bds,
const void *key, struct hlist_node *hnode,
int noref)
{
return cfs_hash_multi_bd_findadd_locked(hs, bds, 2, key,
hnode, noref);
}
struct hlist_node *
cfs_hash_dual_bd_finddel_locked(struct cfs_hash *hs, struct cfs_hash_bd *bds,
const void *key, struct hlist_node *hnode)
{
return cfs_hash_multi_bd_finddel_locked(hs, bds, 2, key, hnode);
}
static void
cfs_hash_buckets_free(struct cfs_hash_bucket **buckets,
int bkt_size, int prev_size, int size)
{
int i;
for (i = prev_size; i < size; i++) {
if (buckets[i] != NULL)
LIBCFS_FREE(buckets[i], bkt_size);
}
LIBCFS_FREE(buckets, sizeof(buckets[0]) * size);
}
static struct cfs_hash_bucket **
cfs_hash_buckets_realloc(struct cfs_hash *hs, struct cfs_hash_bucket **old_bkts,
unsigned int old_size, unsigned int new_size)
{
struct cfs_hash_bucket **new_bkts;
int i;
LASSERT(old_size == 0 || old_bkts != NULL);
if (old_bkts != NULL && old_size == new_size)
return old_bkts;
LIBCFS_ALLOC(new_bkts, sizeof(new_bkts[0]) * new_size);
if (new_bkts == NULL)
return NULL;
if (old_bkts != NULL) {
memcpy(new_bkts, old_bkts,
min(old_size, new_size) * sizeof(*old_bkts));
}
for (i = old_size; i < new_size; i++) {
struct hlist_head *hhead;
struct cfs_hash_bd bd;
LIBCFS_ALLOC(new_bkts[i], cfs_hash_bkt_size(hs));
if (new_bkts[i] == NULL) {
cfs_hash_buckets_free(new_bkts, cfs_hash_bkt_size(hs),
old_size, new_size);
return NULL;
}
new_bkts[i]->hsb_index = i;
new_bkts[i]->hsb_version = 1;
new_bkts[i]->hsb_depmax = -1;
bd.bd_bucket = new_bkts[i];
cfs_hash_bd_for_each_hlist(hs, &bd, hhead)
INIT_HLIST_HEAD(hhead);
if (cfs_hash_with_no_lock(hs) ||
cfs_hash_with_no_bktlock(hs))
continue;
if (cfs_hash_with_rw_bktlock(hs))
rwlock_init(&new_bkts[i]->hsb_lock.rw);
else if (cfs_hash_with_spin_bktlock(hs))
spin_lock_init(&new_bkts[i]->hsb_lock.spin);
else
LBUG();
}
return new_bkts;
}
static int cfs_hash_dep_print(cfs_workitem_t *wi)
{
struct cfs_hash *hs = container_of(wi, struct cfs_hash, hs_dep_wi);
int dep;
int bkt;
int off;
int bits;
spin_lock(&hs->hs_dep_lock);
dep = hs->hs_dep_max;
bkt = hs->hs_dep_bkt;
off = hs->hs_dep_off;
bits = hs->hs_dep_bits;
spin_unlock(&hs->hs_dep_lock);
LCONSOLE_WARN("#### HASH %s (bits: %d): max depth %d at bucket %d/%d\n",
hs->hs_name, bits, dep, bkt, off);
spin_lock(&hs->hs_dep_lock);
hs->hs_dep_bits = 0;
spin_unlock(&hs->hs_dep_lock);
return 0;
}
static void cfs_hash_depth_wi_init(struct cfs_hash *hs)
{
spin_lock_init(&hs->hs_dep_lock);
cfs_wi_init(&hs->hs_dep_wi, hs, cfs_hash_dep_print);
}
static void cfs_hash_depth_wi_cancel(struct cfs_hash *hs)
{
if (cfs_wi_deschedule(cfs_sched_rehash, &hs->hs_dep_wi))
return;
spin_lock(&hs->hs_dep_lock);
while (hs->hs_dep_bits != 0) {
spin_unlock(&hs->hs_dep_lock);
cond_resched();
spin_lock(&hs->hs_dep_lock);
}
spin_unlock(&hs->hs_dep_lock);
}
static inline void cfs_hash_depth_wi_init(struct cfs_hash *hs) {}
static inline void cfs_hash_depth_wi_cancel(struct cfs_hash *hs) {}
struct cfs_hash *
cfs_hash_create(char *name, unsigned cur_bits, unsigned max_bits,
unsigned bkt_bits, unsigned extra_bytes,
unsigned min_theta, unsigned max_theta,
struct cfs_hash_ops *ops, unsigned flags)
{
struct cfs_hash *hs;
int len;
CLASSERT(CFS_HASH_THETA_BITS < 15);
LASSERT(name != NULL);
LASSERT(ops != NULL);
LASSERT(ops->hs_key);
LASSERT(ops->hs_hash);
LASSERT(ops->hs_object);
LASSERT(ops->hs_keycmp);
LASSERT(ops->hs_get != NULL);
LASSERT(ops->hs_put_locked != NULL);
if ((flags & CFS_HASH_REHASH) != 0)
flags |= CFS_HASH_COUNTER;
LASSERT(cur_bits > 0);
LASSERT(cur_bits >= bkt_bits);
LASSERT(max_bits >= cur_bits && max_bits < 31);
LASSERT(ergo((flags & CFS_HASH_REHASH) == 0, cur_bits == max_bits));
LASSERT(ergo((flags & CFS_HASH_REHASH) != 0,
(flags & CFS_HASH_NO_LOCK) == 0));
LASSERT(ergo((flags & CFS_HASH_REHASH_KEY) != 0,
ops->hs_keycpy != NULL));
len = (flags & CFS_HASH_BIGNAME) == 0 ?
CFS_HASH_NAME_LEN : CFS_HASH_BIGNAME_LEN;
LIBCFS_ALLOC(hs, offsetof(struct cfs_hash, hs_name[len]));
if (hs == NULL)
return NULL;
strlcpy(hs->hs_name, name, len);
hs->hs_flags = flags;
atomic_set(&hs->hs_refcount, 1);
atomic_set(&hs->hs_count, 0);
cfs_hash_lock_setup(hs);
cfs_hash_hlist_setup(hs);
hs->hs_cur_bits = (__u8)cur_bits;
hs->hs_min_bits = (__u8)cur_bits;
hs->hs_max_bits = (__u8)max_bits;
hs->hs_bkt_bits = (__u8)bkt_bits;
hs->hs_ops = ops;
hs->hs_extra_bytes = extra_bytes;
hs->hs_rehash_bits = 0;
cfs_wi_init(&hs->hs_rehash_wi, hs, cfs_hash_rehash_worker);
cfs_hash_depth_wi_init(hs);
if (cfs_hash_with_rehash(hs))
__cfs_hash_set_theta(hs, min_theta, max_theta);
hs->hs_buckets = cfs_hash_buckets_realloc(hs, NULL, 0,
CFS_HASH_NBKT(hs));
if (hs->hs_buckets != NULL)
return hs;
LIBCFS_FREE(hs, offsetof(struct cfs_hash, hs_name[len]));
return NULL;
}
static void
cfs_hash_destroy(struct cfs_hash *hs)
{
struct hlist_node *hnode;
struct hlist_node *pos;
struct cfs_hash_bd bd;
int i;
LASSERT(hs != NULL);
LASSERT(!cfs_hash_is_exiting(hs) &&
!cfs_hash_is_iterating(hs));
hs->hs_exiting = 1;
if (cfs_hash_with_rehash(hs))
cfs_hash_rehash_cancel(hs);
cfs_hash_depth_wi_cancel(hs);
LASSERT(hs->hs_buckets != NULL &&
hs->hs_rehash_buckets == NULL);
cfs_hash_for_each_bucket(hs, &bd, i) {
struct hlist_head *hhead;
LASSERT(bd.bd_bucket != NULL);
cfs_hash_bd_lock(hs, &bd, 1);
cfs_hash_bd_for_each_hlist(hs, &bd, hhead) {
hlist_for_each_safe(hnode, pos, hhead) {
LASSERTF(!cfs_hash_with_assert_empty(hs),
"hash %s bucket %u(%u) is not empty: %u items left\n",
hs->hs_name, bd.bd_bucket->hsb_index,
bd.bd_offset, bd.bd_bucket->hsb_count);
cfs_hash_bd_del_locked(hs, &bd, hnode);
cfs_hash_exit(hs, hnode);
}
}
LASSERT(bd.bd_bucket->hsb_count == 0);
cfs_hash_bd_unlock(hs, &bd, 1);
cond_resched();
}
LASSERT(atomic_read(&hs->hs_count) == 0);
cfs_hash_buckets_free(hs->hs_buckets, cfs_hash_bkt_size(hs),
0, CFS_HASH_NBKT(hs));
i = cfs_hash_with_bigname(hs) ?
CFS_HASH_BIGNAME_LEN : CFS_HASH_NAME_LEN;
LIBCFS_FREE(hs, offsetof(struct cfs_hash, hs_name[i]));
}
struct cfs_hash *cfs_hash_getref(struct cfs_hash *hs)
{
if (atomic_inc_not_zero(&hs->hs_refcount))
return hs;
return NULL;
}
void cfs_hash_putref(struct cfs_hash *hs)
{
if (atomic_dec_and_test(&hs->hs_refcount))
cfs_hash_destroy(hs);
}
static inline int
cfs_hash_rehash_bits(struct cfs_hash *hs)
{
if (cfs_hash_with_no_lock(hs) ||
!cfs_hash_with_rehash(hs))
return -EOPNOTSUPP;
if (unlikely(cfs_hash_is_exiting(hs)))
return -ESRCH;
if (unlikely(cfs_hash_is_rehashing(hs)))
return -EALREADY;
if (unlikely(cfs_hash_is_iterating(hs)))
return -EAGAIN;
if ((hs->hs_cur_bits < hs->hs_max_bits) &&
(__cfs_hash_theta(hs) > hs->hs_max_theta))
return hs->hs_cur_bits + 1;
if (!cfs_hash_with_shrink(hs))
return 0;
if ((hs->hs_cur_bits > hs->hs_min_bits) &&
(__cfs_hash_theta(hs) < hs->hs_min_theta))
return hs->hs_cur_bits - 1;
return 0;
}
static inline int
cfs_hash_rehash_inline(struct cfs_hash *hs)
{
return !cfs_hash_with_nblk_change(hs) &&
atomic_read(&hs->hs_count) < CFS_HASH_LOOP_HOG;
}
void
cfs_hash_add(struct cfs_hash *hs, const void *key, struct hlist_node *hnode)
{
struct cfs_hash_bd bd;
int bits;
LASSERT(hlist_unhashed(hnode));
cfs_hash_lock(hs, 0);
cfs_hash_bd_get_and_lock(hs, key, &bd, 1);
cfs_hash_key_validate(hs, key, hnode);
cfs_hash_bd_add_locked(hs, &bd, hnode);
cfs_hash_bd_unlock(hs, &bd, 1);
bits = cfs_hash_rehash_bits(hs);
cfs_hash_unlock(hs, 0);
if (bits > 0)
cfs_hash_rehash(hs, cfs_hash_rehash_inline(hs));
}
static struct hlist_node *
cfs_hash_find_or_add(struct cfs_hash *hs, const void *key,
struct hlist_node *hnode, int noref)
{
struct hlist_node *ehnode;
struct cfs_hash_bd bds[2];
int bits = 0;
LASSERT(hlist_unhashed(hnode));
cfs_hash_lock(hs, 0);
cfs_hash_dual_bd_get_and_lock(hs, key, bds, 1);
cfs_hash_key_validate(hs, key, hnode);
ehnode = cfs_hash_dual_bd_findadd_locked(hs, bds, key,
hnode, noref);
cfs_hash_dual_bd_unlock(hs, bds, 1);
if (ehnode == hnode)
bits = cfs_hash_rehash_bits(hs);
cfs_hash_unlock(hs, 0);
if (bits > 0)
cfs_hash_rehash(hs, cfs_hash_rehash_inline(hs));
return ehnode;
}
int
cfs_hash_add_unique(struct cfs_hash *hs, const void *key,
struct hlist_node *hnode)
{
return cfs_hash_find_or_add(hs, key, hnode, 1) != hnode ?
-EALREADY : 0;
}
void *
cfs_hash_findadd_unique(struct cfs_hash *hs, const void *key,
struct hlist_node *hnode)
{
hnode = cfs_hash_find_or_add(hs, key, hnode, 0);
return cfs_hash_object(hs, hnode);
}
void *
cfs_hash_del(struct cfs_hash *hs, const void *key, struct hlist_node *hnode)
{
void *obj = NULL;
int bits = 0;
struct cfs_hash_bd bds[2];
cfs_hash_lock(hs, 0);
cfs_hash_dual_bd_get_and_lock(hs, key, bds, 1);
if (hnode == NULL || !hlist_unhashed(hnode)) {
if (bds[1].bd_bucket == NULL && hnode != NULL) {
cfs_hash_bd_del_locked(hs, &bds[0], hnode);
} else {
hnode = cfs_hash_dual_bd_finddel_locked(hs, bds,
key, hnode);
}
}
if (hnode != NULL) {
obj = cfs_hash_object(hs, hnode);
bits = cfs_hash_rehash_bits(hs);
}
cfs_hash_dual_bd_unlock(hs, bds, 1);
cfs_hash_unlock(hs, 0);
if (bits > 0)
cfs_hash_rehash(hs, cfs_hash_rehash_inline(hs));
return obj;
}
void *
cfs_hash_del_key(struct cfs_hash *hs, const void *key)
{
return cfs_hash_del(hs, key, NULL);
}
void *
cfs_hash_lookup(struct cfs_hash *hs, const void *key)
{
void *obj = NULL;
struct hlist_node *hnode;
struct cfs_hash_bd bds[2];
cfs_hash_lock(hs, 0);
cfs_hash_dual_bd_get_and_lock(hs, key, bds, 0);
hnode = cfs_hash_dual_bd_lookup_locked(hs, bds, key);
if (hnode != NULL)
obj = cfs_hash_object(hs, hnode);
cfs_hash_dual_bd_unlock(hs, bds, 0);
cfs_hash_unlock(hs, 0);
return obj;
}
static void
cfs_hash_for_each_enter(struct cfs_hash *hs)
{
LASSERT(!cfs_hash_is_exiting(hs));
if (!cfs_hash_with_rehash(hs))
return;
hs->hs_iterating = 1;
cfs_hash_lock(hs, 1);
hs->hs_iterators++;
if (cfs_hash_is_rehashing(hs))
cfs_hash_rehash_cancel_locked(hs);
cfs_hash_unlock(hs, 1);
}
static void
cfs_hash_for_each_exit(struct cfs_hash *hs)
{
int remained;
int bits;
if (!cfs_hash_with_rehash(hs))
return;
cfs_hash_lock(hs, 1);
remained = --hs->hs_iterators;
bits = cfs_hash_rehash_bits(hs);
cfs_hash_unlock(hs, 1);
if (remained == 0)
hs->hs_iterating = 0;
if (bits > 0) {
cfs_hash_rehash(hs, atomic_read(&hs->hs_count) <
CFS_HASH_LOOP_HOG);
}
}
static __u64
cfs_hash_for_each_tight(struct cfs_hash *hs, cfs_hash_for_each_cb_t func,
void *data, int remove_safe)
{
struct hlist_node *hnode;
struct hlist_node *pos;
struct cfs_hash_bd bd;
__u64 count = 0;
int excl = !!remove_safe;
int loop = 0;
int i;
cfs_hash_for_each_enter(hs);
cfs_hash_lock(hs, 0);
LASSERT(!cfs_hash_is_rehashing(hs));
cfs_hash_for_each_bucket(hs, &bd, i) {
struct hlist_head *hhead;
cfs_hash_bd_lock(hs, &bd, excl);
if (func == NULL) {
count += bd.bd_bucket->hsb_count;
cfs_hash_bd_unlock(hs, &bd, excl);
continue;
}
cfs_hash_bd_for_each_hlist(hs, &bd, hhead) {
hlist_for_each_safe(hnode, pos, hhead) {
cfs_hash_bucket_validate(hs, &bd, hnode);
count++;
loop++;
if (func(hs, &bd, hnode, data)) {
cfs_hash_bd_unlock(hs, &bd, excl);
goto out;
}
}
}
cfs_hash_bd_unlock(hs, &bd, excl);
if (loop < CFS_HASH_LOOP_HOG)
continue;
loop = 0;
cfs_hash_unlock(hs, 0);
cond_resched();
cfs_hash_lock(hs, 0);
}
out:
cfs_hash_unlock(hs, 0);
cfs_hash_for_each_exit(hs);
return count;
}
static int
cfs_hash_cond_del_locked(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *data)
{
struct cfs_hash_cond_arg *cond = data;
if (cond->func(cfs_hash_object(hs, hnode), cond->arg))
cfs_hash_bd_del_locked(hs, bd, hnode);
return 0;
}
void
cfs_hash_cond_del(struct cfs_hash *hs, cfs_hash_cond_opt_cb_t func, void *data)
{
struct cfs_hash_cond_arg arg = {
.func = func,
.arg = data,
};
cfs_hash_for_each_tight(hs, cfs_hash_cond_del_locked, &arg, 1);
}
void
cfs_hash_for_each(struct cfs_hash *hs, cfs_hash_for_each_cb_t func,
void *data)
{
cfs_hash_for_each_tight(hs, func, data, 0);
}
void
cfs_hash_for_each_safe(struct cfs_hash *hs, cfs_hash_for_each_cb_t func,
void *data)
{
cfs_hash_for_each_tight(hs, func, data, 1);
}
static int
cfs_hash_peek(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *data)
{
*(int *)data = 0;
return 1;
}
int
cfs_hash_is_empty(struct cfs_hash *hs)
{
int empty = 1;
cfs_hash_for_each_tight(hs, cfs_hash_peek, &empty, 0);
return empty;
}
__u64
cfs_hash_size_get(struct cfs_hash *hs)
{
return cfs_hash_with_counter(hs) ?
atomic_read(&hs->hs_count) :
cfs_hash_for_each_tight(hs, NULL, NULL, 0);
}
static int
cfs_hash_for_each_relax(struct cfs_hash *hs, cfs_hash_for_each_cb_t func,
void *data)
{
struct hlist_node *hnode;
struct hlist_node *tmp;
struct cfs_hash_bd bd;
__u32 version;
int count = 0;
int stop_on_change;
int rc;
int i;
stop_on_change = cfs_hash_with_rehash_key(hs) ||
!cfs_hash_with_no_itemref(hs) ||
hs->hs_ops->hs_put_locked == NULL;
cfs_hash_lock(hs, 0);
LASSERT(!cfs_hash_is_rehashing(hs));
cfs_hash_for_each_bucket(hs, &bd, i) {
struct hlist_head *hhead;
cfs_hash_bd_lock(hs, &bd, 0);
version = cfs_hash_bd_version_get(&bd);
cfs_hash_bd_for_each_hlist(hs, &bd, hhead) {
for (hnode = hhead->first; hnode != NULL;) {
cfs_hash_bucket_validate(hs, &bd, hnode);
cfs_hash_get(hs, hnode);
cfs_hash_bd_unlock(hs, &bd, 0);
cfs_hash_unlock(hs, 0);
rc = func(hs, &bd, hnode, data);
if (stop_on_change)
cfs_hash_put(hs, hnode);
cond_resched();
count++;
cfs_hash_lock(hs, 0);
cfs_hash_bd_lock(hs, &bd, 0);
if (!stop_on_change) {
tmp = hnode->next;
cfs_hash_put_locked(hs, hnode);
hnode = tmp;
} else {
if (version !=
cfs_hash_bd_version_get(&bd))
break;
hnode = hnode->next;
}
if (rc)
break;
}
if (rc)
break;
}
cfs_hash_bd_unlock(hs, &bd, 0);
if (rc)
break;
}
cfs_hash_unlock(hs, 0);
return count;
}
int
cfs_hash_for_each_nolock(struct cfs_hash *hs, cfs_hash_for_each_cb_t func,
void *data)
{
if (cfs_hash_with_no_lock(hs) ||
cfs_hash_with_rehash_key(hs) ||
!cfs_hash_with_no_itemref(hs))
return -EOPNOTSUPP;
if (hs->hs_ops->hs_get == NULL ||
(hs->hs_ops->hs_put == NULL &&
hs->hs_ops->hs_put_locked == NULL))
return -EOPNOTSUPP;
cfs_hash_for_each_enter(hs);
cfs_hash_for_each_relax(hs, func, data);
cfs_hash_for_each_exit(hs);
return 0;
}
int
cfs_hash_for_each_empty(struct cfs_hash *hs, cfs_hash_for_each_cb_t func,
void *data)
{
unsigned i = 0;
if (cfs_hash_with_no_lock(hs))
return -EOPNOTSUPP;
if (hs->hs_ops->hs_get == NULL ||
(hs->hs_ops->hs_put == NULL &&
hs->hs_ops->hs_put_locked == NULL))
return -EOPNOTSUPP;
cfs_hash_for_each_enter(hs);
while (cfs_hash_for_each_relax(hs, func, data)) {
CDEBUG(D_INFO, "Try to empty hash: %s, loop: %u\n",
hs->hs_name, i++);
}
cfs_hash_for_each_exit(hs);
return 0;
}
void
cfs_hash_hlist_for_each(struct cfs_hash *hs, unsigned hindex,
cfs_hash_for_each_cb_t func, void *data)
{
struct hlist_head *hhead;
struct hlist_node *hnode;
struct cfs_hash_bd bd;
cfs_hash_for_each_enter(hs);
cfs_hash_lock(hs, 0);
if (hindex >= CFS_HASH_NHLIST(hs))
goto out;
cfs_hash_bd_index_set(hs, hindex, &bd);
cfs_hash_bd_lock(hs, &bd, 0);
hhead = cfs_hash_bd_hhead(hs, &bd);
hlist_for_each(hnode, hhead) {
if (func(hs, &bd, hnode, data))
break;
}
cfs_hash_bd_unlock(hs, &bd, 0);
out:
cfs_hash_unlock(hs, 0);
cfs_hash_for_each_exit(hs);
}
void
cfs_hash_for_each_key(struct cfs_hash *hs, const void *key,
cfs_hash_for_each_cb_t func, void *data)
{
struct hlist_node *hnode;
struct cfs_hash_bd bds[2];
unsigned int i;
cfs_hash_lock(hs, 0);
cfs_hash_dual_bd_get_and_lock(hs, key, bds, 0);
cfs_hash_for_each_bd(bds, 2, i) {
struct hlist_head *hlist = cfs_hash_bd_hhead(hs, &bds[i]);
hlist_for_each(hnode, hlist) {
cfs_hash_bucket_validate(hs, &bds[i], hnode);
if (cfs_hash_keycmp(hs, key, hnode)) {
if (func(hs, &bds[i], hnode, data))
break;
}
}
}
cfs_hash_dual_bd_unlock(hs, bds, 0);
cfs_hash_unlock(hs, 0);
}
void
cfs_hash_rehash_cancel_locked(struct cfs_hash *hs)
{
int i;
LASSERT(cfs_hash_with_rehash(hs) &&
!cfs_hash_with_no_lock(hs));
if (!cfs_hash_is_rehashing(hs))
return;
if (cfs_wi_deschedule(cfs_sched_rehash, &hs->hs_rehash_wi)) {
hs->hs_rehash_bits = 0;
return;
}
for (i = 2; cfs_hash_is_rehashing(hs); i++) {
cfs_hash_unlock(hs, 1);
CDEBUG(is_power_of_2(i >> 3) ? D_WARNING : D_INFO,
"hash %s is still rehashing, rescheded %d\n",
hs->hs_name, i - 1);
cond_resched();
cfs_hash_lock(hs, 1);
}
}
void
cfs_hash_rehash_cancel(struct cfs_hash *hs)
{
cfs_hash_lock(hs, 1);
cfs_hash_rehash_cancel_locked(hs);
cfs_hash_unlock(hs, 1);
}
int
cfs_hash_rehash(struct cfs_hash *hs, int do_rehash)
{
int rc;
LASSERT(cfs_hash_with_rehash(hs) && !cfs_hash_with_no_lock(hs));
cfs_hash_lock(hs, 1);
rc = cfs_hash_rehash_bits(hs);
if (rc <= 0) {
cfs_hash_unlock(hs, 1);
return rc;
}
hs->hs_rehash_bits = rc;
if (!do_rehash) {
cfs_wi_schedule(cfs_sched_rehash, &hs->hs_rehash_wi);
cfs_hash_unlock(hs, 1);
return 0;
}
cfs_hash_unlock(hs, 1);
return cfs_hash_rehash_worker(&hs->hs_rehash_wi);
}
static int
cfs_hash_rehash_bd(struct cfs_hash *hs, struct cfs_hash_bd *old)
{
struct cfs_hash_bd new;
struct hlist_head *hhead;
struct hlist_node *hnode;
struct hlist_node *pos;
void *key;
int c = 0;
cfs_hash_bd_for_each_hlist(hs, old, hhead) {
hlist_for_each_safe(hnode, pos, hhead) {
key = cfs_hash_key(hs, hnode);
LASSERT(key != NULL);
cfs_hash_bucket_validate(hs, old, hnode);
cfs_hash_bd_from_key(hs, hs->hs_rehash_buckets,
hs->hs_rehash_bits, key, &new);
cfs_hash_bd_move_locked(hs, old, &new, hnode);
c++;
}
}
return c;
}
static int
cfs_hash_rehash_worker(cfs_workitem_t *wi)
{
struct cfs_hash *hs = container_of(wi, struct cfs_hash, hs_rehash_wi);
struct cfs_hash_bucket **bkts;
struct cfs_hash_bd bd;
unsigned int old_size;
unsigned int new_size;
int bsize;
int count = 0;
int rc = 0;
int i;
LASSERT(hs != NULL && cfs_hash_with_rehash(hs));
cfs_hash_lock(hs, 0);
LASSERT(cfs_hash_is_rehashing(hs));
old_size = CFS_HASH_NBKT(hs);
new_size = CFS_HASH_RH_NBKT(hs);
cfs_hash_unlock(hs, 0);
bkts = cfs_hash_buckets_realloc(hs, hs->hs_buckets,
old_size, new_size);
cfs_hash_lock(hs, 1);
if (bkts == NULL) {
rc = -ENOMEM;
goto out;
}
if (bkts == hs->hs_buckets) {
bkts = NULL;
goto out;
}
rc = __cfs_hash_theta(hs);
if ((rc >= hs->hs_min_theta) && (rc <= hs->hs_max_theta)) {
old_size = new_size;
new_size = CFS_HASH_NBKT(hs);
rc = -EALREADY;
goto out;
}
LASSERT(hs->hs_rehash_buckets == NULL);
hs->hs_rehash_buckets = bkts;
rc = 0;
cfs_hash_for_each_bucket(hs, &bd, i) {
if (cfs_hash_is_exiting(hs)) {
rc = -ESRCH;
if (old_size < new_size)
break;
hs->hs_rehash_buckets = NULL;
old_size = new_size;
new_size = CFS_HASH_NBKT(hs);
goto out;
}
count += cfs_hash_rehash_bd(hs, &bd);
if (count < CFS_HASH_LOOP_HOG ||
cfs_hash_is_iterating(hs)) {
continue;
}
count = 0;
cfs_hash_unlock(hs, 1);
cond_resched();
cfs_hash_lock(hs, 1);
}
hs->hs_rehash_count++;
bkts = hs->hs_buckets;
hs->hs_buckets = hs->hs_rehash_buckets;
hs->hs_rehash_buckets = NULL;
hs->hs_cur_bits = hs->hs_rehash_bits;
out:
hs->hs_rehash_bits = 0;
if (rc == -ESRCH)
cfs_wi_exit(cfs_sched_rehash, wi);
bsize = cfs_hash_bkt_size(hs);
cfs_hash_unlock(hs, 1);
if (bkts != NULL)
cfs_hash_buckets_free(bkts, bsize, new_size, old_size);
if (rc != 0)
CDEBUG(D_INFO, "early quit of rehashing: %d\n", rc);
return rc == -ESRCH;
}
void cfs_hash_rehash_key(struct cfs_hash *hs, const void *old_key,
void *new_key, struct hlist_node *hnode)
{
struct cfs_hash_bd bds[3];
struct cfs_hash_bd old_bds[2];
struct cfs_hash_bd new_bd;
LASSERT(!hlist_unhashed(hnode));
cfs_hash_lock(hs, 0);
cfs_hash_dual_bd_get(hs, old_key, old_bds);
cfs_hash_bd_get(hs, new_key, &new_bd);
bds[0] = old_bds[0];
bds[1] = old_bds[1];
bds[2] = new_bd;
cfs_hash_bd_order(&bds[1], &bds[2]);
cfs_hash_bd_order(&bds[0], &bds[1]);
cfs_hash_multi_bd_lock(hs, bds, 3, 1);
if (likely(old_bds[1].bd_bucket == NULL)) {
cfs_hash_bd_move_locked(hs, &old_bds[0], &new_bd, hnode);
} else {
cfs_hash_dual_bd_finddel_locked(hs, old_bds, old_key, hnode);
cfs_hash_bd_add_locked(hs, &new_bd, hnode);
}
cfs_hash_keycpy(hs, hnode, new_key);
cfs_hash_multi_bd_unlock(hs, bds, 3, 1);
cfs_hash_unlock(hs, 0);
}
void cfs_hash_debug_header(struct seq_file *m)
{
seq_printf(m, "%-*s cur min max theta t-min t-max flags rehash count maxdep maxdepb distribution\n",
CFS_HASH_BIGNAME_LEN, "name");
}
static struct cfs_hash_bucket **
cfs_hash_full_bkts(struct cfs_hash *hs)
{
if (hs->hs_rehash_buckets == NULL)
return hs->hs_buckets;
LASSERT(hs->hs_rehash_bits != 0);
return hs->hs_rehash_bits > hs->hs_cur_bits ?
hs->hs_rehash_buckets : hs->hs_buckets;
}
static unsigned int
cfs_hash_full_nbkt(struct cfs_hash *hs)
{
if (hs->hs_rehash_buckets == NULL)
return CFS_HASH_NBKT(hs);
LASSERT(hs->hs_rehash_bits != 0);
return hs->hs_rehash_bits > hs->hs_cur_bits ?
CFS_HASH_RH_NBKT(hs) : CFS_HASH_NBKT(hs);
}
void cfs_hash_debug_str(struct cfs_hash *hs, struct seq_file *m)
{
int dist[8] = { 0, };
int maxdep = -1;
int maxdepb = -1;
int total = 0;
int theta;
int i;
cfs_hash_lock(hs, 0);
theta = __cfs_hash_theta(hs);
seq_printf(m, "%-*s %5d %5d %5d %d.%03d %d.%03d %d.%03d 0x%02x %6d ",
CFS_HASH_BIGNAME_LEN, hs->hs_name,
1 << hs->hs_cur_bits, 1 << hs->hs_min_bits,
1 << hs->hs_max_bits,
__cfs_hash_theta_int(theta), __cfs_hash_theta_frac(theta),
__cfs_hash_theta_int(hs->hs_min_theta),
__cfs_hash_theta_frac(hs->hs_min_theta),
__cfs_hash_theta_int(hs->hs_max_theta),
__cfs_hash_theta_frac(hs->hs_max_theta),
hs->hs_flags, hs->hs_rehash_count);
for (i = 0; i < cfs_hash_full_nbkt(hs); i++) {
struct cfs_hash_bd bd;
bd.bd_bucket = cfs_hash_full_bkts(hs)[i];
cfs_hash_bd_lock(hs, &bd, 0);
if (maxdep < bd.bd_bucket->hsb_depmax) {
maxdep = bd.bd_bucket->hsb_depmax;
maxdepb = ffz(~maxdep);
}
total += bd.bd_bucket->hsb_count;
dist[min(fls(bd.bd_bucket->hsb_count / max(theta, 1)), 7)]++;
cfs_hash_bd_unlock(hs, &bd, 0);
}
seq_printf(m, "%7d %7d %7d ", total, maxdep, maxdepb);
for (i = 0; i < 8; i++)
seq_printf(m, "%d%c", dist[i], (i == 7) ? '\n' : '/');
cfs_hash_unlock(hs, 0);
}
