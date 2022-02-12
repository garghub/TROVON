static void __msm_gpiomux_write(unsigned gpio, gpiomux_config_t val)
{
unsigned tlmm_config = (val & ~GPIOMUX_CTL_MASK) |
((gpio & 0x3ff) << 4);
unsigned tlmm_disable = 0;
int rc;
rc = msm_proc_comm(PCOM_RPC_GPIO_TLMM_CONFIG_EX,
&tlmm_config, &tlmm_disable);
if (rc)
pr_err("%s: unexpected proc_comm failure %d: %08x %08x\n",
__func__, rc, tlmm_config, tlmm_disable);
}
int msm_gpiomux_write(unsigned gpio,
gpiomux_config_t active,
gpiomux_config_t suspended)
{
struct msm_gpiomux_config *cfg = msm_gpiomux_configs + gpio;
unsigned long irq_flags;
gpiomux_config_t setting;
if (gpio >= GPIOMUX_NGPIOS)
return -EINVAL;
spin_lock_irqsave(&gpiomux_lock, irq_flags);
if (active & GPIOMUX_VALID)
cfg->active = active;
if (suspended & GPIOMUX_VALID)
cfg->suspended = suspended;
setting = cfg->ref ? active : suspended;
if (setting & GPIOMUX_VALID)
__msm_gpiomux_write(gpio, setting);
spin_unlock_irqrestore(&gpiomux_lock, irq_flags);
return 0;
}
int msm_gpiomux_get(unsigned gpio)
{
struct msm_gpiomux_config *cfg = msm_gpiomux_configs + gpio;
unsigned long irq_flags;
if (gpio >= GPIOMUX_NGPIOS)
return -EINVAL;
spin_lock_irqsave(&gpiomux_lock, irq_flags);
if (cfg->ref++ == 0 && cfg->active & GPIOMUX_VALID)
__msm_gpiomux_write(gpio, cfg->active);
spin_unlock_irqrestore(&gpiomux_lock, irq_flags);
return 0;
}
int msm_gpiomux_put(unsigned gpio)
{
struct msm_gpiomux_config *cfg = msm_gpiomux_configs + gpio;
unsigned long irq_flags;
if (gpio >= GPIOMUX_NGPIOS)
return -EINVAL;
spin_lock_irqsave(&gpiomux_lock, irq_flags);
BUG_ON(cfg->ref == 0);
if (--cfg->ref == 0 && cfg->suspended & GPIOMUX_VALID)
__msm_gpiomux_write(gpio, cfg->suspended);
spin_unlock_irqrestore(&gpiomux_lock, irq_flags);
return 0;
}
static int __init gpiomux_init(void)
{
unsigned n;
for (n = 0; n < GPIOMUX_NGPIOS; ++n) {
msm_gpiomux_configs[n].ref = 0;
if (!(msm_gpiomux_configs[n].suspended & GPIOMUX_VALID))
continue;
__msm_gpiomux_write(n, msm_gpiomux_configs[n].suspended);
}
return 0;
}
