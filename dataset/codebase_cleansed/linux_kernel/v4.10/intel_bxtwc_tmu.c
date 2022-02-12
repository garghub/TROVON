static irqreturn_t bxt_wcove_tmu_irq_handler(int irq, void *data)
{
struct wcove_tmu *wctmu = data;
unsigned int tmu_irq;
regmap_read(wctmu->regmap, BXTWC_TMUIRQ, &tmu_irq);
if (tmu_irq & BXTWC_TMU_ALRM_IRQ) {
regmap_write(wctmu->regmap, BXTWC_TMUIRQ, tmu_irq);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int bxt_wcove_tmu_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
struct regmap_irq_chip_data *regmap_irq_chip;
struct wcove_tmu *wctmu;
int ret, virq, irq;
wctmu = devm_kzalloc(&pdev->dev, sizeof(*wctmu), GFP_KERNEL);
if (!wctmu)
return -ENOMEM;
wctmu->dev = &pdev->dev;
wctmu->regmap = pmic->regmap;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "invalid irq %d\n", irq);
return irq;
}
regmap_irq_chip = pmic->irq_chip_data_tmu;
virq = regmap_irq_get_virq(regmap_irq_chip, irq);
if (virq < 0) {
dev_err(&pdev->dev,
"failed to get virtual interrupt=%d\n", irq);
return virq;
}
ret = devm_request_threaded_irq(&pdev->dev, virq,
NULL, bxt_wcove_tmu_irq_handler,
IRQF_ONESHOT, "bxt_wcove_tmu", wctmu);
if (ret) {
dev_err(&pdev->dev, "request irq failed: %d,virq: %d\n",
ret, virq);
return ret;
}
wctmu->irq = virq;
regmap_update_bits(wctmu->regmap, BXTWC_MIRQLVL1,
BXTWC_MIRQLVL1_MTMU, 0);
regmap_update_bits(wctmu->regmap, BXTWC_MTMUIRQ_REG,
BXTWC_TMU_ALRM_MASK, 0);
platform_set_drvdata(pdev, wctmu);
return 0;
}
static int bxt_wcove_tmu_remove(struct platform_device *pdev)
{
struct wcove_tmu *wctmu = platform_get_drvdata(pdev);
unsigned int val;
regmap_read(wctmu->regmap, BXTWC_MIRQLVL1, &val);
regmap_write(wctmu->regmap, BXTWC_MIRQLVL1,
val | BXTWC_MIRQLVL1_MTMU);
regmap_read(wctmu->regmap, BXTWC_MTMUIRQ_REG, &val);
regmap_write(wctmu->regmap, BXTWC_MTMUIRQ_REG,
val | BXTWC_TMU_ALRM_MASK);
return 0;
}
static int bxtwc_tmu_suspend(struct device *dev)
{
struct wcove_tmu *wctmu = dev_get_drvdata(dev);
enable_irq_wake(wctmu->irq);
return 0;
}
static int bxtwc_tmu_resume(struct device *dev)
{
struct wcove_tmu *wctmu = dev_get_drvdata(dev);
disable_irq_wake(wctmu->irq);
return 0;
}
