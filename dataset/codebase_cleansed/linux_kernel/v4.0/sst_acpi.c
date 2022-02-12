static int sst_platform_get_resources(struct intel_sst_drv *ctx)
{
struct resource *rsrc;
struct platform_device *pdev = to_platform_device(ctx->dev);
rsrc = platform_get_resource(pdev, IORESOURCE_MEM,
ctx->pdata->res_info->acpi_lpe_res_index);
if (!rsrc) {
dev_err(ctx->dev, "Invalid SHIM base from IFWI");
return -EIO;
}
dev_info(ctx->dev, "LPE base: %#x size:%#x", (unsigned int) rsrc->start,
(unsigned int)resource_size(rsrc));
ctx->iram_base = rsrc->start + ctx->pdata->res_info->iram_offset;
ctx->iram_end = ctx->iram_base + ctx->pdata->res_info->iram_size - 1;
dev_info(ctx->dev, "IRAM base: %#x", ctx->iram_base);
ctx->iram = devm_ioremap_nocache(ctx->dev, ctx->iram_base,
ctx->pdata->res_info->iram_size);
if (!ctx->iram) {
dev_err(ctx->dev, "unable to map IRAM");
return -EIO;
}
ctx->dram_base = rsrc->start + ctx->pdata->res_info->dram_offset;
ctx->dram_end = ctx->dram_base + ctx->pdata->res_info->dram_size - 1;
dev_info(ctx->dev, "DRAM base: %#x", ctx->dram_base);
ctx->dram = devm_ioremap_nocache(ctx->dev, ctx->dram_base,
ctx->pdata->res_info->dram_size);
if (!ctx->dram) {
dev_err(ctx->dev, "unable to map DRAM");
return -EIO;
}
ctx->shim_phy_add = rsrc->start + ctx->pdata->res_info->shim_offset;
dev_info(ctx->dev, "SHIM base: %#x", ctx->shim_phy_add);
ctx->shim = devm_ioremap_nocache(ctx->dev, ctx->shim_phy_add,
ctx->pdata->res_info->shim_size);
if (!ctx->shim) {
dev_err(ctx->dev, "unable to map SHIM");
return -EIO;
}
ctx->shim_phy_add = ctx->pdata->res_info->shim_phy_addr;
ctx->mailbox_add = rsrc->start + ctx->pdata->res_info->mbox_offset;
dev_info(ctx->dev, "Mailbox base: %#x", ctx->mailbox_add);
ctx->mailbox = devm_ioremap_nocache(ctx->dev, ctx->mailbox_add,
ctx->pdata->res_info->mbox_size);
if (!ctx->mailbox) {
dev_err(ctx->dev, "unable to map mailbox");
return -EIO;
}
ctx->mailbox_add = ctx->info.mailbox_start;
rsrc = platform_get_resource(pdev, IORESOURCE_MEM,
ctx->pdata->res_info->acpi_ddr_index);
if (!rsrc) {
dev_err(ctx->dev, "Invalid DDR base from IFWI");
return -EIO;
}
ctx->ddr_base = rsrc->start;
ctx->ddr_end = rsrc->end;
dev_info(ctx->dev, "DDR base: %#x", ctx->ddr_base);
ctx->ddr = devm_ioremap_nocache(ctx->dev, ctx->ddr_base,
resource_size(rsrc));
if (!ctx->ddr) {
dev_err(ctx->dev, "unable to map DDR");
return -EIO;
}
ctx->irq_num = platform_get_irq(pdev,
ctx->pdata->res_info->acpi_ipc_irq_index);
return 0;
}
static acpi_status sst_acpi_mach_match(acpi_handle handle, u32 level,
void *context, void **ret)
{
*(bool *)context = true;
return AE_OK;
}
static struct sst_machines *sst_acpi_find_machine(
struct sst_machines *machines)
{
struct sst_machines *mach;
bool found = false;
for (mach = machines; mach->codec_id; mach++)
if (ACPI_SUCCESS(acpi_get_devices(mach->codec_id,
sst_acpi_mach_match,
&found, NULL)) && found)
return mach;
return NULL;
}
static int sst_acpi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int ret = 0;
struct intel_sst_drv *ctx;
const struct acpi_device_id *id;
struct sst_machines *mach;
struct platform_device *mdev;
struct platform_device *plat_dev;
unsigned int dev_id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return -ENODEV;
dev_dbg(dev, "for %s", id->id);
mach = (struct sst_machines *)id->driver_data;
mach = sst_acpi_find_machine(mach);
if (mach == NULL) {
dev_err(dev, "No matching machine driver found\n");
return -ENODEV;
}
ret = kstrtouint(id->id, 16, &dev_id);
if (ret < 0) {
dev_err(dev, "Unique device id conversion error: %d\n", ret);
return ret;
}
dev_dbg(dev, "ACPI device id: %x\n", dev_id);
plat_dev = platform_device_register_data(dev, mach->pdata->platform, -1, NULL, 0);
if (IS_ERR(plat_dev)) {
dev_err(dev, "Failed to create machine device: %s\n", mach->pdata->platform);
return PTR_ERR(plat_dev);
}
mdev = platform_device_register_data(dev, mach->machine, -1, NULL, 0);
if (IS_ERR(mdev)) {
dev_err(dev, "Failed to create machine device: %s\n", mach->machine);
return PTR_ERR(mdev);
}
ret = sst_alloc_drv_context(&ctx, dev, dev_id);
if (ret < 0)
return ret;
ctx->pdata = mach->pdata;
strcpy(ctx->firmware_name, mach->firmware);
ret = sst_platform_get_resources(ctx);
if (ret)
return ret;
ret = sst_context_init(ctx);
if (ret < 0)
return ret;
ctx->shim_regs64 = devm_kzalloc(ctx->dev, sizeof(*ctx->shim_regs64),
GFP_KERNEL);
if (!ctx->shim_regs64) {
return -ENOMEM;
goto do_sst_cleanup;
}
sst_configure_runtime_pm(ctx);
platform_set_drvdata(pdev, ctx);
return ret;
do_sst_cleanup:
sst_context_cleanup(ctx);
platform_set_drvdata(pdev, NULL);
dev_err(ctx->dev, "failed with %d\n", ret);
return ret;
}
static int sst_acpi_remove(struct platform_device *pdev)
{
struct intel_sst_drv *ctx;
ctx = platform_get_drvdata(pdev);
sst_context_cleanup(ctx);
platform_set_drvdata(pdev, NULL);
return 0;
}
