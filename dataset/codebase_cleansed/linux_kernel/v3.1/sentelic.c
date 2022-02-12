static unsigned char fsp_test_swap_cmd(unsigned char reg_val)
{
switch (reg_val) {
case 10: case 20: case 40: case 60: case 80: case 100: case 200:
return (reg_val >> 4) | (reg_val << 4);
default:
return reg_val;
}
}
static unsigned char fsp_test_invert_cmd(unsigned char reg_val)
{
switch (reg_val) {
case 0xe9: case 0xee: case 0xf2: case 0xff:
return ~reg_val;
default:
return reg_val;
}
}
static int fsp_reg_read(struct psmouse *psmouse, int reg_addr, int *reg_val)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[3];
unsigned char addr;
int rc = -1;
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE);
psmouse_set_state(psmouse, PSMOUSE_CMD_MODE);
ps2_begin_command(ps2dev);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
goto out;
ps2_sendbyte(ps2dev, 0x66, FSP_CMD_TIMEOUT2);
ps2_sendbyte(ps2dev, 0x88, FSP_CMD_TIMEOUT2);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
goto out;
if ((addr = fsp_test_invert_cmd(reg_addr)) != reg_addr) {
ps2_sendbyte(ps2dev, 0x68, FSP_CMD_TIMEOUT2);
} else if ((addr = fsp_test_swap_cmd(reg_addr)) != reg_addr) {
ps2_sendbyte(ps2dev, 0xcc, FSP_CMD_TIMEOUT2);
} else {
ps2_sendbyte(ps2dev, 0x66, FSP_CMD_TIMEOUT2);
}
ps2_sendbyte(ps2dev, addr, FSP_CMD_TIMEOUT);
if (__ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO) < 0)
goto out;
*reg_val = param[2];
rc = 0;
out:
ps2_end_command(ps2dev);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE);
psmouse_set_state(psmouse, PSMOUSE_ACTIVATED);
dev_dbg(&ps2dev->serio->dev, "READ REG: 0x%02x is 0x%02x (rc = %d)\n",
reg_addr, *reg_val, rc);
return rc;
}
static int fsp_reg_write(struct psmouse *psmouse, int reg_addr, int reg_val)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char v;
int rc = -1;
ps2_begin_command(ps2dev);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
goto out;
if ((v = fsp_test_invert_cmd(reg_addr)) != reg_addr) {
ps2_sendbyte(ps2dev, 0x74, FSP_CMD_TIMEOUT2);
} else {
if ((v = fsp_test_swap_cmd(reg_addr)) != reg_addr) {
ps2_sendbyte(ps2dev, 0x77, FSP_CMD_TIMEOUT2);
} else {
ps2_sendbyte(ps2dev, 0x55, FSP_CMD_TIMEOUT2);
}
}
ps2_sendbyte(ps2dev, v, FSP_CMD_TIMEOUT2);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
return -1;
if ((v = fsp_test_invert_cmd(reg_val)) != reg_val) {
ps2_sendbyte(ps2dev, 0x47, FSP_CMD_TIMEOUT2);
} else if ((v = fsp_test_swap_cmd(reg_val)) != reg_val) {
ps2_sendbyte(ps2dev, 0x44, FSP_CMD_TIMEOUT2);
} else {
ps2_sendbyte(ps2dev, 0x33, FSP_CMD_TIMEOUT2);
}
ps2_sendbyte(ps2dev, v, FSP_CMD_TIMEOUT2);
rc = 0;
out:
ps2_end_command(ps2dev);
dev_dbg(&ps2dev->serio->dev, "WRITE REG: 0x%02x to 0x%02x (rc = %d)\n",
reg_addr, reg_val, rc);
return rc;
}
static int fsp_reg_write_enable(struct psmouse *psmouse, bool enable)
{
int v, nv;
if (fsp_reg_read(psmouse, FSP_REG_SYSCTL1, &v) == -1)
return -1;
if (enable)
nv = v | FSP_BIT_EN_REG_CLK;
else
nv = v & ~FSP_BIT_EN_REG_CLK;
if (nv != v)
if (fsp_reg_write(psmouse, FSP_REG_SYSCTL1, nv) == -1)
return -1;
return 0;
}
static int fsp_page_reg_read(struct psmouse *psmouse, int *reg_val)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[3];
int rc = -1;
ps2_command(ps2dev, NULL, PSMOUSE_CMD_DISABLE);
psmouse_set_state(psmouse, PSMOUSE_CMD_MODE);
ps2_begin_command(ps2dev);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
goto out;
ps2_sendbyte(ps2dev, 0x66, FSP_CMD_TIMEOUT2);
ps2_sendbyte(ps2dev, 0x88, FSP_CMD_TIMEOUT2);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
goto out;
ps2_sendbyte(ps2dev, 0x83, FSP_CMD_TIMEOUT2);
ps2_sendbyte(ps2dev, 0x88, FSP_CMD_TIMEOUT2);
if (__ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO))
goto out;
*reg_val = param[2];
rc = 0;
out:
ps2_end_command(ps2dev);
ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE);
psmouse_set_state(psmouse, PSMOUSE_ACTIVATED);
dev_dbg(&ps2dev->serio->dev, "READ PAGE REG: 0x%02x (rc = %d)\n",
*reg_val, rc);
return rc;
}
static int fsp_page_reg_write(struct psmouse *psmouse, int reg_val)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char v;
int rc = -1;
ps2_begin_command(ps2dev);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
goto out;
ps2_sendbyte(ps2dev, 0x38, FSP_CMD_TIMEOUT2);
ps2_sendbyte(ps2dev, 0x88, FSP_CMD_TIMEOUT2);
if (ps2_sendbyte(ps2dev, 0xf3, FSP_CMD_TIMEOUT) < 0)
return -1;
if ((v = fsp_test_invert_cmd(reg_val)) != reg_val) {
ps2_sendbyte(ps2dev, 0x47, FSP_CMD_TIMEOUT2);
} else if ((v = fsp_test_swap_cmd(reg_val)) != reg_val) {
ps2_sendbyte(ps2dev, 0x44, FSP_CMD_TIMEOUT2);
} else {
ps2_sendbyte(ps2dev, 0x33, FSP_CMD_TIMEOUT2);
}
ps2_sendbyte(ps2dev, v, FSP_CMD_TIMEOUT2);
rc = 0;
out:
ps2_end_command(ps2dev);
dev_dbg(&ps2dev->serio->dev, "WRITE PAGE REG: to 0x%02x (rc = %d)\n",
reg_val, rc);
return rc;
}
static int fsp_get_version(struct psmouse *psmouse, int *version)
{
if (fsp_reg_read(psmouse, FSP_REG_VERSION, version))
return -EIO;
return 0;
}
static int fsp_get_revision(struct psmouse *psmouse, int *rev)
{
if (fsp_reg_read(psmouse, FSP_REG_REVISION, rev))
return -EIO;
return 0;
}
static int fsp_get_buttons(struct psmouse *psmouse, int *btn)
{
static const int buttons[] = {
0x16,
0x06,
0x04,
0x02,
};
int val;
if (fsp_reg_read(psmouse, FSP_REG_TMOD_STATUS1, &val) == -1)
return -EIO;
*btn = buttons[(val & 0x30) >> 4];
return 0;
}
static int fsp_opc_tag_enable(struct psmouse *psmouse, bool enable)
{
int v, nv;
int res = 0;
if (fsp_reg_read(psmouse, FSP_REG_OPC_QDOWN, &v) == -1) {
dev_err(&psmouse->ps2dev.serio->dev, "Unable get OPC state.\n");
return -EIO;
}
if (enable)
nv = v | FSP_BIT_EN_OPC_TAG;
else
nv = v & ~FSP_BIT_EN_OPC_TAG;
if (nv != v) {
fsp_reg_write_enable(psmouse, true);
res = fsp_reg_write(psmouse, FSP_REG_OPC_QDOWN, nv);
fsp_reg_write_enable(psmouse, false);
}
if (res != 0) {
dev_err(&psmouse->ps2dev.serio->dev,
"Unable to enable OPC tag.\n");
res = -EIO;
}
return res;
}
static int fsp_onpad_vscr(struct psmouse *psmouse, bool enable)
{
struct fsp_data *pad = psmouse->private;
int val;
if (fsp_reg_read(psmouse, FSP_REG_ONPAD_CTL, &val))
return -EIO;
pad->vscroll = enable;
if (enable)
val |= (FSP_BIT_FIX_VSCR | FSP_BIT_ONPAD_ENABLE);
else
val &= ~FSP_BIT_FIX_VSCR;
if (fsp_reg_write(psmouse, FSP_REG_ONPAD_CTL, val))
return -EIO;
return 0;
}
static int fsp_onpad_hscr(struct psmouse *psmouse, bool enable)
{
struct fsp_data *pad = psmouse->private;
int val, v2;
if (fsp_reg_read(psmouse, FSP_REG_ONPAD_CTL, &val))
return -EIO;
if (fsp_reg_read(psmouse, FSP_REG_SYSCTL5, &v2))
return -EIO;
pad->hscroll = enable;
if (enable) {
val |= (FSP_BIT_FIX_HSCR | FSP_BIT_ONPAD_ENABLE);
v2 |= FSP_BIT_EN_MSID6;
} else {
val &= ~FSP_BIT_FIX_HSCR;
v2 &= ~(FSP_BIT_EN_MSID6 | FSP_BIT_EN_MSID7 | FSP_BIT_EN_MSID8);
}
if (fsp_reg_write(psmouse, FSP_REG_ONPAD_CTL, val))
return -EIO;
if (fsp_reg_write(psmouse, FSP_REG_SYSCTL5, v2))
return -EIO;
return 0;
}
static ssize_t fsp_attr_set_setreg(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
unsigned long reg, val;
char *rest;
ssize_t retval;
reg = simple_strtoul(buf, &rest, 16);
if (rest == buf || *rest != ' ' || reg > 0xff)
return -EINVAL;
if (strict_strtoul(rest + 1, 16, &val) || val > 0xff)
return -EINVAL;
if (fsp_reg_write_enable(psmouse, true))
return -EIO;
retval = fsp_reg_write(psmouse, reg, val) < 0 ? -EIO : count;
fsp_reg_write_enable(psmouse, false);
return count;
}
static ssize_t fsp_attr_show_getreg(struct psmouse *psmouse,
void *data, char *buf)
{
struct fsp_data *pad = psmouse->private;
return sprintf(buf, "%02x%02x\n", pad->last_reg, pad->last_val);
}
static ssize_t fsp_attr_set_getreg(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
struct fsp_data *pad = psmouse->private;
unsigned long reg;
int val;
if (strict_strtoul(buf, 16, &reg) || reg > 0xff)
return -EINVAL;
if (fsp_reg_read(psmouse, reg, &val))
return -EIO;
pad->last_reg = reg;
pad->last_val = val;
return count;
}
static ssize_t fsp_attr_show_pagereg(struct psmouse *psmouse,
void *data, char *buf)
{
int val = 0;
if (fsp_page_reg_read(psmouse, &val))
return -EIO;
return sprintf(buf, "%02x\n", val);
}
static ssize_t fsp_attr_set_pagereg(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
unsigned long val;
if (strict_strtoul(buf, 16, &val) || val > 0xff)
return -EINVAL;
if (fsp_page_reg_write(psmouse, val))
return -EIO;
return count;
}
static ssize_t fsp_attr_show_vscroll(struct psmouse *psmouse,
void *data, char *buf)
{
struct fsp_data *pad = psmouse->private;
return sprintf(buf, "%d\n", pad->vscroll);
}
static ssize_t fsp_attr_set_vscroll(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
unsigned long val;
if (strict_strtoul(buf, 10, &val) || val > 1)
return -EINVAL;
fsp_onpad_vscr(psmouse, val);
return count;
}
static ssize_t fsp_attr_show_hscroll(struct psmouse *psmouse,
void *data, char *buf)
{
struct fsp_data *pad = psmouse->private;
return sprintf(buf, "%d\n", pad->hscroll);
}
static ssize_t fsp_attr_set_hscroll(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
unsigned long val;
if (strict_strtoul(buf, 10, &val) || val > 1)
return -EINVAL;
fsp_onpad_hscr(psmouse, val);
return count;
}
static ssize_t fsp_attr_show_flags(struct psmouse *psmouse,
void *data, char *buf)
{
struct fsp_data *pad = psmouse->private;
return sprintf(buf, "%c\n",
pad->flags & FSPDRV_FLAG_EN_OPC ? 'C' : 'c');
}
static ssize_t fsp_attr_set_flags(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
struct fsp_data *pad = psmouse->private;
size_t i;
for (i = 0; i < count; i++) {
switch (buf[i]) {
case 'C':
pad->flags |= FSPDRV_FLAG_EN_OPC;
break;
case 'c':
pad->flags &= ~FSPDRV_FLAG_EN_OPC;
break;
default:
return -EINVAL;
}
}
return count;
}
static ssize_t fsp_attr_show_ver(struct psmouse *psmouse,
void *data, char *buf)
{
return sprintf(buf, "Sentelic FSP kernel module %s\n", fsp_drv_ver);
}
static void fsp_packet_debug(unsigned char packet[])
{
static unsigned int ps2_packet_cnt;
static unsigned int ps2_last_second;
unsigned int jiffies_msec;
ps2_packet_cnt++;
jiffies_msec = jiffies_to_msecs(jiffies);
printk(KERN_DEBUG "%08dms PS/2 packets: %02x, %02x, %02x, %02x\n",
jiffies_msec, packet[0], packet[1], packet[2], packet[3]);
if (jiffies_msec - ps2_last_second > 1000) {
printk(KERN_DEBUG "PS/2 packets/sec = %d\n", ps2_packet_cnt);
ps2_packet_cnt = 0;
ps2_last_second = jiffies_msec;
}
}
static void fsp_packet_debug(unsigned char packet[])
{
}
static psmouse_ret_t fsp_process_byte(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
struct fsp_data *ad = psmouse->private;
unsigned char *packet = psmouse->packet;
unsigned char button_status = 0, lscroll = 0, rscroll = 0;
int rel_x, rel_y;
if (psmouse->pktcnt < 4)
return PSMOUSE_GOOD_DATA;
switch (psmouse->packet[0] >> FSP_PKT_TYPE_SHIFT) {
case FSP_PKT_TYPE_ABS:
dev_warn(&psmouse->ps2dev.serio->dev,
"Unexpected absolute mode packet, ignored.\n");
break;
case FSP_PKT_TYPE_NORMAL_OPC:
if ((ad->flags & FSPDRV_FLAG_EN_OPC) != FSPDRV_FLAG_EN_OPC)
packet[0] &= ~BIT(0);
case FSP_PKT_TYPE_NORMAL:
if (packet[3] != 0) {
if (packet[3] & BIT(0))
button_status |= 0x01;
if (packet[3] & BIT(1))
button_status |= 0x0f;
if (packet[3] & BIT(2))
button_status |= BIT(4);
if (packet[3] & BIT(3))
button_status |= BIT(5);
if (button_status != 0)
packet[3] = button_status;
rscroll = (packet[3] >> 4) & 1;
lscroll = (packet[3] >> 5) & 1;
}
input_report_rel(dev, REL_WHEEL,
(int)(packet[3] & 8) - (int)(packet[3] & 7));
input_report_rel(dev, REL_HWHEEL, lscroll - rscroll);
input_report_key(dev, BTN_BACK, lscroll);
input_report_key(dev, BTN_FORWARD, rscroll);
input_report_key(dev, BTN_LEFT, packet[0] & 1);
input_report_key(dev, BTN_MIDDLE, (packet[0] >> 2) & 1);
input_report_key(dev, BTN_RIGHT, (packet[0] >> 1) & 1);
rel_x = packet[1] ? (int)packet[1] - (int)((packet[0] << 4) & 0x100) : 0;
rel_y = packet[2] ? (int)((packet[0] << 3) & 0x100) - (int)packet[2] : 0;
input_report_rel(dev, REL_X, rel_x);
input_report_rel(dev, REL_Y, rel_y);
break;
}
input_sync(dev);
fsp_packet_debug(packet);
return PSMOUSE_FULL_PACKET;
}
static int fsp_activate_protocol(struct psmouse *psmouse)
{
struct fsp_data *pad = psmouse->private;
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[2];
int val;
param[0] = 200;
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE);
param[0] = 200;
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE);
param[0] = 80;
ps2_command(ps2dev, param, PSMOUSE_CMD_SETRATE);
ps2_command(ps2dev, param, PSMOUSE_CMD_GETID);
if (param[0] != 0x04) {
dev_err(&psmouse->ps2dev.serio->dev,
"Unable to enable 4 bytes packet format.\n");
return -EIO;
}
if (fsp_reg_read(psmouse, FSP_REG_SYSCTL5, &val)) {
dev_err(&psmouse->ps2dev.serio->dev,
"Unable to read SYSCTL5 register.\n");
return -EIO;
}
val &= ~(FSP_BIT_EN_MSID7 | FSP_BIT_EN_MSID8 | FSP_BIT_EN_AUTO_MSID8);
val &= ~FSP_BIT_EN_PKT_G0;
if (pad->buttons == 0x06) {
val |= FSP_BIT_EN_MSID6;
}
if (fsp_reg_write(psmouse, FSP_REG_SYSCTL5, val)) {
dev_err(&psmouse->ps2dev.serio->dev,
"Unable to set up required mode bits.\n");
return -EIO;
}
if (fsp_opc_tag_enable(psmouse, true))
dev_warn(&psmouse->ps2dev.serio->dev,
"Failed to enable OPC tag mode.\n");
fsp_onpad_vscr(psmouse, true);
fsp_onpad_hscr(psmouse, true);
return 0;
}
int fsp_detect(struct psmouse *psmouse, bool set_properties)
{
int id;
if (fsp_reg_read(psmouse, FSP_REG_DEVICE_ID, &id))
return -EIO;
if (id != 0x01)
return -ENODEV;
if (set_properties) {
psmouse->vendor = "Sentelic";
psmouse->name = "FingerSensingPad";
}
return 0;
}
static void fsp_reset(struct psmouse *psmouse)
{
fsp_opc_tag_enable(psmouse, false);
fsp_onpad_vscr(psmouse, false);
fsp_onpad_hscr(psmouse, false);
}
static void fsp_disconnect(struct psmouse *psmouse)
{
sysfs_remove_group(&psmouse->ps2dev.serio->dev.kobj,
&fsp_attribute_group);
fsp_reset(psmouse);
kfree(psmouse->private);
}
static int fsp_reconnect(struct psmouse *psmouse)
{
int version;
if (fsp_detect(psmouse, 0))
return -ENODEV;
if (fsp_get_version(psmouse, &version))
return -ENODEV;
if (fsp_activate_protocol(psmouse))
return -EIO;
return 0;
}
int fsp_init(struct psmouse *psmouse)
{
struct fsp_data *priv;
int ver, rev, buttons;
int error;
if (fsp_get_version(psmouse, &ver) ||
fsp_get_revision(psmouse, &rev) ||
fsp_get_buttons(psmouse, &buttons)) {
return -ENODEV;
}
printk(KERN_INFO
"Finger Sensing Pad, hw: %d.%d.%d, sw: %s, buttons: %d\n",
ver >> 4, ver & 0x0F, rev, fsp_drv_ver, buttons & 7);
psmouse->private = priv = kzalloc(sizeof(struct fsp_data), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->ver = ver;
priv->rev = rev;
priv->buttons = buttons;
priv->flags |= FSPDRV_FLAG_EN_OPC;
__set_bit(BTN_MIDDLE, psmouse->dev->keybit);
__set_bit(BTN_BACK, psmouse->dev->keybit);
__set_bit(BTN_FORWARD, psmouse->dev->keybit);
__set_bit(REL_WHEEL, psmouse->dev->relbit);
__set_bit(REL_HWHEEL, psmouse->dev->relbit);
psmouse->protocol_handler = fsp_process_byte;
psmouse->disconnect = fsp_disconnect;
psmouse->reconnect = fsp_reconnect;
psmouse->cleanup = fsp_reset;
psmouse->pktsize = 4;
error = fsp_activate_protocol(psmouse);
if (error)
goto err_out;
error = sysfs_create_group(&psmouse->ps2dev.serio->dev.kobj,
&fsp_attribute_group);
if (error) {
dev_err(&psmouse->ps2dev.serio->dev,
"Failed to create sysfs attributes (%d)", error);
goto err_out;
}
return 0;
err_out:
kfree(psmouse->private);
psmouse->private = NULL;
return error;
}
