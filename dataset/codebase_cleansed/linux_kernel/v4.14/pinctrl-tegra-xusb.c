static inline void padctl_writel(struct tegra_xusb_padctl *padctl, u32 value,
unsigned long offset)
{
writel(value, padctl->regs + offset);
}
static inline u32 padctl_readl(struct tegra_xusb_padctl *padctl,
unsigned long offset)
{
return readl(padctl->regs + offset);
}
static int tegra_xusb_padctl_get_groups_count(struct pinctrl_dev *pinctrl)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
return padctl->soc->num_pins;
}
static const char *tegra_xusb_padctl_get_group_name(struct pinctrl_dev *pinctrl,
unsigned int group)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
return padctl->soc->pins[group].name;
}
static int tegra_xusb_padctl_get_group_pins(struct pinctrl_dev *pinctrl,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
*pins = &pinctrl->desc->pins[group].number;
*num_pins = 1;
return 0;
}
static int tegra_xusb_padctl_parse_subnode(struct tegra_xusb_padctl *padctl,
struct device_node *np,
struct pinctrl_map **maps,
unsigned int *reserved_maps,
unsigned int *num_maps)
{
unsigned int i, reserve = 0, num_configs = 0;
unsigned long config, *configs = NULL;
const char *function, *group;
struct property *prop;
int err = 0;
u32 value;
err = of_property_read_string(np, "nvidia,function", &function);
if (err < 0) {
if (err != -EINVAL)
return err;
function = NULL;
}
for (i = 0; i < ARRAY_SIZE(properties); i++) {
err = of_property_read_u32(np, properties[i].name, &value);
if (err < 0) {
if (err == -EINVAL)
continue;
goto out;
}
config = TEGRA_XUSB_PADCTL_PACK(properties[i].param, value);
err = pinctrl_utils_add_config(padctl->pinctrl, &configs,
&num_configs, config);
if (err < 0)
goto out;
}
if (function)
reserve++;
if (num_configs)
reserve++;
err = of_property_count_strings(np, "nvidia,lanes");
if (err < 0)
goto out;
reserve *= err;
err = pinctrl_utils_reserve_map(padctl->pinctrl, maps, reserved_maps,
num_maps, reserve);
if (err < 0)
goto out;
of_property_for_each_string(np, "nvidia,lanes", prop, group) {
if (function) {
err = pinctrl_utils_add_map_mux(padctl->pinctrl, maps,
reserved_maps, num_maps, group,
function);
if (err < 0)
goto out;
}
if (num_configs) {
err = pinctrl_utils_add_map_configs(padctl->pinctrl,
maps, reserved_maps, num_maps, group,
configs, num_configs,
PIN_MAP_TYPE_CONFIGS_GROUP);
if (err < 0)
goto out;
}
}
err = 0;
out:
kfree(configs);
return err;
}
static int tegra_xusb_padctl_dt_node_to_map(struct pinctrl_dev *pinctrl,
struct device_node *parent,
struct pinctrl_map **maps,
unsigned int *num_maps)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
unsigned int reserved_maps = 0;
struct device_node *np;
int err;
*num_maps = 0;
*maps = NULL;
for_each_child_of_node(parent, np) {
err = tegra_xusb_padctl_parse_subnode(padctl, np, maps,
&reserved_maps,
num_maps);
if (err < 0) {
of_node_put(np);
return err;
}
}
return 0;
}
static int tegra_xusb_padctl_get_functions_count(struct pinctrl_dev *pinctrl)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
return padctl->soc->num_functions;
}
static const char *
tegra_xusb_padctl_get_function_name(struct pinctrl_dev *pinctrl,
unsigned int function)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
return padctl->soc->functions[function].name;
}
static int tegra_xusb_padctl_get_function_groups(struct pinctrl_dev *pinctrl,
unsigned int function,
const char * const **groups,
unsigned * const num_groups)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
*num_groups = padctl->soc->functions[function].num_groups;
*groups = padctl->soc->functions[function].groups;
return 0;
}
static int tegra_xusb_padctl_pinmux_set(struct pinctrl_dev *pinctrl,
unsigned int function,
unsigned int group)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
const struct tegra_xusb_padctl_lane *lane;
unsigned int i;
u32 value;
lane = &padctl->soc->lanes[group];
for (i = 0; i < lane->num_funcs; i++)
if (lane->funcs[i] == function)
break;
if (i >= lane->num_funcs)
return -EINVAL;
value = padctl_readl(padctl, lane->offset);
value &= ~(lane->mask << lane->shift);
value |= i << lane->shift;
padctl_writel(padctl, value, lane->offset);
return 0;
}
static int tegra_xusb_padctl_pinconf_group_get(struct pinctrl_dev *pinctrl,
unsigned int group,
unsigned long *config)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
const struct tegra_xusb_padctl_lane *lane;
enum tegra_xusb_padctl_param param;
u32 value;
param = TEGRA_XUSB_PADCTL_UNPACK_PARAM(*config);
lane = &padctl->soc->lanes[group];
switch (param) {
case TEGRA_XUSB_PADCTL_IDDQ:
if (lane->iddq == 0)
return -EINVAL;
value = padctl_readl(padctl, lane->offset);
if (value & BIT(lane->iddq))
value = 0;
else
value = 1;
*config = TEGRA_XUSB_PADCTL_PACK(param, value);
break;
default:
dev_err(padctl->dev, "invalid configuration parameter: %04x\n",
param);
return -ENOTSUPP;
}
return 0;
}
static int tegra_xusb_padctl_pinconf_group_set(struct pinctrl_dev *pinctrl,
unsigned int group,
unsigned long *configs,
unsigned int num_configs)
{
struct tegra_xusb_padctl *padctl = pinctrl_dev_get_drvdata(pinctrl);
const struct tegra_xusb_padctl_lane *lane;
enum tegra_xusb_padctl_param param;
unsigned long value;
unsigned int i;
u32 regval;
lane = &padctl->soc->lanes[group];
for (i = 0; i < num_configs; i++) {
param = TEGRA_XUSB_PADCTL_UNPACK_PARAM(configs[i]);
value = TEGRA_XUSB_PADCTL_UNPACK_VALUE(configs[i]);
switch (param) {
case TEGRA_XUSB_PADCTL_IDDQ:
if (lane->iddq == 0)
return -EINVAL;
regval = padctl_readl(padctl, lane->offset);
if (value)
regval &= ~BIT(lane->iddq);
else
regval |= BIT(lane->iddq);
padctl_writel(padctl, regval, lane->offset);
break;
default:
dev_err(padctl->dev,
"invalid configuration parameter: %04x\n",
param);
return -ENOTSUPP;
}
}
return 0;
}
static const char *strip_prefix(const char *s)
{
const char *comma = strchr(s, ',');
if (!comma)
return s;
return comma + 1;
}
static void
tegra_xusb_padctl_pinconf_group_dbg_show(struct pinctrl_dev *pinctrl,
struct seq_file *s,
unsigned int group)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(properties); i++) {
unsigned long config, value;
int err;
config = TEGRA_XUSB_PADCTL_PACK(properties[i].param, 0);
err = tegra_xusb_padctl_pinconf_group_get(pinctrl, group,
&config);
if (err < 0)
continue;
value = TEGRA_XUSB_PADCTL_UNPACK_VALUE(config);
seq_printf(s, "\n\t%s=%lu\n", strip_prefix(properties[i].name),
value);
}
}
static void
tegra_xusb_padctl_pinconf_config_dbg_show(struct pinctrl_dev *pinctrl,
struct seq_file *s,
unsigned long config)
{
enum tegra_xusb_padctl_param param;
const char *name = "unknown";
unsigned long value;
unsigned int i;
param = TEGRA_XUSB_PADCTL_UNPACK_PARAM(config);
value = TEGRA_XUSB_PADCTL_UNPACK_VALUE(config);
for (i = 0; i < ARRAY_SIZE(properties); i++) {
if (properties[i].param == param) {
name = properties[i].name;
break;
}
}
seq_printf(s, "%s=%lu", strip_prefix(name), value);
}
static int tegra_xusb_padctl_enable(struct tegra_xusb_padctl *padctl)
{
u32 value;
mutex_lock(&padctl->lock);
if (padctl->enable++ > 0)
goto out;
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM);
value &= ~XUSB_PADCTL_ELPG_PROGRAM_AUX_MUX_LP0_CLAMP_EN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM);
value &= ~XUSB_PADCTL_ELPG_PROGRAM_AUX_MUX_LP0_CLAMP_EN_EARLY;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM);
value &= ~XUSB_PADCTL_ELPG_PROGRAM_AUX_MUX_LP0_VCORE_DOWN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM);
out:
mutex_unlock(&padctl->lock);
return 0;
}
static int tegra_xusb_padctl_disable(struct tegra_xusb_padctl *padctl)
{
u32 value;
mutex_lock(&padctl->lock);
if (WARN_ON(padctl->enable == 0))
goto out;
if (--padctl->enable > 0)
goto out;
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM);
value |= XUSB_PADCTL_ELPG_PROGRAM_AUX_MUX_LP0_VCORE_DOWN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM);
value |= XUSB_PADCTL_ELPG_PROGRAM_AUX_MUX_LP0_CLAMP_EN_EARLY;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM);
usleep_range(100, 200);
value = padctl_readl(padctl, XUSB_PADCTL_ELPG_PROGRAM);
value |= XUSB_PADCTL_ELPG_PROGRAM_AUX_MUX_LP0_CLAMP_EN;
padctl_writel(padctl, value, XUSB_PADCTL_ELPG_PROGRAM);
out:
mutex_unlock(&padctl->lock);
return 0;
}
static int tegra_xusb_phy_init(struct phy *phy)
{
struct tegra_xusb_padctl *padctl = phy_get_drvdata(phy);
return tegra_xusb_padctl_enable(padctl);
}
static int tegra_xusb_phy_exit(struct phy *phy)
{
struct tegra_xusb_padctl *padctl = phy_get_drvdata(phy);
return tegra_xusb_padctl_disable(padctl);
}
static int pcie_phy_power_on(struct phy *phy)
{
struct tegra_xusb_padctl *padctl = phy_get_drvdata(phy);
unsigned long timeout;
int err = -ETIMEDOUT;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
value &= ~XUSB_PADCTL_IOPHY_PLL_P0_CTL1_REFCLK_SEL_MASK;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_P0_CTL2);
value |= XUSB_PADCTL_IOPHY_PLL_P0_CTL2_REFCLKBUF_EN |
XUSB_PADCTL_IOPHY_PLL_P0_CTL2_TXCLKREF_EN |
XUSB_PADCTL_IOPHY_PLL_P0_CTL2_TXCLKREF_SEL;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_P0_CTL2);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
value |= XUSB_PADCTL_IOPHY_PLL_P0_CTL1_PLL_RST;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
timeout = jiffies + msecs_to_jiffies(50);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
if (value & XUSB_PADCTL_IOPHY_PLL_P0_CTL1_PLL0_LOCKDET) {
err = 0;
break;
}
usleep_range(100, 200);
}
return err;
}
static int pcie_phy_power_off(struct phy *phy)
{
struct tegra_xusb_padctl *padctl = phy_get_drvdata(phy);
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
value &= ~XUSB_PADCTL_IOPHY_PLL_P0_CTL1_PLL_RST;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_P0_CTL1);
return 0;
}
static int sata_phy_power_on(struct phy *phy)
{
struct tegra_xusb_padctl *padctl = phy_get_drvdata(phy);
unsigned long timeout;
int err = -ETIMEDOUT;
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1);
value &= ~XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1_IDDQ_OVRD;
value &= ~XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1_IDDQ;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value &= ~XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL_PWR_OVRD;
value &= ~XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL_IDDQ;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value |= XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL1_MODE;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value |= XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL_RST;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
timeout = jiffies + msecs_to_jiffies(50);
while (time_before(jiffies, timeout)) {
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
if (value & XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL1_LOCKDET) {
err = 0;
break;
}
usleep_range(100, 200);
}
return err;
}
static int sata_phy_power_off(struct phy *phy)
{
struct tegra_xusb_padctl *padctl = phy_get_drvdata(phy);
u32 value;
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value &= ~XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL_RST;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value &= ~XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL1_MODE;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value |= XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL_PWR_OVRD;
value |= XUSB_PADCTL_IOPHY_PLL_S0_CTL1_PLL_IDDQ;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_PLL_S0_CTL1);
value = padctl_readl(padctl, XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1);
value |= ~XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1_IDDQ_OVRD;
value |= ~XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1_IDDQ;
padctl_writel(padctl, value, XUSB_PADCTL_IOPHY_MISC_PAD_S0_CTL1);
return 0;
}
static struct phy *tegra_xusb_padctl_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct tegra_xusb_padctl *padctl = dev_get_drvdata(dev);
unsigned int index = args->args[0];
if (args->args_count <= 0)
return ERR_PTR(-EINVAL);
if (index >= ARRAY_SIZE(padctl->phys))
return ERR_PTR(-EINVAL);
return padctl->phys[index];
}
int tegra_xusb_padctl_legacy_probe(struct platform_device *pdev)
{
struct tegra_xusb_padctl *padctl;
const struct of_device_id *match;
struct resource *res;
struct phy *phy;
int err;
padctl = devm_kzalloc(&pdev->dev, sizeof(*padctl), GFP_KERNEL);
if (!padctl)
return -ENOMEM;
platform_set_drvdata(pdev, padctl);
mutex_init(&padctl->lock);
padctl->dev = &pdev->dev;
match = of_match_node(tegra_xusb_padctl_of_match, pdev->dev.of_node);
padctl->soc = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
padctl->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(padctl->regs))
return PTR_ERR(padctl->regs);
padctl->rst = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (IS_ERR(padctl->rst))
return PTR_ERR(padctl->rst);
err = reset_control_deassert(padctl->rst);
if (err < 0)
return err;
memset(&padctl->desc, 0, sizeof(padctl->desc));
padctl->desc.name = dev_name(padctl->dev);
padctl->desc.pins = tegra124_pins;
padctl->desc.npins = ARRAY_SIZE(tegra124_pins);
padctl->desc.pctlops = &tegra_xusb_padctl_pinctrl_ops;
padctl->desc.pmxops = &tegra_xusb_padctl_pinmux_ops;
padctl->desc.confops = &tegra_xusb_padctl_pinconf_ops;
padctl->desc.owner = THIS_MODULE;
padctl->pinctrl = devm_pinctrl_register(&pdev->dev, &padctl->desc,
padctl);
if (IS_ERR(padctl->pinctrl)) {
dev_err(&pdev->dev, "failed to register pincontrol\n");
err = PTR_ERR(padctl->pinctrl);
goto reset;
}
phy = devm_phy_create(&pdev->dev, NULL, &pcie_phy_ops);
if (IS_ERR(phy)) {
err = PTR_ERR(phy);
goto reset;
}
padctl->phys[TEGRA_XUSB_PADCTL_PCIE] = phy;
phy_set_drvdata(phy, padctl);
phy = devm_phy_create(&pdev->dev, NULL, &sata_phy_ops);
if (IS_ERR(phy)) {
err = PTR_ERR(phy);
goto reset;
}
padctl->phys[TEGRA_XUSB_PADCTL_SATA] = phy;
phy_set_drvdata(phy, padctl);
padctl->provider = devm_of_phy_provider_register(&pdev->dev,
tegra_xusb_padctl_xlate);
if (IS_ERR(padctl->provider)) {
err = PTR_ERR(padctl->provider);
dev_err(&pdev->dev, "failed to register PHYs: %d\n", err);
goto reset;
}
return 0;
reset:
reset_control_assert(padctl->rst);
return err;
}
int tegra_xusb_padctl_legacy_remove(struct platform_device *pdev)
{
struct tegra_xusb_padctl *padctl = platform_get_drvdata(pdev);
int err;
err = reset_control_assert(padctl->rst);
if (err < 0)
dev_err(&pdev->dev, "failed to assert reset: %d\n", err);
return err;
}
