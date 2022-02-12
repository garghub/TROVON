void
BMIInit(void)
{
bmiDone = false;
pendingEventsFuncCheck = false;
if (!pBMICmdCredits) {
pBMICmdCredits = (u32 *)A_MALLOC_NOWAIT(4);
A_ASSERT(pBMICmdCredits);
}
if (!pBMICmdBuf) {
pBMICmdBuf = (u8 *)A_MALLOC_NOWAIT(MAX_BMI_CMDBUF_SZ);
A_ASSERT(pBMICmdBuf);
}
A_REGISTER_MODULE_DEBUG_INFO(bmi);
}
void
BMICleanup(void)
{
if (pBMICmdCredits) {
kfree(pBMICmdCredits);
pBMICmdCredits = NULL;
}
if (pBMICmdBuf) {
kfree(pBMICmdBuf);
pBMICmdBuf = NULL;
}
}
int
BMIDone(struct hif_device *device)
{
int status;
u32 cid;
if (bmiDone) {
AR_DEBUG_PRINTF (ATH_DEBUG_BMI, ("BMIDone skipped\n"));
return 0;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Done: Enter (device: 0x%p)\n", device));
bmiDone = true;
cid = BMI_DONE;
status = bmiBufferSend(device, (u8 *)&cid, sizeof(cid));
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
if (pBMICmdCredits) {
kfree(pBMICmdCredits);
pBMICmdCredits = NULL;
}
if (pBMICmdBuf) {
kfree(pBMICmdBuf);
pBMICmdBuf = NULL;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Done: Exit\n"));
return 0;
}
int
BMIGetTargetInfo(struct hif_device *device, struct bmi_target_info *targ_info)
{
int status;
u32 cid;
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Get Target Info: Enter (device: 0x%p)\n", device));
cid = BMI_GET_TARGET_INFO;
status = bmiBufferSend(device, (u8 *)&cid, sizeof(cid));
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
status = bmiBufferReceive(device, (u8 *)&targ_info->target_ver,
sizeof(targ_info->target_ver), true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read Target Version from the device\n"));
return A_ERROR;
}
if (targ_info->target_ver == TARGET_VERSION_SENTINAL) {
status = bmiBufferReceive(device, (u8 *)&targ_info->target_info_byte_count,
sizeof(targ_info->target_info_byte_count), true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read Target Info Byte Count from the device\n"));
return A_ERROR;
}
A_ASSERT(targ_info->target_info_byte_count == sizeof(*targ_info));
status = bmiBufferReceive(device,
((u8 *)targ_info)+sizeof(targ_info->target_info_byte_count),
sizeof(*targ_info)-sizeof(targ_info->target_info_byte_count), true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read Target Info (%d bytes) from the device\n",
targ_info->target_info_byte_count));
return A_ERROR;
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Get Target Info: Exit (ver: 0x%x type: 0x%x)\n",
targ_info->target_ver, targ_info->target_type));
return 0;
}
int
BMIReadMemory(struct hif_device *device,
u32 address,
u8 *buffer,
u32 length)
{
u32 cid;
int status;
u32 offset;
u32 remaining, rxlen;
A_ASSERT(BMI_COMMAND_FITS(BMI_DATASZ_MAX + sizeof(cid) + sizeof(address) + sizeof(length)));
memset (pBMICmdBuf, 0, BMI_DATASZ_MAX + sizeof(cid) + sizeof(address) + sizeof(length));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Read Memory: Enter (device: 0x%p, address: 0x%x, length: %d)\n",
device, address, length));
cid = BMI_READ_MEMORY;
remaining = length;
while (remaining)
{
rxlen = (remaining < BMI_DATASZ_MAX) ? remaining : BMI_DATASZ_MAX;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
memcpy(&(pBMICmdBuf[offset]), &rxlen, sizeof(rxlen));
offset += sizeof(length);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
status = bmiBufferReceive(device, pBMICmdBuf, rxlen, true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read from the device\n"));
return A_ERROR;
}
memcpy(&buffer[length - remaining], pBMICmdBuf, rxlen);
remaining -= rxlen; address += rxlen;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Read Memory: Exit\n"));
return 0;
}
int
BMIWriteMemory(struct hif_device *device,
u32 address,
u8 *buffer,
u32 length)
{
u32 cid;
int status;
u32 offset;
u32 remaining, txlen;
const u32 header = sizeof(cid) + sizeof(address) + sizeof(length);
u8 alignedBuffer[BMI_DATASZ_MAX];
u8 *src;
A_ASSERT(BMI_COMMAND_FITS(BMI_DATASZ_MAX + header));
memset (pBMICmdBuf, 0, BMI_DATASZ_MAX + header);
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Write Memory: Enter (device: 0x%p, address: 0x%x, length: %d)\n",
device, address, length));
cid = BMI_WRITE_MEMORY;
remaining = length;
while (remaining)
{
src = &buffer[length - remaining];
if (remaining < (BMI_DATASZ_MAX - header)) {
if (remaining & 3) {
remaining = remaining + (4 - (remaining & 3));
memcpy(alignedBuffer, src, remaining);
src = alignedBuffer;
}
txlen = remaining;
} else {
txlen = (BMI_DATASZ_MAX - header);
}
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
memcpy(&(pBMICmdBuf[offset]), &txlen, sizeof(txlen));
offset += sizeof(txlen);
memcpy(&(pBMICmdBuf[offset]), src, txlen);
offset += txlen;
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
remaining -= txlen; address += txlen;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Write Memory: Exit\n"));
return 0;
}
int
BMIExecute(struct hif_device *device,
u32 address,
u32 *param)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(address) + sizeof(param)));
memset (pBMICmdBuf, 0, sizeof(cid) + sizeof(address) + sizeof(param));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Execute: Enter (device: 0x%p, address: 0x%x, param: %d)\n",
device, address, *param));
cid = BMI_EXECUTE;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
memcpy(&(pBMICmdBuf[offset]), param, sizeof(*param));
offset += sizeof(*param);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
status = bmiBufferReceive(device, pBMICmdBuf, sizeof(*param), false);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read from the device\n"));
return A_ERROR;
}
memcpy(param, pBMICmdBuf, sizeof(*param));
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Execute: Exit (param: %d)\n", *param));
return 0;
}
int
BMISetAppStart(struct hif_device *device,
u32 address)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(address)));
memset (pBMICmdBuf, 0, sizeof(cid) + sizeof(address));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Set App Start: Enter (device: 0x%p, address: 0x%x)\n",
device, address));
cid = BMI_SET_APP_START;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Set App Start: Exit\n"));
return 0;
}
int
BMIReadSOCRegister(struct hif_device *device,
u32 address,
u32 *param)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(address)));
memset (pBMICmdBuf, 0, sizeof(cid) + sizeof(address));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Read SOC Register: Enter (device: 0x%p, address: 0x%x)\n",
device, address));
cid = BMI_READ_SOC_REGISTER;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
status = bmiBufferReceive(device, pBMICmdBuf, sizeof(*param), true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read from the device\n"));
return A_ERROR;
}
memcpy(param, pBMICmdBuf, sizeof(*param));
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Read SOC Register: Exit (value: %d)\n", *param));
return 0;
}
int
BMIWriteSOCRegister(struct hif_device *device,
u32 address,
u32 param)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(address) + sizeof(param)));
memset (pBMICmdBuf, 0, sizeof(cid) + sizeof(address) + sizeof(param));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Write SOC Register: Enter (device: 0x%p, address: 0x%x, param: %d)\n",
device, address, param));
cid = BMI_WRITE_SOC_REGISTER;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
memcpy(&(pBMICmdBuf[offset]), &param, sizeof(param));
offset += sizeof(param);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Read SOC Register: Exit\n"));
return 0;
}
int
BMIrompatchInstall(struct hif_device *device,
u32 ROM_addr,
u32 RAM_addr,
u32 nbytes,
u32 do_activate,
u32 *rompatch_id)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(ROM_addr) + sizeof(RAM_addr) +
sizeof(nbytes) + sizeof(do_activate)));
memset(pBMICmdBuf, 0, sizeof(cid) + sizeof(ROM_addr) + sizeof(RAM_addr) +
sizeof(nbytes) + sizeof(do_activate));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI rompatch Install: Enter (device: 0x%p, ROMaddr: 0x%x, RAMaddr: 0x%x length: %d activate: %d)\n",
device, ROM_addr, RAM_addr, nbytes, do_activate));
cid = BMI_ROMPATCH_INSTALL;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &ROM_addr, sizeof(ROM_addr));
offset += sizeof(ROM_addr);
memcpy(&(pBMICmdBuf[offset]), &RAM_addr, sizeof(RAM_addr));
offset += sizeof(RAM_addr);
memcpy(&(pBMICmdBuf[offset]), &nbytes, sizeof(nbytes));
offset += sizeof(nbytes);
memcpy(&(pBMICmdBuf[offset]), &do_activate, sizeof(do_activate));
offset += sizeof(do_activate);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
status = bmiBufferReceive(device, pBMICmdBuf, sizeof(*rompatch_id), true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read from the device\n"));
return A_ERROR;
}
memcpy(rompatch_id, pBMICmdBuf, sizeof(*rompatch_id));
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI rompatch Install: (rompatch_id=%d)\n", *rompatch_id));
return 0;
}
int
BMIrompatchUninstall(struct hif_device *device,
u32 rompatch_id)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(rompatch_id)));
memset (pBMICmdBuf, 0, sizeof(cid) + sizeof(rompatch_id));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI rompatch Uninstall: Enter (device: 0x%p, rompatch_id: %d)\n",
device, rompatch_id));
cid = BMI_ROMPATCH_UNINSTALL;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &rompatch_id, sizeof(rompatch_id));
offset += sizeof(rompatch_id);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI rompatch UNinstall: (rompatch_id=0x%x)\n", rompatch_id));
return 0;
}
static int
_BMIrompatchChangeActivation(struct hif_device *device,
u32 rompatch_count,
u32 *rompatch_list,
u32 do_activate)
{
u32 cid;
int status;
u32 offset;
u32 length;
A_ASSERT(BMI_COMMAND_FITS(BMI_DATASZ_MAX + sizeof(cid) + sizeof(rompatch_count)));
memset(pBMICmdBuf, 0, BMI_DATASZ_MAX + sizeof(cid) + sizeof(rompatch_count));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Change rompatch Activation: Enter (device: 0x%p, count: %d)\n",
device, rompatch_count));
cid = do_activate ? BMI_ROMPATCH_ACTIVATE : BMI_ROMPATCH_DEACTIVATE;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &rompatch_count, sizeof(rompatch_count));
offset += sizeof(rompatch_count);
length = rompatch_count * sizeof(*rompatch_list);
memcpy(&(pBMICmdBuf[offset]), rompatch_list, length);
offset += length;
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI Change rompatch Activation: Exit\n"));
return 0;
}
int
BMIrompatchActivate(struct hif_device *device,
u32 rompatch_count,
u32 *rompatch_list)
{
return _BMIrompatchChangeActivation(device, rompatch_count, rompatch_list, 1);
}
int
BMIrompatchDeactivate(struct hif_device *device,
u32 rompatch_count,
u32 *rompatch_list)
{
return _BMIrompatchChangeActivation(device, rompatch_count, rompatch_list, 0);
}
int
BMILZData(struct hif_device *device,
u8 *buffer,
u32 length)
{
u32 cid;
int status;
u32 offset;
u32 remaining, txlen;
const u32 header = sizeof(cid) + sizeof(length);
A_ASSERT(BMI_COMMAND_FITS(BMI_DATASZ_MAX+header));
memset (pBMICmdBuf, 0, BMI_DATASZ_MAX+header);
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI Send LZ Data: Enter (device: 0x%p, length: %d)\n",
device, length));
cid = BMI_LZ_DATA;
remaining = length;
while (remaining)
{
txlen = (remaining < (BMI_DATASZ_MAX - header)) ?
remaining : (BMI_DATASZ_MAX - header);
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &txlen, sizeof(txlen));
offset += sizeof(txlen);
memcpy(&(pBMICmdBuf[offset]), &buffer[length - remaining], txlen);
offset += txlen;
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to write to the device\n"));
return A_ERROR;
}
remaining -= txlen;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI LZ Data: Exit\n"));
return 0;
}
int
BMILZStreamStart(struct hif_device *device,
u32 address)
{
u32 cid;
int status;
u32 offset;
A_ASSERT(BMI_COMMAND_FITS(sizeof(cid) + sizeof(address)));
memset (pBMICmdBuf, 0, sizeof(cid) + sizeof(address));
if (bmiDone) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Command disallowed\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI,
("BMI LZ Stream Start: Enter (device: 0x%p, address: 0x%x)\n",
device, address));
cid = BMI_LZ_STREAM_START;
offset = 0;
memcpy(&(pBMICmdBuf[offset]), &cid, sizeof(cid));
offset += sizeof(cid);
memcpy(&(pBMICmdBuf[offset]), &address, sizeof(address));
offset += sizeof(address);
status = bmiBufferSend(device, pBMICmdBuf, offset);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to Start LZ Stream to the device\n"));
return A_ERROR;
}
AR_DEBUG_PRINTF(ATH_DEBUG_BMI, ("BMI LZ Stream Start: Exit\n"));
return 0;
}
int
bmiBufferSend(struct hif_device *device,
u8 *buffer,
u32 length)
{
int status;
u32 timeout;
u32 address;
u32 mboxAddress[HTC_MAILBOX_NUM_MAX];
HIFConfigureDevice(device, HIF_DEVICE_GET_MBOX_ADDR,
&mboxAddress[0], sizeof(mboxAddress));
*pBMICmdCredits = 0;
timeout = BMI_COMMUNICATION_TIMEOUT;
while(timeout-- && !(*pBMICmdCredits)) {
address = COUNT_DEC_ADDRESS + (HTC_MAILBOX_NUM_MAX + ENDPOINT1) * 4;
status = HIFReadWrite(device, address, (u8 *)pBMICmdCredits, 4,
HIF_RD_SYNC_BYTE_INC, NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to decrement the command credit count register\n"));
return A_ERROR;
}
(*pBMICmdCredits) &= 0xFF;
}
if (*pBMICmdCredits) {
address = mboxAddress[ENDPOINT1];
status = HIFReadWrite(device, address, buffer, length,
HIF_WR_SYNC_BYTE_INC, NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to send the BMI data to the device\n"));
return A_ERROR;
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI Communication timeout - bmiBufferSend\n"));
return A_ERROR;
}
return status;
}
int
bmiBufferReceive(struct hif_device *device,
u8 *buffer,
u32 length,
bool want_timeout)
{
int status;
u32 address;
u32 mboxAddress[HTC_MAILBOX_NUM_MAX];
struct hif_pending_events_info hifPendingEvents;
static HIF_PENDING_EVENTS_FUNC getPendingEventsFunc = NULL;
if (!pendingEventsFuncCheck) {
HIFConfigureDevice(device,
HIF_DEVICE_GET_PENDING_EVENTS_FUNC,
&getPendingEventsFunc,
sizeof(getPendingEventsFunc));
pendingEventsFuncCheck = true;
}
HIFConfigureDevice(device, HIF_DEVICE_GET_MBOX_ADDR,
&mboxAddress[0], sizeof(mboxAddress));
if (length >= 4) {
static u32 word_available;
u32 timeout;
word_available = 0;
timeout = BMI_COMMUNICATION_TIMEOUT;
while((!want_timeout || timeout--) && !word_available) {
if (getPendingEventsFunc != NULL) {
status = getPendingEventsFunc(device,
&hifPendingEvents,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("BMI: Failed to get pending events \n"));
break;
}
if (hifPendingEvents.AvailableRecvBytes >= sizeof(u32)) {
word_available = 1;
}
continue;
}
status = HIFReadWrite(device, RX_LOOKAHEAD_VALID_ADDRESS, (u8 *)&word_available,
sizeof(word_available), HIF_RD_SYNC_BYTE_INC, NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read RX_LOOKAHEAD_VALID register\n"));
return A_ERROR;
}
word_available &= (1 << ENDPOINT1);
}
if (!word_available) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI Communication timeout - bmiBufferReceive FIFO empty\n"));
return A_ERROR;
}
}
#define CONSERVATIVE_BMI_READ 0
#if CONSERVATIVE_BMI_READ
if ((length > 4) && (length < 128)) {
u32 timeout;
*pBMICmdCredits = 0;
timeout = BMI_COMMUNICATION_TIMEOUT;
while((!want_timeout || timeout--) && !(*pBMICmdCredits) {
address = COUNT_ADDRESS + (HTC_MAILBOX_NUM_MAX + ENDPOINT1) * 1;
status = HIFReadWrite(device, address, (u8 *)pBMICmdCredits, sizeof(*pBMICmdCredits),
HIF_RD_SYNC_BYTE_FIX, NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read the command credit count register\n"));
return A_ERROR;
}
(*pBMICmdCredits) &= 0xFF;
}
if (!(*pBMICmdCredits)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMI Communication timeout- bmiBufferReceive no credit\n"));
return A_ERROR;
}
}
#endif
address = mboxAddress[ENDPOINT1];
status = HIFReadWrite(device, address, buffer, length, HIF_RD_SYNC_BYTE_INC, NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to read the BMI data from the device\n"));
return A_ERROR;
}
return 0;
}
int
BMIFastDownload(struct hif_device *device, u32 address, u8 *buffer, u32 length)
{
int status = A_ERROR;
u32 lastWord = 0;
u32 lastWordOffset = length & ~0x3;
u32 unalignedBytes = length & 0x3;
status = BMILZStreamStart (device, address);
if (status) {
return A_ERROR;
}
if (unalignedBytes) {
memcpy(&lastWord, &buffer[lastWordOffset], unalignedBytes);
}
status = BMILZData(device, buffer, lastWordOffset);
if (status) {
return A_ERROR;
}
if (unalignedBytes) {
status = BMILZData(device, (u8 *)&lastWord, 4);
}
if (!status) {
status = BMILZStreamStart (device, 0x00);
if (status) {
return A_ERROR;
}
}
return status;
}
int
BMIRawWrite(struct hif_device *device, u8 *buffer, u32 length)
{
return bmiBufferSend(device, buffer, length);
}
int
BMIRawRead(struct hif_device *device, u8 *buffer, u32 length, bool want_timeout)
{
return bmiBufferReceive(device, buffer, length, want_timeout);
}
