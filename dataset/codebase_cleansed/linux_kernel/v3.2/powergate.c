static u32 pmc_read(unsigned long reg)
{
return readl(pmc + reg);
}
static void pmc_write(u32 val, unsigned long reg)
{
writel(val, pmc + reg);
}
static int tegra_powergate_set(int id, bool new_state)
{
bool status;
unsigned long flags;
spin_lock_irqsave(&tegra_powergate_lock, flags);
status = pmc_read(PWRGATE_STATUS) & (1 << id);
if (status == new_state) {
spin_unlock_irqrestore(&tegra_powergate_lock, flags);
return -EINVAL;
}
pmc_write(PWRGATE_TOGGLE_START | id, PWRGATE_TOGGLE);
spin_unlock_irqrestore(&tegra_powergate_lock, flags);
return 0;
}
int tegra_powergate_power_on(int id)
{
if (id < 0 || id >= TEGRA_NUM_POWERGATE)
return -EINVAL;
return tegra_powergate_set(id, true);
}
int tegra_powergate_power_off(int id)
{
if (id < 0 || id >= TEGRA_NUM_POWERGATE)
return -EINVAL;
return tegra_powergate_set(id, false);
}
static bool tegra_powergate_is_powered(int id)
{
u32 status;
WARN_ON(id < 0 || id >= TEGRA_NUM_POWERGATE);
status = pmc_read(PWRGATE_STATUS) & (1 << id);
return !!status;
}
int tegra_powergate_remove_clamping(int id)
{
u32 mask;
if (id < 0 || id >= TEGRA_NUM_POWERGATE)
return -EINVAL;
if (id == TEGRA_POWERGATE_VDEC)
mask = (1 << TEGRA_POWERGATE_PCIE);
else if (id == TEGRA_POWERGATE_PCIE)
mask = (1 << TEGRA_POWERGATE_VDEC);
else
mask = (1 << id);
pmc_write(mask, REMOVE_CLAMPING);
return 0;
}
int tegra_powergate_sequence_power_up(int id, struct clk *clk)
{
int ret;
tegra_periph_reset_assert(clk);
ret = tegra_powergate_power_on(id);
if (ret)
goto err_power;
ret = clk_enable(clk);
if (ret)
goto err_clk;
udelay(10);
ret = tegra_powergate_remove_clamping(id);
if (ret)
goto err_clamp;
udelay(10);
tegra_periph_reset_deassert(clk);
return 0;
err_clamp:
clk_disable(clk);
err_clk:
tegra_powergate_power_off(id);
err_power:
return ret;
}
static int powergate_show(struct seq_file *s, void *data)
{
int i;
seq_printf(s, " powergate powered\n");
seq_printf(s, "------------------\n");
for (i = 0; i < TEGRA_NUM_POWERGATE; i++)
seq_printf(s, " %9s %7s\n", powergate_name[i],
tegra_powergate_is_powered(i) ? "yes" : "no");
return 0;
}
static int powergate_open(struct inode *inode, struct file *file)
{
return single_open(file, powergate_show, inode->i_private);
}
static int __init powergate_debugfs_init(void)
{
struct dentry *d;
int err = -ENOMEM;
d = debugfs_create_file("powergate", S_IRUGO, NULL, NULL,
&powergate_fops);
if (!d)
return -ENOMEM;
return err;
}
