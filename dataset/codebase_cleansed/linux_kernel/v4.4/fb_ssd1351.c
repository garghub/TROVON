static int init_display(struct fbtft_par *par)
{
if (par->pdata
&& par->pdata->display.backlight == FBTFT_ONBOARD_BACKLIGHT) {
par->fbtftops.register_backlight = register_onboard_backlight;
}
par->fbtftops.reset(par);
write_reg(par, 0xfd, 0x12);
write_reg(par, 0xfd, 0xb1);
write_reg(par, 0xae);
write_reg(par, 0xb3, 0xf1);
write_reg(par, 0xca, 0x7f);
write_reg(par, 0x15, 0x00, 0x7f);
write_reg(par, 0x75, 0x00, 0x7f);
write_reg(par, 0xa1, 0x00);
write_reg(par, 0xa2, 0x00);
write_reg(par, 0xb5, 0x00);
write_reg(par, 0xab, 0x01);
write_reg(par, 0xb1, 0x32);
write_reg(par, 0xb4, 0xa0, 0xb5, 0x55);
write_reg(par, 0xbb, 0x17);
write_reg(par, 0xbe, 0x05);
write_reg(par, 0xc1, 0xc8, 0x80, 0xc8);
write_reg(par, 0xc7, 0x0f);
write_reg(par, 0xb6, 0x01);
write_reg(par, 0xa6);
write_reg(par, 0xaf);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
write_reg(par, 0x15, xs, xe);
write_reg(par, 0x75, ys, ye);
write_reg(par, 0x5c);
}
static int set_var(struct fbtft_par *par)
{
unsigned remap;
if (par->fbtftops.init_display != init_display) {
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par,
"%s: skipping since custom init_display() is used\n",
__func__);
return 0;
}
remap = 0x60 | (par->bgr << 2);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0xA0, remap | 0x00 | 1<<4);
break;
case 270:
write_reg(par, 0xA0, remap | 0x03 | 1<<4);
break;
case 180:
write_reg(par, 0xA0, remap | 0x02);
break;
case 90:
write_reg(par, 0xA0, remap | 0x01);
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
unsigned long tmp[GAMMA_NUM * GAMMA_LEN];
int i, acc = 0;
for (i = 0; i < 63; i++) {
if (i > 0 && curves[i] < 2) {
dev_err(par->info->device,
"Illegal value in Grayscale Lookup Table at index %d. " \
"Must be greater than 1\n", i);
return -EINVAL;
}
acc += curves[i];
tmp[i] = acc;
if (acc > 180) {
dev_err(par->info->device,
"Illegal value(s) in Grayscale Lookup Table. " \
"At index=%d, the accumulated value has exceeded 180\n", i);
return -EINVAL;
}
}
write_reg(par, 0xB8,
tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], tmp[7],
tmp[8], tmp[9], tmp[10], tmp[11], tmp[12], tmp[13], tmp[14], tmp[15],
tmp[16], tmp[17], tmp[18], tmp[19], tmp[20], tmp[21], tmp[22], tmp[23],
tmp[24], tmp[25], tmp[26], tmp[27], tmp[28], tmp[29], tmp[30], tmp[31],
tmp[32], tmp[33], tmp[34], tmp[35], tmp[36], tmp[37], tmp[38], tmp[39],
tmp[40], tmp[41], tmp[42], tmp[43], tmp[44], tmp[45], tmp[46], tmp[47],
tmp[48], tmp[49], tmp[50], tmp[51], tmp[52], tmp[53], tmp[54], tmp[55],
tmp[56], tmp[57], tmp[58], tmp[59], tmp[60], tmp[61], tmp[62]);
return 0;
}
static int blank(struct fbtft_par *par, bool on)
{
fbtft_par_dbg(DEBUG_BLANK, par, "%s(blank=%s)\n",
__func__, on ? "true" : "false");
if (on)
write_reg(par, 0xAE);
else
write_reg(par, 0xAF);
return 0;
}
static int update_onboard_backlight(struct backlight_device *bd)
{
struct fbtft_par *par = bl_get_data(bd);
bool on;
fbtft_par_dbg(DEBUG_BACKLIGHT, par,
"%s: power=%d, fb_blank=%d\n",
__func__, bd->props.power, bd->props.fb_blank);
on = (bd->props.power == FB_BLANK_UNBLANK)
&& (bd->props.fb_blank == FB_BLANK_UNBLANK);
write_reg(par, 0xB5, on ? 0x03 : 0x02);
return 0;
}
static void register_onboard_backlight(struct fbtft_par *par)
{
struct backlight_device *bd;
struct backlight_properties bl_props = { 0, };
bl_props.type = BACKLIGHT_RAW;
bl_props.power = FB_BLANK_POWERDOWN;
bd = backlight_device_register(dev_driver_string(par->info->device),
par->info->device, par, &bl_ops, &bl_props);
if (IS_ERR(bd)) {
dev_err(par->info->device,
"cannot register backlight device (%ld)\n",
PTR_ERR(bd));
return;
}
par->info->bl_dev = bd;
if (!par->fbtftops.unregister_backlight)
par->fbtftops.unregister_backlight = fbtft_unregister_backlight;
}
static void register_onboard_backlight(struct fbtft_par *par) { }
