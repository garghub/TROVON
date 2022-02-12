static const struct da8xx_ddrctl_config_knob *
da8xx_ddrctl_match_knob(const struct da8xx_ddrctl_setting *setting)
{
const struct da8xx_ddrctl_config_knob *knob;
int i;
for (i = 0; i < ARRAY_SIZE(da8xx_ddrctl_knobs); i++) {
knob = &da8xx_ddrctl_knobs[i];
if (strcmp(knob->name, setting->name) == 0)
return knob;
}
return NULL;
}
static const struct da8xx_ddrctl_setting *da8xx_ddrctl_get_board_settings(void)
{
const struct da8xx_ddrctl_board_settings *board_settings;
int i;
for (i = 0; i < ARRAY_SIZE(da8xx_ddrctl_board_confs); i++) {
board_settings = &da8xx_ddrctl_board_confs[i];
if (of_machine_is_compatible(board_settings->board))
return board_settings->settings;
}
return NULL;
}
static int da8xx_ddrctl_probe(struct platform_device *pdev)
{
const struct da8xx_ddrctl_config_knob *knob;
const struct da8xx_ddrctl_setting *setting;
struct device_node *node;
struct resource *res;
void __iomem *ddrctl;
struct device *dev;
u32 reg;
dev = &pdev->dev;
node = dev->of_node;
setting = da8xx_ddrctl_get_board_settings();
if (!setting) {
dev_err(dev, "no settings defined for this board\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ddrctl = devm_ioremap_resource(dev, res);
if (IS_ERR(ddrctl)) {
dev_err(dev, "unable to map memory controller registers\n");
return PTR_ERR(ddrctl);
}
for (; setting->name; setting++) {
knob = da8xx_ddrctl_match_knob(setting);
if (!knob) {
dev_warn(dev,
"no such config option: %s\n", setting->name);
continue;
}
if (knob->reg + sizeof(u32) > resource_size(res)) {
dev_warn(dev,
"register offset of '%s' exceeds mapped memory size\n",
knob->name);
continue;
}
reg = readl(ddrctl + knob->reg);
reg &= knob->mask;
reg |= setting->val << knob->shift;
dev_dbg(dev, "writing 0x%08x to %s\n", reg, setting->name);
writel(reg, ddrctl + knob->reg);
}
return 0;
}
