static inline bool is_obj_pfmemalloc(void *objp)
{
return (unsigned long)objp & SLAB_OBJ_PFMEMALLOC;
}
static inline void set_obj_pfmemalloc(void **objp)
{
*objp = (void *)((unsigned long)*objp | SLAB_OBJ_PFMEMALLOC);
return;
}
static inline void clear_obj_pfmemalloc(void **objp)
{
*objp = (void *)((unsigned long)*objp & ~SLAB_OBJ_PFMEMALLOC);
}
static void kmem_cache_node_init(struct kmem_cache_node *parent)
{
INIT_LIST_HEAD(&parent->slabs_full);
INIT_LIST_HEAD(&parent->slabs_partial);
INIT_LIST_HEAD(&parent->slabs_free);
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
static void set_obj_status(struct page *page, int idx, int val)
{
int freelist_size;
char *status;
struct kmem_cache *cachep = page->slab_cache;
freelist_size = cachep->num * sizeof(freelist_idx_t);
status = (char *)page->freelist + freelist_size;
status[idx] = val;
}
static inline unsigned int get_obj_status(struct page *page, int idx)
{
int freelist_size;
char *status;
struct kmem_cache *cachep = page->slab_cache;
freelist_size = cachep->num * sizeof(freelist_idx_t);
status = (char *)page->freelist + freelist_size;
return status[idx];
}
static inline void set_obj_status(struct page *page, int idx, int val) {}
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
static size_t calculate_freelist_size(int nr_objs, size_t align)
{
size_t freelist_size;
freelist_size = nr_objs * sizeof(freelist_idx_t);
if (IS_ENABLED(CONFIG_DEBUG_SLAB_LEAK))
freelist_size += nr_objs * sizeof(char);
if (align)
freelist_size = ALIGN(freelist_size, align);
return freelist_size;
}
static int calculate_nr_objs(size_t slab_size, size_t buffer_size,
size_t idx_size, size_t align)
{
int nr_objs;
size_t remained_size;
size_t freelist_size;
int extra_space = 0;
if (IS_ENABLED(CONFIG_DEBUG_SLAB_LEAK))
extra_space = sizeof(char);
nr_objs = slab_size / (buffer_size + idx_size + extra_space);
remained_size = slab_size - nr_objs * buffer_size;
freelist_size = calculate_freelist_size(nr_objs, align);
if (remained_size < freelist_size)
nr_objs--;
return nr_objs;
}
static void cache_estimate(unsigned long gfporder, size_t buffer_size,
size_t align, int flags, size_t *left_over,
unsigned int *num)
{
int nr_objs;
size_t mgmt_size;
size_t slab_size = PAGE_SIZE << gfporder;
if (flags & CFLGS_OFF_SLAB) {
mgmt_size = 0;
nr_objs = slab_size / buffer_size;
} else {
nr_objs = calculate_nr_objs(slab_size, buffer_size,
sizeof(freelist_idx_t), align);
mgmt_size = calculate_freelist_size(nr_objs, align);
}
*num = nr_objs;
*left_over = slab_size - nr_objs*buffer_size - mgmt_size;
}
static void __slab_error(const char *function, struct kmem_cache *cachep,
char *msg)
{
printk(KERN_ERR "slab error in %s(): cache `%s': %s\n",
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
int node;
node = next_node(cpu_to_mem(cpu), node_online_map);
if (node == MAX_NUMNODES)
node = first_node(node_online_map);
per_cpu(slab_reap_node, cpu) = node;
}
static void next_reap_node(void)
{
int node = __this_cpu_read(slab_reap_node);
node = next_node(node, node_online_map);
if (unlikely(node >= MAX_NUMNODES))
node = first_node(node_online_map);
__this_cpu_write(slab_reap_node, node);
}
static void start_cpu_timer(int cpu)
{
struct delayed_work *reap_work = &per_cpu(slab_reap_work, cpu);
if (keventd_up() && reap_work->work.func == NULL) {
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
static inline bool is_slab_pfmemalloc(struct page *page)
{
return PageSlabPfmemalloc(page);
}
static void recheck_pfmemalloc_active(struct kmem_cache *cachep,
struct array_cache *ac)
{
struct kmem_cache_node *n = get_node(cachep, numa_mem_id());
struct page *page;
unsigned long flags;
if (!pfmemalloc_active)
return;
spin_lock_irqsave(&n->list_lock, flags);
list_for_each_entry(page, &n->slabs_full, lru)
if (is_slab_pfmemalloc(page))
goto out;
list_for_each_entry(page, &n->slabs_partial, lru)
if (is_slab_pfmemalloc(page))
goto out;
list_for_each_entry(page, &n->slabs_free, lru)
if (is_slab_pfmemalloc(page))
goto out;
pfmemalloc_active = false;
out:
spin_unlock_irqrestore(&n->list_lock, flags);
}
static void *__ac_get_obj(struct kmem_cache *cachep, struct array_cache *ac,
gfp_t flags, bool force_refill)
{
int i;
void *objp = ac->entry[--ac->avail];
if (unlikely(is_obj_pfmemalloc(objp))) {
struct kmem_cache_node *n;
if (gfp_pfmemalloc_allowed(flags)) {
clear_obj_pfmemalloc(&objp);
return objp;
}
for (i = 0; i < ac->avail; i++) {
if (!is_obj_pfmemalloc(ac->entry[i])) {
objp = ac->entry[i];
ac->entry[i] = ac->entry[ac->avail];
ac->entry[ac->avail] = objp;
return objp;
}
}
n = get_node(cachep, numa_mem_id());
if (!list_empty(&n->slabs_free) && force_refill) {
struct page *page = virt_to_head_page(objp);
ClearPageSlabPfmemalloc(page);
clear_obj_pfmemalloc(&objp);
recheck_pfmemalloc_active(cachep, ac);
return objp;
}
ac->avail++;
objp = NULL;
}
return objp;
}
static inline void *ac_get_obj(struct kmem_cache *cachep,
struct array_cache *ac, gfp_t flags, bool force_refill)
{
void *objp;
if (unlikely(sk_memalloc_socks()))
objp = __ac_get_obj(cachep, ac, flags, force_refill);
else
objp = ac->entry[--ac->avail];
return objp;
}
static noinline void *__ac_put_obj(struct kmem_cache *cachep,
struct array_cache *ac, void *objp)
{
if (unlikely(pfmemalloc_active)) {
struct page *page = virt_to_head_page(objp);
if (PageSlabPfmemalloc(page))
set_obj_pfmemalloc(&objp);
}
return objp;
}
static inline void ac_put_obj(struct kmem_cache *cachep, struct array_cache *ac,
void *objp)
{
if (unlikely(sk_memalloc_socks()))
objp = __ac_put_obj(cachep, ac, objp);
ac->entry[ac->avail++] = objp;
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
return (struct alien_cache **)BAD_ALIEN_MAGIC;
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
ac_put_obj(cachep, ac, objp);
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
static int init_cache_node_node(int node)
{
struct kmem_cache *cachep;
struct kmem_cache_node *n;
const size_t memsize = sizeof(struct kmem_cache_node);
list_for_each_entry(cachep, &slab_caches, list) {
n = get_node(cachep, node);
if (!n) {
n = kmalloc_node(memsize, GFP_KERNEL, node);
if (!n)
return -ENOMEM;
kmem_cache_node_init(n);
n->next_reap = jiffies + REAPTIMEOUT_NODE +
((unsigned long)cachep) % REAPTIMEOUT_NODE;
cachep->node[node] = n;
}
spin_lock_irq(&n->list_lock);
n->free_limit =
(1 + nr_cpus_node(node)) *
cachep->batchcount + cachep->num;
spin_unlock_irq(&n->list_lock);
}
return 0;
}
static inline int slabs_tofree(struct kmem_cache *cachep,
struct kmem_cache_node *n)
{
return (n->free_objects + cachep->num - 1) / cachep->num;
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
drain_freelist(cachep, n, slabs_tofree(cachep, n));
}
}
static int cpuup_prepare(long cpu)
{
struct kmem_cache *cachep;
struct kmem_cache_node *n = NULL;
int node = cpu_to_mem(cpu);
int err;
err = init_cache_node_node(node);
if (err < 0)
goto bad;
list_for_each_entry(cachep, &slab_caches, list) {
struct array_cache *shared = NULL;
struct alien_cache **alien = NULL;
if (cachep->shared) {
shared = alloc_arraycache(node,
cachep->shared * cachep->batchcount,
0xbaadf00d, GFP_KERNEL);
if (!shared)
goto bad;
}
if (use_alien_caches) {
alien = alloc_alien_cache(node, cachep->limit, GFP_KERNEL);
if (!alien) {
kfree(shared);
goto bad;
}
}
n = get_node(cachep, node);
BUG_ON(!n);
spin_lock_irq(&n->list_lock);
if (!n->shared) {
n->shared = shared;
shared = NULL;
}
#ifdef CONFIG_NUMA
if (!n->alien) {
n->alien = alien;
alien = NULL;
}
#endif
spin_unlock_irq(&n->list_lock);
kfree(shared);
free_alien_cache(alien);
}
return 0;
bad:
cpuup_canceled(cpu);
return -ENOMEM;
}
static int cpuup_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
long cpu = (long)hcpu;
int err = 0;
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
mutex_lock(&slab_mutex);
err = cpuup_prepare(cpu);
mutex_unlock(&slab_mutex);
break;
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
start_cpu_timer(cpu);
break;
#ifdef CONFIG_HOTPLUG_CPU
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
cancel_delayed_work_sync(&per_cpu(slab_reap_work, cpu));
per_cpu(slab_reap_work, cpu).work.func = NULL;
break;
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
start_cpu_timer(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
#endif
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
mutex_lock(&slab_mutex);
cpuup_canceled(cpu);
mutex_unlock(&slab_mutex);
break;
}
return notifier_from_errno(err);
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
drain_freelist(cachep, n, slabs_tofree(cachep, n));
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
if (num_possible_nodes() == 1)
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
kmalloc_caches[INDEX_NODE] = create_kmalloc_cache("kmalloc-node",
kmalloc_size(INDEX_NODE), ARCH_KMALLOC_FLAGS);
slab_state = PARTIAL_NODE;
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
register_cpu_notifier(&cpucache_notifier);
#ifdef CONFIG_NUMA
hotplug_memory_notifier(slab_memory_callback, SLAB_CALLBACK_PRI);
#endif
}
static int __init cpucache_init(void)
{
int cpu;
for_each_online_cpu(cpu)
start_cpu_timer(cpu);
slab_state = FULL;
return 0;
}
static noinline void
slab_out_of_memory(struct kmem_cache *cachep, gfp_t gfpflags, int nodeid)
{
#if DEBUG
struct kmem_cache_node *n;
struct page *page;
unsigned long flags;
int node;
static DEFINE_RATELIMIT_STATE(slab_oom_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
if ((gfpflags & __GFP_NOWARN) || !__ratelimit(&slab_oom_rs))
return;
printk(KERN_WARNING
"SLAB: Unable to allocate memory on node %d (gfp=0x%x)\n",
nodeid, gfpflags);
printk(KERN_WARNING " cache: %s, object size: %d, order: %d\n",
cachep->name, cachep->size, cachep->gfporder);
for_each_kmem_cache_node(cachep, node, n) {
unsigned long active_objs = 0, num_objs = 0, free_objects = 0;
unsigned long active_slabs = 0, num_slabs = 0;
spin_lock_irqsave(&n->list_lock, flags);
list_for_each_entry(page, &n->slabs_full, lru) {
active_objs += cachep->num;
active_slabs++;
}
list_for_each_entry(page, &n->slabs_partial, lru) {
active_objs += page->active;
active_slabs++;
}
list_for_each_entry(page, &n->slabs_free, lru)
num_slabs++;
free_objects += n->free_objects;
spin_unlock_irqrestore(&n->list_lock, flags);
num_slabs += active_slabs;
num_objs = num_slabs * cachep->num;
printk(KERN_WARNING
" node %d: slabs: %ld/%ld, objs: %ld/%ld, free: %ld\n",
node, active_slabs, num_slabs, active_objs, num_objs,
free_objects);
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
if (memcg_charge_slab(cachep, flags, cachep->gfporder))
return NULL;
page = alloc_pages_exact_node(nodeid, flags | __GFP_NOTRACK, cachep->gfporder);
if (!page) {
memcg_uncharge_slab(cachep, cachep->gfporder);
slab_out_of_memory(cachep, flags, nodeid);
return NULL;
}
if (unlikely(page->pfmemalloc))
pfmemalloc_active = true;
nr_pages = (1 << cachep->gfporder);
if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
add_zone_page_state(page_zone(page),
NR_SLAB_RECLAIMABLE, nr_pages);
else
add_zone_page_state(page_zone(page),
NR_SLAB_UNRECLAIMABLE, nr_pages);
__SetPageSlab(page);
if (page->pfmemalloc)
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
const unsigned long nr_freed = (1 << cachep->gfporder);
kmemcheck_free_shadow(page, cachep->gfporder);
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
__free_pages(page, cachep->gfporder);
memcg_uncharge_slab(cachep, cachep->gfporder);
}
static void kmem_rcu_free(struct rcu_head *head)
{
struct kmem_cache *cachep;
struct page *page;
page = container_of(head, struct page, rcu_head);
cachep = page->slab_cache;
kmem_freepages(cachep, page);
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
printk(KERN_ERR "%03x: ", offset);
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
printk(KERN_ERR "Single bit error detected. Probably "
"bad RAM.\n");
#ifdef CONFIG_X86
printk(KERN_ERR "Run memtest86+ or a similar memory "
"test tool.\n");
#else
printk(KERN_ERR "Run a memory test tool.\n");
#endif
}
}
}
static void print_objinfo(struct kmem_cache *cachep, void *objp, int lines)
{
int i, size;
char *realobj;
if (cachep->flags & SLAB_RED_ZONE) {
printk(KERN_ERR "Redzone: 0x%llx/0x%llx.\n",
*dbg_redzone1(cachep, objp),
*dbg_redzone2(cachep, objp));
}
if (cachep->flags & SLAB_STORE_USER) {
printk(KERN_ERR "Last user: [<%p>](%pSR)\n",
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
realobj = (char *)objp + obj_offset(cachep);
size = cachep->object_size;
for (i = 0; i < size; i++) {
char exp = POISON_FREE;
if (i == size - 1)
exp = POISON_END;
if (realobj[i] != exp) {
int limit;
if (lines == 0) {
printk(KERN_ERR
"Slab corruption (%s): %s start=%p, len=%d\n",
print_tainted(), cachep->name, realobj, size);
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
printk(KERN_ERR "Prev obj: start=%p, len=%d\n",
realobj, size);
print_objinfo(cachep, objp, 2);
}
if (objnr + 1 < cachep->num) {
objp = index_to_obj(cachep, page, objnr + 1);
realobj = (char *)objp + obj_offset(cachep);
printk(KERN_ERR "Next obj: start=%p, len=%d\n",
realobj, size);
print_objinfo(cachep, objp, 2);
}
}
}
static void slab_destroy_debugcheck(struct kmem_cache *cachep,
struct page *page)
{
int i;
for (i = 0; i < cachep->num; i++) {
void *objp = index_to_obj(cachep, page, i);
if (cachep->flags & SLAB_POISON) {
#ifdef CONFIG_DEBUG_PAGEALLOC
if (cachep->size % PAGE_SIZE == 0 &&
OFF_SLAB(cachep))
kernel_map_pages(virt_to_page(objp),
cachep->size / PAGE_SIZE, 1);
else
check_poison_obj(cachep, objp);
#else
check_poison_obj(cachep, objp);
#endif
}
if (cachep->flags & SLAB_RED_ZONE) {
if (*dbg_redzone1(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "start of a freed object "
"was overwritten");
if (*dbg_redzone2(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "end of a freed object "
"was overwritten");
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
if (unlikely(cachep->flags & SLAB_DESTROY_BY_RCU)) {
struct rcu_head *head;
head = (void *)&page->rcu_head;
call_rcu(head, kmem_rcu_free);
} else {
kmem_freepages(cachep, page);
}
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
size_t size, size_t align, unsigned long flags)
{
unsigned long offslab_limit;
size_t left_over = 0;
int gfporder;
for (gfporder = 0; gfporder <= KMALLOC_MAX_ORDER; gfporder++) {
unsigned int num;
size_t remainder;
cache_estimate(gfporder, size, align, flags, &remainder, &num);
if (!num)
continue;
if (num > SLAB_OBJ_MAX_NUM)
break;
if (flags & CFLGS_OFF_SLAB) {
size_t freelist_size_per_obj = sizeof(freelist_idx_t);
if (IS_ENABLED(CONFIG_DEBUG_SLAB_LEAK))
freelist_size_per_obj += sizeof(char);
offslab_limit = size;
offslab_limit /= freelist_size_per_obj;
if (num > offslab_limit)
break;
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
static int __init_refok setup_cpu_cache(struct kmem_cache *cachep, gfp_t gfp)
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
int
__kmem_cache_create (struct kmem_cache *cachep, unsigned long flags)
{
size_t left_over, freelist_size;
size_t ralign = BYTES_PER_WORD;
gfp_t gfp;
int err;
size_t size = cachep->size;
#if DEBUG
#if FORCED_DEBUG
if (size < 4096 || fls(size - 1) == fls(size-1 + REDZONE_ALIGN +
2 * sizeof(unsigned long long)))
flags |= SLAB_RED_ZONE | SLAB_STORE_USER;
if (!(flags & SLAB_DESTROY_BY_RCU))
flags |= SLAB_POISON;
#endif
if (flags & SLAB_DESTROY_BY_RCU)
BUG_ON(flags & SLAB_POISON);
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
#if FORCED_DEBUG && defined(CONFIG_DEBUG_PAGEALLOC)
if (size >= kmalloc_size(INDEX_NODE + 1)
&& cachep->object_size > cache_line_size()
&& ALIGN(size, cachep->align) < PAGE_SIZE) {
cachep->obj_offset += PAGE_SIZE - ALIGN(size, cachep->align);
size = PAGE_SIZE;
}
#endif
#endif
if ((size >= (PAGE_SIZE >> 5)) && !slab_early_init &&
!(flags & SLAB_NOLEAKTRACE))
flags |= CFLGS_OFF_SLAB;
size = ALIGN(size, cachep->align);
if (FREELIST_BYTE_INDEX && size < SLAB_OBJ_MIN_SIZE)
size = ALIGN(SLAB_OBJ_MIN_SIZE, cachep->align);
left_over = calculate_slab_order(cachep, size, cachep->align, flags);
if (!cachep->num)
return -E2BIG;
freelist_size = calculate_freelist_size(cachep->num, cachep->align);
if (flags & CFLGS_OFF_SLAB && left_over >= freelist_size) {
flags &= ~CFLGS_OFF_SLAB;
left_over -= freelist_size;
}
if (flags & CFLGS_OFF_SLAB) {
freelist_size = calculate_freelist_size(cachep->num, 0);
#ifdef CONFIG_PAGE_POISONING
if (size % PAGE_SIZE == 0 && flags & SLAB_POISON)
flags &= ~(SLAB_RED_ZONE | SLAB_STORE_USER);
#endif
}
cachep->colour_off = cache_line_size();
if (cachep->colour_off < cachep->align)
cachep->colour_off = cachep->align;
cachep->colour = left_over / cachep->colour_off;
cachep->freelist_size = freelist_size;
cachep->flags = flags;
cachep->allocflags = __GFP_COMP;
if (CONFIG_ZONE_DMA_FLAG && (flags & SLAB_CACHE_DMA))
cachep->allocflags |= GFP_DMA;
cachep->size = size;
cachep->reciprocal_buffer_size = reciprocal_value(size);
if (flags & CFLGS_OFF_SLAB) {
cachep->freelist_cache = kmalloc_slab(freelist_size, 0u);
BUG_ON(ZERO_OR_NULL_PTR(cachep->freelist_cache));
}
err = setup_cpu_cache(cachep, gfp);
if (err) {
__kmem_cache_shutdown(cachep);
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
on_each_cpu(do_drain, cachep, 1);
check_irq_on();
for_each_kmem_cache_node(cachep, node, n)
if (n->alien)
drain_alien_cache(cachep, n->alien);
for_each_kmem_cache_node(cachep, node, n)
drain_array(cachep, n, n->shared, 1, node);
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
#if DEBUG
BUG_ON(page->active);
#endif
list_del(&page->lru);
n->free_objects -= cache->num;
spin_unlock_irq(&n->list_lock);
slab_destroy(cache, page);
nr_freed++;
}
out:
return nr_freed;
}
int __kmem_cache_shrink(struct kmem_cache *cachep, bool deactivate)
{
int ret = 0;
int node;
struct kmem_cache_node *n;
drain_cpu_caches(cachep);
check_irq_on();
for_each_kmem_cache_node(cachep, node, n) {
drain_freelist(cachep, n, slabs_tofree(cachep, n));
ret += !list_empty(&n->slabs_full) ||
!list_empty(&n->slabs_partial);
}
return (ret ? 1 : 0);
}
int __kmem_cache_shutdown(struct kmem_cache *cachep)
{
int i;
struct kmem_cache_node *n;
int rc = __kmem_cache_shrink(cachep, false);
if (rc)
return rc;
free_percpu(cachep->cpu_cache);
for_each_kmem_cache_node(cachep, i, n) {
kfree(n->shared);
free_alien_cache(n->alien);
kfree(n);
cachep->node[i] = NULL;
}
return 0;
}
static void *alloc_slabmgmt(struct kmem_cache *cachep,
struct page *page, int colour_off,
gfp_t local_flags, int nodeid)
{
void *freelist;
void *addr = page_address(page);
if (OFF_SLAB(cachep)) {
freelist = kmem_cache_alloc_node(cachep->freelist_cache,
local_flags, nodeid);
if (!freelist)
return NULL;
} else {
freelist = addr + colour_off;
colour_off += cachep->freelist_size;
}
page->active = 0;
page->s_mem = addr + colour_off;
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
static void cache_init_objs(struct kmem_cache *cachep,
struct page *page)
{
int i;
for (i = 0; i < cachep->num; i++) {
void *objp = index_to_obj(cachep, page, i);
#if DEBUG
if (cachep->flags & SLAB_POISON)
poison_obj(cachep, objp, POISON_FREE);
if (cachep->flags & SLAB_STORE_USER)
*dbg_userword(cachep, objp) = NULL;
if (cachep->flags & SLAB_RED_ZONE) {
*dbg_redzone1(cachep, objp) = RED_INACTIVE;
*dbg_redzone2(cachep, objp) = RED_INACTIVE;
}
if (cachep->ctor && !(cachep->flags & SLAB_POISON))
cachep->ctor(objp + obj_offset(cachep));
if (cachep->flags & SLAB_RED_ZONE) {
if (*dbg_redzone2(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "constructor overwrote the"
" end of an object");
if (*dbg_redzone1(cachep, objp) != RED_INACTIVE)
slab_error(cachep, "constructor overwrote the"
" start of an object");
}
if ((cachep->size % PAGE_SIZE) == 0 &&
OFF_SLAB(cachep) && cachep->flags & SLAB_POISON)
kernel_map_pages(virt_to_page(objp),
cachep->size / PAGE_SIZE, 0);
#else
if (cachep->ctor)
cachep->ctor(objp);
#endif
set_obj_status(page, i, OBJECT_FREE);
set_free_obj(page, i, i);
}
}
static void kmem_flagcheck(struct kmem_cache *cachep, gfp_t flags)
{
if (CONFIG_ZONE_DMA_FLAG) {
if (flags & GFP_DMA)
BUG_ON(!(cachep->allocflags & GFP_DMA));
else
BUG_ON(cachep->allocflags & GFP_DMA);
}
}
static void *slab_get_obj(struct kmem_cache *cachep, struct page *page,
int nodeid)
{
void *objp;
objp = index_to_obj(cachep, page, get_free_obj(page, page->active));
page->active++;
#if DEBUG
WARN_ON(page_to_nid(virt_to_page(objp)) != nodeid);
#endif
return objp;
}
static void slab_put_obj(struct kmem_cache *cachep, struct page *page,
void *objp, int nodeid)
{
unsigned int objnr = obj_to_index(cachep, page, objp);
#if DEBUG
unsigned int i;
WARN_ON(page_to_nid(virt_to_page(objp)) != nodeid);
for (i = page->active; i < cachep->num; i++) {
if (get_free_obj(page, i) == objnr) {
printk(KERN_ERR "slab: double free detected in cache "
"'%s', objp %p\n", cachep->name, objp);
BUG();
}
}
#endif
page->active--;
set_free_obj(page, page->active, objnr);
}
static void slab_map_pages(struct kmem_cache *cache, struct page *page,
void *freelist)
{
page->slab_cache = cache;
page->freelist = freelist;
}
static int cache_grow(struct kmem_cache *cachep,
gfp_t flags, int nodeid, struct page *page)
{
void *freelist;
size_t offset;
gfp_t local_flags;
struct kmem_cache_node *n;
if (unlikely(flags & GFP_SLAB_BUG_MASK)) {
pr_emerg("gfp: %u\n", flags & GFP_SLAB_BUG_MASK);
BUG();
}
local_flags = flags & (GFP_CONSTRAINT_MASK|GFP_RECLAIM_MASK);
check_irq_off();
n = get_node(cachep, nodeid);
spin_lock(&n->list_lock);
offset = n->colour_next;
n->colour_next++;
if (n->colour_next >= cachep->colour)
n->colour_next = 0;
spin_unlock(&n->list_lock);
offset *= cachep->colour_off;
if (local_flags & __GFP_WAIT)
local_irq_enable();
kmem_flagcheck(cachep, flags);
if (!page)
page = kmem_getpages(cachep, local_flags, nodeid);
if (!page)
goto failed;
freelist = alloc_slabmgmt(cachep, page, offset,
local_flags & ~GFP_CONSTRAINT_MASK, nodeid);
if (!freelist)
goto opps1;
slab_map_pages(cachep, page, freelist);
cache_init_objs(cachep, page);
if (local_flags & __GFP_WAIT)
local_irq_disable();
check_irq_off();
spin_lock(&n->list_lock);
list_add_tail(&page->lru, &(n->slabs_free));
STATS_INC_GROWN(cachep);
n->free_objects += cachep->num;
spin_unlock(&n->list_lock);
return 1;
opps1:
kmem_freepages(cachep, page);
failed:
if (local_flags & __GFP_WAIT)
local_irq_disable();
return 0;
}
static void kfree_debugcheck(const void *objp)
{
if (!virt_addr_valid(objp)) {
printk(KERN_ERR "kfree_debugcheck: out of range ptr %lxh.\n",
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
printk(KERN_ERR "%p: redzone 1:0x%llx, redzone 2:0x%llx.\n",
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
if (cachep->flags & SLAB_STORE_USER)
*dbg_userword(cachep, objp) = (void *)caller;
objnr = obj_to_index(cachep, page, objp);
BUG_ON(objnr >= cachep->num);
BUG_ON(objp != index_to_obj(cachep, page, objnr));
set_obj_status(page, objnr, OBJECT_FREE);
if (cachep->flags & SLAB_POISON) {
#ifdef CONFIG_DEBUG_PAGEALLOC
if ((cachep->size % PAGE_SIZE)==0 && OFF_SLAB(cachep)) {
store_stackinfo(cachep, objp, caller);
kernel_map_pages(virt_to_page(objp),
cachep->size / PAGE_SIZE, 0);
} else {
poison_obj(cachep, objp, POISON_FREE);
}
#else
poison_obj(cachep, objp, POISON_FREE);
#endif
}
return objp;
}
static void *cache_alloc_refill(struct kmem_cache *cachep, gfp_t flags,
bool force_refill)
{
int batchcount;
struct kmem_cache_node *n;
struct array_cache *ac;
int node;
check_irq_off();
node = numa_mem_id();
if (unlikely(force_refill))
goto force_grow;
retry:
ac = cpu_cache_get(cachep);
batchcount = ac->batchcount;
if (!ac->touched && batchcount > BATCHREFILL_LIMIT) {
batchcount = BATCHREFILL_LIMIT;
}
n = get_node(cachep, node);
BUG_ON(ac->avail > 0 || !n);
spin_lock(&n->list_lock);
if (n->shared && transfer_objects(ac, n->shared, batchcount)) {
n->shared->touched = 1;
goto alloc_done;
}
while (batchcount > 0) {
struct list_head *entry;
struct page *page;
entry = n->slabs_partial.next;
if (entry == &n->slabs_partial) {
n->free_touched = 1;
entry = n->slabs_free.next;
if (entry == &n->slabs_free)
goto must_grow;
}
page = list_entry(entry, struct page, lru);
check_spinlock_acquired(cachep);
BUG_ON(page->active >= cachep->num);
while (page->active < cachep->num && batchcount--) {
STATS_INC_ALLOCED(cachep);
STATS_INC_ACTIVE(cachep);
STATS_SET_HIGH(cachep);
ac_put_obj(cachep, ac, slab_get_obj(cachep, page,
node));
}
list_del(&page->lru);
if (page->active == cachep->num)
list_add(&page->lru, &n->slabs_full);
else
list_add(&page->lru, &n->slabs_partial);
}
must_grow:
n->free_objects -= ac->avail;
alloc_done:
spin_unlock(&n->list_lock);
if (unlikely(!ac->avail)) {
int x;
force_grow:
x = cache_grow(cachep, flags | GFP_THISNODE, node, NULL);
ac = cpu_cache_get(cachep);
node = numa_mem_id();
if (!x && (ac->avail == 0 || force_refill))
return NULL;
if (!ac->avail)
goto retry;
}
ac->touched = 1;
return ac_get_obj(cachep, ac, flags, force_refill);
}
static inline void cache_alloc_debugcheck_before(struct kmem_cache *cachep,
gfp_t flags)
{
might_sleep_if(flags & __GFP_WAIT);
#if DEBUG
kmem_flagcheck(cachep, flags);
#endif
}
static void *cache_alloc_debugcheck_after(struct kmem_cache *cachep,
gfp_t flags, void *objp, unsigned long caller)
{
struct page *page;
if (!objp)
return objp;
if (cachep->flags & SLAB_POISON) {
#ifdef CONFIG_DEBUG_PAGEALLOC
if ((cachep->size % PAGE_SIZE) == 0 && OFF_SLAB(cachep))
kernel_map_pages(virt_to_page(objp),
cachep->size / PAGE_SIZE, 1);
else
check_poison_obj(cachep, objp);
#else
check_poison_obj(cachep, objp);
#endif
poison_obj(cachep, objp, POISON_INUSE);
}
if (cachep->flags & SLAB_STORE_USER)
*dbg_userword(cachep, objp) = (void *)caller;
if (cachep->flags & SLAB_RED_ZONE) {
if (*dbg_redzone1(cachep, objp) != RED_INACTIVE ||
*dbg_redzone2(cachep, objp) != RED_INACTIVE) {
slab_error(cachep, "double free, or memory outside"
" object was overwritten");
printk(KERN_ERR
"%p: redzone 1:0x%llx, redzone 2:0x%llx\n",
objp, *dbg_redzone1(cachep, objp),
*dbg_redzone2(cachep, objp));
}
*dbg_redzone1(cachep, objp) = RED_ACTIVE;
*dbg_redzone2(cachep, objp) = RED_ACTIVE;
}
page = virt_to_head_page(objp);
set_obj_status(page, obj_to_index(cachep, page, objp), OBJECT_ACTIVE);
objp += obj_offset(cachep);
if (cachep->ctor && cachep->flags & SLAB_POISON)
cachep->ctor(objp);
if (ARCH_SLAB_MINALIGN &&
((unsigned long)objp & (ARCH_SLAB_MINALIGN-1))) {
printk(KERN_ERR "0x%p: not aligned to ARCH_SLAB_MINALIGN=%d\n",
objp, (int)ARCH_SLAB_MINALIGN);
}
return objp;
}
static bool slab_should_failslab(struct kmem_cache *cachep, gfp_t flags)
{
if (unlikely(cachep == kmem_cache))
return false;
return should_failslab(cachep->object_size, flags, cachep->flags);
}
static inline void *____cache_alloc(struct kmem_cache *cachep, gfp_t flags)
{
void *objp;
struct array_cache *ac;
bool force_refill = false;
check_irq_off();
ac = cpu_cache_get(cachep);
if (likely(ac->avail)) {
ac->touched = 1;
objp = ac_get_obj(cachep, ac, flags, false);
if (objp) {
STATS_INC_ALLOCHIT(cachep);
goto out;
}
force_refill = true;
}
STATS_INC_ALLOCMISS(cachep);
objp = cache_alloc_refill(cachep, flags, force_refill);
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
gfp_t local_flags;
struct zoneref *z;
struct zone *zone;
enum zone_type high_zoneidx = gfp_zone(flags);
void *obj = NULL;
int nid;
unsigned int cpuset_mems_cookie;
if (flags & __GFP_THISNODE)
return NULL;
local_flags = flags & (GFP_CONSTRAINT_MASK|GFP_RECLAIM_MASK);
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
flags | GFP_THISNODE, nid);
if (obj)
break;
}
}
if (!obj) {
struct page *page;
if (local_flags & __GFP_WAIT)
local_irq_enable();
kmem_flagcheck(cache, flags);
page = kmem_getpages(cache, local_flags, numa_mem_id());
if (local_flags & __GFP_WAIT)
local_irq_disable();
if (page) {
nid = page_to_nid(page);
if (cache_grow(cache, flags, nid, page)) {
obj = ____cache_alloc_node(cache,
flags | GFP_THISNODE, nid);
if (!obj)
goto retry;
} else {
obj = NULL;
}
}
}
if (unlikely(!obj && read_mems_allowed_retry(cpuset_mems_cookie)))
goto retry_cpuset;
return obj;
}
static void *____cache_alloc_node(struct kmem_cache *cachep, gfp_t flags,
int nodeid)
{
struct list_head *entry;
struct page *page;
struct kmem_cache_node *n;
void *obj;
int x;
VM_BUG_ON(nodeid < 0 || nodeid >= MAX_NUMNODES);
n = get_node(cachep, nodeid);
BUG_ON(!n);
retry:
check_irq_off();
spin_lock(&n->list_lock);
entry = n->slabs_partial.next;
if (entry == &n->slabs_partial) {
n->free_touched = 1;
entry = n->slabs_free.next;
if (entry == &n->slabs_free)
goto must_grow;
}
page = list_entry(entry, struct page, lru);
check_spinlock_acquired_node(cachep, nodeid);
STATS_INC_NODEALLOCS(cachep);
STATS_INC_ACTIVE(cachep);
STATS_SET_HIGH(cachep);
BUG_ON(page->active == cachep->num);
obj = slab_get_obj(cachep, page, nodeid);
n->free_objects--;
list_del(&page->lru);
if (page->active == cachep->num)
list_add(&page->lru, &n->slabs_full);
else
list_add(&page->lru, &n->slabs_partial);
spin_unlock(&n->list_lock);
goto done;
must_grow:
spin_unlock(&n->list_lock);
x = cache_grow(cachep, flags | GFP_THISNODE, nodeid, NULL);
if (x)
goto retry;
return fallback_alloc(cachep, flags);
done:
return obj;
}
static __always_inline void *
slab_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid,
unsigned long caller)
{
unsigned long save_flags;
void *ptr;
int slab_node = numa_mem_id();
flags &= gfp_allowed_mask;
lockdep_trace_alloc(flags);
if (slab_should_failslab(cachep, flags))
return NULL;
cachep = memcg_kmem_get_cache(cachep, flags);
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
kmemleak_alloc_recursive(ptr, cachep->object_size, 1, cachep->flags,
flags);
if (likely(ptr)) {
kmemcheck_slab_alloc(cachep, flags, ptr, cachep->object_size);
if (unlikely(flags & __GFP_ZERO))
memset(ptr, 0, cachep->object_size);
}
memcg_kmem_put_cache(cachep);
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
lockdep_trace_alloc(flags);
if (slab_should_failslab(cachep, flags))
return NULL;
cachep = memcg_kmem_get_cache(cachep, flags);
cache_alloc_debugcheck_before(cachep, flags);
local_irq_save(save_flags);
objp = __do_cache_alloc(cachep, flags);
local_irq_restore(save_flags);
objp = cache_alloc_debugcheck_after(cachep, flags, objp, caller);
kmemleak_alloc_recursive(objp, cachep->object_size, 1, cachep->flags,
flags);
prefetchw(objp);
if (likely(objp)) {
kmemcheck_slab_alloc(cachep, flags, objp, cachep->object_size);
if (unlikely(flags & __GFP_ZERO))
memset(objp, 0, cachep->object_size);
}
memcg_kmem_put_cache(cachep);
return objp;
}
static void free_block(struct kmem_cache *cachep, void **objpp,
int nr_objects, int node, struct list_head *list)
{
int i;
struct kmem_cache_node *n = get_node(cachep, node);
for (i = 0; i < nr_objects; i++) {
void *objp;
struct page *page;
clear_obj_pfmemalloc(&objpp[i]);
objp = objpp[i];
page = virt_to_head_page(objp);
list_del(&page->lru);
check_spinlock_acquired_node(cachep, node);
slab_put_obj(cachep, page, objp, node);
STATS_DEC_ACTIVE(cachep);
n->free_objects++;
if (page->active == 0) {
if (n->free_objects > n->free_limit) {
n->free_objects -= cachep->num;
list_add_tail(&page->lru, list);
} else {
list_add(&page->lru, &n->slabs_free);
}
} else {
list_add_tail(&page->lru, &n->slabs_partial);
}
}
}
static void cache_flusharray(struct kmem_cache *cachep, struct array_cache *ac)
{
int batchcount;
struct kmem_cache_node *n;
int node = numa_mem_id();
LIST_HEAD(list);
batchcount = ac->batchcount;
#if DEBUG
BUG_ON(!batchcount || batchcount > ac->avail);
#endif
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
struct list_head *p;
p = n->slabs_free.next;
while (p != &(n->slabs_free)) {
struct page *page;
page = list_entry(p, struct page, lru);
BUG_ON(page->active);
i++;
p = p->next;
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
ac_put_obj(cachep, ac, objp);
}
void *kmem_cache_alloc(struct kmem_cache *cachep, gfp_t flags)
{
void *ret = slab_alloc(cachep, flags, _RET_IP_);
trace_kmem_cache_alloc(_RET_IP_, ret,
cachep->object_size, cachep->size, flags);
return ret;
}
void *
kmem_cache_alloc_trace(struct kmem_cache *cachep, gfp_t flags, size_t size)
{
void *ret;
ret = slab_alloc(cachep, flags, _RET_IP_);
trace_kmalloc(_RET_IP_, ret,
size, cachep->size, flags);
return ret;
}
void *kmem_cache_alloc_node(struct kmem_cache *cachep, gfp_t flags, int nodeid)
{
void *ret = slab_alloc_node(cachep, flags, nodeid, _RET_IP_);
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
trace_kmalloc_node(_RET_IP_, ret,
size, cachep->size,
flags, nodeid);
return ret;
}
static __always_inline void *
__do_kmalloc_node(size_t size, gfp_t flags, int node, unsigned long caller)
{
struct kmem_cache *cachep;
cachep = kmalloc_slab(size, flags);
if (unlikely(ZERO_OR_NULL_PTR(cachep)))
return cachep;
return kmem_cache_alloc_node_trace(cachep, flags, node, size);
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
static int alloc_kmem_cache_node(struct kmem_cache *cachep, gfp_t gfp)
{
int node;
struct kmem_cache_node *n;
struct array_cache *new_shared;
struct alien_cache **new_alien = NULL;
for_each_online_node(node) {
if (use_alien_caches) {
new_alien = alloc_alien_cache(node, cachep->limit, gfp);
if (!new_alien)
goto fail;
}
new_shared = NULL;
if (cachep->shared) {
new_shared = alloc_arraycache(node,
cachep->shared*cachep->batchcount,
0xbaadf00d, gfp);
if (!new_shared) {
free_alien_cache(new_alien);
goto fail;
}
}
n = get_node(cachep, node);
if (n) {
struct array_cache *shared = n->shared;
LIST_HEAD(list);
spin_lock_irq(&n->list_lock);
if (shared)
free_block(cachep, shared->entry,
shared->avail, node, &list);
n->shared = new_shared;
if (!n->alien) {
n->alien = new_alien;
new_alien = NULL;
}
n->free_limit = (1 + nr_cpus_node(node)) *
cachep->batchcount + cachep->num;
spin_unlock_irq(&n->list_lock);
slabs_destroy(cachep, &list);
kfree(shared);
free_alien_cache(new_alien);
continue;
}
n = kmalloc_node(sizeof(struct kmem_cache_node), gfp, node);
if (!n) {
free_alien_cache(new_alien);
kfree(new_shared);
goto fail;
}
kmem_cache_node_init(n);
n->next_reap = jiffies + REAPTIMEOUT_NODE +
((unsigned long)cachep) % REAPTIMEOUT_NODE;
n->shared = new_shared;
n->alien = new_alien;
n->free_limit = (1 + nr_cpus_node(node)) *
cachep->batchcount + cachep->num;
cachep->node[node] = n;
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
kick_all_cpus_sync();
check_irq_on();
cachep->batchcount = batchcount;
cachep->limit = limit;
cachep->shared = shared;
if (!prev)
goto alloc_node;
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
alloc_node:
return alloc_kmem_cache_node(cachep, gfp);
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
if (err)
printk(KERN_ERR "enable_cpucache failed for %s, error %d.\n",
cachep->name, -err);
return err;
}
static void drain_array(struct kmem_cache *cachep, struct kmem_cache_node *n,
struct array_cache *ac, int force, int node)
{
LIST_HEAD(list);
int tofree;
if (!ac || !ac->avail)
return;
if (ac->touched && !force) {
ac->touched = 0;
} else {
spin_lock_irq(&n->list_lock);
if (ac->avail) {
tofree = force ? ac->avail : (ac->limit + 4) / 5;
if (tofree > ac->avail)
tofree = (ac->avail + 1) / 2;
free_block(cachep, ac->entry, tofree, node, &list);
ac->avail -= tofree;
memmove(ac->entry, &(ac->entry[tofree]),
sizeof(void *) * ac->avail);
}
spin_unlock_irq(&n->list_lock);
slabs_destroy(cachep, &list);
}
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
drain_array(searchp, n, cpu_cache_get(searchp), 0, node);
if (time_after(n->next_reap, jiffies))
goto next;
n->next_reap = jiffies + REAPTIMEOUT_NODE;
drain_array(searchp, n, n->shared, 0, node);
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
struct page *page;
unsigned long active_objs;
unsigned long num_objs;
unsigned long active_slabs = 0;
unsigned long num_slabs, free_objects = 0, shared_avail = 0;
const char *name;
char *error = NULL;
int node;
struct kmem_cache_node *n;
active_objs = 0;
num_slabs = 0;
for_each_kmem_cache_node(cachep, node, n) {
check_irq_on();
spin_lock_irq(&n->list_lock);
list_for_each_entry(page, &n->slabs_full, lru) {
if (page->active != cachep->num && !error)
error = "slabs_full accounting error";
active_objs += cachep->num;
active_slabs++;
}
list_for_each_entry(page, &n->slabs_partial, lru) {
if (page->active == cachep->num && !error)
error = "slabs_partial accounting error";
if (!page->active && !error)
error = "slabs_partial accounting error";
active_objs += page->active;
active_slabs++;
}
list_for_each_entry(page, &n->slabs_free, lru) {
if (page->active && !error)
error = "slabs_free accounting error";
num_slabs++;
}
free_objects += n->free_objects;
if (n->shared)
shared_avail += n->shared->avail;
spin_unlock_irq(&n->list_lock);
}
num_slabs += active_slabs;
num_objs = num_slabs * cachep->num;
if (num_objs - active_objs != free_objects && !error)
error = "free_objects accounting error";
name = cachep->name;
if (error)
printk(KERN_ERR "slab: cache %s error: %s\n", name, error);
sinfo->active_objs = active_objs;
sinfo->num_objs = num_objs;
sinfo->active_slabs = active_slabs;
sinfo->num_slabs = num_slabs;
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
seq_printf(m, " : globalstat %7lu %6lu %5lu %4lu "
"%4lu %4lu %4lu %4lu %4lu",
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
int i;
if (n[0] == n[1])
return;
for (i = 0, p = page->s_mem; i < c->num; i++, p += c->size) {
if (get_obj_status(page, i) != OBJECT_ACTIVE)
continue;
if (!add_caller(n, (unsigned long)*dbg_userword(c, p)))
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
size_t ksize(const void *objp)
{
BUG_ON(!objp);
if (unlikely(objp == ZERO_SIZE_PTR))
return 0;
return virt_to_cache(objp)->object_size;
}
