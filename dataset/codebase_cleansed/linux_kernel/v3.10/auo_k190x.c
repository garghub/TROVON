static void auok190x_issue_data(struct auok190xfb_par *par, u16 data)
{
par->board->set_ctl(par, AUOK190X_I80_WR, 0);
par->board->set_hdb(par, data);
par->board->set_ctl(par, AUOK190X_I80_WR, 1);
}
static void auok190x_issue_cmd(struct auok190xfb_par *par, u16 data)
{
par->board->set_ctl(par, AUOK190X_I80_DC, 0);
auok190x_issue_data(par, data);
par->board->set_ctl(par, AUOK190X_I80_DC, 1);
}
static inline int rgb565_to_gray4(u16 data, struct fb_var_screeninfo *var)
{
return ((((data & 0xF800) >> var->red.offset) * 77 +
((data & 0x07E0) >> (var->green.offset + 1)) * 151 +
((data & 0x1F) >> var->blue.offset) * 28) >> 8 >> 1);
}
static int auok190x_issue_pixels_rgb565(struct auok190xfb_par *par, int size,
u16 *data)
{
struct fb_var_screeninfo *var = &par->info->var;
struct device *dev = par->info->device;
int i;
u16 tmp;
if (size & 7) {
dev_err(dev, "issue_pixels: size %d must be a multiple of 8\n",
size);
return -EINVAL;
}
for (i = 0; i < (size >> 2); i++) {
par->board->set_ctl(par, AUOK190X_I80_WR, 0);
tmp = (rgb565_to_gray4(data[4*i], var) & 0x000F);
tmp |= (rgb565_to_gray4(data[4*i+1], var) << 4) & 0x00F0;
tmp |= (rgb565_to_gray4(data[4*i+2], var) << 8) & 0x0F00;
tmp |= (rgb565_to_gray4(data[4*i+3], var) << 12) & 0xF000;
par->board->set_hdb(par, tmp);
par->board->set_ctl(par, AUOK190X_I80_WR, 1);
}
return 0;
}
static int auok190x_issue_pixels_gray8(struct auok190xfb_par *par, int size,
u16 *data)
{
struct device *dev = par->info->device;
int i;
u16 tmp;
if (size & 3) {
dev_err(dev, "issue_pixels: size %d must be a multiple of 4\n",
size);
return -EINVAL;
}
for (i = 0; i < (size >> 1); i++) {
par->board->set_ctl(par, AUOK190X_I80_WR, 0);
tmp = (data[2*i] & 0xF0) >> 4;
tmp |= (data[2*i] & 0xF000) >> 8;
tmp |= (data[2*i+1] & 0xF0) << 4;
tmp |= (data[2*i+1] & 0xF000);
par->board->set_hdb(par, tmp);
par->board->set_ctl(par, AUOK190X_I80_WR, 1);
}
return 0;
}
static int auok190x_issue_pixels(struct auok190xfb_par *par, int size,
u16 *data)
{
struct fb_info *info = par->info;
struct device *dev = par->info->device;
if (info->var.bits_per_pixel == 8 && info->var.grayscale)
auok190x_issue_pixels_gray8(par, size, data);
else if (info->var.bits_per_pixel == 16)
auok190x_issue_pixels_rgb565(par, size, data);
else
dev_err(dev, "unsupported color mode (bits: %d, gray: %d)\n",
info->var.bits_per_pixel, info->var.grayscale);
return 0;
}
static u16 auok190x_read_data(struct auok190xfb_par *par)
{
u16 data;
par->board->set_ctl(par, AUOK190X_I80_OE, 0);
data = par->board->get_hdb(par);
par->board->set_ctl(par, AUOK190X_I80_OE, 1);
return data;
}
void auok190x_send_command_nowait(struct auok190xfb_par *par, u16 data)
{
par->board->set_ctl(par, AUOK190X_I80_CS, 0);
auok190x_issue_cmd(par, data);
par->board->set_ctl(par, AUOK190X_I80_CS, 1);
}
void auok190x_send_cmdargs_nowait(struct auok190xfb_par *par, u16 cmd,
int argc, u16 *argv)
{
int i;
par->board->set_ctl(par, AUOK190X_I80_CS, 0);
auok190x_issue_cmd(par, cmd);
for (i = 0; i < argc; i++)
auok190x_issue_data(par, argv[i]);
par->board->set_ctl(par, AUOK190X_I80_CS, 1);
}
int auok190x_send_command(struct auok190xfb_par *par, u16 data)
{
int ret;
ret = par->board->wait_for_rdy(par);
if (ret)
return ret;
auok190x_send_command_nowait(par, data);
return 0;
}
int auok190x_send_cmdargs(struct auok190xfb_par *par, u16 cmd,
int argc, u16 *argv)
{
int ret;
ret = par->board->wait_for_rdy(par);
if (ret)
return ret;
auok190x_send_cmdargs_nowait(par, cmd, argc, argv);
return 0;
}
int auok190x_read_cmdargs(struct auok190xfb_par *par, u16 cmd,
int argc, u16 *argv)
{
int i, ret;
ret = par->board->wait_for_rdy(par);
if (ret)
return ret;
par->board->set_ctl(par, AUOK190X_I80_CS, 0);
auok190x_issue_cmd(par, cmd);
for (i = 0; i < argc; i++)
argv[i] = auok190x_read_data(par);
par->board->set_ctl(par, AUOK190X_I80_CS, 1);
return 0;
}
void auok190x_send_cmdargs_pixels_nowait(struct auok190xfb_par *par, u16 cmd,
int argc, u16 *argv, int size, u16 *data)
{
int i;
par->board->set_ctl(par, AUOK190X_I80_CS, 0);
auok190x_issue_cmd(par, cmd);
for (i = 0; i < argc; i++)
auok190x_issue_data(par, argv[i]);
auok190x_issue_pixels(par, size, data);
par->board->set_ctl(par, AUOK190X_I80_CS, 1);
}
int auok190x_send_cmdargs_pixels(struct auok190xfb_par *par, u16 cmd,
int argc, u16 *argv, int size, u16 *data)
{
int ret;
ret = par->board->wait_for_rdy(par);
if (ret)
return ret;
auok190x_send_cmdargs_pixels_nowait(par, cmd, argc, argv, size, data);
return 0;
}
static void auok190xfb_dpy_first_io(struct fb_info *info)
{
pm_runtime_get(info->device);
}
static void auok190xfb_dpy_deferred_io(struct fb_info *info,
struct list_head *pagelist)
{
struct fb_deferred_io *fbdefio = info->fbdefio;
struct auok190xfb_par *par = info->par;
u16 line_length = info->fix.line_length;
u16 yres = info->var.yres;
u16 y1 = 0, h = 0;
int prev_index = -1;
struct page *cur;
int h_inc;
int threshold;
if (!list_empty(pagelist))
pm_runtime_barrier(info->device);
else
pm_runtime_get_sync(info->device);
if (par->need_refresh(par)) {
par->update_all(par);
goto out;
}
h_inc = DIV_ROUND_UP(PAGE_SIZE , line_length);
threshold = par->consecutive_threshold / h_inc;
if (threshold < 1)
threshold = 1;
list_for_each_entry(cur, &fbdefio->pagelist, lru) {
if (prev_index < 0) {
y1 = (cur->index << PAGE_SHIFT) / line_length;
h = h_inc;
} else if ((cur->index - prev_index) <= threshold) {
h += h_inc * (cur->index - prev_index);
} else {
par->update_partial(par, y1, y1 + h);
y1 = (cur->index << PAGE_SHIFT) / line_length;
h = h_inc;
}
prev_index = cur->index;
}
if (h >= yres)
par->update_all(par);
else
par->update_partial(par, y1, min((u16) (y1 + h), yres));
out:
pm_runtime_mark_last_busy(info->device);
pm_runtime_put_autosuspend(info->device);
}
static ssize_t auok190xfb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
struct auok190xfb_par *par = info->par;
unsigned long p = *ppos;
void *dst;
int err = 0;
unsigned long total_size;
if (info->state != FBINFO_STATE_RUNNING)
return -EPERM;
total_size = info->fix.smem_len;
if (p > total_size)
return -EFBIG;
if (count > total_size) {
err = -EFBIG;
count = total_size;
}
if (count + p > total_size) {
if (!err)
err = -ENOSPC;
count = total_size - p;
}
dst = (void *)(info->screen_base + p);
if (copy_from_user(dst, buf, count))
err = -EFAULT;
if (!err)
*ppos += count;
par->update_all(par);
return (err) ? err : count;
}
static void auok190xfb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
struct auok190xfb_par *par = info->par;
sys_fillrect(info, rect);
par->update_all(par);
}
static void auok190xfb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
struct auok190xfb_par *par = info->par;
sys_copyarea(info, area);
par->update_all(par);
}
static void auok190xfb_imageblit(struct fb_info *info,
const struct fb_image *image)
{
struct auok190xfb_par *par = info->par;
sys_imageblit(info, image);
par->update_all(par);
}
static int auok190xfb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct device *dev = info->device;
struct auok190xfb_par *par = info->par;
struct panel_info *panel = &panel_table[par->resolution];
int size;
if (var->bits_per_pixel == 8 && var->grayscale == 1) {
var->red.length = 8;
var->red.offset = 0;
var->red.msb_right = 0;
var->green.length = 8;
var->green.offset = 0;
var->green.msb_right = 0;
var->blue.length = 8;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 0;
var->transp.offset = 0;
var->transp.msb_right = 0;
} else if (var->bits_per_pixel == 16) {
var->red.length = 5;
var->red.offset = 11;
var->red.msb_right = 0;
var->green.length = 6;
var->green.offset = 5;
var->green.msb_right = 0;
var->blue.length = 5;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 0;
var->transp.offset = 0;
var->transp.msb_right = 0;
} else {
dev_warn(dev, "unsupported color mode (bits: %d, grayscale: %d)\n",
info->var.bits_per_pixel, info->var.grayscale);
return -EINVAL;
}
switch (var->rotate) {
case FB_ROTATE_UR:
case FB_ROTATE_UD:
var->xres = panel->w;
var->yres = panel->h;
break;
case FB_ROTATE_CW:
case FB_ROTATE_CCW:
var->xres = panel->h;
var->yres = panel->w;
break;
default:
dev_dbg(dev, "Invalid rotation request\n");
return -EINVAL;
}
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
size = var->xres_virtual * var->yres_virtual * var->bits_per_pixel / 8;
if (size > info->fix.smem_len) {
dev_err(dev, "Memory limit exceeded, requested %dK\n",
size >> 10);
return -ENOMEM;
}
return 0;
}
static int auok190xfb_set_fix(struct fb_info *info)
{
struct fb_fix_screeninfo *fix = &info->fix;
struct fb_var_screeninfo *var = &info->var;
fix->line_length = var->xres_virtual * var->bits_per_pixel / 8;
fix->type = FB_TYPE_PACKED_PIXELS;
fix->accel = FB_ACCEL_NONE;
fix->visual = (var->grayscale) ? FB_VISUAL_STATIC_PSEUDOCOLOR
: FB_VISUAL_TRUECOLOR;
fix->xpanstep = 0;
fix->ypanstep = 0;
fix->ywrapstep = 0;
return 0;
}
static int auok190xfb_set_par(struct fb_info *info)
{
struct auok190xfb_par *par = info->par;
par->rotation = info->var.rotate;
auok190xfb_set_fix(info);
par->init(par);
par->board->wait_for_rdy(par);
return 0;
}
static int auok190x_read_temperature(struct auok190xfb_par *par)
{
struct device *dev = par->info->device;
u16 data[4];
int temp;
pm_runtime_get_sync(dev);
mutex_lock(&(par->io_lock));
auok190x_read_cmdargs(par, AUOK190X_CMD_READ_VERSION, 4, data);
mutex_unlock(&(par->io_lock));
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
temp = ((data[0] & AUOK190X_VERSION_TEMP_MASK) >> 1);
if (temp >= 201)
return (255 - temp + 1) * (-1);
else
return temp;
}
static void auok190x_identify(struct auok190xfb_par *par)
{
struct device *dev = par->info->device;
u16 data[4];
pm_runtime_get_sync(dev);
mutex_lock(&(par->io_lock));
auok190x_read_cmdargs(par, AUOK190X_CMD_READ_VERSION, 4, data);
mutex_unlock(&(par->io_lock));
par->epd_type = data[1] & AUOK190X_VERSION_TEMP_MASK;
par->panel_size_int = AUOK190X_VERSION_SIZE_INT(data[2]);
par->panel_size_float = AUOK190X_VERSION_SIZE_FLOAT(data[2]);
par->panel_model = AUOK190X_VERSION_MODEL(data[2]);
par->tcon_version = AUOK190X_VERSION_TCON(data[3]);
par->lut_version = AUOK190X_VERSION_LUT(data[3]);
dev_dbg(dev, "panel %d.%din, model 0x%x, EPD 0x%x TCON-rev 0x%x, LUT-rev 0x%x",
par->panel_size_int, par->panel_size_float, par->panel_model,
par->epd_type, par->tcon_version, par->lut_version);
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
}
static ssize_t update_mode_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fb_info *info = dev_get_drvdata(dev);
struct auok190xfb_par *par = info->par;
return sprintf(buf, "%d\n", par->update_mode);
}
static ssize_t update_mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fb_info *info = dev_get_drvdata(dev);
struct auok190xfb_par *par = info->par;
int mode, ret;
ret = kstrtoint(buf, 10, &mode);
if (ret)
return ret;
par->update_mode = mode;
if (par->last_mode > 1 && mode < par->last_mode)
par->update_all(par);
return count;
}
static ssize_t flash_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fb_info *info = dev_get_drvdata(dev);
struct auok190xfb_par *par = info->par;
return sprintf(buf, "%d\n", par->flash);
}
static ssize_t flash_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fb_info *info = dev_get_drvdata(dev);
struct auok190xfb_par *par = info->par;
int flash, ret;
ret = kstrtoint(buf, 10, &flash);
if (ret)
return ret;
if (flash > 0)
par->flash = 1;
else
par->flash = 0;
return count;
}
static ssize_t temp_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fb_info *info = dev_get_drvdata(dev);
struct auok190xfb_par *par = info->par;
int temp;
temp = auok190x_read_temperature(par);
return sprintf(buf, "%d\n", temp);
}
static int auok190x_power(struct auok190xfb_par *par, bool on)
{
struct auok190x_board *board = par->board;
int ret;
if (on) {
ret = regulator_enable(par->regulator);
if (ret)
return ret;
msleep(200);
gpio_set_value(board->gpio_nrst, 1);
gpio_set_value(board->gpio_nsleep, 1);
msleep(200);
} else {
regulator_disable(par->regulator);
gpio_set_value(board->gpio_nrst, 0);
gpio_set_value(board->gpio_nsleep, 0);
}
return 0;
}
static void auok190x_recover(struct auok190xfb_par *par)
{
struct device *dev = par->info->device;
auok190x_power(par, 0);
msleep(100);
auok190x_power(par, 1);
pm_runtime_set_active(dev);
par->standby = 0;
par->init(par);
par->board->wait_for_rdy(par);
}
static int auok190x_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct fb_info *info = platform_get_drvdata(pdev);
struct auok190xfb_par *par = info->par;
struct auok190x_board *board = par->board;
u16 standby_param;
mutex_lock(&(par->io_lock));
if (par->standby) {
dev_warn(dev, "already in standby, runtime-pm pairing mismatch\n");
mutex_unlock(&(par->io_lock));
return 0;
}
if (board->quirks & AUOK190X_QUIRK_STANDBYBROKEN) {
dev_dbg(dev, "runtime suspend without standby\n");
goto finish;
} else if (board->quirks & AUOK190X_QUIRK_STANDBYPARAM) {
dev_dbg(dev, "runtime suspend with additional empty param\n");
standby_param = 0;
auok190x_send_cmdargs(par, AUOK190X_CMD_STANDBY, 1,
&standby_param);
} else {
dev_dbg(dev, "runtime suspend without param\n");
auok190x_send_command(par, AUOK190X_CMD_STANDBY);
}
msleep(64);
finish:
par->standby = 1;
return 0;
}
static int auok190x_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct fb_info *info = platform_get_drvdata(pdev);
struct auok190xfb_par *par = info->par;
struct auok190x_board *board = par->board;
if (!par->standby) {
dev_warn(dev, "not in standby, runtime-pm pairing mismatch\n");
return 0;
}
if (board->quirks & AUOK190X_QUIRK_STANDBYBROKEN) {
dev_dbg(dev, "runtime resume without standby\n");
} else {
dev_dbg(dev, "runtime resume from standby\n");
auok190x_send_command_nowait(par, AUOK190X_CMD_WAKEUP);
msleep(160);
board->wait_for_rdy(par);
}
par->standby = 0;
mutex_unlock(&(par->io_lock));
return 0;
}
static int auok190x_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct fb_info *info = platform_get_drvdata(pdev);
struct auok190xfb_par *par = info->par;
struct auok190x_board *board = par->board;
int ret;
dev_dbg(dev, "suspend\n");
if (board->quirks & AUOK190X_QUIRK_STANDBYBROKEN) {
dev_dbg(dev, "suspend with broken standby\n");
auok190x_power(par, 0);
} else {
dev_dbg(dev, "suspend using sleep\n");
if (!pm_runtime_status_suspended(dev)) {
ret = auok190x_runtime_suspend(dev);
if (ret < 0) {
dev_err(dev, "auok190x_runtime_suspend failed with %d\n",
ret);
return ret;
}
par->manual_standby = 1;
}
gpio_direction_output(board->gpio_nsleep, 0);
}
msleep(100);
return 0;
}
static int auok190x_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct fb_info *info = platform_get_drvdata(pdev);
struct auok190xfb_par *par = info->par;
struct auok190x_board *board = par->board;
dev_dbg(dev, "resume\n");
if (board->quirks & AUOK190X_QUIRK_STANDBYBROKEN) {
dev_dbg(dev, "resume with broken standby\n");
auok190x_power(par, 1);
par->init(par);
} else {
dev_dbg(dev, "resume from sleep\n");
gpio_direction_output(board->gpio_nsleep, 1);
msleep(100);
auok190x_runtime_resume(dev);
par->init(par);
if (!par->manual_standby)
auok190x_runtime_suspend(dev);
else
par->manual_standby = 0;
}
return 0;
}
int auok190x_common_probe(struct platform_device *pdev,
struct auok190x_init_data *init)
{
struct auok190x_board *board = init->board;
struct auok190xfb_par *par;
struct fb_info *info;
struct panel_info *panel;
int videomemorysize, ret;
unsigned char *videomemory;
if (!board->init || !board->cleanup || !board->wait_for_rdy
|| !board->set_ctl || !board->set_hdb || !board->get_hdb
|| !board->setup_irq)
return -EINVAL;
info = framebuffer_alloc(sizeof(struct auok190xfb_par), &pdev->dev);
if (!info)
return -ENOMEM;
par = info->par;
par->info = info;
par->board = board;
par->recover = auok190x_recover;
par->update_partial = init->update_partial;
par->update_all = init->update_all;
par->need_refresh = init->need_refresh;
par->init = init->init;
par->update_cnt = 0;
par->update_mode = -1;
par->last_mode = -1;
par->flash = 0;
par->regulator = regulator_get(info->device, "vdd");
if (IS_ERR(par->regulator)) {
ret = PTR_ERR(par->regulator);
dev_err(info->device, "Failed to get regulator: %d\n", ret);
goto err_reg;
}
ret = board->init(par);
if (ret) {
dev_err(info->device, "board init failed, %d\n", ret);
goto err_board;
}
ret = gpio_request(board->gpio_nsleep, "AUOK190x sleep");
if (ret) {
dev_err(info->device, "could not request sleep gpio, %d\n",
ret);
goto err_gpio1;
}
ret = gpio_direction_output(board->gpio_nsleep, 0);
if (ret) {
dev_err(info->device, "could not set sleep gpio, %d\n", ret);
goto err_gpio2;
}
ret = gpio_request(board->gpio_nrst, "AUOK190x reset");
if (ret) {
dev_err(info->device, "could not request reset gpio, %d\n",
ret);
goto err_gpio2;
}
ret = gpio_direction_output(board->gpio_nrst, 0);
if (ret) {
dev_err(info->device, "could not set reset gpio, %d\n", ret);
goto err_gpio3;
}
ret = auok190x_power(par, 1);
if (ret) {
dev_err(info->device, "could not power on the device, %d\n",
ret);
goto err_gpio3;
}
mutex_init(&par->io_lock);
init_waitqueue_head(&par->waitq);
ret = par->board->setup_irq(par->info);
if (ret) {
dev_err(info->device, "could not setup ready-irq, %d\n", ret);
goto err_irq;
}
par->board->wait_for_rdy(par);
strlcpy(info->fix.id, init->id, 16);
info->var.bits_per_pixel = 8;
info->var.grayscale = 1;
panel = &panel_table[board->resolution];
par->resolution = board->resolution;
par->rotation = 0;
videomemorysize = roundup((panel->w * panel->h) * 2, PAGE_SIZE);
videomemory = vmalloc(videomemorysize);
if (!videomemory) {
ret = -ENOMEM;
goto err_irq;
}
memset(videomemory, 0, videomemorysize);
info->screen_base = (char *)videomemory;
info->fix.smem_len = videomemorysize;
info->flags = FBINFO_FLAG_DEFAULT | FBINFO_VIRTFB;
info->fbops = &auok190xfb_ops;
ret = auok190xfb_check_var(&info->var, info);
if (ret)
goto err_defio;
auok190xfb_set_fix(info);
info->fbdefio = devm_kzalloc(info->device,
sizeof(struct fb_deferred_io),
GFP_KERNEL);
if (!info->fbdefio) {
dev_err(info->device, "Failed to allocate memory\n");
ret = -ENOMEM;
goto err_defio;
}
dev_dbg(info->device, "targeting %d frames per second\n", board->fps);
info->fbdefio->delay = HZ / board->fps;
info->fbdefio->first_io = auok190xfb_dpy_first_io,
info->fbdefio->deferred_io = auok190xfb_dpy_deferred_io,
fb_deferred_io_init(info);
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret < 0) {
dev_err(info->device, "Failed to allocate colormap\n");
goto err_cmap;
}
par->consecutive_threshold = 100;
par->init(par);
auok190x_identify(par);
platform_set_drvdata(pdev, info);
ret = register_framebuffer(info);
if (ret < 0)
goto err_regfb;
ret = sysfs_create_group(&info->device->kobj, &auok190x_attr_group);
if (ret)
goto err_sysfs;
dev_info(info->device, "fb%d: %dx%d using %dK of video memory\n",
info->node, info->var.xres, info->var.yres,
videomemorysize >> 10);
par->autosuspend_delay = (board->quirks & AUOK190X_QUIRK_STANDBYBROKEN)
? 1000 : 200;
pm_runtime_set_active(info->device);
pm_runtime_enable(info->device);
pm_runtime_set_autosuspend_delay(info->device, par->autosuspend_delay);
pm_runtime_use_autosuspend(info->device);
return 0;
err_sysfs:
unregister_framebuffer(info);
err_regfb:
fb_dealloc_cmap(&info->cmap);
err_cmap:
fb_deferred_io_cleanup(info);
err_defio:
vfree((void *)info->screen_base);
err_irq:
auok190x_power(par, 0);
err_gpio3:
gpio_free(board->gpio_nrst);
err_gpio2:
gpio_free(board->gpio_nsleep);
err_gpio1:
board->cleanup(par);
err_board:
regulator_put(par->regulator);
err_reg:
framebuffer_release(info);
return ret;
}
int auok190x_common_remove(struct platform_device *pdev)
{
struct fb_info *info = platform_get_drvdata(pdev);
struct auok190xfb_par *par = info->par;
struct auok190x_board *board = par->board;
pm_runtime_disable(info->device);
sysfs_remove_group(&info->device->kobj, &auok190x_attr_group);
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
fb_deferred_io_cleanup(info);
vfree((void *)info->screen_base);
auok190x_power(par, 0);
gpio_free(board->gpio_nrst);
gpio_free(board->gpio_nsleep);
board->cleanup(par);
regulator_put(par->regulator);
framebuffer_release(info);
return 0;
}
