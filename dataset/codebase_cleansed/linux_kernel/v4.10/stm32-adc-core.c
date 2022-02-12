static struct stm32_adc_priv *to_stm32_adc_priv(struct stm32_adc_common *com)
{
return container_of(com, struct stm32_adc_priv, common);
}
static int stm32f4_adc_clk_sel(struct platform_device *pdev,
struct stm32_adc_priv *priv)
{
unsigned long rate;
u32 val;
int i;
rate = clk_get_rate(priv->aclk);
for (i = 0; i < ARRAY_SIZE(stm32f4_pclk_div); i++) {
if ((rate / stm32f4_pclk_div[i]) <= STM32F4_ADC_MAX_CLK_RATE)
break;
}
if (i >= ARRAY_SIZE(stm32f4_pclk_div))
return -EINVAL;
val = readl_relaxed(priv->common.base + STM32F4_ADC_CCR);
val &= ~STM32F4_ADC_ADCPRE_MASK;
val |= i << STM32F4_ADC_ADCPRE_SHIFT;
writel_relaxed(val, priv->common.base + STM32F4_ADC_CCR);
dev_dbg(&pdev->dev, "Using analog clock source at %ld kHz\n",
rate / (stm32f4_pclk_div[i] * 1000));
return 0;
}
static void stm32_adc_irq_handler(struct irq_desc *desc)
{
struct stm32_adc_priv *priv = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
u32 status;
chained_irq_enter(chip, desc);
status = readl_relaxed(priv->common.base + STM32F4_ADC_CSR);
if (status & STM32F4_EOC1)
generic_handle_irq(irq_find_mapping(priv->domain, 0));
if (status & STM32F4_EOC2)
generic_handle_irq(irq_find_mapping(priv->domain, 1));
if (status & STM32F4_EOC3)
generic_handle_irq(irq_find_mapping(priv->domain, 2));
chained_irq_exit(chip, desc);
}
static int stm32_adc_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_data(irq, d->host_data);
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_level_irq);
return 0;
}
static void stm32_adc_domain_unmap(struct irq_domain *d, unsigned int irq)
{
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
static int stm32_adc_irq_probe(struct platform_device *pdev,
struct stm32_adc_priv *priv)
{
struct device_node *np = pdev->dev.of_node;
priv->irq = platform_get_irq(pdev, 0);
if (priv->irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return priv->irq;
}
priv->domain = irq_domain_add_simple(np, STM32_ADC_MAX_ADCS, 0,
&stm32_adc_domain_ops,
priv);
if (!priv->domain) {
dev_err(&pdev->dev, "Failed to add irq domain\n");
return -ENOMEM;
}
irq_set_chained_handler(priv->irq, stm32_adc_irq_handler);
irq_set_handler_data(priv->irq, priv);
return 0;
}
static void stm32_adc_irq_remove(struct platform_device *pdev,
struct stm32_adc_priv *priv)
{
int hwirq;
for (hwirq = 0; hwirq < STM32_ADC_MAX_ADCS; hwirq++)
irq_dispose_mapping(irq_find_mapping(priv->domain, hwirq));
irq_domain_remove(priv->domain);
irq_set_chained_handler(priv->irq, NULL);
}
static int stm32_adc_probe(struct platform_device *pdev)
{
struct stm32_adc_priv *priv;
struct device_node *np = pdev->dev.of_node;
struct resource *res;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->common.base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->common.base))
return PTR_ERR(priv->common.base);
priv->vref = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(priv->vref)) {
ret = PTR_ERR(priv->vref);
dev_err(&pdev->dev, "vref get failed, %d\n", ret);
return ret;
}
ret = regulator_enable(priv->vref);
if (ret < 0) {
dev_err(&pdev->dev, "vref enable failed\n");
return ret;
}
ret = regulator_get_voltage(priv->vref);
if (ret < 0) {
dev_err(&pdev->dev, "vref get voltage failed, %d\n", ret);
goto err_regulator_disable;
}
priv->common.vref_mv = ret / 1000;
dev_dbg(&pdev->dev, "vref+=%dmV\n", priv->common.vref_mv);
priv->aclk = devm_clk_get(&pdev->dev, "adc");
if (IS_ERR(priv->aclk)) {
ret = PTR_ERR(priv->aclk);
dev_err(&pdev->dev, "Can't get 'adc' clock\n");
goto err_regulator_disable;
}
ret = clk_prepare_enable(priv->aclk);
if (ret < 0) {
dev_err(&pdev->dev, "adc clk enable failed\n");
goto err_regulator_disable;
}
ret = stm32f4_adc_clk_sel(pdev, priv);
if (ret < 0) {
dev_err(&pdev->dev, "adc clk selection failed\n");
goto err_clk_disable;
}
ret = stm32_adc_irq_probe(pdev, priv);
if (ret < 0)
goto err_clk_disable;
platform_set_drvdata(pdev, &priv->common);
ret = of_platform_populate(np, NULL, NULL, &pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to populate DT children\n");
goto err_irq_remove;
}
return 0;
err_irq_remove:
stm32_adc_irq_remove(pdev, priv);
err_clk_disable:
clk_disable_unprepare(priv->aclk);
err_regulator_disable:
regulator_disable(priv->vref);
return ret;
}
static int stm32_adc_remove(struct platform_device *pdev)
{
struct stm32_adc_common *common = platform_get_drvdata(pdev);
struct stm32_adc_priv *priv = to_stm32_adc_priv(common);
of_platform_depopulate(&pdev->dev);
stm32_adc_irq_remove(pdev, priv);
clk_disable_unprepare(priv->aclk);
regulator_disable(priv->vref);
return 0;
}
