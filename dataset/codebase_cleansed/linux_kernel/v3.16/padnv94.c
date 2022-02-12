static int
nv94_i2c_pad_fini(struct nouveau_object *object, bool suspend)
{
struct nouveau_i2c *i2c = (void *)object->engine;
struct nv94_i2c_pad *pad = (void *)object;
nv_mask(i2c, 0x00e50c + pad->addr, 0x00000001, 0x00000001);
return nvkm_i2c_pad_fini(&pad->base, suspend);
}
static int
nv94_i2c_pad_init(struct nouveau_object *object)
{
struct nouveau_i2c *i2c = (void *)object->engine;
struct nv94_i2c_pad *pad = (void *)object;
switch (nv_oclass(pad->base.next)->handle) {
case NV_I2C_TYPE_DCBI2C(DCB_I2C_NVIO_AUX):
nv_mask(i2c, 0x00e500 + pad->addr, 0x0000c003, 0x00000002);
break;
case NV_I2C_TYPE_DCBI2C(DCB_I2C_NVIO_BIT):
default:
nv_mask(i2c, 0x00e500 + pad->addr, 0x0000c003, 0x0000c001);
break;
}
nv_mask(i2c, 0x00e50c + pad->addr, 0x00000001, 0x00000000);
return nvkm_i2c_pad_init(&pad->base);
}
static int
nv94_i2c_pad_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 index,
struct nouveau_object **pobject)
{
struct nv94_i2c_pad *pad;
int ret;
ret = nvkm_i2c_pad_create(parent, engine, oclass, index, &pad);
*pobject = nv_object(pad);
if (ret)
return ret;
pad->addr = index * 0x50;;
return 0;
}
