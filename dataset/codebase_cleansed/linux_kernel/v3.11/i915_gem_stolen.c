static unsigned long i915_stolen_to_physical(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pdev = dev_priv->bridge_dev;
u32 base;
base = 0;
if (IS_VALLEYVIEW(dev)) {
pci_read_config_dword(dev->pdev, 0x5c, &base);
base &= ~((1<<20) - 1);
} else if (INTEL_INFO(dev)->gen >= 6) {
pci_read_config_dword(pdev, 0xB0, &base);
base &= ~4095;
} else if (INTEL_INFO(dev)->gen > 3 || IS_G33(dev)) {
pci_read_config_dword(pdev, 0xA4, &base);
#if 0
} else if (IS_GEN3(dev)) {
u8 val;
pci_read_config_byte(pdev, 0x9c, &val);
base = val >> 3 << 27;
base -= dev_priv->mm.gtt->stolen_size;
} else {
base = max_low_pfn_mapped << PAGE_SHIFT;
#endif
}
return base;
}
static int i915_setup_compression(struct drm_device *dev, int size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_mm_node *compressed_fb, *uninitialized_var(compressed_llb);
compressed_fb = drm_mm_search_free(&dev_priv->mm.stolen,
size <<= 1, 4096, 0);
if (!compressed_fb)
compressed_fb = drm_mm_search_free(&dev_priv->mm.stolen,
size >>= 1, 4096, 0);
if (compressed_fb)
compressed_fb = drm_mm_get_block(compressed_fb, size, 4096);
if (!compressed_fb)
goto err;
if (HAS_PCH_SPLIT(dev))
I915_WRITE(ILK_DPFC_CB_BASE, compressed_fb->start);
else if (IS_GM45(dev)) {
I915_WRITE(DPFC_CB_BASE, compressed_fb->start);
} else {
compressed_llb = drm_mm_search_free(&dev_priv->mm.stolen,
4096, 4096, 0);
if (compressed_llb)
compressed_llb = drm_mm_get_block(compressed_llb,
4096, 4096);
if (!compressed_llb)
goto err_fb;
dev_priv->compressed_llb = compressed_llb;
I915_WRITE(FBC_CFB_BASE,
dev_priv->mm.stolen_base + compressed_fb->start);
I915_WRITE(FBC_LL_BASE,
dev_priv->mm.stolen_base + compressed_llb->start);
}
dev_priv->compressed_fb = compressed_fb;
dev_priv->cfb_size = size;
DRM_DEBUG_KMS("reserved %d bytes of contiguous stolen space for FBC\n",
size);
return 0;
err_fb:
drm_mm_put_block(compressed_fb);
err:
pr_info_once("drm: not enough stolen space for compressed buffer (need %d more bytes), disabling. Hint: you may be able to increase stolen memory size in the BIOS to avoid this.\n", size);
return -ENOSPC;
}
int i915_gem_stolen_setup_compression(struct drm_device *dev, int size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return -ENODEV;
if (size < dev_priv->cfb_size)
return 0;
i915_gem_stolen_cleanup_compression(dev);
return i915_setup_compression(dev, size);
}
void i915_gem_stolen_cleanup_compression(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->cfb_size == 0)
return;
if (dev_priv->compressed_fb)
drm_mm_put_block(dev_priv->compressed_fb);
if (dev_priv->compressed_llb)
drm_mm_put_block(dev_priv->compressed_llb);
dev_priv->cfb_size = 0;
}
void i915_gem_cleanup_stolen(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return;
i915_gem_stolen_cleanup_compression(dev);
drm_mm_takedown(&dev_priv->mm.stolen);
}
int i915_gem_init_stolen(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int bios_reserved = 0;
dev_priv->mm.stolen_base = i915_stolen_to_physical(dev);
if (dev_priv->mm.stolen_base == 0)
return 0;
DRM_DEBUG_KMS("found %zd bytes of stolen memory at %08lx\n",
dev_priv->gtt.stolen_size, dev_priv->mm.stolen_base);
if (IS_VALLEYVIEW(dev))
bios_reserved = 1024*1024;
drm_mm_init(&dev_priv->mm.stolen, 0, dev_priv->gtt.stolen_size -
bios_reserved);
return 0;
}
static struct sg_table *
i915_pages_create_for_stolen(struct drm_device *dev,
u32 offset, u32 size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct sg_table *st;
struct scatterlist *sg;
DRM_DEBUG_DRIVER("offset=0x%x, size=%d\n", offset, size);
BUG_ON(offset > dev_priv->gtt.stolen_size - size);
st = kmalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL)
return NULL;
if (sg_alloc_table(st, 1, GFP_KERNEL)) {
kfree(st);
return NULL;
}
sg = st->sgl;
sg->offset = offset;
sg->length = size;
sg_dma_address(sg) = (dma_addr_t)dev_priv->mm.stolen_base + offset;
sg_dma_len(sg) = size;
return st;
}
static int i915_gem_object_get_pages_stolen(struct drm_i915_gem_object *obj)
{
BUG();
return -EINVAL;
}
static void i915_gem_object_put_pages_stolen(struct drm_i915_gem_object *obj)
{
sg_free_table(obj->pages);
kfree(obj->pages);
}
static struct drm_i915_gem_object *
_i915_gem_object_create_stolen(struct drm_device *dev,
struct drm_mm_node *stolen)
{
struct drm_i915_gem_object *obj;
obj = i915_gem_object_alloc(dev);
if (obj == NULL)
return NULL;
if (drm_gem_private_object_init(dev, &obj->base, stolen->size))
goto cleanup;
i915_gem_object_init(obj, &i915_gem_object_stolen_ops);
obj->pages = i915_pages_create_for_stolen(dev,
stolen->start, stolen->size);
if (obj->pages == NULL)
goto cleanup;
obj->has_dma_mapping = true;
i915_gem_object_pin_pages(obj);
obj->stolen = stolen;
obj->base.write_domain = I915_GEM_DOMAIN_GTT;
obj->base.read_domains = I915_GEM_DOMAIN_GTT;
obj->cache_level = I915_CACHE_NONE;
return obj;
cleanup:
i915_gem_object_free(obj);
return NULL;
}
struct drm_i915_gem_object *
i915_gem_object_create_stolen(struct drm_device *dev, u32 size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct drm_mm_node *stolen;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return NULL;
DRM_DEBUG_KMS("creating stolen object: size=%x\n", size);
if (size == 0)
return NULL;
stolen = drm_mm_search_free(&dev_priv->mm.stolen, size, 4096, 0);
if (stolen)
stolen = drm_mm_get_block(stolen, size, 4096);
if (stolen == NULL)
return NULL;
obj = _i915_gem_object_create_stolen(dev, stolen);
if (obj)
return obj;
drm_mm_put_block(stolen);
return NULL;
}
struct drm_i915_gem_object *
i915_gem_object_create_stolen_for_preallocated(struct drm_device *dev,
u32 stolen_offset,
u32 gtt_offset,
u32 size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct drm_mm_node *stolen;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return NULL;
DRM_DEBUG_KMS("creating preallocated stolen object: stolen_offset=%x, gtt_offset=%x, size=%x\n",
stolen_offset, gtt_offset, size);
BUG_ON(stolen_offset & 4095);
BUG_ON(size & 4095);
if (WARN_ON(size == 0))
return NULL;
stolen = drm_mm_create_block(&dev_priv->mm.stolen,
stolen_offset, size,
false);
if (stolen == NULL) {
DRM_DEBUG_KMS("failed to allocate stolen space\n");
return NULL;
}
obj = _i915_gem_object_create_stolen(dev, stolen);
if (obj == NULL) {
DRM_DEBUG_KMS("failed to allocate stolen object\n");
drm_mm_put_block(stolen);
return NULL;
}
if (gtt_offset == -1)
return obj;
if (drm_mm_initialized(&dev_priv->mm.gtt_space)) {
obj->gtt_space = drm_mm_create_block(&dev_priv->mm.gtt_space,
gtt_offset, size,
false);
if (obj->gtt_space == NULL) {
DRM_DEBUG_KMS("failed to allocate stolen GTT space\n");
drm_gem_object_unreference(&obj->base);
return NULL;
}
} else
obj->gtt_space = I915_GTT_RESERVED;
obj->gtt_offset = gtt_offset;
obj->has_global_gtt_mapping = 1;
list_add_tail(&obj->global_list, &dev_priv->mm.bound_list);
list_add_tail(&obj->mm_list, &dev_priv->mm.inactive_list);
return obj;
}
void
i915_gem_object_release_stolen(struct drm_i915_gem_object *obj)
{
if (obj->stolen) {
drm_mm_put_block(obj->stolen);
obj->stolen = NULL;
}
}
