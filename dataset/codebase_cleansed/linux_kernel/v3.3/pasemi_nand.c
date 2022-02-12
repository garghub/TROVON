static void pasemi_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *chip = mtd->priv;
while (len > 0x800) {
memcpy_fromio(buf, chip->IO_ADDR_R, 0x800);
buf += 0x800;
len -= 0x800;
}
memcpy_fromio(buf, chip->IO_ADDR_R, len);
}
static void pasemi_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *chip = mtd->priv;
while (len > 0x800) {
memcpy_toio(chip->IO_ADDR_R, buf, 0x800);
buf += 0x800;
len -= 0x800;
}
memcpy_toio(chip->IO_ADDR_R, buf, len);
}
static void pasemi_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *chip = mtd->priv;
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
out_8(chip->IO_ADDR_W + (1 << CLE_PIN_CTL), cmd);
else
out_8(chip->IO_ADDR_W + (1 << ALE_PIN_CTL), cmd);
eieio();
inl(lpcctl);
}
int pasemi_device_ready(struct mtd_info *mtd)
{
return !!(inl(lpcctl) & LBICTRL_LPCCTL_NR);
}
static int __devinit pasemi_nand_probe(struct platform_device *ofdev)
{
struct pci_dev *pdev;
struct device_node *np = ofdev->dev.of_node;
struct resource res;
struct nand_chip *chip;
int err = 0;
err = of_address_to_resource(np, 0, &res);
if (err)
return -EINVAL;
if (pasemi_nand_mtd)
return -ENODEV;
pr_debug("pasemi_nand at %pR\n", &res);
pasemi_nand_mtd = kzalloc(sizeof(struct mtd_info) +
sizeof(struct nand_chip), GFP_KERNEL);
if (!pasemi_nand_mtd) {
printk(KERN_WARNING
"Unable to allocate PASEMI NAND MTD device structure\n");
err = -ENOMEM;
goto out;
}
chip = (struct nand_chip *)&pasemi_nand_mtd[1];
pasemi_nand_mtd->priv = chip;
pasemi_nand_mtd->owner = THIS_MODULE;
chip->IO_ADDR_R = of_iomap(np, 0);
chip->IO_ADDR_W = chip->IO_ADDR_R;
if (!chip->IO_ADDR_R) {
err = -EIO;
goto out_mtd;
}
pdev = pci_get_device(PCI_VENDOR_ID_PASEMI, 0xa008, NULL);
if (!pdev) {
err = -ENODEV;
goto out_ior;
}
lpcctl = pci_resource_start(pdev, 0);
pci_dev_put(pdev);
if (!request_region(lpcctl, 4, driver_name)) {
err = -EBUSY;
goto out_ior;
}
chip->cmd_ctrl = pasemi_hwcontrol;
chip->dev_ready = pasemi_device_ready;
chip->read_buf = pasemi_read_buf;
chip->write_buf = pasemi_write_buf;
chip->chip_delay = 0;
chip->ecc.mode = NAND_ECC_SOFT;
chip->options = NAND_NO_AUTOINCR;
chip->bbt_options = NAND_BBT_USE_FLASH;
if (nand_scan(pasemi_nand_mtd, 1)) {
err = -ENXIO;
goto out_lpc;
}
if (mtd_device_register(pasemi_nand_mtd, NULL, 0)) {
printk(KERN_ERR "pasemi_nand: Unable to register MTD device\n");
err = -ENODEV;
goto out_lpc;
}
printk(KERN_INFO "PA Semi NAND flash at %08llx, control at I/O %x\n",
res.start, lpcctl);
return 0;
out_lpc:
release_region(lpcctl, 4);
out_ior:
iounmap(chip->IO_ADDR_R);
out_mtd:
kfree(pasemi_nand_mtd);
out:
return err;
}
static int __devexit pasemi_nand_remove(struct platform_device *ofdev)
{
struct nand_chip *chip;
if (!pasemi_nand_mtd)
return 0;
chip = pasemi_nand_mtd->priv;
nand_release(pasemi_nand_mtd);
release_region(lpcctl, 4);
iounmap(chip->IO_ADDR_R);
kfree(pasemi_nand_mtd);
pasemi_nand_mtd = NULL;
return 0;
}
