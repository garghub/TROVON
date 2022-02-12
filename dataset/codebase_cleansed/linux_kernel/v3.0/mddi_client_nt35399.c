static void
nt35399_request_vsync(struct msm_panel_data *panel_data,
struct msmfb_callback *callback)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
panel->fb_callback = callback;
if (panel->nt35399_got_int) {
panel->nt35399_got_int = 0;
client_data->activate_link(client_data);
}
}
static void nt35399_wait_vsync(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
if (panel->nt35399_got_int) {
panel->nt35399_got_int = 0;
client_data->activate_link(client_data);
}
if (wait_event_timeout(nt35399_vsync_wait, panel->nt35399_got_int,
HZ/2) == 0)
printk(KERN_ERR "timeout waiting for VSYNC\n");
panel->nt35399_got_int = 0;
}
static int nt35399_suspend(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
int ret;
ret = bridge_data->uninit(bridge_data, client_data);
if (ret) {
printk(KERN_INFO "mddi nt35399 client: non zero return from "
"uninit\n");
return ret;
}
client_data->suspend(client_data);
return 0;
}
static int nt35399_resume(struct msm_panel_data *panel_data)
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
static int nt35399_blank(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
return bridge_data->blank(bridge_data, client_data);
}
static int nt35399_unblank(struct msm_panel_data *panel_data)
{
struct panel_info *panel = container_of(panel_data, struct panel_info,
panel_data);
struct msm_mddi_client_data *client_data = panel->client_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
return bridge_data->unblank(bridge_data, client_data);
}
irqreturn_t nt35399_vsync_interrupt(int irq, void *data)
{
struct panel_info *panel = data;
panel->nt35399_got_int = 1;
if (panel->fb_callback) {
panel->fb_callback->func(panel->fb_callback);
panel->fb_callback = NULL;
}
wake_up(&nt35399_vsync_wait);
return IRQ_HANDLED;
}
static int setup_vsync(struct panel_info *panel, int init)
{
int ret;
int gpio = 97;
unsigned int irq;
if (!init) {
ret = 0;
goto uninit;
}
ret = gpio_request(gpio, "vsync");
if (ret)
goto err_request_gpio_failed;
ret = gpio_direction_input(gpio);
if (ret)
goto err_gpio_direction_input_failed;
ret = irq = gpio_to_irq(gpio);
if (ret < 0)
goto err_get_irq_num_failed;
ret = request_irq(irq, nt35399_vsync_interrupt, IRQF_TRIGGER_RISING,
"vsync", panel);
if (ret)
goto err_request_irq_failed;
printk(KERN_INFO "vsync on gpio %d now %d\n",
gpio, gpio_get_value(gpio));
return 0;
uninit:
free_irq(gpio_to_irq(gpio), panel->client_data);
err_request_irq_failed:
err_get_irq_num_failed:
err_gpio_direction_input_failed:
gpio_free(gpio);
err_request_gpio_failed:
return ret;
}
static int mddi_nt35399_probe(struct platform_device *pdev)
{
struct msm_mddi_client_data *client_data = pdev->dev.platform_data;
struct msm_mddi_bridge_platform_data *bridge_data =
client_data->private_client_data;
int ret;
struct panel_info *panel = kzalloc(sizeof(struct panel_info),
GFP_KERNEL);
printk(KERN_DEBUG "%s: enter.\n", __func__);
if (!panel)
return -ENOMEM;
platform_set_drvdata(pdev, panel);
ret = setup_vsync(panel, 1);
if (ret) {
dev_err(&pdev->dev, "mddi_nt35399_setup_vsync failed\n");
return ret;
}
panel->client_data = client_data;
panel->panel_data.suspend = nt35399_suspend;
panel->panel_data.resume = nt35399_resume;
panel->panel_data.wait_vsync = nt35399_wait_vsync;
panel->panel_data.request_vsync = nt35399_request_vsync;
panel->panel_data.blank = nt35399_blank;
panel->panel_data.unblank = nt35399_unblank;
panel->panel_data.fb_data = &bridge_data->fb_data;
panel->panel_data.caps = 0;
panel->pdev.name = "msm_panel";
panel->pdev.id = pdev->id;
panel->pdev.resource = client_data->fb_resource;
panel->pdev.num_resources = 1;
panel->pdev.dev.platform_data = &panel->panel_data;
if (bridge_data->init)
bridge_data->init(bridge_data, client_data);
platform_device_register(&panel->pdev);
return 0;
}
static int mddi_nt35399_remove(struct platform_device *pdev)
{
struct panel_info *panel = platform_get_drvdata(pdev);
setup_vsync(panel, 0);
kfree(panel);
return 0;
}
static int __init mddi_client_nt35399_init(void)
{
return platform_driver_register(&mddi_client_0bda_8a47);
}
