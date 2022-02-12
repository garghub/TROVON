static enum nv40_sensor_style
nv40_sensor_style(struct nvkm_therm *therm)
{
switch (therm->subdev.device->chipset) {
case 0x43:
case 0x44:
case 0x4a:
case 0x47:
return OLD_STYLE;
case 0x46:
case 0x49:
case 0x4b:
case 0x4e:
case 0x4c:
case 0x67:
case 0x68:
case 0x63:
return NEW_STYLE;
default:
return INVALID_STYLE;
}
}
static int
nv40_sensor_setup(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
enum nv40_sensor_style style = nv40_sensor_style(therm);
if (style == NEW_STYLE) {
nvkm_mask(device, 0x15b8, 0x80000000, 0);
nvkm_wr32(device, 0x15b0, 0x80003fff);
mdelay(20);
return nvkm_rd32(device, 0x15b4) & 0x3fff;
} else if (style == OLD_STYLE) {
nvkm_wr32(device, 0x15b0, 0xff);
mdelay(20);
return nvkm_rd32(device, 0x15b4) & 0xff;
} else
return -ENODEV;
}
static int
nv40_temp_get(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
struct nvbios_therm_sensor *sensor = &therm->bios_sensor;
enum nv40_sensor_style style = nv40_sensor_style(therm);
int core_temp;
if (style == NEW_STYLE) {
nvkm_wr32(device, 0x15b0, 0x80003fff);
core_temp = nvkm_rd32(device, 0x15b4) & 0x3fff;
} else if (style == OLD_STYLE) {
nvkm_wr32(device, 0x15b0, 0xff);
core_temp = nvkm_rd32(device, 0x15b4) & 0xff;
} else
return -ENODEV;
if (!sensor->slope_div || !sensor->slope_mult ||
!sensor->offset_num || !sensor->offset_den)
return -ENODEV;
core_temp = core_temp * sensor->slope_mult / sensor->slope_div;
core_temp = core_temp + sensor->offset_num / sensor->offset_den;
core_temp = core_temp + sensor->offset_constant - 8;
if (core_temp < 0)
core_temp = 0;
return core_temp;
}
static int
nv40_fan_pwm_ctrl(struct nvkm_therm *therm, int line, bool enable)
{
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
u32 mask = enable ? 0x80000000 : 0x00000000;
if (line == 2) nvkm_mask(device, 0x0010f0, 0x80000000, mask);
else if (line == 9) nvkm_mask(device, 0x0015f4, 0x80000000, mask);
else {
nvkm_error(subdev, "unknown pwm ctrl for gpio %d\n", line);
return -ENODEV;
}
return 0;
}
static int
nv40_fan_pwm_get(struct nvkm_therm *therm, int line, u32 *divs, u32 *duty)
{
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
if (line == 2) {
u32 reg = nvkm_rd32(device, 0x0010f0);
if (reg & 0x80000000) {
*duty = (reg & 0x7fff0000) >> 16;
*divs = (reg & 0x00007fff);
return 0;
}
} else
if (line == 9) {
u32 reg = nvkm_rd32(device, 0x0015f4);
if (reg & 0x80000000) {
*divs = nvkm_rd32(device, 0x0015f8);
*duty = (reg & 0x7fffffff);
return 0;
}
} else {
nvkm_error(subdev, "unknown pwm ctrl for gpio %d\n", line);
return -ENODEV;
}
return -EINVAL;
}
static int
nv40_fan_pwm_set(struct nvkm_therm *therm, int line, u32 divs, u32 duty)
{
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
if (line == 2) {
nvkm_mask(device, 0x0010f0, 0x7fff7fff, (duty << 16) | divs);
} else
if (line == 9) {
nvkm_wr32(device, 0x0015f8, divs);
nvkm_mask(device, 0x0015f4, 0x7fffffff, duty);
} else {
nvkm_error(subdev, "unknown pwm ctrl for gpio %d\n", line);
return -ENODEV;
}
return 0;
}
void
nv40_therm_intr(struct nvkm_therm *therm)
{
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
uint32_t stat = nvkm_rd32(device, 0x1100);
nvkm_wr32(device, 0x1100, 0x70000);
nvkm_error(subdev, "THERM received an IRQ: stat = %x\n", stat);
}
static void
nv40_therm_init(struct nvkm_therm *therm)
{
nv40_sensor_setup(therm);
}
int
nv40_therm_new(struct nvkm_device *device, int index,
struct nvkm_therm **ptherm)
{
return nvkm_therm_new_(&nv40_therm, device, index, ptherm);
}
