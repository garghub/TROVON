static unsigned long aoclk_cec_32k_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct aoclk_cec_32k *cec_32k = to_aoclk_cec_32k(hw);
unsigned long n1;
u32 reg0, reg1;
regmap_read(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0, &reg0);
regmap_read(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL1, &reg1);
if (reg1 & CLK_CNTL1_BYPASS_EN)
return parent_rate;
if (reg0 & CLK_CNTL0_DUALDIV_EN) {
unsigned long n2, m1, m2, f1, f2, p1, p2;
n1 = FIELD_GET(CLK_CNTL0_N1_MASK, reg0) + 1;
n2 = FIELD_GET(CLK_CNTL0_N2_MASK, reg0) + 1;
m1 = FIELD_GET(CLK_CNTL1_M1_MASK, reg1) + 1;
m2 = FIELD_GET(CLK_CNTL1_M2_MASK, reg1) + 1;
f1 = DIV_ROUND_CLOSEST(parent_rate, n1);
f2 = DIV_ROUND_CLOSEST(parent_rate, n2);
p1 = DIV_ROUND_CLOSEST(100000000 * m1, f1 * (m1 + m2));
p2 = DIV_ROUND_CLOSEST(100000000 * m2, f2 * (m1 + m2));
return DIV_ROUND_UP(100000000, p1 + p2);
}
n1 = FIELD_GET(CLK_CNTL0_N1_MASK, reg0) + 1;
return DIV_ROUND_CLOSEST(parent_rate, n1);
}
static const struct cec_32k_freq_table *find_cec_32k_freq(unsigned long rate,
unsigned long prate)
{
int i;
for (i = 0 ; i < ARRAY_SIZE(aoclk_cec_32k_table) ; ++i)
if (aoclk_cec_32k_table[i].parent_rate == prate &&
aoclk_cec_32k_table[i].target_rate == rate)
return &aoclk_cec_32k_table[i];
return NULL;
}
static long aoclk_cec_32k_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
const struct cec_32k_freq_table *freq = find_cec_32k_freq(rate,
*prate);
if (!freq)
return aoclk_cec_32k_table[0].target_rate;
return freq->target_rate;
}
static int aoclk_cec_32k_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
const struct cec_32k_freq_table *freq = find_cec_32k_freq(rate,
parent_rate);
struct aoclk_cec_32k *cec_32k = to_aoclk_cec_32k(hw);
u32 reg = 0;
if (!freq)
return -EINVAL;
regmap_update_bits(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0,
CLK_CNTL0_IN_GATE_EN | CLK_CNTL0_OUT_GATE_EN, 0);
reg = FIELD_PREP(CLK_CNTL0_N1_MASK, freq->n1 - 1);
if (freq->dualdiv)
reg |= CLK_CNTL0_DUALDIV_EN |
FIELD_PREP(CLK_CNTL0_N2_MASK, freq->n2 - 1);
regmap_write(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0, reg);
reg = FIELD_PREP(CLK_CNTL1_M1_MASK, freq->m1 - 1);
if (freq->dualdiv)
reg |= FIELD_PREP(CLK_CNTL1_M2_MASK, freq->m2 - 1);
regmap_write(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL1, reg);
regmap_update_bits(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0,
CLK_CNTL0_IN_GATE_EN, CLK_CNTL0_IN_GATE_EN);
udelay(200);
regmap_update_bits(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0,
CLK_CNTL0_OUT_GATE_EN, CLK_CNTL0_OUT_GATE_EN);
regmap_update_bits(cec_32k->regmap, AO_CRT_CLK_CNTL1,
CLK_CNTL1_SELECT_OSC, CLK_CNTL1_SELECT_OSC);
regmap_update_bits(cec_32k->regmap,
AO_RTI_PWR_CNTL_REG0,
PWR_CNTL_ALT_32K_SEL,
FIELD_PREP(PWR_CNTL_ALT_32K_SEL, 4));
return 0;
}
