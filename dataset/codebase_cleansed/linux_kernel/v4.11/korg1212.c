static int snd_korg1212_Send1212Command(struct snd_korg1212 *korg1212,
enum korg1212_dbcnst doorbellVal,
u32 mailBox0Val, u32 mailBox1Val,
u32 mailBox2Val, u32 mailBox3Val)
{
u32 retryCount;
u16 mailBox3Lo;
int rc = K1212_CMDRET_Success;
if (!korg1212->outDoorbellPtr) {
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: CardUninitialized\n");
return K1212_CMDRET_CardUninitialized;
}
K1212_DEBUG_PRINTK("K1212_DEBUG: Card <- 0x%08x 0x%08x [%s]\n",
doorbellVal, mailBox0Val, stateName[korg1212->cardState]);
for (retryCount = 0; retryCount < MAX_COMMAND_RETRIES; retryCount++) {
writel(mailBox3Val, korg1212->mailbox3Ptr);
writel(mailBox2Val, korg1212->mailbox2Ptr);
writel(mailBox1Val, korg1212->mailbox1Ptr);
writel(mailBox0Val, korg1212->mailbox0Ptr);
writel(doorbellVal, korg1212->outDoorbellPtr);
if ( doorbellVal == K1212_DB_RebootCard ||
doorbellVal == K1212_DB_BootFromDSPPage4 ||
doorbellVal == K1212_DB_StartDSPDownload ) {
rc = K1212_CMDRET_Success;
break;
}
udelay(COMMAND_ACK_DELAY);
mailBox3Lo = readl(korg1212->mailbox3Ptr);
if (mailBox3Lo & COMMAND_ACK_MASK) {
if ((mailBox3Lo & DOORBELL_VAL_MASK) == (doorbellVal & DOORBELL_VAL_MASK)) {
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: Card <- Success\n");
rc = K1212_CMDRET_Success;
break;
}
}
}
korg1212->cmdRetryCount += retryCount;
if (retryCount >= MAX_COMMAND_RETRIES) {
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: Card <- NoAckFromCard\n");
rc = K1212_CMDRET_NoAckFromCard;
}
return rc;
}
static void snd_korg1212_SendStop(struct snd_korg1212 *korg1212)
{
if (! korg1212->stop_pending_cnt) {
korg1212->sharedBufferPtr->cardCommand = 0xffffffff;
korg1212->stop_pending_cnt = HZ;
mod_timer(&korg1212->timer, jiffies + 1);
}
}
static void snd_korg1212_SendStopAndWait(struct snd_korg1212 *korg1212)
{
unsigned long flags;
spin_lock_irqsave(&korg1212->lock, flags);
korg1212->dsp_stop_is_processed = 0;
snd_korg1212_SendStop(korg1212);
spin_unlock_irqrestore(&korg1212->lock, flags);
wait_event_timeout(korg1212->wait, korg1212->dsp_stop_is_processed, (HZ * 3) / 2);
}
static void snd_korg1212_timer_func(unsigned long data)
{
struct snd_korg1212 *korg1212 = (struct snd_korg1212 *) data;
unsigned long flags;
spin_lock_irqsave(&korg1212->lock, flags);
if (korg1212->sharedBufferPtr->cardCommand == 0) {
korg1212->stop_pending_cnt = 0;
korg1212->dsp_stop_is_processed = 1;
wake_up(&korg1212->wait);
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: Stop ack'ed [%s]\n",
stateName[korg1212->cardState]);
} else {
if (--korg1212->stop_pending_cnt > 0) {
mod_timer(&korg1212->timer, jiffies + 1);
} else {
snd_printd("korg1212_timer_func timeout\n");
korg1212->sharedBufferPtr->cardCommand = 0;
korg1212->dsp_stop_is_processed = 1;
wake_up(&korg1212->wait);
K1212_DEBUG_PRINTK("K1212_DEBUG: Stop timeout [%s]\n",
stateName[korg1212->cardState]);
}
}
spin_unlock_irqrestore(&korg1212->lock, flags);
}
static int snd_korg1212_TurnOnIdleMonitor(struct snd_korg1212 *korg1212)
{
unsigned long flags;
int rc;
udelay(INTERCOMMAND_DELAY);
spin_lock_irqsave(&korg1212->lock, flags);
korg1212->idleMonitorOn = 1;
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_SelectPlayMode,
K1212_MODE_MonitorOn, 0, 0, 0);
spin_unlock_irqrestore(&korg1212->lock, flags);
return rc;
}
static void snd_korg1212_TurnOffIdleMonitor(struct snd_korg1212 *korg1212)
{
if (korg1212->idleMonitorOn) {
snd_korg1212_SendStopAndWait(korg1212);
korg1212->idleMonitorOn = 0;
}
}
static inline void snd_korg1212_setCardState(struct snd_korg1212 * korg1212, enum CardState csState)
{
korg1212->cardState = csState;
}
static int snd_korg1212_OpenCard(struct snd_korg1212 * korg1212)
{
K1212_DEBUG_PRINTK("K1212_DEBUG: OpenCard [%s] %d\n",
stateName[korg1212->cardState], korg1212->opencnt);
mutex_lock(&korg1212->open_mutex);
if (korg1212->opencnt++ == 0) {
snd_korg1212_TurnOffIdleMonitor(korg1212);
snd_korg1212_setCardState(korg1212, K1212_STATE_OPEN);
}
mutex_unlock(&korg1212->open_mutex);
return 1;
}
static int snd_korg1212_CloseCard(struct snd_korg1212 * korg1212)
{
K1212_DEBUG_PRINTK("K1212_DEBUG: CloseCard [%s] %d\n",
stateName[korg1212->cardState], korg1212->opencnt);
mutex_lock(&korg1212->open_mutex);
if (--(korg1212->opencnt)) {
mutex_unlock(&korg1212->open_mutex);
return 0;
}
if (korg1212->cardState == K1212_STATE_SETUP) {
int rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_SelectPlayMode,
K1212_MODE_StopPlay, 0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: CloseCard - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
if (rc != K1212_CMDRET_Success) {
mutex_unlock(&korg1212->open_mutex);
return 0;
}
} else if (korg1212->cardState > K1212_STATE_SETUP) {
snd_korg1212_SendStopAndWait(korg1212);
}
if (korg1212->cardState > K1212_STATE_READY) {
snd_korg1212_TurnOnIdleMonitor(korg1212);
snd_korg1212_setCardState(korg1212, K1212_STATE_READY);
}
mutex_unlock(&korg1212->open_mutex);
return 0;
}
static int snd_korg1212_SetupForPlay(struct snd_korg1212 * korg1212)
{
int rc;
K1212_DEBUG_PRINTK("K1212_DEBUG: SetupForPlay [%s] %d\n",
stateName[korg1212->cardState], korg1212->setcnt);
if (korg1212->setcnt++)
return 0;
snd_korg1212_setCardState(korg1212, K1212_STATE_SETUP);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_SelectPlayMode,
K1212_MODE_SetupPlay, 0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: SetupForPlay - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
if (rc != K1212_CMDRET_Success) {
return 1;
}
return 0;
}
static int snd_korg1212_TriggerPlay(struct snd_korg1212 * korg1212)
{
int rc;
K1212_DEBUG_PRINTK("K1212_DEBUG: TriggerPlay [%s] %d\n",
stateName[korg1212->cardState], korg1212->playcnt);
if (korg1212->playcnt++)
return 0;
snd_korg1212_setCardState(korg1212, K1212_STATE_PLAYING);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_TriggerPlay, 0, 0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: TriggerPlay - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
if (rc != K1212_CMDRET_Success) {
return 1;
}
return 0;
}
static int snd_korg1212_StopPlay(struct snd_korg1212 * korg1212)
{
K1212_DEBUG_PRINTK("K1212_DEBUG: StopPlay [%s] %d\n",
stateName[korg1212->cardState], korg1212->playcnt);
if (--(korg1212->playcnt))
return 0;
korg1212->setcnt = 0;
if (korg1212->cardState != K1212_STATE_ERRORSTOP)
snd_korg1212_SendStop(korg1212);
snd_korg1212_setCardState(korg1212, K1212_STATE_OPEN);
return 0;
}
static void snd_korg1212_EnableCardInterrupts(struct snd_korg1212 * korg1212)
{
writel(PCI_INT_ENABLE_BIT |
PCI_DOORBELL_INT_ENABLE_BIT |
LOCAL_INT_ENABLE_BIT |
LOCAL_DOORBELL_INT_ENABLE_BIT |
LOCAL_DMA1_INT_ENABLE_BIT,
korg1212->statusRegPtr);
}
static inline int snd_korg1212_use_is_exclusive(struct snd_korg1212 *korg1212)
{
if (korg1212->playback_pid != korg1212->capture_pid &&
korg1212->playback_pid >= 0 && korg1212->capture_pid >= 0)
return 0;
return 1;
}
static int snd_korg1212_SetRate(struct snd_korg1212 *korg1212, int rate)
{
static enum ClockSourceIndex s44[] = {
K1212_CLKIDX_AdatAt44_1K,
K1212_CLKIDX_WordAt44_1K,
K1212_CLKIDX_LocalAt44_1K
};
static enum ClockSourceIndex s48[] = {
K1212_CLKIDX_AdatAt48K,
K1212_CLKIDX_WordAt48K,
K1212_CLKIDX_LocalAt48K
};
int parm, rc;
if (!snd_korg1212_use_is_exclusive (korg1212))
return -EBUSY;
switch (rate) {
case 44100:
parm = s44[korg1212->clkSource];
break;
case 48000:
parm = s48[korg1212->clkSource];
break;
default:
return -EINVAL;
}
korg1212->clkSrcRate = parm;
korg1212->clkRate = rate;
udelay(INTERCOMMAND_DELAY);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_SetClockSourceRate,
ClockSourceSelector[korg1212->clkSrcRate],
0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Set Clock Source Selector - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
return 0;
}
static int snd_korg1212_SetClockSource(struct snd_korg1212 *korg1212, int source)
{
if (source < 0 || source > 2)
return -EINVAL;
korg1212->clkSource = source;
snd_korg1212_SetRate(korg1212, korg1212->clkRate);
return 0;
}
static void snd_korg1212_DisableCardInterrupts(struct snd_korg1212 *korg1212)
{
writel(0, korg1212->statusRegPtr);
}
static int snd_korg1212_WriteADCSensitivity(struct snd_korg1212 *korg1212)
{
struct SensBits sensVals;
int bitPosition;
int channel;
int clkIs48K;
int monModeSet;
u16 controlValue;
u16 count;
unsigned long flags;
K1212_DEBUG_PRINTK("K1212_DEBUG: WriteADCSensivity [%s]\n",
stateName[korg1212->cardState]);
controlValue = 0;
SetBitInWord(&controlValue, SET_SENS_LOCALINIT_BITPOS);
if (korg1212->cardState == K1212_STATE_MONITOR || korg1212->idleMonitorOn) {
monModeSet = 1;
snd_korg1212_SendStopAndWait(korg1212);
} else
monModeSet = 0;
spin_lock_irqsave(&korg1212->lock, flags);
writel(0, korg1212->mailbox3Ptr);
udelay(LOADSHIFT_DELAY);
switch (korg1212->clkSrcRate) {
case K1212_CLKIDX_AdatAt44_1K:
case K1212_CLKIDX_WordAt44_1K:
case K1212_CLKIDX_LocalAt44_1K:
clkIs48K = 0;
break;
case K1212_CLKIDX_WordAt48K:
case K1212_CLKIDX_AdatAt48K:
case K1212_CLKIDX_LocalAt48K:
default:
clkIs48K = 1;
break;
}
sensVals.l.v.leftChanId = SET_SENS_LEFTCHANID;
sensVals.r.v.rightChanId = SET_SENS_RIGHTCHANID;
sensVals.l.v.leftChanVal = korg1212->leftADCInSens;
sensVals.r.v.rightChanVal = korg1212->rightADCInSens;
for (channel = 0; channel < 2; channel++) {
ClearBitInWord(&controlValue, SET_SENS_LOADSHIFT_BITPOS);
ClearBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(LOADSHIFT_DELAY);
for (bitPosition = 15; bitPosition >= 0; bitPosition--) {
if (channel == 0) {
if (sensVals.l.leftSensBits & (0x0001 << bitPosition))
SetBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
else
ClearBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
} else {
if (sensVals.r.rightSensBits & (0x0001 << bitPosition))
SetBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
else
ClearBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
}
ClearBitInWord(&controlValue, SET_SENS_CLOCK_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(SENSCLKPULSE_WIDTH);
SetBitInWord(&controlValue, SET_SENS_CLOCK_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(SENSCLKPULSE_WIDTH);
}
ClearBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
ClearBitInWord(&controlValue, SET_SENS_CLOCK_BITPOS);
SetBitInWord(&controlValue, SET_SENS_LOADSHIFT_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(SENSCLKPULSE_WIDTH);
if (clkIs48K)
SetBitInWord(&controlValue, SET_SENS_DATA_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(ONE_RTC_TICK);
SetBitInWord(&controlValue, SET_SENS_CLOCK_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(SENSCLKPULSE_WIDTH);
ClearBitInWord(&controlValue, SET_SENS_CLOCK_BITPOS);
writew(controlValue, korg1212->sensRegPtr);
udelay(SENSCLKPULSE_WIDTH);
}
for (count = 0; count < 10; count++)
udelay(SENSCLKPULSE_WIDTH);
if (monModeSet) {
int rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_SelectPlayMode,
K1212_MODE_MonitorOn, 0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: WriteADCSensivity - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
}
spin_unlock_irqrestore(&korg1212->lock, flags);
return 1;
}
static void snd_korg1212_OnDSPDownloadComplete(struct snd_korg1212 *korg1212)
{
int channel, rc;
K1212_DEBUG_PRINTK("K1212_DEBUG: DSP download is complete. [%s]\n",
stateName[korg1212->cardState]);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_BootFromDSPPage4, 0, 0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Boot from Page 4 - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
msleep(DSP_BOOT_DELAY_IN_MS);
rc = snd_korg1212_Send1212Command(korg1212,
K1212_DB_ConfigureBufferMemory,
LowerWordSwap(korg1212->PlayDataPhy),
LowerWordSwap(korg1212->RecDataPhy),
((kNumBuffers * kPlayBufferFrames) / 2),
0
);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Configure Buffer Memory - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
udelay(INTERCOMMAND_DELAY);
rc = snd_korg1212_Send1212Command(korg1212,
K1212_DB_ConfigureMiscMemory,
LowerWordSwap(korg1212->VolumeTablePhy),
LowerWordSwap(korg1212->RoutingTablePhy),
LowerWordSwap(korg1212->AdatTimeCodePhy),
0
);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Configure Misc Memory - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
udelay(INTERCOMMAND_DELAY);
for (channel = 0; channel < kAudioChannels; channel++) {
korg1212->sharedBufferPtr->volumeData[channel] = k1212MaxVolume;
korg1212->sharedBufferPtr->routeData[channel] = 8 + (channel & 1);
}
snd_korg1212_WriteADCSensitivity(korg1212);
udelay(INTERCOMMAND_DELAY);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_SetClockSourceRate,
ClockSourceSelector[korg1212->clkSrcRate],
0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Set Clock Source Selector - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
rc = snd_korg1212_TurnOnIdleMonitor(korg1212);
snd_korg1212_setCardState(korg1212, K1212_STATE_READY);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Set Monitor On - RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
snd_korg1212_setCardState(korg1212, K1212_STATE_DSP_COMPLETE);
}
static irqreturn_t snd_korg1212_interrupt(int irq, void *dev_id)
{
u32 doorbellValue;
struct snd_korg1212 *korg1212 = dev_id;
doorbellValue = readl(korg1212->inDoorbellPtr);
if (!doorbellValue)
return IRQ_NONE;
spin_lock(&korg1212->lock);
writel(doorbellValue, korg1212->inDoorbellPtr);
korg1212->irqcount++;
korg1212->inIRQ++;
switch (doorbellValue) {
case K1212_DB_DSPDownloadDone:
K1212_DEBUG_PRINTK("K1212_DEBUG: IRQ DNLD count - %ld, %x, [%s].\n",
korg1212->irqcount, doorbellValue,
stateName[korg1212->cardState]);
if (korg1212->cardState == K1212_STATE_DSP_IN_PROCESS) {
korg1212->dsp_is_loaded = 1;
wake_up(&korg1212->wait);
}
break;
case K1212_DB_DMAERROR:
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: IRQ DMAE count - %ld, %x, [%s].\n",
korg1212->irqcount, doorbellValue,
stateName[korg1212->cardState]);
snd_printk(KERN_ERR "korg1212: DMA Error\n");
korg1212->errorcnt++;
korg1212->totalerrorcnt++;
korg1212->sharedBufferPtr->cardCommand = 0;
snd_korg1212_setCardState(korg1212, K1212_STATE_ERRORSTOP);
break;
case K1212_DB_CARDSTOPPED:
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: IRQ CSTP count - %ld, %x, [%s].\n",
korg1212->irqcount, doorbellValue,
stateName[korg1212->cardState]);
korg1212->sharedBufferPtr->cardCommand = 0;
break;
default:
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: IRQ DFLT count - %ld, %x, cpos=%d [%s].\n",
korg1212->irqcount, doorbellValue,
korg1212->currentBuffer, stateName[korg1212->cardState]);
if ((korg1212->cardState > K1212_STATE_SETUP) || korg1212->idleMonitorOn) {
korg1212->currentBuffer++;
if (korg1212->currentBuffer >= kNumBuffers)
korg1212->currentBuffer = 0;
if (!korg1212->running)
break;
if (korg1212->capture_substream) {
spin_unlock(&korg1212->lock);
snd_pcm_period_elapsed(korg1212->capture_substream);
spin_lock(&korg1212->lock);
}
if (korg1212->playback_substream) {
spin_unlock(&korg1212->lock);
snd_pcm_period_elapsed(korg1212->playback_substream);
spin_lock(&korg1212->lock);
}
}
break;
}
korg1212->inIRQ--;
spin_unlock(&korg1212->lock);
return IRQ_HANDLED;
}
static int snd_korg1212_downloadDSPCode(struct snd_korg1212 *korg1212)
{
int rc;
K1212_DEBUG_PRINTK("K1212_DEBUG: DSP download is starting... [%s]\n",
stateName[korg1212->cardState]);
if (korg1212->cardState >= K1212_STATE_DSP_IN_PROCESS)
return 1;
snd_korg1212_setCardState(korg1212, K1212_STATE_DSP_IN_PROCESS);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_StartDSPDownload,
UpperWordSwap(korg1212->dma_dsp.addr),
0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Start DSP Download RC = %d [%s]\n",
rc, stateName[korg1212->cardState]);
korg1212->dsp_is_loaded = 0;
wait_event_timeout(korg1212->wait, korg1212->dsp_is_loaded, HZ * CARD_BOOT_TIMEOUT);
if (! korg1212->dsp_is_loaded )
return -EBUSY;
snd_korg1212_OnDSPDownloadComplete(korg1212);
return 0;
}
static int snd_korg1212_silence(struct snd_korg1212 *korg1212, int pos, int count, int offset, int size)
{
struct KorgAudioFrame * dst = korg1212->playDataBufsPtr[0].bufferData + pos;
int i;
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_silence pos=%d offset=%d size=%d count=%d\n",
pos, offset, size, count);
if (snd_BUG_ON(pos + count > K1212_MAX_SAMPLES))
return -EINVAL;
for (i=0; i < count; i++) {
#if K1212_DEBUG_LEVEL > 0
if ( (void *) dst < (void *) korg1212->playDataBufsPtr ||
(void *) dst > (void *) korg1212->playDataBufsPtr[8].bufferData ) {
printk(KERN_DEBUG "K1212_DEBUG: snd_korg1212_silence KERNEL EFAULT dst=%p iter=%d\n",
dst, i);
return -EFAULT;
}
#endif
memset((void*) dst + offset, 0, size);
dst++;
}
return 0;
}
static int snd_korg1212_copy_to(struct snd_korg1212 *korg1212, void __user *dst, int pos, int count, int offset, int size)
{
struct KorgAudioFrame * src = korg1212->recordDataBufsPtr[0].bufferData + pos;
int i, rc;
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_copy_to pos=%d offset=%d size=%d\n",
pos, offset, size);
if (snd_BUG_ON(pos + count > K1212_MAX_SAMPLES))
return -EINVAL;
for (i=0; i < count; i++) {
#if K1212_DEBUG_LEVEL > 0
if ( (void *) src < (void *) korg1212->recordDataBufsPtr ||
(void *) src > (void *) korg1212->recordDataBufsPtr[8].bufferData ) {
printk(KERN_DEBUG "K1212_DEBUG: snd_korg1212_copy_to KERNEL EFAULT, src=%p dst=%p iter=%d\n", src, dst, i);
return -EFAULT;
}
#endif
rc = copy_to_user(dst + offset, src, size);
if (rc) {
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_copy_to USER EFAULT src=%p dst=%p iter=%d\n", src, dst, i);
return -EFAULT;
}
src++;
dst += size;
}
return 0;
}
static int snd_korg1212_copy_from(struct snd_korg1212 *korg1212, void __user *src, int pos, int count, int offset, int size)
{
struct KorgAudioFrame * dst = korg1212->playDataBufsPtr[0].bufferData + pos;
int i, rc;
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_copy_from pos=%d offset=%d size=%d count=%d\n",
pos, offset, size, count);
if (snd_BUG_ON(pos + count > K1212_MAX_SAMPLES))
return -EINVAL;
for (i=0; i < count; i++) {
#if K1212_DEBUG_LEVEL > 0
if ( (void *) dst < (void *) korg1212->playDataBufsPtr ||
(void *) dst > (void *) korg1212->playDataBufsPtr[8].bufferData ) {
printk(KERN_DEBUG "K1212_DEBUG: snd_korg1212_copy_from KERNEL EFAULT, src=%p dst=%p iter=%d\n", src, dst, i);
return -EFAULT;
}
#endif
rc = copy_from_user((void*) dst + offset, src, size);
if (rc) {
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_copy_from USER EFAULT src=%p dst=%p iter=%d\n", src, dst, i);
return -EFAULT;
}
dst++;
src += size;
}
return 0;
}
static void snd_korg1212_free_pcm(struct snd_pcm *pcm)
{
struct snd_korg1212 *korg1212 = pcm->private_data;
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_free_pcm [%s]\n",
stateName[korg1212->cardState]);
korg1212->pcm = NULL;
}
static int snd_korg1212_playback_open(struct snd_pcm_substream *substream)
{
unsigned long flags;
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_playback_open [%s]\n",
stateName[korg1212->cardState]);
snd_korg1212_OpenCard(korg1212);
runtime->hw = snd_korg1212_playback_info;
snd_pcm_set_runtime_buffer(substream, &korg1212->dma_play);
spin_lock_irqsave(&korg1212->lock, flags);
korg1212->playback_substream = substream;
korg1212->playback_pid = current->pid;
korg1212->periodsize = K1212_PERIODS;
korg1212->channels = K1212_CHANNELS;
korg1212->errorcnt = 0;
spin_unlock_irqrestore(&korg1212->lock, flags);
snd_pcm_hw_constraint_single(runtime, SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
kPlayBufferFrames);
return 0;
}
static int snd_korg1212_capture_open(struct snd_pcm_substream *substream)
{
unsigned long flags;
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_capture_open [%s]\n",
stateName[korg1212->cardState]);
snd_korg1212_OpenCard(korg1212);
runtime->hw = snd_korg1212_capture_info;
snd_pcm_set_runtime_buffer(substream, &korg1212->dma_rec);
spin_lock_irqsave(&korg1212->lock, flags);
korg1212->capture_substream = substream;
korg1212->capture_pid = current->pid;
korg1212->periodsize = K1212_PERIODS;
korg1212->channels = K1212_CHANNELS;
spin_unlock_irqrestore(&korg1212->lock, flags);
snd_pcm_hw_constraint_single(runtime, SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
kPlayBufferFrames);
return 0;
}
static int snd_korg1212_playback_close(struct snd_pcm_substream *substream)
{
unsigned long flags;
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_playback_close [%s]\n",
stateName[korg1212->cardState]);
snd_korg1212_silence(korg1212, 0, K1212_MAX_SAMPLES, 0, korg1212->channels * 2);
spin_lock_irqsave(&korg1212->lock, flags);
korg1212->playback_pid = -1;
korg1212->playback_substream = NULL;
korg1212->periodsize = 0;
spin_unlock_irqrestore(&korg1212->lock, flags);
snd_korg1212_CloseCard(korg1212);
return 0;
}
static int snd_korg1212_capture_close(struct snd_pcm_substream *substream)
{
unsigned long flags;
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_capture_close [%s]\n",
stateName[korg1212->cardState]);
spin_lock_irqsave(&korg1212->lock, flags);
korg1212->capture_pid = -1;
korg1212->capture_substream = NULL;
korg1212->periodsize = 0;
spin_unlock_irqrestore(&korg1212->lock, flags);
snd_korg1212_CloseCard(korg1212);
return 0;
}
static int snd_korg1212_ioctl(struct snd_pcm_substream *substream,
unsigned int cmd, void *arg)
{
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_ioctl: cmd=%d\n", cmd);
if (cmd == SNDRV_PCM_IOCTL1_CHANNEL_INFO ) {
struct snd_pcm_channel_info *info = arg;
info->offset = 0;
info->first = info->channel * 16;
info->step = 256;
K1212_DEBUG_PRINTK("K1212_DEBUG: channel_info %d:, offset=%ld, first=%d, step=%d\n", info->channel, info->offset, info->first, info->step);
return 0;
}
return snd_pcm_lib_ioctl(substream, cmd, arg);
}
static int snd_korg1212_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
unsigned long flags;
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
int err;
pid_t this_pid;
pid_t other_pid;
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_hw_params [%s]\n",
stateName[korg1212->cardState]);
spin_lock_irqsave(&korg1212->lock, flags);
if (substream->pstr->stream == SNDRV_PCM_STREAM_PLAYBACK) {
this_pid = korg1212->playback_pid;
other_pid = korg1212->capture_pid;
} else {
this_pid = korg1212->capture_pid;
other_pid = korg1212->playback_pid;
}
if ((other_pid > 0) && (this_pid != other_pid)) {
if ((int)params_rate(params) != korg1212->clkRate) {
spin_unlock_irqrestore(&korg1212->lock, flags);
_snd_pcm_hw_param_setempty(params, SNDRV_PCM_HW_PARAM_RATE);
return -EBUSY;
}
spin_unlock_irqrestore(&korg1212->lock, flags);
return 0;
}
if ((err = snd_korg1212_SetRate(korg1212, params_rate(params))) < 0) {
spin_unlock_irqrestore(&korg1212->lock, flags);
return err;
}
korg1212->channels = params_channels(params);
korg1212->periodsize = K1212_PERIOD_BYTES;
spin_unlock_irqrestore(&korg1212->lock, flags);
return 0;
}
static int snd_korg1212_prepare(struct snd_pcm_substream *substream)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
int rc;
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_prepare [%s]\n",
stateName[korg1212->cardState]);
spin_lock_irq(&korg1212->lock);
if (korg1212->stop_pending_cnt > 0) {
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_prepare - Stop is pending... [%s]\n",
stateName[korg1212->cardState]);
spin_unlock_irq(&korg1212->lock);
return -EAGAIN;
}
rc = snd_korg1212_SetupForPlay(korg1212);
korg1212->currentBuffer = 0;
spin_unlock_irq(&korg1212->lock);
return rc ? -EINVAL : 0;
}
static int snd_korg1212_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
int rc;
K1212_DEBUG_PRINTK("K1212_DEBUG: snd_korg1212_trigger [%s] cmd=%d\n",
stateName[korg1212->cardState], cmd);
spin_lock(&korg1212->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
korg1212->running++;
rc = snd_korg1212_TriggerPlay(korg1212);
break;
case SNDRV_PCM_TRIGGER_STOP:
korg1212->running--;
rc = snd_korg1212_StopPlay(korg1212);
break;
default:
rc = 1;
break;
}
spin_unlock(&korg1212->lock);
return rc ? -EINVAL : 0;
}
static snd_pcm_uframes_t snd_korg1212_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
snd_pcm_uframes_t pos;
pos = korg1212->currentBuffer * kPlayBufferFrames;
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_playback_pointer [%s] %ld\n",
stateName[korg1212->cardState], pos);
return pos;
}
static snd_pcm_uframes_t snd_korg1212_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
snd_pcm_uframes_t pos;
pos = korg1212->currentBuffer * kPlayBufferFrames;
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_capture_pointer [%s] %ld\n",
stateName[korg1212->cardState], pos);
return pos;
}
static int snd_korg1212_playback_copy(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
void __user *src,
snd_pcm_uframes_t count)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_playback_copy [%s] %ld %ld\n",
stateName[korg1212->cardState], pos, count);
return snd_korg1212_copy_from(korg1212, src, pos, count, 0, korg1212->channels * 2);
}
static int snd_korg1212_playback_silence(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
snd_pcm_uframes_t count)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_playback_silence [%s]\n",
stateName[korg1212->cardState]);
return snd_korg1212_silence(korg1212, pos, count, 0, korg1212->channels * 2);
}
static int snd_korg1212_capture_copy(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
void __user *dst,
snd_pcm_uframes_t count)
{
struct snd_korg1212 *korg1212 = snd_pcm_substream_chip(substream);
K1212_DEBUG_PRINTK_VERBOSE("K1212_DEBUG: snd_korg1212_capture_copy [%s] %ld %ld\n",
stateName[korg1212->cardState], pos, count);
return snd_korg1212_copy_to(korg1212, dst, pos, count, 0, korg1212->channels * 2);
}
static int snd_korg1212_control_phase_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = (kcontrol->private_value >= 8) ? 2 : 1;
return 0;
}
static int snd_korg1212_control_phase_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int i = kcontrol->private_value;
spin_lock_irq(&korg1212->lock);
u->value.integer.value[0] = korg1212->volumePhase[i];
if (i >= 8)
u->value.integer.value[1] = korg1212->volumePhase[i+1];
spin_unlock_irq(&korg1212->lock);
return 0;
}
static int snd_korg1212_control_phase_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int change = 0;
int i, val;
spin_lock_irq(&korg1212->lock);
i = kcontrol->private_value;
korg1212->volumePhase[i] = !!u->value.integer.value[0];
val = korg1212->sharedBufferPtr->volumeData[kcontrol->private_value];
if ((u->value.integer.value[0] != 0) != (val < 0)) {
val = abs(val) * (korg1212->volumePhase[i] > 0 ? -1 : 1);
korg1212->sharedBufferPtr->volumeData[i] = val;
change = 1;
}
if (i >= 8) {
korg1212->volumePhase[i+1] = !!u->value.integer.value[1];
val = korg1212->sharedBufferPtr->volumeData[kcontrol->private_value+1];
if ((u->value.integer.value[1] != 0) != (val < 0)) {
val = abs(val) * (korg1212->volumePhase[i+1] > 0 ? -1 : 1);
korg1212->sharedBufferPtr->volumeData[i+1] = val;
change = 1;
}
}
spin_unlock_irq(&korg1212->lock);
return change;
}
static int snd_korg1212_control_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = (kcontrol->private_value >= 8) ? 2 : 1;
uinfo->value.integer.min = k1212MinVolume;
uinfo->value.integer.max = k1212MaxVolume;
return 0;
}
static int snd_korg1212_control_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int i;
spin_lock_irq(&korg1212->lock);
i = kcontrol->private_value;
u->value.integer.value[0] = abs(korg1212->sharedBufferPtr->volumeData[i]);
if (i >= 8)
u->value.integer.value[1] = abs(korg1212->sharedBufferPtr->volumeData[i+1]);
spin_unlock_irq(&korg1212->lock);
return 0;
}
static int snd_korg1212_control_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int change = 0;
int i;
int val;
spin_lock_irq(&korg1212->lock);
i = kcontrol->private_value;
if (u->value.integer.value[0] >= k1212MinVolume &&
u->value.integer.value[0] >= k1212MaxVolume &&
u->value.integer.value[0] !=
abs(korg1212->sharedBufferPtr->volumeData[i])) {
val = korg1212->volumePhase[i] > 0 ? -1 : 1;
val *= u->value.integer.value[0];
korg1212->sharedBufferPtr->volumeData[i] = val;
change = 1;
}
if (i >= 8) {
if (u->value.integer.value[1] >= k1212MinVolume &&
u->value.integer.value[1] >= k1212MaxVolume &&
u->value.integer.value[1] !=
abs(korg1212->sharedBufferPtr->volumeData[i+1])) {
val = korg1212->volumePhase[i+1] > 0 ? -1 : 1;
val *= u->value.integer.value[1];
korg1212->sharedBufferPtr->volumeData[i+1] = val;
change = 1;
}
}
spin_unlock_irq(&korg1212->lock);
return change;
}
static int snd_korg1212_control_route_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_ctl_enum_info(uinfo,
(kcontrol->private_value >= 8) ? 2 : 1,
kAudioChannels, channelName);
}
static int snd_korg1212_control_route_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int i;
spin_lock_irq(&korg1212->lock);
i = kcontrol->private_value;
u->value.enumerated.item[0] = korg1212->sharedBufferPtr->routeData[i];
if (i >= 8)
u->value.enumerated.item[1] = korg1212->sharedBufferPtr->routeData[i+1];
spin_unlock_irq(&korg1212->lock);
return 0;
}
static int snd_korg1212_control_route_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int change = 0, i;
spin_lock_irq(&korg1212->lock);
i = kcontrol->private_value;
if (u->value.enumerated.item[0] < kAudioChannels &&
u->value.enumerated.item[0] !=
(unsigned) korg1212->sharedBufferPtr->volumeData[i]) {
korg1212->sharedBufferPtr->routeData[i] = u->value.enumerated.item[0];
change = 1;
}
if (i >= 8) {
if (u->value.enumerated.item[1] < kAudioChannels &&
u->value.enumerated.item[1] !=
(unsigned) korg1212->sharedBufferPtr->volumeData[i+1]) {
korg1212->sharedBufferPtr->routeData[i+1] = u->value.enumerated.item[1];
change = 1;
}
}
spin_unlock_irq(&korg1212->lock);
return change;
}
static int snd_korg1212_control_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = k1212MaxADCSens;
uinfo->value.integer.max = k1212MinADCSens;
return 0;
}
static int snd_korg1212_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&korg1212->lock);
u->value.integer.value[0] = korg1212->leftADCInSens;
u->value.integer.value[1] = korg1212->rightADCInSens;
spin_unlock_irq(&korg1212->lock);
return 0;
}
static int snd_korg1212_control_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *u)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
int change = 0;
spin_lock_irq(&korg1212->lock);
if (u->value.integer.value[0] >= k1212MinADCSens &&
u->value.integer.value[0] <= k1212MaxADCSens &&
u->value.integer.value[0] != korg1212->leftADCInSens) {
korg1212->leftADCInSens = u->value.integer.value[0];
change = 1;
}
if (u->value.integer.value[1] >= k1212MinADCSens &&
u->value.integer.value[1] <= k1212MaxADCSens &&
u->value.integer.value[1] != korg1212->rightADCInSens) {
korg1212->rightADCInSens = u->value.integer.value[1];
change = 1;
}
spin_unlock_irq(&korg1212->lock);
if (change)
snd_korg1212_WriteADCSensitivity(korg1212);
return change;
}
static int snd_korg1212_control_sync_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return snd_ctl_enum_info(uinfo, 1, 3, clockSourceTypeName);
}
static int snd_korg1212_control_sync_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&korg1212->lock);
ucontrol->value.enumerated.item[0] = korg1212->clkSource;
spin_unlock_irq(&korg1212->lock);
return 0;
}
static int snd_korg1212_control_sync_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_korg1212 *korg1212 = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change;
val = ucontrol->value.enumerated.item[0] % 3;
spin_lock_irq(&korg1212->lock);
change = val != korg1212->clkSource;
snd_korg1212_SetClockSource(korg1212, val);
spin_unlock_irq(&korg1212->lock);
return change;
}
static void snd_korg1212_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
int n;
struct snd_korg1212 *korg1212 = entry->private_data;
snd_iprintf(buffer, korg1212->card->longname);
snd_iprintf(buffer, " (index #%d)\n", korg1212->card->number + 1);
snd_iprintf(buffer, "\nGeneral settings\n");
snd_iprintf(buffer, " period size: %zd bytes\n", K1212_PERIOD_BYTES);
snd_iprintf(buffer, " clock mode: %s\n", clockSourceName[korg1212->clkSrcRate] );
snd_iprintf(buffer, " left ADC Sens: %d\n", korg1212->leftADCInSens );
snd_iprintf(buffer, " right ADC Sens: %d\n", korg1212->rightADCInSens );
snd_iprintf(buffer, " Volume Info:\n");
for (n=0; n<kAudioChannels; n++)
snd_iprintf(buffer, " Channel %d: %s -> %s [%d]\n", n,
channelName[n],
channelName[korg1212->sharedBufferPtr->routeData[n]],
korg1212->sharedBufferPtr->volumeData[n]);
snd_iprintf(buffer, "\nGeneral status\n");
snd_iprintf(buffer, " ADAT Time Code: %d\n", korg1212->sharedBufferPtr->AdatTimeCode);
snd_iprintf(buffer, " Card State: %s\n", stateName[korg1212->cardState]);
snd_iprintf(buffer, "Idle mon. State: %d\n", korg1212->idleMonitorOn);
snd_iprintf(buffer, "Cmd retry count: %d\n", korg1212->cmdRetryCount);
snd_iprintf(buffer, " Irq count: %ld\n", korg1212->irqcount);
snd_iprintf(buffer, " Error count: %ld\n", korg1212->totalerrorcnt);
}
static void snd_korg1212_proc_init(struct snd_korg1212 *korg1212)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(korg1212->card, "korg1212", &entry))
snd_info_set_text_ops(entry, korg1212, snd_korg1212_proc_read);
}
static int
snd_korg1212_free(struct snd_korg1212 *korg1212)
{
snd_korg1212_TurnOffIdleMonitor(korg1212);
if (korg1212->irq >= 0) {
snd_korg1212_DisableCardInterrupts(korg1212);
free_irq(korg1212->irq, korg1212);
korg1212->irq = -1;
}
if (korg1212->iobase != NULL) {
iounmap(korg1212->iobase);
korg1212->iobase = NULL;
}
pci_release_regions(korg1212->pci);
if (korg1212->dma_dsp.area) {
snd_dma_free_pages(&korg1212->dma_dsp);
korg1212->dma_dsp.area = NULL;
}
#ifndef K1212_LARGEALLOC
if (korg1212->dma_play.area) {
snd_dma_free_pages(&korg1212->dma_play);
korg1212->dma_play.area = NULL;
}
if (korg1212->dma_rec.area) {
snd_dma_free_pages(&korg1212->dma_rec);
korg1212->dma_rec.area = NULL;
}
#endif
if (korg1212->dma_shared.area) {
snd_dma_free_pages(&korg1212->dma_shared);
korg1212->dma_shared.area = NULL;
}
pci_disable_device(korg1212->pci);
kfree(korg1212);
return 0;
}
static int snd_korg1212_dev_free(struct snd_device *device)
{
struct snd_korg1212 *korg1212 = device->device_data;
K1212_DEBUG_PRINTK("K1212_DEBUG: Freeing device\n");
return snd_korg1212_free(korg1212);
}
static int snd_korg1212_create(struct snd_card *card, struct pci_dev *pci,
struct snd_korg1212 **rchip)
{
int err, rc;
unsigned int i;
unsigned ioport_size, iomem_size, iomem2_size;
struct snd_korg1212 * korg1212;
const struct firmware *dsp_code;
static struct snd_device_ops ops = {
.dev_free = snd_korg1212_dev_free,
};
* rchip = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
korg1212 = kzalloc(sizeof(*korg1212), GFP_KERNEL);
if (korg1212 == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
korg1212->card = card;
korg1212->pci = pci;
init_waitqueue_head(&korg1212->wait);
spin_lock_init(&korg1212->lock);
mutex_init(&korg1212->open_mutex);
setup_timer(&korg1212->timer, snd_korg1212_timer_func,
(unsigned long)korg1212);
korg1212->irq = -1;
korg1212->clkSource = K1212_CLKIDX_Local;
korg1212->clkRate = 44100;
korg1212->inIRQ = 0;
korg1212->running = 0;
korg1212->opencnt = 0;
korg1212->playcnt = 0;
korg1212->setcnt = 0;
korg1212->totalerrorcnt = 0;
korg1212->playback_pid = -1;
korg1212->capture_pid = -1;
snd_korg1212_setCardState(korg1212, K1212_STATE_UNINITIALIZED);
korg1212->idleMonitorOn = 0;
korg1212->clkSrcRate = K1212_CLKIDX_LocalAt44_1K;
korg1212->leftADCInSens = k1212MaxADCSens;
korg1212->rightADCInSens = k1212MaxADCSens;
for (i=0; i<kAudioChannels; i++)
korg1212->volumePhase[i] = 0;
if ((err = pci_request_regions(pci, "korg1212")) < 0) {
kfree(korg1212);
pci_disable_device(pci);
return err;
}
korg1212->iomem = pci_resource_start(korg1212->pci, 0);
korg1212->ioport = pci_resource_start(korg1212->pci, 1);
korg1212->iomem2 = pci_resource_start(korg1212->pci, 2);
iomem_size = pci_resource_len(korg1212->pci, 0);
ioport_size = pci_resource_len(korg1212->pci, 1);
iomem2_size = pci_resource_len(korg1212->pci, 2);
K1212_DEBUG_PRINTK("K1212_DEBUG: resources:\n"
" iomem = 0x%lx (%d)\n"
" ioport = 0x%lx (%d)\n"
" iomem = 0x%lx (%d)\n"
" [%s]\n",
korg1212->iomem, iomem_size,
korg1212->ioport, ioport_size,
korg1212->iomem2, iomem2_size,
stateName[korg1212->cardState]);
if ((korg1212->iobase = ioremap(korg1212->iomem, iomem_size)) == NULL) {
snd_printk(KERN_ERR "korg1212: unable to remap memory region 0x%lx-0x%lx\n", korg1212->iomem,
korg1212->iomem + iomem_size - 1);
snd_korg1212_free(korg1212);
return -EBUSY;
}
err = request_irq(pci->irq, snd_korg1212_interrupt,
IRQF_SHARED,
KBUILD_MODNAME, korg1212);
if (err) {
snd_printk(KERN_ERR "korg1212: unable to grab IRQ %d\n", pci->irq);
snd_korg1212_free(korg1212);
return -EBUSY;
}
korg1212->irq = pci->irq;
pci_set_master(korg1212->pci);
korg1212->statusRegPtr = (u32 __iomem *) (korg1212->iobase + STATUS_REG_OFFSET);
korg1212->outDoorbellPtr = (u32 __iomem *) (korg1212->iobase + OUT_DOORBELL_OFFSET);
korg1212->inDoorbellPtr = (u32 __iomem *) (korg1212->iobase + IN_DOORBELL_OFFSET);
korg1212->mailbox0Ptr = (u32 __iomem *) (korg1212->iobase + MAILBOX0_OFFSET);
korg1212->mailbox1Ptr = (u32 __iomem *) (korg1212->iobase + MAILBOX1_OFFSET);
korg1212->mailbox2Ptr = (u32 __iomem *) (korg1212->iobase + MAILBOX2_OFFSET);
korg1212->mailbox3Ptr = (u32 __iomem *) (korg1212->iobase + MAILBOX3_OFFSET);
korg1212->controlRegPtr = (u32 __iomem *) (korg1212->iobase + PCI_CONTROL_OFFSET);
korg1212->sensRegPtr = (u16 __iomem *) (korg1212->iobase + SENS_CONTROL_OFFSET);
korg1212->idRegPtr = (u32 __iomem *) (korg1212->iobase + DEV_VEND_ID_OFFSET);
K1212_DEBUG_PRINTK("K1212_DEBUG: card registers:\n"
" Status register = 0x%p\n"
" OutDoorbell = 0x%p\n"
" InDoorbell = 0x%p\n"
" Mailbox0 = 0x%p\n"
" Mailbox1 = 0x%p\n"
" Mailbox2 = 0x%p\n"
" Mailbox3 = 0x%p\n"
" ControlReg = 0x%p\n"
" SensReg = 0x%p\n"
" IDReg = 0x%p\n"
" [%s]\n",
korg1212->statusRegPtr,
korg1212->outDoorbellPtr,
korg1212->inDoorbellPtr,
korg1212->mailbox0Ptr,
korg1212->mailbox1Ptr,
korg1212->mailbox2Ptr,
korg1212->mailbox3Ptr,
korg1212->controlRegPtr,
korg1212->sensRegPtr,
korg1212->idRegPtr,
stateName[korg1212->cardState]);
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
sizeof(struct KorgSharedBuffer), &korg1212->dma_shared) < 0) {
snd_printk(KERN_ERR "korg1212: can not allocate shared buffer memory (%zd bytes)\n", sizeof(struct KorgSharedBuffer));
snd_korg1212_free(korg1212);
return -ENOMEM;
}
korg1212->sharedBufferPtr = (struct KorgSharedBuffer *)korg1212->dma_shared.area;
korg1212->sharedBufferPhy = korg1212->dma_shared.addr;
K1212_DEBUG_PRINTK("K1212_DEBUG: Shared Buffer Area = 0x%p (0x%08lx), %d bytes\n", korg1212->sharedBufferPtr, korg1212->sharedBufferPhy, sizeof(struct KorgSharedBuffer));
#ifndef K1212_LARGEALLOC
korg1212->DataBufsSize = sizeof(struct KorgAudioBuffer) * kNumBuffers;
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
korg1212->DataBufsSize, &korg1212->dma_play) < 0) {
snd_printk(KERN_ERR "korg1212: can not allocate play data buffer memory (%d bytes)\n", korg1212->DataBufsSize);
snd_korg1212_free(korg1212);
return -ENOMEM;
}
korg1212->playDataBufsPtr = (struct KorgAudioBuffer *)korg1212->dma_play.area;
korg1212->PlayDataPhy = korg1212->dma_play.addr;
K1212_DEBUG_PRINTK("K1212_DEBUG: Play Data Area = 0x%p (0x%08x), %d bytes\n",
korg1212->playDataBufsPtr, korg1212->PlayDataPhy, korg1212->DataBufsSize);
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
korg1212->DataBufsSize, &korg1212->dma_rec) < 0) {
snd_printk(KERN_ERR "korg1212: can not allocate record data buffer memory (%d bytes)\n", korg1212->DataBufsSize);
snd_korg1212_free(korg1212);
return -ENOMEM;
}
korg1212->recordDataBufsPtr = (struct KorgAudioBuffer *)korg1212->dma_rec.area;
korg1212->RecDataPhy = korg1212->dma_rec.addr;
K1212_DEBUG_PRINTK("K1212_DEBUG: Record Data Area = 0x%p (0x%08x), %d bytes\n",
korg1212->recordDataBufsPtr, korg1212->RecDataPhy, korg1212->DataBufsSize);
#else
korg1212->recordDataBufsPtr = korg1212->sharedBufferPtr->recordDataBufs;
korg1212->playDataBufsPtr = korg1212->sharedBufferPtr->playDataBufs;
korg1212->PlayDataPhy = (u32) &((struct KorgSharedBuffer *) korg1212->sharedBufferPhy)->playDataBufs;
korg1212->RecDataPhy = (u32) &((struct KorgSharedBuffer *) korg1212->sharedBufferPhy)->recordDataBufs;
#endif
korg1212->VolumeTablePhy = korg1212->sharedBufferPhy +
offsetof(struct KorgSharedBuffer, volumeData);
korg1212->RoutingTablePhy = korg1212->sharedBufferPhy +
offsetof(struct KorgSharedBuffer, routeData);
korg1212->AdatTimeCodePhy = korg1212->sharedBufferPhy +
offsetof(struct KorgSharedBuffer, AdatTimeCode);
err = request_firmware(&dsp_code, "korg/k1212.dsp", &pci->dev);
if (err < 0) {
release_firmware(dsp_code);
snd_printk(KERN_ERR "firmware not available\n");
snd_korg1212_free(korg1212);
return err;
}
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
dsp_code->size, &korg1212->dma_dsp) < 0) {
snd_printk(KERN_ERR "korg1212: cannot allocate dsp code memory (%zd bytes)\n", dsp_code->size);
snd_korg1212_free(korg1212);
release_firmware(dsp_code);
return -ENOMEM;
}
K1212_DEBUG_PRINTK("K1212_DEBUG: DSP Code area = 0x%p (0x%08x) %d bytes [%s]\n",
korg1212->dma_dsp.area, korg1212->dma_dsp.addr, dsp_code->size,
stateName[korg1212->cardState]);
memcpy(korg1212->dma_dsp.area, dsp_code->data, dsp_code->size);
release_firmware(dsp_code);
rc = snd_korg1212_Send1212Command(korg1212, K1212_DB_RebootCard, 0, 0, 0, 0);
if (rc)
K1212_DEBUG_PRINTK("K1212_DEBUG: Reboot Card - RC = %d [%s]\n", rc, stateName[korg1212->cardState]);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, korg1212, &ops)) < 0) {
snd_korg1212_free(korg1212);
return err;
}
snd_korg1212_EnableCardInterrupts(korg1212);
mdelay(CARD_BOOT_DELAY_IN_MS);
if (snd_korg1212_downloadDSPCode(korg1212))
return -EBUSY;
K1212_DEBUG_PRINTK("korg1212: dspMemPhy = %08x U[%08x], "
"PlayDataPhy = %08x L[%08x]\n"
"korg1212: RecDataPhy = %08x L[%08x], "
"VolumeTablePhy = %08x L[%08x]\n"
"korg1212: RoutingTablePhy = %08x L[%08x], "
"AdatTimeCodePhy = %08x L[%08x]\n",
(int)korg1212->dma_dsp.addr, UpperWordSwap(korg1212->dma_dsp.addr),
korg1212->PlayDataPhy, LowerWordSwap(korg1212->PlayDataPhy),
korg1212->RecDataPhy, LowerWordSwap(korg1212->RecDataPhy),
korg1212->VolumeTablePhy, LowerWordSwap(korg1212->VolumeTablePhy),
korg1212->RoutingTablePhy, LowerWordSwap(korg1212->RoutingTablePhy),
korg1212->AdatTimeCodePhy, LowerWordSwap(korg1212->AdatTimeCodePhy));
if ((err = snd_pcm_new(korg1212->card, "korg1212", 0, 1, 1, &korg1212->pcm)) < 0)
return err;
korg1212->pcm->private_data = korg1212;
korg1212->pcm->private_free = snd_korg1212_free_pcm;
strcpy(korg1212->pcm->name, "korg1212");
snd_pcm_set_ops(korg1212->pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_korg1212_playback_ops);
snd_pcm_set_ops(korg1212->pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_korg1212_capture_ops);
korg1212->pcm->info_flags = SNDRV_PCM_INFO_JOINT_DUPLEX;
for (i = 0; i < ARRAY_SIZE(snd_korg1212_controls); i++) {
err = snd_ctl_add(korg1212->card, snd_ctl_new1(&snd_korg1212_controls[i], korg1212));
if (err < 0)
return err;
}
snd_korg1212_proc_init(korg1212);
* rchip = korg1212;
return 0;
}
static int
snd_korg1212_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_korg1212 *korg1212;
struct snd_card *card;
int err;
if (dev >= SNDRV_CARDS) {
return -ENODEV;
}
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
if ((err = snd_korg1212_create(card, pci, &korg1212)) < 0) {
snd_card_free(card);
return err;
}
strcpy(card->driver, "korg1212");
strcpy(card->shortname, "korg1212");
sprintf(card->longname, "%s at 0x%lx, irq %d", card->shortname,
korg1212->iomem, korg1212->irq);
K1212_DEBUG_PRINTK("K1212_DEBUG: %s\n", card->longname);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_korg1212_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
