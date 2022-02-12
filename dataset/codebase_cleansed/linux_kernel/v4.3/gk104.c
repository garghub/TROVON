int
gk104_msvld_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_msvld_new_(&gk104_msvld, device, index, pengine);
}
