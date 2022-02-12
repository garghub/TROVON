static void mf624_disable_interrupt(enum mf624_interrupt_source source,
struct uio_info *info)
{
void __iomem *INTCSR_reg = info->mem[0].internal_addr + INTCSR;
switch (source) {
case ADC:
iowrite32(ioread32(INTCSR_reg)
& ~(INTCSR_ADINT_ENABLE | INTCSR_PCIINT_ENABLE),
INTCSR_reg);
break;
case CTR4:
iowrite32(ioread32(INTCSR_reg)
& ~(INTCSR_CTR4INT_ENABLE | INTCSR_PCIINT_ENABLE),
INTCSR_reg);
break;
case ALL:
default:
iowrite32(ioread32(INTCSR_reg)
& ~(INTCSR_ADINT_ENABLE | INTCSR_CTR4INT_ENABLE
| INTCSR_PCIINT_ENABLE),
INTCSR_reg);
break;
}
}
static void mf624_enable_interrupt(enum mf624_interrupt_source source,
struct uio_info *info)
{
void __iomem *INTCSR_reg = info->mem[0].internal_addr + INTCSR;
switch (source) {
case ADC:
iowrite32(ioread32(INTCSR_reg)
| INTCSR_ADINT_ENABLE | INTCSR_PCIINT_ENABLE,
INTCSR_reg);
break;
case CTR4:
iowrite32(ioread32(INTCSR_reg)
| INTCSR_CTR4INT_ENABLE | INTCSR_PCIINT_ENABLE,
INTCSR_reg);
break;
case ALL:
default:
iowrite32(ioread32(INTCSR_reg)
| INTCSR_ADINT_ENABLE | INTCSR_CTR4INT_ENABLE
| INTCSR_PCIINT_ENABLE,
INTCSR_reg);
break;
}
}
static irqreturn_t mf624_irq_handler(int irq, struct uio_info *info)
{
void __iomem *INTCSR_reg = info->mem[0].internal_addr + INTCSR;
if ((ioread32(INTCSR_reg) & INTCSR_ADINT_ENABLE)
&& (ioread32(INTCSR_reg) & INTCSR_ADINT_STATUS)) {
mf624_disable_interrupt(ADC, info);
return IRQ_HANDLED;
}
if ((ioread32(INTCSR_reg) & INTCSR_CTR4INT_ENABLE)
&& (ioread32(INTCSR_reg) & INTCSR_CTR4INT_STATUS)) {
mf624_disable_interrupt(CTR4, info);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int mf624_irqcontrol(struct uio_info *info, s32 irq_on)
{
if (irq_on == 0)
mf624_disable_interrupt(ALL, info);
else if (irq_on == 1)
mf624_enable_interrupt(ALL, info);
return 0;
}
static int mf624_setup_mem(struct pci_dev *dev, int bar, struct uio_mem *mem, const char *name)
{
resource_size_t start = pci_resource_start(dev, bar);
resource_size_t len = pci_resource_len(dev, bar);
mem->name = name;
mem->addr = start & PAGE_MASK;
mem->offs = start & ~PAGE_MASK;
if (!mem->addr)
return -ENODEV;
mem->size = ((start & ~PAGE_MASK) + len + PAGE_SIZE - 1) & PAGE_MASK;
mem->memtype = UIO_MEM_PHYS;
mem->internal_addr = pci_ioremap_bar(dev, bar);
if (!mem->internal_addr)
return -ENODEV;
return 0;
}
static int mf624_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct uio_info *info;
info = kzalloc(sizeof(struct uio_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if (pci_enable_device(dev))
goto out_free;
if (pci_request_regions(dev, "mf624"))
goto out_disable;
info->name = "mf624";
info->version = "0.0.1";
if (mf624_setup_mem(dev, 0, &info->mem[0], "PCI chipset, interrupts, status "
"bits, special functions"))
goto out_release;
if (mf624_setup_mem(dev, 2, &info->mem[1], "ADC, DAC, DIO"))
goto out_unmap0;
if (mf624_setup_mem(dev, 4, &info->mem[2], "Counter/timer chip"))
goto out_unmap1;
info->irq = dev->irq;
info->irq_flags = IRQF_SHARED;
info->handler = mf624_irq_handler;
info->irqcontrol = mf624_irqcontrol;
if (uio_register_device(&dev->dev, info))
goto out_unmap2;
pci_set_drvdata(dev, info);
return 0;
out_unmap2:
iounmap(info->mem[2].internal_addr);
out_unmap1:
iounmap(info->mem[1].internal_addr);
out_unmap0:
iounmap(info->mem[0].internal_addr);
out_release:
pci_release_regions(dev);
out_disable:
pci_disable_device(dev);
out_free:
kfree(info);
return -ENODEV;
}
static void mf624_pci_remove(struct pci_dev *dev)
{
struct uio_info *info = pci_get_drvdata(dev);
mf624_disable_interrupt(ALL, info);
uio_unregister_device(info);
pci_release_regions(dev);
pci_disable_device(dev);
iounmap(info->mem[0].internal_addr);
iounmap(info->mem[1].internal_addr);
iounmap(info->mem[2].internal_addr);
kfree(info);
}
