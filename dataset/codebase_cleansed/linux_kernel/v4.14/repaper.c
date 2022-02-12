static inline struct repaper_epd *
epd_from_tinydrm(struct tinydrm_device *tdev)
{
return container_of(tdev, struct repaper_epd, tinydrm);
}
static int repaper_spi_transfer(struct spi_device *spi, u8 header,
const void *tx, void *rx, size_t len)
{
void *txbuf = NULL, *rxbuf = NULL;
struct spi_transfer tr[2] = {};
u8 *headerbuf;
int ret;
headerbuf = kmalloc(1, GFP_KERNEL);
if (!headerbuf)
return -ENOMEM;
headerbuf[0] = header;
tr[0].tx_buf = headerbuf;
tr[0].len = 1;
if (tx && len <= 32) {
txbuf = kmalloc(len, GFP_KERNEL);
if (!txbuf) {
ret = -ENOMEM;
goto out_free;
}
memcpy(txbuf, tx, len);
}
if (rx) {
rxbuf = kmalloc(len, GFP_KERNEL);
if (!rxbuf) {
ret = -ENOMEM;
goto out_free;
}
}
tr[1].tx_buf = txbuf ? txbuf : tx;
tr[1].rx_buf = rxbuf;
tr[1].len = len;
ndelay(80);
ret = spi_sync_transfer(spi, tr, 2);
if (rx && !ret)
memcpy(rx, rxbuf, len);
out_free:
kfree(headerbuf);
kfree(txbuf);
kfree(rxbuf);
return ret;
}
static int repaper_write_buf(struct spi_device *spi, u8 reg,
const u8 *buf, size_t len)
{
int ret;
ret = repaper_spi_transfer(spi, 0x70, &reg, NULL, 1);
if (ret)
return ret;
return repaper_spi_transfer(spi, 0x72, buf, NULL, len);
}
static int repaper_write_val(struct spi_device *spi, u8 reg, u8 val)
{
return repaper_write_buf(spi, reg, &val, 1);
}
static int repaper_read_val(struct spi_device *spi, u8 reg)
{
int ret;
u8 val;
ret = repaper_spi_transfer(spi, 0x70, &reg, NULL, 1);
if (ret)
return ret;
ret = repaper_spi_transfer(spi, 0x73, NULL, &val, 1);
return ret ? ret : val;
}
static int repaper_read_id(struct spi_device *spi)
{
int ret;
u8 id;
ret = repaper_spi_transfer(spi, 0x71, NULL, &id, 1);
return ret ? ret : id;
}
static void repaper_spi_mosi_low(struct spi_device *spi)
{
const u8 buf[1] = { 0 };
spi_write(spi, buf, 1);
}
static void repaper_even_pixels(struct repaper_epd *epd, u8 **pp,
const u8 *data, u8 fixed_value, const u8 *mask,
enum repaper_stage stage)
{
unsigned int b;
for (b = 0; b < (epd->width / 8); b++) {
if (data) {
u8 pixels = data[b] & 0xaa;
u8 pixel_mask = 0xff;
u8 p1, p2, p3, p4;
if (mask) {
pixel_mask = (mask[b] ^ pixels) & 0xaa;
pixel_mask |= pixel_mask >> 1;
}
switch (stage) {
case REPAPER_COMPENSATE:
pixels = 0xaa | ((pixels ^ 0xaa) >> 1);
break;
case REPAPER_WHITE:
pixels = 0x55 + ((pixels ^ 0xaa) >> 1);
break;
case REPAPER_INVERSE:
pixels = 0x55 | (pixels ^ 0xaa);
break;
case REPAPER_NORMAL:
pixels = 0xaa | (pixels >> 1);
break;
}
pixels = (pixels & pixel_mask) | (~pixel_mask & 0x55);
p1 = (pixels >> 6) & 0x03;
p2 = (pixels >> 4) & 0x03;
p3 = (pixels >> 2) & 0x03;
p4 = (pixels >> 0) & 0x03;
pixels = (p1 << 0) | (p2 << 2) | (p3 << 4) | (p4 << 6);
*(*pp)++ = pixels;
} else {
*(*pp)++ = fixed_value;
}
}
}
static void repaper_odd_pixels(struct repaper_epd *epd, u8 **pp,
const u8 *data, u8 fixed_value, const u8 *mask,
enum repaper_stage stage)
{
unsigned int b;
for (b = epd->width / 8; b > 0; b--) {
if (data) {
u8 pixels = data[b - 1] & 0x55;
u8 pixel_mask = 0xff;
if (mask) {
pixel_mask = (mask[b - 1] ^ pixels) & 0x55;
pixel_mask |= pixel_mask << 1;
}
switch (stage) {
case REPAPER_COMPENSATE:
pixels = 0xaa | (pixels ^ 0x55);
break;
case REPAPER_WHITE:
pixels = 0x55 + (pixels ^ 0x55);
break;
case REPAPER_INVERSE:
pixels = 0x55 | ((pixels ^ 0x55) << 1);
break;
case REPAPER_NORMAL:
pixels = 0xaa | pixels;
break;
}
pixels = (pixels & pixel_mask) | (~pixel_mask & 0x55);
*(*pp)++ = pixels;
} else {
*(*pp)++ = fixed_value;
}
}
}
static inline u16 repaper_interleave_bits(u16 value)
{
value = (value | (value << 4)) & 0x0f0f;
value = (value | (value << 2)) & 0x3333;
value = (value | (value << 1)) & 0x5555;
return value;
}
static void repaper_all_pixels(struct repaper_epd *epd, u8 **pp,
const u8 *data, u8 fixed_value, const u8 *mask,
enum repaper_stage stage)
{
unsigned int b;
for (b = epd->width / 8; b > 0; b--) {
if (data) {
u16 pixels = repaper_interleave_bits(data[b - 1]);
u16 pixel_mask = 0xffff;
if (mask) {
pixel_mask = repaper_interleave_bits(mask[b - 1]);
pixel_mask = (pixel_mask ^ pixels) & 0x5555;
pixel_mask |= pixel_mask << 1;
}
switch (stage) {
case REPAPER_COMPENSATE:
pixels = 0xaaaa | (pixels ^ 0x5555);
break;
case REPAPER_WHITE:
pixels = 0x5555 + (pixels ^ 0x5555);
break;
case REPAPER_INVERSE:
pixels = 0x5555 | ((pixels ^ 0x5555) << 1);
break;
case REPAPER_NORMAL:
pixels = 0xaaaa | pixels;
break;
}
pixels = (pixels & pixel_mask) | (~pixel_mask & 0x5555);
*(*pp)++ = pixels >> 8;
*(*pp)++ = pixels;
} else {
*(*pp)++ = fixed_value;
*(*pp)++ = fixed_value;
}
}
}
static void repaper_one_line(struct repaper_epd *epd, unsigned int line,
const u8 *data, u8 fixed_value, const u8 *mask,
enum repaper_stage stage)
{
u8 *p = epd->line_buffer;
unsigned int b;
repaper_spi_mosi_low(epd->spi);
if (epd->pre_border_byte)
*p++ = 0x00;
if (epd->middle_scan) {
repaper_odd_pixels(epd, &p, data, fixed_value, mask, stage);
for (b = epd->bytes_per_scan; b > 0; b--) {
if (line / 4 == b - 1)
*p++ = 0x03 << (2 * (line & 0x03));
else
*p++ = 0x00;
}
repaper_even_pixels(epd, &p, data, fixed_value, mask, stage);
} else {
for (b = 0; b < epd->bytes_per_scan; b++) {
if (0 != (line & 0x01) && line / 8 == b)
*p++ = 0xc0 >> (line & 0x06);
else
*p++ = 0x00;
}
repaper_all_pixels(epd, &p, data, fixed_value, mask, stage);
for (b = epd->bytes_per_scan; b > 0; b--) {
if (0 == (line & 0x01) && line / 8 == b - 1)
*p++ = 0x03 << (line & 0x06);
else
*p++ = 0x00;
}
}
switch (epd->border_byte) {
case REPAPER_BORDER_BYTE_NONE:
break;
case REPAPER_BORDER_BYTE_ZERO:
*p++ = 0x00;
break;
case REPAPER_BORDER_BYTE_SET:
switch (stage) {
case REPAPER_COMPENSATE:
case REPAPER_WHITE:
case REPAPER_INVERSE:
*p++ = 0x00;
break;
case REPAPER_NORMAL:
*p++ = 0xaa;
break;
}
break;
}
repaper_write_buf(epd->spi, 0x0a, epd->line_buffer,
p - epd->line_buffer);
repaper_write_val(epd->spi, 0x02, 0x07);
repaper_spi_mosi_low(epd->spi);
}
static void repaper_frame_fixed(struct repaper_epd *epd, u8 fixed_value,
enum repaper_stage stage)
{
unsigned int line;
for (line = 0; line < epd->height; line++)
repaper_one_line(epd, line, NULL, fixed_value, NULL, stage);
}
static void repaper_frame_data(struct repaper_epd *epd, const u8 *image,
const u8 *mask, enum repaper_stage stage)
{
unsigned int line;
if (!mask) {
for (line = 0; line < epd->height; line++) {
repaper_one_line(epd, line,
&image[line * (epd->width / 8)],
0, NULL, stage);
}
} else {
for (line = 0; line < epd->height; line++) {
size_t n = line * epd->width / 8;
repaper_one_line(epd, line, &image[n], 0, &mask[n],
stage);
}
}
}
static void repaper_frame_fixed_repeat(struct repaper_epd *epd, u8 fixed_value,
enum repaper_stage stage)
{
u64 start = local_clock();
u64 end = start + (epd->factored_stage_time * 1000 * 1000);
do {
repaper_frame_fixed(epd, fixed_value, stage);
} while (local_clock() < end);
}
static void repaper_frame_data_repeat(struct repaper_epd *epd, const u8 *image,
const u8 *mask, enum repaper_stage stage)
{
u64 start = local_clock();
u64 end = start + (epd->factored_stage_time * 1000 * 1000);
do {
repaper_frame_data(epd, image, mask, stage);
} while (local_clock() < end);
}
static void repaper_get_temperature(struct repaper_epd *epd)
{
int ret, temperature = 0;
unsigned int factor10x;
if (!epd->thermal)
return;
ret = thermal_zone_get_temp(epd->thermal, &temperature);
if (ret) {
dev_err(&epd->spi->dev, "Failed to get temperature (%d)\n",
ret);
return;
}
temperature /= 1000;
if (temperature <= -10)
factor10x = 170;
else if (temperature <= -5)
factor10x = 120;
else if (temperature <= 5)
factor10x = 80;
else if (temperature <= 10)
factor10x = 40;
else if (temperature <= 15)
factor10x = 30;
else if (temperature <= 20)
factor10x = 20;
else if (temperature <= 40)
factor10x = 10;
else
factor10x = 7;
epd->factored_stage_time = epd->stage_time * factor10x / 10;
}
static void repaper_gray8_to_mono_reversed(u8 *buf, u32 width, u32 height)
{
u8 *gray8 = buf, *mono = buf;
int y, xb, i;
for (y = 0; y < height; y++)
for (xb = 0; xb < width / 8; xb++) {
u8 byte = 0x00;
for (i = 0; i < 8; i++) {
int x = xb * 8 + i;
byte >>= 1;
if (gray8[y * width + x] >> 7)
byte |= BIT(7);
}
*mono++ = byte;
}
}
static int repaper_fb_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int flags, unsigned int color,
struct drm_clip_rect *clips,
unsigned int num_clips)
{
struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
struct dma_buf_attachment *import_attach = cma_obj->base.import_attach;
struct tinydrm_device *tdev = fb->dev->dev_private;
struct repaper_epd *epd = epd_from_tinydrm(tdev);
struct drm_clip_rect clip;
u8 *buf = NULL;
int ret = 0;
clip.x1 = 0;
clip.x2 = fb->width;
clip.y1 = 0;
clip.y2 = fb->height;
mutex_lock(&tdev->dirty_lock);
if (!epd->enabled)
goto out_unlock;
if (tdev->pipe.plane.fb != fb)
goto out_unlock;
repaper_get_temperature(epd);
DRM_DEBUG("Flushing [FB:%d] st=%ums\n", fb->base.id,
epd->factored_stage_time);
buf = kmalloc(fb->width * fb->height, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto out_unlock;
}
if (import_attach) {
ret = dma_buf_begin_cpu_access(import_attach->dmabuf,
DMA_FROM_DEVICE);
if (ret)
goto out_unlock;
}
tinydrm_xrgb8888_to_gray8(buf, cma_obj->vaddr, fb, &clip);
if (import_attach) {
ret = dma_buf_end_cpu_access(import_attach->dmabuf,
DMA_FROM_DEVICE);
if (ret)
goto out_unlock;
}
repaper_gray8_to_mono_reversed(buf, fb->width, fb->height);
if (epd->partial) {
repaper_frame_data_repeat(epd, buf, epd->current_frame,
REPAPER_NORMAL);
} else if (epd->cleared) {
repaper_frame_data_repeat(epd, epd->current_frame, NULL,
REPAPER_COMPENSATE);
repaper_frame_data_repeat(epd, epd->current_frame, NULL,
REPAPER_WHITE);
repaper_frame_data_repeat(epd, buf, NULL, REPAPER_INVERSE);
repaper_frame_data_repeat(epd, buf, NULL, REPAPER_NORMAL);
epd->partial = true;
} else {
repaper_frame_fixed_repeat(epd, 0xff, REPAPER_COMPENSATE);
repaper_frame_fixed_repeat(epd, 0xff, REPAPER_WHITE);
repaper_frame_fixed_repeat(epd, 0xaa, REPAPER_INVERSE);
repaper_frame_fixed_repeat(epd, 0xaa, REPAPER_NORMAL);
repaper_frame_fixed_repeat(epd, 0xaa, REPAPER_COMPENSATE);
repaper_frame_fixed_repeat(epd, 0xaa, REPAPER_WHITE);
repaper_frame_data_repeat(epd, buf, NULL, REPAPER_INVERSE);
repaper_frame_data_repeat(epd, buf, NULL, REPAPER_NORMAL);
epd->cleared = true;
epd->partial = true;
}
memcpy(epd->current_frame, buf, fb->width * fb->height / 8);
if (epd->pre_border_byte) {
unsigned int x;
for (x = 0; x < (fb->width / 8); x++)
if (buf[x + (fb->width * (fb->height - 1) / 8)]) {
repaper_frame_data_repeat(epd, buf,
epd->current_frame,
REPAPER_NORMAL);
break;
}
}
out_unlock:
mutex_unlock(&tdev->dirty_lock);
if (ret)
dev_err(fb->dev->dev, "Failed to update display (%d)\n", ret);
kfree(buf);
return ret;
}
static void power_off(struct repaper_epd *epd)
{
gpiod_set_value_cansleep(epd->reset, 0);
gpiod_set_value_cansleep(epd->panel_on, 0);
if (epd->border)
gpiod_set_value_cansleep(epd->border, 0);
repaper_spi_mosi_low(epd->spi);
gpiod_set_value_cansleep(epd->discharge, 1);
msleep(150);
gpiod_set_value_cansleep(epd->discharge, 0);
}
static void repaper_pipe_enable(struct drm_simple_display_pipe *pipe,
struct drm_crtc_state *crtc_state)
{
struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
struct repaper_epd *epd = epd_from_tinydrm(tdev);
struct spi_device *spi = epd->spi;
struct device *dev = &spi->dev;
bool dc_ok = false;
int i, ret;
DRM_DEBUG_DRIVER("\n");
gpiod_set_value_cansleep(epd->reset, 0);
gpiod_set_value_cansleep(epd->panel_on, 0);
gpiod_set_value_cansleep(epd->discharge, 0);
if (epd->border)
gpiod_set_value_cansleep(epd->border, 0);
repaper_spi_mosi_low(spi);
usleep_range(5000, 10000);
gpiod_set_value_cansleep(epd->panel_on, 1);
usleep_range(10000, 15000);
gpiod_set_value_cansleep(epd->reset, 1);
if (epd->border)
gpiod_set_value_cansleep(epd->border, 1);
usleep_range(5000, 10000);
gpiod_set_value_cansleep(epd->reset, 0);
usleep_range(5000, 10000);
gpiod_set_value_cansleep(epd->reset, 1);
usleep_range(5000, 10000);
for (i = 100; i > 0; i--) {
if (!gpiod_get_value_cansleep(epd->busy))
break;
usleep_range(10, 100);
}
if (!i) {
dev_err(dev, "timeout waiting for panel to become ready.\n");
power_off(epd);
return;
}
repaper_read_id(spi);
ret = repaper_read_id(spi);
if (ret != REPAPER_RID_G2_COG_ID) {
if (ret < 0)
dev_err(dev, "failed to read chip (%d)\n", ret);
else
dev_err(dev, "wrong COG ID 0x%02x\n", ret);
power_off(epd);
return;
}
repaper_write_val(spi, 0x02, 0x40);
ret = repaper_read_val(spi, 0x0f);
if (ret < 0 || !(ret & 0x80)) {
if (ret < 0)
dev_err(dev, "failed to read chip (%d)\n", ret);
else
dev_err(dev, "panel is reported broken\n");
power_off(epd);
return;
}
repaper_write_val(spi, 0x0b, 0x02);
repaper_write_buf(spi, 0x01, epd->channel_select, 8);
repaper_write_val(spi, 0x07, 0xd1);
repaper_write_val(spi, 0x08, 0x02);
repaper_write_val(spi, 0x09, 0xc2);
repaper_write_val(spi, 0x04, 0x03);
repaper_write_val(spi, 0x03, 0x01);
repaper_write_val(spi, 0x03, 0x00);
usleep_range(5000, 10000);
for (i = 0; i < 4; ++i) {
repaper_write_val(spi, 0x05, 0x01);
msleep(240);
repaper_write_val(spi, 0x05, 0x03);
msleep(40);
repaper_write_val(spi, 0x05, 0x0f);
msleep(40);
ret = repaper_read_val(spi, 0x0f);
if (ret < 0) {
dev_err(dev, "failed to read chip (%d)\n", ret);
power_off(epd);
return;
}
if (ret & 0x40) {
dc_ok = true;
break;
}
}
if (!dc_ok) {
dev_err(dev, "dc/dc failed\n");
power_off(epd);
return;
}
repaper_write_val(spi, 0x02, 0x04);
epd->enabled = true;
epd->partial = false;
}
static void repaper_pipe_disable(struct drm_simple_display_pipe *pipe)
{
struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
struct repaper_epd *epd = epd_from_tinydrm(tdev);
struct spi_device *spi = epd->spi;
unsigned int line;
DRM_DEBUG_DRIVER("\n");
mutex_lock(&tdev->dirty_lock);
epd->enabled = false;
mutex_unlock(&tdev->dirty_lock);
for (line = 0; line < epd->height; line++)
repaper_one_line(epd, 0x7fffu, NULL, 0x00, NULL,
REPAPER_COMPENSATE);
if (epd->border) {
repaper_one_line(epd, 0x7fffu, NULL, 0x00, NULL,
REPAPER_COMPENSATE);
msleep(25);
gpiod_set_value_cansleep(epd->border, 0);
msleep(200);
gpiod_set_value_cansleep(epd->border, 1);
} else {
repaper_one_line(epd, 0x7fffu, NULL, 0x00, NULL,
REPAPER_NORMAL);
msleep(200);
}
repaper_write_val(spi, 0x0b, 0x00);
repaper_write_val(spi, 0x03, 0x01);
repaper_write_val(spi, 0x05, 0x03);
repaper_write_val(spi, 0x05, 0x01);
msleep(120);
repaper_write_val(spi, 0x04, 0x80);
repaper_write_val(spi, 0x05, 0x00);
repaper_write_val(spi, 0x07, 0x01);
msleep(50);
power_off(epd);
}
static int repaper_probe(struct spi_device *spi)
{
const struct drm_display_mode *mode;
const struct spi_device_id *spi_id;
const struct of_device_id *match;
struct device *dev = &spi->dev;
struct tinydrm_device *tdev;
enum repaper_model model;
const char *thermal_zone;
struct repaper_epd *epd;
size_t line_buffer_size;
int ret;
match = of_match_device(repaper_of_match, dev);
if (match) {
model = (enum repaper_model)match->data;
} else {
spi_id = spi_get_device_id(spi);
model = spi_id->driver_data;
}
if (!dev->coherent_dma_mask) {
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret) {
dev_warn(dev, "Failed to set dma mask %d\n", ret);
return ret;
}
}
epd = devm_kzalloc(dev, sizeof(*epd), GFP_KERNEL);
if (!epd)
return -ENOMEM;
epd->spi = spi;
epd->panel_on = devm_gpiod_get(dev, "panel-on", GPIOD_OUT_LOW);
if (IS_ERR(epd->panel_on)) {
ret = PTR_ERR(epd->panel_on);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get gpio 'panel-on'\n");
return ret;
}
epd->discharge = devm_gpiod_get(dev, "discharge", GPIOD_OUT_LOW);
if (IS_ERR(epd->discharge)) {
ret = PTR_ERR(epd->discharge);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get gpio 'discharge'\n");
return ret;
}
epd->reset = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(epd->reset)) {
ret = PTR_ERR(epd->reset);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get gpio 'reset'\n");
return ret;
}
epd->busy = devm_gpiod_get(dev, "busy", GPIOD_IN);
if (IS_ERR(epd->busy)) {
ret = PTR_ERR(epd->busy);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get gpio 'busy'\n");
return ret;
}
if (!device_property_read_string(dev, "pervasive,thermal-zone",
&thermal_zone)) {
epd->thermal = thermal_zone_get_zone_by_name(thermal_zone);
if (IS_ERR(epd->thermal)) {
dev_err(dev, "Failed to get thermal zone: %s\n",
thermal_zone);
return PTR_ERR(epd->thermal);
}
}
switch (model) {
case E1144CS021:
mode = &repaper_e1144cs021_mode;
epd->channel_select = repaper_e1144cs021_cs;
epd->stage_time = 480;
epd->bytes_per_scan = 96 / 4;
epd->middle_scan = true;
epd->pre_border_byte = false;
epd->border_byte = REPAPER_BORDER_BYTE_ZERO;
break;
case E1190CS021:
mode = &repaper_e1190cs021_mode;
epd->channel_select = repaper_e1190cs021_cs;
epd->stage_time = 480;
epd->bytes_per_scan = 128 / 4 / 2;
epd->middle_scan = false;
epd->pre_border_byte = false;
epd->border_byte = REPAPER_BORDER_BYTE_SET;
break;
case E2200CS021:
mode = &repaper_e2200cs021_mode;
epd->channel_select = repaper_e2200cs021_cs;
epd->stage_time = 480;
epd->bytes_per_scan = 96 / 4;
epd->middle_scan = true;
epd->pre_border_byte = true;
epd->border_byte = REPAPER_BORDER_BYTE_NONE;
break;
case E2271CS021:
epd->border = devm_gpiod_get(dev, "border", GPIOD_OUT_LOW);
if (IS_ERR(epd->border)) {
ret = PTR_ERR(epd->border);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get gpio 'border'\n");
return ret;
}
mode = &repaper_e2271cs021_mode;
epd->channel_select = repaper_e2271cs021_cs;
epd->stage_time = 630;
epd->bytes_per_scan = 176 / 4;
epd->middle_scan = true;
epd->pre_border_byte = true;
epd->border_byte = REPAPER_BORDER_BYTE_NONE;
break;
default:
return -ENODEV;
}
epd->width = mode->hdisplay;
epd->height = mode->vdisplay;
epd->factored_stage_time = epd->stage_time;
line_buffer_size = 2 * epd->width / 8 + epd->bytes_per_scan + 2;
epd->line_buffer = devm_kzalloc(dev, line_buffer_size, GFP_KERNEL);
if (!epd->line_buffer)
return -ENOMEM;
epd->current_frame = devm_kzalloc(dev, epd->width * epd->height / 8,
GFP_KERNEL);
if (!epd->current_frame)
return -ENOMEM;
tdev = &epd->tinydrm;
ret = devm_tinydrm_init(dev, tdev, &repaper_fb_funcs, &repaper_driver);
if (ret)
return ret;
ret = tinydrm_display_pipe_init(tdev, &repaper_pipe_funcs,
DRM_MODE_CONNECTOR_VIRTUAL,
repaper_formats,
ARRAY_SIZE(repaper_formats), mode, 0);
if (ret)
return ret;
drm_mode_config_reset(tdev->drm);
ret = devm_tinydrm_register(tdev);
if (ret)
return ret;
spi_set_drvdata(spi, tdev);
DRM_DEBUG_DRIVER("Initialized %s:%s @%uMHz on minor %d\n",
tdev->drm->driver->name, dev_name(dev),
spi->max_speed_hz / 1000000,
tdev->drm->primary->index);
return 0;
}
static void repaper_shutdown(struct spi_device *spi)
{
struct tinydrm_device *tdev = spi_get_drvdata(spi);
tinydrm_shutdown(tdev);
}
