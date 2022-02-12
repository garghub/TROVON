const struct linux_logo * __init_refok fb_find_logo(int depth)
{
const struct linux_logo *logo = NULL;
if (nologo)
return NULL;
if (depth >= 1) {
#ifdef CONFIG_LOGO_LINUX_MONO
logo = &logo_linux_mono;
#endif
#ifdef CONFIG_LOGO_SUPERH_MONO
logo = &logo_superh_mono;
#endif
}
if (depth >= 4) {
#ifdef CONFIG_LOGO_LINUX_VGA16
logo = &logo_linux_vga16;
#endif
#ifdef CONFIG_LOGO_BLACKFIN_VGA16
logo = &logo_blackfin_vga16;
#endif
#ifdef CONFIG_LOGO_SUPERH_VGA16
logo = &logo_superh_vga16;
#endif
}
if (depth >= 8) {
#ifdef CONFIG_LOGO_LINUX_CLUT224
logo = &logo_linux_clut224;
#endif
#ifdef CONFIG_LOGO_BLACKFIN_CLUT224
logo = &logo_blackfin_clut224;
#endif
#ifdef CONFIG_LOGO_DEC_CLUT224
logo = &logo_dec_clut224;
#endif
#ifdef CONFIG_LOGO_MAC_CLUT224
if (MACH_IS_MAC)
logo = &logo_mac_clut224;
#endif
#ifdef CONFIG_LOGO_PARISC_CLUT224
logo = &logo_parisc_clut224;
#endif
#ifdef CONFIG_LOGO_SGI_CLUT224
logo = &logo_sgi_clut224;
#endif
#ifdef CONFIG_LOGO_SUN_CLUT224
logo = &logo_sun_clut224;
#endif
#ifdef CONFIG_LOGO_SUPERH_CLUT224
logo = &logo_superh_clut224;
#endif
#ifdef CONFIG_LOGO_M32R_CLUT224
logo = &logo_m32r_clut224;
#endif
}
return logo;
}
