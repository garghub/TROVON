static bool
probe_monitoring_device(struct nouveau_i2c_port *i2c,
struct i2c_board_info *info)
{
struct nouveau_therm_priv *priv = (void *)nouveau_therm(i2c);
struct nvbios_therm_sensor *sensor = &priv->bios_sensor;
struct i2c_client *client;
request_module("%s%s", I2C_MODULE_PREFIX, info->type);
client = i2c_new_device(&i2c->adapter, info);
if (!client)
return false;
if (!client->driver || client->driver->detect(client, info)) {
i2c_unregister_device(client);
return false;
}
nv_info(priv,
"Found an %s at address 0x%x (controlled by lm_sensors, "
"temp offset %+i C)\n",
info->type, info->addr, sensor->offset_constant);
priv->ic = client;
return true;
}
void
nouveau_therm_ic_ctor(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *priv = (void *)therm;
struct nouveau_bios *bios = nouveau_bios(therm);
struct nouveau_i2c *i2c = nouveau_i2c(therm);
struct nvbios_extdev_func extdev_entry;
if (!nvbios_extdev_find(bios, NVBIOS_EXTDEV_LM89, &extdev_entry)) {
struct i2c_board_info board[] = {
{ I2C_BOARD_INFO("lm90", extdev_entry.addr >> 1) },
{ }
};
i2c->identify(i2c, NV_I2C_DEFAULT(0), "monitoring device",
board, probe_monitoring_device);
if (priv->ic)
return;
}
if (!nvbios_extdev_find(bios, NVBIOS_EXTDEV_ADT7473, &extdev_entry)) {
struct i2c_board_info board[] = {
{ I2C_BOARD_INFO("adt7473", extdev_entry.addr >> 1) },
{ }
};
i2c->identify(i2c, NV_I2C_DEFAULT(0), "monitoring device",
board, probe_monitoring_device);
if (priv->ic)
return;
}
i2c->identify(i2c, NV_I2C_DEFAULT(0), "monitoring device",
nv_board_infos, probe_monitoring_device);
}
