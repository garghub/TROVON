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
if (v < -0.04045)
return pow((-v + 0.055) / 1.055, 2.4);
return (v <= 0.04045) ? v / 12.92 : pow((v + 0.055) / 1.055, 2.4);
}
static double transfer_rgb_to_srgb(double v)
{
if (v <= -0.0031308)
return -1.055 * pow(-v, 1.0 / 2.4) + 0.055;
if (v <= 0.0031308)
return v * 12.92;
return 1.055 * pow(v, 1.0 / 2.4) - 0.055;
}
static double transfer_rgb_to_smpte240m(double v)
{
return (v <= 0.0228) ? v * 4.0 : 1.1115 * pow(v, 0.45) - 0.1115;
}
static double transfer_rgb_to_rec709(double v)
{
if (v <= -0.018)
return -1.099 * pow(-v, 0.45) + 0.099;
return (v < 0.018) ? v * 4.5 : 1.099 * pow(v, 0.45) - 0.099;
}
static double transfer_rec709_to_rgb(double v)
{
return (v < 0.081) ? v / 4.5 : pow((v + 0.099) / 1.099, 1.0 / 0.45);
}
static double transfer_rgb_to_adobergb(double v)
{
return pow(v, 1.0 / 2.19921875);
}
static double transfer_srgb_to_rec709(double v)
{
return transfer_rgb_to_rec709(transfer_srgb_to_rgb(v));
}
static void csc(enum v4l2_colorspace colorspace, double *r, double *g, double *b)
{
int clamp = 1;
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
case V4L2_COLORSPACE_ADOBERGB:
*r = transfer_srgb_to_rgb(*r);
*g = transfer_srgb_to_rgb(*g);
*b = transfer_srgb_to_rgb(*b);
mult_matrix(r, g, b, rec709_to_adobergb);
break;
case V4L2_COLORSPACE_BT2020:
*r = transfer_srgb_to_rgb(*r);
*g = transfer_srgb_to_rgb(*g);
*b = transfer_srgb_to_rgb(*b);
mult_matrix(r, g, b, rec709_to_bt2020);
break;
case V4L2_COLORSPACE_SRGB:
case V4L2_COLORSPACE_REC709:
default:
break;
}
if (clamp) {
*r = ((*r) < 0) ? 0 : (((*r) > 1) ? 1 : (*r));
*g = ((*g) < 0) ? 0 : (((*g) > 1) ? 1 : (*g));
*b = ((*b) < 0) ? 0 : (((*b) > 1) ? 1 : (*b));
}
switch (colorspace) {
case V4L2_COLORSPACE_SMPTE240M:
*r = transfer_rgb_to_smpte240m(*r);
*g = transfer_rgb_to_smpte240m(*g);
*b = transfer_rgb_to_smpte240m(*b);
break;
case V4L2_COLORSPACE_SMPTE170M:
case V4L2_COLORSPACE_470_SYSTEM_M:
case V4L2_COLORSPACE_470_SYSTEM_BG:
case V4L2_COLORSPACE_BT2020:
*r = transfer_rgb_to_rec709(*r);
*g = transfer_rgb_to_rec709(*g);
*b = transfer_rgb_to_rec709(*b);
break;
case V4L2_COLORSPACE_SRGB:
break;
case V4L2_COLORSPACE_ADOBERGB:
*r = transfer_rgb_to_adobergb(*r);
*g = transfer_rgb_to_adobergb(*g);
*b = transfer_rgb_to_adobergb(*b);
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
V4L2_COLORSPACE_ADOBERGB,
V4L2_COLORSPACE_BT2020,
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
"V4L2_COLORSPACE_ADOBERGB",
"V4L2_COLORSPACE_BT2020",
};
int i;
int c;
printf("/* Generated table */\n");
printf("const unsigned short tpg_rec709_to_linear[255 * 16 + 1] = {");
for (i = 0; i <= 255 * 16; i++) {
if (i % 16 == 0)
printf("\n\t");
printf("%4d,%s",
(int)(0.5 + 16.0 * 255.0 *
transfer_rec709_to_rgb(i / (16.0 * 255.0))),
i % 16 == 15 || i == 255 * 16 ? "" : " ");
}
printf("\n};\n\n");
printf("/* Generated table */\n");
printf("const unsigned short tpg_linear_to_rec709[255 * 16 + 1] = {");
for (i = 0; i <= 255 * 16; i++) {
if (i % 16 == 0)
printf("\n\t");
printf("%4d,%s",
(int)(0.5 + 16.0 * 255.0 *
transfer_rgb_to_rec709(i / (16.0 * 255.0))),
i % 16 == 15 || i == 255 * 16 ? "" : " ");
}
printf("\n};\n\n");
printf("/* Generated table */\n");
printf("const struct color16 tpg_csc_colors[V4L2_COLORSPACE_BT2020 + 1][TPG_COLOR_CSC_BLACK + 1] = {\n");
for (c = 0; c <= V4L2_COLORSPACE_BT2020; c++) {
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
