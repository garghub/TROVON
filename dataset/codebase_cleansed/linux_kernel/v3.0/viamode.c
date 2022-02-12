struct VideoModeTable *viafb_get_mode(int hres, int vres)
{
u32 i;
for (i = 0; i < ARRAY_SIZE(viafb_modes); i++)
if (viafb_modes[i].mode_array &&
viafb_modes[i].crtc[0].crtc.hor_addr == hres &&
viafb_modes[i].crtc[0].crtc.ver_addr == vres)
return &viafb_modes[i];
return NULL;
}
struct VideoModeTable *viafb_get_rb_mode(int hres, int vres)
{
u32 i;
for (i = 0; i < ARRAY_SIZE(viafb_rb_modes); i++)
if (viafb_rb_modes[i].mode_array &&
viafb_rb_modes[i].crtc[0].crtc.hor_addr == hres &&
viafb_rb_modes[i].crtc[0].crtc.ver_addr == vres)
return &viafb_rb_modes[i];
return NULL;
}
