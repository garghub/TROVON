static int pci_stub_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
dev_info(&dev->dev, "claimed by stub\n");
return 0;
}
static int __init pci_stub_init(void)
{
char *p, *id;
int rc;
rc = pci_register_driver(&stub_driver);
if (rc)
return rc;
if (ids[0] == '\0')
return 0;
p = ids;
while ((id = strsep(&p, ","))) {
unsigned int vendor, device, subvendor = PCI_ANY_ID,
subdevice = PCI_ANY_ID, class=0, class_mask=0;
int fields;
if (!strlen(id))
continue;
fields = sscanf(id, "%x:%x:%x:%x:%x:%x",
&vendor, &device, &subvendor, &subdevice,
&class, &class_mask);
if (fields < 2) {
printk(KERN_WARNING
"pci-stub: invalid id string \"%s\"\n", id);
continue;
}
printk(KERN_INFO
"pci-stub: add %04X:%04X sub=%04X:%04X cls=%08X/%08X\n",
vendor, device, subvendor, subdevice, class, class_mask);
rc = pci_add_dynid(&stub_driver, vendor, device,
subvendor, subdevice, class, class_mask, 0);
if (rc)
printk(KERN_WARNING
"pci-stub: failed to add dynamic id (%d)\n", rc);
}
return 0;
}
static void __exit pci_stub_exit(void)
{
pci_unregister_driver(&stub_driver);
}
