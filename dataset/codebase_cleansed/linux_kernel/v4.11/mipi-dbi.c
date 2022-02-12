static bool mipi_dbi_command_is_read(struct mipi_dbi *mipi, u8 cmd)
{
unsigned int i;
if (!mipi->read_commands)
return false;
for (i = 0; i < 0xff; i++) {
if (!mipi->read_commands[i])
return false;
if (cmd == mipi->read_commands[i])
return true;
}
return false;
}
int mipi_dbi_command_read(struct mipi_dbi *mipi, u8 cmd, u8 *val)
{
if (!mipi->read_commands)
return -EACCES;
if (!mipi_dbi_command_is_read(mipi, cmd))
return -EINVAL;
return mipi_dbi_command_buf(mipi, cmd, val, 1);
}
int mipi_dbi_command_buf(struct mipi_dbi *mipi, u8 cmd, u8 *data, size_t len)
{
int ret;
mutex_lock(&mipi->cmdlock);
ret = mipi->command(mipi, cmd, data, len);
mutex_unlock(&mipi->cmdlock);
return ret;
}
static int mipi_dbi_buf_copy(void *dst, struct drm_framebuffer *fb,
struct drm_clip_rect *clip, bool swap)
{
struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
struct dma_buf_attachment *import_attach = cma_obj->base.import_attach;
struct drm_format_name_buf format_name;
void *src = cma_obj->vaddr;
int ret = 0;
if (import_attach) {
ret = dma_buf_begin_cpu_access(import_attach->dmabuf,
DMA_FROM_DEVICE);
if (ret)
return ret;
}
switch (fb->format->format) {
case DRM_FORMAT_RGB565:
if (swap)
tinydrm_swab16(dst, src, fb, clip);
else
tinydrm_memcpy(dst, src, fb, clip);
break;
case DRM_FORMAT_XRGB8888:
tinydrm_xrgb8888_to_rgb565(dst, src, fb, clip, swap);
break;
default:
dev_err_once(fb->dev->dev, "Format is not supported: %s\n",
drm_get_format_name(fb->format->format,
&format_name));
return -EINVAL;
}
if (import_attach)
ret = dma_buf_end_cpu_access(import_attach->dmabuf,
DMA_FROM_DEVICE);
return ret;
}
static int mipi_dbi_fb_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int flags, unsigned int color,
struct drm_clip_rect *clips,
unsigned int num_clips)
{
struct drm_gem_cma_object *cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
struct tinydrm_device *tdev = fb->dev->dev_private;
struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
bool swap = mipi->swap_bytes;
struct drm_clip_rect clip;
int ret = 0;
bool full;
void *tr;
mutex_lock(&tdev->dirty_lock);
if (!mipi->enabled)
goto out_unlock;
if (tdev->pipe.plane.fb != fb)
goto out_unlock;
full = tinydrm_merge_clips(&clip, clips, num_clips, flags,
fb->width, fb->height);
DRM_DEBUG("Flushing [FB:%d] x1=%u, x2=%u, y1=%u, y2=%u\n", fb->base.id,
clip.x1, clip.x2, clip.y1, clip.y2);
if (!mipi->dc || !full || swap ||
fb->format->format == DRM_FORMAT_XRGB8888) {
tr = mipi->tx_buf;
ret = mipi_dbi_buf_copy(mipi->tx_buf, fb, &clip, swap);
if (ret)
goto out_unlock;
} else {
tr = cma_obj->vaddr;
}
mipi_dbi_command(mipi, MIPI_DCS_SET_COLUMN_ADDRESS,
(clip.x1 >> 8) & 0xFF, clip.x1 & 0xFF,
(clip.x2 >> 8) & 0xFF, (clip.x2 - 1) & 0xFF);
mipi_dbi_command(mipi, MIPI_DCS_SET_PAGE_ADDRESS,
(clip.y1 >> 8) & 0xFF, clip.y1 & 0xFF,
(clip.y2 >> 8) & 0xFF, (clip.y2 - 1) & 0xFF);
ret = mipi_dbi_command_buf(mipi, MIPI_DCS_WRITE_MEMORY_START, tr,
(clip.x2 - clip.x1) * (clip.y2 - clip.y1) * 2);
out_unlock:
mutex_unlock(&tdev->dirty_lock);
if (ret)
dev_err_once(fb->dev->dev, "Failed to update display %d\n",
ret);
return ret;
}
void mipi_dbi_pipe_enable(struct drm_simple_display_pipe *pipe,
struct drm_crtc_state *crtc_state)
{
struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
struct drm_framebuffer *fb = pipe->plane.fb;
DRM_DEBUG_KMS("\n");
mipi->enabled = true;
if (fb)
fb->funcs->dirty(fb, NULL, 0, 0, NULL, 0);
tinydrm_enable_backlight(mipi->backlight);
}
static void mipi_dbi_blank(struct mipi_dbi *mipi)
{
struct drm_device *drm = mipi->tinydrm.drm;
u16 height = drm->mode_config.min_height;
u16 width = drm->mode_config.min_width;
size_t len = width * height * 2;
memset(mipi->tx_buf, 0, len);
mipi_dbi_command(mipi, MIPI_DCS_SET_COLUMN_ADDRESS, 0, 0,
(width >> 8) & 0xFF, (width - 1) & 0xFF);
mipi_dbi_command(mipi, MIPI_DCS_SET_PAGE_ADDRESS, 0, 0,
(height >> 8) & 0xFF, (height - 1) & 0xFF);
mipi_dbi_command_buf(mipi, MIPI_DCS_WRITE_MEMORY_START,
(u8 *)mipi->tx_buf, len);
}
void mipi_dbi_pipe_disable(struct drm_simple_display_pipe *pipe)
{
struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
DRM_DEBUG_KMS("\n");
mipi->enabled = false;
if (mipi->backlight)
tinydrm_disable_backlight(mipi->backlight);
else
mipi_dbi_blank(mipi);
}
int mipi_dbi_init(struct device *dev, struct mipi_dbi *mipi,
const struct drm_simple_display_pipe_funcs *pipe_funcs,
struct drm_driver *driver,
const struct drm_display_mode *mode, unsigned int rotation)
{
size_t bufsize = mode->vdisplay * mode->hdisplay * sizeof(u16);
struct tinydrm_device *tdev = &mipi->tinydrm;
int ret;
if (!mipi->command)
return -EINVAL;
mutex_init(&mipi->cmdlock);
mipi->tx_buf = devm_kmalloc(dev, bufsize, GFP_KERNEL);
if (!mipi->tx_buf)
return -ENOMEM;
ret = devm_tinydrm_init(dev, tdev, &mipi_dbi_fb_funcs, driver);
if (ret)
return ret;
ret = tinydrm_display_pipe_init(tdev, pipe_funcs,
DRM_MODE_CONNECTOR_VIRTUAL,
mipi_dbi_formats,
ARRAY_SIZE(mipi_dbi_formats), mode,
rotation);
if (ret)
return ret;
tdev->drm->mode_config.preferred_depth = 16;
mipi->rotation = rotation;
drm_mode_config_reset(tdev->drm);
DRM_DEBUG_KMS("preferred_depth=%u, rotation = %u\n",
tdev->drm->mode_config.preferred_depth, rotation);
return 0;
}
void mipi_dbi_hw_reset(struct mipi_dbi *mipi)
{
if (!mipi->reset)
return;
gpiod_set_value_cansleep(mipi->reset, 0);
msleep(20);
gpiod_set_value_cansleep(mipi->reset, 1);
msleep(120);
}
bool mipi_dbi_display_is_on(struct mipi_dbi *mipi)
{
u8 val;
if (mipi_dbi_command_read(mipi, MIPI_DCS_GET_POWER_MODE, &val))
return false;
val &= ~DCS_POWER_MODE_RESERVED_MASK;
if (val != (DCS_POWER_MODE_DISPLAY |
DCS_POWER_MODE_DISPLAY_NORMAL_MODE | DCS_POWER_MODE_SLEEP_MODE))
return false;
DRM_DEBUG_DRIVER("Display is ON\n");
return true;
}
static u32 mipi_dbi_spi_cmd_max_speed(struct spi_device *spi, size_t len)
{
if (len > 64)
return 0;
return min_t(u32, 10000000, spi->max_speed_hz);
}
static int mipi_dbi_spi1e_transfer(struct mipi_dbi *mipi, int dc,
const void *buf, size_t len,
unsigned int bpw)
{
bool swap_bytes = (bpw == 16 && tinydrm_machine_little_endian());
size_t chunk, max_chunk = mipi->tx_buf9_len;
struct spi_device *spi = mipi->spi;
struct spi_transfer tr = {
.tx_buf = mipi->tx_buf9,
.bits_per_word = 8,
};
struct spi_message m;
const u8 *src = buf;
int i, ret;
u8 *dst;
if (drm_debug & DRM_UT_DRIVER)
pr_debug("[drm:%s] dc=%d, max_chunk=%zu, transfers:\n",
__func__, dc, max_chunk);
tr.speed_hz = mipi_dbi_spi_cmd_max_speed(spi, len);
spi_message_init_with_transfers(&m, &tr, 1);
if (!dc) {
if (WARN_ON_ONCE(len != 1))
return -EINVAL;
dst = mipi->tx_buf9;
memset(dst, 0, 9);
dst[8] = *src;
tr.len = 9;
tinydrm_dbg_spi_message(spi, &m);
return spi_sync(spi, &m);
}
max_chunk = max_chunk / 9 * 8;
max_chunk = min(max_chunk, len);
max_chunk = max_t(size_t, 8, max_chunk & ~0x7);
while (len) {
size_t added = 0;
chunk = min(len, max_chunk);
len -= chunk;
dst = mipi->tx_buf9;
if (chunk < 8) {
u8 val, carry = 0;
memset(dst, 0, 9);
if (swap_bytes) {
for (i = 1; i < (chunk + 1); i++) {
val = src[1];
*dst++ = carry | BIT(8 - i) | (val >> i);
carry = val << (8 - i);
i++;
val = src[0];
*dst++ = carry | BIT(8 - i) | (val >> i);
carry = val << (8 - i);
src += 2;
}
*dst++ = carry;
} else {
for (i = 1; i < (chunk + 1); i++) {
val = *src++;
*dst++ = carry | BIT(8 - i) | (val >> i);
carry = val << (8 - i);
}
*dst++ = carry;
}
chunk = 8;
added = 1;
} else {
for (i = 0; i < chunk; i += 8) {
if (swap_bytes) {
*dst++ = BIT(7) | (src[1] >> 1);
*dst++ = (src[1] << 7) | BIT(6) | (src[0] >> 2);
*dst++ = (src[0] << 6) | BIT(5) | (src[3] >> 3);
*dst++ = (src[3] << 5) | BIT(4) | (src[2] >> 4);
*dst++ = (src[2] << 4) | BIT(3) | (src[5] >> 5);
*dst++ = (src[5] << 3) | BIT(2) | (src[4] >> 6);
*dst++ = (src[4] << 2) | BIT(1) | (src[7] >> 7);
*dst++ = (src[7] << 1) | BIT(0);
*dst++ = src[6];
} else {
*dst++ = BIT(7) | (src[0] >> 1);
*dst++ = (src[0] << 7) | BIT(6) | (src[1] >> 2);
*dst++ = (src[1] << 6) | BIT(5) | (src[2] >> 3);
*dst++ = (src[2] << 5) | BIT(4) | (src[3] >> 4);
*dst++ = (src[3] << 4) | BIT(3) | (src[4] >> 5);
*dst++ = (src[4] << 3) | BIT(2) | (src[5] >> 6);
*dst++ = (src[5] << 2) | BIT(1) | (src[6] >> 7);
*dst++ = (src[6] << 1) | BIT(0);
*dst++ = src[7];
}
src += 8;
added++;
}
}
tr.len = chunk + added;
tinydrm_dbg_spi_message(spi, &m);
ret = spi_sync(spi, &m);
if (ret)
return ret;
};
return 0;
}
static int mipi_dbi_spi1_transfer(struct mipi_dbi *mipi, int dc,
const void *buf, size_t len,
unsigned int bpw)
{
struct spi_device *spi = mipi->spi;
struct spi_transfer tr = {
.bits_per_word = 9,
};
const u16 *src16 = buf;
const u8 *src8 = buf;
struct spi_message m;
size_t max_chunk;
u16 *dst16;
int ret;
if (!tinydrm_spi_bpw_supported(spi, 9))
return mipi_dbi_spi1e_transfer(mipi, dc, buf, len, bpw);
tr.speed_hz = mipi_dbi_spi_cmd_max_speed(spi, len);
max_chunk = mipi->tx_buf9_len;
dst16 = mipi->tx_buf9;
if (drm_debug & DRM_UT_DRIVER)
pr_debug("[drm:%s] dc=%d, max_chunk=%zu, transfers:\n",
__func__, dc, max_chunk);
max_chunk = min(max_chunk / 2, len);
spi_message_init_with_transfers(&m, &tr, 1);
tr.tx_buf = dst16;
while (len) {
size_t chunk = min(len, max_chunk);
unsigned int i;
if (bpw == 16 && tinydrm_machine_little_endian()) {
for (i = 0; i < (chunk * 2); i += 2) {
dst16[i] = *src16 >> 8;
dst16[i + 1] = *src16++ & 0xFF;
if (dc) {
dst16[i] |= 0x0100;
dst16[i + 1] |= 0x0100;
}
}
} else {
for (i = 0; i < chunk; i++) {
dst16[i] = *src8++;
if (dc)
dst16[i] |= 0x0100;
}
}
tr.len = chunk;
len -= chunk;
tinydrm_dbg_spi_message(spi, &m);
ret = spi_sync(spi, &m);
if (ret)
return ret;
};
return 0;
}
static int mipi_dbi_typec1_command(struct mipi_dbi *mipi, u8 cmd,
u8 *parameters, size_t num)
{
unsigned int bpw = (cmd == MIPI_DCS_WRITE_MEMORY_START) ? 16 : 8;
int ret;
if (mipi_dbi_command_is_read(mipi, cmd))
return -ENOTSUPP;
MIPI_DBI_DEBUG_COMMAND(cmd, parameters, num);
ret = mipi_dbi_spi1_transfer(mipi, 0, &cmd, 1, 8);
if (ret || !num)
return ret;
return mipi_dbi_spi1_transfer(mipi, 1, parameters, num, bpw);
}
static int mipi_dbi_typec3_command_read(struct mipi_dbi *mipi, u8 cmd,
u8 *data, size_t len)
{
struct spi_device *spi = mipi->spi;
u32 speed_hz = min_t(u32, MIPI_DBI_MAX_SPI_READ_SPEED,
spi->max_speed_hz / 2);
struct spi_transfer tr[2] = {
{
.speed_hz = speed_hz,
.tx_buf = &cmd,
.len = 1,
}, {
.speed_hz = speed_hz,
.len = len,
},
};
struct spi_message m;
u8 *buf;
int ret;
if (!len)
return -EINVAL;
if (cmd == MIPI_DCS_GET_DISPLAY_ID ||
cmd == MIPI_DCS_GET_DISPLAY_STATUS) {
if (!(len == 3 || len == 4))
return -EINVAL;
tr[1].len = len + 1;
}
buf = kmalloc(tr[1].len, GFP_KERNEL);
if (!buf)
return -ENOMEM;
tr[1].rx_buf = buf;
gpiod_set_value_cansleep(mipi->dc, 0);
spi_message_init_with_transfers(&m, tr, ARRAY_SIZE(tr));
ret = spi_sync(spi, &m);
if (ret)
goto err_free;
tinydrm_dbg_spi_message(spi, &m);
if (tr[1].len == len) {
memcpy(data, buf, len);
} else {
unsigned int i;
for (i = 0; i < len; i++)
data[i] = (buf[i] << 1) | !!(buf[i + 1] & BIT(7));
}
MIPI_DBI_DEBUG_COMMAND(cmd, data, len);
err_free:
kfree(buf);
return ret;
}
static int mipi_dbi_typec3_command(struct mipi_dbi *mipi, u8 cmd,
u8 *par, size_t num)
{
struct spi_device *spi = mipi->spi;
unsigned int bpw = 8;
u32 speed_hz;
int ret;
if (mipi_dbi_command_is_read(mipi, cmd))
return mipi_dbi_typec3_command_read(mipi, cmd, par, num);
MIPI_DBI_DEBUG_COMMAND(cmd, par, num);
gpiod_set_value_cansleep(mipi->dc, 0);
speed_hz = mipi_dbi_spi_cmd_max_speed(spi, 1);
ret = tinydrm_spi_transfer(spi, speed_hz, NULL, 8, &cmd, 1);
if (ret || !num)
return ret;
if (cmd == MIPI_DCS_WRITE_MEMORY_START && !mipi->swap_bytes)
bpw = 16;
gpiod_set_value_cansleep(mipi->dc, 1);
speed_hz = mipi_dbi_spi_cmd_max_speed(spi, num);
return tinydrm_spi_transfer(spi, speed_hz, NULL, bpw, par, num);
}
int mipi_dbi_spi_init(struct spi_device *spi, struct mipi_dbi *mipi,
struct gpio_desc *dc,
const struct drm_simple_display_pipe_funcs *pipe_funcs,
struct drm_driver *driver,
const struct drm_display_mode *mode,
unsigned int rotation)
{
size_t tx_size = tinydrm_spi_max_transfer_size(spi, 0);
struct device *dev = &spi->dev;
int ret;
if (tx_size < 16) {
DRM_ERROR("SPI transmit buffer too small: %zu\n", tx_size);
return -EINVAL;
}
if (!dev->coherent_dma_mask) {
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret) {
dev_warn(dev, "Failed to set dma mask %d\n", ret);
return ret;
}
}
mipi->spi = spi;
mipi->read_commands = mipi_dbi_dcs_read_commands;
if (dc) {
mipi->command = mipi_dbi_typec3_command;
mipi->dc = dc;
if (tinydrm_machine_little_endian() &&
!tinydrm_spi_bpw_supported(spi, 16))
mipi->swap_bytes = true;
} else {
mipi->command = mipi_dbi_typec1_command;
mipi->tx_buf9_len = tx_size;
mipi->tx_buf9 = devm_kmalloc(dev, tx_size, GFP_KERNEL);
if (!mipi->tx_buf9)
return -ENOMEM;
}
return mipi_dbi_init(dev, mipi, pipe_funcs, driver, mode, rotation);
}
static ssize_t mipi_dbi_debugfs_command_write(struct file *file,
const char __user *ubuf,
size_t count, loff_t *ppos)
{
struct seq_file *m = file->private_data;
struct mipi_dbi *mipi = m->private;
u8 val, cmd = 0, parameters[64];
char *buf, *pos, *token;
unsigned int i;
int ret;
buf = memdup_user_nul(ubuf, count);
if (IS_ERR(buf))
return PTR_ERR(buf);
for (i = count - 1; i > 0; i--)
if (isspace(buf[i]))
buf[i] = '\0';
else
break;
i = 0;
pos = buf;
while (pos) {
token = strsep(&pos, " ");
if (!token) {
ret = -EINVAL;
goto err_free;
}
ret = kstrtou8(token, 16, &val);
if (ret < 0)
goto err_free;
if (token == buf)
cmd = val;
else
parameters[i++] = val;
if (i == 64) {
ret = -E2BIG;
goto err_free;
}
}
ret = mipi_dbi_command_buf(mipi, cmd, parameters, i);
err_free:
kfree(buf);
return ret < 0 ? ret : count;
}
static int mipi_dbi_debugfs_command_show(struct seq_file *m, void *unused)
{
struct mipi_dbi *mipi = m->private;
u8 cmd, val[4];
size_t len, i;
int ret;
for (cmd = 0; cmd < 255; cmd++) {
if (!mipi_dbi_command_is_read(mipi, cmd))
continue;
switch (cmd) {
case MIPI_DCS_READ_MEMORY_START:
case MIPI_DCS_READ_MEMORY_CONTINUE:
len = 2;
break;
case MIPI_DCS_GET_DISPLAY_ID:
len = 3;
break;
case MIPI_DCS_GET_DISPLAY_STATUS:
len = 4;
break;
default:
len = 1;
break;
}
seq_printf(m, "%02x: ", cmd);
ret = mipi_dbi_command_buf(mipi, cmd, val, len);
if (ret) {
seq_puts(m, "XX\n");
continue;
}
for (i = 0; i < len; i++)
seq_printf(m, "%02x", val[i]);
seq_puts(m, "\n");
}
return 0;
}
static int mipi_dbi_debugfs_command_open(struct inode *inode,
struct file *file)
{
return single_open(file, mipi_dbi_debugfs_command_show,
inode->i_private);
}
int mipi_dbi_debugfs_init(struct drm_minor *minor)
{
struct tinydrm_device *tdev = minor->dev->dev_private;
struct mipi_dbi *mipi = mipi_dbi_from_tinydrm(tdev);
umode_t mode = S_IFREG | S_IWUSR;
if (mipi->read_commands)
mode |= S_IRUGO;
debugfs_create_file("command", mode, minor->debugfs_root, mipi,
&mipi_dbi_debugfs_command_fops);
return drm_debugfs_create_files(mipi_dbi_debugfs_list,
ARRAY_SIZE(mipi_dbi_debugfs_list),
minor->debugfs_root, minor);
}
