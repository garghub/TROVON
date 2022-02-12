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
static __always_inline int index_of(const size_t size)
{
extern void __bad_size(void);
if (__builtin_constant_p(size)) {
int i = 0;
#define CACHE(x) \
if (size <=x) \
return i; \
else \
i++;
#include <linux/kmalloc_sizes.h>
#undef CACHE
__bad_size();
} else
__bad_size();
return 0;
}
static void kmem_list3_init(struct kmem_list3 *parent)
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
static inline struct kmem_cache *virt_to_cache(const void *obj)
{
struct page *page = virt_to_head_page(obj);
return page->slab_cache;
}
static inline struct slab *virt_to_slab(const void *obj)
{
struct page *page = virt_to_head_page(obj);
VM_BUG_ON(!PageSlab(page));
return page->slab_page;
}
static inline void *index_to_obj(struct kmem_cache *cache, struct slab *slab,
unsigned int idx)
{
return slab->s_mem + cache->size * idx;
}
static inline unsigned int obj_to_index(const struct kmem_cache *cache,
const struct slab *slab, void *obj)
{
u32 offset = (obj - slab->s_mem);
return reciprocal_divide(offset, cache->reciprocal_buffer_size);
}
static void slab_set_lock_classes(struct kmem_cache *cachep,
struct lock_class_key *l3_key, struct lock_class_key *alc_key,
int q)
{
struct array_cache **alc;
struct kmem_list3 *l3;
int r;
l3 = cachep->nodelists[q];
if (!l3)
return;
lockdep_set_class(&l3->list_lock, l3_key);
alc = l3->alien;
if (!alc || (unsigned long)alc == BAD_ALIEN_MAGIC)
return;
for_each_node(r) {
if (alc[r])
lockdep_set_class(&alc[r]->lock, alc_key);
}
}
static void slab_set_debugobj_lock_classes_node(struct kmem_cache *cachep, int node)
{
slab_set_lock_classes(cachep, &debugobj_l3_key, &debugobj_alc_key, node);
}
static void slab_set_debugobj_lock_classes(struct kmem_cache *cachep)
{
int node;
for_each_online_node(node)
slab_set_debugobj_lock_classes_node(cachep, node);
}
static void init_node_lock_keys(int q)
{
struct cache_sizes *s = malloc_sizes;
if (slab_state < UP)
return;
for (s = malloc_sizes; s->cs_size != ULONG_MAX; s++) {
struct kmem_list3 *l3;
l3 = s->cs_cachep->nodelists[q];
if (!l3 || OFF_SLAB(s->cs_cachep))
continue;
slab_set_lock_classes(s->cs_cachep, &on_slab_l3_key,
&on_slab_alc_key, q);
}
}
static inline void init_lock_keys(void)
{
int node;
for_each_node(node)
init_node_lock_keys(node);
}
static void init_node_lock_keys(int q)
{
}
static inline void init_lock_keys(void)
{
}
static void slab_set_debugobj_lock_classes_node(struct kmem_cache *cachep, int node)
{
}
static void slab_set_debugobj_lock_classes(struct kmem_cache *cachep)
{
}
static inline struct array_cache *cpu_cache_get(struct kmem_cache *cachep)
{
return cachep->array[smp_processor_id()];
}
static inline struct kmem_cache *__find_general_cachep(size_t size,
gfp_t gfpflags)
{
struct cache_sizes *csizep = malloc_sizes;
#if DEBUG
BUG_ON(malloc_sizes[INDEX_AC].cs_cachep == NULL);
#endif
if (!size)
return ZERO_SIZE_PTR;
while (size > csizep->cs_size)
csizep++;
#ifdef CONFIG_ZONE_DMA
if (unlikely(gfpflags & GFP_DMA))
return csizep->cs_dmacachep;
#endif
return csizep->cs_cachep;
}
static struct kmem_cache *kmem_find_general_cachep(size_t size, gfp_t gfpflags)
{
return __find_general_cachep(size, gfpflags);
}
static size_t slab_mgmt_size(size_t nr_objs, size_t align)
{
return ALIGN(sizeof(struct slab)+nr_objs*sizeof(kmem_bufctl_t), align);
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
if (nr_objs > SLAB_LIMIT)
nr_objs = SLAB_LIMIT;
} else {
nr_objs = (slab_size - sizeof(struct slab)) /
(buffer_size + sizeof(kmem_bufctl_t));
if (slab_mgmt_size(nr_objs, align) + nr_objs*buffer_size
> slab_size)
nr_objs--;
if (nr_objs > SLAB_LIMIT)
nr_objs = SLAB_LIMIT;
mgmt_size = slab_mgmt_size(nr_objs, align);
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
add_taint(TAINT_BAD_PAGE);
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
static void __cpuinit start_cpu_timer(int cpu)
{
struct delayed_work *reap_work = &per_cpu(slab_reap_work, cpu);
if (keventd_up() && reap_work->work.func == NULL) {
init_reap_node(cpu);
INIT_DEFERRABLE_WORK(reap_work, cache_reap);
schedule_delayed_work_on(cpu, reap_work,
__round_jiffies_relative(HZ, cpu));
}
}
static struct array_cache *alloc_arraycache(int node, int entries,
int batchcount, gfp_t gfp)
{
int memsize = sizeof(void *) * entries + sizeof(struct array_cache);
struct array_cache *nc = NULL;
nc = kmalloc_node(memsize, gfp, node);
kmemleak_no_scan(nc);
if (nc) {
nc->avail = 0;
nc->limit = entries;
nc->batchcount = batchcount;
nc->touched = 0;
spin_lock_init(&nc->lock);
}
return nc;
}
static inline bool is_slab_pfmemalloc(struct slab *slabp)
{
struct page *page = virt_to_page(slabp->s_mem);
return PageSlabPfmemalloc(page);
}
static void recheck_pfmemalloc_active(struct kmem_cache *cachep,
struct array_cache *ac)
{
struct kmem_list3 *l3 = cachep->nodelists[numa_mem_id()];
struct slab *slabp;
unsigned long flags;
if (!pfmemalloc_active)
return;
spin_lock_irqsave(&l3->list_lock, flags);
list_for_each_entry(slabp, &l3->slabs_full, list)
if (is_slab_pfmemalloc(slabp))
goto out;
list_for_each_entry(slabp, &l3->slabs_partial, list)
if (is_slab_pfmemalloc(slabp))
goto out;
list_for_each_entry(slabp, &l3->slabs_free, list)
if (is_slab_pfmemalloc(slabp))
goto out;
pfmemalloc_active = false;
out:
spin_unlock_irqrestore(&l3->list_lock, flags);
}
static void *__ac_get_obj(struct kmem_cache *cachep, struct array_cache *ac,
gfp_t flags, bool force_refill)
{
int i;
void *objp = ac->entry[--ac->avail];
if (unlikely(is_obj_pfmemalloc(objp))) {
struct kmem_list3 *l3;
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
l3 = cachep->nodelists[numa_mem_id()];
if (!list_empty(&l3->slabs_free) && force_refill) {
struct slab *slabp = virt_to_slab(objp);
ClearPageSlabPfmemalloc(virt_to_head_page(slabp->s_mem));
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
static void *__ac_put_obj(struct kmem_cache *cachep, struct array_cache *ac,
void *objp)
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
static inline struct array_cache **alloc_alien_cache(int node, int limit, gfp_t gfp)
{
return (struct array_cache **)BAD_ALIEN_MAGIC;
}
static inline void free_alien_cache(struct array_cache **ac_ptr)
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
static struct array_cache **alloc_alien_cache(int node, int limit, gfp_t gfp)
{
struct array_cache **ac_ptr;
int memsize = sizeof(void *) * nr_node_ids;
int i;
if (limit > 1)
limit = 12;
ac_ptr = kzalloc_node(memsize, gfp, node);
if (ac_ptr) {
for_each_node(i) {
if (i == node || !node_online(i))
continue;
ac_ptr[i] = alloc_arraycache(node, limit, 0xbaadf00d, gfp);
if (!ac_ptr[i]) {
for (i--; i >= 0; i--)
kfree(ac_ptr[i]);
kfree(ac_ptr);
return NULL;
}
}
}
return ac_ptr;
}
static void free_alien_cache(struct array_cache **ac_ptr)
{
int i;
if (!ac_ptr)
return;
for_each_node(i)
kfree(ac_ptr[i]);
kfree(ac_ptr);
}
static void __drain_alien_cache(struct kmem_cache *cachep,
struct array_cache *ac, int node)
{
struct kmem_list3 *rl3 = cachep->nodelists[node];
if (ac->avail) {
spin_lock(&rl3->list_lock);
if (rl3->shared)
transfer_objects(rl3->shared, ac, ac->limit);
free_block(cachep, ac->entry, ac->avail, node);
ac->avail = 0;
spin_unlock(&rl3->list_lock);
}
}
static void reap_alien(struct kmem_cache *cachep, struct kmem_list3 *l3)
{
int node = __this_cpu_read(slab_reap_node);
if (l3->alien) {
struct array_cache *ac = l3->alien[node];
if (ac && ac->avail && spin_trylock_irq(&ac->lock)) {
__drain_alien_cache(cachep, ac, node);
spin_unlock_irq(&ac->lock);
}
}
}
static void drain_alien_cache(struct kmem_cache *cachep,
struct array_cache **alien)
{
int i = 0;
struct array_cache *ac;
unsigned long flags;
for_each_online_node(i) {
ac = alien[i];
if (ac) {
spin_lock_irqsave(&ac->lock, flags);
__drain_alien_cache(cachep, ac, i);
spin_unlock_irqrestore(&ac->lock, flags);
}
}
}
static inline int cache_free_alien(struct kmem_cache *cachep, void *objp)
{
struct slab *slabp = virt_to_slab(objp);
int nodeid = slabp->nodeid;
struct kmem_list3 *l3;
struct array_cache *alien = NULL;
int node;
node = numa_mem_id();
if (likely(slabp->nodeid == node))
return 0;
l3 = cachep->nodelists[node];
STATS_INC_NODEFREES(cachep);
if (l3->alien && l3->alien[nodeid]) {
alien = l3->alien[nodeid];
spin_lock(&alien->lock);
if (unlikely(alien->avail == alien->limit)) {
STATS_INC_ACOVERFLOW(cachep);
__drain_alien_cache(cachep, alien, nodeid);
}
ac_put_obj(cachep, alien, objp);
spin_unlock(&alien->lock);
} else {
spin_lock(&(cachep->nodelists[nodeid])->list_lock);
free_block(cachep, &objp, 1, nodeid);
spin_unlock(&(cachep->nodelists[nodeid])->list_lock);
}
return 1;
}
static int init_cache_nodelists_node(int node)
{
struct kmem_cache *cachep;
struct kmem_list3 *l3;
const int memsize = sizeof(struct kmem_list3);
list_for_each_entry(cachep, &slab_caches, list) {
if (!cachep->nodelists[node]) {
l3 = kmalloc_node(memsize, GFP_KERNEL, node);
if (!l3)
return -ENOMEM;
kmem_list3_init(l3);
l3->next_reap = jiffies + REAPTIMEOUT_LIST3 +
((unsigned long)cachep) % REAPTIMEOUT_LIST3;
cachep->nodelists[node] = l3;
}
spin_lock_irq(&cachep->nodelists[node]->list_lock);
cachep->nodelists[node]->free_limit =
(1 + nr_cpus_node(node)) *
cachep->batchcount + cachep->num;
spin_unlock_irq(&cachep->nodelists[node]->list_lock);
}
return 0;
}
static void __cpuinit cpuup_canceled(long cpu)
{
struct kmem_cache *cachep;
struct kmem_list3 *l3 = NULL;
int node = cpu_to_mem(cpu);
const struct cpumask *mask = cpumask_of_node(node);
list_for_each_entry(cachep, &slab_caches, list) {
struct array_cache *nc;
struct array_cache *shared;
struct array_cache **alien;
nc = cachep->array[cpu];
cachep->array[cpu] = NULL;
l3 = cachep->nodelists[node];
if (!l3)
goto free_array_cache;
spin_lock_irq(&l3->list_lock);
l3->free_limit -= cachep->batchcount;
if (nc)
free_block(cachep, nc->entry, nc->avail, node);
if (!cpumask_empty(mask)) {
spin_unlock_irq(&l3->list_lock);
goto free_array_cache;
}
shared = l3->shared;
if (shared) {
free_block(cachep, shared->entry,
shared->avail, node);
l3->shared = NULL;
}
alien = l3->alien;
l3->alien = NULL;
spin_unlock_irq(&l3->list_lock);
kfree(shared);
if (alien) {
drain_alien_cache(cachep, alien);
free_alien_cache(alien);
}
free_array_cache:
kfree(nc);
}
list_for_each_entry(cachep, &slab_caches, list) {
l3 = cachep->nodelists[node];
if (!l3)
continue;
drain_freelist(cachep, l3, l3->free_objects);
}
}
static int __cpuinit cpuup_prepare(long cpu)
{
struct kmem_cache *cachep;
struct kmem_list3 *l3 = NULL;
int node = cpu_to_mem(cpu);
int err;
err = init_cache_nodelists_node(node);
if (err < 0)
goto bad;
list_for_each_entry(cachep, &slab_caches, list) {
struct array_cache *nc;
struct array_cache *shared = NULL;
struct array_cache **alien = NULL;
nc = alloc_arraycache(node, cachep->limit,
cachep->batchcount, GFP_KERNEL);
if (!nc)
goto bad;
if (cachep->shared) {
shared = alloc_arraycache(node,
cachep->shared * cachep->batchcount,
0xbaadf00d, GFP_KERNEL);
if (!shared) {
kfree(nc);
goto bad;
}
}
if (use_alien_caches) {
alien = alloc_alien_cache(node, cachep->limit, GFP_KERNEL);
if (!alien) {
kfree(shared);
kfree(nc);
goto bad;
}
}
cachep->array[cpu] = nc;
l3 = cachep->nodelists[node];
BUG_ON(!l3);
spin_lock_irq(&l3->list_lock);
if (!l3->shared) {
l3->shared = shared;
shared = NULL;
}
#ifdef CONFIG_NUMA
if (!l3->alien) {
l3->alien = alien;
alien = NULL;
}
#endif
spin_unlock_irq(&l3->list_lock);
kfree(shared);
free_alien_cache(alien);
if (cachep->flags & SLAB_DEBUG_OBJECTS)
slab_set_debugobj_lock_classes_node(cachep, node);
}
init_node_lock_keys(node);
return 0;
bad:
cpuup_canceled(cpu);
return -ENOMEM;
}
static int __cpuinit cpuup_callback(struct notifier_block *nfb,
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
static int __meminit drain_cache_nodelists_node(int node)
{
struct kmem_cache *cachep;
int ret = 0;
list_for_each_entry(cachep, &slab_caches, list) {
struct kmem_list3 *l3;
l3 = cachep->nodelists[node];
if (!l3)
continue;
drain_freelist(cachep, l3, l3->free_objects);
if (!list_empty(&l3->slabs_full) ||
!list_empty(&l3->slabs_partial)) {
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
ret = init_cache_nodelists_node(nid);
mutex_unlock(&slab_mutex);
break;
case MEM_GOING_OFFLINE:
mutex_lock(&slab_mutex);
ret = drain_cache_nodelists_node(nid);
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
static void __init init_list(struct kmem_cache *cachep, struct kmem_list3 *list,
int nodeid)
{
struct kmem_list3 *ptr;
ptr = kmalloc_node(sizeof(struct kmem_list3), GFP_NOWAIT, nodeid);
BUG_ON(!ptr);
memcpy(ptr, list, sizeof(struct kmem_list3));
spin_lock_init(&ptr->list_lock);
MAKE_ALL_LISTS(cachep, ptr, nodeid);
cachep->nodelists[nodeid] = ptr;
}
static void __init set_up_list3s(struct kmem_cache *cachep, int index)
{
int node;
for_each_online_node(node) {
cachep->nodelists[node] = &initkmem_list3[index + node];
cachep->nodelists[node]->next_reap = jiffies +
REAPTIMEOUT_LIST3 +
((unsigned long)cachep) % REAPTIMEOUT_LIST3;
}
}
void __init kmem_cache_init(void)
{
size_t left_over;
struct cache_sizes *sizes;
struct cache_names *names;
int i;
int order;
int node;
kmem_cache = &kmem_cache_boot;
if (num_possible_nodes() == 1)
use_alien_caches = 0;
for (i = 0; i < NUM_INIT_LISTS; i++) {
kmem_list3_init(&initkmem_list3[i]);
if (i < MAX_NUMNODES)
kmem_cache->nodelists[i] = NULL;
}
set_up_list3s(kmem_cache, CACHE_CACHE);
if (!slab_max_order_set && totalram_pages > (32 << 20) >> PAGE_SHIFT)
slab_max_order = SLAB_MAX_ORDER_HI;
node = numa_mem_id();
INIT_LIST_HEAD(&slab_caches);
list_add(&kmem_cache->list, &slab_caches);
kmem_cache->colour_off = cache_line_size();
kmem_cache->array[smp_processor_id()] = &initarray_cache.cache;
kmem_cache->nodelists[node] = &initkmem_list3[CACHE_CACHE + node];
kmem_cache->size = offsetof(struct kmem_cache, array[nr_cpu_ids]) +
nr_node_ids * sizeof(struct kmem_list3 *);
kmem_cache->object_size = kmem_cache->size;
kmem_cache->size = ALIGN(kmem_cache->object_size,
cache_line_size());
kmem_cache->reciprocal_buffer_size =
reciprocal_value(kmem_cache->size);
for (order = 0; order < MAX_ORDER; order++) {
cache_estimate(order, kmem_cache->size,
cache_line_size(), 0, &left_over, &kmem_cache->num);
if (kmem_cache->num)
break;
}
BUG_ON(!kmem_cache->num);
kmem_cache->gfporder = order;
kmem_cache->colour = left_over / kmem_cache->colour_off;
kmem_cache->slab_size = ALIGN(kmem_cache->num * sizeof(kmem_bufctl_t) +
sizeof(struct slab), cache_line_size());
sizes = malloc_sizes;
names = cache_names;
sizes[INDEX_AC].cs_cachep = kmem_cache_zalloc(kmem_cache, GFP_NOWAIT);
sizes[INDEX_AC].cs_cachep->name = names[INDEX_AC].name;
sizes[INDEX_AC].cs_cachep->size = sizes[INDEX_AC].cs_size;
sizes[INDEX_AC].cs_cachep->object_size = sizes[INDEX_AC].cs_size;
sizes[INDEX_AC].cs_cachep->align = ARCH_KMALLOC_MINALIGN;
__kmem_cache_create(sizes[INDEX_AC].cs_cachep, ARCH_KMALLOC_FLAGS|SLAB_PANIC);
list_add(&sizes[INDEX_AC].cs_cachep->list, &slab_caches);
if (INDEX_AC != INDEX_L3) {
sizes[INDEX_L3].cs_cachep = kmem_cache_zalloc(kmem_cache, GFP_NOWAIT);
sizes[INDEX_L3].cs_cachep->name = names[INDEX_L3].name;
sizes[INDEX_L3].cs_cachep->size = sizes[INDEX_L3].cs_size;
sizes[INDEX_L3].cs_cachep->object_size = sizes[INDEX_L3].cs_size;
sizes[INDEX_L3].cs_cachep->align = ARCH_KMALLOC_MINALIGN;
__kmem_cache_create(sizes[INDEX_L3].cs_cachep, ARCH_KMALLOC_FLAGS|SLAB_PANIC);
list_add(&sizes[INDEX_L3].cs_cachep->list, &slab_caches);
}
slab_early_init = 0;
while (sizes->cs_size != ULONG_MAX) {
if (!sizes->cs_cachep) {
sizes->cs_cachep = kmem_cache_zalloc(kmem_cache, GFP_NOWAIT);
sizes->cs_cachep->name = names->name;
sizes->cs_cachep->size = sizes->cs_size;
sizes->cs_cachep->object_size = sizes->cs_size;
sizes->cs_cachep->align = ARCH_KMALLOC_MINALIGN;
__kmem_cache_create(sizes->cs_cachep, ARCH_KMALLOC_FLAGS|SLAB_PANIC);
list_add(&sizes->cs_cachep->list, &slab_caches);
}
#ifdef CONFIG_ZONE_DMA
sizes->cs_dmacachep = kmem_cache_zalloc(kmem_cache, GFP_NOWAIT);
sizes->cs_dmacachep->name = names->name_dma;
sizes->cs_dmacachep->size = sizes->cs_size;
sizes->cs_dmacachep->object_size = sizes->cs_size;
sizes->cs_dmacachep->align = ARCH_KMALLOC_MINALIGN;
__kmem_cache_create(sizes->cs_dmacachep,
ARCH_KMALLOC_FLAGS|SLAB_CACHE_DMA| SLAB_PANIC);
list_add(&sizes->cs_dmacachep->list, &slab_caches);
#endif
sizes++;
names++;
}
{
struct array_cache *ptr;
ptr = kmalloc(sizeof(struct arraycache_init), GFP_NOWAIT);
BUG_ON(cpu_cache_get(kmem_cache) != &initarray_cache.cache);
memcpy(ptr, cpu_cache_get(kmem_cache),
sizeof(struct arraycache_init));
spin_lock_init(&ptr->lock);
kmem_cache->array[smp_processor_id()] = ptr;
ptr = kmalloc(sizeof(struct arraycache_init), GFP_NOWAIT);
BUG_ON(cpu_cache_get(malloc_sizes[INDEX_AC].cs_cachep)
!= &initarray_generic.cache);
memcpy(ptr, cpu_cache_get(malloc_sizes[INDEX_AC].cs_cachep),
sizeof(struct arraycache_init));
spin_lock_init(&ptr->lock);
malloc_sizes[INDEX_AC].cs_cachep->array[smp_processor_id()] =
ptr;
}
{
int nid;
for_each_online_node(nid) {
init_list(kmem_cache, &initkmem_list3[CACHE_CACHE + nid], nid);
init_list(malloc_sizes[INDEX_AC].cs_cachep,
&initkmem_list3[SIZE_AC + nid], nid);
if (INDEX_AC != INDEX_L3) {
init_list(malloc_sizes[INDEX_L3].cs_cachep,
&initkmem_list3[SIZE_L3 + nid], nid);
}
}
}
slab_state = UP;
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
init_lock_keys();
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
struct kmem_list3 *l3;
struct slab *slabp;
unsigned long flags;
int node;
printk(KERN_WARNING
"SLAB: Unable to allocate memory on node %d (gfp=0x%x)\n",
nodeid, gfpflags);
printk(KERN_WARNING " cache: %s, object size: %d, order: %d\n",
cachep->name, cachep->size, cachep->gfporder);
for_each_online_node(node) {
unsigned long active_objs = 0, num_objs = 0, free_objects = 0;
unsigned long active_slabs = 0, num_slabs = 0;
l3 = cachep->nodelists[node];
if (!l3)
continue;
spin_lock_irqsave(&l3->list_lock, flags);
list_for_each_entry(slabp, &l3->slabs_full, list) {
active_objs += cachep->num;
active_slabs++;
}
list_for_each_entry(slabp, &l3->slabs_partial, list) {
active_objs += slabp->inuse;
active_slabs++;
}
list_for_each_entry(slabp, &l3->slabs_free, list)
num_slabs++;
free_objects += l3->free_objects;
spin_unlock_irqrestore(&l3->list_lock, flags);
num_slabs += active_slabs;
num_objs = num_slabs * cachep->num;
printk(KERN_WARNING
" node %d: slabs: %ld/%ld, objs: %ld/%ld, free: %ld\n",
node, active_slabs, num_slabs, active_objs, num_objs,
free_objects);
}
}
static void *kmem_getpages(struct kmem_cache *cachep, gfp_t flags, int nodeid)
{
struct page *page;
int nr_pages;
int i;
#ifndef CONFIG_MMU
flags |= __GFP_COMP;
#endif
flags |= cachep->allocflags;
if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
flags |= __GFP_RECLAIMABLE;
page = alloc_pages_exact_node(nodeid, flags | __GFP_NOTRACK, cachep->gfporder);
if (!page) {
if (!(flags & __GFP_NOWARN) && printk_ratelimit())
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
for (i = 0; i < nr_pages; i++) {
__SetPageSlab(page + i);
if (page->pfmemalloc)
SetPageSlabPfmemalloc(page + i);
}
if (kmemcheck_enabled && !(cachep->flags & SLAB_NOTRACK)) {
kmemcheck_alloc_shadow(page, cachep->gfporder, flags, nodeid);
if (cachep->ctor)
kmemcheck_mark_uninitialized_pages(page, nr_pages);
else
kmemcheck_mark_unallocated_pages(page, nr_pages);
}
return page_address(page);
}
static void kmem_freepages(struct kmem_cache *cachep, void *addr)
{
unsigned long i = (1 << cachep->gfporder);
struct page *page = virt_to_page(addr);
const unsigned long nr_freed = i;
kmemcheck_free_shadow(page, cachep->gfporder);
if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
sub_zone_page_state(page_zone(page),
NR_SLAB_RECLAIMABLE, nr_freed);
else
sub_zone_page_state(page_zone(page),
NR_SLAB_UNRECLAIMABLE, nr_freed);
while (i--) {
BUG_ON(!PageSlab(page));
__ClearPageSlabPfmemalloc(page);
__ClearPageSlab(page);
page++;
}
if (current->reclaim_state)
current->reclaim_state->reclaimed_slab += nr_freed;
free_pages((unsigned long)addr, cachep->gfporder);
}
static void kmem_rcu_free(struct rcu_head *head)
{
struct slab_rcu *slab_rcu = (struct slab_rcu *)head;
struct kmem_cache *cachep = slab_rcu->cachep;
kmem_freepages(cachep, slab_rcu->addr);
if (OFF_SLAB(cachep))
kmem_cache_free(cachep->slabp_cache, slab_rcu);
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
printk(KERN_ERR "Last user: [<%p>]",
*dbg_userword(cachep, objp));
print_symbol("(%s)",
(unsigned long)*dbg_userword(cachep, objp));
printk("\n");
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
struct slab *slabp = virt_to_slab(objp);
unsigned int objnr;
objnr = obj_to_index(cachep, slabp, objp);
if (objnr) {
objp = index_to_obj(cachep, slabp, objnr - 1);
realobj = (char *)objp + obj_offset(cachep);
printk(KERN_ERR "Prev obj: start=%p, len=%d\n",
realobj, size);
print_objinfo(cachep, objp, 2);
}
if (objnr + 1 < cachep->num) {
objp = index_to_obj(cachep, slabp, objnr + 1);
realobj = (char *)objp + obj_offset(cachep);
printk(KERN_ERR "Next obj: start=%p, len=%d\n",
realobj, size);
print_objinfo(cachep, objp, 2);
}
}
}
static void slab_destroy_debugcheck(struct kmem_cache *cachep, struct slab *slabp)
{
int i;
for (i = 0; i < cachep->num; i++) {
void *objp = index_to_obj(cachep, slabp, i);
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
static void slab_destroy_debugcheck(struct kmem_cache *cachep, struct slab *slabp)
{
}
static void slab_destroy(struct kmem_cache *cachep, struct slab *slabp)
{
void *addr = slabp->s_mem - slabp->colouroff;
slab_destroy_debugcheck(cachep, slabp);
if (unlikely(cachep->flags & SLAB_DESTROY_BY_RCU)) {
struct slab_rcu *slab_rcu;
slab_rcu = (struct slab_rcu *)slabp;
slab_rcu->cachep = cachep;
slab_rcu->addr = addr;
call_rcu(&slab_rcu->head, kmem_rcu_free);
} else {
kmem_freepages(cachep, addr);
if (OFF_SLAB(cachep))
kmem_cache_free(cachep->slabp_cache, slabp);
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
if (flags & CFLGS_OFF_SLAB) {
offslab_limit = size - sizeof(struct slab);
offslab_limit /= sizeof(kmem_bufctl_t);
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
static int __init_refok setup_cpu_cache(struct kmem_cache *cachep, gfp_t gfp)
{
if (slab_state >= FULL)
return enable_cpucache(cachep, gfp);
if (slab_state == DOWN) {
cachep->array[smp_processor_id()] = &initarray_generic.cache;
set_up_list3s(cachep, SIZE_AC);
if (INDEX_AC == INDEX_L3)
slab_state = PARTIAL_L3;
else
slab_state = PARTIAL_ARRAYCACHE;
} else {
cachep->array[smp_processor_id()] =
kmalloc(sizeof(struct arraycache_init), gfp);
if (slab_state == PARTIAL_ARRAYCACHE) {
set_up_list3s(cachep, SIZE_L3);
slab_state = PARTIAL_L3;
} else {
int node;
for_each_online_node(node) {
cachep->nodelists[node] =
kmalloc_node(sizeof(struct kmem_list3),
gfp, node);
BUG_ON(!cachep->nodelists[node]);
kmem_list3_init(cachep->nodelists[node]);
}
}
}
cachep->nodelists[numa_mem_id()]->next_reap =
jiffies + REAPTIMEOUT_LIST3 +
((unsigned long)cachep) % REAPTIMEOUT_LIST3;
cpu_cache_get(cachep)->avail = 0;
cpu_cache_get(cachep)->limit = BOOT_CPUCACHE_ENTRIES;
cpu_cache_get(cachep)->batchcount = 1;
cpu_cache_get(cachep)->touched = 0;
cachep->batchcount = 1;
cachep->limit = BOOT_CPUCACHE_ENTRIES;
return 0;
}
int
__kmem_cache_create (struct kmem_cache *cachep, unsigned long flags)
{
size_t left_over, slab_size, ralign;
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
BUG_ON(flags & ~CREATE_MASK);
if (size & (BYTES_PER_WORD - 1)) {
size += (BYTES_PER_WORD - 1);
size &= ~(BYTES_PER_WORD - 1);
}
if (flags & SLAB_HWCACHE_ALIGN) {
ralign = cache_line_size();
while (size <= ralign / 2)
ralign /= 2;
} else {
ralign = BYTES_PER_WORD;
}
if (flags & SLAB_STORE_USER)
ralign = BYTES_PER_WORD;
if (flags & SLAB_RED_ZONE) {
ralign = REDZONE_ALIGN;
size += REDZONE_ALIGN - 1;
size &= ~(REDZONE_ALIGN - 1);
}
if (ralign < ARCH_SLAB_MINALIGN) {
ralign = ARCH_SLAB_MINALIGN;
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
cachep->nodelists = (struct kmem_list3 **)&cachep->array[nr_cpu_ids];
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
if (size >= malloc_sizes[INDEX_L3 + 1].cs_size
&& cachep->object_size > cache_line_size()
&& ALIGN(size, cachep->align) < PAGE_SIZE) {
cachep->obj_offset += PAGE_SIZE - ALIGN(size, cachep->align);
size = PAGE_SIZE;
}
#endif
#endif
if ((size >= (PAGE_SIZE >> 3)) && !slab_early_init &&
!(flags & SLAB_NOLEAKTRACE))
flags |= CFLGS_OFF_SLAB;
size = ALIGN(size, cachep->align);
left_over = calculate_slab_order(cachep, size, cachep->align, flags);
if (!cachep->num)
return -E2BIG;
slab_size = ALIGN(cachep->num * sizeof(kmem_bufctl_t)
+ sizeof(struct slab), cachep->align);
if (flags & CFLGS_OFF_SLAB && left_over >= slab_size) {
flags &= ~CFLGS_OFF_SLAB;
left_over -= slab_size;
}
if (flags & CFLGS_OFF_SLAB) {
slab_size =
cachep->num * sizeof(kmem_bufctl_t) + sizeof(struct slab);
#ifdef CONFIG_PAGE_POISONING
if (size % PAGE_SIZE == 0 && flags & SLAB_POISON)
flags &= ~(SLAB_RED_ZONE | SLAB_STORE_USER);
#endif
}
cachep->colour_off = cache_line_size();
if (cachep->colour_off < cachep->align)
cachep->colour_off = cachep->align;
cachep->colour = left_over / cachep->colour_off;
cachep->slab_size = slab_size;
cachep->flags = flags;
cachep->allocflags = 0;
if (CONFIG_ZONE_DMA_FLAG && (flags & SLAB_CACHE_DMA))
cachep->allocflags |= GFP_DMA;
cachep->size = size;
cachep->reciprocal_buffer_size = reciprocal_value(size);
if (flags & CFLGS_OFF_SLAB) {
cachep->slabp_cache = kmem_find_general_cachep(slab_size, 0u);
BUG_ON(ZERO_OR_NULL_PTR(cachep->slabp_cache));
}
err = setup_cpu_cache(cachep, gfp);
if (err) {
__kmem_cache_shutdown(cachep);
return err;
}
if (flags & SLAB_DEBUG_OBJECTS) {
WARN_ON_ONCE(flags & SLAB_DESTROY_BY_RCU);
slab_set_debugobj_lock_classes(cachep);
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
assert_spin_locked(&cachep->nodelists[numa_mem_id()]->list_lock);
#endif
}
static void check_spinlock_acquired_node(struct kmem_cache *cachep, int node)
{
#ifdef CONFIG_SMP
check_irq_off();
assert_spin_locked(&cachep->nodelists[node]->list_lock);
#endif
}
static void do_drain(void *arg)
{
struct kmem_cache *cachep = arg;
struct array_cache *ac;
int node = numa_mem_id();
check_irq_off();
ac = cpu_cache_get(cachep);
spin_lock(&cachep->nodelists[node]->list_lock);
free_block(cachep, ac->entry, ac->avail, node);
spin_unlock(&cachep->nodelists[node]->list_lock);
ac->avail = 0;
}
static void drain_cpu_caches(struct kmem_cache *cachep)
{
struct kmem_list3 *l3;
int node;
on_each_cpu(do_drain, cachep, 1);
check_irq_on();
for_each_online_node(node) {
l3 = cachep->nodelists[node];
if (l3 && l3->alien)
drain_alien_cache(cachep, l3->alien);
}
for_each_online_node(node) {
l3 = cachep->nodelists[node];
if (l3)
drain_array(cachep, l3, l3->shared, 1, node);
}
}
static int drain_freelist(struct kmem_cache *cache,
struct kmem_list3 *l3, int tofree)
{
struct list_head *p;
int nr_freed;
struct slab *slabp;
nr_freed = 0;
while (nr_freed < tofree && !list_empty(&l3->slabs_free)) {
spin_lock_irq(&l3->list_lock);
p = l3->slabs_free.prev;
if (p == &l3->slabs_free) {
spin_unlock_irq(&l3->list_lock);
goto out;
}
slabp = list_entry(p, struct slab, list);
#if DEBUG
BUG_ON(slabp->inuse);
#endif
list_del(&slabp->list);
l3->free_objects -= cache->num;
spin_unlock_irq(&l3->list_lock);
slab_destroy(cache, slabp);
nr_freed++;
}
out:
return nr_freed;
}
static int __cache_shrink(struct kmem_cache *cachep)
{
int ret = 0, i = 0;
struct kmem_list3 *l3;
drain_cpu_caches(cachep);
check_irq_on();
for_each_online_node(i) {
l3 = cachep->nodelists[i];
if (!l3)
continue;
drain_freelist(cachep, l3, l3->free_objects);
ret += !list_empty(&l3->slabs_full) ||
!list_empty(&l3->slabs_partial);
}
return (ret ? 1 : 0);
}
int kmem_cache_shrink(struct kmem_cache *cachep)
{
int ret;
BUG_ON(!cachep || in_interrupt());
get_online_cpus();
mutex_lock(&slab_mutex);
ret = __cache_shrink(cachep);
mutex_unlock(&slab_mutex);
put_online_cpus();
return ret;
}
int __kmem_cache_shutdown(struct kmem_cache *cachep)
{
int i;
struct kmem_list3 *l3;
int rc = __cache_shrink(cachep);
if (rc)
return rc;
for_each_online_cpu(i)
kfree(cachep->array[i]);
for_each_online_node(i) {
l3 = cachep->nodelists[i];
if (l3) {
kfree(l3->shared);
free_alien_cache(l3->alien);
kfree(l3);
}
}
return 0;
}
static struct slab *alloc_slabmgmt(struct kmem_cache *cachep, void *objp,
int colour_off, gfp_t local_flags,
int nodeid)
{
struct slab *slabp;
if (OFF_SLAB(cachep)) {
slabp = kmem_cache_alloc_node(cachep->slabp_cache,
local_flags, nodeid);
kmemleak_scan_area(&slabp->list, sizeof(struct list_head),
local_flags);
if (!slabp)
return NULL;
} else {
slabp = objp + colour_off;
colour_off += cachep->slab_size;
}
slabp->inuse = 0;
slabp->colouroff = colour_off;
slabp->s_mem = objp + colour_off;
slabp->nodeid = nodeid;
slabp->free = 0;
return slabp;
}
static inline kmem_bufctl_t *slab_bufctl(struct slab *slabp)
{
return (kmem_bufctl_t *) (slabp + 1);
}
static void cache_init_objs(struct kmem_cache *cachep,
struct slab *slabp)
{
int i;
for (i = 0; i < cachep->num; i++) {
void *objp = index_to_obj(cachep, slabp, i);
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
slab_bufctl(slabp)[i] = i + 1;
}
slab_bufctl(slabp)[i - 1] = BUFCTL_END;
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
static void *slab_get_obj(struct kmem_cache *cachep, struct slab *slabp,
int nodeid)
{
void *objp = index_to_obj(cachep, slabp, slabp->free);
kmem_bufctl_t next;
slabp->inuse++;
next = slab_bufctl(slabp)[slabp->free];
#if DEBUG
slab_bufctl(slabp)[slabp->free] = BUFCTL_FREE;
WARN_ON(slabp->nodeid != nodeid);
#endif
slabp->free = next;
return objp;
}
static void slab_put_obj(struct kmem_cache *cachep, struct slab *slabp,
void *objp, int nodeid)
{
unsigned int objnr = obj_to_index(cachep, slabp, objp);
#if DEBUG
WARN_ON(slabp->nodeid != nodeid);
if (slab_bufctl(slabp)[objnr] + 1 <= SLAB_LIMIT + 1) {
printk(KERN_ERR "slab: double free detected in cache "
"'%s', objp %p\n", cachep->name, objp);
BUG();
}
#endif
slab_bufctl(slabp)[objnr] = slabp->free;
slabp->free = objnr;
slabp->inuse--;
}
static void slab_map_pages(struct kmem_cache *cache, struct slab *slab,
void *addr)
{
int nr_pages;
struct page *page;
page = virt_to_page(addr);
nr_pages = 1;
if (likely(!PageCompound(page)))
nr_pages <<= cache->gfporder;
do {
page->slab_cache = cache;
page->slab_page = slab;
page++;
} while (--nr_pages);
}
static int cache_grow(struct kmem_cache *cachep,
gfp_t flags, int nodeid, void *objp)
{
struct slab *slabp;
size_t offset;
gfp_t local_flags;
struct kmem_list3 *l3;
BUG_ON(flags & GFP_SLAB_BUG_MASK);
local_flags = flags & (GFP_CONSTRAINT_MASK|GFP_RECLAIM_MASK);
check_irq_off();
l3 = cachep->nodelists[nodeid];
spin_lock(&l3->list_lock);
offset = l3->colour_next;
l3->colour_next++;
if (l3->colour_next >= cachep->colour)
l3->colour_next = 0;
spin_unlock(&l3->list_lock);
offset *= cachep->colour_off;
if (local_flags & __GFP_WAIT)
local_irq_enable();
kmem_flagcheck(cachep, flags);
if (!objp)
objp = kmem_getpages(cachep, local_flags, nodeid);
if (!objp)
goto failed;
slabp = alloc_slabmgmt(cachep, objp, offset,
local_flags & ~GFP_CONSTRAINT_MASK, nodeid);
if (!slabp)
goto opps1;
slab_map_pages(cachep, slabp, objp);
cache_init_objs(cachep, slabp);
if (local_flags & __GFP_WAIT)
local_irq_disable();
check_irq_off();
spin_lock(&l3->list_lock);
list_add_tail(&slabp->list, &(l3->slabs_free));
STATS_INC_GROWN(cachep);
l3->free_objects += cachep->num;
spin_unlock(&l3->list_lock);
return 1;
opps1:
kmem_freepages(cachep, objp);
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
struct page *page;
unsigned int objnr;
struct slab *slabp;
BUG_ON(virt_to_cache(objp) != cachep);
objp -= obj_offset(cachep);
kfree_debugcheck(objp);
page = virt_to_head_page(objp);
slabp = page->slab_page;
if (cachep->flags & SLAB_RED_ZONE) {
verify_redzone_free(cachep, objp);
*dbg_redzone1(cachep, objp) = RED_INACTIVE;
*dbg_redzone2(cachep, objp) = RED_INACTIVE;
}
if (cachep->flags & SLAB_STORE_USER)
*dbg_userword(cachep, objp) = (void *)caller;
objnr = obj_to_index(cachep, slabp, objp);
BUG_ON(objnr >= cachep->num);
BUG_ON(objp != index_to_obj(cachep, slabp, objnr));
#ifdef CONFIG_DEBUG_SLAB_LEAK
slab_bufctl(slabp)[objnr] = BUFCTL_FREE;
#endif
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
static void check_slabp(struct kmem_cache *cachep, struct slab *slabp)
{
kmem_bufctl_t i;
int entries = 0;
for (i = slabp->free; i != BUFCTL_END; i = slab_bufctl(slabp)[i]) {
entries++;
if (entries > cachep->num || i >= cachep->num)
goto bad;
}
if (entries != cachep->num - slabp->inuse) {
bad:
printk(KERN_ERR "slab: Internal list corruption detected in "
"cache '%s'(%d), slabp %p(%d). Tainted(%s). Hexdump:\n",
cachep->name, cachep->num, slabp, slabp->inuse,
print_tainted());
print_hex_dump(KERN_ERR, "", DUMP_PREFIX_OFFSET, 16, 1, slabp,
sizeof(*slabp) + cachep->num * sizeof(kmem_bufctl_t),
1);
BUG();
}
}
static void *cache_alloc_refill(struct kmem_cache *cachep, gfp_t flags,
bool force_refill)
{
int batchcount;
struct kmem_list3 *l3;
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
l3 = cachep->nodelists[node];
BUG_ON(ac->avail > 0 || !l3);
spin_lock(&l3->list_lock);
if (l3->shared && transfer_objects(ac, l3->shared, batchcount)) {
l3->shared->touched = 1;
goto alloc_done;
}
while (batchcount > 0) {
struct list_head *entry;
struct slab *slabp;
entry = l3->slabs_partial.next;
if (entry == &l3->slabs_partial) {
l3->free_touched = 1;
entry = l3->slabs_free.next;
if (entry == &l3->slabs_free)
goto must_grow;
}
slabp = list_entry(entry, struct slab, list);
check_slabp(cachep, slabp);
check_spinlock_acquired(cachep);
BUG_ON(slabp->inuse >= cachep->num);
while (slabp->inuse < cachep->num && batchcount--) {
STATS_INC_ALLOCED(cachep);
STATS_INC_ACTIVE(cachep);
STATS_SET_HIGH(cachep);
ac_put_obj(cachep, ac, slab_get_obj(cachep, slabp,
node));
}
check_slabp(cachep, slabp);
list_del(&slabp->list);
if (slabp->free == BUFCTL_END)
list_add(&slabp->list, &l3->slabs_full);
else
list_add(&slabp->list, &l3->slabs_partial);
}
must_grow:
l3->free_objects -= ac->avail;
alloc_done:
spin_unlock(&l3->list_lock);
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
#ifdef CONFIG_DEBUG_SLAB_LEAK
{
struct slab *slabp;
unsigned objnr;
slabp = virt_to_head_page(objp)->slab_page;
objnr = (unsigned)(objp - slabp->s_mem) / cachep->size;
slab_bufctl(slabp)[objnr] = BUFCTL_ACTIVE;
}
#endif
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
if (cachep == kmem_cache)
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
nid_alloc = slab_node();
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
cpuset_mems_cookie = get_mems_allowed();
zonelist = node_zonelist(slab_node(), flags);
retry:
for_each_zone_zonelist(zone, z, zonelist, high_zoneidx) {
nid = zone_to_nid(zone);
if (cpuset_zone_allowed_hardwall(zone, flags) &&
cache->nodelists[nid] &&
cache->nodelists[nid]->free_objects) {
obj = ____cache_alloc_node(cache,
flags | GFP_THISNODE, nid);
if (obj)
break;
}
}
if (!obj) {
if (local_flags & __GFP_WAIT)
local_irq_enable();
kmem_flagcheck(cache, flags);
obj = kmem_getpages(cache, local_flags, numa_mem_id());
if (local_flags & __GFP_WAIT)
local_irq_disable();
if (obj) {
nid = page_to_nid(virt_to_page(obj));
if (cache_grow(cache, flags, nid, obj)) {
obj = ____cache_alloc_node(cache,
flags | GFP_THISNODE, nid);
if (!obj)
goto retry;
} else {
obj = NULL;
}
}
}
if (unlikely(!put_mems_allowed(cpuset_mems_cookie) && !obj))
goto retry_cpuset;
return obj;
}
static void *____cache_alloc_node(struct kmem_cache *cachep, gfp_t flags,
int nodeid)
{
struct list_head *entry;
struct slab *slabp;
struct kmem_list3 *l3;
void *obj;
int x;
l3 = cachep->nodelists[nodeid];
BUG_ON(!l3);
retry:
check_irq_off();
spin_lock(&l3->list_lock);
entry = l3->slabs_partial.next;
if (entry == &l3->slabs_partial) {
l3->free_touched = 1;
entry = l3->slabs_free.next;
if (entry == &l3->slabs_free)
goto must_grow;
}
slabp = list_entry(entry, struct slab, list);
check_spinlock_acquired_node(cachep, nodeid);
check_slabp(cachep, slabp);
STATS_INC_NODEALLOCS(cachep);
STATS_INC_ACTIVE(cachep);
STATS_SET_HIGH(cachep);
BUG_ON(slabp->inuse == cachep->num);
obj = slab_get_obj(cachep, slabp, nodeid);
check_slabp(cachep, slabp);
l3->free_objects--;
list_del(&slabp->list);
if (slabp->free == BUFCTL_END)
list_add(&slabp->list, &l3->slabs_full);
else
list_add(&slabp->list, &l3->slabs_partial);
spin_unlock(&l3->list_lock);
goto done;
must_grow:
spin_unlock(&l3->list_lock);
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
cache_alloc_debugcheck_before(cachep, flags);
local_irq_save(save_flags);
if (nodeid == NUMA_NO_NODE)
nodeid = slab_node;
if (unlikely(!cachep->nodelists[nodeid])) {
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
if (likely(ptr))
kmemcheck_slab_alloc(cachep, flags, ptr, cachep->object_size);
if (unlikely((flags & __GFP_ZERO) && ptr))
memset(ptr, 0, cachep->object_size);
return ptr;
}
static __always_inline void *
__do_cache_alloc(struct kmem_cache *cache, gfp_t flags)
{
void *objp;
if (unlikely(current->flags & (PF_SPREAD_SLAB | PF_MEMPOLICY))) {
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
cache_alloc_debugcheck_before(cachep, flags);
local_irq_save(save_flags);
objp = __do_cache_alloc(cachep, flags);
local_irq_restore(save_flags);
objp = cache_alloc_debugcheck_after(cachep, flags, objp, caller);
kmemleak_alloc_recursive(objp, cachep->object_size, 1, cachep->flags,
flags);
prefetchw(objp);
if (likely(objp))
kmemcheck_slab_alloc(cachep, flags, objp, cachep->object_size);
if (unlikely((flags & __GFP_ZERO) && objp))
memset(objp, 0, cachep->object_size);
return objp;
}
static void free_block(struct kmem_cache *cachep, void **objpp, int nr_objects,
int node)
{
int i;
struct kmem_list3 *l3;
for (i = 0; i < nr_objects; i++) {
void *objp;
struct slab *slabp;
clear_obj_pfmemalloc(&objpp[i]);
objp = objpp[i];
slabp = virt_to_slab(objp);
l3 = cachep->nodelists[node];
list_del(&slabp->list);
check_spinlock_acquired_node(cachep, node);
check_slabp(cachep, slabp);
slab_put_obj(cachep, slabp, objp, node);
STATS_DEC_ACTIVE(cachep);
l3->free_objects++;
check_slabp(cachep, slabp);
if (slabp->inuse == 0) {
if (l3->free_objects > l3->free_limit) {
l3->free_objects -= cachep->num;
slab_destroy(cachep, slabp);
} else {
list_add(&slabp->list, &l3->slabs_free);
}
} else {
list_add_tail(&slabp->list, &l3->slabs_partial);
}
}
}
static void cache_flusharray(struct kmem_cache *cachep, struct array_cache *ac)
{
int batchcount;
struct kmem_list3 *l3;
int node = numa_mem_id();
batchcount = ac->batchcount;
#if DEBUG
BUG_ON(!batchcount || batchcount > ac->avail);
#endif
check_irq_off();
l3 = cachep->nodelists[node];
spin_lock(&l3->list_lock);
if (l3->shared) {
struct array_cache *shared_array = l3->shared;
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
free_block(cachep, ac->entry, batchcount, node);
free_done:
#if STATS
{
int i = 0;
struct list_head *p;
p = l3->slabs_free.next;
while (p != &(l3->slabs_free)) {
struct slab *slabp;
slabp = list_entry(p, struct slab, list);
BUG_ON(slabp->inuse);
i++;
p = p->next;
}
STATS_SET_FREEABLE(cachep, i);
}
#endif
spin_unlock(&l3->list_lock);
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
if (likely(ac->avail < ac->limit)) {
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
cachep = kmem_find_general_cachep(size, flags);
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
void *__kmalloc_node(size_t size, gfp_t flags, int node)
{
return __do_kmalloc_node(size, flags, node, 0);
}
static __always_inline void *__do_kmalloc(size_t size, gfp_t flags,
unsigned long caller)
{
struct kmem_cache *cachep;
void *ret;
cachep = __find_general_cachep(size, flags);
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
void *__kmalloc(size_t size, gfp_t flags)
{
return __do_kmalloc(size, flags, 0);
}
void kmem_cache_free(struct kmem_cache *cachep, void *objp)
{
unsigned long flags;
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
unsigned int kmem_cache_size(struct kmem_cache *cachep)
{
return cachep->object_size;
}
static int alloc_kmemlist(struct kmem_cache *cachep, gfp_t gfp)
{
int node;
struct kmem_list3 *l3;
struct array_cache *new_shared;
struct array_cache **new_alien = NULL;
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
l3 = cachep->nodelists[node];
if (l3) {
struct array_cache *shared = l3->shared;
spin_lock_irq(&l3->list_lock);
if (shared)
free_block(cachep, shared->entry,
shared->avail, node);
l3->shared = new_shared;
if (!l3->alien) {
l3->alien = new_alien;
new_alien = NULL;
}
l3->free_limit = (1 + nr_cpus_node(node)) *
cachep->batchcount + cachep->num;
spin_unlock_irq(&l3->list_lock);
kfree(shared);
free_alien_cache(new_alien);
continue;
}
l3 = kmalloc_node(sizeof(struct kmem_list3), gfp, node);
if (!l3) {
free_alien_cache(new_alien);
kfree(new_shared);
goto fail;
}
kmem_list3_init(l3);
l3->next_reap = jiffies + REAPTIMEOUT_LIST3 +
((unsigned long)cachep) % REAPTIMEOUT_LIST3;
l3->shared = new_shared;
l3->alien = new_alien;
l3->free_limit = (1 + nr_cpus_node(node)) *
cachep->batchcount + cachep->num;
cachep->nodelists[node] = l3;
}
return 0;
fail:
if (!cachep->list.next) {
node--;
while (node >= 0) {
if (cachep->nodelists[node]) {
l3 = cachep->nodelists[node];
kfree(l3->shared);
free_alien_cache(l3->alien);
kfree(l3);
cachep->nodelists[node] = NULL;
}
node--;
}
}
return -ENOMEM;
}
static void do_ccupdate_local(void *info)
{
struct ccupdate_struct *new = info;
struct array_cache *old;
check_irq_off();
old = cpu_cache_get(new->cachep);
new->cachep->array[smp_processor_id()] = new->new[smp_processor_id()];
new->new[smp_processor_id()] = old;
}
static int do_tune_cpucache(struct kmem_cache *cachep, int limit,
int batchcount, int shared, gfp_t gfp)
{
struct ccupdate_struct *new;
int i;
new = kzalloc(sizeof(*new) + nr_cpu_ids * sizeof(struct array_cache *),
gfp);
if (!new)
return -ENOMEM;
for_each_online_cpu(i) {
new->new[i] = alloc_arraycache(cpu_to_mem(i), limit,
batchcount, gfp);
if (!new->new[i]) {
for (i--; i >= 0; i--)
kfree(new->new[i]);
kfree(new);
return -ENOMEM;
}
}
new->cachep = cachep;
on_each_cpu(do_ccupdate_local, (void *)new, 1);
check_irq_on();
cachep->batchcount = batchcount;
cachep->limit = limit;
cachep->shared = shared;
for_each_online_cpu(i) {
struct array_cache *ccold = new->new[i];
if (!ccold)
continue;
spin_lock_irq(&cachep->nodelists[cpu_to_mem(i)]->list_lock);
free_block(cachep, ccold->entry, ccold->avail, cpu_to_mem(i));
spin_unlock_irq(&cachep->nodelists[cpu_to_mem(i)]->list_lock);
kfree(ccold);
}
kfree(new);
return alloc_kmemlist(cachep, gfp);
}
static int enable_cpucache(struct kmem_cache *cachep, gfp_t gfp)
{
int err;
int limit, shared;
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
err = do_tune_cpucache(cachep, limit, (limit + 1) / 2, shared, gfp);
if (err)
printk(KERN_ERR "enable_cpucache failed for %s, error %d.\n",
cachep->name, -err);
return err;
}
static void drain_array(struct kmem_cache *cachep, struct kmem_list3 *l3,
struct array_cache *ac, int force, int node)
{
int tofree;
if (!ac || !ac->avail)
return;
if (ac->touched && !force) {
ac->touched = 0;
} else {
spin_lock_irq(&l3->list_lock);
if (ac->avail) {
tofree = force ? ac->avail : (ac->limit + 4) / 5;
if (tofree > ac->avail)
tofree = (ac->avail + 1) / 2;
free_block(cachep, ac->entry, tofree, node);
ac->avail -= tofree;
memmove(ac->entry, &(ac->entry[tofree]),
sizeof(void *) * ac->avail);
}
spin_unlock_irq(&l3->list_lock);
}
}
static void cache_reap(struct work_struct *w)
{
struct kmem_cache *searchp;
struct kmem_list3 *l3;
int node = numa_mem_id();
struct delayed_work *work = to_delayed_work(w);
if (!mutex_trylock(&slab_mutex))
goto out;
list_for_each_entry(searchp, &slab_caches, list) {
check_irq_on();
l3 = searchp->nodelists[node];
reap_alien(searchp, l3);
drain_array(searchp, l3, cpu_cache_get(searchp), 0, node);
if (time_after(l3->next_reap, jiffies))
goto next;
l3->next_reap = jiffies + REAPTIMEOUT_LIST3;
drain_array(searchp, l3, l3->shared, 0, node);
if (l3->free_touched)
l3->free_touched = 0;
else {
int freed;
freed = drain_freelist(searchp, l3, (l3->free_limit +
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
schedule_delayed_work(work, round_jiffies_relative(REAPTIMEOUT_CPUC));
}
static void print_slabinfo_header(struct seq_file *m)
{
#if STATS
seq_puts(m, "slabinfo - version: 2.1 (statistics)\n");
#else
seq_puts(m, "slabinfo - version: 2.1\n");
#endif
seq_puts(m, "# name <active_objs> <num_objs> <objsize> "
"<objperslab> <pagesperslab>");
seq_puts(m, " : tunables <limit> <batchcount> <sharedfactor>");
seq_puts(m, " : slabdata <active_slabs> <num_slabs> <sharedavail>");
#if STATS
seq_puts(m, " : globalstat <listallocs> <maxobjs> <grown> <reaped> "
"<error> <maxfreeable> <nodeallocs> <remotefrees> <alienoverflow>");
seq_puts(m, " : cpustat <allochit> <allocmiss> <freehit> <freemiss>");
#endif
seq_putc(m, '\n');
}
static void *s_start(struct seq_file *m, loff_t *pos)
{
loff_t n = *pos;
mutex_lock(&slab_mutex);
if (!n)
print_slabinfo_header(m);
return seq_list_start(&slab_caches, *pos);
}
static void *s_next(struct seq_file *m, void *p, loff_t *pos)
{
return seq_list_next(p, &slab_caches, pos);
}
static void s_stop(struct seq_file *m, void *p)
{
mutex_unlock(&slab_mutex);
}
static int s_show(struct seq_file *m, void *p)
{
struct kmem_cache *cachep = list_entry(p, struct kmem_cache, list);
struct slab *slabp;
unsigned long active_objs;
unsigned long num_objs;
unsigned long active_slabs = 0;
unsigned long num_slabs, free_objects = 0, shared_avail = 0;
const char *name;
char *error = NULL;
int node;
struct kmem_list3 *l3;
active_objs = 0;
num_slabs = 0;
for_each_online_node(node) {
l3 = cachep->nodelists[node];
if (!l3)
continue;
check_irq_on();
spin_lock_irq(&l3->list_lock);
list_for_each_entry(slabp, &l3->slabs_full, list) {
if (slabp->inuse != cachep->num && !error)
error = "slabs_full accounting error";
active_objs += cachep->num;
active_slabs++;
}
list_for_each_entry(slabp, &l3->slabs_partial, list) {
if (slabp->inuse == cachep->num && !error)
error = "slabs_partial inuse accounting error";
if (!slabp->inuse && !error)
error = "slabs_partial/inuse accounting error";
active_objs += slabp->inuse;
active_slabs++;
}
list_for_each_entry(slabp, &l3->slabs_free, list) {
if (slabp->inuse && !error)
error = "slabs_free/inuse accounting error";
num_slabs++;
}
free_objects += l3->free_objects;
if (l3->shared)
shared_avail += l3->shared->avail;
spin_unlock_irq(&l3->list_lock);
}
num_slabs += active_slabs;
num_objs = num_slabs * cachep->num;
if (num_objs - active_objs != free_objects && !error)
error = "free_objects accounting error";
name = cachep->name;
if (error)
printk(KERN_ERR "slab: cache %s error: %s\n", name, error);
seq_printf(m, "%-17s %6lu %6lu %6u %4u %4d",
name, active_objs, num_objs, cachep->size,
cachep->num, (1 << cachep->gfporder));
seq_printf(m, " : tunables %4u %4u %4u",
cachep->limit, cachep->batchcount, cachep->shared);
seq_printf(m, " : slabdata %6lu %6lu %6lu",
active_slabs, num_slabs, shared_avail);
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
seq_putc(m, '\n');
return 0;
}
static ssize_t slabinfo_write(struct file *file, const char __user *buffer,
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
static int slabinfo_open(struct inode *inode, struct file *file)
{
return seq_open(file, &slabinfo_op);
}
static void *leaks_start(struct seq_file *m, loff_t *pos)
{
mutex_lock(&slab_mutex);
return seq_list_start(&slab_caches, *pos);
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
static void handle_slab(unsigned long *n, struct kmem_cache *c, struct slab *s)
{
void *p;
int i;
if (n[0] == n[1])
return;
for (i = 0, p = s->s_mem; i < c->num; i++, p += c->size) {
if (slab_bufctl(s)[i] != BUFCTL_ACTIVE)
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
struct slab *slabp;
struct kmem_list3 *l3;
const char *name;
unsigned long *n = m->private;
int node;
int i;
if (!(cachep->flags & SLAB_STORE_USER))
return 0;
if (!(cachep->flags & SLAB_RED_ZONE))
return 0;
n[1] = 0;
for_each_online_node(node) {
l3 = cachep->nodelists[node];
if (!l3)
continue;
check_irq_on();
spin_lock_irq(&l3->list_lock);
list_for_each_entry(slabp, &l3->slabs_full, list)
handle_slab(n, cachep, slabp);
list_for_each_entry(slabp, &l3->slabs_partial, list)
handle_slab(n, cachep, slabp);
spin_unlock_irq(&l3->list_lock);
}
name = cachep->name;
if (n[0] == n[1]) {
mutex_unlock(&slab_mutex);
m->private = kzalloc(n[0] * 4 * sizeof(unsigned long), GFP_KERNEL);
if (!m->private) {
m->private = n;
mutex_lock(&slab_mutex);
return -ENOMEM;
}
*(unsigned long *)m->private = n[0] * 2;
kfree(n);
mutex_lock(&slab_mutex);
m->count = m->size;
return 0;
}
for (i = 0; i < n[1]; i++) {
seq_printf(m, "%s: %lu ", name, n[2*i+3]);
show_symbol(m, n[2*i+2]);
seq_putc(m, '\n');
}
return 0;
}
static int slabstats_open(struct inode *inode, struct file *file)
{
unsigned long *n = kzalloc(PAGE_SIZE, GFP_KERNEL);
int ret = -ENOMEM;
if (n) {
ret = seq_open(file, &slabstats_op);
if (!ret) {
struct seq_file *m = file->private_data;
*n = PAGE_SIZE / (2 * sizeof(unsigned long));
m->private = n;
n = NULL;
}
kfree(n);
}
return ret;
}
static int __init slab_proc_init(void)
{
proc_create("slabinfo",S_IWUSR|S_IRUSR,NULL,&proc_slabinfo_operations);
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
