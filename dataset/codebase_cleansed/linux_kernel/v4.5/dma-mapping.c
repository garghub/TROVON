static pgprot_t __get_dma_pgprot(struct dma_attrs *attrs, pgprot_t prot,
bool coherent)
{
if (!coherent || dma_get_attr(DMA_ATTR_WRITE_COMBINE, attrs))
return pgprot_writecombine(prot);
return prot;
}
static int __init early_coherent_pool(char *p)
{
atomic_pool_size = memparse(p, &p);
return 0;
}
static void *__alloc_from_pool(size_t size, struct page **ret_page, gfp_t flags)
{
unsigned long val;
void *ptr = NULL;
if (!atomic_pool) {
WARN(1, "coherent pool not initialised!\n");
return NULL;
}
val = gen_pool_alloc(atomic_pool, size);
if (val) {
phys_addr_t phys = gen_pool_virt_to_phys(atomic_pool, val);
*ret_page = phys_to_page(phys);
ptr = (void *)val;
memset(ptr, 0, size);
}
return ptr;
}
static bool __in_atomic_pool(void *start, size_t size)
{
return addr_in_gen_pool(atomic_pool, (unsigned long)start, size);
}
static int __free_from_pool(void *start, size_t size)
{
if (!__in_atomic_pool(start, size))
return 0;
gen_pool_free(atomic_pool, (unsigned long)start, size);
return 1;
}
static void *__dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
if (dev == NULL) {
WARN_ONCE(1, "Use an actual device structure for DMA allocation\n");
return NULL;
}
if (IS_ENABLED(CONFIG_ZONE_DMA) &&
dev->coherent_dma_mask <= DMA_BIT_MASK(32))
flags |= GFP_DMA;
if (dev_get_cma_area(dev) && gfpflags_allow_blocking(flags)) {
struct page *page;
void *addr;
page = dma_alloc_from_contiguous(dev, size >> PAGE_SHIFT,
get_order(size));
if (!page)
return NULL;
*dma_handle = phys_to_dma(dev, page_to_phys(page));
addr = page_address(page);
memset(addr, 0, size);
return addr;
} else {
return swiotlb_alloc_coherent(dev, size, dma_handle, flags);
}
}
static void __dma_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
bool freed;
phys_addr_t paddr = dma_to_phys(dev, dma_handle);
if (dev == NULL) {
WARN_ONCE(1, "Use an actual device structure for DMA allocation\n");
return;
}
freed = dma_release_from_contiguous(dev,
phys_to_page(paddr),
size >> PAGE_SHIFT);
if (!freed)
swiotlb_free_coherent(dev, size, vaddr, dma_handle);
}
static void *__dma_alloc(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
struct page *page;
void *ptr, *coherent_ptr;
bool coherent = is_device_dma_coherent(dev);
pgprot_t prot = __get_dma_pgprot(attrs, PAGE_KERNEL, false);
size = PAGE_ALIGN(size);
if (!coherent && !gfpflags_allow_blocking(flags)) {
struct page *page = NULL;
void *addr = __alloc_from_pool(size, &page, flags);
if (addr)
*dma_handle = phys_to_dma(dev, page_to_phys(page));
return addr;
}
ptr = __dma_alloc_coherent(dev, size, dma_handle, flags, attrs);
if (!ptr)
goto no_mem;
if (coherent)
return ptr;
__dma_flush_range(ptr, ptr + size);
page = virt_to_page(ptr);
coherent_ptr = dma_common_contiguous_remap(page, size, VM_USERMAP,
prot, NULL);
if (!coherent_ptr)
goto no_map;
return coherent_ptr;
no_map:
__dma_free_coherent(dev, size, ptr, *dma_handle, attrs);
no_mem:
*dma_handle = DMA_ERROR_CODE;
return NULL;
}
static void __dma_free(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
void *swiotlb_addr = phys_to_virt(dma_to_phys(dev, dma_handle));
size = PAGE_ALIGN(size);
if (!is_device_dma_coherent(dev)) {
if (__free_from_pool(vaddr, size))
return;
vunmap(vaddr);
}
__dma_free_coherent(dev, size, swiotlb_addr, dma_handle, attrs);
}
static dma_addr_t __swiotlb_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
dma_addr_t dev_addr;
dev_addr = swiotlb_map_page(dev, page, offset, size, dir, attrs);
if (!is_device_dma_coherent(dev))
__dma_map_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
return dev_addr;
}
static void __swiotlb_unmap_page(struct device *dev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
if (!is_device_dma_coherent(dev))
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
swiotlb_unmap_page(dev, dev_addr, size, dir, attrs);
}
static int __swiotlb_map_sg_attrs(struct device *dev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i, ret;
ret = swiotlb_map_sg_attrs(dev, sgl, nelems, dir, attrs);
if (!is_device_dma_coherent(dev))
for_each_sg(sgl, sg, ret, i)
__dma_map_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
return ret;
}
static void __swiotlb_unmap_sg_attrs(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i;
if (!is_device_dma_coherent(dev))
for_each_sg(sgl, sg, nelems, i)
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
swiotlb_unmap_sg_attrs(dev, sgl, nelems, dir, attrs);
}
static void __swiotlb_sync_single_for_cpu(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
if (!is_device_dma_coherent(dev))
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
swiotlb_sync_single_for_cpu(dev, dev_addr, size, dir);
}
static void __swiotlb_sync_single_for_device(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
swiotlb_sync_single_for_device(dev, dev_addr, size, dir);
if (!is_device_dma_coherent(dev))
__dma_map_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
}
static void __swiotlb_sync_sg_for_cpu(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
struct scatterlist *sg;
int i;
if (!is_device_dma_coherent(dev))
for_each_sg(sgl, sg, nelems, i)
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
swiotlb_sync_sg_for_cpu(dev, sgl, nelems, dir);
}
static void __swiotlb_sync_sg_for_device(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
struct scatterlist *sg;
int i;
swiotlb_sync_sg_for_device(dev, sgl, nelems, dir);
if (!is_device_dma_coherent(dev))
for_each_sg(sgl, sg, nelems, i)
__dma_map_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
}
static int __swiotlb_mmap(struct device *dev,
struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size,
struct dma_attrs *attrs)
{
int ret = -ENXIO;
unsigned long nr_vma_pages = (vma->vm_end - vma->vm_start) >>
PAGE_SHIFT;
unsigned long nr_pages = PAGE_ALIGN(size) >> PAGE_SHIFT;
unsigned long pfn = dma_to_phys(dev, dma_addr) >> PAGE_SHIFT;
unsigned long off = vma->vm_pgoff;
vma->vm_page_prot = __get_dma_pgprot(attrs, vma->vm_page_prot,
is_device_dma_coherent(dev));
if (dma_mmap_from_coherent(dev, vma, cpu_addr, size, &ret))
return ret;
if (off < nr_pages && nr_vma_pages <= (nr_pages - off)) {
ret = remap_pfn_range(vma, vma->vm_start,
pfn + off,
vma->vm_end - vma->vm_start,
vma->vm_page_prot);
}
return ret;
}
static int __swiotlb_get_sgtable(struct device *dev, struct sg_table *sgt,
void *cpu_addr, dma_addr_t handle, size_t size,
struct dma_attrs *attrs)
{
int ret = sg_alloc_table(sgt, 1, GFP_KERNEL);
if (!ret)
sg_set_page(sgt->sgl, phys_to_page(dma_to_phys(dev, handle)),
PAGE_ALIGN(size), 0);
return ret;
}
static int __init atomic_pool_init(void)
{
pgprot_t prot = __pgprot(PROT_NORMAL_NC);
unsigned long nr_pages = atomic_pool_size >> PAGE_SHIFT;
struct page *page;
void *addr;
unsigned int pool_size_order = get_order(atomic_pool_size);
if (dev_get_cma_area(NULL))
page = dma_alloc_from_contiguous(NULL, nr_pages,
pool_size_order);
else
page = alloc_pages(GFP_DMA, pool_size_order);
if (page) {
int ret;
void *page_addr = page_address(page);
memset(page_addr, 0, atomic_pool_size);
__dma_flush_range(page_addr, page_addr + atomic_pool_size);
atomic_pool = gen_pool_create(PAGE_SHIFT, -1);
if (!atomic_pool)
goto free_page;
addr = dma_common_contiguous_remap(page, atomic_pool_size,
VM_USERMAP, prot, atomic_pool_init);
if (!addr)
goto destroy_genpool;
ret = gen_pool_add_virt(atomic_pool, (unsigned long)addr,
page_to_phys(page),
atomic_pool_size, -1);
if (ret)
goto remove_mapping;
gen_pool_set_algo(atomic_pool,
gen_pool_first_fit_order_align,
(void *)PAGE_SHIFT);
pr_info("DMA: preallocated %zu KiB pool for atomic allocations\n",
atomic_pool_size / 1024);
return 0;
}
goto out;
remove_mapping:
dma_common_free_remap(addr, atomic_pool_size, VM_USERMAP);
destroy_genpool:
gen_pool_destroy(atomic_pool);
atomic_pool = NULL;
free_page:
if (!dma_release_from_contiguous(NULL, page, nr_pages))
__free_pages(page, pool_size_order);
out:
pr_err("DMA: failed to allocate %zu KiB pool for atomic coherent allocation\n",
atomic_pool_size / 1024);
return -ENOMEM;
}
static void *__dummy_alloc(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
return NULL;
}
static void __dummy_free(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
}
static int __dummy_mmap(struct device *dev,
struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size,
struct dma_attrs *attrs)
{
return -ENXIO;
}
static dma_addr_t __dummy_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
return DMA_ERROR_CODE;
}
static void __dummy_unmap_page(struct device *dev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
}
static int __dummy_map_sg(struct device *dev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
return 0;
}
static void __dummy_unmap_sg(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
}
static void __dummy_sync_single(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
}
static void __dummy_sync_sg(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
}
static int __dummy_mapping_error(struct device *hwdev, dma_addr_t dma_addr)
{
return 1;
}
static int __dummy_dma_supported(struct device *hwdev, u64 mask)
{
return 0;
}
static int __init arm64_dma_init(void)
{
return atomic_pool_init();
}
static int __init dma_debug_do_init(void)
{
dma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);
return 0;
}
static void flush_page(struct device *dev, const void *virt, phys_addr_t phys)
{
__dma_flush_range(virt, virt + PAGE_SIZE);
}
static void *__iommu_alloc_attrs(struct device *dev, size_t size,
dma_addr_t *handle, gfp_t gfp,
struct dma_attrs *attrs)
{
bool coherent = is_device_dma_coherent(dev);
int ioprot = dma_direction_to_prot(DMA_BIDIRECTIONAL, coherent);
size_t iosize = size;
void *addr;
if (WARN(!dev, "cannot create IOMMU mapping for unknown device\n"))
return NULL;
size = PAGE_ALIGN(size);
gfp |= __GFP_ZERO;
if (gfpflags_allow_blocking(gfp)) {
struct page **pages;
pgprot_t prot = __get_dma_pgprot(attrs, PAGE_KERNEL, coherent);
pages = iommu_dma_alloc(dev, iosize, gfp, ioprot, handle,
flush_page);
if (!pages)
return NULL;
addr = dma_common_pages_remap(pages, size, VM_USERMAP, prot,
__builtin_return_address(0));
if (!addr)
iommu_dma_free(dev, pages, iosize, handle);
} else {
struct page *page;
if (coherent) {
page = alloc_pages(gfp, get_order(size));
addr = page ? page_address(page) : NULL;
} else {
addr = __alloc_from_pool(size, &page, gfp);
}
if (!addr)
return NULL;
*handle = iommu_dma_map_page(dev, page, 0, iosize, ioprot);
if (iommu_dma_mapping_error(dev, *handle)) {
if (coherent)
__free_pages(page, get_order(size));
else
__free_from_pool(addr, size);
addr = NULL;
}
}
return addr;
}
static void __iommu_free_attrs(struct device *dev, size_t size, void *cpu_addr,
dma_addr_t handle, struct dma_attrs *attrs)
{
size_t iosize = size;
size = PAGE_ALIGN(size);
if (__in_atomic_pool(cpu_addr, size)) {
iommu_dma_unmap_page(dev, handle, iosize, 0, NULL);
__free_from_pool(cpu_addr, size);
} else if (is_vmalloc_addr(cpu_addr)){
struct vm_struct *area = find_vm_area(cpu_addr);
if (WARN_ON(!area || !area->pages))
return;
iommu_dma_free(dev, area->pages, iosize, &handle);
dma_common_free_remap(cpu_addr, size, VM_USERMAP);
} else {
iommu_dma_unmap_page(dev, handle, iosize, 0, NULL);
__free_pages(virt_to_page(cpu_addr), get_order(size));
}
}
static int __iommu_mmap_attrs(struct device *dev, struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size,
struct dma_attrs *attrs)
{
struct vm_struct *area;
int ret;
vma->vm_page_prot = __get_dma_pgprot(attrs, vma->vm_page_prot,
is_device_dma_coherent(dev));
if (dma_mmap_from_coherent(dev, vma, cpu_addr, size, &ret))
return ret;
area = find_vm_area(cpu_addr);
if (WARN_ON(!area || !area->pages))
return -ENXIO;
return iommu_dma_mmap(area->pages, size, vma);
}
static int __iommu_get_sgtable(struct device *dev, struct sg_table *sgt,
void *cpu_addr, dma_addr_t dma_addr,
size_t size, struct dma_attrs *attrs)
{
unsigned int count = PAGE_ALIGN(size) >> PAGE_SHIFT;
struct vm_struct *area = find_vm_area(cpu_addr);
if (WARN_ON(!area || !area->pages))
return -ENXIO;
return sg_alloc_table_from_pages(sgt, area->pages, count, 0, size,
GFP_KERNEL);
}
static void __iommu_sync_single_for_cpu(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
phys_addr_t phys;
if (is_device_dma_coherent(dev))
return;
phys = iommu_iova_to_phys(iommu_get_domain_for_dev(dev), dev_addr);
__dma_unmap_area(phys_to_virt(phys), size, dir);
}
static void __iommu_sync_single_for_device(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
phys_addr_t phys;
if (is_device_dma_coherent(dev))
return;
phys = iommu_iova_to_phys(iommu_get_domain_for_dev(dev), dev_addr);
__dma_map_area(phys_to_virt(phys), size, dir);
}
static dma_addr_t __iommu_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
bool coherent = is_device_dma_coherent(dev);
int prot = dma_direction_to_prot(dir, coherent);
dma_addr_t dev_addr = iommu_dma_map_page(dev, page, offset, size, prot);
if (!iommu_dma_mapping_error(dev, dev_addr) &&
!dma_get_attr(DMA_ATTR_SKIP_CPU_SYNC, attrs))
__iommu_sync_single_for_device(dev, dev_addr, size, dir);
return dev_addr;
}
static void __iommu_unmap_page(struct device *dev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
if (!dma_get_attr(DMA_ATTR_SKIP_CPU_SYNC, attrs))
__iommu_sync_single_for_cpu(dev, dev_addr, size, dir);
iommu_dma_unmap_page(dev, dev_addr, size, dir, attrs);
}
static void __iommu_sync_sg_for_cpu(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
struct scatterlist *sg;
int i;
if (is_device_dma_coherent(dev))
return;
for_each_sg(sgl, sg, nelems, i)
__dma_unmap_area(sg_virt(sg), sg->length, dir);
}
static void __iommu_sync_sg_for_device(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
struct scatterlist *sg;
int i;
if (is_device_dma_coherent(dev))
return;
for_each_sg(sgl, sg, nelems, i)
__dma_map_area(sg_virt(sg), sg->length, dir);
}
static int __iommu_map_sg_attrs(struct device *dev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
bool coherent = is_device_dma_coherent(dev);
if (!dma_get_attr(DMA_ATTR_SKIP_CPU_SYNC, attrs))
__iommu_sync_sg_for_device(dev, sgl, nelems, dir);
return iommu_dma_map_sg(dev, sgl, nelems,
dma_direction_to_prot(dir, coherent));
}
static void __iommu_unmap_sg_attrs(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
if (!dma_get_attr(DMA_ATTR_SKIP_CPU_SYNC, attrs))
__iommu_sync_sg_for_cpu(dev, sgl, nelems, dir);
iommu_dma_unmap_sg(dev, sgl, nelems, dir, attrs);
}
static bool do_iommu_attach(struct device *dev, const struct iommu_ops *ops,
u64 dma_base, u64 size)
{
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
if (!domain) {
domain = ops->domain_alloc(IOMMU_DOMAIN_DMA);
if (!domain)
goto out_no_domain;
domain->ops = ops;
domain->type = IOMMU_DOMAIN_DMA | __IOMMU_DOMAIN_FAKE_DEFAULT;
if (iommu_attach_device(domain, dev))
goto out_put_domain;
}
if (iommu_dma_init_domain(domain, dma_base, size))
goto out_detach;
dev->archdata.dma_ops = &iommu_dma_ops;
return true;
out_detach:
iommu_detach_device(domain, dev);
out_put_domain:
if (domain->type & __IOMMU_DOMAIN_FAKE_DEFAULT)
iommu_domain_free(domain);
out_no_domain:
pr_warn("Failed to set up IOMMU for device %s; retaining platform DMA ops\n",
dev_name(dev));
return false;
}
static void queue_iommu_attach(struct device *dev, const struct iommu_ops *ops,
u64 dma_base, u64 size)
{
struct iommu_dma_notifier_data *iommudata;
iommudata = kzalloc(sizeof(*iommudata), GFP_KERNEL);
if (!iommudata)
return;
iommudata->dev = dev;
iommudata->ops = ops;
iommudata->dma_base = dma_base;
iommudata->size = size;
mutex_lock(&iommu_dma_notifier_lock);
list_add(&iommudata->list, &iommu_dma_masters);
mutex_unlock(&iommu_dma_notifier_lock);
}
static int __iommu_attach_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct iommu_dma_notifier_data *master, *tmp;
if (action != BUS_NOTIFY_ADD_DEVICE)
return 0;
mutex_lock(&iommu_dma_notifier_lock);
list_for_each_entry_safe(master, tmp, &iommu_dma_masters, list) {
if (do_iommu_attach(master->dev, master->ops,
master->dma_base, master->size)) {
list_del(&master->list);
kfree(master);
}
}
mutex_unlock(&iommu_dma_notifier_lock);
return 0;
}
static int __init register_iommu_dma_ops_notifier(struct bus_type *bus)
{
struct notifier_block *nb = kzalloc(sizeof(*nb), GFP_KERNEL);
int ret;
if (!nb)
return -ENOMEM;
nb->notifier_call = __iommu_attach_notifier;
nb->priority = -100;
ret = bus_register_notifier(bus, nb);
if (ret) {
pr_warn("Failed to register DMA domain notifier; IOMMU DMA ops unavailable on bus '%s'\n",
bus->name);
kfree(nb);
}
return ret;
}
static int __init __iommu_dma_init(void)
{
int ret;
ret = iommu_dma_init();
if (!ret)
ret = register_iommu_dma_ops_notifier(&platform_bus_type);
if (!ret)
ret = register_iommu_dma_ops_notifier(&amba_bustype);
if (!ret)
__iommu_attach_notifier(NULL, BUS_NOTIFY_ADD_DEVICE, NULL);
return ret;
}
static void __iommu_setup_dma_ops(struct device *dev, u64 dma_base, u64 size,
const struct iommu_ops *ops)
{
struct iommu_group *group;
if (!ops)
return;
group = iommu_group_get(dev);
if (group) {
do_iommu_attach(dev, ops, dma_base, size);
iommu_group_put(group);
} else {
queue_iommu_attach(dev, ops, dma_base, size);
}
}
void arch_teardown_dma_ops(struct device *dev)
{
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
if (domain) {
iommu_detach_device(domain, dev);
if (domain->type & __IOMMU_DOMAIN_FAKE_DEFAULT)
iommu_domain_free(domain);
}
dev->archdata.dma_ops = NULL;
}
static void __iommu_setup_dma_ops(struct device *dev, u64 dma_base, u64 size,
struct iommu_ops *iommu)
{ }
void arch_setup_dma_ops(struct device *dev, u64 dma_base, u64 size,
struct iommu_ops *iommu, bool coherent)
{
if (!dev->archdata.dma_ops)
dev->archdata.dma_ops = &swiotlb_dma_ops;
dev->archdata.dma_coherent = coherent;
__iommu_setup_dma_ops(dev, dma_base, size, iommu);
}
