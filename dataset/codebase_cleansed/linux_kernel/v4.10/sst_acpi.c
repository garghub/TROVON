static int sst_platform_get_resources(struct intel_sst_drv *ctx)
{
struct resource *rsrc;
struct platform_device *pdev = to_platform_device(ctx->dev);
rsrc = platform_get_resource(pdev, IORESOURCE_MEM,
ctx->pdata->res_info->acpi_lpe_res_index);
if (!rsrc) {
dev_err(ctx->dev, "Invalid SHIM base from IFWI\n");
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
dev_err(ctx->dev, "unable to map IRAM\n");
return -EIO;
}
ctx->dram_base = rsrc->start + ctx->pdata->res_info->dram_offset;
ctx->dram_end = ctx->dram_base + ctx->pdata->res_info->dram_size - 1;
dev_info(ctx->dev, "DRAM base: %#x", ctx->dram_base);
ctx->dram = devm_ioremap_nocache(ctx->dev, ctx->dram_base,
ctx->pdata->res_info->dram_size);
if (!ctx->dram) {
dev_err(ctx->dev, "unable to map DRAM\n");
return -EIO;
}
ctx->shim_phy_add = rsrc->start + ctx->pdata->res_info->shim_offset;
dev_info(ctx->dev, "SHIM base: %#x", ctx->shim_phy_add);
ctx->shim = devm_ioremap_nocache(ctx->dev, ctx->shim_phy_add,
ctx->pdata->res_info->shim_size);
if (!ctx->shim) {
dev_err(ctx->dev, "unable to map SHIM\n");
return -EIO;
}
ctx->shim_phy_add = ctx->pdata->res_info->shim_phy_addr;
ctx->mailbox_add = rsrc->start + ctx->pdata->res_info->mbox_offset;
dev_info(ctx->dev, "Mailbox base: %#x", ctx->mailbox_add);
ctx->mailbox = devm_ioremap_nocache(ctx->dev, ctx->mailbox_add,
ctx->pdata->res_info->mbox_size);
if (!ctx->mailbox) {
dev_err(ctx->dev, "unable to map mailbox\n");
return -EIO;
}
ctx->mailbox_add = ctx->info.mailbox_start;
rsrc = platform_get_resource(pdev, IORESOURCE_MEM,
ctx->pdata->res_info->acpi_ddr_index);
if (!rsrc) {
dev_err(ctx->dev, "Invalid DDR base from IFWI\n");
return -EIO;
}
ctx->ddr_base = rsrc->start;
ctx->ddr_end = rsrc->end;
dev_info(ctx->dev, "DDR base: %#x", ctx->ddr_base);
ctx->ddr = devm_ioremap_nocache(ctx->dev, ctx->ddr_base,
resource_size(rsrc));
if (!ctx->ddr) {
dev_err(ctx->dev, "unable to map DDR\n");
return -EIO;
}
ctx->irq_num = platform_get_irq(pdev,
ctx->pdata->res_info->acpi_ipc_irq_index);
return 0;
}
static int is_byt_cr(struct device *dev, bool *bytcr)
{
int status = 0;
if (IS_ENABLED(CONFIG_IOSF_MBI)) {
static const struct x86_cpu_id cpu_ids[] = {
{ X86_VENDOR_INTEL, 6, 55 },
{}
};
u32 bios_status;
if (!x86_match_cpu(cpu_ids) || !iosf_mbi_available()) {
return status;
}
status = iosf_mbi_read(BT_MBI_UNIT_PMC,
MBI_REG_READ,
0x006,
&bios_status);
if (status) {
dev_err(dev, "could not read PUNIT BIOS_CONFIG\n");
} else {
bios_status = (bios_status >> 26) & 3;
if ((bios_status == 1) || (bios_status == 3))
*bytcr = true;
else
dev_info(dev, "BYT-CR not detected\n");
}
} else {
dev_info(dev, "IOSF_MBI not enabled, no BYT-CR detection\n");
}
return status;
}
static int sst_acpi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int ret = 0;
struct intel_sst_drv *ctx;
const struct acpi_device_id *id;
struct sst_acpi_mach *mach;
struct platform_device *mdev;
struct platform_device *plat_dev;
struct sst_platform_info *pdata;
unsigned int dev_id;
bool bytcr = false;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return -ENODEV;
dev_dbg(dev, "for %s\n", id->id);
mach = (struct sst_acpi_mach *)id->driver_data;
mach = sst_acpi_find_machine(mach);
if (mach == NULL) {
dev_err(dev, "No matching machine driver found\n");
return -ENODEV;
}
if (mach->machine_quirk)
mach = mach->machine_quirk(mach);
pdata = mach->pdata;
ret = kstrtouint(id->id, 16, &dev_id);
if (ret < 0) {
dev_err(dev, "Unique device id conversion error: %d\n", ret);
return ret;
}
dev_dbg(dev, "ACPI device id: %x\n", dev_id);
ret = sst_alloc_drv_context(&ctx, dev, dev_id);
if (ret < 0)
return ret;
ret = is_byt_cr(dev, &bytcr);
if (!((ret < 0) || (bytcr == false))) {
dev_info(dev, "Detected Baytrail-CR platform\n");
byt_rvp_platform_data.res_info = &bytcr_res_info;
}
plat_dev = platform_device_register_data(dev, pdata->platform, -1,
NULL, 0);
if (IS_ERR(plat_dev)) {
dev_err(dev, "Failed to create machine device: %s\n",
pdata->platform);
return PTR_ERR(plat_dev);
}
mdev = platform_device_register_data(dev, mach->drv_name, -1,
(const void *)mach, sizeof(*mach));
if (IS_ERR(mdev)) {
dev_err(dev, "Failed to create machine device: %s\n",
mach->drv_name);
return PTR_ERR(mdev);
}
ctx->pdata = pdata;
strcpy(ctx->firmware_name, mach->fw_filename);
ret = sst_platform_get_resources(ctx);
if (ret)
return ret;
ret = sst_context_init(ctx);
if (ret < 0)
return ret;
ctx->shim_regs64 = devm_kzalloc(ctx->dev, sizeof(*ctx->shim_regs64),
GFP_KERNEL);
if (!ctx->shim_regs64) {
ret = -ENOMEM;
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
static int cht_surface_quirk_cb(const struct dmi_system_id *id)
{
cht_machine_id = CHT_SURFACE_MACH;
return 1;
}
static struct sst_acpi_mach *cht_quirk(void *arg)
{
struct sst_acpi_mach *mach = arg;
dmi_check_system(cht_table);
if (cht_machine_id == CHT_SURFACE_MACH)
return &cht_surface_mach;
else
return mach;
}
