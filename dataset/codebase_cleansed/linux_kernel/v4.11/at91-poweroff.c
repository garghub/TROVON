static void __init at91_wakeup_status(void)
{
u32 reg = readl(at91_shdwc_base + AT91_SHDW_SR);
char *reason = "unknown";
if (!reg)
return;
if (reg & AT91_SHDW_RTTWK)
reason = "RTT";
else if (reg & AT91_SHDW_RTCWK)
reason = "RTC";
pr_info("AT91: Wake-Up source: %s\n", reason);
}
static void at91_poweroff(void)
{
writel(AT91_SHDW_KEY | AT91_SHDW_SHDW, at91_shdwc_base + AT91_SHDW_CR);
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
"r" (at91_shdwc_base),
"r" cpu_to_le32(AT91_SHDW_KEY | AT91_SHDW_SHDW)
: "r0");
}
static int at91_poweroff_get_wakeup_mode(struct device_node *np)
{
const char *pm;
unsigned int i;
int err;
err = of_property_read_string(np, "atmel,wakeup-mode", &pm);
if (err < 0)
return AT91_SHDW_WKMODE0_ANYLEVEL;
for (i = 0; i < ARRAY_SIZE(shdwc_wakeup_modes); i++)
if (!strcasecmp(pm, shdwc_wakeup_modes[i]))
return i;
return -ENODEV;
}
static void at91_poweroff_dt_set_wakeup_mode(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int wakeup_mode;
u32 mode = 0, tmp;
wakeup_mode = at91_poweroff_get_wakeup_mode(np);
if (wakeup_mode < 0) {
dev_warn(&pdev->dev, "shdwc unknown wakeup mode\n");
return;
}
if (!of_property_read_u32(np, "atmel,wakeup-counter", &tmp)) {
if (tmp > AT91_SHDW_CPTWK0_MAX) {
dev_warn(&pdev->dev,
"shdwc wakeup counter 0x%x > 0x%x reduce it to 0x%x\n",
tmp, AT91_SHDW_CPTWK0_MAX, AT91_SHDW_CPTWK0_MAX);
tmp = AT91_SHDW_CPTWK0_MAX;
}
mode |= AT91_SHDW_CPTWK0_(tmp);
}
if (of_property_read_bool(np, "atmel,wakeup-rtc-timer"))
mode |= AT91_SHDW_RTCWKEN;
if (of_property_read_bool(np, "atmel,wakeup-rtt-timer"))
mode |= AT91_SHDW_RTTWKEN;
writel(wakeup_mode | mode, at91_shdwc_base + AT91_SHDW_MR);
}
static int __init at91_poweroff_probe(struct platform_device *pdev)
{
struct resource *res;
struct device_node *np;
u32 ddr_type;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
at91_shdwc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(at91_shdwc_base)) {
dev_err(&pdev->dev, "Could not map reset controller address\n");
return PTR_ERR(at91_shdwc_base);
}
sclk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sclk))
return PTR_ERR(sclk);
ret = clk_prepare_enable(sclk);
if (ret) {
dev_err(&pdev->dev, "Could not enable slow clock\n");
return ret;
}
at91_wakeup_status();
if (pdev->dev.of_node)
at91_poweroff_dt_set_wakeup_mode(pdev);
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
static int __exit at91_poweroff_remove(struct platform_device *pdev)
{
if (pm_power_off == at91_poweroff ||
pm_power_off == at91_lpddr_poweroff)
pm_power_off = NULL;
clk_disable_unprepare(sclk);
return 0;
}
