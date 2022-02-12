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
const enum wakeup_type at91_poweroff_get_wakeup_mode(struct device_node *np)
{
const char *pm;
int err, i;
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
enum wakeup_type wakeup_mode;
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
static int at91_poweroff_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
at91_shdwc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(at91_shdwc_base)) {
dev_err(&pdev->dev, "Could not map reset controller address\n");
return PTR_ERR(at91_shdwc_base);
}
at91_wakeup_status();
if (pdev->dev.of_node)
at91_poweroff_dt_set_wakeup_mode(pdev);
pm_power_off = at91_poweroff;
return 0;
}
