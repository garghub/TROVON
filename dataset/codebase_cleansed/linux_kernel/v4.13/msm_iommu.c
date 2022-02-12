static int msm_fault_handler(struct iommu_domain *domain, struct device *dev,
unsigned long iova, int flags, void *arg)
{
struct msm_iommu *iommu = arg;
if (iommu->base.handler)
return iommu->base.handler(iommu->base.arg, iova, flags);
pr_warn_ratelimited("*** fault: iova=%08lx, flags=%d\n", iova, flags);
return 0;
}
static int msm_iommu_attach(struct msm_mmu *mmu, const char * const *names,
int cnt)
{
struct msm_iommu *iommu = to_msm_iommu(mmu);
int ret;
pm_runtime_get_sync(mmu->dev);
ret = iommu_attach_device(iommu->domain, mmu->dev);
pm_runtime_put_sync(mmu->dev);
return ret;
}
static void msm_iommu_detach(struct msm_mmu *mmu, const char * const *names,
int cnt)
{
struct msm_iommu *iommu = to_msm_iommu(mmu);
pm_runtime_get_sync(mmu->dev);
iommu_detach_device(iommu->domain, mmu->dev);
pm_runtime_put_sync(mmu->dev);
}
static int msm_iommu_map(struct msm_mmu *mmu, uint64_t iova,
struct sg_table *sgt, unsigned len, int prot)
{
struct msm_iommu *iommu = to_msm_iommu(mmu);
size_t ret;
ret = iommu_map_sg(iommu->domain, iova, sgt->sgl, sgt->nents, prot);
WARN_ON(ret < 0);
return (ret == len) ? 0 : -EINVAL;
}
static int msm_iommu_unmap(struct msm_mmu *mmu, uint64_t iova,
struct sg_table *sgt, unsigned len)
{
struct msm_iommu *iommu = to_msm_iommu(mmu);
pm_runtime_get_sync(mmu->dev);
iommu_unmap(iommu->domain, iova, len);
pm_runtime_put_sync(mmu->dev);
return 0;
}
static void msm_iommu_destroy(struct msm_mmu *mmu)
{
struct msm_iommu *iommu = to_msm_iommu(mmu);
iommu_domain_free(iommu->domain);
kfree(iommu);
}
struct msm_mmu *msm_iommu_new(struct device *dev, struct iommu_domain *domain)
{
struct msm_iommu *iommu;
iommu = kzalloc(sizeof(*iommu), GFP_KERNEL);
if (!iommu)
return ERR_PTR(-ENOMEM);
iommu->domain = domain;
msm_mmu_init(&iommu->base, dev, &funcs);
iommu_set_fault_handler(domain, msm_fault_handler, iommu);
return &iommu->base;
}
