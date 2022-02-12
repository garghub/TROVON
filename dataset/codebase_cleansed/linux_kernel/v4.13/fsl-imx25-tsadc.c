static void mx25_tsadc_irq_handler(struct irq_desc *desc)
{
struct mx25_tsadc *tsadc = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
u32 status;
chained_irq_enter(chip, desc);
regmap_read(tsadc->regs, MX25_TSC_TGSR, &status);
if (status & MX25_TGSR_GCQ_INT)
generic_handle_irq(irq_find_mapping(tsadc->domain, 1));
if (status & MX25_TGSR_TCQ_INT)
generic_handle_irq(irq_find_mapping(tsadc->domain, 0));
chained_irq_exit(chip, desc);
}
static int mx25_tsadc_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct mx25_tsadc *tsadc = d->host_data;
irq_set_chip_data(irq, tsadc);
irq_set_chip_and_handler(irq, &dummy_irq_chip,
handle_level_irq);
irq_modify_status(irq, IRQ_NOREQUEST, IRQ_NOPROBE);
return 0;
}
static int mx25_tsadc_setup_irq(struct platform_device *pdev,
struct mx25_tsadc *tsadc)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
int irq;
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "Failed to get irq\n");
return irq;
}
tsadc->domain = irq_domain_add_simple(np, 2, 0, &mx25_tsadc_domain_ops,
tsadc);
if (!tsadc->domain) {
dev_err(dev, "Failed to add irq domain\n");
return -ENOMEM;
}
irq_set_chained_handler(irq, mx25_tsadc_irq_handler);
irq_set_handler_data(irq, tsadc);
return 0;
}
static void mx25_tsadc_setup_clk(struct platform_device *pdev,
struct mx25_tsadc *tsadc)
{
unsigned clk_div;
dev_dbg(&pdev->dev, "Found master clock at %lu Hz\n",
clk_get_rate(tsadc->clk));
clk_div = DIV_ROUND_UP(clk_get_rate(tsadc->clk), 1750000);
dev_dbg(&pdev->dev, "Setting up ADC clock divider to %u\n", clk_div);
clk_div -= 2;
clk_div /= 2;
clk_div = max_t(unsigned, 4, clk_div);
dev_dbg(&pdev->dev, "Resulting ADC conversion clock at %lu Hz\n",
clk_get_rate(tsadc->clk) / (2 * clk_div + 2));
regmap_update_bits(tsadc->regs, MX25_TSC_TGCR,
MX25_TGCR_ADCCLKCFG(0x1f),
MX25_TGCR_ADCCLKCFG(clk_div));
}
static int mx25_tsadc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mx25_tsadc *tsadc;
struct resource *res;
int ret;
void __iomem *iomem;
tsadc = devm_kzalloc(dev, sizeof(*tsadc), GFP_KERNEL);
if (!tsadc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iomem = devm_ioremap_resource(dev, res);
if (IS_ERR(iomem))
return PTR_ERR(iomem);
tsadc->regs = devm_regmap_init_mmio(dev, iomem,
&mx25_tsadc_regmap_config);
if (IS_ERR(tsadc->regs)) {
dev_err(dev, "Failed to initialize regmap\n");
return PTR_ERR(tsadc->regs);
}
tsadc->clk = devm_clk_get(dev, "ipg");
if (IS_ERR(tsadc->clk)) {
dev_err(dev, "Failed to get ipg clock\n");
return PTR_ERR(tsadc->clk);
}
mx25_tsadc_setup_clk(pdev, tsadc);
regmap_update_bits(tsadc->regs, MX25_TSC_TGCR, MX25_TGCR_CLK_EN,
MX25_TGCR_CLK_EN);
regmap_update_bits(tsadc->regs, MX25_TSC_TGCR, MX25_TGCR_TSC_RST,
MX25_TGCR_TSC_RST);
regmap_update_bits(tsadc->regs, MX25_TSC_TGCR, MX25_TGCR_POWERMODE_MASK,
MX25_TGCR_POWERMODE_SAVE);
regmap_update_bits(tsadc->regs, MX25_TSC_TGCR, MX25_TGCR_INTREFEN,
MX25_TGCR_INTREFEN);
ret = mx25_tsadc_setup_irq(pdev, tsadc);
if (ret)
return ret;
platform_set_drvdata(pdev, tsadc);
return devm_of_platform_populate(dev);
}
