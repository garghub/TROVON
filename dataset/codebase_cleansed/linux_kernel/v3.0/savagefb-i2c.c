static void savage4_gpio_setscl(void *data, int val)
{
struct savagefb_i2c_chan *chan = data;
unsigned int r;
r = readl(chan->ioaddr + chan->reg);
if(val)
r |= SAVAGE4_I2C_SCL_OUT;
else
r &= ~SAVAGE4_I2C_SCL_OUT;
writel(r, chan->ioaddr + chan->reg);
readl(chan->ioaddr + chan->reg);
}
static void savage4_gpio_setsda(void *data, int val)
{
struct savagefb_i2c_chan *chan = data;
unsigned int r;
r = readl(chan->ioaddr + chan->reg);
if(val)
r |= SAVAGE4_I2C_SDA_OUT;
else
r &= ~SAVAGE4_I2C_SDA_OUT;
writel(r, chan->ioaddr + chan->reg);
readl(chan->ioaddr + chan->reg);
}
static int savage4_gpio_getscl(void *data)
{
struct savagefb_i2c_chan *chan = data;
return (0 != (readl(chan->ioaddr + chan->reg) & SAVAGE4_I2C_SCL_IN));
}
static int savage4_gpio_getsda(void *data)
{
struct savagefb_i2c_chan *chan = data;
return (0 != (readl(chan->ioaddr + chan->reg) & SAVAGE4_I2C_SDA_IN));
}
static void prosavage_gpio_setscl(void* data, int val)
{
struct savagefb_i2c_chan *chan = data;
u32 r;
r = VGArCR(chan->reg, chan->par);
r |= PROSAVAGE_I2C_ENAB;
if (val) {
r |= PROSAVAGE_I2C_SCL_OUT;
} else {
r &= ~PROSAVAGE_I2C_SCL_OUT;
}
VGAwCR(chan->reg, r, chan->par);
}
static void prosavage_gpio_setsda(void* data, int val)
{
struct savagefb_i2c_chan *chan = data;
unsigned int r;
r = VGArCR(chan->reg, chan->par);
r |= PROSAVAGE_I2C_ENAB;
if (val) {
r |= PROSAVAGE_I2C_SDA_OUT;
} else {
r &= ~PROSAVAGE_I2C_SDA_OUT;
}
VGAwCR(chan->reg, r, chan->par);
}
static int prosavage_gpio_getscl(void* data)
{
struct savagefb_i2c_chan *chan = data;
return (VGArCR(chan->reg, chan->par) & PROSAVAGE_I2C_SCL_IN) ? 1 : 0;
}
static int prosavage_gpio_getsda(void* data)
{
struct savagefb_i2c_chan *chan = data;
return (VGArCR(chan->reg, chan->par) & PROSAVAGE_I2C_SDA_IN) ? 1 : 0;
}
static int savage_setup_i2c_bus(struct savagefb_i2c_chan *chan,
const char *name)
{
int rc = 0;
if (chan->par) {
strcpy(chan->adapter.name, name);
chan->adapter.owner = THIS_MODULE;
chan->adapter.algo_data = &chan->algo;
chan->adapter.dev.parent = &chan->par->pcidev->dev;
chan->algo.udelay = 10;
chan->algo.timeout = 20;
chan->algo.data = chan;
i2c_set_adapdata(&chan->adapter, chan);
chan->algo.setsda(chan, 1);
chan->algo.setscl(chan, 1);
udelay(20);
rc = i2c_bit_add_bus(&chan->adapter);
if (rc == 0)
dev_dbg(&chan->par->pcidev->dev,
"I2C bus %s registered.\n", name);
else
dev_warn(&chan->par->pcidev->dev,
"Failed to register I2C bus %s.\n", name);
}
return rc;
}
void savagefb_create_i2c_busses(struct fb_info *info)
{
struct savagefb_par *par = info->par;
par->chan.par = par;
switch (par->chip) {
case S3_PROSAVAGE:
case S3_PROSAVAGEDDR:
case S3_TWISTER:
par->chan.reg = CR_SERIAL2;
par->chan.ioaddr = par->mmio.vbase;
par->chan.algo.setsda = prosavage_gpio_setsda;
par->chan.algo.setscl = prosavage_gpio_setscl;
par->chan.algo.getsda = prosavage_gpio_getsda;
par->chan.algo.getscl = prosavage_gpio_getscl;
break;
case S3_SAVAGE4:
par->chan.reg = CR_SERIAL1;
if (par->pcidev->revision > 1 && !(VGArCR(0xa6, par) & 0x40))
par->chan.reg = CR_SERIAL2;
par->chan.ioaddr = par->mmio.vbase;
par->chan.algo.setsda = prosavage_gpio_setsda;
par->chan.algo.setscl = prosavage_gpio_setscl;
par->chan.algo.getsda = prosavage_gpio_getsda;
par->chan.algo.getscl = prosavage_gpio_getscl;
break;
case S3_SAVAGE2000:
par->chan.reg = MM_SERIAL1;
par->chan.ioaddr = par->mmio.vbase;
par->chan.algo.setsda = savage4_gpio_setsda;
par->chan.algo.setscl = savage4_gpio_setscl;
par->chan.algo.getsda = savage4_gpio_getsda;
par->chan.algo.getscl = savage4_gpio_getscl;
break;
default:
par->chan.par = NULL;
}
savage_setup_i2c_bus(&par->chan, "SAVAGE DDC2");
}
void savagefb_delete_i2c_busses(struct fb_info *info)
{
struct savagefb_par *par = info->par;
if (par->chan.par)
i2c_del_adapter(&par->chan.adapter);
par->chan.par = NULL;
}
int savagefb_probe_i2c_connector(struct fb_info *info, u8 **out_edid)
{
struct savagefb_par *par = info->par;
u8 *edid;
if (par->chan.par)
edid = fb_ddc_read(&par->chan.adapter);
else
edid = NULL;
if (!edid) {
const u8 *e = fb_firmware_edid(info->device);
if (e)
edid = kmemdup(e, EDID_LENGTH, GFP_KERNEL);
}
*out_edid = edid;
return (edid) ? 0 : 1;
}
