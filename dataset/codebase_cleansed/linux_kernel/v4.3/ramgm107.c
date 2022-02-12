int
gm107_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
if (!(*pram = kzalloc(sizeof(**pram), GFP_KERNEL)))
return -ENOMEM;
return gf100_ram_ctor(&gm107_ram_func, fb, 0x021c14, *pram);
}
