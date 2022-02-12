int
gp104_ce_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_engine_new_(&gp104_ce, device, index, true, pengine);
}
