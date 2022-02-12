static int dwc2_driver_remove(struct platform_device *dev)
{
struct dwc2_hsotg *hsotg = platform_get_drvdata(dev);
dwc2_hcd_remove(hsotg);
return 0;
}
static int dwc2_driver_probe(struct platform_device *dev)
{
const struct of_device_id *match;
const struct dwc2_core_params *params;
struct dwc2_core_params defparams;
struct dwc2_hsotg *hsotg;
struct resource *res;
int retval;
int irq;
if (usb_disabled())
return -ENODEV;
match = of_match_device(dwc2_of_match_table, &dev->dev);
if (match && match->data) {
params = match->data;
} else {
dwc2_set_all_params(&defparams, -1);
params = &defparams;
}
hsotg = devm_kzalloc(&dev->dev, sizeof(*hsotg), GFP_KERNEL);
if (!hsotg)
return -ENOMEM;
hsotg->dev = &dev->dev;
if (!dev->dev.dma_mask)
dev->dev.dma_mask = &dev->dev.coherent_dma_mask;
retval = dma_set_coherent_mask(&dev->dev, DMA_BIT_MASK(32));
if (retval)
return retval;
irq = platform_get_irq(dev, 0);
if (irq < 0) {
dev_err(&dev->dev, "missing IRQ resource\n");
return irq;
}
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
hsotg->regs = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(hsotg->regs))
return PTR_ERR(hsotg->regs);
dev_dbg(&dev->dev, "mapped PA %08lx to VA %p\n",
(unsigned long)res->start, hsotg->regs);
retval = dwc2_hcd_init(hsotg, irq, params);
if (retval)
return retval;
platform_set_drvdata(dev, hsotg);
return retval;
}
