static u32
gk20a_instobj_rd32(struct nvkm_object *object, u64 offset)
{
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(object);
struct gk20a_instobj_priv *node = (void *)object;
unsigned long flags;
u64 base = (node->mem->offset + offset) & 0xffffff00000ULL;
u64 addr = (node->mem->offset + offset) & 0x000000fffffULL;
u32 data;
spin_lock_irqsave(&priv->lock, flags);
if (unlikely(priv->addr != base)) {
nv_wr32(priv, 0x001700, base >> 16);
priv->addr = base;
}
data = nv_rd32(priv, 0x700000 + addr);
spin_unlock_irqrestore(&priv->lock, flags);
return data;
}
static void
gk20a_instobj_wr32(struct nvkm_object *object, u64 offset, u32 data)
{
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(object);
struct gk20a_instobj_priv *node = (void *)object;
unsigned long flags;
u64 base = (node->mem->offset + offset) & 0xffffff00000ULL;
u64 addr = (node->mem->offset + offset) & 0x000000fffffULL;
spin_lock_irqsave(&priv->lock, flags);
if (unlikely(priv->addr != base)) {
nv_wr32(priv, 0x001700, base >> 16);
priv->addr = base;
}
nv_wr32(priv, 0x700000 + addr, data);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void
gk20a_instobj_dtor_dma(struct gk20a_instobj_priv *_node)
{
struct gk20a_instobj_dma *node = (void *)_node;
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(node);
struct device *dev = nv_device_base(nv_device(priv));
if (unlikely(!node->cpuaddr))
return;
dma_free_attrs(dev, _node->mem->size << PAGE_SHIFT, node->cpuaddr,
node->handle, &priv->attrs);
}
static void
gk20a_instobj_dtor_iommu(struct gk20a_instobj_priv *_node)
{
struct gk20a_instobj_iommu *node = (void *)_node;
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(node);
struct nvkm_mm_node *r;
int i;
if (unlikely(list_empty(&_node->mem->regions)))
return;
r = list_first_entry(&_node->mem->regions, struct nvkm_mm_node,
rl_entry);
r->offset &= ~BIT(34 - priv->iommu_pgshift);
for (i = 0; i < _node->mem->size; i++) {
iommu_unmap(priv->domain,
(r->offset + i) << priv->iommu_pgshift, PAGE_SIZE);
__free_page(node->pages[i]);
}
mutex_lock(priv->mm_mutex);
nvkm_mm_free(priv->mm, &r);
mutex_unlock(priv->mm_mutex);
}
static void
gk20a_instobj_dtor(struct nvkm_object *object)
{
struct gk20a_instobj_priv *node = (void *)object;
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(node);
if (priv->domain)
gk20a_instobj_dtor_iommu(node);
else
gk20a_instobj_dtor_dma(node);
nvkm_instobj_destroy(&node->base);
}
static int
gk20a_instobj_ctor_dma(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, u32 npages, u32 align,
struct gk20a_instobj_priv **_node)
{
struct gk20a_instobj_dma *node;
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(parent);
struct device *dev = nv_device_base(nv_device(parent));
int ret;
ret = nvkm_instobj_create_(parent, engine, oclass, sizeof(*node),
(void **)&node);
*_node = &node->base;
if (ret)
return ret;
node->cpuaddr = dma_alloc_attrs(dev, npages << PAGE_SHIFT,
&node->handle, GFP_KERNEL,
&priv->attrs);
if (!node->cpuaddr) {
nv_error(priv, "cannot allocate DMA memory\n");
return -ENOMEM;
}
if (unlikely(node->handle & (align - 1)))
nv_warn(priv, "memory not aligned as requested: %pad (0x%x)\n",
&node->handle, align);
node->r.type = 12;
node->r.offset = node->handle >> 12;
node->r.length = (npages << PAGE_SHIFT) >> 12;
node->base._mem.offset = node->handle;
INIT_LIST_HEAD(&node->base._mem.regions);
list_add_tail(&node->r.rl_entry, &node->base._mem.regions);
return 0;
}
static int
gk20a_instobj_ctor_iommu(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, u32 npages, u32 align,
struct gk20a_instobj_priv **_node)
{
struct gk20a_instobj_iommu *node;
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(parent);
struct nvkm_mm_node *r;
int ret;
int i;
ret = nvkm_instobj_create_(parent, engine, oclass,
sizeof(*node) + sizeof(node->pages[0]) * npages,
(void **)&node);
*_node = &node->base;
if (ret)
return ret;
for (i = 0; i < npages; i++) {
struct page *p = alloc_page(GFP_KERNEL);
if (p == NULL) {
ret = -ENOMEM;
goto free_pages;
}
node->pages[i] = p;
}
mutex_lock(priv->mm_mutex);
ret = nvkm_mm_head(priv->mm, 0, 1, npages, npages,
align >> priv->iommu_pgshift, &r);
mutex_unlock(priv->mm_mutex);
if (ret) {
nv_error(priv, "virtual space is full!\n");
goto free_pages;
}
for (i = 0; i < npages; i++) {
struct page *p = node->pages[i];
u32 offset = (r->offset + i) << priv->iommu_pgshift;
ret = iommu_map(priv->domain, offset, page_to_phys(p),
PAGE_SIZE, IOMMU_READ | IOMMU_WRITE);
if (ret < 0) {
nv_error(priv, "IOMMU mapping failure: %d\n", ret);
while (i-- > 0) {
offset -= PAGE_SIZE;
iommu_unmap(priv->domain, offset, PAGE_SIZE);
}
goto release_area;
}
}
r->offset |= BIT(34 - priv->iommu_pgshift);
node->base._mem.offset = ((u64)r->offset) << priv->iommu_pgshift;
INIT_LIST_HEAD(&node->base._mem.regions);
list_add_tail(&r->rl_entry, &node->base._mem.regions);
return 0;
release_area:
mutex_lock(priv->mm_mutex);
nvkm_mm_free(priv->mm, &r);
mutex_unlock(priv->mm_mutex);
free_pages:
for (i = 0; i < npages && node->pages[i] != NULL; i++)
__free_page(node->pages[i]);
return ret;
}
static int
gk20a_instobj_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 _size,
struct nvkm_object **pobject)
{
struct nvkm_instobj_args *args = data;
struct gk20a_instmem_priv *priv = (void *)nvkm_instmem(parent);
struct gk20a_instobj_priv *node;
u32 size, align;
int ret;
nv_debug(parent, "%s (%s): size: %x align: %x\n", __func__,
priv->domain ? "IOMMU" : "DMA", args->size, args->align);
size = max(roundup(args->size, PAGE_SIZE), PAGE_SIZE);
align = max(roundup(args->align, PAGE_SIZE), PAGE_SIZE);
if (priv->domain)
ret = gk20a_instobj_ctor_iommu(parent, engine, oclass,
size >> PAGE_SHIFT, align, &node);
else
ret = gk20a_instobj_ctor_dma(parent, engine, oclass,
size >> PAGE_SHIFT, align, &node);
*pobject = nv_object(node);
if (ret)
return ret;
node->mem = &node->_mem;
node->mem->size = size >> 12;
node->mem->memtype = 0;
node->mem->page_shift = 12;
node->base.addr = node->mem->offset;
node->base.size = size;
nv_debug(parent, "alloc size: 0x%x, align: 0x%x, gaddr: 0x%llx\n",
size, align, node->mem->offset);
return 0;
}
static int
gk20a_instmem_fini(struct nvkm_object *object, bool suspend)
{
struct gk20a_instmem_priv *priv = (void *)object;
priv->addr = ~0ULL;
return nvkm_instmem_fini(&priv->base, suspend);
}
static int
gk20a_instmem_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct gk20a_instmem_priv *priv;
struct nouveau_platform_device *plat;
int ret;
ret = nvkm_instmem_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
spin_lock_init(&priv->lock);
plat = nv_device_to_platform(nv_device(parent));
if (plat->gpu->iommu.domain) {
priv->domain = plat->gpu->iommu.domain;
priv->mm = plat->gpu->iommu.mm;
priv->iommu_pgshift = plat->gpu->iommu.pgshift;
priv->mm_mutex = &plat->gpu->iommu.mutex;
nv_info(priv, "using IOMMU\n");
} else {
init_dma_attrs(&priv->attrs);
dma_set_attr(DMA_ATTR_NON_CONSISTENT, &priv->attrs);
dma_set_attr(DMA_ATTR_WEAK_ORDERING, &priv->attrs);
dma_set_attr(DMA_ATTR_WRITE_COMBINE, &priv->attrs);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &priv->attrs);
nv_info(priv, "using DMA API\n");
}
return 0;
}
