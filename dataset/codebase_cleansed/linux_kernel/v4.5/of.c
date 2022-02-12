void brcmf_of_probe(struct brcmf_sdio_dev *sdiodev)
{
struct device *dev = sdiodev->dev;
struct device_node *np = dev->of_node;
int irq;
u32 irqf;
u32 val;
if (!np || !of_device_is_compatible(np, "brcm,bcm4329-fmac"))
return;
sdiodev->pdata = devm_kzalloc(dev, sizeof(*sdiodev->pdata), GFP_KERNEL);
if (!sdiodev->pdata)
return;
if (of_property_read_u32(np, "brcm,drive-strength", &val) == 0)
sdiodev->pdata->drive_strength = val;
if (!of_find_property(np, "interrupts", NULL))
return;
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
brcmf_err("interrupt could not be mapped\n");
return;
}
irqf = irqd_get_trigger_type(irq_get_irq_data(irq));
sdiodev->pdata->oob_irq_supported = true;
sdiodev->pdata->oob_irq_nr = irq;
sdiodev->pdata->oob_irq_flags = irqf;
}
