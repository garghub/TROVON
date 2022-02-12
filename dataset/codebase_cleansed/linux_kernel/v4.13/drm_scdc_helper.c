ssize_t drm_scdc_read(struct i2c_adapter *adapter, u8 offset, void *buffer,
size_t size)
{
int ret;
struct i2c_msg msgs[2] = {
{
.addr = SCDC_I2C_SLAVE_ADDRESS,
.flags = 0,
.len = 1,
.buf = &offset,
}, {
.addr = SCDC_I2C_SLAVE_ADDRESS,
.flags = I2C_M_RD,
.len = size,
.buf = buffer,
}
};
ret = i2c_transfer(adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
return ret;
if (ret != ARRAY_SIZE(msgs))
return -EPROTO;
return 0;
}
ssize_t drm_scdc_write(struct i2c_adapter *adapter, u8 offset,
const void *buffer, size_t size)
{
struct i2c_msg msg = {
.addr = SCDC_I2C_SLAVE_ADDRESS,
.flags = 0,
.len = 1 + size,
.buf = NULL,
};
void *data;
int err;
data = kmalloc(1 + size, GFP_TEMPORARY);
if (!data)
return -ENOMEM;
msg.buf = data;
memcpy(data, &offset, sizeof(offset));
memcpy(data + 1, buffer, size);
err = i2c_transfer(adapter, &msg, 1);
kfree(data);
if (err < 0)
return err;
if (err != 1)
return -EPROTO;
return 0;
}
bool drm_scdc_get_scrambling_status(struct i2c_adapter *adapter)
{
u8 status;
int ret;
ret = drm_scdc_readb(adapter, SCDC_SCRAMBLER_STATUS, &status);
if (ret < 0) {
DRM_ERROR("Failed to read scrambling status, error %d\n", ret);
return false;
}
return status & SCDC_SCRAMBLING_STATUS;
}
bool drm_scdc_set_scrambling(struct i2c_adapter *adapter, bool enable)
{
u8 config;
int ret;
ret = drm_scdc_readb(adapter, SCDC_TMDS_CONFIG, &config);
if (ret < 0) {
DRM_ERROR("Failed to read tmds config, err=%d\n", ret);
return false;
}
if (enable)
config |= SCDC_SCRAMBLING_ENABLE;
else
config &= ~SCDC_SCRAMBLING_ENABLE;
ret = drm_scdc_writeb(adapter, SCDC_TMDS_CONFIG, config);
if (ret < 0) {
DRM_ERROR("Failed to enable scrambling, error %d\n", ret);
return false;
}
return true;
}
bool drm_scdc_set_high_tmds_clock_ratio(struct i2c_adapter *adapter, bool set)
{
u8 config;
int ret;
ret = drm_scdc_readb(adapter, SCDC_TMDS_CONFIG, &config);
if (ret < 0) {
DRM_ERROR("Failed to read tmds config, err=%d\n", ret);
return false;
}
if (set)
config |= SCDC_TMDS_BIT_CLOCK_RATIO_BY_40;
else
config &= ~SCDC_TMDS_BIT_CLOCK_RATIO_BY_40;
ret = drm_scdc_writeb(adapter, SCDC_TMDS_CONFIG, config);
if (ret < 0) {
DRM_ERROR("Failed to set TMDS clock ratio, error %d\n", ret);
return false;
}
usleep_range(1000, 2000);
return true;
}
