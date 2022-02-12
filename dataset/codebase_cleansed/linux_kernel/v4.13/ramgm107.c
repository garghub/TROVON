u32
gm107_ram_probe_fbp(const struct nvkm_ram_func *func,
struct nvkm_device *device, int fbp, int *pltcs)
{
u32 fbpao = nvkm_rd32(device, 0x021c14);
return func->probe_fbp_amount(func, fbpao, device, fbp, pltcs);
}
int
gm107_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
return gk104_ram_new_(&gm107_ram, fb, pram);
}
