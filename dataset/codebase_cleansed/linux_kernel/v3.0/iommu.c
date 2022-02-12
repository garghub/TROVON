void register_iommu(struct iommu_ops *ops)
{
if (iommu_ops)
BUG();
iommu_ops = ops;
}
bool iommu_found(void)
{
return iommu_ops != NULL;
}
struct iommu_domain *iommu_domain_alloc(void)
{
struct iommu_domain *domain;
int ret;
domain = kmalloc(sizeof(*domain), GFP_KERNEL);
if (!domain)
return NULL;
ret = iommu_ops->domain_init(domain);
if (ret)
goto out_free;
return domain;
out_free:
kfree(domain);
return NULL;
}
void iommu_domain_free(struct iommu_domain *domain)
{
iommu_ops->domain_destroy(domain);
kfree(domain);
}
int iommu_attach_device(struct iommu_domain *domain, struct device *dev)
{
return iommu_ops->attach_dev(domain, dev);
}
void iommu_detach_device(struct iommu_domain *domain, struct device *dev)
{
iommu_ops->detach_dev(domain, dev);
}
phys_addr_t iommu_iova_to_phys(struct iommu_domain *domain,
unsigned long iova)
{
return iommu_ops->iova_to_phys(domain, iova);
}
int iommu_domain_has_cap(struct iommu_domain *domain,
unsigned long cap)
{
return iommu_ops->domain_has_cap(domain, cap);
}
int iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, int gfp_order, int prot)
{
unsigned long invalid_mask;
size_t size;
size = 0x1000UL << gfp_order;
invalid_mask = size - 1;
BUG_ON((iova | paddr) & invalid_mask);
return iommu_ops->map(domain, iova, paddr, gfp_order, prot);
}
int iommu_unmap(struct iommu_domain *domain, unsigned long iova, int gfp_order)
{
unsigned long invalid_mask;
size_t size;
size = 0x1000UL << gfp_order;
invalid_mask = size - 1;
BUG_ON(iova & invalid_mask);
return iommu_ops->unmap(domain, iova, gfp_order);
}
