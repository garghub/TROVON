static void toshiba_request_vsync(struct msm_panel_data *panel_data,
struct msmfb_callback *callback)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
panel->toshiba_callback = callback;
if (panel->toshiba_got_int) {
panel->toshiba_got_int = 0;
client_data->activate_link(client_data);
}
}
static void toshiba_clear_vsync(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
client_data->activate_link(client_data);
}
static void toshiba_wait_vsync(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
if (panel->toshiba_got_int) {
panel->toshiba_got_int = 0;
client_data->activate_link(client_data);
}
if (wait_event_timeout(toshiba_vsync_wait, panel->toshiba_got_int,
HZ/2) == 0)
printk(KERN_ERR "timeout waiting for VSYNC\n");
panel->toshiba_got_int = 0;
}
static int toshiba_suspend(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
int ret;
ret = bridge_data->uninit(bridge_data, client_data);
if (ret) {
printk(KERN_INFO "mddi toshiba client: non zero return from "
"uninit\n");
return ret;
}
client_data->suspend(client_data);
return 0;
}
static int toshiba_resume(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
int ret;
client_data->resume(client_data);
ret = bridge_data->init(bridge_data, client_data);
if (ret)
return ret;
return 0;
}
static int toshiba_blank(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
return bridge_data->blank(bridge_data, client_data);
}
static int toshiba_unblank(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
return bridge_data->unblank(bridge_data, client_data);
}
irqreturn_t toshiba_vsync_interrupt(int irq, void *data)
{
struct panel_info *panel = data;
panel->toshiba_got_int = 1;
if (panel->toshiba_callback) {
panel->toshiba_callback->func(panel->toshiba_callback);
panel->toshiba_callback = 0;
}
wake_up(&toshiba_vsync_wait);
return IRQ_HANDLED;
}
static int setup_vsync(struct panel_info *panel,
int init)
{
int ret;
int gpio = 97;
unsigned int irq;
if (!init) {
ret = 0;
goto uninit;
}
ret = gpio_request_one(gpio, GPIOF_IN, "vsync");
if (ret)
goto err_request_gpio_failed;
ret = irq = gpio_to_irq(gpio);
if (ret < 0)
goto err_get_irq_num_failed;
ret = request_irq(irq, toshiba_vsync_interrupt, IRQF_TRIGGER_RISING,
"vsync", panel);
if (ret)
goto err_request_irq_failed;
printk(KERN_INFO "vsync on gpio %d now %d\n",
gpio, gpio_get_value(gpio));
return 0;
uninit:
free_irq(gpio_to_irq(gpio), panel);
err_request_irq_failed:
err_get_irq_num_failed:
gpio_free(gpio);
err_request_gpio_failed:
return ret;
}
static int mddi_toshiba_probe(struct platform_device *pdev)
{
int ret;
struct msm_mddi_client_data *client_data = pdev->dev.platform_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
struct panel_info *panel =
kzalloc(sizeof(struct panel_info), GFP_KERNEL);
if (!panel)
return -ENOMEM;
platform_set_drvdata(pdev, panel);
client_data->remote_write(client_data, GPIOSEL_VWAKEINT, GPIOSEL);
client_data->remote_write(client_data, INTMASK_VWAKEOUT, INTMASK);
ret = setup_vsync(panel, 1);
if (ret) {
dev_err(&pdev->dev, "mddi_bridge_setup_vsync failed\n");
return ret;
}
panel->client_data = client_data;
panel->panel_data.suspend = toshiba_suspend;
panel->panel_data.resume = toshiba_resume;
panel->panel_data.wait_vsync = toshiba_wait_vsync;
panel->panel_data.request_vsync = toshiba_request_vsync;
panel->panel_data.clear_vsync = toshiba_clear_vsync;
panel->panel_data.blank = toshiba_blank;
panel->panel_data.unblank = toshiba_unblank;
panel->panel_data.fb_data = &bridge_data->fb_data;
panel->panel_data.caps = MSMFB_CAP_PARTIAL_UPDATES;
panel->pdev.name = "msm_panel";
panel->pdev.id = pdev->id;
panel->pdev.resource = client_data->fb_resource;
panel->pdev.num_resources = 1;
panel->pdev.dev.platform_data = &panel->panel_data;
bridge_data->init(bridge_data, client_data);
platform_device_register(&panel->pdev);
return 0;
}
static int mddi_toshiba_remove(struct platform_device *pdev)
{
struct panel_info *panel = platform_get_drvdata(pdev);
setup_vsync(panel, 0);
kfree(panel);
return 0;
}
static int __init mddi_client_toshiba_init(void)
{
platform_driver_register(&mddi_client_d263_0000);
return 0;
}
