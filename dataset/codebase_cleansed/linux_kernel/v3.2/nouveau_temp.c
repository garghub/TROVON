static void
nouveau_temp_vbios_parse(struct drm_device *dev, u8 *temp)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_pm_engine *pm = &dev_priv->engine.pm;
struct nouveau_pm_temp_sensor_constants *sensor = &pm->sensor_constants;
struct nouveau_pm_threshold_temp *temps = &pm->threshold_temp;
int i, headerlen, recordlen, entries;
if (!temp) {
NV_DEBUG(dev, "temperature table pointer invalid\n");
return;
}
sensor->offset_constant = 0;
sensor->offset_mult = 0;
sensor->offset_div = 1;
sensor->slope_mult = 1;
sensor->slope_div = 1;
temps->critical = 110;
temps->down_clock = 100;
temps->fan_boost = 90;
if (dev_priv->card_type >= NV_40) {
switch (dev_priv->chipset) {
case 0x43:
sensor->offset_mult = 32060;
sensor->offset_div = 1000;
sensor->slope_mult = 792;
sensor->slope_div = 1000;
break;
case 0x44:
case 0x47:
case 0x4a:
sensor->offset_mult = 27839;
sensor->offset_div = 1000;
sensor->slope_mult = 780;
sensor->slope_div = 1000;
break;
case 0x46:
sensor->offset_mult = -24775;
sensor->offset_div = 100;
sensor->slope_mult = 467;
sensor->slope_div = 10000;
break;
case 0x49:
sensor->offset_mult = -25051;
sensor->offset_div = 100;
sensor->slope_mult = 458;
sensor->slope_div = 10000;
break;
case 0x4b:
sensor->offset_mult = -24088;
sensor->offset_div = 100;
sensor->slope_mult = 442;
sensor->slope_div = 10000;
break;
case 0x50:
sensor->offset_mult = -22749;
sensor->offset_div = 100;
sensor->slope_mult = 431;
sensor->slope_div = 10000;
break;
case 0x67:
sensor->offset_mult = -26149;
sensor->offset_div = 100;
sensor->slope_mult = 484;
sensor->slope_div = 10000;
break;
}
}
headerlen = temp[1];
recordlen = temp[2];
entries = temp[3];
temp = temp + headerlen;
for (i = 0; i < entries; i++) {
s16 value = ROM16(temp[1]);
switch (temp[0]) {
case 0x01:
if ((value & 0x8f) == 0)
sensor->offset_constant = (value >> 9) & 0x7f;
break;
case 0x04:
if ((value & 0xf00f) == 0xa000)
temps->critical = (value&0x0ff0) >> 4;
break;
case 0x07:
if ((value & 0xf00f) == 0xa000)
temps->down_clock = (value&0x0ff0) >> 4;
break;
case 0x08:
if ((value & 0xf00f) == 0xa000)
temps->fan_boost = (value&0x0ff0) >> 4;
break;
case 0x10:
sensor->offset_mult = value;
break;
case 0x11:
sensor->offset_div = value;
break;
case 0x12:
sensor->slope_mult = value;
break;
case 0x13:
sensor->slope_div = value;
break;
}
temp += recordlen;
}
nouveau_temp_safety_checks(dev);
}
static int
nv40_sensor_setup(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_pm_engine *pm = &dev_priv->engine.pm;
struct nouveau_pm_temp_sensor_constants *sensor = &pm->sensor_constants;
s32 offset = sensor->offset_mult / sensor->offset_div;
s32 sensor_calibration;
sensor_calibration = 120 - offset - sensor->offset_constant;
sensor_calibration = sensor_calibration * sensor->slope_div /
sensor->slope_mult;
if (dev_priv->chipset >= 0x46)
sensor_calibration |= 0x80000000;
else
sensor_calibration |= 0x10000000;
nv_wr32(dev, 0x0015b0, sensor_calibration);
msleep(5);
return nv_rd32(dev, 0x0015b4) & 0x1fff;
}
int
nv40_temp_get(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_pm_engine *pm = &dev_priv->engine.pm;
struct nouveau_pm_temp_sensor_constants *sensor = &pm->sensor_constants;
int offset = sensor->offset_mult / sensor->offset_div;
int core_temp;
if (dev_priv->card_type >= NV_50) {
core_temp = nv_rd32(dev, 0x20008);
} else {
core_temp = nv_rd32(dev, 0x0015b4) & 0x1fff;
if (core_temp == 0)
core_temp = nv40_sensor_setup(dev);
}
core_temp = core_temp * sensor->slope_mult / sensor->slope_div;
core_temp = core_temp + offset + sensor->offset_constant;
return core_temp;
}
int
nv84_temp_get(struct drm_device *dev)
{
return nv_rd32(dev, 0x20400);
}
void
nouveau_temp_safety_checks(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_pm_engine *pm = &dev_priv->engine.pm;
struct nouveau_pm_threshold_temp *temps = &pm->threshold_temp;
if (temps->critical > 120)
temps->critical = 120;
else if (temps->critical < 80)
temps->critical = 80;
if (temps->down_clock > 110)
temps->down_clock = 110;
else if (temps->down_clock < 60)
temps->down_clock = 60;
if (temps->fan_boost > 100)
temps->fan_boost = 100;
else if (temps->fan_boost < 40)
temps->fan_boost = 40;
}
static bool
probe_monitoring_device(struct nouveau_i2c_chan *i2c,
struct i2c_board_info *info)
{
struct i2c_client *client;
request_module("%s%s", I2C_MODULE_PREFIX, info->type);
client = i2c_new_device(&i2c->adapter, info);
if (!client)
return false;
if (!client->driver || client->driver->detect(client, info)) {
i2c_unregister_device(client);
return false;
}
return true;
}
static void
nouveau_temp_probe_i2c(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct dcb_table *dcb = &dev_priv->vbios.dcb;
struct i2c_board_info info[] = {
{ I2C_BOARD_INFO("w83l785ts", 0x2d) },
{ I2C_BOARD_INFO("w83781d", 0x2d) },
{ I2C_BOARD_INFO("adt7473", 0x2e) },
{ I2C_BOARD_INFO("f75375", 0x2e) },
{ I2C_BOARD_INFO("lm99", 0x4c) },
{ }
};
int idx = (dcb->version >= 0x40 ?
dcb->i2c_default_indices & 0xf : 2);
nouveau_i2c_identify(dev, "monitoring device", info,
probe_monitoring_device, idx);
}
void
nouveau_temp_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct bit_entry P;
u8 *temp = NULL;
if (bios->type == NVBIOS_BIT) {
if (bit_table(dev, 'P', &P))
return;
if (P.version == 1)
temp = ROMPTR(bios, P.data[12]);
else if (P.version == 2)
temp = ROMPTR(bios, P.data[16]);
else
NV_WARN(dev, "unknown temp for BIT P %d\n", P.version);
nouveau_temp_vbios_parse(dev, temp);
}
nouveau_temp_probe_i2c(dev);
}
void
nouveau_temp_fini(struct drm_device *dev)
{
}
