static int
nvkm_fan_update(struct nvkm_fan *fan, bool immediate, int target)
{
struct nvkm_therm *therm = fan->parent;
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_timer *tmr = subdev->device->timer;
unsigned long flags;
int ret = 0;
int duty;
spin_lock_irqsave(&fan->lock, flags);
if (target < 0)
target = fan->percent;
target = max_t(u8, target, fan->bios.min_duty);
target = min_t(u8, target, fan->bios.max_duty);
if (fan->percent != target) {
nvkm_debug(subdev, "FAN target: %d\n", target);
fan->percent = target;
}
duty = fan->get(therm);
if (duty == target) {
spin_unlock_irqrestore(&fan->lock, flags);
return 0;
}
if (!immediate && duty >= 0) {
if (duty < target)
duty = min(duty + 3, target);
else if (duty > target)
duty = max(duty - 3, target);
} else {
duty = target;
}
nvkm_debug(subdev, "FAN update: %d\n", duty);
ret = fan->set(therm, duty);
if (ret) {
spin_unlock_irqrestore(&fan->lock, flags);
return ret;
}
spin_unlock_irqrestore(&fan->lock, flags);
if (list_empty(&fan->alarm.head) && target != duty) {
u16 bump_period = fan->bios.bump_period;
u16 slow_down_period = fan->bios.slow_down_period;
u64 delay;
if (duty > target)
delay = slow_down_period;
else if (duty == target)
delay = min(bump_period, slow_down_period) ;
else
delay = bump_period;
nvkm_timer_alarm(tmr, delay * 1000 * 1000, &fan->alarm);
}
return ret;
}
static void
nvkm_fan_alarm(struct nvkm_alarm *alarm)
{
struct nvkm_fan *fan = container_of(alarm, struct nvkm_fan, alarm);
nvkm_fan_update(fan, false, -1);
}
int
nvkm_therm_fan_get(struct nvkm_therm *therm)
{
return therm->fan->get(therm);
}
int
nvkm_therm_fan_set(struct nvkm_therm *therm, bool immediate, int percent)
{
return nvkm_fan_update(therm->fan, immediate, percent);
}
int
nvkm_therm_fan_sense(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
struct nvkm_timer *tmr = device->timer;
struct nvkm_gpio *gpio = device->gpio;
u32 cycles, cur, prev;
u64 start, end, tach;
if (therm->func->fan_sense)
return therm->func->fan_sense(therm);
if (therm->fan->tach.func == DCB_GPIO_UNUSED)
return -ENODEV;
start = nvkm_timer_read(tmr);
prev = nvkm_gpio_get(gpio, 0, therm->fan->tach.func,
therm->fan->tach.line);
cycles = 0;
do {
usleep_range(500, 1000);
cur = nvkm_gpio_get(gpio, 0, therm->fan->tach.func,
therm->fan->tach.line);
if (prev != cur) {
if (!start)
start = nvkm_timer_read(tmr);
cycles++;
prev = cur;
}
} while (cycles < 5 && nvkm_timer_read(tmr) - start < 250000000);
end = nvkm_timer_read(tmr);
if (cycles == 5) {
tach = (u64)60000000000ULL;
do_div(tach, (end - start));
return tach;
} else
return 0;
}
int
nvkm_therm_fan_user_get(struct nvkm_therm *therm)
{
return nvkm_therm_fan_get(therm);
}
int
nvkm_therm_fan_user_set(struct nvkm_therm *therm, int percent)
{
if (therm->mode != NVKM_THERM_CTRL_MANUAL)
return -EINVAL;
return nvkm_therm_fan_set(therm, true, percent);
}
static void
nvkm_therm_fan_set_defaults(struct nvkm_therm *therm)
{
therm->fan->bios.pwm_freq = 0;
therm->fan->bios.min_duty = 0;
therm->fan->bios.max_duty = 100;
therm->fan->bios.bump_period = 500;
therm->fan->bios.slow_down_period = 2000;
therm->fan->bios.linear_min_temp = 40;
therm->fan->bios.linear_max_temp = 85;
}
static void
nvkm_therm_fan_safety_checks(struct nvkm_therm *therm)
{
if (therm->fan->bios.min_duty > 100)
therm->fan->bios.min_duty = 100;
if (therm->fan->bios.max_duty > 100)
therm->fan->bios.max_duty = 100;
if (therm->fan->bios.min_duty > therm->fan->bios.max_duty)
therm->fan->bios.min_duty = therm->fan->bios.max_duty;
}
int
nvkm_therm_fan_init(struct nvkm_therm *therm)
{
return 0;
}
int
nvkm_therm_fan_fini(struct nvkm_therm *therm, bool suspend)
{
struct nvkm_timer *tmr = therm->subdev.device->timer;
if (suspend)
nvkm_timer_alarm_cancel(tmr, &therm->fan->alarm);
return 0;
}
int
nvkm_therm_fan_ctor(struct nvkm_therm *therm)
{
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_gpio *gpio = device->gpio;
struct nvkm_bios *bios = device->bios;
struct dcb_gpio_func func;
int ret;
ret = nvkm_gpio_find(gpio, 0, DCB_GPIO_FAN, 0xff, &func);
if (ret == 0) {
if (func.line != 16 && func.log[0] & DCB_GPIO_LOG_DIR_IN) {
nvkm_debug(subdev, "GPIO_FAN is in input mode\n");
ret = -EINVAL;
} else {
ret = nvkm_fanpwm_create(therm, &func);
if (ret != 0)
ret = nvkm_fantog_create(therm, &func);
}
}
if (ret != 0) {
ret = nvkm_fannil_create(therm);
if (ret)
return ret;
}
nvkm_debug(subdev, "FAN control: %s\n", therm->fan->type);
therm->fan->percent = nvkm_therm_fan_get(therm);
ret = nvkm_gpio_find(gpio, 0, DCB_GPIO_FAN_SENSE, 0xff,
&therm->fan->tach);
if (ret)
therm->fan->tach.func = DCB_GPIO_UNUSED;
therm->fan->parent = therm;
nvkm_alarm_init(&therm->fan->alarm, nvkm_fan_alarm);
spin_lock_init(&therm->fan->lock);
nvkm_therm_fan_set_defaults(therm);
nvbios_perf_fan_parse(bios, &therm->fan->perf);
if (!nvbios_fan_parse(bios, &therm->fan->bios)) {
nvkm_debug(subdev, "parsing the fan table failed\n");
if (nvbios_therm_fan_parse(bios, &therm->fan->bios))
nvkm_error(subdev, "parsing both fan tables failed\n");
}
nvkm_therm_fan_safety_checks(therm);
return 0;
}
