static ssize_t q40_ct_law(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
char *table = dmasound.soft.format == AFMT_MU_LAW ? dmasound_ulaw2dma8: dmasound_alaw2dma8;
ssize_t count, used;
u_char *p = (u_char *) &frame[*frameUsed];
used = count = min_t(size_t, userCount, frameLeft);
if (copy_from_user(p,userPtr,count))
return -EFAULT;
while (count > 0) {
*p = table[*p]+128;
p++;
count--;
}
*frameUsed += used ;
return used;
}
static ssize_t q40_ct_s8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
u_char *p = (u_char *) &frame[*frameUsed];
used = count = min_t(size_t, userCount, frameLeft);
if (copy_from_user(p,userPtr,count))
return -EFAULT;
while (count > 0) {
*p = *p + 128;
p++;
count--;
}
*frameUsed += used;
return used;
}
static ssize_t q40_ct_u8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
u_char *p = (u_char *) &frame[*frameUsed];
used = count = min_t(size_t, userCount, frameLeft);
if (copy_from_user(p,userPtr,count))
return -EFAULT;
*frameUsed += used;
return used;
}
static ssize_t q40_ctx_law(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
unsigned char *table = (unsigned char *)
(dmasound.soft.format == AFMT_MU_LAW ? dmasound_ulaw2dma8: dmasound_alaw2dma8);
unsigned int data = expand_data;
u_char *p = (u_char *) &frame[*frameUsed];
int bal = expand_bal;
int hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
int utotal, ftotal;
ftotal = frameLeft;
utotal = userCount;
while (frameLeft) {
u_char c;
if (bal < 0) {
if (userCount == 0)
break;
if (get_user(c, userPtr++))
return -EFAULT;
data = table[c];
data += 0x80;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
expand_bal = bal;
expand_data = data;
*frameUsed += (ftotal - frameLeft);
utotal -= userCount;
return utotal;
}
static ssize_t q40_ctx_s8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
u_char *p = (u_char *) &frame[*frameUsed];
unsigned int data = expand_data;
int bal = expand_bal;
int hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
int utotal, ftotal;
ftotal = frameLeft;
utotal = userCount;
while (frameLeft) {
u_char c;
if (bal < 0) {
if (userCount == 0)
break;
if (get_user(c, userPtr++))
return -EFAULT;
data = c ;
data += 0x80;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
expand_bal = bal;
expand_data = data;
*frameUsed += (ftotal - frameLeft);
utotal -= userCount;
return utotal;
}
static ssize_t q40_ctx_u8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
u_char *p = (u_char *) &frame[*frameUsed];
unsigned int data = expand_data;
int bal = expand_bal;
int hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
int utotal, ftotal;
ftotal = frameLeft;
utotal = userCount;
while (frameLeft) {
u_char c;
if (bal < 0) {
if (userCount == 0)
break;
if (get_user(c, userPtr++))
return -EFAULT;
data = c ;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
expand_bal = bal;
expand_data = data;
*frameUsed += (ftotal - frameLeft) ;
utotal -= userCount;
return utotal;
}
static ssize_t q40_ctc_law(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
unsigned char *table = (unsigned char *)
(dmasound.soft.format == AFMT_MU_LAW ? dmasound_ulaw2dma8: dmasound_alaw2dma8);
unsigned int data = expand_data;
u_char *p = (u_char *) &frame[*frameUsed];
int bal = expand_bal;
int hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
int utotal, ftotal;
ftotal = frameLeft;
utotal = userCount;
while (frameLeft) {
u_char c;
while(bal<0) {
if (userCount == 0)
goto lout;
if (!(bal<(-hSpeed))) {
if (get_user(c, userPtr))
return -EFAULT;
data = 0x80 + table[c];
}
userPtr++;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
lout:
expand_bal = bal;
expand_data = data;
*frameUsed += (ftotal - frameLeft);
utotal -= userCount;
return utotal;
}
static ssize_t q40_ctc_s8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
u_char *p = (u_char *) &frame[*frameUsed];
unsigned int data = expand_data;
int bal = expand_bal;
int hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
int utotal, ftotal;
ftotal = frameLeft;
utotal = userCount;
while (frameLeft) {
u_char c;
while (bal < 0) {
if (userCount == 0)
goto lout;
if (!(bal<(-hSpeed))) {
if (get_user(c, userPtr))
return -EFAULT;
data = c + 0x80;
}
userPtr++;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
lout:
expand_bal = bal;
expand_data = data;
*frameUsed += (ftotal - frameLeft);
utotal -= userCount;
return utotal;
}
static ssize_t q40_ctc_u8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
u_char *p = (u_char *) &frame[*frameUsed];
unsigned int data = expand_data;
int bal = expand_bal;
int hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
int utotal, ftotal;
ftotal = frameLeft;
utotal = userCount;
while (frameLeft) {
u_char c;
while (bal < 0) {
if (userCount == 0)
goto lout;
if (!(bal<(-hSpeed))) {
if (get_user(c, userPtr))
return -EFAULT;
data = c ;
}
userPtr++;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
lout:
expand_bal = bal;
expand_data = data;
*frameUsed += (ftotal - frameLeft) ;
utotal -= userCount;
return utotal;
}
static void *Q40Alloc(unsigned int size, gfp_t flags)
{
return kmalloc(size, flags);
}
static void Q40Free(void *ptr, unsigned int size)
{
kfree(ptr);
}
static int __init Q40IrqInit(void)
{
if (request_irq(Q40_IRQ_SAMPLE, Q40StereoInterrupt, 0,
"DMA sound", Q40Interrupt))
return 0;
return(1);
}
static void Q40IrqCleanUp(void)
{
master_outb(0,SAMPLE_ENABLE_REG);
free_irq(Q40_IRQ_SAMPLE, Q40Interrupt);
}
static void Q40Silence(void)
{
master_outb(0,SAMPLE_ENABLE_REG);
*DAC_LEFT=*DAC_RIGHT=127;
}
static void Q40PlayNextFrame(int index)
{
u_char *start;
u_long size;
u_char speed;
int error;
start = write_sq.buffers[write_sq.front];
size = (write_sq.count == index ? write_sq.rear_size : write_sq.block_size);
q40_pp=start;
q40_sc=size;
write_sq.front = (write_sq.front+1) % write_sq.max_count;
write_sq.active++;
speed=(dmasound.hard.speed==10000 ? 0 : 1);
master_outb( 0,SAMPLE_ENABLE_REG);
free_irq(Q40_IRQ_SAMPLE, Q40Interrupt);
if (dmasound.soft.stereo)
error = request_irq(Q40_IRQ_SAMPLE, Q40StereoInterrupt, 0,
"Q40 sound", Q40Interrupt);
else
error = request_irq(Q40_IRQ_SAMPLE, Q40MonoInterrupt, 0,
"Q40 sound", Q40Interrupt);
if (error && printk_ratelimit())
pr_err("Couldn't register sound interrupt\n");
master_outb( speed, SAMPLE_RATE_REG);
master_outb( 1,SAMPLE_CLEAR_REG);
master_outb( 1,SAMPLE_ENABLE_REG);
}
static void Q40Play(void)
{
unsigned long flags;
if (write_sq.active || write_sq.count<=0 ) {
return;
}
if (write_sq.count <= 1 && write_sq.rear_size < write_sq.block_size && !write_sq.syncing) {
return;
}
spin_lock_irqsave(&dmasound.lock, flags);
Q40PlayNextFrame(1);
spin_unlock_irqrestore(&dmasound.lock, flags);
}
static irqreturn_t Q40StereoInterrupt(int irq, void *dummy)
{
spin_lock(&dmasound.lock);
if (q40_sc>1){
*DAC_LEFT=*q40_pp++;
*DAC_RIGHT=*q40_pp++;
q40_sc -=2;
master_outb(1,SAMPLE_CLEAR_REG);
}else Q40Interrupt();
spin_unlock(&dmasound.lock);
return IRQ_HANDLED;
}
static irqreturn_t Q40MonoInterrupt(int irq, void *dummy)
{
spin_lock(&dmasound.lock);
if (q40_sc>0){
*DAC_LEFT=*q40_pp;
*DAC_RIGHT=*q40_pp++;
q40_sc --;
master_outb(1,SAMPLE_CLEAR_REG);
}else Q40Interrupt();
spin_unlock(&dmasound.lock);
return IRQ_HANDLED;
}
static void Q40Interrupt(void)
{
if (!write_sq.active) {
WAKE_UP(write_sq.sync_queue);
master_outb(0,SAMPLE_ENABLE_REG);
goto exit;
} else write_sq.active=0;
write_sq.count--;
Q40Play();
if (q40_sc<2)
{
master_outb(0,SAMPLE_ENABLE_REG);
*DAC_LEFT=*DAC_RIGHT=127;
}
WAKE_UP(write_sq.action_queue);
exit:
master_outb(1,SAMPLE_CLEAR_REG);
}
static void Q40Init(void)
{
int i, idx;
const int freq[] = {10000, 20000};
idx = -1;
for (i = 0; i < 2; i++)
if ((100 * abs(dmasound.soft.speed - freq[i]) / freq[i]) <= catchRadius)
idx = i;
dmasound.hard = dmasound.soft;
dmasound.hard.size=8;
if (idx > -1) {
dmasound.soft.speed = freq[idx];
dmasound.trans_write = &transQ40Normal;
} else
dmasound.trans_write = &transQ40Expanding;
Q40Silence();
if (dmasound.hard.speed > 20200) {
dmasound.hard.speed = 20000;
dmasound.trans_write = &transQ40Compressing;
} else if (dmasound.hard.speed > 10000) {
dmasound.hard.speed = 20000;
} else {
dmasound.hard.speed = 10000;
}
expand_bal = -dmasound.soft.speed;
}
static int Q40SetFormat(int format)
{
switch (format) {
case AFMT_QUERY:
return(dmasound.soft.format);
case AFMT_MU_LAW:
case AFMT_A_LAW:
case AFMT_S8:
case AFMT_U8:
break;
default:
format = AFMT_S8;
}
dmasound.soft.format = format;
dmasound.soft.size = 8;
if (dmasound.minDev == SND_DEV_DSP) {
dmasound.dsp.format = format;
dmasound.dsp.size = 8;
}
Q40Init();
return(format);
}
static int Q40SetVolume(int volume)
{
return 0;
}
static int __init dmasound_q40_init(void)
{
if (MACH_IS_Q40) {
dmasound.mach = machQ40;
dmasound.mach.default_hard = def_hard ;
dmasound.mach.default_soft = def_soft ;
return dmasound_init();
} else
return -ENODEV;
}
static void __exit dmasound_q40_cleanup(void)
{
dmasound_deinit();
}
