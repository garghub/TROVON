static int init_display(struct fbtft_par *par)
{
u8 i;
par->fbtftops.reset(par);
for (i = 0; i < 2; ++i) {
write_reg(par, i, 0x3f);
write_reg(par, i, 0x40);
write_reg(par, i, 0xb0);
write_reg(par, i, 0xc0);
}
return 0;
}
static void reset(struct fbtft_par *par)
{
if (par->gpio.reset == -1)
return;
dev_dbg(par->info->device, "%s()\n", __func__);
gpio_set_value(par->gpio.reset, 0);
udelay(20);
gpio_set_value(par->gpio.reset, 1);
mdelay(120);
}
static int verify_gpios(struct fbtft_par *par)
{
int i;
dev_dbg(par->info->device,
"%s()\n", __func__);
if (par->EPIN < 0) {
dev_err(par->info->device,
"Missing info about 'wr' (aka E) gpio. Aborting.\n");
return -EINVAL;
}
for (i = 0; i < 8; ++i) {
if (par->gpio.db[i] < 0) {
dev_err(par->info->device,
"Missing info about 'db[%i]' gpio. Aborting.\n",
i);
return -EINVAL;
}
}
if (par->CS0 < 0) {
dev_err(par->info->device,
"Missing info about 'cs0' gpio. Aborting.\n");
return -EINVAL;
}
if (par->CS1 < 0) {
dev_err(par->info->device,
"Missing info about 'cs1' gpio. Aborting.\n");
return -EINVAL;
}
if (par->RW < 0) {
dev_err(par->info->device,
"Missing info about 'rw' gpio. Aborting.\n");
return -EINVAL;
}
return 0;
}
static unsigned long
request_gpios_match(struct fbtft_par *par, const struct fbtft_gpio *gpio)
{
dev_dbg(par->info->device,
"%s('%s')\n", __func__, gpio->name);
if (strcasecmp(gpio->name, "wr") == 0) {
par->EPIN = gpio->gpio;
return GPIOF_OUT_INIT_LOW;
} else if (strcasecmp(gpio->name, "cs0") == 0) {
par->CS0 = gpio->gpio;
return GPIOF_OUT_INIT_HIGH;
} else if (strcasecmp(gpio->name, "cs1") == 0) {
par->CS1 = gpio->gpio;
return GPIOF_OUT_INIT_HIGH;
}
else if (strcasecmp(gpio->name, "rw") == 0) {
par->RW = gpio->gpio;
return GPIOF_OUT_INIT_LOW;
}
return FBTFT_GPIO_NO_MATCH;
}
static void write_reg8_bus8(struct fbtft_par *par, int len, ...)
{
va_list args;
int i, ret;
u8 *buf = par->buf;
if (unlikely(par->debug & DEBUG_WRITE_REGISTER)) {
va_start(args, len);
for (i = 0; i < len; i++)
buf[i] = (u8)va_arg(args, unsigned int);
va_end(args);
fbtft_par_dbg_hex(DEBUG_WRITE_REGISTER, par, par->info->device,
u8, buf, len, "%s: ", __func__);
}
va_start(args, len);
*buf = (u8)va_arg(args, unsigned int);
if (*buf > 1) {
va_end(args);
dev_err(par->info->device,
"Incorrect chip select request (%d)\n", *buf);
return;
}
if (*buf) {
gpio_set_value(par->CS0, 1);
gpio_set_value(par->CS1, 0);
} else {
gpio_set_value(par->CS0, 0);
gpio_set_value(par->CS1, 1);
}
gpio_set_value(par->RS, 0);
len--;
if (len) {
i = len;
while (i--)
*buf++ = (u8)va_arg(args, unsigned int);
ret = par->fbtftops.write(par, par->buf, len * (sizeof(u8)));
if (ret < 0) {
va_end(args);
dev_err(par->info->device,
"write() failed and returned %d\n", ret);
return;
}
}
va_end(args);
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
addr_win.xs = xs;
addr_win.ys_page = ys / 8;
addr_win.xe = xe;
addr_win.ye_page = ye / 8;
}
static void
construct_line_bitmap(struct fbtft_par *par, u8 *dest, signed short *src,
int xs, int xe, int y)
{
int x, i;
for (x = xs; x < xe; ++x) {
u8 res = 0;
for (i = 0; i < 8; i++)
if (src[(y * 8 + i) * par->info->var.xres + x])
res |= 1 << i;
#ifdef NEGATIVE
*dest++ = res;
#else
*dest++ = ~res;
#endif
}
}
static void iterate_diffusion_matrix(u32 xres, u32 yres, int x,
int y, signed short *convert_buf,
signed short pixel, signed short error)
{
u16 i, j;
for (i = 0; i < DIFFUSING_MATRIX_WIDTH; ++i)
for (j = 0; j < DIFFUSING_MATRIX_HEIGHT; ++j) {
signed short *write_pos;
signed char coeff;
if (x + i < 0 || x + i >= xres || y + j >= yres)
continue;
write_pos = &convert_buf[(y + j) * xres + x + i];
coeff = diffusing_matrix[i][j];
if (-1 == coeff)
*write_pos = pixel;
else {
signed short p = *write_pos + error * coeff;
if (p > WHITE)
p = WHITE;
if (p < BLACK)
p = BLACK;
*write_pos = p;
}
}
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_buffer;
u8 *buf = par->txbuf.buf;
int x, y;
int ret = 0;
signed short *convert_buf = kmalloc_array(par->info->var.xres *
par->info->var.yres, sizeof(signed short), GFP_NOIO);
if (!convert_buf)
return -ENOMEM;
for (x = 0; x < par->info->var.xres; ++x)
for (y = 0; y < par->info->var.yres; ++y) {
u16 pixel = vmem16[y * par->info->var.xres + x];
u16 b = pixel & 0x1f;
u16 g = (pixel & (0x3f << 5)) >> 5;
u16 r = (pixel & (0x1f << (5 + 6))) >> (5 + 6);
pixel = (299 * r + 587 * g + 114 * b) / 200;
if (pixel > 255)
pixel = 255;
convert_buf[y * par->info->var.xres + x] =
(signed short)gamma_correction_table[pixel];
}
for (x = 0; x < par->info->var.xres; ++x)
for (y = 0; y < par->info->var.yres; ++y) {
signed short pixel =
convert_buf[y * par->info->var.xres + x];
signed short error_b = pixel - BLACK;
signed short error_w = pixel - WHITE;
signed short error;
if (abs(error_b) >= abs(error_w)) {
error = error_w;
pixel = 0xff;
} else {
error = error_b;
pixel = 0;
}
error /= 8;
iterate_diffusion_matrix(par->info->var.xres,
par->info->var.yres,
x, y, convert_buf,
pixel, error);
}
for (y = addr_win.ys_page; y <= addr_win.ye_page; ++y) {
if (addr_win.xs < par->info->var.xres / 2) {
construct_line_bitmap(par, buf, convert_buf,
addr_win.xs,
par->info->var.xres / 2, y);
len = par->info->var.xres / 2 - addr_win.xs;
write_reg(par, 0x00, (1 << 6) | (u8)addr_win.xs);
write_reg(par, 0x00, (0x17 << 3) | (u8)y);
gpio_set_value(par->RS, 1);
ret = par->fbtftops.write(par, buf, len);
if (ret < 0)
dev_err(par->info->device,
"write failed and returned: %d\n",
ret);
}
if (addr_win.xe >= par->info->var.xres / 2) {
construct_line_bitmap(par, buf,
convert_buf,
par->info->var.xres / 2,
addr_win.xe + 1, y);
len = addr_win.xe + 1 - par->info->var.xres / 2;
write_reg(par, 0x01, 1 << 6);
write_reg(par, 0x01, (0x17 << 3) | (u8)y);
gpio_set_value(par->RS, 1);
par->fbtftops.write(par, buf, len);
if (ret < 0)
dev_err(par->info->device,
"write failed and returned: %d\n",
ret);
}
}
kfree(convert_buf);
gpio_set_value(par->CS0, 1);
gpio_set_value(par->CS1, 1);
return ret;
}
static int write(struct fbtft_par *par, void *buf, size_t len)
{
fbtft_par_dbg_hex(DEBUG_WRITE, par, par->info->device, u8, buf, len,
"%s(len=%d): ", __func__, len);
gpio_set_value(par->RW, 0);
while (len--) {
u8 i, data;
data = *(u8 *)buf++;
for (i = 0; i < 8; ++i)
gpio_set_value(par->gpio.db[i], data & (1 << i));
gpio_set_value(par->EPIN, 1);
udelay(5);
gpio_set_value(par->EPIN, 0);
udelay(1);
}
return 0;
}
