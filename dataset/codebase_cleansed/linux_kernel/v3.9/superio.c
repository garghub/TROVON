static irqreturn_t
superio_interrupt(int parent_irq, void *devp)
{
u8 results;
u8 local_irq;
outb (OCW3_POLL,IC_PIC1+0);
results = inb(IC_PIC1+0);
if ((results & 0x80) == 0) {
return IRQ_NONE;
}
local_irq = results & 0x0f;
if (local_irq == 2 || local_irq > 7) {
printk(KERN_ERR PFX "slave interrupted!\n");
return IRQ_HANDLED;
}
if (local_irq == 7) {
outb(OCW3_ISR,IC_PIC1+0);
results = inb(IC_PIC1+0);
if ((results & 0x80) == 0) {
printk(KERN_WARNING PFX "spurious interrupt!\n");
return IRQ_HANDLED;
}
}
generic_handle_irq(local_irq);
outb((OCW2_SEOI|local_irq),IC_PIC1 + 0);
return IRQ_HANDLED;
}
static void
superio_init(struct pci_dev *pcidev)
{
struct superio_device *sio = &sio_dev;
struct pci_dev *pdev = sio->lio_pdev;
u16 word;
int ret;
if (sio->suckyio_irq_enabled)
return;
BUG_ON(!pdev);
BUG_ON(!sio->usb_pdev);
pdev->irq = sio->usb_pdev->irq;
sio->usb_pdev->irq = superio_fixup_irq(sio->usb_pdev);
printk(KERN_INFO PFX "Found NS87560 Legacy I/O device at %s (IRQ %i)\n",
pci_name(pdev), pdev->irq);
pci_read_config_dword (pdev, SIO_SP1BAR, &sio->sp1_base);
sio->sp1_base &= ~1;
printk(KERN_INFO PFX "Serial port 1 at 0x%x\n", sio->sp1_base);
pci_read_config_dword (pdev, SIO_SP2BAR, &sio->sp2_base);
sio->sp2_base &= ~1;
printk(KERN_INFO PFX "Serial port 2 at 0x%x\n", sio->sp2_base);
pci_read_config_dword (pdev, SIO_PPBAR, &sio->pp_base);
sio->pp_base &= ~1;
printk(KERN_INFO PFX "Parallel port at 0x%x\n", sio->pp_base);
pci_read_config_dword (pdev, SIO_FDCBAR, &sio->fdc_base);
sio->fdc_base &= ~1;
printk(KERN_INFO PFX "Floppy controller at 0x%x\n", sio->fdc_base);
pci_read_config_dword (pdev, SIO_ACPIBAR, &sio->acpi_base);
sio->acpi_base &= ~1;
printk(KERN_INFO PFX "ACPI at 0x%x\n", sio->acpi_base);
request_region (IC_PIC1, 0x1f, "pic1");
request_region (IC_PIC2, 0x1f, "pic2");
request_region (sio->acpi_base, 0x1f, "acpi");
pci_read_config_word (pdev, PCI_COMMAND, &word);
word |= PCI_COMMAND_SERR | PCI_COMMAND_PARITY | PCI_COMMAND_IO;
pci_write_config_word (pdev, PCI_COMMAND, word);
pci_set_master (pdev);
ret = pci_enable_device(pdev);
BUG_ON(ret < 0);
pci_write_config_dword (pdev, 0x64, 0x82000000U);
pci_write_config_dword (pdev, TRIGGER_2, 0x07654300U);
pci_write_config_dword (pdev, CFG_IR_INTAB, 0x00001000U);
pci_write_config_dword (pdev, CFG_IR_USB, 0x4c880000U);
outb (0x11,IC_PIC1+0);
outb (0x00,IC_PIC1+1);
outb (0x04,IC_PIC1+1);
outb (0x01,IC_PIC1+1);
outb (0xff,IC_PIC1+1);
outb (0xc2,IC_PIC1+0);
outb (0x11,IC_PIC2+0);
outb (0x00,IC_PIC2+1);
outb (0x02,IC_PIC2+1);
outb (0x01,IC_PIC2+1);
outb (0xff,IC_PIC1+1);
outb (0x68,IC_PIC1+0);
outb (0xff,IC_PIC1+1);
outb(1, sio->acpi_base + USB_REG_CR);
if (inb(sio->acpi_base + USB_REG_CR) & 1)
printk(KERN_INFO PFX "USB regulator enabled\n");
else
printk(KERN_ERR PFX "USB regulator not initialized!\n");
if (request_irq(pdev->irq, superio_interrupt, 0,
SUPERIO, (void *)sio)) {
printk(KERN_ERR PFX "could not get irq\n");
BUG();
return;
}
sio->suckyio_irq_enabled = 1;
}
static void superio_mask_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
u8 r8;
if ((irq < 1) || (irq == 2) || (irq > 7)) {
printk(KERN_ERR PFX "Illegal irq number.\n");
BUG();
return;
}
r8 = inb(IC_PIC1+1);
r8 |= (1 << irq);
outb (r8,IC_PIC1+1);
}
static void superio_unmask_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
u8 r8;
if ((irq < 1) || (irq == 2) || (irq > 7)) {
printk(KERN_ERR PFX "Illegal irq number (%d).\n", irq);
BUG();
return;
}
r8 = inb(IC_PIC1+1);
r8 &= ~(1 << irq);
outb (r8,IC_PIC1+1);
}
int superio_fixup_irq(struct pci_dev *pcidev)
{
int local_irq, i;
#ifdef DEBUG_SUPERIO_INIT
int fn;
fn = PCI_FUNC(pcidev->devfn);
if (expected_device[fn] != pcidev->device) {
BUG();
return -1;
}
printk("superio_fixup_irq(%s) ven 0x%x dev 0x%x from %pf\n",
pci_name(pcidev),
pcidev->vendor, pcidev->device,
__builtin_return_address(0));
#endif
for (i = 0; i < 16; i++) {
irq_set_chip_and_handler(i, &superio_interrupt_type,
handle_simple_irq);
}
switch(pcidev->device) {
case PCI_DEVICE_ID_NS_87415:
local_irq = IDE_IRQ;
break;
case PCI_DEVICE_ID_NS_87560_LIO:
sio_dev.lio_pdev = pcidev;
return -1;
case PCI_DEVICE_ID_NS_87560_USB:
sio_dev.usb_pdev = pcidev;
local_irq = USB_IRQ;
break;
default:
local_irq = -1;
BUG();
break;
}
return local_irq;
}
static void __init superio_serial_init(void)
{
#ifdef CONFIG_SERIAL_8250
int retval;
struct uart_port serial_port;
memset(&serial_port, 0, sizeof(serial_port));
serial_port.iotype = UPIO_PORT;
serial_port.type = PORT_16550A;
serial_port.uartclk = 115200*16;
serial_port.fifosize = 16;
serial_port.iobase = sio_dev.sp1_base;
serial_port.irq = SP1_IRQ;
serial_port.line = 0;
retval = early_serial_setup(&serial_port);
if (retval < 0) {
printk(KERN_WARNING PFX "Register Serial #0 failed.\n");
return;
}
serial_port.iobase = sio_dev.sp2_base;
serial_port.irq = SP2_IRQ;
serial_port.line = 1;
retval = early_serial_setup(&serial_port);
if (retval < 0)
printk(KERN_WARNING PFX "Register Serial #1 failed.\n");
#endif
}
static void __init superio_parport_init(void)
{
#ifdef CONFIG_PARPORT_PC
if (!parport_pc_probe_port(sio_dev.pp_base,
0 ,
PAR_IRQ,
PARPORT_DMA_NONE ,
NULL ,
0 ))
printk(KERN_WARNING PFX "Probing parallel port failed.\n");
#endif
}
static void superio_fixup_pci(struct pci_dev *pdev)
{
u8 prog;
pdev->class |= 0x5;
pci_write_config_byte(pdev, PCI_CLASS_PROG, pdev->class);
pci_read_config_byte(pdev, PCI_CLASS_PROG, &prog);
printk("PCI: Enabled native mode for NS87415 (pif=0x%x)\n", prog);
}
static int __init
superio_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct superio_device *sio = &sio_dev;
DBG_INIT("superio_probe(%s) ven 0x%x dev 0x%x sv 0x%x sd 0x%x class 0x%x\n",
pci_name(dev),
dev->vendor, dev->device,
dev->subsystem_vendor, dev->subsystem_device,
dev->class);
BUG_ON(!sio->suckyio_irq_enabled);
if (dev->device == PCI_DEVICE_ID_NS_87560_LIO) {
superio_parport_init();
superio_serial_init();
return 0;
} else if (dev->device == PCI_DEVICE_ID_NS_87415) {
DBG_INIT("superio_probe: ignoring IDE 87415\n");
} else if (dev->device == PCI_DEVICE_ID_NS_87560_USB) {
DBG_INIT("superio_probe: ignoring USB OHCI controller\n");
} else {
DBG_INIT("superio_probe: WTF? Fire Extinguisher?\n");
}
return -ENODEV;
}
static int __init superio_modinit(void)
{
return pci_register_driver(&superio_driver);
}
static void __exit superio_exit(void)
{
pci_unregister_driver(&superio_driver);
}
