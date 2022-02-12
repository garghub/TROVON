u32
_nouveau_falcon_rd32(struct nouveau_object *object, u64 addr)
{
struct nouveau_falcon *falcon = (void *)object;
return nv_rd32(falcon, falcon->addr + addr);
}
void
_nouveau_falcon_wr32(struct nouveau_object *object, u64 addr, u32 data)
{
struct nouveau_falcon *falcon = (void *)object;
nv_wr32(falcon, falcon->addr + addr, data);
}
int
_nouveau_falcon_init(struct nouveau_object *object)
{
struct nouveau_device *device = nv_device(object);
struct nouveau_falcon *falcon = (void *)object;
const struct firmware *fw;
char name[32] = "internal";
int ret, i;
u32 caps;
ret = nouveau_engine_init(&falcon->base);
if (ret)
return ret;
if (device->chipset < 0xa3 ||
device->chipset == 0xaa || device->chipset == 0xac) {
falcon->version = 0;
falcon->secret = (falcon->addr == 0x087000) ? 1 : 0;
} else {
caps = nv_ro32(falcon, 0x12c);
falcon->version = (caps & 0x0000000f);
falcon->secret = (caps & 0x00000030) >> 4;
}
caps = nv_ro32(falcon, 0x108);
falcon->code.limit = (caps & 0x000001ff) << 8;
falcon->data.limit = (caps & 0x0003fe00) >> 1;
nv_debug(falcon, "falcon version: %d\n", falcon->version);
nv_debug(falcon, "secret level: %d\n", falcon->secret);
nv_debug(falcon, "code limit: %d\n", falcon->code.limit);
nv_debug(falcon, "data limit: %d\n", falcon->data.limit);
if (falcon->secret && falcon->version < 4) {
if (!falcon->version)
nv_wait(falcon, 0x008, 0x00000010, 0x00000010);
else
nv_wait(falcon, 0x180, 0x80000000, 0);
nv_wo32(falcon, 0x004, 0x00000010);
}
nv_wo32(falcon, 0x014, 0xffffffff);
if (!falcon->code.data) {
snprintf(name, sizeof(name), "nouveau/nv%02x_fuc%03x",
device->chipset, falcon->addr >> 12);
ret = request_firmware(&fw, name, &device->pdev->dev);
if (ret == 0) {
falcon->code.data = kmemdup(fw->data, fw->size, GFP_KERNEL);
falcon->code.size = fw->size;
falcon->data.data = NULL;
falcon->data.size = 0;
release_firmware(fw);
}
falcon->external = true;
}
if (!falcon->code.data) {
snprintf(name, sizeof(name), "nouveau/nv%02x_fuc%03xd",
device->chipset, falcon->addr >> 12);
ret = request_firmware(&fw, name, &device->pdev->dev);
if (ret) {
nv_error(falcon, "unable to load firmware data\n");
return ret;
}
falcon->data.data = kmemdup(fw->data, fw->size, GFP_KERNEL);
falcon->data.size = fw->size;
release_firmware(fw);
if (!falcon->data.data)
return -ENOMEM;
snprintf(name, sizeof(name), "nouveau/nv%02x_fuc%03xc",
device->chipset, falcon->addr >> 12);
ret = request_firmware(&fw, name, &device->pdev->dev);
if (ret) {
nv_error(falcon, "unable to load firmware code\n");
return ret;
}
falcon->code.data = kmemdup(fw->data, fw->size, GFP_KERNEL);
falcon->code.size = fw->size;
release_firmware(fw);
if (!falcon->code.data)
return -ENOMEM;
}
nv_debug(falcon, "firmware: %s (%s)\n", name, falcon->data.data ?
"static code/data segments" : "self-bootstrapping");
if (!falcon->data.data && !falcon->core) {
ret = nouveau_gpuobj_new(object->parent, NULL,
falcon->code.size, 256, 0,
&falcon->core);
if (ret) {
nv_error(falcon, "core allocation failed, %d\n", ret);
return ret;
}
for (i = 0; i < falcon->code.size; i += 4)
nv_wo32(falcon->core, i, falcon->code.data[i / 4]);
}
if (falcon->core) {
if (device->card_type < NV_C0)
nv_wo32(falcon, 0x618, 0x04000000);
else
nv_wo32(falcon, 0x618, 0x00000114);
nv_wo32(falcon, 0x11c, 0);
nv_wo32(falcon, 0x110, falcon->core->addr >> 8);
nv_wo32(falcon, 0x114, 0);
nv_wo32(falcon, 0x118, 0x00006610);
} else {
if (falcon->code.size > falcon->code.limit ||
falcon->data.size > falcon->data.limit) {
nv_error(falcon, "ucode exceeds falcon limit(s)\n");
return -EINVAL;
}
if (falcon->version < 3) {
nv_wo32(falcon, 0xff8, 0x00100000);
for (i = 0; i < falcon->code.size / 4; i++)
nv_wo32(falcon, 0xff4, falcon->code.data[i]);
} else {
nv_wo32(falcon, 0x180, 0x01000000);
for (i = 0; i < falcon->code.size / 4; i++) {
if ((i & 0x3f) == 0)
nv_wo32(falcon, 0x188, i >> 6);
nv_wo32(falcon, 0x184, falcon->code.data[i]);
}
}
}
if (falcon->version < 3) {
nv_wo32(falcon, 0xff8, 0x00000000);
for (i = 0; !falcon->core && i < falcon->data.size / 4; i++)
nv_wo32(falcon, 0xff4, falcon->data.data[i]);
for (; i < falcon->data.limit; i += 4)
nv_wo32(falcon, 0xff4, 0x00000000);
} else {
nv_wo32(falcon, 0x1c0, 0x01000000);
for (i = 0; !falcon->core && i < falcon->data.size / 4; i++)
nv_wo32(falcon, 0x1c4, falcon->data.data[i]);
for (; i < falcon->data.limit / 4; i++)
nv_wo32(falcon, 0x1c4, 0x00000000);
}
nv_wo32(falcon, 0x10c, 0x00000001);
nv_wo32(falcon, 0x104, 0x00000000);
nv_wo32(falcon, 0x100, 0x00000002);
nv_wo32(falcon, 0x048, 0x00000003);
return 0;
}
int
_nouveau_falcon_fini(struct nouveau_object *object, bool suspend)
{
struct nouveau_falcon *falcon = (void *)object;
if (!suspend) {
nouveau_gpuobj_ref(NULL, &falcon->core);
if (falcon->external) {
kfree(falcon->data.data);
kfree(falcon->code.data);
falcon->code.data = NULL;
}
}
nv_mo32(falcon, 0x048, 0x00000003, 0x00000000);
nv_wo32(falcon, 0x014, 0xffffffff);
return nouveau_engine_fini(&falcon->base, suspend);
}
int
nouveau_falcon_create_(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, u32 addr, bool enable,
const char *iname, const char *fname,
int length, void **pobject)
{
struct nouveau_falcon *falcon;
int ret;
ret = nouveau_engine_create_(parent, engine, oclass, enable, iname,
fname, length, pobject);
falcon = *pobject;
if (ret)
return ret;
falcon->addr = addr;
return 0;
}
