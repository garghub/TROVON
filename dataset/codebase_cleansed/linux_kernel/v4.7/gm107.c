int
gm107_ce_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_engine_new_(&gm107_ce, device, index, true, pengine);
}
