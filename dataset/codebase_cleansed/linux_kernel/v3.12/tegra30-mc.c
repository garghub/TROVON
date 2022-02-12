static inline u32 mc_readl(struct tegra30_mc *mc, u32 offs)
{
u32 val = 0;
if (offs < 0x10)
val = readl(mc->regs[0] + offs);
else if (offs < 0x1f0)
val = readl(mc->regs[1] + offs - 0x3c);
else if (offs < 0x228)
val = readl(mc->regs[2] + offs - 0x200);
else if (offs < 0x400)
val = readl(mc->regs[3] + offs - 0x284);
return val;
}
static inline void mc_writel(struct tegra30_mc *mc, u32 val, u32 offs)
{
if (offs < 0x10)
writel(val, mc->regs[0] + offs);
else if (offs < 0x1f0)
writel(val, mc->regs[1] + offs - 0x3c);
else if (offs < 0x228)
writel(val, mc->regs[2] + offs - 0x200);
else if (offs < 0x400)
writel(val, mc->regs[3] + offs - 0x284);
}
static void tegra30_mc_decode(struct tegra30_mc *mc, int n)
{
u32 err, addr;
const char * const mc_int_err[] = {
"MC_DECERR",
"Unknown",
"MC_SECURITY_ERR",
"MC_ARBITRATION_EMEM",
"MC_SMMU_ERR",
};
const char * const err_type[] = {
"Unknown",
"Unknown",
"DECERR_EMEM",
"SECURITY_TRUSTZONE",
"SECURITY_CARVEOUT",
"Unknown",
"INVALID_SMMU_PAGE",
"Unknown",
};
char attr[6];
int cid, perm, type, idx;
const char *client = "Unknown";
idx = n - MC_INT_ERR_SHIFT;
if ((idx < 0) || (idx >= ARRAY_SIZE(mc_int_err)) || (idx == 1)) {
dev_err_ratelimited(mc->dev, "Unknown interrupt status %08lx\n",
BIT(n));
return;
}
err = mc_readl(mc, MC_ERR_STATUS);
type = (err & MC_ERR_TYPE_MASK) >> MC_ERR_TYPE_SHIFT;
perm = (err & MC_ERR_INVALID_SMMU_PAGE_MASK) >>
MC_ERR_INVALID_SMMU_PAGE_SHIFT;
if (type == MC_ERR_TYPE_INVALID_SMMU_PAGE)
sprintf(attr, "%c-%c-%c",
(perm & BIT(2)) ? 'R' : '-',
(perm & BIT(1)) ? 'W' : '-',
(perm & BIT(0)) ? 'S' : '-');
else
attr[0] = '\0';
cid = err & MC_CLIENT_ID_MASK;
if (cid < ARRAY_SIZE(tegra30_mc_client))
client = tegra30_mc_client[cid];
addr = mc_readl(mc, MC_ERR_ADR);
dev_err_ratelimited(mc->dev, "%s (0x%08x): 0x%08x %s (%s %s %s %s)\n",
mc_int_err[idx], err, addr, client,
(err & MC_ERR_SECURITY) ? "secure" : "non-secure",
(err & MC_ERR_RW) ? "write" : "read",
err_type[type], attr);
}
static int tegra30_mc_suspend(struct device *dev)
{
int i;
struct tegra30_mc *mc = dev_get_drvdata(dev);
for (i = 0; i < ARRAY_SIZE(tegra30_mc_ctx); i++)
mc->ctx[i] = mc_readl(mc, tegra30_mc_ctx[i]);
return 0;
}
static int tegra30_mc_resume(struct device *dev)
{
int i;
struct tegra30_mc *mc = dev_get_drvdata(dev);
for (i = 0; i < ARRAY_SIZE(tegra30_mc_ctx); i++)
mc_writel(mc, mc->ctx[i], tegra30_mc_ctx[i]);
mc_writel(mc, 1, MC_TIMING_CONTROL);
mc_readl(mc, MC_TIMING_CONTROL);
return 0;
}
static irqreturn_t tegra30_mc_isr(int irq, void *data)
{
u32 stat, mask, bit;
struct tegra30_mc *mc = data;
stat = mc_readl(mc, MC_INTSTATUS);
mask = mc_readl(mc, MC_INTMASK);
mask &= stat;
if (!mask)
return IRQ_NONE;
while ((bit = ffs(mask)) != 0) {
tegra30_mc_decode(mc, bit - 1);
mask &= ~BIT(bit - 1);
}
mc_writel(mc, stat, MC_INTSTATUS);
return IRQ_HANDLED;
}
static int tegra30_mc_probe(struct platform_device *pdev)
{
struct resource *irq;
struct tegra30_mc *mc;
size_t bytes;
int err, i;
u32 intmask;
bytes = sizeof(*mc) + sizeof(u32) * ARRAY_SIZE(tegra30_mc_ctx);
mc = devm_kzalloc(&pdev->dev, bytes, GFP_KERNEL);
if (!mc)
return -ENOMEM;
mc->dev = &pdev->dev;
for (i = 0; i < ARRAY_SIZE(mc->regs); i++) {
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
mc->regs[i] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mc->regs[i]))
return PTR_ERR(mc->regs[i]);
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq)
return -ENODEV;
err = devm_request_irq(&pdev->dev, irq->start, tegra30_mc_isr,
IRQF_SHARED, dev_name(&pdev->dev), mc);
if (err)
return -ENODEV;
platform_set_drvdata(pdev, mc);
intmask = MC_INT_INVALID_SMMU_PAGE |
MC_INT_DECERR_EMEM | MC_INT_SECURITY_VIOLATION;
mc_writel(mc, intmask, MC_INTMASK);
return 0;
}
