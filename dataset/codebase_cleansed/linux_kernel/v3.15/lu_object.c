void lu_object_put(const struct lu_env *env, struct lu_object *o)
{
struct lu_site_bkt_data *bkt;
struct lu_object_header *top;
struct lu_site *site;
struct lu_object *orig;
struct cfs_hash_bd bd;
const struct lu_fid *fid;
top = o->lo_header;
site = o->lo_dev->ld_site;
orig = o;
fid = lu_object_fid(o);
if (fid_is_zero(fid)) {
LASSERT(top->loh_hash.next == NULL
&& top->loh_hash.pprev == NULL);
LASSERT(list_empty(&top->loh_lru));
if (!atomic_dec_and_test(&top->loh_ref))
return;
list_for_each_entry_reverse(o, &top->loh_layers, lo_linkage) {
if (o->lo_ops->loo_object_release != NULL)
o->lo_ops->loo_object_release(env, o);
}
lu_object_free(env, orig);
return;
}
cfs_hash_bd_get(site->ls_obj_hash, &top->loh_fid, &bd);
bkt = cfs_hash_bd_extra_get(site->ls_obj_hash, &bd);
if (!cfs_hash_bd_dec_and_lock(site->ls_obj_hash, &bd, &top->loh_ref)) {
if (lu_object_is_dying(top)) {
wake_up_all(&bkt->lsb_marche_funebre);
}
return;
}
LASSERT(bkt->lsb_busy > 0);
bkt->lsb_busy--;
list_for_each_entry_reverse(o, &top->loh_layers, lo_linkage) {
if (o->lo_ops->loo_object_release != NULL)
o->lo_ops->loo_object_release(env, o);
}
if (!lu_object_is_dying(top)) {
LASSERT(list_empty(&top->loh_lru));
list_add_tail(&top->loh_lru, &bkt->lsb_lru);
cfs_hash_bd_unlock(site->ls_obj_hash, &bd, 1);
return;
}
if (!test_and_set_bit(LU_OBJECT_UNHASHED, &top->loh_flags))
cfs_hash_bd_del_locked(site->ls_obj_hash, &bd, &top->loh_hash);
cfs_hash_bd_unlock(site->ls_obj_hash, &bd, 1);
lu_object_free(env, orig);
}
void lu_object_put_nocache(const struct lu_env *env, struct lu_object *o)
{
set_bit(LU_OBJECT_HEARD_BANSHEE, &o->lo_header->loh_flags);
return lu_object_put(env, o);
}
void lu_object_unhash(const struct lu_env *env, struct lu_object *o)
{
struct lu_object_header *top;
top = o->lo_header;
set_bit(LU_OBJECT_HEARD_BANSHEE, &top->loh_flags);
if (!test_and_set_bit(LU_OBJECT_UNHASHED, &top->loh_flags)) {
struct cfs_hash *obj_hash = o->lo_dev->ld_site->ls_obj_hash;
struct cfs_hash_bd bd;
cfs_hash_bd_get_and_lock(obj_hash, &top->loh_fid, &bd, 1);
list_del_init(&top->loh_lru);
cfs_hash_bd_del_locked(obj_hash, &bd, &top->loh_hash);
cfs_hash_bd_unlock(obj_hash, &bd, 1);
}
}
static struct lu_object *lu_object_alloc(const struct lu_env *env,
struct lu_device *dev,
const struct lu_fid *f,
const struct lu_object_conf *conf)
{
struct lu_object *scan;
struct lu_object *top;
struct list_head *layers;
unsigned int init_mask = 0;
unsigned int init_flag;
int clean;
int result;
top = dev->ld_ops->ldo_object_alloc(env, NULL, dev);
if (top == NULL)
return ERR_PTR(-ENOMEM);
if (IS_ERR(top))
return top;
top->lo_header->loh_fid = *f;
layers = &top->lo_header->loh_layers;
do {
clean = 1;
init_flag = 1;
list_for_each_entry(scan, layers, lo_linkage) {
if (init_mask & init_flag)
goto next;
clean = 0;
scan->lo_header = top->lo_header;
result = scan->lo_ops->loo_object_init(env, scan, conf);
if (result != 0) {
lu_object_free(env, top);
return ERR_PTR(result);
}
init_mask |= init_flag;
next:
init_flag <<= 1;
}
} while (!clean);
list_for_each_entry_reverse(scan, layers, lo_linkage) {
if (scan->lo_ops->loo_object_start != NULL) {
result = scan->lo_ops->loo_object_start(env, scan);
if (result != 0) {
lu_object_free(env, top);
return ERR_PTR(result);
}
}
}
lprocfs_counter_incr(dev->ld_site->ls_stats, LU_SS_CREATED);
return top;
}
static void lu_object_free(const struct lu_env *env, struct lu_object *o)
{
struct lu_site_bkt_data *bkt;
struct lu_site *site;
struct lu_object *scan;
struct list_head *layers;
struct list_head splice;
site = o->lo_dev->ld_site;
layers = &o->lo_header->loh_layers;
bkt = lu_site_bkt_from_fid(site, &o->lo_header->loh_fid);
list_for_each_entry_reverse(scan, layers, lo_linkage) {
if (scan->lo_ops->loo_object_delete != NULL)
scan->lo_ops->loo_object_delete(env, scan);
}
INIT_LIST_HEAD(&splice);
list_splice_init(layers, &splice);
while (!list_empty(&splice)) {
o = container_of0(splice.prev, struct lu_object, lo_linkage);
list_del_init(&o->lo_linkage);
LASSERT(o->lo_ops->loo_object_free != NULL);
o->lo_ops->loo_object_free(env, o);
}
if (waitqueue_active(&bkt->lsb_marche_funebre))
wake_up_all(&bkt->lsb_marche_funebre);
}
int lu_site_purge(const struct lu_env *env, struct lu_site *s, int nr)
{
struct lu_object_header *h;
struct lu_object_header *temp;
struct lu_site_bkt_data *bkt;
struct cfs_hash_bd bd;
struct cfs_hash_bd bd2;
struct list_head dispose;
int did_sth;
int start;
int count;
int bnr;
int i;
if (OBD_FAIL_CHECK(OBD_FAIL_OBD_NO_LRU))
return 0;
INIT_LIST_HEAD(&dispose);
start = s->ls_purge_start;
bnr = (nr == ~0) ? -1 : nr / CFS_HASH_NBKT(s->ls_obj_hash) + 1;
again:
did_sth = 0;
cfs_hash_for_each_bucket(s->ls_obj_hash, &bd, i) {
if (i < start)
continue;
count = bnr;
cfs_hash_bd_lock(s->ls_obj_hash, &bd, 1);
bkt = cfs_hash_bd_extra_get(s->ls_obj_hash, &bd);
list_for_each_entry_safe(h, temp, &bkt->lsb_lru, loh_lru) {
LASSERT(atomic_read(&h->loh_ref) == 0);
cfs_hash_bd_get(s->ls_obj_hash, &h->loh_fid, &bd2);
LASSERT(bd.bd_bucket == bd2.bd_bucket);
cfs_hash_bd_del_locked(s->ls_obj_hash,
&bd2, &h->loh_hash);
list_move(&h->loh_lru, &dispose);
if (did_sth == 0)
did_sth = 1;
if (nr != ~0 && --nr == 0)
break;
if (count > 0 && --count == 0)
break;
}
cfs_hash_bd_unlock(s->ls_obj_hash, &bd, 1);
cond_resched();
while (!list_empty(&dispose)) {
h = container_of0(dispose.next,
struct lu_object_header, loh_lru);
list_del_init(&h->loh_lru);
lu_object_free(env, lu_object_top(h));
lprocfs_counter_incr(s->ls_stats, LU_SS_LRU_PURGED);
}
if (nr == 0)
break;
}
if (nr != 0 && did_sth && start != 0) {
start = 0;
goto again;
}
s->ls_purge_start = i % CFS_HASH_NBKT(s->ls_obj_hash);
return nr;
}
int lu_cdebug_printer(const struct lu_env *env,
void *cookie, const char *format, ...)
{
struct libcfs_debug_msg_data *msgdata = cookie;
struct lu_cdebug_data *key;
int used;
int complete;
va_list args;
va_start(args, format);
key = lu_context_key_get(&env->le_ctx, &lu_global_key);
LASSERT(key != NULL);
used = strlen(key->lck_area);
complete = format[strlen(format) - 1] == '\n';
vsnprintf(key->lck_area + used,
ARRAY_SIZE(key->lck_area) - used, format, args);
if (complete) {
if (cfs_cdebug_show(msgdata->msg_mask, msgdata->msg_subsys))
libcfs_debug_msg(msgdata, "%s", key->lck_area);
key->lck_area[0] = 0;
}
va_end(args);
return 0;
}
void lu_object_header_print(const struct lu_env *env, void *cookie,
lu_printer_t printer,
const struct lu_object_header *hdr)
{
(*printer)(env, cookie, "header@%p[%#lx, %d, "DFID"%s%s%s]",
hdr, hdr->loh_flags, atomic_read(&hdr->loh_ref),
PFID(&hdr->loh_fid),
hlist_unhashed(&hdr->loh_hash) ? "" : " hash",
list_empty((struct list_head *)&hdr->loh_lru) ? \
"" : " lru",
hdr->loh_attr & LOHA_EXISTS ? " exist":"");
}
void lu_object_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct lu_object *o)
{
static const char ruler[] = "........................................";
struct lu_object_header *top;
int depth = 4;
top = o->lo_header;
lu_object_header_print(env, cookie, printer, top);
(*printer)(env, cookie, "{\n");
list_for_each_entry(o, &top->loh_layers, lo_linkage) {
(*printer)(env, cookie, "%*.*s%s@%p", depth, depth, ruler,
o->lo_dev->ld_type->ldt_name, o);
if (o->lo_ops->loo_object_print != NULL)
(*o->lo_ops->loo_object_print)(env, cookie, printer, o);
(*printer)(env, cookie, "\n");
}
(*printer)(env, cookie, "} header@%p\n", top);
}
int lu_object_invariant(const struct lu_object *o)
{
struct lu_object_header *top;
top = o->lo_header;
list_for_each_entry(o, &top->loh_layers, lo_linkage) {
if (o->lo_ops->loo_object_invariant != NULL &&
!o->lo_ops->loo_object_invariant(o))
return 0;
}
return 1;
}
static struct lu_object *htable_lookup(struct lu_site *s,
struct cfs_hash_bd *bd,
const struct lu_fid *f,
wait_queue_t *waiter,
__u64 *version)
{
struct lu_site_bkt_data *bkt;
struct lu_object_header *h;
struct hlist_node *hnode;
__u64 ver = cfs_hash_bd_version_get(bd);
if (*version == ver)
return ERR_PTR(-ENOENT);
*version = ver;
bkt = cfs_hash_bd_extra_get(s->ls_obj_hash, bd);
hnode = cfs_hash_bd_peek_locked(s->ls_obj_hash, bd, (void *)f);
if (hnode == NULL) {
lprocfs_counter_incr(s->ls_stats, LU_SS_CACHE_MISS);
return ERR_PTR(-ENOENT);
}
h = container_of0(hnode, struct lu_object_header, loh_hash);
if (likely(!lu_object_is_dying(h))) {
cfs_hash_get(s->ls_obj_hash, hnode);
lprocfs_counter_incr(s->ls_stats, LU_SS_CACHE_HIT);
list_del_init(&h->loh_lru);
return lu_object_top(h);
}
init_waitqueue_entry(waiter, current);
add_wait_queue(&bkt->lsb_marche_funebre, waiter);
set_current_state(TASK_UNINTERRUPTIBLE);
lprocfs_counter_incr(s->ls_stats, LU_SS_CACHE_DEATH_RACE);
return ERR_PTR(-EAGAIN);
}
struct lu_object *lu_object_find(const struct lu_env *env,
struct lu_device *dev, const struct lu_fid *f,
const struct lu_object_conf *conf)
{
return lu_object_find_at(env, dev->ld_site->ls_top_dev, f, conf);
}
static struct lu_object *lu_object_new(const struct lu_env *env,
struct lu_device *dev,
const struct lu_fid *f,
const struct lu_object_conf *conf)
{
struct lu_object *o;
struct cfs_hash *hs;
struct cfs_hash_bd bd;
struct lu_site_bkt_data *bkt;
o = lu_object_alloc(env, dev, f, conf);
if (unlikely(IS_ERR(o)))
return o;
hs = dev->ld_site->ls_obj_hash;
cfs_hash_bd_get_and_lock(hs, (void *)f, &bd, 1);
bkt = cfs_hash_bd_extra_get(hs, &bd);
cfs_hash_bd_add_locked(hs, &bd, &o->lo_header->loh_hash);
bkt->lsb_busy++;
cfs_hash_bd_unlock(hs, &bd, 1);
return o;
}
static struct lu_object *lu_object_find_try(const struct lu_env *env,
struct lu_device *dev,
const struct lu_fid *f,
const struct lu_object_conf *conf,
wait_queue_t *waiter)
{
struct lu_object *o;
struct lu_object *shadow;
struct lu_site *s;
struct cfs_hash *hs;
struct cfs_hash_bd bd;
__u64 version = 0;
if (conf != NULL && conf->loc_flags & LOC_F_NEW)
return lu_object_new(env, dev, f, conf);
s = dev->ld_site;
hs = s->ls_obj_hash;
cfs_hash_bd_get_and_lock(hs, (void *)f, &bd, 1);
o = htable_lookup(s, &bd, f, waiter, &version);
cfs_hash_bd_unlock(hs, &bd, 1);
if (!IS_ERR(o) || PTR_ERR(o) != -ENOENT)
return o;
o = lu_object_alloc(env, dev, f, conf);
if (unlikely(IS_ERR(o)))
return o;
LASSERT(lu_fid_eq(lu_object_fid(o), f));
cfs_hash_bd_lock(hs, &bd, 1);
shadow = htable_lookup(s, &bd, f, waiter, &version);
if (likely(IS_ERR(shadow) && PTR_ERR(shadow) == -ENOENT)) {
struct lu_site_bkt_data *bkt;
bkt = cfs_hash_bd_extra_get(hs, &bd);
cfs_hash_bd_add_locked(hs, &bd, &o->lo_header->loh_hash);
bkt->lsb_busy++;
cfs_hash_bd_unlock(hs, &bd, 1);
return o;
}
lprocfs_counter_incr(s->ls_stats, LU_SS_CACHE_RACE);
cfs_hash_bd_unlock(hs, &bd, 1);
lu_object_free(env, o);
return shadow;
}
struct lu_object *lu_object_find_at(const struct lu_env *env,
struct lu_device *dev,
const struct lu_fid *f,
const struct lu_object_conf *conf)
{
struct lu_site_bkt_data *bkt;
struct lu_object *obj;
wait_queue_t wait;
while (1) {
obj = lu_object_find_try(env, dev, f, conf, &wait);
if (obj != ERR_PTR(-EAGAIN))
return obj;
schedule();
bkt = lu_site_bkt_from_fid(dev->ld_site, (void *)f);
remove_wait_queue(&bkt->lsb_marche_funebre, &wait);
}
}
struct lu_object *lu_object_find_slice(const struct lu_env *env,
struct lu_device *dev,
const struct lu_fid *f,
const struct lu_object_conf *conf)
{
struct lu_object *top;
struct lu_object *obj;
top = lu_object_find(env, dev, f, conf);
if (!IS_ERR(top)) {
obj = lu_object_locate(top->lo_header, dev->ld_type);
if (obj == NULL)
lu_object_put(env, top);
} else
obj = top;
return obj;
}
int lu_device_type_init(struct lu_device_type *ldt)
{
int result = 0;
INIT_LIST_HEAD(&ldt->ldt_linkage);
if (ldt->ldt_ops->ldto_init)
result = ldt->ldt_ops->ldto_init(ldt);
if (result == 0)
list_add(&ldt->ldt_linkage, &lu_device_types);
return result;
}
void lu_device_type_fini(struct lu_device_type *ldt)
{
list_del_init(&ldt->ldt_linkage);
if (ldt->ldt_ops->ldto_fini)
ldt->ldt_ops->ldto_fini(ldt);
}
void lu_types_stop(void)
{
struct lu_device_type *ldt;
list_for_each_entry(ldt, &lu_device_types, ldt_linkage) {
if (ldt->ldt_device_nr == 0 && ldt->ldt_ops->ldto_stop)
ldt->ldt_ops->ldto_stop(ldt);
}
}
static int
lu_site_obj_print(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *data)
{
struct lu_site_print_arg *arg = (struct lu_site_print_arg *)data;
struct lu_object_header *h;
h = hlist_entry(hnode, struct lu_object_header, loh_hash);
if (!list_empty(&h->loh_layers)) {
const struct lu_object *o;
o = lu_object_top(h);
lu_object_print(arg->lsp_env, arg->lsp_cookie,
arg->lsp_printer, o);
} else {
lu_object_header_print(arg->lsp_env, arg->lsp_cookie,
arg->lsp_printer, h);
}
return 0;
}
void lu_site_print(const struct lu_env *env, struct lu_site *s, void *cookie,
lu_printer_t printer)
{
struct lu_site_print_arg arg = {
.lsp_env = (struct lu_env *)env,
.lsp_cookie = cookie,
.lsp_printer = printer,
};
cfs_hash_for_each(s->ls_obj_hash, lu_site_obj_print, &arg);
}
static int lu_htable_order(void)
{
unsigned long cache_size;
int bits;
cache_size = totalram_pages;
#if BITS_PER_LONG == 32
if (cache_size > 1 << (30 - PAGE_CACHE_SHIFT))
cache_size = 1 << (30 - PAGE_CACHE_SHIFT) * 3 / 4;
#endif
if (lu_cache_percent == 0 || lu_cache_percent > LU_CACHE_PERCENT_MAX) {
CWARN("obdclass: invalid lu_cache_percent: %u, it must be in"
" the range of (0, %u]. Will use default value: %u.\n",
lu_cache_percent, LU_CACHE_PERCENT_MAX,
LU_CACHE_PERCENT_DEFAULT);
lu_cache_percent = LU_CACHE_PERCENT_DEFAULT;
}
cache_size = cache_size / 100 * lu_cache_percent *
(PAGE_CACHE_SIZE / 1024);
for (bits = 1; (1 << bits) < cache_size; ++bits) {
;
}
return bits;
}
static unsigned lu_obj_hop_hash(struct cfs_hash *hs,
const void *key, unsigned mask)
{
struct lu_fid *fid = (struct lu_fid *)key;
__u32 hash;
hash = fid_flatten32(fid);
hash += (hash >> 4) + (hash << 12);
hash = hash_long(hash, hs->hs_bkt_bits);
hash -= hash_long((unsigned long)hs, fid_oid(fid) % 11 + 3);
hash <<= hs->hs_cur_bits - hs->hs_bkt_bits;
hash |= (fid_seq(fid) + fid_oid(fid)) & (CFS_HASH_NBKT(hs) - 1);
return hash & mask;
}
static void *lu_obj_hop_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct lu_object_header, loh_hash);
}
static void *lu_obj_hop_key(struct hlist_node *hnode)
{
struct lu_object_header *h;
h = hlist_entry(hnode, struct lu_object_header, loh_hash);
return &h->loh_fid;
}
static int lu_obj_hop_keycmp(const void *key, struct hlist_node *hnode)
{
struct lu_object_header *h;
h = hlist_entry(hnode, struct lu_object_header, loh_hash);
return lu_fid_eq(&h->loh_fid, (struct lu_fid *)key);
}
static void lu_obj_hop_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct lu_object_header *h;
h = hlist_entry(hnode, struct lu_object_header, loh_hash);
if (atomic_add_return(1, &h->loh_ref) == 1) {
struct lu_site_bkt_data *bkt;
struct cfs_hash_bd bd;
cfs_hash_bd_get(hs, &h->loh_fid, &bd);
bkt = cfs_hash_bd_extra_get(hs, &bd);
bkt->lsb_busy++;
}
}
static void lu_obj_hop_put_locked(struct cfs_hash *hs, struct hlist_node *hnode)
{
LBUG();
}
void lu_dev_add_linkage(struct lu_site *s, struct lu_device *d)
{
spin_lock(&s->ls_ld_lock);
if (list_empty(&d->ld_linkage))
list_add(&d->ld_linkage, &s->ls_ld_linkage);
spin_unlock(&s->ls_ld_lock);
}
void lu_dev_del_linkage(struct lu_site *s, struct lu_device *d)
{
spin_lock(&s->ls_ld_lock);
list_del_init(&d->ld_linkage);
spin_unlock(&s->ls_ld_lock);
}
int lu_site_init(struct lu_site *s, struct lu_device *top)
{
struct lu_site_bkt_data *bkt;
struct cfs_hash_bd bd;
char name[16];
int bits;
int i;
memset(s, 0, sizeof(*s));
bits = lu_htable_order();
snprintf(name, 16, "lu_site_%s", top->ld_type->ldt_name);
for (bits = min(max(LU_SITE_BITS_MIN, bits), LU_SITE_BITS_MAX);
bits >= LU_SITE_BITS_MIN; bits--) {
s->ls_obj_hash = cfs_hash_create(name, bits, bits,
bits - LU_SITE_BKT_BITS,
sizeof(*bkt), 0, 0,
&lu_site_hash_ops,
CFS_HASH_SPIN_BKTLOCK |
CFS_HASH_NO_ITEMREF |
CFS_HASH_DEPTH |
CFS_HASH_ASSERT_EMPTY);
if (s->ls_obj_hash != NULL)
break;
}
if (s->ls_obj_hash == NULL) {
CERROR("failed to create lu_site hash with bits: %d\n", bits);
return -ENOMEM;
}
cfs_hash_for_each_bucket(s->ls_obj_hash, &bd, i) {
bkt = cfs_hash_bd_extra_get(s->ls_obj_hash, &bd);
INIT_LIST_HEAD(&bkt->lsb_lru);
init_waitqueue_head(&bkt->lsb_marche_funebre);
}
s->ls_stats = lprocfs_alloc_stats(LU_SS_LAST_STAT, 0);
if (s->ls_stats == NULL) {
cfs_hash_putref(s->ls_obj_hash);
s->ls_obj_hash = NULL;
return -ENOMEM;
}
lprocfs_counter_init(s->ls_stats, LU_SS_CREATED,
0, "created", "created");
lprocfs_counter_init(s->ls_stats, LU_SS_CACHE_HIT,
0, "cache_hit", "cache_hit");
lprocfs_counter_init(s->ls_stats, LU_SS_CACHE_MISS,
0, "cache_miss", "cache_miss");
lprocfs_counter_init(s->ls_stats, LU_SS_CACHE_RACE,
0, "cache_race", "cache_race");
lprocfs_counter_init(s->ls_stats, LU_SS_CACHE_DEATH_RACE,
0, "cache_death_race", "cache_death_race");
lprocfs_counter_init(s->ls_stats, LU_SS_LRU_PURGED,
0, "lru_purged", "lru_purged");
INIT_LIST_HEAD(&s->ls_linkage);
s->ls_top_dev = top;
top->ld_site = s;
lu_device_get(top);
lu_ref_add(&top->ld_reference, "site-top", s);
INIT_LIST_HEAD(&s->ls_ld_linkage);
spin_lock_init(&s->ls_ld_lock);
lu_dev_add_linkage(s, top);
return 0;
}
void lu_site_fini(struct lu_site *s)
{
mutex_lock(&lu_sites_guard);
list_del_init(&s->ls_linkage);
mutex_unlock(&lu_sites_guard);
if (s->ls_obj_hash != NULL) {
cfs_hash_putref(s->ls_obj_hash);
s->ls_obj_hash = NULL;
}
if (s->ls_top_dev != NULL) {
s->ls_top_dev->ld_site = NULL;
lu_ref_del(&s->ls_top_dev->ld_reference, "site-top", s);
lu_device_put(s->ls_top_dev);
s->ls_top_dev = NULL;
}
if (s->ls_stats != NULL)
lprocfs_free_stats(&s->ls_stats);
}
int lu_site_init_finish(struct lu_site *s)
{
int result;
mutex_lock(&lu_sites_guard);
result = lu_context_refill(&lu_shrink_env.le_ctx);
if (result == 0)
list_add(&s->ls_linkage, &lu_sites);
mutex_unlock(&lu_sites_guard);
return result;
}
void lu_device_get(struct lu_device *d)
{
atomic_inc(&d->ld_ref);
}
void lu_device_put(struct lu_device *d)
{
LASSERT(atomic_read(&d->ld_ref) > 0);
atomic_dec(&d->ld_ref);
}
int lu_device_init(struct lu_device *d, struct lu_device_type *t)
{
if (t->ldt_device_nr++ == 0 && t->ldt_ops->ldto_start != NULL)
t->ldt_ops->ldto_start(t);
memset(d, 0, sizeof(*d));
atomic_set(&d->ld_ref, 0);
d->ld_type = t;
lu_ref_init(&d->ld_reference);
INIT_LIST_HEAD(&d->ld_linkage);
return 0;
}
void lu_device_fini(struct lu_device *d)
{
struct lu_device_type *t;
t = d->ld_type;
if (d->ld_obd != NULL) {
d->ld_obd->obd_lu_dev = NULL;
d->ld_obd = NULL;
}
lu_ref_fini(&d->ld_reference);
LASSERTF(atomic_read(&d->ld_ref) == 0,
"Refcount is %u\n", atomic_read(&d->ld_ref));
LASSERT(t->ldt_device_nr > 0);
if (--t->ldt_device_nr == 0 && t->ldt_ops->ldto_stop != NULL)
t->ldt_ops->ldto_stop(t);
}
int lu_object_init(struct lu_object *o, struct lu_object_header *h,
struct lu_device *d)
{
memset(o, 0, sizeof(*o));
o->lo_header = h;
o->lo_dev = d;
lu_device_get(d);
lu_ref_add_at(&d->ld_reference, &o->lo_dev_ref, "lu_object", o);
INIT_LIST_HEAD(&o->lo_linkage);
return 0;
}
void lu_object_fini(struct lu_object *o)
{
struct lu_device *dev = o->lo_dev;
LASSERT(list_empty(&o->lo_linkage));
if (dev != NULL) {
lu_ref_del_at(&dev->ld_reference, &o->lo_dev_ref,
"lu_object", o);
lu_device_put(dev);
o->lo_dev = NULL;
}
}
void lu_object_add_top(struct lu_object_header *h, struct lu_object *o)
{
list_move(&o->lo_linkage, &h->loh_layers);
}
void lu_object_add(struct lu_object *before, struct lu_object *o)
{
list_move(&o->lo_linkage, &before->lo_linkage);
}
int lu_object_header_init(struct lu_object_header *h)
{
memset(h, 0, sizeof(*h));
atomic_set(&h->loh_ref, 1);
INIT_HLIST_NODE(&h->loh_hash);
INIT_LIST_HEAD(&h->loh_lru);
INIT_LIST_HEAD(&h->loh_layers);
lu_ref_init(&h->loh_reference);
return 0;
}
void lu_object_header_fini(struct lu_object_header *h)
{
LASSERT(list_empty(&h->loh_layers));
LASSERT(list_empty(&h->loh_lru));
LASSERT(hlist_unhashed(&h->loh_hash));
lu_ref_fini(&h->loh_reference);
}
struct lu_object *lu_object_locate(struct lu_object_header *h,
const struct lu_device_type *dtype)
{
struct lu_object *o;
list_for_each_entry(o, &h->loh_layers, lo_linkage) {
if (o->lo_dev->ld_type == dtype)
return o;
}
return NULL;
}
void lu_stack_fini(const struct lu_env *env, struct lu_device *top)
{
struct lu_site *site = top->ld_site;
struct lu_device *scan;
struct lu_device *next;
lu_site_purge(env, site, ~0);
for (scan = top; scan != NULL; scan = next) {
next = scan->ld_type->ldt_ops->ldto_device_fini(env, scan);
lu_ref_del(&scan->ld_reference, "lu-stack", &lu_site_init);
lu_device_put(scan);
}
lu_site_purge(env, site, ~0);
for (scan = top; scan != NULL; scan = next) {
const struct lu_device_type *ldt = scan->ld_type;
struct obd_type *type;
next = ldt->ldt_ops->ldto_device_free(env, scan);
type = ldt->ldt_obd_type;
if (type != NULL) {
type->typ_refcnt--;
class_put_type(type);
}
}
}
int lu_context_key_register(struct lu_context_key *key)
{
int result;
int i;
LASSERT(key->lct_init != NULL);
LASSERT(key->lct_fini != NULL);
LASSERT(key->lct_tags != 0);
result = -ENFILE;
spin_lock(&lu_keys_guard);
for (i = 0; i < ARRAY_SIZE(lu_keys); ++i) {
if (lu_keys[i] == NULL) {
key->lct_index = i;
atomic_set(&key->lct_used, 1);
lu_keys[i] = key;
lu_ref_init(&key->lct_reference);
result = 0;
++key_set_version;
break;
}
}
spin_unlock(&lu_keys_guard);
return result;
}
static void key_fini(struct lu_context *ctx, int index)
{
if (ctx->lc_value != NULL && ctx->lc_value[index] != NULL) {
struct lu_context_key *key;
key = lu_keys[index];
LASSERT(key != NULL);
LASSERT(key->lct_fini != NULL);
LASSERT(atomic_read(&key->lct_used) > 1);
key->lct_fini(ctx, key, ctx->lc_value[index]);
lu_ref_del(&key->lct_reference, "ctx", ctx);
atomic_dec(&key->lct_used);
if ((ctx->lc_tags & LCT_NOREF) == 0) {
#ifdef CONFIG_MODULE_UNLOAD
LINVRNT(module_refcount(key->lct_owner) > 0);
#endif
module_put(key->lct_owner);
}
ctx->lc_value[index] = NULL;
}
}
void lu_context_key_degister(struct lu_context_key *key)
{
LASSERT(atomic_read(&key->lct_used) >= 1);
LINVRNT(0 <= key->lct_index && key->lct_index < ARRAY_SIZE(lu_keys));
lu_context_key_quiesce(key);
++key_set_version;
spin_lock(&lu_keys_guard);
key_fini(&lu_shrink_env.le_ctx, key->lct_index);
if (lu_keys[key->lct_index]) {
lu_keys[key->lct_index] = NULL;
lu_ref_fini(&key->lct_reference);
}
spin_unlock(&lu_keys_guard);
LASSERTF(atomic_read(&key->lct_used) == 1,
"key has instances: %d\n",
atomic_read(&key->lct_used));
}
int lu_context_key_register_many(struct lu_context_key *k, ...)
{
struct lu_context_key *key = k;
va_list args;
int result;
va_start(args, k);
do {
result = lu_context_key_register(key);
if (result)
break;
key = va_arg(args, struct lu_context_key *);
} while (key != NULL);
va_end(args);
if (result != 0) {
va_start(args, k);
while (k != key) {
lu_context_key_degister(k);
k = va_arg(args, struct lu_context_key *);
}
va_end(args);
}
return result;
}
void lu_context_key_degister_many(struct lu_context_key *k, ...)
{
va_list args;
va_start(args, k);
do {
lu_context_key_degister(k);
k = va_arg(args, struct lu_context_key*);
} while (k != NULL);
va_end(args);
}
void lu_context_key_revive_many(struct lu_context_key *k, ...)
{
va_list args;
va_start(args, k);
do {
lu_context_key_revive(k);
k = va_arg(args, struct lu_context_key*);
} while (k != NULL);
va_end(args);
}
void lu_context_key_quiesce_many(struct lu_context_key *k, ...)
{
va_list args;
va_start(args, k);
do {
lu_context_key_quiesce(k);
k = va_arg(args, struct lu_context_key*);
} while (k != NULL);
va_end(args);
}
void *lu_context_key_get(const struct lu_context *ctx,
const struct lu_context_key *key)
{
LINVRNT(ctx->lc_state == LCS_ENTERED);
LINVRNT(0 <= key->lct_index && key->lct_index < ARRAY_SIZE(lu_keys));
LASSERT(lu_keys[key->lct_index] == key);
return ctx->lc_value[key->lct_index];
}
void lu_context_key_quiesce(struct lu_context_key *key)
{
struct lu_context *ctx;
if (!(key->lct_tags & LCT_QUIESCENT)) {
key->lct_tags |= LCT_QUIESCENT;
spin_lock(&lu_keys_guard);
list_for_each_entry(ctx, &lu_context_remembered,
lc_remember)
key_fini(ctx, key->lct_index);
spin_unlock(&lu_keys_guard);
++key_set_version;
}
}
void lu_context_key_revive(struct lu_context_key *key)
{
key->lct_tags &= ~LCT_QUIESCENT;
++key_set_version;
}
static void keys_fini(struct lu_context *ctx)
{
int i;
if (ctx->lc_value == NULL)
return;
for (i = 0; i < ARRAY_SIZE(lu_keys); ++i)
key_fini(ctx, i);
OBD_FREE(ctx->lc_value, ARRAY_SIZE(lu_keys) * sizeof(ctx->lc_value[0]));
ctx->lc_value = NULL;
}
static int keys_fill(struct lu_context *ctx)
{
int i;
LINVRNT(ctx->lc_value != NULL);
for (i = 0; i < ARRAY_SIZE(lu_keys); ++i) {
struct lu_context_key *key;
key = lu_keys[i];
if (ctx->lc_value[i] == NULL && key != NULL &&
(key->lct_tags & ctx->lc_tags) &&
!(key->lct_tags & LCT_QUIESCENT)) {
void *value;
LINVRNT(key->lct_init != NULL);
LINVRNT(key->lct_index == i);
value = key->lct_init(ctx, key);
if (unlikely(IS_ERR(value)))
return PTR_ERR(value);
if (!(ctx->lc_tags & LCT_NOREF))
try_module_get(key->lct_owner);
lu_ref_add_atomic(&key->lct_reference, "ctx", ctx);
atomic_inc(&key->lct_used);
ctx->lc_value[i] = value;
if (key->lct_exit != NULL)
ctx->lc_tags |= LCT_HAS_EXIT;
}
ctx->lc_version = key_set_version;
}
return 0;
}
static int keys_init(struct lu_context *ctx)
{
OBD_ALLOC(ctx->lc_value,
ARRAY_SIZE(lu_keys) * sizeof(ctx->lc_value[0]));
if (likely(ctx->lc_value != NULL))
return keys_fill(ctx);
return -ENOMEM;
}
int lu_context_init(struct lu_context *ctx, __u32 tags)
{
int rc;
memset(ctx, 0, sizeof(*ctx));
ctx->lc_state = LCS_INITIALIZED;
ctx->lc_tags = tags;
if (tags & LCT_REMEMBER) {
spin_lock(&lu_keys_guard);
list_add(&ctx->lc_remember, &lu_context_remembered);
spin_unlock(&lu_keys_guard);
} else {
INIT_LIST_HEAD(&ctx->lc_remember);
}
rc = keys_init(ctx);
if (rc != 0)
lu_context_fini(ctx);
return rc;
}
void lu_context_fini(struct lu_context *ctx)
{
LINVRNT(ctx->lc_state == LCS_INITIALIZED || ctx->lc_state == LCS_LEFT);
ctx->lc_state = LCS_FINALIZED;
if ((ctx->lc_tags & LCT_REMEMBER) == 0) {
LASSERT(list_empty(&ctx->lc_remember));
keys_fini(ctx);
} else {
spin_lock(&lu_keys_guard);
keys_fini(ctx);
list_del_init(&ctx->lc_remember);
spin_unlock(&lu_keys_guard);
}
}
void lu_context_enter(struct lu_context *ctx)
{
LINVRNT(ctx->lc_state == LCS_INITIALIZED || ctx->lc_state == LCS_LEFT);
ctx->lc_state = LCS_ENTERED;
}
void lu_context_exit(struct lu_context *ctx)
{
int i;
LINVRNT(ctx->lc_state == LCS_ENTERED);
ctx->lc_state = LCS_LEFT;
if (ctx->lc_tags & LCT_HAS_EXIT && ctx->lc_value != NULL) {
for (i = 0; i < ARRAY_SIZE(lu_keys); ++i) {
if (ctx->lc_value[i] != NULL) {
struct lu_context_key *key;
key = lu_keys[i];
LASSERT(key != NULL);
if (key->lct_exit != NULL)
key->lct_exit(ctx,
key, ctx->lc_value[i]);
}
}
}
}
int lu_context_refill(struct lu_context *ctx)
{
return likely(ctx->lc_version == key_set_version) ? 0 : keys_fill(ctx);
}
void lu_context_tags_update(__u32 tags)
{
spin_lock(&lu_keys_guard);
lu_context_tags_default |= tags;
key_set_version++;
spin_unlock(&lu_keys_guard);
}
void lu_context_tags_clear(__u32 tags)
{
spin_lock(&lu_keys_guard);
lu_context_tags_default &= ~tags;
key_set_version++;
spin_unlock(&lu_keys_guard);
}
void lu_session_tags_update(__u32 tags)
{
spin_lock(&lu_keys_guard);
lu_session_tags_default |= tags;
key_set_version++;
spin_unlock(&lu_keys_guard);
}
void lu_session_tags_clear(__u32 tags)
{
spin_lock(&lu_keys_guard);
lu_session_tags_default &= ~tags;
key_set_version++;
spin_unlock(&lu_keys_guard);
}
int lu_env_init(struct lu_env *env, __u32 tags)
{
int result;
env->le_ses = NULL;
result = lu_context_init(&env->le_ctx, tags);
if (likely(result == 0))
lu_context_enter(&env->le_ctx);
return result;
}
void lu_env_fini(struct lu_env *env)
{
lu_context_exit(&env->le_ctx);
lu_context_fini(&env->le_ctx);
env->le_ses = NULL;
}
int lu_env_refill(struct lu_env *env)
{
int result;
result = lu_context_refill(&env->le_ctx);
if (result == 0 && env->le_ses != NULL)
result = lu_context_refill(env->le_ses);
return result;
}
int lu_env_refill_by_tags(struct lu_env *env, __u32 ctags,
__u32 stags)
{
int result;
if ((env->le_ctx.lc_tags & ctags) != ctags) {
env->le_ctx.lc_version = 0;
env->le_ctx.lc_tags |= ctags;
}
if (env->le_ses && (env->le_ses->lc_tags & stags) != stags) {
env->le_ses->lc_version = 0;
env->le_ses->lc_tags |= stags;
}
result = lu_env_refill(env);
return result;
}
static void lu_site_stats_get(struct cfs_hash *hs,
lu_site_stats_t *stats, int populated)
{
struct cfs_hash_bd bd;
int i;
cfs_hash_for_each_bucket(hs, &bd, i) {
struct lu_site_bkt_data *bkt = cfs_hash_bd_extra_get(hs, &bd);
struct hlist_head *hhead;
cfs_hash_bd_lock(hs, &bd, 1);
stats->lss_busy += bkt->lsb_busy;
stats->lss_total += cfs_hash_bd_count_get(&bd);
stats->lss_max_search = max((int)stats->lss_max_search,
cfs_hash_bd_depmax_get(&bd));
if (!populated) {
cfs_hash_bd_unlock(hs, &bd, 1);
continue;
}
cfs_hash_bd_for_each_hlist(hs, &bd, hhead) {
if (!hlist_empty(hhead))
stats->lss_populated++;
}
cfs_hash_bd_unlock(hs, &bd, 1);
}
}
static unsigned long lu_cache_shrink_count(struct shrinker *sk,
struct shrink_control *sc)
{
lu_site_stats_t stats;
struct lu_site *s;
struct lu_site *tmp;
unsigned long cached = 0;
if (!(sc->gfp_mask & __GFP_FS))
return 0;
mutex_lock(&lu_sites_guard);
list_for_each_entry_safe(s, tmp, &lu_sites, ls_linkage) {
memset(&stats, 0, sizeof(stats));
lu_site_stats_get(s->ls_obj_hash, &stats, 0);
cached += stats.lss_total - stats.lss_busy;
}
mutex_unlock(&lu_sites_guard);
cached = (cached / 100) * sysctl_vfs_cache_pressure;
CDEBUG(D_INODE, "%ld objects cached\n", cached);
return cached;
}
static unsigned long lu_cache_shrink_scan(struct shrinker *sk,
struct shrink_control *sc)
{
struct lu_site *s;
struct lu_site *tmp;
unsigned long remain = sc->nr_to_scan, freed = 0;
LIST_HEAD(splice);
if (!(sc->gfp_mask & __GFP_FS))
return SHRINK_STOP;
mutex_lock(&lu_sites_guard);
list_for_each_entry_safe(s, tmp, &lu_sites, ls_linkage) {
freed = lu_site_purge(&lu_shrink_env, s, remain);
remain -= freed;
list_move_tail(&s->ls_linkage, &splice);
}
list_splice(&splice, lu_sites.prev);
mutex_unlock(&lu_sites_guard);
return sc->nr_to_scan - remain;
}
int lu_printk_printer(const struct lu_env *env,
void *unused, const char *format, ...)
{
va_list args;
va_start(args, format);
vprintk(format, args);
va_end(args);
return 0;
}
int lu_global_init(void)
{
int result;
CDEBUG(D_INFO, "Lustre LU module (%p).\n", &lu_keys);
result = lu_ref_global_init();
if (result != 0)
return result;
LU_CONTEXT_KEY_INIT(&lu_global_key);
result = lu_context_key_register(&lu_global_key);
if (result != 0)
return result;
mutex_lock(&lu_sites_guard);
result = lu_env_init(&lu_shrink_env, LCT_SHRINKER);
mutex_unlock(&lu_sites_guard);
if (result != 0)
return result;
register_shrinker(&lu_site_shrinker);
return result;
}
void lu_global_fini(void)
{
unregister_shrinker(&lu_site_shrinker);
lu_context_key_degister(&lu_global_key);
mutex_lock(&lu_sites_guard);
lu_env_fini(&lu_shrink_env);
mutex_unlock(&lu_sites_guard);
lu_ref_global_fini();
}
static __u32 ls_stats_read(struct lprocfs_stats *stats, int idx)
{
#ifdef LPROCFS
struct lprocfs_counter ret;
lprocfs_stats_collect(stats, idx, &ret);
return (__u32)ret.lc_count;
#else
return 0;
#endif
}
int lu_site_stats_print(const struct lu_site *s, struct seq_file *m)
{
lu_site_stats_t stats;
memset(&stats, 0, sizeof(stats));
lu_site_stats_get(s->ls_obj_hash, &stats, 1);
return seq_printf(m, "%d/%d %d/%d %d %d %d %d %d %d %d\n",
stats.lss_busy,
stats.lss_total,
stats.lss_populated,
CFS_HASH_NHLIST(s->ls_obj_hash),
stats.lss_max_search,
ls_stats_read(s->ls_stats, LU_SS_CREATED),
ls_stats_read(s->ls_stats, LU_SS_CACHE_HIT),
ls_stats_read(s->ls_stats, LU_SS_CACHE_MISS),
ls_stats_read(s->ls_stats, LU_SS_CACHE_RACE),
ls_stats_read(s->ls_stats, LU_SS_CACHE_DEATH_RACE),
ls_stats_read(s->ls_stats, LU_SS_LRU_PURGED));
}
int lu_kmem_init(struct lu_kmem_descr *caches)
{
int result;
struct lu_kmem_descr *iter = caches;
for (result = 0; iter->ckd_cache != NULL; ++iter) {
*iter->ckd_cache = kmem_cache_create(iter->ckd_name,
iter->ckd_size,
0, 0, NULL);
if (*iter->ckd_cache == NULL) {
result = -ENOMEM;
lu_kmem_fini(caches);
break;
}
}
return result;
}
void lu_kmem_fini(struct lu_kmem_descr *caches)
{
for (; caches->ckd_cache != NULL; ++caches) {
if (*caches->ckd_cache != NULL) {
kmem_cache_destroy(*caches->ckd_cache);
*caches->ckd_cache = NULL;
}
}
}
void lu_object_assign_fid(const struct lu_env *env, struct lu_object *o,
const struct lu_fid *fid)
{
struct lu_site *s = o->lo_dev->ld_site;
struct lu_fid *old = &o->lo_header->loh_fid;
struct lu_site_bkt_data *bkt;
struct lu_object *shadow;
wait_queue_t waiter;
struct cfs_hash *hs;
struct cfs_hash_bd bd;
__u64 version = 0;
LASSERT(fid_is_zero(old));
hs = s->ls_obj_hash;
cfs_hash_bd_get_and_lock(hs, (void *)fid, &bd, 1);
shadow = htable_lookup(s, &bd, fid, &waiter, &version);
LASSERT(IS_ERR(shadow) && PTR_ERR(shadow) == -ENOENT);
*old = *fid;
bkt = cfs_hash_bd_extra_get(hs, &bd);
cfs_hash_bd_add_locked(hs, &bd, &o->lo_header->loh_hash);
bkt->lsb_busy++;
cfs_hash_bd_unlock(hs, &bd, 1);
}
struct lu_object *lu_object_anon(const struct lu_env *env,
struct lu_device *dev,
const struct lu_object_conf *conf)
{
struct lu_fid fid;
struct lu_object *o;
fid_zero(&fid);
o = lu_object_alloc(env, dev, &fid, conf);
return o;
}
void lu_buf_free(struct lu_buf *buf)
{
LASSERT(buf);
if (buf->lb_buf) {
LASSERT(buf->lb_len > 0);
OBD_FREE_LARGE(buf->lb_buf, buf->lb_len);
buf->lb_buf = NULL;
buf->lb_len = 0;
}
}
void lu_buf_alloc(struct lu_buf *buf, int size)
{
LASSERT(buf);
LASSERT(buf->lb_buf == NULL);
LASSERT(buf->lb_len == 0);
OBD_ALLOC_LARGE(buf->lb_buf, size);
if (likely(buf->lb_buf))
buf->lb_len = size;
}
void lu_buf_realloc(struct lu_buf *buf, int size)
{
lu_buf_free(buf);
lu_buf_alloc(buf, size);
}
struct lu_buf *lu_buf_check_and_alloc(struct lu_buf *buf, int len)
{
if (buf->lb_buf == NULL && buf->lb_len == 0)
lu_buf_alloc(buf, len);
if ((len > buf->lb_len) && (buf->lb_buf != NULL))
lu_buf_realloc(buf, len);
return buf;
}
int lu_buf_check_and_grow(struct lu_buf *buf, int len)
{
char *ptr;
if (len <= buf->lb_len)
return 0;
OBD_ALLOC_LARGE(ptr, len);
if (ptr == NULL)
return -ENOMEM;
if (buf->lb_buf != NULL) {
memcpy(ptr, buf->lb_buf, buf->lb_len);
OBD_FREE_LARGE(buf->lb_buf, buf->lb_len);
}
buf->lb_buf = ptr;
buf->lb_len = len;
return 0;
}
