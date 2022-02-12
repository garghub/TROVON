static inline bool cluster_is_a15(u32 cluster)
{
return cluster == info->a15_clusid;
}
void ve_spc_global_wakeup_irq(bool set)
{
u32 reg;
reg = readl_relaxed(info->baseaddr + WAKE_INT_MASK);
if (set)
reg |= GBL_WAKEUP_INT_MSK;
else
reg &= ~GBL_WAKEUP_INT_MSK;
writel_relaxed(reg, info->baseaddr + WAKE_INT_MASK);
}
void ve_spc_cpu_wakeup_irq(u32 cluster, u32 cpu, bool set)
{
u32 mask, reg;
if (cluster >= MAX_CLUSTERS)
return;
mask = 1 << cpu;
if (!cluster_is_a15(cluster))
mask <<= 4;
reg = readl_relaxed(info->baseaddr + WAKE_INT_MASK);
if (set)
reg |= mask;
else
reg &= ~mask;
writel_relaxed(reg, info->baseaddr + WAKE_INT_MASK);
}
void ve_spc_set_resume_addr(u32 cluster, u32 cpu, u32 addr)
{
void __iomem *baseaddr;
if (cluster >= MAX_CLUSTERS)
return;
if (cluster_is_a15(cluster))
baseaddr = info->baseaddr + A15_BX_ADDR0 + (cpu << 2);
else
baseaddr = info->baseaddr + A7_BX_ADDR0 + (cpu << 2);
writel_relaxed(addr, baseaddr);
}
void ve_spc_powerdown(u32 cluster, bool enable)
{
u32 pwdrn_reg;
if (cluster >= MAX_CLUSTERS)
return;
pwdrn_reg = cluster_is_a15(cluster) ? A15_PWRDN_EN : A7_PWRDN_EN;
writel_relaxed(enable, info->baseaddr + pwdrn_reg);
}
int __init ve_spc_init(void __iomem *baseaddr, u32 a15_clusid)
{
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
pr_err(SPCLOG "unable to allocate mem\n");
return -ENOMEM;
}
info->baseaddr = baseaddr;
info->a15_clusid = a15_clusid;
sync_cache_w(info);
sync_cache_w(&info);
return 0;
}
