static int mt2701_spec_pull_set(struct regmap *regmap, unsigned int pin,
unsigned char align, bool isup, unsigned int r1r0)
{
return mtk_pctrl_spec_pull_set_samereg(regmap, mt2701_spec_pupd,
ARRAY_SIZE(mt2701_spec_pupd), pin, align, isup, r1r0);
}
static int mt2701_ies_smt_set(struct regmap *regmap, unsigned int pin,
unsigned char align, int value, enum pin_config_param arg)
{
if (arg == PIN_CONFIG_INPUT_ENABLE)
return mtk_pconf_spec_set_ies_smt_range(regmap, mt2701_ies_set,
ARRAY_SIZE(mt2701_ies_set), pin, align, value);
else if (arg == PIN_CONFIG_INPUT_SCHMITT_ENABLE)
return mtk_pconf_spec_set_ies_smt_range(regmap, mt2701_smt_set,
ARRAY_SIZE(mt2701_smt_set), pin, align, value);
return -EINVAL;
}
static void mt2701_spec_pinmux_set(struct regmap *reg, unsigned int pin,
unsigned int mode)
{
unsigned int i, value, mask;
unsigned int info_num = ARRAY_SIZE(mt2701_spec_pinmux);
unsigned int spec_flag;
for (i = 0; i < info_num; i++) {
if (pin == mt2701_spec_pinmux[i].pin)
break;
}
if (i == info_num)
return;
spec_flag = (mode >> 3);
mask = BIT(mt2701_spec_pinmux[i].bit);
if (!spec_flag)
value = mask;
else
value = 0;
regmap_update_bits(reg, mt2701_spec_pinmux[i].offset, mask, value);
}
static void mt2701_spec_dir_set(unsigned int *reg_addr, unsigned int pin)
{
if (pin > 175)
*reg_addr += 0x10;
}
static int mt2701_pinctrl_probe(struct platform_device *pdev)
{
return mtk_pctrl_init(pdev, &mt2701_pinctrl_data, NULL);
}
static int __init mtk_pinctrl_init(void)
{
return platform_driver_register(&mtk_pinctrl_driver);
}
