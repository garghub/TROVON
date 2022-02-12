int i915_gem_stolen_insert_node_in_range(struct drm_i915_private *dev_priv,
struct drm_mm_node *node, u64 size,
unsigned alignment, u64 start, u64 end)
{
int ret;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return -ENODEV;
if (INTEL_INFO(dev_priv)->gen == 8 && start < 4096)
start = 4096;
mutex_lock(&dev_priv->mm.stolen_lock);
ret = drm_mm_insert_node_in_range(&dev_priv->mm.stolen, node, size,
alignment, start, end,
DRM_MM_SEARCH_DEFAULT);
mutex_unlock(&dev_priv->mm.stolen_lock);
return ret;
}
int i915_gem_stolen_insert_node(struct drm_i915_private *dev_priv,
struct drm_mm_node *node, u64 size,
unsigned alignment)
{
return i915_gem_stolen_insert_node_in_range(dev_priv, node, size,
alignment, 0,
dev_priv->gtt.stolen_usable_size);
}
void i915_gem_stolen_remove_node(struct drm_i915_private *dev_priv,
struct drm_mm_node *node)
{
mutex_lock(&dev_priv->mm.stolen_lock);
drm_mm_remove_node(node);
mutex_unlock(&dev_priv->mm.stolen_lock);
}
static unsigned long i915_stolen_to_physical(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct resource *r;
u32 base;
base = 0;
if (INTEL_INFO(dev)->gen >= 3) {
pci_read_config_dword(dev->pdev, 0x5c, &base);
base &= ~((1<<20) - 1);
} else if (IS_I865G(dev)) {
u16 toud = 0;
pci_bus_read_config_word(dev->pdev->bus, PCI_DEVFN(0, 0),
I865_TOUD, &toud);
base = toud << 16;
} else if (IS_I85X(dev)) {
u32 tseg_size = 0;
u32 tom;
u8 tmp;
pci_bus_read_config_byte(dev->pdev->bus, PCI_DEVFN(0, 0),
I85X_ESMRAMC, &tmp);
if (tmp & TSEG_ENABLE)
tseg_size = MB(1);
pci_bus_read_config_byte(dev->pdev->bus, PCI_DEVFN(0, 1),
I85X_DRB3, &tmp);
tom = tmp * MB(32);
base = tom - tseg_size - dev_priv->gtt.stolen_size;
} else if (IS_845G(dev)) {
u32 tseg_size = 0;
u32 tom;
u8 tmp;
pci_bus_read_config_byte(dev->pdev->bus, PCI_DEVFN(0, 0),
I845_ESMRAMC, &tmp);
if (tmp & TSEG_ENABLE) {
switch (tmp & I845_TSEG_SIZE_MASK) {
case I845_TSEG_SIZE_512K:
tseg_size = KB(512);
break;
case I845_TSEG_SIZE_1M:
tseg_size = MB(1);
break;
}
}
pci_bus_read_config_byte(dev->pdev->bus, PCI_DEVFN(0, 0),
I830_DRB3, &tmp);
tom = tmp * MB(32);
base = tom - tseg_size - dev_priv->gtt.stolen_size;
} else if (IS_I830(dev)) {
u32 tseg_size = 0;
u32 tom;
u8 tmp;
pci_bus_read_config_byte(dev->pdev->bus, PCI_DEVFN(0, 0),
I830_ESMRAMC, &tmp);
if (tmp & TSEG_ENABLE) {
if (tmp & I830_TSEG_SIZE_1M)
tseg_size = MB(1);
else
tseg_size = KB(512);
}
pci_bus_read_config_byte(dev->pdev->bus, PCI_DEVFN(0, 0),
I830_DRB3, &tmp);
tom = tmp * MB(32);
base = tom - tseg_size - dev_priv->gtt.stolen_size;
}
if (base == 0)
return 0;
if (INTEL_INFO(dev)->gen <= 4 && !IS_G33(dev) && !IS_G4X(dev)) {
struct {
u32 start, end;
} stolen[2] = {
{ .start = base, .end = base + dev_priv->gtt.stolen_size, },
{ .start = base, .end = base + dev_priv->gtt.stolen_size, },
};
u64 gtt_start, gtt_end;
gtt_start = I915_READ(PGTBL_CTL);
if (IS_GEN4(dev))
gtt_start = (gtt_start & PGTBL_ADDRESS_LO_MASK) |
(gtt_start & PGTBL_ADDRESS_HI_MASK) << 28;
else
gtt_start &= PGTBL_ADDRESS_LO_MASK;
gtt_end = gtt_start + gtt_total_entries(dev_priv->gtt) * 4;
if (gtt_start >= stolen[0].start && gtt_start < stolen[0].end)
stolen[0].end = gtt_start;
if (gtt_end > stolen[1].start && gtt_end <= stolen[1].end)
stolen[1].start = gtt_end;
if (stolen[0].end - stolen[0].start >
stolen[1].end - stolen[1].start) {
base = stolen[0].start;
dev_priv->gtt.stolen_size = stolen[0].end - stolen[0].start;
} else {
base = stolen[1].start;
dev_priv->gtt.stolen_size = stolen[1].end - stolen[1].start;
}
if (stolen[0].start != stolen[1].start ||
stolen[0].end != stolen[1].end) {
DRM_DEBUG_KMS("GTT within stolen memory at 0x%llx-0x%llx\n",
(unsigned long long) gtt_start,
(unsigned long long) gtt_end - 1);
DRM_DEBUG_KMS("Stolen memory adjusted to 0x%x-0x%x\n",
base, base + (u32) dev_priv->gtt.stolen_size - 1);
}
}
r = devm_request_mem_region(dev->dev, base, dev_priv->gtt.stolen_size,
"Graphics Stolen Memory");
if (r == NULL) {
r = devm_request_mem_region(dev->dev, base + 1,
dev_priv->gtt.stolen_size - 1,
"Graphics Stolen Memory");
if (r == NULL && !IS_GEN3(dev)) {
DRM_ERROR("conflict detected with stolen region: [0x%08x - 0x%08x]\n",
base, base + (uint32_t)dev_priv->gtt.stolen_size);
base = 0;
}
}
return base;
}
void i915_gem_cleanup_stolen(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return;
drm_mm_takedown(&dev_priv->mm.stolen);
}
static void g4x_get_stolen_reserved(struct drm_i915_private *dev_priv,
unsigned long *base, unsigned long *size)
{
uint32_t reg_val = I915_READ(IS_GM45(dev_priv) ?
CTG_STOLEN_RESERVED :
ELK_STOLEN_RESERVED);
unsigned long stolen_top = dev_priv->mm.stolen_base +
dev_priv->gtt.stolen_size;
*base = (reg_val & G4X_STOLEN_RESERVED_ADDR2_MASK) << 16;
WARN_ON((reg_val & G4X_STOLEN_RESERVED_ADDR1_MASK) < *base);
if (*base == 0)
*size = 0;
else
*size = stolen_top - *base;
}
static void gen6_get_stolen_reserved(struct drm_i915_private *dev_priv,
unsigned long *base, unsigned long *size)
{
uint32_t reg_val = I915_READ(GEN6_STOLEN_RESERVED);
*base = reg_val & GEN6_STOLEN_RESERVED_ADDR_MASK;
switch (reg_val & GEN6_STOLEN_RESERVED_SIZE_MASK) {
case GEN6_STOLEN_RESERVED_1M:
*size = 1024 * 1024;
break;
case GEN6_STOLEN_RESERVED_512K:
*size = 512 * 1024;
break;
case GEN6_STOLEN_RESERVED_256K:
*size = 256 * 1024;
break;
case GEN6_STOLEN_RESERVED_128K:
*size = 128 * 1024;
break;
default:
*size = 1024 * 1024;
MISSING_CASE(reg_val & GEN6_STOLEN_RESERVED_SIZE_MASK);
}
}
static void gen7_get_stolen_reserved(struct drm_i915_private *dev_priv,
unsigned long *base, unsigned long *size)
{
uint32_t reg_val = I915_READ(GEN6_STOLEN_RESERVED);
*base = reg_val & GEN7_STOLEN_RESERVED_ADDR_MASK;
switch (reg_val & GEN7_STOLEN_RESERVED_SIZE_MASK) {
case GEN7_STOLEN_RESERVED_1M:
*size = 1024 * 1024;
break;
case GEN7_STOLEN_RESERVED_256K:
*size = 256 * 1024;
break;
default:
*size = 1024 * 1024;
MISSING_CASE(reg_val & GEN7_STOLEN_RESERVED_SIZE_MASK);
}
}
static void gen8_get_stolen_reserved(struct drm_i915_private *dev_priv,
unsigned long *base, unsigned long *size)
{
uint32_t reg_val = I915_READ(GEN6_STOLEN_RESERVED);
*base = reg_val & GEN6_STOLEN_RESERVED_ADDR_MASK;
switch (reg_val & GEN8_STOLEN_RESERVED_SIZE_MASK) {
case GEN8_STOLEN_RESERVED_1M:
*size = 1024 * 1024;
break;
case GEN8_STOLEN_RESERVED_2M:
*size = 2 * 1024 * 1024;
break;
case GEN8_STOLEN_RESERVED_4M:
*size = 4 * 1024 * 1024;
break;
case GEN8_STOLEN_RESERVED_8M:
*size = 8 * 1024 * 1024;
break;
default:
*size = 8 * 1024 * 1024;
MISSING_CASE(reg_val & GEN8_STOLEN_RESERVED_SIZE_MASK);
}
}
static void bdw_get_stolen_reserved(struct drm_i915_private *dev_priv,
unsigned long *base, unsigned long *size)
{
uint32_t reg_val = I915_READ(GEN6_STOLEN_RESERVED);
unsigned long stolen_top;
stolen_top = dev_priv->mm.stolen_base + dev_priv->gtt.stolen_size;
*base = reg_val & GEN6_STOLEN_RESERVED_ADDR_MASK;
if (*base == 0)
*size = 0;
else
*size = stolen_top - *base;
}
int i915_gem_init_stolen(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long reserved_total, reserved_base = 0, reserved_size;
unsigned long stolen_top;
mutex_init(&dev_priv->mm.stolen_lock);
#ifdef CONFIG_INTEL_IOMMU
if (intel_iommu_gfx_mapped && INTEL_INFO(dev)->gen < 8) {
DRM_INFO("DMAR active, disabling use of stolen memory\n");
return 0;
}
#endif
if (dev_priv->gtt.stolen_size == 0)
return 0;
dev_priv->mm.stolen_base = i915_stolen_to_physical(dev);
if (dev_priv->mm.stolen_base == 0)
return 0;
stolen_top = dev_priv->mm.stolen_base + dev_priv->gtt.stolen_size;
switch (INTEL_INFO(dev_priv)->gen) {
case 2:
case 3:
break;
case 4:
if (IS_G4X(dev))
g4x_get_stolen_reserved(dev_priv, &reserved_base,
&reserved_size);
break;
case 5:
reserved_size = 1024 * 1024;
reserved_base = stolen_top - reserved_size;
break;
case 6:
gen6_get_stolen_reserved(dev_priv, &reserved_base,
&reserved_size);
break;
case 7:
gen7_get_stolen_reserved(dev_priv, &reserved_base,
&reserved_size);
break;
default:
if (IS_BROADWELL(dev_priv) || IS_SKYLAKE(dev_priv))
bdw_get_stolen_reserved(dev_priv, &reserved_base,
&reserved_size);
else
gen8_get_stolen_reserved(dev_priv, &reserved_base,
&reserved_size);
break;
}
if (reserved_base == 0) {
reserved_size = 0;
reserved_base = stolen_top;
}
if (reserved_base < dev_priv->mm.stolen_base ||
reserved_base + reserved_size > stolen_top) {
DRM_DEBUG_KMS("Stolen reserved area [0x%08lx - 0x%08lx] outside stolen memory [0x%08lx - 0x%08lx]\n",
reserved_base, reserved_base + reserved_size,
dev_priv->mm.stolen_base, stolen_top);
return 0;
}
reserved_total = stolen_top - reserved_base;
DRM_DEBUG_KMS("Memory reserved for graphics device: %zuK, usable: %luK\n",
dev_priv->gtt.stolen_size >> 10,
(dev_priv->gtt.stolen_size - reserved_total) >> 10);
dev_priv->gtt.stolen_usable_size = dev_priv->gtt.stolen_size -
reserved_total;
drm_mm_init(&dev_priv->mm.stolen, 0, dev_priv->gtt.stolen_usable_size);
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
sg->offset = 0;
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
static void
i915_gem_object_release_stolen(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = obj->base.dev->dev_private;
if (obj->stolen) {
i915_gem_stolen_remove_node(dev_priv, obj->stolen);
kfree(obj->stolen);
obj->stolen = NULL;
}
}
static struct drm_i915_gem_object *
_i915_gem_object_create_stolen(struct drm_device *dev,
struct drm_mm_node *stolen)
{
struct drm_i915_gem_object *obj;
obj = i915_gem_object_alloc(dev);
if (obj == NULL)
return NULL;
drm_gem_private_object_init(dev, &obj->base, stolen->size);
i915_gem_object_init(obj, &i915_gem_object_stolen_ops);
obj->pages = i915_pages_create_for_stolen(dev,
stolen->start, stolen->size);
if (obj->pages == NULL)
goto cleanup;
i915_gem_object_pin_pages(obj);
obj->stolen = stolen;
obj->base.read_domains = I915_GEM_DOMAIN_CPU | I915_GEM_DOMAIN_GTT;
obj->cache_level = HAS_LLC(dev) ? I915_CACHE_LLC : I915_CACHE_NONE;
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
int ret;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return NULL;
DRM_DEBUG_KMS("creating stolen object: size=%x\n", size);
if (size == 0)
return NULL;
stolen = kzalloc(sizeof(*stolen), GFP_KERNEL);
if (!stolen)
return NULL;
ret = i915_gem_stolen_insert_node(dev_priv, stolen, size, 4096);
if (ret) {
kfree(stolen);
return NULL;
}
obj = _i915_gem_object_create_stolen(dev, stolen);
if (obj)
return obj;
i915_gem_stolen_remove_node(dev_priv, stolen);
kfree(stolen);
return NULL;
}
struct drm_i915_gem_object *
i915_gem_object_create_stolen_for_preallocated(struct drm_device *dev,
u32 stolen_offset,
u32 gtt_offset,
u32 size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_address_space *ggtt = &dev_priv->gtt.base;
struct drm_i915_gem_object *obj;
struct drm_mm_node *stolen;
struct i915_vma *vma;
int ret;
if (!drm_mm_initialized(&dev_priv->mm.stolen))
return NULL;
DRM_DEBUG_KMS("creating preallocated stolen object: stolen_offset=%x, gtt_offset=%x, size=%x\n",
stolen_offset, gtt_offset, size);
if (WARN_ON(size == 0) || WARN_ON(size & 4095) ||
WARN_ON(stolen_offset & 4095))
return NULL;
stolen = kzalloc(sizeof(*stolen), GFP_KERNEL);
if (!stolen)
return NULL;
stolen->start = stolen_offset;
stolen->size = size;
mutex_lock(&dev_priv->mm.stolen_lock);
ret = drm_mm_reserve_node(&dev_priv->mm.stolen, stolen);
mutex_unlock(&dev_priv->mm.stolen_lock);
if (ret) {
DRM_DEBUG_KMS("failed to allocate stolen space\n");
kfree(stolen);
return NULL;
}
obj = _i915_gem_object_create_stolen(dev, stolen);
if (obj == NULL) {
DRM_DEBUG_KMS("failed to allocate stolen object\n");
i915_gem_stolen_remove_node(dev_priv, stolen);
kfree(stolen);
return NULL;
}
if (gtt_offset == I915_GTT_OFFSET_NONE)
return obj;
vma = i915_gem_obj_lookup_or_create_vma(obj, ggtt);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto err;
}
vma->node.start = gtt_offset;
vma->node.size = size;
if (drm_mm_initialized(&ggtt->mm)) {
ret = drm_mm_reserve_node(&ggtt->mm, &vma->node);
if (ret) {
DRM_DEBUG_KMS("failed to allocate stolen GTT space\n");
goto err;
}
vma->bound |= GLOBAL_BIND;
__i915_vma_set_map_and_fenceable(vma);
list_add_tail(&vma->mm_list, &ggtt->inactive_list);
}
list_add_tail(&obj->global_list, &dev_priv->mm.bound_list);
i915_gem_object_pin_pages(obj);
return obj;
err:
drm_gem_object_unreference(&obj->base);
return NULL;
}
