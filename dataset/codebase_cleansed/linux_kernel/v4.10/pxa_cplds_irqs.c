static irqreturn_t cplds_irq_handler(int in_irq, void *d)
{
struct cplds *fpga = d;
unsigned long pending;
unsigned int bit;
do {
pending = readl(fpga->base + FPGA_IRQ_SET_CLR) & fpga->irq_mask;
for_each_set_bit(bit, &pending, CPLDS_NB_IRQ) {
generic_handle_irq(irq_find_mapping(fpga->irqdomain,
bit));
}
} while (pending);
return IRQ_HANDLED;
}
static void cplds_irq_mask(struct irq_data *d)
{
struct cplds *fpga = irq_data_get_irq_chip_data(d);
unsigned int cplds_irq = irqd_to_hwirq(d);
unsigned int bit = BIT(cplds_irq);
fpga->irq_mask &= ~bit;
writel(fpga->irq_mask, fpga->base + FPGA_IRQ_MASK_EN);
}
static void cplds_irq_unmask(struct irq_data *d)
{
struct cplds *fpga = irq_data_get_irq_chip_data(d);
unsigned int cplds_irq = irqd_to_hwirq(d);
unsigned int set, bit = BIT(cplds_irq);
set = readl(fpga->base + FPGA_IRQ_SET_CLR);
writel(set & ~bit, fpga->base + FPGA_IRQ_SET_CLR);
fpga->irq_mask |= bit;
writel(fpga->irq_mask, fpga->base + FPGA_IRQ_MASK_EN);
}
static int cplds_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct cplds *fpga = d->host_data;
irq_set_chip_and_handler(irq, &cplds_irq_chip, handle_level_irq);
irq_set_chip_data(irq, fpga);
return 0;
}
static int cplds_resume(struct platform_device *pdev)
{
struct cplds *fpga = platform_get_drvdata(pdev);
writel(fpga->irq_mask, fpga->base + FPGA_IRQ_MASK_EN);
return 0;
}
static int cplds_probe(struct platform_device *pdev)
{
struct resource *res;
struct cplds *fpga;
int ret;
int base_irq;
unsigned long irqflags = 0;
fpga = devm_kzalloc(&pdev->dev, sizeof(*fpga), GFP_KERNEL);
if (!fpga)
return -ENOMEM;
fpga->irq = platform_get_irq(pdev, 0);
if (fpga->irq <= 0)
return fpga->irq;
base_irq = platform_get_irq(pdev, 1);
if (base_irq < 0)
base_irq = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fpga->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fpga->base))
return PTR_ERR(fpga->base);
platform_set_drvdata(pdev, fpga);
writel(fpga->irq_mask, fpga->base + FPGA_IRQ_MASK_EN);
writel(0, fpga->base + FPGA_IRQ_SET_CLR);
irqflags = irq_get_trigger_type(fpga->irq);
ret = devm_request_irq(&pdev->dev, fpga->irq, cplds_irq_handler,
irqflags, dev_name(&pdev->dev), fpga);
if (ret == -ENOSYS)
return -EPROBE_DEFER;
if (ret) {
dev_err(&pdev->dev, "couldn't request main irq%d: %d\n",
fpga->irq, ret);
return ret;
}
irq_set_irq_wake(fpga->irq, 1);
fpga->irqdomain = irq_domain_add_linear(pdev->dev.of_node,
CPLDS_NB_IRQ,
&cplds_irq_domain_ops, fpga);
if (!fpga->irqdomain)
return -ENODEV;
if (base_irq) {
ret = irq_create_strict_mappings(fpga->irqdomain, base_irq, 0,
CPLDS_NB_IRQ);
if (ret) {
dev_err(&pdev->dev, "couldn't create the irq mapping %d..%d\n",
base_irq, base_irq + CPLDS_NB_IRQ);
return ret;
}
}
return 0;
}
static int cplds_remove(struct platform_device *pdev)
{
struct cplds *fpga = platform_get_drvdata(pdev);
irq_set_chip_and_handler(fpga->irq, NULL, NULL);
return 0;
}
