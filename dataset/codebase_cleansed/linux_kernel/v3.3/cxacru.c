static ssize_t cxacru_sysfs_showattr_u32(u32 value, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%u\n", value);
}
static ssize_t cxacru_sysfs_showattr_s8(s8 value, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static ssize_t cxacru_sysfs_showattr_dB(s16 value, char *buf)
{
if (likely(value >= 0)) {
return snprintf(buf, PAGE_SIZE, "%u.%02u\n",
value / 100, value % 100);
} else {
value = -value;
return snprintf(buf, PAGE_SIZE, "-%u.%02u\n",
value / 100, value % 100);
}
}
static ssize_t cxacru_sysfs_showattr_bool(u32 value, char *buf)
{
static char *str[] = { "no", "yes" };
if (unlikely(value >= ARRAY_SIZE(str)))
return snprintf(buf, PAGE_SIZE, "%u\n", value);
return snprintf(buf, PAGE_SIZE, "%s\n", str[value]);
}
static ssize_t cxacru_sysfs_showattr_LINK(u32 value, char *buf)
{
static char *str[] = { NULL, "not connected", "connected", "lost" };
if (unlikely(value >= ARRAY_SIZE(str) || str[value] == NULL))
return snprintf(buf, PAGE_SIZE, "%u\n", value);
return snprintf(buf, PAGE_SIZE, "%s\n", str[value]);
}
static ssize_t cxacru_sysfs_showattr_LINE(u32 value, char *buf)
{
static char *str[] = { "down", "attempting to activate",
"training", "channel analysis", "exchange", "up",
"waiting", "initialising"
};
if (unlikely(value >= ARRAY_SIZE(str)))
return snprintf(buf, PAGE_SIZE, "%u\n", value);
return snprintf(buf, PAGE_SIZE, "%s\n", str[value]);
}
static ssize_t cxacru_sysfs_showattr_MODU(u32 value, char *buf)
{
static char *str[] = {
"",
"ANSI T1.413",
"ITU-T G.992.1 (G.DMT)",
"ITU-T G.992.2 (G.LITE)"
};
if (unlikely(value >= ARRAY_SIZE(str)))
return snprintf(buf, PAGE_SIZE, "%u\n", value);
return snprintf(buf, PAGE_SIZE, "%s\n", str[value]);
}
static ssize_t cxacru_sysfs_show_mac_address(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cxacru_data *instance = to_usbatm_driver_data(
to_usb_interface(dev));
if (instance == NULL || instance->usbatm->atm_dev == NULL)
return -ENODEV;
return snprintf(buf, PAGE_SIZE, "%pM\n",
instance->usbatm->atm_dev->esi);
}
static ssize_t cxacru_sysfs_show_adsl_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
static char *str[] = { "running", "stopped" };
struct cxacru_data *instance = to_usbatm_driver_data(
to_usb_interface(dev));
u32 value;
if (instance == NULL)
return -ENODEV;
value = instance->card_info[CXINF_LINE_STARTABLE];
if (unlikely(value >= ARRAY_SIZE(str)))
return snprintf(buf, PAGE_SIZE, "%u\n", value);
return snprintf(buf, PAGE_SIZE, "%s\n", str[value]);
}
static ssize_t cxacru_sysfs_store_adsl_state(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct cxacru_data *instance = to_usbatm_driver_data(
to_usb_interface(dev));
int ret;
int poll = -1;
char str_cmd[8];
int len = strlen(buf);
if (!capable(CAP_NET_ADMIN))
return -EACCES;
ret = sscanf(buf, "%7s", str_cmd);
if (ret != 1)
return -EINVAL;
ret = 0;
if (instance == NULL)
return -ENODEV;
if (mutex_lock_interruptible(&instance->adsl_state_serialize))
return -ERESTARTSYS;
if (!strcmp(str_cmd, "stop") || !strcmp(str_cmd, "restart")) {
ret = cxacru_cm(instance, CM_REQUEST_CHIP_ADSL_LINE_STOP, NULL, 0, NULL, 0);
if (ret < 0) {
atm_err(instance->usbatm, "change adsl state:"
" CHIP_ADSL_LINE_STOP returned %d\n", ret);
ret = -EIO;
} else {
ret = len;
poll = CXPOLL_STOPPED;
}
}
if (!strcmp(str_cmd, "restart"))
msleep(1500);
if (!strcmp(str_cmd, "start") || !strcmp(str_cmd, "restart")) {
ret = cxacru_cm(instance, CM_REQUEST_CHIP_ADSL_LINE_START, NULL, 0, NULL, 0);
if (ret < 0) {
atm_err(instance->usbatm, "change adsl state:"
" CHIP_ADSL_LINE_START returned %d\n", ret);
ret = -EIO;
} else {
ret = len;
poll = CXPOLL_POLLING;
}
}
if (!strcmp(str_cmd, "poll")) {
ret = len;
poll = CXPOLL_POLLING;
}
if (ret == 0) {
ret = -EINVAL;
poll = -1;
}
if (poll == CXPOLL_POLLING) {
mutex_lock(&instance->poll_state_serialize);
switch (instance->poll_state) {
case CXPOLL_STOPPED:
instance->poll_state = CXPOLL_POLLING;
break;
case CXPOLL_STOPPING:
instance->poll_state = CXPOLL_POLLING;
case CXPOLL_POLLING:
case CXPOLL_SHUTDOWN:
poll = -1;
}
mutex_unlock(&instance->poll_state_serialize);
} else if (poll == CXPOLL_STOPPED) {
mutex_lock(&instance->poll_state_serialize);
if (instance->poll_state == CXPOLL_POLLING)
instance->poll_state = CXPOLL_STOPPING;
mutex_unlock(&instance->poll_state_serialize);
}
mutex_unlock(&instance->adsl_state_serialize);
if (poll == CXPOLL_POLLING)
cxacru_poll_status(&instance->poll_work.work);
return ret;
}
static ssize_t cxacru_sysfs_store_adsl_config(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct cxacru_data *instance = to_usbatm_driver_data(
to_usb_interface(dev));
int len = strlen(buf);
int ret, pos, num;
__le32 data[CMD_PACKET_SIZE / 4];
if (!capable(CAP_NET_ADMIN))
return -EACCES;
if (instance == NULL)
return -ENODEV;
pos = 0;
num = 0;
while (pos < len) {
int tmp;
u32 index;
u32 value;
ret = sscanf(buf + pos, "%x=%x%n", &index, &value, &tmp);
if (ret < 2)
return -EINVAL;
if (index < 0 || index > 0x7f)
return -EINVAL;
pos += tmp;
if (buf[pos] == '\n' && pos == len-1)
pos++;
data[num * 2 + 1] = cpu_to_le32(index);
data[num * 2 + 2] = cpu_to_le32(value);
num++;
if (pos >= len || num >= CMD_MAX_CONFIG) {
char log[CMD_MAX_CONFIG * 12 + 1];
data[0] = cpu_to_le32(num);
ret = cxacru_cm(instance, CM_REQUEST_CARD_DATA_SET,
(u8 *) data, 4 + num * 8, NULL, 0);
if (ret < 0) {
atm_err(instance->usbatm,
"set card data returned %d\n", ret);
return -EIO;
}
for (tmp = 0; tmp < num; tmp++)
snprintf(log + tmp*12, 13, " %02x=%08x",
le32_to_cpu(data[tmp * 2 + 1]),
le32_to_cpu(data[tmp * 2 + 2]));
atm_info(instance->usbatm, "config%s\n", log);
num = 0;
}
}
return len;
}
static void cxacru_blocking_completion(struct urb *urb)
{
complete(urb->context);
}
static void cxacru_timeout_kill(unsigned long data)
{
usb_unlink_urb((struct urb *) data);
}
static int cxacru_start_wait_urb(struct urb *urb, struct completion *done,
int *actual_length)
{
struct timer_list timer;
init_timer(&timer);
timer.expires = jiffies + msecs_to_jiffies(CMD_TIMEOUT);
timer.data = (unsigned long) urb;
timer.function = cxacru_timeout_kill;
add_timer(&timer);
wait_for_completion(done);
del_timer_sync(&timer);
if (actual_length)
*actual_length = urb->actual_length;
return urb->status;
}
static int cxacru_cm(struct cxacru_data *instance, enum cxacru_cm_request cm,
u8 *wdata, int wsize, u8 *rdata, int rsize)
{
int ret, actlen;
int offb, offd;
const int stride = CMD_PACKET_SIZE - 4;
u8 *wbuf = instance->snd_buf;
u8 *rbuf = instance->rcv_buf;
int wbuflen = ((wsize - 1) / stride + 1) * CMD_PACKET_SIZE;
int rbuflen = ((rsize - 1) / stride + 1) * CMD_PACKET_SIZE;
if (wbuflen > PAGE_SIZE || rbuflen > PAGE_SIZE) {
if (printk_ratelimit())
usb_err(instance->usbatm, "requested transfer size too large (%d, %d)\n",
wbuflen, rbuflen);
ret = -ENOMEM;
goto err;
}
mutex_lock(&instance->cm_serialize);
init_completion(&instance->rcv_done);
ret = usb_submit_urb(instance->rcv_urb, GFP_KERNEL);
if (ret < 0) {
if (printk_ratelimit())
usb_err(instance->usbatm, "submit of read urb for cm %#x failed (%d)\n",
cm, ret);
goto fail;
}
memset(wbuf, 0, wbuflen);
wbuf[0] = cm;
for (offb = offd = 0; offd < wsize; offd += stride, offb += CMD_PACKET_SIZE) {
wbuf[offb] = cm;
memcpy(wbuf + offb + 4, wdata + offd, min_t(int, stride, wsize - offd));
}
instance->snd_urb->transfer_buffer_length = wbuflen;
init_completion(&instance->snd_done);
ret = usb_submit_urb(instance->snd_urb, GFP_KERNEL);
if (ret < 0) {
if (printk_ratelimit())
usb_err(instance->usbatm, "submit of write urb for cm %#x failed (%d)\n",
cm, ret);
goto fail;
}
ret = cxacru_start_wait_urb(instance->snd_urb, &instance->snd_done, NULL);
if (ret < 0) {
if (printk_ratelimit())
usb_err(instance->usbatm, "send of cm %#x failed (%d)\n", cm, ret);
goto fail;
}
ret = cxacru_start_wait_urb(instance->rcv_urb, &instance->rcv_done, &actlen);
if (ret < 0) {
if (printk_ratelimit())
usb_err(instance->usbatm, "receive of cm %#x failed (%d)\n", cm, ret);
goto fail;
}
if (actlen % CMD_PACKET_SIZE || !actlen) {
if (printk_ratelimit())
usb_err(instance->usbatm, "invalid response length to cm %#x: %d\n",
cm, actlen);
ret = -EIO;
goto fail;
}
for (offb = offd = 0; offd < rsize && offb < actlen; offb += CMD_PACKET_SIZE) {
if (rbuf[offb] != cm) {
if (printk_ratelimit())
usb_err(instance->usbatm, "wrong cm %#x in response to cm %#x\n",
rbuf[offb], cm);
ret = -EIO;
goto fail;
}
if (rbuf[offb + 1] != CM_STATUS_SUCCESS) {
if (printk_ratelimit())
usb_err(instance->usbatm, "response to cm %#x failed: %#x\n",
cm, rbuf[offb + 1]);
ret = -EIO;
goto fail;
}
if (offd >= rsize)
break;
memcpy(rdata + offd, rbuf + offb + 4, min_t(int, stride, rsize - offd));
offd += stride;
}
ret = offd;
dbg("cm %#x", cm);
fail:
mutex_unlock(&instance->cm_serialize);
err:
return ret;
}
static int cxacru_cm_get_array(struct cxacru_data *instance, enum cxacru_cm_request cm,
u32 *data, int size)
{
int ret, len;
__le32 *buf;
int offb, offd;
const int stride = CMD_PACKET_SIZE / (4 * 2) - 1;
int buflen = ((size - 1) / stride + 1 + size * 2) * 4;
buf = kmalloc(buflen, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = cxacru_cm(instance, cm, NULL, 0, (u8 *) buf, buflen);
if (ret < 0)
goto cleanup;
len = ret / 4;
for (offb = 0; offb < len; ) {
int l = le32_to_cpu(buf[offb++]);
if (l < 0 || l > stride || l > (len - offb) / 2) {
if (printk_ratelimit())
usb_err(instance->usbatm, "invalid data length from cm %#x: %d\n",
cm, l);
ret = -EIO;
goto cleanup;
}
while (l--) {
offd = le32_to_cpu(buf[offb++]);
if (offd >= size) {
if (printk_ratelimit())
usb_err(instance->usbatm, "wrong index %#x in response to cm %#x\n",
offd, cm);
ret = -EIO;
goto cleanup;
}
data[offd] = le32_to_cpu(buf[offb++]);
}
}
ret = 0;
cleanup:
kfree(buf);
return ret;
}
static int cxacru_card_status(struct cxacru_data *instance)
{
int ret = cxacru_cm(instance, CM_REQUEST_CARD_GET_STATUS, NULL, 0, NULL, 0);
if (ret < 0) {
dbg("cxacru_adsl_start: CARD_GET_STATUS returned %d", ret);
return ret;
}
return 0;
}
static void cxacru_remove_device_files(struct usbatm_data *usbatm_instance,
struct atm_dev *atm_dev)
{
struct usb_interface *intf = usbatm_instance->usb_intf;
#define CXACRU_DEVICE_REMOVE_FILE(_name) \
device_remove_file(&intf->dev, &dev_attr_##_name);
CXACRU_ALL_FILES(REMOVE);
#undef CXACRU_DEVICE_REMOVE_FILE
}
static int cxacru_atm_start(struct usbatm_data *usbatm_instance,
struct atm_dev *atm_dev)
{
struct cxacru_data *instance = usbatm_instance->driver_data;
struct usb_interface *intf = usbatm_instance->usb_intf;
int ret;
int start_polling = 1;
dbg("cxacru_atm_start");
ret = cxacru_cm(instance, CM_REQUEST_CARD_GET_MAC_ADDRESS, NULL, 0,
atm_dev->esi, sizeof(atm_dev->esi));
if (ret < 0) {
atm_err(usbatm_instance, "cxacru_atm_start: CARD_GET_MAC_ADDRESS returned %d\n", ret);
return ret;
}
#define CXACRU_DEVICE_CREATE_FILE(_name) \
ret = device_create_file(&intf->dev, &dev_attr_##_name); \
if (unlikely(ret)) \
goto fail_sysfs;
CXACRU_ALL_FILES(CREATE);
#undef CXACRU_DEVICE_CREATE_FILE
mutex_lock(&instance->adsl_state_serialize);
ret = cxacru_cm(instance, CM_REQUEST_CHIP_ADSL_LINE_START, NULL, 0, NULL, 0);
if (ret < 0)
atm_err(usbatm_instance, "cxacru_atm_start: CHIP_ADSL_LINE_START returned %d\n", ret);
mutex_lock(&instance->poll_state_serialize);
switch (instance->poll_state) {
case CXPOLL_STOPPED:
instance->poll_state = CXPOLL_POLLING;
break;
case CXPOLL_STOPPING:
instance->poll_state = CXPOLL_POLLING;
case CXPOLL_POLLING:
case CXPOLL_SHUTDOWN:
start_polling = 0;
}
mutex_unlock(&instance->poll_state_serialize);
mutex_unlock(&instance->adsl_state_serialize);
printk(KERN_INFO "%s%d: %s %pM\n", atm_dev->type, atm_dev->number,
usbatm_instance->description, atm_dev->esi);
if (start_polling)
cxacru_poll_status(&instance->poll_work.work);
return 0;
fail_sysfs:
usb_err(usbatm_instance, "cxacru_atm_start: device_create_file failed (%d)\n", ret);
cxacru_remove_device_files(usbatm_instance, atm_dev);
return ret;
}
static void cxacru_poll_status(struct work_struct *work)
{
struct cxacru_data *instance =
container_of(work, struct cxacru_data, poll_work.work);
u32 buf[CXINF_MAX] = {};
struct usbatm_data *usbatm = instance->usbatm;
struct atm_dev *atm_dev = usbatm->atm_dev;
int keep_polling = 1;
int ret;
ret = cxacru_cm_get_array(instance, CM_REQUEST_CARD_INFO_GET, buf, CXINF_MAX);
if (ret < 0) {
if (ret != -ESHUTDOWN)
atm_warn(usbatm, "poll status: error %d\n", ret);
mutex_lock(&instance->poll_state_serialize);
if (instance->poll_state != CXPOLL_SHUTDOWN) {
instance->poll_state = CXPOLL_STOPPED;
if (ret != -ESHUTDOWN)
atm_warn(usbatm, "polling disabled, set adsl_state"
" to 'start' or 'poll' to resume\n");
}
mutex_unlock(&instance->poll_state_serialize);
goto reschedule;
}
memcpy(instance->card_info, buf, sizeof(instance->card_info));
if (instance->adsl_status != buf[CXINF_LINE_STARTABLE]) {
instance->adsl_status = buf[CXINF_LINE_STARTABLE];
switch (instance->adsl_status) {
case 0:
atm_printk(KERN_INFO, usbatm, "ADSL state: running\n");
break;
case 1:
atm_printk(KERN_INFO, usbatm, "ADSL state: stopped\n");
break;
default:
atm_printk(KERN_INFO, usbatm, "Unknown adsl status %02x\n", instance->adsl_status);
break;
}
}
if (instance->line_status == buf[CXINF_LINE_STATUS])
goto reschedule;
instance->line_status = buf[CXINF_LINE_STATUS];
switch (instance->line_status) {
case 0:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: down\n");
break;
case 1:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: attempting to activate\n");
break;
case 2:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: training\n");
break;
case 3:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: channel analysis\n");
break;
case 4:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: exchange\n");
break;
case 5:
atm_dev->link_rate = buf[CXINF_DOWNSTREAM_RATE] * 1000 / 424;
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_FOUND);
atm_info(usbatm, "ADSL line: up (%d kb/s down | %d kb/s up)\n",
buf[CXINF_DOWNSTREAM_RATE], buf[CXINF_UPSTREAM_RATE]);
break;
case 6:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: waiting\n");
break;
case 7:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_LOST);
atm_info(usbatm, "ADSL line: initializing\n");
break;
default:
atm_dev_signal_change(atm_dev, ATM_PHY_SIG_UNKNOWN);
atm_info(usbatm, "Unknown line state %02x\n", instance->line_status);
break;
}
reschedule:
mutex_lock(&instance->poll_state_serialize);
if (instance->poll_state == CXPOLL_STOPPING &&
instance->adsl_status == 1 &&
instance->line_status == 0)
instance->poll_state = CXPOLL_STOPPED;
if (instance->poll_state == CXPOLL_STOPPED)
keep_polling = 0;
mutex_unlock(&instance->poll_state_serialize);
if (keep_polling)
schedule_delayed_work(&instance->poll_work,
round_jiffies_relative(POLL_INTERVAL*HZ));
}
static int cxacru_fw(struct usb_device *usb_dev, enum cxacru_fw_request fw,
u8 code1, u8 code2, u32 addr, const u8 *data, int size)
{
int ret;
u8 *buf;
int offd, offb;
const int stride = CMD_PACKET_SIZE - 8;
buf = (u8 *) __get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
offb = offd = 0;
do {
int l = min_t(int, stride, size - offd);
buf[offb++] = fw;
buf[offb++] = l;
buf[offb++] = code1;
buf[offb++] = code2;
put_unaligned(cpu_to_le32(addr), (__le32 *)(buf + offb));
offb += 4;
addr += l;
if (l)
memcpy(buf + offb, data + offd, l);
if (l < stride)
memset(buf + offb + l, 0, stride - l);
offb += stride;
offd += stride;
if ((offb >= PAGE_SIZE) || (offd >= size)) {
ret = usb_bulk_msg(usb_dev, usb_sndbulkpipe(usb_dev, CXACRU_EP_CMD),
buf, offb, NULL, CMD_TIMEOUT);
if (ret < 0) {
dbg("sending fw %#x failed", fw);
goto cleanup;
}
offb = 0;
}
} while (offd < size);
dbg("sent fw %#x", fw);
ret = 0;
cleanup:
free_page((unsigned long) buf);
return ret;
}
static void cxacru_upload_firmware(struct cxacru_data *instance,
const struct firmware *fw,
const struct firmware *bp)
{
int ret;
struct usbatm_data *usbatm = instance->usbatm;
struct usb_device *usb_dev = usbatm->usb_dev;
__le16 signature[] = { usb_dev->descriptor.idVendor,
usb_dev->descriptor.idProduct };
__le32 val;
dbg("cxacru_upload_firmware");
val = cpu_to_le32(instance->modem_type->pll_f_clk);
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, PLLFCLK_ADDR, (u8 *) &val, 4);
if (ret) {
usb_err(usbatm, "FirmwarePllFClkValue failed: %d\n", ret);
return;
}
val = cpu_to_le32(instance->modem_type->pll_b_clk);
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, PLLBCLK_ADDR, (u8 *) &val, 4);
if (ret) {
usb_err(usbatm, "FirmwarePllBClkValue failed: %d\n", ret);
return;
}
val = cpu_to_le32(SDRAM_ENA);
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, SDRAMEN_ADDR, (u8 *) &val, 4);
if (ret) {
usb_err(usbatm, "Enable SDRAM failed: %d\n", ret);
return;
}
usb_info(usbatm, "loading firmware\n");
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, FW_ADDR, fw->data, fw->size);
if (ret) {
usb_err(usbatm, "Firmware upload failed: %d\n", ret);
return;
}
if (instance->modem_type->boot_rom_patch) {
usb_info(usbatm, "loading boot ROM patch\n");
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, BR_ADDR, bp->data, bp->size);
if (ret) {
usb_err(usbatm, "Boot ROM patching failed: %d\n", ret);
return;
}
}
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, SIG_ADDR, (u8 *) signature, 4);
if (ret) {
usb_err(usbatm, "Signature storing failed: %d\n", ret);
return;
}
usb_info(usbatm, "starting device\n");
if (instance->modem_type->boot_rom_patch) {
val = cpu_to_le32(BR_ADDR);
ret = cxacru_fw(usb_dev, FW_WRITE_MEM, 0x2, 0x0, BR_STACK_ADDR, (u8 *) &val, 4);
} else {
ret = cxacru_fw(usb_dev, FW_GOTO_MEM, 0x0, 0x0, FW_ADDR, NULL, 0);
}
if (ret) {
usb_err(usbatm, "Passing control to firmware failed: %d\n", ret);
return;
}
msleep_interruptible(1000);
usb_clear_halt(usb_dev, usb_sndbulkpipe(usb_dev, CXACRU_EP_CMD));
usb_clear_halt(usb_dev, usb_rcvbulkpipe(usb_dev, CXACRU_EP_CMD));
usb_clear_halt(usb_dev, usb_sndbulkpipe(usb_dev, CXACRU_EP_DATA));
usb_clear_halt(usb_dev, usb_rcvbulkpipe(usb_dev, CXACRU_EP_DATA));
ret = cxacru_cm(instance, CM_REQUEST_CARD_GET_STATUS, NULL, 0, NULL, 0);
if (ret < 0) {
usb_err(usbatm, "modem failed to initialize: %d\n", ret);
return;
}
}
static int cxacru_find_firmware(struct cxacru_data *instance,
char *phase, const struct firmware **fw_p)
{
struct usbatm_data *usbatm = instance->usbatm;
struct device *dev = &usbatm->usb_intf->dev;
char buf[16];
sprintf(buf, "cxacru-%s.bin", phase);
dbg("cxacru_find_firmware: looking for %s", buf);
if (request_firmware(fw_p, buf, dev)) {
usb_dbg(usbatm, "no stage %s firmware found\n", phase);
return -ENOENT;
}
usb_info(usbatm, "found firmware %s\n", buf);
return 0;
}
static int cxacru_heavy_init(struct usbatm_data *usbatm_instance,
struct usb_interface *usb_intf)
{
const struct firmware *fw, *bp;
struct cxacru_data *instance = usbatm_instance->driver_data;
int ret = cxacru_find_firmware(instance, "fw", &fw);
if (ret) {
usb_warn(usbatm_instance, "firmware (cxacru-fw.bin) unavailable (system misconfigured?)\n");
return ret;
}
if (instance->modem_type->boot_rom_patch) {
ret = cxacru_find_firmware(instance, "bp", &bp);
if (ret) {
usb_warn(usbatm_instance, "boot ROM patch (cxacru-bp.bin) unavailable (system misconfigured?)\n");
release_firmware(fw);
return ret;
}
}
cxacru_upload_firmware(instance, fw, bp);
if (instance->modem_type->boot_rom_patch)
release_firmware(bp);
release_firmware(fw);
ret = cxacru_card_status(instance);
if (ret)
dbg("modem initialisation failed");
else
dbg("done setting up the modem");
return ret;
}
static int cxacru_bind(struct usbatm_data *usbatm_instance,
struct usb_interface *intf, const struct usb_device_id *id)
{
struct cxacru_data *instance;
struct usb_device *usb_dev = interface_to_usbdev(intf);
struct usb_host_endpoint *cmd_ep = usb_dev->ep_in[CXACRU_EP_CMD];
int ret;
instance = kzalloc(sizeof(*instance), GFP_KERNEL);
if (!instance) {
dbg("cxacru_bind: no memory for instance data");
return -ENOMEM;
}
instance->usbatm = usbatm_instance;
instance->modem_type = (struct cxacru_modem_type *) id->driver_info;
mutex_init(&instance->poll_state_serialize);
instance->poll_state = CXPOLL_STOPPED;
instance->line_status = -1;
instance->adsl_status = -1;
mutex_init(&instance->adsl_state_serialize);
instance->rcv_buf = (u8 *) __get_free_page(GFP_KERNEL);
if (!instance->rcv_buf) {
dbg("cxacru_bind: no memory for rcv_buf");
ret = -ENOMEM;
goto fail;
}
instance->snd_buf = (u8 *) __get_free_page(GFP_KERNEL);
if (!instance->snd_buf) {
dbg("cxacru_bind: no memory for snd_buf");
ret = -ENOMEM;
goto fail;
}
instance->rcv_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!instance->rcv_urb) {
dbg("cxacru_bind: no memory for rcv_urb");
ret = -ENOMEM;
goto fail;
}
instance->snd_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!instance->snd_urb) {
dbg("cxacru_bind: no memory for snd_urb");
ret = -ENOMEM;
goto fail;
}
if (!cmd_ep) {
dbg("cxacru_bind: no command endpoint");
ret = -ENODEV;
goto fail;
}
if ((cmd_ep->desc.bmAttributes & USB_ENDPOINT_XFERTYPE_MASK)
== USB_ENDPOINT_XFER_INT) {
usb_fill_int_urb(instance->rcv_urb,
usb_dev, usb_rcvintpipe(usb_dev, CXACRU_EP_CMD),
instance->rcv_buf, PAGE_SIZE,
cxacru_blocking_completion, &instance->rcv_done, 1);
usb_fill_int_urb(instance->snd_urb,
usb_dev, usb_sndintpipe(usb_dev, CXACRU_EP_CMD),
instance->snd_buf, PAGE_SIZE,
cxacru_blocking_completion, &instance->snd_done, 4);
} else {
usb_fill_bulk_urb(instance->rcv_urb,
usb_dev, usb_rcvbulkpipe(usb_dev, CXACRU_EP_CMD),
instance->rcv_buf, PAGE_SIZE,
cxacru_blocking_completion, &instance->rcv_done);
usb_fill_bulk_urb(instance->snd_urb,
usb_dev, usb_sndbulkpipe(usb_dev, CXACRU_EP_CMD),
instance->snd_buf, PAGE_SIZE,
cxacru_blocking_completion, &instance->snd_done);
}
mutex_init(&instance->cm_serialize);
INIT_DELAYED_WORK(&instance->poll_work, cxacru_poll_status);
usbatm_instance->driver_data = instance;
usbatm_instance->flags = (cxacru_card_status(instance) ? 0 : UDSL_SKIP_HEAVY_INIT);
return 0;
fail:
free_page((unsigned long) instance->snd_buf);
free_page((unsigned long) instance->rcv_buf);
usb_free_urb(instance->snd_urb);
usb_free_urb(instance->rcv_urb);
kfree(instance);
return ret;
}
static void cxacru_unbind(struct usbatm_data *usbatm_instance,
struct usb_interface *intf)
{
struct cxacru_data *instance = usbatm_instance->driver_data;
int is_polling = 1;
dbg("cxacru_unbind entered");
if (!instance) {
dbg("cxacru_unbind: NULL instance!");
return;
}
mutex_lock(&instance->poll_state_serialize);
BUG_ON(instance->poll_state == CXPOLL_SHUTDOWN);
if (instance->poll_state == CXPOLL_STOPPED)
is_polling = 0;
instance->poll_state = CXPOLL_SHUTDOWN;
mutex_unlock(&instance->poll_state_serialize);
if (is_polling)
cancel_delayed_work_sync(&instance->poll_work);
usb_kill_urb(instance->snd_urb);
usb_kill_urb(instance->rcv_urb);
usb_free_urb(instance->snd_urb);
usb_free_urb(instance->rcv_urb);
free_page((unsigned long) instance->snd_buf);
free_page((unsigned long) instance->rcv_buf);
kfree(instance);
usbatm_instance->driver_data = NULL;
}
static int cxacru_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *usb_dev = interface_to_usbdev(intf);
char buf[15];
if (usb_dev->descriptor.bDeviceClass == USB_CLASS_VENDOR_SPEC
&& usb_string(usb_dev, usb_dev->descriptor.iProduct,
buf, sizeof(buf)) > 0) {
if (!strcmp(buf, "USB NET CARD")) {
dev_info(&intf->dev, "ignoring cx82310_eth device\n");
return -ENODEV;
}
}
return usbatm_usb_probe(intf, id, &cxacru_driver);
}
