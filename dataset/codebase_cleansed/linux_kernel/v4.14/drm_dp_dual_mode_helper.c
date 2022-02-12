ssize_t drm_dp_dual_mode_read(struct i2c_adapter *adapter,
u8 offset, void *buffer, size_t size)
{
struct i2c_msg msgs[] = {
{
.addr = DP_DUAL_MODE_SLAVE_ADDRESS,
.flags = 0,
.len = 1,
.buf = &offset,
},
{
.addr = DP_DUAL_MODE_SLAVE_ADDRESS,
.flags = I2C_M_RD,
.len = size,
.buf = buffer,
},
};
int ret;
ret = i2c_transfer(adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
return ret;
if (ret != ARRAY_SIZE(msgs))
return -EPROTO;
return 0;
}
ssize_t drm_dp_dual_mode_write(struct i2c_adapter *adapter,
u8 offset, const void *buffer, size_t size)
{
struct i2c_msg msg = {
.addr = DP_DUAL_MODE_SLAVE_ADDRESS,
.flags = 0,
.len = 1 + size,
.buf = NULL,
};
void *data;
int ret;
data = kmalloc(msg.len, GFP_KERNEL);
if (!data)
return -ENOMEM;
msg.buf = data;
memcpy(data, &offset, 1);
memcpy(data + 1, buffer, size);
ret = i2c_transfer(adapter, &msg, 1);
kfree(data);
if (ret < 0)
return ret;
if (ret != 1)
return -EPROTO;
return 0;
}
static bool is_hdmi_adaptor(const char hdmi_id[DP_DUAL_MODE_HDMI_ID_LEN])
{
static const char dp_dual_mode_hdmi_id[DP_DUAL_MODE_HDMI_ID_LEN] =
"DP-HDMI ADAPTOR\x04";
return memcmp(hdmi_id, dp_dual_mode_hdmi_id,
sizeof(dp_dual_mode_hdmi_id)) == 0;
}
static bool is_type1_adaptor(uint8_t adaptor_id)
{
return adaptor_id == 0 || adaptor_id == 0xff;
}
static bool is_type2_adaptor(uint8_t adaptor_id)
{
return adaptor_id == (DP_DUAL_MODE_TYPE_TYPE2 |
DP_DUAL_MODE_REV_TYPE2);
}
static bool is_lspcon_adaptor(const char hdmi_id[DP_DUAL_MODE_HDMI_ID_LEN],
const uint8_t adaptor_id)
{
return is_hdmi_adaptor(hdmi_id) &&
(adaptor_id == (DP_DUAL_MODE_TYPE_TYPE2 |
DP_DUAL_MODE_TYPE_HAS_DPCD));
}
enum drm_dp_dual_mode_type drm_dp_dual_mode_detect(struct i2c_adapter *adapter)
{
char hdmi_id[DP_DUAL_MODE_HDMI_ID_LEN] = {};
uint8_t adaptor_id = 0x00;
ssize_t ret;
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_HDMI_ID,
hdmi_id, sizeof(hdmi_id));
DRM_DEBUG_KMS("DP dual mode HDMI ID: %*pE (err %zd)\n",
ret ? 0 : (int)sizeof(hdmi_id), hdmi_id, ret);
if (ret)
return DRM_DP_DUAL_MODE_UNKNOWN;
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_ADAPTOR_ID,
&adaptor_id, sizeof(adaptor_id));
DRM_DEBUG_KMS("DP dual mode adaptor ID: %02x (err %zd)\n",
adaptor_id, ret);
if (ret == 0) {
if (is_lspcon_adaptor(hdmi_id, adaptor_id))
return DRM_DP_DUAL_MODE_LSPCON;
if (is_type2_adaptor(adaptor_id)) {
if (is_hdmi_adaptor(hdmi_id))
return DRM_DP_DUAL_MODE_TYPE2_HDMI;
else
return DRM_DP_DUAL_MODE_TYPE2_DVI;
}
if (!is_type1_adaptor(adaptor_id) && adaptor_id != hdmi_id[0])
DRM_ERROR("Unexpected DP dual mode adaptor ID %02x\n",
adaptor_id);
}
if (is_hdmi_adaptor(hdmi_id))
return DRM_DP_DUAL_MODE_TYPE1_HDMI;
else
return DRM_DP_DUAL_MODE_TYPE1_DVI;
}
int drm_dp_dual_mode_max_tmds_clock(enum drm_dp_dual_mode_type type,
struct i2c_adapter *adapter)
{
uint8_t max_tmds_clock;
ssize_t ret;
if (type == DRM_DP_DUAL_MODE_NONE)
return 0;
if (type < DRM_DP_DUAL_MODE_TYPE2_DVI)
return 165000;
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_MAX_TMDS_CLOCK,
&max_tmds_clock, sizeof(max_tmds_clock));
if (ret || max_tmds_clock == 0x00 || max_tmds_clock == 0xff) {
DRM_DEBUG_KMS("Failed to query max TMDS clock\n");
return 165000;
}
return max_tmds_clock * 5000 / 2;
}
int drm_dp_dual_mode_get_tmds_output(enum drm_dp_dual_mode_type type,
struct i2c_adapter *adapter,
bool *enabled)
{
uint8_t tmds_oen;
ssize_t ret;
if (type < DRM_DP_DUAL_MODE_TYPE2_DVI) {
*enabled = true;
return 0;
}
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_TMDS_OEN,
&tmds_oen, sizeof(tmds_oen));
if (ret) {
DRM_DEBUG_KMS("Failed to query state of TMDS output buffers\n");
return ret;
}
*enabled = !(tmds_oen & DP_DUAL_MODE_TMDS_DISABLE);
return 0;
}
int drm_dp_dual_mode_set_tmds_output(enum drm_dp_dual_mode_type type,
struct i2c_adapter *adapter, bool enable)
{
uint8_t tmds_oen = enable ? 0 : DP_DUAL_MODE_TMDS_DISABLE;
ssize_t ret;
if (type < DRM_DP_DUAL_MODE_TYPE2_DVI)
return 0;
ret = drm_dp_dual_mode_write(adapter, DP_DUAL_MODE_TMDS_OEN,
&tmds_oen, sizeof(tmds_oen));
if (ret) {
DRM_DEBUG_KMS("Failed to %s TMDS output buffers\n",
enable ? "enable" : "disable");
return ret;
}
return 0;
}
const char *drm_dp_get_dual_mode_type_name(enum drm_dp_dual_mode_type type)
{
switch (type) {
case DRM_DP_DUAL_MODE_NONE:
return "none";
case DRM_DP_DUAL_MODE_TYPE1_DVI:
return "type 1 DVI";
case DRM_DP_DUAL_MODE_TYPE1_HDMI:
return "type 1 HDMI";
case DRM_DP_DUAL_MODE_TYPE2_DVI:
return "type 2 DVI";
case DRM_DP_DUAL_MODE_TYPE2_HDMI:
return "type 2 HDMI";
case DRM_DP_DUAL_MODE_LSPCON:
return "lspcon";
default:
WARN_ON(type != DRM_DP_DUAL_MODE_UNKNOWN);
return "unknown";
}
}
int drm_lspcon_get_mode(struct i2c_adapter *adapter,
enum drm_lspcon_mode *mode)
{
u8 data;
int ret = 0;
if (!mode) {
DRM_ERROR("NULL input\n");
return -EINVAL;
}
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_LSPCON_CURRENT_MODE,
&data, sizeof(data));
if (ret < 0) {
DRM_ERROR("LSPCON read(0x80, 0x41) failed\n");
return -EFAULT;
}
if (data & DP_DUAL_MODE_LSPCON_MODE_PCON)
*mode = DRM_LSPCON_MODE_PCON;
else
*mode = DRM_LSPCON_MODE_LS;
return 0;
}
int drm_lspcon_set_mode(struct i2c_adapter *adapter,
enum drm_lspcon_mode mode)
{
u8 data = 0;
int ret;
int time_out = 200;
enum drm_lspcon_mode current_mode;
if (mode == DRM_LSPCON_MODE_PCON)
data = DP_DUAL_MODE_LSPCON_MODE_PCON;
ret = drm_dp_dual_mode_write(adapter, DP_DUAL_MODE_LSPCON_MODE_CHANGE,
&data, sizeof(data));
if (ret < 0) {
DRM_ERROR("LSPCON mode change failed\n");
return ret;
}
do {
ret = drm_lspcon_get_mode(adapter, &current_mode);
if (ret) {
DRM_ERROR("can't confirm LSPCON mode change\n");
return ret;
} else {
if (current_mode != mode) {
msleep(10);
time_out -= 10;
} else {
DRM_DEBUG_KMS("LSPCON mode changed to %s\n",
mode == DRM_LSPCON_MODE_LS ?
"LS" : "PCON");
return 0;
}
}
} while (time_out);
DRM_ERROR("LSPCON mode change timed out\n");
return -ETIMEDOUT;
}
