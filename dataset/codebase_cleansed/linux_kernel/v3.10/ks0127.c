static inline struct ks0127 *to_ks0127(struct v4l2_subdev *sd)
{
return container_of(sd, struct ks0127, sd);
}
static void init_reg_defaults(void)
{
static int initialized;
u8 *table = reg_defaults;
if (initialized)
return;
initialized = 1;
table[KS_CMDA] = 0x2c;
table[KS_CMDB] = 0x12;
table[KS_CMDC] = 0x00;
table[KS_CMDD] = 0x01;
table[KS_HAVB] = 0x00;
table[KS_HAVE] = 0x00;
table[KS_HS1B] = 0x10;
table[KS_HS1E] = 0x00;
table[KS_HS2B] = 0x00;
table[KS_HS2E] = 0x00;
table[KS_AGC] = 0x53;
table[KS_HXTRA] = 0x00;
table[KS_CDEM] = 0x00;
table[KS_PORTAB] = 0x0f;
table[KS_LUMA] = 0x01;
table[KS_CON] = 0x00;
table[KS_BRT] = 0x00;
table[KS_CHROMA] = 0x2a;
table[KS_CHROMB] = 0x90;
table[KS_DEMOD] = 0x00;
table[KS_SAT] = 0x00;
table[KS_HUE] = 0x00;
table[KS_VERTIA] = 0x00;
table[KS_VERTIB] = 0x12;
table[KS_VERTIC] = 0x0b;
table[KS_HSCLL] = 0x00;
table[KS_HSCLH] = 0x00;
table[KS_VSCLL] = 0x00;
table[KS_VSCLH] = 0x00;
table[KS_OFMTA] = 0x30;
table[KS_OFMTB] = 0x00;
table[KS_VBICTL] = 0x5d;
table[KS_CCDAT2] = 0x00;
table[KS_CCDAT1] = 0x00;
table[KS_VBIL30] = 0xa8;
table[KS_VBIL74] = 0xaa;
table[KS_VBIL118] = 0x2a;
table[KS_VBIL1512] = 0x00;
table[KS_TTFRAM] = 0x00;
table[KS_TESTA] = 0x00;
table[KS_UVOFFH] = 0x00;
table[KS_UVOFFL] = 0x00;
table[KS_UGAIN] = 0x00;
table[KS_VGAIN] = 0x00;
table[KS_VAVB] = 0x07;
table[KS_VAVE] = 0x00;
table[KS_CTRACK] = 0x00;
table[KS_POLCTL] = 0x41;
table[KS_REFCOD] = 0x80;
table[KS_INVALY] = 0x10;
table[KS_INVALU] = 0x80;
table[KS_INVALV] = 0x80;
table[KS_UNUSEY] = 0x10;
table[KS_UNUSEU] = 0x80;
table[KS_UNUSEV] = 0x80;
table[KS_USRSAV] = 0x00;
table[KS_USREAV] = 0x00;
table[KS_SHS1A] = 0x00;
table[KS_SHS1B] = 0x80;
table[KS_SHS1C] = 0x00;
table[KS_CMDE] = 0x00;
table[KS_VSDEL] = 0x00;
table[KS_CMDF] = 0x02;
}
static u8 ks0127_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
char val = 0;
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.len = sizeof(reg),
.buf = &reg
},
{
.addr = client->addr,
.flags = I2C_M_RD | I2C_M_NO_RD_ACK,
.len = sizeof(val),
.buf = &val
}
};
int ret;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret != ARRAY_SIZE(msgs))
v4l2_dbg(1, debug, sd, "read error\n");
return val;
}
static void ks0127_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ks0127 *ks = to_ks0127(sd);
char msg[] = { reg, val };
if (i2c_master_send(client, msg, sizeof(msg)) != sizeof(msg))
v4l2_dbg(1, debug, sd, "write error\n");
ks->regs[reg] = val;
}
static void ks0127_and_or(struct v4l2_subdev *sd, u8 reg, u8 and_v, u8 or_v)
{
struct ks0127 *ks = to_ks0127(sd);
u8 val = ks->regs[reg];
val = (val & and_v) | or_v;
ks0127_write(sd, reg, val);
}
static void ks0127_init(struct v4l2_subdev *sd)
{
struct ks0127 *ks = to_ks0127(sd);
u8 *table = reg_defaults;
int i;
ks->ident = V4L2_IDENT_KS0127;
v4l2_dbg(1, debug, sd, "reset\n");
msleep(1);
for (i = 1; i < 33; i++)
ks0127_write(sd, i, table[i]);
for (i = 35; i < 40; i++)
ks0127_write(sd, i, table[i]);
for (i = 41; i < 56; i++)
ks0127_write(sd, i, table[i]);
for (i = 58; i < 64; i++)
ks0127_write(sd, i, table[i]);
if ((ks0127_read(sd, KS_STAT) & 0x80) == 0) {
ks->ident = V4L2_IDENT_KS0122S;
v4l2_dbg(1, debug, sd, "ks0122s found\n");
return;
}
switch (ks0127_read(sd, KS_CMDE) & 0x0f) {
case 0:
v4l2_dbg(1, debug, sd, "ks0127 found\n");
break;
case 9:
ks->ident = V4L2_IDENT_KS0127B;
v4l2_dbg(1, debug, sd, "ks0127B Revision A found\n");
break;
default:
v4l2_dbg(1, debug, sd, "unknown revision\n");
break;
}
}
static int ks0127_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct ks0127 *ks = to_ks0127(sd);
switch (input) {
case KS_INPUT_COMPOSITE_1:
case KS_INPUT_COMPOSITE_2:
case KS_INPUT_COMPOSITE_3:
case KS_INPUT_COMPOSITE_4:
case KS_INPUT_COMPOSITE_5:
case KS_INPUT_COMPOSITE_6:
v4l2_dbg(1, debug, sd,
"s_routing %d: Composite\n", input);
ks0127_and_or(sd, KS_CMDA, 0xfc, 0x00);
ks0127_and_or(sd, KS_CMDA, ~0x40, 0x00);
ks0127_and_or(sd, KS_CMDB, 0xb0, input);
ks0127_and_or(sd, KS_CMDC, 0x70, 0x0a);
ks0127_and_or(sd, KS_CMDD, 0x03, 0x00);
ks0127_and_or(sd, KS_CTRACK, 0xcf, 0x00);
ks0127_and_or(sd, KS_LUMA, 0x00,
(reg_defaults[KS_LUMA])|0x0c);
ks0127_and_or(sd, KS_VERTIA, 0x08, 0x81);
ks0127_and_or(sd, KS_VERTIC, 0x0f, 0x90);
ks0127_and_or(sd, KS_CHROMB, 0x0f, 0x90);
ks0127_write(sd, KS_UGAIN, reg_defaults[KS_UGAIN]);
ks0127_write(sd, KS_VGAIN, reg_defaults[KS_VGAIN]);
ks0127_write(sd, KS_UVOFFH, reg_defaults[KS_UVOFFH]);
ks0127_write(sd, KS_UVOFFL, reg_defaults[KS_UVOFFL]);
break;
case KS_INPUT_SVIDEO_1:
case KS_INPUT_SVIDEO_2:
case KS_INPUT_SVIDEO_3:
v4l2_dbg(1, debug, sd,
"s_routing %d: S-Video\n", input);
ks0127_and_or(sd, KS_CMDA, 0xfc, 0x00);
ks0127_and_or(sd, KS_CMDA, ~0x40, 0x00);
ks0127_and_or(sd, KS_CMDB, 0xb0, input);
ks0127_and_or(sd, KS_CMDC, 0x70, 0x0a);
ks0127_and_or(sd, KS_CMDD, 0x03, 0x00);
ks0127_and_or(sd, KS_CTRACK, 0xcf, 0x00);
ks0127_and_or(sd, KS_LUMA, 0x00,
reg_defaults[KS_LUMA]);
ks0127_and_or(sd, KS_VERTIA, 0x08,
(reg_defaults[KS_VERTIA]&0xf0)|0x01);
ks0127_and_or(sd, KS_VERTIC, 0x0f,
reg_defaults[KS_VERTIC]&0xf0);
ks0127_and_or(sd, KS_CHROMB, 0x0f,
reg_defaults[KS_CHROMB]&0xf0);
ks0127_write(sd, KS_UGAIN, reg_defaults[KS_UGAIN]);
ks0127_write(sd, KS_VGAIN, reg_defaults[KS_VGAIN]);
ks0127_write(sd, KS_UVOFFH, reg_defaults[KS_UVOFFH]);
ks0127_write(sd, KS_UVOFFL, reg_defaults[KS_UVOFFL]);
break;
case KS_INPUT_YUV656:
v4l2_dbg(1, debug, sd, "s_routing 15: YUV656\n");
if (ks->norm & V4L2_STD_525_60)
ks0127_and_or(sd, KS_CMDA, 0xfc, 0x03);
else
ks0127_and_or(sd, KS_CMDA, 0xfc, 0x02);
ks0127_and_or(sd, KS_CMDA, 0xff, 0x40);
ks0127_and_or(sd, KS_CMDB, 0xb0, (input | 0x40));
ks0127_and_or(sd, KS_CMDC, 0x70, 0x87);
ks0127_and_or(sd, KS_CMDD, 0x03, 0x08);
ks0127_and_or(sd, KS_CTRACK, 0xcf, 0x30);
ks0127_and_or(sd, KS_LUMA, 0x00, 0x71);
ks0127_and_or(sd, KS_VERTIC, 0x0f,
reg_defaults[KS_VERTIC]&0xf0);
ks0127_and_or(sd, KS_VERTIA, 0x08, 0x81);
ks0127_and_or(sd, KS_CHROMB, 0x0f,
reg_defaults[KS_CHROMB]&0xf0);
ks0127_and_or(sd, KS_CON, 0x00, 0x00);
ks0127_and_or(sd, KS_BRT, 0x00, 32);
ks0127_and_or(sd, KS_SAT, 0x00, 0xe8);
ks0127_and_or(sd, KS_HUE, 0x00, 0);
ks0127_and_or(sd, KS_UGAIN, 0x00, 238);
ks0127_and_or(sd, KS_VGAIN, 0x00, 0x00);
ks0127_and_or(sd, KS_UVOFFH, 0x00, 0x4f);
ks0127_and_or(sd, KS_UVOFFL, 0x00, 0x00);
break;
default:
v4l2_dbg(1, debug, sd,
"s_routing: Unknown input %d\n", input);
break;
}
ks0127_write(sd, KS_DEMOD, reg_defaults[KS_DEMOD]);
return 0;
}
static int ks0127_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct ks0127 *ks = to_ks0127(sd);
ks0127_and_or(sd, KS_DEMOD, 0xf0, 0x00);
ks->norm = std;
if (std & V4L2_STD_NTSC) {
v4l2_dbg(1, debug, sd,
"s_std: NTSC_M\n");
ks0127_and_or(sd, KS_CHROMA, 0x9f, 0x20);
} else if (std & V4L2_STD_PAL_N) {
v4l2_dbg(1, debug, sd,
"s_std: NTSC_N (fixme)\n");
ks0127_and_or(sd, KS_CHROMA, 0x9f, 0x40);
} else if (std & V4L2_STD_PAL) {
v4l2_dbg(1, debug, sd,
"s_std: PAL_N\n");
ks0127_and_or(sd, KS_CHROMA, 0x9f, 0x20);
} else if (std & V4L2_STD_PAL_M) {
v4l2_dbg(1, debug, sd,
"s_std: PAL_M (fixme)\n");
ks0127_and_or(sd, KS_CHROMA, 0x9f, 0x40);
} else if (std & V4L2_STD_SECAM) {
v4l2_dbg(1, debug, sd,
"s_std: SECAM\n");
ks0127_and_or(sd, KS_CHROMA, 0xdf, 0x20);
ks0127_and_or(sd, KS_DEMOD, 0xf0, 0x00);
schedule_timeout_interruptible(HZ/10+1);
if (!(ks0127_read(sd, KS_DEMOD) & 0x40))
ks0127_and_or(sd, KS_DEMOD, 0xf0, 0x0f);
} else {
v4l2_dbg(1, debug, sd, "s_std: Unknown norm %llx\n",
(unsigned long long)std);
}
return 0;
}
static int ks0127_s_stream(struct v4l2_subdev *sd, int enable)
{
v4l2_dbg(1, debug, sd, "s_stream(%d)\n", enable);
if (enable) {
ks0127_and_or(sd, KS_OFMTA, 0xcf, 0x30);
ks0127_and_or(sd, KS_CDEM, 0x7f, 0x00);
} else {
ks0127_and_or(sd, KS_OFMTA, 0xcf, 0x00);
ks0127_and_or(sd, KS_CDEM, 0x7f, 0x80);
}
return 0;
}
static int ks0127_status(struct v4l2_subdev *sd, u32 *pstatus, v4l2_std_id *pstd)
{
int stat = V4L2_IN_ST_NO_SIGNAL;
u8 status;
v4l2_std_id std = V4L2_STD_ALL;
status = ks0127_read(sd, KS_STAT);
if (!(status & 0x20))
stat = 0;
if (!(status & 0x01))
stat |= V4L2_IN_ST_NO_COLOR;
if ((status & 0x08))
std = V4L2_STD_PAL;
else
std = V4L2_STD_NTSC;
if (pstd)
*pstd = std;
if (pstatus)
*pstatus = stat;
return 0;
}
static int ks0127_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
v4l2_dbg(1, debug, sd, "querystd\n");
return ks0127_status(sd, NULL, std);
}
static int ks0127_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
v4l2_dbg(1, debug, sd, "g_input_status\n");
return ks0127_status(sd, status, NULL);
}
static int ks0127_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct ks0127 *ks = to_ks0127(sd);
return v4l2_chip_ident_i2c_client(client, chip, ks->ident, 0);
}
static int ks0127_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct ks0127 *ks;
struct v4l2_subdev *sd;
v4l_info(client, "%s chip found @ 0x%x (%s)\n",
client->addr == (I2C_KS0127_ADDON >> 1) ? "addon" : "on-board",
client->addr << 1, client->adapter->name);
ks = kzalloc(sizeof(*ks), GFP_KERNEL);
if (ks == NULL)
return -ENOMEM;
sd = &ks->sd;
v4l2_i2c_subdev_init(sd, client, &ks0127_ops);
init_reg_defaults();
ks0127_write(sd, KS_CMDA, 0x2c);
mdelay(10);
ks0127_init(sd);
return 0;
}
static int ks0127_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
ks0127_write(sd, KS_OFMTA, 0x20);
ks0127_write(sd, KS_CMDA, 0x2c | 0x80);
kfree(to_ks0127(sd));
return 0;
}
