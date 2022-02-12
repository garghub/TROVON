int
ar6000_set_host_app_area(struct ar6_softc *ar)
{
u32 address, data;
struct host_app_area_s host_app_area;
address = TARG_VTOP(ar->arTargetType, HOST_INTEREST_ITEM_ADDRESS(ar, hi_app_host_interest));
if (ar6000_ReadRegDiag(ar->arHifDevice, &address, &data) != 0) {
return A_ERROR;
}
address = TARG_VTOP(ar->arTargetType, data);
host_app_area.wmi_protocol_ver = WMI_PROTOCOL_VERSION;
if (ar6000_WriteDataDiag(ar->arHifDevice, address,
(u8 *)&host_app_area,
sizeof(struct host_app_area_s)) != 0)
{
return A_ERROR;
}
return 0;
}
u32 dbglog_get_debug_hdr_ptr(struct ar6_softc *ar)
{
u32 param;
u32 address;
int status;
address = TARG_VTOP(ar->arTargetType, HOST_INTEREST_ITEM_ADDRESS(ar, hi_dbglog_hdr));
if ((status = ar6000_ReadDataDiag(ar->arHifDevice, address,
(u8 *)&param, 4)) != 0)
{
param = 0;
}
return param;
}
void
ar6000_dbglog_init_done(struct ar6_softc *ar)
{
ar->dbglog_init_done = true;
}
u32 dbglog_get_debug_fragment(s8 *datap, u32 len, u32 limit)
{
s32 *buffer;
u32 count;
u32 numargs;
u32 length;
u32 fraglen;
count = fraglen = 0;
buffer = (s32 *)datap;
length = (limit >> 2);
if (len <= limit) {
fraglen = len;
} else {
while (count < length) {
numargs = DBGLOG_GET_NUMARGS(buffer[count]);
fraglen = (count << 2);
count += numargs + 1;
}
}
return fraglen;
}
void
dbglog_parse_debug_logs(s8 *datap, u32 len)
{
s32 *buffer;
u32 count;
u32 timestamp;
u32 debugid;
u32 moduleid;
u32 numargs;
u32 length;
count = 0;
buffer = (s32 *)datap;
length = (len >> 2);
while (count < length) {
debugid = DBGLOG_GET_DBGID(buffer[count]);
moduleid = DBGLOG_GET_MODULEID(buffer[count]);
numargs = DBGLOG_GET_NUMARGS(buffer[count]);
timestamp = DBGLOG_GET_TIMESTAMP(buffer[count]);
switch (numargs) {
case 0:
AR_DEBUG_PRINTF(ATH_DEBUG_DBG_LOG,("%d %d (%d)\n", moduleid, debugid, timestamp));
break;
case 1:
AR_DEBUG_PRINTF(ATH_DEBUG_DBG_LOG,("%d %d (%d): 0x%x\n", moduleid, debugid,
timestamp, buffer[count+1]));
break;
case 2:
AR_DEBUG_PRINTF(ATH_DEBUG_DBG_LOG,("%d %d (%d): 0x%x, 0x%x\n", moduleid, debugid,
timestamp, buffer[count+1], buffer[count+2]));
break;
default:
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Invalid args: %d\n", numargs));
}
count += numargs + 1;
}
}
int
ar6000_dbglog_get_debug_logs(struct ar6_softc *ar)
{
u32 data[8];
u32 address;
u32 length;
u32 dropped;
u32 firstbuf;
u32 debug_hdr_ptr;
if (!ar->dbglog_init_done) return A_ERROR;
AR6000_SPIN_LOCK(&ar->arLock, 0);
if (ar->dbgLogFetchInProgress) {
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
return A_EBUSY;
}
ar->dbgLogFetchInProgress = true;
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
debug_hdr_ptr = dbglog_get_debug_hdr_ptr(ar);
printk("debug_hdr_ptr: 0x%x\n", debug_hdr_ptr);
if (debug_hdr_ptr) {
address = TARG_VTOP(ar->arTargetType, debug_hdr_ptr);
length = 4 + 4 ;
A_MEMZERO(data, sizeof(data));
ar6000_ReadDataDiag(ar->arHifDevice, address, (u8 *)data, length);
address = TARG_VTOP(ar->arTargetType, data[0] );
firstbuf = address;
dropped = data[1];
length = 4 + 4 + 4 + 4 + 4 + 4 ;
A_MEMZERO(data, sizeof(data));
ar6000_ReadDataDiag(ar->arHifDevice, address, (u8 *)&data, length);
do {
address = TARG_VTOP(ar->arTargetType, data[1] );
length = data[3];
if ((length) && (length <= data[2] )) {
if (ar->log_cnt > (DBGLOG_HOST_LOG_BUFFER_SIZE - length)) {
ar->log_cnt = 0;
}
if(0 != ar6000_ReadDataDiag(ar->arHifDevice, address,
(u8 *)&ar->log_buffer[ar->log_cnt], length))
{
break;
}
ar6000_dbglog_event(ar, dropped, (s8 *)&ar->log_buffer[ar->log_cnt], length);
ar->log_cnt += length;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_DBG_LOG,("Length: %d (Total size: %d)\n",
data[3], data[2]));
}
address = TARG_VTOP(ar->arTargetType, data[0] );
length = 4 + 4 + 4 + 4 + 4 + 4 ;
A_MEMZERO(data, sizeof(data));
if(0 != ar6000_ReadDataDiag(ar->arHifDevice, address,
(u8 *)&data, length))
{
break;
}
} while (address != firstbuf);
}
ar->dbgLogFetchInProgress = false;
return 0;
}
void
ar6000_dbglog_event(struct ar6_softc *ar, u32 dropped,
s8 *buffer, u32 length)
{
#ifdef REPORT_DEBUG_LOGS_TO_APP
#define MAX_WIRELESS_EVENT_SIZE 252
u32 send, sent;
sent = 0;
send = dbglog_get_debug_fragment(&buffer[sent], length - sent,
MAX_WIRELESS_EVENT_SIZE);
while (send) {
sent += send;
send = dbglog_get_debug_fragment(&buffer[sent], length - sent,
MAX_WIRELESS_EVENT_SIZE);
}
#else
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Dropped logs: 0x%x\nDebug info length: %d\n",
dropped, length));
dbglog_parse_debug_logs((s8 *)buffer, length);
#endif
}
static int __init
ar6000_init_module(void)
{
static int probed = 0;
int r;
OSDRV_CALLBACKS osdrvCallbacks;
a_module_debug_support_init();
#ifdef DEBUG
if (debughtc != 0) {
ATH_DEBUG_SET_DEBUG_MASK(htc,debughtc);
}
if (debugbmi != 0) {
ATH_DEBUG_SET_DEBUG_MASK(bmi,debugbmi);
}
if (debughif != 0) {
ATH_DEBUG_SET_DEBUG_MASK(hif,debughif);
}
if (debugdriver != 0) {
ATH_DEBUG_SET_DEBUG_MASK(driver,debugdriver);
}
#endif
A_REGISTER_MODULE_DEBUG_INFO(driver);
A_MEMZERO(&osdrvCallbacks,sizeof(osdrvCallbacks));
osdrvCallbacks.deviceInsertedHandler = ar6000_avail_ev;
osdrvCallbacks.deviceRemovedHandler = ar6000_unavail_ev;
#ifdef CONFIG_PM
osdrvCallbacks.deviceSuspendHandler = ar6000_suspend_ev;
osdrvCallbacks.deviceResumeHandler = ar6000_resume_ev;
osdrvCallbacks.devicePowerChangeHandler = ar6000_power_change_ev;
#endif
#ifdef DEBUG
if(debugflags != 0)
{
g_dbg_flags = debugflags;
}
#endif
if (probed) {
return -ENODEV;
}
probed++;
#ifdef ADAPTIVE_POWER_THROUGHPUT_CONTROL
memset(&aptcTR, 0, sizeof(APTC_TRAFFIC_RECORD));
#endif
r = HIFInit(&osdrvCallbacks);
if (r)
return r;
return 0;
}
static void __exit
ar6000_cleanup_module(void)
{
int i = 0;
struct net_device *ar6000_netdev;
#ifdef ADAPTIVE_POWER_THROUGHPUT_CONTROL
if (timer_pending(&aptcTimer)) {
del_timer_sync(&aptcTimer);
}
#endif
for (i=0; i < MAX_AR6000; i++) {
if (ar6000_devices[i] != NULL) {
ar6000_netdev = ar6000_devices[i];
ar6000_devices[i] = NULL;
ar6000_destroy(ar6000_netdev, 1);
}
}
HIFShutDownDevice(NULL);
a_module_debug_support_cleanup();
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("ar6000_cleanup: success\n"));
}
void
aptcTimerHandler(unsigned long arg)
{
u32 numbytes;
u32 throughput;
struct ar6_softc *ar;
int status;
ar = (struct ar6_softc *)arg;
A_ASSERT(ar != NULL);
A_ASSERT(!timer_pending(&aptcTimer));
AR6000_SPIN_LOCK(&ar->arLock, 0);
numbytes = aptcTR.bytesTransmitted + aptcTR.bytesReceived;
aptcTR.bytesTransmitted = aptcTR.bytesReceived = 0;
throughput = ((numbytes * 8)/APTC_TRAFFIC_SAMPLING_INTERVAL);
if (throughput < APTC_LOWER_THROUGHPUT_THRESHOLD) {
A_ASSERT(ar->arWmiReady == true);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
status = wmi_powermode_cmd(ar->arWmi, REC_POWER);
AR6000_SPIN_LOCK(&ar->arLock, 0);
A_ASSERT(status == 0);
aptcTR.timerScheduled = false;
} else {
A_TIMEOUT_MS(&aptcTimer, APTC_TRAFFIC_SAMPLING_INTERVAL, 0);
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
}
static void
ar6000_alloc_netbufs(A_NETBUF_QUEUE_T *q, u16 num)
{
void * osbuf;
while(num) {
if((osbuf = A_NETBUF_ALLOC(AR6000_BUFFER_SIZE))) {
A_NETBUF_ENQUEUE(q, osbuf);
} else {
break;
}
num--;
}
if(num) {
A_PRINTF("%s(), allocation of netbuf failed", __func__);
}
}
static ssize_t
ar6000_sysfs_bmi_read(struct file *fp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
int index;
struct ar6_softc *ar;
struct hif_device_os_device_info *osDevInfo;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("BMI: Read %d bytes\n", (u32)count));
for (index=0; index < MAX_AR6000; index++) {
ar = (struct ar6_softc *)ar6k_priv(ar6000_devices[index]);
osDevInfo = &ar->osDevInfo;
if (kobj == (&(((struct device *)osDevInfo->pOSDevice)->kobj))) {
break;
}
}
if (index == MAX_AR6000) return 0;
if ((BMIRawRead(ar->arHifDevice, (u8*)buf, count, true)) != 0) {
return 0;
}
return count;
}
static ssize_t
ar6000_sysfs_bmi_write(struct file *fp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
int index;
struct ar6_softc *ar;
struct hif_device_os_device_info *osDevInfo;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("BMI: Write %d bytes\n", (u32)count));
for (index=0; index < MAX_AR6000; index++) {
ar = (struct ar6_softc *)ar6k_priv(ar6000_devices[index]);
osDevInfo = &ar->osDevInfo;
if (kobj == (&(((struct device *)osDevInfo->pOSDevice)->kobj))) {
break;
}
}
if (index == MAX_AR6000) return 0;
if ((BMIRawWrite(ar->arHifDevice, (u8*)buf, count)) != 0) {
return 0;
}
return count;
}
static int
ar6000_sysfs_bmi_init(struct ar6_softc *ar)
{
int status;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("BMI: Creating sysfs entry\n"));
A_MEMZERO(&ar->osDevInfo, sizeof(struct hif_device_os_device_info));
status = HIFConfigureDevice(ar->arHifDevice,
HIF_DEVICE_GET_OS_DEVICE,
&ar->osDevInfo,
sizeof(struct hif_device_os_device_info));
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI: Failed to get OS device info from HIF\n"));
return A_ERROR;
}
if ((sysfs_create_bin_file(&(((struct device *)ar->osDevInfo.pOSDevice)->kobj), &bmi_attr)) < 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMI: Failed to create entry for bmi in sysfs filesystem\n"));
return A_ERROR;
}
return 0;
}
static void
ar6000_sysfs_bmi_deinit(struct ar6_softc *ar)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("BMI: Deleting sysfs entry\n"));
sysfs_remove_bin_file(&(((struct device *)ar->osDevInfo.pOSDevice)->kobj), &bmi_attr);
}
static
void calculate_crc(u32 TargetType, u8 *eeprom_data)
{
u16 *ptr_crc;
u16 *ptr16_eeprom;
u16 checksum;
u32 i;
u32 eeprom_size;
if (TargetType == TARGET_TYPE_AR6001)
{
eeprom_size = 512;
ptr_crc = (u16 *)eeprom_data;
}
else if (TargetType == TARGET_TYPE_AR6003)
{
eeprom_size = 1024;
ptr_crc = (u16 *)((u8 *)eeprom_data + 0x04);
}
else
{
eeprom_size = 768;
ptr_crc = (u16 *)((u8 *)eeprom_data + 0x04);
}
*ptr_crc = 0;
checksum = 0;
ptr16_eeprom = (u16 *)eeprom_data;
for (i = 0;i < eeprom_size; i += 2)
{
checksum = checksum ^ (*ptr16_eeprom);
ptr16_eeprom++;
}
checksum = 0xFFFF ^ checksum;
*ptr_crc = checksum;
}
static void
ar6000_softmac_update(struct ar6_softc *ar, u8 *eeprom_data, size_t size)
{
const char *source = "random generated";
const struct firmware *softmac_entry;
u8 *ptr_mac;
switch (ar->arTargetType) {
case TARGET_TYPE_AR6002:
ptr_mac = (u8 *)((u8 *)eeprom_data + AR6002_MAC_ADDRESS_OFFSET);
break;
case TARGET_TYPE_AR6003:
ptr_mac = (u8 *)((u8 *)eeprom_data + AR6003_MAC_ADDRESS_OFFSET);
break;
default:
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Invalid Target Type\n"));
return;
}
printk(KERN_DEBUG "MAC from EEPROM %pM\n", ptr_mac);
ptr_mac[0] = 0;
ptr_mac[1] = 0x03;
ptr_mac[2] = 0x7F;
ptr_mac[3] = random32() & 0xff;
ptr_mac[4] = random32() & 0xff;
ptr_mac[5] = random32() & 0xff;
if ((A_REQUEST_FIRMWARE(&softmac_entry, "softmac", ((struct device *)ar->osDevInfo.pOSDevice))) == 0)
{
char *macbuf = A_MALLOC_NOWAIT(softmac_entry->size+1);
if (macbuf) {
unsigned int softmac[6];
memcpy(macbuf, softmac_entry->data, softmac_entry->size);
macbuf[softmac_entry->size] = '\0';
if (sscanf(macbuf, "%02x:%02x:%02x:%02x:%02x:%02x",
&softmac[0], &softmac[1], &softmac[2],
&softmac[3], &softmac[4], &softmac[5])==6) {
int i;
for (i=0; i<6; ++i) {
ptr_mac[i] = softmac[i] & 0xff;
}
source = "softmac file";
}
kfree(macbuf);
}
A_RELEASE_FIRMWARE(softmac_entry);
}
printk(KERN_DEBUG "MAC from %s %pM\n", source, ptr_mac);
calculate_crc(ar->arTargetType, eeprom_data);
}
static int
ar6000_transfer_bin_file(struct ar6_softc *ar, AR6K_BIN_FILE file, u32 address, bool compressed)
{
int status;
const char *filename;
const struct firmware *fw_entry;
u32 fw_entry_size;
switch (file) {
case AR6K_OTP_FILE:
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_OTP_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_OTP_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV3_VERSION) {
filename = AR6003_REV3_OTP_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown firmware revision: %d\n", ar->arVersion.target_ver));
return A_ERROR;
}
break;
case AR6K_FIRMWARE_FILE:
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV3_VERSION) {
filename = AR6003_REV3_FIRMWARE_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown firmware revision: %d\n", ar->arVersion.target_ver));
return A_ERROR;
}
if (eppingtest) {
bypasswmi = true;
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_EPPING_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_EPPING_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV3_VERSION) {
filename = AR6003_REV3_EPPING_FIRMWARE_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("eppingtest : unsupported firmware revision: %d\n",
ar->arVersion.target_ver));
return A_ERROR;
}
compressed = false;
}
#ifdef CONFIG_HOST_TCMD_SUPPORT
if(testmode) {
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_TCMD_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_TCMD_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV3_VERSION) {
filename = AR6003_REV3_TCMD_FIRMWARE_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown firmware revision: %d\n", ar->arVersion.target_ver));
return A_ERROR;
}
compressed = false;
}
#endif
#ifdef HTC_RAW_INTERFACE
if (!eppingtest && bypasswmi) {
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_ART_FIRMWARE_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_ART_FIRMWARE_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown firmware revision: %d\n", ar->arVersion.target_ver));
return A_ERROR;
}
compressed = false;
}
#endif
break;
case AR6K_PATCH_FILE:
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_PATCH_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_PATCH_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV3_VERSION) {
filename = AR6003_REV3_PATCH_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown firmware revision: %d\n", ar->arVersion.target_ver));
return A_ERROR;
}
break;
case AR6K_BOARD_DATA_FILE:
if (ar->arVersion.target_ver == AR6003_REV1_VERSION) {
filename = AR6003_REV1_BOARD_DATA_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
filename = AR6003_REV2_BOARD_DATA_FILE;
} else if (ar->arVersion.target_ver == AR6003_REV3_VERSION) {
filename = AR6003_REV3_BOARD_DATA_FILE;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown firmware revision: %d\n", ar->arVersion.target_ver));
return A_ERROR;
}
break;
default:
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unknown file type: %d\n", file));
return A_ERROR;
}
if ((A_REQUEST_FIRMWARE(&fw_entry, filename, ((struct device *)ar->osDevInfo.pOSDevice))) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Failed to get %s\n", filename));
return A_ENOENT;
}
#ifdef SOFTMAC_FILE_USED
if (file==AR6K_BOARD_DATA_FILE && fw_entry->data) {
ar6000_softmac_update(ar, (u8 *)fw_entry->data, fw_entry->size);
}
#endif
fw_entry_size = fw_entry->size;
if ((file==AR6K_BOARD_DATA_FILE) && (fw_entry->data)) {
u32 board_ext_address;
u32 board_ext_data_size;
u32 board_data_size;
board_ext_data_size = (((ar)->arTargetType == TARGET_TYPE_AR6002) ? AR6002_BOARD_EXT_DATA_SZ : \
(((ar)->arTargetType == TARGET_TYPE_AR6003) ? AR6003_BOARD_EXT_DATA_SZ : 0));
board_data_size = (((ar)->arTargetType == TARGET_TYPE_AR6002) ? AR6002_BOARD_DATA_SZ : \
(((ar)->arTargetType == TARGET_TYPE_AR6003) ? AR6003_BOARD_DATA_SZ : 0));
bmifn(BMIReadMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_board_ext_data), (u8 *)&board_ext_address, 4));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("Board extended Data download address: 0x%x\n", board_ext_address));
if ((board_ext_address) && (fw_entry->size == (board_data_size + board_ext_data_size))) {
u32 param;
status = BMIWriteMemory(ar->arHifDevice, board_ext_address, (u8 *)(fw_entry->data + board_data_size), board_ext_data_size);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI operation failed: %d\n", __LINE__));
A_RELEASE_FIRMWARE(fw_entry);
return A_ERROR;
}
param = (board_ext_data_size << 16) | 1;
bmifn(BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_board_ext_data_config),
(unsigned char *)&param, 4));
}
fw_entry_size = board_data_size;
}
if (compressed) {
status = BMIFastDownload(ar->arHifDevice, address, (u8 *)fw_entry->data, fw_entry_size);
} else {
status = BMIWriteMemory(ar->arHifDevice, address, (u8 *)fw_entry->data, fw_entry_size);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI operation failed: %d\n", __LINE__));
A_RELEASE_FIRMWARE(fw_entry);
return A_ERROR;
}
A_RELEASE_FIRMWARE(fw_entry);
return 0;
}
int
ar6000_update_bdaddr(struct ar6_softc *ar)
{
if (setupbtdev != 0) {
u32 address;
if (BMIReadMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_board_data), (u8 *)&address, 4) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for hi_board_data failed\n"));
return A_ERROR;
}
if (BMIReadMemory(ar->arHifDevice, address + BDATA_BDADDR_OFFSET, (u8 *)ar->bdaddr, 6) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for BD address failed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BDADDR 0x%x:0x%x:0x%x:0x%x:0x%x:0x%x\n", ar->bdaddr[0],
ar->bdaddr[1], ar->bdaddr[2], ar->bdaddr[3],
ar->bdaddr[4], ar->bdaddr[5]));
}
return 0;
}
int
ar6000_sysfs_bmi_get_config(struct ar6_softc *ar, u32 mode)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("BMI: Requesting device specific configuration\n"));
if (mode == WLAN_INIT_MODE_UDEV) {
char version[16];
const struct firmware *fw_entry;
sprintf(version, "%2.2x", ar->arVersion.target_ver);
if ((A_REQUEST_FIRMWARE(&fw_entry, version, ((struct device *)ar->osDevInfo.pOSDevice))) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI: Failure to get configuration for target version: %s\n", version));
return A_ERROR;
}
A_RELEASE_FIRMWARE(fw_entry);
} else {
int status;
u32 param, options, sleep, address;
address = MBOX_BASE_ADDRESS + LOCAL_SCRATCH_ADDRESS;
bmifn(BMIReadSOCRegister(ar->arHifDevice, address, &param));
options = param;
param |= AR6K_OPTION_SLEEP_DISABLE;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
address = RTC_BASE_ADDRESS + SYSTEM_SLEEP_ADDRESS;
bmifn(BMIReadSOCRegister(ar->arHifDevice, address, &param));
sleep = param;
param |= WLAN_SYSTEM_SLEEP_DISABLE_SET(1);
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("old options: %d, old sleep: %d\n", options, sleep));
if (ar->arTargetType == TARGET_TYPE_AR6003) {
bmifn(BMIWriteSOCRegister(ar->arHifDevice, ANALOG_INTF_BASE_ADDRESS + 0x284, 0xF9104001));
param = CPU_CLOCK_STANDARD_SET(1);
} else {
param = CPU_CLOCK_STANDARD_SET(0);
}
address = RTC_BASE_ADDRESS + CPU_CLOCK_ADDRESS;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
param = 0;
if (ar->arTargetType == TARGET_TYPE_AR6002) {
bmifn(BMIReadMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_ext_clk_detected), (u8 *)&param, 4));
}
if (param != 1) {
address = RTC_BASE_ADDRESS + LPO_CAL_ADDRESS;
param = LPO_CAL_ENABLE_SET(1);
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
}
if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("AR6K: Temporary WAR to avoid SDIO CRC error\n"));
param = 0x20;
address = GPIO_BASE_ADDRESS + GPIO_PIN10_ADDRESS;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
address = GPIO_BASE_ADDRESS + GPIO_PIN11_ADDRESS;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
address = GPIO_BASE_ADDRESS + GPIO_PIN12_ADDRESS;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
address = GPIO_BASE_ADDRESS + GPIO_PIN13_ADDRESS;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
}
#ifdef FORCE_INTERNAL_CLOCK
if (ar->arTargetType == TARGET_TYPE_AR6003) {
param = 0;
bmifn(BMIWriteMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_ext_clk_detected), (u8 *)&param, 4));
address = RTC_BASE_ADDRESS + CLOCK_CONTROL_ADDRESS;
bmifn(BMIReadSOCRegister(ar->arHifDevice, address, &param));
param &= (~CLOCK_CONTROL_LF_CLK32_SET(1));
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
}
#endif
if (ar->arTargetType == TARGET_TYPE_AR6003) {
bmifn(BMIReadMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_board_data), (u8 *)&address, 4));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("Board Data download address: 0x%x\n", address));
if ((ar6000_transfer_bin_file(ar, AR6K_BOARD_DATA_FILE, address, false)) != 0) {
return A_ERROR;
}
param = 1;
bmifn(BMIWriteMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_board_data_initialized), (u8 *)&param, 4));
AR6K_APP_LOAD_ADDRESS(address, ar->arVersion.target_ver);
if (ar->arVersion.target_ver == AR6003_REV3_VERSION)
address = 0x1234;
status = ar6000_transfer_bin_file(ar, AR6K_OTP_FILE, address, true);
if (status == 0) {
param = 0;
AR6K_APP_START_OVERRIDE_ADDRESS(address, ar->arVersion.target_ver);
bmifn(BMIExecute(ar->arHifDevice, address, &param));
} else if (status != A_ENOENT) {
return A_ERROR;
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Programming of board data for chip %d not supported\n", ar->arTargetType));
return A_ERROR;
}
AR6K_APP_LOAD_ADDRESS(address, ar->arVersion.target_ver);
if (ar->arVersion.target_ver == AR6003_REV3_VERSION)
address = 0x1234;
if ((ar6000_transfer_bin_file(ar, AR6K_FIRMWARE_FILE, address, true)) != 0) {
return A_ERROR;
}
AR6K_APP_START_OVERRIDE_ADDRESS(address, ar->arVersion.target_ver);
bmifn(BMISetAppStart(ar->arHifDevice, address));
if(ar->arTargetType == TARGET_TYPE_AR6003) {
AR6K_DATASET_PATCH_ADDRESS(address, ar->arVersion.target_ver);
if ((ar6000_transfer_bin_file(ar, AR6K_PATCH_FILE,
address, false)) != 0)
return A_ERROR;
param = address;
bmifn(BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_dset_list_head),
(unsigned char *)&param, 4));
}
address = RTC_BASE_ADDRESS + SYSTEM_SLEEP_ADDRESS;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, sleep));
address = MBOX_BASE_ADDRESS + LOCAL_SCRATCH_ADDRESS;
param = options | 0x20;
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
if (ar->arTargetType == TARGET_TYPE_AR6003) {
#ifndef CONFIG_AR600x_DEBUG_UART_TX_PIN
#define CONFIG_AR600x_DEBUG_UART_TX_PIN 8
#endif
param = CONFIG_AR600x_DEBUG_UART_TX_PIN;
bmifn(BMIWriteMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_dbg_uart_txpin), (u8 *)&param, 4));
#if (CONFIG_AR600x_DEBUG_UART_TX_PIN == 23)
{
address = GPIO_BASE_ADDRESS + CLOCK_GPIO_ADDRESS;
bmifn(BMIReadSOCRegister(ar->arHifDevice, address, &param));
param |= CLOCK_GPIO_BT_CLK_OUT_EN_SET(1);
bmifn(BMIWriteSOCRegister(ar->arHifDevice, address, param));
}
#endif
#ifdef ATH6KL_CONFIG_GPIO_BT_RESET
#define CONFIG_AR600x_BT_RESET_PIN 0x16
param = CONFIG_AR600x_BT_RESET_PIN;
bmifn(BMIWriteMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_hci_uart_support_pins), (u8 *)&param, 4));
#endif
#ifndef CONFIG_ATH6KL_BT_UART_FC_POLARITY
#define CONFIG_ATH6KL_BT_UART_FC_POLARITY 0
#endif
#if (CONFIG_ATH6KL_BT_UART_FC_POLARITY == 1)
if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
param = ((CONFIG_ATH6KL_BT_UART_FC_POLARITY << 1) & 0x2);
bmifn(BMIWriteMemory(ar->arHifDevice, HOST_INTEREST_ITEM_ADDRESS(ar, hi_hci_uart_pwr_mgmt_params), (u8 *)&param, 4));
}
#endif
}
#ifdef HTC_RAW_INTERFACE
if (!eppingtest && bypasswmi) {
resetok = 0;
msleep(1000);
}
#endif
}
return 0;
}
int
ar6000_configure_target(struct ar6_softc *ar)
{
u32 param;
if (enableuartprint) {
param = 1;
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_serial_enable),
(u8 *)&param,
4)!= 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for enableuartprint failed \n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Serial console prints enabled\n"));
}
param = HTC_PROTOCOL_VERSION;
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_app_host_interest),
(u8 *)&param,
4)!= 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for htc version failed \n"));
return A_ERROR;
}
#ifdef CONFIG_HOST_TCMD_SUPPORT
if(testmode) {
ar->arTargetMode = AR6000_TCMD_MODE;
}else {
ar->arTargetMode = AR6000_WLAN_MODE;
}
#endif
if (enabletimerwar) {
u32 param;
if (BMIReadMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_option_flag),
(u8 *)&param,
4)!= 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for enabletimerwar failed \n"));
return A_ERROR;
}
param |= HI_OPTION_TIMER_WAR;
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_option_flag),
(u8 *)&param,
4) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for enabletimerwar failed \n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Timer WAR enabled\n"));
}
{
u32 param;
if (BMIReadMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_option_flag),
(u8 *)&param,
4)!= 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for setting fwmode failed \n"));
return A_ERROR;
}
param |= (num_device << HI_OPTION_NUM_DEV_SHIFT);
param |= (fwmode << HI_OPTION_FW_MODE_SHIFT);
param |= (mac_addr_method << HI_OPTION_MAC_ADDR_METHOD_SHIFT);
param |= (firmware_bridge << HI_OPTION_FW_BRIDGE_SHIFT);
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_option_flag),
(u8 *)&param,
4) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for setting fwmode failed \n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Firmware mode set\n"));
}
#ifdef ATH6KL_DISABLE_TARGET_DBGLOGS
{
u32 param;
if (BMIReadMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_option_flag),
(u8 *)&param,
4)!= 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIReadMemory for disabling debug logs failed\n"));
return A_ERROR;
}
param |= HI_OPTION_DISABLE_DBGLOG;
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_option_flag),
(u8 *)&param,
4) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMIWriteMemory for HI_OPTION_DISABLE_DBGLOG\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("Firmware mode set\n"));
}
#endif
if (ar->arTargetType == TARGET_TYPE_AR6003) {
u32 ramReservedSz;
if (ar->arVersion.target_ver == AR6003_REV2_VERSION) {
param = AR6003_REV2_BOARD_EXT_DATA_ADDRESS;
ramReservedSz = AR6003_REV2_RAM_RESERVE_SIZE;
} else {
param = AR6003_REV3_BOARD_EXT_DATA_ADDRESS;
ramReservedSz = AR6003_REV3_RAM_RESERVE_SIZE;
}
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar, hi_board_ext_data),
(u8 *)&param, 4) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("BMIWriteMemory for "
"hi_board_ext_data failed\n"));
return A_ERROR;
}
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar,
hi_end_RAM_reserve_sz),
(u8 *)&ramReservedSz, 4) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR ,
("BMIWriteMemory for "
"hi_end_RAM_reserve_sz failed\n"));
return A_ERROR;
}
}
if (ar6000_set_htc_params(ar->arHifDevice, ar->arTargetType,
mbox_yield_limit, 0)) {
return A_ERROR;
}
if (setupbtdev != 0) {
if (ar6000_set_hci_bridge_flags(ar->arHifDevice,
ar->arTargetType,
setupbtdev)) {
return A_ERROR;
}
}
return 0;
}
static void
init_netdev(struct net_device *dev, char *name)
{
dev->netdev_ops = &ar6000_netdev_ops;
dev->watchdog_timeo = AR6000_TX_TIMEOUT;
if (processDot11Hdr) {
dev->hard_header_len = sizeof(struct ieee80211_qosframe) + sizeof(ATH_LLC_SNAP_HDR) + sizeof(WMI_DATA_HDR) + HTC_HEADER_LEN + WMI_MAX_TX_META_SZ + LINUX_HACK_FUDGE_FACTOR;
} else {
dev->hard_header_len = ETH_HLEN + sizeof(ATH_LLC_SNAP_HDR) +
sizeof(WMI_DATA_HDR) + HTC_HEADER_LEN + WMI_MAX_TX_META_SZ + LINUX_HACK_FUDGE_FACTOR;
}
if (name[0])
{
strcpy(dev->name, name);
}
#ifdef CONFIG_CHECKSUM_OFFLOAD
if(csumOffload){
dev->features |= NETIF_F_IP_CSUM;
}
#endif
return;
}
static int __ath6kl_init_netdev(struct net_device *dev)
{
int r;
rtnl_lock();
r = ar6000_init(dev);
rtnl_unlock();
if (r) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_avail: ar6000_init\n"));
return r;
}
return 0;
}
static int ath6kl_init_netdev_wmi(struct net_device *dev)
{
if (!eppingtest && bypasswmi)
return 0;
return __ath6kl_init_netdev(dev);
}
static int ath6kl_init_netdev_wmi(struct net_device *dev)
{
return __ath6kl_init_netdev(dev);
}
static int ath6kl_init_netdev(struct ar6_softc *ar)
{
int r;
r = ar6000_sysfs_bmi_get_config(ar, wlaninitmode);
if (r) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("ar6000_avail: "
"ar6000_sysfs_bmi_get_config failed\n"));
return r;
}
return ath6kl_init_netdev_wmi(ar->arNetDev);
}
static int
ar6000_avail_ev(void *context, void *hif_handle)
{
int i;
struct net_device *dev;
void *ar_netif;
struct ar6_softc *ar;
int device_index = 0;
struct htc_init_info htcInfo;
struct wireless_dev *wdev;
int r = 0;
struct hif_device_os_device_info osDevInfo;
memset(&osDevInfo, 0, sizeof(osDevInfo));
if (HIFConfigureDevice(hif_handle, HIF_DEVICE_GET_OS_DEVICE,
&osDevInfo, sizeof(osDevInfo))) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s: Failed to get OS device instance\n", __func__));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("ar6000_available\n"));
for (i=0; i < MAX_AR6000; i++) {
if (ar6000_devices[i] == NULL) {
break;
}
}
if (i == MAX_AR6000) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_available: max devices reached\n"));
return A_ERROR;
}
device_index = i;
wdev = ar6k_cfg80211_init(osDevInfo.pOSDevice);
if (IS_ERR(wdev)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("%s: ar6k_cfg80211_init failed\n", __func__));
return A_ERROR;
}
ar_netif = wdev_priv(wdev);
if (ar_netif == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("%s: Can't allocate ar6k priv memory\n", __func__));
return A_ERROR;
}
A_MEMZERO(ar_netif, sizeof(struct ar6_softc));
ar = (struct ar6_softc *)ar_netif;
ar->wdev = wdev;
wdev->iftype = NL80211_IFTYPE_STATION;
dev = alloc_netdev_mq(0, "wlan%d", ether_setup, 1);
if (!dev) {
printk(KERN_CRIT "AR6K: no memory for network device instance\n");
ar6k_cfg80211_deinit(ar);
return A_ERROR;
}
dev->ieee80211_ptr = wdev;
SET_NETDEV_DEV(dev, wiphy_dev(wdev->wiphy));
wdev->netdev = dev;
ar->arNetworkType = INFRA_NETWORK;
ar->smeState = SME_DISCONNECTED;
ar->arAutoAuthStage = AUTH_IDLE;
init_netdev(dev, ifname);
ar->arNetDev = dev;
ar->arHifDevice = hif_handle;
ar->arWlanState = WLAN_ENABLED;
ar->arDeviceIndex = device_index;
ar->arWlanPowerState = WLAN_POWER_STATE_ON;
ar->arWlanOff = false;
#ifdef CONFIG_PM
ar->arWowState = WLAN_WOW_STATE_NONE;
ar->arBTOff = true;
ar->arBTSharing = WLAN_CONFIG_BT_SHARING;
ar->arWlanOffConfig = WLAN_CONFIG_WLAN_OFF;
ar->arSuspendConfig = WLAN_CONFIG_PM_SUSPEND;
ar->arWow2Config = WLAN_CONFIG_PM_WOW2;
#endif
A_INIT_TIMER(&ar->arHBChallengeResp.timer, ar6000_detect_error, dev);
ar->arHBChallengeResp.seqNum = 0;
ar->arHBChallengeResp.outstanding = false;
ar->arHBChallengeResp.missCnt = 0;
ar->arHBChallengeResp.frequency = AR6000_HB_CHALLENGE_RESP_FREQ_DEFAULT;
ar->arHBChallengeResp.missThres = AR6000_HB_CHALLENGE_RESP_MISS_THRES_DEFAULT;
ar6000_init_control_info(ar);
init_waitqueue_head(&arEvent);
sema_init(&ar->arSem, 1);
ar->bIsDestroyProgress = false;
INIT_HTC_PACKET_QUEUE(&ar->amsdu_rx_buffer_queue);
#ifdef ADAPTIVE_POWER_THROUGHPUT_CONTROL
A_INIT_TIMER(&aptcTimer, aptcTimerHandler, ar);
#endif
A_INIT_TIMER(&ar->disconnect_timer, disconnect_timer_handler, dev);
BMIInit();
ar6000_sysfs_bmi_init(ar);
{
struct bmi_target_info targ_info;
r = BMIGetTargetInfo(ar->arHifDevice, &targ_info);
if (r)
goto avail_ev_failed;
ar->arVersion.target_ver = targ_info.target_ver;
ar->arTargetType = targ_info.target_type;
wdev->wiphy->hw_version = targ_info.target_ver;
}
r = ar6000_configure_target(ar);
if (r)
goto avail_ev_failed;
A_MEMZERO(&htcInfo,sizeof(htcInfo));
htcInfo.pContext = ar;
htcInfo.TargetFailure = ar6000_target_failure;
ar->arHtcTarget = HTCCreate(ar->arHifDevice,&htcInfo);
if (!ar->arHtcTarget) {
r = -ENOMEM;
goto avail_ev_failed;
}
spin_lock_init(&ar->arLock);
#ifdef WAPI_ENABLE
ar->arWapiEnable = 0;
#endif
if(csumOffload){
ar->rxMetaVersion=WMI_META_VERSION_2;
}
ar->aggr_cntxt = aggr_init(ar6000_alloc_netbufs);
if (!ar->aggr_cntxt) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s() Failed to initialize aggr.\n", __func__));
r = -ENOMEM;
goto avail_ev_failed;
}
aggr_register_rx_dispatcher(ar->aggr_cntxt, (void *)dev, ar6000_deliver_frames_to_nw_stack);
HIFClaimDevice(ar->arHifDevice, ar);
ar6000_devices[device_index] = dev;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("BMI enabled: %d\n", wlaninitmode));
if ((wlaninitmode == WLAN_INIT_MODE_UDEV) ||
(wlaninitmode == WLAN_INIT_MODE_DRV)) {
r = ath6kl_init_netdev(ar);
if (r)
goto avail_ev_failed;
}
r = register_netdev(dev);
if (r) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_avail: register_netdev failed\n"));
ar6000_destroy(dev, 0);
return r;
}
is_netdev_registered = 1;
#ifdef CONFIG_AP_VIRTUAL_ADAPTER_SUPPORT
arApNetDev = NULL;
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("ar6000_avail: name=%s hifdevice=0x%lx, dev=0x%lx (%d), ar=0x%lx\n",
dev->name, (unsigned long)ar->arHifDevice, (unsigned long)dev, device_index,
(unsigned long)ar));
avail_ev_failed :
if (r)
ar6000_sysfs_bmi_deinit(ar);
return r;
}
static void ar6000_target_failure(void *Instance, int Status)
{
struct ar6_softc *ar = (struct ar6_softc *)Instance;
WMI_TARGET_ERROR_REPORT_EVENT errEvent;
static bool sip = false;
if (Status != 0) {
printk(KERN_ERR "ar6000_target_failure: target asserted \n");
if (timer_pending(&ar->arHBChallengeResp.timer)) {
A_UNTIMEOUT(&ar->arHBChallengeResp.timer);
}
ar6000_dump_target_assert_info(ar->arHifDevice,ar->arTargetType);
ar6000_dbglog_get_debug_logs(ar);
if (!sip) {
sip = true;
errEvent.errorVal = WMI_TARGET_COM_ERR |
WMI_TARGET_FATAL_ERR;
}
}
}
static int
ar6000_unavail_ev(void *context, void *hif_handle)
{
struct ar6_softc *ar = (struct ar6_softc *)context;
ar6000_devices[ar->arDeviceIndex] = NULL;
ar6000_destroy(ar->arNetDev, 1);
return 0;
}
void
ar6000_restart_endpoint(struct net_device *dev)
{
int status = 0;
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
BMIInit();
do {
if ( (status=ar6000_configure_target(ar))!= 0)
break;
if ( (status=ar6000_sysfs_bmi_get_config(ar, wlaninitmode)) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_avail: ar6000_sysfs_bmi_get_config failed\n"));
break;
}
rtnl_lock();
status = (ar6000_init(dev)==0) ? 0 : A_ERROR;
rtnl_unlock();
if (status) {
break;
}
if (ar->arSsidLen && ar->arWlanState == WLAN_ENABLED) {
ar6000_connect_to_ap(ar);
}
} while (0);
if (status== 0) {
return;
}
ar6000_devices[ar->arDeviceIndex] = NULL;
ar6000_destroy(ar->arNetDev, 1);
}
void
ar6000_stop_endpoint(struct net_device *dev, bool keepprofile, bool getdbglogs)
{
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
netif_stop_queue(dev);
if (ar->arWmiReady == true)
{
if (!bypasswmi)
{
bool disconnectIssued;
disconnectIssued = (ar->arConnected) || (ar->arConnectPending);
ar6000_disconnect(ar);
if (!keepprofile) {
ar6000_init_profile_info(ar);
}
A_UNTIMEOUT(&ar->disconnect_timer);
if (getdbglogs) {
ar6000_dbglog_get_debug_logs(ar);
}
ar->arWmiReady = false;
wmi_shutdown(ar->arWmi);
ar->arWmiEnabled = false;
ar->arWmi = NULL;
if (disconnectIssued) {
if(ar->arNetworkType & AP_NETWORK) {
ar6000_disconnect_event(ar, DISCONNECT_CMD, bcast_mac, 0, NULL, 0);
} else {
ar6000_disconnect_event(ar, DISCONNECT_CMD, ar->arBssid, 0, NULL, 0);
}
}
ar->user_savedkeys_stat = USER_SAVEDKEYS_STAT_INIT;
ar->user_key_ctrl = 0;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("%s(): WMI stopped\n", __func__));
}
else
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("%s(): WMI not ready 0x%lx 0x%lx\n",
__func__, (unsigned long) ar, (unsigned long) ar->arWmi));
if(ar->arWmiEnabled == true)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("%s(): Shut down WMI\n", __func__));
wmi_shutdown(ar->arWmi);
ar->arWmiEnabled = false;
ar->arWmi = NULL;
}
}
if (ar->arHtcTarget != NULL) {
#ifdef EXPORT_HCI_BRIDGE_INTERFACE
if (NULL != ar6kHciTransCallbacks.cleanupTransport) {
ar6kHciTransCallbacks.cleanupTransport(NULL);
}
#else
if (NULL != ar->exitCallback) {
struct ar3k_config_info ar3kconfig;
int status;
A_MEMZERO(&ar3kconfig,sizeof(ar3kconfig));
ar6000_set_default_ar3kconfig(ar, (void *)&ar3kconfig);
status = ar->exitCallback(&ar3kconfig);
if (0 != status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to reset AR3K baud rate! \n"));
}
}
if (setuphci)
ar6000_cleanup_hci(ar);
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,(" Shutting down HTC .... \n"));
HTCStop(ar->arHtcTarget);
}
if (resetok) {
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,(" Attempting to reset target on instance destroy.... \n"));
if (ar->arHifDevice != NULL) {
bool coldReset = (ar->arTargetType == TARGET_TYPE_AR6003) ? true: false;
ar6000_reset_device(ar->arHifDevice, ar->arTargetType, true, coldReset);
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,(" Host does not want target reset. \n"));
}
ar6000_cookie_cleanup(ar);
ar6000_cleanup_amsdu_rxbufs(ar);
}
void
ar6000_destroy(struct net_device *dev, unsigned int unregister)
{
struct ar6_softc *ar;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("+ar6000_destroy \n"));
if((dev == NULL) || ((ar = ar6k_priv(dev)) == NULL))
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s(): Failed to get device structure.\n", __func__));
return;
}
ar->bIsDestroyProgress = true;
if (down_interruptible(&ar->arSem)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s(): down_interruptible failed \n", __func__));
return;
}
if (ar->arWlanPowerState != WLAN_POWER_STATE_CUT_PWR) {
ar6000_stop_endpoint(dev, false, true);
}
ar->arWlanState = WLAN_DISABLED;
if (ar->arHtcTarget != NULL) {
HTCDestroy(ar->arHtcTarget);
}
if (ar->arHifDevice != NULL) {
HIFReleaseDevice(ar->arHifDevice);
HIFShutDownDevice(ar->arHifDevice);
}
aggr_module_destroy(ar->aggr_cntxt);
ar6000_cookie_cleanup(ar);
ar6000_cleanup_amsdu_rxbufs(ar);
ar6000_sysfs_bmi_deinit(ar);
BMICleanup();
memset(tx_attempt, 0, sizeof(tx_attempt));
memset(tx_post, 0, sizeof(tx_post));
memset(tx_complete, 0, sizeof(tx_complete));
#ifdef HTC_RAW_INTERFACE
if (ar->arRawHtc) {
kfree(ar->arRawHtc);
ar->arRawHtc = NULL;
}
#endif
if (unregister && is_netdev_registered) {
unregister_netdev(dev);
is_netdev_registered = 0;
}
free_netdev(dev);
ar6k_cfg80211_deinit(ar);
#ifdef CONFIG_AP_VIRTUL_ADAPTER_SUPPORT
ar6000_remove_ap_interface();
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("-ar6000_destroy \n"));
}
static void disconnect_timer_handler(unsigned long ptr)
{
struct net_device *dev = (struct net_device *)ptr;
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
A_UNTIMEOUT(&ar->disconnect_timer);
ar6000_init_profile_info(ar);
ar6000_disconnect(ar);
}
static void ar6000_detect_error(unsigned long ptr)
{
struct net_device *dev = (struct net_device *)ptr;
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
WMI_TARGET_ERROR_REPORT_EVENT errEvent;
AR6000_SPIN_LOCK(&ar->arLock, 0);
if (ar->arHBChallengeResp.outstanding) {
ar->arHBChallengeResp.missCnt++;
} else {
ar->arHBChallengeResp.missCnt = 0;
}
if (ar->arHBChallengeResp.missCnt > ar->arHBChallengeResp.missThres) {
ar->arHBChallengeResp.missCnt = 0;
ar->arHBChallengeResp.seqNum = 0;
errEvent.errorVal = WMI_TARGET_COM_ERR | WMI_TARGET_FATAL_ERR;
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
return;
}
ar->arHBChallengeResp.seqNum++;
ar->arHBChallengeResp.outstanding = true;
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (wmi_get_challenge_resp_cmd(ar->arWmi, ar->arHBChallengeResp.seqNum, DRV_HB_CHALLENGE) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to send heart beat challenge\n"));
}
A_TIMEOUT_MS(&ar->arHBChallengeResp.timer, ar->arHBChallengeResp.frequency * 1000, 0);
}
void ar6000_init_profile_info(struct ar6_softc *ar)
{
ar->arSsidLen = 0;
A_MEMZERO(ar->arSsid, sizeof(ar->arSsid));
switch(fwmode) {
case HI_OPTION_FW_MODE_IBSS:
ar->arNetworkType = ar->arNextMode = ADHOC_NETWORK;
break;
case HI_OPTION_FW_MODE_BSS_STA:
ar->arNetworkType = ar->arNextMode = INFRA_NETWORK;
break;
case HI_OPTION_FW_MODE_AP:
ar->arNetworkType = ar->arNextMode = AP_NETWORK;
break;
}
ar->arDot11AuthMode = OPEN_AUTH;
ar->arAuthMode = NONE_AUTH;
ar->arPairwiseCrypto = NONE_CRYPT;
ar->arPairwiseCryptoLen = 0;
ar->arGroupCrypto = NONE_CRYPT;
ar->arGroupCryptoLen = 0;
A_MEMZERO(ar->arWepKeyList, sizeof(ar->arWepKeyList));
A_MEMZERO(ar->arReqBssid, sizeof(ar->arReqBssid));
A_MEMZERO(ar->arBssid, sizeof(ar->arBssid));
ar->arBssChannel = 0;
}
static void
ar6000_init_control_info(struct ar6_softc *ar)
{
ar->arWmiEnabled = false;
ar6000_init_profile_info(ar);
ar->arDefTxKeyIndex = 0;
A_MEMZERO(ar->arWepKeyList, sizeof(ar->arWepKeyList));
ar->arChannelHint = 0;
ar->arListenIntervalT = A_DEFAULT_LISTEN_INTERVAL;
ar->arListenIntervalB = 0;
ar->arVersion.host_ver = AR6K_SW_VERSION;
ar->arRssi = 0;
ar->arTxPwr = 0;
ar->arTxPwrSet = false;
ar->arSkipScan = 0;
ar->arBeaconInterval = 0;
ar->arBitRate = 0;
ar->arMaxRetries = 0;
ar->arWmmEnabled = true;
ar->intra_bss = 1;
ar->scan_triggered = 0;
A_MEMZERO(&ar->scParams, sizeof(ar->scParams));
ar->scParams.shortScanRatio = WMI_SHORTSCANRATIO_DEFAULT;
ar->scParams.scanCtrlFlags = DEFAULT_SCAN_CTRL_FLAGS;
{
u8 ctr;
A_MEMZERO((u8 *)ar->sta_list, AP_MAX_NUM_STA * sizeof(sta_t));
A_MUTEX_INIT(&ar->mcastpsqLock);
for (ctr=0; ctr < AP_MAX_NUM_STA ; ctr++) {
A_MUTEX_INIT(&ar->sta_list[ctr].psqLock);
A_NETBUF_QUEUE_INIT(&ar->sta_list[ctr].psq);
}
ar->ap_profile_flag = 0;
A_NETBUF_QUEUE_INIT(&ar->mcastpsq);
memcpy(ar->ap_country_code, DEF_AP_COUNTRY_CODE, 3);
ar->ap_wmode = DEF_AP_WMODE_G;
ar->ap_dtim_period = DEF_AP_DTIM;
ar->ap_beacon_interval = DEF_BEACON_INTERVAL;
}
}
static int
ar6000_open(struct net_device *dev)
{
unsigned long flags;
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
spin_lock_irqsave(&ar->arLock, flags);
if(ar->arWlanState == WLAN_DISABLED) {
ar->arWlanState = WLAN_ENABLED;
}
if( ar->arConnected || bypasswmi) {
netif_carrier_on(dev);
netif_wake_queue(dev);
}
else
netif_carrier_off(dev);
spin_unlock_irqrestore(&ar->arLock, flags);
return 0;
}
static int
ar6000_close(struct net_device *dev)
{
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
netif_stop_queue(dev);
ar6000_disconnect(ar);
if(ar->arWmiReady == true) {
if (wmi_scanparams_cmd(ar->arWmi, 0xFFFF, 0,
0, 0, 0, 0, 0, 0, 0, 0) != 0) {
return -EIO;
}
ar->arWlanState = WLAN_DISABLED;
}
ar6k_cfg80211_scanComplete_event(ar, A_ECANCELED);
return 0;
}
static int ar6000_connectservice(struct ar6_softc *ar,
struct htc_service_connect_req *pConnect,
char *pDesc)
{
int status;
struct htc_service_connect_resp response;
do {
A_MEMZERO(&response,sizeof(response));
status = HTCConnectService(ar->arHtcTarget,
pConnect,
&response);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" Failed to connect to %s service status:%d \n",
pDesc, status));
break;
}
switch (pConnect->ServiceID) {
case WMI_CONTROL_SVC :
if (ar->arWmiEnabled) {
wmi_set_control_ep(ar->arWmi, response.Endpoint);
}
ar->arControlEp = response.Endpoint;
break;
case WMI_DATA_BE_SVC :
arSetAc2EndpointIDMap(ar, WMM_AC_BE, response.Endpoint);
break;
case WMI_DATA_BK_SVC :
arSetAc2EndpointIDMap(ar, WMM_AC_BK, response.Endpoint);
break;
case WMI_DATA_VI_SVC :
arSetAc2EndpointIDMap(ar, WMM_AC_VI, response.Endpoint);
break;
case WMI_DATA_VO_SVC :
arSetAc2EndpointIDMap(ar, WMM_AC_VO, response.Endpoint);
break;
default:
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ServiceID not mapped %d\n", pConnect->ServiceID));
status = A_EINVAL;
break;
}
} while (false);
return status;
}
void ar6000_TxDataCleanup(struct ar6_softc *ar)
{
HTCFlushEndpoint(ar->arHtcTarget,
arAc2EndpointID(ar, WMM_AC_BE),
AR6K_DATA_PKT_TAG);
HTCFlushEndpoint(ar->arHtcTarget,
arAc2EndpointID(ar, WMM_AC_BK),
AR6K_DATA_PKT_TAG);
HTCFlushEndpoint(ar->arHtcTarget,
arAc2EndpointID(ar, WMM_AC_VI),
AR6K_DATA_PKT_TAG);
HTCFlushEndpoint(ar->arHtcTarget,
arAc2EndpointID(ar, WMM_AC_VO),
AR6K_DATA_PKT_TAG);
}
HTC_ENDPOINT_ID
ar6000_ac2_endpoint_id ( void * devt, u8 ac)
{
struct ar6_softc *ar = (struct ar6_softc *) devt;
return(arAc2EndpointID(ar, ac));
}
u8 ar6000_endpoint_id2_ac(void * devt, HTC_ENDPOINT_ID ep )
{
struct ar6_softc *ar = (struct ar6_softc *) devt;
return(arEndpoint2Ac(ar, ep ));
}
static int ath6kl_config_btcoex_params(struct ar6_softc *ar)
{
int r;
WMI_SET_BTCOEX_COLOCATED_BT_DEV_CMD sbcb_cmd;
WMI_SET_BTCOEX_FE_ANT_CMD sbfa_cmd;
memset(&sbcb_cmd, 0, sizeof(WMI_SET_BTCOEX_COLOCATED_BT_DEV_CMD));
sbcb_cmd.btcoexCoLocatedBTdev = ATH6KL_BT_DEV;
r = wmi_set_btcoex_colocated_bt_dev_cmd(ar->arWmi, &sbcb_cmd);
if (r) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Unable to set collocated BT type\n"));
return r;
}
memset(&sbfa_cmd, 0, sizeof(WMI_SET_BTCOEX_FE_ANT_CMD));
sbfa_cmd.btcoexFeAntType = ATH6KL_BT_ANTENNA;
r = wmi_set_btcoex_fe_ant_cmd(ar->arWmi, &sbfa_cmd);
if (r) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Unable to set fornt end antenna configuration\n"));
return r;
}
return 0;
}
static int ath6kl_config_btcoex_params(struct ar6_softc *ar)
{
return 0;
}
int ar6000_target_config_wlan_params(struct ar6_softc *ar)
{
int status = 0;
#ifdef CONFIG_HOST_TCMD_SUPPORT
if (ar->arTargetMode != AR6000_WLAN_MODE) {
return 0;
}
#endif
if ((wmi_set_rx_frame_format_cmd(ar->arWmi,ar->rxMetaVersion, processDot11Hdr, processDot11Hdr)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set the rx frame format.\n"));
status = A_ERROR;
}
status = ath6kl_config_btcoex_params(ar);
if (status)
return status;
#if WLAN_CONFIG_IGNORE_POWER_SAVE_FAIL_EVENT_DURING_SCAN
if ((wmi_pmparams_cmd(ar->arWmi, 0, 1, 0, 0, 1, IGNORE_POWER_SAVE_FAIL_EVENT_DURING_SCAN)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set power save fail event policy\n"));
status = A_ERROR;
}
#endif
#if WLAN_CONFIG_DONOT_IGNORE_BARKER_IN_ERP
if ((wmi_set_lpreamble_cmd(ar->arWmi, 0, WMI_DONOT_IGNORE_BARKER_IN_ERP)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set barker preamble policy\n"));
status = A_ERROR;
}
#endif
if ((wmi_set_keepalive_cmd(ar->arWmi, WLAN_CONFIG_KEEP_ALIVE_INTERVAL)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set keep alive interval\n"));
status = A_ERROR;
}
#if WLAN_CONFIG_DISABLE_11N
{
WMI_SET_HT_CAP_CMD htCap;
memset(&htCap, 0, sizeof(WMI_SET_HT_CAP_CMD));
htCap.band = 0;
if ((wmi_set_ht_cap_cmd(ar->arWmi, &htCap)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set ht capabilities \n"));
status = A_ERROR;
}
htCap.band = 1;
if ((wmi_set_ht_cap_cmd(ar->arWmi, &htCap)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set ht capabilities \n"));
status = A_ERROR;
}
}
#endif
#ifdef ATH6K_CONFIG_OTA_MODE
if ((wmi_powermode_cmd(ar->arWmi, MAX_PERF_POWER)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set power mode \n"));
status = A_ERROR;
}
#endif
if ((wmi_disctimeout_cmd(ar->arWmi, WLAN_CONFIG_DISCONNECT_TIMEOUT)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set disconnect timeout \n"));
status = A_ERROR;
}
#if WLAN_CONFIG_DISABLE_TX_BURSTING
if ((wmi_set_wmm_txop(ar->arWmi, WMI_TXOP_DISABLED)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set txop bursting \n"));
status = A_ERROR;
}
#endif
return status;
}
int ar6000_init(struct net_device *dev)
{
struct ar6_softc *ar;
int status;
s32 timeleft;
s16 i;
int ret = 0;
if((ar = ar6k_priv(dev)) == NULL)
{
return -EIO;
}
if (wlaninitmode == WLAN_INIT_MODE_USR || wlaninitmode == WLAN_INIT_MODE_DRV) {
ar6000_update_bdaddr(ar);
if (enablerssicompensation) {
ar6000_copy_cust_data_from_target(ar->arHifDevice, ar->arTargetType);
read_rssi_compensation_param(ar);
for (i=-95; i<=0; i++) {
rssi_compensation_table[0-i] = rssi_compensation_calc(ar,i);
}
}
}
dev_hold(dev);
rtnl_unlock();
if ((wlaninitmode == WLAN_INIT_MODE_USR || wlaninitmode == WLAN_INIT_MODE_DRV) &&
(BMIDone(ar->arHifDevice) != 0))
{
ret = -EIO;
goto ar6000_init_done;
}
if (!bypasswmi)
{
#if 0
if (ar->arVersion.host_ver != ar->arVersion.target_ver) {
A_PRINTF("WARNING: Host version 0x%x does not match Target "
" version 0x%x!\n",
ar->arVersion.host_ver, ar->arVersion.target_ver);
}
#endif
ar->arWmiEnabled = true;
if ((ar->arWmi = wmi_init((void *) ar)) == NULL)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s() Failed to initialize WMI.\n", __func__));
ret = -EIO;
goto ar6000_init_done;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s() Got WMI @ 0x%lx.\n", __func__,
(unsigned long) ar->arWmi));
}
do {
struct htc_service_connect_req connect;
status = HTCWaitTarget(ar->arHtcTarget);
if (status) {
break;
}
A_MEMZERO(&connect,sizeof(connect));
connect.pMetaData = NULL;
connect.MetaDataLength = 0;
connect.EpCallbacks.pContext = ar;
connect.EpCallbacks.EpTxCompleteMultiple = ar6000_tx_complete;
connect.EpCallbacks.EpRecv = ar6000_rx;
connect.EpCallbacks.EpRecvRefill = ar6000_rx_refill;
connect.EpCallbacks.EpSendFull = ar6000_tx_queue_full;
connect.MaxSendQueueDepth = MAX_DEFAULT_SEND_QUEUE_DEPTH;
connect.EpCallbacks.RecvRefillWaterMark = AR6000_MAX_RX_BUFFERS / 4;
if (0 == connect.EpCallbacks.RecvRefillWaterMark) {
connect.EpCallbacks.RecvRefillWaterMark++;
}
connect.ServiceID = WMI_CONTROL_SVC;
status = ar6000_connectservice(ar,
&connect,
"WMI CONTROL");
if (status) {
break;
}
connect.LocalConnectionFlags |= HTC_LOCAL_CONN_FLAGS_ENABLE_SEND_BUNDLE_PADDING;
connect.MaxSendMsgSize = WMI_MAX_TX_DATA_FRAME_LENGTH;
connect.EpCallbacks.RecvAllocThreshold = AR6000_BUFFER_SIZE;
connect.EpCallbacks.EpRecvAllocThresh = ar6000_alloc_amsdu_rxbuf;
if (reduce_credit_dribble) {
connect.ConnectionFlags |= HTC_CONNECT_FLAGS_REDUCE_CREDIT_DRIBBLE;
connect.ConnectionFlags &= ~HTC_CONNECT_FLAGS_THRESHOLD_LEVEL_MASK;
connect.ConnectionFlags |=
((u16)reduce_credit_dribble - 1) & HTC_CONNECT_FLAGS_THRESHOLD_LEVEL_MASK;
}
connect.ServiceID = WMI_DATA_BE_SVC;
status = ar6000_connectservice(ar,
&connect,
"WMI DATA BE");
if (status) {
break;
}
connect.ServiceID = WMI_DATA_BK_SVC;
status = ar6000_connectservice(ar,
&connect,
"WMI DATA BK");
if (status) {
break;
}
connect.ServiceID = WMI_DATA_VI_SVC;
status = ar6000_connectservice(ar,
&connect,
"WMI DATA VI");
if (status) {
break;
}
connect.ServiceID = WMI_DATA_VO_SVC;
status = ar6000_connectservice(ar,
&connect,
"WMI DATA VO");
if (status) {
break;
}
A_ASSERT(arAc2EndpointID(ar,WMM_AC_BE) != 0);
A_ASSERT(arAc2EndpointID(ar,WMM_AC_BK) != 0);
A_ASSERT(arAc2EndpointID(ar,WMM_AC_VI) != 0);
A_ASSERT(arAc2EndpointID(ar,WMM_AC_VO) != 0);
ar->arAcStreamPriMap[WMM_AC_BK] = 0;
ar->arAcStreamPriMap[WMM_AC_BE] = 1;
ar->arAcStreamPriMap[WMM_AC_VI] = 2;
ar->arAcStreamPriMap[WMM_AC_VO] = 3;
#ifdef EXPORT_HCI_BRIDGE_INTERFACE
if (setuphci && (NULL != ar6kHciTransCallbacks.setupTransport)) {
struct hci_transport_misc_handles hciHandles;
hciHandles.netDevice = ar->arNetDev;
hciHandles.hifDevice = ar->arHifDevice;
hciHandles.htcHandle = ar->arHtcTarget;
status = (int)(ar6kHciTransCallbacks.setupTransport(&hciHandles));
}
#else
if (setuphci) {
status = ar6000_setup_hci(ar);
}
#endif
} while (false);
if (status) {
ret = -EIO;
goto ar6000_init_done;
}
if (regscanmode) {
u32 param;
if (BMIReadMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar,
hi_option_flag),
(u8 *)&param,
4) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("BMIReadMemory forsetting "
"regscanmode failed\n"));
return A_ERROR;
}
if (regscanmode == 1)
param |= HI_OPTION_SKIP_REG_SCAN;
else if (regscanmode == 2)
param |= HI_OPTION_INIT_REG_SCAN;
if (BMIWriteMemory(ar->arHifDevice,
HOST_INTEREST_ITEM_ADDRESS(ar,
hi_option_flag),
(u8 *)&param,
4) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("BMIWriteMemory forsetting "
"regscanmode failed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("Regulatory scan mode set\n"));
}
ar6000_rx_refill(ar, ar->arControlEp);
ar6000_rx_refill(ar, arAc2EndpointID(ar,WMM_AC_BE));
if (bypasswmi) {
ar6000_rx_refill(ar,arAc2EndpointID(ar,WMM_AC_BK));
ar6000_rx_refill(ar,arAc2EndpointID(ar,WMM_AC_VI));
ar6000_rx_refill(ar,arAc2EndpointID(ar,WMM_AC_VO));
}
ar6000_refill_amsdu_rxbufs(ar,AR6000_MAX_AMSDU_RX_BUFFERS);
ar6000_setup_credit_dist(ar->arHtcTarget, &ar->arCreditStateInfo);
ar6000_cookie_init(ar);
status = HTCStart(ar->arHtcTarget);
if (status) {
if (ar->arWmiEnabled == true) {
wmi_shutdown(ar->arWmi);
ar->arWmiEnabled = false;
ar->arWmi = NULL;
}
ar6000_cookie_cleanup(ar);
ret = -EIO;
goto ar6000_init_done;
}
if (!bypasswmi) {
timeleft = wait_event_interruptible_timeout(arEvent,
(ar->arWmiReady == true), wmitimeout * HZ);
if (ar->arVersion.abi_ver != AR6K_ABI_VERSION) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ABI Version mismatch: Host(0x%x), Target(0x%x)\n", AR6K_ABI_VERSION, ar->arVersion.abi_ver));
#ifndef ATH6K_SKIP_ABI_VERSION_CHECK
ret = -EIO;
goto ar6000_init_done;
#endif
}
if(!timeleft || signal_pending(current))
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("WMI is not ready or wait was interrupted\n"));
ret = -EIO;
goto ar6000_init_done;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s() WMI is ready\n", __func__));
if ((ar6000_set_host_app_area(ar)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Unable to set the host app area\n"));
}
ar6000_target_config_wlan_params(ar);
}
ar->arNumDataEndPts = 1;
if (bypasswmi) {
dev->dev_addr[0] = 0x00;
dev->dev_addr[1] = 0x01;
dev->dev_addr[2] = 0x02;
dev->dev_addr[3] = 0xAA;
dev->dev_addr[4] = 0xBB;
dev->dev_addr[5] = 0xCC;
}
ar6000_init_done:
rtnl_lock();
dev_put(dev);
return ret;
}
void
ar6000_bitrate_rx(void *devt, s32 rateKbps)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
ar->arBitRate = rateKbps;
wake_up(&arEvent);
}
void
ar6000_ratemask_rx(void *devt, u32 ratemask)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
ar->arRateMask = ratemask;
wake_up(&arEvent);
}
void
ar6000_txPwr_rx(void *devt, u8 txPwr)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
ar->arTxPwr = txPwr;
wake_up(&arEvent);
}
void
ar6000_channelList_rx(void *devt, s8 numChan, u16 *chanList)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
memcpy(ar->arChannelList, chanList, numChan * sizeof (u16));
ar->arNumChannels = numChan;
wake_up(&arEvent);
}
u8 ar6000_ibss_map_epid(struct sk_buff *skb, struct net_device *dev, u32 *mapNo)
{
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
u8 *datap;
ATH_MAC_HDR *macHdr;
u32 i, eptMap;
(*mapNo) = 0;
datap = A_NETBUF_DATA(skb);
macHdr = (ATH_MAC_HDR *)(datap + sizeof(WMI_DATA_HDR));
if (IEEE80211_IS_MULTICAST(macHdr->dstMac)) {
return ENDPOINT_2;
}
eptMap = -1;
for (i = 0; i < ar->arNodeNum; i ++) {
if (IEEE80211_ADDR_EQ(macHdr->dstMac, ar->arNodeMap[i].macAddress)) {
(*mapNo) = i + 1;
ar->arNodeMap[i].txPending ++;
return ar->arNodeMap[i].epId;
}
if ((eptMap == -1) && !ar->arNodeMap[i].txPending) {
eptMap = i;
}
}
if (eptMap == -1) {
eptMap = ar->arNodeNum;
ar->arNodeNum ++;
A_ASSERT(ar->arNodeNum <= MAX_NODE_NUM);
}
memcpy(ar->arNodeMap[eptMap].macAddress, macHdr->dstMac, IEEE80211_ADDR_LEN);
for (i = ENDPOINT_2; i <= ENDPOINT_5; i ++) {
if (!ar->arTxPending[i]) {
ar->arNodeMap[eptMap].epId = i;
break;
}
if (i == ENDPOINT_5) {
ar->arNodeMap[eptMap].epId = ar->arNexEpId;
ar->arNexEpId ++;
if (ar->arNexEpId > ENDPOINT_5) {
ar->arNexEpId = ENDPOINT_2;
}
}
}
(*mapNo) = eptMap + 1;
ar->arNodeMap[eptMap].txPending ++;
return ar->arNodeMap[eptMap].epId;
}
static void ar6000_dump_skb(struct sk_buff *skb)
{
u_char *ch;
for (ch = A_NETBUF_DATA(skb);
(unsigned long)ch < ((unsigned long)A_NETBUF_DATA(skb) +
A_NETBUF_LEN(skb)); ch++)
{
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,("%2.2x ", *ch));
}
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,("\n"));
}
static int
ar6000_data_tx(struct sk_buff *skb, struct net_device *dev)
{
#define AC_NOT_MAPPED 99
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
u8 ac = AC_NOT_MAPPED;
HTC_ENDPOINT_ID eid = ENDPOINT_UNUSED;
u32 mapNo = 0;
int len;
struct ar_cookie *cookie;
bool checkAdHocPsMapping = false,bMoreData = false;
HTC_TX_TAG htc_tag = AR6K_DATA_PKT_TAG;
u8 dot11Hdr = processDot11Hdr;
#ifdef CONFIG_PM
if (ar->arWowState != WLAN_WOW_STATE_NONE) {
A_NETBUF_FREE(skb);
return 0;
}
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_TX,("ar6000_data_tx start - skb=0x%lx, data=0x%lx, len=0x%x\n",
(unsigned long)skb, (unsigned long)A_NETBUF_DATA(skb),
A_NETBUF_LEN(skb)));
if( (!ar->arConnected && !bypasswmi)
#ifdef CONFIG_HOST_TCMD_SUPPORT
|| (ar->arTargetMode == AR6000_TCMD_MODE)
#endif
) {
A_NETBUF_FREE(skb);
return 0;
}
do {
if (ar->arWmiReady == false && bypasswmi == 0) {
break;
}
#ifdef BLOCK_TX_PATH_FLAG
if (blocktx) {
break;
}
#endif
if (ar->arNetworkType == AP_NETWORK) {
ATH_MAC_HDR *datap = (ATH_MAC_HDR *)A_NETBUF_DATA(skb);
sta_t *conn = NULL;
if (IEEE80211_IS_MULTICAST(datap->dstMac)) {
u8 ctr=0;
bool qMcast=false;
for (ctr=0; ctr<AP_MAX_NUM_STA; ctr++) {
if (STA_IS_PWR_SLEEP((&ar->sta_list[ctr]))) {
qMcast = true;
}
}
if(qMcast) {
if (ar->DTIMExpired == false) {
bool isMcastqEmpty = false;
A_MUTEX_LOCK(&ar->mcastpsqLock);
isMcastqEmpty = A_NETBUF_QUEUE_EMPTY(&ar->mcastpsq);
A_NETBUF_ENQUEUE(&ar->mcastpsq, skb);
A_MUTEX_UNLOCK(&ar->mcastpsqLock);
if (isMcastqEmpty) {
wmi_set_pvb_cmd(ar->arWmi, MCAST_AID, 1);
}
return 0;
} else {
A_MUTEX_LOCK(&ar->mcastpsqLock);
if(!A_NETBUF_QUEUE_EMPTY(&ar->mcastpsq)) {
bMoreData = true;
}
A_MUTEX_UNLOCK(&ar->mcastpsqLock);
}
}
} else {
conn = ieee80211_find_conn(ar, datap->dstMac);
if (conn) {
if (STA_IS_PWR_SLEEP(conn)) {
if (!STA_IS_PS_POLLED(conn)) {
bool isPsqEmpty = false;
A_MUTEX_LOCK(&conn->psqLock);
isPsqEmpty = A_NETBUF_QUEUE_EMPTY(&conn->psq);
A_NETBUF_ENQUEUE(&conn->psq, skb);
A_MUTEX_UNLOCK(&conn->psqLock);
if (isPsqEmpty) {
wmi_set_pvb_cmd(ar->arWmi, conn->aid, 1);
}
return 0;
} else {
A_MUTEX_LOCK(&conn->psqLock);
if (!A_NETBUF_QUEUE_EMPTY(&conn->psq)) {
bMoreData = true;
}
A_MUTEX_UNLOCK(&conn->psqLock);
}
}
} else {
A_NETBUF_FREE(skb);
return 0;
}
}
}
if (ar->arWmiEnabled) {
u8 csumStart=0;
u8 csumDest=0;
u8 csum=skb->ip_summed;
if(csumOffload && (csum==CHECKSUM_PARTIAL)){
csumStart = (skb->head + skb->csum_start - skb_network_header(skb) +
sizeof(ATH_LLC_SNAP_HDR));
csumDest=skb->csum_offset+csumStart;
}
if (A_NETBUF_HEADROOM(skb) < dev->hard_header_len - LINUX_HACK_FUDGE_FACTOR) {
struct sk_buff *newbuf;
len = A_NETBUF_LEN(skb);
newbuf = A_NETBUF_ALLOC(len);
if (newbuf == NULL) {
break;
}
A_NETBUF_PUT(newbuf, len);
memcpy(A_NETBUF_DATA(newbuf), A_NETBUF_DATA(skb), len);
A_NETBUF_FREE(skb);
skb = newbuf;
}
if (dot11Hdr) {
if (wmi_dot11_hdr_add(ar->arWmi,skb,ar->arNetworkType) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_data_tx-wmi_dot11_hdr_add failed\n"));
break;
}
} else {
if (wmi_dix_2_dot3(ar->arWmi, skb) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_data_tx - wmi_dix_2_dot3 failed\n"));
break;
}
}
if(csumOffload && (csum ==CHECKSUM_PARTIAL)){
WMI_TX_META_V2 metaV2;
metaV2.csumStart =csumStart;
metaV2.csumDest = csumDest;
metaV2.csumFlags = 0x1;
if (wmi_data_hdr_add(ar->arWmi, skb, DATA_MSGTYPE, bMoreData, dot11Hdr,
WMI_META_VERSION_2,&metaV2) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_data_tx - wmi_data_hdr_add failed\n"));
break;
}
}
else
{
if (wmi_data_hdr_add(ar->arWmi, skb, DATA_MSGTYPE, bMoreData, dot11Hdr,0,NULL) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_data_tx - wmi_data_hdr_add failed\n"));
break;
}
}
if ((ar->arNetworkType == ADHOC_NETWORK) &&
ar->arIbssPsEnable && ar->arConnected) {
checkAdHocPsMapping = true;
} else {
ac = wmi_implicit_create_pstream(ar->arWmi, skb, 0, ar->arWmmEnabled);
}
} else {
EPPING_HEADER *eppingHdr;
eppingHdr = A_NETBUF_DATA(skb);
if (IS_EPPING_PACKET(eppingHdr)) {
ac = eppingHdr->StreamNo_h;
if (IS_EPING_PACKET_NO_DROP(eppingHdr)) {
htc_tag = AR6K_CONTROL_PKT_TAG;
}
if (ac == HCI_TRANSPORT_STREAM_NUM) {
#ifndef EXPORT_HCI_BRIDGE_INTERFACE
if (!hci_test_send(ar,skb)) {
return 0;
}
#endif
ac = AC_NOT_MAPPED;
} else {
if (EPPING_ALIGNMENT_PAD > 0) {
A_NETBUF_PUSH(skb, EPPING_ALIGNMENT_PAD);
}
}
} else {
ac = AC_NOT_MAPPED;
}
}
} while (false);
if ((ac == AC_NOT_MAPPED) && !checkAdHocPsMapping) {
A_NETBUF_FREE(skb);
AR6000_STAT_INC(ar, tx_dropped);
AR6000_STAT_INC(ar, tx_aborted_errors);
return 0;
}
cookie = NULL;
AR6000_SPIN_LOCK(&ar->arLock, 0);
do {
if (checkAdHocPsMapping) {
eid = ar6000_ibss_map_epid(skb, dev, &mapNo);
}else {
eid = arAc2EndpointID (ar, ac);
}
if (eid == 0 || eid == ENDPOINT_UNUSED ) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" eid %d is NOT mapped!\n", eid));
break;
}
cookie = ar6000_alloc_cookie(ar);
if (cookie != NULL) {
ar->arTxPending[eid]++;
ar->arTotalTxDataPending++;
}
} while (false);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (cookie != NULL) {
cookie->arc_bp[0] = (unsigned long)skb;
cookie->arc_bp[1] = mapNo;
SET_HTC_PACKET_INFO_TX(&cookie->HtcPkt,
cookie,
A_NETBUF_DATA(skb),
A_NETBUF_LEN(skb),
eid,
htc_tag);
#ifdef DEBUG
if (debugdriver >= 3) {
ar6000_dump_skb(skb);
}
#endif
#ifdef HTC_TEST_SEND_PKTS
DoHTCSendPktsTest(ar,mapNo,eid,skb);
#endif
HTCSendPkt(ar->arHtcTarget, &cookie->HtcPkt);
} else {
A_NETBUF_FREE(skb);
AR6000_STAT_INC(ar, tx_dropped);
AR6000_STAT_INC(ar, tx_aborted_errors);
}
return 0;
}
int
ar6000_acl_data_tx(struct sk_buff *skb, struct net_device *dev)
{
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
struct ar_cookie *cookie;
HTC_ENDPOINT_ID eid = ENDPOINT_UNUSED;
cookie = NULL;
AR6000_SPIN_LOCK(&ar->arLock, 0);
eid = arAc2EndpointID (ar, 0);
cookie = ar6000_alloc_cookie(ar);
if (cookie != NULL) {
ar->arTxPending[eid]++;
ar->arTotalTxDataPending++;
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (cookie != NULL) {
cookie->arc_bp[0] = (unsigned long)skb;
cookie->arc_bp[1] = 0;
SET_HTC_PACKET_INFO_TX(&cookie->HtcPkt,
cookie,
A_NETBUF_DATA(skb),
A_NETBUF_LEN(skb),
eid,
AR6K_DATA_PKT_TAG);
HTCSendPkt(ar->arHtcTarget, &cookie->HtcPkt);
} else {
A_NETBUF_FREE(skb);
AR6000_STAT_INC(ar, tx_dropped);
AR6000_STAT_INC(ar, tx_aborted_errors);
}
return 0;
}
static void
tvsub(register struct timeval *out, register struct timeval *in)
{
if((out->tv_usec -= in->tv_usec) < 0) {
out->tv_sec--;
out->tv_usec += 1000000;
}
out->tv_sec -= in->tv_sec;
}
void
applyAPTCHeuristics(struct ar6_softc *ar)
{
u32 duration;
u32 numbytes;
u32 throughput;
struct timeval ts;
int status;
AR6000_SPIN_LOCK(&ar->arLock, 0);
if ((enableAPTCHeuristics) && (!aptcTR.timerScheduled)) {
do_gettimeofday(&ts);
tvsub(&ts, &aptcTR.samplingTS);
duration = ts.tv_sec * 1000 + ts.tv_usec / 1000;
numbytes = aptcTR.bytesTransmitted + aptcTR.bytesReceived;
if (duration > APTC_TRAFFIC_SAMPLING_INTERVAL) {
aptcTR.bytesTransmitted = aptcTR.bytesReceived = 0;
do_gettimeofday(&aptcTR.samplingTS);
throughput = ((numbytes * 8) / duration);
if (throughput > APTC_UPPER_THROUGHPUT_THRESHOLD) {
A_ASSERT(ar->arWmiReady == true);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
status = wmi_powermode_cmd(ar->arWmi, MAX_PERF_POWER);
AR6000_SPIN_LOCK(&ar->arLock, 0);
A_TIMEOUT_MS(&aptcTimer, APTC_TRAFFIC_SAMPLING_INTERVAL, 0);
aptcTR.timerScheduled = true;
}
}
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
}
static HTC_SEND_FULL_ACTION ar6000_tx_queue_full(void *Context, struct htc_packet *pPacket)
{
struct ar6_softc *ar = (struct ar6_softc *)Context;
HTC_SEND_FULL_ACTION action = HTC_SEND_FULL_KEEP;
bool stopNet = false;
HTC_ENDPOINT_ID Endpoint = HTC_GET_ENDPOINT_FROM_PKT(pPacket);
do {
if (bypasswmi) {
int accessClass;
if (HTC_GET_TAG_FROM_PKT(pPacket) == AR6K_CONTROL_PKT_TAG) {
break;
}
accessClass = arEndpoint2Ac(ar,Endpoint);
if ((accessClass == WMM_AC_BE) || (accessClass == WMM_AC_BK)) {
action = HTC_SEND_FULL_DROP;
stopNet = false;
} else {
stopNet = true;
}
break;
}
if (Endpoint == ar->arControlEp) {
AR6000_SPIN_LOCK(&ar->arLock, 0);
ar->arWMIControlEpFull = true;
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("WMI Control Endpoint is FULL!!! \n"));
stopNet = false;
break;
}
if (HTC_GET_TAG_FROM_PKT(pPacket) == AR6K_CONTROL_PKT_TAG) {
break;
}
if (ar->arNetworkType == ADHOC_NETWORK) {
stopNet = true;
break;
}
if (ar->arAcStreamPriMap[arEndpoint2Ac(ar,Endpoint)] < ar->arHiAcStreamActivePri &&
ar->arCookieCount <= MAX_HI_COOKIE_NUM) {
action = HTC_SEND_FULL_DROP;
stopNet = false;
break;
}
} while (false);
if (stopNet) {
AR6000_SPIN_LOCK(&ar->arLock, 0);
ar->arNetQueueStopped = true;
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
netif_stop_queue(ar->arNetDev);
}
return action;
}
static void
ar6000_tx_complete(void *Context, struct htc_packet_queue *pPacketQueue)
{
struct ar6_softc *ar = (struct ar6_softc *)Context;
u32 mapNo = 0;
int status;
struct ar_cookie * ar_cookie;
HTC_ENDPOINT_ID eid;
bool wakeEvent = false;
struct sk_buff_head skb_queue;
struct htc_packet *pPacket;
struct sk_buff *pktSkb;
bool flushing = false;
skb_queue_head_init(&skb_queue);
AR6000_SPIN_LOCK(&ar->arLock, 0);
while (!HTC_QUEUE_EMPTY(pPacketQueue)) {
pPacket = HTC_PACKET_DEQUEUE(pPacketQueue);
ar_cookie = (struct ar_cookie *)pPacket->pPktContext;
A_ASSERT(ar_cookie);
status = pPacket->Status;
pktSkb = (struct sk_buff *)ar_cookie->arc_bp[0];
eid = pPacket->Endpoint;
mapNo = ar_cookie->arc_bp[1];
A_ASSERT(pktSkb);
A_ASSERT(pPacket->pBuffer == A_NETBUF_DATA(pktSkb));
__skb_queue_tail(&skb_queue,pktSkb);
if (!status) {
A_ASSERT(pPacket->ActualLength == A_NETBUF_LEN(pktSkb));
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_TX,("ar6000_tx_complete skb=0x%lx data=0x%lx len=0x%x eid=%d ",
(unsigned long)pktSkb, (unsigned long)pPacket->pBuffer,
pPacket->ActualLength,
eid));
ar->arTxPending[eid]--;
if ((eid != ar->arControlEp) || bypasswmi) {
ar->arTotalTxDataPending--;
}
if (eid == ar->arControlEp)
{
if (ar->arWMIControlEpFull) {
ar->arWMIControlEpFull = false;
}
if (ar->arTxPending[eid] == 0) {
wakeEvent = true;
}
}
if (status) {
if (status == A_ECANCELED) {
flushing = true;
}
AR6000_STAT_INC(ar, tx_errors);
if (status != A_NO_RESOURCE) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s() -TX ERROR, status: 0x%x\n", __func__,
status));
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_TX,("OK\n"));
flushing = false;
AR6000_STAT_INC(ar, tx_packets);
ar->arNetStats.tx_bytes += A_NETBUF_LEN(pktSkb);
#ifdef ADAPTIVE_POWER_THROUGHPUT_CONTROL
aptcTR.bytesTransmitted += a_netbuf_to_len(pktSkb);
applyAPTCHeuristics(ar);
#endif
}
if ((ar->arNetworkType == ADHOC_NETWORK) && ar->arIbssPsEnable
&& (eid != ar->arControlEp) && mapNo)
{
mapNo --;
ar->arNodeMap[mapNo].txPending --;
if (!ar->arNodeMap[mapNo].txPending && (mapNo == (ar->arNodeNum - 1))) {
u32 i;
for (i = ar->arNodeNum; i > 0; i --) {
if (!ar->arNodeMap[i - 1].txPending) {
A_MEMZERO(&ar->arNodeMap[i - 1], sizeof(struct ar_node_mapping));
ar->arNodeNum --;
} else {
break;
}
}
}
}
ar6000_free_cookie(ar, ar_cookie);
if (ar->arNetQueueStopped) {
ar->arNetQueueStopped = false;
}
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
while (!skb_queue_empty(&skb_queue)) {
pktSkb = __skb_dequeue(&skb_queue);
A_NETBUF_FREE(pktSkb);
}
if ((ar->arConnected == true) || bypasswmi) {
if (!flushing) {
netif_wake_queue(ar->arNetDev);
}
}
if (wakeEvent) {
wake_up(&arEvent);
}
}
sta_t *
ieee80211_find_conn(struct ar6_softc *ar, u8 *node_addr)
{
sta_t *conn = NULL;
u8 i, max_conn;
switch(ar->arNetworkType) {
case AP_NETWORK:
max_conn = AP_MAX_NUM_STA;
break;
default:
max_conn=0;
break;
}
for (i = 0; i < max_conn; i++) {
if (IEEE80211_ADDR_EQ(node_addr, ar->sta_list[i].mac)) {
conn = &ar->sta_list[i];
break;
}
}
return conn;
}
sta_t *ieee80211_find_conn_for_aid(struct ar6_softc *ar, u8 aid)
{
sta_t *conn = NULL;
u8 ctr;
for (ctr = 0; ctr < AP_MAX_NUM_STA; ctr++) {
if (ar->sta_list[ctr].aid == aid) {
conn = &ar->sta_list[ctr];
break;
}
}
return conn;
}
static void
ar6000_rx(void *Context, struct htc_packet *pPacket)
{
struct ar6_softc *ar = (struct ar6_softc *)Context;
struct sk_buff *skb = (struct sk_buff *)pPacket->pPktContext;
int minHdrLen;
u8 containsDot11Hdr = 0;
int status = pPacket->Status;
HTC_ENDPOINT_ID ept = pPacket->Endpoint;
A_ASSERT((status) ||
(pPacket->pBuffer == (A_NETBUF_DATA(skb) + HTC_HEADER_LEN)));
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_RX,("ar6000_rx ar=0x%lx eid=%d, skb=0x%lx, data=0x%lx, len=0x%x status:%d",
(unsigned long)ar, ept, (unsigned long)skb, (unsigned long)pPacket->pBuffer,
pPacket->ActualLength, status));
if (status) {
if (status != A_ECANCELED) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("RX ERR (%d) \n",status));
}
}
AR6000_SPIN_LOCK(&ar->arLock, 0);
if (!status) {
AR6000_STAT_INC(ar, rx_packets);
ar->arNetStats.rx_bytes += pPacket->ActualLength;
#ifdef ADAPTIVE_POWER_THROUGHPUT_CONTROL
aptcTR.bytesReceived += a_netbuf_to_len(skb);
applyAPTCHeuristics(ar);
#endif
A_NETBUF_PUT(skb, pPacket->ActualLength + HTC_HEADER_LEN);
A_NETBUF_PULL(skb, HTC_HEADER_LEN);
#ifdef DEBUG
if (debugdriver >= 2) {
ar6000_dump_skb(skb);
}
#endif
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
skb->dev = ar->arNetDev;
if (status) {
AR6000_STAT_INC(ar, rx_errors);
A_NETBUF_FREE(skb);
} else if (ar->arWmiEnabled == true) {
if (ept == ar->arControlEp) {
#ifdef CONFIG_PM
ar6000_check_wow_status(ar, skb, true);
#endif
wmi_control_rx(ar->arWmi, skb);
} else {
WMI_DATA_HDR *dhdr = (WMI_DATA_HDR *)A_NETBUF_DATA(skb);
bool is_amsdu;
u8 tid;
if (WARN_ON(WMI_DATA_HDR_GET_DATA_TYPE(dhdr) ==
WMI_DATA_HDR_DATA_TYPE_ACL)) {
AR6000_STAT_INC(ar, rx_errors);
A_NETBUF_FREE(skb);
return;
}
#ifdef CONFIG_PM
ar6000_check_wow_status(ar, NULL, false);
#endif
if (processDot11Hdr) {
minHdrLen = sizeof(WMI_DATA_HDR) + sizeof(struct ieee80211_frame) + sizeof(ATH_LLC_SNAP_HDR);
} else {
minHdrLen = sizeof (WMI_DATA_HDR) + sizeof(ATH_MAC_HDR) +
sizeof(ATH_LLC_SNAP_HDR);
}
if (ar->arNetworkType != AP_NETWORK &&
((pPacket->ActualLength < minHdrLen) ||
(pPacket->ActualLength > AR6000_MAX_RX_MESSAGE_SIZE)))
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("TOO SHORT or TOO LONG\n"));
AR6000_STAT_INC(ar, rx_errors);
AR6000_STAT_INC(ar, rx_length_errors);
A_NETBUF_FREE(skb);
} else {
u16 seq_no;
u8 meta_type;
#if 0
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("RSSI %d\n",
((WMI_DATA_HDR *) A_NETBUF_DATA(skb))->rssi));
#endif
if (ar->arNetworkType == AP_NETWORK) {
sta_t *conn = NULL;
u8 psState=0,prevPsState;
ATH_MAC_HDR *datap=NULL;
u16 offset;
meta_type = WMI_DATA_HDR_GET_META(dhdr);
psState = (((WMI_DATA_HDR *)A_NETBUF_DATA(skb))->info
>> WMI_DATA_HDR_PS_SHIFT) & WMI_DATA_HDR_PS_MASK;
offset = sizeof(WMI_DATA_HDR);
switch (meta_type) {
case 0:
break;
case WMI_META_VERSION_1:
offset += sizeof(WMI_RX_META_V1);
break;
case WMI_META_VERSION_2:
offset += sizeof(WMI_RX_META_V2);
break;
default:
break;
}
datap = (ATH_MAC_HDR *)(A_NETBUF_DATA(skb)+offset);
conn = ieee80211_find_conn(ar, datap->srcMac);
if (conn) {
prevPsState = STA_IS_PWR_SLEEP(conn);
if (psState) {
STA_SET_PWR_SLEEP(conn);
} else {
STA_CLR_PWR_SLEEP(conn);
}
if (prevPsState ^ STA_IS_PWR_SLEEP(conn)) {
if (!STA_IS_PWR_SLEEP(conn)) {
A_MUTEX_LOCK(&conn->psqLock);
while (!A_NETBUF_QUEUE_EMPTY(&conn->psq)) {
struct sk_buff *skb=NULL;
skb = A_NETBUF_DEQUEUE(&conn->psq);
A_MUTEX_UNLOCK(&conn->psqLock);
ar6000_data_tx(skb,ar->arNetDev);
A_MUTEX_LOCK(&conn->psqLock);
}
A_MUTEX_UNLOCK(&conn->psqLock);
wmi_set_pvb_cmd(ar->arWmi, conn->aid, 0);
}
}
} else {
A_ASSERT(false);
}
if((pPacket->ActualLength < minHdrLen) ||
(pPacket->ActualLength > AR6000_MAX_RX_MESSAGE_SIZE)) {
A_NETBUF_FREE(skb);
goto rx_done;
}
}
is_amsdu = WMI_DATA_HDR_IS_AMSDU(dhdr) ? true : false;
tid = WMI_DATA_HDR_GET_UP(dhdr);
seq_no = WMI_DATA_HDR_GET_SEQNO(dhdr);
meta_type = WMI_DATA_HDR_GET_META(dhdr);
containsDot11Hdr = WMI_DATA_HDR_GET_DOT11(dhdr);
wmi_data_hdr_remove(ar->arWmi, skb);
switch (meta_type) {
case WMI_META_VERSION_1:
{
WMI_RX_META_V1 *pMeta = (WMI_RX_META_V1 *)A_NETBUF_DATA(skb);
A_PRINTF("META %d %d %d %d %x\n", pMeta->status, pMeta->rix, pMeta->rssi, pMeta->channel, pMeta->flags);
A_NETBUF_PULL((void*)skb, sizeof(WMI_RX_META_V1));
break;
}
case WMI_META_VERSION_2:
{
WMI_RX_META_V2 *pMeta = (WMI_RX_META_V2 *)A_NETBUF_DATA(skb);
if(pMeta->csumFlags & 0x1){
skb->ip_summed=CHECKSUM_COMPLETE;
skb->csum=(pMeta->csum);
}
A_NETBUF_PULL((void*)skb, sizeof(WMI_RX_META_V2));
break;
}
default:
break;
}
A_ASSERT(status == 0);
if(containsDot11Hdr) {
status = wmi_dot11_hdr_remove(ar->arWmi,skb);
} else if(!is_amsdu) {
status = wmi_dot3_2_dix(skb);
}
if (status) {
A_NETBUF_FREE(skb);
goto rx_done;
}
if ((ar->arNetDev->flags & IFF_UP) == IFF_UP) {
if (ar->arNetworkType == AP_NETWORK) {
struct sk_buff *skb1 = NULL;
ATH_MAC_HDR *datap;
datap = (ATH_MAC_HDR *)A_NETBUF_DATA(skb);
if (IEEE80211_IS_MULTICAST(datap->dstMac)) {
skb1 = skb_copy(skb,GFP_ATOMIC);
} else {
sta_t *conn = NULL;
conn = ieee80211_find_conn(ar, datap->dstMac);
if (conn && ar->intra_bss) {
skb1 = skb;
skb = NULL;
} else if(conn && !ar->intra_bss) {
A_NETBUF_FREE(skb);
skb = NULL;
}
}
if (skb1) {
ar6000_data_tx(skb1, ar->arNetDev);
}
}
}
aggr_process_recv_frm(ar->aggr_cntxt, tid, seq_no, is_amsdu, (void **)&skb);
ar6000_deliver_frames_to_nw_stack((void *) ar->arNetDev, (void *)skb);
}
}
} else {
if (EPPING_ALIGNMENT_PAD > 0) {
A_NETBUF_PULL(skb, EPPING_ALIGNMENT_PAD);
}
ar6000_deliver_frames_to_nw_stack((void *)ar->arNetDev, (void *)skb);
}
rx_done:
return;
}
static void
ar6000_deliver_frames_to_nw_stack(void *dev, void *osbuf)
{
struct sk_buff *skb = (struct sk_buff *)osbuf;
if(skb) {
skb->dev = dev;
if ((skb->dev->flags & IFF_UP) == IFF_UP) {
#ifdef CONFIG_PM
ar6000_check_wow_status((struct ar6_softc *)ar6k_priv(dev), skb, false);
#endif
skb->protocol = eth_type_trans(skb, skb->dev);
if (in_interrupt()) {
netif_rx(skb);
} else {
netif_rx_ni(skb);
}
} else {
A_NETBUF_FREE(skb);
}
}
}
static void
ar6000_rx_refill(void *Context, HTC_ENDPOINT_ID Endpoint)
{
struct ar6_softc *ar = (struct ar6_softc *)Context;
void *osBuf;
int RxBuffers;
int buffersToRefill;
struct htc_packet *pPacket;
struct htc_packet_queue queue;
buffersToRefill = (int)AR6000_MAX_RX_BUFFERS -
HTCGetNumRecvBuffers(ar->arHtcTarget, Endpoint);
if (buffersToRefill <= 0) {
return;
}
INIT_HTC_PACKET_QUEUE(&queue);
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_RX,("ar6000_rx_refill: providing htc with %d buffers at eid=%d\n",
buffersToRefill, Endpoint));
for (RxBuffers = 0; RxBuffers < buffersToRefill; RxBuffers++) {
osBuf = A_NETBUF_ALLOC(AR6000_BUFFER_SIZE);
if (NULL == osBuf) {
break;
}
pPacket = (struct htc_packet *)(A_NETBUF_HEAD(osBuf));
SET_HTC_PACKET_INFO_RX_REFILL(pPacket,osBuf,A_NETBUF_DATA(osBuf),AR6000_BUFFER_SIZE,Endpoint);
HTC_PACKET_ENQUEUE(&queue,pPacket);
}
if (!HTC_QUEUE_EMPTY(&queue)) {
HTCAddReceivePktMultiple(ar->arHtcTarget, &queue);
}
}
static void ar6000_cleanup_amsdu_rxbufs(struct ar6_softc *ar)
{
struct htc_packet *pPacket;
void *osBuf;
while (true) {
AR6000_SPIN_LOCK(&ar->arLock, 0);
pPacket = HTC_PACKET_DEQUEUE(&ar->amsdu_rx_buffer_queue);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (NULL == pPacket) {
break;
}
osBuf = pPacket->pPktContext;
if (NULL == osBuf) {
A_ASSERT(false);
break;
}
A_NETBUF_FREE(osBuf);
}
}
static void ar6000_refill_amsdu_rxbufs(struct ar6_softc *ar, int Count)
{
struct htc_packet *pPacket;
void *osBuf;
while (Count > 0) {
osBuf = A_NETBUF_ALLOC(AR6000_AMSDU_BUFFER_SIZE);
if (NULL == osBuf) {
break;
}
pPacket = (struct htc_packet *)(A_NETBUF_HEAD(osBuf));
SET_HTC_PACKET_INFO_RX_REFILL(pPacket,osBuf,A_NETBUF_DATA(osBuf),AR6000_AMSDU_BUFFER_SIZE,0);
AR6000_SPIN_LOCK(&ar->arLock, 0);
HTC_PACKET_ENQUEUE(&ar->amsdu_rx_buffer_queue,pPacket);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
Count--;
}
}
static struct htc_packet *ar6000_alloc_amsdu_rxbuf(void *Context, HTC_ENDPOINT_ID Endpoint, int Length)
{
struct htc_packet *pPacket = NULL;
struct ar6_softc *ar = (struct ar6_softc *)Context;
int refillCount = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_RX,("ar6000_alloc_amsdu_rxbuf: eid=%d, Length:%d\n",Endpoint,Length));
do {
if (Length <= AR6000_BUFFER_SIZE) {
A_ASSERT(false);
break;
}
if (Length > AR6000_AMSDU_BUFFER_SIZE) {
A_ASSERT(false);
break;
}
AR6000_SPIN_LOCK(&ar->arLock, 0);
pPacket = HTC_PACKET_DEQUEUE(&ar->amsdu_rx_buffer_queue);
refillCount = AR6000_MAX_AMSDU_RX_BUFFERS - HTC_PACKET_QUEUE_DEPTH(&ar->amsdu_rx_buffer_queue);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (NULL == pPacket) {
break;
}
pPacket->Endpoint = Endpoint;
} while (false);
if (refillCount >= AR6000_AMSDU_REFILL_THRESHOLD) {
ar6000_refill_amsdu_rxbufs(ar,refillCount);
}
return pPacket;
}
static void
ar6000_set_multicast_list(struct net_device *dev)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000: Multicast filter not supported\n"));
}
static struct net_device_stats *
ar6000_get_stats(struct net_device *dev)
{
struct ar6_softc *ar = (struct ar6_softc *)ar6k_priv(dev);
return &ar->arNetStats;
}
void
ar6000_ready_event(void *devt, u8 *datap, u8 phyCap, u32 sw_ver, u32 abi_ver)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
struct net_device *dev = ar->arNetDev;
memcpy(dev->dev_addr, datap, AR6000_ETH_ADDR_LEN);
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("mac address = %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x\n",
dev->dev_addr[0], dev->dev_addr[1],
dev->dev_addr[2], dev->dev_addr[3],
dev->dev_addr[4], dev->dev_addr[5]));
ar->arPhyCapability = phyCap;
ar->arVersion.wlan_ver = sw_ver;
ar->arVersion.abi_ver = abi_ver;
ar->arWmiReady = true;
wake_up(&arEvent);
}
void ar6000_install_static_wep_keys(struct ar6_softc *ar)
{
u8 index;
u8 keyUsage;
for (index = WMI_MIN_KEY_INDEX; index <= WMI_MAX_KEY_INDEX; index++) {
if (ar->arWepKeyList[index].arKeyLen) {
keyUsage = GROUP_USAGE;
if (index == ar->arDefTxKeyIndex) {
keyUsage |= TX_USAGE;
}
wmi_addKey_cmd(ar->arWmi,
index,
WEP_CRYPT,
keyUsage,
ar->arWepKeyList[index].arKeyLen,
NULL,
ar->arWepKeyList[index].arKey, KEY_OP_INIT_VAL, NULL,
NO_SYNC_WMIFLAG);
}
}
}
void
add_new_sta(struct ar6_softc *ar, u8 *mac, u16 aid, u8 *wpaie,
u8 ielen, u8 keymgmt, u8 ucipher, u8 auth)
{
u8 free_slot=aid-1;
memcpy(ar->sta_list[free_slot].mac, mac, ATH_MAC_LEN);
memcpy(ar->sta_list[free_slot].wpa_ie, wpaie, ielen);
ar->sta_list[free_slot].aid = aid;
ar->sta_list[free_slot].keymgmt = keymgmt;
ar->sta_list[free_slot].ucipher = ucipher;
ar->sta_list[free_slot].auth = auth;
ar->sta_list_index = ar->sta_list_index | (1 << free_slot);
ar->arAPStats.sta[free_slot].aid = aid;
}
void
ar6000_connect_event(struct ar6_softc *ar, u16 channel, u8 *bssid,
u16 listenInterval, u16 beaconInterval,
NETWORK_TYPE networkType, u8 beaconIeLen,
u8 assocReqLen, u8 assocRespLen,
u8 *assocInfo)
{
union iwreq_data wrqu;
int i, beacon_ie_pos, assoc_resp_ie_pos, assoc_req_ie_pos;
static const char *tag1 = "ASSOCINFO(ReqIEs=";
static const char *tag2 = "ASSOCRESPIE=";
static const char *beaconIetag = "BEACONIE=";
char buf[WMI_CONTROL_MSG_MAX_LEN * 2 + strlen(tag1) + 1];
char *pos;
u8 key_op_ctrl;
unsigned long flags;
struct ieee80211req_key *ik;
CRYPTO_TYPE keyType = NONE_CRYPT;
if(ar->arNetworkType & AP_NETWORK) {
struct net_device *dev = ar->arNetDev;
if(memcmp(dev->dev_addr, bssid, ATH_MAC_LEN)==0) {
ar->arACS = channel;
ik = &ar->ap_mode_bkey;
switch(ar->arAuthMode) {
case NONE_AUTH:
if(ar->arPairwiseCrypto == WEP_CRYPT) {
ar6000_install_static_wep_keys(ar);
}
#ifdef WAPI_ENABLE
else if(ar->arPairwiseCrypto == WAPI_CRYPT) {
ap_set_wapi_key(ar, ik);
}
#endif
break;
case WPA_PSK_AUTH:
case WPA2_PSK_AUTH:
case (WPA_PSK_AUTH|WPA2_PSK_AUTH):
switch (ik->ik_type) {
case IEEE80211_CIPHER_TKIP:
keyType = TKIP_CRYPT;
break;
case IEEE80211_CIPHER_AES_CCM:
keyType = AES_CRYPT;
break;
default:
goto skip_key;
}
wmi_addKey_cmd(ar->arWmi, ik->ik_keyix, keyType, GROUP_USAGE,
ik->ik_keylen, (u8 *)&ik->ik_keyrsc,
ik->ik_keydata, KEY_OP_INIT_VAL, ik->ik_macaddr,
SYNC_BOTH_WMIFLAG);
break;
}
skip_key:
ar->arConnected = true;
return;
}
A_PRINTF("NEW STA %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x \n "
" AID=%d \n", bssid[0], bssid[1], bssid[2],
bssid[3], bssid[4], bssid[5], channel);
switch ((listenInterval>>8)&0xFF) {
case OPEN_AUTH:
A_PRINTF("AUTH: OPEN\n");
break;
case SHARED_AUTH:
A_PRINTF("AUTH: SHARED\n");
break;
default:
A_PRINTF("AUTH: Unknown\n");
break;
}
switch (listenInterval&0xFF) {
case WPA_PSK_AUTH:
A_PRINTF("KeyMgmt: WPA-PSK\n");
break;
case WPA2_PSK_AUTH:
A_PRINTF("KeyMgmt: WPA2-PSK\n");
break;
default:
A_PRINTF("KeyMgmt: NONE\n");
break;
}
switch (beaconInterval) {
case AES_CRYPT:
A_PRINTF("Cipher: AES\n");
break;
case TKIP_CRYPT:
A_PRINTF("Cipher: TKIP\n");
break;
case WEP_CRYPT:
A_PRINTF("Cipher: WEP\n");
break;
#ifdef WAPI_ENABLE
case WAPI_CRYPT:
A_PRINTF("Cipher: WAPI\n");
break;
#endif
default:
A_PRINTF("Cipher: NONE\n");
break;
}
add_new_sta(ar, bssid, channel ,
assocInfo , assocRespLen ,
listenInterval&0xFF , beaconInterval ,
(listenInterval>>8)&0xFF );
A_MEMZERO(&wrqu, sizeof(wrqu));
memcpy(wrqu.addr.sa_data, bssid, ATH_MAC_LEN);
wireless_send_event(ar->arNetDev, IWEVREGISTERED, &wrqu, NULL);
netif_wake_queue(ar->arNetDev);
return;
}
ar6k_cfg80211_connect_event(ar, channel, bssid,
listenInterval, beaconInterval,
networkType, beaconIeLen,
assocReqLen, assocRespLen,
assocInfo);
memcpy(ar->arBssid, bssid, sizeof(ar->arBssid));
ar->arBssChannel = channel;
A_PRINTF("AR6000 connected event on freq %d ", channel);
A_PRINTF("with bssid %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x "
" listenInterval=%d, beaconInterval = %d, beaconIeLen = %d assocReqLen=%d"
" assocRespLen =%d\n",
bssid[0], bssid[1], bssid[2],
bssid[3], bssid[4], bssid[5],
listenInterval, beaconInterval,
beaconIeLen, assocReqLen, assocRespLen);
if (networkType & ADHOC_NETWORK) {
if (networkType & ADHOC_CREATOR) {
A_PRINTF("Network: Adhoc (Creator)\n");
} else {
A_PRINTF("Network: Adhoc (Joiner)\n");
}
} else {
A_PRINTF("Network: Infrastructure\n");
}
if ((ar->arNetworkType == INFRA_NETWORK)) {
wmi_listeninterval_cmd(ar->arWmi, ar->arListenIntervalT, ar->arListenIntervalB);
}
if (beaconIeLen && (sizeof(buf) > (9 + beaconIeLen * 2))) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\nBeaconIEs= "));
beacon_ie_pos = 0;
A_MEMZERO(buf, sizeof(buf));
sprintf(buf, "%s", beaconIetag);
pos = buf + 9;
for (i = beacon_ie_pos; i < beacon_ie_pos + beaconIeLen; i++) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("%2.2x ", assocInfo[i]));
sprintf(pos, "%2.2x", assocInfo[i]);
pos += 2;
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\n"));
A_MEMZERO(&wrqu, sizeof(wrqu));
wrqu.data.length = strlen(buf);
wireless_send_event(ar->arNetDev, IWEVCUSTOM, &wrqu, buf);
}
if (assocRespLen && (sizeof(buf) > (12 + (assocRespLen * 2))))
{
assoc_resp_ie_pos = beaconIeLen + assocReqLen +
sizeof(u16) +
sizeof(u16) +
sizeof(u16) ;
A_MEMZERO(buf, sizeof(buf));
sprintf(buf, "%s", tag2);
pos = buf + 12;
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\nAssocRespIEs= "));
for (i = assoc_resp_ie_pos; i < assoc_resp_ie_pos + assocRespLen - 6; i++)
{
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("%2.2x ", assocInfo[i]));
sprintf(pos, "%2.2x", assocInfo[i]);
pos += 2;
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\n"));
A_MEMZERO(&wrqu, sizeof(wrqu));
wrqu.data.length = strlen(buf);
wireless_send_event(ar->arNetDev, IWEVCUSTOM, &wrqu, buf);
}
if (assocReqLen && (sizeof(buf) > (17 + (assocReqLen * 2)))) {
assoc_req_ie_pos = beaconIeLen +
sizeof(u16) +
sizeof(u16);
A_MEMZERO(buf, sizeof(buf));
sprintf(buf, "%s", tag1);
pos = buf + 17;
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("AssocReqIEs= "));
for (i = assoc_req_ie_pos; i < assoc_req_ie_pos + assocReqLen - 4; i++) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("%2.2x ", assocInfo[i]));
sprintf(pos, "%2.2x", assocInfo[i]);
pos += 2;
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\n"));
A_MEMZERO(&wrqu, sizeof(wrqu));
wrqu.data.length = strlen(buf);
wireless_send_event(ar->arNetDev, IWEVCUSTOM, &wrqu, buf);
}
if (ar->user_savedkeys_stat == USER_SAVEDKEYS_STAT_RUN &&
ar->user_saved_keys.keyOk == true)
{
key_op_ctrl = KEY_OP_VALID_MASK & ~KEY_OP_INIT_TSC;
if (ar->user_key_ctrl & AR6000_USER_SETKEYS_RSC_UNCHANGED) {
key_op_ctrl &= ~KEY_OP_INIT_RSC;
} else {
key_op_ctrl |= KEY_OP_INIT_RSC;
}
ar6000_reinstall_keys(ar, key_op_ctrl);
}
netif_wake_queue(ar->arNetDev);
spin_lock_irqsave(&ar->arLock, flags);
ar->arConnected = true;
ar->arConnectPending = false;
netif_carrier_on(ar->arNetDev);
spin_unlock_irqrestore(&ar->arLock, flags);
aggr_reset_state(ar->aggr_cntxt);
reconnect_flag = 0;
A_MEMZERO(&wrqu, sizeof(wrqu));
memcpy(wrqu.addr.sa_data, bssid, IEEE80211_ADDR_LEN);
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event(ar->arNetDev, SIOCGIWAP, &wrqu, NULL);
if ((ar->arNetworkType == ADHOC_NETWORK) && ar->arIbssPsEnable) {
A_MEMZERO(ar->arNodeMap, sizeof(ar->arNodeMap));
ar->arNodeNum = 0;
ar->arNexEpId = ENDPOINT_2;
}
if (!ar->arUserBssFilter) {
wmi_bssfilter_cmd(ar->arWmi, NONE_BSS_FILTER, 0);
}
}
void ar6000_set_numdataendpts(struct ar6_softc *ar, u32 num)
{
A_ASSERT(num <= (HTC_MAILBOX_NUM_MAX - 1));
ar->arNumDataEndPts = num;
}
void
sta_cleanup(struct ar6_softc *ar, u8 i)
{
struct sk_buff *skb;
A_MUTEX_LOCK(&ar->sta_list[i].psqLock);
while (!A_NETBUF_QUEUE_EMPTY(&ar->sta_list[i].psq)) {
skb = A_NETBUF_DEQUEUE(&ar->sta_list[i].psq);
A_NETBUF_FREE(skb);
}
A_MUTEX_UNLOCK(&ar->sta_list[i].psqLock);
A_MEMZERO(&ar->arAPStats.sta[ar->sta_list[i].aid-1], sizeof(WMI_PER_STA_STAT));
A_MEMZERO(&ar->sta_list[i].mac, ATH_MAC_LEN);
A_MEMZERO(&ar->sta_list[i].wpa_ie, IEEE80211_MAX_IE);
ar->sta_list[i].aid = 0;
ar->sta_list[i].flags = 0;
ar->sta_list_index = ar->sta_list_index & ~(1 << i);
}
u8 remove_sta(struct ar6_softc *ar, u8 *mac, u16 reason)
{
u8 i, removed=0;
if(IS_MAC_NULL(mac)) {
return removed;
}
if(IS_MAC_BCAST(mac)) {
A_PRINTF("DEL ALL STA\n");
for(i=0; i < AP_MAX_NUM_STA; i++) {
if(!IS_MAC_NULL(ar->sta_list[i].mac)) {
sta_cleanup(ar, i);
removed = 1;
}
}
} else {
for(i=0; i < AP_MAX_NUM_STA; i++) {
if(memcmp(ar->sta_list[i].mac, mac, ATH_MAC_LEN)==0) {
A_PRINTF("DEL STA %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x "
" aid=%d REASON=%d\n", mac[0], mac[1], mac[2],
mac[3], mac[4], mac[5], ar->sta_list[i].aid, reason);
sta_cleanup(ar, i);
removed = 1;
break;
}
}
}
return removed;
}
void
ar6000_disconnect_event(struct ar6_softc *ar, u8 reason, u8 *bssid,
u8 assocRespLen, u8 *assocInfo, u16 protocolReasonStatus)
{
u8 i;
unsigned long flags;
union iwreq_data wrqu;
if(ar->arNetworkType & AP_NETWORK) {
union iwreq_data wrqu;
struct sk_buff *skb;
if(!remove_sta(ar, bssid, protocolReasonStatus)) {
return;
}
if (ar->sta_list_index == 0) {
A_MUTEX_LOCK(&ar->mcastpsqLock);
while (!A_NETBUF_QUEUE_EMPTY(&ar->mcastpsq)) {
skb = A_NETBUF_DEQUEUE(&ar->mcastpsq);
A_NETBUF_FREE(skb);
}
A_MUTEX_UNLOCK(&ar->mcastpsqLock);
if (ar->arWmiReady) {
wmi_set_pvb_cmd(ar->arWmi, MCAST_AID, 0);
}
}
if(!IS_MAC_BCAST(bssid)) {
A_MEMZERO(&wrqu, sizeof(wrqu));
memcpy(wrqu.addr.sa_data, bssid, ATH_MAC_LEN);
wireless_send_event(ar->arNetDev, IWEVEXPIRED, &wrqu, NULL);
}
ar->arConnected = false;
return;
}
ar6k_cfg80211_disconnect_event(ar, reason, bssid,
assocRespLen, assocInfo,
protocolReasonStatus);
A_MEMZERO(&wrqu, sizeof(wrqu));
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event(ar->arNetDev, SIOCGIWAP, &wrqu, NULL);
aggr_reset_state(ar->aggr_cntxt);
A_UNTIMEOUT(&ar->disconnect_timer);
A_PRINTF("AR6000 disconnected");
if (bssid[0] || bssid[1] || bssid[2] || bssid[3] || bssid[4] || bssid[5]) {
A_PRINTF(" from %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x ",
bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5]);
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\nDisconnect Reason is %d", reason));
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\nProtocol Reason/Status Code is %d", protocolReasonStatus));
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\nAssocResp Frame = %s",
assocRespLen ? " " : "NULL"));
for (i = 0; i < assocRespLen; i++) {
if (!(i % 0x10)) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\n"));
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("%2.2x ", assocInfo[i]));
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("\n"));
if( reason == DISCONNECT_CMD)
{
if ((!ar->arUserBssFilter) && (ar->arWmiReady)) {
wmi_bssfilter_cmd(ar->arWmi, NONE_BSS_FILTER, 0);
}
} else {
ar->arConnectPending = true;
if (((reason == ASSOC_FAILED) && (protocolReasonStatus == 0x11)) ||
((reason == ASSOC_FAILED) && (protocolReasonStatus == 0x0) && (reconnect_flag == 1))) {
ar->arConnected = true;
return;
}
}
if ((reason == NO_NETWORK_AVAIL) && (ar->arWmiReady))
{
bss_t *pWmiSsidnode = NULL;
wmi_free_node (ar->arWmi, bssid);
do
{
pWmiSsidnode = wmi_find_Ssidnode (ar->arWmi, ar->arSsid, ar->arSsidLen, false, true);
if (pWmiSsidnode)
{
wmi_free_node (ar->arWmi, pWmiSsidnode->ni_macaddr);
}
} while (pWmiSsidnode);
}
spin_lock_irqsave(&ar->arLock, flags);
ar->arConnected = false;
netif_carrier_off(ar->arNetDev);
spin_unlock_irqrestore(&ar->arLock, flags);
if( (reason != CSERV_DISCONNECT) || (reconnect_flag != 1) ) {
reconnect_flag = 0;
}
if (reason != CSERV_DISCONNECT)
{
ar->user_savedkeys_stat = USER_SAVEDKEYS_STAT_INIT;
ar->user_key_ctrl = 0;
}
netif_stop_queue(ar->arNetDev);
A_MEMZERO(ar->arBssid, sizeof(ar->arBssid));
ar->arBssChannel = 0;
ar->arBeaconInterval = 0;
ar6000_TxDataCleanup(ar);
}
void
ar6000_regDomain_event(struct ar6_softc *ar, u32 regCode)
{
A_PRINTF("AR6000 Reg Code = 0x%x\n", regCode);
ar->arRegCode = regCode;
}
void
ar6000_aggr_rcv_addba_req_evt(struct ar6_softc *ar, WMI_ADDBA_REQ_EVENT *evt)
{
if(evt->status == 0) {
aggr_recv_addba_req_evt(ar->aggr_cntxt, evt->tid, evt->st_seq_no, evt->win_sz);
}
}
void
ar6000_aggr_rcv_addba_resp_evt(struct ar6_softc *ar, WMI_ADDBA_RESP_EVENT *evt)
{
A_PRINTF("ADDBA RESP. tid %d status %d, sz %d\n", evt->tid, evt->status, evt->amsdu_sz);
if(evt->status == 0) {
}
}
void
ar6000_aggr_rcv_delba_req_evt(struct ar6_softc *ar, WMI_DELBA_EVENT *evt)
{
aggr_recv_delba_req_evt(ar->aggr_cntxt, evt->tid);
}
void register_pal_cb(ar6k_pal_config_t *palConfig_p)
{
ar6k_pal_config_g = *palConfig_p;
}
void
ar6000_hci_event_rcv_evt(struct ar6_softc *ar, WMI_HCI_EVENT *cmd)
{
void *osbuf = NULL;
s8 i;
u8 size, *buf;
int ret = 0;
size = cmd->evt_buf_sz + 4;
osbuf = A_NETBUF_ALLOC(size);
if (osbuf == NULL) {
ret = A_NO_MEMORY;
A_PRINTF("Error in allocating netbuf \n");
return;
}
A_NETBUF_PUT(osbuf, size);
buf = (u8 *)A_NETBUF_DATA(osbuf);
*((short *)buf) = WMI_HCI_EVENT_EVENTID;
buf += sizeof(int);
memcpy(buf, cmd->buf, cmd->evt_buf_sz);
ar6000_deliver_frames_to_nw_stack(ar->arNetDev, osbuf);
if(loghci) {
A_PRINTF_LOG("HCI Event From PAL <-- \n");
for(i = 0; i < cmd->evt_buf_sz; i++) {
A_PRINTF_LOG("0x%02x ", cmd->buf[i]);
if((i % 10) == 0) {
A_PRINTF_LOG("\n");
}
}
A_PRINTF_LOG("\n");
A_PRINTF_LOG("==================================\n");
}
}
void
ar6000_neighborReport_event(struct ar6_softc *ar, int numAps, WMI_NEIGHBOR_INFO *info)
{
#if WIRELESS_EXT >= 18
struct iw_pmkid_cand *pmkcand;
#else
static const char *tag = "PRE-AUTH";
char buf[128];
#endif
union iwreq_data wrqu;
int i;
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_SCAN,("AR6000 Neighbor Report Event\n"));
for (i=0; i < numAps; info++, i++) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_SCAN,("bssid %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x ",
info->bssid[0], info->bssid[1], info->bssid[2],
info->bssid[3], info->bssid[4], info->bssid[5]));
if (info->bssFlags & WMI_PREAUTH_CAPABLE_BSS) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_SCAN,("preauth-cap"));
}
if (info->bssFlags & WMI_PMKID_VALID_BSS) {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_SCAN,(" pmkid-valid\n"));
continue;
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_SCAN,("\n"));
A_MEMZERO(&wrqu, sizeof(wrqu));
#if WIRELESS_EXT >= 18
pmkcand = A_MALLOC_NOWAIT(sizeof(struct iw_pmkid_cand));
A_MEMZERO(pmkcand, sizeof(struct iw_pmkid_cand));
pmkcand->index = i;
pmkcand->flags = info->bssFlags;
memcpy(pmkcand->bssid.sa_data, info->bssid, ATH_MAC_LEN);
wrqu.data.length = sizeof(struct iw_pmkid_cand);
wireless_send_event(ar->arNetDev, IWEVPMKIDCAND, &wrqu, (char *)pmkcand);
kfree(pmkcand);
#else
snprintf(buf, sizeof(buf), "%s%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x",
tag,
info->bssid[0], info->bssid[1], info->bssid[2],
info->bssid[3], info->bssid[4], info->bssid[5],
i, info->bssFlags);
wrqu.data.length = strlen(buf);
wireless_send_event(ar->arNetDev, IWEVCUSTOM, &wrqu, buf);
#endif
}
}
void
ar6000_tkip_micerr_event(struct ar6_softc *ar, u8 keyid, bool ismcast)
{
static const char *tag = "MLME-MICHAELMICFAILURE.indication";
char buf[128];
union iwreq_data wrqu;
if (ar->arNetworkType == AP_NETWORK) {
sta_t *s = ieee80211_find_conn_for_aid(ar, (keyid >> 2));
if(!s){
A_PRINTF("AP TKIP MIC error received from Invalid aid / STA not found =%d\n", keyid);
return;
}
A_PRINTF("AP TKIP MIC error received from aid=%d\n", keyid);
snprintf(buf,sizeof(buf), "%s addr=%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x",
tag, s->mac[0],s->mac[1],s->mac[2],s->mac[3],s->mac[4],s->mac[5]);
} else {
ar6k_cfg80211_tkip_micerr_event(ar, keyid, ismcast);
A_PRINTF("AR6000 TKIP MIC error received for keyid %d %scast\n",
keyid & 0x3, ismcast ? "multi": "uni");
snprintf(buf, sizeof(buf), "%s(keyid=%d %sicast)", tag, keyid & 0x3,
ismcast ? "mult" : "un");
}
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = strlen(buf);
wireless_send_event(ar->arNetDev, IWEVCUSTOM, &wrqu, buf);
}
void
ar6000_scanComplete_event(struct ar6_softc *ar, int status)
{
ar6k_cfg80211_scanComplete_event(ar, status);
if (!ar->arUserBssFilter) {
wmi_bssfilter_cmd(ar->arWmi, NONE_BSS_FILTER, 0);
}
if (ar->scan_triggered) {
if (status== 0) {
union iwreq_data wrqu;
A_MEMZERO(&wrqu, sizeof(wrqu));
wireless_send_event(ar->arNetDev, SIOCGIWSCAN, &wrqu, NULL);
}
ar->scan_triggered = 0;
}
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_SCAN,( "AR6000 scan complete: %d\n", status));
}
void
ar6000_targetStats_event(struct ar6_softc *ar, u8 *ptr, u32 len)
{
u8 ac;
if(ar->arNetworkType == AP_NETWORK) {
WMI_AP_MODE_STAT *p = (WMI_AP_MODE_STAT *)ptr;
WMI_AP_MODE_STAT *ap = &ar->arAPStats;
if (len < sizeof(*p)) {
return;
}
for(ac=0;ac<AP_MAX_NUM_STA;ac++) {
ap->sta[ac].tx_bytes += p->sta[ac].tx_bytes;
ap->sta[ac].tx_pkts += p->sta[ac].tx_pkts;
ap->sta[ac].tx_error += p->sta[ac].tx_error;
ap->sta[ac].tx_discard += p->sta[ac].tx_discard;
ap->sta[ac].rx_bytes += p->sta[ac].rx_bytes;
ap->sta[ac].rx_pkts += p->sta[ac].rx_pkts;
ap->sta[ac].rx_error += p->sta[ac].rx_error;
ap->sta[ac].rx_discard += p->sta[ac].rx_discard;
}
} else {
WMI_TARGET_STATS *pTarget = (WMI_TARGET_STATS *)ptr;
TARGET_STATS *pStats = &ar->arTargetStats;
if (len < sizeof(*pTarget)) {
return;
}
if (ar->arConnected) {
bss_t *pConnBss = NULL;
pConnBss = wmi_find_node(ar->arWmi,ar->arBssid);
if (pConnBss)
{
pConnBss->ni_rssi = pTarget->cservStats.cs_aveBeacon_rssi;
pConnBss->ni_snr = pTarget->cservStats.cs_aveBeacon_snr;
wmi_node_return(ar->arWmi, pConnBss);
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR6000 updating target stats\n"));
pStats->tx_packets += pTarget->txrxStats.tx_stats.tx_packets;
pStats->tx_bytes += pTarget->txrxStats.tx_stats.tx_bytes;
pStats->tx_unicast_pkts += pTarget->txrxStats.tx_stats.tx_unicast_pkts;
pStats->tx_unicast_bytes += pTarget->txrxStats.tx_stats.tx_unicast_bytes;
pStats->tx_multicast_pkts += pTarget->txrxStats.tx_stats.tx_multicast_pkts;
pStats->tx_multicast_bytes += pTarget->txrxStats.tx_stats.tx_multicast_bytes;
pStats->tx_broadcast_pkts += pTarget->txrxStats.tx_stats.tx_broadcast_pkts;
pStats->tx_broadcast_bytes += pTarget->txrxStats.tx_stats.tx_broadcast_bytes;
pStats->tx_rts_success_cnt += pTarget->txrxStats.tx_stats.tx_rts_success_cnt;
for(ac = 0; ac < WMM_NUM_AC; ac++)
pStats->tx_packet_per_ac[ac] += pTarget->txrxStats.tx_stats.tx_packet_per_ac[ac];
pStats->tx_errors += pTarget->txrxStats.tx_stats.tx_errors;
pStats->tx_failed_cnt += pTarget->txrxStats.tx_stats.tx_failed_cnt;
pStats->tx_retry_cnt += pTarget->txrxStats.tx_stats.tx_retry_cnt;
pStats->tx_mult_retry_cnt += pTarget->txrxStats.tx_stats.tx_mult_retry_cnt;
pStats->tx_rts_fail_cnt += pTarget->txrxStats.tx_stats.tx_rts_fail_cnt;
pStats->tx_unicast_rate = wmi_get_rate(pTarget->txrxStats.tx_stats.tx_unicast_rate);
pStats->rx_packets += pTarget->txrxStats.rx_stats.rx_packets;
pStats->rx_bytes += pTarget->txrxStats.rx_stats.rx_bytes;
pStats->rx_unicast_pkts += pTarget->txrxStats.rx_stats.rx_unicast_pkts;
pStats->rx_unicast_bytes += pTarget->txrxStats.rx_stats.rx_unicast_bytes;
pStats->rx_multicast_pkts += pTarget->txrxStats.rx_stats.rx_multicast_pkts;
pStats->rx_multicast_bytes += pTarget->txrxStats.rx_stats.rx_multicast_bytes;
pStats->rx_broadcast_pkts += pTarget->txrxStats.rx_stats.rx_broadcast_pkts;
pStats->rx_broadcast_bytes += pTarget->txrxStats.rx_stats.rx_broadcast_bytes;
pStats->rx_fragment_pkt += pTarget->txrxStats.rx_stats.rx_fragment_pkt;
pStats->rx_errors += pTarget->txrxStats.rx_stats.rx_errors;
pStats->rx_crcerr += pTarget->txrxStats.rx_stats.rx_crcerr;
pStats->rx_key_cache_miss += pTarget->txrxStats.rx_stats.rx_key_cache_miss;
pStats->rx_decrypt_err += pTarget->txrxStats.rx_stats.rx_decrypt_err;
pStats->rx_duplicate_frames += pTarget->txrxStats.rx_stats.rx_duplicate_frames;
pStats->rx_unicast_rate = wmi_get_rate(pTarget->txrxStats.rx_stats.rx_unicast_rate);
pStats->tkip_local_mic_failure
+= pTarget->txrxStats.tkipCcmpStats.tkip_local_mic_failure;
pStats->tkip_counter_measures_invoked
+= pTarget->txrxStats.tkipCcmpStats.tkip_counter_measures_invoked;
pStats->tkip_replays += pTarget->txrxStats.tkipCcmpStats.tkip_replays;
pStats->tkip_format_errors += pTarget->txrxStats.tkipCcmpStats.tkip_format_errors;
pStats->ccmp_format_errors += pTarget->txrxStats.tkipCcmpStats.ccmp_format_errors;
pStats->ccmp_replays += pTarget->txrxStats.tkipCcmpStats.ccmp_replays;
pStats->power_save_failure_cnt += pTarget->pmStats.power_save_failure_cnt;
pStats->noise_floor_calibation = pTarget->noise_floor_calibation;
pStats->cs_bmiss_cnt += pTarget->cservStats.cs_bmiss_cnt;
pStats->cs_lowRssi_cnt += pTarget->cservStats.cs_lowRssi_cnt;
pStats->cs_connect_cnt += pTarget->cservStats.cs_connect_cnt;
pStats->cs_disconnect_cnt += pTarget->cservStats.cs_disconnect_cnt;
pStats->cs_aveBeacon_snr = pTarget->cservStats.cs_aveBeacon_snr;
pStats->cs_aveBeacon_rssi = pTarget->cservStats.cs_aveBeacon_rssi;
if (enablerssicompensation) {
pStats->cs_aveBeacon_rssi =
rssi_compensation_calc(ar, pStats->cs_aveBeacon_rssi);
}
pStats->cs_lastRoam_msec = pTarget->cservStats.cs_lastRoam_msec;
pStats->cs_snr = pTarget->cservStats.cs_snr;
pStats->cs_rssi = pTarget->cservStats.cs_rssi;
pStats->lq_val = pTarget->lqVal;
pStats->wow_num_pkts_dropped += pTarget->wowStats.wow_num_pkts_dropped;
pStats->wow_num_host_pkt_wakeups += pTarget->wowStats.wow_num_host_pkt_wakeups;
pStats->wow_num_host_event_wakeups += pTarget->wowStats.wow_num_host_event_wakeups;
pStats->wow_num_events_discarded += pTarget->wowStats.wow_num_events_discarded;
pStats->arp_received += pTarget->arpStats.arp_received;
pStats->arp_matched += pTarget->arpStats.arp_matched;
pStats->arp_replied += pTarget->arpStats.arp_replied;
if (ar->statsUpdatePending) {
ar->statsUpdatePending = false;
wake_up(&arEvent);
}
}
}
void
ar6000_rssiThreshold_event(struct ar6_softc *ar, WMI_RSSI_THRESHOLD_VAL newThreshold, s16 rssi)
{
USER_RSSI_THOLD userRssiThold;
rssi = rssi + SIGNAL_QUALITY_NOISE_FLOOR;
if (enablerssicompensation) {
rssi = rssi_compensation_calc(ar, rssi);
}
userRssiThold.tag = ar->rssi_map[newThreshold].tag;
userRssiThold.rssi = rssi;
A_PRINTF("rssi Threshold range = %d tag = %d rssi = %d\n", newThreshold,
userRssiThold.tag, userRssiThold.rssi);
}
void
ar6000_hbChallengeResp_event(struct ar6_softc *ar, u32 cookie, u32 source)
{
if (source != APP_HB_CHALLENGE) {
if (cookie == ar->arHBChallengeResp.seqNum) {
ar->arHBChallengeResp.outstanding = false;
}
}
}
void
ar6000_reportError_event(struct ar6_softc *ar, WMI_TARGET_ERROR_VAL errorVal)
{
static const char * const errString[] = {
[WMI_TARGET_PM_ERR_FAIL] "WMI_TARGET_PM_ERR_FAIL",
[WMI_TARGET_KEY_NOT_FOUND] "WMI_TARGET_KEY_NOT_FOUND",
[WMI_TARGET_DECRYPTION_ERR] "WMI_TARGET_DECRYPTION_ERR",
[WMI_TARGET_BMISS] "WMI_TARGET_BMISS",
[WMI_PSDISABLE_NODE_JOIN] "WMI_PSDISABLE_NODE_JOIN"
};
A_PRINTF("AR6000 Error on Target. Error = 0x%x\n", errorVal);
if(errorVal & (errorVal - 1))
return;
A_PRINTF("AR6000 Error type = ");
switch(errorVal)
{
case WMI_TARGET_PM_ERR_FAIL:
case WMI_TARGET_KEY_NOT_FOUND:
case WMI_TARGET_DECRYPTION_ERR:
case WMI_TARGET_BMISS:
case WMI_PSDISABLE_NODE_JOIN:
A_PRINTF("%s\n", errString[errorVal]);
break;
default:
A_PRINTF("INVALID\n");
break;
}
}
void
ar6000_cac_event(struct ar6_softc *ar, u8 ac, u8 cacIndication,
u8 statusCode, u8 *tspecSuggestion)
{
WMM_TSPEC_IE *tspecIe;
tspecIe = (WMM_TSPEC_IE *)tspecSuggestion;
A_PRINTF("AR6000 CAC notification. "
"AC = %d, cacIndication = 0x%x, statusCode = 0x%x\n",
ac, cacIndication, statusCode);
}
void
ar6000_channel_change_event(struct ar6_softc *ar, u16 oldChannel,
u16 newChannel)
{
A_PRINTF("Channel Change notification\nOld Channel: %d, New Channel: %d\n",
oldChannel, newChannel);
}
void
ar6000_roam_tbl_event(struct ar6_softc *ar, WMI_TARGET_ROAM_TBL *pTbl)
{
u8 i;
A_PRINTF("ROAM TABLE NO OF ENTRIES is %d ROAM MODE is %d\n",
pTbl->numEntries, pTbl->roamMode);
for (i= 0; i < pTbl->numEntries; i++) {
A_PRINTF("[%d]bssid %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x ", i,
pTbl->bssRoamInfo[i].bssid[0], pTbl->bssRoamInfo[i].bssid[1],
pTbl->bssRoamInfo[i].bssid[2],
pTbl->bssRoamInfo[i].bssid[3],
pTbl->bssRoamInfo[i].bssid[4],
pTbl->bssRoamInfo[i].bssid[5]);
A_PRINTF("RSSI %d RSSIDT %d LAST RSSI %d UTIL %d ROAM_UTIL %d"
" BIAS %d\n",
pTbl->bssRoamInfo[i].rssi,
pTbl->bssRoamInfo[i].rssidt,
pTbl->bssRoamInfo[i].last_rssi,
pTbl->bssRoamInfo[i].util,
pTbl->bssRoamInfo[i].roam_util,
pTbl->bssRoamInfo[i].bias);
}
}
void
ar6000_wow_list_event(struct ar6_softc *ar, u8 num_filters, WMI_GET_WOW_LIST_REPLY *wow_reply)
{
u8 i,j;
A_PRINTF("WOW pattern %d of %d patterns\n", wow_reply->this_filter_num, wow_reply->num_filters);
A_PRINTF("wow mode = %s host mode = %s\n",
(wow_reply->wow_mode == 0? "disabled":"enabled"),
(wow_reply->host_mode == 1 ? "awake":"asleep"));
if (wow_reply->this_filter_num) {
i=0;
A_PRINTF("id=%d size=%d offset=%d\n",
wow_reply->wow_filters[i].wow_filter_id,
wow_reply->wow_filters[i].wow_filter_size,
wow_reply->wow_filters[i].wow_filter_offset);
A_PRINTF("wow pattern = ");
for (j=0; j< wow_reply->wow_filters[i].wow_filter_size; j++) {
A_PRINTF("%2.2x",wow_reply->wow_filters[i].wow_filter_pattern[j]);
}
A_PRINTF("\nwow mask = ");
for (j=0; j< wow_reply->wow_filters[i].wow_filter_size; j++) {
A_PRINTF("%2.2x",wow_reply->wow_filters[i].wow_filter_mask[j]);
}
A_PRINTF("\n");
}
}
void
ar6000_display_roam_time(WMI_TARGET_ROAM_TIME *p)
{
A_PRINTF("Disconnect Data : BSSID: ");
AR6000_PRINT_BSSID(p->disassoc_bssid);
A_PRINTF(" RSSI %d DISASSOC Time %d NO_TXRX_TIME %d\n",
p->disassoc_bss_rssi,p->disassoc_time,
p->no_txrx_time);
A_PRINTF("Connect Data: BSSID: ");
AR6000_PRINT_BSSID(p->assoc_bssid);
A_PRINTF(" RSSI %d ASSOC Time %d TXRX_TIME %d\n",
p->assoc_bss_rssi,p->assoc_time,
p->allow_txrx_time);
}
void
ar6000_roam_data_event(struct ar6_softc *ar, WMI_TARGET_ROAM_DATA *p)
{
switch (p->roamDataType) {
case ROAM_DATA_TIME:
ar6000_display_roam_time(&p->u.roamTime);
break;
default:
break;
}
}
void
ar6000_bssInfo_event_rx(struct ar6_softc *ar, u8 *datap, int len)
{
struct sk_buff *skb;
WMI_BSS_INFO_HDR *bih = (WMI_BSS_INFO_HDR *)datap;
if (!ar->arMgmtFilter) {
return;
}
if (((ar->arMgmtFilter & IEEE80211_FILTER_TYPE_BEACON) &&
(bih->frameType != BEACON_FTYPE)) ||
((ar->arMgmtFilter & IEEE80211_FILTER_TYPE_PROBE_RESP) &&
(bih->frameType != PROBERESP_FTYPE)))
{
return;
}
if ((skb = A_NETBUF_ALLOC_RAW(len)) != NULL) {
A_NETBUF_PUT(skb, len);
memcpy(A_NETBUF_DATA(skb), datap, len);
skb->dev = ar->arNetDev;
memcpy(skb_mac_header(skb), A_NETBUF_DATA(skb), 6);
skb->ip_summed = CHECKSUM_NONE;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = __constant_htons(0x0019);
netif_rx(skb);
}
}
int
ar6000_control_tx(void *devt, void *osbuf, HTC_ENDPOINT_ID eid)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
int status = 0;
struct ar_cookie *cookie = NULL;
int i;
#ifdef CONFIG_PM
if (ar->arWowState != WLAN_WOW_STATE_NONE) {
A_NETBUF_FREE(osbuf);
return A_EACCES;
}
#endif
AR6000_SPIN_LOCK(&ar->arLock, 0);
do {
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_TX,("ar_contrstatus = ol_tx: skb=0x%lx, len=0x%x eid =%d\n",
(unsigned long)osbuf, A_NETBUF_LEN(osbuf), eid));
if (ar->arWMIControlEpFull && (eid == ar->arControlEp)) {
cookie = NULL;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" WMI Control EP full, dropping packet : 0x%lX, len:%d \n",
(unsigned long)osbuf, A_NETBUF_LEN(osbuf)));
} else {
cookie = ar6000_alloc_cookie(ar);
}
if (cookie == NULL) {
status = A_NO_MEMORY;
break;
}
if(logWmiRawMsgs) {
A_PRINTF("WMI cmd send, msgNo %d :", wmiSendCmdNum);
for(i = 0; i < a_netbuf_to_len(osbuf); i++)
A_PRINTF("%x ", ((u8 *)a_netbuf_to_data(osbuf))[i]);
A_PRINTF("\n");
}
wmiSendCmdNum++;
} while (false);
if (cookie != NULL) {
ar->arTxPending[eid]++;
if (eid != ar->arControlEp) {
ar->arTotalTxDataPending++;
}
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (cookie != NULL) {
cookie->arc_bp[0] = (unsigned long)osbuf;
cookie->arc_bp[1] = 0;
SET_HTC_PACKET_INFO_TX(&cookie->HtcPkt,
cookie,
A_NETBUF_DATA(osbuf),
A_NETBUF_LEN(osbuf),
eid,
AR6K_CONTROL_PKT_TAG);
HTCSendPkt(ar->arHtcTarget, &cookie->HtcPkt);
status = 0;
}
if (status) {
A_NETBUF_FREE(osbuf);
}
return status;
}
void ar6000_indicate_tx_activity(void *devt, u8 TrafficClass, bool Active)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
HTC_ENDPOINT_ID eid ;
int i;
if (ar->arWmiEnabled) {
eid = arAc2EndpointID(ar, TrafficClass);
AR6000_SPIN_LOCK(&ar->arLock, 0);
ar->arAcStreamActive[TrafficClass] = Active;
if (Active) {
if (ar->arAcStreamPriMap[TrafficClass] > ar->arHiAcStreamActivePri) {
ar->arHiAcStreamActivePri = ar->arAcStreamPriMap[TrafficClass];
}
} else {
if (ar->arHiAcStreamActivePri == ar->arAcStreamPriMap[TrafficClass]) {
ar->arHiAcStreamActivePri = 0;
for (i = 0; i < WMM_NUM_AC; i++) {
if (ar->arAcStreamActive[i]) {
if (ar->arAcStreamPriMap[i] > ar->arHiAcStreamActivePri) {
ar->arHiAcStreamActivePri = ar->arAcStreamPriMap[i];
}
}
}
}
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
} else {
eid = arAc2EndpointID(ar, TrafficClass);
}
HTCIndicateActivityChange(ar->arHtcTarget,
eid,
Active);
}
void
ar6000_btcoex_config_event(struct ar6_softc *ar, u8 *ptr, u32 len)
{
WMI_BTCOEX_CONFIG_EVENT *pBtcoexConfig = (WMI_BTCOEX_CONFIG_EVENT *)ptr;
WMI_BTCOEX_CONFIG_EVENT *pArbtcoexConfig =&ar->arBtcoexConfig;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR6000 BTCOEX CONFIG EVENT \n"));
A_PRINTF("received config event\n");
pArbtcoexConfig->btProfileType = pBtcoexConfig->btProfileType;
pArbtcoexConfig->linkId = pBtcoexConfig->linkId;
switch (pBtcoexConfig->btProfileType) {
case WMI_BTCOEX_BT_PROFILE_SCO:
memcpy(&pArbtcoexConfig->info.scoConfigCmd, &pBtcoexConfig->info.scoConfigCmd,
sizeof(WMI_SET_BTCOEX_SCO_CONFIG_CMD));
break;
case WMI_BTCOEX_BT_PROFILE_A2DP:
memcpy(&pArbtcoexConfig->info.a2dpConfigCmd, &pBtcoexConfig->info.a2dpConfigCmd,
sizeof(WMI_SET_BTCOEX_A2DP_CONFIG_CMD));
break;
case WMI_BTCOEX_BT_PROFILE_ACLCOEX:
memcpy(&pArbtcoexConfig->info.aclcoexConfig, &pBtcoexConfig->info.aclcoexConfig,
sizeof(WMI_SET_BTCOEX_ACLCOEX_CONFIG_CMD));
break;
case WMI_BTCOEX_BT_PROFILE_INQUIRY_PAGE:
memcpy(&pArbtcoexConfig->info.btinquiryPageConfigCmd, &pBtcoexConfig->info.btinquiryPageConfigCmd,
sizeof(WMI_SET_BTCOEX_ACLCOEX_CONFIG_CMD));
break;
}
if (ar->statsUpdatePending) {
ar->statsUpdatePending = false;
wake_up(&arEvent);
}
}
void
ar6000_btcoex_stats_event(struct ar6_softc *ar, u8 *ptr, u32 len)
{
WMI_BTCOEX_STATS_EVENT *pBtcoexStats = (WMI_BTCOEX_STATS_EVENT *)ptr;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR6000 BTCOEX CONFIG EVENT \n"));
memcpy(&ar->arBtcoexStats, pBtcoexStats, sizeof(WMI_BTCOEX_STATS_EVENT));
if (ar->statsUpdatePending) {
ar->statsUpdatePending = false;
wake_up(&arEvent);
}
}
static void
ar6000_cookie_init(struct ar6_softc *ar)
{
u32 i;
ar->arCookieList = NULL;
ar->arCookieCount = 0;
A_MEMZERO(s_ar_cookie_mem, sizeof(s_ar_cookie_mem));
for (i = 0; i < MAX_COOKIE_NUM; i++) {
ar6000_free_cookie(ar, &s_ar_cookie_mem[i]);
}
}
static void
ar6000_cookie_cleanup(struct ar6_softc *ar)
{
ar->arCookieList = NULL;
ar->arCookieCount = 0;
}
static void
ar6000_free_cookie(struct ar6_softc *ar, struct ar_cookie * cookie)
{
A_ASSERT(ar != NULL);
A_ASSERT(cookie != NULL);
cookie->arc_list_next = ar->arCookieList;
ar->arCookieList = cookie;
ar->arCookieCount++;
}
static struct ar_cookie *
ar6000_alloc_cookie(struct ar6_softc *ar)
{
struct ar_cookie *cookie;
cookie = ar->arCookieList;
if(cookie != NULL)
{
ar->arCookieList = cookie->arc_list_next;
ar->arCookieCount--;
}
return cookie;
}
void
ar6000_tx_retry_err_event(void *devt)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Tx retries reach maximum!\n"));
}
void
ar6000_snrThresholdEvent_rx(void *devt, WMI_SNR_THRESHOLD_VAL newThreshold, u8 snr)
{
WMI_SNR_THRESHOLD_EVENT event;
event.range = newThreshold;
event.snr = snr;
}
void
ar6000_lqThresholdEvent_rx(void *devt, WMI_LQ_THRESHOLD_VAL newThreshold, u8 lq)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("lq threshold range %d, lq %d\n", newThreshold, lq));
}
u32 a_copy_to_user(void *to, const void *from, u32 n)
{
return(copy_to_user(to, from, n));
}
u32 a_copy_from_user(void *to, const void *from, u32 n)
{
return(copy_from_user(to, from, n));
}
int
ar6000_get_driver_cfg(struct net_device *dev,
u16 cfgParam,
void *result)
{
int ret = 0;
switch(cfgParam)
{
case AR6000_DRIVER_CFG_GET_WLANNODECACHING:
*((u32 *)result) = wlanNodeCaching;
break;
case AR6000_DRIVER_CFG_LOG_RAW_WMI_MSGS:
*((u32 *)result) = logWmiRawMsgs;
break;
default:
ret = EINVAL;
break;
}
return ret;
}
void
ar6000_keepalive_rx(void *devt, u8 configured)
{
struct ar6_softc *ar = (struct ar6_softc *)devt;
ar->arKeepaliveConfigured = configured;
wake_up(&arEvent);
}
void
ar6000_pmkid_list_event(void *devt, u8 numPMKID, WMI_PMKID *pmkidList,
u8 *bssidList)
{
u8 i, j;
A_PRINTF("Number of Cached PMKIDs is %d\n", numPMKID);
for (i = 0; i < numPMKID; i++) {
A_PRINTF("\nBSSID %d ", i);
for (j = 0; j < ATH_MAC_LEN; j++) {
A_PRINTF("%2.2x", bssidList[j]);
}
bssidList += (ATH_MAC_LEN + WMI_PMKID_LEN);
A_PRINTF("\nPMKID %d ", i);
for (j = 0; j < WMI_PMKID_LEN; j++) {
A_PRINTF("%2.2x", pmkidList->pmkid[j]);
}
pmkidList = (WMI_PMKID *)((u8 *)pmkidList + ATH_MAC_LEN +
WMI_PMKID_LEN);
}
}
void ar6000_pspoll_event(struct ar6_softc *ar,u8 aid)
{
sta_t *conn=NULL;
bool isPsqEmpty = false;
conn = ieee80211_find_conn_for_aid(ar, aid);
A_MUTEX_LOCK(&conn->psqLock);
isPsqEmpty = A_NETBUF_QUEUE_EMPTY(&conn->psq);
A_MUTEX_UNLOCK(&conn->psqLock);
if (isPsqEmpty) {
} else {
struct sk_buff *skb = NULL;
A_MUTEX_LOCK(&conn->psqLock);
skb = A_NETBUF_DEQUEUE(&conn->psq);
A_MUTEX_UNLOCK(&conn->psqLock);
STA_SET_PS_POLLED(conn);
ar6000_data_tx(skb, ar->arNetDev);
STA_CLR_PS_POLLED(conn);
A_MUTEX_LOCK(&conn->psqLock);
isPsqEmpty = A_NETBUF_QUEUE_EMPTY(&conn->psq);
A_MUTEX_UNLOCK(&conn->psqLock);
if (isPsqEmpty) {
wmi_set_pvb_cmd(ar->arWmi, conn->aid, 0);
}
}
}
void ar6000_dtimexpiry_event(struct ar6_softc *ar)
{
bool isMcastQueued = false;
struct sk_buff *skb = NULL;
if (ar->sta_list_index == 0) {
return;
}
A_MUTEX_LOCK(&ar->mcastpsqLock);
isMcastQueued = A_NETBUF_QUEUE_EMPTY(&ar->mcastpsq);
A_MUTEX_UNLOCK(&ar->mcastpsqLock);
A_ASSERT(isMcastQueued == false);
ar->DTIMExpired = true;
A_MUTEX_LOCK(&ar->mcastpsqLock);
while (!A_NETBUF_QUEUE_EMPTY(&ar->mcastpsq)) {
skb = A_NETBUF_DEQUEUE(&ar->mcastpsq);
A_MUTEX_UNLOCK(&ar->mcastpsqLock);
ar6000_data_tx(skb, ar->arNetDev);
A_MUTEX_LOCK(&ar->mcastpsqLock);
}
A_MUTEX_UNLOCK(&ar->mcastpsqLock);
ar->DTIMExpired = false;
wmi_set_pvb_cmd(ar->arWmi, MCAST_AID, 0);
}
void
read_rssi_compensation_param(struct ar6_softc *ar)
{
u8 *cust_data_ptr;
#ifdef RSSICOMPENSATION_PRINT
s16 i;
cust_data_ptr = ar6000_get_cust_data_buffer(ar->arTargetType);
for (i=0; i<16; i++) {
A_PRINTF("cust_data_%d = %x \n", i, *(u8 *)cust_data_ptr);
cust_data_ptr += 1;
}
#endif
cust_data_ptr = ar6000_get_cust_data_buffer(ar->arTargetType);
rssi_compensation_param.customerID = *(u16 *)cust_data_ptr & 0xffff;
rssi_compensation_param.enable = *(u16 *)(cust_data_ptr+2) & 0xffff;
rssi_compensation_param.bg_param_a = *(u16 *)(cust_data_ptr+4) & 0xffff;
rssi_compensation_param.bg_param_b = *(u16 *)(cust_data_ptr+6) & 0xffff;
rssi_compensation_param.a_param_a = *(u16 *)(cust_data_ptr+8) & 0xffff;
rssi_compensation_param.a_param_b = *(u16 *)(cust_data_ptr+10) &0xffff;
rssi_compensation_param.reserved = *(u32 *)(cust_data_ptr+12);
#ifdef RSSICOMPENSATION_PRINT
A_PRINTF("customerID = 0x%x \n", rssi_compensation_param.customerID);
A_PRINTF("enable = 0x%x \n", rssi_compensation_param.enable);
A_PRINTF("bg_param_a = 0x%x and %d \n", rssi_compensation_param.bg_param_a, rssi_compensation_param.bg_param_a);
A_PRINTF("bg_param_b = 0x%x and %d \n", rssi_compensation_param.bg_param_b, rssi_compensation_param.bg_param_b);
A_PRINTF("a_param_a = 0x%x and %d \n", rssi_compensation_param.a_param_a, rssi_compensation_param.a_param_a);
A_PRINTF("a_param_b = 0x%x and %d \n", rssi_compensation_param.a_param_b, rssi_compensation_param.a_param_b);
A_PRINTF("Last 4 bytes = 0x%x \n", rssi_compensation_param.reserved);
#endif
if (rssi_compensation_param.enable != 0x1) {
rssi_compensation_param.enable = 0;
}
return;
}
s32 rssi_compensation_calc_tcmd(u32 freq, s32 rssi, u32 totalPkt)
{
if (freq > 5000)
{
if (rssi_compensation_param.enable)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, (">>> 11a\n"));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi before compensation = %d, totalPkt = %d\n", rssi,totalPkt));
rssi = rssi * rssi_compensation_param.a_param_a + totalPkt * rssi_compensation_param.a_param_b;
rssi = (rssi-50) /100;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi after compensation = %d\n", rssi));
}
}
else
{
if (rssi_compensation_param.enable)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, (">>> 11bg\n"));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi before compensation = %d, totalPkt = %d\n", rssi,totalPkt));
rssi = rssi * rssi_compensation_param.bg_param_a + totalPkt * rssi_compensation_param.bg_param_b;
rssi = (rssi-50) /100;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi after compensation = %d\n", rssi));
}
}
return rssi;
}
s16 rssi_compensation_calc(struct ar6_softc *ar, s16 rssi)
{
if (ar->arBssChannel > 5000)
{
if (rssi_compensation_param.enable)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, (">>> 11a\n"));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi before compensation = %d\n", rssi));
rssi = rssi * rssi_compensation_param.a_param_a + rssi_compensation_param.a_param_b;
rssi = (rssi-50) /100;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi after compensation = %d\n", rssi));
}
}
else
{
if (rssi_compensation_param.enable)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, (">>> 11bg\n"));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi before compensation = %d\n", rssi));
rssi = rssi * rssi_compensation_param.bg_param_a + rssi_compensation_param.bg_param_b;
rssi = (rssi-50) /100;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi after compensation = %d\n", rssi));
}
}
return rssi;
}
s16 rssi_compensation_reverse_calc(struct ar6_softc *ar, s16 rssi, bool Above)
{
s16 i;
if (ar->arBssChannel > 5000)
{
if (rssi_compensation_param.enable)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, (">>> 11a\n"));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi before rev compensation = %d\n", rssi));
rssi = rssi * 100;
rssi = (rssi - rssi_compensation_param.a_param_b) / rssi_compensation_param.a_param_a;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi after rev compensation = %d\n", rssi));
}
}
else
{
if (rssi_compensation_param.enable)
{
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, (">>> 11bg\n"));
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi before rev compensation = %d\n", rssi));
if (Above) {
for (i=95; i>=0; i--) {
if (rssi <= rssi_compensation_table[i]) {
rssi = 0 - i;
break;
}
}
} else {
for (i=0; i<=95; i++) {
if (rssi >= rssi_compensation_table[i]) {
rssi = 0 - i;
break;
}
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO, ("rssi after rev compensation = %d\n", rssi));
}
}
return rssi;
}
void ap_wapi_rekey_event(struct ar6_softc *ar, u8 type, u8 *mac)
{
union iwreq_data wrqu;
char buf[20];
A_MEMZERO(buf, sizeof(buf));
strcpy(buf, "WAPI_REKEY");
buf[10] = type;
memcpy(&buf[11], mac, ATH_MAC_LEN);
A_MEMZERO(&wrqu, sizeof(wrqu));
wrqu.data.length = 10+1+ATH_MAC_LEN;
wireless_send_event(ar->arNetDev, IWEVCUSTOM, &wrqu, buf);
A_PRINTF("WAPI REKEY - %d - %02x:%02x\n", type, mac[4], mac[5]);
}
static int
ar6000_reinstall_keys(struct ar6_softc *ar, u8 key_op_ctrl)
{
int status = 0;
struct ieee80211req_key *uik = &ar->user_saved_keys.ucast_ik;
struct ieee80211req_key *bik = &ar->user_saved_keys.bcast_ik;
CRYPTO_TYPE keyType = ar->user_saved_keys.keyType;
if (IEEE80211_CIPHER_CCKM_KRK != uik->ik_type) {
if (NONE_CRYPT == keyType) {
goto _reinstall_keys_out;
}
if (uik->ik_keylen) {
status = wmi_addKey_cmd(ar->arWmi, uik->ik_keyix,
ar->user_saved_keys.keyType, PAIRWISE_USAGE,
uik->ik_keylen, (u8 *)&uik->ik_keyrsc,
uik->ik_keydata, key_op_ctrl, uik->ik_macaddr, SYNC_BEFORE_WMIFLAG);
}
} else {
status = wmi_add_krk_cmd(ar->arWmi, uik->ik_keydata);
}
if (IEEE80211_CIPHER_CCKM_KRK != bik->ik_type) {
if (NONE_CRYPT == keyType) {
goto _reinstall_keys_out;
}
if (bik->ik_keylen) {
status = wmi_addKey_cmd(ar->arWmi, bik->ik_keyix,
ar->user_saved_keys.keyType, GROUP_USAGE,
bik->ik_keylen, (u8 *)&bik->ik_keyrsc,
bik->ik_keydata, key_op_ctrl, bik->ik_macaddr, NO_SYNC_WMIFLAG);
}
} else {
status = wmi_add_krk_cmd(ar->arWmi, bik->ik_keydata);
}
_reinstall_keys_out:
ar->user_savedkeys_stat = USER_SAVEDKEYS_STAT_INIT;
ar->user_key_ctrl = 0;
return status;
}
void
ar6000_dset_open_req(
void *context,
u32 id,
u32 targHandle,
u32 targReplyFn,
u32 targReplyArg)
{
}
void
ar6000_dset_close(
void *context,
u32 access_cookie)
{
return;
}
void
ar6000_dset_data_req(
void *context,
u32 accessCookie,
u32 offset,
u32 length,
u32 targBuf,
u32 targReplyFn,
u32 targReplyArg)
{
}
int
ar6000_ap_mode_profile_commit(struct ar6_softc *ar)
{
WMI_CONNECT_CMD p;
unsigned long flags;
if(ar->ap_profile_flag==0) {
A_PRINTF("COMMIT: No change in profile!!!\n");
return -ENODATA;
}
if(!ar->arSsidLen) {
A_PRINTF("SSID not set!!!\n");
return -ECHRNG;
}
switch(ar->arAuthMode) {
case NONE_AUTH:
if((ar->arPairwiseCrypto != NONE_CRYPT) &&
#ifdef WAPI_ENABLE
(ar->arPairwiseCrypto != WAPI_CRYPT) &&
#endif
(ar->arPairwiseCrypto != WEP_CRYPT)) {
A_PRINTF("Cipher not supported in AP mode Open auth\n");
return -EOPNOTSUPP;
}
break;
case WPA_PSK_AUTH:
case WPA2_PSK_AUTH:
case (WPA_PSK_AUTH|WPA2_PSK_AUTH):
break;
default:
A_PRINTF("This key mgmt type not supported in AP mode\n");
return -EOPNOTSUPP;
}
ar->arNetworkType = ar->arNextMode;
A_MEMZERO(&p,sizeof(p));
p.ssidLength = ar->arSsidLen;
memcpy(p.ssid,ar->arSsid,p.ssidLength);
p.channel = ar->arChannelHint;
p.networkType = ar->arNetworkType;
p.dot11AuthMode = ar->arDot11AuthMode;
p.authMode = ar->arAuthMode;
p.pairwiseCryptoType = ar->arPairwiseCrypto;
p.pairwiseCryptoLen = ar->arPairwiseCryptoLen;
p.groupCryptoType = ar->arGroupCrypto;
p.groupCryptoLen = ar->arGroupCryptoLen;
p.ctrl_flags = ar->arConnectCtrlFlags;
wmi_ap_profile_commit(ar->arWmi, &p);
spin_lock_irqsave(&ar->arLock, flags);
ar->arConnected = true;
netif_carrier_on(ar->arNetDev);
spin_unlock_irqrestore(&ar->arLock, flags);
ar->ap_profile_flag = 0;
return 0;
}
int
ar6000_connect_to_ap(struct ar6_softc *ar)
{
if((ar->arWmiReady == true) && (ar->arSsidLen > 0) && ar->arNetworkType!=AP_NETWORK)
{
int status;
if((ADHOC_NETWORK != ar->arNetworkType) &&
(NONE_AUTH==ar->arAuthMode) &&
(WEP_CRYPT==ar->arPairwiseCrypto)) {
ar6000_install_static_wep_keys(ar);
}
if (!ar->arUserBssFilter) {
if (wmi_bssfilter_cmd(ar->arWmi, ALL_BSS_FILTER, 0) != 0) {
return -EIO;
}
}
#ifdef WAPI_ENABLE
if (ar->arWapiEnable) {
ar->arPairwiseCrypto = WAPI_CRYPT;
ar->arPairwiseCryptoLen = 0;
ar->arGroupCrypto = WAPI_CRYPT;
ar->arGroupCryptoLen = 0;
ar->arAuthMode = NONE_AUTH;
ar->arConnectCtrlFlags |= CONNECT_IGNORE_WPAx_GROUP_CIPHER;
}
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN_CONNECT,("Connect called with authmode %d dot11 auth %d"\
" PW crypto %d PW crypto Len %d GRP crypto %d"\
" GRP crypto Len %d\n",
ar->arAuthMode, ar->arDot11AuthMode,
ar->arPairwiseCrypto, ar->arPairwiseCryptoLen,
ar->arGroupCrypto, ar->arGroupCryptoLen));
reconnect_flag = 0;
if ((ar->arNetworkType == INFRA_NETWORK)) {
wmi_listeninterval_cmd(ar->arWmi, max(ar->arListenIntervalT, (u16)A_MAX_WOW_LISTEN_INTERVAL), 0);
}
status = wmi_connect_cmd(ar->arWmi, ar->arNetworkType,
ar->arDot11AuthMode, ar->arAuthMode,
ar->arPairwiseCrypto, ar->arPairwiseCryptoLen,
ar->arGroupCrypto,ar->arGroupCryptoLen,
ar->arSsidLen, ar->arSsid,
ar->arReqBssid, ar->arChannelHint,
ar->arConnectCtrlFlags);
if (status) {
wmi_listeninterval_cmd(ar->arWmi, ar->arListenIntervalT, ar->arListenIntervalB);
if (!ar->arUserBssFilter) {
wmi_bssfilter_cmd(ar->arWmi, NONE_BSS_FILTER, 0);
}
return status;
}
if ((!(ar->arConnectCtrlFlags & CONNECT_DO_WPA_OFFLOAD)) &&
((WPA_PSK_AUTH == ar->arAuthMode) || (WPA2_PSK_AUTH == ar->arAuthMode)))
{
A_TIMEOUT_MS(&ar->disconnect_timer, A_DISCONNECT_TIMER_INTERVAL, 0);
}
ar->arConnectCtrlFlags &= ~CONNECT_DO_WPA_OFFLOAD;
ar->arConnectPending = true;
return status;
}
return A_ERROR;
}
int
ar6000_disconnect(struct ar6_softc *ar)
{
if ((ar->arConnected == true) || (ar->arConnectPending == true)) {
wmi_disconnect_cmd(ar->arWmi);
ar->arConnectPending = false;
}
return 0;
}
int
ar6000_ap_mode_get_wpa_ie(struct ar6_softc *ar, struct ieee80211req_wpaie *wpaie)
{
sta_t *conn = NULL;
conn = ieee80211_find_conn(ar, wpaie->wpa_macaddr);
A_MEMZERO(wpaie->wpa_ie, IEEE80211_MAX_IE);
A_MEMZERO(wpaie->rsn_ie, IEEE80211_MAX_IE);
if(conn) {
memcpy(wpaie->wpa_ie, conn->wpa_ie, IEEE80211_MAX_IE);
}
return 0;
}
int
is_iwioctl_allowed(u8 mode, u16 cmd)
{
if(cmd >= SIOCSIWCOMMIT && cmd <= SIOCGIWPOWER) {
cmd -= SIOCSIWCOMMIT;
if(sioctl_filter[cmd] == 0xFF) return 0;
if(sioctl_filter[cmd] & mode) return 0;
} else if(cmd >= SIOCIWFIRSTPRIV && cmd <= (SIOCIWFIRSTPRIV+30)) {
cmd -= SIOCIWFIRSTPRIV;
if(pioctl_filter[cmd] == 0xFF) return 0;
if(pioctl_filter[cmd] & mode) return 0;
} else {
return A_ERROR;
}
return A_ENOTSUP;
}
int
is_xioctl_allowed(u8 mode, int cmd)
{
if(sizeof(xioctl_filter)-1 < cmd) {
A_PRINTF("Filter for this cmd=%d not defined\n",cmd);
return 0;
}
if(xioctl_filter[cmd] == 0xFF) return 0;
if(xioctl_filter[cmd] & mode) return 0;
return A_ERROR;
}
int
ap_set_wapi_key(struct ar6_softc *ar, void *ikey)
{
struct ieee80211req_key *ik = (struct ieee80211req_key *)ikey;
KEY_USAGE keyUsage = 0;
int status;
if (memcmp(ik->ik_macaddr, bcast_mac, IEEE80211_ADDR_LEN) == 0) {
keyUsage = GROUP_USAGE;
} else {
keyUsage = PAIRWISE_USAGE;
}
A_PRINTF("WAPI_KEY: Type:%d ix:%d mac:%02x:%02x len:%d\n",
keyUsage, ik->ik_keyix, ik->ik_macaddr[4], ik->ik_macaddr[5],
ik->ik_keylen);
status = wmi_addKey_cmd(ar->arWmi, ik->ik_keyix, WAPI_CRYPT, keyUsage,
ik->ik_keylen, (u8 *)&ik->ik_keyrsc,
ik->ik_keydata, KEY_OP_INIT_VAL, ik->ik_macaddr,
SYNC_BOTH_WMIFLAG);
if (0 != status) {
return -EIO;
}
return 0;
}
void ar6000_peer_event(
void *context,
u8 eventCode,
u8 *macAddr)
{
u8 pos;
for (pos=0;pos<6;pos++)
printk("%02x: ",*(macAddr+pos));
printk("\n");
}
static void DoHTCSendPktsTest(struct ar6_softc *ar, int MapNo, HTC_ENDPOINT_ID eid, struct sk_buff *dupskb)
{
struct ar_cookie *cookie;
struct ar_cookie *cookieArray[HTC_TEST_DUPLICATE];
struct sk_buff *new_skb;
int i;
int pkts = 0;
struct htc_packet_queue pktQueue;
EPPING_HEADER *eppingHdr;
eppingHdr = A_NETBUF_DATA(dupskb);
if (eppingHdr->Cmd_h == EPPING_CMD_NO_ECHO) {
return;
}
for (i = 0; i < HTC_TEST_DUPLICATE; i++,pkts++) {
AR6000_SPIN_LOCK(&ar->arLock, 0);
cookie = ar6000_alloc_cookie(ar);
if (cookie != NULL) {
ar->arTxPending[eid]++;
ar->arTotalTxDataPending++;
}
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
if (NULL == cookie) {
break;
}
new_skb = A_NETBUF_ALLOC(A_NETBUF_LEN(dupskb));
if (new_skb == NULL) {
AR6000_SPIN_LOCK(&ar->arLock, 0);
ar6000_free_cookie(ar,cookie);
AR6000_SPIN_UNLOCK(&ar->arLock, 0);
break;
}
A_NETBUF_PUT_DATA(new_skb, A_NETBUF_DATA(dupskb), A_NETBUF_LEN(dupskb));
cookie->arc_bp[0] = (unsigned long)new_skb;
cookie->arc_bp[1] = MapNo;
SET_HTC_PACKET_INFO_TX(&cookie->HtcPkt,
cookie,
A_NETBUF_DATA(new_skb),
A_NETBUF_LEN(new_skb),
eid,
AR6K_DATA_PKT_TAG);
cookieArray[i] = cookie;
{
EPPING_HEADER *pHdr = (EPPING_HEADER *)A_NETBUF_DATA(new_skb);
pHdr->Cmd_h = EPPING_CMD_NO_ECHO;
}
}
if (pkts == 0) {
return;
}
INIT_HTC_PACKET_QUEUE(&pktQueue);
for (i = 0; i < pkts; i++) {
HTC_PACKET_ENQUEUE(&pktQueue,&cookieArray[i]->HtcPkt);
}
HTCSendPktsMultiple(ar->arHtcTarget, &pktQueue);
}
int ar6000_start_ap_interface(struct ar6_softc *ar)
{
struct ar_virtual_interface *arApDev;
arApDev = (struct ar_virtual_interface *)ar->arApDev;
ar->arNetDev = arApDev->arNetDev;
return 0;
}
int ar6000_stop_ap_interface(struct ar6_softc *ar)
{
struct ar_virtual_interface *arApDev;
arApDev = (struct ar_virtual_interface *)ar->arApDev;
if (arApDev) {
ar->arNetDev = arApDev->arStaNetDev;
}
return 0;
}
int ar6000_create_ap_interface(struct ar6_softc *ar, char *ap_ifname)
{
struct net_device *dev;
struct ar_virtual_interface *arApDev;
dev = alloc_etherdev(sizeof(struct ar_virtual_interface));
if (dev == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_create_ap_interface: can't alloc etherdev\n"));
return A_ERROR;
}
ether_setup(dev);
init_netdev(dev, ap_ifname);
if (register_netdev(dev)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_create_ap_interface: register_netdev failed\n"));
return A_ERROR;
}
arApDev = netdev_priv(dev);
arApDev->arDev = ar;
arApDev->arNetDev = dev;
arApDev->arStaNetDev = ar->arNetDev;
ar->arApDev = arApDev;
arApNetDev = dev;
memcpy(dev->dev_addr, ar->arNetDev->dev_addr, AR6000_ETH_ADDR_LEN);
return 0;
}
int ar6000_add_ap_interface(struct ar6_softc *ar, char *ap_ifname)
{
if (ar->arApDev != NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("ar6000_add_ap_interface: interface already present \n"));
return 0;
}
if (ar6000_create_ap_interface(ar, ap_ifname) != 0) {
return A_ERROR;
}
A_PRINTF("Add AP interface %s \n",ap_ifname);
return ar6000_start_ap_interface(ar);
}
int ar6000_remove_ap_interface(struct ar6_softc *ar)
{
if (arApNetDev) {
ar6000_stop_ap_interface(ar);
unregister_netdev(arApNetDev);
free_netdev(apApNetDev);
A_PRINTF("Remove AP interface\n");
}
ar->arApDev = NULL;
arApNetDev = NULL;
return 0;
}
