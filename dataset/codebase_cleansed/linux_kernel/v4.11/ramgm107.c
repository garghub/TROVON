int\r\ngm107_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)\r\n{\r\nreturn gk104_ram_ctor(fb, pram, 0x021c14);\r\n}
