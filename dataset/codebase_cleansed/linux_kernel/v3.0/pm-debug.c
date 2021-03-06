void omap2_pm_dump(int mode, int resume, unsigned int us)
{
struct reg {
const char *name;
u32 val;
} regs[32];
int reg_count = 0, i;
const char *s1 = NULL, *s2 = NULL;
if (!resume) {
#if 0
DUMP_PRM_MOD_REG(OCP_MOD, OMAP2_PRM_IRQENABLE_MPU_OFFSET);
DUMP_CM_MOD_REG(MPU_MOD, OMAP2_CM_CLKSTCTRL);
DUMP_PRM_MOD_REG(MPU_MOD, OMAP2_PM_PWSTCTRL);
DUMP_PRM_MOD_REG(MPU_MOD, OMAP2_PM_PWSTST);
DUMP_PRM_MOD_REG(MPU_MOD, PM_WKDEP);
#endif
#if 0
DUMP_INTC_REG(INTC_MIR0, 0x0084);
DUMP_INTC_REG(INTC_MIR1, 0x00a4);
DUMP_INTC_REG(INTC_MIR2, 0x00c4);
#endif
#if 0
DUMP_CM_MOD_REG(CORE_MOD, CM_FCLKEN1);
if (cpu_is_omap24xx()) {
DUMP_CM_MOD_REG(CORE_MOD, OMAP24XX_CM_FCLKEN2);
DUMP_PRM_MOD_REG(OMAP24XX_GR_MOD,
OMAP2_PRCM_CLKEMUL_CTRL_OFFSET);
DUMP_PRM_MOD_REG(OMAP24XX_GR_MOD,
OMAP2_PRCM_CLKSRC_CTRL_OFFSET);
}
DUMP_CM_MOD_REG(WKUP_MOD, CM_FCLKEN);
DUMP_CM_MOD_REG(CORE_MOD, CM_ICLKEN1);
DUMP_CM_MOD_REG(CORE_MOD, CM_ICLKEN2);
DUMP_CM_MOD_REG(WKUP_MOD, CM_ICLKEN);
DUMP_CM_MOD_REG(PLL_MOD, CM_CLKEN);
DUMP_CM_MOD_REG(PLL_MOD, CM_AUTOIDLE);
DUMP_PRM_MOD_REG(CORE_MOD, OMAP2_PM_PWSTST);
#endif
#if 0
if (cpu_is_omap24xx()) {
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_FCLKEN);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_ICLKEN);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_IDLEST);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_AUTOIDLE);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_CLKSEL);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_CM_CLKSTCTRL);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_RM_RSTCTRL);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_RM_RSTST);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_PM_PWSTCTRL);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_PM_PWSTST);
}
#endif
} else {
DUMP_PRM_MOD_REG(CORE_MOD, PM_WKST1);
if (cpu_is_omap24xx())
DUMP_PRM_MOD_REG(CORE_MOD, OMAP24XX_PM_WKST2);
DUMP_PRM_MOD_REG(WKUP_MOD, PM_WKST);
DUMP_PRM_MOD_REG(OCP_MOD, OMAP2_PRCM_IRQSTATUS_MPU_OFFSET);
#if 1
DUMP_INTC_REG(INTC_PENDING_IRQ0, 0x0098);
DUMP_INTC_REG(INTC_PENDING_IRQ1, 0x00b8);
DUMP_INTC_REG(INTC_PENDING_IRQ2, 0x00d8);
#endif
}
switch (mode) {
case 0:
s1 = "full";
s2 = "retention";
break;
case 1:
s1 = "MPU";
s2 = "retention";
break;
case 2:
s1 = "MPU";
s2 = "idle";
break;
}
if (!resume)
#ifdef CONFIG_NO_HZ
printk(KERN_INFO
"--- Going to %s %s (next timer after %u ms)\n", s1, s2,
jiffies_to_msecs(get_next_timer_interrupt(jiffies) -
jiffies));
#else
printk(KERN_INFO "--- Going to %s %s\n", s1, s2);
#endif
else
printk(KERN_INFO "--- Woke up (slept for %u.%03u ms)\n",
us / 1000, us % 1000);
for (i = 0; i < reg_count; i++)
printk(KERN_INFO "%-20s: 0x%08x\n", regs[i].name, regs[i].val);
}
void omap2_pm_wakeup_on_timer(u32 seconds, u32 milliseconds)
{
u32 tick_rate, cycles;
if (!seconds && !milliseconds)
return;
tick_rate = clk_get_rate(omap_dm_timer_get_fclk(gptimer_wakeup));
cycles = tick_rate * seconds + tick_rate * milliseconds / 1000;
omap_dm_timer_stop(gptimer_wakeup);
omap_dm_timer_set_load_start(gptimer_wakeup, 0, 0xffffffff - cycles);
pr_info("PM: Resume timer in %u.%03u secs"
" (%d ticks at %d ticks/sec.)\n",
seconds, milliseconds, cycles, tick_rate);
}
static int pm_dbg_get_regset_size(void)
{
static int regset_size;
if (regset_size == 0) {
int i = 0;
while (pm_dbg_reg_modules[i].name[0] != 0) {
regset_size += pm_dbg_reg_modules[i].high +
4 - pm_dbg_reg_modules[i].low;
i++;
}
}
return regset_size;
}
static int pm_dbg_show_regs(struct seq_file *s, void *unused)
{
int i, j;
unsigned long val;
int reg_set = (int)s->private;
u32 *ptr;
void *store = NULL;
int regs;
int linefeed;
if (reg_set == 0) {
store = kmalloc(pm_dbg_get_regset_size(), GFP_KERNEL);
ptr = store;
pm_dbg_regset_store(ptr);
} else {
ptr = pm_dbg_reg_set[reg_set - 1];
}
i = 0;
while (pm_dbg_reg_modules[i].name[0] != 0) {
regs = 0;
linefeed = 0;
if (pm_dbg_reg_modules[i].type == MOD_CM)
seq_printf(s, "MOD: CM_%s (%08x)\n",
pm_dbg_reg_modules[i].name,
(u32)(OMAP3430_CM_BASE +
pm_dbg_reg_modules[i].offset));
else
seq_printf(s, "MOD: PRM_%s (%08x)\n",
pm_dbg_reg_modules[i].name,
(u32)(OMAP3430_PRM_BASE +
pm_dbg_reg_modules[i].offset));
for (j = pm_dbg_reg_modules[i].low;
j <= pm_dbg_reg_modules[i].high; j += 4) {
val = *(ptr++);
if (val != 0) {
regs++;
if (linefeed) {
seq_printf(s, "\n");
linefeed = 0;
}
seq_printf(s, " %02x => %08lx", j, val);
if (regs % 4 == 0)
linefeed = 1;
}
}
seq_printf(s, "\n");
i++;
}
if (store != NULL)
kfree(store);
return 0;
}
static void pm_dbg_regset_store(u32 *ptr)
{
int i, j;
u32 val;
i = 0;
while (pm_dbg_reg_modules[i].name[0] != 0) {
for (j = pm_dbg_reg_modules[i].low;
j <= pm_dbg_reg_modules[i].high; j += 4) {
if (pm_dbg_reg_modules[i].type == MOD_CM)
val = omap2_cm_read_mod_reg(
pm_dbg_reg_modules[i].offset, j);
else
val = omap2_prm_read_mod_reg(
pm_dbg_reg_modules[i].offset, j);
*(ptr++) = val;
}
i++;
}
}
int pm_dbg_regset_save(int reg_set)
{
if (pm_dbg_reg_set[reg_set-1] == NULL)
return -EINVAL;
pm_dbg_regset_store(pm_dbg_reg_set[reg_set-1]);
return 0;
}
void pm_dbg_update_time(struct powerdomain *pwrdm, int prev)
{
s64 t;
if (!pm_dbg_init_done)
return ;
t = sched_clock();
pwrdm->state_timer[prev] += t - pwrdm->timer;
pwrdm->timer = t;
}
static int clkdm_dbg_show_counter(struct clockdomain *clkdm, void *user)
{
struct seq_file *s = (struct seq_file *)user;
if (strcmp(clkdm->name, "emu_clkdm") == 0 ||
strcmp(clkdm->name, "wkup_clkdm") == 0 ||
strncmp(clkdm->name, "dpll", 4) == 0)
return 0;
seq_printf(s, "%s->%s (%d)", clkdm->name,
clkdm->pwrdm.ptr->name,
atomic_read(&clkdm->usecount));
seq_printf(s, "\n");
return 0;
}
static int pwrdm_dbg_show_counter(struct powerdomain *pwrdm, void *user)
{
struct seq_file *s = (struct seq_file *)user;
int i;
if (strcmp(pwrdm->name, "emu_pwrdm") == 0 ||
strcmp(pwrdm->name, "wkup_pwrdm") == 0 ||
strncmp(pwrdm->name, "dpll", 4) == 0)
return 0;
if (pwrdm->state != pwrdm_read_pwrst(pwrdm))
printk(KERN_ERR "pwrdm state mismatch(%s) %d != %d\n",
pwrdm->name, pwrdm->state, pwrdm_read_pwrst(pwrdm));
seq_printf(s, "%s (%s)", pwrdm->name,
pwrdm_state_names[pwrdm->state]);
for (i = 0; i < PWRDM_MAX_PWRSTS; i++)
seq_printf(s, ",%s:%d", pwrdm_state_names[i],
pwrdm->state_counter[i]);
seq_printf(s, ",RET-LOGIC-OFF:%d", pwrdm->ret_logic_off_counter);
for (i = 0; i < pwrdm->banks; i++)
seq_printf(s, ",RET-MEMBANK%d-OFF:%d", i + 1,
pwrdm->ret_mem_off_counter[i]);
seq_printf(s, "\n");
return 0;
}
static int pwrdm_dbg_show_timer(struct powerdomain *pwrdm, void *user)
{
struct seq_file *s = (struct seq_file *)user;
int i;
if (strcmp(pwrdm->name, "emu_pwrdm") == 0 ||
strcmp(pwrdm->name, "wkup_pwrdm") == 0 ||
strncmp(pwrdm->name, "dpll", 4) == 0)
return 0;
pwrdm_state_switch(pwrdm);
seq_printf(s, "%s (%s)", pwrdm->name,
pwrdm_state_names[pwrdm->state]);
for (i = 0; i < 4; i++)
seq_printf(s, ",%s:%lld", pwrdm_state_names[i],
pwrdm->state_timer[i]);
seq_printf(s, "\n");
return 0;
}
static int pm_dbg_show_counters(struct seq_file *s, void *unused)
{
pwrdm_for_each(pwrdm_dbg_show_counter, s);
clkdm_for_each(clkdm_dbg_show_counter, s);
return 0;
}
static int pm_dbg_show_timers(struct seq_file *s, void *unused)
{
pwrdm_for_each(pwrdm_dbg_show_timer, s);
return 0;
}
static int pm_dbg_open(struct inode *inode, struct file *file)
{
switch ((int)inode->i_private) {
case DEBUG_FILE_COUNTERS:
return single_open(file, pm_dbg_show_counters,
&inode->i_private);
case DEBUG_FILE_TIMERS:
default:
return single_open(file, pm_dbg_show_timers,
&inode->i_private);
};
}
static int pm_dbg_reg_open(struct inode *inode, struct file *file)
{
return single_open(file, pm_dbg_show_regs, inode->i_private);
}
int pm_dbg_regset_init(int reg_set)
{
char name[2];
if (!pm_dbg_init_done)
pm_dbg_init();
if (reg_set < 1 || reg_set > PM_DBG_MAX_REG_SETS ||
pm_dbg_reg_set[reg_set-1] != NULL)
return -EINVAL;
pm_dbg_reg_set[reg_set-1] =
kmalloc(pm_dbg_get_regset_size(), GFP_KERNEL);
if (pm_dbg_reg_set[reg_set-1] == NULL)
return -ENOMEM;
if (pm_dbg_dir != NULL) {
sprintf(name, "%d", reg_set);
(void) debugfs_create_file(name, S_IRUGO,
pm_dbg_dir, (void *)reg_set, &debug_reg_fops);
}
return 0;
}
static int pwrdm_suspend_get(void *data, u64 *val)
{
int ret = -EINVAL;
if (cpu_is_omap34xx())
ret = omap3_pm_get_suspend_state((struct powerdomain *)data);
*val = ret;
if (ret >= 0)
return 0;
return *val;
}
static int pwrdm_suspend_set(void *data, u64 val)
{
if (cpu_is_omap34xx())
return omap3_pm_set_suspend_state(
(struct powerdomain *)data, (int)val);
return -EINVAL;
}
static int __init pwrdms_setup(struct powerdomain *pwrdm, void *dir)
{
int i;
s64 t;
struct dentry *d;
t = sched_clock();
for (i = 0; i < 4; i++)
pwrdm->state_timer[i] = 0;
pwrdm->timer = t;
if (strncmp(pwrdm->name, "dpll", 4) == 0)
return 0;
d = debugfs_create_dir(pwrdm->name, (struct dentry *)dir);
(void) debugfs_create_file("suspend", S_IRUGO|S_IWUSR, d,
(void *)pwrdm, &pwrdm_suspend_fops);
return 0;
}
static int option_get(void *data, u64 *val)
{
u32 *option = data;
*val = *option;
return 0;
}
static int option_set(void *data, u64 val)
{
u32 *option = data;
if (option == &wakeup_timer_milliseconds && val >= 1000)
return -EINVAL;
*option = val;
if (option == &enable_off_mode) {
if (val)
omap_pm_enable_off_mode();
else
omap_pm_disable_off_mode();
if (cpu_is_omap34xx())
omap3_pm_off_mode_enable(val);
}
return 0;
}
static int pm_dbg_init(void)
{
int i;
struct dentry *d;
char name[2];
if (pm_dbg_init_done)
return 0;
if (cpu_is_omap34xx())
pm_dbg_reg_modules = omap3_pm_reg_modules;
else {
printk(KERN_ERR "%s: only OMAP3 supported\n", __func__);
return -ENODEV;
}
d = debugfs_create_dir("pm_debug", NULL);
if (IS_ERR(d))
return PTR_ERR(d);
(void) debugfs_create_file("count", S_IRUGO,
d, (void *)DEBUG_FILE_COUNTERS, &debug_fops);
(void) debugfs_create_file("time", S_IRUGO,
d, (void *)DEBUG_FILE_TIMERS, &debug_fops);
pwrdm_for_each(pwrdms_setup, (void *)d);
pm_dbg_dir = debugfs_create_dir("registers", d);
if (IS_ERR(pm_dbg_dir))
return PTR_ERR(pm_dbg_dir);
(void) debugfs_create_file("current", S_IRUGO,
pm_dbg_dir, (void *)0, &debug_reg_fops);
for (i = 0; i < PM_DBG_MAX_REG_SETS; i++)
if (pm_dbg_reg_set[i] != NULL) {
sprintf(name, "%d", i+1);
(void) debugfs_create_file(name, S_IRUGO,
pm_dbg_dir, (void *)(i+1), &debug_reg_fops);
}
(void) debugfs_create_file("enable_off_mode", S_IRUGO | S_IWUSR, d,
&enable_off_mode, &pm_dbg_option_fops);
(void) debugfs_create_file("sleep_while_idle", S_IRUGO | S_IWUSR, d,
&sleep_while_idle, &pm_dbg_option_fops);
(void) debugfs_create_file("wakeup_timer_seconds", S_IRUGO | S_IWUSR, d,
&wakeup_timer_seconds, &pm_dbg_option_fops);
(void) debugfs_create_file("wakeup_timer_milliseconds",
S_IRUGO | S_IWUSR, d, &wakeup_timer_milliseconds,
&pm_dbg_option_fops);
pm_dbg_init_done = 1;
return 0;
}
