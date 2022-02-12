int rl6231_calc_dmic_clk(int rate)
{
int div[] = {2, 3, 4, 6, 8, 12}, idx = -EINVAL;
int i, red, bound, temp;
red = 3000000 * 12;
for (i = 0; i < ARRAY_SIZE(div); i++) {
bound = div[i] * 3000000;
if (rate > bound)
continue;
temp = bound - rate;
if (temp < red) {
red = temp;
idx = i;
}
}
return idx;
}
int rl6231_pll_calc(const unsigned int freq_in,
const unsigned int freq_out, struct rl6231_pll_code *pll_code)
{
int max_n = RL6231_PLL_N_MAX, max_m = RL6231_PLL_M_MAX;
int k, red, n_t, pll_out, in_t, out_t;
int n = 0, m = 0, m_t = 0;
int red_t = abs(freq_out - freq_in);
bool bypass = false;
if (RL6231_PLL_INP_MAX < freq_in || RL6231_PLL_INP_MIN > freq_in)
return -EINVAL;
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
