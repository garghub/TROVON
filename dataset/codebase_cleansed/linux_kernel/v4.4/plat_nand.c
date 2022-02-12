static int plat_nand_probe(struct platform_device *pdev)
{
struct platform_nand_data *pdata = dev_get_platdata(&pdev->dev);
struct mtd_part_parser_data ppdata;
struct plat_nand_data *data;
struct resource *res;
const char **part_types;
int err = 0;
if (!pdata) {
dev_err(&pdev->dev, "platform_nand_data is missing\n");
return -EINVAL;
}
if (pdata->chip.nr_chips < 1) {
dev_err(&pdev->dev, "invalid number of chips specified\n");
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct plat_nand_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->io_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->io_base))
return PTR_ERR(data->io_base);
data->chip.priv = &data;
data->mtd.priv = &data->chip;
data->mtd.dev.parent = &pdev->dev;
data->chip.IO_ADDR_R = data->io_base;
data->chip.IO_ADDR_W = data->io_base;
data->chip.cmd_ctrl = pdata->ctrl.cmd_ctrl;
data->chip.dev_ready = pdata->ctrl.dev_ready;
data->chip.select_chip = pdata->ctrl.select_chip;
data->chip.write_buf = pdata->ctrl.write_buf;
data->chip.read_buf = pdata->ctrl.read_buf;
data->chip.read_byte = pdata->ctrl.read_byte;
data->chip.chip_delay = pdata->chip.chip_delay;
data->chip.options |= pdata->chip.options;
data->chip.bbt_options |= pdata->chip.bbt_options;
data->chip.ecc.hwctl = pdata->ctrl.hwcontrol;
data->chip.ecc.layout = pdata->chip.ecclayout;
data->chip.ecc.mode = NAND_ECC_SOFT;
platform_set_drvdata(pdev, data);
if (pdata->ctrl.probe) {
err = pdata->ctrl.probe(pdev);
if (err)
goto out;
}
if (nand_scan(&data->mtd, pdata->chip.nr_chips)) {
err = -ENXIO;
goto out;
}
part_types = pdata->chip.part_probe_types;
ppdata.of_node = pdev->dev.of_node;
err = mtd_device_parse_register(&data->mtd, part_types, &ppdata,
pdata->chip.partitions,
pdata->chip.nr_partitions);
if (!err)
return err;
nand_release(&data->mtd);
out:
if (pdata->ctrl.remove)
pdata->ctrl.remove(pdev);
return err;
}
static int plat_nand_remove(struct platform_device *pdev)
{
struct plat_nand_data *data = platform_get_drvdata(pdev);
struct platform_nand_data *pdata = dev_get_platdata(&pdev->dev);
nand_release(&data->mtd);
if (pdata->ctrl.remove)
pdata->ctrl.remove(pdev);
return 0;
}
