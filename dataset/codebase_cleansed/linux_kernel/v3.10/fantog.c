static void
nouveau_fantog_update(struct nouveau_fantog_priv *priv, int percent)
{
struct nouveau_therm_priv *tpriv = (void *)priv->base.parent;
struct nouveau_timer *ptimer = nouveau_timer(tpriv);
struct nouveau_gpio *gpio = nouveau_gpio(tpriv);
unsigned long flags;
int duty;
spin_lock_irqsave(&priv->lock, flags);
if (percent < 0)
percent = priv->percent;
priv->percent = percent;
duty = !gpio->get(gpio, 0, DCB_GPIO_FAN, 0xff);
gpio->set(gpio, 0, DCB_GPIO_FAN, 0xff, duty);
if (list_empty(&priv->alarm.head) && percent != (duty * 100)) {
u64 next_change = (percent * priv->period_us) / 100;
if (!duty)
next_change = priv->period_us - next_change;
ptimer->alarm(ptimer, next_change * 1000, &priv->alarm);
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static void
nouveau_fantog_alarm(struct nouveau_alarm *alarm)
{
struct nouveau_fantog_priv *priv =
container_of(alarm, struct nouveau_fantog_priv, alarm);
nouveau_fantog_update(priv, -1);
}
static int
nouveau_fantog_get(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fantog_priv *priv = (void *)tpriv->fan;
return priv->percent;
}
static int
nouveau_fantog_set(struct nouveau_therm *therm, int percent)
{
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fantog_priv *priv = (void *)tpriv->fan;
if (therm->pwm_ctrl)
therm->pwm_ctrl(therm, priv->func.line, false);
nouveau_fantog_update(priv, percent);
return 0;
}
int
nouveau_fantog_create(struct nouveau_therm *therm, struct dcb_gpio_func *func)
{
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fantog_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
tpriv->fan = &priv->base;
if (!priv)
return -ENOMEM;
priv->base.type = "toggle";
priv->base.get = nouveau_fantog_get;
priv->base.set = nouveau_fantog_set;
nouveau_alarm_init(&priv->alarm, nouveau_fantog_alarm);
priv->period_us = 100000;
priv->percent = 100;
priv->func = *func;
spin_lock_init(&priv->lock);
return 0;
}
