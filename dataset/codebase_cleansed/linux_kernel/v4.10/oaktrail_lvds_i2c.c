static int get_clock(void *data)
{
struct psb_intel_i2c_chan *chan = data;
u32 val, tmp;
val = LPC_READ_REG(chan, RGIO);
val |= GPIO_CLOCK;
LPC_WRITE_REG(chan, RGIO, val);
tmp = LPC_READ_REG(chan, RGLVL);
val = (LPC_READ_REG(chan, RGLVL) & GPIO_CLOCK) ? 1 : 0;
return val;
}
static int get_data(void *data)
{
struct psb_intel_i2c_chan *chan = data;
u32 val, tmp;
val = LPC_READ_REG(chan, RGIO);
val |= GPIO_DATA;
LPC_WRITE_REG(chan, RGIO, val);
tmp = LPC_READ_REG(chan, RGLVL);
val = (LPC_READ_REG(chan, RGLVL) & GPIO_DATA) ? 1 : 0;
return val;
}
static void set_clock(void *data, int state_high)
{
struct psb_intel_i2c_chan *chan = data;
u32 val;
if (state_high) {
val = LPC_READ_REG(chan, RGIO);
val |= GPIO_CLOCK;
LPC_WRITE_REG(chan, RGIO, val);
} else {
val = LPC_READ_REG(chan, RGIO);
val &= ~GPIO_CLOCK;
LPC_WRITE_REG(chan, RGIO, val);
val = LPC_READ_REG(chan, RGLVL);
val &= ~GPIO_CLOCK;
LPC_WRITE_REG(chan, RGLVL, val);
}
}
static void set_data(void *data, int state_high)
{
struct psb_intel_i2c_chan *chan = data;
u32 val;
if (state_high) {
val = LPC_READ_REG(chan, RGIO);
val |= GPIO_DATA;
LPC_WRITE_REG(chan, RGIO, val);
} else {
val = LPC_READ_REG(chan, RGIO);
val &= ~GPIO_DATA;
LPC_WRITE_REG(chan, RGIO, val);
val = LPC_READ_REG(chan, RGLVL);
val &= ~GPIO_DATA;
LPC_WRITE_REG(chan, RGLVL, val);
}
}
void oaktrail_lvds_i2c_init(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct gma_encoder *gma_encoder = to_gma_encoder(encoder);
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_i2c_chan *chan;
chan = kzalloc(sizeof(struct psb_intel_i2c_chan), GFP_KERNEL);
if (!chan)
return;
chan->drm_dev = dev;
chan->reg = dev_priv->lpc_gpio_base;
strncpy(chan->adapter.name, "gma500 LPC", I2C_NAME_SIZE - 1);
chan->adapter.owner = THIS_MODULE;
chan->adapter.algo_data = &chan->algo;
chan->adapter.dev.parent = &dev->pdev->dev;
chan->algo.setsda = set_data;
chan->algo.setscl = set_clock;
chan->algo.getsda = get_data;
chan->algo.getscl = get_clock;
chan->algo.udelay = 100;
chan->algo.timeout = usecs_to_jiffies(2200);
chan->algo.data = chan;
i2c_set_adapdata(&chan->adapter, chan);
set_data(chan, 1);
set_clock(chan, 1);
udelay(50);
if (i2c_bit_add_bus(&chan->adapter)) {
kfree(chan);
return;
}
gma_encoder->ddc_bus = chan;
}
