static void internal_free_pages(struct sg_table *st)
{
struct scatterlist *sg;
for (sg = st->sgl; sg; sg = __sg_next(sg))
__free_pages(sg_page(sg), get_order(sg->length));
sg_free_table(st);
kfree(st);
}
static struct sg_table *
i915_gem_object_get_pages_internal(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *i915 = to_i915(obj->base.dev);
unsigned int npages = obj->base.size / PAGE_SIZE;
struct sg_table *st;
struct scatterlist *sg;
int max_order;
gfp_t gfp;
st = kmalloc(sizeof(*st), GFP_KERNEL);
if (!st)
return ERR_PTR(-ENOMEM);
if (sg_alloc_table(st, npages, GFP_KERNEL)) {
kfree(st);
return ERR_PTR(-ENOMEM);
}
sg = st->sgl;
st->nents = 0;
max_order = MAX_ORDER;
#ifdef CONFIG_SWIOTLB
if (swiotlb_nr_tbl()) {
unsigned int max_segment;
max_segment = swiotlb_max_segment();
if (max_segment) {
max_segment = max_t(unsigned int, max_segment,
PAGE_SIZE) >> PAGE_SHIFT;
max_order = min(max_order, ilog2(max_segment));
}
}
#endif
gfp = GFP_KERNEL | __GFP_HIGHMEM | __GFP_RECLAIMABLE;
if (IS_CRESTLINE(i915) || IS_BROADWATER(i915)) {
gfp &= ~__GFP_HIGHMEM;
gfp |= __GFP_DMA32;
}
do {
int order = min(fls(npages) - 1, max_order);
struct page *page;
do {
page = alloc_pages(gfp | (order ? QUIET : 0), order);
if (page)
break;
if (!order--)
goto err;
max_order = order;
} while (1);
sg_set_page(sg, page, PAGE_SIZE << order, 0);
st->nents++;
npages -= 1 << order;
if (!npages) {
sg_mark_end(sg);
break;
}
sg = __sg_next(sg);
} while (1);
if (i915_gem_gtt_prepare_pages(obj, st))
goto err;
obj->mm.madv = I915_MADV_DONTNEED;
return st;
err:
sg_mark_end(sg);
internal_free_pages(st);
return ERR_PTR(-ENOMEM);
}
static void i915_gem_object_put_pages_internal(struct drm_i915_gem_object *obj,
struct sg_table *pages)
{
i915_gem_gtt_finish_pages(obj, pages);
internal_free_pages(pages);
obj->mm.dirty = false;
obj->mm.madv = I915_MADV_WILLNEED;
}
struct drm_i915_gem_object *
i915_gem_object_create_internal(struct drm_i915_private *i915,
unsigned int size)
{
struct drm_i915_gem_object *obj;
obj = i915_gem_object_alloc(&i915->drm);
if (!obj)
return ERR_PTR(-ENOMEM);
drm_gem_private_object_init(&i915->drm, &obj->base, size);
i915_gem_object_init(obj, &i915_gem_object_internal_ops);
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->cache_level = HAS_LLC(i915) ? I915_CACHE_LLC : I915_CACHE_NONE;
return obj;
}
