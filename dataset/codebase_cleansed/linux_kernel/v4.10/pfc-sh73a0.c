static void sh73a0_vccq_mc0_endisable(struct regulator_dev *reg, bool enable)
{
struct sh_pfc *pfc = reg->reg_data;
void __iomem *addr = pfc->windows[1].virt + 4;
unsigned long flags;
u32 value;
spin_lock_irqsave(&pfc->lock, flags);
value = ioread32(addr);
if (enable)
value |= BIT(28);
else
value &= ~BIT(28);
iowrite32(value, addr);
spin_unlock_irqrestore(&pfc->lock, flags);
}
static int sh73a0_vccq_mc0_enable(struct regulator_dev *reg)
{
sh73a0_vccq_mc0_endisable(reg, true);
return 0;
}
static int sh73a0_vccq_mc0_disable(struct regulator_dev *reg)
{
sh73a0_vccq_mc0_endisable(reg, false);
return 0;
}
static int sh73a0_vccq_mc0_is_enabled(struct regulator_dev *reg)
{
struct sh_pfc *pfc = reg->reg_data;
void __iomem *addr = pfc->windows[1].virt + 4;
unsigned long flags;
u32 value;
spin_lock_irqsave(&pfc->lock, flags);
value = ioread32(addr);
spin_unlock_irqrestore(&pfc->lock, flags);
return !!(value & BIT(28));
}
static int sh73a0_vccq_mc0_get_voltage(struct regulator_dev *reg)
{
return 3300000;
}
static unsigned int sh73a0_pinmux_get_bias(struct sh_pfc *pfc, unsigned int pin)
{
void __iomem *addr = pfc->windows->virt
+ sh73a0_portcr_offsets[pin >> 5] + pin;
u32 value = ioread8(addr) & PORTnCR_PULMD_MASK;
switch (value) {
case PORTnCR_PULMD_UP:
return PIN_CONFIG_BIAS_PULL_UP;
case PORTnCR_PULMD_DOWN:
return PIN_CONFIG_BIAS_PULL_DOWN;
case PORTnCR_PULMD_OFF:
default:
return PIN_CONFIG_BIAS_DISABLE;
}
}
static void sh73a0_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
void __iomem *addr = pfc->windows->virt
+ sh73a0_portcr_offsets[pin >> 5] + pin;
u32 value = ioread8(addr) & ~PORTnCR_PULMD_MASK;
switch (bias) {
case PIN_CONFIG_BIAS_PULL_UP:
value |= PORTnCR_PULMD_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
value |= PORTnCR_PULMD_DOWN;
break;
}
iowrite8(value, addr);
}
static int sh73a0_pinmux_soc_init(struct sh_pfc *pfc)
{
struct regulator_config cfg = { };
struct regulator_dev *vccq;
int ret;
cfg.dev = pfc->dev;
cfg.init_data = &sh73a0_vccq_mc0_init_data;
cfg.driver_data = pfc;
vccq = devm_regulator_register(pfc->dev, &sh73a0_vccq_mc0_desc, &cfg);
if (IS_ERR(vccq)) {
ret = PTR_ERR(vccq);
dev_err(pfc->dev, "Failed to register VCCQ MC0 regulator: %d\n",
ret);
return ret;
}
return 0;
}
