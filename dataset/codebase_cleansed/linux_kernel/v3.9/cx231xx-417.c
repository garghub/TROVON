static int setITVCReg(struct cx231xx *dev, u32 gpio_direction, u32 value)
{
int status = 0;
u32 _gpio_direction = 0;
_gpio_direction = _gpio_direction & CX23417_GPIO_MASK;
_gpio_direction = _gpio_direction|gpio_direction;
status = cx231xx_send_gpio_cmd(dev, _gpio_direction,
(u8 *)&value, 4, 0, 0);
return status;
}
static int getITVCReg(struct cx231xx *dev, u32 gpio_direction, u32 *pValue)
{
int status = 0;
u32 _gpio_direction = 0;
_gpio_direction = _gpio_direction & CX23417_GPIO_MASK;
_gpio_direction = _gpio_direction|gpio_direction;
status = cx231xx_send_gpio_cmd(dev, _gpio_direction,
(u8 *)pValue, 4, 0, 1);
return status;
}
static int waitForMciComplete(struct cx231xx *dev)
{
u32 gpio;
u32 gpio_driection = 0;
u8 count = 0;
getITVCReg(dev, gpio_driection, &gpio);
while (!(gpio&0x020000)) {
msleep(10);
getITVCReg(dev, gpio_driection, &gpio);
if (count++ > 100) {
dprintk(3, "ERROR: Timeout - gpio=%x\n", gpio);
return -1;
}
}
return 0;
}
static int mc417_register_write(struct cx231xx *dev, u16 address, u32 value)
{
u32 temp;
int status = 0;
temp = 0x82|MCI_REGISTER_DATA_BYTE0|((value&0x000000FF)<<8);
temp = temp<<10;
status = setITVCReg(dev, ITVC_WRITE_DIR, temp);
if (status < 0)
return status;
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_REGISTER_DATA_BYTE1|(value&0x0000FF00);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_REGISTER_DATA_BYTE2|((value&0x00FF0000)>>8);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_REGISTER_DATA_BYTE3|((value&0xFF000000)>>16);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_REGISTER_ADDRESS_BYTE0|((address&0x000000FF)<<8);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_REGISTER_ADDRESS_BYTE1|(address&0x0000FF00);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82 | MCI_REGISTER_MODE | MCI_MODE_REGISTER_WRITE;
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
return waitForMciComplete(dev);
}
static int mc417_register_read(struct cx231xx *dev, u16 address, u32 *value)
{
u32 temp;
u32 return_value = 0;
int ret = 0;
temp = 0x82 | MCI_REGISTER_ADDRESS_BYTE0 | ((address & 0x00FF) << 8);
temp = temp << 10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp | ((0x05) << 10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82 | MCI_REGISTER_ADDRESS_BYTE1 | (address & 0xFF00);
temp = temp << 10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp | ((0x05) << 10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82 | MCI_REGISTER_MODE | MCI_MODE_REGISTER_READ;
temp = temp << 10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp | ((0x05) << 10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
ret = waitForMciComplete(dev);
temp = (0x82 | MCI_REGISTER_DATA_BYTE0) << 10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81 | MCI_REGISTER_DATA_BYTE0) << 10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp & 0x03FC0000) >> 18);
setITVCReg(dev, ITVC_READ_DIR, (0x87 << 10));
temp = (0x82 | MCI_REGISTER_DATA_BYTE1) << 10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81 | MCI_REGISTER_DATA_BYTE1) << 10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp & 0x03FC0000) >> 10);
setITVCReg(dev, ITVC_READ_DIR, (0x87 << 10));
temp = (0x82 | MCI_REGISTER_DATA_BYTE2) << 10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81 | MCI_REGISTER_DATA_BYTE2) << 10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp & 0x03FC0000) >> 2);
setITVCReg(dev, ITVC_READ_DIR, (0x87 << 10));
temp = (0x82 | MCI_REGISTER_DATA_BYTE3) << 10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81 | MCI_REGISTER_DATA_BYTE3) << 10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp & 0x03FC0000) << 6);
setITVCReg(dev, ITVC_READ_DIR, (0x87 << 10));
*value = return_value;
return ret;
}
static int mc417_memory_write(struct cx231xx *dev, u32 address, u32 value)
{
u32 temp;
int ret = 0;
temp = 0x82 | MCI_MEMORY_DATA_BYTE0|((value & 0x000000FF) << 8);
temp = temp << 10;
ret = setITVCReg(dev, ITVC_WRITE_DIR, temp);
if (ret < 0)
return ret;
temp = temp | ((0x05) << 10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82 | MCI_MEMORY_DATA_BYTE1 | (value & 0x0000FF00);
temp = temp << 10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp | ((0x05) << 10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_DATA_BYTE2|((value&0x00FF0000)>>8);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_DATA_BYTE3|((value&0xFF000000)>>16);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE2 | MCI_MODE_MEMORY_WRITE |
((address & 0x003F0000)>>8);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE1 | (address & 0xFF00);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE0|((address & 0x00FF)<<8);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
waitForMciComplete(dev);
return 0;
}
static int mc417_memory_read(struct cx231xx *dev, u32 address, u32 *value)
{
u32 temp = 0;
u32 return_value = 0;
int ret = 0;
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE2 | MCI_MODE_MEMORY_READ |
((address & 0x003F0000)>>8);
temp = temp<<10;
ret = setITVCReg(dev, ITVC_WRITE_DIR, temp);
if (ret < 0)
return ret;
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE1 | (address & 0xFF00);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE0 | ((address & 0x00FF)<<8);
temp = temp<<10;
setITVCReg(dev, ITVC_WRITE_DIR, temp);
temp = temp|((0x05)<<10);
setITVCReg(dev, ITVC_WRITE_DIR, temp);
ret = waitForMciComplete(dev);
temp = (0x82|MCI_MEMORY_DATA_BYTE3)<<10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81|MCI_MEMORY_DATA_BYTE3)<<10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp&0x03FC0000)<<6);
setITVCReg(dev, ITVC_READ_DIR, (0x87<<10));
temp = (0x82|MCI_MEMORY_DATA_BYTE2)<<10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81|MCI_MEMORY_DATA_BYTE2)<<10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp&0x03FC0000)>>2);
setITVCReg(dev, ITVC_READ_DIR, (0x87<<10));
temp = (0x82|MCI_MEMORY_DATA_BYTE1)<<10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81|MCI_MEMORY_DATA_BYTE1)<<10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp&0x03FC0000)>>10);
setITVCReg(dev, ITVC_READ_DIR, (0x87<<10));
temp = (0x82|MCI_MEMORY_DATA_BYTE0)<<10;
setITVCReg(dev, ITVC_READ_DIR, temp);
temp = ((0x81|MCI_MEMORY_DATA_BYTE0)<<10);
setITVCReg(dev, ITVC_READ_DIR, temp);
getITVCReg(dev, ITVC_READ_DIR, &temp);
return_value |= ((temp&0x03FC0000)>>18);
setITVCReg(dev, ITVC_READ_DIR, (0x87<<10));
*value = return_value;
return ret;
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
return "SET_PCR_PID";
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
return "SET_DNR_FILTER_PROPS";
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
static int cx231xx_mbox_func(void *priv,
u32 command,
int in,
int out,
u32 data[CX2341X_MBOX_MAX_DATA])
{
struct cx231xx *dev = priv;
unsigned long timeout;
u32 value, flag, retval = 0;
int i;
dprintk(3, "%s: command(0x%X) = %s\n", __func__, command,
cmd_to_str(command));
mc417_memory_read(dev, dev->cx23417_mailbox - 4, &value);
if (value != 0x12345678) {
dprintk(3,
"Firmware and/or mailbox pointer not initialized "
"or corrupted, signature = 0x%x, cmd = %s\n", value,
cmd_to_str(command));
return -1;
}
mc417_memory_read(dev, dev->cx23417_mailbox, &flag);
if (flag) {
dprintk(3, "ERROR: Mailbox appears to be in use "
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
dprintk(3, "ERROR: API Mailbox timeout\n");
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
static int cx231xx_api_cmd(struct cx231xx *dev,
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
err = cx231xx_mbox_func(dev, command, inputcnt, outputcnt, data);
for (i = 0; i < outputcnt; i++) {
int *vptr = va_arg(vargs, int *);
*vptr = data[i];
}
va_end(vargs);
return err;
}
static int cx231xx_find_mailbox(struct cx231xx *dev)
{
u32 signature[4] = {
0x12345678, 0x34567812, 0x56781234, 0x78123456
};
int signaturecnt = 0;
u32 value;
int i;
int ret = 0;
dprintk(2, "%s()\n", __func__);
for (i = 0; i < 0x100; i++) {
ret = mc417_memory_read(dev, i, &value);
if (ret < 0)
return ret;
if (value == signature[signaturecnt])
signaturecnt++;
else
signaturecnt = 0;
if (4 == signaturecnt) {
dprintk(1, "Mailbox signature found at 0x%x\n", i+1);
return i+1;
}
}
dprintk(3, "Mailbox signature values not found!\n");
return -1;
}
static void mciWriteMemoryToGPIO(struct cx231xx *dev, u32 address, u32 value,
u32 *p_fw_image)
{
u32 temp = 0;
int i = 0;
temp = 0x82|MCI_MEMORY_DATA_BYTE0|((value&0x000000FF)<<8);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
temp = 0x82|MCI_MEMORY_DATA_BYTE1|(value&0x0000FF00);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
temp = 0x82|MCI_MEMORY_DATA_BYTE2|((value&0x00FF0000)>>8);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
temp = 0x82|MCI_MEMORY_DATA_BYTE3|((value&0xFF000000)>>16);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE2 | MCI_MODE_MEMORY_WRITE |
((address & 0x003F0000)>>8);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE1 | (address & 0xFF00);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
temp = 0x82|MCI_MEMORY_ADDRESS_BYTE0|((address & 0x00FF)<<8);
temp = temp<<10;
*p_fw_image = temp;
p_fw_image++;
temp = temp|((0x05)<<10);
*p_fw_image = temp;
p_fw_image++;
for (i = 0; i < 6; i++) {
*p_fw_image = 0xFFFFFFFF;
p_fw_image++;
}
}
static int cx231xx_load_firmware(struct cx231xx *dev)
{
static const unsigned char magic[8] = {
0xa7, 0x0d, 0x00, 0x00, 0x66, 0xbb, 0x55, 0xaa
};
const struct firmware *firmware;
int i, retval = 0;
u32 value = 0;
u32 gpio_output = 0;
u32 transfer_size = 0;
u32 fw_data = 0;
u32 address = 0;
u32 *p_current_fw, *p_fw;
u32 *p_fw_data;
int frame = 0;
u16 _buffer_size = 4096;
u8 *p_buffer;
p_current_fw = vmalloc(1884180 * 4);
p_fw = p_current_fw;
if (p_current_fw == NULL) {
dprintk(2, "FAIL!!!\n");
return -1;
}
p_buffer = vmalloc(4096);
if (p_buffer == NULL) {
dprintk(2, "FAIL!!!\n");
return -1;
}
dprintk(2, "%s()\n", __func__);
retval |= mc417_memory_read(dev, 0x9020, &gpio_output);
retval |= mc417_memory_read(dev, 0x900C, &value);
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
retval = request_firmware(&firmware, CX231xx_FIRM_IMAGE_NAME,
&dev->udev->dev);
if (retval != 0) {
printk(KERN_ERR
"ERROR: Hotplug firmware request failed (%s).\n",
CX231xx_FIRM_IMAGE_NAME);
printk(KERN_ERR "Please fix your hotplug setup, the board will "
"not work without firmware loaded!\n");
return -1;
}
if (firmware->size != CX231xx_FIRM_IMAGE_SIZE) {
printk(KERN_ERR "ERROR: Firmware size mismatch "
"(have %zd, expected %d)\n",
firmware->size, CX231xx_FIRM_IMAGE_SIZE);
release_firmware(firmware);
return -1;
}
if (0 != memcmp(firmware->data, magic, 8)) {
printk(KERN_ERR
"ERROR: Firmware magic mismatch, wrong file?\n");
release_firmware(firmware);
return -1;
}
initGPIO(dev);
dprintk(2, "Loading firmware to GPIO...\n");
p_fw_data = (u32 *)firmware->data;
dprintk(2, "firmware->size=%zd\n", firmware->size);
for (transfer_size = 0; transfer_size < firmware->size;
transfer_size += 4) {
fw_data = *p_fw_data;
mciWriteMemoryToGPIO(dev, address, fw_data, p_current_fw);
address = address + 1;
p_current_fw += 20;
p_fw_data += 1;
}
for (frame = 0; frame < (int)(CX231xx_FIRM_IMAGE_SIZE*20/_buffer_size);
frame++) {
for (i = 0; i < _buffer_size; i++) {
*(p_buffer + i) = (u8)(*(p_fw + (frame * 128 * 8 + (i / 4))) & 0x000000FF);
i++;
*(p_buffer + i) = (u8)((*(p_fw + (frame * 128 * 8 + (i / 4))) & 0x0000FF00) >> 8);
i++;
*(p_buffer + i) = (u8)((*(p_fw + (frame * 128 * 8 + (i / 4))) & 0x00FF0000) >> 16);
i++;
*(p_buffer + i) = (u8)((*(p_fw + (frame * 128 * 8 + (i / 4))) & 0xFF000000) >> 24);
}
cx231xx_ep5_bulkout(dev, p_buffer, _buffer_size);
}
p_current_fw = p_fw;
vfree(p_current_fw);
p_current_fw = NULL;
uninitGPIO(dev);
release_firmware(firmware);
dprintk(1, "Firmware upload successful.\n");
retval |= mc417_register_write(dev, IVTV_REG_HW_BLOCKS,
IVTV_CMD_HW_BLOCKS_RST);
if (retval < 0) {
printk(KERN_ERR "%s: Error with mc417_register_write\n",
__func__);
return retval;
}
retval |= mc417_register_write(dev, 0x9020, gpio_output);
retval |= mc417_register_write(dev, 0x900C, value);
retval |= mc417_register_read(dev, IVTV_REG_VPU, &value);
retval |= mc417_register_write(dev, IVTV_REG_VPU, value & 0xFFFFFFE8);
if (retval < 0) {
printk(KERN_ERR "%s: Error with mc417_register_write\n",
__func__);
return retval;
}
return 0;
}
static void cx231xx_417_check_encoder(struct cx231xx *dev)
{
u32 status, seq;
status = 0;
seq = 0;
cx231xx_api_cmd(dev, CX2341X_ENC_GET_SEQ_END, 0, 2, &status, &seq);
dprintk(1, "%s() status = %d, seq = %d\n", __func__, status, seq);
}
static void cx231xx_codec_settings(struct cx231xx *dev)
{
dprintk(1, "%s()\n", __func__);
cx231xx_api_cmd(dev, CX2341X_ENC_SET_FRAME_SIZE, 2, 0,
dev->ts1.height, dev->ts1.width);
dev->mpeg_params.width = dev->ts1.width;
dev->mpeg_params.height = dev->ts1.height;
cx2341x_update(dev, cx231xx_mbox_func, NULL, &dev->mpeg_params);
cx231xx_api_cmd(dev, CX2341X_ENC_MISC, 2, 0, 3, 1);
cx231xx_api_cmd(dev, CX2341X_ENC_MISC, 2, 0, 4, 1);
}
static int cx231xx_initialize_codec(struct cx231xx *dev)
{
int version;
int retval;
u32 i;
u32 val = 0;
dprintk(1, "%s()\n", __func__);
cx231xx_disable656(dev);
retval = cx231xx_api_cmd(dev, CX2341X_ENC_PING_FW, 0, 0);
if (retval < 0) {
dprintk(2, "%s() PING OK\n", __func__);
retval = cx231xx_load_firmware(dev);
if (retval < 0) {
printk(KERN_ERR "%s() f/w load failed\n", __func__);
return retval;
}
retval = cx231xx_find_mailbox(dev);
if (retval < 0) {
printk(KERN_ERR "%s() mailbox < 0, error\n",
__func__);
return -1;
}
dev->cx23417_mailbox = retval;
retval = cx231xx_api_cmd(dev, CX2341X_ENC_PING_FW, 0, 0);
if (retval < 0) {
printk(KERN_ERR
"ERROR: cx23417 firmware ping failed!\n");
return -1;
}
retval = cx231xx_api_cmd(dev, CX2341X_ENC_GET_VERSION, 0, 1,
&version);
if (retval < 0) {
printk(KERN_ERR "ERROR: cx23417 firmware get encoder :"
"version failed!\n");
return -1;
}
dprintk(1, "cx23417 firmware version is 0x%08x\n", version);
msleep(200);
}
for (i = 0; i < 1; i++) {
retval = mc417_register_read(dev, 0x20f8, &val);
dprintk(3, "***before enable656() VIM Capture Lines =%d ***\n",
val);
if (retval < 0)
return retval;
}
cx231xx_enable656(dev);
cx231xx_api_cmd(dev, CX2341X_ENC_STOP_CAPTURE,
3, 0, 1, 3, 4);
cx231xx_codec_settings(dev);
msleep(60);
#if 0
u32 data[7];
data[0] = 0x0001BD00;
data[1] = 1;
data[2] = 4;
data[3] = 0x91559155;
data[4] = 0x206080C0;
data[5] = 6;
data[6] = 64;
cx231xx_api_cmd(dev, CX2341X_ENC_SET_VBI_CONFIG, 7, 0, data[0], data[1],
data[2], data[3], data[4], data[5], data[6]);
for (i = 2; i <= 24; i++) {
int valid;
valid = ((i >= 19) && (i <= 21));
cx231xx_api_cmd(dev, CX2341X_ENC_SET_VBI_LINE, 5, 0, i,
valid, 0 , 0, 0);
cx231xx_api_cmd(dev, CX2341X_ENC_SET_VBI_LINE, 5, 0,
i | 0x80000000, valid, 0, 0, 0);
}
#endif
retval = cx231xx_api_cmd(dev, CX2341X_ENC_INITIALIZE_INPUT, 0, 0);
if (retval < 0)
return retval;
msleep(60);
mc417_memory_write(dev, 2120, 0x00000080);
retval = cx231xx_api_cmd(dev, CX2341X_ENC_START_CAPTURE, 2, 0,
CX231xx_MPEG_CAPTURE, CX231xx_RAW_BITS_NONE);
if (retval < 0)
return retval;
msleep(10);
for (i = 0; i < 1; i++) {
mc417_register_read(dev, 0x20f8, &val);
dprintk(3, "***VIM Capture Lines =%d ***\n", val);
}
return 0;
}
static int bb_buf_setup(struct videobuf_queue *q,
unsigned int *count, unsigned int *size)
{
struct cx231xx_fh *fh = q->priv_data;
fh->dev->ts1.ts_packet_size = mpeglinesize;
fh->dev->ts1.ts_packet_count = mpeglines;
*size = fh->dev->ts1.ts_packet_size * fh->dev->ts1.ts_packet_count;
*count = mpegbufs;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct cx231xx_buffer *buf)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
unsigned long flags = 0;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->video_mode.slock, flags);
if (dev->USE_ISO) {
if (dev->video_mode.isoc_ctl.buf == buf)
dev->video_mode.isoc_ctl.buf = NULL;
} else {
if (dev->video_mode.bulk_ctl.buf == buf)
dev->video_mode.bulk_ctl.buf = NULL;
}
spin_unlock_irqrestore(&dev->video_mode.slock, flags);
videobuf_waiton(vq, &buf->vb, 0, 0);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static void buffer_copy(struct cx231xx *dev, char *data, int len, struct urb *urb,
struct cx231xx_dmaqueue *dma_q)
{
void *vbuf;
struct cx231xx_buffer *buf;
u32 tail_data = 0;
char *p_data;
if (dma_q->mpeg_buffer_done == 0) {
if (list_empty(&dma_q->active))
return;
buf = list_entry(dma_q->active.next,
struct cx231xx_buffer, vb.queue);
dev->video_mode.isoc_ctl.buf = buf;
dma_q->mpeg_buffer_done = 1;
}
buf = dev->video_mode.isoc_ctl.buf;
vbuf = videobuf_to_vmalloc(&buf->vb);
if ((dma_q->mpeg_buffer_completed+len) <
mpeglines*mpeglinesize) {
if (dma_q->add_ps_package_head ==
CX231XX_NEED_ADD_PS_PACKAGE_HEAD) {
memcpy(vbuf+dma_q->mpeg_buffer_completed,
dma_q->ps_head, 3);
dma_q->mpeg_buffer_completed =
dma_q->mpeg_buffer_completed + 3;
dma_q->add_ps_package_head =
CX231XX_NONEED_PS_PACKAGE_HEAD;
}
memcpy(vbuf+dma_q->mpeg_buffer_completed, data, len);
dma_q->mpeg_buffer_completed =
dma_q->mpeg_buffer_completed + len;
} else {
dma_q->mpeg_buffer_done = 0;
tail_data =
mpeglines*mpeglinesize - dma_q->mpeg_buffer_completed;
memcpy(vbuf+dma_q->mpeg_buffer_completed,
data, tail_data);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
v4l2_get_timestamp(&buf->vb.ts);
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
dma_q->mpeg_buffer_completed = 0;
if (len - tail_data > 0) {
p_data = data + tail_data;
dma_q->left_data_count = len - tail_data;
memcpy(dma_q->p_left_data,
p_data, len - tail_data);
}
}
return;
}
static void buffer_filled(char *data, int len, struct urb *urb,
struct cx231xx_dmaqueue *dma_q)
{
void *vbuf;
struct cx231xx_buffer *buf;
if (list_empty(&dma_q->active))
return;
buf = list_entry(dma_q->active.next,
struct cx231xx_buffer, vb.queue);
vbuf = videobuf_to_vmalloc(&buf->vb);
memcpy(vbuf, data, len);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
v4l2_get_timestamp(&buf->vb.ts);
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
return;
}
static inline int cx231xx_isoc_copy(struct cx231xx *dev, struct urb *urb)
{
struct cx231xx_dmaqueue *dma_q = urb->context;
unsigned char *p_buffer;
u32 buffer_size = 0;
u32 i = 0;
for (i = 0; i < urb->number_of_packets; i++) {
if (dma_q->left_data_count > 0) {
buffer_copy(dev, dma_q->p_left_data,
dma_q->left_data_count, urb, dma_q);
dma_q->mpeg_buffer_completed = dma_q->left_data_count;
dma_q->left_data_count = 0;
}
p_buffer = urb->transfer_buffer +
urb->iso_frame_desc[i].offset;
buffer_size = urb->iso_frame_desc[i].actual_length;
if (buffer_size > 0)
buffer_copy(dev, p_buffer, buffer_size, urb, dma_q);
}
return 0;
}
static inline int cx231xx_bulk_copy(struct cx231xx *dev, struct urb *urb)
{
struct cx231xx_dmaqueue *dma_q = urb->context;
unsigned char *p_buffer, *buffer;
u32 buffer_size = 0;
p_buffer = urb->transfer_buffer;
buffer_size = urb->actual_length;
buffer = kmalloc(buffer_size, GFP_ATOMIC);
memcpy(buffer, dma_q->ps_head, 3);
memcpy(buffer+3, p_buffer, buffer_size-3);
memcpy(dma_q->ps_head, p_buffer+buffer_size-3, 3);
p_buffer = buffer;
buffer_filled(p_buffer, buffer_size, urb, dma_q);
kfree(buffer);
return 0;
}
static int bb_buf_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb, enum v4l2_field field)
{
struct cx231xx_fh *fh = q->priv_data;
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx *dev = fh->dev;
int rc = 0, urb_init = 0;
int size = fh->dev->ts1.ts_packet_size * fh->dev->ts1.ts_packet_count;
dma_qq = &dev->video_mode.vidq;
if (0 != buf->vb.baddr && buf->vb.bsize < size)
return -EINVAL;
buf->vb.width = fh->dev->ts1.ts_packet_size;
buf->vb.height = fh->dev->ts1.ts_packet_count;
buf->vb.size = size;
buf->vb.field = field;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
rc = videobuf_iolock(q, &buf->vb, NULL);
if (rc < 0)
goto fail;
}
if (dev->USE_ISO) {
if (!dev->video_mode.isoc_ctl.num_bufs)
urb_init = 1;
} else {
if (!dev->video_mode.bulk_ctl.num_bufs)
urb_init = 1;
}
dev->mode_tv = 1;
if (urb_init) {
rc = cx231xx_set_mode(dev, CX231XX_DIGITAL_MODE);
rc = cx231xx_unmute_audio(dev);
if (dev->USE_ISO) {
cx231xx_set_alt_setting(dev, INDEX_TS1, 4);
rc = cx231xx_init_isoc(dev, mpeglines,
mpegbufs,
dev->ts1_mode.max_pkt_size,
cx231xx_isoc_copy);
} else {
cx231xx_set_alt_setting(dev, INDEX_TS1, 0);
rc = cx231xx_init_bulk(dev, mpeglines,
mpegbufs,
dev->ts1_mode.max_pkt_size,
cx231xx_bulk_copy);
}
if (rc < 0)
goto fail;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(q, buf);
return rc;
}
static void bb_buf_queue(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct cx231xx_fh *fh = q->priv_data;
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx *dev = fh->dev;
struct cx231xx_dmaqueue *vidq = &dev->video_mode.vidq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vidq->active);
}
static void bb_buf_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
free_buffer(q, buf);
}
static int cx231xx_queryctrl(struct cx231xx *dev,
struct v4l2_queryctrl *qctrl)
{
qctrl->id = v4l2_ctrl_next(ctrl_classes, qctrl->id);
if (qctrl->id == 0)
return -EINVAL;
if (cx2341x_ctrl_query(&dev->mpeg_params, qctrl))
qctrl->flags |= V4L2_CTRL_FLAG_DISABLED;
return 0;
}
static int cx231xx_querymenu(struct cx231xx *dev,
struct v4l2_querymenu *qmenu)
{
struct v4l2_queryctrl qctrl;
qctrl.id = qmenu->id;
cx231xx_queryctrl(dev, &qctrl);
return v4l2_ctrl_query_menu(qmenu, &qctrl,
cx2341x_ctrl_get_menu(&dev->mpeg_params, qmenu->id));
}
static int vidioc_g_std(struct file *file, void *fh0, v4l2_std_id *norm)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
*norm = dev->encodernorm.id;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(cx231xx_tvnorms); i++)
if (*id & cx231xx_tvnorms[i].id)
break;
if (i == ARRAY_SIZE(cx231xx_tvnorms))
return -EINVAL;
dev->encodernorm = cx231xx_tvnorms[i];
if (dev->encodernorm.id & 0xb000) {
dprintk(3, "encodernorm set to NTSC\n");
dev->norm = V4L2_STD_NTSC;
dev->ts1.height = 480;
dev->mpeg_params.is_50hz = 0;
} else {
dprintk(3, "encodernorm set to PAL\n");
dev->norm = V4L2_STD_PAL_B;
dev->ts1.height = 576;
dev->mpeg_params.is_50hz = 1;
}
call_all(dev, core, s_std, dev->norm);
cx231xx_do_mode_ctrl_overrides(dev);
dprintk(3, "exit vidioc_s_std() i=0x%x\n", i);
return 0;
}
static int vidioc_g_audio(struct file *file, void *fh,
struct v4l2_audio *a)
{
struct v4l2_audio *vin = a;
int ret = -EINVAL;
if (vin->index > 0)
return ret;
strncpy(vin->name, "VideoGrabber Audio", 14);
vin->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_enumaudio(struct file *file, void *fh,
struct v4l2_audio *a)
{
struct v4l2_audio *vin = a;
int ret = -EINVAL;
if (vin->index > 0)
return ret;
strncpy(vin->name, "VideoGrabber Audio", 14);
vin->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
struct cx231xx_input *input;
int n;
dprintk(3, "enter vidioc_enum_input()i->index=%d\n", i->index);
if (i->index >= 4)
return -EINVAL;
input = &cx231xx_boards[dev->model].input[i->index];
if (input->type == 0)
return -EINVAL;
n = i->index;
strcpy(i->name, iname[INPUT(n)->type]);
if (input->type == CX231XX_VMUX_TELEVISION ||
input->type == CX231XX_VMUX_CABLE)
i->type = V4L2_INPUT_TYPE_TUNER;
else
i->type = V4L2_INPUT_TYPE_CAMERA;
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_s_input() i=%d\n", i);
mutex_lock(&dev->lock);
video_mux(dev, i);
mutex_unlock(&dev->lock);
if (i >= 4)
return -EINVAL;
dev->input = i;
dprintk(3, "exit vidioc_s_input()\n");
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
return 0;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctl)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_s_ctrl()\n");
call_all(dev, core, s_ctrl, ctl);
dprintk(3, "exit vidioc_s_ctrl()\n");
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
memcpy(cap, &pvr_capability, sizeof(struct v4l2_capability));
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
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_g_fmt_vid_cap()\n");
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage =
dev->ts1.ts_packet_size * dev->ts1.ts_packet_count;
f->fmt.pix.colorspace = 0;
f->fmt.pix.width = dev->ts1.width;
f->fmt.pix.height = dev->ts1.height;
f->fmt.pix.field = fh->vidq.field;
dprintk(1, "VIDIOC_G_FMT: w: %d, h: %d, f: %d\n",
dev->ts1.width, dev->ts1.height, fh->vidq.field);
dprintk(3, "exit vidioc_g_fmt_vid_cap()\n");
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_try_fmt_vid_cap()\n");
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage =
dev->ts1.ts_packet_size * dev->ts1.ts_packet_count;
f->fmt.pix.colorspace = 0;
dprintk(1, "VIDIOC_TRY_FMT: w: %d, h: %d, f: %d\n",
dev->ts1.width, dev->ts1.height, fh->vidq.field);
dprintk(3, "exit vidioc_try_fmt_vid_cap()\n");
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
return 0;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct cx231xx_fh *fh = file->private_data;
return videobuf_reqbufs(&fh->vidq, p);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx231xx_fh *fh = file->private_data;
return videobuf_querybuf(&fh->vidq, p);
}
static int vidioc_qbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx231xx_fh *fh = file->private_data;
return videobuf_qbuf(&fh->vidq, p);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct cx231xx_fh *fh = priv;
return videobuf_dqbuf(&fh->vidq, b, file->f_flags & O_NONBLOCK);
}
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type i)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_streamon()\n");
cx231xx_set_alt_setting(dev, INDEX_TS1, 0);
cx231xx_set_mode(dev, CX231XX_DIGITAL_MODE);
if (dev->USE_ISO)
cx231xx_init_isoc(dev, CX231XX_NUM_PACKETS,
CX231XX_NUM_BUFS,
dev->video_mode.max_pkt_size,
cx231xx_isoc_copy);
else {
cx231xx_init_bulk(dev, 320,
5,
dev->ts1_mode.max_pkt_size,
cx231xx_bulk_copy);
}
dprintk(3, "exit vidioc_streamon()\n");
return videobuf_streamon(&fh->vidq);
}
static int vidioc_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct cx231xx_fh *fh = file->private_data;
return videobuf_streamoff(&fh->vidq);
}
static int vidioc_g_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_g_ext_ctrls()\n");
if (f->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
dprintk(3, "exit vidioc_g_ext_ctrls()\n");
return cx2341x_ext_ctrls(&dev->mpeg_params, 0, f, VIDIOC_G_EXT_CTRLS);
}
static int vidioc_s_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
struct cx2341x_mpeg_params p;
int err;
dprintk(3, "enter vidioc_s_ext_ctrls()\n");
if (f->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
p = dev->mpeg_params;
err = cx2341x_ext_ctrls(&p, 0, f, VIDIOC_TRY_EXT_CTRLS);
if (err == 0) {
err = cx2341x_update(dev, cx231xx_mbox_func,
&dev->mpeg_params, &p);
dev->mpeg_params = p;
}
return err;
return 0;
}
static int vidioc_try_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
struct cx2341x_mpeg_params p;
int err;
dprintk(3, "enter vidioc_try_ext_ctrls()\n");
if (f->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
p = dev->mpeg_params;
err = cx2341x_ext_ctrls(&p, 0, f, VIDIOC_TRY_EXT_CTRLS);
dprintk(3, "exit vidioc_try_ext_ctrls() err=%d\n", err);
return err;
}
static int vidioc_log_status(struct file *file, void *priv)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
char name[32 + 2];
snprintf(name, sizeof(name), "%s/2", dev->name);
dprintk(3,
"%s/2: ============ START LOG STATUS ============\n",
dev->name);
call_all(dev, core, log_status);
cx2341x_log_status(&dev->mpeg_params, name);
dprintk(3,
"%s/2: ============= END LOG STATUS =============\n",
dev->name);
return 0;
}
static int vidioc_querymenu(struct file *file, void *priv,
struct v4l2_querymenu *a)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_querymenu()\n");
dprintk(3, "exit vidioc_querymenu()\n");
return cx231xx_querymenu(dev, a);
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *c)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
dprintk(3, "enter vidioc_queryctrl()\n");
dprintk(3, "exit vidioc_queryctrl()\n");
return cx231xx_queryctrl(dev, c);
}
static int mpeg_open(struct file *file)
{
int minor = video_devdata(file)->minor;
struct cx231xx *h, *dev = NULL;
struct cx231xx_fh *fh;
dprintk(2, "%s()\n", __func__);
list_for_each_entry(h, &cx231xx_devlist, devlist) {
if (h->v4l_device->minor == minor)
dev = h;
}
if (dev == NULL)
return -ENODEV;
mutex_lock(&dev->lock);
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (NULL == fh) {
mutex_unlock(&dev->lock);
return -ENOMEM;
}
file->private_data = fh;
fh->dev = dev;
videobuf_queue_vmalloc_init(&fh->vidq, &cx231xx_qops,
NULL, &dev->video_mode.slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED,
sizeof(struct cx231xx_buffer), fh, NULL);
cx231xx_set_alt_setting(dev, INDEX_VANC, 1);
cx231xx_set_gpio_value(dev, 2, 0);
cx231xx_initialize_codec(dev);
mutex_unlock(&dev->lock);
cx231xx_start_TS1(dev);
return 0;
}
static int mpeg_release(struct file *file)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(3, "mpeg_release()! dev=0x%p\n", dev);
if (!dev) {
dprintk(3, "abort!!!\n");
return 0;
}
mutex_lock(&dev->lock);
cx231xx_stop_TS1(dev);
if (dev->USE_ISO)
cx231xx_uninit_isoc(dev);
else
cx231xx_uninit_bulk(dev);
cx231xx_set_mode(dev, CX231XX_SUSPEND);
cx231xx_api_cmd(fh->dev, CX2341X_ENC_STOP_CAPTURE, 3, 0,
CX231xx_END_NOW, CX231xx_MPEG_CAPTURE,
CX231xx_RAW_BITS_NONE);
if (atomic_cmpxchg(&fh->v4l_reading, 1, 0) == 1) {
if (atomic_dec_return(&dev->v4l_reader_count) == 0) {
msleep(500);
cx231xx_417_check_encoder(dev);
}
}
if (fh->vidq.streaming)
videobuf_streamoff(&fh->vidq);
if (fh->vidq.reading)
videobuf_read_stop(&fh->vidq);
videobuf_mmap_free(&fh->vidq);
file->private_data = NULL;
kfree(fh);
mutex_unlock(&dev->lock);
return 0;
}
static ssize_t mpeg_read(struct file *file, char __user *data,
size_t count, loff_t *ppos)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
if (atomic_cmpxchg(&fh->v4l_reading, 0, 1) == 0) {
if (atomic_inc_return(&dev->v4l_reader_count) == 1) {
if (cx231xx_initialize_codec(dev) < 0)
return -EINVAL;
}
}
return videobuf_read_stream(&fh->vidq, data, count, ppos, 0,
file->f_flags & O_NONBLOCK);
}
static unsigned int mpeg_poll(struct file *file,
struct poll_table_struct *wait)
{
struct cx231xx_fh *fh = file->private_data;
return videobuf_poll_stream(file, &fh->vidq, wait);
}
static int mpeg_mmap(struct file *file, struct vm_area_struct *vma)
{
struct cx231xx_fh *fh = file->private_data;
struct cx231xx *dev = fh->dev;
dprintk(2, "%s()\n", __func__);
return videobuf_mmap_mapper(&fh->vidq, vma);
}
void cx231xx_417_unregister(struct cx231xx *dev)
{
dprintk(1, "%s()\n", __func__);
dprintk(3, "%s()\n", __func__);
if (dev->v4l_device) {
if (-1 != dev->v4l_device->minor)
video_unregister_device(dev->v4l_device);
else
video_device_release(dev->v4l_device);
dev->v4l_device = NULL;
}
}
static struct video_device *cx231xx_video_dev_alloc(
struct cx231xx *dev,
struct usb_device *usbdev,
struct video_device *template,
char *type)
{
struct video_device *vfd;
dprintk(1, "%s()\n", __func__);
vfd = video_device_alloc();
if (NULL == vfd)
return NULL;
*vfd = *template;
vfd->minor = -1;
snprintf(vfd->name, sizeof(vfd->name), "%s %s (%s)", dev->name,
type, cx231xx_boards[dev->model].name);
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->release = video_device_release;
return vfd;
}
int cx231xx_417_register(struct cx231xx *dev)
{
int err = -ENODEV;
struct cx231xx_tsport *tsport = &dev->ts1;
dprintk(1, "%s()\n", __func__);
dev->encodernorm = cx231xx_tvnorms[0];
if (dev->encodernorm.id & V4L2_STD_525_60)
tsport->height = 480;
else
tsport->height = 576;
tsport->width = 720;
cx2341x_fill_defaults(&dev->mpeg_params);
dev->norm = V4L2_STD_NTSC;
dev->mpeg_params.port = CX2341X_PORT_SERIAL;
dev->v4l_device = cx231xx_video_dev_alloc(dev,
dev->udev, &cx231xx_mpeg_template, "mpeg");
err = video_register_device(dev->v4l_device,
VFL_TYPE_GRABBER, -1);
if (err < 0) {
dprintk(3, "%s: can't register mpeg device\n", dev->name);
return err;
}
dprintk(3, "%s: registered device video%d [mpeg]\n",
dev->name, dev->v4l_device->num);
return 0;
}
