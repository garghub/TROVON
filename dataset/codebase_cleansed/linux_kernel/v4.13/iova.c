void
init_iova_domain(struct iova_domain *iovad, unsigned long granule,
unsigned long start_pfn, unsigned long pfn_32bit)
{
BUG_ON((granule > PAGE_SIZE) || !is_power_of_2(granule));
spin_lock_init(&iovad->iova_rbtree_lock);
iovad->rbroot = RB_ROOT;
iovad->cached32_node = NULL;
iovad->granule = granule;
iovad->start_pfn = start_pfn;
iovad->dma_32bit_pfn = pfn_32bit + 1;
init_iova_rcaches(iovad);
}
static struct rb_node *
__get_cached_rbnode(struct iova_domain *iovad, unsigned long *limit_pfn)
{
if ((*limit_pfn > iovad->dma_32bit_pfn) ||
(iovad->cached32_node == NULL))
return rb_last(&iovad->rbroot);
else {
struct rb_node *prev_node = rb_prev(iovad->cached32_node);
struct iova *curr_iova =
rb_entry(iovad->cached32_node, struct iova, node);
*limit_pfn = curr_iova->pfn_lo;
return prev_node;
}
}
static void
__cached_rbnode_insert_update(struct iova_domain *iovad,
unsigned long limit_pfn, struct iova *new)
{
if (limit_pfn != iovad->dma_32bit_pfn)
return;
iovad->cached32_node = &new->node;
}
static void
__cached_rbnode_delete_update(struct iova_domain *iovad, struct iova *free)
{
struct iova *cached_iova;
struct rb_node *curr;
if (!iovad->cached32_node)
return;
curr = iovad->cached32_node;
cached_iova = rb_entry(curr, struct iova, node);
if (free->pfn_lo >= cached_iova->pfn_lo) {
struct rb_node *node = rb_next(&free->node);
struct iova *iova = rb_entry(node, struct iova, node);
if (node && iova->pfn_lo < iovad->dma_32bit_pfn)
iovad->cached32_node = node;
else
iovad->cached32_node = NULL;
}
}
static void
iova_insert_rbtree(struct rb_root *root, struct iova *iova,
struct rb_node *start)
{
struct rb_node **new, *parent = NULL;
new = (start) ? &start : &(root->rb_node);
while (*new) {
struct iova *this = rb_entry(*new, struct iova, node);
parent = *new;
if (iova->pfn_lo < this->pfn_lo)
new = &((*new)->rb_left);
else if (iova->pfn_lo > this->pfn_lo)
new = &((*new)->rb_right);
else {
WARN_ON(1);
return;
}
}
rb_link_node(&iova->node, parent, new);
rb_insert_color(&iova->node, root);
}
static unsigned int
iova_get_pad_size(unsigned int size, unsigned int limit_pfn)
{
return (limit_pfn - size) & (__roundup_pow_of_two(size) - 1);
}
static int __alloc_and_insert_iova_range(struct iova_domain *iovad,
unsigned long size, unsigned long limit_pfn,
struct iova *new, bool size_aligned)
{
struct rb_node *prev, *curr = NULL;
unsigned long flags;
unsigned long saved_pfn;
unsigned int pad_size = 0;
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
saved_pfn = limit_pfn;
curr = __get_cached_rbnode(iovad, &limit_pfn);
prev = curr;
while (curr) {
struct iova *curr_iova = rb_entry(curr, struct iova, node);
if (limit_pfn <= curr_iova->pfn_lo) {
goto move_left;
} else if (limit_pfn > curr_iova->pfn_hi) {
if (size_aligned)
pad_size = iova_get_pad_size(size, limit_pfn);
if ((curr_iova->pfn_hi + size + pad_size) < limit_pfn)
break;
}
limit_pfn = curr_iova->pfn_lo;
move_left:
prev = curr;
curr = rb_prev(curr);
}
if (!curr) {
if (size_aligned)
pad_size = iova_get_pad_size(size, limit_pfn);
if ((iovad->start_pfn + size + pad_size) > limit_pfn) {
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
return -ENOMEM;
}
}
new->pfn_lo = limit_pfn - (size + pad_size);
new->pfn_hi = new->pfn_lo + size - 1;
iova_insert_rbtree(&iovad->rbroot, new, prev);
__cached_rbnode_insert_update(iovad, saved_pfn, new);
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
return 0;
}
struct iova *alloc_iova_mem(void)
{
return kmem_cache_alloc(iova_cache, GFP_ATOMIC);
}
void free_iova_mem(struct iova *iova)
{
kmem_cache_free(iova_cache, iova);
}
int iova_cache_get(void)
{
mutex_lock(&iova_cache_mutex);
if (!iova_cache_users) {
iova_cache = kmem_cache_create(
"iommu_iova", sizeof(struct iova), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!iova_cache) {
mutex_unlock(&iova_cache_mutex);
printk(KERN_ERR "Couldn't create iova cache\n");
return -ENOMEM;
}
}
iova_cache_users++;
mutex_unlock(&iova_cache_mutex);
return 0;
}
void iova_cache_put(void)
{
mutex_lock(&iova_cache_mutex);
if (WARN_ON(!iova_cache_users)) {
mutex_unlock(&iova_cache_mutex);
return;
}
iova_cache_users--;
if (!iova_cache_users)
kmem_cache_destroy(iova_cache);
mutex_unlock(&iova_cache_mutex);
}
struct iova *
alloc_iova(struct iova_domain *iovad, unsigned long size,
unsigned long limit_pfn,
bool size_aligned)
{
struct iova *new_iova;
int ret;
new_iova = alloc_iova_mem();
if (!new_iova)
return NULL;
ret = __alloc_and_insert_iova_range(iovad, size, limit_pfn + 1,
new_iova, size_aligned);
if (ret) {
free_iova_mem(new_iova);
return NULL;
}
return new_iova;
}
static struct iova *
private_find_iova(struct iova_domain *iovad, unsigned long pfn)
{
struct rb_node *node = iovad->rbroot.rb_node;
assert_spin_locked(&iovad->iova_rbtree_lock);
while (node) {
struct iova *iova = rb_entry(node, struct iova, node);
if ((pfn >= iova->pfn_lo) && (pfn <= iova->pfn_hi)) {
return iova;
}
if (pfn < iova->pfn_lo)
node = node->rb_left;
else if (pfn > iova->pfn_lo)
node = node->rb_right;
}
return NULL;
}
static void private_free_iova(struct iova_domain *iovad, struct iova *iova)
{
assert_spin_locked(&iovad->iova_rbtree_lock);
__cached_rbnode_delete_update(iovad, iova);
rb_erase(&iova->node, &iovad->rbroot);
free_iova_mem(iova);
}
struct iova *find_iova(struct iova_domain *iovad, unsigned long pfn)
{
unsigned long flags;
struct iova *iova;
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
iova = private_find_iova(iovad, pfn);
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
return iova;
}
void
__free_iova(struct iova_domain *iovad, struct iova *iova)
{
unsigned long flags;
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
private_free_iova(iovad, iova);
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
}
void
free_iova(struct iova_domain *iovad, unsigned long pfn)
{
struct iova *iova = find_iova(iovad, pfn);
if (iova)
__free_iova(iovad, iova);
}
unsigned long
alloc_iova_fast(struct iova_domain *iovad, unsigned long size,
unsigned long limit_pfn)
{
bool flushed_rcache = false;
unsigned long iova_pfn;
struct iova *new_iova;
iova_pfn = iova_rcache_get(iovad, size, limit_pfn);
if (iova_pfn)
return iova_pfn;
retry:
new_iova = alloc_iova(iovad, size, limit_pfn, true);
if (!new_iova) {
unsigned int cpu;
if (flushed_rcache)
return 0;
flushed_rcache = true;
for_each_online_cpu(cpu)
free_cpu_cached_iovas(cpu, iovad);
goto retry;
}
return new_iova->pfn_lo;
}
void
free_iova_fast(struct iova_domain *iovad, unsigned long pfn, unsigned long size)
{
if (iova_rcache_insert(iovad, pfn, size))
return;
free_iova(iovad, pfn);
}
void put_iova_domain(struct iova_domain *iovad)
{
struct rb_node *node;
unsigned long flags;
free_iova_rcaches(iovad);
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
node = rb_first(&iovad->rbroot);
while (node) {
struct iova *iova = rb_entry(node, struct iova, node);
rb_erase(node, &iovad->rbroot);
free_iova_mem(iova);
node = rb_first(&iovad->rbroot);
}
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
}
static int
__is_range_overlap(struct rb_node *node,
unsigned long pfn_lo, unsigned long pfn_hi)
{
struct iova *iova = rb_entry(node, struct iova, node);
if ((pfn_lo <= iova->pfn_hi) && (pfn_hi >= iova->pfn_lo))
return 1;
return 0;
}
static inline struct iova *
alloc_and_init_iova(unsigned long pfn_lo, unsigned long pfn_hi)
{
struct iova *iova;
iova = alloc_iova_mem();
if (iova) {
iova->pfn_lo = pfn_lo;
iova->pfn_hi = pfn_hi;
}
return iova;
}
static struct iova *
__insert_new_range(struct iova_domain *iovad,
unsigned long pfn_lo, unsigned long pfn_hi)
{
struct iova *iova;
iova = alloc_and_init_iova(pfn_lo, pfn_hi);
if (iova)
iova_insert_rbtree(&iovad->rbroot, iova, NULL);
return iova;
}
static void
__adjust_overlap_range(struct iova *iova,
unsigned long *pfn_lo, unsigned long *pfn_hi)
{
if (*pfn_lo < iova->pfn_lo)
iova->pfn_lo = *pfn_lo;
if (*pfn_hi > iova->pfn_hi)
*pfn_lo = iova->pfn_hi + 1;
}
struct iova *
reserve_iova(struct iova_domain *iovad,
unsigned long pfn_lo, unsigned long pfn_hi)
{
struct rb_node *node;
unsigned long flags;
struct iova *iova;
unsigned int overlap = 0;
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
for (node = rb_first(&iovad->rbroot); node; node = rb_next(node)) {
if (__is_range_overlap(node, pfn_lo, pfn_hi)) {
iova = rb_entry(node, struct iova, node);
__adjust_overlap_range(iova, &pfn_lo, &pfn_hi);
if ((pfn_lo >= iova->pfn_lo) &&
(pfn_hi <= iova->pfn_hi))
goto finish;
overlap = 1;
} else if (overlap)
break;
}
iova = __insert_new_range(iovad, pfn_lo, pfn_hi);
finish:
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
return iova;
}
void
copy_reserved_iova(struct iova_domain *from, struct iova_domain *to)
{
unsigned long flags;
struct rb_node *node;
spin_lock_irqsave(&from->iova_rbtree_lock, flags);
for (node = rb_first(&from->rbroot); node; node = rb_next(node)) {
struct iova *iova = rb_entry(node, struct iova, node);
struct iova *new_iova;
new_iova = reserve_iova(to, iova->pfn_lo, iova->pfn_hi);
if (!new_iova)
printk(KERN_ERR "Reserve iova range %lx@%lx failed\n",
iova->pfn_lo, iova->pfn_lo);
}
spin_unlock_irqrestore(&from->iova_rbtree_lock, flags);
}
struct iova *
split_and_remove_iova(struct iova_domain *iovad, struct iova *iova,
unsigned long pfn_lo, unsigned long pfn_hi)
{
unsigned long flags;
struct iova *prev = NULL, *next = NULL;
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
if (iova->pfn_lo < pfn_lo) {
prev = alloc_and_init_iova(iova->pfn_lo, pfn_lo - 1);
if (prev == NULL)
goto error;
}
if (iova->pfn_hi > pfn_hi) {
next = alloc_and_init_iova(pfn_hi + 1, iova->pfn_hi);
if (next == NULL)
goto error;
}
__cached_rbnode_delete_update(iovad, iova);
rb_erase(&iova->node, &iovad->rbroot);
if (prev) {
iova_insert_rbtree(&iovad->rbroot, prev, NULL);
iova->pfn_lo = pfn_lo;
}
if (next) {
iova_insert_rbtree(&iovad->rbroot, next, NULL);
iova->pfn_hi = pfn_hi;
}
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
return iova;
error:
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
if (prev)
free_iova_mem(prev);
return NULL;
}
static struct iova_magazine *iova_magazine_alloc(gfp_t flags)
{
return kzalloc(sizeof(struct iova_magazine), flags);
}
static void iova_magazine_free(struct iova_magazine *mag)
{
kfree(mag);
}
static void
iova_magazine_free_pfns(struct iova_magazine *mag, struct iova_domain *iovad)
{
unsigned long flags;
int i;
if (!mag)
return;
spin_lock_irqsave(&iovad->iova_rbtree_lock, flags);
for (i = 0 ; i < mag->size; ++i) {
struct iova *iova = private_find_iova(iovad, mag->pfns[i]);
BUG_ON(!iova);
private_free_iova(iovad, iova);
}
spin_unlock_irqrestore(&iovad->iova_rbtree_lock, flags);
mag->size = 0;
}
static bool iova_magazine_full(struct iova_magazine *mag)
{
return (mag && mag->size == IOVA_MAG_SIZE);
}
static bool iova_magazine_empty(struct iova_magazine *mag)
{
return (!mag || mag->size == 0);
}
static unsigned long iova_magazine_pop(struct iova_magazine *mag,
unsigned long limit_pfn)
{
BUG_ON(iova_magazine_empty(mag));
if (mag->pfns[mag->size - 1] >= limit_pfn)
return 0;
return mag->pfns[--mag->size];
}
static void iova_magazine_push(struct iova_magazine *mag, unsigned long pfn)
{
BUG_ON(iova_magazine_full(mag));
mag->pfns[mag->size++] = pfn;
}
static void init_iova_rcaches(struct iova_domain *iovad)
{
struct iova_cpu_rcache *cpu_rcache;
struct iova_rcache *rcache;
unsigned int cpu;
int i;
for (i = 0; i < IOVA_RANGE_CACHE_MAX_SIZE; ++i) {
rcache = &iovad->rcaches[i];
spin_lock_init(&rcache->lock);
rcache->depot_size = 0;
rcache->cpu_rcaches = __alloc_percpu(sizeof(*cpu_rcache), cache_line_size());
if (WARN_ON(!rcache->cpu_rcaches))
continue;
for_each_possible_cpu(cpu) {
cpu_rcache = per_cpu_ptr(rcache->cpu_rcaches, cpu);
spin_lock_init(&cpu_rcache->lock);
cpu_rcache->loaded = iova_magazine_alloc(GFP_KERNEL);
cpu_rcache->prev = iova_magazine_alloc(GFP_KERNEL);
}
}
}
static bool __iova_rcache_insert(struct iova_domain *iovad,
struct iova_rcache *rcache,
unsigned long iova_pfn)
{
struct iova_magazine *mag_to_free = NULL;
struct iova_cpu_rcache *cpu_rcache;
bool can_insert = false;
unsigned long flags;
cpu_rcache = raw_cpu_ptr(rcache->cpu_rcaches);
spin_lock_irqsave(&cpu_rcache->lock, flags);
if (!iova_magazine_full(cpu_rcache->loaded)) {
can_insert = true;
} else if (!iova_magazine_full(cpu_rcache->prev)) {
swap(cpu_rcache->prev, cpu_rcache->loaded);
can_insert = true;
} else {
struct iova_magazine *new_mag = iova_magazine_alloc(GFP_ATOMIC);
if (new_mag) {
spin_lock(&rcache->lock);
if (rcache->depot_size < MAX_GLOBAL_MAGS) {
rcache->depot[rcache->depot_size++] =
cpu_rcache->loaded;
} else {
mag_to_free = cpu_rcache->loaded;
}
spin_unlock(&rcache->lock);
cpu_rcache->loaded = new_mag;
can_insert = true;
}
}
if (can_insert)
iova_magazine_push(cpu_rcache->loaded, iova_pfn);
spin_unlock_irqrestore(&cpu_rcache->lock, flags);
if (mag_to_free) {
iova_magazine_free_pfns(mag_to_free, iovad);
iova_magazine_free(mag_to_free);
}
return can_insert;
}
static bool iova_rcache_insert(struct iova_domain *iovad, unsigned long pfn,
unsigned long size)
{
unsigned int log_size = order_base_2(size);
if (log_size >= IOVA_RANGE_CACHE_MAX_SIZE)
return false;
return __iova_rcache_insert(iovad, &iovad->rcaches[log_size], pfn);
}
static unsigned long __iova_rcache_get(struct iova_rcache *rcache,
unsigned long limit_pfn)
{
struct iova_cpu_rcache *cpu_rcache;
unsigned long iova_pfn = 0;
bool has_pfn = false;
unsigned long flags;
cpu_rcache = raw_cpu_ptr(rcache->cpu_rcaches);
spin_lock_irqsave(&cpu_rcache->lock, flags);
if (!iova_magazine_empty(cpu_rcache->loaded)) {
has_pfn = true;
} else if (!iova_magazine_empty(cpu_rcache->prev)) {
swap(cpu_rcache->prev, cpu_rcache->loaded);
has_pfn = true;
} else {
spin_lock(&rcache->lock);
if (rcache->depot_size > 0) {
iova_magazine_free(cpu_rcache->loaded);
cpu_rcache->loaded = rcache->depot[--rcache->depot_size];
has_pfn = true;
}
spin_unlock(&rcache->lock);
}
if (has_pfn)
iova_pfn = iova_magazine_pop(cpu_rcache->loaded, limit_pfn);
spin_unlock_irqrestore(&cpu_rcache->lock, flags);
return iova_pfn;
}
static unsigned long iova_rcache_get(struct iova_domain *iovad,
unsigned long size,
unsigned long limit_pfn)
{
unsigned int log_size = order_base_2(size);
if (log_size >= IOVA_RANGE_CACHE_MAX_SIZE)
return 0;
return __iova_rcache_get(&iovad->rcaches[log_size], limit_pfn);
}
static void free_cpu_iova_rcache(unsigned int cpu, struct iova_domain *iovad,
struct iova_rcache *rcache)
{
struct iova_cpu_rcache *cpu_rcache = per_cpu_ptr(rcache->cpu_rcaches, cpu);
unsigned long flags;
spin_lock_irqsave(&cpu_rcache->lock, flags);
iova_magazine_free_pfns(cpu_rcache->loaded, iovad);
iova_magazine_free(cpu_rcache->loaded);
iova_magazine_free_pfns(cpu_rcache->prev, iovad);
iova_magazine_free(cpu_rcache->prev);
spin_unlock_irqrestore(&cpu_rcache->lock, flags);
}
static void free_iova_rcaches(struct iova_domain *iovad)
{
struct iova_rcache *rcache;
unsigned long flags;
unsigned int cpu;
int i, j;
for (i = 0; i < IOVA_RANGE_CACHE_MAX_SIZE; ++i) {
rcache = &iovad->rcaches[i];
for_each_possible_cpu(cpu)
free_cpu_iova_rcache(cpu, iovad, rcache);
spin_lock_irqsave(&rcache->lock, flags);
free_percpu(rcache->cpu_rcaches);
for (j = 0; j < rcache->depot_size; ++j) {
iova_magazine_free_pfns(rcache->depot[j], iovad);
iova_magazine_free(rcache->depot[j]);
}
spin_unlock_irqrestore(&rcache->lock, flags);
}
}
void free_cpu_cached_iovas(unsigned int cpu, struct iova_domain *iovad)
{
struct iova_cpu_rcache *cpu_rcache;
struct iova_rcache *rcache;
unsigned long flags;
int i;
for (i = 0; i < IOVA_RANGE_CACHE_MAX_SIZE; ++i) {
rcache = &iovad->rcaches[i];
cpu_rcache = per_cpu_ptr(rcache->cpu_rcaches, cpu);
spin_lock_irqsave(&cpu_rcache->lock, flags);
iova_magazine_free_pfns(cpu_rcache->loaded, iovad);
iova_magazine_free_pfns(cpu_rcache->prev, iovad);
spin_unlock_irqrestore(&cpu_rcache->lock, flags);
}
}
