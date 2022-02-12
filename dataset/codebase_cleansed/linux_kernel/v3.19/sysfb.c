static __init int sysfb_init(void)
{
struct screen_info *si = &screen_info;
struct simplefb_platform_data mode;
struct platform_device *pd;
const char *name;
bool compatible;
int ret;
sysfb_apply_efi_quirks();
compatible = parse_mode(si, &mode);
if (compatible) {
ret = create_simplefb(si, &mode);
if (!ret)
return 0;
}
if (si->orig_video_isVGA == VIDEO_TYPE_EFI)
name = "efi-framebuffer";
else if (si->orig_video_isVGA == VIDEO_TYPE_VLFB)
name = "vesa-framebuffer";
else
name = "platform-framebuffer";
pd = platform_device_register_resndata(NULL, name, 0,
NULL, 0, si, sizeof(*si));
return PTR_ERR_OR_ZERO(pd);
}
