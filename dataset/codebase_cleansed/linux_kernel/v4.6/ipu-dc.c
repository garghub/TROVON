static void dc_link_event(struct ipu_dc *dc, int event, int addr, int priority)
{
u32 reg;
reg = readl(dc->base + DC_RL_CH(event));
reg &= ~(0xffff << (16 * (event & 0x1)));
reg |= ((addr << 8) | priority) << (16 * (event & 0x1));
writel(reg, dc->base + DC_RL_CH(event));
}
static void dc_write_tmpl(struct ipu_dc *dc, int word, u32 opcode, u32 operand,
int map, int wave, int glue, int sync, int stop)
{
struct ipu_dc_priv *priv = dc->priv;
u32 reg1, reg2;
if (opcode == WCLK) {
reg1 = (operand << 20) & 0xfff00000;
reg2 = operand >> 12 | opcode << 1 | stop << 9;
} else if (opcode == WRG) {
reg1 = sync | glue << 4 | ++wave << 11 | ((operand << 15) & 0xffff8000);
reg2 = operand >> 17 | opcode << 7 | stop << 9;
} else {
reg1 = sync | glue << 4 | ++wave << 11 | ++map << 15 | ((operand << 20) & 0xfff00000);
reg2 = operand >> 12 | opcode << 4 | stop << 9;
}
writel(reg1, priv->dc_tmpl_reg + word * 8);
writel(reg2, priv->dc_tmpl_reg + word * 8 + 4);
}
static int ipu_bus_format_to_map(u32 fmt)
{
switch (fmt) {
case MEDIA_BUS_FMT_RGB888_1X24:
return IPU_DC_MAP_RGB24;
case MEDIA_BUS_FMT_RGB565_1X16:
return IPU_DC_MAP_RGB565;
case MEDIA_BUS_FMT_GBR888_1X24:
return IPU_DC_MAP_GBR24;
case MEDIA_BUS_FMT_RGB666_1X18:
return IPU_DC_MAP_BGR666;
case MEDIA_BUS_FMT_RGB666_1X24_CPADHI:
return IPU_DC_MAP_LVDS666;
case MEDIA_BUS_FMT_BGR888_1X24:
return IPU_DC_MAP_BGR24;
default:
return -EINVAL;
}
}
int ipu_dc_init_sync(struct ipu_dc *dc, struct ipu_di *di, bool interlaced,
u32 bus_format, u32 width)
{
struct ipu_dc_priv *priv = dc->priv;
int addr, sync;
u32 reg = 0;
int map;
dc->di = ipu_di_get_num(di);
map = ipu_bus_format_to_map(bus_format);
if (map < 0) {
dev_dbg(priv->dev, "IPU_DISP: No MAP\n");
return map;
}
sync = interlaced ? 6 : 5;
if (dc->di)
addr = 5;
else
addr = 0;
if (interlaced) {
dc_link_event(dc, DC_EVT_NL, addr, 3);
dc_link_event(dc, DC_EVT_EOL, addr, 2);
dc_link_event(dc, DC_EVT_NEW_DATA, addr, 1);
dc_write_tmpl(dc, addr, WROD(0), 0, map, SYNC_WAVE, 0, sync, 1);
} else {
dc_link_event(dc, DC_EVT_NL, addr + 2, 3);
dc_link_event(dc, DC_EVT_EOL, addr + 3, 2);
dc_link_event(dc, DC_EVT_NEW_DATA, addr + 1, 1);
dc_write_tmpl(dc, addr + 2, WROD(0), 0, map, SYNC_WAVE, 8, sync, 1);
dc_write_tmpl(dc, addr + 3, WROD(0), 0, map, SYNC_WAVE, 4, sync, 0);
dc_write_tmpl(dc, addr + 4, WRG, 0, map, NULL_WAVE, 0, 0, 1);
dc_write_tmpl(dc, addr + 1, WROD(0), 0, map, SYNC_WAVE, 0, sync, 1);
}
dc_link_event(dc, DC_EVT_NF, 0, 0);
dc_link_event(dc, DC_EVT_NFIELD, 0, 0);
dc_link_event(dc, DC_EVT_EOF, 0, 0);
dc_link_event(dc, DC_EVT_EOFIELD, 0, 0);
dc_link_event(dc, DC_EVT_NEW_CHAN, 0, 0);
dc_link_event(dc, DC_EVT_NEW_ADDR, 0, 0);
reg = readl(dc->base + DC_WR_CH_CONF);
if (interlaced)
reg |= DC_WR_CH_CONF_FIELD_MODE;
else
reg &= ~DC_WR_CH_CONF_FIELD_MODE;
writel(reg, dc->base + DC_WR_CH_CONF);
writel(0x0, dc->base + DC_WR_CH_ADDR);
writel(width, priv->dc_reg + DC_DISP_CONF2(dc->di));
return 0;
}
void ipu_dc_enable(struct ipu_soc *ipu)
{
struct ipu_dc_priv *priv = ipu->dc_priv;
mutex_lock(&priv->mutex);
if (!priv->use_count)
ipu_module_enable(priv->ipu, IPU_CONF_DC_EN);
priv->use_count++;
mutex_unlock(&priv->mutex);
}
void ipu_dc_enable_channel(struct ipu_dc *dc)
{
int di;
u32 reg;
di = dc->di;
reg = readl(dc->base + DC_WR_CH_CONF);
reg |= DC_WR_CH_CONF_PROG_TYPE_NORMAL;
writel(reg, dc->base + DC_WR_CH_CONF);
}
static irqreturn_t dc_irq_handler(int irq, void *dev_id)
{
struct ipu_dc *dc = dev_id;
u32 reg;
reg = readl(dc->base + DC_WR_CH_CONF);
reg &= ~DC_WR_CH_CONF_PROG_TYPE_MASK;
writel(reg, dc->base + DC_WR_CH_CONF);
complete(&dc->priv->comp);
return IRQ_HANDLED;
}
void ipu_dc_disable_channel(struct ipu_dc *dc)
{
struct ipu_dc_priv *priv = dc->priv;
int irq;
unsigned long ret;
u32 val;
if (dc->chno == 1)
irq = priv->dc_irq;
else if (dc->chno == 5)
irq = priv->dp_irq;
else
return;
init_completion(&priv->comp);
enable_irq(irq);
ret = wait_for_completion_timeout(&priv->comp, msecs_to_jiffies(50));
disable_irq(irq);
if (ret == 0) {
dev_warn(priv->dev, "DC stop timeout after 50 ms\n");
val = readl(dc->base + DC_WR_CH_CONF);
val &= ~DC_WR_CH_CONF_PROG_TYPE_MASK;
writel(val, dc->base + DC_WR_CH_CONF);
}
}
void ipu_dc_disable(struct ipu_soc *ipu)
{
struct ipu_dc_priv *priv = ipu->dc_priv;
mutex_lock(&priv->mutex);
priv->use_count--;
if (!priv->use_count)
ipu_module_disable(priv->ipu, IPU_CONF_DC_EN);
if (priv->use_count < 0)
priv->use_count = 0;
mutex_unlock(&priv->mutex);
}
static void ipu_dc_map_config(struct ipu_dc_priv *priv, enum ipu_dc_map map,
int byte_num, int offset, int mask)
{
int ptr = map * 3 + byte_num;
u32 reg;
reg = readl(priv->dc_reg + DC_MAP_CONF_VAL(ptr));
reg &= ~(0xffff << (16 * (ptr & 0x1)));
reg |= ((offset << 8) | mask) << (16 * (ptr & 0x1));
writel(reg, priv->dc_reg + DC_MAP_CONF_VAL(ptr));
reg = readl(priv->dc_reg + DC_MAP_CONF_PTR(map));
reg &= ~(0x1f << ((16 * (map & 0x1)) + (5 * byte_num)));
reg |= ptr << ((16 * (map & 0x1)) + (5 * byte_num));
writel(reg, priv->dc_reg + DC_MAP_CONF_PTR(map));
}
static void ipu_dc_map_clear(struct ipu_dc_priv *priv, int map)
{
u32 reg = readl(priv->dc_reg + DC_MAP_CONF_PTR(map));
writel(reg & ~(0xffff << (16 * (map & 0x1))),
priv->dc_reg + DC_MAP_CONF_PTR(map));
}
struct ipu_dc *ipu_dc_get(struct ipu_soc *ipu, int channel)
{
struct ipu_dc_priv *priv = ipu->dc_priv;
struct ipu_dc *dc;
if (channel >= IPU_DC_NUM_CHANNELS)
return ERR_PTR(-ENODEV);
dc = &priv->channels[channel];
mutex_lock(&priv->mutex);
if (dc->in_use) {
mutex_unlock(&priv->mutex);
return ERR_PTR(-EBUSY);
}
dc->in_use = true;
mutex_unlock(&priv->mutex);
return dc;
}
void ipu_dc_put(struct ipu_dc *dc)
{
struct ipu_dc_priv *priv = dc->priv;
mutex_lock(&priv->mutex);
dc->in_use = false;
mutex_unlock(&priv->mutex);
}
int ipu_dc_init(struct ipu_soc *ipu, struct device *dev,
unsigned long base, unsigned long template_base)
{
struct ipu_dc_priv *priv;
static int channel_offsets[] = { 0, 0x1c, 0x38, 0x54, 0x58, 0x5c,
0x78, 0, 0x94, 0xb4};
int i, ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mutex_init(&priv->mutex);
priv->dev = dev;
priv->ipu = ipu;
priv->dc_reg = devm_ioremap(dev, base, PAGE_SIZE);
priv->dc_tmpl_reg = devm_ioremap(dev, template_base, PAGE_SIZE);
if (!priv->dc_reg || !priv->dc_tmpl_reg)
return -ENOMEM;
for (i = 0; i < IPU_DC_NUM_CHANNELS; i++) {
priv->channels[i].chno = i;
priv->channels[i].priv = priv;
priv->channels[i].base = priv->dc_reg + channel_offsets[i];
}
priv->dc_irq = ipu_map_irq(ipu, IPU_IRQ_DC_FC_1);
if (!priv->dc_irq)
return -EINVAL;
ret = devm_request_irq(dev, priv->dc_irq, dc_irq_handler, 0, NULL,
&priv->channels[1]);
if (ret < 0)
return ret;
disable_irq(priv->dc_irq);
priv->dp_irq = ipu_map_irq(ipu, IPU_IRQ_DP_SF_END);
if (!priv->dp_irq)
return -EINVAL;
ret = devm_request_irq(dev, priv->dp_irq, dc_irq_handler, 0, NULL,
&priv->channels[5]);
if (ret < 0)
return ret;
disable_irq(priv->dp_irq);
writel(DC_WR_CH_CONF_WORD_SIZE_24 | DC_WR_CH_CONF_DISP_ID_PARALLEL(1) |
DC_WR_CH_CONF_PROG_DI_ID,
priv->channels[1].base + DC_WR_CH_CONF);
writel(DC_WR_CH_CONF_WORD_SIZE_24 | DC_WR_CH_CONF_DISP_ID_PARALLEL(0),
priv->channels[5].base + DC_WR_CH_CONF);
writel(DC_GEN_SYNC_1_6_SYNC | DC_GEN_SYNC_PRIORITY_1,
priv->dc_reg + DC_GEN);
ipu->dc_priv = priv;
dev_dbg(dev, "DC base: 0x%08lx template base: 0x%08lx\n",
base, template_base);
ipu_dc_map_clear(priv, IPU_DC_MAP_RGB24);
ipu_dc_map_config(priv, IPU_DC_MAP_RGB24, 0, 7, 0xff);
ipu_dc_map_config(priv, IPU_DC_MAP_RGB24, 1, 15, 0xff);
ipu_dc_map_config(priv, IPU_DC_MAP_RGB24, 2, 23, 0xff);
ipu_dc_map_clear(priv, IPU_DC_MAP_RGB565);
ipu_dc_map_config(priv, IPU_DC_MAP_RGB565, 0, 4, 0xf8);
ipu_dc_map_config(priv, IPU_DC_MAP_RGB565, 1, 10, 0xfc);
ipu_dc_map_config(priv, IPU_DC_MAP_RGB565, 2, 15, 0xf8);
ipu_dc_map_clear(priv, IPU_DC_MAP_GBR24);
ipu_dc_map_config(priv, IPU_DC_MAP_GBR24, 2, 15, 0xff);
ipu_dc_map_config(priv, IPU_DC_MAP_GBR24, 1, 7, 0xff);
ipu_dc_map_config(priv, IPU_DC_MAP_GBR24, 0, 23, 0xff);
ipu_dc_map_clear(priv, IPU_DC_MAP_BGR666);
ipu_dc_map_config(priv, IPU_DC_MAP_BGR666, 0, 5, 0xfc);
ipu_dc_map_config(priv, IPU_DC_MAP_BGR666, 1, 11, 0xfc);
ipu_dc_map_config(priv, IPU_DC_MAP_BGR666, 2, 17, 0xfc);
ipu_dc_map_clear(priv, IPU_DC_MAP_LVDS666);
ipu_dc_map_config(priv, IPU_DC_MAP_LVDS666, 0, 5, 0xfc);
ipu_dc_map_config(priv, IPU_DC_MAP_LVDS666, 1, 13, 0xfc);
ipu_dc_map_config(priv, IPU_DC_MAP_LVDS666, 2, 21, 0xfc);
ipu_dc_map_clear(priv, IPU_DC_MAP_BGR24);
ipu_dc_map_config(priv, IPU_DC_MAP_BGR24, 2, 7, 0xff);
ipu_dc_map_config(priv, IPU_DC_MAP_BGR24, 1, 15, 0xff);
ipu_dc_map_config(priv, IPU_DC_MAP_BGR24, 0, 23, 0xff);
return 0;
}
void ipu_dc_exit(struct ipu_soc *ipu)
{
}
