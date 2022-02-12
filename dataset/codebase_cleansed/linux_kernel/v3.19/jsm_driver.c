static int jsm_probe_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc = 0;
struct jsm_board *brd;
static int adapter_count;
rc = pci_enable_device(pdev);
if (rc) {
dev_err(&pdev->dev, "Device enable FAILED\n");
goto out;
}
rc = pci_request_regions(pdev, "jsm");
if (rc) {
dev_err(&pdev->dev, "pci_request_region FAILED\n");
goto out_disable_device;
}
brd = kzalloc(sizeof(*brd), GFP_KERNEL);
if (!brd) {
rc = -ENOMEM;
goto out_release_regions;
}
brd->boardnum = adapter_count++;
brd->pci_dev = pdev;
switch (pdev->device) {
case PCI_DEVICE_ID_NEO_2DB9:
case PCI_DEVICE_ID_NEO_2DB9PRI:
case PCI_DEVICE_ID_NEO_2RJ45:
case PCI_DEVICE_ID_NEO_2RJ45PRI:
case PCI_DEVICE_ID_NEO_2_422_485:
brd->maxports = 2;
break;
case PCI_DEVICE_ID_CLASSIC_4:
case PCI_DEVICE_ID_CLASSIC_4_422:
case PCI_DEVICE_ID_NEO_4:
case PCIE_DEVICE_ID_NEO_4:
case PCIE_DEVICE_ID_NEO_4RJ45:
case PCIE_DEVICE_ID_NEO_4_IBM:
brd->maxports = 4;
break;
case PCI_DEVICE_ID_CLASSIC_8:
case PCI_DEVICE_ID_CLASSIC_8_422:
case PCI_DEVICE_ID_DIGI_NEO_8:
case PCIE_DEVICE_ID_NEO_8:
case PCIE_DEVICE_ID_NEO_8RJ45:
brd->maxports = 8;
break;
default:
brd->maxports = 1;
break;
}
spin_lock_init(&brd->bd_intr_lock);
brd->rev = pdev->revision;
brd->irq = pdev->irq;
switch (pdev->device) {
case PCI_DEVICE_ID_CLASSIC_4:
case PCI_DEVICE_ID_CLASSIC_4_422:
case PCI_DEVICE_ID_CLASSIC_8:
case PCI_DEVICE_ID_CLASSIC_8_422:
jsm_dbg(INIT, &brd->pci_dev,
"jsm_found_board - Classic adapter\n");
brd->membase = pci_resource_start(pdev, 4);
brd->membase_end = pci_resource_end(pdev, 4);
if (brd->membase & 0x1)
brd->membase &= ~0x3;
else
brd->membase &= ~0xF;
brd->iobase = pci_resource_start(pdev, 1);
brd->iobase_end = pci_resource_end(pdev, 1);
brd->iobase = ((unsigned int)(brd->iobase)) & 0xFFFE;
brd->bd_ops = &jsm_cls_ops;
brd->bd_uart_offset = 0x8;
brd->bd_dividend = 921600;
brd->re_map_membase = ioremap(brd->membase,
pci_resource_len(pdev, 4));
if (!brd->re_map_membase) {
dev_err(&pdev->dev,
"Card has no PCI Memory resources, failing board.\n");
rc = -ENOMEM;
goto out_kfree_brd;
}
outb(0x43, brd->iobase + 0x4c);
break;
case PCI_DEVICE_ID_NEO_2DB9:
case PCI_DEVICE_ID_NEO_2DB9PRI:
case PCI_DEVICE_ID_NEO_2RJ45:
case PCI_DEVICE_ID_NEO_2RJ45PRI:
case PCI_DEVICE_ID_NEO_2_422_485:
case PCI_DEVICE_ID_NEO_4:
case PCIE_DEVICE_ID_NEO_4:
case PCIE_DEVICE_ID_NEO_4RJ45:
case PCIE_DEVICE_ID_NEO_4_IBM:
case PCI_DEVICE_ID_DIGI_NEO_8:
case PCIE_DEVICE_ID_NEO_8:
case PCIE_DEVICE_ID_NEO_8RJ45:
jsm_dbg(INIT, &brd->pci_dev, "jsm_found_board - NEO adapter\n");
brd->membase = pci_resource_start(pdev, 0);
brd->membase_end = pci_resource_end(pdev, 0);
if (brd->membase & 1)
brd->membase &= ~0x3;
else
brd->membase &= ~0xF;
brd->bd_ops = &jsm_neo_ops;
brd->bd_uart_offset = 0x200;
brd->bd_dividend = 921600;
brd->re_map_membase = ioremap(brd->membase,
pci_resource_len(pdev, 0));
if (!brd->re_map_membase) {
dev_err(&pdev->dev,
"Card has no PCI Memory resources, failing board.\n");
rc = -ENOMEM;
goto out_kfree_brd;
}
break;
default:
return -ENXIO;
}
rc = request_irq(brd->irq, brd->bd_ops->intr, IRQF_SHARED, "JSM", brd);
if (rc) {
dev_warn(&pdev->dev, "Failed to hook IRQ %d\n", brd->irq);
goto out_iounmap;
}
rc = jsm_tty_init(brd);
if (rc < 0) {
dev_err(&pdev->dev, "Can't init tty devices (%d)\n", rc);
rc = -ENXIO;
goto out_free_irq;
}
rc = jsm_uart_port_init(brd);
if (rc < 0) {
dev_err(&pdev->dev, "Can't init uart port (%d)\n", rc);
rc = -ENXIO;
goto out_free_irq;
}
dev_info(&pdev->dev, "board %d: Digi Classic/Neo (rev %d), irq %d\n",
adapter_count, brd->rev, brd->irq);
pci_set_drvdata(pdev, brd);
pci_save_state(pdev);
return 0;
out_free_irq:
jsm_remove_uart_port(brd);
free_irq(brd->irq, brd);
out_iounmap:
iounmap(brd->re_map_membase);
out_kfree_brd:
kfree(brd);
out_release_regions:
pci_release_regions(pdev);
out_disable_device:
pci_disable_device(pdev);
out:
return rc;
}
static void jsm_remove_one(struct pci_dev *pdev)
{
struct jsm_board *brd = pci_get_drvdata(pdev);
int i = 0;
switch (pdev->device) {
case PCI_DEVICE_ID_CLASSIC_4:
case PCI_DEVICE_ID_CLASSIC_4_422:
case PCI_DEVICE_ID_CLASSIC_8:
case PCI_DEVICE_ID_CLASSIC_8_422:
outb(0x0, brd->iobase + 0x4c);
break;
default:
break;
}
jsm_remove_uart_port(brd);
free_irq(brd->irq, brd);
iounmap(brd->re_map_membase);
for (i = 0; i < brd->maxports; i++) {
if (brd->channels[i]) {
kfree(brd->channels[i]->ch_rqueue);
kfree(brd->channels[i]->ch_equeue);
kfree(brd->channels[i]);
}
}
pci_release_regions(pdev);
pci_disable_device(pdev);
kfree(brd);
}
static pci_ers_result_t jsm_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct jsm_board *brd = pci_get_drvdata(pdev);
jsm_remove_uart_port(brd);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t jsm_io_slot_reset(struct pci_dev *pdev)
{
int rc;
rc = pci_enable_device(pdev);
if (rc)
return PCI_ERS_RESULT_DISCONNECT;
pci_set_master(pdev);
return PCI_ERS_RESULT_RECOVERED;
}
static void jsm_io_resume(struct pci_dev *pdev)
{
struct jsm_board *brd = pci_get_drvdata(pdev);
pci_restore_state(pdev);
pci_save_state(pdev);
jsm_uart_port_init(brd);
}
static int __init jsm_init_module(void)
{
int rc;
rc = uart_register_driver(&jsm_uart_driver);
if (!rc) {
rc = pci_register_driver(&jsm_driver);
if (rc)
uart_unregister_driver(&jsm_uart_driver);
}
return rc;
}
static void __exit jsm_exit_module(void)
{
pci_unregister_driver(&jsm_driver);
uart_unregister_driver(&jsm_uart_driver);
}
