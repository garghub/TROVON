static int bcm2048_send_command(struct bcm2048_device *bdev, unsigned int reg,
unsigned int value)
{
struct i2c_client *client = bdev->client;
u8 data[2];
if (!bdev->power_state) {
dev_err(&bdev->client->dev, "bcm2048: chip not powered!\n");
return -EIO;
}
data[0] = reg & 0xff;
data[1] = value & 0xff;
if (i2c_master_send(client, data, 2) == 2)
return 0;
dev_err(&bdev->client->dev, "BCM I2C error!\n");
dev_err(&bdev->client->dev, "Is Bluetooth up and running?\n");
return -EIO;
}
static int bcm2048_recv_command(struct bcm2048_device *bdev, unsigned int reg,
u8 *value)
{
struct i2c_client *client = bdev->client;
if (!bdev->power_state) {
dev_err(&bdev->client->dev, "bcm2048: chip not powered!\n");
return -EIO;
}
value[0] = i2c_smbus_read_byte_data(client, reg & 0xff);
return 0;
}
static int bcm2048_recv_duples(struct bcm2048_device *bdev, unsigned int reg,
u8 *value, u8 duples)
{
struct i2c_client *client = bdev->client;
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg[2];
u8 buf;
if (!bdev->power_state) {
dev_err(&bdev->client->dev, "bcm2048: chip not powered!\n");
return -EIO;
}
buf = reg & 0xff;
msg[0].addr = client->addr;
msg[0].flags = client->flags & I2C_M_TEN;
msg[0].len = 1;
msg[0].buf = &buf;
msg[1].addr = client->addr;
msg[1].flags = client->flags & I2C_M_TEN;
msg[1].flags |= I2C_M_RD;
msg[1].len = duples;
msg[1].buf = value;
return i2c_transfer(adap, msg, 2);
}
static int bcm2048_set_power_state(struct bcm2048_device *bdev, u8 power)
{
int err = 0;
mutex_lock(&bdev->mutex);
if (power) {
bdev->power_state = BCM2048_POWER_ON;
bdev->cache_fm_rds_system |= BCM2048_FM_ON;
} else {
bdev->cache_fm_rds_system &= ~BCM2048_FM_ON;
}
if (power)
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_RDS_SYSTEM,
bdev->cache_fm_rds_system);
msleep(BCM2048_DEFAULT_POWERING_DELAY);
if (!power)
bdev->power_state = BCM2048_POWER_OFF;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_power_state(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_SYSTEM, &value);
mutex_unlock(&bdev->mutex);
if (!err && (value & BCM2048_FM_ON))
return BCM2048_POWER_ON;
return err;
}
static int bcm2048_set_rds_no_lock(struct bcm2048_device *bdev, u8 rds_on)
{
int err;
u8 flags;
bdev->cache_fm_rds_system &= ~BCM2048_RDS_ON;
if (rds_on) {
bdev->cache_fm_rds_system |= BCM2048_RDS_ON;
bdev->rds_state = BCM2048_RDS_ON;
flags = BCM2048_RDS_FLAG_FIFO_WLINE;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_RDS_MASK1,
flags);
} else {
flags = 0;
bdev->rds_state = 0;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_RDS_MASK1,
flags);
memset(&bdev->rds_info, 0, sizeof(bdev->rds_info));
}
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_RDS_SYSTEM,
bdev->cache_fm_rds_system);
return err;
}
static int bcm2048_get_rds_no_lock(struct bcm2048_device *bdev)
{
int err;
u8 value;
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_SYSTEM, &value);
if (!err && (value & BCM2048_RDS_ON))
return BCM2048_ITEM_ENABLED;
return err;
}
static int bcm2048_set_rds(struct bcm2048_device *bdev, u8 rds_on)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_set_rds_no_lock(bdev, rds_on);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds(struct bcm2048_device *bdev)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_get_rds_no_lock(bdev);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_pi(struct bcm2048_device *bdev)
{
return bdev->rds_info.rds_pi;
}
static int bcm2048_set_fm_automatic_stereo_mono(struct bcm2048_device *bdev,
u8 enabled)
{
int err;
mutex_lock(&bdev->mutex);
bdev->cache_fm_ctrl &= ~BCM2048_STEREO_MONO_AUTO_SELECT;
if (enabled)
bdev->cache_fm_ctrl |= BCM2048_STEREO_MONO_AUTO_SELECT;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_CTRL,
bdev->cache_fm_ctrl);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_set_fm_hi_lo_injection(struct bcm2048_device *bdev,
u8 hi_lo)
{
int err;
mutex_lock(&bdev->mutex);
bdev->cache_fm_ctrl &= ~BCM2048_HI_LO_INJECTION;
if (hi_lo)
bdev->cache_fm_ctrl |= BCM2048_HI_LO_INJECTION;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_CTRL,
bdev->cache_fm_ctrl);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_hi_lo_injection(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_CTRL, &value);
mutex_unlock(&bdev->mutex);
if (!err && (value & BCM2048_HI_LO_INJECTION))
return BCM2048_ITEM_ENABLED;
return err;
}
static int bcm2048_set_fm_frequency(struct bcm2048_device *bdev, u32 frequency)
{
int err;
if (frequency < bdev->region_info.bottom_frequency ||
frequency > bdev->region_info.top_frequency)
return -EDOM;
frequency -= BCM2048_FREQUENCY_BASE;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_FREQ0, lsb(frequency));
err |= bcm2048_send_command(bdev, BCM2048_I2C_FM_FREQ1,
msb(frequency));
if (!err)
bdev->frequency = frequency;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_frequency(struct bcm2048_device *bdev)
{
int err;
u8 lsb, msb;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_FREQ0, &lsb);
err |= bcm2048_recv_command(bdev, BCM2048_I2C_FM_FREQ1, &msb);
mutex_unlock(&bdev->mutex);
if (err)
return err;
err = compose_u16(msb, lsb);
err += BCM2048_FREQUENCY_BASE;
return err;
}
static int bcm2048_set_fm_af_frequency(struct bcm2048_device *bdev,
u32 frequency)
{
int err;
if (frequency < bdev->region_info.bottom_frequency ||
frequency > bdev->region_info.top_frequency)
return -EDOM;
frequency -= BCM2048_FREQUENCY_BASE;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_AF_FREQ0,
lsb(frequency));
err |= bcm2048_send_command(bdev, BCM2048_I2C_FM_AF_FREQ1,
msb(frequency));
if (!err)
bdev->frequency = frequency;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_af_frequency(struct bcm2048_device *bdev)
{
int err;
u8 lsb, msb;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_AF_FREQ0, &lsb);
err |= bcm2048_recv_command(bdev, BCM2048_I2C_FM_AF_FREQ1, &msb);
mutex_unlock(&bdev->mutex);
if (err)
return err;
err = compose_u16(msb, lsb);
err += BCM2048_FREQUENCY_BASE;
return err;
}
static int bcm2048_set_fm_deemphasis(struct bcm2048_device *bdev, int d)
{
int err;
u8 deemphasis;
if (d == BCM2048_DE_EMPHASIS_75us)
deemphasis = BCM2048_DE_EMPHASIS_SELECT;
else
deemphasis = 0;
mutex_lock(&bdev->mutex);
bdev->cache_fm_audio_ctrl0 &= ~BCM2048_DE_EMPHASIS_SELECT;
bdev->cache_fm_audio_ctrl0 |= deemphasis;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0,
bdev->cache_fm_audio_ctrl0);
if (!err)
bdev->region_info.deemphasis = d;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_deemphasis(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0, &value);
mutex_unlock(&bdev->mutex);
if (!err) {
if (value & BCM2048_DE_EMPHASIS_SELECT)
return BCM2048_DE_EMPHASIS_75us;
return BCM2048_DE_EMPHASIS_50us;
}
return err;
}
static int bcm2048_set_region(struct bcm2048_device *bdev, u8 region)
{
int err;
u32 new_frequency = 0;
if (region >= ARRAY_SIZE(region_configs))
return -EINVAL;
mutex_lock(&bdev->mutex);
bdev->region_info = region_configs[region];
mutex_unlock(&bdev->mutex);
if (bdev->frequency < region_configs[region].bottom_frequency ||
bdev->frequency > region_configs[region].top_frequency)
new_frequency = region_configs[region].bottom_frequency;
if (new_frequency > 0) {
err = bcm2048_set_fm_frequency(bdev, new_frequency);
if (err)
goto done;
}
err = bcm2048_set_fm_deemphasis(bdev,
region_configs[region].deemphasis);
done:
return err;
}
static int bcm2048_get_region(struct bcm2048_device *bdev)
{
int err;
mutex_lock(&bdev->mutex);
err = bdev->region_info.region;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_set_mute(struct bcm2048_device *bdev, u16 mute)
{
int err;
mutex_lock(&bdev->mutex);
bdev->cache_fm_audio_ctrl0 &= ~(BCM2048_RF_MUTE | BCM2048_MANUAL_MUTE);
if (mute)
bdev->cache_fm_audio_ctrl0 |= (BCM2048_RF_MUTE |
BCM2048_MANUAL_MUTE);
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0,
bdev->cache_fm_audio_ctrl0);
if (!err)
bdev->mute_state = mute;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_mute(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
if (bdev->power_state) {
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0,
&value);
if (!err)
err = value & (BCM2048_RF_MUTE | BCM2048_MANUAL_MUTE);
} else {
err = bdev->mute_state;
}
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_set_audio_route(struct bcm2048_device *bdev, u8 route)
{
int err;
mutex_lock(&bdev->mutex);
route &= (BCM2048_AUDIO_ROUTE_DAC | BCM2048_AUDIO_ROUTE_I2S);
bdev->cache_fm_audio_ctrl0 &= ~(BCM2048_AUDIO_ROUTE_DAC |
BCM2048_AUDIO_ROUTE_I2S);
bdev->cache_fm_audio_ctrl0 |= route;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0,
bdev->cache_fm_audio_ctrl0);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_audio_route(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0, &value);
mutex_unlock(&bdev->mutex);
if (!err)
return value & (BCM2048_AUDIO_ROUTE_DAC |
BCM2048_AUDIO_ROUTE_I2S);
return err;
}
static int bcm2048_set_dac_output(struct bcm2048_device *bdev, u8 channels)
{
int err;
mutex_lock(&bdev->mutex);
bdev->cache_fm_audio_ctrl0 &= ~(BCM2048_DAC_OUTPUT_LEFT |
BCM2048_DAC_OUTPUT_RIGHT);
bdev->cache_fm_audio_ctrl0 |= channels;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0,
bdev->cache_fm_audio_ctrl0);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_dac_output(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_AUDIO_CTRL0, &value);
mutex_unlock(&bdev->mutex);
if (!err)
return value & (BCM2048_DAC_OUTPUT_LEFT |
BCM2048_DAC_OUTPUT_RIGHT);
return err;
}
static int bcm2048_set_fm_search_rssi_threshold(struct bcm2048_device *bdev,
u8 threshold)
{
int err;
mutex_lock(&bdev->mutex);
threshold &= BCM2048_SEARCH_RSSI_THRESHOLD;
bdev->cache_fm_search_ctrl0 &= ~BCM2048_SEARCH_RSSI_THRESHOLD;
bdev->cache_fm_search_ctrl0 |= threshold;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_SEARCH_CTRL0,
bdev->cache_fm_search_ctrl0);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_search_rssi_threshold(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_SEARCH_CTRL0, &value);
mutex_unlock(&bdev->mutex);
if (!err)
return value & BCM2048_SEARCH_RSSI_THRESHOLD;
return err;
}
static int bcm2048_set_fm_search_mode_direction(struct bcm2048_device *bdev,
u8 direction)
{
int err;
mutex_lock(&bdev->mutex);
bdev->cache_fm_search_ctrl0 &= ~BCM2048_SEARCH_DIRECTION;
if (direction)
bdev->cache_fm_search_ctrl0 |= BCM2048_SEARCH_DIRECTION;
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_SEARCH_CTRL0,
bdev->cache_fm_search_ctrl0);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_search_mode_direction(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_SEARCH_CTRL0, &value);
mutex_unlock(&bdev->mutex);
if (!err && (value & BCM2048_SEARCH_DIRECTION))
return BCM2048_SEARCH_DIRECTION_UP;
return err;
}
static int bcm2048_set_fm_search_tune_mode(struct bcm2048_device *bdev,
u8 mode)
{
int err, timeout, restart_rds = 0;
u8 value, flags;
value = mode & BCM2048_FM_AUTO_SEARCH;
flags = BCM2048_FM_FLAG_SEARCH_TUNE_FINISHED |
BCM2048_FM_FLAG_SEARCH_TUNE_FAIL;
mutex_lock(&bdev->mutex);
if (bcm2048_get_rds_no_lock(bdev)) {
err = bcm2048_set_rds_no_lock(bdev, 0);
if (err)
goto unlock;
restart_rds = 1;
}
err = bcm2048_send_command(bdev, BCM2048_I2C_FM_RDS_MASK0, flags);
if (err)
goto unlock;
bcm2048_send_command(bdev, BCM2048_I2C_FM_SEARCH_TUNE_MODE, value);
if (mode != BCM2048_FM_AUTO_SEARCH_MODE)
timeout = BCM2048_DEFAULT_TIMEOUT;
else
timeout = BCM2048_AUTO_SEARCH_TIMEOUT;
if (!wait_for_completion_timeout(&bdev->compl,
msecs_to_jiffies(timeout)))
dev_err(&bdev->client->dev, "IRQ timeout.\n");
if (value)
if (!bdev->scan_state)
err = -EIO;
unlock:
if (restart_rds)
err |= bcm2048_set_rds_no_lock(bdev, 1);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_search_tune_mode(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_SEARCH_TUNE_MODE,
&value);
mutex_unlock(&bdev->mutex);
if (!err)
return value & BCM2048_FM_AUTO_SEARCH;
return err;
}
static int bcm2048_set_rds_b_block_mask(struct bcm2048_device *bdev, u16 mask)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev,
BCM2048_I2C_RDS_BLKB_MASK0, lsb(mask));
err |= bcm2048_send_command(bdev,
BCM2048_I2C_RDS_BLKB_MASK1, msb(mask));
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_b_block_mask(struct bcm2048_device *bdev)
{
int err;
u8 lsb, msb;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_BLKB_MASK0, &lsb);
err |= bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_BLKB_MASK1, &msb);
mutex_unlock(&bdev->mutex);
if (!err)
return compose_u16(msb, lsb);
return err;
}
static int bcm2048_set_rds_b_block_match(struct bcm2048_device *bdev,
u16 match)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev,
BCM2048_I2C_RDS_BLKB_MATCH0, lsb(match));
err |= bcm2048_send_command(bdev,
BCM2048_I2C_RDS_BLKB_MATCH1, msb(match));
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_b_block_match(struct bcm2048_device *bdev)
{
int err;
u8 lsb, msb;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_BLKB_MATCH0, &lsb);
err |= bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_BLKB_MATCH1, &msb);
mutex_unlock(&bdev->mutex);
if (!err)
return compose_u16(msb, lsb);
return err;
}
static int bcm2048_set_rds_pi_mask(struct bcm2048_device *bdev, u16 mask)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev,
BCM2048_I2C_RDS_PI_MASK0, lsb(mask));
err |= bcm2048_send_command(bdev,
BCM2048_I2C_RDS_PI_MASK1, msb(mask));
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_pi_mask(struct bcm2048_device *bdev)
{
int err;
u8 lsb, msb;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_PI_MASK0, &lsb);
err |= bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_PI_MASK1, &msb);
mutex_unlock(&bdev->mutex);
if (!err)
return compose_u16(msb, lsb);
return err;
}
static int bcm2048_set_rds_pi_match(struct bcm2048_device *bdev, u16 match)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev,
BCM2048_I2C_RDS_PI_MATCH0, lsb(match));
err |= bcm2048_send_command(bdev,
BCM2048_I2C_RDS_PI_MATCH1, msb(match));
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_pi_match(struct bcm2048_device *bdev)
{
int err;
u8 lsb, msb;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_PI_MATCH0, &lsb);
err |= bcm2048_recv_command(bdev,
BCM2048_I2C_RDS_PI_MATCH1, &msb);
mutex_unlock(&bdev->mutex);
if (!err)
return compose_u16(msb, lsb);
return err;
}
static int bcm2048_set_fm_rds_mask(struct bcm2048_device *bdev, u16 mask)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev,
BCM2048_I2C_FM_RDS_MASK0, lsb(mask));
err |= bcm2048_send_command(bdev,
BCM2048_I2C_FM_RDS_MASK1, msb(mask));
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_rds_mask(struct bcm2048_device *bdev)
{
int err;
u8 value0, value1;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_MASK0, &value0);
err |= bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_MASK1, &value1);
mutex_unlock(&bdev->mutex);
if (!err)
return compose_u16(value1, value0);
return err;
}
static int bcm2048_get_fm_rds_flags(struct bcm2048_device *bdev)
{
int err;
u8 value0, value1;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_FLAG0, &value0);
err |= bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_FLAG1, &value1);
mutex_unlock(&bdev->mutex);
if (!err)
return compose_u16(value1, value0);
return err;
}
static int bcm2048_get_region_bottom_frequency(struct bcm2048_device *bdev)
{
return bdev->region_info.bottom_frequency;
}
static int bcm2048_get_region_top_frequency(struct bcm2048_device *bdev)
{
return bdev->region_info.top_frequency;
}
static int bcm2048_set_fm_best_tune_mode(struct bcm2048_device *bdev, u8 mode)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_BEST_TUNE_MODE,
&value);
value &= ~BCM2048_BEST_TUNE_MODE;
if (mode)
value |= BCM2048_BEST_TUNE_MODE;
err |= bcm2048_send_command(bdev, BCM2048_I2C_FM_BEST_TUNE_MODE,
value);
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_fm_best_tune_mode(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_BEST_TUNE_MODE,
&value);
mutex_unlock(&bdev->mutex);
if (!err && (value & BCM2048_BEST_TUNE_MODE))
return BCM2048_ITEM_ENABLED;
return err;
}
static int bcm2048_get_fm_carrier_error(struct bcm2048_device *bdev)
{
int err = 0;
s8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_CARRIER, &value);
mutex_unlock(&bdev->mutex);
if (!err)
return value;
return err;
}
static int bcm2048_get_fm_rssi(struct bcm2048_device *bdev)
{
int err;
s8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_RSSI, &value);
mutex_unlock(&bdev->mutex);
if (!err)
return value;
return err;
}
static int bcm2048_set_rds_wline(struct bcm2048_device *bdev, u8 wline)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_send_command(bdev, BCM2048_I2C_RDS_WLINE, wline);
if (!err)
bdev->fifo_size = wline;
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_wline(struct bcm2048_device *bdev)
{
int err;
u8 value;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_RDS_WLINE, &value);
mutex_unlock(&bdev->mutex);
if (!err) {
bdev->fifo_size = value;
return value;
}
return err;
}
static int bcm2048_checkrev(struct bcm2048_device *bdev)
{
int err;
u8 version;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_REV, &version);
mutex_unlock(&bdev->mutex);
if (!err) {
dev_info(&bdev->client->dev, "BCM2048 Version 0x%x\n",
version);
return version;
}
return err;
}
static int bcm2048_get_rds_rt(struct bcm2048_device *bdev, char *data)
{
int err = 0, i, j = 0, ce = 0, cr = 0;
char data_buffer[BCM2048_MAX_RDS_RT+1];
mutex_lock(&bdev->mutex);
if (!bdev->rds_info.text_len) {
err = -EINVAL;
goto unlock;
}
for (i = 0; i < BCM2048_MAX_RDS_RT; i++) {
if (bdev->rds_info.rds_rt[i]) {
ce = i;
if (bdev->rds_info.rds_rt[i] != 0x0d) {
data_buffer[j++] = bdev->rds_info.rds_rt[i];
} else {
cr = i;
break;
}
}
}
if (j <= BCM2048_MAX_RDS_RT)
data_buffer[j] = 0;
for (i = 0; i < BCM2048_MAX_RDS_RT; i++) {
if (!bdev->rds_info.rds_rt[i]) {
if (cr && (i < cr)) {
err = -EBUSY;
goto unlock;
}
if (i < ce) {
if (cr && (i >= cr))
break;
err = -EBUSY;
goto unlock;
}
}
}
memcpy(data, data_buffer, sizeof(data_buffer));
unlock:
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_get_rds_ps(struct bcm2048_device *bdev, char *data)
{
int err = 0, i, j = 0;
char data_buffer[BCM2048_MAX_RDS_PS+1];
mutex_lock(&bdev->mutex);
if (!bdev->rds_info.text_len) {
err = -EINVAL;
goto unlock;
}
for (i = 0; i < BCM2048_MAX_RDS_PS; i++) {
if (bdev->rds_info.rds_ps[i]) {
data_buffer[j++] = bdev->rds_info.rds_ps[i];
} else {
if (i < (BCM2048_MAX_RDS_PS - 1)) {
err = -EBUSY;
goto unlock;
}
}
}
if (j <= BCM2048_MAX_RDS_PS)
data_buffer[j] = 0;
memcpy(data, data_buffer, sizeof(data_buffer));
unlock:
mutex_unlock(&bdev->mutex);
return err;
}
static void bcm2048_parse_rds_pi(struct bcm2048_device *bdev)
{
int i, cnt = 0;
u16 pi;
for (i = 0; i < bdev->fifo_size; i += BCM2048_RDS_FIFO_DUPLE_SIZE) {
if (bdev->rds_info.radio_text[i] == BCM2048_RDS_BLOCK_A) {
pi = (bdev->rds_info.radio_text[i+1] << 8) +
bdev->rds_info.radio_text[i+2];
if (!bdev->rds_info.rds_pi) {
bdev->rds_info.rds_pi = pi;
return;
}
if (pi != bdev->rds_info.rds_pi) {
cnt++;
if (cnt > 3) {
bdev->rds_info.rds_pi = pi;
cnt = 0;
}
} else {
cnt = 0;
}
}
}
}
static int bcm2048_rds_block_crc(struct bcm2048_device *bdev, int i)
{
return bdev->rds_info.radio_text[i] & BCM2048_RDS_CRC_MASK;
}
static void bcm2048_parse_rds_rt_block(struct bcm2048_device *bdev, int i,
int index, int crc)
{
if (crc) {
if (!bdev->rds_info.rds_rt[index])
bdev->rds_info.rds_rt[index] =
bdev->rds_info.radio_text[i+1];
if (!bdev->rds_info.rds_rt[index+1])
bdev->rds_info.rds_rt[index+1] =
bdev->rds_info.radio_text[i+2];
} else {
bdev->rds_info.rds_rt[index] = bdev->rds_info.radio_text[i+1];
bdev->rds_info.rds_rt[index+1] =
bdev->rds_info.radio_text[i+2];
}
}
static int bcm2048_parse_rt_match_b(struct bcm2048_device *bdev, int i)
{
int crc, rt_id, rt_group_b, rt_ab, index = 0;
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
return -EIO;
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK) ==
BCM2048_RDS_BLOCK_B) {
rt_id = bdev->rds_info.radio_text[i+1] &
BCM2048_RDS_BLOCK_MASK;
rt_group_b = bdev->rds_info.radio_text[i+1] &
BCM2048_RDS_GROUP_AB_MASK;
rt_ab = bdev->rds_info.radio_text[i+2] &
BCM2048_RDS_RT_AB_MASK;
if (rt_group_b != bdev->rds_info.rds_rt_group_b) {
memset(bdev->rds_info.rds_rt, 0,
sizeof(bdev->rds_info.rds_rt));
bdev->rds_info.rds_rt_group_b = rt_group_b;
}
if (rt_id == BCM2048_RDS_RT) {
if (rt_ab != bdev->rds_info.rds_rt_ab) {
memset(bdev->rds_info.rds_rt, 0,
sizeof(bdev->rds_info.rds_rt));
bdev->rds_info.rds_rt_ab = rt_ab;
}
index = bdev->rds_info.radio_text[i+2] &
BCM2048_RDS_RT_INDEX;
if (bdev->rds_info.rds_rt_group_b)
index <<= 1;
else
index <<= 2;
return index;
}
}
return -EIO;
}
static int bcm2048_parse_rt_match_c(struct bcm2048_device *bdev, int i,
int index)
{
int crc;
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
return 0;
BUG_ON((index+2) >= BCM2048_MAX_RDS_RT);
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK) ==
BCM2048_RDS_BLOCK_C) {
if (bdev->rds_info.rds_rt_group_b)
return 1;
bcm2048_parse_rds_rt_block(bdev, i, index, crc);
return 1;
}
return 0;
}
static void bcm2048_parse_rt_match_d(struct bcm2048_device *bdev, int i,
int index)
{
int crc;
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
return;
BUG_ON((index+4) >= BCM2048_MAX_RDS_RT);
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK) ==
BCM2048_RDS_BLOCK_D)
bcm2048_parse_rds_rt_block(bdev, i, index+2, crc);
}
static void bcm2048_parse_rds_rt(struct bcm2048_device *bdev)
{
int i, index = 0, crc, match_b = 0, match_c = 0, match_d = 0;
for (i = 0; i < bdev->fifo_size; i += BCM2048_RDS_FIFO_DUPLE_SIZE) {
if (match_b) {
match_b = 0;
index = bcm2048_parse_rt_match_b(bdev, i);
if (index >= 0 && index <= (BCM2048_MAX_RDS_RT - 5))
match_c = 1;
continue;
} else if (match_c) {
match_c = 0;
if (bcm2048_parse_rt_match_c(bdev, i, index))
match_d = 1;
continue;
} else if (match_d) {
match_d = 0;
bcm2048_parse_rt_match_d(bdev, i, index);
continue;
}
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK)
== BCM2048_RDS_BLOCK_A) {
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
continue;
if (((bdev->rds_info.radio_text[i+1] << 8) +
bdev->rds_info.radio_text[i+2]) ==
bdev->rds_info.rds_pi)
match_b = 1;
}
}
}
static void bcm2048_parse_rds_ps_block(struct bcm2048_device *bdev, int i,
int index, int crc)
{
if (crc) {
if (!bdev->rds_info.rds_ps[index])
bdev->rds_info.rds_ps[index] =
bdev->rds_info.radio_text[i+1];
if (!bdev->rds_info.rds_ps[index+1])
bdev->rds_info.rds_ps[index+1] =
bdev->rds_info.radio_text[i+2];
} else {
bdev->rds_info.rds_ps[index] = bdev->rds_info.radio_text[i+1];
bdev->rds_info.rds_ps[index+1] =
bdev->rds_info.radio_text[i+2];
}
}
static int bcm2048_parse_ps_match_c(struct bcm2048_device *bdev, int i,
int index)
{
int crc;
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
return 0;
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK) ==
BCM2048_RDS_BLOCK_C)
return 1;
return 0;
}
static void bcm2048_parse_ps_match_d(struct bcm2048_device *bdev, int i,
int index)
{
int crc;
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
return;
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK) ==
BCM2048_RDS_BLOCK_D)
bcm2048_parse_rds_ps_block(bdev, i, index, crc);
}
static int bcm2048_parse_ps_match_b(struct bcm2048_device *bdev, int i)
{
int crc, index, ps_id, ps_group;
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
return -EIO;
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK) ==
BCM2048_RDS_BLOCK_B) {
ps_id = bdev->rds_info.radio_text[i+1] &
BCM2048_RDS_BLOCK_MASK;
ps_group = bdev->rds_info.radio_text[i+1] &
BCM2048_RDS_GROUP_AB_MASK;
if (ps_group != bdev->rds_info.rds_ps_group) {
if (crc == BCM2048_RDS_CRC_NONE) {
bdev->rds_info.rds_ps_group_cnt++;
if (bdev->rds_info.rds_ps_group_cnt > 2) {
bdev->rds_info.rds_ps_group = ps_group;
bdev->rds_info.rds_ps_group_cnt = 0;
dev_err(&bdev->client->dev,
"RDS PS Group change!\n");
} else {
return -EIO;
}
} else {
bdev->rds_info.rds_ps_group_cnt = 0;
}
}
if (ps_id == BCM2048_RDS_PS) {
index = bdev->rds_info.radio_text[i+2] &
BCM2048_RDS_PS_INDEX;
index <<= 1;
return index;
}
}
return -EIO;
}
static void bcm2048_parse_rds_ps(struct bcm2048_device *bdev)
{
int i, index = 0, crc, match_b = 0, match_c = 0, match_d = 0;
for (i = 0; i < bdev->fifo_size; i += BCM2048_RDS_FIFO_DUPLE_SIZE) {
if (match_b) {
match_b = 0;
index = bcm2048_parse_ps_match_b(bdev, i);
if (index >= 0 && index < (BCM2048_MAX_RDS_PS - 1))
match_c = 1;
continue;
} else if (match_c) {
match_c = 0;
if (bcm2048_parse_ps_match_c(bdev, i, index))
match_d = 1;
continue;
} else if (match_d) {
match_d = 0;
bcm2048_parse_ps_match_d(bdev, i, index);
continue;
}
if ((bdev->rds_info.radio_text[i] & BCM2048_RDS_BLOCK_MASK)
== BCM2048_RDS_BLOCK_A) {
crc = bcm2048_rds_block_crc(bdev, i);
if (crc == BCM2048_RDS_CRC_UNRECOVARABLE)
continue;
if (((bdev->rds_info.radio_text[i+1] << 8) +
bdev->rds_info.radio_text[i+2]) ==
bdev->rds_info.rds_pi)
match_b = 1;
}
}
}
static void bcm2048_rds_fifo_receive(struct bcm2048_device *bdev)
{
int err;
mutex_lock(&bdev->mutex);
err = bcm2048_recv_duples(bdev, BCM2048_I2C_RDS_DATA,
bdev->rds_info.radio_text, bdev->fifo_size);
if (err != 2) {
dev_err(&bdev->client->dev, "RDS Read problem\n");
mutex_unlock(&bdev->mutex);
return;
}
bdev->rds_info.text_len = bdev->fifo_size;
bcm2048_parse_rds_pi(bdev);
bcm2048_parse_rds_rt(bdev);
bcm2048_parse_rds_ps(bdev);
mutex_unlock(&bdev->mutex);
wake_up_interruptible(&bdev->read_queue);
}
static int bcm2048_get_rds_data(struct bcm2048_device *bdev, char *data)
{
int err = 0, i, p = 0;
char *data_buffer;
mutex_lock(&bdev->mutex);
if (!bdev->rds_info.text_len) {
err = -EINVAL;
goto unlock;
}
data_buffer = kcalloc(BCM2048_MAX_RDS_RADIO_TEXT, 5, GFP_KERNEL);
if (!data_buffer) {
err = -ENOMEM;
goto unlock;
}
for (i = 0; i < bdev->rds_info.text_len; i++) {
p += sprintf(data_buffer+p, "%x ",
bdev->rds_info.radio_text[i]);
}
memcpy(data, data_buffer, p);
kfree(data_buffer);
unlock:
mutex_unlock(&bdev->mutex);
return err;
}
static int bcm2048_init(struct bcm2048_device *bdev)
{
int err;
err = bcm2048_set_power_state(bdev, BCM2048_POWER_ON);
if (err < 0)
goto exit;
err = bcm2048_set_audio_route(bdev, BCM2048_AUDIO_ROUTE_DAC);
if (err < 0)
goto exit;
err = bcm2048_set_dac_output(bdev, BCM2048_DAC_OUTPUT_LEFT |
BCM2048_DAC_OUTPUT_RIGHT);
exit:
return err;
}
static int bcm2048_deinit(struct bcm2048_device *bdev)
{
int err;
err = bcm2048_set_audio_route(bdev, 0);
if (err < 0)
goto exit;
err = bcm2048_set_dac_output(bdev, 0);
if (err < 0)
goto exit;
err = bcm2048_set_power_state(bdev, BCM2048_POWER_OFF);
if (err < 0)
goto exit;
exit:
return err;
}
static int bcm2048_probe(struct bcm2048_device *bdev)
{
int err;
err = bcm2048_set_power_state(bdev, BCM2048_POWER_ON);
if (err < 0)
goto unlock;
err = bcm2048_checkrev(bdev);
if (err < 0)
goto unlock;
err = bcm2048_set_mute(bdev, BCM2048_DEFAULT_MUTE);
if (err < 0)
goto unlock;
err = bcm2048_set_region(bdev, BCM2048_DEFAULT_REGION);
if (err < 0)
goto unlock;
err = bcm2048_set_fm_search_rssi_threshold(bdev,
BCM2048_DEFAULT_RSSI_THRESHOLD);
if (err < 0)
goto unlock;
err = bcm2048_set_fm_automatic_stereo_mono(bdev, BCM2048_ITEM_ENABLED);
if (err < 0)
goto unlock;
err = bcm2048_get_rds_wline(bdev);
if (err < BCM2048_DEFAULT_RDS_WLINE)
err = bcm2048_set_rds_wline(bdev, BCM2048_DEFAULT_RDS_WLINE);
if (err < 0)
goto unlock;
err = bcm2048_set_power_state(bdev, BCM2048_POWER_OFF);
init_waitqueue_head(&bdev->read_queue);
bdev->rds_data_available = 0;
bdev->rd_index = 0;
bdev->users = 0;
unlock:
return err;
}
static void bcm2048_work(struct work_struct *work)
{
struct bcm2048_device *bdev;
u8 flag_lsb, flag_msb, flags;
bdev = container_of(work, struct bcm2048_device, work);
bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_FLAG0, &flag_lsb);
bcm2048_recv_command(bdev, BCM2048_I2C_FM_RDS_FLAG1, &flag_msb);
if (flag_lsb & (BCM2048_FM_FLAG_SEARCH_TUNE_FINISHED |
BCM2048_FM_FLAG_SEARCH_TUNE_FAIL)) {
if (flag_lsb & BCM2048_FM_FLAG_SEARCH_TUNE_FAIL)
bdev->scan_state = BCM2048_SCAN_FAIL;
else
bdev->scan_state = BCM2048_SCAN_OK;
complete(&bdev->compl);
}
if (flag_msb & BCM2048_RDS_FLAG_FIFO_WLINE) {
bcm2048_rds_fifo_receive(bdev);
if (bdev->rds_state) {
flags = BCM2048_RDS_FLAG_FIFO_WLINE;
bcm2048_send_command(bdev, BCM2048_I2C_FM_RDS_MASK1,
flags);
}
bdev->rds_data_available = 1;
bdev->rd_index = 0;
}
}
static irqreturn_t bcm2048_handler(int irq, void *dev)
{
struct bcm2048_device *bdev = dev;
dev_dbg(&bdev->client->dev, "IRQ called, queuing work\n");
if (bdev->power_state)
schedule_work(&bdev->work);
return IRQ_HANDLED;
}
static int bcm2048_sysfs_unregister_properties(struct bcm2048_device *bdev,
int size)
{
int i;
for (i = 0; i < size; i++)
device_remove_file(&bdev->client->dev, &attrs[i]);
return 0;
}
static int bcm2048_sysfs_register_properties(struct bcm2048_device *bdev)
{
int err = 0;
int i;
for (i = 0; i < ARRAY_SIZE(attrs); i++) {
if (device_create_file(&bdev->client->dev, &attrs[i]) != 0) {
dev_err(&bdev->client->dev,
"could not register sysfs entry\n");
err = -EBUSY;
bcm2048_sysfs_unregister_properties(bdev, i);
break;
}
}
return err;
}
static int bcm2048_fops_open(struct file *file)
{
struct bcm2048_device *bdev = video_drvdata(file);
bdev->users++;
bdev->rd_index = 0;
bdev->rds_data_available = 0;
return 0;
}
static int bcm2048_fops_release(struct file *file)
{
struct bcm2048_device *bdev = video_drvdata(file);
bdev->users--;
return 0;
}
static unsigned int bcm2048_fops_poll(struct file *file,
struct poll_table_struct *pts)
{
struct bcm2048_device *bdev = video_drvdata(file);
int retval = 0;
poll_wait(file, &bdev->read_queue, pts);
if (bdev->rds_data_available)
retval = POLLIN | POLLRDNORM;
return retval;
}
static ssize_t bcm2048_fops_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct bcm2048_device *bdev = video_drvdata(file);
int i;
int retval = 0;
count = (count / 3) * 3;
if (count < 3)
return -ENOBUFS;
while (!bdev->rds_data_available) {
if (file->f_flags & O_NONBLOCK) {
retval = -EWOULDBLOCK;
goto done;
}
if (wait_event_interruptible(bdev->read_queue,
bdev->rds_data_available) < 0) {
retval = -EINTR;
goto done;
}
}
mutex_lock(&bdev->mutex);
i = bdev->fifo_size - bdev->rd_index;
if (count > i)
count = (i / 3) * 3;
i = 0;
while (i < count) {
unsigned char tmpbuf[3];
tmpbuf[i] = bdev->rds_info.radio_text[bdev->rd_index+i+2];
tmpbuf[i+1] = bdev->rds_info.radio_text[bdev->rd_index+i+1];
tmpbuf[i+2] = (bdev->rds_info.radio_text[bdev->rd_index + i] & 0xf0) >> 4;
if ((bdev->rds_info.radio_text[bdev->rd_index+i] &
BCM2048_RDS_CRC_MASK) == BCM2048_RDS_CRC_UNRECOVARABLE)
tmpbuf[i+2] |= 0x80;
if (copy_to_user(buf+i, tmpbuf, 3)) {
retval = -EFAULT;
break;
}
i += 3;
}
bdev->rd_index += i;
if (bdev->rd_index >= bdev->fifo_size)
bdev->rds_data_available = 0;
mutex_unlock(&bdev->mutex);
if (retval == 0)
retval = i;
done:
return retval;
}
static int bcm2048_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *capability)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
strlcpy(capability->driver, BCM2048_DRIVER_NAME,
sizeof(capability->driver));
strlcpy(capability->card, BCM2048_DRIVER_CARD,
sizeof(capability->card));
snprintf(capability->bus_info, 32, "I2C: 0x%X", bdev->client->addr);
capability->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO |
V4L2_CAP_HW_FREQ_SEEK;
capability->capabilities = capability->device_caps |
V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int bcm2048_vidioc_g_input(struct file *filp, void *priv,
unsigned int *i)
{
*i = 0;
return 0;
}
static int bcm2048_vidioc_s_input(struct file *filp, void *priv,
unsigned int i)
{
if (i)
return -EINVAL;
return 0;
}
static int bcm2048_vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
int i;
for (i = 0; i < ARRAY_SIZE(bcm2048_v4l2_queryctrl); i++) {
if (qc->id && qc->id == bcm2048_v4l2_queryctrl[i].id) {
*qc = bcm2048_v4l2_queryctrl[i];
return 0;
}
}
return -EINVAL;
}
static int bcm2048_vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
int err = 0;
if (!bdev)
return -ENODEV;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
err = bcm2048_get_mute(bdev);
if (err >= 0)
ctrl->value = err;
break;
}
return err;
}
static int bcm2048_vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
int err = 0;
if (!bdev)
return -ENODEV;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value) {
if (bdev->power_state) {
err = bcm2048_set_mute(bdev, ctrl->value);
err |= bcm2048_deinit(bdev);
}
} else {
if (!bdev->power_state) {
err = bcm2048_init(bdev);
err |= bcm2048_set_mute(bdev, ctrl->value);
}
}
break;
}
return err;
}
static int bcm2048_vidioc_g_audio(struct file *file, void *priv,
struct v4l2_audio *audio)
{
if (audio->index > 1)
return -EINVAL;
strncpy(audio->name, "Radio", 32);
audio->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int bcm2048_vidioc_s_audio(struct file *file, void *priv,
const struct v4l2_audio *audio)
{
if (audio->index != 0)
return -EINVAL;
return 0;
}
static int bcm2048_vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *tuner)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
s8 f_error;
s8 rssi;
if (!bdev)
return -ENODEV;
if (tuner->index > 0)
return -EINVAL;
strncpy(tuner->name, "FM Receiver", 32);
tuner->type = V4L2_TUNER_RADIO;
tuner->rangelow =
dev_to_v4l2(bcm2048_get_region_bottom_frequency(bdev));
tuner->rangehigh =
dev_to_v4l2(bcm2048_get_region_top_frequency(bdev));
tuner->rxsubchans = V4L2_TUNER_SUB_STEREO;
tuner->capability = V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LOW;
tuner->audmode = V4L2_TUNER_MODE_STEREO;
tuner->afc = 0;
if (bdev->power_state) {
f_error = bcm2048_get_fm_carrier_error(bdev);
if (f_error < BCM2048_FREQ_ERROR_FLOOR ||
f_error > BCM2048_FREQ_ERROR_ROOF) {
tuner->signal = 0;
} else {
rssi = bcm2048_get_fm_rssi(bdev);
if (rssi >= BCM2048_RSSI_LEVEL_BASE) {
tuner->signal = 0xFFFF;
} else if (rssi > BCM2048_RSSI_LEVEL_ROOF) {
tuner->signal = (rssi +
BCM2048_RSSI_LEVEL_ROOF_NEG)
* BCM2048_SIGNAL_MULTIPLIER;
} else {
tuner->signal = 0;
}
}
} else {
tuner->signal = 0;
}
return 0;
}
static int bcm2048_vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *tuner)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
if (!bdev)
return -ENODEV;
if (tuner->index > 0)
return -EINVAL;
return 0;
}
static int bcm2048_vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *freq)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
int err = 0;
int f;
if (!bdev->power_state)
return -ENODEV;
freq->type = V4L2_TUNER_RADIO;
f = bcm2048_get_fm_frequency(bdev);
if (f < 0)
err = f;
else
freq->frequency = dev_to_v4l2(f);
return err;
}
static int bcm2048_vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *freq)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
int err;
if (freq->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (!bdev->power_state)
return -ENODEV;
err = bcm2048_set_fm_frequency(bdev, v4l2_to_dev(freq->frequency));
err |= bcm2048_set_fm_search_tune_mode(bdev, BCM2048_FM_PRE_SET_MODE);
return err;
}
static int bcm2048_vidioc_s_hw_freq_seek(struct file *file, void *priv,
const struct v4l2_hw_freq_seek *seek)
{
struct bcm2048_device *bdev = video_get_drvdata(video_devdata(file));
int err;
if (!bdev->power_state)
return -ENODEV;
if ((seek->tuner != 0) || (seek->type != V4L2_TUNER_RADIO))
return -EINVAL;
err = bcm2048_set_fm_search_mode_direction(bdev, seek->seek_upward);
err |= bcm2048_set_fm_search_tune_mode(bdev,
BCM2048_FM_AUTO_SEARCH_MODE);
return err;
}
static int bcm2048_i2c_driver_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bcm2048_device *bdev;
int err;
bdev = kzalloc(sizeof(*bdev), GFP_KERNEL);
if (!bdev) {
err = -ENOMEM;
goto exit;
}
bdev->client = client;
i2c_set_clientdata(client, bdev);
mutex_init(&bdev->mutex);
init_completion(&bdev->compl);
INIT_WORK(&bdev->work, bcm2048_work);
if (client->irq) {
err = request_irq(client->irq,
bcm2048_handler, IRQF_TRIGGER_FALLING,
client->name, bdev);
if (err < 0) {
dev_err(&client->dev, "Could not request IRQ\n");
goto free_bdev;
}
dev_dbg(&client->dev, "IRQ requested.\n");
} else {
dev_dbg(&client->dev, "IRQ not configured. Using timeouts.\n");
}
bdev->videodev = bcm2048_viddev_template;
video_set_drvdata(&bdev->videodev, bdev);
if (video_register_device(&bdev->videodev, VFL_TYPE_RADIO, radio_nr)) {
dev_dbg(&client->dev, "Could not register video device.\n");
err = -EIO;
goto free_irq;
}
err = bcm2048_sysfs_register_properties(bdev);
if (err < 0) {
dev_dbg(&client->dev, "Could not register sysfs interface.\n");
goto free_registration;
}
err = bcm2048_probe(bdev);
if (err < 0) {
dev_dbg(&client->dev, "Failed to probe device information.\n");
goto free_sysfs;
}
return 0;
free_sysfs:
bcm2048_sysfs_unregister_properties(bdev, ARRAY_SIZE(attrs));
free_registration:
video_unregister_device(&bdev->videodev);
free_irq:
if (client->irq)
free_irq(client->irq, bdev);
free_bdev:
i2c_set_clientdata(client, NULL);
kfree(bdev);
exit:
return err;
}
static int __exit bcm2048_i2c_driver_remove(struct i2c_client *client)
{
struct bcm2048_device *bdev = i2c_get_clientdata(client);
if (!client->adapter)
return -ENODEV;
if (bdev) {
bcm2048_sysfs_unregister_properties(bdev, ARRAY_SIZE(attrs));
video_unregister_device(&bdev->videodev);
if (bdev->power_state)
bcm2048_set_power_state(bdev, BCM2048_POWER_OFF);
if (client->irq > 0)
free_irq(client->irq, bdev);
cancel_work_sync(&bdev->work);
kfree(bdev);
}
return 0;
}
