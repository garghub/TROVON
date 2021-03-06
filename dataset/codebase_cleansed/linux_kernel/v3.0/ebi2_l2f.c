static void epsonQcif_disp_init(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
int i;
if (disp_initialized)
return;
mfd = platform_get_drvdata(pdev);
DISP_CMD_PORT = mfd->cmd_port;
DISP_DATA_PORT = mfd->data_port;
DISP_CMD_OUT(DISP_CMD_SLPIN);
DISP_CMD_OUT(DISP_CMD_DISOFF);
DISP_CMD_OUT(DISP_CMD_DISNOR);
DISP_CMD_OUT(DISP_CMD_DATCTL);
DISP_DATA_OUT(DISP_DATCTL_565);
DISP_CMD_OUT(DISP_CMD_DISCTL);
DISP_DATA_OUT(0x1c);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x82);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xe0);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xdc);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x00);
DISP_CMD_OUT(DISP_CMD_GCP64);
DISP_DATA_OUT(0x08);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x2a);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x4e);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x6b);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x88);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xa3);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xba);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xd1);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xe5);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0xf3);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x03);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x13);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x22);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x2f);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x3b);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x46);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x51);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x5b);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x64);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x6c);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x74);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x7c);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x83);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x8a);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x91);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x98);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x9f);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xa6);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xac);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xb2);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xb7);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xbc);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xc1);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xc6);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xcb);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xd0);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xd4);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xd8);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xdc);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xe0);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xe4);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xe8);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xec);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xf0);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xf4);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xf8);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xfb);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xfe);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x03);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x05);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x07);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x09);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x0b);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x0d);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x0f);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x11);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x13);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x15);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x17);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x19);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x1b);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x1c);
DISP_DATA_OUT(0x02);
DISP_CMD_OUT(DISP_CMD_GCP16);
DISP_DATA_OUT(0x1a);
DISP_DATA_OUT(0x32);
DISP_DATA_OUT(0x42);
DISP_DATA_OUT(0x4c);
DISP_DATA_OUT(0x58);
DISP_DATA_OUT(0x5f);
DISP_DATA_OUT(0x66);
DISP_DATA_OUT(0x6b);
DISP_DATA_OUT(0x70);
DISP_DATA_OUT(0x74);
DISP_DATA_OUT(0x78);
DISP_DATA_OUT(0x7b);
DISP_DATA_OUT(0x7e);
DISP_DATA_OUT(0x80);
DISP_DATA_OUT(0x82);
DISP_CMD_OUT(DISP_CMD_MD_CSET);
DISP_DATA_OUT(0xff);
DISP_DATA_OUT(0x03);
DISP_DATA_OUT(0xff);
DISP_DATA_OUT(0x03);
DISP_CMD_OUT(DISP_CMD_MD_PSET);
DISP_DATA_OUT(0xff);
DISP_DATA_OUT(0x01);
DISP_DATA_OUT(0xff);
DISP_DATA_OUT(0x01);
DISP_CMD_OUT(DISP_CMD_SD_CSET);
DISP_DATA_OUT(0x02);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT((QCIF_WIDTH + 1) & 0xFF);
DISP_DATA_OUT((QCIF_WIDTH + 1) >> 8);
DISP_CMD_OUT(DISP_CMD_SD_PSET);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT(0x00);
DISP_DATA_OUT((QCIF_HEIGHT - 1) & 0xFF);
DISP_DATA_OUT((QCIF_HEIGHT - 1) >> 8);
DISP_CMD_OUT(DISP_CMD_GSSET);
DISP_DATA_OUT(DISP_GS_64);
DISP_CMD_OUT(DISP_CMD_OSSEL);
DISP_DATA_OUT(0);
DISP_CMD_OUT(DISP_CMD_SLPOUT);
WAIT_SEC(40000);
DISP_CMD_OUT(DISP_CMD_VOLCTL);
DISP_DATA_OUT(DISP_VOLCTL_TONE);
WAIT_SEC(40000);
DISP_CMD_OUT(DISP_CMD_VOLCTL);
DISP_DATA_OUT(DISP_DEFAULT_CONTRAST);
DISP_SET_RECT(0, (QCIF_HEIGHT - 1), 0, (QCIF_WIDTH - 1));
DISP_CMD_OUT(DISP_CMD_RAMWR);
for (i = 0; i < QCIF_HEIGHT * QCIF_WIDTH; i++)
DISP_DATA_OUT(0xffff);
DISP_CMD_OUT(DISP_CMD_RAMRD);
databack = DISP_DATA_IN();
databack = DISP_DATA_IN();
databack = DISP_DATA_IN();
databack = DISP_DATA_IN();
WAIT_SEC(80000);
DISP_CMD_OUT(DISP_CMD_DISON);
disp_area_start_row = 0;
disp_area_end_row = QCIF_HEIGHT - 1;
disp_powered_up = TRUE;
disp_initialized = TRUE;
epsonQcif_disp_set_display_area(0, QCIF_HEIGHT - 1);
display_on = TRUE;
}
static void epsonQcif_disp_set_rect(int x, int y, int xres, int yres)
{
if (!disp_initialized)
return;
DISP_SET_RECT(y, y + yres - 1, x, x + xres - 1);
DISP_CMD_OUT(DISP_CMD_RAMWR);
}
static void epsonQcif_disp_set_display_area(word start_row, word end_row)
{
if (!disp_initialized)
return;
if ((start_row == disp_area_start_row)
&& (end_row == disp_area_end_row))
return;
disp_area_start_row = start_row;
disp_area_end_row = end_row;
if (end_row >= QCIF_HEIGHT)
end_row = QCIF_HEIGHT - 1;
if (start_row > end_row)
start_row = end_row;
if ((start_row == 0) && (end_row == (QCIF_HEIGHT - 1))) {
DISP_CMD_OUT(DISP_CMD_PTLOUT);
WAIT_SEC(10000);
DISP_CMD_OUT(DISP_CMD_DISOFF);
WAIT_SEC(100000);
DISP_CMD_OUT(DISP_CMD_GSSET);
DISP_DATA_OUT(DISP_GS_64);
WAIT_SEC(100000);
DISP_CMD_OUT(DISP_CMD_DISON);
} else {
DISP_CMD_OUT(DISP_CMD_PTLIN);
DISP_DATA_OUT(start_row);
DISP_DATA_OUT(start_row >> 8);
DISP_DATA_OUT(end_row);
DISP_DATA_OUT(end_row >> 8);
DISP_CMD_OUT(DISP_CMD_GSSET);
DISP_DATA_OUT(DISP_GS_2);
}
}
static int epsonQcif_disp_off(struct platform_device *pdev)
{
if (!disp_initialized)
epsonQcif_disp_init(pdev);
if (display_on) {
DISP_CMD_OUT(DISP_CMD_DISOFF);
DISP_CMD_OUT(DISP_CMD_SLPIN);
display_on = FALSE;
}
return 0;
}
static int epsonQcif_disp_on(struct platform_device *pdev)
{
if (!disp_initialized)
epsonQcif_disp_init(pdev);
if (!display_on) {
DISP_CMD_OUT(DISP_CMD_SLPOUT);
WAIT_SEC(40000);
DISP_CMD_OUT(DISP_CMD_DISON);
epsonQcif_disp_set_contrast(disp_contrast);
display_on = TRUE;
}
return 0;
}
static void epsonQcif_disp_set_contrast(word contrast)
{
if (!disp_initialized)
return;
DISP_CMD_OUT(DISP_CMD_VOLCTL);
DISP_DATA_OUT(DISP_VOLCTL_TONE);
WAIT_SEC(40000);
DISP_CMD_OUT(DISP_CMD_VOLCTL);
if (contrast > 127)
contrast = 127;
DISP_DATA_OUT(contrast);
disp_contrast = (byte) contrast;
}
static void epsonQcif_disp_clear_screen_area(
word start_row, word end_row, word start_column, word end_column) {
int32 i;
DISP_SET_RECT(start_row, end_row, start_column, end_column);
DISP_CMD_OUT(DISP_CMD_RAMWR);
i = (end_row - start_row + 1) * (end_column - start_column + 1);
for (; i > 0; i--)
DISP_DATA_OUT(0xffff);
}
static int __init epsonQcif_probe(struct platform_device *pdev)
{
msm_fb_add_device(pdev);
return 0;
}
static int __init epsonQcif_init(void)
{
int ret;
struct msm_panel_info *pinfo;
ret = platform_driver_register(&this_driver);
if (!ret) {
pinfo = &epsonQcif_panel_data.panel_info;
pinfo->xres = QCIF_WIDTH;
pinfo->yres = QCIF_HEIGHT;
pinfo->type = EBI2_PANEL;
pinfo->pdest = DISPLAY_2;
pinfo->wait_cycle = 0x808000;
pinfo->bpp = 16;
pinfo->fb_num = 2;
pinfo->lcd.vsync_enable = FALSE;
ret = platform_device_register(&this_device);
if (ret)
platform_driver_unregister(&this_driver);
}
return ret;
}
