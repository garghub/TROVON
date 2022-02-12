static int tegra186_pmc_restart_notify(struct notifier_block *nb,
unsigned long action,
void *data)
{
struct tegra_pmc *pmc = container_of(nb, struct tegra_pmc, restart);
const char *cmd = data;
u32 value;
value = readl(pmc->scratch + SCRATCH_SCRATCH0);
value &= ~SCRATCH_SCRATCH0_MODE_MASK;
if (cmd) {
if (strcmp(cmd, "recovery") == 0)
value |= SCRATCH_SCRATCH0_MODE_RECOVERY;
if (strcmp(cmd, "bootloader") == 0)
value |= SCRATCH_SCRATCH0_MODE_BOOTLOADER;
if (strcmp(cmd, "forced-recovery") == 0)
value |= SCRATCH_SCRATCH0_MODE_RCM;
}
writel(value, pmc->scratch + SCRATCH_SCRATCH0);
if (pmc->system_restart) {
pmc->system_restart(reboot_mode, cmd);
return NOTIFY_DONE;
}
value = readl(pmc->regs + PMC_CNTRL);
value |= PMC_CNTRL_MAIN_RST;
writel(value, pmc->regs + PMC_CNTRL);
return NOTIFY_DONE;
}
static int tegra186_pmc_setup(struct tegra_pmc *pmc)
{
struct device_node *np = pmc->dev->of_node;
bool invert;
u32 value;
invert = of_property_read_bool(np, "nvidia,invert-interrupt");
value = readl(pmc->wake + WAKE_AOWAKE_CTRL);
if (invert)
value |= WAKE_AOWAKE_CTRL_INTR_POLARITY;
else
value &= ~WAKE_AOWAKE_CTRL_INTR_POLARITY;
writel(value, pmc->wake + WAKE_AOWAKE_CTRL);
pmc->system_restart = arm_pm_restart;
arm_pm_restart = NULL;
pmc->restart.notifier_call = tegra186_pmc_restart_notify;
pmc->restart.priority = 128;
return register_restart_handler(&pmc->restart);
}
static int tegra186_pmc_probe(struct platform_device *pdev)
{
struct tegra_pmc *pmc;
struct resource *res;
pmc = devm_kzalloc(&pdev->dev, sizeof(*pmc), GFP_KERNEL);
if (!pmc)
return -ENOMEM;
pmc->dev = &pdev->dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pmc");
pmc->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmc->regs))
return PTR_ERR(pmc->regs);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "wake");
pmc->wake = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmc->wake))
return PTR_ERR(pmc->wake);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "aotag");
pmc->aotag = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmc->aotag))
return PTR_ERR(pmc->aotag);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "scratch");
pmc->scratch = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmc->scratch))
return PTR_ERR(pmc->scratch);
return tegra186_pmc_setup(pmc);
}
