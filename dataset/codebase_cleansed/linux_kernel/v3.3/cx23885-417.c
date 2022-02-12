void cx23885_mc417_init(struct cx23885_dev *dev)
{
u32 regval;
dprintk(2, "%s()\n", __func__);
regval = MC417_SPD_CTL(MC417_SPD_CTL_FAST) |
MC417_GPIO_SEL(MC417_GPIO_SEL_GPIO3) |
MC417_UART_GPIO_EN;
cx_write(MC417_CTL, regval);
regval = MC417_MIRDY;
cx_write(MC417_OEN, regval);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS;
cx_write(MC417_RWD, regval);
}
static int mc417_wait_ready(struct cx23885_dev *dev)
{
u32 mi_ready;
unsigned long timeout = jiffies + msecs_to_jiffies(1);
for (;;) {
mi_ready = cx_read(MC417_RWD) & MC417_MIRDY;
if (mi_ready != 0)
return 0;
if (time_after(jiffies, timeout))
return -1;
udelay(1);
}
}
int mc417_register_write(struct cx23885_dev *dev, u16 address, u32 value)
{
u32 regval;
cx_write(MC417_OEN, MC417_MIRDY);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE0 |
(value & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE1 |
((value >> 8) & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE2 |
((value >> 16) & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE3 |
((value >> 24) & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_ADDRESS_BYTE0 |
(address & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_ADDRESS_BYTE1 |
((address >> 8) & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_MODE |
MCI_MODE_REGISTER_WRITE;
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
return mc417_wait_ready(dev);
}
int mc417_register_read(struct cx23885_dev *dev, u16 address, u32 *value)
{
int retval;
u32 regval;
u32 tempval;
u32 dataval;
cx_write(MC417_OEN, MC417_MIRDY);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_ADDRESS_BYTE0 |
((address & 0x00FF));
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_ADDRESS_BYTE1 |
((address >> 8) & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_MODE |
MCI_MODE_REGISTER_READ;
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
retval = mc417_wait_ready(dev);
cx_write(MC417_OEN, MC417_MIRDY | MC417_MIDATA);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE0;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_REGISTER_DATA_BYTE0;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval = tempval & 0x000000FF;
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE1;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_REGISTER_DATA_BYTE1;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval |= ((tempval & 0x000000FF) << 8);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE2;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_REGISTER_DATA_BYTE2;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval |= ((tempval & 0x000000FF) << 16);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_REGISTER_DATA_BYTE3;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_REGISTER_DATA_BYTE3;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval |= ((tempval & 0x000000FF) << 24);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
*value = dataval;
return retval;
}
int mc417_memory_write(struct cx23885_dev *dev, u32 address, u32 value)
{
u32 regval;
cx_write(MC417_OEN, MC417_MIRDY);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE0 |
(value & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE1 |
((value >> 8) & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE2 |
((value >> 16) & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE3 |
((value >> 24) & 0x000000FF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_ADDRESS_BYTE2 |
MCI_MODE_MEMORY_WRITE | ((address >> 16) & 0x3F);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_ADDRESS_BYTE1 |
((address >> 8) & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_ADDRESS_BYTE0 |
(address & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
return mc417_wait_ready(dev);
}
int mc417_memory_read(struct cx23885_dev *dev, u32 address, u32 *value)
{
int retval;
u32 regval;
u32 tempval;
u32 dataval;
cx_write(MC417_OEN, MC417_MIRDY);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_ADDRESS_BYTE2 |
MCI_MODE_MEMORY_READ | ((address >> 16) & 0x3F);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_ADDRESS_BYTE1 |
((address >> 8) & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_ADDRESS_BYTE0 |
(address & 0xFF);
cx_write(MC417_RWD, regval);
regval |= MC417_MICS | MC417_MIWR;
cx_write(MC417_RWD, regval);
retval = mc417_wait_ready(dev);
cx_write(MC417_OEN, MC417_MIRDY | MC417_MIDATA);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE3;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_MEMORY_DATA_BYTE3;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval = ((tempval & 0x000000FF) << 24);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE2;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_MEMORY_DATA_BYTE2;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval |= ((tempval & 0x000000FF) << 16);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE1;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_MEMORY_DATA_BYTE1;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval |= ((tempval & 0x000000FF) << 8);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
regval = MC417_MIRD | MC417_MIRDY | MCI_MEMORY_DATA_BYTE0;
cx_write(MC417_RWD, regval);
regval = MC417_MIWR | MC417_MIRDY | MCI_MEMORY_DATA_BYTE0;
cx_write(MC417_RWD, regval);
tempval = cx_read(MC417_RWD);
dataval |= (tempval & 0x000000FF);
regval = MC417_MIWR | MC417_MIRD | MC417_MICS | MC417_MIRDY;
cx_write(MC417_RWD, regval);
*value = dataval;
return retval;
}
void mc417_gpio_set(struct cx23885_dev *dev, u32 mask)
{
u32 val;
mc417_register_read(dev, 0x900C, &val);
val |= (mask & 0x000ffff);
mc417_register_write(dev, 0x900C, val);
}
void mc417_gpio_clear(struct cx23885_dev *dev, u32 mask)
{
u32 val;
mc417_register_read(dev, 0x900C, &val);
val &= ~(mask & 0x0000ffff);
mc417_register_write(dev, 0x900C, val);
}
void mc417_gpio_enable(struct cx23885_dev *dev, u32 mask, int asoutput)
{
u32 val;
mc417_register_read(dev, 0x9020, &val);
if (asoutput)
val |= (mask & 0x0000ffff);
else
val &= ~(mask & 0x0000ffff);
mc417_register_write(dev, 0x9020, val);
}
static char *cmd_to_str(int cmd)
{
switch (cmd) {
case CX2341X_ENC_PING_FW:
return "PING_FW";
case CX2341X_ENC_START_CAPTURE:
return "START_CAPTURE";
case CX2341X_ENC_STOP_CAPTURE:
return "STOP_CAPTURE";
case CX2341X_ENC_SET_AUDIO_ID:
return "SET_AUDIO_ID";
case CX2341X_ENC_SET_VIDEO_ID:
return "SET_VIDEO_ID";
case CX2341X_ENC_SET_PCR_ID:
return "SET_PCR_ID";
case CX2341X_ENC_SET_FRAME_RATE:
return "SET_FRAME_RATE";
case CX2341X_ENC_SET_FRAME_SIZE:
return "SET_FRAME_SIZE";
case CX2341X_ENC_SET_BIT_RATE:
return "SET_BIT_RATE";
case CX2341X_ENC_SET_GOP_PROPERTIES:
return "SET_GOP_PROPERTIES";
case CX2341X_ENC_SET_ASPECT_RATIO:
return "SET_ASPECT_RATIO";
case CX2341X_ENC_SET_DNR_FILTER_MODE:
return "SET_DNR_FILTER_MODE";
case CX2341X_ENC_SET_DNR_FILTER_PROPS:
return "SET_DNR_FILTER_PROPS";
case CX2341X_ENC_SET_CORING_LEVELS:
return "SET_CORING_LEVELS";
case CX2341X_ENC_SET_SPATIAL_FILTER_TYPE:
return "SET_SPATIAL_FILTER_TYPE";
case CX2341X_ENC_SET_VBI_LINE:
return "SET_VBI_LINE";
case CX2341X_ENC_SET_STREAM_TYPE:
return "SET_STREAM_TYPE";
case CX2341X_ENC_SET_OUTPUT_PORT:
return "SET_OUTPUT_PORT";
case CX2341X_ENC_SET_AUDIO_PROPERTIES:
return "SET_AUDIO_PROPERTIES";
case CX2341X_ENC_HALT_FW:
return "HALT_FW";
case CX2341X_ENC_GET_VERSION:
return "GET_VERSION";
case CX2341X_ENC_SET_GOP_CLOSURE:
return "SET_GOP_CLOSURE";
case CX2341X_ENC_GET_SEQ_END:
return "GET_SEQ_END";
case CX2341X_ENC_SET_PGM_INDEX_INFO:
return "SET_PGM_INDEX_INFO";
case CX2341X_ENC_SET_VBI_CONFIG:
return "SET_VBI_CONFIG";
case CX2341X_ENC_SET_DMA_BLOCK_SIZE:
return "SET_DMA_BLOCK_SIZE";
case CX2341X_ENC_GET_PREV_DMA_INFO_MB_10:
return "GET_PREV_DMA_INFO_MB_10";
case CX2341X_ENC_GET_PREV_DMA_INFO_MB_9:
return "GET_PREV_DMA_INFO_MB_9";
case CX2341X_ENC_SCHED_DMA_TO_HOST:
return "SCHED_DMA_TO_HOST";
case CX2341X_ENC_INITIALIZE_INPUT:
return "INITIALIZE_INPUT";
case CX2341X_ENC_SET_FRAME_DROP_RATE:
return "SET_FRAME_DROP_RATE";
case CX2341X_ENC_PAUSE_ENCODER:
return "PAUSE_ENCODER";
case CX2341X_ENC_REFRESH_INPUT:
return "REFRESH_INPUT";
case CX2341X_ENC_SET_COPYRIGHT:
return "SET_COPYRIGHT";
case CX2341X_ENC_SET_EVENT_NOTIFICATION:
return "SET_EVENT_NOTIFICATION";
case CX2341X_ENC_SET_NUM_VSYNC_LINES:
return "SET_NUM_VSYNC_LINES";
case CX2341X_ENC_SET_PLACEHOLDER:
return "SET_PLACEHOLDER";
case CX2341X_ENC_MUTE_VIDEO:
return "MUTE_VIDEO";
case CX2341X_ENC_MUTE_AUDIO:
return "MUTE_AUDIO";
case CX2341X_ENC_MISC:
return "MISC";
default:
return "UNKNOWN";
}
}
static int cx23885_mbox_func(void *priv,
u32 command,
int in,
int out,
u32 data[CX2341X_MBOX_MAX_DATA])
{
struct cx23885_dev *dev = priv;
unsigned long timeout;
u32 value, flag, retval = 0;
int i;
dprintk(3, "%s: command(0x%X) = %s\n", __func__, command,
cmd_to_str(command));
mc417_memory_read(dev, dev->cx23417_mailbox - 4, &value);
if (value != 0x12345678) {
printk(KERN_ERR
"Firmware and/or mailbox pointer not initialized "
"or corrupted, signature = 0x%x, cmd = %s\n", value,
cmd_to_str(command));
return -1;
}
mc417_memory_read(dev, dev->cx23417_mailbox, &flag);
if (flag) {
printk(KERN_ERR "ERROR: Mailbox appears to be in use "
"(%x), cmd = %s\n", flag, cmd_to_str(command));
return -1;
}
flag |= 1;
mc417_memory_write(dev, dev->cx23417_mailbox, flag);
mc417_memory_write(dev, dev->cx23417_mailbox + 1, command);
mc417_memory_write(dev, dev->cx23417_mailbox + 3,
IVTV_API_STD_TIMEOUT);
for (i = 0; i < in; i++) {
mc417_memory_write(dev, dev->cx23417_mailbox + 4 + i, data[i]);
dprintk(3, "API Input %d = %d\n", i, data[i]);
}
for (; i < CX2341X_MBOX_MAX_DATA; i++)
mc417_memory_write(dev, dev->cx23417_mailbox + 4 + i, 0);
flag |= 3;
mc417_memory_write(dev, dev->cx23417_mailbox, flag);
timeout = jiffies + msecs_to_jiffies(10);
for (;;) {
mc417_memory_read(dev, dev->cx23417_mailbox, &flag);
if (0 != (flag & 4))
break;
if (time_after(jiffies, timeout)) {
printk(KERN_ERR "ERROR: API Mailbox timeout\n");
return -1;
}
udelay(10);
}
for (i = 0; i < out; i++) {
mc417_memory_read(dev, dev->cx23417_mailbox + 4 + i, data + i);
dprintk(3, "API Output %d = %d\n", i, data[i]);
}
mc417_memory_read(dev, dev->cx23417_mailbox + 2, &retval);
dprintk(3, "API result = %d\n", retval);
flag = 0;
mc417_memory_write(dev, dev->cx23417_mailbox, flag);
return retval;
}
static int cx23885_api_cmd(struct cx23885_dev *dev,
u32 command,
u32 inputcnt,
u32 outputcnt,
...)
{
u32 data[CX2341X_MBOX_MAX_DATA];
va_list vargs;
int i, err;
dprintk(3, "%s() cmds = 0x%08x\n", __func__, command);
va_start(vargs, outputcnt);
for (i = 0; i < inputcnt; i++)
data[i] = va_arg(vargs, int);
err = cx23885_mbox_func(dev, command, inputcnt, outputcnt, data);
for (i = 0; i < outputcnt; i++) {
int *vptr = va_arg(vargs, int *);
*vptr = data[i];
}
va_end(vargs);
return err;
}
static int cx23885_find_mailbox(struct cx23885_dev *dev)
{
u32 signature[4] = {
0x12345678, 0x34567812, 0x56781234, 0x78123456
};
int signaturecnt = 0;
u32 value;
int i;
dprintk(2, "%s()\n", __func__);
for (i = 0; i < CX23885_FIRM_IMAGE_SIZE; i++) {
mc417_memory_read(dev, i, &value);
if (value == signature[signaturecnt])
signaturecnt++;
else
signaturecnt = 0;
if (4 == signaturecnt) {
dprintk(1, "Mailbox signature found at 0x%x\n", i+1);
return i+1;
}
}
printk(KERN_ERR "Mailbox signature values not found!\n");
return -1;
}
static int cx23885_load_firmware(struct cx23885_dev *dev)
{
static const unsigned char magic[8] = {
0xa7, 0x0d, 0x00, 0x00, 0x66, 0xbb, 0x55, 0xaa
};
const struct firmware *firmware;
int i, retval = 0;
u32 value = 0;
u32 gpio_output = 0;
u32 gpio_value;
u32 checksum = 0;
u32 *dataptr;
dprintk(2, "%s()\n", __func__);
retval |= mc417_memory_read(dev, 0x9020, &gpio_output);
retval |= mc417_memory_read(dev, 0x900C, &gpio_value);
retval = mc417_register_write(dev,
IVTV_REG_VPU, 0xFFFFFFED);
retval |= mc417_register_write(dev,
IVTV_REG_HW_BLOCKS, IVTV_CMD_HW_BLOCKS_RST);
retval |= mc417_register_write(dev,
IVTV_REG_ENC_SDRAM_REFRESH, 0x80000800);
retval |= mc417_register_write(dev,
IVTV_REG_ENC_SDRAM_PRECHARGE, 0x1A);
retval |= mc417_register_write(dev,
IVTV_REG_APU, 0);
if (retval != 0) {
printk(KERN_ERR "%s: Error with mc417_register_write\n",
__func__);
return -1;
}
retval = request_firmware(&firmware, CX23885_FIRM_IMAGE_NAME,
&dev->pci->dev);
if (retval != 0) {
printk(KERN_ERR
"ERROR: Hotplug firmware request failed (%s).\n",
CX23885_FIRM_IMAGE_NAME);
printk(KERN_ERR "Please fix your hotplug setup, the board will "
"not work without firmware loaded!\n");
return -1;
}
if (firmware->size != CX23885_FIRM_IMAGE_SIZE) {
printk(KERN_ERR "ERROR: Firmware size mismatch "
"(have %zd, expected %d)\n",
firmware->size, CX23885_FIRM_IMAGE_SIZE);
release_firmware(firmware);
return -1;
}
if (0 != memcmp(firmware->data, magic, 8)) {
printk(KERN_ERR
"ERROR: Firmware magic mismatch, wrong file?\n");
release_firmware(firmware);
return -1;
}
dprintk(2, "Loading firmware ...\n");
dataptr = (u32 *)firmware->data;
for (i = 0; i < (firmware->size >> 2); i++) {
value = *dataptr;
checksum += ~value;
if (mc417_memory_write(dev, i, value) != 0) {
printk(KERN_ERR "ERROR: Loading firmware failed!\n");
release_firmware(firmware);
return -1;
}
dataptr++;
}
dprintk(1, "Verifying firmware ...\n");
for (i--; i >= 0; i--) {
if (mc417_memory_read(dev, i, &value) != 0) {
printk(KERN_ERR "ERROR: Reading firmware failed!\n");
release_firmware(firmware);
return -1;
}
checksum -= ~value;
}
if (checksum) {
printk(KERN_ERR
"ERROR: Firmware load failed (checksum mismatch).\n");
release_firmware(firmware);
return -1;
}
release_firmware(firmware);
dprintk(1, "Firmware upload successful.\n");
retval |= mc417_register_write(dev, IVTV_REG_HW_BLOCKS,
IVTV_CMD_HW_BLOCKS_RST);
retval |= mc417_register_write(dev, 0x9020, gpio_output);
retval |= mc417_register_write(dev, 0x900C, gpio_value);
retval |= mc417_register_read(dev, IVTV_REG_VPU, &value);
retval |= mc417_register_write(dev, IVTV_REG_VPU, value & 0xFFFFFFE8);
retval |= mc417_register_write(dev, 0x9020, 0x4000);
retval |= mc417_register_write(dev, 0x900C, 0x4000);
mc417_register_read(dev, 0x9020, &gpio_output);
mc417_register_read(dev, 0x900C, &gpio_value);
if (retval < 0)
printk(KERN_ERR "%s: Error with mc417_register_write\n",
__func__);
return 0;
}
void cx23885_417_check_encoder(struct cx23885_dev *dev)
{
u32 status, seq;
status = seq = 0;
cx23885_api_cmd(dev, CX2341X_ENC_GET_SEQ_END, 0, 2, &status, &seq);
dprintk(1, "%s() status = %d, seq = %d\n", __func__, status, seq);
}
static void cx23885_codec_settings(struct cx23885_dev *dev)
{
dprintk(1, "%s()\n", __func__);
if (dev->encodernorm.id & V4L2_STD_525_60)
dev->ts1.height = 480;
else
dev->ts1.height = 576;
cx23885_api_cmd(dev, CX2341X_ENC_SET_FRAME_SIZE, 2, 0,
dev->ts1.height, dev->ts1.width);
dev->mpeg_params.width = dev->ts1.width;
dev->mpeg_params.height = dev->ts1.height;
dev->mpeg_params.is_50hz =
(dev->encodernorm.id & V4L2_STD_625_50) != 0;
cx2341x_update(dev, cx23885_mbox_func, NULL, &dev->mpeg_params);
cx23885_api_cmd(dev, CX2341X_ENC_MISC, 2, 0, 3, 1);
cx23885_api_cmd(dev, CX2341X_ENC_MISC, 2, 0, 4, 1);
}
static int cx23885_initialize_codec(struct cx23885_dev *dev, int startencoder)
{
int version;
int retval;
u32 i, data[7];
dprintk(1, "%s()\n", __func__);
retval = cx23885_api_cmd(dev, CX2341X_ENC_PING_FW, 0, 0);
if (retval < 0) {
dprintk(2, "%s() PING OK\n", __func__);
retval = cx23885_load_firmware(dev);
if (retval < 0) {
printk(KERN_ERR "%s() f/w load failed\n", __func__);
return retval;
}
retval = cx23885_find_mailbox(dev);
if (retval < 0) {
printk(KERN_ERR "%s() mailbox < 0, error\n",
__func__);
return -1;
}
dev->cx23417_mailbox = retval;
retval = cx23885_api_cmd(dev, CX2341X_ENC_PING_FW, 0, 0);
if (retval < 0) {
printk(KERN_ERR
"ERROR: cx23417 firmware ping failed!\n");
return -1;
}
retval = cx23885_api_cmd(dev, CX2341X_ENC_GET_VERSION, 0, 1,
&version);
if (retval < 0) {
printk(KERN_ERR "ERROR: cx23417 firmware get encoder :"
"version failed!\n");
return -1;
}
dprintk(1, "cx23417 firmware version is 0x%08x\n", version);
msleep(200);
}
cx23885_codec_settings(dev);
msleep(60);
cx23885_api_cmd(dev, CX2341X_ENC_SET_NUM_VSYNC_LINES, 2, 0,
CX23885_FIELD1_SAA7115, CX23885_FIELD2_SAA7115);
cx23885_api_cmd(dev, CX2341X_ENC_SET_PLACEHOLDER, 12, 0,
CX23885_CUSTOM_EXTENSION_USR_DATA, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0);
data[0] = 0x0001BD00;
data[1] = 1;
data[2] = 4;
data[3] = 0x91559155;
data[4] = 0x206080C0;
data[5] = 6;
data[6] = 64;
cx23885_api_cmd(dev, CX2341X_ENC_SET_VBI_CONFIG, 7, 0, data[0], data[1],
data[2], data[3], data[4], data[5], data[6]);
for (i = 2; i <= 24; i++) {
int valid;
valid = ((i >= 19) && (i <= 21));
cx23885_api_cmd(dev, CX2341X_ENC_SET_VBI_LINE, 5, 0, i,
valid, 0 , 0, 0);
cx23885_api_cmd(dev, CX2341X_ENC_SET_VBI_LINE, 5, 0,
i | 0x80000000, valid, 0, 0, 0);
}
cx23885_api_cmd(dev, CX2341X_ENC_MUTE_AUDIO, 1, 0, CX23885_UNMUTE);
msleep(60);
cx23885_api_cmd(dev, CX2341X_ENC_INITIALIZE_INPUT, 0, 0);
msleep(60);
mc417_memory_write(dev, 2120, 0x00000080);
if (startencoder) {
cx23885_api_cmd(dev, CX2341X_ENC_START_CAPTURE, 2, 0,
CX23885_MPEG_CAPTURE, CX23885_RAW_BITS_NONE);
msleep(10);
}
return 0;
}
static int bb_buf_setup(struct videobuf_queue *q,
unsigned int *count, unsigned int *size)
{
struct cx23885_fh *fh = q->priv_data;
fh->dev->ts1.ts_packet_size = mpeglinesize;
fh->dev->ts1.ts_packet_count = mpeglines;
*size = fh->dev->ts1.ts_packet_size * fh->dev->ts1.ts_packet_count;
*count = mpegbufs;
return 0;
}
static int bb_buf_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb, enum v4l2_field field)
{
struct cx23885_fh *fh = q->priv_data;
return cx23885_buf_prepare(q, &fh->dev->ts1,
(struct cx23885_buffer *)vb,
field);
}
static void bb_buf_queue(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct cx23885_fh *fh = q->priv_data;
cx23885_buf_queue(&fh->dev->ts1, (struct cx23885_buffer *)vb);
}
static void bb_buf_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
cx23885_free_buffer(q, (struct cx23885_buffer *)vb);
}
static int cx23885_queryctrl(struct cx23885_dev *dev,
struct v4l2_queryctrl *qctrl)
{
qctrl->id = v4l2_ctrl_next(ctrl_classes, qctrl->id);
if (qctrl->id == 0)
return -EINVAL;
if (cx2341x_ctrl_query(&dev->mpeg_params, qctrl))
qctrl->flags |= V4L2_CTRL_FLAG_DISABLED;
return 0;
}
static int cx23885_querymenu(struct cx23885_dev *dev,
struct v4l2_querymenu *qmenu)
{
struct v4l2_queryctrl qctrl;
qctrl.id = qmenu->id;
cx23885_queryctrl(dev, &qctrl);
return v4l2_ctrl_query_menu(qmenu, &qctrl,
cx2341x_ctrl_get_menu(&dev->mpeg_params, qmenu->id));
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
call_all(dev, core, g_std, id);
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(cx23885_tvnorms); i++)
if (*id & cx23885_tvnorms[i].id)
break;
if (i == ARRAY_SIZE(cx23885_tvnorms))
return -EINVAL;
dev->encodernorm = cx23885_tvnorms[i];
mutex_lock(&dev->lock);
cx23885_set_tvnorm(dev, *id);
mutex_unlock(&dev->lock);
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
dprintk(1, "%s()\n", __func__);
return cx23885_enum_input(dev, i);
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
return cx23885_get_input(file, priv, i);
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
return cx23885_set_input(file, priv, i);
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
if (UNSET == dev->tuner_type)
return -EINVAL;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Television");
call_all(dev, tuner, g_tuner, t);
dprintk(1, "VIDIOC_G_TUNER: tuner type %d\n", t->type);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
if (UNSET == dev->tuner_type)
return -EINVAL;
call_all(dev, tuner, s_tuner, t);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
if (UNSET == dev->tuner_type)
return -EINVAL;
f->type = V4L2_TUNER_ANALOG_TV;
f->frequency = dev->freq;
call_all(dev, tuner, g_frequency, f);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
return cx23885_set_frequency(file, priv, f);
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctl)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
return cx23885_get_control(dev, ctl);
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctl)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
return cx23885_set_control(dev, ctl);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
struct cx23885_tsport *tsport = &dev->ts1;
strlcpy(cap->driver, dev->name, sizeof(cap->driver));
strlcpy(cap->card, cx23885_boards[tsport->dev->board].name,
sizeof(cap->card));
sprintf(cap->bus_info, "PCI:%s", pci_name(dev->pci));
cap->capabilities =
V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING |
0;
if (UNSET != dev->tuner_type)
cap->capabilities |= V4L2_CAP_TUNER;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
strlcpy(f->description, "MPEG", sizeof(f->description));
f->pixelformat = V4L2_PIX_FMT_MPEG;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage =
dev->ts1.ts_packet_size * dev->ts1.ts_packet_count;
f->fmt.pix.colorspace = 0;
f->fmt.pix.width = dev->ts1.width;
f->fmt.pix.height = dev->ts1.height;
f->fmt.pix.field = fh->mpegq.field;
dprintk(1, "VIDIOC_G_FMT: w: %d, h: %d, f: %d\n",
dev->ts1.width, dev->ts1.height, fh->mpegq.field);
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage =
dev->ts1.ts_packet_size * dev->ts1.ts_packet_count;
f->fmt.pix.colorspace = 0;
dprintk(1, "VIDIOC_TRY_FMT: w: %d, h: %d, f: %d\n",
dev->ts1.width, dev->ts1.height, fh->mpegq.field);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage =
dev->ts1.ts_packet_size * dev->ts1.ts_packet_count;
f->fmt.pix.colorspace = 0;
dprintk(1, "VIDIOC_S_FMT: w: %d, h: %d, f: %d\n",
f->fmt.pix.width, f->fmt.pix.height, f->fmt.pix.field);
return 0;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct cx23885_fh *fh = file->private_data;
return videobuf_reqbufs(&fh->mpegq, p);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx23885_fh *fh = file->private_data;
return videobuf_querybuf(&fh->mpegq, p);
}
static int vidioc_qbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx23885_fh *fh = file->private_data;
return videobuf_qbuf(&fh->mpegq, p);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct cx23885_fh *fh = priv;
return videobuf_dqbuf(&fh->mpegq, b, file->f_flags & O_NONBLOCK);
}
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type i)
{
struct cx23885_fh *fh = file->private_data;
return videobuf_streamon(&fh->mpegq);
}
static int vidioc_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct cx23885_fh *fh = file->private_data;
return videobuf_streamoff(&fh->mpegq);
}
static int vidioc_g_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
if (f->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
return cx2341x_ext_ctrls(&dev->mpeg_params, 0, f, VIDIOC_G_EXT_CTRLS);
}
static int vidioc_s_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
struct cx2341x_mpeg_params p;
int err;
if (f->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
p = dev->mpeg_params;
err = cx2341x_ext_ctrls(&p, 0, f, VIDIOC_S_EXT_CTRLS);
if (err == 0) {
err = cx2341x_update(dev, cx23885_mbox_func,
&dev->mpeg_params, &p);
dev->mpeg_params = p;
}
return err;
}
static int vidioc_try_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
struct cx2341x_mpeg_params p;
int err;
if (f->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
p = dev->mpeg_params;
err = cx2341x_ext_ctrls(&p, 0, f, VIDIOC_TRY_EXT_CTRLS);
return err;
}
static int vidioc_log_status(struct file *file, void *priv)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
char name[32 + 2];
snprintf(name, sizeof(name), "%s/2", dev->name);
printk(KERN_INFO
"%s/2: ============ START LOG STATUS ============\n",
dev->name);
call_all(dev, core, log_status);
cx2341x_log_status(&dev->mpeg_params, name);
printk(KERN_INFO
"%s/2: ============= END LOG STATUS =============\n",
dev->name);
return 0;
}
static int vidioc_querymenu(struct file *file, void *priv,
struct v4l2_querymenu *a)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
return cx23885_querymenu(dev, a);
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *c)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
return cx23885_queryctrl(dev, c);
}
static int mpeg_open(struct file *file)
{
struct cx23885_dev *dev = video_drvdata(file);
struct cx23885_fh *fh;
dprintk(2, "%s()\n", __func__);
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (!fh)
return -ENOMEM;
file->private_data = fh;
fh->dev = dev;
videobuf_queue_sg_init(&fh->mpegq, &cx23885_qops,
&dev->pci->dev, &dev->ts1.slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_INTERLACED,
sizeof(struct cx23885_buffer),
fh, NULL);
return 0;
}
static int mpeg_release(struct file *file)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
dprintk(2, "%s()\n", __func__);
if (atomic_cmpxchg(&fh->v4l_reading, 1, 0) == 1) {
if (atomic_dec_return(&dev->v4l_reader_count) == 0) {
cx23885_api_cmd(fh->dev, CX2341X_ENC_STOP_CAPTURE, 3, 0,
CX23885_END_NOW, CX23885_MPEG_CAPTURE,
CX23885_RAW_BITS_NONE);
msleep(500);
cx23885_417_check_encoder(dev);
cx23885_cancel_buffers(&fh->dev->ts1);
}
}
if (fh->mpegq.streaming)
videobuf_streamoff(&fh->mpegq);
if (fh->mpegq.reading)
videobuf_read_stop(&fh->mpegq);
videobuf_mmap_free(&fh->mpegq);
file->private_data = NULL;
kfree(fh);
return 0;
}
static ssize_t mpeg_read(struct file *file, char __user *data,
size_t count, loff_t *ppos)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
dprintk(2, "%s()\n", __func__);
if (atomic_cmpxchg(&fh->v4l_reading, 0, 1) == 0) {
if (atomic_inc_return(&dev->v4l_reader_count) == 1) {
if (cx23885_initialize_codec(dev, 1) < 0)
return -EINVAL;
}
}
return videobuf_read_stream(&fh->mpegq, data, count, ppos, 0,
file->f_flags & O_NONBLOCK);
}
static unsigned int mpeg_poll(struct file *file,
struct poll_table_struct *wait)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
dprintk(2, "%s\n", __func__);
return videobuf_poll_stream(file, &fh->mpegq, wait);
}
static int mpeg_mmap(struct file *file, struct vm_area_struct *vma)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
dprintk(2, "%s()\n", __func__);
return videobuf_mmap_mapper(&fh->mpegq, vma);
}
void cx23885_417_unregister(struct cx23885_dev *dev)
{
dprintk(1, "%s()\n", __func__);
if (dev->v4l_device) {
if (video_is_registered(dev->v4l_device))
video_unregister_device(dev->v4l_device);
else
video_device_release(dev->v4l_device);
dev->v4l_device = NULL;
}
}
static struct video_device *cx23885_video_dev_alloc(
struct cx23885_tsport *tsport,
struct pci_dev *pci,
struct video_device *template,
char *type)
{
struct video_device *vfd;
struct cx23885_dev *dev = tsport->dev;
dprintk(1, "%s()\n", __func__);
vfd = video_device_alloc();
if (NULL == vfd)
return NULL;
*vfd = *template;
snprintf(vfd->name, sizeof(vfd->name), "%s (%s)",
cx23885_boards[tsport->dev->board].name, type);
vfd->parent = &pci->dev;
vfd->release = video_device_release;
return vfd;
}
int cx23885_417_register(struct cx23885_dev *dev)
{
int err = -ENODEV;
struct cx23885_tsport *tsport = &dev->ts1;
dprintk(1, "%s()\n", __func__);
if (cx23885_boards[dev->board].portb != CX23885_MPEG_ENCODER)
return err;
dev->encodernorm = cx23885_tvnorms[0];
if (dev->encodernorm.id & V4L2_STD_525_60)
tsport->height = 480;
else
tsport->height = 576;
tsport->width = 720;
cx2341x_fill_defaults(&dev->mpeg_params);
dev->mpeg_params.port = CX2341X_PORT_SERIAL;
dev->v4l_device = cx23885_video_dev_alloc(tsport,
dev->pci, &cx23885_mpeg_template, "mpeg");
video_set_drvdata(dev->v4l_device, dev);
err = video_register_device(dev->v4l_device,
VFL_TYPE_GRABBER, -1);
if (err < 0) {
printk(KERN_INFO "%s: can't register mpeg device\n", dev->name);
return err;
}
printk(KERN_INFO "%s: registered device %s [mpeg]\n",
dev->name, video_device_node_name(dev->v4l_device));
cx23885_initialize_codec(dev, 0);
return 0;
}
