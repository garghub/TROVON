static void nomadik_ecc_control(struct mtd_info *mtd, int mode)
{
}
static void nomadik_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *nand = mtd->priv;
struct nomadik_nand_host *host = nand->priv;
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, host->cmd_va);
else
writeb(cmd, host->addr_va);
}
static int nomadik_nand_probe(struct platform_device *pdev)
{
struct nomadik_nand_platform_data *pdata = pdev->dev.platform_data;
struct nomadik_nand_host *host;
struct mtd_info *mtd;
struct nand_chip *nand;
struct resource *res;
int ret = 0;
host = kzalloc(sizeof(struct nomadik_nand_host), GFP_KERNEL);
if (!host) {
dev_err(&pdev->dev, "Failed to allocate device structure.\n");
return -ENOMEM;
}
if (pdata->init)
ret = pdata->init();
if (ret < 0) {
dev_err(&pdev->dev, "Init function failed\n");
goto err;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_addr");
if (!res) {
ret = -EIO;
goto err_unmap;
}
host->addr_va = ioremap(res->start, resource_size(res));
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_data");
if (!res) {
ret = -EIO;
goto err_unmap;
}
host->data_va = ioremap(res->start, resource_size(res));
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_cmd");
if (!res) {
ret = -EIO;
goto err_unmap;
}
host->cmd_va = ioremap(res->start, resource_size(res));
if (!host->addr_va || !host->data_va || !host->cmd_va) {
ret = -ENOMEM;
goto err_unmap;
}
mtd = &host->mtd;
nand = &host->nand;
mtd->priv = nand;
nand->priv = host;
host->mtd.owner = THIS_MODULE;
nand->IO_ADDR_R = host->data_va;
nand->IO_ADDR_W = host->data_va;
nand->cmd_ctrl = nomadik_cmd_ctrl;
nand->ecc.mode = NAND_ECC_SOFT;
nand->ecc.layout = &nomadik_ecc_layout;
nand->ecc.hwctl = nomadik_ecc_control;
nand->ecc.size = 512;
nand->ecc.bytes = 3;
nand->options = pdata->options;
if (nand_scan(&host->mtd, 1)) {
ret = -ENXIO;
goto err_unmap;
}
mtd_device_register(&host->mtd, pdata->parts, pdata->nparts);
platform_set_drvdata(pdev, host);
return 0;
err_unmap:
if (host->cmd_va)
iounmap(host->cmd_va);
if (host->data_va)
iounmap(host->data_va);
if (host->addr_va)
iounmap(host->addr_va);
err:
kfree(host);
return ret;
}
static int nomadik_nand_remove(struct platform_device *pdev)
{
struct nomadik_nand_host *host = platform_get_drvdata(pdev);
struct nomadik_nand_platform_data *pdata = pdev->dev.platform_data;
if (pdata->exit)
pdata->exit();
if (host) {
iounmap(host->cmd_va);
iounmap(host->data_va);
iounmap(host->addr_va);
kfree(host);
}
return 0;
}
static int nomadik_nand_suspend(struct device *dev)
{
struct nomadik_nand_host *host = dev_get_drvdata(dev);
int ret = 0;
if (host)
ret = host->mtd.suspend(&host->mtd);
return ret;
}
static int nomadik_nand_resume(struct device *dev)
{
struct nomadik_nand_host *host = dev_get_drvdata(dev);
if (host)
host->mtd.resume(&host->mtd);
return 0;
}
static int __init nand_nomadik_init(void)
{
pr_info("Nomadik NAND driver\n");
return platform_driver_register(&nomadik_nand_driver);
}
static void __exit nand_nomadik_exit(void)
{
platform_driver_unregister(&nomadik_nand_driver);
}
