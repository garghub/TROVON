static inline u32 iosf_mbi_form_mcr(u8 op, u8 port, u8 offset)
{
return (op << 24) | (port << 16) | (offset << 8) | MBI_ENABLE;
}
static int iosf_mbi_pci_read_mdr(u32 mcrx, u32 mcr, u32 *mdr)
{
int result;
if (!mbi_pdev)
return -ENODEV;
if (mcrx) {
result = pci_write_config_dword(mbi_pdev, MBI_MCRX_OFFSET,
mcrx);
if (result < 0)
goto fail_read;
}
result = pci_write_config_dword(mbi_pdev, MBI_MCR_OFFSET, mcr);
if (result < 0)
goto fail_read;
result = pci_read_config_dword(mbi_pdev, MBI_MDR_OFFSET, mdr);
if (result < 0)
goto fail_read;
return 0;
fail_read:
dev_err(&mbi_pdev->dev, "PCI config access failed with %d\n", result);
return result;
}
static int iosf_mbi_pci_write_mdr(u32 mcrx, u32 mcr, u32 mdr)
{
int result;
if (!mbi_pdev)
return -ENODEV;
result = pci_write_config_dword(mbi_pdev, MBI_MDR_OFFSET, mdr);
if (result < 0)
goto fail_write;
if (mcrx) {
result = pci_write_config_dword(mbi_pdev, MBI_MCRX_OFFSET,
mcrx);
if (result < 0)
goto fail_write;
}
result = pci_write_config_dword(mbi_pdev, MBI_MCR_OFFSET, mcr);
if (result < 0)
goto fail_write;
return 0;
fail_write:
dev_err(&mbi_pdev->dev, "PCI config access failed with %d\n", result);
return result;
}
int iosf_mbi_read(u8 port, u8 opcode, u32 offset, u32 *mdr)
{
u32 mcr, mcrx;
unsigned long flags;
int ret;
if (port == BT_MBI_UNIT_GFX) {
WARN_ON(1);
return -EPERM;
}
mcr = iosf_mbi_form_mcr(opcode, port, offset & MBI_MASK_LO);
mcrx = offset & MBI_MASK_HI;
spin_lock_irqsave(&iosf_mbi_lock, flags);
ret = iosf_mbi_pci_read_mdr(mcrx, mcr, mdr);
spin_unlock_irqrestore(&iosf_mbi_lock, flags);
return ret;
}
int iosf_mbi_write(u8 port, u8 opcode, u32 offset, u32 mdr)
{
u32 mcr, mcrx;
unsigned long flags;
int ret;
if (port == BT_MBI_UNIT_GFX) {
WARN_ON(1);
return -EPERM;
}
mcr = iosf_mbi_form_mcr(opcode, port, offset & MBI_MASK_LO);
mcrx = offset & MBI_MASK_HI;
spin_lock_irqsave(&iosf_mbi_lock, flags);
ret = iosf_mbi_pci_write_mdr(mcrx, mcr, mdr);
spin_unlock_irqrestore(&iosf_mbi_lock, flags);
return ret;
}
int iosf_mbi_modify(u8 port, u8 opcode, u32 offset, u32 mdr, u32 mask)
{
u32 mcr, mcrx;
u32 value;
unsigned long flags;
int ret;
if (port == BT_MBI_UNIT_GFX) {
WARN_ON(1);
return -EPERM;
}
mcr = iosf_mbi_form_mcr(opcode, port, offset & MBI_MASK_LO);
mcrx = offset & MBI_MASK_HI;
spin_lock_irqsave(&iosf_mbi_lock, flags);
ret = iosf_mbi_pci_read_mdr(mcrx, mcr & MBI_RD_MASK, &value);
if (ret < 0) {
spin_unlock_irqrestore(&iosf_mbi_lock, flags);
return ret;
}
value &= ~mask;
mdr &= mask;
value |= mdr;
ret = iosf_mbi_pci_write_mdr(mcrx, mcr | MBI_WR_MASK, value);
spin_unlock_irqrestore(&iosf_mbi_lock, flags);
return ret;
}
static int iosf_mbi_probe(struct pci_dev *pdev,
const struct pci_device_id *unused)
{
int ret;
ret = pci_enable_device(pdev);
if (ret < 0) {
dev_err(&pdev->dev, "error: could not enable device\n");
return ret;
}
mbi_pdev = pci_dev_get(pdev);
return 0;
}
static int __init iosf_mbi_init(void)
{
return pci_register_driver(&iosf_mbi_pci_driver);
}
static void __exit iosf_mbi_exit(void)
{
pci_unregister_driver(&iosf_mbi_pci_driver);
if (mbi_pdev) {
pci_dev_put(mbi_pdev);
mbi_pdev = NULL;
}
}
