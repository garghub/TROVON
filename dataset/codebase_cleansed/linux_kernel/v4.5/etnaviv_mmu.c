static int etnaviv_fault_handler(struct iommu_domain *iommu, struct device *dev,
unsigned long iova, int flags, void *arg)
{
DBG("*** fault: iova=%08lx, flags=%d", iova, flags);
return 0;
}
int etnaviv_iommu_map(struct etnaviv_iommu *iommu, u32 iova,
struct sg_table *sgt, unsigned len, int prot)
{
struct iommu_domain *domain = iommu->domain;
struct scatterlist *sg;
unsigned int da = iova;
unsigned int i, j;
int ret;
if (!domain || !sgt)
return -EINVAL;
for_each_sg(sgt->sgl, sg, sgt->nents, i) {
u32 pa = sg_dma_address(sg) - sg->offset;
size_t bytes = sg_dma_len(sg) + sg->offset;
VERB("map[%d]: %08x %08x(%zx)", i, iova, pa, bytes);
ret = iommu_map(domain, da, pa, bytes, prot);
if (ret)
goto fail;
da += bytes;
}
return 0;
fail:
da = iova;
for_each_sg(sgt->sgl, sg, i, j) {
size_t bytes = sg_dma_len(sg) + sg->offset;
iommu_unmap(domain, da, bytes);
da += bytes;
}
return ret;
}
int etnaviv_iommu_unmap(struct etnaviv_iommu *iommu, u32 iova,
struct sg_table *sgt, unsigned len)
{
struct iommu_domain *domain = iommu->domain;
struct scatterlist *sg;
unsigned int da = iova;
int i;
for_each_sg(sgt->sgl, sg, sgt->nents, i) {
size_t bytes = sg_dma_len(sg) + sg->offset;
size_t unmapped;
unmapped = iommu_unmap(domain, da, bytes);
if (unmapped < bytes)
return unmapped;
VERB("unmap[%d]: %08x(%zx)", i, iova, bytes);
BUG_ON(!PAGE_ALIGNED(bytes));
da += bytes;
}
return 0;
}
static void etnaviv_iommu_remove_mapping(struct etnaviv_iommu *mmu,
struct etnaviv_vram_mapping *mapping)
{
struct etnaviv_gem_object *etnaviv_obj = mapping->object;
etnaviv_iommu_unmap(mmu, mapping->vram_node.start,
etnaviv_obj->sgt, etnaviv_obj->base.size);
drm_mm_remove_node(&mapping->vram_node);
}
int etnaviv_iommu_map_gem(struct etnaviv_iommu *mmu,
struct etnaviv_gem_object *etnaviv_obj, u32 memory_base,
struct etnaviv_vram_mapping *mapping)
{
struct etnaviv_vram_mapping *free = NULL;
struct sg_table *sgt = etnaviv_obj->sgt;
struct drm_mm_node *node;
int ret;
lockdep_assert_held(&etnaviv_obj->lock);
mutex_lock(&mmu->lock);
if (sgt->nents == 1 && !(etnaviv_obj->flags & ETNA_BO_FORCE_MMU)) {
u32 iova;
iova = sg_dma_address(sgt->sgl) - memory_base;
if (iova < 0x80000000 - sg_dma_len(sgt->sgl)) {
mapping->iova = iova;
list_add_tail(&mapping->mmu_node, &mmu->mappings);
mutex_unlock(&mmu->lock);
return 0;
}
}
node = &mapping->vram_node;
while (1) {
struct etnaviv_vram_mapping *m, *n;
struct list_head list;
bool found;
ret = drm_mm_insert_node_in_range(&mmu->mm, node,
etnaviv_obj->base.size, 0, mmu->last_iova, ~0UL,
DRM_MM_SEARCH_DEFAULT);
if (ret != -ENOSPC)
break;
if (mmu->last_iova) {
mmu->last_iova = 0;
mmu->need_flush = true;
continue;
}
drm_mm_init_scan(&mmu->mm, etnaviv_obj->base.size, 0, 0);
found = 0;
INIT_LIST_HEAD(&list);
list_for_each_entry(free, &mmu->mappings, mmu_node) {
if (!free->vram_node.mm)
continue;
if (free->use)
continue;
list_add(&free->scan_node, &list);
if (drm_mm_scan_add_block(&free->vram_node)) {
found = true;
break;
}
}
if (!found) {
list_for_each_entry_safe(m, n, &list, scan_node)
BUG_ON(drm_mm_scan_remove_block(&m->vram_node));
break;
}
list_for_each_entry_safe(m, n, &list, scan_node)
if (!drm_mm_scan_remove_block(&m->vram_node))
list_del_init(&m->scan_node);
list_for_each_entry_safe(m, n, &list, scan_node) {
etnaviv_iommu_remove_mapping(mmu, m);
m->mmu = NULL;
list_del_init(&m->mmu_node);
list_del_init(&m->scan_node);
}
mmu->need_flush = true;
}
if (ret < 0) {
mutex_unlock(&mmu->lock);
return ret;
}
mmu->last_iova = node->start + etnaviv_obj->base.size;
mapping->iova = node->start;
ret = etnaviv_iommu_map(mmu, node->start, sgt, etnaviv_obj->base.size,
IOMMU_READ | IOMMU_WRITE);
if (ret < 0) {
drm_mm_remove_node(node);
mutex_unlock(&mmu->lock);
return ret;
}
list_add_tail(&mapping->mmu_node, &mmu->mappings);
mutex_unlock(&mmu->lock);
return ret;
}
void etnaviv_iommu_unmap_gem(struct etnaviv_iommu *mmu,
struct etnaviv_vram_mapping *mapping)
{
WARN_ON(mapping->use);
mutex_lock(&mmu->lock);
if (mapping->vram_node.mm == &mmu->mm)
etnaviv_iommu_remove_mapping(mmu, mapping);
list_del(&mapping->mmu_node);
mutex_unlock(&mmu->lock);
}
void etnaviv_iommu_destroy(struct etnaviv_iommu *mmu)
{
drm_mm_takedown(&mmu->mm);
iommu_domain_free(mmu->domain);
kfree(mmu);
}
struct etnaviv_iommu *etnaviv_iommu_new(struct etnaviv_gpu *gpu,
struct iommu_domain *domain, enum etnaviv_iommu_version version)
{
struct etnaviv_iommu *mmu;
mmu = kzalloc(sizeof(*mmu), GFP_KERNEL);
if (!mmu)
return ERR_PTR(-ENOMEM);
mmu->domain = domain;
mmu->gpu = gpu;
mmu->version = version;
mutex_init(&mmu->lock);
INIT_LIST_HEAD(&mmu->mappings);
drm_mm_init(&mmu->mm, domain->geometry.aperture_start,
domain->geometry.aperture_end -
domain->geometry.aperture_start + 1);
iommu_set_fault_handler(domain, etnaviv_fault_handler, gpu->dev);
return mmu;
}
size_t etnaviv_iommu_dump_size(struct etnaviv_iommu *iommu)
{
struct etnaviv_iommu_ops *ops;
ops = container_of(iommu->domain->ops, struct etnaviv_iommu_ops, ops);
return ops->dump_size(iommu->domain);
}
void etnaviv_iommu_dump(struct etnaviv_iommu *iommu, void *buf)
{
struct etnaviv_iommu_ops *ops;
ops = container_of(iommu->domain->ops, struct etnaviv_iommu_ops, ops);
ops->dump(iommu->domain, buf);
}
