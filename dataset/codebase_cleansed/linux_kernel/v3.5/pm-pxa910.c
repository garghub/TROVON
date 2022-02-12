int pxa910_set_wake(struct irq_data *data, unsigned int on)
{
int irq = data->irq;
struct irq_desc *desc = irq_to_desc(data->irq);
uint32_t awucrm = 0, apcr = 0;
if (unlikely(irq >= nr_irqs)) {
pr_err("IRQ nubmers are out of boundary!\n");
return -EINVAL;
}
if (on) {
if (desc->action)
desc->action->flags |= IRQF_NO_SUSPEND;
} else {
if (desc->action)
desc->action->flags &= ~IRQF_NO_SUSPEND;
}
switch (irq) {
case IRQ_PXA910_AP_GPIO:
awucrm = MPMU_AWUCRM_WAKEUP(2);
apcr |= MPMU_APCR_SLPWP2;
break;
case IRQ_PXA910_KEYPAD:
awucrm = MPMU_AWUCRM_WAKEUP(3) | MPMU_AWUCRM_KEYPRESS;
apcr |= MPMU_APCR_SLPWP3;
break;
case IRQ_PXA910_ROTARY:
awucrm = MPMU_AWUCRM_WAKEUP(3) | MPMU_AWUCRM_NEWROTARY;
apcr |= MPMU_APCR_SLPWP3;
break;
case IRQ_PXA910_TRACKBALL:
awucrm = MPMU_AWUCRM_WAKEUP(3) | MPMU_AWUCRM_TRACKBALL;
apcr |= MPMU_APCR_SLPWP3;
break;
case IRQ_PXA910_AP1_TIMER1:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_AP1_TIMER_1;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_AP1_TIMER2:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_AP1_TIMER_2;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_AP1_TIMER3:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_AP1_TIMER_3;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_AP2_TIMER1:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_AP2_TIMER_1;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_AP2_TIMER2:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_AP2_TIMER_2;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_AP2_TIMER3:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_AP2_TIMER_3;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_RTC_ALARM:
awucrm = MPMU_AWUCRM_WAKEUP(4) | MPMU_AWUCRM_RTC_ALARM;
apcr |= MPMU_APCR_SLPWP4;
break;
case IRQ_PXA910_USB1:
case IRQ_PXA910_USB2:
awucrm = MPMU_AWUCRM_WAKEUP(5);
apcr |= MPMU_APCR_SLPWP5;
break;
case IRQ_PXA910_MMC:
awucrm = MPMU_AWUCRM_WAKEUP(6)
| MPMU_AWUCRM_SDH1
| MPMU_AWUCRM_SDH2;
apcr |= MPMU_APCR_SLPWP6;
break;
case IRQ_PXA910_PMIC_INT:
awucrm = MPMU_AWUCRM_WAKEUP(7);
apcr |= MPMU_APCR_SLPWP7;
break;
default:
if (irq >= IRQ_GPIO_START && irq < IRQ_BOARD_START) {
awucrm = MPMU_AWUCRM_WAKEUP(2);
apcr |= MPMU_APCR_SLPWP2;
} else
printk(KERN_ERR "Error: no defined wake up source irq: %d\n",
irq);
}
if (on) {
if (awucrm) {
awucrm |= __raw_readl(MPMU_AWUCRM);
__raw_writel(awucrm, MPMU_AWUCRM);
}
if (apcr) {
apcr = ~apcr & __raw_readl(MPMU_APCR);
__raw_writel(apcr, MPMU_APCR);
}
} else {
if (awucrm) {
awucrm = ~awucrm & __raw_readl(MPMU_AWUCRM);
__raw_writel(awucrm, MPMU_AWUCRM);
}
if (apcr) {
apcr |= __raw_readl(MPMU_APCR);
__raw_writel(apcr, MPMU_APCR);
}
}
return 0;
}
void pxa910_pm_enter_lowpower_mode(int state)
{
uint32_t idle_cfg, apcr;
idle_cfg = __raw_readl(APMU_MOH_IDLE_CFG);
apcr = __raw_readl(MPMU_APCR);
apcr &= ~(MPMU_APCR_DDRCORSD | MPMU_APCR_APBSD | MPMU_APCR_AXISD
| MPMU_APCR_VCTCXOSD | MPMU_APCR_STBYEN);
idle_cfg &= ~(APMU_MOH_IDLE_CFG_MOH_IDLE
| APMU_MOH_IDLE_CFG_MOH_PWRDWN);
switch (state) {
case POWER_MODE_UDR:
apcr |= MPMU_APCR_STBYEN | MPMU_APCR_APBSD;
case POWER_MODE_SYS_SLEEP:
apcr |= MPMU_APCR_SLPEN;
apcr |= MPMU_APCR_VCTCXOSD;
case POWER_MODE_APPS_SLEEP:
apcr |= MPMU_APCR_DDRCORSD;
case POWER_MODE_APPS_IDLE:
apcr |= MPMU_APCR_AXISD;
case POWER_MODE_CORE_EXTIDLE:
idle_cfg |= APMU_MOH_IDLE_CFG_MOH_IDLE;
idle_cfg |= APMU_MOH_IDLE_CFG_MOH_PWRDWN;
idle_cfg |= APMU_MOH_IDLE_CFG_MOH_PWR_SW(3)
| APMU_MOH_IDLE_CFG_MOH_L2_PWR_SW(3);
case POWER_MODE_CORE_INTIDLE:
break;
}
idle_cfg |= APMU_MOH_IDLE_CFG_MOH_DIS_MC_SW_REQ;
idle_cfg |= APMU_MOH_IDLE_CFG_MOH_MC_WAKE_EN;
__raw_writel(0x0, APMU_MC_HW_SLP_TYPE);
apcr |= MPMU_APCR_DSPSD | MPMU_APCR_DTCMSD | MPMU_APCR_BBSD
| MPMU_APCR_MSASLPEN;
apcr |= MPMU_APCR_SLPEN;
__raw_writel(idle_cfg, APMU_MOH_IDLE_CFG);
__raw_writel(apcr, MPMU_APCR);
}
static int pxa910_pm_enter(suspend_state_t state)
{
unsigned int idle_cfg, reg = 0;
reg = __raw_readl(ICU_INT_CONF(IRQ_PXA910_PMIC_INT));
if ((reg & 0x3) == 0)
return -EAGAIN;
idle_cfg = __raw_readl(APMU_MOH_IDLE_CFG);
idle_cfg |= APMU_MOH_IDLE_CFG_MOH_PWRDWN
| APMU_MOH_IDLE_CFG_MOH_SRAM_PWRDWN;
__raw_writel(idle_cfg, APMU_MOH_IDLE_CFG);
outer_disable();
while (!(readl(CIU_REG(0x8)) & (1 << 16)))
udelay(1);
cpu_do_idle();
outer_resume();
while (!(readl(CIU_REG(0x8)) & (1 << 16)))
udelay(1);
idle_cfg = __raw_readl(APMU_MOH_IDLE_CFG);
idle_cfg &= ~(APMU_MOH_IDLE_CFG_MOH_PWRDWN
| APMU_MOH_IDLE_CFG_MOH_SRAM_PWRDWN);
__raw_writel(idle_cfg, APMU_MOH_IDLE_CFG);
return 0;
}
static int pxa910_pm_prepare(void)
{
pxa910_pm_enter_lowpower_mode(POWER_MODE_UDR);
return 0;
}
static void pxa910_pm_finish(void)
{
pxa910_pm_enter_lowpower_mode(POWER_MODE_CORE_INTIDLE);
}
static int pxa910_pm_valid(suspend_state_t state)
{
return ((state == PM_SUSPEND_STANDBY) || (state == PM_SUSPEND_MEM));
}
static int __init pxa910_pm_init(void)
{
uint32_t awucrm = 0;
if (!cpu_is_pxa910())
return -EIO;
suspend_set_ops(&pxa910_pm_ops);
__raw_writel(__raw_readl(APMU_SQU_CLK_GATE_CTRL) | (1 << 30),
APMU_SQU_CLK_GATE_CTRL);
__raw_writel(__raw_readl(MPMU_FCCR) | (1 << 28), MPMU_FCCR);
awucrm |= MPMU_AWUCRM_AP_ASYNC_INT | MPMU_AWUCRM_AP_FULL_IDLE;
__raw_writel(awucrm, MPMU_AWUCRM);
return 0;
}
