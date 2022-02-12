static void fpu_begin(void)
{
kernel_fpu_begin();
}
static void fpu_end(void)
{
kernel_fpu_end();
}
static irqreturn_t v_ADDI_Interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
const struct addi_board *this_board = comedi_board(dev);
this_board->interrupt(irq, d);
return IRQ_RETVAL(1);
}
static const void *apci1710_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct addi_board *this_board;
int i;
for (i = 0; i < ARRAY_SIZE(apci1710_boardtypes); i++) {
this_board = &apci1710_boardtypes[i];
if (this_board->i_VendorId == pcidev->vendor &&
this_board->i_DeviceId == pcidev->device)
return this_board;
}
return NULL;
}
static int apci1710_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct addi_board *this_board;
struct addi_private *devpriv;
struct comedi_subdevice *s;
int ret;
this_board = apci1710_find_boardinfo(dev, pcidev);
if (!this_board)
return -ENODEV;
dev->board_ptr = this_board;
dev->board_name = this_board->pc_DriverName;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
if (this_board->i_IorangeBase1)
dev->iobase = pci_resource_start(pcidev, 1);
else
dev->iobase = pci_resource_start(pcidev, 0);
devpriv->iobase = dev->iobase;
devpriv->i_IobaseAmcc = pci_resource_start(pcidev, 0);
devpriv->i_IobaseAddon = pci_resource_start(pcidev, 2);
devpriv->i_IobaseReserved = pci_resource_start(pcidev, 3);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, v_ADDI_Interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
i_ADDI_AttachPCI1710(dev);
devpriv->s_BoardInfos.ui_Address = pci_resource_start(pcidev, 2);
i_APCI1710_Reset(dev);
return 0;
}
static void apci1710_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->iobase)
i_APCI1710_Reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int apci1710_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci1710_driver);
}
