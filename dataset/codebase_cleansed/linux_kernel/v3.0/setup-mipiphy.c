static int __s5p_mipi_phy_control(struct platform_device *pdev,
bool on, u32 reset)
{
static DEFINE_SPINLOCK(lock);
void __iomem *addr;
unsigned long flags;
int pid;
u32 cfg;
if (!pdev)
return -EINVAL;
pid = (pdev->id == -1) ? 0 : pdev->id;
if (pid != 0 && pid != 1)
return -EINVAL;
addr = S5P_MIPI_DPHY_CONTROL(pid);
spin_lock_irqsave(&lock, flags);
cfg = __raw_readl(addr);
cfg = on ? (cfg | reset) : (cfg & ~reset);
__raw_writel(cfg, addr);
if (on) {
cfg |= S5P_MIPI_DPHY_ENABLE;
} else if (!(cfg & (S5P_MIPI_DPHY_SRESETN |
S5P_MIPI_DPHY_MRESETN) & ~reset)) {
cfg &= ~S5P_MIPI_DPHY_ENABLE;
}
__raw_writel(cfg, addr);
spin_unlock_irqrestore(&lock, flags);
return 0;
}
int s5p_csis_phy_enable(struct platform_device *pdev, bool on)
{
return __s5p_mipi_phy_control(pdev, on, S5P_MIPI_DPHY_SRESETN);
}
int s5p_dsim_phy_enable(struct platform_device *pdev, bool on)
{
return __s5p_mipi_phy_control(pdev, on, S5P_MIPI_DPHY_MRESETN);
}
