static int tegra_mc_setup_latency_allowance(struct tegra_mc *mc)
{
unsigned long long tick;
unsigned int i;
u32 value;
tick = mc->tick * clk_get_rate(mc->clk);
do_div(tick, NSEC_PER_SEC);
value = readl(mc->regs + MC_EMEM_ARB_CFG);
value &= ~MC_EMEM_ARB_CFG_CYCLES_PER_UPDATE_MASK;
value |= MC_EMEM_ARB_CFG_CYCLES_PER_UPDATE(tick);
writel(value, mc->regs + MC_EMEM_ARB_CFG);
for (i = 0; i < mc->soc->num_clients; i++) {
const struct tegra_mc_la *la = &mc->soc->clients[i].la;
u32 value;
value = readl(mc->regs + la->reg);
value &= ~(la->mask << la->shift);
value |= (la->def & la->mask) << la->shift;
writel(value, mc->regs + la->reg);
}
return 0;
}
static irqreturn_t tegra_mc_irq(int irq, void *data)
{
struct tegra_mc *mc = data;
unsigned long status, mask;
unsigned int bit;
status = mc_readl(mc, MC_INTSTATUS);
mask = mc_readl(mc, MC_INTMASK);
for_each_set_bit(bit, &status, 32) {
const char *error = status_names[bit] ?: "unknown";
const char *client = "unknown", *desc;
const char *direction, *secure;
phys_addr_t addr = 0;
unsigned int i;
char perm[7];
u8 id, type;
u32 value;
value = mc_readl(mc, MC_ERR_STATUS);
#ifdef CONFIG_PHYS_ADDR_T_64BIT
if (mc->soc->num_address_bits > 32) {
addr = ((value >> MC_ERR_STATUS_ADR_HI_SHIFT) &
MC_ERR_STATUS_ADR_HI_MASK);
addr <<= 32;
}
#endif
if (value & MC_ERR_STATUS_RW)
direction = "write";
else
direction = "read";
if (value & MC_ERR_STATUS_SECURITY)
secure = "secure ";
else
secure = "";
id = value & MC_ERR_STATUS_CLIENT_MASK;
for (i = 0; i < mc->soc->num_clients; i++) {
if (mc->soc->clients[i].id == id) {
client = mc->soc->clients[i].name;
break;
}
}
type = (value & MC_ERR_STATUS_TYPE_MASK) >>
MC_ERR_STATUS_TYPE_SHIFT;
desc = error_names[type];
switch (value & MC_ERR_STATUS_TYPE_MASK) {
case MC_ERR_STATUS_TYPE_INVALID_SMMU_PAGE:
perm[0] = ' ';
perm[1] = '[';
if (value & MC_ERR_STATUS_READABLE)
perm[2] = 'R';
else
perm[2] = '-';
if (value & MC_ERR_STATUS_WRITABLE)
perm[3] = 'W';
else
perm[3] = '-';
if (value & MC_ERR_STATUS_NONSECURE)
perm[4] = '-';
else
perm[4] = 'S';
perm[5] = ']';
perm[6] = '\0';
break;
default:
perm[0] = '\0';
break;
}
value = mc_readl(mc, MC_ERR_ADR);
addr |= value;
dev_err_ratelimited(mc->dev, "%s: %s%s @%pa: %s (%s%s)\n",
client, secure, direction, &addr, error,
desc, perm);
}
mc_writel(mc, status, MC_INTSTATUS);
return IRQ_HANDLED;
}
static int tegra_mc_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct resource *res;
struct tegra_mc *mc;
u32 value;
int err;
match = of_match_node(tegra_mc_of_match, pdev->dev.of_node);
if (!match)
return -ENODEV;
mc = devm_kzalloc(&pdev->dev, sizeof(*mc), GFP_KERNEL);
if (!mc)
return -ENOMEM;
platform_set_drvdata(pdev, mc);
mc->soc = match->data;
mc->dev = &pdev->dev;
mc->tick = 30;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mc->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mc->regs))
return PTR_ERR(mc->regs);
mc->clk = devm_clk_get(&pdev->dev, "mc");
if (IS_ERR(mc->clk)) {
dev_err(&pdev->dev, "failed to get MC clock: %ld\n",
PTR_ERR(mc->clk));
return PTR_ERR(mc->clk);
}
err = tegra_mc_setup_latency_allowance(mc);
if (err < 0) {
dev_err(&pdev->dev, "failed to setup latency allowance: %d\n",
err);
return err;
}
if (IS_ENABLED(CONFIG_TEGRA_IOMMU_SMMU)) {
mc->smmu = tegra_smmu_probe(&pdev->dev, mc->soc->smmu, mc);
if (IS_ERR(mc->smmu)) {
dev_err(&pdev->dev, "failed to probe SMMU: %ld\n",
PTR_ERR(mc->smmu));
return PTR_ERR(mc->smmu);
}
}
mc->irq = platform_get_irq(pdev, 0);
if (mc->irq < 0) {
dev_err(&pdev->dev, "interrupt not specified\n");
return mc->irq;
}
err = devm_request_irq(&pdev->dev, mc->irq, tegra_mc_irq, IRQF_SHARED,
dev_name(&pdev->dev), mc);
if (err < 0) {
dev_err(&pdev->dev, "failed to request IRQ#%u: %d\n", mc->irq,
err);
return err;
}
value = MC_INT_DECERR_MTS | MC_INT_SECERR_SEC | MC_INT_DECERR_VPR |
MC_INT_INVALID_APB_ASID_UPDATE | MC_INT_INVALID_SMMU_PAGE |
MC_INT_ARBITRATION_EMEM | MC_INT_SECURITY_VIOLATION |
MC_INT_DECERR_EMEM;
mc_writel(mc, value, MC_INTMASK);
return 0;
}
static int tegra_mc_init(void)
{
return platform_driver_register(&tegra_mc_driver);
}
