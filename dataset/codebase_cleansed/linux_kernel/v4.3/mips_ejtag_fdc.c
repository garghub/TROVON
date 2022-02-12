static inline void mips_ejtag_fdc_write(struct mips_ejtag_fdc_tty *priv,
unsigned int offs, unsigned int data)
{
__raw_writel(data, priv->reg + offs);
}
static inline unsigned int mips_ejtag_fdc_read(struct mips_ejtag_fdc_tty *priv,
unsigned int offs)
{
return __raw_readl(priv->reg + offs);
}
static struct fdc_word mips_ejtag_fdc_encode(const char **ptrs,
unsigned int *sizes,
unsigned int ranges)
{
struct fdc_word word = { 0, 0 };
const char **ptrs_end = ptrs + ranges;
for (; ptrs < ptrs_end; ++ptrs) {
const char *ptr = *(ptrs++);
const char *end = ptr + *(sizes++);
for (; ptr < end; ++ptr) {
word.word |= (u8)*ptr << (8*word.bytes);
++word.bytes;
if (word.bytes == 4)
goto done;
}
}
done:
switch (word.bytes) {
case 4:
if ((word.word >> 8) != 0x808080 &&
(word.word >> 16) != 0x8181 &&
(word.word >> 24) != 0x82)
break;
word.bytes = 3;
word.word &= 0x00ffffff;
case 3:
word.word |= 0x82000000;
break;
case 2:
word.word |= 0x81810000;
break;
case 1:
word.word |= 0x80808000;
break;
}
return word;
}
static unsigned int mips_ejtag_fdc_decode(u32 word, char *buf)
{
buf[0] = (u8)word;
word >>= 8;
if (word == 0x808080)
return 1;
buf[1] = (u8)word;
word >>= 8;
if (word == 0x8181)
return 2;
buf[2] = (u8)word;
word >>= 8;
if (word == 0x82)
return 3;
buf[3] = (u8)word;
return 4;
}
static void mips_ejtag_fdc_console_write(struct console *c, const char *s,
unsigned int count)
{
struct mips_ejtag_fdc_console *cons =
container_of(c, struct mips_ejtag_fdc_console, cons);
void __iomem *regs;
struct fdc_word word;
unsigned long flags;
unsigned int i, buf_len, cpu;
bool done_cr = false;
char buf[4];
const char *buf_ptr = buf;
u8 inc[4];
local_irq_save(flags);
cpu = smp_processor_id();
regs = cons->regs[cpu];
if (!regs) {
regs = mips_cdmm_early_probe(0xfd);
cons->regs[cpu] = regs;
}
if (IS_ERR(regs))
goto out;
while (count) {
for (buf_len = 0, i = 0; buf_len < 4 && i < count; ++buf_len) {
if (s[i] == '\n' && !done_cr) {
buf[buf_len] = '\r';
done_cr = true;
} else {
buf[buf_len] = s[i];
done_cr = false;
++i;
}
inc[buf_len] = i;
}
word = mips_ejtag_fdc_encode(&buf_ptr, &buf_len, 1);
count -= inc[word.bytes - 1];
s += inc[word.bytes - 1];
while (__raw_readl(regs + REG_FDSTAT) & REG_FDSTAT_TXF)
;
__raw_writel(word.word, regs + REG_FDTX(c->index));
}
out:
local_irq_restore(flags);
}
static struct tty_driver *mips_ejtag_fdc_console_device(struct console *c,
int *index)
{
struct mips_ejtag_fdc_console *cons =
container_of(c, struct mips_ejtag_fdc_console, cons);
*index = c->index;
return cons->tty_drv;
}
static int __init mips_ejtag_fdc_console_init(struct mips_ejtag_fdc_console *c)
{
void __iomem *regs;
unsigned long flags;
int ret = 0;
raw_spin_lock_irqsave(&c->lock, flags);
if (c->initialised)
goto out;
regs = mips_cdmm_early_probe(0xfd);
if (IS_ERR(regs)) {
ret = PTR_ERR(regs);
goto out;
}
c->initialised = true;
c->regs[smp_processor_id()] = regs;
register_console(&c->cons);
out:
raw_spin_unlock_irqrestore(&c->lock, flags);
return ret;
}
static unsigned int mips_ejtag_fdc_put_chan(struct mips_ejtag_fdc_tty *priv,
unsigned int chan)
{
struct mips_ejtag_fdc_tty_port *dport;
struct tty_struct *tty;
const char *ptrs[2];
unsigned int sizes[2] = { 0 };
struct fdc_word word = { .bytes = 0 };
unsigned long flags;
dport = &priv->ports[chan];
spin_lock(&dport->xmit_lock);
if (dport->xmit_cnt) {
ptrs[0] = dport->port.xmit_buf + dport->xmit_tail;
sizes[0] = min_t(unsigned int,
priv->xmit_size - dport->xmit_tail,
dport->xmit_cnt);
ptrs[1] = dport->port.xmit_buf;
sizes[1] = dport->xmit_cnt - sizes[0];
word = mips_ejtag_fdc_encode(ptrs, sizes, 1 + !!sizes[1]);
dev_dbg(priv->dev, "%s%u: out %08x: \"%*pE%*pE\"\n",
priv->driver_name, chan, word.word,
min_t(int, word.bytes, sizes[0]), ptrs[0],
max_t(int, 0, word.bytes - sizes[0]), ptrs[1]);
local_irq_save(flags);
if (mips_ejtag_fdc_read(priv, REG_FDSTAT) & REG_FDSTAT_TXF)
word.bytes = 0;
else
mips_ejtag_fdc_write(priv, REG_FDTX(chan), word.word);
local_irq_restore(flags);
dport->xmit_cnt -= word.bytes;
if (!dport->xmit_cnt) {
dport->xmit_head = 0;
dport->xmit_tail = 0;
complete(&dport->xmit_empty);
} else {
dport->xmit_tail += word.bytes;
if (dport->xmit_tail >= priv->xmit_size)
dport->xmit_tail -= priv->xmit_size;
}
atomic_sub(word.bytes, &priv->xmit_total);
}
spin_unlock(&dport->xmit_lock);
if (sizes[0] && word.bytes) {
tty = tty_port_tty_get(&dport->port);
if (tty) {
tty_wakeup(tty);
tty_kref_put(tty);
}
}
return word.bytes;
}
static int mips_ejtag_fdc_put(void *arg)
{
struct mips_ejtag_fdc_tty *priv = arg;
struct mips_ejtag_fdc_tty_port *dport;
unsigned int ret;
u32 cfg;
__set_current_state(TASK_RUNNING);
while (!kthread_should_stop()) {
wait_event_interruptible(priv->waitqueue,
atomic_read(&priv->xmit_total) ||
kthread_should_stop());
if (kthread_should_stop())
break;
raw_spin_lock_irq(&priv->lock);
if (mips_ejtag_fdc_read(priv, REG_FDSTAT) & REG_FDSTAT_TXF) {
priv->xmit_full = true;
if (priv->irq >= 0) {
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~REG_FDCFG_TXINTTHRES;
cfg |= REG_FDCFG_TXINTTHRES_NOTFULL;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
}
}
raw_spin_unlock_irq(&priv->lock);
wait_event_interruptible(priv->waitqueue,
!(mips_ejtag_fdc_read(priv, REG_FDSTAT)
& REG_FDSTAT_TXF) ||
kthread_should_stop());
if (kthread_should_stop())
break;
for (;;) {
dport = &priv->ports[priv->xmit_next];
spin_lock(&dport->xmit_lock);
ret = dport->xmit_cnt;
spin_unlock(&dport->xmit_lock);
if (ret)
break;
++priv->xmit_next;
if (priv->xmit_next >= NUM_TTY_CHANNELS)
priv->xmit_next = 0;
}
ret = mips_ejtag_fdc_put_chan(priv, priv->xmit_next);
if (ret) {
++priv->xmit_next;
if (priv->xmit_next >= NUM_TTY_CHANNELS)
priv->xmit_next = 0;
}
}
return 0;
}
static void mips_ejtag_fdc_handle(struct mips_ejtag_fdc_tty *priv)
{
struct mips_ejtag_fdc_tty_port *dport;
unsigned int stat, channel, data, cfg, i, flipped;
int len;
char buf[4];
for (;;) {
stat = mips_ejtag_fdc_read(priv, REG_FDSTAT);
if (stat & REG_FDSTAT_RXE)
break;
channel = (stat & REG_FDSTAT_RXCHAN) >> REG_FDSTAT_RXCHAN_SHIFT;
dport = &priv->ports[channel];
raw_spin_lock(&dport->rx_lock);
data = mips_ejtag_fdc_read(priv, REG_FDRX);
len = mips_ejtag_fdc_decode(data, buf);
dev_dbg(priv->dev, "%s%u: in %08x: \"%*pE\"\n",
priv->driver_name, channel, data, len, buf);
flipped = 0;
for (i = 0; i < len; ++i) {
#ifdef CONFIG_MAGIC_SYSRQ
#ifdef CONFIG_MIPS_EJTAG_FDC_KGDB
if (channel == CONFIG_MIPS_EJTAG_FDC_KGDB_CHAN) {
if (buf[i] == '\x03') {
handle_sysrq('g');
continue;
}
}
#endif
if (channel == mips_ejtag_fdc_con.cons.index) {
if (buf[i] == '\x0f') {
priv->sysrq_pressed =
!priv->sysrq_pressed;
if (priv->sysrq_pressed)
continue;
} else if (priv->sysrq_pressed) {
handle_sysrq(buf[i]);
priv->sysrq_pressed = false;
continue;
}
}
#endif
if (!dport->rx_buf)
continue;
flipped += tty_insert_flip_char(&dport->port, buf[i],
TTY_NORMAL);
}
if (flipped)
tty_flip_buffer_push(&dport->port);
raw_spin_unlock(&dport->rx_lock);
}
raw_spin_lock(&priv->lock);
if (priv->xmit_full && !(stat & REG_FDSTAT_TXF)) {
priv->xmit_full = false;
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~REG_FDCFG_TXINTTHRES;
cfg |= REG_FDCFG_TXINTTHRES_DISABLED;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
wake_up_interruptible(&priv->waitqueue);
}
raw_spin_unlock(&priv->lock);
}
static irqreturn_t mips_ejtag_fdc_isr(int irq, void *dev_id)
{
struct mips_ejtag_fdc_tty *priv = dev_id;
if (smp_processor_id() != priv->cpu)
return IRQ_NONE;
if (!(read_c0_cause() & CAUSEF_FDCI))
return IRQ_NONE;
mips_ejtag_fdc_handle(priv);
return IRQ_HANDLED;
}
static void mips_ejtag_fdc_tty_timer(unsigned long opaque)
{
struct mips_ejtag_fdc_tty *priv = (void *)opaque;
mips_ejtag_fdc_handle(priv);
if (!priv->removing)
mod_timer_pinned(&priv->poll_timer, jiffies + FDC_TTY_POLL);
}
static int mips_ejtag_fdc_tty_port_activate(struct tty_port *port,
struct tty_struct *tty)
{
struct mips_ejtag_fdc_tty_port *dport =
container_of(port, struct mips_ejtag_fdc_tty_port, port);
void *rx_buf;
if (tty_port_alloc_xmit_buf(port) < 0)
goto err;
rx_buf = kzalloc(RX_BUF_SIZE, GFP_KERNEL);
if (!rx_buf)
goto err_free_xmit;
raw_spin_lock_irq(&dport->rx_lock);
dport->rx_buf = rx_buf;
raw_spin_unlock_irq(&dport->rx_lock);
return 0;
err_free_xmit:
tty_port_free_xmit_buf(port);
err:
return -ENOMEM;
}
static void mips_ejtag_fdc_tty_port_shutdown(struct tty_port *port)
{
struct mips_ejtag_fdc_tty_port *dport =
container_of(port, struct mips_ejtag_fdc_tty_port, port);
struct mips_ejtag_fdc_tty *priv = dport->driver;
void *rx_buf;
unsigned int count;
spin_lock(&dport->xmit_lock);
count = dport->xmit_cnt;
spin_unlock(&dport->xmit_lock);
if (count) {
wake_up_interruptible(&priv->waitqueue);
wait_for_completion(&dport->xmit_empty);
}
raw_spin_lock_irq(&dport->rx_lock);
rx_buf = dport->rx_buf;
dport->rx_buf = NULL;
raw_spin_unlock_irq(&dport->rx_lock);
kfree(rx_buf);
tty_port_free_xmit_buf(port);
}
static int mips_ejtag_fdc_tty_install(struct tty_driver *driver,
struct tty_struct *tty)
{
struct mips_ejtag_fdc_tty *priv = driver->driver_state;
tty->driver_data = &priv->ports[tty->index];
return tty_port_install(&priv->ports[tty->index].port, driver, tty);
}
static int mips_ejtag_fdc_tty_open(struct tty_struct *tty, struct file *filp)
{
return tty_port_open(tty->port, tty, filp);
}
static void mips_ejtag_fdc_tty_close(struct tty_struct *tty, struct file *filp)
{
return tty_port_close(tty->port, tty, filp);
}
static void mips_ejtag_fdc_tty_hangup(struct tty_struct *tty)
{
struct mips_ejtag_fdc_tty_port *dport = tty->driver_data;
struct mips_ejtag_fdc_tty *priv = dport->driver;
spin_lock(&dport->xmit_lock);
if (dport->xmit_cnt) {
atomic_sub(dport->xmit_cnt, &priv->xmit_total);
dport->xmit_cnt = 0;
dport->xmit_head = 0;
dport->xmit_tail = 0;
complete(&dport->xmit_empty);
}
spin_unlock(&dport->xmit_lock);
tty_port_hangup(tty->port);
}
static int mips_ejtag_fdc_tty_write(struct tty_struct *tty,
const unsigned char *buf, int total)
{
int count, block;
struct mips_ejtag_fdc_tty_port *dport = tty->driver_data;
struct mips_ejtag_fdc_tty *priv = dport->driver;
spin_lock(&dport->xmit_lock);
total = min(total, (int)(priv->xmit_size - dport->xmit_cnt));
atomic_add(total, &priv->xmit_total);
dport->xmit_cnt += total;
for (count = total; count; count -= block) {
block = min(count, (int)(priv->xmit_size - dport->xmit_head));
memcpy(dport->port.xmit_buf + dport->xmit_head, buf, block);
dport->xmit_head += block;
if (dport->xmit_head >= priv->xmit_size)
dport->xmit_head -= priv->xmit_size;
buf += block;
}
count = dport->xmit_cnt;
if (count)
reinit_completion(&dport->xmit_empty);
spin_unlock(&dport->xmit_lock);
if (total)
wake_up_interruptible(&priv->waitqueue);
return total;
}
static int mips_ejtag_fdc_tty_write_room(struct tty_struct *tty)
{
struct mips_ejtag_fdc_tty_port *dport = tty->driver_data;
struct mips_ejtag_fdc_tty *priv = dport->driver;
int room;
spin_lock(&dport->xmit_lock);
room = priv->xmit_size - dport->xmit_cnt;
spin_unlock(&dport->xmit_lock);
return room;
}
static int mips_ejtag_fdc_tty_chars_in_buffer(struct tty_struct *tty)
{
struct mips_ejtag_fdc_tty_port *dport = tty->driver_data;
int chars;
spin_lock(&dport->xmit_lock);
chars = dport->xmit_cnt;
spin_unlock(&dport->xmit_lock);
return chars;
}
int __weak get_c0_fdc_int(void)
{
return -1;
}
static int mips_ejtag_fdc_tty_probe(struct mips_cdmm_device *dev)
{
int ret, nport;
struct mips_ejtag_fdc_tty_port *dport;
struct mips_ejtag_fdc_tty *priv;
struct tty_driver *driver;
unsigned int cfg, tx_fifo;
priv = devm_kzalloc(&dev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->cpu = dev->cpu;
priv->dev = &dev->dev;
mips_cdmm_set_drvdata(dev, priv);
atomic_set(&priv->xmit_total, 0);
raw_spin_lock_init(&priv->lock);
priv->reg = devm_ioremap_nocache(priv->dev, dev->res.start,
resource_size(&dev->res));
if (!priv->reg) {
dev_err(priv->dev, "ioremap failed for resource %pR\n",
&dev->res);
return -ENOMEM;
}
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
tx_fifo = (cfg & REG_FDCFG_TXFIFOSIZE) >> REG_FDCFG_TXFIFOSIZE_SHIFT;
cfg &= ~(REG_FDCFG_TXINTTHRES | REG_FDCFG_RXINTTHRES);
cfg |= REG_FDCFG_TXINTTHRES_DISABLED;
cfg |= REG_FDCFG_RXINTTHRES_DISABLED;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
priv->xmit_size = min(tx_fifo * 4, (unsigned int)SERIAL_XMIT_SIZE);
driver = tty_alloc_driver(NUM_TTY_CHANNELS, TTY_DRIVER_REAL_RAW);
if (IS_ERR(driver))
return PTR_ERR(driver);
priv->driver = driver;
driver->driver_name = "ejtag_fdc";
snprintf(priv->fdc_name, sizeof(priv->fdc_name), "ttyFDC%u", dev->cpu);
snprintf(priv->driver_name, sizeof(priv->driver_name), "%sc",
priv->fdc_name);
driver->name = priv->driver_name;
driver->major = 0;
driver->minor_start = 0;
driver->type = TTY_DRIVER_TYPE_SERIAL;
driver->subtype = SERIAL_TYPE_NORMAL;
driver->init_termios = tty_std_termios;
driver->init_termios.c_cflag |= CLOCAL;
driver->driver_state = priv;
tty_set_operations(driver, &mips_ejtag_fdc_tty_ops);
for (nport = 0; nport < NUM_TTY_CHANNELS; nport++) {
dport = &priv->ports[nport];
dport->driver = priv;
tty_port_init(&dport->port);
dport->port.ops = &mips_ejtag_fdc_tty_port_ops;
raw_spin_lock_init(&dport->rx_lock);
spin_lock_init(&dport->xmit_lock);
init_completion(&dport->xmit_empty);
complete(&dport->xmit_empty);
}
mips_ejtag_fdc_con.regs[dev->cpu] = priv->reg;
if (dev->cpu == 0)
mips_ejtag_fdc_con.tty_drv = driver;
init_waitqueue_head(&priv->waitqueue);
priv->thread = kthread_create(mips_ejtag_fdc_put, priv, priv->fdc_name);
if (IS_ERR(priv->thread)) {
ret = PTR_ERR(priv->thread);
dev_err(priv->dev, "Couldn't create kthread (%d)\n", ret);
goto err_destroy_ports;
}
kthread_bind(priv->thread, dev->cpu);
wake_up_process(priv->thread);
priv->irq = get_c0_fdc_int();
if (priv->irq >= 0) {
ret = devm_request_irq(priv->dev, priv->irq, mips_ejtag_fdc_isr,
IRQF_PERCPU | IRQF_SHARED |
IRQF_NO_THREAD | IRQF_NO_SUSPEND,
priv->fdc_name, priv);
if (ret)
priv->irq = -1;
}
if (priv->irq >= 0) {
raw_spin_lock_irq(&priv->lock);
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~REG_FDCFG_RXINTTHRES;
cfg |= REG_FDCFG_RXINTTHRES_NOTEMPTY;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
raw_spin_unlock_irq(&priv->lock);
} else {
setup_timer(&priv->poll_timer, mips_ejtag_fdc_tty_timer,
(unsigned long)priv);
priv->poll_timer.expires = jiffies + FDC_TTY_POLL;
add_timer_on(&priv->poll_timer, dev->cpu);
dev_info(priv->dev, "No usable IRQ, polling enabled\n");
}
ret = tty_register_driver(driver);
if (ret < 0) {
dev_err(priv->dev, "Couldn't install tty driver (%d)\n", ret);
goto err_stop_irq;
}
return 0;
err_stop_irq:
if (priv->irq >= 0) {
raw_spin_lock_irq(&priv->lock);
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~(REG_FDCFG_TXINTTHRES | REG_FDCFG_RXINTTHRES);
cfg |= REG_FDCFG_TXINTTHRES_DISABLED;
cfg |= REG_FDCFG_RXINTTHRES_DISABLED;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
raw_spin_unlock_irq(&priv->lock);
} else {
priv->removing = true;
del_timer_sync(&priv->poll_timer);
}
kthread_stop(priv->thread);
err_destroy_ports:
if (dev->cpu == 0)
mips_ejtag_fdc_con.tty_drv = NULL;
for (nport = 0; nport < NUM_TTY_CHANNELS; nport++) {
dport = &priv->ports[nport];
tty_port_destroy(&dport->port);
}
put_tty_driver(priv->driver);
return ret;
}
static int mips_ejtag_fdc_tty_remove(struct mips_cdmm_device *dev)
{
struct mips_ejtag_fdc_tty *priv = mips_cdmm_get_drvdata(dev);
struct mips_ejtag_fdc_tty_port *dport;
int nport;
unsigned int cfg;
if (priv->irq >= 0) {
raw_spin_lock_irq(&priv->lock);
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~(REG_FDCFG_TXINTTHRES | REG_FDCFG_RXINTTHRES);
cfg |= REG_FDCFG_TXINTTHRES_DISABLED;
cfg |= REG_FDCFG_RXINTTHRES_DISABLED;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
raw_spin_unlock_irq(&priv->lock);
} else {
priv->removing = true;
del_timer_sync(&priv->poll_timer);
}
kthread_stop(priv->thread);
if (dev->cpu == 0)
mips_ejtag_fdc_con.tty_drv = NULL;
tty_unregister_driver(priv->driver);
for (nport = 0; nport < NUM_TTY_CHANNELS; nport++) {
dport = &priv->ports[nport];
tty_port_destroy(&dport->port);
}
put_tty_driver(priv->driver);
return 0;
}
static int mips_ejtag_fdc_tty_cpu_down(struct mips_cdmm_device *dev)
{
struct mips_ejtag_fdc_tty *priv = mips_cdmm_get_drvdata(dev);
unsigned int cfg;
if (priv->irq >= 0) {
raw_spin_lock_irq(&priv->lock);
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~(REG_FDCFG_TXINTTHRES | REG_FDCFG_RXINTTHRES);
cfg |= REG_FDCFG_TXINTTHRES_DISABLED;
cfg |= REG_FDCFG_RXINTTHRES_DISABLED;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
raw_spin_unlock_irq(&priv->lock);
} else {
priv->removing = true;
del_timer_sync(&priv->poll_timer);
}
kthread_stop(priv->thread);
return 0;
}
static int mips_ejtag_fdc_tty_cpu_up(struct mips_cdmm_device *dev)
{
struct mips_ejtag_fdc_tty *priv = mips_cdmm_get_drvdata(dev);
unsigned int cfg;
int ret = 0;
if (priv->irq >= 0) {
raw_spin_lock_irq(&priv->lock);
cfg = mips_ejtag_fdc_read(priv, REG_FDCFG);
cfg &= ~(REG_FDCFG_TXINTTHRES | REG_FDCFG_RXINTTHRES);
cfg |= REG_FDCFG_TXINTTHRES_DISABLED;
cfg |= REG_FDCFG_RXINTTHRES_NOTEMPTY;
mips_ejtag_fdc_write(priv, REG_FDCFG, cfg);
raw_spin_unlock_irq(&priv->lock);
} else {
priv->removing = false;
add_timer_on(&priv->poll_timer, dev->cpu);
}
priv->thread = kthread_create(mips_ejtag_fdc_put, priv, priv->fdc_name);
if (IS_ERR(priv->thread)) {
ret = PTR_ERR(priv->thread);
dev_err(priv->dev, "Couldn't re-create kthread (%d)\n", ret);
goto out;
}
kthread_bind(priv->thread, dev->cpu);
wake_up_process(priv->thread);
out:
return ret;
}
static int __init mips_ejtag_fdc_init_console(void)
{
return mips_ejtag_fdc_console_init(&mips_ejtag_fdc_con);
}
int __init setup_early_fdc_console(void)
{
return mips_ejtag_fdc_console_init(&mips_ejtag_fdc_earlycon);
}
static void __iomem *kgdbfdc_setup(void)
{
void __iomem *regs;
unsigned int cpu;
cpu = smp_processor_id();
regs = mips_ejtag_fdc_con.regs[cpu];
if (!regs) {
regs = mips_cdmm_early_probe(0xfd);
mips_ejtag_fdc_con.regs[cpu] = regs;
}
if (IS_ERR(regs))
return regs;
return regs;
}
static int kgdbfdc_read_char(void)
{
unsigned int stat, channel, data;
void __iomem *regs;
if (kgdbfdc_rpos >= kgdbfdc_rbuflen) {
kgdbfdc_rpos = 0;
kgdbfdc_rbuflen = 0;
regs = kgdbfdc_setup();
if (IS_ERR(regs))
return NO_POLL_CHAR;
do {
stat = __raw_readl(regs + REG_FDSTAT);
if (stat & REG_FDSTAT_RXE)
return NO_POLL_CHAR;
channel = (stat & REG_FDSTAT_RXCHAN) >>
REG_FDSTAT_RXCHAN_SHIFT;
data = __raw_readl(regs + REG_FDRX);
} while (channel != CONFIG_MIPS_EJTAG_FDC_KGDB_CHAN);
kgdbfdc_rbuflen = mips_ejtag_fdc_decode(data, kgdbfdc_rbuf);
}
pr_devel("kgdbfdc r %c\n", kgdbfdc_rbuf[kgdbfdc_rpos]);
return kgdbfdc_rbuf[kgdbfdc_rpos++];
}
static void kgdbfdc_push_one(void)
{
const char *bufs[1] = { kgdbfdc_wbuf };
struct fdc_word word;
void __iomem *regs;
unsigned int i;
word = mips_ejtag_fdc_encode(bufs, &kgdbfdc_wbuflen, 1);
kgdbfdc_wbuflen -= word.bytes;
for (i = 0; i < kgdbfdc_wbuflen; ++i)
kgdbfdc_wbuf[i] = kgdbfdc_wbuf[i + word.bytes];
regs = kgdbfdc_setup();
if (IS_ERR(regs))
return;
while (__raw_readl(regs + REG_FDSTAT) & REG_FDSTAT_TXF)
;
__raw_writel(word.word,
regs + REG_FDTX(CONFIG_MIPS_EJTAG_FDC_KGDB_CHAN));
}
static void kgdbfdc_flush(void)
{
while (kgdbfdc_wbuflen)
kgdbfdc_push_one();
}
static void kgdbfdc_write_char(u8 chr)
{
pr_devel("kgdbfdc w %c\n", chr);
kgdbfdc_wbuf[kgdbfdc_wbuflen++] = chr;
if (kgdbfdc_wbuflen >= sizeof(kgdbfdc_wbuf))
kgdbfdc_push_one();
}
static int __init kgdbfdc_init(void)
{
kgdb_register_io_module(&kgdbfdc_io_ops);
return 0;
}
