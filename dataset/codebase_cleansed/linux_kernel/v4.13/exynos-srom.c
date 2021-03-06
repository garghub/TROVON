static struct exynos_srom_reg_dump *exynos_srom_alloc_reg_dump(
const unsigned long *rdump,
unsigned long nr_rdump)
{
struct exynos_srom_reg_dump *rd;
unsigned int i;
rd = kcalloc(nr_rdump, sizeof(*rd), GFP_KERNEL);
if (!rd)
return NULL;
for (i = 0; i < nr_rdump; ++i)
rd[i].offset = rdump[i];
return rd;
}
static int exynos_srom_configure_bank(struct exynos_srom *srom,
struct device_node *np)
{
u32 bank, width, pmc = 0;
u32 timing[6];
u32 cs, bw;
if (of_property_read_u32(np, "reg", &bank))
return -EINVAL;
if (of_property_read_u32(np, "reg-io-width", &width))
width = 1;
if (of_property_read_bool(np, "samsung,srom-page-mode"))
pmc = 1 << EXYNOS_SROM_BCX__PMC__SHIFT;
if (of_property_read_u32_array(np, "samsung,srom-timing", timing,
ARRAY_SIZE(timing)))
return -EINVAL;
bank *= 4;
cs = 1 << EXYNOS_SROM_BW__BYTEENABLE__SHIFT;
if (width == 2)
cs |= 1 << EXYNOS_SROM_BW__DATAWIDTH__SHIFT;
bw = readl_relaxed(srom->reg_base + EXYNOS_SROM_BW);
bw = (bw & ~(EXYNOS_SROM_BW__CS_MASK << bank)) | (cs << bank);
writel_relaxed(bw, srom->reg_base + EXYNOS_SROM_BW);
writel_relaxed(pmc | (timing[0] << EXYNOS_SROM_BCX__TACP__SHIFT) |
(timing[1] << EXYNOS_SROM_BCX__TCAH__SHIFT) |
(timing[2] << EXYNOS_SROM_BCX__TCOH__SHIFT) |
(timing[3] << EXYNOS_SROM_BCX__TACC__SHIFT) |
(timing[4] << EXYNOS_SROM_BCX__TCOS__SHIFT) |
(timing[5] << EXYNOS_SROM_BCX__TACS__SHIFT),
srom->reg_base + EXYNOS_SROM_BC0 + bank);
return 0;
}
static int exynos_srom_probe(struct platform_device *pdev)
{
struct device_node *np, *child;
struct exynos_srom *srom;
struct device *dev = &pdev->dev;
bool bad_bank_config = false;
np = dev->of_node;
if (!np) {
dev_err(&pdev->dev, "could not find device info\n");
return -EINVAL;
}
srom = devm_kzalloc(&pdev->dev,
sizeof(struct exynos_srom), GFP_KERNEL);
if (!srom)
return -ENOMEM;
srom->dev = dev;
srom->reg_base = of_iomap(np, 0);
if (!srom->reg_base) {
dev_err(&pdev->dev, "iomap of exynos srom controller failed\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, srom);
srom->reg_offset = exynos_srom_alloc_reg_dump(exynos_srom_offsets,
ARRAY_SIZE(exynos_srom_offsets));
if (!srom->reg_offset) {
iounmap(srom->reg_base);
return -ENOMEM;
}
for_each_child_of_node(np, child) {
if (exynos_srom_configure_bank(srom, child)) {
dev_err(dev,
"Could not decode bank configuration for %s\n",
child->name);
bad_bank_config = true;
}
}
if (bad_bank_config)
return 0;
return of_platform_populate(np, NULL, NULL, dev);
}
static void exynos_srom_save(void __iomem *base,
struct exynos_srom_reg_dump *rd,
unsigned int num_regs)
{
for (; num_regs > 0; --num_regs, ++rd)
rd->value = readl(base + rd->offset);
}
static void exynos_srom_restore(void __iomem *base,
const struct exynos_srom_reg_dump *rd,
unsigned int num_regs)
{
for (; num_regs > 0; --num_regs, ++rd)
writel(rd->value, base + rd->offset);
}
static int exynos_srom_suspend(struct device *dev)
{
struct exynos_srom *srom = dev_get_drvdata(dev);
exynos_srom_save(srom->reg_base, srom->reg_offset,
ARRAY_SIZE(exynos_srom_offsets));
return 0;
}
static int exynos_srom_resume(struct device *dev)
{
struct exynos_srom *srom = dev_get_drvdata(dev);
exynos_srom_restore(srom->reg_base, srom->reg_offset,
ARRAY_SIZE(exynos_srom_offsets));
return 0;
}
