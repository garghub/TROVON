const char *msp_standard_std_name(int std)
{
int i;
for (i = 0; msp_stdlist[i].name != NULL; i++)
if (msp_stdlist[i].retval == std)
return msp_stdlist[i].name;
return "unknown";
}
static void msp_set_source(struct i2c_client *client, u16 src)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
if (msp_dolby) {
msp_write_dsp(client, 0x0008, 0x0520);
msp_write_dsp(client, 0x0009, 0x0620);
} else {
msp_write_dsp(client, 0x0008, src);
msp_write_dsp(client, 0x0009, src);
}
msp_write_dsp(client, 0x000a, src);
msp_write_dsp(client, 0x000b, src);
msp_write_dsp(client, 0x000c, src);
if (state->has_scart2_out)
msp_write_dsp(client, 0x0041, src);
}
void msp3400c_set_carrier(struct i2c_client *client, int cdo1, int cdo2)
{
msp_write_dem(client, 0x0093, cdo1 & 0xfff);
msp_write_dem(client, 0x009b, cdo1 >> 12);
msp_write_dem(client, 0x00a3, cdo2 & 0xfff);
msp_write_dem(client, 0x00ab, cdo2 >> 12);
msp_write_dem(client, 0x0056, 0);
}
void msp3400c_set_mode(struct i2c_client *client, int mode)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
struct msp3400c_init_data_dem *data = &msp3400c_init_data[mode];
int tuner = (state->route_in >> 3) & 1;
int i;
v4l_dbg(1, msp_debug, client, "set_mode: %d\n", mode);
state->mode = mode;
state->rxsubchans = V4L2_TUNER_SUB_MONO;
msp_write_dem(client, 0x00bb, data->ad_cv | (tuner ? 0x100 : 0));
for (i = 5; i >= 0; i--)
msp_write_dem(client, 0x0001, data->fir1[i]);
msp_write_dem(client, 0x0005, 0x0004);
msp_write_dem(client, 0x0005, 0x0040);
msp_write_dem(client, 0x0005, 0x0000);
for (i = 5; i >= 0; i--)
msp_write_dem(client, 0x0005, data->fir2[i]);
msp_write_dem(client, 0x0083, data->mode_reg);
msp3400c_set_carrier(client, data->cdo1, data->cdo2);
msp_set_source(client, data->dsp_src);
msp_write_dsp(client, 0x000d, 0x1900);
msp_write_dsp(client, 0x000e, data->dsp_matrix);
if (state->has_nicam)
msp_write_dsp(client, 0x0010, 0x5a00);
}
static void msp3400c_set_audmode(struct i2c_client *client)
{
static char *strmode[] = {
"mono", "stereo", "lang2", "lang1", "lang1+lang2"
};
struct msp_state *state = to_state(i2c_get_clientdata(client));
char *modestr = (state->audmode >= 0 && state->audmode < 5) ?
strmode[state->audmode] : "unknown";
int src = 0;
int audmode = state->audmode;
if (state->opmode == OPMODE_AUTOSELECT) {
v4l_dbg(1, msp_debug, client,
"set_audmode called with mode=%d instead of set_source (ignored)\n",
state->audmode);
return;
}
if (state->mode != MSP_MODE_EXTERN) {
if (state->rxsubchans == V4L2_TUNER_SUB_MONO)
audmode = V4L2_TUNER_MODE_MONO;
else if (state->rxsubchans & V4L2_TUNER_SUB_LANG2) {
if (audmode == V4L2_TUNER_MODE_MONO ||
audmode == V4L2_TUNER_MODE_STEREO)
audmode = V4L2_TUNER_MODE_LANG1;
}
else if (audmode != V4L2_TUNER_MODE_MONO)
audmode = V4L2_TUNER_MODE_STEREO;
}
switch (state->mode) {
case MSP_MODE_FM_TERRA:
v4l_dbg(1, msp_debug, client, "FM set_audmode: %s\n", modestr);
switch (audmode) {
case V4L2_TUNER_MODE_STEREO:
msp_write_dsp(client, 0x000e, 0x3001);
break;
case V4L2_TUNER_MODE_MONO:
case V4L2_TUNER_MODE_LANG1:
case V4L2_TUNER_MODE_LANG2:
case V4L2_TUNER_MODE_LANG1_LANG2:
msp_write_dsp(client, 0x000e, 0x3000);
break;
}
break;
case MSP_MODE_FM_SAT:
v4l_dbg(1, msp_debug, client, "SAT set_audmode: %s\n", modestr);
switch (audmode) {
case V4L2_TUNER_MODE_MONO:
msp3400c_set_carrier(client, MSP_CARRIER(6.5), MSP_CARRIER(6.5));
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1_LANG2:
msp3400c_set_carrier(client, MSP_CARRIER(7.2), MSP_CARRIER(7.02));
break;
case V4L2_TUNER_MODE_LANG1:
msp3400c_set_carrier(client, MSP_CARRIER(7.38), MSP_CARRIER(7.02));
break;
case V4L2_TUNER_MODE_LANG2:
msp3400c_set_carrier(client, MSP_CARRIER(7.38), MSP_CARRIER(7.02));
break;
}
break;
case MSP_MODE_FM_NICAM1:
case MSP_MODE_FM_NICAM2:
case MSP_MODE_AM_NICAM:
v4l_dbg(1, msp_debug, client,
"NICAM set_audmode: %s\n", modestr);
if (state->nicam_on)
src = 0x0100;
break;
case MSP_MODE_BTSC:
v4l_dbg(1, msp_debug, client,
"BTSC set_audmode: %s\n", modestr);
break;
case MSP_MODE_EXTERN:
v4l_dbg(1, msp_debug, client,
"extern set_audmode: %s\n", modestr);
src = 0x0200;
break;
case MSP_MODE_FM_RADIO:
v4l_dbg(1, msp_debug, client,
"FM-Radio set_audmode: %s\n", modestr);
break;
default:
v4l_dbg(1, msp_debug, client, "mono set_audmode\n");
return;
}
v4l_dbg(1, msp_debug, client, "set audmode %d\n", audmode);
switch (audmode) {
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1_LANG2:
src |= 0x0020;
break;
case V4L2_TUNER_MODE_MONO:
if (state->mode == MSP_MODE_AM_NICAM) {
v4l_dbg(1, msp_debug, client, "switching to AM mono\n");
msp_set_scart(client, SCART_MONO, 0);
src = 0x0200;
break;
}
if (state->rxsubchans & V4L2_TUNER_SUB_STEREO)
src = 0x0030;
break;
case V4L2_TUNER_MODE_LANG1:
break;
case V4L2_TUNER_MODE_LANG2:
src |= 0x0010;
break;
}
v4l_dbg(1, msp_debug, client,
"set_audmode final source/matrix = 0x%x\n", src);
msp_set_source(client, src);
}
static void msp3400c_print_mode(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
if (state->main == state->second)
v4l_dbg(1, msp_debug, client,
"mono sound carrier: %d.%03d MHz\n",
state->main / 910000, (state->main / 910) % 1000);
else
v4l_dbg(1, msp_debug, client,
"main sound carrier: %d.%03d MHz\n",
state->main / 910000, (state->main / 910) % 1000);
if (state->mode == MSP_MODE_FM_NICAM1 || state->mode == MSP_MODE_FM_NICAM2)
v4l_dbg(1, msp_debug, client,
"NICAM/FM carrier : %d.%03d MHz\n",
state->second / 910000, (state->second/910) % 1000);
if (state->mode == MSP_MODE_AM_NICAM)
v4l_dbg(1, msp_debug, client,
"NICAM/AM carrier : %d.%03d MHz\n",
state->second / 910000, (state->second / 910) % 1000);
if (state->mode == MSP_MODE_FM_TERRA && state->main != state->second) {
v4l_dbg(1, msp_debug, client,
"FM-stereo carrier : %d.%03d MHz\n",
state->second / 910000, (state->second / 910) % 1000);
}
}
static int msp3400c_detect_stereo(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
int val;
int rxsubchans = state->rxsubchans;
int newnicam = state->nicam_on;
int update = 0;
switch (state->mode) {
case MSP_MODE_FM_TERRA:
val = msp_read_dsp(client, 0x18);
if (val > 32767)
val -= 65536;
v4l_dbg(2, msp_debug, client,
"stereo detect register: %d\n", val);
if (val > 8192) {
rxsubchans = V4L2_TUNER_SUB_STEREO;
} else if (val < -4096) {
rxsubchans = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
} else {
rxsubchans = V4L2_TUNER_SUB_MONO;
}
newnicam = 0;
break;
case MSP_MODE_FM_NICAM1:
case MSP_MODE_FM_NICAM2:
case MSP_MODE_AM_NICAM:
val = msp_read_dem(client, 0x23);
v4l_dbg(2, msp_debug, client, "nicam sync=%d, mode=%d\n",
val & 1, (val & 0x1e) >> 1);
if (val & 1) {
switch ((val & 0x1e) >> 1) {
case 0:
case 8:
rxsubchans = V4L2_TUNER_SUB_STEREO;
break;
case 1:
case 9:
rxsubchans = V4L2_TUNER_SUB_MONO;
break;
case 2:
case 10:
rxsubchans = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
break;
default:
rxsubchans = V4L2_TUNER_SUB_MONO;
break;
}
newnicam = 1;
} else {
newnicam = 0;
rxsubchans = V4L2_TUNER_SUB_MONO;
}
break;
}
if (rxsubchans != state->rxsubchans) {
update = 1;
v4l_dbg(1, msp_debug, client,
"watch: rxsubchans %02x => %02x\n",
state->rxsubchans, rxsubchans);
state->rxsubchans = rxsubchans;
}
if (newnicam != state->nicam_on) {
update = 1;
v4l_dbg(1, msp_debug, client, "watch: nicam %d => %d\n",
state->nicam_on, newnicam);
state->nicam_on = newnicam;
}
return update;
}
static void watch_stereo(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
if (msp_detect_stereo(client))
msp_set_audmode(client);
if (msp_once)
state->watch_stereo = 0;
}
int msp3400c_thread(void *data)
{
struct i2c_client *client = data;
struct msp_state *state = to_state(i2c_get_clientdata(client));
struct msp3400c_carrier_detect *cd;
int count, max1, max2, val1, val2, val, i;
v4l_dbg(1, msp_debug, client, "msp3400 daemon started\n");
set_freezable();
for (;;) {
v4l_dbg(2, msp_debug, client, "msp3400 thread: sleep\n");
msp_sleep(state, -1);
v4l_dbg(2, msp_debug, client, "msp3400 thread: wakeup\n");
restart:
v4l_dbg(2, msp_debug, client, "thread: restart scan\n");
state->restart = 0;
if (kthread_should_stop())
break;
if (state->radio || MSP_MODE_EXTERN == state->mode) {
v4l_dbg(1, msp_debug, client,
"thread: no carrier scan\n");
state->scan_in_progress = 0;
msp_update_volume(state);
continue;
}
state->scan_in_progress = 1;
msp_update_volume(state);
msp3400c_set_mode(client, MSP_MODE_AM_DETECT);
val1 = val2 = 0;
max1 = max2 = -1;
state->watch_stereo = 0;
state->nicam_on = 0;
if (msp_sleep(state, 200))
goto restart;
cd = msp3400c_carrier_detect_main;
count = ARRAY_SIZE(msp3400c_carrier_detect_main);
if (msp_amsound && (state->v4l2_std & V4L2_STD_SECAM)) {
max1 = 3;
count = 0;
v4l_dbg(1, msp_debug, client, "AM sound override\n");
}
for (i = 0; i < count; i++) {
msp3400c_set_carrier(client, cd[i].cdo, cd[i].cdo);
if (msp_sleep(state, 100))
goto restart;
val = msp_read_dsp(client, 0x1b);
if (val > 32767)
val -= 65536;
if (val1 < val)
val1 = val, max1 = i;
v4l_dbg(1, msp_debug, client,
"carrier1 val: %5d / %s\n", val, cd[i].name);
}
switch (max1) {
case 1:
cd = msp3400c_carrier_detect_55;
count = ARRAY_SIZE(msp3400c_carrier_detect_55);
break;
case 3:
cd = msp3400c_carrier_detect_65;
count = ARRAY_SIZE(msp3400c_carrier_detect_65);
break;
case 0:
case 2:
default:
cd = NULL;
count = 0;
break;
}
if (msp_amsound && (state->v4l2_std & V4L2_STD_SECAM)) {
cd = NULL;
count = 0;
max2 = 0;
}
for (i = 0; i < count; i++) {
msp3400c_set_carrier(client, cd[i].cdo, cd[i].cdo);
if (msp_sleep(state, 100))
goto restart;
val = msp_read_dsp(client, 0x1b);
if (val > 32767)
val -= 65536;
if (val2 < val)
val2 = val, max2 = i;
v4l_dbg(1, msp_debug, client,
"carrier2 val: %5d / %s\n", val, cd[i].name);
}
state->main = msp3400c_carrier_detect_main[max1].cdo;
switch (max1) {
case 1:
if (max2 == 0) {
state->second = msp3400c_carrier_detect_55[max2].cdo;
msp3400c_set_mode(client, MSP_MODE_FM_TERRA);
state->watch_stereo = 1;
} else if (max2 == 1 && state->has_nicam) {
state->second = msp3400c_carrier_detect_55[max2].cdo;
msp3400c_set_mode(client, MSP_MODE_FM_NICAM1);
state->nicam_on = 1;
state->watch_stereo = 1;
} else {
goto no_second;
}
break;
case 2:
state->second = MSP_CARRIER(6.552);
msp3400c_set_mode(client, MSP_MODE_FM_NICAM2);
state->nicam_on = 1;
state->watch_stereo = 1;
break;
case 3:
if (max2 == 1 || max2 == 2) {
state->second = msp3400c_carrier_detect_65[max2].cdo;
msp3400c_set_mode(client, MSP_MODE_FM_TERRA);
state->watch_stereo = 1;
} else if (max2 == 0 && (state->v4l2_std & V4L2_STD_SECAM)) {
state->second = msp3400c_carrier_detect_65[max2].cdo;
msp3400c_set_mode(client, MSP_MODE_AM_NICAM);
state->watch_stereo = 1;
} else if (max2 == 0 && state->has_nicam) {
state->second = msp3400c_carrier_detect_65[max2].cdo;
msp3400c_set_mode(client, MSP_MODE_FM_NICAM1);
state->nicam_on = 1;
state->watch_stereo = 1;
} else {
goto no_second;
}
break;
case 0:
default:
no_second:
state->second = msp3400c_carrier_detect_main[max1].cdo;
msp3400c_set_mode(client, MSP_MODE_FM_TERRA);
break;
}
msp3400c_set_carrier(client, state->second, state->main);
state->scan_in_progress = 0;
msp3400c_set_audmode(client);
msp_update_volume(state);
if (msp_debug)
msp3400c_print_mode(client);
count = 3;
while (state->watch_stereo) {
if (msp_sleep(state, count ? 1000 : 5000))
goto restart;
if (count)
count--;
watch_stereo(client);
}
}
v4l_dbg(1, msp_debug, client, "thread: exit\n");
return 0;
}
int msp3410d_thread(void *data)
{
struct i2c_client *client = data;
struct msp_state *state = to_state(i2c_get_clientdata(client));
int val, i, std, count;
v4l_dbg(1, msp_debug, client, "msp3410 daemon started\n");
set_freezable();
for (;;) {
v4l_dbg(2, msp_debug, client, "msp3410 thread: sleep\n");
msp_sleep(state, -1);
v4l_dbg(2, msp_debug, client, "msp3410 thread: wakeup\n");
restart:
v4l_dbg(2, msp_debug, client, "thread: restart scan\n");
state->restart = 0;
if (kthread_should_stop())
break;
if (state->mode == MSP_MODE_EXTERN) {
v4l_dbg(1, msp_debug, client,
"thread: no carrier scan\n");
state->scan_in_progress = 0;
msp_update_volume(state);
continue;
}
state->scan_in_progress = 1;
msp_update_volume(state);
if (state->radio)
std = 0x40;
else
std = (state->v4l2_std & V4L2_STD_NTSC) ? 0x20 : 1;
state->watch_stereo = 0;
state->nicam_on = 0;
if (msp_sleep(state, 200))
goto restart;
if (msp_debug)
v4l_dbg(2, msp_debug, client,
"setting standard: %s (0x%04x)\n",
msp_standard_std_name(std), std);
if (std != 1) {
val = std;
} else {
msp_write_dem(client, 0x20, std);
for (;;) {
if (msp_sleep(state, 100))
goto restart;
val = msp_read_dem(client, 0x7e);
if (val < 0x07ff)
break;
v4l_dbg(2, msp_debug, client,
"detection still in progress\n");
}
}
for (i = 0; msp_stdlist[i].name != NULL; i++)
if (msp_stdlist[i].retval == val)
break;
v4l_dbg(1, msp_debug, client, "current standard: %s (0x%04x)\n",
msp_standard_std_name(val), val);
state->main = msp_stdlist[i].main;
state->second = msp_stdlist[i].second;
state->std = val;
state->rxsubchans = V4L2_TUNER_SUB_MONO;
if (msp_amsound && !state->radio &&
(state->v4l2_std & V4L2_STD_SECAM) && (val != 0x0009)) {
v4l_dbg(1, msp_debug, client, "autodetection failed,"
" switching to backup standard: %s (0x%04x)\n",
msp_stdlist[8].name ?
msp_stdlist[8].name : "unknown", val);
state->std = val = 0x0009;
msp_write_dem(client, 0x20, val);
}
switch (val) {
case 0x0008:
case 0x000a:
case 0x000b:
if (val == 0x000a)
state->mode = MSP_MODE_FM_NICAM2;
else
state->mode = MSP_MODE_FM_NICAM1;
state->nicam_on = 1;
state->watch_stereo = 1;
break;
case 0x0009:
state->mode = MSP_MODE_AM_NICAM;
state->nicam_on = 1;
state->watch_stereo = 1;
break;
case 0x0020:
state->mode = MSP_MODE_BTSC;
break;
case 0x0040:
state->mode = MSP_MODE_FM_RADIO;
state->rxsubchans = V4L2_TUNER_SUB_STEREO;
msp3400c_set_mode(client, MSP_MODE_FM_RADIO);
msp3400c_set_carrier(client, MSP_CARRIER(10.7),
MSP_CARRIER(10.7));
break;
case 0x0002:
case 0x0003:
case 0x0004:
case 0x0005:
state->mode = MSP_MODE_FM_TERRA;
state->watch_stereo = 1;
break;
}
msp_write_dsp(client, 0x0d, 0x1900);
msp_write_dsp(client, 0x0e, 0x3000);
if (state->has_nicam)
msp_write_dsp(client, 0x10, 0x5a00);
if (state->has_i2s_conf)
msp_write_dem(client, 0x40, state->i2s_mode);
msp3400c_set_audmode(client);
state->scan_in_progress = 0;
msp_update_volume(state);
count = 3;
while (state->watch_stereo) {
if (msp_sleep(state, count ? 1000 : 5000))
goto restart;
if (count)
count--;
watch_stereo(client);
}
}
v4l_dbg(1, msp_debug, client, "thread: exit\n");
return 0;
}
static int msp34xxg_modus(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
if (state->radio) {
v4l_dbg(1, msp_debug, client, "selected radio modus\n");
return 0x0001;
}
if (state->v4l2_std == V4L2_STD_NTSC_M_JP) {
v4l_dbg(1, msp_debug, client, "selected M (EIA-J) modus\n");
return 0x4001;
}
if (state->v4l2_std == V4L2_STD_NTSC_M_KR) {
v4l_dbg(1, msp_debug, client, "selected M (A2) modus\n");
return 0x0001;
}
if (state->v4l2_std == V4L2_STD_SECAM_L) {
v4l_dbg(1, msp_debug, client, "selected SECAM-L modus\n");
return 0x6001;
}
if (state->v4l2_std & V4L2_STD_MN) {
v4l_dbg(1, msp_debug, client, "selected M (BTSC) modus\n");
return 0x2001;
}
return 0x7001;
}
static void msp34xxg_set_source(struct i2c_client *client, u16 reg, int in)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
int source, matrix;
switch (state->audmode) {
case V4L2_TUNER_MODE_MONO:
source = 0;
matrix = 0x30;
break;
case V4L2_TUNER_MODE_LANG2:
source = 4;
matrix = 0x10;
break;
case V4L2_TUNER_MODE_LANG1_LANG2:
source = 1;
matrix = 0x20;
break;
case V4L2_TUNER_MODE_LANG1:
source = 3;
matrix = 0x00;
break;
case V4L2_TUNER_MODE_STEREO:
default:
source = 3;
matrix = 0x20;
break;
}
if (in == MSP_DSP_IN_TUNER)
source = (source << 8) | 0x20;
else if (in >= MSP_DSP_IN_MAIN_AVC && state->has_dolby_pro_logic)
source = ((in + 1) << 8) | matrix;
else
source = (in << 8) | matrix;
v4l_dbg(1, msp_debug, client,
"set source to %d (0x%x) for output %02x\n", in, source, reg);
msp_write_dsp(client, reg, source);
}
static void msp34xxg_set_sources(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
u32 in = state->route_in;
msp34xxg_set_source(client, 0x0008, (in >> 4) & 0xf);
msp34xxg_set_source(client, 0x000c, (in >> 4) & 0xf);
msp34xxg_set_source(client, 0x0009, (in >> 8) & 0xf);
msp34xxg_set_source(client, 0x000a, (in >> 12) & 0xf);
if (state->has_scart2_out)
msp34xxg_set_source(client, 0x0041, (in >> 16) & 0xf);
msp34xxg_set_source(client, 0x000b, (in >> 20) & 0xf);
}
static void msp34xxg_reset(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
int tuner = (state->route_in >> 3) & 1;
int modus;
state->std = 1;
msp_reset(client);
if (state->has_i2s_conf)
msp_write_dem(client, 0x40, state->i2s_mode);
modus = msp34xxg_modus(client);
modus |= tuner ? 0x100 : 0;
msp_write_dem(client, 0x30, modus);
msp34xxg_set_sources(client);
msp_write_dsp(client, 0x0d, 0x1900);
msp_write_dsp(client, 0x0e, 0x3000);
if (state->has_nicam)
msp_write_dsp(client, 0x10, 0x5a00);
msp_write_dem(client, 0x22, msp_stereo_thresh);
}
int msp34xxg_thread(void *data)
{
struct i2c_client *client = data;
struct msp_state *state = to_state(i2c_get_clientdata(client));
int val, i;
v4l_dbg(1, msp_debug, client, "msp34xxg daemon started\n");
set_freezable();
for (;;) {
v4l_dbg(2, msp_debug, client, "msp34xxg thread: sleep\n");
msp_sleep(state, -1);
v4l_dbg(2, msp_debug, client, "msp34xxg thread: wakeup\n");
restart:
v4l_dbg(1, msp_debug, client, "thread: restart scan\n");
state->restart = 0;
if (kthread_should_stop())
break;
if (state->mode == MSP_MODE_EXTERN) {
v4l_dbg(1, msp_debug, client,
"thread: no carrier scan\n");
state->scan_in_progress = 0;
msp_update_volume(state);
continue;
}
msp34xxg_reset(client);
state->std = state->radio ? 0x40 :
(state->force_btsc && msp_standard == 1) ? 32 : msp_standard;
msp_write_dem(client, 0x20, state->std);
if (state->std != 1)
goto unmute;
v4l_dbg(1, msp_debug, client,
"started autodetect, waiting for result\n");
for (i = 0; i < 10; i++) {
if (msp_sleep(state, 100))
goto restart;
val = msp_read_dem(client, 0x7e);
if (val < 0x07ff) {
state->std = val;
break;
}
v4l_dbg(2, msp_debug, client,
"detection still in progress\n");
}
if (state->std == 1) {
v4l_dbg(1, msp_debug, client,
"detection still in progress after 10 tries. giving up.\n");
continue;
}
unmute:
v4l_dbg(1, msp_debug, client,
"detected standard: %s (0x%04x)\n",
msp_standard_std_name(state->std), state->std);
if (state->std == 9) {
msp_write_dsp(client, 0x0e, 0x7c00);
}
msp_update_volume(state);
if (msp_write_dsp(client, 0x13, state->acb))
return -1;
if (state->std != 0x20)
continue;
state->watch_stereo = 1;
watch_stereo(client);
while (state->watch_stereo) {
watch_stereo(client);
if (msp_sleep(state, 5000))
goto restart;
}
}
v4l_dbg(1, msp_debug, client, "thread: exit\n");
return 0;
}
static int msp34xxg_detect_stereo(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
int status = msp_read_dem(client, 0x0200);
int is_bilingual = status & 0x100;
int is_stereo = status & 0x40;
int oldrx = state->rxsubchans;
if (state->mode == MSP_MODE_EXTERN)
return 0;
state->rxsubchans = 0;
if (is_stereo)
state->rxsubchans = V4L2_TUNER_SUB_STEREO;
else
state->rxsubchans = V4L2_TUNER_SUB_MONO;
if (is_bilingual) {
if (state->std == 0x20)
state->rxsubchans |= V4L2_TUNER_SUB_SAP;
else
state->rxsubchans =
V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
}
v4l_dbg(1, msp_debug, client,
"status=0x%x, stereo=%d, bilingual=%d -> rxsubchans=%d\n",
status, is_stereo, is_bilingual, state->rxsubchans);
return (oldrx != state->rxsubchans);
}
static void msp34xxg_set_audmode(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
if (state->std == 0x20) {
if ((state->rxsubchans & V4L2_TUNER_SUB_SAP) &&
(state->audmode == V4L2_TUNER_MODE_LANG1_LANG2 ||
state->audmode == V4L2_TUNER_MODE_LANG2)) {
msp_write_dem(client, 0x20, 0x21);
} else {
msp_write_dem(client, 0x20, 0x20);
}
}
msp34xxg_set_sources(client);
}
void msp_set_audmode(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
switch (state->opmode) {
case OPMODE_MANUAL:
case OPMODE_AUTODETECT:
msp3400c_set_audmode(client);
break;
case OPMODE_AUTOSELECT:
msp34xxg_set_audmode(client);
break;
}
}
int msp_detect_stereo(struct i2c_client *client)
{
struct msp_state *state = to_state(i2c_get_clientdata(client));
switch (state->opmode) {
case OPMODE_MANUAL:
case OPMODE_AUTODETECT:
return msp3400c_detect_stereo(client);
case OPMODE_AUTOSELECT:
return msp34xxg_detect_stereo(client);
}
return 0;
}
