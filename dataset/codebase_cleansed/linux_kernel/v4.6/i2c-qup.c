static irqreturn_t qup_i2c_interrupt(int irq, void *dev)
{
struct qup_i2c_dev *qup = dev;
u32 bus_err;
u32 qup_err;
u32 opflags;
bus_err = readl(qup->base + QUP_I2C_STATUS);
qup_err = readl(qup->base + QUP_ERROR_FLAGS);
opflags = readl(qup->base + QUP_OPERATIONAL);
if (!qup->msg) {
writel(QUP_RESET_STATE, qup->base + QUP_STATE);
return IRQ_HANDLED;
}
bus_err &= I2C_STATUS_ERROR_MASK;
qup_err &= QUP_STATUS_ERROR_FLAGS;
if (qup_err) {
writel(qup_err, qup->base + QUP_ERROR_FLAGS);
goto done;
}
if (bus_err) {
writel(QUP_RESET_STATE, qup->base + QUP_STATE);
goto done;
}
if (opflags & QUP_IN_SVC_FLAG)
writel(QUP_IN_SVC_FLAG, qup->base + QUP_OPERATIONAL);
if (opflags & QUP_OUT_SVC_FLAG)
writel(QUP_OUT_SVC_FLAG, qup->base + QUP_OPERATIONAL);
done:
qup->qup_err = qup_err;
qup->bus_err = bus_err;
complete(&qup->xfer);
return IRQ_HANDLED;
}
static int qup_i2c_poll_state_mask(struct qup_i2c_dev *qup,
u32 req_state, u32 req_mask)
{
int retries = 1;
u32 state;
do {
state = readl(qup->base + QUP_STATE);
if (state & QUP_STATE_VALID &&
(state & req_mask) == req_state)
return 0;
udelay(1);
} while (retries--);
return -ETIMEDOUT;
}
static int qup_i2c_poll_state(struct qup_i2c_dev *qup, u32 req_state)
{
return qup_i2c_poll_state_mask(qup, req_state, QUP_STATE_MASK);
}
static void qup_i2c_flush(struct qup_i2c_dev *qup)
{
u32 val = readl(qup->base + QUP_STATE);
val |= QUP_I2C_FLUSH;
writel(val, qup->base + QUP_STATE);
}
static int qup_i2c_poll_state_valid(struct qup_i2c_dev *qup)
{
return qup_i2c_poll_state_mask(qup, 0, 0);
}
static int qup_i2c_poll_state_i2c_master(struct qup_i2c_dev *qup)
{
return qup_i2c_poll_state_mask(qup, QUP_I2C_MAST_GEN, QUP_I2C_MAST_GEN);
}
static int qup_i2c_change_state(struct qup_i2c_dev *qup, u32 state)
{
if (qup_i2c_poll_state_valid(qup) != 0)
return -EIO;
writel(state, qup->base + QUP_STATE);
if (qup_i2c_poll_state(qup, state) != 0)
return -EIO;
return 0;
}
static int qup_i2c_wait_ready(struct qup_i2c_dev *qup, int op, bool val,
int len)
{
unsigned long timeout;
u32 opflags;
u32 status;
u32 shift = __ffs(op);
len *= qup->one_byte_t;
timeout = jiffies + len * 4;
for (;;) {
opflags = readl(qup->base + QUP_OPERATIONAL);
status = readl(qup->base + QUP_I2C_STATUS);
if (((opflags & op) >> shift) == val) {
if ((op == QUP_OUT_NOT_EMPTY) && qup->is_last) {
if (!(status & I2C_STATUS_BUS_ACTIVE))
return 0;
} else {
return 0;
}
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
usleep_range(len, len * 2);
}
}
static void qup_i2c_set_write_mode_v2(struct qup_i2c_dev *qup,
struct i2c_msg *msg)
{
int total = msg->len + qup->blk.tx_tag_len;
total |= qup->config_run;
if (total < qup->out_fifo_sz) {
writel(QUP_REPACK_EN, qup->base + QUP_IO_MODE);
writel(total, qup->base + QUP_MX_WRITE_CNT);
} else {
writel(QUP_OUTPUT_BLK_MODE | QUP_REPACK_EN,
qup->base + QUP_IO_MODE);
writel(total, qup->base + QUP_MX_OUTPUT_CNT);
}
}
static void qup_i2c_set_write_mode(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int total = msg->len + 1;
if (total < qup->out_fifo_sz) {
writel(QUP_REPACK_EN, qup->base + QUP_IO_MODE);
writel(total, qup->base + QUP_MX_WRITE_CNT);
} else {
writel(QUP_OUTPUT_BLK_MODE | QUP_REPACK_EN,
qup->base + QUP_IO_MODE);
writel(total, qup->base + QUP_MX_OUTPUT_CNT);
}
}
static int check_for_fifo_space(struct qup_i2c_dev *qup)
{
int ret;
ret = qup_i2c_change_state(qup, QUP_PAUSE_STATE);
if (ret)
goto out;
ret = qup_i2c_wait_ready(qup, QUP_OUT_FULL,
RESET_BIT, 4 * ONE_BYTE);
if (ret) {
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto out;
ret = qup_i2c_wait_ready(qup, QUP_OUT_NOT_EMPTY,
RESET_BIT, 256 * ONE_BYTE);
if (ret) {
dev_err(qup->dev, "timeout for fifo out full");
goto out;
}
ret = qup_i2c_change_state(qup, QUP_PAUSE_STATE);
if (ret)
goto out;
}
out:
return ret;
}
static int qup_i2c_issue_write(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
u32 addr = msg->addr << 1;
u32 qup_tag;
int idx;
u32 val;
int ret = 0;
if (qup->pos == 0) {
val = QUP_TAG_START | addr;
idx = 1;
} else {
val = 0;
idx = 0;
}
while (qup->pos < msg->len) {
ret = check_for_fifo_space(qup);
if (ret)
return ret;
if (qup->pos == msg->len - 1)
qup_tag = QUP_TAG_STOP;
else
qup_tag = QUP_TAG_DATA;
if (idx & 1)
val |= (qup_tag | msg->buf[qup->pos]) << QUP_MSW_SHIFT;
else
val = qup_tag | msg->buf[qup->pos];
if (idx & 1 || qup->pos == msg->len - 1)
writel(val, qup->base + QUP_OUT_FIFO_BASE);
qup->pos++;
idx++;
}
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
return ret;
}
static void qup_i2c_set_blk_data(struct qup_i2c_dev *qup,
struct i2c_msg *msg)
{
memset(&qup->blk, 0, sizeof(qup->blk));
qup->blk.data_len = msg->len;
qup->blk.count = (msg->len + QUP_READ_LIMIT - 1) / QUP_READ_LIMIT;
qup->blk.tx_tag_len = 4 + (qup->blk.count - 1) * 2;
if (msg->flags & I2C_M_RD)
qup->blk.rx_tag_len = qup->blk.count * 2;
}
static int qup_i2c_send_data(struct qup_i2c_dev *qup, int tlen, u8 *tbuf,
int dlen, u8 *dbuf)
{
u32 val = 0, idx = 0, pos = 0, i = 0, t;
int len = tlen + dlen;
u8 *buf = tbuf;
int ret = 0;
while (len > 0) {
ret = check_for_fifo_space(qup);
if (ret)
return ret;
t = (len >= 4) ? 4 : len;
while (idx < t) {
if (!i && (pos >= tlen)) {
buf = dbuf;
pos = 0;
i = 1;
}
val |= buf[pos++] << (idx++ * 8);
}
writel(val, qup->base + QUP_OUT_FIFO_BASE);
idx = 0;
val = 0;
len -= 4;
}
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
return ret;
}
static int qup_i2c_get_data_len(struct qup_i2c_dev *qup)
{
int data_len;
if (qup->blk.data_len > QUP_READ_LIMIT)
data_len = QUP_READ_LIMIT;
else
data_len = qup->blk.data_len;
return data_len;
}
static int qup_i2c_set_tags(u8 *tags, struct qup_i2c_dev *qup,
struct i2c_msg *msg, int is_dma)
{
u16 addr = (msg->addr << 1) | ((msg->flags & I2C_M_RD) == I2C_M_RD);
int len = 0;
int data_len;
int last = (qup->blk.pos == (qup->blk.count - 1)) && (qup->is_last);
if (qup->blk.pos == 0) {
tags[len++] = QUP_TAG_V2_START;
tags[len++] = addr & 0xff;
if (msg->flags & I2C_M_TEN)
tags[len++] = addr >> 8;
}
if (last) {
if (msg->flags & I2C_M_RD)
tags[len++] = QUP_TAG_V2_DATARD_STOP;
else
tags[len++] = QUP_TAG_V2_DATAWR_STOP;
} else {
if (msg->flags & I2C_M_RD)
tags[len++] = QUP_TAG_V2_DATARD;
else
tags[len++] = QUP_TAG_V2_DATAWR;
}
data_len = qup_i2c_get_data_len(qup);
if (data_len == QUP_READ_LIMIT)
tags[len++] = 0;
else
tags[len++] = data_len;
if ((msg->flags & I2C_M_RD) && last && is_dma) {
tags[len++] = QUP_BAM_INPUT_EOT;
tags[len++] = QUP_BAM_FLUSH_STOP;
}
return len;
}
static int qup_i2c_issue_xfer_v2(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int data_len = 0, tag_len, index;
int ret;
tag_len = qup_i2c_set_tags(qup->blk.tags, qup, msg, 0);
index = msg->len - qup->blk.data_len;
if (!(msg->flags & I2C_M_RD))
data_len = qup_i2c_get_data_len(qup);
ret = qup_i2c_send_data(qup, tag_len, qup->blk.tags,
data_len, &msg->buf[index]);
qup->blk.data_len -= data_len;
return ret;
}
static void qup_i2c_bam_cb(void *data)
{
struct qup_i2c_dev *qup = data;
complete(&qup->xfer);
}
static int qup_sg_set_buf(struct scatterlist *sg, void *buf,
struct qup_i2c_tag *tg, unsigned int buflen,
struct qup_i2c_dev *qup, int map, int dir)
{
int ret;
sg_set_buf(sg, buf, buflen);
ret = dma_map_sg(qup->dev, sg, 1, dir);
if (!ret)
return -EINVAL;
if (!map)
sg_dma_address(sg) = tg->addr + ((u8 *)buf - tg->start);
return 0;
}
static void qup_i2c_rel_dma(struct qup_i2c_dev *qup)
{
if (qup->btx.dma)
dma_release_channel(qup->btx.dma);
if (qup->brx.dma)
dma_release_channel(qup->brx.dma);
qup->btx.dma = NULL;
qup->brx.dma = NULL;
}
static int qup_i2c_req_dma(struct qup_i2c_dev *qup)
{
int err;
if (!qup->btx.dma) {
qup->btx.dma = dma_request_slave_channel_reason(qup->dev, "tx");
if (IS_ERR(qup->btx.dma)) {
err = PTR_ERR(qup->btx.dma);
qup->btx.dma = NULL;
dev_err(qup->dev, "\n tx channel not available");
return err;
}
}
if (!qup->brx.dma) {
qup->brx.dma = dma_request_slave_channel_reason(qup->dev, "rx");
if (IS_ERR(qup->brx.dma)) {
dev_err(qup->dev, "\n rx channel not available");
err = PTR_ERR(qup->brx.dma);
qup->brx.dma = NULL;
qup_i2c_rel_dma(qup);
return err;
}
}
return 0;
}
static int qup_i2c_bam_do_xfer(struct qup_i2c_dev *qup, struct i2c_msg *msg,
int num)
{
struct dma_async_tx_descriptor *txd, *rxd = NULL;
int ret = 0, idx = 0, limit = QUP_READ_LIMIT;
dma_cookie_t cookie_rx, cookie_tx;
u32 rx_nents = 0, tx_nents = 0, len, blocks, rem;
u32 i, tlen, tx_len, tx_buf = 0, rx_buf = 0, off = 0;
u8 *tags;
while (idx < num) {
blocks = (msg->len + limit) / limit;
rem = msg->len % limit;
tx_len = 0, len = 0, i = 0;
qup->is_last = (idx == (num - 1));
qup_i2c_set_blk_data(qup, msg);
if (msg->flags & I2C_M_RD) {
rx_nents += (blocks * 2) + 1;
tx_nents += 1;
while (qup->blk.pos < blocks) {
tlen = (i == (blocks - 1)) ? rem : 0;
tags = &qup->start_tag.start[off + len];
len += qup_i2c_set_tags(tags, qup, msg, 1);
ret = qup_sg_set_buf(&qup->brx.sg[rx_buf++],
&qup->brx.tag.start[0],
&qup->brx.tag,
2, qup, 0, 0);
if (ret)
return ret;
ret = qup_sg_set_buf(&qup->brx.sg[rx_buf++],
&msg->buf[limit * i],
NULL, tlen, qup,
1, DMA_FROM_DEVICE);
if (ret)
return ret;
i++;
qup->blk.pos = i;
}
ret = qup_sg_set_buf(&qup->btx.sg[tx_buf++],
&qup->start_tag.start[off],
&qup->start_tag, len, qup, 0, 0);
if (ret)
return ret;
off += len;
ret = qup_sg_set_buf(&qup->brx.sg[rx_buf++],
&qup->brx.tag.start[0],
&qup->brx.tag, 2,
qup, 0, 0);
if (ret)
return ret;
} else {
tx_nents += (blocks * 2);
while (qup->blk.pos < blocks) {
tlen = (i == (blocks - 1)) ? rem : 0;
tags = &qup->start_tag.start[off + tx_len];
len = qup_i2c_set_tags(tags, qup, msg, 1);
ret = qup_sg_set_buf(&qup->btx.sg[tx_buf++],
tags,
&qup->start_tag, len,
qup, 0, 0);
if (ret)
return ret;
tx_len += len;
ret = qup_sg_set_buf(&qup->btx.sg[tx_buf++],
&msg->buf[limit * i],
NULL, tlen, qup, 1,
DMA_TO_DEVICE);
if (ret)
return ret;
i++;
qup->blk.pos = i;
}
off += tx_len;
if (idx == (num - 1)) {
len = 1;
if (rx_nents) {
qup->btx.tag.start[0] =
QUP_BAM_INPUT_EOT;
len++;
}
qup->btx.tag.start[len - 1] =
QUP_BAM_FLUSH_STOP;
ret = qup_sg_set_buf(&qup->btx.sg[tx_buf++],
&qup->btx.tag.start[0],
&qup->btx.tag, len,
qup, 0, 0);
if (ret)
return ret;
tx_nents += 1;
}
}
idx++;
msg++;
}
txd = dmaengine_prep_slave_sg(qup->btx.dma, qup->btx.sg, tx_nents,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_PREP_FENCE);
if (!txd) {
dev_err(qup->dev, "failed to get tx desc\n");
ret = -EINVAL;
goto desc_err;
}
if (!rx_nents) {
txd->callback = qup_i2c_bam_cb;
txd->callback_param = qup;
}
cookie_tx = dmaengine_submit(txd);
if (dma_submit_error(cookie_tx)) {
ret = -EINVAL;
goto desc_err;
}
dma_async_issue_pending(qup->btx.dma);
if (rx_nents) {
rxd = dmaengine_prep_slave_sg(qup->brx.dma, qup->brx.sg,
rx_nents, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
if (!rxd) {
dev_err(qup->dev, "failed to get rx desc\n");
ret = -EINVAL;
dmaengine_terminate_all(qup->btx.dma);
goto desc_err;
}
rxd->callback = qup_i2c_bam_cb;
rxd->callback_param = qup;
cookie_rx = dmaengine_submit(rxd);
if (dma_submit_error(cookie_rx)) {
ret = -EINVAL;
goto desc_err;
}
dma_async_issue_pending(qup->brx.dma);
}
if (!wait_for_completion_timeout(&qup->xfer, TOUT_MAX * HZ)) {
dev_err(qup->dev, "normal trans timed out\n");
ret = -ETIMEDOUT;
}
if (ret || qup->bus_err || qup->qup_err) {
if (qup->bus_err & QUP_I2C_NACK_FLAG) {
msg--;
dev_err(qup->dev, "NACK from %x\n", msg->addr);
ret = -EIO;
if (qup_i2c_change_state(qup, QUP_RUN_STATE)) {
dev_err(qup->dev, "change to run state timed out");
return ret;
}
if (rx_nents)
writel(QUP_BAM_INPUT_EOT,
qup->base + QUP_OUT_FIFO_BASE);
writel(QUP_BAM_FLUSH_STOP,
qup->base + QUP_OUT_FIFO_BASE);
qup_i2c_flush(qup);
if (!wait_for_completion_timeout(&qup->xfer, HZ))
dev_err(qup->dev, "flush timed out\n");
qup_i2c_rel_dma(qup);
}
}
dma_unmap_sg(qup->dev, qup->btx.sg, tx_nents, DMA_TO_DEVICE);
if (rx_nents)
dma_unmap_sg(qup->dev, qup->brx.sg, rx_nents,
DMA_FROM_DEVICE);
desc_err:
return ret;
}
static int qup_i2c_bam_xfer(struct i2c_adapter *adap, struct i2c_msg *msg,
int num)
{
struct qup_i2c_dev *qup = i2c_get_adapdata(adap);
int ret = 0;
enable_irq(qup->irq);
ret = qup_i2c_req_dma(qup);
if (ret)
goto out;
qup->bus_err = 0;
qup->qup_err = 0;
writel(0, qup->base + QUP_MX_INPUT_CNT);
writel(0, qup->base + QUP_MX_OUTPUT_CNT);
writel(QUP_REPACK_EN | QUP_BAM_MODE, qup->base + QUP_IO_MODE);
writel((0x3 << 8), qup->base + QUP_OPERATIONAL_MASK);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto out;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
qup->msg = msg;
ret = qup_i2c_bam_do_xfer(qup, qup->msg, num);
out:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static int qup_i2c_wait_for_complete(struct qup_i2c_dev *qup,
struct i2c_msg *msg)
{
unsigned long left;
int ret = 0;
left = wait_for_completion_timeout(&qup->xfer, HZ);
if (!left) {
writel(1, qup->base + QUP_SW_RESET);
ret = -ETIMEDOUT;
}
if (qup->bus_err || qup->qup_err) {
if (qup->bus_err & QUP_I2C_NACK_FLAG) {
dev_err(qup->dev, "NACK from %x\n", msg->addr);
ret = -EIO;
}
}
return ret;
}
static int qup_i2c_write_one_v2(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int ret = 0;
qup->msg = msg;
qup->pos = 0;
enable_irq(qup->irq);
qup_i2c_set_blk_data(qup, msg);
qup_i2c_set_write_mode_v2(qup, msg);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
do {
ret = qup_i2c_issue_xfer_v2(qup, msg);
if (ret)
goto err;
ret = qup_i2c_wait_for_complete(qup, msg);
if (ret)
goto err;
qup->blk.pos++;
} while (qup->blk.pos < qup->blk.count);
ret = qup_i2c_wait_ready(qup, QUP_OUT_NOT_EMPTY, RESET_BIT, ONE_BYTE);
err:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static int qup_i2c_write_one(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int ret;
qup->msg = msg;
qup->pos = 0;
enable_irq(qup->irq);
qup_i2c_set_write_mode(qup, msg);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
do {
ret = qup_i2c_change_state(qup, QUP_PAUSE_STATE);
if (ret)
goto err;
ret = qup_i2c_issue_write(qup, msg);
if (ret)
goto err;
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
ret = qup_i2c_wait_for_complete(qup, msg);
if (ret)
goto err;
} while (qup->pos < msg->len);
ret = qup_i2c_wait_ready(qup, QUP_OUT_NOT_EMPTY, RESET_BIT, ONE_BYTE);
err:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static void qup_i2c_set_read_mode(struct qup_i2c_dev *qup, int len)
{
if (len < qup->in_fifo_sz) {
writel(QUP_REPACK_EN, qup->base + QUP_IO_MODE);
writel(len, qup->base + QUP_MX_READ_CNT);
} else {
writel(QUP_INPUT_BLK_MODE | QUP_REPACK_EN,
qup->base + QUP_IO_MODE);
writel(len, qup->base + QUP_MX_INPUT_CNT);
}
}
static void qup_i2c_set_read_mode_v2(struct qup_i2c_dev *qup, int len)
{
int tx_len = qup->blk.tx_tag_len;
len += qup->blk.rx_tag_len;
len |= qup->config_run;
tx_len |= qup->config_run;
if (len < qup->in_fifo_sz) {
writel(QUP_REPACK_EN, qup->base + QUP_IO_MODE);
writel(tx_len, qup->base + QUP_MX_WRITE_CNT);
writel(len, qup->base + QUP_MX_READ_CNT);
} else {
writel(QUP_INPUT_BLK_MODE | QUP_REPACK_EN,
qup->base + QUP_IO_MODE);
writel(tx_len, qup->base + QUP_MX_OUTPUT_CNT);
writel(len, qup->base + QUP_MX_INPUT_CNT);
}
}
static void qup_i2c_issue_read(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
u32 addr, len, val;
addr = (msg->addr << 1) | 1;
len = (msg->len == QUP_READ_LIMIT) ? 0 : msg->len;
val = ((QUP_TAG_REC | len) << QUP_MSW_SHIFT) | QUP_TAG_START | addr;
writel(val, qup->base + QUP_OUT_FIFO_BASE);
}
static int qup_i2c_read_fifo(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
u32 val = 0;
int idx;
int ret = 0;
for (idx = 0; qup->pos < msg->len; idx++) {
if ((idx & 1) == 0) {
ret = qup_i2c_wait_ready(qup, QUP_IN_NOT_EMPTY,
SET_BIT, 4 * ONE_BYTE);
if (ret)
return ret;
val = readl(qup->base + QUP_IN_FIFO_BASE);
msg->buf[qup->pos++] = val & 0xFF;
} else {
msg->buf[qup->pos++] = val >> QUP_MSW_SHIFT;
}
}
return ret;
}
static int qup_i2c_read_fifo_v2(struct qup_i2c_dev *qup,
struct i2c_msg *msg)
{
u32 val;
int idx, pos = 0, ret = 0, total;
total = qup_i2c_get_data_len(qup);
while (pos < (total + 2)) {
ret = qup_i2c_wait_ready(qup, QUP_IN_NOT_EMPTY,
SET_BIT, 4 * ONE_BYTE);
if (ret) {
dev_err(qup->dev, "timeout for fifo not empty");
return ret;
}
val = readl(qup->base + QUP_IN_FIFO_BASE);
for (idx = 0; idx < 4; idx++, val >>= 8, pos++) {
if (pos < 2)
continue;
if (pos >= (total + 2))
goto out;
msg->buf[qup->pos++] = val & 0xff;
}
}
out:
qup->blk.data_len -= total;
return ret;
}
static int qup_i2c_read_one_v2(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int ret = 0;
qup->msg = msg;
qup->pos = 0;
enable_irq(qup->irq);
qup_i2c_set_blk_data(qup, msg);
qup_i2c_set_read_mode_v2(qup, msg->len);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
do {
ret = qup_i2c_issue_xfer_v2(qup, msg);
if (ret)
goto err;
ret = qup_i2c_wait_for_complete(qup, msg);
if (ret)
goto err;
ret = qup_i2c_read_fifo_v2(qup, msg);
if (ret)
goto err;
qup->blk.pos++;
} while (qup->blk.pos < qup->blk.count);
err:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static int qup_i2c_read_one(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int ret;
qup->msg = msg;
qup->pos = 0;
enable_irq(qup->irq);
qup_i2c_set_read_mode(qup, msg->len);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
ret = qup_i2c_change_state(qup, QUP_PAUSE_STATE);
if (ret)
goto err;
qup_i2c_issue_read(qup, msg);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
do {
ret = qup_i2c_wait_for_complete(qup, msg);
if (ret)
goto err;
ret = qup_i2c_read_fifo(qup, msg);
if (ret)
goto err;
} while (qup->pos < msg->len);
err:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static int qup_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg msgs[],
int num)
{
struct qup_i2c_dev *qup = i2c_get_adapdata(adap);
int ret, idx;
ret = pm_runtime_get_sync(qup->dev);
if (ret < 0)
goto out;
writel(1, qup->base + QUP_SW_RESET);
ret = qup_i2c_poll_state(qup, QUP_RESET_STATE);
if (ret)
goto out;
writel(I2C_MINI_CORE | I2C_N_VAL, qup->base + QUP_CONFIG);
for (idx = 0; idx < num; idx++) {
if (msgs[idx].len == 0) {
ret = -EINVAL;
goto out;
}
if (qup_i2c_poll_state_i2c_master(qup)) {
ret = -EIO;
goto out;
}
if (msgs[idx].flags & I2C_M_RD)
ret = qup_i2c_read_one(qup, &msgs[idx]);
else
ret = qup_i2c_write_one(qup, &msgs[idx]);
if (ret)
break;
ret = qup_i2c_change_state(qup, QUP_RESET_STATE);
if (ret)
break;
}
if (ret == 0)
ret = num;
out:
pm_runtime_mark_last_busy(qup->dev);
pm_runtime_put_autosuspend(qup->dev);
return ret;
}
static int qup_i2c_xfer_v2(struct i2c_adapter *adap,
struct i2c_msg msgs[],
int num)
{
struct qup_i2c_dev *qup = i2c_get_adapdata(adap);
int ret, len, idx = 0, use_dma = 0;
ret = pm_runtime_get_sync(qup->dev);
if (ret < 0)
goto out;
writel(1, qup->base + QUP_SW_RESET);
ret = qup_i2c_poll_state(qup, QUP_RESET_STATE);
if (ret)
goto out;
writel(I2C_MINI_CORE | I2C_N_VAL_V2, qup->base + QUP_CONFIG);
writel(QUP_V2_TAGS_EN, qup->base + QUP_I2C_MASTER_GEN);
if ((qup->is_dma)) {
for (idx = 0; idx < num; idx++) {
if (msgs[idx].len == 0) {
ret = -EINVAL;
goto out;
}
len = (msgs[idx].len > qup->out_fifo_sz) ||
(msgs[idx].len > qup->in_fifo_sz);
if ((!is_vmalloc_addr(msgs[idx].buf)) && len) {
use_dma = 1;
} else {
use_dma = 0;
break;
}
}
}
do {
if (msgs[idx].len == 0) {
ret = -EINVAL;
goto out;
}
if (qup_i2c_poll_state_i2c_master(qup)) {
ret = -EIO;
goto out;
}
qup->is_last = (idx == (num - 1));
if (idx)
qup->config_run = QUP_I2C_MX_CONFIG_DURING_RUN;
else
qup->config_run = 0;
reinit_completion(&qup->xfer);
if (use_dma) {
ret = qup_i2c_bam_xfer(adap, &msgs[idx], num);
} else {
if (msgs[idx].flags & I2C_M_RD)
ret = qup_i2c_read_one_v2(qup, &msgs[idx]);
else
ret = qup_i2c_write_one_v2(qup, &msgs[idx]);
}
} while ((idx++ < (num - 1)) && !use_dma && !ret);
if (!ret)
ret = qup_i2c_change_state(qup, QUP_RESET_STATE);
if (ret == 0)
ret = num;
out:
pm_runtime_mark_last_busy(qup->dev);
pm_runtime_put_autosuspend(qup->dev);
return ret;
}
static u32 qup_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static void qup_i2c_enable_clocks(struct qup_i2c_dev *qup)
{
clk_prepare_enable(qup->clk);
clk_prepare_enable(qup->pclk);
}
static void qup_i2c_disable_clocks(struct qup_i2c_dev *qup)
{
u32 config;
qup_i2c_change_state(qup, QUP_RESET_STATE);
clk_disable_unprepare(qup->clk);
config = readl(qup->base + QUP_CONFIG);
config |= QUP_CLOCK_AUTO_GATE;
writel(config, qup->base + QUP_CONFIG);
clk_disable_unprepare(qup->pclk);
}
static int qup_i2c_probe(struct platform_device *pdev)
{
static const int blk_sizes[] = {4, 16, 32};
struct device_node *node = pdev->dev.of_node;
struct qup_i2c_dev *qup;
unsigned long one_bit_t;
struct resource *res;
u32 io_mode, hw_ver, size;
int ret, fs_div, hs_div;
int src_clk_freq;
u32 clk_freq = 100000;
int blocks;
qup = devm_kzalloc(&pdev->dev, sizeof(*qup), GFP_KERNEL);
if (!qup)
return -ENOMEM;
qup->dev = &pdev->dev;
init_completion(&qup->xfer);
platform_set_drvdata(pdev, qup);
of_property_read_u32(node, "clock-frequency", &clk_freq);
if (of_device_is_compatible(pdev->dev.of_node, "qcom,i2c-qup-v1.1.1")) {
qup->adap.algo = &qup_i2c_algo;
qup->adap.quirks = &qup_i2c_quirks;
} else {
qup->adap.algo = &qup_i2c_algo_v2;
ret = qup_i2c_req_dma(qup);
if (ret == -EPROBE_DEFER)
goto fail_dma;
else if (ret != 0)
goto nodma;
blocks = (MX_BLOCKS << 1) + 1;
qup->btx.sg = devm_kzalloc(&pdev->dev,
sizeof(*qup->btx.sg) * blocks,
GFP_KERNEL);
if (!qup->btx.sg) {
ret = -ENOMEM;
goto fail_dma;
}
sg_init_table(qup->btx.sg, blocks);
qup->brx.sg = devm_kzalloc(&pdev->dev,
sizeof(*qup->brx.sg) * blocks,
GFP_KERNEL);
if (!qup->brx.sg) {
ret = -ENOMEM;
goto fail_dma;
}
sg_init_table(qup->brx.sg, blocks);
size = blocks * 2 + 5;
qup->dpool = dma_pool_create("qup_i2c-dma-pool", &pdev->dev,
size, 4, 0);
qup->start_tag.start = dma_pool_alloc(qup->dpool, GFP_KERNEL,
&qup->start_tag.addr);
if (!qup->start_tag.start) {
ret = -ENOMEM;
goto fail_dma;
}
qup->brx.tag.start = dma_pool_alloc(qup->dpool,
GFP_KERNEL,
&qup->brx.tag.addr);
if (!qup->brx.tag.start) {
ret = -ENOMEM;
goto fail_dma;
}
qup->btx.tag.start = dma_pool_alloc(qup->dpool,
GFP_KERNEL,
&qup->btx.tag.addr);
if (!qup->btx.tag.start) {
ret = -ENOMEM;
goto fail_dma;
}
qup->is_dma = true;
}
nodma:
if (!clk_freq || clk_freq > 400000) {
dev_err(qup->dev, "clock frequency not supported %d\n",
clk_freq);
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
qup->base = devm_ioremap_resource(qup->dev, res);
if (IS_ERR(qup->base))
return PTR_ERR(qup->base);
qup->irq = platform_get_irq(pdev, 0);
if (qup->irq < 0) {
dev_err(qup->dev, "No IRQ defined\n");
return qup->irq;
}
qup->clk = devm_clk_get(qup->dev, "core");
if (IS_ERR(qup->clk)) {
dev_err(qup->dev, "Could not get core clock\n");
return PTR_ERR(qup->clk);
}
qup->pclk = devm_clk_get(qup->dev, "iface");
if (IS_ERR(qup->pclk)) {
dev_err(qup->dev, "Could not get iface clock\n");
return PTR_ERR(qup->pclk);
}
qup_i2c_enable_clocks(qup);
writel(1, qup->base + QUP_SW_RESET);
ret = qup_i2c_poll_state_valid(qup);
if (ret)
goto fail;
ret = devm_request_irq(qup->dev, qup->irq, qup_i2c_interrupt,
IRQF_TRIGGER_HIGH, "i2c_qup", qup);
if (ret) {
dev_err(qup->dev, "Request %d IRQ failed\n", qup->irq);
goto fail;
}
disable_irq(qup->irq);
hw_ver = readl(qup->base + QUP_HW_VERSION);
dev_dbg(qup->dev, "Revision %x\n", hw_ver);
io_mode = readl(qup->base + QUP_IO_MODE);
size = QUP_OUTPUT_BLOCK_SIZE(io_mode);
if (size >= ARRAY_SIZE(blk_sizes)) {
ret = -EIO;
goto fail;
}
qup->out_blk_sz = blk_sizes[size] / 2;
size = QUP_INPUT_BLOCK_SIZE(io_mode);
if (size >= ARRAY_SIZE(blk_sizes)) {
ret = -EIO;
goto fail;
}
qup->in_blk_sz = blk_sizes[size] / 2;
size = QUP_OUTPUT_FIFO_SIZE(io_mode);
qup->out_fifo_sz = qup->out_blk_sz * (2 << size);
size = QUP_INPUT_FIFO_SIZE(io_mode);
qup->in_fifo_sz = qup->in_blk_sz * (2 << size);
src_clk_freq = clk_get_rate(qup->clk);
fs_div = ((src_clk_freq / clk_freq) / 2) - 3;
hs_div = 3;
qup->clk_ctl = (hs_div << 8) | (fs_div & 0xff);
one_bit_t = (USEC_PER_SEC / clk_freq) + 1;
qup->one_byte_t = one_bit_t * 9;
dev_dbg(qup->dev, "IN:block:%d, fifo:%d, OUT:block:%d, fifo:%d\n",
qup->in_blk_sz, qup->in_fifo_sz,
qup->out_blk_sz, qup->out_fifo_sz);
i2c_set_adapdata(&qup->adap, qup);
qup->adap.dev.parent = qup->dev;
qup->adap.dev.of_node = pdev->dev.of_node;
qup->is_last = true;
strlcpy(qup->adap.name, "QUP I2C adapter", sizeof(qup->adap.name));
pm_runtime_set_autosuspend_delay(qup->dev, MSEC_PER_SEC);
pm_runtime_use_autosuspend(qup->dev);
pm_runtime_set_active(qup->dev);
pm_runtime_enable(qup->dev);
ret = i2c_add_adapter(&qup->adap);
if (ret)
goto fail_runtime;
return 0;
fail_runtime:
pm_runtime_disable(qup->dev);
pm_runtime_set_suspended(qup->dev);
fail:
qup_i2c_disable_clocks(qup);
fail_dma:
if (qup->btx.dma)
dma_release_channel(qup->btx.dma);
if (qup->brx.dma)
dma_release_channel(qup->brx.dma);
return ret;
}
static int qup_i2c_remove(struct platform_device *pdev)
{
struct qup_i2c_dev *qup = platform_get_drvdata(pdev);
if (qup->is_dma) {
dma_pool_free(qup->dpool, qup->start_tag.start,
qup->start_tag.addr);
dma_pool_free(qup->dpool, qup->brx.tag.start,
qup->brx.tag.addr);
dma_pool_free(qup->dpool, qup->btx.tag.start,
qup->btx.tag.addr);
dma_pool_destroy(qup->dpool);
dma_release_channel(qup->btx.dma);
dma_release_channel(qup->brx.dma);
}
disable_irq(qup->irq);
qup_i2c_disable_clocks(qup);
i2c_del_adapter(&qup->adap);
pm_runtime_disable(qup->dev);
pm_runtime_set_suspended(qup->dev);
return 0;
}
static int qup_i2c_pm_suspend_runtime(struct device *device)
{
struct qup_i2c_dev *qup = dev_get_drvdata(device);
dev_dbg(device, "pm_runtime: suspending...\n");
qup_i2c_disable_clocks(qup);
return 0;
}
static int qup_i2c_pm_resume_runtime(struct device *device)
{
struct qup_i2c_dev *qup = dev_get_drvdata(device);
dev_dbg(device, "pm_runtime: resuming...\n");
qup_i2c_enable_clocks(qup);
return 0;
}
static int qup_i2c_suspend(struct device *device)
{
qup_i2c_pm_suspend_runtime(device);
return 0;
}
static int qup_i2c_resume(struct device *device)
{
qup_i2c_pm_resume_runtime(device);
pm_runtime_mark_last_busy(device);
pm_request_autosuspend(device);
return 0;
}
