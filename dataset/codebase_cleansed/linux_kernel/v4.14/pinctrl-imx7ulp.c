static void imx7ulp_cfg_params_fixup(unsigned long *configs,
unsigned int num_configs,
u32 *raw_config)
{
enum pin_config_param param;
u32 param_val;
int i;
*raw_config &= ~BM_LK_ENABLED;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
param_val = pinconf_to_config_argument(configs[i]);
if ((param == PIN_CONFIG_BIAS_PULL_UP) ||
(param == PIN_CONFIG_BIAS_PULL_DOWN)) {
*raw_config |= BM_PULL_ENABLED;
return;
}
}
}
static int imx7ulp_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset, bool input)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
u32 reg;
pin_reg = &info->pin_regs[offset];
if (pin_reg->mux_reg == -1)
return -EINVAL;
reg = readl(ipctl->base + pin_reg->mux_reg);
if (input)
reg = (reg & ~BM_OBE_ENABLED) | BM_IBE_ENABLED;
else
reg = (reg & ~BM_IBE_ENABLED) | BM_OBE_ENABLED;
writel(reg, ipctl->base + pin_reg->mux_reg);
return 0;
}
static int imx7ulp_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx7ulp_pinctrl_info);
}
static int __init imx7ulp_pinctrl_init(void)
{
return platform_driver_register(&imx7ulp_pinctrl_driver);
}
