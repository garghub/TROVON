static const struct fb_videomode *get_best_mode(
const struct fb_videomode *modes, int n,
int hres, int vres, int refresh)
{
const struct fb_videomode *best = NULL;
int i;
for (i = 0; i < n; i++) {
if (modes[i].xres != hres || modes[i].yres != vres)
continue;
if (!best || abs(modes[i].refresh - refresh) <
abs(best->refresh - refresh))
best = &modes[i];
}
return best;
}
const struct fb_videomode *viafb_get_best_mode(int hres, int vres, int refresh)
{
return get_best_mode(viafb_modes, ARRAY_SIZE(viafb_modes),
hres, vres, refresh);
}
const struct fb_videomode *viafb_get_best_rb_mode(int hres, int vres,
int refresh)
{
return get_best_mode(viafb_rb_modes, ARRAY_SIZE(viafb_rb_modes),
hres, vres, refresh);
}
