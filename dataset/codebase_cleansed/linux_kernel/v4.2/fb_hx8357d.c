static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
write_reg(par, HX8357B_SWRESET);
usleep_range(5000, 7000);
write_reg(par, HX8357D_SETC, 0xFF, 0x83, 0x57);
msleep(150);
write_reg(par, HX8357_SETRGB, 0x00, 0x00, 0x06, 0x06);
write_reg(par, HX8357D_SETCOM, 0x25);
write_reg(par, HX8357_SETOSC, 0x68);
write_reg(par, HX8357_SETPANEL, 0x05);
write_reg(par, HX8357_SETPWR1,
0x00,
0x15,
0x1C,
0x1C,
0x83,
0xAA);
write_reg(par, HX8357D_SETSTBA,
0x50,
0x50,
0x01,
0x3C,
0x1E,
0x08);
write_reg(par, HX8357D_SETCYC,
0x02,
0x40,
0x00,
0x2A,
0x2A,
0x0D,
0x78);
write_reg(par, HX8357D_SETGAMMA,
0x02,
0x0A,
0x11,
0x1d,
0x23,
0x35,
0x41,
0x4b,
0x4b,
0x42,
0x3A,
0x27,
0x1B,
0x08,
0x09,
0x03,
0x02,
0x0A,
0x11,
0x1d,
0x23,
0x35,
0x41,
0x4b,
0x4b,
0x42,
0x3A,
0x27,
0x1B,
0x08,
0x09,
0x03,
0x00,
0x01);
write_reg(par, HX8357_COLMOD, 0x55);
write_reg(par, HX8357_MADCTL, 0xC0);
write_reg(par, HX8357_TEON, 0x00);
write_reg(par, HX8357_TEARLINE, 0x00, 0x02);
write_reg(par, HX8357_SLPOUT);
msleep(150);
write_reg(par, HX8357_DISPON);
usleep_range(5000, 7000);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, HX8357_CASET,
xs >> 8, xs & 0xff,
xe >> 8, xe & 0xff);
write_reg(par, HX8357_PASET,
ys >> 8, ys & 0xff,
ye >> 8, ye & 0xff);
write_reg(par, HX8357_RAMWR);
}
static int set_var(struct fbtft_par *par)
{
u8 val;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
switch (par->info->var.rotate) {
case 270:
val = HX8357D_MADCTL_MV | HX8357D_MADCTL_MX;
break;
case 180:
val = 0;
break;
case 90:
val = HX8357D_MADCTL_MV | HX8357D_MADCTL_MY;
break;
default:
val = HX8357D_MADCTL_MX | HX8357D_MADCTL_MY;
break;
}
val |= (par->bgr ? HX8357D_MADCTL_RGB : HX8357D_MADCTL_BGR);
write_reg(par, HX8357_MADCTL, val);
return 0;
}
