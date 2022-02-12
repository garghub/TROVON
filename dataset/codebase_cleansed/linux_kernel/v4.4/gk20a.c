static enum nvkm_memory_target
gk20a_instobj_target(struct nvkm_memory *memory)
{
return NVKM_MEM_TARGET_HOST;
}
static u64
gk20a_instobj_addr(struct nvkm_memory *memory)
{
return gk20a_instobj(memory)->mem.offset;
}
static u64
gk20a_instobj_size(struct nvkm_memory *memory)
{
return (u64)gk20a_instobj(memory)->mem.size << 12;
}
static void __iomem *
gk20a_instobj_cpu_map_dma(struct nvkm_memory *memory)
{
#if defined(CONFIG_ARM) || defined(CONFIG_ARM64)
struct gk20a_instobj_dma *node = gk20a_instobj_dma(memory);
struct device *dev = node->base.imem->base.subdev.device->dev;
int npages = nvkm_memory_size(memory) >> 12;
struct page *pages[npages];
int i;
pages[0] = pfn_to_page(dma_to_phys(dev, node->handle) >> PAGE_SHIFT);
for (i = 1; i < npages; i++)
pages[i] = pages[0] + i;
return vmap(pages, npages, VM_MAP, pgprot_writecombine(PAGE_KERNEL));
#else
BUG();
return NULL;
#endif
}
static void __iomem *
gk20a_instobj_cpu_map_iommu(struct nvkm_memory *memory)
{
struct gk20a_instobj_iommu *node = gk20a_instobj_iommu(memory);
int npages = nvkm_memory_size(memory) >> 12;
return vmap(node->pages, npages, VM_MAP,
pgprot_writecombine(PAGE_KERNEL));
}
static void
gk20a_instmem_vaddr_gc(struct gk20a_instmem *imem, const u64 size)
{
while (imem->vaddr_use + size > imem->vaddr_max) {
struct gk20a_instobj *obj;
if (list_empty(&imem->vaddr_lru))
break;
obj = list_first_entry(&imem->vaddr_lru, struct gk20a_instobj,
vaddr_node);
list_del(&obj->vaddr_node);
vunmap(obj->vaddr);
obj->vaddr = NULL;
imem->vaddr_use -= nvkm_memory_size(&obj->memory);
nvkm_debug(&imem->base.subdev, "(GC) vaddr used: %x/%x\n",
imem->vaddr_use, imem->vaddr_max);
}
}
static void __iomem *
gk20a_instobj_acquire(struct nvkm_memory *memory)
{
struct gk20a_instobj *node = gk20a_instobj(memory);
struct gk20a_instmem *imem = node->imem;
struct nvkm_ltc *ltc = imem->base.subdev.device->ltc;
const u64 size = nvkm_memory_size(memory);
unsigned long flags;
nvkm_ltc_flush(ltc);
spin_lock_irqsave(&imem->lock, flags);
if (node->vaddr) {
list_del(&node->vaddr_node);
goto out;
}
gk20a_instmem_vaddr_gc(imem, size);
node->vaddr = imem->cpu_map(memory);
if (!node->vaddr) {
nvkm_error(&imem->base.subdev, "cannot map instobj - "
"this is not going to end well...\n");
goto out;
}
imem->vaddr_use += size;
nvkm_debug(&imem->base.subdev, "vaddr used: %x/%x\n",
imem->vaddr_use, imem->vaddr_max);
out:
spin_unlock_irqrestore(&imem->lock, flags);
return node->vaddr;
}
static void
gk20a_instobj_release(struct nvkm_memory *memory)
{
struct gk20a_instobj *node = gk20a_instobj(memory);
struct gk20a_instmem *imem = node->imem;
struct nvkm_ltc *ltc = imem->base.subdev.device->ltc;
unsigned long flags;
spin_lock_irqsave(&imem->lock, flags);
list_add_tail(&node->vaddr_node, &imem->vaddr_lru);
spin_unlock_irqrestore(&imem->lock, flags);
wmb();
nvkm_ltc_invalidate(ltc);
}
static u32
gk20a_instobj_rd32(struct nvkm_memory *memory, u64 offset)
{
struct gk20a_instobj *node = gk20a_instobj(memory);
return node->vaddr[offset / 4];
}
static void
gk20a_instobj_wr32(struct nvkm_memory *memory, u64 offset, u32 data)
{
struct gk20a_instobj *node = gk20a_instobj(memory);
node->vaddr[offset / 4] = data;
}
static void
gk20a_instobj_map(struct nvkm_memory *memory, struct nvkm_vma *vma, u64 offset)
{
struct gk20a_instobj *node = gk20a_instobj(memory);
nvkm_vm_map_at(vma, offset, &node->mem);
}
static void
gk20a_instobj_dtor(struct gk20a_instobj *node)
{
struct gk20a_instmem *imem = node->imem;
struct gk20a_instobj *obj;
unsigned long flags;
spin_lock_irqsave(&imem->lock, flags);
if (!node->vaddr)
goto out;
list_for_each_entry(obj, &imem->vaddr_lru, vaddr_node) {
if (obj == node) {
list_del(&obj->vaddr_node);
break;
}
}
vunmap(node->vaddr);
node->vaddr = NULL;
imem->vaddr_use -= nvkm_memory_size(&node->memory);
nvkm_debug(&imem->base.subdev, "vaddr used: %x/%x\n",
imem->vaddr_use, imem->vaddr_max);
out:
spin_unlock_irqrestore(&imem->lock, flags);
}
static void *
gk20a_instobj_dtor_dma(struct nvkm_memory *memory)
{
struct gk20a_instobj_dma *node = gk20a_instobj_dma(memory);
struct gk20a_instmem *imem = node->base.imem;
struct device *dev = imem->base.subdev.device->dev;
gk20a_instobj_dtor(&node->base);
if (unlikely(!node->cpuaddr))
goto out;
dma_free_attrs(dev, node->base.mem.size << PAGE_SHIFT, node->cpuaddr,
node->handle, &imem->attrs);
out:
return node;
}
static void *
gk20a_instobj_dtor_iommu(struct nvkm_memory *memory)
{
struct gk20a_instobj_iommu *node = gk20a_instobj_iommu(memory);
struct gk20a_instmem *imem = node->base.imem;
struct device *dev = imem->base.subdev.device->dev;
struct nvkm_mm_node *r;
int i;
gk20a_instobj_dtor(&node->base);
if (unlikely(list_empty(&node->base.mem.regions)))
goto out;
r = list_first_entry(&node->base.mem.regions, struct nvkm_mm_node,
rl_entry);
r->offset &= ~BIT(imem->iommu_bit - imem->iommu_pgshift);
for (i = 0; i < node->base.mem.size; i++) {
iommu_unmap(imem->domain,
(r->offset + i) << imem->iommu_pgshift, PAGE_SIZE);
dma_unmap_page(dev, node->dma_addrs[i], PAGE_SIZE,
DMA_BIDIRECTIONAL);
__free_page(node->pages[i]);
}
mutex_lock(imem->mm_mutex);
nvkm_mm_free(imem->mm, &r);
mutex_unlock(imem->mm_mutex);
out:
return node;
}
static int
gk20a_instobj_ctor_dma(struct gk20a_instmem *imem, u32 npages, u32 align,
struct gk20a_instobj **_node)
{
struct gk20a_instobj_dma *node;
struct nvkm_subdev *subdev = &imem->base.subdev;
struct device *dev = subdev->device->dev;
if (!(node = kzalloc(sizeof(*node), GFP_KERNEL)))
return -ENOMEM;
*_node = &node->base;
nvkm_memory_ctor(&gk20a_instobj_func_dma, &node->base.memory);
node->cpuaddr = dma_alloc_attrs(dev, npages << PAGE_SHIFT,
&node->handle, GFP_KERNEL,
&imem->attrs);
if (!node->cpuaddr) {
nvkm_error(subdev, "cannot allocate DMA memory\n");
return -ENOMEM;
}
if (unlikely(node->handle & (align - 1)))
nvkm_warn(subdev,
"memory not aligned as requested: %pad (0x%x)\n",
&node->handle, align);
node->r.type = 12;
node->r.offset = node->handle >> 12;
node->r.length = (npages << PAGE_SHIFT) >> 12;
node->base.mem.offset = node->handle;
INIT_LIST_HEAD(&node->base.mem.regions);
list_add_tail(&node->r.rl_entry, &node->base.mem.regions);
return 0;
}
static int
gk20a_instobj_ctor_iommu(struct gk20a_instmem *imem, u32 npages, u32 align,
struct gk20a_instobj **_node)
{
struct gk20a_instobj_iommu *node;
struct nvkm_subdev *subdev = &imem->base.subdev;
struct device *dev = subdev->device->dev;
struct nvkm_mm_node *r;
int ret;
int i;
if (!(node = kzalloc(sizeof(*node) + ((sizeof(node->pages[0]) +
sizeof(*node->dma_addrs)) * npages), GFP_KERNEL)))
return -ENOMEM;
*_node = &node->base;
node->dma_addrs = (void *)(node->pages + npages);
nvkm_memory_ctor(&gk20a_instobj_func_iommu, &node->base.memory);
for (i = 0; i < npages; i++) {
struct page *p = alloc_page(GFP_KERNEL);
dma_addr_t dma_adr;
if (p == NULL) {
ret = -ENOMEM;
goto free_pages;
}
node->pages[i] = p;
dma_adr = dma_map_page(dev, p, 0, PAGE_SIZE, DMA_BIDIRECTIONAL);
if (dma_mapping_error(dev, dma_adr)) {
nvkm_error(subdev, "DMA mapping error!\n");
ret = -ENOMEM;
goto free_pages;
}
node->dma_addrs[i] = dma_adr;
}
mutex_lock(imem->mm_mutex);
ret = nvkm_mm_head(imem->mm, 0, 1, npages, npages,
align >> imem->iommu_pgshift, &r);
mutex_unlock(imem->mm_mutex);
if (ret) {
nvkm_error(subdev, "IOMMU space is full!\n");
goto free_pages;
}
for (i = 0; i < npages; i++) {
u32 offset = (r->offset + i) << imem->iommu_pgshift;
ret = iommu_map(imem->domain, offset, node->dma_addrs[i],
PAGE_SIZE, IOMMU_READ | IOMMU_WRITE);
if (ret < 0) {
nvkm_error(subdev, "IOMMU mapping failure: %d\n", ret);
while (i-- > 0) {
offset -= PAGE_SIZE;
iommu_unmap(imem->domain, offset, PAGE_SIZE);
}
goto release_area;
}
}
r->offset |= BIT(imem->iommu_bit - imem->iommu_pgshift);
node->base.mem.offset = ((u64)r->offset) << imem->iommu_pgshift;
INIT_LIST_HEAD(&node->base.mem.regions);
list_add_tail(&r->rl_entry, &node->base.mem.regions);
return 0;
release_area:
mutex_lock(imem->mm_mutex);
nvkm_mm_free(imem->mm, &r);
mutex_unlock(imem->mm_mutex);
free_pages:
for (i = 0; i < npages && node->pages[i] != NULL; i++) {
dma_addr_t dma_addr = node->dma_addrs[i];
if (dma_addr)
dma_unmap_page(dev, dma_addr, PAGE_SIZE,
DMA_BIDIRECTIONAL);
__free_page(node->pages[i]);
}
return ret;
}
static int
gk20a_instobj_new(struct nvkm_instmem *base, u32 size, u32 align, bool zero,
struct nvkm_memory **pmemory)
{
struct gk20a_instmem *imem = gk20a_instmem(base);
struct nvkm_subdev *subdev = &imem->base.subdev;
struct gk20a_instobj *node = NULL;
int ret;
nvkm_debug(subdev, "%s (%s): size: %x align: %x\n", __func__,
imem->domain ? "IOMMU" : "DMA", size, align);
size = max(roundup(size, PAGE_SIZE), PAGE_SIZE);
align = max(roundup(align, PAGE_SIZE), PAGE_SIZE);
if (imem->domain)
ret = gk20a_instobj_ctor_iommu(imem, size >> PAGE_SHIFT,
align, &node);
else
ret = gk20a_instobj_ctor_dma(imem, size >> PAGE_SHIFT,
align, &node);
*pmemory = node ? &node->memory : NULL;
if (ret)
return ret;
node->imem = imem;
node->mem.size = size >> 12;
node->mem.memtype = 0;
node->mem.page_shift = 12;
nvkm_debug(subdev, "alloc size: 0x%x, align: 0x%x, gaddr: 0x%llx\n",
size, align, node->mem.offset);
return 0;
}
static void *
gk20a_instmem_dtor(struct nvkm_instmem *base)
{
struct gk20a_instmem *imem = gk20a_instmem(base);
if (!list_empty(&imem->vaddr_lru))
nvkm_warn(&base->subdev, "instobj LRU not empty!\n");
if (imem->vaddr_use != 0)
nvkm_warn(&base->subdev, "instobj vmap area not empty! "
"0x%x bytes still mapped\n", imem->vaddr_use);
return imem;
}
int
gk20a_instmem_new(struct nvkm_device *device, int index,
struct nvkm_instmem **pimem)
{
struct nvkm_device_tegra *tdev = device->func->tegra(device);
struct gk20a_instmem *imem;
if (!(imem = kzalloc(sizeof(*imem), GFP_KERNEL)))
return -ENOMEM;
nvkm_instmem_ctor(&gk20a_instmem, device, index, &imem->base);
spin_lock_init(&imem->lock);
*pimem = &imem->base;
imem->vaddr_use = 0;
imem->vaddr_max = 0x100000;
INIT_LIST_HEAD(&imem->vaddr_lru);
if (tdev->iommu.domain) {
imem->mm_mutex = &tdev->iommu.mutex;
imem->mm = &tdev->iommu.mm;
imem->domain = tdev->iommu.domain;
imem->iommu_pgshift = tdev->iommu.pgshift;
imem->cpu_map = gk20a_instobj_cpu_map_iommu;
imem->iommu_bit = tdev->func->iommu_bit;
nvkm_info(&imem->base.subdev, "using IOMMU\n");
} else {
init_dma_attrs(&imem->attrs);
dma_set_attr(DMA_ATTR_NON_CONSISTENT, &imem->attrs);
dma_set_attr(DMA_ATTR_WEAK_ORDERING, &imem->attrs);
dma_set_attr(DMA_ATTR_WRITE_COMBINE, &imem->attrs);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &imem->attrs);
imem->cpu_map = gk20a_instobj_cpu_map_dma;
nvkm_info(&imem->base.subdev, "using DMA API\n");
}
return 0;
}
