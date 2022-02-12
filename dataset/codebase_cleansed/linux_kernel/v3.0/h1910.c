static void h1910_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *chip = mtd->priv;
if (cmd != NAND_CMD_NONE)
writeb(cmd, chip->IO_ADDR_W | ((ctrl & 0x6) << 1));
}
static int __init h1910_init(void)
{
struct nand_chip *this;
const char *part_type = 0;
int mtd_parts_nb = 0;
struct mtd_partition *mtd_parts = 0;
void __iomem *nandaddr;
if (!machine_is_h1900())
return -ENODEV;
nandaddr = ioremap(0x08000000, 0x1000);
if (!nandaddr) {
printk("Failed to ioremap nand flash.\n");
return -ENOMEM;
}
h1910_nand_mtd = kmalloc(sizeof(struct mtd_info) + sizeof(struct nand_chip), GFP_KERNEL);
if (!h1910_nand_mtd) {
printk("Unable to allocate h1910 NAND MTD device structure.\n");
iounmap((void *)nandaddr);
return -ENOMEM;
}
this = (struct nand_chip *)(&h1910_nand_mtd[1]);
memset(h1910_nand_mtd, 0, sizeof(struct mtd_info));
memset(this, 0, sizeof(struct nand_chip));
h1910_nand_mtd->priv = this;
h1910_nand_mtd->owner = THIS_MODULE;
GPSR(37) = GPIO_bit(37);
this->IO_ADDR_R = nandaddr;
this->IO_ADDR_W = nandaddr;
this->cmd_ctrl = h1910_hwcontrol;
this->dev_ready = NULL;
this->chip_delay = 50;
this->ecc.mode = NAND_ECC_SOFT;
this->options = NAND_NO_AUTOINCR;
if (nand_scan(h1910_nand_mtd, 1)) {
printk(KERN_NOTICE "No NAND device - returning -ENXIO\n");
kfree(h1910_nand_mtd);
iounmap((void *)nandaddr);
return -ENXIO;
}
#ifdef CONFIG_MTD_CMDLINE_PARTS
mtd_parts_nb = parse_cmdline_partitions(h1910_nand_mtd, &mtd_parts, "h1910-nand");
if (mtd_parts_nb > 0)
part_type = "command line";
else
mtd_parts_nb = 0;
#endif
if (mtd_parts_nb == 0) {
mtd_parts = partition_info;
mtd_parts_nb = NUM_PARTITIONS;
part_type = "static";
}
printk(KERN_NOTICE "Using %s partition definition\n", part_type);
mtd_device_register(h1910_nand_mtd, mtd_parts, mtd_parts_nb);
return 0;
}
static void __exit h1910_cleanup(void)
{
struct nand_chip *this = (struct nand_chip *)&h1910_nand_mtd[1];
nand_release(h1910_nand_mtd);
iounmap((void *)this->IO_ADDR_W);
kfree(h1910_nand_mtd);
}
