static unsigned int codec_send_command(struct hda_codec *codec, hda_nid_t nid,
unsigned int verb, unsigned int parm, unsigned int *res)
{
unsigned int response;
response = snd_hda_codec_read(codec, nid, 0, verb, parm);
*res = response;
return ((response == -1) ? -1 : 0);
}
static int codec_set_converter_format(struct hda_codec *codec, hda_nid_t nid,
unsigned short converter_format, unsigned int *res)
{
return codec_send_command(codec, nid, VENDOR_CHIPIO_STREAM_FORMAT,
converter_format & 0xffff, res);
}
static int codec_set_converter_stream_channel(struct hda_codec *codec,
hda_nid_t nid, unsigned char stream,
unsigned char channel, unsigned int *res)
{
unsigned char converter_stream_channel = 0;
converter_stream_channel = (stream << 4) | (channel & 0x0f);
return codec_send_command(codec, nid, AC_VERB_SET_CHANNEL_STREAMID,
converter_stream_channel, res);
}
static int chipio_send(struct hda_codec *codec,
unsigned int reg,
unsigned int data)
{
unsigned int res;
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
do {
res = snd_hda_codec_read(codec, WIDGET_CHIP_CTRL, 0,
reg, data);
if (res == VENDOR_STATUS_CHIPIO_OK)
return 0;
msleep(20);
} while (time_before(jiffies, timeout));
return -EIO;
}
static int chipio_write_address(struct hda_codec *codec,
unsigned int chip_addx)
{
struct ca0132_spec *spec = codec->spec;
int res;
if (spec->curr_chip_addx == chip_addx)
return 0;
res = chipio_send(codec, VENDOR_CHIPIO_ADDRESS_LOW,
chip_addx & 0xffff);
if (res != -EIO) {
res = chipio_send(codec, VENDOR_CHIPIO_ADDRESS_HIGH,
chip_addx >> 16);
}
spec->curr_chip_addx = (res < 0) ? ~0UL : chip_addx;
return res;
}
static int chipio_write_data(struct hda_codec *codec, unsigned int data)
{
struct ca0132_spec *spec = codec->spec;
int res;
res = chipio_send(codec, VENDOR_CHIPIO_DATA_LOW, data & 0xffff);
if (res != -EIO) {
res = chipio_send(codec, VENDOR_CHIPIO_DATA_HIGH,
data >> 16);
}
spec->curr_chip_addx = (res != -EIO) ?
(spec->curr_chip_addx + 4) : ~0UL;
return res;
}
static int chipio_write_data_multiple(struct hda_codec *codec,
const u32 *data,
unsigned int count)
{
int status = 0;
if (data == NULL) {
snd_printdd(KERN_ERR "chipio_write_data null ptr\n");
return -EINVAL;
}
while ((count-- != 0) && (status == 0))
status = chipio_write_data(codec, *data++);
return status;
}
static int chipio_read_data(struct hda_codec *codec, unsigned int *data)
{
struct ca0132_spec *spec = codec->spec;
int res;
res = chipio_send(codec, VENDOR_CHIPIO_HIC_POST_READ, 0);
if (res != -EIO) {
res = chipio_send(codec, VENDOR_CHIPIO_STATUS, 0);
}
if (res != -EIO) {
*data = snd_hda_codec_read(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_HIC_READ_DATA,
0);
}
spec->curr_chip_addx = (res != -EIO) ?
(spec->curr_chip_addx + 4) : ~0UL;
return res;
}
static int chipio_write(struct hda_codec *codec,
unsigned int chip_addx, const unsigned int data)
{
struct ca0132_spec *spec = codec->spec;
int err;
mutex_lock(&spec->chipio_mutex);
err = chipio_write_address(codec, chip_addx);
if (err < 0)
goto exit;
err = chipio_write_data(codec, data);
if (err < 0)
goto exit;
exit:
mutex_unlock(&spec->chipio_mutex);
return err;
}
static int chipio_write_multiple(struct hda_codec *codec,
u32 chip_addx,
const u32 *data,
unsigned int count)
{
struct ca0132_spec *spec = codec->spec;
int status;
mutex_lock(&spec->chipio_mutex);
status = chipio_write_address(codec, chip_addx);
if (status < 0)
goto error;
status = chipio_write_data_multiple(codec, data, count);
error:
mutex_unlock(&spec->chipio_mutex);
return status;
}
static int chipio_read(struct hda_codec *codec,
unsigned int chip_addx, unsigned int *data)
{
struct ca0132_spec *spec = codec->spec;
int err;
mutex_lock(&spec->chipio_mutex);
err = chipio_write_address(codec, chip_addx);
if (err < 0)
goto exit;
err = chipio_read_data(codec, data);
if (err < 0)
goto exit;
exit:
mutex_unlock(&spec->chipio_mutex);
return err;
}
static void chipio_set_control_flag(struct hda_codec *codec,
enum control_flag_id flag_id,
bool flag_state)
{
unsigned int val;
unsigned int flag_bit;
flag_bit = (flag_state ? 1 : 0);
val = (flag_bit << 7) | (flag_id);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_FLAG_SET, val);
}
static void chipio_set_control_param(struct hda_codec *codec,
enum control_param_id param_id, int param_val)
{
struct ca0132_spec *spec = codec->spec;
int val;
if ((param_id < 32) && (param_val < 8)) {
val = (param_val << 5) | (param_id);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PARAM_SET, val);
} else {
mutex_lock(&spec->chipio_mutex);
if (chipio_send(codec, VENDOR_CHIPIO_STATUS, 0) == 0) {
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PARAM_EX_ID_SET,
param_id);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PARAM_EX_VALUE_SET,
param_val);
}
mutex_unlock(&spec->chipio_mutex);
}
}
static void chipio_set_conn_rate(struct hda_codec *codec,
int connid, enum ca0132_sample_rate rate)
{
chipio_set_control_param(codec, CONTROL_PARAM_CONN_POINT_ID, connid);
chipio_set_control_param(codec, CONTROL_PARAM_CONN_POINT_SAMPLE_RATE,
rate);
}
static void chipio_enable_clocks(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
mutex_lock(&spec->chipio_mutex);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_LOW, 0);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PLL_PMU_WRITE, 0xff);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_LOW, 5);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PLL_PMU_WRITE, 0x0b);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_LOW, 6);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PLL_PMU_WRITE, 0xff);
mutex_unlock(&spec->chipio_mutex);
}
static int dspio_send(struct hda_codec *codec, unsigned int reg,
unsigned int data)
{
int res;
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
do {
res = snd_hda_codec_read(codec, WIDGET_DSP_CTRL, 0, reg, data);
if ((res >= 0) && (res != VENDOR_STATUS_DSPIO_BUSY))
return res;
msleep(20);
} while (time_before(jiffies, timeout));
return -EIO;
}
static void dspio_write_wait(struct hda_codec *codec)
{
int status;
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
do {
status = snd_hda_codec_read(codec, WIDGET_DSP_CTRL, 0,
VENDOR_DSPIO_STATUS, 0);
if ((status == VENDOR_STATUS_DSPIO_OK) ||
(status == VENDOR_STATUS_DSPIO_SCP_RESPONSE_QUEUE_EMPTY))
break;
msleep(1);
} while (time_before(jiffies, timeout));
}
static int dspio_write(struct hda_codec *codec, unsigned int scp_data)
{
struct ca0132_spec *spec = codec->spec;
int status;
dspio_write_wait(codec);
mutex_lock(&spec->chipio_mutex);
status = dspio_send(codec, VENDOR_DSPIO_SCP_WRITE_DATA_LOW,
scp_data & 0xffff);
if (status < 0)
goto error;
status = dspio_send(codec, VENDOR_DSPIO_SCP_WRITE_DATA_HIGH,
scp_data >> 16);
if (status < 0)
goto error;
status = snd_hda_codec_read(codec, WIDGET_DSP_CTRL, 0,
VENDOR_DSPIO_STATUS, 0);
error:
mutex_unlock(&spec->chipio_mutex);
return (status == VENDOR_STATUS_DSPIO_SCP_COMMAND_QUEUE_FULL) ?
-EIO : 0;
}
static int dspio_write_multiple(struct hda_codec *codec,
unsigned int *buffer, unsigned int size)
{
int status = 0;
unsigned int count;
if ((buffer == NULL))
return -EINVAL;
count = 0;
while (count < size) {
status = dspio_write(codec, *buffer++);
if (status != 0)
break;
count++;
}
return status;
}
static int dspio_read(struct hda_codec *codec, unsigned int *data)
{
int status;
status = dspio_send(codec, VENDOR_DSPIO_SCP_POST_READ_DATA, 0);
if (status == -EIO)
return status;
status = dspio_send(codec, VENDOR_DSPIO_STATUS, 0);
if (status == -EIO ||
status == VENDOR_STATUS_DSPIO_SCP_RESPONSE_QUEUE_EMPTY)
return -EIO;
*data = snd_hda_codec_read(codec, WIDGET_DSP_CTRL, 0,
VENDOR_DSPIO_SCP_READ_DATA, 0);
return 0;
}
static int dspio_read_multiple(struct hda_codec *codec, unsigned int *buffer,
unsigned int *buf_size, unsigned int size_count)
{
int status = 0;
unsigned int size = *buf_size;
unsigned int count;
unsigned int skip_count;
unsigned int dummy;
if ((buffer == NULL))
return -1;
count = 0;
while (count < size && count < size_count) {
status = dspio_read(codec, buffer++);
if (status != 0)
break;
count++;
}
skip_count = count;
if (status == 0) {
while (skip_count < size) {
status = dspio_read(codec, &dummy);
if (status != 0)
break;
skip_count++;
}
}
*buf_size = count;
return status;
}
static inline unsigned int
make_scp_header(unsigned int target_id, unsigned int source_id,
unsigned int get_flag, unsigned int req,
unsigned int device_flag, unsigned int resp_flag,
unsigned int error_flag, unsigned int data_size)
{
unsigned int header = 0;
header = (data_size & 0x1f) << 27;
header |= (error_flag & 0x01) << 26;
header |= (resp_flag & 0x01) << 25;
header |= (device_flag & 0x01) << 24;
header |= (req & 0x7f) << 17;
header |= (get_flag & 0x01) << 16;
header |= (source_id & 0xff) << 8;
header |= target_id & 0xff;
return header;
}
static inline void
extract_scp_header(unsigned int header,
unsigned int *target_id, unsigned int *source_id,
unsigned int *get_flag, unsigned int *req,
unsigned int *device_flag, unsigned int *resp_flag,
unsigned int *error_flag, unsigned int *data_size)
{
if (data_size)
*data_size = (header >> 27) & 0x1f;
if (error_flag)
*error_flag = (header >> 26) & 0x01;
if (resp_flag)
*resp_flag = (header >> 25) & 0x01;
if (device_flag)
*device_flag = (header >> 24) & 0x01;
if (req)
*req = (header >> 17) & 0x7f;
if (get_flag)
*get_flag = (header >> 16) & 0x01;
if (source_id)
*source_id = (header >> 8) & 0xff;
if (target_id)
*target_id = header & 0xff;
}
static void dspio_clear_response_queue(struct hda_codec *codec)
{
unsigned int dummy = 0;
int status = -1;
do {
status = dspio_read(codec, &dummy);
} while (status == 0);
}
static int dspio_get_response_data(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
unsigned int data = 0;
unsigned int count;
if (dspio_read(codec, &data) < 0)
return -EIO;
if ((data & 0x00ffffff) == spec->wait_scp_header) {
spec->scp_resp_header = data;
spec->scp_resp_count = data >> 27;
count = spec->wait_num_data;
dspio_read_multiple(codec, spec->scp_resp_data,
&spec->scp_resp_count, count);
return 0;
}
return -EIO;
}
static int dspio_send_scp_message(struct hda_codec *codec,
unsigned char *send_buf,
unsigned int send_buf_size,
unsigned char *return_buf,
unsigned int return_buf_size,
unsigned int *bytes_returned)
{
struct ca0132_spec *spec = codec->spec;
int status = -1;
unsigned int scp_send_size = 0;
unsigned int total_size;
bool waiting_for_resp = false;
unsigned int header;
struct scp_msg *ret_msg;
unsigned int resp_src_id, resp_target_id;
unsigned int data_size, src_id, target_id, get_flag, device_flag;
if (bytes_returned)
*bytes_returned = 0;
header = *((unsigned int *)send_buf);
extract_scp_header(header, &target_id, &src_id, &get_flag, NULL,
&device_flag, NULL, NULL, &data_size);
scp_send_size = data_size + 1;
total_size = (scp_send_size * 4);
if (send_buf_size < total_size)
return -EINVAL;
if (get_flag || device_flag) {
if (!return_buf || return_buf_size < 4 || !bytes_returned)
return -EINVAL;
spec->wait_scp_header = *((unsigned int *)send_buf);
resp_target_id = src_id;
resp_src_id = target_id;
spec->wait_scp_header &= 0xffff0000;
spec->wait_scp_header |= (resp_src_id << 8) | (resp_target_id);
spec->wait_num_data = return_buf_size/sizeof(unsigned int) - 1;
spec->wait_scp = 1;
waiting_for_resp = true;
}
status = dspio_write_multiple(codec, (unsigned int *)send_buf,
scp_send_size);
if (status < 0) {
spec->wait_scp = 0;
return status;
}
if (waiting_for_resp) {
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
memset(return_buf, 0, return_buf_size);
do {
msleep(20);
} while (spec->wait_scp && time_before(jiffies, timeout));
waiting_for_resp = false;
if (!spec->wait_scp) {
ret_msg = (struct scp_msg *)return_buf;
memcpy(&ret_msg->hdr, &spec->scp_resp_header, 4);
memcpy(&ret_msg->data, spec->scp_resp_data,
spec->wait_num_data);
*bytes_returned = (spec->scp_resp_count + 1) * 4;
status = 0;
} else {
status = -EIO;
}
spec->wait_scp = 0;
}
return status;
}
static int dspio_scp(struct hda_codec *codec,
int mod_id, int req, int dir, void *data, unsigned int len,
void *reply, unsigned int *reply_len)
{
int status = 0;
struct scp_msg scp_send, scp_reply;
unsigned int ret_bytes, send_size, ret_size;
unsigned int send_get_flag, reply_resp_flag, reply_error_flag;
unsigned int reply_data_size;
memset(&scp_send, 0, sizeof(scp_send));
memset(&scp_reply, 0, sizeof(scp_reply));
if ((len != 0 && data == NULL) || (len > SCP_MAX_DATA_WORDS))
return -EINVAL;
if (dir == SCP_GET && reply == NULL) {
snd_printdd(KERN_ERR "dspio_scp get but has no buffer\n");
return -EINVAL;
}
if (reply != NULL && (reply_len == NULL || (*reply_len == 0))) {
snd_printdd(KERN_ERR "dspio_scp bad resp buf len parms\n");
return -EINVAL;
}
scp_send.hdr = make_scp_header(mod_id, 0x20, (dir == SCP_GET), req,
0, 0, 0, len/sizeof(unsigned int));
if (data != NULL && len > 0) {
len = min((unsigned int)(sizeof(scp_send.data)), len);
memcpy(scp_send.data, data, len);
}
ret_bytes = 0;
send_size = sizeof(unsigned int) + len;
status = dspio_send_scp_message(codec, (unsigned char *)&scp_send,
send_size, (unsigned char *)&scp_reply,
sizeof(scp_reply), &ret_bytes);
if (status < 0) {
snd_printdd(KERN_ERR "dspio_scp: send scp msg failed\n");
return status;
}
extract_scp_header(scp_send.hdr, NULL, NULL, &send_get_flag,
NULL, NULL, NULL, NULL, NULL);
extract_scp_header(scp_reply.hdr, NULL, NULL, NULL, NULL, NULL,
&reply_resp_flag, &reply_error_flag,
&reply_data_size);
if (!send_get_flag)
return 0;
if (reply_resp_flag && !reply_error_flag) {
ret_size = (ret_bytes - sizeof(scp_reply.hdr))
/ sizeof(unsigned int);
if (*reply_len < ret_size*sizeof(unsigned int)) {
snd_printdd(KERN_ERR "reply too long for buf\n");
return -EINVAL;
} else if (ret_size != reply_data_size) {
snd_printdd(KERN_ERR "RetLen and HdrLen .NE.\n");
return -EINVAL;
} else {
*reply_len = ret_size*sizeof(unsigned int);
memcpy(reply, scp_reply.data, *reply_len);
}
} else {
snd_printdd(KERN_ERR "reply ill-formed or errflag set\n");
return -EIO;
}
return status;
}
static int dspio_set_param(struct hda_codec *codec, int mod_id,
int req, void *data, unsigned int len)
{
return dspio_scp(codec, mod_id, req, SCP_SET, data, len, NULL, NULL);
}
static int dspio_set_uint_param(struct hda_codec *codec, int mod_id,
int req, unsigned int data)
{
return dspio_set_param(codec, mod_id, req, &data, sizeof(unsigned int));
}
static int dspio_alloc_dma_chan(struct hda_codec *codec, unsigned int *dma_chan)
{
int status = 0;
unsigned int size = sizeof(dma_chan);
snd_printdd(KERN_INFO " dspio_alloc_dma_chan() -- begin\n");
status = dspio_scp(codec, MASTERCONTROL, MASTERCONTROL_ALLOC_DMA_CHAN,
SCP_GET, NULL, 0, dma_chan, &size);
if (status < 0) {
snd_printdd(KERN_INFO "dspio_alloc_dma_chan: SCP Failed\n");
return status;
}
if ((*dma_chan + 1) == 0) {
snd_printdd(KERN_INFO "no free dma channels to allocate\n");
return -EBUSY;
}
snd_printdd("dspio_alloc_dma_chan: chan=%d\n", *dma_chan);
snd_printdd(KERN_INFO " dspio_alloc_dma_chan() -- complete\n");
return status;
}
static int dspio_free_dma_chan(struct hda_codec *codec, unsigned int dma_chan)
{
int status = 0;
unsigned int dummy = 0;
snd_printdd(KERN_INFO " dspio_free_dma_chan() -- begin\n");
snd_printdd("dspio_free_dma_chan: chan=%d\n", dma_chan);
status = dspio_scp(codec, MASTERCONTROL, MASTERCONTROL_ALLOC_DMA_CHAN,
SCP_SET, &dma_chan, sizeof(dma_chan), NULL, &dummy);
if (status < 0) {
snd_printdd(KERN_INFO "dspio_free_dma_chan: SCP Failed\n");
return status;
}
snd_printdd(KERN_INFO " dspio_free_dma_chan() -- complete\n");
return status;
}
static int dsp_set_run_state(struct hda_codec *codec)
{
unsigned int dbg_ctrl_reg;
unsigned int halt_state;
int err;
err = chipio_read(codec, DSP_DBGCNTL_INST_OFFSET, &dbg_ctrl_reg);
if (err < 0)
return err;
halt_state = (dbg_ctrl_reg & DSP_DBGCNTL_STATE_MASK) >>
DSP_DBGCNTL_STATE_LOBIT;
if (halt_state != 0) {
dbg_ctrl_reg &= ~((halt_state << DSP_DBGCNTL_SS_LOBIT) &
DSP_DBGCNTL_SS_MASK);
err = chipio_write(codec, DSP_DBGCNTL_INST_OFFSET,
dbg_ctrl_reg);
if (err < 0)
return err;
dbg_ctrl_reg |= (halt_state << DSP_DBGCNTL_EXEC_LOBIT) &
DSP_DBGCNTL_EXEC_MASK;
err = chipio_write(codec, DSP_DBGCNTL_INST_OFFSET,
dbg_ctrl_reg);
if (err < 0)
return err;
}
return 0;
}
static int dsp_reset(struct hda_codec *codec)
{
unsigned int res;
int retry = 20;
snd_printdd("dsp_reset\n");
do {
res = dspio_send(codec, VENDOR_DSPIO_DSP_INIT, 0);
retry--;
} while (res == -EIO && retry);
if (!retry) {
snd_printdd("dsp_reset timeout\n");
return -EIO;
}
return 0;
}
static unsigned int dsp_chip_to_dsp_addx(unsigned int chip_addx,
bool *code, bool *yram)
{
*code = *yram = false;
if (UC_RANGE(chip_addx, 1)) {
*code = true;
return UC_OFF(chip_addx);
} else if (X_RANGE_ALL(chip_addx, 1)) {
return X_OFF(chip_addx);
} else if (Y_RANGE_ALL(chip_addx, 1)) {
*yram = true;
return Y_OFF(chip_addx);
}
return INVALID_CHIP_ADDRESS;
}
static bool dsp_is_dma_active(struct hda_codec *codec, unsigned int dma_chan)
{
unsigned int dma_chnlstart_reg;
chipio_read(codec, DSPDMAC_CHNLSTART_INST_OFFSET, &dma_chnlstart_reg);
return ((dma_chnlstart_reg & (1 <<
(DSPDMAC_CHNLSTART_EN_LOBIT + dma_chan))) != 0);
}
static int dsp_dma_setup_common(struct hda_codec *codec,
unsigned int chip_addx,
unsigned int dma_chan,
unsigned int port_map_mask,
bool ovly)
{
int status = 0;
unsigned int chnl_prop;
unsigned int dsp_addx;
unsigned int active;
bool code, yram;
snd_printdd(KERN_INFO "-- dsp_dma_setup_common() -- Begin ---------\n");
if (dma_chan >= DSPDMAC_DMA_CFG_CHANNEL_COUNT) {
snd_printdd(KERN_ERR "dma chan num invalid\n");
return -EINVAL;
}
if (dsp_is_dma_active(codec, dma_chan)) {
snd_printdd(KERN_ERR "dma already active\n");
return -EBUSY;
}
dsp_addx = dsp_chip_to_dsp_addx(chip_addx, &code, &yram);
if (dsp_addx == INVALID_CHIP_ADDRESS) {
snd_printdd(KERN_ERR "invalid chip addr\n");
return -ENXIO;
}
chnl_prop = DSPDMAC_CHNLPROP_AC_MASK;
active = 0;
snd_printdd(KERN_INFO " dsp_dma_setup_common() start reg pgm\n");
if (ovly) {
status = chipio_read(codec, DSPDMAC_CHNLPROP_INST_OFFSET,
&chnl_prop);
if (status < 0) {
snd_printdd(KERN_ERR "read CHNLPROP Reg fail\n");
return status;
}
snd_printdd(KERN_INFO "dsp_dma_setup_common() Read CHNLPROP\n");
}
if (!code)
chnl_prop &= ~(1 << (DSPDMAC_CHNLPROP_MSPCE_LOBIT + dma_chan));
else
chnl_prop |= (1 << (DSPDMAC_CHNLPROP_MSPCE_LOBIT + dma_chan));
chnl_prop &= ~(1 << (DSPDMAC_CHNLPROP_DCON_LOBIT + dma_chan));
status = chipio_write(codec, DSPDMAC_CHNLPROP_INST_OFFSET, chnl_prop);
if (status < 0) {
snd_printdd(KERN_ERR "write CHNLPROP Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup_common() Write CHNLPROP\n");
if (ovly) {
status = chipio_read(codec, DSPDMAC_ACTIVE_INST_OFFSET,
&active);
if (status < 0) {
snd_printdd(KERN_ERR "read ACTIVE Reg fail\n");
return status;
}
snd_printdd(KERN_INFO "dsp_dma_setup_common() Read ACTIVE\n");
}
active &= (~(1 << (DSPDMAC_ACTIVE_AAR_LOBIT + dma_chan))) &
DSPDMAC_ACTIVE_AAR_MASK;
status = chipio_write(codec, DSPDMAC_ACTIVE_INST_OFFSET, active);
if (status < 0) {
snd_printdd(KERN_ERR "write ACTIVE Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup_common() Write ACTIVE\n");
status = chipio_write(codec, DSPDMAC_AUDCHSEL_INST_OFFSET(dma_chan),
port_map_mask);
if (status < 0) {
snd_printdd(KERN_ERR "write AUDCHSEL Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup_common() Write AUDCHSEL\n");
status = chipio_write(codec, DSPDMAC_IRQCNT_INST_OFFSET(dma_chan),
DSPDMAC_IRQCNT_BICNT_MASK | DSPDMAC_IRQCNT_CICNT_MASK);
if (status < 0) {
snd_printdd(KERN_ERR "write IRQCNT Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup_common() Write IRQCNT\n");
snd_printdd(
"ChipA=0x%x,DspA=0x%x,dmaCh=%u, "
"CHSEL=0x%x,CHPROP=0x%x,Active=0x%x\n",
chip_addx, dsp_addx, dma_chan,
port_map_mask, chnl_prop, active);
snd_printdd(KERN_INFO "-- dsp_dma_setup_common() -- Complete ------\n");
return 0;
}
static int dsp_dma_setup(struct hda_codec *codec,
unsigned int chip_addx,
unsigned int count,
unsigned int dma_chan)
{
int status = 0;
bool code, yram;
unsigned int dsp_addx;
unsigned int addr_field;
unsigned int incr_field;
unsigned int base_cnt;
unsigned int cur_cnt;
unsigned int dma_cfg = 0;
unsigned int adr_ofs = 0;
unsigned int xfr_cnt = 0;
const unsigned int max_dma_count = 1 << (DSPDMAC_XFRCNT_BCNT_HIBIT -
DSPDMAC_XFRCNT_BCNT_LOBIT + 1);
snd_printdd(KERN_INFO "-- dsp_dma_setup() -- Begin ---------\n");
if (count > max_dma_count) {
snd_printdd(KERN_ERR "count too big\n");
return -EINVAL;
}
dsp_addx = dsp_chip_to_dsp_addx(chip_addx, &code, &yram);
if (dsp_addx == INVALID_CHIP_ADDRESS) {
snd_printdd(KERN_ERR "invalid chip addr\n");
return -ENXIO;
}
snd_printdd(KERN_INFO " dsp_dma_setup() start reg pgm\n");
addr_field = dsp_addx << DSPDMAC_DMACFG_DBADR_LOBIT;
incr_field = 0;
if (!code) {
addr_field <<= 1;
if (yram)
addr_field |= (1 << DSPDMAC_DMACFG_DBADR_LOBIT);
incr_field = (1 << DSPDMAC_DMACFG_AINCR_LOBIT);
}
dma_cfg = addr_field + incr_field;
status = chipio_write(codec, DSPDMAC_DMACFG_INST_OFFSET(dma_chan),
dma_cfg);
if (status < 0) {
snd_printdd(KERN_ERR "write DMACFG Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup() Write DMACFG\n");
adr_ofs = (count - 1) << (DSPDMAC_DSPADROFS_BOFS_LOBIT +
(code ? 0 : 1));
status = chipio_write(codec, DSPDMAC_DSPADROFS_INST_OFFSET(dma_chan),
adr_ofs);
if (status < 0) {
snd_printdd(KERN_ERR "write DSPADROFS Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup() Write DSPADROFS\n");
base_cnt = (count - 1) << DSPDMAC_XFRCNT_BCNT_LOBIT;
cur_cnt = (count - 1) << DSPDMAC_XFRCNT_CCNT_LOBIT;
xfr_cnt = base_cnt | cur_cnt;
status = chipio_write(codec,
DSPDMAC_XFRCNT_INST_OFFSET(dma_chan), xfr_cnt);
if (status < 0) {
snd_printdd(KERN_ERR "write XFRCNT Reg fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_dma_setup() Write XFRCNT\n");
snd_printdd(
"ChipA=0x%x, cnt=0x%x, DMACFG=0x%x, "
"ADROFS=0x%x, XFRCNT=0x%x\n",
chip_addx, count, dma_cfg, adr_ofs, xfr_cnt);
snd_printdd(KERN_INFO "-- dsp_dma_setup() -- Complete ---------\n");
return 0;
}
static int dsp_dma_start(struct hda_codec *codec,
unsigned int dma_chan, bool ovly)
{
unsigned int reg = 0;
int status = 0;
snd_printdd(KERN_INFO "-- dsp_dma_start() -- Begin ---------\n");
if (ovly) {
status = chipio_read(codec,
DSPDMAC_CHNLSTART_INST_OFFSET, &reg);
if (status < 0) {
snd_printdd(KERN_ERR "read CHNLSTART reg fail\n");
return status;
}
snd_printdd(KERN_INFO "-- dsp_dma_start() Read CHNLSTART\n");
reg &= ~(DSPDMAC_CHNLSTART_EN_MASK |
DSPDMAC_CHNLSTART_DIS_MASK);
}
status = chipio_write(codec, DSPDMAC_CHNLSTART_INST_OFFSET,
reg | (1 << (dma_chan + DSPDMAC_CHNLSTART_EN_LOBIT)));
if (status < 0) {
snd_printdd(KERN_ERR "write CHNLSTART reg fail\n");
return status;
}
snd_printdd(KERN_INFO "-- dsp_dma_start() -- Complete ---------\n");
return status;
}
static int dsp_dma_stop(struct hda_codec *codec,
unsigned int dma_chan, bool ovly)
{
unsigned int reg = 0;
int status = 0;
snd_printdd(KERN_INFO "-- dsp_dma_stop() -- Begin ---------\n");
if (ovly) {
status = chipio_read(codec,
DSPDMAC_CHNLSTART_INST_OFFSET, &reg);
if (status < 0) {
snd_printdd(KERN_ERR "read CHNLSTART reg fail\n");
return status;
}
snd_printdd(KERN_INFO "-- dsp_dma_stop() Read CHNLSTART\n");
reg &= ~(DSPDMAC_CHNLSTART_EN_MASK |
DSPDMAC_CHNLSTART_DIS_MASK);
}
status = chipio_write(codec, DSPDMAC_CHNLSTART_INST_OFFSET,
reg | (1 << (dma_chan + DSPDMAC_CHNLSTART_DIS_LOBIT)));
if (status < 0) {
snd_printdd(KERN_ERR "write CHNLSTART reg fail\n");
return status;
}
snd_printdd(KERN_INFO "-- dsp_dma_stop() -- Complete ---------\n");
return status;
}
static int dsp_allocate_router_ports(struct hda_codec *codec,
unsigned int num_chans,
unsigned int ports_per_channel,
unsigned int start_device,
unsigned int *port_map)
{
int status = 0;
int res;
u8 val;
status = chipio_send(codec, VENDOR_CHIPIO_STATUS, 0);
if (status < 0)
return status;
val = start_device << 6;
val |= (ports_per_channel - 1) << 4;
val |= num_chans - 1;
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PORT_ALLOC_CONFIG_SET,
val);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PORT_ALLOC_SET,
MEM_CONNID_DSP);
status = chipio_send(codec, VENDOR_CHIPIO_STATUS, 0);
if (status < 0)
return status;
res = snd_hda_codec_read(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PORT_ALLOC_GET, 0);
*port_map = res;
return (res < 0) ? res : 0;
}
static int dsp_free_router_ports(struct hda_codec *codec)
{
int status = 0;
status = chipio_send(codec, VENDOR_CHIPIO_STATUS, 0);
if (status < 0)
return status;
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_PORT_FREE_SET,
MEM_CONNID_DSP);
status = chipio_send(codec, VENDOR_CHIPIO_STATUS, 0);
return status;
}
static int dsp_allocate_ports(struct hda_codec *codec,
unsigned int num_chans,
unsigned int rate_multi, unsigned int *port_map)
{
int status;
snd_printdd(KERN_INFO " dsp_allocate_ports() -- begin\n");
if ((rate_multi != 1) && (rate_multi != 2) && (rate_multi != 4)) {
snd_printdd(KERN_ERR "bad rate multiple\n");
return -EINVAL;
}
status = dsp_allocate_router_ports(codec, num_chans,
rate_multi, 0, port_map);
snd_printdd(KERN_INFO " dsp_allocate_ports() -- complete\n");
return status;
}
static int dsp_allocate_ports_format(struct hda_codec *codec,
const unsigned short fmt,
unsigned int *port_map)
{
int status;
unsigned int num_chans;
unsigned int sample_rate_div = ((get_hdafmt_rate(fmt) >> 0) & 3) + 1;
unsigned int sample_rate_mul = ((get_hdafmt_rate(fmt) >> 3) & 3) + 1;
unsigned int rate_multi = sample_rate_mul / sample_rate_div;
if ((rate_multi != 1) && (rate_multi != 2) && (rate_multi != 4)) {
snd_printdd(KERN_ERR "bad rate multiple\n");
return -EINVAL;
}
num_chans = get_hdafmt_chs(fmt) + 1;
status = dsp_allocate_ports(codec, num_chans, rate_multi, port_map);
return status;
}
static int dsp_free_ports(struct hda_codec *codec)
{
int status;
snd_printdd(KERN_INFO " dsp_free_ports() -- begin\n");
status = dsp_free_router_ports(codec);
if (status < 0) {
snd_printdd(KERN_ERR "free router ports fail\n");
return status;
}
snd_printdd(KERN_INFO " dsp_free_ports() -- complete\n");
return status;
}
static int dma_convert_to_hda_format(
unsigned int sample_rate,
unsigned short channels,
unsigned short *hda_format)
{
unsigned int format_val;
format_val = snd_hda_calc_stream_format(
sample_rate,
channels,
SNDRV_PCM_FORMAT_S32_LE,
32, 0);
if (hda_format)
*hda_format = (unsigned short)format_val;
return 0;
}
static int dma_reset(struct dma_engine *dma)
{
struct hda_codec *codec = dma->codec;
struct ca0132_spec *spec = codec->spec;
int status;
if (dma->dmab->area)
snd_hda_codec_load_dsp_cleanup(codec, dma->dmab);
status = snd_hda_codec_load_dsp_prepare(codec,
dma->m_converter_format,
dma->buf_size,
dma->dmab);
if (status < 0)
return status;
spec->dsp_stream_id = status;
return 0;
}
static int dma_set_state(struct dma_engine *dma, enum dma_state state)
{
bool cmd;
snd_printdd("dma_set_state state=%d\n", state);
switch (state) {
case DMA_STATE_STOP:
cmd = false;
break;
case DMA_STATE_RUN:
cmd = true;
break;
default:
return 0;
}
snd_hda_codec_load_dsp_trigger(dma->codec, cmd);
return 0;
}
static unsigned int dma_get_buffer_size(struct dma_engine *dma)
{
return dma->dmab->bytes;
}
static unsigned char *dma_get_buffer_addr(struct dma_engine *dma)
{
return dma->dmab->area;
}
static int dma_xfer(struct dma_engine *dma,
const unsigned int *data,
unsigned int count)
{
memcpy(dma->dmab->area, data, count);
return 0;
}
static void dma_get_converter_format(
struct dma_engine *dma,
unsigned short *format)
{
if (format)
*format = dma->m_converter_format;
}
static unsigned int dma_get_stream_id(struct dma_engine *dma)
{
struct ca0132_spec *spec = dma->codec->spec;
return spec->dsp_stream_id;
}
static bool is_valid(const struct dsp_image_seg *p)
{
return p->magic == g_magic_value;
}
static bool is_hci_prog_list_seg(const struct dsp_image_seg *p)
{
return g_chip_addr_magic_value == p->chip_addr;
}
static bool is_last(const struct dsp_image_seg *p)
{
return p->count == 0;
}
static size_t dsp_sizeof(const struct dsp_image_seg *p)
{
return sizeof(*p) + p->count*sizeof(u32);
}
static const struct dsp_image_seg *get_next_seg_ptr(
const struct dsp_image_seg *p)
{
return (struct dsp_image_seg *)((unsigned char *)(p) + dsp_sizeof(p));
}
static int dspxfr_hci_write(struct hda_codec *codec,
const struct dsp_image_seg *fls)
{
int status;
const u32 *data;
unsigned int count;
if (fls == NULL || fls->chip_addr != g_chip_addr_magic_value) {
snd_printdd(KERN_ERR "hci_write invalid params\n");
return -EINVAL;
}
count = fls->count;
data = (u32 *)(fls->data);
while (count >= 2) {
status = chipio_write(codec, data[0], data[1]);
if (status < 0) {
snd_printdd(KERN_ERR "hci_write chipio failed\n");
return status;
}
count -= 2;
data += 2;
}
return 0;
}
static int dspxfr_one_seg(struct hda_codec *codec,
const struct dsp_image_seg *fls,
unsigned int reloc,
struct dma_engine *dma_engine,
unsigned int dma_chan,
unsigned int port_map_mask,
bool ovly)
{
int status = 0;
bool comm_dma_setup_done = false;
const unsigned int *data;
unsigned int chip_addx;
unsigned int words_to_write;
unsigned int buffer_size_words;
unsigned char *buffer_addx;
unsigned short hda_format;
unsigned int sample_rate_div;
unsigned int sample_rate_mul;
unsigned int num_chans;
unsigned int hda_frame_size_words;
unsigned int remainder_words;
const u32 *data_remainder;
u32 chip_addx_remainder;
unsigned int run_size_words;
const struct dsp_image_seg *hci_write = NULL;
unsigned long timeout;
bool dma_active;
if (fls == NULL)
return -EINVAL;
if (is_hci_prog_list_seg(fls)) {
hci_write = fls;
fls = get_next_seg_ptr(fls);
}
if (hci_write && (!fls || is_last(fls))) {
snd_printdd("hci_write\n");
return dspxfr_hci_write(codec, hci_write);
}
if (fls == NULL || dma_engine == NULL || port_map_mask == 0) {
snd_printdd("Invalid Params\n");
return -EINVAL;
}
data = fls->data;
chip_addx = fls->chip_addr,
words_to_write = fls->count;
if (!words_to_write)
return hci_write ? dspxfr_hci_write(codec, hci_write) : 0;
if (reloc)
chip_addx = (chip_addx & (0xFFFF0000 << 2)) + (reloc << 2);
if (!UC_RANGE(chip_addx, words_to_write) &&
!X_RANGE_ALL(chip_addx, words_to_write) &&
!Y_RANGE_ALL(chip_addx, words_to_write)) {
snd_printdd("Invalid chip_addx Params\n");
return -EINVAL;
}
buffer_size_words = (unsigned int)dma_get_buffer_size(dma_engine) /
sizeof(u32);
buffer_addx = dma_get_buffer_addr(dma_engine);
if (buffer_addx == NULL) {
snd_printdd(KERN_ERR "dma_engine buffer NULL\n");
return -EINVAL;
}
dma_get_converter_format(dma_engine, &hda_format);
sample_rate_div = ((get_hdafmt_rate(hda_format) >> 0) & 3) + 1;
sample_rate_mul = ((get_hdafmt_rate(hda_format) >> 3) & 3) + 1;
num_chans = get_hdafmt_chs(hda_format) + 1;
hda_frame_size_words = ((sample_rate_div == 0) ? 0 :
(num_chans * sample_rate_mul / sample_rate_div));
if (hda_frame_size_words == 0) {
snd_printdd(KERN_ERR "frmsz zero\n");
return -EINVAL;
}
buffer_size_words = min(buffer_size_words,
(unsigned int)(UC_RANGE(chip_addx, 1) ?
65536 : 32768));
buffer_size_words -= buffer_size_words % hda_frame_size_words;
snd_printdd(
"chpadr=0x%08x frmsz=%u nchan=%u "
"rate_mul=%u div=%u bufsz=%u\n",
chip_addx, hda_frame_size_words, num_chans,
sample_rate_mul, sample_rate_div, buffer_size_words);
if (buffer_size_words < hda_frame_size_words) {
snd_printdd(KERN_ERR "dspxfr_one_seg:failed\n");
return -EINVAL;
}
remainder_words = words_to_write % hda_frame_size_words;
data_remainder = data;
chip_addx_remainder = chip_addx;
data += remainder_words;
chip_addx += remainder_words*sizeof(u32);
words_to_write -= remainder_words;
while (words_to_write != 0) {
run_size_words = min(buffer_size_words, words_to_write);
snd_printdd("dspxfr (seg loop)cnt=%u rs=%u remainder=%u\n",
words_to_write, run_size_words, remainder_words);
dma_xfer(dma_engine, data, run_size_words*sizeof(u32));
if (!comm_dma_setup_done) {
status = dsp_dma_stop(codec, dma_chan, ovly);
if (status < 0)
return status;
status = dsp_dma_setup_common(codec, chip_addx,
dma_chan, port_map_mask, ovly);
if (status < 0)
return status;
comm_dma_setup_done = true;
}
status = dsp_dma_setup(codec, chip_addx,
run_size_words, dma_chan);
if (status < 0)
return status;
status = dsp_dma_start(codec, dma_chan, ovly);
if (status < 0)
return status;
if (!dsp_is_dma_active(codec, dma_chan)) {
snd_printdd(KERN_ERR "dspxfr:DMA did not start\n");
return -EIO;
}
status = dma_set_state(dma_engine, DMA_STATE_RUN);
if (status < 0)
return status;
if (remainder_words != 0) {
status = chipio_write_multiple(codec,
chip_addx_remainder,
data_remainder,
remainder_words);
if (status < 0)
return status;
remainder_words = 0;
}
if (hci_write) {
status = dspxfr_hci_write(codec, hci_write);
if (status < 0)
return status;
hci_write = NULL;
}
timeout = jiffies + msecs_to_jiffies(2000);
do {
dma_active = dsp_is_dma_active(codec, dma_chan);
if (!dma_active)
break;
msleep(20);
} while (time_before(jiffies, timeout));
if (dma_active)
break;
snd_printdd(KERN_INFO "+++++ DMA complete\n");
dma_set_state(dma_engine, DMA_STATE_STOP);
status = dma_reset(dma_engine);
if (status < 0)
return status;
data += run_size_words;
chip_addx += run_size_words*sizeof(u32);
words_to_write -= run_size_words;
}
if (remainder_words != 0) {
status = chipio_write_multiple(codec, chip_addx_remainder,
data_remainder, remainder_words);
}
return status;
}
static int dspxfr_image(struct hda_codec *codec,
const struct dsp_image_seg *fls_data,
unsigned int reloc,
unsigned int sample_rate,
unsigned short channels,
bool ovly)
{
struct ca0132_spec *spec = codec->spec;
int status;
unsigned short hda_format = 0;
unsigned int response;
unsigned char stream_id = 0;
struct dma_engine *dma_engine;
unsigned int dma_chan;
unsigned int port_map_mask;
if (fls_data == NULL)
return -EINVAL;
dma_engine = kzalloc(sizeof(*dma_engine), GFP_KERNEL);
if (!dma_engine)
return -ENOMEM;
dma_engine->dmab = kzalloc(sizeof(*dma_engine->dmab), GFP_KERNEL);
if (!dma_engine->dmab) {
kfree(dma_engine);
return -ENOMEM;
}
dma_engine->codec = codec;
dma_convert_to_hda_format(sample_rate, channels, &hda_format);
dma_engine->m_converter_format = hda_format;
dma_engine->buf_size = (ovly ? DSP_DMA_WRITE_BUFLEN_OVLY :
DSP_DMA_WRITE_BUFLEN_INIT) * 2;
dma_chan = ovly ? INVALID_DMA_CHANNEL : 0;
status = codec_set_converter_format(codec, WIDGET_CHIP_CTRL,
hda_format, &response);
if (status < 0) {
snd_printdd(KERN_ERR "set converter format fail\n");
goto exit;
}
status = snd_hda_codec_load_dsp_prepare(codec,
dma_engine->m_converter_format,
dma_engine->buf_size,
dma_engine->dmab);
if (status < 0)
goto exit;
spec->dsp_stream_id = status;
if (ovly) {
status = dspio_alloc_dma_chan(codec, &dma_chan);
if (status < 0) {
snd_printdd(KERN_ERR "alloc dmachan fail\n");
dma_chan = INVALID_DMA_CHANNEL;
goto exit;
}
}
port_map_mask = 0;
status = dsp_allocate_ports_format(codec, hda_format,
&port_map_mask);
if (status < 0) {
snd_printdd(KERN_ERR "alloc ports fail\n");
goto exit;
}
stream_id = dma_get_stream_id(dma_engine);
status = codec_set_converter_stream_channel(codec,
WIDGET_CHIP_CTRL, stream_id, 0, &response);
if (status < 0) {
snd_printdd(KERN_ERR "set stream chan fail\n");
goto exit;
}
while ((fls_data != NULL) && !is_last(fls_data)) {
if (!is_valid(fls_data)) {
snd_printdd(KERN_ERR "FLS check fail\n");
status = -EINVAL;
goto exit;
}
status = dspxfr_one_seg(codec, fls_data, reloc,
dma_engine, dma_chan,
port_map_mask, ovly);
if (status < 0)
break;
if (is_hci_prog_list_seg(fls_data))
fls_data = get_next_seg_ptr(fls_data);
if ((fls_data != NULL) && !is_last(fls_data))
fls_data = get_next_seg_ptr(fls_data);
}
if (port_map_mask != 0)
status = dsp_free_ports(codec);
if (status < 0)
goto exit;
status = codec_set_converter_stream_channel(codec,
WIDGET_CHIP_CTRL, 0, 0, &response);
exit:
if (ovly && (dma_chan != INVALID_DMA_CHANNEL))
dspio_free_dma_chan(codec, dma_chan);
if (dma_engine->dmab->area)
snd_hda_codec_load_dsp_cleanup(codec, dma_engine->dmab);
kfree(dma_engine->dmab);
kfree(dma_engine);
return status;
}
static void dspload_post_setup(struct hda_codec *codec)
{
snd_printdd(KERN_INFO "---- dspload_post_setup ------\n");
chipio_write(codec, XRAM_XRAM_INST_OFFSET(0x18), 0x08080080);
chipio_write(codec, XRAM_XRAM_INST_OFFSET(0x19), 0x3f800000);
chipio_write(codec, XRAM_XRAM_INST_OFFSET(0x29), 0x00000002);
}
static int dspload_image(struct hda_codec *codec,
const struct dsp_image_seg *fls,
bool ovly,
unsigned int reloc,
bool autostart,
int router_chans)
{
int status = 0;
unsigned int sample_rate;
unsigned short channels;
snd_printdd(KERN_INFO "---- dspload_image begin ------\n");
if (router_chans == 0) {
if (!ovly)
router_chans = DMA_TRANSFER_FRAME_SIZE_NWORDS;
else
router_chans = DMA_OVERLAY_FRAME_SIZE_NWORDS;
}
sample_rate = 48000;
channels = (unsigned short)router_chans;
while (channels > 16) {
sample_rate *= 2;
channels /= 2;
}
do {
snd_printdd(KERN_INFO "Ready to program DMA\n");
if (!ovly)
status = dsp_reset(codec);
if (status < 0)
break;
snd_printdd(KERN_INFO "dsp_reset() complete\n");
status = dspxfr_image(codec, fls, reloc, sample_rate, channels,
ovly);
if (status < 0)
break;
snd_printdd(KERN_INFO "dspxfr_image() complete\n");
if (autostart && !ovly) {
dspload_post_setup(codec);
status = dsp_set_run_state(codec);
}
snd_printdd(KERN_INFO "LOAD FINISHED\n");
} while (0);
return status;
}
static bool dspload_is_loaded(struct hda_codec *codec)
{
unsigned int data = 0;
int status = 0;
status = chipio_read(codec, 0x40004, &data);
if ((status < 0) || (data != 1))
return false;
return true;
}
static bool dspload_wait_loaded(struct hda_codec *codec)
{
unsigned long timeout = jiffies + msecs_to_jiffies(2000);
do {
if (dspload_is_loaded(codec)) {
pr_info("ca0132 DOWNLOAD OK :-) DSP IS RUNNING.\n");
return true;
}
msleep(20);
} while (time_before(jiffies, timeout));
pr_err("ca0132 DOWNLOAD FAILED!!! DSP IS NOT RUNNING.\n");
return false;
}
static void ca0132_setup_stream(struct hda_codec *codec, hda_nid_t nid,
u32 stream_tag,
int channel_id, int format)
{
unsigned int oldval, newval;
if (!nid)
return;
snd_printdd(
"ca0132_setup_stream: NID=0x%x, stream=0x%x, "
"channel=%d, format=0x%x\n",
nid, stream_tag, channel_id, format);
oldval = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_STREAM_FORMAT,
0);
if (oldval != format) {
msleep(20);
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_STREAM_FORMAT,
format);
}
oldval = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONV, 0);
newval = (stream_tag << 4) | channel_id;
if (oldval != newval) {
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CHANNEL_STREAMID,
newval);
}
}
static void ca0132_cleanup_stream(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int val;
if (!nid)
return;
snd_printdd(KERN_INFO "ca0132_cleanup_stream: NID=0x%x\n", nid);
val = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONV, 0);
if (!val)
return;
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_STREAM_FORMAT, 0);
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0);
}
static int ca0132_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_setup_stream(codec, spec->dacs[0], stream_tag, 0, format);
return 0;
}
static int ca0132_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
if (spec->dsp_state == DSP_DOWNLOADING)
return 0;
if (spec->effects_switch[PLAY_ENHANCEMENT - EFFECT_START_NID])
msleep(50);
ca0132_cleanup_stream(codec, spec->dacs[0]);
return 0;
}
static unsigned int ca0132_playback_pcm_delay(struct hda_pcm_stream *info,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
unsigned int latency = DSP_PLAYBACK_INIT_LATENCY;
struct snd_pcm_runtime *runtime = substream->runtime;
if (spec->dsp_state != DSP_DOWNLOADED)
return 0;
if (spec->effects_switch[PLAY_ENHANCEMENT - EFFECT_START_NID]) {
if ((spec->effects_switch[SURROUND - EFFECT_START_NID]) ||
(spec->effects_switch[DIALOG_PLUS - EFFECT_START_NID]))
latency += DSP_PLAY_ENHANCEMENT_LATENCY;
}
if (spec->cur_out_type == SPEAKER_OUT)
latency += DSP_SPEAKER_OUT_LATENCY;
return (latency * runtime->rate) / 1000;
}
static int ca0132_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int ca0132_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout,
stream_tag, format, substream);
}
static int ca0132_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
return snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
}
static int ca0132_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int ca0132_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
ca0132_setup_stream(codec, spec->adcs[substream->number],
stream_tag, 0, format);
return 0;
}
static int ca0132_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
if (spec->dsp_state == DSP_DOWNLOADING)
return 0;
ca0132_cleanup_stream(codec, hinfo->nid);
return 0;
}
static unsigned int ca0132_capture_pcm_delay(struct hda_pcm_stream *info,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ca0132_spec *spec = codec->spec;
unsigned int latency = DSP_CAPTURE_INIT_LATENCY;
struct snd_pcm_runtime *runtime = substream->runtime;
if (spec->dsp_state != DSP_DOWNLOADED)
return 0;
if (spec->effects_switch[CRYSTAL_VOICE - EFFECT_START_NID])
latency += DSP_CRYSTAL_VOICE_LATENCY;
return (latency * runtime->rate) / 1000;
}
static int tuning_ctl_set(struct hda_codec *codec, hda_nid_t nid,
unsigned int *lookup, int idx)
{
int i = 0;
for (i = 0; i < TUNING_CTLS_COUNT; i++)
if (nid == ca0132_tuning_ctls[i].nid)
break;
snd_hda_power_up(codec);
dspio_set_param(codec, ca0132_tuning_ctls[i].mid,
ca0132_tuning_ctls[i].req,
&(lookup[idx]), sizeof(unsigned int));
snd_hda_power_down(codec);
return 1;
}
static int tuning_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
long *valp = ucontrol->value.integer.value;
int idx = nid - TUNING_CTL_START_NID;
*valp = spec->cur_ctl_vals[idx];
return 0;
}
static int voice_focus_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int chs = get_amp_channels(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = chs == 3 ? 2 : 1;
uinfo->value.integer.min = 20;
uinfo->value.integer.max = 180;
uinfo->value.integer.step = 1;
return 0;
}
static int voice_focus_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
long *valp = ucontrol->value.integer.value;
int idx;
idx = nid - TUNING_CTL_START_NID;
if (spec->cur_ctl_vals[idx] == *valp)
return 0;
spec->cur_ctl_vals[idx] = *valp;
idx = *valp - 20;
tuning_ctl_set(codec, nid, voice_focus_vals_lookup, idx);
return 1;
}
static int mic_svm_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int chs = get_amp_channels(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = chs == 3 ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 100;
uinfo->value.integer.step = 1;
return 0;
}
static int mic_svm_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
long *valp = ucontrol->value.integer.value;
int idx;
idx = nid - TUNING_CTL_START_NID;
if (spec->cur_ctl_vals[idx] == *valp)
return 0;
spec->cur_ctl_vals[idx] = *valp;
idx = *valp;
tuning_ctl_set(codec, nid, mic_svm_vals_lookup, idx);
return 0;
}
static int equalizer_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int chs = get_amp_channels(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = chs == 3 ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 48;
uinfo->value.integer.step = 1;
return 0;
}
static int equalizer_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
long *valp = ucontrol->value.integer.value;
int idx;
idx = nid - TUNING_CTL_START_NID;
if (spec->cur_ctl_vals[idx] == *valp)
return 0;
spec->cur_ctl_vals[idx] = *valp;
idx = *valp;
tuning_ctl_set(codec, nid, equalizer_vals_lookup, idx);
return 1;
}
static int add_tuning_control(struct hda_codec *codec,
hda_nid_t pnid, hda_nid_t nid,
const char *name, int dir)
{
char namestr[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
int type = dir ? HDA_INPUT : HDA_OUTPUT;
struct snd_kcontrol_new knew =
HDA_CODEC_VOLUME_MONO(namestr, nid, 1, 0, type);
knew.access = SNDRV_CTL_ELEM_ACCESS_READWRITE |
SNDRV_CTL_ELEM_ACCESS_TLV_READ;
knew.tlv.c = 0;
knew.tlv.p = 0;
switch (pnid) {
case VOICE_FOCUS:
knew.info = voice_focus_ctl_info;
knew.get = tuning_ctl_get;
knew.put = voice_focus_ctl_put;
knew.tlv.p = voice_focus_db_scale;
break;
case MIC_SVM:
knew.info = mic_svm_ctl_info;
knew.get = tuning_ctl_get;
knew.put = mic_svm_ctl_put;
break;
case EQUALIZER:
knew.info = equalizer_ctl_info;
knew.get = tuning_ctl_get;
knew.put = equalizer_ctl_put;
knew.tlv.p = eq_db_scale;
break;
default:
return 0;
}
knew.private_value =
HDA_COMPOSE_AMP_VAL(nid, 1, 0, type);
sprintf(namestr, "%s %s Volume", name, dirstr[dir]);
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static int add_tuning_ctls(struct hda_codec *codec)
{
int i;
int err;
for (i = 0; i < TUNING_CTLS_COUNT; i++) {
err = add_tuning_control(codec,
ca0132_tuning_ctls[i].parent_nid,
ca0132_tuning_ctls[i].nid,
ca0132_tuning_ctls[i].name,
ca0132_tuning_ctls[i].direct);
if (err < 0)
return err;
}
return 0;
}
static void ca0132_init_tuning_defaults(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
int i;
spec->cur_ctl_vals[WEDGE_ANGLE - TUNING_CTL_START_NID] = 10;
spec->cur_ctl_vals[SVM_LEVEL - TUNING_CTL_START_NID] = 74;
for (i = 2; i < TUNING_CTLS_COUNT; i++)
spec->cur_ctl_vals[i] = 24;
}
static int ca0132_select_out(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
unsigned int pin_ctl;
int jack_present;
int auto_jack;
unsigned int tmp;
int err;
snd_printdd(KERN_INFO "ca0132_select_out\n");
snd_hda_power_up(codec);
auto_jack = spec->vnode_lswitch[VNID_HP_ASEL - VNODE_START_NID];
if (auto_jack)
jack_present = snd_hda_jack_detect(codec, spec->out_pins[1]);
else
jack_present =
spec->vnode_lswitch[VNID_HP_SEL - VNODE_START_NID];
if (jack_present)
spec->cur_out_type = HEADPHONE_OUT;
else
spec->cur_out_type = SPEAKER_OUT;
if (spec->cur_out_type == SPEAKER_OUT) {
snd_printdd(KERN_INFO "ca0132_select_out speaker\n");
tmp = FLOAT_ONE;
err = dspio_set_uint_param(codec, 0x80, 0x04, tmp);
if (err < 0)
goto exit;
tmp = FLOAT_ONE;
err = dspio_set_uint_param(codec, 0x8f, 0x00, tmp);
if (err < 0)
goto exit;
snd_hda_codec_write(codec, spec->out_pins[1], 0,
VENDOR_CHIPIO_EAPD_SEL_SET, 0x02);
snd_hda_codec_write(codec, spec->out_pins[0], 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x00);
snd_hda_codec_write(codec, spec->out_pins[0], 0,
VENDOR_CHIPIO_EAPD_SEL_SET, 0x00);
snd_hda_codec_write(codec, spec->out_pins[0], 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x02);
pin_ctl = snd_hda_codec_read(codec, spec->out_pins[1], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_set_pin_ctl(codec, spec->out_pins[1],
pin_ctl & ~PIN_HP);
pin_ctl = snd_hda_codec_read(codec, spec->out_pins[0], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_set_pin_ctl(codec, spec->out_pins[0],
pin_ctl | PIN_OUT);
} else {
snd_printdd(KERN_INFO "ca0132_select_out hp\n");
tmp = FLOAT_ZERO;
err = dspio_set_uint_param(codec, 0x80, 0x04, tmp);
if (err < 0)
goto exit;
tmp = FLOAT_ZERO;
err = dspio_set_uint_param(codec, 0x8f, 0x00, tmp);
if (err < 0)
goto exit;
snd_hda_codec_write(codec, spec->out_pins[0], 0,
VENDOR_CHIPIO_EAPD_SEL_SET, 0x00);
snd_hda_codec_write(codec, spec->out_pins[0], 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x00);
snd_hda_codec_write(codec, spec->out_pins[1], 0,
VENDOR_CHIPIO_EAPD_SEL_SET, 0x02);
snd_hda_codec_write(codec, spec->out_pins[0], 0,
AC_VERB_SET_EAPD_BTLENABLE, 0x02);
pin_ctl = snd_hda_codec_read(codec, spec->out_pins[0], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_set_pin_ctl(codec, spec->out_pins[0],
pin_ctl & ~PIN_HP);
pin_ctl = snd_hda_codec_read(codec, spec->out_pins[1], 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
snd_hda_set_pin_ctl(codec, spec->out_pins[1],
pin_ctl | PIN_HP);
}
exit:
snd_hda_power_down(codec);
return err < 0 ? err : 0;
}
static void ca0132_unsol_hp_delayed(struct work_struct *work)
{
struct ca0132_spec *spec = container_of(
to_delayed_work(work), struct ca0132_spec, unsol_hp_work);
ca0132_select_out(spec->codec);
snd_hda_jack_report_sync(spec->codec);
}
static int ca0132_set_vipsource(struct hda_codec *codec, int val)
{
struct ca0132_spec *spec = codec->spec;
unsigned int tmp;
if (spec->dsp_state != DSP_DOWNLOADED)
return 0;
if (!spec->effects_switch[CRYSTAL_VOICE - EFFECT_START_NID] ||
(val == 0)) {
chipio_set_control_param(codec, CONTROL_PARAM_VIP_SOURCE, 0);
chipio_set_conn_rate(codec, MEM_CONNID_MICIN1, SR_96_000);
chipio_set_conn_rate(codec, MEM_CONNID_MICOUT1, SR_96_000);
if (spec->cur_mic_type == DIGITAL_MIC)
tmp = FLOAT_TWO;
else
tmp = FLOAT_ONE;
dspio_set_uint_param(codec, 0x80, 0x00, tmp);
tmp = FLOAT_ZERO;
dspio_set_uint_param(codec, 0x80, 0x05, tmp);
} else {
chipio_set_conn_rate(codec, MEM_CONNID_MICIN1, SR_16_000);
chipio_set_conn_rate(codec, MEM_CONNID_MICOUT1, SR_16_000);
if (spec->cur_mic_type == DIGITAL_MIC)
tmp = FLOAT_TWO;
else
tmp = FLOAT_ONE;
dspio_set_uint_param(codec, 0x80, 0x00, tmp);
tmp = FLOAT_ONE;
dspio_set_uint_param(codec, 0x80, 0x05, tmp);
msleep(20);
chipio_set_control_param(codec, CONTROL_PARAM_VIP_SOURCE, val);
}
return 1;
}
static int ca0132_select_mic(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
int jack_present;
int auto_jack;
snd_printdd(KERN_INFO "ca0132_select_mic\n");
snd_hda_power_up(codec);
auto_jack = spec->vnode_lswitch[VNID_AMIC1_ASEL - VNODE_START_NID];
if (auto_jack)
jack_present = snd_hda_jack_detect(codec, spec->input_pins[0]);
else
jack_present =
spec->vnode_lswitch[VNID_AMIC1_SEL - VNODE_START_NID];
if (jack_present)
spec->cur_mic_type = LINE_MIC_IN;
else
spec->cur_mic_type = DIGITAL_MIC;
if (spec->cur_mic_type == DIGITAL_MIC) {
chipio_set_conn_rate(codec, MEM_CONNID_DMIC, SR_32_000);
ca0132_set_dmic(codec, 1);
ca0132_mic_boost_set(codec, 0);
ca0132_effects_set(codec, VOICE_FOCUS,
spec->effects_switch
[VOICE_FOCUS - EFFECT_START_NID]);
} else {
chipio_set_conn_rate(codec, MEM_CONNID_DMIC, SR_96_000);
ca0132_set_dmic(codec, 0);
ca0132_mic_boost_set(codec, spec->cur_mic_boost);
ca0132_effects_set(codec, VOICE_FOCUS, 0);
}
snd_hda_power_down(codec);
return 0;
}
static bool ca0132_is_vnode_effective(struct hda_codec *codec,
hda_nid_t vnid,
hda_nid_t *shared_nid)
{
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid;
switch (vnid) {
case VNID_SPK:
nid = spec->shared_out_nid;
break;
case VNID_MIC:
nid = spec->shared_mic_nid;
break;
default:
return false;
}
if (shared_nid)
*shared_nid = nid;
return true;
}
static int ca0132_voicefx_set(struct hda_codec *codec, int enable)
{
struct ca0132_spec *spec = codec->spec;
unsigned int tmp;
if (enable) {
tmp = spec->effects_switch[CRYSTAL_VOICE - EFFECT_START_NID] ?
FLOAT_ONE : FLOAT_ZERO;
} else {
tmp = FLOAT_ZERO;
}
dspio_set_uint_param(codec, ca0132_voicefx.mid,
ca0132_voicefx.reqs[0], tmp);
return 1;
}
static int ca0132_effects_set(struct hda_codec *codec, hda_nid_t nid, long val)
{
struct ca0132_spec *spec = codec->spec;
unsigned int on;
int num_fx = OUT_EFFECTS_COUNT + IN_EFFECTS_COUNT;
int err = 0;
int idx = nid - EFFECT_START_NID;
if ((idx < 0) || (idx >= num_fx))
return 0;
if ((nid >= OUT_EFFECT_START_NID) && (nid < OUT_EFFECT_END_NID)) {
if (!spec->effects_switch[PLAY_ENHANCEMENT - EFFECT_START_NID])
val = 0;
}
if ((nid >= IN_EFFECT_START_NID) && (nid < IN_EFFECT_END_NID)) {
if (!spec->effects_switch[CRYSTAL_VOICE - EFFECT_START_NID])
val = 0;
if ((nid == VOICE_FOCUS) && (spec->cur_mic_type != DIGITAL_MIC))
val = 0;
}
snd_printdd(KERN_INFO "ca0132_effect_set: nid=0x%x, val=%ld\n",
nid, val);
on = (val == 0) ? FLOAT_ZERO : FLOAT_ONE;
err = dspio_set_uint_param(codec, ca0132_effects[idx].mid,
ca0132_effects[idx].reqs[0], on);
if (err < 0)
return 0;
return 1;
}
static int ca0132_pe_switch_set(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid;
int i, ret = 0;
snd_printdd(KERN_INFO "ca0132_pe_switch_set: val=%ld\n",
spec->effects_switch[PLAY_ENHANCEMENT - EFFECT_START_NID]);
i = OUT_EFFECT_START_NID - EFFECT_START_NID;
nid = OUT_EFFECT_START_NID;
for (; nid < OUT_EFFECT_END_NID; nid++, i++)
ret |= ca0132_effects_set(codec, nid, spec->effects_switch[i]);
return ret;
}
static int stop_mic1(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
unsigned int oldval = snd_hda_codec_read(codec, spec->adcs[0], 0,
AC_VERB_GET_CONV, 0);
if (oldval != 0)
snd_hda_codec_write(codec, spec->adcs[0], 0,
AC_VERB_SET_CHANNEL_STREAMID,
0);
return oldval;
}
static void resume_mic1(struct hda_codec *codec, unsigned int oldval)
{
struct ca0132_spec *spec = codec->spec;
if (oldval != 0)
snd_hda_codec_write(codec, spec->adcs[0], 0,
AC_VERB_SET_CHANNEL_STREAMID,
oldval);
}
static int ca0132_cvoice_switch_set(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid;
int i, ret = 0;
unsigned int oldval;
snd_printdd(KERN_INFO "ca0132_cvoice_switch_set: val=%ld\n",
spec->effects_switch[CRYSTAL_VOICE - EFFECT_START_NID]);
i = IN_EFFECT_START_NID - EFFECT_START_NID;
nid = IN_EFFECT_START_NID;
for (; nid < IN_EFFECT_END_NID; nid++, i++)
ret |= ca0132_effects_set(codec, nid, spec->effects_switch[i]);
ret |= ca0132_voicefx_set(codec, (spec->voicefx_val ? 1 : 0));
oldval = stop_mic1(codec);
ret |= ca0132_set_vipsource(codec, 1);
resume_mic1(codec, oldval);
return ret;
}
static int ca0132_mic_boost_set(struct hda_codec *codec, long val)
{
struct ca0132_spec *spec = codec->spec;
int ret = 0;
if (val)
ret = snd_hda_codec_amp_update(codec, spec->input_pins[0], 0,
HDA_INPUT, 0, HDA_AMP_VOLMASK, 3);
else
ret = snd_hda_codec_amp_update(codec, spec->input_pins[0], 0,
HDA_INPUT, 0, HDA_AMP_VOLMASK, 0);
return ret;
}
static int ca0132_vnode_switch_set(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = get_amp_nid(kcontrol);
hda_nid_t shared_nid = 0;
bool effective;
int ret = 0;
struct ca0132_spec *spec = codec->spec;
int auto_jack;
if (nid == VNID_HP_SEL) {
auto_jack =
spec->vnode_lswitch[VNID_HP_ASEL - VNODE_START_NID];
if (!auto_jack)
ca0132_select_out(codec);
return 1;
}
if (nid == VNID_AMIC1_SEL) {
auto_jack =
spec->vnode_lswitch[VNID_AMIC1_ASEL - VNODE_START_NID];
if (!auto_jack)
ca0132_select_mic(codec);
return 1;
}
if (nid == VNID_HP_ASEL) {
ca0132_select_out(codec);
return 1;
}
if (nid == VNID_AMIC1_ASEL) {
ca0132_select_mic(codec);
return 1;
}
effective = ca0132_is_vnode_effective(codec, nid, &shared_nid);
if (effective) {
int dir = get_amp_direction(kcontrol);
int ch = get_amp_channels(kcontrol);
unsigned long pval;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(shared_nid, ch,
0, dir);
ret = snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
}
return ret;
}
static int ca0132_voicefx_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int items = sizeof(ca0132_voicefx_presets)
/ sizeof(struct ct_voicefx_preset);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = items;
if (uinfo->value.enumerated.item >= items)
uinfo->value.enumerated.item = items - 1;
strcpy(uinfo->value.enumerated.name,
ca0132_voicefx_presets[uinfo->value.enumerated.item].name);
return 0;
}
static int ca0132_voicefx_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->voicefx_val;
return 0;
}
static int ca0132_voicefx_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
int i, err = 0;
int sel = ucontrol->value.enumerated.item[0];
unsigned int items = sizeof(ca0132_voicefx_presets)
/ sizeof(struct ct_voicefx_preset);
if (sel >= items)
return 0;
snd_printdd(KERN_INFO "ca0132_voicefx_put: sel=%d, preset=%s\n",
sel, ca0132_voicefx_presets[sel].name);
for (i = 0; i < VOICEFX_MAX_PARAM_COUNT; i++) {
err = dspio_set_uint_param(codec, ca0132_voicefx.mid,
ca0132_voicefx.reqs[i],
ca0132_voicefx_presets[sel].vals[i]);
if (err < 0)
break;
}
if (err >= 0) {
spec->voicefx_val = sel;
ca0132_voicefx_set(codec, (sel ? 1 : 0));
}
return 1;
}
static int ca0132_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
int ch = get_amp_channels(kcontrol);
long *valp = ucontrol->value.integer.value;
if ((nid >= VNODE_START_NID) && (nid < VNODE_END_NID)) {
if (ch & 1) {
*valp = spec->vnode_lswitch[nid - VNODE_START_NID];
valp++;
}
if (ch & 2) {
*valp = spec->vnode_rswitch[nid - VNODE_START_NID];
valp++;
}
return 0;
}
if ((nid >= EFFECT_START_NID) && (nid < EFFECT_END_NID)) {
*valp = spec->effects_switch[nid - EFFECT_START_NID];
return 0;
}
if (nid == spec->input_pins[0]) {
*valp = spec->cur_mic_boost;
return 0;
}
return 0;
}
static int ca0132_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
int ch = get_amp_channels(kcontrol);
long *valp = ucontrol->value.integer.value;
int changed = 1;
snd_printdd(KERN_INFO "ca0132_switch_put: nid=0x%x, val=%ld\n",
nid, *valp);
snd_hda_power_up(codec);
if ((nid >= VNODE_START_NID) && (nid < VNODE_END_NID)) {
if (ch & 1) {
spec->vnode_lswitch[nid - VNODE_START_NID] = *valp;
valp++;
}
if (ch & 2) {
spec->vnode_rswitch[nid - VNODE_START_NID] = *valp;
valp++;
}
changed = ca0132_vnode_switch_set(kcontrol, ucontrol);
goto exit;
}
if (nid == PLAY_ENHANCEMENT) {
spec->effects_switch[nid - EFFECT_START_NID] = *valp;
changed = ca0132_pe_switch_set(codec);
goto exit;
}
if (nid == CRYSTAL_VOICE) {
spec->effects_switch[nid - EFFECT_START_NID] = *valp;
changed = ca0132_cvoice_switch_set(codec);
goto exit;
}
if (((nid >= OUT_EFFECT_START_NID) && (nid < OUT_EFFECT_END_NID)) ||
((nid >= IN_EFFECT_START_NID) && (nid < IN_EFFECT_END_NID))) {
spec->effects_switch[nid - EFFECT_START_NID] = *valp;
changed = ca0132_effects_set(codec, nid, *valp);
goto exit;
}
if (nid == spec->input_pins[0]) {
spec->cur_mic_boost = *valp;
if (spec->cur_mic_type != DIGITAL_MIC)
changed = ca0132_mic_boost_set(codec, *valp);
goto exit;
}
exit:
snd_hda_power_down(codec);
return changed;
}
static int ca0132_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
int ch = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
unsigned long pval;
int err;
switch (nid) {
case VNID_SPK:
nid = spec->shared_out_nid;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(nid, ch, 0, dir);
err = snd_hda_mixer_amp_volume_info(kcontrol, uinfo);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
break;
case VNID_MIC:
nid = spec->shared_mic_nid;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(nid, ch, 0, dir);
err = snd_hda_mixer_amp_volume_info(kcontrol, uinfo);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
break;
default:
err = snd_hda_mixer_amp_volume_info(kcontrol, uinfo);
}
return err;
}
static int ca0132_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
int ch = get_amp_channels(kcontrol);
long *valp = ucontrol->value.integer.value;
if (ch & 1) {
*valp = spec->vnode_lvol[nid - VNODE_START_NID];
valp++;
}
if (ch & 2) {
*valp = spec->vnode_rvol[nid - VNODE_START_NID];
valp++;
}
return 0;
}
static int ca0132_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
int ch = get_amp_channels(kcontrol);
long *valp = ucontrol->value.integer.value;
hda_nid_t shared_nid = 0;
bool effective;
int changed = 1;
if (ch & 1) {
spec->vnode_lvol[nid - VNODE_START_NID] = *valp;
valp++;
}
if (ch & 2) {
spec->vnode_rvol[nid - VNODE_START_NID] = *valp;
valp++;
}
effective = ca0132_is_vnode_effective(codec, nid, &shared_nid);
if (effective) {
int dir = get_amp_direction(kcontrol);
unsigned long pval;
snd_hda_power_up(codec);
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(shared_nid, ch,
0, dir);
changed = snd_hda_mixer_amp_volume_put(kcontrol, ucontrol);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
snd_hda_power_down(codec);
}
return changed;
}
static int ca0132_volume_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ca0132_spec *spec = codec->spec;
hda_nid_t nid = get_amp_nid(kcontrol);
int ch = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
unsigned long pval;
int err;
switch (nid) {
case VNID_SPK:
nid = spec->shared_out_nid;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(nid, ch, 0, dir);
err = snd_hda_mixer_amp_tlv(kcontrol, op_flag, size, tlv);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
break;
case VNID_MIC:
nid = spec->shared_mic_nid;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = HDA_COMPOSE_AMP_VAL(nid, ch, 0, dir);
err = snd_hda_mixer_amp_tlv(kcontrol, op_flag, size, tlv);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
break;
default:
err = snd_hda_mixer_amp_tlv(kcontrol, op_flag, size, tlv);
}
return err;
}
static int add_fx_switch(struct hda_codec *codec, hda_nid_t nid,
const char *pfx, int dir)
{
char namestr[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
int type = dir ? HDA_INPUT : HDA_OUTPUT;
struct snd_kcontrol_new knew =
CA0132_CODEC_MUTE_MONO(namestr, nid, 1, type);
sprintf(namestr, "%s %s Switch", pfx, dirstr[dir]);
return snd_hda_ctl_add(codec, nid, snd_ctl_new1(&knew, codec));
}
static int add_voicefx(struct hda_codec *codec)
{
struct snd_kcontrol_new knew =
HDA_CODEC_MUTE_MONO(ca0132_voicefx.name,
VOICEFX, 1, 0, HDA_INPUT);
knew.info = ca0132_voicefx_info;
knew.get = ca0132_voicefx_get;
knew.put = ca0132_voicefx_put;
return snd_hda_ctl_add(codec, VOICEFX, snd_ctl_new1(&knew, codec));
}
static int ca0132_build_controls(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
int i, num_fx;
int err = 0;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
num_fx = OUT_EFFECTS_COUNT + IN_EFFECTS_COUNT;
for (i = 0; i < num_fx; i++) {
err = add_fx_switch(codec, ca0132_effects[i].nid,
ca0132_effects[i].name,
ca0132_effects[i].direct);
if (err < 0)
return err;
}
err = add_fx_switch(codec, PLAY_ENHANCEMENT, "PlayEnhancement", 0);
if (err < 0)
return err;
err = add_fx_switch(codec, CRYSTAL_VOICE, "CrystalVoice", 1);
if (err < 0)
return err;
add_voicefx(codec);
#ifdef ENABLE_TUNING_CONTROLS
add_tuning_ctls(codec);
#endif
err = snd_hda_jack_add_kctls(codec, &spec->autocfg);
if (err < 0)
return err;
if (spec->dig_out) {
err = snd_hda_create_spdif_out_ctls(codec, spec->dig_out,
spec->dig_out);
if (err < 0)
return err;
err = snd_hda_create_spdif_share_sw(codec, &spec->multiout);
if (err < 0)
return err;
}
if (spec->dig_in) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in);
if (err < 0)
return err;
}
return 0;
}
static int ca0132_build_pcms(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->pcm_info = info;
codec->num_pcms = 0;
info->name = "CA0132 Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = ca0132_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dacs[0];
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max =
spec->multiout.max_channels;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ca0132_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = 1;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adcs[0];
codec->num_pcms++;
info++;
info->name = "CA0132 Analog Mic-In2";
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ca0132_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = 1;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adcs[1];
codec->num_pcms++;
info++;
info->name = "CA0132 What U Hear";
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ca0132_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = 1;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adcs[2];
codec->num_pcms++;
if (!spec->dig_out && !spec->dig_in)
return 0;
info++;
info->name = "CA0132 Digital";
info->pcm_type = HDA_PCM_TYPE_SPDIF;
if (spec->dig_out) {
info->stream[SNDRV_PCM_STREAM_PLAYBACK] =
ca0132_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->dig_out;
}
if (spec->dig_in) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] =
ca0132_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in;
}
codec->num_pcms++;
return 0;
}
static void init_output(struct hda_codec *codec, hda_nid_t pin, hda_nid_t dac)
{
if (pin) {
snd_hda_set_pin_ctl(codec, pin, PIN_HP);
if (get_wcaps(codec, pin) & AC_WCAP_OUT_AMP)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_OUT_UNMUTE);
}
if (dac && (get_wcaps(codec, dac) & AC_WCAP_OUT_AMP))
snd_hda_codec_write(codec, dac, 0,
AC_VERB_SET_AMP_GAIN_MUTE, AMP_OUT_ZERO);
}
static void init_input(struct hda_codec *codec, hda_nid_t pin, hda_nid_t adc)
{
if (pin) {
snd_hda_set_pin_ctl(codec, pin, PIN_VREF80);
if (get_wcaps(codec, pin) & AC_WCAP_IN_AMP)
snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
}
if (adc && (get_wcaps(codec, adc) & AC_WCAP_IN_AMP)) {
snd_hda_codec_write(codec, adc, 0, AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
snd_hda_codec_amp_stereo(codec, adc, HDA_INPUT, 0,
HDA_AMP_VOLMASK, 0x5a);
snd_hda_codec_amp_stereo(codec, adc, HDA_INPUT, 0,
HDA_AMP_MUTE, 0);
}
}
static void ca0132_init_unsol(struct hda_codec *codec)
{
snd_hda_jack_detect_enable(codec, UNSOL_TAG_HP, UNSOL_TAG_HP);
snd_hda_jack_detect_enable(codec, UNSOL_TAG_AMIC1, UNSOL_TAG_AMIC1);
}
static void refresh_amp_caps(struct hda_codec *codec, hda_nid_t nid, int dir)
{
unsigned int caps;
caps = snd_hda_param_read(codec, nid, dir == HDA_OUTPUT ?
AC_PAR_AMP_OUT_CAP : AC_PAR_AMP_IN_CAP);
snd_hda_override_amp_caps(codec, nid, dir, caps);
}
static void ca0132_set_dmic(struct hda_codec *codec, int enable)
{
struct ca0132_spec *spec = codec->spec;
unsigned int tmp;
u8 val;
unsigned int oldval;
snd_printdd(KERN_INFO "ca0132_set_dmic: enable=%d\n", enable);
oldval = stop_mic1(codec);
ca0132_set_vipsource(codec, 0);
if (enable) {
tmp = FLOAT_TWO;
dspio_set_uint_param(codec, 0x80, 0x00, tmp);
val = spec->dmic_ctl;
val |= 0x80;
snd_hda_codec_write(codec, spec->input_pins[0], 0,
VENDOR_CHIPIO_DMIC_CTL_SET, val);
if (!(spec->dmic_ctl & 0x20))
chipio_set_control_flag(codec, CONTROL_FLAG_DMIC, 1);
} else {
tmp = FLOAT_ONE;
dspio_set_uint_param(codec, 0x80, 0x00, tmp);
val = spec->dmic_ctl;
val &= 0x5f;
snd_hda_codec_write(codec, spec->input_pins[0], 0,
VENDOR_CHIPIO_DMIC_CTL_SET, val);
if (!(spec->dmic_ctl & 0x20))
chipio_set_control_flag(codec, CONTROL_FLAG_DMIC, 0);
}
ca0132_set_vipsource(codec, 1);
resume_mic1(codec, oldval);
}
static void ca0132_init_dmic(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
u8 val;
val = 0x01;
snd_hda_codec_write(codec, spec->input_pins[0], 0,
VENDOR_CHIPIO_DMIC_MCLK_SET, val);
val = 0x83;
snd_hda_codec_write(codec, spec->input_pins[0], 0,
VENDOR_CHIPIO_DMIC_PIN_SET, val);
val = 0x23;
spec->dmic_ctl = val;
snd_hda_codec_write(codec, spec->input_pins[0], 0,
VENDOR_CHIPIO_DMIC_CTL_SET, val);
}
static void ca0132_init_analog_mic2(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
mutex_lock(&spec->chipio_mutex);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_LOW, 0x20);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_HIGH, 0x19);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_DATA_WRITE, 0x00);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_LOW, 0x2D);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_ADDRESS_HIGH, 0x19);
snd_hda_codec_write(codec, WIDGET_CHIP_CTRL, 0,
VENDOR_CHIPIO_8051_DATA_WRITE, 0x00);
mutex_unlock(&spec->chipio_mutex);
}
static void ca0132_refresh_widget_caps(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
int i;
hda_nid_t nid;
snd_printdd(KERN_INFO "ca0132_refresh_widget_caps.\n");
nid = codec->start_nid;
for (i = 0; i < codec->num_nodes; i++, nid++)
codec->wcaps[i] = snd_hda_param_read(codec, nid,
AC_PAR_AUDIO_WIDGET_CAP);
for (i = 0; i < spec->multiout.num_dacs; i++)
refresh_amp_caps(codec, spec->dacs[i], HDA_OUTPUT);
for (i = 0; i < spec->num_outputs; i++)
refresh_amp_caps(codec, spec->out_pins[i], HDA_OUTPUT);
for (i = 0; i < spec->num_inputs; i++) {
refresh_amp_caps(codec, spec->adcs[i], HDA_INPUT);
refresh_amp_caps(codec, spec->input_pins[i], HDA_INPUT);
}
}
static void ca0132_setup_defaults(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
unsigned int tmp;
int num_fx;
int idx, i;
if (spec->dsp_state != DSP_DOWNLOADED)
return;
num_fx = OUT_EFFECTS_COUNT + IN_EFFECTS_COUNT + 1;
for (idx = 0; idx < num_fx; idx++) {
for (i = 0; i <= ca0132_effects[idx].params; i++) {
dspio_set_uint_param(codec, ca0132_effects[idx].mid,
ca0132_effects[idx].reqs[i],
ca0132_effects[idx].def_vals[i]);
}
}
tmp = FLOAT_ZERO;
dspio_set_uint_param(codec, 0x96, 0x3C, tmp);
dspio_set_uint_param(codec, 0x8f, 0x01, tmp);
tmp = FLOAT_ONE;
dspio_set_uint_param(codec, 0x80, 0x00, tmp);
dspio_set_uint_param(codec, 0x80, 0x01, tmp);
tmp = FLOAT_ONE;
dspio_set_uint_param(codec, 0x80, 0x05, tmp);
tmp = FLOAT_TWO;
dspio_set_uint_param(codec, 0x31, 0x00, tmp);
}
static void ca0132_init_flags(struct hda_codec *codec)
{
chipio_set_control_flag(codec, CONTROL_FLAG_IDLE_ENABLE, 0);
chipio_set_control_flag(codec, CONTROL_FLAG_PORT_A_COMMON_MODE, 0);
chipio_set_control_flag(codec, CONTROL_FLAG_PORT_D_COMMON_MODE, 0);
chipio_set_control_flag(codec, CONTROL_FLAG_PORT_A_10KOHM_LOAD, 0);
chipio_set_control_flag(codec, CONTROL_FLAG_PORT_D_10KOHM_LOAD, 0);
chipio_set_control_flag(codec, CONTROL_FLAG_ADC_C_HIGH_PASS, 1);
}
static void ca0132_init_params(struct hda_codec *codec)
{
chipio_set_control_param(codec, CONTROL_PARAM_PORTA_160OHM_GAIN, 6);
chipio_set_control_param(codec, CONTROL_PARAM_PORTD_160OHM_GAIN, 6);
}
static void ca0132_set_dsp_msr(struct hda_codec *codec, bool is96k)
{
chipio_set_control_flag(codec, CONTROL_FLAG_DSP_96KHZ, is96k);
chipio_set_control_flag(codec, CONTROL_FLAG_DAC_96KHZ, is96k);
chipio_set_control_flag(codec, CONTROL_FLAG_SRC_RATE_96KHZ, is96k);
chipio_set_control_flag(codec, CONTROL_FLAG_SRC_CLOCK_196MHZ, is96k);
chipio_set_control_flag(codec, CONTROL_FLAG_ADC_B_96KHZ, is96k);
chipio_set_control_flag(codec, CONTROL_FLAG_ADC_C_96KHZ, is96k);
chipio_set_conn_rate(codec, MEM_CONNID_MICIN1, SR_96_000);
chipio_set_conn_rate(codec, MEM_CONNID_MICOUT1, SR_96_000);
chipio_set_conn_rate(codec, MEM_CONNID_WUH, SR_48_000);
}
static bool ca0132_download_dsp_images(struct hda_codec *codec)
{
bool dsp_loaded = false;
const struct dsp_image_seg *dsp_os_image;
const struct firmware *fw_entry;
if (request_firmware(&fw_entry, EFX_FILE, codec->bus->card->dev) != 0)
return false;
dsp_os_image = (struct dsp_image_seg *)(fw_entry->data);
if (dspload_image(codec, dsp_os_image, 0, 0, true, 0)) {
pr_err("ca0132 dspload_image failed.\n");
goto exit_download;
}
dsp_loaded = dspload_wait_loaded(codec);
exit_download:
release_firmware(fw_entry);
return dsp_loaded;
}
static void ca0132_download_dsp(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
#ifndef CONFIG_SND_HDA_CODEC_CA0132_DSP
return;
#endif
chipio_enable_clocks(codec);
spec->dsp_state = DSP_DOWNLOADING;
if (!ca0132_download_dsp_images(codec))
spec->dsp_state = DSP_DOWNLOAD_FAILED;
else
spec->dsp_state = DSP_DOWNLOADED;
if (spec->dsp_state == DSP_DOWNLOADED)
ca0132_set_dsp_msr(codec, true);
}
static void ca0132_process_dsp_response(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
snd_printdd(KERN_INFO "ca0132_process_dsp_response\n");
if (spec->wait_scp) {
if (dspio_get_response_data(codec) >= 0)
spec->wait_scp = 0;
}
dspio_clear_response_queue(codec);
}
static void ca0132_unsol_event(struct hda_codec *codec, unsigned int res)
{
struct ca0132_spec *spec = codec->spec;
if (((res >> AC_UNSOL_RES_TAG_SHIFT) & 0x3f) == UNSOL_TAG_DSP) {
ca0132_process_dsp_response(codec);
} else {
res = snd_hda_jack_get_action(codec,
(res >> AC_UNSOL_RES_TAG_SHIFT) & 0x3f);
snd_printdd(KERN_INFO "snd_hda_jack_get_action: 0x%x\n", res);
switch (res) {
case UNSOL_TAG_HP:
cancel_delayed_work_sync(&spec->unsol_hp_work);
queue_delayed_work(codec->bus->workq,
&spec->unsol_hp_work,
msecs_to_jiffies(500));
break;
case UNSOL_TAG_AMIC1:
ca0132_select_mic(codec);
snd_hda_jack_report_sync(codec);
break;
default:
break;
}
}
}
static void ca0132_init_chip(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
int num_fx;
int i;
unsigned int on;
mutex_init(&spec->chipio_mutex);
spec->cur_out_type = SPEAKER_OUT;
spec->cur_mic_type = DIGITAL_MIC;
spec->cur_mic_boost = 0;
for (i = 0; i < VNODES_COUNT; i++) {
spec->vnode_lvol[i] = 0x5a;
spec->vnode_rvol[i] = 0x5a;
spec->vnode_lswitch[i] = 0;
spec->vnode_rswitch[i] = 0;
}
num_fx = OUT_EFFECTS_COUNT + IN_EFFECTS_COUNT;
for (i = 0; i < num_fx; i++) {
on = (unsigned int)ca0132_effects[i].reqs[0];
spec->effects_switch[i] = on ? 1 : 0;
}
spec->voicefx_val = 0;
spec->effects_switch[PLAY_ENHANCEMENT - EFFECT_START_NID] = 1;
spec->effects_switch[CRYSTAL_VOICE - EFFECT_START_NID] = 0;
#ifdef ENABLE_TUNING_CONTROLS
ca0132_init_tuning_defaults(codec);
#endif
}
static void ca0132_exit_chip(struct hda_codec *codec)
{
if (dspload_is_loaded(codec))
dsp_reset(codec);
}
static int ca0132_init(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
int i;
spec->dsp_state = DSP_DOWNLOAD_INIT;
spec->curr_chip_addx = INVALID_CHIP_ADDRESS;
snd_hda_power_up(codec);
ca0132_init_params(codec);
ca0132_init_flags(codec);
snd_hda_sequence_write(codec, spec->base_init_verbs);
ca0132_download_dsp(codec);
ca0132_refresh_widget_caps(codec);
ca0132_setup_defaults(codec);
ca0132_init_analog_mic2(codec);
ca0132_init_dmic(codec);
for (i = 0; i < spec->num_outputs; i++)
init_output(codec, spec->out_pins[i], spec->dacs[0]);
init_output(codec, cfg->dig_out_pins[0], spec->dig_out);
for (i = 0; i < spec->num_inputs; i++)
init_input(codec, spec->input_pins[i], spec->adcs[i]);
init_input(codec, cfg->dig_in_pin, spec->dig_in);
for (i = 0; i < spec->num_init_verbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
ca0132_init_unsol(codec);
ca0132_select_out(codec);
ca0132_select_mic(codec);
snd_hda_jack_report_sync(codec);
snd_hda_power_down(codec);
return 0;
}
static void ca0132_free(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
cancel_delayed_work_sync(&spec->unsol_hp_work);
snd_hda_power_up(codec);
snd_hda_sequence_write(codec, spec->base_exit_verbs);
ca0132_exit_chip(codec);
snd_hda_power_down(codec);
kfree(codec->spec);
}
static void ca0132_config(struct hda_codec *codec)
{
struct ca0132_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->autocfg;
spec->dacs[0] = 0x2;
spec->dacs[1] = 0x3;
spec->dacs[2] = 0x4;
spec->multiout.dac_nids = spec->dacs;
spec->multiout.num_dacs = 3;
spec->multiout.max_channels = 2;
spec->num_outputs = 2;
spec->out_pins[0] = 0x0b;
spec->out_pins[1] = 0x10;
spec->shared_out_nid = 0x2;
spec->num_inputs = 3;
spec->adcs[0] = 0x7;
spec->adcs[1] = 0x8;
spec->adcs[2] = 0xa;
spec->shared_mic_nid = 0x7;
spec->input_pins[0] = 0x12;
spec->input_pins[1] = 0x11;
spec->input_pins[2] = 0x13;
spec->dig_out = 0x05;
spec->multiout.dig_out_nid = spec->dig_out;
cfg->dig_out_pins[0] = 0x0c;
cfg->dig_outs = 1;
cfg->dig_out_type[0] = HDA_PCM_TYPE_SPDIF;
spec->dig_in = 0x09;
cfg->dig_in_pin = 0x0e;
cfg->dig_in_type = HDA_PCM_TYPE_SPDIF;
}
static int patch_ca0132(struct hda_codec *codec)
{
struct ca0132_spec *spec;
int err;
snd_printdd("patch_ca0132\n");
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
spec->codec = codec;
spec->num_mixers = 1;
spec->mixers[0] = ca0132_mixer;
spec->base_init_verbs = ca0132_base_init_verbs;
spec->base_exit_verbs = ca0132_base_exit_verbs;
spec->init_verbs[0] = ca0132_init_verbs0;
spec->init_verbs[1] = ca0132_init_verbs1;
spec->num_init_verbs = 2;
INIT_DELAYED_WORK(&spec->unsol_hp_work, ca0132_unsol_hp_delayed);
ca0132_init_chip(codec);
ca0132_config(codec);
err = snd_hda_parse_pin_def_config(codec, &spec->autocfg, NULL);
if (err < 0)
return err;
codec->patch_ops = ca0132_patch_ops;
return 0;
}
static int __init patch_ca0132_init(void)
{
return snd_hda_add_codec_preset(&ca0132_list);
}
static void __exit patch_ca0132_exit(void)
{
snd_hda_delete_codec_preset(&ca0132_list);
}
