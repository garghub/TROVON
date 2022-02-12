int
nv1a_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
return nvkm_fb_new_(&nv1a_fb, device, index, pfb);
}
