static int omap2_enter_full_retention(void)
{
u32 l;
clk_disable(osc_ck);
omap_prm_clear_mod_irqs(CORE_MOD, PM_WKST1, ~0);
omap_prm_clear_mod_irqs(CORE_MOD, OMAP24XX_PM_WKST2, ~0);
omap_prm_clear_mod_irqs(WKUP_MOD, PM_WKST, ~0);
pwrdm_set_next_pwrst(core_pwrdm, PWRDM_POWER_RET);
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_RET);
l = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0) | OMAP24XX_USBSTANDBYCTRL;
omap_ctrl_writel(l, OMAP2_CONTROL_DEVCONF0);
omap2_gpio_prepare_for_idle(0);
if (omap_irq_pending())
goto no_sleep;
omap2_sram_suspend(sdrc_read_reg(SDRC_DLLA_CTRL),
OMAP_SDRC_REGADDR(SDRC_DLLA_CTRL),
OMAP_SDRC_REGADDR(SDRC_POWER));
no_sleep:
omap2_gpio_resume_after_idle();
clk_enable(osc_ck);
omap_prm_clear_mod_irqs(CORE_MOD, PM_WKST1, ~0);
omap_prm_clear_mod_irqs(CORE_MOD, OMAP24XX_PM_WKST2, ~0);
omap_prm_clear_mod_irqs(WKUP_MOD, PM_WKST, 0x4 | 0x1);
omap_prm_clear_mod_irqs(OCP_MOD, OMAP2_PRCM_IRQSTATUS_MPU_OFFSET, 0x1);
omap_prm_clear_mod_irqs(OCP_MOD, OMAP2_PRCM_IRQSTATUS_MPU_OFFSET, 0x20);
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_ON);
pwrdm_set_next_pwrst(core_pwrdm, PWRDM_POWER_ON);
return 0;
}
static int omap2_allow_mpu_retention(void)
{
if (!omap2xxx_cm_mpu_retention_allowed())
return 0;
if (sti_console_enabled)
return 0;
return 1;
}
static void omap2_enter_mpu_retention(void)
{
const int zero = 0;
if (omap2_allow_mpu_retention()) {
omap_prm_clear_mod_irqs(CORE_MOD, PM_WKST1, ~0);
omap_prm_clear_mod_irqs(CORE_MOD, OMAP24XX_PM_WKST2, ~0);
omap_prm_clear_mod_irqs(WKUP_MOD, PM_WKST, ~0);
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_RET);
} else {
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_ON);
}
asm("mcr p15, 0, %0, c7, c0, 4" : : "r" (zero) : "memory", "cc");
pwrdm_set_next_pwrst(mpu_pwrdm, PWRDM_POWER_ON);
}
static int omap2_can_sleep(void)
{
if (omap2xxx_cm_fclks_active())
return 0;
if (__clk_is_enabled(osc_ck))
return 0;
if (omap_dma_running())
return 0;
return 1;
}
static void omap2_pm_idle(void)
{
if (!omap2_can_sleep()) {
if (omap_irq_pending())
return;
omap2_enter_mpu_retention();
return;
}
if (omap_irq_pending())
return;
omap2_enter_full_retention();
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
pwrdm_set_logic_retst(core_pwrdm, PWRDM_POWER_RET);
pwrdm_set_logic_retst(mpu_pwrdm, PWRDM_POWER_RET);
pwrdm = clkdm_get_pwrdm(dsp_clkdm);
pwrdm_set_next_pwrst(pwrdm, PWRDM_POWER_OFF);
pwrdm = clkdm_get_pwrdm(gfx_clkdm);
pwrdm_set_next_pwrst(pwrdm, PWRDM_POWER_OFF);
clkdm_for_each(omap_pm_clkdms_setup, NULL);
clkdm_add_wkdep(mpu_clkdm, wkup_clkdm);
omap_common_suspend_init(omap2_enter_full_retention);
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
omap2_prm_set_mod_reg_bits(OMAP_AUTOEXTCLKMODE_MASK, OMAP24XX_GR_MOD,
OMAP2_PRCM_CLKSRC_CTRL_OFFSET);
}
int __init omap2_pm_init(void)
{
u32 l;
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
omap2_sram_suspend = omap_sram_push(omap24xx_cpu_suspend,
omap24xx_cpu_suspend_sz);
arm_pm_idle = omap2_pm_idle;
return 0;
}
