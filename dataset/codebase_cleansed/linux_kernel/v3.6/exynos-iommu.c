static unsigned long *section_entry(unsigned long *pgtable, unsigned long iova)
{
return pgtable + lv1ent_offset(iova);
}
static unsigned long *page_entry(unsigned long *sent, unsigned long iova)
{
return (unsigned long *)__va(lv2table_base(sent)) + lv2ent_offset(iova);
}
static bool set_sysmmu_active(struct sysmmu_drvdata *data)
{
return ++data->activations == 1;
}
static bool set_sysmmu_inactive(struct sysmmu_drvdata *data)
{
BUG_ON(data->activations < 1);
return --data->activations == 0;
}
static bool is_sysmmu_active(struct sysmmu_drvdata *data)
{
return data->activations > 0;
}
static void sysmmu_unblock(void __iomem *sfrbase)
{
__raw_writel(CTRL_ENABLE, sfrbase + REG_MMU_CTRL);
}
static bool sysmmu_block(void __iomem *sfrbase)
{
int i = 120;
__raw_writel(CTRL_BLOCK, sfrbase + REG_MMU_CTRL);
while ((i > 0) && !(__raw_readl(sfrbase + REG_MMU_STATUS) & 1))
--i;
if (!(__raw_readl(sfrbase + REG_MMU_STATUS) & 1)) {
sysmmu_unblock(sfrbase);
return false;
}
return true;
}
static void __sysmmu_tlb_invalidate(void __iomem *sfrbase)
{
__raw_writel(0x1, sfrbase + REG_MMU_FLUSH);
}
static void __sysmmu_tlb_invalidate_entry(void __iomem *sfrbase,
unsigned long iova)
{
__raw_writel((iova & SPAGE_MASK) | 1, sfrbase + REG_MMU_FLUSH_ENTRY);
}
static void __sysmmu_set_ptbase(void __iomem *sfrbase,
unsigned long pgd)
{
__raw_writel(0x1, sfrbase + REG_MMU_CFG);
__raw_writel(pgd, sfrbase + REG_PT_BASE_ADDR);
__sysmmu_tlb_invalidate(sfrbase);
}
static void __sysmmu_set_prefbuf(void __iomem *sfrbase, unsigned long base,
unsigned long size, int idx)
{
__raw_writel(base, sfrbase + REG_PB0_SADDR + idx * 8);
__raw_writel(size - 1 + base, sfrbase + REG_PB0_EADDR + idx * 8);
}
void exynos_sysmmu_set_prefbuf(struct device *dev,
unsigned long base0, unsigned long size0,
unsigned long base1, unsigned long size1)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
unsigned long flags;
int i;
BUG_ON((base0 + size0) <= base0);
BUG_ON((size1 > 0) && ((base1 + size1) <= base1));
read_lock_irqsave(&data->lock, flags);
if (!is_sysmmu_active(data))
goto finish;
for (i = 0; i < data->nsfrs; i++) {
if ((readl(data->sfrbases[i] + REG_MMU_VERSION) >> 28) == 3) {
if (!sysmmu_block(data->sfrbases[i]))
continue;
if (size1 == 0) {
if (size0 <= SZ_128K) {
base1 = base0;
size1 = size0;
} else {
size1 = size0 -
ALIGN(size0 / 2, SZ_64K);
size0 = size0 - size1;
base1 = base0 + size0;
}
}
__sysmmu_set_prefbuf(
data->sfrbases[i], base0, size0, 0);
__sysmmu_set_prefbuf(
data->sfrbases[i], base1, size1, 1);
sysmmu_unblock(data->sfrbases[i]);
}
}
finish:
read_unlock_irqrestore(&data->lock, flags);
}
static void __set_fault_handler(struct sysmmu_drvdata *data,
sysmmu_fault_handler_t handler)
{
unsigned long flags;
write_lock_irqsave(&data->lock, flags);
data->fault_handler = handler;
write_unlock_irqrestore(&data->lock, flags);
}
void exynos_sysmmu_set_fault_handler(struct device *dev,
sysmmu_fault_handler_t handler)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
__set_fault_handler(data, handler);
}
static int default_fault_handler(enum exynos_sysmmu_inttype itype,
unsigned long pgtable_base, unsigned long fault_addr)
{
unsigned long *ent;
if ((itype >= SYSMMU_FAULTS_NUM) || (itype < SYSMMU_PAGEFAULT))
itype = SYSMMU_FAULT_UNKNOWN;
pr_err("%s occurred at 0x%lx(Page table base: 0x%lx)\n",
sysmmu_fault_name[itype], fault_addr, pgtable_base);
ent = section_entry(__va(pgtable_base), fault_addr);
pr_err("\tLv1 entry: 0x%lx\n", *ent);
if (lv1ent_page(ent)) {
ent = page_entry(ent, fault_addr);
pr_err("\t Lv2 entry: 0x%lx\n", *ent);
}
pr_err("Generating Kernel OOPS... because it is unrecoverable.\n");
BUG();
return 0;
}
static irqreturn_t exynos_sysmmu_irq(int irq, void *dev_id)
{
struct sysmmu_drvdata *data = dev_id;
struct resource *irqres;
struct platform_device *pdev;
enum exynos_sysmmu_inttype itype;
unsigned long addr = -1;
int i, ret = -ENOSYS;
read_lock(&data->lock);
WARN_ON(!is_sysmmu_active(data));
pdev = to_platform_device(data->sysmmu);
for (i = 0; i < (pdev->num_resources / 2); i++) {
irqres = platform_get_resource(pdev, IORESOURCE_IRQ, i);
if (irqres && ((int)irqres->start == irq))
break;
}
if (i == pdev->num_resources) {
itype = SYSMMU_FAULT_UNKNOWN;
} else {
itype = (enum exynos_sysmmu_inttype)
__ffs(__raw_readl(data->sfrbases[i] + REG_INT_STATUS));
if (WARN_ON(!((itype >= 0) && (itype < SYSMMU_FAULT_UNKNOWN))))
itype = SYSMMU_FAULT_UNKNOWN;
else
addr = __raw_readl(
data->sfrbases[i] + fault_reg_offset[itype]);
}
if (data->domain)
ret = report_iommu_fault(data->domain, data->dev,
addr, itype);
if ((ret == -ENOSYS) && data->fault_handler) {
unsigned long base = data->pgtable;
if (itype != SYSMMU_FAULT_UNKNOWN)
base = __raw_readl(
data->sfrbases[i] + REG_PT_BASE_ADDR);
ret = data->fault_handler(itype, base, addr);
}
if (!ret && (itype != SYSMMU_FAULT_UNKNOWN))
__raw_writel(1 << itype, data->sfrbases[i] + REG_INT_CLEAR);
else
dev_dbg(data->sysmmu, "(%s) %s is not handled.\n",
data->dbgname, sysmmu_fault_name[itype]);
if (itype != SYSMMU_FAULT_UNKNOWN)
sysmmu_unblock(data->sfrbases[i]);
read_unlock(&data->lock);
return IRQ_HANDLED;
}
static bool __exynos_sysmmu_disable(struct sysmmu_drvdata *data)
{
unsigned long flags;
bool disabled = false;
int i;
write_lock_irqsave(&data->lock, flags);
if (!set_sysmmu_inactive(data))
goto finish;
for (i = 0; i < data->nsfrs; i++)
__raw_writel(CTRL_DISABLE, data->sfrbases[i] + REG_MMU_CTRL);
if (data->clk[1])
clk_disable(data->clk[1]);
if (data->clk[0])
clk_disable(data->clk[0]);
disabled = true;
data->pgtable = 0;
data->domain = NULL;
finish:
write_unlock_irqrestore(&data->lock, flags);
if (disabled)
dev_dbg(data->sysmmu, "(%s) Disabled\n", data->dbgname);
else
dev_dbg(data->sysmmu, "(%s) %d times left to be disabled\n",
data->dbgname, data->activations);
return disabled;
}
static int __exynos_sysmmu_enable(struct sysmmu_drvdata *data,
unsigned long pgtable, struct iommu_domain *domain)
{
int i, ret = 0;
unsigned long flags;
write_lock_irqsave(&data->lock, flags);
if (!set_sysmmu_active(data)) {
if (WARN_ON(pgtable != data->pgtable)) {
ret = -EBUSY;
set_sysmmu_inactive(data);
} else {
ret = 1;
}
dev_dbg(data->sysmmu, "(%s) Already enabled\n", data->dbgname);
goto finish;
}
if (data->clk[0])
clk_enable(data->clk[0]);
if (data->clk[1])
clk_enable(data->clk[1]);
data->pgtable = pgtable;
for (i = 0; i < data->nsfrs; i++) {
__sysmmu_set_ptbase(data->sfrbases[i], pgtable);
if ((readl(data->sfrbases[i] + REG_MMU_VERSION) >> 28) == 3) {
__raw_writel((1 << 12) | (2 << 28),
data->sfrbases[i] + REG_MMU_CFG);
__sysmmu_set_prefbuf(data->sfrbases[i], 0, -1, 0);
__sysmmu_set_prefbuf(data->sfrbases[i], 0, -1, 1);
}
__raw_writel(CTRL_ENABLE, data->sfrbases[i] + REG_MMU_CTRL);
}
data->domain = domain;
dev_dbg(data->sysmmu, "(%s) Enabled\n", data->dbgname);
finish:
write_unlock_irqrestore(&data->lock, flags);
return ret;
}
int exynos_sysmmu_enable(struct device *dev, unsigned long pgtable)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
int ret;
BUG_ON(!memblock_is_memory(pgtable));
ret = pm_runtime_get_sync(data->sysmmu);
if (ret < 0) {
dev_dbg(data->sysmmu, "(%s) Failed to enable\n", data->dbgname);
return ret;
}
ret = __exynos_sysmmu_enable(data, pgtable, NULL);
if (WARN_ON(ret < 0)) {
pm_runtime_put(data->sysmmu);
dev_err(data->sysmmu,
"(%s) Already enabled with page table %#lx\n",
data->dbgname, data->pgtable);
} else {
data->dev = dev;
}
return ret;
}
bool exynos_sysmmu_disable(struct device *dev)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
bool disabled;
disabled = __exynos_sysmmu_disable(data);
pm_runtime_put(data->sysmmu);
return disabled;
}
static void sysmmu_tlb_invalidate_entry(struct device *dev, unsigned long iova)
{
unsigned long flags;
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
read_lock_irqsave(&data->lock, flags);
if (is_sysmmu_active(data)) {
int i;
for (i = 0; i < data->nsfrs; i++) {
if (sysmmu_block(data->sfrbases[i])) {
__sysmmu_tlb_invalidate_entry(
data->sfrbases[i], iova);
sysmmu_unblock(data->sfrbases[i]);
}
}
} else {
dev_dbg(data->sysmmu,
"(%s) Disabled. Skipping invalidating TLB.\n",
data->dbgname);
}
read_unlock_irqrestore(&data->lock, flags);
}
void exynos_sysmmu_tlb_invalidate(struct device *dev)
{
unsigned long flags;
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
read_lock_irqsave(&data->lock, flags);
if (is_sysmmu_active(data)) {
int i;
for (i = 0; i < data->nsfrs; i++) {
if (sysmmu_block(data->sfrbases[i])) {
__sysmmu_tlb_invalidate(data->sfrbases[i]);
sysmmu_unblock(data->sfrbases[i]);
}
}
} else {
dev_dbg(data->sysmmu,
"(%s) Disabled. Skipping invalidating TLB.\n",
data->dbgname);
}
read_unlock_irqrestore(&data->lock, flags);
}
static int exynos_sysmmu_probe(struct platform_device *pdev)
{
int i, ret;
struct device *dev;
struct sysmmu_drvdata *data;
dev = &pdev->dev;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
dev_dbg(dev, "Not enough memory\n");
ret = -ENOMEM;
goto err_alloc;
}
ret = dev_set_drvdata(dev, data);
if (ret) {
dev_dbg(dev, "Unabled to initialize driver data\n");
goto err_init;
}
data->nsfrs = pdev->num_resources / 2;
data->sfrbases = kmalloc(sizeof(*data->sfrbases) * data->nsfrs,
GFP_KERNEL);
if (data->sfrbases == NULL) {
dev_dbg(dev, "Not enough memory\n");
ret = -ENOMEM;
goto err_init;
}
for (i = 0; i < data->nsfrs; i++) {
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res) {
dev_dbg(dev, "Unable to find IOMEM region\n");
ret = -ENOENT;
goto err_res;
}
data->sfrbases[i] = ioremap(res->start, resource_size(res));
if (!data->sfrbases[i]) {
dev_dbg(dev, "Unable to map IOMEM @ PA:%#x\n",
res->start);
ret = -ENOENT;
goto err_res;
}
}
for (i = 0; i < data->nsfrs; i++) {
ret = platform_get_irq(pdev, i);
if (ret <= 0) {
dev_dbg(dev, "Unable to find IRQ resource\n");
goto err_irq;
}
ret = request_irq(ret, exynos_sysmmu_irq, 0,
dev_name(dev), data);
if (ret) {
dev_dbg(dev, "Unabled to register interrupt handler\n");
goto err_irq;
}
}
if (dev_get_platdata(dev)) {
char *deli, *beg;
struct sysmmu_platform_data *platdata = dev_get_platdata(dev);
beg = platdata->clockname;
for (deli = beg; (*deli != '\0') && (*deli != ','); deli++)
;
if (*deli == '\0')
deli = NULL;
else
*deli = '\0';
data->clk[0] = clk_get(dev, beg);
if (IS_ERR(data->clk[0])) {
data->clk[0] = NULL;
dev_dbg(dev, "No clock descriptor registered\n");
}
if (data->clk[0] && deli) {
*deli = ',';
data->clk[1] = clk_get(dev, deli + 1);
if (IS_ERR(data->clk[1]))
data->clk[1] = NULL;
}
data->dbgname = platdata->dbgname;
}
data->sysmmu = dev;
rwlock_init(&data->lock);
INIT_LIST_HEAD(&data->node);
__set_fault_handler(data, &default_fault_handler);
if (dev->parent)
pm_runtime_enable(dev);
dev_dbg(dev, "(%s) Initialized\n", data->dbgname);
return 0;
err_irq:
while (i-- > 0) {
int irq;
irq = platform_get_irq(pdev, i);
free_irq(irq, data);
}
err_res:
while (data->nsfrs-- > 0)
iounmap(data->sfrbases[data->nsfrs]);
kfree(data->sfrbases);
err_init:
kfree(data);
err_alloc:
dev_err(dev, "Failed to initialize\n");
return ret;
}
static inline void pgtable_flush(void *vastart, void *vaend)
{
dmac_flush_range(vastart, vaend);
outer_flush_range(virt_to_phys(vastart),
virt_to_phys(vaend));
}
static int exynos_iommu_domain_init(struct iommu_domain *domain)
{
struct exynos_iommu_domain *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->pgtable = (unsigned long *)__get_free_pages(
GFP_KERNEL | __GFP_ZERO, 2);
if (!priv->pgtable)
goto err_pgtable;
priv->lv2entcnt = (short *)__get_free_pages(
GFP_KERNEL | __GFP_ZERO, 1);
if (!priv->lv2entcnt)
goto err_counter;
pgtable_flush(priv->pgtable, priv->pgtable + NUM_LV1ENTRIES);
spin_lock_init(&priv->lock);
spin_lock_init(&priv->pgtablelock);
INIT_LIST_HEAD(&priv->clients);
domain->geometry.aperture_start = 0;
domain->geometry.aperture_end = ~0UL;
domain->geometry.force_aperture = true;
domain->priv = priv;
return 0;
err_counter:
free_pages((unsigned long)priv->pgtable, 2);
err_pgtable:
kfree(priv);
return -ENOMEM;
}
static void exynos_iommu_domain_destroy(struct iommu_domain *domain)
{
struct exynos_iommu_domain *priv = domain->priv;
struct sysmmu_drvdata *data;
unsigned long flags;
int i;
WARN_ON(!list_empty(&priv->clients));
spin_lock_irqsave(&priv->lock, flags);
list_for_each_entry(data, &priv->clients, node) {
while (!exynos_sysmmu_disable(data->dev))
;
}
spin_unlock_irqrestore(&priv->lock, flags);
for (i = 0; i < NUM_LV1ENTRIES; i++)
if (lv1ent_page(priv->pgtable + i))
kfree(__va(lv2table_base(priv->pgtable + i)));
free_pages((unsigned long)priv->pgtable, 2);
free_pages((unsigned long)priv->lv2entcnt, 1);
kfree(domain->priv);
domain->priv = NULL;
}
static int exynos_iommu_attach_device(struct iommu_domain *domain,
struct device *dev)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
struct exynos_iommu_domain *priv = domain->priv;
unsigned long flags;
int ret;
ret = pm_runtime_get_sync(data->sysmmu);
if (ret < 0)
return ret;
ret = 0;
spin_lock_irqsave(&priv->lock, flags);
ret = __exynos_sysmmu_enable(data, __pa(priv->pgtable), domain);
if (ret == 0) {
BUG_ON(!list_empty(&data->node));
data->dev = dev;
list_add_tail(&data->node, &priv->clients);
}
spin_unlock_irqrestore(&priv->lock, flags);
if (ret < 0) {
dev_err(dev, "%s: Failed to attach IOMMU with pgtable %#lx\n",
__func__, __pa(priv->pgtable));
pm_runtime_put(data->sysmmu);
} else if (ret > 0) {
dev_dbg(dev, "%s: IOMMU with pgtable 0x%lx already attached\n",
__func__, __pa(priv->pgtable));
} else {
dev_dbg(dev, "%s: Attached new IOMMU with pgtable 0x%lx\n",
__func__, __pa(priv->pgtable));
}
return ret;
}
static void exynos_iommu_detach_device(struct iommu_domain *domain,
struct device *dev)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev->archdata.iommu);
struct exynos_iommu_domain *priv = domain->priv;
struct list_head *pos;
unsigned long flags;
bool found = false;
spin_lock_irqsave(&priv->lock, flags);
list_for_each(pos, &priv->clients) {
if (list_entry(pos, struct sysmmu_drvdata, node) == data) {
found = true;
break;
}
}
if (!found)
goto finish;
if (__exynos_sysmmu_disable(data)) {
dev_dbg(dev, "%s: Detached IOMMU with pgtable %#lx\n",
__func__, __pa(priv->pgtable));
list_del(&data->node);
INIT_LIST_HEAD(&data->node);
} else {
dev_dbg(dev, "%s: Detaching IOMMU with pgtable %#lx delayed",
__func__, __pa(priv->pgtable));
}
finish:
spin_unlock_irqrestore(&priv->lock, flags);
if (found)
pm_runtime_put(data->sysmmu);
}
static unsigned long *alloc_lv2entry(unsigned long *sent, unsigned long iova,
short *pgcounter)
{
if (lv1ent_fault(sent)) {
unsigned long *pent;
pent = kzalloc(LV2TABLE_SIZE, GFP_ATOMIC);
BUG_ON((unsigned long)pent & (LV2TABLE_SIZE - 1));
if (!pent)
return NULL;
*sent = mk_lv1ent_page(__pa(pent));
*pgcounter = NUM_LV2ENTRIES;
pgtable_flush(pent, pent + NUM_LV2ENTRIES);
pgtable_flush(sent, sent + 1);
}
return page_entry(sent, iova);
}
static int lv1set_section(unsigned long *sent, phys_addr_t paddr, short *pgcnt)
{
if (lv1ent_section(sent))
return -EADDRINUSE;
if (lv1ent_page(sent)) {
if (*pgcnt != NUM_LV2ENTRIES)
return -EADDRINUSE;
kfree(page_entry(sent, 0));
*pgcnt = 0;
}
*sent = mk_lv1ent_sect(paddr);
pgtable_flush(sent, sent + 1);
return 0;
}
static int lv2set_page(unsigned long *pent, phys_addr_t paddr, size_t size,
short *pgcnt)
{
if (size == SPAGE_SIZE) {
if (!lv2ent_fault(pent))
return -EADDRINUSE;
*pent = mk_lv2ent_spage(paddr);
pgtable_flush(pent, pent + 1);
*pgcnt -= 1;
} else {
int i;
for (i = 0; i < SPAGES_PER_LPAGE; i++, pent++) {
if (!lv2ent_fault(pent)) {
memset(pent, 0, sizeof(*pent) * i);
return -EADDRINUSE;
}
*pent = mk_lv2ent_lpage(paddr);
}
pgtable_flush(pent - SPAGES_PER_LPAGE, pent);
*pgcnt -= SPAGES_PER_LPAGE;
}
return 0;
}
static int exynos_iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, size_t size, int prot)
{
struct exynos_iommu_domain *priv = domain->priv;
unsigned long *entry;
unsigned long flags;
int ret = -ENOMEM;
BUG_ON(priv->pgtable == NULL);
spin_lock_irqsave(&priv->pgtablelock, flags);
entry = section_entry(priv->pgtable, iova);
if (size == SECT_SIZE) {
ret = lv1set_section(entry, paddr,
&priv->lv2entcnt[lv1ent_offset(iova)]);
} else {
unsigned long *pent;
pent = alloc_lv2entry(entry, iova,
&priv->lv2entcnt[lv1ent_offset(iova)]);
if (!pent)
ret = -ENOMEM;
else
ret = lv2set_page(pent, paddr, size,
&priv->lv2entcnt[lv1ent_offset(iova)]);
}
if (ret) {
pr_debug("%s: Failed to map iova 0x%lx/0x%x bytes\n",
__func__, iova, size);
}
spin_unlock_irqrestore(&priv->pgtablelock, flags);
return ret;
}
static size_t exynos_iommu_unmap(struct iommu_domain *domain,
unsigned long iova, size_t size)
{
struct exynos_iommu_domain *priv = domain->priv;
struct sysmmu_drvdata *data;
unsigned long flags;
unsigned long *ent;
BUG_ON(priv->pgtable == NULL);
spin_lock_irqsave(&priv->pgtablelock, flags);
ent = section_entry(priv->pgtable, iova);
if (lv1ent_section(ent)) {
BUG_ON(size < SECT_SIZE);
*ent = 0;
pgtable_flush(ent, ent + 1);
size = SECT_SIZE;
goto done;
}
if (unlikely(lv1ent_fault(ent))) {
if (size > SECT_SIZE)
size = SECT_SIZE;
goto done;
}
ent = page_entry(ent, iova);
if (unlikely(lv2ent_fault(ent))) {
size = SPAGE_SIZE;
goto done;
}
if (lv2ent_small(ent)) {
*ent = 0;
size = SPAGE_SIZE;
priv->lv2entcnt[lv1ent_offset(iova)] += 1;
goto done;
}
BUG_ON(size < LPAGE_SIZE);
memset(ent, 0, sizeof(*ent) * SPAGES_PER_LPAGE);
size = LPAGE_SIZE;
priv->lv2entcnt[lv1ent_offset(iova)] += SPAGES_PER_LPAGE;
done:
spin_unlock_irqrestore(&priv->pgtablelock, flags);
spin_lock_irqsave(&priv->lock, flags);
list_for_each_entry(data, &priv->clients, node)
sysmmu_tlb_invalidate_entry(data->dev, iova);
spin_unlock_irqrestore(&priv->lock, flags);
return size;
}
static phys_addr_t exynos_iommu_iova_to_phys(struct iommu_domain *domain,
unsigned long iova)
{
struct exynos_iommu_domain *priv = domain->priv;
unsigned long *entry;
unsigned long flags;
phys_addr_t phys = 0;
spin_lock_irqsave(&priv->pgtablelock, flags);
entry = section_entry(priv->pgtable, iova);
if (lv1ent_section(entry)) {
phys = section_phys(entry) + section_offs(iova);
} else if (lv1ent_page(entry)) {
entry = page_entry(entry, iova);
if (lv2ent_large(entry))
phys = lpage_phys(entry) + lpage_offs(iova);
else if (lv2ent_small(entry))
phys = spage_phys(entry) + spage_offs(iova);
}
spin_unlock_irqrestore(&priv->pgtablelock, flags);
return phys;
}
static int __init exynos_iommu_init(void)
{
int ret;
ret = platform_driver_register(&exynos_sysmmu_driver);
if (ret == 0)
bus_set_iommu(&platform_bus_type, &exynos_iommu_ops);
return ret;
}
