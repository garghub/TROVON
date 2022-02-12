static int dwc2_driver_remove(struct platform_device *dev)
{
struct dwc2_hsotg *hsotg = platform_get_drvdata(dev);
dwc2_hcd_remove(hsotg);
s3c_hsotg_remove(hsotg);
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
match = of_match_device(dwc2_of_match_table, &dev->dev);
if (match && match->data) {
params = match->data;
} else {
dwc2_set_all_params(&defparams, -1);
params = &defparams;
defparams.dma_desc_enable = 0;
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
dev_dbg(hsotg->dev, "registering common handler for irq%d\n",
irq);
retval = devm_request_irq(hsotg->dev, irq,
dwc2_handle_common_intr, IRQF_SHARED,
dev_name(hsotg->dev), hsotg);
if (retval)
return retval;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
hsotg->regs = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(hsotg->regs))
return PTR_ERR(hsotg->regs);
dev_dbg(&dev->dev, "mapped PA %08lx to VA %p\n",
(unsigned long)res->start, hsotg->regs);
hsotg->dr_mode = of_usb_get_dr_mode(dev->dev.of_node);
spin_lock_init(&hsotg->lock);
mutex_init(&hsotg->init_mutex);
retval = dwc2_gadget_init(hsotg, irq);
if (retval)
return retval;
retval = dwc2_hcd_init(hsotg, irq, params);
if (retval)
return retval;
platform_set_drvdata(dev, hsotg);
return retval;
}
static int __maybe_unused dwc2_suspend(struct device *dev)
{
struct dwc2_hsotg *dwc2 = dev_get_drvdata(dev);
int ret = 0;
if (dwc2_is_device_mode(dwc2))
ret = s3c_hsotg_suspend(dwc2);
return ret;
}
static int __maybe_unused dwc2_resume(struct device *dev)
{
struct dwc2_hsotg *dwc2 = dev_get_drvdata(dev);
int ret = 0;
if (dwc2_is_device_mode(dwc2))
ret = s3c_hsotg_resume(dwc2);
return ret;
}
