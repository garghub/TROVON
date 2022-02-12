static inline u32 ipu_di_read(struct ipu_di *di, unsigned offset)
{
return readl(di->base + offset);
}
static inline void ipu_di_write(struct ipu_di *di, u32 value, unsigned offset)
{
writel(value, di->base + offset);
}
static int ipu_di_clk_calc_div(unsigned long inrate, unsigned long outrate)
{
u64 tmp = inrate;
int div;
tmp *= 16;
do_div(tmp, outrate);
div = tmp;
if (div < 0x10)
div = 0x10;
#ifdef WTF_IS_THIS
if (div & 0x10)
div &= ~0x7;
else {
if ((div & 0xC) == 0xC) {
div += 0x10;
div &= ~0xF;
}
}
#endif
return div;
}
static unsigned long clk_di_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ipu_di *di = container_of(hw, struct ipu_di, clk_hw_out);
unsigned long outrate;
u32 div = ipu_di_read(di, DI_BS_CLKGEN0);
if (div < 0x10)
div = 0x10;
outrate = (parent_rate / div) * 16;
return outrate;
}
static long clk_di_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct ipu_di *di = container_of(hw, struct ipu_di, clk_hw_out);
unsigned long outrate;
int div;
u32 val;
div = ipu_di_clk_calc_div(*prate, rate);
outrate = (*prate / div) * 16;
val = ipu_di_read(di, DI_GENERAL);
if (!(val & DI_GEN_DI_CLK_EXT) && outrate > *prate / 2)
outrate = *prate / 2;
dev_dbg(di->ipu->dev,
"%s: inrate: %ld div: 0x%08x outrate: %ld wanted: %ld\n",
__func__, *prate, div, outrate, rate);
return outrate;
}
static int clk_di_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct ipu_di *di = container_of(hw, struct ipu_di, clk_hw_out);
int div;
u32 clkgen0;
clkgen0 = ipu_di_read(di, DI_BS_CLKGEN0) & ~0xfff;
div = ipu_di_clk_calc_div(parent_rate, rate);
ipu_di_write(di, clkgen0 | div, DI_BS_CLKGEN0);
dev_dbg(di->ipu->dev, "%s: inrate: %ld desired: %ld div: 0x%08x\n",
__func__, parent_rate, rate, div);
return 0;
}
static u8 clk_di_get_parent(struct clk_hw *hw)
{
struct ipu_di *di = container_of(hw, struct ipu_di, clk_hw_out);
u32 val;
val = ipu_di_read(di, DI_GENERAL);
return val & DI_GEN_DI_CLK_EXT ? 1 : 0;
}
static int clk_di_set_parent(struct clk_hw *hw, u8 index)
{
struct ipu_di *di = container_of(hw, struct ipu_di, clk_hw_out);
u32 val;
val = ipu_di_read(di, DI_GENERAL);
if (index)
val |= DI_GEN_DI_CLK_EXT;
else
val &= ~DI_GEN_DI_CLK_EXT;
ipu_di_write(di, val, DI_GENERAL);
return 0;
}
static void ipu_di_data_wave_config(struct ipu_di *di,
int wave_gen,
int access_size, int component_size)
{
u32 reg;
reg = (access_size << DI_DW_GEN_ACCESS_SIZE_OFFSET) |
(component_size << DI_DW_GEN_COMPONENT_SIZE_OFFSET);
ipu_di_write(di, reg, DI_DW_GEN(wave_gen));
}
static void ipu_di_data_pin_config(struct ipu_di *di, int wave_gen, int di_pin,
int set, int up, int down)
{
u32 reg;
reg = ipu_di_read(di, DI_DW_GEN(wave_gen));
reg &= ~(0x3 << (di_pin * 2));
reg |= set << (di_pin * 2);
ipu_di_write(di, reg, DI_DW_GEN(wave_gen));
ipu_di_write(di, (down << 16) | up, DI_DW_SET(wave_gen, set));
}
static void ipu_di_sync_config(struct ipu_di *di, struct di_sync_config *config,
int start, int count)
{
u32 reg;
int i;
for (i = 0; i < count; i++) {
struct di_sync_config *c = &config[i];
int wave_gen = start + i + 1;
if ((c->run_count >= 0x1000) || (c->offset_count >= 0x1000) ||
(c->repeat_count >= 0x1000) ||
(c->cnt_up >= 0x400) ||
(c->cnt_down >= 0x400)) {
dev_err(di->ipu->dev, "DI%d counters out of range.\n",
di->id);
return;
}
reg = DI_SW_GEN0_RUN_COUNT(c->run_count) |
DI_SW_GEN0_RUN_SRC(c->run_src) |
DI_SW_GEN0_OFFSET_COUNT(c->offset_count) |
DI_SW_GEN0_OFFSET_SRC(c->offset_src);
ipu_di_write(di, reg, DI_SW_GEN0(wave_gen));
reg = DI_SW_GEN1_CNT_POL_GEN_EN(c->cnt_polarity_gen_en) |
DI_SW_GEN1_CNT_CLR_SRC(c->cnt_clr_src) |
DI_SW_GEN1_CNT_POL_TRIGGER_SRC(
c->cnt_polarity_trigger_src) |
DI_SW_GEN1_CNT_POL_CLR_SRC(c->cnt_polarity_clr_src) |
DI_SW_GEN1_CNT_DOWN(c->cnt_down) |
DI_SW_GEN1_CNT_UP(c->cnt_up);
if (c->repeat_count == 0)
reg |= DI_SW_GEN1_AUTO_RELOAD;
ipu_di_write(di, reg, DI_SW_GEN1(wave_gen));
reg = ipu_di_read(di, DI_STP_REP(wave_gen));
reg &= ~(0xffff << (16 * ((wave_gen - 1) & 0x1)));
reg |= c->repeat_count << (16 * ((wave_gen - 1) & 0x1));
ipu_di_write(di, reg, DI_STP_REP(wave_gen));
}
}
static void ipu_di_sync_config_interlaced(struct ipu_di *di,
struct ipu_di_signal_cfg *sig)
{
u32 h_total = sig->width + sig->h_sync_width +
sig->h_start_width + sig->h_end_width;
u32 v_total = sig->height + sig->v_sync_width +
sig->v_start_width + sig->v_end_width;
u32 reg;
struct di_sync_config cfg[] = {
{
.run_count = h_total / 2 - 1,
.run_src = DI_SYNC_CLK,
}, {
.run_count = h_total - 11,
.run_src = DI_SYNC_CLK,
.cnt_down = 4,
}, {
.run_count = v_total * 2 - 1,
.run_src = DI_SYNC_INT_HSYNC,
.offset_count = 1,
.offset_src = DI_SYNC_INT_HSYNC,
.cnt_down = 4,
}, {
.run_count = v_total / 2 - 1,
.run_src = DI_SYNC_HSYNC,
.offset_count = sig->v_start_width,
.offset_src = DI_SYNC_HSYNC,
.repeat_count = 2,
.cnt_clr_src = DI_SYNC_VSYNC,
}, {
.run_src = DI_SYNC_HSYNC,
.repeat_count = sig->height / 2,
.cnt_clr_src = 4,
}, {
.run_count = v_total - 1,
.run_src = DI_SYNC_HSYNC,
}, {
.run_count = v_total / 2 - 1,
.run_src = DI_SYNC_HSYNC,
.offset_count = 9,
.offset_src = DI_SYNC_HSYNC,
.repeat_count = 2,
.cnt_clr_src = DI_SYNC_VSYNC,
}, {
.run_src = DI_SYNC_CLK,
.offset_count = sig->h_start_width,
.offset_src = DI_SYNC_CLK,
.repeat_count = sig->width,
.cnt_clr_src = 5,
}, {
.run_count = v_total - 1,
.run_src = DI_SYNC_INT_HSYNC,
.offset_count = v_total / 2,
.offset_src = DI_SYNC_INT_HSYNC,
.cnt_clr_src = DI_SYNC_HSYNC,
.cnt_down = 4,
}
};
ipu_di_sync_config(di, cfg, 0, ARRAY_SIZE(cfg));
reg = ipu_di_read(di, DI_SW_GEN1(9));
reg &= 0x1FFFFFFF;
reg |= (3 - 1) << 29 | 0x00008000;
ipu_di_write(di, reg, DI_SW_GEN1(9));
ipu_di_write(di, v_total / 2 - 1, DI_SCR_CONF);
}
static void ipu_di_sync_config_noninterlaced(struct ipu_di *di,
struct ipu_di_signal_cfg *sig, int div)
{
u32 h_total = sig->width + sig->h_sync_width + sig->h_start_width +
sig->h_end_width;
u32 v_total = sig->height + sig->v_sync_width + sig->v_start_width +
sig->v_end_width;
struct di_sync_config cfg[] = {
{
.run_count = h_total - 1,
.run_src = DI_SYNC_CLK,
} , {
.run_count = h_total - 1,
.run_src = DI_SYNC_CLK,
.offset_count = div * sig->v_to_h_sync,
.offset_src = DI_SYNC_CLK,
.cnt_polarity_gen_en = 1,
.cnt_polarity_trigger_src = DI_SYNC_CLK,
.cnt_down = sig->h_sync_width * 2,
} , {
.run_count = v_total - 1,
.run_src = DI_SYNC_INT_HSYNC,
.cnt_polarity_gen_en = 1,
.cnt_polarity_trigger_src = DI_SYNC_INT_HSYNC,
.cnt_down = sig->v_sync_width * 2,
} , {
.run_src = DI_SYNC_HSYNC,
.offset_count = sig->v_sync_width + sig->v_start_width,
.offset_src = DI_SYNC_HSYNC,
.repeat_count = sig->height,
.cnt_clr_src = DI_SYNC_VSYNC,
} , {
.run_src = DI_SYNC_CLK,
.offset_count = sig->h_sync_width + sig->h_start_width,
.offset_src = DI_SYNC_CLK,
.repeat_count = sig->width,
.cnt_clr_src = 5,
} , {
} , {
} , {
} , {
},
};
struct di_sync_config cfg_vga[] = {
{
.run_count = h_total - 1,
.run_src = DI_SYNC_CLK,
} , {
.run_count = v_total - 1,
.run_src = DI_SYNC_INT_HSYNC,
} , {
.run_src = DI_SYNC_INT_HSYNC,
.offset_count = sig->v_sync_width + sig->v_start_width,
.offset_src = DI_SYNC_INT_HSYNC,
.repeat_count = sig->height,
.cnt_clr_src = 3 ,
} , {
.run_count = h_total - 1,
.run_src = DI_SYNC_CLK,
.offset_count = div * sig->v_to_h_sync + 18,
.offset_src = DI_SYNC_CLK,
.cnt_polarity_gen_en = 1,
.cnt_polarity_trigger_src = DI_SYNC_CLK,
.cnt_down = sig->h_sync_width * 2,
} , {
.run_src = DI_SYNC_CLK,
.offset_count = sig->h_sync_width + sig->h_start_width,
.offset_src = DI_SYNC_CLK,
.repeat_count = sig->width,
.cnt_clr_src = 4,
} , {
.run_count = v_total - 1,
.run_src = DI_SYNC_INT_HSYNC,
.offset_count = 1,
.offset_src = DI_SYNC_INT_HSYNC,
.cnt_polarity_gen_en = 1,
.cnt_polarity_trigger_src = DI_SYNC_INT_HSYNC,
.cnt_down = sig->v_sync_width * 2,
} , {
.run_count = h_total - 1,
.run_src = DI_SYNC_CLK,
.offset_count = div * sig->v_to_h_sync + 18,
.offset_src = DI_SYNC_CLK,
.cnt_polarity_gen_en = 1,
.cnt_polarity_trigger_src = DI_SYNC_CLK,
.cnt_down = sig->h_sync_width * 2,
} , {
.run_count = v_total - 1,
.run_src = DI_SYNC_INT_HSYNC,
.offset_count = 1,
.offset_src = DI_SYNC_INT_HSYNC,
.cnt_polarity_gen_en = 1,
.cnt_polarity_trigger_src = DI_SYNC_INT_HSYNC,
.cnt_down = sig->v_sync_width * 2,
} , {
},
};
ipu_di_write(di, v_total - 1, DI_SCR_CONF);
if (sig->hsync_pin == 2 && sig->vsync_pin == 3)
ipu_di_sync_config(di, cfg, 0, ARRAY_SIZE(cfg));
else
ipu_di_sync_config(di, cfg_vga, 0, ARRAY_SIZE(cfg_vga));
}
int ipu_di_init_sync_panel(struct ipu_di *di, struct ipu_di_signal_cfg *sig)
{
u32 reg;
u32 di_gen, vsync_cnt;
u32 div;
u32 h_total, v_total;
int ret;
unsigned long round;
struct clk *parent;
dev_dbg(di->ipu->dev, "disp %d: panel size = %d x %d\n",
di->id, sig->width, sig->height);
if ((sig->v_sync_width == 0) || (sig->h_sync_width == 0))
return -EINVAL;
if (sig->clkflags & IPU_DI_CLKMODE_EXT)
parent = di->clk_di;
else
parent = di->clk_ipu;
ret = clk_set_parent(di->clk_di_pixel, parent);
if (ret) {
dev_err(di->ipu->dev,
"setting pixel clock to parent %s failed with %d\n",
__clk_get_name(parent), ret);
return ret;
}
if (sig->clkflags & IPU_DI_CLKMODE_SYNC)
round = clk_get_rate(parent);
else
round = clk_round_rate(di->clk_di_pixel, sig->pixelclock);
ret = clk_set_rate(di->clk_di_pixel, round);
h_total = sig->width + sig->h_sync_width + sig->h_start_width +
sig->h_end_width;
v_total = sig->height + sig->v_sync_width + sig->v_start_width +
sig->v_end_width;
mutex_lock(&di_mutex);
div = ipu_di_read(di, DI_BS_CLKGEN0) & 0xfff;
div = div / 16;
ipu_di_write(di, (div << 16), DI_BS_CLKGEN1);
ipu_di_data_wave_config(di, SYNC_WAVE, div - 1, div - 1);
ipu_di_data_pin_config(di, SYNC_WAVE, DI_PIN15, 3, 0, div * 2);
di_gen = ipu_di_read(di, DI_GENERAL) & DI_GEN_DI_CLK_EXT;
di_gen |= DI_GEN_DI_VSYNC_EXT;
if (sig->interlaced) {
ipu_di_sync_config_interlaced(di, sig);
di_gen |= 0x10000000;
di_gen |= DI_GEN_POLARITY_5;
di_gen |= DI_GEN_POLARITY_8;
vsync_cnt = 7;
if (sig->Hsync_pol)
di_gen |= DI_GEN_POLARITY_3;
if (sig->Vsync_pol)
di_gen |= DI_GEN_POLARITY_2;
} else {
ipu_di_sync_config_noninterlaced(di, sig, div);
vsync_cnt = 3;
if (di->id == 1)
if (!(sig->hsync_pin == 2 && sig->vsync_pin == 3))
vsync_cnt = 6;
if (sig->Hsync_pol) {
if (sig->hsync_pin == 2)
di_gen |= DI_GEN_POLARITY_2;
else if (sig->hsync_pin == 4)
di_gen |= DI_GEN_POLARITY_4;
else if (sig->hsync_pin == 7)
di_gen |= DI_GEN_POLARITY_7;
}
if (sig->Vsync_pol) {
if (sig->vsync_pin == 3)
di_gen |= DI_GEN_POLARITY_3;
else if (sig->vsync_pin == 6)
di_gen |= DI_GEN_POLARITY_6;
else if (sig->vsync_pin == 8)
di_gen |= DI_GEN_POLARITY_8;
}
}
if (!sig->clk_pol)
di_gen |= DI_GEN_POLARITY_DISP_CLK;
ipu_di_write(di, di_gen, DI_GENERAL);
ipu_di_write(di, (--vsync_cnt << DI_VSYNC_SEL_OFFSET) | 0x00000002,
DI_SYNC_AS_GEN);
reg = ipu_di_read(di, DI_POL);
reg &= ~(DI_POL_DRDY_DATA_POLARITY | DI_POL_DRDY_POLARITY_15);
if (sig->enable_pol)
reg |= DI_POL_DRDY_POLARITY_15;
if (sig->data_pol)
reg |= DI_POL_DRDY_DATA_POLARITY;
ipu_di_write(di, reg, DI_POL);
mutex_unlock(&di_mutex);
return 0;
}
int ipu_di_enable(struct ipu_di *di)
{
clk_prepare_enable(di->clk_di_pixel);
ipu_module_enable(di->ipu, di->module);
return 0;
}
int ipu_di_disable(struct ipu_di *di)
{
ipu_module_disable(di->ipu, di->module);
clk_disable_unprepare(di->clk_di_pixel);
return 0;
}
int ipu_di_get_num(struct ipu_di *di)
{
return di->id;
}
struct ipu_di *ipu_di_get(struct ipu_soc *ipu, int disp)
{
struct ipu_di *di;
if (disp > 1)
return ERR_PTR(-EINVAL);
di = ipu->di_priv[disp];
mutex_lock(&ipu_di_lock);
if (di->inuse) {
di = ERR_PTR(-EBUSY);
goto out;
}
di->inuse = true;
out:
mutex_unlock(&ipu_di_lock);
return di;
}
void ipu_di_put(struct ipu_di *di)
{
mutex_lock(&ipu_di_lock);
di->inuse = false;
mutex_unlock(&ipu_di_lock);
}
int ipu_di_init(struct ipu_soc *ipu, struct device *dev, int id,
unsigned long base,
u32 module, struct clk *clk_ipu)
{
struct ipu_di *di;
int ret;
const char *di_parent[2];
struct clk_init_data init = {
.ops = &clk_di_ops,
.num_parents = 2,
.flags = 0,
};
if (id > 1)
return -ENODEV;
di = devm_kzalloc(dev, sizeof(*di), GFP_KERNEL);
if (!di)
return -ENOMEM;
ipu->di_priv[id] = di;
di->clk_di = devm_clk_get(dev, id ? "di1" : "di0");
if (IS_ERR(di->clk_di))
return PTR_ERR(di->clk_di);
di->module = module;
di->id = id;
di->clk_ipu = clk_ipu;
di->base = devm_ioremap(dev, base, PAGE_SIZE);
if (!di->base)
return -ENOMEM;
di_parent[0] = __clk_get_name(di->clk_ipu);
di_parent[1] = __clk_get_name(di->clk_di);
ipu_di_write(di, 0x10, DI_BS_CLKGEN0);
init.parent_names = (const char **)&di_parent;
di->clk_name = kasprintf(GFP_KERNEL, "%s_di%d_pixel",
dev_name(dev), id);
if (!di->clk_name)
return -ENOMEM;
init.name = di->clk_name;
di->clk_hw_out.init = &init;
di->clk_di_pixel = clk_register(dev, &di->clk_hw_out);
if (IS_ERR(di->clk_di_pixel)) {
ret = PTR_ERR(di->clk_di_pixel);
goto failed_clk_register;
}
dev_dbg(dev, "DI%d base: 0x%08lx remapped to %p\n",
id, base, di->base);
di->inuse = false;
di->ipu = ipu;
return 0;
failed_clk_register:
kfree(di->clk_name);
return ret;
}
void ipu_di_exit(struct ipu_soc *ipu, int id)
{
struct ipu_di *di = ipu->di_priv[id];
clk_unregister(di->clk_di_pixel);
kfree(di->clk_name);
}
