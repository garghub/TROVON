static inline u32 mc_readl(struct tegra20_mc *mc, u32 offs)
{
u32 val = 0;
if (offs < 0x24)
val = readl(mc->regs[0] + offs);
else if (offs < 0x400)
val = readl(mc->regs[1] + offs - 0x3c);
return val;
}
static inline void mc_writel(struct tegra20_mc *mc, u32 val, u32 offs)
{
if (offs < 0x24)
writel(val, mc->regs[0] + offs);
else if (offs < 0x400)
writel(val, mc->regs[1] + offs - 0x3c);
}
static void tegra20_mc_decode(struct tegra20_mc *mc, int n)
{
u32 addr, req;
const char *client = "Unknown";
int idx, cid;
const struct reg_info {
u32 offset;
u32 write_bit;
int cid_shift;
char *message;
} reg[] = {
{
.offset = MC_DECERR_EMEM_OTHERS_STATUS,
.write_bit = 31,
.message = "MC_DECERR",
},
{
.offset = MC_GART_ERROR_REQ,
.cid_shift = 1,
.message = "MC_GART_ERR",
},
{
.offset = MC_SECURITY_VIOLATION_STATUS,
.write_bit = 31,
.message = "MC_SECURITY_ERR",
},
};
idx = n - MC_INT_ERR_SHIFT;
if ((idx < 0) || (idx >= ARRAY_SIZE(reg))) {
dev_err_ratelimited(mc->dev, "Unknown interrupt status %08lx\n",
BIT(n));
return;
}
req = mc_readl(mc, reg[idx].offset);
cid = (req >> reg[idx].cid_shift) & MC_CLIENT_ID_MASK;
if (cid < ARRAY_SIZE(tegra20_mc_client))
client = tegra20_mc_client[cid];
addr = mc_readl(mc, reg[idx].offset + sizeof(u32));
dev_err_ratelimited(mc->dev, "%s (0x%08x): 0x%08x %s (%s %s)\n",
reg[idx].message, req, addr, client,
(req & BIT(reg[idx].write_bit)) ? "write" : "read",
(reg[idx].offset == MC_SECURITY_VIOLATION_STATUS) ?
((req & SECURITY_VIOLATION_TYPE) ?
"carveout" : "trustzone") : "");
}
static irqreturn_t tegra20_mc_isr(int irq, void *data)
{
u32 stat, mask, bit;
struct tegra20_mc *mc = data;
stat = mc_readl(mc, MC_INTSTATUS);
mask = mc_readl(mc, MC_INTMASK);
mask &= stat;
if (!mask)
return IRQ_NONE;
while ((bit = ffs(mask)) != 0)
tegra20_mc_decode(mc, bit - 1);
mc_writel(mc, stat, MC_INTSTATUS);
return IRQ_HANDLED;
}
static int __devinit tegra20_mc_probe(struct platform_device *pdev)
{
struct resource *irq;
struct tegra20_mc *mc;
int i, err;
u32 intmask;
mc = devm_kzalloc(&pdev->dev, sizeof(*mc), GFP_KERNEL);
if (!mc)
return -ENOMEM;
mc->dev = &pdev->dev;
for (i = 0; i < ARRAY_SIZE(mc->regs); i++) {
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res)
return -ENODEV;
mc->regs[i] = devm_request_and_ioremap(&pdev->dev, res);
if (!mc->regs[i])
return -EBUSY;
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq)
return -ENODEV;
err = devm_request_irq(&pdev->dev, irq->start, tegra20_mc_isr,
IRQF_SHARED, dev_name(&pdev->dev), mc);
if (err)
return -ENODEV;
platform_set_drvdata(pdev, mc);
intmask = MC_INT_INVALID_GART_PAGE |
MC_INT_DECERR_EMEM | MC_INT_SECURITY_VIOLATION;
mc_writel(mc, intmask, MC_INTMASK);
return 0;
}
