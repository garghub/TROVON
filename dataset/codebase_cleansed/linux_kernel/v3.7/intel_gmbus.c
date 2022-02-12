static inline struct intel_gmbus *
to_intel_gmbus(struct i2c_adapter *i2c)
{
return container_of(i2c, struct intel_gmbus, adapter);
}
void
gma_intel_i2c_reset(struct drm_device *dev)
{
REG_WRITE(GMBUS0, 0);
}
static void intel_i2c_quirk_set(struct drm_psb_private *dev_priv, bool enable)
{
}
static u32 get_reserved(struct intel_gpio *gpio)
{
struct drm_psb_private *dev_priv = gpio->dev_priv;
struct drm_device *dev = dev_priv->dev;
u32 reserved = 0;
reserved = REG_READ(gpio->reg) &
(GPIO_DATA_PULLUP_DISABLE |
GPIO_CLOCK_PULLUP_DISABLE);
return reserved;
}
static int get_clock(void *data)
{
struct intel_gpio *gpio = data;
struct drm_psb_private *dev_priv = gpio->dev_priv;
struct drm_device *dev = dev_priv->dev;
u32 reserved = get_reserved(gpio);
REG_WRITE(gpio->reg, reserved | GPIO_CLOCK_DIR_MASK);
REG_WRITE(gpio->reg, reserved);
return (REG_READ(gpio->reg) & GPIO_CLOCK_VAL_IN) != 0;
}
static int get_data(void *data)
{
struct intel_gpio *gpio = data;
struct drm_psb_private *dev_priv = gpio->dev_priv;
struct drm_device *dev = dev_priv->dev;
u32 reserved = get_reserved(gpio);
REG_WRITE(gpio->reg, reserved | GPIO_DATA_DIR_MASK);
REG_WRITE(gpio->reg, reserved);
return (REG_READ(gpio->reg) & GPIO_DATA_VAL_IN) != 0;
}
static void set_clock(void *data, int state_high)
{
struct intel_gpio *gpio = data;
struct drm_psb_private *dev_priv = gpio->dev_priv;
struct drm_device *dev = dev_priv->dev;
u32 reserved = get_reserved(gpio);
u32 clock_bits;
if (state_high)
clock_bits = GPIO_CLOCK_DIR_IN | GPIO_CLOCK_DIR_MASK;
else
clock_bits = GPIO_CLOCK_DIR_OUT | GPIO_CLOCK_DIR_MASK |
GPIO_CLOCK_VAL_MASK;
REG_WRITE(gpio->reg, reserved | clock_bits);
REG_READ(gpio->reg);
}
static void set_data(void *data, int state_high)
{
struct intel_gpio *gpio = data;
struct drm_psb_private *dev_priv = gpio->dev_priv;
struct drm_device *dev = dev_priv->dev;
u32 reserved = get_reserved(gpio);
u32 data_bits;
if (state_high)
data_bits = GPIO_DATA_DIR_IN | GPIO_DATA_DIR_MASK;
else
data_bits = GPIO_DATA_DIR_OUT | GPIO_DATA_DIR_MASK |
GPIO_DATA_VAL_MASK;
REG_WRITE(gpio->reg, reserved | data_bits);
REG_READ(gpio->reg);
}
static struct i2c_adapter *
intel_gpio_create(struct drm_psb_private *dev_priv, u32 pin)
{
static const int map_pin_to_reg[] = {
0,
GPIOB,
GPIOA,
GPIOC,
GPIOD,
GPIOE,
0,
GPIOF,
};
struct intel_gpio *gpio;
if (pin >= ARRAY_SIZE(map_pin_to_reg) || !map_pin_to_reg[pin])
return NULL;
gpio = kzalloc(sizeof(struct intel_gpio), GFP_KERNEL);
if (gpio == NULL)
return NULL;
gpio->reg = map_pin_to_reg[pin];
gpio->dev_priv = dev_priv;
snprintf(gpio->adapter.name, sizeof(gpio->adapter.name),
"gma500 GPIO%c", "?BACDE?F"[pin]);
gpio->adapter.owner = THIS_MODULE;
gpio->adapter.algo_data = &gpio->algo;
gpio->adapter.dev.parent = &dev_priv->dev->pdev->dev;
gpio->algo.setsda = set_data;
gpio->algo.setscl = set_clock;
gpio->algo.getsda = get_data;
gpio->algo.getscl = get_clock;
gpio->algo.udelay = I2C_RISEFALL_TIME;
gpio->algo.timeout = usecs_to_jiffies(2200);
gpio->algo.data = gpio;
if (i2c_bit_add_bus(&gpio->adapter))
goto out_free;
return &gpio->adapter;
out_free:
kfree(gpio);
return NULL;
}
static int
intel_i2c_quirk_xfer(struct drm_psb_private *dev_priv,
struct i2c_adapter *adapter,
struct i2c_msg *msgs,
int num)
{
struct intel_gpio *gpio = container_of(adapter,
struct intel_gpio,
adapter);
int ret;
gma_intel_i2c_reset(dev_priv->dev);
intel_i2c_quirk_set(dev_priv, true);
set_data(gpio, 1);
set_clock(gpio, 1);
udelay(I2C_RISEFALL_TIME);
ret = adapter->algo->master_xfer(adapter, msgs, num);
set_data(gpio, 1);
set_clock(gpio, 1);
intel_i2c_quirk_set(dev_priv, false);
return ret;
}
static int
gmbus_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs,
int num)
{
struct intel_gmbus *bus = container_of(adapter,
struct intel_gmbus,
adapter);
struct drm_psb_private *dev_priv = adapter->algo_data;
struct drm_device *dev = dev_priv->dev;
int i, reg_offset;
if (bus->force_bit)
return intel_i2c_quirk_xfer(dev_priv,
bus->force_bit, msgs, num);
reg_offset = 0;
REG_WRITE(GMBUS0 + reg_offset, bus->reg0);
for (i = 0; i < num; i++) {
u16 len = msgs[i].len;
u8 *buf = msgs[i].buf;
if (msgs[i].flags & I2C_M_RD) {
REG_WRITE(GMBUS1 + reg_offset,
GMBUS_CYCLE_WAIT | (i + 1 == num ? GMBUS_CYCLE_STOP : 0) |
(len << GMBUS_BYTE_COUNT_SHIFT) |
(msgs[i].addr << GMBUS_SLAVE_ADDR_SHIFT) |
GMBUS_SLAVE_READ | GMBUS_SW_RDY);
REG_READ(GMBUS2+reg_offset);
do {
u32 val, loop = 0;
if (wait_for(REG_READ(GMBUS2 + reg_offset) & (GMBUS_SATOER | GMBUS_HW_RDY), 50))
goto timeout;
if (REG_READ(GMBUS2 + reg_offset) & GMBUS_SATOER)
goto clear_err;
val = REG_READ(GMBUS3 + reg_offset);
do {
*buf++ = val & 0xff;
val >>= 8;
} while (--len && ++loop < 4);
} while (len);
} else {
u32 val, loop;
val = loop = 0;
do {
val |= *buf++ << (8 * loop);
} while (--len && ++loop < 4);
REG_WRITE(GMBUS3 + reg_offset, val);
REG_WRITE(GMBUS1 + reg_offset,
(i + 1 == num ? GMBUS_CYCLE_STOP : GMBUS_CYCLE_WAIT) |
(msgs[i].len << GMBUS_BYTE_COUNT_SHIFT) |
(msgs[i].addr << GMBUS_SLAVE_ADDR_SHIFT) |
GMBUS_SLAVE_WRITE | GMBUS_SW_RDY);
REG_READ(GMBUS2+reg_offset);
while (len) {
if (wait_for(REG_READ(GMBUS2 + reg_offset) & (GMBUS_SATOER | GMBUS_HW_RDY), 50))
goto timeout;
if (REG_READ(GMBUS2 + reg_offset) & GMBUS_SATOER)
goto clear_err;
val = loop = 0;
do {
val |= *buf++ << (8 * loop);
} while (--len && ++loop < 4);
REG_WRITE(GMBUS3 + reg_offset, val);
REG_READ(GMBUS2+reg_offset);
}
}
if (i + 1 < num && wait_for(REG_READ(GMBUS2 + reg_offset) & (GMBUS_SATOER | GMBUS_HW_WAIT_PHASE), 50))
goto timeout;
if (REG_READ(GMBUS2 + reg_offset) & GMBUS_SATOER)
goto clear_err;
}
goto done;
clear_err:
REG_WRITE(GMBUS1 + reg_offset, GMBUS_SW_CLR_INT);
REG_WRITE(GMBUS1 + reg_offset, 0);
done:
REG_WRITE(GMBUS0 + reg_offset, 0);
return i;
timeout:
DRM_INFO("GMBUS timed out, falling back to bit banging on pin %d [%s]\n",
bus->reg0 & 0xff, bus->adapter.name);
REG_WRITE(GMBUS0 + reg_offset, 0);
bus->force_bit = intel_gpio_create(dev_priv, bus->reg0 & 0xff);
if (!bus->force_bit)
return -ENOMEM;
return intel_i2c_quirk_xfer(dev_priv, bus->force_bit, msgs, num);
}
static u32 gmbus_func(struct i2c_adapter *adapter)
{
struct intel_gmbus *bus = container_of(adapter,
struct intel_gmbus,
adapter);
if (bus->force_bit)
bus->force_bit->algo->functionality(bus->force_bit);
return (I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA |
I2C_FUNC_SMBUS_BLOCK_PROC_CALL);
}
int gma_intel_setup_gmbus(struct drm_device *dev)
{
static const char *names[GMBUS_NUM_PORTS] = {
"disabled",
"ssc",
"vga",
"panel",
"dpc",
"dpb",
"reserved",
"dpd",
};
struct drm_psb_private *dev_priv = dev->dev_private;
int ret, i;
dev_priv->gmbus = kcalloc(GMBUS_NUM_PORTS, sizeof(struct intel_gmbus),
GFP_KERNEL);
if (dev_priv->gmbus == NULL)
return -ENOMEM;
for (i = 0; i < GMBUS_NUM_PORTS; i++) {
struct intel_gmbus *bus = &dev_priv->gmbus[i];
bus->adapter.owner = THIS_MODULE;
bus->adapter.class = I2C_CLASS_DDC;
snprintf(bus->adapter.name,
sizeof(bus->adapter.name),
"gma500 gmbus %s",
names[i]);
bus->adapter.dev.parent = &dev->pdev->dev;
bus->adapter.algo_data = dev_priv;
bus->adapter.algo = &gmbus_algorithm;
ret = i2c_add_adapter(&bus->adapter);
if (ret)
goto err;
bus->reg0 = i | GMBUS_RATE_100KHZ;
bus->force_bit = intel_gpio_create(dev_priv, i);
}
gma_intel_i2c_reset(dev_priv->dev);
return 0;
err:
while (--i) {
struct intel_gmbus *bus = &dev_priv->gmbus[i];
i2c_del_adapter(&bus->adapter);
}
kfree(dev_priv->gmbus);
dev_priv->gmbus = NULL;
return ret;
}
void gma_intel_gmbus_set_speed(struct i2c_adapter *adapter, int speed)
{
struct intel_gmbus *bus = to_intel_gmbus(adapter);
bus->reg0 = (bus->reg0 & ~(0x3 << 8)) | (speed << 8);
}
void gma_intel_gmbus_force_bit(struct i2c_adapter *adapter, bool force_bit)
{
struct intel_gmbus *bus = to_intel_gmbus(adapter);
if (force_bit) {
if (bus->force_bit == NULL) {
struct drm_psb_private *dev_priv = adapter->algo_data;
bus->force_bit = intel_gpio_create(dev_priv,
bus->reg0 & 0xff);
}
} else {
if (bus->force_bit) {
i2c_del_adapter(bus->force_bit);
kfree(bus->force_bit);
bus->force_bit = NULL;
}
}
}
void gma_intel_teardown_gmbus(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int i;
if (dev_priv->gmbus == NULL)
return;
for (i = 0; i < GMBUS_NUM_PORTS; i++) {
struct intel_gmbus *bus = &dev_priv->gmbus[i];
if (bus->force_bit) {
i2c_del_adapter(bus->force_bit);
kfree(bus->force_bit);
}
i2c_del_adapter(&bus->adapter);
}
kfree(dev_priv->gmbus);
dev_priv->gmbus = NULL;
}
