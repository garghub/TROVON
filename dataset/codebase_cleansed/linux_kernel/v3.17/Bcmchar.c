static int bcm_handle_nvm_read_cmd(struct bcm_mini_adapter *Adapter,
PUCHAR pReadData, struct bcm_nvm_readwrite *stNVMReadWrite)
{
INT Status = STATUS_FAILURE;
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) || (Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter,
DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
kfree(pReadData);
return -EACCES;
}
Status = BeceemNVMRead(Adapter, (PUINT)pReadData,
stNVMReadWrite->uiOffset,
stNVMReadWrite->uiNumBytes);
up(&Adapter->NVMRdmWrmLock);
if (Status != STATUS_SUCCESS) {
kfree(pReadData);
return Status;
}
if (copy_to_user(stNVMReadWrite->pBuffer, pReadData,
stNVMReadWrite->uiNumBytes)) {
kfree(pReadData);
return -EFAULT;
}
return STATUS_SUCCESS;
}
static int handle_flash2x_adapter(struct bcm_mini_adapter *Adapter,
PUCHAR pReadData, struct bcm_nvm_readwrite *stNVMReadWrite)
{
INT Status;
ULONG ulDSDMagicNumInUsrBuff = 0;
Status = BcmFlash2xCorruptSig(Adapter, Adapter->eActiveDSD);
if (Status == STATUS_SUCCESS)
return STATUS_SUCCESS;
if (((stNVMReadWrite->uiOffset + stNVMReadWrite->uiNumBytes) !=
Adapter->uiNVMDSDSize) ||
(stNVMReadWrite->uiNumBytes < SIGNATURE_SIZE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"DSD Sig is present neither in Flash nor User provided Input..");
up(&Adapter->NVMRdmWrmLock);
kfree(pReadData);
return Status;
}
ulDSDMagicNumInUsrBuff =
ntohl(*(PUINT)(pReadData + stNVMReadWrite->uiNumBytes -
SIGNATURE_SIZE));
if (ulDSDMagicNumInUsrBuff != DSD_IMAGE_MAGIC_NUMBER) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"DSD Sig is present neither in Flash nor User provided Input..");
up(&Adapter->NVMRdmWrmLock);
kfree(pReadData);
return Status;
}
return STATUS_SUCCESS;
}
static int bcm_char_open(struct inode *inode, struct file *filp)
{
struct bcm_mini_adapter *Adapter = NULL;
struct bcm_tarang_data *pTarang = NULL;
Adapter = GET_BCM_ADAPTER(gblpnetdev);
pTarang = kzalloc(sizeof(struct bcm_tarang_data), GFP_KERNEL);
if (!pTarang)
return -ENOMEM;
pTarang->Adapter = Adapter;
pTarang->RxCntrlMsgBitMask = 0xFFFFFFFF & ~(1 << 0xB);
down(&Adapter->RxAppControlQueuelock);
pTarang->next = Adapter->pTarangs;
Adapter->pTarangs = pTarang;
up(&Adapter->RxAppControlQueuelock);
filp->private_data = pTarang;
atomic_inc(&Adapter->ApplicationRunning);
nonseekable_open(inode, filp);
return 0;
}
static int bcm_char_release(struct inode *inode, struct file *filp)
{
struct bcm_tarang_data *pTarang, *tmp, *ptmp;
struct bcm_mini_adapter *Adapter = NULL;
struct sk_buff *pkt, *npkt;
pTarang = (struct bcm_tarang_data *)filp->private_data;
if (pTarang == NULL)
return 0;
Adapter = pTarang->Adapter;
down(&Adapter->RxAppControlQueuelock);
tmp = Adapter->pTarangs;
for (ptmp = NULL; tmp; ptmp = tmp, tmp = tmp->next) {
if (tmp == pTarang)
break;
}
if (tmp) {
if (!ptmp)
Adapter->pTarangs = tmp->next;
else
ptmp->next = tmp->next;
} else {
up(&Adapter->RxAppControlQueuelock);
return 0;
}
pkt = pTarang->RxAppControlHead;
while (pkt) {
npkt = pkt->next;
kfree_skb(pkt);
pkt = npkt;
}
up(&Adapter->RxAppControlQueuelock);
atomic_dec(&Adapter->ApplicationRunning);
kfree(pTarang);
filp->private_data = NULL;
return 0;
}
static ssize_t bcm_char_read(struct file *filp, char __user *buf, size_t size,
loff_t *f_pos)
{
struct bcm_tarang_data *pTarang = filp->private_data;
struct bcm_mini_adapter *Adapter = pTarang->Adapter;
struct sk_buff *Packet = NULL;
ssize_t PktLen = 0;
int wait_ret_val = 0;
unsigned long ret = 0;
wait_ret_val = wait_event_interruptible(
Adapter->process_read_wait_queue,
(pTarang->RxAppControlHead ||
Adapter->device_removed));
if ((wait_ret_val == -ERESTARTSYS)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Exiting as i've been asked to exit!!!\n");
return wait_ret_val;
}
if (Adapter->device_removed) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device Removed... Killing the Apps...\n");
return -ENODEV;
}
if (false == Adapter->fw_download_done)
return -EACCES;
down(&Adapter->RxAppControlQueuelock);
if (pTarang->RxAppControlHead) {
Packet = pTarang->RxAppControlHead;
DEQUEUEPACKET(pTarang->RxAppControlHead,
pTarang->RxAppControlTail);
pTarang->AppCtrlQueueLen--;
}
up(&Adapter->RxAppControlQueuelock);
if (Packet) {
PktLen = Packet->len;
ret = copy_to_user(buf, Packet->data,
min_t(size_t, PktLen, size));
if (ret) {
dev_kfree_skb(Packet);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Returning from copy to user failure\n");
return -EFAULT;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Read %zd Bytes From Adapter packet = %p by process %d!\n",
PktLen, Packet, current->pid);
dev_kfree_skb(Packet);
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL, "<\n");
return PktLen;
}
static int bcm_char_ioctl_reg_read_private(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_rdm_buffer sRdmBuffer = {0};
struct bcm_ioctl_buffer IoBuffer;
PCHAR temp_buff;
INT Status = STATUS_FAILURE;
UINT Bufflen;
u16 temp_value;
int bytes;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(sRdmBuffer))
return -EINVAL;
if (copy_from_user(&sRdmBuffer, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
if (IoBuffer.OutputLength > USHRT_MAX ||
IoBuffer.OutputLength == 0) {
return -EINVAL;
}
Bufflen = IoBuffer.OutputLength;
temp_value = 4 - (Bufflen % 4);
Bufflen += temp_value % 4;
temp_buff = kmalloc(Bufflen, GFP_KERNEL);
if (!temp_buff)
return -ENOMEM;
bytes = rdmalt(Adapter, (UINT)sRdmBuffer.Register,
(PUINT)temp_buff, Bufflen);
if (bytes > 0) {
Status = STATUS_SUCCESS;
if (copy_to_user(IoBuffer.OutputBuffer, temp_buff, bytes)) {
kfree(temp_buff);
return -EFAULT;
}
} else {
Status = bytes;
}
kfree(temp_buff);
return Status;
}
static int bcm_char_ioctl_reg_write_private(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_wrm_buffer sWrmBuffer = {0};
struct bcm_ioctl_buffer IoBuffer;
UINT uiTempVar = 0;
INT Status;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(sWrmBuffer))
return -EINVAL;
if (copy_from_user(&sWrmBuffer, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
uiTempVar = sWrmBuffer.Register & EEPROM_REJECT_MASK;
if (!((Adapter->pstargetparams->m_u32Customize) & VSG_MODE) &&
((uiTempVar == EEPROM_REJECT_REG_1) ||
(uiTempVar == EEPROM_REJECT_REG_2) ||
(uiTempVar == EEPROM_REJECT_REG_3) ||
(uiTempVar == EEPROM_REJECT_REG_4))) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"EEPROM Access Denied, not in VSG Mode\n");
return -EFAULT;
}
Status = wrmalt(Adapter, (UINT)sWrmBuffer.Register,
(PUINT)sWrmBuffer.Data, sizeof(ULONG));
if (Status == STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, "WRM Done\n");
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, "WRM Failed\n");
Status = -EFAULT;
}
return Status;
}
static int bcm_char_ioctl_eeprom_reg_read(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_rdm_buffer sRdmBuffer = {0};
struct bcm_ioctl_buffer IoBuffer;
PCHAR temp_buff = NULL;
UINT uiTempVar = 0;
INT Status;
int bytes;
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Device in Idle Mode, Blocking Rdms\n");
return -EACCES;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(sRdmBuffer))
return -EINVAL;
if (copy_from_user(&sRdmBuffer, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
if (IoBuffer.OutputLength > USHRT_MAX ||
IoBuffer.OutputLength == 0) {
return -EINVAL;
}
temp_buff = kmalloc(IoBuffer.OutputLength, GFP_KERNEL);
if (!temp_buff)
return STATUS_FAILURE;
if ((((ULONG)sRdmBuffer.Register & 0x0F000000) != 0x0F000000) ||
((ULONG)sRdmBuffer.Register & 0x3)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"RDM Done On invalid Address : %x Access Denied.\n",
(int)sRdmBuffer.Register);
kfree(temp_buff);
return -EINVAL;
}
uiTempVar = sRdmBuffer.Register & EEPROM_REJECT_MASK;
bytes = rdmaltWithLock(Adapter, (UINT)sRdmBuffer.Register,
(PUINT)temp_buff, IoBuffer.OutputLength);
if (bytes > 0) {
Status = STATUS_SUCCESS;
if (copy_to_user(IoBuffer.OutputBuffer, temp_buff, bytes)) {
kfree(temp_buff);
return -EFAULT;
}
} else {
Status = bytes;
}
kfree(temp_buff);
return Status;
}
static int bcm_char_ioctl_eeprom_reg_write(void __user *argp,
struct bcm_mini_adapter *Adapter,
UINT cmd)
{
struct bcm_wrm_buffer sWrmBuffer = {0};
struct bcm_ioctl_buffer IoBuffer;
UINT uiTempVar = 0;
INT Status;
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Device in Idle Mode, Blocking Wrms\n");
return -EACCES;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(sWrmBuffer))
return -EINVAL;
if (copy_from_user(&sWrmBuffer, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
if ((((ULONG)sWrmBuffer.Register & 0x0F000000) != 0x0F000000) ||
((ULONG)sWrmBuffer.Register & 0x3)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"WRM Done On invalid Address : %x Access Denied.\n",
(int)sWrmBuffer.Register);
return -EINVAL;
}
uiTempVar = sWrmBuffer.Register & EEPROM_REJECT_MASK;
if (!((Adapter->pstargetparams->m_u32Customize) & VSG_MODE) &&
((uiTempVar == EEPROM_REJECT_REG_1) ||
(uiTempVar == EEPROM_REJECT_REG_2) ||
(uiTempVar == EEPROM_REJECT_REG_3) ||
(uiTempVar == EEPROM_REJECT_REG_4)) &&
(cmd == IOCTL_BCM_REGISTER_WRITE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"EEPROM Access Denied, not in VSG Mode\n");
return -EFAULT;
}
Status = wrmaltWithLock(Adapter, (UINT)sWrmBuffer.Register,
(PUINT)sWrmBuffer.Data,
sWrmBuffer.Length);
if (Status == STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, OSAL_DBG,
DBG_LVL_ALL, "WRM Done\n");
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, "WRM Failed\n");
Status = -EFAULT;
}
return Status;
}
static int bcm_char_ioctl_gpio_set_request(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_gpio_info gpio_info = {0};
struct bcm_ioctl_buffer IoBuffer;
UCHAR ucResetValue[4];
UINT value = 0;
UINT uiBit = 0;
UINT uiOperation = 0;
INT Status;
int bytes;
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"GPIO Can't be set/clear in Low power Mode");
return -EACCES;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(gpio_info))
return -EINVAL;
if (copy_from_user(&gpio_info, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
uiBit = gpio_info.uiGpioNumber;
uiOperation = gpio_info.uiGpioValue;
value = (1<<uiBit);
if (IsReqGpioIsLedInNVM(Adapter, value) == false) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"Sorry, Requested GPIO<0x%X> is not correspond to LED !!!",
value);
return -EINVAL;
}
if (uiOperation) {
Status = wrmaltWithLock(Adapter,
BCM_GPIO_OUTPUT_SET_REG,
(PUINT)(&value), sizeof(UINT));
if (Status == STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL,
"Set the GPIO bit\n");
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL,
"Failed to set the %dth GPIO\n",
uiBit);
return Status;
}
} else {
Status = wrmaltWithLock(Adapter,
BCM_GPIO_OUTPUT_CLR_REG,
(PUINT)(&value), sizeof(UINT));
if (Status == STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL,
"Set the GPIO bit\n");
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL,
"Failed to clear the %dth GPIO\n",
uiBit);
return Status;
}
}
bytes = rdmaltWithLock(Adapter, (UINT)GPIO_MODE_REGISTER,
(PUINT)ucResetValue, sizeof(UINT));
if (bytes < 0) {
Status = bytes;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"GPIO_MODE_REGISTER read failed");
return Status;
} else {
Status = STATUS_SUCCESS;
}
*(UINT *)ucResetValue |= (1<<uiBit);
Status = wrmaltWithLock(Adapter, GPIO_MODE_REGISTER,
(PUINT)ucResetValue, sizeof(UINT));
if (Status == STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"Set the GPIO to output Mode\n");
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"Failed to put GPIO in Output Mode\n");
}
return Status;
}
static int bcm_char_ioctl_led_thread_state_change_req(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_user_thread_req threadReq = {0};
struct bcm_ioctl_buffer IoBuffer;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"User made LED thread InActive");
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"GPIO Can't be set/clear in Low power Mode");
return -EACCES;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(threadReq))
return -EINVAL;
if (copy_from_user(&threadReq, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
if (Adapter->LEDInfo.led_thread_running) {
if (threadReq.ThreadState == LED_THREAD_ACTIVATION_REQ) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL,
"Activating thread req");
Adapter->DriverState = LED_THREAD_ACTIVE;
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL,
"DeActivating Thread req.....");
Adapter->DriverState = LED_THREAD_INACTIVE;
}
wake_up(&Adapter->LEDInfo.notify_led_event);
}
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_gpio_status_request(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_gpio_info gpio_info = {0};
struct bcm_ioctl_buffer IoBuffer;
ULONG uiBit = 0;
UCHAR ucRead[4];
INT Status;
int bytes;
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE))
return -EACCES;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(gpio_info))
return -EINVAL;
if (copy_from_user(&gpio_info, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
uiBit = gpio_info.uiGpioNumber;
bytes = rdmaltWithLock(Adapter, (UINT)GPIO_PIN_STATE_REGISTER,
(PUINT)ucRead, sizeof(UINT));
if (bytes < 0) {
Status = bytes;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"RDM Failed\n");
return Status;
} else {
Status = STATUS_SUCCESS;
}
return Status;
}
static int bcm_char_ioctl_gpio_multi_request(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_gpio_multi_info gpio_multi_info[MAX_IDX];
struct bcm_gpio_multi_info *pgpio_multi_info =
(struct bcm_gpio_multi_info *)gpio_multi_info;
struct bcm_ioctl_buffer IoBuffer;
UCHAR ucResetValue[4];
INT Status = STATUS_FAILURE;
int bytes;
memset(pgpio_multi_info, 0,
MAX_IDX * sizeof(struct bcm_gpio_multi_info));
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE))
return -EINVAL;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(gpio_multi_info))
return -EINVAL;
if (IoBuffer.OutputLength > sizeof(gpio_multi_info))
IoBuffer.OutputLength = sizeof(gpio_multi_info);
if (copy_from_user(&gpio_multi_info, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
if (IsReqGpioIsLedInNVM(Adapter, pgpio_multi_info[WIMAX_IDX].uiGPIOMask)
== false) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"Sorry, Requested GPIO<0x%X> is not correspond to NVM LED bit map<0x%X>!!!",
pgpio_multi_info[WIMAX_IDX].uiGPIOMask,
Adapter->gpioBitMap);
return -EINVAL;
}
if ((pgpio_multi_info[WIMAX_IDX].uiGPIOMask) &
(pgpio_multi_info[WIMAX_IDX].uiGPIOCommand)) {
*(UINT *)ucResetValue = pgpio_multi_info[WIMAX_IDX].uiGPIOMask &
pgpio_multi_info[WIMAX_IDX].uiGPIOCommand &
pgpio_multi_info[WIMAX_IDX].uiGPIOValue;
if (*(UINT *) ucResetValue)
Status = wrmaltWithLock(Adapter,
BCM_GPIO_OUTPUT_SET_REG,
(PUINT)ucResetValue, sizeof(ULONG));
if (Status != STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"WRM to BCM_GPIO_OUTPUT_SET_REG Failed.");
return Status;
}
*(UINT *)ucResetValue =
(pgpio_multi_info[WIMAX_IDX].uiGPIOMask &
pgpio_multi_info[WIMAX_IDX].uiGPIOCommand &
(~(pgpio_multi_info[WIMAX_IDX].uiGPIOValue)));
if (*(UINT *) ucResetValue)
Status = wrmaltWithLock(Adapter,
BCM_GPIO_OUTPUT_CLR_REG, (PUINT)ucResetValue,
sizeof(ULONG));
if (Status != STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"WRM to BCM_GPIO_OUTPUT_CLR_REG Failed.");
return Status;
}
}
if (pgpio_multi_info[WIMAX_IDX].uiGPIOMask) {
bytes = rdmaltWithLock(Adapter, (UINT)GPIO_PIN_STATE_REGISTER,
(PUINT)ucResetValue, sizeof(UINT));
if (bytes < 0) {
Status = bytes;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"RDM to GPIO_PIN_STATE_REGISTER Failed.");
return Status;
} else {
Status = STATUS_SUCCESS;
}
pgpio_multi_info[WIMAX_IDX].uiGPIOValue =
(*(UINT *)ucResetValue &
pgpio_multi_info[WIMAX_IDX].uiGPIOMask);
}
Status = copy_to_user(IoBuffer.OutputBuffer, &gpio_multi_info,
IoBuffer.OutputLength);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Failed while copying Content to IOBufer for user space err:%d",
Status);
return -EFAULT;
}
return Status;
}
static int bcm_char_ioctl_gpio_mode_request(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_gpio_multi_mode gpio_multi_mode[MAX_IDX];
struct bcm_gpio_multi_mode *pgpio_multi_mode =
(struct bcm_gpio_multi_mode *)gpio_multi_mode;
struct bcm_ioctl_buffer IoBuffer;
UCHAR ucResetValue[4];
INT Status;
int bytes;
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE))
return -EINVAL;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength > sizeof(gpio_multi_mode))
return -EINVAL;
if (IoBuffer.OutputLength > sizeof(gpio_multi_mode))
IoBuffer.OutputLength = sizeof(gpio_multi_mode);
if (copy_from_user(&gpio_multi_mode, IoBuffer.InputBuffer,
IoBuffer.InputLength))
return -EFAULT;
bytes = rdmaltWithLock(Adapter, (UINT)GPIO_MODE_REGISTER,
(PUINT)ucResetValue, sizeof(UINT));
if (bytes < 0) {
Status = bytes;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Read of GPIO_MODE_REGISTER failed");
return Status;
} else {
Status = STATUS_SUCCESS;
}
if (IsReqGpioIsLedInNVM(Adapter, pgpio_multi_mode[WIMAX_IDX].uiGPIOMask)
== false) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Sorry, Requested GPIO<0x%X> is not correspond to NVM LED bit map<0x%X>!!!",
pgpio_multi_mode[WIMAX_IDX].uiGPIOMask,
Adapter->gpioBitMap);
return -EINVAL;
}
if (pgpio_multi_mode[WIMAX_IDX].uiGPIOMask) {
*(UINT *) ucResetValue |=
(pgpio_multi_mode[WIMAX_IDX].uiGPIOMode &
pgpio_multi_mode[WIMAX_IDX].uiGPIOMask);
*(UINT *) ucResetValue &=
~((~pgpio_multi_mode[WIMAX_IDX].uiGPIOMode) &
pgpio_multi_mode[WIMAX_IDX].uiGPIOMask);
pgpio_multi_mode[WIMAX_IDX].uiGPIOMode = *(UINT *)ucResetValue;
Status = wrmaltWithLock(Adapter, GPIO_MODE_REGISTER,
(PUINT)ucResetValue, sizeof(ULONG));
if (Status == STATUS_SUCCESS) {
BCM_DEBUG_PRINT(Adapter,
DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"WRM to GPIO_MODE_REGISTER Done");
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"WRM to GPIO_MODE_REGISTER Failed");
return -EFAULT;
}
} else {
pgpio_multi_mode[WIMAX_IDX].uiGPIOMode = *(UINT *)ucResetValue;
}
Status = copy_to_user(IoBuffer.OutputBuffer, &gpio_multi_mode,
IoBuffer.OutputLength);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Failed while copying Content to IOBufer for user space err:%d",
Status);
return -EFAULT;
}
return Status;
}
static int bcm_char_ioctl_misc_request(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
PVOID pvBuffer = NULL;
INT Status;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength < sizeof(struct bcm_link_request))
return -EINVAL;
if (IoBuffer.InputLength > MAX_CNTL_PKT_SIZE)
return -EINVAL;
pvBuffer = memdup_user(IoBuffer.InputBuffer,
IoBuffer.InputLength);
if (IS_ERR(pvBuffer))
return PTR_ERR(pvBuffer);
down(&Adapter->LowPowerModeSync);
Status = wait_event_interruptible_timeout(
Adapter->lowpower_mode_wait_queue,
!Adapter->bPreparingForLowPowerMode,
(1 * HZ));
if (Status == -ERESTARTSYS)
goto cntrlEnd;
if (Adapter->bPreparingForLowPowerMode) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Preparing Idle Mode is still True - Hence Rejecting control message\n");
Status = STATUS_FAILURE;
goto cntrlEnd;
}
Status = CopyBufferToControlPacket(Adapter, (PVOID)pvBuffer);
cntrlEnd:
up(&Adapter->LowPowerModeSync);
kfree(pvBuffer);
return Status;
}
static int bcm_char_ioctl_buffer_download_start(
struct bcm_mini_adapter *Adapter)
{
INT Status;
if (down_trylock(&Adapter->NVMRdmWrmLock)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_CHIP_RESET not allowed as EEPROM Read/Write is in progress\n");
return -EACCES;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Starting the firmware download PID =0x%x!!!!\n",
current->pid);
if (down_trylock(&Adapter->fw_download_sema))
return -EBUSY;
Adapter->bBinDownloaded = false;
Adapter->fw_download_process_pid = current->pid;
Adapter->bCfgDownloaded = false;
Adapter->fw_download_done = false;
netif_carrier_off(Adapter->dev);
netif_stop_queue(Adapter->dev);
Status = reset_card_proc(Adapter);
if (Status) {
pr_err(PFX "%s: reset_card_proc Failed!\n", Adapter->dev->name);
up(&Adapter->fw_download_sema);
up(&Adapter->NVMRdmWrmLock);
return Status;
}
mdelay(10);
up(&Adapter->NVMRdmWrmLock);
return Status;
}
static int bcm_char_ioctl_buffer_download(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_firmware_info *psFwInfo = NULL;
struct bcm_ioctl_buffer IoBuffer;
INT Status;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Starting the firmware download PID =0x%x!!!!\n", current->pid);
if (!down_trylock(&Adapter->fw_download_sema)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Invalid way to download buffer. Use Start and then call this!!!\n");
up(&Adapter->fw_download_sema);
return -EINVAL;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer))) {
up(&Adapter->fw_download_sema);
return -EFAULT;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Length for FW DLD is : %lx\n", IoBuffer.InputLength);
if (IoBuffer.InputLength > sizeof(struct bcm_firmware_info)) {
up(&Adapter->fw_download_sema);
return -EINVAL;
}
psFwInfo = kmalloc(sizeof(*psFwInfo), GFP_KERNEL);
if (!psFwInfo) {
up(&Adapter->fw_download_sema);
return -ENOMEM;
}
if (copy_from_user(psFwInfo, IoBuffer.InputBuffer,
IoBuffer.InputLength)) {
up(&Adapter->fw_download_sema);
kfree(psFwInfo);
return -EFAULT;
}
if (!psFwInfo->pvMappedFirmwareAddress ||
(psFwInfo->u32FirmwareLength == 0)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Something else is wrong %lu\n",
psFwInfo->u32FirmwareLength);
up(&Adapter->fw_download_sema);
kfree(psFwInfo);
Status = -EINVAL;
return Status;
}
Status = bcm_ioctl_fw_download(Adapter, psFwInfo);
if (Status != STATUS_SUCCESS) {
if (psFwInfo->u32StartingAddress == CONFIG_BEGIN_ADDR)
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"IOCTL: Configuration File Upload Failed\n");
else
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"IOCTL: Firmware File Upload Failed\n");
if (Adapter->LEDInfo.led_thread_running &
BCM_LED_THREAD_RUNNING_ACTIVELY) {
Adapter->DriverState = DRIVER_INIT;
Adapter->LEDInfo.bLedInitDone = false;
wake_up(&Adapter->LEDInfo.notify_led_event);
}
}
if (Status != STATUS_SUCCESS)
up(&Adapter->fw_download_sema);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, OSAL_DBG, DBG_LVL_ALL,
"IOCTL: Firmware File Uploaded\n");
kfree(psFwInfo);
return Status;
}
static int bcm_char_ioctl_buffer_download_stop(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
INT Status;
int timeout = 0;
if (!down_trylock(&Adapter->fw_download_sema)) {
up(&Adapter->fw_download_sema);
return -EINVAL;
}
if (down_trylock(&Adapter->NVMRdmWrmLock)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"FW download blocked as EEPROM Read/Write is in progress\n");
up(&Adapter->fw_download_sema);
return -EACCES;
}
Adapter->bBinDownloaded = TRUE;
Adapter->bCfgDownloaded = TRUE;
atomic_set(&Adapter->CurrNumFreeTxDesc, 0);
Adapter->CurrNumRecvDescs = 0;
Adapter->downloadDDR = 0;
Status = run_card_proc(Adapter);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Firm Download Failed\n");
up(&Adapter->fw_download_sema);
up(&Adapter->NVMRdmWrmLock);
return Status;
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, "Firm Download Over...\n");
}
mdelay(10);
if (StartInterruptUrb((struct bcm_interface_adapter *)Adapter->pvInterfaceAdapter))
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Unable to send interrupt...\n");
timeout = 5*HZ;
Adapter->waiting_to_fw_download_done = false;
wait_event_timeout(Adapter->ioctl_fw_dnld_wait_queue,
Adapter->waiting_to_fw_download_done, timeout);
Adapter->fw_download_process_pid = INVALID_PID;
Adapter->fw_download_done = TRUE;
atomic_set(&Adapter->CurrNumFreeTxDesc, 0);
Adapter->CurrNumRecvDescs = 0;
Adapter->PrevNumRecvDescs = 0;
atomic_set(&Adapter->cntrlpktCnt, 0);
Adapter->LinkUpStatus = 0;
Adapter->LinkStatus = 0;
if (Adapter->LEDInfo.led_thread_running &
BCM_LED_THREAD_RUNNING_ACTIVELY) {
Adapter->DriverState = FW_DOWNLOAD_DONE;
wake_up(&Adapter->LEDInfo.notify_led_event);
}
if (!timeout)
Status = -ENODEV;
up(&Adapter->fw_download_sema);
up(&Adapter->NVMRdmWrmLock);
return Status;
}
static int bcm_char_ioctl_chip_reset(struct bcm_mini_adapter *Adapter)
{
INT Status;
INT NVMAccess;
NVMAccess = down_trylock(&Adapter->NVMRdmWrmLock);
if (NVMAccess) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
" IOCTL_BCM_CHIP_RESET not allowed as EEPROM Read/Write is in progress\n");
return -EACCES;
}
down(&Adapter->RxAppControlQueuelock);
Status = reset_card_proc(Adapter);
flushAllAppQ();
up(&Adapter->RxAppControlQueuelock);
up(&Adapter->NVMRdmWrmLock);
ResetCounters(Adapter);
return Status;
}
static int bcm_char_ioctl_qos_threshold(ULONG arg,
struct bcm_mini_adapter *Adapter)
{
USHORT uiLoopIndex;
for (uiLoopIndex = 0; uiLoopIndex < NO_OF_QUEUES; uiLoopIndex++) {
if (get_user(Adapter->PackInfo[uiLoopIndex].uiThreshold,
(unsigned long __user *)arg)) {
return -EFAULT;
}
}
return 0;
}
static int bcm_char_ioctl_switch_transfer_mode(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
UINT uiData = 0;
if (copy_from_user(&uiData, argp, sizeof(UINT)))
return -EFAULT;
if (uiData) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_SWITCH_TRANSFER_MODE: ETH_PACKET_TUNNELING_MODE\n");
Adapter->TransferMode = ETH_PACKET_TUNNELING_MODE;
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_SWITCH_TRANSFER_MODE: IP_PACKET_ONLY_MODE\n");
Adapter->TransferMode = IP_PACKET_ONLY_MODE;
}
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_get_driver_version(void __user *argp)
{
struct bcm_ioctl_buffer IoBuffer;
ulong len;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
len = min_t(ulong, IoBuffer.OutputLength, strlen(DRV_VERSION) + 1);
if (copy_to_user(IoBuffer.OutputBuffer, DRV_VERSION, len))
return -EFAULT;
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_get_current_status(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_link_state link_state;
struct bcm_ioctl_buffer IoBuffer;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer))) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"copy_from_user failed..\n");
return -EFAULT;
}
if (IoBuffer.OutputLength != sizeof(link_state))
return -EINVAL;
memset(&link_state, 0, sizeof(link_state));
link_state.bIdleMode = Adapter->IdleMode;
link_state.bShutdownMode = Adapter->bShutStatus;
link_state.ucLinkStatus = Adapter->LinkStatus;
if (copy_to_user(IoBuffer.OutputBuffer, &link_state, min_t(size_t,
sizeof(link_state), IoBuffer.OutputLength))) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy_to_user Failed..\n");
return -EFAULT;
}
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_set_mac_tracing(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
UINT tracing_flag;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (copy_from_user(&tracing_flag, IoBuffer.InputBuffer, sizeof(UINT)))
return -EFAULT;
if (tracing_flag)
Adapter->pTarangs->MacTracingEnabled = TRUE;
else
Adapter->pTarangs->MacTracingEnabled = false;
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_get_dsx_indication(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
ULONG ulSFId = 0;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.OutputLength < sizeof(struct bcm_add_indication_alt)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Mismatch req: %lx needed is =0x%zx!!!",
IoBuffer.OutputLength,
sizeof(struct bcm_add_indication_alt));
return -EINVAL;
}
if (copy_from_user(&ulSFId, IoBuffer.InputBuffer, sizeof(ulSFId)))
return -EFAULT;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Get DSX Data SF ID is =%lx\n", ulSFId);
get_dsx_sf_data_to_application(Adapter, ulSFId, IoBuffer.OutputBuffer);
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_get_host_mibs(void __user *argp,
struct bcm_mini_adapter *Adapter, struct bcm_tarang_data *pTarang)
{
struct bcm_ioctl_buffer IoBuffer;
INT Status = STATUS_FAILURE;
PVOID temp_buff;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.OutputLength != sizeof(struct bcm_host_stats_mibs)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Length Check failed %lu %zd\n", IoBuffer.OutputLength,
sizeof(struct bcm_host_stats_mibs));
return -EINVAL;
}
temp_buff = kzalloc(sizeof(struct bcm_host_stats_mibs), GFP_KERNEL);
if (!temp_buff)
return STATUS_FAILURE;
Status = ProcessGetHostMibs(Adapter, temp_buff);
GetDroppedAppCntrlPktMibs(temp_buff, pTarang);
if (Status != STATUS_FAILURE) {
if (copy_to_user(IoBuffer.OutputBuffer, temp_buff,
sizeof(struct bcm_host_stats_mibs))) {
kfree(temp_buff);
return -EFAULT;
}
}
kfree(temp_buff);
return Status;
}
static int bcm_char_ioctl_bulk_wrm(void __user *argp,
struct bcm_mini_adapter *Adapter, UINT cmd)
{
struct bcm_bulk_wrm_buffer *pBulkBuffer;
struct bcm_ioctl_buffer IoBuffer;
UINT uiTempVar = 0;
INT Status = STATUS_FAILURE;
PCHAR pvBuffer = NULL;
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT (Adapter, DBG_TYPE_PRINTK, 0, 0,
"Device in Idle/Shutdown Mode, Blocking Wrms\n");
return -EACCES;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.InputLength < sizeof(ULONG) * 2)
return -EINVAL;
pvBuffer = memdup_user(IoBuffer.InputBuffer,
IoBuffer.InputLength);
if (IS_ERR(pvBuffer))
return PTR_ERR(pvBuffer);
pBulkBuffer = (struct bcm_bulk_wrm_buffer *)pvBuffer;
if (((ULONG)pBulkBuffer->Register & 0x0F000000) != 0x0F000000 ||
((ULONG)pBulkBuffer->Register & 0x3)) {
BCM_DEBUG_PRINT (Adapter, DBG_TYPE_PRINTK, 0, 0,
"WRM Done On invalid Address : %x Access Denied.\n",
(int)pBulkBuffer->Register);
kfree(pvBuffer);
return -EINVAL;
}
uiTempVar = pBulkBuffer->Register & EEPROM_REJECT_MASK;
if (!((Adapter->pstargetparams->m_u32Customize)&VSG_MODE) &&
((uiTempVar == EEPROM_REJECT_REG_1) ||
(uiTempVar == EEPROM_REJECT_REG_2) ||
(uiTempVar == EEPROM_REJECT_REG_3) ||
(uiTempVar == EEPROM_REJECT_REG_4)) &&
(cmd == IOCTL_BCM_REGISTER_WRITE)) {
kfree(pvBuffer);
BCM_DEBUG_PRINT (Adapter, DBG_TYPE_PRINTK, 0, 0,
"EEPROM Access Denied, not in VSG Mode\n");
return -EFAULT;
}
if (pBulkBuffer->SwapEndian == false)
Status = wrmWithLock(Adapter, (UINT)pBulkBuffer->Register,
(PCHAR)pBulkBuffer->Values,
IoBuffer.InputLength - 2*sizeof(ULONG));
else
Status = wrmaltWithLock(Adapter, (UINT)pBulkBuffer->Register,
(PUINT)pBulkBuffer->Values,
IoBuffer.InputLength - 2*sizeof(ULONG));
if (Status != STATUS_SUCCESS)
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0, "WRM Failed\n");
kfree(pvBuffer);
return Status;
}
static int bcm_char_ioctl_get_nvm_size(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (Adapter->eNVMType == NVM_EEPROM || Adapter->eNVMType == NVM_FLASH) {
if (copy_to_user(IoBuffer.OutputBuffer, &Adapter->uiNVMDSDSize,
sizeof(UINT)))
return -EFAULT;
}
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_cal_init(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
UINT uiSectorSize = 0;
INT Status = STATUS_FAILURE;
if (Adapter->eNVMType == NVM_FLASH) {
if (copy_from_user(&IoBuffer, argp,
sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (copy_from_user(&uiSectorSize, IoBuffer.InputBuffer,
sizeof(UINT)))
return -EFAULT;
if ((uiSectorSize < MIN_SECTOR_SIZE) ||
(uiSectorSize > MAX_SECTOR_SIZE)) {
if (copy_to_user(IoBuffer.OutputBuffer,
&Adapter->uiSectorSize, sizeof(UINT)))
return -EFAULT;
} else {
if (IsFlash2x(Adapter)) {
if (copy_to_user(IoBuffer.OutputBuffer,
&Adapter->uiSectorSize, sizeof(UINT)))
return -EFAULT;
} else {
if ((TRUE == Adapter->bShutStatus) ||
(TRUE == Adapter->IdleMode)) {
BCM_DEBUG_PRINT(Adapter,
DBG_TYPE_PRINTK, 0, 0,
"Device is in Idle/Shutdown Mode\n");
return -EACCES;
}
Adapter->uiSectorSize = uiSectorSize;
BcmUpdateSectorSize(Adapter,
Adapter->uiSectorSize);
}
}
Status = STATUS_SUCCESS;
} else {
Status = STATUS_FAILURE;
}
return Status;
}
static int bcm_char_ioctl_set_debug(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
#ifdef DEBUG
struct bcm_ioctl_buffer IoBuffer;
struct bcm_user_debug_state sUserDebugState;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"In SET_DEBUG ioctl\n");
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (copy_from_user(&sUserDebugState, IoBuffer.InputBuffer,
sizeof(struct bcm_user_debug_state)))
return -EFAULT;
BCM_DEBUG_PRINT (Adapter, DBG_TYPE_PRINTK, 0, 0,
"IOCTL_BCM_SET_DEBUG: OnOff=%d Type = 0x%x ",
sUserDebugState.OnOff, sUserDebugState.Type);
sUserDebugState.Subtype = 1 << sUserDebugState.Subtype;
BCM_DEBUG_PRINT (Adapter, DBG_TYPE_PRINTK, 0, 0,
"actual Subtype=0x%x\n", sUserDebugState.Subtype);
Adapter->stDebugState.type |= sUserDebugState.Type;
if (sUserDebugState.OnOff)
Adapter->stDebugState.subtype[sUserDebugState.Type] |=
sUserDebugState.Subtype;
else
Adapter->stDebugState.subtype[sUserDebugState.Type] &=
~sUserDebugState.Subtype;
BCM_SHOW_DEBUG_BITMAP(Adapter);
#endif
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_nvm_rw(void __user *argp,
struct bcm_mini_adapter *Adapter, UINT cmd)
{
struct bcm_nvm_readwrite stNVMReadWrite;
struct timeval tv0, tv1;
struct bcm_ioctl_buffer IoBuffer;
PUCHAR pReadData = NULL;
INT Status = STATUS_FAILURE;
memset(&tv0, 0, sizeof(struct timeval));
memset(&tv1, 0, sizeof(struct timeval));
if ((Adapter->eNVMType == NVM_FLASH) &&
(Adapter->uiFlashLayoutMajorVersion == 0)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"The Flash Control Section is Corrupted. Hence Rejection on NVM Read/Write\n");
return -EFAULT;
}
if (IsFlash2x(Adapter)) {
if ((Adapter->eActiveDSD != DSD0) &&
(Adapter->eActiveDSD != DSD1) &&
(Adapter->eActiveDSD != DSD2)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"No DSD is active..hence NVM Command is blocked");
return STATUS_FAILURE;
}
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (copy_from_user(&stNVMReadWrite,
(IOCTL_BCM_NVM_READ == cmd) ?
IoBuffer.OutputBuffer : IoBuffer.InputBuffer,
sizeof(struct bcm_nvm_readwrite)))
return -EFAULT;
if (stNVMReadWrite.uiNumBytes > Adapter->uiNVMDSDSize)
return STATUS_FAILURE;
if (stNVMReadWrite.uiOffset >
Adapter->uiNVMDSDSize - stNVMReadWrite.uiNumBytes)
return STATUS_FAILURE;
pReadData = memdup_user(stNVMReadWrite.pBuffer,
stNVMReadWrite.uiNumBytes);
if (IS_ERR(pReadData))
return PTR_ERR(pReadData);
do_gettimeofday(&tv0);
if (IOCTL_BCM_NVM_READ == cmd) {
int ret = bcm_handle_nvm_read_cmd(Adapter, pReadData,
&stNVMReadWrite);
if (ret != STATUS_SUCCESS)
return ret;
} else {
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter,
DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
kfree(pReadData);
return -EACCES;
}
Adapter->bHeaderChangeAllowed = TRUE;
if (IsFlash2x(Adapter)) {
int ret = handle_flash2x_adapter(Adapter,
pReadData,
&stNVMReadWrite);
if (ret != STATUS_SUCCESS)
return ret;
}
Status = BeceemNVMWrite(Adapter, (PUINT)pReadData,
stNVMReadWrite.uiOffset, stNVMReadWrite.uiNumBytes,
stNVMReadWrite.bVerify);
if (IsFlash2x(Adapter))
BcmFlash2xWriteSig(Adapter, Adapter->eActiveDSD);
Adapter->bHeaderChangeAllowed = false;
up(&Adapter->NVMRdmWrmLock);
if (Status != STATUS_SUCCESS) {
kfree(pReadData);
return Status;
}
}
do_gettimeofday(&tv1);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
" timetaken by Write/read :%ld msec\n",
(tv1.tv_sec - tv0.tv_sec)*1000 +
(tv1.tv_usec - tv0.tv_usec)/1000);
kfree(pReadData);
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_flash2x_section_read(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_flash2x_readwrite sFlash2xRead = {0};
struct bcm_ioctl_buffer IoBuffer;
PUCHAR pReadBuff = NULL;
UINT NOB = 0;
UINT BuffSize = 0;
UINT ReadBytes = 0;
UINT ReadOffset = 0;
INT Status = STATUS_FAILURE;
void __user *OutPutBuff;
if (IsFlash2x(Adapter) != TRUE) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash Does not have 2.x map");
return -EINVAL;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, "IOCTL_BCM_FLASH2X_SECTION_READ Called");
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (copy_from_user(&sFlash2xRead, IoBuffer.InputBuffer,
sizeof(struct bcm_flash2x_readwrite)))
return -EFAULT;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.Section :%x",
sFlash2xRead.Section);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.offset :%x",
sFlash2xRead.offset);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.numOfBytes :%x",
sFlash2xRead.numOfBytes);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.bVerify :%x\n",
sFlash2xRead.bVerify);
if (validateFlash2xReadWrite(Adapter, &sFlash2xRead) == false)
return STATUS_FAILURE;
NOB = sFlash2xRead.numOfBytes;
if (NOB > Adapter->uiSectorSize)
BuffSize = Adapter->uiSectorSize;
else
BuffSize = NOB;
ReadOffset = sFlash2xRead.offset;
OutPutBuff = IoBuffer.OutputBuffer;
pReadBuff = kzalloc(BuffSize , GFP_KERNEL);
if (pReadBuff == NULL) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Memory allocation failed for Flash 2.x Read Structure");
return -ENOMEM;
}
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
kfree(pReadBuff);
return -EACCES;
}
while (NOB) {
if (NOB > Adapter->uiSectorSize)
ReadBytes = Adapter->uiSectorSize;
else
ReadBytes = NOB;
Status = BcmFlash2xBulkRead(Adapter, (PUINT)pReadBuff,
sFlash2xRead.Section, ReadOffset, ReadBytes);
if (Status) {
BCM_DEBUG_PRINT(Adapter,
DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Flash 2x read err with Status :%d",
Status);
break;
}
BCM_DEBUG_PRINT_BUFFER(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, pReadBuff, ReadBytes);
Status = copy_to_user(OutPutBuff, pReadBuff, ReadBytes);
if (Status) {
BCM_DEBUG_PRINT(Adapter,
DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Copy to use failed with status :%d", Status);
up(&Adapter->NVMRdmWrmLock);
kfree(pReadBuff);
return -EFAULT;
}
NOB = NOB - ReadBytes;
if (NOB) {
ReadOffset = ReadOffset + ReadBytes;
OutPutBuff = OutPutBuff + ReadBytes;
}
}
up(&Adapter->NVMRdmWrmLock);
kfree(pReadBuff);
return Status;
}
static int bcm_char_ioctl_flash2x_section_write(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_flash2x_readwrite sFlash2xWrite = {0};
struct bcm_ioctl_buffer IoBuffer;
PUCHAR pWriteBuff;
void __user *InputAddr;
UINT NOB = 0;
UINT BuffSize = 0;
UINT WriteOffset = 0;
UINT WriteBytes = 0;
INT Status = STATUS_FAILURE;
if (IsFlash2x(Adapter) != TRUE) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash Does not have 2.x map");
return -EINVAL;
}
Adapter->bAllDSDWriteAllow = false;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_FLASH2X_SECTION_WRITE Called");
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (copy_from_user(&sFlash2xWrite, IoBuffer.InputBuffer,
sizeof(struct bcm_flash2x_readwrite)))
return -EFAULT;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.Section :%x", sFlash2xWrite.Section);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.offset :%d", sFlash2xWrite.offset);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.numOfBytes :%x", sFlash2xWrite.numOfBytes);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\nsFlash2xRead.bVerify :%x\n", sFlash2xWrite.bVerify);
if ((sFlash2xWrite.Section != VSA0) && (sFlash2xWrite.Section != VSA1)
&& (sFlash2xWrite.Section != VSA2)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Only VSA write is allowed");
return -EINVAL;
}
if (validateFlash2xReadWrite(Adapter, &sFlash2xWrite) == false)
return STATUS_FAILURE;
InputAddr = sFlash2xWrite.pDataBuff;
WriteOffset = sFlash2xWrite.offset;
NOB = sFlash2xWrite.numOfBytes;
if (NOB > Adapter->uiSectorSize)
BuffSize = Adapter->uiSectorSize;
else
BuffSize = NOB;
pWriteBuff = kmalloc(BuffSize, GFP_KERNEL);
if (pWriteBuff == NULL)
return -ENOMEM;
WriteBytes = Adapter->uiSectorSize;
if (WriteOffset % Adapter->uiSectorSize) {
WriteBytes = Adapter->uiSectorSize -
(WriteOffset % Adapter->uiSectorSize);
}
if (NOB < WriteBytes)
WriteBytes = NOB;
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
kfree(pWriteBuff);
return -EACCES;
}
BcmFlash2xCorruptSig(Adapter, sFlash2xWrite.Section);
do {
Status = copy_from_user(pWriteBuff, InputAddr, WriteBytes);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy to user failed with status :%d", Status);
up(&Adapter->NVMRdmWrmLock);
kfree(pWriteBuff);
return -EFAULT;
}
BCM_DEBUG_PRINT_BUFFER(Adapter, DBG_TYPE_OTHERS,
OSAL_DBG, DBG_LVL_ALL, pWriteBuff, WriteBytes);
Status = BcmFlash2xBulkWrite(Adapter, (PUINT)pWriteBuff,
sFlash2xWrite.Section,
WriteOffset,
WriteBytes,
sFlash2xWrite.bVerify);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash 2x read err with Status :%d", Status);
break;
}
NOB = NOB - WriteBytes;
if (NOB) {
WriteOffset = WriteOffset + WriteBytes;
InputAddr = InputAddr + WriteBytes;
if (NOB > Adapter->uiSectorSize)
WriteBytes = Adapter->uiSectorSize;
else
WriteBytes = NOB;
}
} while (NOB > 0);
BcmFlash2xWriteSig(Adapter, sFlash2xWrite.Section);
up(&Adapter->NVMRdmWrmLock);
kfree(pWriteBuff);
return Status;
}
static int bcm_char_ioctl_flash2x_section_bitmap(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_flash2x_bitmap *psFlash2xBitMap;
struct bcm_ioctl_buffer IoBuffer;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_GET_FLASH2X_SECTION_BITMAP Called");
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.OutputLength != sizeof(struct bcm_flash2x_bitmap))
return -EINVAL;
psFlash2xBitMap = kzalloc(sizeof(struct bcm_flash2x_bitmap),
GFP_KERNEL);
if (psFlash2xBitMap == NULL) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Memory is not available");
return -ENOMEM;
}
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
kfree(psFlash2xBitMap);
return -EACCES;
}
BcmGetFlash2xSectionalBitMap(Adapter, psFlash2xBitMap);
up(&Adapter->NVMRdmWrmLock);
if (copy_to_user(IoBuffer.OutputBuffer, psFlash2xBitMap,
sizeof(struct bcm_flash2x_bitmap))) {
kfree(psFlash2xBitMap);
return -EFAULT;
}
kfree(psFlash2xBitMap);
return STATUS_FAILURE;
}
static int bcm_char_ioctl_set_active_section(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
enum bcm_flash2x_section_val eFlash2xSectionVal = 0;
INT Status = STATUS_FAILURE;
struct bcm_ioctl_buffer IoBuffer;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_SET_ACTIVE_SECTION Called");
if (IsFlash2x(Adapter) != TRUE) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash Does not have 2.x map");
return -EINVAL;
}
Status = copy_from_user(&IoBuffer, argp,
sizeof(struct bcm_ioctl_buffer));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of IOCTL BUFFER failed");
return -EFAULT;
}
Status = copy_from_user(&eFlash2xSectionVal,
IoBuffer.InputBuffer, sizeof(INT));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of flash section val failed");
return -EFAULT;
}
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
return -EACCES;
}
Status = BcmSetActiveSection(Adapter, eFlash2xSectionVal);
if (Status)
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Failed to make it's priority Highest. Status %d",
Status);
up(&Adapter->NVMRdmWrmLock);
return Status;
}
static int bcm_char_ioctl_copy_section(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_flash2x_copy_section sCopySectStrut = {0};
struct bcm_ioctl_buffer IoBuffer;
INT Status = STATUS_SUCCESS;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_COPY_SECTION Called");
Adapter->bAllDSDWriteAllow = false;
if (IsFlash2x(Adapter) != TRUE) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash Does not have 2.x map");
return -EINVAL;
}
Status = copy_from_user(&IoBuffer, argp,
sizeof(struct bcm_ioctl_buffer));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of IOCTL BUFFER failed Status :%d",
Status);
return -EFAULT;
}
Status = copy_from_user(&sCopySectStrut, IoBuffer.InputBuffer,
sizeof(struct bcm_flash2x_copy_section));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of Copy_Section_Struct failed with Status :%d",
Status);
return -EFAULT;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Source SEction :%x", sCopySectStrut.SrcSection);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Destination SEction :%x", sCopySectStrut.DstSection);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"offset :%x", sCopySectStrut.offset);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"NOB :%x", sCopySectStrut.numOfBytes);
if (IsSectionExistInFlash(Adapter, sCopySectStrut.SrcSection) == false) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Source Section<%x> does not exist in Flash ",
sCopySectStrut.SrcSection);
return -EINVAL;
}
if (IsSectionExistInFlash(Adapter, sCopySectStrut.DstSection) == false) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Destinatio Section<%x> does not exist in Flash ",
sCopySectStrut.DstSection);
return -EINVAL;
}
if (sCopySectStrut.SrcSection == sCopySectStrut.DstSection) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Source and Destination section should be different");
return -EINVAL;
}
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
up(&Adapter->NVMRdmWrmLock);
return -EACCES;
}
if (sCopySectStrut.SrcSection == ISO_IMAGE1 ||
sCopySectStrut.SrcSection == ISO_IMAGE2) {
if (IsNonCDLessDevice(Adapter)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Device is Non-CDLess hence won't have ISO !!");
Status = -EINVAL;
} else if (sCopySectStrut.numOfBytes == 0) {
Status = BcmCopyISO(Adapter, sCopySectStrut);
} else {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Partial Copy of ISO section is not Allowed..");
Status = STATUS_FAILURE;
}
up(&Adapter->NVMRdmWrmLock);
return Status;
}
Status = BcmCopySection(Adapter, sCopySectStrut.SrcSection,
sCopySectStrut.DstSection,
sCopySectStrut.offset,
sCopySectStrut.numOfBytes);
up(&Adapter->NVMRdmWrmLock);
return Status;
}
static int bcm_char_ioctl_get_flash_cs_info(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
INT Status = STATUS_SUCCESS;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
" IOCTL_BCM_GET_FLASH_CS_INFO Called");
Status = copy_from_user(&IoBuffer, argp,
sizeof(struct bcm_ioctl_buffer));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of IOCTL BUFFER failed");
return -EFAULT;
}
if (Adapter->eNVMType != NVM_FLASH) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Connected device does not have flash");
return -EINVAL;
}
if (IsFlash2x(Adapter) == TRUE) {
if (IoBuffer.OutputLength < sizeof(struct bcm_flash2x_cs_info))
return -EINVAL;
if (copy_to_user(IoBuffer.OutputBuffer,
Adapter->psFlash2xCSInfo,
sizeof(struct bcm_flash2x_cs_info)))
return -EFAULT;
} else {
if (IoBuffer.OutputLength < sizeof(struct bcm_flash_cs_info))
return -EINVAL;
if (copy_to_user(IoBuffer.OutputBuffer, Adapter->psFlashCSInfo,
sizeof(struct bcm_flash_cs_info)))
return -EFAULT;
}
return Status;
}
static int bcm_char_ioctl_select_dsd(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_ioctl_buffer IoBuffer;
INT Status = STATUS_FAILURE;
UINT SectOfset = 0;
enum bcm_flash2x_section_val eFlash2xSectionVal;
eFlash2xSectionVal = NO_SECTION_VAL;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_SELECT_DSD Called");
if (IsFlash2x(Adapter) != TRUE) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash Does not have 2.x map");
return -EINVAL;
}
Status = copy_from_user(&IoBuffer, argp,
sizeof(struct bcm_ioctl_buffer));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of IOCTL BUFFER failed");
return -EFAULT;
}
Status = copy_from_user(&eFlash2xSectionVal, IoBuffer.InputBuffer,
sizeof(INT));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy of flash section val failed");
return -EFAULT;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Read Section :%d", eFlash2xSectionVal);
if ((eFlash2xSectionVal != DSD0) &&
(eFlash2xSectionVal != DSD1) &&
(eFlash2xSectionVal != DSD2)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Passed section<%x> is not DSD section",
eFlash2xSectionVal);
return STATUS_FAILURE;
}
SectOfset = BcmGetSectionValStartOffset(Adapter, eFlash2xSectionVal);
if (SectOfset == INVALID_OFFSET) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Provided Section val <%d> does not exist in Flash 2.x",
eFlash2xSectionVal);
return -EINVAL;
}
Adapter->bAllDSDWriteAllow = TRUE;
Adapter->ulFlashCalStart = SectOfset;
Adapter->eActiveDSD = eFlash2xSectionVal;
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_nvm_raw_read(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_nvm_readwrite stNVMRead;
struct bcm_ioctl_buffer IoBuffer;
unsigned int NOB;
INT BuffSize;
INT ReadOffset = 0;
UINT ReadBytes = 0;
PUCHAR pReadBuff;
void __user *OutPutBuff;
INT Status = STATUS_FAILURE;
if (Adapter->eNVMType != NVM_FLASH) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"NVM TYPE is not Flash");
return -EINVAL;
}
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer))) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"copy_from_user 1 failed\n");
return -EFAULT;
}
if (copy_from_user(&stNVMRead, IoBuffer.OutputBuffer,
sizeof(struct bcm_nvm_readwrite)))
return -EFAULT;
NOB = stNVMRead.uiNumBytes;
if (NOB > DEFAULT_BUFF_SIZE)
BuffSize = DEFAULT_BUFF_SIZE;
else
BuffSize = NOB;
ReadOffset = stNVMRead.uiOffset;
OutPutBuff = stNVMRead.pBuffer;
pReadBuff = kzalloc(BuffSize , GFP_KERNEL);
if (pReadBuff == NULL) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Memory allocation failed for Flash 2.x Read Structure");
return -ENOMEM;
}
down(&Adapter->NVMRdmWrmLock);
if ((Adapter->IdleMode == TRUE) ||
(Adapter->bShutStatus == TRUE) ||
(Adapter->bPreparingForLowPowerMode == TRUE)) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Device is in Idle/Shutdown Mode\n");
kfree(pReadBuff);
up(&Adapter->NVMRdmWrmLock);
return -EACCES;
}
Adapter->bFlashRawRead = TRUE;
while (NOB) {
if (NOB > DEFAULT_BUFF_SIZE)
ReadBytes = DEFAULT_BUFF_SIZE;
else
ReadBytes = NOB;
Status = BeceemNVMRead(Adapter, (PUINT)pReadBuff,
ReadOffset, ReadBytes);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Flash 2x read err with Status :%d",
Status);
break;
}
BCM_DEBUG_PRINT_BUFFER(Adapter, DBG_TYPE_OTHERS, OSAL_DBG,
DBG_LVL_ALL, pReadBuff, ReadBytes);
Status = copy_to_user(OutPutBuff, pReadBuff, ReadBytes);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_PRINTK, 0, 0,
"Copy to use failed with status :%d",
Status);
up(&Adapter->NVMRdmWrmLock);
kfree(pReadBuff);
return -EFAULT;
}
NOB = NOB - ReadBytes;
if (NOB) {
ReadOffset = ReadOffset + ReadBytes;
OutPutBuff = OutPutBuff + ReadBytes;
}
}
Adapter->bFlashRawRead = false;
up(&Adapter->NVMRdmWrmLock);
kfree(pReadBuff);
return Status;
}
static int bcm_char_ioctl_cntrlmsg_mask(void __user *argp,
struct bcm_mini_adapter *Adapter, struct bcm_tarang_data *pTarang)
{
struct bcm_ioctl_buffer IoBuffer;
INT Status = STATUS_FAILURE;
ULONG RxCntrlMsgBitMask = 0;
Status = copy_from_user(&IoBuffer, argp,
sizeof(struct bcm_ioctl_buffer));
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"copy of Ioctl buffer is failed from user space");
return -EFAULT;
}
if (IoBuffer.InputLength != sizeof(unsigned long))
return -EINVAL;
Status = copy_from_user(&RxCntrlMsgBitMask, IoBuffer.InputBuffer,
IoBuffer.InputLength);
if (Status) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"copy of control bit mask failed from user space");
return -EFAULT;
}
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"\n Got user defined cntrl msg bit mask :%lx",
RxCntrlMsgBitMask);
pTarang->RxCntrlMsgBitMask = RxCntrlMsgBitMask;
return Status;
}
static int bcm_char_ioctl_get_device_driver_info(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_driver_info DevInfo;
struct bcm_ioctl_buffer IoBuffer;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Called IOCTL_BCM_GET_DEVICE_DRIVER_INFO\n");
memset(&DevInfo, 0, sizeof(DevInfo));
DevInfo.MaxRDMBufferSize = BUFFER_4K;
DevInfo.u32DSDStartOffset = EEPROM_CALPARAM_START;
DevInfo.u32RxAlignmentCorrection = 0;
DevInfo.u32NVMType = Adapter->eNVMType;
DevInfo.u32InterfaceType = BCM_USB;
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.OutputLength < sizeof(DevInfo))
return -EINVAL;
if (copy_to_user(IoBuffer.OutputBuffer, &DevInfo, sizeof(DevInfo)))
return -EFAULT;
return STATUS_SUCCESS;
}
static int bcm_char_ioctl_time_since_net_entry(void __user *argp,
struct bcm_mini_adapter *Adapter)
{
struct bcm_time_elapsed stTimeElapsedSinceNetEntry = {0};
struct bcm_ioctl_buffer IoBuffer;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_TIME_SINCE_NET_ENTRY called");
if (copy_from_user(&IoBuffer, argp, sizeof(struct bcm_ioctl_buffer)))
return -EFAULT;
if (IoBuffer.OutputLength < sizeof(struct bcm_time_elapsed))
return -EINVAL;
stTimeElapsedSinceNetEntry.ul64TimeElapsedSinceNetEntry =
get_seconds() - Adapter->liTimeSinceLastNetEntry;
if (copy_to_user(IoBuffer.OutputBuffer, &stTimeElapsedSinceNetEntry,
sizeof(struct bcm_time_elapsed)))
return -EFAULT;
return STATUS_SUCCESS;
}
static long bcm_char_ioctl(struct file *filp, UINT cmd, ULONG arg)
{
struct bcm_tarang_data *pTarang = filp->private_data;
void __user *argp = (void __user *)arg;
struct bcm_mini_adapter *Adapter = pTarang->Adapter;
INT Status = STATUS_FAILURE;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"Parameters Passed to control IOCTL cmd=0x%X arg=0x%lX",
cmd, arg);
if (_IOC_TYPE(cmd) != BCM_IOCTL)
return -EFAULT;
if (_IOC_DIR(cmd) & _IOC_READ)
Status = !access_ok(VERIFY_WRITE, argp, _IOC_SIZE(cmd));
else if (_IOC_DIR(cmd) & _IOC_WRITE)
Status = !access_ok(VERIFY_READ, argp, _IOC_SIZE(cmd));
else if (_IOC_NONE == (_IOC_DIR(cmd) & _IOC_NONE))
Status = STATUS_SUCCESS;
if (Status)
return -EFAULT;
if (Adapter->device_removed)
return -EFAULT;
if (false == Adapter->fw_download_done) {
switch (cmd) {
case IOCTL_MAC_ADDR_REQ:
case IOCTL_LINK_REQ:
case IOCTL_CM_REQUEST:
case IOCTL_SS_INFO_REQ:
case IOCTL_SEND_CONTROL_MESSAGE:
case IOCTL_IDLE_REQ:
case IOCTL_BCM_GPIO_SET_REQUEST:
case IOCTL_BCM_GPIO_STATUS_REQUEST:
return -EACCES;
default:
break;
}
}
Status = vendorextnIoctl(Adapter, cmd, arg);
if (Status != CONTINUE_COMMON_PATH)
return Status;
switch (cmd) {
case IOCTL_BCM_REGISTER_READ_PRIVATE:
Status = bcm_char_ioctl_reg_read_private(argp, Adapter);
return Status;
case IOCTL_BCM_REGISTER_WRITE_PRIVATE:
Status = bcm_char_ioctl_reg_write_private(argp, Adapter);
return Status;
case IOCTL_BCM_REGISTER_READ:
case IOCTL_BCM_EEPROM_REGISTER_READ:
Status = bcm_char_ioctl_eeprom_reg_read(argp, Adapter);
return Status;
case IOCTL_BCM_REGISTER_WRITE:
case IOCTL_BCM_EEPROM_REGISTER_WRITE:
Status = bcm_char_ioctl_eeprom_reg_write(argp, Adapter, cmd);
return Status;
case IOCTL_BCM_GPIO_SET_REQUEST:
Status = bcm_char_ioctl_gpio_set_request(argp, Adapter);
return Status;
case BCM_LED_THREAD_STATE_CHANGE_REQ:
Status = bcm_char_ioctl_led_thread_state_change_req(argp,
Adapter);
return Status;
case IOCTL_BCM_GPIO_STATUS_REQUEST:
Status = bcm_char_ioctl_gpio_status_request(argp, Adapter);
return Status;
case IOCTL_BCM_GPIO_MULTI_REQUEST:
Status = bcm_char_ioctl_gpio_multi_request(argp, Adapter);
return Status;
case IOCTL_BCM_GPIO_MODE_REQUEST:
Status = bcm_char_ioctl_gpio_mode_request(argp, Adapter);
return Status;
case IOCTL_MAC_ADDR_REQ:
case IOCTL_LINK_REQ:
case IOCTL_CM_REQUEST:
case IOCTL_SS_INFO_REQ:
case IOCTL_SEND_CONTROL_MESSAGE:
case IOCTL_IDLE_REQ:
Status = bcm_char_ioctl_misc_request(argp, Adapter);
return Status;
case IOCTL_BCM_BUFFER_DOWNLOAD_START:
Status = bcm_char_ioctl_buffer_download_start(Adapter);
return Status;
case IOCTL_BCM_BUFFER_DOWNLOAD:
Status = bcm_char_ioctl_buffer_download(argp, Adapter);
return Status;
case IOCTL_BCM_BUFFER_DOWNLOAD_STOP:
Status = bcm_char_ioctl_buffer_download_stop(argp, Adapter);
return Status;
case IOCTL_BE_BUCKET_SIZE:
Status = 0;
if (get_user(Adapter->BEBucketSize,
(unsigned long __user *)arg))
Status = -EFAULT;
break;
case IOCTL_RTPS_BUCKET_SIZE:
Status = 0;
if (get_user(Adapter->rtPSBucketSize,
(unsigned long __user *)arg))
Status = -EFAULT;
break;
case IOCTL_CHIP_RESET:
Status = bcm_char_ioctl_chip_reset(Adapter);
return Status;
case IOCTL_QOS_THRESHOLD:
Status = bcm_char_ioctl_qos_threshold(arg, Adapter);
return Status;
case IOCTL_DUMP_PACKET_INFO:
DumpPackInfo(Adapter);
DumpPhsRules(&Adapter->stBCMPhsContext);
Status = STATUS_SUCCESS;
break;
case IOCTL_GET_PACK_INFO:
if (copy_to_user(argp, &Adapter->PackInfo,
sizeof(struct bcm_packet_info)*NO_OF_QUEUES))
return -EFAULT;
Status = STATUS_SUCCESS;
break;
case IOCTL_BCM_SWITCH_TRANSFER_MODE:
Status = bcm_char_ioctl_switch_transfer_mode(argp, Adapter);
return Status;
case IOCTL_BCM_GET_DRIVER_VERSION:
Status = bcm_char_ioctl_get_driver_version(argp);
return Status;
case IOCTL_BCM_GET_CURRENT_STATUS:
Status = bcm_char_ioctl_get_current_status(argp, Adapter);
return Status;
case IOCTL_BCM_SET_MAC_TRACING:
Status = bcm_char_ioctl_set_mac_tracing(argp, Adapter);
return Status;
case IOCTL_BCM_GET_DSX_INDICATION:
Status = bcm_char_ioctl_get_dsx_indication(argp, Adapter);
return Status;
case IOCTL_BCM_GET_HOST_MIBS:
Status = bcm_char_ioctl_get_host_mibs(argp, Adapter, pTarang);
return Status;
case IOCTL_BCM_WAKE_UP_DEVICE_FROM_IDLE:
if ((false == Adapter->bTriedToWakeUpFromlowPowerMode) &&
(TRUE == Adapter->IdleMode)) {
Adapter->usIdleModePattern = ABORT_IDLE_MODE;
Adapter->bWakeUpDevice = TRUE;
wake_up(&Adapter->process_rx_cntrlpkt);
}
Status = STATUS_SUCCESS;
break;
case IOCTL_BCM_BULK_WRM:
Status = bcm_char_ioctl_bulk_wrm(argp, Adapter, cmd);
return Status;
case IOCTL_BCM_GET_NVM_SIZE:
Status = bcm_char_ioctl_get_nvm_size(argp, Adapter);
return Status;
case IOCTL_BCM_CAL_INIT:
Status = bcm_char_ioctl_cal_init(argp, Adapter);
return Status;
case IOCTL_BCM_SET_DEBUG:
Status = bcm_char_ioctl_set_debug(argp, Adapter);
return Status;
case IOCTL_BCM_NVM_READ:
case IOCTL_BCM_NVM_WRITE:
Status = bcm_char_ioctl_nvm_rw(argp, Adapter, cmd);
return Status;
case IOCTL_BCM_FLASH2X_SECTION_READ:
Status = bcm_char_ioctl_flash2x_section_read(argp, Adapter);
return Status;
case IOCTL_BCM_FLASH2X_SECTION_WRITE:
Status = bcm_char_ioctl_flash2x_section_write(argp, Adapter);
return Status;
case IOCTL_BCM_GET_FLASH2X_SECTION_BITMAP:
Status = bcm_char_ioctl_flash2x_section_bitmap(argp, Adapter);
return Status;
case IOCTL_BCM_SET_ACTIVE_SECTION:
Status = bcm_char_ioctl_set_active_section(argp, Adapter);
return Status;
case IOCTL_BCM_IDENTIFY_ACTIVE_SECTION:
Adapter->bAllDSDWriteAllow = false;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_BCM_IDENTIFY_ACTIVE_SECTION called");
Status = STATUS_SUCCESS;
break;
case IOCTL_BCM_COPY_SECTION:
Status = bcm_char_ioctl_copy_section(argp, Adapter);
return Status;
case IOCTL_BCM_GET_FLASH_CS_INFO:
Status = bcm_char_ioctl_get_flash_cs_info(argp, Adapter);
return Status;
case IOCTL_BCM_SELECT_DSD:
Status = bcm_char_ioctl_select_dsd(argp, Adapter);
return Status;
case IOCTL_BCM_NVM_RAW_READ:
Status = bcm_char_ioctl_nvm_raw_read(argp, Adapter);
return Status;
case IOCTL_BCM_CNTRLMSG_MASK:
Status = bcm_char_ioctl_cntrlmsg_mask(argp, Adapter, pTarang);
return Status;
case IOCTL_BCM_GET_DEVICE_DRIVER_INFO:
Status = bcm_char_ioctl_get_device_driver_info(argp, Adapter);
return Status;
case IOCTL_BCM_TIME_SINCE_NET_ENTRY:
Status = bcm_char_ioctl_time_since_net_entry(argp, Adapter);
return Status;
case IOCTL_CLOSE_NOTIFICATION:
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, OSAL_DBG, DBG_LVL_ALL,
"IOCTL_CLOSE_NOTIFICATION");
break;
default:
pr_info(DRV_NAME ": unknown ioctl cmd=%#x\n", cmd);
Status = STATUS_FAILURE;
break;
}
return Status;
}
int register_control_device_interface(struct bcm_mini_adapter *Adapter)
{
if (Adapter->major > 0)
return Adapter->major;
Adapter->major = register_chrdev(0, DEV_NAME, &bcm_fops);
if (Adapter->major < 0) {
pr_err(DRV_NAME ": could not created character device\n");
return Adapter->major;
}
Adapter->pstCreatedClassDevice = device_create(bcm_class, NULL,
MKDEV(Adapter->major, 0),
Adapter, DEV_NAME);
if (IS_ERR(Adapter->pstCreatedClassDevice)) {
pr_err(DRV_NAME ": class device create failed\n");
unregister_chrdev(Adapter->major, DEV_NAME);
return PTR_ERR(Adapter->pstCreatedClassDevice);
}
return 0;
}
void unregister_control_device_interface(struct bcm_mini_adapter *Adapter)
{
if (Adapter->major > 0) {
device_destroy(bcm_class, MKDEV(Adapter->major, 0));
unregister_chrdev(Adapter->major, DEV_NAME);
}
}
