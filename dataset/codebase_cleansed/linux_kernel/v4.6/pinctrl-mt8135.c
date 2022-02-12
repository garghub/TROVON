static int spec_pull_set(struct regmap *regmap, unsigned int pin,
unsigned char align, bool isup, unsigned int r1r0)
{
unsigned int i;
unsigned int reg_pupd, reg_set_r0, reg_set_r1;
unsigned int reg_rst_r0, reg_rst_r1;
bool find = false;
for (i = 0; i < ARRAY_SIZE(spec_pupd); i++) {
if (pin == spec_pupd[i].pin) {
find = true;
break;
}
}
if (!find)
return -EINVAL;
if (isup)
reg_pupd = spec_pupd[i].pupd_offset + align;
else
reg_pupd = spec_pupd[i].pupd_offset + (align << 1);
regmap_write(regmap, reg_pupd, spec_pupd[i].pupd_bit);
reg_set_r0 = spec_pupd[i].r0_offset + align;
reg_rst_r0 = spec_pupd[i].r0_offset + (align << 1);
reg_set_r1 = spec_pupd[i].r1_offset + align;
reg_rst_r1 = spec_pupd[i].r1_offset + (align << 1);
switch (r1r0) {
case MTK_PUPD_SET_R1R0_00:
regmap_write(regmap, reg_rst_r0, spec_pupd[i].r0_bit);
regmap_write(regmap, reg_rst_r1, spec_pupd[i].r1_bit);
break;
case MTK_PUPD_SET_R1R0_01:
regmap_write(regmap, reg_set_r0, spec_pupd[i].r0_bit);
regmap_write(regmap, reg_rst_r1, spec_pupd[i].r1_bit);
break;
case MTK_PUPD_SET_R1R0_10:
regmap_write(regmap, reg_rst_r0, spec_pupd[i].r0_bit);
regmap_write(regmap, reg_set_r1, spec_pupd[i].r1_bit);
break;
case MTK_PUPD_SET_R1R0_11:
regmap_write(regmap, reg_set_r0, spec_pupd[i].r0_bit);
regmap_write(regmap, reg_set_r1, spec_pupd[i].r1_bit);
break;
default:
return -EINVAL;
}
return 0;
}
static int mt8135_pinctrl_probe(struct platform_device *pdev)
{
return mtk_pctrl_init(pdev, &mt8135_pinctrl_data, NULL);
}
static int __init mtk_pinctrl_init(void)
{
return platform_driver_register(&mtk_pinctrl_driver);
}
