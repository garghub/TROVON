int gspca_expo_autogain(
struct gspca_dev *gspca_dev,
int avg_lum,
int desired_avg_lum,
int deadzone,
int gain_knee,
int exposure_knee)
{
s32 gain, orig_gain, exposure, orig_exposure;
int i, steps, retval = 0;
if (v4l2_ctrl_g_ctrl(gspca_dev->autogain) == 0)
return 0;
orig_gain = gain = v4l2_ctrl_g_ctrl(gspca_dev->gain);
orig_exposure = exposure = v4l2_ctrl_g_ctrl(gspca_dev->exposure);
steps = abs(desired_avg_lum - avg_lum) / deadzone;
PDEBUG(D_FRAM, "autogain: lum: %d, desired: %d, steps: %d",
avg_lum, desired_avg_lum, steps);
for (i = 0; i < steps; i++) {
if (avg_lum > desired_avg_lum) {
if (gain > gain_knee)
gain--;
else if (exposure > exposure_knee)
exposure--;
else if (gain > gspca_dev->gain->default_value)
gain--;
else if (exposure > gspca_dev->exposure->minimum)
exposure--;
else if (gain > gspca_dev->gain->minimum)
gain--;
else
break;
} else {
if (gain < gspca_dev->gain->default_value)
gain++;
else if (exposure < exposure_knee)
exposure++;
else if (gain < gain_knee)
gain++;
else if (exposure < gspca_dev->exposure->maximum)
exposure++;
else if (gain < gspca_dev->gain->maximum)
gain++;
else
break;
}
}
if (gain != orig_gain) {
v4l2_ctrl_s_ctrl(gspca_dev->gain, gain);
retval = 1;
}
if (exposure != orig_exposure) {
v4l2_ctrl_s_ctrl(gspca_dev->exposure, exposure);
retval = 1;
}
if (retval)
PDEBUG(D_FRAM, "autogain: changed gain: %d, expo: %d",
gain, exposure);
return retval;
}
int gspca_coarse_grained_expo_autogain(
struct gspca_dev *gspca_dev,
int avg_lum,
int desired_avg_lum,
int deadzone)
{
s32 gain_low, gain_high, gain, orig_gain, exposure, orig_exposure;
int steps, retval = 0;
if (v4l2_ctrl_g_ctrl(gspca_dev->autogain) == 0)
return 0;
orig_gain = gain = v4l2_ctrl_g_ctrl(gspca_dev->gain);
orig_exposure = exposure = v4l2_ctrl_g_ctrl(gspca_dev->exposure);
gain_low = (s32)(gspca_dev->gain->maximum - gspca_dev->gain->minimum) /
5 * 2 + gspca_dev->gain->minimum;
gain_high = (s32)(gspca_dev->gain->maximum - gspca_dev->gain->minimum) /
5 * 4 + gspca_dev->gain->minimum;
steps = (desired_avg_lum - avg_lum) / deadzone;
PDEBUG(D_FRAM, "autogain: lum: %d, desired: %d, steps: %d",
avg_lum, desired_avg_lum, steps);
if ((gain + steps) > gain_high &&
exposure < gspca_dev->exposure->maximum) {
gain = gain_high;
gspca_dev->exp_too_low_cnt++;
gspca_dev->exp_too_high_cnt = 0;
} else if ((gain + steps) < gain_low &&
exposure > gspca_dev->exposure->minimum) {
gain = gain_low;
gspca_dev->exp_too_high_cnt++;
gspca_dev->exp_too_low_cnt = 0;
} else {
gain += steps;
if (gain > gspca_dev->gain->maximum)
gain = gspca_dev->gain->maximum;
else if (gain < gspca_dev->gain->minimum)
gain = gspca_dev->gain->minimum;
gspca_dev->exp_too_high_cnt = 0;
gspca_dev->exp_too_low_cnt = 0;
}
if (gspca_dev->exp_too_high_cnt > 3) {
exposure--;
gspca_dev->exp_too_high_cnt = 0;
} else if (gspca_dev->exp_too_low_cnt > 3) {
exposure++;
gspca_dev->exp_too_low_cnt = 0;
}
if (gain != orig_gain) {
v4l2_ctrl_s_ctrl(gspca_dev->gain, gain);
retval = 1;
}
if (exposure != orig_exposure) {
v4l2_ctrl_s_ctrl(gspca_dev->exposure, exposure);
retval = 1;
}
if (retval)
PDEBUG(D_FRAM, "autogain: changed gain: %d, expo: %d",
gain, exposure);
return retval;
}
