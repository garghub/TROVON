static bool
shadow_fetch(struct nvkm_bios *bios, struct shadow *mthd, u32 upto)
{
const u32 limit = (upto + 3) & ~3;
const u32 start = bios->size;
void *data = mthd->data;
if (nvbios_extend(bios, limit) > 0) {
u32 read = mthd->func->read(data, start, limit - start, bios);
bios->size = start + read;
}
return bios->size >= upto;
}
static int
shadow_image(struct nvkm_bios *bios, int idx, u32 offset, struct shadow *mthd)
{
struct nvkm_subdev *subdev = &bios->subdev;
struct nvbios_image image;
int score = 1;
if (mthd->func->no_pcir) {
image.base = 0;
image.type = 0;
image.size = mthd->func->size(mthd->data);
image.last = 1;
} else {
if (!shadow_fetch(bios, mthd, offset + 0x1000)) {
nvkm_debug(subdev, "%08x: header fetch failed\n",
offset);
return 0;
}
if (!nvbios_image(bios, idx, &image)) {
nvkm_debug(subdev, "image %d invalid\n", idx);
return 0;
}
}
nvkm_debug(subdev, "%08x: type %02x, %d bytes\n",
image.base, image.type, image.size);
if (!shadow_fetch(bios, mthd, image.size)) {
nvkm_debug(subdev, "%08x: fetch failed\n", image.base);
return 0;
}
switch (image.type) {
case 0x00:
if (!mthd->func->ignore_checksum &&
nvbios_checksum(&bios->data[image.base], image.size)) {
nvkm_debug(subdev, "%08x: checksum failed\n",
image.base);
if (!mthd->func->require_checksum) {
if (mthd->func->rw)
score += 1;
score += 1;
} else
return 0;
} else {
score += 3;
}
break;
default:
score += 3;
break;
}
if (!image.last)
score += shadow_image(bios, idx + 1, offset + image.size, mthd);
return score;
}
static int
shadow_method(struct nvkm_bios *bios, struct shadow *mthd, const char *name)
{
const struct nvbios_source *func = mthd->func;
struct nvkm_subdev *subdev = &bios->subdev;
if (func->name) {
nvkm_debug(subdev, "trying %s...\n", name ? name : func->name);
if (func->init) {
mthd->data = func->init(bios, name);
if (IS_ERR(mthd->data)) {
mthd->data = NULL;
return 0;
}
}
mthd->score = shadow_image(bios, 0, 0, mthd);
if (func->fini)
func->fini(mthd->data);
nvkm_debug(subdev, "scored %d\n", mthd->score);
mthd->data = bios->data;
mthd->size = bios->size;
bios->data = NULL;
bios->size = 0;
}
return mthd->score;
}
static u32
shadow_fw_read(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
const struct firmware *fw = data;
if (offset + length <= fw->size) {
memcpy(bios->data + offset, fw->data + offset, length);
return length;
}
return 0;
}
static void *
shadow_fw_init(struct nvkm_bios *bios, const char *name)
{
struct device *dev = bios->subdev.device->dev;
const struct firmware *fw;
int ret = request_firmware(&fw, name, dev);
if (ret)
return ERR_PTR(-ENOENT);
return (void *)fw;
}
int
nvbios_shadow(struct nvkm_bios *bios)
{
struct nvkm_subdev *subdev = &bios->subdev;
struct nvkm_device *device = subdev->device;
struct shadow mthds[] = {
{ 0, &nvbios_of },
{ 0, &nvbios_ramin },
{ 0, &nvbios_rom },
{ 0, &nvbios_acpi_fast },
{ 4, &nvbios_acpi_slow },
{ 1, &nvbios_pcirom },
{ 1, &nvbios_platform },
{}
}, *mthd, *best = NULL;
const char *optarg;
char *source;
int optlen;
optarg = nvkm_stropt(device->cfgopt, "NvBios", &optlen);
source = optarg ? kstrndup(optarg, optlen, GFP_KERNEL) : NULL;
if (source) {
for (mthd = mthds; mthd->func; mthd++) {
if (mthd->func->name &&
!strcasecmp(source, mthd->func->name)) {
best = mthd;
if (shadow_method(bios, mthd, NULL))
break;
}
}
if (!best && (best = mthd)) {
mthd->func = &shadow_fw;
shadow_method(bios, mthd, source);
mthd->func = NULL;
}
if (!best->score) {
nvkm_error(subdev, "%s invalid\n", source);
kfree(source);
source = NULL;
}
}
if (!best || !best->score) {
for (mthd = mthds, best = mthd; mthd->func; mthd++) {
if (!mthd->skip || best->score < mthd->skip) {
if (shadow_method(bios, mthd, NULL)) {
if (mthd->score > best->score)
best = mthd;
}
}
}
}
for (mthd = mthds; mthd->func; mthd++) {
if (mthd != best)
kfree(mthd->data);
}
if (!best->score) {
nvkm_error(subdev, "unable to locate usable image\n");
return -EINVAL;
}
nvkm_debug(subdev, "using image from %s\n", best->func ?
best->func->name : source);
bios->data = best->data;
bios->size = best->size;
kfree(source);
return 0;
}
