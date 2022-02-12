int
nv04_i2c_pad_new(struct nvkm_i2c *i2c, int id, struct nvkm_i2c_pad **ppad)
{
return nvkm_i2c_pad_new_(&nv04_i2c_pad_func, i2c, id, ppad);
}
