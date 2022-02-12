static u_char cmx270_read_byte(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
return (readl(this->IO_ADDR_R) >> 16);
}
static void cmx270_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
for (i=0; i<len; i++)
writel((*buf++ << 16), this->IO_ADDR_W);
}
static void cmx270_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
for (i=0; i<len; i++)
*buf++ = readl(this->IO_ADDR_R) >> 16;
}
static inline void nand_cs_on(void)
{
gpio_set_value(GPIO_NAND_CS, 0);
}
static void nand_cs_off(void)
{
dsb();
gpio_set_value(GPIO_NAND_CS, 1);
}
static void cmx270_hwcontrol(struct mtd_info *mtd, int dat,
unsigned int ctrl)
{
struct nand_chip* this = mtd->priv;
unsigned int nandaddr = (unsigned int)this->IO_ADDR_W;
dsb();
if (ctrl & NAND_CTRL_CHANGE) {
if ( ctrl & NAND_ALE )
nandaddr |= (1 << 3);
else
nandaddr &= ~(1 << 3);
if ( ctrl & NAND_CLE )
nandaddr |= (1 << 2);
else
nandaddr &= ~(1 << 2);
if ( ctrl & NAND_NCE )
nand_cs_on();
else
nand_cs_off();
}
dsb();
this->IO_ADDR_W = (void __iomem*)nandaddr;
if (dat != NAND_CMD_NONE)
writel((dat << 16), this->IO_ADDR_W);
dsb();
}
static int cmx270_device_ready(struct mtd_info *mtd)
{
dsb();
return (gpio_get_value(GPIO_NAND_RB));
}
static int __init cmx270_init(void)
{
struct nand_chip *this;
int ret;
if (!(machine_is_armcore() && cpu_is_pxa27x()))
return -ENODEV;
ret = gpio_request(GPIO_NAND_CS, "NAND CS");
if (ret) {
pr_warning("CM-X270: failed to request NAND CS gpio\n");
return ret;
}
gpio_direction_output(GPIO_NAND_CS, 1);
ret = gpio_request(GPIO_NAND_RB, "NAND R/B");
if (ret) {
pr_warning("CM-X270: failed to request NAND R/B gpio\n");
goto err_gpio_request;
}
gpio_direction_input(GPIO_NAND_RB);
cmx270_nand_mtd = kzalloc(sizeof(struct mtd_info) +
sizeof(struct nand_chip),
GFP_KERNEL);
if (!cmx270_nand_mtd) {
pr_debug("Unable to allocate CM-X270 NAND MTD device structure.\n");
ret = -ENOMEM;
goto err_kzalloc;
}
cmx270_nand_io = ioremap(PXA_CS1_PHYS, 12);
if (!cmx270_nand_io) {
pr_debug("Unable to ioremap NAND device\n");
ret = -EINVAL;
goto err_ioremap;
}
this = (struct nand_chip *)(&cmx270_nand_mtd[1]);
cmx270_nand_mtd->owner = THIS_MODULE;
cmx270_nand_mtd->priv = this;
this->IO_ADDR_R = cmx270_nand_io;
this->IO_ADDR_W = cmx270_nand_io;
this->cmd_ctrl = cmx270_hwcontrol;
this->dev_ready = cmx270_device_ready;
this->chip_delay = 20;
this->ecc.mode = NAND_ECC_SOFT;
this->read_byte = cmx270_read_byte;
this->read_buf = cmx270_read_buf;
this->write_buf = cmx270_write_buf;
if (nand_scan (cmx270_nand_mtd, 1)) {
pr_notice("No NAND device\n");
ret = -ENXIO;
goto err_scan;
}
ret = mtd_device_parse_register(cmx270_nand_mtd, NULL, NULL,
partition_info, NUM_PARTITIONS);
if (ret)
goto err_scan;
return 0;
err_scan:
iounmap(cmx270_nand_io);
err_ioremap:
kfree(cmx270_nand_mtd);
err_kzalloc:
gpio_free(GPIO_NAND_RB);
err_gpio_request:
gpio_free(GPIO_NAND_CS);
return ret;
}
static void __exit cmx270_cleanup(void)
{
nand_release(cmx270_nand_mtd);
gpio_free(GPIO_NAND_RB);
gpio_free(GPIO_NAND_CS);
iounmap(cmx270_nand_io);
kfree (cmx270_nand_mtd);
}
