static int
gm107_fan_pwm_ctrl(struct nouveau_therm *therm, int line, bool enable)
{
return 0;
}
static int
gm107_fan_pwm_get(struct nouveau_therm *therm, int line, u32 *divs, u32 *duty)
{
*divs = nv_rd32(therm, 0x10eb20) & 0x1fff;
*duty = nv_rd32(therm, 0x10eb24) & 0x1fff;
return 0;
}
static int
gm107_fan_pwm_set(struct nouveau_therm *therm, int line, u32 divs, u32 duty)
{
nv_mask(therm, 0x10eb10, 0x1fff, divs);
nv_wr32(therm, 0x10eb14, duty | 0x80000000);
return 0;
}
static int
gm107_fan_pwm_clock(struct nouveau_therm *therm, int line)
{
return nv_device(therm)->crystal * 1000;
}
static int
gm107_therm_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct gm107_therm_priv *priv;
int ret;
ret = nouveau_therm_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.base.pwm_ctrl = gm107_fan_pwm_ctrl;
priv->base.base.pwm_get = gm107_fan_pwm_get;
priv->base.base.pwm_set = gm107_fan_pwm_set;
priv->base.base.pwm_clock = gm107_fan_pwm_clock;
priv->base.base.temp_get = nv84_temp_get;
priv->base.base.fan_sense = nva3_therm_fan_sense;
priv->base.sensor.program_alarms = nouveau_therm_program_alarms_polling;
return nouveau_therm_preinit(&priv->base.base);
}
