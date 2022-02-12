int
gm107_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
return gk104_ram_ctor(fb, pram, 0x021c14);
}
