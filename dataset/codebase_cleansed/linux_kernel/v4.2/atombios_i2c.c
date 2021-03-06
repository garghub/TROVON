static int amdgpu_atombios_i2c_process_i2c_ch(struct amdgpu_i2c_chan *chan,
u8 slave_addr, u8 flags,
u8 *buf, u8 num)
{
struct drm_device *dev = chan->dev;
struct amdgpu_device *adev = dev->dev_private;
PROCESS_I2C_CHANNEL_TRANSACTION_PS_ALLOCATION args;
int index = GetIndexIntoMasterTable(COMMAND, ProcessI2cChannelTransaction);
unsigned char *base;
u16 out = cpu_to_le16(0);
int r = 0;
memset(&args, 0, sizeof(args));
mutex_lock(&chan->mutex);
base = (unsigned char *)adev->mode_info.atom_context->scratch;
if (flags & HW_I2C_WRITE) {
if (num > ATOM_MAX_HW_I2C_WRITE) {
DRM_ERROR("hw i2c: tried to write too many bytes (%d vs 3)\n", num);
r = -EINVAL;
goto done;
}
if (buf == NULL)
args.ucRegIndex = 0;
else
args.ucRegIndex = buf[0];
if (num)
num--;
if (num)
memcpy(&out, &buf[1], num);
args.lpI2CDataOut = cpu_to_le16(out);
} else {
if (num > ATOM_MAX_HW_I2C_READ) {
DRM_ERROR("hw i2c: tried to read too many bytes (%d vs 255)\n", num);
r = -EINVAL;
goto done;
}
args.ucRegIndex = 0;
args.lpI2CDataOut = 0;
}
args.ucFlag = flags;
args.ucI2CSpeed = TARGET_HW_I2C_CLOCK;
args.ucTransBytes = num;
args.ucSlaveAddr = slave_addr << 1;
args.ucLineNumber = chan->rec.i2c_id;
amdgpu_atom_execute_table(adev->mode_info.atom_context, index, (uint32_t *)&args);
if (args.ucStatus != HW_ASSISTED_I2C_STATUS_SUCCESS) {
DRM_DEBUG_KMS("hw_i2c error\n");
r = -EIO;
goto done;
}
if (!(flags & HW_I2C_WRITE))
amdgpu_atombios_copy_swap(buf, base, num, false);
done:
mutex_unlock(&chan->mutex);
return r;
}
int amdgpu_atombios_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, int num)
{
struct amdgpu_i2c_chan *i2c = i2c_get_adapdata(i2c_adap);
struct i2c_msg *p;
int i, remaining, current_count, buffer_offset, max_bytes, ret;
u8 flags;
p = &msgs[0];
if ((num == 1) && (p->len == 0)) {
ret = amdgpu_atombios_i2c_process_i2c_ch(i2c,
p->addr, HW_I2C_WRITE,
NULL, 0);
if (ret)
return ret;
else
return num;
}
for (i = 0; i < num; i++) {
p = &msgs[i];
remaining = p->len;
buffer_offset = 0;
if (p->flags & I2C_M_RD) {
max_bytes = ATOM_MAX_HW_I2C_READ;
flags = HW_I2C_READ;
} else {
max_bytes = ATOM_MAX_HW_I2C_WRITE;
flags = HW_I2C_WRITE;
}
while (remaining) {
if (remaining > max_bytes)
current_count = max_bytes;
else
current_count = remaining;
ret = amdgpu_atombios_i2c_process_i2c_ch(i2c,
p->addr, flags,
&p->buf[buffer_offset], current_count);
if (ret)
return ret;
remaining -= current_count;
buffer_offset += current_count;
}
}
return num;
}
u32 amdgpu_atombios_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
