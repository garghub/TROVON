static void spia_hwcontrol(struct mtd_info *mtd, int cmd)
{
struct nand_chip *chip = mtd->priv;
if (ctrl & NAND_CTRL_CHANGE) {
void __iomem *addr = spia_io_base + spia_pedr;
unsigned char bits;
bits = (ctrl & NAND_CNE) << 2;
bits |= (ctrl & NAND_CLE | NAND_ALE) >> 1;
writeb((readb(addr) & ~0x7) | bits, addr);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, chip->IO_ADDR_W);
}
static int __init spia_init(void)
{
struct nand_chip *this;
spia_mtd = kmalloc(sizeof(struct mtd_info) + sizeof(struct nand_chip), GFP_KERNEL);
if (!spia_mtd) {
printk("Unable to allocate SPIA NAND MTD device structure.\n");
return -ENOMEM;
}
this = (struct nand_chip *)(&spia_mtd[1]);
memset(spia_mtd, 0, sizeof(struct mtd_info));
memset(this, 0, sizeof(struct nand_chip));
spia_mtd->priv = this;
spia_mtd->owner = THIS_MODULE;
(*(volatile unsigned char *)(spia_io_base + spia_peddr)) = 0x07;
this->IO_ADDR_R = (void __iomem *)spia_fio_base;
this->IO_ADDR_W = (void __iomem *)spia_fio_base;
this->cmd_ctrl = spia_hwcontrol;
this->chip_delay = 15;
if (nand_scan(spia_mtd, 1)) {
kfree(spia_mtd);
return -ENXIO;
}
mtd_device_register(spia_mtd, partition_info, NUM_PARTITIONS);
return 0;
}
static void __exit spia_cleanup(void)
{
nand_release(spia_mtd);
kfree(spia_mtd);
}
