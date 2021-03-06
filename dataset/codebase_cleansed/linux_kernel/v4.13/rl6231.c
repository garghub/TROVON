int rl6231_get_pre_div(struct regmap *map, unsigned int reg, int sft)
{
int pd, val;
regmap_read(map, reg, &val);
val = (val >> sft) & 0x7;
switch (val) {
case 0:
case 1:
case 2:
case 3:
pd = val + 1;
break;
case 4:
pd = 6;
break;
case 5:
pd = 8;
break;
case 6:
pd = 12;
break;
case 7:
pd = 16;
break;
default:
pd = -EINVAL;
break;
}
return pd;
}
int rl6231_calc_dmic_clk(int rate)
{
int div[] = {2, 3, 4, 6, 8, 12};
int i;
if (rate < 1000000 * div[0]) {
pr_warn("Base clock rate %d is too low\n", rate);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(div); i++) {
if ((div[i] % 3) == 0)
continue;
if (3072000 * div[i] >= rate)
return i;
}
pr_warn("Base clock rate %d is too high\n", rate);
return -EINVAL;
}
int rl6231_pll_calc(const unsigned int freq_in,
const unsigned int freq_out, struct rl6231_pll_code *pll_code)
{
int max_n = RL6231_PLL_N_MAX, max_m = RL6231_PLL_M_MAX;
int i, k, red, n_t, pll_out, in_t, out_t;
int n = 0, m = 0, m_t = 0;
int red_t = abs(freq_out - freq_in);
bool bypass = false;
if (RL6231_PLL_INP_MAX < freq_in || RL6231_PLL_INP_MIN > freq_in)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(pll_preset_table); i++) {
if (freq_in == pll_preset_table[i].pll_in &&
freq_out == pll_preset_table[i].pll_out) {
k = pll_preset_table[i].k;
m = pll_preset_table[i].m;
n = pll_preset_table[i].n;
bypass = pll_preset_table[i].m_bp;
pr_debug("Use preset PLL parameter table\n");
goto code_find;
}
}
k = 100000000 / freq_out - 2;
if (k > RL6231_PLL_K_MAX)
k = RL6231_PLL_K_MAX;
for (n_t = 0; n_t <= max_n; n_t++) {
in_t = freq_in / (k + 2);
pll_out = freq_out / (n_t + 2);
if (in_t < 0)
continue;
if (in_t == pll_out) {
bypass = true;
n = n_t;
goto code_find;
}
red = abs(in_t - pll_out);
if (red < red_t) {
bypass = true;
n = n_t;
m = m_t;
if (red == 0)
goto code_find;
red_t = red;
}
for (m_t = 0; m_t <= max_m; m_t++) {
out_t = in_t / (m_t + 2);
red = abs(out_t - pll_out);
if (red < red_t) {
bypass = false;
n = n_t;
m = m_t;
if (red == 0)
goto code_find;
red_t = red;
}
}
}
pr_debug("Only get approximation about PLL\n");
code_find:
pll_code->m_bp = bypass;
pll_code->m_code = m;
pll_code->n_code = n;
pll_code->k_code = k;
return 0;
}
int rl6231_get_clk_info(int sclk, int rate)
{
int i, pd[] = {1, 2, 3, 4, 6, 8, 12, 16};
if (sclk <= 0 || rate <= 0)
return -EINVAL;
rate = rate << 8;
for (i = 0; i < ARRAY_SIZE(pd); i++)
if (sclk == rate * pd[i])
return i;
return -EINVAL;
}
