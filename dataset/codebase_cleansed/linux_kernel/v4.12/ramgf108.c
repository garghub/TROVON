u32
gf108_ram_probe_fbp_amount(const struct nvkm_ram_func *func, u32 fbpao,
struct nvkm_device *device, int fbp, int *pltcs)
{
u32 fbpt = nvkm_rd32(device, 0x022438);
u32 fbpat = nvkm_rd32(device, 0x02243c);
u32 fbpas = fbpat / fbpt;
u32 fbpa = fbp * fbpas;
u32 size = 0;
while (fbpas--) {
if (!(fbpao & BIT(fbpa)))
size += func->probe_fbpa_amount(device, fbpa);
fbpa++;
}
*pltcs = 1;
return size;
}
int
gf108_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
return gf100_ram_new_(&gf108_ram, fb, pram);
}
