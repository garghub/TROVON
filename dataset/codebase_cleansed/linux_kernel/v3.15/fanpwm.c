static int
nouveau_fanpwm_get(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fanpwm_priv *priv = (void *)tpriv->fan;
struct nouveau_gpio *gpio = nouveau_gpio(therm);
int card_type = nv_device(therm)->card_type;
u32 divs, duty;
int ret;
ret = therm->pwm_get(therm, priv->func.line, &divs, &duty);
if (ret == 0 && divs) {
divs = max(divs, duty);
if (card_type <= NV_40 || (priv->func.log[0] & 1))
duty = divs - duty;
return (duty * 100) / divs;
}
return gpio->get(gpio, 0, priv->func.func, priv->func.line) * 100;
}
static int
nouveau_fanpwm_set(struct nouveau_therm *therm, int percent)
{
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fanpwm_priv *priv = (void *)tpriv->fan;
int card_type = nv_device(therm)->card_type;
u32 divs, duty;
int ret;
divs = priv->base.perf.pwm_divisor;
if (priv->base.bios.pwm_freq) {
divs = 1;
if (therm->pwm_clock)
divs = therm->pwm_clock(therm, priv->func.line);
divs /= priv->base.bios.pwm_freq;
}
duty = ((divs * percent) + 99) / 100;
if (card_type <= NV_40 || (priv->func.log[0] & 1))
duty = divs - duty;
ret = therm->pwm_set(therm, priv->func.line, divs, duty);
if (ret == 0)
ret = therm->pwm_ctrl(therm, priv->func.line, true);
return ret;
}
int
nouveau_fanpwm_create(struct nouveau_therm *therm, struct dcb_gpio_func *func)
{
struct nouveau_device *device = nv_device(therm);
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fanpwm_priv *priv;
u32 divs, duty;
if (!nouveau_boolopt(device->cfgopt, "NvFanPWM", func->param) ||
!therm->pwm_ctrl ||
therm->pwm_get(therm, func->line, &divs, &duty) == -ENODEV)
return -ENODEV;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
tpriv->fan = &priv->base;
if (!priv)
return -ENOMEM;
priv->base.type = "PWM";
priv->base.get = nouveau_fanpwm_get;
priv->base.set = nouveau_fanpwm_set;
priv->func = *func;
return 0;
}
