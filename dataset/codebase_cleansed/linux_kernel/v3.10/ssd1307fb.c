static int ssd1307fb_write_array(struct i2c_client *client, u8 type, u8 *cmd, u32 len)
{
u8 *buf;
int ret = 0;
buf = kzalloc(len + 1, GFP_KERNEL);
if (!buf) {
dev_err(&client->dev, "Couldn't allocate sending buffer.\n");
return -ENOMEM;
}
buf[0] = type;
memcpy(buf + 1, cmd, len);
ret = i2c_master_send(client, buf, len + 1);
if (ret != len + 1) {
dev_err(&client->dev, "Couldn't send I2C command.\n");
goto error;
}
error:
kfree(buf);
return ret;
}
static inline int ssd1307fb_write_cmd_array(struct i2c_client *client, u8 *cmd, u32 len)
{
return ssd1307fb_write_array(client, SSD1307FB_COMMAND, cmd, len);
}
static inline int ssd1307fb_write_cmd(struct i2c_client *client, u8 cmd)
{
return ssd1307fb_write_cmd_array(client, &cmd, 1);
}
static inline int ssd1307fb_write_data_array(struct i2c_client *client, u8 *cmd, u32 len)
{
return ssd1307fb_write_array(client, SSD1307FB_DATA, cmd, len);
}
static inline int ssd1307fb_write_data(struct i2c_client *client, u8 data)
{
return ssd1307fb_write_data_array(client, &data, 1);
}
static void ssd1307fb_update_display(struct ssd1307fb_par *par)
{
u8 *vmem = par->info->screen_base;
int i, j, k;
for (i = 0; i < (SSD1307FB_HEIGHT / 8); i++) {
ssd1307fb_write_cmd(par->client, SSD1307FB_START_PAGE_ADDRESS + (i + 1));
ssd1307fb_write_cmd(par->client, 0x00);
ssd1307fb_write_cmd(par->client, 0x10);
for (j = 0; j < SSD1307FB_WIDTH; j++) {
u8 buf = 0;
for (k = 0; k < 8; k++) {
u32 page_length = SSD1307FB_WIDTH * i;
u32 index = page_length + (SSD1307FB_WIDTH * k + j) / 8;
u8 byte = *(vmem + index);
u8 bit = byte & (1 << (j % 8));
bit = bit >> (j % 8);
buf |= bit << k;
}
ssd1307fb_write_data(par->client, buf);
}
}
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
static int ssd1307fb_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct fb_info *info;
u32 vmem_size = SSD1307FB_WIDTH * SSD1307FB_HEIGHT / 8;
struct ssd1307fb_par *par;
u8 *vmem;
int ret;
if (!client->dev.of_node) {
dev_err(&client->dev, "No device tree data found!\n");
return -EINVAL;
}
info = framebuffer_alloc(sizeof(struct ssd1307fb_par), &client->dev);
if (!info) {
dev_err(&client->dev, "Couldn't allocate framebuffer.\n");
return -ENOMEM;
}
vmem = devm_kzalloc(&client->dev, vmem_size, GFP_KERNEL);
if (!vmem) {
dev_err(&client->dev, "Couldn't allocate graphical memory.\n");
ret = -ENOMEM;
goto fb_alloc_error;
}
info->fbops = &ssd1307fb_ops;
info->fix = ssd1307fb_fix;
info->fbdefio = &ssd1307fb_defio;
info->var = ssd1307fb_var;
info->var.red.length = 1;
info->var.red.offset = 0;
info->var.green.length = 1;
info->var.green.offset = 0;
info->var.blue.length = 1;
info->var.blue.offset = 0;
info->screen_base = (u8 __force __iomem *)vmem;
info->fix.smem_start = (unsigned long)vmem;
info->fix.smem_len = vmem_size;
fb_deferred_io_init(info);
par = info->par;
par->info = info;
par->client = client;
par->reset = of_get_named_gpio(client->dev.of_node,
"reset-gpios", 0);
if (!gpio_is_valid(par->reset)) {
ret = -EINVAL;
goto reset_oled_error;
}
ret = devm_gpio_request_one(&client->dev, par->reset,
GPIOF_OUT_INIT_HIGH,
"oled-reset");
if (ret) {
dev_err(&client->dev,
"failed to request gpio %d: %d\n",
par->reset, ret);
goto reset_oled_error;
}
par->pwm = pwm_get(&client->dev, NULL);
if (IS_ERR(par->pwm)) {
dev_err(&client->dev, "Could not get PWM from device tree!\n");
ret = PTR_ERR(par->pwm);
goto pwm_error;
}
par->pwm_period = pwm_get_period(par->pwm);
dev_dbg(&client->dev, "Using PWM%d with a %dns period.\n", par->pwm->pwm, par->pwm_period);
ret = register_framebuffer(info);
if (ret) {
dev_err(&client->dev, "Couldn't register the framebuffer\n");
goto fbreg_error;
}
i2c_set_clientdata(client, info);
gpio_set_value(par->reset, 0);
udelay(4);
gpio_set_value(par->reset, 1);
udelay(4);
pwm_config(par->pwm, par->pwm_period / 2, par->pwm_period);
pwm_enable(par->pwm);
ret = ssd1307fb_write_cmd(client, SSD1307FB_SEG_REMAP_ON);
if (ret < 0) {
dev_err(&client->dev, "Couldn't remap the screen.\n");
goto remap_error;
}
ret = ssd1307fb_write_cmd(client, SSD1307FB_DISPLAY_ON);
if (ret < 0) {
dev_err(&client->dev, "Couldn't turn the display on.\n");
goto remap_error;
}
dev_info(&client->dev, "fb%d: %s framebuffer device registered, using %d bytes of video memory\n", info->node, info->fix.id, vmem_size);
return 0;
remap_error:
unregister_framebuffer(info);
pwm_disable(par->pwm);
fbreg_error:
pwm_put(par->pwm);
pwm_error:
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
unregister_framebuffer(info);
pwm_disable(par->pwm);
pwm_put(par->pwm);
fb_deferred_io_cleanup(info);
framebuffer_release(info);
return 0;
}
