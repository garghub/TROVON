static int pl172_timing_prop(struct amba_device *adev,
const struct device_node *np, const char *name,
u32 reg_offset, u32 max, int start)
{
struct pl172_data *pl172 = amba_get_drvdata(adev);
int cycles;
u32 val;
if (!of_property_read_u32(np, name, &val)) {
cycles = DIV_ROUND_UP(val * pl172->rate, NSEC_PER_MSEC) - start;
if (cycles < 0) {
cycles = 0;
} else if (cycles > max) {
dev_err(&adev->dev, "%s timing too tight\n", name);
return -EINVAL;
}
writel(cycles, pl172->base + reg_offset);
}
dev_dbg(&adev->dev, "%s: %u cycle(s)\n", name, start +
readl(pl172->base + reg_offset));
return 0;
}
static int pl172_setup_static(struct amba_device *adev,
struct device_node *np, u32 cs)
{
struct pl172_data *pl172 = amba_get_drvdata(adev);
u32 cfg;
int ret;
if (!of_property_read_u32(np, "mpmc,memory-width", &cfg)) {
if (cfg == 8) {
cfg = MPMC_STATIC_CFG_MW_8BIT;
} else if (cfg == 16) {
cfg = MPMC_STATIC_CFG_MW_16BIT;
} else if (cfg == 32) {
cfg = MPMC_STATIC_CFG_MW_32BIT;
} else {
dev_err(&adev->dev, "invalid memory width cs%u\n", cs);
return -EINVAL;
}
} else {
dev_err(&adev->dev, "memory-width property required\n");
return -EINVAL;
}
if (of_property_read_bool(np, "mpmc,async-page-mode"))
cfg |= MPMC_STATIC_CFG_PM;
if (of_property_read_bool(np, "mpmc,cs-active-high"))
cfg |= MPMC_STATIC_CFG_PC;
if (of_property_read_bool(np, "mpmc,byte-lane-low"))
cfg |= MPMC_STATIC_CFG_PB;
if (of_property_read_bool(np, "mpmc,extended-wait"))
cfg |= MPMC_STATIC_CFG_EW;
if (amba_part(adev) == 0x172 &&
of_property_read_bool(np, "mpmc,buffer-enable"))
cfg |= MPMC_STATIC_CFG_B;
if (of_property_read_bool(np, "mpmc,write-protect"))
cfg |= MPMC_STATIC_CFG_P;
writel(cfg, pl172->base + MPMC_STATIC_CFG(cs));
dev_dbg(&adev->dev, "mpmc static config cs%u: 0x%08x\n", cs, cfg);
ret = pl172_timing_prop(adev, np, "mpmc,write-enable-delay",
MPMC_STATIC_WAIT_WEN(cs),
MPMC_STATIC_WAIT_WEN_MAX, 1);
if (ret)
goto fail;
ret = pl172_timing_prop(adev, np, "mpmc,output-enable-delay",
MPMC_STATIC_WAIT_OEN(cs),
MPMC_STATIC_WAIT_OEN_MAX, 0);
if (ret)
goto fail;
ret = pl172_timing_prop(adev, np, "mpmc,read-access-delay",
MPMC_STATIC_WAIT_RD(cs),
MPMC_STATIC_WAIT_RD_MAX, 1);
if (ret)
goto fail;
ret = pl172_timing_prop(adev, np, "mpmc,page-mode-read-delay",
MPMC_STATIC_WAIT_PAGE(cs),
MPMC_STATIC_WAIT_PAGE_MAX, 1);
if (ret)
goto fail;
ret = pl172_timing_prop(adev, np, "mpmc,write-access-delay",
MPMC_STATIC_WAIT_WR(cs),
MPMC_STATIC_WAIT_WR_MAX, 2);
if (ret)
goto fail;
ret = pl172_timing_prop(adev, np, "mpmc,turn-round-delay",
MPMC_STATIC_WAIT_TURN(cs),
MPMC_STATIC_WAIT_TURN_MAX, 1);
if (ret)
goto fail;
return 0;
fail:
dev_err(&adev->dev, "failed to configure cs%u\n", cs);
return ret;
}
static int pl172_parse_cs_config(struct amba_device *adev,
struct device_node *np)
{
u32 cs;
if (!of_property_read_u32(np, "mpmc,cs", &cs)) {
if (cs >= PL172_MAX_CS) {
dev_err(&adev->dev, "cs%u invalid\n", cs);
return -EINVAL;
}
return pl172_setup_static(adev, np, cs);
}
dev_err(&adev->dev, "cs property required\n");
return -EINVAL;
}
static int pl172_probe(struct amba_device *adev, const struct amba_id *id)
{
struct device_node *child_np, *np = adev->dev.of_node;
struct device *dev = &adev->dev;
static const char *rev = "?";
struct pl172_data *pl172;
int ret;
if (amba_part(adev) == 0x172) {
if (amba_rev(adev) < ARRAY_SIZE(pl172_revisions))
rev = pl172_revisions[amba_rev(adev)];
} else if (amba_part(adev) == 0x175) {
if (amba_rev(adev) < ARRAY_SIZE(pl175_revisions))
rev = pl175_revisions[amba_rev(adev)];
} else if (amba_part(adev) == 0x176) {
if (amba_rev(adev) < ARRAY_SIZE(pl176_revisions))
rev = pl176_revisions[amba_rev(adev)];
}
dev_info(dev, "ARM PL%x revision %s\n", amba_part(adev), rev);
pl172 = devm_kzalloc(dev, sizeof(*pl172), GFP_KERNEL);
if (!pl172)
return -ENOMEM;
pl172->clk = devm_clk_get(dev, "mpmcclk");
if (IS_ERR(pl172->clk)) {
dev_err(dev, "no mpmcclk provided clock\n");
return PTR_ERR(pl172->clk);
}
ret = clk_prepare_enable(pl172->clk);
if (ret) {
dev_err(dev, "unable to mpmcclk enable clock\n");
return ret;
}
pl172->rate = clk_get_rate(pl172->clk) / MSEC_PER_SEC;
if (!pl172->rate) {
dev_err(dev, "unable to get mpmcclk clock rate\n");
ret = -EINVAL;
goto err_clk_enable;
}
ret = amba_request_regions(adev, NULL);
if (ret) {
dev_err(dev, "unable to request AMBA regions\n");
goto err_clk_enable;
}
pl172->base = devm_ioremap(dev, adev->res.start,
resource_size(&adev->res));
if (!pl172->base) {
dev_err(dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_no_ioremap;
}
amba_set_drvdata(adev, pl172);
for_each_available_child_of_node(np, child_np) {
ret = pl172_parse_cs_config(adev, child_np);
if (ret)
continue;
of_platform_populate(child_np, NULL, NULL, dev);
}
return 0;
err_no_ioremap:
amba_release_regions(adev);
err_clk_enable:
clk_disable_unprepare(pl172->clk);
return ret;
}
static int pl172_remove(struct amba_device *adev)
{
struct pl172_data *pl172 = amba_get_drvdata(adev);
clk_disable_unprepare(pl172->clk);
amba_release_regions(adev);
return 0;
}
