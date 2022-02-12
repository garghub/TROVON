static bool
probe_monitoring_device(struct nvkm_i2c_bus *bus,
struct i2c_board_info *info, void *data)
{
struct nvkm_therm *therm = data;
struct nvbios_therm_sensor *sensor = &therm->bios_sensor;
struct i2c_client *client;
request_module("%s%s", I2C_MODULE_PREFIX, info->type);
client = i2c_new_device(&bus->i2c, info);
if (!client)
return false;
if (!client->dev.driver ||
to_i2c_driver(client->dev.driver)->detect(client, info)) {
i2c_unregister_device(client);
return false;
}
nvkm_debug(&therm->subdev,
"Found an %s at address 0x%x (controlled by lm_sensors, "
"temp offset %+i C)\n",
info->type, info->addr, sensor->offset_constant);
therm->ic = client;
return true;
}
void
nvkm_therm_ic_ctor(struct nvkm_therm *therm)
{
struct nvkm_device *device = therm->subdev.device;
struct nvkm_bios *bios = device->bios;
struct nvkm_i2c *i2c = device->i2c;
struct nvkm_i2c_bus *bus;
struct nvbios_extdev_func extdev_entry;
bus = nvkm_i2c_bus_find(i2c, NVKM_I2C_BUS_PRI);
if (!bus)
return;
if (!nvbios_extdev_find(bios, NVBIOS_EXTDEV_LM89, &extdev_entry)) {
struct nvkm_i2c_bus_probe board[] = {
{ { I2C_BOARD_INFO("lm90", extdev_entry.addr >> 1) }, 0},
{ }
};
nvkm_i2c_bus_probe(bus, "monitoring device", board,
probe_monitoring_device, therm);
if (therm->ic)
return;
}
if (!nvbios_extdev_find(bios, NVBIOS_EXTDEV_ADT7473, &extdev_entry)) {
struct nvkm_i2c_bus_probe board[] = {
{ { I2C_BOARD_INFO("adt7473", extdev_entry.addr >> 1) }, 20 },
{ }
};
nvkm_i2c_bus_probe(bus, "monitoring device", board,
probe_monitoring_device, therm);
if (therm->ic)
return;
}
nvkm_i2c_bus_probe(bus, "monitoring device", nv_board_infos,
probe_monitoring_device, therm);
}
