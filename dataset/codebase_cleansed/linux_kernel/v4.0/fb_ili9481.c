static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x2a, xs >> 8, xs & 0xff, xe >> 8, xe & 0xff);
write_reg(par, 0x2b, ys >> 8, ys & 0xff, ye >> 8, ye & 0xff);
write_reg(par, 0x2c);
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
switch (par->info->var.rotate) {
case 270:
write_reg(par, 0x36, ROWxCOL | HFLIP | VFLIP | (par->bgr << 3));
break;
case 180:
write_reg(par, 0x36, VFLIP | (par->bgr << 3));
break;
case 90:
write_reg(par, 0x36, ROWxCOL | (par->bgr << 3));
break;
default:
write_reg(par, 0x36, HFLIP | (par->bgr << 3));
break;
}
return 0;
}
