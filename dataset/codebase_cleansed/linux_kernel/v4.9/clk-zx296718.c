static int __init top_clocks_init(struct device_node *np)
{
void __iomem *reg_base;
int i, ret;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return -ENXIO;
}
for (i = 0; i < ARRAY_SIZE(zx296718_pll_clk); i++) {
zx296718_pll_clk[i].reg_base += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &zx296718_pll_clk[i].hw);
if (ret) {
pr_warn("top clk %s init error!\n",
zx296718_pll_clk[i].hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(top_ffactor_clk); i++) {
if (top_ffactor_clk[i].id)
top_hw_onecell_data.hws[top_ffactor_clk[i].id] =
&top_ffactor_clk[i].factor.hw;
ret = clk_hw_register(NULL, &top_ffactor_clk[i].factor.hw);
if (ret) {
pr_warn("top clk %s init error!\n",
top_ffactor_clk[i].factor.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(top_mux_clk); i++) {
if (top_mux_clk[i].id)
top_hw_onecell_data.hws[top_mux_clk[i].id] =
&top_mux_clk[i].mux.hw;
top_mux_clk[i].mux.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &top_mux_clk[i].mux.hw);
if (ret) {
pr_warn("top clk %s init error!\n",
top_mux_clk[i].mux.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(top_gate_clk); i++) {
if (top_gate_clk[i].id)
top_hw_onecell_data.hws[top_gate_clk[i].id] =
&top_gate_clk[i].gate.hw;
top_gate_clk[i].gate.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &top_gate_clk[i].gate.hw);
if (ret) {
pr_warn("top clk %s init error!\n",
top_gate_clk[i].gate.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(top_div_clk); i++) {
if (top_div_clk[i].id)
top_hw_onecell_data.hws[top_div_clk[i].id] =
&top_div_clk[i].div.hw;
top_div_clk[i].div.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &top_div_clk[i].div.hw);
if (ret) {
pr_warn("top clk %s init error!\n",
top_div_clk[i].div.hw.init->name);
}
}
if (of_clk_add_hw_provider(np, of_clk_hw_onecell_get, &top_hw_onecell_data))
panic("could not register clk provider\n");
pr_info("top clk init over, nr:%d\n", TOP_NR_CLKS);
return 0;
}
static int __init lsp0_clocks_init(struct device_node *np)
{
void __iomem *reg_base;
int i, ret;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return -ENXIO;
}
for (i = 0; i < ARRAY_SIZE(lsp0_mux_clk); i++) {
if (lsp0_mux_clk[i].id)
lsp0_hw_onecell_data.hws[lsp0_mux_clk[i].id] =
&lsp0_mux_clk[i].mux.hw;
lsp0_mux_clk[i].mux.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &lsp0_mux_clk[i].mux.hw);
if (ret) {
pr_warn("lsp0 clk %s init error!\n",
lsp0_mux_clk[i].mux.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(lsp0_gate_clk); i++) {
if (lsp0_gate_clk[i].id)
lsp0_hw_onecell_data.hws[lsp0_gate_clk[i].id] =
&lsp0_gate_clk[i].gate.hw;
lsp0_gate_clk[i].gate.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &lsp0_gate_clk[i].gate.hw);
if (ret) {
pr_warn("lsp0 clk %s init error!\n",
lsp0_gate_clk[i].gate.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(lsp0_div_clk); i++) {
if (lsp0_div_clk[i].id)
lsp0_hw_onecell_data.hws[lsp0_div_clk[i].id] =
&lsp0_div_clk[i].div.hw;
lsp0_div_clk[i].div.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &lsp0_div_clk[i].div.hw);
if (ret) {
pr_warn("lsp0 clk %s init error!\n",
lsp0_div_clk[i].div.hw.init->name);
}
}
if (of_clk_add_hw_provider(np, of_clk_hw_onecell_get, &lsp0_hw_onecell_data))
panic("could not register clk provider\n");
pr_info("lsp0-clk init over:%d\n", LSP0_NR_CLKS);
return 0;
}
static int __init lsp1_clocks_init(struct device_node *np)
{
void __iomem *reg_base;
int i, ret;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return -ENXIO;
}
for (i = 0; i < ARRAY_SIZE(lsp1_mux_clk); i++) {
if (lsp1_mux_clk[i].id)
lsp1_hw_onecell_data.hws[lsp1_mux_clk[i].id] =
&lsp0_mux_clk[i].mux.hw;
lsp1_mux_clk[i].mux.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &lsp1_mux_clk[i].mux.hw);
if (ret) {
pr_warn("lsp1 clk %s init error!\n",
lsp1_mux_clk[i].mux.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(lsp1_gate_clk); i++) {
if (lsp1_gate_clk[i].id)
lsp1_hw_onecell_data.hws[lsp1_gate_clk[i].id] =
&lsp1_gate_clk[i].gate.hw;
lsp1_gate_clk[i].gate.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &lsp1_gate_clk[i].gate.hw);
if (ret) {
pr_warn("lsp1 clk %s init error!\n",
lsp1_gate_clk[i].gate.hw.init->name);
}
}
for (i = 0; i < ARRAY_SIZE(lsp1_div_clk); i++) {
if (lsp1_div_clk[i].id)
lsp1_hw_onecell_data.hws[lsp1_div_clk[i].id] =
&lsp1_div_clk[i].div.hw;
lsp1_div_clk[i].div.reg += (uintptr_t)reg_base;
ret = clk_hw_register(NULL, &lsp1_div_clk[i].div.hw);
if (ret) {
pr_warn("lsp1 clk %s init error!\n",
lsp1_div_clk[i].div.hw.init->name);
}
}
if (of_clk_add_hw_provider(np, of_clk_hw_onecell_get, &lsp1_hw_onecell_data))
panic("could not register clk provider\n");
pr_info("lsp1-clk init over, nr:%d\n", LSP1_NR_CLKS);
return 0;
}
static int zx_clkc_probe(struct platform_device *pdev)
{
int (*init_fn)(struct device_node *np);
struct device_node *np = pdev->dev.of_node;
init_fn = of_device_get_match_data(&pdev->dev);
if (!init_fn) {
dev_err(&pdev->dev, "Error: No device match found\n");
return -ENODEV;
}
return init_fn(np);
}
static int __init zx_clk_init(void)
{
return platform_driver_register(&zx_clk_driver);
}
