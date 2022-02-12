static int vgg2432a4_lcd_init(struct ili9320 *lcd,
struct ili9320_platdata *cfg)
{
unsigned int addr;
int ret;
ret = ili9320_write(lcd, 0x00e5, 0x8000);
if (ret)
goto err_initial;
ret = ili9320_write(lcd, ILI9320_OSCILATION, ILI9320_OSCILATION_OSC);
if (ret)
goto err_initial;
mdelay(15);
ret = ili9320_write_regs(lcd, vgg_init0, ARRAY_SIZE(vgg_init0));
if (ret != 0)
goto err_initial;
ili9320_write(lcd, ILI9320_DISPLAY2, cfg->display2);
ili9320_write(lcd, ILI9320_DISPLAY3, cfg->display3);
ili9320_write(lcd, ILI9320_DISPLAY4, cfg->display4);
ili9320_write(lcd, ILI9320_RGB_IF1, cfg->rgb_if1);
ili9320_write(lcd, ILI9320_FRAMEMAKER, 0x0);
ili9320_write(lcd, ILI9320_RGB_IF2, cfg->rgb_if2);
ret = ili9320_write_regs(lcd, vgg_init1, ARRAY_SIZE(vgg_init1));
if (ret != 0)
goto err_vgg;
mdelay(300);
ret = ili9320_write_regs(lcd, vgg_init2, ARRAY_SIZE(vgg_init2));
if (ret != 0)
goto err_vgg2;
mdelay(100);
ili9320_write(lcd, ILI9320_POWER3, 0x13c);
mdelay(100);
ili9320_write(lcd, ILI9320_POWER4, 0x1c00);
ili9320_write(lcd, ILI9320_POWER7, 0x000e);
mdelay(100);
ili9320_write(lcd, ILI9320_GRAM_HORIZ_ADDR, 0x00);
ili9320_write(lcd, ILI9320_GRAM_VERT_ADD, 0x00);
ret = ili9320_write_regs(lcd, vgg_gamma, ARRAY_SIZE(vgg_gamma));
if (ret != 0)
goto err_vgg3;
ili9320_write(lcd, ILI9320_HORIZ_START, 0x0);
ili9320_write(lcd, ILI9320_HORIZ_END, cfg->hsize - 1);
ili9320_write(lcd, ILI9320_VERT_START, 0x0);
ili9320_write(lcd, ILI9320_VERT_END, cfg->vsize - 1);
ili9320_write(lcd, ILI9320_DRIVER2,
ILI9320_DRIVER2_NL(((cfg->vsize - 240) / 8) + 0x1D));
ili9320_write(lcd, ILI9320_BASE_IMAGE, 0x1);
ili9320_write(lcd, ILI9320_VERT_SCROLL, 0x00);
for (addr = ILI9320_PARTIAL1_POSITION; addr <= ILI9320_PARTIAL2_END;
addr++) {
ili9320_write(lcd, addr, 0x0);
}
ili9320_write(lcd, ILI9320_INTERFACE1, 0x10);
ili9320_write(lcd, ILI9320_INTERFACE2, cfg->interface2);
ili9320_write(lcd, ILI9320_INTERFACE3, cfg->interface3);
ili9320_write(lcd, ILI9320_INTERFACE4, cfg->interface4);
ili9320_write(lcd, ILI9320_INTERFACE5, cfg->interface5);
ili9320_write(lcd, ILI9320_INTERFACE6, cfg->interface6);
lcd->display1 = (ILI9320_DISPLAY1_D(3) | ILI9320_DISPLAY1_DTE |
ILI9320_DISPLAY1_GON | ILI9320_DISPLAY1_BASEE |
0x40);
ili9320_write(lcd, ILI9320_DISPLAY1, lcd->display1);
return 0;
err_vgg3:
err_vgg2:
err_vgg:
err_initial:
return ret;
}
static int vgg2432a4_suspend(struct spi_device *spi, pm_message_t state)
{
return ili9320_suspend(spi_get_drvdata(spi), state);
}
static int vgg2432a4_resume(struct spi_device *spi)
{
return ili9320_resume(spi_get_drvdata(spi));
}
static int vgg2432a4_probe(struct spi_device *spi)
{
int ret;
ret = ili9320_probe_spi(spi, &vgg2432a4_client);
if (ret != 0) {
dev_err(&spi->dev, "failed to initialise ili9320\n");
return ret;
}
return 0;
}
static int vgg2432a4_remove(struct spi_device *spi)
{
return ili9320_remove(spi_get_drvdata(spi));
}
static void vgg2432a4_shutdown(struct spi_device *spi)
{
ili9320_shutdown(spi_get_drvdata(spi));
}
