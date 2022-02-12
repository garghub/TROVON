static uint8_t oxnas_nand_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct oxnas_nand_ctrl *oxnas = nand_get_controller_data(chip);
return readb(oxnas->io_base);
}
static void oxnas_nand_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct oxnas_nand_ctrl *oxnas = nand_get_controller_data(chip);
ioread8_rep(oxnas->io_base, buf, len);
}
static void oxnas_nand_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct oxnas_nand_ctrl *oxnas = nand_get_controller_data(chip);
iowrite8_rep(oxnas->io_base, buf, len);
}
static void oxnas_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct oxnas_nand_ctrl *oxnas = nand_get_controller_data(chip);
if (ctrl & NAND_CLE)
writeb(cmd, oxnas->io_base + OXNAS_NAND_CMD_CLE);
else if (ctrl & NAND_ALE)
writeb(cmd, oxnas->io_base + OXNAS_NAND_CMD_ALE);
}
static int oxnas_nand_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *nand_np;
struct oxnas_nand_ctrl *oxnas;
struct nand_chip *chip;
struct mtd_info *mtd;
struct resource *res;
int nchips = 0;
int count = 0;
int err = 0;
oxnas = devm_kzalloc(&pdev->dev, sizeof(*oxnas),
GFP_KERNEL);
if (!oxnas)
return -ENOMEM;
nand_hw_control_init(&oxnas->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
oxnas->io_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(oxnas->io_base))
return PTR_ERR(oxnas->io_base);
oxnas->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(oxnas->clk))
oxnas->clk = NULL;
count = of_get_child_count(np);
if (count > 1)
return -EINVAL;
err = clk_prepare_enable(oxnas->clk);
if (err)
return err;
device_reset_optional(&pdev->dev);
for_each_child_of_node(np, nand_np) {
chip = devm_kzalloc(&pdev->dev, sizeof(struct nand_chip),
GFP_KERNEL);
if (!chip) {
err = -ENOMEM;
goto err_clk_unprepare;
}
chip->controller = &oxnas->base;
nand_set_flash_node(chip, nand_np);
nand_set_controller_data(chip, oxnas);
mtd = nand_to_mtd(chip);
mtd->dev.parent = &pdev->dev;
mtd->priv = chip;
chip->cmd_ctrl = oxnas_nand_cmd_ctrl;
chip->read_buf = oxnas_nand_read_buf;
chip->read_byte = oxnas_nand_read_byte;
chip->write_buf = oxnas_nand_write_buf;
chip->chip_delay = 30;
err = nand_scan(mtd, 1);
if (err)
goto err_clk_unprepare;
err = mtd_device_register(mtd, NULL, 0);
if (err) {
nand_release(mtd);
goto err_clk_unprepare;
}
oxnas->chips[nchips] = chip;
++nchips;
}
if (!nchips) {
err = -ENODEV;
goto err_clk_unprepare;
}
platform_set_drvdata(pdev, oxnas);
return 0;
err_clk_unprepare:
clk_disable_unprepare(oxnas->clk);
return err;
}
static int oxnas_nand_remove(struct platform_device *pdev)
{
struct oxnas_nand_ctrl *oxnas = platform_get_drvdata(pdev);
if (oxnas->chips[0])
nand_release(nand_to_mtd(oxnas->chips[0]));
clk_disable_unprepare(oxnas->clk);
return 0;
}
