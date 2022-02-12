static int write_gpio16_wr_slow(struct fbtft_par *par, void *buf, size_t len)
{
u16 data;
int i;
#ifndef DO_NOT_OPTIMIZE_FBTFT_WRITE_GPIO
static u16 prev_data;
#endif
fbtft_par_dbg_hex(DEBUG_WRITE, par, par->info->device, u8, buf, len,
"%s(len=%d): ", __func__, len);
while (len) {
data = *(u16 *) buf;
gpio_set_value(par->gpio.wr, 0);
#ifndef DO_NOT_OPTIMIZE_FBTFT_WRITE_GPIO
if (data == prev_data) {
gpio_set_value(par->gpio.wr, 0);
} else {
for (i = 0; i < 16; i++) {
if ((data & 1) != (prev_data & 1))
gpio_set_value(par->gpio.db[i],
(data & 1));
data >>= 1;
prev_data >>= 1;
}
}
#else
for (i = 0; i < 16; i++) {
gpio_set_value(par->gpio.db[i], (data & 1));
data >>= 1;
}
#endif
gpio_set_value(par->gpio.wr, 1);
#ifndef DO_NOT_OPTIMIZE_FBTFT_WRITE_GPIO
prev_data = *(u16 *) buf;
#endif
buf += 2;
len -= 2;
}
return 0;
}
static void adafruit18_green_tab_set_addr_win(struct fbtft_par *par,
int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x2A, 0, xs + 2, 0, xe + 2);
write_reg(par, 0x2B, 0, ys + 1, 0, ye + 1);
write_reg(par, 0x2C);
}
static void fbtft_device_pdev_release(struct device *dev)
{
}
static int spi_device_found(struct device *dev, void *data)
{
struct spi_device *spi = container_of(dev, struct spi_device, dev);
pr_info(DRVNAME": %s %s %dkHz %d bits mode=0x%02X\n",
spi->modalias, dev_name(dev), spi->max_speed_hz/1000,
spi->bits_per_word, spi->mode);
return 0;
}
static void pr_spi_devices(void)
{
pr_info(DRVNAME": SPI devices registered:\n");
bus_for_each_dev(&spi_bus_type, NULL, NULL, spi_device_found);
}
static int p_device_found(struct device *dev, void *data)
{
struct platform_device
*pdev = container_of(dev, struct platform_device, dev);
if (strstr(pdev->name, "fb"))
pr_info(DRVNAME": %s id=%d pdata? %s\n",
pdev->name, pdev->id,
pdev->dev.platform_data ? "yes" : "no");
return 0;
}
static void pr_p_devices(void)
{
pr_info(DRVNAME": 'fb' Platform devices registered:\n");
bus_for_each_dev(&platform_bus_type, NULL, NULL, p_device_found);
}
static void fbtft_device_spi_delete(struct spi_master *master, unsigned cs)
{
struct device *dev;
char str[32];
snprintf(str, sizeof(str), "%s.%u", dev_name(&master->dev), cs);
dev = bus_find_device_by_name(&spi_bus_type, NULL, str);
if (dev) {
if (verbose)
pr_info(DRVNAME": Deleting %s\n", str);
device_del(dev);
}
}
static int fbtft_device_spi_device_register(struct spi_board_info *spi)
{
struct spi_master *master;
master = spi_busnum_to_master(spi->bus_num);
if (!master) {
pr_err(DRVNAME ": spi_busnum_to_master(%d) returned NULL\n",
spi->bus_num);
return -EINVAL;
}
fbtft_device_spi_delete(master, spi->chip_select);
spi_device = spi_new_device(master, spi);
put_device(&master->dev);
if (!spi_device) {
pr_err(DRVNAME ": spi_new_device() returned NULL\n");
return -EPERM;
}
return 0;
}
static int fbtft_device_spi_device_register(struct spi_board_info *spi)
{
return spi_register_board_info(spi, 1);
}
static int __init fbtft_device_init(void)
{
struct spi_board_info *spi = NULL;
struct fbtft_platform_data *pdata;
const struct fbtft_gpio *gpio = NULL;
char *p_gpio, *p_name, *p_num;
bool found = false;
int i = 0;
long val;
int ret = 0;
pr_debug("\n\n"DRVNAME": init\n");
if (name == NULL) {
#ifdef MODULE
pr_err(DRVNAME": missing module parameter: 'name'\n");
return -EINVAL;
#else
return 0;
#endif
}
if (init_num > FBTFT_MAX_INIT_SEQUENCE) {
pr_err(DRVNAME \
": init parameter: exceeded max array size: %d\n",
FBTFT_MAX_INIT_SEQUENCE);
return -EINVAL;
}
while ((p_gpio = strsep(&gpios, ","))) {
if (strchr(p_gpio, ':') == NULL) {
pr_err(DRVNAME \
": error: missing ':' in gpios parameter: %s\n",
p_gpio);
return -EINVAL;
}
p_num = p_gpio;
p_name = strsep(&p_num, ":");
if (p_name == NULL || p_num == NULL) {
pr_err(DRVNAME \
": something bad happened parsing gpios parameter: %s\n",
p_gpio);
return -EINVAL;
}
ret = kstrtol(p_num, 10, &val);
if (ret) {
pr_err(DRVNAME \
": could not parse number in gpios parameter: %s:%s\n",
p_name, p_num);
return -EINVAL;
}
strcpy(fbtft_device_param_gpios[i].name, p_name);
fbtft_device_param_gpios[i++].gpio = (int) val;
if (i == MAX_GPIOS) {
pr_err(DRVNAME \
": gpios parameter: exceeded max array size: %d\n",
MAX_GPIOS);
return -EINVAL;
}
}
if (fbtft_device_param_gpios[0].name[0])
gpio = fbtft_device_param_gpios;
if (verbose > 2)
pr_spi_devices();
if (verbose > 2)
pr_p_devices();
pr_debug(DRVNAME": name='%s', busnum=%d, cs=%d\n", name, busnum, cs);
if (rotate > 0 && rotate < 4) {
rotate = (4 - rotate) * 90;
pr_warn("argument 'rotate' should be an angle. Values 1-3 is deprecated. Setting it to %d.\n",
rotate);
}
if (rotate != 0 && rotate != 90 && rotate != 180 && rotate != 270) {
pr_warn("argument 'rotate' illegal value: %d. Setting it to 0.\n",
rotate);
rotate = 0;
}
if (strncmp(name, "list", 32) == 0) {
pr_info(DRVNAME": Supported displays:\n");
for (i = 0; i < ARRAY_SIZE(displays); i++)
pr_info(DRVNAME": %s\n", displays[i].name);
return -ECANCELED;
}
if (custom) {
i = ARRAY_SIZE(displays) - 1;
displays[i].name = name;
if (speed == 0) {
displays[i].pdev->name = name;
displays[i].spi = NULL;
} else {
strncpy(displays[i].spi->modalias, name, SPI_NAME_SIZE);
displays[i].pdev = NULL;
}
}
for (i = 0; i < ARRAY_SIZE(displays); i++) {
if (strncmp(name, displays[i].name, 32) == 0) {
if (displays[i].spi) {
spi = displays[i].spi;
spi->chip_select = cs;
spi->bus_num = busnum;
if (speed)
spi->max_speed_hz = speed;
if (mode != -1)
spi->mode = mode;
pdata = (void *)spi->platform_data;
} else if (displays[i].pdev) {
p_device = displays[i].pdev;
pdata = p_device->dev.platform_data;
} else {
pr_err(DRVNAME": broken displays array\n");
return -EINVAL;
}
pdata->rotate = rotate;
if (bgr == 0)
pdata->bgr = false;
else if (bgr == 1)
pdata->bgr = true;
if (startbyte)
pdata->startbyte = startbyte;
if (gamma)
pdata->gamma = gamma;
pdata->display.debug = debug;
if (fps)
pdata->fps = fps;
if (txbuflen)
pdata->txbuflen = txbuflen;
if (init_num)
pdata->display.init_sequence = init;
if (gpio)
pdata->gpios = gpio;
if (custom) {
pdata->display.width = width;
pdata->display.height = height;
pdata->display.buswidth = buswidth;
pdata->display.backlight = 1;
}
if (displays[i].spi) {
ret = fbtft_device_spi_device_register(spi);
if (ret) {
pr_err(DRVNAME \
": failed to register SPI device\n");
return ret;
}
found = true;
break;
} else {
ret = platform_device_register(p_device);
if (ret < 0) {
pr_err(DRVNAME \
": platform_device_register() returned %d\n",
ret);
return ret;
}
found = true;
break;
}
}
}
if (!found) {
pr_err(DRVNAME": display not supported: '%s'\n", name);
return -EINVAL;
}
if (verbose && pdata && pdata->gpios) {
gpio = pdata->gpios;
pr_info(DRVNAME": GPIOS used by '%s':\n", name);
found = false;
while (verbose && gpio->name[0]) {
pr_info(DRVNAME": '%s' = GPIO%d\n",
gpio->name, gpio->gpio);
gpio++;
found = true;
}
if (!found)
pr_info(DRVNAME": (none)\n");
}
if (spi_device && (verbose > 1))
pr_spi_devices();
if (p_device && (verbose > 1))
pr_p_devices();
return 0;
}
static void __exit fbtft_device_exit(void)
{
pr_debug(DRVNAME" - exit\n");
if (spi_device) {
device_del(&spi_device->dev);
kfree(spi_device);
}
if (p_device)
platform_device_unregister(p_device);
}
