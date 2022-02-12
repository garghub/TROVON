bool psb_intel_ddc_probe(struct psb_intel_output *psb_intel_output)
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
ret = i2c_transfer(&psb_intel_output->ddc_bus->adapter, msgs, 2);
if (ret == 2)
return true;
return false;
}
int psb_intel_ddc_get_modes(struct psb_intel_output *psb_intel_output)
{
struct edid *edid;
int ret = 0;
edid =
drm_get_edid(&psb_intel_output->base,
&psb_intel_output->ddc_bus->adapter);
if (edid) {
drm_mode_connector_update_edid_property(&psb_intel_output->
base, edid);
ret = drm_add_edid_modes(&psb_intel_output->base, edid);
kfree(edid);
}
return ret;
}
