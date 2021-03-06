void Hci_log(u8 * log_string,u8 *data,u32 len)
{
int i;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s : ",log_string));
for (i = 0; i < len; i++) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("0x%02x ", data[i]));
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("\n...................................\n"));
}
int AthPSInitialize(struct ar3k_config_info *hdev)
{
int status = 0;
if(hdev == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Invalid Device handle received\n"));
return A_ERROR;
}
#ifndef HCI_TRANSPORT_SDIO
DECLARE_WAITQUEUE(wait, current);
#endif
#ifdef HCI_TRANSPORT_SDIO
status = PSSendOps((void*)hdev);
#else
if(InitPSState(hdev) == -1) {
return A_ERROR;
}
allow_signal(SIGKILL);
add_wait_queue(&PsCompleteEvent,&wait);
set_current_state(TASK_INTERRUPTIBLE);
if(!kernel_thread(PSSendOps,(void*)hdev,CLONE_FS|CLONE_FILES|CLONE_SIGHAND|SIGCHLD)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Kthread Failed\n"));
remove_wait_queue(&PsCompleteEvent,&wait);
return A_ERROR;
}
wait_event_interruptible(PsCompleteEvent,(PSTagMode == false));
set_current_state(TASK_RUNNING);
remove_wait_queue(&PsCompleteEvent,&wait);
#endif
return status;
}
int PSSendOps(void *arg)
{
int i;
int status = 0;
struct ps_cmd_packet *HciCmdList;
const struct firmware* firmware;
u32 numCmds;
u8 *event;
u8 *bufferToFree;
struct hci_dev *device;
u8 *buffer;
u32 len;
u32 DevType;
u8 *PsFileName;
u8 *patchFileName;
u8 *path = NULL;
u8 *config_path = NULL;
u8 config_bdaddr[MAX_BDADDR_FORMAT_LENGTH];
struct ar3k_config_info *hdev = (struct ar3k_config_info*)arg;
struct device *firmwareDev = NULL;
status = 0;
HciCmdList = NULL;
#ifdef HCI_TRANSPORT_SDIO
device = hdev->pBtStackHCIDev;
firmwareDev = device->parent;
#else
device = hdev;
firmwareDev = &device->dev;
AthEnableSyncCommandOp(true);
#endif
path =(u8 *)A_MALLOC(MAX_FW_PATH_LEN);
if(path == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Malloc failed to allocate %d bytes for path\n", MAX_FW_PATH_LEN));
goto complete;
}
config_path = (u8 *) A_MALLOC(MAX_FW_PATH_LEN);
if(config_path == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Malloc failed to allocate %d bytes for config_path\n", MAX_FW_PATH_LEN));
goto complete;
}
if(A_ERROR == getDeviceType(hdev,&DevType)) {
status = 1;
goto complete;
}
if(A_ERROR == ReadVersionInfo(hdev)) {
status = 1;
goto complete;
}
patchFileName = PATCH_FILE;
snprintf(path, MAX_FW_PATH_LEN, "%s/%xcoex/",CONFIG_PATH,Rom_Version);
if(DevType){
if(DevType == 0xdeadc0de){
PsFileName = PS_ASIC_FILE;
} else{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" FPGA Test Image : %x %x \n",Rom_Version,Build_Version));
if((Rom_Version == 0x99999999) && (Build_Version == 1)){
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("FPGA Test Image : Skipping Patch File load\n"));
patchFileName = NULL;
}
PsFileName = PS_FPGA_FILE;
}
}
else{
PsFileName = PS_ASIC_FILE;
}
snprintf(config_path, MAX_FW_PATH_LEN, "%s%s",path,PsFileName);
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%x: FPGA/ASIC PS File Name %s\n", DevType,config_path));
if(A_REQUEST_FIRMWARE(&firmware,config_path,firmwareDev) < 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s: firmware file open error\n", __FUNCTION__ ));
status = 1;
goto complete;
}
if(NULL == firmware || firmware->size == 0) {
status = 1;
goto complete;
}
buffer = (u8 *)A_MALLOC(firmware->size);
if(buffer != NULL) {
memcpy(buffer,firmware->data,firmware->size);
len = firmware->size;
A_RELEASE_FIRMWARE(firmware);
status = AthDoParsePS(buffer,len);
kfree(buffer);
} else {
A_RELEASE_FIRMWARE(firmware);
}
if(patchFileName != NULL)
snprintf(config_path,
MAX_FW_PATH_LEN, "%s%s",path,patchFileName);
else {
status = 0;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Patch File Name %s\n", config_path));
if((patchFileName == NULL) || (A_REQUEST_FIRMWARE(&firmware,config_path,firmwareDev) < 0)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s: firmware file open error\n", __FUNCTION__ ));
status = 0;
} else {
if(NULL == firmware || firmware->size == 0) {
status = 0;
} else {
buffer = (u8 *)A_MALLOC(firmware->size);
if(buffer != NULL) {
memcpy(buffer,firmware->data,firmware->size);
len = firmware->size;
A_RELEASE_FIRMWARE(firmware);
status = AthDoParsePatch(buffer,len);
kfree(buffer);
} else {
A_RELEASE_FIRMWARE(firmware);
}
}
}
AthCreateCommandList(&HciCmdList,&numCmds);
if(SendHCICommandWaitCommandComplete
(hdev,
HciCmdList[0].Hcipacket,
HciCmdList[0].packetLen,
&event,
&bufferToFree) == 0) {
if(ReadPSEvent(event) == 0) {
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
#ifndef HCI_TRANSPORT_SDIO
if(bdaddr && bdaddr[0] !='\0') {
write_bdaddr(hdev,bdaddr,BDADDR_TYPE_STRING);
}
#endif
status = 1;
goto complete;
}
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
} else {
status = 0;
goto complete;
}
for(i = 1; i <numCmds; i++) {
if(SendHCICommandWaitCommandComplete
(hdev,
HciCmdList[i].Hcipacket,
HciCmdList[i].packetLen,
&event,
&bufferToFree) == 0) {
if(ReadPSEvent(event) != 0) {
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
status = 1;
goto complete;
}
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
} else {
status = 0;
goto complete;
}
}
#ifdef HCI_TRANSPORT_SDIO
if(BDADDR == false)
if(hdev->bdaddr[0] !=0x00 ||
hdev->bdaddr[1] !=0x00 ||
hdev->bdaddr[2] !=0x00 ||
hdev->bdaddr[3] !=0x00 ||
hdev->bdaddr[4] !=0x00 ||
hdev->bdaddr[5] !=0x00)
write_bdaddr(hdev,hdev->bdaddr,BDADDR_TYPE_HEX);
#ifndef HCI_TRANSPORT_SDIO
if(bdaddr && bdaddr[0] != '\0') {
write_bdaddr(hdev,bdaddr,BDADDR_TYPE_STRING);
} else
#endif
#endif
{
snprintf(config_path,MAX_FW_PATH_LEN, "%s%s",path,BDADDR_FILE);
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Patch File Name %s\n", config_path));
if(A_REQUEST_FIRMWARE(&firmware,config_path,firmwareDev) < 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("%s: firmware file open error\n", __FUNCTION__ ));
status = 1;
goto complete;
}
if(NULL == firmware || firmware->size == 0) {
status = 1;
goto complete;
}
len = min_t(size_t, firmware->size, MAX_BDADDR_FORMAT_LENGTH - 1);
memcpy(config_bdaddr, firmware->data, len);
config_bdaddr[len] = '\0';
write_bdaddr(hdev,config_bdaddr,BDADDR_TYPE_STRING);
A_RELEASE_FIRMWARE(firmware);
}
complete:
#ifndef HCI_TRANSPORT_SDIO
AthEnableSyncCommandOp(false);
PSTagMode = false;
wake_up_interruptible(&PsCompleteEvent);
#endif
if(NULL != HciCmdList) {
AthFreeCommandList(&HciCmdList,numCmds);
}
if(path) {
kfree(path);
}
if(config_path) {
kfree(config_path);
}
return status;
}
int SendHCICommandWaitCommandComplete(struct ar3k_config_info *pConfig,
u8 *pHCICommand,
int CmdLength,
u8 **ppEventBuffer,
u8 **ppBufferToFree)
{
if(CmdLength == 0) {
return A_ERROR;
}
Hci_log("COM Write -->",pHCICommand,CmdLength);
PSAcked = false;
if(PSHciWritepacket(pConfig,pHCICommand,CmdLength) == 0) {
return A_ERROR;
}
wait_event_interruptible(HciEvent,(PSAcked == true));
if(NULL != HciEventpacket) {
*ppEventBuffer = HciEventpacket;
*ppBufferToFree = HciEventpacket;
} else {
*ppBufferToFree = NULL;
return A_ERROR;
}
return 0;
}
int ReadPSEvent(u8* Data){
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" PS Event %x %x %x\n",Data[4],Data[5],Data[3]));
if(Data[4] == 0xFC && Data[5] == 0x00)
{
switch(Data[3]){
case 0x0B:
return 0;
break;
case 0x0C:
return 0;
break;
case 0x04:
return 0;
break;
case 0x1E:
Rom_Version = Data[9];
Rom_Version = ((Rom_Version << 8) |Data[8]);
Rom_Version = ((Rom_Version << 8) |Data[7]);
Rom_Version = ((Rom_Version << 8) |Data[6]);
Build_Version = Data[13];
Build_Version = ((Build_Version << 8) |Data[12]);
Build_Version = ((Build_Version << 8) |Data[11]);
Build_Version = ((Build_Version << 8) |Data[10]);
return 0;
break;
}
}
return A_ERROR;
}
int str2ba(unsigned char *str_bdaddr,unsigned char *bdaddr)
{
unsigned char bdbyte[3];
unsigned char *str_byte = str_bdaddr;
int i,j;
unsigned char colon_present = 0;
if(NULL != strstr(str_bdaddr,":")) {
colon_present = 1;
}
bdbyte[2] = '\0';
for( i = 0,j = 5; i < 6; i++, j--) {
bdbyte[0] = str_byte[0];
bdbyte[1] = str_byte[1];
bdaddr[j] = A_STRTOL(bdbyte,NULL,16);
if(colon_present == 1) {
str_byte+=3;
} else {
str_byte+=2;
}
}
return 0;
}
int write_bdaddr(struct ar3k_config_info *pConfig,u8 *bdaddr,int type)
{
u8 bdaddr_cmd[] = { 0x0B, 0xFC, 0x0A, 0x01, 0x01,
0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
u8 *event;
u8 *bufferToFree = NULL;
int result = A_ERROR;
int inc,outc;
if (type == BDADDR_TYPE_STRING)
str2ba(bdaddr,&bdaddr_cmd[7]);
else {
for(inc = 5 ,outc = 7; inc >=0; inc--, outc++)
bdaddr_cmd[outc] = bdaddr[inc];
}
if(0 == SendHCICommandWaitCommandComplete(pConfig,bdaddr_cmd,
sizeof(bdaddr_cmd),
&event,&bufferToFree)) {
if(event[4] == 0xFC && event[5] == 0x00){
if(event[3] == 0x0B){
result = 0;
}
}
}
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
return result;
}
int ReadVersionInfo(struct ar3k_config_info *pConfig)
{
u8 hciCommand[] = {0x1E,0xfc,0x00};
u8 *event;
u8 *bufferToFree = NULL;
int result = A_ERROR;
if(0 == SendHCICommandWaitCommandComplete(pConfig,hciCommand,sizeof(hciCommand),&event,&bufferToFree)) {
result = ReadPSEvent(event);
}
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
return result;
}
int getDeviceType(struct ar3k_config_info *pConfig, u32 *code)
{
u8 hciCommand[] = {0x05,0xfc,0x05,0x00,0x00,0x00,0x00,0x04};
u8 *event;
u8 *bufferToFree = NULL;
u32 reg;
int result = A_ERROR;
*code = 0;
hciCommand[3] = (u8)(FPGA_REGISTER & 0xFF);
hciCommand[4] = (u8)((FPGA_REGISTER >> 8) & 0xFF);
hciCommand[5] = (u8)((FPGA_REGISTER >> 16) & 0xFF);
hciCommand[6] = (u8)((FPGA_REGISTER >> 24) & 0xFF);
if(0 == SendHCICommandWaitCommandComplete(pConfig,hciCommand,sizeof(hciCommand),&event,&bufferToFree)) {
if(event[4] == 0xFC && event[5] == 0x00){
switch(event[3]){
case 0x05:
reg = event[9];
reg = ((reg << 8) |event[8]);
reg = ((reg << 8) |event[7]);
reg = ((reg << 8) |event[6]);
*code = reg;
result = 0;
break;
case 0x06:
break;
}
}
}
if(bufferToFree != NULL) {
kfree(bufferToFree);
}
return result;
}
