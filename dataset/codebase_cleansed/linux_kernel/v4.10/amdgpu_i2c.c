static int amdgpu_i2c_pre_xfer(struct i2c_adapter *i2c_adap)
{
struct amdgpu_i2c_chan *i2c = i2c_get_adapdata(i2c_adap);
struct amdgpu_device *adev = i2c->dev->dev_private;
struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
uint32_t temp;
mutex_lock(&i2c->mutex);
if (rec->hw_capable) {
temp = RREG32(rec->mask_clk_reg);
temp &= ~(1 << 16);
WREG32(rec->mask_clk_reg, temp);
}
temp = RREG32(rec->a_clk_reg) & ~rec->a_clk_mask;
WREG32(rec->a_clk_reg, temp);
temp = RREG32(rec->a_data_reg) & ~rec->a_data_mask;
WREG32(rec->a_data_reg, temp);
temp = RREG32(rec->en_clk_reg) & ~rec->en_clk_mask;
WREG32(rec->en_clk_reg, temp);
temp = RREG32(rec->en_data_reg) & ~rec->en_data_mask;
WREG32(rec->en_data_reg, temp);
temp = RREG32(rec->mask_clk_reg) | rec->mask_clk_mask;
WREG32(rec->mask_clk_reg, temp);
temp = RREG32(rec->mask_clk_reg);
temp = RREG32(rec->mask_data_reg) | rec->mask_data_mask;
WREG32(rec->mask_data_reg, temp);
temp = RREG32(rec->mask_data_reg);
return 0;
}
static void amdgpu_i2c_post_xfer(struct i2c_adapter *i2c_adap)
{
struct amdgpu_i2c_chan *i2c = i2c_get_adapdata(i2c_adap);
struct amdgpu_device *adev = i2c->dev->dev_private;
struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
uint32_t temp;
temp = RREG32(rec->mask_clk_reg) & ~rec->mask_clk_mask;
WREG32(rec->mask_clk_reg, temp);
temp = RREG32(rec->mask_clk_reg);
temp = RREG32(rec->mask_data_reg) & ~rec->mask_data_mask;
WREG32(rec->mask_data_reg, temp);
temp = RREG32(rec->mask_data_reg);
mutex_unlock(&i2c->mutex);
}
static int amdgpu_i2c_get_clock(void *i2c_priv)
{
struct amdgpu_i2c_chan *i2c = i2c_priv;
struct amdgpu_device *adev = i2c->dev->dev_private;
struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
uint32_t val;
val = RREG32(rec->y_clk_reg);
val &= rec->y_clk_mask;
return (val != 0);
}
static int amdgpu_i2c_get_data(void *i2c_priv)
{
struct amdgpu_i2c_chan *i2c = i2c_priv;
struct amdgpu_device *adev = i2c->dev->dev_private;
struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
uint32_t val;
val = RREG32(rec->y_data_reg);
val &= rec->y_data_mask;
return (val != 0);
}
static void amdgpu_i2c_set_clock(void *i2c_priv, int clock)
{
struct amdgpu_i2c_chan *i2c = i2c_priv;
struct amdgpu_device *adev = i2c->dev->dev_private;
struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
uint32_t val;
val = RREG32(rec->en_clk_reg) & ~rec->en_clk_mask;
val |= clock ? 0 : rec->en_clk_mask;
WREG32(rec->en_clk_reg, val);
}
static void amdgpu_i2c_set_data(void *i2c_priv, int data)
{
struct amdgpu_i2c_chan *i2c = i2c_priv;
struct amdgpu_device *adev = i2c->dev->dev_private;
struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
uint32_t val;
val = RREG32(rec->en_data_reg) & ~rec->en_data_mask;
val |= data ? 0 : rec->en_data_mask;
WREG32(rec->en_data_reg, val);
}
struct amdgpu_i2c_chan *amdgpu_i2c_create(struct drm_device *dev,
const struct amdgpu_i2c_bus_rec *rec,
const char *name)
{
struct amdgpu_i2c_chan *i2c;
int ret;
if (rec->mm_i2c && (amdgpu_hw_i2c == 0))
return NULL;
i2c = kzalloc(sizeof(struct amdgpu_i2c_chan), GFP_KERNEL);
if (i2c == NULL)
return NULL;
i2c->rec = *rec;
i2c->adapter.owner = THIS_MODULE;
i2c->adapter.class = I2C_CLASS_DDC;
i2c->adapter.dev.parent = &dev->pdev->dev;
i2c->dev = dev;
i2c_set_adapdata(&i2c->adapter, i2c);
mutex_init(&i2c->mutex);
if (rec->hw_capable &&
amdgpu_hw_i2c) {
snprintf(i2c->adapter.name, sizeof(i2c->adapter.name),
"AMDGPU i2c hw bus %s", name);
i2c->adapter.algo = &amdgpu_atombios_i2c_algo;
ret = i2c_add_adapter(&i2c->adapter);
if (ret)
goto out_free;
} else {
snprintf(i2c->adapter.name, sizeof(i2c->adapter.name),
"AMDGPU i2c bit bus %s", name);
i2c->adapter.algo_data = &i2c->bit;
i2c->bit.pre_xfer = amdgpu_i2c_pre_xfer;
i2c->bit.post_xfer = amdgpu_i2c_post_xfer;
i2c->bit.setsda = amdgpu_i2c_set_data;
i2c->bit.setscl = amdgpu_i2c_set_clock;
i2c->bit.getsda = amdgpu_i2c_get_data;
i2c->bit.getscl = amdgpu_i2c_get_clock;
i2c->bit.udelay = 10;
i2c->bit.timeout = usecs_to_jiffies(2200);
i2c->bit.data = i2c;
ret = i2c_bit_add_bus(&i2c->adapter);
if (ret) {
DRM_ERROR("Failed to register bit i2c %s\n", name);
goto out_free;
}
}
return i2c;
out_free:
kfree(i2c);
return NULL;
}
void amdgpu_i2c_destroy(struct amdgpu_i2c_chan *i2c)
{
if (!i2c)
return;
WARN_ON(i2c->has_aux);
i2c_del_adapter(&i2c->adapter);
kfree(i2c);
}
void amdgpu_i2c_init(struct amdgpu_device *adev)
{
if (amdgpu_hw_i2c)
DRM_INFO("hw_i2c forced on, you may experience display detection problems!\n");
if (adev->is_atom_bios)
amdgpu_atombios_i2c_init(adev);
}
void amdgpu_i2c_fini(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < AMDGPU_MAX_I2C_BUS; i++) {
if (adev->i2c_bus[i]) {
amdgpu_i2c_destroy(adev->i2c_bus[i]);
adev->i2c_bus[i] = NULL;
}
}
}
void amdgpu_i2c_add(struct amdgpu_device *adev,
const struct amdgpu_i2c_bus_rec *rec,
const char *name)
{
struct drm_device *dev = adev->ddev;
int i;
for (i = 0; i < AMDGPU_MAX_I2C_BUS; i++) {
if (!adev->i2c_bus[i]) {
adev->i2c_bus[i] = amdgpu_i2c_create(dev, rec, name);
return;
}
}
}
struct amdgpu_i2c_chan *
amdgpu_i2c_lookup(struct amdgpu_device *adev,
const struct amdgpu_i2c_bus_rec *i2c_bus)
{
int i;
for (i = 0; i < AMDGPU_MAX_I2C_BUS; i++) {
if (adev->i2c_bus[i] &&
(adev->i2c_bus[i]->rec.i2c_id == i2c_bus->i2c_id)) {
return adev->i2c_bus[i];
}
}
return NULL;
}
static void amdgpu_i2c_get_byte(struct amdgpu_i2c_chan *i2c_bus,
u8 slave_addr,
u8 addr,
u8 *val)
{
u8 out_buf[2];
u8 in_buf[2];
struct i2c_msg msgs[] = {
{
.addr = slave_addr,
.flags = 0,
.len = 1,
.buf = out_buf,
},
{
.addr = slave_addr,
.flags = I2C_M_RD,
.len = 1,
.buf = in_buf,
}
};
out_buf[0] = addr;
out_buf[1] = 0;
if (i2c_transfer(&i2c_bus->adapter, msgs, 2) == 2) {
*val = in_buf[0];
DRM_DEBUG("val = 0x%02x\n", *val);
} else {
DRM_DEBUG("i2c 0x%02x 0x%02x read failed\n",
addr, *val);
}
}
static void amdgpu_i2c_put_byte(struct amdgpu_i2c_chan *i2c_bus,
u8 slave_addr,
u8 addr,
u8 val)
{
uint8_t out_buf[2];
struct i2c_msg msg = {
.addr = slave_addr,
.flags = 0,
.len = 2,
.buf = out_buf,
};
out_buf[0] = addr;
out_buf[1] = val;
if (i2c_transfer(&i2c_bus->adapter, &msg, 1) != 1)
DRM_DEBUG("i2c 0x%02x 0x%02x write failed\n",
addr, val);
}
void
amdgpu_i2c_router_select_ddc_port(const struct amdgpu_connector *amdgpu_connector)
{
u8 val;
if (!amdgpu_connector->router.ddc_valid)
return;
if (!amdgpu_connector->router_bus)
return;
amdgpu_i2c_get_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x3, &val);
val &= ~amdgpu_connector->router.ddc_mux_control_pin;
amdgpu_i2c_put_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x3, val);
amdgpu_i2c_get_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x1, &val);
val &= ~amdgpu_connector->router.ddc_mux_control_pin;
val |= amdgpu_connector->router.ddc_mux_state;
amdgpu_i2c_put_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x1, val);
}
void
amdgpu_i2c_router_select_cd_port(const struct amdgpu_connector *amdgpu_connector)
{
u8 val;
if (!amdgpu_connector->router.cd_valid)
return;
if (!amdgpu_connector->router_bus)
return;
amdgpu_i2c_get_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x3, &val);
val &= ~amdgpu_connector->router.cd_mux_control_pin;
amdgpu_i2c_put_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x3, val);
amdgpu_i2c_get_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x1, &val);
val &= ~amdgpu_connector->router.cd_mux_control_pin;
val |= amdgpu_connector->router.cd_mux_state;
amdgpu_i2c_put_byte(amdgpu_connector->router_bus,
amdgpu_connector->router.i2c_addr,
0x1, val);
}
