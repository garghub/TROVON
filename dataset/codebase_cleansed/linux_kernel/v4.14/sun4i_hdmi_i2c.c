static int fifo_transfer(struct sun4i_hdmi *hdmi, u8 *buf, int len, bool read)
{
const unsigned long byte_time_ns = 100;
const u32 mask = SUN4I_HDMI_DDC_INT_STATUS_ERROR_MASK |
SUN4I_HDMI_DDC_INT_STATUS_FIFO_REQUEST |
SUN4I_HDMI_DDC_INT_STATUS_TRANSFER_COMPLETE;
u32 reg;
len = min_t(int, len, read ? (RX_THRESHOLD + 1) :
(SUN4I_HDMI_DDC_FIFO_SIZE - TX_THRESHOLD + 1));
if (readl_poll_timeout(hdmi->base + SUN4I_HDMI_DDC_INT_STATUS_REG, reg,
reg & mask, len * byte_time_ns, 100000))
return -ETIMEDOUT;
if (reg & SUN4I_HDMI_DDC_INT_STATUS_ERROR_MASK)
return -EIO;
if (read)
readsb(hdmi->base + SUN4I_HDMI_DDC_FIFO_DATA_REG, buf, len);
else
writesb(hdmi->base + SUN4I_HDMI_DDC_FIFO_DATA_REG, buf, len);
writel(SUN4I_HDMI_DDC_INT_STATUS_FIFO_REQUEST,
hdmi->base + SUN4I_HDMI_DDC_INT_STATUS_REG);
return len;
}
static int xfer_msg(struct sun4i_hdmi *hdmi, struct i2c_msg *msg)
{
int i, len;
u32 reg;
reg = readl(hdmi->base + SUN4I_HDMI_DDC_CTRL_REG);
reg &= ~SUN4I_HDMI_DDC_CTRL_FIFO_DIR_MASK;
reg |= (msg->flags & I2C_M_RD) ?
SUN4I_HDMI_DDC_CTRL_FIFO_DIR_READ :
SUN4I_HDMI_DDC_CTRL_FIFO_DIR_WRITE;
writel(reg, hdmi->base + SUN4I_HDMI_DDC_CTRL_REG);
writel(SUN4I_HDMI_DDC_ADDR_SLAVE(msg->addr),
hdmi->base + SUN4I_HDMI_DDC_ADDR_REG);
reg = readl(hdmi->base + SUN4I_HDMI_DDC_FIFO_CTRL_REG);
reg |= SUN4I_HDMI_DDC_FIFO_CTRL_CLEAR;
reg &= ~SUN4I_HDMI_DDC_FIFO_CTRL_RX_THRES_MASK;
reg |= SUN4I_HDMI_DDC_FIFO_CTRL_RX_THRES(RX_THRESHOLD);
reg &= ~SUN4I_HDMI_DDC_FIFO_CTRL_TX_THRES_MASK;
reg |= SUN4I_HDMI_DDC_FIFO_CTRL_TX_THRES(TX_THRESHOLD);
writel(reg, hdmi->base + SUN4I_HDMI_DDC_FIFO_CTRL_REG);
if (readl_poll_timeout(hdmi->base + SUN4I_HDMI_DDC_FIFO_CTRL_REG,
reg,
!(reg & SUN4I_HDMI_DDC_FIFO_CTRL_CLEAR),
100, 2000))
return -EIO;
writel(msg->len, hdmi->base + SUN4I_HDMI_DDC_BYTE_COUNT_REG);
writel(msg->flags & I2C_M_RD ?
SUN4I_HDMI_DDC_CMD_IMPLICIT_READ :
SUN4I_HDMI_DDC_CMD_IMPLICIT_WRITE,
hdmi->base + SUN4I_HDMI_DDC_CMD_REG);
writel(SUN4I_HDMI_DDC_INT_STATUS_ERROR_MASK |
SUN4I_HDMI_DDC_INT_STATUS_FIFO_REQUEST |
SUN4I_HDMI_DDC_INT_STATUS_TRANSFER_COMPLETE,
hdmi->base + SUN4I_HDMI_DDC_INT_STATUS_REG);
reg = readl(hdmi->base + SUN4I_HDMI_DDC_CTRL_REG);
writel(reg | SUN4I_HDMI_DDC_CTRL_START_CMD,
hdmi->base + SUN4I_HDMI_DDC_CTRL_REG);
for (i = 0; i < msg->len; i += len) {
len = fifo_transfer(hdmi, msg->buf + i, msg->len - i,
msg->flags & I2C_M_RD);
if (len <= 0)
return len;
}
if (readl_poll_timeout(hdmi->base + SUN4I_HDMI_DDC_CTRL_REG,
reg,
!(reg & SUN4I_HDMI_DDC_CTRL_START_CMD),
100, 100000))
return -EIO;
reg = readl(hdmi->base + SUN4I_HDMI_DDC_INT_STATUS_REG);
if ((reg & SUN4I_HDMI_DDC_INT_STATUS_ERROR_MASK) ||
!(reg & SUN4I_HDMI_DDC_INT_STATUS_TRANSFER_COMPLETE)) {
return -EIO;
}
return 0;
}
static int sun4i_hdmi_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct sun4i_hdmi *hdmi = i2c_get_adapdata(adap);
u32 reg;
int err, i, ret = num;
for (i = 0; i < num; i++) {
if (!msgs[i].len)
return -EINVAL;
if (msgs[i].len > SUN4I_HDMI_DDC_BYTE_COUNT_MAX)
return -EINVAL;
}
writel(SUN4I_HDMI_DDC_CTRL_ENABLE | SUN4I_HDMI_DDC_CTRL_RESET,
hdmi->base + SUN4I_HDMI_DDC_CTRL_REG);
if (readl_poll_timeout(hdmi->base + SUN4I_HDMI_DDC_CTRL_REG, reg,
!(reg & SUN4I_HDMI_DDC_CTRL_RESET),
100, 2000))
return -EIO;
writel(SUN4I_HDMI_DDC_LINE_CTRL_SDA_ENABLE |
SUN4I_HDMI_DDC_LINE_CTRL_SCL_ENABLE,
hdmi->base + SUN4I_HDMI_DDC_LINE_CTRL_REG);
clk_prepare_enable(hdmi->ddc_clk);
clk_set_rate(hdmi->ddc_clk, 100000);
for (i = 0; i < num; i++) {
err = xfer_msg(hdmi, &msgs[i]);
if (err) {
ret = err;
break;
}
}
clk_disable_unprepare(hdmi->ddc_clk);
return ret;
}
static u32 sun4i_hdmi_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
int sun4i_hdmi_i2c_create(struct device *dev, struct sun4i_hdmi *hdmi)
{
struct i2c_adapter *adap;
int ret = 0;
ret = sun4i_ddc_create(hdmi, hdmi->tmds_clk);
if (ret)
return ret;
adap = devm_kzalloc(dev, sizeof(*adap), GFP_KERNEL);
if (!adap)
return -ENOMEM;
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DDC;
adap->algo = &sun4i_hdmi_i2c_algorithm;
strlcpy(adap->name, "sun4i_hdmi_i2c adapter", sizeof(adap->name));
i2c_set_adapdata(adap, hdmi);
ret = i2c_add_adapter(adap);
if (ret)
return ret;
hdmi->i2c = adap;
return ret;
}
