ssize_t
radeon_dp_aux_transfer_native(struct drm_dp_aux *aux, struct drm_dp_aux_msg *msg)
{
struct radeon_i2c_chan *chan =
container_of(aux, struct radeon_i2c_chan, aux);
struct drm_device *dev = chan->dev;
struct radeon_device *rdev = dev->dev_private;
int ret = 0, i;
uint32_t tmp, ack = 0;
int instance = chan->rec.i2c_id & 0xf;
u8 byte;
u8 *buf = msg->buffer;
int retry_count = 0;
int bytes;
int msize;
bool is_write = false;
if (WARN_ON(msg->size > 16))
return -E2BIG;
switch (msg->request & ~DP_AUX_I2C_MOT) {
case DP_AUX_NATIVE_WRITE:
case DP_AUX_I2C_WRITE:
is_write = true;
break;
case DP_AUX_NATIVE_READ:
case DP_AUX_I2C_READ:
break;
default:
return -EINVAL;
}
msize = 0;
bytes = BARE_ADDRESS_SIZE;
if (msg->size) {
msize = msg->size - 1;
bytes++;
if (is_write)
bytes += msg->size;
}
mutex_lock(&chan->mutex);
tmp = RREG32(chan->rec.mask_clk_reg);
tmp |= (1 << 16);
WREG32(chan->rec.mask_clk_reg, tmp);
tmp = RREG32(AUX_CONTROL + aux_offset[instance]);
tmp &= AUX_HPD_SEL(0x7);
tmp |= AUX_HPD_SEL(chan->rec.hpd);
tmp |= AUX_EN | AUX_LS_READ_EN;
WREG32(AUX_CONTROL + aux_offset[instance], tmp);
WREG32(AUX_SW_CONTROL + aux_offset[instance],
AUX_SW_WR_BYTES(bytes));
WREG32(AUX_SW_CONTROL + aux_offset[instance],
AUX_SW_WR_BYTES(bytes));
byte = (msg->request << 4);
WREG32(AUX_SW_DATA + aux_offset[instance],
AUX_SW_DATA_MASK(byte) | AUX_SW_AUTOINCREMENT_DISABLE);
byte = (msg->address >> 8) & 0xff;
WREG32(AUX_SW_DATA + aux_offset[instance],
AUX_SW_DATA_MASK(byte));
byte = msg->address & 0xff;
WREG32(AUX_SW_DATA + aux_offset[instance],
AUX_SW_DATA_MASK(byte));
byte = msize;
WREG32(AUX_SW_DATA + aux_offset[instance],
AUX_SW_DATA_MASK(byte));
if (is_write) {
for (i = 0; i < msg->size; i++) {
WREG32(AUX_SW_DATA + aux_offset[instance],
AUX_SW_DATA_MASK(buf[i]));
}
}
WREG32(AUX_SW_INTERRUPT_CONTROL + aux_offset[instance], AUX_SW_DONE_ACK);
WREG32(AUX_SW_CONTROL + aux_offset[instance],
AUX_SW_WR_BYTES(bytes) | AUX_SW_GO);
do {
tmp = RREG32(AUX_SW_STATUS + aux_offset[instance]);
if (tmp & AUX_SW_DONE) {
break;
}
usleep_range(100, 200);
} while (retry_count++ < 1000);
if (retry_count >= 1000) {
DRM_ERROR("auxch hw never signalled completion, error %08x\n", tmp);
ret = -EIO;
goto done;
}
if (tmp & AUX_SW_RX_TIMEOUT) {
DRM_DEBUG_KMS("dp_aux_ch timed out\n");
ret = -ETIMEDOUT;
goto done;
}
if (tmp & AUX_RX_ERROR_FLAGS) {
DRM_DEBUG_KMS("dp_aux_ch flags not zero: %08x\n", tmp);
ret = -EIO;
goto done;
}
bytes = AUX_SW_REPLY_GET_BYTE_COUNT(tmp);
if (bytes) {
WREG32(AUX_SW_DATA + aux_offset[instance],
AUX_SW_DATA_RW | AUX_SW_AUTOINCREMENT_DISABLE);
tmp = RREG32(AUX_SW_DATA + aux_offset[instance]);
ack = (tmp >> 8) & 0xff;
for (i = 0; i < bytes - 1; i++) {
tmp = RREG32(AUX_SW_DATA + aux_offset[instance]);
if (buf)
buf[i] = (tmp >> 8) & 0xff;
}
if (buf)
ret = bytes - 1;
}
WREG32(AUX_SW_INTERRUPT_CONTROL + aux_offset[instance], AUX_SW_DONE_ACK);
if (is_write)
ret = msg->size;
done:
mutex_unlock(&chan->mutex);
if (ret >= 0)
msg->reply = ack >> 4;
return ret;
}
