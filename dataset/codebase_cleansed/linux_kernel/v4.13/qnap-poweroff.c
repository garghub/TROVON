static void qnap_power_off(void)
{
const unsigned divisor = ((tclk + (8 * cfg->baud)) / (16 * cfg->baud));
pr_err("%s: triggering power-off...\n", __func__);
writel(0x83, UART1_REG(LCR));
writel(divisor & 0xff, UART1_REG(DLL));
writel((divisor >> 8) & 0xff, UART1_REG(DLM));
writel(0x03, UART1_REG(LCR));
writel(0x00, UART1_REG(IER));
writel(0x00, UART1_REG(FCR));
writel(0x00, UART1_REG(MCR));
writel(cfg->cmd, UART1_REG(TX));
}
static int qnap_power_off_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res;
struct clk *clk;
char symname[KSYM_NAME_LEN];
const struct of_device_id *match =
of_match_node(qnap_power_off_of_match_table, np);
cfg = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Missing resource");
return -EINVAL;
}
base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!base) {
dev_err(&pdev->dev, "Unable to map resource");
return -EINVAL;
}
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Clk missing");
return PTR_ERR(clk);
}
tclk = clk_get_rate(clk);
if (pm_power_off) {
lookup_symbol_name((ulong)pm_power_off, symname);
dev_err(&pdev->dev,
"pm_power_off already claimed %p %s",
pm_power_off, symname);
return -EBUSY;
}
pm_power_off = qnap_power_off;
return 0;
}
static int qnap_power_off_remove(struct platform_device *pdev)
{
pm_power_off = NULL;
return 0;
}
