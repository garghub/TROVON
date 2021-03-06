static int xc2028_get_reg(struct xc2028_data *priv, u16 reg, u16 *val)
{
unsigned char buf[2];
unsigned char ibuf[2];
tuner_dbg("%s %04x called\n", __func__, reg);
buf[0] = reg >> 8;
buf[1] = (unsigned char) reg;
if (i2c_send_recv(priv, buf, 2, ibuf, 2) != 2)
return -EIO;
*val = (ibuf[1]) | (ibuf[0] << 8);
return 0;
}
static void dump_firm_type_and_int_freq(unsigned int type, u16 int_freq)
{
if (type & BASE)
printk("BASE ");
if (type & INIT1)
printk("INIT1 ");
if (type & F8MHZ)
printk("F8MHZ ");
if (type & MTS)
printk("MTS ");
if (type & D2620)
printk("D2620 ");
if (type & D2633)
printk("D2633 ");
if (type & DTV6)
printk("DTV6 ");
if (type & QAM)
printk("QAM ");
if (type & DTV7)
printk("DTV7 ");
if (type & DTV78)
printk("DTV78 ");
if (type & DTV8)
printk("DTV8 ");
if (type & FM)
printk("FM ");
if (type & INPUT1)
printk("INPUT1 ");
if (type & LCD)
printk("LCD ");
if (type & NOGD)
printk("NOGD ");
if (type & MONO)
printk("MONO ");
if (type & ATSC)
printk("ATSC ");
if (type & IF)
printk("IF ");
if (type & LG60)
printk("LG60 ");
if (type & ATI638)
printk("ATI638 ");
if (type & OREN538)
printk("OREN538 ");
if (type & OREN36)
printk("OREN36 ");
if (type & TOYOTA388)
printk("TOYOTA388 ");
if (type & TOYOTA794)
printk("TOYOTA794 ");
if (type & DIBCOM52)
printk("DIBCOM52 ");
if (type & ZARLINK456)
printk("ZARLINK456 ");
if (type & CHINA)
printk("CHINA ");
if (type & F6MHZ)
printk("F6MHZ ");
if (type & INPUT2)
printk("INPUT2 ");
if (type & SCODE)
printk("SCODE ");
if (type & HAS_IF)
printk("HAS_IF_%d ", int_freq);
}
static v4l2_std_id parse_audio_std_option(void)
{
if (strcasecmp(audio_std, "A2") == 0)
return V4L2_STD_A2;
if (strcasecmp(audio_std, "A2/A") == 0)
return V4L2_STD_A2_A;
if (strcasecmp(audio_std, "A2/B") == 0)
return V4L2_STD_A2_B;
if (strcasecmp(audio_std, "NICAM") == 0)
return V4L2_STD_NICAM;
if (strcasecmp(audio_std, "NICAM/A") == 0)
return V4L2_STD_NICAM_A;
if (strcasecmp(audio_std, "NICAM/B") == 0)
return V4L2_STD_NICAM_B;
return 0;
}
static int check_device_status(struct xc2028_data *priv)
{
switch (priv->state) {
case XC2028_NO_FIRMWARE:
case XC2028_WAITING_FIRMWARE:
return -EAGAIN;
case XC2028_ACTIVE:
case XC2028_SLEEP:
return 0;
case XC2028_NODEV:
return -ENODEV;
}
return 0;
}
static void free_firmware(struct xc2028_data *priv)
{
int i;
tuner_dbg("%s called\n", __func__);
if (!priv->firm)
return;
for (i = 0; i < priv->firm_size; i++)
kfree(priv->firm[i].ptr);
kfree(priv->firm);
priv->firm = NULL;
priv->firm_size = 0;
priv->state = XC2028_NO_FIRMWARE;
memset(&priv->cur_fw, 0, sizeof(priv->cur_fw));
}
static int load_all_firmwares(struct dvb_frontend *fe,
const struct firmware *fw)
{
struct xc2028_data *priv = fe->tuner_priv;
const unsigned char *p, *endp;
int rc = 0;
int n, n_array;
char name[33];
tuner_dbg("%s called\n", __func__);
p = fw->data;
endp = p + fw->size;
if (fw->size < sizeof(name) - 1 + 2 + 2) {
tuner_err("Error: firmware file %s has invalid size!\n",
priv->fname);
goto corrupt;
}
memcpy(name, p, sizeof(name) - 1);
name[sizeof(name) - 1] = 0;
p += sizeof(name) - 1;
priv->firm_version = get_unaligned_le16(p);
p += 2;
n_array = get_unaligned_le16(p);
p += 2;
tuner_info("Loading %d firmware images from %s, type: %s, ver %d.%d\n",
n_array, priv->fname, name,
priv->firm_version >> 8, priv->firm_version & 0xff);
priv->firm = kcalloc(n_array, sizeof(*priv->firm), GFP_KERNEL);
if (priv->firm == NULL) {
tuner_err("Not enough memory to load firmware file.\n");
rc = -ENOMEM;
goto err;
}
priv->firm_size = n_array;
n = -1;
while (p < endp) {
__u32 type, size;
v4l2_std_id id;
__u16 int_freq = 0;
n++;
if (n >= n_array) {
tuner_err("More firmware images in file than "
"were expected!\n");
goto corrupt;
}
if (endp - p < sizeof(type) + sizeof(id) + sizeof(size))
goto header;
type = get_unaligned_le32(p);
p += sizeof(type);
id = get_unaligned_le64(p);
p += sizeof(id);
if (type & HAS_IF) {
int_freq = get_unaligned_le16(p);
p += sizeof(int_freq);
if (endp - p < sizeof(size))
goto header;
}
size = get_unaligned_le32(p);
p += sizeof(size);
if (!size || size > endp - p) {
tuner_err("Firmware type ");
dump_firm_type(type);
printk("(%x), id %llx is corrupted "
"(size=%d, expected %d)\n",
type, (unsigned long long)id,
(unsigned)(endp - p), size);
goto corrupt;
}
priv->firm[n].ptr = kzalloc(size, GFP_KERNEL);
if (priv->firm[n].ptr == NULL) {
tuner_err("Not enough memory to load firmware file.\n");
rc = -ENOMEM;
goto err;
}
tuner_dbg("Reading firmware type ");
if (debug) {
dump_firm_type_and_int_freq(type, int_freq);
printk("(%x), id %llx, size=%d.\n",
type, (unsigned long long)id, size);
}
memcpy(priv->firm[n].ptr, p, size);
priv->firm[n].type = type;
priv->firm[n].id = id;
priv->firm[n].size = size;
priv->firm[n].int_freq = int_freq;
p += size;
}
if (n + 1 != priv->firm_size) {
tuner_err("Firmware file is incomplete!\n");
goto corrupt;
}
goto done;
header:
tuner_err("Firmware header is incomplete!\n");
corrupt:
rc = -EINVAL;
tuner_err("Error: firmware file is corrupted!\n");
err:
tuner_info("Releasing partially loaded firmware file.\n");
free_firmware(priv);
done:
if (rc == 0)
tuner_dbg("Firmware files loaded.\n");
else
priv->state = XC2028_NODEV;
return rc;
}
static int seek_firmware(struct dvb_frontend *fe, unsigned int type,
v4l2_std_id *id)
{
struct xc2028_data *priv = fe->tuner_priv;
int i, best_i = -1, best_nr_matches = 0;
unsigned int type_mask = 0;
tuner_dbg("%s called, want type=", __func__);
if (debug) {
dump_firm_type(type);
printk("(%x), id %016llx.\n", type, (unsigned long long)*id);
}
if (!priv->firm) {
tuner_err("Error! firmware not loaded\n");
return -EINVAL;
}
if (((type & ~SCODE) == 0) && (*id == 0))
*id = V4L2_STD_PAL;
if (type & BASE)
type_mask = BASE_TYPES;
else if (type & SCODE) {
type &= SCODE_TYPES;
type_mask = SCODE_TYPES & ~HAS_IF;
} else if (type & DTV_TYPES)
type_mask = DTV_TYPES;
else if (type & STD_SPECIFIC_TYPES)
type_mask = STD_SPECIFIC_TYPES;
type &= type_mask;
if (!(type & SCODE))
type_mask = ~0;
for (i = 0; i < priv->firm_size; i++) {
if ((type == (priv->firm[i].type & type_mask)) &&
(*id == priv->firm[i].id))
goto found;
}
for (i = 0; i < priv->firm_size; i++) {
v4l2_std_id match_mask;
int nr_matches;
if (type != (priv->firm[i].type & type_mask))
continue;
match_mask = *id & priv->firm[i].id;
if (!match_mask)
continue;
if ((*id & match_mask) == *id)
goto found;
nr_matches = hweight64(match_mask);
if (nr_matches > best_nr_matches) {
best_nr_matches = nr_matches;
best_i = i;
}
}
if (best_nr_matches > 0) {
tuner_dbg("Selecting best matching firmware (%d bits) for "
"type=", best_nr_matches);
dump_firm_type(type);
printk("(%x), id %016llx:\n", type, (unsigned long long)*id);
i = best_i;
goto found;
}
i = -ENOENT;
goto ret;
found:
*id = priv->firm[i].id;
ret:
tuner_dbg("%s firmware for type=", (i < 0) ? "Can't find" : "Found");
if (debug) {
dump_firm_type(type);
printk("(%x), id %016llx.\n", type, (unsigned long long)*id);
}
return i;
}
static inline int do_tuner_callback(struct dvb_frontend *fe, int cmd, int arg)
{
struct xc2028_data *priv = fe->tuner_priv;
return (!fe->callback) ? -EINVAL :
fe->callback(((fe->dvb) && (fe->dvb->priv)) ?
fe->dvb->priv : priv->i2c_props.adap->algo_data,
DVB_FRONTEND_COMPONENT_TUNER, cmd, arg);
}
static int load_firmware(struct dvb_frontend *fe, unsigned int type,
v4l2_std_id *id)
{
struct xc2028_data *priv = fe->tuner_priv;
int pos, rc;
unsigned char *p, *endp, buf[MAX_XFER_SIZE];
if (priv->ctrl.max_len > sizeof(buf))
priv->ctrl.max_len = sizeof(buf);
tuner_dbg("%s called\n", __func__);
pos = seek_firmware(fe, type, id);
if (pos < 0)
return pos;
tuner_info("Loading firmware for type=");
dump_firm_type(priv->firm[pos].type);
printk("(%x), id %016llx.\n", priv->firm[pos].type,
(unsigned long long)*id);
p = priv->firm[pos].ptr;
endp = p + priv->firm[pos].size;
while (p < endp) {
__u16 size;
if (p + sizeof(size) > endp) {
tuner_err("Firmware chunk size is wrong\n");
return -EINVAL;
}
size = le16_to_cpu(*(__le16 *) p);
p += sizeof(size);
if (size == 0xffff)
return 0;
if (!size) {
rc = do_tuner_callback(fe, XC2028_TUNER_RESET, 0);
if (rc < 0) {
tuner_err("Error at RESET code %d\n",
(*p) & 0x7f);
return -EINVAL;
}
continue;
}
if (size >= 0xff00) {
switch (size) {
case 0xff00:
rc = do_tuner_callback(fe, XC2028_RESET_CLK, 0);
if (rc < 0) {
tuner_err("Error at RESET code %d\n",
(*p) & 0x7f);
return -EINVAL;
}
break;
default:
tuner_info("Invalid RESET code %d\n",
size & 0x7f);
return -EINVAL;
}
continue;
}
if (size & 0x8000) {
msleep(size & 0x7fff);
continue;
}
if ((size + p > endp)) {
tuner_err("missing bytes: need %d, have %d\n",
size, (int)(endp - p));
return -EINVAL;
}
buf[0] = *p;
p++;
size--;
while (size > 0) {
int len = (size < priv->ctrl.max_len - 1) ?
size : priv->ctrl.max_len - 1;
memcpy(buf + 1, p, len);
rc = i2c_send(priv, buf, len + 1);
if (rc < 0) {
tuner_err("%d returned from send\n", rc);
return -EINVAL;
}
p += len;
size -= len;
}
rc = do_tuner_callback(fe, XC2028_I2C_FLUSH, 0);
if ((rc < 0) && (rc != -EINVAL)) {
tuner_err("error executing flush: %d\n", rc);
return rc;
}
}
return 0;
}
static int load_scode(struct dvb_frontend *fe, unsigned int type,
v4l2_std_id *id, __u16 int_freq, int scode)
{
struct xc2028_data *priv = fe->tuner_priv;
int pos, rc;
unsigned char *p;
tuner_dbg("%s called\n", __func__);
if (!int_freq) {
pos = seek_firmware(fe, type, id);
if (pos < 0)
return pos;
} else {
for (pos = 0; pos < priv->firm_size; pos++) {
if ((priv->firm[pos].int_freq == int_freq) &&
(priv->firm[pos].type & HAS_IF))
break;
}
if (pos == priv->firm_size)
return -ENOENT;
}
p = priv->firm[pos].ptr;
if (priv->firm[pos].type & HAS_IF) {
if (priv->firm[pos].size != 12 * 16 || scode >= 16)
return -EINVAL;
p += 12 * scode;
} else {
if (priv->firm[pos].size != 14 * 16 || scode >= 16 ||
le16_to_cpu(*(__le16 *)(p + 14 * scode)) != 12)
return -EINVAL;
p += 14 * scode + 2;
}
tuner_info("Loading SCODE for type=");
dump_firm_type_and_int_freq(priv->firm[pos].type,
priv->firm[pos].int_freq);
printk("(%x), id %016llx.\n", priv->firm[pos].type,
(unsigned long long)*id);
if (priv->firm_version < 0x0202)
rc = send_seq(priv, {0x20, 0x00, 0x00, 0x00});
else
rc = send_seq(priv, {0xa0, 0x00, 0x00, 0x00});
if (rc < 0)
return -EIO;
rc = i2c_send(priv, p, 12);
if (rc < 0)
return -EIO;
rc = send_seq(priv, {0x00, 0x8c});
if (rc < 0)
return -EIO;
return 0;
}
static int check_firmware(struct dvb_frontend *fe, unsigned int type,
v4l2_std_id std, __u16 int_freq)
{
struct xc2028_data *priv = fe->tuner_priv;
struct firmware_properties new_fw;
int rc, retry_count = 0;
u16 version, hwmodel;
v4l2_std_id std0;
tuner_dbg("%s called\n", __func__);
rc = check_device_status(priv);
if (rc < 0)
return rc;
if (priv->ctrl.mts && !(type & FM))
type |= MTS;
retry:
new_fw.type = type;
new_fw.id = std;
new_fw.std_req = std;
new_fw.scode_table = SCODE | priv->ctrl.scode_table;
new_fw.scode_nr = 0;
new_fw.int_freq = int_freq;
tuner_dbg("checking firmware, user requested type=");
if (debug) {
dump_firm_type(new_fw.type);
printk("(%x), id %016llx, ", new_fw.type,
(unsigned long long)new_fw.std_req);
if (!int_freq) {
printk("scode_tbl ");
dump_firm_type(priv->ctrl.scode_table);
printk("(%x), ", priv->ctrl.scode_table);
} else
printk("int_freq %d, ", new_fw.int_freq);
printk("scode_nr %d\n", new_fw.scode_nr);
}
if ((priv->state == XC2028_ACTIVE) &&
(((BASE | new_fw.type) & BASE_TYPES) ==
(priv->cur_fw.type & BASE_TYPES))) {
tuner_dbg("BASE firmware not changed.\n");
goto skip_base;
}
memset(&priv->cur_fw, 0, sizeof(priv->cur_fw));
rc = do_tuner_callback(fe, XC2028_TUNER_RESET, 0);
if (rc < 0)
goto fail;
std0 = 0;
rc = load_firmware(fe, BASE | new_fw.type, &std0);
if (rc < 0) {
tuner_err("Error %d while loading base firmware\n",
rc);
goto fail;
}
tuner_dbg("Load init1 firmware, if exists\n");
rc = load_firmware(fe, BASE | INIT1 | new_fw.type, &std0);
if (rc == -ENOENT)
rc = load_firmware(fe, (BASE | INIT1 | new_fw.type) & ~F8MHZ,
&std0);
if (rc < 0 && rc != -ENOENT) {
tuner_err("Error %d while loading init1 firmware\n",
rc);
goto fail;
}
skip_base:
if (priv->cur_fw.type == (BASE | new_fw.type) &&
priv->cur_fw.std_req == std) {
tuner_dbg("Std-specific firmware already loaded.\n");
goto skip_std_specific;
}
priv->cur_fw.scode_table = 0;
rc = load_firmware(fe, new_fw.type, &new_fw.id);
if (rc == -ENOENT)
rc = load_firmware(fe, new_fw.type & ~F8MHZ, &new_fw.id);
if (rc < 0)
goto fail;
skip_std_specific:
if (priv->cur_fw.scode_table == new_fw.scode_table &&
priv->cur_fw.scode_nr == new_fw.scode_nr) {
tuner_dbg("SCODE firmware already loaded.\n");
goto check_device;
}
if (new_fw.type & FM)
goto check_device;
tuner_dbg("Trying to load scode %d\n", new_fw.scode_nr);
rc = load_scode(fe, new_fw.type | new_fw.scode_table, &new_fw.id,
new_fw.int_freq, new_fw.scode_nr);
check_device:
if (xc2028_get_reg(priv, 0x0004, &version) < 0 ||
xc2028_get_reg(priv, 0x0008, &hwmodel) < 0) {
tuner_err("Unable to read tuner registers.\n");
goto fail;
}
tuner_dbg("Device is Xceive %d version %d.%d, "
"firmware version %d.%d\n",
hwmodel, (version & 0xf000) >> 12, (version & 0xf00) >> 8,
(version & 0xf0) >> 4, version & 0xf);
if (priv->ctrl.read_not_reliable)
goto read_not_reliable;
if (priv->firm_version != ((version & 0xf0) << 4 | (version & 0x0f))) {
if (!priv->ctrl.read_not_reliable) {
tuner_err("Incorrect readback of firmware version.\n");
goto fail;
} else {
tuner_err("Returned an incorrect version. However, "
"read is not reliable enough. Ignoring it.\n");
hwmodel = 3028;
}
}
if (priv->hwmodel == 0 && (hwmodel == 2028 || hwmodel == 3028)) {
priv->hwmodel = hwmodel;
priv->hwvers = version & 0xff00;
} else if (priv->hwmodel == 0 || priv->hwmodel != hwmodel ||
priv->hwvers != (version & 0xff00)) {
tuner_err("Read invalid device hardware information - tuner "
"hung?\n");
goto fail;
}
read_not_reliable:
priv->cur_fw = new_fw;
priv->cur_fw.type |= BASE;
priv->state = XC2028_ACTIVE;
return 0;
fail:
priv->state = XC2028_SLEEP;
memset(&priv->cur_fw, 0, sizeof(priv->cur_fw));
if (retry_count < 8) {
msleep(50);
retry_count++;
tuner_dbg("Retrying firmware load\n");
goto retry;
}
if (rc == -ENOENT)
rc = -EINVAL;
return rc;
}
static int xc2028_signal(struct dvb_frontend *fe, u16 *strength)
{
struct xc2028_data *priv = fe->tuner_priv;
u16 frq_lock, signal = 0;
int rc, i;
tuner_dbg("%s called\n", __func__);
rc = check_device_status(priv);
if (rc < 0)
return rc;
mutex_lock(&priv->lock);
for (i = 0; i < 3; i++) {
rc = xc2028_get_reg(priv, XREG_LOCK, &frq_lock);
if (rc < 0)
goto ret;
if (frq_lock)
break;
msleep(6);
}
if (frq_lock == 2)
goto ret;
rc = xc2028_get_reg(priv, XREG_SNR, &signal);
if (rc < 0)
goto ret;
signal = ((1 << 12) - 1) | ((signal & 0x07) << 12);
ret:
mutex_unlock(&priv->lock);
*strength = signal;
tuner_dbg("signal strength is %d\n", signal);
return rc;
}
static int xc2028_get_afc(struct dvb_frontend *fe, s32 *afc)
{
struct xc2028_data *priv = fe->tuner_priv;
int i, rc;
u16 frq_lock = 0;
s16 afc_reg = 0;
rc = check_device_status(priv);
if (rc < 0)
return rc;
mutex_lock(&priv->lock);
for (i = 0; i < 3; i++) {
rc = xc2028_get_reg(priv, XREG_LOCK, &frq_lock);
if (rc < 0)
goto ret;
if (frq_lock)
break;
msleep(6);
}
if (frq_lock == 2)
goto ret;
rc = xc2028_get_reg(priv, XREG_FREQ_ERROR, &afc_reg);
if (rc < 0)
goto ret;
*afc = afc_reg * 15625;
tuner_dbg("AFC is %d Hz\n", *afc);
ret:
mutex_unlock(&priv->lock);
return rc;
}
static int generic_set_freq(struct dvb_frontend *fe, u32 freq ,
enum v4l2_tuner_type new_type,
unsigned int type,
v4l2_std_id std,
u16 int_freq)
{
struct xc2028_data *priv = fe->tuner_priv;
int rc = -EINVAL;
unsigned char buf[4];
u32 div, offset = 0;
tuner_dbg("%s called\n", __func__);
mutex_lock(&priv->lock);
tuner_dbg("should set frequency %d kHz\n", freq / 1000);
if (check_firmware(fe, type, std, int_freq) < 0)
goto ret;
switch (new_type) {
case V4L2_TUNER_ANALOG_TV:
rc = send_seq(priv, {0x00, 0x00});
break;
case V4L2_TUNER_RADIO:
break;
case V4L2_TUNER_DIGITAL_TV:
if (priv->cur_fw.type & DTV6)
offset = 1750000;
else
offset = 2750000;
#if 0
if (priv->firm_version < 0x0302) {
if (priv->cur_fw.type & DTV7)
offset += 500000;
} else {
if (priv->cur_fw.type & DTV7)
offset -= 300000;
else if (type != ATSC)
offset += 200000;
}
#endif
}
div = (freq - offset + DIV / 2) / DIV;
if (priv->firm_version < 0x0202)
rc = send_seq(priv, {0x00, XREG_RF_FREQ, 0x00, 0x00});
else
rc = send_seq(priv, {0x80, XREG_RF_FREQ, 0x00, 0x00});
if (rc < 0)
goto ret;
if (priv->ctrl.msleep)
msleep(priv->ctrl.msleep);
do_tuner_callback(fe, XC2028_RESET_CLK, 1);
msleep(10);
buf[0] = 0xff & (div >> 24);
buf[1] = 0xff & (div >> 16);
buf[2] = 0xff & (div >> 8);
buf[3] = 0xff & (div);
rc = i2c_send(priv, buf, sizeof(buf));
if (rc < 0)
goto ret;
msleep(100);
priv->frequency = freq;
tuner_dbg("divisor= %*ph (freq=%d.%03d)\n", 4, buf,
freq / 1000000, (freq % 1000000) / 1000);
rc = 0;
ret:
mutex_unlock(&priv->lock);
return rc;
}
static int xc2028_set_analog_freq(struct dvb_frontend *fe,
struct analog_parameters *p)
{
struct xc2028_data *priv = fe->tuner_priv;
unsigned int type=0;
tuner_dbg("%s called\n", __func__);
if (p->mode == V4L2_TUNER_RADIO) {
type |= FM;
if (priv->ctrl.input1)
type |= INPUT1;
return generic_set_freq(fe, (625l * p->frequency) / 10,
V4L2_TUNER_RADIO, type, 0, 0);
}
if (!p->std)
p->std = V4L2_STD_MN;
if (!(p->std & V4L2_STD_MN))
type |= F8MHZ;
p->std |= parse_audio_std_option();
return generic_set_freq(fe, 62500l * p->frequency,
V4L2_TUNER_ANALOG_TV, type, p->std, 0);
}
static int xc2028_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 delsys = c->delivery_system;
u32 bw = c->bandwidth_hz;
struct xc2028_data *priv = fe->tuner_priv;
int rc;
unsigned int type = 0;
u16 demod = 0;
tuner_dbg("%s called\n", __func__);
rc = check_device_status(priv);
if (rc < 0)
return rc;
switch (delsys) {
case SYS_DVBT:
case SYS_DVBT2:
if (bw <= 6000000)
type |= QAM;
switch (priv->ctrl.type) {
case XC2028_D2633:
type |= D2633;
break;
case XC2028_D2620:
type |= D2620;
break;
case XC2028_AUTO:
default:
if (priv->ctrl.demod == XC3028_FE_ZARLINK456)
type |= D2633;
else
type |= D2620;
}
break;
case SYS_ATSC:
type |= ATSC | D2633;
break;
default:
return -EINVAL;
}
if (bw <= 6000000) {
type |= DTV6;
priv->ctrl.vhfbw7 = 0;
priv->ctrl.uhfbw8 = 0;
} else if (bw <= 7000000) {
if (c->frequency < 470000000)
priv->ctrl.vhfbw7 = 1;
else
priv->ctrl.uhfbw8 = 0;
type |= (priv->ctrl.vhfbw7 && priv->ctrl.uhfbw8) ? DTV78 : DTV7;
type |= F8MHZ;
} else {
if (c->frequency < 470000000)
priv->ctrl.vhfbw7 = 0;
else
priv->ctrl.uhfbw8 = 1;
type |= (priv->ctrl.vhfbw7 && priv->ctrl.uhfbw8) ? DTV78 : DTV8;
type |= F8MHZ;
}
if (priv->ctrl.demod) {
demod = priv->ctrl.demod;
if (type == ATSC || priv->firm_version < 0x0302)
demod += 200;
}
return generic_set_freq(fe, c->frequency,
V4L2_TUNER_DIGITAL_TV, type, 0, demod);
}
static int xc2028_sleep(struct dvb_frontend *fe)
{
struct xc2028_data *priv = fe->tuner_priv;
int rc;
rc = check_device_status(priv);
if (rc < 0)
return rc;
if (no_poweroff || priv->ctrl.disable_power_mgmt)
return 0;
tuner_dbg("Putting xc2028/3028 into poweroff mode.\n");
if (debug > 1) {
tuner_dbg("Printing sleep stack trace:\n");
dump_stack();
}
mutex_lock(&priv->lock);
if (priv->firm_version < 0x0202)
rc = send_seq(priv, {0x00, XREG_POWER_DOWN, 0x00, 0x00});
else
rc = send_seq(priv, {0x80, XREG_POWER_DOWN, 0x00, 0x00});
priv->state = XC2028_SLEEP;
mutex_unlock(&priv->lock);
return rc;
}
static int xc2028_dvb_release(struct dvb_frontend *fe)
{
struct xc2028_data *priv = fe->tuner_priv;
tuner_dbg("%s called\n", __func__);
mutex_lock(&xc2028_list_mutex);
if (hybrid_tuner_report_instance_count(priv) == 1) {
free_firmware(priv);
kfree(priv->ctrl.fname);
priv->ctrl.fname = NULL;
}
if (priv)
hybrid_tuner_release_state(priv);
mutex_unlock(&xc2028_list_mutex);
fe->tuner_priv = NULL;
return 0;
}
static int xc2028_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct xc2028_data *priv = fe->tuner_priv;
int rc;
tuner_dbg("%s called\n", __func__);
rc = check_device_status(priv);
if (rc < 0)
return rc;
*frequency = priv->frequency;
return 0;
}
static void load_firmware_cb(const struct firmware *fw,
void *context)
{
struct dvb_frontend *fe = context;
struct xc2028_data *priv = fe->tuner_priv;
int rc;
tuner_dbg("request_firmware_nowait(): %s\n", fw ? "OK" : "error");
if (!fw) {
tuner_err("Could not load firmware %s.\n", priv->fname);
priv->state = XC2028_NODEV;
return;
}
rc = load_all_firmwares(fe, fw);
release_firmware(fw);
if (rc < 0)
return;
priv->state = XC2028_SLEEP;
}
static int xc2028_set_config(struct dvb_frontend *fe, void *priv_cfg)
{
struct xc2028_data *priv = fe->tuner_priv;
struct xc2028_ctrl *p = priv_cfg;
int rc = 0;
tuner_dbg("%s called\n", __func__);
mutex_lock(&priv->lock);
kfree(priv->ctrl.fname);
memcpy(&priv->ctrl, p, sizeof(priv->ctrl));
if (p->fname) {
priv->ctrl.fname = kstrdup(p->fname, GFP_KERNEL);
if (priv->ctrl.fname == NULL)
rc = -ENOMEM;
}
if (!firmware_name[0] && p->fname &&
priv->fname && strcmp(p->fname, priv->fname))
free_firmware(priv);
if (priv->ctrl.max_len < 9)
priv->ctrl.max_len = 13;
if (priv->state == XC2028_NO_FIRMWARE) {
if (!firmware_name[0])
priv->fname = priv->ctrl.fname;
else
priv->fname = firmware_name;
rc = request_firmware_nowait(THIS_MODULE, 1,
priv->fname,
priv->i2c_props.adap->dev.parent,
GFP_KERNEL,
fe, load_firmware_cb);
if (rc < 0) {
tuner_err("Failed to request firmware %s\n",
priv->fname);
priv->state = XC2028_NODEV;
} else
priv->state = XC2028_WAITING_FIRMWARE;
}
mutex_unlock(&priv->lock);
return rc;
}
struct dvb_frontend *xc2028_attach(struct dvb_frontend *fe,
struct xc2028_config *cfg)
{
struct xc2028_data *priv;
int instance;
if (debug)
printk(KERN_DEBUG "xc2028: Xcv2028/3028 init called!\n");
if (NULL == cfg)
return NULL;
if (!fe) {
printk(KERN_ERR "xc2028: No frontend!\n");
return NULL;
}
mutex_lock(&xc2028_list_mutex);
instance = hybrid_tuner_request_state(struct xc2028_data, priv,
hybrid_tuner_instance_list,
cfg->i2c_adap, cfg->i2c_addr,
"xc2028");
switch (instance) {
case 0:
goto fail;
break;
case 1:
priv->ctrl.max_len = 13;
mutex_init(&priv->lock);
fe->tuner_priv = priv;
break;
case 2:
fe->tuner_priv = priv;
break;
}
memcpy(&fe->ops.tuner_ops, &xc2028_dvb_tuner_ops,
sizeof(xc2028_dvb_tuner_ops));
tuner_info("type set to %s\n", "XCeive xc2028/xc3028 tuner");
if (cfg->ctrl)
xc2028_set_config(fe, cfg->ctrl);
mutex_unlock(&xc2028_list_mutex);
return fe;
fail:
mutex_unlock(&xc2028_list_mutex);
xc2028_dvb_release(fe);
return NULL;
}
