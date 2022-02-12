static int zynq_pctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->ngroups;
}
static const char *zynq_pctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->groups[selector].name;
}
static int zynq_pctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = pctrl->groups[selector].pins;
*num_pins = pctrl->groups[selector].npins;
return 0;
}
static int zynq_pmux_get_functions_count(struct pinctrl_dev *pctldev)
{
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->nfuncs;
}
static const char *zynq_pmux_get_function_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->funcs[selector].name;
}
static int zynq_pmux_get_function_groups(struct pinctrl_dev *pctldev,
unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctrl->funcs[selector].groups;
*num_groups = pctrl->funcs[selector].ngroups;
return 0;
}
static int zynq_pinmux_set_mux(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
int i, ret;
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
const struct zynq_pctrl_group *pgrp = &pctrl->groups[group];
const struct zynq_pinmux_function *func = &pctrl->funcs[function];
if (function == ZYNQ_PMUX_sdio0_cd || function == ZYNQ_PMUX_sdio0_wp ||
function == ZYNQ_PMUX_sdio1_cd ||
function == ZYNQ_PMUX_sdio1_wp) {
u32 reg;
ret = regmap_read(pctrl->syscon,
pctrl->pctrl_offset + func->mux, &reg);
if (ret)
return ret;
reg &= ~func->mux_mask;
reg |= pgrp->pins[0] << func->mux_shift;
ret = regmap_write(pctrl->syscon,
pctrl->pctrl_offset + func->mux, reg);
if (ret)
return ret;
} else {
for (i = 0; i < pgrp->npins; i++) {
unsigned int pin = pgrp->pins[i];
u32 reg, addr = pctrl->pctrl_offset + (4 * pin);
ret = regmap_read(pctrl->syscon, addr, &reg);
if (ret)
return ret;
reg &= ~ZYNQ_PINMUX_MUX_MASK;
reg |= func->mux_val << ZYNQ_PINMUX_MUX_SHIFT;
ret = regmap_write(pctrl->syscon, addr, reg);
if (ret)
return ret;
}
}
return 0;
}
static unsigned int zynq_pinconf_iostd_get(u32 reg)
{
return (reg & ZYNQ_PINCONF_IOTYPE_MASK) >> ZYNQ_PINCONF_IOTYPE_SHIFT;
}
static int zynq_pinconf_cfg_get(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *config)
{
u32 reg;
int ret;
unsigned int arg = 0;
unsigned int param = pinconf_to_config_param(*config);
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
if (pin >= ZYNQ_NUM_MIOS)
return -ENOTSUPP;
ret = regmap_read(pctrl->syscon, pctrl->pctrl_offset + (4 * pin), &reg);
if (ret)
return -EIO;
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
if (!(reg & ZYNQ_PINCONF_PULLUP))
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
if (!(reg & ZYNQ_PINCONF_TRISTATE))
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_BIAS_DISABLE:
if (reg & ZYNQ_PINCONF_PULLUP || reg & ZYNQ_PINCONF_TRISTATE)
return -EINVAL;
break;
case PIN_CONFIG_SLEW_RATE:
arg = !!(reg & ZYNQ_PINCONF_SPEED);
break;
case PIN_CONFIG_LOW_POWER_MODE:
{
enum zynq_io_standards iostd = zynq_pinconf_iostd_get(reg);
if (iostd != zynq_iostd_hstl)
return -EINVAL;
if (!(reg & ZYNQ_PINCONF_DISABLE_RECVR))
return -EINVAL;
arg = !!(reg & ZYNQ_PINCONF_DISABLE_RECVR);
break;
}
case PIN_CONFIG_IOSTANDARD:
arg = zynq_pinconf_iostd_get(reg);
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int zynq_pinconf_cfg_set(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs)
{
int i, ret;
u32 reg;
u32 pullup = 0;
u32 tristate = 0;
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
if (pin >= ZYNQ_NUM_MIOS)
return -ENOTSUPP;
ret = regmap_read(pctrl->syscon, pctrl->pctrl_offset + (4 * pin), &reg);
if (ret)
return -EIO;
for (i = 0; i < num_configs; i++) {
unsigned int param = pinconf_to_config_param(configs[i]);
unsigned int arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
pullup = ZYNQ_PINCONF_PULLUP;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
tristate = ZYNQ_PINCONF_TRISTATE;
break;
case PIN_CONFIG_BIAS_DISABLE:
reg &= ~(ZYNQ_PINCONF_PULLUP | ZYNQ_PINCONF_TRISTATE);
break;
case PIN_CONFIG_SLEW_RATE:
if (arg)
reg |= ZYNQ_PINCONF_SPEED;
else
reg &= ~ZYNQ_PINCONF_SPEED;
break;
case PIN_CONFIG_IOSTANDARD:
if (arg <= zynq_iostd_min || arg >= zynq_iostd_max) {
dev_warn(pctldev->dev,
"unsupported IO standard '%u'\n",
param);
break;
}
reg &= ~ZYNQ_PINCONF_IOTYPE_MASK;
reg |= arg << ZYNQ_PINCONF_IOTYPE_SHIFT;
break;
case PIN_CONFIG_LOW_POWER_MODE:
if (arg)
reg |= ZYNQ_PINCONF_DISABLE_RECVR;
else
reg &= ~ZYNQ_PINCONF_DISABLE_RECVR;
break;
default:
dev_warn(pctldev->dev,
"unsupported configuration parameter '%u'\n",
param);
continue;
}
}
if (tristate || pullup) {
reg &= ~(ZYNQ_PINCONF_PULLUP | ZYNQ_PINCONF_TRISTATE);
reg |= tristate | pullup;
}
ret = regmap_write(pctrl->syscon, pctrl->pctrl_offset + (4 * pin), reg);
if (ret)
return -EIO;
return 0;
}
static int zynq_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned selector,
unsigned long *configs,
unsigned num_configs)
{
int i, ret;
struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
const struct zynq_pctrl_group *pgrp = &pctrl->groups[selector];
for (i = 0; i < pgrp->npins; i++) {
ret = zynq_pinconf_cfg_set(pctldev, pgrp->pins[i], configs,
num_configs);
if (ret)
return ret;
}
return 0;
}
static int zynq_pinctrl_probe(struct platform_device *pdev)
{
struct resource *res;
struct zynq_pinctrl *pctrl;
pctrl = devm_kzalloc(&pdev->dev, sizeof(*pctrl), GFP_KERNEL);
if (!pctrl)
return -ENOMEM;
pctrl->syscon = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"syscon");
if (IS_ERR(pctrl->syscon)) {
dev_err(&pdev->dev, "unable to get syscon\n");
return PTR_ERR(pctrl->syscon);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "missing IO resource\n");
return -ENODEV;
}
pctrl->pctrl_offset = res->start;
pctrl->groups = zynq_pctrl_groups;
pctrl->ngroups = ARRAY_SIZE(zynq_pctrl_groups);
pctrl->funcs = zynq_pmux_functions;
pctrl->nfuncs = ARRAY_SIZE(zynq_pmux_functions);
pctrl->pctrl = pinctrl_register(&zynq_desc, &pdev->dev, pctrl);
if (IS_ERR(pctrl->pctrl))
return PTR_ERR(pctrl->pctrl);
platform_set_drvdata(pdev, pctrl);
dev_info(&pdev->dev, "zynq pinctrl initialized\n");
return 0;
}
static int zynq_pinctrl_remove(struct platform_device *pdev)
{
struct zynq_pinctrl *pctrl = platform_get_drvdata(pdev);
pinctrl_unregister(pctrl->pctrl);
return 0;
}
static int __init zynq_pinctrl_init(void)
{
return platform_driver_register(&zynq_pinctrl_driver);
}
static void __exit zynq_pinctrl_exit(void)
{
platform_driver_unregister(&zynq_pinctrl_driver);
}
