int drm_edid_header_is_valid(const u8 *raw_edid)
{
int i, score = 0;
for (i = 0; i < sizeof(edid_header); i++)
if (raw_edid[i] == edid_header[i])
score++;
return score;
}
static int drm_edid_block_checksum(const u8 *raw_edid)
{
int i;
u8 csum = 0;
for (i = 0; i < EDID_LENGTH; i++)
csum += raw_edid[i];
return csum;
}
static bool drm_edid_is_zero(const u8 *in_edid, int length)
{
if (memchr_inv(in_edid, 0, length))
return false;
return true;
}
bool drm_edid_block_valid(u8 *raw_edid, int block, bool print_bad_edid,
bool *edid_corrupt)
{
u8 csum;
struct edid *edid = (struct edid *)raw_edid;
if (WARN_ON(!raw_edid))
return false;
if (edid_fixup > 8 || edid_fixup < 0)
edid_fixup = 6;
if (block == 0) {
int score = drm_edid_header_is_valid(raw_edid);
if (score == 8) {
if (edid_corrupt)
*edid_corrupt = false;
} else if (score >= edid_fixup) {
if (edid_corrupt)
*edid_corrupt = true;
DRM_DEBUG("Fixing EDID header, your hardware may be failing\n");
memcpy(raw_edid, edid_header, sizeof(edid_header));
} else {
if (edid_corrupt)
*edid_corrupt = true;
goto bad;
}
}
csum = drm_edid_block_checksum(raw_edid);
if (csum) {
if (edid_corrupt)
*edid_corrupt = true;
if (raw_edid[0] == CEA_EXT) {
DRM_DEBUG("EDID checksum is invalid, remainder is %d\n", csum);
DRM_DEBUG("Assuming a KVM switch modified the CEA block but left the original checksum\n");
} else {
if (print_bad_edid)
DRM_NOTE("EDID checksum is invalid, remainder is %d\n", csum);
goto bad;
}
}
switch (raw_edid[0]) {
case 0:
if (edid->version != 1) {
DRM_NOTE("EDID has major version %d, instead of 1\n", edid->version);
goto bad;
}
if (edid->revision > 4)
DRM_DEBUG("EDID minor > 4, assuming backward compatibility\n");
break;
default:
break;
}
return true;
bad:
if (print_bad_edid) {
if (drm_edid_is_zero(raw_edid, EDID_LENGTH)) {
pr_notice("EDID block is all zeroes\n");
} else {
pr_notice("Raw EDID:\n");
print_hex_dump(KERN_NOTICE,
" \t", DUMP_PREFIX_NONE, 16, 1,
raw_edid, EDID_LENGTH, false);
}
}
return false;
}
bool drm_edid_is_valid(struct edid *edid)
{
int i;
u8 *raw = (u8 *)edid;
if (!edid)
return false;
for (i = 0; i <= edid->extensions; i++)
if (!drm_edid_block_valid(raw + i * EDID_LENGTH, i, true, NULL))
return false;
return true;
}
static int
drm_do_probe_ddc_edid(void *data, u8 *buf, unsigned int block, size_t len)
{
struct i2c_adapter *adapter = data;
unsigned char start = block * EDID_LENGTH;
unsigned char segment = block >> 1;
unsigned char xfers = segment ? 3 : 2;
int ret, retries = 5;
do {
struct i2c_msg msgs[] = {
{
.addr = DDC_SEGMENT_ADDR,
.flags = 0,
.len = 1,
.buf = &segment,
}, {
.addr = DDC_ADDR,
.flags = 0,
.len = 1,
.buf = &start,
}, {
.addr = DDC_ADDR,
.flags = I2C_M_RD,
.len = len,
.buf = buf,
}
};
ret = i2c_transfer(adapter, &msgs[3 - xfers], xfers);
if (ret == -ENXIO) {
DRM_DEBUG_KMS("drm: skipping non-existent adapter %s\n",
adapter->name);
break;
}
} while (ret != xfers && --retries);
return ret == xfers ? 0 : -1;
}
static void connector_bad_edid(struct drm_connector *connector,
u8 *edid, int num_blocks)
{
int i;
if (connector->bad_edid_counter++ && !(drm_debug & DRM_UT_KMS))
return;
dev_warn(connector->dev->dev,
"%s: EDID is invalid:\n",
connector->name);
for (i = 0; i < num_blocks; i++) {
u8 *block = edid + i * EDID_LENGTH;
char prefix[20];
if (drm_edid_is_zero(block, EDID_LENGTH))
sprintf(prefix, "\t[%02x] ZERO ", i);
else if (!drm_edid_block_valid(block, i, false, NULL))
sprintf(prefix, "\t[%02x] BAD ", i);
else
sprintf(prefix, "\t[%02x] GOOD ", i);
print_hex_dump(KERN_WARNING,
prefix, DUMP_PREFIX_NONE, 16, 1,
block, EDID_LENGTH, false);
}
}
struct edid *drm_do_get_edid(struct drm_connector *connector,
int (*get_edid_block)(void *data, u8 *buf, unsigned int block,
size_t len),
void *data)
{
int i, j = 0, valid_extensions = 0;
u8 *edid, *new;
if ((edid = kmalloc(EDID_LENGTH, GFP_KERNEL)) == NULL)
return NULL;
for (i = 0; i < 4; i++) {
if (get_edid_block(data, edid, 0, EDID_LENGTH))
goto out;
if (drm_edid_block_valid(edid, 0, false,
&connector->edid_corrupt))
break;
if (i == 0 && drm_edid_is_zero(edid, EDID_LENGTH)) {
connector->null_edid_counter++;
goto carp;
}
}
if (i == 4)
goto carp;
valid_extensions = edid[0x7e];
if (valid_extensions == 0)
return (struct edid *)edid;
new = krealloc(edid, (valid_extensions + 1) * EDID_LENGTH, GFP_KERNEL);
if (!new)
goto out;
edid = new;
for (j = 1; j <= edid[0x7e]; j++) {
u8 *block = edid + j * EDID_LENGTH;
for (i = 0; i < 4; i++) {
if (get_edid_block(data, block, j, EDID_LENGTH))
goto out;
if (drm_edid_block_valid(block, j, false, NULL))
break;
}
if (i == 4)
valid_extensions--;
}
if (valid_extensions != edid[0x7e]) {
u8 *base;
connector_bad_edid(connector, edid, edid[0x7e] + 1);
edid[EDID_LENGTH-1] += edid[0x7e] - valid_extensions;
edid[0x7e] = valid_extensions;
new = kmalloc((valid_extensions + 1) * EDID_LENGTH, GFP_KERNEL);
if (!new)
goto out;
base = new;
for (i = 0; i <= edid[0x7e]; i++) {
u8 *block = edid + i * EDID_LENGTH;
if (!drm_edid_block_valid(block, i, false, NULL))
continue;
memcpy(base, block, EDID_LENGTH);
base += EDID_LENGTH;
}
kfree(edid);
edid = new;
}
return (struct edid *)edid;
carp:
connector_bad_edid(connector, edid, 1);
out:
kfree(edid);
return NULL;
}
bool
drm_probe_ddc(struct i2c_adapter *adapter)
{
unsigned char out;
return (drm_do_probe_ddc_edid(adapter, &out, 0, 1) == 0);
}
struct edid *drm_get_edid(struct drm_connector *connector,
struct i2c_adapter *adapter)
{
struct edid *edid;
if (connector->force == DRM_FORCE_OFF)
return NULL;
if (connector->force == DRM_FORCE_UNSPECIFIED && !drm_probe_ddc(adapter))
return NULL;
edid = drm_do_get_edid(connector, drm_do_probe_ddc_edid, adapter);
if (edid)
drm_get_displayid(connector, edid);
return edid;
}
struct edid *drm_get_edid_switcheroo(struct drm_connector *connector,
struct i2c_adapter *adapter)
{
struct pci_dev *pdev = connector->dev->pdev;
struct edid *edid;
vga_switcheroo_lock_ddc(pdev);
edid = drm_get_edid(connector, adapter);
vga_switcheroo_unlock_ddc(pdev);
return edid;
}
struct edid *drm_edid_duplicate(const struct edid *edid)
{
return kmemdup(edid, (edid->extensions + 1) * EDID_LENGTH, GFP_KERNEL);
}
static bool edid_vendor(struct edid *edid, const char *vendor)
{
char edid_vendor[3];
edid_vendor[0] = ((edid->mfg_id[0] & 0x7c) >> 2) + '@';
edid_vendor[1] = (((edid->mfg_id[0] & 0x3) << 3) |
((edid->mfg_id[1] & 0xe0) >> 5)) + '@';
edid_vendor[2] = (edid->mfg_id[1] & 0x1f) + '@';
return !strncmp(edid_vendor, vendor, 3);
}
static u32 edid_get_quirks(struct edid *edid)
{
const struct edid_quirk *quirk;
int i;
for (i = 0; i < ARRAY_SIZE(edid_quirk_list); i++) {
quirk = &edid_quirk_list[i];
if (edid_vendor(edid, quirk->vendor) &&
(EDID_PRODUCT_ID(edid) == quirk->product_id))
return quirk->quirks;
}
return 0;
}
static void edid_fixup_preferred(struct drm_connector *connector,
u32 quirks)
{
struct drm_display_mode *t, *cur_mode, *preferred_mode;
int target_refresh = 0;
int cur_vrefresh, preferred_vrefresh;
if (list_empty(&connector->probed_modes))
return;
if (quirks & EDID_QUIRK_PREFER_LARGE_60)
target_refresh = 60;
if (quirks & EDID_QUIRK_PREFER_LARGE_75)
target_refresh = 75;
preferred_mode = list_first_entry(&connector->probed_modes,
struct drm_display_mode, head);
list_for_each_entry_safe(cur_mode, t, &connector->probed_modes, head) {
cur_mode->type &= ~DRM_MODE_TYPE_PREFERRED;
if (cur_mode == preferred_mode)
continue;
if (MODE_SIZE(cur_mode) > MODE_SIZE(preferred_mode))
preferred_mode = cur_mode;
cur_vrefresh = cur_mode->vrefresh ?
cur_mode->vrefresh : drm_mode_vrefresh(cur_mode);
preferred_vrefresh = preferred_mode->vrefresh ?
preferred_mode->vrefresh : drm_mode_vrefresh(preferred_mode);
if ((MODE_SIZE(cur_mode) == MODE_SIZE(preferred_mode)) &&
MODE_REFRESH_DIFF(cur_vrefresh, target_refresh) <
MODE_REFRESH_DIFF(preferred_vrefresh, target_refresh)) {
preferred_mode = cur_mode;
}
}
preferred_mode->type |= DRM_MODE_TYPE_PREFERRED;
}
static bool
mode_is_rb(const struct drm_display_mode *mode)
{
return (mode->htotal - mode->hdisplay == 160) &&
(mode->hsync_end - mode->hdisplay == 80) &&
(mode->hsync_end - mode->hsync_start == 32) &&
(mode->vsync_start - mode->vdisplay == 3);
}
struct drm_display_mode *drm_mode_find_dmt(struct drm_device *dev,
int hsize, int vsize, int fresh,
bool rb)
{
int i;
for (i = 0; i < ARRAY_SIZE(drm_dmt_modes); i++) {
const struct drm_display_mode *ptr = &drm_dmt_modes[i];
if (hsize != ptr->hdisplay)
continue;
if (vsize != ptr->vdisplay)
continue;
if (fresh != drm_mode_vrefresh(ptr))
continue;
if (rb != mode_is_rb(ptr))
continue;
return drm_mode_duplicate(dev, ptr);
}
return NULL;
}
static void
cea_for_each_detailed_block(u8 *ext, detailed_cb *cb, void *closure)
{
int i, n = 0;
u8 d = ext[0x02];
u8 *det_base = ext + d;
n = (127 - d) / 18;
for (i = 0; i < n; i++)
cb((struct detailed_timing *)(det_base + 18 * i), closure);
}
static void
vtb_for_each_detailed_block(u8 *ext, detailed_cb *cb, void *closure)
{
unsigned int i, n = min((int)ext[0x02], 6);
u8 *det_base = ext + 5;
if (ext[0x01] != 1)
return;
for (i = 0; i < n; i++)
cb((struct detailed_timing *)(det_base + 18 * i), closure);
}
static void
drm_for_each_detailed_block(u8 *raw_edid, detailed_cb *cb, void *closure)
{
int i;
struct edid *edid = (struct edid *)raw_edid;
if (edid == NULL)
return;
for (i = 0; i < EDID_DETAILED_TIMINGS; i++)
cb(&(edid->detailed_timings[i]), closure);
for (i = 1; i <= raw_edid[0x7e]; i++) {
u8 *ext = raw_edid + (i * EDID_LENGTH);
switch (*ext) {
case CEA_EXT:
cea_for_each_detailed_block(ext, cb, closure);
break;
case VTB_EXT:
vtb_for_each_detailed_block(ext, cb, closure);
break;
default:
break;
}
}
}
static void
is_rb(struct detailed_timing *t, void *data)
{
u8 *r = (u8 *)t;
if (r[3] == EDID_DETAIL_MONITOR_RANGE)
if (r[15] & 0x10)
*(bool *)data = true;
}
static bool
drm_monitor_supports_rb(struct edid *edid)
{
if (edid->revision >= 4) {
bool ret = false;
drm_for_each_detailed_block((u8 *)edid, is_rb, &ret);
return ret;
}
return ((edid->input & DRM_EDID_INPUT_DIGITAL) != 0);
}
static void
find_gtf2(struct detailed_timing *t, void *data)
{
u8 *r = (u8 *)t;
if (r[3] == EDID_DETAIL_MONITOR_RANGE && r[10] == 0x02)
*(u8 **)data = r;
}
static int
drm_gtf2_hbreak(struct edid *edid)
{
u8 *r = NULL;
drm_for_each_detailed_block((u8 *)edid, find_gtf2, &r);
return r ? (r[12] * 2) : 0;
}
static int
drm_gtf2_2c(struct edid *edid)
{
u8 *r = NULL;
drm_for_each_detailed_block((u8 *)edid, find_gtf2, &r);
return r ? r[13] : 0;
}
static int
drm_gtf2_m(struct edid *edid)
{
u8 *r = NULL;
drm_for_each_detailed_block((u8 *)edid, find_gtf2, &r);
return r ? (r[15] << 8) + r[14] : 0;
}
static int
drm_gtf2_k(struct edid *edid)
{
u8 *r = NULL;
drm_for_each_detailed_block((u8 *)edid, find_gtf2, &r);
return r ? r[16] : 0;
}
static int
drm_gtf2_2j(struct edid *edid)
{
u8 *r = NULL;
drm_for_each_detailed_block((u8 *)edid, find_gtf2, &r);
return r ? r[17] : 0;
}
static int standard_timing_level(struct edid *edid)
{
if (edid->revision >= 2) {
if (edid->revision >= 4 && (edid->features & DRM_EDID_FEATURE_DEFAULT_GTF))
return LEVEL_CVT;
if (drm_gtf2_hbreak(edid))
return LEVEL_GTF2;
return LEVEL_GTF;
}
return LEVEL_DMT;
}
static int
bad_std_timing(u8 a, u8 b)
{
return (a == 0x00 && b == 0x00) ||
(a == 0x01 && b == 0x01) ||
(a == 0x20 && b == 0x20);
}
static struct drm_display_mode *
drm_mode_std(struct drm_connector *connector, struct edid *edid,
struct std_timing *t)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *m, *mode = NULL;
int hsize, vsize;
int vrefresh_rate;
unsigned aspect_ratio = (t->vfreq_aspect & EDID_TIMING_ASPECT_MASK)
>> EDID_TIMING_ASPECT_SHIFT;
unsigned vfreq = (t->vfreq_aspect & EDID_TIMING_VFREQ_MASK)
>> EDID_TIMING_VFREQ_SHIFT;
int timing_level = standard_timing_level(edid);
if (bad_std_timing(t->hsize, t->vfreq_aspect))
return NULL;
hsize = t->hsize * 8 + 248;
vrefresh_rate = vfreq + 60;
if (aspect_ratio == 0) {
if (edid->revision < 3)
vsize = hsize;
else
vsize = (hsize * 10) / 16;
} else if (aspect_ratio == 1)
vsize = (hsize * 3) / 4;
else if (aspect_ratio == 2)
vsize = (hsize * 4) / 5;
else
vsize = (hsize * 9) / 16;
if (vrefresh_rate == 60 &&
((hsize == 1360 && vsize == 765) ||
(hsize == 1368 && vsize == 769))) {
hsize = 1366;
vsize = 768;
}
list_for_each_entry(m, &connector->probed_modes, head)
if (m->hdisplay == hsize && m->vdisplay == vsize &&
drm_mode_vrefresh(m) == vrefresh_rate)
return NULL;
if (hsize == 1366 && vsize == 768 && vrefresh_rate == 60) {
mode = drm_cvt_mode(dev, 1366, 768, vrefresh_rate, 0, 0,
false);
mode->hdisplay = 1366;
mode->hsync_start = mode->hsync_start - 1;
mode->hsync_end = mode->hsync_end - 1;
return mode;
}
if (drm_monitor_supports_rb(edid)) {
mode = drm_mode_find_dmt(dev, hsize, vsize, vrefresh_rate,
true);
if (mode)
return mode;
}
mode = drm_mode_find_dmt(dev, hsize, vsize, vrefresh_rate, false);
if (mode)
return mode;
switch (timing_level) {
case LEVEL_DMT:
break;
case LEVEL_GTF:
mode = drm_gtf_mode(dev, hsize, vsize, vrefresh_rate, 0, 0);
break;
case LEVEL_GTF2:
mode = drm_gtf_mode(dev, hsize, vsize, vrefresh_rate, 0, 0);
if (!mode)
return NULL;
if (drm_mode_hsync(mode) > drm_gtf2_hbreak(edid)) {
drm_mode_destroy(dev, mode);
mode = drm_gtf_mode_complex(dev, hsize, vsize,
vrefresh_rate, 0, 0,
drm_gtf2_m(edid),
drm_gtf2_2c(edid),
drm_gtf2_k(edid),
drm_gtf2_2j(edid));
}
break;
case LEVEL_CVT:
mode = drm_cvt_mode(dev, hsize, vsize, vrefresh_rate, 0, 0,
false);
break;
}
return mode;
}
static void
drm_mode_do_interlace_quirk(struct drm_display_mode *mode,
struct detailed_pixel_timing *pt)
{
int i;
static const struct {
int w, h;
} cea_interlaced[] = {
{ 1920, 1080 },
{ 720, 480 },
{ 1440, 480 },
{ 2880, 480 },
{ 720, 576 },
{ 1440, 576 },
{ 2880, 576 },
};
if (!(pt->misc & DRM_EDID_PT_INTERLACED))
return;
for (i = 0; i < ARRAY_SIZE(cea_interlaced); i++) {
if ((mode->hdisplay == cea_interlaced[i].w) &&
(mode->vdisplay == cea_interlaced[i].h / 2)) {
mode->vdisplay *= 2;
mode->vsync_start *= 2;
mode->vsync_end *= 2;
mode->vtotal *= 2;
mode->vtotal |= 1;
}
}
mode->flags |= DRM_MODE_FLAG_INTERLACE;
}
static struct drm_display_mode *drm_mode_detailed(struct drm_device *dev,
struct edid *edid,
struct detailed_timing *timing,
u32 quirks)
{
struct drm_display_mode *mode;
struct detailed_pixel_timing *pt = &timing->data.pixel_data;
unsigned hactive = (pt->hactive_hblank_hi & 0xf0) << 4 | pt->hactive_lo;
unsigned vactive = (pt->vactive_vblank_hi & 0xf0) << 4 | pt->vactive_lo;
unsigned hblank = (pt->hactive_hblank_hi & 0xf) << 8 | pt->hblank_lo;
unsigned vblank = (pt->vactive_vblank_hi & 0xf) << 8 | pt->vblank_lo;
unsigned hsync_offset = (pt->hsync_vsync_offset_pulse_width_hi & 0xc0) << 2 | pt->hsync_offset_lo;
unsigned hsync_pulse_width = (pt->hsync_vsync_offset_pulse_width_hi & 0x30) << 4 | pt->hsync_pulse_width_lo;
unsigned vsync_offset = (pt->hsync_vsync_offset_pulse_width_hi & 0xc) << 2 | pt->vsync_offset_pulse_width_lo >> 4;
unsigned vsync_pulse_width = (pt->hsync_vsync_offset_pulse_width_hi & 0x3) << 4 | (pt->vsync_offset_pulse_width_lo & 0xf);
if (hactive < 64 || vactive < 64)
return NULL;
if (pt->misc & DRM_EDID_PT_STEREO) {
DRM_DEBUG_KMS("stereo mode not supported\n");
return NULL;
}
if (!(pt->misc & DRM_EDID_PT_SEPARATE_SYNC)) {
DRM_DEBUG_KMS("composite sync not supported\n");
}
if (!hsync_pulse_width || !vsync_pulse_width) {
DRM_DEBUG_KMS("Incorrect Detailed timing. "
"Wrong Hsync/Vsync pulse width\n");
return NULL;
}
if (quirks & EDID_QUIRK_FORCE_REDUCED_BLANKING) {
mode = drm_cvt_mode(dev, hactive, vactive, 60, true, false, false);
if (!mode)
return NULL;
goto set_size;
}
mode = drm_mode_create(dev);
if (!mode)
return NULL;
if (quirks & EDID_QUIRK_135_CLOCK_TOO_HIGH)
timing->pixel_clock = cpu_to_le16(1088);
mode->clock = le16_to_cpu(timing->pixel_clock) * 10;
mode->hdisplay = hactive;
mode->hsync_start = mode->hdisplay + hsync_offset;
mode->hsync_end = mode->hsync_start + hsync_pulse_width;
mode->htotal = mode->hdisplay + hblank;
mode->vdisplay = vactive;
mode->vsync_start = mode->vdisplay + vsync_offset;
mode->vsync_end = mode->vsync_start + vsync_pulse_width;
mode->vtotal = mode->vdisplay + vblank;
if (mode->hsync_end > mode->htotal)
mode->htotal = mode->hsync_end + 1;
if (mode->vsync_end > mode->vtotal)
mode->vtotal = mode->vsync_end + 1;
drm_mode_do_interlace_quirk(mode, pt);
if (quirks & EDID_QUIRK_DETAILED_SYNC_PP) {
pt->misc |= DRM_EDID_PT_HSYNC_POSITIVE | DRM_EDID_PT_VSYNC_POSITIVE;
}
mode->flags |= (pt->misc & DRM_EDID_PT_HSYNC_POSITIVE) ?
DRM_MODE_FLAG_PHSYNC : DRM_MODE_FLAG_NHSYNC;
mode->flags |= (pt->misc & DRM_EDID_PT_VSYNC_POSITIVE) ?
DRM_MODE_FLAG_PVSYNC : DRM_MODE_FLAG_NVSYNC;
set_size:
mode->width_mm = pt->width_mm_lo | (pt->width_height_mm_hi & 0xf0) << 4;
mode->height_mm = pt->height_mm_lo | (pt->width_height_mm_hi & 0xf) << 8;
if (quirks & EDID_QUIRK_DETAILED_IN_CM) {
mode->width_mm *= 10;
mode->height_mm *= 10;
}
if (quirks & EDID_QUIRK_DETAILED_USE_MAXIMUM_SIZE) {
mode->width_mm = edid->width_cm * 10;
mode->height_mm = edid->height_cm * 10;
}
mode->type = DRM_MODE_TYPE_DRIVER;
mode->vrefresh = drm_mode_vrefresh(mode);
drm_mode_set_name(mode);
return mode;
}
static bool
mode_in_hsync_range(const struct drm_display_mode *mode,
struct edid *edid, u8 *t)
{
int hsync, hmin, hmax;
hmin = t[7];
if (edid->revision >= 4)
hmin += ((t[4] & 0x04) ? 255 : 0);
hmax = t[8];
if (edid->revision >= 4)
hmax += ((t[4] & 0x08) ? 255 : 0);
hsync = drm_mode_hsync(mode);
return (hsync <= hmax && hsync >= hmin);
}
static bool
mode_in_vsync_range(const struct drm_display_mode *mode,
struct edid *edid, u8 *t)
{
int vsync, vmin, vmax;
vmin = t[5];
if (edid->revision >= 4)
vmin += ((t[4] & 0x01) ? 255 : 0);
vmax = t[6];
if (edid->revision >= 4)
vmax += ((t[4] & 0x02) ? 255 : 0);
vsync = drm_mode_vrefresh(mode);
return (vsync <= vmax && vsync >= vmin);
}
static u32
range_pixel_clock(struct edid *edid, u8 *t)
{
if (t[9] == 0 || t[9] == 255)
return 0;
if (edid->revision >= 4 && t[10] == 0x04)
return (t[9] * 10000) - ((t[12] >> 2) * 250);
return t[9] * 10000 + 5001;
}
static bool
mode_in_range(const struct drm_display_mode *mode, struct edid *edid,
struct detailed_timing *timing)
{
u32 max_clock;
u8 *t = (u8 *)timing;
if (!mode_in_hsync_range(mode, edid, t))
return false;
if (!mode_in_vsync_range(mode, edid, t))
return false;
if ((max_clock = range_pixel_clock(edid, t)))
if (mode->clock > max_clock)
return false;
if (edid->revision >= 4 && t[10] == 0x04)
if (t[13] && mode->hdisplay > 8 * (t[13] + (256 * (t[12]&0x3))))
return false;
if (mode_is_rb(mode) && !drm_monitor_supports_rb(edid))
return false;
return true;
}
static bool valid_inferred_mode(const struct drm_connector *connector,
const struct drm_display_mode *mode)
{
const struct drm_display_mode *m;
bool ok = false;
list_for_each_entry(m, &connector->probed_modes, head) {
if (mode->hdisplay == m->hdisplay &&
mode->vdisplay == m->vdisplay &&
drm_mode_vrefresh(mode) == drm_mode_vrefresh(m))
return false;
if (mode->hdisplay <= m->hdisplay &&
mode->vdisplay <= m->vdisplay)
ok = true;
}
return ok;
}
static int
drm_dmt_modes_for_range(struct drm_connector *connector, struct edid *edid,
struct detailed_timing *timing)
{
int i, modes = 0;
struct drm_display_mode *newmode;
struct drm_device *dev = connector->dev;
for (i = 0; i < ARRAY_SIZE(drm_dmt_modes); i++) {
if (mode_in_range(drm_dmt_modes + i, edid, timing) &&
valid_inferred_mode(connector, drm_dmt_modes + i)) {
newmode = drm_mode_duplicate(dev, &drm_dmt_modes[i]);
if (newmode) {
drm_mode_probed_add(connector, newmode);
modes++;
}
}
}
return modes;
}
void drm_mode_fixup_1366x768(struct drm_display_mode *mode)
{
if (mode->hdisplay == 1368 && mode->vdisplay == 768) {
mode->hdisplay = 1366;
mode->hsync_start--;
mode->hsync_end--;
drm_mode_set_name(mode);
}
}
static int
drm_gtf_modes_for_range(struct drm_connector *connector, struct edid *edid,
struct detailed_timing *timing)
{
int i, modes = 0;
struct drm_display_mode *newmode;
struct drm_device *dev = connector->dev;
for (i = 0; i < ARRAY_SIZE(extra_modes); i++) {
const struct minimode *m = &extra_modes[i];
newmode = drm_gtf_mode(dev, m->w, m->h, m->r, 0, 0);
if (!newmode)
return modes;
drm_mode_fixup_1366x768(newmode);
if (!mode_in_range(newmode, edid, timing) ||
!valid_inferred_mode(connector, newmode)) {
drm_mode_destroy(dev, newmode);
continue;
}
drm_mode_probed_add(connector, newmode);
modes++;
}
return modes;
}
static int
drm_cvt_modes_for_range(struct drm_connector *connector, struct edid *edid,
struct detailed_timing *timing)
{
int i, modes = 0;
struct drm_display_mode *newmode;
struct drm_device *dev = connector->dev;
bool rb = drm_monitor_supports_rb(edid);
for (i = 0; i < ARRAY_SIZE(extra_modes); i++) {
const struct minimode *m = &extra_modes[i];
newmode = drm_cvt_mode(dev, m->w, m->h, m->r, rb, 0, 0);
if (!newmode)
return modes;
drm_mode_fixup_1366x768(newmode);
if (!mode_in_range(newmode, edid, timing) ||
!valid_inferred_mode(connector, newmode)) {
drm_mode_destroy(dev, newmode);
continue;
}
drm_mode_probed_add(connector, newmode);
modes++;
}
return modes;
}
static void
do_inferred_modes(struct detailed_timing *timing, void *c)
{
struct detailed_mode_closure *closure = c;
struct detailed_non_pixel *data = &timing->data.other_data;
struct detailed_data_monitor_range *range = &data->data.range;
if (data->type != EDID_DETAIL_MONITOR_RANGE)
return;
closure->modes += drm_dmt_modes_for_range(closure->connector,
closure->edid,
timing);
if (!version_greater(closure->edid, 1, 1))
return;
switch (range->flags) {
case 0x02:
case 0x00:
closure->modes += drm_gtf_modes_for_range(closure->connector,
closure->edid,
timing);
break;
case 0x04:
if (!version_greater(closure->edid, 1, 3))
break;
closure->modes += drm_cvt_modes_for_range(closure->connector,
closure->edid,
timing);
break;
case 0x01:
default:
break;
}
}
static int
add_inferred_modes(struct drm_connector *connector, struct edid *edid)
{
struct detailed_mode_closure closure = {
.connector = connector,
.edid = edid,
};
if (version_greater(edid, 1, 0))
drm_for_each_detailed_block((u8 *)edid, do_inferred_modes,
&closure);
return closure.modes;
}
static int
drm_est3_modes(struct drm_connector *connector, struct detailed_timing *timing)
{
int i, j, m, modes = 0;
struct drm_display_mode *mode;
u8 *est = ((u8 *)timing) + 6;
for (i = 0; i < 6; i++) {
for (j = 7; j >= 0; j--) {
m = (i * 8) + (7 - j);
if (m >= ARRAY_SIZE(est3_modes))
break;
if (est[i] & (1 << j)) {
mode = drm_mode_find_dmt(connector->dev,
est3_modes[m].w,
est3_modes[m].h,
est3_modes[m].r,
est3_modes[m].rb);
if (mode) {
drm_mode_probed_add(connector, mode);
modes++;
}
}
}
}
return modes;
}
static void
do_established_modes(struct detailed_timing *timing, void *c)
{
struct detailed_mode_closure *closure = c;
struct detailed_non_pixel *data = &timing->data.other_data;
if (data->type == EDID_DETAIL_EST_TIMINGS)
closure->modes += drm_est3_modes(closure->connector, timing);
}
static int
add_established_modes(struct drm_connector *connector, struct edid *edid)
{
struct drm_device *dev = connector->dev;
unsigned long est_bits = edid->established_timings.t1 |
(edid->established_timings.t2 << 8) |
((edid->established_timings.mfg_rsvd & 0x80) << 9);
int i, modes = 0;
struct detailed_mode_closure closure = {
.connector = connector,
.edid = edid,
};
for (i = 0; i <= EDID_EST_TIMINGS; i++) {
if (est_bits & (1<<i)) {
struct drm_display_mode *newmode;
newmode = drm_mode_duplicate(dev, &edid_est_modes[i]);
if (newmode) {
drm_mode_probed_add(connector, newmode);
modes++;
}
}
}
if (version_greater(edid, 1, 0))
drm_for_each_detailed_block((u8 *)edid,
do_established_modes, &closure);
return modes + closure.modes;
}
static void
do_standard_modes(struct detailed_timing *timing, void *c)
{
struct detailed_mode_closure *closure = c;
struct detailed_non_pixel *data = &timing->data.other_data;
struct drm_connector *connector = closure->connector;
struct edid *edid = closure->edid;
if (data->type == EDID_DETAIL_STD_MODES) {
int i;
for (i = 0; i < 6; i++) {
struct std_timing *std;
struct drm_display_mode *newmode;
std = &data->data.timings[i];
newmode = drm_mode_std(connector, edid, std);
if (newmode) {
drm_mode_probed_add(connector, newmode);
closure->modes++;
}
}
}
}
static int
add_standard_modes(struct drm_connector *connector, struct edid *edid)
{
int i, modes = 0;
struct detailed_mode_closure closure = {
.connector = connector,
.edid = edid,
};
for (i = 0; i < EDID_STD_TIMINGS; i++) {
struct drm_display_mode *newmode;
newmode = drm_mode_std(connector, edid,
&edid->standard_timings[i]);
if (newmode) {
drm_mode_probed_add(connector, newmode);
modes++;
}
}
if (version_greater(edid, 1, 0))
drm_for_each_detailed_block((u8 *)edid, do_standard_modes,
&closure);
return modes + closure.modes;
}
static int drm_cvt_modes(struct drm_connector *connector,
struct detailed_timing *timing)
{
int i, j, modes = 0;
struct drm_display_mode *newmode;
struct drm_device *dev = connector->dev;
struct cvt_timing *cvt;
const int rates[] = { 60, 85, 75, 60, 50 };
const u8 empty[3] = { 0, 0, 0 };
for (i = 0; i < 4; i++) {
int uninitialized_var(width), height;
cvt = &(timing->data.other_data.data.cvt[i]);
if (!memcmp(cvt->code, empty, 3))
continue;
height = (cvt->code[0] + ((cvt->code[1] & 0xf0) << 4) + 1) * 2;
switch (cvt->code[1] & 0x0c) {
case 0x00:
width = height * 4 / 3;
break;
case 0x04:
width = height * 16 / 9;
break;
case 0x08:
width = height * 16 / 10;
break;
case 0x0c:
width = height * 15 / 9;
break;
}
for (j = 1; j < 5; j++) {
if (cvt->code[2] & (1 << j)) {
newmode = drm_cvt_mode(dev, width, height,
rates[j], j == 0,
false, false);
if (newmode) {
drm_mode_probed_add(connector, newmode);
modes++;
}
}
}
}
return modes;
}
static void
do_cvt_mode(struct detailed_timing *timing, void *c)
{
struct detailed_mode_closure *closure = c;
struct detailed_non_pixel *data = &timing->data.other_data;
if (data->type == EDID_DETAIL_CVT_3BYTE)
closure->modes += drm_cvt_modes(closure->connector, timing);
}
static int
add_cvt_modes(struct drm_connector *connector, struct edid *edid)
{
struct detailed_mode_closure closure = {
.connector = connector,
.edid = edid,
};
if (version_greater(edid, 1, 2))
drm_for_each_detailed_block((u8 *)edid, do_cvt_mode, &closure);
return closure.modes;
}
static void
do_detailed_mode(struct detailed_timing *timing, void *c)
{
struct detailed_mode_closure *closure = c;
struct drm_display_mode *newmode;
if (timing->pixel_clock) {
newmode = drm_mode_detailed(closure->connector->dev,
closure->edid, timing,
closure->quirks);
if (!newmode)
return;
if (closure->preferred)
newmode->type |= DRM_MODE_TYPE_PREFERRED;
fixup_detailed_cea_mode_clock(newmode);
drm_mode_probed_add(closure->connector, newmode);
closure->modes++;
closure->preferred = 0;
}
}
static int
add_detailed_modes(struct drm_connector *connector, struct edid *edid,
u32 quirks)
{
struct detailed_mode_closure closure = {
.connector = connector,
.edid = edid,
.preferred = 1,
.quirks = quirks,
};
if (closure.preferred && !version_greater(edid, 1, 3))
closure.preferred =
(edid->features & DRM_EDID_FEATURE_PREFERRED_TIMING);
drm_for_each_detailed_block((u8 *)edid, do_detailed_mode, &closure);
return closure.modes;
}
static u8 *drm_find_edid_extension(struct edid *edid, int ext_id)
{
u8 *edid_ext = NULL;
int i;
if (edid == NULL || edid->extensions == 0)
return NULL;
for (i = 0; i < edid->extensions; i++) {
edid_ext = (u8 *)edid + EDID_LENGTH * (i + 1);
if (edid_ext[0] == ext_id)
break;
}
if (i == edid->extensions)
return NULL;
return edid_ext;
}
static u8 *drm_find_cea_extension(struct edid *edid)
{
return drm_find_edid_extension(edid, CEA_EXT);
}
static u8 *drm_find_displayid_extension(struct edid *edid)
{
return drm_find_edid_extension(edid, DISPLAYID_EXT);
}
static unsigned int
cea_mode_alternate_clock(const struct drm_display_mode *cea_mode)
{
unsigned int clock = cea_mode->clock;
if (cea_mode->vrefresh % 6 != 0)
return clock;
if (cea_mode->vdisplay == 240 || cea_mode->vdisplay == 480)
clock = DIV_ROUND_CLOSEST(clock * 1001, 1000);
else
clock = DIV_ROUND_CLOSEST(clock * 1000, 1001);
return clock;
}
static bool
cea_mode_alternate_timings(u8 vic, struct drm_display_mode *mode)
{
BUILD_BUG_ON(edid_cea_modes[8].vtotal != 262 ||
edid_cea_modes[9].vtotal != 262 ||
edid_cea_modes[12].vtotal != 262 ||
edid_cea_modes[13].vtotal != 262 ||
edid_cea_modes[23].vtotal != 312 ||
edid_cea_modes[24].vtotal != 312 ||
edid_cea_modes[27].vtotal != 312 ||
edid_cea_modes[28].vtotal != 312);
if (((vic == 8 || vic == 9 ||
vic == 12 || vic == 13) && mode->vtotal < 263) ||
((vic == 23 || vic == 24 ||
vic == 27 || vic == 28) && mode->vtotal < 314)) {
mode->vsync_start++;
mode->vsync_end++;
mode->vtotal++;
return true;
}
return false;
}
static u8 drm_match_cea_mode_clock_tolerance(const struct drm_display_mode *to_match,
unsigned int clock_tolerance)
{
u8 vic;
if (!to_match->clock)
return 0;
for (vic = 1; vic < ARRAY_SIZE(edid_cea_modes); vic++) {
struct drm_display_mode cea_mode = edid_cea_modes[vic];
unsigned int clock1, clock2;
clock1 = cea_mode.clock;
clock2 = cea_mode_alternate_clock(&cea_mode);
if (abs(to_match->clock - clock1) > clock_tolerance &&
abs(to_match->clock - clock2) > clock_tolerance)
continue;
do {
if (drm_mode_equal_no_clocks_no_stereo(to_match, &cea_mode))
return vic;
} while (cea_mode_alternate_timings(vic, &cea_mode));
}
return 0;
}
u8 drm_match_cea_mode(const struct drm_display_mode *to_match)
{
u8 vic;
if (!to_match->clock)
return 0;
for (vic = 1; vic < ARRAY_SIZE(edid_cea_modes); vic++) {
struct drm_display_mode cea_mode = edid_cea_modes[vic];
unsigned int clock1, clock2;
clock1 = cea_mode.clock;
clock2 = cea_mode_alternate_clock(&cea_mode);
if (KHZ2PICOS(to_match->clock) != KHZ2PICOS(clock1) &&
KHZ2PICOS(to_match->clock) != KHZ2PICOS(clock2))
continue;
do {
if (drm_mode_equal_no_clocks_no_stereo(to_match, &cea_mode))
return vic;
} while (cea_mode_alternate_timings(vic, &cea_mode));
}
return 0;
}
static bool drm_valid_cea_vic(u8 vic)
{
return vic > 0 && vic < ARRAY_SIZE(edid_cea_modes);
}
enum hdmi_picture_aspect drm_get_cea_aspect_ratio(const u8 video_code)
{
return edid_cea_modes[video_code].picture_aspect_ratio;
}
static unsigned int
hdmi_mode_alternate_clock(const struct drm_display_mode *hdmi_mode)
{
if (hdmi_mode->vdisplay == 4096 && hdmi_mode->hdisplay == 2160)
return hdmi_mode->clock;
return cea_mode_alternate_clock(hdmi_mode);
}
static u8 drm_match_hdmi_mode_clock_tolerance(const struct drm_display_mode *to_match,
unsigned int clock_tolerance)
{
u8 vic;
if (!to_match->clock)
return 0;
for (vic = 1; vic < ARRAY_SIZE(edid_4k_modes); vic++) {
const struct drm_display_mode *hdmi_mode = &edid_4k_modes[vic];
unsigned int clock1, clock2;
clock1 = hdmi_mode->clock;
clock2 = hdmi_mode_alternate_clock(hdmi_mode);
if (abs(to_match->clock - clock1) > clock_tolerance &&
abs(to_match->clock - clock2) > clock_tolerance)
continue;
if (drm_mode_equal_no_clocks(to_match, hdmi_mode))
return vic;
}
return 0;
}
static u8 drm_match_hdmi_mode(const struct drm_display_mode *to_match)
{
u8 vic;
if (!to_match->clock)
return 0;
for (vic = 1; vic < ARRAY_SIZE(edid_4k_modes); vic++) {
const struct drm_display_mode *hdmi_mode = &edid_4k_modes[vic];
unsigned int clock1, clock2;
clock1 = hdmi_mode->clock;
clock2 = hdmi_mode_alternate_clock(hdmi_mode);
if ((KHZ2PICOS(to_match->clock) == KHZ2PICOS(clock1) ||
KHZ2PICOS(to_match->clock) == KHZ2PICOS(clock2)) &&
drm_mode_equal_no_clocks_no_stereo(to_match, hdmi_mode))
return vic;
}
return 0;
}
static bool drm_valid_hdmi_vic(u8 vic)
{
return vic > 0 && vic < ARRAY_SIZE(edid_4k_modes);
}
static int
add_alternate_cea_modes(struct drm_connector *connector, struct edid *edid)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode, *tmp;
LIST_HEAD(list);
int modes = 0;
if (!drm_find_cea_extension(edid))
return 0;
list_for_each_entry(mode, &connector->probed_modes, head) {
const struct drm_display_mode *cea_mode = NULL;
struct drm_display_mode *newmode;
u8 vic = drm_match_cea_mode(mode);
unsigned int clock1, clock2;
if (drm_valid_cea_vic(vic)) {
cea_mode = &edid_cea_modes[vic];
clock2 = cea_mode_alternate_clock(cea_mode);
} else {
vic = drm_match_hdmi_mode(mode);
if (drm_valid_hdmi_vic(vic)) {
cea_mode = &edid_4k_modes[vic];
clock2 = hdmi_mode_alternate_clock(cea_mode);
}
}
if (!cea_mode)
continue;
clock1 = cea_mode->clock;
if (clock1 == clock2)
continue;
if (mode->clock != clock1 && mode->clock != clock2)
continue;
newmode = drm_mode_duplicate(dev, cea_mode);
if (!newmode)
continue;
newmode->flags |= mode->flags & DRM_MODE_FLAG_3D_MASK;
if (mode->clock != clock1)
newmode->clock = clock1;
else
newmode->clock = clock2;
list_add_tail(&newmode->head, &list);
}
list_for_each_entry_safe(mode, tmp, &list, head) {
list_del(&mode->head);
drm_mode_probed_add(connector, mode);
modes++;
}
return modes;
}
static struct drm_display_mode *
drm_display_mode_from_vic_index(struct drm_connector *connector,
const u8 *video_db, u8 video_len,
u8 video_index)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *newmode;
u8 vic;
if (video_db == NULL || video_index >= video_len)
return NULL;
vic = (video_db[video_index] & 127);
if (!drm_valid_cea_vic(vic))
return NULL;
newmode = drm_mode_duplicate(dev, &edid_cea_modes[vic]);
if (!newmode)
return NULL;
newmode->vrefresh = 0;
return newmode;
}
static int
do_cea_modes(struct drm_connector *connector, const u8 *db, u8 len)
{
int i, modes = 0;
for (i = 0; i < len; i++) {
struct drm_display_mode *mode;
mode = drm_display_mode_from_vic_index(connector, db, len, i);
if (mode) {
drm_mode_probed_add(connector, mode);
modes++;
}
}
return modes;
}
static bool
stereo_match_mandatory(const struct drm_display_mode *mode,
const struct stereo_mandatory_mode *stereo_mode)
{
unsigned int interlaced = mode->flags & DRM_MODE_FLAG_INTERLACE;
return mode->hdisplay == stereo_mode->width &&
mode->vdisplay == stereo_mode->height &&
interlaced == (stereo_mode->flags & DRM_MODE_FLAG_INTERLACE) &&
drm_mode_vrefresh(mode) == stereo_mode->vrefresh;
}
static int add_hdmi_mandatory_stereo_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
const struct drm_display_mode *mode;
struct list_head stereo_modes;
int modes = 0, i;
INIT_LIST_HEAD(&stereo_modes);
list_for_each_entry(mode, &connector->probed_modes, head) {
for (i = 0; i < ARRAY_SIZE(stereo_mandatory_modes); i++) {
const struct stereo_mandatory_mode *mandatory;
struct drm_display_mode *new_mode;
if (!stereo_match_mandatory(mode,
&stereo_mandatory_modes[i]))
continue;
mandatory = &stereo_mandatory_modes[i];
new_mode = drm_mode_duplicate(dev, mode);
if (!new_mode)
continue;
new_mode->flags |= mandatory->flags;
list_add_tail(&new_mode->head, &stereo_modes);
modes++;
}
}
list_splice_tail(&stereo_modes, &connector->probed_modes);
return modes;
}
static int add_hdmi_mode(struct drm_connector *connector, u8 vic)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *newmode;
if (!drm_valid_hdmi_vic(vic)) {
DRM_ERROR("Unknown HDMI VIC: %d\n", vic);
return 0;
}
newmode = drm_mode_duplicate(dev, &edid_4k_modes[vic]);
if (!newmode)
return 0;
drm_mode_probed_add(connector, newmode);
return 1;
}
static int add_3d_struct_modes(struct drm_connector *connector, u16 structure,
const u8 *video_db, u8 video_len, u8 video_index)
{
struct drm_display_mode *newmode;
int modes = 0;
if (structure & (1 << 0)) {
newmode = drm_display_mode_from_vic_index(connector, video_db,
video_len,
video_index);
if (newmode) {
newmode->flags |= DRM_MODE_FLAG_3D_FRAME_PACKING;
drm_mode_probed_add(connector, newmode);
modes++;
}
}
if (structure & (1 << 6)) {
newmode = drm_display_mode_from_vic_index(connector, video_db,
video_len,
video_index);
if (newmode) {
newmode->flags |= DRM_MODE_FLAG_3D_TOP_AND_BOTTOM;
drm_mode_probed_add(connector, newmode);
modes++;
}
}
if (structure & (1 << 8)) {
newmode = drm_display_mode_from_vic_index(connector, video_db,
video_len,
video_index);
if (newmode) {
newmode->flags |= DRM_MODE_FLAG_3D_SIDE_BY_SIDE_HALF;
drm_mode_probed_add(connector, newmode);
modes++;
}
}
return modes;
}
static int
do_hdmi_vsdb_modes(struct drm_connector *connector, const u8 *db, u8 len,
const u8 *video_db, u8 video_len)
{
int modes = 0, offset = 0, i, multi_present = 0, multi_len;
u8 vic_len, hdmi_3d_len = 0;
u16 mask;
u16 structure_all;
if (len < 8)
goto out;
if (!(db[8] & (1 << 5)))
goto out;
if (db[8] & (1 << 7))
offset += 2;
if (db[8] & (1 << 6))
offset += 2;
if (len < (8 + offset + 2))
goto out;
offset++;
if (db[8 + offset] & (1 << 7)) {
modes += add_hdmi_mandatory_stereo_modes(connector);
multi_present = (db[8 + offset] & 0x60) >> 5;
}
offset++;
vic_len = db[8 + offset] >> 5;
hdmi_3d_len = db[8 + offset] & 0x1f;
for (i = 0; i < vic_len && len >= (9 + offset + i); i++) {
u8 vic;
vic = db[9 + offset + i];
modes += add_hdmi_mode(connector, vic);
}
offset += 1 + vic_len;
if (multi_present == 1)
multi_len = 2;
else if (multi_present == 2)
multi_len = 4;
else
multi_len = 0;
if (len < (8 + offset + hdmi_3d_len - 1))
goto out;
if (hdmi_3d_len < multi_len)
goto out;
if (multi_present == 1 || multi_present == 2) {
structure_all = (db[8 + offset] << 8) | db[9 + offset];
if (multi_present == 2)
mask = (db[10 + offset] << 8) | db[11 + offset];
else
mask = 0xffff;
for (i = 0; i < 16; i++) {
if (mask & (1 << i))
modes += add_3d_struct_modes(connector,
structure_all,
video_db,
video_len, i);
}
}
offset += multi_len;
for (i = 0; i < (hdmi_3d_len - multi_len); i++) {
int vic_index;
struct drm_display_mode *newmode = NULL;
unsigned int newflag = 0;
bool detail_present;
detail_present = ((db[8 + offset + i] & 0x0f) > 7);
if (detail_present && (i + 1 == hdmi_3d_len - multi_len))
break;
vic_index = db[8 + offset + i] >> 4;
switch (db[8 + offset + i] & 0x0f) {
case 0:
newflag = DRM_MODE_FLAG_3D_FRAME_PACKING;
break;
case 6:
newflag = DRM_MODE_FLAG_3D_TOP_AND_BOTTOM;
break;
case 8:
if ((db[9 + offset + i] >> 4) == 1)
newflag = DRM_MODE_FLAG_3D_SIDE_BY_SIDE_HALF;
break;
}
if (newflag != 0) {
newmode = drm_display_mode_from_vic_index(connector,
video_db,
video_len,
vic_index);
if (newmode) {
newmode->flags |= newflag;
drm_mode_probed_add(connector, newmode);
modes++;
}
}
if (detail_present)
i++;
}
out:
return modes;
}
static int
cea_db_payload_len(const u8 *db)
{
return db[0] & 0x1f;
}
static int
cea_db_tag(const u8 *db)
{
return db[0] >> 5;
}
static int
cea_revision(const u8 *cea)
{
return cea[1];
}
static int
cea_db_offsets(const u8 *cea, int *start, int *end)
{
*start = 4;
*end = cea[2];
if (*end == 0)
*end = 127;
if (*end < 4 || *end > 127)
return -ERANGE;
return 0;
}
static bool cea_db_is_hdmi_vsdb(const u8 *db)
{
int hdmi_id;
if (cea_db_tag(db) != VENDOR_BLOCK)
return false;
if (cea_db_payload_len(db) < 5)
return false;
hdmi_id = db[1] | (db[2] << 8) | (db[3] << 16);
return hdmi_id == HDMI_IEEE_OUI;
}
static bool cea_db_is_hdmi_forum_vsdb(const u8 *db)
{
unsigned int oui;
if (cea_db_tag(db) != VENDOR_BLOCK)
return false;
if (cea_db_payload_len(db) < 7)
return false;
oui = db[3] << 16 | db[2] << 8 | db[1];
return oui == HDMI_FORUM_IEEE_OUI;
}
static int
add_cea_modes(struct drm_connector *connector, struct edid *edid)
{
const u8 *cea = drm_find_cea_extension(edid);
const u8 *db, *hdmi = NULL, *video = NULL;
u8 dbl, hdmi_len, video_len = 0;
int modes = 0;
if (cea && cea_revision(cea) >= 3) {
int i, start, end;
if (cea_db_offsets(cea, &start, &end))
return 0;
for_each_cea_db(cea, i, start, end) {
db = &cea[i];
dbl = cea_db_payload_len(db);
if (cea_db_tag(db) == VIDEO_BLOCK) {
video = db + 1;
video_len = dbl;
modes += do_cea_modes(connector, video, dbl);
}
else if (cea_db_is_hdmi_vsdb(db)) {
hdmi = db;
hdmi_len = dbl;
}
}
}
if (hdmi)
modes += do_hdmi_vsdb_modes(connector, hdmi, hdmi_len, video,
video_len);
return modes;
}
static void fixup_detailed_cea_mode_clock(struct drm_display_mode *mode)
{
const struct drm_display_mode *cea_mode;
int clock1, clock2, clock;
u8 vic;
const char *type;
vic = drm_match_cea_mode_clock_tolerance(mode, 5);
if (drm_valid_cea_vic(vic)) {
type = "CEA";
cea_mode = &edid_cea_modes[vic];
clock1 = cea_mode->clock;
clock2 = cea_mode_alternate_clock(cea_mode);
} else {
vic = drm_match_hdmi_mode_clock_tolerance(mode, 5);
if (drm_valid_hdmi_vic(vic)) {
type = "HDMI";
cea_mode = &edid_4k_modes[vic];
clock1 = cea_mode->clock;
clock2 = hdmi_mode_alternate_clock(cea_mode);
} else {
return;
}
}
if (abs(mode->clock - clock1) < abs(mode->clock - clock2))
clock = clock1;
else
clock = clock2;
if (mode->clock == clock)
return;
DRM_DEBUG("detailed mode matches %s VIC %d, adjusting clock %d -> %d\n",
type, vic, mode->clock, clock);
mode->clock = clock;
}
static void
drm_parse_hdmi_vsdb_audio(struct drm_connector *connector, const u8 *db)
{
u8 len = cea_db_payload_len(db);
if (len >= 6)
connector->eld[5] |= (db[6] >> 7) << 1;
if (len >= 8) {
connector->latency_present[0] = db[8] >> 7;
connector->latency_present[1] = (db[8] >> 6) & 1;
}
if (len >= 9)
connector->video_latency[0] = db[9];
if (len >= 10)
connector->audio_latency[0] = db[10];
if (len >= 11)
connector->video_latency[1] = db[11];
if (len >= 12)
connector->audio_latency[1] = db[12];
DRM_DEBUG_KMS("HDMI: latency present %d %d, "
"video latency %d %d, "
"audio latency %d %d\n",
connector->latency_present[0],
connector->latency_present[1],
connector->video_latency[0],
connector->video_latency[1],
connector->audio_latency[0],
connector->audio_latency[1]);
}
static void
monitor_name(struct detailed_timing *t, void *data)
{
if (t->data.other_data.type == EDID_DETAIL_MONITOR_NAME)
*(u8 **)data = t->data.other_data.data.str.str;
}
static int get_monitor_name(struct edid *edid, char name[13])
{
char *edid_name = NULL;
int mnl;
if (!edid || !name)
return 0;
drm_for_each_detailed_block((u8 *)edid, monitor_name, &edid_name);
for (mnl = 0; edid_name && mnl < 13; mnl++) {
if (edid_name[mnl] == 0x0a)
break;
name[mnl] = edid_name[mnl];
}
return mnl;
}
void drm_edid_get_monitor_name(struct edid *edid, char *name, int bufsize)
{
int name_length;
char buf[13];
if (bufsize <= 0)
return;
name_length = min(get_monitor_name(edid, buf), bufsize - 1);
memcpy(name, buf, name_length);
name[name_length] = '\0';
}
void drm_edid_to_eld(struct drm_connector *connector, struct edid *edid)
{
uint8_t *eld = connector->eld;
u8 *cea;
u8 *db;
int total_sad_count = 0;
int mnl;
int dbl;
memset(eld, 0, sizeof(connector->eld));
connector->latency_present[0] = false;
connector->latency_present[1] = false;
connector->video_latency[0] = 0;
connector->audio_latency[0] = 0;
connector->video_latency[1] = 0;
connector->audio_latency[1] = 0;
if (!edid)
return;
cea = drm_find_cea_extension(edid);
if (!cea) {
DRM_DEBUG_KMS("ELD: no CEA Extension found\n");
return;
}
mnl = get_monitor_name(edid, eld + 20);
eld[4] = (cea[1] << 5) | mnl;
DRM_DEBUG_KMS("ELD monitor %s\n", eld + 20);
eld[0] = 2 << 3;
eld[16] = edid->mfg_id[0];
eld[17] = edid->mfg_id[1];
eld[18] = edid->prod_code[0];
eld[19] = edid->prod_code[1];
if (cea_revision(cea) >= 3) {
int i, start, end;
if (cea_db_offsets(cea, &start, &end)) {
start = 0;
end = 0;
}
for_each_cea_db(cea, i, start, end) {
db = &cea[i];
dbl = cea_db_payload_len(db);
switch (cea_db_tag(db)) {
int sad_count;
case AUDIO_BLOCK:
sad_count = min(dbl / 3, 15 - total_sad_count);
if (sad_count >= 1)
memcpy(eld + 20 + mnl + total_sad_count * 3,
&db[1], sad_count * 3);
total_sad_count += sad_count;
break;
case SPEAKER_BLOCK:
if (dbl >= 1)
eld[7] = db[1];
break;
case VENDOR_BLOCK:
if (cea_db_is_hdmi_vsdb(db))
drm_parse_hdmi_vsdb_audio(connector, db);
break;
default:
break;
}
}
}
eld[5] |= total_sad_count << 4;
eld[DRM_ELD_BASELINE_ELD_LEN] =
DIV_ROUND_UP(drm_eld_calc_baseline_block_size(eld), 4);
DRM_DEBUG_KMS("ELD size %d, SAD count %d\n",
drm_eld_size(eld), total_sad_count);
}
int drm_edid_to_sad(struct edid *edid, struct cea_sad **sads)
{
int count = 0;
int i, start, end, dbl;
u8 *cea;
cea = drm_find_cea_extension(edid);
if (!cea) {
DRM_DEBUG_KMS("SAD: no CEA Extension found\n");
return -ENOENT;
}
if (cea_revision(cea) < 3) {
DRM_DEBUG_KMS("SAD: wrong CEA revision\n");
return -ENOTSUPP;
}
if (cea_db_offsets(cea, &start, &end)) {
DRM_DEBUG_KMS("SAD: invalid data block offsets\n");
return -EPROTO;
}
for_each_cea_db(cea, i, start, end) {
u8 *db = &cea[i];
if (cea_db_tag(db) == AUDIO_BLOCK) {
int j;
dbl = cea_db_payload_len(db);
count = dbl / 3;
*sads = kcalloc(count, sizeof(**sads), GFP_KERNEL);
if (!*sads)
return -ENOMEM;
for (j = 0; j < count; j++) {
u8 *sad = &db[1 + j * 3];
(*sads)[j].format = (sad[0] & 0x78) >> 3;
(*sads)[j].channels = sad[0] & 0x7;
(*sads)[j].freq = sad[1] & 0x7F;
(*sads)[j].byte2 = sad[2];
}
break;
}
}
return count;
}
int drm_edid_to_speaker_allocation(struct edid *edid, u8 **sadb)
{
int count = 0;
int i, start, end, dbl;
const u8 *cea;
cea = drm_find_cea_extension(edid);
if (!cea) {
DRM_DEBUG_KMS("SAD: no CEA Extension found\n");
return -ENOENT;
}
if (cea_revision(cea) < 3) {
DRM_DEBUG_KMS("SAD: wrong CEA revision\n");
return -ENOTSUPP;
}
if (cea_db_offsets(cea, &start, &end)) {
DRM_DEBUG_KMS("SAD: invalid data block offsets\n");
return -EPROTO;
}
for_each_cea_db(cea, i, start, end) {
const u8 *db = &cea[i];
if (cea_db_tag(db) == SPEAKER_BLOCK) {
dbl = cea_db_payload_len(db);
if (dbl == 3) {
*sadb = kmemdup(&db[1], dbl, GFP_KERNEL);
if (!*sadb)
return -ENOMEM;
count = dbl;
break;
}
}
}
return count;
}
int drm_av_sync_delay(struct drm_connector *connector,
const struct drm_display_mode *mode)
{
int i = !!(mode->flags & DRM_MODE_FLAG_INTERLACE);
int a, v;
if (!connector->latency_present[0])
return 0;
if (!connector->latency_present[1])
i = 0;
a = connector->audio_latency[i];
v = connector->video_latency[i];
if (a == 255 || v == 255)
return 0;
if (a)
a = min(2 * (a - 1), 500);
if (v)
v = min(2 * (v - 1), 500);
return max(v - a, 0);
}
bool drm_detect_hdmi_monitor(struct edid *edid)
{
u8 *edid_ext;
int i;
int start_offset, end_offset;
edid_ext = drm_find_cea_extension(edid);
if (!edid_ext)
return false;
if (cea_db_offsets(edid_ext, &start_offset, &end_offset))
return false;
for_each_cea_db(edid_ext, i, start_offset, end_offset) {
if (cea_db_is_hdmi_vsdb(&edid_ext[i]))
return true;
}
return false;
}
bool drm_detect_monitor_audio(struct edid *edid)
{
u8 *edid_ext;
int i, j;
bool has_audio = false;
int start_offset, end_offset;
edid_ext = drm_find_cea_extension(edid);
if (!edid_ext)
goto end;
has_audio = ((edid_ext[3] & EDID_BASIC_AUDIO) != 0);
if (has_audio) {
DRM_DEBUG_KMS("Monitor has basic audio support\n");
goto end;
}
if (cea_db_offsets(edid_ext, &start_offset, &end_offset))
goto end;
for_each_cea_db(edid_ext, i, start_offset, end_offset) {
if (cea_db_tag(&edid_ext[i]) == AUDIO_BLOCK) {
has_audio = true;
for (j = 1; j < cea_db_payload_len(&edid_ext[i]) + 1; j += 3)
DRM_DEBUG_KMS("CEA audio format %d\n",
(edid_ext[i + j] >> 3) & 0xf);
goto end;
}
}
end:
return has_audio;
}
bool drm_rgb_quant_range_selectable(struct edid *edid)
{
u8 *edid_ext;
int i, start, end;
edid_ext = drm_find_cea_extension(edid);
if (!edid_ext)
return false;
if (cea_db_offsets(edid_ext, &start, &end))
return false;
for_each_cea_db(edid_ext, i, start, end) {
if (cea_db_tag(&edid_ext[i]) == VIDEO_CAPABILITY_BLOCK &&
cea_db_payload_len(&edid_ext[i]) == 2) {
DRM_DEBUG_KMS("CEA VCDB 0x%02x\n", edid_ext[i + 2]);
return edid_ext[i + 2] & EDID_CEA_VCDB_QS;
}
}
return false;
}
enum hdmi_quantization_range
drm_default_rgb_quant_range(const struct drm_display_mode *mode)
{
return drm_match_cea_mode(mode) > 1 ?
HDMI_QUANTIZATION_RANGE_LIMITED :
HDMI_QUANTIZATION_RANGE_FULL;
}
static void drm_parse_hdmi_forum_vsdb(struct drm_connector *connector,
const u8 *hf_vsdb)
{
struct drm_display_info *display = &connector->display_info;
struct drm_hdmi_info *hdmi = &display->hdmi;
if (hf_vsdb[6] & 0x80) {
hdmi->scdc.supported = true;
if (hf_vsdb[6] & 0x40)
hdmi->scdc.read_request = true;
}
if (hf_vsdb[5]) {
u32 max_tmds_clock = hf_vsdb[5] * 5000;
struct drm_scdc *scdc = &hdmi->scdc;
if (max_tmds_clock > 340000) {
display->max_tmds_clock = max_tmds_clock;
DRM_DEBUG_KMS("HF-VSDB: max TMDS clock %d kHz\n",
display->max_tmds_clock);
}
if (scdc->supported) {
scdc->scrambling.supported = true;
if ((hf_vsdb[6] & 0x8))
scdc->scrambling.low_rates = true;
}
}
}
static void drm_parse_hdmi_deep_color_info(struct drm_connector *connector,
const u8 *hdmi)
{
struct drm_display_info *info = &connector->display_info;
unsigned int dc_bpc = 0;
info->bpc = 8;
if (cea_db_payload_len(hdmi) < 6)
return;
if (hdmi[6] & DRM_EDID_HDMI_DC_30) {
dc_bpc = 10;
info->edid_hdmi_dc_modes |= DRM_EDID_HDMI_DC_30;
DRM_DEBUG("%s: HDMI sink does deep color 30.\n",
connector->name);
}
if (hdmi[6] & DRM_EDID_HDMI_DC_36) {
dc_bpc = 12;
info->edid_hdmi_dc_modes |= DRM_EDID_HDMI_DC_36;
DRM_DEBUG("%s: HDMI sink does deep color 36.\n",
connector->name);
}
if (hdmi[6] & DRM_EDID_HDMI_DC_48) {
dc_bpc = 16;
info->edid_hdmi_dc_modes |= DRM_EDID_HDMI_DC_48;
DRM_DEBUG("%s: HDMI sink does deep color 48.\n",
connector->name);
}
if (dc_bpc == 0) {
DRM_DEBUG("%s: No deep color support on this HDMI sink.\n",
connector->name);
return;
}
DRM_DEBUG("%s: Assigning HDMI sink color depth as %d bpc.\n",
connector->name, dc_bpc);
info->bpc = dc_bpc;
info->color_formats = DRM_COLOR_FORMAT_RGB444;
if (hdmi[6] & DRM_EDID_HDMI_DC_Y444) {
info->color_formats |= DRM_COLOR_FORMAT_YCRCB444;
DRM_DEBUG("%s: HDMI sink does YCRCB444 in deep color.\n",
connector->name);
}
if (!(hdmi[6] & DRM_EDID_HDMI_DC_36)) {
DRM_DEBUG("%s: HDMI sink should do DC_36, but does not!\n",
connector->name);
}
}
static void
drm_parse_hdmi_vsdb_video(struct drm_connector *connector, const u8 *db)
{
struct drm_display_info *info = &connector->display_info;
u8 len = cea_db_payload_len(db);
if (len >= 6)
info->dvi_dual = db[6] & 1;
if (len >= 7)
info->max_tmds_clock = db[7] * 5000;
DRM_DEBUG_KMS("HDMI: DVI dual %d, "
"max TMDS clock %d kHz\n",
info->dvi_dual,
info->max_tmds_clock);
drm_parse_hdmi_deep_color_info(connector, db);
}
static void drm_parse_cea_ext(struct drm_connector *connector,
struct edid *edid)
{
struct drm_display_info *info = &connector->display_info;
const u8 *edid_ext;
int i, start, end;
edid_ext = drm_find_cea_extension(edid);
if (!edid_ext)
return;
info->cea_rev = edid_ext[1];
info->color_formats = DRM_COLOR_FORMAT_RGB444;
if (edid_ext[3] & EDID_CEA_YCRCB444)
info->color_formats |= DRM_COLOR_FORMAT_YCRCB444;
if (edid_ext[3] & EDID_CEA_YCRCB422)
info->color_formats |= DRM_COLOR_FORMAT_YCRCB422;
if (cea_db_offsets(edid_ext, &start, &end))
return;
for_each_cea_db(edid_ext, i, start, end) {
const u8 *db = &edid_ext[i];
if (cea_db_is_hdmi_vsdb(db))
drm_parse_hdmi_vsdb_video(connector, db);
if (cea_db_is_hdmi_forum_vsdb(db))
drm_parse_hdmi_forum_vsdb(connector, db);
}
}
static void drm_add_display_info(struct drm_connector *connector,
struct edid *edid)
{
struct drm_display_info *info = &connector->display_info;
info->width_mm = edid->width_cm * 10;
info->height_mm = edid->height_cm * 10;
info->bpc = 0;
info->color_formats = 0;
info->cea_rev = 0;
info->max_tmds_clock = 0;
info->dvi_dual = false;
if (edid->revision < 3)
return;
if (!(edid->input & DRM_EDID_INPUT_DIGITAL))
return;
drm_parse_cea_ext(connector, edid);
if ((info->bpc == 0) && (edid->revision < 4) &&
(edid->input & DRM_EDID_DIGITAL_TYPE_DVI)) {
info->bpc = 8;
DRM_DEBUG("%s: Assigning DFP sink color depth as %d bpc.\n",
connector->name, info->bpc);
}
if (edid->revision < 4)
return;
switch (edid->input & DRM_EDID_DIGITAL_DEPTH_MASK) {
case DRM_EDID_DIGITAL_DEPTH_6:
info->bpc = 6;
break;
case DRM_EDID_DIGITAL_DEPTH_8:
info->bpc = 8;
break;
case DRM_EDID_DIGITAL_DEPTH_10:
info->bpc = 10;
break;
case DRM_EDID_DIGITAL_DEPTH_12:
info->bpc = 12;
break;
case DRM_EDID_DIGITAL_DEPTH_14:
info->bpc = 14;
break;
case DRM_EDID_DIGITAL_DEPTH_16:
info->bpc = 16;
break;
case DRM_EDID_DIGITAL_DEPTH_UNDEF:
default:
info->bpc = 0;
break;
}
DRM_DEBUG("%s: Assigning EDID-1.4 digital sink color depth as %d bpc.\n",
connector->name, info->bpc);
info->color_formats |= DRM_COLOR_FORMAT_RGB444;
if (edid->features & DRM_EDID_FEATURE_RGB_YCRCB444)
info->color_formats |= DRM_COLOR_FORMAT_YCRCB444;
if (edid->features & DRM_EDID_FEATURE_RGB_YCRCB422)
info->color_formats |= DRM_COLOR_FORMAT_YCRCB422;
}
static int validate_displayid(u8 *displayid, int length, int idx)
{
int i;
u8 csum = 0;
struct displayid_hdr *base;
base = (struct displayid_hdr *)&displayid[idx];
DRM_DEBUG_KMS("base revision 0x%x, length %d, %d %d\n",
base->rev, base->bytes, base->prod_id, base->ext_count);
if (base->bytes + 5 > length - idx)
return -EINVAL;
for (i = idx; i <= base->bytes + 5; i++) {
csum += displayid[i];
}
if (csum) {
DRM_NOTE("DisplayID checksum invalid, remainder is %d\n", csum);
return -EINVAL;
}
return 0;
}
static struct drm_display_mode *drm_mode_displayid_detailed(struct drm_device *dev,
struct displayid_detailed_timings_1 *timings)
{
struct drm_display_mode *mode;
unsigned pixel_clock = (timings->pixel_clock[0] |
(timings->pixel_clock[1] << 8) |
(timings->pixel_clock[2] << 16));
unsigned hactive = (timings->hactive[0] | timings->hactive[1] << 8) + 1;
unsigned hblank = (timings->hblank[0] | timings->hblank[1] << 8) + 1;
unsigned hsync = (timings->hsync[0] | (timings->hsync[1] & 0x7f) << 8) + 1;
unsigned hsync_width = (timings->hsw[0] | timings->hsw[1] << 8) + 1;
unsigned vactive = (timings->vactive[0] | timings->vactive[1] << 8) + 1;
unsigned vblank = (timings->vblank[0] | timings->vblank[1] << 8) + 1;
unsigned vsync = (timings->vsync[0] | (timings->vsync[1] & 0x7f) << 8) + 1;
unsigned vsync_width = (timings->vsw[0] | timings->vsw[1] << 8) + 1;
bool hsync_positive = (timings->hsync[1] >> 7) & 0x1;
bool vsync_positive = (timings->vsync[1] >> 7) & 0x1;
mode = drm_mode_create(dev);
if (!mode)
return NULL;
mode->clock = pixel_clock * 10;
mode->hdisplay = hactive;
mode->hsync_start = mode->hdisplay + hsync;
mode->hsync_end = mode->hsync_start + hsync_width;
mode->htotal = mode->hdisplay + hblank;
mode->vdisplay = vactive;
mode->vsync_start = mode->vdisplay + vsync;
mode->vsync_end = mode->vsync_start + vsync_width;
mode->vtotal = mode->vdisplay + vblank;
mode->flags = 0;
mode->flags |= hsync_positive ? DRM_MODE_FLAG_PHSYNC : DRM_MODE_FLAG_NHSYNC;
mode->flags |= vsync_positive ? DRM_MODE_FLAG_PVSYNC : DRM_MODE_FLAG_NVSYNC;
mode->type = DRM_MODE_TYPE_DRIVER;
if (timings->flags & 0x80)
mode->type |= DRM_MODE_TYPE_PREFERRED;
mode->vrefresh = drm_mode_vrefresh(mode);
drm_mode_set_name(mode);
return mode;
}
static int add_displayid_detailed_1_modes(struct drm_connector *connector,
struct displayid_block *block)
{
struct displayid_detailed_timing_block *det = (struct displayid_detailed_timing_block *)block;
int i;
int num_timings;
struct drm_display_mode *newmode;
int num_modes = 0;
if (block->num_bytes % 20)
return 0;
num_timings = block->num_bytes / 20;
for (i = 0; i < num_timings; i++) {
struct displayid_detailed_timings_1 *timings = &det->timings[i];
newmode = drm_mode_displayid_detailed(connector->dev, timings);
if (!newmode)
continue;
drm_mode_probed_add(connector, newmode);
num_modes++;
}
return num_modes;
}
static int add_displayid_detailed_modes(struct drm_connector *connector,
struct edid *edid)
{
u8 *displayid;
int ret;
int idx = 1;
int length = EDID_LENGTH;
struct displayid_block *block;
int num_modes = 0;
displayid = drm_find_displayid_extension(edid);
if (!displayid)
return 0;
ret = validate_displayid(displayid, length, idx);
if (ret)
return 0;
idx += sizeof(struct displayid_hdr);
while (block = (struct displayid_block *)&displayid[idx],
idx + sizeof(struct displayid_block) <= length &&
idx + sizeof(struct displayid_block) + block->num_bytes <= length &&
block->num_bytes > 0) {
idx += block->num_bytes + sizeof(struct displayid_block);
switch (block->tag) {
case DATA_BLOCK_TYPE_1_DETAILED_TIMING:
num_modes += add_displayid_detailed_1_modes(connector, block);
break;
}
}
return num_modes;
}
int drm_add_edid_modes(struct drm_connector *connector, struct edid *edid)
{
int num_modes = 0;
u32 quirks;
if (edid == NULL) {
return 0;
}
if (!drm_edid_is_valid(edid)) {
dev_warn(connector->dev->dev, "%s: EDID invalid.\n",
connector->name);
return 0;
}
quirks = edid_get_quirks(edid);
num_modes += add_detailed_modes(connector, edid, quirks);
num_modes += add_cvt_modes(connector, edid);
num_modes += add_standard_modes(connector, edid);
num_modes += add_established_modes(connector, edid);
num_modes += add_cea_modes(connector, edid);
num_modes += add_alternate_cea_modes(connector, edid);
num_modes += add_displayid_detailed_modes(connector, edid);
if (edid->features & DRM_EDID_FEATURE_DEFAULT_GTF)
num_modes += add_inferred_modes(connector, edid);
if (quirks & (EDID_QUIRK_PREFER_LARGE_60 | EDID_QUIRK_PREFER_LARGE_75))
edid_fixup_preferred(connector, quirks);
drm_add_display_info(connector, edid);
if (quirks & EDID_QUIRK_FORCE_6BPC)
connector->display_info.bpc = 6;
if (quirks & EDID_QUIRK_FORCE_8BPC)
connector->display_info.bpc = 8;
if (quirks & EDID_QUIRK_FORCE_10BPC)
connector->display_info.bpc = 10;
if (quirks & EDID_QUIRK_FORCE_12BPC)
connector->display_info.bpc = 12;
return num_modes;
}
int drm_add_modes_noedid(struct drm_connector *connector,
int hdisplay, int vdisplay)
{
int i, count, num_modes = 0;
struct drm_display_mode *mode;
struct drm_device *dev = connector->dev;
count = ARRAY_SIZE(drm_dmt_modes);
if (hdisplay < 0)
hdisplay = 0;
if (vdisplay < 0)
vdisplay = 0;
for (i = 0; i < count; i++) {
const struct drm_display_mode *ptr = &drm_dmt_modes[i];
if (hdisplay && vdisplay) {
if (ptr->hdisplay > hdisplay ||
ptr->vdisplay > vdisplay)
continue;
}
if (drm_mode_vrefresh(ptr) > 61)
continue;
mode = drm_mode_duplicate(dev, ptr);
if (mode) {
drm_mode_probed_add(connector, mode);
num_modes++;
}
}
return num_modes;
}
void drm_set_preferred_mode(struct drm_connector *connector,
int hpref, int vpref)
{
struct drm_display_mode *mode;
list_for_each_entry(mode, &connector->probed_modes, head) {
if (mode->hdisplay == hpref &&
mode->vdisplay == vpref)
mode->type |= DRM_MODE_TYPE_PREFERRED;
}
}
int
drm_hdmi_avi_infoframe_from_display_mode(struct hdmi_avi_infoframe *frame,
const struct drm_display_mode *mode)
{
int err;
if (!frame || !mode)
return -EINVAL;
err = hdmi_avi_infoframe_init(frame);
if (err < 0)
return err;
if (mode->flags & DRM_MODE_FLAG_DBLCLK)
frame->pixel_repeat = 1;
frame->video_code = drm_match_cea_mode(mode);
frame->picture_aspect = HDMI_PICTURE_ASPECT_NONE;
if (mode->picture_aspect_ratio == HDMI_PICTURE_ASPECT_4_3 ||
mode->picture_aspect_ratio == HDMI_PICTURE_ASPECT_16_9)
frame->picture_aspect = mode->picture_aspect_ratio;
else if (frame->video_code > 0)
frame->picture_aspect = drm_get_cea_aspect_ratio(
frame->video_code);
frame->active_aspect = HDMI_ACTIVE_ASPECT_PICTURE;
frame->scan_mode = HDMI_SCAN_MODE_UNDERSCAN;
return 0;
}
void
drm_hdmi_avi_infoframe_quant_range(struct hdmi_avi_infoframe *frame,
const struct drm_display_mode *mode,
enum hdmi_quantization_range rgb_quant_range,
bool rgb_quant_range_selectable)
{
if (rgb_quant_range_selectable ||
rgb_quant_range == drm_default_rgb_quant_range(mode))
frame->quantization_range = rgb_quant_range;
else
frame->quantization_range = HDMI_QUANTIZATION_RANGE_DEFAULT;
if (rgb_quant_range == HDMI_QUANTIZATION_RANGE_LIMITED)
frame->ycc_quantization_range =
HDMI_YCC_QUANTIZATION_RANGE_LIMITED;
else
frame->ycc_quantization_range =
HDMI_YCC_QUANTIZATION_RANGE_FULL;
}
static enum hdmi_3d_structure
s3d_structure_from_display_mode(const struct drm_display_mode *mode)
{
u32 layout = mode->flags & DRM_MODE_FLAG_3D_MASK;
switch (layout) {
case DRM_MODE_FLAG_3D_FRAME_PACKING:
return HDMI_3D_STRUCTURE_FRAME_PACKING;
case DRM_MODE_FLAG_3D_FIELD_ALTERNATIVE:
return HDMI_3D_STRUCTURE_FIELD_ALTERNATIVE;
case DRM_MODE_FLAG_3D_LINE_ALTERNATIVE:
return HDMI_3D_STRUCTURE_LINE_ALTERNATIVE;
case DRM_MODE_FLAG_3D_SIDE_BY_SIDE_FULL:
return HDMI_3D_STRUCTURE_SIDE_BY_SIDE_FULL;
case DRM_MODE_FLAG_3D_L_DEPTH:
return HDMI_3D_STRUCTURE_L_DEPTH;
case DRM_MODE_FLAG_3D_L_DEPTH_GFX_GFX_DEPTH:
return HDMI_3D_STRUCTURE_L_DEPTH_GFX_GFX_DEPTH;
case DRM_MODE_FLAG_3D_TOP_AND_BOTTOM:
return HDMI_3D_STRUCTURE_TOP_AND_BOTTOM;
case DRM_MODE_FLAG_3D_SIDE_BY_SIDE_HALF:
return HDMI_3D_STRUCTURE_SIDE_BY_SIDE_HALF;
default:
return HDMI_3D_STRUCTURE_INVALID;
}
}
int
drm_hdmi_vendor_infoframe_from_display_mode(struct hdmi_vendor_infoframe *frame,
const struct drm_display_mode *mode)
{
int err;
u32 s3d_flags;
u8 vic;
if (!frame || !mode)
return -EINVAL;
vic = drm_match_hdmi_mode(mode);
s3d_flags = mode->flags & DRM_MODE_FLAG_3D_MASK;
if (!vic && !s3d_flags)
return -EINVAL;
if (vic && s3d_flags)
return -EINVAL;
err = hdmi_vendor_infoframe_init(frame);
if (err < 0)
return err;
if (vic)
frame->vic = vic;
else
frame->s3d_struct = s3d_structure_from_display_mode(mode);
return 0;
}
static int drm_parse_tiled_block(struct drm_connector *connector,
struct displayid_block *block)
{
struct displayid_tiled_block *tile = (struct displayid_tiled_block *)block;
u16 w, h;
u8 tile_v_loc, tile_h_loc;
u8 num_v_tile, num_h_tile;
struct drm_tile_group *tg;
w = tile->tile_size[0] | tile->tile_size[1] << 8;
h = tile->tile_size[2] | tile->tile_size[3] << 8;
num_v_tile = (tile->topo[0] & 0xf) | (tile->topo[2] & 0x30);
num_h_tile = (tile->topo[0] >> 4) | ((tile->topo[2] >> 2) & 0x30);
tile_v_loc = (tile->topo[1] & 0xf) | ((tile->topo[2] & 0x3) << 4);
tile_h_loc = (tile->topo[1] >> 4) | (((tile->topo[2] >> 2) & 0x3) << 4);
connector->has_tile = true;
if (tile->tile_cap & 0x80)
connector->tile_is_single_monitor = true;
connector->num_h_tile = num_h_tile + 1;
connector->num_v_tile = num_v_tile + 1;
connector->tile_h_loc = tile_h_loc;
connector->tile_v_loc = tile_v_loc;
connector->tile_h_size = w + 1;
connector->tile_v_size = h + 1;
DRM_DEBUG_KMS("tile cap 0x%x\n", tile->tile_cap);
DRM_DEBUG_KMS("tile_size %d x %d\n", w + 1, h + 1);
DRM_DEBUG_KMS("topo num tiles %dx%d, location %dx%d\n",
num_h_tile + 1, num_v_tile + 1, tile_h_loc, tile_v_loc);
DRM_DEBUG_KMS("vend %c%c%c\n", tile->topology_id[0], tile->topology_id[1], tile->topology_id[2]);
tg = drm_mode_get_tile_group(connector->dev, tile->topology_id);
if (!tg) {
tg = drm_mode_create_tile_group(connector->dev, tile->topology_id);
}
if (!tg)
return -ENOMEM;
if (connector->tile_group != tg) {
if (connector->tile_group) {
drm_mode_put_tile_group(connector->dev, connector->tile_group);
}
connector->tile_group = tg;
} else
drm_mode_put_tile_group(connector->dev, tg);
return 0;
}
static int drm_parse_display_id(struct drm_connector *connector,
u8 *displayid, int length,
bool is_edid_extension)
{
int idx = 0;
struct displayid_block *block;
int ret;
if (is_edid_extension)
idx = 1;
ret = validate_displayid(displayid, length, idx);
if (ret)
return ret;
idx += sizeof(struct displayid_hdr);
while (block = (struct displayid_block *)&displayid[idx],
idx + sizeof(struct displayid_block) <= length &&
idx + sizeof(struct displayid_block) + block->num_bytes <= length &&
block->num_bytes > 0) {
idx += block->num_bytes + sizeof(struct displayid_block);
DRM_DEBUG_KMS("block id 0x%x, rev %d, len %d\n",
block->tag, block->rev, block->num_bytes);
switch (block->tag) {
case DATA_BLOCK_TILED_DISPLAY:
ret = drm_parse_tiled_block(connector, block);
if (ret)
return ret;
break;
case DATA_BLOCK_TYPE_1_DETAILED_TIMING:
break;
default:
DRM_DEBUG_KMS("found DisplayID tag 0x%x, unhandled\n", block->tag);
break;
}
}
return 0;
}
static void drm_get_displayid(struct drm_connector *connector,
struct edid *edid)
{
void *displayid = NULL;
int ret;
connector->has_tile = false;
displayid = drm_find_displayid_extension(edid);
if (!displayid) {
goto out_drop_ref;
}
ret = drm_parse_display_id(connector, displayid, EDID_LENGTH, true);
if (ret < 0)
goto out_drop_ref;
if (!connector->has_tile)
goto out_drop_ref;
return;
out_drop_ref:
if (connector->tile_group) {
drm_mode_put_tile_group(connector->dev, connector->tile_group);
connector->tile_group = NULL;
}
return;
}
