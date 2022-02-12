static void mult_matrix(double *r, double *g, double *b, const double m[3][3])
{
double ir, ig, ib;
ir = m[0][0] * (*r) + m[0][1] * (*g) + m[0][2] * (*b);
ig = m[1][0] * (*r) + m[1][1] * (*g) + m[1][2] * (*b);
ib = m[2][0] * (*r) + m[2][1] * (*g) + m[2][2] * (*b);
*r = ir;
*g = ig;
*b = ib;
}
static double transfer_srgb_to_rgb(double v)
{
return (v <= 0.03928) ? v / 12.92 : pow((v + 0.055) / 1.055, 2.4);
}
static double transfer_rgb_to_smpte240m(double v)
{
return (v <= 0.0228) ? v * 4.0 : 1.1115 * pow(v, 0.45) - 0.1115;
}
static double transfer_rgb_to_rec709(double v)
{
return (v < 0.018) ? v * 4.5 : 1.099 * pow(v, 0.45) - 0.099;
}
static double transfer_srgb_to_rec709(double v)
{
return transfer_rgb_to_rec709(transfer_srgb_to_rgb(v));
}
static void csc(enum v4l2_colorspace colorspace, double *r, double *g, double *b)
{
switch (colorspace) {
case V4L2_COLORSPACE_SMPTE240M:
*r = transfer_srgb_to_rgb(*r);
*g = transfer_srgb_to_rgb(*g);
*b = transfer_srgb_to_rgb(*b);
mult_matrix(r, g, b, rec709_to_240m);
break;
case V4L2_COLORSPACE_SMPTE170M:
*r = transfer_srgb_to_rgb(*r);
*g = transfer_srgb_to_rgb(*g);
*b = transfer_srgb_to_rgb(*b);
mult_matrix(r, g, b, rec709_to_170m);
break;
case V4L2_COLORSPACE_470_SYSTEM_BG:
*r = transfer_srgb_to_rgb(*r);
*g = transfer_srgb_to_rgb(*g);
*b = transfer_srgb_to_rgb(*b);
mult_matrix(r, g, b, rec709_to_ebu);
break;
case V4L2_COLORSPACE_470_SYSTEM_M:
*r = transfer_srgb_to_rgb(*r);
*g = transfer_srgb_to_rgb(*g);
*b = transfer_srgb_to_rgb(*b);
mult_matrix(r, g, b, rec709_to_ntsc1953);
break;
case V4L2_COLORSPACE_SRGB:
case V4L2_COLORSPACE_REC709:
default:
break;
}
*r = ((*r) < 0) ? 0 : (((*r) > 1) ? 1 : (*r));
*g = ((*g) < 0) ? 0 : (((*g) > 1) ? 1 : (*g));
*b = ((*b) < 0) ? 0 : (((*b) > 1) ? 1 : (*b));
switch (colorspace) {
case V4L2_COLORSPACE_SMPTE240M:
*r = transfer_rgb_to_smpte240m(*r);
*g = transfer_rgb_to_smpte240m(*g);
*b = transfer_rgb_to_smpte240m(*b);
break;
case V4L2_COLORSPACE_SMPTE170M:
case V4L2_COLORSPACE_470_SYSTEM_M:
case V4L2_COLORSPACE_470_SYSTEM_BG:
*r = transfer_rgb_to_rec709(*r);
*g = transfer_rgb_to_rec709(*g);
*b = transfer_rgb_to_rec709(*b);
break;
case V4L2_COLORSPACE_SRGB:
break;
case V4L2_COLORSPACE_REC709:
default:
*r = transfer_srgb_to_rec709(*r);
*g = transfer_srgb_to_rec709(*g);
*b = transfer_srgb_to_rec709(*b);
break;
}
}
int main(int argc, char **argv)
{
static const unsigned colorspaces[] = {
0,
V4L2_COLORSPACE_SMPTE170M,
V4L2_COLORSPACE_SMPTE240M,
V4L2_COLORSPACE_REC709,
0,
V4L2_COLORSPACE_470_SYSTEM_M,
V4L2_COLORSPACE_470_SYSTEM_BG,
0,
V4L2_COLORSPACE_SRGB,
};
static const char * const colorspace_names[] = {
"",
"V4L2_COLORSPACE_SMPTE170M",
"V4L2_COLORSPACE_SMPTE240M",
"V4L2_COLORSPACE_REC709",
"",
"V4L2_COLORSPACE_470_SYSTEM_M",
"V4L2_COLORSPACE_470_SYSTEM_BG",
"",
"V4L2_COLORSPACE_SRGB",
};
int i;
int c;
printf("/* Generated table */\n");
printf("const struct color16 tpg_csc_colors[V4L2_COLORSPACE_SRGB + 1][TPG_COLOR_CSC_BLACK + 1] = {\n");
for (c = 0; c <= V4L2_COLORSPACE_SRGB; c++) {
for (i = 0; i <= TPG_COLOR_CSC_BLACK; i++) {
double r, g, b;
if (colorspaces[c] == 0)
continue;
r = tpg_colors[i].r / 255.0;
g = tpg_colors[i].g / 255.0;
b = tpg_colors[i].b / 255.0;
csc(c, &r, &g, &b);
printf("\t[%s][%d] = { %d, %d, %d },\n", colorspace_names[c], i,
(int)(r * 4080), (int)(g * 4080), (int)(b * 4080));
}
}
printf("};\n\n");
return 0;
}
