gboolean
initialize_color(color_t *color, guint16 red, guint16 green, guint16 blue)
{
GdkColor gdk_color;
gdk_color.pixel = 0;
gdk_color.red = red;
gdk_color.green = green;
gdk_color.blue = blue;
#if 0
if (!get_color(&gdk_color))
return FALSE;
#endif
gdkcolor_to_color_t(color, &gdk_color);
return TRUE;
}
void
colors_init(void)
{
#if 0
gboolean got_white, got_black;
sys_cmap = gdk_colormap_get_system();
got_white = get_color(&WHITE);
got_black = get_color(&BLACK);
if (!got_white) {
if (!got_black)
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not allocate colors black or white.");
else
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not allocate color white.");
} else {
if (!got_black)
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not allocate color black.");
}
#endif
}
void
color_t_to_gdkcolor(GdkColor *target, const color_t *source)
{
target->pixel = source->pixel;
target->red = source->red;
target->green = source->green;
target->blue = source->blue;
}
void
color_t_to_gdkRGBAcolor(GdkRGBA *target, const color_t *source)
{
target->alpha = 1;
target->red = source->red / 65535.0;
target->green = source->green / 65535.0;
target->blue = source->blue / 65535.0;
}
void
gdkcolor_to_color_t(color_t *target, const GdkColor *source)
{
target->pixel = source->pixel;
target->red = source->red;
target->green = source->green;
target->blue = source->blue;
}
void
gdkRGBAcolor_to_color_t(color_t *target, const GdkRGBA *source)
{
target->pixel = 0;
target->red = (guint16)(source->red*65535);
target->green = (guint16)(source->green*65535);
target->blue = (guint16)(source->blue*65535);
}
void
GdkColor_to_GdkRGBA(GdkRGBA *target, const GdkColor *source)
{
target->alpha = 1;
target->red = (double)source->red / 65535.0;
target->green = (double)source->green / 65535.0;
target->blue = (double)source->blue / 65535.0;
}
void
gdkRGBAcolor_to_GdkColor(GdkColor *target, const GdkRGBA *source)
{
target->pixel = 0;
target->red = (guint16)(source->red*65535);
target->green = (guint16)(source->green*65535);
target->blue = (guint16)(source->blue*65535);
}
