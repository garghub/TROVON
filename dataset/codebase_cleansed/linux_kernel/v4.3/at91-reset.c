static int at91sam9260_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
asm volatile(
".balign 32\n\t"
"str %2, [%0, #" __stringify(AT91_SDRAMC_TR) "]\n\t"
"str %3, [%0, #" __stringify(AT91_SDRAMC_LPR) "]\n\t"
"str %4, [%1, #" __stringify(AT91_RSTC_CR) "]\n\t"
"b .\n\t"
:
: "r" (at91_ramc_base[0]),
"r" (at91_rstc_base),
"r" (1),
"r" cpu_to_le32(AT91_SDRAMC_LPCB_POWER_DOWN),
"r" cpu_to_le32(AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST));
return NOTIFY_DONE;
}
static int at91sam9g45_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
asm volatile(
"cmp %1, #0\n\t"
"beq 1f\n\t"
"ldr r0, [%1]\n\t"
"cmp r0, #0\n\t"
".balign 32\n\t"
"1: str %3, [%0, #" __stringify(AT91_DDRSDRC_RTR) "]\n\t"
" str %4, [%0, #" __stringify(AT91_DDRSDRC_LPR) "]\n\t"
" strne %3, [%1, #" __stringify(AT91_DDRSDRC_RTR) "]\n\t"
" strne %4, [%1, #" __stringify(AT91_DDRSDRC_LPR) "]\n\t"
" str %5, [%2, #" __stringify(AT91_RSTC_CR) "]\n\t"
" b .\n\t"
:
: "r" (at91_ramc_base[0]),
"r" (at91_ramc_base[1]),
"r" (at91_rstc_base),
"r" (1),
"r" cpu_to_le32(AT91_DDRSDRC_LPCB_POWER_DOWN),
"r" cpu_to_le32(AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST)
: "r0");
return NOTIFY_DONE;
}
static int sama5d3_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
writel(cpu_to_le32(AT91_RSTC_KEY | AT91_RSTC_PERRST | AT91_RSTC_PROCRST),
at91_rstc_base);
return NOTIFY_DONE;
}
static void __init at91_reset_status(struct platform_device *pdev)
{
u32 reg = readl(at91_rstc_base + AT91_RSTC_SR);
char *reason;
switch ((reg & AT91_RSTC_RSTTYP) >> 8) {
case RESET_TYPE_GENERAL:
reason = "general reset";
break;
case RESET_TYPE_WAKEUP:
reason = "wakeup";
break;
case RESET_TYPE_WATCHDOG:
reason = "watchdog reset";
break;
case RESET_TYPE_SOFTWARE:
reason = "software reset";
break;
case RESET_TYPE_USER:
reason = "user reset";
break;
default:
reason = "unknown reset";
break;
}
pr_info("AT91: Starting after %s\n", reason);
}
static int at91_reset_of_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device_node *np;
int idx = 0;
at91_rstc_base = of_iomap(pdev->dev.of_node, 0);
if (!at91_rstc_base) {
dev_err(&pdev->dev, "Could not map reset controller address\n");
return -ENODEV;
}
if (!of_device_is_compatible(pdev->dev.of_node, "atmel,sama5d3-rstc")) {
for_each_matching_node(np, at91_ramc_of_match) {
at91_ramc_base[idx] = of_iomap(np, 0);
if (!at91_ramc_base[idx]) {
dev_err(&pdev->dev, "Could not map ram controller address\n");
return -ENODEV;
}
idx++;
}
}
match = of_match_node(at91_reset_of_match, pdev->dev.of_node);
at91_restart_nb.notifier_call = match->data;
return register_restart_handler(&at91_restart_nb);
}
static int at91_reset_platform_probe(struct platform_device *pdev)
{
const struct platform_device_id *match;
struct resource *res;
int idx = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
at91_rstc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(at91_rstc_base)) {
dev_err(&pdev->dev, "Could not map reset controller address\n");
return PTR_ERR(at91_rstc_base);
}
for (idx = 0; idx < 2; idx++) {
res = platform_get_resource(pdev, IORESOURCE_MEM, idx + 1 );
at91_ramc_base[idx] = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!at91_ramc_base[idx]) {
dev_err(&pdev->dev, "Could not map ram controller address\n");
return -ENOMEM;
}
}
match = platform_get_device_id(pdev);
at91_restart_nb.notifier_call =
(int (*)(struct notifier_block *,
unsigned long, void *)) match->driver_data;
return register_restart_handler(&at91_restart_nb);
}
static int at91_reset_probe(struct platform_device *pdev)
{
int ret;
if (pdev->dev.of_node)
ret = at91_reset_of_probe(pdev);
else
ret = at91_reset_platform_probe(pdev);
if (ret)
return ret;
at91_reset_status(pdev);
return 0;
}
