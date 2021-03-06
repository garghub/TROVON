static struct omap_iommu_domain *to_omap_domain(struct iommu_domain *dom)
{
return container_of(dom, struct omap_iommu_domain, domain);
}
void omap_iommu_save_ctx(struct device *dev)
{
struct omap_iommu *obj = dev_to_omap_iommu(dev);
u32 *p = obj->ctx;
int i;
for (i = 0; i < (MMU_REG_SIZE / sizeof(u32)); i++) {
p[i] = iommu_read_reg(obj, i * sizeof(u32));
dev_dbg(obj->dev, "%s\t[%02d] %08x\n", __func__, i, p[i]);
}
}
void omap_iommu_restore_ctx(struct device *dev)
{
struct omap_iommu *obj = dev_to_omap_iommu(dev);
u32 *p = obj->ctx;
int i;
for (i = 0; i < (MMU_REG_SIZE / sizeof(u32)); i++) {
iommu_write_reg(obj, p[i], i * sizeof(u32));
dev_dbg(obj->dev, "%s\t[%02d] %08x\n", __func__, i, p[i]);
}
}
static void dra7_cfg_dspsys_mmu(struct omap_iommu *obj, bool enable)
{
u32 val, mask;
if (!obj->syscfg)
return;
mask = (1 << (obj->id * DSP_SYS_MMU_CONFIG_EN_SHIFT));
val = enable ? mask : 0;
regmap_update_bits(obj->syscfg, DSP_SYS_MMU_CONFIG, mask, val);
}
static void __iommu_set_twl(struct omap_iommu *obj, bool on)
{
u32 l = iommu_read_reg(obj, MMU_CNTL);
if (on)
iommu_write_reg(obj, MMU_IRQ_TWL_MASK, MMU_IRQENABLE);
else
iommu_write_reg(obj, MMU_IRQ_TLB_MISS_MASK, MMU_IRQENABLE);
l &= ~MMU_CNTL_MASK;
if (on)
l |= (MMU_CNTL_MMU_EN | MMU_CNTL_TWL_EN);
else
l |= (MMU_CNTL_MMU_EN);
iommu_write_reg(obj, l, MMU_CNTL);
}
static int omap2_iommu_enable(struct omap_iommu *obj)
{
u32 l, pa;
if (!obj->iopgd || !IS_ALIGNED((u32)obj->iopgd, SZ_16K))
return -EINVAL;
pa = virt_to_phys(obj->iopgd);
if (!IS_ALIGNED(pa, SZ_16K))
return -EINVAL;
l = iommu_read_reg(obj, MMU_REVISION);
dev_info(obj->dev, "%s: version %d.%d\n", obj->name,
(l >> 4) & 0xf, l & 0xf);
iommu_write_reg(obj, pa, MMU_TTB);
dra7_cfg_dspsys_mmu(obj, true);
if (obj->has_bus_err_back)
iommu_write_reg(obj, MMU_GP_REG_BUS_ERR_BACK_EN, MMU_GP_REG);
__iommu_set_twl(obj, true);
return 0;
}
static void omap2_iommu_disable(struct omap_iommu *obj)
{
u32 l = iommu_read_reg(obj, MMU_CNTL);
l &= ~MMU_CNTL_MASK;
iommu_write_reg(obj, l, MMU_CNTL);
dra7_cfg_dspsys_mmu(obj, false);
dev_dbg(obj->dev, "%s is shutting down\n", obj->name);
}
static int iommu_enable(struct omap_iommu *obj)
{
int err;
struct platform_device *pdev = to_platform_device(obj->dev);
struct iommu_platform_data *pdata = dev_get_platdata(&pdev->dev);
if (pdata && pdata->deassert_reset) {
err = pdata->deassert_reset(pdev, pdata->reset_name);
if (err) {
dev_err(obj->dev, "deassert_reset failed: %d\n", err);
return err;
}
}
pm_runtime_get_sync(obj->dev);
err = omap2_iommu_enable(obj);
return err;
}
static void iommu_disable(struct omap_iommu *obj)
{
struct platform_device *pdev = to_platform_device(obj->dev);
struct iommu_platform_data *pdata = dev_get_platdata(&pdev->dev);
omap2_iommu_disable(obj);
pm_runtime_put_sync(obj->dev);
if (pdata && pdata->assert_reset)
pdata->assert_reset(pdev, pdata->reset_name);
}
static u32 iotlb_cr_to_virt(struct cr_regs *cr)
{
u32 page_size = cr->cam & MMU_CAM_PGSZ_MASK;
u32 mask = get_cam_va_mask(cr->cam & page_size);
return cr->cam & mask;
}
static u32 get_iopte_attr(struct iotlb_entry *e)
{
u32 attr;
attr = e->mixed << 5;
attr |= e->endian;
attr |= e->elsz >> 3;
attr <<= (((e->pgsz == MMU_CAM_PGSZ_4K) ||
(e->pgsz == MMU_CAM_PGSZ_64K)) ? 0 : 6);
return attr;
}
static u32 iommu_report_fault(struct omap_iommu *obj, u32 *da)
{
u32 status, fault_addr;
status = iommu_read_reg(obj, MMU_IRQSTATUS);
status &= MMU_IRQ_MASK;
if (!status) {
*da = 0;
return 0;
}
fault_addr = iommu_read_reg(obj, MMU_FAULT_AD);
*da = fault_addr;
iommu_write_reg(obj, status, MMU_IRQSTATUS);
return status;
}
void iotlb_lock_get(struct omap_iommu *obj, struct iotlb_lock *l)
{
u32 val;
val = iommu_read_reg(obj, MMU_LOCK);
l->base = MMU_LOCK_BASE(val);
l->vict = MMU_LOCK_VICT(val);
}
void iotlb_lock_set(struct omap_iommu *obj, struct iotlb_lock *l)
{
u32 val;
val = (l->base << MMU_LOCK_BASE_SHIFT);
val |= (l->vict << MMU_LOCK_VICT_SHIFT);
iommu_write_reg(obj, val, MMU_LOCK);
}
static void iotlb_read_cr(struct omap_iommu *obj, struct cr_regs *cr)
{
cr->cam = iommu_read_reg(obj, MMU_READ_CAM);
cr->ram = iommu_read_reg(obj, MMU_READ_RAM);
}
static void iotlb_load_cr(struct omap_iommu *obj, struct cr_regs *cr)
{
iommu_write_reg(obj, cr->cam | MMU_CAM_V, MMU_CAM);
iommu_write_reg(obj, cr->ram, MMU_RAM);
iommu_write_reg(obj, 1, MMU_FLUSH_ENTRY);
iommu_write_reg(obj, 1, MMU_LD_TLB);
}
struct cr_regs __iotlb_read_cr(struct omap_iommu *obj, int n)
{
struct cr_regs cr;
struct iotlb_lock l;
iotlb_lock_get(obj, &l);
l.vict = n;
iotlb_lock_set(obj, &l);
iotlb_read_cr(obj, &cr);
return cr;
}
static struct cr_regs *iotlb_alloc_cr(struct omap_iommu *obj,
struct iotlb_entry *e)
{
struct cr_regs *cr;
if (!e)
return NULL;
if (e->da & ~(get_cam_va_mask(e->pgsz))) {
dev_err(obj->dev, "%s:\twrong alignment: %08x\n", __func__,
e->da);
return ERR_PTR(-EINVAL);
}
cr = kmalloc(sizeof(*cr), GFP_KERNEL);
if (!cr)
return ERR_PTR(-ENOMEM);
cr->cam = (e->da & MMU_CAM_VATAG_MASK) | e->prsvd | e->pgsz | e->valid;
cr->ram = e->pa | e->endian | e->elsz | e->mixed;
return cr;
}
static int load_iotlb_entry(struct omap_iommu *obj, struct iotlb_entry *e)
{
int err = 0;
struct iotlb_lock l;
struct cr_regs *cr;
if (!obj || !obj->nr_tlb_entries || !e)
return -EINVAL;
pm_runtime_get_sync(obj->dev);
iotlb_lock_get(obj, &l);
if (l.base == obj->nr_tlb_entries) {
dev_warn(obj->dev, "%s: preserve entries full\n", __func__);
err = -EBUSY;
goto out;
}
if (!e->prsvd) {
int i;
struct cr_regs tmp;
for_each_iotlb_cr(obj, obj->nr_tlb_entries, i, tmp)
if (!iotlb_cr_valid(&tmp))
break;
if (i == obj->nr_tlb_entries) {
dev_dbg(obj->dev, "%s: full: no entry\n", __func__);
err = -EBUSY;
goto out;
}
iotlb_lock_get(obj, &l);
} else {
l.vict = l.base;
iotlb_lock_set(obj, &l);
}
cr = iotlb_alloc_cr(obj, e);
if (IS_ERR(cr)) {
pm_runtime_put_sync(obj->dev);
return PTR_ERR(cr);
}
iotlb_load_cr(obj, cr);
kfree(cr);
if (e->prsvd)
l.base++;
if (++l.vict == obj->nr_tlb_entries)
l.vict = l.base;
iotlb_lock_set(obj, &l);
out:
pm_runtime_put_sync(obj->dev);
return err;
}
static int load_iotlb_entry(struct omap_iommu *obj, struct iotlb_entry *e)
{
return 0;
}
static int prefetch_iotlb_entry(struct omap_iommu *obj, struct iotlb_entry *e)
{
return load_iotlb_entry(obj, e);
}
static void flush_iotlb_page(struct omap_iommu *obj, u32 da)
{
int i;
struct cr_regs cr;
pm_runtime_get_sync(obj->dev);
for_each_iotlb_cr(obj, obj->nr_tlb_entries, i, cr) {
u32 start;
size_t bytes;
if (!iotlb_cr_valid(&cr))
continue;
start = iotlb_cr_to_virt(&cr);
bytes = iopgsz_to_bytes(cr.cam & 3);
if ((start <= da) && (da < start + bytes)) {
dev_dbg(obj->dev, "%s: %08x<=%08x(%x)\n",
__func__, start, da, bytes);
iotlb_load_cr(obj, &cr);
iommu_write_reg(obj, 1, MMU_FLUSH_ENTRY);
break;
}
}
pm_runtime_put_sync(obj->dev);
if (i == obj->nr_tlb_entries)
dev_dbg(obj->dev, "%s: no page for %08x\n", __func__, da);
}
static void flush_iotlb_all(struct omap_iommu *obj)
{
struct iotlb_lock l;
pm_runtime_get_sync(obj->dev);
l.base = 0;
l.vict = 0;
iotlb_lock_set(obj, &l);
iommu_write_reg(obj, 1, MMU_GFLUSH);
pm_runtime_put_sync(obj->dev);
}
static void flush_iopte_range(struct device *dev, dma_addr_t dma,
unsigned long offset, int num_entries)
{
size_t size = num_entries * sizeof(u32);
dma_sync_single_range_for_device(dev, dma, offset, size, DMA_TO_DEVICE);
}
static void iopte_free(struct omap_iommu *obj, u32 *iopte, bool dma_valid)
{
dma_addr_t pt_dma;
if (iopte) {
if (dma_valid) {
pt_dma = virt_to_phys(iopte);
dma_unmap_single(obj->dev, pt_dma, IOPTE_TABLE_SIZE,
DMA_TO_DEVICE);
}
kmem_cache_free(iopte_cachep, iopte);
}
}
static u32 *iopte_alloc(struct omap_iommu *obj, u32 *iopgd,
dma_addr_t *pt_dma, u32 da)
{
u32 *iopte;
unsigned long offset = iopgd_index(da) * sizeof(da);
if (*iopgd)
goto pte_ready;
spin_unlock(&obj->page_table_lock);
iopte = kmem_cache_zalloc(iopte_cachep, GFP_KERNEL);
spin_lock(&obj->page_table_lock);
if (!*iopgd) {
if (!iopte)
return ERR_PTR(-ENOMEM);
*pt_dma = dma_map_single(obj->dev, iopte, IOPTE_TABLE_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(obj->dev, *pt_dma)) {
dev_err(obj->dev, "DMA map error for L2 table\n");
iopte_free(obj, iopte, false);
return ERR_PTR(-ENOMEM);
}
if (WARN_ON(*pt_dma != virt_to_phys(iopte))) {
dev_err(obj->dev, "DMA translation error for L2 table\n");
dma_unmap_single(obj->dev, *pt_dma, IOPTE_TABLE_SIZE,
DMA_TO_DEVICE);
iopte_free(obj, iopte, false);
return ERR_PTR(-ENOMEM);
}
*iopgd = virt_to_phys(iopte) | IOPGD_TABLE;
flush_iopte_range(obj->dev, obj->pd_dma, offset, 1);
dev_vdbg(obj->dev, "%s: a new pte:%p\n", __func__, iopte);
} else {
iopte_free(obj, iopte, false);
}
pte_ready:
iopte = iopte_offset(iopgd, da);
*pt_dma = virt_to_phys(iopte);
dev_vdbg(obj->dev,
"%s: da:%08x pgd:%p *pgd:%08x pte:%p *pte:%08x\n",
__func__, da, iopgd, *iopgd, iopte, *iopte);
return iopte;
}
static int iopgd_alloc_section(struct omap_iommu *obj, u32 da, u32 pa, u32 prot)
{
u32 *iopgd = iopgd_offset(obj, da);
unsigned long offset = iopgd_index(da) * sizeof(da);
if ((da | pa) & ~IOSECTION_MASK) {
dev_err(obj->dev, "%s: %08x:%08x should aligned on %08lx\n",
__func__, da, pa, IOSECTION_SIZE);
return -EINVAL;
}
*iopgd = (pa & IOSECTION_MASK) | prot | IOPGD_SECTION;
flush_iopte_range(obj->dev, obj->pd_dma, offset, 1);
return 0;
}
static int iopgd_alloc_super(struct omap_iommu *obj, u32 da, u32 pa, u32 prot)
{
u32 *iopgd = iopgd_offset(obj, da);
unsigned long offset = iopgd_index(da) * sizeof(da);
int i;
if ((da | pa) & ~IOSUPER_MASK) {
dev_err(obj->dev, "%s: %08x:%08x should aligned on %08lx\n",
__func__, da, pa, IOSUPER_SIZE);
return -EINVAL;
}
for (i = 0; i < 16; i++)
*(iopgd + i) = (pa & IOSUPER_MASK) | prot | IOPGD_SUPER;
flush_iopte_range(obj->dev, obj->pd_dma, offset, 16);
return 0;
}
static int iopte_alloc_page(struct omap_iommu *obj, u32 da, u32 pa, u32 prot)
{
u32 *iopgd = iopgd_offset(obj, da);
dma_addr_t pt_dma;
u32 *iopte = iopte_alloc(obj, iopgd, &pt_dma, da);
unsigned long offset = iopte_index(da) * sizeof(da);
if (IS_ERR(iopte))
return PTR_ERR(iopte);
*iopte = (pa & IOPAGE_MASK) | prot | IOPTE_SMALL;
flush_iopte_range(obj->dev, pt_dma, offset, 1);
dev_vdbg(obj->dev, "%s: da:%08x pa:%08x pte:%p *pte:%08x\n",
__func__, da, pa, iopte, *iopte);
return 0;
}
static int iopte_alloc_large(struct omap_iommu *obj, u32 da, u32 pa, u32 prot)
{
u32 *iopgd = iopgd_offset(obj, da);
dma_addr_t pt_dma;
u32 *iopte = iopte_alloc(obj, iopgd, &pt_dma, da);
unsigned long offset = iopte_index(da) * sizeof(da);
int i;
if ((da | pa) & ~IOLARGE_MASK) {
dev_err(obj->dev, "%s: %08x:%08x should aligned on %08lx\n",
__func__, da, pa, IOLARGE_SIZE);
return -EINVAL;
}
if (IS_ERR(iopte))
return PTR_ERR(iopte);
for (i = 0; i < 16; i++)
*(iopte + i) = (pa & IOLARGE_MASK) | prot | IOPTE_LARGE;
flush_iopte_range(obj->dev, pt_dma, offset, 16);
return 0;
}
static int
iopgtable_store_entry_core(struct omap_iommu *obj, struct iotlb_entry *e)
{
int (*fn)(struct omap_iommu *, u32, u32, u32);
u32 prot;
int err;
if (!obj || !e)
return -EINVAL;
switch (e->pgsz) {
case MMU_CAM_PGSZ_16M:
fn = iopgd_alloc_super;
break;
case MMU_CAM_PGSZ_1M:
fn = iopgd_alloc_section;
break;
case MMU_CAM_PGSZ_64K:
fn = iopte_alloc_large;
break;
case MMU_CAM_PGSZ_4K:
fn = iopte_alloc_page;
break;
default:
fn = NULL;
break;
}
if (WARN_ON(!fn))
return -EINVAL;
prot = get_iopte_attr(e);
spin_lock(&obj->page_table_lock);
err = fn(obj, e->da, e->pa, prot);
spin_unlock(&obj->page_table_lock);
return err;
}
static int
omap_iopgtable_store_entry(struct omap_iommu *obj, struct iotlb_entry *e)
{
int err;
flush_iotlb_page(obj, e->da);
err = iopgtable_store_entry_core(obj, e);
if (!err)
prefetch_iotlb_entry(obj, e);
return err;
}
static void
iopgtable_lookup_entry(struct omap_iommu *obj, u32 da, u32 **ppgd, u32 **ppte)
{
u32 *iopgd, *iopte = NULL;
iopgd = iopgd_offset(obj, da);
if (!*iopgd)
goto out;
if (iopgd_is_table(*iopgd))
iopte = iopte_offset(iopgd, da);
out:
*ppgd = iopgd;
*ppte = iopte;
}
static size_t iopgtable_clear_entry_core(struct omap_iommu *obj, u32 da)
{
size_t bytes;
u32 *iopgd = iopgd_offset(obj, da);
int nent = 1;
dma_addr_t pt_dma;
unsigned long pd_offset = iopgd_index(da) * sizeof(da);
unsigned long pt_offset = iopte_index(da) * sizeof(da);
if (!*iopgd)
return 0;
if (iopgd_is_table(*iopgd)) {
int i;
u32 *iopte = iopte_offset(iopgd, da);
bytes = IOPTE_SIZE;
if (*iopte & IOPTE_LARGE) {
nent *= 16;
iopte = iopte_offset(iopgd, (da & IOLARGE_MASK));
}
bytes *= nent;
memset(iopte, 0, nent * sizeof(*iopte));
pt_dma = virt_to_phys(iopte);
flush_iopte_range(obj->dev, pt_dma, pt_offset, nent);
iopte = iopte_offset(iopgd, 0);
for (i = 0; i < PTRS_PER_IOPTE; i++)
if (iopte[i])
goto out;
iopte_free(obj, iopte, true);
nent = 1;
} else {
bytes = IOPGD_SIZE;
if ((*iopgd & IOPGD_SUPER) == IOPGD_SUPER) {
nent *= 16;
iopgd = iopgd_offset(obj, (da & IOSUPER_MASK));
}
bytes *= nent;
}
memset(iopgd, 0, nent * sizeof(*iopgd));
flush_iopte_range(obj->dev, obj->pd_dma, pd_offset, nent);
out:
return bytes;
}
static size_t iopgtable_clear_entry(struct omap_iommu *obj, u32 da)
{
size_t bytes;
spin_lock(&obj->page_table_lock);
bytes = iopgtable_clear_entry_core(obj, da);
flush_iotlb_page(obj, da);
spin_unlock(&obj->page_table_lock);
return bytes;
}
static void iopgtable_clear_entry_all(struct omap_iommu *obj)
{
unsigned long offset;
int i;
spin_lock(&obj->page_table_lock);
for (i = 0; i < PTRS_PER_IOPGD; i++) {
u32 da;
u32 *iopgd;
da = i << IOPGD_SHIFT;
iopgd = iopgd_offset(obj, da);
offset = iopgd_index(da) * sizeof(da);
if (!*iopgd)
continue;
if (iopgd_is_table(*iopgd))
iopte_free(obj, iopte_offset(iopgd, 0), true);
*iopgd = 0;
flush_iopte_range(obj->dev, obj->pd_dma, offset, 1);
}
flush_iotlb_all(obj);
spin_unlock(&obj->page_table_lock);
}
static irqreturn_t iommu_fault_handler(int irq, void *data)
{
u32 da, errs;
u32 *iopgd, *iopte;
struct omap_iommu *obj = data;
struct iommu_domain *domain = obj->domain;
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
if (!omap_domain->iommu_dev)
return IRQ_NONE;
errs = iommu_report_fault(obj, &da);
if (errs == 0)
return IRQ_HANDLED;
if (!report_iommu_fault(domain, obj->dev, da, 0))
return IRQ_HANDLED;
iommu_write_reg(obj, 0, MMU_IRQENABLE);
iopgd = iopgd_offset(obj, da);
if (!iopgd_is_table(*iopgd)) {
dev_err(obj->dev, "%s: errs:0x%08x da:0x%08x pgd:0x%p *pgd:px%08x\n",
obj->name, errs, da, iopgd, *iopgd);
return IRQ_NONE;
}
iopte = iopte_offset(iopgd, da);
dev_err(obj->dev, "%s: errs:0x%08x da:0x%08x pgd:0x%p *pgd:0x%08x pte:0x%p *pte:0x%08x\n",
obj->name, errs, da, iopgd, *iopgd, iopte, *iopte);
return IRQ_NONE;
}
static int omap_iommu_attach(struct omap_iommu *obj, u32 *iopgd)
{
int err;
spin_lock(&obj->iommu_lock);
obj->pd_dma = dma_map_single(obj->dev, iopgd, IOPGD_TABLE_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(obj->dev, obj->pd_dma)) {
dev_err(obj->dev, "DMA map error for L1 table\n");
err = -ENOMEM;
goto out_err;
}
obj->iopgd = iopgd;
err = iommu_enable(obj);
if (err)
goto out_err;
flush_iotlb_all(obj);
spin_unlock(&obj->iommu_lock);
dev_dbg(obj->dev, "%s: %s\n", __func__, obj->name);
return 0;
out_err:
spin_unlock(&obj->iommu_lock);
return err;
}
static void omap_iommu_detach(struct omap_iommu *obj)
{
if (!obj || IS_ERR(obj))
return;
spin_lock(&obj->iommu_lock);
dma_unmap_single(obj->dev, obj->pd_dma, IOPGD_TABLE_SIZE,
DMA_TO_DEVICE);
iommu_disable(obj);
obj->pd_dma = 0;
obj->iopgd = NULL;
spin_unlock(&obj->iommu_lock);
dev_dbg(obj->dev, "%s: %s\n", __func__, obj->name);
}
static int omap_iommu_dra7_get_dsp_system_cfg(struct platform_device *pdev,
struct omap_iommu *obj)
{
struct device_node *np = pdev->dev.of_node;
int ret;
if (!of_device_is_compatible(np, "ti,dra7-dsp-iommu"))
return 0;
if (!of_property_read_bool(np, "ti,syscon-mmuconfig")) {
dev_err(&pdev->dev, "ti,syscon-mmuconfig property is missing\n");
return -EINVAL;
}
obj->syscfg =
syscon_regmap_lookup_by_phandle(np, "ti,syscon-mmuconfig");
if (IS_ERR(obj->syscfg)) {
ret = PTR_ERR(obj->syscfg);
return ret;
}
if (of_property_read_u32_index(np, "ti,syscon-mmuconfig", 1,
&obj->id)) {
dev_err(&pdev->dev, "couldn't get the IOMMU instance id within subsystem\n");
return -EINVAL;
}
if (obj->id != 0 && obj->id != 1) {
dev_err(&pdev->dev, "invalid IOMMU instance id\n");
return -EINVAL;
}
return 0;
}
static int omap_iommu_probe(struct platform_device *pdev)
{
int err = -ENODEV;
int irq;
struct omap_iommu *obj;
struct resource *res;
struct device_node *of = pdev->dev.of_node;
if (!of) {
pr_err("%s: only DT-based devices are supported\n", __func__);
return -ENODEV;
}
obj = devm_kzalloc(&pdev->dev, sizeof(*obj) + MMU_REG_SIZE, GFP_KERNEL);
if (!obj)
return -ENOMEM;
obj->name = dev_name(&pdev->dev);
obj->nr_tlb_entries = 32;
err = of_property_read_u32(of, "ti,#tlb-entries", &obj->nr_tlb_entries);
if (err && err != -EINVAL)
return err;
if (obj->nr_tlb_entries != 32 && obj->nr_tlb_entries != 8)
return -EINVAL;
if (of_find_property(of, "ti,iommu-bus-err-back", NULL))
obj->has_bus_err_back = MMU_GP_REG_BUS_ERR_BACK_EN;
obj->dev = &pdev->dev;
obj->ctx = (void *)obj + sizeof(*obj);
spin_lock_init(&obj->iommu_lock);
spin_lock_init(&obj->page_table_lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
obj->regbase = devm_ioremap_resource(obj->dev, res);
if (IS_ERR(obj->regbase))
return PTR_ERR(obj->regbase);
err = omap_iommu_dra7_get_dsp_system_cfg(pdev, obj);
if (err)
return err;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
err = devm_request_irq(obj->dev, irq, iommu_fault_handler, IRQF_SHARED,
dev_name(obj->dev), obj);
if (err < 0)
return err;
platform_set_drvdata(pdev, obj);
obj->group = iommu_group_alloc();
if (IS_ERR(obj->group))
return PTR_ERR(obj->group);
err = iommu_device_sysfs_add(&obj->iommu, obj->dev, NULL, obj->name);
if (err)
goto out_group;
iommu_device_set_ops(&obj->iommu, &omap_iommu_ops);
err = iommu_device_register(&obj->iommu);
if (err)
goto out_sysfs;
pm_runtime_irq_safe(obj->dev);
pm_runtime_enable(obj->dev);
omap_iommu_debugfs_add(obj);
dev_info(&pdev->dev, "%s registered\n", obj->name);
return 0;
out_sysfs:
iommu_device_sysfs_remove(&obj->iommu);
out_group:
iommu_group_put(obj->group);
return err;
}
static int omap_iommu_remove(struct platform_device *pdev)
{
struct omap_iommu *obj = platform_get_drvdata(pdev);
iommu_group_put(obj->group);
obj->group = NULL;
iommu_device_sysfs_remove(&obj->iommu);
iommu_device_unregister(&obj->iommu);
omap_iommu_debugfs_remove(obj);
pm_runtime_disable(obj->dev);
dev_info(&pdev->dev, "%s removed\n", obj->name);
return 0;
}
static u32 iotlb_init_entry(struct iotlb_entry *e, u32 da, u32 pa, int pgsz)
{
memset(e, 0, sizeof(*e));
e->da = da;
e->pa = pa;
e->valid = MMU_CAM_V;
e->pgsz = pgsz;
e->endian = MMU_RAM_ENDIAN_LITTLE;
e->elsz = MMU_RAM_ELSZ_8;
e->mixed = 0;
return iopgsz_to_bytes(e->pgsz);
}
static int omap_iommu_map(struct iommu_domain *domain, unsigned long da,
phys_addr_t pa, size_t bytes, int prot)
{
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
struct omap_iommu *oiommu = omap_domain->iommu_dev;
struct device *dev = oiommu->dev;
struct iotlb_entry e;
int omap_pgsz;
u32 ret;
omap_pgsz = bytes_to_iopgsz(bytes);
if (omap_pgsz < 0) {
dev_err(dev, "invalid size to map: %d\n", bytes);
return -EINVAL;
}
dev_dbg(dev, "mapping da 0x%lx to pa %pa size 0x%x\n", da, &pa, bytes);
iotlb_init_entry(&e, da, pa, omap_pgsz);
ret = omap_iopgtable_store_entry(oiommu, &e);
if (ret)
dev_err(dev, "omap_iopgtable_store_entry failed: %d\n", ret);
return ret;
}
static size_t omap_iommu_unmap(struct iommu_domain *domain, unsigned long da,
size_t size)
{
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
struct omap_iommu *oiommu = omap_domain->iommu_dev;
struct device *dev = oiommu->dev;
dev_dbg(dev, "unmapping da 0x%lx size %u\n", da, size);
return iopgtable_clear_entry(oiommu, da);
}
static int
omap_iommu_attach_dev(struct iommu_domain *domain, struct device *dev)
{
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
struct omap_iommu_arch_data *arch_data = dev->archdata.iommu;
struct omap_iommu *oiommu;
int ret = 0;
if (!arch_data || !arch_data->iommu_dev) {
dev_err(dev, "device doesn't have an associated iommu\n");
return -EINVAL;
}
spin_lock(&omap_domain->lock);
if (omap_domain->iommu_dev) {
dev_err(dev, "iommu domain is already attached\n");
ret = -EBUSY;
goto out;
}
oiommu = arch_data->iommu_dev;
ret = omap_iommu_attach(oiommu, omap_domain->pgtable);
if (ret) {
dev_err(dev, "can't get omap iommu: %d\n", ret);
goto out;
}
omap_domain->iommu_dev = oiommu;
omap_domain->dev = dev;
oiommu->domain = domain;
out:
spin_unlock(&omap_domain->lock);
return ret;
}
static void _omap_iommu_detach_dev(struct omap_iommu_domain *omap_domain,
struct device *dev)
{
struct omap_iommu *oiommu = dev_to_omap_iommu(dev);
if (omap_domain->iommu_dev != oiommu) {
dev_err(dev, "invalid iommu device\n");
return;
}
iopgtable_clear_entry_all(oiommu);
omap_iommu_detach(oiommu);
omap_domain->iommu_dev = NULL;
omap_domain->dev = NULL;
oiommu->domain = NULL;
}
static void omap_iommu_detach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
spin_lock(&omap_domain->lock);
_omap_iommu_detach_dev(omap_domain, dev);
spin_unlock(&omap_domain->lock);
}
static struct iommu_domain *omap_iommu_domain_alloc(unsigned type)
{
struct omap_iommu_domain *omap_domain;
if (type != IOMMU_DOMAIN_UNMANAGED)
return NULL;
omap_domain = kzalloc(sizeof(*omap_domain), GFP_KERNEL);
if (!omap_domain)
goto out;
omap_domain->pgtable = kzalloc(IOPGD_TABLE_SIZE, GFP_KERNEL);
if (!omap_domain->pgtable)
goto fail_nomem;
if (WARN_ON(!IS_ALIGNED((long)omap_domain->pgtable, IOPGD_TABLE_SIZE)))
goto fail_align;
spin_lock_init(&omap_domain->lock);
omap_domain->domain.geometry.aperture_start = 0;
omap_domain->domain.geometry.aperture_end = (1ULL << 32) - 1;
omap_domain->domain.geometry.force_aperture = true;
return &omap_domain->domain;
fail_align:
kfree(omap_domain->pgtable);
fail_nomem:
kfree(omap_domain);
out:
return NULL;
}
static void omap_iommu_domain_free(struct iommu_domain *domain)
{
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
if (omap_domain->iommu_dev)
_omap_iommu_detach_dev(omap_domain, omap_domain->dev);
kfree(omap_domain->pgtable);
kfree(omap_domain);
}
static phys_addr_t omap_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t da)
{
struct omap_iommu_domain *omap_domain = to_omap_domain(domain);
struct omap_iommu *oiommu = omap_domain->iommu_dev;
struct device *dev = oiommu->dev;
u32 *pgd, *pte;
phys_addr_t ret = 0;
iopgtable_lookup_entry(oiommu, da, &pgd, &pte);
if (pte) {
if (iopte_is_small(*pte))
ret = omap_iommu_translate(*pte, da, IOPTE_MASK);
else if (iopte_is_large(*pte))
ret = omap_iommu_translate(*pte, da, IOLARGE_MASK);
else
dev_err(dev, "bogus pte 0x%x, da 0x%llx", *pte,
(unsigned long long)da);
} else {
if (iopgd_is_section(*pgd))
ret = omap_iommu_translate(*pgd, da, IOSECTION_MASK);
else if (iopgd_is_super(*pgd))
ret = omap_iommu_translate(*pgd, da, IOSUPER_MASK);
else
dev_err(dev, "bogus pgd 0x%x, da 0x%llx", *pgd,
(unsigned long long)da);
}
return ret;
}
static int omap_iommu_add_device(struct device *dev)
{
struct omap_iommu_arch_data *arch_data;
struct omap_iommu *oiommu;
struct iommu_group *group;
struct device_node *np;
struct platform_device *pdev;
int ret;
if (!dev->of_node)
return 0;
np = of_parse_phandle(dev->of_node, "iommus", 0);
if (!np)
return 0;
pdev = of_find_device_by_node(np);
if (WARN_ON(!pdev)) {
of_node_put(np);
return -EINVAL;
}
oiommu = platform_get_drvdata(pdev);
if (!oiommu) {
of_node_put(np);
return -EINVAL;
}
arch_data = kzalloc(sizeof(*arch_data), GFP_KERNEL);
if (!arch_data) {
of_node_put(np);
return -ENOMEM;
}
ret = iommu_device_link(&oiommu->iommu, dev);
if (ret) {
kfree(arch_data);
of_node_put(np);
return ret;
}
arch_data->iommu_dev = oiommu;
dev->archdata.iommu = arch_data;
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group)) {
iommu_device_unlink(&oiommu->iommu, dev);
dev->archdata.iommu = NULL;
kfree(arch_data);
return PTR_ERR(group);
}
iommu_group_put(group);
of_node_put(np);
return 0;
}
static void omap_iommu_remove_device(struct device *dev)
{
struct omap_iommu_arch_data *arch_data = dev->archdata.iommu;
if (!dev->of_node || !arch_data)
return;
iommu_device_unlink(&arch_data->iommu_dev->iommu, dev);
iommu_group_remove_device(dev);
dev->archdata.iommu = NULL;
kfree(arch_data);
}
static struct iommu_group *omap_iommu_device_group(struct device *dev)
{
struct omap_iommu_arch_data *arch_data = dev->archdata.iommu;
struct iommu_group *group = ERR_PTR(-EINVAL);
if (arch_data->iommu_dev)
group = arch_data->iommu_dev->group;
return group;
}
static int __init omap_iommu_init(void)
{
struct kmem_cache *p;
const unsigned long flags = SLAB_HWCACHE_ALIGN;
size_t align = 1 << 10;
struct device_node *np;
int ret;
np = of_find_matching_node(NULL, omap_iommu_of_match);
if (!np)
return 0;
of_node_put(np);
p = kmem_cache_create("iopte_cache", IOPTE_TABLE_SIZE, align, flags,
NULL);
if (!p)
return -ENOMEM;
iopte_cachep = p;
omap_iommu_debugfs_init();
ret = platform_driver_register(&omap_iommu_driver);
if (ret) {
pr_err("%s: failed to register driver\n", __func__);
goto fail_driver;
}
ret = bus_set_iommu(&platform_bus_type, &omap_iommu_ops);
if (ret)
goto fail_bus;
return 0;
fail_bus:
platform_driver_unregister(&omap_iommu_driver);
fail_driver:
kmem_cache_destroy(iopte_cachep);
return ret;
}
