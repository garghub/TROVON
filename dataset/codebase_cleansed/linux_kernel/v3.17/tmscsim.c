static void inline dc390_start_segment(struct dc390_srb* pSRB)
{
struct scatterlist *psgl = pSRB->pSegmentList;
pSRB->SGBusAddr = sg_dma_address(psgl);
pSRB->SGToBeXferLen = sg_dma_len(psgl);
}
static unsigned long inline dc390_advance_segment(struct dc390_srb* pSRB, u32 residue)
{
unsigned long xfer = pSRB->SGToBeXferLen - residue;
pSRB->SGBusAddr += xfer;
pSRB->TotalXferredLen += xfer;
pSRB->SGToBeXferLen = residue;
return xfer;
}
static struct dc390_dcb __inline__ *dc390_findDCB ( struct dc390_acb* pACB, u8 id, u8 lun)
{
struct dc390_dcb* pDCB = pACB->pLinkDCB; if (!pDCB) return NULL;
while (pDCB->TargetID != id || pDCB->TargetLUN != lun)
{
pDCB = pDCB->pNextDCB;
if (pDCB == pACB->pLinkDCB)
return NULL;
}
DCBDEBUG1( printk (KERN_DEBUG "DCB %p (%02x,%02x) found.\n", \
pDCB, pDCB->TargetID, pDCB->TargetLUN));
return pDCB;
}
static __inline__ void dc390_Free_insert (struct dc390_acb* pACB, struct dc390_srb* pSRB)
{
DEBUG0(printk ("DC390: Free SRB %p\n", pSRB));
pSRB->pNextSRB = pACB->pFreeSRB;
pACB->pFreeSRB = pSRB;
}
static __inline__ void dc390_Going_append (struct dc390_dcb* pDCB, struct dc390_srb* pSRB)
{
pDCB->GoingSRBCnt++;
DEBUG0(printk("DC390: Append SRB %p to Going\n", pSRB));
if( pDCB->pGoingSRB )
pDCB->pGoingLast->pNextSRB = pSRB;
else
pDCB->pGoingSRB = pSRB;
pDCB->pGoingLast = pSRB;
pSRB->pNextSRB = NULL;
}
static __inline__ void dc390_Going_remove (struct dc390_dcb* pDCB, struct dc390_srb* pSRB)
{
DEBUG0(printk("DC390: Remove SRB %p from Going\n", pSRB));
if (pSRB == pDCB->pGoingSRB)
pDCB->pGoingSRB = pSRB->pNextSRB;
else
{
struct dc390_srb* psrb = pDCB->pGoingSRB;
while (psrb && psrb->pNextSRB != pSRB)
psrb = psrb->pNextSRB;
if (!psrb)
{ printk (KERN_ERR "DC390: Remove non-ex. SRB %p from Going!\n", pSRB); return; }
psrb->pNextSRB = pSRB->pNextSRB;
if (pSRB == pDCB->pGoingLast)
pDCB->pGoingLast = psrb;
}
pDCB->GoingSRBCnt--;
}
static struct scatterlist* dc390_sg_build_single(struct scatterlist *sg, void *addr, unsigned int length)
{
sg_init_one(sg, addr, length);
return sg;
}
static int dc390_pci_map (struct dc390_srb* pSRB)
{
int error = 0;
struct scsi_cmnd *pcmd = pSRB->pcmd;
struct pci_dev *pdev = pSRB->pSRBDCB->pDCBACB->pdev;
dc390_cmd_scp_t* cmdp = ((dc390_cmd_scp_t*)(&pcmd->SCp));
if (pSRB->SRBFlag & AUTO_REQSENSE) {
pSRB->pSegmentList = dc390_sg_build_single(&pSRB->Segmentx, pcmd->sense_buffer, SCSI_SENSE_BUFFERSIZE);
pSRB->SGcount = pci_map_sg(pdev, pSRB->pSegmentList, 1,
DMA_FROM_DEVICE);
cmdp->saved_dma_handle = sg_dma_address(pSRB->pSegmentList);
if (pSRB->SGcount != 1)
error = 1;
DEBUG1(printk("%s(): Mapped sense buffer %p at %x\n", __func__, pcmd->sense_buffer, cmdp->saved_dma_handle));
} else if (scsi_sg_count(pcmd)) {
int nseg;
nseg = scsi_dma_map(pcmd);
pSRB->pSegmentList = scsi_sglist(pcmd);
pSRB->SGcount = nseg;
if (nseg < 0)
error = 1;
DEBUG1(printk("%s(): Mapped SG %p with %d (%d) elements\n",\
__func__, scsi_sglist(pcmd), nseg, scsi_sg_count(pcmd)));
} else
pSRB->SGcount = 0;
return error;
}
static void dc390_pci_unmap (struct dc390_srb* pSRB)
{
struct scsi_cmnd *pcmd = pSRB->pcmd;
struct pci_dev *pdev = pSRB->pSRBDCB->pDCBACB->pdev;
DEBUG1(dc390_cmd_scp_t* cmdp = ((dc390_cmd_scp_t*)(&pcmd->SCp)));
if (pSRB->SRBFlag) {
pci_unmap_sg(pdev, &pSRB->Segmentx, 1, DMA_FROM_DEVICE);
DEBUG1(printk("%s(): Unmapped sense buffer at %x\n", __func__, cmdp->saved_dma_handle));
} else {
scsi_dma_unmap(pcmd);
DEBUG1(printk("%s(): Unmapped SG at %p with %d elements\n",
__func__, scsi_sglist(pcmd), scsi_sg_count(pcmd)));
}
}
static void __inline__
dc390_freetag (struct dc390_dcb* pDCB, struct dc390_srb* pSRB)
{
if (pSRB->TagNumber != SCSI_NO_TAG) {
pDCB->TagMask &= ~(1 << pSRB->TagNumber);
pSRB->TagNumber = SCSI_NO_TAG;
}
}
static int
dc390_StartSCSI( struct dc390_acb* pACB, struct dc390_dcb* pDCB, struct dc390_srb* pSRB )
{
struct scsi_cmnd *scmd = pSRB->pcmd;
struct scsi_device *sdev = scmd->device;
u8 cmd, disc_allowed, try_sync_nego;
char tag[2];
pSRB->ScsiPhase = SCSI_NOP0;
if (pACB->Connected)
{
printk (KERN_WARNING "DC390: Can't select when connected! (%08x,%02x)\n",
pSRB->SRBState, pSRB->SRBFlag);
pSRB->SRBState = SRB_READY;
pACB->SelConn++;
return 1;
}
if (time_before (jiffies, pACB->last_reset))
{
DEBUG0(printk ("DC390: We were just reset and don't accept commands yet!\n"));
return 1;
}
dc390_pci_map(pSRB);
DC390_write8 (Scsi_Dest_ID, pDCB->TargetID);
DC390_write8 (Sync_Period, pDCB->SyncPeriod);
DC390_write8 (Sync_Offset, pDCB->SyncOffset);
DC390_write8 (CtrlReg1, pDCB->CtrlR1);
DC390_write8 (CtrlReg3, pDCB->CtrlR3);
DC390_write8 (CtrlReg4, pDCB->CtrlR4);
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
DEBUG1(printk (KERN_INFO "DC390: Start SCSI command: %02x (Sync:%02x)\n",\
scmd->cmnd[0], pDCB->SyncMode));
if (! (pSRB->SRBFlag & AUTO_REQSENSE))
disc_allowed = pDCB->DevMode & EN_DISCONNECT_;
else
disc_allowed = 0;
if ((pDCB->SyncMode & SYNC_ENABLE) && pDCB->TargetLUN == 0 && sdev->sdtr &&
(((scmd->cmnd[0] == REQUEST_SENSE || (pSRB->SRBFlag & AUTO_REQSENSE)) &&
!(pDCB->SyncMode & SYNC_NEGO_DONE)) || scmd->cmnd[0] == INQUIRY))
try_sync_nego = 1;
else
try_sync_nego = 0;
pSRB->MsgCnt = 0;
cmd = SEL_W_ATN;
DC390_write8 (ScsiFifo, IDENTIFY(disc_allowed, pDCB->TargetLUN));
if ((pDCB->SyncMode & EN_TAG_QUEUEING) && disc_allowed && scsi_populate_tag_msg(scmd, tag)) {
DC390_write8(ScsiFifo, tag[0]);
pDCB->TagMask |= 1 << tag[1];
pSRB->TagNumber = tag[1];
DC390_write8(ScsiFifo, tag[1]);
DEBUG1(printk(KERN_INFO "DC390: Select w/DisCn for SRB %p, block tag %02x\n", pSRB, tag[1]));
cmd = SEL_W_ATN3;
} else {
DEBUG1(printk(KERN_INFO "DC390: Select w%s/DisCn for SRB %p, No TagQ\n", disc_allowed ? "" : "o", pSRB));
}
pSRB->SRBState = SRB_START_;
if (try_sync_nego)
{
u8 Sync_Off = pDCB->SyncOffset;
DEBUG0(printk (KERN_INFO "DC390: NEW Sync Nego code triggered (%i %i)\n", pDCB->TargetID, pDCB->TargetLUN));
pSRB->MsgOutBuf[0] = EXTENDED_MESSAGE;
pSRB->MsgOutBuf[1] = 3;
pSRB->MsgOutBuf[2] = EXTENDED_SDTR;
pSRB->MsgOutBuf[3] = pDCB->NegoPeriod;
if (!(Sync_Off & 0x0f)) Sync_Off = SYNC_NEGO_OFFSET;
pSRB->MsgOutBuf[4] = Sync_Off;
pSRB->MsgCnt = 5;
pSRB->SRBState |= DO_SYNC_NEGO;
cmd = SEL_W_ATN_STOP;
}
if (cmd != SEL_W_ATN_STOP)
{
if( pSRB->SRBFlag & AUTO_REQSENSE )
{
DC390_write8 (ScsiFifo, REQUEST_SENSE);
DC390_write8 (ScsiFifo, pDCB->TargetLUN << 5);
DC390_write8 (ScsiFifo, 0);
DC390_write8 (ScsiFifo, 0);
DC390_write8 (ScsiFifo, SCSI_SENSE_BUFFERSIZE);
DC390_write8 (ScsiFifo, 0);
DEBUG1(printk (KERN_DEBUG "DC390: AutoReqSense !\n"));
}
else
{
u8 *ptr; u8 i;
ptr = (u8 *)scmd->cmnd;
for (i = 0; i < scmd->cmd_len; i++)
DC390_write8 (ScsiFifo, *(ptr++));
}
}
DEBUG0(if (pACB->pActiveDCB) \
printk (KERN_WARNING "DC390: ActiveDCB != 0\n"));
DEBUG0(if (pDCB->pActiveSRB) \
printk (KERN_WARNING "DC390: ActiveSRB != 0\n"));
if (DC390_read8 (Scsi_Status) & INTERRUPT)
{
dc390_freetag (pDCB, pSRB);
DEBUG0(printk ("DC390: Interrupt during Start SCSI (target %02i-%02i)\n",
scmd->device->id, (u8)scmd->device->lun));
pSRB->SRBState = SRB_READY;
pACB->SelLost++;
return 1;
}
DC390_write8 (ScsiCmd, cmd);
pACB->pActiveDCB = pDCB;
pDCB->pActiveSRB = pSRB;
pACB->Connected = 1;
pSRB->ScsiPhase = SCSI_NOP1;
return 0;
}
static void __inline__
dc390_InvalidCmd(struct dc390_acb* pACB)
{
if (pACB->pActiveDCB->pActiveSRB->SRBState & (SRB_START_ | SRB_MSGOUT))
DC390_write8(ScsiCmd, CLEAR_FIFO_CMD);
}
static irqreturn_t __inline__
DC390_Interrupt(void *dev_id)
{
struct dc390_acb *pACB = dev_id;
struct dc390_dcb *pDCB;
struct dc390_srb *pSRB;
u8 sstatus=0;
u8 phase;
void (*stateV)( struct dc390_acb*, struct dc390_srb*, u8 *);
u8 istate, istatus;
sstatus = DC390_read8 (Scsi_Status);
if( !(sstatus & INTERRUPT) )
return IRQ_NONE;
DEBUG1(printk (KERN_DEBUG "sstatus=%02x,", sstatus));
spin_lock_irq(pACB->pScsiHost->host_lock);
istate = DC390_read8 (Intern_State);
istatus = DC390_read8 (INT_Status);
DEBUG1(printk (KERN_INFO "Istatus(Res,Inv,Dis,Serv,Succ,ReS,SelA,Sel)=%02x,",istatus));
dc390_laststatus &= ~0x00ffffff;
dc390_laststatus |= sstatus<<16 | istate<<8 | istatus;
if (sstatus & ILLEGAL_OP_ERR)
{
printk ("DC390: Illegal Operation detected (%08x)!\n", dc390_laststatus);
dc390_dumpinfo (pACB, pACB->pActiveDCB, pACB->pActiveDCB->pActiveSRB);
}
else if (istatus & INVALID_CMD)
{
printk ("DC390: Invalid Command detected (%08x)!\n", dc390_laststatus);
dc390_InvalidCmd( pACB );
goto unlock;
}
if (istatus & SCSI_RESET)
{
dc390_ScsiRstDetect( pACB );
goto unlock;
}
if (istatus & DISCONNECTED)
{
dc390_Disconnect( pACB );
goto unlock;
}
if (istatus & RESELECTED)
{
dc390_Reselect( pACB );
goto unlock;
}
else if (istatus & (SELECTED | SEL_ATTENTION))
{
printk (KERN_ERR "DC390: Target mode not supported!\n");
goto unlock;
}
if (istatus & (SUCCESSFUL_OP|SERVICE_REQUEST) )
{
pDCB = pACB->pActiveDCB;
if (!pDCB)
{
printk (KERN_ERR "DC390: Suc. op/ Serv. req: pActiveDCB = 0!\n");
goto unlock;
}
pSRB = pDCB->pActiveSRB;
if( pDCB->DCBFlag & ABORT_DEV_ )
dc390_EnableMsgOut_Abort (pACB, pSRB);
phase = pSRB->ScsiPhase;
DEBUG1(printk (KERN_INFO "DC390: [%i]%s(0) (%02x)\n", phase, dc390_p0_str[phase], sstatus));
stateV = (void *) dc390_phase0[phase];
( *stateV )( pACB, pSRB, &sstatus );
pSRB->ScsiPhase = sstatus & 7;
phase = (u8) sstatus & 7;
DEBUG1(printk (KERN_INFO "DC390: [%i]%s(1) (%02x)\n", phase, dc390_p1_str[phase], sstatus));
stateV = (void *) dc390_phase1[phase];
( *stateV )( pACB, pSRB, &sstatus );
}
unlock:
spin_unlock_irq(pACB->pScsiHost->host_lock);
return IRQ_HANDLED;
}
static irqreturn_t do_DC390_Interrupt(int irq, void *dev_id)
{
irqreturn_t ret;
DEBUG1(printk (KERN_INFO "DC390: Irq (%i) caught: ", irq));
ret = DC390_Interrupt(dev_id);
DEBUG1(printk (".. IRQ returned\n"));
return ret;
}
static void
dc390_DataOut_0(struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
u8 sstatus;
u32 ResidCnt;
u8 dstate = 0;
sstatus = *psstatus;
if( !(pSRB->SRBState & SRB_XFERPAD) )
{
if( sstatus & (PARITY_ERR | ILLEGAL_OP_ERR) )
pSRB->SRBStatus |= PARITY_ERROR;
if( sstatus & COUNT_2_ZERO )
{
unsigned long timeout = jiffies + HZ;
if (pSRB->SGToBeXferLen)
while (time_before(jiffies, timeout) && !((dstate = DC390_read8 (DMA_Status)) & DMA_XFER_DONE)) {
spin_unlock_irq(pACB->pScsiHost->host_lock);
udelay(50);
spin_lock_irq(pACB->pScsiHost->host_lock);
}
if (!time_before(jiffies, timeout))
printk (KERN_CRIT "DC390: Deadlock in DataOut_0: DMA aborted unfinished: %06x bytes remain!!\n",
DC390_read32 (DMA_Wk_ByteCntr));
dc390_laststatus &= ~0xff000000;
dc390_laststatus |= dstate << 24;
pSRB->TotalXferredLen += pSRB->SGToBeXferLen;
pSRB->SGIndex++;
if( pSRB->SGIndex < pSRB->SGcount )
{
pSRB->pSegmentList++;
dc390_start_segment(pSRB);
}
else
pSRB->SGToBeXferLen = 0;
}
else
{
ResidCnt = ((u32) DC390_read8 (Current_Fifo) & 0x1f) +
(((u32) DC390_read8 (CtcReg_High) << 16) |
((u32) DC390_read8 (CtcReg_Mid) << 8) |
(u32) DC390_read8 (CtcReg_Low));
dc390_advance_segment(pSRB, ResidCnt);
}
}
if ((*psstatus & 7) != SCSI_DATA_OUT)
{
DC390_write8 (DMA_Cmd, WRITE_DIRECTION+DMA_IDLE_CMD);
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
}
}
static void
dc390_DataIn_0(struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
u8 sstatus, residual, bval;
u32 ResidCnt, i;
unsigned long xferCnt;
sstatus = *psstatus;
if( !(pSRB->SRBState & SRB_XFERPAD) )
{
if( sstatus & (PARITY_ERR | ILLEGAL_OP_ERR))
pSRB->SRBStatus |= PARITY_ERROR;
if( sstatus & COUNT_2_ZERO )
{
int dstate = 0;
unsigned long timeout = jiffies + HZ;
if (pSRB->SGToBeXferLen)
while (time_before(jiffies, timeout) && !((dstate = DC390_read8 (DMA_Status)) & DMA_XFER_DONE)) {
spin_unlock_irq(pACB->pScsiHost->host_lock);
udelay(50);
spin_lock_irq(pACB->pScsiHost->host_lock);
}
if (!time_before(jiffies, timeout)) {
printk (KERN_CRIT "DC390: Deadlock in DataIn_0: DMA aborted unfinished: %06x bytes remain!!\n",
DC390_read32 (DMA_Wk_ByteCntr));
printk (KERN_CRIT "DC390: DataIn_0: DMA State: %i\n", dstate);
}
dc390_laststatus &= ~0xff000000;
dc390_laststatus |= dstate << 24;
DEBUG1(ResidCnt = ((unsigned long) DC390_read8 (CtcReg_High) << 16) \
+ ((unsigned long) DC390_read8 (CtcReg_Mid) << 8) \
+ ((unsigned long) DC390_read8 (CtcReg_Low)));
DEBUG1(printk (KERN_DEBUG "Count_2_Zero (ResidCnt=%u,ToBeXfer=%lu),", ResidCnt, pSRB->SGToBeXferLen));
DC390_write8 (DMA_Cmd, READ_DIRECTION+DMA_IDLE_CMD);
pSRB->TotalXferredLen += pSRB->SGToBeXferLen;
pSRB->SGIndex++;
if( pSRB->SGIndex < pSRB->SGcount )
{
pSRB->pSegmentList++;
dc390_start_segment(pSRB);
}
else
pSRB->SGToBeXferLen = 0;
}
else
{
residual = 0;
bval = DC390_read8 (Current_Fifo);
while( bval & 0x1f )
{
DEBUG1(printk (KERN_DEBUG "Check for residuals,"));
if( (bval & 0x1f) == 1 )
{
for(i=0; i < 0x100; i++)
{
bval = DC390_read8 (Current_Fifo);
if( !(bval & 0x1f) )
goto din_1;
else if( i == 0x0ff )
{
residual = 1;
goto din_1;
}
}
}
else
bval = DC390_read8 (Current_Fifo);
}
din_1:
DC390_write8 (DMA_Cmd, READ_DIRECTION+DMA_BLAST_CMD);
for (i = 0xa000; i; i--)
{
bval = DC390_read8 (DMA_Status);
if (bval & BLAST_COMPLETE)
break;
}
if (!i) printk (KERN_ERR "DC390: DMA Blast aborted unfinished!\n");
dc390_laststatus &= ~0xff000000;
dc390_laststatus |= bval << 24;
DEBUG1(printk (KERN_DEBUG "Blast: Read %i times DMA_Status %02x", 0xa000-i, bval));
ResidCnt = (((u32) DC390_read8 (CtcReg_High) << 16) |
((u32) DC390_read8 (CtcReg_Mid) << 8)) |
(u32) DC390_read8 (CtcReg_Low);
xferCnt = dc390_advance_segment(pSRB, ResidCnt);
if (residual) {
size_t count = 1;
size_t offset = pSRB->SGBusAddr - sg_dma_address(pSRB->pSegmentList);
unsigned long flags;
u8 *ptr;
bval = DC390_read8 (ScsiFifo);
local_irq_save(flags);
ptr = scsi_kmap_atomic_sg(pSRB->pSegmentList, pSRB->SGcount, &offset, &count);
if (likely(ptr)) {
*(ptr + offset) = bval;
scsi_kunmap_atomic_sg(ptr);
}
local_irq_restore(flags);
WARN_ON(!ptr);
xferCnt += dc390_advance_segment(pSRB, pSRB->SGToBeXferLen - 1);
}
DEBUG1(printk (KERN_DEBUG "Xfered: %lu, Total: %lu, Remaining: %lu\n", xferCnt,\
pSRB->TotalXferredLen, pSRB->SGToBeXferLen));
}
}
if ((*psstatus & 7) != SCSI_DATA_IN)
{
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
DC390_write8 (DMA_Cmd, READ_DIRECTION+DMA_IDLE_CMD);
}
}
static void
dc390_Command_0( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
}
static void
dc390_Status_0( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
pSRB->TargetStatus = DC390_read8 (ScsiFifo);
pSRB->EndMessage = DC390_read8 (ScsiFifo);
*psstatus = SCSI_NOP0;
pSRB->SRBState = SRB_COMPLETED;
DC390_write8 (ScsiCmd, MSG_ACCEPTED_CMD);
}
static void
dc390_MsgOut_0( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
if( pSRB->SRBState & (SRB_UNEXPECT_RESEL+SRB_ABORT_SENT) )
*psstatus = SCSI_NOP0;
}
static void __inline__
dc390_reprog (struct dc390_acb* pACB, struct dc390_dcb* pDCB)
{
DC390_write8 (Sync_Period, pDCB->SyncPeriod);
DC390_write8 (Sync_Offset, pDCB->SyncOffset);
DC390_write8 (CtrlReg3, pDCB->CtrlR3);
DC390_write8 (CtrlReg4, pDCB->CtrlR4);
dc390_SetXferRate (pACB, pDCB);
}
static void
dc390_printMsg (u8 *MsgBuf, u8 len)
{
int i;
printk (" %02x", MsgBuf[0]);
for (i = 1; i < len; i++)
printk (" %02x", MsgBuf[i]);
printk ("\n");
}
static void __inline__
dc390_MsgIn_reject (struct dc390_acb* pACB, struct dc390_srb* pSRB)
{
pSRB->MsgOutBuf[0] = MESSAGE_REJECT;
pSRB->MsgCnt = 1;
DC390_ENABLE_MSGOUT;
DEBUG0 (printk (KERN_INFO "DC390: Reject message\n"));
}
static void
dc390_EnableMsgOut_Abort ( struct dc390_acb* pACB, struct dc390_srb* pSRB )
{
pSRB->MsgOutBuf[0] = ABORT;
pSRB->MsgCnt = 1; DC390_ENABLE_MSGOUT;
pSRB->pSRBDCB->DCBFlag &= ~ABORT_DEV_;
}
static struct dc390_srb*
dc390_MsgIn_QTag (struct dc390_acb* pACB, struct dc390_dcb* pDCB, s8 tag)
{
struct dc390_srb* pSRB = pDCB->pGoingSRB;
if (pSRB)
{
struct scsi_cmnd *scmd = scsi_find_tag(pSRB->pcmd->device, tag);
pSRB = (struct dc390_srb *)scmd->host_scribble;
if (pDCB->DCBFlag & ABORT_DEV_)
{
pSRB->SRBState = SRB_ABORT_SENT;
dc390_EnableMsgOut_Abort( pACB, pSRB );
}
if (!(pSRB->SRBState & SRB_DISCONNECT))
goto mingx0;
pDCB->pActiveSRB = pSRB;
pSRB->SRBState = SRB_DATA_XFER;
}
else
{
mingx0:
pSRB = pACB->pTmpSRB;
pSRB->SRBState = SRB_UNEXPECT_RESEL;
pDCB->pActiveSRB = pSRB;
pSRB->MsgOutBuf[0] = ABORT_TAG;
pSRB->MsgCnt = 1; DC390_ENABLE_MSGOUT;
}
return pSRB;
}
static void
dc390_MsgIn_set_async (struct dc390_acb* pACB, struct dc390_srb* pSRB)
{
struct dc390_dcb* pDCB = pSRB->pSRBDCB;
if (!(pSRB->SRBState & DO_SYNC_NEGO))
printk (KERN_INFO "DC390: Target %i initiates Non-Sync?\n", pDCB->TargetID);
pSRB->SRBState &= ~DO_SYNC_NEGO;
pDCB->SyncMode &= ~(SYNC_ENABLE+SYNC_NEGO_DONE);
pDCB->SyncPeriod = 0;
pDCB->SyncOffset = 0;
pDCB->CtrlR3 = FAST_CLK;
pDCB->CtrlR4 &= 0x3f;
pDCB->CtrlR4 |= pACB->glitch_cfg;
dc390_reprog (pACB, pDCB);
}
static void
dc390_MsgIn_set_sync (struct dc390_acb* pACB, struct dc390_srb* pSRB)
{
u8 bval;
u16 wval, wval1;
struct dc390_dcb* pDCB = pSRB->pSRBDCB;
u8 oldsyncperiod = pDCB->SyncPeriod;
u8 oldsyncoffset = pDCB->SyncOffset;
if (!(pSRB->SRBState & DO_SYNC_NEGO))
{
printk (KERN_INFO "DC390: Target %i initiates Sync: %ins %i ... answer ...\n",
pDCB->TargetID, pSRB->MsgInBuf[3]<<2, pSRB->MsgInBuf[4]);
if (pSRB->MsgInBuf[4] > 15)
{
printk (KERN_INFO "DC390: Lower Sync Offset to 15\n");
pSRB->MsgInBuf[4] = 15;
}
if (pSRB->MsgInBuf[3] < pDCB->NegoPeriod)
{
printk (KERN_INFO "DC390: Set sync nego period to %ins\n", pDCB->NegoPeriod << 2);
pSRB->MsgInBuf[3] = pDCB->NegoPeriod;
}
memcpy (pSRB->MsgOutBuf, pSRB->MsgInBuf, 5);
pSRB->MsgCnt = 5;
DC390_ENABLE_MSGOUT;
}
pSRB->SRBState &= ~DO_SYNC_NEGO;
pDCB->SyncMode |= SYNC_ENABLE+SYNC_NEGO_DONE;
pDCB->SyncOffset &= 0x0f0;
pDCB->SyncOffset |= pSRB->MsgInBuf[4];
pDCB->NegoPeriod = pSRB->MsgInBuf[3];
wval = (u16) pSRB->MsgInBuf[3];
wval = wval << 2; wval -= 3; wval1 = wval / 25;
if( (wval1 * 25) != wval) wval1++;
bval = FAST_CLK+FAST_SCSI;
pDCB->CtrlR4 &= 0x3f;
if (pACB->glitch_cfg != NS_TO_GLITCH(0))
pDCB->CtrlR4 |= NS_TO_GLITCH(((GLITCH_TO_NS(pACB->glitch_cfg)) - 1));
else
pDCB->CtrlR4 |= NS_TO_GLITCH(0);
if (wval1 < 4) pDCB->CtrlR4 |= NS_TO_GLITCH(0);
if (wval1 >= 8)
{
wval1--;
bval = FAST_CLK;
pDCB->CtrlR4 |= pACB->glitch_cfg;
}
pDCB->CtrlR3 = bval;
pDCB->SyncPeriod = (u8)wval1;
if ((oldsyncperiod != wval1 || oldsyncoffset != pDCB->SyncOffset) && pDCB->TargetLUN == 0)
{
if (! (bval & FAST_SCSI)) wval1++;
printk (KERN_INFO "DC390: Target %i: Sync transfer %i.%1i MHz, Offset %i\n", pDCB->TargetID,
40/wval1, ((40%wval1)*10+wval1/2)/wval1, pDCB->SyncOffset & 0x0f);
}
dc390_reprog (pACB, pDCB);
}
static void
dc390_restore_ptr (struct dc390_acb* pACB, struct dc390_srb* pSRB)
{
struct scsi_cmnd *pcmd = pSRB->pcmd;
struct scatterlist *psgl;
pSRB->TotalXferredLen = 0;
pSRB->SGIndex = 0;
if (scsi_sg_count(pcmd)) {
size_t saved;
pSRB->pSegmentList = scsi_sglist(pcmd);
psgl = pSRB->pSegmentList;
while (pSRB->TotalXferredLen + (unsigned long) sg_dma_len(psgl) < pSRB->Saved_Ptr)
{
pSRB->TotalXferredLen += (unsigned long) sg_dma_len(psgl);
pSRB->SGIndex++;
if( pSRB->SGIndex < pSRB->SGcount )
{
pSRB->pSegmentList++;
dc390_start_segment(pSRB);
}
else
pSRB->SGToBeXferLen = 0;
}
saved = pSRB->Saved_Ptr - pSRB->TotalXferredLen;
pSRB->SGToBeXferLen -= saved;
pSRB->SGBusAddr += saved;
printk (KERN_INFO "DC390: Pointer restored. Segment %i, Total %li, Bus %08lx\n",
pSRB->SGIndex, pSRB->Saved_Ptr, pSRB->SGBusAddr);
} else {
pSRB->SGcount = 0;
printk (KERN_INFO "DC390: RESTORE_PTR message for Transfer without Scatter-Gather ??\n");
}
pSRB->TotalXferredLen = pSRB->Saved_Ptr;
}
static u8 __inline__
dc390_MsgIn_complete (u8 *msgbuf, u32 len)
{
if (*msgbuf == EXTENDED_MESSAGE)
{
if (len < 2) return 0;
if (len < msgbuf[1] + 2) return 0;
}
else if (*msgbuf >= 0x20 && *msgbuf <= 0x2f)
if (len < 2) return 0;
return 1;
}
static void
dc390_MsgIn_0( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
struct dc390_dcb* pDCB = pACB->pActiveDCB;
pSRB->MsgInBuf[pACB->MsgLen++] = DC390_read8 (ScsiFifo);
if (dc390_MsgIn_complete (pSRB->MsgInBuf, pACB->MsgLen))
{
DEBUG0 (printk (KERN_INFO "DC390: MsgIn:"); dc390_printMsg (pSRB->MsgInBuf, pACB->MsgLen));
switch (pSRB->MsgInBuf[0])
{
case DISCONNECT:
pSRB->SRBState = SRB_DISCONNECT; break;
case SIMPLE_QUEUE_TAG:
case HEAD_OF_QUEUE_TAG:
case ORDERED_QUEUE_TAG:
pSRB = dc390_MsgIn_QTag (pACB, pDCB, pSRB->MsgInBuf[1]);
break;
case MESSAGE_REJECT:
DC390_write8 (ScsiCmd, RESET_ATN_CMD);
pDCB->NegoPeriod = 50;
if( pSRB->SRBState & DO_SYNC_NEGO)
dc390_MsgIn_set_async (pACB, pSRB);
break;
case EXTENDED_MESSAGE:
if (pSRB->MsgInBuf[1] != 3 || pSRB->MsgInBuf[2] != EXTENDED_SDTR)
dc390_MsgIn_reject (pACB, pSRB);
else
{
if (pSRB->MsgInBuf[3] == 0 || pSRB->MsgInBuf[4] == 0)
dc390_MsgIn_set_async (pACB, pSRB);
else
dc390_MsgIn_set_sync (pACB, pSRB);
}
case COMMAND_COMPLETE: break;
case SAVE_POINTERS:
pSRB->Saved_Ptr = pSRB->TotalXferredLen;
break;
case RESTORE_POINTERS:
DEBUG0(printk ("DC390: RESTORE POINTER message received ... try to handle\n"));
dc390_restore_ptr (pACB, pSRB);
break;
default: dc390_MsgIn_reject (pACB, pSRB);
}
pSRB->SRBState &= ~SRB_MSGIN;
pACB->MsgLen = 0;
}
*psstatus = SCSI_NOP0;
DC390_write8 (ScsiCmd, MSG_ACCEPTED_CMD);
}
static void
dc390_DataIO_Comm( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 ioDir)
{
unsigned long lval;
struct dc390_dcb* pDCB = pACB->pActiveDCB;
if (pSRB == pACB->pTmpSRB)
{
if (pDCB)
printk(KERN_ERR "DC390: pSRB == pTmpSRB! (TagQ Error?) (%02i-%i)\n", pDCB->TargetID, pDCB->TargetLUN);
else
printk(KERN_ERR "DC390: pSRB == pTmpSRB! (TagQ Error?) (DCB 0!)\n");
if (pDCB && pACB->scan_devices && pDCB->GoingSRBCnt == 1) {
pSRB = pDCB->pGoingSRB;
pDCB->pActiveSRB = pSRB;
} else {
pSRB->pSRBDCB = pDCB;
dc390_EnableMsgOut_Abort(pACB, pSRB);
if (pDCB)
pDCB->DCBFlag |= ABORT_DEV;
return;
}
}
if( pSRB->SGIndex < pSRB->SGcount )
{
DC390_write8 (DMA_Cmd, DMA_IDLE_CMD | ioDir);
if( !pSRB->SGToBeXferLen )
{
dc390_start_segment(pSRB);
DEBUG1(printk (KERN_DEBUG " DC390: Next SG segment."));
}
lval = pSRB->SGToBeXferLen;
DEBUG1(printk (KERN_DEBUG " DC390: Start transfer: %li bytes (address %08lx)\n", lval, pSRB->SGBusAddr));
DC390_write8 (CtcReg_Low, (u8) lval);
lval >>= 8;
DC390_write8 (CtcReg_Mid, (u8) lval);
lval >>= 8;
DC390_write8 (CtcReg_High, (u8) lval);
DC390_write32 (DMA_XferCnt, pSRB->SGToBeXferLen);
DC390_write32 (DMA_XferAddr, pSRB->SGBusAddr);
pSRB->SRBState = SRB_DATA_XFER;
DC390_write8 (ScsiCmd, DMA_COMMAND+INFO_XFER_CMD);
DC390_write8 (DMA_Cmd, DMA_START_CMD | ioDir);
}
else
{
if( pSRB->SGcount )
{
pSRB->AdaptStatus = H_OVER_UNDER_RUN;
pSRB->SRBStatus |= OVER_RUN;
DEBUG0(printk (KERN_WARNING " DC390: Overrun -"));
}
DEBUG0(printk (KERN_WARNING " Clear transfer pad \n"));
DC390_write8 (CtcReg_Low, 0);
DC390_write8 (CtcReg_Mid, 0);
DC390_write8 (CtcReg_High, 0);
pSRB->SRBState |= SRB_XFERPAD;
DC390_write8 (ScsiCmd, DMA_COMMAND+XFER_PAD_BYTE);
}
}
static void
dc390_DataOutPhase( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
dc390_DataIO_Comm (pACB, pSRB, WRITE_DIRECTION);
}
static void
dc390_DataInPhase( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
dc390_DataIO_Comm (pACB, pSRB, READ_DIRECTION);
}
static void
dc390_CommandPhase( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
struct dc390_dcb* pDCB;
u8 i, cnt;
u8 *ptr;
DC390_write8 (ScsiCmd, RESET_ATN_CMD);
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
if( !(pSRB->SRBFlag & AUTO_REQSENSE) )
{
cnt = (u8) pSRB->pcmd->cmd_len;
ptr = (u8 *) pSRB->pcmd->cmnd;
for(i=0; i < cnt; i++)
DC390_write8 (ScsiFifo, *(ptr++));
}
else
{
DC390_write8 (ScsiFifo, REQUEST_SENSE);
pDCB = pACB->pActiveDCB;
DC390_write8 (ScsiFifo, pDCB->TargetLUN << 5);
DC390_write8 (ScsiFifo, 0);
DC390_write8 (ScsiFifo, 0);
DC390_write8 (ScsiFifo, SCSI_SENSE_BUFFERSIZE);
DC390_write8 (ScsiFifo, 0);
DEBUG0(printk(KERN_DEBUG "DC390: AutoReqSense (CmndPhase)!\n"));
}
pSRB->SRBState = SRB_COMMAND;
DC390_write8 (ScsiCmd, INFO_XFER_CMD);
}
static void
dc390_StatusPhase( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
pSRB->SRBState = SRB_STATUS;
DC390_write8 (ScsiCmd, INITIATOR_CMD_CMPLTE);
}
static void
dc390_MsgOutPhase( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
u8 bval, i, cnt;
u8 *ptr;
struct dc390_dcb* pDCB;
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
pDCB = pACB->pActiveDCB;
if( !(pSRB->SRBState & SRB_MSGOUT) )
{
cnt = pSRB->MsgCnt;
if( cnt )
{
ptr = (u8 *) pSRB->MsgOutBuf;
for(i=0; i < cnt; i++)
DC390_write8 (ScsiFifo, *(ptr++));
pSRB->MsgCnt = 0;
if( (pDCB->DCBFlag & ABORT_DEV_) &&
(pSRB->MsgOutBuf[0] == ABORT) )
pSRB->SRBState = SRB_ABORT_SENT;
}
else
{
bval = ABORT;
if( (pSRB->pcmd->cmnd[0] == INQUIRY ) ||
(pSRB->pcmd->cmnd[0] == REQUEST_SENSE) ||
(pSRB->SRBFlag & AUTO_REQSENSE) )
{
if( pDCB->SyncMode & SYNC_ENABLE )
goto mop1;
}
DC390_write8 (ScsiFifo, bval);
}
DC390_write8 (ScsiCmd, INFO_XFER_CMD);
}
else
{
mop1:
printk (KERN_ERR "DC390: OLD Sync Nego code triggered! (%i %i)\n", pDCB->TargetID, pDCB->TargetLUN);
DC390_write8 (ScsiFifo, EXTENDED_MESSAGE);
DC390_write8 (ScsiFifo, 3);
DC390_write8 (ScsiFifo, EXTENDED_SDTR);
DC390_write8 (ScsiFifo, pDCB->NegoPeriod);
if (pDCB->SyncOffset & 0x0f)
DC390_write8 (ScsiFifo, pDCB->SyncOffset);
else
DC390_write8 (ScsiFifo, SYNC_NEGO_OFFSET);
pSRB->SRBState |= DO_SYNC_NEGO;
DC390_write8 (ScsiCmd, INFO_XFER_CMD);
}
}
static void
dc390_MsgInPhase( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
if( !(pSRB->SRBState & SRB_MSGIN) )
{
pSRB->SRBState &= ~SRB_DISCONNECT;
pSRB->SRBState |= SRB_MSGIN;
}
DC390_write8 (ScsiCmd, INFO_XFER_CMD);
}
static void
dc390_Nop_0( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
}
static void
dc390_Nop_1( struct dc390_acb* pACB, struct dc390_srb* pSRB, u8 *psstatus)
{
}
static void
dc390_SetXferRate( struct dc390_acb* pACB, struct dc390_dcb* pDCB )
{
u8 bval, i, cnt;
struct dc390_dcb* ptr;
if( !(pDCB->TargetLUN) )
{
if( !pACB->scan_devices )
{
ptr = pACB->pLinkDCB;
cnt = pACB->DCBCnt;
bval = pDCB->TargetID;
for(i=0; i<cnt; i++)
{
if( ptr->TargetID == bval )
{
ptr->SyncPeriod = pDCB->SyncPeriod;
ptr->SyncOffset = pDCB->SyncOffset;
ptr->CtrlR3 = pDCB->CtrlR3;
ptr->CtrlR4 = pDCB->CtrlR4;
ptr->SyncMode = pDCB->SyncMode;
}
ptr = ptr->pNextDCB;
}
}
}
return;
}
static void
dc390_Disconnect( struct dc390_acb* pACB )
{
struct dc390_dcb *pDCB;
struct dc390_srb *pSRB, *psrb;
u8 i, cnt;
DEBUG0(printk(KERN_INFO "DISC,"));
if (!pACB->Connected) printk(KERN_ERR "DC390: Disconnect not-connected bus?\n");
pACB->Connected = 0;
pDCB = pACB->pActiveDCB;
if (!pDCB)
{
DEBUG0(printk(KERN_ERR "ACB:%p->ActiveDCB:%p IOPort:%04x IRQ:%02x !\n",\
pACB, pDCB, pACB->IOPortBase, pACB->IRQLevel));
mdelay(400);
DC390_read8 (INT_Status);
DC390_write8 (ScsiCmd, EN_SEL_RESEL);
return;
}
DC390_write8 (ScsiCmd, EN_SEL_RESEL);
pSRB = pDCB->pActiveSRB;
pACB->pActiveDCB = NULL;
pSRB->ScsiPhase = SCSI_NOP0;
if( pSRB->SRBState & SRB_UNEXPECT_RESEL )
pSRB->SRBState = 0;
else if( pSRB->SRBState & SRB_ABORT_SENT )
{
pDCB->TagMask = 0;
pDCB->DCBFlag = 0;
cnt = pDCB->GoingSRBCnt;
pDCB->GoingSRBCnt = 0;
pSRB = pDCB->pGoingSRB;
for( i=0; i < cnt; i++)
{
psrb = pSRB->pNextSRB;
dc390_Free_insert (pACB, pSRB);
pSRB = psrb;
}
pDCB->pGoingSRB = NULL;
}
else
{
if( (pSRB->SRBState & (SRB_START_+SRB_MSGOUT)) ||
!(pSRB->SRBState & (SRB_DISCONNECT+SRB_COMPLETED)) )
{
pSRB->AdaptStatus = H_SEL_TIMEOUT;
pSRB->TargetStatus = 0;
goto disc1;
}
else if (!(pSRB->SRBState & SRB_DISCONNECT) && (pSRB->SRBState & SRB_COMPLETED))
{
disc1:
dc390_freetag (pDCB, pSRB);
pDCB->pActiveSRB = NULL;
pSRB->SRBState = SRB_FREE;
dc390_SRBdone( pACB, pDCB, pSRB);
}
}
pACB->MsgLen = 0;
}
static void
dc390_Reselect( struct dc390_acb* pACB )
{
struct dc390_dcb* pDCB;
struct dc390_srb* pSRB;
u8 id, lun;
DEBUG0(printk(KERN_INFO "RSEL,"));
pACB->Connected = 1;
pDCB = pACB->pActiveDCB;
if( pDCB )
{
DEBUG0(printk ("DC390: (ActiveDCB != 0: Arb. lost but resel. won)!\n"));
pSRB = pDCB->pActiveSRB;
if( !( pACB->scan_devices ) )
{
struct scsi_cmnd *pcmd = pSRB->pcmd;
scsi_set_resid(pcmd, scsi_bufflen(pcmd));
SET_RES_DID(pcmd->result, DID_SOFT_ERROR);
dc390_Going_remove(pDCB, pSRB);
dc390_Free_insert(pACB, pSRB);
pcmd->scsi_done (pcmd);
DEBUG0(printk(KERN_DEBUG"DC390: Return SRB %p to free\n", pSRB));
}
}
lun = DC390_read8 (ScsiFifo);
DEBUG0(printk ("Dev %02x,", lun));
if (!(lun & (1 << pACB->pScsiHost->this_id)))
printk (KERN_ERR "DC390: Reselection must select host adapter: %02x!\n", lun);
else
lun ^= 1 << pACB->pScsiHost->this_id;
id = 0; while (lun >>= 1) id++;
lun = DC390_read8 (ScsiFifo);
if (!(lun & IDENTIFY_BASE)) printk (KERN_ERR "DC390: Resel: Expect identify message!\n");
lun &= 7;
DEBUG0(printk ("(%02i-%i),", id, lun));
pDCB = dc390_findDCB (pACB, id, lun);
if (!pDCB)
{
printk (KERN_ERR "DC390: Reselect from non existing device (%02i-%i)\n",
id, lun);
return;
}
pACB->pActiveDCB = pDCB;
if( pDCB->SyncMode & EN_TAG_QUEUEING )
{
pSRB = pACB->pTmpSRB;
pDCB->pActiveSRB = pSRB;
}
else
{
pSRB = pDCB->pActiveSRB;
if( !pSRB || !(pSRB->SRBState & SRB_DISCONNECT) )
{
pSRB= pACB->pTmpSRB;
pSRB->SRBState = SRB_UNEXPECT_RESEL;
printk (KERN_ERR "DC390: Reselect without outstanding cmnd (%02i-%i)\n",
id, lun);
pDCB->pActiveSRB = pSRB;
dc390_EnableMsgOut_Abort ( pACB, pSRB );
}
else
{
if( pDCB->DCBFlag & ABORT_DEV_ )
{
pSRB->SRBState = SRB_ABORT_SENT;
printk (KERN_INFO "DC390: Reselect: Abort (%02i-%i)\n",
id, lun);
dc390_EnableMsgOut_Abort( pACB, pSRB );
}
else
pSRB->SRBState = SRB_DATA_XFER;
}
}
DEBUG1(printk (KERN_DEBUG "Resel SRB(%p): TagNum (%02x)\n", pSRB, pSRB->TagNumber));
pSRB->ScsiPhase = SCSI_NOP0;
DC390_write8 (Scsi_Dest_ID, pDCB->TargetID);
DC390_write8 (Sync_Period, pDCB->SyncPeriod);
DC390_write8 (Sync_Offset, pDCB->SyncOffset);
DC390_write8 (CtrlReg1, pDCB->CtrlR1);
DC390_write8 (CtrlReg3, pDCB->CtrlR3);
DC390_write8 (CtrlReg4, pDCB->CtrlR4);
DC390_write8 (ScsiCmd, MSG_ACCEPTED_CMD);
}
static int __inline__
dc390_RequestSense(struct dc390_acb* pACB, struct dc390_dcb* pDCB, struct dc390_srb* pSRB)
{
struct scsi_cmnd *pcmd;
pcmd = pSRB->pcmd;
REMOVABLEDEBUG(printk(KERN_INFO "DC390: RequestSense(Cmd %02x, Id %02x, LUN %02x)\n",\
pcmd->cmnd[0], pDCB->TargetID, pDCB->TargetLUN));
pSRB->SRBFlag |= AUTO_REQSENSE;
pSRB->SavedTotXLen = pSRB->TotalXferredLen;
pSRB->AdaptStatus = 0;
pSRB->TargetStatus = 0;
pSRB->SGIndex = 0;
pSRB->TotalXferredLen = 0;
pSRB->SGToBeXferLen = 0;
return dc390_StartSCSI(pACB, pDCB, pSRB);
}
static void
dc390_SRBdone( struct dc390_acb* pACB, struct dc390_dcb* pDCB, struct dc390_srb* pSRB )
{
u8 status;
struct scsi_cmnd *pcmd;
pcmd = pSRB->pcmd;
dc390_pci_unmap(pSRB);
status = pSRB->TargetStatus;
DEBUG0(printk (" SRBdone (%02x,%08x), SRB %p\n", status, pcmd->result, pSRB));
if(pSRB->SRBFlag & AUTO_REQSENSE)
{
pSRB->SRBFlag &= ~AUTO_REQSENSE;
pSRB->AdaptStatus = 0;
pSRB->TargetStatus = SAM_STAT_CHECK_CONDITION;
if (status == SAM_STAT_CHECK_CONDITION)
pcmd->result = MK_RES_LNX(0, DID_BAD_TARGET, 0, 0);
else
{
if( pSRB->pcmd->cmnd[0] == TEST_UNIT_READY )
{
pcmd->result = MK_RES_LNX(DRIVER_SENSE, DID_OK, 0, SAM_STAT_CHECK_CONDITION);
REMOVABLEDEBUG(printk(KERN_INFO "Cmd=%02x, Result=%08x, XferL=%08x\n",pSRB->pcmd->cmnd[0],\
(u32) pcmd->result, (u32) pSRB->TotalXferredLen));
} else {
SET_RES_DRV(pcmd->result, DRIVER_SENSE);
DEBUG0 (printk ("DC390: RETRY (%02x), target %02i-%02i\n", pcmd->cmnd[0], pcmd->device->id, (u8)pcmd->device->lun));
pSRB->TotalXferredLen = 0;
SET_RES_DID(pcmd->result, DID_SOFT_ERROR);
}
}
goto cmd_done;
}
if( status )
{
if (status == SAM_STAT_CHECK_CONDITION)
{
if (dc390_RequestSense(pACB, pDCB, pSRB)) {
SET_RES_DID(pcmd->result, DID_ERROR);
goto cmd_done;
}
return;
}
else if (status == SAM_STAT_TASK_SET_FULL)
{
scsi_track_queue_full(pcmd->device, pDCB->GoingSRBCnt - 1);
DEBUG0 (printk ("DC390: RETRY (%02x), target %02i-%02i\n", pcmd->cmnd[0], pcmd->device->id, (u8)pcmd->device->lun));
pSRB->TotalXferredLen = 0;
SET_RES_DID(pcmd->result, DID_SOFT_ERROR);
}
else if (status == SAM_STAT_BUSY &&
(pcmd->cmnd[0] == TEST_UNIT_READY || pcmd->cmnd[0] == INQUIRY) &&
pACB->scan_devices)
{
pSRB->AdaptStatus = 0;
pSRB->TargetStatus = status;
pcmd->result = MK_RES(0,0,pSRB->EndMessage,0);
}
else
{
pSRB->TotalXferredLen = 0;
SET_RES_DID(pcmd->result, DID_SOFT_ERROR);
goto cmd_done;
}
}
else
{
status = pSRB->AdaptStatus;
if (status == H_OVER_UNDER_RUN)
{
pSRB->TargetStatus = 0;
SET_RES_DID(pcmd->result,DID_OK);
SET_RES_MSG(pcmd->result,pSRB->EndMessage);
}
else if (status == H_SEL_TIMEOUT)
{
pcmd->result = MK_RES(0, DID_NO_CONNECT, 0, 0);
}
else if( pSRB->SRBStatus & PARITY_ERROR)
{
SET_RES_DID(pcmd->result,DID_PARITY);
SET_RES_MSG(pcmd->result,pSRB->EndMessage);
}
else
{
pSRB->AdaptStatus = 0;
pSRB->TargetStatus = 0;
SET_RES_DID(pcmd->result,DID_OK);
}
}
cmd_done:
scsi_set_resid(pcmd, scsi_bufflen(pcmd) - pSRB->TotalXferredLen);
dc390_Going_remove (pDCB, pSRB);
dc390_Free_insert (pACB, pSRB);
DEBUG0(printk (KERN_DEBUG "DC390: SRBdone: done\n"));
pcmd->scsi_done (pcmd);
return;
}
static void
dc390_DoingSRB_Done(struct dc390_acb* pACB, struct scsi_cmnd *cmd)
{
struct dc390_dcb *pDCB, *pdcb;
struct dc390_srb *psrb, *psrb2;
int i;
struct scsi_cmnd *pcmd;
pDCB = pACB->pLinkDCB;
pdcb = pDCB;
if (! pdcb) return;
do
{
psrb = pdcb->pGoingSRB;
for (i = 0; i < pdcb->GoingSRBCnt; i++)
{
psrb2 = psrb->pNextSRB;
pcmd = psrb->pcmd;
dc390_Free_insert (pACB, psrb);
psrb = psrb2;
}
pdcb->GoingSRBCnt = 0;
pdcb->pGoingSRB = NULL;
pdcb->TagMask = 0;
pdcb = pdcb->pNextDCB;
} while( pdcb != pDCB );
}
static void
dc390_ResetSCSIBus( struct dc390_acb* pACB )
{
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
DC390_write8 (DMA_Cmd, DMA_IDLE_CMD);
DC390_write8 (ScsiCmd, RST_SCSI_BUS_CMD);
pACB->Connected = 0;
return;
}
static void
dc390_ScsiRstDetect( struct dc390_acb* pACB )
{
printk ("DC390: Rst_Detect: laststat = %08x\n", dc390_laststatus);
DC390_write8 (DMA_Cmd, DMA_IDLE_CMD);
udelay (1000);
DC390_write8 (ScsiCmd, CLEAR_FIFO_CMD);
pACB->last_reset = jiffies + 5*HZ/2
+ HZ * dc390_eepromBuf[pACB->AdapterIndex][EE_DELAY];
pACB->Connected = 0;
if( pACB->ACBFlag & RESET_DEV )
pACB->ACBFlag |= RESET_DONE;
else
{
pACB->ACBFlag |= RESET_DETECT;
dc390_ResetDevParam( pACB );
dc390_DoingSRB_Done( pACB, NULL);
pACB->pActiveDCB = NULL;
pACB->ACBFlag = 0;
}
return;
}
static int DC390_queuecommand_lck(struct scsi_cmnd *cmd,
void (*done)(struct scsi_cmnd *))
{
struct scsi_device *sdev = cmd->device;
struct dc390_acb *acb = (struct dc390_acb *)sdev->host->hostdata;
struct dc390_dcb *dcb = sdev->hostdata;
struct dc390_srb *srb;
if (sdev->queue_depth <= dcb->GoingSRBCnt)
goto device_busy;
if (acb->pActiveDCB)
goto host_busy;
if (acb->ACBFlag & (RESET_DETECT|RESET_DONE|RESET_DEV))
goto host_busy;
srb = acb->pFreeSRB;
if (unlikely(srb == NULL))
goto host_busy;
cmd->scsi_done = done;
cmd->result = 0;
acb->Cmds++;
acb->pFreeSRB = srb->pNextSRB;
srb->pNextSRB = NULL;
srb->pSRBDCB = dcb;
srb->pcmd = cmd;
cmd->host_scribble = (char *)srb;
srb->SGIndex = 0;
srb->AdaptStatus = 0;
srb->TargetStatus = 0;
srb->MsgCnt = 0;
srb->SRBStatus = 0;
srb->SRBFlag = 0;
srb->SRBState = 0;
srb->TotalXferredLen = 0;
srb->SGBusAddr = 0;
srb->SGToBeXferLen = 0;
srb->ScsiPhase = 0;
srb->EndMessage = 0;
srb->TagNumber = SCSI_NO_TAG;
if (dc390_StartSCSI(acb, dcb, srb)) {
dc390_Free_insert(acb, srb);
goto host_busy;
}
dc390_Going_append(dcb, srb);
return 0;
host_busy:
return SCSI_MLQUEUE_HOST_BUSY;
device_busy:
return SCSI_MLQUEUE_DEVICE_BUSY;
}
int DC390_abort(struct scsi_cmnd *cmd)
{
struct dc390_acb *pACB = (struct dc390_acb*) cmd->device->host->hostdata;
struct dc390_dcb *pDCB = (struct dc390_dcb*) cmd->device->hostdata;
scmd_printk(KERN_WARNING, cmd, "DC390: Abort command\n");
dc390_dumpinfo(pACB, pDCB, NULL);
pDCB->DCBFlag |= ABORT_DEV_;
printk(KERN_INFO "DC390: Aborted.\n");
return FAILED;
}
static void dc390_ResetDevParam( struct dc390_acb* pACB )
{
struct dc390_dcb *pDCB, *pdcb;
pDCB = pACB->pLinkDCB;
if (! pDCB) return;
pdcb = pDCB;
do
{
pDCB->SyncMode &= ~SYNC_NEGO_DONE;
pDCB->SyncPeriod = 0;
pDCB->SyncOffset = 0;
pDCB->TagMask = 0;
pDCB->CtrlR3 = FAST_CLK;
pDCB->CtrlR4 &= NEGATE_REQACKDATA | CTRL4_RESERVED | NEGATE_REQACK;
pDCB->CtrlR4 |= pACB->glitch_cfg;
pDCB = pDCB->pNextDCB;
}
while( pdcb != pDCB );
pACB->ACBFlag &= ~(RESET_DEV | RESET_DONE | RESET_DETECT);
}
static int DC390_bus_reset (struct scsi_cmnd *cmd)
{
struct dc390_acb* pACB = (struct dc390_acb*) cmd->device->host->hostdata;
u8 bval;
spin_lock_irq(cmd->device->host->host_lock);
bval = DC390_read8(CtrlReg1) | DIS_INT_ON_SCSI_RST;
DC390_write8(CtrlReg1, bval);
pACB->ACBFlag |= RESET_DEV;
dc390_ResetSCSIBus(pACB);
dc390_ResetDevParam(pACB);
mdelay(1);
pACB->last_reset = jiffies + 3*HZ/2
+ HZ * dc390_eepromBuf[pACB->AdapterIndex][EE_DELAY];
DC390_write8(ScsiCmd, CLEAR_FIFO_CMD);
DC390_read8(INT_Status);
dc390_DoingSRB_Done(pACB, cmd);
pACB->pActiveDCB = NULL;
pACB->ACBFlag = 0;
bval = DC390_read8(CtrlReg1) & ~DIS_INT_ON_SCSI_RST;
DC390_write8(CtrlReg1, bval);
spin_unlock_irq(cmd->device->host->host_lock);
return SUCCESS;
}
static int dc390_slave_alloc(struct scsi_device *scsi_device)
{
struct dc390_acb *pACB = (struct dc390_acb*) scsi_device->host->hostdata;
struct dc390_dcb *pDCB, *pDCB2 = NULL;
uint id = scsi_device->id;
uint lun = scsi_device->lun;
pDCB = kzalloc(sizeof(struct dc390_dcb), GFP_KERNEL);
if (!pDCB)
return -ENOMEM;
if (!pACB->DCBCnt++) {
pACB->pLinkDCB = pDCB;
pACB->pDCBRunRobin = pDCB;
} else {
pACB->pLastDCB->pNextDCB = pDCB;
}
pDCB->pNextDCB = pACB->pLinkDCB;
pACB->pLastDCB = pDCB;
pDCB->pDCBACB = pACB;
pDCB->TargetID = id;
pDCB->TargetLUN = lun;
if (lun && (pDCB2 = dc390_findDCB(pACB, id, 0))) {
pDCB->DevMode = pDCB2->DevMode;
pDCB->SyncMode = pDCB2->SyncMode & SYNC_NEGO_DONE;
pDCB->SyncPeriod = pDCB2->SyncPeriod;
pDCB->SyncOffset = pDCB2->SyncOffset;
pDCB->NegoPeriod = pDCB2->NegoPeriod;
pDCB->CtrlR3 = pDCB2->CtrlR3;
pDCB->CtrlR4 = pDCB2->CtrlR4;
} else {
u8 index = pACB->AdapterIndex;
PEEprom prom = (PEEprom) &dc390_eepromBuf[index][id << 2];
pDCB->DevMode = prom->EE_MODE1;
pDCB->NegoPeriod =
(dc390_clock_period1[prom->EE_SPEED] * 25) >> 2;
pDCB->CtrlR3 = FAST_CLK;
pDCB->CtrlR4 = pACB->glitch_cfg | CTRL4_RESERVED;
if (dc390_eepromBuf[index][EE_MODE2] & ACTIVE_NEGATION)
pDCB->CtrlR4 |= NEGATE_REQACKDATA | NEGATE_REQACK;
}
if (pDCB->DevMode & SYNC_NEGO_)
pDCB->SyncMode |= SYNC_ENABLE;
else {
pDCB->SyncMode = 0;
pDCB->SyncOffset &= ~0x0f;
}
pDCB->CtrlR1 = pACB->pScsiHost->this_id;
if (pDCB->DevMode & PARITY_CHK_)
pDCB->CtrlR1 |= PARITY_ERR_REPO;
pACB->scan_devices = 1;
scsi_device->hostdata = pDCB;
return 0;
}
static void dc390_slave_destroy(struct scsi_device *scsi_device)
{
struct dc390_acb* pACB = (struct dc390_acb*) scsi_device->host->hostdata;
struct dc390_dcb* pDCB = (struct dc390_dcb*) scsi_device->hostdata;
struct dc390_dcb* pPrevDCB = pACB->pLinkDCB;
pACB->scan_devices = 0;
BUG_ON(pDCB->GoingSRBCnt > 1);
if (pDCB == pACB->pLinkDCB) {
if (pACB->pLastDCB == pDCB) {
pDCB->pNextDCB = NULL;
pACB->pLastDCB = NULL;
}
pACB->pLinkDCB = pDCB->pNextDCB;
} else {
while (pPrevDCB->pNextDCB != pDCB)
pPrevDCB = pPrevDCB->pNextDCB;
pPrevDCB->pNextDCB = pDCB->pNextDCB;
if (pDCB == pACB->pLastDCB)
pACB->pLastDCB = pPrevDCB;
}
if (pDCB == pACB->pActiveDCB)
pACB->pActiveDCB = NULL;
if (pDCB == pACB->pLinkDCB)
pACB->pLinkDCB = pDCB->pNextDCB;
if (pDCB == pACB->pDCBRunRobin)
pACB->pDCBRunRobin = pDCB->pNextDCB;
kfree(pDCB);
pACB->DCBCnt--;
}
static int dc390_slave_configure(struct scsi_device *sdev)
{
struct dc390_acb *acb = (struct dc390_acb *)sdev->host->hostdata;
struct dc390_dcb *dcb = (struct dc390_dcb *)sdev->hostdata;
acb->scan_devices = 0;
if (sdev->tagged_supported && (dcb->DevMode & TAG_QUEUEING_)) {
dcb->SyncMode |= EN_TAG_QUEUEING;
scsi_activate_tcq(sdev, acb->TagMaxNum);
}
return 0;
}
static void dc390_eeprom_prepare_read(struct pci_dev *pdev, u8 cmd)
{
u8 carryFlag = 1, j = 0x80, bval;
int i;
for (i = 0; i < 9; i++) {
if (carryFlag) {
pci_write_config_byte(pdev, 0x80, 0x40);
bval = 0xc0;
} else
bval = 0x80;
udelay(160);
pci_write_config_byte(pdev, 0x80, bval);
udelay(160);
pci_write_config_byte(pdev, 0x80, 0);
udelay(160);
carryFlag = (cmd & j) ? 1 : 0;
j >>= 1;
}
}
static u16 dc390_eeprom_get_data(struct pci_dev *pdev)
{
int i;
u16 wval = 0;
u8 bval;
for (i = 0; i < 16; i++) {
wval <<= 1;
pci_write_config_byte(pdev, 0x80, 0x80);
udelay(160);
pci_write_config_byte(pdev, 0x80, 0x40);
udelay(160);
pci_read_config_byte(pdev, 0x00, &bval);
if (bval == 0x22)
wval |= 1;
}
return wval;
}
static void dc390_read_eeprom(struct pci_dev *pdev, u16 *ptr)
{
u8 cmd = EEPROM_READ, i;
for (i = 0; i < 0x40; i++) {
pci_write_config_byte(pdev, 0xc0, 0);
udelay(160);
dc390_eeprom_prepare_read(pdev, cmd++);
*ptr++ = dc390_eeprom_get_data(pdev);
pci_write_config_byte(pdev, 0x80, 0);
pci_write_config_byte(pdev, 0x80, 0);
udelay(160);
}
}
static void dc390_eeprom_override(u8 index)
{
u8 *ptr = (u8 *) dc390_eepromBuf[index], id;
if (tmscsim[0] != -2)
ptr[EE_ADAPT_SCSI_ID] = (u8)tmscsim[0];
if (tmscsim[3] != -2)
ptr[EE_MODE2] = (u8)tmscsim[3];
if (tmscsim[5] != -2)
ptr[EE_DELAY] = tmscsim[5];
if (tmscsim[4] != -2)
ptr[EE_TAG_CMD_NUM] = (u8)tmscsim[4];
for (id = 0; id < MAX_SCSI_ID; id++) {
if (tmscsim[2] != -2)
ptr[id << 2] = (u8)tmscsim[2];
if (tmscsim[1] != -2)
ptr[(id << 2) + 1] = (u8)tmscsim[1];
}
}
static void dc390_fill_with_defaults (void)
{
int i;
for (i = 0; i < 6; i++) {
if (tmscsim[i] < 0 || tmscsim[i] > 255)
tmscsim[i] = tmscsim_def[i];
}
if (tmscsim[0] > 7)
tmscsim[0] = 7;
if (tmscsim[1] > 7)
tmscsim[1] = 4;
if (tmscsim[4] > 5)
tmscsim[4] = 4;
if (tmscsim[5] > 180)
tmscsim[5] = 180;
}
static void dc390_check_eeprom(struct pci_dev *pdev, u8 index)
{
u8 interpd[] = {1, 3, 5, 10, 16, 30, 60, 120};
u8 EEbuf[128];
u16 *ptr = (u16 *)EEbuf, wval = 0;
int i;
dc390_read_eeprom(pdev, ptr);
memcpy(dc390_eepromBuf[index], EEbuf, EE_ADAPT_SCSI_ID);
memcpy(&dc390_eepromBuf[index][EE_ADAPT_SCSI_ID],
&EEbuf[REAL_EE_ADAPT_SCSI_ID], EE_LEN - EE_ADAPT_SCSI_ID);
dc390_eepromBuf[index][EE_DELAY] = interpd[dc390_eepromBuf[index][EE_DELAY]];
for (i = 0; i < 0x40; i++, ptr++)
wval += *ptr;
if (wval != 0x1234) {
int speed;
printk(KERN_INFO "DC390_init: No EEPROM found! Trying default settings ...\n");
dc390_fill_with_defaults();
speed = dc390_clock_speed[tmscsim[1]];
printk(KERN_INFO "DC390: Used defaults: AdaptID=%i, SpeedIdx=%i (%i.%i MHz), "
"DevMode=0x%02x, AdaptMode=0x%02x, TaggedCmnds=%i (%i), DelayReset=%is\n",
tmscsim[0], tmscsim[1], speed / 10, speed % 10,
(u8)tmscsim[2], (u8)tmscsim[3], tmscsim[4], 2 << (tmscsim[4]), tmscsim[5]);
}
}
static void dc390_init_hw(struct dc390_acb *pACB, u8 index)
{
struct Scsi_Host *shost = pACB->pScsiHost;
u8 dstate;
DC390_write8(CtrlReg1, DIS_INT_ON_SCSI_RST | shost->this_id);
if (pACB->Gmode2 & RST_SCSI_BUS) {
dc390_ResetSCSIBus(pACB);
udelay(1000);
pACB->last_reset = jiffies + HZ/2 +
HZ * dc390_eepromBuf[pACB->AdapterIndex][EE_DELAY];
}
pACB->ACBFlag = 0;
DC390_read8(INT_Status);
DC390_write8(Scsi_TimeOut, SEL_TIMEOUT);
DC390_write8(Clk_Factor, CLK_FREQ_40MHZ);
DC390_write8(ScsiCmd, NOP_CMD);
DC390_write8(CtrlReg2, EN_FEATURE+EN_SCSI2_CMD);
DC390_write8(CtrlReg3, FAST_CLK);
DC390_write8(CtrlReg4, pACB->glitch_cfg |
(dc390_eepromBuf[index][EE_MODE2] & ACTIVE_NEGATION) ?
NEGATE_REQACKDATA : 0);
DC390_write8(CtcReg_High, 0);
DC390_write8(DMA_Cmd, DMA_IDLE_CMD);
DC390_write8(ScsiCmd, CLEAR_FIFO_CMD);
DC390_write32(DMA_ScsiBusCtrl, EN_INT_ON_PCI_ABORT);
dstate = DC390_read8(DMA_Status);
DC390_write8(DMA_Status, dstate);
}
static int dc390_probe_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct dc390_acb *pACB;
struct Scsi_Host *shost;
unsigned long io_port;
int error = -ENODEV, i;
if (pci_enable_device(pdev))
goto out;
pci_set_master(pdev);
error = -ENOMEM;
if (disable_clustering)
driver_template.use_clustering = DISABLE_CLUSTERING;
shost = scsi_host_alloc(&driver_template, sizeof(struct dc390_acb));
if (!shost)
goto out_disable_device;
pACB = (struct dc390_acb *)shost->hostdata;
memset(pACB, 0, sizeof(struct dc390_acb));
dc390_check_eeprom(pdev, dc390_adapterCnt);
dc390_eeprom_override(dc390_adapterCnt);
io_port = pci_resource_start(pdev, 0);
shost->this_id = dc390_eepromBuf[dc390_adapterCnt][EE_ADAPT_SCSI_ID];
shost->io_port = io_port;
shost->n_io_port = 0x80;
shost->irq = pdev->irq;
shost->base = io_port;
shost->unique_id = io_port;
pACB->last_reset = jiffies;
pACB->pScsiHost = shost;
pACB->IOPortBase = (u16) io_port;
pACB->IRQLevel = pdev->irq;
shost->max_id = 8;
if (shost->max_id - 1 ==
dc390_eepromBuf[dc390_adapterCnt][EE_ADAPT_SCSI_ID])
shost->max_id--;
if (dc390_eepromBuf[dc390_adapterCnt][EE_MODE2] & LUN_CHECK)
shost->max_lun = 8;
else
shost->max_lun = 1;
pACB->pFreeSRB = pACB->SRB_array;
pACB->SRBCount = MAX_SRB_CNT;
pACB->AdapterIndex = dc390_adapterCnt;
pACB->TagMaxNum =
2 << dc390_eepromBuf[dc390_adapterCnt][EE_TAG_CMD_NUM];
pACB->Gmode2 = dc390_eepromBuf[dc390_adapterCnt][EE_MODE2];
for (i = 0; i < pACB->SRBCount-1; i++)
pACB->SRB_array[i].pNextSRB = &pACB->SRB_array[i+1];
pACB->SRB_array[pACB->SRBCount-1].pNextSRB = NULL;
pACB->pTmpSRB = &pACB->TmpSRB;
pACB->sel_timeout = SEL_TIMEOUT;
pACB->glitch_cfg = EATER_25NS;
pACB->pdev = pdev;
if (!request_region(io_port, shost->n_io_port, "tmscsim")) {
printk(KERN_ERR "DC390: register IO ports error!\n");
goto out_host_put;
}
DC390_read8_(INT_Status, io_port);
if (request_irq(pdev->irq, do_DC390_Interrupt, IRQF_SHARED,
"tmscsim", pACB)) {
printk(KERN_ERR "DC390: register IRQ error!\n");
goto out_release_region;
}
dc390_init_hw(pACB, dc390_adapterCnt);
dc390_adapterCnt++;
pci_set_drvdata(pdev, shost);
error = scsi_add_host(shost, &pdev->dev);
if (error)
goto out_free_irq;
scsi_scan_host(shost);
return 0;
out_free_irq:
free_irq(pdev->irq, pACB);
out_release_region:
release_region(io_port, shost->n_io_port);
out_host_put:
scsi_host_put(shost);
out_disable_device:
pci_disable_device(pdev);
out:
return error;
}
static void dc390_remove_one(struct pci_dev *dev)
{
struct Scsi_Host *scsi_host = pci_get_drvdata(dev);
unsigned long iflags;
struct dc390_acb* pACB = (struct dc390_acb*) scsi_host->hostdata;
u8 bval;
scsi_remove_host(scsi_host);
spin_lock_irqsave(scsi_host->host_lock, iflags);
pACB->ACBFlag = RESET_DEV;
bval = DC390_read8(CtrlReg1) | DIS_INT_ON_SCSI_RST;
DC390_write8 (CtrlReg1, bval);
if (pACB->Gmode2 & RST_SCSI_BUS)
dc390_ResetSCSIBus(pACB);
spin_unlock_irqrestore(scsi_host->host_lock, iflags);
free_irq(scsi_host->irq, pACB);
release_region(scsi_host->io_port, scsi_host->n_io_port);
pci_disable_device(dev);
scsi_host_put(scsi_host);
}
static int __init dc390_module_init(void)
{
if (!disable_clustering) {
printk(KERN_INFO "DC390: clustering now enabled by default. If you get problems load\n");
printk(KERN_INFO " with \"disable_clustering=1\" and report to maintainers\n");
}
if (tmscsim[0] == -1 || tmscsim[0] > 15) {
tmscsim[0] = 7;
tmscsim[1] = 4;
tmscsim[2] = PARITY_CHK_ | TAG_QUEUEING_;
tmscsim[3] = MORE2_DRV | GREATER_1G | RST_SCSI_BUS | ACTIVE_NEGATION;
tmscsim[4] = 2;
tmscsim[5] = 10;
printk (KERN_INFO "DC390: Using safe settings.\n");
}
return pci_register_driver(&dc390_driver);
}
static void __exit dc390_module_exit(void)
{
pci_unregister_driver(&dc390_driver);
}
static int __init dc390_setup (char *str)
{
int ints[8],i, im;
get_options(str, ARRAY_SIZE(ints), ints);
im = ints[0];
if (im > 6) {
printk (KERN_NOTICE "DC390: ignore extra params!\n");
im = 6;
}
for (i = 0; i < im; i++)
tmscsim[i] = ints[i+1];
return 1;
}
