static int st_irq_xlate(struct platform_device *pdev,
int device, int channel, bool irq)
{
struct st_irq_syscfg *ddata = dev_get_drvdata(&pdev->dev);
switch (device) {
case ST_IRQ_SYSCFG_EXT_0:
ddata->config |= ST_A9_IRQ_EN_EXT_0;
break;
case ST_IRQ_SYSCFG_EXT_1:
ddata->config |= ST_A9_IRQ_EN_EXT_1;
break;
case ST_IRQ_SYSCFG_EXT_2:
ddata->config |= ST_A9_IRQ_EN_EXT_2;
break;
case ST_IRQ_SYSCFG_CTI_0:
ddata->config |= ST_A9_IRQ_EN_CTI_0;
break;
case ST_IRQ_SYSCFG_CTI_1:
ddata->config |= ST_A9_IRQ_EN_CTI_1;
break;
case ST_IRQ_SYSCFG_PMU_0:
ddata->config |= ST_A9_IRQ_EN_PMU_0;
break;
case ST_IRQ_SYSCFG_PMU_1:
ddata->config |= ST_A9_IRQ_EN_PMU_1;
break;
case ST_IRQ_SYSCFG_pl310_L2:
ddata->config |= ST_A9_IRQ_EN_PL310_L2;
break;
case ST_IRQ_SYSCFG_DISABLED:
return 0;
default:
dev_err(&pdev->dev, "Unrecognised device %d\n", device);
return -EINVAL;
}
ddata->config |= irq ?
ST_A9_IRQ_N_SEL(device, channel) :
ST_A9_FIQ_N_SEL(device, channel);
return 0;
}
static int st_irq_syscfg_enable(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct st_irq_syscfg *ddata = dev_get_drvdata(&pdev->dev);
int channels, ret, i;
u32 device, invert;
channels = of_property_count_u32_elems(np, "st,irq-device");
if (channels != ST_A9_IRQ_MAX_CHANS) {
dev_err(&pdev->dev, "st,enable-irq-device must have 2 elems\n");
return -EINVAL;
}
channels = of_property_count_u32_elems(np, "st,fiq-device");
if (channels != ST_A9_IRQ_MAX_CHANS) {
dev_err(&pdev->dev, "st,enable-fiq-device must have 2 elems\n");
return -EINVAL;
}
for (i = 0; i < ST_A9_IRQ_MAX_CHANS; i++) {
of_property_read_u32_index(np, "st,irq-device", i, &device);
ret = st_irq_xlate(pdev, device, i, true);
if (ret)
return ret;
of_property_read_u32_index(np, "st,fiq-device", i, &device);
ret = st_irq_xlate(pdev, device, i, false);
if (ret)
return ret;
}
of_property_read_u32(np, "st,invert-ext", &invert);
ddata->config |= ST_A9_EXTIRQ_INV_SEL(invert);
return regmap_update_bits(ddata->regmap, ddata->syscfg,
ST_A9_IRQ_MASK, ddata->config);
}
static int st_irq_syscfg_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct st_irq_syscfg *ddata;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
match = of_match_device(st_irq_syscfg_match, &pdev->dev);
if (!match)
return -ENODEV;
ddata->syscfg = (unsigned int)match->data;
ddata->regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(ddata->regmap)) {
dev_err(&pdev->dev, "syscfg phandle missing\n");
return PTR_ERR(ddata->regmap);
}
dev_set_drvdata(&pdev->dev, ddata);
return st_irq_syscfg_enable(pdev);
}
static int st_irq_syscfg_resume(struct device *dev)
{
struct st_irq_syscfg *ddata = dev_get_drvdata(dev);
return regmap_update_bits(ddata->regmap, ddata->syscfg,
ST_A9_IRQ_MASK, ddata->config);
}
static int __init st_irq_syscfg_init(void)
{
return platform_driver_register(&st_irq_syscfg_driver);
}
