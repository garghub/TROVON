static int send_i2c_data(struct i2c_client *client,
struct sii9022_i2c_addr_data *regset,
int size)
{
int i;
int rc = 0;
for (i = 0; i < size; i++) {
rc = i2c_smbus_write_byte_data(
client,
regset[i].addr, regset[i].data);
if (rc)
break;
}
return rc;
}
static int hdmi_sii_enable(struct i2c_client *client)
{
int rc;
int retries = 10;
int count;
rc = i2c_smbus_write_byte_data(client, 0xC7, 0x00);
if (rc)
goto enable_exit;
do {
msleep(1);
rc = i2c_smbus_read_byte_data(client, 0x1B);
} while ((rc != SII9022_DEVICE_ID) && retries--);
if (rc != SII9022_DEVICE_ID)
return -ENODEV;
rc = i2c_smbus_write_byte_data(client, 0x1A, 0x11);
if (rc)
goto enable_exit;
count = ARRAY_SIZE(video_mode_data);
rc = i2c_master_send(client, video_mode_data, count);
if (rc != count) {
rc = -EIO;
goto enable_exit;
}
rc = i2c_smbus_write_byte_data(client, 0x08, 0x20);
if (rc)
goto enable_exit;
count = ARRAY_SIZE(avi_io_format);
rc = i2c_master_send(client, avi_io_format, count);
if (rc != count) {
rc = -EIO;
goto enable_exit;
}
rc = send_i2c_data(client, regset0, ARRAY_SIZE(regset0));
if (rc)
goto enable_exit;
count = ARRAY_SIZE(video_infoframe);
rc = i2c_master_send(client, video_infoframe, count);
if (rc != count) {
rc = -EIO;
goto enable_exit;
}
rc = send_i2c_data(client, regset1, ARRAY_SIZE(regset1));
if (rc)
goto enable_exit;
count = ARRAY_SIZE(misc_infoframe);
rc = i2c_master_send(client, misc_infoframe, count);
if (rc != count) {
rc = -EIO;
goto enable_exit;
}
rc = send_i2c_data(client, regset2, ARRAY_SIZE(regset2));
if (rc)
goto enable_exit;
return 0;
enable_exit:
printk(KERN_ERR "%s: exited rc=%d\n", __func__, rc);
return rc;
}
static int hdmi_sii_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int rc;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE | I2C_FUNC_I2C))
return -ENODEV;
rc = hdmi_sii_enable(client);
return rc;
}
static int __init lcdc_st15_init(void)
{
int ret;
struct msm_panel_info pinfo;
if (msm_fb_detect_client("lcdc_st15"))
return 0;
pinfo.xres = 1366;
pinfo.yres = 768;
pinfo.type = LCDC_PANEL;
pinfo.pdest = DISPLAY_1;
pinfo.wait_cycle = 0;
pinfo.bpp = 24;
pinfo.fb_num = 2;
pinfo.clk_rate = 74250000;
pinfo.lcdc.h_back_porch = 120;
pinfo.lcdc.h_front_porch = 20;
pinfo.lcdc.h_pulse_width = 40;
pinfo.lcdc.v_back_porch = 25;
pinfo.lcdc.v_front_porch = 1;
pinfo.lcdc.v_pulse_width = 7;
pinfo.lcdc.border_clr = 0;
pinfo.lcdc.underflow_clr = 0xff;
pinfo.lcdc.hsync_skew = 0;
ret = lcdc_device_register(&pinfo);
if (ret) {
printk(KERN_ERR "%s: failed to register device!\n", __func__);
goto init_exit;
}
ret = i2c_add_driver(&hdmi_sii_i2c_driver);
if (ret)
printk(KERN_ERR "%s: failed to add i2c driver\n", __func__);
init_exit:
return ret;
}
