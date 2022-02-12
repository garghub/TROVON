static int exynos_audss_clk_suspend(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(reg_save); i++)
reg_save[i][1] = readl(reg_base + reg_save[i][0]);
return 0;
}
static void exynos_audss_clk_resume(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(reg_save); i++)
writel(reg_save[i][1], reg_base + reg_save[i][0]);
}
void __init exynos_audss_clk_init(struct device_node *np)
{
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: failed to map audss registers\n", __func__);
return;
}
clk_table = kzalloc(sizeof(struct clk *) * EXYNOS_AUDSS_MAX_CLKS,
GFP_KERNEL);
if (!clk_table) {
pr_err("%s: could not allocate clk lookup table\n", __func__);
return;
}
clk_data.clks = clk_table;
clk_data.clk_num = EXYNOS_AUDSS_MAX_CLKS;
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
clk_table[EXYNOS_MOUT_AUDSS] = clk_register_mux(NULL, "mout_audss",
mout_audss_p, ARRAY_SIZE(mout_audss_p), 0,
reg_base + ASS_CLK_SRC, 0, 1, 0, &lock);
clk_table[EXYNOS_MOUT_I2S] = clk_register_mux(NULL, "mout_i2s",
mout_i2s_p, ARRAY_SIZE(mout_i2s_p), 0,
reg_base + ASS_CLK_SRC, 2, 2, 0, &lock);
clk_table[EXYNOS_DOUT_SRP] = clk_register_divider(NULL, "dout_srp",
"mout_audss", 0, reg_base + ASS_CLK_DIV, 0, 4,
0, &lock);
clk_table[EXYNOS_DOUT_AUD_BUS] = clk_register_divider(NULL,
"dout_aud_bus", "dout_srp", 0,
reg_base + ASS_CLK_DIV, 4, 4, 0, &lock);
clk_table[EXYNOS_DOUT_I2S] = clk_register_divider(NULL, "dout_i2s",
"mout_i2s", 0, reg_base + ASS_CLK_DIV, 8, 4, 0,
&lock);
clk_table[EXYNOS_SRP_CLK] = clk_register_gate(NULL, "srp_clk",
"dout_srp", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 0, 0, &lock);
clk_table[EXYNOS_I2S_BUS] = clk_register_gate(NULL, "i2s_bus",
"dout_aud_bus", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 2, 0, &lock);
clk_table[EXYNOS_SCLK_I2S] = clk_register_gate(NULL, "sclk_i2s",
"dout_i2s", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 3, 0, &lock);
clk_table[EXYNOS_PCM_BUS] = clk_register_gate(NULL, "pcm_bus",
"sclk_pcm", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 4, 0, &lock);
clk_table[EXYNOS_SCLK_PCM] = clk_register_gate(NULL, "sclk_pcm",
"div_pcm0", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 5, 0, &lock);
#ifdef CONFIG_PM_SLEEP
register_syscore_ops(&exynos_audss_clk_syscore_ops);
#endif
pr_info("Exynos: Audss: clock setup completed\n");
}
