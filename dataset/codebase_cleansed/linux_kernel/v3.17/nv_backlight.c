static int nvidia_bl_get_level_brightness(struct nvidia_par *par,
int level)
{
struct fb_info *info = pci_get_drvdata(par->pci_dev);
int nlevel;
nlevel = MIN_LEVEL + info->bl_curve[level] * LEVEL_STEP;
if (nlevel < 0)
nlevel = 0;
else if (nlevel < MIN_LEVEL)
nlevel = MIN_LEVEL;
else if (nlevel > MAX_LEVEL)
nlevel = MAX_LEVEL;
return nlevel;
}
static int nvidia_bl_update_status(struct backlight_device *bd)
{
struct nvidia_par *par = bl_get_data(bd);
u32 tmp_pcrt, tmp_pmc, fpcontrol;
int level;
if (!par->FlatPanel)
return 0;
if (bd->props.power != FB_BLANK_UNBLANK ||
bd->props.fb_blank != FB_BLANK_UNBLANK)
level = 0;
else
level = bd->props.brightness;
tmp_pmc = NV_RD32(par->PMC, 0x10F0) & 0x0000FFFF;
tmp_pcrt = NV_RD32(par->PCRTC0, 0x081C) & 0xFFFFFFFC;
fpcontrol = NV_RD32(par->PRAMDAC, 0x0848) & 0xCFFFFFCC;
if (level > 0) {
tmp_pcrt |= 0x1;
tmp_pmc |= (1 << 31);
tmp_pmc |= nvidia_bl_get_level_brightness(par, level) << 16;
fpcontrol |= par->fpSyncs;
} else
fpcontrol |= 0x20000022;
NV_WR32(par->PCRTC0, 0x081C, tmp_pcrt);
NV_WR32(par->PMC, 0x10F0, tmp_pmc);
NV_WR32(par->PRAMDAC, 0x848, fpcontrol);
return 0;
}
void nvidia_bl_init(struct nvidia_par *par)
{
struct backlight_properties props;
struct fb_info *info = pci_get_drvdata(par->pci_dev);
struct backlight_device *bd;
char name[12];
if (!par->FlatPanel)
return;
#ifdef CONFIG_PMAC_BACKLIGHT
if (!machine_is(powermac) ||
!pmac_has_backlight_type("mnca"))
return;
#endif
snprintf(name, sizeof(name), "nvidiabl%d", info->node);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = FB_BACKLIGHT_LEVELS - 1;
bd = backlight_device_register(name, info->dev, par, &nvidia_bl_ops,
&props);
if (IS_ERR(bd)) {
info->bl_dev = NULL;
printk(KERN_WARNING "nvidia: Backlight registration failed\n");
goto error;
}
info->bl_dev = bd;
fb_bl_default_curve(info, 0,
0x158 * FB_BACKLIGHT_MAX / MAX_LEVEL,
0x534 * FB_BACKLIGHT_MAX / MAX_LEVEL);
bd->props.brightness = bd->props.max_brightness;
bd->props.power = FB_BLANK_UNBLANK;
backlight_update_status(bd);
printk("nvidia: Backlight initialized (%s)\n", name);
return;
error:
return;
}
void nvidia_bl_exit(struct nvidia_par *par)
{
struct fb_info *info = pci_get_drvdata(par->pci_dev);
struct backlight_device *bd = info->bl_dev;
backlight_device_unregister(bd);
printk("nvidia: Backlight unloaded\n");
}
