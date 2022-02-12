int
gm107_ce_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
if (index == NVKM_ENGINE_CE0) {
return nvkm_engine_new_(&gm107_ce, device, index,
0x00000040, true, pengine);
} else
if (index == NVKM_ENGINE_CE1) {
return nvkm_engine_new_(&gm107_ce, device, index,
0x00000080, true, pengine);
} else
if (index == NVKM_ENGINE_CE2) {
return nvkm_engine_new_(&gm107_ce, device, index,
0x00200000, true, pengine);
}
return -ENODEV;
}
