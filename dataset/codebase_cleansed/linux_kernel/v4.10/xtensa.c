static int
nvkm_xtensa_oclass_get(struct nvkm_oclass *oclass, int index)
{
struct nvkm_xtensa *xtensa = nvkm_xtensa(oclass->engine);
int c = 0;
while (xtensa->func->sclass[c].oclass) {
if (c++ == index) {
oclass->base = xtensa->func->sclass[index];
return index;
}
}
return c;
}
static int
nvkm_xtensa_cclass_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
return nvkm_gpuobj_new(object->engine->subdev.device, 0x10000, align,
true, parent, pgpuobj);
}
static void
nvkm_xtensa_intr(struct nvkm_engine *engine)
{
struct nvkm_xtensa *xtensa = nvkm_xtensa(engine);
struct nvkm_subdev *subdev = &xtensa->engine.subdev;
struct nvkm_device *device = subdev->device;
const u32 base = xtensa->addr;
u32 unk104 = nvkm_rd32(device, base + 0xd04);
u32 intr = nvkm_rd32(device, base + 0xc20);
u32 chan = nvkm_rd32(device, base + 0xc28);
u32 unk10c = nvkm_rd32(device, base + 0xd0c);
if (intr & 0x10)
nvkm_warn(subdev, "Watchdog interrupt, engine hung.\n");
nvkm_wr32(device, base + 0xc20, intr);
intr = nvkm_rd32(device, base + 0xc20);
if (unk104 == 0x10001 && unk10c == 0x200 && chan && !intr) {
nvkm_debug(subdev, "Enabling FIFO_CTRL\n");
nvkm_mask(device, xtensa->addr + 0xd94, 0, xtensa->func->fifo_val);
}
}
static int
nvkm_xtensa_fini(struct nvkm_engine *engine, bool suspend)
{
struct nvkm_xtensa *xtensa = nvkm_xtensa(engine);
struct nvkm_device *device = xtensa->engine.subdev.device;
const u32 base = xtensa->addr;
nvkm_wr32(device, base + 0xd84, 0);
nvkm_wr32(device, base + 0xd94, 0);
if (!suspend)
nvkm_memory_del(&xtensa->gpu_fw);
return 0;
}
static int
nvkm_xtensa_init(struct nvkm_engine *engine)
{
struct nvkm_xtensa *xtensa = nvkm_xtensa(engine);
struct nvkm_subdev *subdev = &xtensa->engine.subdev;
struct nvkm_device *device = subdev->device;
const u32 base = xtensa->addr;
const struct firmware *fw;
char name[32];
int i, ret;
u64 addr, size;
u32 tmp;
if (!xtensa->gpu_fw) {
snprintf(name, sizeof(name), "nouveau/nv84_xuc%03x",
xtensa->addr >> 12);
ret = request_firmware(&fw, name, device->dev);
if (ret) {
nvkm_warn(subdev, "unable to load firmware %s\n", name);
return ret;
}
if (fw->size > 0x40000) {
nvkm_warn(subdev, "firmware %s too large\n", name);
release_firmware(fw);
return -EINVAL;
}
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST,
0x40000, 0x1000, false,
&xtensa->gpu_fw);
if (ret) {
release_firmware(fw);
return ret;
}
nvkm_kmap(xtensa->gpu_fw);
for (i = 0; i < fw->size / 4; i++)
nvkm_wo32(xtensa->gpu_fw, i * 4, *((u32 *)fw->data + i));
nvkm_done(xtensa->gpu_fw);
release_firmware(fw);
}
addr = nvkm_memory_addr(xtensa->gpu_fw);
size = nvkm_memory_size(xtensa->gpu_fw);
nvkm_wr32(device, base + 0xd10, 0x1fffffff);
nvkm_wr32(device, base + 0xd08, 0x0fffffff);
nvkm_wr32(device, base + 0xd28, xtensa->func->unkd28);
nvkm_wr32(device, base + 0xc20, 0x3f);
nvkm_wr32(device, base + 0xd84, 0x3f);
nvkm_wr32(device, base + 0xcc0, addr >> 8);
nvkm_wr32(device, base + 0xcc4, 0x1c);
nvkm_wr32(device, base + 0xcc8, size >> 8);
tmp = nvkm_rd32(device, 0x0);
nvkm_wr32(device, base + 0xde0, tmp);
nvkm_wr32(device, base + 0xce8, 0xf);
nvkm_wr32(device, base + 0xc20, 0x3f);
nvkm_wr32(device, base + 0xd84, 0x3f);
return 0;
}
static void *
nvkm_xtensa_dtor(struct nvkm_engine *engine)
{
return nvkm_xtensa(engine);
}
int
nvkm_xtensa_new_(const struct nvkm_xtensa_func *func,
struct nvkm_device *device, int index, bool enable,
u32 addr, struct nvkm_engine **pengine)
{
struct nvkm_xtensa *xtensa;
if (!(xtensa = kzalloc(sizeof(*xtensa), GFP_KERNEL)))
return -ENOMEM;
xtensa->func = func;
xtensa->addr = addr;
*pengine = &xtensa->engine;
return nvkm_engine_ctor(&nvkm_xtensa, device, index,
enable, &xtensa->engine);
}
