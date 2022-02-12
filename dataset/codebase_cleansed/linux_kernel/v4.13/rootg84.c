static int
g84_disp_root_new(struct nvkm_disp *disp, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
return nv50_disp_root_new_(&g84_disp_root, disp, oclass,
data, size, pobject);
}
