int
nv4e_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
return nvkm_fb_new_(&nv4e_fb, device, index, pfb);
}
