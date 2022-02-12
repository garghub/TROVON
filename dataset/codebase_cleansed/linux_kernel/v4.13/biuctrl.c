static int __init mcp_write_pairing_set(void)
{
u32 creds = 0;
if (!cpubiuctrl_base)
return -1;
creds = readl_relaxed(cpubiuctrl_base + CPU_CREDIT_REG_OFFSET);
if (mcp_wr_pairing_en) {
pr_info("MCP: Enabling write pairing\n");
writel_relaxed(creds | CPU_CREDIT_REG_MCPx_WR_PAIRING_EN_MASK,
cpubiuctrl_base + CPU_CREDIT_REG_OFFSET);
} else if (creds & CPU_CREDIT_REG_MCPx_WR_PAIRING_EN_MASK) {
pr_info("MCP: Disabling write pairing\n");
writel_relaxed(creds & ~CPU_CREDIT_REG_MCPx_WR_PAIRING_EN_MASK,
cpubiuctrl_base + CPU_CREDIT_REG_OFFSET);
} else {
pr_info("MCP: Write pairing already disabled\n");
}
return 0;
}
static int __init setup_hifcpubiuctrl_regs(void)
{
struct device_node *np;
int ret = 0;
np = of_find_compatible_node(NULL, NULL, "brcm,brcmstb-cpu-biu-ctrl");
if (!np) {
pr_err("missing BIU control node\n");
return -ENODEV;
}
cpubiuctrl_base = of_iomap(np, 0);
if (!cpubiuctrl_base) {
pr_err("failed to remap BIU control base\n");
ret = -ENOMEM;
goto out;
}
mcp_wr_pairing_en = of_property_read_bool(np, "brcm,write-pairing");
out:
of_node_put(np);
return ret;
}
static int brcmstb_cpu_credit_reg_suspend(void)
{
if (cpubiuctrl_base)
cpu_credit_reg_dump =
readl_relaxed(cpubiuctrl_base + CPU_CREDIT_REG_OFFSET);
return 0;
}
static void brcmstb_cpu_credit_reg_resume(void)
{
if (cpubiuctrl_base)
writel_relaxed(cpu_credit_reg_dump,
cpubiuctrl_base + CPU_CREDIT_REG_OFFSET);
}
void __init brcmstb_biuctrl_init(void)
{
int ret;
setup_hifcpubiuctrl_regs();
ret = mcp_write_pairing_set();
if (ret) {
pr_err("MCP: Unable to disable write pairing!\n");
return;
}
#ifdef CONFIG_PM_SLEEP
register_syscore_ops(&brcmstb_cpu_credit_syscore_ops);
#endif
}
