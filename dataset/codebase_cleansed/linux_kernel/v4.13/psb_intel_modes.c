bool psb_intel_ddc_probe(struct i2c_adapter *adapter)
{
u8 out_buf[] = { 0x0, 0x0 };
u8 buf[2];
int ret;
struct i2c_msg msgs[] = {
{
.addr = 0x50,
.flags = 0,
.len = 1,
.buf = out_buf,
},
{
.addr = 0x50,
.flags = I2C_M_RD,
.len = 1,
.buf = buf,
}
};
ret = i2c_transfer(adapter, msgs, 2);
if (ret == 2)
return true;
return false;
}
int psb_intel_ddc_get_modes(struct drm_connector *connector,
struct i2c_adapter *adapter)
{
struct edid *edid;
int ret = 0;
edid = drm_get_edid(connector, adapter);
if (edid) {
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
kfree(edid);
}
return ret;
}
