static void flexfb_set_addr_win_1(struct fbtft_par *par,
int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par, "%s(xs=%d, ys=%d, xe=%d, ye=%d)\n",
__func__, xs, ys, xe, ye);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x0020, xs);
write_reg(par, 0x0021, ys);
break;
case 180:
write_reg(par, 0x0020, width - 1 - xs);
write_reg(par, 0x0021, height - 1 - ys);
break;
case 270:
write_reg(par, 0x0020, width - 1 - ys);
write_reg(par, 0x0021, xs);
break;
case 90:
write_reg(par, 0x0020, ys);
write_reg(par, 0x0021, height - 1 - xs);
break;
}
write_reg(par, 0x0022);
}
static void flexfb_set_addr_win_2(struct fbtft_par *par,
int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n",
__func__, xs, ys, xe, ye);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x4e, xs);
write_reg(par, 0x4f, ys);
break;
case 180:
write_reg(par, 0x4e, par->info->var.xres - 1 - xs);
write_reg(par, 0x4f, par->info->var.yres - 1 - ys);
break;
case 270:
write_reg(par, 0x4e, par->info->var.yres - 1 - ys);
write_reg(par, 0x4f, xs);
break;
case 90:
write_reg(par, 0x4e, ys);
write_reg(par, 0x4f, par->info->var.xres - 1 - xs);
break;
}
write_reg(par, 0x22, 0);
}
static void set_addr_win_3(struct fbtft_par *par,
int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__,
xs, ys, xe, ye);
write_reg(par, 0x15, xs, xe);
write_reg(par, 0x75, ys, ye);
write_reg(par, 0x5C);
}
static int flexfb_verify_gpios_dc(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_VERIFY_GPIOS, par, "%s()\n", __func__);
if (par->gpio.dc < 0) {
dev_err(par->info->device,
"Missing info about 'dc' gpio. Aborting.\n");
return -EINVAL;
}
return 0;
}
static int flexfb_verify_gpios_db(struct fbtft_par *par)
{
int i;
int num_db = buswidth;
fbtft_par_dbg(DEBUG_VERIFY_GPIOS, par, "%s()\n", __func__);
if (par->gpio.dc < 0) {
dev_err(par->info->device, "Missing info about 'dc' gpio. Aborting.\n");
return -EINVAL;
}
if (par->gpio.wr < 0) {
dev_err(par->info->device, "Missing info about 'wr' gpio. Aborting.\n");
return -EINVAL;
}
if (latched && (par->gpio.latch < 0)) {
dev_err(par->info->device, "Missing info about 'latch' gpio. Aborting.\n");
return -EINVAL;
}
if (latched)
num_db = buswidth / 2;
for (i = 0; i < num_db; i++) {
if (par->gpio.db[i] < 0) {
dev_err(par->info->device,
"Missing info about 'db%02d' gpio. Aborting.\n",
i);
return -EINVAL;
}
}
return 0;
}
static void flexfb_chip_load_param(const struct flexfb_lcd_controller *chip)
{
if (!width)
width = chip->width;
if (!height)
height = chip->height;
setaddrwin = chip->setaddrwin;
if (chip->regwidth)
regwidth = chip->regwidth;
if (!init_num) {
initp = chip->init_seq;
initp_num = chip->init_seq_sz;
}
}
static int flexfb_chip_init(const struct device *dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(flexfb_chip_table); i++)
if (!strcmp(chip, flexfb_chip_table[i].name)) {
flexfb_chip_load_param(&flexfb_chip_table[i]);
return 0;
}
dev_err(dev, "chip=%s is not supported\n", chip);
return -EINVAL;
}
static int flexfb_probe_common(struct spi_device *sdev,
struct platform_device *pdev)
{
struct device *dev;
struct fb_info *info;
struct fbtft_par *par;
int ret;
initp = init;
initp_num = init_num;
if (sdev)
dev = &sdev->dev;
else
dev = &pdev->dev;
fbtft_init_dbg(dev, "%s(%s)\n", __func__,
sdev ? "'SPI device'" : "'Platform device'");
if (chip) {
ret = flexfb_chip_init(dev);
if (ret)
return ret;
}
if (width == 0 || height == 0) {
dev_err(dev, "argument(s) missing: width and height has to be set.\n");
return -EINVAL;
}
flex_display.width = width;
flex_display.height = height;
fbtft_init_dbg(dev, "Display resolution: %dx%d\n", width, height);
fbtft_init_dbg(dev, "chip = %s\n", chip ? chip : "not set");
fbtft_init_dbg(dev, "setaddrwin = %d\n", setaddrwin);
fbtft_init_dbg(dev, "regwidth = %d\n", regwidth);
fbtft_init_dbg(dev, "buswidth = %d\n", buswidth);
info = fbtft_framebuffer_alloc(&flex_display, dev, dev->platform_data);
if (!info)
return -ENOMEM;
par = info->par;
if (sdev)
par->spi = sdev;
else
par->pdev = pdev;
if (!par->init_sequence)
par->init_sequence = initp;
par->fbtftops.init_display = fbtft_init_display;
switch (regwidth) {
case 8:
par->fbtftops.write_register = fbtft_write_reg8_bus8;
break;
case 16:
par->fbtftops.write_register = fbtft_write_reg16_bus8;
break;
default:
dev_err(dev,
"argument 'regwidth': %d is not supported.\n",
regwidth);
return -EINVAL;
}
if (sdev) {
par->fbtftops.write = fbtft_write_spi;
switch (buswidth) {
case 8:
par->fbtftops.write_vmem = fbtft_write_vmem16_bus8;
if (!par->startbyte)
par->fbtftops.verify_gpios = flexfb_verify_gpios_dc;
break;
case 9:
if (regwidth == 16) {
dev_err(dev, "argument 'regwidth': %d is not supported with buswidth=%d and SPI.\n", regwidth, buswidth);
return -EINVAL;
}
par->fbtftops.write_register = fbtft_write_reg8_bus9;
par->fbtftops.write_vmem = fbtft_write_vmem16_bus9;
if (par->spi->master->bits_per_word_mask
& SPI_BPW_MASK(9)) {
par->spi->bits_per_word = 9;
} else {
dev_warn(dev,
"9-bit SPI not available, emulating using 8-bit.\n");
par->extra = devm_kzalloc(par->info->device,
par->txbuf.len + (par->txbuf.len / 8) + 8,
GFP_KERNEL);
if (!par->extra) {
ret = -ENOMEM;
goto out_release;
}
par->fbtftops.write = fbtft_write_spi_emulate_9;
}
break;
default:
dev_err(dev, "argument 'buswidth': %d is not supported with SPI.\n", buswidth);
return -EINVAL;
}
} else {
par->fbtftops.verify_gpios = flexfb_verify_gpios_db;
switch (buswidth) {
case 8:
par->fbtftops.write = fbtft_write_gpio8_wr;
par->fbtftops.write_vmem = fbtft_write_vmem16_bus8;
break;
case 16:
par->fbtftops.write_register = fbtft_write_reg16_bus16;
if (latched)
par->fbtftops.write = fbtft_write_gpio16_wr_latched;
else
par->fbtftops.write = fbtft_write_gpio16_wr;
par->fbtftops.write_vmem = fbtft_write_vmem16_bus16;
break;
default:
dev_err(dev, "argument 'buswidth': %d is not supported with parallel.\n", buswidth);
return -EINVAL;
}
}
switch (setaddrwin) {
case 0:
break;
case 1:
par->fbtftops.set_addr_win = flexfb_set_addr_win_1;
break;
case 2:
par->fbtftops.set_addr_win = flexfb_set_addr_win_2;
break;
case 3:
par->fbtftops.set_addr_win = set_addr_win_3;
break;
default:
dev_err(dev, "argument 'setaddrwin': unknown value %d.\n",
setaddrwin);
return -EINVAL;
}
if (!nobacklight)
par->fbtftops.register_backlight = fbtft_register_backlight;
ret = fbtft_register_framebuffer(info);
if (ret < 0)
goto out_release;
return 0;
out_release:
fbtft_framebuffer_release(info);
return ret;
}
static int flexfb_remove_common(struct device *dev, struct fb_info *info)
{
struct fbtft_par *par;
if (!info)
return -EINVAL;
par = info->par;
if (par)
fbtft_par_dbg(DEBUG_DRIVER_INIT_FUNCTIONS, par, "%s()\n",
__func__);
fbtft_unregister_framebuffer(info);
fbtft_framebuffer_release(info);
return 0;
}
static int flexfb_probe_spi(struct spi_device *spi)
{
return flexfb_probe_common(spi, NULL);
}
static int flexfb_remove_spi(struct spi_device *spi)
{
struct fb_info *info = spi_get_drvdata(spi);
return flexfb_remove_common(&spi->dev, info);
}
static int flexfb_probe_pdev(struct platform_device *pdev)
{
return flexfb_probe_common(NULL, pdev);
}
static int flexfb_remove_pdev(struct platform_device *pdev)
{
struct fb_info *info = platform_get_drvdata(pdev);
return flexfb_remove_common(&pdev->dev, info);
}
static int __init flexfb_init(void)
{
int ret, ret2;
ret = spi_register_driver(&flexfb_spi_driver);
ret2 = platform_driver_register(&flexfb_platform_driver);
if (ret < 0)
return ret;
return ret2;
}
static void __exit flexfb_exit(void)
{
spi_unregister_driver(&flexfb_spi_driver);
platform_driver_unregister(&flexfb_platform_driver);
}
