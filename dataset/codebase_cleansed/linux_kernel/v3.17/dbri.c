static __u32 reverse_bytes(__u32 b, int len)
{
switch (len) {
case 32:
b = ((b & 0xffff0000) >> 16) | ((b & 0x0000ffff) << 16);
case 16:
b = ((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8);
case 8:
b = ((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4);
case 4:
b = ((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2);
case 2:
b = ((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1);
case 1:
case 0:
break;
default:
printk(KERN_ERR "DBRI reverse_bytes: unsupported length\n");
}
return b;
}
static void dbri_cmdwait(struct snd_dbri *dbri)
{
int maxloops = MAXLOOPS;
unsigned long flags;
spin_lock_irqsave(&dbri->lock, flags);
while ((--maxloops) > 0 && (sbus_readl(dbri->regs + REG0) & D_P)) {
spin_unlock_irqrestore(&dbri->lock, flags);
msleep_interruptible(1);
spin_lock_irqsave(&dbri->lock, flags);
}
spin_unlock_irqrestore(&dbri->lock, flags);
if (maxloops == 0)
printk(KERN_ERR "DBRI: Chip never completed command buffer\n");
else
dprintk(D_CMD, "Chip completed command buffer (%d)\n",
MAXLOOPS - maxloops - 1);
}
static s32 *dbri_cmdlock(struct snd_dbri *dbri, int len)
{
len += 2;
spin_lock(&dbri->cmdlock);
if (dbri->cmdptr - dbri->dma->cmd + len < DBRI_NO_CMDS - 2)
return dbri->cmdptr + 2;
else if (len < sbus_readl(dbri->regs + REG8) - dbri->dma_dvma)
return dbri->dma->cmd;
else
printk(KERN_ERR "DBRI: no space for commands.");
return NULL;
}
static void dbri_cmdsend(struct snd_dbri *dbri, s32 *cmd, int len)
{
s32 tmp, addr;
static int wait_id = 0;
wait_id++;
wait_id &= 0xffff;
*(cmd) = DBRI_CMD(D_WAIT, 1, wait_id);
*(cmd+1) = DBRI_CMD(D_WAIT, 1, wait_id);
addr = dbri->dma_dvma + (cmd - len - dbri->dma->cmd) * sizeof(s32);
*(dbri->cmdptr+1) = addr;
*(dbri->cmdptr) = DBRI_CMD(D_JUMP, 0, 0);
#ifdef DBRI_DEBUG
if (cmd > dbri->cmdptr) {
s32 *ptr;
for (ptr = dbri->cmdptr; ptr < cmd+2; ptr++)
dprintk(D_CMD, "cmd: %lx:%08x\n",
(unsigned long)ptr, *ptr);
} else {
s32 *ptr = dbri->cmdptr;
dprintk(D_CMD, "cmd: %lx:%08x\n", (unsigned long)ptr, *ptr);
ptr++;
dprintk(D_CMD, "cmd: %lx:%08x\n", (unsigned long)ptr, *ptr);
for (ptr = dbri->dma->cmd; ptr < cmd+2; ptr++)
dprintk(D_CMD, "cmd: %lx:%08x\n",
(unsigned long)ptr, *ptr);
}
#endif
tmp = sbus_readl(dbri->regs + REG0);
tmp |= D_P;
sbus_writel(tmp, dbri->regs + REG0);
dbri->cmdptr = cmd;
spin_unlock(&dbri->cmdlock);
}
static void dbri_reset(struct snd_dbri *dbri)
{
int i;
u32 tmp;
dprintk(D_GEN, "reset 0:%x 2:%x 8:%x 9:%x\n",
sbus_readl(dbri->regs + REG0),
sbus_readl(dbri->regs + REG2),
sbus_readl(dbri->regs + REG8), sbus_readl(dbri->regs + REG9));
sbus_writel(D_R, dbri->regs + REG0);
for (i = 0; (sbus_readl(dbri->regs + REG0) & D_R) && i < 64; i++)
udelay(10);
tmp = sbus_readl(dbri->regs + REG0);
tmp |= D_G | D_E;
tmp &= ~D_S;
sbus_writel(tmp, dbri->regs + REG0);
}
static void dbri_initialize(struct snd_dbri *dbri)
{
s32 *cmd;
u32 dma_addr;
unsigned long flags;
int n;
spin_lock_irqsave(&dbri->lock, flags);
dbri_reset(dbri);
for (n = 0; n < DBRI_NO_PIPES; n++)
dbri->pipes[n].desc = dbri->pipes[n].first_desc = -1;
spin_lock_init(&dbri->cmdlock);
dma_addr = dbri->dma_dvma + dbri_dma_off(intr, 0);
dbri->dma->intr[0] = dma_addr;
dbri->dbri_irqp = 1;
spin_lock(&dbri->cmdlock);
cmd = dbri->cmdptr = dbri->dma->cmd;
*(cmd++) = DBRI_CMD(D_IIQ, 0, 0);
*(cmd++) = dma_addr;
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
dbri->cmdptr = cmd;
*(cmd++) = DBRI_CMD(D_WAIT, 1, 0);
*(cmd++) = DBRI_CMD(D_WAIT, 1, 0);
dma_addr = dbri->dma_dvma + dbri_dma_off(cmd, 0);
sbus_writel(dma_addr, dbri->regs + REG8);
spin_unlock(&dbri->cmdlock);
spin_unlock_irqrestore(&dbri->lock, flags);
dbri_cmdwait(dbri);
}
static inline int pipe_active(struct snd_dbri *dbri, int pipe)
{
return ((pipe >= 0) && (dbri->pipes[pipe].desc != -1));
}
static void reset_pipe(struct snd_dbri *dbri, int pipe)
{
int sdp;
int desc;
s32 *cmd;
if (pipe < 0 || pipe > DBRI_MAX_PIPE) {
printk(KERN_ERR "DBRI: reset_pipe called with "
"illegal pipe number\n");
return;
}
sdp = dbri->pipes[pipe].sdp;
if (sdp == 0) {
printk(KERN_ERR "DBRI: reset_pipe called "
"on uninitialized pipe\n");
return;
}
cmd = dbri_cmdlock(dbri, 3);
*(cmd++) = DBRI_CMD(D_SDP, 0, sdp | D_SDP_C | D_SDP_P);
*(cmd++) = 0;
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
dbri_cmdsend(dbri, cmd, 3);
desc = dbri->pipes[pipe].first_desc;
if (desc >= 0)
do {
dbri->dma->desc[desc].ba = 0;
dbri->dma->desc[desc].nda = 0;
desc = dbri->next_desc[desc];
} while (desc != -1 && desc != dbri->pipes[pipe].first_desc);
dbri->pipes[pipe].desc = -1;
dbri->pipes[pipe].first_desc = -1;
}
static void setup_pipe(struct snd_dbri *dbri, int pipe, int sdp)
{
if (pipe < 0 || pipe > DBRI_MAX_PIPE) {
printk(KERN_ERR "DBRI: setup_pipe called "
"with illegal pipe number\n");
return;
}
if ((sdp & 0xf800) != sdp) {
printk(KERN_ERR "DBRI: setup_pipe called "
"with strange SDP value\n");
}
if (D_SDP_MODE(sdp) == D_SDP_FIXED && !(sdp & D_SDP_TO_SER))
sdp |= D_SDP_CHANGE;
sdp |= D_PIPE(pipe);
dbri->pipes[pipe].sdp = sdp;
dbri->pipes[pipe].desc = -1;
dbri->pipes[pipe].first_desc = -1;
reset_pipe(dbri, pipe);
}
static void link_time_slot(struct snd_dbri *dbri, int pipe,
int prevpipe, int nextpipe,
int length, int cycle)
{
s32 *cmd;
int val;
if (pipe < 0 || pipe > DBRI_MAX_PIPE
|| prevpipe < 0 || prevpipe > DBRI_MAX_PIPE
|| nextpipe < 0 || nextpipe > DBRI_MAX_PIPE) {
printk(KERN_ERR
"DBRI: link_time_slot called with illegal pipe number\n");
return;
}
if (dbri->pipes[pipe].sdp == 0
|| dbri->pipes[prevpipe].sdp == 0
|| dbri->pipes[nextpipe].sdp == 0) {
printk(KERN_ERR "DBRI: link_time_slot called "
"on uninitialized pipe\n");
return;
}
dbri->pipes[prevpipe].nextpipe = pipe;
dbri->pipes[pipe].nextpipe = nextpipe;
dbri->pipes[pipe].length = length;
cmd = dbri_cmdlock(dbri, 4);
if (dbri->pipes[pipe].sdp & D_SDP_TO_SER) {
if (prevpipe == 16 && cycle == 0)
cycle = dbri->chi_bpf;
val = D_DTS_VO | D_DTS_INS | D_DTS_PRVOUT(prevpipe) | pipe;
*(cmd++) = DBRI_CMD(D_DTS, 0, val);
*(cmd++) = 0;
*(cmd++) =
D_TS_LEN(length) | D_TS_CYCLE(cycle) | D_TS_NEXT(nextpipe);
} else {
val = D_DTS_VI | D_DTS_INS | D_DTS_PRVIN(prevpipe) | pipe;
*(cmd++) = DBRI_CMD(D_DTS, 0, val);
*(cmd++) =
D_TS_LEN(length) | D_TS_CYCLE(cycle) | D_TS_NEXT(nextpipe);
*(cmd++) = 0;
}
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
dbri_cmdsend(dbri, cmd, 4);
}
static void xmit_fixed(struct snd_dbri *dbri, int pipe, unsigned int data)
{
s32 *cmd;
unsigned long flags;
if (pipe < 16 || pipe > DBRI_MAX_PIPE) {
printk(KERN_ERR "DBRI: xmit_fixed: Illegal pipe number\n");
return;
}
if (D_SDP_MODE(dbri->pipes[pipe].sdp) == 0) {
printk(KERN_ERR "DBRI: xmit_fixed: "
"Uninitialized pipe %d\n", pipe);
return;
}
if (D_SDP_MODE(dbri->pipes[pipe].sdp) != D_SDP_FIXED) {
printk(KERN_ERR "DBRI: xmit_fixed: Non-fixed pipe %d\n", pipe);
return;
}
if (!(dbri->pipes[pipe].sdp & D_SDP_TO_SER)) {
printk(KERN_ERR "DBRI: xmit_fixed: Called on receive pipe %d\n",
pipe);
return;
}
if (dbri->pipes[pipe].sdp & D_SDP_MSB)
data = reverse_bytes(data, dbri->pipes[pipe].length);
cmd = dbri_cmdlock(dbri, 3);
*(cmd++) = DBRI_CMD(D_SSP, 0, pipe);
*(cmd++) = data;
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
spin_lock_irqsave(&dbri->lock, flags);
dbri_cmdsend(dbri, cmd, 3);
spin_unlock_irqrestore(&dbri->lock, flags);
dbri_cmdwait(dbri);
}
static void recv_fixed(struct snd_dbri *dbri, int pipe, volatile __u32 *ptr)
{
if (pipe < 16 || pipe > DBRI_MAX_PIPE) {
printk(KERN_ERR "DBRI: recv_fixed called with "
"illegal pipe number\n");
return;
}
if (D_SDP_MODE(dbri->pipes[pipe].sdp) != D_SDP_FIXED) {
printk(KERN_ERR "DBRI: recv_fixed called on "
"non-fixed pipe %d\n", pipe);
return;
}
if (dbri->pipes[pipe].sdp & D_SDP_TO_SER) {
printk(KERN_ERR "DBRI: recv_fixed called on "
"transmit pipe %d\n", pipe);
return;
}
dbri->pipes[pipe].recv_fixed_ptr = ptr;
}
static int setup_descs(struct snd_dbri *dbri, int streamno, unsigned int period)
{
struct dbri_streaminfo *info = &dbri->stream_info[streamno];
__u32 dvma_buffer;
int desc;
int len;
int first_desc = -1;
int last_desc = -1;
if (info->pipe < 0 || info->pipe > 15) {
printk(KERN_ERR "DBRI: setup_descs: Illegal pipe number\n");
return -2;
}
if (dbri->pipes[info->pipe].sdp == 0) {
printk(KERN_ERR "DBRI: setup_descs: Uninitialized pipe %d\n",
info->pipe);
return -2;
}
dvma_buffer = info->dvma_buffer;
len = info->size;
if (streamno == DBRI_PLAY) {
if (!(dbri->pipes[info->pipe].sdp & D_SDP_TO_SER)) {
printk(KERN_ERR "DBRI: setup_descs: "
"Called on receive pipe %d\n", info->pipe);
return -2;
}
} else {
if (dbri->pipes[info->pipe].sdp & D_SDP_TO_SER) {
printk(KERN_ERR
"DBRI: setup_descs: Called on transmit pipe %d\n",
info->pipe);
return -2;
}
if (pipe_active(dbri, info->pipe)) {
printk(KERN_ERR "DBRI: recv_on_pipe: "
"Called on active pipe %d\n", info->pipe);
return -2;
}
len &= ~3;
}
desc = dbri->pipes[info->pipe].first_desc;
if (desc >= 0)
do {
dbri->dma->desc[desc].ba = 0;
dbri->dma->desc[desc].nda = 0;
desc = dbri->next_desc[desc];
} while (desc != -1 &&
desc != dbri->pipes[info->pipe].first_desc);
dbri->pipes[info->pipe].desc = -1;
dbri->pipes[info->pipe].first_desc = -1;
desc = 0;
while (len > 0) {
int mylen;
for (; desc < DBRI_NO_DESCS; desc++) {
if (!dbri->dma->desc[desc].ba)
break;
}
if (desc == DBRI_NO_DESCS) {
printk(KERN_ERR "DBRI: setup_descs: No descriptors\n");
return -1;
}
if (len > DBRI_TD_MAXCNT)
mylen = DBRI_TD_MAXCNT;
else
mylen = len;
if (mylen > period)
mylen = period;
dbri->next_desc[desc] = -1;
dbri->dma->desc[desc].ba = dvma_buffer;
dbri->dma->desc[desc].nda = 0;
if (streamno == DBRI_PLAY) {
dbri->dma->desc[desc].word1 = DBRI_TD_CNT(mylen);
dbri->dma->desc[desc].word4 = 0;
dbri->dma->desc[desc].word1 |= DBRI_TD_F | DBRI_TD_B;
} else {
dbri->dma->desc[desc].word1 = 0;
dbri->dma->desc[desc].word4 =
DBRI_RD_B | DBRI_RD_BCNT(mylen);
}
if (first_desc == -1)
first_desc = desc;
else {
dbri->next_desc[last_desc] = desc;
dbri->dma->desc[last_desc].nda =
dbri->dma_dvma + dbri_dma_off(desc, desc);
}
last_desc = desc;
dvma_buffer += mylen;
len -= mylen;
}
if (first_desc == -1 || last_desc == -1) {
printk(KERN_ERR "DBRI: setup_descs: "
" Not enough descriptors available\n");
return -1;
}
dbri->dma->desc[last_desc].nda =
dbri->dma_dvma + dbri_dma_off(desc, first_desc);
dbri->next_desc[last_desc] = first_desc;
dbri->pipes[info->pipe].first_desc = first_desc;
dbri->pipes[info->pipe].desc = first_desc;
#ifdef DBRI_DEBUG
for (desc = first_desc; desc != -1;) {
dprintk(D_DESC, "DESC %d: %08x %08x %08x %08x\n",
desc,
dbri->dma->desc[desc].word1,
dbri->dma->desc[desc].ba,
dbri->dma->desc[desc].nda, dbri->dma->desc[desc].word4);
desc = dbri->next_desc[desc];
if (desc == first_desc)
break;
}
#endif
return 0;
}
static void reset_chi(struct snd_dbri *dbri,
enum master_or_slave master_or_slave,
int bits_per_frame)
{
s32 *cmd;
int val;
cmd = dbri_cmdlock(dbri, 4);
val = D_DTS_VO | D_DTS_VI | D_DTS_INS
| D_DTS_PRVIN(16) | D_PIPE(16) | D_DTS_PRVOUT(16);
*(cmd++) = DBRI_CMD(D_DTS, 0, val);
*(cmd++) = D_TS_ANCHOR | D_TS_NEXT(16);
*(cmd++) = D_TS_ANCHOR | D_TS_NEXT(16);
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
dbri_cmdsend(dbri, cmd, 4);
dbri->pipes[16].sdp = 1;
dbri->pipes[16].nextpipe = 16;
cmd = dbri_cmdlock(dbri, 4);
if (master_or_slave == CHIslave) {
*(cmd++) = DBRI_CMD(D_CHI, 0, D_CHI_CHICM(0));
} else {
int clockrate = bits_per_frame * 8;
int divisor = 12288 / clockrate;
if (divisor > 255 || divisor * clockrate != 12288)
printk(KERN_ERR "DBRI: illegal bits_per_frame "
"in setup_chi\n");
*(cmd++) = DBRI_CMD(D_CHI, 0, D_CHI_CHICM(divisor) | D_CHI_FD
| D_CHI_BPF(bits_per_frame));
}
dbri->chi_bpf = bits_per_frame;
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
*(cmd++) = DBRI_CMD(D_CDM, 0, D_CDM_XCE | D_CDM_XEN | D_CDM_REN);
*(cmd++) = DBRI_CMD(D_PAUSE, 0, 0);
dbri_cmdsend(dbri, cmd, 4);
}
static void cs4215_setup_pipes(struct snd_dbri *dbri)
{
unsigned long flags;
spin_lock_irqsave(&dbri->lock, flags);
setup_pipe(dbri, 4, D_SDP_MEM | D_SDP_TO_SER | D_SDP_MSB);
setup_pipe(dbri, 20, D_SDP_FIXED | D_SDP_TO_SER | D_SDP_MSB);
setup_pipe(dbri, 6, D_SDP_MEM | D_SDP_FROM_SER | D_SDP_MSB);
setup_pipe(dbri, 21, D_SDP_FIXED | D_SDP_FROM_SER | D_SDP_MSB);
setup_pipe(dbri, 17, D_SDP_FIXED | D_SDP_TO_SER | D_SDP_MSB);
setup_pipe(dbri, 18, D_SDP_FIXED | D_SDP_FROM_SER | D_SDP_MSB);
setup_pipe(dbri, 19, D_SDP_FIXED | D_SDP_FROM_SER | D_SDP_MSB);
spin_unlock_irqrestore(&dbri->lock, flags);
dbri_cmdwait(dbri);
}
static int cs4215_init_data(struct cs4215 *mm)
{
mm->data[0] = CS4215_LO(0x20) | CS4215_HE | CS4215_LE;
mm->data[1] = CS4215_RO(0x20) | CS4215_SE;
mm->data[2] = CS4215_LG(0x8) | CS4215_IS | CS4215_PIO0 | CS4215_PIO1;
mm->data[3] = CS4215_RG(0x8) | CS4215_MA(0xf);
mm->ctrl[0] = CS4215_RSRVD_1 | CS4215_MLB;
mm->ctrl[1] = CS4215_DFR_ULAW | CS4215_FREQ[0].csval;
mm->ctrl[2] = CS4215_XCLK | CS4215_BSEL_128 | CS4215_FREQ[0].xtal;
mm->ctrl[3] = 0;
mm->status = 0;
mm->version = 0xff;
mm->precision = 8;
mm->channels = 1;
return 0;
}
static void cs4215_setdata(struct snd_dbri *dbri, int muted)
{
if (muted) {
dbri->mm.data[0] |= 63;
dbri->mm.data[1] |= 63;
dbri->mm.data[2] &= ~15;
dbri->mm.data[3] &= ~15;
} else {
struct dbri_streaminfo *info = &dbri->stream_info[DBRI_PLAY];
int left_gain = info->left_gain & 0x3f;
int right_gain = info->right_gain & 0x3f;
dbri->mm.data[0] &= ~0x3f;
dbri->mm.data[1] &= ~0x3f;
dbri->mm.data[0] |= (DBRI_MAX_VOLUME - left_gain);
dbri->mm.data[1] |= (DBRI_MAX_VOLUME - right_gain);
info = &dbri->stream_info[DBRI_REC];
left_gain = info->left_gain & 0xf;
right_gain = info->right_gain & 0xf;
dbri->mm.data[2] |= CS4215_LG(left_gain);
dbri->mm.data[3] |= CS4215_RG(right_gain);
}
xmit_fixed(dbri, 20, *(int *)dbri->mm.data);
}
static void cs4215_open(struct snd_dbri *dbri)
{
int data_width;
u32 tmp;
unsigned long flags;
dprintk(D_MM, "cs4215_open: %d channels, %d bits\n",
dbri->mm.channels, dbri->mm.precision);
cs4215_setdata(dbri, 1);
udelay(125);
spin_lock_irqsave(&dbri->lock, flags);
tmp = sbus_readl(dbri->regs + REG0);
tmp &= ~(D_C);
sbus_writel(tmp, dbri->regs + REG0);
sbus_writel(D_ENPIO | D_PIO1 | D_PIO3 |
(dbri->mm.onboard ? D_PIO0 : D_PIO2), dbri->regs + REG2);
reset_chi(dbri, CHIslave, 128);
data_width = dbri->mm.channels * dbri->mm.precision;
link_time_slot(dbri, 4, 16, 16, data_width, dbri->mm.offset);
link_time_slot(dbri, 20, 4, 16, 32, dbri->mm.offset + 32);
link_time_slot(dbri, 6, 16, 16, data_width, dbri->mm.offset);
link_time_slot(dbri, 21, 6, 16, 16, dbri->mm.offset + 40);
tmp = sbus_readl(dbri->regs + REG0);
tmp |= D_C;
sbus_writel(tmp, dbri->regs + REG0);
spin_unlock_irqrestore(&dbri->lock, flags);
cs4215_setdata(dbri, 0);
}
static int cs4215_setctrl(struct snd_dbri *dbri)
{
int i, val;
u32 tmp;
unsigned long flags;
cs4215_setdata(dbri, 1);
udelay(125);
val = D_ENPIO | D_PIO1 | (dbri->mm.onboard ? D_PIO0 : D_PIO2);
sbus_writel(val, dbri->regs + REG2);
dprintk(D_MM, "cs4215_setctrl: reg2=0x%x\n", val);
udelay(34);
spin_lock_irqsave(&dbri->lock, flags);
tmp = sbus_readl(dbri->regs + REG0);
tmp &= ~D_C;
sbus_writel(tmp, dbri->regs + REG0);
reset_chi(dbri, CHImaster, 128);
link_time_slot(dbri, 17, 16, 16, 32, dbri->mm.offset);
link_time_slot(dbri, 18, 16, 16, 8, dbri->mm.offset);
link_time_slot(dbri, 19, 18, 16, 8, dbri->mm.offset + 48);
spin_unlock_irqrestore(&dbri->lock, flags);
dbri->mm.ctrl[0] &= ~CS4215_CLB;
xmit_fixed(dbri, 17, *(int *)dbri->mm.ctrl);
spin_lock_irqsave(&dbri->lock, flags);
tmp = sbus_readl(dbri->regs + REG0);
tmp |= D_C;
sbus_writel(tmp, dbri->regs + REG0);
spin_unlock_irqrestore(&dbri->lock, flags);
for (i = 10; ((dbri->mm.status & 0xe4) != 0x20); --i)
msleep_interruptible(1);
if (i == 0) {
dprintk(D_MM, "CS4215 didn't respond to CLB (0x%02x)\n",
dbri->mm.status);
return -1;
}
recv_fixed(dbri, 19, NULL);
dbri->mm.ctrl[0] |= CS4215_CLB;
xmit_fixed(dbri, 17, *(int *)dbri->mm.ctrl);
udelay(250);
cs4215_setdata(dbri, 0);
return 0;
}
static int cs4215_prepare(struct snd_dbri *dbri, unsigned int rate,
snd_pcm_format_t format, unsigned int channels)
{
int freq_idx;
int ret = 0;
for (freq_idx = 0; CS4215_FREQ[freq_idx].freq != 0; freq_idx++) {
if (CS4215_FREQ[freq_idx].freq == rate)
break;
}
if (CS4215_FREQ[freq_idx].freq != rate) {
printk(KERN_WARNING "DBRI: Unsupported rate %d Hz\n", rate);
return -1;
}
switch (format) {
case SNDRV_PCM_FORMAT_MU_LAW:
dbri->mm.ctrl[1] = CS4215_DFR_ULAW;
dbri->mm.precision = 8;
break;
case SNDRV_PCM_FORMAT_A_LAW:
dbri->mm.ctrl[1] = CS4215_DFR_ALAW;
dbri->mm.precision = 8;
break;
case SNDRV_PCM_FORMAT_U8:
dbri->mm.ctrl[1] = CS4215_DFR_LINEAR8;
dbri->mm.precision = 8;
break;
case SNDRV_PCM_FORMAT_S16_BE:
dbri->mm.ctrl[1] = CS4215_DFR_LINEAR16;
dbri->mm.precision = 16;
break;
default:
printk(KERN_WARNING "DBRI: Unsupported format %d\n", format);
return -1;
}
dbri->mm.ctrl[1] |= CS4215_FREQ[freq_idx].csval;
dbri->mm.ctrl[2] = CS4215_XCLK |
CS4215_BSEL_128 | CS4215_FREQ[freq_idx].xtal;
dbri->mm.channels = channels;
if (channels == 2)
dbri->mm.ctrl[1] |= CS4215_DFR_STEREO;
ret = cs4215_setctrl(dbri);
if (ret == 0)
cs4215_open(dbri);
return ret;
}
static int cs4215_init(struct snd_dbri *dbri)
{
u32 reg2 = sbus_readl(dbri->regs + REG2);
dprintk(D_MM, "cs4215_init: reg2=0x%x\n", reg2);
if (reg2 & D_PIO2) {
dprintk(D_MM, "Onboard CS4215 detected\n");
dbri->mm.onboard = 1;
}
if (reg2 & D_PIO0) {
dprintk(D_MM, "Speakerbox detected\n");
dbri->mm.onboard = 0;
if (reg2 & D_PIO2) {
printk(KERN_INFO "DBRI: Using speakerbox / "
"ignoring onboard mmcodec.\n");
sbus_writel(D_ENPIO2, dbri->regs + REG2);
}
}
if (!(reg2 & (D_PIO0 | D_PIO2))) {
printk(KERN_ERR "DBRI: no mmcodec found.\n");
return -EIO;
}
cs4215_setup_pipes(dbri);
cs4215_init_data(&dbri->mm);
recv_fixed(dbri, 18, &dbri->mm.status);
recv_fixed(dbri, 19, &dbri->mm.version);
dbri->mm.offset = dbri->mm.onboard ? 0 : 8;
if (cs4215_setctrl(dbri) == -1 || dbri->mm.version == 0xff) {
dprintk(D_MM, "CS4215 failed probe at offset %d\n",
dbri->mm.offset);
return -EIO;
}
dprintk(D_MM, "Found CS4215 at offset %d\n", dbri->mm.offset);
return 0;
}
static void xmit_descs(struct snd_dbri *dbri)
{
struct dbri_streaminfo *info;
s32 *cmd;
unsigned long flags;
int first_td;
if (dbri == NULL)
return;
info = &dbri->stream_info[DBRI_REC];
spin_lock_irqsave(&dbri->lock, flags);
if (info->pipe >= 0) {
first_td = dbri->pipes[info->pipe].first_desc;
dprintk(D_DESC, "xmit_descs rec @ TD %d\n", first_td);
if (first_td >= 0) {
cmd = dbri_cmdlock(dbri, 2);
*(cmd++) = DBRI_CMD(D_SDP, 0,
dbri->pipes[info->pipe].sdp
| D_SDP_P | D_SDP_EVERY | D_SDP_C);
*(cmd++) = dbri->dma_dvma +
dbri_dma_off(desc, first_td);
dbri_cmdsend(dbri, cmd, 2);
dbri->pipes[info->pipe].desc = first_td;
}
}
info = &dbri->stream_info[DBRI_PLAY];
if (info->pipe >= 0) {
first_td = dbri->pipes[info->pipe].first_desc;
dprintk(D_DESC, "xmit_descs play @ TD %d\n", first_td);
if (first_td >= 0) {
cmd = dbri_cmdlock(dbri, 2);
*(cmd++) = DBRI_CMD(D_SDP, 0,
dbri->pipes[info->pipe].sdp
| D_SDP_P | D_SDP_EVERY | D_SDP_C);
*(cmd++) = dbri->dma_dvma +
dbri_dma_off(desc, first_td);
dbri_cmdsend(dbri, cmd, 2);
dbri->pipes[info->pipe].desc = first_td;
}
}
spin_unlock_irqrestore(&dbri->lock, flags);
}
static void transmission_complete_intr(struct snd_dbri *dbri, int pipe)
{
struct dbri_streaminfo *info = &dbri->stream_info[DBRI_PLAY];
int td = dbri->pipes[pipe].desc;
int status;
while (td >= 0) {
if (td >= DBRI_NO_DESCS) {
printk(KERN_ERR "DBRI: invalid td on pipe %d\n", pipe);
return;
}
status = DBRI_TD_STATUS(dbri->dma->desc[td].word4);
if (!(status & DBRI_TD_TBC))
break;
dprintk(D_INT, "TD %d, status 0x%02x\n", td, status);
dbri->dma->desc[td].word4 = 0;
info->offset += DBRI_RD_CNT(dbri->dma->desc[td].word1);
td = dbri->next_desc[td];
dbri->pipes[pipe].desc = td;
}
spin_unlock(&dbri->lock);
snd_pcm_period_elapsed(info->substream);
spin_lock(&dbri->lock);
}
static void reception_complete_intr(struct snd_dbri *dbri, int pipe)
{
struct dbri_streaminfo *info;
int rd = dbri->pipes[pipe].desc;
s32 status;
if (rd < 0 || rd >= DBRI_NO_DESCS) {
printk(KERN_ERR "DBRI: invalid rd on pipe %d\n", pipe);
return;
}
dbri->pipes[pipe].desc = dbri->next_desc[rd];
status = dbri->dma->desc[rd].word1;
dbri->dma->desc[rd].word1 = 0;
info = &dbri->stream_info[DBRI_REC];
info->offset += DBRI_RD_CNT(status);
dprintk(D_INT, "Recv RD %d, status 0x%02x, len %d\n",
rd, DBRI_RD_STATUS(status), DBRI_RD_CNT(status));
spin_unlock(&dbri->lock);
snd_pcm_period_elapsed(info->substream);
spin_lock(&dbri->lock);
}
static void dbri_process_one_interrupt(struct snd_dbri *dbri, int x)
{
int val = D_INTR_GETVAL(x);
int channel = D_INTR_GETCHAN(x);
int command = D_INTR_GETCMD(x);
int code = D_INTR_GETCODE(x);
#ifdef DBRI_DEBUG
int rval = D_INTR_GETRVAL(x);
#endif
if (channel == D_INTR_CMD) {
dprintk(D_CMD, "INTR: Command: %-5s Value:%d\n",
cmds[command], val);
} else {
dprintk(D_INT, "INTR: Chan:%d Code:%d Val:%#x\n",
channel, code, rval);
}
switch (code) {
case D_INTR_CMDI:
if (command != D_WAIT)
printk(KERN_ERR "DBRI: Command read interrupt\n");
break;
case D_INTR_BRDY:
reception_complete_intr(dbri, channel);
break;
case D_INTR_XCMP:
case D_INTR_MINT:
transmission_complete_intr(dbri, channel);
break;
case D_INTR_UNDR:
{
printk(KERN_ERR "DBRI: Underrun error\n");
#if 0
s32 *cmd;
int pipe = channel;
int td = dbri->pipes[pipe].desc;
dbri->dma->desc[td].word4 = 0;
cmd = dbri_cmdlock(dbri, NoGetLock);
*(cmd++) = DBRI_CMD(D_SDP, 0,
dbri->pipes[pipe].sdp
| D_SDP_P | D_SDP_C | D_SDP_2SAME);
*(cmd++) = dbri->dma_dvma + dbri_dma_off(desc, td);
dbri_cmdsend(dbri, cmd);
#endif
}
break;
case D_INTR_FXDT:
if (dbri->pipes[channel].sdp & D_SDP_MSB)
val = reverse_bytes(val, dbri->pipes[channel].length);
if (dbri->pipes[channel].recv_fixed_ptr)
*(dbri->pipes[channel].recv_fixed_ptr) = val;
break;
default:
if (channel != D_INTR_CMD)
printk(KERN_WARNING
"DBRI: Ignored Interrupt: %d (0x%x)\n", code, x);
}
}
static void dbri_process_interrupt_buffer(struct snd_dbri *dbri)
{
s32 x;
while ((x = dbri->dma->intr[dbri->dbri_irqp]) != 0) {
dbri->dma->intr[dbri->dbri_irqp] = 0;
dbri->dbri_irqp++;
if (dbri->dbri_irqp == DBRI_INT_BLK)
dbri->dbri_irqp = 1;
dbri_process_one_interrupt(dbri, x);
}
}
static irqreturn_t snd_dbri_interrupt(int irq, void *dev_id)
{
struct snd_dbri *dbri = dev_id;
static int errcnt = 0;
int x;
if (dbri == NULL)
return IRQ_NONE;
spin_lock(&dbri->lock);
x = sbus_readl(dbri->regs + REG1);
if (x & (D_MRR | D_MLE | D_LBG | D_MBE)) {
u32 tmp;
if (x & D_MRR)
printk(KERN_ERR
"DBRI: Multiple Error Ack on SBus reg1=0x%x\n",
x);
if (x & D_MLE)
printk(KERN_ERR
"DBRI: Multiple Late Error on SBus reg1=0x%x\n",
x);
if (x & D_LBG)
printk(KERN_ERR
"DBRI: Lost Bus Grant on SBus reg1=0x%x\n", x);
if (x & D_MBE)
printk(KERN_ERR
"DBRI: Burst Error on SBus reg1=0x%x\n", x);
if ((++errcnt) % 10 == 0) {
dprintk(D_INT, "Interrupt errors exceeded.\n");
dbri_reset(dbri);
} else {
tmp = sbus_readl(dbri->regs + REG0);
tmp &= ~(D_D);
sbus_writel(tmp, dbri->regs + REG0);
}
}
dbri_process_interrupt_buffer(dbri);
spin_unlock(&dbri->lock);
return IRQ_HANDLED;
}
static int snd_hw_rule_format(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *f = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
struct snd_mask fmt;
snd_mask_any(&fmt);
if (c->min > 1) {
fmt.bits[0] &= SNDRV_PCM_FMTBIT_S16_BE;
return snd_mask_refine(f, &fmt);
}
return 0;
}
static int snd_hw_rule_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *f = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
struct snd_interval ch;
snd_interval_any(&ch);
if (!(f->bits[0] & SNDRV_PCM_FMTBIT_S16_BE)) {
ch.min = 1;
ch.max = 1;
ch.integer = 1;
return snd_interval_refine(c, &ch);
}
return 0;
}
static int snd_dbri_open(struct snd_pcm_substream *substream)
{
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
unsigned long flags;
dprintk(D_USR, "open audio output.\n");
runtime->hw = snd_dbri_pcm_hw;
spin_lock_irqsave(&dbri->lock, flags);
info->substream = substream;
info->offset = 0;
info->dvma_buffer = 0;
info->pipe = -1;
spin_unlock_irqrestore(&dbri->lock, flags);
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
snd_hw_rule_format, NULL, SNDRV_PCM_HW_PARAM_FORMAT,
-1);
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_FORMAT,
snd_hw_rule_channels, NULL,
SNDRV_PCM_HW_PARAM_CHANNELS,
-1);
cs4215_open(dbri);
return 0;
}
static int snd_dbri_close(struct snd_pcm_substream *substream)
{
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
dprintk(D_USR, "close audio output.\n");
info->substream = NULL;
info->offset = 0;
return 0;
}
static int snd_dbri_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
int direction;
int ret;
ret = cs4215_prepare(dbri, params_rate(hw_params),
params_format(hw_params),
params_channels(hw_params));
if (ret != 0)
return ret;
if ((ret = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params))) < 0) {
printk(KERN_ERR "malloc_pages failed with %d\n", ret);
return ret;
}
if (info->dvma_buffer == 0) {
if (DBRI_STREAMNO(substream) == DBRI_PLAY)
direction = DMA_TO_DEVICE;
else
direction = DMA_FROM_DEVICE;
info->dvma_buffer =
dma_map_single(&dbri->op->dev,
runtime->dma_area,
params_buffer_bytes(hw_params),
direction);
}
direction = params_buffer_bytes(hw_params);
dprintk(D_USR, "hw_params: %d bytes, dvma=%x\n",
direction, info->dvma_buffer);
return 0;
}
static int snd_dbri_hw_free(struct snd_pcm_substream *substream)
{
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
int direction;
dprintk(D_USR, "hw_free.\n");
if (info->dvma_buffer) {
if (DBRI_STREAMNO(substream) == DBRI_PLAY)
direction = DMA_TO_DEVICE;
else
direction = DMA_FROM_DEVICE;
dma_unmap_single(&dbri->op->dev, info->dvma_buffer,
substream->runtime->buffer_size, direction);
info->dvma_buffer = 0;
}
if (info->pipe != -1) {
reset_pipe(dbri, info->pipe);
info->pipe = -1;
}
return snd_pcm_lib_free_pages(substream);
}
static int snd_dbri_prepare(struct snd_pcm_substream *substream)
{
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
int ret;
info->size = snd_pcm_lib_buffer_bytes(substream);
if (DBRI_STREAMNO(substream) == DBRI_PLAY)
info->pipe = 4;
else
info->pipe = 6;
spin_lock_irq(&dbri->lock);
info->offset = 0;
ret = setup_descs(dbri, DBRI_STREAMNO(substream),
snd_pcm_lib_period_bytes(substream));
spin_unlock_irq(&dbri->lock);
dprintk(D_USR, "prepare audio output. %d bytes\n", info->size);
return ret;
}
static int snd_dbri_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
dprintk(D_USR, "start audio, period is %d bytes\n",
(int)snd_pcm_lib_period_bytes(substream));
xmit_descs(dbri);
break;
case SNDRV_PCM_TRIGGER_STOP:
dprintk(D_USR, "stop audio.\n");
reset_pipe(dbri, info->pipe);
break;
default:
ret = -EINVAL;
}
return ret;
}
static snd_pcm_uframes_t snd_dbri_pointer(struct snd_pcm_substream *substream)
{
struct snd_dbri *dbri = snd_pcm_substream_chip(substream);
struct dbri_streaminfo *info = DBRI_STREAM(dbri, substream);
snd_pcm_uframes_t ret;
ret = bytes_to_frames(substream->runtime, info->offset)
% substream->runtime->buffer_size;
dprintk(D_USR, "I/O pointer: %ld frames of %ld.\n",
ret, substream->runtime->buffer_size);
return ret;
}
static int snd_dbri_pcm(struct snd_card *card)
{
struct snd_pcm *pcm;
int err;
if ((err = snd_pcm_new(card,
"sun_dbri",
0,
1,
1, &pcm)) < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_dbri_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_dbri_ops);
pcm->private_data = card->private_data;
pcm->info_flags = 0;
strcpy(pcm->name, card->shortname);
if ((err = snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
64 * 1024, 64 * 1024)) < 0)
return err;
return 0;
}
static int snd_cs4215_info_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
if (kcontrol->private_value == DBRI_PLAY)
uinfo->value.integer.max = DBRI_MAX_VOLUME;
else
uinfo->value.integer.max = DBRI_MAX_GAIN;
return 0;
}
static int snd_cs4215_get_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dbri *dbri = snd_kcontrol_chip(kcontrol);
struct dbri_streaminfo *info;
if (snd_BUG_ON(!dbri))
return -EINVAL;
info = &dbri->stream_info[kcontrol->private_value];
ucontrol->value.integer.value[0] = info->left_gain;
ucontrol->value.integer.value[1] = info->right_gain;
return 0;
}
static int snd_cs4215_put_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dbri *dbri = snd_kcontrol_chip(kcontrol);
struct dbri_streaminfo *info =
&dbri->stream_info[kcontrol->private_value];
unsigned int vol[2];
int changed = 0;
vol[0] = ucontrol->value.integer.value[0];
vol[1] = ucontrol->value.integer.value[1];
if (kcontrol->private_value == DBRI_PLAY) {
if (vol[0] > DBRI_MAX_VOLUME || vol[1] > DBRI_MAX_VOLUME)
return -EINVAL;
} else {
if (vol[0] > DBRI_MAX_GAIN || vol[1] > DBRI_MAX_GAIN)
return -EINVAL;
}
if (info->left_gain != vol[0]) {
info->left_gain = vol[0];
changed = 1;
}
if (info->right_gain != vol[1]) {
info->right_gain = vol[1];
changed = 1;
}
if (changed) {
cs4215_setdata(dbri, 1);
udelay(125);
cs4215_setdata(dbri, 0);
}
return changed;
}
static int snd_cs4215_info_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = (mask == 1) ?
SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_cs4215_get_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dbri *dbri = snd_kcontrol_chip(kcontrol);
int elem = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 1;
if (snd_BUG_ON(!dbri))
return -EINVAL;
if (elem < 4)
ucontrol->value.integer.value[0] =
(dbri->mm.data[elem] >> shift) & mask;
else
ucontrol->value.integer.value[0] =
(dbri->mm.ctrl[elem - 4] >> shift) & mask;
if (invert == 1)
ucontrol->value.integer.value[0] =
mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_cs4215_put_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dbri *dbri = snd_kcontrol_chip(kcontrol);
int elem = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 1;
int changed = 0;
unsigned short val;
if (snd_BUG_ON(!dbri))
return -EINVAL;
val = (ucontrol->value.integer.value[0] & mask);
if (invert == 1)
val = mask - val;
val <<= shift;
if (elem < 4) {
dbri->mm.data[elem] = (dbri->mm.data[elem] &
~(mask << shift)) | val;
changed = (val != dbri->mm.data[elem]);
} else {
dbri->mm.ctrl[elem - 4] = (dbri->mm.ctrl[elem - 4] &
~(mask << shift)) | val;
changed = (val != dbri->mm.ctrl[elem - 4]);
}
dprintk(D_GEN, "put_single: mask=0x%x, changed=%d, "
"mixer-value=%ld, mm-value=0x%x\n",
mask, changed, ucontrol->value.integer.value[0],
dbri->mm.data[elem & 3]);
if (changed) {
cs4215_setdata(dbri, 1);
udelay(125);
cs4215_setdata(dbri, 0);
}
return changed;
}
static int snd_dbri_mixer(struct snd_card *card)
{
int idx, err;
struct snd_dbri *dbri;
if (snd_BUG_ON(!card || !card->private_data))
return -EINVAL;
dbri = card->private_data;
strcpy(card->mixername, card->shortname);
for (idx = 0; idx < ARRAY_SIZE(dbri_controls); idx++) {
err = snd_ctl_add(card,
snd_ctl_new1(&dbri_controls[idx], dbri));
if (err < 0)
return err;
}
for (idx = DBRI_REC; idx < DBRI_NO_STREAMS; idx++) {
dbri->stream_info[idx].left_gain = 0;
dbri->stream_info[idx].right_gain = 0;
}
return 0;
}
static void dbri_regs_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_dbri *dbri = entry->private_data;
snd_iprintf(buffer, "REG0: 0x%x\n", sbus_readl(dbri->regs + REG0));
snd_iprintf(buffer, "REG2: 0x%x\n", sbus_readl(dbri->regs + REG2));
snd_iprintf(buffer, "REG8: 0x%x\n", sbus_readl(dbri->regs + REG8));
snd_iprintf(buffer, "REG9: 0x%x\n", sbus_readl(dbri->regs + REG9));
}
static void dbri_debug_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_dbri *dbri = entry->private_data;
int pipe;
snd_iprintf(buffer, "debug=%d\n", dbri_debug);
for (pipe = 0; pipe < 32; pipe++) {
if (pipe_active(dbri, pipe)) {
struct dbri_pipe *pptr = &dbri->pipes[pipe];
snd_iprintf(buffer,
"Pipe %d: %s SDP=0x%x desc=%d, "
"len=%d next %d\n",
pipe,
(pptr->sdp & D_SDP_TO_SER) ? "output" :
"input",
pptr->sdp, pptr->desc,
pptr->length, pptr->nextpipe);
}
}
}
static void snd_dbri_proc(struct snd_card *card)
{
struct snd_dbri *dbri = card->private_data;
struct snd_info_entry *entry;
if (!snd_card_proc_new(card, "regs", &entry))
snd_info_set_text_ops(entry, dbri, dbri_regs_read);
#ifdef DBRI_DEBUG
if (!snd_card_proc_new(card, "debug", &entry)) {
snd_info_set_text_ops(entry, dbri, dbri_debug_read);
entry->mode = S_IFREG | S_IRUGO;
}
#endif
}
static int snd_dbri_create(struct snd_card *card,
struct platform_device *op,
int irq, int dev)
{
struct snd_dbri *dbri = card->private_data;
int err;
spin_lock_init(&dbri->lock);
dbri->op = op;
dbri->irq = irq;
dbri->dma = dma_zalloc_coherent(&op->dev, sizeof(struct dbri_dma),
&dbri->dma_dvma, GFP_ATOMIC);
if (!dbri->dma)
return -ENOMEM;
dprintk(D_GEN, "DMA Cmd Block 0x%p (0x%08x)\n",
dbri->dma, dbri->dma_dvma);
dbri->regs_size = resource_size(&op->resource[0]);
dbri->regs = of_ioremap(&op->resource[0], 0,
dbri->regs_size, "DBRI Registers");
if (!dbri->regs) {
printk(KERN_ERR "DBRI: could not allocate registers\n");
dma_free_coherent(&op->dev, sizeof(struct dbri_dma),
(void *)dbri->dma, dbri->dma_dvma);
return -EIO;
}
err = request_irq(dbri->irq, snd_dbri_interrupt, IRQF_SHARED,
"DBRI audio", dbri);
if (err) {
printk(KERN_ERR "DBRI: Can't get irq %d\n", dbri->irq);
of_iounmap(&op->resource[0], dbri->regs, dbri->regs_size);
dma_free_coherent(&op->dev, sizeof(struct dbri_dma),
(void *)dbri->dma, dbri->dma_dvma);
return err;
}
dbri_initialize(dbri);
err = cs4215_init(dbri);
if (err) {
snd_dbri_free(dbri);
return err;
}
return 0;
}
static void snd_dbri_free(struct snd_dbri *dbri)
{
dprintk(D_GEN, "snd_dbri_free\n");
dbri_reset(dbri);
if (dbri->irq)
free_irq(dbri->irq, dbri);
if (dbri->regs)
of_iounmap(&dbri->op->resource[0], dbri->regs, dbri->regs_size);
if (dbri->dma)
dma_free_coherent(&dbri->op->dev,
sizeof(struct dbri_dma),
(void *)dbri->dma, dbri->dma_dvma);
}
static int dbri_probe(struct platform_device *op)
{
struct snd_dbri *dbri;
struct resource *rp;
struct snd_card *card;
static int dev = 0;
int irq;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
irq = op->archdata.irqs[0];
if (irq <= 0) {
printk(KERN_ERR "DBRI-%d: No IRQ.\n", dev);
return -ENODEV;
}
err = snd_card_new(&op->dev, index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_dbri), &card);
if (err < 0)
return err;
strcpy(card->driver, "DBRI");
strcpy(card->shortname, "Sun DBRI");
rp = &op->resource[0];
sprintf(card->longname, "%s at 0x%02lx:0x%016Lx, irq %d",
card->shortname,
rp->flags & 0xffL, (unsigned long long)rp->start, irq);
err = snd_dbri_create(card, op, irq, dev);
if (err < 0) {
snd_card_free(card);
return err;
}
dbri = card->private_data;
err = snd_dbri_pcm(card);
if (err < 0)
goto _err;
err = snd_dbri_mixer(card);
if (err < 0)
goto _err;
snd_dbri_proc(card);
dev_set_drvdata(&op->dev, card);
err = snd_card_register(card);
if (err < 0)
goto _err;
printk(KERN_INFO "audio%d at %p (irq %d) is DBRI(%c)+CS4215(%d)\n",
dev, dbri->regs,
dbri->irq, op->dev.of_node->name[9], dbri->mm.version);
dev++;
return 0;
_err:
snd_dbri_free(dbri);
snd_card_free(card);
return err;
}
static int dbri_remove(struct platform_device *op)
{
struct snd_card *card = dev_get_drvdata(&op->dev);
snd_dbri_free(card->private_data);
snd_card_free(card);
return 0;
}
