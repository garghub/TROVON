void efifb_setup_from_dmi(struct screen_info *si, const char *opt)
{
int i;
for (i = 0; i < M_UNKNOWN; i++) {
if (efifb_dmi_list[i].base != 0 &&
!strcmp(opt, efifb_dmi_list[i].optname)) {
si->lfb_base = efifb_dmi_list[i].base;
si->lfb_linelength = efifb_dmi_list[i].stride;
si->lfb_width = efifb_dmi_list[i].width;
si->lfb_height = efifb_dmi_list[i].height;
}
}
}
static int __init efifb_set_system(const struct dmi_system_id *id)
{
struct efifb_dmi_info *info = id->driver_data;
if (info->base == 0 && info->height == 0 && info->width == 0 &&
info->stride == 0)
return 0;
if (screen_info.lfb_base == 0) {
#if defined(CONFIG_PCI)
struct pci_dev *dev = NULL;
int found_bar = 0;
#endif
if (info->base) {
screen_info.lfb_base = choose_value(info->base,
screen_info.lfb_base, OVERRIDE_BASE,
info->flags);
#if defined(CONFIG_PCI)
for_each_pci_dev(dev) {
int i;
if ((dev->class >> 8) != PCI_CLASS_DISPLAY_VGA)
continue;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
resource_size_t start, end;
unsigned long flags;
flags = pci_resource_flags(dev, i);
if (!(flags & IORESOURCE_MEM))
continue;
if (flags & IORESOURCE_UNSET)
continue;
if (pci_resource_len(dev, i) == 0)
continue;
start = pci_resource_start(dev, i);
end = pci_resource_end(dev, i);
if (screen_info.lfb_base >= start &&
screen_info.lfb_base < end) {
found_bar = 1;
break;
}
}
}
if (!found_bar)
screen_info.lfb_base = 0;
#endif
}
}
if (screen_info.lfb_base) {
screen_info.lfb_linelength = choose_value(info->stride,
screen_info.lfb_linelength, OVERRIDE_STRIDE,
info->flags);
screen_info.lfb_width = choose_value(info->width,
screen_info.lfb_width, OVERRIDE_WIDTH,
info->flags);
screen_info.lfb_height = choose_value(info->height,
screen_info.lfb_height, OVERRIDE_HEIGHT,
info->flags);
if (screen_info.orig_video_isVGA == 0)
screen_info.orig_video_isVGA = VIDEO_TYPE_EFI;
} else {
screen_info.lfb_linelength = 0;
screen_info.lfb_width = 0;
screen_info.lfb_height = 0;
screen_info.orig_video_isVGA = 0;
return 0;
}
printk(KERN_INFO "efifb: dmi detected %s - framebuffer at 0x%08x "
"(%dx%d, stride %d)\n", id->ident,
screen_info.lfb_base, screen_info.lfb_width,
screen_info.lfb_height, screen_info.lfb_linelength);
return 1;
}
__init void sysfb_apply_efi_quirks(void)
{
if (screen_info.orig_video_isVGA != VIDEO_TYPE_EFI ||
!(screen_info.capabilities & VIDEO_CAPABILITY_SKIP_QUIRKS))
dmi_check_system(efifb_dmi_system_table);
}
