int
nv84_temp_get(struct nouveau_therm *therm)
{
struct nouveau_fuse *fuse = nouveau_fuse(therm);
if (nv_ro32(fuse, 0x1a8) == 1)
return nv_rd32(therm, 0x20400);
else
return -ENODEV;
}
void
nv84_sensor_setup(struct nouveau_therm *therm)
{
struct nouveau_fuse *fuse = nouveau_fuse(therm);
if (nv_ro32(fuse, 0x1a8) == 1) {
nv_mask(therm, 0x20008, 0x80008000, 0x80000000);
nv_mask(therm, 0x2000c, 0x80000003, 0x00000000);
mdelay(20);
}
}
static void
nv84_therm_program_alarms(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *priv = (void *)therm;
struct nvbios_therm_sensor *sensor = &priv->bios_sensor;
unsigned long flags;
spin_lock_irqsave(&priv->sensor.alarm_program_lock, flags);
nv_wr32(therm, 0x20000, 0x000003ff);
nv_wr32(therm, 0x20484, sensor->thrs_shutdown.hysteresis);
nv_wr32(therm, 0x20480, sensor->thrs_shutdown.temp);
nv_wr32(therm, 0x204c4, sensor->thrs_fan_boost.temp);
nv_wr32(therm, 0x204c0, sensor->thrs_critical.temp);
nv_wr32(therm, 0x20414, sensor->thrs_down_clock.temp);
spin_unlock_irqrestore(&priv->sensor.alarm_program_lock, flags);
nv_debug(therm,
"Programmed thresholds [ %d(%d), %d(%d), %d(%d), %d(%d) ]\n",
sensor->thrs_fan_boost.temp, sensor->thrs_fan_boost.hysteresis,
sensor->thrs_down_clock.temp,
sensor->thrs_down_clock.hysteresis,
sensor->thrs_critical.temp, sensor->thrs_critical.hysteresis,
sensor->thrs_shutdown.temp, sensor->thrs_shutdown.hysteresis);
}
static void
nv84_therm_threshold_hyst_emulation(struct nouveau_therm *therm,
uint32_t thrs_reg, u8 status_bit,
const struct nvbios_therm_threshold *thrs,
enum nouveau_therm_thrs thrs_name)
{
enum nouveau_therm_thrs_direction direction;
enum nouveau_therm_thrs_state prev_state, new_state;
int temp, cur;
prev_state = nouveau_therm_sensor_get_threshold_state(therm, thrs_name);
temp = nv_rd32(therm, thrs_reg);
if (temp == thrs->temp) {
nv_wr32(therm, thrs_reg, thrs->temp - thrs->hysteresis);
new_state = NOUVEAU_THERM_THRS_HIGHER;
} else {
nv_wr32(therm, thrs_reg, thrs->temp);
new_state = NOUVEAU_THERM_THRS_LOWER;
}
cur = therm->temp_get(therm);
if (new_state == NOUVEAU_THERM_THRS_LOWER && cur > thrs->temp)
new_state = NOUVEAU_THERM_THRS_HIGHER;
else if (new_state == NOUVEAU_THERM_THRS_HIGHER &&
cur < thrs->temp - thrs->hysteresis)
new_state = NOUVEAU_THERM_THRS_LOWER;
nouveau_therm_sensor_set_threshold_state(therm, thrs_name, new_state);
if (prev_state < new_state)
direction = NOUVEAU_THERM_THRS_RISING;
else if (prev_state > new_state)
direction = NOUVEAU_THERM_THRS_FALLING;
else
return;
nouveau_therm_sensor_event(therm, thrs_name, direction);
}
static void
nv84_therm_intr(struct nouveau_subdev *subdev)
{
struct nouveau_therm *therm = nouveau_therm(subdev);
struct nouveau_therm_priv *priv = (void *)therm;
struct nvbios_therm_sensor *sensor = &priv->bios_sensor;
unsigned long flags;
uint32_t intr;
spin_lock_irqsave(&priv->sensor.alarm_program_lock, flags);
intr = nv_rd32(therm, 0x20100) & 0x3ff;
if (intr & 0x002) {
nv84_therm_threshold_hyst_emulation(therm, 0x20414, 24,
&sensor->thrs_down_clock,
NOUVEAU_THERM_THRS_DOWNCLOCK);
intr &= ~0x002;
}
if (intr & 0x004) {
nv84_therm_threshold_hyst_emulation(therm, 0x20480, 20,
&sensor->thrs_shutdown,
NOUVEAU_THERM_THRS_SHUTDOWN);
intr &= ~0x004;
}
if (intr & 0x008) {
nv84_therm_threshold_hyst_emulation(therm, 0x204c4, 21,
&sensor->thrs_fan_boost,
NOUVEAU_THERM_THRS_FANBOOST);
intr &= ~0x008;
}
if (intr & 0x010) {
nv84_therm_threshold_hyst_emulation(therm, 0x204c0, 22,
&sensor->thrs_critical,
NOUVEAU_THERM_THRS_CRITICAL);
intr &= ~0x010;
}
if (intr)
nv_error(therm, "unhandled intr 0x%08x\n", intr);
nv_wr32(therm, 0x20100, 0xffffffff);
nv_wr32(therm, 0x1100, 0x10000);
spin_unlock_irqrestore(&priv->sensor.alarm_program_lock, flags);
}
static int
nv84_therm_init(struct nouveau_object *object)
{
struct nv84_therm_priv *priv = (void *)object;
int ret;
ret = nouveau_therm_init(&priv->base.base);
if (ret)
return ret;
nv84_sensor_setup(&priv->base.base);
return 0;
}
static int
nv84_therm_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv84_therm_priv *priv;
int ret;
ret = nouveau_therm_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.base.pwm_ctrl = nv50_fan_pwm_ctrl;
priv->base.base.pwm_get = nv50_fan_pwm_get;
priv->base.base.pwm_set = nv50_fan_pwm_set;
priv->base.base.pwm_clock = nv50_fan_pwm_clock;
priv->base.base.temp_get = nv84_temp_get;
priv->base.sensor.program_alarms = nv84_therm_program_alarms;
nv_subdev(priv)->intr = nv84_therm_intr;
nouveau_therm_sensor_set_threshold_state(&priv->base.base,
NOUVEAU_THERM_THRS_SHUTDOWN,
NOUVEAU_THERM_THRS_LOWER);
nouveau_therm_sensor_set_threshold_state(&priv->base.base,
NOUVEAU_THERM_THRS_FANBOOST,
NOUVEAU_THERM_THRS_LOWER);
nouveau_therm_sensor_set_threshold_state(&priv->base.base,
NOUVEAU_THERM_THRS_CRITICAL,
NOUVEAU_THERM_THRS_LOWER);
nouveau_therm_sensor_set_threshold_state(&priv->base.base,
NOUVEAU_THERM_THRS_DOWNCLOCK,
NOUVEAU_THERM_THRS_LOWER);
return nouveau_therm_preinit(&priv->base.base);
}
int
nv84_therm_fini(struct nouveau_object *object, bool suspend)
{
nv_wr32(object, 0x20000, 0x00000000);
nv_wr32(object, 0x20100, 0xffffffff);
nv_wr32(object, 0x1100, 0x10000);
return _nouveau_therm_fini(object, suspend);
}
