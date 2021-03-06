u32
_nouveau_xtensa_rd32(struct nouveau_object *object, u64 addr)
{
struct nouveau_xtensa *xtensa = (void *)object;
return nv_rd32(xtensa, xtensa->addr + addr);
}
void
_nouveau_xtensa_wr32(struct nouveau_object *object, u64 addr, u32 data)
{
struct nouveau_xtensa *xtensa = (void *)object;
nv_wr32(xtensa, xtensa->addr + addr, data);
}
int
_nouveau_xtensa_engctx_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_engctx *engctx;
int ret;
ret = nouveau_engctx_create(parent, engine, oclass, NULL,
0x10000, 0x1000,
NVOBJ_FLAG_ZERO_ALLOC, &engctx);
*pobject = nv_object(engctx);
return ret;
}
void
_nouveau_xtensa_intr(struct nouveau_subdev *subdev)
{
struct nouveau_xtensa *xtensa = (void *)subdev;
u32 unk104 = nv_ro32(xtensa, 0xd04);
u32 intr = nv_ro32(xtensa, 0xc20);
u32 chan = nv_ro32(xtensa, 0xc28);
u32 unk10c = nv_ro32(xtensa, 0xd0c);
if (intr & 0x10)
nv_warn(xtensa, "Watchdog interrupt, engine hung.\n");
nv_wo32(xtensa, 0xc20, intr);
intr = nv_ro32(xtensa, 0xc20);
if (unk104 == 0x10001 && unk10c == 0x200 && chan && !intr) {
nv_debug(xtensa, "Enabling FIFO_CTRL\n");
nv_mask(xtensa, xtensa->addr + 0xd94, 0, xtensa->fifo_val);
}
}
int
nouveau_xtensa_create_(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, u32 addr, bool enable,
const char *iname, const char *fname,
int length, void **pobject)
{
struct nouveau_xtensa *xtensa;
int ret;
ret = nouveau_engine_create_(parent, engine, oclass, enable, iname,
fname, length, pobject);
xtensa = *pobject;
if (ret)
return ret;
nv_subdev(xtensa)->intr = _nouveau_xtensa_intr;
xtensa->addr = addr;
return 0;
}
int
_nouveau_xtensa_init(struct nouveau_object *object)
{
struct nouveau_device *device = nv_device(object);
struct nouveau_xtensa *xtensa = (void *)object;
const struct firmware *fw;
char name[32];
int i, ret;
u32 tmp;
ret = nouveau_engine_init(&xtensa->base);
if (ret)
return ret;
if (!xtensa->gpu_fw) {
snprintf(name, sizeof(name), "nouveau/nv84_xuc%03x",
xtensa->addr >> 12);
ret = request_firmware(&fw, name, &device->pdev->dev);
if (ret) {
nv_warn(xtensa, "unable to load firmware %s\n", name);
return ret;
}
if (fw->size > 0x40000) {
nv_warn(xtensa, "firmware %s too large\n", name);
release_firmware(fw);
return -EINVAL;
}
ret = nouveau_gpuobj_new(object, NULL, 0x40000, 0x1000, 0,
&xtensa->gpu_fw);
if (ret) {
release_firmware(fw);
return ret;
}
nv_debug(xtensa, "Loading firmware to address: 0x%llx\n",
xtensa->gpu_fw->addr);
for (i = 0; i < fw->size / 4; i++)
nv_wo32(xtensa->gpu_fw, i * 4, *((u32 *)fw->data + i));
release_firmware(fw);
}
nv_wo32(xtensa, 0xd10, 0x1fffffff);
nv_wo32(xtensa, 0xd08, 0x0fffffff);
nv_wo32(xtensa, 0xd28, xtensa->unkd28);
nv_wo32(xtensa, 0xc20, 0x3f);
nv_wo32(xtensa, 0xd84, 0x3f);
nv_wo32(xtensa, 0xcc0, xtensa->gpu_fw->addr >> 8);
nv_wo32(xtensa, 0xcc4, 0x1c);
nv_wo32(xtensa, 0xcc8, xtensa->gpu_fw->size >> 8);
tmp = nv_rd32(xtensa, 0x0);
nv_wo32(xtensa, 0xde0, tmp);
nv_wo32(xtensa, 0xce8, 0xf);
nv_wo32(xtensa, 0xc20, 0x3f);
nv_wo32(xtensa, 0xd84, 0x3f);
return 0;
}
int
_nouveau_xtensa_fini(struct nouveau_object *object, bool suspend)
{
struct nouveau_xtensa *xtensa = (void *)object;
nv_wo32(xtensa, 0xd84, 0);
nv_wo32(xtensa, 0xd94, 0);
if (!suspend)
nouveau_gpuobj_ref(NULL, &xtensa->gpu_fw);
return nouveau_engine_fini(&xtensa->base, suspend);
}
