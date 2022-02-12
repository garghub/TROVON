static void softreset_push(void *data)
{
printk(KERN_WARNING "SOFTRESET switch was pushed\n");
msp_restart(NULL);
}
static void softreset_release(void *data)
{
printk(KERN_WARNING "SOFTRESET switch was released\n");
}
static void standby_on(void *data)
{
printk(KERN_WARNING "STANDBY switch was set to ON (not implemented)\n");
}
static void standby_off(void *data)
{
printk(KERN_WARNING
"STANDBY switch was set to OFF (not implemented)\n");
}
static irqreturn_t hwbutton_handler(int irq, void *data)
{
struct hwbutton_interrupt *hirq = data;
unsigned long cic_ext = *CIC_EXT_CFG_REG;
if (CIC_EXT_IS_ACTIVE_HI(cic_ext, hirq->eirq)) {
CIC_EXT_SET_ACTIVE_LO(cic_ext, hirq->eirq);
hirq->handle_hi(hirq->data);
} else {
CIC_EXT_SET_ACTIVE_HI(cic_ext, hirq->eirq);
hirq->handle_lo(hirq->data);
}
*CIC_EXT_CFG_REG = cic_ext;
return IRQ_HANDLED;
}
static int msp_hwbutton_register(struct hwbutton_interrupt *hirq)
{
unsigned long cic_ext;
if (hirq->handle_hi == NULL || hirq->handle_lo == NULL)
return -EINVAL;
cic_ext = *CIC_EXT_CFG_REG;
CIC_EXT_SET_TRIGGER_LEVEL(cic_ext, hirq->eirq);
if (hirq->initial_state == HWBUTTON_HI)
CIC_EXT_SET_ACTIVE_LO(cic_ext, hirq->eirq);
else
CIC_EXT_SET_ACTIVE_HI(cic_ext, hirq->eirq);
*CIC_EXT_CFG_REG = cic_ext;
return request_irq(hirq->irq, hwbutton_handler, IRQF_DISABLED,
hirq->name, hirq);
}
static int __init msp_hwbutton_setup(void)
{
#ifdef CONFIG_PMC_MSP7120_GW
msp_hwbutton_register(&softreset_sw);
msp_hwbutton_register(&standby_sw);
#endif
return 0;
}
