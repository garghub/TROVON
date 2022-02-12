static void edac_pci_read_dword(struct pci_dev *dev, int reg, u32 *val32)
{
int ret;
ret = pci_read_config_dword(dev, reg, val32);
if (ret != 0)
printk(KERN_ERR AMD8131_EDAC_MOD_STR
" PCI Access Read Error at 0x%x\n", reg);
}
static void edac_pci_write_dword(struct pci_dev *dev, int reg, u32 val32)
{
int ret;
ret = pci_write_config_dword(dev, reg, val32);
if (ret != 0)
printk(KERN_ERR AMD8131_EDAC_MOD_STR
" PCI Access Write Error at 0x%x\n", reg);
}
static void amd8131_pcix_init(struct amd8131_dev_info *dev_info)
{
u32 val32;
struct pci_dev *dev = dev_info->dev;
edac_pci_read_dword(dev, REG_MEM_LIM, &val32);
if (val32 & MEM_LIMIT_MASK)
edac_pci_write_dword(dev, REG_MEM_LIM, val32);
edac_pci_read_dword(dev, REG_INT_CTLR, &val32);
if (val32 & INT_CTLR_DTS)
edac_pci_write_dword(dev, REG_INT_CTLR, val32);
edac_pci_read_dword(dev, REG_LNK_CTRL_A, &val32);
if (val32 & LNK_CTRL_CRCERR_A)
edac_pci_write_dword(dev, REG_LNK_CTRL_A, val32);
edac_pci_read_dword(dev, REG_LNK_CTRL_B, &val32);
if (val32 & LNK_CTRL_CRCERR_B)
edac_pci_write_dword(dev, REG_LNK_CTRL_B, val32);
edac_pci_read_dword(dev, REG_INT_CTLR, &val32);
val32 |= INT_CTLR_PERR | INT_CTLR_SERR | INT_CTLR_DTSE;
edac_pci_write_dword(dev, REG_INT_CTLR, val32);
edac_pci_read_dword(dev, REG_STS_CMD, &val32);
val32 |= STS_CMD_SERREN;
edac_pci_write_dword(dev, REG_STS_CMD, val32);
edac_pci_read_dword(dev, REG_LNK_CTRL_A, &val32);
val32 |= LNK_CTRL_CRCFEN;
edac_pci_write_dword(dev, REG_LNK_CTRL_A, val32);
edac_pci_read_dword(dev, REG_LNK_CTRL_B, &val32);
val32 |= LNK_CTRL_CRCFEN;
edac_pci_write_dword(dev, REG_LNK_CTRL_B, val32);
}
static void amd8131_pcix_exit(struct amd8131_dev_info *dev_info)
{
u32 val32;
struct pci_dev *dev = dev_info->dev;
edac_pci_read_dword(dev, REG_INT_CTLR, &val32);
val32 &= ~(INT_CTLR_PERR | INT_CTLR_SERR | INT_CTLR_DTSE);
edac_pci_write_dword(dev, REG_INT_CTLR, val32);
edac_pci_read_dword(dev, REG_STS_CMD, &val32);
val32 &= ~STS_CMD_SERREN;
edac_pci_write_dword(dev, REG_STS_CMD, val32);
edac_pci_read_dword(dev, REG_LNK_CTRL_A, &val32);
val32 &= ~LNK_CTRL_CRCFEN;
edac_pci_write_dword(dev, REG_LNK_CTRL_A, val32);
edac_pci_read_dword(dev, REG_LNK_CTRL_B, &val32);
val32 &= ~LNK_CTRL_CRCFEN;
edac_pci_write_dword(dev, REG_LNK_CTRL_B, val32);
}
static void amd8131_pcix_check(struct edac_pci_ctl_info *edac_dev)
{
struct amd8131_dev_info *dev_info = edac_dev->pvt_info;
struct pci_dev *dev = dev_info->dev;
u32 val32;
edac_pci_read_dword(dev, REG_MEM_LIM, &val32);
if (val32 & MEM_LIMIT_MASK) {
printk(KERN_INFO "Error(s) in mem limit register "
"on %s bridge\n", dev_info->ctl_name);
printk(KERN_INFO "DPE: %d, RSE: %d, RMA: %d\n"
"RTA: %d, STA: %d, MDPE: %d\n",
val32 & MEM_LIMIT_DPE,
val32 & MEM_LIMIT_RSE,
val32 & MEM_LIMIT_RMA,
val32 & MEM_LIMIT_RTA,
val32 & MEM_LIMIT_STA,
val32 & MEM_LIMIT_MDPE);
val32 |= MEM_LIMIT_MASK;
edac_pci_write_dword(dev, REG_MEM_LIM, val32);
edac_pci_handle_npe(edac_dev, edac_dev->ctl_name);
}
edac_pci_read_dword(dev, REG_INT_CTLR, &val32);
if (val32 & INT_CTLR_DTS) {
printk(KERN_INFO "Error(s) in interrupt and control register "
"on %s bridge\n", dev_info->ctl_name);
printk(KERN_INFO "DTS: %d\n", val32 & INT_CTLR_DTS);
val32 |= INT_CTLR_DTS;
edac_pci_write_dword(dev, REG_INT_CTLR, val32);
edac_pci_handle_npe(edac_dev, edac_dev->ctl_name);
}
edac_pci_read_dword(dev, REG_LNK_CTRL_A, &val32);
if (val32 & LNK_CTRL_CRCERR_A) {
printk(KERN_INFO "Error(s) in link conf and control register "
"on %s bridge\n", dev_info->ctl_name);
printk(KERN_INFO "CRCERR: %d\n", val32 & LNK_CTRL_CRCERR_A);
val32 |= LNK_CTRL_CRCERR_A;
edac_pci_write_dword(dev, REG_LNK_CTRL_A, val32);
edac_pci_handle_npe(edac_dev, edac_dev->ctl_name);
}
edac_pci_read_dword(dev, REG_LNK_CTRL_B, &val32);
if (val32 & LNK_CTRL_CRCERR_B) {
printk(KERN_INFO "Error(s) in link conf and control register "
"on %s bridge\n", dev_info->ctl_name);
printk(KERN_INFO "CRCERR: %d\n", val32 & LNK_CTRL_CRCERR_B);
val32 |= LNK_CTRL_CRCERR_B;
edac_pci_write_dword(dev, REG_LNK_CTRL_B, val32);
edac_pci_handle_npe(edac_dev, edac_dev->ctl_name);
}
}
static int amd8131_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct amd8131_dev_info *dev_info;
for (dev_info = amd8131_chipset.devices; dev_info->inst != NO_BRIDGE;
dev_info++)
if (dev_info->devfn == dev->devfn)
break;
if (dev_info->inst == NO_BRIDGE)
return -ENODEV;
dev_info->dev = pci_dev_get(dev);
if (pci_enable_device(dev_info->dev)) {
pci_dev_put(dev_info->dev);
printk(KERN_ERR "failed to enable:"
"vendor %x, device %x, devfn %x, name %s\n",
PCI_VENDOR_ID_AMD, amd8131_chipset.err_dev,
dev_info->devfn, dev_info->ctl_name);
return -ENODEV;
}
dev_info->edac_idx = edac_pci_alloc_index();
dev_info->edac_dev = edac_pci_alloc_ctl_info(0, dev_info->ctl_name);
if (!dev_info->edac_dev)
return -ENOMEM;
dev_info->edac_dev->pvt_info = dev_info;
dev_info->edac_dev->dev = &dev_info->dev->dev;
dev_info->edac_dev->mod_name = AMD8131_EDAC_MOD_STR;
dev_info->edac_dev->ctl_name = dev_info->ctl_name;
dev_info->edac_dev->dev_name = dev_name(&dev_info->dev->dev);
if (edac_op_state == EDAC_OPSTATE_POLL)
dev_info->edac_dev->edac_check = amd8131_chipset.check;
if (amd8131_chipset.init)
amd8131_chipset.init(dev_info);
if (edac_pci_add_device(dev_info->edac_dev, dev_info->edac_idx) > 0) {
printk(KERN_ERR "failed edac_pci_add_device() for %s\n",
dev_info->ctl_name);
edac_pci_free_ctl_info(dev_info->edac_dev);
return -ENODEV;
}
printk(KERN_INFO "added one device on AMD8131 "
"vendor %x, device %x, devfn %x, name %s\n",
PCI_VENDOR_ID_AMD, amd8131_chipset.err_dev,
dev_info->devfn, dev_info->ctl_name);
return 0;
}
static void amd8131_remove(struct pci_dev *dev)
{
struct amd8131_dev_info *dev_info;
for (dev_info = amd8131_chipset.devices; dev_info->inst != NO_BRIDGE;
dev_info++)
if (dev_info->devfn == dev->devfn)
break;
if (dev_info->inst == NO_BRIDGE)
return;
if (dev_info->edac_dev) {
edac_pci_del_device(dev_info->edac_dev->dev);
edac_pci_free_ctl_info(dev_info->edac_dev);
}
if (amd8131_chipset.exit)
amd8131_chipset.exit(dev_info);
pci_dev_put(dev_info->dev);
}
static int __init amd8131_edac_init(void)
{
printk(KERN_INFO "AMD8131 EDAC driver " AMD8131_EDAC_REVISION "\n");
printk(KERN_INFO "\t(c) 2008 Wind River Systems, Inc.\n");
edac_op_state = EDAC_OPSTATE_POLL;
return pci_register_driver(&amd8131_edac_driver);
}
static void __exit amd8131_edac_exit(void)
{
pci_unregister_driver(&amd8131_edac_driver);
}
