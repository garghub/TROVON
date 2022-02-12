static inline bool is_suspending(void)
{
return (suspend_state != PM_SUSPEND_ON);
}
static inline bool is_suspending(void)
{
return false;
}
static int omap2_fclks_active(void)
{
u32 f1, f2;
f1 = omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
f2 = omap2_cm_read_mod_reg(CORE_MOD, OMAP24XX_CM_FCLKEN2);
f1 &= ~(OMAP24XX_EN_UART1_MASK | OMAP24XX_EN_UART2_MASK);
f2 &= ~OMAP24XX_EN_UART3_MASK;
if (f1 | f2)
return 1;
return 0;
}
static void omap2_enter_full_retention(void)
{
u32 l;
clk_disable(osc_ck);
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, PM_WKST1);
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, OMAP24XX_PM_WKST2);
omap2_prm_write_mod_reg(0xffffffff, WKUP_MOD, PM_WKST);
pwrdm_set_logic_retst(mpu_pwrdm, PWRDM_POWER_RET);
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_RET);
l = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0) | OMAP24XX_USBSTANDBYCTRL;
omap_ctrl_writel(l, OMAP2_CONTROL_DEVCONF0);
omap2_gpio_prepare_for_idle(0);
if (omap_irq_pending())
goto no_sleep;
if (!is_suspending())
if (!console_trylock())
goto no_sleep;
omap_uart_prepare_idle(0);
omap_uart_prepare_idle(1);
omap_uart_prepare_idle(2);
omap2_sram_suspend(sdrc_read_reg(SDRC_DLLA_CTRL),
OMAP_SDRC_REGADDR(SDRC_DLLA_CTRL),
OMAP_SDRC_REGADDR(SDRC_POWER));
omap_uart_resume_idle(2);
omap_uart_resume_idle(1);
omap_uart_resume_idle(0);
if (!is_suspending())
console_unlock();
no_sleep:
omap2_gpio_resume_after_idle();
clk_enable(osc_ck);
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, PM_WKST1);
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, OMAP24XX_PM_WKST2);
omap2_prm_clear_mod_reg_bits(0x4 | 0x1, WKUP_MOD, PM_WKST);
l = omap2_prm_read_mod_reg(OCP_MOD, OMAP2_PRCM_IRQSTATUS_MPU_OFFSET);
if (l & 0x01)
omap2_prm_write_mod_reg(0x01, OCP_MOD,
OMAP2_PRCM_IRQSTATUS_MPU_OFFSET);
if (l & 0x20)
omap2_prm_write_mod_reg(0x20, OCP_MOD,
OMAP2_PRCM_IRQSTATUS_MPU_OFFSET);
omap2_prm_write_mod_reg(0x0, OCP_MOD, OMAP2_PRCM_IRQSTATUS_MPU_OFFSET);
}
static int omap2_i2c_active(void)
{
u32 l;
l = omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
return l & (OMAP2420_EN_I2C2_MASK | OMAP2420_EN_I2C1_MASK);
}
static int omap2_allow_mpu_retention(void)
{
u32 l;
l = omap2_cm_read_mod_reg(CORE_MOD, CM_FCLKEN1);
if (l & (OMAP2420_EN_MMC_MASK | OMAP24XX_EN_UART2_MASK |
OMAP24XX_EN_UART1_MASK | OMAP24XX_EN_MCSPI2_MASK |
OMAP24XX_EN_MCSPI1_MASK | OMAP24XX_EN_DSS1_MASK))
return 0;
l = omap2_cm_read_mod_reg(CORE_MOD, OMAP24XX_CM_FCLKEN2);
if (l & OMAP24XX_EN_UART3_MASK)
return 0;
if (sti_console_enabled)
return 0;
return 1;
}
static void omap2_enter_mpu_retention(void)
{
int only_idle = 0;
if (omap2_i2c_active())
return;
if (omap2_allow_mpu_retention()) {
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, PM_WKST1);
omap2_prm_write_mod_reg(0xffffffff, CORE_MOD, OMAP24XX_PM_WKST2);
omap2_prm_write_mod_reg(0xffffffff, WKUP_MOD, PM_WKST);
omap2_prm_write_mod_reg((0x01 << OMAP_POWERSTATE_SHIFT) |
OMAP_LOGICRETSTATE_MASK,
MPU_MOD, OMAP2_PM_PWSTCTRL);
} else {
omap2_prm_write_mod_reg(OMAP_LOGICRETSTATE_MASK, MPU_MOD,
OMAP2_PM_PWSTCTRL);
only_idle = 1;
}
omap2_sram_idle();
}
static int omap2_can_sleep(void)
{
if (omap2_fclks_active())
return 0;
if (!omap_uart_can_sleep())
return 0;
if (osc_ck->usecount > 1)
return 0;
if (omap_dma_running())
return 0;
return 1;
}
static void omap2_pm_idle(void)
{
local_irq_disable();
local_fiq_disable();
if (!omap2_can_sleep()) {
if (omap_irq_pending())
goto out;
omap2_enter_mpu_retention();
goto out;
}
if (omap_irq_pending())
goto out;
omap2_enter_full_retention();
out:
local_fiq_enable();
local_irq_enable();
}
static int omap2_pm_begin(suspend_state_t state)
{
disable_hlt();
suspend_state = state;
return 0;
}
static int omap2_pm_suspend(void)
{
u32 wken_wkup, mir1;
wken_wkup = omap2_prm_read_mod_reg(WKUP_MOD, PM_WKEN);
wken_wkup &= ~OMAP24XX_EN_GPT1_MASK;
omap2_prm_write_mod_reg(wken_wkup, WKUP_MOD, PM_WKEN);
mir1 = omap_readl(0x480fe0a4);
omap_writel(1 << 5, 0x480fe0ac);
omap_uart_prepare_suspend();
omap2_enter_full_retention();
omap_writel(mir1, 0x480fe0a4);
omap2_prm_write_mod_reg(wken_wkup, WKUP_MOD, PM_WKEN);
return 0;
}
static int omap2_pm_enter(suspend_state_t state)
{
int ret = 0;
switch (state) {
case PM_SUSPEND_STANDBY:
case PM_SUSPEND_MEM:
ret = omap2_pm_suspend();
break;
default:
ret = -EINVAL;
}
return ret;
}
static void omap2_pm_end(void)
{
suspend_state = PM_SUSPEND_ON;
enable_hlt();
}
static int __init clkdms_setup(struct clockdomain *clkdm, void *unused)
{
if (clkdm->flags & CLKDM_CAN_ENABLE_AUTO)
clkdm_allow_idle(clkdm);
else if (clkdm->flags & CLKDM_CAN_FORCE_SLEEP &&
atomic_read(&clkdm->usecount) == 0)
clkdm_sleep(clkdm);
return 0;
}
static void __init prcm_setup_regs(void)
{
int i, num_mem_banks;
struct powerdomain *pwrdm;
omap2_prm_write_mod_reg(OMAP24XX_AUTOIDLE_MASK, OCP_MOD,
OMAP2_PRCM_SYSCONFIG_OFFSET);
num_mem_banks = pwrdm_get_mem_bank_count(core_pwrdm);
for (i = 0; i < num_mem_banks; i++)
pwrdm_set_mem_retst(core_pwrdm, i, PWRDM_POWER_RET);
pwrdm_set_next_pwrst(core_pwrdm, PWRDM_POWER_RET);
pwrdm_set_logic_retst(mpu_pwrdm, PWRDM_POWER_RET);
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_RET);
pwrdm = clkdm_get_pwrdm(dsp_clkdm);
pwrdm_set_next_pwrst(pwrdm, PWRDM_POWER_OFF);
clkdm_sleep(dsp_clkdm);
pwrdm = clkdm_get_pwrdm(gfx_clkdm);
pwrdm_set_next_pwrst(pwrdm, PWRDM_POWER_OFF);
clkdm_sleep(gfx_clkdm);
clkdm_for_each(clkdms_setup, NULL);
clkdm_add_wkdep(mpu_clkdm, wkup_clkdm);
omap2_prm_write_mod_reg(15 << OMAP_SETUP_TIME_SHIFT, OMAP24XX_GR_MOD,
OMAP2_PRCM_CLKSSETUP_OFFSET);
omap2_prm_write_mod_reg(2 << OMAP_SETUP_TIME_SHIFT, OMAP24XX_GR_MOD,
OMAP2_PRCM_VOLTSETUP_OFFSET);
omap2_prm_write_mod_reg(OMAP24XX_AUTO_EXTVOLT_MASK |
(0x1 << OMAP24XX_SETOFF_LEVEL_SHIFT) |
OMAP24XX_MEMRETCTRL_MASK |
(0x1 << OMAP24XX_SETRET_LEVEL_SHIFT) |
(0x0 << OMAP24XX_VOLT_LEVEL_SHIFT),
OMAP24XX_GR_MOD, OMAP2_PRCM_VOLTCTRL_OFFSET);
omap2_prm_write_mod_reg(OMAP24XX_EN_GPIOS_MASK | OMAP24XX_EN_GPT1_MASK,
WKUP_MOD, PM_WKEN);
}
static int __init omap2_pm_init(void)
{
u32 l;
if (!cpu_is_omap24xx())
return -ENODEV;
printk(KERN_INFO "Power Management for OMAP2 initializing\n");
l = omap2_prm_read_mod_reg(OCP_MOD, OMAP2_PRCM_REVISION_OFFSET);
printk(KERN_INFO "PRCM revision %d.%d\n", (l >> 4) & 0x0f, l & 0x0f);
mpu_pwrdm = pwrdm_lookup("mpu_pwrdm");
if (!mpu_pwrdm)
pr_err("PM: mpu_pwrdm not found\n");
core_pwrdm = pwrdm_lookup("core_pwrdm");
if (!core_pwrdm)
pr_err("PM: core_pwrdm not found\n");
mpu_clkdm = clkdm_lookup("mpu_clkdm");
if (!mpu_clkdm)
pr_err("PM: mpu_clkdm not found\n");
wkup_clkdm = clkdm_lookup("wkup_clkdm");
if (!wkup_clkdm)
pr_err("PM: wkup_clkdm not found\n");
dsp_clkdm = clkdm_lookup("dsp_clkdm");
if (!dsp_clkdm)
pr_err("PM: dsp_clkdm not found\n");
gfx_clkdm = clkdm_lookup("gfx_clkdm");
if (!gfx_clkdm)
pr_err("PM: gfx_clkdm not found\n");
osc_ck = clk_get(NULL, "osc_ck");
if (IS_ERR(osc_ck)) {
printk(KERN_ERR "could not get osc_ck\n");
return -ENODEV;
}
if (cpu_is_omap242x()) {
emul_ck = clk_get(NULL, "emul_ck");
if (IS_ERR(emul_ck)) {
printk(KERN_ERR "could not get emul_ck\n");
clk_put(osc_ck);
return -ENODEV;
}
}
prcm_setup_regs();
{
const struct omap_sti_console_config *sti;
sti = omap_get_config(OMAP_TAG_STI_CONSOLE,
struct omap_sti_console_config);
if (sti != NULL && sti->enable)
sti_console_enabled = 1;
}
if (cpu_is_omap24xx()) {
omap2_sram_idle = omap_sram_push(omap24xx_idle_loop_suspend,
omap24xx_idle_loop_suspend_sz);
omap2_sram_suspend = omap_sram_push(omap24xx_cpu_suspend,
omap24xx_cpu_suspend_sz);
}
suspend_set_ops(&omap_pm_ops);
pm_idle = omap2_pm_idle;
return 0;
}
