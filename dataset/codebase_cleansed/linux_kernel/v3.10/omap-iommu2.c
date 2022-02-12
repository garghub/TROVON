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
__iommu_set_twl(obj, true);
return 0;
}
static void omap2_iommu_disable(struct omap_iommu *obj)
{
u32 l = iommu_read_reg(obj, MMU_CNTL);
l &= ~MMU_CNTL_MASK;
iommu_write_reg(obj, l, MMU_CNTL);
dev_dbg(obj->dev, "%s is shutting down\n", obj->name);
}
static void omap2_iommu_set_twl(struct omap_iommu *obj, bool on)
{
__iommu_set_twl(obj, false);
}
static u32 omap2_iommu_fault_isr(struct omap_iommu *obj, u32 *ra)
{
u32 stat, da;
u32 errs = 0;
stat = iommu_read_reg(obj, MMU_IRQSTATUS);
stat &= MMU_IRQ_MASK;
if (!stat) {
*ra = 0;
return 0;
}
da = iommu_read_reg(obj, MMU_FAULT_AD);
*ra = da;
if (stat & MMU_IRQ_TLBMISS)
errs |= OMAP_IOMMU_ERR_TLB_MISS;
if (stat & MMU_IRQ_TRANSLATIONFAULT)
errs |= OMAP_IOMMU_ERR_TRANS_FAULT;
if (stat & MMU_IRQ_EMUMISS)
errs |= OMAP_IOMMU_ERR_EMU_MISS;
if (stat & MMU_IRQ_TABLEWALKFAULT)
errs |= OMAP_IOMMU_ERR_TBLWALK_FAULT;
if (stat & MMU_IRQ_MULTIHITFAULT)
errs |= OMAP_IOMMU_ERR_MULTIHIT_FAULT;
iommu_write_reg(obj, stat, MMU_IRQSTATUS);
return errs;
}
static void omap2_tlb_read_cr(struct omap_iommu *obj, struct cr_regs *cr)
{
cr->cam = iommu_read_reg(obj, MMU_READ_CAM);
cr->ram = iommu_read_reg(obj, MMU_READ_RAM);
}
static void omap2_tlb_load_cr(struct omap_iommu *obj, struct cr_regs *cr)
{
iommu_write_reg(obj, cr->cam | MMU_CAM_V, MMU_CAM);
iommu_write_reg(obj, cr->ram, MMU_RAM);
}
static u32 omap2_cr_to_virt(struct cr_regs *cr)
{
u32 page_size = cr->cam & MMU_CAM_PGSZ_MASK;
u32 mask = get_cam_va_mask(cr->cam & page_size);
return cr->cam & mask;
}
static struct cr_regs *omap2_alloc_cr(struct omap_iommu *obj,
struct iotlb_entry *e)
{
struct cr_regs *cr;
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
static inline int omap2_cr_valid(struct cr_regs *cr)
{
return cr->cam & MMU_CAM_V;
}
static u32 omap2_get_pte_attr(struct iotlb_entry *e)
{
u32 attr;
attr = e->mixed << 5;
attr |= e->endian;
attr |= e->elsz >> 3;
attr <<= (((e->pgsz == MMU_CAM_PGSZ_4K) ||
(e->pgsz == MMU_CAM_PGSZ_64K)) ? 0 : 6);
return attr;
}
static ssize_t
omap2_dump_cr(struct omap_iommu *obj, struct cr_regs *cr, char *buf)
{
char *p = buf;
p += sprintf(p, "%08x %08x %01x\n", cr->cam, cr->ram,
(cr->cam & MMU_CAM_P) ? 1 : 0);
return p - buf;
}
static ssize_t
omap2_iommu_dump_ctx(struct omap_iommu *obj, char *buf, ssize_t len)
{
char *p = buf;
pr_reg(REVISION);
pr_reg(IRQSTATUS);
pr_reg(IRQENABLE);
pr_reg(WALKING_ST);
pr_reg(CNTL);
pr_reg(FAULT_AD);
pr_reg(TTB);
pr_reg(LOCK);
pr_reg(LD_TLB);
pr_reg(CAM);
pr_reg(RAM);
pr_reg(GFLUSH);
pr_reg(FLUSH_ENTRY);
pr_reg(READ_CAM);
pr_reg(READ_RAM);
pr_reg(EMU_FAULT_AD);
out:
return p - buf;
}
static void omap2_iommu_save_ctx(struct omap_iommu *obj)
{
int i;
u32 *p = obj->ctx;
for (i = 0; i < (MMU_REG_SIZE / sizeof(u32)); i++) {
p[i] = iommu_read_reg(obj, i * sizeof(u32));
dev_dbg(obj->dev, "%s\t[%02d] %08x\n", __func__, i, p[i]);
}
BUG_ON(p[0] != IOMMU_ARCH_VERSION);
}
static void omap2_iommu_restore_ctx(struct omap_iommu *obj)
{
int i;
u32 *p = obj->ctx;
for (i = 0; i < (MMU_REG_SIZE / sizeof(u32)); i++) {
iommu_write_reg(obj, p[i], i * sizeof(u32));
dev_dbg(obj->dev, "%s\t[%02d] %08x\n", __func__, i, p[i]);
}
BUG_ON(p[0] != IOMMU_ARCH_VERSION);
}
static void omap2_cr_to_e(struct cr_regs *cr, struct iotlb_entry *e)
{
e->da = cr->cam & MMU_CAM_VATAG_MASK;
e->pa = cr->ram & MMU_RAM_PADDR_MASK;
e->valid = cr->cam & MMU_CAM_V;
e->pgsz = cr->cam & MMU_CAM_PGSZ_MASK;
e->endian = cr->ram & MMU_RAM_ENDIAN_MASK;
e->elsz = cr->ram & MMU_RAM_ELSZ_MASK;
e->mixed = cr->ram & MMU_RAM_MIXED;
}
static int __init omap2_iommu_init(void)
{
return omap_install_iommu_arch(&omap2_iommu_ops);
}
static void __exit omap2_iommu_exit(void)
{
omap_uninstall_iommu_arch(&omap2_iommu_ops);
}
