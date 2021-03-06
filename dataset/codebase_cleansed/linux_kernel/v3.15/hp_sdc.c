static inline uint8_t hp_sdc_status_in8(void)
{
uint8_t status;
unsigned long flags;
write_lock_irqsave(&hp_sdc.ibf_lock, flags);
status = sdc_readb(hp_sdc.status_io);
if (!(status & HP_SDC_STATUS_IBF))
hp_sdc.ibf = 0;
write_unlock_irqrestore(&hp_sdc.ibf_lock, flags);
return status;
}
static inline uint8_t hp_sdc_data_in8(void)
{
return sdc_readb(hp_sdc.data_io);
}
static inline void hp_sdc_status_out8(uint8_t val)
{
unsigned long flags;
write_lock_irqsave(&hp_sdc.ibf_lock, flags);
hp_sdc.ibf = 1;
if ((val & 0xf0) == 0xe0)
hp_sdc.wi = 0xff;
sdc_writeb(val, hp_sdc.status_io);
write_unlock_irqrestore(&hp_sdc.ibf_lock, flags);
}
static inline void hp_sdc_data_out8(uint8_t val)
{
unsigned long flags;
write_lock_irqsave(&hp_sdc.ibf_lock, flags);
hp_sdc.ibf = 1;
sdc_writeb(val, hp_sdc.data_io);
write_unlock_irqrestore(&hp_sdc.ibf_lock, flags);
}
static inline void hp_sdc_spin_ibf(void)
{
unsigned long flags;
rwlock_t *lock;
lock = &hp_sdc.ibf_lock;
read_lock_irqsave(lock, flags);
if (!hp_sdc.ibf) {
read_unlock_irqrestore(lock, flags);
return;
}
read_unlock(lock);
write_lock(lock);
while (sdc_readb(hp_sdc.status_io) & HP_SDC_STATUS_IBF)
{ }
hp_sdc.ibf = 0;
write_unlock_irqrestore(lock, flags);
}
static void hp_sdc_take(int irq, void *dev_id, uint8_t status, uint8_t data)
{
hp_sdc_transaction *curr;
read_lock(&hp_sdc.rtq_lock);
if (hp_sdc.rcurr < 0) {
read_unlock(&hp_sdc.rtq_lock);
return;
}
curr = hp_sdc.tq[hp_sdc.rcurr];
read_unlock(&hp_sdc.rtq_lock);
curr->seq[curr->idx++] = status;
curr->seq[curr->idx++] = data;
hp_sdc.rqty -= 2;
do_gettimeofday(&hp_sdc.rtv);
if (hp_sdc.rqty <= 0) {
if (curr->seq[curr->actidx] & HP_SDC_ACT_SEMAPHORE)
if (curr->act.semaphore)
up(curr->act.semaphore);
if (curr->seq[curr->actidx] & HP_SDC_ACT_CALLBACK)
if (curr->act.irqhook)
curr->act.irqhook(irq, dev_id, status, data);
curr->actidx = curr->idx;
curr->idx++;
write_lock(&hp_sdc.rtq_lock);
hp_sdc.rcurr = -1;
hp_sdc.rqty = 0;
write_unlock(&hp_sdc.rtq_lock);
tasklet_schedule(&hp_sdc.task);
}
}
static irqreturn_t hp_sdc_isr(int irq, void *dev_id)
{
uint8_t status, data;
status = hp_sdc_status_in8();
data = hp_sdc_data_in8();
if (((status & 0xf1) == 0x51) && data == 0x82)
return IRQ_HANDLED;
switch (status & HP_SDC_STATUS_IRQMASK) {
case 0:
break;
case HP_SDC_STATUS_USERTIMER:
case HP_SDC_STATUS_PERIODIC:
case HP_SDC_STATUS_TIMER:
read_lock(&hp_sdc.hook_lock);
if (hp_sdc.timer != NULL)
hp_sdc.timer(irq, dev_id, status, data);
read_unlock(&hp_sdc.hook_lock);
break;
case HP_SDC_STATUS_REG:
hp_sdc_take(irq, dev_id, status, data);
break;
case HP_SDC_STATUS_HILCMD:
case HP_SDC_STATUS_HILDATA:
read_lock(&hp_sdc.hook_lock);
if (hp_sdc.hil != NULL)
hp_sdc.hil(irq, dev_id, status, data);
read_unlock(&hp_sdc.hook_lock);
break;
case HP_SDC_STATUS_PUP:
read_lock(&hp_sdc.hook_lock);
if (hp_sdc.pup != NULL)
hp_sdc.pup(irq, dev_id, status, data);
else
printk(KERN_INFO PREFIX "HP SDC reports successful PUP.\n");
read_unlock(&hp_sdc.hook_lock);
break;
default:
read_lock(&hp_sdc.hook_lock);
if (hp_sdc.cooked != NULL)
hp_sdc.cooked(irq, dev_id, status, data);
read_unlock(&hp_sdc.hook_lock);
break;
}
return IRQ_HANDLED;
}
static irqreturn_t hp_sdc_nmisr(int irq, void *dev_id)
{
int status;
status = hp_sdc_status_in8();
printk(KERN_WARNING PREFIX "NMI !\n");
#if 0
if (status & HP_SDC_NMISTATUS_FHS) {
read_lock(&hp_sdc.hook_lock);
if (hp_sdc.timer != NULL)
hp_sdc.timer(irq, dev_id, status, 0);
read_unlock(&hp_sdc.hook_lock);
} else {
printk(KERN_WARNING PREFIX "HIL NMI\n");
}
#endif
return IRQ_HANDLED;
}
static void hp_sdc_tasklet(unsigned long foo)
{
write_lock_irq(&hp_sdc.rtq_lock);
if (hp_sdc.rcurr >= 0) {
struct timeval tv;
do_gettimeofday(&tv);
if (tv.tv_sec > hp_sdc.rtv.tv_sec)
tv.tv_usec += USEC_PER_SEC;
if (tv.tv_usec - hp_sdc.rtv.tv_usec > HP_SDC_MAX_REG_DELAY) {
hp_sdc_transaction *curr;
uint8_t tmp;
curr = hp_sdc.tq[hp_sdc.rcurr];
printk(KERN_WARNING PREFIX "read timeout (%ius)!\n",
(int)(tv.tv_usec - hp_sdc.rtv.tv_usec));
curr->idx += hp_sdc.rqty;
hp_sdc.rqty = 0;
tmp = curr->seq[curr->actidx];
curr->seq[curr->actidx] |= HP_SDC_ACT_DEAD;
if (tmp & HP_SDC_ACT_SEMAPHORE)
if (curr->act.semaphore)
up(curr->act.semaphore);
if (tmp & HP_SDC_ACT_CALLBACK) {
if (curr->act.irqhook)
curr->act.irqhook(0, NULL, 0, 0);
}
curr->actidx = curr->idx;
curr->idx++;
hp_sdc.rcurr = -1;
}
}
write_unlock_irq(&hp_sdc.rtq_lock);
hp_sdc_put();
}
unsigned long hp_sdc_put(void)
{
hp_sdc_transaction *curr;
uint8_t act;
int idx, curridx;
int limit = 0;
write_lock(&hp_sdc.lock);
if (hp_sdc.ibf) {
hp_sdc_status_in8();
if (hp_sdc.ibf)
goto finish;
}
anew:
if (hp_sdc.wcurr < 0)
hp_sdc.wcurr = 0;
read_lock_irq(&hp_sdc.rtq_lock);
if (hp_sdc.rcurr == hp_sdc.wcurr)
hp_sdc.wcurr++;
read_unlock_irq(&hp_sdc.rtq_lock);
if (hp_sdc.wcurr >= HP_SDC_QUEUE_LEN)
hp_sdc.wcurr = 0;
curridx = hp_sdc.wcurr;
if (hp_sdc.tq[curridx] != NULL)
goto start;
while (++curridx != hp_sdc.wcurr) {
if (curridx >= HP_SDC_QUEUE_LEN) {
curridx = -1;
continue;
}
read_lock_irq(&hp_sdc.rtq_lock);
if (hp_sdc.rcurr == curridx) {
read_unlock_irq(&hp_sdc.rtq_lock);
continue;
}
read_unlock_irq(&hp_sdc.rtq_lock);
if (hp_sdc.tq[curridx] != NULL)
break;
}
if (curridx == hp_sdc.wcurr) {
curridx = -1;
}
hp_sdc.wcurr = curridx;
start:
if (hp_sdc.set_im) {
hp_sdc_status_out8(hp_sdc.im | HP_SDC_CMD_SET_IM);
hp_sdc.set_im = 0;
goto finish;
}
if (hp_sdc.wcurr == -1)
goto done;
curr = hp_sdc.tq[curridx];
idx = curr->actidx;
if (curr->actidx >= curr->endidx) {
hp_sdc.tq[curridx] = NULL;
hp_sdc.wcurr++;
if (hp_sdc.wcurr >= HP_SDC_QUEUE_LEN)
hp_sdc.wcurr = 0;
goto finish;
}
act = curr->seq[idx];
idx++;
if (curr->idx >= curr->endidx) {
if (act & HP_SDC_ACT_DEALLOC)
kfree(curr);
hp_sdc.tq[curridx] = NULL;
hp_sdc.wcurr++;
if (hp_sdc.wcurr >= HP_SDC_QUEUE_LEN)
hp_sdc.wcurr = 0;
goto finish;
}
while (act & HP_SDC_ACT_PRECMD) {
if (curr->idx != idx) {
idx++;
act &= ~HP_SDC_ACT_PRECMD;
break;
}
hp_sdc_status_out8(curr->seq[idx]);
curr->idx++;
if ((act & HP_SDC_ACT_DURING) == HP_SDC_ACT_PRECMD)
goto actdone;
if (act & HP_SDC_ACT_DATAOUT)
curr->idx++;
goto finish;
}
if (act & HP_SDC_ACT_DATAOUT) {
int qty;
qty = curr->seq[idx];
idx++;
if (curr->idx - idx < qty) {
hp_sdc_data_out8(curr->seq[curr->idx]);
curr->idx++;
if (curr->idx - idx >= qty &&
(act & HP_SDC_ACT_DURING) == HP_SDC_ACT_DATAOUT)
goto actdone;
goto finish;
}
idx += qty;
act &= ~HP_SDC_ACT_DATAOUT;
} else
while (act & HP_SDC_ACT_DATAREG) {
int mask;
uint8_t w7[4];
mask = curr->seq[idx];
if (idx != curr->idx) {
idx++;
idx += !!(mask & 1);
idx += !!(mask & 2);
idx += !!(mask & 4);
idx += !!(mask & 8);
act &= ~HP_SDC_ACT_DATAREG;
break;
}
w7[0] = (mask & 1) ? curr->seq[++idx] : hp_sdc.r7[0];
w7[1] = (mask & 2) ? curr->seq[++idx] : hp_sdc.r7[1];
w7[2] = (mask & 4) ? curr->seq[++idx] : hp_sdc.r7[2];
w7[3] = (mask & 8) ? curr->seq[++idx] : hp_sdc.r7[3];
if (hp_sdc.wi > 0x73 || hp_sdc.wi < 0x70 ||
w7[hp_sdc.wi - 0x70] == hp_sdc.r7[hp_sdc.wi - 0x70]) {
int i = 0;
while (i < 4 && w7[i] == hp_sdc.r7[i])
i++;
if (i < 4) {
hp_sdc_status_out8(HP_SDC_CMD_SET_D0 + i);
hp_sdc.wi = 0x70 + i;
goto finish;
}
idx++;
if ((act & HP_SDC_ACT_DURING) == HP_SDC_ACT_DATAREG)
goto actdone;
curr->idx = idx;
act &= ~HP_SDC_ACT_DATAREG;
break;
}
hp_sdc_data_out8(w7[hp_sdc.wi - 0x70]);
hp_sdc.r7[hp_sdc.wi - 0x70] = w7[hp_sdc.wi - 0x70];
hp_sdc.wi++;
{
int i = 0;
while ((i < 4) && w7[i] == hp_sdc.r7[i])
i++;
if (i >= 4) {
curr->idx = idx + 1;
if ((act & HP_SDC_ACT_DURING) ==
HP_SDC_ACT_DATAREG)
goto actdone;
}
}
goto finish;
}
read_lock_irq(&hp_sdc.rtq_lock);
if (hp_sdc.rcurr >= 0) {
read_unlock_irq(&hp_sdc.rtq_lock);
goto finish;
}
read_unlock_irq(&hp_sdc.rtq_lock);
if (act & HP_SDC_ACT_POSTCMD) {
uint8_t postcmd;
postcmd = curr->seq[idx];
curr->idx++;
if (act & HP_SDC_ACT_DATAIN) {
hp_sdc.rqty = curr->seq[curr->idx];
do_gettimeofday(&hp_sdc.rtv);
curr->idx++;
write_lock_irq(&hp_sdc.rtq_lock);
hp_sdc.rcurr = curridx;
write_unlock_irq(&hp_sdc.rtq_lock);
hp_sdc_status_out8(postcmd);
goto finish;
}
hp_sdc_status_out8(postcmd);
goto actdone;
}
actdone:
if (act & HP_SDC_ACT_SEMAPHORE)
up(curr->act.semaphore);
else if (act & HP_SDC_ACT_CALLBACK)
curr->act.irqhook(0,NULL,0,0);
if (curr->idx >= curr->endidx) {
if (act & HP_SDC_ACT_DEALLOC)
kfree(curr);
hp_sdc.tq[curridx] = NULL;
} else {
curr->actidx = idx + 1;
curr->idx = idx + 2;
}
hp_sdc.wcurr++;
if (hp_sdc.wcurr >= HP_SDC_QUEUE_LEN)
hp_sdc.wcurr = 0;
finish:
if (!hp_sdc.ibf && limit++ < 20)
goto anew;
done:
if (hp_sdc.wcurr >= 0)
tasklet_schedule(&hp_sdc.task);
write_unlock(&hp_sdc.lock);
return 0;
}
int __hp_sdc_enqueue_transaction(hp_sdc_transaction *this)
{
int i;
if (this == NULL) {
BUG();
return -EINVAL;
}
for (i = 0; i < HP_SDC_QUEUE_LEN; i++)
if (hp_sdc.tq[i] == this)
goto fail;
this->actidx = 0;
this->idx = 1;
for (i = 0; i < HP_SDC_QUEUE_LEN; i++)
if (hp_sdc.tq[i] == NULL) {
hp_sdc.tq[i] = this;
tasklet_schedule(&hp_sdc.task);
return 0;
}
printk(KERN_WARNING PREFIX "No free slot to add transaction.\n");
return -EBUSY;
fail:
printk(KERN_WARNING PREFIX "Transaction add failed: transaction already queued?\n");
return -EINVAL;
}
int hp_sdc_enqueue_transaction(hp_sdc_transaction *this) {
unsigned long flags;
int ret;
write_lock_irqsave(&hp_sdc.lock, flags);
ret = __hp_sdc_enqueue_transaction(this);
write_unlock_irqrestore(&hp_sdc.lock,flags);
return ret;
}
int hp_sdc_dequeue_transaction(hp_sdc_transaction *this)
{
unsigned long flags;
int i;
write_lock_irqsave(&hp_sdc.lock, flags);
for (i = 0; i < HP_SDC_QUEUE_LEN; i++)
if (hp_sdc.tq[i] == this)
hp_sdc.tq[i] = NULL;
write_unlock_irqrestore(&hp_sdc.lock, flags);
return 0;
}
int hp_sdc_request_timer_irq(hp_sdc_irqhook *callback)
{
if (callback == NULL || hp_sdc.dev == NULL)
return -EINVAL;
write_lock_irq(&hp_sdc.hook_lock);
if (hp_sdc.timer != NULL) {
write_unlock_irq(&hp_sdc.hook_lock);
return -EBUSY;
}
hp_sdc.timer = callback;
hp_sdc.im &= ~HP_SDC_IM_FH;
hp_sdc.im &= ~HP_SDC_IM_PT;
hp_sdc.im &= ~HP_SDC_IM_TIMERS;
hp_sdc.set_im = 1;
write_unlock_irq(&hp_sdc.hook_lock);
tasklet_schedule(&hp_sdc.task);
return 0;
}
int hp_sdc_request_hil_irq(hp_sdc_irqhook *callback)
{
if (callback == NULL || hp_sdc.dev == NULL)
return -EINVAL;
write_lock_irq(&hp_sdc.hook_lock);
if (hp_sdc.hil != NULL) {
write_unlock_irq(&hp_sdc.hook_lock);
return -EBUSY;
}
hp_sdc.hil = callback;
hp_sdc.im &= ~(HP_SDC_IM_HIL | HP_SDC_IM_RESET);
hp_sdc.set_im = 1;
write_unlock_irq(&hp_sdc.hook_lock);
tasklet_schedule(&hp_sdc.task);
return 0;
}
int hp_sdc_request_cooked_irq(hp_sdc_irqhook *callback)
{
if (callback == NULL || hp_sdc.dev == NULL)
return -EINVAL;
write_lock_irq(&hp_sdc.hook_lock);
if (hp_sdc.cooked != NULL) {
write_unlock_irq(&hp_sdc.hook_lock);
return -EBUSY;
}
hp_sdc.cooked = callback;
hp_sdc.im &= ~(HP_SDC_IM_HIL | HP_SDC_IM_RESET);
hp_sdc.set_im = 1;
write_unlock_irq(&hp_sdc.hook_lock);
tasklet_schedule(&hp_sdc.task);
return 0;
}
int hp_sdc_release_timer_irq(hp_sdc_irqhook *callback)
{
write_lock_irq(&hp_sdc.hook_lock);
if ((callback != hp_sdc.timer) ||
(hp_sdc.timer == NULL)) {
write_unlock_irq(&hp_sdc.hook_lock);
return -EINVAL;
}
hp_sdc.timer = NULL;
hp_sdc.im |= HP_SDC_IM_TIMERS;
hp_sdc.im |= HP_SDC_IM_FH;
hp_sdc.im |= HP_SDC_IM_PT;
hp_sdc.set_im = 1;
write_unlock_irq(&hp_sdc.hook_lock);
tasklet_schedule(&hp_sdc.task);
return 0;
}
int hp_sdc_release_hil_irq(hp_sdc_irqhook *callback)
{
write_lock_irq(&hp_sdc.hook_lock);
if ((callback != hp_sdc.hil) ||
(hp_sdc.hil == NULL)) {
write_unlock_irq(&hp_sdc.hook_lock);
return -EINVAL;
}
hp_sdc.hil = NULL;
if(hp_sdc.cooked == NULL) {
hp_sdc.im |= (HP_SDC_IM_HIL | HP_SDC_IM_RESET);
hp_sdc.set_im = 1;
}
write_unlock_irq(&hp_sdc.hook_lock);
tasklet_schedule(&hp_sdc.task);
return 0;
}
int hp_sdc_release_cooked_irq(hp_sdc_irqhook *callback)
{
write_lock_irq(&hp_sdc.hook_lock);
if ((callback != hp_sdc.cooked) ||
(hp_sdc.cooked == NULL)) {
write_unlock_irq(&hp_sdc.hook_lock);
return -EINVAL;
}
hp_sdc.cooked = NULL;
if(hp_sdc.hil == NULL) {
hp_sdc.im |= (HP_SDC_IM_HIL | HP_SDC_IM_RESET);
hp_sdc.set_im = 1;
}
write_unlock_irq(&hp_sdc.hook_lock);
tasklet_schedule(&hp_sdc.task);
return 0;
}
static void hp_sdc_kicker(unsigned long data)
{
tasklet_schedule(&hp_sdc.task);
mod_timer(&hp_sdc.kicker, jiffies + HZ);
}
static int __init hp_sdc_init(void)
{
char *errstr;
hp_sdc_transaction t_sync;
uint8_t ts_sync[6];
struct semaphore s_sync;
rwlock_init(&hp_sdc.lock);
rwlock_init(&hp_sdc.ibf_lock);
rwlock_init(&hp_sdc.rtq_lock);
rwlock_init(&hp_sdc.hook_lock);
hp_sdc.timer = NULL;
hp_sdc.hil = NULL;
hp_sdc.pup = NULL;
hp_sdc.cooked = NULL;
hp_sdc.im = HP_SDC_IM_MASK;
hp_sdc.set_im = 1;
hp_sdc.wi = 0xff;
hp_sdc.r7[0] = 0xff;
hp_sdc.r7[1] = 0xff;
hp_sdc.r7[2] = 0xff;
hp_sdc.r7[3] = 0xff;
hp_sdc.ibf = 1;
memset(&hp_sdc.tq, 0, sizeof(hp_sdc.tq));
hp_sdc.wcurr = -1;
hp_sdc.rcurr = -1;
hp_sdc.rqty = 0;
hp_sdc.dev_err = -ENODEV;
errstr = "IO not found for";
if (!hp_sdc.base_io)
goto err0;
errstr = "IRQ not found for";
if (!hp_sdc.irq)
goto err0;
hp_sdc.dev_err = -EBUSY;
#if defined(__hppa__)
errstr = "IO not available for";
if (request_region(hp_sdc.data_io, 2, hp_sdc_driver.name))
goto err0;
#endif
errstr = "IRQ not available for";
if (request_irq(hp_sdc.irq, &hp_sdc_isr, IRQF_SHARED,
"HP SDC", &hp_sdc))
goto err1;
errstr = "NMI not available for";
if (request_irq(hp_sdc.nmi, &hp_sdc_nmisr, IRQF_SHARED,
"HP SDC NMI", &hp_sdc))
goto err2;
printk(KERN_INFO PREFIX "HP SDC at 0x%p, IRQ %d (NMI IRQ %d)\n",
(void *)hp_sdc.base_io, hp_sdc.irq, hp_sdc.nmi);
hp_sdc_status_in8();
hp_sdc_data_in8();
tasklet_init(&hp_sdc.task, hp_sdc_tasklet, 0);
t_sync.actidx = 0;
t_sync.idx = 1;
t_sync.endidx = 6;
t_sync.seq = ts_sync;
ts_sync[0] = HP_SDC_ACT_DATAREG | HP_SDC_ACT_SEMAPHORE;
ts_sync[1] = 0x0f;
ts_sync[2] = ts_sync[3] = ts_sync[4] = ts_sync[5] = 0;
t_sync.act.semaphore = &s_sync;
sema_init(&s_sync, 0);
hp_sdc_enqueue_transaction(&t_sync);
down(&s_sync);
init_timer(&hp_sdc.kicker);
hp_sdc.kicker.expires = jiffies + HZ;
hp_sdc.kicker.function = &hp_sdc_kicker;
add_timer(&hp_sdc.kicker);
hp_sdc.dev_err = 0;
return 0;
err2:
free_irq(hp_sdc.irq, &hp_sdc);
err1:
release_region(hp_sdc.data_io, 2);
err0:
printk(KERN_WARNING PREFIX ": %s SDC IO=0x%p IRQ=0x%x NMI=0x%x\n",
errstr, (void *)hp_sdc.base_io, hp_sdc.irq, hp_sdc.nmi);
hp_sdc.dev = NULL;
return hp_sdc.dev_err;
}
static void request_module_delayed(struct work_struct *work)
{
request_module("hp_sdc_mlc");
}
static int __init hp_sdc_init_hppa(struct parisc_device *d)
{
int ret;
if (!d)
return 1;
if (hp_sdc.dev != NULL)
return 1;
hp_sdc.dev = d;
hp_sdc.irq = d->irq;
hp_sdc.nmi = d->aux_irq;
hp_sdc.base_io = d->hpa.start;
hp_sdc.data_io = d->hpa.start + 0x800;
hp_sdc.status_io = d->hpa.start + 0x801;
INIT_DELAYED_WORK(&moduleloader_work, request_module_delayed);
ret = hp_sdc_init();
if (!ret)
schedule_delayed_work(&moduleloader_work,
msecs_to_jiffies(2000));
return ret;
}
static void hp_sdc_exit(void)
{
if (!hp_sdc.dev)
return;
write_lock_irq(&hp_sdc.lock);
hp_sdc_spin_ibf();
sdc_writeb(HP_SDC_CMD_SET_IM | HP_SDC_IM_MASK, hp_sdc.status_io);
hp_sdc_spin_ibf();
free_irq(hp_sdc.nmi, &hp_sdc);
free_irq(hp_sdc.irq, &hp_sdc);
write_unlock_irq(&hp_sdc.lock);
del_timer_sync(&hp_sdc.kicker);
tasklet_kill(&hp_sdc.task);
#if defined(__hppa__)
cancel_delayed_work_sync(&moduleloader_work);
if (unregister_parisc_driver(&hp_sdc_driver))
printk(KERN_WARNING PREFIX "Error unregistering HP SDC");
#endif
}
static int __init hp_sdc_register(void)
{
hp_sdc_transaction tq_init;
uint8_t tq_init_seq[5];
struct semaphore tq_init_sem;
#if defined(__mc68000__)
mm_segment_t fs;
unsigned char i;
#endif
if (hp_sdc_disabled) {
printk(KERN_WARNING PREFIX "HP SDC driver disabled by no_hpsdc=1.\n");
return -ENODEV;
}
hp_sdc.dev = NULL;
hp_sdc.dev_err = 0;
#if defined(__hppa__)
if (register_parisc_driver(&hp_sdc_driver)) {
printk(KERN_WARNING PREFIX "Error registering SDC with system bus tree.\n");
return -ENODEV;
}
#elif defined(__mc68000__)
if (!MACH_IS_HP300)
return -ENODEV;
hp_sdc.irq = 1;
hp_sdc.nmi = 7;
hp_sdc.base_io = (unsigned long) 0xf0428000;
hp_sdc.data_io = (unsigned long) hp_sdc.base_io + 1;
hp_sdc.status_io = (unsigned long) hp_sdc.base_io + 3;
fs = get_fs();
set_fs(KERNEL_DS);
if (!get_user(i, (unsigned char *)hp_sdc.data_io))
hp_sdc.dev = (void *)1;
set_fs(fs);
hp_sdc.dev_err = hp_sdc_init();
#endif
if (hp_sdc.dev == NULL) {
printk(KERN_WARNING PREFIX "No SDC found.\n");
return hp_sdc.dev_err;
}
sema_init(&tq_init_sem, 0);
tq_init.actidx = 0;
tq_init.idx = 1;
tq_init.endidx = 5;
tq_init.seq = tq_init_seq;
tq_init.act.semaphore = &tq_init_sem;
tq_init_seq[0] =
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN | HP_SDC_ACT_SEMAPHORE;
tq_init_seq[1] = HP_SDC_CMD_READ_KCC;
tq_init_seq[2] = 1;
tq_init_seq[3] = 0;
tq_init_seq[4] = 0;
hp_sdc_enqueue_transaction(&tq_init);
down(&tq_init_sem);
up(&tq_init_sem);
if ((tq_init_seq[0] & HP_SDC_ACT_DEAD) == HP_SDC_ACT_DEAD) {
printk(KERN_WARNING PREFIX "Error reading config byte.\n");
hp_sdc_exit();
return -ENODEV;
}
hp_sdc.r11 = tq_init_seq[4];
if (hp_sdc.r11 & HP_SDC_CFG_NEW) {
const char *str;
printk(KERN_INFO PREFIX "New style SDC\n");
tq_init_seq[1] = HP_SDC_CMD_READ_XTD;
tq_init.actidx = 0;
tq_init.idx = 1;
down(&tq_init_sem);
hp_sdc_enqueue_transaction(&tq_init);
down(&tq_init_sem);
up(&tq_init_sem);
if ((tq_init_seq[0] & HP_SDC_ACT_DEAD) == HP_SDC_ACT_DEAD) {
printk(KERN_WARNING PREFIX "Error reading extended config byte.\n");
return -ENODEV;
}
hp_sdc.r7e = tq_init_seq[4];
HP_SDC_XTD_REV_STRINGS(hp_sdc.r7e & HP_SDC_XTD_REV, str)
printk(KERN_INFO PREFIX "Revision: %s\n", str);
if (hp_sdc.r7e & HP_SDC_XTD_BEEPER)
printk(KERN_INFO PREFIX "TI SN76494 beeper present\n");
if (hp_sdc.r7e & HP_SDC_XTD_BBRTC)
printk(KERN_INFO PREFIX "OKI MSM-58321 BBRTC present\n");
printk(KERN_INFO PREFIX "Spunking the self test register to force PUP "
"on next firmware reset.\n");
tq_init_seq[0] = HP_SDC_ACT_PRECMD |
HP_SDC_ACT_DATAOUT | HP_SDC_ACT_SEMAPHORE;
tq_init_seq[1] = HP_SDC_CMD_SET_STR;
tq_init_seq[2] = 1;
tq_init_seq[3] = 0;
tq_init.actidx = 0;
tq_init.idx = 1;
tq_init.endidx = 4;
down(&tq_init_sem);
hp_sdc_enqueue_transaction(&tq_init);
down(&tq_init_sem);
up(&tq_init_sem);
} else
printk(KERN_INFO PREFIX "Old style SDC (1820-%s).\n",
(hp_sdc.r11 & HP_SDC_CFG_REV) ? "3300" : "2564/3087");
return 0;
}
