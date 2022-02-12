int
nouveau_voltage_gpio_get(struct drm_device *dev)
{
struct nouveau_pm_voltage *volt = &nouveau_pm(dev)->voltage;
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_gpio *gpio = nouveau_gpio(device);
u8 vid = 0;
int i;
for (i = 0; i < nr_vidtag; i++) {
if (!(volt->vid_mask & (1 << i)))
continue;
vid |= gpio->get(gpio, 0, vidtag[i], 0xff) << i;
}
return nouveau_volt_lvl_lookup(dev, vid);
}
int
nouveau_voltage_gpio_set(struct drm_device *dev, int voltage)
{
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_gpio *gpio = nouveau_gpio(device);
struct nouveau_pm_voltage *volt = &nouveau_pm(dev)->voltage;
int vid, i;
vid = nouveau_volt_vid_lookup(dev, voltage);
if (vid < 0)
return vid;
for (i = 0; i < nr_vidtag; i++) {
if (!(volt->vid_mask & (1 << i)))
continue;
gpio->set(gpio, 0, vidtag[i], 0xff, !!(vid & (1 << i)));
}
return 0;
}
int
nouveau_volt_vid_lookup(struct drm_device *dev, int voltage)
{
struct nouveau_pm_voltage *volt = &nouveau_pm(dev)->voltage;
int i;
for (i = 0; i < volt->nr_level; i++) {
if (volt->level[i].voltage == voltage)
return volt->level[i].vid;
}
return -ENOENT;
}
int
nouveau_volt_lvl_lookup(struct drm_device *dev, int vid)
{
struct nouveau_pm_voltage *volt = &nouveau_pm(dev)->voltage;
int i;
for (i = 0; i < volt->nr_level; i++) {
if (volt->level[i].vid == vid)
return volt->level[i].voltage;
}
return -ENOENT;
}
void
nouveau_volt_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_gpio *gpio = nouveau_gpio(drm->device);
struct nouveau_pm *pm = nouveau_pm(dev);
struct nouveau_pm_voltage *voltage = &pm->voltage;
struct nvbios *bios = &drm->vbios;
struct dcb_gpio_func func;
struct bit_entry P;
u8 *volt = NULL, *entry;
int i, headerlen, recordlen, entries, vidmask, vidshift;
if (bios->type == NVBIOS_BIT) {
if (bit_table(dev, 'P', &P))
return;
if (P.version == 1)
volt = ROMPTR(dev, P.data[16]);
else
if (P.version == 2)
volt = ROMPTR(dev, P.data[12]);
else {
NV_WARN(drm, "unknown volt for BIT P %d\n", P.version);
}
} else {
if (bios->data[bios->offset + 6] < 0x27) {
NV_DEBUG(drm, "BMP version too old for voltage\n");
return;
}
volt = ROMPTR(dev, bios->data[bios->offset + 0x98]);
}
if (!volt) {
NV_DEBUG(drm, "voltage table pointer invalid\n");
return;
}
switch (volt[0]) {
case 0x10:
case 0x11:
case 0x12:
headerlen = 5;
recordlen = volt[1];
entries = volt[2];
vidshift = 0;
vidmask = volt[4];
break;
case 0x20:
headerlen = volt[1];
recordlen = volt[3];
entries = volt[2];
vidshift = 0;
vidmask = volt[5];
break;
case 0x30:
headerlen = volt[1];
recordlen = volt[2];
entries = volt[3];
vidmask = volt[4];
vidshift = 2;
break;
case 0x40:
headerlen = volt[1];
recordlen = volt[2];
entries = volt[3];
vidmask = volt[11];
vidshift = 0;
break;
default:
NV_WARN(drm, "voltage table 0x%02x unknown\n", volt[0]);
return;
}
voltage->vid_mask = vidmask;
if (!voltage->vid_mask)
return;
i = 0;
while (vidmask) {
if (i > nr_vidtag) {
NV_DEBUG(drm, "vid bit %d unknown\n", i);
return;
}
if (gpio && gpio->find(gpio, 0, vidtag[i], 0xff, &func)) {
NV_DEBUG(drm, "vid bit %d has no gpio tag\n", i);
return;
}
vidmask >>= 1;
i++;
}
voltage->version = volt[0];
if (voltage->version < 0x40) {
voltage->nr_level = entries;
voltage->level =
kcalloc(entries, sizeof(*voltage->level), GFP_KERNEL);
if (!voltage->level)
return;
entry = volt + headerlen;
for (i = 0; i < entries; i++, entry += recordlen) {
voltage->level[i].voltage = entry[0] * 10000;
voltage->level[i].vid = entry[1] >> vidshift;
}
} else {
u32 volt_uv = ROM32(volt[4]);
s16 step_uv = ROM16(volt[8]);
u8 vid;
voltage->nr_level = voltage->vid_mask + 1;
voltage->level = kcalloc(voltage->nr_level,
sizeof(*voltage->level), GFP_KERNEL);
if (!voltage->level)
return;
for (vid = 0; vid <= voltage->vid_mask; vid++) {
voltage->level[vid].voltage = volt_uv;
voltage->level[vid].vid = vid;
volt_uv += step_uv;
}
}
voltage->supported = true;
}
void
nouveau_volt_fini(struct drm_device *dev)
{
struct nouveau_pm_voltage *volt = &nouveau_pm(dev)->voltage;
kfree(volt->level);
}
