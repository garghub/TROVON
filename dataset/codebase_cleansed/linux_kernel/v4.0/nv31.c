static void
nv31_bus_intr(struct nvkm_subdev *subdev)
{
struct nvkm_bus *pbus = nvkm_bus(subdev);
u32 stat = nv_rd32(pbus, 0x001100) & nv_rd32(pbus, 0x001140);
u32 gpio = nv_rd32(pbus, 0x001104) & nv_rd32(pbus, 0x001144);
if (gpio) {
subdev = nvkm_subdev(pbus, NVDEV_SUBDEV_GPIO);
if (subdev && subdev->intr)
subdev->intr(subdev);
}
if (stat & 0x00000008) {
u32 addr = nv_rd32(pbus, 0x009084);
u32 data = nv_rd32(pbus, 0x009088);
nv_error(pbus, "MMIO %s of 0x%08x FAULT at 0x%06x\n",
(addr & 0x00000002) ? "write" : "read", data,
(addr & 0x00fffffc));
stat &= ~0x00000008;
nv_wr32(pbus, 0x001100, 0x00000008);
}
if (stat & 0x00070000) {
subdev = nvkm_subdev(pbus, NVDEV_SUBDEV_THERM);
if (subdev && subdev->intr)
subdev->intr(subdev);
stat &= ~0x00070000;
nv_wr32(pbus, 0x001100, 0x00070000);
}
if (stat) {
nv_error(pbus, "unknown intr 0x%08x\n", stat);
nv_mask(pbus, 0x001140, stat, 0x00000000);
}
}
static int
nv31_bus_init(struct nvkm_object *object)
{
struct nv04_bus_priv *priv = (void *)object;
int ret;
ret = nvkm_bus_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x001100, 0xffffffff);
nv_wr32(priv, 0x001140, 0x00070008);
return 0;
}
