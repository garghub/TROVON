static void do_nokia_modem_rst_ind_tasklet(unsigned long data)
{
struct nokia_modem_device *modem = (struct nokia_modem_device *)data;
if (!modem)
return;
dev_info(modem->device, "CMT rst line change detected\n");
if (modem->ssi_protocol)
ssip_reset_event(modem->ssi_protocol);
}
static irqreturn_t nokia_modem_rst_ind_isr(int irq, void *data)
{
struct nokia_modem_device *modem = (struct nokia_modem_device *)data;
tasklet_schedule(&modem->nokia_modem_rst_ind_tasklet);
return IRQ_HANDLED;
}
static void nokia_modem_gpio_unexport(struct device *dev)
{
struct nokia_modem_device *modem = dev_get_drvdata(dev);
int i;
for (i = 0; i < modem->gpio_amount; i++) {
sysfs_remove_link(&dev->kobj, modem->gpios[i].name);
gpiod_unexport(modem->gpios[i].gpio);
}
}
static int nokia_modem_gpio_probe(struct device *dev)
{
struct device_node *np = dev->of_node;
struct nokia_modem_device *modem = dev_get_drvdata(dev);
int gpio_count, gpio_name_count, i, err;
gpio_count = of_gpio_count(np);
if (gpio_count < 0) {
dev_err(dev, "missing gpios: %d\n", gpio_count);
return gpio_count;
}
gpio_name_count = of_property_count_strings(np, "gpio-names");
if (gpio_count != gpio_name_count) {
dev_err(dev, "number of gpios does not equal number of gpio names\n");
return -EINVAL;
}
modem->gpios = devm_kzalloc(dev, gpio_count *
sizeof(struct nokia_modem_gpio), GFP_KERNEL);
if (!modem->gpios) {
dev_err(dev, "Could not allocate memory for gpios\n");
return -ENOMEM;
}
modem->gpio_amount = gpio_count;
for (i = 0; i < gpio_count; i++) {
modem->gpios[i].gpio = devm_gpiod_get_index(dev, NULL, i);
if (IS_ERR(modem->gpios[i].gpio)) {
dev_err(dev, "Could not get gpio %d\n", i);
return PTR_ERR(modem->gpios[i].gpio);
}
err = of_property_read_string_index(np, "gpio-names", i,
&(modem->gpios[i].name));
if (err) {
dev_err(dev, "Could not get gpio name %d\n", i);
return err;
}
err = gpiod_direction_output(modem->gpios[i].gpio, 0);
if (err)
return err;
err = gpiod_export(modem->gpios[i].gpio, 0);
if (err)
return err;
err = gpiod_export_link(dev, modem->gpios[i].name,
modem->gpios[i].gpio);
if (err)
return err;
}
return 0;
}
static int nokia_modem_probe(struct device *dev)
{
struct device_node *np;
struct nokia_modem_device *modem;
struct hsi_client *cl = to_hsi_client(dev);
struct hsi_port *port = hsi_get_port(cl);
int irq, pflags, err;
struct hsi_board_info ssip;
np = dev->of_node;
if (!np) {
dev_err(dev, "device tree node not found\n");
return -ENXIO;
}
modem = devm_kzalloc(dev, sizeof(*modem), GFP_KERNEL);
if (!modem) {
dev_err(dev, "Could not allocate memory for nokia_modem_device\n");
return -ENOMEM;
}
dev_set_drvdata(dev, modem);
irq = irq_of_parse_and_map(np, 0);
if (irq < 0) {
dev_err(dev, "Invalid rst_ind interrupt (%d)\n", irq);
return irq;
}
modem->nokia_modem_rst_ind_irq = irq;
pflags = irq_get_trigger_type(irq);
tasklet_init(&modem->nokia_modem_rst_ind_tasklet,
do_nokia_modem_rst_ind_tasklet, (unsigned long)modem);
err = devm_request_irq(dev, irq, nokia_modem_rst_ind_isr,
IRQF_DISABLED | pflags, "modem_rst_ind", modem);
if (err < 0) {
dev_err(dev, "Request rst_ind irq(%d) failed (flags %d)\n",
irq, pflags);
return err;
}
enable_irq_wake(irq);
if(pm) {
err = nokia_modem_gpio_probe(dev);
if (err < 0) {
dev_err(dev, "Could not probe GPIOs\n");
goto error1;
}
}
ssip.name = "ssi-protocol";
ssip.tx_cfg = cl->tx_cfg;
ssip.rx_cfg = cl->rx_cfg;
ssip.platform_data = NULL;
ssip.archdata = NULL;
modem->ssi_protocol = hsi_new_client(port, &ssip);
if (!modem->ssi_protocol) {
dev_err(dev, "Could not register ssi-protocol device\n");
goto error2;
}
err = device_attach(&modem->ssi_protocol->device);
if (err == 0) {
dev_err(dev, "Missing ssi-protocol driver\n");
err = -EPROBE_DEFER;
goto error3;
} else if (err < 0) {
dev_err(dev, "Could not load ssi-protocol driver (%d)\n", err);
goto error3;
}
dev_info(dev, "Registered Nokia HSI modem\n");
return 0;
error3:
hsi_remove_client(&modem->ssi_protocol->device, NULL);
error2:
nokia_modem_gpio_unexport(dev);
error1:
disable_irq_wake(modem->nokia_modem_rst_ind_irq);
tasklet_kill(&modem->nokia_modem_rst_ind_tasklet);
return err;
}
static int nokia_modem_remove(struct device *dev)
{
struct nokia_modem_device *modem = dev_get_drvdata(dev);
if (!modem)
return 0;
if (modem->ssi_protocol) {
hsi_remove_client(&modem->ssi_protocol->device, NULL);
modem->ssi_protocol = NULL;
}
nokia_modem_gpio_unexport(dev);
dev_set_drvdata(dev, NULL);
disable_irq_wake(modem->nokia_modem_rst_ind_irq);
tasklet_kill(&modem->nokia_modem_rst_ind_tasklet);
return 0;
}
static int __init nokia_modem_init(void)
{
return hsi_register_client_driver(&nokia_modem_driver);
}
static void __exit nokia_modem_exit(void)
{
hsi_unregister_client_driver(&nokia_modem_driver);
}
