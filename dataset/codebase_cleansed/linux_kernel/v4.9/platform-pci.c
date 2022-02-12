static unsigned long alloc_xen_mmio(unsigned long len)
{
unsigned long addr;
addr = platform_mmio + platform_mmio_alloc;
platform_mmio_alloc += len;
BUG_ON(platform_mmio_alloc > platform_mmiolen);
return addr;
}
static int platform_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int i, ret;
long ioaddr;
long mmio_addr, mmio_len;
unsigned int max_nr_gframes;
unsigned long grant_frames;
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
max_nr_gframes = gnttab_max_grant_frames();
grant_frames = alloc_xen_mmio(PAGE_SIZE * max_nr_gframes);
ret = gnttab_setup_auto_xlat_frames(grant_frames);
if (ret)
goto out;
ret = gnttab_init();
if (ret)
goto grant_out;
xenbus_probe(NULL);
return 0;
grant_out:
gnttab_free_auto_xlat_frames();
out:
pci_release_region(pdev, 0);
mem_out:
pci_release_region(pdev, 1);
pci_out:
pci_disable_device(pdev);
return ret;
}
static int __init platform_pci_init(void)
{
return pci_register_driver(&platform_driver);
}
