static s32 dcon_write(struct dcon_priv *dcon, u8 reg, u16 val)
{
return i2c_smbus_write_word_data(dcon->client, reg, val);
}
static s32 dcon_read(struct dcon_priv *dcon, u8 reg)
{
return i2c_smbus_read_word_data(dcon->client, reg);
}
static int dcon_hw_init(struct dcon_priv *dcon, int is_init)
{
uint16_t ver;
int rc = 0;
ver = dcon_read(dcon, DCON_REG_ID);
if ((ver >> 8) != 0xDC) {
pr_err("DCON ID not 0xDCxx: 0x%04x instead.\n", ver);
rc = -ENXIO;
goto err;
}
if (is_init) {
pr_info("Discovered DCON version %x\n", ver & 0xFF);
rc = pdata->init(dcon);
if (rc != 0) {
pr_err("Unable to init.\n");
goto err;
}
}
if (ver < 0xdc02) {
dev_err(&dcon->client->dev,
"DCON v1 is unsupported, giving up..\n");
rc = -ENODEV;
goto err;
}
dcon_write(dcon, 0x3a, 0xc040);
dcon_write(dcon, 0x41, 0x0000);
dcon_write(dcon, 0x41, 0x0101);
dcon_write(dcon, 0x42, 0x0101);
if (is_init) {
dcon->disp_mode = MODE_PASSTHRU | MODE_BL_ENABLE |
MODE_CSWIZZLE | MODE_COL_AA;
}
dcon_write(dcon, DCON_REG_MODE, dcon->disp_mode);
dcon_write(dcon, DCON_REG_SCAN_INT, resumeline);
err:
return rc;
}
static int dcon_bus_stabilize(struct dcon_priv *dcon, int is_powered_down)
{
unsigned long timeout;
int x;
power_up:
if (is_powered_down) {
x = 1;
x = olpc_ec_cmd(0x26, (unsigned char *)&x, 1, NULL, 0);
if (x) {
pr_warn("unable to force dcon to power up: %d!\n", x);
return x;
}
msleep(10);
}
pdata->bus_stabilize_wiggle();
for (x = -1, timeout = 50; timeout && x < 0; timeout--) {
msleep(1);
x = dcon_read(dcon, DCON_REG_ID);
}
if (x < 0) {
pr_err("unable to stabilize dcon's smbus, reasserting power and praying.\n");
BUG_ON(olpc_board_at_least(olpc_board(0xc2)));
x = 0;
olpc_ec_cmd(0x26, (unsigned char *)&x, 1, NULL, 0);
msleep(100);
is_powered_down = 1;
goto power_up;
}
if (is_powered_down)
return dcon_hw_init(dcon, 0);
return 0;
}
static void dcon_set_backlight(struct dcon_priv *dcon, u8 level)
{
dcon->bl_val = level;
dcon_write(dcon, DCON_REG_BRIGHT, dcon->bl_val);
if (dcon->bl_val == 0) {
dcon->disp_mode &= ~MODE_BL_ENABLE;
dcon_write(dcon, DCON_REG_MODE, dcon->disp_mode);
} else if (!(dcon->disp_mode & MODE_BL_ENABLE)) {
dcon->disp_mode |= MODE_BL_ENABLE;
dcon_write(dcon, DCON_REG_MODE, dcon->disp_mode);
}
}
static int dcon_set_mono_mode(struct dcon_priv *dcon, bool enable_mono)
{
if (dcon->mono == enable_mono)
return 0;
dcon->mono = enable_mono;
if (enable_mono) {
dcon->disp_mode &= ~(MODE_CSWIZZLE | MODE_COL_AA);
dcon->disp_mode |= MODE_MONO_LUMA;
} else {
dcon->disp_mode &= ~(MODE_MONO_LUMA);
dcon->disp_mode |= MODE_CSWIZZLE | MODE_COL_AA;
}
dcon_write(dcon, DCON_REG_MODE, dcon->disp_mode);
return 0;
}
static void dcon_sleep(struct dcon_priv *dcon, bool sleep)
{
int x;
if (dcon->asleep == sleep)
return;
if (!olpc_board_at_least(olpc_board(0xc2)))
return;
if (sleep) {
x = 0;
x = olpc_ec_cmd(0x26, (unsigned char *)&x, 1, NULL, 0);
if (x)
pr_warn("unable to force dcon to power down: %d!\n", x);
else
dcon->asleep = sleep;
} else {
if (dcon->bl_val != 0)
dcon->disp_mode |= MODE_BL_ENABLE;
x = dcon_bus_stabilize(dcon, 1);
if (x)
pr_warn("unable to reinit dcon hardware: %d!\n", x);
else
dcon->asleep = sleep;
dcon_set_backlight(dcon, dcon->bl_val);
}
}
static void dcon_load_holdoff(struct dcon_priv *dcon)
{
struct timespec delta_t, now;
while (1) {
getnstimeofday(&now);
delta_t = timespec_sub(now, dcon->load_time);
if (delta_t.tv_sec != 0 ||
delta_t.tv_nsec > NSEC_PER_MSEC * 20) {
break;
}
mdelay(4);
}
}
static bool dcon_blank_fb(struct dcon_priv *dcon, bool blank)
{
int err;
if (!lock_fb_info(dcon->fbinfo)) {
dev_err(&dcon->client->dev, "unable to lock framebuffer\n");
return false;
}
console_lock();
dcon->ignore_fb_events = true;
err = fb_blank(dcon->fbinfo,
blank ? FB_BLANK_POWERDOWN : FB_BLANK_UNBLANK);
dcon->ignore_fb_events = false;
console_unlock();
unlock_fb_info(dcon->fbinfo);
if (err) {
dev_err(&dcon->client->dev, "couldn't %sblank framebuffer\n",
blank ? "" : "un");
return false;
}
return true;
}
static void dcon_source_switch(struct work_struct *work)
{
struct dcon_priv *dcon = container_of(work, struct dcon_priv,
switch_source);
int source = dcon->pending_src;
if (dcon->curr_src == source)
return;
dcon_load_holdoff(dcon);
dcon->switched = false;
switch (source) {
case DCON_SOURCE_CPU:
pr_info("dcon_source_switch to CPU\n");
if (dcon_write(dcon, DCON_REG_MODE,
dcon->disp_mode | MODE_SCAN_INT))
pr_err("couldn't enable scanline interrupt!\n");
else
wait_event_timeout(dcon->waitq, dcon->switched, HZ);
if (!dcon->switched)
pr_err("Timeout entering CPU mode; expect a screen glitch.\n");
if (dcon_write(dcon, DCON_REG_MODE, dcon->disp_mode))
pr_err("couldn't disable scanline interrupt!\n");
if (!dcon_blank_fb(dcon, false)) {
pr_err("Failed to enter CPU mode\n");
dcon->pending_src = DCON_SOURCE_DCON;
return;
}
pdata->set_dconload(1);
getnstimeofday(&dcon->load_time);
pr_info("The CPU has control\n");
break;
case DCON_SOURCE_DCON:
{
struct timespec delta_t;
pr_info("dcon_source_switch to DCON\n");
pdata->set_dconload(0);
getnstimeofday(&dcon->load_time);
wait_event_timeout(dcon->waitq, dcon->switched, HZ/2);
if (!dcon->switched) {
pr_err("Timeout entering DCON mode; expect a screen glitch.\n");
} else {
delta_t = timespec_sub(dcon->irq_time, dcon->load_time);
if (dcon->switched && delta_t.tv_sec == 0 &&
delta_t.tv_nsec < NSEC_PER_MSEC * 20) {
pr_err("missed loading, retrying\n");
pdata->set_dconload(1);
mdelay(41);
pdata->set_dconload(0);
getnstimeofday(&dcon->load_time);
mdelay(41);
}
}
dcon_blank_fb(dcon, true);
pr_info("The DCON has control\n");
break;
}
default:
BUG();
}
dcon->curr_src = source;
}
static void dcon_set_source(struct dcon_priv *dcon, int arg)
{
if (dcon->pending_src == arg)
return;
dcon->pending_src = arg;
if ((dcon->curr_src != arg) && !work_pending(&dcon->switch_source))
schedule_work(&dcon->switch_source);
}
static void dcon_set_source_sync(struct dcon_priv *dcon, int arg)
{
dcon_set_source(dcon, arg);
flush_scheduled_work();
}
static ssize_t dcon_mode_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dcon_priv *dcon = dev_get_drvdata(dev);
return sprintf(buf, "%4.4X\n", dcon->disp_mode);
}
static ssize_t dcon_sleep_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dcon_priv *dcon = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", dcon->asleep);
}
static ssize_t dcon_freeze_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dcon_priv *dcon = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", dcon->curr_src == DCON_SOURCE_DCON ? 1 : 0);
}
static ssize_t dcon_mono_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dcon_priv *dcon = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", dcon->mono);
}
static ssize_t dcon_resumeline_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", resumeline);
}
static ssize_t dcon_mono_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long enable_mono;
int rc;
rc = kstrtoul(buf, 10, &enable_mono);
if (rc)
return rc;
dcon_set_mono_mode(dev_get_drvdata(dev), enable_mono ? true : false);
return count;
}
static ssize_t dcon_freeze_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct dcon_priv *dcon = dev_get_drvdata(dev);
unsigned long output;
int ret;
ret = kstrtoul(buf, 10, &output);
if (ret)
return ret;
pr_info("dcon_freeze_store: %lu\n", output);
switch (output) {
case 0:
dcon_set_source(dcon, DCON_SOURCE_CPU);
break;
case 1:
dcon_set_source_sync(dcon, DCON_SOURCE_DCON);
break;
case 2:
dcon_set_source(dcon, DCON_SOURCE_DCON);
break;
default:
return -EINVAL;
}
return count;
}
static ssize_t dcon_resumeline_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned short rl;
int rc;
rc = kstrtou16(buf, 10, &rl);
if (rc)
return rc;
resumeline = rl;
dcon_write(dev_get_drvdata(dev), DCON_REG_SCAN_INT, resumeline);
return count;
}
static ssize_t dcon_sleep_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long output;
int ret;
ret = kstrtoul(buf, 10, &output);
if (ret)
return ret;
dcon_sleep(dev_get_drvdata(dev), output ? true : false);
return count;
}
static int dcon_bl_update(struct backlight_device *dev)
{
struct dcon_priv *dcon = bl_get_data(dev);
u8 level = dev->props.brightness & 0x0F;
if (dev->props.power != FB_BLANK_UNBLANK)
level = 0;
if (level != dcon->bl_val)
dcon_set_backlight(dcon, level);
if (!dcon->ignore_fb_events)
dcon_sleep(dcon, !!(dev->props.state & BL_CORE_FBBLANK));
return 0;
}
static int dcon_bl_get(struct backlight_device *dev)
{
struct dcon_priv *dcon = bl_get_data(dev);
return dcon->bl_val;
}
static int dcon_reboot_notify(struct notifier_block *nb,
unsigned long foo, void *bar)
{
struct dcon_priv *dcon = container_of(nb, struct dcon_priv, reboot_nb);
if (!dcon || !dcon->client)
return NOTIFY_DONE;
dcon_write(dcon, DCON_REG_MODE, 0x39);
dcon_write(dcon, DCON_REG_MODE, 0x32);
return NOTIFY_DONE;
}
static int unfreeze_on_panic(struct notifier_block *nb,
unsigned long e, void *p)
{
pdata->set_dconload(1);
return NOTIFY_DONE;
}
static int dcon_detect(struct i2c_client *client, struct i2c_board_info *info)
{
strlcpy(info->type, "olpc_dcon", I2C_NAME_SIZE);
return 0;
}
static int dcon_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct dcon_priv *dcon;
int rc, i, j;
if (!pdata)
return -ENXIO;
dcon = kzalloc(sizeof(*dcon), GFP_KERNEL);
if (!dcon)
return -ENOMEM;
dcon->client = client;
init_waitqueue_head(&dcon->waitq);
INIT_WORK(&dcon->switch_source, dcon_source_switch);
dcon->reboot_nb.notifier_call = dcon_reboot_notify;
dcon->reboot_nb.priority = -1;
i2c_set_clientdata(client, dcon);
if (num_registered_fb < 1) {
dev_err(&client->dev, "DCON driver requires a registered fb\n");
rc = -EIO;
goto einit;
}
dcon->fbinfo = registered_fb[0];
rc = dcon_hw_init(dcon, 1);
if (rc)
goto einit;
dcon_device = platform_device_alloc("dcon", -1);
if (dcon_device == NULL) {
pr_err("Unable to create the DCON device\n");
rc = -ENOMEM;
goto eirq;
}
rc = platform_device_add(dcon_device);
platform_set_drvdata(dcon_device, dcon);
if (rc) {
pr_err("Unable to add the DCON device\n");
goto edev;
}
for (i = 0; i < ARRAY_SIZE(dcon_device_files); i++) {
rc = device_create_file(&dcon_device->dev,
&dcon_device_files[i]);
if (rc) {
dev_err(&dcon_device->dev, "Cannot create sysfs file\n");
goto ecreate;
}
}
dcon->bl_val = dcon_read(dcon, DCON_REG_BRIGHT) & 0x0F;
dcon_bl_props.brightness = dcon->bl_val;
dcon->bl_dev = backlight_device_register("dcon-bl", &dcon_device->dev,
dcon, &dcon_bl_ops, &dcon_bl_props);
if (IS_ERR(dcon->bl_dev)) {
dev_err(&client->dev, "cannot register backlight dev (%ld)\n",
PTR_ERR(dcon->bl_dev));
dcon->bl_dev = NULL;
}
register_reboot_notifier(&dcon->reboot_nb);
atomic_notifier_chain_register(&panic_notifier_list, &dcon_panic_nb);
return 0;
ecreate:
for (j = 0; j < i; j++)
device_remove_file(&dcon_device->dev, &dcon_device_files[j]);
edev:
platform_device_unregister(dcon_device);
dcon_device = NULL;
eirq:
free_irq(DCON_IRQ, dcon);
einit:
kfree(dcon);
return rc;
}
static int dcon_remove(struct i2c_client *client)
{
struct dcon_priv *dcon = i2c_get_clientdata(client);
unregister_reboot_notifier(&dcon->reboot_nb);
atomic_notifier_chain_unregister(&panic_notifier_list, &dcon_panic_nb);
free_irq(DCON_IRQ, dcon);
if (dcon->bl_dev)
backlight_device_unregister(dcon->bl_dev);
if (dcon_device != NULL)
platform_device_unregister(dcon_device);
cancel_work_sync(&dcon->switch_source);
kfree(dcon);
return 0;
}
static int dcon_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct dcon_priv *dcon = i2c_get_clientdata(client);
if (!dcon->asleep) {
dcon_set_source_sync(dcon, DCON_SOURCE_DCON);
}
return 0;
}
static int dcon_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct dcon_priv *dcon = i2c_get_clientdata(client);
if (!dcon->asleep) {
dcon_bus_stabilize(dcon, 0);
dcon_set_source(dcon, DCON_SOURCE_CPU);
}
return 0;
}
irqreturn_t dcon_interrupt(int irq, void *id)
{
struct dcon_priv *dcon = id;
u8 status;
if (pdata->read_status(&status))
return IRQ_NONE;
switch (status & 3) {
case 3:
pr_debug("DCONLOAD_MISSED interrupt\n");
break;
case 2:
case 1:
dcon->switched = true;
getnstimeofday(&dcon->irq_time);
wake_up(&dcon->waitq);
break;
case 0:
if (dcon->curr_src != dcon->pending_src && !dcon->switched) {
dcon->switched = true;
getnstimeofday(&dcon->irq_time);
wake_up(&dcon->waitq);
pr_debug("switching w/ status 0/0\n");
} else {
pr_debug("scanline interrupt w/CPU\n");
}
}
return IRQ_HANDLED;
}
static int __init olpc_dcon_init(void)
{
#ifdef CONFIG_FB_OLPC_DCON_1_5
if (olpc_board_at_least(olpc_board(0xd0)))
pdata = &dcon_pdata_xo_1_5;
#endif
#ifdef CONFIG_FB_OLPC_DCON_1
if (!pdata)
pdata = &dcon_pdata_xo_1;
#endif
return i2c_add_driver(&dcon_driver);
}
static void __exit olpc_dcon_exit(void)
{
i2c_del_driver(&dcon_driver);
}
