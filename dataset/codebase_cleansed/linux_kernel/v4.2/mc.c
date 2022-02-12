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
void tegra_mc_write_emem_configuration(struct tegra_mc *mc, unsigned long rate)
{
unsigned int i;
struct tegra_mc_timing *timing = NULL;
for (i = 0; i < mc->num_timings; i++) {
if (mc->timings[i].rate == rate) {
timing = &mc->timings[i];
break;
}
}
if (!timing) {
dev_err(mc->dev, "no memory timing registered for rate %lu\n",
rate);
return;
}
for (i = 0; i < mc->soc->num_emem_regs; ++i)
mc_writel(mc, timing->emem_data[i], mc->soc->emem_regs[i]);
}
unsigned int tegra_mc_get_emem_device_count(struct tegra_mc *mc)
{
u8 dram_count;
dram_count = mc_readl(mc, MC_EMEM_ADR_CFG);
dram_count &= MC_EMEM_ADR_CFG_EMEM_NUMDEV;
dram_count++;
return dram_count;
}
static int load_one_timing(struct tegra_mc *mc,
struct tegra_mc_timing *timing,
struct device_node *node)
{
int err;
u32 tmp;
err = of_property_read_u32(node, "clock-frequency", &tmp);
if (err) {
dev_err(mc->dev,
"timing %s: failed to read rate\n", node->name);
return err;
}
timing->rate = tmp;
timing->emem_data = devm_kcalloc(mc->dev, mc->soc->num_emem_regs,
sizeof(u32), GFP_KERNEL);
if (!timing->emem_data)
return -ENOMEM;
err = of_property_read_u32_array(node, "nvidia,emem-configuration",
timing->emem_data,
mc->soc->num_emem_regs);
if (err) {
dev_err(mc->dev,
"timing %s: failed to read EMEM configuration\n",
node->name);
return err;
}
return 0;
}
static int load_timings(struct tegra_mc *mc, struct device_node *node)
{
struct device_node *child;
struct tegra_mc_timing *timing;
int child_count = of_get_child_count(node);
int i = 0, err;
mc->timings = devm_kcalloc(mc->dev, child_count, sizeof(*timing),
GFP_KERNEL);
if (!mc->timings)
return -ENOMEM;
mc->num_timings = child_count;
for_each_child_of_node(node, child) {
timing = &mc->timings[i++];
err = load_one_timing(mc, timing, child);
if (err)
return err;
}
return 0;
}
static int tegra_mc_setup_timings(struct tegra_mc *mc)
{
struct device_node *node;
u32 ram_code, node_ram_code;
int err;
ram_code = tegra_read_ram_code();
mc->num_timings = 0;
for_each_child_of_node(mc->dev->of_node, node) {
err = of_property_read_u32(node, "nvidia,ram-code",
&node_ram_code);
if (err || (node_ram_code != ram_code)) {
of_node_put(node);
continue;
}
err = load_timings(mc, node);
if (err)
return err;
of_node_put(node);
break;
}
if (mc->num_timings == 0)
dev_warn(mc->dev,
"no memory timings for RAM code %u registered\n",
ram_code);
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
err = tegra_mc_setup_timings(mc);
if (err < 0) {
dev_err(&pdev->dev, "failed to setup timings: %d\n", err);
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
MC_INT_SECURITY_VIOLATION | MC_INT_DECERR_EMEM;
mc_writel(mc, value, MC_INTMASK);
return 0;
}
static int tegra_mc_init(void)
{
return platform_driver_register(&tegra_mc_driver);
}
