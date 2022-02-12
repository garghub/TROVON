static int denali_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int ret = -ENODEV;
resource_size_t csr_base, mem_base;
unsigned long csr_len, mem_len;
struct denali_nand_info *denali;
denali = kzalloc(sizeof(*denali), GFP_KERNEL);
if (!denali)
return -ENOMEM;
ret = pci_enable_device(dev);
if (ret) {
pr_err("Spectra: pci_enable_device failed.\n");
goto failed_alloc_memery;
}
if (id->driver_data == INTEL_CE4100) {
denali->platform = INTEL_CE4100;
mem_base = pci_resource_start(dev, 0);
mem_len = pci_resource_len(dev, 1);
csr_base = pci_resource_start(dev, 1);
csr_len = pci_resource_len(dev, 1);
} else {
denali->platform = INTEL_MRST;
csr_base = pci_resource_start(dev, 0);
csr_len = pci_resource_len(dev, 0);
mem_base = pci_resource_start(dev, 1);
mem_len = pci_resource_len(dev, 1);
if (!mem_len) {
mem_base = csr_base + csr_len;
mem_len = csr_len;
}
}
pci_set_master(dev);
denali->dev = &dev->dev;
denali->irq = dev->irq;
ret = pci_request_regions(dev, DENALI_NAND_NAME);
if (ret) {
pr_err("Spectra: Unable to request memory regions\n");
goto failed_enable_dev;
}
denali->flash_reg = ioremap_nocache(csr_base, csr_len);
if (!denali->flash_reg) {
pr_err("Spectra: Unable to remap memory region\n");
ret = -ENOMEM;
goto failed_req_regions;
}
denali->flash_mem = ioremap_nocache(mem_base, mem_len);
if (!denali->flash_mem) {
pr_err("Spectra: ioremap_nocache failed!");
ret = -ENOMEM;
goto failed_remap_reg;
}
ret = denali_init(denali);
if (ret)
goto failed_remap_mem;
pci_set_drvdata(dev, denali);
return 0;
failed_remap_mem:
iounmap(denali->flash_mem);
failed_remap_reg:
iounmap(denali->flash_reg);
failed_req_regions:
pci_release_regions(dev);
failed_enable_dev:
pci_disable_device(dev);
failed_alloc_memery:
kfree(denali);
return ret;
}
static void denali_pci_remove(struct pci_dev *dev)
{
struct denali_nand_info *denali = pci_get_drvdata(dev);
denali_remove(denali);
iounmap(denali->flash_reg);
iounmap(denali->flash_mem);
pci_release_regions(dev);
pci_disable_device(dev);
kfree(denali);
}
static int denali_init_pci(void)
{
return pci_register_driver(&denali_pci_driver);
}
static void denali_exit_pci(void)
{
pci_unregister_driver(&denali_pci_driver);
}
