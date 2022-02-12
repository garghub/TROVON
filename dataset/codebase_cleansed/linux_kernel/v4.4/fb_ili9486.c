static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
write_reg(par, 0x2A, xs >> 8, xs & 0xFF, xe >> 8, xe & 0xFF);
write_reg(par, 0x2B, ys >> 8, ys & 0xFF, ye >> 8, ye & 0xFF);
write_reg(par, 0x2C);
}
static int set_var(struct fbtft_par *par)
{
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x36, 0x80 | (par->bgr << 3));
break;
case 90:
write_reg(par, 0x36, 0x20 | (par->bgr << 3));
break;
case 180:
write_reg(par, 0x36, 0x40 | (par->bgr << 3));
break;
case 270:
write_reg(par, 0x36, 0xE0 | (par->bgr << 3));
break;
default:
break;
}
return 0;
}
