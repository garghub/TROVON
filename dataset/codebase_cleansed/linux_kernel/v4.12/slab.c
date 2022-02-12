static void kmem_cache_node_init(struct kmem_cache_node *parent)
{
INIT_LIST_HEAD(&parent->slabs_full);
INIT_LIST_HEAD(&parent->slabs_partial);
INIT_LIST_HEAD(&parent->slabs_free);
parent->total_slabs = 0;
parent->free_slabs = 0;
parent->shared = NULL;
parent->alien = NULL;
parent->colour_next = 0;
spin_lock_init(&parent->list_lock);
parent->free_objects = 0;
parent->free_touched = 0;
}
static int obj_offset(struct kmem_cache *cachep)
{
return cachep->obj_offset;
}
static unsigned long long *dbg_redzone1(struct kmem_cache *cachep, void *objp)
{
BUG_ON(!(cachep->flags & SLAB_RED_ZONE));
return (unsigned long long*) (objp + obj_offset(cachep) -
sizeof(unsigned long long));
}
static unsigned long long *dbg_redzone2(struct kmem_cache *cachep, void *objp)
{
BUG_ON(!(cachep->flags & SLAB_RED_ZONE));
if (cachep->flags & SLAB_STORE_USER)
return (unsigned long long *)(objp + cachep->size -
sizeof(unsigned long long) -
REDZONE_ALIGN);
return (unsigned long long *) (objp + cachep->size -
sizeof(unsigned long long));
}
static void **dbg_userword(struct kmem_cache *cachep, void *objp)
{
BUG_ON(!(cachep->flags & SLAB_STORE_USER));
return (void **)(objp + cachep->size - BYTES_PER_WORD);
}
static inline bool is_store_user_clean(struct kmem_cache *cachep)
{
return atomic_read(&cachep->store_user_clean) == 1;
}
static inline void set_store_user_clean(struct kmem_cache *cachep)
{
atomic_set(&cachep->store_user_clean, 1);
}
static inline void set_store_user_dirty(struct kmem_cache *cachep)
{
if (is_store_user_clean(cachep))
atomic_set(&cachep->store_user_clean, 0);
}
static inline void set_store_user_dirty(struct kmem_cache *cachep) {}
static inline struct kmem_cache *virt_to_cache(const void *obj)
{
struct page *page = virt_to_head_page(obj);
return page->slab_cache;
}
static inline void *index_to_obj(struct kmem_cache *cache, struct page *page,
unsigned int idx)
{
return page->s_mem + cache->size * idx;
}
static inline unsigned int obj_to_index(const struct kmem_cache *cache,
const struct page *page, void *obj)
{
u32 offset = (obj - page->s_mem);
return reciprocal_divide(offset, cache->reciprocal_buffer_size);
}
static inline struct array_cache *cpu_cache_get(struct kmem_cache *cachep)
{
return this_cpu_ptr(cachep->cpu_cache);
}
static unsigned int cache_estimate(unsigned long gfporder, size_t buffer_size,
unsigned long flags, size_t *left_over)
{
unsigned int num;
size_t slab_size = PAGE_SIZE << gfporder;
if (flags & (CFLGS_OBJFREELIST_SLAB | CFLGS_OFF_SLAB)) {
num = slab_size / buffer_size;
*left_over = slab_size % buffer_size;
} else {
num = slab_size / (buffer_size + sizeof(freelist_idx_t));
*left_over = slab_size %
(buffer_size + sizeof(freelist_idx_t));
}
return num;
}
static void __slab_error(const char *function, struct kmem_cache *cachep,
char *msg)
{
pr_err("slab error in %s(): cache `%s': %s\n",
function, cachep->name, msg);
dump_stack();
add_taint(TAINT_BAD_PAGE, LOCKDEP_NOW_UNRELIABLE);
}
static int __init noaliencache_setup(char *s)
{
use_alien_caches = 0;
return 1;
}
static int __init slab_max_order_setup(char *str)
{
get_option(&str, &slab_max_order);
slab_max_order = slab_max_order < 0 ? 0 :
min(slab_max_order, MAX_ORDER - 1);
slab_max_order_set = true;
return 1;
}
static void init_reap_node(int cpu)
{
per_cpu(slab_reap_node, cpu) = next_node_in(cpu_to_mem(cpu),
node_online_map);
}
static void next_reap_node(void)
{
int node = __this_cpu_read(slab_reap_node);
node = next_node_in(node, node_online_map);
__this_cpu_write(slab_reap_node, node);
}
static void start_cpu_timer(int cpu)
{
struct delayed_work *reap_work = &per_cpu(slab_reap_work, cpu);
if (reap_work->work.func == NULL) {
init_reap_node(cpu);
INIT_DEFERRABLE_WORK(reap_work, cache_reap);
schedule_delayed_work_on(cpu, reap_work,
__round_jiffies_relative(HZ, cpu));
}
}
static void init_arraycache(struct array_cache *ac, int limit, int batch)
{
kmemleak_no_scan(ac);
if (ac) {
ac->avail = 0;
ac->limit = limit;
ac->batchcount = batch;
ac->touched = 0;
}
}
static struct array_cache *alloc_arraycache(int node, int entries,
int batchcount, gfp_t gfp)
{
size_t memsize = sizeof(void *) * entries + sizeof(struct array_cache);
struct array_cache *ac = NULL;
ac = kmalloc_node(memsize, gfp, node);
init_arraycache(ac, entries, batchcount);
return ac;
}
static noinline void cache_free_pfmemalloc(struct kmem_cache *cachep,
struct page *page, void *objp)
{
struct kmem_cache_node *n;
int page_node;
LIST_HEAD(list);
page_node = page_to_nid(page);
n = get_node(cachep, page_node);
spin_lock(&n->list_lock);
free_block(cachep, &objp, 1, page_node, &list);
spin_unlock(&n->list_lock);
slabs_destroy(cachep, &list);
}
static int transfer_objects(struct array_cache *to,
struct array_cache *from, unsigned int max)
{
int nr = min3(from->avail, max, to->limit - to->avail);
if (!nr)
return 0;
memcpy(to->entry + to->avail, from->entry + from->avail -nr,
sizeof(void *) *nr);
from->avail -= nr;
to->avail += nr;
return nr;
}
static inline struct alien_cache **alloc_alien_cache(int node,
int limit, gfp_t gfp)
{
return NULL;
}
static inline void free_alien_cache(struct alien_cache **ac_ptr)
{
}
static inline int cache_free_alien(struct kmem_cache *cachep, void *objp)
{
return 0;
}
static inline void *alternate_node_alloc(struct kmem_cache *cachep,
gfp_t flags)
{
return NULL;
}
static inline void *____cache_alloc_node(struct kmem_cache *cachep,
gfp_t flags, int nodeid)
{
return NULL;
}
static inline gfp_t gfp_exact_node(gfp_t flags)
{
return flags & ~__GFP_NOFAIL;
}
static struct alien_cache *__alloc_alien_cache(int node, int entries,
int batch, gfp_t gfp)
{
size_t memsize = sizeof(void *) * entries + sizeof(struct alien_cache);
struct alien_cache *alc = NULL;
alc = kmalloc_node(memsize, gfp, node);
init_arraycache(&alc->ac, entries, batch);
spin_lock_init(&alc->lock);
return alc;
}
static struct alien_cache **alloc_alien_cache(int node, int limit, gfp_t gfp)
{
struct alien_cache **alc_ptr;
size_t memsize = sizeof(void *) * nr_node_ids;
int i;
if (limit > 1)
limit = 12;
alc_ptr = kzalloc_node(memsize, gfp, node);
if (!alc_ptr)
return NULL;
for_each_node(i) {
if (i == node || !node_online(i))
continue;
alc_ptr[i] = __alloc_alien_cache(node, limit, 0xbaadf00d, gfp);
if (!alc_ptr[i]) {
for (i--; i >= 0; i--)
kfree(alc_ptr[i]);
kfree(alc_ptr);
return NULL;
}
}
return alc_ptr;
}
static void free_alien_cache(struct alien_cache **alc_ptr)
{
int i;
if (!alc_ptr)
return;
for_each_node(i)
kfree(alc_ptr[i]);
kfree(alc_ptr);
}
static void __drain_alien_cache(struct kmem_cache *cachep,
struct array_cache *ac, int node,
struct list_head *list)
{
struct kmem_cache_node *n = get_node(cachep, node);
if (ac->avail) {
spin_lock(&n->list_lock);
if (n->shared)
transfer_objects(n->shared, ac, ac->limit);
free_block(cachep, ac->entry, ac->avail, node, list);
ac->avail = 0;
spin_unlock(&n->list_lock);
}
}
static void reap_alien(struct kmem_cache *cachep, struct kmem_cache_node *n)
{
int node = __this_cpu_read(slab_reap_node);
if (n->alien) {
struct alien_cache *alc = n->alien[node];
struct array_cache *ac;
if (alc) {
ac = &alc->ac;
if (ac->avail && spin_trylock_irq(&alc->lock)) {
LIST_HEAD(list);
__drain_alien_cache(cachep, ac, node, &list);
spin_unlock_irq(&alc->lock);
slabs_destroy(cachep, &list);
}
}
}
}
static void drain_alien_cache(struct kmem_cache *cachep,
struct alien_cache **alien)
{
int i = 0;
struct alien_cache *alc;
struct array_cache *ac;
unsigned long flags;
for_each_online_node(i) {
alc = alien[i];
if (alc) {
LIST_HEAD(list);
ac = &alc->ac;
spin_lock_irqsave(&alc->lock, flags);
__drain_alien_cache(cachep, ac, i, &list);
spin_unlock_irqrestore(&alc->lock, flags);
slabs_destroy(cachep, &list);
}
}
}
static int __cache_free_alien(struct kmem_cache *cachep, void *objp,
int node, int page_node)
{
struct kmem_cache_node *n;
struct alien_cache *alien = NULL;
struct array_cache *ac;
LIST_HEAD(list);
n = get_node(cachep, node);
STATS_INC_NODEFREES(cachep);
if (n->alien && n->alien[page_node]) {
alien = n->alien[page_node];
ac = &alien->ac;
spin_lock(&alien->lock);
if (unlikely(ac->avail == ac->limit)) {
STATS_INC_ACOVERFLOW(cachep);
__drain_alien_cache(cachep, ac, page_node, &list);
}
ac->entry[ac->avail++] = objp;
spin_unlock(&alien->lock);
slabs_destroy(cachep, &list);
} else {
n = get_node(cachep, page_node);
spin_lock(&n->list_lock);
free_block(cachep, &objp, 1, page_node, &list);
spin_unlock(&n->list_lock);
slabs_destroy(cachep, &list);
}
return 1;
}
static inline int cache_free_alien(struct kmem_cache *cachep, void *objp)
{
int page_node = page_to_nid(virt_to_page(objp));
int node = numa_mem_id();
if (likely(node == page_node))
return 0;
return __cache_free_alien(cachep, objp, node, page_node);
}
static inline gfp_t gfp_exact_node(gfp_t flags)
{
return (flags | __GFP_THISNODE | __GFP_NOWARN) & ~(__GFP_RECLAIM|__GFP_NOFAIL);
}
static int init_cache_node(struct kmem_cache *cachep, int node, gfp_t gfp)
{
struct kmem_cache_node *n;
n = get_node(cachep, node);
if (n) {
spin_lock_irq(&n->list_lock);
n->free_limit = (1 + nr_cpus_node(node)) * cachep->batchcount +
cachep->num;
spin_unlock_irq(&n->list_lock);
return 0;
}
n = kmalloc_node(sizeof(struct kmem_cache_node), gfp, node);
if (!n)
return -ENOMEM;
kmem_cache_node_init(n);
n->next_reap = jiffies + REAPTIMEOUT_NODE +
((unsigned long)cachep) % REAPTIMEOUT_NODE;
n->free_limit =
(1 + nr_cpus_node(node)) * cachep->batchcount + cachep->num;
cachep->node[node] = n;
return 0;
}
static int init_cache_node_node(int node)
{
int ret;
struct kmem_cache *cachep;
list_for_each_entry(cachep, &slab_caches, list) {
ret = init_cache_node(cachep, node, GFP_KERNEL);
if (ret)
return ret;
}
return 0;
}
static int setup_kmem_cache_node(struct kmem_cache *cachep,
int node, gfp_t gfp, bool force_change)
{
int ret = -ENOMEM;
struct kmem_cache_node *n;
struct array_cache *old_shared = NULL;
struct array_cache *new_shared = NULL;
struct alien_cache **new_alien = NULL;
LIST_HEAD(list);
if (use_alien_caches) {
new_alien = alloc_alien_cache(node, cachep->limit, gfp);
if (!new_alien)
goto fail;
}
if (cachep->shared) {
new_shared = alloc_arraycache(node,
cachep->shared * cachep->batchcount, 0xbaadf00d, gfp);
if (!new_shared)
goto fail;
}
ret = init_cache_node(cachep, node, gfp);
if (ret)
goto fail;
n = get_node(cachep, node);
spin_lock_irq(&n->list_lock);
if (n->shared && force_change) {
free_block(cachep, n->shared->entry,
n->shared->avail, node, &list);
n->shared->avail = 0;
}
if (!n->shared || force_change) {
old_shared = n->shared;
n->shared = new_shared;
new_shared = NULL;
}
if (!n->alien) {
n->alien = new_alien;
new_alien = NULL;
}
spin_unlock_irq(&n->list_lock);
slabs_destroy(cachep, &list);
if (old_shared && force_change)
synchronize_sched();
fail:
kfree(old_shared);
kfree(new_shared);
free_alien_cache(new_alien);
return ret;
}
static void cpuup_canceled(long cpu)
{
struct kmem_cache *cachep;
struct kmem_cache_node *n = NULL;
int node = cpu_to_mem(cpu);
const struct cpumask *mask = cpumask_of_node(node);
list_for_each_entry(cachep, &slab_caches, list) {
struct array_cache *nc;
struct array_cache *shared;
struct alien_cache **alien;
LIST_HEAD(list);
n = get_node(cachep, node);
if (!n)
continue;
spin_lock_irq(&n->list_lock);
n->free_limit -= cachep->batchcount;
nc = per_cpu_ptr(cachep->cpu_cache, cpu);
if (nc) {
free_block(cachep, nc->entry, nc->avail, node, &list);
nc->avail = 0;
}
if (!cpumask_empty(mask)) {
spin_unlock_irq(&n->list_lock);
goto free_slab;
}
shared = n->shared;
if (shared) {
free_block(cachep, shared->entry,
shared->avail, node, &list);
n->shared = NULL;
}
alien = n->alien;
n->alien = NULL;
spin_unlock_irq(&n->list_lock);
kfree(shared);
if (alien) {
drain_alien_cache(cachep, alien);
free_alien_cache(alien);
}
free_slab:
slabs_destroy(cachep, &list);
}
list_for_each_entry(cachep, &slab_caches, list) {
n = get_node(cachep, node);
if (!n)
continue;
drain_freelist(cachep, n, INT_MAX);
}
}
static int cpuup_prepare(long cpu)
{
struct kmem_cache *cachep;
int node = cpu_to_mem(cpu);
int err;
err = init_cache_node_node(node);
if (err < 0)
goto bad;
list_for_each_entry(cachep, &slab_caches, list) {
err = setup_kmem_cache_node(cachep, node, GFP_KERNEL, false);
if (err)
goto bad;
}
return 0;
bad:
cpuup_canceled(cpu);
return -ENOMEM;
}
int slab_prepare_cpu(unsigned int cpu)
{
int err;
mutex_lock(&slab_mutex);
err = cpuup_prepare(cpu);
mutex_unlock(&slab_mutex);
return err;
}
int slab_dead_cpu(unsigned int cpu)
{
mutex_lock(&slab_mutex);
cpuup_canceled(cpu);
mutex_unlock(&slab_mutex);
return 0;
}
static int slab_online_cpu(unsigned int cpu)
{
start_cpu_timer(cpu);
return 0;
}
static int slab_offline_cpu(unsigned int cpu)
{
cancel_delayed_work_sync(&per_cpu(slab_reap_work, cpu));
per_cpu(slab_reap_work, cpu).work.func = NULL;
return 0;
}
static int __meminit drain_cache_node_node(int node)
{
struct kmem_cache *cachep;
int ret = 0;
list_for_each_entry(cachep, &slab_caches, list) {
struct kmem_cache_node *n;
n = get_node(cachep, node);
if (!n)
continue;
drain_freelist(cachep, n, INT_MAX);
if (!list_empty(&n->slabs_full) ||
!list_empty(&n->slabs_partial)) {
ret = -EBUSY;
break;
}
}
return ret;
}
static int __meminit slab_memory_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
struct memory_notify *mnb = arg;
int ret = 0;
int nid;
nid = mnb->status_change_nid;
if (nid < 0)
goto out;
switch (action) {
case MEM_GOING_ONLINE:
mutex_lock(&slab_mutex);
ret = init_cache_node_node(nid);
mutex_unlock(&slab_mutex);
break;
case MEM_GOING_OFFLINE:
mutex_lock(&slab_mutex);
ret = drain_cache_node_node(nid);
mutex_unlock(&slab_mutex);
break;
case MEM_ONLINE:
case MEM_OFFLINE:
case MEM_CANCEL_ONLINE:
case MEM_CANCEL_OFFLINE:
break;
}
out:
return notifier_from_errno(ret);
}
static void __init init_list(struct kmem_cache *cachep, struct kmem_cache_node *list,
int nodeid)
{
struct kmem_cache_node *ptr;
ptr = kmalloc_node(sizeof(struct kmem_cache_node), GFP_NOWAIT, nodeid);
BUG_ON(!ptr);
memcpy(ptr, list, sizeof(struct kmem_cache_node));
spin_lock_init(&ptr->list_lock);
MAKE_ALL_LISTS(cachep, ptr, nodeid);
cachep->node[nodeid] = ptr;
}
static void __init set_up_node(struct kmem_cache *cachep, int index)
{
int node;
for_each_online_node(node) {
cachep->node[node] = &init_kmem_cache_node[index + node];
cachep->node[node]->next_reap = jiffies +
REAPTIMEOUT_NODE +
((unsigned long)cachep) % REAPTIMEOUT_NODE;
}
}
void __init kmem_cache_init(void)
{
int i;
BUILD_BUG_ON(sizeof(((struct page *)NULL)->lru) <
sizeof(struct rcu_head));
kmem_cache = &kmem_cache_boot;
if (!IS_ENABLED(CONFIG_NUMA) || num_possible_nodes() == 1)
use_alien_caches = 0;
for (i = 0; i < NUM_INIT_LISTS; i++)
kmem_cache_node_init(&init_kmem_cache_node[i]);
if (!slab_max_order_set && totalram_pages > (32 << 20) >> PAGE_SHIFT)
slab_max_order = SLAB_MAX_ORDER_HI;
create_boot_cache(kmem_cache, "kmem_cache",
offsetof(struct kmem_cache, node) +
nr_node_ids * sizeof(struct kmem_cache_node *),
SLAB_HWCACHE_ALIGN);
list_add(&kmem_cache->list, &slab_caches);
slab_state = PARTIAL;
kmalloc_caches[INDEX_NODE] = create_kmalloc_cache(
kmalloc_info[INDEX_NODE].name,
kmalloc_size(INDEX_NODE), ARCH_KMALLOC_FLAGS);
slab_state = PARTIAL_NODE;
setup_kmalloc_cache_index_table();
slab_early_init = 0;
{
int nid;
for_each_online_node(nid) {
init_list(kmem_cache, &init_kmem_cache_node[CACHE_CACHE + nid], nid);
init_list(kmalloc_caches[INDEX_NODE],
&init_kmem_cache_node[SIZE_NODE + nid], nid);
}
}
create_kmalloc_caches(ARCH_KMALLOC_FLAGS);
}
void __init kmem_cache_init_late(void)
{
struct kmem_cache *cachep;
slab_state = UP;
mutex_lock(&slab_mutex);
list_for_each_entry(cachep, &slab_caches, list)
if (enable_cpucache(cachep, GFP_NOWAIT))
BUG();
mutex_unlock(&slab_mutex);
slab_state = FULL;
#ifdef CONFIG_NUMA
hotplug_memory_notifier(slab_memory_callback, SLAB_CALLBACK_PRI);
#endif
}
static int __init cpucache_init(void)
{
int ret;
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "SLAB online",
slab_online_cpu, slab_offline_cpu);
WARN_ON(ret < 0);
slab_state = FULL;
return 0;
}
static noinline void
slab_out_of_memory(struct kmem_cache *cachep, gfp_t gfpflags, int nodeid)
{
#if DEBUG
struct kmem_cache_node *n;
unsigned long flags;
int node;
static DEFINE_RATELIMIT_STATE(slab_oom_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
if ((gfpflags & __GFP_NOWARN) || !__ratelimit(&slab_oom_rs))
return;
pr_warn("SLAB: Unable to allocate memory on node %d, gfp=%#x(%pGg)\n",
nodeid, gfpflags, &gfpflags);
pr_warn(" cache: %s, object size: %d, order: %d\n",
cachep->name, cachep->size, cachep->gfporder);
for_each_kmem_cache_node(cachep, node, n) {
unsigned long total_slabs, free_slabs, free_objs;
spin_lock_irqsave(&n->list_lock, flags);
total_slabs = n->total_slabs;
free_slabs = n->free_slabs;
free_objs = n->free_objects;
spin_unlock_irqrestore(&n->list_lock, flags);
pr_warn(" node %d: slabs: %ld/%ld, objs: %ld/%ld\n",
node, total_slabs - free_slabs, total_slabs,
(total_slabs * cachep->num) - free_objs,
total_slabs * cachep->num);
}
#endif
}
static struct page *kmem_getpages(struct kmem_cache *cachep, gfp_t flags,
int nodeid)
{
struct page *page;
int nr_pages;
flags |= cachep->allocflags;
if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
flags |= __GFP_RECLAIMABLE;
page = __alloc_pages_node(nodeid, flags | __GFP_NOTRACK, cachep->gfporder);
if (!page) {
slab_out_of_memory(cachep, flags, nodeid);
return NULL;
}
if (memcg_charge_slab(page, flags, cachep->gfporder, cachep)) {
__free_pages(page, cachep->gfporder);
return NULL;
}
nr_pages = (1 << cachep->gfporder);
if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
add_zone_page_state(page_zone(page),
NR_SLAB_RECLAIMABLE, nr_pages);
else
add_zone_page_state(page_zone(page),
NR_SLAB_UNRECLAIMABLE, nr_pages);
__SetPageSlab(page);
if (sk_memalloc_socks() && page_is_pfmemalloc(page))
SetPageSlabPfmemalloc(page);
if (kmemcheck_enabled && !(cachep->flags & SLAB_NOTRACK)) {
kmemcheck_alloc_shadow(page, cachep->gfporder, flags, nodeid);
if (cachep->ctor)
kmemcheck_mark_uninitialized_pages(page, nr_pages);
else
kmemcheck_mark_unallocated_pages(page, nr_pages);
}
return page;
}
static void kmem_freepages(struct kmem_cache *cachep, struct page *page)
{
int order = cachep->gfporder;
unsigned long nr_freed = (1 << order);
kmemcheck_free_shadow(page, order);
if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
sub_zone_page_state(page_zone(page),
NR_SLAB_RECLAIMABLE, nr_freed);
else
sub_zone_page_state(page_zone(page),
NR_SLAB_UNRECLAIMABLE, nr_freed);
BUG_ON(!PageSlab(page));
__ClearPageSlabPfmemalloc(page);
__ClearPageSlab(page);
page_mapcount_reset(page);
page->mapping = NULL;
if (current->reclaim_state)
current->reclaim_state->reclaimed_slab += nr_freed;
memcg_uncharge_slab(page, order, cachep);
__free_pages(page, order);
}
static void kmem_rcu_free(struct rcu_head *head)
{
struct kmem_cache *cachep;
struct page *page;
page = container_of(head, struct page, rcu_head);
cachep = page->slab_cache;
kmem_freepages(cachep, page);
}
static bool is_debug_pagealloc_cache(struct kmem_cache *cachep)
{
if (debug_pagealloc_enabled() && OFF_SLAB(cachep) &&
(cachep->size % PAGE_SIZE) == 0)
return true;
return false;
}
static void store_stackinfo(struct kmem_cache *cachep, unsigned long *addr,
unsigned long caller)
{
int size = cachep->object_size;
addr = (unsigned long *)&((char *)addr)[obj_offset(cachep)];
if (size < 5 * sizeof(unsigned long))
return;
*addr++ = 0x12345678;
*addr++ = caller;
*addr++ = smp_processor_id();
size -= 3 * sizeof(unsigned long);
{
unsigned long *sptr = &caller;
unsigned long svalue;
while (!kstack_end(sptr)) {
svalue = *sptr++;
if (kernel_text_address(svalue)) {
*addr++ = svalue;
size -= sizeof(unsigned long);
if (size <= sizeof(unsigned long))
break;
}
}
}
*addr++ = 0x87654321;
}
static void slab_kernel_map(struct kmem_cache *cachep, void *objp,
int map, unsigned long caller)
{
if (!is_debug_pagealloc_cache(cachep))
return;
if (caller)
store_stackinfo(cachep, objp, caller);
kernel_map_pages(virt_to_page(objp), cachep->size / PAGE_SIZE, map);
}
static inline void slab_kernel_map(struct kmem_cache *cachep, void *objp,
int map, unsigned long caller) {}
static void poison_obj(struct kmem_cache *cachep, void *addr, unsigned char val)
{
int size = cachep->object_size;
addr = &((char *)addr)[obj_offset(cachep)];
memset(addr, val, size);
*(unsigned char *)(addr + size - 1) = POISON_END;
}
static void dump_line(char *data, int offset, int limit)
{
int i;
unsigned char error = 0;
int bad_count = 0;
pr_err("%03x: ", offset);
for (i = 0; i < limit; i++) {
if (data[offset + i] != POISON_FREE) {
error = data[offset + i];
bad_count++;
}
}
print_hex_dump(KERN_CONT, "", 0, 16, 1,
&data[offset], limit, 1);
if (bad_count == 1) {
error ^= POISON_FREE;
if (!(error & (error - 1))) {
pr_err("Single bit error detected. Probably bad RAM.\n");
#ifdef CONFIG_X86
pr_err("Run memtest86+ or a similar memory test tool.\n");
#else
pr_err("Run a memory test tool.\n");
#endif
}
}
}
static void print_objinfo(struct kmem_cache *cachep, void *objp, int lines)
{
int i, size;
char *realobj;
if (cachep->flags & SLAB_RED_ZONE) {
pr_err("Redzone: 0x%llx/0x%llx\n",
*dbg_redzone1(cachep, objp),
*dbg_redzone2(cachep, objp));
}
if (cachep->flags & SLAB_STORE_USER) {
pr_err("Last user: [<%p>](%pSR)\n",
*dbg_userword(cachep, objp),
*dbg_userword(cachep, objp));
}
realobj = (char *)objp + obj_offset(cachep);
size = cachep->object_size;
for (i = 0; i < size && lines; i += 16, lines--) {
int limit;
limit = 16;
if (i + limit > size)
limit = size - i;
dump_line(realobj, i, limit);
}
}
static void check_poison_obj(struct kmem_cache *cachep, void *objp)
{
char *realobj;
int size, i;
int lines = 0;
if (is_debug_pagealloc_cache(cachep))
return;
realobj = (char *)objp + obj_offset(cachep);
size = cachep->object_size;
for (i = 0; i < size; i++) {
char exp = POISON_FREE;
if (i == size - 1)
exp = POISON_END;
if (realobj[i] != exp) {
int limit;
if (lines == 0) {
pr_err("Slab corruption (%s): %s start=%p, len=%d\n",
print_tainted(), cachep->name,
realobj, size);
print_objinfo(cachep, objp, 0);
}
i = (i / 16) * 16;
limit = 16;
if (i + limit > size)
limit = size - i;
dump_line(realobj, i, limit);
i += 16;
lines++;
if (lines > 5)
break;
}
}
if (lines != 0) {
struct page *page = virt_to_head_page(objp);
unsigned int objnr;
objnr = obj_to_index(cachep, page, objp);
if (objnr) {
objp = index_to_obj(cachep, page, objnr - 1);
realobj = (char *)objp + obj_offset(cachep);
pr_err("Prev obj: start=%p, len=%d\n", realobj, size);
print_objinfo(cachep, objp, 2);
}
if (objnr + 1 < cachep->num) {
objp = index_to_obj(cachep, page, objnr + 1);
realobj = (char *)objp + obj_offset(cachep);
pr_err("Next obj: start=%p, len=%d\n", realobj, size);
print_objinfo(cachep, objp, 2);
}
}
}
static void slab_destroy_debugcheck(struct kmem_cache *cachep,
struct page *page)
{
int i;
if (OBJFREELIST_SLAB(cachep) && cachep->flags & SLAB_POISON) {
poison_obj(cachep, page->freelist - obj_offset(cachep),
POISON_FREE);
}
for (i = 0; i < cachep->num; i++) {
void *objp = index_to_obj(cachep, page, i);
if (cachep->flags & SLAB_POISON) {
check_poison_obj(cachep, objp);
slab_kernel_map(cachep, objp, 1, 0);
}
if (cachep->flags & SLAB_RED_ZONE) {
if (*dbg_redzone1(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "start of a freed object was overwritten");
if (*dbg_redzone2(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "end of a freed object was overwritten");
}
}
}
static void slab_destroy_debugcheck(struct kmem_cache *cachep,
struct page *page)
{
}
static void slab_destroy(struct kmem_cache *cachep, struct page *page)
{
void *freelist;
freelist = page->freelist;
slab_destroy_debugcheck(cachep, page);
if (unlikely(cachep->flags & SLAB_TYPESAFE_BY_RCU))
call_rcu(&page->rcu_head, kmem_rcu_free);
else
kmem_freepages(cachep, page);
if (OFF_SLAB(cachep))
kmem_cache_free(cachep->freelist_cache, freelist);
}
static void slabs_destroy(struct kmem_cache *cachep, struct list_head *list)
{
struct page *page, *n;
list_for_each_entry_safe(page, n, list, lru) {
list_del(&page->lru);
slab_destroy(cachep, page);
}
}
static size_t calculate_slab_order(struct kmem_cache *cachep,
size_t size, unsigned long flags)
{
size_t left_over = 0;
int gfporder;
for (gfporder = 0; gfporder <= KMALLOC_MAX_ORDER; gfporder++) {
unsigned int num;
size_t remainder;
num = cache_estimate(gfporder, size, flags, &remainder);
if (!num)
continue;
if (num > SLAB_OBJ_MAX_NUM)
break;
if (flags & CFLGS_OFF_SLAB) {
struct kmem_cache *freelist_cache;
size_t freelist_size;
freelist_size = num * sizeof(freelist_idx_t);
freelist_cache = kmalloc_slab(freelist_size, 0u);
if (!freelist_cache)
continue;
if (OFF_SLAB(freelist_cache))
continue;
if (freelist_cache->size > cachep->size / 2)
continue;
}
cachep->num = num;
cachep->gfporder = gfporder;
left_over = remainder;
if (flags & SLAB_RECLAIM_ACCOUNT)
break;
if (gfporder >= slab_max_order)
break;
if (left_over * 8 <= (PAGE_SIZE << gfporder))
break;
}
return left_over;
}
static struct array_cache __percpu *alloc_kmem_cache_cpus(
struct kmem_cache *cachep, int entries, int batchcount)
{
int cpu;
size_t size;
struct array_cache __percpu *cpu_cache;
size = sizeof(void *) * entries + sizeof(struct array_cache);
cpu_cache = __alloc_percpu(size, sizeof(void *));
if (!cpu_cache)
return NULL;
for_each_possible_cpu(cpu) {
init_arraycache(per_cpu_ptr(cpu_cache, cpu),
entries, batchcount);
}
return cpu_cache;
}
static int __ref setup_cpu_cache(struct kmem_cache *cachep, gfp_t gfp)
{
if (slab_state >= FULL)
return enable_cpucache(cachep, gfp);
cachep->cpu_cache = alloc_kmem_cache_cpus(cachep, 1, 1);
if (!cachep->cpu_cache)
return 1;
if (slab_state == DOWN) {
set_up_node(kmem_cache, CACHE_CACHE);
} else if (slab_state == PARTIAL) {
set_up_node(cachep, SIZE_NODE);
} else {
int node;
for_each_online_node(node) {
cachep->node[node] = kmalloc_node(
sizeof(struct kmem_cache_node), gfp, node);
BUG_ON(!cachep->node[node]);
kmem_cache_node_init(cachep->node[node]);
}
}
cachep->node[numa_mem_id()]->next_reap =
jiffies + REAPTIMEOUT_NODE +
((unsigned long)cachep) % REAPTIMEOUT_NODE;
cpu_cache_get(cachep)->avail = 0;
cpu_cache_get(cachep)->limit = BOOT_CPUCACHE_ENTRIES;
cpu_cache_get(cachep)->batchcount = 1;
cpu_cache_get(cachep)->touched = 0;
cachep->batchcount = 1;
cachep->limit = BOOT_CPUCACHE_ENTRIES;
return 0;
}
unsigned long kmem_cache_flags(unsigned long object_size,
unsigned long flags, const char *name,
void (*ctor)(void *))
{
return flags;
}
struct kmem_cache *
__kmem_cache_alias(const char *name, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *))
{
struct kmem_cache *cachep;
cachep = find_mergeable(size, align, flags, name, ctor);
if (cachep) {
cachep->refcount++;
cachep->object_size = max_t(int, cachep->object_size, size);
}
return cachep;
}
static bool set_objfreelist_slab_cache(struct kmem_cache *cachep,
size_t size, unsigned long flags)
{
size_t left;
cachep->num = 0;
if (cachep->ctor || flags & SLAB_TYPESAFE_BY_RCU)
return false;
left = calculate_slab_order(cachep, size,
flags | CFLGS_OBJFREELIST_SLAB);
if (!cachep->num)
return false;
if (cachep->num * sizeof(freelist_idx_t) > cachep->object_size)
return false;
cachep->colour = left / cachep->colour_off;
return true;
}
static bool set_off_slab_cache(struct kmem_cache *cachep,
size_t size, unsigned long flags)
{
size_t left;
cachep->num = 0;
if (flags & SLAB_NOLEAKTRACE)
return false;
left = calculate_slab_order(cachep, size, flags | CFLGS_OFF_SLAB);
if (!cachep->num)
return false;
if (left >= cachep->num * sizeof(freelist_idx_t))
return false;
cachep->colour = left / cachep->colour_off;
return true;
}
static bool set_on_slab_cache(struct kmem_cache *cachep,
size_t size, unsigned long flags)
{
size_t left;
cachep->num = 0;
left = calculate_slab_order(cachep, size, flags);
if (!cachep->num)
return false;
cachep->colour = left / cachep->colour_off;
return true;
}
int
__kmem_cache_create (struct kmem_cache *cachep, unsigned long flags)
{
size_t ralign = BYTES_PER_WORD;
gfp_t gfp;
int err;
size_t size = cachep->size;
#if DEBUG
#if FORCED_DEBUG
if (size < 4096 || fls(size - 1) == fls(size-1 + REDZONE_ALIGN +
2 * sizeof(unsigned long long)))
flags |= SLAB_RED_ZONE | SLAB_STORE_USER;
if (!(flags & SLAB_TYPESAFE_BY_RCU))
flags |= SLAB_POISON;
#endif
#endif
if (size & (BYTES_PER_WORD - 1)) {
size += (BYTES_PER_WORD - 1);
size &= ~(BYTES_PER_WORD - 1);
}
if (flags & SLAB_RED_ZONE) {
ralign = REDZONE_ALIGN;
size += REDZONE_ALIGN - 1;
size &= ~(REDZONE_ALIGN - 1);
}
if (ralign < cachep->align) {
ralign = cachep->align;
}
if (ralign > __alignof__(unsigned long long))
flags &= ~(SLAB_RED_ZONE | SLAB_STORE_USER);
cachep->align = ralign;
cachep->colour_off = cache_line_size();
if (cachep->colour_off < cachep->align)
cachep->colour_off = cachep->align;
if (slab_is_available())
gfp = GFP_KERNEL;
else
gfp = GFP_NOWAIT;
#if DEBUG
if (flags & SLAB_RED_ZONE) {
cachep->obj_offset += sizeof(unsigned long long);
size += 2 * sizeof(unsigned long long);
}
if (flags & SLAB_STORE_USER) {
if (flags & SLAB_RED_ZONE)
size += REDZONE_ALIGN;
else
size += BYTES_PER_WORD;
}
#endif
kasan_cache_create(cachep, &size, &flags);
size = ALIGN(size, cachep->align);
if (FREELIST_BYTE_INDEX && size < SLAB_OBJ_MIN_SIZE)
size = ALIGN(SLAB_OBJ_MIN_SIZE, cachep->align);
#if DEBUG
if (debug_pagealloc_enabled() && (flags & SLAB_POISON) &&
size >= 256 && cachep->object_size > cache_line_size()) {
if (size < PAGE_SIZE || size % PAGE_SIZE == 0) {
size_t tmp_size = ALIGN(size, PAGE_SIZE);
if (set_off_slab_cache(cachep, tmp_size, flags)) {
flags |= CFLGS_OFF_SLAB;
cachep->obj_offset += tmp_size - size;
size = tmp_size;
goto done;
}
}
}
#endif
if (set_objfreelist_slab_cache(cachep, size, flags)) {
flags |= CFLGS_OBJFREELIST_SLAB;
goto done;
}
if (set_off_slab_cache(cachep, size, flags)) {
flags |= CFLGS_OFF_SLAB;
goto done;
}
if (set_on_slab_cache(cachep, size, flags))
goto done;
return -E2BIG;
done:
cachep->freelist_size = cachep->num * sizeof(freelist_idx_t);
cachep->flags = flags;
cachep->allocflags = __GFP_COMP;
if (flags & SLAB_CACHE_DMA)
cachep->allocflags |= GFP_DMA;
cachep->size = size;
cachep->reciprocal_buffer_size = reciprocal_value(size);
#if DEBUG
if (IS_ENABLED(CONFIG_PAGE_POISONING) &&
(cachep->flags & SLAB_POISON) &&
is_debug_pagealloc_cache(cachep))
cachep->flags &= ~(SLAB_RED_ZONE | SLAB_STORE_USER);
#endif
if (OFF_SLAB(cachep)) {
cachep->freelist_cache =
kmalloc_slab(cachep->freelist_size, 0u);
}
err = setup_cpu_cache(cachep, gfp);
if (err) {
__kmem_cache_release(cachep);
return err;
}
return 0;
}
static void check_irq_off(void)
{
BUG_ON(!irqs_disabled());
}
static void check_irq_on(void)
{
BUG_ON(irqs_disabled());
}
static void check_mutex_acquired(void)
{
BUG_ON(!mutex_is_locked(&slab_mutex));
}
static void check_spinlock_acquired(struct kmem_cache *cachep)
{
#ifdef CONFIG_SMP
check_irq_off();
assert_spin_locked(&get_node(cachep, numa_mem_id())->list_lock);
#endif
}
static void check_spinlock_acquired_node(struct kmem_cache *cachep, int node)
{
#ifdef CONFIG_SMP
check_irq_off();
assert_spin_locked(&get_node(cachep, node)->list_lock);
#endif
}
static void drain_array_locked(struct kmem_cache *cachep, struct array_cache *ac,
int node, bool free_all, struct list_head *list)
{
int tofree;
if (!ac || !ac->avail)
return;
tofree = free_all ? ac->avail : (ac->limit + 4) / 5;
if (tofree > ac->avail)
tofree = (ac->avail + 1) / 2;
free_block(cachep, ac->entry, tofree, node, list);
ac->avail -= tofree;
memmove(ac->entry, &(ac->entry[tofree]), sizeof(void *) * ac->avail);
}
static void do_drain(void *arg)
{
struct kmem_cache *cachep = arg;
struct array_cache *ac;
int node = numa_mem_id();
struct kmem_cache_node *n;
LIST_HEAD(list);
check_irq_off();
ac = cpu_cache_get(cachep);
n = get_node(cachep, node);
spin_lock(&n->list_lock);
free_block(cachep, ac->entry, ac->avail, node, &list);
spin_unlock(&n->list_lock);
slabs_destroy(cachep, &list);
ac->avail = 0;
}
static void drain_cpu_caches(struct kmem_cache *cachep)
{
struct kmem_cache_node *n;
int node;
LIST_HEAD(list);
on_each_cpu(do_drain, cachep, 1);
check_irq_on();
for_each_kmem_cache_node(cachep, node, n)
if (n->alien)
drain_alien_cache(cachep, n->alien);
for_each_kmem_cache_node(cachep, node, n) {
spin_lock_irq(&n->list_lock);
drain_array_locked(cachep, n->shared, node, true, &list);
spin_unlock_irq(&n->list_lock);
slabs_destroy(cachep, &list);
}
}
static int drain_freelist(struct kmem_cache *cache,
struct kmem_cache_node *n, int tofree)
{
struct list_head *p;
int nr_freed;
struct page *page;
nr_freed = 0;
while (nr_freed < tofree && !list_empty(&n->slabs_free)) {
spin_lock_irq(&n->list_lock);
p = n->slabs_free.prev;
if (p == &n->slabs_free) {
spin_unlock_irq(&n->list_lock);
goto out;
}
page = list_entry(p, struct page, lru);
list_del(&page->lru);
n->free_slabs--;
n->total_slabs--;
n->free_objects -= cache->num;
spin_unlock_irq(&n->list_lock);
slab_destroy(cache, page);
nr_freed++;
}
out:
return nr_freed;
}
int __kmem_cache_shrink(struct kmem_cache *cachep)
{
int ret = 0;
int node;
struct kmem_cache_node *n;
drain_cpu_caches(cachep);
check_irq_on();
for_each_kmem_cache_node(cachep, node, n) {
drain_freelist(cachep, n, INT_MAX);
ret += !list_empty(&n->slabs_full) ||
!list_empty(&n->slabs_partial);
}
return (ret ? 1 : 0);
}
void __kmemcg_cache_deactivate(struct kmem_cache *cachep)
{
__kmem_cache_shrink(cachep);
}
int __kmem_cache_shutdown(struct kmem_cache *cachep)
{
return __kmem_cache_shrink(cachep);
}
void __kmem_cache_release(struct kmem_cache *cachep)
{
int i;
struct kmem_cache_node *n;
cache_random_seq_destroy(cachep);
free_percpu(cachep->cpu_cache);
for_each_kmem_cache_node(cachep, i, n) {
kfree(n->shared);
free_alien_cache(n->alien);
kfree(n);
cachep->node[i] = NULL;
}
}
static void *alloc_slabmgmt(struct kmem_cache *cachep,
struct page *page, int colour_off,
gfp_t local_flags, int nodeid)
{
void *freelist;
void *addr = page_address(page);
page->s_mem = addr + colour_off;
page->active = 0;
if (OBJFREELIST_SLAB(cachep))
freelist = NULL;
else if (OFF_SLAB(cachep)) {
freelist = kmem_cache_alloc_node(cachep->freelist_cache,
local_flags, nodeid);
if (!freelist)
return NULL;
} else {
freelist = addr + (PAGE_SIZE << cachep->gfporder) -
cachep->freelist_size;
}
return freelist;
}
static inline freelist_idx_t get_free_obj(struct page *page, unsigned int idx)
{
return ((freelist_idx_t *)page->freelist)[idx];
}
static inline void set_free_obj(struct page *page,
unsigned int idx, freelist_idx_t val)
{
((freelist_idx_t *)(page->freelist))[idx] = val;
}
static void cache_init_objs_debug(struct kmem_cache *cachep, struct page *page)
{
#if DEBUG
int i;
for (i = 0; i < cachep->num; i++) {
void *objp = index_to_obj(cachep, page, i);
if (cachep->flags & SLAB_STORE_USER)
*dbg_userword(cachep, objp) = NULL;
if (cachep->flags & SLAB_RED_ZONE) {
*dbg_redzone1(cachep, objp) = RED_INACTIVE;
*dbg_redzone2(cachep, objp) = RED_INACTIVE;
}
if (cachep->ctor && !(cachep->flags & SLAB_POISON)) {
kasan_unpoison_object_data(cachep,
objp + obj_offset(cachep));
cachep->ctor(objp + obj_offset(cachep));
kasan_poison_object_data(
cachep, objp + obj_offset(cachep));
}
if (cachep->flags & SLAB_RED_ZONE) {
if (*dbg_redzone2(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "constructor overwrote the end of an object");
if (*dbg_redzone1(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "constructor overwrote the start of an object");
}
if (cachep->flags & SLAB_POISON) {
poison_obj(cachep, objp, POISON_FREE);
slab_kernel_map(cachep, objp, 0, 0);
}
}
#endif
}
static bool freelist_state_initialize(union freelist_init_state *state,
struct kmem_cache *cachep,
unsigned int count)
{
bool ret;
unsigned int rand;
rand = get_random_int();
if (!cachep->random_seq) {
prandom_seed_state(&state->rnd_state, rand);
ret = false;
} else {
state->list = cachep->random_seq;
state->count = count;
state->pos = rand % count;
ret = true;
}
return ret;
}
static freelist_idx_t next_random_slot(union freelist_init_state *state)
{
if (state->pos >= state->count)
state->pos = 0;
return state->list[state->pos++];
}
static void swap_free_obj(struct page *page, unsigned int a, unsigned int b)
{
swap(((freelist_idx_t *)page->freelist)[a],
((freelist_idx_t *)page->freelist)[b]);
}
static bool shuffle_freelist(struct kmem_cache *cachep, struct page *page)
{
unsigned int objfreelist = 0, i, rand, count = cachep->num;
union freelist_init_state state;
bool precomputed;
if (count < 2)
return false;
precomputed = freelist_state_initialize(&state, cachep, count);
if (OBJFREELIST_SLAB(cachep)) {
if (!precomputed)
objfreelist = count - 1;
else
objfreelist = next_random_slot(&state);
page->freelist = index_to_obj(cachep, page, objfreelist) +
obj_offset(cachep);
count--;
}
if (!precomputed) {
for (i = 0; i < count; i++)
set_free_obj(page, i, i);
for (i = count - 1; i > 0; i--) {
rand = prandom_u32_state(&state.rnd_state);
rand %= (i + 1);
swap_free_obj(page, i, rand);
}
} else {
for (i = 0; i < count; i++)
set_free_obj(page, i, next_random_slot(&state));
}
if (OBJFREELIST_SLAB(cachep))
set_free_obj(page, cachep->num - 1, objfreelist);
return true;
}
static inline bool shuffle_freelist(struct kmem_cache *cachep,
struct page *page)
{
return false;
}
static void cache_init_objs(struct kmem_cache *cachep,
struct page *page)
{
int i;
void *objp;
bool shuffled;
cache_init_objs_debug(cachep, page);
shuffled = shuffle_freelist(cachep, page);
if (!shuffled && OBJFREELIST_SLAB(cachep)) {
page->freelist = index_to_obj(cachep, page, cachep->num - 1) +
obj_offset(cachep);
}
for (i = 0; i < cachep->num; i++) {
objp = index_to_obj(cachep, page, i);
kasan_init_slab_obj(cachep, objp);
if (DEBUG == 0 && cachep->ctor) {
kasan_unpoison_object_data(cachep, objp);
cachep->ctor(objp);
kasan_poison_object_data(cachep, objp);
}
if (!shuffled)
set_free_obj(page, i, i);
}
}
static void *slab_get_obj(struct kmem_cache *cachep, struct page *page)
{
void *objp;
objp = index_to_obj(cachep, page, get_free_obj(page, page->active));
page->active++;
#if DEBUG
if (cachep->flags & SLAB_STORE_USER)
set_store_user_dirty(cachep);
#endif
return objp;
}
static void slab_put_obj(struct kmem_cache *cachep,
struct page *page, void *objp)
{
unsigned int objnr = obj_to_index(cachep, page, objp);
#if DEBUG
unsigned int i;
for (i = page->active; i < cachep->num; i++) {
if (get_free_obj(page, i) == objnr) {
pr_err("slab: double free detected in cache '%s', objp %p\n",
cachep->name, objp);
BUG();
}
}
#endif
page->active--;
if (!page->freelist)
page->freelist = objp + obj_offset(cachep);
set_free_obj(page, page->active, objnr);
}
static void slab_map_pages(struct kmem_cache *cache, struct page *page,
void *freelist)
{
page->slab_cache = cache;
page->freelist = freelist;
}
static struct page *cache_grow_begin(struct kmem_cache *cachep,
gfp_t flags, int nodeid)
{
void *freelist;
size_t offset;
gfp_t local_flags;
int page_node;
struct kmem_cache_node *n;
struct page *page;
if (unlikely(flags & GFP_SLAB_BUG_MASK)) {
gfp_t invalid_mask = flags & GFP_SLAB_BUG_MASK;
flags &= ~GFP_SLAB_BUG_MASK;
pr_warn("Unexpected gfp: %#x (%pGg). Fixing up to gfp: %#x (%pGg). Fix your code!\n",
invalid_mask, &invalid_mask, flags, &flags);
dump_stack();
}
local_flags = flags & (GFP_CONSTRAINT_MASK|GFP_RECLAIM_MASK);
check_irq_off();
if (gfpflags_allow_blocking(local_flags))
local_irq_enable();
page = kmem_getpages(cachep, local_flags, nodeid);
if (!page)
goto failed;
page_node = page_to_nid(page);
n = get_node(cachep, page_node);
n->colour_next++;
if (n->colour_next >= cachep->colour)
n->colour_next = 0;
offset = n->colour_next;
if (offset >= cachep->colour)
offset = 0;
offset *= cachep->colour_off;
freelist = alloc_slabmgmt(cachep, page, offset,
local_flags & ~GFP_CONSTRAINT_MASK, page_node);
if (OFF_SLAB(cachep) && !freelist)
goto opps1;
slab_map_pages(cachep, page, freelist);
kasan_poison_slab(page);
cache_init_objs(cachep, page);
if (gfpflags_allow_blocking(local_flags))
local_irq_disable();
return page;
opps1:
kmem_freepages(cachep, page);
failed:
if (gfpflags_allow_blocking(local_flags))
local_irq_disable();
return NULL;
}
static void cache_grow_end(struct kmem_cache *cachep, struct page *page)
{
struct kmem_cache_node *n;
void *list = NULL;
check_irq_off();
if (!page)
return;
INIT_LIST_HEAD(&page->lru);
n = get_node(cachep, page_to_nid(page));
spin_lock(&n->list_lock);
n->total_slabs++;
if (!page->active) {
list_add_tail(&page->lru, &(n->slabs_free));
n->free_slabs++;
} else
fixup_slab_list(cachep, n, page, &list);
STATS_INC_GROWN(cachep);
n->free_objects += cachep->num - page->active;
spin_unlock(&n->list_lock);
fixup_objfreelist_debug(cachep, &list);
}
static void kfree_debugcheck(const void *objp)
{
if (!virt_addr_valid(objp)) {
pr_err("kfree_debugcheck: out of range ptr %lxh\n",
(unsigned long)objp);
BUG();
}
}
static inline void verify_redzone_free(struct kmem_cache *cache, void *obj)
{
unsigned long long redzone1, redzone2;
redzone1 = *dbg_redzone1(cache, obj);
redzone2 = *dbg_redzone2(cache, obj);
if (redzone1 == RED_ACTIVE && redzone2 == RED_ACTIVE)
return;
if (redzone1 == RED_INACTIVE && redzone2 == RED_INACTIVE)
slab_error(cache, "double free detected");
else
slab_error(cache, "memory outside object was overwritten");
pr_err("%p: redzone 1:0x%llx, redzone 2:0x%llx\n",
obj, redzone1, redzone2);
}
static void *cache_free_debugcheck(struct kmem_cache *cachep, void *objp,
unsigned long caller)
{
unsigned int objnr;
struct page *page;
BUG_ON(virt_to_cache(objp) != cachep);
objp -= obj_offset(cachep);
kfree_debugcheck(objp);
page = virt_to_head_page(objp);
if (cachep->flags & SLAB_RED_ZONE) {
verify_redzone_free(cachep, objp);
*dbg_redzone1(cachep, objp) = RED_INACTIVE;
*dbg_redzone2(cachep, objp) = RED_INACTIVE;
}
if (cachep->flags & SLAB_STORE_USER) {
set_store_user_dirty(cachep);
*dbg_userword(cachep, objp) = (void *)caller;
}
objnr = obj_to_index(cachep, page, objp);
BUG_ON(objnr >= cachep->num);
BUG_ON(objp != index_to_obj(cachep, page, objnr));
if (cachep->flags & SLAB_POISON) {
poison_obj(cachep, objp, POISON_FREE);
slab_kernel_map(cachep, objp, 0, caller);
}
return objp;
}
static inline void fixup_objfreelist_debug(struct kmem_cache *cachep,
void **list)
{
#if DEBUG
void *next = *list;
void *objp;
while (next) {
objp = next - obj_offset(cachep);
next = *(void **)next;
poison_obj(cachep, objp, POISON_FREE);
}
#endif
}
static inline void fixup_slab_list(struct kmem_cache *cachep,
struct kmem_cache_node *n, struct page *page,
void **list)
{
list_del(&page->lru);
if (page->active == cachep->num) {
list_add(&page->lru, &n->slabs_full);
if (OBJFREELIST_SLAB(cachep)) {
#if DEBUG
if (cachep->flags & SLAB_POISON) {
void **objp = page->freelist;
*objp = *list;
*list = objp;
}
#endif
page->freelist = NULL;
}
} else
list_add(&page->lru, &n->slabs_partial);
}
struct page *get_first_slab(struct kmem_cache_node *n, bool pfmemalloc)
{
struct page *page;
assert_spin_locked(&n->list_lock);
page = list_first_entry_or_null(&n->slabs_partial, struct page, lru);
if (!page) {
n->free_touched = 1;
page = list_first_entry_or_null(&n->slabs_free, struct page,
lru);
if (page)
n->free_slabs--;
}
if (sk_memalloc_socks())
page = get_valid_first_slab(n, page, pfmemalloc);
return page;
}
static noinline void *cache_alloc_pfmemalloc(struct kmem_cache *cachep,
struct kmem_cache_node *n, gfp_t flags)
{
struct page *page;
void *obj;
void *list = NULL;
if (!gfp_pfmemalloc_allowed(flags))
return NULL;
spin_lock(&n->list_lock);
page = get_first_slab(n, true);
if (!page) {
spin_unlock(&n->list_lock);
return NULL;
}
obj = slab_get_obj(cachep, page);
n->free_objects--;
fixup_slab_list(cachep, n, page, &list);
spin_unlock(&n->list_lock);
fixup_objfreelist_debug(cachep, &list);
return obj;
}
static __always_inline int alloc_block(struct kmem_cache *cachep,
struct array_cache *ac, struct page *page, int batchcount)
{
BUG_ON(page->active >= cachep->num);
while (page->active < cachep->num && batchcount--) {
STATS_INC_ALLOCED(cachep);
STATS_INC_ACTIVE(cachep);
STATS_SET_HIGH(cachep);
ac->entry[ac->avail++] = slab_get_obj(cachep, page);
}
return batchcount;
}
static void *cache_alloc_refill(struct kmem_cache *cachep, gfp_t flags)
{
int batchcount;
struct kmem_cache_node *n;
struct array_cache *ac, *shared;
int node;
void *list = NULL;
struct page *page;
check_irq_off();
node = numa_mem_id();
ac = cpu_cache_get(cachep);
batchcount = ac->batchcount;
if (!ac->touched && batchcount > BATCHREFILL_LIMIT) {
batchcount = BATCHREFILL_LIMIT;
}
n = get_node(cachep, node);
BUG_ON(ac->avail > 0 || !n);
shared = READ_ONCE(n->shared);
if (!n->free_objects && (!shared || !shared->avail))
goto direct_grow;
spin_lock(&n->list_lock);
shared = READ_ONCE(n->shared);
if (shared && transfer_objects(ac, shared, batchcount)) {
shared->touched = 1;
goto alloc_done;
}
while (batchcount > 0) {
page = get_first_slab(n, false);
if (!page)
goto must_grow;
check_spinlock_acquired(cachep);
batchcount = alloc_block(cachep, ac, page, batchcount);
fixup_slab_list(cachep, n, page, &list);
}
must_grow:
n->free_objects -= ac->avail;
alloc_done:
spin_unlock(&n->list_lock);
fixup_objfreelist_debug(cachep, &list);
direct_grow:
if (unlikely(!ac->avail)) {
if (sk_memalloc_socks()) {
void *obj = cache_alloc_pfmemalloc(cachep, n, flags);
if (obj)
return obj;
}
page = cache_grow_begin(cachep, gfp_exact_node(flags), node);
ac = cpu_cache_get(cachep);
if (!ac->avail && page)
alloc_block(cachep, ac, page, batchcount);
cache_grow_end(cachep, page);
if (!ac->avail)
return NULL;
}
ac->touched = 1;
return ac->entry[--ac->avail];
}
static inline void cache_alloc_debugcheck_before(struct kmem_cache *cachep,
gfp_t flags)
{
might_sleep_if(gfpflags_allow_blocking(flags));
}
static void *cache_alloc_debugcheck_after(struct kmem_cache *cachep,
gfp_t flags, void *objp, unsigned long caller)
{
if (!objp)
return objp;
if (cachep->flags & SLAB_POISON) {
check_poison_obj(cachep, objp);
slab_kernel_map(cachep, objp, 1, 0);
poison_obj(cachep, objp, POISON_INUSE);
}
if (cachep->flags & SLAB_STORE_USER)
*dbg_userword(cachep, objp) = (void *)caller;
if (cachep->flags & SLAB_RED_ZONE) {
if (*dbg_redzone1(cachep, objp) != RED_INACTIVE ||
*dbg_redzone2(cachep, objp) != RED_INACTIVE) {
slab_error(cachep, "double free, or memory outside object was overwritten");
pr_err("%p: redzone 1:0x%llx, redzone 2:0x%llx\n",
objp, *dbg_redzone1(cachep, objp),
*dbg_redzone2(cachep, objp));
}
*dbg_redzone1(cachep, objp) = RED_ACTIVE;
*dbg_redzone2(cachep, objp) = RED_ACTIVE;
}
objp += obj_offset(cachep);
if (cachep->ctor && cachep->flags & SLAB_POISON)
cachep->ctor(objp);
if (ARCH_SLAB_MINALIGN &&
((unsigned long)objp & (ARCH_SLAB_MINALIGN-1))) {
pr_err("0x%p: not aligned to ARCH_SLAB_MINALIGN=%d\n",
objp, (int)ARCH_SLAB_MINALIGN);
}
return objp;
}
static inline void *____cache_alloc(struct kmem_cache *cachep, gfp_t flags)
{
void *objp;
struct array_cache *ac;
check_irq_off();
ac = cpu_cache_get(cachep);
if (likely(ac->avail)) {
ac->touched = 1;
objp = ac->entry[--ac->avail];
STATS_INC_ALLOCHIT(cachep);
goto out;
}
STATS_INC_ALLOCMISS(cachep);
objp = cache_alloc_refill(cachep, flags);
ac = cpu_cache_get(cachep);
out:
if (objp)
kmemleak_erase(&ac->entry[ac->avail]);
return objp;
}
static void *alternate_node_alloc(struct kmem_cache *cachep, gfp_t flags)
{
int nid_alloc, nid_here;
if (in_interrupt() || (flags & __GFP_THISNODE))
return NULL;
nid_alloc = nid_here = numa_mem_id();
if (cpuset_do_slab_mem_spread() && (cachep->flags & SLAB_MEM_SPREAD))
nid_alloc = cpuset_slab_spread_node();
else if (current->mempolicy)
nid_alloc = mempolicy_slab_node();
if (nid_alloc != nid_here)
return ____cache_alloc_node(cachep, flags, nid_alloc);
return NULL;
}
static void *fallback_alloc(struct kmem_cache *cache, gfp_t flags)
{
struct zonelist *zonelist;
struct zoneref *z;
struct zone *zone;
enum zone_type high_zoneidx = gfp_zone(flags);
void *obj = NULL;
struct page *page;
int nid;
unsigned int cpuset_mems_cookie;
if (flags & __GFP_THISNODE)
return NULL;
retry_cpuset:
cpuset_mems_cookie = read_mems_allowed_begin();
zonelist = node_zonelist(mempolicy_slab_node(), flags);
retry:
for_each_zone_zonelist(zone, z, zonelist, high_zoneidx) {
nid = zone_to_nid(zone);
if (cpuset_zone_allowed(zone, flags) &&
get_node(cache, nid) &&
get_node(cache, nid)->free_objects) {
obj = ____cache_alloc_node(cache,
gfp_exact_node(flags), nid);
if (obj)
break;
}
}
if (!obj) {
page = cache_grow_begin(cache, flags, numa_mem_id());
cache_grow_end(cache, page);
if (page) {
nid = page_to_nid(page);
obj = ____cache_alloc_node(cache,
gfp_exact_node(flags), nid);
if (!obj)
goto retry;
}
}
if (unlikely(!obj && read_mems_allowed_retry(cpuset_mems_cookie)))
goto retry_cpuset;
return obj;
}
static void *____cache_alloc_node(struct kmem_cache *cachep, gfp_t flags,
int nodeid)
{
struct page *page;
struct kmem_cache_node *n;
void *obj = NULL;
void *list = NULL;
VM_BUG_ON(nodeid < 0 || nodeid >= MAX_NUMNODES);
n = get_node(cachep, nodeid);
BUG_ON(!n);
check_irq_off();
spin_lock(&n->list_lock);
page = get_first_slab(n, false);
if (!page)
goto must_grow;
check_spinlock_acquired_node(cachep, nodeid);
STATS_INC_NODEALLOCS(cachep);
STATS_INC_ACTIVE(cachep);
STATS_SET_HIGH(cachep);
BUG_ON(page->active == cachep->num);
obj = slab_get_obj(cachep, page);
n->free_objects--;
fixup_slab_list(cachep, n, page, &list);
spin_unlock(&n->list_lock);
fixup_objfreelist_debug(cachep, &list);
return obj;
must_grow:
spin_unlock(&n->list_lock);
page = cache_grow_begin(cachep, gfp_exact_node(flags), nodeid);
if (page) {
obj = slab_get_obj(cachep, page);
}
cache_grow_end(cachep, page);
return obj ? obj : fallback_alloc(cachep, flags);
}
static __always_inline void *
slab_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid,
unsigned long caller)
{
unsigned long save_flags;
void *ptr;
int slab_node = numa_mem_id();
flags &= gfp_allowed_mask;
cachep = slab_pre_alloc_hook(cachep, flags);
if (unlikely(!cachep))
return NULL;
cache_alloc_debugcheck_before(cachep, flags);
local_irq_save(save_flags);
if (nodeid == NUMA_NO_NODE)
nodeid = slab_node;
if (unlikely(!get_node(cachep, nodeid))) {
ptr = fallback_alloc(cachep, flags);
goto out;
}
if (nodeid == slab_node) {
ptr = ____cache_alloc(cachep, flags);
if (ptr)
goto out;
}
ptr = ____cache_alloc_node(cachep, flags, nodeid);
out:
local_irq_restore(save_flags);
ptr = cache_alloc_debugcheck_after(cachep, flags, ptr, caller);
if (unlikely(flags & __GFP_ZERO) && ptr)
memset(ptr, 0, cachep->object_size);
slab_post_alloc_hook(cachep, flags, 1, &ptr);
return ptr;
}
static __always_inline void *
__do_cache_alloc(struct kmem_cache *cache, gfp_t flags)
{
void *objp;
if (current->mempolicy || cpuset_do_slab_mem_spread()) {
objp = alternate_node_alloc(cache, flags);
if (objp)
goto out;
}
objp = ____cache_alloc(cache, flags);
if (!objp)
objp = ____cache_alloc_node(cache, flags, numa_mem_id());
out:
return objp;
}
static __always_inline void *
__do_cache_alloc(struct kmem_cache *cachep, gfp_t flags)
{
return ____cache_alloc(cachep, flags);
}
static __always_inline void *
slab_alloc(struct kmem_cache *cachep, gfp_t flags, unsigned long caller)
{
unsigned long save_flags;
void *objp;
flags &= gfp_allowed_mask;
cachep = slab_pre_alloc_hook(cachep, flags);
if (unlikely(!cachep))
return NULL;
cache_alloc_debugcheck_before(cachep, flags);
local_irq_save(save_flags);
objp = __do_cache_alloc(cachep, flags);
local_irq_restore(save_flags);
objp = cache_alloc_debugcheck_after(cachep, flags, objp, caller);
prefetchw(objp);
if (unlikely(flags & __GFP_ZERO) && objp)
memset(objp, 0, cachep->object_size);
slab_post_alloc_hook(cachep, flags, 1, &objp);
return objp;
}
static void free_block(struct kmem_cache *cachep, void **objpp,
int nr_objects, int node, struct list_head *list)
{
int i;
struct kmem_cache_node *n = get_node(cachep, node);
struct page *page;
n->free_objects += nr_objects;
for (i = 0; i < nr_objects; i++) {
void *objp;
struct page *page;
objp = objpp[i];
page = virt_to_head_page(objp);
list_del(&page->lru);
check_spinlock_acquired_node(cachep, node);
slab_put_obj(cachep, page, objp);
STATS_DEC_ACTIVE(cachep);
if (page->active == 0) {
list_add(&page->lru, &n->slabs_free);
n->free_slabs++;
} else {
list_add_tail(&page->lru, &n->slabs_partial);
}
}
while (n->free_objects > n->free_limit && !list_empty(&n->slabs_free)) {
n->free_objects -= cachep->num;
page = list_last_entry(&n->slabs_free, struct page, lru);
list_move(&page->lru, list);
n->free_slabs--;
n->total_slabs--;
}
}
static void cache_flusharray(struct kmem_cache *cachep, struct array_cache *ac)
{
int batchcount;
struct kmem_cache_node *n;
int node = numa_mem_id();
LIST_HEAD(list);
batchcount = ac->batchcount;
check_irq_off();
n = get_node(cachep, node);
spin_lock(&n->list_lock);
if (n->shared) {
struct array_cache *shared_array = n->shared;
int max = shared_array->limit - shared_array->avail;
if (max) {
if (batchcount > max)
batchcount = max;
memcpy(&(shared_array->entry[shared_array->avail]),
ac->entry, sizeof(void *) * batchcount);
shared_array->avail += batchcount;
goto free_done;
}
}
free_block(cachep, ac->entry, batchcount, node, &list);
free_done:
#if STATS
{
int i = 0;
struct page *page;
list_for_each_entry(page, &n->slabs_free, lru) {
BUG_ON(page->active);
i++;
}
STATS_SET_FREEABLE(cachep, i);
}
#endif
spin_unlock(&n->list_lock);
slabs_destroy(cachep, &list);
ac->avail -= batchcount;
memmove(ac->entry, &(ac->entry[batchcount]), sizeof(void *)*ac->avail);
}
static inline void __cache_free(struct kmem_cache *cachep, void *objp,
unsigned long caller)
{
if (kasan_slab_free(cachep, objp))
return;
___cache_free(cachep, objp, caller);
}
void ___cache_free(struct kmem_cache *cachep, void *objp,
unsigned long caller)
{
struct array_cache *ac = cpu_cache_get(cachep);
check_irq_off();
kmemleak_free_recursive(objp, cachep->flags);
objp = cache_free_debugcheck(cachep, objp, caller);
kmemcheck_slab_free(cachep, objp, cachep->object_size);
if (nr_online_nodes > 1 && cache_free_alien(cachep, objp))
return;
if (ac->avail < ac->limit) {
STATS_INC_FREEHIT(cachep);
} else {
STATS_INC_FREEMISS(cachep);
cache_flusharray(cachep, ac);
}
if (sk_memalloc_socks()) {
struct page *page = virt_to_head_page(objp);
if (unlikely(PageSlabPfmemalloc(page))) {
cache_free_pfmemalloc(cachep, page, objp);
return;
}
}
ac->entry[ac->avail++] = objp;
}
void *kmem_cache_alloc(struct kmem_cache *cachep, gfp_t flags)
{
void *ret = slab_alloc(cachep, flags, _RET_IP_);
kasan_slab_alloc(cachep, ret, flags);
trace_kmem_cache_alloc(_RET_IP_, ret,
cachep->object_size, cachep->size, flags);
return ret;
}
static __always_inline void
cache_alloc_debugcheck_after_bulk(struct kmem_cache *s, gfp_t flags,
size_t size, void **p, unsigned long caller)
{
size_t i;
for (i = 0; i < size; i++)
p[i] = cache_alloc_debugcheck_after(s, flags, p[i], caller);
}
int kmem_cache_alloc_bulk(struct kmem_cache *s, gfp_t flags, size_t size,
void **p)
{
size_t i;
s = slab_pre_alloc_hook(s, flags);
if (!s)
return 0;
cache_alloc_debugcheck_before(s, flags);
local_irq_disable();
for (i = 0; i < size; i++) {
void *objp = __do_cache_alloc(s, flags);
if (unlikely(!objp))
goto error;
p[i] = objp;
}
local_irq_enable();
cache_alloc_debugcheck_after_bulk(s, flags, size, p, _RET_IP_);
if (unlikely(flags & __GFP_ZERO))
for (i = 0; i < size; i++)
memset(p[i], 0, s->object_size);
slab_post_alloc_hook(s, flags, size, p);
return size;
error:
local_irq_enable();
cache_alloc_debugcheck_after_bulk(s, flags, i, p, _RET_IP_);
slab_post_alloc_hook(s, flags, i, p);
__kmem_cache_free_bulk(s, i, p);
return 0;
}
void *
kmem_cache_alloc_trace(struct kmem_cache *cachep, gfp_t flags, size_t size)
{
void *ret;
ret = slab_alloc(cachep, flags, _RET_IP_);
kasan_kmalloc(cachep, ret, size, flags);
trace_kmalloc(_RET_IP_, ret,
size, cachep->size, flags);
return ret;
}
void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid)
{
void *ret = slab_alloc_node(cachep, flags, nodeid, _RET_IP_);
kasan_slab_alloc(cachep, ret, flags);
trace_kmem_cache_alloc_node(_RET_IP_, ret,
cachep->object_size, cachep->size,
flags, nodeid);
return ret;
}
void *kmem_cache_alloc_node_trace(struct kmem_cache *cachep,
gfp_t flags,
int nodeid,
size_t size)
{
void *ret;
ret = slab_alloc_node(cachep, flags, nodeid, _RET_IP_);
kasan_kmalloc(cachep, ret, size, flags);
trace_kmalloc_node(_RET_IP_, ret,
size, cachep->size,
flags, nodeid);
return ret;
}
static __always_inline void *
__do_kmalloc_node(size_t size, gfp_t flags, int node, unsigned long caller)
{
struct kmem_cache *cachep;
void *ret;
cachep = kmalloc_slab(size, flags);
if (unlikely(ZERO_OR_NULL_PTR(cachep)))
return cachep;
ret = kmem_cache_alloc_node_trace(cachep, flags, node, size);
kasan_kmalloc(cachep, ret, size, flags);
return ret;
}
void *__kmalloc_node(size_t size, gfp_t flags, int node)
{
return __do_kmalloc_node(size, flags, node, _RET_IP_);
}
void *__kmalloc_node_track_caller(size_t size, gfp_t flags,
int node, unsigned long caller)
{
return __do_kmalloc_node(size, flags, node, caller);
}
static __always_inline void *__do_kmalloc(size_t size, gfp_t flags,
unsigned long caller)
{
struct kmem_cache *cachep;
void *ret;
cachep = kmalloc_slab(size, flags);
if (unlikely(ZERO_OR_NULL_PTR(cachep)))
return cachep;
ret = slab_alloc(cachep, flags, caller);
kasan_kmalloc(cachep, ret, size, flags);
trace_kmalloc(caller, ret,
size, cachep->size, flags);
return ret;
}
void *__kmalloc(size_t size, gfp_t flags)
{
return __do_kmalloc(size, flags, _RET_IP_);
}
void *__kmalloc_track_caller(size_t size, gfp_t flags, unsigned long caller)
{
return __do_kmalloc(size, flags, caller);
}
void kmem_cache_free(struct kmem_cache *cachep, void *objp)
{
unsigned long flags;
cachep = cache_from_obj(cachep, objp);
if (!cachep)
return;
local_irq_save(flags);
debug_check_no_locks_freed(objp, cachep->object_size);
if (!(cachep->flags & SLAB_DEBUG_OBJECTS))
debug_check_no_obj_freed(objp, cachep->object_size);
__cache_free(cachep, objp, _RET_IP_);
local_irq_restore(flags);
trace_kmem_cache_free(_RET_IP_, objp);
}
void kmem_cache_free_bulk(struct kmem_cache *orig_s, size_t size, void **p)
{
struct kmem_cache *s;
size_t i;
local_irq_disable();
for (i = 0; i < size; i++) {
void *objp = p[i];
if (!orig_s)
s = virt_to_cache(objp);
else
s = cache_from_obj(orig_s, objp);
debug_check_no_locks_freed(objp, s->object_size);
if (!(s->flags & SLAB_DEBUG_OBJECTS))
debug_check_no_obj_freed(objp, s->object_size);
__cache_free(s, objp, _RET_IP_);
}
local_irq_enable();
}
void kfree(const void *objp)
{
struct kmem_cache *c;
unsigned long flags;
trace_kfree(_RET_IP_, objp);
if (unlikely(ZERO_OR_NULL_PTR(objp)))
return;
local_irq_save(flags);
kfree_debugcheck(objp);
c = virt_to_cache(objp);
debug_check_no_locks_freed(objp, c->object_size);
debug_check_no_obj_freed(objp, c->object_size);
__cache_free(c, (void *)objp, _RET_IP_);
local_irq_restore(flags);
}
static int setup_kmem_cache_nodes(struct kmem_cache *cachep, gfp_t gfp)
{
int ret;
int node;
struct kmem_cache_node *n;
for_each_online_node(node) {
ret = setup_kmem_cache_node(cachep, node, gfp, true);
if (ret)
goto fail;
}
return 0;
fail:
if (!cachep->list.next) {
node--;
while (node >= 0) {
n = get_node(cachep, node);
if (n) {
kfree(n->shared);
free_alien_cache(n->alien);
kfree(n);
cachep->node[node] = NULL;
}
node--;
}
}
return -ENOMEM;
}
static int __do_tune_cpucache(struct kmem_cache *cachep, int limit,
int batchcount, int shared, gfp_t gfp)
{
struct array_cache __percpu *cpu_cache, *prev;
int cpu;
cpu_cache = alloc_kmem_cache_cpus(cachep, limit, batchcount);
if (!cpu_cache)
return -ENOMEM;
prev = cachep->cpu_cache;
cachep->cpu_cache = cpu_cache;
if (prev)
kick_all_cpus_sync();
check_irq_on();
cachep->batchcount = batchcount;
cachep->limit = limit;
cachep->shared = shared;
if (!prev)
goto setup_node;
for_each_online_cpu(cpu) {
LIST_HEAD(list);
int node;
struct kmem_cache_node *n;
struct array_cache *ac = per_cpu_ptr(prev, cpu);
node = cpu_to_mem(cpu);
n = get_node(cachep, node);
spin_lock_irq(&n->list_lock);
free_block(cachep, ac->entry, ac->avail, node, &list);
spin_unlock_irq(&n->list_lock);
slabs_destroy(cachep, &list);
}
free_percpu(prev);
setup_node:
return setup_kmem_cache_nodes(cachep, gfp);
}
static int do_tune_cpucache(struct kmem_cache *cachep, int limit,
int batchcount, int shared, gfp_t gfp)
{
int ret;
struct kmem_cache *c;
ret = __do_tune_cpucache(cachep, limit, batchcount, shared, gfp);
if (slab_state < FULL)
return ret;
if ((ret < 0) || !is_root_cache(cachep))
return ret;
lockdep_assert_held(&slab_mutex);
for_each_memcg_cache(c, cachep) {
__do_tune_cpucache(c, limit, batchcount, shared, gfp);
}
return ret;
}
static int enable_cpucache(struct kmem_cache *cachep, gfp_t gfp)
{
int err;
int limit = 0;
int shared = 0;
int batchcount = 0;
err = cache_random_seq_create(cachep, cachep->num, gfp);
if (err)
goto end;
if (!is_root_cache(cachep)) {
struct kmem_cache *root = memcg_root_cache(cachep);
limit = root->limit;
shared = root->shared;
batchcount = root->batchcount;
}
if (limit && shared && batchcount)
goto skip_setup;
if (cachep->size > 131072)
limit = 1;
else if (cachep->size > PAGE_SIZE)
limit = 8;
else if (cachep->size > 1024)
limit = 24;
else if (cachep->size > 256)
limit = 54;
else
limit = 120;
shared = 0;
if (cachep->size <= PAGE_SIZE && num_possible_cpus() > 1)
shared = 8;
#if DEBUG
if (limit > 32)
limit = 32;
#endif
batchcount = (limit + 1) / 2;
skip_setup:
err = do_tune_cpucache(cachep, limit, batchcount, shared, gfp);
end:
if (err)
pr_err("enable_cpucache failed for %s, error %d\n",
cachep->name, -err);
return err;
}
static void drain_array(struct kmem_cache *cachep, struct kmem_cache_node *n,
struct array_cache *ac, int node)
{
LIST_HEAD(list);
check_mutex_acquired();
if (!ac || !ac->avail)
return;
if (ac->touched) {
ac->touched = 0;
return;
}
spin_lock_irq(&n->list_lock);
drain_array_locked(cachep, ac, node, false, &list);
spin_unlock_irq(&n->list_lock);
slabs_destroy(cachep, &list);
}
static void cache_reap(struct work_struct *w)
{
struct kmem_cache *searchp;
struct kmem_cache_node *n;
int node = numa_mem_id();
struct delayed_work *work = to_delayed_work(w);
if (!mutex_trylock(&slab_mutex))
goto out;
list_for_each_entry(searchp, &slab_caches, list) {
check_irq_on();
n = get_node(searchp, node);
reap_alien(searchp, n);
drain_array(searchp, n, cpu_cache_get(searchp), node);
if (time_after(n->next_reap, jiffies))
goto next;
n->next_reap = jiffies + REAPTIMEOUT_NODE;
drain_array(searchp, n, n->shared, node);
if (n->free_touched)
n->free_touched = 0;
else {
int freed;
freed = drain_freelist(searchp, n, (n->free_limit +
5 * searchp->num - 1) / (5 * searchp->num));
STATS_ADD_REAPED(searchp, freed);
}
next:
cond_resched();
}
check_irq_on();
mutex_unlock(&slab_mutex);
next_reap_node();
out:
schedule_delayed_work(work, round_jiffies_relative(REAPTIMEOUT_AC));
}
void get_slabinfo(struct kmem_cache *cachep, struct slabinfo *sinfo)
{
unsigned long active_objs, num_objs, active_slabs;
unsigned long total_slabs = 0, free_objs = 0, shared_avail = 0;
unsigned long free_slabs = 0;
int node;
struct kmem_cache_node *n;
for_each_kmem_cache_node(cachep, node, n) {
check_irq_on();
spin_lock_irq(&n->list_lock);
total_slabs += n->total_slabs;
free_slabs += n->free_slabs;
free_objs += n->free_objects;
if (n->shared)
shared_avail += n->shared->avail;
spin_unlock_irq(&n->list_lock);
}
num_objs = total_slabs * cachep->num;
active_slabs = total_slabs - free_slabs;
active_objs = num_objs - free_objs;
sinfo->active_objs = active_objs;
sinfo->num_objs = num_objs;
sinfo->active_slabs = active_slabs;
sinfo->num_slabs = total_slabs;
sinfo->shared_avail = shared_avail;
sinfo->limit = cachep->limit;
sinfo->batchcount = cachep->batchcount;
sinfo->shared = cachep->shared;
sinfo->objects_per_slab = cachep->num;
sinfo->cache_order = cachep->gfporder;
}
void slabinfo_show_stats(struct seq_file *m, struct kmem_cache *cachep)
{
#if STATS
{
unsigned long high = cachep->high_mark;
unsigned long allocs = cachep->num_allocations;
unsigned long grown = cachep->grown;
unsigned long reaped = cachep->reaped;
unsigned long errors = cachep->errors;
unsigned long max_freeable = cachep->max_freeable;
unsigned long node_allocs = cachep->node_allocs;
unsigned long node_frees = cachep->node_frees;
unsigned long overflows = cachep->node_overflow;
seq_printf(m, " : globalstat %7lu %6lu %5lu %4lu %4lu %4lu %4lu %4lu %4lu",
allocs, high, grown,
reaped, errors, max_freeable, node_allocs,
node_frees, overflows);
}
{
unsigned long allochit = atomic_read(&cachep->allochit);
unsigned long allocmiss = atomic_read(&cachep->allocmiss);
unsigned long freehit = atomic_read(&cachep->freehit);
unsigned long freemiss = atomic_read(&cachep->freemiss);
seq_printf(m, " : cpustat %6lu %6lu %6lu %6lu",
allochit, allocmiss, freehit, freemiss);
}
#endif
}
ssize_t slabinfo_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
char kbuf[MAX_SLABINFO_WRITE + 1], *tmp;
int limit, batchcount, shared, res;
struct kmem_cache *cachep;
if (count > MAX_SLABINFO_WRITE)
return -EINVAL;
if (copy_from_user(&kbuf, buffer, count))
return -EFAULT;
kbuf[MAX_SLABINFO_WRITE] = '\0';
tmp = strchr(kbuf, ' ');
if (!tmp)
return -EINVAL;
*tmp = '\0';
tmp++;
if (sscanf(tmp, " %d %d %d", &limit, &batchcount, &shared) != 3)
return -EINVAL;
mutex_lock(&slab_mutex);
res = -EINVAL;
list_for_each_entry(cachep, &slab_caches, list) {
if (!strcmp(cachep->name, kbuf)) {
if (limit < 1 || batchcount < 1 ||
batchcount > limit || shared < 0) {
res = 0;
} else {
res = do_tune_cpucache(cachep, limit,
batchcount, shared,
GFP_KERNEL);
}
break;
}
}
mutex_unlock(&slab_mutex);
if (res >= 0)
res = count;
return res;
}
static inline int add_caller(unsigned long *n, unsigned long v)
{
unsigned long *p;
int l;
if (!v)
return 1;
l = n[1];
p = n + 2;
while (l) {
int i = l/2;
unsigned long *q = p + 2 * i;
if (*q == v) {
q[1]++;
return 1;
}
if (*q > v) {
l = i;
} else {
p = q + 2;
l -= i + 1;
}
}
if (++n[1] == n[0])
return 0;
memmove(p + 2, p, n[1] * 2 * sizeof(unsigned long) - ((void *)p - (void *)n));
p[0] = v;
p[1] = 1;
return 1;
}
static void handle_slab(unsigned long *n, struct kmem_cache *c,
struct page *page)
{
void *p;
int i, j;
unsigned long v;
if (n[0] == n[1])
return;
for (i = 0, p = page->s_mem; i < c->num; i++, p += c->size) {
bool active = true;
for (j = page->active; j < c->num; j++) {
if (get_free_obj(page, j) == i) {
active = false;
break;
}
}
if (!active)
continue;
if (probe_kernel_read(&v, dbg_userword(c, p), sizeof(v)))
continue;
if (!add_caller(n, v))
return;
}
}
static void show_symbol(struct seq_file *m, unsigned long address)
{
#ifdef CONFIG_KALLSYMS
unsigned long offset, size;
char modname[MODULE_NAME_LEN], name[KSYM_NAME_LEN];
if (lookup_symbol_attrs(address, &size, &offset, modname, name) == 0) {
seq_printf(m, "%s+%#lx/%#lx", name, offset, size);
if (modname[0])
seq_printf(m, " [%s]", modname);
return;
}
#endif
seq_printf(m, "%p", (void *)address);
}
static int leaks_show(struct seq_file *m, void *p)
{
struct kmem_cache *cachep = list_entry(p, struct kmem_cache, list);
struct page *page;
struct kmem_cache_node *n;
const char *name;
unsigned long *x = m->private;
int node;
int i;
if (!(cachep->flags & SLAB_STORE_USER))
return 0;
if (!(cachep->flags & SLAB_RED_ZONE))
return 0;
do {
set_store_user_clean(cachep);
drain_cpu_caches(cachep);
x[1] = 0;
for_each_kmem_cache_node(cachep, node, n) {
check_irq_on();
spin_lock_irq(&n->list_lock);
list_for_each_entry(page, &n->slabs_full, lru)
handle_slab(x, cachep, page);
list_for_each_entry(page, &n->slabs_partial, lru)
handle_slab(x, cachep, page);
spin_unlock_irq(&n->list_lock);
}
} while (!is_store_user_clean(cachep));
name = cachep->name;
if (x[0] == x[1]) {
mutex_unlock(&slab_mutex);
m->private = kzalloc(x[0] * 4 * sizeof(unsigned long), GFP_KERNEL);
if (!m->private) {
m->private = x;
mutex_lock(&slab_mutex);
return -ENOMEM;
}
*(unsigned long *)m->private = x[0] * 2;
kfree(x);
mutex_lock(&slab_mutex);
m->count = m->size;
return 0;
}
for (i = 0; i < x[1]; i++) {
seq_printf(m, "%s: %lu ", name, x[2*i+3]);
show_symbol(m, x[2*i+2]);
seq_putc(m, '\n');
}
return 0;
}
static int slabstats_open(struct inode *inode, struct file *file)
{
unsigned long *n;
n = __seq_open_private(file, &slabstats_op, PAGE_SIZE);
if (!n)
return -ENOMEM;
*n = PAGE_SIZE / (2 * sizeof(unsigned long));
return 0;
}
static int __init slab_proc_init(void)
{
#ifdef CONFIG_DEBUG_SLAB_LEAK
proc_create("slab_allocators", 0, NULL, &proc_slabstats_operations);
#endif
return 0;
}
const char *__check_heap_object(const void *ptr, unsigned long n,
struct page *page)
{
struct kmem_cache *cachep;
unsigned int objnr;
unsigned long offset;
cachep = page->slab_cache;
objnr = obj_to_index(cachep, page, (void *)ptr);
BUG_ON(objnr >= cachep->num);
offset = ptr - index_to_obj(cachep, page, objnr) - obj_offset(cachep);
if (offset <= cachep->object_size && n <= cachep->object_size - offset)
return NULL;
return cachep->name;
}
size_t ksize(const void *objp)
{
size_t size;
BUG_ON(!objp);
if (unlikely(objp == ZERO_SIZE_PTR))
return 0;
size = virt_to_cache(objp)->object_size;
kasan_unpoison_shadow(objp, size);
return size;
}
