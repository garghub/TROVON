static int plat_nand_probe(struct platform_device *pdev)
{
struct platform_nand_data *pdata = pdev->dev.platform_data;
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
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
data = kzalloc(sizeof(struct plat_nand_data), GFP_KERNEL);
if (!data) {
dev_err(&pdev->dev, "failed to allocate device structure.\n");
return -ENOMEM;
}
if (!request_mem_region(res->start, resource_size(res),
dev_name(&pdev->dev))) {
dev_err(&pdev->dev, "request_mem_region failed\n");
err = -EBUSY;
goto out_free;
}
data->io_base = ioremap(res->start, resource_size(res));
if (data->io_base == NULL) {
dev_err(&pdev->dev, "ioremap failed\n");
err = -EIO;
goto out_release_io;
}
data->chip.priv = &data;
data->mtd.priv = &data->chip;
data->mtd.owner = THIS_MODULE;
data->mtd.name = dev_name(&pdev->dev);
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
part_types = pdata->chip.part_probe_types ? : part_probe_types;
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
platform_set_drvdata(pdev, NULL);
iounmap(data->io_base);
out_release_io:
release_mem_region(res->start, resource_size(res));
out_free:
kfree(data);
return err;
}
static int plat_nand_remove(struct platform_device *pdev)
{
struct plat_nand_data *data = platform_get_drvdata(pdev);
struct platform_nand_data *pdata = pdev->dev.platform_data;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nand_release(&data->mtd);
if (pdata->ctrl.remove)
pdata->ctrl.remove(pdev);
iounmap(data->io_base);
release_mem_region(res->start, resource_size(res));
kfree(data);
return 0;
}
