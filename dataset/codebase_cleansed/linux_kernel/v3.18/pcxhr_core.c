static int pcxhr_check_reg_bit(struct pcxhr_mgr *mgr, unsigned int reg,
unsigned char mask, unsigned char bit, int time,
unsigned char* read)
{
int i = 0;
unsigned long end_time = jiffies + (time * HZ + 999) / 1000;
do {
*read = PCXHR_INPB(mgr, reg);
if ((*read & mask) == bit) {
if (i > 100)
dev_dbg(&mgr->pci->dev,
"ATTENTION! check_reg(%x) loopcount=%d\n",
reg, i);
return 0;
}
i++;
} while (time_after_eq(end_time, jiffies));
dev_err(&mgr->pci->dev,
"pcxhr_check_reg_bit: timeout, reg=%x, mask=0x%x, val=%x\n",
reg, mask, *read);
return -EIO;
}
static int pcxhr_send_it_dsp(struct pcxhr_mgr *mgr,
unsigned int itdsp, int atomic)
{
int err;
unsigned char reg;
if (itdsp & PCXHR_MASK_IT_MANAGE_HF5) {
PCXHR_OUTPL(mgr, PCXHR_PLX_MBOX0,
PCXHR_INPL(mgr, PCXHR_PLX_MBOX0) &
~PCXHR_MBOX0_HF5);
}
if ((itdsp & PCXHR_MASK_IT_NO_HF0_HF1) == 0) {
reg = (PCXHR_ICR_HI08_RREQ |
PCXHR_ICR_HI08_TREQ |
PCXHR_ICR_HI08_HDRQ);
if (itdsp & PCXHR_MASK_IT_HF0)
reg |= PCXHR_ICR_HI08_HF0;
if (itdsp & PCXHR_MASK_IT_HF1)
reg |= PCXHR_ICR_HI08_HF1;
PCXHR_OUTPB(mgr, PCXHR_DSP_ICR, reg);
}
reg = (unsigned char)(((itdsp & PCXHR_MASK_EXTRA_INFO) >> 1) |
PCXHR_CVR_HI08_HC);
PCXHR_OUTPB(mgr, PCXHR_DSP_CVR, reg);
if (itdsp & PCXHR_MASK_IT_WAIT) {
if (atomic)
mdelay(PCXHR_WAIT_IT);
else
msleep(PCXHR_WAIT_IT);
}
if (itdsp & PCXHR_MASK_IT_WAIT_EXTRA) {
if (atomic)
mdelay(PCXHR_WAIT_IT_EXTRA);
else
msleep(PCXHR_WAIT_IT);
}
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_CVR, PCXHR_CVR_HI08_HC, 0,
PCXHR_TIMEOUT_DSP, &reg);
if (err) {
dev_err(&mgr->pci->dev, "pcxhr_send_it_dsp : TIMEOUT CVR\n");
return err;
}
if (itdsp & PCXHR_MASK_IT_MANAGE_HF5) {
err = pcxhr_check_reg_bit(mgr, PCXHR_PLX_MBOX0,
PCXHR_MBOX0_HF5,
PCXHR_MBOX0_HF5,
PCXHR_TIMEOUT_DSP,
&reg);
if (err) {
dev_err(&mgr->pci->dev,
"pcxhr_send_it_dsp : TIMEOUT HF5\n");
return err;
}
}
return 0;
}
void pcxhr_reset_xilinx_com(struct pcxhr_mgr *mgr)
{
PCXHR_OUTPL(mgr, PCXHR_PLX_CHIPSC,
PCXHR_CHIPSC_INIT_VALUE & ~PCXHR_CHIPSC_RESET_XILINX);
}
static void pcxhr_enable_irq(struct pcxhr_mgr *mgr, int enable)
{
unsigned int reg = PCXHR_INPL(mgr, PCXHR_PLX_IRQCS);
if (enable)
reg |= (PCXHR_IRQCS_ENABLE_PCIIRQ | PCXHR_IRQCS_ENABLE_PCIDB);
else
reg &= ~(PCXHR_IRQCS_ENABLE_PCIIRQ | PCXHR_IRQCS_ENABLE_PCIDB);
PCXHR_OUTPL(mgr, PCXHR_PLX_IRQCS, reg);
}
void pcxhr_reset_dsp(struct pcxhr_mgr *mgr)
{
pcxhr_enable_irq(mgr, 0);
PCXHR_OUTPB(mgr, PCXHR_DSP_RESET, 0);
msleep( PCXHR_WAIT_DEFAULT );
PCXHR_OUTPB(mgr, PCXHR_DSP_RESET, 3);
msleep( PCXHR_WAIT_DEFAULT );
PCXHR_OUTPL(mgr, PCXHR_PLX_MBOX0, 0);
}
void pcxhr_enable_dsp(struct pcxhr_mgr *mgr)
{
pcxhr_enable_irq(mgr, 1);
}
int pcxhr_load_xilinx_binary(struct pcxhr_mgr *mgr,
const struct firmware *xilinx, int second)
{
unsigned int i;
unsigned int chipsc;
unsigned char data;
unsigned char mask;
const unsigned char *image;
chipsc = PCXHR_INPL(mgr, PCXHR_PLX_CHIPSC);
if(second) {
if ((chipsc & PCXHR_CHIPSC_GPI_USERI) == 0) {
dev_err(&mgr->pci->dev, "error loading first xilinx\n");
return -EINVAL;
}
chipsc |= PCXHR_CHIPSC_RESET_XILINX;
PCXHR_OUTPL(mgr, PCXHR_PLX_CHIPSC, chipsc);
msleep( PCXHR_WAIT_DEFAULT );
}
image = xilinx->data;
for (i = 0; i < xilinx->size; i++, image++) {
data = *image;
mask = 0x80;
while (mask) {
chipsc &= ~(PCXHR_CHIPSC_DATA_CLK |
PCXHR_CHIPSC_DATA_IN);
if (data & mask)
chipsc |= PCXHR_CHIPSC_DATA_IN;
PCXHR_OUTPL(mgr, PCXHR_PLX_CHIPSC, chipsc);
chipsc |= PCXHR_CHIPSC_DATA_CLK;
PCXHR_OUTPL(mgr, PCXHR_PLX_CHIPSC, chipsc);
mask >>= 1;
}
cond_resched();
}
chipsc &= ~(PCXHR_CHIPSC_DATA_CLK | PCXHR_CHIPSC_DATA_IN);
PCXHR_OUTPL(mgr, PCXHR_PLX_CHIPSC, chipsc);
msleep( PCXHR_WAIT_DEFAULT );
return 0;
}
static int pcxhr_download_dsp(struct pcxhr_mgr *mgr, const struct firmware *dsp)
{
int err;
unsigned int i;
unsigned int len;
const unsigned char *data;
unsigned char dummy;
if (dsp->size <= 0)
return -EINVAL;
if (dsp->size % 3)
return -EINVAL;
if (snd_BUG_ON(!dsp->data))
return -EINVAL;
for (i = 0; i < dsp->size; i += 3) {
data = dsp->data + i;
if (i == 0) {
len = (unsigned int)((data[0]<<16) +
(data[1]<<8) +
data[2]);
if (len && (dsp->size != (len + 2) * 3))
return -EINVAL;
}
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR,
PCXHR_ISR_HI08_TRDY,
PCXHR_ISR_HI08_TRDY,
PCXHR_TIMEOUT_DSP, &dummy);
if (err) {
dev_err(&mgr->pci->dev,
"dsp loading error at position %d\n", i);
return err;
}
PCXHR_OUTPB(mgr, PCXHR_DSP_TXH, data[0]);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXM, data[1]);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXL, data[2]);
cond_resched();
}
msleep(PCXHR_WAIT_DEFAULT);
return 0;
}
int pcxhr_load_eeprom_binary(struct pcxhr_mgr *mgr,
const struct firmware *eeprom)
{
int err;
unsigned char reg;
reg = PCXHR_ICR_HI08_RREQ | PCXHR_ICR_HI08_TREQ | PCXHR_ICR_HI08_HDRQ;
if (PCXHR_INPL(mgr, PCXHR_PLX_MBOX0) & PCXHR_MBOX0_BOOT_HERE) {
PCXHR_OUTPB(mgr, PCXHR_DSP_ICR, reg | PCXHR_ICR_HI08_INIT);
msleep(PCXHR_WAIT_DEFAULT);
PCXHR_OUTPB(mgr, PCXHR_DSP_ICR, reg);
msleep(PCXHR_WAIT_DEFAULT);
dev_dbg(&mgr->pci->dev, "no need to load eeprom boot\n");
return 0;
}
PCXHR_OUTPB(mgr, PCXHR_DSP_ICR, reg);
err = pcxhr_download_dsp(mgr, eeprom);
if (err)
return err;
return pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR, PCXHR_ISR_HI08_CHK,
PCXHR_ISR_HI08_CHK, PCXHR_TIMEOUT_DSP, &reg);
}
int pcxhr_load_boot_binary(struct pcxhr_mgr *mgr, const struct firmware *boot)
{
int err;
unsigned int physaddr = mgr->hostport.addr;
unsigned char dummy;
if (snd_BUG_ON(physaddr & 0xff))
return -EINVAL;
PCXHR_OUTPL(mgr, PCXHR_PLX_MBOX1, (physaddr >> 8));
err = pcxhr_send_it_dsp(mgr, PCXHR_IT_DOWNLOAD_BOOT, 0);
if (err)
return err;
PCXHR_OUTPL(mgr, PCXHR_PLX_MBOX0,
PCXHR_INPL(mgr, PCXHR_PLX_MBOX0) & ~PCXHR_MBOX0_HF5);
err = pcxhr_download_dsp(mgr, boot);
if (err)
return err;
return pcxhr_check_reg_bit(mgr, PCXHR_PLX_MBOX0, PCXHR_MBOX0_HF5,
PCXHR_MBOX0_HF5, PCXHR_TIMEOUT_DSP, &dummy);
}
int pcxhr_load_dsp_binary(struct pcxhr_mgr *mgr, const struct firmware *dsp)
{
int err;
unsigned char dummy;
err = pcxhr_send_it_dsp(mgr, PCXHR_IT_RESET_BOARD_FUNC, 0);
if (err)
return err;
err = pcxhr_send_it_dsp(mgr, PCXHR_IT_DOWNLOAD_DSP, 0);
if (err)
return err;
err = pcxhr_download_dsp(mgr, dsp);
if (err)
return err;
return pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR,
PCXHR_ISR_HI08_CHK,
PCXHR_ISR_HI08_CHK,
PCXHR_TIMEOUT_DSP, &dummy);
}
static int pcxhr_read_rmh_status(struct pcxhr_mgr *mgr, struct pcxhr_rmh *rmh)
{
int err;
int i;
u32 data;
u32 size_mask;
unsigned char reg;
int max_stat_len;
if (rmh->stat_len < PCXHR_SIZE_MAX_STATUS)
max_stat_len = PCXHR_SIZE_MAX_STATUS;
else max_stat_len = rmh->stat_len;
for (i = 0; i < rmh->stat_len; i++) {
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR,
PCXHR_ISR_HI08_RXDF,
PCXHR_ISR_HI08_RXDF,
PCXHR_TIMEOUT_DSP, &reg);
if (err) {
dev_err(&mgr->pci->dev,
"ERROR RMH stat: ISR:RXDF=1 (ISR = %x; i=%d )\n",
reg, i);
return err;
}
data = PCXHR_INPB(mgr, PCXHR_DSP_TXH) << 16;
data |= PCXHR_INPB(mgr, PCXHR_DSP_TXM) << 8;
data |= PCXHR_INPB(mgr, PCXHR_DSP_TXL);
if (!i) {
if (rmh->dsp_stat != RMH_SSIZE_FIXED) {
if (rmh->dsp_stat == RMH_SSIZE_ARG) {
rmh->stat_len = (data & 0x0000ff) + 1;
data &= 0xffff00;
} else {
rmh->stat_len = 1;
size_mask = data;
while (size_mask) {
if (size_mask & 1)
rmh->stat_len++;
size_mask >>= 1;
}
}
}
}
#ifdef CONFIG_SND_DEBUG_VERBOSE
if (rmh->cmd_idx < CMD_LAST_INDEX)
dev_dbg(&mgr->pci->dev, " stat[%d]=%x\n", i, data);
#endif
if (i < max_stat_len)
rmh->stat[i] = data;
}
if (rmh->stat_len > max_stat_len) {
dev_dbg(&mgr->pci->dev, "PCXHR : rmh->stat_len=%x too big\n",
rmh->stat_len);
rmh->stat_len = max_stat_len;
}
return 0;
}
static int pcxhr_send_msg_nolock(struct pcxhr_mgr *mgr, struct pcxhr_rmh *rmh)
{
int err;
int i;
u32 data;
unsigned char reg;
if (snd_BUG_ON(rmh->cmd_len >= PCXHR_SIZE_MAX_CMD))
return -EINVAL;
err = pcxhr_send_it_dsp(mgr, PCXHR_IT_MESSAGE, 1);
if (err) {
dev_err(&mgr->pci->dev,
"pcxhr_send_message : ED_DSP_CRASHED\n");
return err;
}
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR, PCXHR_ISR_HI08_CHK,
PCXHR_ISR_HI08_CHK, PCXHR_TIMEOUT_DSP, &reg);
if (err)
return err;
err = pcxhr_send_it_dsp(mgr, PCXHR_IT_RESET_CHK, 1);
if (err)
return err;
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR, PCXHR_ISR_HI08_CHK, 0,
PCXHR_TIMEOUT_DSP, &reg);
if (err)
return err;
data = rmh->cmd[0];
if (rmh->cmd_len > 1)
data |= 0x008000;
else
data &= 0xff7fff;
#ifdef CONFIG_SND_DEBUG_VERBOSE
if (rmh->cmd_idx < CMD_LAST_INDEX)
dev_dbg(&mgr->pci->dev, "MSG cmd[0]=%x (%s)\n",
data, cmd_names[rmh->cmd_idx]);
#endif
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR, PCXHR_ISR_HI08_TRDY,
PCXHR_ISR_HI08_TRDY, PCXHR_TIMEOUT_DSP, &reg);
if (err)
return err;
PCXHR_OUTPB(mgr, PCXHR_DSP_TXH, (data>>16)&0xFF);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXM, (data>>8)&0xFF);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXL, (data&0xFF));
if (rmh->cmd_len > 1) {
data = rmh->cmd_len - 1;
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR,
PCXHR_ISR_HI08_TRDY,
PCXHR_ISR_HI08_TRDY,
PCXHR_TIMEOUT_DSP, &reg);
if (err)
return err;
PCXHR_OUTPB(mgr, PCXHR_DSP_TXH, (data>>16)&0xFF);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXM, (data>>8)&0xFF);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXL, (data&0xFF));
for (i=1; i < rmh->cmd_len; i++) {
data = rmh->cmd[i];
#ifdef CONFIG_SND_DEBUG_VERBOSE
if (rmh->cmd_idx < CMD_LAST_INDEX)
dev_dbg(&mgr->pci->dev,
" cmd[%d]=%x\n", i, data);
#endif
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR,
PCXHR_ISR_HI08_TRDY,
PCXHR_ISR_HI08_TRDY,
PCXHR_TIMEOUT_DSP, &reg);
if (err)
return err;
PCXHR_OUTPB(mgr, PCXHR_DSP_TXH, (data>>16)&0xFF);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXM, (data>>8)&0xFF);
PCXHR_OUTPB(mgr, PCXHR_DSP_TXL, (data&0xFF));
}
}
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR, PCXHR_ISR_HI08_CHK,
PCXHR_ISR_HI08_CHK, PCXHR_TIMEOUT_DSP, &reg);
if (err)
return err;
if (reg & PCXHR_ISR_HI08_ERR) {
err = pcxhr_check_reg_bit(mgr, PCXHR_DSP_ISR,
PCXHR_ISR_HI08_RXDF,
PCXHR_ISR_HI08_RXDF,
PCXHR_TIMEOUT_DSP, &reg);
if (err) {
dev_err(&mgr->pci->dev,
"ERROR RMH: ISR:RXDF=1 (ISR = %x)\n", reg);
return err;
}
data = PCXHR_INPB(mgr, PCXHR_DSP_TXH) << 16;
data |= PCXHR_INPB(mgr, PCXHR_DSP_TXM) << 8;
data |= PCXHR_INPB(mgr, PCXHR_DSP_TXL);
dev_err(&mgr->pci->dev, "ERROR RMH(%d): 0x%x\n",
rmh->cmd_idx, data);
err = -EINVAL;
} else {
err = pcxhr_read_rmh_status(mgr, rmh);
}
if (pcxhr_send_it_dsp(mgr, PCXHR_IT_RESET_SEMAPHORE, 1) < 0)
return -EIO;
return err;
}
void pcxhr_init_rmh(struct pcxhr_rmh *rmh, int cmd)
{
if (snd_BUG_ON(cmd >= CMD_LAST_INDEX))
return;
rmh->cmd[0] = pcxhr_dsp_cmds[cmd].opcode;
rmh->cmd_len = 1;
rmh->stat_len = pcxhr_dsp_cmds[cmd].st_length;
rmh->dsp_stat = pcxhr_dsp_cmds[cmd].st_type;
rmh->cmd_idx = cmd;
}
void pcxhr_set_pipe_cmd_params(struct pcxhr_rmh *rmh, int capture,
unsigned int param1, unsigned int param2,
unsigned int param3)
{
snd_BUG_ON(param1 > MASK_FIRST_FIELD);
if (capture)
rmh->cmd[0] |= 0x800;
if (param1)
rmh->cmd[0] |= (param1 << FIELD_SIZE);
if (param2) {
snd_BUG_ON(param2 > MASK_FIRST_FIELD);
rmh->cmd[0] |= param2;
}
if(param3) {
snd_BUG_ON(param3 > MASK_DSP_WORD);
rmh->cmd[1] = param3;
rmh->cmd_len = 2;
}
}
int pcxhr_send_msg(struct pcxhr_mgr *mgr, struct pcxhr_rmh *rmh)
{
int err;
mutex_lock(&mgr->msg_lock);
err = pcxhr_send_msg_nolock(mgr, rmh);
mutex_unlock(&mgr->msg_lock);
return err;
}
static inline int pcxhr_pipes_running(struct pcxhr_mgr *mgr)
{
int start_mask = PCXHR_INPL(mgr, PCXHR_PLX_MBOX2);
start_mask &= 0xffffff;
dev_dbg(&mgr->pci->dev, "CMD_PIPE_STATE MBOX2=0x%06x\n", start_mask);
return start_mask;
}
static int pcxhr_prepair_pipe_start(struct pcxhr_mgr *mgr,
int audio_mask, int *retry)
{
struct pcxhr_rmh rmh;
int err;
int audio = 0;
*retry = 0;
while (audio_mask) {
if (audio_mask & 1) {
pcxhr_init_rmh(&rmh, CMD_CAN_START_PIPE);
if (audio < PCXHR_PIPE_STATE_CAPTURE_OFFSET) {
pcxhr_set_pipe_cmd_params(&rmh, 0, audio, 0, 0);
} else {
pcxhr_set_pipe_cmd_params(&rmh, 1, audio -
PCXHR_PIPE_STATE_CAPTURE_OFFSET,
0, 0);
}
err = pcxhr_send_msg(mgr, &rmh);
if (err) {
dev_err(&mgr->pci->dev,
"error pipe start "
"(CMD_CAN_START_PIPE) err=%x!\n",
err);
return err;
}
if (rmh.stat[0] == 0)
*retry |= (1<<audio);
}
audio_mask>>=1;
audio++;
}
return 0;
}
static int pcxhr_stop_pipes(struct pcxhr_mgr *mgr, int audio_mask)
{
struct pcxhr_rmh rmh;
int err;
int audio = 0;
while (audio_mask) {
if (audio_mask & 1) {
pcxhr_init_rmh(&rmh, CMD_STOP_PIPE);
if (audio < PCXHR_PIPE_STATE_CAPTURE_OFFSET) {
pcxhr_set_pipe_cmd_params(&rmh, 0, audio, 0, 0);
} else {
pcxhr_set_pipe_cmd_params(&rmh, 1, audio -
PCXHR_PIPE_STATE_CAPTURE_OFFSET,
0, 0);
}
err = pcxhr_send_msg(mgr, &rmh);
if (err) {
dev_err(&mgr->pci->dev,
"error pipe stop "
"(CMD_STOP_PIPE) err=%x!\n", err);
return err;
}
}
audio_mask>>=1;
audio++;
}
return 0;
}
static int pcxhr_toggle_pipes(struct pcxhr_mgr *mgr, int audio_mask)
{
struct pcxhr_rmh rmh;
int err;
int audio = 0;
while (audio_mask) {
if (audio_mask & 1) {
pcxhr_init_rmh(&rmh, CMD_CONF_PIPE);
if (audio < PCXHR_PIPE_STATE_CAPTURE_OFFSET)
pcxhr_set_pipe_cmd_params(&rmh, 0, 0, 0,
1 << audio);
else
pcxhr_set_pipe_cmd_params(&rmh, 1, 0, 0,
1 << (audio - PCXHR_PIPE_STATE_CAPTURE_OFFSET));
err = pcxhr_send_msg(mgr, &rmh);
if (err) {
dev_err(&mgr->pci->dev,
"error pipe start "
"(CMD_CONF_PIPE) err=%x!\n", err);
return err;
}
}
audio_mask>>=1;
audio++;
}
pcxhr_init_rmh(&rmh, CMD_SEND_IRQA);
err = pcxhr_send_msg(mgr, &rmh);
if (err) {
dev_err(&mgr->pci->dev,
"error pipe start (CMD_SEND_IRQA) err=%x!\n",
err);
return err;
}
return 0;
}
int pcxhr_set_pipe_state(struct pcxhr_mgr *mgr, int playback_mask,
int capture_mask, int start)
{
int state, i, err;
int audio_mask;
#ifdef CONFIG_SND_DEBUG_VERBOSE
struct timeval my_tv1, my_tv2;
do_gettimeofday(&my_tv1);
#endif
audio_mask = (playback_mask |
(capture_mask << PCXHR_PIPE_STATE_CAPTURE_OFFSET));
state = pcxhr_pipes_running(mgr);
dev_dbg(&mgr->pci->dev,
"pcxhr_set_pipe_state %s (mask %x current %x)\n",
start ? "START" : "STOP", audio_mask, state);
if (start) {
audio_mask &= ~state;
state = audio_mask;
for (i = 0; i < MAX_WAIT_FOR_DSP; i++) {
err = pcxhr_prepair_pipe_start(mgr, state, &state);
if (err)
return err;
if (state == 0)
break;
mdelay(1);
}
} else {
audio_mask &= state;
}
if (audio_mask == 0)
return 0;
err = pcxhr_toggle_pipes(mgr, audio_mask);
if (err)
return err;
i = 0;
while (1) {
state = pcxhr_pipes_running(mgr);
if ((state & audio_mask) == (start ? audio_mask : 0))
break;
if (++i >= MAX_WAIT_FOR_DSP * 100) {
dev_err(&mgr->pci->dev, "error pipe start/stop\n");
return -EBUSY;
}
udelay(10);
}
if (!start) {
err = pcxhr_stop_pipes(mgr, audio_mask);
if (err)
return err;
}
#ifdef CONFIG_SND_DEBUG_VERBOSE
do_gettimeofday(&my_tv2);
dev_dbg(&mgr->pci->dev, "***SET PIPE STATE*** TIME = %ld (err = %x)\n",
(long)(my_tv2.tv_usec - my_tv1.tv_usec), err);
#endif
return 0;
}
int pcxhr_write_io_num_reg_cont(struct pcxhr_mgr *mgr, unsigned int mask,
unsigned int value, int *changed)
{
struct pcxhr_rmh rmh;
int err;
mutex_lock(&mgr->msg_lock);
if ((mgr->io_num_reg_cont & mask) == value) {
dev_dbg(&mgr->pci->dev,
"IO_NUM_REG_CONT mask %x already is set to %x\n",
mask, value);
if (changed)
*changed = 0;
mutex_unlock(&mgr->msg_lock);
return 0;
}
pcxhr_init_rmh(&rmh, CMD_ACCESS_IO_WRITE);
rmh.cmd[0] |= IO_NUM_REG_CONT;
rmh.cmd[1] = mask;
rmh.cmd[2] = value;
rmh.cmd_len = 3;
err = pcxhr_send_msg_nolock(mgr, &rmh);
if (err == 0) {
mgr->io_num_reg_cont &= ~mask;
mgr->io_num_reg_cont |= value;
if (changed)
*changed = 1;
}
mutex_unlock(&mgr->msg_lock);
return err;
}
static int pcxhr_handle_async_err(struct pcxhr_mgr *mgr, u32 err,
enum pcxhr_async_err_src err_src, int pipe,
int is_capture)
{
static char* err_src_name[] = {
[PCXHR_ERR_PIPE] = "Pipe",
[PCXHR_ERR_STREAM] = "Stream",
[PCXHR_ERR_AUDIO] = "Audio"
};
if (err & 0xfff)
err &= 0xfff;
else
err = ((err >> 12) & 0xfff);
if (!err)
return 0;
dev_dbg(&mgr->pci->dev, "CMD_ASYNC : Error %s %s Pipe %d err=%x\n",
err_src_name[err_src],
is_capture ? "Record" : "Play", pipe, err);
if (err == 0xe01)
mgr->async_err_stream_xrun++;
else if (err == 0xe10)
mgr->async_err_pipe_xrun++;
else
mgr->async_err_other_last = (int)err;
return 1;
}
static void pcxhr_msg_thread(struct pcxhr_mgr *mgr)
{
struct pcxhr_rmh *prmh = mgr->prmh;
int err;
int i, j;
if (mgr->src_it_dsp & PCXHR_IRQ_FREQ_CHANGE)
dev_dbg(&mgr->pci->dev,
"PCXHR_IRQ_FREQ_CHANGE event occurred\n");
if (mgr->src_it_dsp & PCXHR_IRQ_TIME_CODE)
dev_dbg(&mgr->pci->dev,
"PCXHR_IRQ_TIME_CODE event occurred\n");
if (mgr->src_it_dsp & PCXHR_IRQ_NOTIFY)
dev_dbg(&mgr->pci->dev,
"PCXHR_IRQ_NOTIFY event occurred\n");
if (mgr->src_it_dsp & (PCXHR_IRQ_FREQ_CHANGE | PCXHR_IRQ_TIME_CODE)) {
pcxhr_init_rmh(prmh, CMD_TEST_IT);
err = pcxhr_send_msg(mgr, prmh);
dev_dbg(&mgr->pci->dev, "CMD_TEST_IT : err=%x, stat=%x\n",
err, prmh->stat[0]);
}
if (mgr->src_it_dsp & PCXHR_IRQ_ASYNC) {
dev_dbg(&mgr->pci->dev,
"PCXHR_IRQ_ASYNC event occurred\n");
pcxhr_init_rmh(prmh, CMD_ASYNC);
prmh->cmd[0] |= 1;
prmh->stat_len = PCXHR_SIZE_MAX_LONG_STATUS;
err = pcxhr_send_msg(mgr, prmh);
if (err)
dev_err(&mgr->pci->dev, "ERROR pcxhr_msg_thread=%x;\n",
err);
i = 1;
while (i < prmh->stat_len) {
int nb_audio = ((prmh->stat[i] >> FIELD_SIZE) &
MASK_FIRST_FIELD);
int nb_stream = ((prmh->stat[i] >> (2*FIELD_SIZE)) &
MASK_FIRST_FIELD);
int pipe = prmh->stat[i] & MASK_FIRST_FIELD;
int is_capture = prmh->stat[i] & 0x400000;
u32 err2;
if (prmh->stat[i] & 0x800000) {
dev_dbg(&mgr->pci->dev,
"TASKLET : End%sPipe %d\n",
is_capture ? "Record" : "Play",
pipe);
}
i++;
err2 = prmh->stat[i] ? prmh->stat[i] : prmh->stat[i+1];
if (err2)
pcxhr_handle_async_err(mgr, err2,
PCXHR_ERR_PIPE,
pipe, is_capture);
i += 2;
for (j = 0; j < nb_stream; j++) {
err2 = prmh->stat[i] ?
prmh->stat[i] : prmh->stat[i+1];
if (err2)
pcxhr_handle_async_err(mgr, err2,
PCXHR_ERR_STREAM,
pipe,
is_capture);
i += 2;
}
for (j = 0; j < nb_audio; j++) {
err2 = prmh->stat[i] ?
prmh->stat[i] : prmh->stat[i+1];
if (err2)
pcxhr_handle_async_err(mgr, err2,
PCXHR_ERR_AUDIO,
pipe,
is_capture);
i += 2;
}
}
}
}
static u_int64_t pcxhr_stream_read_position(struct pcxhr_mgr *mgr,
struct pcxhr_stream *stream)
{
u_int64_t hw_sample_count;
struct pcxhr_rmh rmh;
int err, stream_mask;
stream_mask = stream->pipe->is_capture ? 1 : 1<<stream->substream->number;
pcxhr_init_rmh(&rmh, CMD_STREAM_SAMPLE_COUNT);
pcxhr_set_pipe_cmd_params(&rmh, stream->pipe->is_capture,
stream->pipe->first_audio, 0, stream_mask);
err = pcxhr_send_msg(mgr, &rmh);
if (err)
return 0;
hw_sample_count = ((u_int64_t)rmh.stat[0]) << 24;
hw_sample_count += (u_int64_t)rmh.stat[1];
dev_dbg(&mgr->pci->dev,
"stream %c%d : abs samples real(%llu) timer(%llu)\n",
stream->pipe->is_capture ? 'C' : 'P',
stream->substream->number,
hw_sample_count,
stream->timer_abs_periods + stream->timer_period_frag +
mgr->granularity);
return hw_sample_count;
}
static void pcxhr_update_timer_pos(struct pcxhr_mgr *mgr,
struct pcxhr_stream *stream,
int samples_to_add)
{
if (stream->substream &&
(stream->status == PCXHR_STREAM_STATUS_RUNNING)) {
u_int64_t new_sample_count;
int elapsed = 0;
int hardware_read = 0;
struct snd_pcm_runtime *runtime = stream->substream->runtime;
if (samples_to_add < 0) {
stream->timer_is_synced = 0;
samples_to_add = mgr->granularity;
}
if (!stream->timer_is_synced) {
if ((stream->timer_abs_periods != 0) ||
((stream->timer_period_frag + samples_to_add) >=
runtime->period_size)) {
new_sample_count =
pcxhr_stream_read_position(mgr, stream);
hardware_read = 1;
if (new_sample_count >= mgr->granularity) {
new_sample_count -= mgr->granularity;
stream->timer_is_synced = 1;
}
}
}
if (!hardware_read) {
new_sample_count = stream->timer_abs_periods +
stream->timer_period_frag + samples_to_add;
}
while (1) {
u_int64_t new_elapse_pos = stream->timer_abs_periods +
runtime->period_size;
if (new_elapse_pos > new_sample_count)
break;
elapsed = 1;
stream->timer_buf_periods++;
if (stream->timer_buf_periods >= runtime->periods)
stream->timer_buf_periods = 0;
stream->timer_abs_periods = new_elapse_pos;
}
if (new_sample_count >= stream->timer_abs_periods) {
stream->timer_period_frag =
(u_int32_t)(new_sample_count -
stream->timer_abs_periods);
} else {
dev_err(&mgr->pci->dev,
"ERROR new_sample_count too small ??? %ld\n",
(long unsigned int)new_sample_count);
}
if (elapsed) {
mutex_unlock(&mgr->lock);
snd_pcm_period_elapsed(stream->substream);
mutex_lock(&mgr->lock);
}
}
}
irqreturn_t pcxhr_interrupt(int irq, void *dev_id)
{
struct pcxhr_mgr *mgr = dev_id;
unsigned int reg;
bool wake_thread = false;
reg = PCXHR_INPL(mgr, PCXHR_PLX_IRQCS);
if (! (reg & PCXHR_IRQCS_ACTIVE_PCIDB)) {
return IRQ_NONE;
}
reg = PCXHR_INPL(mgr, PCXHR_PLX_L2PCIDB);
PCXHR_OUTPL(mgr, PCXHR_PLX_L2PCIDB, reg);
if (reg & PCXHR_IRQ_TIMER) {
int timer_toggle = reg & PCXHR_IRQ_TIMER;
if (timer_toggle == mgr->timer_toggle) {
dev_dbg(&mgr->pci->dev, "ERROR TIMER TOGGLE\n");
mgr->dsp_time_err++;
}
mgr->timer_toggle = timer_toggle;
mgr->src_it_dsp = reg;
wake_thread = true;
}
if (reg & PCXHR_IRQ_MASK) {
if (reg & PCXHR_IRQ_ASYNC) {
mgr->dsp_time_last = PCXHR_DSP_TIME_INVALID;
}
mgr->src_it_dsp = reg;
wake_thread = true;
}
#ifdef CONFIG_SND_DEBUG_VERBOSE
if (reg & PCXHR_FATAL_DSP_ERR)
dev_dbg(&mgr->pci->dev, "FATAL DSP ERROR : %x\n", reg);
#endif
return wake_thread ? IRQ_WAKE_THREAD : IRQ_HANDLED;
}
irqreturn_t pcxhr_threaded_irq(int irq, void *dev_id)
{
struct pcxhr_mgr *mgr = dev_id;
int i, j;
struct snd_pcxhr *chip;
mutex_lock(&mgr->lock);
if (mgr->src_it_dsp & PCXHR_IRQ_TIMER) {
int dsp_time_new =
PCXHR_INPL(mgr, PCXHR_PLX_MBOX4) & PCXHR_DSP_TIME_MASK;
int dsp_time_diff = dsp_time_new - mgr->dsp_time_last;
if ((dsp_time_diff < 0) &&
(mgr->dsp_time_last != PCXHR_DSP_TIME_INVALID)) {
int tmp_diff = dsp_time_diff + PCXHR_DSP_TIME_MASK + 1;
dev_dbg(&mgr->pci->dev,
"WARNING DSP timestamp old(%d) new(%d)",
mgr->dsp_time_last, dsp_time_new);
if (tmp_diff > 0 && tmp_diff <= (2*mgr->granularity)) {
dev_dbg(&mgr->pci->dev,
"-> timestamp wraparound OK: "
"diff=%d\n", tmp_diff);
dsp_time_diff = tmp_diff;
} else {
dev_dbg(&mgr->pci->dev,
"-> resynchronize all streams\n");
mgr->dsp_time_err++;
}
}
#ifdef CONFIG_SND_DEBUG_VERBOSE
if (dsp_time_diff == 0)
dev_dbg(&mgr->pci->dev,
"ERROR DSP TIME NO DIFF time(%d)\n",
dsp_time_new);
else if (dsp_time_diff >= (2*mgr->granularity))
dev_dbg(&mgr->pci->dev,
"ERROR DSP TIME TOO BIG old(%d) add(%d)\n",
mgr->dsp_time_last,
dsp_time_new - mgr->dsp_time_last);
else if (dsp_time_diff % mgr->granularity)
dev_dbg(&mgr->pci->dev,
"ERROR DSP TIME increased by %d\n",
dsp_time_diff);
#endif
mgr->dsp_time_last = dsp_time_new;
for (i = 0; i < mgr->num_cards; i++) {
chip = mgr->chip[i];
for (j = 0; j < chip->nb_streams_capt; j++)
pcxhr_update_timer_pos(mgr,
&chip->capture_stream[j],
dsp_time_diff);
}
for (i = 0; i < mgr->num_cards; i++) {
chip = mgr->chip[i];
for (j = 0; j < chip->nb_streams_play; j++)
pcxhr_update_timer_pos(mgr,
&chip->playback_stream[j],
dsp_time_diff);
}
}
pcxhr_msg_thread(mgr);
return IRQ_HANDLED;
}
