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
static phys_addr_t root_entry_lctp(struct root_entry *re)
{
if (!(re->lo & 1))
return 0;
return re->lo & VTD_PAGE_MASK;
}
static phys_addr_t root_entry_uctp(struct root_entry *re)
{
if (!(re->hi & 1))
return 0;
return re->hi & VTD_PAGE_MASK;
}
static inline void context_clear_pasid_enable(struct context_entry *context)
{
context->lo &= ~(1ULL << 11);
}
static inline bool context_pasid_enabled(struct context_entry *context)
{
return !!(context->lo & (1ULL << 11));
}
static inline void context_set_copied(struct context_entry *context)
{
context->hi |= (1ull << 3);
}
static inline bool context_copied(struct context_entry *context)
{
return !!(context->hi & (1ULL << 3));
}
static inline bool __context_present(struct context_entry *context)
{
return (context->lo & 1);
}
static inline bool context_present(struct context_entry *context)
{
return context_pasid_enabled(context) ?
__context_present(context) :
__context_present(context) && !context_copied(context);
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
static inline int context_domain_id(struct context_entry *c)
{
return((c->hi >> 8) & 0xffff);
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
static bool translation_pre_enabled(struct intel_iommu *iommu)
{
return (iommu->flags & VTD_FLAG_TRANS_PRE_ENABLED);
}
static void clear_translation_pre_enabled(struct intel_iommu *iommu)
{
iommu->flags &= ~VTD_FLAG_TRANS_PRE_ENABLED;
}
static void init_translation_status(struct intel_iommu *iommu)
{
u32 gsts;
gsts = readl(iommu->reg + DMAR_GSTS_REG);
if (gsts & DMA_GSTS_TES)
iommu->flags |= VTD_FLAG_TRANS_PRE_ENABLED;
}
static struct dmar_domain *to_dmar_domain(struct iommu_domain *dom)
{
return container_of(dom, struct dmar_domain, domain);
}
static int __init intel_iommu_setup(char *str)
{
if (!str)
return -EINVAL;
while (*str) {
if (!strncmp(str, "on", 2)) {
dmar_disabled = 0;
pr_info("IOMMU enabled\n");
} else if (!strncmp(str, "off", 3)) {
dmar_disabled = 1;
pr_info("IOMMU disabled\n");
} else if (!strncmp(str, "igfx_off", 8)) {
dmar_map_gfx = 0;
pr_info("Disable GFX device mapping\n");
} else if (!strncmp(str, "forcedac", 8)) {
pr_info("Forcing DAC for PCI devices\n");
dmar_forcedac = 1;
} else if (!strncmp(str, "strict", 6)) {
pr_info("Disable batched IOTLB flush\n");
intel_iommu_strict = 1;
} else if (!strncmp(str, "sp_off", 6)) {
pr_info("Disable supported super page\n");
intel_iommu_superpage = 0;
} else if (!strncmp(str, "ecs_off", 7)) {
printk(KERN_INFO
"Intel-IOMMU: disable extended context table support\n");
intel_iommu_ecs = 0;
} else if (!strncmp(str, "pasid28", 7)) {
printk(KERN_INFO
"Intel-IOMMU: enable pre-production PASID support\n");
intel_iommu_pasid28 = 1;
iommu_identity_mapping |= IDENTMAP_GFX;
}
str += strcspn(str, ",");
while (*str == ',')
str++;
}
return 0;
}
static struct dmar_domain* get_iommu_domain(struct intel_iommu *iommu, u16 did)
{
struct dmar_domain **domains;
int idx = did >> 8;
domains = iommu->domains[idx];
if (!domains)
return NULL;
return domains[did & 0xff];
}
static void set_iommu_domain(struct intel_iommu *iommu, u16 did,
struct dmar_domain *domain)
{
struct dmar_domain **domains;
int idx = did >> 8;
if (!iommu->domains[idx]) {
size_t size = 256 * sizeof(struct dmar_domain *);
iommu->domains[idx] = kzalloc(size, GFP_ATOMIC);
}
domains = iommu->domains[idx];
if (WARN_ON(!domains))
return;
else
domains[did & 0xff] = domain;
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
static inline int domain_type_is_vm(struct dmar_domain *domain)
{
return domain->flags & DOMAIN_FLAG_VIRTUAL_MACHINE;
}
static inline int domain_type_is_si(struct dmar_domain *domain)
{
return domain->flags & DOMAIN_FLAG_STATIC_IDENTITY;
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
for_each_domain_iommu(iommu_id, domain)
break;
if (iommu_id < 0 || iommu_id >= g_num_of_iommus)
return NULL;
return g_iommus[iommu_id];
}
static void domain_update_iommu_coherency(struct dmar_domain *domain)
{
struct dmar_drhd_unit *drhd;
struct intel_iommu *iommu;
bool found = false;
int i;
domain->iommu_coherency = 1;
for_each_domain_iommu(i, domain) {
found = true;
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
static inline struct context_entry *iommu_context_addr(struct intel_iommu *iommu,
u8 bus, u8 devfn, int alloc)
{
struct root_entry *root = &iommu->root_entry[bus];
struct context_entry *context;
u64 *entry;
entry = &root->lo;
if (ecs_enabled(iommu)) {
if (devfn >= 0x80) {
devfn -= 0x80;
entry = &root->hi;
}
devfn *= 2;
}
if (*entry & 1)
context = phys_to_virt(*entry & VTD_PAGE_MASK);
else {
unsigned long phy_addr;
if (!alloc)
return NULL;
context = alloc_pgtable_page(iommu->node);
if (!context)
return NULL;
__iommu_flush_cache(iommu, (void *)context, CONTEXT_SIZE);
phy_addr = virt_to_phys((void *)context);
*entry = phy_addr | 1;
__iommu_flush_cache(iommu, entry, sizeof(*entry));
}
return &context[devfn];
}
static int iommu_dummy(struct device *dev)
{
return dev->archdata.iommu == DUMMY_DEVICE_DOMAIN_INFO;
}
static struct intel_iommu *device_to_iommu(struct device *dev, u8 *bus, u8 *devfn)
{
struct dmar_drhd_unit *drhd = NULL;
struct intel_iommu *iommu;
struct device *tmp;
struct pci_dev *ptmp, *pdev = NULL;
u16 segment = 0;
int i;
if (iommu_dummy(dev))
return NULL;
if (dev_is_pci(dev)) {
pdev = to_pci_dev(dev);
segment = pci_domain_nr(pdev->bus);
} else if (has_acpi_companion(dev))
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
static int device_context_mapped(struct intel_iommu *iommu, u8 bus, u8 devfn)
{
struct context_entry *context;
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
context = iommu_context_addr(iommu, bus, devfn, 0);
if (context)
ret = context_present(context);
spin_unlock_irqrestore(&iommu->lock, flags);
return ret;
}
static void clear_context_table(struct intel_iommu *iommu, u8 bus, u8 devfn)
{
struct context_entry *context;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
context = iommu_context_addr(iommu, bus, devfn, 0);
if (context) {
context_clear_entry(context);
__iommu_flush_cache(iommu, context, sizeof(*context));
}
spin_unlock_irqrestore(&iommu->lock, flags);
}
static void free_context_table(struct intel_iommu *iommu)
{
int i;
unsigned long flags;
struct context_entry *context;
spin_lock_irqsave(&iommu->lock, flags);
if (!iommu->root_entry) {
goto out;
}
for (i = 0; i < ROOT_ENTRY_NR; i++) {
context = iommu_context_addr(iommu, i, 0, 0);
if (context)
free_pgtable_page(context);
if (!ecs_enabled(iommu))
continue;
context = iommu_context_addr(iommu, i, 0x80, 0);
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
static struct page *domain_unmap(struct dmar_domain *domain,
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
static void dma_free_pagelist(struct page *freelist)
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
pr_err("Allocating root entry for %s failed\n",
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
u64 addr;
u32 sts;
unsigned long flag;
addr = virt_to_phys(iommu->root_entry);
if (ecs_enabled(iommu))
addr |= DMA_RTADDR_RTT;
raw_spin_lock_irqsave(&iommu->register_lock, flag);
dmar_writeq(iommu->reg + DMAR_RTADDR_REG, addr);
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
pr_err("Flush IOTLB failed\n");
if (DMA_TLB_IAIG(val) != DMA_TLB_IIRG(type))
pr_debug("TLB flush request %Lx, actual %Lx\n",
(unsigned long long)DMA_TLB_IIRG(type),
(unsigned long long)DMA_TLB_IAIG(val));
}
static struct device_domain_info *
iommu_support_dev_iotlb (struct dmar_domain *domain, struct intel_iommu *iommu,
u8 bus, u8 devfn)
{
struct device_domain_info *info;
assert_spin_locked(&device_domain_lock);
if (!iommu->qi)
return NULL;
list_for_each_entry(info, &domain->devices, link)
if (info->iommu == iommu && info->bus == bus &&
info->devfn == devfn) {
if (info->ats_supported && info->dev)
return info;
break;
}
return NULL;
}
static void domain_update_iotlb(struct dmar_domain *domain)
{
struct device_domain_info *info;
bool has_iotlb_device = false;
assert_spin_locked(&device_domain_lock);
list_for_each_entry(info, &domain->devices, link) {
struct pci_dev *pdev;
if (!info->dev || !dev_is_pci(info->dev))
continue;
pdev = to_pci_dev(info->dev);
if (pdev->ats_enabled) {
has_iotlb_device = true;
break;
}
}
domain->has_iotlb_device = has_iotlb_device;
}
static void iommu_enable_dev_iotlb(struct device_domain_info *info)
{
struct pci_dev *pdev;
assert_spin_locked(&device_domain_lock);
if (!info || !dev_is_pci(info->dev))
return;
pdev = to_pci_dev(info->dev);
#ifdef CONFIG_INTEL_IOMMU_SVM
if (info->pasid_supported && !pci_enable_pasid(pdev, info->pasid_supported & ~1))
info->pasid_enabled = 1;
if (info->pri_supported && !pci_reset_pri(pdev) && !pci_enable_pri(pdev, 32))
info->pri_enabled = 1;
#endif
if (info->ats_supported && !pci_enable_ats(pdev, VTD_PAGE_SHIFT)) {
info->ats_enabled = 1;
domain_update_iotlb(info->domain);
info->ats_qdep = pci_ats_queue_depth(pdev);
}
}
static void iommu_disable_dev_iotlb(struct device_domain_info *info)
{
struct pci_dev *pdev;
assert_spin_locked(&device_domain_lock);
if (!dev_is_pci(info->dev))
return;
pdev = to_pci_dev(info->dev);
if (info->ats_enabled) {
pci_disable_ats(pdev);
info->ats_enabled = 0;
domain_update_iotlb(info->domain);
}
#ifdef CONFIG_INTEL_IOMMU_SVM
if (info->pri_enabled) {
pci_disable_pri(pdev);
info->pri_enabled = 0;
}
if (info->pasid_enabled) {
pci_disable_pasid(pdev);
info->pasid_enabled = 0;
}
#endif
}
static void iommu_flush_dev_iotlb(struct dmar_domain *domain,
u64 addr, unsigned mask)
{
u16 sid, qdep;
unsigned long flags;
struct device_domain_info *info;
if (!domain->has_iotlb_device)
return;
spin_lock_irqsave(&device_domain_lock, flags);
list_for_each_entry(info, &domain->devices, link) {
if (!info->ats_enabled)
continue;
sid = info->bus << 8 | info->devfn;
qdep = info->ats_qdep;
qi_flush_dev_iotlb(info->iommu, sid, qdep, addr, mask);
}
spin_unlock_irqrestore(&device_domain_lock, flags);
}
static void iommu_flush_iotlb_psi(struct intel_iommu *iommu,
struct dmar_domain *domain,
unsigned long pfn, unsigned int pages,
int ih, int map)
{
unsigned int mask = ilog2(__roundup_pow_of_two(pages));
uint64_t addr = (uint64_t)pfn << VTD_PAGE_SHIFT;
u16 did = domain->iommu_did[iommu->seq_id];
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
iommu_flush_dev_iotlb(get_iommu_domain(iommu, did),
addr, mask);
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
u32 ndomains, nlongs;
size_t size;
ndomains = cap_ndoms(iommu->cap);
pr_debug("%s: Number of Domains supported <%d>\n",
iommu->name, ndomains);
nlongs = BITS_TO_LONGS(ndomains);
spin_lock_init(&iommu->lock);
iommu->domain_ids = kcalloc(nlongs, sizeof(unsigned long), GFP_KERNEL);
if (!iommu->domain_ids) {
pr_err("%s: Allocating domain id array failed\n",
iommu->name);
return -ENOMEM;
}
size = ((ndomains >> 8) + 1) * sizeof(struct dmar_domain **);
iommu->domains = kzalloc(size, GFP_KERNEL);
if (iommu->domains) {
size = 256 * sizeof(struct dmar_domain *);
iommu->domains[0] = kzalloc(size, GFP_KERNEL);
}
if (!iommu->domains || !iommu->domains[0]) {
pr_err("%s: Allocating domain array failed\n",
iommu->name);
kfree(iommu->domain_ids);
kfree(iommu->domains);
iommu->domain_ids = NULL;
iommu->domains = NULL;
return -ENOMEM;
}
set_bit(0, iommu->domain_ids);
return 0;
}
static void disable_dmar_iommu(struct intel_iommu *iommu)
{
struct device_domain_info *info, *tmp;
unsigned long flags;
if (!iommu->domains || !iommu->domain_ids)
return;
spin_lock_irqsave(&device_domain_lock, flags);
list_for_each_entry_safe(info, tmp, &device_domain_list, global) {
struct dmar_domain *domain;
if (info->iommu != iommu)
continue;
if (!info->dev || !info->domain)
continue;
domain = info->domain;
dmar_remove_one_dev_info(domain, info->dev);
if (!domain_type_is_vm_or_si(domain))
domain_exit(domain);
}
spin_unlock_irqrestore(&device_domain_lock, flags);
if (iommu->gcmd & DMA_GCMD_TE)
iommu_disable_translation(iommu);
}
static void free_dmar_iommu(struct intel_iommu *iommu)
{
if ((iommu->domains) && (iommu->domain_ids)) {
int elems = (cap_ndoms(iommu->cap) >> 8) + 1;
int i;
for (i = 0; i < elems; i++)
kfree(iommu->domains[i]);
kfree(iommu->domains);
kfree(iommu->domain_ids);
iommu->domains = NULL;
iommu->domain_ids = NULL;
}
g_iommus[iommu->seq_id] = NULL;
free_context_table(iommu);
#ifdef CONFIG_INTEL_IOMMU_SVM
if (pasid_enabled(iommu)) {
if (ecap_prs(iommu->ecap))
intel_svm_finish_prq(iommu);
intel_svm_free_pasid_tables(iommu);
}
#endif
}
static struct dmar_domain *alloc_domain(int flags)
{
struct dmar_domain *domain;
domain = alloc_domain_mem();
if (!domain)
return NULL;
memset(domain, 0, sizeof(*domain));
domain->nid = -1;
domain->flags = flags;
domain->has_iotlb_device = false;
INIT_LIST_HEAD(&domain->devices);
return domain;
}
static int domain_attach_iommu(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
unsigned long ndomains;
int num;
assert_spin_locked(&device_domain_lock);
assert_spin_locked(&iommu->lock);
domain->iommu_refcnt[iommu->seq_id] += 1;
domain->iommu_count += 1;
if (domain->iommu_refcnt[iommu->seq_id] == 1) {
ndomains = cap_ndoms(iommu->cap);
num = find_first_zero_bit(iommu->domain_ids, ndomains);
if (num >= ndomains) {
pr_err("%s: No free domain ids\n", iommu->name);
domain->iommu_refcnt[iommu->seq_id] -= 1;
domain->iommu_count -= 1;
return -ENOSPC;
}
set_bit(num, iommu->domain_ids);
set_iommu_domain(iommu, num, domain);
domain->iommu_did[iommu->seq_id] = num;
domain->nid = iommu->node;
domain_update_iommu_cap(domain);
}
return 0;
}
static int domain_detach_iommu(struct dmar_domain *domain,
struct intel_iommu *iommu)
{
int num, count = INT_MAX;
assert_spin_locked(&device_domain_lock);
assert_spin_locked(&iommu->lock);
domain->iommu_refcnt[iommu->seq_id] -= 1;
count = --domain->iommu_count;
if (domain->iommu_refcnt[iommu->seq_id] == 0) {
num = domain->iommu_did[iommu->seq_id];
clear_bit(num, iommu->domain_ids);
set_iommu_domain(iommu, num, NULL);
domain_update_iommu_cap(domain);
domain->iommu_did[iommu->seq_id] = 0;
}
return count;
}
static int dmar_init_reserved_ranges(void)
{
struct pci_dev *pdev = NULL;
struct iova *iova;
int i;
init_iova_domain(&reserved_iova_list, VTD_PAGE_SIZE, IOVA_START_PFN,
DMA_32BIT_PFN);
lockdep_set_class(&reserved_iova_list.iova_rbtree_lock,
&reserved_rbtree_key);
iova = reserve_iova(&reserved_iova_list, IOVA_PFN(IOAPIC_RANGE_START),
IOVA_PFN(IOAPIC_RANGE_END));
if (!iova) {
pr_err("Reserve IOAPIC range failed\n");
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
pr_err("Reserve iova failed\n");
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
static int domain_init(struct dmar_domain *domain, struct intel_iommu *iommu,
int guest_width)
{
int adjust_width, agaw;
unsigned long sagaw;
init_iova_domain(&domain->iovad, VTD_PAGE_SIZE, IOVA_START_PFN,
DMA_32BIT_PFN);
domain_reserve_special_ranges(domain);
if (guest_width > cap_mgaw(iommu->cap))
guest_width = cap_mgaw(iommu->cap);
domain->gaw = guest_width;
adjust_width = guestwidth_to_adjustwidth(guest_width);
agaw = width_to_agaw(adjust_width);
sagaw = cap_sagaw(iommu->cap);
if (!test_bit(agaw, &sagaw)) {
pr_debug("Hardware doesn't support agaw %d\n", agaw);
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
struct page *freelist = NULL;
if (!domain)
return;
if (!intel_iommu_strict) {
int cpu;
for_each_possible_cpu(cpu)
flush_unmaps_timeout(cpu);
}
rcu_read_lock();
domain_remove_dev_info(domain);
rcu_read_unlock();
put_iova_domain(&domain->iovad);
freelist = domain_unmap(domain, 0, DOMAIN_MAX_PFN(domain->gaw));
dma_free_pagelist(freelist);
free_domain_mem(domain);
}
static int domain_context_mapping_one(struct dmar_domain *domain,
struct intel_iommu *iommu,
u8 bus, u8 devfn)
{
u16 did = domain->iommu_did[iommu->seq_id];
int translation = CONTEXT_TT_MULTI_LEVEL;
struct device_domain_info *info = NULL;
struct context_entry *context;
unsigned long flags;
struct dma_pte *pgd;
int ret, agaw;
WARN_ON(did == 0);
if (hw_pass_through && domain_type_is_si(domain))
translation = CONTEXT_TT_PASS_THROUGH;
pr_debug("Set context mapping for %02x:%02x.%d\n",
bus, PCI_SLOT(devfn), PCI_FUNC(devfn));
BUG_ON(!domain->pgd);
spin_lock_irqsave(&device_domain_lock, flags);
spin_lock(&iommu->lock);
ret = -ENOMEM;
context = iommu_context_addr(iommu, bus, devfn, 1);
if (!context)
goto out_unlock;
ret = 0;
if (context_present(context))
goto out_unlock;
pgd = domain->pgd;
context_clear_entry(context);
context_set_domain_id(context, did);
if (translation != CONTEXT_TT_PASS_THROUGH) {
for (agaw = domain->agaw; agaw != iommu->agaw; agaw--) {
ret = -ENOMEM;
pgd = phys_to_virt(dma_pte_addr(pgd));
if (!dma_pte_present(pgd))
goto out_unlock;
}
info = iommu_support_dev_iotlb(domain, iommu, bus, devfn);
if (info && info->ats_supported)
translation = CONTEXT_TT_DEV_IOTLB;
else
translation = CONTEXT_TT_MULTI_LEVEL;
context_set_address_root(context, virt_to_phys(pgd));
context_set_address_width(context, iommu->agaw);
} else {
context_set_address_width(context, iommu->msagaw);
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
iommu->flush.flush_iotlb(iommu, did, 0, 0, DMA_TLB_DSI_FLUSH);
} else {
iommu_flush_write_buffer(iommu);
}
iommu_enable_dev_iotlb(info);
ret = 0;
out_unlock:
spin_unlock(&iommu->lock);
spin_unlock_irqrestore(&device_domain_lock, flags);
return 0;
}
static int domain_context_mapping_cb(struct pci_dev *pdev,
u16 alias, void *opaque)
{
struct domain_context_mapping_data *data = opaque;
return domain_context_mapping_one(data->domain, data->iommu,
PCI_BUS_NUM(alias), alias & 0xff);
}
static int
domain_context_mapping(struct dmar_domain *domain, struct device *dev)
{
struct intel_iommu *iommu;
u8 bus, devfn;
struct domain_context_mapping_data data;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
if (!dev_is_pci(dev))
return domain_context_mapping_one(domain, iommu, bus, devfn);
data.domain = domain;
data.iommu = iommu;
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
unsigned long nr_superpages, end_pfn;
pteval |= DMA_PTE_LARGE_PAGE;
lvl_pages = lvl_to_nr_pages(largepage_lvl);
nr_superpages = sg_res / lvl_pages;
end_pfn = iov_pfn + nr_superpages * lvl_pages - 1;
dma_pte_free_pagetable(domain, iov_pfn, end_pfn);
} else {
pteval &= ~(uint64_t)DMA_PTE_LARGE_PAGE;
}
}
tmp = cmpxchg64_local(&pte->val, 0ULL, pteval);
if (tmp) {
static int dumps = 5;
pr_crit("ERROR: DMA PTE for vPFN 0x%lx already set (to %llx not %llx)\n",
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
static void domain_context_clear_one(struct intel_iommu *iommu, u8 bus, u8 devfn)
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
list_for_each_entry_safe(info, tmp, &domain->devices, link)
__dmar_remove_one_dev_info(info);
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
static struct dmar_domain *dmar_insert_one_dev_info(struct intel_iommu *iommu,
int bus, int devfn,
struct device *dev,
struct dmar_domain *domain)
{
struct dmar_domain *found = NULL;
struct device_domain_info *info;
unsigned long flags;
int ret;
info = alloc_devinfo_mem();
if (!info)
return NULL;
info->bus = bus;
info->devfn = devfn;
info->ats_supported = info->pasid_supported = info->pri_supported = 0;
info->ats_enabled = info->pasid_enabled = info->pri_enabled = 0;
info->ats_qdep = 0;
info->dev = dev;
info->domain = domain;
info->iommu = iommu;
if (dev && dev_is_pci(dev)) {
struct pci_dev *pdev = to_pci_dev(info->dev);
if (ecap_dev_iotlb_support(iommu->ecap) &&
pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_ATS) &&
dmar_find_matched_atsr_unit(pdev))
info->ats_supported = 1;
if (ecs_enabled(iommu)) {
if (pasid_enabled(iommu)) {
int features = pci_pasid_features(pdev);
if (features >= 0)
info->pasid_supported = features | 1;
}
if (info->ats_supported && ecap_prs(iommu->ecap) &&
pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PRI))
info->pri_supported = 1;
}
}
spin_lock_irqsave(&device_domain_lock, flags);
if (dev)
found = find_domain(dev);
if (!found) {
struct device_domain_info *info2;
info2 = dmar_search_domain_by_dev_info(iommu->segment, bus, devfn);
if (info2) {
found = info2->domain;
info2->dev = dev;
}
}
if (found) {
spin_unlock_irqrestore(&device_domain_lock, flags);
free_devinfo_mem(info);
return found;
}
spin_lock(&iommu->lock);
ret = domain_attach_iommu(domain, iommu);
spin_unlock(&iommu->lock);
if (ret) {
spin_unlock_irqrestore(&device_domain_lock, flags);
free_devinfo_mem(info);
return NULL;
}
list_add(&info->link, &domain->devices);
list_add(&info->global, &device_domain_list);
if (dev)
dev->archdata.iommu = info;
spin_unlock_irqrestore(&device_domain_lock, flags);
if (dev && domain_context_mapping(domain, dev)) {
pr_err("Domain context map for %s failed\n", dev_name(dev));
dmar_remove_one_dev_info(domain, dev);
return NULL;
}
return domain;
}
static int get_last_alias(struct pci_dev *pdev, u16 alias, void *opaque)
{
*(u16 *)opaque = alias;
return 0;
}
static struct dmar_domain *get_domain_for_dev(struct device *dev, int gaw)
{
struct device_domain_info *info = NULL;
struct dmar_domain *domain, *tmp;
struct intel_iommu *iommu;
u16 req_id, dma_alias;
unsigned long flags;
u8 bus, devfn;
domain = find_domain(dev);
if (domain)
return domain;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return NULL;
req_id = ((u16)bus << 8) | devfn;
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
if (domain_init(domain, iommu, gaw)) {
domain_exit(domain);
return NULL;
}
if (dev_is_pci(dev) && req_id != dma_alias) {
tmp = dmar_insert_one_dev_info(iommu, PCI_BUS_NUM(dma_alias),
dma_alias & 0xff, NULL, domain);
if (!tmp || tmp != domain) {
domain_exit(domain);
domain = tmp;
}
if (!domain)
return NULL;
}
found_domain:
tmp = dmar_insert_one_dev_info(iommu, bus, devfn, dev, domain);
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
pr_err("Reserving iova failed\n");
return -ENOMEM;
}
pr_debug("Mapping reserved region %llx-%llx\n", start, end);
dma_pte_clear_range(domain, first_vpfn, last_vpfn);
return domain_pfn_mapping(domain, first_vpfn, first_vpfn,
last_vpfn - first_vpfn + 1,
DMA_PTE_READ|DMA_PTE_WRITE);
}
static int domain_prepare_identity_map(struct device *dev,
struct dmar_domain *domain,
unsigned long long start,
unsigned long long end)
{
if (domain == si_domain && hw_pass_through) {
pr_warn("Ignoring identity map for HW passthrough device %s [0x%Lx - 0x%Lx]\n",
dev_name(dev), start, end);
return 0;
}
pr_info("Setting identity map for device %s [0x%Lx - 0x%Lx]\n",
dev_name(dev), start, end);
if (end < start) {
WARN(1, "Your BIOS is broken; RMRR ends before it starts!\n"
"BIOS vendor: %s; Ver: %s; Product Version: %s\n",
dmi_get_system_info(DMI_BIOS_VENDOR),
dmi_get_system_info(DMI_BIOS_VERSION),
dmi_get_system_info(DMI_PRODUCT_VERSION));
return -EIO;
}
if (end >> agaw_to_width(domain->agaw)) {
WARN(1, "Your BIOS is broken; RMRR exceeds permitted address width (%d bits)\n"
"BIOS vendor: %s; Ver: %s; Product Version: %s\n",
agaw_to_width(domain->agaw),
dmi_get_system_info(DMI_BIOS_VENDOR),
dmi_get_system_info(DMI_BIOS_VERSION),
dmi_get_system_info(DMI_PRODUCT_VERSION));
return -EIO;
}
return iommu_domain_identity_map(domain, start, end);
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
ret = domain_prepare_identity_map(dev, domain, start, end);
if (ret)
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
pr_info("Prepare 0-16MiB unity mapping for LPC\n");
ret = iommu_prepare_identity_map(&pdev->dev, 0, 16*1024*1024 - 1);
if (ret)
pr_err("Failed to create 0-16MiB identity map - floppy might not work\n");
pci_dev_put(pdev);
}
static inline void iommu_prepare_isa(void)
{
return;
}
static int __init si_domain_init(int hw)
{
int nid, ret = 0;
si_domain = alloc_domain(DOMAIN_FLAG_STATIC_IDENTITY);
if (!si_domain)
return -EFAULT;
if (md_domain_init(si_domain, DEFAULT_DOMAIN_ADDRESS_WIDTH)) {
domain_exit(si_domain);
return -EFAULT;
}
pr_debug("Identity mapping domain allocated\n");
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
static int domain_add_dev_info(struct dmar_domain *domain, struct device *dev)
{
struct dmar_domain *ndomain;
struct intel_iommu *iommu;
u8 bus, devfn;
iommu = device_to_iommu(dev, &bus, &devfn);
if (!iommu)
return -ENODEV;
ndomain = dmar_insert_one_dev_info(iommu, bus, devfn, dev, domain);
if (ndomain != domain)
return -EBUSY;
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
if (IS_USB_DEVICE(pdev) || IS_GFX_DEVICE(pdev))
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
ret = domain_add_dev_info(si_domain, dev);
if (!ret)
pr_info("%s identity mapping for device %s\n",
hw ? "Hardware" : "Software", dev_name(dev));
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
pr_info("%s: Using Register based invalidation\n",
iommu->name);
} else {
iommu->flush.flush_context = qi_flush_context;
iommu->flush.flush_iotlb = qi_flush_iotlb;
pr_info("%s: Using Queued invalidation\n", iommu->name);
}
}
static int copy_context_table(struct intel_iommu *iommu,
struct root_entry *old_re,
struct context_entry **tbl,
int bus, bool ext)
{
int tbl_idx, pos = 0, idx, devfn, ret = 0, did;
struct context_entry *new_ce = NULL, ce;
struct context_entry *old_ce = NULL;
struct root_entry re;
phys_addr_t old_ce_phys;
tbl_idx = ext ? bus * 2 : bus;
memcpy(&re, old_re, sizeof(re));
for (devfn = 0; devfn < 256; devfn++) {
idx = (ext ? devfn * 2 : devfn) % 256;
if (idx == 0) {
if (new_ce) {
tbl[tbl_idx] = new_ce;
__iommu_flush_cache(iommu, new_ce,
VTD_PAGE_SIZE);
pos = 1;
}
if (old_ce)
iounmap(old_ce);
ret = 0;
if (devfn < 0x80)
old_ce_phys = root_entry_lctp(&re);
else
old_ce_phys = root_entry_uctp(&re);
if (!old_ce_phys) {
if (ext && devfn == 0) {
devfn = 0x7f;
continue;
} else {
goto out;
}
}
ret = -ENOMEM;
old_ce = memremap(old_ce_phys, PAGE_SIZE,
MEMREMAP_WB);
if (!old_ce)
goto out;
new_ce = alloc_pgtable_page(iommu->node);
if (!new_ce)
goto out_unmap;
ret = 0;
}
memcpy(&ce, old_ce + idx, sizeof(ce));
if (!__context_present(&ce))
continue;
did = context_domain_id(&ce);
if (did >= 0 && did < cap_ndoms(iommu->cap))
set_bit(did, iommu->domain_ids);
context_clear_pasid_enable(&ce);
context_set_copied(&ce);
new_ce[idx] = ce;
}
tbl[tbl_idx + pos] = new_ce;
__iommu_flush_cache(iommu, new_ce, VTD_PAGE_SIZE);
out_unmap:
memunmap(old_ce);
out:
return ret;
}
static int copy_translation_tables(struct intel_iommu *iommu)
{
struct context_entry **ctxt_tbls;
struct root_entry *old_rt;
phys_addr_t old_rt_phys;
int ctxt_table_entries;
unsigned long flags;
u64 rtaddr_reg;
int bus, ret;
bool new_ext, ext;
rtaddr_reg = dmar_readq(iommu->reg + DMAR_RTADDR_REG);
ext = !!(rtaddr_reg & DMA_RTADDR_RTT);
new_ext = !!ecap_ecs(iommu->ecap);
if (new_ext != ext)
return -EINVAL;
old_rt_phys = rtaddr_reg & VTD_PAGE_MASK;
if (!old_rt_phys)
return -EINVAL;
old_rt = memremap(old_rt_phys, PAGE_SIZE, MEMREMAP_WB);
if (!old_rt)
return -ENOMEM;
ctxt_table_entries = ext ? 512 : 256;
ret = -ENOMEM;
ctxt_tbls = kzalloc(ctxt_table_entries * sizeof(void *), GFP_KERNEL);
if (!ctxt_tbls)
goto out_unmap;
for (bus = 0; bus < 256; bus++) {
ret = copy_context_table(iommu, &old_rt[bus],
ctxt_tbls, bus, ext);
if (ret) {
pr_err("%s: Failed to copy context table for bus %d\n",
iommu->name, bus);
continue;
}
}
spin_lock_irqsave(&iommu->lock, flags);
for (bus = 0; bus < 256; bus++) {
int idx = ext ? bus * 2 : bus;
u64 val;
if (ctxt_tbls[idx]) {
val = virt_to_phys(ctxt_tbls[idx]) | 1;
iommu->root_entry[bus].lo = val;
}
if (!ext || !ctxt_tbls[idx + 1])
continue;
val = virt_to_phys(ctxt_tbls[idx + 1]) | 1;
iommu->root_entry[bus].hi = val;
}
spin_unlock_irqrestore(&iommu->lock, flags);
kfree(ctxt_tbls);
__iommu_flush_cache(iommu, iommu->root_entry, PAGE_SIZE);
ret = 0;
out_unmap:
memunmap(old_rt);
return ret;
}
static int __init init_dmars(void)
{
struct dmar_drhd_unit *drhd;
struct dmar_rmrr_unit *rmrr;
bool copied_tables = false;
struct device *dev;
struct intel_iommu *iommu;
int i, ret, cpu;
for_each_drhd_unit(drhd) {
if (g_num_of_iommus < DMAR_UNITS_SUPPORTED) {
g_num_of_iommus++;
continue;
}
pr_err_once("Exceeded %d IOMMUs\n", DMAR_UNITS_SUPPORTED);
}
if (g_num_of_iommus < DMAR_UNITS_SUPPORTED)
g_num_of_iommus = DMAR_UNITS_SUPPORTED;
g_iommus = kcalloc(g_num_of_iommus, sizeof(struct intel_iommu *),
GFP_KERNEL);
if (!g_iommus) {
pr_err("Allocating global iommu array failed\n");
ret = -ENOMEM;
goto error;
}
for_each_possible_cpu(cpu) {
struct deferred_flush_data *dfd = per_cpu_ptr(&deferred_flush,
cpu);
dfd->tables = kzalloc(g_num_of_iommus *
sizeof(struct deferred_flush_table),
GFP_KERNEL);
if (!dfd->tables) {
ret = -ENOMEM;
goto free_g_iommus;
}
spin_lock_init(&dfd->lock);
setup_timer(&dfd->timer, flush_unmaps_timeout, cpu);
}
for_each_active_iommu(iommu, drhd) {
g_iommus[iommu->seq_id] = iommu;
intel_iommu_init_qi(iommu);
ret = iommu_init_domains(iommu);
if (ret)
goto free_iommu;
init_translation_status(iommu);
if (translation_pre_enabled(iommu) && !is_kdump_kernel()) {
iommu_disable_translation(iommu);
clear_translation_pre_enabled(iommu);
pr_warn("Translation was enabled for %s but we are not in kdump mode\n",
iommu->name);
}
ret = iommu_alloc_root_entry(iommu);
if (ret)
goto free_iommu;
if (translation_pre_enabled(iommu)) {
pr_info("Translation already enabled - trying to copy translation structures\n");
ret = copy_translation_tables(iommu);
if (ret) {
pr_err("Failed to copy translation tables from previous kernel for %s\n",
iommu->name);
iommu_disable_translation(iommu);
clear_translation_pre_enabled(iommu);
} else {
pr_info("Copied translation tables from previous kernel for %s\n",
iommu->name);
copied_tables = true;
}
}
if (!ecap_pass_through(iommu->ecap))
hw_pass_through = 0;
#ifdef CONFIG_INTEL_IOMMU_SVM
if (pasid_enabled(iommu))
intel_svm_alloc_pasid_tables(iommu);
#endif
}
for_each_active_iommu(iommu, drhd) {
iommu_flush_write_buffer(iommu);
iommu_set_root_entry(iommu);
iommu->flush.flush_context(iommu, 0, 0, 0, DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0, DMA_TLB_GLOBAL_FLUSH);
}
if (iommu_pass_through)
iommu_identity_mapping |= IDENTMAP_ALL;
#ifdef CONFIG_INTEL_IOMMU_BROKEN_GFX_WA
iommu_identity_mapping |= IDENTMAP_GFX;
#endif
if (iommu_identity_mapping) {
ret = si_domain_init(hw_pass_through);
if (ret)
goto free_iommu;
}
check_tylersburg_isoch();
if (copied_tables)
goto domains_done;
if (iommu_identity_mapping) {
ret = iommu_prepare_static_identity_mapping(hw_pass_through);
if (ret) {
pr_crit("Failed to setup IOMMU pass-through\n");
goto free_iommu;
}
}
pr_info("Setting RMRR:\n");
for_each_rmrr_units(rmrr) {
for_each_active_dev_scope(rmrr->devices, rmrr->devices_cnt,
i, dev) {
ret = iommu_prepare_rmrr_dev(rmrr, dev);
if (ret)
pr_err("Mapping reserved region failed\n");
}
}
iommu_prepare_isa();
domains_done:
for_each_iommu(iommu, drhd) {
if (drhd->ignored) {
if (force_on)
iommu_disable_protect_mem_regions(iommu);
continue;
}
iommu_flush_write_buffer(iommu);
#ifdef CONFIG_INTEL_IOMMU_SVM
if (pasid_enabled(iommu) && ecap_prs(iommu->ecap)) {
ret = intel_svm_enable_prq(iommu);
if (ret)
goto free_iommu;
}
#endif
ret = dmar_set_interrupt(iommu);
if (ret)
goto free_iommu;
if (!translation_pre_enabled(iommu))
iommu_enable_translation(iommu);
iommu_disable_protect_mem_regions(iommu);
}
return 0;
free_iommu:
for_each_active_iommu(iommu, drhd) {
disable_dmar_iommu(iommu);
free_dmar_iommu(iommu);
}
free_g_iommus:
for_each_possible_cpu(cpu)
kfree(per_cpu_ptr(&deferred_flush, cpu)->tables);
kfree(g_iommus);
error:
return ret;
}
static unsigned long intel_alloc_iova(struct device *dev,
struct dmar_domain *domain,
unsigned long nrpages, uint64_t dma_mask)
{
unsigned long iova_pfn = 0;
dma_mask = min_t(uint64_t, DOMAIN_MAX_ADDR(domain->gaw), dma_mask);
nrpages = __roundup_pow_of_two(nrpages);
if (!dmar_forcedac && dma_mask > DMA_BIT_MASK(32)) {
iova_pfn = alloc_iova_fast(&domain->iovad, nrpages,
IOVA_PFN(DMA_BIT_MASK(32)));
if (iova_pfn)
return iova_pfn;
}
iova_pfn = alloc_iova_fast(&domain->iovad, nrpages, IOVA_PFN(dma_mask));
if (unlikely(!iova_pfn)) {
pr_err("Allocating %ld-page iova for %s failed",
nrpages, dev_name(dev));
return 0;
}
return iova_pfn;
}
static struct dmar_domain *__get_valid_domain_for_dev(struct device *dev)
{
struct dmar_rmrr_unit *rmrr;
struct dmar_domain *domain;
struct device *i_dev;
int i, ret;
domain = get_domain_for_dev(dev, DEFAULT_DOMAIN_ADDRESS_WIDTH);
if (!domain) {
pr_err("Allocating domain for %s failed\n",
dev_name(dev));
return NULL;
}
rcu_read_lock();
for_each_rmrr_units(rmrr) {
for_each_active_dev_scope(rmrr->devices, rmrr->devices_cnt,
i, i_dev) {
if (i_dev != dev)
continue;
ret = domain_prepare_identity_map(dev, domain,
rmrr->base_address,
rmrr->end_address);
if (ret)
dev_err(dev, "Mapping reserved region failed\n");
}
}
rcu_read_unlock();
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
dmar_remove_one_dev_info(si_domain, dev);
pr_info("32bit %s uses non-identity mapping\n",
dev_name(dev));
return 0;
}
} else {
if (iommu_should_identity_map(dev, 0)) {
int ret;
ret = domain_add_dev_info(si_domain, dev);
if (!ret) {
pr_info("64bit %s uses identity mapping\n",
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
unsigned long iova_pfn;
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
iova_pfn = intel_alloc_iova(dev, domain, dma_to_mm_pfn(size), dma_mask);
if (!iova_pfn)
goto error;
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL || \
!cap_zlr(iommu->cap))
prot |= DMA_PTE_READ;
if (dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL)
prot |= DMA_PTE_WRITE;
ret = domain_pfn_mapping(domain, mm_to_dma_pfn(iova_pfn),
mm_to_dma_pfn(paddr_pfn), size, prot);
if (ret)
goto error;
if (cap_caching_mode(iommu->cap))
iommu_flush_iotlb_psi(iommu, domain,
mm_to_dma_pfn(iova_pfn),
size, 0, 1);
else
iommu_flush_write_buffer(iommu);
start_paddr = (phys_addr_t)iova_pfn << PAGE_SHIFT;
start_paddr += paddr & ~PAGE_MASK;
return start_paddr;
error:
if (iova_pfn)
free_iova_fast(&domain->iovad, iova_pfn, dma_to_mm_pfn(size));
pr_err("Device %s request: %zx@%llx dir %d --- failed\n",
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
static void flush_unmaps(struct deferred_flush_data *flush_data)
{
int i, j;
flush_data->timer_on = 0;
for (i = 0; i < g_num_of_iommus; i++) {
struct intel_iommu *iommu = g_iommus[i];
struct deferred_flush_table *flush_table =
&flush_data->tables[i];
if (!iommu)
continue;
if (!flush_table->next)
continue;
if (!cap_caching_mode(iommu->cap))
iommu->flush.flush_iotlb(iommu, 0, 0, 0,
DMA_TLB_GLOBAL_FLUSH);
for (j = 0; j < flush_table->next; j++) {
unsigned long mask;
struct deferred_flush_entry *entry =
&flush_table->entries[j];
unsigned long iova_pfn = entry->iova_pfn;
unsigned long nrpages = entry->nrpages;
struct dmar_domain *domain = entry->domain;
struct page *freelist = entry->freelist;
if (cap_caching_mode(iommu->cap))
iommu_flush_iotlb_psi(iommu, domain,
mm_to_dma_pfn(iova_pfn),
nrpages, !freelist, 0);
else {
mask = ilog2(nrpages);
iommu_flush_dev_iotlb(domain,
(uint64_t)iova_pfn << PAGE_SHIFT, mask);
}
free_iova_fast(&domain->iovad, iova_pfn, nrpages);
if (freelist)
dma_free_pagelist(freelist);
}
flush_table->next = 0;
}
flush_data->size = 0;
}
static void flush_unmaps_timeout(unsigned long cpuid)
{
struct deferred_flush_data *flush_data = per_cpu_ptr(&deferred_flush, cpuid);
unsigned long flags;
spin_lock_irqsave(&flush_data->lock, flags);
flush_unmaps(flush_data);
spin_unlock_irqrestore(&flush_data->lock, flags);
}
static void add_unmap(struct dmar_domain *dom, unsigned long iova_pfn,
unsigned long nrpages, struct page *freelist)
{
unsigned long flags;
int entry_id, iommu_id;
struct intel_iommu *iommu;
struct deferred_flush_entry *entry;
struct deferred_flush_data *flush_data;
unsigned int cpuid;
cpuid = get_cpu();
flush_data = per_cpu_ptr(&deferred_flush, cpuid);
if (flush_data->size == HIGH_WATER_MARK) {
int cpu;
for_each_online_cpu(cpu)
flush_unmaps_timeout(cpu);
}
spin_lock_irqsave(&flush_data->lock, flags);
iommu = domain_get_iommu(dom);
iommu_id = iommu->seq_id;
entry_id = flush_data->tables[iommu_id].next;
++(flush_data->tables[iommu_id].next);
entry = &flush_data->tables[iommu_id].entries[entry_id];
entry->domain = dom;
entry->iova_pfn = iova_pfn;
entry->nrpages = nrpages;
entry->freelist = freelist;
if (!flush_data->timer_on) {
mod_timer(&flush_data->timer, jiffies + msecs_to_jiffies(10));
flush_data->timer_on = 1;
}
flush_data->size++;
spin_unlock_irqrestore(&flush_data->lock, flags);
put_cpu();
}
static void intel_unmap(struct device *dev, dma_addr_t dev_addr, size_t size)
{
struct dmar_domain *domain;
unsigned long start_pfn, last_pfn;
unsigned long nrpages;
unsigned long iova_pfn;
struct intel_iommu *iommu;
struct page *freelist;
if (iommu_no_mapping(dev))
return;
domain = find_domain(dev);
BUG_ON(!domain);
iommu = domain_get_iommu(domain);
iova_pfn = IOVA_PFN(dev_addr);
nrpages = aligned_nrpages(dev_addr, size);
start_pfn = mm_to_dma_pfn(iova_pfn);
last_pfn = start_pfn + nrpages - 1;
pr_debug("Device %s unmapping: pfn %lx-%lx\n",
dev_name(dev), start_pfn, last_pfn);
freelist = domain_unmap(domain, start_pfn, last_pfn);
if (intel_iommu_strict) {
iommu_flush_iotlb_psi(iommu, domain, start_pfn,
nrpages, !freelist, 0);
free_iova_fast(&domain->iovad, iova_pfn, dma_to_mm_pfn(nrpages));
dma_free_pagelist(freelist);
} else {
add_unmap(domain, iova_pfn, nrpages, freelist);
}
}
static void intel_unmap_page(struct device *dev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
intel_unmap(dev, dev_addr, size);
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
if (gfpflags_allow_blocking(flags)) {
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
intel_unmap(dev, dma_handle, size);
if (!dma_release_from_contiguous(dev, page, size >> PAGE_SHIFT))
__free_pages(page, order);
}
static void intel_unmap_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
dma_addr_t startaddr = sg_dma_address(sglist) & PAGE_MASK;
unsigned long nrpages = 0;
struct scatterlist *sg;
int i;
for_each_sg(sglist, sg, nelems, i) {
nrpages += aligned_nrpages(sg_dma_address(sg), sg_dma_len(sg));
}
intel_unmap(dev, startaddr, nrpages << VTD_PAGE_SHIFT);
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
unsigned long iova_pfn;
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
iova_pfn = intel_alloc_iova(dev, domain, dma_to_mm_pfn(size),
*dev->dma_mask);
if (!iova_pfn) {
sglist->dma_length = 0;
return 0;
}
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL || \
!cap_zlr(iommu->cap))
prot |= DMA_PTE_READ;
if (dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL)
prot |= DMA_PTE_WRITE;
start_vpfn = mm_to_dma_pfn(iova_pfn);
ret = domain_sg_mapping(domain, start_vpfn, sglist, size, prot);
if (unlikely(ret)) {
dma_pte_free_pagetable(domain, start_vpfn,
start_vpfn + size - 1);
free_iova_fast(&domain->iovad, iova_pfn, dma_to_mm_pfn(size));
return 0;
}
if (cap_caching_mode(iommu->cap))
iommu_flush_iotlb_psi(iommu, domain, start_vpfn, size, 0, 1);
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
pr_err("Couldn't create iommu_domain cache\n");
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
pr_err("Couldn't create devinfo cache\n");
ret = -ENOMEM;
}
return ret;
}
static int __init iommu_init_mempool(void)
{
int ret;
ret = iova_cache_get();
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
iova_cache_put();
return -ENOMEM;
}
static void __init iommu_exit_mempool(void)
{
kmem_cache_destroy(iommu_devinfo_cache);
kmem_cache_destroy(iommu_domain_cache);
iova_cache_put();
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
pr_warn("%s: Doesn't support hardware pass through.\n",
iommu->name);
return -ENXIO;
}
if (!ecap_sc_support(iommu->ecap) &&
domain_update_iommu_snooping(iommu)) {
pr_warn("%s: Doesn't support snooping.\n",
iommu->name);
return -ENXIO;
}
sp = domain_update_iommu_superpage(iommu) - 1;
if (sp >= 0 && !(cap_super_page_val(iommu->cap) & (1 << sp))) {
pr_warn("%s: Doesn't support large page.\n",
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
#ifdef CONFIG_INTEL_IOMMU_SVM
if (pasid_enabled(iommu))
intel_svm_alloc_pasid_tables(iommu);
#endif
if (dmaru->ignored) {
if (force_on)
iommu_disable_protect_mem_regions(iommu);
return 0;
}
intel_iommu_init_qi(iommu);
iommu_flush_write_buffer(iommu);
#ifdef CONFIG_INTEL_IOMMU_SVM
if (pasid_enabled(iommu) && ecap_prs(iommu->ecap)) {
ret = intel_svm_enable_prq(iommu);
if (ret)
goto disable_iommu;
}
#endif
ret = dmar_set_interrupt(iommu);
if (ret)
goto disable_iommu;
iommu_set_root_entry(iommu);
iommu->flush.flush_context(iommu, 0, 0, 0, DMA_CCMD_GLOBAL_INVL);
iommu->flush.flush_iotlb(iommu, 0, 0, 0, DMA_TLB_GLOBAL_FLUSH);
iommu_enable_translation(iommu);
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
if (!bridge)
return 1;
if (!pci_is_pcie(bridge) ||
pci_pcie_type(bridge) == PCI_EXP_TYPE_PCI_BRIDGE)
return 0;
if (pci_pcie_type(bridge) == PCI_EXP_TYPE_ROOT_PORT)
break;
}
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
} else if (info->event == BUS_NOTIFY_REMOVED_DEVICE) {
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
} else if (info->event == BUS_NOTIFY_REMOVED_DEVICE) {
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
dmar_remove_one_dev_info(domain, dev);
if (!domain_type_is_vm_or_si(domain) && list_empty(&domain->devices))
domain_exit(domain);
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
pr_warn("Failed to build identity map for [%llx-%llx]\n",
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
pr_debug("Failed get IOVA for PFN %lx\n",
start_vpfn);
break;
}
iova = split_and_remove_iova(&si_domain->iovad, iova,
start_vpfn, last_vpfn);
if (iova == NULL) {
pr_warn("Failed to split IOVA PFN [%lx-%lx]\n",
start_vpfn, last_vpfn);
return NOTIFY_BAD;
}
freelist = domain_unmap(si_domain, iova->pfn_lo,
iova->pfn_hi);
rcu_read_lock();
for_each_active_iommu(iommu, drhd)
iommu_flush_iotlb_psi(iommu, si_domain,
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
static void free_all_cpu_cached_iovas(unsigned int cpu)
{
int i;
for (i = 0; i < g_num_of_iommus; i++) {
struct intel_iommu *iommu = g_iommus[i];
struct dmar_domain *domain;
int did;
if (!iommu)
continue;
for (did = 0; did < cap_ndoms(iommu->cap); did++) {
domain = get_iommu_domain(iommu, (u16)did);
if (!domain)
continue;
free_cpu_cached_iovas(cpu, &domain->iovad);
}
}
}
static int intel_iommu_cpu_notifier(struct notifier_block *nfb,
unsigned long action, void *v)
{
unsigned int cpu = (unsigned long)v;
switch (action) {
case CPU_DEAD:
case CPU_DEAD_FROZEN:
free_all_cpu_cached_iovas(cpu);
flush_unmaps_timeout(cpu);
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
static ssize_t intel_iommu_show_ndoms(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct intel_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%ld\n", cap_ndoms(iommu->cap));
}
static ssize_t intel_iommu_show_ndoms_used(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct intel_iommu *iommu = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", bitmap_weight(iommu->domain_ids,
cap_ndoms(iommu->cap)));
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
if (dmar_dev_scope_init() < 0) {
if (force_on)
panic("tboot: Failed to initialize DMAR device scope\n");
goto out_free_dmar;
}
if (no_iommu || dmar_disabled)
goto out_free_dmar;
if (list_empty(&dmar_rmrr_units))
pr_info("No RMRR found\n");
if (list_empty(&dmar_atsr_units))
pr_info("No ATSR found\n");
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
pr_err("Initialization failed\n");
goto out_free_reserved_range;
}
up_write(&dmar_global_lock);
pr_info("Intel(R) Virtualization Technology for Directed I/O\n");
#ifdef CONFIG_SWIOTLB
swiotlb = 0;
#endif
dma_ops = &intel_dma_ops;
init_iommu_pm_ops();
for_each_active_iommu(iommu, drhd)
iommu->iommu_dev = iommu_device_create(NULL, iommu,
intel_iommu_groups,
"%s", iommu->name);
bus_set_iommu(&pci_bus_type, &intel_iommu_ops);
bus_register_notifier(&pci_bus_type, &device_nb);
if (si_domain && !hw_pass_through)
register_memory_notifier(&intel_iommu_memory_nb);
register_hotcpu_notifier(&intel_iommu_cpu_nb);
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
static int domain_context_clear_one_cb(struct pci_dev *pdev, u16 alias, void *opaque)
{
struct intel_iommu *iommu = opaque;
domain_context_clear_one(iommu, PCI_BUS_NUM(alias), alias & 0xff);
return 0;
}
static void domain_context_clear(struct intel_iommu *iommu, struct device *dev)
{
if (!iommu || !dev || !dev_is_pci(dev))
return;
pci_for_each_dma_alias(to_pci_dev(dev), &domain_context_clear_one_cb, iommu);
}
static void __dmar_remove_one_dev_info(struct device_domain_info *info)
{
struct intel_iommu *iommu;
unsigned long flags;
assert_spin_locked(&device_domain_lock);
if (WARN_ON(!info))
return;
iommu = info->iommu;
if (info->dev) {
iommu_disable_dev_iotlb(info);
domain_context_clear(iommu, info->dev);
}
unlink_domain_info(info);
spin_lock_irqsave(&iommu->lock, flags);
domain_detach_iommu(info->domain, iommu);
spin_unlock_irqrestore(&iommu->lock, flags);
free_devinfo_mem(info);
}
static void dmar_remove_one_dev_info(struct dmar_domain *domain,
struct device *dev)
{
struct device_domain_info *info;
unsigned long flags;
spin_lock_irqsave(&device_domain_lock, flags);
info = dev->archdata.iommu;
__dmar_remove_one_dev_info(info);
spin_unlock_irqrestore(&device_domain_lock, flags);
}
static int md_domain_init(struct dmar_domain *domain, int guest_width)
{
int adjust_width;
init_iova_domain(&domain->iovad, VTD_PAGE_SIZE, IOVA_START_PFN,
DMA_32BIT_PFN);
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
static struct iommu_domain *intel_iommu_domain_alloc(unsigned type)
{
struct dmar_domain *dmar_domain;
struct iommu_domain *domain;
if (type != IOMMU_DOMAIN_UNMANAGED)
return NULL;
dmar_domain = alloc_domain(DOMAIN_FLAG_VIRTUAL_MACHINE);
if (!dmar_domain) {
pr_err("Can't allocate dmar_domain\n");
return NULL;
}
if (md_domain_init(dmar_domain, DEFAULT_DOMAIN_ADDRESS_WIDTH)) {
pr_err("Domain initialization failed\n");
domain_exit(dmar_domain);
return NULL;
}
domain_update_iommu_cap(dmar_domain);
domain = &dmar_domain->domain;
domain->geometry.aperture_start = 0;
domain->geometry.aperture_end = __DOMAIN_MAX_ADDR(dmar_domain->gaw);
domain->geometry.force_aperture = true;
return domain;
}
static void intel_iommu_domain_free(struct iommu_domain *domain)
{
domain_exit(to_dmar_domain(domain));
}
static int intel_iommu_attach_device(struct iommu_domain *domain,
struct device *dev)
{
struct dmar_domain *dmar_domain = to_dmar_domain(domain);
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
rcu_read_lock();
dmar_remove_one_dev_info(old_domain, dev);
rcu_read_unlock();
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
pr_err("%s: iommu width (%d) is not "
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
return domain_add_dev_info(dmar_domain, dev);
}
static void intel_iommu_detach_device(struct iommu_domain *domain,
struct device *dev)
{
dmar_remove_one_dev_info(to_dmar_domain(domain), dev);
}
static int intel_iommu_map(struct iommu_domain *domain,
unsigned long iova, phys_addr_t hpa,
size_t size, int iommu_prot)
{
struct dmar_domain *dmar_domain = to_dmar_domain(domain);
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
pr_err("%s: iommu width (%d) is not "
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
struct dmar_domain *dmar_domain = to_dmar_domain(domain);
struct page *freelist = NULL;
struct intel_iommu *iommu;
unsigned long start_pfn, last_pfn;
unsigned int npages;
int iommu_id, level = 0;
BUG_ON(!pfn_to_dma_pte(dmar_domain, iova >> VTD_PAGE_SHIFT, &level));
if (size < VTD_PAGE_SIZE << level_to_offset_bits(level))
size = VTD_PAGE_SIZE << level_to_offset_bits(level);
start_pfn = iova >> VTD_PAGE_SHIFT;
last_pfn = (iova + size - 1) >> VTD_PAGE_SHIFT;
freelist = domain_unmap(dmar_domain, start_pfn, last_pfn);
npages = last_pfn - start_pfn + 1;
for_each_domain_iommu(iommu_id, dmar_domain) {
iommu = g_iommus[iommu_id];
iommu_flush_iotlb_psi(g_iommus[iommu_id], dmar_domain,
start_pfn, npages, !freelist, 0);
}
dma_free_pagelist(freelist);
if (dmar_domain->max_addr == iova + size)
dmar_domain->max_addr = iova;
return size;
}
static phys_addr_t intel_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
struct dmar_domain *dmar_domain = to_dmar_domain(domain);
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
int intel_iommu_enable_pasid(struct intel_iommu *iommu, struct intel_svm_dev *sdev)
{
struct device_domain_info *info;
struct context_entry *context;
struct dmar_domain *domain;
unsigned long flags;
u64 ctx_lo;
int ret;
domain = get_valid_domain_for_dev(sdev->dev);
if (!domain)
return -EINVAL;
spin_lock_irqsave(&device_domain_lock, flags);
spin_lock(&iommu->lock);
ret = -EINVAL;
info = sdev->dev->archdata.iommu;
if (!info || !info->pasid_supported)
goto out;
context = iommu_context_addr(iommu, info->bus, info->devfn, 0);
if (WARN_ON(!context))
goto out;
ctx_lo = context[0].lo;
sdev->did = domain->iommu_did[iommu->seq_id];
sdev->sid = PCI_DEVID(info->bus, info->devfn);
if (!(ctx_lo & CONTEXT_PASIDE)) {
context[1].hi = (u64)virt_to_phys(iommu->pasid_state_table);
context[1].lo = (u64)virt_to_phys(iommu->pasid_table) | ecap_pss(iommu->ecap);
wmb();
if ((ctx_lo & CONTEXT_TT_MASK) == (CONTEXT_TT_PASS_THROUGH << 2)) {
ctx_lo &= ~CONTEXT_TT_MASK;
if (info->ats_supported)
ctx_lo |= CONTEXT_TT_PT_PASID_DEV_IOTLB << 2;
else
ctx_lo |= CONTEXT_TT_PT_PASID << 2;
}
ctx_lo |= CONTEXT_PASIDE;
if (iommu->pasid_state_table)
ctx_lo |= CONTEXT_DINVE;
if (info->pri_supported)
ctx_lo |= CONTEXT_PRS;
context[0].lo = ctx_lo;
wmb();
iommu->flush.flush_context(iommu, sdev->did, sdev->sid,
DMA_CCMD_MASK_NOBIT,
DMA_CCMD_DEVICE_INVL);
}
if (!info->pasid_enabled)
iommu_enable_dev_iotlb(info);
if (info->ats_enabled) {
sdev->dev_iotlb = 1;
sdev->qdep = info->ats_qdep;
if (sdev->qdep >= QI_DEV_EIOTLB_MAX_INVS)
sdev->qdep = 0;
}
ret = 0;
out:
spin_unlock(&iommu->lock);
spin_unlock_irqrestore(&device_domain_lock, flags);
return ret;
}
struct intel_iommu *intel_svm_device_to_iommu(struct device *dev)
{
struct intel_iommu *iommu;
u8 bus, devfn;
if (iommu_dummy(dev)) {
dev_warn(dev,
"No IOMMU translation for device; cannot enable SVM\n");
return NULL;
}
iommu = device_to_iommu(dev, &bus, &devfn);
if ((!iommu)) {
dev_err(dev, "No IOMMU for device; cannot enable SVM\n");
return NULL;
}
if (!iommu->pasid_table) {
dev_err(dev, "PASID not enabled on IOMMU; cannot enable SVM\n");
return NULL;
}
return iommu;
}
static void quirk_iommu_g4x_gfx(struct pci_dev *dev)
{
pr_info("Disabling IOMMU for graphics on this chipset\n");
dmar_map_gfx = 0;
}
static void quirk_iommu_rwbf(struct pci_dev *dev)
{
pr_info("Forcing write-buffer flush capability\n");
rwbf_quirk = 1;
}
static void quirk_calpella_no_shadow_gtt(struct pci_dev *dev)
{
unsigned short ggc;
if (pci_read_config_word(dev, GGC, &ggc))
return;
if (!(ggc & GGC_MEMORY_VT_ENABLED)) {
pr_info("BIOS has allocated no shadow GTT; disabling IOMMU for graphics\n");
dmar_map_gfx = 0;
} else if (dmar_map_gfx) {
pr_info("Disabling batched IOTLB flush on Ironlake\n");
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
pr_warn("Recommended TLB entries for ISOCH unit is 16; your BIOS set %d\n",
vtisochctrl);
}
