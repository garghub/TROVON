static void isp1760_init_core(struct isp1760_device *isp)
{
u32 otgctrl;
u32 hwmode;
if (isp->rst_gpio) {
gpiod_set_value_cansleep(isp->rst_gpio, 1);
mdelay(50);
gpiod_set_value_cansleep(isp->rst_gpio, 0);
}
isp1760_write32(isp->regs, HC_RESET_REG, SW_RESET_RESET_ALL);
msleep(100);
hwmode = HW_DATA_BUS_32BIT;
if (isp->devflags & ISP1760_FLAG_BUS_WIDTH_16)
hwmode &= ~HW_DATA_BUS_32BIT;
if (isp->devflags & ISP1760_FLAG_ANALOG_OC)
hwmode |= HW_ANA_DIGI_OC;
if (isp->devflags & ISP1760_FLAG_DACK_POL_HIGH)
hwmode |= HW_DACK_POL_HIGH;
if (isp->devflags & ISP1760_FLAG_DREQ_POL_HIGH)
hwmode |= HW_DREQ_POL_HIGH;
if (isp->devflags & ISP1760_FLAG_INTR_POL_HIGH)
hwmode |= HW_INTR_HIGH_ACT;
if (isp->devflags & ISP1760_FLAG_INTR_EDGE_TRIG)
hwmode |= HW_INTR_EDGE_TRIG;
if (isp->devflags & ISP1760_FLAG_ISP1761) {
isp1760_write32(isp->regs, DC_MODE, 0);
hwmode |= HW_COMN_IRQ;
}
isp1760_write32(isp->regs, HC_HW_MODE_CTRL, hwmode);
isp1760_write32(isp->regs, HC_HW_MODE_CTRL, hwmode);
if ((isp->devflags & ISP1760_FLAG_ISP1761) &&
(isp->devflags & ISP1760_FLAG_OTG_EN))
otgctrl = ((HW_DM_PULLDOWN | HW_DP_PULLDOWN) << 16)
| HW_OTG_DISABLE;
else
otgctrl = (HW_SW_SEL_HC_DC << 16)
| (HW_VBUS_DRV | HW_SEL_CP_EXT);
isp1760_write32(isp->regs, HC_PORT1_CTRL, otgctrl);
dev_info(isp->dev, "bus width: %u, oc: %s\n",
isp->devflags & ISP1760_FLAG_BUS_WIDTH_16 ? 16 : 32,
isp->devflags & ISP1760_FLAG_ANALOG_OC ? "analog" : "digital");
}
void isp1760_set_pullup(struct isp1760_device *isp, bool enable)
{
isp1760_write32(isp->regs, HW_OTG_CTRL_SET,
enable ? HW_DP_PULLUP : HW_DP_PULLUP << 16);
}
int isp1760_register(struct resource *mem, int irq, unsigned long irqflags,
struct device *dev, unsigned int devflags)
{
struct isp1760_device *isp;
bool udc_disabled = !(devflags & ISP1760_FLAG_ISP1761);
int ret;
if ((!IS_ENABLED(CONFIG_USB_ISP1760_HCD) || usb_disabled()) &&
(!IS_ENABLED(CONFIG_USB_ISP1761_UDC) || udc_disabled))
return -ENODEV;
dev->dma_mask = NULL;
isp = devm_kzalloc(dev, sizeof(*isp), GFP_KERNEL);
if (!isp)
return -ENOMEM;
isp->dev = dev;
isp->devflags = devflags;
isp->rst_gpio = devm_gpiod_get_optional(dev, NULL, GPIOD_OUT_HIGH);
if (IS_ERR(isp->rst_gpio))
return PTR_ERR(isp->rst_gpio);
isp->regs = devm_ioremap_resource(dev, mem);
if (IS_ERR(isp->regs))
return PTR_ERR(isp->regs);
isp1760_init_core(isp);
if (IS_ENABLED(CONFIG_USB_ISP1760_HCD) && !usb_disabled()) {
ret = isp1760_hcd_register(&isp->hcd, isp->regs, mem, irq,
irqflags | IRQF_SHARED, dev);
if (ret < 0)
return ret;
}
if (IS_ENABLED(CONFIG_USB_ISP1761_UDC) && !udc_disabled) {
ret = isp1760_udc_register(isp, irq, irqflags);
if (ret < 0) {
isp1760_hcd_unregister(&isp->hcd);
return ret;
}
}
dev_set_drvdata(dev, isp);
return 0;
}
void isp1760_unregister(struct device *dev)
{
struct isp1760_device *isp = dev_get_drvdata(dev);
isp1760_udc_unregister(isp);
isp1760_hcd_unregister(&isp->hcd);
}
