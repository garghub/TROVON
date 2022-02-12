static void
nouveau_therm_temp_set_defaults(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *priv = (void *)therm;
priv->bios_sensor.slope_mult = 1;
priv->bios_sensor.slope_div = 1;
priv->bios_sensor.offset_num = 0;
priv->bios_sensor.offset_den = 1;
priv->bios_sensor.offset_constant = 0;
priv->bios_sensor.thrs_fan_boost.temp = 90;
priv->bios_sensor.thrs_fan_boost.hysteresis = 3;
priv->bios_sensor.thrs_down_clock.temp = 95;
priv->bios_sensor.thrs_down_clock.hysteresis = 3;
priv->bios_sensor.thrs_critical.temp = 105;
priv->bios_sensor.thrs_critical.hysteresis = 5;
priv->bios_sensor.thrs_shutdown.temp = 135;
priv->bios_sensor.thrs_shutdown.hysteresis = 5;
}
static void
nouveau_therm_temp_safety_checks(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *priv = (void *)therm;
if (!priv->bios_sensor.slope_div)
priv->bios_sensor.slope_div = 1;
if (!priv->bios_sensor.offset_den)
priv->bios_sensor.offset_den = 1;
}
int
nouveau_therm_sensor_ctor(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *priv = (void *)therm;
struct nouveau_bios *bios = nouveau_bios(therm);
nouveau_therm_temp_set_defaults(therm);
if (nvbios_therm_sensor_parse(bios, NVBIOS_THERM_DOMAIN_CORE,
&priv->bios_sensor))
nv_error(therm, "nvbios_therm_sensor_parse failed\n");
nouveau_therm_temp_safety_checks(therm);
return 0;
}
