static int sun4i_gpadc_probe(struct platform_device *pdev)
{
struct sun4i_gpadc_dev *dev;
struct resource *mem;
const struct of_device_id *of_id;
const struct mfd_cell *cells;
unsigned int irq, size;
int ret;
of_id = of_match_node(sun4i_gpadc_of_match, pdev->dev.of_node);
if (!of_id)
return -EINVAL;
switch ((long)of_id->data) {
case ARCH_SUN4I_A10:
cells = sun4i_gpadc_cells;
size = ARRAY_SIZE(sun4i_gpadc_cells);
break;
case ARCH_SUN5I_A13:
cells = sun5i_gpadc_cells;
size = ARRAY_SIZE(sun5i_gpadc_cells);
break;
case ARCH_SUN6I_A31:
cells = sun6i_gpadc_cells;
size = ARRAY_SIZE(sun6i_gpadc_cells);
break;
default:
return -EINVAL;
}
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dev->base))
return PTR_ERR(dev->base);
dev->dev = &pdev->dev;
dev_set_drvdata(dev->dev, dev);
dev->regmap = devm_regmap_init_mmio(dev->dev, dev->base,
&sun4i_gpadc_regmap_config);
if (IS_ERR(dev->regmap)) {
ret = PTR_ERR(dev->regmap);
dev_err(&pdev->dev, "failed to init regmap: %d\n", ret);
return ret;
}
regmap_write(dev->regmap, SUN4I_GPADC_INT_FIFOC, 0);
irq = platform_get_irq(pdev, 0);
ret = devm_regmap_add_irq_chip(&pdev->dev, dev->regmap, irq,
IRQF_ONESHOT, 0,
&sun4i_gpadc_regmap_irq_chip,
&dev->regmap_irqc);
if (ret) {
dev_err(&pdev->dev, "failed to add irq chip: %d\n", ret);
return ret;
}
ret = devm_mfd_add_devices(dev->dev, 0, cells, size, NULL, 0, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to add MFD devices: %d\n", ret);
return ret;
}
return 0;
}
