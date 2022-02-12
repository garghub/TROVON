static int picolcd_fb_send_tile(struct picolcd_data *data, u8 *vbitmap,
int chip, int tile)
{
struct hid_report *report1, *report2;
unsigned long flags;
u8 *tdata;
int i;
report1 = picolcd_out_report(REPORT_LCD_CMD_DATA, data->hdev);
if (!report1 || report1->maxfield != 1)
return -ENODEV;
report2 = picolcd_out_report(REPORT_LCD_DATA, data->hdev);
if (!report2 || report2->maxfield != 1)
return -ENODEV;
spin_lock_irqsave(&data->lock, flags);
if ((data->status & PICOLCD_FAILED)) {
spin_unlock_irqrestore(&data->lock, flags);
return -ENODEV;
}
hid_set_field(report1->field[0], 0, chip << 2);
hid_set_field(report1->field[0], 1, 0x02);
hid_set_field(report1->field[0], 2, 0x00);
hid_set_field(report1->field[0], 3, 0x00);
hid_set_field(report1->field[0], 4, 0xb8 | tile);
hid_set_field(report1->field[0], 5, 0x00);
hid_set_field(report1->field[0], 6, 0x00);
hid_set_field(report1->field[0], 7, 0x40);
hid_set_field(report1->field[0], 8, 0x00);
hid_set_field(report1->field[0], 9, 0x00);
hid_set_field(report1->field[0], 10, 32);
hid_set_field(report2->field[0], 0, (chip << 2) | 0x01);
hid_set_field(report2->field[0], 1, 0x00);
hid_set_field(report2->field[0], 2, 0x00);
hid_set_field(report2->field[0], 3, 32);
tdata = vbitmap + (tile * 4 + chip) * 64;
for (i = 0; i < 64; i++)
if (i < 32)
hid_set_field(report1->field[0], 11 + i, tdata[i]);
else
hid_set_field(report2->field[0], 4 + i - 32, tdata[i]);
hid_hw_request(data->hdev, report1, HID_REQ_SET_REPORT);
hid_hw_request(data->hdev, report2, HID_REQ_SET_REPORT);
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int picolcd_fb_update_tile(u8 *vbitmap, const u8 *bitmap, int bpp,
int chip, int tile)
{
int i, b, changed = 0;
u8 tdata[64];
u8 *vdata = vbitmap + (tile * 4 + chip) * 64;
if (bpp == 1) {
for (b = 7; b >= 0; b--) {
const u8 *bdata = bitmap + tile * 256 + chip * 8 + b * 32;
for (i = 0; i < 64; i++) {
tdata[i] <<= 1;
tdata[i] |= (bdata[i/8] >> (i % 8)) & 0x01;
}
}
} else if (bpp == 8) {
for (b = 7; b >= 0; b--) {
const u8 *bdata = bitmap + (tile * 256 + chip * 8 + b * 32) * 8;
for (i = 0; i < 64; i++) {
tdata[i] <<= 1;
tdata[i] |= (bdata[i] & 0x80) ? 0x01 : 0x00;
}
}
} else {
WARN_ON(1);
return 0;
}
for (i = 0; i < 64; i++)
if (tdata[i] != vdata[i]) {
changed = 1;
vdata[i] = tdata[i];
}
return changed;
}
void picolcd_fb_refresh(struct picolcd_data *data)
{
if (data->fb_info)
schedule_delayed_work(&data->fb_info->deferred_work, 0);
}
int picolcd_fb_reset(struct picolcd_data *data, int clear)
{
struct hid_report *report = picolcd_out_report(REPORT_LCD_CMD, data->hdev);
struct picolcd_fb_data *fbdata = data->fb_info->par;
int i, j;
unsigned long flags;
static const u8 mapcmd[8] = { 0x00, 0x02, 0x00, 0x64, 0x3f, 0x00, 0x64, 0xc0 };
if (!report || report->maxfield != 1)
return -ENODEV;
spin_lock_irqsave(&data->lock, flags);
for (i = 0; i < 4; i++) {
for (j = 0; j < report->field[0]->maxusage; j++)
if (j == 0)
hid_set_field(report->field[0], j, i << 2);
else if (j < sizeof(mapcmd))
hid_set_field(report->field[0], j, mapcmd[j]);
else
hid_set_field(report->field[0], j, 0);
hid_hw_request(data->hdev, report, HID_REQ_SET_REPORT);
}
spin_unlock_irqrestore(&data->lock, flags);
if (clear) {
memset(fbdata->vbitmap, 0, PICOLCDFB_SIZE);
memset(fbdata->bitmap, 0, PICOLCDFB_SIZE*fbdata->bpp);
}
fbdata->force = 1;
if (fbdata->ready)
schedule_delayed_work(&data->fb_info->deferred_work, 0);
else
fbdata->ready = 1;
return 0;
}
static void picolcd_fb_update(struct fb_info *info)
{
int chip, tile, n;
unsigned long flags;
struct picolcd_fb_data *fbdata = info->par;
struct picolcd_data *data;
mutex_lock(&info->lock);
spin_lock_irqsave(&fbdata->lock, flags);
if (!fbdata->ready && fbdata->picolcd)
picolcd_fb_reset(fbdata->picolcd, 0);
spin_unlock_irqrestore(&fbdata->lock, flags);
n = 0;
for (chip = 0; chip < 4; chip++)
for (tile = 0; tile < 8; tile++) {
if (!fbdata->force && !picolcd_fb_update_tile(
fbdata->vbitmap, fbdata->bitmap,
fbdata->bpp, chip, tile))
continue;
n += 2;
if (n >= HID_OUTPUT_FIFO_SIZE / 2) {
spin_lock_irqsave(&fbdata->lock, flags);
data = fbdata->picolcd;
spin_unlock_irqrestore(&fbdata->lock, flags);
mutex_unlock(&info->lock);
if (!data)
return;
hid_hw_wait(data->hdev);
mutex_lock(&info->lock);
n = 0;
}
spin_lock_irqsave(&fbdata->lock, flags);
data = fbdata->picolcd;
spin_unlock_irqrestore(&fbdata->lock, flags);
if (!data || picolcd_fb_send_tile(data,
fbdata->vbitmap, chip, tile))
goto out;
}
fbdata->force = false;
if (n) {
spin_lock_irqsave(&fbdata->lock, flags);
data = fbdata->picolcd;
spin_unlock_irqrestore(&fbdata->lock, flags);
mutex_unlock(&info->lock);
if (data)
hid_hw_wait(data->hdev);
return;
}
out:
mutex_unlock(&info->lock);
}
static void picolcd_fb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
if (!info->par)
return;
sys_fillrect(info, rect);
schedule_delayed_work(&info->deferred_work, 0);
}
static void picolcd_fb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
if (!info->par)
return;
sys_copyarea(info, area);
schedule_delayed_work(&info->deferred_work, 0);
}
static void picolcd_fb_imageblit(struct fb_info *info, const struct fb_image *image)
{
if (!info->par)
return;
sys_imageblit(info, image);
schedule_delayed_work(&info->deferred_work, 0);
}
static ssize_t picolcd_fb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
ssize_t ret;
if (!info->par)
return -ENODEV;
ret = fb_sys_write(info, buf, count, ppos);
if (ret >= 0)
schedule_delayed_work(&info->deferred_work, 0);
return ret;
}
static int picolcd_fb_blank(int blank, struct fb_info *info)
{
return 0;
}
static void picolcd_fb_destroy(struct fb_info *info)
{
struct picolcd_fb_data *fbdata = info->par;
fb_deferred_io_cleanup(info);
WARN_ON(fbdata->picolcd != NULL);
vfree((u8 *)info->fix.smem_start);
framebuffer_release(info);
}
static int picolcd_fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
__u32 bpp = var->bits_per_pixel;
__u32 activate = var->activate;
*var = picolcdfb_var;
var->activate = activate;
if (bpp >= 8) {
var->bits_per_pixel = 8;
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
} else {
var->bits_per_pixel = 1;
var->red.length = 1;
var->green.length = 1;
var->blue.length = 1;
}
return 0;
}
static int picolcd_set_par(struct fb_info *info)
{
struct picolcd_fb_data *fbdata = info->par;
u8 *tmp_fb, *o_fb;
if (info->var.bits_per_pixel == fbdata->bpp)
return 0;
if (info->var.bits_per_pixel != 1 && info->var.bits_per_pixel != 8)
return -EINVAL;
o_fb = fbdata->bitmap;
tmp_fb = kmalloc(PICOLCDFB_SIZE*info->var.bits_per_pixel, GFP_KERNEL);
if (!tmp_fb)
return -ENOMEM;
if (info->var.bits_per_pixel == 1) {
int i, b;
for (i = 0; i < PICOLCDFB_SIZE; i++) {
u8 p = 0;
for (b = 0; b < 8; b++) {
p <<= 1;
p |= o_fb[i*8+b] ? 0x01 : 0x00;
}
tmp_fb[i] = p;
}
memcpy(o_fb, tmp_fb, PICOLCDFB_SIZE);
info->fix.visual = FB_VISUAL_MONO01;
info->fix.line_length = PICOLCDFB_WIDTH / 8;
} else {
int i;
memcpy(tmp_fb, o_fb, PICOLCDFB_SIZE);
for (i = 0; i < PICOLCDFB_SIZE * 8; i++)
o_fb[i] = tmp_fb[i/8] & (0x01 << (7 - i % 8)) ? 0xff : 0x00;
info->fix.visual = FB_VISUAL_DIRECTCOLOR;
info->fix.line_length = PICOLCDFB_WIDTH;
}
kfree(tmp_fb);
fbdata->bpp = info->var.bits_per_pixel;
return 0;
}
static void picolcd_fb_deferred_io(struct fb_info *info, struct list_head *pagelist)
{
picolcd_fb_update(info);
}
static ssize_t picolcd_fb_update_rate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct picolcd_data *data = dev_get_drvdata(dev);
struct picolcd_fb_data *fbdata = data->fb_info->par;
unsigned i, fb_update_rate = fbdata->update_rate;
size_t ret = 0;
for (i = 1; i <= PICOLCDFB_UPDATE_RATE_LIMIT; i++)
if (ret >= PAGE_SIZE)
break;
else if (i == fb_update_rate)
ret += snprintf(buf+ret, PAGE_SIZE-ret, "[%u] ", i);
else
ret += snprintf(buf+ret, PAGE_SIZE-ret, "%u ", i);
if (ret > 0)
buf[min(ret, (size_t)PAGE_SIZE)-1] = '\n';
return ret;
}
static ssize_t picolcd_fb_update_rate_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct picolcd_data *data = dev_get_drvdata(dev);
struct picolcd_fb_data *fbdata = data->fb_info->par;
int i;
unsigned u;
if (count < 1 || count > 10)
return -EINVAL;
i = sscanf(buf, "%u", &u);
if (i != 1)
return -EINVAL;
if (u > PICOLCDFB_UPDATE_RATE_LIMIT)
return -ERANGE;
else if (u == 0)
u = PICOLCDFB_UPDATE_RATE_DEFAULT;
fbdata->update_rate = u;
data->fb_info->fbdefio->delay = HZ / fbdata->update_rate;
return count;
}
int picolcd_init_framebuffer(struct picolcd_data *data)
{
struct device *dev = &data->hdev->dev;
struct fb_info *info = NULL;
struct picolcd_fb_data *fbdata = NULL;
int i, error = -ENOMEM;
u32 *palette;
info = framebuffer_alloc(256 * sizeof(u32) +
sizeof(struct fb_deferred_io) +
sizeof(struct picolcd_fb_data) +
PICOLCDFB_SIZE, dev);
if (info == NULL) {
dev_err(dev, "failed to allocate a framebuffer\n");
goto err_nomem;
}
info->fbdefio = info->par;
*info->fbdefio = picolcd_fb_defio;
info->par += sizeof(struct fb_deferred_io);
palette = info->par;
info->par += 256 * sizeof(u32);
for (i = 0; i < 256; i++)
palette[i] = i > 0 && i < 16 ? 0xff : 0;
info->pseudo_palette = palette;
info->fbops = &picolcdfb_ops;
info->var = picolcdfb_var;
info->fix = picolcdfb_fix;
info->fix.smem_len = PICOLCDFB_SIZE*8;
info->flags = FBINFO_FLAG_DEFAULT;
fbdata = info->par;
spin_lock_init(&fbdata->lock);
fbdata->picolcd = data;
fbdata->update_rate = PICOLCDFB_UPDATE_RATE_DEFAULT;
fbdata->bpp = picolcdfb_var.bits_per_pixel;
fbdata->force = 1;
fbdata->vbitmap = info->par + sizeof(struct picolcd_fb_data);
fbdata->bitmap = vmalloc(PICOLCDFB_SIZE*8);
if (fbdata->bitmap == NULL) {
dev_err(dev, "can't get a free page for framebuffer\n");
goto err_nomem;
}
info->screen_base = (char __force __iomem *)fbdata->bitmap;
info->fix.smem_start = (unsigned long)fbdata->bitmap;
memset(fbdata->vbitmap, 0xff, PICOLCDFB_SIZE);
data->fb_info = info;
error = picolcd_fb_reset(data, 1);
if (error) {
dev_err(dev, "failed to configure display\n");
goto err_cleanup;
}
error = device_create_file(dev, &dev_attr_fb_update_rate);
if (error) {
dev_err(dev, "failed to create sysfs attributes\n");
goto err_cleanup;
}
fb_deferred_io_init(info);
error = register_framebuffer(info);
if (error) {
dev_err(dev, "failed to register framebuffer\n");
goto err_sysfs;
}
return 0;
err_sysfs:
device_remove_file(dev, &dev_attr_fb_update_rate);
fb_deferred_io_cleanup(info);
err_cleanup:
data->fb_info = NULL;
err_nomem:
if (fbdata)
vfree(fbdata->bitmap);
framebuffer_release(info);
return error;
}
void picolcd_exit_framebuffer(struct picolcd_data *data)
{
struct fb_info *info = data->fb_info;
struct picolcd_fb_data *fbdata = info->par;
unsigned long flags;
device_remove_file(&data->hdev->dev, &dev_attr_fb_update_rate);
spin_lock_irqsave(&fbdata->lock, flags);
fbdata->picolcd = NULL;
spin_unlock_irqrestore(&fbdata->lock, flags);
flush_delayed_work(&info->deferred_work);
data->fb_info = NULL;
unregister_framebuffer(info);
}
