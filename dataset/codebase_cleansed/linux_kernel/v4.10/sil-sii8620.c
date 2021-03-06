static int sii8620_clear_error(struct sii8620 *ctx)
{
int ret = ctx->error;
ctx->error = 0;
return ret;
}
static void sii8620_read_buf(struct sii8620 *ctx, u16 addr, u8 *buf, int len)
{
struct device *dev = ctx->dev;
struct i2c_client *client = to_i2c_client(dev);
u8 data = addr;
struct i2c_msg msg[] = {
{
.addr = sii8620_i2c_page[addr >> 8],
.flags = client->flags,
.len = 1,
.buf = &data
},
{
.addr = sii8620_i2c_page[addr >> 8],
.flags = client->flags | I2C_M_RD,
.len = len,
.buf = buf
},
};
int ret;
if (ctx->error)
return;
ret = i2c_transfer(client->adapter, msg, 2);
dev_dbg(dev, "read at %04x: %*ph, %d\n", addr, len, buf, ret);
if (ret != 2) {
dev_err(dev, "Read at %#06x of %d bytes failed with code %d.\n",
addr, len, ret);
ctx->error = ret < 0 ? ret : -EIO;
}
}
static u8 sii8620_readb(struct sii8620 *ctx, u16 addr)
{
u8 ret;
sii8620_read_buf(ctx, addr, &ret, 1);
return ret;
}
static void sii8620_write_buf(struct sii8620 *ctx, u16 addr, const u8 *buf,
int len)
{
struct device *dev = ctx->dev;
struct i2c_client *client = to_i2c_client(dev);
u8 data[2];
struct i2c_msg msg = {
.addr = sii8620_i2c_page[addr >> 8],
.flags = client->flags,
.len = len + 1,
};
int ret;
if (ctx->error)
return;
if (len > 1) {
msg.buf = kmalloc(len + 1, GFP_KERNEL);
if (!msg.buf) {
ctx->error = -ENOMEM;
return;
}
memcpy(msg.buf + 1, buf, len);
} else {
msg.buf = data;
msg.buf[1] = *buf;
}
msg.buf[0] = addr;
ret = i2c_transfer(client->adapter, &msg, 1);
dev_dbg(dev, "write at %04x: %*ph, %d\n", addr, len, buf, ret);
if (ret != 1) {
dev_err(dev, "Write at %#06x of %*ph failed with code %d.\n",
addr, len, buf, ret);
ctx->error = ret ?: -EIO;
}
if (len > 1)
kfree(msg.buf);
}
static void __sii8620_write_seq(struct sii8620 *ctx, const u16 *seq, int len)
{
int i;
for (i = 0; i < len; i += 2)
sii8620_write(ctx, seq[i], seq[i + 1]);
}
static void sii8620_setbits(struct sii8620 *ctx, u16 addr, u8 mask, u8 val)
{
val = (val & mask) | (sii8620_readb(ctx, addr) & ~mask);
sii8620_write(ctx, addr, val);
}
static void sii8620_mt_cleanup(struct sii8620 *ctx)
{
struct sii8620_mt_msg *msg, *n;
list_for_each_entry_safe(msg, n, &ctx->mt_queue, node) {
list_del(&msg->node);
kfree(msg);
}
ctx->mt_state = MT_STATE_READY;
}
static void sii8620_mt_work(struct sii8620 *ctx)
{
struct sii8620_mt_msg *msg;
if (ctx->error)
return;
if (ctx->mt_state == MT_STATE_BUSY || list_empty(&ctx->mt_queue))
return;
if (ctx->mt_state == MT_STATE_DONE) {
ctx->mt_state = MT_STATE_READY;
msg = list_first_entry(&ctx->mt_queue, struct sii8620_mt_msg,
node);
if (msg->recv)
msg->recv(ctx, msg);
list_del(&msg->node);
kfree(msg);
}
if (ctx->mt_state != MT_STATE_READY || list_empty(&ctx->mt_queue))
return;
ctx->mt_state = MT_STATE_BUSY;
msg = list_first_entry(&ctx->mt_queue, struct sii8620_mt_msg, node);
if (msg->send)
msg->send(ctx, msg);
}
static void sii8620_mt_msc_cmd_send(struct sii8620 *ctx,
struct sii8620_mt_msg *msg)
{
switch (msg->reg[0]) {
case MHL_WRITE_STAT:
case MHL_SET_INT:
sii8620_write_buf(ctx, REG_MSC_CMD_OR_OFFSET, msg->reg + 1, 2);
sii8620_write(ctx, REG_MSC_COMMAND_START,
BIT_MSC_COMMAND_START_WRITE_STAT);
break;
case MHL_MSC_MSG:
sii8620_write_buf(ctx, REG_MSC_CMD_OR_OFFSET, msg->reg, 3);
sii8620_write(ctx, REG_MSC_COMMAND_START,
BIT_MSC_COMMAND_START_MSC_MSG);
break;
default:
dev_err(ctx->dev, "%s: command %#x not supported\n", __func__,
msg->reg[0]);
}
}
static struct sii8620_mt_msg *sii8620_mt_msg_new(struct sii8620 *ctx)
{
struct sii8620_mt_msg *msg = kzalloc(sizeof(*msg), GFP_KERNEL);
if (!msg)
ctx->error = -ENOMEM;
else
list_add_tail(&msg->node, &ctx->mt_queue);
return msg;
}
static void sii8620_mt_msc_cmd(struct sii8620 *ctx, u8 cmd, u8 arg1, u8 arg2)
{
struct sii8620_mt_msg *msg = sii8620_mt_msg_new(ctx);
if (!msg)
return;
msg->reg[0] = cmd;
msg->reg[1] = arg1;
msg->reg[2] = arg2;
msg->send = sii8620_mt_msc_cmd_send;
}
static void sii8620_mt_write_stat(struct sii8620 *ctx, u8 reg, u8 val)
{
sii8620_mt_msc_cmd(ctx, MHL_WRITE_STAT, reg, val);
}
static inline void sii8620_mt_set_int(struct sii8620 *ctx, u8 irq, u8 mask)
{
sii8620_mt_msc_cmd(ctx, MHL_SET_INT, irq, mask);
}
static void sii8620_mt_msc_msg(struct sii8620 *ctx, u8 cmd, u8 data)
{
sii8620_mt_msc_cmd(ctx, MHL_MSC_MSG, cmd, data);
}
static void sii8620_mt_rap(struct sii8620 *ctx, u8 code)
{
sii8620_mt_msc_msg(ctx, MHL_MSC_MSG_RAP, code);
}
static void sii8620_mt_read_devcap_send(struct sii8620 *ctx,
struct sii8620_mt_msg *msg)
{
u8 ctrl = BIT_EDID_CTRL_DEVCAP_SELECT_DEVCAP
| BIT_EDID_CTRL_EDID_FIFO_ADDR_AUTO
| BIT_EDID_CTRL_EDID_MODE_EN;
if (msg->reg[0] == MHL_READ_XDEVCAP)
ctrl |= BIT_EDID_CTRL_XDEVCAP_EN;
sii8620_write_seq(ctx,
REG_INTR9_MASK, BIT_INTR9_DEVCAP_DONE,
REG_EDID_CTRL, ctrl,
REG_TPI_CBUS_START, BIT_TPI_CBUS_START_GET_DEVCAP_START
);
}
static void sii8620_update_array(u8 *dst, u8 *src, int count)
{
while (--count >= 0) {
*src ^= *dst;
*dst++ ^= *src++;
}
}
static void sii8620_mr_devcap(struct sii8620 *ctx)
{
static const char * const sink_str[] = {
[SINK_NONE] = "NONE",
[SINK_HDMI] = "HDMI",
[SINK_DVI] = "DVI"
};
u8 dcap[MHL_DCAP_SIZE];
char sink_name[20];
struct device *dev = ctx->dev;
sii8620_read_buf(ctx, REG_EDID_FIFO_RD_DATA, dcap, MHL_DCAP_SIZE);
if (ctx->error < 0)
return;
dev_info(dev, "dcap: %*ph\n", MHL_DCAP_SIZE, dcap);
dev_info(dev, "detected dongle MHL %d.%d, ChipID %02x%02x:%02x%02x\n",
dcap[MHL_DCAP_MHL_VERSION] / 16,
dcap[MHL_DCAP_MHL_VERSION] % 16, dcap[MHL_DCAP_ADOPTER_ID_H],
dcap[MHL_DCAP_ADOPTER_ID_L], dcap[MHL_DCAP_DEVICE_ID_H],
dcap[MHL_DCAP_DEVICE_ID_L]);
sii8620_update_array(ctx->devcap, dcap, MHL_DCAP_SIZE);
if (!(dcap[MHL_DCAP_CAT] & MHL_DCAP_CAT_SINK))
return;
sii8620_fetch_edid(ctx);
if (!ctx->edid) {
dev_err(ctx->dev, "Cannot fetch EDID\n");
sii8620_mhl_disconnected(ctx);
return;
}
if (drm_detect_hdmi_monitor(ctx->edid))
ctx->sink_type = SINK_HDMI;
else
ctx->sink_type = SINK_DVI;
drm_edid_get_monitor_name(ctx->edid, sink_name, ARRAY_SIZE(sink_name));
dev_info(dev, "detected sink(type: %s): %s\n",
sink_str[ctx->sink_type], sink_name);
sii8620_set_upstream_edid(ctx);
sii8620_enable_hpd(ctx);
}
static void sii8620_mr_xdevcap(struct sii8620 *ctx)
{
sii8620_read_buf(ctx, REG_EDID_FIFO_RD_DATA, ctx->xdevcap,
MHL_XDC_SIZE);
sii8620_mt_write_stat(ctx, MHL_XDS_REG(CURR_ECBUS_MODE),
MHL_XDS_ECBUS_S | MHL_XDS_SLOT_MODE_8BIT);
sii8620_mt_rap(ctx, MHL_RAP_CBUS_MODE_UP);
}
static void sii8620_mt_read_devcap_recv(struct sii8620 *ctx,
struct sii8620_mt_msg *msg)
{
u8 ctrl = BIT_EDID_CTRL_DEVCAP_SELECT_DEVCAP
| BIT_EDID_CTRL_EDID_FIFO_ADDR_AUTO
| BIT_EDID_CTRL_EDID_MODE_EN;
if (msg->reg[0] == MHL_READ_XDEVCAP)
ctrl |= BIT_EDID_CTRL_XDEVCAP_EN;
sii8620_write_seq(ctx,
REG_INTR9_MASK, BIT_INTR9_DEVCAP_DONE | BIT_INTR9_EDID_DONE
| BIT_INTR9_EDID_ERROR,
REG_EDID_CTRL, ctrl,
REG_EDID_FIFO_ADDR, 0
);
if (msg->reg[0] == MHL_READ_XDEVCAP)
sii8620_mr_xdevcap(ctx);
else
sii8620_mr_devcap(ctx);
}
static void sii8620_mt_read_devcap(struct sii8620 *ctx, bool xdevcap)
{
struct sii8620_mt_msg *msg = sii8620_mt_msg_new(ctx);
if (!msg)
return;
msg->reg[0] = xdevcap ? MHL_READ_XDEVCAP : MHL_READ_DEVCAP;
msg->send = sii8620_mt_read_devcap_send;
msg->recv = sii8620_mt_read_devcap_recv;
}
static void sii8620_fetch_edid(struct sii8620 *ctx)
{
u8 lm_ddc, ddc_cmd, int3, cbus;
int fetched, i;
int edid_len = EDID_LENGTH;
u8 *edid;
sii8620_readb(ctx, REG_CBUS_STATUS);
lm_ddc = sii8620_readb(ctx, REG_LM_DDC);
ddc_cmd = sii8620_readb(ctx, REG_DDC_CMD);
sii8620_write_seq(ctx,
REG_INTR9_MASK, 0,
REG_EDID_CTRL, BIT_EDID_CTRL_EDID_FIFO_ADDR_AUTO,
REG_HDCP2X_POLL_CS, 0x71,
REG_HDCP2X_CTRL_0, BIT_HDCP2X_CTRL_0_HDCP2X_HDCPTX,
REG_LM_DDC, lm_ddc | BIT_LM_DDC_SW_TPI_EN_DISABLED,
);
for (i = 0; i < 256; ++i) {
u8 ddc_stat = sii8620_readb(ctx, REG_DDC_STATUS);
if (!(ddc_stat & BIT_DDC_STATUS_DDC_I2C_IN_PROG))
break;
sii8620_write(ctx, REG_DDC_STATUS,
BIT_DDC_STATUS_DDC_FIFO_EMPTY);
}
sii8620_write(ctx, REG_DDC_ADDR, 0x50 << 1);
edid = kmalloc(EDID_LENGTH, GFP_KERNEL);
if (!edid) {
ctx->error = -ENOMEM;
return;
}
#define FETCH_SIZE 16
for (fetched = 0; fetched < edid_len; fetched += FETCH_SIZE) {
sii8620_readb(ctx, REG_DDC_STATUS);
sii8620_write_seq(ctx,
REG_DDC_CMD, ddc_cmd | VAL_DDC_CMD_DDC_CMD_ABORT,
REG_DDC_CMD, ddc_cmd | VAL_DDC_CMD_DDC_CMD_CLEAR_FIFO,
REG_DDC_STATUS, BIT_DDC_STATUS_DDC_FIFO_EMPTY
);
sii8620_write_seq(ctx,
REG_DDC_SEGM, fetched >> 8,
REG_DDC_OFFSET, fetched & 0xff,
REG_DDC_DIN_CNT1, FETCH_SIZE,
REG_DDC_DIN_CNT2, 0,
REG_DDC_CMD, ddc_cmd | VAL_DDC_CMD_ENH_DDC_READ_NO_ACK
);
do {
int3 = sii8620_readb(ctx, REG_INTR3);
cbus = sii8620_readb(ctx, REG_CBUS_STATUS);
if (int3 & BIT_DDC_CMD_DONE)
break;
if (!(cbus & BIT_CBUS_STATUS_CBUS_CONNECTED)) {
kfree(edid);
edid = NULL;
goto end;
}
} while (1);
sii8620_readb(ctx, REG_DDC_STATUS);
while (sii8620_readb(ctx, REG_DDC_DOUT_CNT) < FETCH_SIZE)
usleep_range(10, 20);
sii8620_read_buf(ctx, REG_DDC_DATA, edid + fetched, FETCH_SIZE);
if (fetched + FETCH_SIZE == EDID_LENGTH) {
u8 ext = ((struct edid *)edid)->extensions;
if (ext) {
u8 *new_edid;
edid_len += ext * EDID_LENGTH;
new_edid = krealloc(edid, edid_len, GFP_KERNEL);
if (!new_edid) {
kfree(edid);
ctx->error = -ENOMEM;
return;
}
edid = new_edid;
}
}
if (fetched + FETCH_SIZE == edid_len)
sii8620_write(ctx, REG_INTR3, int3);
}
sii8620_write(ctx, REG_LM_DDC, lm_ddc);
end:
kfree(ctx->edid);
ctx->edid = (struct edid *)edid;
}
static void sii8620_set_upstream_edid(struct sii8620 *ctx)
{
sii8620_setbits(ctx, REG_DPD, BIT_DPD_PDNRX12 | BIT_DPD_PDIDCK_N
| BIT_DPD_PD_MHL_CLK_N, 0xff);
sii8620_write_seq_static(ctx,
REG_RX_HDMI_CTRL3, 0x00,
REG_PKT_FILTER_0, 0xFF,
REG_PKT_FILTER_1, 0xFF,
REG_ALICE0_BW_I2C, 0x06
);
sii8620_setbits(ctx, REG_RX_HDMI_CLR_BUFFER,
BIT_RX_HDMI_CLR_BUFFER_VSI_CLR_EN, 0xff);
sii8620_write_seq_static(ctx,
REG_EDID_CTRL, BIT_EDID_CTRL_EDID_FIFO_ADDR_AUTO
| BIT_EDID_CTRL_EDID_MODE_EN,
REG_EDID_FIFO_ADDR, 0,
);
sii8620_write_buf(ctx, REG_EDID_FIFO_WR_DATA, (u8 *)ctx->edid,
(ctx->edid->extensions + 1) * EDID_LENGTH);
sii8620_write_seq_static(ctx,
REG_EDID_CTRL, BIT_EDID_CTRL_EDID_PRIME_VALID
| BIT_EDID_CTRL_EDID_FIFO_ADDR_AUTO
| BIT_EDID_CTRL_EDID_MODE_EN,
REG_INTR5_MASK, BIT_INTR_SCDT_CHANGE,
REG_INTR9_MASK, 0
);
}
static void sii8620_xtal_set_rate(struct sii8620 *ctx)
{
static const struct {
unsigned int rate;
u8 div;
u8 tp1;
} rates[] = {
{ 19200, 0x04, 0x53 },
{ 20000, 0x04, 0x62 },
{ 24000, 0x05, 0x75 },
{ 30000, 0x06, 0x92 },
{ 38400, 0x0c, 0xbc },
};
unsigned long rate = clk_get_rate(ctx->clk_xtal) / 1000;
int i;
for (i = 0; i < ARRAY_SIZE(rates) - 1; ++i)
if (rate <= rates[i].rate)
break;
if (rate != rates[i].rate)
dev_err(ctx->dev, "xtal clock rate(%lukHz) not supported, setting MHL for %ukHz.\n",
rate, rates[i].rate);
sii8620_write(ctx, REG_DIV_CTL_MAIN, rates[i].div);
sii8620_write(ctx, REG_HDCP2X_TP1, rates[i].tp1);
}
static int sii8620_hw_on(struct sii8620 *ctx)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
if (ret)
return ret;
usleep_range(10000, 20000);
return clk_prepare_enable(ctx->clk_xtal);
}
static int sii8620_hw_off(struct sii8620 *ctx)
{
clk_disable_unprepare(ctx->clk_xtal);
gpiod_set_value(ctx->gpio_reset, 1);
return regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
}
static void sii8620_hw_reset(struct sii8620 *ctx)
{
usleep_range(10000, 20000);
gpiod_set_value(ctx->gpio_reset, 0);
usleep_range(5000, 20000);
gpiod_set_value(ctx->gpio_reset, 1);
usleep_range(10000, 20000);
gpiod_set_value(ctx->gpio_reset, 0);
msleep(300);
}
static void sii8620_cbus_reset(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_PWD_SRST, BIT_PWD_SRST_CBUS_RST
| BIT_PWD_SRST_CBUS_RST_SW_EN,
REG_PWD_SRST, BIT_PWD_SRST_CBUS_RST_SW_EN
);
}
static void sii8620_set_auto_zone(struct sii8620 *ctx)
{
if (ctx->mode != CM_MHL1) {
sii8620_write_seq_static(ctx,
REG_TX_ZONE_CTL1, 0x0,
REG_MHL_PLL_CTL0, VAL_MHL_PLL_CTL0_HDMI_CLK_RATIO_1X
| BIT_MHL_PLL_CTL0_CRYSTAL_CLK_SEL
| BIT_MHL_PLL_CTL0_ZONE_MASK_OE
);
} else {
sii8620_write_seq_static(ctx,
REG_TX_ZONE_CTL1, VAL_TX_ZONE_CTL1_TX_ZONE_CTRL_MODE,
REG_MHL_PLL_CTL0, VAL_MHL_PLL_CTL0_HDMI_CLK_RATIO_1X
| BIT_MHL_PLL_CTL0_ZONE_MASK_OE
);
}
}
static void sii8620_stop_video(struct sii8620 *ctx)
{
u8 uninitialized_var(val);
sii8620_write_seq_static(ctx,
REG_TPI_INTR_EN, 0,
REG_HDCP2X_INTR0_MASK, 0,
REG_TPI_COPP_DATA2, 0,
REG_TPI_INTR_ST0, ~0,
);
switch (ctx->sink_type) {
case SINK_DVI:
val = BIT_TPI_SC_REG_TMDS_OE_POWER_DOWN
| BIT_TPI_SC_TPI_AV_MUTE;
break;
case SINK_HDMI:
val = BIT_TPI_SC_REG_TMDS_OE_POWER_DOWN
| BIT_TPI_SC_TPI_AV_MUTE
| BIT_TPI_SC_TPI_OUTPUT_MODE_0_HDMI;
break;
default:
return;
}
sii8620_write(ctx, REG_TPI_SC, val);
}
static void sii8620_start_hdmi(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_RX_HDMI_CTRL2, VAL_RX_HDMI_CTRL2_DEFVAL
| BIT_RX_HDMI_CTRL2_USE_AV_MUTE,
REG_VID_OVRRD, BIT_VID_OVRRD_PP_AUTO_DISABLE
| BIT_VID_OVRRD_M1080P_OVRRD,
REG_VID_MODE, 0,
REG_MHL_TOP_CTL, 0x1,
REG_MHLTX_CTL6, 0xa0,
REG_TPI_INPUT, VAL_TPI_FORMAT(RGB, FULL),
REG_TPI_OUTPUT, VAL_TPI_FORMAT(RGB, FULL),
);
sii8620_mt_write_stat(ctx, MHL_DST_REG(LINK_MODE),
MHL_DST_LM_CLK_MODE_NORMAL |
MHL_DST_LM_PATH_ENABLED);
sii8620_set_auto_zone(ctx);
sii8620_write(ctx, REG_TPI_SC, BIT_TPI_SC_TPI_OUTPUT_MODE_0_HDMI);
sii8620_write_buf(ctx, REG_TPI_AVI_CHSUM, ctx->avif,
ARRAY_SIZE(ctx->avif));
sii8620_write(ctx, REG_PKT_FILTER_0, 0xa1, 0x2);
}
static void sii8620_start_video(struct sii8620 *ctx)
{
if (ctx->mode < CM_MHL3)
sii8620_stop_video(ctx);
switch (ctx->sink_type) {
case SINK_HDMI:
sii8620_start_hdmi(ctx);
break;
case SINK_DVI:
default:
break;
}
}
static void sii8620_disable_hpd(struct sii8620 *ctx)
{
sii8620_setbits(ctx, REG_EDID_CTRL, BIT_EDID_CTRL_EDID_PRIME_VALID, 0);
sii8620_write_seq_static(ctx,
REG_HPD_CTRL, BIT_HPD_CTRL_HPD_OUT_OVR_EN,
REG_INTR8_MASK, 0
);
}
static void sii8620_enable_hpd(struct sii8620 *ctx)
{
sii8620_setbits(ctx, REG_TMDS_CSTAT_P3,
BIT_TMDS_CSTAT_P3_SCDT_CLR_AVI_DIS
| BIT_TMDS_CSTAT_P3_CLR_AVI, ~0);
sii8620_write_seq_static(ctx,
REG_HPD_CTRL, BIT_HPD_CTRL_HPD_OUT_OVR_EN
| BIT_HPD_CTRL_HPD_HIGH,
);
}
static void sii8620_enable_gen2_write_burst(struct sii8620 *ctx)
{
if (ctx->gen2_write_burst)
return;
sii8620_write_seq_static(ctx,
REG_MDT_RCV_TIMEOUT, 100,
REG_MDT_RCV_CTRL, BIT_MDT_RCV_CTRL_MDT_RCV_EN
);
ctx->gen2_write_burst = 1;
}
static void sii8620_disable_gen2_write_burst(struct sii8620 *ctx)
{
if (!ctx->gen2_write_burst)
return;
sii8620_write_seq_static(ctx,
REG_MDT_XMIT_CTRL, 0,
REG_MDT_RCV_CTRL, 0
);
ctx->gen2_write_burst = 0;
}
static void sii8620_start_gen2_write_burst(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_MDT_INT_1_MASK, BIT_MDT_RCV_TIMEOUT
| BIT_MDT_RCV_SM_ABORT_PKT_RCVD | BIT_MDT_RCV_SM_ERROR
| BIT_MDT_XMIT_TIMEOUT | BIT_MDT_XMIT_SM_ABORT_PKT_RCVD
| BIT_MDT_XMIT_SM_ERROR,
REG_MDT_INT_0_MASK, BIT_MDT_XFIFO_EMPTY
| BIT_MDT_IDLE_AFTER_HAWB_DISABLE
| BIT_MDT_RFIFO_DATA_RDY
);
sii8620_enable_gen2_write_burst(ctx);
}
static void sii8620_mhl_discover(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_DISC_CTRL9, BIT_DISC_CTRL9_WAKE_DRVFLT
| BIT_DISC_CTRL9_DISC_PULSE_PROCEED,
REG_DISC_CTRL4, VAL_DISC_CTRL4(VAL_PUP_5K, VAL_PUP_20K),
REG_CBUS_DISC_INTR0_MASK, BIT_MHL3_EST_INT
| BIT_MHL_EST_INT
| BIT_NOT_MHL_EST_INT
| BIT_CBUS_MHL3_DISCON_INT
| BIT_CBUS_MHL12_DISCON_INT
| BIT_RGND_READY_INT,
REG_MHL_PLL_CTL0, VAL_MHL_PLL_CTL0_HDMI_CLK_RATIO_1X
| BIT_MHL_PLL_CTL0_CRYSTAL_CLK_SEL
| BIT_MHL_PLL_CTL0_ZONE_MASK_OE,
REG_MHL_DP_CTL0, BIT_MHL_DP_CTL0_DP_OE
| BIT_MHL_DP_CTL0_TX_OE_OVR,
REG_M3_CTRL, VAL_M3_CTRL_MHL3_VALUE,
REG_MHL_DP_CTL1, 0xA2,
REG_MHL_DP_CTL2, 0x03,
REG_MHL_DP_CTL3, 0x35,
REG_MHL_DP_CTL5, 0x02,
REG_MHL_DP_CTL6, 0x02,
REG_MHL_DP_CTL7, 0x03,
REG_COC_CTLC, 0xFF,
REG_DPD, BIT_DPD_PWRON_PLL | BIT_DPD_PDNTX12
| BIT_DPD_OSC_EN | BIT_DPD_PWRON_HSIC,
REG_COC_INTR_MASK, BIT_COC_PLL_LOCK_STATUS_CHANGE
| BIT_COC_CALIBRATION_DONE,
REG_CBUS_INT_1_MASK, BIT_CBUS_MSC_ABORT_RCVD
| BIT_CBUS_CMD_ABORT,
REG_CBUS_INT_0_MASK, BIT_CBUS_MSC_MT_DONE
| BIT_CBUS_HPD_CHG
| BIT_CBUS_MSC_MR_WRITE_STAT
| BIT_CBUS_MSC_MR_MSC_MSG
| BIT_CBUS_MSC_MR_WRITE_BURST
| BIT_CBUS_MSC_MR_SET_INT
| BIT_CBUS_MSC_MT_DONE_NACK
);
}
static void sii8620_peer_specific_init(struct sii8620 *ctx)
{
if (ctx->mode == CM_MHL3)
sii8620_write_seq_static(ctx,
REG_SYS_CTRL1, BIT_SYS_CTRL1_BLOCK_DDC_BY_HPD,
REG_EMSCINTRMASK1,
BIT_EMSCINTR1_EMSC_TRAINING_COMMA_ERR
);
else
sii8620_write_seq_static(ctx,
REG_HDCP2X_INTR0_MASK, 0x00,
REG_EMSCINTRMASK1, 0x00,
REG_HDCP2X_INTR0, 0xFF,
REG_INTR1, 0xFF,
REG_SYS_CTRL1, BIT_SYS_CTRL1_BLOCK_DDC_BY_HPD
| BIT_SYS_CTRL1_TX_CTRL_HDMI
);
}
static void sii8620_set_dev_cap(struct sii8620 *ctx)
{
static const u8 devcap[MHL_DCAP_SIZE] = {
[MHL_DCAP_MHL_VERSION] = SII8620_MHL_VERSION,
[MHL_DCAP_CAT] = MHL_DCAP_CAT_SOURCE | MHL_DCAP_CAT_POWER,
[MHL_DCAP_ADOPTER_ID_H] = 0x01,
[MHL_DCAP_ADOPTER_ID_L] = 0x41,
[MHL_DCAP_VID_LINK_MODE] = MHL_DCAP_VID_LINK_RGB444
| MHL_DCAP_VID_LINK_PPIXEL
| MHL_DCAP_VID_LINK_16BPP,
[MHL_DCAP_AUD_LINK_MODE] = MHL_DCAP_AUD_LINK_2CH,
[MHL_DCAP_VIDEO_TYPE] = MHL_DCAP_VT_GRAPHICS,
[MHL_DCAP_LOG_DEV_MAP] = MHL_DCAP_LD_GUI,
[MHL_DCAP_BANDWIDTH] = 0x0f,
[MHL_DCAP_FEATURE_FLAG] = MHL_DCAP_FEATURE_RCP_SUPPORT
| MHL_DCAP_FEATURE_RAP_SUPPORT
| MHL_DCAP_FEATURE_SP_SUPPORT,
[MHL_DCAP_SCRATCHPAD_SIZE] = SII8620_SCRATCHPAD_SIZE,
[MHL_DCAP_INT_STAT_SIZE] = SII8620_INT_STAT_SIZE,
};
static const u8 xdcap[MHL_XDC_SIZE] = {
[MHL_XDC_ECBUS_SPEEDS] = MHL_XDC_ECBUS_S_075
| MHL_XDC_ECBUS_S_8BIT,
[MHL_XDC_TMDS_SPEEDS] = MHL_XDC_TMDS_150
| MHL_XDC_TMDS_300 | MHL_XDC_TMDS_600,
[MHL_XDC_ECBUS_ROLES] = MHL_XDC_DEV_HOST,
[MHL_XDC_LOG_DEV_MAPX] = MHL_XDC_LD_PHONE,
};
sii8620_write_buf(ctx, REG_MHL_DEVCAP_0, devcap, ARRAY_SIZE(devcap));
sii8620_write_buf(ctx, REG_MHL_EXTDEVCAP_0, xdcap, ARRAY_SIZE(xdcap));
}
static void sii8620_mhl_init(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_DISC_CTRL4, VAL_DISC_CTRL4(VAL_PUP_OFF, VAL_PUP_20K),
REG_CBUS_MSC_COMPAT_CTRL,
BIT_CBUS_MSC_COMPAT_CTRL_XDEVCAP_EN,
);
sii8620_peer_specific_init(ctx);
sii8620_disable_hpd(ctx);
sii8620_write_seq_static(ctx,
REG_EDID_CTRL, BIT_EDID_CTRL_EDID_FIFO_ADDR_AUTO,
REG_DISC_CTRL9, BIT_DISC_CTRL9_WAKE_DRVFLT
| BIT_DISC_CTRL9_WAKE_PULSE_BYPASS,
REG_TMDS0_CCTRL1, 0x90,
REG_TMDS_CLK_EN, 0x01,
REG_TMDS_CH_EN, 0x11,
REG_BGR_BIAS, 0x87,
REG_ALICE0_ZONE_CTRL, 0xE8,
REG_ALICE0_MODE_CTRL, 0x04,
);
sii8620_setbits(ctx, REG_LM_DDC, BIT_LM_DDC_SW_TPI_EN_DISABLED, 0);
sii8620_write_seq_static(ctx,
REG_TPI_HW_OPT3, 0x76,
REG_TMDS_CCTRL, BIT_TMDS_CCTRL_TMDS_OE,
REG_TPI_DTD_B2, 79,
);
sii8620_set_dev_cap(ctx);
sii8620_write_seq_static(ctx,
REG_MDT_XMIT_TIMEOUT, 100,
REG_MDT_XMIT_CTRL, 0x03,
REG_MDT_XFIFO_STAT, 0x00,
REG_MDT_RCV_TIMEOUT, 100,
REG_CBUS_LINK_CTRL_8, 0x1D,
);
sii8620_start_gen2_write_burst(ctx);
sii8620_write_seq_static(ctx,
REG_BIST_CTRL, 0x00,
REG_COC_CTL1, 0x10,
REG_COC_CTL2, 0x18,
REG_COC_CTLF, 0x07,
REG_COC_CTL11, 0xF8,
REG_COC_CTL17, 0x61,
REG_COC_CTL18, 0x46,
REG_COC_CTL19, 0x15,
REG_COC_CTL1A, 0x01,
REG_MHL_COC_CTL3, BIT_MHL_COC_CTL3_COC_AECHO_EN,
REG_MHL_COC_CTL4, 0x2D,
REG_MHL_COC_CTL5, 0xF9,
REG_MSC_HEARTBEAT_CTRL, 0x27,
);
sii8620_disable_gen2_write_burst(ctx);
sii8620_mt_write_stat(ctx, MHL_DST_REG(VERSION), 0);
sii8620_mt_write_stat(ctx, MHL_DST_REG(CONNECTED_RDY),
MHL_DST_CONN_DCAP_RDY | MHL_DST_CONN_XDEVCAPP_SUPP
| MHL_DST_CONN_POW_STAT);
sii8620_mt_set_int(ctx, MHL_INT_REG(RCHANGE), MHL_INT_RC_DCAP_CHG);
}
static void sii8620_set_mode(struct sii8620 *ctx, enum sii8620_mode mode)
{
if (ctx->mode == mode)
return;
ctx->mode = mode;
switch (mode) {
case CM_MHL1:
sii8620_write_seq_static(ctx,
REG_CBUS_MSC_COMPAT_CTRL, 0x02,
REG_M3_CTRL, VAL_M3_CTRL_MHL1_2_VALUE,
REG_DPD, BIT_DPD_PWRON_PLL | BIT_DPD_PDNTX12
| BIT_DPD_OSC_EN,
REG_COC_INTR_MASK, 0
);
break;
case CM_MHL3:
sii8620_write_seq_static(ctx,
REG_M3_CTRL, VAL_M3_CTRL_MHL3_VALUE,
REG_COC_CTL0, 0x40,
REG_MHL_COC_CTL1, 0x07
);
break;
case CM_DISCONNECTED:
break;
default:
dev_err(ctx->dev, "%s mode %d not supported\n", __func__, mode);
break;
}
sii8620_set_auto_zone(ctx);
if (mode != CM_MHL1)
return;
sii8620_write_seq_static(ctx,
REG_MHL_DP_CTL0, 0xBC,
REG_MHL_DP_CTL1, 0xBB,
REG_MHL_DP_CTL3, 0x48,
REG_MHL_DP_CTL5, 0x39,
REG_MHL_DP_CTL2, 0x2A,
REG_MHL_DP_CTL6, 0x2A,
REG_MHL_DP_CTL7, 0x08
);
}
static void sii8620_disconnect(struct sii8620 *ctx)
{
sii8620_disable_gen2_write_burst(ctx);
sii8620_stop_video(ctx);
msleep(50);
sii8620_cbus_reset(ctx);
sii8620_set_mode(ctx, CM_DISCONNECTED);
sii8620_write_seq_static(ctx,
REG_COC_CTL0, 0x40,
REG_CBUS3_CNVT, 0x84,
REG_COC_CTL14, 0x00,
REG_COC_CTL0, 0x40,
REG_HRXCTRL3, 0x07,
REG_MHL_PLL_CTL0, VAL_MHL_PLL_CTL0_HDMI_CLK_RATIO_1X
| BIT_MHL_PLL_CTL0_CRYSTAL_CLK_SEL
| BIT_MHL_PLL_CTL0_ZONE_MASK_OE,
REG_MHL_DP_CTL0, BIT_MHL_DP_CTL0_DP_OE
| BIT_MHL_DP_CTL0_TX_OE_OVR,
REG_MHL_DP_CTL1, 0xBB,
REG_MHL_DP_CTL3, 0x48,
REG_MHL_DP_CTL5, 0x3F,
REG_MHL_DP_CTL2, 0x2F,
REG_MHL_DP_CTL6, 0x2A,
REG_MHL_DP_CTL7, 0x03
);
sii8620_disable_hpd(ctx);
sii8620_write_seq_static(ctx,
REG_M3_CTRL, VAL_M3_CTRL_MHL3_VALUE,
REG_MHL_COC_CTL1, 0x07,
REG_DISC_CTRL4, VAL_DISC_CTRL4(VAL_PUP_OFF, VAL_PUP_20K),
REG_DISC_CTRL8, 0x00,
REG_DISC_CTRL9, BIT_DISC_CTRL9_WAKE_DRVFLT
| BIT_DISC_CTRL9_WAKE_PULSE_BYPASS,
REG_INT_CTRL, 0x00,
REG_MSC_HEARTBEAT_CTRL, 0x27,
REG_DISC_CTRL1, 0x25,
REG_CBUS_DISC_INTR0, (u8)~BIT_RGND_READY_INT,
REG_CBUS_DISC_INTR0_MASK, BIT_RGND_READY_INT,
REG_MDT_INT_1, 0xff,
REG_MDT_INT_1_MASK, 0x00,
REG_MDT_INT_0, 0xff,
REG_MDT_INT_0_MASK, 0x00,
REG_COC_INTR, 0xff,
REG_COC_INTR_MASK, 0x00,
REG_TRXINTH, 0xff,
REG_TRXINTMH, 0x00,
REG_CBUS_INT_0, 0xff,
REG_CBUS_INT_0_MASK, 0x00,
REG_CBUS_INT_1, 0xff,
REG_CBUS_INT_1_MASK, 0x00,
REG_EMSCINTR, 0xff,
REG_EMSCINTRMASK, 0x00,
REG_EMSCINTR1, 0xff,
REG_EMSCINTRMASK1, 0x00,
REG_INTR8, 0xff,
REG_INTR8_MASK, 0x00,
REG_TPI_INTR_ST0, 0xff,
REG_TPI_INTR_EN, 0x00,
REG_HDCP2X_INTR0, 0xff,
REG_HDCP2X_INTR0_MASK, 0x00,
REG_INTR9, 0xff,
REG_INTR9_MASK, 0x00,
REG_INTR3, 0xff,
REG_INTR3_MASK, 0x00,
REG_INTR5, 0xff,
REG_INTR5_MASK, 0x00,
REG_INTR2, 0xff,
REG_INTR2_MASK, 0x00,
);
memset(ctx->stat, 0, sizeof(ctx->stat));
memset(ctx->xstat, 0, sizeof(ctx->xstat));
memset(ctx->devcap, 0, sizeof(ctx->devcap));
memset(ctx->xdevcap, 0, sizeof(ctx->xdevcap));
ctx->cbus_status = 0;
ctx->sink_type = SINK_NONE;
kfree(ctx->edid);
ctx->edid = NULL;
sii8620_mt_cleanup(ctx);
}
static void sii8620_mhl_disconnected(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_DISC_CTRL4, VAL_DISC_CTRL4(VAL_PUP_OFF, VAL_PUP_20K),
REG_CBUS_MSC_COMPAT_CTRL,
BIT_CBUS_MSC_COMPAT_CTRL_XDEVCAP_EN
);
sii8620_disconnect(ctx);
}
static void sii8620_irq_disc(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_CBUS_DISC_INTR0);
if (stat & VAL_CBUS_MHL_DISCON)
sii8620_mhl_disconnected(ctx);
if (stat & BIT_RGND_READY_INT) {
u8 stat2 = sii8620_readb(ctx, REG_DISC_STAT2);
if ((stat2 & MSK_DISC_STAT2_RGND) == VAL_RGND_1K) {
sii8620_mhl_discover(ctx);
} else {
sii8620_write_seq_static(ctx,
REG_DISC_CTRL9, BIT_DISC_CTRL9_WAKE_DRVFLT
| BIT_DISC_CTRL9_NOMHL_EST
| BIT_DISC_CTRL9_WAKE_PULSE_BYPASS,
REG_CBUS_DISC_INTR0_MASK, BIT_RGND_READY_INT
| BIT_CBUS_MHL3_DISCON_INT
| BIT_CBUS_MHL12_DISCON_INT
| BIT_NOT_MHL_EST_INT
);
}
}
if (stat & BIT_MHL_EST_INT)
sii8620_mhl_init(ctx);
sii8620_write(ctx, REG_CBUS_DISC_INTR0, stat);
}
static void sii8620_irq_g2wb(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_MDT_INT_0);
if (stat & BIT_MDT_IDLE_AFTER_HAWB_DISABLE)
dev_dbg(ctx->dev, "HAWB idle\n");
sii8620_write(ctx, REG_MDT_INT_0, stat);
}
static void sii8620_status_changed_dcap(struct sii8620 *ctx)
{
if (ctx->stat[MHL_DST_CONNECTED_RDY] & MHL_DST_CONN_DCAP_RDY) {
sii8620_set_mode(ctx, CM_MHL1);
sii8620_peer_specific_init(ctx);
sii8620_write(ctx, REG_INTR9_MASK, BIT_INTR9_DEVCAP_DONE
| BIT_INTR9_EDID_DONE | BIT_INTR9_EDID_ERROR);
}
}
static void sii8620_status_changed_path(struct sii8620 *ctx)
{
if (ctx->stat[MHL_DST_LINK_MODE] & MHL_DST_LM_PATH_ENABLED) {
sii8620_mt_write_stat(ctx, MHL_DST_REG(LINK_MODE),
MHL_DST_LM_CLK_MODE_NORMAL
| MHL_DST_LM_PATH_ENABLED);
sii8620_mt_read_devcap(ctx, false);
} else {
sii8620_mt_write_stat(ctx, MHL_DST_REG(LINK_MODE),
MHL_DST_LM_CLK_MODE_NORMAL);
}
}
static void sii8620_msc_mr_write_stat(struct sii8620 *ctx)
{
u8 st[MHL_DST_SIZE], xst[MHL_XDS_SIZE];
sii8620_read_buf(ctx, REG_MHL_STAT_0, st, MHL_DST_SIZE);
sii8620_read_buf(ctx, REG_MHL_EXTSTAT_0, xst, MHL_XDS_SIZE);
sii8620_update_array(ctx->stat, st, MHL_DST_SIZE);
sii8620_update_array(ctx->xstat, xst, MHL_XDS_SIZE);
if (st[MHL_DST_CONNECTED_RDY] & MHL_DST_CONN_DCAP_RDY)
sii8620_status_changed_dcap(ctx);
if (st[MHL_DST_LINK_MODE] & MHL_DST_LM_PATH_ENABLED)
sii8620_status_changed_path(ctx);
}
static void sii8620_msc_mr_set_int(struct sii8620 *ctx)
{
u8 ints[MHL_INT_SIZE];
sii8620_read_buf(ctx, REG_MHL_INT_0, ints, MHL_INT_SIZE);
sii8620_write_buf(ctx, REG_MHL_INT_0, ints, MHL_INT_SIZE);
}
static struct sii8620_mt_msg *sii8620_msc_msg_first(struct sii8620 *ctx)
{
struct device *dev = ctx->dev;
if (list_empty(&ctx->mt_queue)) {
dev_err(dev, "unexpected MSC MT response\n");
return NULL;
}
return list_first_entry(&ctx->mt_queue, struct sii8620_mt_msg, node);
}
static void sii8620_msc_mt_done(struct sii8620 *ctx)
{
struct sii8620_mt_msg *msg = sii8620_msc_msg_first(ctx);
if (!msg)
return;
msg->ret = sii8620_readb(ctx, REG_MSC_MT_RCVD_DATA0);
ctx->mt_state = MT_STATE_DONE;
}
static void sii8620_msc_mr_msc_msg(struct sii8620 *ctx)
{
struct sii8620_mt_msg *msg = sii8620_msc_msg_first(ctx);
u8 buf[2];
if (!msg)
return;
sii8620_read_buf(ctx, REG_MSC_MR_MSC_MSG_RCVD_1ST_DATA, buf, 2);
switch (buf[0]) {
case MHL_MSC_MSG_RAPK:
msg->ret = buf[1];
ctx->mt_state = MT_STATE_DONE;
break;
default:
dev_err(ctx->dev, "%s message type %d,%d not supported",
__func__, buf[0], buf[1]);
}
}
static void sii8620_irq_msc(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_CBUS_INT_0);
if (stat & ~BIT_CBUS_HPD_CHG)
sii8620_write(ctx, REG_CBUS_INT_0, stat & ~BIT_CBUS_HPD_CHG);
if (stat & BIT_CBUS_HPD_CHG) {
u8 cbus_stat = sii8620_readb(ctx, REG_CBUS_STATUS);
if ((cbus_stat ^ ctx->cbus_status) & BIT_CBUS_STATUS_CBUS_HPD) {
sii8620_write(ctx, REG_CBUS_INT_0, BIT_CBUS_HPD_CHG);
} else {
stat ^= BIT_CBUS_STATUS_CBUS_HPD;
cbus_stat ^= BIT_CBUS_STATUS_CBUS_HPD;
}
ctx->cbus_status = cbus_stat;
}
if (stat & BIT_CBUS_MSC_MR_WRITE_STAT)
sii8620_msc_mr_write_stat(ctx);
if (stat & BIT_CBUS_MSC_MR_SET_INT)
sii8620_msc_mr_set_int(ctx);
if (stat & BIT_CBUS_MSC_MT_DONE)
sii8620_msc_mt_done(ctx);
if (stat & BIT_CBUS_MSC_MR_MSC_MSG)
sii8620_msc_mr_msc_msg(ctx);
}
static void sii8620_irq_coc(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_COC_INTR);
sii8620_write(ctx, REG_COC_INTR, stat);
}
static void sii8620_irq_merr(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_CBUS_INT_1);
sii8620_write(ctx, REG_CBUS_INT_1, stat);
}
static void sii8620_irq_edid(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_INTR9);
sii8620_write(ctx, REG_INTR9, stat);
if (stat & BIT_INTR9_DEVCAP_DONE)
ctx->mt_state = MT_STATE_DONE;
}
static void sii8620_scdt_high(struct sii8620 *ctx)
{
sii8620_write_seq_static(ctx,
REG_INTR8_MASK, BIT_CEA_NEW_AVI | BIT_CEA_NEW_VSI,
REG_TPI_SC, BIT_TPI_SC_TPI_OUTPUT_MODE_0_HDMI,
);
}
static void sii8620_scdt_low(struct sii8620 *ctx)
{
sii8620_write(ctx, REG_TMDS_CSTAT_P3,
BIT_TMDS_CSTAT_P3_SCDT_CLR_AVI_DIS |
BIT_TMDS_CSTAT_P3_CLR_AVI);
sii8620_stop_video(ctx);
sii8620_write(ctx, REG_INTR8_MASK, 0);
}
static void sii8620_irq_scdt(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_INTR5);
if (stat & BIT_INTR_SCDT_CHANGE) {
u8 cstat = sii8620_readb(ctx, REG_TMDS_CSTAT_P3);
if (cstat & BIT_TMDS_CSTAT_P3_SCDT)
sii8620_scdt_high(ctx);
else
sii8620_scdt_low(ctx);
}
sii8620_write(ctx, REG_INTR5, stat);
}
static void sii8620_new_vsi(struct sii8620 *ctx)
{
u8 vsif[11];
sii8620_write(ctx, REG_RX_HDMI_CTRL2,
VAL_RX_HDMI_CTRL2_DEFVAL |
BIT_RX_HDMI_CTRL2_VSI_MON_SEL_VSI);
sii8620_read_buf(ctx, REG_RX_HDMI_MON_PKT_HEADER1, vsif,
ARRAY_SIZE(vsif));
}
static void sii8620_new_avi(struct sii8620 *ctx)
{
sii8620_write(ctx, REG_RX_HDMI_CTRL2, VAL_RX_HDMI_CTRL2_DEFVAL);
sii8620_read_buf(ctx, REG_RX_HDMI_MON_PKT_HEADER1, ctx->avif,
ARRAY_SIZE(ctx->avif));
}
static void sii8620_irq_infr(struct sii8620 *ctx)
{
u8 stat = sii8620_readb(ctx, REG_INTR8)
& (BIT_CEA_NEW_VSI | BIT_CEA_NEW_AVI);
sii8620_write(ctx, REG_INTR8, stat);
if (stat & BIT_CEA_NEW_VSI)
sii8620_new_vsi(ctx);
if (stat & BIT_CEA_NEW_AVI)
sii8620_new_avi(ctx);
if (stat & (BIT_CEA_NEW_VSI | BIT_CEA_NEW_AVI))
sii8620_start_video(ctx);
}
static bool sii8620_test_bit(unsigned int nr, const u8 *addr)
{
return 1 & (addr[nr / BITS_PER_BYTE] >> (nr % BITS_PER_BYTE));
}
static irqreturn_t sii8620_irq_thread(int irq, void *data)
{
static const struct {
int bit;
void (*handler)(struct sii8620 *ctx);
} irq_vec[] = {
{ BIT_FAST_INTR_STAT_DISC, sii8620_irq_disc },
{ BIT_FAST_INTR_STAT_G2WB, sii8620_irq_g2wb },
{ BIT_FAST_INTR_STAT_COC, sii8620_irq_coc },
{ BIT_FAST_INTR_STAT_MSC, sii8620_irq_msc },
{ BIT_FAST_INTR_STAT_MERR, sii8620_irq_merr },
{ BIT_FAST_INTR_STAT_EDID, sii8620_irq_edid },
{ BIT_FAST_INTR_STAT_SCDT, sii8620_irq_scdt },
{ BIT_FAST_INTR_STAT_INFR, sii8620_irq_infr },
};
struct sii8620 *ctx = data;
u8 stats[LEN_FAST_INTR_STAT];
int i, ret;
mutex_lock(&ctx->lock);
sii8620_read_buf(ctx, REG_FAST_INTR_STAT, stats, ARRAY_SIZE(stats));
for (i = 0; i < ARRAY_SIZE(irq_vec); ++i)
if (sii8620_test_bit(irq_vec[i].bit, stats))
irq_vec[i].handler(ctx);
sii8620_mt_work(ctx);
ret = sii8620_clear_error(ctx);
if (ret) {
dev_err(ctx->dev, "Error during IRQ handling, %d.\n", ret);
sii8620_mhl_disconnected(ctx);
}
mutex_unlock(&ctx->lock);
return IRQ_HANDLED;
}
static void sii8620_cable_in(struct sii8620 *ctx)
{
struct device *dev = ctx->dev;
u8 ver[5];
int ret;
ret = sii8620_hw_on(ctx);
if (ret) {
dev_err(dev, "Error powering on, %d.\n", ret);
return;
}
sii8620_hw_reset(ctx);
sii8620_read_buf(ctx, REG_VND_IDL, ver, ARRAY_SIZE(ver));
ret = sii8620_clear_error(ctx);
if (ret) {
dev_err(dev, "Error accessing I2C bus, %d.\n", ret);
return;
}
dev_info(dev, "ChipID %02x%02x:%02x%02x rev %02x.\n", ver[1], ver[0],
ver[3], ver[2], ver[4]);
sii8620_write(ctx, REG_DPD,
BIT_DPD_PWRON_PLL | BIT_DPD_PDNTX12 | BIT_DPD_OSC_EN);
sii8620_xtal_set_rate(ctx);
sii8620_disconnect(ctx);
sii8620_write_seq_static(ctx,
REG_MHL_CBUS_CTL0, VAL_MHL_CBUS_CTL0_CBUS_DRV_SEL_STRONG
| VAL_MHL_CBUS_CTL0_CBUS_RGND_VBIAS_734,
REG_MHL_CBUS_CTL1, VAL_MHL_CBUS_CTL1_1115_OHM,
REG_DPD, BIT_DPD_PWRON_PLL | BIT_DPD_PDNTX12 | BIT_DPD_OSC_EN,
);
ret = sii8620_clear_error(ctx);
if (ret) {
dev_err(dev, "Error accessing I2C bus, %d.\n", ret);
return;
}
enable_irq(to_i2c_client(ctx->dev)->irq);
}
static inline struct sii8620 *bridge_to_sii8620(struct drm_bridge *bridge)
{
return container_of(bridge, struct sii8620, bridge);
}
static bool sii8620_mode_fixup(struct drm_bridge *bridge,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct sii8620 *ctx = bridge_to_sii8620(bridge);
bool ret = false;
int max_clock = 74250;
mutex_lock(&ctx->lock);
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
goto out;
if (ctx->devcap[MHL_DCAP_VID_LINK_MODE] & MHL_DCAP_VID_LINK_PPIXEL)
max_clock = 300000;
ret = mode->clock <= max_clock;
out:
mutex_unlock(&ctx->lock);
return ret;
}
static int sii8620_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct sii8620 *ctx;
int ret;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = dev;
mutex_init(&ctx->lock);
INIT_LIST_HEAD(&ctx->mt_queue);
ctx->clk_xtal = devm_clk_get(dev, "xtal");
if (IS_ERR(ctx->clk_xtal)) {
dev_err(dev, "failed to get xtal clock from DT\n");
return PTR_ERR(ctx->clk_xtal);
}
if (!client->irq) {
dev_err(dev, "no irq provided\n");
return -EINVAL;
}
irq_set_status_flags(client->irq, IRQ_NOAUTOEN);
ret = devm_request_threaded_irq(dev, client->irq, NULL,
sii8620_irq_thread,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"sii8620", ctx);
ctx->gpio_reset = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(ctx->gpio_reset)) {
dev_err(dev, "failed to get reset gpio from DT\n");
return PTR_ERR(ctx->gpio_reset);
}
ctx->supplies[0].supply = "cvcc10";
ctx->supplies[1].supply = "iovcc18";
ret = devm_regulator_bulk_get(dev, 2, ctx->supplies);
if (ret)
return ret;
i2c_set_clientdata(client, ctx);
ctx->bridge.funcs = &sii8620_bridge_funcs;
ctx->bridge.of_node = dev->of_node;
drm_bridge_add(&ctx->bridge);
sii8620_cable_in(ctx);
return 0;
}
static int sii8620_remove(struct i2c_client *client)
{
struct sii8620 *ctx = i2c_get_clientdata(client);
disable_irq(to_i2c_client(ctx->dev)->irq);
drm_bridge_remove(&ctx->bridge);
sii8620_hw_off(ctx);
return 0;
}
