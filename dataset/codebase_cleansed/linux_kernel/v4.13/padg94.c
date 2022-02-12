void
g94_i2c_pad_mode(struct nvkm_i2c_pad *pad, enum nvkm_i2c_pad_mode mode)
{
struct nvkm_subdev *subdev = &pad->i2c->subdev;
struct nvkm_device *device = subdev->device;
const u32 base = (pad->id - NVKM_I2C_PAD_HYBRID(0)) * 0x50;
switch (mode) {
case NVKM_I2C_PAD_OFF:
nvkm_mask(device, 0x00e50c + base, 0x00000001, 0x00000001);
break;
case NVKM_I2C_PAD_I2C:
nvkm_mask(device, 0x00e500 + base, 0x0000c003, 0x0000c001);
nvkm_mask(device, 0x00e50c + base, 0x00000001, 0x00000000);
break;
case NVKM_I2C_PAD_AUX:
nvkm_mask(device, 0x00e500 + base, 0x0000c003, 0x00000002);
nvkm_mask(device, 0x00e50c + base, 0x00000001, 0x00000000);
break;
default:
WARN_ON(1);
break;
}
}
int
g94_i2c_pad_s_new(struct nvkm_i2c *i2c, int id, struct nvkm_i2c_pad **ppad)
{
return nvkm_i2c_pad_new_(&g94_i2c_pad_s_func, i2c, id, ppad);
}
int
g94_i2c_pad_x_new(struct nvkm_i2c *i2c, int id, struct nvkm_i2c_pad **ppad)
{
return nvkm_i2c_pad_new_(&g94_i2c_pad_x_func, i2c, id, ppad);
}
