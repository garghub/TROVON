static int __devinit emu_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct emu *emu;
struct gameport *port;
int error;
emu = kzalloc(sizeof(struct emu), GFP_KERNEL);
port = gameport_allocate_port();
if (!emu || !port) {
printk(KERN_ERR "emu10k1-gp: Memory allocation failed\n");
error = -ENOMEM;
goto err_out_free;
}
error = pci_enable_device(pdev);
if (error)
goto err_out_free;
emu->io = pci_resource_start(pdev, 0);
emu->size = pci_resource_len(pdev, 0);
emu->dev = pdev;
emu->gameport = port;
gameport_set_name(port, "EMU10K1");
gameport_set_phys(port, "pci%s/gameport0", pci_name(pdev));
port->dev.parent = &pdev->dev;
port->io = emu->io;
if (!request_region(emu->io, emu->size, "emu10k1-gp")) {
printk(KERN_ERR "emu10k1-gp: unable to grab region 0x%x-0x%x\n",
emu->io, emu->io + emu->size - 1);
error = -EBUSY;
goto err_out_disable_dev;
}
pci_set_drvdata(pdev, emu);
gameport_register_port(port);
return 0;
err_out_disable_dev:
pci_disable_device(pdev);
err_out_free:
gameport_free_port(port);
kfree(emu);
return error;
}
static void __devexit emu_remove(struct pci_dev *pdev)
{
struct emu *emu = pci_get_drvdata(pdev);
gameport_unregister_port(emu->gameport);
release_region(emu->io, emu->size);
kfree(emu);
pci_disable_device(pdev);
}
static int __init emu_init(void)
{
return pci_register_driver(&emu_driver);
}
static void __exit emu_exit(void)
{
pci_unregister_driver(&emu_driver);
}
