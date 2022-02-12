static void
nvkm_fantog_update(struct nvkm_fantog *fan, int percent)
{
struct nvkm_therm *therm = fan->base.parent;
struct nvkm_device *device = therm->subdev.device;
struct nvkm_timer *tmr = device->timer;
struct nvkm_gpio *gpio = device->gpio;
unsigned long flags;
int duty;
spin_lock_irqsave(&fan->lock, flags);
if (percent < 0)
percent = fan->percent;
fan->percent = percent;
duty = !nvkm_gpio_get(gpio, 0, DCB_GPIO_FAN, 0xff);
nvkm_gpio_set(gpio, 0, DCB_GPIO_FAN, 0xff, duty);
if (percent != (duty * 100)) {
u64 next_change = (percent * fan->period_us) / 100;
if (!duty)
next_change = fan->period_us - next_change;
nvkm_timer_alarm(tmr, next_change * 1000, &fan->alarm);
}
spin_unlock_irqrestore(&fan->lock, flags);
}
static void
nvkm_fantog_alarm(struct nvkm_alarm *alarm)
{
struct nvkm_fantog *fan =
container_of(alarm, struct nvkm_fantog, alarm);
nvkm_fantog_update(fan, -1);
}
static int
nvkm_fantog_get(struct nvkm_therm *therm)
{
struct nvkm_fantog *fan = (void *)therm->fan;
return fan->percent;
}
static int
nvkm_fantog_set(struct nvkm_therm *therm, int percent)
{
struct nvkm_fantog *fan = (void *)therm->fan;
if (therm->func->pwm_ctrl)
therm->func->pwm_ctrl(therm, fan->func.line, false);
nvkm_fantog_update(fan, percent);
return 0;
}
int
nvkm_fantog_create(struct nvkm_therm *therm, struct dcb_gpio_func *func)
{
struct nvkm_fantog *fan;
int ret;
if (therm->func->pwm_ctrl) {
ret = therm->func->pwm_ctrl(therm, func->line, false);
if (ret)
return ret;
}
fan = kzalloc(sizeof(*fan), GFP_KERNEL);
therm->fan = &fan->base;
if (!fan)
return -ENOMEM;
fan->base.type = "toggle";
fan->base.get = nvkm_fantog_get;
fan->base.set = nvkm_fantog_set;
nvkm_alarm_init(&fan->alarm, nvkm_fantog_alarm);
fan->period_us = 100000;
fan->percent = 100;
fan->func = *func;
spin_lock_init(&fan->lock);
return 0;
}
