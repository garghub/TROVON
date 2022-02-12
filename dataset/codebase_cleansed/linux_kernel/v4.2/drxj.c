static u32 frac28(u32 N, u32 D)
{
int i = 0;
u32 Q1 = 0;
u32 R0 = 0;
R0 = (N % D) << 4;
Q1 = N / D;
for (i = 0; i < 7; i++) {
Q1 = (Q1 << 4) | R0 / D;
R0 = (R0 % D) << 4;
}
if ((R0 >> 3) >= D)
Q1++;
return Q1;
}
static u32 log1_times100(u32 x)
{
static const u8 scale = 15;
static const u8 index_width = 5;
static const u32 log2lut[] = {
0,
290941,
573196,
847269,
1113620,
1372674,
1624818,
1870412,
2109788,
2343253,
2571091,
2793569,
3010931,
3223408,
3431216,
3634553,
3833610,
4028562,
4219576,
4406807,
4590402,
4770499,
4947231,
5120719,
5291081,
5458428,
5622864,
5784489,
5943398,
6099680,
6253421,
6404702,
6553600,
};
u8 i = 0;
u32 y = 0;
u32 d = 0;
u32 k = 0;
u32 r = 0;
if (x == 0)
return 0;
if ((x & (((u32) (-1)) << (scale + 1))) == 0) {
for (k = scale; k > 0; k--) {
if (x & (((u32) 1) << scale))
break;
x <<= 1;
}
} else {
for (k = scale; k < 31; k++) {
if ((x & (((u32) (-1)) << (scale + 1))) == 0)
break;
x >>= 1;
}
}
y = k * ((((u32) 1) << scale) * 200);
x &= ((((u32) 1) << scale) - 1);
i = (u8) (x >> (scale - index_width));
d = x & ((((u32) 1) << (scale - index_width)) - 1);
y += log2lut[i] +
((d * (log2lut[i + 1] - log2lut[i])) >> (scale - index_width));
y /= 108853;
r = (y >> 1);
if (y & ((u32)1))
r++;
return r;
}
static u32 frac_times1e6(u32 N, u32 D)
{
u32 remainder = 0;
u32 frac = 0;
frac = (((u32) N) * (1000000 >> 4)) / D;
frac <<= 4;
remainder = (((u32) N) * (1000000 >> 4)) % D;
remainder <<= 4;
frac += remainder / D;
remainder = remainder % D;
if ((remainder * 2) > D)
frac++;
return frac;
}
static
bool is_handled_by_aud_tr_if(u32 addr)
{
bool retval = false;
if ((DRXDAP_FASI_ADDR2BLOCK(addr) == 4) &&
(DRXDAP_FASI_ADDR2BANK(addr) > 1) &&
(DRXDAP_FASI_ADDR2BANK(addr) < 6)) {
retval = true;
}
return retval;
}
int drxbsp_i2c_write_read(struct i2c_device_addr *w_dev_addr,
u16 w_count,
u8 *wData,
struct i2c_device_addr *r_dev_addr,
u16 r_count, u8 *r_data)
{
struct drx39xxj_state *state;
struct i2c_msg msg[2];
unsigned int num_msgs;
if (w_dev_addr == NULL) {
state = r_dev_addr->user_data;
msg[0].addr = r_dev_addr->i2c_addr >> 1;
msg[0].flags = I2C_M_RD;
msg[0].buf = r_data;
msg[0].len = r_count;
num_msgs = 1;
} else if (r_dev_addr == NULL) {
state = w_dev_addr->user_data;
msg[0].addr = w_dev_addr->i2c_addr >> 1;
msg[0].flags = 0;
msg[0].buf = wData;
msg[0].len = w_count;
num_msgs = 1;
} else {
state = w_dev_addr->user_data;
msg[0].addr = w_dev_addr->i2c_addr >> 1;
msg[0].flags = 0;
msg[0].buf = wData;
msg[0].len = w_count;
msg[1].addr = r_dev_addr->i2c_addr >> 1;
msg[1].flags = I2C_M_RD;
msg[1].buf = r_data;
msg[1].len = r_count;
num_msgs = 2;
}
if (state->i2c == NULL) {
pr_err("i2c was zero, aborting\n");
return 0;
}
if (i2c_transfer(state->i2c, msg, num_msgs) != num_msgs) {
pr_warn("drx3933: I2C write/read failed\n");
return -EREMOTEIO;
}
#ifdef DJH_DEBUG
if (w_dev_addr == NULL || r_dev_addr == NULL)
return 0;
state = w_dev_addr->user_data;
if (state->i2c == NULL)
return 0;
msg[0].addr = w_dev_addr->i2c_addr;
msg[0].flags = 0;
msg[0].buf = wData;
msg[0].len = w_count;
msg[1].addr = r_dev_addr->i2c_addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = r_data;
msg[1].len = r_count;
num_msgs = 2;
pr_debug("drx3933 i2c operation addr=%x i2c=%p, wc=%x rc=%x\n",
w_dev_addr->i2c_addr, state->i2c, w_count, r_count);
if (i2c_transfer(state->i2c, msg, 2) != 2) {
pr_warn("drx3933: I2C write/read failed\n");
return -EREMOTEIO;
}
#endif
return 0;
}
static int drxdap_fasi_read_block(struct i2c_device_addr *dev_addr,
u32 addr,
u16 datasize,
u8 *data, u32 flags)
{
u8 buf[4];
u16 bufx;
int rc;
u16 overhead_size = 0;
if (dev_addr == NULL)
return -EINVAL;
overhead_size = (IS_I2C_10BIT(dev_addr->i2c_addr) ? 2 : 1) +
(DRXDAP_FASI_LONG_FORMAT(addr) ? 4 : 2);
if ((DRXDAP_FASI_OFFSET_TOO_LARGE(addr)) ||
((!(DRXDAPFASI_LONG_ADDR_ALLOWED)) &&
DRXDAP_FASI_LONG_FORMAT(addr)) ||
(overhead_size > (DRXDAP_MAX_WCHUNKSIZE)) ||
((datasize != 0) && (data == NULL)) || ((datasize & 1) == 1)) {
return -EINVAL;
}
flags &= (~DRXDAP_FASI_RMW & ~DRXDAP_FASI_MODEFLAGS);
#if DRXDAP_SINGLE_MASTER
flags |= DRXDAP_FASI_SINGLE_MASTER;
#endif
do {
u16 todo = (datasize < DRXDAP_MAX_RCHUNKSIZE ?
datasize : DRXDAP_MAX_RCHUNKSIZE);
bufx = 0;
addr &= ~DRXDAP_FASI_FLAGS;
addr |= flags;
#if ((DRXDAPFASI_LONG_ADDR_ALLOWED == 1) && (DRXDAPFASI_SHORT_ADDR_ALLOWED == 1))
if (DRXDAP_FASI_LONG_FORMAT(addr)) {
#endif
#if (DRXDAPFASI_LONG_ADDR_ALLOWED == 1)
buf[bufx++] = (u8) (((addr << 1) & 0xFF) | 0x01);
buf[bufx++] = (u8) ((addr >> 16) & 0xFF);
buf[bufx++] = (u8) ((addr >> 24) & 0xFF);
buf[bufx++] = (u8) ((addr >> 7) & 0xFF);
#endif
#if ((DRXDAPFASI_LONG_ADDR_ALLOWED == 1) && (DRXDAPFASI_SHORT_ADDR_ALLOWED == 1))
} else {
#endif
#if (DRXDAPFASI_SHORT_ADDR_ALLOWED == 1)
buf[bufx++] = (u8) ((addr << 1) & 0xFF);
buf[bufx++] =
(u8) (((addr >> 16) & 0x0F) |
((addr >> 18) & 0xF0));
#endif
#if ((DRXDAPFASI_LONG_ADDR_ALLOWED == 1) && (DRXDAPFASI_SHORT_ADDR_ALLOWED == 1))
}
#endif
#if DRXDAP_SINGLE_MASTER
rc = drxbsp_i2c_write_read(dev_addr, bufx, buf,
NULL, 0, NULL);
if (rc == 0)
rc = drxbsp_i2c_write_read(NULL, 0, NULL, dev_addr, todo, data);
#else
rc = drxbsp_i2c_write_read(dev_addr, bufx, buf, dev_addr, todo,
data);
#endif
data += todo;
addr += (todo >> 1);
datasize -= todo;
} while (datasize && rc == 0);
return rc;
}
static int drxdap_fasi_read_reg16(struct i2c_device_addr *dev_addr,
u32 addr,
u16 *data, u32 flags)
{
u8 buf[sizeof(*data)];
int rc;
if (!data)
return -EINVAL;
rc = drxdap_fasi_read_block(dev_addr, addr, sizeof(*data), buf, flags);
*data = buf[0] + (((u16) buf[1]) << 8);
return rc;
}
static int drxdap_fasi_read_reg32(struct i2c_device_addr *dev_addr,
u32 addr,
u32 *data, u32 flags)
{
u8 buf[sizeof(*data)];
int rc;
if (!data)
return -EINVAL;
rc = drxdap_fasi_read_block(dev_addr, addr, sizeof(*data), buf, flags);
*data = (((u32) buf[0]) << 0) +
(((u32) buf[1]) << 8) +
(((u32) buf[2]) << 16) + (((u32) buf[3]) << 24);
return rc;
}
static int drxdap_fasi_write_block(struct i2c_device_addr *dev_addr,
u32 addr,
u16 datasize,
u8 *data, u32 flags)
{
u8 buf[DRXDAP_MAX_WCHUNKSIZE];
int st = -EIO;
int first_err = 0;
u16 overhead_size = 0;
u16 block_size = 0;
if (dev_addr == NULL)
return -EINVAL;
overhead_size = (IS_I2C_10BIT(dev_addr->i2c_addr) ? 2 : 1) +
(DRXDAP_FASI_LONG_FORMAT(addr) ? 4 : 2);
if ((DRXDAP_FASI_OFFSET_TOO_LARGE(addr)) ||
((!(DRXDAPFASI_LONG_ADDR_ALLOWED)) &&
DRXDAP_FASI_LONG_FORMAT(addr)) ||
(overhead_size > (DRXDAP_MAX_WCHUNKSIZE)) ||
((datasize != 0) && (data == NULL)) || ((datasize & 1) == 1))
return -EINVAL;
flags &= DRXDAP_FASI_FLAGS;
flags &= ~DRXDAP_FASI_MODEFLAGS;
#if DRXDAP_SINGLE_MASTER
flags |= DRXDAP_FASI_SINGLE_MASTER;
#endif
block_size = ((DRXDAP_MAX_WCHUNKSIZE) - overhead_size) & ~1;
do {
u16 todo = 0;
u16 bufx = 0;
addr &= ~DRXDAP_FASI_FLAGS;
addr |= flags;
#if (((DRXDAPFASI_LONG_ADDR_ALLOWED) == 1) && ((DRXDAPFASI_SHORT_ADDR_ALLOWED) == 1))
if (DRXDAP_FASI_LONG_FORMAT(addr)) {
#endif
#if ((DRXDAPFASI_LONG_ADDR_ALLOWED) == 1)
buf[bufx++] = (u8) (((addr << 1) & 0xFF) | 0x01);
buf[bufx++] = (u8) ((addr >> 16) & 0xFF);
buf[bufx++] = (u8) ((addr >> 24) & 0xFF);
buf[bufx++] = (u8) ((addr >> 7) & 0xFF);
#endif
#if (((DRXDAPFASI_LONG_ADDR_ALLOWED) == 1) && ((DRXDAPFASI_SHORT_ADDR_ALLOWED) == 1))
} else {
#endif
#if ((DRXDAPFASI_SHORT_ADDR_ALLOWED) == 1)
buf[bufx++] = (u8) ((addr << 1) & 0xFF);
buf[bufx++] =
(u8) (((addr >> 16) & 0x0F) |
((addr >> 18) & 0xF0));
#endif
#if (((DRXDAPFASI_LONG_ADDR_ALLOWED) == 1) && ((DRXDAPFASI_SHORT_ADDR_ALLOWED) == 1))
}
#endif
todo = (block_size < datasize ? block_size : datasize);
if (todo == 0) {
u16 overhead_size_i2c_addr = 0;
u16 data_block_size = 0;
overhead_size_i2c_addr =
(IS_I2C_10BIT(dev_addr->i2c_addr) ? 2 : 1);
data_block_size =
(DRXDAP_MAX_WCHUNKSIZE - overhead_size_i2c_addr) & ~1;
st = drxbsp_i2c_write_read(dev_addr,
(u16) (bufx),
buf,
(struct i2c_device_addr *)(NULL),
0, (u8 *)(NULL));
if ((st != 0) && (first_err == 0)) {
first_err = st;
}
bufx = 0;
todo =
(data_block_size <
datasize ? data_block_size : datasize);
}
memcpy(&buf[bufx], data, todo);
st = drxbsp_i2c_write_read(dev_addr,
(u16) (bufx + todo),
buf,
(struct i2c_device_addr *)(NULL),
0, (u8 *)(NULL));
if ((st != 0) && (first_err == 0)) {
first_err = st;
}
datasize -= todo;
data += todo;
addr += (todo >> 1);
} while (datasize);
return first_err;
}
static int drxdap_fasi_write_reg16(struct i2c_device_addr *dev_addr,
u32 addr,
u16 data, u32 flags)
{
u8 buf[sizeof(data)];
buf[0] = (u8) ((data >> 0) & 0xFF);
buf[1] = (u8) ((data >> 8) & 0xFF);
return drxdap_fasi_write_block(dev_addr, addr, sizeof(data), buf, flags);
}
static int drxdap_fasi_read_modify_write_reg16(struct i2c_device_addr *dev_addr,
u32 waddr,
u32 raddr,
u16 wdata, u16 *rdata)
{
int rc = -EIO;
#if (DRXDAPFASI_LONG_ADDR_ALLOWED == 1)
if (rdata == NULL)
return -EINVAL;
rc = drxdap_fasi_write_reg16(dev_addr, waddr, wdata, DRXDAP_FASI_RMW);
if (rc == 0)
rc = drxdap_fasi_read_reg16(dev_addr, raddr, rdata, 0);
#endif
return rc;
}
static int drxdap_fasi_write_reg32(struct i2c_device_addr *dev_addr,
u32 addr,
u32 data, u32 flags)
{
u8 buf[sizeof(data)];
buf[0] = (u8) ((data >> 0) & 0xFF);
buf[1] = (u8) ((data >> 8) & 0xFF);
buf[2] = (u8) ((data >> 16) & 0xFF);
buf[3] = (u8) ((data >> 24) & 0xFF);
return drxdap_fasi_write_block(dev_addr, addr, sizeof(data), buf, flags);
}
static int drxj_dap_rm_write_reg16short(struct i2c_device_addr *dev_addr,
u32 waddr,
u32 raddr,
u16 wdata, u16 *rdata)
{
int rc;
if (rdata == NULL)
return -EINVAL;
rc = drxdap_fasi_write_reg16(dev_addr,
SIO_HI_RA_RAM_S0_FLG_ACC__A,
SIO_HI_RA_RAM_S0_FLG_ACC_S0_RWM__M,
0x0000);
if (rc == 0) {
rc = drxdap_fasi_write_reg16(dev_addr, waddr, wdata,
0x0000);
}
if (rc == 0) {
rc = drxdap_fasi_read_reg16(dev_addr, raddr, rdata,
0x0000);
}
if (rc == 0) {
rc = drxdap_fasi_write_reg16(dev_addr,
SIO_HI_RA_RAM_S0_FLG_ACC__A,
0, 0x0000);
}
return rc;
}
static int drxj_dap_read_modify_write_reg16(struct i2c_device_addr *dev_addr,
u32 waddr,
u32 raddr,
u16 wdata, u16 *rdata)
{
#if (DRXDAPFASI_LONG_ADDR_ALLOWED == 1)
return drxdap_fasi_read_modify_write_reg16(dev_addr,
waddr,
raddr, wdata, rdata);
#else
return drxj_dap_rm_write_reg16short(dev_addr, waddr, raddr, wdata, rdata);
#endif
}
static int drxj_dap_read_aud_reg16(struct i2c_device_addr *dev_addr,
u32 addr, u16 *data)
{
u32 start_timer = 0;
u32 current_timer = 0;
u32 delta_timer = 0;
u16 tr_status = 0;
int stat = -EIO;
if (DRXDAP_FASI_ADDR2BANK(addr) == 3) {
stat = -EINVAL;
} else {
const u32 write_bit = ((dr_xaddr_t) 1) << 16;
addr &= (~write_bit);
start_timer = jiffies_to_msecs(jiffies);
do {
stat = drxj_dap_read_modify_write_reg16(dev_addr,
addr,
SIO_HI_RA_RAM_S0_RMWBUF__A,
0x0000, &tr_status);
if (stat != 0)
break;
current_timer = jiffies_to_msecs(jiffies);
delta_timer = current_timer - start_timer;
if (delta_timer > DRXJ_DAP_AUDTRIF_TIMEOUT) {
stat = -EIO;
break;
}
} while (((tr_status & AUD_TOP_TR_CTR_FIFO_LOCK__M) ==
AUD_TOP_TR_CTR_FIFO_LOCK_LOCKED) ||
((tr_status & AUD_TOP_TR_CTR_FIFO_FULL__M) ==
AUD_TOP_TR_CTR_FIFO_FULL_FULL));
}
if (stat == 0) {
start_timer = jiffies_to_msecs(jiffies);
while ((tr_status & AUD_TOP_TR_CTR_FIFO_RD_RDY__M) !=
AUD_TOP_TR_CTR_FIFO_RD_RDY_READY) {
stat = drxj_dap_read_reg16(dev_addr,
AUD_TOP_TR_CTR__A,
&tr_status, 0x0000);
if (stat != 0)
break;
current_timer = jiffies_to_msecs(jiffies);
delta_timer = current_timer - start_timer;
if (delta_timer > DRXJ_DAP_AUDTRIF_TIMEOUT) {
stat = -EIO;
break;
}
}
}
if (stat == 0)
stat = drxj_dap_read_modify_write_reg16(dev_addr,
AUD_TOP_TR_RD_REG__A,
SIO_HI_RA_RAM_S0_RMWBUF__A,
0x0000, data);
return stat;
}
static int drxj_dap_read_reg16(struct i2c_device_addr *dev_addr,
u32 addr,
u16 *data, u32 flags)
{
int stat = -EIO;
if ((dev_addr == NULL) || (data == NULL))
return -EINVAL;
if (is_handled_by_aud_tr_if(addr))
stat = drxj_dap_read_aud_reg16(dev_addr, addr, data);
else
stat = drxdap_fasi_read_reg16(dev_addr, addr, data, flags);
return stat;
}
static int drxj_dap_write_aud_reg16(struct i2c_device_addr *dev_addr,
u32 addr, u16 data)
{
int stat = -EIO;
if (DRXDAP_FASI_ADDR2BANK(addr) == 2) {
stat = -EINVAL;
} else {
u32 start_timer = 0;
u32 current_timer = 0;
u32 delta_timer = 0;
u16 tr_status = 0;
const u32 write_bit = ((dr_xaddr_t) 1) << 16;
addr |= write_bit;
start_timer = jiffies_to_msecs(jiffies);
do {
stat = drxj_dap_read_modify_write_reg16(dev_addr,
addr,
SIO_HI_RA_RAM_S0_RMWBUF__A,
data, &tr_status);
if (stat != 0)
break;
current_timer = jiffies_to_msecs(jiffies);
delta_timer = current_timer - start_timer;
if (delta_timer > DRXJ_DAP_AUDTRIF_TIMEOUT) {
stat = -EIO;
break;
}
} while (((tr_status & AUD_TOP_TR_CTR_FIFO_LOCK__M) ==
AUD_TOP_TR_CTR_FIFO_LOCK_LOCKED) ||
((tr_status & AUD_TOP_TR_CTR_FIFO_FULL__M) ==
AUD_TOP_TR_CTR_FIFO_FULL_FULL));
}
return stat;
}
static int drxj_dap_write_reg16(struct i2c_device_addr *dev_addr,
u32 addr,
u16 data, u32 flags)
{
int stat = -EIO;
if (dev_addr == NULL)
return -EINVAL;
if (is_handled_by_aud_tr_if(addr))
stat = drxj_dap_write_aud_reg16(dev_addr, addr, data);
else
stat = drxdap_fasi_write_reg16(dev_addr,
addr, data, flags);
return stat;
}
static
int drxj_dap_atomic_read_write_block(struct i2c_device_addr *dev_addr,
u32 addr,
u16 datasize,
u8 *data, bool read_flag)
{
struct drxj_hi_cmd hi_cmd;
int rc;
u16 word;
u16 dummy = 0;
u16 i = 0;
if (!data || !dev_addr || ((datasize % 2)) || ((datasize / 2) > 8))
return -EINVAL;
hi_cmd.cmd = SIO_HI_RA_RAM_CMD_ATOMIC_COPY;
hi_cmd.param1 =
(u16) ((DRXDAP_FASI_ADDR2BLOCK(DRXJ_HI_ATOMIC_BUF_START) << 6) +
DRXDAP_FASI_ADDR2BANK(DRXJ_HI_ATOMIC_BUF_START));
hi_cmd.param2 =
(u16) DRXDAP_FASI_ADDR2OFFSET(DRXJ_HI_ATOMIC_BUF_START);
hi_cmd.param3 = (u16) ((datasize / 2) - 1);
if (!read_flag)
hi_cmd.param3 |= DRXJ_HI_ATOMIC_WRITE;
else
hi_cmd.param3 |= DRXJ_HI_ATOMIC_READ;
hi_cmd.param4 = (u16) ((DRXDAP_FASI_ADDR2BLOCK(addr) << 6) +
DRXDAP_FASI_ADDR2BANK(addr));
hi_cmd.param5 = (u16) DRXDAP_FASI_ADDR2OFFSET(addr);
if (!read_flag) {
for (i = 0; i < (datasize / 2); i++) {
word = ((u16) data[2 * i]);
word += (((u16) data[(2 * i) + 1]) << 8);
drxj_dap_write_reg16(dev_addr,
(DRXJ_HI_ATOMIC_BUF_START + i),
word, 0);
}
}
rc = hi_command(dev_addr, &hi_cmd, &dummy);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (read_flag) {
for (i = 0; i < (datasize / 2); i++) {
drxj_dap_read_reg16(dev_addr,
(DRXJ_HI_ATOMIC_BUF_START + i),
&word, 0);
data[2 * i] = (u8) (word & 0xFF);
data[(2 * i) + 1] = (u8) (word >> 8);
}
}
return 0;
rw_error:
return rc;
}
static
int drxj_dap_atomic_read_reg32(struct i2c_device_addr *dev_addr,
u32 addr,
u32 *data, u32 flags)
{
u8 buf[sizeof(*data)] = { 0 };
int rc = -EIO;
u32 word = 0;
if (!data)
return -EINVAL;
rc = drxj_dap_atomic_read_write_block(dev_addr, addr,
sizeof(*data), buf, true);
if (rc < 0)
return 0;
word = (u32) buf[3];
word <<= 8;
word |= (u32) buf[2];
word <<= 8;
word |= (u32) buf[1];
word <<= 8;
word |= (u32) buf[0];
*data = word;
return rc;
}
static int hi_cfg_command(const struct drx_demod_instance *demod)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
struct drxj_hi_cmd hi_cmd;
u16 result = 0;
int rc;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
hi_cmd.cmd = SIO_HI_RA_RAM_CMD_CONFIG;
hi_cmd.param1 = SIO_HI_RA_RAM_PAR_1_PAR1_SEC_KEY;
hi_cmd.param2 = ext_attr->hi_cfg_timing_div;
hi_cmd.param3 = ext_attr->hi_cfg_bridge_delay;
hi_cmd.param4 = ext_attr->hi_cfg_wake_up_key;
hi_cmd.param5 = ext_attr->hi_cfg_ctrl;
hi_cmd.param6 = ext_attr->hi_cfg_transmit;
rc = hi_command(demod->my_i2c_dev_addr, &hi_cmd, &result);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->hi_cfg_ctrl &= (~(SIO_HI_RA_RAM_PAR_5_CFG_SLEEP_ZZZ));
return 0;
rw_error:
return rc;
}
static int
hi_command(struct i2c_device_addr *dev_addr, const struct drxj_hi_cmd *cmd, u16 *result)
{
u16 wait_cmd = 0;
u16 nr_retries = 0;
bool powerdown_cmd = false;
int rc;
switch (cmd->cmd) {
case SIO_HI_RA_RAM_CMD_CONFIG:
case SIO_HI_RA_RAM_CMD_ATOMIC_COPY:
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_PAR_6__A, cmd->param6, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_PAR_5__A, cmd->param5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_PAR_4__A, cmd->param4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_PAR_3__A, cmd->param3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case SIO_HI_RA_RAM_CMD_BRDCTRL:
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_PAR_2__A, cmd->param2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_PAR_1__A, cmd->param1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case SIO_HI_RA_RAM_CMD_NULL:
break;
default:
return -EINVAL;
break;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_HI_RA_RAM_CMD__A, cmd->cmd, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if ((cmd->cmd) == SIO_HI_RA_RAM_CMD_RESET)
msleep(1);
powerdown_cmd = (bool) ((cmd->cmd == SIO_HI_RA_RAM_CMD_CONFIG) &&
(((cmd->
param5) & SIO_HI_RA_RAM_PAR_5_CFG_SLEEP__M)
== SIO_HI_RA_RAM_PAR_5_CFG_SLEEP_ZZZ));
if (!powerdown_cmd) {
do {
nr_retries++;
if (nr_retries > DRXJ_MAX_RETRIES) {
pr_err("timeout\n");
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, SIO_HI_RA_RAM_CMD__A, &wait_cmd, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} while (wait_cmd != 0);
rc = drxj_dap_read_reg16(dev_addr, SIO_HI_RA_RAM_RES__A, result, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
return 0;
rw_error:
return rc;
}
static int init_hi(const struct drx_demod_instance *demod)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
struct drx_common_attr *common_attr = (struct drx_common_attr *) (NULL);
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
int rc;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
dev_addr = demod->my_i2c_dev_addr;
rc = drxj_dap_write_reg16(dev_addr, 0x4301D7, 0x801, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->hi_cfg_timing_div =
(u16) ((common_attr->sys_clock_freq / 1000) * HI_I2C_DELAY) / 1000;
if ((ext_attr->hi_cfg_timing_div) > SIO_HI_RA_RAM_PAR_2_CFG_DIV__M)
ext_attr->hi_cfg_timing_div = SIO_HI_RA_RAM_PAR_2_CFG_DIV__M;
ext_attr->hi_cfg_bridge_delay =
(u16) ((common_attr->osc_clock_freq / 1000) * HI_I2C_BRIDGE_DELAY) /
1000;
if ((ext_attr->hi_cfg_bridge_delay) > SIO_HI_RA_RAM_PAR_3_CFG_DBL_SDA__M)
ext_attr->hi_cfg_bridge_delay = SIO_HI_RA_RAM_PAR_3_CFG_DBL_SDA__M;
ext_attr->hi_cfg_bridge_delay += ((ext_attr->hi_cfg_bridge_delay) <<
SIO_HI_RA_RAM_PAR_3_CFG_DBL_SCL__B);
ext_attr->hi_cfg_wake_up_key = DRXJ_WAKE_UP_KEY;
ext_attr->hi_cfg_ctrl = (SIO_HI_RA_RAM_PAR_5_CFG_SLV0_SLAVE);
ext_attr->hi_cfg_transmit = SIO_HI_RA_RAM_PAR_6__PRE;
rc = hi_cfg_command(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int get_device_capabilities(struct drx_demod_instance *demod)
{
struct drx_common_attr *common_attr = (struct drx_common_attr *) (NULL);
struct drxj_data *ext_attr = (struct drxj_data *) NULL;
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
u16 sio_pdr_ohw_cfg = 0;
u32 sio_top_jtagid_lo = 0;
u16 bid = 0;
int rc;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
dev_addr = demod->my_i2c_dev_addr;
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, SIO_PDR_OHW_CFG__A, &sio_pdr_ohw_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
switch ((sio_pdr_ohw_cfg & SIO_PDR_OHW_CFG_FREF_SEL__M)) {
case 0:
break;
case 1:
common_attr->osc_clock_freq = 27000;
break;
case 2:
common_attr->osc_clock_freq = 20250;
break;
case 3:
common_attr->osc_clock_freq = 4000;
break;
default:
return -EIO;
}
rc = drxdap_fasi_read_reg32(dev_addr, SIO_TOP_JTAGID_LO__A, &sio_top_jtagid_lo, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->mfx = (u8) ((sio_top_jtagid_lo >> 29) & 0xF);
switch ((sio_top_jtagid_lo >> 12) & 0xFF) {
case 0x31:
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, SIO_PDR_UIO_IN_HI__A, &bid, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
bid = (bid >> 10) & 0xf;
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->has_lna = true;
ext_attr->has_ntsc = false;
ext_attr->has_btsc = false;
ext_attr->has_oob = false;
ext_attr->has_smatx = true;
ext_attr->has_smarx = false;
ext_attr->has_gpio = false;
ext_attr->has_irqn = false;
break;
case 0x33:
ext_attr->has_lna = false;
ext_attr->has_ntsc = false;
ext_attr->has_btsc = false;
ext_attr->has_oob = false;
ext_attr->has_smatx = true;
ext_attr->has_smarx = false;
ext_attr->has_gpio = false;
ext_attr->has_irqn = false;
break;
case 0x45:
ext_attr->has_lna = true;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = false;
ext_attr->has_oob = false;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = false;
break;
case 0x46:
ext_attr->has_lna = false;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = false;
ext_attr->has_oob = false;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = false;
break;
case 0x41:
ext_attr->has_lna = true;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = true;
ext_attr->has_oob = false;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = false;
break;
case 0x43:
ext_attr->has_lna = false;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = true;
ext_attr->has_oob = false;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = false;
break;
case 0x32:
ext_attr->has_lna = true;
ext_attr->has_ntsc = false;
ext_attr->has_btsc = false;
ext_attr->has_oob = true;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = true;
break;
case 0x34:
ext_attr->has_lna = false;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = true;
ext_attr->has_oob = true;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = true;
break;
case 0x42:
ext_attr->has_lna = true;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = true;
ext_attr->has_oob = true;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = true;
break;
case 0x44:
ext_attr->has_lna = false;
ext_attr->has_ntsc = true;
ext_attr->has_btsc = true;
ext_attr->has_oob = true;
ext_attr->has_smatx = true;
ext_attr->has_smarx = true;
ext_attr->has_gpio = true;
ext_attr->has_irqn = true;
break;
default:
return -EIO;
break;
}
return 0;
rw_error:
return rc;
}
static int power_up_device(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
u8 data = 0;
u16 retry_count = 0;
struct i2c_device_addr wake_up_addr;
dev_addr = demod->my_i2c_dev_addr;
wake_up_addr.i2c_addr = DRXJ_WAKE_UP_KEY;
wake_up_addr.i2c_dev_id = dev_addr->i2c_dev_id;
wake_up_addr.user_data = dev_addr->user_data;
do {
data = 0;
drxbsp_i2c_write_read(&wake_up_addr, 1, &data,
(struct i2c_device_addr *)(NULL), 0,
(u8 *)(NULL));
msleep(10);
retry_count++;
} while ((drxbsp_i2c_write_read
((struct i2c_device_addr *) (NULL), 0, (u8 *)(NULL), dev_addr, 1,
&data)
!= 0) && (retry_count < DRXJ_MAX_RETRIES_POWERUP));
msleep(10);
if (retry_count == DRXJ_MAX_RETRIES_POWERUP)
return -EIO;
return 0;
}
static int
ctrl_set_cfg_mpeg_output(struct drx_demod_instance *demod, struct drx_cfg_mpeg_output *cfg_data)
{
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
struct drx_common_attr *common_attr = (struct drx_common_attr *) (NULL);
int rc;
u16 fec_oc_reg_mode = 0;
u16 fec_oc_reg_ipr_mode = 0;
u16 fec_oc_reg_ipr_invert = 0;
u32 max_bit_rate = 0;
u32 rcn_rate = 0;
u32 nr_bits = 0;
u16 sio_pdr_md_cfg = 0;
u16 invert_data_mask =
FEC_OC_IPR_INVERT_MD7__M | FEC_OC_IPR_INVERT_MD6__M |
FEC_OC_IPR_INVERT_MD5__M | FEC_OC_IPR_INVERT_MD4__M |
FEC_OC_IPR_INVERT_MD3__M | FEC_OC_IPR_INVERT_MD2__M |
FEC_OC_IPR_INVERT_MD1__M | FEC_OC_IPR_INVERT_MD0__M;
if ((demod == NULL) || (cfg_data == NULL))
return -EINVAL;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
if (cfg_data->enable_mpeg_output == true) {
switch (ext_attr->standard) {
case DRX_STANDARD_8VSB:
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
break;
default:
return 0;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_OCR_INVERT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
switch (ext_attr->standard) {
case DRX_STANDARD_8VSB:
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_FCT_USAGE__A, 7, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_TMD_CTL_UPD_RATE__A, 10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_TMD_INT_UPD_RATE__A, 10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_AVR_PARM_A__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_AVR_PARM_B__A, 7, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_RCN_GAIN__A, 10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_LWM__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_HWM__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
switch (ext_attr->constellation) {
case DRX_CONSTELLATION_QAM256:
nr_bits = 8;
break;
case DRX_CONSTELLATION_QAM128:
nr_bits = 7;
break;
case DRX_CONSTELLATION_QAM64:
nr_bits = 6;
break;
case DRX_CONSTELLATION_QAM32:
nr_bits = 5;
break;
case DRX_CONSTELLATION_QAM16:
nr_bits = 4;
break;
default:
return -EIO;
}
max_bit_rate =
(ext_attr->curr_symbol_rate / 8) * nr_bits * 188;
case DRX_STANDARD_ITU_B:
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_FCT_USAGE__A, FEC_OC_FCT_USAGE__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_TMD_CTL_UPD_RATE__A, FEC_OC_TMD_CTL_UPD_RATE__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_TMD_INT_UPD_RATE__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_AVR_PARM_A__A, FEC_OC_AVR_PARM_A__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_AVR_PARM_B__A, FEC_OC_AVR_PARM_B__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (cfg_data->static_clk == true) {
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_RCN_GAIN__A, 0xD, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_RCN_GAIN__A, FEC_OC_RCN_GAIN__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_LWM__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_HWM__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
break;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_MODE__A, &fec_oc_reg_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_IPR_MODE__A, &fec_oc_reg_ipr_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (cfg_data->insert_rs_byte == true) {
fec_oc_reg_mode |= FEC_OC_MODE_PARITY__M;
fec_oc_reg_ipr_mode |= FEC_OC_IPR_MODE_MVAL_DIS_PAR__M;
switch (ext_attr->standard) {
case DRX_STANDARD_8VSB:
rcn_rate = 0x004854D3;
break;
case DRX_STANDARD_ITU_B:
fec_oc_reg_mode |= FEC_OC_MODE_TRANSPARENT__M;
switch (ext_attr->constellation) {
case DRX_CONSTELLATION_QAM256:
rcn_rate = 0x008945E7;
break;
case DRX_CONSTELLATION_QAM64:
rcn_rate = 0x005F64D4;
break;
default:
return -EIO;
}
break;
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
rcn_rate =
(frac28
(max_bit_rate,
(u32) (common_attr->sys_clock_freq / 8))) /
188;
break;
default:
return -EIO;
}
} else {
fec_oc_reg_mode &= (~FEC_OC_MODE_PARITY__M);
fec_oc_reg_ipr_mode &= (~FEC_OC_IPR_MODE_MVAL_DIS_PAR__M);
switch (ext_attr->standard) {
case DRX_STANDARD_8VSB:
rcn_rate = 0x0041605C;
break;
case DRX_STANDARD_ITU_B:
fec_oc_reg_mode &= (~FEC_OC_MODE_TRANSPARENT__M);
switch (ext_attr->constellation) {
case DRX_CONSTELLATION_QAM256:
rcn_rate = 0x0082D6A0;
break;
case DRX_CONSTELLATION_QAM64:
rcn_rate = 0x005AEC1A;
break;
default:
return -EIO;
}
break;
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
rcn_rate =
(frac28
(max_bit_rate,
(u32) (common_attr->sys_clock_freq / 8))) /
204;
break;
default:
return -EIO;
}
}
if (cfg_data->enable_parallel == true) {
fec_oc_reg_ipr_mode &= (~(FEC_OC_IPR_MODE_SERIAL__M));
} else {
fec_oc_reg_ipr_mode |= FEC_OC_IPR_MODE_SERIAL__M;
}
if (cfg_data->invert_data == true)
fec_oc_reg_ipr_invert |= invert_data_mask;
else
fec_oc_reg_ipr_invert &= (~(invert_data_mask));
if (cfg_data->invert_err == true)
fec_oc_reg_ipr_invert |= FEC_OC_IPR_INVERT_MERR__M;
else
fec_oc_reg_ipr_invert &= (~(FEC_OC_IPR_INVERT_MERR__M));
if (cfg_data->invert_str == true)
fec_oc_reg_ipr_invert |= FEC_OC_IPR_INVERT_MSTRT__M;
else
fec_oc_reg_ipr_invert &= (~(FEC_OC_IPR_INVERT_MSTRT__M));
if (cfg_data->invert_val == true)
fec_oc_reg_ipr_invert |= FEC_OC_IPR_INVERT_MVAL__M;
else
fec_oc_reg_ipr_invert &= (~(FEC_OC_IPR_INVERT_MVAL__M));
if (cfg_data->invert_clk == true)
fec_oc_reg_ipr_invert |= FEC_OC_IPR_INVERT_MCLK__M;
else
fec_oc_reg_ipr_invert &= (~(FEC_OC_IPR_INVERT_MCLK__M));
if (cfg_data->static_clk == true) {
u32 dto_rate = 0;
u32 bit_rate = 0;
u16 fec_oc_dto_burst_len = 0;
u16 fec_oc_dto_period = 0;
fec_oc_dto_burst_len = FEC_OC_DTO_BURST_LEN__PRE;
switch (ext_attr->standard) {
case DRX_STANDARD_8VSB:
fec_oc_dto_period = 4;
if (cfg_data->insert_rs_byte == true)
fec_oc_dto_burst_len = 208;
break;
case DRX_STANDARD_ITU_A:
{
u32 symbol_rate_th = 6400000;
if (cfg_data->insert_rs_byte == true) {
fec_oc_dto_burst_len = 204;
symbol_rate_th = 5900000;
}
if (ext_attr->curr_symbol_rate >=
symbol_rate_th) {
fec_oc_dto_period = 0;
} else {
fec_oc_dto_period = 1;
}
}
break;
case DRX_STANDARD_ITU_B:
fec_oc_dto_period = 1;
if (cfg_data->insert_rs_byte == true)
fec_oc_dto_burst_len = 128;
break;
case DRX_STANDARD_ITU_C:
fec_oc_dto_period = 1;
if (cfg_data->insert_rs_byte == true)
fec_oc_dto_burst_len = 204;
break;
default:
return -EIO;
}
bit_rate =
common_attr->sys_clock_freq * 1000 / (fec_oc_dto_period +
2);
dto_rate =
frac28(bit_rate, common_attr->sys_clock_freq * 1000);
dto_rate >>= 3;
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DTO_RATE_HI__A, (u16)((dto_rate >> 16) & FEC_OC_DTO_RATE_HI__M), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DTO_RATE_LO__A, (u16)(dto_rate & FEC_OC_DTO_RATE_LO_RATE_LO__M), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DTO_MODE__A, FEC_OC_DTO_MODE_DYNAMIC__M | FEC_OC_DTO_MODE_OFFSET_ENABLE__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_FCT_MODE__A, FEC_OC_FCT_MODE_RAT_ENA__M | FEC_OC_FCT_MODE_VIRT_ENA__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DTO_BURST_LEN__A, fec_oc_dto_burst_len, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (ext_attr->mpeg_output_clock_rate != DRXJ_MPEGOUTPUT_CLOCK_RATE_AUTO)
fec_oc_dto_period = ext_attr->mpeg_output_clock_rate - 1;
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DTO_PERIOD__A, fec_oc_dto_period, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DTO_MODE__A, FEC_OC_DTO_MODE_DYNAMIC__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_FCT_MODE__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxdap_fasi_write_reg32(dev_addr, FEC_OC_RCN_CTL_RATE_LO__A, rcn_rate, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_MODE__A, fec_oc_reg_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_IPR_MODE__A, fec_oc_reg_ipr_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_IPR_INVERT__A, fec_oc_reg_ipr_invert, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, 0xFABA, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MSTRT_CFG__A, 0x0013, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MERR_CFG__A, 0x0013, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MCLK_CFG__A, MPEG_OUTPUT_CLK_DRIVE_STRENGTH << SIO_PDR_MCLK_CFG_DRIVE__B | 0x03 << SIO_PDR_MCLK_CFG_MODE__B, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MVAL_CFG__A, 0x0013, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
sio_pdr_md_cfg =
MPEG_SERIAL_OUTPUT_PIN_DRIVE_STRENGTH <<
SIO_PDR_MD0_CFG_DRIVE__B | 0x03 << SIO_PDR_MD0_CFG_MODE__B;
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD0_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (cfg_data->enable_parallel == true) {
sio_pdr_md_cfg =
MPEG_PARALLEL_OUTPUT_PIN_DRIVE_STRENGTH <<
SIO_PDR_MD0_CFG_DRIVE__B | 0x03 <<
SIO_PDR_MD0_CFG_MODE__B;
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD0_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD1_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD2_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD3_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD4_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD5_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD6_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD7_CFG__A, sio_pdr_md_cfg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD1_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD2_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD3_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD4_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD5_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD6_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD7_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MON_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, 0xFABA, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MSTRT_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MERR_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MCLK_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MVAL_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD0_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD1_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD2_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD3_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD4_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD5_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD6_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MD7_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_MON_CFG__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
common_attr->mpeg_cfg.enable_mpeg_output = cfg_data->enable_mpeg_output;
return 0;
rw_error:
return rc;
}
static int set_mpegtei_handling(struct drx_demod_instance *demod)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
int rc;
u16 fec_oc_dpr_mode = 0;
u16 fec_oc_snc_mode = 0;
u16 fec_oc_ems_mode = 0;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_DPR_MODE__A, &fec_oc_dpr_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_SNC_MODE__A, &fec_oc_snc_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_EMS_MODE__A, &fec_oc_ems_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
fec_oc_dpr_mode &= (~FEC_OC_DPR_MODE_ERR_DISABLE__M);
fec_oc_snc_mode &= (~(FEC_OC_SNC_MODE_ERROR_CTL__M |
FEC_OC_SNC_MODE_CORR_DISABLE__M));
fec_oc_ems_mode &= (~FEC_OC_EMS_MODE_MODE__M);
if (ext_attr->disable_te_ihandling) {
fec_oc_dpr_mode |= FEC_OC_DPR_MODE_ERR_DISABLE__M;
fec_oc_snc_mode |= FEC_OC_SNC_MODE_CORR_DISABLE__M |
((0x2) << (FEC_OC_SNC_MODE_ERROR_CTL__B));
fec_oc_ems_mode |= ((0x01) << (FEC_OC_EMS_MODE_MODE__B));
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_DPR_MODE__A, fec_oc_dpr_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_MODE__A, fec_oc_snc_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_EMS_MODE__A, fec_oc_ems_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int bit_reverse_mpeg_output(struct drx_demod_instance *demod)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
int rc;
u16 fec_oc_ipr_mode = 0;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_IPR_MODE__A, &fec_oc_ipr_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
fec_oc_ipr_mode &= (~FEC_OC_IPR_MODE_REVERSE_ORDER__M);
if (ext_attr->bit_reverse_mpeg_outout)
fec_oc_ipr_mode |= FEC_OC_IPR_MODE_REVERSE_ORDER__M;
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_IPR_MODE__A, fec_oc_ipr_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_mpeg_start_width(struct drx_demod_instance *demod)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)(NULL);
struct drx_common_attr *common_attr = (struct drx_common_attr *) NULL;
int rc;
u16 fec_oc_comm_mb = 0;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
common_attr = demod->my_common_attr;
if ((common_attr->mpeg_cfg.static_clk == true)
&& (common_attr->mpeg_cfg.enable_parallel == false)) {
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_COMM_MB__A, &fec_oc_comm_mb, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
fec_oc_comm_mb &= ~FEC_OC_COMM_MB_CTL_ON;
if (ext_attr->mpeg_start_width == DRXJ_MPEG_START_WIDTH_8CLKCYC)
fec_oc_comm_mb |= FEC_OC_COMM_MB_CTL_ON;
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_COMM_MB__A, fec_oc_comm_mb, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
return 0;
rw_error:
return rc;
}
static int ctrl_set_uio_cfg(struct drx_demod_instance *demod, struct drxuio_cfg *uio_cfg)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
int rc;
if ((uio_cfg == NULL) || (demod == NULL))
return -EINVAL;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
switch (uio_cfg->uio) {
case DRX_UIO1:
if (!ext_attr->has_smatx)
return -EIO;
switch (uio_cfg->mode) {
case DRX_UIO_MODE_FIRMWARE_SMA:
case DRX_UIO_MODE_FIRMWARE_SAW:
case DRX_UIO_MODE_READWRITE:
ext_attr->uio_sma_tx_mode = uio_cfg->mode;
break;
case DRX_UIO_MODE_DISABLE:
ext_attr->uio_sma_tx_mode = uio_cfg->mode;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_SMA_TX_CFG__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EINVAL;
}
break;
case DRX_UIO2:
if (!ext_attr->has_smarx)
return -EIO;
switch (uio_cfg->mode) {
case DRX_UIO_MODE_FIRMWARE0:
case DRX_UIO_MODE_READWRITE:
ext_attr->uio_sma_rx_mode = uio_cfg->mode;
break;
case DRX_UIO_MODE_DISABLE:
ext_attr->uio_sma_rx_mode = uio_cfg->mode;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_SMA_RX_CFG__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EINVAL;
break;
}
break;
case DRX_UIO3:
if (!ext_attr->has_gpio)
return -EIO;
switch (uio_cfg->mode) {
case DRX_UIO_MODE_FIRMWARE0:
case DRX_UIO_MODE_READWRITE:
ext_attr->uio_gpio_mode = uio_cfg->mode;
break;
case DRX_UIO_MODE_DISABLE:
ext_attr->uio_gpio_mode = uio_cfg->mode;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_GPIO_CFG__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EINVAL;
break;
}
break;
case DRX_UIO4:
if (!ext_attr->has_irqn)
return -EIO;
switch (uio_cfg->mode) {
case DRX_UIO_MODE_READWRITE:
ext_attr->uio_irqn_mode = uio_cfg->mode;
break;
case DRX_UIO_MODE_DISABLE:
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_IRQN_CFG__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->uio_irqn_mode = uio_cfg->mode;
break;
case DRX_UIO_MODE_FIRMWARE0:
default:
return -EINVAL;
break;
}
break;
default:
return -EINVAL;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_TOP_COMM_KEY__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int
ctrl_uio_write(struct drx_demod_instance *demod, struct drxuio_data *uio_data)
{
struct drxj_data *ext_attr = (struct drxj_data *) (NULL);
int rc;
u16 pin_cfg_value = 0;
u16 value = 0;
if ((uio_data == NULL) || (demod == NULL))
return -EINVAL;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
switch (uio_data->uio) {
case DRX_UIO1:
if (!ext_attr->has_smatx)
return -EIO;
if ((ext_attr->uio_sma_tx_mode != DRX_UIO_MODE_READWRITE)
&& (ext_attr->uio_sma_tx_mode != DRX_UIO_MODE_FIRMWARE_SAW)) {
return -EIO;
}
pin_cfg_value = 0;
pin_cfg_value |= 0x0113;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_SMA_TX_CFG__A, pin_cfg_value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_LO__A, &value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (!uio_data->value)
value &= 0x7FFF;
else
value |= 0x8000;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_LO__A, value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_UIO2:
if (!ext_attr->has_smarx)
return -EIO;
if (ext_attr->uio_sma_rx_mode != DRX_UIO_MODE_READWRITE)
return -EIO;
pin_cfg_value = 0;
pin_cfg_value |= 0x0113;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_SMA_RX_CFG__A, pin_cfg_value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_LO__A, &value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (!uio_data->value)
value &= 0xBFFF;
else
value |= 0x4000;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_LO__A, value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_UIO3:
if (!ext_attr->has_gpio)
return -EIO;
if (ext_attr->uio_gpio_mode != DRX_UIO_MODE_READWRITE)
return -EIO;
pin_cfg_value = 0;
pin_cfg_value |= 0x0113;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_GPIO_CFG__A, pin_cfg_value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_HI__A, &value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (!uio_data->value)
value &= 0xFFFB;
else
value |= 0x0004;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_HI__A, value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_UIO4:
if (!ext_attr->has_irqn)
return -EIO;
if (ext_attr->uio_irqn_mode != DRX_UIO_MODE_READWRITE)
return -EIO;
pin_cfg_value = 0;
pin_cfg_value |= 0x0113;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_IRQN_CFG__A, pin_cfg_value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_LO__A, &value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (uio_data->value == false)
value &= 0xEFFF;
else
value |= 0x1000;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_UIO_OUT_LO__A, value, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EINVAL;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_TOP_COMM_KEY__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int
ctrl_i2c_bridge(struct drx_demod_instance *demod, bool *bridge_closed)
{
struct drxj_hi_cmd hi_cmd;
u16 result = 0;
if (bridge_closed == NULL)
return -EINVAL;
hi_cmd.cmd = SIO_HI_RA_RAM_CMD_BRDCTRL;
hi_cmd.param1 = SIO_HI_RA_RAM_PAR_1_PAR1_SEC_KEY;
if (*bridge_closed)
hi_cmd.param2 = SIO_HI_RA_RAM_PAR_2_BRD_CFG_CLOSED;
else
hi_cmd.param2 = SIO_HI_RA_RAM_PAR_2_BRD_CFG_OPEN;
return hi_command(demod->my_i2c_dev_addr, &hi_cmd, &result);
}
static int smart_ant_init(struct drx_demod_instance *demod)
{
struct drxj_data *ext_attr = NULL;
struct i2c_device_addr *dev_addr = NULL;
struct drxuio_cfg uio_cfg = { DRX_UIO1, DRX_UIO_MODE_FIRMWARE_SMA };
int rc;
u16 data = 0;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_TOP_COMM_KEY__A, SIO_TOP_COMM_KEY_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, SIO_SA_TX_COMMAND__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (ext_attr->smart_ant_inverted) {
rc = drxj_dap_write_reg16(dev_addr, SIO_SA_TX_COMMAND__A, (data | SIO_SA_TX_COMMAND_TX_INVERT__M) | SIO_SA_TX_COMMAND_TX_ENABLE__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, SIO_SA_TX_COMMAND__A, (data & (~SIO_SA_TX_COMMAND_TX_INVERT__M)) | SIO_SA_TX_COMMAND_TX_ENABLE__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = ctrl_set_uio_cfg(demod, &uio_cfg);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_SMA_TX_CFG__A, 0x13, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_PDR_SMA_TX_GPIO_FNC__A, 0x03, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, SIO_TOP_COMM_KEY__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int scu_command(struct i2c_device_addr *dev_addr, struct drxjscu_cmd *cmd)
{
int rc;
u16 cur_cmd = 0;
unsigned long timeout;
if (cmd == NULL)
return -EINVAL;
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_COMMAND__A, &cur_cmd, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (cur_cmd != DRX_SCU_READY)
return -EIO;
switch (cmd->parameter_len) {
case 5:
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_PARAM_4__A, *(cmd->parameter + 4), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 4:
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_PARAM_3__A, *(cmd->parameter + 3), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 3:
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_PARAM_2__A, *(cmd->parameter + 2), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 2:
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_PARAM_1__A, *(cmd->parameter + 1), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 1:
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_PARAM_0__A, *(cmd->parameter + 0), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 0:
break;
default:
return -EIO;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_COMMAND__A, cmd->command, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
timeout = jiffies + msecs_to_jiffies(DRXJ_MAX_WAITTIME);
while (time_is_after_jiffies(timeout)) {
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_COMMAND__A, &cur_cmd, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (cur_cmd == DRX_SCU_READY)
break;
usleep_range(1000, 2000);
}
if (cur_cmd != DRX_SCU_READY)
return -EIO;
if ((cmd->result_len > 0) && (cmd->result != NULL)) {
s16 err;
switch (cmd->result_len) {
case 4:
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_PARAM_3__A, cmd->result + 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 3:
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_PARAM_2__A, cmd->result + 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 2:
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_PARAM_1__A, cmd->result + 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 1:
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_PARAM_0__A, cmd->result + 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
case 0:
break;
default:
return -EIO;
}
err = cmd->result[0];
if ((err == (s16) SCU_RAM_PARAM_0_RESULT_UNKSTD)
|| (err == (s16) SCU_RAM_PARAM_0_RESULT_UNKCMD)
|| (err == (s16) SCU_RAM_PARAM_0_RESULT_INVPAR)
|| (err == (s16) SCU_RAM_PARAM_0_RESULT_SIZE)
) {
return -EINVAL;
}
else if (err < 0)
return -EIO;
else
return 0;
}
return 0;
rw_error:
return rc;
}
static
int drxj_dap_scu_atomic_read_write_block(struct i2c_device_addr *dev_addr, u32 addr, u16 datasize,
u8 *data, bool read_flag)
{
struct drxjscu_cmd scu_cmd;
int rc;
u16 set_param_parameters[15];
u16 cmd_result[15];
if (!data || !dev_addr || (datasize % 2) || ((datasize / 2) > 16))
return -EINVAL;
set_param_parameters[1] = (u16) ADDR_AT_SCU_SPACE(addr);
if (read_flag) {
set_param_parameters[0] = ((~(0x0080)) & datasize);
scu_cmd.parameter_len = 2;
scu_cmd.result_len = datasize / 2 + 2;
} else {
int i = 0;
set_param_parameters[0] = 0x0080 | datasize;
for (i = 0; i < (datasize / 2); i++) {
set_param_parameters[i + 2] =
(data[2 * i] | (data[(2 * i) + 1] << 8));
}
scu_cmd.parameter_len = datasize / 2 + 2;
scu_cmd.result_len = 1;
}
scu_cmd.command =
SCU_RAM_COMMAND_STANDARD_TOP |
SCU_RAM_COMMAND_CMD_AUX_SCU_ATOMIC_ACCESS;
scu_cmd.result = cmd_result;
scu_cmd.parameter = set_param_parameters;
rc = scu_command(dev_addr, &scu_cmd);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (read_flag) {
int i = 0;
for (i = 0; i < (datasize / 2); i++) {
data[2 * i] = (u8) (scu_cmd.result[i + 2] & 0xFF);
data[(2 * i) + 1] = (u8) (scu_cmd.result[i + 2] >> 8);
}
}
return 0;
rw_error:
return rc;
}
static
int drxj_dap_scu_atomic_read_reg16(struct i2c_device_addr *dev_addr,
u32 addr,
u16 *data, u32 flags)
{
u8 buf[2] = { 0 };
int rc = -EIO;
u16 word = 0;
if (!data)
return -EINVAL;
rc = drxj_dap_scu_atomic_read_write_block(dev_addr, addr, 2, buf, true);
if (rc < 0)
return rc;
word = (u16) (buf[0] + (buf[1] << 8));
*data = word;
return rc;
}
static
int drxj_dap_scu_atomic_write_reg16(struct i2c_device_addr *dev_addr,
u32 addr,
u16 data, u32 flags)
{
u8 buf[2];
int rc = -EIO;
buf[0] = (u8) (data & 0xff);
buf[1] = (u8) ((data >> 8) & 0xff);
rc = drxj_dap_scu_atomic_read_write_block(dev_addr, addr, 2, buf, false);
return rc;
}
static int adc_sync_measurement(struct drx_demod_instance *demod, u16 *count)
{
struct i2c_device_addr *dev_addr = NULL;
int rc;
u16 data = 0;
dev_addr = demod->my_i2c_dev_addr;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_COMM_EXEC__A, IQM_AF_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_START_LOCK__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
msleep(1);
*count = 0;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_PHASE0__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (data == 127)
*count = *count + 1;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_PHASE1__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (data == 127)
*count = *count + 1;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_PHASE2__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (data == 127)
*count = *count + 1;
return 0;
rw_error:
return rc;
}
static int adc_synchronization(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = NULL;
int rc;
u16 count = 0;
dev_addr = demod->my_i2c_dev_addr;
rc = adc_sync_measurement(demod, &count);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (count == 1) {
u16 clk_neg = 0;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_CLKNEG__A, &clk_neg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
clk_neg ^= IQM_AF_CLKNEG_CLKNEGDATA__M;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_CLKNEG__A, clk_neg, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = adc_sync_measurement(demod, &count);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if (count < 2)
return -EIO;
return 0;
rw_error:
return rc;
}
static int init_agc(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = NULL;
struct drx_common_attr *common_attr = NULL;
struct drxj_data *ext_attr = NULL;
struct drxj_cfg_agc *p_agc_rf_settings = NULL;
struct drxj_cfg_agc *p_agc_if_settings = NULL;
int rc;
u16 ingain_tgt_max = 0;
u16 clp_dir_to = 0;
u16 sns_sum_max = 0;
u16 clp_sum_max = 0;
u16 sns_dir_to = 0;
u16 ki_innergain_min = 0;
u16 agc_ki = 0;
u16 ki_max = 0;
u16 if_iaccu_hi_tgt_min = 0;
u16 data = 0;
u16 agc_ki_dgain = 0;
u16 ki_min = 0;
u16 clp_ctrl_mode = 0;
u16 agc_rf = 0;
u16 agc_if = 0;
dev_addr = demod->my_i2c_dev_addr;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
switch (ext_attr->standard) {
case DRX_STANDARD_8VSB:
clp_sum_max = 1023;
clp_dir_to = (u16) (-9);
sns_sum_max = 1023;
sns_dir_to = (u16) (-9);
ki_innergain_min = (u16) (-32768);
ki_max = 0x032C;
agc_ki_dgain = 0xC;
if_iaccu_hi_tgt_min = 2047;
ki_min = 0x0117;
ingain_tgt_max = 16383;
clp_ctrl_mode = 0;
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MINGAIN__A, 0x7fff, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MAXGAIN__A, 0x0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_SUM__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_CYCCNT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_DIR_WD__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_DIR_STP__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_SUM__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_CYCCNT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_DIR_WD__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_DIR_STP__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_INGAIN__A, 1024, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_VSB_AGC_POW_TGT__A, 22600, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_INGAIN_TGT__A, 13200, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
p_agc_if_settings = &(ext_attr->vsb_if_agc_cfg);
p_agc_rf_settings = &(ext_attr->vsb_rf_agc_cfg);
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
case DRX_STANDARD_ITU_B:
ingain_tgt_max = 5119;
clp_sum_max = 1023;
clp_dir_to = (u16) (-5);
sns_sum_max = 127;
sns_dir_to = (u16) (-3);
ki_innergain_min = 0;
ki_max = 0x0657;
if_iaccu_hi_tgt_min = 2047;
agc_ki_dgain = 0x7;
ki_min = 0x0117;
clp_ctrl_mode = 0;
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MINGAIN__A, 0x7fff, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MAXGAIN__A, 0x0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_SUM__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_CYCCNT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_DIR_WD__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_DIR_STP__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_SUM__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_CYCCNT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_DIR_WD__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_DIR_STP__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
p_agc_if_settings = &(ext_attr->qam_if_agc_cfg);
p_agc_rf_settings = &(ext_attr->qam_rf_agc_cfg);
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_INGAIN_TGT__A, p_agc_if_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_AGC_KI__A, &agc_ki, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
agc_ki &= 0xf000;
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI__A, agc_ki, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
#endif
default:
return -EINVAL;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_INGAIN_TGT_MIN__A, p_agc_if_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_INGAIN__A, p_agc_if_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_INGAIN_TGT_MAX__A, ingain_tgt_max, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT_MIN__A, if_iaccu_hi_tgt_min, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_IF_IACCU_HI__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_IF_IACCU_LO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_RF_IACCU_HI__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_RF_IACCU_LO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_RF_MAX__A, 32767, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_SUM_MAX__A, clp_sum_max, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_SUM_MAX__A, sns_sum_max, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_INNERGAIN_MIN__A, ki_innergain_min, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_FAST_SNS_CTRL_DELAY__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_CYCLEN__A, 500, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_CYCLEN__A, 500, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MAXMINGAIN_TH__A, 20, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MIN__A, ki_min, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_MAX__A, ki_max, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI_RED__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_SUM_MIN__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_CYCLEN__A, 500, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_DIR_TO__A, clp_dir_to, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_SUM_MIN__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_SNS_DIR_TO__A, sns_dir_to, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_FAST_CLP_CTRL_DELAY__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_CLP_CTRL_MODE__A, clp_ctrl_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
agc_rf = 0x800 + p_agc_rf_settings->cut_off_current;
if (common_attr->tuner_rf_agc_pol == true)
agc_rf = 0x87ff - agc_rf;
agc_if = 0x800;
if (common_attr->tuner_if_agc_pol == true)
agc_rf = 0x87ff - agc_rf;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_AGC_RF__A, agc_rf, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_AGC_IF__A, agc_if, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_DGAIN__M;
data |= (agc_ki_dgain << SCU_RAM_AGC_KI_DGAIN__B);
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int
set_frequency(struct drx_demod_instance *demod,
struct drx_channel *channel, s32 tuner_freq_offset)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drxj_data *ext_attr = demod->my_ext_attr;
int rc;
s32 sampling_frequency = 0;
s32 frequency_shift = 0;
s32 if_freq_actual = 0;
s32 rf_freq_residual = -1 * tuner_freq_offset;
s32 adc_freq = 0;
s32 intermediate_freq = 0;
u32 iqm_fs_rate_ofs = 0;
bool adc_flip = true;
bool select_pos_image = false;
bool rf_mirror;
bool tuner_mirror;
bool image_to_select = true;
s32 fm_frequency_shift = 0;
rf_mirror = (ext_attr->mirror == DRX_MIRROR_YES) ? true : false;
tuner_mirror = demod->my_common_attr->mirror_freq_spect ? false : true;
switch (ext_attr->standard) {
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
case DRX_STANDARD_PAL_SECAM_LP:
case DRX_STANDARD_8VSB:
select_pos_image = true;
break;
case DRX_STANDARD_FM:
fm_frequency_shift = 1000;
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_NTSC:
case DRX_STANDARD_PAL_SECAM_BG:
case DRX_STANDARD_PAL_SECAM_DK:
case DRX_STANDARD_PAL_SECAM_I:
case DRX_STANDARD_PAL_SECAM_L:
select_pos_image = false;
break;
default:
return -EINVAL;
}
intermediate_freq = demod->my_common_attr->intermediate_freq;
sampling_frequency = demod->my_common_attr->sys_clock_freq / 3;
if (tuner_mirror)
if_freq_actual = intermediate_freq + rf_freq_residual + fm_frequency_shift;
else
if_freq_actual = intermediate_freq - rf_freq_residual - fm_frequency_shift;
if (if_freq_actual > sampling_frequency / 2) {
adc_freq = sampling_frequency - if_freq_actual;
adc_flip = true;
} else {
adc_freq = if_freq_actual;
adc_flip = false;
}
frequency_shift = adc_freq;
image_to_select =
(bool) (rf_mirror ^ tuner_mirror ^ adc_flip ^ select_pos_image);
iqm_fs_rate_ofs = frac28(frequency_shift, sampling_frequency);
if (image_to_select)
iqm_fs_rate_ofs = ~iqm_fs_rate_ofs + 1;
rc = drxdap_fasi_write_reg32(dev_addr, IQM_FS_RATE_OFS_LO__A, iqm_fs_rate_ofs, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->iqm_fs_rate_ofs = iqm_fs_rate_ofs;
ext_attr->pos_image = (bool) (rf_mirror ^ tuner_mirror ^ select_pos_image);
return 0;
rw_error:
return rc;
}
static int get_acc_pkt_err(struct drx_demod_instance *demod, u16 *packet_err)
{
int rc;
static u16 pkt_err;
static u16 last_pkt_err;
u16 data = 0;
struct drxj_data *ext_attr = NULL;
struct i2c_device_addr *dev_addr = NULL;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
dev_addr = demod->my_i2c_dev_addr;
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_FEC_ACCUM_PKT_FAILURES__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (ext_attr->reset_pkt_err_acc) {
last_pkt_err = data;
pkt_err = 0;
ext_attr->reset_pkt_err_acc = false;
}
if (data < last_pkt_err) {
pkt_err += 0xffff - last_pkt_err;
pkt_err += data;
} else {
pkt_err += (data - last_pkt_err);
}
*packet_err = pkt_err;
last_pkt_err = data;
return 0;
rw_error:
return rc;
}
static int
set_agc_rf(struct drx_demod_instance *demod, struct drxj_cfg_agc *agc_settings, bool atomic)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
struct drxj_cfg_agc *p_agc_settings = NULL;
struct drx_common_attr *common_attr = NULL;
int rc;
drx_write_reg16func_t scu_wr16 = NULL;
drx_read_reg16func_t scu_rr16 = NULL;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
if (atomic) {
scu_rr16 = drxj_dap_scu_atomic_read_reg16;
scu_wr16 = drxj_dap_scu_atomic_write_reg16;
} else {
scu_rr16 = drxj_dap_read_reg16;
scu_wr16 = drxj_dap_write_reg16;
}
if ((ext_attr->standard == agc_settings->standard) ||
(DRXJ_ISQAMSTD(ext_attr->standard) &&
DRXJ_ISQAMSTD(agc_settings->standard)) ||
(DRXJ_ISATVSTD(ext_attr->standard) &&
DRXJ_ISATVSTD(agc_settings->standard))) {
u16 data = 0;
switch (agc_settings->ctrl_mode) {
case DRX_AGC_CTRL_AUTO:
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data |= IQM_AF_STDBY_STDBY_TAGC_RF_A2_ACTIVE;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_RF__M;
if (ext_attr->standard == DRX_STANDARD_8VSB)
data |= (2 << SCU_RAM_AGC_KI_RF__B);
else if (DRXJ_ISQAMSTD(ext_attr->standard))
data |= (5 << SCU_RAM_AGC_KI_RF__B);
else
data |= (4 << SCU_RAM_AGC_KI_RF__B);
if (common_attr->tuner_rf_agc_pol)
data |= SCU_RAM_AGC_KI_INV_RF_POL__M;
else
data &= ~SCU_RAM_AGC_KI_INV_RF_POL__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI_RED__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_RED_RAGC_RED__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI_RED__A, (~(agc_settings->speed << SCU_RAM_AGC_KI_RED_RAGC_RED__B) & SCU_RAM_AGC_KI_RED_RAGC_RED__M) | data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (agc_settings->standard == DRX_STANDARD_8VSB)
p_agc_settings = &(ext_attr->vsb_if_agc_cfg);
else if (DRXJ_ISQAMSTD(agc_settings->standard))
p_agc_settings = &(ext_attr->qam_if_agc_cfg);
else if (DRXJ_ISATVSTD(agc_settings->standard))
p_agc_settings = &(ext_attr->atv_if_agc_cfg);
else
return -EINVAL;
if (p_agc_settings->ctrl_mode == DRX_AGC_CTRL_AUTO) {
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT_MAX__A, agc_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT__A, agc_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_RF_IACCU_HI_CO__A, agc_settings->cut_off_current, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_AGC_CTRL_USER:
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data |= IQM_AF_STDBY_STDBY_TAGC_RF_A2_ACTIVE;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_RF__M;
if (common_attr->tuner_rf_agc_pol)
data |= SCU_RAM_AGC_KI_INV_RF_POL__M;
else
data &= ~SCU_RAM_AGC_KI_INV_RF_POL__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_RF_IACCU_HI__A, agc_settings->output_level, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_AGC_CTRL_OFF:
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= (~IQM_AF_STDBY_STDBY_TAGC_RF_A2_ACTIVE);
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_RF__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EINVAL;
}
}
switch (agc_settings->standard) {
case DRX_STANDARD_8VSB:
ext_attr->vsb_rf_agc_cfg = *agc_settings;
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
ext_attr->qam_rf_agc_cfg = *agc_settings;
break;
#endif
default:
return -EIO;
}
return 0;
rw_error:
return rc;
}
static int
set_agc_if(struct drx_demod_instance *demod, struct drxj_cfg_agc *agc_settings, bool atomic)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
struct drxj_cfg_agc *p_agc_settings = NULL;
struct drx_common_attr *common_attr = NULL;
drx_write_reg16func_t scu_wr16 = NULL;
drx_read_reg16func_t scu_rr16 = NULL;
int rc;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
if (atomic) {
scu_rr16 = drxj_dap_scu_atomic_read_reg16;
scu_wr16 = drxj_dap_scu_atomic_write_reg16;
} else {
scu_rr16 = drxj_dap_read_reg16;
scu_wr16 = drxj_dap_write_reg16;
}
if ((ext_attr->standard == agc_settings->standard) ||
(DRXJ_ISQAMSTD(ext_attr->standard) &&
DRXJ_ISQAMSTD(agc_settings->standard)) ||
(DRXJ_ISATVSTD(ext_attr->standard) &&
DRXJ_ISATVSTD(agc_settings->standard))) {
u16 data = 0;
switch (agc_settings->ctrl_mode) {
case DRX_AGC_CTRL_AUTO:
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data |= IQM_AF_STDBY_STDBY_TAGC_IF_A2_ACTIVE;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_IF_AGC_DISABLE__M;
data &= ~SCU_RAM_AGC_KI_IF__M;
if (ext_attr->standard == DRX_STANDARD_8VSB)
data |= (3 << SCU_RAM_AGC_KI_IF__B);
else if (DRXJ_ISQAMSTD(ext_attr->standard))
data |= (6 << SCU_RAM_AGC_KI_IF__B);
else
data |= (5 << SCU_RAM_AGC_KI_IF__B);
if (common_attr->tuner_if_agc_pol)
data |= SCU_RAM_AGC_KI_INV_IF_POL__M;
else
data &= ~SCU_RAM_AGC_KI_INV_IF_POL__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI_RED__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_RED_IAGC_RED__M;
rc = (*scu_wr16) (dev_addr, SCU_RAM_AGC_KI_RED__A, (~(agc_settings->speed << SCU_RAM_AGC_KI_RED_IAGC_RED__B) & SCU_RAM_AGC_KI_RED_IAGC_RED__M) | data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (agc_settings->standard == DRX_STANDARD_8VSB)
p_agc_settings = &(ext_attr->vsb_rf_agc_cfg);
else if (DRXJ_ISQAMSTD(agc_settings->standard))
p_agc_settings = &(ext_attr->qam_rf_agc_cfg);
else if (DRXJ_ISATVSTD(agc_settings->standard))
p_agc_settings = &(ext_attr->atv_rf_agc_cfg);
else
return -EINVAL;
if (p_agc_settings->ctrl_mode == DRX_AGC_CTRL_AUTO) {
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT_MAX__A, p_agc_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT__A, p_agc_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT_MAX__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
break;
case DRX_AGC_CTRL_USER:
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data |= IQM_AF_STDBY_STDBY_TAGC_IF_A2_ACTIVE;
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_IF_AGC_DISABLE__M;
data |= SCU_RAM_AGC_KI_IF_AGC_DISABLE__M;
if (common_attr->tuner_if_agc_pol)
data |= SCU_RAM_AGC_KI_INV_IF_POL__M;
else
data &= ~SCU_RAM_AGC_KI_INV_IF_POL__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_IF_IACCU_HI_TGT_MAX__A, agc_settings->output_level, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_AGC_CTRL_OFF:
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= (~IQM_AF_STDBY_STDBY_TAGC_IF_A2_ACTIVE);
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = (*scu_rr16)(dev_addr, SCU_RAM_AGC_KI__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data &= ~SCU_RAM_AGC_KI_IF_AGC_DISABLE__M;
data |= SCU_RAM_AGC_KI_IF_AGC_DISABLE__M;
rc = (*scu_wr16)(dev_addr, SCU_RAM_AGC_KI__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EINVAL;
}
rc = (*scu_wr16) (dev_addr, SCU_RAM_AGC_INGAIN_TGT_MIN__A, agc_settings->top, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
switch (agc_settings->standard) {
case DRX_STANDARD_8VSB:
ext_attr->vsb_if_agc_cfg = *agc_settings;
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
ext_attr->qam_if_agc_cfg = *agc_settings;
break;
#endif
default:
return -EIO;
}
return 0;
rw_error:
return rc;
}
static int set_iqm_af(struct drx_demod_instance *demod, bool active)
{
u16 data = 0;
struct i2c_device_addr *dev_addr = NULL;
int rc;
dev_addr = demod->my_i2c_dev_addr;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_STDBY__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (!active)
data &= ((~IQM_AF_STDBY_STDBY_ADC_A2_ACTIVE) & (~IQM_AF_STDBY_STDBY_AMP_A2_ACTIVE) & (~IQM_AF_STDBY_STDBY_PD_A2_ACTIVE) & (~IQM_AF_STDBY_STDBY_TAGC_IF_A2_ACTIVE) & (~IQM_AF_STDBY_STDBY_TAGC_RF_A2_ACTIVE));
else
data |= (IQM_AF_STDBY_STDBY_ADC_A2_ACTIVE | IQM_AF_STDBY_STDBY_AMP_A2_ACTIVE | IQM_AF_STDBY_STDBY_PD_A2_ACTIVE | IQM_AF_STDBY_STDBY_TAGC_IF_A2_ACTIVE | IQM_AF_STDBY_STDBY_TAGC_RF_A2_ACTIVE);
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int power_down_vsb(struct drx_demod_instance *demod, bool primary)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drxjscu_cmd cmd_scu = { 0,
0,
0,
NULL,
NULL
};
struct drx_cfg_mpeg_output cfg_mpeg_output;
int rc;
u16 cmd_result = 0;
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_VSB |
SCU_RAM_COMMAND_CMD_DEMOD_STOP;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_COMM_EXEC__A, FEC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_COMM_EXEC__A, VSB_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (primary) {
rc = drxj_dap_write_reg16(dev_addr, IQM_COMM_EXEC__A, IQM_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_iqm_af(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_COMM_EXEC__A, IQM_FS_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FD_COMM_EXEC__A, IQM_FD_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_COMM_EXEC__A, IQM_RC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RT_COMM_EXEC__A, IQM_RT_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_COMM_EXEC__A, IQM_CF_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
cfg_mpeg_output.enable_mpeg_output = false;
rc = ctrl_set_cfg_mpeg_output(demod, &cfg_mpeg_output);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_vsb_leak_n_gain(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = NULL;
int rc;
const u8 vsb_ffe_leak_gain_ram0[] = {
DRXJ_16TO8(0x8),
DRXJ_16TO8(0x8),
DRXJ_16TO8(0x8),
DRXJ_16TO8(0xf),
DRXJ_16TO8(0xf),
DRXJ_16TO8(0xf),
DRXJ_16TO8(0xf),
DRXJ_16TO8(0xf),
DRXJ_16TO8(0xf),
DRXJ_16TO8(0x8),
DRXJ_16TO8(0x8),
DRXJ_16TO8(0x8),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x20),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x10),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x0e),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x07),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x0c),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x06),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x4040),
DRXJ_16TO8(0x4040),
DRXJ_16TO8(0x4040),
DRXJ_16TO8(0x4040),
DRXJ_16TO8(0x4040),
DRXJ_16TO8(0x4040),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010)
};
const u8 vsb_ffe_leak_gain_ram1[] = {
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0808),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0606),
DRXJ_16TO8(0x0606),
DRXJ_16TO8(0x0606),
DRXJ_16TO8(0x0606),
DRXJ_16TO8(0x0606),
DRXJ_16TO8(0x0606),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0505),
DRXJ_16TO8(0x0505),
DRXJ_16TO8(0x0505),
DRXJ_16TO8(0x0505),
DRXJ_16TO8(0x0505),
DRXJ_16TO8(0x0505),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x0303),
DRXJ_16TO8(0x001f),
DRXJ_16TO8(0x01ff),
DRXJ_16TO8(0x01ff),
DRXJ_16TO8(0x004f),
DRXJ_16TO8(0x004f),
DRXJ_16TO8(0x01ff),
DRXJ_16TO8(0x01ff),
DRXJ_16TO8(0x0352),
DRXJ_16TO8(0x0352),
DRXJ_16TO8(0x0000),
DRXJ_16TO8(0x2020),
DRXJ_16TO8(0x1010),
DRXJ_16TO8(0x1818),
DRXJ_16TO8(0x1212)
};
dev_addr = demod->my_i2c_dev_addr;
rc = drxdap_fasi_write_block(dev_addr, VSB_SYSCTRL_RAM0_FFETRAINLKRATIO1__A, sizeof(vsb_ffe_leak_gain_ram0), ((u8 *)vsb_ffe_leak_gain_ram0), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, VSB_SYSCTRL_RAM1_FIRRCA1GAIN9__A, sizeof(vsb_ffe_leak_gain_ram1), ((u8 *)vsb_ffe_leak_gain_ram1), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_vsb(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = NULL;
int rc;
struct drx_common_attr *common_attr = NULL;
struct drxjscu_cmd cmd_scu;
struct drxj_data *ext_attr = NULL;
u16 cmd_result = 0;
u16 cmd_param = 0;
const u8 vsb_taps_re[] = {
DRXJ_16TO8(-2),
DRXJ_16TO8(4),
DRXJ_16TO8(1),
DRXJ_16TO8(-4),
DRXJ_16TO8(1),
DRXJ_16TO8(4),
DRXJ_16TO8(-3),
DRXJ_16TO8(-3),
DRXJ_16TO8(6),
DRXJ_16TO8(1),
DRXJ_16TO8(-9),
DRXJ_16TO8(3),
DRXJ_16TO8(12),
DRXJ_16TO8(-9),
DRXJ_16TO8(-15),
DRXJ_16TO8(17),
DRXJ_16TO8(19),
DRXJ_16TO8(-29),
DRXJ_16TO8(-22),
DRXJ_16TO8(45),
DRXJ_16TO8(25),
DRXJ_16TO8(-70),
DRXJ_16TO8(-28),
DRXJ_16TO8(111),
DRXJ_16TO8(30),
DRXJ_16TO8(-201),
DRXJ_16TO8(-31),
DRXJ_16TO8(629)
};
dev_addr = demod->my_i2c_dev_addr;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_write_reg16(dev_addr, FEC_COMM_EXEC__A, FEC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_COMM_EXEC__A, VSB_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_COMM_EXEC__A, IQM_FS_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FD_COMM_EXEC__A, IQM_FD_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_COMM_EXEC__A, IQM_RC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RT_COMM_EXEC__A, IQM_RT_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_COMM_EXEC__A, IQM_CF_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_VSB
| SCU_RAM_COMMAND_CMD_DEMOD_RESET;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_DCF_BYPASS__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_ADJ_SEL__A, IQM_FS_ADJ_SEL_B_VSB, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_ADJ_SEL__A, IQM_RC_ADJ_SEL_B_VSB, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->iqm_rc_rate_ofs = 0x00AD0D79;
rc = drxdap_fasi_write_reg32(dev_addr, IQM_RC_RATE_OFS_LO__A, ext_attr->iqm_rc_rate_ofs, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CFAGC_GAINSHIFT__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CYGN1TRK__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_CROUT_ENA__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_STRETCH__A, 28, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RT_ACTIVE__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_SYMMETRIC__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_MIDTAP__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_OUT_ENA__A, IQM_CF_OUT_ENA_VSB__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_SCALE__A, 1393, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_SCALE_SH__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_POW_MEAS_LEN__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_RE0__A, sizeof(vsb_taps_re), ((u8 *)vsb_taps_re), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_IM0__A, sizeof(vsb_taps_re), ((u8 *)vsb_taps_re), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_BNTHRESH__A, 330, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CLPLASTNUM__A, 90, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_SNRTH_RCA1__A, 0x0042, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_SNRTH_RCA2__A, 0x0053, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_EQCTRL__A, 0x1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_GPIO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_TOP_ANNEX__A, FEC_TOP_ANNEX_D, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
{
u16 fec_oc_snc_mode = 0;
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_SNC_MODE__A, &fec_oc_snc_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_MODE__A, fec_oc_snc_mode | FEC_OC_SNC_MODE_UNLOCK_ENABLE__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_CLP_LEN__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_CLP_TH__A, 470, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_SNS_LEN__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_SNRTH_PT__A, 0xD4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
{
u16 fec_oc_reg_mode = 0;
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_MODE__A, &fec_oc_reg_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_MODE__A, fec_oc_reg_mode & (~(FEC_OC_MODE_TRANSPARENT__M | FEC_OC_MODE_CLEAR__M | FEC_OC_MODE_RETAIN_FRAMING__M)), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, FEC_DI_TIMEOUT_LO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_DI_TIMEOUT_HI__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_RS_MODE__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_RS_MEASUREMENT_PERIOD__A, FEC_RS_MEASUREMENT_PERIOD, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_RS_MEASUREMENT_PRESCALE__A, FEC_RS_MEASUREMENT_PRESCALE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_MEASUREMENT_PERIOD__A, VSB_TOP_MEASUREMENT_PERIOD, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_reg32(dev_addr, SCU_RAM_FEC_ACCUM_CW_CORRECTED_LO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_FEC_MEAS_COUNT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_FEC_ACCUM_PKT_FAILURES__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CKGN1TRK__A, 128, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (!ext_attr->has_lna) {
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_AMUX__A, 0x02, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = set_iqm_af(demod, true);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = adc_synchronization(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = init_agc(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_agc_if(demod, &(ext_attr->vsb_if_agc_cfg), false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_agc_rf(demod, &(ext_attr->vsb_rf_agc_cfg), false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
{
struct drxj_cfg_afe_gain vsb_pga_cfg = { DRX_STANDARD_8VSB, 0 };
vsb_pga_cfg.gain = ext_attr->vsb_pga_cfg;
rc = ctrl_set_cfg_afe_gain(demod, &vsb_pga_cfg);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = ctrl_set_cfg_pre_saw(demod, &(ext_attr->vsb_pre_saw_cfg));
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_mpegtei_handling(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = bit_reverse_mpeg_output(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_mpeg_start_width(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
{
struct drx_cfg_mpeg_output cfg_mpeg_output;
memcpy(&cfg_mpeg_output, &common_attr->mpeg_cfg, sizeof(cfg_mpeg_output));
cfg_mpeg_output.enable_mpeg_output = true;
rc = ctrl_set_cfg_mpeg_output(demod, &cfg_mpeg_output);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
cmd_param = 0x00;
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_VSB
| SCU_RAM_COMMAND_CMD_DEMOD_SET_PARAM;
cmd_scu.parameter_len = 1;
cmd_scu.result_len = 1;
cmd_scu.parameter = &cmd_param;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_BEAGC_GAINSHIFT__A, 0x0004, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_SNRTH_PT__A, 0x00D2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_SYSSMTRNCTRL__A, VSB_TOP_SYSSMTRNCTRL__PRE | VSB_TOP_SYSSMTRNCTRL_NCOTIMEOUTCNTEN__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_BEDETCTRL__A, 0x142, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_LBAGCREFLVL__A, 640, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CYGN1ACQ__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CYGN1TRK__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_TOP_CYGN2TRK__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_VSB
| SCU_RAM_COMMAND_CMD_DEMOD_START;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_COMM_EXEC__A, IQM_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, VSB_COMM_EXEC__A, VSB_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_COMM_EXEC__A, FEC_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int get_vsb_post_rs_pck_err(struct i2c_device_addr *dev_addr,
u32 *pck_errs, u32 *pck_count)
{
int rc;
u16 data = 0;
u16 period = 0;
u16 prescale = 0;
u16 packet_errors_mant = 0;
u16 packet_errors_exp = 0;
rc = drxj_dap_read_reg16(dev_addr, FEC_RS_NR_FAILURES__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
packet_errors_mant = data & FEC_RS_NR_FAILURES_FIXED_MANT__M;
packet_errors_exp = (data & FEC_RS_NR_FAILURES_EXP__M)
>> FEC_RS_NR_FAILURES_EXP__B;
period = FEC_RS_MEASUREMENT_PERIOD;
prescale = FEC_RS_MEASUREMENT_PRESCALE;
if (period * prescale == 0) {
pr_err("error: period and/or prescale is zero!\n");
return -EIO;
}
*pck_errs = packet_errors_mant * (1 << packet_errors_exp);
*pck_count = period * prescale * 77;
return 0;
rw_error:
return rc;
}
static int get_vs_bpost_viterbi_ber(struct i2c_device_addr *dev_addr,
u32 *ber, u32 *cnt)
{
int rc;
u16 data = 0;
u16 period = 0;
u16 prescale = 0;
u16 bit_errors_mant = 0;
u16 bit_errors_exp = 0;
rc = drxj_dap_read_reg16(dev_addr, FEC_RS_NR_BIT_ERRORS__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
period = FEC_RS_MEASUREMENT_PERIOD;
prescale = FEC_RS_MEASUREMENT_PRESCALE;
bit_errors_mant = data & FEC_RS_NR_BIT_ERRORS_FIXED_MANT__M;
bit_errors_exp = (data & FEC_RS_NR_BIT_ERRORS_EXP__M)
>> FEC_RS_NR_BIT_ERRORS_EXP__B;
*cnt = period * prescale * 207 * ((bit_errors_exp > 2) ? 1 : 8);
if (((bit_errors_mant << bit_errors_exp) >> 3) > 68700)
*ber = (*cnt) * 26570;
else {
if (period * prescale == 0) {
pr_err("error: period and/or prescale is zero!\n");
return -EIO;
}
*ber = bit_errors_mant << ((bit_errors_exp > 2) ?
(bit_errors_exp - 3) : bit_errors_exp);
}
return 0;
rw_error:
return rc;
}
static int get_vs_bpre_viterbi_ber(struct i2c_device_addr *dev_addr,
u32 *ber, u32 *cnt)
{
u16 data = 0;
int rc;
rc = drxj_dap_read_reg16(dev_addr, VSB_TOP_NR_SYM_ERRS__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
return -EIO;
}
*ber = data;
*cnt = VSB_TOP_MEASUREMENT_PERIOD * SYMBOLS_PER_SEGMENT;
return 0;
}
static int get_vsbmer(struct i2c_device_addr *dev_addr, u16 *mer)
{
int rc;
u16 data_hi = 0;
rc = drxj_dap_read_reg16(dev_addr, VSB_TOP_ERR_ENERGY_H__A, &data_hi, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
*mer =
(u16) (log1_times100(21504) - log1_times100((data_hi << 6) / 52));
return 0;
rw_error:
return rc;
}
static int power_down_qam(struct drx_demod_instance *demod, bool primary)
{
struct drxjscu_cmd cmd_scu = { 0,
0,
0,
NULL,
NULL
};
int rc;
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drx_cfg_mpeg_output cfg_mpeg_output;
struct drx_common_attr *common_attr = demod->my_common_attr;
u16 cmd_result = 0;
rc = drxj_dap_write_reg16(dev_addr, FEC_COMM_EXEC__A, FEC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_COMM_EXEC__A, QAM_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_QAM |
SCU_RAM_COMMAND_CMD_DEMOD_STOP;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (primary) {
rc = drxj_dap_write_reg16(dev_addr, IQM_COMM_EXEC__A, IQM_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_iqm_af(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_COMM_EXEC__A, IQM_FS_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FD_COMM_EXEC__A, IQM_FD_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_COMM_EXEC__A, IQM_RC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RT_COMM_EXEC__A, IQM_RT_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_COMM_EXEC__A, IQM_CF_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
memcpy(&cfg_mpeg_output, &common_attr->mpeg_cfg, sizeof(cfg_mpeg_output));
cfg_mpeg_output.enable_mpeg_output = false;
rc = ctrl_set_cfg_mpeg_output(demod, &cfg_mpeg_output);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int
set_qam_measurement(struct drx_demod_instance *demod,
enum drx_modulation constellation, u32 symbol_rate)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
int rc;
u32 fec_bits_desired = 0;
u16 fec_rs_plen = 0;
u16 fec_rs_prescale = 0;
u32 fec_rs_period = 0;
u32 fec_rs_bit_cnt = 0;
u32 fec_oc_snc_fail_period = 0;
u32 qam_vd_period = 0;
u32 qam_vd_bit_cnt = 0;
u16 fec_vd_plen = 0;
u16 qam_vd_prescale = 0;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
fec_bits_desired = ext_attr->fec_bits_desired;
fec_rs_prescale = ext_attr->fec_rs_prescale;
switch (constellation) {
case DRX_CONSTELLATION_QAM16:
fec_bits_desired = 4 * symbol_rate;
break;
case DRX_CONSTELLATION_QAM32:
fec_bits_desired = 5 * symbol_rate;
break;
case DRX_CONSTELLATION_QAM64:
fec_bits_desired = 6 * symbol_rate;
break;
case DRX_CONSTELLATION_QAM128:
fec_bits_desired = 7 * symbol_rate;
break;
case DRX_CONSTELLATION_QAM256:
fec_bits_desired = 8 * symbol_rate;
break;
default:
return -EINVAL;
}
switch (ext_attr->standard) {
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
fec_rs_plen = 204 * 8;
break;
case DRX_STANDARD_ITU_B:
fec_rs_plen = 128 * 7;
break;
default:
return -EINVAL;
}
ext_attr->fec_rs_plen = fec_rs_plen;
fec_rs_bit_cnt = fec_rs_prescale * fec_rs_plen;
if (fec_rs_bit_cnt == 0) {
pr_err("error: fec_rs_bit_cnt is zero!\n");
return -EIO;
}
fec_rs_period = fec_bits_desired / fec_rs_bit_cnt + 1;
if (ext_attr->standard != DRX_STANDARD_ITU_B)
fec_oc_snc_fail_period = fec_rs_period;
if (fec_rs_period > 0xFFFF)
fec_rs_period = 0xFFFF;
switch (ext_attr->standard) {
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_C:
break;
case DRX_STANDARD_ITU_B:
switch (constellation) {
case DRX_CONSTELLATION_QAM64:
fec_rs_period = 31581;
fec_oc_snc_fail_period = 17932;
break;
case DRX_CONSTELLATION_QAM256:
fec_rs_period = 45446;
fec_oc_snc_fail_period = 25805;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_OC_SNC_FAIL_PERIOD__A, (u16)fec_oc_snc_fail_period, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_RS_MEASUREMENT_PERIOD__A, (u16)fec_rs_period, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_RS_MEASUREMENT_PRESCALE__A, fec_rs_prescale, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->fec_rs_period = (u16) fec_rs_period;
ext_attr->fec_rs_prescale = fec_rs_prescale;
rc = drxdap_fasi_write_reg32(dev_addr, SCU_RAM_FEC_ACCUM_CW_CORRECTED_LO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_FEC_MEAS_COUNT__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_FEC_ACCUM_PKT_FAILURES__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (ext_attr->standard == DRX_STANDARD_ITU_B) {
fec_vd_plen = ext_attr->fec_vd_plen;
qam_vd_prescale = ext_attr->qam_vd_prescale;
qam_vd_bit_cnt = qam_vd_prescale * fec_vd_plen;
switch (constellation) {
case DRX_CONSTELLATION_QAM64:
qam_vd_period =
qam_vd_bit_cnt * (QAM_TOP_CONSTELLATION_QAM64 + 1)
* (QAM_TOP_CONSTELLATION_QAM64 + 1);
break;
case DRX_CONSTELLATION_QAM256:
qam_vd_period =
qam_vd_bit_cnt * (QAM_TOP_CONSTELLATION_QAM256 + 1)
* (QAM_TOP_CONSTELLATION_QAM256 + 1);
break;
default:
return -EINVAL;
}
if (qam_vd_period == 0) {
pr_err("error: qam_vd_period is zero!\n");
return -EIO;
}
qam_vd_period = fec_bits_desired / qam_vd_period;
if (qam_vd_period > 0xFFFF)
qam_vd_period = 0xFFFF;
qam_vd_bit_cnt *= qam_vd_period;
rc = drxj_dap_write_reg16(dev_addr, QAM_VD_MEASUREMENT_PERIOD__A, (u16)qam_vd_period, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_VD_MEASUREMENT_PRESCALE__A, qam_vd_prescale, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->qam_vd_period = (u16) qam_vd_period;
ext_attr->qam_vd_prescale = qam_vd_prescale;
}
return 0;
rw_error:
return rc;
}
static int set_qam16(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
const u8 qam_dq_qual_fun[] = {
DRXJ_16TO8(2),
DRXJ_16TO8(2),
DRXJ_16TO8(2),
DRXJ_16TO8(2),
DRXJ_16TO8(3),
DRXJ_16TO8(3),
};
const u8 qam_eq_cma_rad[] = {
DRXJ_16TO8(13517),
DRXJ_16TO8(13517),
DRXJ_16TO8(13517),
DRXJ_16TO8(13517),
DRXJ_16TO8(13517),
DRXJ_16TO8(13517),
};
rc = drxdap_fasi_write_block(dev_addr, QAM_DQ_QUAL_FUN0__A, sizeof(qam_dq_qual_fun), ((u8 *)qam_dq_qual_fun), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, SCU_RAM_QAM_EQ_CMA_RAD0__A, sizeof(qam_eq_cma_rad), ((u8 *)qam_eq_cma_rad), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RTH__A, 140, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FTH__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_PTH__A, 120, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_QTH__A, 230, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_CTH__A, 95, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MTH__A, 105, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RATE_LIM__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FREQ_LIM__A, 56, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_COUNT_LIM__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MEDIAN_AV_MULT__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RADIUS_AV_LIMIT__A, 220, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET1__A, 25, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET2__A, 6, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET3__A, (u16)(-24), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET4__A, (u16)(-65), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET5__A, (u16)(-127), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_FINE__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_COARSE__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_MEDIUM__A, 20, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_COARSE__A, 255, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_MEDIUM__A, 10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_COARSE__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_MEDIUM__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_COARSE__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_MEDIUM__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_FINE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_MEDIUM__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_COARSE__A, 240, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_FINE__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_MEDIUM__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_COARSE__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_SL_SIG_POWER__A, 40960, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_qam32(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
const u8 qam_dq_qual_fun[] = {
DRXJ_16TO8(3),
DRXJ_16TO8(3),
DRXJ_16TO8(3),
DRXJ_16TO8(3),
DRXJ_16TO8(4),
DRXJ_16TO8(4),
};
const u8 qam_eq_cma_rad[] = {
DRXJ_16TO8(6707),
DRXJ_16TO8(6707),
DRXJ_16TO8(6707),
DRXJ_16TO8(6707),
DRXJ_16TO8(6707),
DRXJ_16TO8(6707),
};
rc = drxdap_fasi_write_block(dev_addr, QAM_DQ_QUAL_FUN0__A, sizeof(qam_dq_qual_fun), ((u8 *)qam_dq_qual_fun), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, SCU_RAM_QAM_EQ_CMA_RAD0__A, sizeof(qam_eq_cma_rad), ((u8 *)qam_eq_cma_rad), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RTH__A, 90, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FTH__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_PTH__A, 100, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_QTH__A, 170, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_CTH__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MTH__A, 100, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RATE_LIM__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FREQ_LIM__A, 56, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_COUNT_LIM__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MEDIAN_AV_MULT__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RADIUS_AV_LIMIT__A, 140, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET1__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET2__A, (u16)(-16), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET3__A, (u16)(-26), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET4__A, (u16)(-56), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET5__A, (u16)(-86), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_FINE__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_COARSE__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_MEDIUM__A, 20, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_COARSE__A, 255, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_MEDIUM__A, 10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_COARSE__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_MEDIUM__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_COARSE__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_MEDIUM__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_FINE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_MEDIUM__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_COARSE__A, 176, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_FINE__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_MEDIUM__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_COARSE__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_SL_SIG_POWER__A, 20480, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_qam64(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
const u8 qam_dq_qual_fun[] = {
DRXJ_16TO8(4),
DRXJ_16TO8(4),
DRXJ_16TO8(4),
DRXJ_16TO8(4),
DRXJ_16TO8(6),
DRXJ_16TO8(6),
};
const u8 qam_eq_cma_rad[] = {
DRXJ_16TO8(13336),
DRXJ_16TO8(12618),
DRXJ_16TO8(11988),
DRXJ_16TO8(13809),
DRXJ_16TO8(13809),
DRXJ_16TO8(15609),
};
rc = drxdap_fasi_write_block(dev_addr, QAM_DQ_QUAL_FUN0__A, sizeof(qam_dq_qual_fun), ((u8 *)qam_dq_qual_fun), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, SCU_RAM_QAM_EQ_CMA_RAD0__A, sizeof(qam_eq_cma_rad), ((u8 *)qam_eq_cma_rad), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RTH__A, 105, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FTH__A, 60, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_PTH__A, 100, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_QTH__A, 195, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_CTH__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MTH__A, 84, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RATE_LIM__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FREQ_LIM__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_COUNT_LIM__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MEDIAN_AV_MULT__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RADIUS_AV_LIMIT__A, 141, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET1__A, 7, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET2__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET3__A, (u16)(-15), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET4__A, (u16)(-45), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET5__A, (u16)(-80), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_FINE__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_COARSE__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_MEDIUM__A, 30, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_COARSE__A, 255, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_MEDIUM__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_COARSE__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_MEDIUM__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_COARSE__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_MEDIUM__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_FINE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_MEDIUM__A, 48, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_COARSE__A, 160, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_FINE__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_MEDIUM__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_COARSE__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_SL_SIG_POWER__A, 43008, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_qam128(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
const u8 qam_dq_qual_fun[] = {
DRXJ_16TO8(6),
DRXJ_16TO8(6),
DRXJ_16TO8(6),
DRXJ_16TO8(6),
DRXJ_16TO8(9),
DRXJ_16TO8(9),
};
const u8 qam_eq_cma_rad[] = {
DRXJ_16TO8(6164),
DRXJ_16TO8(6598),
DRXJ_16TO8(6394),
DRXJ_16TO8(6409),
DRXJ_16TO8(6656),
DRXJ_16TO8(7238),
};
rc = drxdap_fasi_write_block(dev_addr, QAM_DQ_QUAL_FUN0__A, sizeof(qam_dq_qual_fun), ((u8 *)qam_dq_qual_fun), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, SCU_RAM_QAM_EQ_CMA_RAD0__A, sizeof(qam_eq_cma_rad), ((u8 *)qam_eq_cma_rad), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RTH__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FTH__A, 60, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_PTH__A, 100, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_QTH__A, 140, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_CTH__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MTH__A, 100, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RATE_LIM__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FREQ_LIM__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_COUNT_LIM__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MEDIAN_AV_MULT__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RADIUS_AV_LIMIT__A, 65, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET1__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET2__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET3__A, (u16)(-1), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET4__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET5__A, (u16)(-23), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_FINE__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_COARSE__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_MEDIUM__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_COARSE__A, 255, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_MEDIUM__A, 20, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_COARSE__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_MEDIUM__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_COARSE__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_MEDIUM__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_FINE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_MEDIUM__A, 32, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_COARSE__A, 144, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_FINE__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_MEDIUM__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_SL_SIG_POWER__A, 20992, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int set_qam256(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
const u8 qam_dq_qual_fun[] = {
DRXJ_16TO8(8),
DRXJ_16TO8(8),
DRXJ_16TO8(8),
DRXJ_16TO8(8),
DRXJ_16TO8(12),
DRXJ_16TO8(12),
};
const u8 qam_eq_cma_rad[] = {
DRXJ_16TO8(12345),
DRXJ_16TO8(12345),
DRXJ_16TO8(13626),
DRXJ_16TO8(12931),
DRXJ_16TO8(14719),
DRXJ_16TO8(15356),
};
rc = drxdap_fasi_write_block(dev_addr, QAM_DQ_QUAL_FUN0__A, sizeof(qam_dq_qual_fun), ((u8 *)qam_dq_qual_fun), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, SCU_RAM_QAM_EQ_CMA_RAD0__A, sizeof(qam_eq_cma_rad), ((u8 *)qam_eq_cma_rad), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RTH__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FTH__A, 60, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_PTH__A, 100, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_QTH__A, 150, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_CTH__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MTH__A, 110, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RATE_LIM__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_FREQ_LIM__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_COUNT_LIM__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_MEDIAN_AV_MULT__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_RADIUS_AV_LIMIT__A, 74, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET1__A, 18, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET2__A, 13, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET3__A, 7, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET4__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_LCAVG_OFFSET5__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_FINE__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CA_COARSE__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_MEDIUM__A, 50, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CP_COARSE__A, 255, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_FINE__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_MEDIUM__A, 25, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CI_COARSE__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_MEDIUM__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EP_COARSE__A, 24, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_FINE__A, 12, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_MEDIUM__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_EI_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_FINE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_MEDIUM__A, 48, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF_COARSE__A, 80, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_FINE__A, 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_MEDIUM__A, 15, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_LC_CF1_COARSE__A, 16, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_SL_SIG_POWER__A, 43520, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int
set_qam(struct drx_demod_instance *demod,
struct drx_channel *channel, s32 tuner_freq_offset, u32 op)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
struct drx_common_attr *common_attr = NULL;
int rc;
u32 adc_frequency = 0;
u32 iqm_rc_rate = 0;
u16 cmd_result = 0;
u16 lc_symbol_freq = 0;
u16 iqm_rc_stretch = 0;
u16 set_env_parameters = 0;
u16 set_param_parameters[2] = { 0 };
struct drxjscu_cmd cmd_scu = { 0,
0,
0,
NULL,
NULL
};
const u8 qam_a_taps[] = {
DRXJ_16TO8(-1),
DRXJ_16TO8(1),
DRXJ_16TO8(1),
DRXJ_16TO8(-1),
DRXJ_16TO8(-1),
DRXJ_16TO8(2),
DRXJ_16TO8(1),
DRXJ_16TO8(-2),
DRXJ_16TO8(0),
DRXJ_16TO8(3),
DRXJ_16TO8(-1),
DRXJ_16TO8(-3),
DRXJ_16TO8(4),
DRXJ_16TO8(1),
DRXJ_16TO8(-8),
DRXJ_16TO8(4),
DRXJ_16TO8(13),
DRXJ_16TO8(-13),
DRXJ_16TO8(-19),
DRXJ_16TO8(28),
DRXJ_16TO8(25),
DRXJ_16TO8(-53),
DRXJ_16TO8(-31),
DRXJ_16TO8(96),
DRXJ_16TO8(37),
DRXJ_16TO8(-190),
DRXJ_16TO8(-40),
DRXJ_16TO8(619)
};
const u8 qam_b64_taps[] = {
DRXJ_16TO8(0),
DRXJ_16TO8(-2),
DRXJ_16TO8(1),
DRXJ_16TO8(2),
DRXJ_16TO8(-2),
DRXJ_16TO8(0),
DRXJ_16TO8(4),
DRXJ_16TO8(-2),
DRXJ_16TO8(-4),
DRXJ_16TO8(4),
DRXJ_16TO8(3),
DRXJ_16TO8(-6),
DRXJ_16TO8(0),
DRXJ_16TO8(6),
DRXJ_16TO8(-5),
DRXJ_16TO8(-3),
DRXJ_16TO8(11),
DRXJ_16TO8(-4),
DRXJ_16TO8(-19),
DRXJ_16TO8(19),
DRXJ_16TO8(28),
DRXJ_16TO8(-45),
DRXJ_16TO8(-36),
DRXJ_16TO8(90),
DRXJ_16TO8(42),
DRXJ_16TO8(-185),
DRXJ_16TO8(-46),
DRXJ_16TO8(614)
};
const u8 qam_b256_taps[] = {
DRXJ_16TO8(-2),
DRXJ_16TO8(4),
DRXJ_16TO8(1),
DRXJ_16TO8(-4),
DRXJ_16TO8(0),
DRXJ_16TO8(4),
DRXJ_16TO8(-2),
DRXJ_16TO8(-4),
DRXJ_16TO8(5),
DRXJ_16TO8(2),
DRXJ_16TO8(-8),
DRXJ_16TO8(2),
DRXJ_16TO8(11),
DRXJ_16TO8(-8),
DRXJ_16TO8(-15),
DRXJ_16TO8(16),
DRXJ_16TO8(19),
DRXJ_16TO8(-27),
DRXJ_16TO8(-22),
DRXJ_16TO8(44),
DRXJ_16TO8(26),
DRXJ_16TO8(-69),
DRXJ_16TO8(-28),
DRXJ_16TO8(110),
DRXJ_16TO8(31),
DRXJ_16TO8(-201),
DRXJ_16TO8(-32),
DRXJ_16TO8(628)
};
const u8 qam_c_taps[] = {
DRXJ_16TO8(-3),
DRXJ_16TO8(3),
DRXJ_16TO8(2),
DRXJ_16TO8(-4),
DRXJ_16TO8(0),
DRXJ_16TO8(4),
DRXJ_16TO8(-1),
DRXJ_16TO8(-4),
DRXJ_16TO8(3),
DRXJ_16TO8(3),
DRXJ_16TO8(-5),
DRXJ_16TO8(0),
DRXJ_16TO8(9),
DRXJ_16TO8(-4),
DRXJ_16TO8(-12),
DRXJ_16TO8(10),
DRXJ_16TO8(16),
DRXJ_16TO8(-21),
DRXJ_16TO8(-20),
DRXJ_16TO8(37),
DRXJ_16TO8(25),
DRXJ_16TO8(-62),
DRXJ_16TO8(-28),
DRXJ_16TO8(105),
DRXJ_16TO8(31),
DRXJ_16TO8(-197),
DRXJ_16TO8(-33),
DRXJ_16TO8(626)
};
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
if ((op & QAM_SET_OP_ALL) || (op & QAM_SET_OP_CONSTELLATION)) {
if (ext_attr->standard == DRX_STANDARD_ITU_B) {
switch (channel->constellation) {
case DRX_CONSTELLATION_QAM256:
iqm_rc_rate = 0x00AE3562;
lc_symbol_freq =
QAM_LC_SYMBOL_FREQ_FREQ_QAM_B_256;
channel->symbolrate = 5360537;
iqm_rc_stretch = IQM_RC_STRETCH_QAM_B_256;
break;
case DRX_CONSTELLATION_QAM64:
iqm_rc_rate = 0x00C05A0E;
lc_symbol_freq = 409;
channel->symbolrate = 5056941;
iqm_rc_stretch = IQM_RC_STRETCH_QAM_B_64;
break;
default:
return -EINVAL;
}
} else {
adc_frequency = (common_attr->sys_clock_freq * 1000) / 3;
if (channel->symbolrate == 0) {
pr_err("error: channel symbolrate is zero!\n");
return -EIO;
}
iqm_rc_rate =
(adc_frequency / channel->symbolrate) * (1 << 21) +
(frac28
((adc_frequency % channel->symbolrate),
channel->symbolrate) >> 7) - (1 << 23);
lc_symbol_freq =
(u16) (frac28
(channel->symbolrate +
(adc_frequency >> 13),
adc_frequency) >> 16);
if (lc_symbol_freq > 511)
lc_symbol_freq = 511;
iqm_rc_stretch = 21;
}
if (ext_attr->standard == DRX_STANDARD_ITU_A) {
set_env_parameters = QAM_TOP_ANNEX_A;
set_param_parameters[0] = channel->constellation;
set_param_parameters[1] = DRX_INTERLEAVEMODE_I12_J17;
} else if (ext_attr->standard == DRX_STANDARD_ITU_B) {
set_env_parameters = QAM_TOP_ANNEX_B;
set_param_parameters[0] = channel->constellation;
set_param_parameters[1] = channel->interleavemode;
} else if (ext_attr->standard == DRX_STANDARD_ITU_C) {
set_env_parameters = QAM_TOP_ANNEX_C;
set_param_parameters[0] = channel->constellation;
set_param_parameters[1] = DRX_INTERLEAVEMODE_I12_J17;
} else {
return -EINVAL;
}
}
if (op & QAM_SET_OP_ALL) {
rc = drxj_dap_write_reg16(dev_addr, FEC_COMM_EXEC__A, FEC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_COMM_EXEC__A, QAM_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_COMM_EXEC__A, IQM_FS_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FD_COMM_EXEC__A, IQM_FD_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_COMM_EXEC__A, IQM_RC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RT_COMM_EXEC__A, IQM_RT_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_COMM_EXEC__A, IQM_CF_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_QAM |
SCU_RAM_COMMAND_CMD_DEMOD_RESET;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if ((op & QAM_SET_OP_ALL) || (op & QAM_SET_OP_CONSTELLATION)) {
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_QAM |
SCU_RAM_COMMAND_CMD_DEMOD_SET_ENV;
cmd_scu.parameter_len = 1;
cmd_scu.result_len = 1;
cmd_scu.parameter = &set_env_parameters;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_QAM |
SCU_RAM_COMMAND_CMD_DEMOD_SET_PARAM;
cmd_scu.parameter_len = 2;
cmd_scu.result_len = 1;
cmd_scu.parameter = set_param_parameters;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_reg32(dev_addr, IQM_RC_RATE_OFS_LO__A, iqm_rc_rate, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->iqm_rc_rate_ofs = iqm_rc_rate;
rc = set_qam_measurement(demod, channel->constellation, channel->symbolrate);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if ((op & QAM_SET_OP_ALL) || (op & QAM_SET_OP_SPECTRUM)) {
rc = set_frequency(demod, channel, tuner_freq_offset);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if ((op & QAM_SET_OP_ALL) || (op & QAM_SET_OP_CONSTELLATION)) {
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_SYMBOL_FREQ__A, lc_symbol_freq, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_STRETCH__A, iqm_rc_stretch, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if (op & QAM_SET_OP_ALL) {
if (!ext_attr->has_lna) {
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_AMUX__A, 0x02, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_SYMMETRIC__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_MIDTAP__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_OUT_ENA__A, IQM_CF_OUT_ENA_QAM__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_WR_RSV_0__A, 0x5f, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_SYNC_SEL__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_CLP_LEN__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_CLP_TH__A, 448, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_SNS_LEN__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_PDREF__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_STDBY__A, 0x10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_PGA_GAIN__A, 11, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_POW_MEAS_LEN__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_SCALE_SH__A, IQM_CF_SCALE_SH__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_TIMEOUT__A, QAM_SY_TIMEOUT__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (ext_attr->standard == DRX_STANDARD_ITU_B) {
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_LWM__A, QAM_SY_SYNC_LWM__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_AWM__A, QAM_SY_SYNC_AWM__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_HWM__A, QAM_SY_SYNC_HWM__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
switch (channel->constellation) {
case DRX_CONSTELLATION_QAM16:
case DRX_CONSTELLATION_QAM64:
case DRX_CONSTELLATION_QAM256:
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_LWM__A, 0x03, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_AWM__A, 0x04, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_HWM__A, QAM_SY_SYNC_HWM__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_QAM32:
case DRX_CONSTELLATION_QAM128:
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_LWM__A, 0x03, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_AWM__A, 0x05, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_SY_SYNC_HWM__A, 0x06, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EIO;
}
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_MODE__A, QAM_LC_MODE__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_RATE_LIMIT__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_LPF_FACTORP__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_LPF_FACTORI__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_MODE__A, 7, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB0__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB1__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB2__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB3__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB4__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB5__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB6__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB8__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB9__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB10__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB12__A, 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB15__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB16__A, 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB20__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_QUAL_TAB25__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_ADJ_SEL__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_ADJ_SEL__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_ADJ_SEL__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_POW_MEAS_LEN__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_GPIO__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_iqm_af(demod, true);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = adc_synchronization(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = init_agc(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_agc_if(demod, &(ext_attr->qam_if_agc_cfg), false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_agc_rf(demod, &(ext_attr->qam_rf_agc_cfg), false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
{
struct drxj_cfg_afe_gain qam_pga_cfg = { DRX_STANDARD_ITU_B, 0 };
qam_pga_cfg.gain = ext_attr->qam_pga_cfg;
rc = ctrl_set_cfg_afe_gain(demod, &qam_pga_cfg);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = ctrl_set_cfg_pre_saw(demod, &(ext_attr->qam_pre_saw_cfg));
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if ((op & QAM_SET_OP_ALL) || (op & QAM_SET_OP_CONSTELLATION)) {
if (ext_attr->standard == DRX_STANDARD_ITU_A) {
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_RE0__A, sizeof(qam_a_taps), ((u8 *)qam_a_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_IM0__A, sizeof(qam_a_taps), ((u8 *)qam_a_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else if (ext_attr->standard == DRX_STANDARD_ITU_B) {
switch (channel->constellation) {
case DRX_CONSTELLATION_QAM64:
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_RE0__A, sizeof(qam_b64_taps), ((u8 *)qam_b64_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_IM0__A, sizeof(qam_b64_taps), ((u8 *)qam_b64_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_QAM256:
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_RE0__A, sizeof(qam_b256_taps), ((u8 *)qam_b256_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_IM0__A, sizeof(qam_b256_taps), ((u8 *)qam_b256_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EIO;
}
} else if (ext_attr->standard == DRX_STANDARD_ITU_C) {
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_RE0__A, sizeof(qam_c_taps), ((u8 *)qam_c_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, IQM_CF_TAP_IM0__A, sizeof(qam_c_taps), ((u8 *)qam_c_taps), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
switch (channel->constellation) {
case DRX_CONSTELLATION_QAM16:
rc = set_qam16(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_QAM32:
rc = set_qam32(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_QAM64:
rc = set_qam64(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_QAM128:
rc = set_qam128(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_QAM256:
rc = set_qam256(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
return -EIO;
}
}
if ((op & QAM_SET_OP_ALL)) {
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_SCALE_SH__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_mpegtei_handling(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = bit_reverse_mpeg_output(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_mpeg_start_width(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
{
struct drx_cfg_mpeg_output cfg_mpeg_output;
memcpy(&cfg_mpeg_output, &common_attr->mpeg_cfg, sizeof(cfg_mpeg_output));
cfg_mpeg_output.enable_mpeg_output = true;
rc = ctrl_set_cfg_mpeg_output(demod, &cfg_mpeg_output);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
}
if ((op & QAM_SET_OP_ALL) || (op & QAM_SET_OP_CONSTELLATION)) {
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_QAM |
SCU_RAM_COMMAND_CMD_DEMOD_START;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, IQM_COMM_EXEC__A, IQM_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_COMM_EXEC__A, QAM_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, FEC_COMM_EXEC__A, FEC_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int qam_flip_spec(struct drx_demod_instance *demod, struct drx_channel *channel)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drxj_data *ext_attr = demod->my_ext_attr;
int rc;
u32 iqm_fs_rate_ofs = 0;
u32 iqm_fs_rate_lo = 0;
u16 qam_ctl_ena = 0;
u16 data = 0;
u16 equ_mode = 0;
u16 fsm_state = 0;
int i = 0;
int ofsofs = 0;
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_QAM_CTL_ENA__A, &qam_ctl_ena, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_CTL_ENA__A, qam_ctl_ena & ~(SCU_RAM_QAM_CTL_ENA_ACQ__M | SCU_RAM_QAM_CTL_ENA_EQU__M | SCU_RAM_QAM_CTL_ENA_LC__M), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_CF__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_CF1__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_atomic_read_reg32(dev_addr, IQM_FS_RATE_OFS_LO__A, &iqm_fs_rate_ofs, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_atomic_read_reg32(dev_addr, IQM_FS_RATE_LO__A, &iqm_fs_rate_lo, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ofsofs = iqm_fs_rate_lo - iqm_fs_rate_ofs;
iqm_fs_rate_ofs = ~iqm_fs_rate_ofs + 1;
iqm_fs_rate_ofs -= 2 * ofsofs;
rc = drxj_dap_read_reg16(dev_addr, QAM_DQ_MODE__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
data = (data & 0xfff9);
rc = drxj_dap_write_reg16(dev_addr, QAM_DQ_MODE__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_FQ_MODE__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_CI__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_LC_EP__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_FQ_LA_FACTOR__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_reg32(dev_addr, IQM_FS_RATE_OFS_LO__A, iqm_fs_rate_ofs, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->iqm_fs_rate_ofs = iqm_fs_rate_ofs;
ext_attr->pos_image = (ext_attr->pos_image) ? false : true;
rc = drxj_dap_read_reg16(dev_addr, QAM_DQ_MODE__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
equ_mode = data;
data = (data & 0xfff9);
rc = drxj_dap_write_reg16(dev_addr, QAM_DQ_MODE__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_FQ_MODE__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
for (i = 0; i < 28; i++) {
rc = drxj_dap_read_reg16(dev_addr, QAM_DQ_TAP_IM_EL0__A + (2 * i), &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_DQ_TAP_IM_EL0__A + (2 * i), -data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
for (i = 0; i < 24; i++) {
rc = drxj_dap_read_reg16(dev_addr, QAM_FQ_TAP_IM_EL0__A + (2 * i), &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_FQ_TAP_IM_EL0__A + (2 * i), -data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
data = equ_mode;
rc = drxj_dap_write_reg16(dev_addr, QAM_DQ_MODE__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, QAM_FQ_MODE__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_FSM_STATE_TGT__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
i = 0;
while ((fsm_state != 4) && (i++ < 100)) {
rc = drxj_dap_read_reg16(dev_addr, SCU_RAM_QAM_FSM_STATE__A, &fsm_state, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_QAM_CTL_ENA__A, (qam_ctl_ena | 0x0016), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int
qam64auto(struct drx_demod_instance *demod,
struct drx_channel *channel,
s32 tuner_freq_offset, enum drx_lock_status *lock_status)
{
struct drxj_data *ext_attr = demod->my_ext_attr;
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drx39xxj_state *state = dev_addr->user_data;
struct dtv_frontend_properties *p = &state->frontend.dtv_property_cache;
int rc;
u32 lck_state = NO_LOCK;
u32 start_time = 0;
u32 d_locked_time = 0;
u32 timeout_ofs = 0;
u16 data = 0;
*lock_status = DRX_NOT_LOCKED;
start_time = jiffies_to_msecs(jiffies);
lck_state = NO_LOCK;
do {
rc = ctrl_lock_status(demod, lock_status);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
switch (lck_state) {
case NO_LOCK:
if (*lock_status == DRXJ_DEMOD_LOCK) {
rc = ctrl_get_qam_sig_quality(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (p->cnr.stat[0].svalue > 20800) {
lck_state = DEMOD_LOCKED;
timeout_ofs += DRXJ_QAM_DEMOD_LOCK_EXT_WAITTIME;
d_locked_time = jiffies_to_msecs(jiffies);
}
}
break;
case DEMOD_LOCKED:
if ((*lock_status == DRXJ_DEMOD_LOCK) &&
((jiffies_to_msecs(jiffies) - d_locked_time) >
DRXJ_QAM_FEC_LOCK_WAITTIME)) {
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, QAM_SY_TIMEOUT__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, QAM_SY_TIMEOUT__A, data | 0x1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
lck_state = SYNC_FLIPPED;
msleep(10);
}
break;
case SYNC_FLIPPED:
if (*lock_status == DRXJ_DEMOD_LOCK) {
if (channel->mirror == DRX_MIRROR_AUTO) {
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, QAM_SY_TIMEOUT__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, QAM_SY_TIMEOUT__A, data & 0xFFFE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->mirror = DRX_MIRROR_YES;
rc = qam_flip_spec(demod, channel);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
lck_state = SPEC_MIRRORED;
start_time = d_locked_time =
jiffies_to_msecs(jiffies);
timeout_ofs = 0;
} else {
start_time =
jiffies_to_msecs(jiffies) -
DRXJ_QAM_MAX_WAITTIME - timeout_ofs;
}
}
break;
case SPEC_MIRRORED:
if ((*lock_status == DRXJ_DEMOD_LOCK) &&
((jiffies_to_msecs(jiffies) - d_locked_time) >
DRXJ_QAM_FEC_LOCK_WAITTIME)) {
rc = ctrl_get_qam_sig_quality(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (p->cnr.stat[0].svalue > 20800) {
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, QAM_SY_TIMEOUT__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr, QAM_SY_TIMEOUT__A, data | 0x1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
start_time =
jiffies_to_msecs(jiffies) -
DRXJ_QAM_MAX_WAITTIME - timeout_ofs;
}
}
break;
default:
break;
}
msleep(10);
} while
((*lock_status != DRX_LOCKED) &&
(*lock_status != DRX_NEVER_LOCK) &&
((jiffies_to_msecs(jiffies) - start_time) <
(DRXJ_QAM_MAX_WAITTIME + timeout_ofs))
);
return 0;
rw_error:
return rc;
}
static int
qam256auto(struct drx_demod_instance *demod,
struct drx_channel *channel,
s32 tuner_freq_offset, enum drx_lock_status *lock_status)
{
struct drxj_data *ext_attr = demod->my_ext_attr;
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drx39xxj_state *state = dev_addr->user_data;
struct dtv_frontend_properties *p = &state->frontend.dtv_property_cache;
int rc;
u32 lck_state = NO_LOCK;
u32 start_time = 0;
u32 d_locked_time = 0;
u32 timeout_ofs = DRXJ_QAM_DEMOD_LOCK_EXT_WAITTIME;
*lock_status = DRX_NOT_LOCKED;
start_time = jiffies_to_msecs(jiffies);
lck_state = NO_LOCK;
do {
rc = ctrl_lock_status(demod, lock_status);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
switch (lck_state) {
case NO_LOCK:
if (*lock_status == DRXJ_DEMOD_LOCK) {
rc = ctrl_get_qam_sig_quality(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (p->cnr.stat[0].svalue > 26800) {
lck_state = DEMOD_LOCKED;
timeout_ofs += DRXJ_QAM_DEMOD_LOCK_EXT_WAITTIME;
d_locked_time = jiffies_to_msecs(jiffies);
}
}
break;
case DEMOD_LOCKED:
if (*lock_status == DRXJ_DEMOD_LOCK) {
if ((channel->mirror == DRX_MIRROR_AUTO) &&
((jiffies_to_msecs(jiffies) - d_locked_time) >
DRXJ_QAM_FEC_LOCK_WAITTIME)) {
ext_attr->mirror = DRX_MIRROR_YES;
rc = qam_flip_spec(demod, channel);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
lck_state = SPEC_MIRRORED;
start_time = jiffies_to_msecs(jiffies);
timeout_ofs = -DRXJ_QAM_MAX_WAITTIME / 2;
}
}
break;
case SPEC_MIRRORED:
break;
default:
break;
}
msleep(10);
} while
((*lock_status < DRX_LOCKED) &&
(*lock_status != DRX_NEVER_LOCK) &&
((jiffies_to_msecs(jiffies) - start_time) <
(DRXJ_QAM_MAX_WAITTIME + timeout_ofs)));
return 0;
rw_error:
return rc;
}
static int
set_qam_channel(struct drx_demod_instance *demod,
struct drx_channel *channel, s32 tuner_freq_offset)
{
struct drxj_data *ext_attr = NULL;
int rc;
enum drx_lock_status lock_status = DRX_NOT_LOCKED;
bool auto_flag = false;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
switch (channel->constellation) {
case DRX_CONSTELLATION_QAM16:
case DRX_CONSTELLATION_QAM32:
case DRX_CONSTELLATION_QAM128:
return -EINVAL;
case DRX_CONSTELLATION_QAM64:
case DRX_CONSTELLATION_QAM256:
if (ext_attr->standard != DRX_STANDARD_ITU_B)
return -EINVAL;
ext_attr->constellation = channel->constellation;
if (channel->mirror == DRX_MIRROR_AUTO)
ext_attr->mirror = DRX_MIRROR_NO;
else
ext_attr->mirror = channel->mirror;
rc = set_qam(demod, channel, tuner_freq_offset, QAM_SET_OP_ALL);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (channel->constellation == DRX_CONSTELLATION_QAM64)
rc = qam64auto(demod, channel, tuner_freq_offset,
&lock_status);
else
rc = qam256auto(demod, channel, tuner_freq_offset,
&lock_status);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_CONSTELLATION_AUTO:
if (ext_attr->standard == DRX_STANDARD_ITU_B) {
u16 qam_ctl_ena = 0;
auto_flag = true;
channel->constellation = DRX_CONSTELLATION_QAM256;
ext_attr->constellation = DRX_CONSTELLATION_QAM256;
if (channel->mirror == DRX_MIRROR_AUTO)
ext_attr->mirror = DRX_MIRROR_NO;
else
ext_attr->mirror = channel->mirror;
rc = set_qam(demod, channel, tuner_freq_offset,
QAM_SET_OP_ALL);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = qam256auto(demod, channel, tuner_freq_offset,
&lock_status);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (lock_status >= DRX_LOCKED) {
channel->constellation = DRX_CONSTELLATION_AUTO;
break;
}
channel->constellation = DRX_CONSTELLATION_QAM64;
ext_attr->constellation = DRX_CONSTELLATION_QAM64;
if (channel->mirror == DRX_MIRROR_AUTO)
ext_attr->mirror = DRX_MIRROR_NO;
else
ext_attr->mirror = channel->mirror;
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_CTL_ENA__A,
&qam_ctl_ena, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_CTL_ENA__A,
qam_ctl_ena & ~SCU_RAM_QAM_CTL_ENA_ACQ__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_FSM_STATE_TGT__A,
0x2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_qam(demod, channel, tuner_freq_offset,
QAM_SET_OP_CONSTELLATION);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_CTL_ENA__A,
qam_ctl_ena, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = qam64auto(demod, channel, tuner_freq_offset,
&lock_status);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
channel->constellation = DRX_CONSTELLATION_AUTO;
} else if (ext_attr->standard == DRX_STANDARD_ITU_C) {
u16 qam_ctl_ena = 0;
channel->constellation = DRX_CONSTELLATION_QAM64;
ext_attr->constellation = DRX_CONSTELLATION_QAM64;
auto_flag = true;
if (channel->mirror == DRX_MIRROR_AUTO)
ext_attr->mirror = DRX_MIRROR_NO;
else
ext_attr->mirror = channel->mirror;
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_CTL_ENA__A,
&qam_ctl_ena, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_CTL_ENA__A,
qam_ctl_ena & ~SCU_RAM_QAM_CTL_ENA_ACQ__M, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_FSM_STATE_TGT__A,
0x2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_qam(demod, channel, tuner_freq_offset,
QAM_SET_OP_CONSTELLATION);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(demod->my_i2c_dev_addr,
SCU_RAM_QAM_CTL_ENA__A,
qam_ctl_ena, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = qam64auto(demod, channel, tuner_freq_offset,
&lock_status);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
channel->constellation = DRX_CONSTELLATION_AUTO;
} else {
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
rw_error:
if (auto_flag)
channel->constellation = DRX_CONSTELLATION_AUTO;
return rc;
}
static int
get_qamrs_err_count(struct i2c_device_addr *dev_addr,
struct drxjrs_errors *rs_errors)
{
int rc;
u16 nr_bit_errors = 0,
nr_symbol_errors = 0,
nr_packet_errors = 0, nr_failures = 0, nr_snc_par_fail_count = 0;
if (dev_addr == NULL)
return -EINVAL;
rc = drxj_dap_read_reg16(dev_addr, FEC_RS_NR_BIT_ERRORS__A, &nr_bit_errors, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_RS_NR_SYMBOL_ERRORS__A, &nr_symbol_errors, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_RS_NR_PACKET_ERRORS__A, &nr_packet_errors, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_RS_NR_FAILURES__A, &nr_failures, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_SNC_FAIL_COUNT__A, &nr_snc_par_fail_count, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rs_errors->nr_bit_errors = nr_bit_errors & FEC_RS_NR_BIT_ERRORS__M;
rs_errors->nr_symbol_errors = nr_symbol_errors & FEC_RS_NR_SYMBOL_ERRORS__M;
rs_errors->nr_packet_errors = nr_packet_errors & FEC_RS_NR_PACKET_ERRORS__M;
rs_errors->nr_failures = nr_failures & FEC_RS_NR_FAILURES__M;
rs_errors->nr_snc_par_fail_count =
nr_snc_par_fail_count & FEC_OC_SNC_FAIL_COUNT__M;
return 0;
rw_error:
return rc;
}
static int get_sig_strength(struct drx_demod_instance *demod, u16 *sig_strength)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
u16 rf_gain = 0;
u16 if_gain = 0;
u16 if_agc_sns = 0;
u16 if_agc_top = 0;
u16 rf_agc_max = 0;
u16 rf_agc_min = 0;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_AGC_IF__A, &if_gain, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if_gain &= IQM_AF_AGC_IF__M;
rc = drxj_dap_read_reg16(dev_addr, IQM_AF_AGC_RF__A, &rf_gain, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rf_gain &= IQM_AF_AGC_RF__M;
if_agc_sns = DRXJ_AGC_SNS;
if_agc_top = DRXJ_AGC_TOP;
rf_agc_max = DRXJ_RFAGC_MAX;
rf_agc_min = DRXJ_RFAGC_MIN;
if (if_gain > if_agc_top) {
if (rf_gain > rf_agc_max)
*sig_strength = 100;
else if (rf_gain > rf_agc_min) {
if (rf_agc_max == rf_agc_min) {
pr_err("error: rf_agc_max == rf_agc_min\n");
return -EIO;
}
*sig_strength =
75 + 25 * (rf_gain - rf_agc_min) / (rf_agc_max -
rf_agc_min);
} else
*sig_strength = 75;
} else if (if_gain > if_agc_sns) {
if (if_agc_top == if_agc_sns) {
pr_err("error: if_agc_top == if_agc_sns\n");
return -EIO;
}
*sig_strength =
20 + 55 * (if_gain - if_agc_sns) / (if_agc_top - if_agc_sns);
} else {
if (!if_agc_sns) {
pr_err("error: if_agc_sns is zero!\n");
return -EIO;
}
*sig_strength = (20 * if_gain / if_agc_sns);
}
if (*sig_strength <= 7)
*sig_strength = 0;
return 0;
rw_error:
return rc;
}
static int
ctrl_get_qam_sig_quality(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drxj_data *ext_attr = demod->my_ext_attr;
struct drx39xxj_state *state = dev_addr->user_data;
struct dtv_frontend_properties *p = &state->frontend.dtv_property_cache;
struct drxjrs_errors measuredrs_errors = { 0, 0, 0, 0, 0 };
enum drx_modulation constellation = ext_attr->constellation;
int rc;
u32 pre_bit_err_rs = 0;
u32 post_bit_err_rs = 0;
u32 pkt_errs = 0;
u16 qam_sl_err_power = 0;
u16 qsym_err_vd = 0;
u16 fec_oc_period = 0;
u16 fec_rs_prescale = 0;
u16 fec_rs_period = 0;
u32 rs_bit_cnt = 0;
u32 qam_sl_sig_power = 0;
u32 e = 0;
u32 m = 0;
u32 ber_cnt = 0;
u32 qam_sl_mer = 0;
u32 qam_pre_rs_ber = 0;
u32 qam_post_rs_ber = 0;
u32 qam_vd_ser = 0;
u16 qam_vd_prescale = 0;
u16 qam_vd_period = 0;
u32 vd_bit_cnt = 0;
p->block_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
rc = get_qamrs_err_count(dev_addr, &measuredrs_errors);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, QAM_SL_ERR_POWER__A, &qam_sl_err_power, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_read_reg16(dev_addr, FEC_OC_SNC_FAIL_PERIOD__A, &fec_oc_period, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
fec_rs_period = ext_attr->fec_rs_period;
fec_rs_prescale = ext_attr->fec_rs_prescale;
rs_bit_cnt = fec_rs_period * fec_rs_prescale * ext_attr->fec_rs_plen;
qam_vd_period = ext_attr->qam_vd_period;
qam_vd_prescale = ext_attr->qam_vd_prescale;
vd_bit_cnt = qam_vd_period * qam_vd_prescale * ext_attr->fec_vd_plen;
switch (constellation) {
case DRX_CONSTELLATION_QAM16:
qam_sl_sig_power = DRXJ_QAM_SL_SIG_POWER_QAM16 << 2;
break;
case DRX_CONSTELLATION_QAM32:
qam_sl_sig_power = DRXJ_QAM_SL_SIG_POWER_QAM32 << 2;
break;
case DRX_CONSTELLATION_QAM64:
qam_sl_sig_power = DRXJ_QAM_SL_SIG_POWER_QAM64 << 2;
break;
case DRX_CONSTELLATION_QAM128:
qam_sl_sig_power = DRXJ_QAM_SL_SIG_POWER_QAM128 << 2;
break;
case DRX_CONSTELLATION_QAM256:
qam_sl_sig_power = DRXJ_QAM_SL_SIG_POWER_QAM256 << 2;
break;
default:
return -EIO;
}
if (qam_sl_err_power == 0)
qam_sl_mer = 0;
else
qam_sl_mer = log1_times100(qam_sl_sig_power) - log1_times100((u32)qam_sl_err_power);
rc = drxj_dap_read_reg16(dev_addr, QAM_VD_NR_QSYM_ERRORS__A, &qsym_err_vd, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
e = (qsym_err_vd & QAM_VD_NR_QSYM_ERRORS_EXP__M) >>
QAM_VD_NR_QSYM_ERRORS_EXP__B;
m = (qsym_err_vd & QAM_VD_NR_SYMBOL_ERRORS_FIXED_MANT__M) >>
QAM_VD_NR_SYMBOL_ERRORS_FIXED_MANT__B;
if ((m << e) >> 3 > 549752)
qam_vd_ser = 500000 * vd_bit_cnt * ((e > 2) ? 1 : 8) / 8;
else
qam_vd_ser = m << ((e > 2) ? (e - 3) : e);
pre_bit_err_rs = (u32) measuredrs_errors.nr_bit_errors;
pkt_errs = post_bit_err_rs = (u32) measuredrs_errors.nr_snc_par_fail_count;
e = (pre_bit_err_rs & FEC_RS_NR_BIT_ERRORS_EXP__M) >>
FEC_RS_NR_BIT_ERRORS_EXP__B;
m = (pre_bit_err_rs & FEC_RS_NR_BIT_ERRORS_FIXED_MANT__M) >>
FEC_RS_NR_BIT_ERRORS_FIXED_MANT__B;
ber_cnt = m << e;
if (m > (rs_bit_cnt >> (e + 1)) || (rs_bit_cnt >> e) == 0)
qam_pre_rs_ber = 500000 * rs_bit_cnt >> e;
else
qam_pre_rs_ber = ber_cnt;
e = post_bit_err_rs * 742686;
m = fec_oc_period * 100;
if (fec_oc_period == 0)
qam_post_rs_ber = 0xFFFFFFFF;
else
qam_post_rs_ber = e / m;
p->pre_bit_count.stat[0].scale = FE_SCALE_COUNTER;
p->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
p->pre_bit_error.stat[0].scale = FE_SCALE_COUNTER;
p->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
p->block_error.stat[0].scale = FE_SCALE_COUNTER;
p->cnr.stat[0].scale = FE_SCALE_DECIBEL;
p->cnr.stat[0].svalue = ((u16) qam_sl_mer) * 100;
if (ext_attr->standard == DRX_STANDARD_ITU_B) {
p->pre_bit_error.stat[0].uvalue += qam_vd_ser;
p->pre_bit_count.stat[0].uvalue += vd_bit_cnt * ((e > 2) ? 1 : 8) / 8;
} else {
p->pre_bit_error.stat[0].uvalue += qam_pre_rs_ber;
p->pre_bit_count.stat[0].uvalue += rs_bit_cnt >> e;
}
p->post_bit_error.stat[0].uvalue += qam_post_rs_ber;
p->post_bit_count.stat[0].uvalue += rs_bit_cnt >> e;
p->block_error.stat[0].uvalue += pkt_errs;
#ifdef DRXJ_SIGNAL_ACCUM_ERR
rc = get_acc_pkt_err(demod, &sig_quality->packet_error);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
#endif
return 0;
rw_error:
p->pre_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->pre_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
return rc;
}
static int
power_down_atv(struct drx_demod_instance *demod, enum drx_standard standard, bool primary)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drxjscu_cmd cmd_scu = { 0,
0,
0,
NULL,
NULL
};
int rc;
u16 cmd_result = 0;
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_ATV |
SCU_RAM_COMMAND_CMD_DEMOD_STOP;
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 1;
cmd_scu.parameter = NULL;
cmd_scu.result = &cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ATV_TOP_STDBY__A, (ATV_TOP_STDBY_SIF_STDBY_STANDBY & (~ATV_TOP_STDBY_CVBS_STDBY_A2_ACTIVE)), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ATV_COMM_EXEC__A, ATV_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (primary) {
rc = drxj_dap_write_reg16(dev_addr, IQM_COMM_EXEC__A, IQM_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_iqm_af(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} else {
rc = drxj_dap_write_reg16(dev_addr, IQM_FS_COMM_EXEC__A, IQM_FS_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_FD_COMM_EXEC__A, IQM_FD_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RC_COMM_EXEC__A, IQM_RC_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_RT_COMM_EXEC__A, IQM_RT_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, IQM_CF_COMM_EXEC__A, IQM_CF_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = power_down_aud(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int power_down_aud(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
int rc;
dev_addr = (struct i2c_device_addr *)demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
rc = drxj_dap_write_reg16(dev_addr, AUD_COMM_EXEC__A, AUD_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->aud_data.audio_is_active = false;
return 0;
rw_error:
return rc;
}
static int set_orx_nsu_aox(struct drx_demod_instance *demod, bool active)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
u16 data = 0;
rc = drxj_dap_read_reg16(dev_addr, ORX_NSU_AOX_STDBY_W__A, &data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (!active)
data &= ((~ORX_NSU_AOX_STDBY_W_STDBYADC_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYAMP_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYBIAS_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYPLL_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYPD_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYTAGC_IF_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYTAGC_RF_A2_ON) & (~ORX_NSU_AOX_STDBY_W_STDBYFLT_A2_ON));
else
data |= (ORX_NSU_AOX_STDBY_W_STDBYADC_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYAMP_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYBIAS_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYPLL_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYPD_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYTAGC_IF_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYTAGC_RF_A2_ON | ORX_NSU_AOX_STDBY_W_STDBYFLT_A2_ON);
rc = drxj_dap_write_reg16(dev_addr, ORX_NSU_AOX_STDBY_W__A, data, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
return 0;
rw_error:
return rc;
}
static int ctrl_set_oob(struct drx_demod_instance *demod, struct drxoob *oob_param)
{
int rc;
s32 freq = 0;
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
u16 i = 0;
bool mirror_freq_spect_oob = false;
u16 trk_filter_value = 0;
struct drxjscu_cmd scu_cmd;
u16 set_param_parameters[3];
u16 cmd_result[2] = { 0, 0 };
s16 nyquist_coeffs[4][(NYQFILTERLEN + 1) / 2] = {
IMPULSE_COSINE_ALPHA_0_3,
IMPULSE_COSINE_ALPHA_0_3,
IMPULSE_COSINE_ALPHA_0_5,
IMPULSE_COSINE_ALPHA_RO_0_5
};
u8 mode_val[4] = { 2, 2, 0, 1 };
u8 pfi_coeffs[4][6] = {
{DRXJ_16TO8(-92), DRXJ_16TO8(-108), DRXJ_16TO8(100)},
{DRXJ_16TO8(-64), DRXJ_16TO8(-80), DRXJ_16TO8(80)},
{DRXJ_16TO8(-80), DRXJ_16TO8(-98), DRXJ_16TO8(92)},
{DRXJ_16TO8(-80), DRXJ_16TO8(-98), DRXJ_16TO8(92)}
};
u16 mode_index;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
mirror_freq_spect_oob = ext_attr->mirror_freq_spect_oob;
if (oob_param == NULL) {
scu_cmd.command = SCU_RAM_COMMAND_STANDARD_OOB
| SCU_RAM_COMMAND_CMD_DEMOD_STOP;
scu_cmd.parameter_len = 0;
scu_cmd.result_len = 1;
scu_cmd.result = cmd_result;
rc = scu_command(dev_addr, &scu_cmd);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_orx_nsu_aox(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_COMM_EXEC__A, ORX_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->oob_power_on = false;
return 0;
}
freq = oob_param->frequency;
if ((freq < 70000) || (freq > 130000))
return -EIO;
freq = (freq - 50000) / 50;
{
u16 index = 0;
u16 remainder = 0;
u16 *trk_filtercfg = ext_attr->oob_trk_filter_cfg;
index = (u16) ((freq - 400) / 200);
remainder = (u16) ((freq - 400) % 200);
trk_filter_value =
trk_filtercfg[index] - (trk_filtercfg[index] -
trk_filtercfg[index +
1]) / 10 * remainder /
20;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_COMM_EXEC__A, ORX_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
scu_cmd.command = SCU_RAM_COMMAND_STANDARD_OOB
| SCU_RAM_COMMAND_CMD_DEMOD_STOP;
scu_cmd.parameter_len = 0;
scu_cmd.result_len = 1;
scu_cmd.result = cmd_result;
rc = scu_command(dev_addr, &scu_cmd);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
scu_cmd.command = SCU_RAM_COMMAND_STANDARD_OOB
| SCU_RAM_COMMAND_CMD_DEMOD_RESET;
scu_cmd.parameter_len = 0;
scu_cmd.result_len = 1;
scu_cmd.result = cmd_result;
rc = scu_command(dev_addr, &scu_cmd);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
scu_cmd.command = SCU_RAM_COMMAND_STANDARD_OOB
| SCU_RAM_COMMAND_CMD_DEMOD_SET_ENV;
scu_cmd.parameter_len = 3;
switch (oob_param->standard) {
case DRX_OOB_MODE_A:
if (
((oob_param->spectrum_inverted == true) &&
(!mirror_freq_spect_oob)) |
((oob_param->spectrum_inverted == false) &&
(mirror_freq_spect_oob))
)
set_param_parameters[0] =
SCU_RAM_ORX_RF_RX_DATA_RATE_2048KBPS_INVSPEC;
else
set_param_parameters[0] =
SCU_RAM_ORX_RF_RX_DATA_RATE_2048KBPS_REGSPEC;
break;
case DRX_OOB_MODE_B_GRADE_A:
if (
((oob_param->spectrum_inverted == true) &&
(!mirror_freq_spect_oob)) |
((oob_param->spectrum_inverted == false) &&
(mirror_freq_spect_oob))
)
set_param_parameters[0] =
SCU_RAM_ORX_RF_RX_DATA_RATE_1544KBPS_INVSPEC;
else
set_param_parameters[0] =
SCU_RAM_ORX_RF_RX_DATA_RATE_1544KBPS_REGSPEC;
break;
case DRX_OOB_MODE_B_GRADE_B:
default:
if (
((oob_param->spectrum_inverted == true) &&
(!mirror_freq_spect_oob)) |
((oob_param->spectrum_inverted == false) &&
(mirror_freq_spect_oob))
)
set_param_parameters[0] =
SCU_RAM_ORX_RF_RX_DATA_RATE_3088KBPS_INVSPEC;
else
set_param_parameters[0] =
SCU_RAM_ORX_RF_RX_DATA_RATE_3088KBPS_REGSPEC;
break;
}
set_param_parameters[1] = (u16) (freq & 0xFFFF);
set_param_parameters[2] = trk_filter_value;
scu_cmd.parameter = set_param_parameters;
scu_cmd.result_len = 1;
scu_cmd.result = cmd_result;
mode_index = mode_val[(set_param_parameters[0] & 0xC0) >> 6];
rc = scu_command(dev_addr, &scu_cmd);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, 0xFABA, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_OOB_CRX_CFG__A, OOB_CRX_DRIVE_STRENGTH << SIO_PDR_OOB_CRX_CFG_DRIVE__B | 0x03 << SIO_PDR_OOB_CRX_CFG_MODE__B, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_PDR_OOB_DRX_CFG__A, OOB_DRX_DRIVE_STRENGTH << SIO_PDR_OOB_DRX_CFG_DRIVE__B | 0x03 << SIO_PDR_OOB_DRX_CFG_MODE__B, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_TOP_COMM_KEY__A, 0x0000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_TOP_COMM_KEY__A, 0, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_FWP_AAG_LEN_W__A, 16000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_FWP_AAG_THR_W__A, 40, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_DDC_OFO_SET_W__A, ORX_DDC_OFO_SET_W__PRE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_NSU_AOX_LOPOW_W__A, ext_attr->oob_lo_pow, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_TARGET_MODE__A, SCU_RAM_ORX_TARGET_MODE_2048KBPS_SQRT, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_FREQ_GAIN_CORR__A, SCU_RAM_ORX_FREQ_GAIN_CORR_2048KBPS, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_RST_CPH__A, 0x0001, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_RST_CTI__A, 0x0002, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_RST_KRN__A, 0x0004, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_RST_KRP__A, 0x0008, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_AGN_LOCK_TH__A, 2048 >> 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_AGN_LOCK_TOTH__A, (u16)(-2048), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_AGN_ONLOCK_TTH__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_AGN_UNLOCK_TTH__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_AGN_LOCK_MASK__A, 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_DGN_LOCK_TH__A, 10, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_DGN_LOCK_TOTH__A, (u16)(-2048), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_DGN_ONLOCK_TTH__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_DGN_UNLOCK_TTH__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_DGN_LOCK_MASK__A, 1 << 1, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_FRQ_LOCK_TH__A, 17, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_FRQ_LOCK_TOTH__A, (u16)(-2048), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_FRQ_ONLOCK_TTH__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_FRQ_UNLOCK_TTH__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_FRQ_LOCK_MASK__A, 1 << 2, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_PHA_LOCK_TH__A, 3000, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_PHA_LOCK_TOTH__A, (u16)(-2048), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_PHA_ONLOCK_TTH__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_PHA_UNLOCK_TTH__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_PHA_LOCK_MASK__A, 1 << 3, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_TIM_LOCK_TH__A, 400, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_TIM_LOCK_TOTH__A, (u16)(-2048), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_TIM_ONLOCK_TTH__A, 8, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_TIM_UNLOCK_TTH__A, (u16)(-8), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_TIM_LOCK_MASK__A, 1 << 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_EQU_LOCK_TH__A, 20, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_EQU_LOCK_TOTH__A, (u16)(-2048), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_EQU_ONLOCK_TTH__A, 4, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_EQU_UNLOCK_TTH__A, (u16)(-4), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_ORX_EQU_LOCK_MASK__A, 1 << 5, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxdap_fasi_write_block(dev_addr, ORX_FWP_PFI_A_W__A, sizeof(pfi_coeffs[mode_index]), ((u8 *)pfi_coeffs[mode_index]), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_TOP_MDE_W__A, mode_index, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
for (i = 0; i < (NYQFILTERLEN + 1) / 2; i++) {
rc = drxj_dap_write_reg16(dev_addr, ORX_FWP_NYQ_ADR_W__A, i, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_FWP_NYQ_COF_RW__A, nyquist_coeffs[mode_index][i], 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
rc = drxj_dap_write_reg16(dev_addr, ORX_FWP_NYQ_ADR_W__A, 31, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_COMM_EXEC__A, ORX_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
scu_cmd.command = SCU_RAM_COMMAND_STANDARD_OOB
| SCU_RAM_COMMAND_CMD_DEMOD_START;
scu_cmd.parameter_len = 0;
scu_cmd.result_len = 1;
scu_cmd.result = cmd_result;
rc = scu_command(dev_addr, &scu_cmd);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_orx_nsu_aox(demod, true);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, ORX_NSU_AOX_STHR_W__A, ext_attr->oob_pre_saw, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->oob_power_on = true;
return 0;
rw_error:
return rc;
}
static int
ctrl_set_channel(struct drx_demod_instance *demod, struct drx_channel *channel)
{
int rc;
s32 tuner_freq_offset = 0;
struct drxj_data *ext_attr = NULL;
struct i2c_device_addr *dev_addr = NULL;
enum drx_standard standard = DRX_STANDARD_UNKNOWN;
#ifndef DRXJ_VSB_ONLY
u32 min_symbol_rate = 0;
u32 max_symbol_rate = 0;
int bandwidth_temp = 0;
int bandwidth = 0;
#endif
if ((demod == NULL) || (channel == NULL))
return -EINVAL;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
standard = ext_attr->standard;
switch (standard) {
case DRX_STANDARD_8VSB:
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
#endif
break;
case DRX_STANDARD_UNKNOWN:
default:
return -EINVAL;
}
if ((standard == DRX_STANDARD_ITU_B) ||
(standard == DRX_STANDARD_8VSB) ||
(standard == DRX_STANDARD_NTSC)) {
switch (channel->bandwidth) {
case DRX_BANDWIDTH_6MHZ:
case DRX_BANDWIDTH_UNKNOWN:
channel->bandwidth = DRX_BANDWIDTH_6MHZ;
break;
case DRX_BANDWIDTH_8MHZ:
case DRX_BANDWIDTH_7MHZ:
default:
return -EINVAL;
}
}
#ifndef DRXJ_VSB_ONLY
if ((standard == DRX_STANDARD_ITU_A) ||
(standard == DRX_STANDARD_ITU_C)) {
struct drxuio_cfg uio_cfg = { DRX_UIO1, DRX_UIO_MODE_FIRMWARE_SAW };
int bw_rolloff_factor = 0;
bw_rolloff_factor = (standard == DRX_STANDARD_ITU_A) ? 115 : 113;
min_symbol_rate = DRXJ_QAM_SYMBOLRATE_MIN;
max_symbol_rate = DRXJ_QAM_SYMBOLRATE_MAX;
rc = ctrl_set_uio_cfg(demod, &uio_cfg);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (channel->symbolrate < min_symbol_rate ||
channel->symbolrate > max_symbol_rate) {
return -EINVAL;
}
switch (channel->constellation) {
case DRX_CONSTELLATION_QAM16:
case DRX_CONSTELLATION_QAM32:
case DRX_CONSTELLATION_QAM64:
case DRX_CONSTELLATION_QAM128:
case DRX_CONSTELLATION_QAM256:
bandwidth_temp = channel->symbolrate * bw_rolloff_factor;
bandwidth = bandwidth_temp / 100;
if ((bandwidth_temp % 100) >= 50)
bandwidth++;
if (bandwidth <= 6100000) {
channel->bandwidth = DRX_BANDWIDTH_6MHZ;
} else if ((bandwidth > 6100000)
&& (bandwidth <= 7100000)) {
channel->bandwidth = DRX_BANDWIDTH_7MHZ;
} else if (bandwidth > 7100000) {
channel->bandwidth = DRX_BANDWIDTH_8MHZ;
}
break;
default:
return -EINVAL;
}
}
if (standard == DRX_STANDARD_ITU_B) {
switch (channel->constellation) {
case DRX_CONSTELLATION_AUTO:
case DRX_CONSTELLATION_QAM256:
case DRX_CONSTELLATION_QAM64:
break;
default:
return -EINVAL;
}
switch (channel->interleavemode) {
case DRX_INTERLEAVEMODE_I128_J1:
case DRX_INTERLEAVEMODE_I128_J1_V2:
case DRX_INTERLEAVEMODE_I128_J2:
case DRX_INTERLEAVEMODE_I64_J2:
case DRX_INTERLEAVEMODE_I128_J3:
case DRX_INTERLEAVEMODE_I32_J4:
case DRX_INTERLEAVEMODE_I128_J4:
case DRX_INTERLEAVEMODE_I16_J8:
case DRX_INTERLEAVEMODE_I128_J5:
case DRX_INTERLEAVEMODE_I8_J16:
case DRX_INTERLEAVEMODE_I128_J6:
case DRX_INTERLEAVEMODE_I128_J7:
case DRX_INTERLEAVEMODE_I128_J8:
case DRX_INTERLEAVEMODE_I12_J17:
case DRX_INTERLEAVEMODE_I5_J4:
case DRX_INTERLEAVEMODE_B52_M240:
case DRX_INTERLEAVEMODE_B52_M720:
case DRX_INTERLEAVEMODE_UNKNOWN:
case DRX_INTERLEAVEMODE_AUTO:
break;
default:
return -EINVAL;
}
}
if ((ext_attr->uio_sma_tx_mode) == DRX_UIO_MODE_FIRMWARE_SAW) {
struct drxuio_data uio1 = { DRX_UIO1, false };
switch (channel->bandwidth) {
case DRX_BANDWIDTH_8MHZ:
uio1.value = true;
break;
case DRX_BANDWIDTH_7MHZ:
uio1.value = false;
break;
case DRX_BANDWIDTH_6MHZ:
uio1.value = false;
break;
case DRX_BANDWIDTH_UNKNOWN:
default:
return -EINVAL;
}
rc = ctrl_uio_write(demod, &uio1);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
#endif
rc = drxj_dap_write_reg16(dev_addr, SCU_COMM_EXEC__A, SCU_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
tuner_freq_offset = 0;
switch (standard) {
case DRX_STANDARD_8VSB:
if (channel->mirror == DRX_MIRROR_AUTO)
ext_attr->mirror = DRX_MIRROR_NO;
else
ext_attr->mirror = channel->mirror;
rc = set_vsb(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_frequency(demod, channel, tuner_freq_offset);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
rc = set_qam_channel(demod, channel, tuner_freq_offset);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
#endif
case DRX_STANDARD_UNKNOWN:
default:
return -EIO;
}
ext_attr->reset_pkt_err_acc = true;
return 0;
rw_error:
return rc;
}
static int
ctrl_sig_quality(struct drx_demod_instance *demod,
enum drx_lock_status lock_status)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
struct drxj_data *ext_attr = demod->my_ext_attr;
struct drx39xxj_state *state = dev_addr->user_data;
struct dtv_frontend_properties *p = &state->frontend.dtv_property_cache;
enum drx_standard standard = ext_attr->standard;
int rc;
u32 ber, cnt, err, pkt;
u16 mer, strength = 0;
rc = get_sig_strength(demod, &strength);
if (rc < 0) {
pr_err("error getting signal strength %d\n", rc);
p->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
} else {
p->strength.stat[0].scale = FE_SCALE_RELATIVE;
p->strength.stat[0].uvalue = 65535UL * strength/ 100;
}
switch (standard) {
case DRX_STANDARD_8VSB:
#ifdef DRXJ_SIGNAL_ACCUM_ERR
rc = get_acc_pkt_err(demod, &pkt);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
#endif
if (lock_status != DRXJ_DEMOD_LOCK && lock_status != DRX_LOCKED) {
p->pre_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->pre_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->block_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
} else {
rc = get_vsb_post_rs_pck_err(dev_addr, &err, &pkt);
if (rc != 0) {
pr_err("error %d getting UCB\n", rc);
p->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
} else {
p->block_error.stat[0].scale = FE_SCALE_COUNTER;
p->block_error.stat[0].uvalue += err;
p->block_count.stat[0].scale = FE_SCALE_COUNTER;
p->block_count.stat[0].uvalue += pkt;
}
rc = get_vs_bpre_viterbi_ber(dev_addr, &ber, &cnt);
if (rc != 0) {
pr_err("error %d getting pre-ber\n", rc);
p->pre_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
} else {
p->pre_bit_error.stat[0].scale = FE_SCALE_COUNTER;
p->pre_bit_error.stat[0].uvalue += ber;
p->pre_bit_count.stat[0].scale = FE_SCALE_COUNTER;
p->pre_bit_count.stat[0].uvalue += cnt;
}
rc = get_vs_bpost_viterbi_ber(dev_addr, &ber, &cnt);
if (rc != 0) {
pr_err("error %d getting post-ber\n", rc);
p->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
} else {
p->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
p->post_bit_error.stat[0].uvalue += ber;
p->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
p->post_bit_count.stat[0].uvalue += cnt;
}
rc = get_vsbmer(dev_addr, &mer);
if (rc != 0) {
pr_err("error %d getting MER\n", rc);
p->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
} else {
p->cnr.stat[0].svalue = mer * 100;
p->cnr.stat[0].scale = FE_SCALE_DECIBEL;
}
}
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
rc = ctrl_get_qam_sig_quality(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
#endif
default:
return -EIO;
}
return 0;
rw_error:
return rc;
}
static int
ctrl_lock_status(struct drx_demod_instance *demod, enum drx_lock_status *lock_stat)
{
enum drx_standard standard = DRX_STANDARD_UNKNOWN;
struct drxj_data *ext_attr = NULL;
struct i2c_device_addr *dev_addr = NULL;
struct drxjscu_cmd cmd_scu = { 0,
0,
0,
NULL,
NULL
};
int rc;
u16 cmd_result[2] = { 0, 0 };
u16 demod_lock = SCU_RAM_PARAM_1_RES_DEMOD_GET_LOCK_DEMOD_LOCKED;
if ((demod == NULL) || (lock_stat == NULL))
return -EINVAL;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
standard = ext_attr->standard;
*lock_stat = DRX_NOT_LOCKED;
switch (standard) {
case DRX_STANDARD_8VSB:
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_VSB |
SCU_RAM_COMMAND_CMD_DEMOD_GET_LOCK;
demod_lock |= 0x6;
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
cmd_scu.command = SCU_RAM_COMMAND_STANDARD_QAM |
SCU_RAM_COMMAND_CMD_DEMOD_GET_LOCK;
break;
#endif
case DRX_STANDARD_UNKNOWN:
default:
return -EIO;
}
cmd_scu.parameter_len = 0;
cmd_scu.result_len = 2;
cmd_scu.parameter = NULL;
cmd_scu.result = cmd_result;
rc = scu_command(dev_addr, &cmd_scu);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (cmd_scu.result[1] < demod_lock) {
*lock_stat = DRX_NOT_LOCKED;
} else if (cmd_scu.result[1] < SCU_RAM_PARAM_1_RES_DEMOD_GET_LOCK_LOCKED) {
*lock_stat = DRXJ_DEMOD_LOCK;
} else if (cmd_scu.result[1] <
SCU_RAM_PARAM_1_RES_DEMOD_GET_LOCK_NEVER_LOCK) {
*lock_stat = DRX_LOCKED;
} else {
*lock_stat = DRX_NEVER_LOCK;
}
return 0;
rw_error:
return rc;
}
static int
ctrl_set_standard(struct drx_demod_instance *demod, enum drx_standard *standard)
{
struct drxj_data *ext_attr = NULL;
int rc;
enum drx_standard prev_standard;
if ((standard == NULL) || (demod == NULL))
return -EINVAL;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
prev_standard = ext_attr->standard;
switch (prev_standard) {
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
rc = power_down_qam(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
#endif
case DRX_STANDARD_8VSB:
rc = power_down_vsb(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_STANDARD_UNKNOWN:
break;
case DRX_STANDARD_AUTO:
default:
return -EINVAL;
}
ext_attr->standard = *standard;
switch (*standard) {
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
do {
u16 dummy;
rc = drxj_dap_read_reg16(demod->my_i2c_dev_addr, SCU_RAM_VERSION_HI__A, &dummy, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
} while (0);
break;
#endif
case DRX_STANDARD_8VSB:
rc = set_vsb_leak_n_gain(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
default:
ext_attr->standard = DRX_STANDARD_UNKNOWN;
return -EINVAL;
break;
}
return 0;
rw_error:
ext_attr->standard = DRX_STANDARD_UNKNOWN;
return rc;
}
static void drxj_reset_mode(struct drxj_data *ext_attr)
{
if (ext_attr->has_lna) {
#ifndef DRXJ_VSB_ONLY
ext_attr->qam_if_agc_cfg.standard = DRX_STANDARD_ITU_B;
ext_attr->qam_if_agc_cfg.ctrl_mode = DRX_AGC_CTRL_OFF;
ext_attr->qam_pga_cfg = 140 + (11 * 13);
#endif
ext_attr->vsb_if_agc_cfg.standard = DRX_STANDARD_8VSB;
ext_attr->vsb_if_agc_cfg.ctrl_mode = DRX_AGC_CTRL_OFF;
ext_attr->vsb_pga_cfg = 140 + (11 * 13);
} else {
#ifndef DRXJ_VSB_ONLY
ext_attr->qam_if_agc_cfg.standard = DRX_STANDARD_ITU_B;
ext_attr->qam_if_agc_cfg.ctrl_mode = DRX_AGC_CTRL_AUTO;
ext_attr->qam_if_agc_cfg.min_output_level = 0;
ext_attr->qam_if_agc_cfg.max_output_level = 0x7FFF;
ext_attr->qam_if_agc_cfg.speed = 3;
ext_attr->qam_if_agc_cfg.top = 1297;
ext_attr->qam_pga_cfg = 140;
#endif
ext_attr->vsb_if_agc_cfg.standard = DRX_STANDARD_8VSB;
ext_attr->vsb_if_agc_cfg.ctrl_mode = DRX_AGC_CTRL_AUTO;
ext_attr->vsb_if_agc_cfg.min_output_level = 0;
ext_attr->vsb_if_agc_cfg.max_output_level = 0x7FFF;
ext_attr->vsb_if_agc_cfg.speed = 3;
ext_attr->vsb_if_agc_cfg.top = 1024;
ext_attr->vsb_pga_cfg = 140;
}
#ifndef DRXJ_VSB_ONLY
ext_attr->qam_rf_agc_cfg.standard = DRX_STANDARD_ITU_B;
ext_attr->qam_rf_agc_cfg.ctrl_mode = DRX_AGC_CTRL_AUTO;
ext_attr->qam_rf_agc_cfg.min_output_level = 0;
ext_attr->qam_rf_agc_cfg.max_output_level = 0x7FFF;
ext_attr->qam_rf_agc_cfg.speed = 3;
ext_attr->qam_rf_agc_cfg.top = 9500;
ext_attr->qam_rf_agc_cfg.cut_off_current = 4000;
ext_attr->qam_pre_saw_cfg.standard = DRX_STANDARD_ITU_B;
ext_attr->qam_pre_saw_cfg.reference = 0x07;
ext_attr->qam_pre_saw_cfg.use_pre_saw = true;
#endif
ext_attr->vsb_rf_agc_cfg.standard = DRX_STANDARD_8VSB;
ext_attr->vsb_rf_agc_cfg.ctrl_mode = DRX_AGC_CTRL_AUTO;
ext_attr->vsb_rf_agc_cfg.min_output_level = 0;
ext_attr->vsb_rf_agc_cfg.max_output_level = 0x7FFF;
ext_attr->vsb_rf_agc_cfg.speed = 3;
ext_attr->vsb_rf_agc_cfg.top = 9500;
ext_attr->vsb_rf_agc_cfg.cut_off_current = 4000;
ext_attr->vsb_pre_saw_cfg.standard = DRX_STANDARD_8VSB;
ext_attr->vsb_pre_saw_cfg.reference = 0x07;
ext_attr->vsb_pre_saw_cfg.use_pre_saw = true;
}
static int
ctrl_power_mode(struct drx_demod_instance *demod, enum drx_power_mode *mode)
{
struct drx_common_attr *common_attr = (struct drx_common_attr *) NULL;
struct drxj_data *ext_attr = (struct drxj_data *) NULL;
struct i2c_device_addr *dev_addr = (struct i2c_device_addr *)NULL;
int rc;
u16 sio_cc_pwd_mode = 0;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
dev_addr = demod->my_i2c_dev_addr;
if (mode == NULL)
return -EINVAL;
if (common_attr->current_power_mode == *mode)
return 0;
switch (*mode) {
case DRX_POWER_UP:
case DRXJ_POWER_DOWN_MAIN_PATH:
sio_cc_pwd_mode = SIO_CC_PWD_MODE_LEVEL_NONE;
break;
case DRXJ_POWER_DOWN_CORE:
sio_cc_pwd_mode = SIO_CC_PWD_MODE_LEVEL_CLOCK;
break;
case DRXJ_POWER_DOWN_PLL:
sio_cc_pwd_mode = SIO_CC_PWD_MODE_LEVEL_PLL;
break;
case DRX_POWER_DOWN:
sio_cc_pwd_mode = SIO_CC_PWD_MODE_LEVEL_OSC;
break;
default:
return -EINVAL;
break;
}
if ((common_attr->current_power_mode != DRX_POWER_UP)) {
rc = power_up_device(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
if ((*mode == DRX_POWER_UP)) {
drxj_reset_mode(ext_attr);
} else {
switch (ext_attr->standard) {
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
rc = power_down_qam(demod, true);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_STANDARD_8VSB:
rc = power_down_vsb(demod, true);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_STANDARD_PAL_SECAM_BG:
case DRX_STANDARD_PAL_SECAM_DK:
case DRX_STANDARD_PAL_SECAM_I:
case DRX_STANDARD_PAL_SECAM_L:
case DRX_STANDARD_PAL_SECAM_LP:
case DRX_STANDARD_NTSC:
case DRX_STANDARD_FM:
rc = power_down_atv(demod, ext_attr->standard, true);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
break;
case DRX_STANDARD_UNKNOWN:
break;
case DRX_STANDARD_AUTO:
default:
return -EIO;
}
ext_attr->standard = DRX_STANDARD_UNKNOWN;
}
if (*mode != DRXJ_POWER_DOWN_MAIN_PATH) {
rc = drxj_dap_write_reg16(dev_addr, SIO_CC_PWD_MODE__A, sio_cc_pwd_mode, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_CC_UPDATE__A, SIO_CC_UPDATE_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if ((*mode != DRX_POWER_UP)) {
rc = init_hi(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->hi_cfg_ctrl |= SIO_HI_RA_RAM_PAR_5_CFG_SLEEP_ZZZ;
rc = hi_cfg_command(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
}
common_attr->current_power_mode = *mode;
return 0;
rw_error:
return rc;
}
static int
ctrl_set_cfg_pre_saw(struct drx_demod_instance *demod, struct drxj_cfg_pre_saw *pre_saw)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
int rc;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
if ((pre_saw == NULL) || (pre_saw->reference > IQM_AF_PDREF__M)
) {
return -EINVAL;
}
if ((ext_attr->standard == pre_saw->standard) ||
(DRXJ_ISQAMSTD(ext_attr->standard) &&
DRXJ_ISQAMSTD(pre_saw->standard)) ||
(DRXJ_ISATVSTD(ext_attr->standard) &&
DRXJ_ISATVSTD(pre_saw->standard))) {
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_PDREF__A, pre_saw->reference, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
switch (pre_saw->standard) {
case DRX_STANDARD_8VSB:
ext_attr->vsb_pre_saw_cfg = *pre_saw;
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
ext_attr->qam_pre_saw_cfg = *pre_saw;
break;
#endif
default:
return -EINVAL;
}
return 0;
rw_error:
return rc;
}
static int
ctrl_set_cfg_afe_gain(struct drx_demod_instance *demod, struct drxj_cfg_afe_gain *afe_gain)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
int rc;
u8 gain = 0;
if (afe_gain == NULL)
return -EINVAL;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
switch (afe_gain->standard) {
case DRX_STANDARD_8VSB:
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
#endif
break;
default:
return -EINVAL;
}
if (afe_gain->gain >= 329)
gain = 15;
else if (afe_gain->gain <= 147)
gain = 0;
else
gain = (afe_gain->gain - 140 + 6) / 13;
if (ext_attr->standard == afe_gain->standard) {
rc = drxj_dap_write_reg16(dev_addr, IQM_AF_PGA_GAIN__A, gain, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
}
switch (afe_gain->standard) {
case DRX_STANDARD_8VSB:
ext_attr->vsb_pga_cfg = gain * 13 + 140;
break;
#ifndef DRXJ_VSB_ONLY
case DRX_STANDARD_ITU_A:
case DRX_STANDARD_ITU_B:
case DRX_STANDARD_ITU_C:
ext_attr->qam_pga_cfg = gain * 13 + 140;
break;
#endif
default:
return -EIO;
}
return 0;
rw_error:
return rc;
}
static int drxj_open(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = NULL;
struct drxj_data *ext_attr = NULL;
struct drx_common_attr *common_attr = NULL;
u32 driver_version = 0;
struct drxu_code_info ucode_info;
struct drx_cfg_mpeg_output cfg_mpeg_output;
int rc;
enum drx_power_mode power_mode = DRX_POWER_UP;
if ((demod == NULL) ||
(demod->my_common_attr == NULL) ||
(demod->my_ext_attr == NULL) ||
(demod->my_i2c_dev_addr == NULL) ||
(demod->my_common_attr->is_opened)) {
return -EINVAL;
}
if (demod->my_ext_attr == NULL)
return -EINVAL;
dev_addr = demod->my_i2c_dev_addr;
ext_attr = (struct drxj_data *) demod->my_ext_attr;
common_attr = (struct drx_common_attr *) demod->my_common_attr;
rc = ctrl_power_mode(demod, &power_mode);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (power_mode != DRX_POWER_UP) {
rc = -EINVAL;
pr_err("failed to powerup device\n");
goto rw_error;
}
rc = get_device_capabilities(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_CC_SOFT_RST__A, (0x04 | SIO_CC_SOFT_RST_SYS__M | SIO_CC_SOFT_RST_OSC__M), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SIO_CC_UPDATE__A, SIO_CC_UPDATE_KEY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
msleep(1);
rc = drxj_dap_write_reg16(dev_addr, ATV_TOP_STDBY__A, (~ATV_TOP_STDBY_CVBS_STDBY_A2_ACTIVE) | ATV_TOP_STDBY_SIF_STDBY_STANDBY, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_iqm_af(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = set_orx_nsu_aox(demod, false);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = init_hi(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
memcpy(&cfg_mpeg_output, &common_attr->mpeg_cfg, sizeof(cfg_mpeg_output));
cfg_mpeg_output.enable_mpeg_output = false;
rc = ctrl_set_cfg_mpeg_output(demod, &cfg_mpeg_output);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = power_down_aud(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_COMM_EXEC__A, SCU_COMM_EXEC_STOP, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
if (common_attr->microcode_file != NULL) {
common_attr->is_opened = true;
ucode_info.mc_file = common_attr->microcode_file;
if (DRX_ISPOWERDOWNMODE(demod->my_common_attr->current_power_mode)) {
pr_err("Should powerup before loading the firmware.");
return -EINVAL;
}
rc = drx_ctrl_u_code(demod, &ucode_info, UCODE_UPLOAD);
if (rc != 0) {
pr_err("error %d while uploading the firmware\n", rc);
goto rw_error;
}
if (common_attr->verify_microcode == true) {
rc = drx_ctrl_u_code(demod, &ucode_info, UCODE_VERIFY);
if (rc != 0) {
pr_err("error %d while verifying the firmware\n",
rc);
goto rw_error;
}
}
common_attr->is_opened = false;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_COMM_EXEC__A, SCU_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
common_attr->scan_demod_lock_timeout = DRXJ_SCAN_TIMEOUT;
common_attr->scan_desired_lock = DRX_LOCKED;
drxj_reset_mode(ext_attr);
ext_attr->standard = DRX_STANDARD_UNKNOWN;
rc = smart_ant_init(demod);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
driver_version = (VERSION_MAJOR / 100) % 10;
driver_version <<= 4;
driver_version += (VERSION_MAJOR / 10) % 10;
driver_version <<= 4;
driver_version += (VERSION_MAJOR % 10);
driver_version <<= 4;
driver_version += (VERSION_MINOR % 10);
driver_version <<= 4;
driver_version += (VERSION_PATCH / 1000) % 10;
driver_version <<= 4;
driver_version += (VERSION_PATCH / 100) % 10;
driver_version <<= 4;
driver_version += (VERSION_PATCH / 10) % 10;
driver_version <<= 4;
driver_version += (VERSION_PATCH % 10);
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_DRIVER_VER_HI__A, (u16)(driver_version >> 16), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_RAM_DRIVER_VER_LO__A, (u16)(driver_version & 0xFFFF), 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = ctrl_set_oob(demod, NULL);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
ext_attr->aud_data = drxj_default_aud_data_g;
demod->my_common_attr->is_opened = true;
drxj_set_lna_state(demod, false);
return 0;
rw_error:
common_attr->is_opened = false;
return rc;
}
static int drxj_close(struct drx_demod_instance *demod)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
enum drx_power_mode power_mode = DRX_POWER_UP;
if ((demod->my_common_attr == NULL) ||
(demod->my_ext_attr == NULL) ||
(demod->my_i2c_dev_addr == NULL) ||
(!demod->my_common_attr->is_opened)) {
return -EINVAL;
}
rc = ctrl_power_mode(demod, &power_mode);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
rc = drxj_dap_write_reg16(dev_addr, SCU_COMM_EXEC__A, SCU_COMM_EXEC_ACTIVE, 0);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
power_mode = DRX_POWER_DOWN;
rc = ctrl_power_mode(demod, &power_mode);
if (rc != 0) {
pr_err("error %d\n", rc);
goto rw_error;
}
DRX_ATTR_ISOPENED(demod) = false;
return 0;
rw_error:
DRX_ATTR_ISOPENED(demod) = false;
return rc;
}
static u16 drx_u_code_compute_crc(u8 *block_data, u16 nr_words)
{
u16 i = 0;
u16 j = 0;
u32 crc_word = 0;
u32 carry = 0;
while (i < nr_words) {
crc_word |= (u32)be16_to_cpu(*(__be16 *)(block_data));
for (j = 0; j < 16; j++) {
crc_word <<= 1;
if (carry != 0)
crc_word ^= 0x80050000UL;
carry = crc_word & 0x80000000UL;
}
i++;
block_data += (sizeof(u16));
}
return (u16)(crc_word >> 16);
}
static int drx_check_firmware(struct drx_demod_instance *demod, u8 *mc_data,
unsigned size)
{
struct drxu_code_block_hdr block_hdr;
int i;
unsigned count = 2 * sizeof(u16);
u32 mc_dev_type, mc_version, mc_base_version;
u16 mc_nr_of_blks = be16_to_cpu(*(__be16 *)(mc_data + sizeof(u16)));
DRX_ATTR_MCRECORD(demod).aux_type = 0;
DRX_ATTR_MCRECORD(demod).mc_dev_type = 0;
DRX_ATTR_MCRECORD(demod).mc_version = 0;
DRX_ATTR_MCRECORD(demod).mc_base_version = 0;
for (i = 0; i < mc_nr_of_blks; i++) {
if (count + 3 * sizeof(u16) + sizeof(u32) > size)
goto eof;
block_hdr.addr = be32_to_cpu(*(__be32 *)(mc_data + count));
count += sizeof(u32);
block_hdr.size = be16_to_cpu(*(__be16 *)(mc_data + count));
count += sizeof(u16);
block_hdr.flags = be16_to_cpu(*(__be16 *)(mc_data + count));
count += sizeof(u16);
block_hdr.CRC = be16_to_cpu(*(__be16 *)(mc_data + count));
count += sizeof(u16);
pr_debug("%u: addr %u, size %u, flags 0x%04x, CRC 0x%04x\n",
count, block_hdr.addr, block_hdr.size, block_hdr.flags,
block_hdr.CRC);
if (block_hdr.flags & 0x8) {
u8 *auxblk = ((void *)mc_data) + block_hdr.addr;
u16 auxtype;
if (block_hdr.addr + sizeof(u16) > size)
goto eof;
auxtype = be16_to_cpu(*(__be16 *)(auxblk));
if (DRX_ISMCVERTYPE(auxtype)) {
if (block_hdr.addr + 2 * sizeof(u16) + 2 * sizeof (u32) > size)
goto eof;
auxblk += sizeof(u16);
mc_dev_type = be32_to_cpu(*(__be32 *)(auxblk));
auxblk += sizeof(u32);
mc_version = be32_to_cpu(*(__be32 *)(auxblk));
auxblk += sizeof(u32);
mc_base_version = be32_to_cpu(*(__be32 *)(auxblk));
DRX_ATTR_MCRECORD(demod).aux_type = auxtype;
DRX_ATTR_MCRECORD(demod).mc_dev_type = mc_dev_type;
DRX_ATTR_MCRECORD(demod).mc_version = mc_version;
DRX_ATTR_MCRECORD(demod).mc_base_version = mc_base_version;
pr_info("Firmware dev %x, ver %x, base ver %x\n",
mc_dev_type, mc_version, mc_base_version);
}
} else if (count + block_hdr.size * sizeof(u16) > size)
goto eof;
count += block_hdr.size * sizeof(u16);
}
return 0;
eof:
pr_err("Firmware is truncated at pos %u/%u\n", count, size);
return -EINVAL;
}
static int drx_ctrl_u_code(struct drx_demod_instance *demod,
struct drxu_code_info *mc_info,
enum drxu_code_action action)
{
struct i2c_device_addr *dev_addr = demod->my_i2c_dev_addr;
int rc;
u16 i = 0;
u16 mc_nr_of_blks = 0;
u16 mc_magic_word = 0;
const u8 *mc_data_init = NULL;
u8 *mc_data = NULL;
unsigned size;
char *mc_file;
if (!mc_info || !mc_info->mc_file)
return -EINVAL;
mc_file = mc_info->mc_file;
if (!demod->firmware) {
const struct firmware *fw = NULL;
rc = request_firmware(&fw, mc_file, demod->i2c->dev.parent);
if (rc < 0) {
pr_err("Couldn't read firmware %s\n", mc_file);
return rc;
}
demod->firmware = fw;
if (demod->firmware->size < 2 * sizeof(u16)) {
rc = -EINVAL;
pr_err("Firmware is too short!\n");
goto release;
}
pr_info("Firmware %s, size %zu\n",
mc_file, demod->firmware->size);
}
mc_data_init = demod->firmware->data;
size = demod->firmware->size;
mc_data = (void *)mc_data_init;
mc_magic_word = be16_to_cpu(*(__be16 *)(mc_data));
mc_data += sizeof(u16);
mc_nr_of_blks = be16_to_cpu(*(__be16 *)(mc_data));
mc_data += sizeof(u16);
if ((mc_magic_word != DRX_UCODE_MAGIC_WORD) || (mc_nr_of_blks == 0)) {
rc = -EINVAL;
pr_err("Firmware magic word doesn't match\n");
goto release;
}
if (action == UCODE_UPLOAD) {
rc = drx_check_firmware(demod, (u8 *)mc_data_init, size);
if (rc)
goto release;
pr_info("Uploading firmware %s\n", mc_file);
} else {
pr_info("Verifying if firmware upload was ok.\n");
}
for (i = 0; i < mc_nr_of_blks; i++) {
struct drxu_code_block_hdr block_hdr;
u16 mc_block_nr_bytes = 0;
block_hdr.addr = be32_to_cpu(*(__be32 *)(mc_data));
mc_data += sizeof(u32);
block_hdr.size = be16_to_cpu(*(__be16 *)(mc_data));
mc_data += sizeof(u16);
block_hdr.flags = be16_to_cpu(*(__be16 *)(mc_data));
mc_data += sizeof(u16);
block_hdr.CRC = be16_to_cpu(*(__be16 *)(mc_data));
mc_data += sizeof(u16);
pr_debug("%u: addr %u, size %u, flags 0x%04x, CRC 0x%04x\n",
(unsigned)(mc_data - mc_data_init), block_hdr.addr,
block_hdr.size, block_hdr.flags, block_hdr.CRC);
if ((block_hdr.size > 0x7FFF) ||
(((block_hdr.flags & DRX_UCODE_CRC_FLAG) != 0) &&
(block_hdr.CRC != drx_u_code_compute_crc(mc_data, block_hdr.size)))
) {
rc = -EINVAL;
pr_err("firmware CRC is wrong\n");
goto release;
}
if (!block_hdr.size)
continue;
mc_block_nr_bytes = block_hdr.size * ((u16) sizeof(u16));
switch (action) {
case UCODE_UPLOAD:
if (drxdap_fasi_write_block(dev_addr,
block_hdr.addr,
mc_block_nr_bytes,
mc_data, 0x0000)) {
rc = -EIO;
pr_err("error writing firmware at pos %u\n",
(unsigned)(mc_data - mc_data_init));
goto release;
}
break;
case UCODE_VERIFY: {
int result = 0;
u8 mc_data_buffer[DRX_UCODE_MAX_BUF_SIZE];
u32 bytes_to_comp = 0;
u32 bytes_left = mc_block_nr_bytes;
u32 curr_addr = block_hdr.addr;
u8 *curr_ptr = mc_data;
while (bytes_left != 0) {
if (bytes_left > DRX_UCODE_MAX_BUF_SIZE)
bytes_to_comp = DRX_UCODE_MAX_BUF_SIZE;
else
bytes_to_comp = bytes_left;
if (drxdap_fasi_read_block(dev_addr,
curr_addr,
(u16)bytes_to_comp,
(u8 *)mc_data_buffer,
0x0000)) {
pr_err("error reading firmware at pos %u\n",
(unsigned)(mc_data - mc_data_init));
return -EIO;
}
result = memcmp(curr_ptr, mc_data_buffer,
bytes_to_comp);
if (result) {
pr_err("error verifying firmware at pos %u\n",
(unsigned)(mc_data - mc_data_init));
return -EIO;
}
curr_addr += ((dr_xaddr_t)(bytes_to_comp / 2));
curr_ptr =&(curr_ptr[bytes_to_comp]);
bytes_left -=((u32) bytes_to_comp);
}
break;
}
default:
return -EINVAL;
break;
}
mc_data += mc_block_nr_bytes;
}
return 0;
release:
release_firmware(demod->firmware);
demod->firmware = NULL;
return rc;
}
static int drxj_set_lna_state(struct drx_demod_instance *demod, bool state)
{
struct drxuio_cfg uio_cfg;
struct drxuio_data uio_data;
int result;
uio_cfg.uio = DRX_UIO1;
uio_cfg.mode = DRX_UIO_MODE_READWRITE;
result = ctrl_set_uio_cfg(demod, &uio_cfg);
if (result) {
pr_err("Failed to setup LNA GPIO!\n");
return result;
}
uio_data.uio = DRX_UIO1;
uio_data.value = state;
result = ctrl_uio_write(demod, &uio_data);
if (result != 0) {
pr_err("Failed to %sable LNA!\n",
state ? "en" : "dis");
return result;
}
return 0;
}
static int drx39xxj_set_powerstate(struct dvb_frontend *fe, int enable)
{
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
int result;
enum drx_power_mode power_mode;
if (enable)
power_mode = DRX_POWER_UP;
else
power_mode = DRX_POWER_DOWN;
result = ctrl_power_mode(demod, &power_mode);
if (result != 0) {
pr_err("Power state change failed\n");
return 0;
}
return 0;
}
static int drx39xxj_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
int result;
enum drx_lock_status lock_status;
*status = 0;
result = ctrl_lock_status(demod, &lock_status);
if (result != 0) {
pr_err("drx39xxj: could not get lock status!\n");
*status = 0;
}
switch (lock_status) {
case DRX_NEVER_LOCK:
*status = 0;
pr_err("drx says NEVER_LOCK\n");
break;
case DRX_NOT_LOCKED:
*status = 0;
break;
case DRX_LOCK_STATE_1:
case DRX_LOCK_STATE_2:
case DRX_LOCK_STATE_3:
case DRX_LOCK_STATE_4:
case DRX_LOCK_STATE_5:
case DRX_LOCK_STATE_6:
case DRX_LOCK_STATE_7:
case DRX_LOCK_STATE_8:
case DRX_LOCK_STATE_9:
*status = FE_HAS_SIGNAL
| FE_HAS_CARRIER | FE_HAS_VITERBI | FE_HAS_SYNC;
break;
case DRX_LOCKED:
*status = FE_HAS_SIGNAL
| FE_HAS_CARRIER
| FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;
break;
default:
pr_err("Lock state unknown %d\n", lock_status);
}
ctrl_sig_quality(demod, lock_status);
return 0;
}
static int drx39xxj_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
if (p->pre_bit_error.stat[0].scale == FE_SCALE_NOT_AVAILABLE) {
*ber = 0;
return 0;
}
if (!p->pre_bit_count.stat[0].uvalue) {
if (!p->pre_bit_error.stat[0].uvalue)
*ber = 0;
else
*ber = 1000000;
} else {
*ber = frac_times1e6(p->pre_bit_error.stat[0].uvalue,
p->pre_bit_count.stat[0].uvalue);
}
return 0;
}
static int drx39xxj_read_signal_strength(struct dvb_frontend *fe,
u16 *strength)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
if (p->strength.stat[0].scale == FE_SCALE_NOT_AVAILABLE) {
*strength = 0;
return 0;
}
*strength = p->strength.stat[0].uvalue;
return 0;
}
static int drx39xxj_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
u64 tmp64;
if (p->cnr.stat[0].scale == FE_SCALE_NOT_AVAILABLE) {
*snr = 0;
return 0;
}
tmp64 = p->cnr.stat[0].svalue;
do_div(tmp64, 10);
*snr = tmp64;
return 0;
}
static int drx39xxj_read_ucblocks(struct dvb_frontend *fe, u32 *ucb)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
if (p->block_error.stat[0].scale == FE_SCALE_NOT_AVAILABLE) {
*ucb = 0;
return 0;
}
*ucb = p->block_error.stat[0].uvalue;
return 0;
}
static int drx39xxj_set_frontend(struct dvb_frontend *fe)
{
#ifdef DJH_DEBUG
int i;
#endif
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
enum drx_standard standard = DRX_STANDARD_8VSB;
struct drx_channel channel;
int result;
static const struct drx_channel def_channel = {
0,
DRX_BANDWIDTH_6MHZ,
DRX_MIRROR_NO,
DRX_CONSTELLATION_AUTO,
DRX_HIERARCHY_UNKNOWN,
DRX_PRIORITY_UNKNOWN,
DRX_CODERATE_UNKNOWN,
DRX_GUARD_UNKNOWN,
DRX_FFTMODE_UNKNOWN,
DRX_CLASSIFICATION_AUTO,
5057000,
DRX_INTERLEAVEMODE_UNKNOWN,
DRX_LDPC_UNKNOWN,
DRX_CARRIER_UNKNOWN,
DRX_FRAMEMODE_UNKNOWN
};
u32 constellation = DRX_CONSTELLATION_AUTO;
drx39xxj_set_powerstate(fe, 1);
if (fe->ops.tuner_ops.set_params) {
u32 int_freq;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.tuner_ops.get_if_frequency) {
fe->ops.tuner_ops.get_if_frequency(fe, &int_freq);
demod->my_common_attr->intermediate_freq = int_freq / 1000;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
switch (p->delivery_system) {
case SYS_ATSC:
standard = DRX_STANDARD_8VSB;
break;
case SYS_DVBC_ANNEX_B:
standard = DRX_STANDARD_ITU_B;
switch (p->modulation) {
case QAM_64:
constellation = DRX_CONSTELLATION_QAM64;
break;
case QAM_256:
constellation = DRX_CONSTELLATION_QAM256;
break;
default:
constellation = DRX_CONSTELLATION_AUTO;
break;
}
break;
default:
return -EINVAL;
}
result = ctrl_set_standard(demod, &standard);
if (result != 0) {
pr_err("Failed to set standard! result=%02x\n",
result);
return -EINVAL;
}
channel = def_channel;
channel.frequency = p->frequency / 1000;
channel.bandwidth = DRX_BANDWIDTH_6MHZ;
channel.constellation = constellation;
result = ctrl_set_channel(demod, &channel);
if (result != 0) {
pr_err("Failed to set channel!\n");
return -EINVAL;
}
drxj_set_lna_state(demod, false);
p->strength.stat[0].scale = FE_SCALE_RELATIVE;
return 0;
}
static int drx39xxj_sleep(struct dvb_frontend *fe)
{
return drx39xxj_set_powerstate(fe, 0);
}
static int drx39xxj_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
bool i2c_gate_state;
int result;
#ifdef DJH_DEBUG
pr_debug("i2c gate call: enable=%d state=%d\n", enable,
state->i2c_gate_open);
#endif
if (enable)
i2c_gate_state = true;
else
i2c_gate_state = false;
if (state->i2c_gate_open == enable) {
return 0;
}
result = ctrl_i2c_bridge(demod, &i2c_gate_state);
if (result != 0) {
pr_err("drx39xxj: could not open i2c gate [%d]\n",
result);
dump_stack();
} else {
state->i2c_gate_open = enable;
}
return 0;
}
static int drx39xxj_init(struct dvb_frontend *fe)
{
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
int rc = 0;
if (fe->exit == DVB_FE_DEVICE_RESUME) {
demod->my_common_attr->is_opened = false;
rc = drxj_open(demod);
if (rc != 0)
pr_err("drx39xxj_init(): DRX open failed rc=%d!\n", rc);
} else
drx39xxj_set_powerstate(fe, 1);
return rc;
}
static int drx39xxj_set_lna(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
struct drxj_data *ext_attr = demod->my_ext_attr;
if (c->lna) {
if (!ext_attr->has_lna) {
pr_err("LNA is not supported on this device!\n");
return -EINVAL;
}
}
return drxj_set_lna_state(demod, c->lna);
}
static int drx39xxj_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void drx39xxj_release(struct dvb_frontend *fe)
{
struct drx39xxj_state *state = fe->demodulator_priv;
struct drx_demod_instance *demod = state->demod;
if (fe->exit != DVB_FE_DEVICE_REMOVED)
drxj_close(demod);
kfree(demod->my_ext_attr);
kfree(demod->my_common_attr);
kfree(demod->my_i2c_dev_addr);
release_firmware(demod->firmware);
kfree(demod);
kfree(state);
}
struct dvb_frontend *drx39xxj_attach(struct i2c_adapter *i2c)
{
struct drx39xxj_state *state = NULL;
struct i2c_device_addr *demod_addr = NULL;
struct drx_common_attr *demod_comm_attr = NULL;
struct drxj_data *demod_ext_attr = NULL;
struct drx_demod_instance *demod = NULL;
struct dtv_frontend_properties *p;
int result;
state = kzalloc(sizeof(struct drx39xxj_state), GFP_KERNEL);
if (state == NULL)
goto error;
demod = kmalloc(sizeof(struct drx_demod_instance), GFP_KERNEL);
if (demod == NULL)
goto error;
demod_addr = kmemdup(&drxj_default_addr_g,
sizeof(struct i2c_device_addr), GFP_KERNEL);
if (demod_addr == NULL)
goto error;
demod_comm_attr = kmemdup(&drxj_default_comm_attr_g,
sizeof(struct drx_common_attr), GFP_KERNEL);
if (demod_comm_attr == NULL)
goto error;
demod_ext_attr = kmemdup(&drxj_data_g, sizeof(struct drxj_data),
GFP_KERNEL);
if (demod_ext_attr == NULL)
goto error;
state->i2c = i2c;
state->demod = demod;
memcpy(demod, &drxj_default_demod_g, sizeof(struct drx_demod_instance));
demod->my_i2c_dev_addr = demod_addr;
demod->my_common_attr = demod_comm_attr;
demod->my_i2c_dev_addr->user_data = state;
demod->my_common_attr->microcode_file = DRX39XX_MAIN_FIRMWARE;
demod->my_common_attr->verify_microcode = true;
demod->my_common_attr->intermediate_freq = 5000;
demod->my_common_attr->current_power_mode = DRX_POWER_DOWN;
demod->my_ext_attr = demod_ext_attr;
((struct drxj_data *)demod_ext_attr)->uio_sma_tx_mode = DRX_UIO_MODE_READWRITE;
demod->i2c = i2c;
result = drxj_open(demod);
if (result != 0) {
pr_err("DRX open failed! Aborting\n");
goto error;
}
memcpy(&state->frontend.ops, &drx39xxj_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
p = &state->frontend.dtv_property_cache;
p->strength.len = 1;
p->pre_bit_count.len = 1;
p->pre_bit_error.len = 1;
p->post_bit_count.len = 1;
p->post_bit_error.len = 1;
p->block_count.len = 1;
p->block_error.len = 1;
p->cnr.len = 1;
p->strength.stat[0].scale = FE_SCALE_RELATIVE;
p->pre_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->pre_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->block_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
p->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
return &state->frontend;
error:
kfree(demod_ext_attr);
kfree(demod_comm_attr);
kfree(demod_addr);
kfree(demod);
kfree(state);
return NULL;
}
