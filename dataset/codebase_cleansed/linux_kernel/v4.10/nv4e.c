int
nv4e_i2c_new(struct nvkm_device *device, int index, struct nvkm_i2c **pi2c)
{
return nvkm_i2c_new_(&nv4e_i2c, device, index, pi2c);
}
