static struct ssd1307fb_array *ssd1307fb_alloc_array(u32 len, u8 type)
{
struct ssd1307fb_array *array;
array = kzalloc(sizeof(struct ssd1307fb_array) + len, GFP_KERNEL);
if (!array)
return NULL;
array->type = type;
return array;
}
static int ssd1307fb_write_array(struct i2c_client *client,
struct ssd1307fb_array *array, u32 len)
{
int ret;
len += sizeof(struct ssd1307fb_array);
ret = i2c_master_send(client, (u8 *)array, len);
if (ret != len) {
dev_err(&client->dev, "Couldn't send I2C command.\n");
return ret;
}
return 0;
}
static inline int ssd1307fb_write_cmd(struct i2c_client *client, u8 cmd)
{
struct ssd1307fb_array *array;
int ret;
array = ssd1307fb_alloc_array(1, SSD1307FB_COMMAND);
if (!array)
return -ENOMEM;
array->data[0] = cmd;
ret = ssd1307fb_write_array(client, array, 1);
kfree(array);
return ret;
}
static void ssd1307fb_update_display(struct ssd1307fb_par *par)
{
struct ssd1307fb_array *array;
u8 *vmem = par->info->screen_base;
int i, j, k;
array = ssd1307fb_alloc_array(par->width * par->height / 8,
SSD1307FB_DATA);
if (!array)
return;
for (i = 0; i < (par->height / 8); i++) {
for (j = 0; j < par->width; j++) {
u32 array_idx = i * par->width + j;
array->data[array_idx] = 0;
for (k = 0; k < 8; k++) {
u32 page_length = par->width * i;
u32 index = page_length + (par->width * k + j) / 8;
u8 byte = *(vmem + index);
u8 bit = byte & (1 << (j % 8));
bit = bit >> (j % 8);
array->data[array_idx] |= bit << k;
}
}
}
ssd1307fb_write_array(par->client, array, par->width * par->height / 8);
kfree(array);
}
static ssize_t ssd1307fb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
struct ssd1307fb_par *par = info->par;
unsigned long total_size;
unsigned long p = *ppos;
u8 __iomem *dst;
total_size = info->fix.smem_len;
if (p > total_size)
return -EINVAL;
if (count + p > total_size)
count = total_size - p;
if (!count)
return -EINVAL;
dst = (void __force *) (info->screen_base + p);
if (copy_from_user(dst, buf, count))
return -EFAULT;
ssd1307fb_update_display(par);
*ppos += count;
return count;
}
static int ssd1307fb_blank(int blank_mode, struct fb_info *info)
{
struct ssd1307fb_par *par = info->par;
if (blank_mode != FB_BLANK_UNBLANK)
return ssd1307fb_write_cmd(par->client, SSD1307FB_DISPLAY_OFF);
else
return ssd1307fb_write_cmd(par->client, SSD1307FB_DISPLAY_ON);
}
static void ssd1307fb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct ssd1307fb_par *par = info->par;
sys_fillrect(info, rect);
ssd1307fb_update_display(par);
}
static void ssd1307fb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct ssd1307fb_par *par = info->par;
sys_copyarea(info, area);
ssd1307fb_update_display(par);
}
static void ssd1307fb_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct ssd1307fb_par *par = info->par;
sys_imageblit(info, image);
ssd1307fb_update_display(par);
}
static void ssd1307fb_deferred_io(struct fb_info *info,
struct list_head *pagelist)
{
ssd1307fb_update_display(info->par);
}
static int ssd1307fb_init(struct ssd1307fb_par *par)
{
int ret;
u32 precharge, dclk, com_invdir, compins;
struct pwm_args pargs;
if (par->device_info->need_pwm) {
par->pwm = pwm_get(&par->client->dev, NULL);
if (IS_ERR(par->pwm)) {
dev_err(&par->client->dev, "Could not get PWM from device tree!\n");
return PTR_ERR(par->pwm);
}
pwm_apply_args(par->pwm);
pwm_get_args(par->pwm, &pargs);
par->pwm_period = pargs.period;
pwm_config(par->pwm, par->pwm_period / 2, par->pwm_period);
pwm_enable(par->pwm);
dev_dbg(&par->client->dev, "Using PWM%d with a %dns period.\n",
par->pwm->pwm, par->pwm_period);
};
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_CONTRAST);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, par->contrast);
if (ret < 0)
return ret;
if (par->seg_remap) {
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SEG_REMAP_ON);
if (ret < 0)
return ret;
};
com_invdir = 0xc0 | (par->com_invdir & 0x1) << 3;
ret = ssd1307fb_write_cmd(par->client, com_invdir);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_MULTIPLEX_RATIO);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, par->height - 1);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_DISPLAY_OFFSET);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, par->com_offset);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_CLOCK_FREQ);
if (ret < 0)
return ret;
dclk = ((par->dclk_div - 1) & 0xf) | (par->dclk_frq & 0xf) << 4;
ret = ssd1307fb_write_cmd(par->client, dclk);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_PRECHARGE_PERIOD);
if (ret < 0)
return ret;
precharge = (par->prechargep1 & 0xf) | (par->prechargep2 & 0xf) << 4;
ret = ssd1307fb_write_cmd(par->client, precharge);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_COM_PINS_CONFIG);
if (ret < 0)
return ret;
compins = 0x02 | !(par->com_seq & 0x1) << 4
| (par->com_lrremap & 0x1) << 5;
ret = ssd1307fb_write_cmd(par->client, compins);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_VCOMH);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, par->vcomh);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_CHARGE_PUMP);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client,
BIT(4) | (par->device_info->need_chargepump ? BIT(2) : 0));
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_ADDRESS_MODE);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client,
SSD1307FB_SET_ADDRESS_MODE_HORIZONTAL);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_COL_RANGE);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, 0x0);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, par->width - 1);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_SET_PAGE_RANGE);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, 0x0);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client,
par->page_offset + (par->height / 8) - 1);
if (ret < 0)
return ret;
ssd1307fb_update_display(par);
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_DISPLAY_ON);
if (ret < 0)
return ret;
return 0;
}
static int ssd1307fb_update_bl(struct backlight_device *bdev)
{
struct ssd1307fb_par *par = bl_get_data(bdev);
int ret;
int brightness = bdev->props.brightness;
par->contrast = brightness;
ret = ssd1307fb_write_cmd(par->client, SSD1307FB_CONTRAST);
if (ret < 0)
return ret;
ret = ssd1307fb_write_cmd(par->client, par->contrast);
if (ret < 0)
return ret;
return 0;
}
static int ssd1307fb_get_brightness(struct backlight_device *bdev)
{
struct ssd1307fb_par *par = bl_get_data(bdev);
return par->contrast;
}
static int ssd1307fb_check_fb(struct backlight_device *bdev,
struct fb_info *info)
{
return (info->bl_dev == bdev);
}
static int ssd1307fb_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct backlight_device *bl;
char bl_name[12];
struct fb_info *info;
struct device_node *node = client->dev.of_node;
struct fb_deferred_io *ssd1307fb_defio;
u32 vmem_size;
struct ssd1307fb_par *par;
u8 *vmem;
int ret;
if (!node) {
dev_err(&client->dev, "No device tree data found!\n");
return -EINVAL;
}
info = framebuffer_alloc(sizeof(struct ssd1307fb_par), &client->dev);
if (!info) {
dev_err(&client->dev, "Couldn't allocate framebuffer.\n");
return -ENOMEM;
}
par = info->par;
par->info = info;
par->client = client;
par->device_info = of_device_get_match_data(&client->dev);
par->reset = devm_gpiod_get_optional(&client->dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(par->reset)) {
dev_err(&client->dev, "failed to get reset gpio: %ld\n",
PTR_ERR(par->reset));
ret = PTR_ERR(par->reset);
goto fb_alloc_error;
}
par->vbat_reg = devm_regulator_get_optional(&client->dev, "vbat");
if (IS_ERR(par->vbat_reg)) {
ret = PTR_ERR(par->vbat_reg);
if (ret == -ENODEV) {
par->vbat_reg = NULL;
} else {
dev_err(&client->dev, "failed to get VBAT regulator: %d\n",
ret);
goto fb_alloc_error;
}
}
if (of_property_read_u32(node, "solomon,width", &par->width))
par->width = 96;
if (of_property_read_u32(node, "solomon,height", &par->height))
par->height = 16;
if (of_property_read_u32(node, "solomon,page-offset", &par->page_offset))
par->page_offset = 1;
if (of_property_read_u32(node, "solomon,com-offset", &par->com_offset))
par->com_offset = 0;
if (of_property_read_u32(node, "solomon,prechargep1", &par->prechargep1))
par->prechargep1 = 2;
if (of_property_read_u32(node, "solomon,prechargep2", &par->prechargep2))
par->prechargep2 = 2;
par->seg_remap = !of_property_read_bool(node, "solomon,segment-no-remap");
par->com_seq = of_property_read_bool(node, "solomon,com-seq");
par->com_lrremap = of_property_read_bool(node, "solomon,com-lrremap");
par->com_invdir = of_property_read_bool(node, "solomon,com-invdir");
par->contrast = 127;
par->vcomh = par->device_info->default_vcomh;
par->dclk_div = par->device_info->default_dclk_div;
par->dclk_frq = par->device_info->default_dclk_frq;
vmem_size = par->width * par->height / 8;
vmem = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(vmem_size));
if (!vmem) {
dev_err(&client->dev, "Couldn't allocate graphical memory.\n");
ret = -ENOMEM;
goto fb_alloc_error;
}
ssd1307fb_defio = devm_kzalloc(&client->dev, sizeof(struct fb_deferred_io), GFP_KERNEL);
if (!ssd1307fb_defio) {
dev_err(&client->dev, "Couldn't allocate deferred io.\n");
ret = -ENOMEM;
goto fb_alloc_error;
}
ssd1307fb_defio->delay = HZ / refreshrate;
ssd1307fb_defio->deferred_io = ssd1307fb_deferred_io;
info->fbops = &ssd1307fb_ops;
info->fix = ssd1307fb_fix;
info->fix.line_length = par->width / 8;
info->fbdefio = ssd1307fb_defio;
info->var = ssd1307fb_var;
info->var.xres = par->width;
info->var.xres_virtual = par->width;
info->var.yres = par->height;
info->var.yres_virtual = par->height;
info->var.red.length = 1;
info->var.red.offset = 0;
info->var.green.length = 1;
info->var.green.offset = 0;
info->var.blue.length = 1;
info->var.blue.offset = 0;
info->screen_base = (u8 __force __iomem *)vmem;
info->fix.smem_start = __pa(vmem);
info->fix.smem_len = vmem_size;
fb_deferred_io_init(info);
i2c_set_clientdata(client, info);
if (par->reset) {
gpiod_set_value(par->reset, 0);
udelay(4);
gpiod_set_value(par->reset, 1);
udelay(4);
}
if (par->vbat_reg) {
ret = regulator_enable(par->vbat_reg);
if (ret) {
dev_err(&client->dev, "failed to enable VBAT: %d\n",
ret);
goto reset_oled_error;
}
}
ret = ssd1307fb_init(par);
if (ret)
goto regulator_enable_error;
ret = register_framebuffer(info);
if (ret) {
dev_err(&client->dev, "Couldn't register the framebuffer\n");
goto panel_init_error;
}
snprintf(bl_name, sizeof(bl_name), "ssd1307fb%d", info->node);
bl = backlight_device_register(bl_name, &client->dev, par,
&ssd1307fb_bl_ops, NULL);
if (IS_ERR(bl)) {
ret = PTR_ERR(bl);
dev_err(&client->dev, "unable to register backlight device: %d\n",
ret);
goto bl_init_error;
}
bl->props.brightness = par->contrast;
bl->props.max_brightness = MAX_CONTRAST;
info->bl_dev = bl;
dev_info(&client->dev, "fb%d: %s framebuffer device registered, using %d bytes of video memory\n", info->node, info->fix.id, vmem_size);
return 0;
bl_init_error:
unregister_framebuffer(info);
panel_init_error:
if (par->device_info->need_pwm) {
pwm_disable(par->pwm);
pwm_put(par->pwm);
};
regulator_enable_error:
if (par->vbat_reg)
regulator_disable(par->vbat_reg);
reset_oled_error:
fb_deferred_io_cleanup(info);
fb_alloc_error:
framebuffer_release(info);
return ret;
}
static int ssd1307fb_remove(struct i2c_client *client)
{
struct fb_info *info = i2c_get_clientdata(client);
struct ssd1307fb_par *par = info->par;
ssd1307fb_write_cmd(par->client, SSD1307FB_DISPLAY_OFF);
backlight_device_unregister(info->bl_dev);
unregister_framebuffer(info);
if (par->device_info->need_pwm) {
pwm_disable(par->pwm);
pwm_put(par->pwm);
};
fb_deferred_io_cleanup(info);
__free_pages(__va(info->fix.smem_start), get_order(info->fix.smem_len));
framebuffer_release(info);
return 0;
}
