static int am200_init_gpio_regs(struct metronomefb_par *par)
{
int i;
int err;
for (i = 0; i < ARRAY_SIZE(gpios); i++) {
err = gpio_request(gpios[i], gpio_names[i]);
if (err) {
dev_err(&am200_device->dev, "failed requesting "
"gpio %s, err=%d\n", gpio_names[i], err);
goto err_req_gpio;
}
}
gpio_direction_output(LED_GPIO_PIN, 0);
gpio_direction_output(STDBY_GPIO_PIN, 0);
gpio_direction_output(RST_GPIO_PIN, 0);
gpio_direction_input(RDY_GPIO_PIN);
gpio_direction_input(ERR_GPIO_PIN);
gpio_direction_output(PCBPWR_GPIO_PIN, 0);
return 0;
err_req_gpio:
while (--i >= 0)
gpio_free(gpios[i]);
return err;
}
static void am200_cleanup(struct metronomefb_par *par)
{
int i;
free_irq(PXA_GPIO_TO_IRQ(RDY_GPIO_PIN), par);
for (i = 0; i < ARRAY_SIZE(gpios); i++)
gpio_free(gpios[i]);
}
static int am200_share_video_mem(struct fb_info *info)
{
if ((info->var.xres != am200_fb_info.modes->xres)
|| (info->var.yres != am200_fb_info.modes->yres))
return 0;
am200_board.metromem = info->screen_base;
am200_board.host_fbinfo = info;
if (!try_module_get(info->fbops->owner))
return -ENODEV;
return 0;
}
static int am200_unshare_video_mem(struct fb_info *info)
{
dev_dbg(&am200_device->dev, "ENTER %s\n", __func__);
if (info != am200_board.host_fbinfo)
return 0;
module_put(am200_board.host_fbinfo->fbops->owner);
return 0;
}
static int am200_fb_notifier_callback(struct notifier_block *self,
unsigned long event, void *data)
{
struct fb_event *evdata = data;
struct fb_info *info = evdata->info;
dev_dbg(&am200_device->dev, "ENTER %s\n", __func__);
if (event == FB_EVENT_FB_REGISTERED)
return am200_share_video_mem(info);
else if (event == FB_EVENT_FB_UNREGISTERED)
return am200_unshare_video_mem(info);
return 0;
}
static void __init am200_presetup_fb(void)
{
int fw;
int fh;
int padding_size;
int totalsize;
switch (panel_type) {
case 6:
am200_fb_info.modes = &am200_fb_mode_6inch;
break;
case 8:
am200_fb_info.modes = &am200_fb_mode_8inch;
break;
case 97:
am200_fb_info.modes = &am200_fb_mode_9inch7;
break;
default:
dev_err(&am200_device->dev, "invalid panel_type selection,"
" setting to 6\n");
am200_fb_info.modes = &am200_fb_mode_6inch;
break;
}
fw = am200_fb_info.modes->xres;
fh = am200_fb_info.modes->yres;
am200_board.wfm_size = roundup(16*1024 + 2, fw);
padding_size = PAGE_SIZE + (4 * fw);
totalsize = fw + am200_board.wfm_size + padding_size + (fw*fh);
am200_board.fw = fw;
am200_board.fh = fh;
am200_fb_info.modes->yres = DIV_ROUND_UP(totalsize, fw);
am200_fb_info.modes->xres /= 2;
pxa_set_fb_info(NULL, &am200_fb_info);
}
static int am200_setup_fb(struct metronomefb_par *par)
{
int fw;
int fh;
fw = am200_board.fw;
fh = am200_board.fh;
par->metromem_cmd = (struct metromem_cmd *) am200_board.metromem;
par->metromem_wfm = am200_board.metromem + fw;
par->metromem_img = par->metromem_wfm + am200_board.wfm_size;
par->metromem_img_csum = (u16 *) (par->metromem_img + (fw * fh));
par->metromem_dma = am200_board.host_fbinfo->fix.smem_start;
return 0;
}
static int am200_get_panel_type(void)
{
return panel_type;
}
static irqreturn_t am200_handle_irq(int irq, void *dev_id)
{
struct metronomefb_par *par = dev_id;
wake_up_interruptible(&par->waitq);
return IRQ_HANDLED;
}
static int am200_setup_irq(struct fb_info *info)
{
int ret;
ret = request_irq(PXA_GPIO_TO_IRQ(RDY_GPIO_PIN), am200_handle_irq,
IRQF_TRIGGER_FALLING, "AM200", info->par);
if (ret)
dev_err(&am200_device->dev, "request_irq failed: %d\n", ret);
return ret;
}
static void am200_set_rst(struct metronomefb_par *par, int state)
{
gpio_set_value(RST_GPIO_PIN, state);
}
static void am200_set_stdby(struct metronomefb_par *par, int state)
{
gpio_set_value(STDBY_GPIO_PIN, state);
}
static int am200_wait_event(struct metronomefb_par *par)
{
return wait_event_timeout(par->waitq, gpio_get_value(RDY_GPIO_PIN), HZ);
}
static int am200_wait_event_intr(struct metronomefb_par *par)
{
return wait_event_interruptible_timeout(par->waitq,
gpio_get_value(RDY_GPIO_PIN), HZ);
}
int __init am200_init(void)
{
int ret;
fb_register_client(&am200_fb_notif);
pxa2xx_mfp_config(ARRAY_AND_SIZE(am200_pin_config));
request_module("metronomefb");
am200_device = platform_device_alloc("metronomefb", -1);
if (!am200_device)
return -ENOMEM;
platform_device_add_data(am200_device, &am200_board,
sizeof(am200_board));
ret = platform_device_add(am200_device);
if (ret) {
platform_device_put(am200_device);
fb_unregister_client(&am200_fb_notif);
return ret;
}
am200_presetup_fb();
return 0;
}
