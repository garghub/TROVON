static void ep7312_hwcontrol(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *chip = mtd->priv;
if (ctrl & NAND_CTRL_CHANGE) {
unsigned char bits = 0x80;
bits |= (ctrl & (NAND_CLE | NAND_ALE)) << 3;
bits |= (ctrl & NAND_NCE) ? 0x00 : 0x40;
clps_writeb((clps_readb(ep7312_pxdr) & 0xF0) | bits,
ep7312_pxdr);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, chip->IO_ADDR_W);
}
static int ep7312_device_ready(struct mtd_info *mtd)
{
return 1;
}
static int __init ep7312_init(void)
{
struct nand_chip *this;
const char *part_type = 0;
int mtd_parts_nb = 0;
struct mtd_partition *mtd_parts = 0;
void __iomem *ep7312_fio_base;
ep7312_mtd = kmalloc(sizeof(struct mtd_info) + sizeof(struct nand_chip), GFP_KERNEL);
if (!ep7312_mtd) {
printk("Unable to allocate EDB7312 NAND MTD device structure.\n");
return -ENOMEM;
}
ep7312_fio_base = ioremap(ep7312_fio_pbase, SZ_1K);
if (!ep7312_fio_base) {
printk("ioremap EDB7312 NAND flash failed\n");
kfree(ep7312_mtd);
return -EIO;
}
this = (struct nand_chip *)(&ep7312_mtd[1]);
memset(ep7312_mtd, 0, sizeof(struct mtd_info));
memset(this, 0, sizeof(struct nand_chip));
ep7312_mtd->priv = this;
ep7312_mtd->owner = THIS_MODULE;
clps_writeb(0xf0, ep7312_pxddr);
this->IO_ADDR_R = ep7312_fio_base;
this->IO_ADDR_W = ep7312_fio_base;
this->cmd_ctrl = ep7312_hwcontrol;
this->dev_ready = ep7312_device_ready;
this->chip_delay = 15;
if (nand_scan(ep7312_mtd, 1)) {
iounmap((void *)ep7312_fio_base);
kfree(ep7312_mtd);
return -ENXIO;
}
ep7312_mtd->name = "edb7312-nand";
mtd_parts_nb = parse_mtd_partitions(ep7312_mtd, part_probes, &mtd_parts, 0);
if (mtd_parts_nb > 0)
part_type = "command line";
else
mtd_parts_nb = 0;
if (mtd_parts_nb == 0) {
mtd_parts = partition_info;
mtd_parts_nb = NUM_PARTITIONS;
part_type = "static";
}
printk(KERN_NOTICE "Using %s partition definition\n", part_type);
mtd_device_register(ep7312_mtd, mtd_parts, mtd_parts_nb);
return 0;
}
static void __exit ep7312_cleanup(void)
{
struct nand_chip *this = (struct nand_chip *)&ep7312_mtd[1];
nand_release(ap7312_mtd);
iounmap(this->IO_ADDR_R);
kfree(ep7312_mtd);
}
