static void
nv4e_i2c_bus_drive_scl(struct nvkm_i2c_bus *base, int state)
{
struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
nvkm_mask(device, bus->addr, 0x2f, state ? 0x21 : 0x01);
}
static void
nv4e_i2c_bus_drive_sda(struct nvkm_i2c_bus *base, int state)
{
struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
nvkm_mask(device, bus->addr, 0x1f, state ? 0x11 : 0x01);
}
static int
nv4e_i2c_bus_sense_scl(struct nvkm_i2c_bus *base)
{
struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
return !!(nvkm_rd32(device, bus->addr) & 0x00040000);
}
static int
nv4e_i2c_bus_sense_sda(struct nvkm_i2c_bus *base)
{
struct nv4e_i2c_bus *bus = nv4e_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
return !!(nvkm_rd32(device, bus->addr) & 0x00080000);
}
int
nv4e_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive,
struct nvkm_i2c_bus **pbus)
{
struct nv4e_i2c_bus *bus;
if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
return -ENOMEM;
*pbus = &bus->base;
nvkm_i2c_bus_ctor(&nv4e_i2c_bus_func, pad, id, &bus->base);
bus->addr = 0x600800 + drive;
return 0;
}
