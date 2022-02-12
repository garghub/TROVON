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
return 0;
}
pmc_write(PWRGATE_TOGGLE_START | id, PWRGATE_TOGGLE);
spin_unlock_irqrestore(&tegra_powergate_lock, flags);
return 0;
}
int tegra_powergate_power_on(int id)
{
if (id < 0 || id >= tegra_num_powerdomains)
return -EINVAL;
return tegra_powergate_set(id, true);
}
int tegra_powergate_power_off(int id)
{
if (id < 0 || id >= tegra_num_powerdomains)
return -EINVAL;
return tegra_powergate_set(id, false);
}
int tegra_powergate_is_powered(int id)
{
u32 status;
if (id < 0 || id >= tegra_num_powerdomains)
return -EINVAL;
status = pmc_read(PWRGATE_STATUS) & (1 << id);
return !!status;
}
int tegra_powergate_remove_clamping(int id)
{
u32 mask;
if (id < 0 || id >= tegra_num_powerdomains)
return -EINVAL;
if (tegra_chip_id == TEGRA124) {
if (id == TEGRA_POWERGATE_3D) {
pmc_write(0, GPU_RG_CNTRL);
return 0;
}
}
if (id == TEGRA_POWERGATE_VDEC)
mask = (1 << TEGRA_POWERGATE_PCIE);
else if (id == TEGRA_POWERGATE_PCIE)
mask = (1 << TEGRA_POWERGATE_VDEC);
else
mask = (1 << id);
pmc_write(mask, REMOVE_CLAMPING);
return 0;
}
int tegra_powergate_sequence_power_up(int id, struct clk *clk,
struct reset_control *rst)
{
int ret;
reset_control_assert(rst);
ret = tegra_powergate_power_on(id);
if (ret)
goto err_power;
ret = clk_prepare_enable(clk);
if (ret)
goto err_clk;
udelay(10);
ret = tegra_powergate_remove_clamping(id);
if (ret)
goto err_clamp;
udelay(10);
reset_control_deassert(rst);
return 0;
err_clamp:
clk_disable_unprepare(clk);
err_clk:
tegra_powergate_power_off(id);
err_power:
return ret;
}
int tegra_cpu_powergate_id(int cpuid)
{
if (cpuid > 0 && cpuid < tegra_num_cpu_domains)
return tegra_cpu_domains[cpuid];
return -EINVAL;
}
int __init tegra_powergate_init(void)
{
switch (tegra_chip_id) {
case TEGRA20:
tegra_num_powerdomains = 7;
break;
case TEGRA30:
tegra_num_powerdomains = 14;
tegra_num_cpu_domains = 4;
tegra_cpu_domains = tegra30_cpu_domains;
break;
case TEGRA114:
tegra_num_powerdomains = 23;
tegra_num_cpu_domains = 4;
tegra_cpu_domains = tegra114_cpu_domains;
break;
case TEGRA124:
tegra_num_powerdomains = 25;
tegra_num_cpu_domains = 4;
tegra_cpu_domains = tegra124_cpu_domains;
break;
default:
tegra_num_powerdomains = 0;
break;
}
return 0;
}
static int powergate_show(struct seq_file *s, void *data)
{
int i;
seq_printf(s, " powergate powered\n");
seq_printf(s, "------------------\n");
for (i = 0; i < tegra_num_powerdomains; i++) {
if (!powergate_name[i])
continue;
seq_printf(s, " %9s %7s\n", powergate_name[i],
tegra_powergate_is_powered(i) ? "yes" : "no");
}
return 0;
}
static int powergate_open(struct inode *inode, struct file *file)
{
return single_open(file, powergate_show, inode->i_private);
}
int __init tegra_powergate_debugfs_init(void)
{
struct dentry *d;
switch (tegra_chip_id) {
case TEGRA20:
powergate_name = powergate_name_t20;
break;
case TEGRA30:
powergate_name = powergate_name_t30;
break;
case TEGRA114:
powergate_name = powergate_name_t114;
break;
case TEGRA124:
powergate_name = powergate_name_t124;
break;
}
if (powergate_name) {
d = debugfs_create_file("powergate", S_IRUGO, NULL, NULL,
&powergate_fops);
if (!d)
return -ENOMEM;
}
return 0;
}
static int tegra_io_rail_prepare(int id, unsigned long *request,
unsigned long *status, unsigned int *bit)
{
unsigned long rate, value;
struct clk *clk;
*bit = id % 32;
if (id > 63 || *bit == 30 || *bit == 31)
return -EINVAL;
if (id < 32) {
*status = IO_DPD_STATUS;
*request = IO_DPD_REQ;
} else {
*status = IO_DPD2_STATUS;
*request = IO_DPD2_REQ;
}
clk = clk_get_sys(NULL, "pclk");
if (IS_ERR(clk))
return PTR_ERR(clk);
rate = clk_get_rate(clk);
clk_put(clk);
pmc_write(DPD_SAMPLE_ENABLE, DPD_SAMPLE);
value = DIV_ROUND_UP(1000000000, rate);
value = DIV_ROUND_UP(200, value);
pmc_write(value, SEL_DPD_TIM);
return 0;
}
static int tegra_io_rail_poll(unsigned long offset, unsigned long mask,
unsigned long val, unsigned long timeout)
{
unsigned long value;
timeout = jiffies + msecs_to_jiffies(timeout);
while (time_after(timeout, jiffies)) {
value = pmc_read(offset);
if ((value & mask) == val)
return 0;
usleep_range(250, 1000);
}
return -ETIMEDOUT;
}
static void tegra_io_rail_unprepare(void)
{
pmc_write(DPD_SAMPLE_DISABLE, DPD_SAMPLE);
}
int tegra_io_rail_power_on(int id)
{
unsigned long request, status, value;
unsigned int bit, mask;
int err;
err = tegra_io_rail_prepare(id, &request, &status, &bit);
if (err < 0)
return err;
mask = 1 << bit;
value = pmc_read(request);
value |= mask;
value &= ~IO_DPD_REQ_CODE_MASK;
value |= IO_DPD_REQ_CODE_OFF;
pmc_write(value, request);
err = tegra_io_rail_poll(status, mask, 0, 250);
if (err < 0)
return err;
tegra_io_rail_unprepare();
return 0;
}
int tegra_io_rail_power_off(int id)
{
unsigned long request, status, value;
unsigned int bit, mask;
int err;
err = tegra_io_rail_prepare(id, &request, &status, &bit);
if (err < 0)
return err;
mask = 1 << bit;
value = pmc_read(request);
value |= mask;
value &= ~IO_DPD_REQ_CODE_MASK;
value |= IO_DPD_REQ_CODE_ON;
pmc_write(value, request);
err = tegra_io_rail_poll(status, mask, mask, 250);
if (err < 0)
return err;
tegra_io_rail_unprepare();
return 0;
}
