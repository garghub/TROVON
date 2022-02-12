static void
nv04_i2c_bus_drive_scl(struct nvkm_i2c_bus *base, int state)
{
struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
u8 val = nvkm_rdvgac(device, 0, bus->drive);
if (state) val |= 0x20;
else val &= 0xdf;
nvkm_wrvgac(device, 0, bus->drive, val | 0x01);
}
static void
nv04_i2c_bus_drive_sda(struct nvkm_i2c_bus *base, int state)
{
struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
u8 val = nvkm_rdvgac(device, 0, bus->drive);
if (state) val |= 0x10;
else val &= 0xef;
nvkm_wrvgac(device, 0, bus->drive, val | 0x01);
}
static int
nv04_i2c_bus_sense_scl(struct nvkm_i2c_bus *base)
{
struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
return !!(nvkm_rdvgac(device, 0, bus->sense) & 0x04);
}
static int
nv04_i2c_bus_sense_sda(struct nvkm_i2c_bus *base)
{
struct nv04_i2c_bus *bus = nv04_i2c_bus(base);
struct nvkm_device *device = bus->base.pad->i2c->subdev.device;
return !!(nvkm_rdvgac(device, 0, bus->sense) & 0x08);
}
int
nv04_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive, u8 sense,
struct nvkm_i2c_bus **pbus)
{
struct nv04_i2c_bus *bus;
if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
return -ENOMEM;
*pbus = &bus->base;
nvkm_i2c_bus_ctor(&nv04_i2c_bus_func, pad, id, &bus->base);
bus->drive = drive;
bus->sense = sense;
return 0;
}
