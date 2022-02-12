static int __init roadrunner_map_irq(const struct pci_dev *dev, u8 idsel,
u8 pin)
{
static int pci_card_slot_irq[] = {INTB, INTC, INTD, INTA};
static int pmc_card_slot_irq[] = {INTA, INTB, INTC, INTD};
static int usb_irq[] = {INTB, INTC, INTD, -1};
static int mini_pci_1_irq[] = {INTB, INTC, -1, -1};
static int mini_pci_2_irq[] = {INTC, INTD, -1, -1};
switch(dev->bus->number) {
case 0:
switch(dev->devfn) {
case 0x0:
break;
case 0x8:
return pci_card_slot_irq[pin - 1];
case 0x10:
return pmc_card_slot_irq[pin - 1];
case 0x18:
break;
case 0x20:
break;
default:
return NO_IRQ;
}
break;
case 1:
switch(dev->devfn) {
case 0x0:
return (pin == 1) ? INTC : -1;
case 0x8:
case 0x9:
case 0xa:
return usb_irq[pin - 1];
case 0x10:
return mini_pci_1_irq[pin-1];
case 0x18:
return mini_pci_2_irq[pin-1];
case 0x20:
return (pin == 1) ? INTA : -1;
default:
return NO_IRQ;
}
break;
default:
return NO_IRQ;
}
return NO_IRQ;
}
static void __init roadrunner_pci_preinit(void)
{
irq_set_irq_type(IRQ_ROADRUNNER_PCI_INTC, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IRQ_ROADRUNNER_PCI_INTD, IRQ_TYPE_LEVEL_LOW);
ixp23xx_pci_preinit();
}
static int __init roadrunner_pci_init(void)
{
if (machine_is_roadrunner())
pci_common_init(&roadrunner_pci);
return 0;
}
static void __init roadrunner_init(void)
{
platform_device_register(&roadrunner_flash);
IXP23XX_EXP_CS0[0] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[1] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[2] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[3] |= IXP23XX_FLASH_WRITABLE;
ixp23xx_sys_init();
}
