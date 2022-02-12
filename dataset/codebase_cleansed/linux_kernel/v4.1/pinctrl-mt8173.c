static int spec_pull_set(struct regmap *regmap, unsigned int pin,
unsigned char align, bool isup, unsigned int r1r0)
{
unsigned int i;
unsigned int reg_pupd, reg_set, reg_rst;
unsigned int bit_pupd, bit_r0, bit_r1;
const struct mtk_pin_spec_pupd_set *spec_pupd_pin;
bool find = false;
for (i = 0; i < ARRAY_SIZE(mt8173_spec_pupd); i++) {
if (pin == mt8173_spec_pupd[i].pin) {
find = true;
break;
}
}
if (!find)
return -EINVAL;
spec_pupd_pin = mt8173_spec_pupd + i;
reg_set = spec_pupd_pin->offset + align;
reg_rst = spec_pupd_pin->offset + (align << 1);
if (isup)
reg_pupd = reg_rst;
else
reg_pupd = reg_set;
bit_pupd = BIT(spec_pupd_pin->pupd_bit);
regmap_write(regmap, reg_pupd, bit_pupd);
bit_r0 = BIT(spec_pupd_pin->r0_bit);
bit_r1 = BIT(spec_pupd_pin->r1_bit);
switch (r1r0) {
case MTK_PUPD_SET_R1R0_00:
regmap_write(regmap, reg_rst, bit_r0);
regmap_write(regmap, reg_rst, bit_r1);
break;
case MTK_PUPD_SET_R1R0_01:
regmap_write(regmap, reg_set, bit_r0);
regmap_write(regmap, reg_rst, bit_r1);
break;
case MTK_PUPD_SET_R1R0_10:
regmap_write(regmap, reg_rst, bit_r0);
regmap_write(regmap, reg_set, bit_r1);
break;
case MTK_PUPD_SET_R1R0_11:
regmap_write(regmap, reg_set, bit_r0);
regmap_write(regmap, reg_set, bit_r1);
break;
default:
return -EINVAL;
}
return 0;
}
static int spec_ies_smt_set(struct regmap *regmap, unsigned int pin,
unsigned char align, int value)
{
unsigned int i, reg_addr, bit;
bool find = false;
for (i = 0; i < ARRAY_SIZE(mt8173_ies_smt_set); i++) {
if (pin >= mt8173_ies_smt_set[i].start &&
pin <= mt8173_ies_smt_set[i].end) {
find = true;
break;
}
}
if (!find)
return -EINVAL;
if (value)
reg_addr = mt8173_ies_smt_set[i].offset + align;
else
reg_addr = mt8173_ies_smt_set[i].offset + (align << 1);
bit = BIT(mt8173_ies_smt_set[i].bit);
regmap_write(regmap, reg_addr, bit);
return 0;
}
static int mt8173_pinctrl_probe(struct platform_device *pdev)
{
return mtk_pctrl_init(pdev, &mt8173_pinctrl_data);
}
static int __init mtk_pinctrl_init(void)
{
return platform_driver_register(&mtk_pinctrl_driver);
}
