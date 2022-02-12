int
gf119_i2c_aux_new(struct nvkm_i2c_pad *pad, int index, u8 drive,
struct nvkm_i2c_aux **paux)
{
return g94_i2c_aux_new_(&gf119_i2c_aux, pad, index, drive, paux);
}
