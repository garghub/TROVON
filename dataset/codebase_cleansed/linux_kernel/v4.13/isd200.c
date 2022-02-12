static void isd200_build_sense(struct us_data *us, struct scsi_cmnd *srb)
{
struct isd200_info *info = (struct isd200_info *)us->extra;
struct sense_data *buf = (struct sense_data *) &srb->sense_buffer[0];
unsigned char error = info->ATARegs[ATA_REG_ERROR_OFFSET];
if(error & ATA_ERROR_MEDIA_CHANGE) {
buf->ErrorCode = 0x70 | SENSE_ERRCODE_VALID;
buf->AdditionalSenseLength = 0xb;
buf->Flags = UNIT_ATTENTION;
buf->AdditionalSenseCode = 0;
buf->AdditionalSenseCodeQualifier = 0;
} else if (error & ATA_MCR) {
buf->ErrorCode = 0x70 | SENSE_ERRCODE_VALID;
buf->AdditionalSenseLength = 0xb;
buf->Flags = UNIT_ATTENTION;
buf->AdditionalSenseCode = 0;
buf->AdditionalSenseCodeQualifier = 0;
} else if (error & ATA_TRK0NF) {
buf->ErrorCode = 0x70 | SENSE_ERRCODE_VALID;
buf->AdditionalSenseLength = 0xb;
buf->Flags = NOT_READY;
buf->AdditionalSenseCode = 0;
buf->AdditionalSenseCodeQualifier = 0;
} else if (error & ATA_UNC) {
buf->ErrorCode = 0x70 | SENSE_ERRCODE_VALID;
buf->AdditionalSenseLength = 0xb;
buf->Flags = DATA_PROTECT;
buf->AdditionalSenseCode = 0;
buf->AdditionalSenseCodeQualifier = 0;
} else {
buf->ErrorCode = 0;
buf->AdditionalSenseLength = 0;
buf->Flags = 0;
buf->AdditionalSenseCode = 0;
buf->AdditionalSenseCodeQualifier = 0;
}
}
static void isd200_set_srb(struct isd200_info *info,
enum dma_data_direction dir, void* buff, unsigned bufflen)
{
struct scsi_cmnd *srb = &info->srb;
if (buff)
sg_init_one(&info->sg, buff, bufflen);
srb->sc_data_direction = dir;
srb->sdb.table.sgl = buff ? &info->sg : NULL;
srb->sdb.length = bufflen;
srb->sdb.table.nents = buff ? 1 : 0;
}
static void isd200_srb_set_bufflen(struct scsi_cmnd *srb, unsigned bufflen)
{
srb->sdb.length = bufflen;
}
static int isd200_action( struct us_data *us, int action,
void* pointer, int value )
{
union ata_cdb ata;
static struct scsi_device srb_dev;
struct isd200_info *info = (struct isd200_info *)us->extra;
struct scsi_cmnd *srb = &info->srb;
int status;
memset(&ata, 0, sizeof(ata));
srb->cmnd = info->cmnd;
srb->device = &srb_dev;
ata.generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ata.generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ata.generic.TransferBlockSize = 1;
switch ( action ) {
case ACTION_READ_STATUS:
usb_stor_dbg(us, " isd200_action(READ_STATUS)\n");
ata.generic.ActionSelect = ACTION_SELECT_0|ACTION_SELECT_2;
ata.generic.RegisterSelect =
REG_CYLINDER_LOW | REG_CYLINDER_HIGH |
REG_STATUS | REG_ERROR;
isd200_set_srb(info, DMA_FROM_DEVICE, pointer, value);
break;
case ACTION_ENUM:
usb_stor_dbg(us, " isd200_action(ENUM,0x%02x)\n", value);
ata.generic.ActionSelect = ACTION_SELECT_1|ACTION_SELECT_2|
ACTION_SELECT_3|ACTION_SELECT_4|
ACTION_SELECT_5;
ata.generic.RegisterSelect = REG_DEVICE_HEAD;
ata.write.DeviceHeadByte = value;
isd200_set_srb(info, DMA_NONE, NULL, 0);
break;
case ACTION_RESET:
usb_stor_dbg(us, " isd200_action(RESET)\n");
ata.generic.ActionSelect = ACTION_SELECT_1|ACTION_SELECT_2|
ACTION_SELECT_3|ACTION_SELECT_4;
ata.generic.RegisterSelect = REG_DEVICE_CONTROL;
ata.write.DeviceControlByte = ATA_DC_RESET_CONTROLLER;
isd200_set_srb(info, DMA_NONE, NULL, 0);
break;
case ACTION_REENABLE:
usb_stor_dbg(us, " isd200_action(REENABLE)\n");
ata.generic.ActionSelect = ACTION_SELECT_1|ACTION_SELECT_2|
ACTION_SELECT_3|ACTION_SELECT_4;
ata.generic.RegisterSelect = REG_DEVICE_CONTROL;
ata.write.DeviceControlByte = ATA_DC_REENABLE_CONTROLLER;
isd200_set_srb(info, DMA_NONE, NULL, 0);
break;
case ACTION_SOFT_RESET:
usb_stor_dbg(us, " isd200_action(SOFT_RESET)\n");
ata.generic.ActionSelect = ACTION_SELECT_1|ACTION_SELECT_5;
ata.generic.RegisterSelect = REG_DEVICE_HEAD | REG_COMMAND;
ata.write.DeviceHeadByte = info->DeviceHead;
ata.write.CommandByte = ATA_CMD_DEV_RESET;
isd200_set_srb(info, DMA_NONE, NULL, 0);
break;
case ACTION_IDENTIFY:
usb_stor_dbg(us, " isd200_action(IDENTIFY)\n");
ata.generic.RegisterSelect = REG_COMMAND;
ata.write.CommandByte = ATA_CMD_ID_ATA;
isd200_set_srb(info, DMA_FROM_DEVICE, info->id,
ATA_ID_WORDS * 2);
break;
default:
usb_stor_dbg(us, "Error: Undefined action %d\n", action);
return ISD200_ERROR;
}
memcpy(srb->cmnd, &ata, sizeof(ata.generic));
srb->cmd_len = sizeof(ata.generic);
status = usb_stor_Bulk_transport(srb, us);
if (status == USB_STOR_TRANSPORT_GOOD)
status = ISD200_GOOD;
else {
usb_stor_dbg(us, " isd200_action(0x%02x) error: %d\n",
action, status);
status = ISD200_ERROR;
}
return status;
}
static int isd200_read_regs( struct us_data *us )
{
struct isd200_info *info = (struct isd200_info *)us->extra;
int retStatus = ISD200_GOOD;
int transferStatus;
usb_stor_dbg(us, "Entering isd200_IssueATAReadRegs\n");
transferStatus = isd200_action( us, ACTION_READ_STATUS,
info->RegsBuf, sizeof(info->ATARegs) );
if (transferStatus != ISD200_TRANSPORT_GOOD) {
usb_stor_dbg(us, " Error reading ATA registers\n");
retStatus = ISD200_ERROR;
} else {
memcpy(info->ATARegs, info->RegsBuf, sizeof(info->ATARegs));
usb_stor_dbg(us, " Got ATA Register[ATA_REG_ERROR_OFFSET] = 0x%x\n",
info->ATARegs[ATA_REG_ERROR_OFFSET]);
}
return retStatus;
}
static void isd200_invoke_transport( struct us_data *us,
struct scsi_cmnd *srb,
union ata_cdb *ataCdb )
{
int need_auto_sense = 0;
int transferStatus;
int result;
memcpy(srb->cmnd, ataCdb, sizeof(ataCdb->generic));
srb->cmd_len = sizeof(ataCdb->generic);
transferStatus = usb_stor_Bulk_transport(srb, us);
if (test_bit(US_FLIDX_TIMED_OUT, &us->dflags)) {
usb_stor_dbg(us, "-- command was aborted\n");
goto Handle_Abort;
}
switch (transferStatus) {
case USB_STOR_TRANSPORT_GOOD:
srb->result = SAM_STAT_GOOD;
break;
case USB_STOR_TRANSPORT_NO_SENSE:
usb_stor_dbg(us, "-- transport indicates protocol failure\n");
srb->result = SAM_STAT_CHECK_CONDITION;
return;
case USB_STOR_TRANSPORT_FAILED:
usb_stor_dbg(us, "-- transport indicates command failure\n");
need_auto_sense = 1;
break;
case USB_STOR_TRANSPORT_ERROR:
usb_stor_dbg(us, "-- transport indicates transport error\n");
srb->result = DID_ERROR << 16;
return;
default:
usb_stor_dbg(us, "-- transport indicates unknown error\n");
srb->result = DID_ERROR << 16;
return;
}
if ((scsi_get_resid(srb) > 0) &&
!((srb->cmnd[0] == REQUEST_SENSE) ||
(srb->cmnd[0] == INQUIRY) ||
(srb->cmnd[0] == MODE_SENSE) ||
(srb->cmnd[0] == LOG_SENSE) ||
(srb->cmnd[0] == MODE_SENSE_10))) {
usb_stor_dbg(us, "-- unexpectedly short transfer\n");
need_auto_sense = 1;
}
if (need_auto_sense) {
result = isd200_read_regs(us);
if (test_bit(US_FLIDX_TIMED_OUT, &us->dflags)) {
usb_stor_dbg(us, "-- auto-sense aborted\n");
goto Handle_Abort;
}
if (result == ISD200_GOOD) {
isd200_build_sense(us, srb);
srb->result = SAM_STAT_CHECK_CONDITION;
if ((srb->sense_buffer[2] & 0xf) == 0x0)
srb->result = SAM_STAT_GOOD;
} else {
srb->result = DID_ERROR << 16;
}
}
if (transferStatus == USB_STOR_TRANSPORT_FAILED)
srb->result = SAM_STAT_CHECK_CONDITION;
return;
Handle_Abort:
srb->result = DID_ABORT << 16;
clear_bit(US_FLIDX_ABORTING, &us->dflags);
}
static void isd200_log_config(struct us_data *us, struct isd200_info *info)
{
usb_stor_dbg(us, " Event Notification: 0x%x\n",
info->ConfigData.EventNotification);
usb_stor_dbg(us, " External Clock: 0x%x\n",
info->ConfigData.ExternalClock);
usb_stor_dbg(us, " ATA Init Timeout: 0x%x\n",
info->ConfigData.ATAInitTimeout);
usb_stor_dbg(us, " ATAPI Command Block Size: 0x%x\n",
(info->ConfigData.ATAConfig & ATACFG_BLOCKSIZE) >> 6);
usb_stor_dbg(us, " Master/Slave Selection: 0x%x\n",
info->ConfigData.ATAConfig & ATACFG_MASTER);
usb_stor_dbg(us, " ATAPI Reset: 0x%x\n",
info->ConfigData.ATAConfig & ATACFG_ATAPI_RESET);
usb_stor_dbg(us, " ATA Timing: 0x%x\n",
info->ConfigData.ATAConfig & ATACFG_TIMING);
usb_stor_dbg(us, " ATA Major Command: 0x%x\n",
info->ConfigData.ATAMajorCommand);
usb_stor_dbg(us, " ATA Minor Command: 0x%x\n",
info->ConfigData.ATAMinorCommand);
usb_stor_dbg(us, " Init Status: 0x%x\n",
info->ConfigData.ATAExtraConfig & ATACFGE_INIT_STATUS);
usb_stor_dbg(us, " Config Descriptor 2: 0x%x\n",
info->ConfigData.ATAExtraConfig & ATACFGE_CONF_DESC2);
usb_stor_dbg(us, " Skip Device Boot: 0x%x\n",
info->ConfigData.ATAExtraConfig & ATACFGE_SKIP_BOOT);
usb_stor_dbg(us, " ATA 3 State Suspend: 0x%x\n",
info->ConfigData.ATAExtraConfig & ATACFGE_STATE_SUSPEND);
usb_stor_dbg(us, " Descriptor Override: 0x%x\n",
info->ConfigData.ATAExtraConfig & ATACFGE_DESC_OVERRIDE);
usb_stor_dbg(us, " Last LUN Identifier: 0x%x\n",
info->ConfigData.ATAExtraConfig & ATACFGE_LAST_LUN);
usb_stor_dbg(us, " SRST Enable: 0x%x\n",
info->ConfigData.ATAExtraConfig & CFG_CAPABILITY_SRST);
}
static int isd200_write_config( struct us_data *us )
{
struct isd200_info *info = (struct isd200_info *)us->extra;
int retStatus = ISD200_GOOD;
int result;
#ifdef CONFIG_USB_STORAGE_DEBUG
usb_stor_dbg(us, "Entering isd200_write_config\n");
usb_stor_dbg(us, " Writing the following ISD200 Config Data:\n");
isd200_log_config(us, info);
#endif
result = usb_stor_ctrl_transfer(
us,
us->send_ctrl_pipe,
0x01,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
0x0000,
0x0002,
(void *) &info->ConfigData,
sizeof(info->ConfigData));
if (result >= 0) {
usb_stor_dbg(us, " ISD200 Config Data was written successfully\n");
} else {
usb_stor_dbg(us, " Request to write ISD200 Config Data failed!\n");
retStatus = ISD200_ERROR;
}
usb_stor_dbg(us, "Leaving isd200_write_config %08X\n", retStatus);
return retStatus;
}
static int isd200_read_config( struct us_data *us )
{
struct isd200_info *info = (struct isd200_info *)us->extra;
int retStatus = ISD200_GOOD;
int result;
usb_stor_dbg(us, "Entering isd200_read_config\n");
result = usb_stor_ctrl_transfer(
us,
us->recv_ctrl_pipe,
0x02,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x0000,
0x0002,
(void *) &info->ConfigData,
sizeof(info->ConfigData));
if (result >= 0) {
usb_stor_dbg(us, " Retrieved the following ISD200 Config Data:\n");
#ifdef CONFIG_USB_STORAGE_DEBUG
isd200_log_config(us, info);
#endif
} else {
usb_stor_dbg(us, " Request to get ISD200 Config Data failed!\n");
retStatus = ISD200_ERROR;
}
usb_stor_dbg(us, "Leaving isd200_read_config %08X\n", retStatus);
return retStatus;
}
static int isd200_atapi_soft_reset( struct us_data *us )
{
int retStatus = ISD200_GOOD;
int transferStatus;
usb_stor_dbg(us, "Entering isd200_atapi_soft_reset\n");
transferStatus = isd200_action( us, ACTION_SOFT_RESET, NULL, 0 );
if (transferStatus != ISD200_TRANSPORT_GOOD) {
usb_stor_dbg(us, " Error issuing Atapi Soft Reset\n");
retStatus = ISD200_ERROR;
}
usb_stor_dbg(us, "Leaving isd200_atapi_soft_reset %08X\n", retStatus);
return retStatus;
}
static int isd200_srst( struct us_data *us )
{
int retStatus = ISD200_GOOD;
int transferStatus;
usb_stor_dbg(us, "Entering isd200_SRST\n");
transferStatus = isd200_action( us, ACTION_RESET, NULL, 0 );
if (transferStatus != ISD200_TRANSPORT_GOOD) {
usb_stor_dbg(us, " Error issuing SRST\n");
retStatus = ISD200_ERROR;
} else {
msleep(10);
transferStatus = isd200_action( us, ACTION_REENABLE, NULL, 0 );
if (transferStatus != ISD200_TRANSPORT_GOOD) {
usb_stor_dbg(us, " Error taking drive out of reset\n");
retStatus = ISD200_ERROR;
} else {
msleep(50);
}
}
usb_stor_dbg(us, "Leaving isd200_srst %08X\n", retStatus);
return retStatus;
}
static int isd200_try_enum(struct us_data *us, unsigned char master_slave,
int detect )
{
int status = ISD200_GOOD;
unsigned long endTime;
struct isd200_info *info = (struct isd200_info *)us->extra;
unsigned char *regs = info->RegsBuf;
int recheckAsMaster = 0;
if ( detect )
endTime = jiffies + ISD200_ENUM_DETECT_TIMEOUT * HZ;
else
endTime = jiffies + ISD200_ENUM_BSY_TIMEOUT * HZ;
while(1) {
status = isd200_action( us, ACTION_ENUM, NULL, master_slave );
if ( status != ISD200_GOOD )
break;
status = isd200_action( us, ACTION_READ_STATUS,
regs, 8 );
if ( status != ISD200_GOOD )
break;
if (!detect) {
if (regs[ATA_REG_STATUS_OFFSET] & ATA_BUSY) {
usb_stor_dbg(us, " %s status is still BSY, try again...\n",
master_slave == ATA_ADDRESS_DEVHEAD_STD ?
"Master" : "Slave");
} else {
usb_stor_dbg(us, " %s status !BSY, continue with next operation\n",
master_slave == ATA_ADDRESS_DEVHEAD_STD ?
"Master" : "Slave");
break;
}
}
else if (regs[ATA_REG_STATUS_OFFSET] &
(ATA_BUSY | ATA_DF | ATA_ERR)) {
usb_stor_dbg(us, " Status indicates it is not ready, try again...\n");
}
else if (regs[ATA_REG_STATUS_OFFSET] & ATA_DRDY) {
usb_stor_dbg(us, " Identified ATA device\n");
info->DeviceFlags |= DF_ATA_DEVICE;
info->DeviceHead = master_slave;
break;
}
else if (regs[ATA_REG_HCYL_OFFSET] == 0xEB &&
regs[ATA_REG_LCYL_OFFSET] == 0x14) {
if ((master_slave & ATA_ADDRESS_DEVHEAD_SLAVE) &&
!recheckAsMaster) {
usb_stor_dbg(us, " Identified ATAPI device as slave. Rechecking again as master\n");
recheckAsMaster = 1;
master_slave = ATA_ADDRESS_DEVHEAD_STD;
} else {
usb_stor_dbg(us, " Identified ATAPI device\n");
info->DeviceHead = master_slave;
status = isd200_atapi_soft_reset(us);
break;
}
} else {
usb_stor_dbg(us, " Not ATA, not ATAPI - Weird\n");
break;
}
if (time_after_eq(jiffies, endTime)) {
if (!detect)
usb_stor_dbg(us, " BSY check timeout, just continue with next operation...\n");
else
usb_stor_dbg(us, " Device detect timeout!\n");
break;
}
}
return status;
}
static int isd200_manual_enum(struct us_data *us)
{
struct isd200_info *info = (struct isd200_info *)us->extra;
int retStatus = ISD200_GOOD;
usb_stor_dbg(us, "Entering isd200_manual_enum\n");
retStatus = isd200_read_config(us);
if (retStatus == ISD200_GOOD) {
int isslave;
retStatus = isd200_try_enum( us, ATA_ADDRESS_DEVHEAD_STD, 0);
if (retStatus == ISD200_GOOD)
retStatus = isd200_try_enum( us, ATA_ADDRESS_DEVHEAD_SLAVE, 0);
if (retStatus == ISD200_GOOD) {
retStatus = isd200_srst(us);
if (retStatus == ISD200_GOOD)
retStatus = isd200_try_enum( us, ATA_ADDRESS_DEVHEAD_STD, 1);
}
isslave = (info->DeviceHead & ATA_ADDRESS_DEVHEAD_SLAVE) ? 1 : 0;
if (!(info->ConfigData.ATAConfig & ATACFG_MASTER)) {
usb_stor_dbg(us, " Setting Master/Slave selection to %d\n",
isslave);
info->ConfigData.ATAConfig &= 0x3f;
info->ConfigData.ATAConfig |= (isslave<<6);
retStatus = isd200_write_config(us);
}
}
usb_stor_dbg(us, "Leaving isd200_manual_enum %08X\n", retStatus);
return(retStatus);
}
static void isd200_fix_driveid(u16 *id)
{
#ifndef __LITTLE_ENDIAN
# ifdef __BIG_ENDIAN
int i;
for (i = 0; i < ATA_ID_WORDS; i++)
id[i] = __le16_to_cpu(id[i]);
# else
# error "Please fix <asm/byteorder.h>"
# endif
#endif
}
static void isd200_dump_driveid(struct us_data *us, u16 *id)
{
usb_stor_dbg(us, " Identify Data Structure:\n");
usb_stor_dbg(us, " config = 0x%x\n", id[ATA_ID_CONFIG]);
usb_stor_dbg(us, " cyls = 0x%x\n", id[ATA_ID_CYLS]);
usb_stor_dbg(us, " heads = 0x%x\n", id[ATA_ID_HEADS]);
usb_stor_dbg(us, " track_bytes = 0x%x\n", id[4]);
usb_stor_dbg(us, " sector_bytes = 0x%x\n", id[5]);
usb_stor_dbg(us, " sectors = 0x%x\n", id[ATA_ID_SECTORS]);
usb_stor_dbg(us, " serial_no[0] = 0x%x\n", *(char *)&id[ATA_ID_SERNO]);
usb_stor_dbg(us, " buf_type = 0x%x\n", id[20]);
usb_stor_dbg(us, " buf_size = 0x%x\n", id[ATA_ID_BUF_SIZE]);
usb_stor_dbg(us, " ecc_bytes = 0x%x\n", id[22]);
usb_stor_dbg(us, " fw_rev[0] = 0x%x\n", *(char *)&id[ATA_ID_FW_REV]);
usb_stor_dbg(us, " model[0] = 0x%x\n", *(char *)&id[ATA_ID_PROD]);
usb_stor_dbg(us, " max_multsect = 0x%x\n", id[ATA_ID_MAX_MULTSECT] & 0xff);
usb_stor_dbg(us, " dword_io = 0x%x\n", id[ATA_ID_DWORD_IO]);
usb_stor_dbg(us, " capability = 0x%x\n", id[ATA_ID_CAPABILITY] >> 8);
usb_stor_dbg(us, " tPIO = 0x%x\n", id[ATA_ID_OLD_PIO_MODES] >> 8);
usb_stor_dbg(us, " tDMA = 0x%x\n", id[ATA_ID_OLD_DMA_MODES] >> 8);
usb_stor_dbg(us, " field_valid = 0x%x\n", id[ATA_ID_FIELD_VALID]);
usb_stor_dbg(us, " cur_cyls = 0x%x\n", id[ATA_ID_CUR_CYLS]);
usb_stor_dbg(us, " cur_heads = 0x%x\n", id[ATA_ID_CUR_HEADS]);
usb_stor_dbg(us, " cur_sectors = 0x%x\n", id[ATA_ID_CUR_SECTORS]);
usb_stor_dbg(us, " cur_capacity = 0x%x\n", ata_id_u32(id, 57));
usb_stor_dbg(us, " multsect = 0x%x\n", id[ATA_ID_MULTSECT] & 0xff);
usb_stor_dbg(us, " lba_capacity = 0x%x\n", ata_id_u32(id, ATA_ID_LBA_CAPACITY));
usb_stor_dbg(us, " command_set_1 = 0x%x\n", id[ATA_ID_COMMAND_SET_1]);
usb_stor_dbg(us, " command_set_2 = 0x%x\n", id[ATA_ID_COMMAND_SET_2]);
}
static int isd200_get_inquiry_data( struct us_data *us )
{
struct isd200_info *info = (struct isd200_info *)us->extra;
int retStatus = ISD200_GOOD;
u16 *id = info->id;
usb_stor_dbg(us, "Entering isd200_get_inquiry_data\n");
info->DeviceHead = ATA_ADDRESS_DEVHEAD_STD;
retStatus = isd200_manual_enum(us);
if (retStatus == ISD200_GOOD) {
int transferStatus;
if (info->DeviceFlags & DF_ATA_DEVICE) {
transferStatus = isd200_action( us, ACTION_IDENTIFY,
id, ATA_ID_WORDS * 2);
if (transferStatus != ISD200_TRANSPORT_GOOD) {
usb_stor_dbg(us, " Error issuing ATA Command Identify\n");
retStatus = ISD200_ERROR;
} else {
int i;
__be16 *src;
__u16 *dest;
isd200_fix_driveid(id);
isd200_dump_driveid(us, id);
memset(&info->InquiryData, 0, sizeof(info->InquiryData));
info->InquiryData.DeviceType = DIRECT_ACCESS_DEVICE;
info->InquiryData.AdditionalLength = 0x1F;
if (id[ATA_ID_COMMAND_SET_1] & COMMANDSET_MEDIA_STATUS) {
info->InquiryData.DeviceTypeModifier = DEVICE_REMOVABLE;
info->DeviceFlags |= DF_REMOVABLE_MEDIA;
}
src = (__be16 *)&id[ATA_ID_PROD];
dest = (__u16*)info->InquiryData.VendorId;
for (i=0;i<4;i++)
dest[i] = be16_to_cpu(src[i]);
src = (__be16 *)&id[ATA_ID_PROD + 8/2];
dest = (__u16*)info->InquiryData.ProductId;
for (i=0;i<8;i++)
dest[i] = be16_to_cpu(src[i]);
src = (__be16 *)&id[ATA_ID_FW_REV];
dest = (__u16*)info->InquiryData.ProductRevisionLevel;
for (i=0;i<2;i++)
dest[i] = be16_to_cpu(src[i]);
if (id[ATA_ID_COMMAND_SET_2] & COMMANDSET_MEDIA_STATUS) {
usb_stor_dbg(us, " Device supports Media Status Notification\n");
info->DeviceFlags |= DF_MEDIA_STATUS_ENABLED;
}
else
info->DeviceFlags &= ~DF_MEDIA_STATUS_ENABLED;
}
} else {
us->protocol_name = "Transparent SCSI";
us->proto_handler = usb_stor_transparent_scsi_command;
usb_stor_dbg(us, "Protocol changed to: %s\n",
us->protocol_name);
us->extra_destructor(info);
kfree(info);
us->extra = NULL;
us->extra_destructor = NULL;
}
}
usb_stor_dbg(us, "Leaving isd200_get_inquiry_data %08X\n", retStatus);
return(retStatus);
}
static int isd200_scsi_to_ata(struct scsi_cmnd *srb, struct us_data *us,
union ata_cdb * ataCdb)
{
struct isd200_info *info = (struct isd200_info *)us->extra;
u16 *id = info->id;
int sendToTransport = 1;
unsigned char sectnum, head;
unsigned short cylinder;
unsigned long lba;
unsigned long blockCount;
unsigned char senseData[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
memset(ataCdb, 0, sizeof(union ata_cdb));
switch (srb->cmnd[0]) {
case INQUIRY:
usb_stor_dbg(us, " ATA OUT - INQUIRY\n");
usb_stor_set_xfer_buf((unsigned char *) &info->InquiryData,
sizeof(info->InquiryData), srb);
srb->result = SAM_STAT_GOOD;
sendToTransport = 0;
break;
case MODE_SENSE:
usb_stor_dbg(us, " ATA OUT - SCSIOP_MODE_SENSE\n");
usb_stor_set_xfer_buf(senseData, sizeof(senseData), srb);
if (info->DeviceFlags & DF_MEDIA_STATUS_ENABLED)
{
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 1;
ataCdb->generic.RegisterSelect = REG_COMMAND;
ataCdb->write.CommandByte = ATA_COMMAND_GET_MEDIA_STATUS;
isd200_srb_set_bufflen(srb, 0);
} else {
usb_stor_dbg(us, " Media Status not supported, just report okay\n");
srb->result = SAM_STAT_GOOD;
sendToTransport = 0;
}
break;
case TEST_UNIT_READY:
usb_stor_dbg(us, " ATA OUT - SCSIOP_TEST_UNIT_READY\n");
if (info->DeviceFlags & DF_MEDIA_STATUS_ENABLED)
{
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 1;
ataCdb->generic.RegisterSelect = REG_COMMAND;
ataCdb->write.CommandByte = ATA_COMMAND_GET_MEDIA_STATUS;
isd200_srb_set_bufflen(srb, 0);
} else {
usb_stor_dbg(us, " Media Status not supported, just report okay\n");
srb->result = SAM_STAT_GOOD;
sendToTransport = 0;
}
break;
case READ_CAPACITY:
{
unsigned long capacity;
struct read_capacity_data readCapacityData;
usb_stor_dbg(us, " ATA OUT - SCSIOP_READ_CAPACITY\n");
if (ata_id_has_lba(id))
capacity = ata_id_u32(id, ATA_ID_LBA_CAPACITY) - 1;
else
capacity = (id[ATA_ID_HEADS] * id[ATA_ID_CYLS] *
id[ATA_ID_SECTORS]) - 1;
readCapacityData.LogicalBlockAddress = cpu_to_be32(capacity);
readCapacityData.BytesPerBlock = cpu_to_be32(0x200);
usb_stor_set_xfer_buf((unsigned char *) &readCapacityData,
sizeof(readCapacityData), srb);
srb->result = SAM_STAT_GOOD;
sendToTransport = 0;
}
break;
case READ_10:
usb_stor_dbg(us, " ATA OUT - SCSIOP_READ\n");
lba = be32_to_cpu(*(__be32 *)&srb->cmnd[2]);
blockCount = (unsigned long)srb->cmnd[7]<<8 | (unsigned long)srb->cmnd[8];
if (ata_id_has_lba(id)) {
sectnum = (unsigned char)(lba);
cylinder = (unsigned short)(lba>>8);
head = ATA_ADDRESS_DEVHEAD_LBA_MODE | (unsigned char)(lba>>24 & 0x0F);
} else {
sectnum = (u8)((lba % id[ATA_ID_SECTORS]) + 1);
cylinder = (u16)(lba / (id[ATA_ID_SECTORS] *
id[ATA_ID_HEADS]));
head = (u8)((lba / id[ATA_ID_SECTORS]) %
id[ATA_ID_HEADS]);
}
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 1;
ataCdb->generic.RegisterSelect =
REG_SECTOR_COUNT | REG_SECTOR_NUMBER |
REG_CYLINDER_LOW | REG_CYLINDER_HIGH |
REG_DEVICE_HEAD | REG_COMMAND;
ataCdb->write.SectorCountByte = (unsigned char)blockCount;
ataCdb->write.SectorNumberByte = sectnum;
ataCdb->write.CylinderHighByte = (unsigned char)(cylinder>>8);
ataCdb->write.CylinderLowByte = (unsigned char)cylinder;
ataCdb->write.DeviceHeadByte = (head | ATA_ADDRESS_DEVHEAD_STD);
ataCdb->write.CommandByte = ATA_CMD_PIO_READ;
break;
case WRITE_10:
usb_stor_dbg(us, " ATA OUT - SCSIOP_WRITE\n");
lba = be32_to_cpu(*(__be32 *)&srb->cmnd[2]);
blockCount = (unsigned long)srb->cmnd[7]<<8 | (unsigned long)srb->cmnd[8];
if (ata_id_has_lba(id)) {
sectnum = (unsigned char)(lba);
cylinder = (unsigned short)(lba>>8);
head = ATA_ADDRESS_DEVHEAD_LBA_MODE | (unsigned char)(lba>>24 & 0x0F);
} else {
sectnum = (u8)((lba % id[ATA_ID_SECTORS]) + 1);
cylinder = (u16)(lba / (id[ATA_ID_SECTORS] *
id[ATA_ID_HEADS]));
head = (u8)((lba / id[ATA_ID_SECTORS]) %
id[ATA_ID_HEADS]);
}
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 1;
ataCdb->generic.RegisterSelect =
REG_SECTOR_COUNT | REG_SECTOR_NUMBER |
REG_CYLINDER_LOW | REG_CYLINDER_HIGH |
REG_DEVICE_HEAD | REG_COMMAND;
ataCdb->write.SectorCountByte = (unsigned char)blockCount;
ataCdb->write.SectorNumberByte = sectnum;
ataCdb->write.CylinderHighByte = (unsigned char)(cylinder>>8);
ataCdb->write.CylinderLowByte = (unsigned char)cylinder;
ataCdb->write.DeviceHeadByte = (head | ATA_ADDRESS_DEVHEAD_STD);
ataCdb->write.CommandByte = ATA_CMD_PIO_WRITE;
break;
case ALLOW_MEDIUM_REMOVAL:
usb_stor_dbg(us, " ATA OUT - SCSIOP_MEDIUM_REMOVAL\n");
if (info->DeviceFlags & DF_REMOVABLE_MEDIA) {
usb_stor_dbg(us, " srb->cmnd[4] = 0x%X\n",
srb->cmnd[4]);
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 1;
ataCdb->generic.RegisterSelect = REG_COMMAND;
ataCdb->write.CommandByte = (srb->cmnd[4] & 0x1) ?
ATA_CMD_MEDIA_LOCK : ATA_CMD_MEDIA_UNLOCK;
isd200_srb_set_bufflen(srb, 0);
} else {
usb_stor_dbg(us, " Not removeable media, just report okay\n");
srb->result = SAM_STAT_GOOD;
sendToTransport = 0;
}
break;
case START_STOP:
usb_stor_dbg(us, " ATA OUT - SCSIOP_START_STOP_UNIT\n");
usb_stor_dbg(us, " srb->cmnd[4] = 0x%X\n", srb->cmnd[4]);
if ((srb->cmnd[4] & 0x3) == 0x2) {
usb_stor_dbg(us, " Media Eject\n");
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 0;
ataCdb->generic.RegisterSelect = REG_COMMAND;
ataCdb->write.CommandByte = ATA_COMMAND_MEDIA_EJECT;
} else if ((srb->cmnd[4] & 0x3) == 0x1) {
usb_stor_dbg(us, " Get Media Status\n");
ataCdb->generic.SignatureByte0 = info->ConfigData.ATAMajorCommand;
ataCdb->generic.SignatureByte1 = info->ConfigData.ATAMinorCommand;
ataCdb->generic.TransferBlockSize = 1;
ataCdb->generic.RegisterSelect = REG_COMMAND;
ataCdb->write.CommandByte = ATA_COMMAND_GET_MEDIA_STATUS;
isd200_srb_set_bufflen(srb, 0);
} else {
usb_stor_dbg(us, " Nothing to do, just report okay\n");
srb->result = SAM_STAT_GOOD;
sendToTransport = 0;
}
break;
default:
usb_stor_dbg(us, "Unsupported SCSI command - 0x%X\n",
srb->cmnd[0]);
srb->result = DID_ERROR << 16;
sendToTransport = 0;
break;
}
return(sendToTransport);
}
static void isd200_free_info_ptrs(void *info_)
{
struct isd200_info *info = (struct isd200_info *) info_;
if (info) {
kfree(info->id);
kfree(info->RegsBuf);
kfree(info->srb.sense_buffer);
}
}
static int isd200_init_info(struct us_data *us)
{
struct isd200_info *info;
info = kzalloc(sizeof(struct isd200_info), GFP_KERNEL);
if (!info)
return ISD200_ERROR;
info->id = kzalloc(ATA_ID_WORDS * 2, GFP_KERNEL);
info->RegsBuf = kmalloc(sizeof(info->ATARegs), GFP_KERNEL);
info->srb.sense_buffer = kmalloc(SCSI_SENSE_BUFFERSIZE, GFP_KERNEL);
if (!info->id || !info->RegsBuf || !info->srb.sense_buffer) {
isd200_free_info_ptrs(info);
kfree(info);
return ISD200_ERROR;
}
us->extra = info;
us->extra_destructor = isd200_free_info_ptrs;
return ISD200_GOOD;
}
static int isd200_Initialization(struct us_data *us)
{
usb_stor_dbg(us, "ISD200 Initialization...\n");
if (isd200_init_info(us) == ISD200_ERROR) {
usb_stor_dbg(us, "ERROR Initializing ISD200 Info struct\n");
} else {
if (isd200_get_inquiry_data(us) != ISD200_GOOD)
usb_stor_dbg(us, "ISD200 Initialization Failure\n");
else
usb_stor_dbg(us, "ISD200 Initialization complete\n");
}
return 0;
}
static void isd200_ata_command(struct scsi_cmnd *srb, struct us_data *us)
{
int sendToTransport = 1, orig_bufflen;
union ata_cdb ataCdb;
if (us->extra == NULL) {
usb_stor_dbg(us, "ERROR Driver not initialized\n");
srb->result = DID_ERROR << 16;
return;
}
scsi_set_resid(srb, 0);
orig_bufflen = scsi_bufflen(srb);
sendToTransport = isd200_scsi_to_ata(srb, us, &ataCdb);
if (sendToTransport)
isd200_invoke_transport(us, srb, &ataCdb);
isd200_srb_set_bufflen(srb, orig_bufflen);
}
static int isd200_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct us_data *us;
int result;
result = usb_stor_probe1(&us, intf, id,
(id - isd200_usb_ids) + isd200_unusual_dev_list,
&isd200_host_template);
if (result)
return result;
us->protocol_name = "ISD200 ATA/ATAPI";
us->proto_handler = isd200_ata_command;
result = usb_stor_probe2(us);
return result;
}
