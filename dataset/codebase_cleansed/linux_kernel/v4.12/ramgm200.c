u32
gm200_ram_probe_fbp_amount(const struct nvkm_ram_func *func, u32 fbpao,
struct nvkm_device *device, int fbp, int *pltcs)
{
u32 ltcs = nvkm_rd32(device, 0x022450);
u32 fbpas = nvkm_rd32(device, 0x022458);
u32 fbpa = fbp * fbpas;
u32 size = 0;
if (!(nvkm_rd32(device, 0x021d38) & BIT(fbp))) {
u32 ltco = nvkm_rd32(device, 0x021d70 + (fbp * 4));
u32 ltcm = ~ltco & ((1 << ltcs) - 1);
while (fbpas--) {
if (!(fbpao & (1 << fbpa)))
size += func->probe_fbpa_amount(device, fbpa);
fbpa++;
}
*pltcs = hweight32(ltcm);
}
return size;
}
int
gm200_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
return gk104_ram_new_(&gm200_ram, fb, pram);
}
