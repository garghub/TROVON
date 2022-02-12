static int tpo_td043_write(struct spi_device *spi, u8 addr, u8 data)
{
struct spi_message m;
struct spi_transfer xfer;
u16 w;
int r;
spi_message_init(&m);
memset(&xfer, 0, sizeof(xfer));
w = ((u16)addr << 10) | (1 << 8) | data;
xfer.tx_buf = &w;
xfer.bits_per_word = 16;
xfer.len = 2;
spi_message_add_tail(&xfer, &m);
r = spi_sync(spi, &m);
if (r < 0)
dev_warn(&spi->dev, "failed to write to LCD reg (%d)\n", r);
return r;
}
static void tpo_td043_write_gamma(struct spi_device *spi, u16 gamma[12])
{
u8 i, val;
for (val = i = 0; i < 4; i++)
val |= (gamma[i] & 0x300) >> ((i + 1) * 2);
tpo_td043_write(spi, 0x11, val);
for (val = i = 0; i < 4; i++)
val |= (gamma[i+4] & 0x300) >> ((i + 1) * 2);
tpo_td043_write(spi, 0x12, val);
for (val = i = 0; i < 4; i++)
val |= (gamma[i+8] & 0x300) >> ((i + 1) * 2);
tpo_td043_write(spi, 0x13, val);
for (val = i = 0; i < 12; i++)
tpo_td043_write(spi, 0x14 + i, gamma[i] & 0xff);
}
static int tpo_td043_write_mirror(struct spi_device *spi, bool h, bool v)
{
u8 reg4 = TPO_R04_NFLIP_H | TPO_R04_NFLIP_V |
TPO_R04_CP_CLK_FREQ_1H | TPO_R04_VGL_FREQ_1H;
if (h)
reg4 &= ~TPO_R04_NFLIP_H;
if (v)
reg4 &= ~TPO_R04_NFLIP_V;
return tpo_td043_write(spi, 4, reg4);
}
static int tpo_td043_set_hmirror(struct omap_dss_device *dssdev, bool enable)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
ddata->hmirror = enable;
return tpo_td043_write_mirror(ddata->spi, ddata->hmirror,
ddata->vmirror);
}
static bool tpo_td043_get_hmirror(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
return ddata->hmirror;
}
static ssize_t tpo_td043_vmirror_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ddata->vmirror);
}
static ssize_t tpo_td043_vmirror_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
int val;
int ret;
ret = kstrtoint(buf, 0, &val);
if (ret < 0)
return ret;
val = !!val;
ret = tpo_td043_write_mirror(ddata->spi, ddata->hmirror, val);
if (ret < 0)
return ret;
ddata->vmirror = val;
return count;
}
static ssize_t tpo_td043_mode_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ddata->mode);
}
static ssize_t tpo_td043_mode_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
long val;
int ret;
ret = kstrtol(buf, 0, &val);
if (ret != 0 || val & ~7)
return -EINVAL;
ddata->mode = val;
val |= TPO_R02_NCLK_RISING;
tpo_td043_write(ddata->spi, 2, val);
return count;
}
static ssize_t tpo_td043_gamma_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
ssize_t len = 0;
int ret;
int i;
for (i = 0; i < ARRAY_SIZE(ddata->gamma); i++) {
ret = snprintf(buf + len, PAGE_SIZE - len, "%u ",
ddata->gamma[i]);
if (ret < 0)
return ret;
len += ret;
}
buf[len - 1] = '\n';
return len;
}
static ssize_t tpo_td043_gamma_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
unsigned int g[12];
int ret;
int i;
ret = sscanf(buf, "%u %u %u %u %u %u %u %u %u %u %u %u",
&g[0], &g[1], &g[2], &g[3], &g[4], &g[5],
&g[6], &g[7], &g[8], &g[9], &g[10], &g[11]);
if (ret != 12)
return -EINVAL;
for (i = 0; i < 12; i++)
ddata->gamma[i] = g[i];
tpo_td043_write_gamma(ddata->spi, ddata->gamma);
return count;
}
static int tpo_td043_power_on(struct panel_drv_data *ddata)
{
int r;
if (ddata->powered_on)
return 0;
r = regulator_enable(ddata->vcc_reg);
if (r != 0)
return r;
msleep(160);
if (gpio_is_valid(ddata->nreset_gpio))
gpio_set_value(ddata->nreset_gpio, 1);
tpo_td043_write(ddata->spi, 2,
TPO_R02_MODE(ddata->mode) | TPO_R02_NCLK_RISING);
tpo_td043_write(ddata->spi, 3, TPO_R03_VAL_NORMAL);
tpo_td043_write(ddata->spi, 0x20, 0xf0);
tpo_td043_write(ddata->spi, 0x21, 0xf0);
tpo_td043_write_mirror(ddata->spi, ddata->hmirror,
ddata->vmirror);
tpo_td043_write_gamma(ddata->spi, ddata->gamma);
ddata->powered_on = 1;
return 0;
}
static void tpo_td043_power_off(struct panel_drv_data *ddata)
{
if (!ddata->powered_on)
return;
tpo_td043_write(ddata->spi, 3,
TPO_R03_VAL_STANDBY | TPO_R03_EN_PWM);
if (gpio_is_valid(ddata->nreset_gpio))
gpio_set_value(ddata->nreset_gpio, 0);
msleep(50);
tpo_td043_write(ddata->spi, 3, TPO_R03_VAL_STANDBY);
regulator_disable(ddata->vcc_reg);
ddata->powered_on = 0;
}
static int tpo_td043_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.dpi->connect(in, dssdev);
if (r)
return r;
return 0;
}
static void tpo_td043_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.dpi->disconnect(in, dssdev);
}
static int tpo_td043_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
if (ddata->data_lines)
in->ops.dpi->set_data_lines(in, ddata->data_lines);
in->ops.dpi->set_timings(in, &ddata->vm);
r = in->ops.dpi->enable(in);
if (r)
return r;
if (!ddata->spi_suspended) {
r = tpo_td043_power_on(ddata);
if (r) {
in->ops.dpi->disable(in);
return r;
}
}
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void tpo_td043_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
in->ops.dpi->disable(in);
if (!ddata->spi_suspended)
tpo_td043_power_off(ddata);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void tpo_td043_set_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->vm = *vm;
dssdev->panel.vm = *vm;
in->ops.dpi->set_timings(in, vm);
}
static void tpo_td043_get_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*vm = ddata->vm;
}
static int tpo_td043_check_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.dpi->check_timings(in, vm);
}
static int tpo_td043_probe_of(struct spi_device *spi)
{
struct device_node *node = spi->dev.of_node;
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *in;
int gpio;
gpio = of_get_named_gpio(node, "reset-gpios", 0);
if (!gpio_is_valid(gpio)) {
dev_err(&spi->dev, "failed to parse enable gpio\n");
return gpio;
}
ddata->nreset_gpio = gpio;
in = omapdss_of_find_source_for_first_ep(node);
if (IS_ERR(in)) {
dev_err(&spi->dev, "failed to find video source\n");
return PTR_ERR(in);
}
ddata->in = in;
return 0;
}
static int tpo_td043_probe(struct spi_device *spi)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
dev_dbg(&spi->dev, "%s\n", __func__);
spi->bits_per_word = 16;
spi->mode = SPI_MODE_0;
r = spi_setup(spi);
if (r < 0) {
dev_err(&spi->dev, "spi_setup failed: %d\n", r);
return r;
}
ddata = devm_kzalloc(&spi->dev, sizeof(*ddata), GFP_KERNEL);
if (ddata == NULL)
return -ENOMEM;
dev_set_drvdata(&spi->dev, ddata);
ddata->spi = spi;
if (!spi->dev.of_node)
return -ENODEV;
r = tpo_td043_probe_of(spi);
if (r)
return r;
ddata->mode = TPO_R02_MODE_800x480;
memcpy(ddata->gamma, tpo_td043_def_gamma, sizeof(ddata->gamma));
ddata->vcc_reg = devm_regulator_get(&spi->dev, "vcc");
if (IS_ERR(ddata->vcc_reg)) {
dev_err(&spi->dev, "failed to get LCD VCC regulator\n");
r = PTR_ERR(ddata->vcc_reg);
goto err_regulator;
}
if (gpio_is_valid(ddata->nreset_gpio)) {
r = devm_gpio_request_one(&spi->dev,
ddata->nreset_gpio, GPIOF_OUT_INIT_LOW,
"lcd reset");
if (r < 0) {
dev_err(&spi->dev, "couldn't request reset GPIO\n");
goto err_gpio_req;
}
}
r = sysfs_create_group(&spi->dev.kobj, &tpo_td043_attr_group);
if (r) {
dev_err(&spi->dev, "failed to create sysfs files\n");
goto err_sysfs;
}
ddata->vm = tpo_td043_vm;
dssdev = &ddata->dssdev;
dssdev->dev = &spi->dev;
dssdev->driver = &tpo_td043_ops;
dssdev->type = OMAP_DISPLAY_TYPE_DPI;
dssdev->owner = THIS_MODULE;
dssdev->panel.vm = ddata->vm;
r = omapdss_register_display(dssdev);
if (r) {
dev_err(&spi->dev, "Failed to register panel\n");
goto err_reg;
}
return 0;
err_reg:
sysfs_remove_group(&spi->dev.kobj, &tpo_td043_attr_group);
err_sysfs:
err_gpio_req:
err_regulator:
omap_dss_put_device(ddata->in);
return r;
}
static int tpo_td043_remove(struct spi_device *spi)
{
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
dev_dbg(&ddata->spi->dev, "%s\n", __func__);
omapdss_unregister_display(dssdev);
tpo_td043_disable(dssdev);
tpo_td043_disconnect(dssdev);
omap_dss_put_device(in);
sysfs_remove_group(&spi->dev.kobj, &tpo_td043_attr_group);
return 0;
}
static int tpo_td043_spi_suspend(struct device *dev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
dev_dbg(dev, "tpo_td043_spi_suspend, tpo %p\n", ddata);
ddata->power_on_resume = ddata->powered_on;
tpo_td043_power_off(ddata);
ddata->spi_suspended = 1;
return 0;
}
static int tpo_td043_spi_resume(struct device *dev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dev);
int ret;
dev_dbg(dev, "tpo_td043_spi_resume\n");
if (ddata->power_on_resume) {
ret = tpo_td043_power_on(ddata);
if (ret)
return ret;
}
ddata->spi_suspended = 0;
return 0;
}
