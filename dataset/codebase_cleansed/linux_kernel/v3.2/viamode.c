static struct VideoModeTable *get_modes(struct VideoModeTable *vmt, int n,
int hres, int vres)
{
int i;
for (i = 0; i < n; i++)
if (vmt[i].mode_array &&
vmt[i].crtc[0].crtc.hor_addr == hres &&
vmt[i].crtc[0].crtc.ver_addr == vres)
return &viafb_modes[i];
return NULL;
}
static struct crt_mode_table *get_best_mode(struct VideoModeTable *vmt,
int refresh)
{
struct crt_mode_table *best;
int i;
if (!vmt)
return NULL;
best = &vmt->crtc[0];
for (i = 1; i < vmt->mode_array; i++) {
if (abs(vmt->crtc[i].refresh_rate - refresh)
< abs(best->refresh_rate - refresh))
best = &vmt->crtc[i];
}
return best;
}
static struct VideoModeTable *viafb_get_mode(int hres, int vres)
{
return get_modes(viafb_modes, ARRAY_SIZE(viafb_modes), hres, vres);
}
struct crt_mode_table *viafb_get_best_mode(int hres, int vres, int refresh)
{
return get_best_mode(viafb_get_mode(hres, vres), refresh);
}
static struct VideoModeTable *viafb_get_rb_mode(int hres, int vres)
{
return get_modes(viafb_rb_modes, ARRAY_SIZE(viafb_rb_modes), hres,
vres);
}
struct crt_mode_table *viafb_get_best_rb_mode(int hres, int vres, int refresh)
{
return get_best_mode(viafb_get_rb_mode(hres, vres), refresh);
}
