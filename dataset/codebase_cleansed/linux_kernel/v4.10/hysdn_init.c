static int hysdn_pci_init_one(struct pci_dev *akt_pcidev,
const struct pci_device_id *ent)
{
hysdn_card *card;
int rc;
rc = pci_enable_device(akt_pcidev);
if (rc)
return rc;
if (!(card = kzalloc(sizeof(hysdn_card), GFP_KERNEL))) {
printk(KERN_ERR "HYSDN: unable to alloc device mem \n");
rc = -ENOMEM;
goto err_out;
}
card->myid = cardmax;
card->bus = akt_pcidev->bus->number;
card->devfn = akt_pcidev->devfn;
card->subsysid = akt_pcidev->subsystem_device;
card->irq = akt_pcidev->irq;
card->iobase = pci_resource_start(akt_pcidev, PCI_REG_PLX_IO_BASE);
card->plxbase = pci_resource_start(akt_pcidev, PCI_REG_PLX_MEM_BASE);
card->membase = pci_resource_start(akt_pcidev, PCI_REG_MEMORY_BASE);
card->brdtype = BD_NONE;
card->debug_flags = DEF_DEB_FLAGS;
card->faxchans = 0;
card->bchans = 2;
card->brdtype = ent->driver_data;
if (ergo_inithardware(card)) {
printk(KERN_WARNING "HYSDN: card at io 0x%04x already in use\n", card->iobase);
rc = -EBUSY;
goto err_out_card;
}
cardmax++;
card->next = NULL;
if (card_last)
card_last->next = card;
else
card_root = card;
card_last = card;
pci_set_drvdata(akt_pcidev, card);
return 0;
err_out_card:
kfree(card);
err_out:
pci_disable_device(akt_pcidev);
return rc;
}
static void hysdn_pci_remove_one(struct pci_dev *akt_pcidev)
{
hysdn_card *card = pci_get_drvdata(akt_pcidev);
pci_set_drvdata(akt_pcidev, NULL);
if (card->stopcard)
card->stopcard(card);
#ifdef CONFIG_HYSDN_CAPI
hycapi_capi_release(card);
#endif
if (card->releasehardware)
card->releasehardware(card);
if (card == card_root) {
card_root = card_root->next;
if (!card_root)
card_last = NULL;
} else {
hysdn_card *tmp = card_root;
while (tmp) {
if (tmp->next == card)
tmp->next = card->next;
card_last = tmp;
tmp = tmp->next;
}
}
kfree(card);
pci_disable_device(akt_pcidev);
}
static int __init
hysdn_init(void)
{
int rc;
printk(KERN_NOTICE "HYSDN: module loaded\n");
rc = pci_register_driver(&hysdn_pci_driver);
if (rc)
return rc;
printk(KERN_INFO "HYSDN: %d card(s) found.\n", cardmax);
if (!hysdn_procconf_init())
hysdn_have_procfs = 1;
#ifdef CONFIG_HYSDN_CAPI
if (cardmax > 0) {
if (hycapi_init()) {
printk(KERN_ERR "HYCAPI: init failed\n");
if (hysdn_have_procfs)
hysdn_procconf_release();
pci_unregister_driver(&hysdn_pci_driver);
return -ESPIPE;
}
}
#endif
return 0;
}
static void __exit
hysdn_exit(void)
{
if (hysdn_have_procfs)
hysdn_procconf_release();
pci_unregister_driver(&hysdn_pci_driver);
#ifdef CONFIG_HYSDN_CAPI
hycapi_cleanup();
#endif
printk(KERN_NOTICE "HYSDN: module unloaded\n");
}
