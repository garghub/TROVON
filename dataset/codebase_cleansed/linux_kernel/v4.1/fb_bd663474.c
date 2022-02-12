static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
if (par->gpio.cs != -1)
gpio_set_value(par->gpio.cs, 0);
par->fbtftops.reset(par);
write_reg(par, 0x000, 0x0001);
mdelay(10);
write_reg(par, 0x100, 0x0000);
write_reg(par, 0x101, 0x0000);
write_reg(par, 0x102, 0x3110);
write_reg(par, 0x103, 0xe200);
write_reg(par, 0x110, 0x009d);
write_reg(par, 0x111, 0x0022);
write_reg(par, 0x100, 0x0120);
mdelay(20);
write_reg(par, 0x100, 0x3120);
mdelay(80);
write_reg(par, 0x001, 0x0100);
write_reg(par, 0x002, 0x0000);
write_reg(par, 0x003, 0x1230);
write_reg(par, 0x006, 0x0000);
write_reg(par, 0x007, 0x0101);
write_reg(par, 0x008, 0x0808);
write_reg(par, 0x009, 0x0000);
write_reg(par, 0x00b, 0x0000);
write_reg(par, 0x00c, 0x0000);
write_reg(par, 0x00d, 0x0018);
write_reg(par, 0x012, 0x0000);
write_reg(par, 0x013, 0x0000);
write_reg(par, 0x018, 0x0000);
write_reg(par, 0x019, 0x0000);
write_reg(par, 0x203, 0x0000);
write_reg(par, 0x204, 0x0000);
write_reg(par, 0x210, 0x0000);
write_reg(par, 0x211, 0x00ef);
write_reg(par, 0x212, 0x0000);
write_reg(par, 0x213, 0x013f);
write_reg(par, 0x214, 0x0000);
write_reg(par, 0x215, 0x0000);
write_reg(par, 0x216, 0x0000);
write_reg(par, 0x217, 0x0000);
write_reg(par, 0x300, 0x5343);
write_reg(par, 0x301, 0x1021);
write_reg(par, 0x302, 0x0003);
write_reg(par, 0x303, 0x0011);
write_reg(par, 0x304, 0x050a);
write_reg(par, 0x305, 0x4342);
write_reg(par, 0x306, 0x1100);
write_reg(par, 0x307, 0x0003);
write_reg(par, 0x308, 0x1201);
write_reg(par, 0x309, 0x050a);
write_reg(par, 0x400, 0x4027);
write_reg(par, 0x401, 0x0000);
write_reg(par, 0x402, 0x0000);
write_reg(par, 0x403, 0x013f);
write_reg(par, 0x404, 0x0000);
write_reg(par, 0x200, 0x0000);
write_reg(par, 0x201, 0x0000);
write_reg(par, 0x100, 0x7120);
write_reg(par, 0x007, 0x0103);
mdelay(10);
write_reg(par, 0x007, 0x0113);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x0200, xs);
write_reg(par, 0x0201, ys);
break;
case 180:
write_reg(par, 0x0200, WIDTH - 1 - xs);
write_reg(par, 0x0201, HEIGHT - 1 - ys);
break;
case 270:
write_reg(par, 0x0200, WIDTH - 1 - ys);
write_reg(par, 0x0201, xs);
break;
case 90:
write_reg(par, 0x0200, ys);
write_reg(par, 0x0201, HEIGHT - 1 - xs);
break;
}
write_reg(par, 0x202);
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x003, 0x1230);
break;
case 180:
write_reg(par, 0x003, 0x1200);
break;
case 270:
write_reg(par, 0x003, 0x1228);
break;
case 90:
write_reg(par, 0x003, 0x1218);
break;
}
return 0;
}
