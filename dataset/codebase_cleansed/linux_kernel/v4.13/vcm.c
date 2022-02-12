int vcm_power_up(struct v4l2_subdev *sd)
{
const struct camera_af_platform_data *vcm_platform_data;
vcm_platform_data = camera_get_af_platform_data();
if (NULL == vcm_platform_data)
return -ENODEV;
return vcm_platform_data->power_ctrl(sd, 1);
}
int vcm_power_down(struct v4l2_subdev *sd)
{
const struct camera_af_platform_data *vcm_platform_data;
vcm_platform_data = camera_get_af_platform_data();
if (NULL == vcm_platform_data)
return -ENODEV;
return vcm_platform_data->power_ctrl(sd, 0);
}
