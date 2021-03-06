static void
pmu_code(struct nv50_devinit *init, u32 pmu, u32 img, u32 len, bool sec)
{
struct nvkm_device *device = init->base.subdev.device;
struct nvkm_bios *bios = device->bios;
int i;
nvkm_wr32(device, 0x10a180, 0x01000000 | (sec ? 0x10000000 : 0) | pmu);
for (i = 0; i < len; i += 4) {
if ((i & 0xff) == 0)
nvkm_wr32(device, 0x10a188, (pmu + i) >> 8);
nvkm_wr32(device, 0x10a184, nvbios_rd32(bios, img + i));
}
while (i & 0xff) {
nvkm_wr32(device, 0x10a184, 0x00000000);
i += 4;
}
}
static void
pmu_data(struct nv50_devinit *init, u32 pmu, u32 img, u32 len)
{
struct nvkm_device *device = init->base.subdev.device;
struct nvkm_bios *bios = device->bios;
int i;
nvkm_wr32(device, 0x10a1c0, 0x01000000 | pmu);
for (i = 0; i < len; i += 4)
nvkm_wr32(device, 0x10a1c4, nvbios_rd32(bios, img + i));
}
static u32
pmu_args(struct nv50_devinit *init, u32 argp, u32 argi)
{
struct nvkm_device *device = init->base.subdev.device;
nvkm_wr32(device, 0x10a1c0, argp);
nvkm_wr32(device, 0x10a1c0, nvkm_rd32(device, 0x10a1c4) + argi);
return nvkm_rd32(device, 0x10a1c4);
}
static void
pmu_exec(struct nv50_devinit *init, u32 init_addr)
{
struct nvkm_device *device = init->base.subdev.device;
nvkm_wr32(device, 0x10a104, init_addr);
nvkm_wr32(device, 0x10a10c, 0x00000000);
nvkm_wr32(device, 0x10a100, 0x00000002);
}
static int
pmu_load(struct nv50_devinit *init, u8 type, bool post,
u32 *init_addr_pmu, u32 *args_addr_pmu)
{
struct nvkm_subdev *subdev = &init->base.subdev;
struct nvkm_bios *bios = subdev->device->bios;
struct nvbios_pmuR pmu;
if (!nvbios_pmuRm(bios, type, &pmu)) {
nvkm_error(subdev, "VBIOS PMU fuc %02x not found\n", type);
return -EINVAL;
}
if (!post)
return 0;
pmu_code(init, pmu.boot_addr_pmu, pmu.boot_addr, pmu.boot_size, false);
pmu_code(init, pmu.code_addr_pmu, pmu.code_addr, pmu.code_size, true);
pmu_data(init, pmu.data_addr_pmu, pmu.data_addr, pmu.data_size);
if (init_addr_pmu) {
*init_addr_pmu = pmu.init_addr_pmu;
*args_addr_pmu = pmu.args_addr_pmu;
return 0;
}
return pmu_exec(init, pmu.init_addr_pmu), 0;
}
static int
gm204_devinit_post(struct nvkm_devinit *base, bool post)
{
struct nv50_devinit *init = nv50_devinit(base);
struct nvkm_subdev *subdev = &init->base.subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_bios *bios = device->bios;
struct bit_entry bit_I;
u32 exec, args;
int ret;
if (bit_entry(bios, 'I', &bit_I) || bit_I.version != 1 ||
bit_I.length < 0x1c) {
nvkm_error(subdev, "VBIOS PMU init data not found\n");
return -EINVAL;
}
if (post) {
nvkm_mask(device, 0x000200, 0x00002000, 0x00000000);
nvkm_mask(device, 0x000200, 0x00002000, 0x00002000);
nvkm_rd32(device, 0x000200);
while (nvkm_rd32(device, 0x10a10c) & 0x00000006) {
}
}
ret = pmu_load(init, 0x04, post, &exec, &args);
if (ret)
return ret;
if (post) {
u32 pmu = pmu_args(init, args + 0x08, 0x08);
u32 img = nvbios_rd16(bios, bit_I.offset + 0x14);
u32 len = nvbios_rd16(bios, bit_I.offset + 0x16);
pmu_data(init, pmu, img, len);
}
if (post) {
u32 pmu = pmu_args(init, args + 0x08, 0x10);
u32 img = nvbios_rd16(bios, bit_I.offset + 0x18);
u32 len = nvbios_rd16(bios, bit_I.offset + 0x1a);
pmu_data(init, pmu, img, len);
}
if (post) {
nvkm_wr32(device, 0x10a040, 0x00005000);
pmu_exec(init, exec);
while (!(nvkm_rd32(device, 0x10a040) & 0x00002000)) {
}
}
return pmu_load(init, 0x01, post, NULL, NULL);
}
int
gm204_devinit_new(struct nvkm_device *device, int index,
struct nvkm_devinit **pinit)
{
return nv50_devinit_new_(&gm204_devinit, device, index, pinit);
}
