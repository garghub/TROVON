void wmt_setup_restart(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "wmt,prizm-pmc");
if (np) {
pmc_base = of_iomap(np, 0);
if (!pmc_base)
pr_err("%s:of_iomap(pmc) failed\n", __func__);
of_node_put(np);
} else {
pmc_base = ioremap(LEGACY_PMC_BASE, 0x1000);
if (!pmc_base) {
pr_err("%s:ioremap(rstc) failed\n", __func__);
return;
}
}
}
void wmt_restart(char mode, const char *cmd)
{
if (pmc_base)
writel(1, pmc_base + WMT_PRIZM_PMSR_REG);
}
