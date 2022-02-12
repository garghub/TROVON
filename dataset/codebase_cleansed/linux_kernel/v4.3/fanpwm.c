static int
nvkm_fanpwm_get(struct nvkm_therm *therm)
{
struct nvkm_fanpwm *fan = (void *)therm->fan;
struct nvkm_device *device = therm->subdev.device;
struct nvkm_gpio *gpio = device->gpio;
int card_type = device->card_type;
u32 divs, duty;
int ret;
ret = therm->func->pwm_get(therm, fan->func.line, &divs, &duty);
if (ret == 0 && divs) {
divs = max(divs, duty);
if (card_type <= NV_40 || (fan->func.log[0] & 1))
duty = divs - duty;
return (duty * 100) / divs;
}
return nvkm_gpio_get(gpio, 0, fan->func.func, fan->func.line) * 100;
}
static int
nvkm_fanpwm_set(struct nvkm_therm *therm, int percent)
{
struct nvkm_fanpwm *fan = (void *)therm->fan;
int card_type = therm->subdev.device->card_type;
u32 divs, duty;
int ret;
divs = fan->base.perf.pwm_divisor;
if (fan->base.bios.pwm_freq) {
divs = 1;
if (therm->func->pwm_clock)
divs = therm->func->pwm_clock(therm, fan->func.line);
divs /= fan->base.bios.pwm_freq;
}
duty = ((divs * percent) + 99) / 100;
if (card_type <= NV_40 || (fan->func.log[0] & 1))
duty = divs - duty;
ret = therm->func->pwm_set(therm, fan->func.line, divs, duty);
if (ret == 0)
ret = therm->func->pwm_ctrl(therm, fan->func.line, true);
return ret;
}
int
nvkm_fanpwm_create(struct nvkm_therm *therm, struct dcb_gpio_func *func)
{
struct nvkm_device *device = therm->subdev.device;
struct nvkm_bios *bios = device->bios;
struct nvkm_fanpwm *fan;
struct nvbios_therm_fan info = {};
u32 divs, duty;
nvbios_fan_parse(bios, &info);
if (!nvkm_boolopt(device->cfgopt, "NvFanPWM", func->param) ||
!therm->func->pwm_ctrl || info.type == NVBIOS_THERM_FAN_TOGGLE ||
therm->func->pwm_get(therm, func->line, &divs, &duty) == -ENODEV)
return -ENODEV;
fan = kzalloc(sizeof(*fan), GFP_KERNEL);
therm->fan = &fan->base;
if (!fan)
return -ENOMEM;
fan->base.type = "PWM";
fan->base.get = nvkm_fanpwm_get;
fan->base.set = nvkm_fanpwm_set;
fan->func = *func;
return 0;
}
