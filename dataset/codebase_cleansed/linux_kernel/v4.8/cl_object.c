int cl_object_header_init(struct cl_object_header *h)
{
int result;
result = lu_object_header_init(&h->coh_lu);
if (result == 0) {
spin_lock_init(&h->coh_attr_guard);
lockdep_set_class(&h->coh_attr_guard, &cl_attr_guard_class);
h->coh_page_bufsize = 0;
}
return result;
}
struct cl_object *cl_object_find(const struct lu_env *env,
struct cl_device *cd, const struct lu_fid *fid,
const struct cl_object_conf *c)
{
might_sleep();
return lu2cl(lu_object_find_slice(env, cl2lu_dev(cd), fid, &c->coc_lu));
}
void cl_object_put(const struct lu_env *env, struct cl_object *o)
{
lu_object_put(env, &o->co_lu);
}
void cl_object_get(struct cl_object *o)
{
lu_object_get(&o->co_lu);
}
struct cl_object *cl_object_top(struct cl_object *o)
{
struct cl_object_header *hdr = cl_object_header(o);
struct cl_object *top;
while (hdr->coh_parent)
hdr = hdr->coh_parent;
top = lu2cl(lu_object_top(&hdr->coh_lu));
CDEBUG(D_TRACE, "%p -> %p\n", o, top);
return top;
}
static spinlock_t *cl_object_attr_guard(struct cl_object *o)
{
return &cl_object_header(cl_object_top(o))->coh_attr_guard;
}
void cl_object_attr_lock(struct cl_object *o)
__acquires(cl_object_attr_guard(o)
void cl_object_attr_unlock(struct cl_object *o)
__releases(cl_object_attr_guard(o)
int cl_object_attr_get(const struct lu_env *env, struct cl_object *obj,
struct cl_attr *attr)
{
struct lu_object_header *top;
int result;
assert_spin_locked(cl_object_attr_guard(obj));
top = obj->co_lu.lo_header;
result = 0;
list_for_each_entry(obj, &top->loh_layers, co_lu.lo_linkage) {
if (obj->co_ops->coo_attr_get) {
result = obj->co_ops->coo_attr_get(env, obj, attr);
if (result != 0) {
if (result > 0)
result = 0;
break;
}
}
}
return result;
}
int cl_object_attr_set(const struct lu_env *env, struct cl_object *obj,
const struct cl_attr *attr, unsigned v)
{
struct lu_object_header *top;
int result;
assert_spin_locked(cl_object_attr_guard(obj));
top = obj->co_lu.lo_header;
result = 0;
list_for_each_entry_reverse(obj, &top->loh_layers, co_lu.lo_linkage) {
if (obj->co_ops->coo_attr_set) {
result = obj->co_ops->coo_attr_set(env, obj, attr, v);
if (result != 0) {
if (result > 0)
result = 0;
break;
}
}
}
return result;
}
int cl_object_glimpse(const struct lu_env *env, struct cl_object *obj,
struct ost_lvb *lvb)
{
struct lu_object_header *top;
int result;
top = obj->co_lu.lo_header;
result = 0;
list_for_each_entry_reverse(obj, &top->loh_layers, co_lu.lo_linkage) {
if (obj->co_ops->coo_glimpse) {
result = obj->co_ops->coo_glimpse(env, obj, lvb);
if (result != 0)
break;
}
}
LU_OBJECT_HEADER(D_DLMTRACE, env, lu_object_top(top),
"size: %llu mtime: %llu atime: %llu ctime: %llu blocks: %llu\n",
lvb->lvb_size, lvb->lvb_mtime, lvb->lvb_atime,
lvb->lvb_ctime, lvb->lvb_blocks);
return result;
}
int cl_conf_set(const struct lu_env *env, struct cl_object *obj,
const struct cl_object_conf *conf)
{
struct lu_object_header *top;
int result;
top = obj->co_lu.lo_header;
result = 0;
list_for_each_entry(obj, &top->loh_layers, co_lu.lo_linkage) {
if (obj->co_ops->coo_conf_set) {
result = obj->co_ops->coo_conf_set(env, obj, conf);
if (result != 0)
break;
}
}
return result;
}
int cl_object_prune(const struct lu_env *env, struct cl_object *obj)
{
struct lu_object_header *top;
struct cl_object *o;
int result;
top = obj->co_lu.lo_header;
result = 0;
list_for_each_entry(o, &top->loh_layers, co_lu.lo_linkage) {
if (o->co_ops->coo_prune) {
result = o->co_ops->coo_prune(env, o);
if (result != 0)
break;
}
}
return result;
}
void cl_object_kill(const struct lu_env *env, struct cl_object *obj)
{
struct cl_object_header *hdr = cl_object_header(obj);
set_bit(LU_OBJECT_HEARD_BANSHEE, &hdr->coh_lu.loh_flags);
}
void cache_stats_init(struct cache_stats *cs, const char *name)
{
int i;
cs->cs_name = name;
for (i = 0; i < CS_NR; i++)
atomic_set(&cs->cs_stats[i], 0);
}
static int cache_stats_print(const struct cache_stats *cs,
struct seq_file *m, int h)
{
int i;
if (h) {
const char *names[CS_NR] = CS_NAMES;
seq_printf(m, "%6s", " ");
for (i = 0; i < CS_NR; i++)
seq_printf(m, "%8s", names[i]);
seq_printf(m, "\n");
}
seq_printf(m, "%5.5s:", cs->cs_name);
for (i = 0; i < CS_NR; i++)
seq_printf(m, "%8u", atomic_read(&cs->cs_stats[i]));
return 0;
}
int cl_site_init(struct cl_site *s, struct cl_device *d)
{
int i;
int result;
result = lu_site_init(&s->cs_lu, &d->cd_lu_dev);
if (result == 0) {
cache_stats_init(&s->cs_pages, "pages");
for (i = 0; i < ARRAY_SIZE(s->cs_pages_state); ++i)
atomic_set(&s->cs_pages_state[0], 0);
cl_env_percpu_refill();
}
return result;
}
void cl_site_fini(struct cl_site *s)
{
lu_site_fini(&s->cs_lu);
}
int cl_site_stats_print(const struct cl_site *site, struct seq_file *m)
{
int i;
static const char *pstate[] = {
[CPS_CACHED] = "c",
[CPS_OWNED] = "o",
[CPS_PAGEOUT] = "w",
[CPS_PAGEIN] = "r",
[CPS_FREEING] = "f"
};
lu_site_stats_print(&site->cs_lu, m);
cache_stats_print(&site->cs_pages, m, 1);
seq_printf(m, " [");
for (i = 0; i < ARRAY_SIZE(site->cs_pages_state); ++i)
seq_printf(m, "%s: %u ", pstate[i],
atomic_read(&site->cs_pages_state[i]));
seq_printf(m, "]\n");
cache_stats_print(&cl_env_stats, m, 0);
seq_printf(m, "\n");
return 0;
}
static void cl_env_init0(struct cl_env *cle, void *debug)
{
LASSERT(cle->ce_ref == 0);
LASSERT(cle->ce_magic == &cl_env_init0);
LASSERT(!cle->ce_debug && !cle->ce_owner);
cle->ce_ref = 1;
cle->ce_debug = debug;
CL_ENV_INC(busy);
}
static unsigned cl_env_hops_hash(struct cfs_hash *lh,
const void *key, unsigned mask)
{
#if BITS_PER_LONG == 64
return cfs_hash_u64_hash((__u64)key, mask);
#else
return cfs_hash_u32_hash((__u32)key, mask);
#endif
}
static void *cl_env_hops_obj(struct hlist_node *hn)
{
struct cl_env *cle = hlist_entry(hn, struct cl_env, ce_node);
LASSERT(cle->ce_magic == &cl_env_init0);
return (void *)cle;
}
static int cl_env_hops_keycmp(const void *key, struct hlist_node *hn)
{
struct cl_env *cle = cl_env_hops_obj(hn);
LASSERT(cle->ce_owner);
return (key == cle->ce_owner);
}
static void cl_env_hops_noop(struct cfs_hash *hs, struct hlist_node *hn)
{
struct cl_env *cle = hlist_entry(hn, struct cl_env, ce_node);
LASSERT(cle->ce_magic == &cl_env_init0);
}
static inline struct cl_env *cl_env_fetch(void)
{
struct cl_env *cle;
cle = cfs_hash_lookup(cl_env_hash, (void *)(long)current->pid);
LASSERT(ergo(cle, cle->ce_magic == &cl_env_init0));
return cle;
}
static inline void cl_env_attach(struct cl_env *cle)
{
if (cle) {
int rc;
LASSERT(!cle->ce_owner);
cle->ce_owner = (void *)(long)current->pid;
rc = cfs_hash_add_unique(cl_env_hash, cle->ce_owner,
&cle->ce_node);
LASSERT(rc == 0);
}
}
static inline void cl_env_do_detach(struct cl_env *cle)
{
void *cookie;
LASSERT(cle->ce_owner == (void *)(long)current->pid);
cookie = cfs_hash_del(cl_env_hash, cle->ce_owner,
&cle->ce_node);
LASSERT(cookie == cle);
cle->ce_owner = NULL;
}
static int cl_env_store_init(void)
{
cl_env_hash = cfs_hash_create("cl_env",
HASH_CL_ENV_BITS, HASH_CL_ENV_BITS,
HASH_CL_ENV_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&cl_env_hops,
CFS_HASH_RW_BKTLOCK);
return cl_env_hash ? 0 : -ENOMEM;
}
static void cl_env_store_fini(void)
{
cfs_hash_putref(cl_env_hash);
}
static inline struct cl_env *cl_env_detach(struct cl_env *cle)
{
if (!cle)
cle = cl_env_fetch();
if (cle && cle->ce_owner)
cl_env_do_detach(cle);
return cle;
}
static struct lu_env *cl_env_new(__u32 ctx_tags, __u32 ses_tags, void *debug)
{
struct lu_env *env;
struct cl_env *cle;
cle = kmem_cache_zalloc(cl_env_kmem, GFP_NOFS);
if (cle) {
int rc;
INIT_LIST_HEAD(&cle->ce_linkage);
cle->ce_magic = &cl_env_init0;
env = &cle->ce_lu;
rc = lu_env_init(env, ctx_tags | LCT_CL_THREAD);
if (rc == 0) {
rc = lu_context_init(&cle->ce_ses,
ses_tags | LCT_SESSION);
if (rc == 0) {
lu_context_enter(&cle->ce_ses);
env->le_ses = &cle->ce_ses;
cl_env_init0(cle, debug);
} else {
lu_env_fini(env);
}
}
if (rc != 0) {
kmem_cache_free(cl_env_kmem, cle);
env = ERR_PTR(rc);
} else {
CL_ENV_INC(create);
CL_ENV_INC(total);
}
} else {
env = ERR_PTR(-ENOMEM);
}
return env;
}
static void cl_env_fini(struct cl_env *cle)
{
CL_ENV_DEC(total);
lu_context_fini(&cle->ce_lu.le_ctx);
lu_context_fini(&cle->ce_ses);
kmem_cache_free(cl_env_kmem, cle);
}
static struct lu_env *cl_env_obtain(void *debug)
{
struct cl_env *cle;
struct lu_env *env;
spin_lock(&cl_envs_guard);
LASSERT(equi(cl_envs_cached_nr == 0, list_empty(&cl_envs)));
if (cl_envs_cached_nr > 0) {
int rc;
cle = container_of(cl_envs.next, struct cl_env, ce_linkage);
list_del_init(&cle->ce_linkage);
cl_envs_cached_nr--;
spin_unlock(&cl_envs_guard);
env = &cle->ce_lu;
rc = lu_env_refill(env);
if (rc == 0) {
cl_env_init0(cle, debug);
lu_context_enter(&env->le_ctx);
lu_context_enter(&cle->ce_ses);
} else {
cl_env_fini(cle);
env = ERR_PTR(rc);
}
} else {
spin_unlock(&cl_envs_guard);
env = cl_env_new(lu_context_tags_default,
lu_session_tags_default, debug);
}
return env;
}
static inline struct cl_env *cl_env_container(struct lu_env *env)
{
return container_of(env, struct cl_env, ce_lu);
}
static struct lu_env *cl_env_peek(int *refcheck)
{
struct lu_env *env;
struct cl_env *cle;
CL_ENV_INC(lookup);
CLASSERT(offsetof(struct cl_env, ce_magic) == 0);
env = NULL;
cle = cl_env_fetch();
if (cle) {
CL_ENV_INC(hit);
env = &cle->ce_lu;
*refcheck = ++cle->ce_ref;
}
CDEBUG(D_OTHER, "%d@%p\n", cle ? cle->ce_ref : 0, cle);
return env;
}
struct lu_env *cl_env_get(int *refcheck)
{
struct lu_env *env;
env = cl_env_peek(refcheck);
if (!env) {
env = cl_env_obtain(__builtin_return_address(0));
if (!IS_ERR(env)) {
struct cl_env *cle;
cle = cl_env_container(env);
cl_env_attach(cle);
*refcheck = cle->ce_ref;
CDEBUG(D_OTHER, "%d@%p\n", cle->ce_ref, cle);
}
}
return env;
}
struct lu_env *cl_env_alloc(int *refcheck, __u32 tags)
{
struct lu_env *env;
LASSERT(!cl_env_peek(refcheck));
env = cl_env_new(tags, tags, __builtin_return_address(0));
if (!IS_ERR(env)) {
struct cl_env *cle;
cle = cl_env_container(env);
*refcheck = cle->ce_ref;
CDEBUG(D_OTHER, "%d@%p\n", cle->ce_ref, cle);
}
return env;
}
static void cl_env_exit(struct cl_env *cle)
{
LASSERT(!cle->ce_owner);
lu_context_exit(&cle->ce_lu.le_ctx);
lu_context_exit(&cle->ce_ses);
}
unsigned int cl_env_cache_purge(unsigned int nr)
{
struct cl_env *cle;
spin_lock(&cl_envs_guard);
for (; !list_empty(&cl_envs) && nr > 0; --nr) {
cle = container_of(cl_envs.next, struct cl_env, ce_linkage);
list_del_init(&cle->ce_linkage);
LASSERT(cl_envs_cached_nr > 0);
cl_envs_cached_nr--;
spin_unlock(&cl_envs_guard);
cl_env_fini(cle);
spin_lock(&cl_envs_guard);
}
LASSERT(equi(cl_envs_cached_nr == 0, list_empty(&cl_envs)));
spin_unlock(&cl_envs_guard);
return nr;
}
void cl_env_put(struct lu_env *env, int *refcheck)
{
struct cl_env *cle;
cle = cl_env_container(env);
LASSERT(cle->ce_ref > 0);
LASSERT(ergo(refcheck, cle->ce_ref == *refcheck));
CDEBUG(D_OTHER, "%d@%p\n", cle->ce_ref, cle);
if (--cle->ce_ref == 0) {
CL_ENV_DEC(busy);
cl_env_detach(cle);
cle->ce_debug = NULL;
cl_env_exit(cle);
if (cl_envs_cached_nr < cl_envs_cached_max &&
(env->le_ctx.lc_tags & ~LCT_HAS_EXIT) == LCT_CL_THREAD &&
(env->le_ses->lc_tags & ~LCT_HAS_EXIT) == LCT_SESSION) {
spin_lock(&cl_envs_guard);
list_add(&cle->ce_linkage, &cl_envs);
cl_envs_cached_nr++;
spin_unlock(&cl_envs_guard);
} else {
cl_env_fini(cle);
}
}
}
void *cl_env_reenter(void)
{
return cl_env_detach(NULL);
}
void cl_env_reexit(void *cookie)
{
cl_env_detach(NULL);
cl_env_attach(cookie);
}
void cl_env_implant(struct lu_env *env, int *refcheck)
{
struct cl_env *cle = cl_env_container(env);
LASSERT(cle->ce_ref > 0);
cl_env_attach(cle);
cl_env_get(refcheck);
CDEBUG(D_OTHER, "%d@%p\n", cle->ce_ref, cle);
}
void cl_env_unplant(struct lu_env *env, int *refcheck)
{
struct cl_env *cle = cl_env_container(env);
LASSERT(cle->ce_ref > 1);
CDEBUG(D_OTHER, "%d@%p\n", cle->ce_ref, cle);
cl_env_detach(cle);
cl_env_put(env, refcheck);
}
struct lu_env *cl_env_nested_get(struct cl_env_nest *nest)
{
struct lu_env *env;
nest->cen_cookie = NULL;
env = cl_env_peek(&nest->cen_refcheck);
if (env) {
if (!cl_io_is_going(env))
return env;
cl_env_put(env, &nest->cen_refcheck);
nest->cen_cookie = cl_env_reenter();
}
env = cl_env_get(&nest->cen_refcheck);
if (IS_ERR(env)) {
cl_env_reexit(nest->cen_cookie);
return env;
}
LASSERT(!cl_io_is_going(env));
return env;
}
void cl_env_nested_put(struct cl_env_nest *nest, struct lu_env *env)
{
cl_env_put(env, &nest->cen_refcheck);
cl_env_reexit(nest->cen_cookie);
}
void cl_lvb2attr(struct cl_attr *attr, const struct ost_lvb *lvb)
{
attr->cat_size = lvb->lvb_size;
attr->cat_mtime = lvb->lvb_mtime;
attr->cat_atime = lvb->lvb_atime;
attr->cat_ctime = lvb->lvb_ctime;
attr->cat_blocks = lvb->lvb_blocks;
}
static int cl_env_percpu_init(void)
{
struct cl_env *cle;
int tags = LCT_REMEMBER | LCT_NOREF;
int i, j;
int rc = 0;
for_each_possible_cpu(i) {
struct lu_env *env;
cle = &cl_env_percpu[i];
env = &cle->ce_lu;
INIT_LIST_HEAD(&cle->ce_linkage);
cle->ce_magic = &cl_env_init0;
rc = lu_env_init(env, LCT_CL_THREAD | tags);
if (rc == 0) {
rc = lu_context_init(&cle->ce_ses, LCT_SESSION | tags);
if (rc == 0) {
lu_context_enter(&cle->ce_ses);
env->le_ses = &cle->ce_ses;
} else {
lu_env_fini(env);
}
}
if (rc != 0)
break;
}
if (rc != 0) {
for (j = 0; j < i; j++) {
cle = &cl_env_percpu[i];
lu_context_exit(&cle->ce_ses);
lu_context_fini(&cle->ce_ses);
lu_env_fini(&cle->ce_lu);
}
}
return rc;
}
static void cl_env_percpu_fini(void)
{
int i;
for_each_possible_cpu(i) {
struct cl_env *cle = &cl_env_percpu[i];
lu_context_exit(&cle->ce_ses);
lu_context_fini(&cle->ce_ses);
lu_env_fini(&cle->ce_lu);
}
}
static void cl_env_percpu_refill(void)
{
int i;
for_each_possible_cpu(i)
lu_env_refill(&cl_env_percpu[i].ce_lu);
}
void cl_env_percpu_put(struct lu_env *env)
{
struct cl_env *cle;
int cpu;
cpu = smp_processor_id();
cle = cl_env_container(env);
LASSERT(cle == &cl_env_percpu[cpu]);
cle->ce_ref--;
LASSERT(cle->ce_ref == 0);
CL_ENV_DEC(busy);
cl_env_detach(cle);
cle->ce_debug = NULL;
put_cpu();
}
struct lu_env *cl_env_percpu_get(void)
{
struct cl_env *cle;
cle = &cl_env_percpu[get_cpu()];
cl_env_init0(cle, __builtin_return_address(0));
cl_env_attach(cle);
return &cle->ce_lu;
}
struct cl_device *cl_type_setup(const struct lu_env *env, struct lu_site *site,
struct lu_device_type *ldt,
struct lu_device *next)
{
const char *typename;
struct lu_device *d;
typename = ldt->ldt_name;
d = ldt->ldt_ops->ldto_device_alloc(env, ldt, NULL);
if (!IS_ERR(d)) {
int rc;
if (site)
d->ld_site = site;
rc = ldt->ldt_ops->ldto_device_init(env, d, typename, next);
if (rc == 0) {
lu_device_get(d);
lu_ref_add(&d->ld_reference,
"lu-stack", &lu_site_init);
} else {
ldt->ldt_ops->ldto_device_free(env, d);
CERROR("can't init device '%s', %d\n", typename, rc);
d = ERR_PTR(rc);
}
} else {
CERROR("Cannot allocate device: '%s'\n", typename);
}
return lu2cl_dev(d);
}
void cl_stack_fini(const struct lu_env *env, struct cl_device *cl)
{
lu_stack_fini(env, cl2lu_dev(cl));
}
struct cl_thread_info *cl_env_info(const struct lu_env *env)
{
return lu_context_key_get(&env->le_ctx, &cl_key);
}
static void *cl_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct cl_thread_info *info;
info = cl0_key_init(ctx, key);
if (!IS_ERR(info)) {
int i;
for (i = 0; i < ARRAY_SIZE(info->clt_counters); ++i)
lu_ref_init(&info->clt_counters[i].ctc_locks_locked);
}
return info;
}
static void cl_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct cl_thread_info *info;
int i;
info = data;
for (i = 0; i < ARRAY_SIZE(info->clt_counters); ++i)
lu_ref_fini(&info->clt_counters[i].ctc_locks_locked);
cl0_key_fini(ctx, key, data);
}
static void cl_key_exit(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct cl_thread_info *info = data;
int i;
for (i = 0; i < ARRAY_SIZE(info->clt_counters); ++i) {
LASSERT(info->clt_counters[i].ctc_nr_held == 0);
LASSERT(info->clt_counters[i].ctc_nr_used == 0);
LASSERT(info->clt_counters[i].ctc_nr_locks_acquired == 0);
LASSERT(info->clt_counters[i].ctc_nr_locks_locked == 0);
lu_ref_fini(&info->clt_counters[i].ctc_locks_locked);
lu_ref_init(&info->clt_counters[i].ctc_locks_locked);
}
}
int cl_global_init(void)
{
int result;
result = cl_env_store_init();
if (result)
return result;
result = lu_kmem_init(cl_object_caches);
if (result)
goto out_store;
LU_CONTEXT_KEY_INIT(&cl_key);
result = lu_context_key_register(&cl_key);
if (result)
goto out_kmem;
result = cl_env_percpu_init();
if (result)
goto out_context;
return 0;
out_context:
lu_context_key_degister(&cl_key);
out_kmem:
lu_kmem_fini(cl_object_caches);
out_store:
cl_env_store_fini();
return result;
}
void cl_global_fini(void)
{
cl_env_percpu_fini();
lu_context_key_degister(&cl_key);
lu_kmem_fini(cl_object_caches);
cl_env_store_fini();
}
