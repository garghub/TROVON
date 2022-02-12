static inline void jz4740_adc_irq_set_masked(struct jz4740_adc *adc, int irq,
bool masked)
{
unsigned long flags;
uint8_t val;
irq -= adc->irq_base;
spin_lock_irqsave(&adc->lock, flags);
val = readb(adc->base + JZ_REG_ADC_CTRL);
if (masked)
val |= BIT(irq);
else
val &= ~BIT(irq);
writeb(val, adc->base + JZ_REG_ADC_CTRL);
spin_unlock_irqrestore(&adc->lock, flags);
}
static void jz4740_adc_irq_mask(struct irq_data *data)
{
struct jz4740_adc *adc = irq_data_get_irq_chip_data(data);
jz4740_adc_irq_set_masked(adc, data->irq, true);
}
static void jz4740_adc_irq_unmask(struct irq_data *data)
{
struct jz4740_adc *adc = irq_data_get_irq_chip_data(data);
jz4740_adc_irq_set_masked(adc, data->irq, false);
}
static void jz4740_adc_irq_ack(struct irq_data *data)
{
struct jz4740_adc *adc = irq_data_get_irq_chip_data(data);
unsigned int irq = data->irq - adc->irq_base;
writeb(BIT(irq), adc->base + JZ_REG_ADC_STATUS);
}
static void jz4740_adc_irq_demux(unsigned int irq, struct irq_desc *desc)
{
struct jz4740_adc *adc = irq_desc_get_handler_data(desc);
uint8_t status;
unsigned int i;
status = readb(adc->base + JZ_REG_ADC_STATUS);
for (i = 0; i < 5; ++i) {
if (status & BIT(i))
generic_handle_irq(adc->irq_base + i);
}
}
static inline void jz4740_adc_clk_enable(struct jz4740_adc *adc)
{
if (atomic_inc_return(&adc->clk_ref) == 1)
clk_enable(adc->clk);
}
static inline void jz4740_adc_clk_disable(struct jz4740_adc *adc)
{
if (atomic_dec_return(&adc->clk_ref) == 0)
clk_disable(adc->clk);
}
static inline void jz4740_adc_set_enabled(struct jz4740_adc *adc, int engine,
bool enabled)
{
unsigned long flags;
uint8_t val;
spin_lock_irqsave(&adc->lock, flags);
val = readb(adc->base + JZ_REG_ADC_ENABLE);
if (enabled)
val |= BIT(engine);
else
val &= ~BIT(engine);
writeb(val, adc->base + JZ_REG_ADC_ENABLE);
spin_unlock_irqrestore(&adc->lock, flags);
}
static int jz4740_adc_cell_enable(struct platform_device *pdev)
{
struct jz4740_adc *adc = dev_get_drvdata(pdev->dev.parent);
jz4740_adc_clk_enable(adc);
jz4740_adc_set_enabled(adc, pdev->id, true);
return 0;
}
static int jz4740_adc_cell_disable(struct platform_device *pdev)
{
struct jz4740_adc *adc = dev_get_drvdata(pdev->dev.parent);
jz4740_adc_set_enabled(adc, pdev->id, false);
jz4740_adc_clk_disable(adc);
return 0;
}
int jz4740_adc_set_config(struct device *dev, uint32_t mask, uint32_t val)
{
struct jz4740_adc *adc = dev_get_drvdata(dev);
unsigned long flags;
uint32_t cfg;
if (!adc)
return -ENODEV;
spin_lock_irqsave(&adc->lock, flags);
cfg = readl(adc->base + JZ_REG_ADC_CFG);
cfg &= ~mask;
cfg |= val;
writel(cfg, adc->base + JZ_REG_ADC_CFG);
spin_unlock_irqrestore(&adc->lock, flags);
return 0;
}
static int __devinit jz4740_adc_probe(struct platform_device *pdev)
{
int ret;
struct jz4740_adc *adc;
struct resource *mem_base;
int irq;
adc = kmalloc(sizeof(*adc), GFP_KERNEL);
if (!adc) {
dev_err(&pdev->dev, "Failed to allocate driver structure\n");
return -ENOMEM;
}
adc->irq = platform_get_irq(pdev, 0);
if (adc->irq < 0) {
ret = adc->irq;
dev_err(&pdev->dev, "Failed to get platform irq: %d\n", ret);
goto err_free;
}
adc->irq_base = platform_get_irq(pdev, 1);
if (adc->irq_base < 0) {
ret = adc->irq_base;
dev_err(&pdev->dev, "Failed to get irq base: %d\n", ret);
goto err_free;
}
mem_base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_base) {
ret = -ENOENT;
dev_err(&pdev->dev, "Failed to get platform mmio resource\n");
goto err_free;
}
adc->mem = request_mem_region(mem_base->start, JZ_REG_ADC_STATUS,
pdev->name);
if (!adc->mem) {
ret = -EBUSY;
dev_err(&pdev->dev, "Failed to request mmio memory region\n");
goto err_free;
}
adc->base = ioremap_nocache(adc->mem->start, resource_size(adc->mem));
if (!adc->base) {
ret = -EBUSY;
dev_err(&pdev->dev, "Failed to ioremap mmio memory\n");
goto err_release_mem_region;
}
adc->clk = clk_get(&pdev->dev, "adc");
if (IS_ERR(adc->clk)) {
ret = PTR_ERR(adc->clk);
dev_err(&pdev->dev, "Failed to get clock: %d\n", ret);
goto err_iounmap;
}
spin_lock_init(&adc->lock);
atomic_set(&adc->clk_ref, 0);
platform_set_drvdata(pdev, adc);
for (irq = adc->irq_base; irq < adc->irq_base + 5; ++irq) {
irq_set_chip_data(irq, adc);
irq_set_chip_and_handler(irq, &jz4740_adc_irq_chip,
handle_level_irq);
}
irq_set_handler_data(adc->irq, adc);
irq_set_chained_handler(adc->irq, jz4740_adc_irq_demux);
writeb(0x00, adc->base + JZ_REG_ADC_ENABLE);
writeb(0xff, adc->base + JZ_REG_ADC_CTRL);
ret = mfd_add_devices(&pdev->dev, 0, jz4740_adc_cells,
ARRAY_SIZE(jz4740_adc_cells), mem_base, adc->irq_base);
if (ret < 0)
goto err_clk_put;
return 0;
err_clk_put:
clk_put(adc->clk);
err_iounmap:
platform_set_drvdata(pdev, NULL);
iounmap(adc->base);
err_release_mem_region:
release_mem_region(adc->mem->start, resource_size(adc->mem));
err_free:
kfree(adc);
return ret;
}
static int __devexit jz4740_adc_remove(struct platform_device *pdev)
{
struct jz4740_adc *adc = platform_get_drvdata(pdev);
mfd_remove_devices(&pdev->dev);
irq_set_handler_data(adc->irq, NULL);
irq_set_chained_handler(adc->irq, NULL);
iounmap(adc->base);
release_mem_region(adc->mem->start, resource_size(adc->mem));
clk_put(adc->clk);
platform_set_drvdata(pdev, NULL);
kfree(adc);
return 0;
}
static int __init jz4740_adc_init(void)
{
return platform_driver_register(&jz4740_adc_driver);
}
static void __exit jz4740_adc_exit(void)
{
platform_driver_unregister(&jz4740_adc_driver);
}
