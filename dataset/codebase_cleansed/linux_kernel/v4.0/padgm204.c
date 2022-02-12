static int
gm204_i2c_pad_fini(struct nvkm_object *object, bool suspend)
{
struct nvkm_i2c *i2c = (void *)nvkm_i2c(object);
struct gm204_i2c_pad *pad = (void *)object;
nv_mask(i2c, 0x00d97c + pad->addr, 0x00000001, 0x00000001);
return nvkm_i2c_pad_fini(&pad->base, suspend);
}
static int
gm204_i2c_pad_init(struct nvkm_object *object)
{
struct nvkm_i2c *i2c = (void *)nvkm_i2c(object);
struct gm204_i2c_pad *pad = (void *)object;
switch (nv_oclass(pad->base.next)->handle) {
case NV_I2C_TYPE_DCBI2C(DCB_I2C_NVIO_AUX):
nv_mask(i2c, 0x00d970 + pad->addr, 0x0000c003, 0x00000002);
break;
case NV_I2C_TYPE_DCBI2C(DCB_I2C_NVIO_BIT):
default:
nv_mask(i2c, 0x00d970 + pad->addr, 0x0000c003, 0x0000c001);
break;
}
nv_mask(i2c, 0x00d97c + pad->addr, 0x00000001, 0x00000000);
return nvkm_i2c_pad_init(&pad->base);
}
static int
gm204_i2c_pad_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 index,
struct nvkm_object **pobject)
{
struct gm204_i2c_pad *pad;
int ret;
ret = nvkm_i2c_pad_create(parent, engine, oclass, index, &pad);
*pobject = nv_object(pad);
if (ret)
return ret;
pad->addr = index * 0x50;;
return 0;
}
