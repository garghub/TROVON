static inline u64 gen8_canonical_addr(u64 address)
{
return sign_extend64(address, GEN8_HIGH_ADDRESS_BIT);
}
static inline u64 gen8_noncanonical_addr(u64 address)
{
return address & GENMASK_ULL(GEN8_HIGH_ADDRESS_BIT, 0);
}
static int eb_create(struct i915_execbuffer *eb)
{
if (!(eb->args->flags & I915_EXEC_HANDLE_LUT)) {
unsigned int size = 1 + ilog2(eb->buffer_count);
do {
unsigned int flags;
flags = GFP_TEMPORARY;
if (size > 1)
flags |= __GFP_NORETRY | __GFP_NOWARN;
eb->buckets = kzalloc(sizeof(struct hlist_head) << size,
flags);
if (eb->buckets)
break;
} while (--size);
if (unlikely(!size))
return -ENOMEM;
eb->lut_size = size;
} else {
eb->lut_size = -eb->buffer_count;
}
return 0;
}
static bool
eb_vma_misplaced(const struct drm_i915_gem_exec_object2 *entry,
const struct i915_vma *vma)
{
if (!(entry->flags & __EXEC_OBJECT_HAS_PIN))
return true;
if (vma->node.size < entry->pad_to_size)
return true;
if (entry->alignment && !IS_ALIGNED(vma->node.start, entry->alignment))
return true;
if (entry->flags & EXEC_OBJECT_PINNED &&
vma->node.start != entry->offset)
return true;
if (entry->flags & __EXEC_OBJECT_NEEDS_BIAS &&
vma->node.start < BATCH_OFFSET_BIAS)
return true;
if (!(entry->flags & EXEC_OBJECT_SUPPORTS_48B_ADDRESS) &&
(vma->node.start + vma->node.size - 1) >> 32)
return true;
return false;
}
static inline void
eb_pin_vma(struct i915_execbuffer *eb,
struct drm_i915_gem_exec_object2 *entry,
struct i915_vma *vma)
{
u64 flags;
if (vma->node.size)
flags = vma->node.start;
else
flags = entry->offset & PIN_OFFSET_MASK;
flags |= PIN_USER | PIN_NOEVICT | PIN_OFFSET_FIXED;
if (unlikely(entry->flags & EXEC_OBJECT_NEEDS_GTT))
flags |= PIN_GLOBAL;
if (unlikely(i915_vma_pin(vma, 0, 0, flags)))
return;
if (unlikely(entry->flags & EXEC_OBJECT_NEEDS_FENCE)) {
if (unlikely(i915_vma_get_fence(vma))) {
i915_vma_unpin(vma);
return;
}
if (i915_vma_pin_fence(vma))
entry->flags |= __EXEC_OBJECT_HAS_FENCE;
}
entry->flags |= __EXEC_OBJECT_HAS_PIN;
}
static inline void
__eb_unreserve_vma(struct i915_vma *vma,
const struct drm_i915_gem_exec_object2 *entry)
{
GEM_BUG_ON(!(entry->flags & __EXEC_OBJECT_HAS_PIN));
if (unlikely(entry->flags & __EXEC_OBJECT_HAS_FENCE))
i915_vma_unpin_fence(vma);
__i915_vma_unpin(vma);
}
static inline void
eb_unreserve_vma(struct i915_vma *vma,
struct drm_i915_gem_exec_object2 *entry)
{
if (!(entry->flags & __EXEC_OBJECT_HAS_PIN))
return;
__eb_unreserve_vma(vma, entry);
entry->flags &= ~__EXEC_OBJECT_RESERVED;
}
static int
eb_validate_vma(struct i915_execbuffer *eb,
struct drm_i915_gem_exec_object2 *entry,
struct i915_vma *vma)
{
if (unlikely(entry->flags & eb->invalid_flags))
return -EINVAL;
if (unlikely(entry->alignment && !is_power_of_2(entry->alignment)))
return -EINVAL;
if (unlikely(entry->flags & EXEC_OBJECT_PINNED &&
entry->offset != gen8_canonical_addr(entry->offset & PAGE_MASK)))
return -EINVAL;
if (entry->flags & EXEC_OBJECT_PAD_TO_SIZE) {
if (unlikely(offset_in_page(entry->pad_to_size)))
return -EINVAL;
} else {
entry->pad_to_size = 0;
}
if (unlikely(vma->exec_entry)) {
DRM_DEBUG("Object [handle %d, index %d] appears more than once in object list\n",
entry->handle, (int)(entry - eb->exec));
return -EINVAL;
}
entry->offset = gen8_noncanonical_addr(entry->offset);
return 0;
}
static int
eb_add_vma(struct i915_execbuffer *eb,
struct drm_i915_gem_exec_object2 *entry,
struct i915_vma *vma)
{
int err;
GEM_BUG_ON(i915_vma_is_closed(vma));
if (!(eb->args->flags & __EXEC_VALIDATED)) {
err = eb_validate_vma(eb, entry, vma);
if (unlikely(err))
return err;
}
if (eb->lut_size > 0) {
vma->exec_handle = entry->handle;
hlist_add_head(&vma->exec_node,
&eb->buckets[hash_32(entry->handle,
eb->lut_size)]);
}
if (entry->relocation_count)
list_add_tail(&vma->reloc_link, &eb->relocs);
if (!eb->reloc_cache.has_fence) {
entry->flags &= ~EXEC_OBJECT_NEEDS_FENCE;
} else {
if ((entry->flags & EXEC_OBJECT_NEEDS_FENCE ||
eb->reloc_cache.needs_unfenced) &&
i915_gem_object_is_tiled(vma->obj))
entry->flags |= EXEC_OBJECT_NEEDS_GTT | __EXEC_OBJECT_NEEDS_MAP;
}
if (!(entry->flags & EXEC_OBJECT_PINNED))
entry->flags |= eb->context_flags;
vma->exec_entry = entry;
__exec_to_vma(entry) = (uintptr_t)vma;
err = 0;
eb_pin_vma(eb, entry, vma);
if (eb_vma_misplaced(entry, vma)) {
eb_unreserve_vma(vma, entry);
list_add_tail(&vma->exec_link, &eb->unbound);
if (drm_mm_node_allocated(&vma->node))
err = i915_vma_unbind(vma);
} else {
if (entry->offset != vma->node.start) {
entry->offset = vma->node.start | UPDATE;
eb->args->flags |= __EXEC_HAS_RELOC;
}
}
return err;
}
static inline int use_cpu_reloc(const struct reloc_cache *cache,
const struct drm_i915_gem_object *obj)
{
if (!i915_gem_object_has_struct_page(obj))
return false;
if (DBG_FORCE_RELOC == FORCE_CPU_RELOC)
return true;
if (DBG_FORCE_RELOC == FORCE_GTT_RELOC)
return false;
return (cache->has_llc ||
obj->cache_dirty ||
obj->cache_level != I915_CACHE_NONE);
}
static int eb_reserve_vma(const struct i915_execbuffer *eb,
struct i915_vma *vma)
{
struct drm_i915_gem_exec_object2 *entry = vma->exec_entry;
u64 flags;
int err;
flags = PIN_USER | PIN_NONBLOCK;
if (entry->flags & EXEC_OBJECT_NEEDS_GTT)
flags |= PIN_GLOBAL;
if (!(entry->flags & EXEC_OBJECT_SUPPORTS_48B_ADDRESS))
flags |= PIN_ZONE_4G;
if (entry->flags & __EXEC_OBJECT_NEEDS_MAP)
flags |= PIN_MAPPABLE;
if (entry->flags & EXEC_OBJECT_PINNED) {
flags |= entry->offset | PIN_OFFSET_FIXED;
flags &= ~PIN_NONBLOCK;
} else if (entry->flags & __EXEC_OBJECT_NEEDS_BIAS) {
flags |= BATCH_OFFSET_BIAS | PIN_OFFSET_BIAS;
}
err = i915_vma_pin(vma, entry->pad_to_size, entry->alignment, flags);
if (err)
return err;
if (entry->offset != vma->node.start) {
entry->offset = vma->node.start | UPDATE;
eb->args->flags |= __EXEC_HAS_RELOC;
}
if (unlikely(entry->flags & EXEC_OBJECT_NEEDS_FENCE)) {
err = i915_vma_get_fence(vma);
if (unlikely(err)) {
i915_vma_unpin(vma);
return err;
}
if (i915_vma_pin_fence(vma))
entry->flags |= __EXEC_OBJECT_HAS_FENCE;
}
entry->flags |= __EXEC_OBJECT_HAS_PIN;
GEM_BUG_ON(eb_vma_misplaced(entry, vma));
return 0;
}
static int eb_reserve(struct i915_execbuffer *eb)
{
const unsigned int count = eb->buffer_count;
struct list_head last;
struct i915_vma *vma;
unsigned int i, pass;
int err;
pass = 0;
err = 0;
do {
list_for_each_entry(vma, &eb->unbound, exec_link) {
err = eb_reserve_vma(eb, vma);
if (err)
break;
}
if (err != -ENOSPC)
return err;
INIT_LIST_HEAD(&eb->unbound);
INIT_LIST_HEAD(&last);
for (i = 0; i < count; i++) {
struct drm_i915_gem_exec_object2 *entry = &eb->exec[i];
if (entry->flags & EXEC_OBJECT_PINNED &&
entry->flags & __EXEC_OBJECT_HAS_PIN)
continue;
vma = exec_to_vma(entry);
eb_unreserve_vma(vma, entry);
if (entry->flags & EXEC_OBJECT_PINNED)
list_add(&vma->exec_link, &eb->unbound);
else if (entry->flags & __EXEC_OBJECT_NEEDS_MAP)
list_add_tail(&vma->exec_link, &eb->unbound);
else
list_add_tail(&vma->exec_link, &last);
}
list_splice_tail(&last, &eb->unbound);
switch (pass++) {
case 0:
break;
case 1:
err = i915_gem_evict_vm(eb->vm);
if (err)
return err;
break;
default:
return -ENOSPC;
}
} while (1);
}
static inline struct hlist_head *
ht_head(const struct i915_gem_context_vma_lut *lut, u32 handle)
{
return &lut->ht[hash_32(handle, lut->ht_bits)];
}
static inline bool
ht_needs_resize(const struct i915_gem_context_vma_lut *lut)
{
return (4*lut->ht_count > 3*lut->ht_size ||
4*lut->ht_count + 1 < lut->ht_size);
}
static unsigned int eb_batch_index(const struct i915_execbuffer *eb)
{
if (eb->args->flags & I915_EXEC_BATCH_FIRST)
return 0;
else
return eb->buffer_count - 1;
}
static int eb_select_context(struct i915_execbuffer *eb)
{
struct i915_gem_context *ctx;
ctx = i915_gem_context_lookup(eb->file->driver_priv, eb->args->rsvd1);
if (unlikely(IS_ERR(ctx)))
return PTR_ERR(ctx);
if (unlikely(i915_gem_context_is_banned(ctx))) {
DRM_DEBUG("Context %u tried to submit while banned\n",
ctx->user_handle);
return -EIO;
}
eb->ctx = i915_gem_context_get(ctx);
eb->vm = ctx->ppgtt ? &ctx->ppgtt->base : &eb->i915->ggtt.base;
eb->context_flags = 0;
if (ctx->flags & CONTEXT_NO_ZEROMAP)
eb->context_flags |= __EXEC_OBJECT_NEEDS_BIAS;
return 0;
}
static int eb_lookup_vmas(struct i915_execbuffer *eb)
{
#define INTERMEDIATE BIT(0)
const unsigned int count = eb->buffer_count;
struct i915_gem_context_vma_lut *lut = &eb->ctx->vma_lut;
struct i915_vma *vma;
struct idr *idr;
unsigned int i;
int slow_pass = -1;
int err;
INIT_LIST_HEAD(&eb->relocs);
INIT_LIST_HEAD(&eb->unbound);
if (unlikely(lut->ht_size & I915_CTX_RESIZE_IN_PROGRESS))
flush_work(&lut->resize);
GEM_BUG_ON(lut->ht_size & I915_CTX_RESIZE_IN_PROGRESS);
for (i = 0; i < count; i++) {
__exec_to_vma(&eb->exec[i]) = 0;
hlist_for_each_entry(vma,
ht_head(lut, eb->exec[i].handle),
ctx_node) {
if (vma->ctx_handle != eb->exec[i].handle)
continue;
err = eb_add_vma(eb, &eb->exec[i], vma);
if (unlikely(err))
return err;
goto next_vma;
}
if (slow_pass < 0)
slow_pass = i;
next_vma: ;
}
if (slow_pass < 0)
goto out;
spin_lock(&eb->file->table_lock);
idr = &eb->file->object_idr;
for (i = slow_pass; i < count; i++) {
struct drm_i915_gem_object *obj;
if (__exec_to_vma(&eb->exec[i]))
continue;
obj = to_intel_bo(idr_find(idr, eb->exec[i].handle));
if (unlikely(!obj)) {
spin_unlock(&eb->file->table_lock);
DRM_DEBUG("Invalid object handle %d at index %d\n",
eb->exec[i].handle, i);
err = -ENOENT;
goto err;
}
__exec_to_vma(&eb->exec[i]) = INTERMEDIATE | (uintptr_t)obj;
}
spin_unlock(&eb->file->table_lock);
for (i = slow_pass; i < count; i++) {
struct drm_i915_gem_object *obj;
if (!(__exec_to_vma(&eb->exec[i]) & INTERMEDIATE))
continue;
obj = u64_to_ptr(typeof(*obj),
__exec_to_vma(&eb->exec[i]) & ~INTERMEDIATE);
vma = i915_vma_instance(obj, eb->vm, NULL);
if (unlikely(IS_ERR(vma))) {
DRM_DEBUG("Failed to lookup VMA\n");
err = PTR_ERR(vma);
goto err;
}
if (!vma->ctx) {
vma->ctx = eb->ctx;
vma->ctx_handle = eb->exec[i].handle;
hlist_add_head(&vma->ctx_node,
ht_head(lut, eb->exec[i].handle));
lut->ht_count++;
lut->ht_size |= I915_CTX_RESIZE_IN_PROGRESS;
if (i915_vma_is_ggtt(vma)) {
GEM_BUG_ON(obj->vma_hashed);
obj->vma_hashed = vma;
}
i915_vma_get(vma);
}
err = eb_add_vma(eb, &eb->exec[i], vma);
if (unlikely(err))
goto err;
if (vma->ctx != eb->ctx) {
i915_vma_get(vma);
eb->exec[i].flags |= __EXEC_OBJECT_HAS_REF;
}
}
if (lut->ht_size & I915_CTX_RESIZE_IN_PROGRESS) {
if (ht_needs_resize(lut))
queue_work(system_highpri_wq, &lut->resize);
else
lut->ht_size &= ~I915_CTX_RESIZE_IN_PROGRESS;
}
out:
i = eb_batch_index(eb);
eb->batch = exec_to_vma(&eb->exec[i]);
if (!(eb->exec[i].flags & EXEC_OBJECT_PINNED))
eb->exec[i].flags |= __EXEC_OBJECT_NEEDS_BIAS;
if (eb->reloc_cache.has_fence)
eb->exec[i].flags |= EXEC_OBJECT_NEEDS_FENCE;
eb->args->flags |= __EXEC_VALIDATED;
return eb_reserve(eb);
err:
for (i = slow_pass; i < count; i++) {
if (__exec_to_vma(&eb->exec[i]) & INTERMEDIATE)
__exec_to_vma(&eb->exec[i]) = 0;
}
lut->ht_size &= ~I915_CTX_RESIZE_IN_PROGRESS;
return err;
#undef INTERMEDIATE
}
static struct i915_vma *
eb_get_vma(const struct i915_execbuffer *eb, unsigned long handle)
{
if (eb->lut_size < 0) {
if (handle >= -eb->lut_size)
return NULL;
return exec_to_vma(&eb->exec[handle]);
} else {
struct hlist_head *head;
struct i915_vma *vma;
head = &eb->buckets[hash_32(handle, eb->lut_size)];
hlist_for_each_entry(vma, head, exec_node) {
if (vma->exec_handle == handle)
return vma;
}
return NULL;
}
}
static void eb_release_vmas(const struct i915_execbuffer *eb)
{
const unsigned int count = eb->buffer_count;
unsigned int i;
for (i = 0; i < count; i++) {
struct drm_i915_gem_exec_object2 *entry = &eb->exec[i];
struct i915_vma *vma = exec_to_vma(entry);
if (!vma)
continue;
GEM_BUG_ON(vma->exec_entry != entry);
vma->exec_entry = NULL;
__exec_to_vma(entry) = 0;
if (entry->flags & __EXEC_OBJECT_HAS_PIN)
__eb_unreserve_vma(vma, entry);
if (entry->flags & __EXEC_OBJECT_HAS_REF)
i915_vma_put(vma);
entry->flags &=
~(__EXEC_OBJECT_RESERVED | __EXEC_OBJECT_HAS_REF);
}
}
static void eb_reset_vmas(const struct i915_execbuffer *eb)
{
eb_release_vmas(eb);
if (eb->lut_size > 0)
memset(eb->buckets, 0,
sizeof(struct hlist_head) << eb->lut_size);
}
static void eb_destroy(const struct i915_execbuffer *eb)
{
GEM_BUG_ON(eb->reloc_cache.rq);
if (eb->lut_size > 0)
kfree(eb->buckets);
}
static inline u64
relocation_target(const struct drm_i915_gem_relocation_entry *reloc,
const struct i915_vma *target)
{
return gen8_canonical_addr((int)reloc->delta + target->node.start);
}
static void reloc_cache_init(struct reloc_cache *cache,
struct drm_i915_private *i915)
{
cache->page = -1;
cache->vaddr = 0;
cache->gen = INTEL_GEN(i915);
cache->has_llc = HAS_LLC(i915);
cache->use_64bit_reloc = HAS_64BIT_RELOC(i915);
cache->has_fence = cache->gen < 4;
cache->needs_unfenced = INTEL_INFO(i915)->unfenced_needs_alignment;
cache->node.allocated = false;
cache->rq = NULL;
cache->rq_size = 0;
}
static inline void *unmask_page(unsigned long p)
{
return (void *)(uintptr_t)(p & PAGE_MASK);
}
static inline unsigned int unmask_flags(unsigned long p)
{
return p & ~PAGE_MASK;
}
static inline struct i915_ggtt *cache_to_ggtt(struct reloc_cache *cache)
{
struct drm_i915_private *i915 =
container_of(cache, struct i915_execbuffer, reloc_cache)->i915;
return &i915->ggtt;
}
static void reloc_gpu_flush(struct reloc_cache *cache)
{
GEM_BUG_ON(cache->rq_size >= cache->rq->batch->obj->base.size / sizeof(u32));
cache->rq_cmd[cache->rq_size] = MI_BATCH_BUFFER_END;
i915_gem_object_unpin_map(cache->rq->batch->obj);
i915_gem_chipset_flush(cache->rq->i915);
__i915_add_request(cache->rq, true);
cache->rq = NULL;
}
static void reloc_cache_reset(struct reloc_cache *cache)
{
void *vaddr;
if (cache->rq)
reloc_gpu_flush(cache);
if (!cache->vaddr)
return;
vaddr = unmask_page(cache->vaddr);
if (cache->vaddr & KMAP) {
if (cache->vaddr & CLFLUSH_AFTER)
mb();
kunmap_atomic(vaddr);
i915_gem_obj_finish_shmem_access((struct drm_i915_gem_object *)cache->node.mm);
} else {
wmb();
io_mapping_unmap_atomic((void __iomem *)vaddr);
if (cache->node.allocated) {
struct i915_ggtt *ggtt = cache_to_ggtt(cache);
ggtt->base.clear_range(&ggtt->base,
cache->node.start,
cache->node.size);
drm_mm_remove_node(&cache->node);
} else {
i915_vma_unpin((struct i915_vma *)cache->node.mm);
}
}
cache->vaddr = 0;
cache->page = -1;
}
static void *reloc_kmap(struct drm_i915_gem_object *obj,
struct reloc_cache *cache,
unsigned long page)
{
void *vaddr;
if (cache->vaddr) {
kunmap_atomic(unmask_page(cache->vaddr));
} else {
unsigned int flushes;
int err;
err = i915_gem_obj_prepare_shmem_write(obj, &flushes);
if (err)
return ERR_PTR(err);
BUILD_BUG_ON(KMAP & CLFLUSH_FLAGS);
BUILD_BUG_ON((KMAP | CLFLUSH_FLAGS) & PAGE_MASK);
cache->vaddr = flushes | KMAP;
cache->node.mm = (void *)obj;
if (flushes)
mb();
}
vaddr = kmap_atomic(i915_gem_object_get_dirty_page(obj, page));
cache->vaddr = unmask_flags(cache->vaddr) | (unsigned long)vaddr;
cache->page = page;
return vaddr;
}
static void *reloc_iomap(struct drm_i915_gem_object *obj,
struct reloc_cache *cache,
unsigned long page)
{
struct i915_ggtt *ggtt = cache_to_ggtt(cache);
unsigned long offset;
void *vaddr;
if (cache->vaddr) {
io_mapping_unmap_atomic((void __force __iomem *) unmask_page(cache->vaddr));
} else {
struct i915_vma *vma;
int err;
if (use_cpu_reloc(cache, obj))
return NULL;
err = i915_gem_object_set_to_gtt_domain(obj, true);
if (err)
return ERR_PTR(err);
vma = i915_gem_object_ggtt_pin(obj, NULL, 0, 0,
PIN_MAPPABLE | PIN_NONBLOCK);
if (IS_ERR(vma)) {
memset(&cache->node, 0, sizeof(cache->node));
err = drm_mm_insert_node_in_range
(&ggtt->base.mm, &cache->node,
PAGE_SIZE, 0, I915_COLOR_UNEVICTABLE,
0, ggtt->mappable_end,
DRM_MM_INSERT_LOW);
if (err)
return NULL;
} else {
err = i915_vma_put_fence(vma);
if (err) {
i915_vma_unpin(vma);
return ERR_PTR(err);
}
cache->node.start = vma->node.start;
cache->node.mm = (void *)vma;
}
}
offset = cache->node.start;
if (cache->node.allocated) {
wmb();
ggtt->base.insert_page(&ggtt->base,
i915_gem_object_get_dma_address(obj, page),
offset, I915_CACHE_NONE, 0);
} else {
offset += page << PAGE_SHIFT;
}
vaddr = (void __force *)io_mapping_map_atomic_wc(&ggtt->mappable,
offset);
cache->page = page;
cache->vaddr = (unsigned long)vaddr;
return vaddr;
}
static void *reloc_vaddr(struct drm_i915_gem_object *obj,
struct reloc_cache *cache,
unsigned long page)
{
void *vaddr;
if (cache->page == page) {
vaddr = unmask_page(cache->vaddr);
} else {
vaddr = NULL;
if ((cache->vaddr & KMAP) == 0)
vaddr = reloc_iomap(obj, cache, page);
if (!vaddr)
vaddr = reloc_kmap(obj, cache, page);
}
return vaddr;
}
static void clflush_write32(u32 *addr, u32 value, unsigned int flushes)
{
if (unlikely(flushes & (CLFLUSH_BEFORE | CLFLUSH_AFTER))) {
if (flushes & CLFLUSH_BEFORE) {
clflushopt(addr);
mb();
}
*addr = value;
if (flushes & CLFLUSH_AFTER)
clflushopt(addr);
} else
*addr = value;
}
static int __reloc_gpu_alloc(struct i915_execbuffer *eb,
struct i915_vma *vma,
unsigned int len)
{
struct reloc_cache *cache = &eb->reloc_cache;
struct drm_i915_gem_object *obj;
struct drm_i915_gem_request *rq;
struct i915_vma *batch;
u32 *cmd;
int err;
GEM_BUG_ON(vma->obj->base.write_domain & I915_GEM_DOMAIN_CPU);
obj = i915_gem_batch_pool_get(&eb->engine->batch_pool, PAGE_SIZE);
if (IS_ERR(obj))
return PTR_ERR(obj);
cmd = i915_gem_object_pin_map(obj,
cache->has_llc ? I915_MAP_WB : I915_MAP_WC);
i915_gem_object_unpin_pages(obj);
if (IS_ERR(cmd))
return PTR_ERR(cmd);
err = i915_gem_object_set_to_wc_domain(obj, false);
if (err)
goto err_unmap;
batch = i915_vma_instance(obj, vma->vm, NULL);
if (IS_ERR(batch)) {
err = PTR_ERR(batch);
goto err_unmap;
}
err = i915_vma_pin(batch, 0, 0, PIN_USER | PIN_NONBLOCK);
if (err)
goto err_unmap;
rq = i915_gem_request_alloc(eb->engine, eb->ctx);
if (IS_ERR(rq)) {
err = PTR_ERR(rq);
goto err_unpin;
}
err = i915_gem_request_await_object(rq, vma->obj, true);
if (err)
goto err_request;
err = eb->engine->emit_flush(rq, EMIT_INVALIDATE);
if (err)
goto err_request;
err = i915_switch_context(rq);
if (err)
goto err_request;
err = eb->engine->emit_bb_start(rq,
batch->node.start, PAGE_SIZE,
cache->gen > 5 ? 0 : I915_DISPATCH_SECURE);
if (err)
goto err_request;
GEM_BUG_ON(!reservation_object_test_signaled_rcu(batch->resv, true));
i915_vma_move_to_active(batch, rq, 0);
reservation_object_lock(batch->resv, NULL);
reservation_object_add_excl_fence(batch->resv, &rq->fence);
reservation_object_unlock(batch->resv);
i915_vma_unpin(batch);
i915_vma_move_to_active(vma, rq, EXEC_OBJECT_WRITE);
reservation_object_lock(vma->resv, NULL);
reservation_object_add_excl_fence(vma->resv, &rq->fence);
reservation_object_unlock(vma->resv);
rq->batch = batch;
cache->rq = rq;
cache->rq_cmd = cmd;
cache->rq_size = 0;
return 0;
err_request:
i915_add_request(rq);
err_unpin:
i915_vma_unpin(batch);
err_unmap:
i915_gem_object_unpin_map(obj);
return err;
}
static u32 *reloc_gpu(struct i915_execbuffer *eb,
struct i915_vma *vma,
unsigned int len)
{
struct reloc_cache *cache = &eb->reloc_cache;
u32 *cmd;
if (cache->rq_size > PAGE_SIZE/sizeof(u32) - (len + 1))
reloc_gpu_flush(cache);
if (unlikely(!cache->rq)) {
int err;
err = __reloc_gpu_alloc(eb, vma, len);
if (unlikely(err))
return ERR_PTR(err);
}
cmd = cache->rq_cmd + cache->rq_size;
cache->rq_size += len;
return cmd;
}
static u64
relocate_entry(struct i915_vma *vma,
const struct drm_i915_gem_relocation_entry *reloc,
struct i915_execbuffer *eb,
const struct i915_vma *target)
{
u64 offset = reloc->offset;
u64 target_offset = relocation_target(reloc, target);
bool wide = eb->reloc_cache.use_64bit_reloc;
void *vaddr;
if (!eb->reloc_cache.vaddr &&
(DBG_FORCE_RELOC == FORCE_GPU_RELOC ||
!reservation_object_test_signaled_rcu(vma->resv, true))) {
const unsigned int gen = eb->reloc_cache.gen;
unsigned int len;
u32 *batch;
u64 addr;
if (wide)
len = offset & 7 ? 8 : 5;
else if (gen >= 4)
len = 4;
else if (gen >= 3)
len = 3;
else
goto repeat;
batch = reloc_gpu(eb, vma, len);
if (IS_ERR(batch))
goto repeat;
addr = gen8_canonical_addr(vma->node.start + offset);
if (wide) {
if (offset & 7) {
*batch++ = MI_STORE_DWORD_IMM_GEN4;
*batch++ = lower_32_bits(addr);
*batch++ = upper_32_bits(addr);
*batch++ = lower_32_bits(target_offset);
addr = gen8_canonical_addr(addr + 4);
*batch++ = MI_STORE_DWORD_IMM_GEN4;
*batch++ = lower_32_bits(addr);
*batch++ = upper_32_bits(addr);
*batch++ = upper_32_bits(target_offset);
} else {
*batch++ = (MI_STORE_DWORD_IMM_GEN4 | (1 << 21)) + 1;
*batch++ = lower_32_bits(addr);
*batch++ = upper_32_bits(addr);
*batch++ = lower_32_bits(target_offset);
*batch++ = upper_32_bits(target_offset);
}
} else if (gen >= 6) {
*batch++ = MI_STORE_DWORD_IMM_GEN4;
*batch++ = 0;
*batch++ = addr;
*batch++ = target_offset;
} else if (gen >= 4) {
*batch++ = MI_STORE_DWORD_IMM_GEN4 | MI_USE_GGTT;
*batch++ = 0;
*batch++ = addr;
*batch++ = target_offset;
} else {
*batch++ = MI_STORE_DWORD_IMM | MI_MEM_VIRTUAL;
*batch++ = addr;
*batch++ = target_offset;
}
goto out;
}
repeat:
vaddr = reloc_vaddr(vma->obj, &eb->reloc_cache, offset >> PAGE_SHIFT);
if (IS_ERR(vaddr))
return PTR_ERR(vaddr);
clflush_write32(vaddr + offset_in_page(offset),
lower_32_bits(target_offset),
eb->reloc_cache.vaddr);
if (wide) {
offset += sizeof(u32);
target_offset >>= 32;
wide = false;
goto repeat;
}
out:
return target->node.start | UPDATE;
}
static u64
eb_relocate_entry(struct i915_execbuffer *eb,
struct i915_vma *vma,
const struct drm_i915_gem_relocation_entry *reloc)
{
struct i915_vma *target;
int err;
target = eb_get_vma(eb, reloc->target_handle);
if (unlikely(!target))
return -ENOENT;
if (unlikely(reloc->write_domain & (reloc->write_domain - 1))) {
DRM_DEBUG("reloc with multiple write domains: "
"target %d offset %d "
"read %08x write %08x",
reloc->target_handle,
(int) reloc->offset,
reloc->read_domains,
reloc->write_domain);
return -EINVAL;
}
if (unlikely((reloc->write_domain | reloc->read_domains)
& ~I915_GEM_GPU_DOMAINS)) {
DRM_DEBUG("reloc with read/write non-GPU domains: "
"target %d offset %d "
"read %08x write %08x",
reloc->target_handle,
(int) reloc->offset,
reloc->read_domains,
reloc->write_domain);
return -EINVAL;
}
if (reloc->write_domain) {
target->exec_entry->flags |= EXEC_OBJECT_WRITE;
if (reloc->write_domain == I915_GEM_DOMAIN_INSTRUCTION &&
IS_GEN6(eb->i915)) {
err = i915_vma_bind(target, target->obj->cache_level,
PIN_GLOBAL);
if (WARN_ONCE(err,
"Unexpected failure to bind target VMA!"))
return err;
}
}
if (!DBG_FORCE_RELOC &&
gen8_canonical_addr(target->node.start) == reloc->presumed_offset)
return 0;
if (unlikely(reloc->offset >
vma->size - (eb->reloc_cache.use_64bit_reloc ? 8 : 4))) {
DRM_DEBUG("Relocation beyond object bounds: "
"target %d offset %d size %d.\n",
reloc->target_handle,
(int)reloc->offset,
(int)vma->size);
return -EINVAL;
}
if (unlikely(reloc->offset & 3)) {
DRM_DEBUG("Relocation not 4-byte aligned: "
"target %d offset %d.\n",
reloc->target_handle,
(int)reloc->offset);
return -EINVAL;
}
vma->exec_entry->flags &= ~EXEC_OBJECT_ASYNC;
return relocate_entry(vma, reloc, eb, target);
}
static int eb_relocate_vma(struct i915_execbuffer *eb, struct i915_vma *vma)
{
#define N_RELOC(x) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct drm_i915_gem_relocation_entry stack[N_RELOC(512)];
struct drm_i915_gem_relocation_entry __user *urelocs;
const struct drm_i915_gem_exec_object2 *entry = vma->exec_entry;
unsigned int remain;
urelocs = u64_to_user_ptr(entry->relocs_ptr);
remain = entry->relocation_count;
if (unlikely(remain > N_RELOC(ULONG_MAX)))
return -EINVAL;
if (unlikely(!access_ok(VERIFY_READ, urelocs, remain*sizeof(*urelocs))))
return -EFAULT;
do {
struct drm_i915_gem_relocation_entry *r = stack;
unsigned int count =
min_t(unsigned int, remain, ARRAY_SIZE(stack));
unsigned int copied;
pagefault_disable();
copied = __copy_from_user_inatomic(r, urelocs, count * sizeof(r[0]));
pagefault_enable();
if (unlikely(copied)) {
remain = -EFAULT;
goto out;
}
remain -= count;
do {
u64 offset = eb_relocate_entry(eb, vma, r);
if (likely(offset == 0)) {
} else if ((s64)offset < 0) {
remain = (int)offset;
goto out;
} else {
offset = gen8_canonical_addr(offset & ~UPDATE);
__put_user(offset,
&urelocs[r-stack].presumed_offset);
}
} while (r++, --count);
urelocs += ARRAY_SIZE(stack);
} while (remain);
out:
reloc_cache_reset(&eb->reloc_cache);
return remain;
}
static int
eb_relocate_vma_slow(struct i915_execbuffer *eb, struct i915_vma *vma)
{
const struct drm_i915_gem_exec_object2 *entry = vma->exec_entry;
struct drm_i915_gem_relocation_entry *relocs =
u64_to_ptr(typeof(*relocs), entry->relocs_ptr);
unsigned int i;
int err;
for (i = 0; i < entry->relocation_count; i++) {
u64 offset = eb_relocate_entry(eb, vma, &relocs[i]);
if ((s64)offset < 0) {
err = (int)offset;
goto err;
}
}
err = 0;
err:
reloc_cache_reset(&eb->reloc_cache);
return err;
}
static int check_relocations(const struct drm_i915_gem_exec_object2 *entry)
{
const char __user *addr, *end;
unsigned long size;
char __maybe_unused c;
size = entry->relocation_count;
if (size == 0)
return 0;
if (size > N_RELOC(ULONG_MAX))
return -EINVAL;
addr = u64_to_user_ptr(entry->relocs_ptr);
size *= sizeof(struct drm_i915_gem_relocation_entry);
if (!access_ok(VERIFY_READ, addr, size))
return -EFAULT;
end = addr + size;
for (; addr < end; addr += PAGE_SIZE) {
int err = __get_user(c, addr);
if (err)
return err;
}
return __get_user(c, end - 1);
}
static int eb_copy_relocations(const struct i915_execbuffer *eb)
{
const unsigned int count = eb->buffer_count;
unsigned int i;
int err;
for (i = 0; i < count; i++) {
const unsigned int nreloc = eb->exec[i].relocation_count;
struct drm_i915_gem_relocation_entry __user *urelocs;
struct drm_i915_gem_relocation_entry *relocs;
unsigned long size;
unsigned long copied;
if (nreloc == 0)
continue;
err = check_relocations(&eb->exec[i]);
if (err)
goto err;
urelocs = u64_to_user_ptr(eb->exec[i].relocs_ptr);
size = nreloc * sizeof(*relocs);
relocs = kvmalloc_array(size, 1, GFP_TEMPORARY);
if (!relocs) {
kvfree(relocs);
err = -ENOMEM;
goto err;
}
copied = 0;
do {
unsigned int len =
min_t(u64, BIT_ULL(31), size - copied);
if (__copy_from_user((char *)relocs + copied,
(char *)urelocs + copied,
len)) {
kvfree(relocs);
err = -EFAULT;
goto err;
}
copied += len;
} while (copied < size);
user_access_begin();
for (copied = 0; copied < nreloc; copied++)
unsafe_put_user(-1,
&urelocs[copied].presumed_offset,
end_user);
end_user:
user_access_end();
eb->exec[i].relocs_ptr = (uintptr_t)relocs;
}
return 0;
err:
while (i--) {
struct drm_i915_gem_relocation_entry *relocs =
u64_to_ptr(typeof(*relocs), eb->exec[i].relocs_ptr);
if (eb->exec[i].relocation_count)
kvfree(relocs);
}
return err;
}
static int eb_prefault_relocations(const struct i915_execbuffer *eb)
{
const unsigned int count = eb->buffer_count;
unsigned int i;
if (unlikely(i915.prefault_disable))
return 0;
for (i = 0; i < count; i++) {
int err;
err = check_relocations(&eb->exec[i]);
if (err)
return err;
}
return 0;
}
static noinline int eb_relocate_slow(struct i915_execbuffer *eb)
{
struct drm_device *dev = &eb->i915->drm;
bool have_copy = false;
struct i915_vma *vma;
int err = 0;
repeat:
if (signal_pending(current)) {
err = -ERESTARTSYS;
goto out;
}
eb_reset_vmas(eb);
mutex_unlock(&dev->struct_mutex);
if (!err) {
err = eb_prefault_relocations(eb);
} else if (!have_copy) {
err = eb_copy_relocations(eb);
have_copy = err == 0;
} else {
cond_resched();
err = 0;
}
if (err) {
mutex_lock(&dev->struct_mutex);
goto out;
}
flush_workqueue(eb->i915->mm.userptr_wq);
err = i915_mutex_lock_interruptible(dev);
if (err) {
mutex_lock(&dev->struct_mutex);
goto out;
}
err = eb_lookup_vmas(eb);
if (err)
goto err;
list_for_each_entry(vma, &eb->relocs, reloc_link) {
if (!have_copy) {
pagefault_disable();
err = eb_relocate_vma(eb, vma);
pagefault_enable();
if (err)
goto repeat;
} else {
err = eb_relocate_vma_slow(eb, vma);
if (err)
goto err;
}
}
err:
if (err == -EAGAIN)
goto repeat;
out:
if (have_copy) {
const unsigned int count = eb->buffer_count;
unsigned int i;
for (i = 0; i < count; i++) {
const struct drm_i915_gem_exec_object2 *entry =
&eb->exec[i];
struct drm_i915_gem_relocation_entry *relocs;
if (!entry->relocation_count)
continue;
relocs = u64_to_ptr(typeof(*relocs), entry->relocs_ptr);
kvfree(relocs);
}
}
return err;
}
static int eb_relocate(struct i915_execbuffer *eb)
{
if (eb_lookup_vmas(eb))
goto slow;
if (eb->args->flags & __EXEC_HAS_RELOC) {
struct i915_vma *vma;
list_for_each_entry(vma, &eb->relocs, reloc_link) {
if (eb_relocate_vma(eb, vma))
goto slow;
}
}
return 0;
slow:
return eb_relocate_slow(eb);
}
static void eb_export_fence(struct i915_vma *vma,
struct drm_i915_gem_request *req,
unsigned int flags)
{
struct reservation_object *resv = vma->resv;
reservation_object_lock(resv, NULL);
if (flags & EXEC_OBJECT_WRITE)
reservation_object_add_excl_fence(resv, &req->fence);
else if (reservation_object_reserve_shared(resv) == 0)
reservation_object_add_shared_fence(resv, &req->fence);
reservation_object_unlock(resv);
}
static int eb_move_to_gpu(struct i915_execbuffer *eb)
{
const unsigned int count = eb->buffer_count;
unsigned int i;
int err;
for (i = 0; i < count; i++) {
struct drm_i915_gem_exec_object2 *entry = &eb->exec[i];
struct i915_vma *vma = exec_to_vma(entry);
struct drm_i915_gem_object *obj = vma->obj;
if (entry->flags & EXEC_OBJECT_CAPTURE) {
struct i915_gem_capture_list *capture;
capture = kmalloc(sizeof(*capture), GFP_KERNEL);
if (unlikely(!capture))
return -ENOMEM;
capture->next = eb->request->capture_list;
capture->vma = vma;
eb->request->capture_list = capture;
}
if (unlikely(obj->cache_dirty && !obj->cache_coherent)) {
if (i915_gem_clflush_object(obj, 0))
entry->flags &= ~EXEC_OBJECT_ASYNC;
}
if (entry->flags & EXEC_OBJECT_ASYNC)
goto skip_flushes;
err = i915_gem_request_await_object
(eb->request, obj, entry->flags & EXEC_OBJECT_WRITE);
if (err)
return err;
skip_flushes:
i915_vma_move_to_active(vma, eb->request, entry->flags);
__eb_unreserve_vma(vma, entry);
vma->exec_entry = NULL;
}
for (i = 0; i < count; i++) {
const struct drm_i915_gem_exec_object2 *entry = &eb->exec[i];
struct i915_vma *vma = exec_to_vma(entry);
eb_export_fence(vma, eb->request, entry->flags);
if (unlikely(entry->flags & __EXEC_OBJECT_HAS_REF))
i915_vma_put(vma);
}
eb->exec = NULL;
i915_gem_chipset_flush(eb->i915);
return eb->engine->emit_flush(eb->request, EMIT_INVALIDATE);
}
static bool i915_gem_check_execbuffer(struct drm_i915_gem_execbuffer2 *exec)
{
if (exec->flags & __I915_EXEC_ILLEGAL_FLAGS)
return false;
if (exec->num_cliprects || exec->cliprects_ptr)
return false;
if (exec->DR4 == 0xffffffff) {
DRM_DEBUG("UXA submitting garbage DR4, fixing up\n");
exec->DR4 = 0;
}
if (exec->DR1 || exec->DR4)
return false;
if ((exec->batch_start_offset | exec->batch_len) & 0x7)
return false;
return true;
}
void i915_vma_move_to_active(struct i915_vma *vma,
struct drm_i915_gem_request *req,
unsigned int flags)
{
struct drm_i915_gem_object *obj = vma->obj;
const unsigned int idx = req->engine->id;
lockdep_assert_held(&req->i915->drm.struct_mutex);
GEM_BUG_ON(!drm_mm_node_allocated(&vma->node));
if (!i915_vma_is_active(vma))
obj->active_count++;
i915_vma_set_active(vma, idx);
i915_gem_active_set(&vma->last_read[idx], req);
list_move_tail(&vma->vm_link, &vma->vm->active_list);
obj->base.write_domain = 0;
if (flags & EXEC_OBJECT_WRITE) {
obj->base.write_domain = I915_GEM_DOMAIN_RENDER;
if (intel_fb_obj_invalidate(obj, ORIGIN_CS))
i915_gem_active_set(&obj->frontbuffer_write, req);
obj->base.read_domains = 0;
}
obj->base.read_domains |= I915_GEM_GPU_DOMAINS;
if (flags & EXEC_OBJECT_NEEDS_FENCE)
i915_gem_active_set(&vma->last_fence, req);
}
static int i915_reset_gen7_sol_offsets(struct drm_i915_gem_request *req)
{
u32 *cs;
int i;
if (!IS_GEN7(req->i915) || req->engine->id != RCS) {
DRM_DEBUG("sol reset is gen7/rcs only\n");
return -EINVAL;
}
cs = intel_ring_begin(req, 4 * 2 + 2);
if (IS_ERR(cs))
return PTR_ERR(cs);
*cs++ = MI_LOAD_REGISTER_IMM(4);
for (i = 0; i < 4; i++) {
*cs++ = i915_mmio_reg_offset(GEN7_SO_WRITE_OFFSET(i));
*cs++ = 0;
}
*cs++ = MI_NOOP;
intel_ring_advance(req, cs);
return 0;
}
static struct i915_vma *eb_parse(struct i915_execbuffer *eb, bool is_master)
{
struct drm_i915_gem_object *shadow_batch_obj;
struct i915_vma *vma;
int err;
shadow_batch_obj = i915_gem_batch_pool_get(&eb->engine->batch_pool,
PAGE_ALIGN(eb->batch_len));
if (IS_ERR(shadow_batch_obj))
return ERR_CAST(shadow_batch_obj);
err = intel_engine_cmd_parser(eb->engine,
eb->batch->obj,
shadow_batch_obj,
eb->batch_start_offset,
eb->batch_len,
is_master);
if (err) {
if (err == -EACCES)
vma = NULL;
else
vma = ERR_PTR(err);
goto out;
}
vma = i915_gem_object_ggtt_pin(shadow_batch_obj, NULL, 0, 0, 0);
if (IS_ERR(vma))
goto out;
vma->exec_entry =
memset(&eb->exec[eb->buffer_count++],
0, sizeof(*vma->exec_entry));
vma->exec_entry->flags = __EXEC_OBJECT_HAS_PIN | __EXEC_OBJECT_HAS_REF;
__exec_to_vma(vma->exec_entry) = (uintptr_t)i915_vma_get(vma);
out:
i915_gem_object_unpin_pages(shadow_batch_obj);
return vma;
}
static void
add_to_client(struct drm_i915_gem_request *req, struct drm_file *file)
{
req->file_priv = file->driver_priv;
list_add_tail(&req->client_link, &req->file_priv->mm.request_list);
}
static int eb_submit(struct i915_execbuffer *eb)
{
int err;
err = eb_move_to_gpu(eb);
if (err)
return err;
err = i915_switch_context(eb->request);
if (err)
return err;
if (eb->args->flags & I915_EXEC_GEN7_SOL_RESET) {
err = i915_reset_gen7_sol_offsets(eb->request);
if (err)
return err;
}
err = eb->engine->emit_bb_start(eb->request,
eb->batch->node.start +
eb->batch_start_offset,
eb->batch_len,
eb->batch_flags);
if (err)
return err;
return 0;
}
static unsigned int
gen8_dispatch_bsd_engine(struct drm_i915_private *dev_priv,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
if ((int)file_priv->bsd_engine < 0)
file_priv->bsd_engine = atomic_fetch_xor(1,
&dev_priv->mm.bsd_engine_dispatch_index);
return file_priv->bsd_engine;
}
static struct intel_engine_cs *
eb_select_engine(struct drm_i915_private *dev_priv,
struct drm_file *file,
struct drm_i915_gem_execbuffer2 *args)
{
unsigned int user_ring_id = args->flags & I915_EXEC_RING_MASK;
struct intel_engine_cs *engine;
if (user_ring_id > I915_USER_RINGS) {
DRM_DEBUG("execbuf with unknown ring: %u\n", user_ring_id);
return NULL;
}
if ((user_ring_id != I915_EXEC_BSD) &&
((args->flags & I915_EXEC_BSD_MASK) != 0)) {
DRM_DEBUG("execbuf with non bsd ring but with invalid "
"bsd dispatch flags: %d\n", (int)(args->flags));
return NULL;
}
if (user_ring_id == I915_EXEC_BSD && HAS_BSD2(dev_priv)) {
unsigned int bsd_idx = args->flags & I915_EXEC_BSD_MASK;
if (bsd_idx == I915_EXEC_BSD_DEFAULT) {
bsd_idx = gen8_dispatch_bsd_engine(dev_priv, file);
} else if (bsd_idx >= I915_EXEC_BSD_RING1 &&
bsd_idx <= I915_EXEC_BSD_RING2) {
bsd_idx >>= I915_EXEC_BSD_SHIFT;
bsd_idx--;
} else {
DRM_DEBUG("execbuf with unknown bsd ring: %u\n",
bsd_idx);
return NULL;
}
engine = dev_priv->engine[_VCS(bsd_idx)];
} else {
engine = dev_priv->engine[user_ring_map[user_ring_id]];
}
if (!engine) {
DRM_DEBUG("execbuf with invalid ring: %u\n", user_ring_id);
return NULL;
}
return engine;
}
static int
i915_gem_do_execbuffer(struct drm_device *dev,
struct drm_file *file,
struct drm_i915_gem_execbuffer2 *args,
struct drm_i915_gem_exec_object2 *exec)
{
struct i915_execbuffer eb;
struct dma_fence *in_fence = NULL;
struct sync_file *out_fence = NULL;
int out_fence_fd = -1;
int err;
BUILD_BUG_ON(__EXEC_OBJECT_INTERNAL_FLAGS &
~__EXEC_OBJECT_UNKNOWN_FLAGS);
eb.i915 = to_i915(dev);
eb.file = file;
eb.args = args;
if (DBG_FORCE_RELOC || !(args->flags & I915_EXEC_NO_RELOC))
args->flags |= __EXEC_HAS_RELOC;
eb.exec = exec;
eb.ctx = NULL;
eb.invalid_flags = __EXEC_OBJECT_UNKNOWN_FLAGS;
if (USES_FULL_PPGTT(eb.i915))
eb.invalid_flags |= EXEC_OBJECT_NEEDS_GTT;
reloc_cache_init(&eb.reloc_cache, eb.i915);
eb.buffer_count = args->buffer_count;
eb.batch_start_offset = args->batch_start_offset;
eb.batch_len = args->batch_len;
eb.batch_flags = 0;
if (args->flags & I915_EXEC_SECURE) {
if (!drm_is_current_master(file) || !capable(CAP_SYS_ADMIN))
return -EPERM;
eb.batch_flags |= I915_DISPATCH_SECURE;
}
if (args->flags & I915_EXEC_IS_PINNED)
eb.batch_flags |= I915_DISPATCH_PINNED;
eb.engine = eb_select_engine(eb.i915, file, args);
if (!eb.engine)
return -EINVAL;
if (args->flags & I915_EXEC_RESOURCE_STREAMER) {
if (!HAS_RESOURCE_STREAMER(eb.i915)) {
DRM_DEBUG("RS is only allowed for Haswell, Gen8 and above\n");
return -EINVAL;
}
if (eb.engine->id != RCS) {
DRM_DEBUG("RS is not available on %s\n",
eb.engine->name);
return -EINVAL;
}
eb.batch_flags |= I915_DISPATCH_RS;
}
if (args->flags & I915_EXEC_FENCE_IN) {
in_fence = sync_file_get_fence(lower_32_bits(args->rsvd2));
if (!in_fence)
return -EINVAL;
}
if (args->flags & I915_EXEC_FENCE_OUT) {
out_fence_fd = get_unused_fd_flags(O_CLOEXEC);
if (out_fence_fd < 0) {
err = out_fence_fd;
goto err_in_fence;
}
}
err = eb_create(&eb);
if (err)
goto err_out_fence;
GEM_BUG_ON(!eb.lut_size);
intel_runtime_pm_get(eb.i915);
err = i915_mutex_lock_interruptible(dev);
if (err)
goto err_rpm;
err = eb_select_context(&eb);
if (unlikely(err))
goto err_unlock;
err = eb_relocate(&eb);
if (err) {
args->flags &= ~__EXEC_HAS_RELOC;
goto err_vma;
}
if (unlikely(eb.batch->exec_entry->flags & EXEC_OBJECT_WRITE)) {
DRM_DEBUG("Attempting to use self-modifying batch buffer\n");
err = -EINVAL;
goto err_vma;
}
if (eb.batch_start_offset > eb.batch->size ||
eb.batch_len > eb.batch->size - eb.batch_start_offset) {
DRM_DEBUG("Attempting to use out-of-bounds batch\n");
err = -EINVAL;
goto err_vma;
}
if (eb.engine->needs_cmd_parser && eb.batch_len) {
struct i915_vma *vma;
vma = eb_parse(&eb, drm_is_current_master(file));
if (IS_ERR(vma)) {
err = PTR_ERR(vma);
goto err_vma;
}
if (vma) {
eb.batch_flags |= I915_DISPATCH_SECURE;
eb.batch_start_offset = 0;
eb.batch = vma;
}
}
if (eb.batch_len == 0)
eb.batch_len = eb.batch->size - eb.batch_start_offset;
if (eb.batch_flags & I915_DISPATCH_SECURE) {
struct i915_vma *vma;
vma = i915_gem_object_ggtt_pin(eb.batch->obj, NULL, 0, 0, 0);
if (IS_ERR(vma)) {
err = PTR_ERR(vma);
goto err_vma;
}
eb.batch = vma;
}
GEM_BUG_ON(eb.reloc_cache.rq);
eb.request = i915_gem_request_alloc(eb.engine, eb.ctx);
if (IS_ERR(eb.request)) {
err = PTR_ERR(eb.request);
goto err_batch_unpin;
}
if (in_fence) {
err = i915_gem_request_await_dma_fence(eb.request, in_fence);
if (err < 0)
goto err_request;
}
if (out_fence_fd != -1) {
out_fence = sync_file_create(&eb.request->fence);
if (!out_fence) {
err = -ENOMEM;
goto err_request;
}
}
eb.request->batch = eb.batch;
trace_i915_gem_request_queue(eb.request, eb.batch_flags);
err = eb_submit(&eb);
err_request:
__i915_add_request(eb.request, err == 0);
add_to_client(eb.request, file);
if (out_fence) {
if (err == 0) {
fd_install(out_fence_fd, out_fence->file);
args->rsvd2 &= GENMASK_ULL(0, 31);
args->rsvd2 |= (u64)out_fence_fd << 32;
out_fence_fd = -1;
} else {
fput(out_fence->file);
}
}
err_batch_unpin:
if (eb.batch_flags & I915_DISPATCH_SECURE)
i915_vma_unpin(eb.batch);
err_vma:
if (eb.exec)
eb_release_vmas(&eb);
i915_gem_context_put(eb.ctx);
err_unlock:
mutex_unlock(&dev->struct_mutex);
err_rpm:
intel_runtime_pm_put(eb.i915);
eb_destroy(&eb);
err_out_fence:
if (out_fence_fd != -1)
put_unused_fd(out_fence_fd);
err_in_fence:
dma_fence_put(in_fence);
return err;
}
int
i915_gem_execbuffer(struct drm_device *dev, void *data,
struct drm_file *file)
{
const size_t sz = sizeof(struct drm_i915_gem_exec_object2);
struct drm_i915_gem_execbuffer *args = data;
struct drm_i915_gem_execbuffer2 exec2;
struct drm_i915_gem_exec_object *exec_list = NULL;
struct drm_i915_gem_exec_object2 *exec2_list = NULL;
unsigned int i;
int err;
if (args->buffer_count < 1 || args->buffer_count > SIZE_MAX / sz - 1) {
DRM_DEBUG("execbuf2 with %d buffers\n", args->buffer_count);
return -EINVAL;
}
exec2.buffers_ptr = args->buffers_ptr;
exec2.buffer_count = args->buffer_count;
exec2.batch_start_offset = args->batch_start_offset;
exec2.batch_len = args->batch_len;
exec2.DR1 = args->DR1;
exec2.DR4 = args->DR4;
exec2.num_cliprects = args->num_cliprects;
exec2.cliprects_ptr = args->cliprects_ptr;
exec2.flags = I915_EXEC_RENDER;
i915_execbuffer2_set_context_id(exec2, 0);
if (!i915_gem_check_execbuffer(&exec2))
return -EINVAL;
exec_list = kvmalloc_array(args->buffer_count, sizeof(*exec_list),
__GFP_NOWARN | GFP_TEMPORARY);
exec2_list = kvmalloc_array(args->buffer_count + 1, sz,
__GFP_NOWARN | GFP_TEMPORARY);
if (exec_list == NULL || exec2_list == NULL) {
DRM_DEBUG("Failed to allocate exec list for %d buffers\n",
args->buffer_count);
kvfree(exec_list);
kvfree(exec2_list);
return -ENOMEM;
}
err = copy_from_user(exec_list,
u64_to_user_ptr(args->buffers_ptr),
sizeof(*exec_list) * args->buffer_count);
if (err) {
DRM_DEBUG("copy %d exec entries failed %d\n",
args->buffer_count, err);
kvfree(exec_list);
kvfree(exec2_list);
return -EFAULT;
}
for (i = 0; i < args->buffer_count; i++) {
exec2_list[i].handle = exec_list[i].handle;
exec2_list[i].relocation_count = exec_list[i].relocation_count;
exec2_list[i].relocs_ptr = exec_list[i].relocs_ptr;
exec2_list[i].alignment = exec_list[i].alignment;
exec2_list[i].offset = exec_list[i].offset;
if (INTEL_GEN(to_i915(dev)) < 4)
exec2_list[i].flags = EXEC_OBJECT_NEEDS_FENCE;
else
exec2_list[i].flags = 0;
}
err = i915_gem_do_execbuffer(dev, file, &exec2, exec2_list);
if (exec2.flags & __EXEC_HAS_RELOC) {
struct drm_i915_gem_exec_object __user *user_exec_list =
u64_to_user_ptr(args->buffers_ptr);
for (i = 0; i < args->buffer_count; i++) {
if (!(exec2_list[i].offset & UPDATE))
continue;
exec2_list[i].offset =
gen8_canonical_addr(exec2_list[i].offset & PIN_OFFSET_MASK);
exec2_list[i].offset &= PIN_OFFSET_MASK;
if (__copy_to_user(&user_exec_list[i].offset,
&exec2_list[i].offset,
sizeof(user_exec_list[i].offset)))
break;
}
}
kvfree(exec_list);
kvfree(exec2_list);
return err;
}
int
i915_gem_execbuffer2(struct drm_device *dev, void *data,
struct drm_file *file)
{
const size_t sz = sizeof(struct drm_i915_gem_exec_object2);
struct drm_i915_gem_execbuffer2 *args = data;
struct drm_i915_gem_exec_object2 *exec2_list;
int err;
if (args->buffer_count < 1 || args->buffer_count > SIZE_MAX / sz - 1) {
DRM_DEBUG("execbuf2 with %d buffers\n", args->buffer_count);
return -EINVAL;
}
if (!i915_gem_check_execbuffer(args))
return -EINVAL;
exec2_list = kvmalloc_array(args->buffer_count + 1, sz,
__GFP_NOWARN | GFP_TEMPORARY);
if (exec2_list == NULL) {
DRM_DEBUG("Failed to allocate exec list for %d buffers\n",
args->buffer_count);
return -ENOMEM;
}
if (copy_from_user(exec2_list,
u64_to_user_ptr(args->buffers_ptr),
sizeof(*exec2_list) * args->buffer_count)) {
DRM_DEBUG("copy %d exec entries failed\n", args->buffer_count);
kvfree(exec2_list);
return -EFAULT;
}
err = i915_gem_do_execbuffer(dev, file, args, exec2_list);
if (args->flags & __EXEC_HAS_RELOC) {
struct drm_i915_gem_exec_object2 __user *user_exec_list =
u64_to_user_ptr(args->buffers_ptr);
unsigned int i;
user_access_begin();
for (i = 0; i < args->buffer_count; i++) {
if (!(exec2_list[i].offset & UPDATE))
continue;
exec2_list[i].offset =
gen8_canonical_addr(exec2_list[i].offset & PIN_OFFSET_MASK);
unsafe_put_user(exec2_list[i].offset,
&user_exec_list[i].offset,
end_user);
}
end_user:
user_access_end();
}
args->flags &= ~__I915_EXEC_UNKNOWN_FLAGS;
kvfree(exec2_list);
return err;
}
