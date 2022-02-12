static inline int rsctrl_enable_rspll_write(void)
{
return regmap_update_bits(pllctrl_regs, rspll_offset + RSCTRL_RG,
RSCTRL_KEY_MASK, RSCTRL_KEY);
}
static int rsctrl_restart_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
rsctrl_enable_rspll_write();
regmap_update_bits(pllctrl_regs, rspll_offset + RSCTRL_RG,
RSCTRL_RESET_MASK, 0);
return NOTIFY_DONE;
}
static int rsctrl_probe(struct platform_device *pdev)
{
int i;
int ret;
u32 val;
unsigned int rg;
u32 rsmux_offset;
struct regmap *devctrl_regs;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
if (!np)
return -ENODEV;
pllctrl_regs = syscon_regmap_lookup_by_phandle(np, "ti,syscon-pll");
if (IS_ERR(pllctrl_regs))
return PTR_ERR(pllctrl_regs);
devctrl_regs = syscon_regmap_lookup_by_phandle(np, "ti,syscon-dev");
if (IS_ERR(devctrl_regs))
return PTR_ERR(devctrl_regs);
ret = of_property_read_u32_index(np, "ti,syscon-pll", 1, &rspll_offset);
if (ret) {
dev_err(dev, "couldn't read the reset pll offset!\n");
return -EINVAL;
}
ret = of_property_read_u32_index(np, "ti,syscon-dev", 1, &rsmux_offset);
if (ret) {
dev_err(dev, "couldn't read the rsmux offset!\n");
return -EINVAL;
}
val = of_property_read_bool(np, "ti,soft-reset");
val = val ? RSCFG_RSTYPE_SOFT : RSCFG_RSTYPE_HARD;
ret = rsctrl_enable_rspll_write();
if (ret)
return ret;
ret = regmap_write(pllctrl_regs, rspll_offset + RSCFG_RG, val);
if (ret)
return ret;
ret = regmap_write(pllctrl_regs, rspll_offset + RSISO_RG, 0);
if (ret)
return ret;
for (i = 0; i < WDT_MUX_NUMBER; i++) {
ret = of_property_read_u32_index(np, "ti,wdt-list", i, &val);
if (ret == -EOVERFLOW && !i) {
dev_err(dev, "ti,wdt-list property has to contain at"
"least one entry\n");
return -EINVAL;
} else if (ret) {
break;
}
if (val >= WDT_MUX_NUMBER) {
dev_err(dev, "ti,wdt-list property can contain"
"only numbers < 4\n");
return -EINVAL;
}
rg = rsmux_offset + val * 4;
ret = regmap_update_bits(devctrl_regs, rg, RSMUX_OMODE_MASK,
RSMUX_OMODE_RESET_ON |
RSMUX_LOCK_SET);
if (ret)
return ret;
}
ret = register_restart_handler(&rsctrl_restart_nb);
if (ret)
dev_err(dev, "cannot register restart handler (err=%d)\n", ret);
return ret;
}
