static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
xs >> 8, xs & 0xff, xe >> 8, xe & 0xff);
write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
ys >> 8, ys & 0xff, ye >> 8, ye & 0xff);
write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
}
static int set_var(struct fbtft_par *par)
{
switch (par->info->var.rotate) {
case 270:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
ROW_X_COL | HFLIP | VFLIP | (par->bgr << 3));
break;
case 180:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
VFLIP | (par->bgr << 3));
break;
case 90:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
ROW_X_COL | (par->bgr << 3));
break;
default:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
HFLIP | (par->bgr << 3));
break;
}
return 0;
}
