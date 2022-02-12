static irqreturn_t pruss_handler(int irq, struct uio_info *info)
{
struct uio_pruss_dev *gdev = info->priv;
int intr_bit = (irq - gdev->hostirq_start + 2);
int val, intr_mask = (1 << intr_bit);
void __iomem *base = gdev->prussio_vaddr + gdev->pintc_base;
void __iomem *intren_reg = base + PINTC_HIER;
void __iomem *intrdis_reg = base + PINTC_HIDISR;
void __iomem *intrstat_reg = base + PINTC_HIPIR + (intr_bit << 2);
val = ioread32(intren_reg);
if (!(val & intr_mask) && (ioread32(intrstat_reg) & HIPIR_NOPEND))
return IRQ_NONE;
iowrite32(intr_bit, intrdis_reg);
return IRQ_HANDLED;
}
static void pruss_cleanup(struct device *dev, struct uio_pruss_dev *gdev)
{
int cnt;
struct uio_info *p = gdev->info;
for (cnt = 0; cnt < MAX_PRUSS_EVT; cnt++, p++) {
uio_unregister_device(p);
kfree(p->name);
}
iounmap(gdev->prussio_vaddr);
if (gdev->ddr_vaddr) {
dma_free_coherent(dev, extram_pool_sz, gdev->ddr_vaddr,
gdev->ddr_paddr);
}
if (gdev->sram_vaddr)
gen_pool_free(gdev->sram_pool,
gdev->sram_vaddr,
sram_pool_sz);
kfree(gdev->info);
clk_put(gdev->pruss_clk);
kfree(gdev);
}
static int pruss_probe(struct platform_device *pdev)
{
struct uio_info *p;
struct uio_pruss_dev *gdev;
struct resource *regs_prussio;
struct device *dev = &pdev->dev;
int ret = -ENODEV, cnt = 0, len;
struct uio_pruss_pdata *pdata = dev_get_platdata(dev);
gdev = kzalloc(sizeof(struct uio_pruss_dev), GFP_KERNEL);
if (!gdev)
return -ENOMEM;
gdev->info = kzalloc(sizeof(*p) * MAX_PRUSS_EVT, GFP_KERNEL);
if (!gdev->info) {
kfree(gdev);
return -ENOMEM;
}
gdev->pruss_clk = clk_get(dev, "pruss");
if (IS_ERR(gdev->pruss_clk)) {
dev_err(dev, "Failed to get clock\n");
ret = PTR_ERR(gdev->pruss_clk);
kfree(gdev->info);
kfree(gdev);
return ret;
} else {
clk_enable(gdev->pruss_clk);
}
regs_prussio = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs_prussio) {
dev_err(dev, "No PRUSS I/O resource specified\n");
goto out_free;
}
if (!regs_prussio->start) {
dev_err(dev, "Invalid memory resource\n");
goto out_free;
}
if (pdata->sram_pool) {
gdev->sram_pool = pdata->sram_pool;
gdev->sram_vaddr =
(unsigned long)gen_pool_dma_alloc(gdev->sram_pool,
sram_pool_sz, &gdev->sram_paddr);
if (!gdev->sram_vaddr) {
dev_err(dev, "Could not allocate SRAM pool\n");
goto out_free;
}
}
gdev->ddr_vaddr = dma_alloc_coherent(dev, extram_pool_sz,
&(gdev->ddr_paddr), GFP_KERNEL | GFP_DMA);
if (!gdev->ddr_vaddr) {
dev_err(dev, "Could not allocate external memory\n");
goto out_free;
}
len = resource_size(regs_prussio);
gdev->prussio_vaddr = ioremap(regs_prussio->start, len);
if (!gdev->prussio_vaddr) {
dev_err(dev, "Can't remap PRUSS I/O address range\n");
goto out_free;
}
gdev->pintc_base = pdata->pintc_base;
gdev->hostirq_start = platform_get_irq(pdev, 0);
for (cnt = 0, p = gdev->info; cnt < MAX_PRUSS_EVT; cnt++, p++) {
p->mem[0].addr = regs_prussio->start;
p->mem[0].size = resource_size(regs_prussio);
p->mem[0].memtype = UIO_MEM_PHYS;
p->mem[1].addr = gdev->sram_paddr;
p->mem[1].size = sram_pool_sz;
p->mem[1].memtype = UIO_MEM_PHYS;
p->mem[2].addr = gdev->ddr_paddr;
p->mem[2].size = extram_pool_sz;
p->mem[2].memtype = UIO_MEM_PHYS;
p->name = kasprintf(GFP_KERNEL, "pruss_evt%d", cnt);
p->version = DRV_VERSION;
p->irq = gdev->hostirq_start + cnt;
p->handler = pruss_handler;
p->priv = gdev;
ret = uio_register_device(dev, p);
if (ret < 0)
goto out_free;
}
platform_set_drvdata(pdev, gdev);
return 0;
out_free:
pruss_cleanup(dev, gdev);
return ret;
}
static int pruss_remove(struct platform_device *dev)
{
struct uio_pruss_dev *gdev = platform_get_drvdata(dev);
pruss_cleanup(&dev->dev, gdev);
return 0;
}
