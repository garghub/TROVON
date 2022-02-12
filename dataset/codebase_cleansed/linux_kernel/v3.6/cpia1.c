static int cpia_usb_transferCmd(struct gspca_dev *gspca_dev, u8 *command)
{
u8 requesttype;
unsigned int pipe;
int ret, databytes = command[6] | (command[7] << 8);
int retries = 3;
if (command[0] == DATA_IN) {
pipe = usb_rcvctrlpipe(gspca_dev->dev, 0);
requesttype = USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
} else if (command[0] == DATA_OUT) {
pipe = usb_sndctrlpipe(gspca_dev->dev, 0);
requesttype = USB_TYPE_VENDOR | USB_RECIP_DEVICE;
} else {
PDEBUG(D_ERR, "Unexpected first byte of command: %x",
command[0]);
return -EINVAL;
}
retry:
ret = usb_control_msg(gspca_dev->dev, pipe,
command[1],
requesttype,
command[2] | (command[3] << 8),
command[4] | (command[5] << 8),
gspca_dev->usb_buf, databytes, 1000);
if (ret < 0)
pr_err("usb_control_msg %02x, error %d\n", command[1], ret);
if (ret == -EPIPE && retries > 0) {
retries--;
goto retry;
}
return (ret < 0) ? ret : 0;
}
static int do_command(struct gspca_dev *gspca_dev, u16 command,
u8 a, u8 b, u8 c, u8 d)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret, datasize;
u8 cmd[8];
switch (command) {
case CPIA_COMMAND_GetCPIAVersion:
case CPIA_COMMAND_GetPnPID:
case CPIA_COMMAND_GetCameraStatus:
case CPIA_COMMAND_GetVPVersion:
case CPIA_COMMAND_GetColourParams:
case CPIA_COMMAND_GetColourBalance:
case CPIA_COMMAND_GetExposure:
datasize = 8;
break;
case CPIA_COMMAND_ReadMCPorts:
case CPIA_COMMAND_ReadVCRegs:
datasize = 4;
break;
default:
datasize = 0;
break;
}
cmd[0] = command >> 8;
cmd[1] = command & 0xff;
cmd[2] = a;
cmd[3] = b;
cmd[4] = c;
cmd[5] = d;
cmd[6] = datasize;
cmd[7] = 0;
ret = cpia_usb_transferCmd(gspca_dev, cmd);
if (ret)
return ret;
switch (command) {
case CPIA_COMMAND_GetCPIAVersion:
sd->params.version.firmwareVersion = gspca_dev->usb_buf[0];
sd->params.version.firmwareRevision = gspca_dev->usb_buf[1];
sd->params.version.vcVersion = gspca_dev->usb_buf[2];
sd->params.version.vcRevision = gspca_dev->usb_buf[3];
break;
case CPIA_COMMAND_GetPnPID:
sd->params.pnpID.vendor =
gspca_dev->usb_buf[0] | (gspca_dev->usb_buf[1] << 8);
sd->params.pnpID.product =
gspca_dev->usb_buf[2] | (gspca_dev->usb_buf[3] << 8);
sd->params.pnpID.deviceRevision =
gspca_dev->usb_buf[4] | (gspca_dev->usb_buf[5] << 8);
break;
case CPIA_COMMAND_GetCameraStatus:
sd->params.status.systemState = gspca_dev->usb_buf[0];
sd->params.status.grabState = gspca_dev->usb_buf[1];
sd->params.status.streamState = gspca_dev->usb_buf[2];
sd->params.status.fatalError = gspca_dev->usb_buf[3];
sd->params.status.cmdError = gspca_dev->usb_buf[4];
sd->params.status.debugFlags = gspca_dev->usb_buf[5];
sd->params.status.vpStatus = gspca_dev->usb_buf[6];
sd->params.status.errorCode = gspca_dev->usb_buf[7];
break;
case CPIA_COMMAND_GetVPVersion:
sd->params.vpVersion.vpVersion = gspca_dev->usb_buf[0];
sd->params.vpVersion.vpRevision = gspca_dev->usb_buf[1];
sd->params.vpVersion.cameraHeadID =
gspca_dev->usb_buf[2] | (gspca_dev->usb_buf[3] << 8);
break;
case CPIA_COMMAND_GetColourParams:
sd->params.colourParams.brightness = gspca_dev->usb_buf[0];
sd->params.colourParams.contrast = gspca_dev->usb_buf[1];
sd->params.colourParams.saturation = gspca_dev->usb_buf[2];
break;
case CPIA_COMMAND_GetColourBalance:
sd->params.colourBalance.redGain = gspca_dev->usb_buf[0];
sd->params.colourBalance.greenGain = gspca_dev->usb_buf[1];
sd->params.colourBalance.blueGain = gspca_dev->usb_buf[2];
break;
case CPIA_COMMAND_GetExposure:
sd->params.exposure.gain = gspca_dev->usb_buf[0];
sd->params.exposure.fineExp = gspca_dev->usb_buf[1];
sd->params.exposure.coarseExpLo = gspca_dev->usb_buf[2];
sd->params.exposure.coarseExpHi = gspca_dev->usb_buf[3];
sd->params.exposure.redComp = gspca_dev->usb_buf[4];
sd->params.exposure.green1Comp = gspca_dev->usb_buf[5];
sd->params.exposure.green2Comp = gspca_dev->usb_buf[6];
sd->params.exposure.blueComp = gspca_dev->usb_buf[7];
break;
case CPIA_COMMAND_ReadMCPorts:
a = ((gspca_dev->usb_buf[1] & 0x02) == 0);
if (a != sd->params.qx3.button) {
#if defined(CONFIG_INPUT) || defined(CONFIG_INPUT_MODULE)
input_report_key(gspca_dev->input_dev, KEY_CAMERA, a);
input_sync(gspca_dev->input_dev);
#endif
sd->params.qx3.button = a;
}
if (sd->params.qx3.button) {
do_command(gspca_dev, CPIA_COMMAND_WriteMCPort,
3, 0xdf, 0xdf, 0);
do_command(gspca_dev, CPIA_COMMAND_WriteMCPort,
3, 0xff, 0xff, 0);
}
sd->params.qx3.cradled = ((gspca_dev->usb_buf[2] & 0x40) == 0);
break;
}
return 0;
}
static int do_command_extended(struct gspca_dev *gspca_dev, u16 command,
u8 a, u8 b, u8 c, u8 d,
u8 e, u8 f, u8 g, u8 h,
u8 i, u8 j, u8 k, u8 l)
{
u8 cmd[8];
cmd[0] = command >> 8;
cmd[1] = command & 0xff;
cmd[2] = a;
cmd[3] = b;
cmd[4] = c;
cmd[5] = d;
cmd[6] = 8;
cmd[7] = 0;
gspca_dev->usb_buf[0] = e;
gspca_dev->usb_buf[1] = f;
gspca_dev->usb_buf[2] = g;
gspca_dev->usb_buf[3] = h;
gspca_dev->usb_buf[4] = i;
gspca_dev->usb_buf[5] = j;
gspca_dev->usb_buf[6] = k;
gspca_dev->usb_buf[7] = l;
return cpia_usb_transferCmd(gspca_dev, cmd);
}
static int find_over_exposure(int brightness)
{
int MaxAllowableOverExposure, OverExposure;
MaxAllowableOverExposure = FLICKER_MAX_EXPOSURE - brightness -
FLICKER_BRIGHTNESS_CONSTANT;
if (MaxAllowableOverExposure < FLICKER_ALLOWABLE_OVER_EXPOSURE)
OverExposure = MaxAllowableOverExposure;
else
OverExposure = FLICKER_ALLOWABLE_OVER_EXPOSURE;
return OverExposure;
}
static void reset_camera_params(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam_params *params = &sd->params;
params->colourParams.brightness = BRIGHTNESS_DEF;
params->colourParams.contrast = CONTRAST_DEF;
params->colourParams.saturation = SATURATION_DEF;
params->exposure.gainMode = 4;
params->exposure.expMode = 2;
params->exposure.compMode = 1;
params->exposure.centreWeight = 1;
params->exposure.gain = 0;
params->exposure.fineExp = 0;
params->exposure.coarseExpLo = 185;
params->exposure.coarseExpHi = 0;
params->exposure.redComp = COMP_RED;
params->exposure.green1Comp = COMP_GREEN1;
params->exposure.green2Comp = COMP_GREEN2;
params->exposure.blueComp = COMP_BLUE;
params->colourBalance.balanceMode = 2;
params->colourBalance.redGain = 32;
params->colourBalance.greenGain = 6;
params->colourBalance.blueGain = 92;
params->apcor.gain1 = 0x18;
params->apcor.gain2 = 0x16;
params->apcor.gain4 = 0x24;
params->apcor.gain8 = 0x34;
params->vlOffset.gain1 = 20;
params->vlOffset.gain2 = 24;
params->vlOffset.gain4 = 26;
params->vlOffset.gain8 = 26;
params->compressionParams.hysteresis = 3;
params->compressionParams.threshMax = 11;
params->compressionParams.smallStep = 1;
params->compressionParams.largeStep = 3;
params->compressionParams.decimationHysteresis = 2;
params->compressionParams.frDiffStepThresh = 5;
params->compressionParams.qDiffStepThresh = 3;
params->compressionParams.decimationThreshMod = 2;
params->sensorFps.divisor = 1;
params->sensorFps.baserate = 1;
params->flickerControl.flickerMode = 0;
params->flickerControl.disabled = 1;
params->flickerControl.coarseJump =
flicker_jumps[sd->mainsFreq]
[params->sensorFps.baserate]
[params->sensorFps.divisor];
params->flickerControl.allowableOverExposure =
find_over_exposure(params->colourParams.brightness);
params->yuvThreshold.yThreshold = 6;
params->yuvThreshold.uvThreshold = 6;
params->format.subSample = SUBSAMPLE_420;
params->format.yuvOrder = YUVORDER_YUYV;
params->compression.mode = CPIA_COMPRESSION_AUTO;
params->compression.decimation = NO_DECIMATION;
params->compressionTarget.frTargeting = COMP_TARGET_DEF;
params->compressionTarget.targetFR = 15;
params->compressionTarget.targetQ = 5;
params->qx3.qx3_detected = 0;
params->qx3.toplight = 0;
params->qx3.bottomlight = 0;
params->qx3.button = 0;
params->qx3.cradled = 0;
}
static void printstatus(struct cam_params *params)
{
PDEBUG(D_PROBE, "status: %02x %02x %02x %02x %02x %02x %02x %02x",
params->status.systemState, params->status.grabState,
params->status.streamState, params->status.fatalError,
params->status.cmdError, params->status.debugFlags,
params->status.vpStatus, params->status.errorCode);
}
static int goto_low_power(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
ret = do_command(gspca_dev, CPIA_COMMAND_GotoLoPower, 0, 0, 0, 0);
if (ret)
return ret;
ret = do_command(gspca_dev, CPIA_COMMAND_GetCameraStatus, 0, 0, 0, 0);
if (ret)
return ret;
if (sd->params.status.systemState != LO_POWER_STATE) {
if (sd->params.status.systemState != WARM_BOOT_STATE) {
PDEBUG(D_ERR,
"unexpected state after lo power cmd: %02x",
sd->params.status.systemState);
printstatus(&sd->params);
}
return -EIO;
}
PDEBUG(D_CONF, "camera now in LOW power state");
return 0;
}
static int goto_high_power(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
ret = do_command(gspca_dev, CPIA_COMMAND_GotoHiPower, 0, 0, 0, 0);
if (ret)
return ret;
msleep_interruptible(40);
if (signal_pending(current))
return -EINTR;
do_command(gspca_dev, CPIA_COMMAND_GetCameraStatus, 0, 0, 0, 0);
if (ret)
return ret;
if (sd->params.status.systemState != HI_POWER_STATE) {
PDEBUG(D_ERR, "unexpected state after hi power cmd: %02x",
sd->params.status.systemState);
printstatus(&sd->params);
return -EIO;
}
PDEBUG(D_CONF, "camera now in HIGH power state");
return 0;
}
static int get_version_information(struct gspca_dev *gspca_dev)
{
int ret;
ret = do_command(gspca_dev, CPIA_COMMAND_GetCPIAVersion, 0, 0, 0, 0);
if (ret)
return ret;
return do_command(gspca_dev, CPIA_COMMAND_GetPnPID, 0, 0, 0, 0);
}
static int save_camera_state(struct gspca_dev *gspca_dev)
{
int ret;
ret = do_command(gspca_dev, CPIA_COMMAND_GetColourBalance, 0, 0, 0, 0);
if (ret)
return ret;
return do_command(gspca_dev, CPIA_COMMAND_GetExposure, 0, 0, 0, 0);
}
static int command_setformat(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
ret = do_command(gspca_dev, CPIA_COMMAND_SetFormat,
sd->params.format.videoSize,
sd->params.format.subSample,
sd->params.format.yuvOrder, 0);
if (ret)
return ret;
return do_command(gspca_dev, CPIA_COMMAND_SetROI,
sd->params.roi.colStart, sd->params.roi.colEnd,
sd->params.roi.rowStart, sd->params.roi.rowEnd);
}
static int command_setcolourparams(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetColourParams,
sd->params.colourParams.brightness,
sd->params.colourParams.contrast,
sd->params.colourParams.saturation, 0);
}
static int command_setapcor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetApcor,
sd->params.apcor.gain1,
sd->params.apcor.gain2,
sd->params.apcor.gain4,
sd->params.apcor.gain8);
}
static int command_setvloffset(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetVLOffset,
sd->params.vlOffset.gain1,
sd->params.vlOffset.gain2,
sd->params.vlOffset.gain4,
sd->params.vlOffset.gain8);
}
static int command_setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
ret = do_command_extended(gspca_dev, CPIA_COMMAND_SetExposure,
sd->params.exposure.gainMode,
1,
sd->params.exposure.compMode,
sd->params.exposure.centreWeight,
sd->params.exposure.gain,
sd->params.exposure.fineExp,
sd->params.exposure.coarseExpLo,
sd->params.exposure.coarseExpHi,
sd->params.exposure.redComp,
sd->params.exposure.green1Comp,
sd->params.exposure.green2Comp,
sd->params.exposure.blueComp);
if (ret)
return ret;
if (sd->params.exposure.expMode != 1) {
ret = do_command_extended(gspca_dev, CPIA_COMMAND_SetExposure,
0,
sd->params.exposure.expMode,
0, 0,
sd->params.exposure.gain,
sd->params.exposure.fineExp,
sd->params.exposure.coarseExpLo,
sd->params.exposure.coarseExpHi,
0, 0, 0, 0);
}
return ret;
}
static int command_setcolourbalance(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->params.colourBalance.balanceMode == 1) {
int ret;
ret = do_command(gspca_dev, CPIA_COMMAND_SetColourBalance,
1,
sd->params.colourBalance.redGain,
sd->params.colourBalance.greenGain,
sd->params.colourBalance.blueGain);
if (ret)
return ret;
return do_command(gspca_dev, CPIA_COMMAND_SetColourBalance,
3, 0, 0, 0);
}
if (sd->params.colourBalance.balanceMode == 2) {
return do_command(gspca_dev, CPIA_COMMAND_SetColourBalance,
2, 0, 0, 0);
}
if (sd->params.colourBalance.balanceMode == 3) {
return do_command(gspca_dev, CPIA_COMMAND_SetColourBalance,
3, 0, 0, 0);
}
return -EINVAL;
}
static int command_setcompressiontarget(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetCompressionTarget,
sd->params.compressionTarget.frTargeting,
sd->params.compressionTarget.targetFR,
sd->params.compressionTarget.targetQ, 0);
}
static int command_setyuvtresh(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetYUVThresh,
sd->params.yuvThreshold.yThreshold,
sd->params.yuvThreshold.uvThreshold, 0, 0);
}
static int command_setcompressionparams(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command_extended(gspca_dev,
CPIA_COMMAND_SetCompressionParams,
0, 0, 0, 0,
sd->params.compressionParams.hysteresis,
sd->params.compressionParams.threshMax,
sd->params.compressionParams.smallStep,
sd->params.compressionParams.largeStep,
sd->params.compressionParams.decimationHysteresis,
sd->params.compressionParams.frDiffStepThresh,
sd->params.compressionParams.qDiffStepThresh,
sd->params.compressionParams.decimationThreshMod);
}
static int command_setcompression(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetCompression,
sd->params.compression.mode,
sd->params.compression.decimation, 0, 0);
}
static int command_setsensorfps(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetSensorFPS,
sd->params.sensorFps.divisor,
sd->params.sensorFps.baserate, 0, 0);
}
static int command_setflickerctrl(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetFlickerCtrl,
sd->params.flickerControl.flickerMode,
sd->params.flickerControl.coarseJump,
sd->params.flickerControl.allowableOverExposure,
0);
}
static int command_setecptiming(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_SetECPTiming,
sd->params.ecpTiming, 0, 0, 0);
}
static int command_pause(struct gspca_dev *gspca_dev)
{
return do_command(gspca_dev, CPIA_COMMAND_EndStreamCap, 0, 0, 0, 0);
}
static int command_resume(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return do_command(gspca_dev, CPIA_COMMAND_InitStreamCap,
0, sd->params.streamStartLine, 0, 0);
}
static int command_setlights(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret, p1, p2;
p1 = (sd->params.qx3.bottomlight == 0) << 1;
p2 = (sd->params.qx3.toplight == 0) << 3;
ret = do_command(gspca_dev, CPIA_COMMAND_WriteVCReg,
0x90, 0x8f, 0x50, 0);
if (ret)
return ret;
return do_command(gspca_dev, CPIA_COMMAND_WriteMCPort, 2, 0,
p1 | p2 | 0xe0, 0);
}
static int set_flicker(struct gspca_dev *gspca_dev, int on, int apply)
{
#if 0
#define COMPGAIN(base, curexp, newexp) \
(u8) ((((float) base - 128.0) * ((float) curexp / (float) newexp)) + 128.5)
#define EXP_FROM_COMP(basecomp, curcomp, curexp) \
(u16)((float)curexp * (float)(u8)(curcomp + 128) / \
(float)(u8)(basecomp - 128))
#else
#define COMPGAIN(base, curexp, newexp) \
(u8)(128 + (((u32)(2*(base-128)*curexp + newexp)) / (2 * newexp)))
#define EXP_FROM_COMP(basecomp, curcomp, curexp) \
(u16)(((u32)(curexp * (u8)(curcomp + 128)) / (u8)(basecomp - 128)))
#endif
struct sd *sd = (struct sd *) gspca_dev;
int currentexp = sd->params.exposure.coarseExpLo +
sd->params.exposure.coarseExpHi * 256;
int ret, startexp;
if (on) {
int cj = sd->params.flickerControl.coarseJump;
sd->params.flickerControl.flickerMode = 1;
sd->params.flickerControl.disabled = 0;
if (sd->params.exposure.expMode != 2) {
sd->params.exposure.expMode = 2;
sd->exposure_status = EXPOSURE_NORMAL;
}
currentexp = currentexp << sd->params.exposure.gain;
sd->params.exposure.gain = 0;
startexp = (currentexp + ROUND_UP_EXP_FOR_FLICKER) / cj;
if (startexp < 1)
startexp = 1;
startexp = (startexp * cj) - 1;
if (FIRMWARE_VERSION(1, 2))
while (startexp > MAX_EXP_102)
startexp -= cj;
else
while (startexp > MAX_EXP)
startexp -= cj;
sd->params.exposure.coarseExpLo = startexp & 0xff;
sd->params.exposure.coarseExpHi = startexp >> 8;
if (currentexp > startexp) {
if (currentexp > (2 * startexp))
currentexp = 2 * startexp;
sd->params.exposure.redComp =
COMPGAIN(COMP_RED, currentexp, startexp);
sd->params.exposure.green1Comp =
COMPGAIN(COMP_GREEN1, currentexp, startexp);
sd->params.exposure.green2Comp =
COMPGAIN(COMP_GREEN2, currentexp, startexp);
sd->params.exposure.blueComp =
COMPGAIN(COMP_BLUE, currentexp, startexp);
} else {
sd->params.exposure.redComp = COMP_RED;
sd->params.exposure.green1Comp = COMP_GREEN1;
sd->params.exposure.green2Comp = COMP_GREEN2;
sd->params.exposure.blueComp = COMP_BLUE;
}
if (FIRMWARE_VERSION(1, 2))
sd->params.exposure.compMode = 0;
else
sd->params.exposure.compMode = 1;
sd->params.apcor.gain1 = 0x18;
sd->params.apcor.gain2 = 0x18;
sd->params.apcor.gain4 = 0x16;
sd->params.apcor.gain8 = 0x14;
} else {
sd->params.flickerControl.flickerMode = 0;
sd->params.flickerControl.disabled = 1;
startexp = EXP_FROM_COMP(COMP_RED,
sd->params.exposure.redComp, currentexp);
startexp += EXP_FROM_COMP(COMP_GREEN1,
sd->params.exposure.green1Comp, currentexp);
startexp += EXP_FROM_COMP(COMP_GREEN2,
sd->params.exposure.green2Comp, currentexp);
startexp += EXP_FROM_COMP(COMP_BLUE,
sd->params.exposure.blueComp, currentexp);
startexp = startexp >> 2;
while (startexp > MAX_EXP && sd->params.exposure.gain <
sd->params.exposure.gainMode - 1) {
startexp = startexp >> 1;
++sd->params.exposure.gain;
}
if (FIRMWARE_VERSION(1, 2) && startexp > MAX_EXP_102)
startexp = MAX_EXP_102;
if (startexp > MAX_EXP)
startexp = MAX_EXP;
sd->params.exposure.coarseExpLo = startexp & 0xff;
sd->params.exposure.coarseExpHi = startexp >> 8;
sd->params.exposure.redComp = COMP_RED;
sd->params.exposure.green1Comp = COMP_GREEN1;
sd->params.exposure.green2Comp = COMP_GREEN2;
sd->params.exposure.blueComp = COMP_BLUE;
sd->params.exposure.compMode = 1;
sd->params.apcor.gain1 = 0x18;
sd->params.apcor.gain2 = 0x16;
sd->params.apcor.gain4 = 0x24;
sd->params.apcor.gain8 = 0x34;
}
sd->params.vlOffset.gain1 = 20;
sd->params.vlOffset.gain2 = 24;
sd->params.vlOffset.gain4 = 26;
sd->params.vlOffset.gain8 = 26;
if (apply) {
ret = command_setexposure(gspca_dev);
if (ret)
return ret;
ret = command_setapcor(gspca_dev);
if (ret)
return ret;
ret = command_setvloffset(gspca_dev);
if (ret)
return ret;
ret = command_setflickerctrl(gspca_dev);
if (ret)
return ret;
}
return 0;
#undef EXP_FROM_COMP
#undef COMPGAIN
}
static void monitor_exposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 exp_acc, bcomp, cmd[8];
int ret, light_exp, dark_exp, very_dark_exp;
int old_exposure, new_exposure, framerate;
int setfps = 0, setexp = 0, setflicker = 0;
cmd[0] = CPIA_COMMAND_ReadVPRegs >> 8;
cmd[1] = CPIA_COMMAND_ReadVPRegs & 0xff;
cmd[2] = 30;
cmd[3] = 4;
cmd[4] = 9;
cmd[5] = 8;
cmd[6] = 8;
cmd[7] = 0;
ret = cpia_usb_transferCmd(gspca_dev, cmd);
if (ret) {
pr_err("ReadVPRegs(30,4,9,8) - failed: %d\n", ret);
return;
}
exp_acc = gspca_dev->usb_buf[0];
bcomp = gspca_dev->usb_buf[1];
light_exp = sd->params.colourParams.brightness +
TC - 50 + EXP_ACC_LIGHT;
if (light_exp > 255)
light_exp = 255;
dark_exp = sd->params.colourParams.brightness +
TC - 50 - EXP_ACC_DARK;
if (dark_exp < 0)
dark_exp = 0;
very_dark_exp = dark_exp / 2;
old_exposure = sd->params.exposure.coarseExpHi * 256 +
sd->params.exposure.coarseExpLo;
if (!sd->params.flickerControl.disabled) {
int max_comp = FIRMWARE_VERSION(1, 2) ? MAX_COMP :
HIGH_COMP_102;
bcomp += 128;
if (bcomp >= max_comp && exp_acc < dark_exp) {
if (exp_acc < very_dark_exp) {
if (sd->exposure_status == EXPOSURE_VERY_DARK)
++sd->exposure_count;
else {
sd->exposure_status =
EXPOSURE_VERY_DARK;
sd->exposure_count = 1;
}
} else {
if (sd->exposure_status == EXPOSURE_DARK)
++sd->exposure_count;
else {
sd->exposure_status = EXPOSURE_DARK;
sd->exposure_count = 1;
}
}
} else if (old_exposure <= LOW_EXP || exp_acc > light_exp) {
if (old_exposure <= VERY_LOW_EXP) {
if (sd->exposure_status == EXPOSURE_VERY_LIGHT)
++sd->exposure_count;
else {
sd->exposure_status =
EXPOSURE_VERY_LIGHT;
sd->exposure_count = 1;
}
} else {
if (sd->exposure_status == EXPOSURE_LIGHT)
++sd->exposure_count;
else {
sd->exposure_status = EXPOSURE_LIGHT;
sd->exposure_count = 1;
}
}
} else {
sd->exposure_status = EXPOSURE_NORMAL;
}
} else {
if (old_exposure >= MAX_EXP && exp_acc < dark_exp) {
if (exp_acc < very_dark_exp) {
if (sd->exposure_status == EXPOSURE_VERY_DARK)
++sd->exposure_count;
else {
sd->exposure_status =
EXPOSURE_VERY_DARK;
sd->exposure_count = 1;
}
} else {
if (sd->exposure_status == EXPOSURE_DARK)
++sd->exposure_count;
else {
sd->exposure_status = EXPOSURE_DARK;
sd->exposure_count = 1;
}
}
} else if (old_exposure <= LOW_EXP || exp_acc > light_exp) {
if (old_exposure <= VERY_LOW_EXP) {
if (sd->exposure_status == EXPOSURE_VERY_LIGHT)
++sd->exposure_count;
else {
sd->exposure_status =
EXPOSURE_VERY_LIGHT;
sd->exposure_count = 1;
}
} else {
if (sd->exposure_status == EXPOSURE_LIGHT)
++sd->exposure_count;
else {
sd->exposure_status = EXPOSURE_LIGHT;
sd->exposure_count = 1;
}
}
} else {
sd->exposure_status = EXPOSURE_NORMAL;
}
}
framerate = atomic_read(&sd->fps);
if (framerate > 30 || framerate < 1)
framerate = 1;
if (!sd->params.flickerControl.disabled) {
if ((sd->exposure_status == EXPOSURE_VERY_DARK ||
sd->exposure_status == EXPOSURE_DARK) &&
sd->exposure_count >= DARK_TIME * framerate &&
sd->params.sensorFps.divisor < 2) {
++sd->params.sensorFps.divisor;
setfps = 1;
sd->params.flickerControl.coarseJump =
flicker_jumps[sd->mainsFreq]
[sd->params.sensorFps.baserate]
[sd->params.sensorFps.divisor];
setflicker = 1;
new_exposure = sd->params.flickerControl.coarseJump-1;
while (new_exposure < old_exposure / 2)
new_exposure +=
sd->params.flickerControl.coarseJump;
sd->params.exposure.coarseExpLo = new_exposure & 0xff;
sd->params.exposure.coarseExpHi = new_exposure >> 8;
setexp = 1;
sd->exposure_status = EXPOSURE_NORMAL;
PDEBUG(D_CONF, "Automatically decreasing sensor_fps");
} else if ((sd->exposure_status == EXPOSURE_VERY_LIGHT ||
sd->exposure_status == EXPOSURE_LIGHT) &&
sd->exposure_count >= LIGHT_TIME * framerate &&
sd->params.sensorFps.divisor > 0) {
int max_exp = FIRMWARE_VERSION(1, 2) ? MAX_EXP_102 :
MAX_EXP;
--sd->params.sensorFps.divisor;
setfps = 1;
sd->params.flickerControl.coarseJump =
flicker_jumps[sd->mainsFreq]
[sd->params.sensorFps.baserate]
[sd->params.sensorFps.divisor];
setflicker = 1;
new_exposure = sd->params.flickerControl.coarseJump-1;
while (new_exposure < 2 * old_exposure &&
new_exposure +
sd->params.flickerControl.coarseJump < max_exp)
new_exposure +=
sd->params.flickerControl.coarseJump;
sd->params.exposure.coarseExpLo = new_exposure & 0xff;
sd->params.exposure.coarseExpHi = new_exposure >> 8;
setexp = 1;
sd->exposure_status = EXPOSURE_NORMAL;
PDEBUG(D_CONF, "Automatically increasing sensor_fps");
}
} else {
if ((sd->exposure_status == EXPOSURE_VERY_DARK ||
sd->exposure_status == EXPOSURE_DARK) &&
sd->exposure_count >= DARK_TIME * framerate &&
sd->params.sensorFps.divisor < 2) {
++sd->params.sensorFps.divisor;
setfps = 1;
if (sd->params.exposure.gain > 0) {
--sd->params.exposure.gain;
setexp = 1;
}
sd->exposure_status = EXPOSURE_NORMAL;
PDEBUG(D_CONF, "Automatically decreasing sensor_fps");
} else if ((sd->exposure_status == EXPOSURE_VERY_LIGHT ||
sd->exposure_status == EXPOSURE_LIGHT) &&
sd->exposure_count >= LIGHT_TIME * framerate &&
sd->params.sensorFps.divisor > 0) {
--sd->params.sensorFps.divisor;
setfps = 1;
if (sd->params.exposure.gain <
sd->params.exposure.gainMode - 1) {
++sd->params.exposure.gain;
setexp = 1;
}
sd->exposure_status = EXPOSURE_NORMAL;
PDEBUG(D_CONF, "Automatically increasing sensor_fps");
}
}
if (setexp)
command_setexposure(gspca_dev);
if (setfps)
command_setsensorfps(gspca_dev);
if (setflicker)
command_setflickerctrl(gspca_dev);
}
static void restart_flicker(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int cam_exposure, old_exp;
if (!FIRMWARE_VERSION(1, 2))
return;
cam_exposure = atomic_read(&sd->cam_exposure);
if (sd->params.flickerControl.flickerMode == 0 ||
cam_exposure == 0)
return;
old_exp = sd->params.exposure.coarseExpLo +
sd->params.exposure.coarseExpHi*256;
cam_exposure %= sd->params.flickerControl.coarseJump;
if (!sd->params.flickerControl.disabled &&
cam_exposure <= sd->params.flickerControl.coarseJump - 3) {
sd->params.flickerControl.disabled = 1;
}
if (sd->params.flickerControl.disabled &&
old_exp > sd->params.flickerControl.coarseJump +
ROUND_UP_EXP_FOR_FLICKER) {
set_flicker(gspca_dev, 1, 1);
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
sd->mainsFreq = FREQ_DEF == V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
reset_camera_params(gspca_dev);
PDEBUG(D_PROBE, "cpia CPiA camera detected (vid/pid 0x%04X:0x%04X)",
id->idVendor, id->idProduct);
cam = &gspca_dev->cam;
cam->cam_mode = mode;
cam->nmodes = ARRAY_SIZE(mode);
goto_low_power(gspca_dev);
sd->params.version.firmwareVersion = 0;
get_version_information(gspca_dev);
if (sd->params.version.firmwareVersion != 1) {
PDEBUG(D_ERR, "only firmware version 1 is supported (got: %d)",
sd->params.version.firmwareVersion);
return -ENODEV;
}
if (sd->params.version.firmwareRevision <= 2 &&
sd->params.exposure.gainMode > 2) {
sd->params.exposure.gainMode = 2;
}
sd->params.qx3.qx3_detected = (sd->params.pnpID.vendor == 0x0813 &&
sd->params.pnpID.product == 0x0001);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int priv, ret;
if (goto_low_power(gspca_dev)) {
if (sd->params.status.systemState != WARM_BOOT_STATE) {
PDEBUG(D_ERR, "unexpected systemstate: %02x",
sd->params.status.systemState);
printstatus(&sd->params);
return -ENODEV;
}
ret = goto_high_power(gspca_dev);
if (ret)
return ret;
ret = do_command(gspca_dev, CPIA_COMMAND_DiscardFrame,
0, 0, 0, 0);
if (ret)
return ret;
ret = goto_low_power(gspca_dev);
if (ret)
return ret;
}
sd->params.version.firmwareVersion = 0;
get_version_information(gspca_dev);
ret = do_command(gspca_dev, CPIA_COMMAND_ModifyCameraStatus,
STREAMSTATE, 0, STREAM_NOT_READY, 0);
if (ret)
return ret;
ret = goto_high_power(gspca_dev);
if (ret)
return ret;
ret = do_command(gspca_dev, CPIA_COMMAND_GetCameraStatus, 0, 0, 0, 0);
if (ret)
return ret;
if (sd->params.status.fatalError) {
PDEBUG(D_ERR, "fatal_error: %04x, vp_status: %04x",
sd->params.status.fatalError,
sd->params.status.vpStatus);
return -EIO;
}
ret = do_command(gspca_dev, CPIA_COMMAND_GetVPVersion, 0, 0, 0, 0);
if (ret)
return ret;
sd->params.streamStartLine = 120;
priv = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
if (priv & 0x01) {
sd->params.roi.colStart = 2;
sd->params.roi.rowStart = 6;
} else {
sd->params.roi.colStart = 0;
sd->params.roi.rowStart = 0;
}
if (priv & 0x02) {
sd->params.format.videoSize = VIDEOSIZE_QCIF;
sd->params.roi.colStart /= 2;
sd->params.roi.rowStart /= 2;
sd->params.streamStartLine /= 2;
} else
sd->params.format.videoSize = VIDEOSIZE_CIF;
sd->params.roi.colEnd = sd->params.roi.colStart +
(gspca_dev->width >> 3);
sd->params.roi.rowEnd = sd->params.roi.rowStart +
(gspca_dev->height >> 2);
ret = do_command(gspca_dev, CPIA_COMMAND_SetGrabMode,
CPIA_GRAB_CONTINEOUS, 0, 0, 0);
if (ret)
return ret;
ret = do_command(gspca_dev, CPIA_COMMAND_SetCompression,
CPIA_COMPRESSION_NONE,
NO_DECIMATION, 0, 0);
if (ret)
return ret;
ret = command_setcompressiontarget(gspca_dev);
if (ret)
return ret;
ret = command_setcolourparams(gspca_dev);
if (ret)
return ret;
ret = command_setformat(gspca_dev);
if (ret)
return ret;
ret = command_setyuvtresh(gspca_dev);
if (ret)
return ret;
ret = command_setecptiming(gspca_dev);
if (ret)
return ret;
ret = command_setcompressionparams(gspca_dev);
if (ret)
return ret;
ret = command_setexposure(gspca_dev);
if (ret)
return ret;
ret = command_setcolourbalance(gspca_dev);
if (ret)
return ret;
ret = command_setsensorfps(gspca_dev);
if (ret)
return ret;
ret = command_setapcor(gspca_dev);
if (ret)
return ret;
ret = command_setflickerctrl(gspca_dev);
if (ret)
return ret;
ret = command_setvloffset(gspca_dev);
if (ret)
return ret;
ret = command_resume(gspca_dev);
if (ret)
return ret;
sd->first_frame = 6;
sd->exposure_status = EXPOSURE_NORMAL;
sd->exposure_count = 0;
atomic_set(&sd->cam_exposure, 0);
atomic_set(&sd->fps, 0);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
command_pause(gspca_dev);
save_camera_state(gspca_dev);
goto_low_power(gspca_dev);
do_command(gspca_dev, CPIA_COMMAND_GetCameraStatus, 0, 0, 0, 0);
#if defined(CONFIG_INPUT) || defined(CONFIG_INPUT_MODULE)
if (sd->params.qx3.button) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
}
#endif
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
ret = sd_start(gspca_dev);
if (ret)
return ret;
if (sd->params.qx3.qx3_detected)
command_setlights(gspca_dev);
sd_stopN(gspca_dev);
PDEBUG(D_PROBE, "CPIA Version: %d.%02d (%d.%d)",
sd->params.version.firmwareVersion,
sd->params.version.firmwareRevision,
sd->params.version.vcVersion,
sd->params.version.vcRevision);
PDEBUG(D_PROBE, "CPIA PnP-ID: %04x:%04x:%04x",
sd->params.pnpID.vendor, sd->params.pnpID.product,
sd->params.pnpID.deviceRevision);
PDEBUG(D_PROBE, "VP-Version: %d.%d %04x",
sd->params.vpVersion.vpVersion,
sd->params.vpVersion.vpRevision,
sd->params.vpVersion.cameraHeadID);
return 0;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (len >= 64 &&
data[0] == MAGIC_0 && data[1] == MAGIC_1 &&
data[16] == sd->params.format.videoSize &&
data[17] == sd->params.format.subSample &&
data[18] == sd->params.format.yuvOrder &&
data[24] == sd->params.roi.colStart &&
data[25] == sd->params.roi.colEnd &&
data[26] == sd->params.roi.rowStart &&
data[27] == sd->params.roi.rowEnd) {
u8 *image;
atomic_set(&sd->cam_exposure, data[39] * 2);
atomic_set(&sd->fps, data[41]);
image = gspca_dev->image;
if (image != NULL &&
gspca_dev->image_len > 4 &&
image[gspca_dev->image_len - 4] == 0xff &&
image[gspca_dev->image_len - 3] == 0xff &&
image[gspca_dev->image_len - 2] == 0xff &&
image[gspca_dev->image_len - 1] == 0xff)
gspca_frame_add(gspca_dev, LAST_PACKET,
NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
return;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static void sd_dq_callback(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->first_frame) {
sd->first_frame--;
if (sd->first_frame == 0)
command_setcompression(gspca_dev);
}
restart_flicker(gspca_dev);
if (sd->params.exposure.expMode == 2)
monitor_exposure(gspca_dev);
do_command(gspca_dev, CPIA_COMMAND_GetExposure, 0, 0, 0, 0);
do_command(gspca_dev, CPIA_COMMAND_ReadMCPorts, 0, 0, 0, 0);
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming && ctrl->id != V4L2_CID_POWER_LINE_FREQUENCY)
return 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
sd->params.colourParams.brightness = ctrl->val;
sd->params.flickerControl.allowableOverExposure =
find_over_exposure(sd->params.colourParams.brightness);
gspca_dev->usb_err = command_setcolourparams(gspca_dev);
if (!gspca_dev->usb_err)
gspca_dev->usb_err = command_setflickerctrl(gspca_dev);
break;
case V4L2_CID_CONTRAST:
sd->params.colourParams.contrast = ctrl->val;
gspca_dev->usb_err = command_setcolourparams(gspca_dev);
break;
case V4L2_CID_SATURATION:
sd->params.colourParams.saturation = ctrl->val;
gspca_dev->usb_err = command_setcolourparams(gspca_dev);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
sd->mainsFreq = ctrl->val == V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
sd->params.flickerControl.coarseJump =
flicker_jumps[sd->mainsFreq]
[sd->params.sensorFps.baserate]
[sd->params.sensorFps.divisor];
gspca_dev->usb_err = set_flicker(gspca_dev,
ctrl->val != V4L2_CID_POWER_LINE_FREQUENCY_DISABLED,
gspca_dev->streaming);
break;
case V4L2_CID_ILLUMINATORS_1:
sd->params.qx3.bottomlight = ctrl->val;
gspca_dev->usb_err = command_setlights(gspca_dev);
break;
case V4L2_CID_ILLUMINATORS_2:
sd->params.qx3.toplight = ctrl->val;
gspca_dev->usb_err = command_setlights(gspca_dev);
break;
case CPIA1_CID_COMP_TARGET:
sd->params.compressionTarget.frTargeting = ctrl->val;
gspca_dev->usb_err = command_setcompressiontarget(gspca_dev);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
static const char * const comp_target_menu[] = {
"Quality",
"Framerate",
NULL
};
static const struct v4l2_ctrl_config comp_target = {
.ops = &sd_ctrl_ops,
.id = CPIA1_CID_COMP_TARGET,
.type = V4L2_CTRL_TYPE_MENU,
.name = "Compression Target",
.qmenu = comp_target_menu,
.max = 1,
.def = COMP_TARGET_DEF,
};
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 7);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 100, 1, BRIGHTNESS_DEF);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 96, 8, CONTRAST_DEF);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 100, 1, SATURATION_DEF);
sd->freq = v4l2_ctrl_new_std_menu(hdl, &sd_ctrl_ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, 0,
FREQ_DEF);
if (sd->params.qx3.qx3_detected) {
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_ILLUMINATORS_1, 0, 1, 1,
ILLUMINATORS_1_DEF);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_ILLUMINATORS_2, 0, 1, 1,
ILLUMINATORS_2_DEF);
}
v4l2_ctrl_new_custom(hdl, &comp_target, NULL);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
