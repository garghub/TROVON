static bool inline smmu_valid_reg(struct smmu_device *smmu,
void __iomem *addr)
{
int i;
for (i = 0; i < smmu->nregs; i++) {
if (addr < smmu->regs[i])
break;
if (addr <= smmu->rege[i])
return true;
}
return false;
}
static inline u32 smmu_read(struct smmu_device *smmu, size_t offs)
{
void __iomem *addr = smmu->regbase + offs;
BUG_ON(!smmu_valid_reg(smmu, addr));
return readl(addr);
}
static inline void smmu_write(struct smmu_device *smmu, u32 val, size_t offs)
{
void __iomem *addr = smmu->regbase + offs;
BUG_ON(!smmu_valid_reg(smmu, addr));
writel(val, addr);
}
static int __smmu_client_set_hwgrp(struct smmu_client *c,
unsigned long map, int on)
{
int i;
struct smmu_as *as = c->as;
u32 val, offs, mask = SMMU_ASID_ENABLE(as->asid);
struct smmu_device *smmu = as->smmu;
WARN_ON(!on && map);
if (on && !map)
return -EINVAL;
if (!on)
map = smmu_client_hwgrp(c);
for_each_set_bit(i, &map, HWGRP_COUNT) {
offs = HWGRP_ASID_REG(i);
val = smmu_read(smmu, offs);
if (on) {
if (WARN_ON(val & mask))
goto err_hw_busy;
val |= mask;
} else {
WARN_ON((val & mask) == mask);
val &= ~mask;
}
smmu_write(smmu, val, offs);
}
FLUSH_SMMU_REGS(smmu);
c->hwgrp = map;
return 0;
err_hw_busy:
for_each_set_bit(i, &map, HWGRP_COUNT) {
offs = HWGRP_ASID_REG(i);
val = smmu_read(smmu, offs);
val &= ~mask;
smmu_write(smmu, val, offs);
}
return -EBUSY;
}
static int smmu_client_set_hwgrp(struct smmu_client *c, u32 map, int on)
{
u32 val;
unsigned long flags;
struct smmu_as *as = c->as;
struct smmu_device *smmu = as->smmu;
spin_lock_irqsave(&smmu->lock, flags);
val = __smmu_client_set_hwgrp(c, map, on);
spin_unlock_irqrestore(&smmu->lock, flags);
return val;
}
static void smmu_flush_regs(struct smmu_device *smmu, int enable)
{
u32 val;
smmu_write(smmu, SMMU_PTC_FLUSH_TYPE_ALL, SMMU_PTC_FLUSH);
FLUSH_SMMU_REGS(smmu);
val = SMMU_TLB_FLUSH_VA_MATCH_ALL |
SMMU_TLB_FLUSH_ASID_MATCH_disable;
smmu_write(smmu, val, SMMU_TLB_FLUSH);
if (enable)
smmu_write(smmu, SMMU_CONFIG_ENABLE, SMMU_CONFIG);
FLUSH_SMMU_REGS(smmu);
}
static int smmu_setup_regs(struct smmu_device *smmu)
{
int i;
u32 val;
for (i = 0; i < smmu->num_as; i++) {
struct smmu_as *as = &smmu->as[i];
struct smmu_client *c;
smmu_write(smmu, SMMU_PTB_ASID_CUR(as->asid), SMMU_PTB_ASID);
val = as->pdir_page ?
SMMU_MK_PDIR(as->pdir_page, as->pdir_attr) :
SMMU_PTB_DATA_RESET_VAL;
smmu_write(smmu, val, SMMU_PTB_DATA);
list_for_each_entry(c, &as->client, list)
__smmu_client_set_hwgrp(c, c->hwgrp, 1);
}
smmu_write(smmu, smmu->translation_enable_0, SMMU_TRANSLATION_ENABLE_0);
smmu_write(smmu, smmu->translation_enable_1, SMMU_TRANSLATION_ENABLE_1);
smmu_write(smmu, smmu->translation_enable_2, SMMU_TRANSLATION_ENABLE_2);
smmu_write(smmu, smmu->asid_security, SMMU_ASID_SECURITY);
smmu_write(smmu, SMMU_TLB_CONFIG_RESET_VAL, SMMU_CACHE_CONFIG(_TLB));
smmu_write(smmu, SMMU_PTC_CONFIG_RESET_VAL, SMMU_CACHE_CONFIG(_PTC));
smmu_flush_regs(smmu, 1);
return tegra_ahb_enable_smmu(smmu->ahb);
}
static void flush_ptc_and_tlb(struct smmu_device *smmu,
struct smmu_as *as, dma_addr_t iova,
unsigned long *pte, struct page *page, int is_pde)
{
u32 val;
unsigned long tlb_flush_va = is_pde
? SMMU_TLB_FLUSH_VA(iova, SECTION)
: SMMU_TLB_FLUSH_VA(iova, GROUP);
val = SMMU_PTC_FLUSH_TYPE_ADR | VA_PAGE_TO_PA(pte, page);
smmu_write(smmu, val, SMMU_PTC_FLUSH);
FLUSH_SMMU_REGS(smmu);
val = tlb_flush_va |
SMMU_TLB_FLUSH_ASID_MATCH__ENABLE |
(as->asid << SMMU_TLB_FLUSH_ASID_SHIFT);
smmu_write(smmu, val, SMMU_TLB_FLUSH);
FLUSH_SMMU_REGS(smmu);
}
static void free_ptbl(struct smmu_as *as, dma_addr_t iova)
{
unsigned long pdn = SMMU_ADDR_TO_PDN(iova);
unsigned long *pdir = (unsigned long *)page_address(as->pdir_page);
if (pdir[pdn] != _PDE_VACANT(pdn)) {
dev_dbg(as->smmu->dev, "pdn: %lx\n", pdn);
ClearPageReserved(SMMU_EX_PTBL_PAGE(pdir[pdn]));
__free_page(SMMU_EX_PTBL_PAGE(pdir[pdn]));
pdir[pdn] = _PDE_VACANT(pdn);
FLUSH_CPU_DCACHE(&pdir[pdn], as->pdir_page, sizeof pdir[pdn]);
flush_ptc_and_tlb(as->smmu, as, iova, &pdir[pdn],
as->pdir_page, 1);
}
}
static void free_pdir(struct smmu_as *as)
{
unsigned addr;
int count;
struct device *dev = as->smmu->dev;
if (!as->pdir_page)
return;
addr = as->smmu->iovmm_base;
count = as->smmu->page_count;
while (count-- > 0) {
free_ptbl(as, addr);
addr += SMMU_PAGE_SIZE * SMMU_PTBL_COUNT;
}
ClearPageReserved(as->pdir_page);
__free_page(as->pdir_page);
as->pdir_page = NULL;
devm_kfree(dev, as->pte_count);
as->pte_count = NULL;
}
static unsigned long *locate_pte(struct smmu_as *as,
dma_addr_t iova, bool allocate,
struct page **ptbl_page_p,
unsigned int **count)
{
unsigned long ptn = SMMU_ADDR_TO_PFN(iova);
unsigned long pdn = SMMU_ADDR_TO_PDN(iova);
unsigned long *pdir = page_address(as->pdir_page);
unsigned long *ptbl;
if (pdir[pdn] != _PDE_VACANT(pdn)) {
*ptbl_page_p = SMMU_EX_PTBL_PAGE(pdir[pdn]);
ptbl = page_address(*ptbl_page_p);
} else if (!allocate) {
return NULL;
} else {
int pn;
unsigned long addr = SMMU_PDN_TO_ADDR(pdn);
dev_dbg(as->smmu->dev, "New PTBL pdn: %lx\n", pdn);
*ptbl_page_p = alloc_page(GFP_ATOMIC);
if (!*ptbl_page_p) {
dev_err(as->smmu->dev,
"failed to allocate smmu_device page table\n");
return NULL;
}
SetPageReserved(*ptbl_page_p);
ptbl = (unsigned long *)page_address(*ptbl_page_p);
for (pn = 0; pn < SMMU_PTBL_COUNT;
pn++, addr += SMMU_PAGE_SIZE) {
ptbl[pn] = _PTE_VACANT(addr);
}
FLUSH_CPU_DCACHE(ptbl, *ptbl_page_p, SMMU_PTBL_SIZE);
pdir[pdn] = SMMU_MK_PDE(*ptbl_page_p,
as->pde_attr | _PDE_NEXT);
FLUSH_CPU_DCACHE(&pdir[pdn], as->pdir_page, sizeof pdir[pdn]);
flush_ptc_and_tlb(as->smmu, as, iova, &pdir[pdn],
as->pdir_page, 1);
}
*count = &as->pte_count[pdn];
return &ptbl[ptn % SMMU_PTBL_COUNT];
}
static void put_signature(struct smmu_as *as,
dma_addr_t iova, unsigned long pfn)
{
struct page *page;
unsigned long *vaddr;
page = pfn_to_page(pfn);
vaddr = page_address(page);
if (!vaddr)
return;
vaddr[0] = iova;
vaddr[1] = pfn << PAGE_SHIFT;
FLUSH_CPU_DCACHE(vaddr, page, sizeof(vaddr[0]) * 2);
}
static inline void put_signature(struct smmu_as *as,
unsigned long addr, unsigned long pfn)
{
}
static int alloc_pdir(struct smmu_as *as)
{
unsigned long *pdir, flags;
int pdn, err = 0;
u32 val;
struct smmu_device *smmu = as->smmu;
struct page *page;
unsigned int *cnt;
cnt = devm_kzalloc(smmu->dev,
sizeof(cnt[0]) * SMMU_PDIR_COUNT,
GFP_KERNEL);
page = alloc_page(GFP_KERNEL | __GFP_DMA);
spin_lock_irqsave(&as->lock, flags);
if (as->pdir_page) {
err = -EAGAIN;
goto err_out;
}
if (!page || !cnt) {
dev_err(smmu->dev, "failed to allocate at %s\n", __func__);
err = -ENOMEM;
goto err_out;
}
as->pdir_page = page;
as->pte_count = cnt;
SetPageReserved(as->pdir_page);
pdir = page_address(as->pdir_page);
for (pdn = 0; pdn < SMMU_PDIR_COUNT; pdn++)
pdir[pdn] = _PDE_VACANT(pdn);
FLUSH_CPU_DCACHE(pdir, as->pdir_page, SMMU_PDIR_SIZE);
val = SMMU_PTC_FLUSH_TYPE_ADR | VA_PAGE_TO_PA(pdir, as->pdir_page);
smmu_write(smmu, val, SMMU_PTC_FLUSH);
FLUSH_SMMU_REGS(as->smmu);
val = SMMU_TLB_FLUSH_VA_MATCH_ALL |
SMMU_TLB_FLUSH_ASID_MATCH__ENABLE |
(as->asid << SMMU_TLB_FLUSH_ASID_SHIFT);
smmu_write(smmu, val, SMMU_TLB_FLUSH);
FLUSH_SMMU_REGS(as->smmu);
spin_unlock_irqrestore(&as->lock, flags);
return 0;
err_out:
spin_unlock_irqrestore(&as->lock, flags);
devm_kfree(smmu->dev, cnt);
if (page)
__free_page(page);
return err;
}
static void __smmu_iommu_unmap(struct smmu_as *as, dma_addr_t iova)
{
unsigned long *pte;
struct page *page;
unsigned int *count;
pte = locate_pte(as, iova, false, &page, &count);
if (WARN_ON(!pte))
return;
if (WARN_ON(*pte == _PTE_VACANT(iova)))
return;
*pte = _PTE_VACANT(iova);
FLUSH_CPU_DCACHE(pte, page, sizeof(*pte));
flush_ptc_and_tlb(as->smmu, as, iova, pte, page, 0);
if (!--(*count))
free_ptbl(as, iova);
}
static void __smmu_iommu_map_pfn(struct smmu_as *as, dma_addr_t iova,
unsigned long pfn)
{
struct smmu_device *smmu = as->smmu;
unsigned long *pte;
unsigned int *count;
struct page *page;
pte = locate_pte(as, iova, true, &page, &count);
if (WARN_ON(!pte))
return;
if (*pte == _PTE_VACANT(iova))
(*count)++;
*pte = SMMU_PFN_TO_PTE(pfn, as->pte_attr);
if (unlikely((*pte == _PTE_VACANT(iova))))
(*count)--;
FLUSH_CPU_DCACHE(pte, page, sizeof(*pte));
flush_ptc_and_tlb(smmu, as, iova, pte, page, 0);
put_signature(as, iova, pfn);
}
static int smmu_iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t pa, size_t bytes, int prot)
{
struct smmu_as *as = domain->priv;
unsigned long pfn = __phys_to_pfn(pa);
unsigned long flags;
dev_dbg(as->smmu->dev, "[%d] %08lx:%08x\n", as->asid, iova, pa);
if (!pfn_valid(pfn))
return -ENOMEM;
spin_lock_irqsave(&as->lock, flags);
__smmu_iommu_map_pfn(as, iova, pfn);
spin_unlock_irqrestore(&as->lock, flags);
return 0;
}
static size_t smmu_iommu_unmap(struct iommu_domain *domain, unsigned long iova,
size_t bytes)
{
struct smmu_as *as = domain->priv;
unsigned long flags;
dev_dbg(as->smmu->dev, "[%d] %08lx\n", as->asid, iova);
spin_lock_irqsave(&as->lock, flags);
__smmu_iommu_unmap(as, iova);
spin_unlock_irqrestore(&as->lock, flags);
return SMMU_PAGE_SIZE;
}
static phys_addr_t smmu_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
struct smmu_as *as = domain->priv;
unsigned long *pte;
unsigned int *count;
struct page *page;
unsigned long pfn;
unsigned long flags;
spin_lock_irqsave(&as->lock, flags);
pte = locate_pte(as, iova, true, &page, &count);
pfn = *pte & SMMU_PFN_MASK;
WARN_ON(!pfn_valid(pfn));
dev_dbg(as->smmu->dev,
"iova:%08llx pfn:%08lx asid:%d\n", (unsigned long long)iova,
pfn, as->asid);
spin_unlock_irqrestore(&as->lock, flags);
return PFN_PHYS(pfn);
}
static int smmu_iommu_domain_has_cap(struct iommu_domain *domain,
unsigned long cap)
{
return 0;
}
static int smmu_iommu_attach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct smmu_as *as = domain->priv;
struct smmu_device *smmu = as->smmu;
struct smmu_client *client, *c;
u32 map;
int err;
client = devm_kzalloc(smmu->dev, sizeof(*c), GFP_KERNEL);
if (!client)
return -ENOMEM;
client->dev = dev;
client->as = as;
map = (unsigned long)dev->platform_data;
if (!map)
return -EINVAL;
err = smmu_client_enable_hwgrp(client, map);
if (err)
goto err_hwgrp;
spin_lock(&as->client_lock);
list_for_each_entry(c, &as->client, list) {
if (c->dev == dev) {
dev_err(smmu->dev,
"%s is already attached\n", dev_name(c->dev));
err = -EINVAL;
goto err_client;
}
}
list_add(&client->list, &as->client);
spin_unlock(&as->client_lock);
if (map & HWG_AVPC) {
struct page *page;
page = as->smmu->avp_vector_page;
__smmu_iommu_map_pfn(as, 0, page_to_pfn(page));
pr_info("Reserve \"page zero\" for AVP vectors using a common dummy\n");
}
dev_dbg(smmu->dev, "%s is attached\n", dev_name(dev));
return 0;
err_client:
smmu_client_disable_hwgrp(client);
spin_unlock(&as->client_lock);
err_hwgrp:
devm_kfree(smmu->dev, client);
return err;
}
static void smmu_iommu_detach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct smmu_as *as = domain->priv;
struct smmu_device *smmu = as->smmu;
struct smmu_client *c;
spin_lock(&as->client_lock);
list_for_each_entry(c, &as->client, list) {
if (c->dev == dev) {
smmu_client_disable_hwgrp(c);
list_del(&c->list);
devm_kfree(smmu->dev, c);
c->as = NULL;
dev_dbg(smmu->dev,
"%s is detached\n", dev_name(c->dev));
goto out;
}
}
dev_err(smmu->dev, "Couldn't find %s\n", dev_name(dev));
out:
spin_unlock(&as->client_lock);
}
static int smmu_iommu_domain_init(struct iommu_domain *domain)
{
int i, err = -EAGAIN;
unsigned long flags;
struct smmu_as *as;
struct smmu_device *smmu = smmu_handle;
for (i = 0; i < smmu->num_as; i++) {
as = &smmu->as[i];
if (as->pdir_page)
continue;
err = alloc_pdir(as);
if (!err)
goto found;
if (err != -EAGAIN)
break;
}
if (i == smmu->num_as)
dev_err(smmu->dev, "no free AS\n");
return err;
found:
spin_lock_irqsave(&smmu->lock, flags);
smmu_write(smmu, SMMU_PTB_ASID_CUR(as->asid), SMMU_PTB_ASID);
smmu_write(smmu,
SMMU_MK_PDIR(as->pdir_page, as->pdir_attr), SMMU_PTB_DATA);
FLUSH_SMMU_REGS(smmu);
spin_unlock_irqrestore(&smmu->lock, flags);
domain->priv = as;
domain->geometry.aperture_start = smmu->iovmm_base;
domain->geometry.aperture_end = smmu->iovmm_base +
smmu->page_count * SMMU_PAGE_SIZE - 1;
domain->geometry.force_aperture = true;
dev_dbg(smmu->dev, "smmu_as@%p\n", as);
return 0;
}
static void smmu_iommu_domain_destroy(struct iommu_domain *domain)
{
struct smmu_as *as = domain->priv;
struct smmu_device *smmu = as->smmu;
unsigned long flags;
spin_lock_irqsave(&as->lock, flags);
if (as->pdir_page) {
spin_lock(&smmu->lock);
smmu_write(smmu, SMMU_PTB_ASID_CUR(as->asid), SMMU_PTB_ASID);
smmu_write(smmu, SMMU_PTB_DATA_RESET_VAL, SMMU_PTB_DATA);
FLUSH_SMMU_REGS(smmu);
spin_unlock(&smmu->lock);
free_pdir(as);
}
if (!list_empty(&as->client)) {
struct smmu_client *c;
list_for_each_entry(c, &as->client, list)
smmu_iommu_detach_dev(domain, c->dev);
}
spin_unlock_irqrestore(&as->lock, flags);
domain->priv = NULL;
dev_dbg(smmu->dev, "smmu_as@%p\n", as);
}
static ssize_t smmu_debugfs_stats_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *pos)
{
struct smmu_debugfs_info *info;
struct smmu_device *smmu;
int i;
enum {
_OFF = 0,
_ON,
_RESET,
};
const char * const command[] = {
[_OFF] = "off",
[_ON] = "on",
[_RESET] = "reset",
};
char str[] = "reset";
u32 val;
size_t offs;
count = min_t(size_t, count, sizeof(str));
if (copy_from_user(str, buffer, count))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(command); i++)
if (strncmp(str, command[i],
strlen(command[i])) == 0)
break;
if (i == ARRAY_SIZE(command))
return -EINVAL;
info = file_inode(file)->i_private;
smmu = info->smmu;
offs = SMMU_CACHE_CONFIG(info->cache);
val = smmu_read(smmu, offs);
switch (i) {
case _OFF:
val &= ~SMMU_CACHE_CONFIG_STATS_ENABLE;
val &= ~SMMU_CACHE_CONFIG_STATS_TEST;
smmu_write(smmu, val, offs);
break;
case _ON:
val |= SMMU_CACHE_CONFIG_STATS_ENABLE;
val &= ~SMMU_CACHE_CONFIG_STATS_TEST;
smmu_write(smmu, val, offs);
break;
case _RESET:
val |= SMMU_CACHE_CONFIG_STATS_TEST;
smmu_write(smmu, val, offs);
val &= ~SMMU_CACHE_CONFIG_STATS_TEST;
smmu_write(smmu, val, offs);
break;
default:
BUG();
break;
}
dev_dbg(smmu->dev, "%s() %08x, %08x @%08x\n", __func__,
val, smmu_read(smmu, offs), offs);
return count;
}
static int smmu_debugfs_stats_show(struct seq_file *s, void *v)
{
struct smmu_debugfs_info *info = s->private;
struct smmu_device *smmu = info->smmu;
int i;
const char * const stats[] = { "hit", "miss", };
for (i = 0; i < ARRAY_SIZE(stats); i++) {
u32 val;
size_t offs;
offs = SMMU_STATS_CACHE_COUNT(info->mc, info->cache, i);
val = smmu_read(smmu, offs);
seq_printf(s, "%s:%08x ", stats[i], val);
dev_dbg(smmu->dev, "%s() %s %08x @%08x\n", __func__,
stats[i], val, offs);
}
seq_printf(s, "\n");
return 0;
}
static int smmu_debugfs_stats_open(struct inode *inode, struct file *file)
{
return single_open(file, smmu_debugfs_stats_show, inode->i_private);
}
static void smmu_debugfs_delete(struct smmu_device *smmu)
{
debugfs_remove_recursive(smmu->debugfs_root);
kfree(smmu->debugfs_info);
}
static void smmu_debugfs_create(struct smmu_device *smmu)
{
int i;
size_t bytes;
struct dentry *root;
bytes = ARRAY_SIZE(smmu_debugfs_mc) * ARRAY_SIZE(smmu_debugfs_cache) *
sizeof(*smmu->debugfs_info);
smmu->debugfs_info = kmalloc(bytes, GFP_KERNEL);
if (!smmu->debugfs_info)
return;
root = debugfs_create_dir(dev_name(smmu->dev), NULL);
if (!root)
goto err_out;
smmu->debugfs_root = root;
for (i = 0; i < ARRAY_SIZE(smmu_debugfs_mc); i++) {
int j;
struct dentry *mc;
mc = debugfs_create_dir(smmu_debugfs_mc[i], root);
if (!mc)
goto err_out;
for (j = 0; j < ARRAY_SIZE(smmu_debugfs_cache); j++) {
struct dentry *cache;
struct smmu_debugfs_info *info;
info = smmu->debugfs_info;
info += i * ARRAY_SIZE(smmu_debugfs_mc) + j;
info->smmu = smmu;
info->mc = i;
info->cache = j;
cache = debugfs_create_file(smmu_debugfs_cache[j],
S_IWUGO | S_IRUGO, mc,
(void *)info,
&smmu_debugfs_stats_fops);
if (!cache)
goto err_out;
}
}
return;
err_out:
smmu_debugfs_delete(smmu);
}
static int tegra_smmu_suspend(struct device *dev)
{
struct smmu_device *smmu = dev_get_drvdata(dev);
smmu->translation_enable_0 = smmu_read(smmu, SMMU_TRANSLATION_ENABLE_0);
smmu->translation_enable_1 = smmu_read(smmu, SMMU_TRANSLATION_ENABLE_1);
smmu->translation_enable_2 = smmu_read(smmu, SMMU_TRANSLATION_ENABLE_2);
smmu->asid_security = smmu_read(smmu, SMMU_ASID_SECURITY);
return 0;
}
static int tegra_smmu_resume(struct device *dev)
{
struct smmu_device *smmu = dev_get_drvdata(dev);
unsigned long flags;
int err;
spin_lock_irqsave(&smmu->lock, flags);
err = smmu_setup_regs(smmu);
spin_unlock_irqrestore(&smmu->lock, flags);
return err;
}
static int tegra_smmu_probe(struct platform_device *pdev)
{
struct smmu_device *smmu;
struct device *dev = &pdev->dev;
int i, asids, err = 0;
dma_addr_t uninitialized_var(base);
size_t bytes, uninitialized_var(size);
if (smmu_handle)
return -EIO;
BUILD_BUG_ON(PAGE_SHIFT != SMMU_PAGE_SHIFT);
if (of_property_read_u32(dev->of_node, "nvidia,#asids", &asids))
return -ENODEV;
bytes = sizeof(*smmu) + asids * sizeof(*smmu->as);
smmu = devm_kzalloc(dev, bytes, GFP_KERNEL);
if (!smmu) {
dev_err(dev, "failed to allocate smmu_device\n");
return -ENOMEM;
}
smmu->nregs = pdev->num_resources;
smmu->regs = devm_kzalloc(dev, 2 * smmu->nregs * sizeof(*smmu->regs),
GFP_KERNEL);
smmu->rege = smmu->regs + smmu->nregs;
if (!smmu->regs)
return -ENOMEM;
for (i = 0; i < smmu->nregs; i++) {
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
smmu->regs[i] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(smmu->regs[i]))
return PTR_ERR(smmu->regs[i]);
smmu->rege[i] = smmu->regs[i] + resource_size(res) - 1;
}
smmu->regbase = (void __iomem *)((u32)smmu->regs[0] & PAGE_MASK);
err = of_get_dma_window(dev->of_node, NULL, 0, NULL, &base, &size);
if (err)
return -ENODEV;
if (size & SMMU_PAGE_MASK)
return -EINVAL;
size >>= SMMU_PAGE_SHIFT;
if (!size)
return -EINVAL;
smmu->ahb = of_parse_phandle(dev->of_node, "nvidia,ahb", 0);
if (!smmu->ahb)
return -ENODEV;
smmu->dev = dev;
smmu->num_as = asids;
smmu->iovmm_base = base;
smmu->page_count = size;
smmu->translation_enable_0 = ~0;
smmu->translation_enable_1 = ~0;
smmu->translation_enable_2 = ~0;
smmu->asid_security = 0;
for (i = 0; i < smmu->num_as; i++) {
struct smmu_as *as = &smmu->as[i];
as->smmu = smmu;
as->asid = i;
as->pdir_attr = _PDIR_ATTR;
as->pde_attr = _PDE_ATTR;
as->pte_attr = _PTE_ATTR;
spin_lock_init(&as->lock);
spin_lock_init(&as->client_lock);
INIT_LIST_HEAD(&as->client);
}
spin_lock_init(&smmu->lock);
err = smmu_setup_regs(smmu);
if (err)
return err;
platform_set_drvdata(pdev, smmu);
smmu->avp_vector_page = alloc_page(GFP_KERNEL);
if (!smmu->avp_vector_page)
return -ENOMEM;
smmu_debugfs_create(smmu);
smmu_handle = smmu;
bus_set_iommu(&platform_bus_type, &smmu_iommu_ops);
return 0;
}
static int tegra_smmu_remove(struct platform_device *pdev)
{
struct smmu_device *smmu = platform_get_drvdata(pdev);
int i;
smmu_debugfs_delete(smmu);
smmu_write(smmu, SMMU_CONFIG_DISABLE, SMMU_CONFIG);
for (i = 0; i < smmu->num_as; i++)
free_pdir(&smmu->as[i]);
__free_page(smmu->avp_vector_page);
smmu_handle = NULL;
return 0;
}
static int tegra_smmu_init(void)
{
return platform_driver_register(&tegra_smmu_driver);
}
static void __exit tegra_smmu_exit(void)
{
platform_driver_unregister(&tegra_smmu_driver);
}
