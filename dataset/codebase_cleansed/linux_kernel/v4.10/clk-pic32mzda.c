static int pic32_fscm_nmi(struct notifier_block *nb,
unsigned long action, void *data)
{
struct pic32mzda_clk_data *cd;
cd = container_of(nb, struct pic32mzda_clk_data, failsafe_notifier);
if (readl(cd->core.iobase) & BIT(2))
pr_alert("pic32-clk: FSCM detected clk failure.\n");
return NOTIFY_OK;
}
static int pic32mzda_clk_probe(struct platform_device *pdev)
{
const char *const pll_mux_parents[] = {"posc_clk", "frc_clk"};
struct device_node *np = pdev->dev.of_node;
struct pic32mzda_clk_data *cd;
struct pic32_clk_common *core;
struct clk *pll_mux_clk, *clk;
struct clk **clks;
int nr_clks, i, ret;
cd = devm_kzalloc(&pdev->dev, sizeof(*cd), GFP_KERNEL);
if (!cd)
return -ENOMEM;
core = &cd->core;
core->iobase = of_io_request_and_map(np, 0, of_node_full_name(np));
if (IS_ERR(core->iobase)) {
dev_err(&pdev->dev, "pic32-clk: failed to map registers\n");
return PTR_ERR(core->iobase);
}
spin_lock_init(&core->reg_lock);
core->dev = &pdev->dev;
clks = &cd->clks[0];
clks[POSCCLK] = clk_register_fixed_rate(&pdev->dev, "posc_clk", NULL,
0, 24000000);
clks[FRCCLK] = clk_register_fixed_rate(&pdev->dev, "frc_clk", NULL,
0, 8000000);
clks[BFRCCLK] = clk_register_fixed_rate(&pdev->dev, "bfrc_clk", NULL,
0, 8000000);
clks[LPRCCLK] = clk_register_fixed_rate(&pdev->dev, "lprc_clk", NULL,
0, 32000);
clks[UPLLCLK] = clk_register_fixed_rate(&pdev->dev, "usbphy_clk", NULL,
0, 24000000);
if (of_find_property(np, "microchip,pic32mzda-sosc", NULL)) {
pr_info("pic32-clk: dt requests SOSC.\n");
clks[SOSCCLK] = pic32_sosc_clk_register(&sosc_clk, core);
}
clks[FRCDIVCLK] = clk_register_divider(&pdev->dev, "frcdiv_clk",
"frc_clk", 0,
core->iobase,
OSC_FRCDIV_SHIFT,
OSC_FRCDIV_MASK,
CLK_DIVIDER_POWER_OF_TWO,
&core->reg_lock);
pll_mux_clk = clk_register_mux(&pdev->dev, "spll_mux_clk",
pll_mux_parents, 2, 0,
core->iobase + 0x020,
PLL_ICLK_SHIFT, 1, 0, &core->reg_lock);
if (IS_ERR(pll_mux_clk))
pr_err("spll_mux_clk: clk register failed\n");
clks[PLLCLK] = pic32_spll_clk_register(&sys_pll, core);
clks[SCLK] = pic32_sys_clk_register(&sys_mux_clk, core);
for (nr_clks = PB1CLK, i = 0; nr_clks <= PB7CLK; i++, nr_clks++)
clks[nr_clks] = pic32_periph_clk_register(&periph_clocks[i],
core);
for (nr_clks = REF1CLK, i = 0; nr_clks <= REF5CLK; i++, nr_clks++)
clks[nr_clks] = pic32_refo_clk_register(&ref_clks[i], core);
for (i = 0; i < MAXCLKS; i++) {
if (IS_ERR(clks[i]))
continue;
clk_register_clkdev(clks[i], NULL, __clk_get_name(clks[i]));
}
cd->onecell_data.clks = clks;
cd->onecell_data.clk_num = MAXCLKS;
ret = of_clk_add_provider(np, of_clk_src_onecell_get,
&cd->onecell_data);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(pic32mzda_critical_clks); i++) {
clk = clks[pic32mzda_critical_clks[i]];
if (clk_prepare_enable(clk))
dev_err(&pdev->dev, "clk_prepare_enable(%s) failed\n",
__clk_get_name(clk));
}
cd->failsafe_notifier.notifier_call = pic32_fscm_nmi;
return register_nmi_notifier(&cd->failsafe_notifier);
}
static int __init microchip_pic32mzda_clk_init(void)
{
return platform_driver_register(&pic32mzda_clk_driver);
}
