static void __init at91_wakeup_status(struct platform_device *pdev)
{
struct shdwc *shdw = platform_get_drvdata(pdev);
u32 reg;
char *reason = "unknown";
reg = readl(shdw->at91_shdwc_base + AT91_SHDW_SR);
dev_dbg(&pdev->dev, "%s: status = %#x\n", __func__, reg);
if (!reg)
return;
if (SHDW_WK_PIN(reg, shdw->cfg))
reason = "WKUP pin";
else if (SHDW_RTCWK(reg, shdw->cfg))
reason = "RTC";
pr_info("AT91: Wake-Up source: %s\n", reason);
}
static void at91_poweroff(void)
{
writel(AT91_SHDW_KEY | AT91_SHDW_SHDW,
at91_shdwc->at91_shdwc_base + AT91_SHDW_CR);
}
static void at91_lpddr_poweroff(void)
{
asm volatile(
".balign 32\n\t"
" ldr r6, [%2, #" __stringify(AT91_SHDW_CR) "]\n\t"
" str %1, [%0, #" __stringify(AT91_DDRSDRC_LPR) "]\n\t"
" str %3, [%2, #" __stringify(AT91_SHDW_CR) "]\n\t"
" b .\n\t"
:
: "r" (mpddrc_base),
"r" cpu_to_le32(AT91_DDRSDRC_LPDDR2_PWOFF),
"r" (at91_shdwc->at91_shdwc_base),
"r" cpu_to_le32(AT91_SHDW_KEY | AT91_SHDW_SHDW)
: "r6");
}
static u32 at91_shdwc_debouncer_value(struct platform_device *pdev,
u32 in_period_us)
{
int i;
int max_idx = ARRAY_SIZE(sdwc_dbc_period) - 1;
unsigned long long period_us;
unsigned long long max_period_us = DBC_PERIOD_US(sdwc_dbc_period[max_idx]);
if (in_period_us > max_period_us) {
dev_warn(&pdev->dev,
"debouncer period %u too big, reduced to %llu us\n",
in_period_us, max_period_us);
return max_idx;
}
for (i = max_idx - 1; i > 0; i--) {
period_us = DBC_PERIOD_US(sdwc_dbc_period[i]);
dev_dbg(&pdev->dev, "%s: ref[%d] = %llu\n",
__func__, i, period_us);
if (in_period_us > period_us)
break;
}
return i + 1;
}
static u32 at91_shdwc_get_wakeup_input(struct platform_device *pdev,
struct device_node *np)
{
struct device_node *cnp;
u32 wk_input_mask;
u32 wuir = 0;
u32 wk_input;
for_each_child_of_node(np, cnp) {
if (of_property_read_u32(cnp, "reg", &wk_input)) {
dev_warn(&pdev->dev, "reg property is missing for %pOF\n",
cnp);
continue;
}
wk_input_mask = 1 << wk_input;
if (!(wk_input_mask & AT91_SHDW_WKUPEN_MASK)) {
dev_warn(&pdev->dev,
"wake-up input %d out of bounds ignore\n",
wk_input);
continue;
}
wuir |= wk_input_mask;
if (of_property_read_bool(cnp, "atmel,wakeup-active-high"))
wuir |= AT91_SHDW_WKUPT(wk_input);
dev_dbg(&pdev->dev, "%s: (child %d) wuir = %#x\n",
__func__, wk_input, wuir);
}
return wuir;
}
static void at91_shdwc_dt_configure(struct platform_device *pdev)
{
struct shdwc *shdw = platform_get_drvdata(pdev);
struct device_node *np = pdev->dev.of_node;
u32 mode = 0, tmp, input;
if (!np) {
dev_err(&pdev->dev, "device node not found\n");
return;
}
if (!of_property_read_u32(np, "debounce-delay-us", &tmp))
mode |= AT91_SHDW_WKUPDBC(at91_shdwc_debouncer_value(pdev, tmp));
if (of_property_read_bool(np, "atmel,wakeup-rtc-timer"))
mode |= SHDW_RTCWKEN(shdw->cfg);
dev_dbg(&pdev->dev, "%s: mode = %#x\n", __func__, mode);
writel(mode, shdw->at91_shdwc_base + AT91_SHDW_MR);
input = at91_shdwc_get_wakeup_input(pdev, np);
writel(input, shdw->at91_shdwc_base + AT91_SHDW_WUIR);
}
static int __init at91_shdwc_probe(struct platform_device *pdev)
{
struct resource *res;
const struct of_device_id *match;
struct device_node *np;
u32 ddr_type;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
at91_shdwc = devm_kzalloc(&pdev->dev, sizeof(*at91_shdwc), GFP_KERNEL);
if (!at91_shdwc)
return -ENOMEM;
platform_set_drvdata(pdev, at91_shdwc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
at91_shdwc->at91_shdwc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(at91_shdwc->at91_shdwc_base)) {
dev_err(&pdev->dev, "Could not map reset controller address\n");
return PTR_ERR(at91_shdwc->at91_shdwc_base);
}
match = of_match_node(at91_shdwc_of_match, pdev->dev.of_node);
at91_shdwc->cfg = (struct shdwc_config *)(match->data);
sclk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sclk))
return PTR_ERR(sclk);
ret = clk_prepare_enable(sclk);
if (ret) {
dev_err(&pdev->dev, "Could not enable slow clock\n");
return ret;
}
at91_wakeup_status(pdev);
at91_shdwc_dt_configure(pdev);
pm_power_off = at91_poweroff;
np = of_find_compatible_node(NULL, NULL, "atmel,sama5d3-ddramc");
if (!np)
return 0;
mpddrc_base = of_iomap(np, 0);
of_node_put(np);
if (!mpddrc_base)
return 0;
ddr_type = readl(mpddrc_base + AT91_DDRSDRC_MDR) & AT91_DDRSDRC_MD;
if ((ddr_type == AT91_DDRSDRC_MD_LPDDR2) ||
(ddr_type == AT91_DDRSDRC_MD_LPDDR3))
pm_power_off = at91_lpddr_poweroff;
else
iounmap(mpddrc_base);
return 0;
}
static int __exit at91_shdwc_remove(struct platform_device *pdev)
{
struct shdwc *shdw = platform_get_drvdata(pdev);
if (pm_power_off == at91_poweroff ||
pm_power_off == at91_lpddr_poweroff)
pm_power_off = NULL;
writel(0, shdw->at91_shdwc_base + AT91_SHDW_MR);
writel(0, shdw->at91_shdwc_base + AT91_SHDW_WUIR);
clk_disable_unprepare(sclk);
return 0;
}
