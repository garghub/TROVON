static inline void rfbi_write_reg(const struct rfbi_reg idx, u32 val)
{
__raw_writel(val, rfbi.base + idx.idx);
}
static inline u32 rfbi_read_reg(const struct rfbi_reg idx)
{
return __raw_readl(rfbi.base + idx.idx);
}
static int rfbi_runtime_get(void)
{
int r;
DSSDBG("rfbi_runtime_get\n");
r = pm_runtime_get_sync(&rfbi.pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
static void rfbi_runtime_put(void)
{
int r;
DSSDBG("rfbi_runtime_put\n");
r = pm_runtime_put_sync(&rfbi.pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS);
}
void rfbi_bus_lock(void)
{
down(&rfbi.bus_lock);
}
void rfbi_bus_unlock(void)
{
up(&rfbi.bus_lock);
}
void omap_rfbi_write_command(const void *buf, u32 len)
{
switch (rfbi.parallelmode) {
case OMAP_DSS_RFBI_PARALLELMODE_8:
{
const u8 *b = buf;
for (; len; len--)
rfbi_write_reg(RFBI_CMD, *b++);
break;
}
case OMAP_DSS_RFBI_PARALLELMODE_16:
{
const u16 *w = buf;
BUG_ON(len & 1);
for (; len; len -= 2)
rfbi_write_reg(RFBI_CMD, *w++);
break;
}
case OMAP_DSS_RFBI_PARALLELMODE_9:
case OMAP_DSS_RFBI_PARALLELMODE_12:
default:
BUG();
}
}
void omap_rfbi_read_data(void *buf, u32 len)
{
switch (rfbi.parallelmode) {
case OMAP_DSS_RFBI_PARALLELMODE_8:
{
u8 *b = buf;
for (; len; len--) {
rfbi_write_reg(RFBI_READ, 0);
*b++ = rfbi_read_reg(RFBI_READ);
}
break;
}
case OMAP_DSS_RFBI_PARALLELMODE_16:
{
u16 *w = buf;
BUG_ON(len & ~1);
for (; len; len -= 2) {
rfbi_write_reg(RFBI_READ, 0);
*w++ = rfbi_read_reg(RFBI_READ);
}
break;
}
case OMAP_DSS_RFBI_PARALLELMODE_9:
case OMAP_DSS_RFBI_PARALLELMODE_12:
default:
BUG();
}
}
void omap_rfbi_write_data(const void *buf, u32 len)
{
switch (rfbi.parallelmode) {
case OMAP_DSS_RFBI_PARALLELMODE_8:
{
const u8 *b = buf;
for (; len; len--)
rfbi_write_reg(RFBI_PARAM, *b++);
break;
}
case OMAP_DSS_RFBI_PARALLELMODE_16:
{
const u16 *w = buf;
BUG_ON(len & 1);
for (; len; len -= 2)
rfbi_write_reg(RFBI_PARAM, *w++);
break;
}
case OMAP_DSS_RFBI_PARALLELMODE_9:
case OMAP_DSS_RFBI_PARALLELMODE_12:
default:
BUG();
}
}
void omap_rfbi_write_pixels(const void __iomem *buf, int scr_width,
u16 x, u16 y,
u16 w, u16 h)
{
int start_offset = scr_width * y + x;
int horiz_offset = scr_width - w;
int i;
if (rfbi.datatype == OMAP_DSS_RFBI_DATATYPE_16 &&
rfbi.parallelmode == OMAP_DSS_RFBI_PARALLELMODE_8) {
const u16 __iomem *pd = buf;
pd += start_offset;
for (; h; --h) {
for (i = 0; i < w; ++i) {
const u8 __iomem *b = (const u8 __iomem *)pd;
rfbi_write_reg(RFBI_PARAM, __raw_readb(b+1));
rfbi_write_reg(RFBI_PARAM, __raw_readb(b+0));
++pd;
}
pd += horiz_offset;
}
} else if (rfbi.datatype == OMAP_DSS_RFBI_DATATYPE_24 &&
rfbi.parallelmode == OMAP_DSS_RFBI_PARALLELMODE_8) {
const u32 __iomem *pd = buf;
pd += start_offset;
for (; h; --h) {
for (i = 0; i < w; ++i) {
const u8 __iomem *b = (const u8 __iomem *)pd;
rfbi_write_reg(RFBI_PARAM, __raw_readb(b+2));
rfbi_write_reg(RFBI_PARAM, __raw_readb(b+1));
rfbi_write_reg(RFBI_PARAM, __raw_readb(b+0));
++pd;
}
pd += horiz_offset;
}
} else if (rfbi.datatype == OMAP_DSS_RFBI_DATATYPE_16 &&
rfbi.parallelmode == OMAP_DSS_RFBI_PARALLELMODE_16) {
const u16 __iomem *pd = buf;
pd += start_offset;
for (; h; --h) {
for (i = 0; i < w; ++i) {
rfbi_write_reg(RFBI_PARAM, __raw_readw(pd));
++pd;
}
pd += horiz_offset;
}
} else {
BUG();
}
}
static int rfbi_transfer_area(struct omap_dss_device *dssdev,
void (*callback)(void *data), void *data)
{
u32 l;
int r;
struct omap_overlay_manager *mgr = dssdev->output->manager;
u16 width = rfbi.timings.x_res;
u16 height = rfbi.timings.y_res;
BUG_ON(rfbi.framedone_callback != NULL);
DSSDBG("rfbi_transfer_area %dx%d\n", width, height);
dss_mgr_set_timings(mgr, &rfbi.timings);
r = dss_mgr_enable(mgr);
if (r)
return r;
rfbi.framedone_callback = callback;
rfbi.framedone_callback_data = data;
rfbi_write_reg(RFBI_PIXEL_CNT, width * height);
l = rfbi_read_reg(RFBI_CONTROL);
l = FLD_MOD(l, 1, 0, 0);
if (!rfbi.te_enabled)
l = FLD_MOD(l, 1, 4, 4);
rfbi_write_reg(RFBI_CONTROL, l);
return 0;
}
static void framedone_callback(void *data)
{
void (*callback)(void *data);
DSSDBG("FRAMEDONE\n");
REG_FLD_MOD(RFBI_CONTROL, 0, 0, 0);
callback = rfbi.framedone_callback;
rfbi.framedone_callback = NULL;
if (callback != NULL)
callback(rfbi.framedone_callback_data);
}
static void rfbi_print_timings(void)
{
u32 l;
u32 time;
l = rfbi_read_reg(RFBI_CONFIG(0));
time = 1000000000 / rfbi.l4_khz;
if (l & (1 << 4))
time *= 2;
DSSDBG("Tick time %u ps\n", time);
l = rfbi_read_reg(RFBI_ONOFF_TIME(0));
DSSDBG("CSONTIME %d, CSOFFTIME %d, WEONTIME %d, WEOFFTIME %d, "
"REONTIME %d, REOFFTIME %d\n",
l & 0x0f, (l >> 4) & 0x3f, (l >> 10) & 0x0f, (l >> 14) & 0x3f,
(l >> 20) & 0x0f, (l >> 24) & 0x3f);
l = rfbi_read_reg(RFBI_CYCLE_TIME(0));
DSSDBG("WECYCLETIME %d, RECYCLETIME %d, CSPULSEWIDTH %d, "
"ACCESSTIME %d\n",
(l & 0x3f), (l >> 6) & 0x3f, (l >> 12) & 0x3f,
(l >> 22) & 0x3f);
}
static void rfbi_print_timings(void) {}
static inline unsigned long round_to_extif_ticks(unsigned long ps, int div)
{
int bus_tick = extif_clk_period * div;
return (ps + bus_tick - 1) / bus_tick * bus_tick;
}
static int calc_reg_timing(struct rfbi_timings *t, int div)
{
t->clk_div = div;
t->cs_on_time = round_to_extif_ticks(t->cs_on_time, div);
t->we_on_time = round_to_extif_ticks(t->we_on_time, div);
t->we_off_time = round_to_extif_ticks(t->we_off_time, div);
t->we_cycle_time = round_to_extif_ticks(t->we_cycle_time, div);
t->re_on_time = round_to_extif_ticks(t->re_on_time, div);
t->re_off_time = round_to_extif_ticks(t->re_off_time, div);
t->re_cycle_time = round_to_extif_ticks(t->re_cycle_time, div);
t->access_time = round_to_extif_ticks(t->access_time, div);
t->cs_off_time = round_to_extif_ticks(t->cs_off_time, div);
t->cs_pulse_width = round_to_extif_ticks(t->cs_pulse_width, div);
DSSDBG("[reg]cson %d csoff %d reon %d reoff %d\n",
t->cs_on_time, t->cs_off_time, t->re_on_time, t->re_off_time);
DSSDBG("[reg]weon %d weoff %d recyc %d wecyc %d\n",
t->we_on_time, t->we_off_time, t->re_cycle_time,
t->we_cycle_time);
DSSDBG("[reg]rdaccess %d cspulse %d\n",
t->access_time, t->cs_pulse_width);
return rfbi_convert_timings(t);
}
static int calc_extif_timings(struct rfbi_timings *t)
{
u32 max_clk_div;
int div;
rfbi_get_clk_info(&extif_clk_period, &max_clk_div);
for (div = 1; div <= max_clk_div; div++) {
if (calc_reg_timing(t, div) == 0)
break;
}
if (div <= max_clk_div)
return 0;
DSSERR("can't setup timings\n");
return -1;
}
static void rfbi_set_timings(int rfbi_module, struct rfbi_timings *t)
{
int r;
if (!t->converted) {
r = calc_extif_timings(t);
if (r < 0)
DSSERR("Failed to calc timings\n");
}
BUG_ON(!t->converted);
rfbi_write_reg(RFBI_ONOFF_TIME(rfbi_module), t->tim[0]);
rfbi_write_reg(RFBI_CYCLE_TIME(rfbi_module), t->tim[1]);
REG_FLD_MOD(RFBI_CONFIG(rfbi_module),
(t->tim[2] ? 1 : 0), 4, 4);
rfbi_print_timings();
}
static int ps_to_rfbi_ticks(int time, int div)
{
unsigned long tick_ps;
int ret;
tick_ps = 1000000000 / (rfbi.l4_khz) * div;
ret = (time + tick_ps - 1) / tick_ps;
return ret;
}
static void rfbi_get_clk_info(u32 *clk_period, u32 *max_clk_div)
{
*clk_period = 1000000000 / rfbi.l4_khz;
*max_clk_div = 2;
}
static int rfbi_convert_timings(struct rfbi_timings *t)
{
u32 l;
int reon, reoff, weon, weoff, cson, csoff, cs_pulse;
int actim, recyc, wecyc;
int div = t->clk_div;
if (div <= 0 || div > 2)
return -1;
weon = ps_to_rfbi_ticks(t->we_on_time, div);
weoff = ps_to_rfbi_ticks(t->we_off_time, div);
if (weoff <= weon)
weoff = weon + 1;
if (weon > 0x0f)
return -1;
if (weoff > 0x3f)
return -1;
reon = ps_to_rfbi_ticks(t->re_on_time, div);
reoff = ps_to_rfbi_ticks(t->re_off_time, div);
if (reoff <= reon)
reoff = reon + 1;
if (reon > 0x0f)
return -1;
if (reoff > 0x3f)
return -1;
cson = ps_to_rfbi_ticks(t->cs_on_time, div);
csoff = ps_to_rfbi_ticks(t->cs_off_time, div);
if (csoff <= cson)
csoff = cson + 1;
if (csoff < max(weoff, reoff))
csoff = max(weoff, reoff);
if (cson > 0x0f)
return -1;
if (csoff > 0x3f)
return -1;
l = cson;
l |= csoff << 4;
l |= weon << 10;
l |= weoff << 14;
l |= reon << 20;
l |= reoff << 24;
t->tim[0] = l;
actim = ps_to_rfbi_ticks(t->access_time, div);
if (actim <= reon)
actim = reon + 1;
if (actim > 0x3f)
return -1;
wecyc = ps_to_rfbi_ticks(t->we_cycle_time, div);
if (wecyc < weoff)
wecyc = weoff;
if (wecyc > 0x3f)
return -1;
recyc = ps_to_rfbi_ticks(t->re_cycle_time, div);
if (recyc < reoff)
recyc = reoff;
if (recyc > 0x3f)
return -1;
cs_pulse = ps_to_rfbi_ticks(t->cs_pulse_width, div);
if (cs_pulse > 0x3f)
return -1;
l = wecyc;
l |= recyc << 6;
l |= cs_pulse << 12;
l |= actim << 22;
t->tim[1] = l;
t->tim[2] = div - 1;
t->converted = 1;
return 0;
}
int omap_rfbi_setup_te(enum omap_rfbi_te_mode mode,
unsigned hs_pulse_time, unsigned vs_pulse_time,
int hs_pol_inv, int vs_pol_inv, int extif_div)
{
int hs, vs;
int min;
u32 l;
hs = ps_to_rfbi_ticks(hs_pulse_time, 1);
vs = ps_to_rfbi_ticks(vs_pulse_time, 1);
if (hs < 2)
return -EDOM;
if (mode == OMAP_DSS_RFBI_TE_MODE_2)
min = 2;
else
min = 4;
if (vs < min)
return -EDOM;
if (vs == hs)
return -EINVAL;
rfbi.te_mode = mode;
DSSDBG("setup_te: mode %d hs %d vs %d hs_inv %d vs_inv %d\n",
mode, hs, vs, hs_pol_inv, vs_pol_inv);
rfbi_write_reg(RFBI_HSYNC_WIDTH, hs);
rfbi_write_reg(RFBI_VSYNC_WIDTH, vs);
l = rfbi_read_reg(RFBI_CONFIG(0));
if (hs_pol_inv)
l &= ~(1 << 21);
else
l |= 1 << 21;
if (vs_pol_inv)
l &= ~(1 << 20);
else
l |= 1 << 20;
return 0;
}
int omap_rfbi_enable_te(bool enable, unsigned line)
{
u32 l;
DSSDBG("te %d line %d mode %d\n", enable, line, rfbi.te_mode);
if (line > (1 << 11) - 1)
return -EINVAL;
l = rfbi_read_reg(RFBI_CONFIG(0));
l &= ~(0x3 << 2);
if (enable) {
rfbi.te_enabled = 1;
l |= rfbi.te_mode << 2;
} else
rfbi.te_enabled = 0;
rfbi_write_reg(RFBI_CONFIG(0), l);
rfbi_write_reg(RFBI_LINE_NUMBER, line);
return 0;
}
static int rfbi_configure(int rfbi_module, int bpp, int lines)
{
u32 l;
int cycle1 = 0, cycle2 = 0, cycle3 = 0;
enum omap_rfbi_cycleformat cycleformat;
enum omap_rfbi_datatype datatype;
enum omap_rfbi_parallelmode parallelmode;
switch (bpp) {
case 12:
datatype = OMAP_DSS_RFBI_DATATYPE_12;
break;
case 16:
datatype = OMAP_DSS_RFBI_DATATYPE_16;
break;
case 18:
datatype = OMAP_DSS_RFBI_DATATYPE_18;
break;
case 24:
datatype = OMAP_DSS_RFBI_DATATYPE_24;
break;
default:
BUG();
return 1;
}
rfbi.datatype = datatype;
switch (lines) {
case 8:
parallelmode = OMAP_DSS_RFBI_PARALLELMODE_8;
break;
case 9:
parallelmode = OMAP_DSS_RFBI_PARALLELMODE_9;
break;
case 12:
parallelmode = OMAP_DSS_RFBI_PARALLELMODE_12;
break;
case 16:
parallelmode = OMAP_DSS_RFBI_PARALLELMODE_16;
break;
default:
BUG();
return 1;
}
rfbi.parallelmode = parallelmode;
if ((bpp % lines) == 0) {
switch (bpp / lines) {
case 1:
cycleformat = OMAP_DSS_RFBI_CYCLEFORMAT_1_1;
break;
case 2:
cycleformat = OMAP_DSS_RFBI_CYCLEFORMAT_2_1;
break;
case 3:
cycleformat = OMAP_DSS_RFBI_CYCLEFORMAT_3_1;
break;
default:
BUG();
return 1;
}
} else if ((2 * bpp % lines) == 0) {
if ((2 * bpp / lines) == 3)
cycleformat = OMAP_DSS_RFBI_CYCLEFORMAT_3_2;
else {
BUG();
return 1;
}
} else {
BUG();
return 1;
}
switch (cycleformat) {
case OMAP_DSS_RFBI_CYCLEFORMAT_1_1:
cycle1 = lines;
break;
case OMAP_DSS_RFBI_CYCLEFORMAT_2_1:
cycle1 = lines;
cycle2 = lines;
break;
case OMAP_DSS_RFBI_CYCLEFORMAT_3_1:
cycle1 = lines;
cycle2 = lines;
cycle3 = lines;
break;
case OMAP_DSS_RFBI_CYCLEFORMAT_3_2:
cycle1 = lines;
cycle2 = (lines / 2) | ((lines / 2) << 16);
cycle3 = (lines << 16);
break;
}
REG_FLD_MOD(RFBI_CONTROL, 0, 3, 2);
l = 0;
l |= FLD_VAL(parallelmode, 1, 0);
l |= FLD_VAL(0, 3, 2);
l |= FLD_VAL(0, 4, 4);
l |= FLD_VAL(datatype, 6, 5);
l |= FLD_VAL(0, 8, 7);
l |= FLD_VAL(cycleformat, 10, 9);
l |= FLD_VAL(0, 12, 11);
l |= FLD_VAL(0, 16, 16);
l |= FLD_VAL(0, 17, 17);
l |= FLD_VAL(0, 18, 18);
l |= FLD_VAL(0, 19, 19);
l |= FLD_VAL(1, 20, 20);
l |= FLD_VAL(1, 21, 21);
rfbi_write_reg(RFBI_CONFIG(rfbi_module), l);
rfbi_write_reg(RFBI_DATA_CYCLE1(rfbi_module), cycle1);
rfbi_write_reg(RFBI_DATA_CYCLE2(rfbi_module), cycle2);
rfbi_write_reg(RFBI_DATA_CYCLE3(rfbi_module), cycle3);
l = rfbi_read_reg(RFBI_CONTROL);
l = FLD_MOD(l, rfbi_module+1, 3, 2);
l = FLD_MOD(l, 0, 1, 1);
rfbi_write_reg(RFBI_CONTROL, l);
DSSDBG("RFBI config: bpp %d, lines %d, cycles: 0x%x 0x%x 0x%x\n",
bpp, lines, cycle1, cycle2, cycle3);
return 0;
}
int omap_rfbi_configure(struct omap_dss_device *dssdev)
{
return rfbi_configure(dssdev->phy.rfbi.channel, rfbi.pixel_size,
rfbi.data_lines);
}
int omap_rfbi_update(struct omap_dss_device *dssdev, void (*callback)(void *),
void *data)
{
return rfbi_transfer_area(dssdev, callback, data);
}
void omapdss_rfbi_set_size(struct omap_dss_device *dssdev, u16 w, u16 h)
{
rfbi.timings.x_res = w;
rfbi.timings.y_res = h;
}
void omapdss_rfbi_set_pixel_size(struct omap_dss_device *dssdev, int pixel_size)
{
rfbi.pixel_size = pixel_size;
}
void omapdss_rfbi_set_data_lines(struct omap_dss_device *dssdev, int data_lines)
{
rfbi.data_lines = data_lines;
}
void omapdss_rfbi_set_interface_timings(struct omap_dss_device *dssdev,
struct rfbi_timings *timings)
{
rfbi.intf_timings = *timings;
}
static void rfbi_dump_regs(struct seq_file *s)
{
#define DUMPREG(r) seq_printf(s, "%-35s %08x\n", #r, rfbi_read_reg(r))
if (rfbi_runtime_get())
return;
DUMPREG(RFBI_REVISION);
DUMPREG(RFBI_SYSCONFIG);
DUMPREG(RFBI_SYSSTATUS);
DUMPREG(RFBI_CONTROL);
DUMPREG(RFBI_PIXEL_CNT);
DUMPREG(RFBI_LINE_NUMBER);
DUMPREG(RFBI_CMD);
DUMPREG(RFBI_PARAM);
DUMPREG(RFBI_DATA);
DUMPREG(RFBI_READ);
DUMPREG(RFBI_STATUS);
DUMPREG(RFBI_CONFIG(0));
DUMPREG(RFBI_ONOFF_TIME(0));
DUMPREG(RFBI_CYCLE_TIME(0));
DUMPREG(RFBI_DATA_CYCLE1(0));
DUMPREG(RFBI_DATA_CYCLE2(0));
DUMPREG(RFBI_DATA_CYCLE3(0));
DUMPREG(RFBI_CONFIG(1));
DUMPREG(RFBI_ONOFF_TIME(1));
DUMPREG(RFBI_CYCLE_TIME(1));
DUMPREG(RFBI_DATA_CYCLE1(1));
DUMPREG(RFBI_DATA_CYCLE2(1));
DUMPREG(RFBI_DATA_CYCLE3(1));
DUMPREG(RFBI_VSYNC_WIDTH);
DUMPREG(RFBI_HSYNC_WIDTH);
rfbi_runtime_put();
#undef DUMPREG
}
static void rfbi_config_lcd_manager(struct omap_dss_device *dssdev)
{
struct omap_overlay_manager *mgr = dssdev->output->manager;
struct dss_lcd_mgr_config mgr_config;
mgr_config.io_pad_mode = DSS_IO_PAD_MODE_RFBI;
mgr_config.stallmode = true;
mgr_config.fifohandcheck = false;
mgr_config.video_port_width = rfbi.pixel_size;
mgr_config.lcden_sig_polarity = 0;
dss_mgr_set_lcd_config(mgr, &mgr_config);
rfbi.timings.hsw = 1;
rfbi.timings.hfp = 1;
rfbi.timings.hbp = 1;
rfbi.timings.vsw = 1;
rfbi.timings.vfp = 0;
rfbi.timings.vbp = 0;
rfbi.timings.interlace = false;
rfbi.timings.hsync_level = OMAPDSS_SIG_ACTIVE_HIGH;
rfbi.timings.vsync_level = OMAPDSS_SIG_ACTIVE_HIGH;
rfbi.timings.data_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
rfbi.timings.de_level = OMAPDSS_SIG_ACTIVE_HIGH;
rfbi.timings.sync_pclk_edge = OMAPDSS_DRIVE_SIG_OPPOSITE_EDGES;
dss_mgr_set_timings(mgr, &rfbi.timings);
}
int omapdss_rfbi_display_enable(struct omap_dss_device *dssdev)
{
struct omap_dss_output *out = dssdev->output;
int r;
if (out == NULL || out->manager == NULL) {
DSSERR("failed to enable display: no output/manager\n");
return -ENODEV;
}
r = rfbi_runtime_get();
if (r)
return r;
r = omap_dss_start_device(dssdev);
if (r) {
DSSERR("failed to start device\n");
goto err0;
}
r = dss_mgr_register_framedone_handler(out->manager,
framedone_callback, NULL);
if (r) {
DSSERR("can't get FRAMEDONE irq\n");
goto err1;
}
rfbi_config_lcd_manager(dssdev);
rfbi_configure(dssdev->phy.rfbi.channel, rfbi.pixel_size,
rfbi.data_lines);
rfbi_set_timings(dssdev->phy.rfbi.channel, &rfbi.intf_timings);
return 0;
err1:
omap_dss_stop_device(dssdev);
err0:
rfbi_runtime_put();
return r;
}
void omapdss_rfbi_display_disable(struct omap_dss_device *dssdev)
{
struct omap_dss_output *out = dssdev->output;
dss_mgr_unregister_framedone_handler(out->manager,
framedone_callback, NULL);
omap_dss_stop_device(dssdev);
rfbi_runtime_put();
}
static int __init rfbi_init_display(struct omap_dss_device *dssdev)
{
rfbi.dssdev[dssdev->phy.rfbi.channel] = dssdev;
return 0;
}
static struct omap_dss_device * __init rfbi_find_dssdev(struct platform_device *pdev)
{
struct omap_dss_board_info *pdata = pdev->dev.platform_data;
const char *def_disp_name = omapdss_get_default_display_name();
struct omap_dss_device *def_dssdev;
int i;
def_dssdev = NULL;
for (i = 0; i < pdata->num_devices; ++i) {
struct omap_dss_device *dssdev = pdata->devices[i];
if (dssdev->type != OMAP_DISPLAY_TYPE_DBI)
continue;
if (def_dssdev == NULL)
def_dssdev = dssdev;
if (def_disp_name != NULL &&
strcmp(dssdev->name, def_disp_name) == 0) {
def_dssdev = dssdev;
break;
}
}
return def_dssdev;
}
static void __init rfbi_probe_pdata(struct platform_device *rfbidev)
{
struct omap_dss_device *plat_dssdev;
struct omap_dss_device *dssdev;
int r;
plat_dssdev = rfbi_find_dssdev(rfbidev);
if (!plat_dssdev)
return;
dssdev = dss_alloc_and_init_device(&rfbidev->dev);
if (!dssdev)
return;
dss_copy_device_pdata(dssdev, plat_dssdev);
r = rfbi_init_display(dssdev);
if (r) {
DSSERR("device %s init failed: %d\n", dssdev->name, r);
dss_put_device(dssdev);
return;
}
r = omapdss_output_set_device(&rfbi.output, dssdev);
if (r) {
DSSERR("failed to connect output to new device: %s\n",
dssdev->name);
dss_put_device(dssdev);
return;
}
r = dss_add_device(dssdev);
if (r) {
DSSERR("device %s register failed: %d\n", dssdev->name, r);
omapdss_output_unset_device(&rfbi.output);
dss_put_device(dssdev);
return;
}
}
static void __init rfbi_init_output(struct platform_device *pdev)
{
struct omap_dss_output *out = &rfbi.output;
out->pdev = pdev;
out->id = OMAP_DSS_OUTPUT_DBI;
out->type = OMAP_DISPLAY_TYPE_DBI;
dss_register_output(out);
}
static void __exit rfbi_uninit_output(struct platform_device *pdev)
{
struct omap_dss_output *out = &rfbi.output;
dss_unregister_output(out);
}
static int __init omap_rfbihw_probe(struct platform_device *pdev)
{
u32 rev;
struct resource *rfbi_mem;
struct clk *clk;
int r;
rfbi.pdev = pdev;
sema_init(&rfbi.bus_lock, 1);
rfbi_mem = platform_get_resource(rfbi.pdev, IORESOURCE_MEM, 0);
if (!rfbi_mem) {
DSSERR("can't get IORESOURCE_MEM RFBI\n");
return -EINVAL;
}
rfbi.base = devm_ioremap(&pdev->dev, rfbi_mem->start,
resource_size(rfbi_mem));
if (!rfbi.base) {
DSSERR("can't ioremap RFBI\n");
return -ENOMEM;
}
clk = clk_get(&pdev->dev, "ick");
if (IS_ERR(clk)) {
DSSERR("can't get ick\n");
return PTR_ERR(clk);
}
rfbi.l4_khz = clk_get_rate(clk) / 1000;
clk_put(clk);
pm_runtime_enable(&pdev->dev);
r = rfbi_runtime_get();
if (r)
goto err_runtime_get;
msleep(10);
rev = rfbi_read_reg(RFBI_REVISION);
dev_dbg(&pdev->dev, "OMAP RFBI rev %d.%d\n",
FLD_GET(rev, 7, 4), FLD_GET(rev, 3, 0));
rfbi_runtime_put();
dss_debugfs_create_file("rfbi", rfbi_dump_regs);
rfbi_init_output(pdev);
rfbi_probe_pdata(pdev);
return 0;
err_runtime_get:
pm_runtime_disable(&pdev->dev);
return r;
}
static int __exit omap_rfbihw_remove(struct platform_device *pdev)
{
dss_unregister_child_devices(&pdev->dev);
rfbi_uninit_output(pdev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int rfbi_runtime_suspend(struct device *dev)
{
dispc_runtime_put();
return 0;
}
static int rfbi_runtime_resume(struct device *dev)
{
int r;
r = dispc_runtime_get();
if (r < 0)
return r;
return 0;
}
int __init rfbi_init_platform_driver(void)
{
return platform_driver_probe(&omap_rfbihw_driver, omap_rfbihw_probe);
}
void __exit rfbi_uninit_platform_driver(void)
{
platform_driver_unregister(&omap_rfbihw_driver);
}
