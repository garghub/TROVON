static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
xs >> 8, xs & 0xFF, xe >> 8, xe & 0xFF);
write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
ys >> 8, ys & 0xFF, ye >> 8, ye & 0xFF);
write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
}
static int set_var(struct fbtft_par *par)
{
switch (par->info->var.rotate) {
case 0:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
0x80 | (par->bgr << 3));
break;
case 90:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
0x20 | (par->bgr << 3));
break;
case 180:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
0x40 | (par->bgr << 3));
break;
case 270:
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE,
0xE0 | (par->bgr << 3));
break;
default:
break;
}
return 0;
}
