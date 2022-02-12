static irqreturn_t highbank_mc_err_handler(int irq, void *dev_id)
{
struct mem_ctl_info *mci = dev_id;
struct hb_mc_drvdata *drvdata = mci->pvt_info;
u32 status, err_addr;
status = readl(drvdata->mc_int_base + HB_DDR_ECC_INT_STATUS);
if (status & HB_DDR_ECC_INT_STAT_UE) {
err_addr = readl(drvdata->mc_err_base + HB_DDR_ECC_U_ERR_ADDR);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
err_addr >> PAGE_SHIFT,
err_addr & ~PAGE_MASK, 0,
0, 0, -1,
mci->ctl_name, "");
}
if (status & HB_DDR_ECC_INT_STAT_CE) {
u32 syndrome = readl(drvdata->mc_err_base + HB_DDR_ECC_C_ERR_STAT);
syndrome = (syndrome >> 8) & 0xff;
err_addr = readl(drvdata->mc_err_base + HB_DDR_ECC_C_ERR_ADDR);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
err_addr >> PAGE_SHIFT,
err_addr & ~PAGE_MASK, syndrome,
0, 0, -1,
mci->ctl_name, "");
}
writel(status, drvdata->mc_int_base + HB_DDR_ECC_INT_ACK);
return IRQ_HANDLED;
}
static void highbank_mc_err_inject(struct mem_ctl_info *mci, u8 synd)
{
struct hb_mc_drvdata *pdata = mci->pvt_info;
u32 reg;
reg = readl(pdata->mc_err_base + HB_DDR_ECC_OPT);
reg &= HB_DDR_ECC_OPT_MODE_MASK;
reg |= (synd << HB_DDR_ECC_OPT_XOR_SHIFT) | HB_DDR_ECC_OPT_FWC;
writel(reg, pdata->mc_err_base + HB_DDR_ECC_OPT);
}
static ssize_t highbank_mc_inject_ctrl(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct mem_ctl_info *mci = to_mci(dev);
u8 synd;
if (kstrtou8(buf, 16, &synd))
return -EINVAL;
highbank_mc_err_inject(mci, synd);
return count;
}
static int highbank_mc_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
const struct hb_mc_settings *settings;
struct edac_mc_layer layers[2];
struct mem_ctl_info *mci;
struct hb_mc_drvdata *drvdata;
struct dimm_info *dimm;
struct resource *r;
void __iomem *base;
u32 control;
int irq;
int res = 0;
id = of_match_device(hb_ddr_ctrl_of_match, &pdev->dev);
if (!id)
return -ENODEV;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = 1;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = 1;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers,
sizeof(struct hb_mc_drvdata));
if (!mci)
return -ENOMEM;
mci->pdev = &pdev->dev;
drvdata = mci->pvt_info;
platform_set_drvdata(pdev, mci);
if (!devres_open_group(&pdev->dev, NULL, GFP_KERNEL))
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "Unable to get mem resource\n");
res = -ENODEV;
goto err;
}
if (!devm_request_mem_region(&pdev->dev, r->start,
resource_size(r), dev_name(&pdev->dev))) {
dev_err(&pdev->dev, "Error while requesting mem region\n");
res = -EBUSY;
goto err;
}
base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!base) {
dev_err(&pdev->dev, "Unable to map regs\n");
res = -ENOMEM;
goto err;
}
settings = id->data;
drvdata->mc_err_base = base + settings->err_offset;
drvdata->mc_int_base = base + settings->int_offset;
control = readl(drvdata->mc_err_base + HB_DDR_ECC_OPT) & 0x3;
if (!control || (control == 0x2)) {
dev_err(&pdev->dev, "No ECC present, or ECC disabled\n");
res = -ENODEV;
goto err;
}
mci->mtype_cap = MEM_FLAG_DDR3;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = pdev->dev.driver->name;
mci->mod_ver = "1";
mci->ctl_name = id->compatible;
mci->dev_name = dev_name(&pdev->dev);
mci->scrub_mode = SCRUB_SW_SRC;
dimm = *mci->dimms;
dimm->nr_pages = (~0UL >> PAGE_SHIFT) + 1;
dimm->grain = 8;
dimm->dtype = DEV_X8;
dimm->mtype = MEM_DDR3;
dimm->edac_mode = EDAC_SECDED;
res = edac_mc_add_mc_with_groups(mci, highbank_dev_groups);
if (res < 0)
goto err;
irq = platform_get_irq(pdev, 0);
res = devm_request_irq(&pdev->dev, irq, highbank_mc_err_handler,
0, dev_name(&pdev->dev), mci);
if (res < 0) {
dev_err(&pdev->dev, "Unable to request irq %d\n", irq);
goto err2;
}
devres_close_group(&pdev->dev, NULL);
return 0;
err2:
edac_mc_del_mc(&pdev->dev);
err:
devres_release_group(&pdev->dev, NULL);
edac_mc_free(mci);
return res;
}
static int highbank_mc_remove(struct platform_device *pdev)
{
struct mem_ctl_info *mci = platform_get_drvdata(pdev);
edac_mc_del_mc(&pdev->dev);
edac_mc_free(mci);
return 0;
}
