int
nv49_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
return nvkm_fb_new_(&nv49_fb, device, index, pfb);
}
