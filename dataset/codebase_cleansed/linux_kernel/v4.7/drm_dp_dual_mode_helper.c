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
data = kmalloc(msg.len, GFP_TEMPORARY);
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
static bool is_type2_adaptor(uint8_t adaptor_id)
{
return adaptor_id == (DP_DUAL_MODE_TYPE_TYPE2 |
DP_DUAL_MODE_REV_TYPE2);
}
enum drm_dp_dual_mode_type drm_dp_dual_mode_detect(struct i2c_adapter *adapter)
{
char hdmi_id[DP_DUAL_MODE_HDMI_ID_LEN] = {};
uint8_t adaptor_id = 0x00;
ssize_t ret;
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_HDMI_ID,
hdmi_id, sizeof(hdmi_id));
if (ret)
return DRM_DP_DUAL_MODE_UNKNOWN;
ret = drm_dp_dual_mode_read(adapter, DP_DUAL_MODE_ADAPTOR_ID,
&adaptor_id, sizeof(adaptor_id));
if (ret == 0) {
if (is_type2_adaptor(adaptor_id)) {
if (is_hdmi_adaptor(hdmi_id))
return DRM_DP_DUAL_MODE_TYPE2_HDMI;
else
return DRM_DP_DUAL_MODE_TYPE2_DVI;
}
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
default:
WARN_ON(type != DRM_DP_DUAL_MODE_UNKNOWN);
return "unknown";
}
}
