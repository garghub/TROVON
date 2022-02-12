static int __init setup_slab_nomerge(char *str)
{
slab_nomerge = 1;
return 1;
}
unsigned int kmem_cache_size(struct kmem_cache *s)
{
return s->object_size;
}
static int kmem_cache_sanity_check(const char *name, size_t size)
{
struct kmem_cache *s = NULL;
if (!name || in_interrupt() || size < sizeof(void *) ||
size > KMALLOC_MAX_SIZE) {
pr_err("kmem_cache_create(%s) integrity check failed\n", name);
return -EINVAL;
}
list_for_each_entry(s, &slab_caches, list) {
char tmp;
int res;
res = probe_kernel_address(s->name, tmp);
if (res) {
pr_err("Slab cache with size %d has lost its name\n",
s->object_size);
continue;
}
}
WARN_ON(strchr(name, ' '));
return 0;
}
static inline int kmem_cache_sanity_check(const char *name, size_t size)
{
return 0;
}
void __kmem_cache_free_bulk(struct kmem_cache *s, size_t nr, void **p)
{
size_t i;
for (i = 0; i < nr; i++) {
if (s)
kmem_cache_free(s, p[i]);
else
kfree(p[i]);
}
}
int __kmem_cache_alloc_bulk(struct kmem_cache *s, gfp_t flags, size_t nr,
void **p)
{
size_t i;
for (i = 0; i < nr; i++) {
void *x = p[i] = kmem_cache_alloc(s, flags);
if (!x) {
__kmem_cache_free_bulk(s, i, p);
return 0;
}
}
return i;
}
void slab_init_memcg_params(struct kmem_cache *s)
{
s->memcg_params.is_root_cache = true;
INIT_LIST_HEAD(&s->memcg_params.list);
RCU_INIT_POINTER(s->memcg_params.memcg_caches, NULL);
}
static int init_memcg_params(struct kmem_cache *s,
struct mem_cgroup *memcg, struct kmem_cache *root_cache)
{
struct memcg_cache_array *arr;
if (memcg) {
s->memcg_params.is_root_cache = false;
s->memcg_params.memcg = memcg;
s->memcg_params.root_cache = root_cache;
return 0;
}
slab_init_memcg_params(s);
if (!memcg_nr_cache_ids)
return 0;
arr = kzalloc(sizeof(struct memcg_cache_array) +
memcg_nr_cache_ids * sizeof(void *),
GFP_KERNEL);
if (!arr)
return -ENOMEM;
RCU_INIT_POINTER(s->memcg_params.memcg_caches, arr);
return 0;
}
static void destroy_memcg_params(struct kmem_cache *s)
{
if (is_root_cache(s))
kfree(rcu_access_pointer(s->memcg_params.memcg_caches));
}
static int update_memcg_params(struct kmem_cache *s, int new_array_size)
{
struct memcg_cache_array *old, *new;
if (!is_root_cache(s))
return 0;
new = kzalloc(sizeof(struct memcg_cache_array) +
new_array_size * sizeof(void *), GFP_KERNEL);
if (!new)
return -ENOMEM;
old = rcu_dereference_protected(s->memcg_params.memcg_caches,
lockdep_is_held(&slab_mutex));
if (old)
memcpy(new->entries, old->entries,
memcg_nr_cache_ids * sizeof(void *));
rcu_assign_pointer(s->memcg_params.memcg_caches, new);
if (old)
kfree_rcu(old, rcu);
return 0;
}
int memcg_update_all_caches(int num_memcgs)
{
struct kmem_cache *s;
int ret = 0;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list) {
ret = update_memcg_params(s, num_memcgs);
if (ret)
break;
}
mutex_unlock(&slab_mutex);
return ret;
}
static inline int init_memcg_params(struct kmem_cache *s,
struct mem_cgroup *memcg, struct kmem_cache *root_cache)
{
return 0;
}
static inline void destroy_memcg_params(struct kmem_cache *s)
{
}
int slab_unmergeable(struct kmem_cache *s)
{
if (slab_nomerge || (s->flags & SLAB_NEVER_MERGE))
return 1;
if (!is_root_cache(s))
return 1;
if (s->ctor)
return 1;
if (s->refcount < 0)
return 1;
return 0;
}
struct kmem_cache *find_mergeable(size_t size, size_t align,
unsigned long flags, const char *name, void (*ctor)(void *))
{
struct kmem_cache *s;
if (slab_nomerge || (flags & SLAB_NEVER_MERGE))
return NULL;
if (ctor)
return NULL;
size = ALIGN(size, sizeof(void *));
align = calculate_alignment(flags, align, size);
size = ALIGN(size, align);
flags = kmem_cache_flags(size, flags, name, NULL);
list_for_each_entry_reverse(s, &slab_caches, list) {
if (slab_unmergeable(s))
continue;
if (size > s->size)
continue;
if ((flags & SLAB_MERGE_SAME) != (s->flags & SLAB_MERGE_SAME))
continue;
if ((s->size & ~(align - 1)) != s->size)
continue;
if (s->size - size >= sizeof(void *))
continue;
if (IS_ENABLED(CONFIG_SLAB) && align &&
(align > s->align || s->align % align))
continue;
return s;
}
return NULL;
}
unsigned long calculate_alignment(unsigned long flags,
unsigned long align, unsigned long size)
{
if (flags & SLAB_HWCACHE_ALIGN) {
unsigned long ralign = cache_line_size();
while (size <= ralign / 2)
ralign /= 2;
align = max(align, ralign);
}
if (align < ARCH_SLAB_MINALIGN)
align = ARCH_SLAB_MINALIGN;
return ALIGN(align, sizeof(void *));
}
static struct kmem_cache *create_cache(const char *name,
size_t object_size, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *),
struct mem_cgroup *memcg, struct kmem_cache *root_cache)
{
struct kmem_cache *s;
int err;
err = -ENOMEM;
s = kmem_cache_zalloc(kmem_cache, GFP_KERNEL);
if (!s)
goto out;
s->name = name;
s->object_size = object_size;
s->size = size;
s->align = align;
s->ctor = ctor;
err = init_memcg_params(s, memcg, root_cache);
if (err)
goto out_free_cache;
err = __kmem_cache_create(s, flags);
if (err)
goto out_free_cache;
s->refcount = 1;
list_add(&s->list, &slab_caches);
out:
if (err)
return ERR_PTR(err);
return s;
out_free_cache:
destroy_memcg_params(s);
kmem_cache_free(kmem_cache, s);
goto out;
}
struct kmem_cache *
kmem_cache_create(const char *name, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *))
{
struct kmem_cache *s = NULL;
const char *cache_name;
int err;
get_online_cpus();
get_online_mems();
memcg_get_cache_ids();
mutex_lock(&slab_mutex);
err = kmem_cache_sanity_check(name, size);
if (err) {
goto out_unlock;
}
flags &= CACHE_CREATE_MASK;
s = __kmem_cache_alias(name, size, align, flags, ctor);
if (s)
goto out_unlock;
cache_name = kstrdup_const(name, GFP_KERNEL);
if (!cache_name) {
err = -ENOMEM;
goto out_unlock;
}
s = create_cache(cache_name, size, size,
calculate_alignment(flags, align, size),
flags, ctor, NULL, NULL);
if (IS_ERR(s)) {
err = PTR_ERR(s);
kfree_const(cache_name);
}
out_unlock:
mutex_unlock(&slab_mutex);
memcg_put_cache_ids();
put_online_mems();
put_online_cpus();
if (err) {
if (flags & SLAB_PANIC)
panic("kmem_cache_create: Failed to create slab '%s'. Error %d\n",
name, err);
else {
pr_warn("kmem_cache_create(%s) failed with error %d\n",
name, err);
dump_stack();
}
return NULL;
}
return s;
}
static int shutdown_cache(struct kmem_cache *s,
struct list_head *release, bool *need_rcu_barrier)
{
if (__kmem_cache_shutdown(s) != 0)
return -EBUSY;
if (s->flags & SLAB_DESTROY_BY_RCU)
*need_rcu_barrier = true;
list_move(&s->list, release);
return 0;
}
static void release_caches(struct list_head *release, bool need_rcu_barrier)
{
struct kmem_cache *s, *s2;
if (need_rcu_barrier)
rcu_barrier();
list_for_each_entry_safe(s, s2, release, list) {
#ifdef SLAB_SUPPORTS_SYSFS
sysfs_slab_remove(s);
#else
slab_kmem_cache_release(s);
#endif
}
}
void memcg_create_kmem_cache(struct mem_cgroup *memcg,
struct kmem_cache *root_cache)
{
static char memcg_name_buf[NAME_MAX + 1];
struct cgroup_subsys_state *css = &memcg->css;
struct memcg_cache_array *arr;
struct kmem_cache *s = NULL;
char *cache_name;
int idx;
get_online_cpus();
get_online_mems();
mutex_lock(&slab_mutex);
if (memcg->kmem_state != KMEM_ONLINE)
goto out_unlock;
idx = memcg_cache_id(memcg);
arr = rcu_dereference_protected(root_cache->memcg_params.memcg_caches,
lockdep_is_held(&slab_mutex));
if (arr->entries[idx])
goto out_unlock;
cgroup_name(css->cgroup, memcg_name_buf, sizeof(memcg_name_buf));
cache_name = kasprintf(GFP_KERNEL, "%s(%llu:%s)", root_cache->name,
css->serial_nr, memcg_name_buf);
if (!cache_name)
goto out_unlock;
s = create_cache(cache_name, root_cache->object_size,
root_cache->size, root_cache->align,
root_cache->flags & CACHE_CREATE_MASK,
root_cache->ctor, memcg, root_cache);
if (IS_ERR(s)) {
kfree(cache_name);
goto out_unlock;
}
list_add(&s->memcg_params.list, &root_cache->memcg_params.list);
smp_wmb();
arr->entries[idx] = s;
out_unlock:
mutex_unlock(&slab_mutex);
put_online_mems();
put_online_cpus();
}
void memcg_deactivate_kmem_caches(struct mem_cgroup *memcg)
{
int idx;
struct memcg_cache_array *arr;
struct kmem_cache *s, *c;
idx = memcg_cache_id(memcg);
get_online_cpus();
get_online_mems();
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list) {
if (!is_root_cache(s))
continue;
arr = rcu_dereference_protected(s->memcg_params.memcg_caches,
lockdep_is_held(&slab_mutex));
c = arr->entries[idx];
if (!c)
continue;
__kmem_cache_shrink(c, true);
arr->entries[idx] = NULL;
}
mutex_unlock(&slab_mutex);
put_online_mems();
put_online_cpus();
}
static int __shutdown_memcg_cache(struct kmem_cache *s,
struct list_head *release, bool *need_rcu_barrier)
{
BUG_ON(is_root_cache(s));
if (shutdown_cache(s, release, need_rcu_barrier))
return -EBUSY;
list_del(&s->memcg_params.list);
return 0;
}
void memcg_destroy_kmem_caches(struct mem_cgroup *memcg)
{
LIST_HEAD(release);
bool need_rcu_barrier = false;
struct kmem_cache *s, *s2;
get_online_cpus();
get_online_mems();
mutex_lock(&slab_mutex);
list_for_each_entry_safe(s, s2, &slab_caches, list) {
if (is_root_cache(s) || s->memcg_params.memcg != memcg)
continue;
BUG_ON(__shutdown_memcg_cache(s, &release, &need_rcu_barrier));
}
mutex_unlock(&slab_mutex);
put_online_mems();
put_online_cpus();
release_caches(&release, need_rcu_barrier);
}
static int shutdown_memcg_caches(struct kmem_cache *s,
struct list_head *release, bool *need_rcu_barrier)
{
struct memcg_cache_array *arr;
struct kmem_cache *c, *c2;
LIST_HEAD(busy);
int i;
BUG_ON(!is_root_cache(s));
arr = rcu_dereference_protected(s->memcg_params.memcg_caches,
lockdep_is_held(&slab_mutex));
for_each_memcg_cache_index(i) {
c = arr->entries[i];
if (!c)
continue;
if (__shutdown_memcg_cache(c, release, need_rcu_barrier))
list_move(&c->memcg_params.list, &busy);
else
arr->entries[i] = NULL;
}
list_for_each_entry_safe(c, c2, &s->memcg_params.list,
memcg_params.list)
__shutdown_memcg_cache(c, release, need_rcu_barrier);
list_splice(&busy, &s->memcg_params.list);
if (!list_empty(&s->memcg_params.list))
return -EBUSY;
return 0;
}
static inline int shutdown_memcg_caches(struct kmem_cache *s,
struct list_head *release, bool *need_rcu_barrier)
{
return 0;
}
void slab_kmem_cache_release(struct kmem_cache *s)
{
__kmem_cache_release(s);
destroy_memcg_params(s);
kfree_const(s->name);
kmem_cache_free(kmem_cache, s);
}
void kmem_cache_destroy(struct kmem_cache *s)
{
LIST_HEAD(release);
bool need_rcu_barrier = false;
int err;
if (unlikely(!s))
return;
get_online_cpus();
get_online_mems();
kasan_cache_destroy(s);
mutex_lock(&slab_mutex);
s->refcount--;
if (s->refcount)
goto out_unlock;
err = shutdown_memcg_caches(s, &release, &need_rcu_barrier);
if (!err)
err = shutdown_cache(s, &release, &need_rcu_barrier);
if (err) {
pr_err("kmem_cache_destroy %s: Slab cache still has objects\n",
s->name);
dump_stack();
}
out_unlock:
mutex_unlock(&slab_mutex);
put_online_mems();
put_online_cpus();
release_caches(&release, need_rcu_barrier);
}
int kmem_cache_shrink(struct kmem_cache *cachep)
{
int ret;
get_online_cpus();
get_online_mems();
kasan_cache_shrink(cachep);
ret = __kmem_cache_shrink(cachep, false);
put_online_mems();
put_online_cpus();
return ret;
}
bool slab_is_available(void)
{
return slab_state >= UP;
}
void __init create_boot_cache(struct kmem_cache *s, const char *name, size_t size,
unsigned long flags)
{
int err;
s->name = name;
s->size = s->object_size = size;
s->align = calculate_alignment(flags, ARCH_KMALLOC_MINALIGN, size);
slab_init_memcg_params(s);
err = __kmem_cache_create(s, flags);
if (err)
panic("Creation of kmalloc slab %s size=%zu failed. Reason %d\n",
name, size, err);
s->refcount = -1;
}
struct kmem_cache *__init create_kmalloc_cache(const char *name, size_t size,
unsigned long flags)
{
struct kmem_cache *s = kmem_cache_zalloc(kmem_cache, GFP_NOWAIT);
if (!s)
panic("Out of memory when creating slab %s\n", name);
create_boot_cache(s, name, size, flags);
list_add(&s->list, &slab_caches);
s->refcount = 1;
return s;
}
static inline int size_index_elem(size_t bytes)
{
return (bytes - 1) / 8;
}
struct kmem_cache *kmalloc_slab(size_t size, gfp_t flags)
{
int index;
if (unlikely(size > KMALLOC_MAX_SIZE)) {
WARN_ON_ONCE(!(flags & __GFP_NOWARN));
return NULL;
}
if (size <= 192) {
if (!size)
return ZERO_SIZE_PTR;
index = size_index[size_index_elem(size)];
} else
index = fls(size - 1);
#ifdef CONFIG_ZONE_DMA
if (unlikely((flags & GFP_DMA)))
return kmalloc_dma_caches[index];
#endif
return kmalloc_caches[index];
}
void __init setup_kmalloc_cache_index_table(void)
{
int i;
BUILD_BUG_ON(KMALLOC_MIN_SIZE > 256 ||
(KMALLOC_MIN_SIZE & (KMALLOC_MIN_SIZE - 1)));
for (i = 8; i < KMALLOC_MIN_SIZE; i += 8) {
int elem = size_index_elem(i);
if (elem >= ARRAY_SIZE(size_index))
break;
size_index[elem] = KMALLOC_SHIFT_LOW;
}
if (KMALLOC_MIN_SIZE >= 64) {
for (i = 64 + 8; i <= 96; i += 8)
size_index[size_index_elem(i)] = 7;
}
if (KMALLOC_MIN_SIZE >= 128) {
for (i = 128 + 8; i <= 192; i += 8)
size_index[size_index_elem(i)] = 8;
}
}
static void __init new_kmalloc_cache(int idx, unsigned long flags)
{
kmalloc_caches[idx] = create_kmalloc_cache(kmalloc_info[idx].name,
kmalloc_info[idx].size, flags);
}
void __init create_kmalloc_caches(unsigned long flags)
{
int i;
for (i = KMALLOC_SHIFT_LOW; i <= KMALLOC_SHIFT_HIGH; i++) {
if (!kmalloc_caches[i])
new_kmalloc_cache(i, flags);
if (KMALLOC_MIN_SIZE <= 32 && !kmalloc_caches[1] && i == 6)
new_kmalloc_cache(1, flags);
if (KMALLOC_MIN_SIZE <= 64 && !kmalloc_caches[2] && i == 7)
new_kmalloc_cache(2, flags);
}
slab_state = UP;
#ifdef CONFIG_ZONE_DMA
for (i = 0; i <= KMALLOC_SHIFT_HIGH; i++) {
struct kmem_cache *s = kmalloc_caches[i];
if (s) {
int size = kmalloc_size(i);
char *n = kasprintf(GFP_NOWAIT,
"dma-kmalloc-%d", size);
BUG_ON(!n);
kmalloc_dma_caches[i] = create_kmalloc_cache(n,
size, SLAB_CACHE_DMA | flags);
}
}
#endif
}
void *kmalloc_order(size_t size, gfp_t flags, unsigned int order)
{
void *ret;
struct page *page;
flags |= __GFP_COMP;
page = alloc_pages(flags, order);
ret = page ? page_address(page) : NULL;
kmemleak_alloc(ret, size, 1, flags);
kasan_kmalloc_large(ret, size, flags);
return ret;
}
void *kmalloc_order_trace(size_t size, gfp_t flags, unsigned int order)
{
void *ret = kmalloc_order(size, flags, order);
trace_kmalloc(_RET_IP_, ret, size, PAGE_SIZE << order, flags);
return ret;
}
static void freelist_randomize(struct rnd_state *state, unsigned int *list,
size_t count)
{
size_t i;
unsigned int rand;
for (i = 0; i < count; i++)
list[i] = i;
for (i = count - 1; i > 0; i--) {
rand = prandom_u32_state(state);
rand %= (i + 1);
swap(list[i], list[rand]);
}
}
int cache_random_seq_create(struct kmem_cache *cachep, unsigned int count,
gfp_t gfp)
{
struct rnd_state state;
if (count < 2 || cachep->random_seq)
return 0;
cachep->random_seq = kcalloc(count, sizeof(unsigned int), gfp);
if (!cachep->random_seq)
return -ENOMEM;
prandom_seed_state(&state, get_random_long());
freelist_randomize(&state, cachep->random_seq, count);
return 0;
}
void cache_random_seq_destroy(struct kmem_cache *cachep)
{
kfree(cachep->random_seq);
cachep->random_seq = NULL;
}
static void print_slabinfo_header(struct seq_file *m)
{
#ifdef CONFIG_DEBUG_SLAB
seq_puts(m, "slabinfo - version: 2.1 (statistics)\n");
#else
seq_puts(m, "slabinfo - version: 2.1\n");
#endif
seq_puts(m, "# name <active_objs> <num_objs> <objsize> <objperslab> <pagesperslab>");
seq_puts(m, " : tunables <limit> <batchcount> <sharedfactor>");
seq_puts(m, " : slabdata <active_slabs> <num_slabs> <sharedavail>");
#ifdef CONFIG_DEBUG_SLAB
seq_puts(m, " : globalstat <listallocs> <maxobjs> <grown> <reaped> <error> <maxfreeable> <nodeallocs> <remotefrees> <alienoverflow>");
seq_puts(m, " : cpustat <allochit> <allocmiss> <freehit> <freemiss>");
#endif
seq_putc(m, '\n');
}
void *slab_start(struct seq_file *m, loff_t *pos)
{
mutex_lock(&slab_mutex);
return seq_list_start(&slab_caches, *pos);
}
void *slab_next(struct seq_file *m, void *p, loff_t *pos)
{
return seq_list_next(p, &slab_caches, pos);
}
void slab_stop(struct seq_file *m, void *p)
{
mutex_unlock(&slab_mutex);
}
static void
memcg_accumulate_slabinfo(struct kmem_cache *s, struct slabinfo *info)
{
struct kmem_cache *c;
struct slabinfo sinfo;
if (!is_root_cache(s))
return;
for_each_memcg_cache(c, s) {
memset(&sinfo, 0, sizeof(sinfo));
get_slabinfo(c, &sinfo);
info->active_slabs += sinfo.active_slabs;
info->num_slabs += sinfo.num_slabs;
info->shared_avail += sinfo.shared_avail;
info->active_objs += sinfo.active_objs;
info->num_objs += sinfo.num_objs;
}
}
static void cache_show(struct kmem_cache *s, struct seq_file *m)
{
struct slabinfo sinfo;
memset(&sinfo, 0, sizeof(sinfo));
get_slabinfo(s, &sinfo);
memcg_accumulate_slabinfo(s, &sinfo);
seq_printf(m, "%-17s %6lu %6lu %6u %4u %4d",
cache_name(s), sinfo.active_objs, sinfo.num_objs, s->size,
sinfo.objects_per_slab, (1 << sinfo.cache_order));
seq_printf(m, " : tunables %4u %4u %4u",
sinfo.limit, sinfo.batchcount, sinfo.shared);
seq_printf(m, " : slabdata %6lu %6lu %6lu",
sinfo.active_slabs, sinfo.num_slabs, sinfo.shared_avail);
slabinfo_show_stats(m, s);
seq_putc(m, '\n');
}
static int slab_show(struct seq_file *m, void *p)
{
struct kmem_cache *s = list_entry(p, struct kmem_cache, list);
if (p == slab_caches.next)
print_slabinfo_header(m);
if (is_root_cache(s))
cache_show(s, m);
return 0;
}
int memcg_slab_show(struct seq_file *m, void *p)
{
struct kmem_cache *s = list_entry(p, struct kmem_cache, list);
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
if (p == slab_caches.next)
print_slabinfo_header(m);
if (!is_root_cache(s) && s->memcg_params.memcg == memcg)
cache_show(s, m);
return 0;
}
static int slabinfo_open(struct inode *inode, struct file *file)
{
return seq_open(file, &slabinfo_op);
}
static int __init slab_proc_init(void)
{
proc_create("slabinfo", SLABINFO_RIGHTS, NULL,
&proc_slabinfo_operations);
return 0;
}
static __always_inline void *__do_krealloc(const void *p, size_t new_size,
gfp_t flags)
{
void *ret;
size_t ks = 0;
if (p)
ks = ksize(p);
if (ks >= new_size) {
kasan_krealloc((void *)p, new_size, flags);
return (void *)p;
}
ret = kmalloc_track_caller(new_size, flags);
if (ret && p)
memcpy(ret, p, ks);
return ret;
}
void *__krealloc(const void *p, size_t new_size, gfp_t flags)
{
if (unlikely(!new_size))
return ZERO_SIZE_PTR;
return __do_krealloc(p, new_size, flags);
}
void *krealloc(const void *p, size_t new_size, gfp_t flags)
{
void *ret;
if (unlikely(!new_size)) {
kfree(p);
return ZERO_SIZE_PTR;
}
ret = __do_krealloc(p, new_size, flags);
if (ret && p != ret)
kfree(p);
return ret;
}
void kzfree(const void *p)
{
size_t ks;
void *mem = (void *)p;
if (unlikely(ZERO_OR_NULL_PTR(mem)))
return;
ks = ksize(mem);
memset(mem, 0, ks);
kfree(mem);
}
