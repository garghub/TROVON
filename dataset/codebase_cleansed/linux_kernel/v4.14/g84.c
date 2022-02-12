int
g84_temp_get(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
if (nvkm_fuse_read(device->fuse, 0x1a8) == 1)
return nvkm_rd32(device, 0x20400);
else
return -ENODEV;
}
void
g84_sensor_setup(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
if (nvkm_fuse_read(device->fuse, 0x1a8) == 1) {
nvkm_mask(device, 0x20008, 0x80008000, 0x80000000);
nvkm_mask(device, 0x2000c, 0x80000003, 0x00000000);
mdelay(20);
}
}
static void
g84_therm_program_alarms(struct nvkm_therm *therm)
{
struct nvbios_therm_sensor *sensor = &therm->bios_sensor;
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
unsigned long flags;
spin_lock_irqsave(&therm->sensor.alarm_program_lock, flags);
nvkm_wr32(device, 0x20000, 0x000003ff);
nvkm_wr32(device, 0x20484, sensor->thrs_shutdown.hysteresis);
nvkm_wr32(device, 0x20480, sensor->thrs_shutdown.temp);
nvkm_wr32(device, 0x204c4, sensor->thrs_fan_boost.temp);
nvkm_wr32(device, 0x204c0, sensor->thrs_critical.temp);
nvkm_wr32(device, 0x20414, sensor->thrs_down_clock.temp);
spin_unlock_irqrestore(&therm->sensor.alarm_program_lock, flags);
nvkm_debug(subdev,
"Programmed thresholds [ %d(%d), %d(%d), %d(%d), %d(%d) ]\n",
sensor->thrs_fan_boost.temp,
sensor->thrs_fan_boost.hysteresis,
sensor->thrs_down_clock.temp,
sensor->thrs_down_clock.hysteresis,
sensor->thrs_critical.temp,
sensor->thrs_critical.hysteresis,
sensor->thrs_shutdown.temp,
sensor->thrs_shutdown.hysteresis);
}
static void
g84_therm_threshold_hyst_emulation(struct nvkm_therm *therm,
uint32_t thrs_reg, u8 status_bit,
const struct nvbios_therm_threshold *thrs,
enum nvkm_therm_thrs thrs_name)
{
struct nvkm_device *device = therm->subdev.device;
enum nvkm_therm_thrs_direction direction;
enum nvkm_therm_thrs_state prev_state, new_state;
int temp, cur;
prev_state = nvkm_therm_sensor_get_threshold_state(therm, thrs_name);
temp = nvkm_rd32(device, thrs_reg);
if (temp == thrs->temp) {
nvkm_wr32(device, thrs_reg, thrs->temp - thrs->hysteresis);
new_state = NVKM_THERM_THRS_HIGHER;
} else {
nvkm_wr32(device, thrs_reg, thrs->temp);
new_state = NVKM_THERM_THRS_LOWER;
}
cur = therm->func->temp_get(therm);
if (new_state == NVKM_THERM_THRS_LOWER && cur > thrs->temp)
new_state = NVKM_THERM_THRS_HIGHER;
else if (new_state == NVKM_THERM_THRS_HIGHER &&
cur < thrs->temp - thrs->hysteresis)
new_state = NVKM_THERM_THRS_LOWER;
nvkm_therm_sensor_set_threshold_state(therm, thrs_name, new_state);
if (prev_state < new_state)
direction = NVKM_THERM_THRS_RISING;
else if (prev_state > new_state)
direction = NVKM_THERM_THRS_FALLING;
else
return;
nvkm_therm_sensor_event(therm, thrs_name, direction);
}
static void
g84_therm_intr(struct nvkm_therm *therm)
{
struct nvkm_subdev *subdev = &therm->subdev;
struct nvkm_device *device = subdev->device;
struct nvbios_therm_sensor *sensor = &therm->bios_sensor;
unsigned long flags;
uint32_t intr;
spin_lock_irqsave(&therm->sensor.alarm_program_lock, flags);
intr = nvkm_rd32(device, 0x20100) & 0x3ff;
if (intr & 0x002) {
g84_therm_threshold_hyst_emulation(therm, 0x20414, 24,
&sensor->thrs_down_clock,
NVKM_THERM_THRS_DOWNCLOCK);
intr &= ~0x002;
}
if (intr & 0x004) {
g84_therm_threshold_hyst_emulation(therm, 0x20480, 20,
&sensor->thrs_shutdown,
NVKM_THERM_THRS_SHUTDOWN);
intr &= ~0x004;
}
if (intr & 0x008) {
g84_therm_threshold_hyst_emulation(therm, 0x204c4, 21,
&sensor->thrs_fan_boost,
NVKM_THERM_THRS_FANBOOST);
intr &= ~0x008;
}
if (intr & 0x010) {
g84_therm_threshold_hyst_emulation(therm, 0x204c0, 22,
&sensor->thrs_critical,
NVKM_THERM_THRS_CRITICAL);
intr &= ~0x010;
}
if (intr)
nvkm_error(subdev, "intr %08x\n", intr);
nvkm_wr32(device, 0x20100, 0xffffffff);
nvkm_wr32(device, 0x1100, 0x10000);
spin_unlock_irqrestore(&therm->sensor.alarm_program_lock, flags);
}
void
g84_therm_fini(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
nvkm_wr32(device, 0x20000, 0x00000000);
nvkm_wr32(device, 0x20100, 0xffffffff);
nvkm_wr32(device, 0x1100, 0x10000);
}
void
g84_therm_init(struct nvkm_therm *therm)
{
g84_sensor_setup(therm);
}
int
g84_therm_new(struct nvkm_device *device, int index, struct nvkm_therm **ptherm)
{
struct nvkm_therm *therm;
int ret;
ret = nvkm_therm_new_(&g84_therm, device, index, &therm);
*ptherm = therm;
if (ret)
return ret;
nvkm_therm_sensor_set_threshold_state(therm, NVKM_THERM_THRS_SHUTDOWN,
NVKM_THERM_THRS_LOWER);
nvkm_therm_sensor_set_threshold_state(therm, NVKM_THERM_THRS_FANBOOST,
NVKM_THERM_THRS_LOWER);
nvkm_therm_sensor_set_threshold_state(therm, NVKM_THERM_THRS_CRITICAL,
NVKM_THERM_THRS_LOWER);
nvkm_therm_sensor_set_threshold_state(therm, NVKM_THERM_THRS_DOWNCLOCK,
NVKM_THERM_THRS_LOWER);
return 0;
}
