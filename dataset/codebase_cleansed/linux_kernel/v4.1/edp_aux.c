static int edp_msg_fifo_tx(struct edp_aux *aux, struct drm_dp_aux_msg *msg)
{
u32 data[4];
u32 reg, len;
bool native = msg->request & (DP_AUX_NATIVE_WRITE & DP_AUX_NATIVE_READ);
bool read = msg->request & (DP_AUX_I2C_READ & DP_AUX_NATIVE_READ);
u8 *msgdata = msg->buffer;
int i;
if (read)
len = 4;
else
len = msg->size + 4;
if (len > AUX_CMD_FIFO_LEN)
return -EINVAL;
data[0] = (msg->address >> 16) & 0xf;
if (read)
data[0] |= BIT(4);
data[1] = (msg->address >> 8) & 0xff;
data[2] = msg->address & 0xff;
data[3] = (msg->size - 1) & 0xff;
for (i = 0; i < len; i++) {
reg = (i < 4) ? data[i] : msgdata[i - 4];
reg = EDP_AUX_DATA_DATA(reg);
if (i == 0)
reg |= EDP_AUX_DATA_INDEX_WRITE;
edp_write(aux->base + REG_EDP_AUX_DATA, reg);
}
reg = 0;
if (!native)
reg |= EDP_AUX_TRANS_CTRL_I2C;
reg |= EDP_AUX_TRANS_CTRL_GO;
edp_write(aux->base + REG_EDP_AUX_TRANS_CTRL, reg);
return 0;
}
static int edp_msg_fifo_rx(struct edp_aux *aux, struct drm_dp_aux_msg *msg)
{
u32 data;
u8 *dp;
int i;
u32 len = msg->size;
edp_write(aux->base + REG_EDP_AUX_DATA,
EDP_AUX_DATA_INDEX_WRITE | EDP_AUX_DATA_READ);
dp = msg->buffer;
data = edp_read(aux->base + REG_EDP_AUX_DATA);
for (i = 0; i < len; i++) {
data = edp_read(aux->base + REG_EDP_AUX_DATA);
dp[i] = (u8)((data >> 8) & 0xff);
}
return 0;
}
ssize_t edp_aux_transfer(struct drm_dp_aux *drm_aux, struct drm_dp_aux_msg *msg)
{
struct edp_aux *aux = to_edp_aux(drm_aux);
ssize_t ret;
bool native = msg->request & (DP_AUX_NATIVE_WRITE & DP_AUX_NATIVE_READ);
bool read = msg->request & (DP_AUX_I2C_READ & DP_AUX_NATIVE_READ);
if ((msg->size == 0) || (msg->buffer == NULL)) {
msg->reply = native ?
DP_AUX_NATIVE_REPLY_ACK : DP_AUX_I2C_REPLY_ACK;
return msg->size;
}
if ((native && (msg->size > AUX_CMD_NATIVE_MAX)) ||
(msg->size > AUX_CMD_I2C_MAX)) {
pr_err("%s: invalid msg: size(%zu), request(%x)\n",
__func__, msg->size, msg->request);
return -EINVAL;
}
mutex_lock(&aux->msg_mutex);
aux->msg_err = false;
reinit_completion(&aux->msg_comp);
ret = edp_msg_fifo_tx(aux, msg);
if (ret < 0)
goto unlock_exit;
DBG("wait_for_completion");
ret = wait_for_completion_timeout(&aux->msg_comp, 300);
if (ret <= 0) {
edp_write(aux->base + REG_EDP_AUX_TRANS_CTRL, 0);
msm_edp_aux_ctrl(aux, 1);
pr_err("%s: aux timeout, %zd\n", __func__, ret);
goto unlock_exit;
}
DBG("completion");
if (!aux->msg_err) {
if (read) {
ret = edp_msg_fifo_rx(aux, msg);
if (ret < 0)
goto unlock_exit;
}
msg->reply = native ?
DP_AUX_NATIVE_REPLY_ACK : DP_AUX_I2C_REPLY_ACK;
} else {
msg->reply = native ?
DP_AUX_NATIVE_REPLY_DEFER : DP_AUX_I2C_REPLY_DEFER;
msleep(100);
}
ret = msg->size;
unlock_exit:
mutex_unlock(&aux->msg_mutex);
return ret;
}
void *msm_edp_aux_init(struct device *dev, void __iomem *regbase,
struct drm_dp_aux **drm_aux)
{
struct edp_aux *aux = NULL;
int ret;
DBG("");
aux = devm_kzalloc(dev, sizeof(*aux), GFP_KERNEL);
if (!aux)
return NULL;
aux->base = regbase;
mutex_init(&aux->msg_mutex);
init_completion(&aux->msg_comp);
aux->drm_aux.name = "msm_edp_aux";
aux->drm_aux.dev = dev;
aux->drm_aux.transfer = edp_aux_transfer;
ret = drm_dp_aux_register(&aux->drm_aux);
if (ret) {
pr_err("%s: failed to register drm aux: %d\n", __func__, ret);
mutex_destroy(&aux->msg_mutex);
}
if (drm_aux && aux)
*drm_aux = &aux->drm_aux;
return aux;
}
void msm_edp_aux_destroy(struct device *dev, struct edp_aux *aux)
{
if (aux) {
drm_dp_aux_unregister(&aux->drm_aux);
mutex_destroy(&aux->msg_mutex);
}
}
irqreturn_t msm_edp_aux_irq(struct edp_aux *aux, u32 isr)
{
if (isr & EDP_INTR_TRANS_STATUS) {
DBG("isr=%x", isr);
edp_write(aux->base + REG_EDP_AUX_TRANS_CTRL, 0);
if (isr & EDP_INTR_AUX_I2C_ERR)
aux->msg_err = true;
else
aux->msg_err = false;
complete(&aux->msg_comp);
}
return IRQ_HANDLED;
}
void msm_edp_aux_ctrl(struct edp_aux *aux, int enable)
{
u32 data;
DBG("enable=%d", enable);
data = edp_read(aux->base + REG_EDP_AUX_CTRL);
if (enable) {
data |= EDP_AUX_CTRL_RESET;
edp_write(aux->base + REG_EDP_AUX_CTRL, data);
wmb();
usleep_range(500, 1000);
data &= ~EDP_AUX_CTRL_RESET;
data |= EDP_AUX_CTRL_ENABLE;
edp_write(aux->base + REG_EDP_AUX_CTRL, data);
} else {
data &= ~EDP_AUX_CTRL_ENABLE;
edp_write(aux->base + REG_EDP_AUX_CTRL, data);
}
}
