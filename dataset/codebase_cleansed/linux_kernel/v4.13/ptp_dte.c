static void dte_write_nco(void __iomem *regs, s64 ns)
{
u32 sum2, sum3;
sum2 = (u32)((ns >> DTE_NCO_SUM2_SHIFT) & DTE_NCO_SUM2_MASK);
if (sum2 != DTE_NCO_SUM2_MASK)
sum2++;
sum3 = (u32)(((ns >> DTE_NCO_SUM3_SHIFT) & DTE_NCO_SUM3_MASK) <<
DTE_NCO_SUM3_WR_SHIFT);
writel(0, (regs + DTE_NCO_LOW_TIME_REG));
writel(sum2, (regs + DTE_NCO_TIME_REG));
writel(sum3, (regs + DTE_NCO_OVERFLOW_REG));
}
static s64 dte_read_nco(void __iomem *regs)
{
u32 sum2, sum3;
s64 ns;
sum3 = readl(regs + DTE_NCO_OVERFLOW_REG) & DTE_NCO_SUM3_MASK;
sum2 = readl(regs + DTE_NCO_TIME_REG);
ns = ((s64)sum3 << DTE_NCO_SUM3_SHIFT) |
((s64)sum2 << DTE_NCO_SUM2_SHIFT);
return ns;
}
static void dte_write_nco_delta(struct ptp_dte *ptp_dte, s64 delta)
{
s64 ns;
ns = dte_read_nco(ptp_dte->regs);
if ((delta < 0) && (abs(delta) > ns)) {
if (ptp_dte->ts_wrap_cnt) {
ns += DTE_NCO_MAX_NS + delta;
ptp_dte->ts_wrap_cnt--;
} else {
ns = 0;
}
} else {
ns += delta;
if (ns > DTE_NCO_MAX_NS) {
ptp_dte->ts_wrap_cnt++;
ns -= DTE_NCO_MAX_NS;
}
}
dte_write_nco(ptp_dte->regs, ns);
ptp_dte->ts_ovf_last = (ns >> DTE_NCO_TS_WRAP_LSHIFT) &
DTE_NCO_TS_WRAP_MASK;
}
static s64 dte_read_nco_with_ovf(struct ptp_dte *ptp_dte)
{
u32 ts_ovf;
s64 ns = 0;
ns = dte_read_nco(ptp_dte->regs);
ts_ovf = (ns >> DTE_NCO_TS_WRAP_LSHIFT) & DTE_NCO_TS_WRAP_MASK;
if (ts_ovf < ptp_dte->ts_ovf_last)
ptp_dte->ts_wrap_cnt++;
ptp_dte->ts_ovf_last = ts_ovf;
ns += (s64)(BIT_ULL(DTE_WRAP_AROUND_NSEC_SHIFT) * ptp_dte->ts_wrap_cnt);
return ns;
}
static int ptp_dte_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
u32 nco_incr;
unsigned long flags;
struct ptp_dte *ptp_dte = container_of(ptp, struct ptp_dte, caps);
if (abs(ppb) > ptp_dte->caps.max_adj) {
dev_err(ptp_dte->dev, "ppb adj too big\n");
return -EINVAL;
}
if (ppb < 0)
nco_incr = DTE_NCO_INC_DEFAULT - DTE_PPB_ADJ(ppb);
else
nco_incr = DTE_NCO_INC_DEFAULT + DTE_PPB_ADJ(ppb);
spin_lock_irqsave(&ptp_dte->lock, flags);
writel(nco_incr, ptp_dte->regs + DTE_NCO_INC_REG);
spin_unlock_irqrestore(&ptp_dte->lock, flags);
return 0;
}
static int ptp_dte_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
unsigned long flags;
struct ptp_dte *ptp_dte = container_of(ptp, struct ptp_dte, caps);
spin_lock_irqsave(&ptp_dte->lock, flags);
dte_write_nco_delta(ptp_dte, delta);
spin_unlock_irqrestore(&ptp_dte->lock, flags);
return 0;
}
static int ptp_dte_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
unsigned long flags;
struct ptp_dte *ptp_dte = container_of(ptp, struct ptp_dte, caps);
spin_lock_irqsave(&ptp_dte->lock, flags);
*ts = ns_to_timespec64(dte_read_nco_with_ovf(ptp_dte));
spin_unlock_irqrestore(&ptp_dte->lock, flags);
return 0;
}
static int ptp_dte_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
unsigned long flags;
struct ptp_dte *ptp_dte = container_of(ptp, struct ptp_dte, caps);
spin_lock_irqsave(&ptp_dte->lock, flags);
writel(0, ptp_dte->regs + DTE_NCO_INC_REG);
dte_write_nco(ptp_dte->regs, timespec64_to_ns(ts));
ptp_dte->ts_ovf_last = 0;
ptp_dte->ts_wrap_cnt = 0;
writel(DTE_NCO_INC_DEFAULT, ptp_dte->regs + DTE_NCO_INC_REG);
spin_unlock_irqrestore(&ptp_dte->lock, flags);
return 0;
}
static int ptp_dte_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
static int ptp_dte_probe(struct platform_device *pdev)
{
struct ptp_dte *ptp_dte;
struct device *dev = &pdev->dev;
struct resource *res;
ptp_dte = devm_kzalloc(dev, sizeof(struct ptp_dte), GFP_KERNEL);
if (!ptp_dte)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ptp_dte->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(ptp_dte->regs)) {
dev_err(dev,
"%s: io remap failed\n", __func__);
return PTR_ERR(ptp_dte->regs);
}
spin_lock_init(&ptp_dte->lock);
ptp_dte->dev = dev;
ptp_dte->caps = ptp_dte_caps;
ptp_dte->ptp_clk = ptp_clock_register(&ptp_dte->caps, &pdev->dev);
if (IS_ERR(ptp_dte->ptp_clk)) {
dev_err(dev,
"%s: Failed to register ptp clock\n", __func__);
return PTR_ERR(ptp_dte->ptp_clk);
}
platform_set_drvdata(pdev, ptp_dte);
dev_info(dev, "ptp clk probe done\n");
return 0;
}
static int ptp_dte_remove(struct platform_device *pdev)
{
struct ptp_dte *ptp_dte = platform_get_drvdata(pdev);
u8 i;
ptp_clock_unregister(ptp_dte->ptp_clk);
for (i = 0; i < DTE_NUM_REGS_TO_RESTORE; i++)
writel(0, ptp_dte->regs + (i * sizeof(u32)));
return 0;
}
static int ptp_dte_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ptp_dte *ptp_dte = platform_get_drvdata(pdev);
u8 i;
for (i = 0; i < DTE_NUM_REGS_TO_RESTORE; i++) {
ptp_dte->reg_val[i] =
readl(ptp_dte->regs + (i * sizeof(u32)));
}
writel(0, ptp_dte->regs + DTE_NCO_INC_REG);
return 0;
}
static int ptp_dte_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ptp_dte *ptp_dte = platform_get_drvdata(pdev);
u8 i;
for (i = 0; i < DTE_NUM_REGS_TO_RESTORE; i++) {
if ((i * sizeof(u32)) != DTE_NCO_OVERFLOW_REG)
writel(ptp_dte->reg_val[i],
(ptp_dte->regs + (i * sizeof(u32))));
else
writel(((ptp_dte->reg_val[i] &
DTE_NCO_SUM3_MASK) << DTE_NCO_SUM3_WR_SHIFT),
(ptp_dte->regs + (i * sizeof(u32))));
}
return 0;
}
