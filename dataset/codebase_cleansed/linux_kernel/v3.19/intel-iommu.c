static inline int agaw_to_level(int agaw)
{
return agaw + 2;
}
static inline int agaw_to_width(int agaw)
{
return min_t(int, 30 + agaw * LEVEL_STRIDE, MAX_AGAW_WIDTH);
}
static inline int width_to_agaw(int width)
{
return DIV_ROUND_UP(width - 30, LEVEL_STRIDE);
}
static inline unsigned int level_to_offset_bits(int level)
{
return (level - 1) * LEVEL_STRIDE;
}
static inline int pfn_level_offset(unsigned long pfn, int level)
{
return (pfn >> level_to_offset_bits(level)) & LEVEL_MASK;
}
static inline unsigned long level_mask(int level)
{
return -1UL << level_to_offset_bits(level);
}
static inline unsigned long level_size(int level)
{
return 1UL << level_to_offset_bits(level);
}
static inline unsigned long align_to_level(unsigned long pfn, int level)
{
return (pfn + level_size(level) - 1) & level_mask(level);
}
static inline unsigned long lvl_to_nr_pages(unsigned int lvl)
{
return 1 << min_t(int, (lvl - 1) * LEVEL_STRIDE, MAX_AGAW_PFN_WIDTH);
}
static inline unsigned long dma_to_mm_pfn(unsigned long dma_pfn)
{
return dma_pfn >> (PAGE_SHIFT - VTD_PAGE_SHIFT);
}
static inline unsigned long mm_to_dma_pfn(unsigned long mm_pfn)
{
return mm_pfn << (PAGE_SHIFT - VTD_PAGE_SHIFT);
}
static inline unsigned long page_to_dma_pfn(struct page *pg)
{
return mm_to_dma_pfn(page_to_pfn(pg));
}
static inline unsigned long virt_to_dma_pfn(void *p)
{
return page_to_dma_pfn(virt_to_page(p));
}
static inline bool root_present(struct root_entry *root)
{
return (root->val & 1);
}
static inline void set_root_present(struct root_entry *root)
{
root->val |= 1;
}
static inline void set_root_value(struct root_entry *root, unsigned long value)
{
root->val &= ~VTD_PAGE_MASK;
root->val |= value & VTD_PAGE_MASK;
}
static inline struct context_entry *
get_context_addr_from_root(struct root_entry *root)
{
return (struct context_entry *)
(root_present(root)?phys_to_virt(
root->val & VTD_PAGE_MASK) :
NULL);
}
static inline bool context_present(struct context_entry *context)
{
return (context->lo & 1);
}
static inline void context_set_present(struct context_entry *context)
{
context->lo |= 1;
}
static inline void context_set_fault_enable(struct context_entry *context)
{
context->lo &= (((u64)-1) << 2) | 1;
}
static inline void context_set_translation_type(struct context_entry *context,
unsigned long value)
{
context->lo &= (((u64)-1) << 4) | 3;
context->lo |= (value & 3) << 2;
}
static inline void context_set_address_root(struct context_entry *context,
unsigned long value)
{
context->lo &= ~VTD_PAGE_MASK;
context->lo |= value & VTD_PAGE_MASK;
}
static inline void context_set_address_width(struct context_entry *context,
unsigned long value)
{
context->hi |= value & 7;
}
static inline void context_set_domain_id(struct context_entry *context,
unsigned long value)
{
context->hi |= (value & ((1 << 16) - 1)) << 8;
}
static inline void context_clear_entry(struct context_entry *context)
{
context->lo = 0;
context->hi = 0;
}
static inline void dma_clear_pte(struct dma_pte *pte)
{
pte->val = 0;
}
static inline u64 dma_pte_addr(struct dma_pte *pte)
{
#ifdef CONFIG_64BIT
return pte->val & VTD_PAGE_MASK;
#else
return __cmpxchg64(&pte->val, 0ULL, 0ULL) & VTD_PAGE_MASK;
#endif
}
static inline bool dma_pte_present(struct dma_pte *pte)
{
return (pte->val & 3) != 0;
}
static inline bool dma_pte_superpage(struct dma_pte *pte)
{
return (pte->val & DMA_PTE_LARGE_PAGE);
}
static inline int first_pte_in_page(struct dma_pte *pte)
{
return !((unsigned long)pte & ~VTD_PAGE_MASK);
}
static int __init intel_iommu_setup(char *str)
{
if (!str)
return -EINVAL;
while (*str) {
if (!strncmp(str, "on", 2)) {
dmar_disabled = 0;
printk(KERN_INFO "Intel-IOMMU: enabled\n");
} else if (!strncmp(str, "off", 3)) {
dmar_disabled = 1;
printk(KERN_INFO "Intel-IOMMU: disabled\n");
} else if (!strncmp(str, "igfx_off", 8)) {
dmar_map_gfx = 0;
printk(KERN_INFO
"Intel-IOMMU: disable GFX device mapping\n");
} else if (!strncmp(str, "forcedac", 8)) {
printk(KERN_INFO
"Intel-IOMMU: Forcing DAC for PCI devices\n");
dmar_forcedac = 1;
} else if (!strncmp(str, "strict", 6)) {
printk(KERN_INFO
"Intel-IOMMU: disable batched IOTLB flush\n");
intel_iommu_strict = 1;
} else if (!strncmp(str, "sp_off", 6)) {
printk(KERN_INFO
"Intel-IOMMU: disable supported super page\n");
intel_iommu_superpage = 0;
}
str += strcspn(str, ",");
while (*str == ',')
str++;
}
return 0;
}
static inline void *alloc_pgtable_page(int node)
{
struct page *page;
void *vaddr = NULL;
page = alloc_pages_node(node, GFP_ATOMIC | __GFP_ZERO, 0);
if (page)
vaddr = page_address(page);
return vaddr;
}
static inline void free_pgtable_page(void *vaddr)
{
free_page((unsigned long)vaddr);
}
static inline void *alloc_domain_mem(void)
{
return kmem_cache_alloc(iommu_domain_cache, GFP_ATOMIC);
}
static void free_domain_mem(void *vaddr)
{
kmem_cache_free(iommu_domain_cache, vaddr);
}
static inline void * alloc_devinfo_mem(void)
{
return kmem_cache_alloc(iommu_devinfo_cache, GFP_ATOMIC);
}
static inline void free_devinfo_mem(void *vaddr)
{
kmem_cache_free(iommu_devinfo_cache, vaddr);
}
struct iova *alloc_iova_mem(void)
{
return kmem_cache_alloc(iommu_iova_cache, GFP_ATOMIC);
}
void free_iova_mem(struct iova *iova)
{
kmem_cache_free(iommu_iova_cache, iova);
}
static inline int domain_type_is_vm(struct dmar_domain *domain)
{
return domain->flags & DOMAIN_FLAG_VIRTUAL_MACHINE;
}
static inline int domain_type_is_vm_or_si(struct dmar_domain *domain)
{
return domain->flags & (DOMAIN_FLAG_VIRTUAL_MACHINE |
DOMAIN_FLAG_STATIC_IDENTITY);
}
static inline int domain_pfn_supported(struct dmar_domain *domain,
unsigned long pfn)
{
int addr_width = agaw_to_width(domain->agaw) - VTD_PAGE_SHIFT;
return !(addr_width < BITS_PER_LONG && pfn >> addr_width);
}
static int __iommu_calculate_agaw(struct intel_iommu *iommu, int max_gaw)
{
unsigned long sagaw;
int agaw = -1;
sagaw = cap_sagaw(iommu->cap);
for (agaw = width_to_agaw(max_gaw);
agaw >= 0; agaw--) {
if (test_bit(agaw, &sagaw))
break;
}
return agaw;
}
int iommu_calculate_max_sagaw(struct intel_iommu *iommu)
{
return __iommu_calculate_agaw(iommu, MAX_AGAW_WIDTH);
}
int iommu_calculate_agaw(struct intel_iommu *iommu)
{
return __iommu_calculate_agaw(iommu, DEFAULT_DOMAIN_ADDRESS_WIDTH);
}
static struct intel_iommu *domain_get_iommu(struct dmar_domain *domain)
{
int iommu_id;
BUG_ON(domain_type_is_vm_or_si(domain));
iommu_id = find_first_bit(domain->iommu_bmp, g_num_of_iommus);
if (iommu_id < 0 || iommu_id >= g_num_of_iommus)
return NULL;
return g_iommus[iommu_id];
}
static void domain_update_iommu_coherency(struct dmar_domain *domain)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
int i, found = 0;
domain->iommu_coherency = 1;
for_each_set_bit(i, domain->iommu_bmp, g_num_of_iommus) {
found = 1;
if (!ecap_coherent(g_iommus[i]->ecap)) {
domain->iommu_coherency = 0;
break;
}
}
if (found)
return;
rcu_read_lock();
for_each_active_iommu(iommu, drhd) {
if (!ecap_coherent(iommu->ecap)) {
domain->iommu_coherency = 0;
break;
}
}
rcu_read_unlock();
}
static int domain_update_iommu_snooping(struct intel_iommu *skip)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
int ret = 1;
rcu_read_lock();
for_each_active_iommu(iommu, drhd) {
if (iommu != skip) {
if (!ecap_sc_support(iommu->ecap)) {
ret = 0;
break;
}
}
}
rcu_read_unlock();
return ret;
}
static int domain_update_iommu_superpage(struct intel_iommu *skip)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
int mask = 0xf;
if (!intel_iommu_superpage) {
return 0;
}
rcu_read_lock();
for_each_active_iommu(iommu, drhd) {
if (iommu != skip) {
mask &= cap_super_page_val(iommu->cap);
if (!mask)
break;
}
}
rcu_read_unlock();
return fls(mask);
}
static void domain_update_iommu_cap(struct dmar_domain *domain)
{
domain_update_iommu_coherency(domain);
domain->iommu_snooping = domain_update_iommu_snooping(NULL);
domain->iommu_superpage = domain_update_iommu_superpage(NULL);
}
static struct intel_iommu *device_to_iommu(struct device *dev, u8 *bus, u8 *devfn)
{
struct dmar_drhd_unit *drhd = NULL;
struct intel_iommu *iommu;
struct device *tmp;
struct pci_dev *ptmp, *pdev = NULL;
u16 segment = 0;
int i;
if (dev_is_pci(dev)) {
pdev = to_pci_dev(dev);
segment = pci_domain_nr(pdev->bus);
} else if (ACPI_COMPANION(dev))
dev = &ACPI_COMPANION(dev)->dev;
rcu_read_lock();
for_each_active_iommu(iommu, drhd) {
if (pdev && segment != drhd->segment)
continue;
for_each_active_dev_scope(drhd->devices,
drhd->devices_cnt, i, tmp) {
if (tmp == dev) {
*bus = drhd->devices[i].bus;
*devfn = drhd->devices[i].devfn;
goto out;
}
if (!pdev || !dev_is_pci(tmp))
continue;
ptmp = to_pci_dev(tmp);
if (ptmp->subordinate &&
ptmp->subordinate->number <= pdev->bus->number &&
ptmp->subordinate->busn_res.end >= pdev->bus->number)
goto got_pdev;
}
if (pdev && drhd->include_all) {
got_pdev:
*bus = pdev->bus->number;
*devfn = pdev->devfn;
goto out;
}
}
iommu = NULL;
out:
rcu_read_unlock();
return iommu;
}
static void domain_flush_cache(struct dmar_domain *domain,
void *addr, int size)
{
if (!domain->iommu_coherency)
clflush_cache_range(addr, size);
}
static struct context_entry * device_to_context_entry(struct intel_iommu *iommu,
u8 bus, u8 devfn)
{
struct root_entry *root;
struct context_entry *context;
unsigned long phy_addr;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
root = &iommu->root_entry[bus];
context = get_context_addr_from_root(root);
if (!context) {
context = (struct context_entry *)
alloc_pgtable_page(iommu->node);
if (!context) {
spin_unlock_irqrestore(&iommu->lock, flags);
return NULL;
}
__iommu_flush_cache(iommu, (void *)context, CONTEXT_SIZE);
phy_addr = virt_to_phys((void *)context);
set_root_value(root, phy_addr);
set_root_present(root);
__iommu_flush_cache(iommu, root, sizeof(*root));
}
spin_unlock_irqrestore(&iommu->lock, flags);
return &context[devfn];
}
static int device_context_mapped(struct intel_iommu *iommu, u8 bus, u8 devfn)
{
struct root_entry *root;
struct context_entry *context;
int ret;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
root = &iommu->root_entry[bus];
context = get_context_addr_from_root(root);
if (!context) {
ret = 0;
goto out;
}
ret = context_present(&context[devfn]);
out:
spin_unlock_irqrestore(&iommu->lock, flags);
return ret;
}
static void clear_context_table(struct intel_iommu *iommu, u8 bus, u8 devfn)
{
struct root_entry *root;
struct context_entry *context;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
root = &iommu->root_entry[bus];
context = get_context_addr_from_root(root);
if (context) {
context_clear_entry(&context[devfn]);
__iommu_flush_cache(iommu, &context[devfn], \
sizeof(*context));
}
spin_unlock_irqrestore(&iommu->lock, flags);
}
static void free_context_table(struct intel_iommu *iommu)
{
struct root_entry *root;
int i;
unsigned long flags;
struct context_entry *context;
spin_lock_irqsave(&iommu->lock, flags);
if (!iommu->root_entry) {
goto out;
}
for (i = 0; i < ROOT_ENTRY_NR; i++) {
root = &iommu->root_entry[i];
context = get_context_addr_from_root(root);
if (context)
free_pgtable_page(context);
}
free_pgtable_page(iommu->root_entry);
iommu->root_entry = NULL;
out:
spin_unlock_irqrestore(&iommu->lock, flags);
}
static struct dma_pte *pfn_to_dma_pte(struct dmar_domain *domain,
unsigned long pfn, int *target_level)
{
struct dma_pte *parent, *pte = NULL;
int level = agaw_to_level(domain->agaw);
int offset;
BUG_ON(!domain->pgd);
if (!domain_pfn_supported(domain, pfn))
return NULL;
parent = domain->pgd;
while (1) {
void *tmp_page;
offset = pfn_level_offset(pfn, level);
pte = &parent[offset];
if (!*target_level && (dma_pte_superpage(pte) || !dma_pte_present(pte)))
break;
if (level == *target_level)
break;
if (!dma_pte_present(pte)) {
uint64_t pteval;
tmp_page = alloc_pgtable_page(domain->nid);
if (!tmp_page)
return NULL;
domain_flush_cache(domain, tmp_page, VTD_PAGE_SIZE);
pteval = ((uint64_t)virt_to_dma_pfn(tmp_page) << VTD_PAGE_SHIFT) | DMA_PTE_READ | DMA_PTE_WRITE;
if (cmpxchg64(&pte->val, 0ULL, pteval))
free_pgtable_page(tmp_page);
else
domain_flush_cache(domain, pte, sizeof(*pte));
}
if (level == 1)
break;
parent = phys_to_virt(dma_pte_addr(pte));
level--;
}
if (!*target_level)
*target_level = level;
return pte;
}
static struct dma_pte *dma_pfn_level_pte(struct dmar_domain *domain,
unsigned long pfn,
int level, int *large_page)
{
struct dma_pte *parent, *pte = NULL;
int total = agaw_to_level(domain->agaw);
int offset;
parent = domain->pgd;
while (level <= total) {
offset = pfn_level_offset(pfn, total);
pte = &parent[offset];
if (level == total)
return pte;
if (!dma_pte_present(pte)) {
*large_page = total;
break;
}
if (dma_pte_superpage(pte)) {
*large_page = total;
return pte;
}
parent = phys_to_virt(dma_pte_addr(pte));
total--;
}
return NULL;
}
static void dma_pte_clear_range(struct dmar_domain *domain,
unsigned long start_pfn,
unsigned long last_pfn)
{
unsigned int large_page = 1;
struct dma_pte *first_pte, *pte;
BUG_ON(!domain_pfn_supported(domain, start_pfn));
BUG_ON(!domain_pfn_supported(domain, last_pfn));
BUG_ON(start_pfn > last_pfn);
do {
large_page = 1;
first_pte = pte = dma_pfn_level_pte(domain, start_pfn, 1, &large_page);
if (!pte) {
start_pfn = align_to_level(start_pfn + 1, large_page + 1);
continue;
}
do {
dma_clear_pte(pte);
start_pfn += lvl_to_nr_pages(large_page);
pte++;
} while (start_pfn <= last_pfn && !first_pte_in_page(pte));
domain_flush_cache(domain, first_pte,
(void *)pte - (void *)first_pte);
} while (start_pfn && start_pfn <= last_pfn);
}
static void dma_pte_free_level(struct dmar_domain *domain, int level,
struct dma_pte *pte, unsigned long pfn,
unsigned long start_pfn, unsigned long last_pfn)
{
pfn = max(start_pfn, pfn);
pte = &pte[pfn_level_offset(pfn, level)];
do {
unsigned long level_pfn;
struct dma_pte *level_pte;
if (!dma_pte_present(pte) || dma_pte_superpage(pte))
goto next;
level_pfn = pfn & level_mask(level - 1);
level_pte = phys_to_virt(dma_pte_addr(pte));
if (level > 2)
dma_pte_free_level(domain, level - 1, level_pte,
level_pfn, start_pfn, last_pfn);
if (!(start_pfn > level_pfn ||
last_pfn < level_pfn + level_size(level) - 1)) {
dma_clear_pte(pte);
domain_flush_cache(domain, pte, sizeof(*pte));
free_pgtable_page(level_pte);
}
next:
pfn += level_size(level);
} while (!first_pte_in_page(++pte) && pfn <= last_pfn);
}
static void dma_pte_free_pagetable(struct dmar_domain *domain,
unsigned long start_pfn,
unsigned long last_pfn)
{
BUG_ON(!domain_pfn_supported(domain, start_pfn));
BUG_ON(!domain_pfn_supported(domain, last_pfn));
BUG_ON(start_pfn > last_pfn);
dma_pte_clear_range(domain, start_pfn, last_pfn);
dma_pte_free_level(domain, agaw_to_level(domain->agaw),
domain->pgd, 0, start_pfn, last_pfn);
if (start_pfn == 0 && last_pfn == DOMAIN_MAX_PFN(domain->gaw)) {
free_pgtable_page(domain->pgd);
domain->pgd = NULL;
}
}
static struct page *dma_pte_list_pagetables(struct dmar_domain *domain,
int level, struct dma_pte *pte,
struct page *freelist)
{
struct page *pg;
pg = pfn_to_page(dma_pte_addr(pte) >> PAGE_SHIFT);
pg->freelist = freelist;
freelist = pg;
if (level == 1)
return freelist;
pte = page_address(pg);
do {
if (dma_pte_present(pte) && !dma_pte_superpage(pte))
freelist = dma_pte_list_pagetables(domain, level - 1,
pte, freelist);
pte++;
} while (!first_pte_in_page(pte));
return freelist;
}
static struct page *dma_pte_clear_level(struct dmar_domain *domain, int level,
struct dma_pte *pte, unsigned long pfn,
unsigned long start_pfn,
unsigned long last_pfn,
struct page *freelist)
{
struct dma_pte *first_pte = NULL, *last_pte = NULL;
pfn = max(start_pfn, pfn);
pte = &pte[pfn_level_offset(pfn, level)];
do {
unsigned long level_pfn;
if (!dma_pte_present(pte))
goto next;
level_pfn = pfn & level_mask(level);
if (start_pfn <= level_pfn &&
last_pfn >= level_pfn + level_size(level) - 1) {
if (level > 1 && !dma_pte_superpage(pte))
freelist = dma_pte_list_pagetables(domain, level - 1, pte, freelist);
dma_clear_pte(pte);
if (!first_pte)
first_pte = pte;
last_pte = pte;
} else if (level > 1) {
freelist = dma_pte_clear_level(domain, level - 1,
phys_to_virt(dma_pte_addr(pte)),
level_pfn, start_pfn, last_pfn,
freelist);
}
next:
pfn += level_size(level);
} while (!first_pte_in_page(++pte) && pfn <= last_pfn);
if (first_pte)
domain_flush_cache(domain, first_pte,
(void *)++last_pte - (void *)first_pte);
return freelist;
}
struct page *domain_unmap(struct dmar_domain *domain,
unsigned long start_pfn,
unsigned long last_pfn)
{
struct page *freelist = NULL;
BUG_ON(!domain_pfn_supported(domain, start_pfn));
BUG_ON(!domain_pfn_supported(domain, last_pfn));
BUG_ON(start_pfn > last_pfn);
freelist = dma_pte_clear_level(domain, agaw_to_level(domain->agaw),
domain->pgd, 0, start_pfn, last_pfn, NULL);
if (start_pfn == 0 && last_pfn == DOMAIN_MAX_PFN(domain->gaw)) {
struct page *pgd_page = virt_to_page(domain->pgd);
pgd_page->freelist = freelist;
freelist = pgd_page;
domain->pgd = NULL;
}
return freelist;
}
void dma_free_pagelist(struct page *freelist)
{
struct page *pg;
while ((pg = freelist)) {
freelist = pg->freelist;
free_pgtable_page(page_address(pg));
}
}
static int iommu_alloc_root_entry(struct intel_iommu *iommu)
{
struct root_entry *root;
unsigned long flags;
root = (struct root_entry *)alloc_pgtable_page(iommu->node);
if (!root) {
pr_err("IOMMU: allocating root entry for %s failed\n",
iommu->name);
return -ENOMEM;
}
__iommu_flush_cache(iommu, root, ROOT_SIZE);
spin_lock_irqsave(&iommu->lock, flags);
iommu->root_entry = root;
spin_unlock_irqrestore(&iommu->lock, flags);
return 0;
}
static void iommu_set_root_entry(struct intel_iommu *iommu)
{
void *addr;
u32 sts;
unsigned long flag;
addr = iommu->root_entry;
raw_spin_lock_irqsave(&iommu->register_lock, flag);
dmar_writeq(iommu->reg + DMAR_RTADDR_REG, virt_to_phys(addr));
writel(iommu->gcmd | DMA_GCMD_SRTP, iommu->reg + DMAR_GCMD_REG);
IOMMU_WAIT_OP(iommu, DMAR_GSTS_REG,
readl, (sts & DMA_GSTS_RTPS), sts);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
}
static void iommu_flush_write_buffer(struct intel_iommu *iommu)
{
u32 val;
unsigned long flag;
if (!rwbf_quirk && !cap_rwbf(iommu->cap))
return;
raw_spin_lock_irqsave(&iommu->register_lock, flag);
writel(iommu->gcmd | DMA_GCMD_WBF, iommu->reg + DMAR_GCMD_REG);
IOMMU_WAIT_OP(iommu, DMAR_GSTS_REG,
readl, (!(val & DMA_GSTS_WBFS)), val);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
}
static void __iommu_flush_context(struct intel_iommu *iommu,
u16 did, u16 source_id, u8 function_mask,
u64 type)
{
u64 val = 0;
unsigned long flag;
switch (type) {
case DMA_CCMD_GLOBAL_INVL:
val = DMA_CCMD_GLOBAL_INVL;
break;
case DMA_CCMD_DOMAIN_INVL:
val = DMA_CCMD_DOMAIN_INVL|DMA_CCMD_DID(did);
break;
case DMA_CCMD_DEVICE_INVL:
val = DMA_CCMD_DEVICE_INVL|DMA_CCMD_DID(did)
| DMA_CCMD_SID(source_id) | DMA_CCMD_FM(function_mask);
break;
default:
BUG();
}
val |= DMA_CCMD_ICC;
raw_spin_lock_irqsave(&iommu->register_lock, flag);
dmar_writeq(iommu->reg + DMAR_CCMD_REG, val);
IOMMU_WAIT_OP(iommu, DMAR_CCMD_REG,
dmar_readq, (!(val & DMA_CCMD_ICC)), val);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
}
static void __iommu_flush_iotlb(struct intel_iommu *iommu, u16 did,
u64 addr, unsigned int size_order, u64 type)
{
int tlb_offset = ecap_iotlb_offset(iommu->ecap);
u64 val = 0, val_iva = 0;
unsigned long flag;
switch (type) {
case DMA_TLB_GLOBAL_FLUSH:
val = DMA_TLB_GLOBAL_FLUSH|DMA_TLB_IVT;
break;
case DMA_TLB_DSI_FLUSH:
val = DMA_TLB_DSI_FLUSH|DMA_TLB_IVT|DMA_TLB_DID(did);
break;
case DMA_TLB_PSI_FLUSH:
val = DMA_TLB_PSI_FLUSH|DMA_TLB_IVT|DMA_TLB_DID(did);
val_iva = size_order | addr;
break;
default:
BUG();
}
#if 0
if (cap_read_drain(iommu->cap))
val |= DMA_TLB_READ_DRAIN;
#endif
if (cap_write_drain(iommu->cap))
val |= DMA_TLB_WRITE_DRAIN;
raw_spin_lock_irqsave(&iommu->register_lock, flag);
if (val_iva)
dmar_writeq(iommu->reg + tlb_offset, val_iva);
dmar_writeq(iommu->reg + tlb_offset + 8, val);
IOMMU_WAIT_OP(iommu, tlb_offset + 8,
dmar_readq, (!(val & DMA_TLB_IVT)), val);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
if (DMA_TLB_IAIG(val) == 0)
printk(KERN_ERR"IOMMU: flush IOTLB failed\n");
if (DMA_TLB_IAIG(val) != DMA_TLB_IIRG(type))
pr_debug("IOMMU: tlb flush request %Lx, actual %Lx\n",
(unsigned long long)DMA_TLB_IIRG(type),
(unsigned long long)DMA_TLB_IAIG(val));
}
static struct device_domain_info *
iommu_support_dev_iotlb (struct dmar_domain *domain, struct intel_iommu *iommu,
u8 bus, u8 devfn)
{
int found = 0;
unsigned long flags;
struct device_domain_info *info;
struct pci_dev *pdev;
if (!ecap_dev_iotlb_support(iommu->ecap))
return NULL;
if (!iommu->qi)
return NULL;
spin_lock_irqsave(&device_domain_lock, flags);
list_for_each_entry(info, &domain->devices, link)
if (info->iommu == iommu && info->bus == bus &&
info->devfn == devfn) {
found = 1;
break;
}
spin_unlock_irqrestore(&device_domain_lock, flags);
if (!found || !info->dev || !dev_is_pci(info->dev))
return NULL;
pdev = to_pci_dev(info->dev);
if (!pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_ATS))
return NULL;
if (!dmar_find_matched_atsr_unit(pdev))
return NULL;
return info;
}
static void iommu_enable_dev_iotlb(struct device_domain_info *info)
{
if (!info || !dev_is_pci(info->dev))
return;
pci_enable_ats(to_pci_dev(info->dev), VTD_PAGE_SHIFT);
}
static void iommu_disable_dev_iotlb(struct device_domain_info *info)
{
if (!info->dev || !dev_is_pci(info->dev) ||
!pci_ats_enabled(to_pci_dev(info->dev)))
return;
pci_disable_ats(to_pci_dev(info->dev));
}
static void iommu_flush_dev_iotlb(struct dmar_domain *domain,
u64 addr, unsigned mask)
{
u16 sid, qdep;
unsigned long flags;
struct device_domain_info *info;
spin_lock_irqsave(&device_domain_lock, flags);
list_for_each_entry(info, &domain->devices, link) {
struct pci_dev *pdev;
if (!info->dev || !dev_is_pci(info->dev))
continue;
pdev = to_pci_dev(info->dev);
if (!pci_ats_enabled(pdev))
continue;
sid = info->bus << 8 | info->devfn;
qdep = pci_ats_queue_depth(pdev);
qi_flush_dev_iotlb(info->iommu, sid, qdep, addr, mask);
}
spin_unlock_irqrestore(&device_domain_lock, flags);
}
static void iommu_flush_iotlb_psi(struct intel_iommu *iommu, u16 did,
unsigned long pfn, unsigned int pages, int ih, int map)
{
unsigned int mask = ilog2(__roundup_pow_of_two(pages));
uint64_t addr = (uint64_t)pfn << VTD_PAGE_SHIFT;
BUG_ON(pages == 0);
if (ih)
ih = 1 << 6;
if (!cap_pgsel_inv(iommu->cap) || mask > cap_max_amask_val(iommu->cap))
iommu->flush.flush_iotlb(iommu, did, 0, 0,
DMA_TLB_DSI_FLUSH);
else
iommu->flush.flush_iotlb(iommu, did, addr | ih, mask,
DMA_TLB_PSI_FLUSH);
if (!cap_caching_mode(iommu->cap) || !map)
iommu_flush_dev_iotlb(iommu->domains[did], addr, mask);
}
static void iommu_disable_protect_mem_regions(struct intel_iommu *iommu)
{
u32 pmen;
unsigned long flags;
raw_spin_lock_irqsave(&iommu->register_lock, flags);
pmen = readl(iommu->reg + DMAR_PMEN_REG);
pmen &= ~DMA_PMEN_EPM;
writel(pmen, iommu->reg + DMAR_PMEN_REG);
IOMMU_WAIT_OP(iommu, DMAR_PMEN_REG,
readl, !(pmen & DMA_PMEN_PRS), pmen);
raw_spin_unlock_irqrestore(&iommu->register_lock, flags);
}
static void iommu_enable_translation(struct intel_iommu *iommu)
{
u32 sts;
unsigned long flags;
raw_spin_lock_irqsave(&iommu->register_lock, flags);
iommu->gcmd |= DMA_GCMD_TE;
writel(iommu->gcmd, iommu->reg + DMAR_GCMD_REG);
IOMMU_WAIT_OP(iommu, DMAR_GSTS_REG,
readl, (sts & DMA_GSTS_TES), sts);
raw_spin_unlock_irqrestore(&iommu->register_lock, flags);
}
static void iommu_disable_translation(struct intel_iommu *iommu)
{
u32 sts;
unsigned long flag;
raw_spin_lock_irqsave(&iommu->register_lock, flag);
iommu->gcmd &= ~DMA_GCMD_TE;
writel(iommu->gcmd, iommu->reg + DMAR_GCMD_REG);
IOMMU_WAIT_OP(iommu, DMAR_GSTS_REG,
readl, (!(sts & DMA_GSTS_TES)), sts);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
}
static int iommu_init_domains(struct intel_iommu *iommu)
{
unsigned long ndomains;
unsigned long nlongs;
ndomains = cap_ndoms(iommu->cap);
pr_debug("IOMMU%d: Number of Domains supported <%ld>\n",
iommu->seq_id, ndomains);
nlongs = BITS_TO_LONGS(ndomains);
spin_lock_init(&iommu->lock);
iommu->domain_ids = kcalloc(nlongs, sizeof(unsigned long), GFP_KERNEL);
if (!iommu->domain_ids) {
pr_err("IOMMU%d: allocating domain id array failed\n",
iommu->seq_id);
return -ENOMEM;
}
iommu->domains = kcalloc(ndomains, sizeof(struct dmar_domain *),
GFP_KERNEL);
if (!iommu->domains) {
pr_err("IOMMU%d: allocating domain array failed\n",
iommu->seq_id);
kfree(iommu->domain_ids);
iommu->domain_ids = NULL;
return -ENOMEM;
}
if (cap_caching_mode(iommu->cap))
set_bit(0, iommu->domain_ids);
return 0;
}
static void disable_dmar_iommu(struct intel_iommu *iommu)
{
struct dmar_domain *domain;
int i;
if ((iommu->domains) && (iommu->domain_ids)) {
for_each_set_bit(i, iommu->domain_ids, cap_ndoms(iommu->cap)) {
if (cap_caching_mode(iommu->cap) && i == 0)
continue;
domain = iommu->domains[i];
clear_bit(i, iommu->domain_ids);
if (domain_detach_iommu(domain, iommu) == 0 &&
!domain_type_is_vm(domain))
domain_exit(domain);
}
}
if (iommu->gcmd & DMA_GCMD_TE)
iommu_disable_translation(iommu);
}
static void free_dmar_iommu(struct intel_iommu *iommu)
{
if ((iommu->domains) && (iommu->domain_ids)) {
kfree(iommu->domains);
kfree(iommu->domain_ids);
iommu->domains = NULL;
iommu->domain_ids = NULL;
}
g_iommus[iommu->seq_id] = NULL;
free_context_table(iommu);
}
static struct dmar_domain *alloc_domain(int flags)
{
static atomic_t vm_domid = ATOMIC_INIT(0);
struct dmar_domain *domain;
domain = alloc_domain_mem();
if (!domain)
return NULL;
memset(domain, 0, sizeof(*domain));
domain->nid = -1;
domain->flags = flags;
spin_lock_init(&domain->iommu_lock);
INIT_LIST_HEAD(&domain->devices);
if (flags & DOMAIN_FLAG_VIRTUAL_MACHINE)
domain->id = atomic_inc_return(&vm_domid);
return domain;
}
static int __iommu_attach_domain(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
int num;
unsigned long ndomains;
ndomains = cap_ndoms(iommu->cap);
num = find_first_zero_bit(iommu->domain_ids, ndomains);
if (num < ndomains) {
set_bit(num, iommu->domain_ids);
iommu->domains[num] = domain;
} else {
num = -ENOSPC;
}
return num;
}
static int iommu_attach_domain(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
int num;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
num = __iommu_attach_domain(domain, iommu);
spin_unlock_irqrestore(&iommu->lock, flags);
if (num < 0)
pr_err("IOMMU: no free domain ids\n");
return num;
}
static int iommu_attach_vm_domain(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
int num;
unsigned long ndomains;
ndomains = cap_ndoms(iommu->cap);
for_each_set_bit(num, iommu->domain_ids, ndomains)
if (iommu->domains[num] == domain)
return num;
return __iommu_attach_domain(domain, iommu);
}
static void iommu_detach_domain(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
unsigned long flags;
int num, ndomains;
spin_lock_irqsave(&iommu->lock, flags);
if (domain_type_is_vm_or_si(domain)) {
ndomains = cap_ndoms(iommu->cap);
for_each_set_bit(num, iommu->domain_ids, ndomains) {
if (iommu->domains[num] == domain) {
clear_bit(num, iommu->domain_ids);
iommu->domains[num] = NULL;
break;
}
}
} else {
clear_bit(domain->id, iommu->domain_ids);
iommu->domains[domain->id] = NULL;
}
spin_unlock_irqrestore(&iommu->lock, flags);
}
static void domain_attach_iommu(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
unsigned long flags;
spin_lock_irqsave(&domain->iommu_lock, flags);
if (!test_and_set_bit(iommu->seq_id, domain->iommu_bmp)) {
domain->iommu_count++;
if (domain->iommu_count == 1)
domain->nid = iommu->node;
domain_update_iommu_cap(domain);
}
spin_unlock_irqrestore(&domain->iommu_lock, flags);
}
static int domain_detach_iommu(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
unsigned long flags;
int count = INT_MAX;
spin_lock_irqsave(&domain->iommu_lock, flags);
if (test_and_clear_bit(iommu->seq_id, domain->iommu_bmp)) {
count = --domain->iommu_count;
domain_update_iommu_cap(domain);
}
spin_unlock_irqrestore(&domain->iommu_lock, flags);
return count;
}
static int dmar_init_reserved_ranges(void)
{
struct pci_dev *pdev = NULL;
struct iova *iova;
int i;
init_iova_domain(&reserved_iova_list, DMA_32BIT_PFN);
lockdep_set_class(&reserved_iova_list.iova_rbtree_lock,
&reserved_rbtree_key);
iova = reserve_iova(&reserved_iova_list, IOVA_PFN(IOAPIC_RANGE_START),
IOVA_PFN(IOAPIC_RANGE_END));
if (!iova) {
printk(KERN_ERR "Reserve IOAPIC range failed\n");
return -ENODEV;
}
for_each_pci_dev(pdev) {
struct resource *r;
for (i = 0; i < PCI_NUM_RESOURCES; i++) {
r = &pdev->resource[i];
if (!r->flags || !(r->flags & IORESOURCE_MEM))
continue;
iova = reserve_iova(&reserved_iova_list,
IOVA_PFN(r->start),
IOVA_PFN(r->end));
if (!iova) {
printk(KERN_ERR "Reserve iova failed\n");
return -ENODEV;
}
}
}
return 0;
}
static void domain_reserve_special_ranges(struct dmar_domain *domain)
{
copy_reserved_iova(&reserved_iova_list, &domain->iovad);
}
static inline int guestwidth_to_adjustwidth(int gaw)
{
int agaw;
int r = (gaw - 12) % 9;
if (r == 0)
agaw = gaw;
else
agaw = gaw + 9 - r;
if (agaw > 64)
agaw = 64;
return agaw;
}
static int domain_init(struct dmar_domain *domain, int guest_width)
{
struct intel_iommu *iommu;
int adjust_width, agaw;
unsigned long sagaw;
init_iova_domain(&domain->iovad, DMA_32BIT_PFN);
domain_reserve_special_ranges(domain);
iommu = domain_get_iommu(domain);
if (guest_width > cap_mgaw(iommu->cap))
guest_width = cap_mgaw(iommu->cap);
domain->gaw = guest_width;
adjust_width = guestwidth_to_adjustwidth(guest_width);
agaw = width_to_agaw(adjust_width);
sagaw = cap_sagaw(iommu->cap);
if (!test_bit(agaw, &sagaw)) {
pr_debug("IOMMU: hardware doesn't support agaw %d\n", agaw);
agaw = find_next_bit(&sagaw, 5, agaw);
if (agaw >= 5)
return -ENODEV;
}
domain->agaw = agaw;
if (ecap_coherent(iommu->ecap))
domain->iommu_coherency = 1;
else
domain->iommu_coherency = 0;
if (ecap_sc_support(iommu->ecap))
domain->iommu_snooping = 1;
else
domain->iommu_snooping = 0;
if (intel_iommu_superpage)
domain->iommu_superpage = fls(cap_super_page_val(iommu->cap));
else
domain->iommu_superpage = 0;
domain->nid = iommu->node;
domain->pgd = (struct dma_pte *)alloc_pgtable_page(domain->nid);
if (!domain->pgd)
return -ENOMEM;
__iommu_flush_cache(iommu, domain->pgd, PAGE_SIZE);
return 0;
}
static void domain_exit(struct dmar_domain *domain)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
struct page *freelist = NULL;
if (!domain)
return;
if (!intel_iommu_strict)
flush_unmaps_timeout(0);
domain_remove_dev_info(domain);
put_iova_domain(&domain->iovad);
freelist = domain_unmap(domain, 0, DOMAIN_MAX_PFN(domain->gaw));
rcu_read_lock();
for_each_active_iommu(iommu, drhd)
iommu_detach_domain(domain, iommu);
rcu_read_unlock();
dma_free_pagelist(freelist);
free_domain_mem(domain);
}
static int domain_context_mapping_one(struct dmar_domain *domain,
struct intel_iommu *iommu,
u8 bus, u8 devfn, int translation)
{
struct context_entry *context;
unsigned long flags;
struct dma_pte *pgd;
int id;
int agaw;
struct device_domain_info *info = NULL;
pr_debug("Set context mapping for %02x:%02x.%d\n",
bus, PCI_SLOT(devfn), PCI_FUNC(devfn));
BUG_ON(!domain->pgd);
BUG_ON(translation != CONTEXT_TT_PASS_THROUGH &&
translation != CONTEXT_TT_MULTI_LEVEL);
context = device_to_context_entry(iommu, bus, devfn);
if (!context)
return -ENOMEM;
spin_lock_irqsave(&iommu->lock, flags);
if (context_present(context)) {
spin_unlock_irqrestore(&iommu->lock, flags);
return 0;
}
id = domain->id;
pgd = domain->pgd;
if (domain_type_is_vm_or_si(domain)) {
if (domain_type_is_vm(domain)) {
id = iommu_attach_vm_domain(domain, iommu);
if (id < 0) {
spin_unlock_irqrestore(&iommu->lock, flags);
pr_err("IOMMU: no free domain ids\n");
return -EFAULT;
}
}
if (translation != CONTEXT_TT_PASS_THROUGH) {
for (agaw = domain->agaw; agaw != iommu->agaw; agaw--) {
pgd = phys_to_virt(dma_pte_addr(pgd));
if (!dma_pte_present(pgd)) {
spin_unlock_irqrestore(&iommu->lock, flags);
return -ENOMEM;
}
}
}
}
context_set_domain_id(context, id);
if (translation != CONTEXT_TT_PASS_THROUGH) {
info = iommu_support_dev_iotlb(domain, iommu, bus, devfn);
translation = info ? CONTEXT_TT_DEV_IOTLB :
CONTEXT_TT_MULTI_LEVEL;
}
if (unlikely(translation == CONTEXT_TT_PASS_THROUGH))
context_set_address_width(context, iommu->msagaw);
else {
context_set_address_root(context, virt_to_phys(pgd));
context_set_address_width(context, iommu->agaw);
}
context_set_translation_type(context, translation);
context_set_fault_enable(context);
context_set_present(context);
domain_flush_cache(domain, context, sizeof(*context));
if (cap_caching_mode(iommu->cap)) {
iommu->flush.flush_context(iommu, 0,
(((u16)bus) << 8) | devfn,
DMA_CCMD_MASK_NOBIT,
DMA_CCMD_DEVICE_INVL);
iommu->flush.flush_iotlb(iommu, id, 0, 0, DMA_TLB_DSI_FLUSH);
} else {
iommu_flush_write_buffer(iommu);
}
iommu_enable_dev_iotlb(info);
spin_unlock_irqrestore(&iommu->lock, flags);
domain_attach_iommu(domain, iommu);
return 0;
}
static int domain_context_mapping_cb(struct pci_dev *pdev,
u16 alias, void *opaque)
{
struct domain_context_mapping_data *data = opaque;
return domain_context_mapping_one(data->domain, data->iommu,
PCI_BUS_NUM(alias), alias & 0xff,
data->translation);
}
static int
domain_context_mapping(struct dmar_domain *domain, struct device *dev,
int translation)
{
struct intel_iommu *iommu;
u8 bus, devfn;
struct domain_context_mapping_data data;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
if (!dev_is_pci(dev))
return domain_context_mapping_one(domain, iommu, bus, devfn,
translation);
data.domain = domain;
data.iommu = iommu;
data.translation = translation;
return pci_for_each_dma_alias(to_pci_dev(dev),
&domain_context_mapping_cb, &data);
}
static int domain_context_mapped_cb(struct pci_dev *pdev,
u16 alias, void *opaque)
{
struct intel_iommu *iommu = opaque;
return !device_context_mapped(iommu, PCI_BUS_NUM(alias), alias & 0xff);
}
static int domain_context_mapped(struct device *dev)
{
struct intel_iommu *iommu;
u8 bus, devfn;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
if (!dev_is_pci(dev))
return device_context_mapped(iommu, bus, devfn);
return !pci_for_each_dma_alias(to_pci_dev(dev),
domain_context_mapped_cb, iommu);
}
static inline unsigned long aligned_nrpages(unsigned long host_addr,
size_t size)
{
host_addr &= ~PAGE_MASK;
return PAGE_ALIGN(host_addr + size) >> VTD_PAGE_SHIFT;
}
static inline int hardware_largepage_caps(struct dmar_domain *domain,
unsigned long iov_pfn,
unsigned long phy_pfn,
unsigned long pages)
{
int support, level = 1;
unsigned long pfnmerge;
support = domain->iommu_superpage;
pfnmerge = iov_pfn | phy_pfn;
while (support && !(pfnmerge & ~VTD_STRIDE_MASK)) {
pages >>= VTD_STRIDE_SHIFT;
if (!pages)
break;
pfnmerge >>= VTD_STRIDE_SHIFT;
level++;
support--;
}
return level;
}
static int __domain_mapping(struct dmar_domain *domain, unsigned long iov_pfn,
struct scatterlist *sg, unsigned long phys_pfn,
unsigned long nr_pages, int prot)
{
struct dma_pte *first_pte = NULL, *pte = NULL;
phys_addr_t uninitialized_var(pteval);
unsigned long sg_res = 0;
unsigned int largepage_lvl = 0;
unsigned long lvl_pages = 0;
BUG_ON(!domain_pfn_supported(domain, iov_pfn + nr_pages - 1));
if ((prot & (DMA_PTE_READ|DMA_PTE_WRITE)) == 0)
return -EINVAL;
prot &= DMA_PTE_READ | DMA_PTE_WRITE | DMA_PTE_SNP;
if (!sg) {
sg_res = nr_pages;
pteval = ((phys_addr_t)phys_pfn << VTD_PAGE_SHIFT) | prot;
}
while (nr_pages > 0) {
uint64_t tmp;
if (!sg_res) {
sg_res = aligned_nrpages(sg->offset, sg->length);
sg->dma_address = ((dma_addr_t)iov_pfn << VTD_PAGE_SHIFT) + sg->offset;
sg->dma_length = sg->length;
pteval = page_to_phys(sg_page(sg)) | prot;
phys_pfn = pteval >> VTD_PAGE_SHIFT;
}
if (!pte) {
largepage_lvl = hardware_largepage_caps(domain, iov_pfn, phys_pfn, sg_res);
first_pte = pte = pfn_to_dma_pte(domain, iov_pfn, &largepage_lvl);
if (!pte)
return -ENOMEM;
if (largepage_lvl > 1) {
pteval |= DMA_PTE_LARGE_PAGE;
lvl_pages = lvl_to_nr_pages(largepage_lvl);
dma_pte_free_pagetable(domain, iov_pfn,
iov_pfn + lvl_pages - 1);
} else {
pteval &= ~(uint64_t)DMA_PTE_LARGE_PAGE;
}
}
tmp = cmpxchg64_local(&pte->val, 0ULL, pteval);
if (tmp) {
static int dumps = 5;
printk(KERN_CRIT "ERROR: DMA PTE for vPFN 0x%lx already set (to %llx not %llx)\n",
iov_pfn, tmp, (unsigned long long)pteval);
if (dumps) {
dumps--;
debug_dma_dump_mappings(NULL);
}
WARN_ON(1);
}
lvl_pages = lvl_to_nr_pages(largepage_lvl);
BUG_ON(nr_pages < lvl_pages);
BUG_ON(sg_res < lvl_pages);
nr_pages -= lvl_pages;
iov_pfn += lvl_pages;
phys_pfn += lvl_pages;
pteval += lvl_pages * VTD_PAGE_SIZE;
sg_res -= lvl_pages;
pte++;
if (!nr_pages || first_pte_in_page(pte) ||
(largepage_lvl > 1 && sg_res < lvl_pages)) {
domain_flush_cache(domain, first_pte,
(void *)pte - (void *)first_pte);
pte = NULL;
}
if (!sg_res && nr_pages)
sg = sg_next(sg);
}
return 0;
}
static inline int domain_sg_mapping(struct dmar_domain *domain, unsigned long iov_pfn,
struct scatterlist *sg, unsigned long nr_pages,
int prot)
{
return __domain_mapping(domain, iov_pfn, sg, 0, nr_pages, prot);
}
static inline int domain_pfn_mapping(struct dmar_domain *domain, unsigned long iov_pfn,
unsigned long phys_pfn, unsigned long nr_pages,
int prot)
{
return __domain_mapping(domain, iov_pfn, NULL, phys_pfn, nr_pages, prot);
}
static void iommu_detach_dev(struct intel_iommu *iommu, u8 bus, u8 devfn)
{
if (!iommu)
return;
clear_context_table(iommu, bus, devfn);
iommu->flush.flush_context(iommu, 0, 0, 0,
DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0, DMA_TLB_GLOBAL_FLUSH);
}
static inline void unlink_domain_info(struct device_domain_info *info)
{
assert_spin_locked(&device_domain_lock);
list_del(&info->link);
list_del(&info->global);
if (info->dev)
info->dev->archdata.iommu = NULL;
}
static void domain_remove_dev_info(struct dmar_domain *domain)
{
struct device_domain_info *info, *tmp;
unsigned long flags;
spin_lock_irqsave(&device_domain_lock, flags);
list_for_each_entry_safe(info, tmp, &domain->devices, link) {
unlink_domain_info(info);
spin_unlock_irqrestore(&device_domain_lock, flags);
iommu_disable_dev_iotlb(info);
iommu_detach_dev(info->iommu, info->bus, info->devfn);
if (domain_type_is_vm(domain)) {
iommu_detach_dependent_devices(info->iommu, info->dev);
domain_detach_iommu(domain, info->iommu);
}
free_devinfo_mem(info);
spin_lock_irqsave(&device_domain_lock, flags);
}
spin_unlock_irqrestore(&device_domain_lock, flags);
}
static struct dmar_domain *find_domain(struct device *dev)
{
struct device_domain_info *info;
info = dev->archdata.iommu;
if (info)
return info->domain;
return NULL;
}
static inline struct device_domain_info *
dmar_search_domain_by_dev_info(int segment, int bus, int devfn)
{
struct device_domain_info *info;
list_for_each_entry(info, &device_domain_list, global)
if (info->iommu->segment == segment && info->bus == bus &&
info->devfn == devfn)
return info;
return NULL;
}
static struct dmar_domain *dmar_insert_dev_info(struct intel_iommu *iommu,
int bus, int devfn,
struct device *dev,
struct dmar_domain *domain)
{
struct dmar_domain *found = NULL;
struct device_domain_info *info;
unsigned long flags;
info = alloc_devinfo_mem();
if (!info)
return NULL;
info->bus = bus;
info->devfn = devfn;
info->dev = dev;
info->domain = domain;
info->iommu = iommu;
spin_lock_irqsave(&device_domain_lock, flags);
if (dev)
found = find_domain(dev);
else {
struct device_domain_info *info2;
info2 = dmar_search_domain_by_dev_info(iommu->segment, bus, devfn);
if (info2)
found = info2->domain;
}
if (found) {
spin_unlock_irqrestore(&device_domain_lock, flags);
free_devinfo_mem(info);
return found;
}
list_add(&info->link, &domain->devices);
list_add(&info->global, &device_domain_list);
if (dev)
dev->archdata.iommu = info;
spin_unlock_irqrestore(&device_domain_lock, flags);
return domain;
}
static int get_last_alias(struct pci_dev *pdev, u16 alias, void *opaque)
{
*(u16 *)opaque = alias;
return 0;
}
static struct dmar_domain *get_domain_for_dev(struct device *dev, int gaw)
{
struct dmar_domain *domain, *tmp;
struct intel_iommu *iommu;
struct device_domain_info *info;
u16 dma_alias;
unsigned long flags;
u8 bus, devfn;
domain = find_domain(dev);
if (domain)
return domain;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return NULL;
if (dev_is_pci(dev)) {
struct pci_dev *pdev = to_pci_dev(dev);
pci_for_each_dma_alias(pdev, get_last_alias, &dma_alias);
spin_lock_irqsave(&device_domain_lock, flags);
info = dmar_search_domain_by_dev_info(pci_domain_nr(pdev->bus),
PCI_BUS_NUM(dma_alias),
dma_alias & 0xff);
if (info) {
iommu = info->iommu;
domain = info->domain;
}
spin_unlock_irqrestore(&device_domain_lock, flags);
if (info)
goto found_domain;
}
domain = alloc_domain(0);
if (!domain)
return NULL;
domain->id = iommu_attach_domain(domain, iommu);
if (domain->id < 0) {
free_domain_mem(domain);
return NULL;
}
domain_attach_iommu(domain, iommu);
if (domain_init(domain, gaw)) {
domain_exit(domain);
return NULL;
}
if (dev_is_pci(dev)) {
tmp = dmar_insert_dev_info(iommu, PCI_BUS_NUM(dma_alias),
dma_alias & 0xff, NULL, domain);
if (!tmp || tmp != domain) {
domain_exit(domain);
domain = tmp;
}
if (!domain)
return NULL;
}
found_domain:
tmp = dmar_insert_dev_info(iommu, bus, devfn, dev, domain);
if (!tmp || tmp != domain) {
domain_exit(domain);
domain = tmp;
}
return domain;
}
static int iommu_domain_identity_map(struct dmar_domain *domain,
unsigned long long start,
unsigned long long end)
{
unsigned long first_vpfn = start >> VTD_PAGE_SHIFT;
unsigned long last_vpfn = end >> VTD_PAGE_SHIFT;
if (!reserve_iova(&domain->iovad, dma_to_mm_pfn(first_vpfn),
dma_to_mm_pfn(last_vpfn))) {
printk(KERN_ERR "IOMMU: reserve iova failed\n");
return -ENOMEM;
}
pr_debug("Mapping reserved region %llx-%llx for domain %d\n",
start, end, domain->id);
dma_pte_clear_range(domain, first_vpfn, last_vpfn);
return domain_pfn_mapping(domain, first_vpfn, first_vpfn,
last_vpfn - first_vpfn + 1,
DMA_PTE_READ|DMA_PTE_WRITE);
}
static int iommu_prepare_identity_map(struct device *dev,
unsigned long long start,
unsigned long long end)
{
struct dmar_domain *domain;
int ret;
domain = get_domain_for_dev(dev, DEFAULT_DOMAIN_ADDRESS_WIDTH);
if (!domain)
return -ENOMEM;
if (domain == si_domain && hw_pass_through) {
printk("Ignoring identity map for HW passthrough device %s [0x%Lx - 0x%Lx]\n",
dev_name(dev), start, end);
return 0;
}
printk(KERN_INFO
"IOMMU: Setting identity map for device %s [0x%Lx - 0x%Lx]\n",
dev_name(dev), start, end);
if (end < start) {
WARN(1, "Your BIOS is broken; RMRR ends before it starts!\n"
"BIOS vendor: %s; Ver: %s; Product Version: %s\n",
dmi_get_system_info(DMI_BIOS_VENDOR),
dmi_get_system_info(DMI_BIOS_VERSION),
dmi_get_system_info(DMI_PRODUCT_VERSION));
ret = -EIO;
goto error;
}
if (end >> agaw_to_width(domain->agaw)) {
WARN(1, "Your BIOS is broken; RMRR exceeds permitted address width (%d bits)\n"
"BIOS vendor: %s; Ver: %s; Product Version: %s\n",
agaw_to_width(domain->agaw),
dmi_get_system_info(DMI_BIOS_VENDOR),
dmi_get_system_info(DMI_BIOS_VERSION),
dmi_get_system_info(DMI_PRODUCT_VERSION));
ret = -EIO;
goto error;
}
ret = iommu_domain_identity_map(domain, start, end);
if (ret)
goto error;
ret = domain_context_mapping(domain, dev, CONTEXT_TT_MULTI_LEVEL);
if (ret)
goto error;
return 0;
error:
domain_exit(domain);
return ret;
}
static inline int iommu_prepare_rmrr_dev(struct dmar_rmrr_unit *rmrr,
struct device *dev)
{
if (dev->archdata.iommu == DUMMY_DEVICE_DOMAIN_INFO)
return 0;
return iommu_prepare_identity_map(dev, rmrr->base_address,
rmrr->end_address);
}
static inline void iommu_prepare_isa(void)
{
struct pci_dev *pdev;
int ret;
pdev = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, NULL);
if (!pdev)
return;
printk(KERN_INFO "IOMMU: Prepare 0-16MiB unity mapping for LPC\n");
ret = iommu_prepare_identity_map(&pdev->dev, 0, 16*1024*1024 - 1);
if (ret)
printk(KERN_ERR "IOMMU: Failed to create 0-16MiB identity map; "
"floppy might not work\n");
pci_dev_put(pdev);
}
static inline void iommu_prepare_isa(void)
{
return;
}
static int __init si_domain_init(int hw)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
int nid, ret = 0;
bool first = true;
si_domain = alloc_domain(DOMAIN_FLAG_STATIC_IDENTITY);
if (!si_domain)
return -EFAULT;
for_each_active_iommu(iommu, drhd) {
ret = iommu_attach_domain(si_domain, iommu);
if (ret < 0) {
domain_exit(si_domain);
return -EFAULT;
} else if (first) {
si_domain->id = ret;
first = false;
} else if (si_domain->id != ret) {
domain_exit(si_domain);
return -EFAULT;
}
domain_attach_iommu(si_domain, iommu);
}
if (md_domain_init(si_domain, DEFAULT_DOMAIN_ADDRESS_WIDTH)) {
domain_exit(si_domain);
return -EFAULT;
}
pr_debug("IOMMU: identity mapping domain is domain %d\n",
si_domain->id);
if (hw)
return 0;
for_each_online_node(nid) {
unsigned long start_pfn, end_pfn;
int i;
for_each_mem_pfn_range(i, nid, &start_pfn, &end_pfn, NULL) {
ret = iommu_domain_identity_map(si_domain,
PFN_PHYS(start_pfn), PFN_PHYS(end_pfn));
if (ret)
return ret;
}
}
return 0;
}
static int identity_mapping(struct device *dev)
{
struct device_domain_info *info;
if (likely(!iommu_identity_mapping))
return 0;
info = dev->archdata.iommu;
if (info && info != DUMMY_DEVICE_DOMAIN_INFO)
return (info->domain == si_domain);
return 0;
}
static int domain_add_dev_info(struct dmar_domain *domain,
struct device *dev, int translation)
{
struct dmar_domain *ndomain;
struct intel_iommu *iommu;
u8 bus, devfn;
int ret;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
ndomain = dmar_insert_dev_info(iommu, bus, devfn, dev, domain);
if (ndomain != domain)
return -EBUSY;
ret = domain_context_mapping(domain, dev, translation);
if (ret) {
domain_remove_one_dev_info(domain, dev);
return ret;
}
return 0;
}
static bool device_has_rmrr(struct device *dev)
{
struct dmar_rmrr_unit *rmrr;
struct device *tmp;
int i;
rcu_read_lock();
for_each_rmrr_units(rmrr) {
for_each_active_dev_scope(rmrr->devices,
rmrr->devices_cnt, i, tmp)
if (tmp == dev) {
rcu_read_unlock();
return true;
}
}
rcu_read_unlock();
return false;
}
static bool device_is_rmrr_locked(struct device *dev)
{
if (!device_has_rmrr(dev))
return false;
if (dev_is_pci(dev)) {
struct pci_dev *pdev = to_pci_dev(dev);
if ((pdev->class >> 8) == PCI_CLASS_SERIAL_USB)
return false;
}
return true;
}
static int iommu_should_identity_map(struct device *dev, int startup)
{
if (dev_is_pci(dev)) {
struct pci_dev *pdev = to_pci_dev(dev);
if (device_is_rmrr_locked(dev))
return 0;
if ((iommu_identity_mapping & IDENTMAP_AZALIA) && IS_AZALIA(pdev))
return 1;
if ((iommu_identity_mapping & IDENTMAP_GFX) && IS_GFX_DEVICE(pdev))
return 1;
if (!(iommu_identity_mapping & IDENTMAP_ALL))
return 0;
if (!pci_is_pcie(pdev)) {
if (!pci_is_root_bus(pdev->bus))
return 0;
if (pdev->class >> 8 == PCI_CLASS_BRIDGE_PCI)
return 0;
} else if (pci_pcie_type(pdev) == PCI_EXP_TYPE_PCI_BRIDGE)
return 0;
} else {
if (device_has_rmrr(dev))
return 0;
}
if (!startup) {
u64 dma_mask = *dev->dma_mask;
if (dev->coherent_dma_mask &&
dev->coherent_dma_mask < dma_mask)
dma_mask = dev->coherent_dma_mask;
return dma_mask >= dma_get_required_mask(dev);
}
return 1;
}
static int __init dev_prepare_static_identity_mapping(struct device *dev, int hw)
{
int ret;
if (!iommu_should_identity_map(dev, 1))
return 0;
ret = domain_add_dev_info(si_domain, dev,
hw ? CONTEXT_TT_PASS_THROUGH :
CONTEXT_TT_MULTI_LEVEL);
if (!ret)
pr_info("IOMMU: %s identity mapping for device %s\n",
hw ? "hardware" : "software", dev_name(dev));
else if (ret == -ENODEV)
ret = 0;
return ret;
}
static int __init iommu_prepare_static_identity_mapping(int hw)
{
struct pci_dev *pdev = NULL;
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
struct device *dev;
int i;
int ret = 0;
ret = si_domain_init(hw);
if (ret)
return -EFAULT;
for_each_pci_dev(pdev) {
ret = dev_prepare_static_identity_mapping(&pdev->dev, hw);
if (ret)
return ret;
}
for_each_active_iommu(iommu, drhd)
for_each_active_dev_scope(drhd->devices, drhd->devices_cnt, i, dev) {
struct acpi_device_physical_node *pn;
struct acpi_device *adev;
if (dev->bus != &acpi_bus_type)
continue;
adev= to_acpi_device(dev);
mutex_lock(&adev->physical_node_lock);
list_for_each_entry(pn, &adev->physical_node_list, node) {
ret = dev_prepare_static_identity_mapping(pn->dev, hw);
if (ret)
break;
}
mutex_unlock(&adev->physical_node_lock);
if (ret)
return ret;
}
return 0;
}
static void intel_iommu_init_qi(struct intel_iommu *iommu)
{
if (!iommu->qi) {
dmar_fault(-1, iommu);
dmar_disable_qi(iommu);
}
if (dmar_enable_qi(iommu)) {
iommu->flush.flush_context = __iommu_flush_context;
iommu->flush.flush_iotlb = __iommu_flush_iotlb;
pr_info("IOMMU: %s using Register based invalidation\n",
iommu->name);
} else {
iommu->flush.flush_context = qi_flush_context;
iommu->flush.flush_iotlb = qi_flush_iotlb;
pr_info("IOMMU: %s using Queued invalidation\n", iommu->name);
}
}
static int __init init_dmars(void)
{
struct dmar_drhd_unit *drhd;
struct dmar_rmrr_unit *rmrr;
struct device *dev;
struct intel_iommu *iommu;
int i, ret;
for_each_drhd_unit(drhd) {
if (g_num_of_iommus < DMAR_UNITS_SUPPORTED) {
g_num_of_iommus++;
continue;
}
printk_once(KERN_ERR "intel-iommu: exceeded %d IOMMUs\n",
DMAR_UNITS_SUPPORTED);
}
if (g_num_of_iommus < DMAR_UNITS_SUPPORTED)
g_num_of_iommus = DMAR_UNITS_SUPPORTED;
g_iommus = kcalloc(g_num_of_iommus, sizeof(struct intel_iommu *),
GFP_KERNEL);
if (!g_iommus) {
printk(KERN_ERR "Allocating global iommu array failed\n");
ret = -ENOMEM;
goto error;
}
deferred_flush = kzalloc(g_num_of_iommus *
sizeof(struct deferred_flush_tables), GFP_KERNEL);
if (!deferred_flush) {
ret = -ENOMEM;
goto free_g_iommus;
}
for_each_active_iommu(iommu, drhd) {
g_iommus[iommu->seq_id] = iommu;
ret = iommu_init_domains(iommu);
if (ret)
goto free_iommu;
ret = iommu_alloc_root_entry(iommu);
if (ret)
goto free_iommu;
if (!ecap_pass_through(iommu->ecap))
hw_pass_through = 0;
}
for_each_active_iommu(iommu, drhd)
intel_iommu_init_qi(iommu);
if (iommu_pass_through)
iommu_identity_mapping |= IDENTMAP_ALL;
#ifdef CONFIG_INTEL_IOMMU_BROKEN_GFX_WA
iommu_identity_mapping |= IDENTMAP_GFX;
#endif
check_tylersburg_isoch();
if (iommu_identity_mapping) {
ret = iommu_prepare_static_identity_mapping(hw_pass_through);
if (ret) {
printk(KERN_CRIT "Failed to setup IOMMU pass-through\n");
goto free_iommu;
}
}
printk(KERN_INFO "IOMMU: Setting RMRR:\n");
for_each_rmrr_units(rmrr) {
for_each_active_dev_scope(rmrr->devices, rmrr->devices_cnt,
i, dev) {
ret = iommu_prepare_rmrr_dev(rmrr, dev);
if (ret)
printk(KERN_ERR
"IOMMU: mapping reserved region failed\n");
}
}
iommu_prepare_isa();
for_each_iommu(iommu, drhd) {
if (drhd->ignored) {
if (force_on)
iommu_disable_protect_mem_regions(iommu);
continue;
}
iommu_flush_write_buffer(iommu);
ret = dmar_set_interrupt(iommu);
if (ret)
goto free_iommu;
iommu_set_root_entry(iommu);
iommu->flush.flush_context(iommu, 0, 0, 0, DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0, DMA_TLB_GLOBAL_FLUSH);
iommu_enable_translation(iommu);
iommu_disable_protect_mem_regions(iommu);
}
return 0;
free_iommu:
for_each_active_iommu(iommu, drhd) {
disable_dmar_iommu(iommu);
free_dmar_iommu(iommu);
}
kfree(deferred_flush);
free_g_iommus:
kfree(g_iommus);
error:
return ret;
}
static struct iova *intel_alloc_iova(struct device *dev,
struct dmar_domain *domain,
unsigned long nrpages, uint64_t dma_mask)
{
struct iova *iova = NULL;
dma_mask = min_t(uint64_t, DOMAIN_MAX_ADDR(domain->gaw), dma_mask);
if (!dmar_forcedac && dma_mask > DMA_BIT_MASK(32)) {
iova = alloc_iova(&domain->iovad, nrpages,
IOVA_PFN(DMA_BIT_MASK(32)), 1);
if (iova)
return iova;
}
iova = alloc_iova(&domain->iovad, nrpages, IOVA_PFN(dma_mask), 1);
if (unlikely(!iova)) {
printk(KERN_ERR "Allocating %ld-page iova for %s failed",
nrpages, dev_name(dev));
return NULL;
}
return iova;
}
static struct dmar_domain *__get_valid_domain_for_dev(struct device *dev)
{
struct dmar_domain *domain;
int ret;
domain = get_domain_for_dev(dev, DEFAULT_DOMAIN_ADDRESS_WIDTH);
if (!domain) {
printk(KERN_ERR "Allocating domain for %s failed",
dev_name(dev));
return NULL;
}
if (unlikely(!domain_context_mapped(dev))) {
ret = domain_context_mapping(domain, dev, CONTEXT_TT_MULTI_LEVEL);
if (ret) {
printk(KERN_ERR "Domain context map for %s failed",
dev_name(dev));
return NULL;
}
}
return domain;
}
static inline struct dmar_domain *get_valid_domain_for_dev(struct device *dev)
{
struct device_domain_info *info;
info = dev->archdata.iommu;
if (likely(info))
return info->domain;
return __get_valid_domain_for_dev(dev);
}
static int iommu_dummy(struct device *dev)
{
return dev->archdata.iommu == DUMMY_DEVICE_DOMAIN_INFO;
}
static int iommu_no_mapping(struct device *dev)
{
int found;
if (iommu_dummy(dev))
return 1;
if (!iommu_identity_mapping)
return 0;
found = identity_mapping(dev);
if (found) {
if (iommu_should_identity_map(dev, 0))
return 1;
else {
domain_remove_one_dev_info(si_domain, dev);
printk(KERN_INFO "32bit %s uses non-identity mapping\n",
dev_name(dev));
return 0;
}
} else {
if (iommu_should_identity_map(dev, 0)) {
int ret;
ret = domain_add_dev_info(si_domain, dev,
hw_pass_through ?
CONTEXT_TT_PASS_THROUGH :
CONTEXT_TT_MULTI_LEVEL);
if (!ret) {
printk(KERN_INFO "64bit %s uses identity mapping\n",
dev_name(dev));
return 1;
}
}
}
return 0;
}
static dma_addr_t __intel_map_single(struct device *dev, phys_addr_t paddr,
size_t size, int dir, u64 dma_mask)
{
struct dmar_domain *domain;
phys_addr_t start_paddr;
struct iova *iova;
int prot = 0;
int ret;
struct intel_iommu *iommu;
unsigned long paddr_pfn = paddr >> PAGE_SHIFT;
BUG_ON(dir == DMA_NONE);
if (iommu_no_mapping(dev))
return paddr;
domain = get_valid_domain_for_dev(dev);
if (!domain)
return 0;
iommu = domain_get_iommu(domain);
size = aligned_nrpages(paddr, size);
iova = intel_alloc_iova(dev, domain, dma_to_mm_pfn(size), dma_mask);
if (!iova)
goto error;
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL || \
!cap_zlr(iommu->cap))
prot |= DMA_PTE_READ;
if (dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL)
prot |= DMA_PTE_WRITE;
ret = domain_pfn_mapping(domain, mm_to_dma_pfn(iova->pfn_lo),
mm_to_dma_pfn(paddr_pfn), size, prot);
if (ret)
goto error;
if (cap_caching_mode(iommu->cap))
iommu_flush_iotlb_psi(iommu, domain->id, mm_to_dma_pfn(iova->pfn_lo), size, 0, 1);
else
iommu_flush_write_buffer(iommu);
start_paddr = (phys_addr_t)iova->pfn_lo << PAGE_SHIFT;
start_paddr += paddr & ~PAGE_MASK;
return start_paddr;
error:
if (iova)
__free_iova(&domain->iovad, iova);
printk(KERN_ERR"Device %s request: %zx@%llx dir %d --- failed\n",
dev_name(dev), size, (unsigned long long)paddr, dir);
return 0;
}
static dma_addr_t intel_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
return __intel_map_single(dev, page_to_phys(page) + offset, size,
dir, *dev->dma_mask);
}
static void flush_unmaps(void)
{
int i, j;
timer_on = 0;
for (i = 0; i < g_num_of_iommus; i++) {
struct intel_iommu *iommu = g_iommus[i];
if (!iommu)
continue;
if (!deferred_flush[i].next)
continue;
if (!cap_caching_mode(iommu->cap))
iommu->flush.flush_iotlb(iommu, 0, 0, 0,
DMA_TLB_GLOBAL_FLUSH);
for (j = 0; j < deferred_flush[i].next; j++) {
unsigned long mask;
struct iova *iova = deferred_flush[i].iova[j];
struct dmar_domain *domain = deferred_flush[i].domain[j];
if (cap_caching_mode(iommu->cap))
iommu_flush_iotlb_psi(iommu, domain->id,
iova->pfn_lo, iova_size(iova),
!deferred_flush[i].freelist[j], 0);
else {
mask = ilog2(mm_to_dma_pfn(iova_size(iova)));
iommu_flush_dev_iotlb(deferred_flush[i].domain[j],
(uint64_t)iova->pfn_lo << PAGE_SHIFT, mask);
}
__free_iova(&deferred_flush[i].domain[j]->iovad, iova);
if (deferred_flush[i].freelist[j])
dma_free_pagelist(deferred_flush[i].freelist[j]);
}
deferred_flush[i].next = 0;
}
list_size = 0;
}
static void flush_unmaps_timeout(unsigned long data)
{
unsigned long flags;
spin_lock_irqsave(&async_umap_flush_lock, flags);
flush_unmaps();
spin_unlock_irqrestore(&async_umap_flush_lock, flags);
}
static void add_unmap(struct dmar_domain *dom, struct iova *iova, struct page *freelist)
{
unsigned long flags;
int next, iommu_id;
struct intel_iommu *iommu;
spin_lock_irqsave(&async_umap_flush_lock, flags);
if (list_size == HIGH_WATER_MARK)
flush_unmaps();
iommu = domain_get_iommu(dom);
iommu_id = iommu->seq_id;
next = deferred_flush[iommu_id].next;
deferred_flush[iommu_id].domain[next] = dom;
deferred_flush[iommu_id].iova[next] = iova;
deferred_flush[iommu_id].freelist[next] = freelist;
deferred_flush[iommu_id].next++;
if (!timer_on) {
mod_timer(&unmap_timer, jiffies + msecs_to_jiffies(10));
timer_on = 1;
}
list_size++;
spin_unlock_irqrestore(&async_umap_flush_lock, flags);
}
static void intel_unmap(struct device *dev, dma_addr_t dev_addr)
{
struct dmar_domain *domain;
unsigned long start_pfn, last_pfn;
struct iova *iova;
struct intel_iommu *iommu;
struct page *freelist;
if (iommu_no_mapping(dev))
return;
domain = find_domain(dev);
BUG_ON(!domain);
iommu = domain_get_iommu(domain);
iova = find_iova(&domain->iovad, IOVA_PFN(dev_addr));
if (WARN_ONCE(!iova, "Driver unmaps unmatched page at PFN %llx\n",
(unsigned long long)dev_addr))
return;
start_pfn = mm_to_dma_pfn(iova->pfn_lo);
last_pfn = mm_to_dma_pfn(iova->pfn_hi + 1) - 1;
pr_debug("Device %s unmapping: pfn %lx-%lx\n",
dev_name(dev), start_pfn, last_pfn);
freelist = domain_unmap(domain, start_pfn, last_pfn);
if (intel_iommu_strict) {
iommu_flush_iotlb_psi(iommu, domain->id, start_pfn,
last_pfn - start_pfn + 1, !freelist, 0);
__free_iova(&domain->iovad, iova);
dma_free_pagelist(freelist);
} else {
add_unmap(domain, iova, freelist);
}
}
static void intel_unmap_page(struct device *dev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
intel_unmap(dev, dev_addr);
}
static void *intel_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
struct page *page = NULL;
int order;
size = PAGE_ALIGN(size);
order = get_order(size);
if (!iommu_no_mapping(dev))
flags &= ~(GFP_DMA | GFP_DMA32);
else if (dev->coherent_dma_mask < dma_get_required_mask(dev)) {
if (dev->coherent_dma_mask < DMA_BIT_MASK(32))
flags |= GFP_DMA;
else
flags |= GFP_DMA32;
}
if (flags & __GFP_WAIT) {
unsigned int count = size >> PAGE_SHIFT;
page = dma_alloc_from_contiguous(dev, count, order);
if (page && iommu_no_mapping(dev) &&
page_to_phys(page) + size > dev->coherent_dma_mask) {
dma_release_from_contiguous(dev, page, count);
page = NULL;
}
}
if (!page)
page = alloc_pages(flags, order);
if (!page)
return NULL;
memset(page_address(page), 0, size);
*dma_handle = __intel_map_single(dev, page_to_phys(page), size,
DMA_BIDIRECTIONAL,
dev->coherent_dma_mask);
if (*dma_handle)
return page_address(page);
if (!dma_release_from_contiguous(dev, page, size >> PAGE_SHIFT))
__free_pages(page, order);
return NULL;
}
static void intel_free_coherent(struct device *dev, size_t size, void *vaddr,
dma_addr_t dma_handle, struct dma_attrs *attrs)
{
int order;
struct page *page = virt_to_page(vaddr);
size = PAGE_ALIGN(size);
order = get_order(size);
intel_unmap(dev, dma_handle);
if (!dma_release_from_contiguous(dev, page, size >> PAGE_SHIFT))
__free_pages(page, order);
}
static void intel_unmap_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
intel_unmap(dev, sglist[0].dma_address);
}
static int intel_nontranslate_map_sg(struct device *hddev,
struct scatterlist *sglist, int nelems, int dir)
{
int i;
struct scatterlist *sg;
for_each_sg(sglist, sg, nelems, i) {
BUG_ON(!sg_page(sg));
sg->dma_address = page_to_phys(sg_page(sg)) + sg->offset;
sg->dma_length = sg->length;
}
return nelems;
}
static int intel_map_sg(struct device *dev, struct scatterlist *sglist, int nelems,
enum dma_data_direction dir, struct dma_attrs *attrs)
{
int i;
struct dmar_domain *domain;
size_t size = 0;
int prot = 0;
struct iova *iova = NULL;
int ret;
struct scatterlist *sg;
unsigned long start_vpfn;
struct intel_iommu *iommu;
BUG_ON(dir == DMA_NONE);
if (iommu_no_mapping(dev))
return intel_nontranslate_map_sg(dev, sglist, nelems, dir);
domain = get_valid_domain_for_dev(dev);
if (!domain)
return 0;
iommu = domain_get_iommu(domain);
for_each_sg(sglist, sg, nelems, i)
size += aligned_nrpages(sg->offset, sg->length);
iova = intel_alloc_iova(dev, domain, dma_to_mm_pfn(size),
*dev->dma_mask);
if (!iova) {
sglist->dma_length = 0;
return 0;
}
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL || \
!cap_zlr(iommu->cap))
prot |= DMA_PTE_READ;
if (dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL)
prot |= DMA_PTE_WRITE;
start_vpfn = mm_to_dma_pfn(iova->pfn_lo);
ret = domain_sg_mapping(domain, start_vpfn, sglist, size, prot);
if (unlikely(ret)) {
dma_pte_free_pagetable(domain, start_vpfn,
start_vpfn + size - 1);
__free_iova(&domain->iovad, iova);
return 0;
}
if (cap_caching_mode(iommu->cap))
iommu_flush_iotlb_psi(iommu, domain->id, start_vpfn, size, 0, 1);
else
iommu_flush_write_buffer(iommu);
return nelems;
}
static int intel_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return !dma_addr;
}
static inline int iommu_domain_cache_init(void)
{
int ret = 0;
iommu_domain_cache = kmem_cache_create("iommu_domain",
sizeof(struct dmar_domain),
0,
SLAB_HWCACHE_ALIGN,
NULL);
if (!iommu_domain_cache) {
printk(KERN_ERR "Couldn't create iommu_domain cache\n");
ret = -ENOMEM;
}
return ret;
}
static inline int iommu_devinfo_cache_init(void)
{
int ret = 0;
iommu_devinfo_cache = kmem_cache_create("iommu_devinfo",
sizeof(struct device_domain_info),
0,
SLAB_HWCACHE_ALIGN,
NULL);
if (!iommu_devinfo_cache) {
printk(KERN_ERR "Couldn't create devinfo cache\n");
ret = -ENOMEM;
}
return ret;
}
static inline int iommu_iova_cache_init(void)
{
int ret = 0;
iommu_iova_cache = kmem_cache_create("iommu_iova",
sizeof(struct iova),
0,
SLAB_HWCACHE_ALIGN,
NULL);
if (!iommu_iova_cache) {
printk(KERN_ERR "Couldn't create iova cache\n");
ret = -ENOMEM;
}
return ret;
}
static int __init iommu_init_mempool(void)
{
int ret;
ret = iommu_iova_cache_init();
if (ret)
return ret;
ret = iommu_domain_cache_init();
if (ret)
goto domain_error;
ret = iommu_devinfo_cache_init();
if (!ret)
return ret;
kmem_cache_destroy(iommu_domain_cache);
domain_error:
kmem_cache_destroy(iommu_iova_cache);
return -ENOMEM;
}
static void __init iommu_exit_mempool(void)
{
kmem_cache_destroy(iommu_devinfo_cache);
kmem_cache_destroy(iommu_domain_cache);
kmem_cache_destroy(iommu_iova_cache);
}
static void quirk_ioat_snb_local_iommu(struct pci_dev *pdev)
{
struct dmar_drhd_unit *drhd;
u32 vtbar;
int rc;
rc = pci_bus_read_config_dword(pdev->bus, PCI_DEVFN(0, 0), 0xb0, &vtbar);
if (rc) {
dev_info(&pdev->dev, "failed to run vt-d quirk\n");
return;
}
vtbar &= 0xffff0000;
drhd = dmar_find_matched_drhd_unit(pdev);
if (WARN_TAINT_ONCE(!drhd || drhd->reg_base_addr - vtbar != 0xa000,
TAINT_FIRMWARE_WORKAROUND,
"BIOS assigned incorrect VT-d unit for Intel(R) QuickData Technology device\n"))
pdev->dev.archdata.iommu = DUMMY_DEVICE_DOMAIN_INFO;
}
static void __init init_no_remapping_devices(void)
{
struct dmar_drhd_unit *drhd;
struct device *dev;
int i;
for_each_drhd_unit(drhd) {
if (!drhd->include_all) {
for_each_active_dev_scope(drhd->devices,
drhd->devices_cnt, i, dev)
break;
if (i == drhd->devices_cnt)
drhd->ignored = 1;
}
}
for_each_active_drhd_unit(drhd) {
if (drhd->include_all)
continue;
for_each_active_dev_scope(drhd->devices,
drhd->devices_cnt, i, dev)
if (!dev_is_pci(dev) || !IS_GFX_DEVICE(to_pci_dev(dev)))
break;
if (i < drhd->devices_cnt)
continue;
if (dmar_map_gfx) {
intel_iommu_gfx_mapped = 1;
} else {
drhd->ignored = 1;
for_each_active_dev_scope(drhd->devices,
drhd->devices_cnt, i, dev)
dev->archdata.iommu = DUMMY_DEVICE_DOMAIN_INFO;
}
}
}
static int init_iommu_hw(void)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu = NULL;
for_each_active_iommu(iommu, drhd)
if (iommu->qi)
dmar_reenable_qi(iommu);
for_each_iommu(iommu, drhd) {
if (drhd->ignored) {
if (force_on)
iommu_disable_protect_mem_regions(iommu);
continue;
}
iommu_flush_write_buffer(iommu);
iommu_set_root_entry(iommu);
iommu->flush.flush_context(iommu, 0, 0, 0,
DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0, DMA_TLB_GLOBAL_FLUSH);
iommu_enable_translation(iommu);
iommu_disable_protect_mem_regions(iommu);
}
return 0;
}
static void iommu_flush_all(void)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
for_each_active_iommu(iommu, drhd) {
iommu->flush.flush_context(iommu, 0, 0, 0,
DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0,
DMA_TLB_GLOBAL_FLUSH);
}
}
static int iommu_suspend(void)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu = NULL;
unsigned long flag;
for_each_active_iommu(iommu, drhd) {
iommu->iommu_state = kzalloc(sizeof(u32) * MAX_SR_DMAR_REGS,
GFP_ATOMIC);
if (!iommu->iommu_state)
goto nomem;
}
iommu_flush_all();
for_each_active_iommu(iommu, drhd) {
iommu_disable_translation(iommu);
raw_spin_lock_irqsave(&iommu->register_lock, flag);
iommu->iommu_state[SR_DMAR_FECTL_REG] =
readl(iommu->reg + DMAR_FECTL_REG);
iommu->iommu_state[SR_DMAR_FEDATA_REG] =
readl(iommu->reg + DMAR_FEDATA_REG);
iommu->iommu_state[SR_DMAR_FEADDR_REG] =
readl(iommu->reg + DMAR_FEADDR_REG);
iommu->iommu_state[SR_DMAR_FEUADDR_REG] =
readl(iommu->reg + DMAR_FEUADDR_REG);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
}
return 0;
nomem:
for_each_active_iommu(iommu, drhd)
kfree(iommu->iommu_state);
return -ENOMEM;
}
static void iommu_resume(void)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu = NULL;
unsigned long flag;
if (init_iommu_hw()) {
if (force_on)
panic("tboot: IOMMU setup failed, DMAR can not resume!\n");
else
WARN(1, "IOMMU setup failed, DMAR can not resume!\n");
return;
}
for_each_active_iommu(iommu, drhd) {
raw_spin_lock_irqsave(&iommu->register_lock, flag);
writel(iommu->iommu_state[SR_DMAR_FECTL_REG],
iommu->reg + DMAR_FECTL_REG);
writel(iommu->iommu_state[SR_DMAR_FEDATA_REG],
iommu->reg + DMAR_FEDATA_REG);
writel(iommu->iommu_state[SR_DMAR_FEADDR_REG],
iommu->reg + DMAR_FEADDR_REG);
writel(iommu->iommu_state[SR_DMAR_FEUADDR_REG],
iommu->reg + DMAR_FEUADDR_REG);
raw_spin_unlock_irqrestore(&iommu->register_lock, flag);
}
for_each_active_iommu(iommu, drhd)
kfree(iommu->iommu_state);
}
static void __init init_iommu_pm_ops(void)
{
register_syscore_ops(&iommu_syscore_ops);
}
static inline void init_iommu_pm_ops(void) {}
int __init dmar_parse_one_rmrr(struct acpi_dmar_header *header, void *arg)
{
struct acpi_dmar_reserved_memory *rmrr;
struct dmar_rmrr_unit *rmrru;
rmrru = kzalloc(sizeof(*rmrru), GFP_KERNEL);
if (!rmrru)
return -ENOMEM;
rmrru->hdr = header;
rmrr = (struct acpi_dmar_reserved_memory *)header;
rmrru->base_address = rmrr->base_address;
rmrru->end_address = rmrr->end_address;
rmrru->devices = dmar_alloc_dev_scope((void *)(rmrr + 1),
((void *)rmrr) + rmrr->header.length,
&rmrru->devices_cnt);
if (rmrru->devices_cnt && rmrru->devices == NULL) {
kfree(rmrru);
return -ENOMEM;
}
list_add(&rmrru->list, &dmar_rmrr_units);
return 0;
}
static struct dmar_atsr_unit *dmar_find_atsr(struct acpi_dmar_atsr *atsr)
{
struct dmar_atsr_unit *atsru;
struct acpi_dmar_atsr *tmp;
list_for_each_entry_rcu(atsru, &dmar_atsr_units, list) {
tmp = (struct acpi_dmar_atsr *)atsru->hdr;
if (atsr->segment != tmp->segment)
continue;
if (atsr->header.length != tmp->header.length)
continue;
if (memcmp(atsr, tmp, atsr->header.length) == 0)
return atsru;
}
return NULL;
}
int dmar_parse_one_atsr(struct acpi_dmar_header *hdr, void *arg)
{
struct acpi_dmar_atsr *atsr;
struct dmar_atsr_unit *atsru;
if (system_state != SYSTEM_BOOTING && !intel_iommu_enabled)
return 0;
atsr = container_of(hdr, struct acpi_dmar_atsr, header);
atsru = dmar_find_atsr(atsr);
if (atsru)
return 0;
atsru = kzalloc(sizeof(*atsru) + hdr->length, GFP_KERNEL);
if (!atsru)
return -ENOMEM;
atsru->hdr = (void *)(atsru + 1);
memcpy(atsru->hdr, hdr, hdr->length);
atsru->include_all = atsr->flags & 0x1;
if (!atsru->include_all) {
atsru->devices = dmar_alloc_dev_scope((void *)(atsr + 1),
(void *)atsr + atsr->header.length,
&atsru->devices_cnt);
if (atsru->devices_cnt && atsru->devices == NULL) {
kfree(atsru);
return -ENOMEM;
}
}
list_add_rcu(&atsru->list, &dmar_atsr_units);
return 0;
}
static void intel_iommu_free_atsr(struct dmar_atsr_unit *atsru)
{
dmar_free_dev_scope(&atsru->devices, &atsru->devices_cnt);
kfree(atsru);
}
int dmar_release_one_atsr(struct acpi_dmar_header *hdr, void *arg)
{
struct acpi_dmar_atsr *atsr;
struct dmar_atsr_unit *atsru;
atsr = container_of(hdr, struct acpi_dmar_atsr, header);
atsru = dmar_find_atsr(atsr);
if (atsru) {
list_del_rcu(&atsru->list);
synchronize_rcu();
intel_iommu_free_atsr(atsru);
}
return 0;
}
int dmar_check_one_atsr(struct acpi_dmar_header *hdr, void *arg)
{
int i;
struct device *dev;
struct acpi_dmar_atsr *atsr;
struct dmar_atsr_unit *atsru;
atsr = container_of(hdr, struct acpi_dmar_atsr, header);
atsru = dmar_find_atsr(atsr);
if (!atsru)
return 0;
if (!atsru->include_all && atsru->devices && atsru->devices_cnt)
for_each_active_dev_scope(atsru->devices, atsru->devices_cnt,
i, dev)
return -EBUSY;
return 0;
}
static int intel_iommu_add(struct dmar_drhd_unit *dmaru)
{
int sp, ret = 0;
struct intel_iommu *iommu = dmaru->iommu;
if (g_iommus[iommu->seq_id])
return 0;
if (hw_pass_through && !ecap_pass_through(iommu->ecap)) {
pr_warn("IOMMU: %s doesn't support hardware pass through.\n",
iommu->name);
return -ENXIO;
}
if (!ecap_sc_support(iommu->ecap) &&
domain_update_iommu_snooping(iommu)) {
pr_warn("IOMMU: %s doesn't support snooping.\n",
iommu->name);
return -ENXIO;
}
sp = domain_update_iommu_superpage(iommu) - 1;
if (sp >= 0 && !(cap_super_page_val(iommu->cap) & (1 << sp))) {
pr_warn("IOMMU: %s doesn't support large page.\n",
iommu->name);
return -ENXIO;
}
if (iommu->gcmd & DMA_GCMD_TE)
iommu_disable_translation(iommu);
g_iommus[iommu->seq_id] = iommu;
ret = iommu_init_domains(iommu);
if (ret == 0)
ret = iommu_alloc_root_entry(iommu);
if (ret)
goto out;
if (dmaru->ignored) {
if (force_on)
iommu_disable_protect_mem_regions(iommu);
return 0;
}
intel_iommu_init_qi(iommu);
iommu_flush_write_buffer(iommu);
ret = dmar_set_interrupt(iommu);
if (ret)
goto disable_iommu;
iommu_set_root_entry(iommu);
iommu->flush.flush_context(iommu, 0, 0, 0, DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0, DMA_TLB_GLOBAL_FLUSH);
iommu_enable_translation(iommu);
if (si_domain) {
ret = iommu_attach_domain(si_domain, iommu);
if (ret < 0 || si_domain->id != ret)
goto disable_iommu;
domain_attach_iommu(si_domain, iommu);
}
iommu_disable_protect_mem_regions(iommu);
return 0;
disable_iommu:
disable_dmar_iommu(iommu);
out:
free_dmar_iommu(iommu);
return ret;
}
int dmar_iommu_hotplug(struct dmar_drhd_unit *dmaru, bool insert)
{
int ret = 0;
struct intel_iommu *iommu = dmaru->iommu;
if (!intel_iommu_enabled)
return 0;
if (iommu == NULL)
return -EINVAL;
if (insert) {
ret = intel_iommu_add(dmaru);
} else {
disable_dmar_iommu(iommu);
free_dmar_iommu(iommu);
}
return ret;
}
static void intel_iommu_free_dmars(void)
{
struct dmar_rmrr_unit *rmrru, *rmrr_n;
struct dmar_atsr_unit *atsru, *atsr_n;
list_for_each_entry_safe(rmrru, rmrr_n, &dmar_rmrr_units, list) {
list_del(&rmrru->list);
dmar_free_dev_scope(&rmrru->devices, &rmrru->devices_cnt);
kfree(rmrru);
}
list_for_each_entry_safe(atsru, atsr_n, &dmar_atsr_units, list) {
list_del(&atsru->list);
intel_iommu_free_atsr(atsru);
}
}
int dmar_find_matched_atsr_unit(struct pci_dev *dev)
{
int i, ret = 1;
struct pci_bus *bus;
struct pci_dev *bridge = NULL;
struct device *tmp;
struct acpi_dmar_atsr *atsr;
struct dmar_atsr_unit *atsru;
dev = pci_physfn(dev);
for (bus = dev->bus; bus; bus = bus->parent) {
bridge = bus->self;
if (!bridge || !pci_is_pcie(bridge) ||
pci_pcie_type(bridge) == PCI_EXP_TYPE_PCI_BRIDGE)
return 0;
if (pci_pcie_type(bridge) == PCI_EXP_TYPE_ROOT_PORT)
break;
}
if (!bridge)
return 0;
rcu_read_lock();
list_for_each_entry_rcu(atsru, &dmar_atsr_units, list) {
atsr = container_of(atsru->hdr, struct acpi_dmar_atsr, header);
if (atsr->segment != pci_domain_nr(dev->bus))
continue;
for_each_dev_scope(atsru->devices, atsru->devices_cnt, i, tmp)
if (tmp == &bridge->dev)
goto out;
if (atsru->include_all)
goto out;
}
ret = 0;
out:
rcu_read_unlock();
return ret;
}
int dmar_iommu_notify_scope_dev(struct dmar_pci_notify_info *info)
{
int ret = 0;
struct dmar_rmrr_unit *rmrru;
struct dmar_atsr_unit *atsru;
struct acpi_dmar_atsr *atsr;
struct acpi_dmar_reserved_memory *rmrr;
if (!intel_iommu_enabled && system_state != SYSTEM_BOOTING)
return 0;
list_for_each_entry(rmrru, &dmar_rmrr_units, list) {
rmrr = container_of(rmrru->hdr,
struct acpi_dmar_reserved_memory, header);
if (info->event == BUS_NOTIFY_ADD_DEVICE) {
ret = dmar_insert_dev_scope(info, (void *)(rmrr + 1),
((void *)rmrr) + rmrr->header.length,
rmrr->segment, rmrru->devices,
rmrru->devices_cnt);
if(ret < 0)
return ret;
} else if (info->event == BUS_NOTIFY_DEL_DEVICE) {
dmar_remove_dev_scope(info, rmrr->segment,
rmrru->devices, rmrru->devices_cnt);
}
}
list_for_each_entry(atsru, &dmar_atsr_units, list) {
if (atsru->include_all)
continue;
atsr = container_of(atsru->hdr, struct acpi_dmar_atsr, header);
if (info->event == BUS_NOTIFY_ADD_DEVICE) {
ret = dmar_insert_dev_scope(info, (void *)(atsr + 1),
(void *)atsr + atsr->header.length,
atsr->segment, atsru->devices,
atsru->devices_cnt);
if (ret > 0)
break;
else if(ret < 0)
return ret;
} else if (info->event == BUS_NOTIFY_DEL_DEVICE) {
if (dmar_remove_dev_scope(info, atsr->segment,
atsru->devices, atsru->devices_cnt))
break;
}
}
return 0;
}
static int device_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
struct dmar_domain *domain;
if (iommu_dummy(dev))
return 0;
if (action != BUS_NOTIFY_REMOVED_DEVICE)
return 0;
domain = find_domain(dev);
if (!domain)
return 0;
down_read(&dmar_global_lock);
domain_remove_one_dev_info(domain, dev);
if (!domain_type_is_vm_or_si(domain) && list_empty(&domain->devices))
domain_exit(domain);
up_read(&dmar_global_lock);
return 0;
}
static int intel_iommu_memory_notifier(struct notifier_block *nb,
unsigned long val, void *v)
{
struct memory_notify *mhp = v;
unsigned long long start, end;
unsigned long start_vpfn, last_vpfn;
switch (val) {
case MEM_GOING_ONLINE:
start = mhp->start_pfn << PAGE_SHIFT;
end = ((mhp->start_pfn + mhp->nr_pages) << PAGE_SHIFT) - 1;
if (iommu_domain_identity_map(si_domain, start, end)) {
pr_warn("dmar: failed to build identity map for [%llx-%llx]\n",
start, end);
return NOTIFY_BAD;
}
break;
case MEM_OFFLINE:
case MEM_CANCEL_ONLINE:
start_vpfn = mm_to_dma_pfn(mhp->start_pfn);
last_vpfn = mm_to_dma_pfn(mhp->start_pfn + mhp->nr_pages - 1);
while (start_vpfn <= last_vpfn) {
struct iova *iova;
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
struct page *freelist;
iova = find_iova(&si_domain->iovad, start_vpfn);
if (iova == NULL) {
pr_debug("dmar: failed get IOVA for PFN %lx\n",
start_vpfn);
break;
}
iova = split_and_remove_iova(&si_domain->iovad, iova,
start_vpfn, last_vpfn);
if (iova == NULL) {
pr_warn("dmar: failed to split IOVA PFN [%lx-%lx]\n",
start_vpfn, last_vpfn);
return NOTIFY_BAD;
}
freelist = domain_unmap(si_domain, iova->pfn_lo,
iova->pfn_hi);
rcu_read_lock();
for_each_active_iommu(iommu, drhd)
iommu_flush_iotlb_psi(iommu, si_domain->id,
iova->pfn_lo, iova_size(iova),
!freelist, 0);
rcu_read_unlock();
dma_free_pagelist(freelist);
start_vpfn = iova->pfn_hi + 1;
free_iova_mem(iova);
}
break;
}
return NOTIFY_OK;
}
static ssize_t intel_iommu_show_version(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct intel_iommu *iommu = dev_get_drvdata(dev);
u32 ver = readl(iommu->reg + DMAR_VER_REG);
return sprintf(buf, "%d:%d\n",
DMAR_VER_MAJOR(ver), DMAR_VER_MINOR(ver));
}
static ssize_t intel_iommu_show_address(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct intel_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%llx\n", iommu->reg_phys);
}
static ssize_t intel_iommu_show_cap(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct intel_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%llx\n", iommu->cap);
}
static ssize_t intel_iommu_show_ecap(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct intel_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%llx\n", iommu->ecap);
}
int __init intel_iommu_init(void)
{
int ret = -ENODEV;
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
force_on = tboot_force_iommu();
if (iommu_init_mempool()) {
if (force_on)
panic("tboot: Failed to initialize iommu memory\n");
return -ENOMEM;
}
down_write(&dmar_global_lock);
if (dmar_table_init()) {
if (force_on)
panic("tboot: Failed to initialize DMAR table\n");
goto out_free_dmar;
}
for_each_active_iommu(iommu, drhd)
if (iommu->gcmd & DMA_GCMD_TE)
iommu_disable_translation(iommu);
if (dmar_dev_scope_init() < 0) {
if (force_on)
panic("tboot: Failed to initialize DMAR device scope\n");
goto out_free_dmar;
}
if (no_iommu || dmar_disabled)
goto out_free_dmar;
if (list_empty(&dmar_rmrr_units))
printk(KERN_INFO "DMAR: No RMRR found\n");
if (list_empty(&dmar_atsr_units))
printk(KERN_INFO "DMAR: No ATSR found\n");
if (dmar_init_reserved_ranges()) {
if (force_on)
panic("tboot: Failed to reserve iommu ranges\n");
goto out_free_reserved_range;
}
init_no_remapping_devices();
ret = init_dmars();
if (ret) {
if (force_on)
panic("tboot: Failed to initialize DMARs\n");
printk(KERN_ERR "IOMMU: dmar init failed\n");
goto out_free_reserved_range;
}
up_write(&dmar_global_lock);
printk(KERN_INFO
"PCI-DMA: Intel(R) Virtualization Technology for Directed I/O\n");
init_timer(&unmap_timer);
#ifdef CONFIG_SWIOTLB
swiotlb = 0;
#endif
dma_ops = &intel_dma_ops;
init_iommu_pm_ops();
for_each_active_iommu(iommu, drhd)
iommu->iommu_dev = iommu_device_create(NULL, iommu,
intel_iommu_groups,
iommu->name);
bus_set_iommu(&pci_bus_type, &intel_iommu_ops);
bus_register_notifier(&pci_bus_type, &device_nb);
if (si_domain && !hw_pass_through)
register_memory_notifier(&intel_iommu_memory_nb);
intel_iommu_enabled = 1;
return 0;
out_free_reserved_range:
put_iova_domain(&reserved_iova_list);
out_free_dmar:
intel_iommu_free_dmars();
up_write(&dmar_global_lock);
iommu_exit_mempool();
return ret;
}
static int iommu_detach_dev_cb(struct pci_dev *pdev, u16 alias, void *opaque)
{
struct intel_iommu *iommu = opaque;
iommu_detach_dev(iommu, PCI_BUS_NUM(alias), alias & 0xff);
return 0;
}
static void iommu_detach_dependent_devices(struct intel_iommu *iommu,
struct device *dev)
{
if (!iommu || !dev || !dev_is_pci(dev))
return;
pci_for_each_dma_alias(to_pci_dev(dev), &iommu_detach_dev_cb, iommu);
}
static void domain_remove_one_dev_info(struct dmar_domain *domain,
struct device *dev)
{
struct device_domain_info *info, *tmp;
struct intel_iommu *iommu;
unsigned long flags;
int found = 0;
u8 bus, devfn;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return;
spin_lock_irqsave(&device_domain_lock, flags);
list_for_each_entry_safe(info, tmp, &domain->devices, link) {
if (info->iommu == iommu && info->bus == bus &&
info->devfn == devfn) {
unlink_domain_info(info);
spin_unlock_irqrestore(&device_domain_lock, flags);
iommu_disable_dev_iotlb(info);
iommu_detach_dev(iommu, info->bus, info->devfn);
iommu_detach_dependent_devices(iommu, dev);
free_devinfo_mem(info);
spin_lock_irqsave(&device_domain_lock, flags);
if (found)
break;
else
continue;
}
if (info->iommu == iommu)
found = 1;
}
spin_unlock_irqrestore(&device_domain_lock, flags);
if (found == 0) {
domain_detach_iommu(domain, iommu);
if (!domain_type_is_vm_or_si(domain))
iommu_detach_domain(domain, iommu);
}
}
static int md_domain_init(struct dmar_domain *domain, int guest_width)
{
int adjust_width;
init_iova_domain(&domain->iovad, DMA_32BIT_PFN);
domain_reserve_special_ranges(domain);
domain->gaw = guest_width;
adjust_width = guestwidth_to_adjustwidth(guest_width);
domain->agaw = width_to_agaw(adjust_width);
domain->iommu_coherency = 0;
domain->iommu_snooping = 0;
domain->iommu_superpage = 0;
domain->max_addr = 0;
domain->pgd = (struct dma_pte *)alloc_pgtable_page(domain->nid);
if (!domain->pgd)
return -ENOMEM;
domain_flush_cache(domain, domain->pgd, PAGE_SIZE);
return 0;
}
static int intel_iommu_domain_init(struct iommu_domain *domain)
{
struct dmar_domain *dmar_domain;
dmar_domain = alloc_domain(DOMAIN_FLAG_VIRTUAL_MACHINE);
if (!dmar_domain) {
printk(KERN_ERR
"intel_iommu_domain_init: dmar_domain == NULL\n");
return -ENOMEM;
}
if (md_domain_init(dmar_domain, DEFAULT_DOMAIN_ADDRESS_WIDTH)) {
printk(KERN_ERR
"intel_iommu_domain_init() failed\n");
domain_exit(dmar_domain);
return -ENOMEM;
}
domain_update_iommu_cap(dmar_domain);
domain->priv = dmar_domain;
domain->geometry.aperture_start = 0;
domain->geometry.aperture_end = __DOMAIN_MAX_ADDR(dmar_domain->gaw);
domain->geometry.force_aperture = true;
return 0;
}
static void intel_iommu_domain_destroy(struct iommu_domain *domain)
{
struct dmar_domain *dmar_domain = domain->priv;
domain->priv = NULL;
domain_exit(dmar_domain);
}
static int intel_iommu_attach_device(struct iommu_domain *domain,
struct device *dev)
{
struct dmar_domain *dmar_domain = domain->priv;
struct intel_iommu *iommu;
int addr_width;
u8 bus, devfn;
if (device_is_rmrr_locked(dev)) {
dev_warn(dev, "Device is ineligible for IOMMU domain attach due to platform RMRR requirement. Contact your platform vendor.\n");
return -EPERM;
}
if (unlikely(domain_context_mapped(dev))) {
struct dmar_domain *old_domain;
old_domain = find_domain(dev);
if (old_domain) {
if (domain_type_is_vm_or_si(dmar_domain))
domain_remove_one_dev_info(old_domain, dev);
else
domain_remove_dev_info(old_domain);
if (!domain_type_is_vm_or_si(old_domain) &&
list_empty(&old_domain->devices))
domain_exit(old_domain);
}
}
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
addr_width = agaw_to_width(iommu->agaw);
if (addr_width > cap_mgaw(iommu->cap))
addr_width = cap_mgaw(iommu->cap);
if (dmar_domain->max_addr > (1LL << addr_width)) {
printk(KERN_ERR "%s: iommu width (%d) is not "
"sufficient for the mapped address (%llx)\n",
__func__, addr_width, dmar_domain->max_addr);
return -EFAULT;
}
dmar_domain->gaw = addr_width;
while (iommu->agaw < dmar_domain->agaw) {
struct dma_pte *pte;
pte = dmar_domain->pgd;
if (dma_pte_present(pte)) {
dmar_domain->pgd = (struct dma_pte *)
phys_to_virt(dma_pte_addr(pte));
free_pgtable_page(pte);
}
dmar_domain->agaw--;
}
return domain_add_dev_info(dmar_domain, dev, CONTEXT_TT_MULTI_LEVEL);
}
static void intel_iommu_detach_device(struct iommu_domain *domain,
struct device *dev)
{
struct dmar_domain *dmar_domain = domain->priv;
domain_remove_one_dev_info(dmar_domain, dev);
}
static int intel_iommu_map(struct iommu_domain *domain,
unsigned long iova, phys_addr_t hpa,
size_t size, int iommu_prot)
{
struct dmar_domain *dmar_domain = domain->priv;
u64 max_addr;
int prot = 0;
int ret;
if (iommu_prot & IOMMU_READ)
prot |= DMA_PTE_READ;
if (iommu_prot & IOMMU_WRITE)
prot |= DMA_PTE_WRITE;
if ((iommu_prot & IOMMU_CACHE) && dmar_domain->iommu_snooping)
prot |= DMA_PTE_SNP;
max_addr = iova + size;
if (dmar_domain->max_addr < max_addr) {
u64 end;
end = __DOMAIN_MAX_ADDR(dmar_domain->gaw) + 1;
if (end < max_addr) {
printk(KERN_ERR "%s: iommu width (%d) is not "
"sufficient for the mapped address (%llx)\n",
__func__, dmar_domain->gaw, max_addr);
return -EFAULT;
}
dmar_domain->max_addr = max_addr;
}
size = aligned_nrpages(hpa, size);
ret = domain_pfn_mapping(dmar_domain, iova >> VTD_PAGE_SHIFT,
hpa >> VTD_PAGE_SHIFT, size, prot);
return ret;
}
static size_t intel_iommu_unmap(struct iommu_domain *domain,
unsigned long iova, size_t size)
{
struct dmar_domain *dmar_domain = domain->priv;
struct page *freelist = NULL;
struct intel_iommu *iommu;
unsigned long start_pfn, last_pfn;
unsigned int npages;
int iommu_id, num, ndomains, level = 0;
if (!pfn_to_dma_pte(dmar_domain, iova >> VTD_PAGE_SHIFT, &level))
BUG();
if (size < VTD_PAGE_SIZE << level_to_offset_bits(level))
size = VTD_PAGE_SIZE << level_to_offset_bits(level);
start_pfn = iova >> VTD_PAGE_SHIFT;
last_pfn = (iova + size - 1) >> VTD_PAGE_SHIFT;
freelist = domain_unmap(dmar_domain, start_pfn, last_pfn);
npages = last_pfn - start_pfn + 1;
for_each_set_bit(iommu_id, dmar_domain->iommu_bmp, g_num_of_iommus) {
iommu = g_iommus[iommu_id];
ndomains = cap_ndoms(iommu->cap);
for_each_set_bit(num, iommu->domain_ids, ndomains) {
if (iommu->domains[num] == dmar_domain)
iommu_flush_iotlb_psi(iommu, num, start_pfn,
npages, !freelist, 0);
}
}
dma_free_pagelist(freelist);
if (dmar_domain->max_addr == iova + size)
dmar_domain->max_addr = iova;
return size;
}
static phys_addr_t intel_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
struct dmar_domain *dmar_domain = domain->priv;
struct dma_pte *pte;
int level = 0;
u64 phys = 0;
pte = pfn_to_dma_pte(dmar_domain, iova >> VTD_PAGE_SHIFT, &level);
if (pte)
phys = dma_pte_addr(pte);
return phys;
}
static bool intel_iommu_capable(enum iommu_cap cap)
{
if (cap == IOMMU_CAP_CACHE_COHERENCY)
return domain_update_iommu_snooping(NULL) == 1;
if (cap == IOMMU_CAP_INTR_REMAP)
return irq_remapping_enabled == 1;
return false;
}
static int intel_iommu_add_device(struct device *dev)
{
struct intel_iommu *iommu;
struct iommu_group *group;
u8 bus, devfn;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
iommu_device_link(iommu->iommu_dev, dev);
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group))
return PTR_ERR(group);
iommu_group_put(group);
return 0;
}
static void intel_iommu_remove_device(struct device *dev)
{
struct intel_iommu *iommu;
u8 bus, devfn;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return;
iommu_group_remove_device(dev);
iommu_device_unlink(iommu->iommu_dev, dev);
}
static void quirk_iommu_g4x_gfx(struct pci_dev *dev)
{
printk(KERN_INFO "DMAR: Disabling IOMMU for graphics on this chipset\n");
dmar_map_gfx = 0;
}
static void quirk_iommu_rwbf(struct pci_dev *dev)
{
printk(KERN_INFO "DMAR: Forcing write-buffer flush capability\n");
rwbf_quirk = 1;
}
static void quirk_calpella_no_shadow_gtt(struct pci_dev *dev)
{
unsigned short ggc;
if (pci_read_config_word(dev, GGC, &ggc))
return;
if (!(ggc & GGC_MEMORY_VT_ENABLED)) {
printk(KERN_INFO "DMAR: BIOS has allocated no shadow GTT; disabling IOMMU for graphics\n");
dmar_map_gfx = 0;
} else if (dmar_map_gfx) {
printk(KERN_INFO "DMAR: Disabling batched IOTLB flush on Ironlake\n");
intel_iommu_strict = 1;
}
}
static void __init check_tylersburg_isoch(void)
{
struct pci_dev *pdev;
uint32_t vtisochctrl;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x3a3e, NULL);
if (!pdev)
return;
pci_dev_put(pdev);
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x342e, NULL);
if (!pdev)
return;
if (pci_read_config_dword(pdev, 0x188, &vtisochctrl)) {
pci_dev_put(pdev);
return;
}
pci_dev_put(pdev);
if (vtisochctrl & 1)
return;
vtisochctrl &= 0x1c;
if (vtisochctrl == 0x10)
return;
if (!vtisochctrl) {
WARN(1, "Your BIOS is broken; DMA routed to ISOCH DMAR unit but no TLB space.\n"
"BIOS vendor: %s; Ver: %s; Product Version: %s\n",
dmi_get_system_info(DMI_BIOS_VENDOR),
dmi_get_system_info(DMI_BIOS_VERSION),
dmi_get_system_info(DMI_PRODUCT_VERSION));
iommu_identity_mapping |= IDENTMAP_AZALIA;
return;
}
printk(KERN_WARNING "DMAR: Recommended TLB entries for ISOCH unit is 16; your BIOS set %d\n",
vtisochctrl);
}
