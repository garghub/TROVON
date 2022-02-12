const struct hdmi_config *hdmi_default_timing(void)
{
return &vesa_timings[0];
}
static const struct hdmi_config *hdmi_find_timing(int code,
const struct hdmi_config *timings_arr, int len)
{
int i;
for (i = 0; i < len; i++) {
if (timings_arr[i].cm.code == code)
return &timings_arr[i];
}
return NULL;
}
const struct hdmi_config *hdmi_get_timings(int mode, int code)
{
const struct hdmi_config *arr;
int len;
if (mode == HDMI_DVI) {
arr = vesa_timings;
len = ARRAY_SIZE(vesa_timings);
} else {
arr = cea_timings;
len = ARRAY_SIZE(cea_timings);
}
return hdmi_find_timing(code, arr, len);
}
static bool hdmi_timings_compare(struct omap_video_timings *timing1,
const struct omap_video_timings *timing2)
{
int timing1_vsync, timing1_hsync, timing2_vsync, timing2_hsync;
if ((DIV_ROUND_CLOSEST(timing2->pixelclock, 1000000) ==
DIV_ROUND_CLOSEST(timing1->pixelclock, 1000000)) &&
(timing2->x_res == timing1->x_res) &&
(timing2->y_res == timing1->y_res)) {
timing2_hsync = timing2->hfp + timing2->hsw + timing2->hbp;
timing1_hsync = timing1->hfp + timing1->hsw + timing1->hbp;
timing2_vsync = timing2->vfp + timing2->vsw + timing2->vbp;
timing1_vsync = timing1->vfp + timing1->vsw + timing1->vbp;
DSSDBG("timing1_hsync = %d timing1_vsync = %d"\
"timing2_hsync = %d timing2_vsync = %d\n",
timing1_hsync, timing1_vsync,
timing2_hsync, timing2_vsync);
if ((timing1_hsync == timing2_hsync) &&
(timing1_vsync == timing2_vsync)) {
return true;
}
}
return false;
}
struct hdmi_cm hdmi_get_code(struct omap_video_timings *timing)
{
int i;
struct hdmi_cm cm = {-1};
DSSDBG("hdmi_get_code\n");
for (i = 0; i < ARRAY_SIZE(cea_timings); i++) {
if (hdmi_timings_compare(timing, &cea_timings[i].timings)) {
cm = cea_timings[i].cm;
goto end;
}
}
for (i = 0; i < ARRAY_SIZE(vesa_timings); i++) {
if (hdmi_timings_compare(timing, &vesa_timings[i].timings)) {
cm = vesa_timings[i].cm;
goto end;
}
}
end:
return cm;
}
int hdmi_compute_acr(u32 pclk, u32 sample_freq, u32 *n, u32 *cts)
{
u32 deep_color;
bool deep_color_correct = false;
if (n == NULL || cts == NULL)
return -EINVAL;
deep_color = 100;
switch (sample_freq) {
case 32000:
case 48000:
case 96000:
case 192000:
if (deep_color == 125)
if (pclk == 27027000 || pclk == 74250000)
deep_color_correct = true;
if (deep_color == 150)
if (pclk == 27027000)
deep_color_correct = true;
break;
case 44100:
case 88200:
case 176400:
if (deep_color == 125)
if (pclk == 27027000)
deep_color_correct = true;
break;
default:
return -EINVAL;
}
if (deep_color_correct) {
switch (sample_freq) {
case 32000:
*n = 8192;
break;
case 44100:
*n = 12544;
break;
case 48000:
*n = 8192;
break;
case 88200:
*n = 25088;
break;
case 96000:
*n = 16384;
break;
case 176400:
*n = 50176;
break;
case 192000:
*n = 32768;
break;
default:
return -EINVAL;
}
} else {
switch (sample_freq) {
case 32000:
*n = 4096;
break;
case 44100:
*n = 6272;
break;
case 48000:
*n = 6144;
break;
case 88200:
*n = 12544;
break;
case 96000:
*n = 12288;
break;
case 176400:
*n = 25088;
break;
case 192000:
*n = 24576;
break;
default:
return -EINVAL;
}
}
*cts = (pclk/1000) * (*n / 128) * deep_color / (sample_freq / 10);
return 0;
}
