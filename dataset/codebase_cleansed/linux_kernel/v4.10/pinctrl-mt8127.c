static int mt8127_spec_pull_set(struct regmap *regmap, unsigned int pin,
unsigned char align, bool isup, unsigned int r1r0)
{
return mtk_pctrl_spec_pull_set_samereg(regmap, mt8127_spec_pupd,
ARRAY_SIZE(mt8127_spec_pupd), pin, align, isup, r1r0);
}
static int mt8127_ies_smt_set(struct regmap *regmap, unsigned int pin,
unsigned char align, int value, enum pin_config_param arg)
{
if (arg == PIN_CONFIG_INPUT_ENABLE)
return mtk_pconf_spec_set_ies_smt_range(regmap, mt8127_ies_set,
ARRAY_SIZE(mt8127_ies_set), pin, align, value);
else if (arg == PIN_CONFIG_INPUT_SCHMITT_ENABLE)
return mtk_pconf_spec_set_ies_smt_range(regmap, mt8127_smt_set,
ARRAY_SIZE(mt8127_smt_set), pin, align, value);
return -EINVAL;
}
static int mt8127_pinctrl_probe(struct platform_device *pdev)
{
return mtk_pctrl_init(pdev, &mt8127_pinctrl_data, NULL);
}
static int __init mtk_pinctrl_init(void)
{
return platform_driver_register(&mtk_pinctrl_driver);
}
