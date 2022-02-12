void
color_t_to_gdkcolor(GdkColor *target, const color_t *source)
{
target->pixel = 0;
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
target->red = source->red;
target->green = source->green;
target->blue = source->blue;
}
void
gdkRGBAcolor_to_color_t(color_t *target, const GdkRGBA *source)
{
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
