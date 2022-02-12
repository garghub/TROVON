static void tgfx_timer(unsigned long private)
{
struct tgfx *tgfx = (void *) private;
struct input_dev *dev;
int data1, data2, i;
for (i = 0; i < 7; i++)
if (tgfx->sticks & (1 << i)) {
dev = tgfx->dev[i];
parport_write_data(tgfx->pd->port, ~(1 << i));
data1 = parport_read_status(tgfx->pd->port) ^ 0x7f;
data2 = parport_read_control(tgfx->pd->port) ^ 0x04;
input_report_abs(dev, ABS_X, !!(data1 & TGFX_RIGHT) - !!(data1 & TGFX_LEFT));
input_report_abs(dev, ABS_Y, !!(data1 & TGFX_DOWN ) - !!(data1 & TGFX_UP ));
input_report_key(dev, BTN_TRIGGER, (data1 & TGFX_TRIGGER));
input_report_key(dev, BTN_THUMB, (data2 & TGFX_THUMB ));
input_report_key(dev, BTN_THUMB2, (data2 & TGFX_THUMB2 ));
input_report_key(dev, BTN_TOP, (data2 & TGFX_TOP ));
input_report_key(dev, BTN_TOP2, (data2 & TGFX_TOP2 ));
input_sync(dev);
}
mod_timer(&tgfx->timer, jiffies + TGFX_REFRESH_TIME);
}
static int tgfx_open(struct input_dev *dev)
{
struct tgfx *tgfx = input_get_drvdata(dev);
int err;
err = mutex_lock_interruptible(&tgfx->sem);
if (err)
return err;
if (!tgfx->used++) {
parport_claim(tgfx->pd);
parport_write_control(tgfx->pd->port, 0x04);
mod_timer(&tgfx->timer, jiffies + TGFX_REFRESH_TIME);
}
mutex_unlock(&tgfx->sem);
return 0;
}
static void tgfx_close(struct input_dev *dev)
{
struct tgfx *tgfx = input_get_drvdata(dev);
mutex_lock(&tgfx->sem);
if (!--tgfx->used) {
del_timer_sync(&tgfx->timer);
parport_write_control(tgfx->pd->port, 0x00);
parport_release(tgfx->pd);
}
mutex_unlock(&tgfx->sem);
}
static void tgfx_attach(struct parport *pp)
{
struct tgfx *tgfx;
struct input_dev *input_dev;
struct pardevice *pd;
int i, j, port_idx;
int *n_buttons, n_devs;
struct pardev_cb tgfx_parport_cb;
for (port_idx = 0; port_idx < TGFX_MAX_PORTS; port_idx++) {
if (tgfx_cfg[port_idx].nargs == 0 ||
tgfx_cfg[port_idx].args[0] < 0)
continue;
if (tgfx_cfg[port_idx].args[0] == pp->number)
break;
}
if (port_idx == TGFX_MAX_PORTS) {
pr_debug("Not using parport%d.\n", pp->number);
return;
}
n_buttons = tgfx_cfg[port_idx].args + 1;
n_devs = tgfx_cfg[port_idx].nargs - 1;
memset(&tgfx_parport_cb, 0, sizeof(tgfx_parport_cb));
tgfx_parport_cb.flags = PARPORT_FLAG_EXCL;
pd = parport_register_dev_model(pp, "turbografx", &tgfx_parport_cb,
port_idx);
if (!pd) {
pr_err("parport busy already - lp.o loaded?\n");
return;
}
tgfx = kzalloc(sizeof(struct tgfx), GFP_KERNEL);
if (!tgfx) {
printk(KERN_ERR "turbografx.c: Not enough memory\n");
goto err_unreg_pardev;
}
mutex_init(&tgfx->sem);
tgfx->pd = pd;
tgfx->parportno = pp->number;
init_timer(&tgfx->timer);
tgfx->timer.data = (long) tgfx;
tgfx->timer.function = tgfx_timer;
for (i = 0; i < n_devs; i++) {
if (n_buttons[i] < 1)
continue;
if (n_buttons[i] > ARRAY_SIZE(tgfx_buttons)) {
printk(KERN_ERR "turbografx.c: Invalid number of buttons %d\n", n_buttons[i]);
goto err_unreg_devs;
}
tgfx->dev[i] = input_dev = input_allocate_device();
if (!input_dev) {
printk(KERN_ERR "turbografx.c: Not enough memory for input device\n");
goto err_unreg_devs;
}
tgfx->sticks |= (1 << i);
snprintf(tgfx->name[i], sizeof(tgfx->name[i]),
"TurboGraFX %d-button Multisystem joystick", n_buttons[i]);
snprintf(tgfx->phys[i], sizeof(tgfx->phys[i]),
"%s/input%d", tgfx->pd->port->name, i);
input_dev->name = tgfx->name[i];
input_dev->phys = tgfx->phys[i];
input_dev->id.bustype = BUS_PARPORT;
input_dev->id.vendor = 0x0003;
input_dev->id.product = n_buttons[i];
input_dev->id.version = 0x0100;
input_set_drvdata(input_dev, tgfx);
input_dev->open = tgfx_open;
input_dev->close = tgfx_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_set_abs_params(input_dev, ABS_X, -1, 1, 0, 0);
input_set_abs_params(input_dev, ABS_Y, -1, 1, 0, 0);
for (j = 0; j < n_buttons[i]; j++)
set_bit(tgfx_buttons[j], input_dev->keybit);
if (input_register_device(tgfx->dev[i]))
goto err_free_dev;
}
if (!tgfx->sticks) {
printk(KERN_ERR "turbografx.c: No valid devices specified\n");
goto err_free_tgfx;
}
tgfx_base[port_idx] = tgfx;
return;
err_free_dev:
input_free_device(tgfx->dev[i]);
err_unreg_devs:
while (--i >= 0)
if (tgfx->dev[i])
input_unregister_device(tgfx->dev[i]);
err_free_tgfx:
kfree(tgfx);
err_unreg_pardev:
parport_unregister_device(pd);
}
static void tgfx_detach(struct parport *port)
{
int i;
struct tgfx *tgfx;
for (i = 0; i < TGFX_MAX_PORTS; i++) {
if (tgfx_base[i] && tgfx_base[i]->parportno == port->number)
break;
}
if (i == TGFX_MAX_PORTS)
return;
tgfx = tgfx_base[i];
tgfx_base[i] = NULL;
for (i = 0; i < TGFX_MAX_DEVICES; i++)
if (tgfx->dev[i])
input_unregister_device(tgfx->dev[i]);
parport_unregister_device(tgfx->pd);
kfree(tgfx);
}
static int __init tgfx_init(void)
{
int i;
int have_dev = 0;
for (i = 0; i < TGFX_MAX_PORTS; i++) {
if (tgfx_cfg[i].nargs == 0 || tgfx_cfg[i].args[0] < 0)
continue;
if (tgfx_cfg[i].nargs < 2) {
printk(KERN_ERR "turbografx.c: at least one joystick must be specified\n");
return -EINVAL;
}
have_dev = 1;
}
if (!have_dev)
return -ENODEV;
return parport_register_driver(&tgfx_parport_driver);
}
static void __exit tgfx_exit(void)
{
parport_unregister_driver(&tgfx_parport_driver);
}
