static void cmdbuf_add(struct pt3_i2cbuf *cbuf, enum ctl_cmd cmd)
{
int buf_idx;
if ((cbuf->num_cmds % 2) == 0)
cbuf->tmp = cmd;
else {
cbuf->tmp |= cmd << 4;
buf_idx = cbuf->num_cmds / 2;
if (buf_idx < ARRAY_SIZE(cbuf->data))
cbuf->data[buf_idx] = cbuf->tmp;
}
cbuf->num_cmds++;
}
static void put_end(struct pt3_i2cbuf *cbuf)
{
cmdbuf_add(cbuf, I_END);
if (cbuf->num_cmds % 2)
cmdbuf_add(cbuf, I_END);
}
static void put_start(struct pt3_i2cbuf *cbuf)
{
cmdbuf_add(cbuf, I_DATA_H);
cmdbuf_add(cbuf, I_CLOCK_H);
cmdbuf_add(cbuf, I_DATA_L);
cmdbuf_add(cbuf, I_CLOCK_L);
}
static void put_byte_write(struct pt3_i2cbuf *cbuf, u8 val)
{
u8 mask;
mask = 0x80;
for (mask = 0x80; mask > 0; mask >>= 1)
cmdbuf_add(cbuf, (val & mask) ? I_DATA_H_NOP : I_DATA_L_NOP);
cmdbuf_add(cbuf, I_DATA_H_ACK0);
}
static void put_byte_read(struct pt3_i2cbuf *cbuf, u32 size)
{
int i, j;
for (i = 0; i < size; i++) {
for (j = 0; j < 8; j++)
cmdbuf_add(cbuf, I_DATA_H_READ);
cmdbuf_add(cbuf, (i == size - 1) ? I_DATA_H_NOP : I_DATA_L_NOP);
}
}
static void put_stop(struct pt3_i2cbuf *cbuf)
{
cmdbuf_add(cbuf, I_DATA_L);
cmdbuf_add(cbuf, I_CLOCK_H);
cmdbuf_add(cbuf, I_DATA_H);
}
static void translate(struct pt3_i2cbuf *cbuf, struct i2c_msg *msgs, int num)
{
int i, j;
bool rd;
cbuf->num_cmds = 0;
for (i = 0; i < num; i++) {
rd = !!(msgs[i].flags & I2C_M_RD);
put_start(cbuf);
put_byte_write(cbuf, msgs[i].addr << 1 | rd);
if (rd)
put_byte_read(cbuf, msgs[i].len);
else
for (j = 0; j < msgs[i].len; j++)
put_byte_write(cbuf, msgs[i].buf[j]);
}
if (num > 0) {
put_stop(cbuf);
put_end(cbuf);
}
}
static int wait_i2c_result(struct pt3_board *pt3, u32 *result, int max_wait)
{
int i;
u32 v;
for (i = 0; i < max_wait; i++) {
v = ioread32(pt3->regs[0] + REG_I2C_R);
if (!(v & STAT_SEQ_RUNNING))
break;
usleep_range(500, 750);
}
if (i >= max_wait)
return -EIO;
if (result)
*result = v;
return 0;
}
static int send_i2c_cmd(struct pt3_board *pt3, u32 addr)
{
u32 ret;
if (wait_i2c_result(pt3, NULL, 50)) {
dev_warn(&pt3->pdev->dev, "(%s) prev. transaction stalled\n",
__func__);
return -EIO;
}
iowrite32(PT3_I2C_RUN | addr, pt3->regs[0] + REG_I2C_W);
usleep_range(200, 300);
if (wait_i2c_result(pt3, &ret, 500) || (ret & STAT_SEQ_ERROR)) {
dev_warn(&pt3->pdev->dev, "(%s) failed.\n", __func__);
return -EIO;
}
return 0;
}
int pt3_init_all_demods(struct pt3_board *pt3)
{
ioread32(pt3->regs[0] + REG_I2C_R);
return send_i2c_cmd(pt3, PT3_CMD_ADDR_INIT_DEMOD);
}
int pt3_init_all_mxl301rf(struct pt3_board *pt3)
{
usleep_range(1000, 2000);
return send_i2c_cmd(pt3, PT3_CMD_ADDR_INIT_TUNER);
}
void pt3_i2c_reset(struct pt3_board *pt3)
{
iowrite32(PT3_I2C_RESET, pt3->regs[0] + REG_I2C_W);
}
int
pt3_i2c_master_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct pt3_board *pt3;
struct pt3_i2cbuf *cbuf;
int i;
void __iomem *p;
pt3 = i2c_get_adapdata(adap);
cbuf = pt3->i2c_buf;
for (i = 0; i < num; i++)
if (msgs[i].flags & I2C_M_RECV_LEN) {
dev_warn(&pt3->pdev->dev,
"(%s) I2C_M_RECV_LEN not supported.\n",
__func__);
return -EINVAL;
}
translate(cbuf, msgs, num);
memcpy_toio(pt3->regs[1] + PT3_I2C_BASE + PT3_CMD_ADDR_NORMAL / 2,
cbuf->data, cbuf->num_cmds);
if (send_i2c_cmd(pt3, PT3_CMD_ADDR_NORMAL) < 0)
return -EIO;
p = pt3->regs[1] + PT3_I2C_BASE;
for (i = 0; i < num; i++)
if ((msgs[i].flags & I2C_M_RD) && msgs[i].len > 0) {
memcpy_fromio(msgs[i].buf, p, msgs[i].len);
p += msgs[i].len;
}
return num;
}
u32 pt3_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C;
}
