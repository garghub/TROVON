static void
gf119_i2c_bus_drive_scl(struct nvkm_i2c_bus *base, int state)
{
struct gf119_i2c_bus *bus = gf119_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
nvkm_mask(device, bus->addr, 0x00000001, state ? 0x00000001 : 0);
}
static void
gf119_i2c_bus_drive_sda(struct nvkm_i2c_bus *base, int state)
{
struct gf119_i2c_bus *bus = gf119_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
nvkm_mask(device, bus->addr, 0x00000002, state ? 0x00000002 : 0);
}
static int
gf119_i2c_bus_sense_scl(struct nvkm_i2c_bus *base)
{
struct gf119_i2c_bus *bus = gf119_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
return !!(nvkm_rd32(device, bus->addr) & 0x00000010);
}
static int
gf119_i2c_bus_sense_sda(struct nvkm_i2c_bus *base)
{
struct gf119_i2c_bus *bus = gf119_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
return !!(nvkm_rd32(device, bus->addr) & 0x00000020);
}
static void
gf119_i2c_bus_init(struct nvkm_i2c_bus *base)
{
struct gf119_i2c_bus *bus = gf119_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
nvkm_wr32(device, bus->addr, 0x00000007);
}
int
gf119_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive,
struct nvkm_i2c_bus **pbus)
{
struct gf119_i2c_bus *bus;
if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
return -ENOMEM;
*pbus = &bus->base;
nvkm_i2c_bus_ctor(&gf119_i2c_bus_func, pad, id, &bus->base);
bus->addr = 0x00d014 + (drive * 0x20);
return 0;
}
