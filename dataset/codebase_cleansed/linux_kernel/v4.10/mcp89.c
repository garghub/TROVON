int
mcp89_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
return nv50_fb_new_(&mcp89_fb, device, index, pfb);
}
