static int calibrate_8916(struct tsens_device *tmdev)
{
int base0 = 0, base1 = 0, i;
u32 p1[5], p2[5];
int mode = 0;
u32 *qfprom_cdata, *qfprom_csel;
qfprom_cdata = (u32 *)qfprom_read(tmdev->dev, "calib");
if (IS_ERR(qfprom_cdata))
return PTR_ERR(qfprom_cdata);
qfprom_csel = (u32 *)qfprom_read(tmdev->dev, "calib_sel");
if (IS_ERR(qfprom_csel))
return PTR_ERR(qfprom_csel);
mode = (qfprom_csel[0] & CAL_SEL_MASK) >> CAL_SEL_SHIFT;
dev_dbg(tmdev->dev, "calibration mode is %d\n", mode);
switch (mode) {
case TWO_PT_CALIB:
base1 = (qfprom_cdata[1] & BASE1_MASK) >> BASE1_SHIFT;
p2[0] = (qfprom_cdata[0] & S0_P2_MASK) >> S0_P2_SHIFT;
p2[1] = (qfprom_cdata[0] & S1_P2_MASK) >> S1_P2_SHIFT;
p2[2] = (qfprom_cdata[1] & S2_P2_MASK) >> S2_P2_SHIFT;
p2[3] = (qfprom_cdata[1] & S3_P2_MASK) >> S3_P2_SHIFT;
p2[4] = (qfprom_cdata[1] & S4_P2_MASK) >> S4_P2_SHIFT;
for (i = 0; i < tmdev->num_sensors; i++)
p2[i] = ((base1 + p2[i]) << 3);
case ONE_PT_CALIB2:
base0 = (qfprom_cdata[0] & BASE0_MASK);
p1[0] = (qfprom_cdata[0] & S0_P1_MASK) >> S0_P1_SHIFT;
p1[1] = (qfprom_cdata[0] & S1_P1_MASK) >> S1_P1_SHIFT;
p1[2] = (qfprom_cdata[0] & S2_P1_MASK) >> S2_P1_SHIFT;
p1[3] = (qfprom_cdata[1] & S3_P1_MASK) >> S3_P1_SHIFT;
p1[4] = (qfprom_cdata[1] & S4_P1_MASK) >> S4_P1_SHIFT;
for (i = 0; i < tmdev->num_sensors; i++)
p1[i] = (((base0) + p1[i]) << 3);
break;
default:
for (i = 0; i < tmdev->num_sensors; i++) {
p1[i] = 500;
p2[i] = 780;
}
break;
}
compute_intercept_slope(tmdev, p1, p2, mode);
return 0;
}
