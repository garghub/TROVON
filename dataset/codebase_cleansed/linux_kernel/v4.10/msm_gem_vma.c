void
msm_gem_unmap_vma(struct msm_gem_address_space *aspace,
struct msm_gem_vma *vma, struct sg_table *sgt)
{
if (!vma->iova)
return;
if (aspace->mmu) {
unsigned size = vma->node.size << PAGE_SHIFT;
aspace->mmu->funcs->unmap(aspace->mmu, vma->iova, sgt, size);
}
drm_mm_remove_node(&vma->node);
vma->iova = 0;
}
int
msm_gem_map_vma(struct msm_gem_address_space *aspace,
struct msm_gem_vma *vma, struct sg_table *sgt, int npages)
{
int ret;
if (WARN_ON(drm_mm_node_allocated(&vma->node)))
return 0;
ret = drm_mm_insert_node(&aspace->mm, &vma->node, npages,
0, DRM_MM_SEARCH_DEFAULT);
if (ret)
return ret;
vma->iova = vma->node.start << PAGE_SHIFT;
if (aspace->mmu) {
unsigned size = npages << PAGE_SHIFT;
ret = aspace->mmu->funcs->map(aspace->mmu, vma->iova, sgt,
size, IOMMU_READ | IOMMU_WRITE);
}
return ret;
}
void
msm_gem_address_space_destroy(struct msm_gem_address_space *aspace)
{
drm_mm_takedown(&aspace->mm);
if (aspace->mmu)
aspace->mmu->funcs->destroy(aspace->mmu);
kfree(aspace);
}
struct msm_gem_address_space *
msm_gem_address_space_create(struct device *dev, struct iommu_domain *domain,
const char *name)
{
struct msm_gem_address_space *aspace;
aspace = kzalloc(sizeof(*aspace), GFP_KERNEL);
if (!aspace)
return ERR_PTR(-ENOMEM);
aspace->name = name;
aspace->mmu = msm_iommu_new(dev, domain);
drm_mm_init(&aspace->mm, (domain->geometry.aperture_start >> PAGE_SHIFT),
(domain->geometry.aperture_end >> PAGE_SHIFT) - 1);
return aspace;
}
