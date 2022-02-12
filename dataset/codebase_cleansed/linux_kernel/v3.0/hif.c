static struct hif_device *ath6kl_alloc_hifdev(struct sdio_func *func)
{
struct hif_device *hifdevice;
hifdevice = kzalloc(sizeof(struct hif_device), GFP_KERNEL);
#if HIF_USE_DMA_BOUNCE_BUFFER
hifdevice->dma_buffer = kmalloc(HIF_DMA_BUFFER_SIZE, GFP_KERNEL);
#endif
hifdevice->func = func;
hifdevice->powerConfig = HIF_DEVICE_POWER_UP;
sdio_set_drvdata(func, hifdevice);
return hifdevice;
}
static struct hif_device *ath6kl_get_hifdev(struct sdio_func *func)
{
return (struct hif_device *) sdio_get_drvdata(func);
}
static int ath6kl_hifdev_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
int ret;
struct hif_device *device;
int count;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE,
("ath6kl: Function: 0x%X, Vendor ID: 0x%X, "
"Device ID: 0x%X, block size: 0x%X/0x%X\n",
func->num, func->vendor, func->device,
func->max_blksize, func->cur_blksize));
ath6kl_alloc_hifdev(func);
device = ath6kl_get_hifdev(func);
device->id = id;
device->is_disabled = true;
spin_lock_init(&device->lock);
spin_lock_init(&device->asynclock);
DL_LIST_INIT(&device->ScatterReqHead);
if (!nohifscattersupport)
device->scatter_enabled = true;
A_MEMZERO(device->busRequest, sizeof(device->busRequest));
for (count = 0; count < BUS_REQUEST_MAX_NUM; count++) {
sema_init(&device->busRequest[count].sem_req, 0);
hifFreeBusRequest(device, &device->busRequest[count]);
}
sema_init(&device->sem_async, 0);
ret = hifEnableFunc(device, func);
return ret;
}
static void ath6kl_hifdev_remove(struct sdio_func *func)
{
int status = 0;
struct hif_device *device;
device = ath6kl_get_hifdev(func);
if (device->claimedContext != NULL)
status = osdrvCallbacks.
deviceRemovedHandler(device->claimedContext, device);
if (device->is_disabled)
device->is_disabled = false;
else
status = hifDisableFunc(device, func);
CleanupHIFScatterResources(device);
delHifDevice(device);
}
static int ath6kl_hifdev_suspend(struct device *dev)
{
struct sdio_func *func = dev_to_sdio_func(dev);
int status = 0;
struct hif_device *device;
device = ath6kl_get_hifdev(func);
if (device && device->claimedContext &&
osdrvCallbacks.deviceSuspendHandler) {
device->is_suspend = true;
status = osdrvCallbacks.
deviceSuspendHandler(device->claimedContext);
if (status)
device->is_suspend = false;
}
CleanupHIFScatterResources(device);
switch (status) {
case 0:
return 0;
case A_EBUSY:
return -EBUSY;
default:
return -1;
}
}
static int ath6kl_hifdev_resume(struct device *dev)
{
struct sdio_func *func = dev_to_sdio_func(dev);
int status = 0;
struct hif_device *device;
device = ath6kl_get_hifdev(func);
if (device && device->claimedContext &&
osdrvCallbacks.deviceSuspendHandler) {
status = osdrvCallbacks.
deviceResumeHandler(device->claimedContext);
if (status == 0)
device->is_suspend = false;
}
return status;
}
int HIFInit(OSDRV_CALLBACKS *callbacks)
{
int r;
AR_DEBUG_ASSERT(callbacks != NULL);
A_REGISTER_MODULE_DEBUG_INFO(hif);
osdrvCallbacks = *callbacks;
registered = 1;
r = sdio_register_driver(&ath6kl_hifdev_driver);
if (r < 0)
return r;
return 0;
}
static int
__HIFReadWrite(struct hif_device *device,
u32 address,
u8 *buffer,
u32 length,
u32 request,
void *context)
{
u8 opcode;
int status = 0;
int ret;
u8 *tbuffer;
bool bounced = false;
AR_DEBUG_ASSERT(device != NULL);
AR_DEBUG_ASSERT(device->func != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Device: 0x%p, buffer:0x%p (addr:0x%X)\n",
device, buffer, address));
do {
if (request & HIF_EXTENDED_IO) {
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: Invalid command type: 0x%08x\n", request));
status = A_EINVAL;
break;
}
if (request & HIF_BLOCK_BASIS) {
length = (length / HIF_MBOX_BLOCK_SIZE) * HIF_MBOX_BLOCK_SIZE;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE,
("AR6000: Block mode (BlockLen: %d)\n",
length));
} else if (request & HIF_BYTE_BASIS) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE,
("AR6000: Byte mode (BlockLen: %d)\n",
length));
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: Invalid data mode: 0x%08x\n", request));
status = A_EINVAL;
break;
}
#if 0
if (length & 0x3) {
A_PRINTF(KERN_ALERT"AR6000: HIF (%s) is not a multiple of 4 bytes, addr:0x%X, len:%d\n",
request & HIF_WRITE ? "write":"read", address, length);
}
#endif
if (request & HIF_WRITE) {
if ((address >= HIF_MBOX_START_ADDR(0)) &&
(address <= HIF_MBOX_END_ADDR(3)))
{
AR_DEBUG_ASSERT(length <= HIF_MBOX_WIDTH);
address += (HIF_MBOX_WIDTH - length);
}
}
if (request & HIF_FIXED_ADDRESS) {
opcode = CMD53_FIXED_ADDRESS;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Address mode: Fixed 0x%X\n", address));
} else if (request & HIF_INCREMENTAL_ADDRESS) {
opcode = CMD53_INCR_ADDRESS;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Address mode: Incremental 0x%X\n", address));
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: Invalid address mode: 0x%08x\n", request));
status = A_EINVAL;
break;
}
if (request & HIF_WRITE) {
#if HIF_USE_DMA_BOUNCE_BUFFER
if (BUFFER_NEEDS_BOUNCE(buffer)) {
AR_DEBUG_ASSERT(device->dma_buffer != NULL);
tbuffer = device->dma_buffer;
AR_DEBUG_ASSERT(length <= HIF_DMA_BUFFER_SIZE);
memcpy(tbuffer, buffer, length);
bounced = true;
} else {
tbuffer = buffer;
}
#else
tbuffer = buffer;
#endif
if (opcode == CMD53_FIXED_ADDRESS) {
ret = sdio_writesb(device->func, address, tbuffer, length);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: writesb ret=%d address: 0x%X, len: %d, 0x%X\n",
ret, address, length, *(int *)tbuffer));
} else {
ret = sdio_memcpy_toio(device->func, address, tbuffer, length);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: writeio ret=%d address: 0x%X, len: %d, 0x%X\n",
ret, address, length, *(int *)tbuffer));
}
} else if (request & HIF_READ) {
#if HIF_USE_DMA_BOUNCE_BUFFER
if (BUFFER_NEEDS_BOUNCE(buffer)) {
AR_DEBUG_ASSERT(device->dma_buffer != NULL);
AR_DEBUG_ASSERT(length <= HIF_DMA_BUFFER_SIZE);
tbuffer = device->dma_buffer;
bounced = true;
} else {
tbuffer = buffer;
}
#else
tbuffer = buffer;
#endif
if (opcode == CMD53_FIXED_ADDRESS) {
ret = sdio_readsb(device->func, tbuffer, address, length);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: readsb ret=%d address: 0x%X, len: %d, 0x%X\n",
ret, address, length, *(int *)tbuffer));
} else {
ret = sdio_memcpy_fromio(device->func, tbuffer, address, length);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: readio ret=%d address: 0x%X, len: %d, 0x%X\n",
ret, address, length, *(int *)tbuffer));
}
#if HIF_USE_DMA_BOUNCE_BUFFER
if (bounced) {
memcpy(buffer, tbuffer, length);
}
#endif
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: Invalid direction: 0x%08x\n", request));
status = A_EINVAL;
break;
}
if (ret) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: SDIO bus operation failed! MMC stack returned : %d \n", ret));
status = A_ERROR;
}
} while (false);
return status;
}
void AddToAsyncList(struct hif_device *device, BUS_REQUEST *busrequest)
{
unsigned long flags;
BUS_REQUEST *async;
BUS_REQUEST *active;
spin_lock_irqsave(&device->asynclock, flags);
active = device->asyncreq;
if (active == NULL) {
device->asyncreq = busrequest;
device->asyncreq->inusenext = NULL;
} else {
for (async = device->asyncreq;
async != NULL;
async = async->inusenext) {
active = async;
}
active->inusenext = busrequest;
busrequest->inusenext = NULL;
}
spin_unlock_irqrestore(&device->asynclock, flags);
}
int
HIFReadWrite(struct hif_device *device,
u32 address,
u8 *buffer,
u32 length,
u32 request,
void *context)
{
int status = 0;
BUS_REQUEST *busrequest;
AR_DEBUG_ASSERT(device != NULL);
AR_DEBUG_ASSERT(device->func != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Device: %p addr:0x%X\n", device,address));
do {
if ((request & HIF_ASYNCHRONOUS) || (request & HIF_SYNCHRONOUS)){
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Execution mode: %s\n",
(request & HIF_ASYNCHRONOUS)?"Async":"Synch"));
busrequest = hifAllocateBusRequest(device);
if (busrequest == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: no async bus requests available (%s, addr:0x%X, len:%d) \n",
request & HIF_READ ? "READ":"WRITE", address, length));
return A_ERROR;
}
busrequest->address = address;
busrequest->buffer = buffer;
busrequest->length = length;
busrequest->request = request;
busrequest->context = context;
AddToAsyncList(device, busrequest);
if (request & HIF_SYNCHRONOUS) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: queued sync req: 0x%lX\n", (unsigned long)busrequest));
up(&device->sem_async);
if (down_interruptible(&busrequest->sem_req) != 0) {
return A_ERROR;
} else {
int status = busrequest->status;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: sync return freeing 0x%lX: 0x%X\n",
(unsigned long)busrequest, busrequest->status));
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: freeing req: 0x%X\n", (unsigned int)request));
hifFreeBusRequest(device, busrequest);
return status;
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: queued async req: 0x%lX\n", (unsigned long)busrequest));
up(&device->sem_async);
return A_PENDING;
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: Invalid execution mode: 0x%08x\n", (unsigned int)request));
status = A_EINVAL;
break;
}
} while(0);
return status;
}
static int async_task(void *param)
{
struct hif_device *device;
BUS_REQUEST *request;
int status;
unsigned long flags;
device = (struct hif_device *)param;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async task\n"));
set_current_state(TASK_INTERRUPTIBLE);
while(!device->async_shutdown) {
if (down_interruptible(&device->sem_async) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async task interrupted\n"));
break;
}
if (device->async_shutdown) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async task stopping\n"));
break;
}
sdio_claim_host(device->func);
spin_lock_irqsave(&device->asynclock, flags);
while (device->asyncreq != NULL) {
request = device->asyncreq;
if (request->inusenext != NULL) {
device->asyncreq = request->inusenext;
} else {
device->asyncreq = NULL;
}
spin_unlock_irqrestore(&device->asynclock, flags);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async_task processing req: 0x%lX\n", (unsigned long)request));
if (request->pScatterReq != NULL) {
A_ASSERT(device->scatter_enabled);
status = DoHifReadWriteScatter(device,request);
} else {
status = __HIFReadWrite(device, request->address, request->buffer,
request->length, request->request & ~HIF_SYNCHRONOUS, NULL);
if (request->request & HIF_ASYNCHRONOUS) {
void *context = request->context;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async_task freeing req: 0x%lX\n", (unsigned long)request));
hifFreeBusRequest(device, request);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async_task completion routine req: 0x%lX\n", (unsigned long)request));
device->htcCallbacks.rwCompletionHandler(context, status);
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: async_task upping req: 0x%lX\n", (unsigned long)request));
request->status = status;
up(&request->sem_req);
}
}
spin_lock_irqsave(&device->asynclock, flags);
}
spin_unlock_irqrestore(&device->asynclock, flags);
sdio_release_host(device->func);
}
complete_and_exit(&device->async_completion, 0);
return 0;
}
static s32 IssueSDCommand(struct hif_device *device, u32 opcode, u32 arg, u32 flags, u32 *resp)
{
struct mmc_command cmd;
s32 err;
struct mmc_host *host;
struct sdio_func *func;
func = device->func;
host = func->card->host;
memset(&cmd, 0, sizeof(struct mmc_command));
cmd.opcode = opcode;
cmd.arg = arg;
cmd.flags = flags;
err = mmc_wait_for_cmd(host, &cmd, 3);
if ((!err) && (resp)) {
*resp = cmd.resp[0];
}
return err;
}
int ReinitSDIO(struct hif_device *device)
{
s32 err;
struct mmc_host *host;
struct mmc_card *card;
struct sdio_func *func;
u8 cmd52_resp;
u32 clock;
func = device->func;
card = func->card;
host = card->host;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: +ReinitSDIO \n"));
sdio_claim_host(func);
do {
if (!device->is_suspend) {
u32 resp;
u16 rca;
u32 i;
int bit = fls(host->ocr_avail) - 1;
host->ios.vdd = bit;
host->ios.chip_select = MMC_CS_DONTCARE;
host->ios.bus_mode = MMC_BUSMODE_OPENDRAIN;
host->ios.power_mode = MMC_POWER_UP;
host->ios.bus_width = MMC_BUS_WIDTH_1;
host->ios.timing = MMC_TIMING_LEGACY;
host->ops->set_ios(host, &host->ios);
msleep(2);
host->ios.clock = host->f_min;
host->ios.power_mode = MMC_POWER_ON;
host->ops->set_ios(host, &host->ios);
msleep(2);
host->ios.chip_select = MMC_CS_HIGH;
host->ops->set_ios(host, &host->ios);
msleep(1);
err = IssueSDCommand(device, MMC_GO_IDLE_STATE, 0, (MMC_RSP_NONE | MMC_CMD_BC), NULL);
host->ios.chip_select = MMC_CS_DONTCARE;
host->ops->set_ios(host, &host->ios);
msleep(1);
host->use_spi_crc = 0;
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD0 failed : %d \n",err));
break;
}
if (!host->ocr) {
err = IssueSDCommand(device, SD_IO_SEND_OP_COND, 0, (MMC_RSP_R4 | MMC_CMD_BCR), &resp);
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD5 failed : %d \n",err));
break;
}
host->ocr = resp;
}
for (i=0;i<100;i++) {
err = IssueSDCommand(device, SD_IO_SEND_OP_COND, host->ocr, (MMC_RSP_R4 | MMC_CMD_BCR), &resp);
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD5 failed : %d \n",err));
break;
}
if (resp & MMC_CARD_BUSY) {
break;
}
msleep(10);
}
if ((i == 100) || (err)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: card in not ready : %d %d \n",i,err));
break;
}
err = IssueSDCommand(device, SD_SEND_RELATIVE_ADDR, 0, MMC_RSP_R6 | MMC_CMD_BCR, &resp);
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD3 failed : %d \n",err));
break;
}
rca = resp >> 16;
host->ios.bus_mode = MMC_BUSMODE_PUSHPULL;
host->ops->set_ios(host, &host->ios);
err = IssueSDCommand(device, MMC_SELECT_CARD, (rca << 16), MMC_RSP_R1 | MMC_CMD_AC, NULL);
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD7 failed : %d \n",err));
break;
}
}
if (card->host->caps & MMC_CAP_SD_HIGHSPEED) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("ReinitSDIO: Set high speed mode\n"));
err = Func0_CMD52ReadByte(card, SDIO_CCCR_SPEED, &cmd52_resp);
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD52 read to CCCR speed register failed : %d \n",err));
card->state &= ~MMC_STATE_HIGHSPEED;
} else {
err = Func0_CMD52WriteByte(card, SDIO_CCCR_SPEED, (cmd52_resp | SDIO_SPEED_EHS));
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD52 write to CCCR speed register failed : %d \n",err));
break;
}
mmc_card_set_highspeed(card);
host->ios.timing = MMC_TIMING_SD_HS;
host->ops->set_ios(host, &host->ios);
}
}
if (mmc_card_highspeed(card)) {
clock = 50000000;
} else {
clock = card->cis.max_dtr;
}
if (clock > host->f_max) {
clock = host->f_max;
}
host->ios.clock = clock;
host->ops->set_ios(host, &host->ios);
if (card->host->caps & MMC_CAP_4_BIT_DATA) {
err = Func0_CMD52WriteByte(card, SDIO_CCCR_IF, SDIO_BUS_CD_DISABLE | SDIO_BUS_WIDTH_4BIT);
if (err) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("ReinitSDIO: CMD52 to set bus mode failed : %d \n",err));
break;
}
host->ios.bus_width = MMC_BUS_WIDTH_4;
host->ops->set_ios(host, &host->ios);
}
} while (0);
sdio_release_host(func);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: -ReinitSDIO \n"));
return (err) ? A_ERROR : 0;
}
int
PowerStateChangeNotify(struct hif_device *device, HIF_DEVICE_POWER_CHANGE_TYPE config)
{
int status = 0;
#if defined(CONFIG_PM)
struct sdio_func *func = device->func;
int old_reset_val;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: +PowerStateChangeNotify %d\n", config));
switch (config) {
case HIF_DEVICE_POWER_DOWN:
case HIF_DEVICE_POWER_CUT:
old_reset_val = reset_sdio_on_unload;
reset_sdio_on_unload = 1;
status = hifDisableFunc(device, func);
reset_sdio_on_unload = old_reset_val;
if (!device->is_suspend) {
struct mmc_host *host = func->card->host;
host->ios.clock = 0;
host->ios.vdd = 0;
host->ios.bus_mode = MMC_BUSMODE_OPENDRAIN;
host->ios.chip_select = MMC_CS_DONTCARE;
host->ios.power_mode = MMC_POWER_OFF;
host->ios.bus_width = MMC_BUS_WIDTH_1;
host->ios.timing = MMC_TIMING_LEGACY;
host->ops->set_ios(host, &host->ios);
}
break;
case HIF_DEVICE_POWER_UP:
if (device->powerConfig == HIF_DEVICE_POWER_CUT) {
status = ReinitSDIO(device);
}
if (status == 0) {
status = hifEnableFunc(device, func);
}
break;
}
device->powerConfig = config;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: -PowerStateChangeNotify\n"));
#endif
return status;
}
int
HIFConfigureDevice(struct hif_device *device, HIF_DEVICE_CONFIG_OPCODE opcode,
void *config, u32 configLen)
{
u32 count;
int status = 0;
switch(opcode) {
case HIF_DEVICE_GET_MBOX_BLOCK_SIZE:
((u32 *)config)[0] = HIF_MBOX0_BLOCK_SIZE;
((u32 *)config)[1] = HIF_MBOX1_BLOCK_SIZE;
((u32 *)config)[2] = HIF_MBOX2_BLOCK_SIZE;
((u32 *)config)[3] = HIF_MBOX3_BLOCK_SIZE;
break;
case HIF_DEVICE_GET_MBOX_ADDR:
for (count = 0; count < 4; count ++) {
((u32 *)config)[count] = HIF_MBOX_START_ADDR(count);
}
if (configLen >= sizeof(struct hif_device_mbox_info)) {
SetExtendedMboxWindowInfo((u16)device->func->device,
(struct hif_device_mbox_info *)config);
}
break;
case HIF_DEVICE_GET_IRQ_PROC_MODE:
*((HIF_DEVICE_IRQ_PROCESSING_MODE *)config) = HIF_DEVICE_IRQ_SYNC_ONLY;
break;
case HIF_CONFIGURE_QUERY_SCATTER_REQUEST_SUPPORT:
if (!device->scatter_enabled) {
return A_ENOTSUP;
}
status = SetupHIFScatterSupport(device, (struct hif_device_scatter_support_info *)config);
if (status) {
device->scatter_enabled = false;
}
break;
case HIF_DEVICE_GET_OS_DEVICE:
((struct hif_device_os_device_info *)config)->pOSDevice = &device->func->dev;
break;
case HIF_DEVICE_POWER_STATE_CHANGE:
status = PowerStateChangeNotify(device, *(HIF_DEVICE_POWER_CHANGE_TYPE *)config);
break;
default:
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,
("AR6000: Unsupported configuration opcode: %d\n", opcode));
status = A_ERROR;
}
return status;
}
void
HIFShutDownDevice(struct hif_device *device)
{
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: +HIFShutDownDevice\n"));
if (device != NULL) {
AR_DEBUG_ASSERT(device->func != NULL);
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: HIFShutDownDevice, resetting\n"));
ResetAllCards();
if (registered) {
registered = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE,
("AR6000: Unregistering with the bus driver\n"));
sdio_unregister_driver(&ath6kl_hifdev_driver);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE,
("AR6000: Unregistered\n"));
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: -HIFShutDownDevice\n"));
}
static void
hifIRQHandler(struct sdio_func *func)
{
int status;
struct hif_device *device;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: +hifIRQHandler\n"));
device = ath6kl_get_hifdev(func);
atomic_set(&device->irqHandling, 1);
sdio_release_host(device->func);
status = device->htcCallbacks.dsrHandler(device->htcCallbacks.context);
sdio_claim_host(device->func);
atomic_set(&device->irqHandling, 0);
AR_DEBUG_ASSERT(status == 0 || status == A_ECANCELED);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: -hifIRQHandler\n"));
}
static int startup_task(void *param)
{
struct hif_device *device;
device = (struct hif_device *)param;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: call HTC from startup_task\n"));
if ((osdrvCallbacks.deviceInsertedHandler(osdrvCallbacks.context,device)) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Device rejected\n"));
}
return 0;
}
static int enable_task(void *param)
{
struct hif_device *device;
device = (struct hif_device *)param;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: call from resume_task\n"));
if (device &&
device->claimedContext &&
osdrvCallbacks.devicePowerChangeHandler &&
osdrvCallbacks.devicePowerChangeHandler(device->claimedContext, HIF_DEVICE_POWER_UP) != 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: Device rejected\n"));
}
return 0;
}
void
HIFAckInterrupt(struct hif_device *device)
{
AR_DEBUG_ASSERT(device != NULL);
}
void
HIFUnMaskInterrupt(struct hif_device *device)
{
int ret;
AR_DEBUG_ASSERT(device != NULL);
AR_DEBUG_ASSERT(device->func != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: HIFUnMaskInterrupt\n"));
sdio_claim_host(device->func);
ret = sdio_claim_irq(device->func, hifIRQHandler);
sdio_release_host(device->func);
AR_DEBUG_ASSERT(ret == 0);
}
void HIFMaskInterrupt(struct hif_device *device)
{
int ret;
AR_DEBUG_ASSERT(device != NULL);
AR_DEBUG_ASSERT(device->func != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: HIFMaskInterrupt\n"));
sdio_claim_host(device->func);
while (atomic_read(&device->irqHandling)) {
sdio_release_host(device->func);
schedule_timeout(HZ/10);
sdio_claim_host(device->func);
}
ret = sdio_release_irq(device->func);
sdio_release_host(device->func);
AR_DEBUG_ASSERT(ret == 0);
}
BUS_REQUEST *hifAllocateBusRequest(struct hif_device *device)
{
BUS_REQUEST *busrequest;
unsigned long flag;
spin_lock_irqsave(&device->lock, flag);
if((busrequest = device->s_busRequestFreeQueue) != NULL)
{
device->s_busRequestFreeQueue = busrequest->next;
}
spin_unlock_irqrestore(&device->lock, flag);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: hifAllocateBusRequest: 0x%p\n", busrequest));
return busrequest;
}
void
hifFreeBusRequest(struct hif_device *device, BUS_REQUEST *busrequest)
{
unsigned long flag;
AR_DEBUG_ASSERT(busrequest != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: hifFreeBusRequest: 0x%p\n", busrequest));
spin_lock_irqsave(&device->lock, flag);
busrequest->next = device->s_busRequestFreeQueue;
busrequest->inusenext = NULL;
device->s_busRequestFreeQueue = busrequest;
spin_unlock_irqrestore(&device->lock, flag);
}
static int hifDisableFunc(struct hif_device *device, struct sdio_func *func)
{
int ret;
int status = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: +hifDisableFunc\n"));
device = ath6kl_get_hifdev(func);
if (!IS_ERR(device->async_task)) {
init_completion(&device->async_completion);
device->async_shutdown = 1;
up(&device->sem_async);
wait_for_completion(&device->async_completion);
device->async_task = NULL;
}
sdio_claim_host(device->func);
ret = sdio_disable_func(device->func);
if (ret) {
status = A_ERROR;
}
if (reset_sdio_on_unload) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("AR6000: reseting SDIO card back to uninitialized state \n"));
ret = Func0_CMD52WriteByte(device->func->card, SDIO_CCCR_ABORT, (1 << 3));
if (ret) {
status = A_ERROR;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("AR6000: reset failed : %d \n",ret));
}
}
sdio_release_host(device->func);
if (status == 0) {
device->is_disabled = true;
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: -hifDisableFunc\n"));
return status;
}
static int hifEnableFunc(struct hif_device *device, struct sdio_func *func)
{
struct task_struct* pTask;
const char *taskName = NULL;
int (*taskFunc)(void *) = NULL;
int ret = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: +hifEnableFunc\n"));
device = ath6kl_get_hifdev(func);
if (device->is_disabled) {
sdio_claim_host(func);
if ((device->id->device & MANUFACTURER_ID_AR6K_BASE_MASK) >= MANUFACTURER_ID_AR6003_BASE) {
ret = Func0_CMD52WriteByte(func->card, CCCR_SDIO_IRQ_MODE_REG, SDIO_IRQ_MODE_ASYNC_4BIT_IRQ);
if (ret) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("AR6000: failed to enable 4-bit ASYNC IRQ mode %d \n",ret));
sdio_release_host(func);
return ret;
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: 4-bit ASYNC IRQ mode enabled\n"));
}
func->enable_timeout = 100;
ret = sdio_enable_func(func);
if (ret) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("AR6000: %s(), Unable to enable AR6K: 0x%X\n",
__FUNCTION__, ret));
sdio_release_host(func);
return ret;
}
ret = sdio_set_block_size(func, HIF_MBOX_BLOCK_SIZE);
sdio_release_host(func);
if (ret) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("AR6000: %s(), Unable to set block size 0x%x AR6K: 0x%X\n",
__FUNCTION__, HIF_MBOX_BLOCK_SIZE, ret));
return ret;
}
device->is_disabled = false;
if (!device->async_task) {
device->async_shutdown = 0;
device->async_task = kthread_create(async_task,
(void *)device,
"AR6K Async");
if (IS_ERR(device->async_task)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("AR6000: %s(), to create async task\n", __FUNCTION__));
return -ENOMEM;
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: start async task\n"));
wake_up_process(device->async_task );
}
}
if (!device->claimedContext) {
taskFunc = startup_task;
taskName = "AR6K startup";
ret = 0;
#if defined(CONFIG_PM)
} else {
taskFunc = enable_task;
taskName = "AR6K enable";
ret = -ENOMEM;
#endif
}
pTask = kthread_create(taskFunc, (void *)device, taskName);
if (IS_ERR(pTask)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("AR6000: %s(), to create enabel task\n", __FUNCTION__));
return -ENOMEM;
}
wake_up_process(pTask);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: -hifEnableFunc\n"));
return ret;
}
int hifWaitForPendingRecv(struct hif_device *device)
{
s32 cnt = 10;
u8 host_int_status;
int status = 0;
do {
while (atomic_read(&device->irqHandling)) {
schedule_timeout(HZ/10);
}
host_int_status = 0;
status = HIFReadWrite(device, HOST_INT_STATUS_ADDRESS,
(u8 *)&host_int_status, sizeof(host_int_status),
HIF_RD_SYNC_BYTE_INC, NULL);
host_int_status = !status ? (host_int_status & (1 << 0)) : 0;
if (host_int_status) {
schedule();
}
} while (host_int_status && --cnt > 0);
if (host_int_status && cnt == 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("AR6000: %s(), Unable clear up pending IRQ before the system suspended\n", __FUNCTION__));
}
return 0;
}
static void
delHifDevice(struct hif_device * device)
{
AR_DEBUG_ASSERT(device!= NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_TRACE, ("AR6000: delHifDevice; 0x%p\n", device));
kfree(device->dma_buffer);
kfree(device);
}
static void ResetAllCards(void)
{
}
void HIFClaimDevice(struct hif_device *device, void *context)
{
device->claimedContext = context;
}
void HIFReleaseDevice(struct hif_device *device)
{
device->claimedContext = NULL;
}
int HIFAttachHTC(struct hif_device *device, HTC_CALLBACKS *callbacks)
{
if (device->htcCallbacks.context != NULL) {
return A_ERROR;
}
device->htcCallbacks = *callbacks;
return 0;
}
void HIFDetachHTC(struct hif_device *device)
{
A_MEMZERO(&device->htcCallbacks,sizeof(device->htcCallbacks));
}
static int Func0_CMD52WriteByte(struct mmc_card *card, unsigned int address, unsigned char byte)
{
struct mmc_command ioCmd;
unsigned long arg;
memset(&ioCmd,0,sizeof(ioCmd));
SDIO_SET_CMD52_WRITE_ARG(arg,0,address,byte);
ioCmd.opcode = SD_IO_RW_DIRECT;
ioCmd.arg = arg;
ioCmd.flags = MMC_RSP_R5 | MMC_CMD_AC;
return mmc_wait_for_cmd(card->host, &ioCmd, 0);
}
static int Func0_CMD52ReadByte(struct mmc_card *card, unsigned int address, unsigned char *byte)
{
struct mmc_command ioCmd;
unsigned long arg;
s32 err;
memset(&ioCmd,0,sizeof(ioCmd));
SDIO_SET_CMD52_READ_ARG(arg,0,address);
ioCmd.opcode = SD_IO_RW_DIRECT;
ioCmd.arg = arg;
ioCmd.flags = MMC_RSP_R5 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &ioCmd, 0);
if ((!err) && (byte)) {
*byte = ioCmd.resp[0] & 0xFF;
}
return err;
}
