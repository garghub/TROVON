static int mxl111sf_set_gpo_state(struct mxl111sf_state *state, u8 pin, u8 val)
{
int ret;
u8 tmp;
mxl_debug_adv("(%d, %d)", pin, val);
if ((pin > 0) && (pin < 8)) {
ret = mxl111sf_read_reg(state, 0x19, &tmp);
if (mxl_fail(ret))
goto fail;
tmp &= ~(1 << (pin - 1));
tmp |= (val << (pin - 1));
ret = mxl111sf_write_reg(state, 0x19, tmp);
if (mxl_fail(ret))
goto fail;
} else if (pin <= 10) {
if (pin == 0)
pin += 7;
ret = mxl111sf_read_reg(state, 0x30, &tmp);
if (mxl_fail(ret))
goto fail;
tmp &= ~(1 << (pin - 3));
tmp |= (val << (pin - 3));
ret = mxl111sf_write_reg(state, 0x30, tmp);
if (mxl_fail(ret))
goto fail;
} else
ret = -EINVAL;
fail:
return ret;
}
static int mxl111sf_get_gpi_state(struct mxl111sf_state *state, u8 pin, u8 *val)
{
int ret;
u8 tmp;
mxl_debug("(0x%02x)", pin);
*val = 0;
switch (pin) {
case 0:
case 1:
case 2:
case 3:
ret = mxl111sf_read_reg(state, 0x23, &tmp);
if (mxl_fail(ret))
goto fail;
*val = (tmp >> (pin + 4)) & 0x01;
break;
case 4:
case 5:
case 6:
case 7:
ret = mxl111sf_read_reg(state, 0x2f, &tmp);
if (mxl_fail(ret))
goto fail;
*val = (tmp >> pin) & 0x01;
break;
case 8:
case 9:
case 10:
ret = mxl111sf_read_reg(state, 0x22, &tmp);
if (mxl_fail(ret))
goto fail;
*val = (tmp >> (pin - 3)) & 0x01;
break;
default:
return -EINVAL;
}
fail:
return ret;
}
static int mxl111sf_config_gpio_pins(struct mxl111sf_state *state,
struct mxl_gpio_cfg *gpio_cfg)
{
int ret;
u8 tmp;
mxl_debug_adv("(%d, %d)", gpio_cfg->pin, gpio_cfg->dir);
switch (gpio_cfg->pin) {
case 0:
case 1:
case 2:
case 3:
ret = mxl111sf_read_reg(state, MXL_GPIO_MUX_REG_0, &tmp);
if (mxl_fail(ret))
goto fail;
tmp &= ~(1 << (gpio_cfg->pin + 4));
tmp |= (gpio_cfg->dir << (gpio_cfg->pin + 4));
ret = mxl111sf_write_reg(state, MXL_GPIO_MUX_REG_0, tmp);
if (mxl_fail(ret))
goto fail;
break;
case 4:
case 5:
case 6:
case 7:
ret = mxl111sf_read_reg(state, MXL_GPIO_MUX_REG_1, &tmp);
if (mxl_fail(ret))
goto fail;
tmp &= ~(1 << gpio_cfg->pin);
tmp |= (gpio_cfg->dir << gpio_cfg->pin);
ret = mxl111sf_write_reg(state, MXL_GPIO_MUX_REG_1, tmp);
if (mxl_fail(ret))
goto fail;
break;
case 8:
case 9:
case 10:
ret = mxl111sf_read_reg(state, MXL_GPIO_MUX_REG_2, &tmp);
if (mxl_fail(ret))
goto fail;
tmp &= ~(1 << (gpio_cfg->pin - 3));
tmp |= (gpio_cfg->dir << (gpio_cfg->pin - 3));
ret = mxl111sf_write_reg(state, MXL_GPIO_MUX_REG_2, tmp);
if (mxl_fail(ret))
goto fail;
break;
default:
return -EINVAL;
}
ret = (MXL_GPIO_DIR_OUTPUT == gpio_cfg->dir) ?
mxl111sf_set_gpo_state(state,
gpio_cfg->pin, gpio_cfg->val) :
mxl111sf_get_gpi_state(state,
gpio_cfg->pin, &gpio_cfg->val);
mxl_fail(ret);
fail:
return ret;
}
static int mxl111sf_hw_do_set_gpio(struct mxl111sf_state *state,
int gpio, int direction, int val)
{
struct mxl_gpio_cfg gpio_config = {
.pin = gpio,
.dir = direction,
.val = val,
};
mxl_debug("(%d, %d, %d)", gpio, direction, val);
return mxl111sf_config_gpio_pins(state, &gpio_config);
}
int mxl111sf_config_pin_mux_modes(struct mxl111sf_state *state,
enum mxl111sf_mux_config pin_mux_config)
{
u8 r12, r15, r17, r18, r3D, r82, r84, r89;
int ret;
mxl_debug("(%d)", pin_mux_config);
ret = mxl111sf_read_reg(state, 0x17, &r17);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x18, &r18);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x12, &r12);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x15, &r15);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x82, &r82);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x84, &r84);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x89, &r89);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_read_reg(state, 0x3D, &r3D);
if (mxl_fail(ret))
goto fail;
switch (pin_mux_config) {
case PIN_MUX_TS_OUT_PARALLEL:
r17 |= PIN_MUX_MPEG_MODE_MASK;
r18 |= PIN_MUX_MPEG_PAR_EN_MASK;
r18 &= ~PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 |= PIN_MUX_MCLK_EN_CTRL_MASK;
r82 |= PIN_MUX_MPERR_EN_CTRL_MASK;
r82 |= PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 |= PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 |= 0xF0;
r89 |= 0xF0;
break;
case PIN_MUX_TS_OUT_SERIAL:
r17 |= PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 |= PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 |= PIN_MUX_MCLK_EN_CTRL_MASK;
r82 |= PIN_MUX_MPERR_EN_CTRL_MASK;
r82 |= PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 |= PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 |= 0xF0;
r89 |= 0xF0;
break;
case PIN_MUX_GPIO_MODE:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 &= ~PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_TS_SERIAL_IN_MODE_0:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 |= PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_TS_SERIAL_IN_MODE_1:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 |= PIN_MUX_MPEG_SER_EN_MASK;
r3D |= PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_TS_SPI_IN_MODE_1:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 |= PIN_MUX_MPEG_SER_EN_MASK;
r3D |= PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 |= PIN_MUX_I2S_ENABLE_MASK;
r3D |= PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_TS_SPI_IN_MODE_0:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 |= PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 |= PIN_MUX_I2S_ENABLE_MASK;
r3D |= PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_TS_PARALLEL_IN:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 |= PIN_MUX_MPEG_PAR_EN_MASK;
r18 &= ~PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_BT656_I2S_MODE:
r17 &= ~PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 &= ~PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 |= PIN_MUX_BT656_ENABLE_MASK;
r15 |= PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
case PIN_MUX_DEFAULT:
default:
r17 |= PIN_MUX_MPEG_MODE_MASK;
r18 &= ~PIN_MUX_MPEG_PAR_EN_MASK;
r18 &= ~PIN_MUX_MPEG_SER_EN_MASK;
r3D &= ~PIN_MUX_MPG_IN_MUX_MASK;
r12 &= ~PIN_MUX_BT656_ENABLE_MASK;
r15 &= ~PIN_MUX_I2S_ENABLE_MASK;
r3D &= ~PIN_MUX_SPI_MODE_MASK;
r82 &= ~PIN_MUX_MCLK_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPERR_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MDVAL_EN_CTRL_MASK;
r82 &= ~PIN_MUX_MPSYN_EN_CTRL_MASK;
r84 &= 0x0F;
r89 &= 0x0F;
break;
}
ret = mxl111sf_write_reg(state, 0x17, r17);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x18, r18);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x12, r12);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x15, r15);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x82, r82);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x84, r84);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x89, r89);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_write_reg(state, 0x3D, r3D);
if (mxl_fail(ret))
goto fail;
fail:
return ret;
}
static int mxl111sf_hw_set_gpio(struct mxl111sf_state *state, int gpio, int val)
{
return mxl111sf_hw_do_set_gpio(state, gpio, MXL_GPIO_DIR_OUTPUT, val);
}
static int mxl111sf_hw_gpio_initialize(struct mxl111sf_state *state)
{
u8 gpioval = 0x07;
int i, ret;
mxl_debug("()");
for (i = 3; i < 8; i++) {
ret = mxl111sf_hw_set_gpio(state, i, (gpioval >> i) & 0x01);
if (mxl_fail(ret))
break;
}
return ret;
}
static int pca9534_set_gpio(struct mxl111sf_state *state, int gpio, int val)
{
u8 w[2] = { 1, 0 };
u8 r = 0;
struct i2c_msg msg[] = {
{ .addr = PCA9534_I2C_ADDR,
.flags = 0, .buf = w, .len = 1 },
{ .addr = PCA9534_I2C_ADDR,
.flags = I2C_M_RD, .buf = &r, .len = 1 },
};
mxl_debug("(%d, %d)", gpio, val);
i2c_transfer(&state->d->i2c_adap, msg, 2);
msg[0].len = 2;
#if 0
w[0] = 1;
#endif
w[1] = r;
w[1] &= ~(1 << gpio);
w[1] |= ((val ? 1 : 0) << gpio);
i2c_transfer(&state->d->i2c_adap, &msg[0], 1);
return 0;
}
static int pca9534_init_port_expander(struct mxl111sf_state *state)
{
u8 w[2] = { 1, 0x07 };
struct i2c_msg msg = {
.addr = PCA9534_I2C_ADDR,
.flags = 0, .buf = w, .len = 2
};
mxl_debug("()");
i2c_transfer(&state->d->i2c_adap, &msg, 1);
w[0] = 3;
w[1] = 0;
i2c_transfer(&state->d->i2c_adap, &msg, 1);
return 0;
}
int mxl111sf_set_gpio(struct mxl111sf_state *state, int gpio, int val)
{
mxl_debug("(%d, %d)", gpio, val);
switch (state->gpio_port_expander) {
default:
mxl_printk(KERN_ERR,
"gpio_port_expander undefined, assuming PCA9534");
case mxl111sf_PCA9534:
return pca9534_set_gpio(state, gpio, val);
case mxl111sf_gpio_hw:
return mxl111sf_hw_set_gpio(state, gpio, val);
}
}
static int mxl111sf_probe_port_expander(struct mxl111sf_state *state)
{
int ret;
u8 w = 1;
u8 r = 0;
struct i2c_msg msg[] = {
{ .flags = 0, .buf = &w, .len = 1 },
{ .flags = I2C_M_RD, .buf = &r, .len = 1 },
};
mxl_debug("()");
msg[0].addr = 0x70 >> 1;
msg[1].addr = 0x70 >> 1;
ret = i2c_transfer(&state->d->i2c_adap, msg, 2);
if (ret == 2) {
state->port_expander_addr = msg[0].addr;
state->gpio_port_expander = mxl111sf_PCA9534;
mxl_debug("found port expander at 0x%02x",
state->port_expander_addr);
return 0;
}
msg[0].addr = 0x40 >> 1;
msg[1].addr = 0x40 >> 1;
ret = i2c_transfer(&state->d->i2c_adap, msg, 2);
if (ret == 2) {
state->port_expander_addr = msg[0].addr;
state->gpio_port_expander = mxl111sf_PCA9534;
mxl_debug("found port expander at 0x%02x",
state->port_expander_addr);
return 0;
}
state->port_expander_addr = 0xff;
state->gpio_port_expander = mxl111sf_gpio_hw;
mxl_debug("using hardware gpio");
return 0;
}
int mxl111sf_init_port_expander(struct mxl111sf_state *state)
{
mxl_debug("()");
if (0x00 == state->port_expander_addr)
mxl111sf_probe_port_expander(state);
switch (state->gpio_port_expander) {
default:
mxl_printk(KERN_ERR,
"gpio_port_expander undefined, assuming PCA9534");
case mxl111sf_PCA9534:
return pca9534_init_port_expander(state);
case mxl111sf_gpio_hw:
return mxl111sf_hw_gpio_initialize(state);
}
}
int mxl111sf_gpio_mode_switch(struct mxl111sf_state *state, unsigned int mode)
{
mxl_debug("(%d)", mode);
switch (mode) {
case MXL111SF_GPIO_MOD_MH:
mxl111sf_set_gpio(state, 4, 0);
mxl111sf_set_gpio(state, 5, 0);
msleep(50);
mxl111sf_set_gpio(state, 7, 1);
msleep(50);
mxl111sf_set_gpio(state, 6, 1);
msleep(50);
mxl111sf_set_gpio(state, 3, 0);
break;
case MXL111SF_GPIO_MOD_ATSC:
mxl111sf_set_gpio(state, 6, 0);
mxl111sf_set_gpio(state, 7, 0);
msleep(50);
mxl111sf_set_gpio(state, 5, 1);
msleep(50);
mxl111sf_set_gpio(state, 4, 1);
msleep(50);
mxl111sf_set_gpio(state, 3, 1);
break;
default:
mxl111sf_init_port_expander(state);
break;
}
return 0;
}
