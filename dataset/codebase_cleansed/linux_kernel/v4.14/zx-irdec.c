static void zx_irdec_set_mask(struct zx_irdec *irdec, unsigned int reg,
u32 mask, u32 value)
{
u32 data;
data = readl(irdec->base + reg);
data &= ~mask;
data |= value & mask;
writel(data, irdec->base + reg);
}
static irqreturn_t zx_irdec_irq(int irq, void *dev_id)
{
struct zx_irdec *irdec = dev_id;
u8 address, not_address;
u8 command, not_command;
u32 rawcode, scancode;
enum rc_proto rc_proto;
writel(1, irdec->base + ZX_IR_INTSTCLR);
if (readl(irdec->base + ZX_IR_CNUM) & ZX_NECRPT) {
rc_repeat(irdec->rcd);
goto done;
}
rawcode = readl(irdec->base + ZX_IR_CODE);
not_command = (rawcode >> 24) & 0xff;
command = (rawcode >> 16) & 0xff;
not_address = (rawcode >> 8) & 0xff;
address = rawcode & 0xff;
scancode = ir_nec_bytes_to_scancode(address, not_address,
command, not_command,
&rc_proto);
rc_keydown(irdec->rcd, rc_proto, scancode, 0);
done:
return IRQ_HANDLED;
}
static int zx_irdec_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct zx_irdec *irdec;
struct resource *res;
struct rc_dev *rcd;
int irq;
int ret;
irdec = devm_kzalloc(dev, sizeof(*irdec), GFP_KERNEL);
if (!irdec)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irdec->base = devm_ioremap_resource(dev, res);
if (IS_ERR(irdec->base))
return PTR_ERR(irdec->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
rcd = devm_rc_allocate_device(dev, RC_DRIVER_SCANCODE);
if (!rcd) {
dev_err(dev, "failed to allocate rc device\n");
return -ENOMEM;
}
irdec->rcd = rcd;
rcd->priv = irdec;
rcd->input_phys = DRIVER_NAME "/input0";
rcd->input_id.bustype = BUS_HOST;
rcd->map_name = RC_MAP_ZX_IRDEC;
rcd->allowed_protocols = RC_PROTO_BIT_NEC | RC_PROTO_BIT_NECX |
RC_PROTO_BIT_NEC32;
rcd->driver_name = DRIVER_NAME;
rcd->device_name = DRIVER_NAME;
platform_set_drvdata(pdev, irdec);
ret = devm_rc_register_device(dev, rcd);
if (ret) {
dev_err(dev, "failed to register rc device\n");
return ret;
}
ret = devm_request_irq(dev, irq, zx_irdec_irq, 0, NULL, irdec);
if (ret) {
dev_err(dev, "failed to request irq\n");
return ret;
}
zx_irdec_set_mask(irdec, ZX_IR_CTRL, ZX_DEGL_MASK, ZX_DEGL_VALUE(0));
zx_irdec_set_mask(irdec, ZX_IR_CTRL, ZX_WDBEGIN_MASK,
ZX_WDBEGIN_VALUE(0x21c));
writel(1, irdec->base + ZX_IR_INTEN);
zx_irdec_set_mask(irdec, ZX_IR_ENABLE, ZX_IREN, ZX_IREN);
return 0;
}
static int zx_irdec_remove(struct platform_device *pdev)
{
struct zx_irdec *irdec = platform_get_drvdata(pdev);
zx_irdec_set_mask(irdec, ZX_IR_ENABLE, ZX_IREN, 0);
writel(0, irdec->base + ZX_IR_INTEN);
return 0;
}
