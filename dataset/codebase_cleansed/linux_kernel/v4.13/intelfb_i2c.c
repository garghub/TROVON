static void intelfb_gpio_setscl(void *data, int state)
{
struct intelfb_i2c_chan *chan = data;
struct intelfb_info *dinfo = chan->dinfo;
u32 val;
OUTREG(chan->reg, (state ? SCL_VAL_OUT : 0) |
SCL_DIR | SCL_DIR_MASK | SCL_VAL_MASK);
val = INREG(chan->reg);
}
static void intelfb_gpio_setsda(void *data, int state)
{
struct intelfb_i2c_chan *chan = data;
struct intelfb_info *dinfo = chan->dinfo;
u32 val;
OUTREG(chan->reg, (state ? SDA_VAL_OUT : 0) |
SDA_DIR | SDA_DIR_MASK | SDA_VAL_MASK);
val = INREG(chan->reg);
}
static int intelfb_gpio_getscl(void *data)
{
struct intelfb_i2c_chan *chan = data;
struct intelfb_info *dinfo = chan->dinfo;
u32 val;
OUTREG(chan->reg, SCL_DIR_MASK);
OUTREG(chan->reg, 0);
val = INREG(chan->reg);
return ((val & SCL_VAL_IN) != 0);
}
static int intelfb_gpio_getsda(void *data)
{
struct intelfb_i2c_chan *chan = data;
struct intelfb_info *dinfo = chan->dinfo;
u32 val;
OUTREG(chan->reg, SDA_DIR_MASK);
OUTREG(chan->reg, 0);
val = INREG(chan->reg);
return ((val & SDA_VAL_IN) != 0);
}
static int intelfb_setup_i2c_bus(struct intelfb_info *dinfo,
struct intelfb_i2c_chan *chan,
const u32 reg, const char *name,
int class)
{
int rc;
chan->dinfo = dinfo;
chan->reg = reg;
snprintf(chan->adapter.name, sizeof(chan->adapter.name),
"intelfb %s", name);
chan->adapter.class = class;
chan->adapter.owner = THIS_MODULE;
chan->adapter.algo_data = &chan->algo;
chan->adapter.dev.parent = &chan->dinfo->pdev->dev;
chan->algo.setsda = intelfb_gpio_setsda;
chan->algo.setscl = intelfb_gpio_setscl;
chan->algo.getsda = intelfb_gpio_getsda;
chan->algo.getscl = intelfb_gpio_getscl;
chan->algo.udelay = 40;
chan->algo.timeout = 20;
chan->algo.data = chan;
i2c_set_adapdata(&chan->adapter, chan);
intelfb_gpio_setsda(chan, 1);
intelfb_gpio_setscl(chan, 1);
udelay(20);
rc = i2c_bit_add_bus(&chan->adapter);
if (rc == 0)
DBG_MSG("I2C bus %s registered.\n", name);
else
WRN_MSG("Failed to register I2C bus %s.\n", name);
return rc;
}
void intelfb_create_i2c_busses(struct intelfb_info *dinfo)
{
int i = 0;
dinfo->num_outputs = 1;
dinfo->output[i].type = INTELFB_OUTPUT_ANALOG;
intelfb_setup_i2c_bus(dinfo, &dinfo->output[i].ddc_bus, GPIOA,
"CRTDDC_A", I2C_CLASS_DDC);
i++;
switch(dinfo->chipset) {
case INTEL_830M:
case INTEL_845G:
case INTEL_854:
case INTEL_855GM:
case INTEL_865G:
dinfo->output[i].type = INTELFB_OUTPUT_DVO;
intelfb_setup_i2c_bus(dinfo, &dinfo->output[i].ddc_bus,
GPIOD, "DVODDC_D", I2C_CLASS_DDC);
intelfb_setup_i2c_bus(dinfo, &dinfo->output[i].i2c_bus,
GPIOE, "DVOI2C_E", 0);
i++;
break;
case INTEL_915G:
case INTEL_915GM:
case INTEL_945G:
case INTEL_945GM:
case INTEL_945GME:
case INTEL_965G:
case INTEL_965GM:
dinfo->output[i].type = INTELFB_OUTPUT_SDVO;
intelfb_setup_i2c_bus(dinfo, &dinfo->output[i].i2c_bus,
GPIOE, "SDVOCTRL_E", 0);
i++;
dinfo->output[i].type = INTELFB_OUTPUT_SDVO;
dinfo->output[i].i2c_bus = dinfo->output[i - 1].i2c_bus;
i++;
break;
}
dinfo->num_outputs = i;
}
void intelfb_delete_i2c_busses(struct intelfb_info *dinfo)
{
int i;
for (i = 0; i < MAX_OUTPUTS; i++) {
if (dinfo->output[i].i2c_bus.dinfo) {
i2c_del_adapter(&dinfo->output[i].i2c_bus.adapter);
dinfo->output[i].i2c_bus.dinfo = NULL;
}
if (dinfo->output[i].ddc_bus.dinfo) {
i2c_del_adapter(&dinfo->output[i].ddc_bus.adapter);
dinfo->output[i].ddc_bus.dinfo = NULL;
}
}
}
