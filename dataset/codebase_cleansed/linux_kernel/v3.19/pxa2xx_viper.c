static inline struct arcom_pcmcia_pdata *viper_get_pdata(void)
{
return arcom_pcmcia_dev->dev.platform_data;
}
static int viper_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
struct arcom_pcmcia_pdata *pdata = viper_get_pdata();
unsigned long flags;
skt->stat[SOC_STAT_CD].gpio = pdata->cd_gpio;
skt->stat[SOC_STAT_CD].name = "PCMCIA_CD";
skt->stat[SOC_STAT_RDY].gpio = pdata->rdy_gpio;
skt->stat[SOC_STAT_RDY].name = "CF ready";
if (gpio_request(pdata->pwr_gpio, "CF power"))
goto err_request_pwr;
local_irq_save(flags);
if (gpio_direction_output(pdata->pwr_gpio, 0)) {
local_irq_restore(flags);
goto err_dir;
}
local_irq_restore(flags);
return 0;
err_dir:
gpio_free(pdata->pwr_gpio);
err_request_pwr:
dev_err(&arcom_pcmcia_dev->dev, "Failed to setup PCMCIA GPIOs\n");
return -1;
}
static void viper_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
struct arcom_pcmcia_pdata *pdata = viper_get_pdata();
gpio_free(pdata->pwr_gpio);
}
static void viper_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int viper_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
struct arcom_pcmcia_pdata *pdata = viper_get_pdata();
pdata->reset(state->flags & SS_RESET);
switch (state->Vcc) {
case 0:
gpio_set_value(pdata->pwr_gpio, 0);
break;
case 33:
gpio_set_value(pdata->pwr_gpio, 1);
break;
default:
dev_err(&arcom_pcmcia_dev->dev, "Unsupported Vcc:%d\n", state->Vcc);
return -1;
}
return 0;
}
static int viper_pcmcia_probe(struct platform_device *pdev)
{
int ret;
if (arcom_pcmcia_dev)
return -EEXIST;
if (!pdev->dev.platform_data)
return -EINVAL;
viper_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!viper_pcmcia_device)
return -ENOMEM;
arcom_pcmcia_dev = pdev;
viper_pcmcia_device->dev.parent = &pdev->dev;
ret = platform_device_add_data(viper_pcmcia_device,
&viper_pcmcia_ops,
sizeof(viper_pcmcia_ops));
if (!ret)
ret = platform_device_add(viper_pcmcia_device);
if (ret) {
platform_device_put(viper_pcmcia_device);
arcom_pcmcia_dev = NULL;
}
return ret;
}
static int viper_pcmcia_remove(struct platform_device *pdev)
{
platform_device_unregister(viper_pcmcia_device);
arcom_pcmcia_dev = NULL;
return 0;
}
