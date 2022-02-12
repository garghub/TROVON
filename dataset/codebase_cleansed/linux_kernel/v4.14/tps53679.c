static int tps53679_identify(struct i2c_client *client,
struct pmbus_driver_info *info)
{
u8 vout_params;
int ret;
ret = pmbus_read_byte_data(client, 0, PMBUS_VOUT_MODE);
if (ret < 0)
return ret;
vout_params = ret & GENMASK(4, 0);
switch (vout_params) {
case TPS53679_PROT_VR13_10MV:
case TPS53679_PROT_VR12_5_10MV:
info->vrm_version = vr13;
break;
case TPS53679_PROT_VR13_5MV:
case TPS53679_PROT_VR12_5MV:
case TPS53679_PROT_IMVP8_5MV:
info->vrm_version = vr12;
break;
default:
return -EINVAL;
}
return 0;
}
static int tps53679_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &tps53679_info);
}
