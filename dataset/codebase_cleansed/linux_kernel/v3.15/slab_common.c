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
#if !defined(CONFIG_SLUB) || !defined(CONFIG_SLUB_DEBUG_ON)
if (!strcmp(s->name, name)) {
pr_err("%s (%s): Cache name already exists.\n",
__func__, name);
dump_stack();
s = NULL;
return -EINVAL;
}
#endif
}
WARN_ON(strchr(name, ' '));
return 0;
}
static inline int kmem_cache_sanity_check(const char *name, size_t size)
{
return 0;
}
int memcg_update_all_caches(int num_memcgs)
{
struct kmem_cache *s;
int ret = 0;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list) {
if (!is_root_cache(s))
continue;
ret = memcg_update_cache_size(s, num_memcgs);
if (ret)
goto out;
}
memcg_update_array_size(num_memcgs);
out:
mutex_unlock(&slab_mutex);
return ret;
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
static struct kmem_cache *
do_kmem_cache_create(char *name, size_t object_size, size_t size, size_t align,
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
err = memcg_alloc_cache_params(memcg, s, root_cache);
if (err)
goto out_free_cache;
err = __kmem_cache_create(s, flags);
if (err)
goto out_free_cache;
s->refcount = 1;
list_add(&s->list, &slab_caches);
memcg_register_cache(s);
out:
if (err)
return ERR_PTR(err);
return s;
out_free_cache:
memcg_free_cache_params(s);
kfree(s);
goto out;
}
struct kmem_cache *
kmem_cache_create(const char *name, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *))
{
struct kmem_cache *s;
char *cache_name;
int err;
get_online_cpus();
mutex_lock(&slab_mutex);
err = kmem_cache_sanity_check(name, size);
if (err)
goto out_unlock;
flags &= CACHE_CREATE_MASK;
s = __kmem_cache_alias(name, size, align, flags, ctor);
if (s)
goto out_unlock;
cache_name = kstrdup(name, GFP_KERNEL);
if (!cache_name) {
err = -ENOMEM;
goto out_unlock;
}
s = do_kmem_cache_create(cache_name, size, size,
calculate_alignment(flags, align, size),
flags, ctor, NULL, NULL);
if (IS_ERR(s)) {
err = PTR_ERR(s);
kfree(cache_name);
}
out_unlock:
mutex_unlock(&slab_mutex);
put_online_cpus();
if (err) {
if (flags & SLAB_PANIC)
panic("kmem_cache_create: Failed to create slab '%s'. Error %d\n",
name, err);
else {
printk(KERN_WARNING "kmem_cache_create(%s) failed with error %d",
name, err);
dump_stack();
}
return NULL;
}
return s;
}
void kmem_cache_create_memcg(struct mem_cgroup *memcg, struct kmem_cache *root_cache)
{
struct kmem_cache *s;
char *cache_name;
get_online_cpus();
mutex_lock(&slab_mutex);
if (cache_from_memcg_idx(root_cache, memcg_cache_id(memcg)))
goto out_unlock;
cache_name = memcg_create_cache_name(memcg, root_cache);
if (!cache_name)
goto out_unlock;
s = do_kmem_cache_create(cache_name, root_cache->object_size,
root_cache->size, root_cache->align,
root_cache->flags, root_cache->ctor,
memcg, root_cache);
if (IS_ERR(s)) {
kfree(cache_name);
goto out_unlock;
}
s->allocflags |= __GFP_KMEMCG;
out_unlock:
mutex_unlock(&slab_mutex);
put_online_cpus();
}
static int kmem_cache_destroy_memcg_children(struct kmem_cache *s)
{
int rc;
if (!s->memcg_params ||
!s->memcg_params->is_root_cache)
return 0;
mutex_unlock(&slab_mutex);
rc = __kmem_cache_destroy_memcg_children(s);
mutex_lock(&slab_mutex);
return rc;
}
static int kmem_cache_destroy_memcg_children(struct kmem_cache *s)
{
return 0;
}
void slab_kmem_cache_release(struct kmem_cache *s)
{
kfree(s->name);
kmem_cache_free(kmem_cache, s);
}
void kmem_cache_destroy(struct kmem_cache *s)
{
get_online_cpus();
mutex_lock(&slab_mutex);
s->refcount--;
if (s->refcount)
goto out_unlock;
if (kmem_cache_destroy_memcg_children(s) != 0)
goto out_unlock;
list_del(&s->list);
memcg_unregister_cache(s);
if (__kmem_cache_shutdown(s) != 0) {
list_add(&s->list, &slab_caches);
memcg_register_cache(s);
printk(KERN_ERR "kmem_cache_destroy %s: "
"Slab cache still has objects\n", s->name);
dump_stack();
goto out_unlock;
}
mutex_unlock(&slab_mutex);
if (s->flags & SLAB_DESTROY_BY_RCU)
rcu_barrier();
memcg_free_cache_params(s);
#ifdef SLAB_SUPPORTS_SYSFS
sysfs_slab_remove(s);
#else
slab_kmem_cache_release(s);
#endif
goto out_put_cpus;
out_unlock:
mutex_unlock(&slab_mutex);
out_put_cpus:
put_online_cpus();
}
int slab_is_available(void)
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
void __init create_kmalloc_caches(unsigned long flags)
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
for (i = KMALLOC_SHIFT_LOW; i <= KMALLOC_SHIFT_HIGH; i++) {
if (!kmalloc_caches[i]) {
kmalloc_caches[i] = create_kmalloc_cache(NULL,
1 << i, flags);
}
if (KMALLOC_MIN_SIZE <= 32 && !kmalloc_caches[1] && i == 6)
kmalloc_caches[1] = create_kmalloc_cache(NULL, 96, flags);
if (KMALLOC_MIN_SIZE <= 64 && !kmalloc_caches[2] && i == 7)
kmalloc_caches[2] = create_kmalloc_cache(NULL, 192, flags);
}
slab_state = UP;
for (i = 0; i <= KMALLOC_SHIFT_HIGH; i++) {
struct kmem_cache *s = kmalloc_caches[i];
char *n;
if (s) {
n = kasprintf(GFP_NOWAIT, "kmalloc-%d", kmalloc_size(i));
BUG_ON(!n);
s->name = n;
}
}
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
void *kmalloc_order_trace(size_t size, gfp_t flags, unsigned int order)
{
void *ret = kmalloc_order(size, flags, order);
trace_kmalloc(_RET_IP_, ret, size, PAGE_SIZE << order, flags);
return ret;
}
void print_slabinfo_header(struct seq_file *m)
{
#ifdef CONFIG_DEBUG_SLAB
seq_puts(m, "slabinfo - version: 2.1 (statistics)\n");
#else
seq_puts(m, "slabinfo - version: 2.1\n");
#endif
seq_puts(m, "# name <active_objs> <num_objs> <objsize> "
"<objperslab> <pagesperslab>");
seq_puts(m, " : tunables <limit> <batchcount> <sharedfactor>");
seq_puts(m, " : slabdata <active_slabs> <num_slabs> <sharedavail>");
#ifdef CONFIG_DEBUG_SLAB
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
int i;
if (!is_root_cache(s))
return;
for_each_memcg_cache_index(i) {
c = cache_from_memcg_idx(s, i);
if (!c)
continue;
memset(&sinfo, 0, sizeof(sinfo));
get_slabinfo(c, &sinfo);
info->active_slabs += sinfo.active_slabs;
info->num_slabs += sinfo.num_slabs;
info->shared_avail += sinfo.shared_avail;
info->active_objs += sinfo.active_objs;
info->num_objs += sinfo.num_objs;
}
}
int cache_show(struct kmem_cache *s, struct seq_file *m)
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
return 0;
}
static int s_show(struct seq_file *m, void *p)
{
struct kmem_cache *s = list_entry(p, struct kmem_cache, list);
if (!is_root_cache(s))
return 0;
return cache_show(s, m);
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
