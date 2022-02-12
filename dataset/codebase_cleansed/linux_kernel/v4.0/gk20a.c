static void
gk20a_ibus_init_priv_ring(struct gk20a_ibus_priv *priv)
{
nv_mask(priv, 0x137250, 0x3f, 0);
nv_mask(priv, 0x000200, 0x20, 0);
usleep_range(20, 30);
nv_mask(priv, 0x000200, 0x20, 0x20);
nv_wr32(priv, 0x12004c, 0x4);
nv_wr32(priv, 0x122204, 0x2);
nv_rd32(priv, 0x122204);
}
static void
gk20a_ibus_intr(struct nvkm_subdev *subdev)
{
struct gk20a_ibus_priv *priv = (void *)subdev;
u32 status0 = nv_rd32(priv, 0x120058);
if (status0 & 0x7) {
nv_debug(priv, "resetting priv ring\n");
gk20a_ibus_init_priv_ring(priv);
}
nv_mask(priv, 0x12004c, 0x2, 0x2);
if (!nv_wait(subdev, 0x12004c, 0x3f, 0x00))
nv_warn(priv, "timeout waiting for ringmaster ack\n");
}
static int
gk20a_ibus_init(struct nvkm_object *object)
{
struct gk20a_ibus_priv *priv = (void *)object;
int ret;
ret = _nvkm_ibus_init(object);
if (ret)
return ret;
gk20a_ibus_init_priv_ring(priv);
return 0;
}
static int
gk20a_ibus_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct gk20a_ibus_priv *priv;
int ret;
ret = nvkm_ibus_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->intr = gk20a_ibus_intr;
return 0;
}
