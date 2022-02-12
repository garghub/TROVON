static struct sh_mipi *sh_mipi_by_handle(int handle)
{
if (handle >= ARRAY_SIZE(mipi_dsi) || handle < 0)
return NULL;
return mipi_dsi[handle];
}
static int sh_mipi_send_short(struct sh_mipi *mipi, u8 dsi_cmd,
u8 cmd, u8 param)
{
u32 data = (dsi_cmd << 24) | (cmd << 16) | (param << 8);
int cnt = 100;
iowrite32(1 | data, mipi->linkbase + CMTSRTCTR);
iowrite32(1, mipi->linkbase + CMTSRTREQ);
while ((ioread32(mipi->linkbase + CMTSRTREQ) & 1) && --cnt)
udelay(1);
return cnt ? 0 : -ETIMEDOUT;
}
static int sh_mipi_dcs(int handle, u8 cmd)
{
struct sh_mipi *mipi = sh_mipi_by_handle(LCD_CHAN2MIPI(handle));
if (!mipi)
return -ENODEV;
return sh_mipi_send_short(mipi, MIPI_DSI_DCS_SHORT_WRITE, cmd, 0);
}
static int sh_mipi_dcs_param(int handle, u8 cmd, u8 param)
{
struct sh_mipi *mipi = sh_mipi_by_handle(LCD_CHAN2MIPI(handle));
if (!mipi)
return -ENODEV;
return sh_mipi_send_short(mipi, MIPI_DSI_DCS_SHORT_WRITE_PARAM, cmd,
param);
}
static void sh_mipi_dsi_enable(struct sh_mipi *mipi, bool enable)
{
iowrite32(0x00000002 | enable, mipi->linkbase + DTCTR);
}
static void sh_mipi_shutdown(struct platform_device *pdev)
{
struct sh_mipi *mipi = platform_get_drvdata(pdev);
sh_mipi_dsi_enable(mipi, false);
}
static void mipi_display_on(void *arg, struct fb_info *info)
{
struct sh_mipi *mipi = arg;
pm_runtime_get_sync(mipi->dev);
sh_mipi_dsi_enable(mipi, true);
if (mipi->next_display_on)
mipi->next_display_on(mipi->next_board_data, info);
}
static void mipi_display_off(void *arg)
{
struct sh_mipi *mipi = arg;
if (mipi->next_display_off)
mipi->next_display_off(mipi->next_board_data);
sh_mipi_dsi_enable(mipi, false);
pm_runtime_put(mipi->dev);
}
static int __init sh_mipi_setup(struct sh_mipi *mipi,
struct sh_mipi_dsi_info *pdata)
{
void __iomem *base = mipi->base;
struct sh_mobile_lcdc_chan_cfg *ch = pdata->lcd_chan;
u32 pctype, datatype, pixfmt, linelength, vmctr2 = 0x00e00000;
bool yuv;
switch (pdata->data_format) {
case MIPI_RGB888:
pctype = 0;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_24;
pixfmt = MIPI_DCS_PIXEL_FMT_24BIT;
linelength = ch->lcd_cfg[0].xres * 3;
yuv = false;
break;
case MIPI_RGB565:
pctype = 1;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_16;
pixfmt = MIPI_DCS_PIXEL_FMT_16BIT;
linelength = ch->lcd_cfg[0].xres * 2;
yuv = false;
break;
case MIPI_RGB666_LP:
pctype = 2;
datatype = MIPI_DSI_PIXEL_STREAM_3BYTE_18;
pixfmt = MIPI_DCS_PIXEL_FMT_24BIT;
linelength = ch->lcd_cfg[0].xres * 3;
yuv = false;
break;
case MIPI_RGB666:
pctype = 3;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_18;
pixfmt = MIPI_DCS_PIXEL_FMT_18BIT;
linelength = (ch->lcd_cfg[0].xres * 18 + 7) / 8;
yuv = false;
break;
case MIPI_BGR888:
pctype = 8;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_24;
pixfmt = MIPI_DCS_PIXEL_FMT_24BIT;
linelength = ch->lcd_cfg[0].xres * 3;
yuv = false;
break;
case MIPI_BGR565:
pctype = 9;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_16;
pixfmt = MIPI_DCS_PIXEL_FMT_16BIT;
linelength = ch->lcd_cfg[0].xres * 2;
yuv = false;
break;
case MIPI_BGR666_LP:
pctype = 0xa;
datatype = MIPI_DSI_PIXEL_STREAM_3BYTE_18;
pixfmt = MIPI_DCS_PIXEL_FMT_24BIT;
linelength = ch->lcd_cfg[0].xres * 3;
yuv = false;
break;
case MIPI_BGR666:
pctype = 0xb;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_18;
pixfmt = MIPI_DCS_PIXEL_FMT_18BIT;
linelength = (ch->lcd_cfg[0].xres * 18 + 7) / 8;
yuv = false;
break;
case MIPI_YUYV:
pctype = 4;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR16;
pixfmt = MIPI_DCS_PIXEL_FMT_16BIT;
linelength = ch->lcd_cfg[0].xres * 2;
yuv = true;
break;
case MIPI_UYVY:
pctype = 5;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR16;
pixfmt = MIPI_DCS_PIXEL_FMT_16BIT;
linelength = ch->lcd_cfg[0].xres * 2;
yuv = true;
break;
case MIPI_YUV420_L:
pctype = 6;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR12;
pixfmt = MIPI_DCS_PIXEL_FMT_12BIT;
linelength = (ch->lcd_cfg[0].xres * 12 + 7) / 8;
yuv = true;
break;
case MIPI_YUV420:
pctype = 7;
datatype = MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR12;
pixfmt = MIPI_DCS_PIXEL_FMT_12BIT;
linelength = (ch->lcd_cfg[0].xres + 1) / 2;
yuv = true;
break;
default:
return -EINVAL;
}
if ((yuv && ch->interface_type != YUV422) ||
(!yuv && ch->interface_type != RGB24))
return -EINVAL;
iowrite32(0x00000001, base + SYSCTRL);
udelay(50);
iowrite32(0x00000000, base + SYSCTRL);
iowrite32(0x00003703, base + SYSCONF);
iowrite32(0x70003332, base + TIMSET);
iowrite32(0x00000000, base + RESREQSET0);
iowrite32(0x00000100, base + RESREQSET1);
iowrite32(0x0fffffff, base + HSTTOVSET);
iowrite32(0x0fffffff, base + LPRTOVSET);
iowrite32(0x0fffffff, base + TATOVSET);
iowrite32(0x0fffffff, base + PRTOVSET);
iowrite32(0x00000f00, base + DSICTRL);
iowrite32(0, base + DSIINTE);
iowrite32(0x00000001, base + PHYCTRL);
udelay(200);
iowrite32(0x03070b01, base + PHYCTRL);
iowrite32(0x00000006, mipi->linkbase + DTCTR);
iowrite32((ch->lcd_cfg[0].vsync_len << pdata->vsynw_offset) |
(pdata->clksrc << 16) | (pctype << 12) | datatype,
mipi->linkbase + VMCTR1);
if (pdata->flags & SH_MIPI_DSI_HSABM)
vmctr2 |= 0x20;
if (pdata->flags & SH_MIPI_DSI_HSPBM)
vmctr2 |= 0x10;
iowrite32(vmctr2, mipi->linkbase + VMCTR2);
iowrite32(1 | (linelength << 16), mipi->linkbase + VMLEN1);
msleep(5);
sh_mipi_dcs(ch->chan, MIPI_DCS_EXIT_SLEEP_MODE);
msleep(120);
sh_mipi_dcs_param(ch->chan, MIPI_DCS_SET_ADDRESS_MODE, 0x00);
sh_mipi_dcs_param(ch->chan, MIPI_DCS_SET_PIXEL_FORMAT,
pixfmt << 4);
sh_mipi_dcs(ch->chan, MIPI_DCS_SET_DISPLAY_ON);
return 0;
}
static int __init sh_mipi_probe(struct platform_device *pdev)
{
struct sh_mipi *mipi;
struct sh_mipi_dsi_info *pdata = pdev->dev.platform_data;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *res2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
unsigned long rate, f_current;
int idx = pdev->id, ret;
char dsip_clk[] = "dsi.p_clk";
if (!res || !res2 || idx >= ARRAY_SIZE(mipi_dsi) || !pdata)
return -ENODEV;
mutex_lock(&array_lock);
if (idx < 0)
for (idx = 0; idx < ARRAY_SIZE(mipi_dsi) && mipi_dsi[idx]; idx++)
;
if (idx == ARRAY_SIZE(mipi_dsi)) {
ret = -EBUSY;
goto efindslot;
}
mipi = kzalloc(sizeof(*mipi), GFP_KERNEL);
if (!mipi) {
ret = -ENOMEM;
goto ealloc;
}
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "MIPI register region already claimed\n");
ret = -EBUSY;
goto ereqreg;
}
mipi->base = ioremap(res->start, resource_size(res));
if (!mipi->base) {
ret = -ENOMEM;
goto emap;
}
if (!request_mem_region(res2->start, resource_size(res2), pdev->name)) {
dev_err(&pdev->dev, "MIPI register region 2 already claimed\n");
ret = -EBUSY;
goto ereqreg2;
}
mipi->linkbase = ioremap(res2->start, resource_size(res2));
if (!mipi->linkbase) {
ret = -ENOMEM;
goto emap2;
}
mipi->dev = &pdev->dev;
mipi->dsit_clk = clk_get(&pdev->dev, "dsit_clk");
if (IS_ERR(mipi->dsit_clk)) {
ret = PTR_ERR(mipi->dsit_clk);
goto eclktget;
}
f_current = clk_get_rate(mipi->dsit_clk);
rate = clk_round_rate(mipi->dsit_clk, 80000000);
if (rate > 0 && rate != f_current)
ret = clk_set_rate(mipi->dsit_clk, rate);
else
ret = rate;
if (ret < 0)
goto esettrate;
dev_dbg(&pdev->dev, "DSI-T clk %lu -> %lu\n", f_current, rate);
sprintf(dsip_clk, "dsi%1.1dp_clk", idx);
mipi->dsip_clk = clk_get(&pdev->dev, dsip_clk);
if (IS_ERR(mipi->dsip_clk)) {
ret = PTR_ERR(mipi->dsip_clk);
goto eclkpget;
}
f_current = clk_get_rate(mipi->dsip_clk);
rate = clk_round_rate(mipi->dsip_clk, 24000000);
if (rate > 0 && rate != f_current)
ret = clk_set_rate(mipi->dsip_clk, rate);
else
ret = rate;
if (ret < 0)
goto esetprate;
dev_dbg(&pdev->dev, "DSI-P clk %lu -> %lu\n", f_current, rate);
msleep(10);
ret = clk_enable(mipi->dsit_clk);
if (ret < 0)
goto eclkton;
ret = clk_enable(mipi->dsip_clk);
if (ret < 0)
goto eclkpon;
mipi_dsi[idx] = mipi;
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
ret = sh_mipi_setup(mipi, pdata);
if (ret < 0)
goto emipisetup;
mutex_unlock(&array_lock);
platform_set_drvdata(pdev, mipi);
mipi->next_board_data = pdata->lcd_chan->board_cfg.board_data;
mipi->next_display_on = pdata->lcd_chan->board_cfg.display_on;
mipi->next_display_off = pdata->lcd_chan->board_cfg.display_off;
pdata->lcd_chan->board_cfg.board_data = mipi;
pdata->lcd_chan->board_cfg.display_on = mipi_display_on;
pdata->lcd_chan->board_cfg.display_off = mipi_display_off;
pdata->lcd_chan->board_cfg.owner = THIS_MODULE;
return 0;
emipisetup:
mipi_dsi[idx] = NULL;
pm_runtime_disable(&pdev->dev);
clk_disable(mipi->dsip_clk);
eclkpon:
clk_disable(mipi->dsit_clk);
eclkton:
esetprate:
clk_put(mipi->dsip_clk);
eclkpget:
esettrate:
clk_put(mipi->dsit_clk);
eclktget:
iounmap(mipi->linkbase);
emap2:
release_mem_region(res2->start, resource_size(res2));
ereqreg2:
iounmap(mipi->base);
emap:
release_mem_region(res->start, resource_size(res));
ereqreg:
kfree(mipi);
ealloc:
efindslot:
mutex_unlock(&array_lock);
return ret;
}
static int __exit sh_mipi_remove(struct platform_device *pdev)
{
struct sh_mipi_dsi_info *pdata = pdev->dev.platform_data;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *res2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
struct sh_mipi *mipi = platform_get_drvdata(pdev);
int i, ret;
mutex_lock(&array_lock);
for (i = 0; i < ARRAY_SIZE(mipi_dsi) && mipi_dsi[i] != mipi; i++)
;
if (i == ARRAY_SIZE(mipi_dsi)) {
ret = -EINVAL;
} else {
ret = 0;
mipi_dsi[i] = NULL;
}
mutex_unlock(&array_lock);
if (ret < 0)
return ret;
pdata->lcd_chan->board_cfg.owner = NULL;
pdata->lcd_chan->board_cfg.display_on = NULL;
pdata->lcd_chan->board_cfg.display_off = NULL;
pdata->lcd_chan->board_cfg.board_data = NULL;
pm_runtime_disable(&pdev->dev);
clk_disable(mipi->dsip_clk);
clk_disable(mipi->dsit_clk);
clk_put(mipi->dsit_clk);
clk_put(mipi->dsip_clk);
iounmap(mipi->linkbase);
if (res2)
release_mem_region(res2->start, resource_size(res2));
iounmap(mipi->base);
if (res)
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(pdev, NULL);
kfree(mipi);
return 0;
}
static int __init sh_mipi_init(void)
{
return platform_driver_probe(&sh_mipi_driver, sh_mipi_probe);
}
static void __exit sh_mipi_exit(void)
{
platform_driver_unregister(&sh_mipi_driver);
}
