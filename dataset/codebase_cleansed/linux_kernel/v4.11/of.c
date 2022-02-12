void brcmf_of_probe(struct device *dev, enum brcmf_bus_type bus_type,
struct brcmf_mp_device *settings)
{
struct brcmfmac_sdio_pd *sdio = &settings->bus.sdio;
struct device_node *np = dev->of_node;
int irq;
u32 irqf;
u32 val;
if (!np || bus_type != BRCMF_BUSTYPE_SDIO ||
!of_device_is_compatible(np, "brcm,bcm4329-fmac"))
return;
if (of_property_read_u32(np, "brcm,drive-strength", &val) == 0)
sdio->drive_strength = val;
if (!of_find_property(np, "interrupts", NULL))
return;
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
brcmf_err("interrupt could not be mapped\n");
return;
}
irqf = irqd_get_trigger_type(irq_get_irq_data(irq));
sdio->oob_irq_supported = true;
sdio->oob_irq_nr = irq;
sdio->oob_irq_flags = irqf;
}
