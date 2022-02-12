static int am300_wait_event(struct broadsheetfb_par *par)
{
wait_event(par->waitq, gpio_get_value(RDY_GPIO_PIN));
return 0;
}
static int am300_init_gpio_regs(struct broadsheetfb_par *par)
{
int i;
int err;
char dbname[8];
for (i = 0; i < ARRAY_SIZE(gpios); i++) {
err = gpio_request(gpios[i], gpio_names[i]);
if (err) {
dev_err(&am300_device->dev, "failed requesting "
"gpio %s, err=%d\n", gpio_names[i], err);
goto err_req_gpio;
}
}
for (i = DB0_GPIO_PIN; i <= DB15_GPIO_PIN; i++) {
sprintf(dbname, "DB%d", i);
err = gpio_request(i, dbname);
if (err) {
dev_err(&am300_device->dev, "failed requesting "
"gpio %d, err=%d\n", i, err);
goto err_req_gpio2;
}
}
gpio_direction_output(PWR_GPIO_PIN, 0);
gpio_direction_output(CFG_GPIO_PIN, 1);
gpio_direction_output(DC_GPIO_PIN, 0);
gpio_direction_output(RD_GPIO_PIN, 1);
gpio_direction_output(WR_GPIO_PIN, 1);
gpio_direction_output(CS_GPIO_PIN, 1);
gpio_direction_output(RST_GPIO_PIN, 0);
gpio_direction_input(RDY_GPIO_PIN);
gpio_direction_input(IRQ_GPIO_PIN);
for (i = DB0_GPIO_PIN; i <= DB15_GPIO_PIN; i++)
gpio_direction_output(i, 0);
gpio_set_value(CFG_GPIO_PIN, 1);
gpio_set_value(RST_GPIO_PIN, 0);
msleep(10);
gpio_set_value(RST_GPIO_PIN, 1);
msleep(10);
am300_wait_event(par);
return 0;
err_req_gpio2:
while (--i >= DB0_GPIO_PIN)
gpio_free(i);
i = ARRAY_SIZE(gpios);
err_req_gpio:
while (--i >= 0)
gpio_free(gpios[i]);
return err;
}
static int am300_init_board(struct broadsheetfb_par *par)
{
return am300_init_gpio_regs(par);
}
static void am300_cleanup(struct broadsheetfb_par *par)
{
int i;
free_irq(IRQ_GPIO(RDY_GPIO_PIN), par);
for (i = 0; i < ARRAY_SIZE(gpios); i++)
gpio_free(gpios[i]);
for (i = DB0_GPIO_PIN; i <= DB15_GPIO_PIN; i++)
gpio_free(i);
}
static u16 am300_get_hdb(struct broadsheetfb_par *par)
{
u16 res = 0;
int i;
for (i = 0; i <= (DB15_GPIO_PIN - DB0_GPIO_PIN) ; i++)
res |= (gpio_get_value(DB0_GPIO_PIN + i)) ? (1 << i) : 0;
return res;
}
static void am300_set_hdb(struct broadsheetfb_par *par, u16 data)
{
int i;
for (i = 0; i <= (DB15_GPIO_PIN - DB0_GPIO_PIN) ; i++)
gpio_set_value(DB0_GPIO_PIN + i, (data >> i) & 0x01);
}
static void am300_set_ctl(struct broadsheetfb_par *par, unsigned char bit,
u8 state)
{
switch (bit) {
case BS_CS:
gpio_set_value(CS_GPIO_PIN, state);
break;
case BS_DC:
gpio_set_value(DC_GPIO_PIN, state);
break;
case BS_WR:
gpio_set_value(WR_GPIO_PIN, state);
break;
}
}
static int am300_get_panel_type(void)
{
return panel_type;
}
static irqreturn_t am300_handle_irq(int irq, void *dev_id)
{
struct broadsheetfb_par *par = dev_id;
wake_up(&par->waitq);
return IRQ_HANDLED;
}
static int am300_setup_irq(struct fb_info *info)
{
int ret;
struct broadsheetfb_par *par = info->par;
ret = request_irq(IRQ_GPIO(RDY_GPIO_PIN), am300_handle_irq,
IRQF_DISABLED|IRQF_TRIGGER_RISING,
"AM300", par);
if (ret)
dev_err(&am300_device->dev, "request_irq failed: %d\n", ret);
return ret;
}
int __init am300_init(void)
{
int ret;
pxa2xx_mfp_config(ARRAY_AND_SIZE(am300_pin_config));
request_module("broadsheetfb");
am300_device = platform_device_alloc("broadsheetfb", -1);
if (!am300_device)
return -ENOMEM;
platform_device_add_data(am300_device, &am300_board,
sizeof(am300_board));
ret = platform_device_add(am300_device);
if (ret) {
platform_device_put(am300_device);
return ret;
}
return 0;
}
