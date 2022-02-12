static int init_display(struct fbtft_par *par)
{
write_reg(par, MIPI_DCS_EXIT_SLEEP_MODE);
mdelay(120);
write_reg(par, MIPI_DCS_SET_PIXEL_FORMAT, MIPI_DCS_PIXEL_FMT_16BIT);
write_reg(par, PORCTRL, 0x08, 0x08, 0x00, 0x22, 0x22);
write_reg(par, GCTRL, 0x35);
write_reg(par, VDVVRHEN, 0x01, 0xFF);
write_reg(par, VRHS, 0x0B);
write_reg(par, VDVS, 0x20);
write_reg(par, VCOMS, 0x20);
write_reg(par, VCMOFSET, 0x20);
write_reg(par, PWCTRL1, 0xA4, 0xA1);
write_reg(par, MIPI_DCS_SET_DISPLAY_ON);
return 0;
}
static int set_var(struct fbtft_par *par)
{
u8 madctl_par = 0;
if (par->bgr)
madctl_par |= MADCTL_BGR;
switch (par->info->var.rotate) {
case 0:
break;
case 90:
madctl_par |= (MADCTL_MV | MADCTL_MY);
break;
case 180:
madctl_par |= (MADCTL_MX | MADCTL_MY);
break;
case 270:
madctl_par |= (MADCTL_MV | MADCTL_MX);
break;
default:
return -EINVAL;
}
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE, madctl_par);
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
int i;
int j;
int c;
const u8 gamma_par_mask[] = {
0xFF,
0x3F,
0x3F,
0x1F,
0x1F,
0x3F,
0x7F,
0x77,
0x7F,
0x3F,
0x1F,
0x1F,
0x3F,
0x3F,
};
for (i = 0; i < par->gamma.num_curves; i++) {
c = i * par->gamma.num_values;
for (j = 0; j < par->gamma.num_values; j++)
curves[c + j] &= gamma_par_mask[j];
write_reg(
par, PVGAMCTRL + i,
curves[c + 0], curves[c + 1], curves[c + 2],
curves[c + 3], curves[c + 4], curves[c + 5],
curves[c + 6], curves[c + 7], curves[c + 8],
curves[c + 9], curves[c + 10], curves[c + 11],
curves[c + 12], curves[c + 13]);
}
return 0;
}
static int blank(struct fbtft_par *par, bool on)
{
if (on)
write_reg(par, MIPI_DCS_SET_DISPLAY_OFF);
else
write_reg(par, MIPI_DCS_SET_DISPLAY_ON);
return 0;
}
