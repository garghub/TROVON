const struct font_desc *find_font(const char *name)
{
unsigned int i;
for (i = 0; i < num_fonts; i++)
if (!strcmp(fonts[i]->name, name))
return fonts[i];
return NULL;
}
const struct font_desc *get_default_font(int xres, int yres, u32 font_w,
u32 font_h)
{
int i, c, cc;
const struct font_desc *f, *g;
g = NULL;
cc = -10000;
for(i=0; i<num_fonts; i++) {
f = fonts[i];
c = f->pref;
#if defined(__mc68000__)
#ifdef CONFIG_FONT_PEARL_8x8
if (MACH_IS_AMIGA && f->idx == PEARL8x8_IDX)
c = 100;
#endif
#ifdef CONFIG_FONT_6x11
if (MACH_IS_MAC && xres < 640 && f->idx == VGA6x11_IDX)
c = 100;
#endif
#endif
if ((yres < 400) == (f->height <= 8))
c += 1000;
if ((font_w & (1 << (f->width - 1))) &&
(font_h & (1 << (f->height - 1))))
c += 1000;
if (c > cc) {
cc = c;
g = f;
}
}
return g;
}
