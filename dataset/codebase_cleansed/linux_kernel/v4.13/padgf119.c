int
gf119_i2c_pad_s_new(struct nvkm_i2c *i2c, int id, struct nvkm_i2c_pad **ppad)
{
return nvkm_i2c_pad_new_(&gf119_i2c_pad_s_func, i2c, id, ppad);
}
int
gf119_i2c_pad_x_new(struct nvkm_i2c *i2c, int id, struct nvkm_i2c_pad **ppad)
{
return nvkm_i2c_pad_new_(&gf119_i2c_pad_x_func, i2c, id, ppad);
}
