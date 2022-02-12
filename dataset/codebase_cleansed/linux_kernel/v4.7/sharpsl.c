static inline struct sharpsl_nand *mtd_to_sharpsl(struct mtd_info *mtd)
{
return container_of(mtd_to_nand(mtd), struct sharpsl_nand, chip);
}
static void sharpsl_nand_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct sharpsl_nand *sharpsl = mtd_to_sharpsl(mtd);
struct nand_chip *chip = mtd_to_nand(mtd);
if (ctrl & NAND_CTRL_CHANGE) {
unsigned char bits = ctrl & 0x07;
bits |= (ctrl & 0x01) << 4;
bits ^= 0x11;
writeb((readb(sharpsl->io + FLASHCTL) & ~0x17) | bits, sharpsl->io + FLASHCTL);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, chip->IO_ADDR_W);
}
static int sharpsl_nand_dev_ready(struct mtd_info *mtd)
{
struct sharpsl_nand *sharpsl = mtd_to_sharpsl(mtd);
return !((readb(sharpsl->io + FLASHCTL) & FLRYBY) == 0);
}
static void sharpsl_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct sharpsl_nand *sharpsl = mtd_to_sharpsl(mtd);
writeb(0, sharpsl->io + ECCCLRR);
}
static int sharpsl_nand_calculate_ecc(struct mtd_info *mtd, const u_char * dat, u_char * ecc_code)
{
struct sharpsl_nand *sharpsl = mtd_to_sharpsl(mtd);
ecc_code[0] = ~readb(sharpsl->io + ECCLPUB);
ecc_code[1] = ~readb(sharpsl->io + ECCLPLB);
ecc_code[2] = (~readb(sharpsl->io + ECCCP) << 2) | 0x03;
return readb(sharpsl->io + ECCCNTR) != 0;
}
static int sharpsl_nand_probe(struct platform_device *pdev)
{
struct nand_chip *this;
struct mtd_info *mtd;
struct resource *r;
int err = 0;
struct sharpsl_nand *sharpsl;
struct sharpsl_nand_platform_data *data = dev_get_platdata(&pdev->dev);
if (!data) {
dev_err(&pdev->dev, "no platform data!\n");
return -EINVAL;
}
sharpsl = kzalloc(sizeof(struct sharpsl_nand), GFP_KERNEL);
if (!sharpsl)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no io memory resource defined!\n");
err = -ENODEV;
goto err_get_res;
}
sharpsl->io = ioremap(r->start, resource_size(r));
if (!sharpsl->io) {
dev_err(&pdev->dev, "ioremap to access Sharp SL NAND chip failed\n");
err = -EIO;
goto err_ioremap;
}
this = (struct nand_chip *)(&sharpsl->chip);
mtd = nand_to_mtd(this);
mtd->dev.parent = &pdev->dev;
mtd_set_ooblayout(mtd, data->ecc_layout);
platform_set_drvdata(pdev, sharpsl);
writeb(readb(sharpsl->io + FLASHCTL) | FLWP, sharpsl->io + FLASHCTL);
this->IO_ADDR_R = sharpsl->io + FLASHIO;
this->IO_ADDR_W = sharpsl->io + FLASHIO;
this->cmd_ctrl = sharpsl_nand_hwcontrol;
this->dev_ready = sharpsl_nand_dev_ready;
this->chip_delay = 15;
this->ecc.mode = NAND_ECC_HW;
this->ecc.size = 256;
this->ecc.bytes = 3;
this->ecc.strength = 1;
this->badblock_pattern = data->badblock_pattern;
this->ecc.hwctl = sharpsl_nand_enable_hwecc;
this->ecc.calculate = sharpsl_nand_calculate_ecc;
this->ecc.correct = nand_correct_data;
err = nand_scan(mtd, 1);
if (err)
goto err_scan;
mtd->name = "sharpsl-nand";
err = mtd_device_parse_register(mtd, NULL, NULL,
data->partitions, data->nr_partitions);
if (err)
goto err_add;
return 0;
err_add:
nand_release(mtd);
err_scan:
iounmap(sharpsl->io);
err_ioremap:
err_get_res:
kfree(sharpsl);
return err;
}
static int sharpsl_nand_remove(struct platform_device *pdev)
{
struct sharpsl_nand *sharpsl = platform_get_drvdata(pdev);
nand_release(nand_to_mtd(&sharpsl->chip));
iounmap(sharpsl->io);
kfree(sharpsl);
return 0;
}
