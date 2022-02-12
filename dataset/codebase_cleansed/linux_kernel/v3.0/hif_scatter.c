static void FreeScatterReq(struct hif_device *device, struct hif_scatter_req *pReq)
{
unsigned long flag;
spin_lock_irqsave(&device->lock, flag);
DL_ListInsertTail(&device->ScatterReqHead, &pReq->ListLink);
spin_unlock_irqrestore(&device->lock, flag);
}
static struct hif_scatter_req *AllocScatterReq(struct hif_device *device)
{
struct dl_list *pItem;
unsigned long flag;
spin_lock_irqsave(&device->lock, flag);
pItem = DL_ListRemoveItemFromHead(&device->ScatterReqHead);
spin_unlock_irqrestore(&device->lock, flag);
if (pItem != NULL) {
return A_CONTAINING_STRUCT(pItem, struct hif_scatter_req, ListLink);
}
return NULL;
}
int DoHifReadWriteScatter(struct hif_device *device, BUS_REQUEST *busrequest)
{
int i;
u8 rw;
u8 opcode;
struct mmc_request mmcreq;
struct mmc_command cmd;
struct mmc_data data;
struct hif_scatter_req_priv *pReqPriv;
struct hif_scatter_req *pReq;
int status = 0;
struct scatterlist *pSg;
pReqPriv = busrequest->pScatterReq;
A_ASSERT(pReqPriv != NULL);
pReq = pReqPriv->pHifScatterReq;
memset(&mmcreq, 0, sizeof(struct mmc_request));
memset(&cmd, 0, sizeof(struct mmc_command));
memset(&data, 0, sizeof(struct mmc_data));
data.blksz = HIF_MBOX_BLOCK_SIZE;
data.blocks = pReq->TotalLength / HIF_MBOX_BLOCK_SIZE;
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, ("HIF-SCATTER: (%s) Address: 0x%X, (BlockLen: %d, BlockCount: %d) , (tot:%d,sg:%d)\n",
(pReq->Request & HIF_WRITE) ? "WRITE":"READ", pReq->Address, data.blksz, data.blocks,
pReq->TotalLength,pReq->ValidScatterEntries));
if (pReq->Request & HIF_WRITE) {
rw = _CMD53_ARG_WRITE;
data.flags = MMC_DATA_WRITE;
} else {
rw = _CMD53_ARG_READ;
data.flags = MMC_DATA_READ;
}
if (pReq->Request & HIF_FIXED_ADDRESS) {
opcode = _CMD53_ARG_FIXED_ADDRESS;
} else {
opcode = _CMD53_ARG_INCR_ADDRESS;
}
pSg = pReqPriv->sgentries;
sg_init_table(pSg, pReq->ValidScatterEntries);
for (i = 0 ; i < pReq->ValidScatterEntries ; i++, pSg++) {
if ((unsigned long)pReq->ScatterList[i].pBuffer & 0x3) {
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER,
("HIF: (%s) Scatter Buffer is unaligned 0x%lx\n",
pReq->Request & HIF_WRITE ? "WRITE":"READ",
(unsigned long)pReq->ScatterList[i].pBuffer));
}
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, (" %d: Addr:0x%lX, Len:%d \n",
i,(unsigned long)pReq->ScatterList[i].pBuffer,pReq->ScatterList[i].Length));
sg_set_buf(pSg, pReq->ScatterList[i].pBuffer, pReq->ScatterList[i].Length);
}
data.sg = pReqPriv->sgentries;
data.sg_len = pReq->ValidScatterEntries;
SDIO_SET_CMD53_ARG(cmd.arg,
rw,
device->func->num,
_CMD53_ARG_BLOCK_BASIS,
opcode,
pReq->Address,
data.blocks);
cmd.opcode = SD_IO_RW_EXTENDED;
cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_ADTC;
mmcreq.cmd = &cmd;
mmcreq.data = &data;
mmc_set_data_timeout(&data, device->func->card);
mmc_wait_for_req(device->func->card->host, &mmcreq);
if (cmd.error) {
status = A_ERROR;
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("HIF-SCATTER: cmd error: %d \n",cmd.error));
}
if (data.error) {
status = A_ERROR;
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("HIF-SCATTER: data error: %d \n",data.error));
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR, ("HIF-SCATTER: FAILED!!! (%s) Address: 0x%X, Block mode (BlockLen: %d, BlockCount: %d)\n",
(pReq->Request & HIF_WRITE) ? "WRITE":"READ",pReq->Address, data.blksz, data.blocks));
}
pReq->CompletionStatus = status;
if (pReq->Request & HIF_ASYNCHRONOUS) {
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, ("HIF-SCATTER: async_task completion routine req: 0x%lX (%d)\n",(unsigned long)busrequest, status));
A_ASSERT(pReq->CompletionRoutine != NULL);
pReq->CompletionRoutine(pReq);
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, ("HIF-SCATTER async_task upping busrequest : 0x%lX (%d)\n", (unsigned long)busrequest,status));
up(&busrequest->sem_req);
}
return status;
}
static int HifReadWriteScatter(struct hif_device *device, struct hif_scatter_req *pReq)
{
int status = A_EINVAL;
u32 request = pReq->Request;
struct hif_scatter_req_priv *pReqPriv = (struct hif_scatter_req_priv *)pReq->HIFPrivate[0];
do {
A_ASSERT(pReqPriv != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, ("HIF-SCATTER: total len: %d Scatter Entries: %d\n",
pReq->TotalLength, pReq->ValidScatterEntries));
if (!(request & HIF_EXTENDED_IO)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("HIF-SCATTER: Invalid command type: 0x%08x\n", request));
break;
}
if (!(request & (HIF_SYNCHRONOUS | HIF_ASYNCHRONOUS))) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("HIF-SCATTER: Invalid execution mode: 0x%08x\n", request));
break;
}
if (!(request & HIF_BLOCK_BASIS)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("HIF-SCATTER: Invalid data mode: 0x%08x\n", request));
break;
}
if (pReq->TotalLength > MAX_SCATTER_REQ_TRANSFER_SIZE) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,
("HIF-SCATTER: Invalid length: %d \n", pReq->TotalLength));
break;
}
if (pReq->TotalLength == 0) {
A_ASSERT(false);
break;
}
AddToAsyncList(device, pReqPriv->busrequest);
if (request & HIF_SYNCHRONOUS) {
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, ("HIF-SCATTER: queued sync req: 0x%lX\n", (unsigned long)pReqPriv->busrequest));
up(&device->sem_async);
if (down_interruptible(&pReqPriv->busrequest->sem_req) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERROR,("HIF-SCATTER: interrupted! \n"));
status = A_ERROR;
break;
} else {
status = pReq->CompletionStatus;
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_SCATTER, ("HIF-SCATTER: queued async req: 0x%lX\n", (unsigned long)pReqPriv->busrequest));
up(&device->sem_async);
status = 0;
}
} while (false);
if (status && (request & HIF_ASYNCHRONOUS)) {
pReq->CompletionStatus = status;
pReq->CompletionRoutine(pReq);
status = 0;
}
return status;
}
int SetupHIFScatterSupport(struct hif_device *device, struct hif_device_scatter_support_info *pInfo)
{
int status = A_ERROR;
int i;
struct hif_scatter_req_priv *pReqPriv;
BUS_REQUEST *busrequest;
do {
if (device->func->card->host->max_segs < MAX_SCATTER_ENTRIES_PER_REQ) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("HIF-SCATTER : host only supports scatter of : %d entries, need: %d \n",
device->func->card->host->max_segs, MAX_SCATTER_ENTRIES_PER_REQ));
status = A_ENOTSUP;
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,("HIF-SCATTER Enabled: max scatter req : %d entries: %d \n",
MAX_SCATTER_REQUESTS, MAX_SCATTER_ENTRIES_PER_REQ));
for (i = 0; i < MAX_SCATTER_REQUESTS; i++) {
pReqPriv = (struct hif_scatter_req_priv *)A_MALLOC(sizeof(struct hif_scatter_req_priv));
if (NULL == pReqPriv) {
break;
}
A_MEMZERO(pReqPriv, sizeof(struct hif_scatter_req_priv));
pReqPriv->device = device;
pReqPriv->pHifScatterReq = (struct hif_scatter_req *)A_MALLOC(sizeof(struct hif_scatter_req) +
(MAX_SCATTER_ENTRIES_PER_REQ - 1) * (sizeof(struct hif_scatter_item)));
if (NULL == pReqPriv->pHifScatterReq) {
kfree(pReqPriv);
break;
}
A_MEMZERO(pReqPriv->pHifScatterReq, sizeof(struct hif_scatter_req));
pReqPriv->pHifScatterReq->HIFPrivate[0] = pReqPriv;
busrequest = hifAllocateBusRequest(device);
if (NULL == busrequest) {
kfree(pReqPriv->pHifScatterReq);
kfree(pReqPriv);
break;
}
busrequest->pScatterReq = pReqPriv;
pReqPriv->busrequest = busrequest;
FreeScatterReq(device,pReqPriv->pHifScatterReq);
}
if (i != MAX_SCATTER_REQUESTS) {
status = A_NO_MEMORY;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("HIF-SCATTER : failed to alloc scatter resources !\n"));
break;
}
pInfo->pAllocateReqFunc = AllocScatterReq;
pInfo->pFreeReqFunc = FreeScatterReq;
pInfo->pReadWriteScatterFunc = HifReadWriteScatter;
pInfo->MaxScatterEntries = MAX_SCATTER_ENTRIES_PER_REQ;
pInfo->MaxTransferSizePerScatterReq = MAX_SCATTER_REQ_TRANSFER_SIZE;
status = 0;
} while (false);
if (status) {
CleanupHIFScatterResources(device);
}
return status;
}
void CleanupHIFScatterResources(struct hif_device *device)
{
struct hif_scatter_req_priv *pReqPriv;
struct hif_scatter_req *pReq;
while (1) {
pReq = AllocScatterReq(device);
if (NULL == pReq) {
break;
}
pReqPriv = (struct hif_scatter_req_priv *)pReq->HIFPrivate[0];
A_ASSERT(pReqPriv != NULL);
if (pReqPriv->busrequest != NULL) {
pReqPriv->busrequest->pScatterReq = NULL;
hifFreeBusRequest(device, pReqPriv->busrequest);
pReqPriv->busrequest = NULL;
}
if (pReqPriv->pHifScatterReq != NULL) {
kfree(pReqPriv->pHifScatterReq);
pReqPriv->pHifScatterReq = NULL;
}
kfree(pReqPriv);
}
}
