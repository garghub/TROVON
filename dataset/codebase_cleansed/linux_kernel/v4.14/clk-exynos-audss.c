static int exynos_audss_clk_suspend(struct device *dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(reg_save); i++)
reg_save[i][1] = readl(reg_base + reg_save[i][0]);
return 0;
}
static int exynos_audss_clk_resume(struct device *dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(reg_save); i++)
writel(reg_save[i][1], reg_base + reg_save[i][0]);
return 0;
}
static void exynos_audss_clk_teardown(void)
{
int i;
for (i = EXYNOS_MOUT_AUDSS; i < EXYNOS_DOUT_SRP; i++) {
if (!IS_ERR(clk_data->hws[i]))
clk_hw_unregister_mux(clk_data->hws[i]);
}
for (; i < EXYNOS_SRP_CLK; i++) {
if (!IS_ERR(clk_data->hws[i]))
clk_hw_unregister_divider(clk_data->hws[i]);
}
for (; i < clk_data->num; i++) {
if (!IS_ERR(clk_data->hws[i]))
clk_hw_unregister_gate(clk_data->hws[i]);
}
}
static int exynos_audss_clk_probe(struct platform_device *pdev)
{
const char *mout_audss_p[] = {"fin_pll", "fout_epll"};
const char *mout_i2s_p[] = {"mout_audss", "cdclk0", "sclk_audio0"};
const char *sclk_pcm_p = "sclk_pcm0";
struct clk *pll_ref, *pll_in, *cdclk, *sclk_audio, *sclk_pcm_in;
const struct exynos_audss_clk_drvdata *variant;
struct clk_hw **clk_table;
struct resource *res;
int i, ret = 0;
variant = of_device_get_match_data(&pdev->dev);
if (!variant)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(reg_base)) {
dev_err(&pdev->dev, "failed to map audss registers\n");
return PTR_ERR(reg_base);
}
epll = ERR_PTR(-ENODEV);
clk_data = devm_kzalloc(&pdev->dev,
sizeof(*clk_data) +
sizeof(*clk_data->hws) * EXYNOS_AUDSS_MAX_CLKS,
GFP_KERNEL);
if (!clk_data)
return -ENOMEM;
clk_data->num = variant->num_clks;
clk_table = clk_data->hws;
pll_ref = devm_clk_get(&pdev->dev, "pll_ref");
pll_in = devm_clk_get(&pdev->dev, "pll_in");
if (!IS_ERR(pll_ref))
mout_audss_p[0] = __clk_get_name(pll_ref);
if (!IS_ERR(pll_in)) {
mout_audss_p[1] = __clk_get_name(pll_in);
if (variant->enable_epll) {
epll = pll_in;
ret = clk_prepare_enable(epll);
if (ret) {
dev_err(&pdev->dev,
"failed to prepare the epll clock\n");
return ret;
}
}
}
clk_table[EXYNOS_MOUT_AUDSS] = clk_hw_register_mux(NULL, "mout_audss",
mout_audss_p, ARRAY_SIZE(mout_audss_p),
CLK_SET_RATE_NO_REPARENT | CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_SRC, 0, 1, 0, &lock);
cdclk = devm_clk_get(&pdev->dev, "cdclk");
sclk_audio = devm_clk_get(&pdev->dev, "sclk_audio");
if (!IS_ERR(cdclk))
mout_i2s_p[1] = __clk_get_name(cdclk);
if (!IS_ERR(sclk_audio))
mout_i2s_p[2] = __clk_get_name(sclk_audio);
clk_table[EXYNOS_MOUT_I2S] = clk_hw_register_mux(NULL, "mout_i2s",
mout_i2s_p, ARRAY_SIZE(mout_i2s_p),
CLK_SET_RATE_NO_REPARENT,
reg_base + ASS_CLK_SRC, 2, 2, 0, &lock);
clk_table[EXYNOS_DOUT_SRP] = clk_hw_register_divider(NULL, "dout_srp",
"mout_audss", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_DIV, 0, 4, 0, &lock);
clk_table[EXYNOS_DOUT_AUD_BUS] = clk_hw_register_divider(NULL,
"dout_aud_bus", "dout_srp", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_DIV, 4, 4, 0, &lock);
clk_table[EXYNOS_DOUT_I2S] = clk_hw_register_divider(NULL, "dout_i2s",
"mout_i2s", 0, reg_base + ASS_CLK_DIV, 8, 4, 0,
&lock);
clk_table[EXYNOS_SRP_CLK] = clk_hw_register_gate(NULL, "srp_clk",
"dout_srp", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 0, 0, &lock);
clk_table[EXYNOS_I2S_BUS] = clk_hw_register_gate(NULL, "i2s_bus",
"dout_aud_bus", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 2, 0, &lock);
clk_table[EXYNOS_SCLK_I2S] = clk_hw_register_gate(NULL, "sclk_i2s",
"dout_i2s", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 3, 0, &lock);
clk_table[EXYNOS_PCM_BUS] = clk_hw_register_gate(NULL, "pcm_bus",
"sclk_pcm", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 4, 0, &lock);
sclk_pcm_in = devm_clk_get(&pdev->dev, "sclk_pcm_in");
if (!IS_ERR(sclk_pcm_in))
sclk_pcm_p = __clk_get_name(sclk_pcm_in);
clk_table[EXYNOS_SCLK_PCM] = clk_hw_register_gate(NULL, "sclk_pcm",
sclk_pcm_p, CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 5, 0, &lock);
if (variant->has_adma_clk) {
clk_table[EXYNOS_ADMA] = clk_hw_register_gate(NULL, "adma",
"dout_srp", CLK_SET_RATE_PARENT,
reg_base + ASS_CLK_GATE, 9, 0, &lock);
}
for (i = 0; i < clk_data->num; i++) {
if (IS_ERR(clk_table[i])) {
dev_err(&pdev->dev, "failed to register clock %d\n", i);
ret = PTR_ERR(clk_table[i]);
goto unregister;
}
}
ret = of_clk_add_hw_provider(pdev->dev.of_node, of_clk_hw_onecell_get,
clk_data);
if (ret) {
dev_err(&pdev->dev, "failed to add clock provider\n");
goto unregister;
}
return 0;
unregister:
exynos_audss_clk_teardown();
if (!IS_ERR(epll))
clk_disable_unprepare(epll);
return ret;
}
static int exynos_audss_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
exynos_audss_clk_teardown();
if (!IS_ERR(epll))
clk_disable_unprepare(epll);
return 0;
}
