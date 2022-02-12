static int aac_nark_ioremap(struct aac_dev * dev, u32 size)
{
if (!size) {
iounmap(dev->regs.rx);
dev->regs.rx = NULL;
iounmap(dev->base);
dev->base = NULL;
return 0;
}
dev->scsi_host_ptr->base = pci_resource_start(dev->pdev, 2);
dev->regs.rx = ioremap((u64)pci_resource_start(dev->pdev, 0) |
((u64)pci_resource_start(dev->pdev, 1) << 32),
sizeof(struct rx_registers) - sizeof(struct rx_inbound));
dev->base = NULL;
if (dev->regs.rx == NULL)
return -1;
dev->base = ioremap(dev->scsi_host_ptr->base, size);
if (dev->base == NULL) {
iounmap(dev->regs.rx);
dev->regs.rx = NULL;
return -1;
}
dev->IndexRegs = &((struct rx_registers __iomem *)dev->base)->IndexRegs;
return 0;
}
int aac_nark_init(struct aac_dev * dev)
{
dev->a_ops.adapter_ioremap = aac_nark_ioremap;
dev->a_ops.adapter_comm = aac_rx_select_comm;
return _aac_rx_init(dev);
}
