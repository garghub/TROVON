int dwc3_host_init(struct dwc3 *dwc)
{
struct platform_device *xhci;
int ret;
xhci = platform_device_alloc("xhci-hcd", -1);
if (!xhci) {
dev_err(dwc->dev, "couldn't allocate xHCI device\n");
ret = -ENOMEM;
goto err0;
}
dma_set_coherent_mask(&xhci->dev, dwc->dev->coherent_dma_mask);
xhci->dev.parent = dwc->dev;
xhci->dev.dma_mask = dwc->dev->dma_mask;
xhci->dev.dma_parms = dwc->dev->dma_parms;
dwc->xhci = xhci;
generic_resources[0].start = dwc->irq;
generic_resources[1].start = dwc->res->start;
generic_resources[1].end = dwc->res->start + 0x7fff;
ret = platform_device_add_resources(xhci, generic_resources,
ARRAY_SIZE(generic_resources));
if (ret) {
dev_err(dwc->dev, "couldn't add resources to xHCI device\n");
goto err1;
}
ret = platform_device_add(xhci);
if (ret) {
dev_err(dwc->dev, "failed to register xHCI device\n");
goto err1;
}
return 0;
err1:
platform_device_put(xhci);
err0:
return ret;
}
void dwc3_host_exit(struct dwc3 *dwc)
{
platform_device_unregister(dwc->xhci);
}
