static inline struct CHIPSTATE *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct CHIPSTATE, sd);
}
static int chip_write(struct CHIPSTATE *chip, int subaddr, int val)
{
struct v4l2_subdev *sd = &chip->sd;
struct i2c_client *c = v4l2_get_subdevdata(sd);
unsigned char buffer[2];
if (subaddr < 0) {
v4l2_dbg(1, debug, sd, "chip_write: 0x%x\n", val);
chip->shadow.bytes[1] = val;
buffer[0] = val;
if (1 != i2c_master_send(c, buffer, 1)) {
v4l2_warn(sd, "I/O error (write 0x%x)\n", val);
return -1;
}
} else {
if (subaddr + 1 >= ARRAY_SIZE(chip->shadow.bytes)) {
v4l2_info(sd,
"Tried to access a non-existent register: %d\n",
subaddr);
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "chip_write: reg%d=0x%x\n",
subaddr, val);
chip->shadow.bytes[subaddr+1] = val;
buffer[0] = subaddr;
buffer[1] = val;
if (2 != i2c_master_send(c, buffer, 2)) {
v4l2_warn(sd, "I/O error (write reg%d=0x%x)\n",
subaddr, val);
return -1;
}
}
return 0;
}
static int chip_write_masked(struct CHIPSTATE *chip,
int subaddr, int val, int mask)
{
struct v4l2_subdev *sd = &chip->sd;
if (mask != 0) {
if (subaddr < 0) {
val = (chip->shadow.bytes[1] & ~mask) | (val & mask);
} else {
if (subaddr + 1 >= ARRAY_SIZE(chip->shadow.bytes)) {
v4l2_info(sd,
"Tried to access a non-existent register: %d\n",
subaddr);
return -EINVAL;
}
val = (chip->shadow.bytes[subaddr+1] & ~mask) | (val & mask);
}
}
return chip_write(chip, subaddr, val);
}
static int chip_read(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
struct i2c_client *c = v4l2_get_subdevdata(sd);
unsigned char buffer;
if (1 != i2c_master_recv(c, &buffer, 1)) {
v4l2_warn(sd, "I/O error (read)\n");
return -1;
}
v4l2_dbg(1, debug, sd, "chip_read: 0x%x\n", buffer);
return buffer;
}
static int chip_read2(struct CHIPSTATE *chip, int subaddr)
{
struct v4l2_subdev *sd = &chip->sd;
struct i2c_client *c = v4l2_get_subdevdata(sd);
unsigned char write[1];
unsigned char read[1];
struct i2c_msg msgs[2] = {
{ c->addr, 0, 1, write },
{ c->addr, I2C_M_RD, 1, read }
};
write[0] = subaddr;
if (2 != i2c_transfer(c->adapter, msgs, 2)) {
v4l2_warn(sd, "I/O error (read2)\n");
return -1;
}
v4l2_dbg(1, debug, sd, "chip_read2: reg%d=0x%x\n",
subaddr, read[0]);
return read[0];
}
static int chip_cmd(struct CHIPSTATE *chip, char *name, audiocmd *cmd)
{
struct v4l2_subdev *sd = &chip->sd;
struct i2c_client *c = v4l2_get_subdevdata(sd);
int i;
if (0 == cmd->count)
return 0;
if (cmd->count + cmd->bytes[0] - 1 >= ARRAY_SIZE(chip->shadow.bytes)) {
v4l2_info(sd,
"Tried to access a non-existent register range: %d to %d\n",
cmd->bytes[0] + 1, cmd->bytes[0] + cmd->count - 1);
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "chip_cmd(%s): reg=%d, data:",
name, cmd->bytes[0]);
for (i = 1; i < cmd->count; i++) {
if (debug)
printk(KERN_CONT " 0x%x", cmd->bytes[i]);
chip->shadow.bytes[i+cmd->bytes[0]] = cmd->bytes[i];
}
if (debug)
printk(KERN_CONT "\n");
if (cmd->count != i2c_master_send(c, cmd->bytes, cmd->count)) {
v4l2_warn(sd, "I/O error (%s)\n", name);
return -1;
}
return 0;
}
static void chip_thread_wake(unsigned long data)
{
struct CHIPSTATE *chip = (struct CHIPSTATE*)data;
wake_up_process(chip->thread);
}
static int chip_thread(void *data)
{
struct CHIPSTATE *chip = data;
struct CHIPDESC *desc = chip->desc;
struct v4l2_subdev *sd = &chip->sd;
int mode;
v4l2_dbg(1, debug, sd, "thread started\n");
set_freezable();
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (!kthread_should_stop())
schedule();
set_current_state(TASK_RUNNING);
try_to_freeze();
if (kthread_should_stop())
break;
v4l2_dbg(1, debug, sd, "thread wakeup\n");
if (chip->radio || chip->mode != 0)
continue;
mode = desc->getmode(chip);
if (mode == chip->prevmode)
continue;
v4l2_dbg(1, debug, sd, "thread checkmode\n");
chip->prevmode = mode;
if (mode & V4L2_TUNER_MODE_STEREO)
desc->setmode(chip, V4L2_TUNER_MODE_STEREO);
if (mode & V4L2_TUNER_MODE_LANG1_LANG2)
desc->setmode(chip, V4L2_TUNER_MODE_STEREO);
else if (mode & V4L2_TUNER_MODE_LANG1)
desc->setmode(chip, V4L2_TUNER_MODE_LANG1);
else if (mode & V4L2_TUNER_MODE_LANG2)
desc->setmode(chip, V4L2_TUNER_MODE_LANG2);
else
desc->setmode(chip, V4L2_TUNER_MODE_MONO);
mod_timer(&chip->wt, jiffies+msecs_to_jiffies(2000));
}
v4l2_dbg(1, debug, sd, "thread exiting\n");
return 0;
}
static int tda9840_getmode(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
int val, mode;
val = chip_read(chip);
mode = V4L2_TUNER_MODE_MONO;
if (val & TDA9840_DS_DUAL)
mode |= V4L2_TUNER_MODE_LANG1 | V4L2_TUNER_MODE_LANG2;
if (val & TDA9840_ST_STEREO)
mode |= V4L2_TUNER_MODE_STEREO;
v4l2_dbg(1, debug, sd, "tda9840_getmode(): raw chip read: %d, return: %d\n",
val, mode);
return mode;
}
static void tda9840_setmode(struct CHIPSTATE *chip, int mode)
{
int update = 1;
int t = chip->shadow.bytes[TDA9840_SW + 1] & ~0x7e;
switch (mode) {
case V4L2_TUNER_MODE_MONO:
t |= TDA9840_MONO;
break;
case V4L2_TUNER_MODE_STEREO:
t |= TDA9840_STEREO;
break;
case V4L2_TUNER_MODE_LANG1:
t |= TDA9840_DUALA;
break;
case V4L2_TUNER_MODE_LANG2:
t |= TDA9840_DUALB;
break;
default:
update = 0;
}
if (update)
chip_write(chip, TDA9840_SW, t);
}
static int tda9840_checkit(struct CHIPSTATE *chip)
{
int rc;
rc = chip_read(chip);
return ((rc & 0x1f) == 0) ? 1 : 0;
}
static int tda9855_volume(int val) { return val/0x2e8+0x27; }
static int tda9855_bass(int val) { return val/0xccc+0x06; }
static int tda9855_treble(int val) { return (val/0x1c71+0x3)<<1; }
static int tda985x_getmode(struct CHIPSTATE *chip)
{
int mode;
mode = ((TDA985x_STP | TDA985x_SAPP) &
chip_read(chip)) >> 4;
return mode | V4L2_TUNER_MODE_MONO;
}
static void tda985x_setmode(struct CHIPSTATE *chip, int mode)
{
int update = 1;
int c6 = chip->shadow.bytes[TDA985x_C6+1] & 0x3f;
switch (mode) {
case V4L2_TUNER_MODE_MONO:
c6 |= TDA985x_MONO;
break;
case V4L2_TUNER_MODE_STEREO:
c6 |= TDA985x_STEREO;
break;
case V4L2_TUNER_MODE_LANG1:
c6 |= TDA985x_SAP;
break;
default:
update = 0;
}
if (update)
chip_write(chip,TDA985x_C6,c6);
}
static int tda9873_getmode(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
int val,mode;
val = chip_read(chip);
mode = V4L2_TUNER_MODE_MONO;
if (val & TDA9873_STEREO)
mode |= V4L2_TUNER_MODE_STEREO;
if (val & TDA9873_DUAL)
mode |= V4L2_TUNER_MODE_LANG1 | V4L2_TUNER_MODE_LANG2;
v4l2_dbg(1, debug, sd, "tda9873_getmode(): raw chip read: %d, return: %d\n",
val, mode);
return mode;
}
static void tda9873_setmode(struct CHIPSTATE *chip, int mode)
{
struct v4l2_subdev *sd = &chip->sd;
int sw_data = chip->shadow.bytes[TDA9873_SW+1] & ~ TDA9873_TR_MASK;
if ((sw_data & TDA9873_INP_MASK) != TDA9873_INTERNAL) {
v4l2_dbg(1, debug, sd, "tda9873_setmode(): external input\n");
return;
}
v4l2_dbg(1, debug, sd, "tda9873_setmode(): chip->shadow.bytes[%d] = %d\n", TDA9873_SW+1, chip->shadow.bytes[TDA9873_SW+1]);
v4l2_dbg(1, debug, sd, "tda9873_setmode(): sw_data = %d\n", sw_data);
switch (mode) {
case V4L2_TUNER_MODE_MONO:
sw_data |= TDA9873_TR_MONO;
break;
case V4L2_TUNER_MODE_STEREO:
sw_data |= TDA9873_TR_STEREO;
break;
case V4L2_TUNER_MODE_LANG1:
sw_data |= TDA9873_TR_DUALA;
break;
case V4L2_TUNER_MODE_LANG2:
sw_data |= TDA9873_TR_DUALB;
break;
default:
chip->mode = 0;
return;
}
chip_write(chip, TDA9873_SW, sw_data);
v4l2_dbg(1, debug, sd, "tda9873_setmode(): req. mode %d; chip_write: %d\n",
mode, sw_data);
}
static int tda9873_checkit(struct CHIPSTATE *chip)
{
int rc;
if (-1 == (rc = chip_read2(chip,254)))
return 0;
return (rc & ~0x1f) == 0x80;
}
static int tda9874a_setup(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
chip_write(chip, TDA9874A_AGCGR, 0x00);
chip_write(chip, TDA9874A_GCONR, tda9874a_GCONR);
chip_write(chip, TDA9874A_MSR, (tda9874a_mode) ? 0x03:0x02);
if(tda9874a_dic == 0x11) {
chip_write(chip, TDA9874A_FMMR, 0x80);
} else {
chip_cmd(chip,"tda9874_modelist",&tda9874a_modelist[tda9874a_STD].cmd);
chip_write(chip, TDA9874A_FMMR, 0x00);
}
chip_write(chip, TDA9874A_C1OLAR, 0x00);
chip_write(chip, TDA9874A_C2OLAR, 0x00);
chip_write(chip, TDA9874A_NCONR, tda9874a_NCONR);
chip_write(chip, TDA9874A_NOLAR, 0x00);
chip_write(chip, TDA9874A_NLELR, 0x14);
chip_write(chip, TDA9874A_NUELR, 0x50);
if(tda9874a_dic == 0x11) {
chip_write(chip, TDA9874A_AMCONR, 0xf9);
chip_write(chip, TDA9874A_SDACOSR, (tda9874a_mode) ? 0x81:0x80);
chip_write(chip, TDA9874A_AOSR, 0x80);
chip_write(chip, TDA9874A_MDACOSR, (tda9874a_mode) ? 0x82:0x80);
chip_write(chip, TDA9874A_ESP, tda9874a_ESP);
} else {
chip_write(chip, TDA9874A_AMCONR, 0xfb);
chip_write(chip, TDA9874A_SDACOSR, (tda9874a_mode) ? 0x81:0x80);
chip_write(chip, TDA9874A_AOSR, 0x00);
}
v4l2_dbg(1, debug, sd, "tda9874a_setup(): %s [0x%02X].\n",
tda9874a_modelist[tda9874a_STD].name,tda9874a_STD);
return 1;
}
static int tda9874a_getmode(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
int dsr,nsr,mode;
int necr;
mode = V4L2_TUNER_MODE_MONO;
if(-1 == (dsr = chip_read2(chip,TDA9874A_DSR)))
return mode;
if(-1 == (nsr = chip_read2(chip,TDA9874A_NSR)))
return mode;
if(-1 == (necr = chip_read2(chip,TDA9874A_NECR)))
return mode;
chip->shadow.bytes[MAXREGS-2] = dsr;
chip->shadow.bytes[MAXREGS-1] = nsr;
if(tda9874a_mode) {
if(nsr & 0x02)
mode |= V4L2_TUNER_MODE_STEREO;
if(nsr & 0x01)
mode |= V4L2_TUNER_MODE_LANG1 | V4L2_TUNER_MODE_LANG2;
} else {
if(dsr & 0x02)
mode |= V4L2_TUNER_MODE_STEREO;
if(dsr & 0x04)
mode |= V4L2_TUNER_MODE_LANG1 | V4L2_TUNER_MODE_LANG2;
}
v4l2_dbg(1, debug, sd, "tda9874a_getmode(): DSR=0x%X, NSR=0x%X, NECR=0x%X, return: %d.\n",
dsr, nsr, necr, mode);
return mode;
}
static void tda9874a_setmode(struct CHIPSTATE *chip, int mode)
{
struct v4l2_subdev *sd = &chip->sd;
if (tda9874a_mode) {
if(chip->shadow.bytes[MAXREGS-2] & 0x20)
tda9874a_NCONR &= 0xfe;
else
tda9874a_NCONR |= 0x01;
chip_write(chip, TDA9874A_NCONR, tda9874a_NCONR);
}
if(tda9874a_dic == 0x11) {
int aosr = 0x80;
int mdacosr = (tda9874a_mode) ? 0x82:0x80;
switch(mode) {
case V4L2_TUNER_MODE_MONO:
case V4L2_TUNER_MODE_STEREO:
break;
case V4L2_TUNER_MODE_LANG1:
aosr = 0x80;
mdacosr = (tda9874a_mode) ? 0x82:0x80;
break;
case V4L2_TUNER_MODE_LANG2:
aosr = 0xa0;
mdacosr = (tda9874a_mode) ? 0x83:0x81;
break;
default:
chip->mode = 0;
return;
}
chip_write(chip, TDA9874A_AOSR, aosr);
chip_write(chip, TDA9874A_MDACOSR, mdacosr);
v4l2_dbg(1, debug, sd, "tda9874a_setmode(): req. mode %d; AOSR=0x%X, MDACOSR=0x%X.\n",
mode, aosr, mdacosr);
} else {
int fmmr,aosr;
switch(mode) {
case V4L2_TUNER_MODE_MONO:
fmmr = 0x00;
aosr = 0x10;
break;
case V4L2_TUNER_MODE_STEREO:
if(tda9874a_mode) {
fmmr = 0x00;
aosr = 0x00;
} else {
fmmr = (tda9874a_ESP == 1) ? 0x05 : 0x04;
aosr = 0x00;
}
break;
case V4L2_TUNER_MODE_LANG1:
fmmr = 0x02;
aosr = 0x10;
break;
case V4L2_TUNER_MODE_LANG2:
fmmr = 0x02;
aosr = 0x20;
break;
default:
chip->mode = 0;
return;
}
chip_write(chip, TDA9874A_FMMR, fmmr);
chip_write(chip, TDA9874A_AOSR, aosr);
v4l2_dbg(1, debug, sd, "tda9874a_setmode(): req. mode %d; FMMR=0x%X, AOSR=0x%X.\n",
mode, fmmr, aosr);
}
}
static int tda9874a_checkit(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
int dic,sic;
if(-1 == (dic = chip_read2(chip,TDA9874A_DIC)))
return 0;
if(-1 == (sic = chip_read2(chip,TDA9874A_SIC)))
return 0;
v4l2_dbg(1, debug, sd, "tda9874a_checkit(): DIC=0x%X, SIC=0x%X.\n", dic, sic);
if((dic == 0x11)||(dic == 0x07)) {
v4l2_info(sd, "found tda9874%s.\n", (dic == 0x11) ? "a" : "h");
tda9874a_dic = dic;
return 1;
}
return 0;
}
static int tda9874a_initialize(struct CHIPSTATE *chip)
{
if (tda9874a_SIF > 2)
tda9874a_SIF = 1;
if (tda9874a_STD >= ARRAY_SIZE(tda9874a_modelist))
tda9874a_STD = 0;
if(tda9874a_AMSEL > 1)
tda9874a_AMSEL = 0;
if(tda9874a_SIF == 1)
tda9874a_GCONR = 0xc0;
else
tda9874a_GCONR = 0xc1;
tda9874a_ESP = tda9874a_STD;
tda9874a_mode = (tda9874a_STD < 5) ? 0 : 1;
if(tda9874a_AMSEL == 0)
tda9874a_NCONR = 0x01;
else
tda9874a_NCONR = 0x05;
tda9874a_setup(chip);
return 0;
}
static int tda9875_initialize(struct CHIPSTATE *chip)
{
chip_write(chip, TDA9875_CFG, 0xd0);
chip_write(chip, TDA9875_MSR, 0x03);
chip_write(chip, TDA9875_C1MSB, 0x00);
chip_write(chip, TDA9875_C1MIB, 0x00);
chip_write(chip, TDA9875_C1LSB, 0x00);
chip_write(chip, TDA9875_C2MSB, 0x00);
chip_write(chip, TDA9875_C2MIB, 0x00);
chip_write(chip, TDA9875_C2LSB, 0x00);
chip_write(chip, TDA9875_DCR, 0x00);
chip_write(chip, TDA9875_DEEM, 0x44);
chip_write(chip, TDA9875_FMAT, 0x00);
chip_write(chip, TDA9875_SC1, 0x00);
chip_write(chip, TDA9875_SC2, 0x01);
chip_write(chip, TDA9875_CH1V, 0x10);
chip_write(chip, TDA9875_CH2V, 0x10);
chip_write(chip, TDA9875_DACOS, 0x02);
chip_write(chip, TDA9875_ADCIS, 0x6f);
chip_write(chip, TDA9875_LOSR, 0x00);
chip_write(chip, TDA9875_AER, 0x00);
chip_write(chip, TDA9875_MCS, 0x44);
chip_write(chip, TDA9875_MVL, 0x03);
chip_write(chip, TDA9875_MVR, 0x03);
chip_write(chip, TDA9875_MBA, 0x00);
chip_write(chip, TDA9875_MTR, 0x00);
chip_write(chip, TDA9875_ACS, 0x44);
chip_write(chip, TDA9875_AVL, 0x00);
chip_write(chip, TDA9875_AVR, 0x00);
chip_write(chip, TDA9875_ABA, 0x00);
chip_write(chip, TDA9875_ATR, 0x00);
chip_write(chip, TDA9875_MUT, 0xcc);
return 0;
}
static int tda9875_volume(int val) { return (unsigned char)(val / 602 - 84); }
static int tda9875_bass(int val) { return (unsigned char)(max(-12, val / 2115 - 15)); }
static int tda9875_treble(int val) { return (unsigned char)(val / 2622 - 12); }
static int tda9875_checkit(struct CHIPSTATE *chip)
{
struct v4l2_subdev *sd = &chip->sd;
int dic, rev;
dic = chip_read2(chip, 254);
rev = chip_read2(chip, 255);
if (dic == 0 || dic == 2) {
v4l2_info(sd, "found tda9875%s rev. %d.\n",
dic == 0 ? "" : "A", rev);
return 1;
}
return 0;
}
static int tea6300_shift10(int val) { return val >> 10; }
static int tea6300_shift12(int val) { return val >> 12; }
static int tea6320_volume(int val) { return (val / (65535/(63-12)) + 12) & 0x3f; }
static int tea6320_shift11(int val) { return val >> 11; }
static int tea6320_initialize(struct CHIPSTATE * chip)
{
chip_write(chip, TEA6320_FFR, 0x3f);
chip_write(chip, TEA6320_FFL, 0x3f);
chip_write(chip, TEA6320_FRR, 0x3f);
chip_write(chip, TEA6320_FRL, 0x3f);
return 0;
}
static int tda8425_shift10(int val) { return (val >> 10) | 0xc0; }
static int tda8425_shift12(int val) { return (val >> 12) | 0xf0; }
static void tda8425_setmode(struct CHIPSTATE *chip, int mode)
{
int s1 = chip->shadow.bytes[TDA8425_S1+1] & 0xe1;
if (mode & V4L2_TUNER_MODE_LANG1) {
s1 |= TDA8425_S1_ML_SOUND_A;
s1 |= TDA8425_S1_STEREO_PSEUDO;
} else if (mode & V4L2_TUNER_MODE_LANG2) {
s1 |= TDA8425_S1_ML_SOUND_B;
s1 |= TDA8425_S1_STEREO_PSEUDO;
} else {
s1 |= TDA8425_S1_ML_STEREO;
if (mode & V4L2_TUNER_MODE_MONO)
s1 |= TDA8425_S1_STEREO_MONO;
if (mode & V4L2_TUNER_MODE_STEREO)
s1 |= TDA8425_S1_STEREO_SPATIAL;
}
chip_write(chip,TDA8425_S1,s1);
}
static int ta8874z_getmode(struct CHIPSTATE *chip)
{
int val, mode;
val = chip_read(chip);
mode = V4L2_TUNER_MODE_MONO;
if (val & TA8874Z_B1){
mode |= V4L2_TUNER_MODE_LANG1 | V4L2_TUNER_MODE_LANG2;
}else if (!(val & TA8874Z_B0)){
mode |= V4L2_TUNER_MODE_STEREO;
}
return mode;
}
static void ta8874z_setmode(struct CHIPSTATE *chip, int mode)
{
struct v4l2_subdev *sd = &chip->sd;
int update = 1;
audiocmd *t = NULL;
v4l2_dbg(1, debug, sd, "ta8874z_setmode(): mode: 0x%02x\n", mode);
switch(mode){
case V4L2_TUNER_MODE_MONO:
t = &ta8874z_mono;
break;
case V4L2_TUNER_MODE_STEREO:
t = &ta8874z_stereo;
break;
case V4L2_TUNER_MODE_LANG1:
t = &ta8874z_main;
break;
case V4L2_TUNER_MODE_LANG2:
t = &ta8874z_sub;
break;
default:
update = 0;
}
if(update)
chip_cmd(chip, "TA8874Z", t);
}
static int ta8874z_checkit(struct CHIPSTATE *chip)
{
int rc;
rc = chip_read(chip);
return ((rc & 0x1f) == 0x1f) ? 1 : 0;
}
static int tvaudio_g_ctrl(struct v4l2_subdev *sd,
struct v4l2_control *ctrl)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (!(desc->flags & CHIP_HAS_INPUTSEL))
break;
ctrl->value=chip->muted;
return 0;
case V4L2_CID_AUDIO_VOLUME:
if (!(desc->flags & CHIP_HAS_VOLUME))
break;
ctrl->value = max(chip->left,chip->right);
return 0;
case V4L2_CID_AUDIO_BALANCE:
{
int volume;
if (!(desc->flags & CHIP_HAS_VOLUME))
break;
volume = max(chip->left,chip->right);
if (volume)
ctrl->value=(32768*min(chip->left,chip->right))/volume;
else
ctrl->value=32768;
return 0;
}
case V4L2_CID_AUDIO_BASS:
if (!(desc->flags & CHIP_HAS_BASSTREBLE))
break;
ctrl->value = chip->bass;
return 0;
case V4L2_CID_AUDIO_TREBLE:
if (!(desc->flags & CHIP_HAS_BASSTREBLE))
break;
ctrl->value = chip->treble;
return 0;
}
return -EINVAL;
}
static int tvaudio_s_ctrl(struct v4l2_subdev *sd,
struct v4l2_control *ctrl)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (!(desc->flags & CHIP_HAS_INPUTSEL))
break;
if (ctrl->value < 0 || ctrl->value >= 2)
return -ERANGE;
chip->muted = ctrl->value;
if (chip->muted)
chip_write_masked(chip,desc->inputreg,desc->inputmute,desc->inputmask);
else
chip_write_masked(chip,desc->inputreg,
desc->inputmap[chip->input],desc->inputmask);
return 0;
case V4L2_CID_AUDIO_VOLUME:
{
int volume,balance;
if (!(desc->flags & CHIP_HAS_VOLUME))
break;
volume = max(chip->left,chip->right);
if (volume)
balance=(32768*min(chip->left,chip->right))/volume;
else
balance=32768;
volume=ctrl->value;
chip->left = (min(65536 - balance,32768) * volume) / 32768;
chip->right = (min(balance,volume *(__u16)32768)) / 32768;
chip_write(chip,desc->leftreg,desc->volfunc(chip->left));
chip_write(chip,desc->rightreg,desc->volfunc(chip->right));
return 0;
}
case V4L2_CID_AUDIO_BALANCE:
{
int volume, balance;
if (!(desc->flags & CHIP_HAS_VOLUME))
break;
volume = max(chip->left, chip->right);
balance = ctrl->value;
chip->left = (min(65536 - balance, 32768) * volume) / 32768;
chip->right = (min(balance, volume * (__u16)32768)) / 32768;
chip_write(chip, desc->leftreg, desc->volfunc(chip->left));
chip_write(chip, desc->rightreg, desc->volfunc(chip->right));
return 0;
}
case V4L2_CID_AUDIO_BASS:
if (!(desc->flags & CHIP_HAS_BASSTREBLE))
break;
chip->bass = ctrl->value;
chip_write(chip,desc->bassreg,desc->bassfunc(chip->bass));
return 0;
case V4L2_CID_AUDIO_TREBLE:
if (!(desc->flags & CHIP_HAS_BASSTREBLE))
break;
chip->treble = ctrl->value;
chip_write(chip,desc->treblereg,desc->treblefunc(chip->treble));
return 0;
}
return -EINVAL;
}
static int tvaudio_s_radio(struct v4l2_subdev *sd)
{
struct CHIPSTATE *chip = to_state(sd);
chip->radio = 1;
chip->watch_stereo = 0;
return 0;
}
static int tvaudio_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
if (desc->flags & CHIP_HAS_INPUTSEL)
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 0);
break;
case V4L2_CID_AUDIO_VOLUME:
if (desc->flags & CHIP_HAS_VOLUME)
return v4l2_ctrl_query_fill(qc, 0, 65535, 65535 / 100, 58880);
break;
case V4L2_CID_AUDIO_BALANCE:
if (desc->flags & CHIP_HAS_VOLUME)
return v4l2_ctrl_query_fill(qc, 0, 65535, 65535 / 100, 32768);
break;
case V4L2_CID_AUDIO_BASS:
case V4L2_CID_AUDIO_TREBLE:
if (desc->flags & CHIP_HAS_BASSTREBLE)
return v4l2_ctrl_query_fill(qc, 0, 65535, 65535 / 100, 32768);
break;
default:
break;
}
return -EINVAL;
}
static int tvaudio_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
if (!(desc->flags & CHIP_HAS_INPUTSEL))
return 0;
if (input >= 4)
return -EINVAL;
chip->input = input;
if (chip->muted)
return 0;
chip_write_masked(chip, desc->inputreg,
desc->inputmap[chip->input], desc->inputmask);
return 0;
}
static int tvaudio_s_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
int mode = 0;
if (!desc->setmode)
return 0;
if (chip->radio)
return 0;
switch (vt->audmode) {
case V4L2_TUNER_MODE_MONO:
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1:
case V4L2_TUNER_MODE_LANG2:
mode = vt->audmode;
break;
case V4L2_TUNER_MODE_LANG1_LANG2:
mode = V4L2_TUNER_MODE_STEREO;
break;
default:
return -EINVAL;
}
chip->audmode = vt->audmode;
if (mode) {
chip->watch_stereo = 0;
chip->mode = mode;
desc->setmode(chip, mode);
}
return 0;
}
static int tvaudio_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
int mode = V4L2_TUNER_MODE_MONO;
if (!desc->getmode)
return 0;
if (chip->radio)
return 0;
vt->audmode = chip->audmode;
vt->rxsubchans = 0;
vt->capability = V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_LANG1 | V4L2_TUNER_CAP_LANG2;
mode = desc->getmode(chip);
if (mode & V4L2_TUNER_MODE_MONO)
vt->rxsubchans |= V4L2_TUNER_SUB_MONO;
if (mode & V4L2_TUNER_MODE_STEREO)
vt->rxsubchans |= V4L2_TUNER_SUB_STEREO;
if (mode & V4L2_TUNER_MODE_LANG1)
vt->rxsubchans = V4L2_TUNER_SUB_LANG1 |
V4L2_TUNER_SUB_LANG2;
return 0;
}
static int tvaudio_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct CHIPSTATE *chip = to_state(sd);
chip->radio = 0;
return 0;
}
static int tvaudio_s_frequency(struct v4l2_subdev *sd, struct v4l2_frequency *freq)
{
struct CHIPSTATE *chip = to_state(sd);
struct CHIPDESC *desc = chip->desc;
chip->mode = 0;
if (chip->thread) {
desc->setmode(chip, V4L2_TUNER_MODE_MONO);
if (chip->prevmode != V4L2_TUNER_MODE_MONO)
chip->prevmode = -1;
mod_timer(&chip->wt, jiffies+msecs_to_jiffies(2000));
}
return 0;
}
static int tvaudio_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_TVAUDIO, 0);
}
static int tvaudio_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct CHIPSTATE *chip;
struct CHIPDESC *desc;
struct v4l2_subdev *sd;
if (debug) {
printk(KERN_INFO "tvaudio: TV audio decoder + audio/video mux driver\n");
printk(KERN_INFO "tvaudio: known chips: ");
for (desc = chiplist; desc->name != NULL; desc++)
printk("%s%s", (desc == chiplist) ? "" : ", ", desc->name);
printk("\n");
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
sd = &chip->sd;
v4l2_i2c_subdev_init(sd, client, &tvaudio_ops);
v4l2_dbg(1, debug, sd, "chip found @ 0x%x\n", client->addr<<1);
for (desc = chiplist; desc->name != NULL; desc++) {
if (0 == *(desc->insmodopt))
continue;
if (client->addr < desc->addr_lo ||
client->addr > desc->addr_hi)
continue;
if (desc->checkit && !desc->checkit(chip))
continue;
break;
}
if (desc->name == NULL) {
v4l2_dbg(1, debug, sd, "no matching chip description found\n");
kfree(chip);
return -EIO;
}
v4l2_info(sd, "%s found @ 0x%x (%s)\n", desc->name, client->addr<<1, client->adapter->name);
if (desc->flags) {
v4l2_dbg(1, debug, sd, "matches:%s%s%s.\n",
(desc->flags & CHIP_HAS_VOLUME) ? " volume" : "",
(desc->flags & CHIP_HAS_BASSTREBLE) ? " bass/treble" : "",
(desc->flags & CHIP_HAS_INPUTSEL) ? " audiomux" : "");
}
if (!id)
strlcpy(client->name, desc->name, I2C_NAME_SIZE);
chip->desc = desc;
chip->shadow.count = desc->registers+1;
chip->prevmode = -1;
chip->audmode = V4L2_TUNER_MODE_LANG1;
if (desc->initialize != NULL)
desc->initialize(chip);
else
chip_cmd(chip, "init", &desc->init);
if (desc->flags & CHIP_HAS_VOLUME) {
if (!desc->volfunc) {
v4l2_info(sd, "volume callback undefined!\n");
desc->flags &= ~CHIP_HAS_VOLUME;
} else {
chip->left = desc->leftinit ? desc->leftinit : 65535;
chip->right = desc->rightinit ? desc->rightinit : 65535;
chip_write(chip, desc->leftreg,
desc->volfunc(chip->left));
chip_write(chip, desc->rightreg,
desc->volfunc(chip->right));
}
}
if (desc->flags & CHIP_HAS_BASSTREBLE) {
if (!desc->bassfunc || !desc->treblefunc) {
v4l2_info(sd, "bass/treble callbacks undefined!\n");
desc->flags &= ~CHIP_HAS_BASSTREBLE;
} else {
chip->treble = desc->trebleinit ?
desc->trebleinit : 32768;
chip->bass = desc->bassinit ?
desc->bassinit : 32768;
chip_write(chip, desc->bassreg,
desc->bassfunc(chip->bass));
chip_write(chip, desc->treblereg,
desc->treblefunc(chip->treble));
}
}
chip->thread = NULL;
init_timer(&chip->wt);
if (desc->flags & CHIP_NEED_CHECKMODE) {
if (!desc->getmode || !desc->setmode) {
v4l2_info(sd, "set/get mode callbacks undefined!\n");
return 0;
}
chip->wt.function = chip_thread_wake;
chip->wt.data = (unsigned long)chip;
chip->thread = kthread_run(chip_thread, chip, client->name);
if (IS_ERR(chip->thread)) {
v4l2_warn(sd, "failed to create kthread\n");
chip->thread = NULL;
}
}
return 0;
}
static int tvaudio_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct CHIPSTATE *chip = to_state(sd);
del_timer_sync(&chip->wt);
if (chip->thread) {
kthread_stop(chip->thread);
chip->thread = NULL;
}
v4l2_device_unregister_subdev(sd);
kfree(chip);
return 0;
}
static __init int init_tvaudio(void)
{
return i2c_add_driver(&tvaudio_driver);
}
static __exit void exit_tvaudio(void)
{
i2c_del_driver(&tvaudio_driver);
}
