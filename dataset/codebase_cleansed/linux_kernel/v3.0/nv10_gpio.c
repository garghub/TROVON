static bool
get_gpio_location(struct dcb_gpio_entry *ent, uint32_t *reg, uint32_t *shift,
uint32_t *mask)
{
if (ent->line < 2) {
*reg = NV_PCRTC_GPIO;
*shift = ent->line * 16;
*mask = 0x11;
} else if (ent->line < 10) {
*reg = NV_PCRTC_GPIO_EXT;
*shift = (ent->line - 2) * 4;
*mask = 0x3;
} else if (ent->line < 14) {
*reg = NV_PCRTC_850;
*shift = (ent->line - 10) * 4;
*mask = 0x3;
} else {
return false;
}
return true;
}
int
nv10_gpio_get(struct drm_device *dev, enum dcb_gpio_tag tag)
{
struct dcb_gpio_entry *ent = nouveau_bios_gpio_entry(dev, tag);
uint32_t reg, shift, mask, value;
if (!ent)
return -ENODEV;
if (!get_gpio_location(ent, &reg, &shift, &mask))
return -ENODEV;
value = NVReadCRTC(dev, 0, reg) >> shift;
return (ent->invert ? 1 : 0) ^ (value & 1);
}
int
nv10_gpio_set(struct drm_device *dev, enum dcb_gpio_tag tag, int state)
{
struct dcb_gpio_entry *ent = nouveau_bios_gpio_entry(dev, tag);
uint32_t reg, shift, mask, value;
if (!ent)
return -ENODEV;
if (!get_gpio_location(ent, &reg, &shift, &mask))
return -ENODEV;
value = ((ent->invert ? 1 : 0) ^ (state ? 1 : 0)) << shift;
mask = ~(mask << shift);
NVWriteCRTC(dev, 0, reg, value | (NVReadCRTC(dev, 0, reg) & mask));
return 0;
}
