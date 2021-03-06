unsigned long alloc_xen_mmio(unsigned long len)
{
unsigned long addr;
addr = platform_mmio + platform_mmio_alloc;
platform_mmio_alloc += len;
BUG_ON(platform_mmio_alloc > platform_mmiolen);
return addr;
}
static uint64_t get_callback_via(struct pci_dev *pdev)
{
u8 pin;
int irq;
irq = pdev->irq;
if (irq < 16)
return irq;
pin = pdev->pin;
return ((uint64_t)0x01 << 56) |
((uint64_t)pci_domain_nr(pdev->bus) << 32) |
((uint64_t)pdev->bus->number << 16) |
((uint64_t)(pdev->devfn & 0xff) << 8) |
((uint64_t)(pin - 1) & 3);
}
static irqreturn_t do_hvm_evtchn_intr(int irq, void *dev_id)
{
xen_hvm_evtchn_do_upcall();
return IRQ_HANDLED;
}
static int xen_allocate_irq(struct pci_dev *pdev)
{
return request_irq(pdev->irq, do_hvm_evtchn_intr,
IRQF_NOBALANCING | IRQF_TRIGGER_RISING,
"xen-platform-pci", pdev);
}
static int platform_pci_resume(struct pci_dev *pdev)
{
int err;
if (xen_have_vector_callback)
return 0;
err = xen_set_callback_via(callback_via);
if (err) {
dev_err(&pdev->dev, "platform_pci_resume failure!\n");
return err;
}
return 0;
}
static int platform_pci_init(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int i, ret;
long ioaddr;
long mmio_addr, mmio_len;
unsigned int max_nr_gframes;
if (!xen_domain())
return -ENODEV;
i = pci_enable_device(pdev);
if (i)
return i;
ioaddr = pci_resource_start(pdev, 0);
mmio_addr = pci_resource_start(pdev, 1);
mmio_len = pci_resource_len(pdev, 1);
if (mmio_addr == 0 || ioaddr == 0) {
dev_err(&pdev->dev, "no resources found\n");
ret = -ENOENT;
goto pci_out;
}
ret = pci_request_region(pdev, 1, DRV_NAME);
if (ret < 0)
goto pci_out;
ret = pci_request_region(pdev, 0, DRV_NAME);
if (ret < 0)
goto mem_out;
platform_mmio = mmio_addr;
platform_mmiolen = mmio_len;
if (!xen_have_vector_callback) {
ret = xen_allocate_irq(pdev);
if (ret) {
dev_warn(&pdev->dev, "request_irq failed err=%d\n", ret);
goto out;
}
callback_via = get_callback_via(pdev);
ret = xen_set_callback_via(callback_via);
if (ret) {
dev_warn(&pdev->dev, "Unable to set the evtchn callback "
"err=%d\n", ret);
goto out;
}
}
max_nr_gframes = gnttab_max_grant_frames();
xen_hvm_resume_frames = alloc_xen_mmio(PAGE_SIZE * max_nr_gframes);
ret = gnttab_init();
if (ret)
goto out;
xenbus_probe(NULL);
return 0;
out:
pci_release_region(pdev, 0);
mem_out:
pci_release_region(pdev, 1);
pci_out:
pci_disable_device(pdev);
return ret;
}
static int __init platform_pci_module_init(void)
{
return pci_register_driver(&platform_driver);
}
