static void dbg_hcs_params (struct fusbh200_hcd *fusbh200, char *label)
{
u32 params = fusbh200_readl(fusbh200, &fusbh200->caps->hcs_params);
fusbh200_dbg (fusbh200,
"%s hcs_params 0x%x ports=%d\n",
label, params,
HCS_N_PORTS (params)
);
}
static void dbg_hcc_params (struct fusbh200_hcd *fusbh200, char *label)
{
u32 params = fusbh200_readl(fusbh200, &fusbh200->caps->hcc_params);
fusbh200_dbg (fusbh200,
"%s hcc_params %04x uframes %s%s\n",
label,
params,
HCC_PGM_FRAMELISTLEN(params) ? "256/512/1024" : "1024",
HCC_CANPARK(params) ? " park" : "");
}
static void __maybe_unused
dbg_qtd (const char *label, struct fusbh200_hcd *fusbh200, struct fusbh200_qtd *qtd)
{
fusbh200_dbg(fusbh200, "%s td %p n%08x %08x t%08x p0=%08x\n", label, qtd,
hc32_to_cpup(fusbh200, &qtd->hw_next),
hc32_to_cpup(fusbh200, &qtd->hw_alt_next),
hc32_to_cpup(fusbh200, &qtd->hw_token),
hc32_to_cpup(fusbh200, &qtd->hw_buf [0]));
if (qtd->hw_buf [1])
fusbh200_dbg(fusbh200, " p1=%08x p2=%08x p3=%08x p4=%08x\n",
hc32_to_cpup(fusbh200, &qtd->hw_buf[1]),
hc32_to_cpup(fusbh200, &qtd->hw_buf[2]),
hc32_to_cpup(fusbh200, &qtd->hw_buf[3]),
hc32_to_cpup(fusbh200, &qtd->hw_buf[4]));
}
static void __maybe_unused
dbg_qh (const char *label, struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
struct fusbh200_qh_hw *hw = qh->hw;
fusbh200_dbg (fusbh200, "%s qh %p n%08x info %x %x qtd %x\n", label,
qh, hw->hw_next, hw->hw_info1, hw->hw_info2, hw->hw_current);
dbg_qtd("overlay", fusbh200, (struct fusbh200_qtd *) &hw->hw_qtd_next);
}
static void __maybe_unused
dbg_itd (const char *label, struct fusbh200_hcd *fusbh200, struct fusbh200_itd *itd)
{
fusbh200_dbg (fusbh200, "%s [%d] itd %p, next %08x, urb %p\n",
label, itd->frame, itd, hc32_to_cpu(fusbh200, itd->hw_next),
itd->urb);
fusbh200_dbg (fusbh200,
" trans: %08x %08x %08x %08x %08x %08x %08x %08x\n",
hc32_to_cpu(fusbh200, itd->hw_transaction[0]),
hc32_to_cpu(fusbh200, itd->hw_transaction[1]),
hc32_to_cpu(fusbh200, itd->hw_transaction[2]),
hc32_to_cpu(fusbh200, itd->hw_transaction[3]),
hc32_to_cpu(fusbh200, itd->hw_transaction[4]),
hc32_to_cpu(fusbh200, itd->hw_transaction[5]),
hc32_to_cpu(fusbh200, itd->hw_transaction[6]),
hc32_to_cpu(fusbh200, itd->hw_transaction[7]));
fusbh200_dbg (fusbh200,
" buf: %08x %08x %08x %08x %08x %08x %08x\n",
hc32_to_cpu(fusbh200, itd->hw_bufp[0]),
hc32_to_cpu(fusbh200, itd->hw_bufp[1]),
hc32_to_cpu(fusbh200, itd->hw_bufp[2]),
hc32_to_cpu(fusbh200, itd->hw_bufp[3]),
hc32_to_cpu(fusbh200, itd->hw_bufp[4]),
hc32_to_cpu(fusbh200, itd->hw_bufp[5]),
hc32_to_cpu(fusbh200, itd->hw_bufp[6]));
fusbh200_dbg (fusbh200, " index: %d %d %d %d %d %d %d %d\n",
itd->index[0], itd->index[1], itd->index[2],
itd->index[3], itd->index[4], itd->index[5],
itd->index[6], itd->index[7]);
}
static int __maybe_unused
dbg_status_buf (char *buf, unsigned len, const char *label, u32 status)
{
return scnprintf (buf, len,
"%s%sstatus %04x%s%s%s%s%s%s%s%s%s%s",
label, label [0] ? " " : "", status,
(status & STS_ASS) ? " Async" : "",
(status & STS_PSS) ? " Periodic" : "",
(status & STS_RECL) ? " Recl" : "",
(status & STS_HALT) ? " Halt" : "",
(status & STS_IAA) ? " IAA" : "",
(status & STS_FATAL) ? " FATAL" : "",
(status & STS_FLR) ? " FLR" : "",
(status & STS_PCD) ? " PCD" : "",
(status & STS_ERR) ? " ERR" : "",
(status & STS_INT) ? " INT" : ""
);
}
static int __maybe_unused
dbg_intr_buf (char *buf, unsigned len, const char *label, u32 enable)
{
return scnprintf (buf, len,
"%s%sintrenable %02x%s%s%s%s%s%s",
label, label [0] ? " " : "", enable,
(enable & STS_IAA) ? " IAA" : "",
(enable & STS_FATAL) ? " FATAL" : "",
(enable & STS_FLR) ? " FLR" : "",
(enable & STS_PCD) ? " PCD" : "",
(enable & STS_ERR) ? " ERR" : "",
(enable & STS_INT) ? " INT" : ""
);
}
static int
dbg_command_buf (char *buf, unsigned len, const char *label, u32 command)
{
return scnprintf (buf, len,
"%s%scommand %07x %s=%d ithresh=%d%s%s%s "
"period=%s%s %s",
label, label [0] ? " " : "", command,
(command & CMD_PARK) ? " park" : "(park)",
CMD_PARK_CNT (command),
(command >> 16) & 0x3f,
(command & CMD_IAAD) ? " IAAD" : "",
(command & CMD_ASE) ? " Async" : "",
(command & CMD_PSE) ? " Periodic" : "",
fls_strings [(command >> 2) & 0x3],
(command & CMD_RESET) ? " Reset" : "",
(command & CMD_RUN) ? "RUN" : "HALT"
);
}
static int
dbg_port_buf (char *buf, unsigned len, const char *label, int port, u32 status)
{
char *sig;
switch (status & (3 << 10)) {
case 0 << 10: sig = "se0"; break;
case 1 << 10: sig = "k"; break;
case 2 << 10: sig = "j"; break;
default: sig = "?"; break;
}
return scnprintf (buf, len,
"%s%sport:%d status %06x %d "
"sig=%s%s%s%s%s%s%s%s",
label, label [0] ? " " : "", port, status,
status>>25,
sig,
(status & PORT_RESET) ? " RESET" : "",
(status & PORT_SUSPEND) ? " SUSPEND" : "",
(status & PORT_RESUME) ? " RESUME" : "",
(status & PORT_PEC) ? " PEC" : "",
(status & PORT_PE) ? " PE" : "",
(status & PORT_CSC) ? " CSC" : "",
(status & PORT_CONNECT) ? " CONNECT" : "");
}
static inline char token_mark(struct fusbh200_hcd *fusbh200, __hc32 token)
{
__u32 v = hc32_to_cpu(fusbh200, token);
if (v & QTD_STS_ACTIVE)
return '*';
if (v & QTD_STS_HALT)
return '-';
if (!IS_SHORT_READ (v))
return ' ';
return '/';
}
static void qh_lines (
struct fusbh200_hcd *fusbh200,
struct fusbh200_qh *qh,
char **nextp,
unsigned *sizep
)
{
u32 scratch;
u32 hw_curr;
struct fusbh200_qtd *td;
unsigned temp;
unsigned size = *sizep;
char *next = *nextp;
char mark;
__le32 list_end = FUSBH200_LIST_END(fusbh200);
struct fusbh200_qh_hw *hw = qh->hw;
if (hw->hw_qtd_next == list_end)
mark = '@';
else
mark = token_mark(fusbh200, hw->hw_token);
if (mark == '/') {
if ((hw->hw_alt_next & QTD_MASK(fusbh200))
== fusbh200->async->hw->hw_alt_next)
mark = '#';
else if (hw->hw_alt_next == list_end)
mark = '.';
}
scratch = hc32_to_cpup(fusbh200, &hw->hw_info1);
hw_curr = (mark == '*') ? hc32_to_cpup(fusbh200, &hw->hw_current) : 0;
temp = scnprintf (next, size,
"qh/%p dev%d %cs ep%d %08x %08x (%08x%c %s nak%d)",
qh, scratch & 0x007f,
speed_char (scratch),
(scratch >> 8) & 0x000f,
scratch, hc32_to_cpup(fusbh200, &hw->hw_info2),
hc32_to_cpup(fusbh200, &hw->hw_token), mark,
(cpu_to_hc32(fusbh200, QTD_TOGGLE) & hw->hw_token)
? "data1" : "data0",
(hc32_to_cpup(fusbh200, &hw->hw_alt_next) >> 1) & 0x0f);
size -= temp;
next += temp;
list_for_each_entry(td, &qh->qtd_list, qtd_list) {
scratch = hc32_to_cpup(fusbh200, &td->hw_token);
mark = ' ';
if (hw_curr == td->qtd_dma)
mark = '*';
else if (hw->hw_qtd_next == cpu_to_hc32(fusbh200, td->qtd_dma))
mark = '+';
else if (QTD_LENGTH (scratch)) {
if (td->hw_alt_next == fusbh200->async->hw->hw_alt_next)
mark = '#';
else if (td->hw_alt_next != list_end)
mark = '/';
}
temp = snprintf (next, size,
"\n\t%p%c%s len=%d %08x urb %p",
td, mark, ({ char *tmp;
switch ((scratch>>8)&0x03) {
case 0: tmp = "out"; break;
case 1: tmp = "in"; break;
case 2: tmp = "setup"; break;
default: tmp = "?"; break;
} tmp;}),
(scratch >> 16) & 0x7fff,
scratch,
td->urb);
if (size < temp)
temp = size;
size -= temp;
next += temp;
if (temp == size)
goto done;
}
temp = snprintf (next, size, "\n");
if (size < temp)
temp = size;
size -= temp;
next += temp;
done:
*sizep = size;
*nextp = next;
}
static ssize_t fill_async_buffer(struct debug_buffer *buf)
{
struct usb_hcd *hcd;
struct fusbh200_hcd *fusbh200;
unsigned long flags;
unsigned temp, size;
char *next;
struct fusbh200_qh *qh;
hcd = bus_to_hcd(buf->bus);
fusbh200 = hcd_to_fusbh200 (hcd);
next = buf->output_buf;
size = buf->alloc_size;
*next = 0;
spin_lock_irqsave (&fusbh200->lock, flags);
for (qh = fusbh200->async->qh_next.qh; size > 0 && qh; qh = qh->qh_next.qh)
qh_lines (fusbh200, qh, &next, &size);
if (fusbh200->async_unlink && size > 0) {
temp = scnprintf(next, size, "\nunlink =\n");
size -= temp;
next += temp;
for (qh = fusbh200->async_unlink; size > 0 && qh;
qh = qh->unlink_next)
qh_lines (fusbh200, qh, &next, &size);
}
spin_unlock_irqrestore (&fusbh200->lock, flags);
return strlen(buf->output_buf);
}
static ssize_t fill_periodic_buffer(struct debug_buffer *buf)
{
struct usb_hcd *hcd;
struct fusbh200_hcd *fusbh200;
unsigned long flags;
union fusbh200_shadow p, *seen;
unsigned temp, size, seen_count;
char *next;
unsigned i;
__hc32 tag;
seen = kmalloc(DBG_SCHED_LIMIT * sizeof *seen, GFP_ATOMIC);
if (!seen)
return 0;
seen_count = 0;
hcd = bus_to_hcd(buf->bus);
fusbh200 = hcd_to_fusbh200 (hcd);
next = buf->output_buf;
size = buf->alloc_size;
temp = scnprintf (next, size, "size = %d\n", fusbh200->periodic_size);
size -= temp;
next += temp;
spin_lock_irqsave (&fusbh200->lock, flags);
for (i = 0; i < fusbh200->periodic_size; i++) {
p = fusbh200->pshadow [i];
if (likely (!p.ptr))
continue;
tag = Q_NEXT_TYPE(fusbh200, fusbh200->periodic [i]);
temp = scnprintf (next, size, "%4d: ", i);
size -= temp;
next += temp;
do {
struct fusbh200_qh_hw *hw;
switch (hc32_to_cpu(fusbh200, tag)) {
case Q_TYPE_QH:
hw = p.qh->hw;
temp = scnprintf (next, size, " qh%d-%04x/%p",
p.qh->period,
hc32_to_cpup(fusbh200,
&hw->hw_info2)
& (QH_CMASK | QH_SMASK),
p.qh);
size -= temp;
next += temp;
for (temp = 0; temp < seen_count; temp++) {
if (seen [temp].ptr != p.ptr)
continue;
if (p.qh->qh_next.ptr) {
temp = scnprintf (next, size,
" ...");
size -= temp;
next += temp;
}
break;
}
if (temp == seen_count) {
u32 scratch = hc32_to_cpup(fusbh200,
&hw->hw_info1);
struct fusbh200_qtd *qtd;
char *type = "";
temp = 0;
list_for_each_entry (qtd,
&p.qh->qtd_list,
qtd_list) {
temp++;
switch (0x03 & (hc32_to_cpu(
fusbh200,
qtd->hw_token) >> 8)) {
case 0: type = "out"; continue;
case 1: type = "in"; continue;
}
}
temp = scnprintf (next, size,
" (%c%d ep%d%s "
"[%d/%d] q%d p%d)",
speed_char (scratch),
scratch & 0x007f,
(scratch >> 8) & 0x000f, type,
p.qh->usecs, p.qh->c_usecs,
temp,
0x7ff & (scratch >> 16));
if (seen_count < DBG_SCHED_LIMIT)
seen [seen_count++].qh = p.qh;
} else
temp = 0;
tag = Q_NEXT_TYPE(fusbh200, hw->hw_next);
p = p.qh->qh_next;
break;
case Q_TYPE_FSTN:
temp = scnprintf (next, size,
" fstn-%8x/%p", p.fstn->hw_prev,
p.fstn);
tag = Q_NEXT_TYPE(fusbh200, p.fstn->hw_next);
p = p.fstn->fstn_next;
break;
case Q_TYPE_ITD:
temp = scnprintf (next, size,
" itd/%p", p.itd);
tag = Q_NEXT_TYPE(fusbh200, p.itd->hw_next);
p = p.itd->itd_next;
break;
}
size -= temp;
next += temp;
} while (p.ptr);
temp = scnprintf (next, size, "\n");
size -= temp;
next += temp;
}
spin_unlock_irqrestore (&fusbh200->lock, flags);
kfree (seen);
return buf->alloc_size - size;
}
static const char *rh_state_string(struct fusbh200_hcd *fusbh200)
{
switch (fusbh200->rh_state) {
case FUSBH200_RH_HALTED:
return "halted";
case FUSBH200_RH_SUSPENDED:
return "suspended";
case FUSBH200_RH_RUNNING:
return "running";
case FUSBH200_RH_STOPPING:
return "stopping";
}
return "?";
}
static ssize_t fill_registers_buffer(struct debug_buffer *buf)
{
struct usb_hcd *hcd;
struct fusbh200_hcd *fusbh200;
unsigned long flags;
unsigned temp, size, i;
char *next, scratch [80];
static char fmt [] = "%*s\n";
static char label [] = "";
hcd = bus_to_hcd(buf->bus);
fusbh200 = hcd_to_fusbh200 (hcd);
next = buf->output_buf;
size = buf->alloc_size;
spin_lock_irqsave (&fusbh200->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd)) {
size = scnprintf (next, size,
"bus %s, device %s\n"
"%s\n"
"SUSPENDED (no register access)\n",
hcd->self.controller->bus->name,
dev_name(hcd->self.controller),
hcd->product_desc);
goto done;
}
i = HC_VERSION(fusbh200, fusbh200_readl(fusbh200, &fusbh200->caps->hc_capbase));
temp = scnprintf (next, size,
"bus %s, device %s\n"
"%s\n"
"EHCI %x.%02x, rh state %s\n",
hcd->self.controller->bus->name,
dev_name(hcd->self.controller),
hcd->product_desc,
i >> 8, i & 0x0ff, rh_state_string(fusbh200));
size -= temp;
next += temp;
i = fusbh200_readl(fusbh200, &fusbh200->caps->hcs_params);
temp = scnprintf (next, size, "structural params 0x%08x\n", i);
size -= temp;
next += temp;
i = fusbh200_readl(fusbh200, &fusbh200->caps->hcc_params);
temp = scnprintf (next, size, "capability params 0x%08x\n", i);
size -= temp;
next += temp;
temp = dbg_status_buf (scratch, sizeof scratch, label,
fusbh200_readl(fusbh200, &fusbh200->regs->status));
temp = scnprintf (next, size, fmt, temp, scratch);
size -= temp;
next += temp;
temp = dbg_command_buf (scratch, sizeof scratch, label,
fusbh200_readl(fusbh200, &fusbh200->regs->command));
temp = scnprintf (next, size, fmt, temp, scratch);
size -= temp;
next += temp;
temp = dbg_intr_buf (scratch, sizeof scratch, label,
fusbh200_readl(fusbh200, &fusbh200->regs->intr_enable));
temp = scnprintf (next, size, fmt, temp, scratch);
size -= temp;
next += temp;
temp = scnprintf (next, size, "uframe %04x\n",
fusbh200_read_frame_index(fusbh200));
size -= temp;
next += temp;
if (fusbh200->async_unlink) {
temp = scnprintf(next, size, "async unlink qh %p\n",
fusbh200->async_unlink);
size -= temp;
next += temp;
}
temp = scnprintf (next, size,
"irq normal %ld err %ld iaa %ld (lost %ld)\n",
fusbh200->stats.normal, fusbh200->stats.error, fusbh200->stats.iaa,
fusbh200->stats.lost_iaa);
size -= temp;
next += temp;
temp = scnprintf (next, size, "complete %ld unlink %ld\n",
fusbh200->stats.complete, fusbh200->stats.unlink);
size -= temp;
next += temp;
done:
spin_unlock_irqrestore (&fusbh200->lock, flags);
return buf->alloc_size - size;
}
static struct debug_buffer *alloc_buffer(struct usb_bus *bus,
ssize_t (*fill_func)(struct debug_buffer *))
{
struct debug_buffer *buf;
buf = kzalloc(sizeof(struct debug_buffer), GFP_KERNEL);
if (buf) {
buf->bus = bus;
buf->fill_func = fill_func;
mutex_init(&buf->mutex);
buf->alloc_size = PAGE_SIZE;
}
return buf;
}
static int fill_buffer(struct debug_buffer *buf)
{
int ret = 0;
if (!buf->output_buf)
buf->output_buf = vmalloc(buf->alloc_size);
if (!buf->output_buf) {
ret = -ENOMEM;
goto out;
}
ret = buf->fill_func(buf);
if (ret >= 0) {
buf->count = ret;
ret = 0;
}
out:
return ret;
}
static ssize_t debug_output(struct file *file, char __user *user_buf,
size_t len, loff_t *offset)
{
struct debug_buffer *buf = file->private_data;
int ret = 0;
mutex_lock(&buf->mutex);
if (buf->count == 0) {
ret = fill_buffer(buf);
if (ret != 0) {
mutex_unlock(&buf->mutex);
goto out;
}
}
mutex_unlock(&buf->mutex);
ret = simple_read_from_buffer(user_buf, len, offset,
buf->output_buf, buf->count);
out:
return ret;
}
static int debug_close(struct inode *inode, struct file *file)
{
struct debug_buffer *buf = file->private_data;
if (buf) {
vfree(buf->output_buf);
kfree(buf);
}
return 0;
}
static int debug_async_open(struct inode *inode, struct file *file)
{
file->private_data = alloc_buffer(inode->i_private, fill_async_buffer);
return file->private_data ? 0 : -ENOMEM;
}
static int debug_periodic_open(struct inode *inode, struct file *file)
{
struct debug_buffer *buf;
buf = alloc_buffer(inode->i_private, fill_periodic_buffer);
if (!buf)
return -ENOMEM;
buf->alloc_size = (sizeof(void *) == 4 ? 6 : 8)*PAGE_SIZE;
file->private_data = buf;
return 0;
}
static int debug_registers_open(struct inode *inode, struct file *file)
{
file->private_data = alloc_buffer(inode->i_private,
fill_registers_buffer);
return file->private_data ? 0 : -ENOMEM;
}
static inline void create_debug_files (struct fusbh200_hcd *fusbh200)
{
struct usb_bus *bus = &fusbh200_to_hcd(fusbh200)->self;
fusbh200->debug_dir = debugfs_create_dir(bus->bus_name, fusbh200_debug_root);
if (!fusbh200->debug_dir)
return;
if (!debugfs_create_file("async", S_IRUGO, fusbh200->debug_dir, bus,
&debug_async_fops))
goto file_error;
if (!debugfs_create_file("periodic", S_IRUGO, fusbh200->debug_dir, bus,
&debug_periodic_fops))
goto file_error;
if (!debugfs_create_file("registers", S_IRUGO, fusbh200->debug_dir, bus,
&debug_registers_fops))
goto file_error;
return;
file_error:
debugfs_remove_recursive(fusbh200->debug_dir);
}
static inline void remove_debug_files (struct fusbh200_hcd *fusbh200)
{
debugfs_remove_recursive(fusbh200->debug_dir);
}
static int handshake (struct fusbh200_hcd *fusbh200, void __iomem *ptr,
u32 mask, u32 done, int usec)
{
u32 result;
do {
result = fusbh200_readl(fusbh200, ptr);
if (result == ~(u32)0)
return -ENODEV;
result &= mask;
if (result == done)
return 0;
udelay (1);
usec--;
} while (usec > 0);
return -ETIMEDOUT;
}
static int fusbh200_halt (struct fusbh200_hcd *fusbh200)
{
u32 temp;
spin_lock_irq(&fusbh200->lock);
fusbh200_writel(fusbh200, 0, &fusbh200->regs->intr_enable);
fusbh200->command &= ~CMD_RUN;
temp = fusbh200_readl(fusbh200, &fusbh200->regs->command);
temp &= ~(CMD_RUN | CMD_IAAD);
fusbh200_writel(fusbh200, temp, &fusbh200->regs->command);
spin_unlock_irq(&fusbh200->lock);
synchronize_irq(fusbh200_to_hcd(fusbh200)->irq);
return handshake(fusbh200, &fusbh200->regs->status,
STS_HALT, STS_HALT, 16 * 125);
}
static int fusbh200_reset (struct fusbh200_hcd *fusbh200)
{
int retval;
u32 command = fusbh200_readl(fusbh200, &fusbh200->regs->command);
if (fusbh200->debug && !dbgp_reset_prep(fusbh200_to_hcd(fusbh200)))
fusbh200->debug = NULL;
command |= CMD_RESET;
dbg_cmd (fusbh200, "reset", command);
fusbh200_writel(fusbh200, command, &fusbh200->regs->command);
fusbh200->rh_state = FUSBH200_RH_HALTED;
fusbh200->next_statechange = jiffies;
retval = handshake (fusbh200, &fusbh200->regs->command,
CMD_RESET, 0, 250 * 1000);
if (retval)
return retval;
if (fusbh200->debug)
dbgp_external_startup(fusbh200_to_hcd(fusbh200));
fusbh200->port_c_suspend = fusbh200->suspended_ports =
fusbh200->resuming_ports = 0;
return retval;
}
static void fusbh200_quiesce (struct fusbh200_hcd *fusbh200)
{
u32 temp;
if (fusbh200->rh_state != FUSBH200_RH_RUNNING)
return;
temp = (fusbh200->command << 10) & (STS_ASS | STS_PSS);
handshake(fusbh200, &fusbh200->regs->status, STS_ASS | STS_PSS, temp, 16 * 125);
spin_lock_irq(&fusbh200->lock);
fusbh200->command &= ~(CMD_ASE | CMD_PSE);
fusbh200_writel(fusbh200, fusbh200->command, &fusbh200->regs->command);
spin_unlock_irq(&fusbh200->lock);
handshake(fusbh200, &fusbh200->regs->status, STS_ASS | STS_PSS, 0, 16 * 125);
}
static void fusbh200_set_command_bit(struct fusbh200_hcd *fusbh200, u32 bit)
{
fusbh200->command |= bit;
fusbh200_writel(fusbh200, fusbh200->command, &fusbh200->regs->command);
fusbh200_readl(fusbh200, &fusbh200->regs->command);
}
static void fusbh200_clear_command_bit(struct fusbh200_hcd *fusbh200, u32 bit)
{
fusbh200->command &= ~bit;
fusbh200_writel(fusbh200, fusbh200->command, &fusbh200->regs->command);
fusbh200_readl(fusbh200, &fusbh200->regs->command);
}
static void fusbh200_enable_event(struct fusbh200_hcd *fusbh200, unsigned event,
bool resched)
{
ktime_t *timeout = &fusbh200->hr_timeouts[event];
if (resched)
*timeout = ktime_add(ktime_get(),
ktime_set(0, event_delays_ns[event]));
fusbh200->enabled_hrtimer_events |= (1 << event);
if (event < fusbh200->next_hrtimer_event) {
fusbh200->next_hrtimer_event = event;
hrtimer_start_range_ns(&fusbh200->hrtimer, *timeout,
NSEC_PER_MSEC, HRTIMER_MODE_ABS);
}
}
static void fusbh200_poll_ASS(struct fusbh200_hcd *fusbh200)
{
unsigned actual, want;
if (fusbh200->rh_state != FUSBH200_RH_RUNNING)
return;
want = (fusbh200->command & CMD_ASE) ? STS_ASS : 0;
actual = fusbh200_readl(fusbh200, &fusbh200->regs->status) & STS_ASS;
if (want != actual) {
if (fusbh200->ASS_poll_count++ < 20) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_POLL_ASS, true);
return;
}
fusbh200_dbg(fusbh200, "Waited too long for the async schedule status (%x/%x), giving up\n",
want, actual);
}
fusbh200->ASS_poll_count = 0;
if (want == 0) {
if (fusbh200->async_count > 0)
fusbh200_set_command_bit(fusbh200, CMD_ASE);
} else {
if (fusbh200->async_count == 0) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_DISABLE_ASYNC,
true);
}
}
}
static void fusbh200_disable_ASE(struct fusbh200_hcd *fusbh200)
{
fusbh200_clear_command_bit(fusbh200, CMD_ASE);
}
static void fusbh200_poll_PSS(struct fusbh200_hcd *fusbh200)
{
unsigned actual, want;
if (fusbh200->rh_state != FUSBH200_RH_RUNNING)
return;
want = (fusbh200->command & CMD_PSE) ? STS_PSS : 0;
actual = fusbh200_readl(fusbh200, &fusbh200->regs->status) & STS_PSS;
if (want != actual) {
if (fusbh200->PSS_poll_count++ < 20) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_POLL_PSS, true);
return;
}
fusbh200_dbg(fusbh200, "Waited too long for the periodic schedule status (%x/%x), giving up\n",
want, actual);
}
fusbh200->PSS_poll_count = 0;
if (want == 0) {
if (fusbh200->periodic_count > 0)
fusbh200_set_command_bit(fusbh200, CMD_PSE);
} else {
if (fusbh200->periodic_count == 0) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_DISABLE_PERIODIC,
true);
}
}
}
static void fusbh200_disable_PSE(struct fusbh200_hcd *fusbh200)
{
fusbh200_clear_command_bit(fusbh200, CMD_PSE);
}
static void fusbh200_handle_controller_death(struct fusbh200_hcd *fusbh200)
{
if (!(fusbh200_readl(fusbh200, &fusbh200->regs->status) & STS_HALT)) {
if (fusbh200->died_poll_count++ < 5) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_POLL_DEAD, true);
return;
}
fusbh200_warn(fusbh200, "Waited too long for the controller to stop, giving up\n");
}
fusbh200->rh_state = FUSBH200_RH_HALTED;
fusbh200_writel(fusbh200, 0, &fusbh200->regs->intr_enable);
fusbh200_work(fusbh200);
end_unlink_async(fusbh200);
}
static void fusbh200_handle_intr_unlinks(struct fusbh200_hcd *fusbh200)
{
bool stopped = (fusbh200->rh_state < FUSBH200_RH_RUNNING);
fusbh200->intr_unlinking = true;
while (fusbh200->intr_unlink) {
struct fusbh200_qh *qh = fusbh200->intr_unlink;
if (!stopped && qh->unlink_cycle == fusbh200->intr_unlink_cycle)
break;
fusbh200->intr_unlink = qh->unlink_next;
qh->unlink_next = NULL;
end_unlink_intr(fusbh200, qh);
}
if (fusbh200->intr_unlink) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_UNLINK_INTR, true);
++fusbh200->intr_unlink_cycle;
}
fusbh200->intr_unlinking = false;
}
static void start_free_itds(struct fusbh200_hcd *fusbh200)
{
if (!(fusbh200->enabled_hrtimer_events & BIT(FUSBH200_HRTIMER_FREE_ITDS))) {
fusbh200->last_itd_to_free = list_entry(
fusbh200->cached_itd_list.prev,
struct fusbh200_itd, itd_list);
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_FREE_ITDS, true);
}
}
static void end_free_itds(struct fusbh200_hcd *fusbh200)
{
struct fusbh200_itd *itd, *n;
if (fusbh200->rh_state < FUSBH200_RH_RUNNING) {
fusbh200->last_itd_to_free = NULL;
}
list_for_each_entry_safe(itd, n, &fusbh200->cached_itd_list, itd_list) {
list_del(&itd->itd_list);
dma_pool_free(fusbh200->itd_pool, itd, itd->itd_dma);
if (itd == fusbh200->last_itd_to_free)
break;
}
if (!list_empty(&fusbh200->cached_itd_list))
start_free_itds(fusbh200);
}
static void fusbh200_iaa_watchdog(struct fusbh200_hcd *fusbh200)
{
if (fusbh200->rh_state != FUSBH200_RH_RUNNING)
return;
if (fusbh200->async_iaa) {
u32 cmd, status;
cmd = fusbh200_readl(fusbh200, &fusbh200->regs->command);
status = fusbh200_readl(fusbh200, &fusbh200->regs->status);
if ((status & STS_IAA) || !(cmd & CMD_IAAD)) {
COUNT(fusbh200->stats.lost_iaa);
fusbh200_writel(fusbh200, STS_IAA, &fusbh200->regs->status);
}
fusbh200_dbg(fusbh200, "IAA watchdog: status %x cmd %x\n",
status, cmd);
end_unlink_async(fusbh200);
}
}
static void turn_on_io_watchdog(struct fusbh200_hcd *fusbh200)
{
if (fusbh200->rh_state != FUSBH200_RH_RUNNING ||
(fusbh200->enabled_hrtimer_events &
BIT(FUSBH200_HRTIMER_IO_WATCHDOG)))
return;
if (fusbh200->isoc_count > 0 || (fusbh200->need_io_watchdog &&
fusbh200->async_count + fusbh200->intr_count > 0))
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_IO_WATCHDOG, true);
}
static enum hrtimer_restart fusbh200_hrtimer_func(struct hrtimer *t)
{
struct fusbh200_hcd *fusbh200 = container_of(t, struct fusbh200_hcd, hrtimer);
ktime_t now;
unsigned long events;
unsigned long flags;
unsigned e;
spin_lock_irqsave(&fusbh200->lock, flags);
events = fusbh200->enabled_hrtimer_events;
fusbh200->enabled_hrtimer_events = 0;
fusbh200->next_hrtimer_event = FUSBH200_HRTIMER_NO_EVENT;
now = ktime_get();
for_each_set_bit(e, &events, FUSBH200_HRTIMER_NUM_EVENTS) {
if (now.tv64 >= fusbh200->hr_timeouts[e].tv64)
event_handlers[e](fusbh200);
else
fusbh200_enable_event(fusbh200, e, false);
}
spin_unlock_irqrestore(&fusbh200->lock, flags);
return HRTIMER_NORESTART;
}
static int check_reset_complete (
struct fusbh200_hcd *fusbh200,
int index,
u32 __iomem *status_reg,
int port_status
) {
if (!(port_status & PORT_CONNECT))
return port_status;
if (!(port_status & PORT_PE)) {
fusbh200_dbg (fusbh200,
"Failed to enable port %d on root hub TT\n",
index+1);
return port_status;
} else {
fusbh200_dbg(fusbh200, "port %d reset complete, port enabled\n",
index + 1);
}
return port_status;
}
static int
fusbh200_hub_status_data (struct usb_hcd *hcd, char *buf)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
u32 temp, status;
u32 mask;
int retval = 1;
unsigned long flags;
buf [0] = 0;
status = fusbh200->resuming_ports;
mask = PORT_CSC | PORT_PEC;
spin_lock_irqsave (&fusbh200->lock, flags);
temp = fusbh200_readl(fusbh200, &fusbh200->regs->port_status);
if ((temp & mask) != 0 || test_bit(0, &fusbh200->port_c_suspend)
|| (fusbh200->reset_done[0] && time_after_eq(
jiffies, fusbh200->reset_done[0]))) {
buf [0] |= 1 << 1;
status = STS_PCD;
}
spin_unlock_irqrestore (&fusbh200->lock, flags);
return status ? retval : 0;
}
static void
fusbh200_hub_descriptor (
struct fusbh200_hcd *fusbh200,
struct usb_hub_descriptor *desc
) {
int ports = HCS_N_PORTS (fusbh200->hcs_params);
u16 temp;
desc->bDescriptorType = USB_DT_HUB;
desc->bPwrOn2PwrGood = 10;
desc->bHubContrCurrent = 0;
desc->bNbrPorts = ports;
temp = 1 + (ports / 8);
desc->bDescLength = 7 + 2 * temp;
memset(&desc->u.hs.DeviceRemovable[0], 0, temp);
memset(&desc->u.hs.DeviceRemovable[temp], 0xff, temp);
temp = HUB_CHAR_INDV_PORT_OCPM;
temp |= HUB_CHAR_NO_LPSM;
desc->wHubCharacteristics = cpu_to_le16(temp);
}
static int fusbh200_hub_control (
struct usb_hcd *hcd,
u16 typeReq,
u16 wValue,
u16 wIndex,
char *buf,
u16 wLength
) {
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
int ports = HCS_N_PORTS (fusbh200->hcs_params);
u32 __iomem *status_reg = &fusbh200->regs->port_status;
u32 temp, temp1, status;
unsigned long flags;
int retval = 0;
unsigned selector;
spin_lock_irqsave (&fusbh200->lock, flags);
switch (typeReq) {
case ClearHubFeature:
switch (wValue) {
case C_HUB_LOCAL_POWER:
case C_HUB_OVER_CURRENT:
break;
default:
goto error;
}
break;
case ClearPortFeature:
if (!wIndex || wIndex > ports)
goto error;
wIndex--;
temp = fusbh200_readl(fusbh200, status_reg);
temp &= ~PORT_RWC_BITS;
switch (wValue) {
case USB_PORT_FEAT_ENABLE:
fusbh200_writel(fusbh200, temp & ~PORT_PE, status_reg);
break;
case USB_PORT_FEAT_C_ENABLE:
fusbh200_writel(fusbh200, temp | PORT_PEC, status_reg);
break;
case USB_PORT_FEAT_SUSPEND:
if (temp & PORT_RESET)
goto error;
if (!(temp & PORT_SUSPEND))
break;
if ((temp & PORT_PE) == 0)
goto error;
fusbh200_writel(fusbh200, temp | PORT_RESUME, status_reg);
fusbh200->reset_done[wIndex] = jiffies
+ msecs_to_jiffies(USB_RESUME_TIMEOUT);
break;
case USB_PORT_FEAT_C_SUSPEND:
clear_bit(wIndex, &fusbh200->port_c_suspend);
break;
case USB_PORT_FEAT_C_CONNECTION:
fusbh200_writel(fusbh200, temp | PORT_CSC, status_reg);
break;
case USB_PORT_FEAT_C_OVER_CURRENT:
fusbh200_writel(fusbh200, temp | BMISR_OVC, &fusbh200->regs->bmisr);
break;
case USB_PORT_FEAT_C_RESET:
break;
default:
goto error;
}
fusbh200_readl(fusbh200, &fusbh200->regs->command);
break;
case GetHubDescriptor:
fusbh200_hub_descriptor (fusbh200, (struct usb_hub_descriptor *)
buf);
break;
case GetHubStatus:
memset (buf, 0, 4);
break;
case GetPortStatus:
if (!wIndex || wIndex > ports)
goto error;
wIndex--;
status = 0;
temp = fusbh200_readl(fusbh200, status_reg);
if (temp & PORT_CSC)
status |= USB_PORT_STAT_C_CONNECTION << 16;
if (temp & PORT_PEC)
status |= USB_PORT_STAT_C_ENABLE << 16;
temp1 = fusbh200_readl(fusbh200, &fusbh200->regs->bmisr);
if (temp1 & BMISR_OVC)
status |= USB_PORT_STAT_C_OVERCURRENT << 16;
if (temp & PORT_RESUME) {
if (!fusbh200->reset_done[wIndex]) {
fusbh200->reset_done[wIndex] = jiffies
+ msecs_to_jiffies(20);
mod_timer(&fusbh200_to_hcd(fusbh200)->rh_timer,
fusbh200->reset_done[wIndex]);
}
else if (time_after_eq(jiffies,
fusbh200->reset_done[wIndex])) {
clear_bit(wIndex, &fusbh200->suspended_ports);
set_bit(wIndex, &fusbh200->port_c_suspend);
fusbh200->reset_done[wIndex] = 0;
temp = fusbh200_readl(fusbh200, status_reg);
fusbh200_writel(fusbh200,
temp & ~(PORT_RWC_BITS | PORT_RESUME),
status_reg);
clear_bit(wIndex, &fusbh200->resuming_ports);
retval = handshake(fusbh200, status_reg,
PORT_RESUME, 0, 2000 );
if (retval != 0) {
fusbh200_err(fusbh200,
"port %d resume error %d\n",
wIndex + 1, retval);
goto error;
}
temp &= ~(PORT_SUSPEND|PORT_RESUME|(3<<10));
}
}
if ((temp & PORT_RESET)
&& time_after_eq(jiffies,
fusbh200->reset_done[wIndex])) {
status |= USB_PORT_STAT_C_RESET << 16;
fusbh200->reset_done [wIndex] = 0;
clear_bit(wIndex, &fusbh200->resuming_ports);
fusbh200_writel(fusbh200, temp & ~(PORT_RWC_BITS | PORT_RESET),
status_reg);
retval = handshake(fusbh200, status_reg,
PORT_RESET, 0, 1000);
if (retval != 0) {
fusbh200_err (fusbh200, "port %d reset error %d\n",
wIndex + 1, retval);
goto error;
}
temp = check_reset_complete (fusbh200, wIndex, status_reg,
fusbh200_readl(fusbh200, status_reg));
}
if (!(temp & (PORT_RESUME|PORT_RESET))) {
fusbh200->reset_done[wIndex] = 0;
clear_bit(wIndex, &fusbh200->resuming_ports);
}
if ((temp & PORT_CONNECT) &&
test_bit(wIndex, &fusbh200->companion_ports)) {
temp &= ~PORT_RWC_BITS;
fusbh200_writel(fusbh200, temp, status_reg);
fusbh200_dbg(fusbh200, "port %d --> companion\n", wIndex + 1);
temp = fusbh200_readl(fusbh200, status_reg);
}
if (temp & PORT_CONNECT) {
status |= USB_PORT_STAT_CONNECTION;
status |= fusbh200_port_speed(fusbh200, temp);
}
if (temp & PORT_PE)
status |= USB_PORT_STAT_ENABLE;
if (temp & (PORT_SUSPEND|PORT_RESUME)) {
status |= USB_PORT_STAT_SUSPEND;
} else if (test_bit(wIndex, &fusbh200->suspended_ports)) {
clear_bit(wIndex, &fusbh200->suspended_ports);
clear_bit(wIndex, &fusbh200->resuming_ports);
fusbh200->reset_done[wIndex] = 0;
if (temp & PORT_PE)
set_bit(wIndex, &fusbh200->port_c_suspend);
}
temp1 = fusbh200_readl(fusbh200, &fusbh200->regs->bmisr);
if (temp1 & BMISR_OVC)
status |= USB_PORT_STAT_OVERCURRENT;
if (temp & PORT_RESET)
status |= USB_PORT_STAT_RESET;
if (test_bit(wIndex, &fusbh200->port_c_suspend))
status |= USB_PORT_STAT_C_SUSPEND << 16;
if (status & ~0xffff)
dbg_port(fusbh200, "GetStatus", wIndex + 1, temp);
put_unaligned_le32(status, buf);
break;
case SetHubFeature:
switch (wValue) {
case C_HUB_LOCAL_POWER:
case C_HUB_OVER_CURRENT:
break;
default:
goto error;
}
break;
case SetPortFeature:
selector = wIndex >> 8;
wIndex &= 0xff;
if (!wIndex || wIndex > ports)
goto error;
wIndex--;
temp = fusbh200_readl(fusbh200, status_reg);
temp &= ~PORT_RWC_BITS;
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
if ((temp & PORT_PE) == 0
|| (temp & PORT_RESET) != 0)
goto error;
fusbh200_writel(fusbh200, temp | PORT_SUSPEND, status_reg);
set_bit(wIndex, &fusbh200->suspended_ports);
break;
case USB_PORT_FEAT_RESET:
if (temp & PORT_RESUME)
goto error;
fusbh200_dbg(fusbh200, "port %d reset\n", wIndex + 1);
temp |= PORT_RESET;
temp &= ~PORT_PE;
fusbh200->reset_done [wIndex] = jiffies
+ msecs_to_jiffies (50);
fusbh200_writel(fusbh200, temp, status_reg);
break;
case USB_PORT_FEAT_TEST:
if (!selector || selector > 5)
goto error;
spin_unlock_irqrestore(&fusbh200->lock, flags);
fusbh200_quiesce(fusbh200);
spin_lock_irqsave(&fusbh200->lock, flags);
temp = fusbh200_readl(fusbh200, status_reg) & ~PORT_RWC_BITS;
if (temp & PORT_PE)
fusbh200_writel(fusbh200, temp | PORT_SUSPEND,
status_reg);
spin_unlock_irqrestore(&fusbh200->lock, flags);
fusbh200_halt(fusbh200);
spin_lock_irqsave(&fusbh200->lock, flags);
temp = fusbh200_readl(fusbh200, status_reg);
temp |= selector << 16;
fusbh200_writel(fusbh200, temp, status_reg);
break;
default:
goto error;
}
fusbh200_readl(fusbh200, &fusbh200->regs->command);
break;
default:
error:
retval = -EPIPE;
}
spin_unlock_irqrestore (&fusbh200->lock, flags);
return retval;
}
static void __maybe_unused fusbh200_relinquish_port(struct usb_hcd *hcd,
int portnum)
{
return;
}
static int __maybe_unused fusbh200_port_handed_over(struct usb_hcd *hcd,
int portnum)
{
return 0;
}
static inline void fusbh200_qtd_init(struct fusbh200_hcd *fusbh200, struct fusbh200_qtd *qtd,
dma_addr_t dma)
{
memset (qtd, 0, sizeof *qtd);
qtd->qtd_dma = dma;
qtd->hw_token = cpu_to_hc32(fusbh200, QTD_STS_HALT);
qtd->hw_next = FUSBH200_LIST_END(fusbh200);
qtd->hw_alt_next = FUSBH200_LIST_END(fusbh200);
INIT_LIST_HEAD (&qtd->qtd_list);
}
static struct fusbh200_qtd *fusbh200_qtd_alloc (struct fusbh200_hcd *fusbh200, gfp_t flags)
{
struct fusbh200_qtd *qtd;
dma_addr_t dma;
qtd = dma_pool_alloc (fusbh200->qtd_pool, flags, &dma);
if (qtd != NULL) {
fusbh200_qtd_init(fusbh200, qtd, dma);
}
return qtd;
}
static inline void fusbh200_qtd_free (struct fusbh200_hcd *fusbh200, struct fusbh200_qtd *qtd)
{
dma_pool_free (fusbh200->qtd_pool, qtd, qtd->qtd_dma);
}
static void qh_destroy(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
if (!list_empty (&qh->qtd_list) || qh->qh_next.ptr) {
fusbh200_dbg (fusbh200, "unused qh not empty!\n");
BUG ();
}
if (qh->dummy)
fusbh200_qtd_free (fusbh200, qh->dummy);
dma_pool_free(fusbh200->qh_pool, qh->hw, qh->qh_dma);
kfree(qh);
}
static struct fusbh200_qh *fusbh200_qh_alloc (struct fusbh200_hcd *fusbh200, gfp_t flags)
{
struct fusbh200_qh *qh;
dma_addr_t dma;
qh = kzalloc(sizeof *qh, GFP_ATOMIC);
if (!qh)
goto done;
qh->hw = (struct fusbh200_qh_hw *)
dma_pool_alloc(fusbh200->qh_pool, flags, &dma);
if (!qh->hw)
goto fail;
memset(qh->hw, 0, sizeof *qh->hw);
qh->qh_dma = dma;
INIT_LIST_HEAD (&qh->qtd_list);
qh->dummy = fusbh200_qtd_alloc (fusbh200, flags);
if (qh->dummy == NULL) {
fusbh200_dbg (fusbh200, "no dummy td\n");
goto fail1;
}
done:
return qh;
fail1:
dma_pool_free(fusbh200->qh_pool, qh->hw, qh->qh_dma);
fail:
kfree(qh);
return NULL;
}
static void fusbh200_mem_cleanup (struct fusbh200_hcd *fusbh200)
{
if (fusbh200->async)
qh_destroy(fusbh200, fusbh200->async);
fusbh200->async = NULL;
if (fusbh200->dummy)
qh_destroy(fusbh200, fusbh200->dummy);
fusbh200->dummy = NULL;
if (fusbh200->qtd_pool)
dma_pool_destroy (fusbh200->qtd_pool);
fusbh200->qtd_pool = NULL;
if (fusbh200->qh_pool) {
dma_pool_destroy (fusbh200->qh_pool);
fusbh200->qh_pool = NULL;
}
if (fusbh200->itd_pool)
dma_pool_destroy (fusbh200->itd_pool);
fusbh200->itd_pool = NULL;
if (fusbh200->periodic)
dma_free_coherent (fusbh200_to_hcd(fusbh200)->self.controller,
fusbh200->periodic_size * sizeof (u32),
fusbh200->periodic, fusbh200->periodic_dma);
fusbh200->periodic = NULL;
kfree(fusbh200->pshadow);
fusbh200->pshadow = NULL;
}
static int fusbh200_mem_init (struct fusbh200_hcd *fusbh200, gfp_t flags)
{
int i;
fusbh200->qtd_pool = dma_pool_create ("fusbh200_qtd",
fusbh200_to_hcd(fusbh200)->self.controller,
sizeof (struct fusbh200_qtd),
32 ,
4096 );
if (!fusbh200->qtd_pool) {
goto fail;
}
fusbh200->qh_pool = dma_pool_create ("fusbh200_qh",
fusbh200_to_hcd(fusbh200)->self.controller,
sizeof(struct fusbh200_qh_hw),
32 ,
4096 );
if (!fusbh200->qh_pool) {
goto fail;
}
fusbh200->async = fusbh200_qh_alloc (fusbh200, flags);
if (!fusbh200->async) {
goto fail;
}
fusbh200->itd_pool = dma_pool_create ("fusbh200_itd",
fusbh200_to_hcd(fusbh200)->self.controller,
sizeof (struct fusbh200_itd),
64 ,
4096 );
if (!fusbh200->itd_pool) {
goto fail;
}
fusbh200->periodic = (__le32 *)
dma_alloc_coherent (fusbh200_to_hcd(fusbh200)->self.controller,
fusbh200->periodic_size * sizeof(__le32),
&fusbh200->periodic_dma, 0);
if (fusbh200->periodic == NULL) {
goto fail;
}
for (i = 0; i < fusbh200->periodic_size; i++)
fusbh200->periodic[i] = FUSBH200_LIST_END(fusbh200);
fusbh200->pshadow = kcalloc(fusbh200->periodic_size, sizeof(void *), flags);
if (fusbh200->pshadow != NULL)
return 0;
fail:
fusbh200_dbg (fusbh200, "couldn't init memory\n");
fusbh200_mem_cleanup (fusbh200);
return -ENOMEM;
}
static int
qtd_fill(struct fusbh200_hcd *fusbh200, struct fusbh200_qtd *qtd, dma_addr_t buf,
size_t len, int token, int maxpacket)
{
int i, count;
u64 addr = buf;
qtd->hw_buf[0] = cpu_to_hc32(fusbh200, (u32)addr);
qtd->hw_buf_hi[0] = cpu_to_hc32(fusbh200, (u32)(addr >> 32));
count = 0x1000 - (buf & 0x0fff);
if (likely (len < count))
count = len;
else {
buf += 0x1000;
buf &= ~0x0fff;
for (i = 1; count < len && i < 5; i++) {
addr = buf;
qtd->hw_buf[i] = cpu_to_hc32(fusbh200, (u32)addr);
qtd->hw_buf_hi[i] = cpu_to_hc32(fusbh200,
(u32)(addr >> 32));
buf += 0x1000;
if ((count + 0x1000) < len)
count += 0x1000;
else
count = len;
}
if (count != len)
count -= (count % maxpacket);
}
qtd->hw_token = cpu_to_hc32(fusbh200, (count << 16) | token);
qtd->length = count;
return count;
}
static inline void
qh_update (struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh, struct fusbh200_qtd *qtd)
{
struct fusbh200_qh_hw *hw = qh->hw;
BUG_ON(qh->qh_state != QH_STATE_IDLE);
hw->hw_qtd_next = QTD_NEXT(fusbh200, qtd->qtd_dma);
hw->hw_alt_next = FUSBH200_LIST_END(fusbh200);
if (!(hw->hw_info1 & cpu_to_hc32(fusbh200, QH_TOGGLE_CTL))) {
unsigned is_out, epnum;
is_out = qh->is_out;
epnum = (hc32_to_cpup(fusbh200, &hw->hw_info1) >> 8) & 0x0f;
if (unlikely (!usb_gettoggle (qh->dev, epnum, is_out))) {
hw->hw_token &= ~cpu_to_hc32(fusbh200, QTD_TOGGLE);
usb_settoggle (qh->dev, epnum, is_out, 1);
}
}
hw->hw_token &= cpu_to_hc32(fusbh200, QTD_TOGGLE | QTD_STS_PING);
}
static void
qh_refresh (struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
struct fusbh200_qtd *qtd;
if (list_empty (&qh->qtd_list))
qtd = qh->dummy;
else {
qtd = list_entry (qh->qtd_list.next,
struct fusbh200_qtd, qtd_list);
if (cpu_to_hc32(fusbh200, qtd->qtd_dma) == qh->hw->hw_current) {
qh->hw->hw_qtd_next = qtd->hw_next;
qtd = NULL;
}
}
if (qtd)
qh_update (fusbh200, qh, qtd);
}
static void fusbh200_clear_tt_buffer_complete(struct usb_hcd *hcd,
struct usb_host_endpoint *ep)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200(hcd);
struct fusbh200_qh *qh = ep->hcpriv;
unsigned long flags;
spin_lock_irqsave(&fusbh200->lock, flags);
qh->clearing_tt = 0;
if (qh->qh_state == QH_STATE_IDLE && !list_empty(&qh->qtd_list)
&& fusbh200->rh_state == FUSBH200_RH_RUNNING)
qh_link_async(fusbh200, qh);
spin_unlock_irqrestore(&fusbh200->lock, flags);
}
static void fusbh200_clear_tt_buffer(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh,
struct urb *urb, u32 token)
{
if (urb->dev->tt && !usb_pipeint(urb->pipe) && !qh->clearing_tt) {
struct usb_device *tt = urb->dev->tt->hub;
dev_dbg(&tt->dev,
"clear tt buffer port %d, a%d ep%d t%08x\n",
urb->dev->ttport, urb->dev->devnum,
usb_pipeendpoint(urb->pipe), token);
if (urb->dev->tt->hub !=
fusbh200_to_hcd(fusbh200)->self.root_hub) {
if (usb_hub_clear_tt_buffer(urb) == 0)
qh->clearing_tt = 1;
}
}
}
static int qtd_copy_status (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
size_t length,
u32 token
)
{
int status = -EINPROGRESS;
if (likely (QTD_PID (token) != 2))
urb->actual_length += length - QTD_LENGTH (token);
if (unlikely(urb->unlinked))
return status;
if (unlikely (IS_SHORT_READ (token)))
status = -EREMOTEIO;
if (token & QTD_STS_HALT) {
if (token & QTD_STS_BABBLE) {
status = -EOVERFLOW;
} else if (QTD_CERR(token)) {
status = -EPIPE;
} else if (token & QTD_STS_MMF) {
status = -EPROTO;
} else if (token & QTD_STS_DBE) {
status = (QTD_PID (token) == 1)
? -ENOSR
: -ECOMM;
} else if (token & QTD_STS_XACT) {
fusbh200_dbg(fusbh200, "devpath %s ep%d%s 3strikes\n",
urb->dev->devpath,
usb_pipeendpoint(urb->pipe),
usb_pipein(urb->pipe) ? "in" : "out");
status = -EPROTO;
} else {
status = -EPROTO;
}
fusbh200_dbg(fusbh200,
"dev%d ep%d%s qtd token %08x --> status %d\n",
usb_pipedevice (urb->pipe),
usb_pipeendpoint (urb->pipe),
usb_pipein (urb->pipe) ? "in" : "out",
token, status);
}
return status;
}
static void
fusbh200_urb_done(struct fusbh200_hcd *fusbh200, struct urb *urb, int status)
__releases(fusbh200->lock)
__acquires(fusbh200->lock)
{
if (likely (urb->hcpriv != NULL)) {
struct fusbh200_qh *qh = (struct fusbh200_qh *) urb->hcpriv;
if ((qh->hw->hw_info2 & cpu_to_hc32(fusbh200, QH_SMASK)) != 0) {
fusbh200_to_hcd(fusbh200)->self.bandwidth_int_reqs--;
}
}
if (unlikely(urb->unlinked)) {
COUNT(fusbh200->stats.unlink);
} else {
if (status == -EINPROGRESS || status == -EREMOTEIO)
status = 0;
COUNT(fusbh200->stats.complete);
}
#ifdef FUSBH200_URB_TRACE
fusbh200_dbg (fusbh200,
"%s %s urb %p ep%d%s status %d len %d/%d\n",
__func__, urb->dev->devpath, urb,
usb_pipeendpoint (urb->pipe),
usb_pipein (urb->pipe) ? "in" : "out",
status,
urb->actual_length, urb->transfer_buffer_length);
#endif
usb_hcd_unlink_urb_from_ep(fusbh200_to_hcd(fusbh200), urb);
spin_unlock (&fusbh200->lock);
usb_hcd_giveback_urb(fusbh200_to_hcd(fusbh200), urb, status);
spin_lock (&fusbh200->lock);
}
static unsigned
qh_completions (struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
struct fusbh200_qtd *last, *end = qh->dummy;
struct list_head *entry, *tmp;
int last_status;
int stopped;
unsigned count = 0;
u8 state;
struct fusbh200_qh_hw *hw = qh->hw;
if (unlikely (list_empty (&qh->qtd_list)))
return count;
state = qh->qh_state;
qh->qh_state = QH_STATE_COMPLETING;
stopped = (state == QH_STATE_IDLE);
rescan:
last = NULL;
last_status = -EINPROGRESS;
qh->needs_rescan = 0;
list_for_each_safe (entry, tmp, &qh->qtd_list) {
struct fusbh200_qtd *qtd;
struct urb *urb;
u32 token = 0;
qtd = list_entry (entry, struct fusbh200_qtd, qtd_list);
urb = qtd->urb;
if (last) {
if (likely (last->urb != urb)) {
fusbh200_urb_done(fusbh200, last->urb, last_status);
count++;
last_status = -EINPROGRESS;
}
fusbh200_qtd_free (fusbh200, last);
last = NULL;
}
if (qtd == end)
break;
rmb ();
token = hc32_to_cpu(fusbh200, qtd->hw_token);
retry_xacterr:
if ((token & QTD_STS_ACTIVE) == 0) {
if (token & QTD_STS_DBE)
fusbh200_dbg(fusbh200,
"detected DataBufferErr for urb %p ep%d%s len %d, qtd %p [qh %p]\n",
urb,
usb_endpoint_num(&urb->ep->desc),
usb_endpoint_dir_in(&urb->ep->desc) ? "in" : "out",
urb->transfer_buffer_length,
qtd,
qh);
if ((token & QTD_STS_HALT) != 0) {
if ((token & QTD_STS_XACT) &&
QTD_CERR(token) == 0 &&
++qh->xacterrs < QH_XACTERR_MAX &&
!urb->unlinked) {
fusbh200_dbg(fusbh200,
"detected XactErr len %zu/%zu retry %d\n",
qtd->length - QTD_LENGTH(token), qtd->length, qh->xacterrs);
token &= ~QTD_STS_HALT;
token |= QTD_STS_ACTIVE |
(FUSBH200_TUNE_CERR << 10);
qtd->hw_token = cpu_to_hc32(fusbh200,
token);
wmb();
hw->hw_token = cpu_to_hc32(fusbh200,
token);
goto retry_xacterr;
}
stopped = 1;
} else if (IS_SHORT_READ (token)
&& !(qtd->hw_alt_next
& FUSBH200_LIST_END(fusbh200))) {
stopped = 1;
}
} else if (likely (!stopped
&& fusbh200->rh_state >= FUSBH200_RH_RUNNING)) {
break;
} else {
stopped = 1;
if (fusbh200->rh_state < FUSBH200_RH_RUNNING)
last_status = -ESHUTDOWN;
else if (last_status == -EINPROGRESS && !urb->unlinked)
continue;
if (state == QH_STATE_IDLE
&& cpu_to_hc32(fusbh200, qtd->qtd_dma)
== hw->hw_current) {
token = hc32_to_cpu(fusbh200, hw->hw_token);
fusbh200_clear_tt_buffer(fusbh200, qh, urb, token);
}
}
if (last_status == -EINPROGRESS) {
last_status = qtd_copy_status(fusbh200, urb,
qtd->length, token);
if (last_status == -EREMOTEIO
&& (qtd->hw_alt_next
& FUSBH200_LIST_END(fusbh200)))
last_status = -EINPROGRESS;
if (unlikely(last_status != -EINPROGRESS &&
last_status != -EREMOTEIO)) {
if (last_status != -EPIPE)
fusbh200_clear_tt_buffer(fusbh200, qh, urb,
token);
}
}
if (stopped && qtd->qtd_list.prev != &qh->qtd_list) {
last = list_entry (qtd->qtd_list.prev,
struct fusbh200_qtd, qtd_list);
last->hw_next = qtd->hw_next;
}
list_del (&qtd->qtd_list);
last = qtd;
qh->xacterrs = 0;
}
if (likely (last != NULL)) {
fusbh200_urb_done(fusbh200, last->urb, last_status);
count++;
fusbh200_qtd_free (fusbh200, last);
}
if (unlikely(qh->needs_rescan)) {
if (state == QH_STATE_IDLE)
goto rescan;
if (state != QH_STATE_LINKED)
qh->needs_rescan = 0;
}
qh->qh_state = state;
if (stopped != 0 || hw->hw_qtd_next == FUSBH200_LIST_END(fusbh200)) {
switch (state) {
case QH_STATE_IDLE:
qh_refresh(fusbh200, qh);
break;
case QH_STATE_LINKED:
qh->needs_rescan = 1;
break;
}
}
return count;
}
static void qtd_list_free (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
struct list_head *qtd_list
) {
struct list_head *entry, *temp;
list_for_each_safe (entry, temp, qtd_list) {
struct fusbh200_qtd *qtd;
qtd = list_entry (entry, struct fusbh200_qtd, qtd_list);
list_del (&qtd->qtd_list);
fusbh200_qtd_free (fusbh200, qtd);
}
}
static struct list_head *
qh_urb_transaction (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
struct list_head *head,
gfp_t flags
) {
struct fusbh200_qtd *qtd, *qtd_prev;
dma_addr_t buf;
int len, this_sg_len, maxpacket;
int is_input;
u32 token;
int i;
struct scatterlist *sg;
qtd = fusbh200_qtd_alloc (fusbh200, flags);
if (unlikely (!qtd))
return NULL;
list_add_tail (&qtd->qtd_list, head);
qtd->urb = urb;
token = QTD_STS_ACTIVE;
token |= (FUSBH200_TUNE_CERR << 10);
len = urb->transfer_buffer_length;
is_input = usb_pipein (urb->pipe);
if (usb_pipecontrol (urb->pipe)) {
qtd_fill(fusbh200, qtd, urb->setup_dma,
sizeof (struct usb_ctrlrequest),
token | (2 << 8), 8);
token ^= QTD_TOGGLE;
qtd_prev = qtd;
qtd = fusbh200_qtd_alloc (fusbh200, flags);
if (unlikely (!qtd))
goto cleanup;
qtd->urb = urb;
qtd_prev->hw_next = QTD_NEXT(fusbh200, qtd->qtd_dma);
list_add_tail (&qtd->qtd_list, head);
if (len == 0)
token |= (1 << 8);
}
i = urb->num_mapped_sgs;
if (len > 0 && i > 0) {
sg = urb->sg;
buf = sg_dma_address(sg);
this_sg_len = min_t(int, sg_dma_len(sg), len);
} else {
sg = NULL;
buf = urb->transfer_dma;
this_sg_len = len;
}
if (is_input)
token |= (1 << 8);
maxpacket = max_packet(usb_maxpacket(urb->dev, urb->pipe, !is_input));
for (;;) {
int this_qtd_len;
this_qtd_len = qtd_fill(fusbh200, qtd, buf, this_sg_len, token,
maxpacket);
this_sg_len -= this_qtd_len;
len -= this_qtd_len;
buf += this_qtd_len;
if (is_input)
qtd->hw_alt_next = fusbh200->async->hw->hw_alt_next;
if ((maxpacket & (this_qtd_len + (maxpacket - 1))) == 0)
token ^= QTD_TOGGLE;
if (likely(this_sg_len <= 0)) {
if (--i <= 0 || len <= 0)
break;
sg = sg_next(sg);
buf = sg_dma_address(sg);
this_sg_len = min_t(int, sg_dma_len(sg), len);
}
qtd_prev = qtd;
qtd = fusbh200_qtd_alloc (fusbh200, flags);
if (unlikely (!qtd))
goto cleanup;
qtd->urb = urb;
qtd_prev->hw_next = QTD_NEXT(fusbh200, qtd->qtd_dma);
list_add_tail (&qtd->qtd_list, head);
}
if (likely ((urb->transfer_flags & URB_SHORT_NOT_OK) == 0
|| usb_pipecontrol (urb->pipe)))
qtd->hw_alt_next = FUSBH200_LIST_END(fusbh200);
if (likely (urb->transfer_buffer_length != 0)) {
int one_more = 0;
if (usb_pipecontrol (urb->pipe)) {
one_more = 1;
token ^= 0x0100;
token |= QTD_TOGGLE;
} else if (usb_pipeout(urb->pipe)
&& (urb->transfer_flags & URB_ZERO_PACKET)
&& !(urb->transfer_buffer_length % maxpacket)) {
one_more = 1;
}
if (one_more) {
qtd_prev = qtd;
qtd = fusbh200_qtd_alloc (fusbh200, flags);
if (unlikely (!qtd))
goto cleanup;
qtd->urb = urb;
qtd_prev->hw_next = QTD_NEXT(fusbh200, qtd->qtd_dma);
list_add_tail (&qtd->qtd_list, head);
qtd_fill(fusbh200, qtd, 0, 0, token, 0);
}
}
if (likely (!(urb->transfer_flags & URB_NO_INTERRUPT)))
qtd->hw_token |= cpu_to_hc32(fusbh200, QTD_IOC);
return head;
cleanup:
qtd_list_free (fusbh200, urb, head);
return NULL;
}
static struct fusbh200_qh *
qh_make (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
gfp_t flags
) {
struct fusbh200_qh *qh = fusbh200_qh_alloc (fusbh200, flags);
u32 info1 = 0, info2 = 0;
int is_input, type;
int maxp = 0;
struct usb_tt *tt = urb->dev->tt;
struct fusbh200_qh_hw *hw;
if (!qh)
return qh;
info1 |= usb_pipeendpoint (urb->pipe) << 8;
info1 |= usb_pipedevice (urb->pipe) << 0;
is_input = usb_pipein (urb->pipe);
type = usb_pipetype (urb->pipe);
maxp = usb_maxpacket (urb->dev, urb->pipe, !is_input);
if (max_packet(maxp) > 1024) {
fusbh200_dbg(fusbh200, "bogus qh maxpacket %d\n", max_packet(maxp));
goto done;
}
if (type == PIPE_INTERRUPT) {
qh->usecs = NS_TO_US(usb_calc_bus_time(USB_SPEED_HIGH,
is_input, 0,
hb_mult(maxp) * max_packet(maxp)));
qh->start = NO_FRAME;
if (urb->dev->speed == USB_SPEED_HIGH) {
qh->c_usecs = 0;
qh->gap_uf = 0;
qh->period = urb->interval >> 3;
if (qh->period == 0 && urb->interval != 1) {
urb->interval = 1;
} else if (qh->period > fusbh200->periodic_size) {
qh->period = fusbh200->periodic_size;
urb->interval = qh->period << 3;
}
} else {
int think_time;
qh->gap_uf = 1 + usb_calc_bus_time (urb->dev->speed,
is_input, 0, maxp) / (125 * 1000);
if (is_input) {
qh->c_usecs = qh->usecs + HS_USECS (0);
qh->usecs = HS_USECS (1);
} else {
qh->usecs += HS_USECS (1);
qh->c_usecs = HS_USECS (0);
}
think_time = tt ? tt->think_time : 0;
qh->tt_usecs = NS_TO_US (think_time +
usb_calc_bus_time (urb->dev->speed,
is_input, 0, max_packet (maxp)));
qh->period = urb->interval;
if (qh->period > fusbh200->periodic_size) {
qh->period = fusbh200->periodic_size;
urb->interval = qh->period;
}
}
}
qh->dev = urb->dev;
switch (urb->dev->speed) {
case USB_SPEED_LOW:
info1 |= QH_LOW_SPEED;
case USB_SPEED_FULL:
if (type != PIPE_INTERRUPT)
info1 |= (FUSBH200_TUNE_RL_TT << 28);
if (type == PIPE_CONTROL) {
info1 |= QH_CONTROL_EP;
info1 |= QH_TOGGLE_CTL;
}
info1 |= maxp << 16;
info2 |= (FUSBH200_TUNE_MULT_TT << 30);
if (fusbh200_has_fsl_portno_bug(fusbh200))
info2 |= (urb->dev->ttport-1) << 23;
else
info2 |= urb->dev->ttport << 23;
if (tt && tt->hub != fusbh200_to_hcd(fusbh200)->self.root_hub)
info2 |= tt->hub->devnum << 16;
break;
case USB_SPEED_HIGH:
info1 |= QH_HIGH_SPEED;
if (type == PIPE_CONTROL) {
info1 |= (FUSBH200_TUNE_RL_HS << 28);
info1 |= 64 << 16;
info1 |= QH_TOGGLE_CTL;
info2 |= (FUSBH200_TUNE_MULT_HS << 30);
} else if (type == PIPE_BULK) {
info1 |= (FUSBH200_TUNE_RL_HS << 28);
info1 |= max_packet(maxp) << 16;
info2 |= (FUSBH200_TUNE_MULT_HS << 30);
} else {
info1 |= max_packet (maxp) << 16;
info2 |= hb_mult (maxp) << 30;
}
break;
default:
fusbh200_dbg(fusbh200, "bogus dev %p speed %d\n", urb->dev,
urb->dev->speed);
done:
qh_destroy(fusbh200, qh);
return NULL;
}
qh->qh_state = QH_STATE_IDLE;
hw = qh->hw;
hw->hw_info1 = cpu_to_hc32(fusbh200, info1);
hw->hw_info2 = cpu_to_hc32(fusbh200, info2);
qh->is_out = !is_input;
usb_settoggle (urb->dev, usb_pipeendpoint (urb->pipe), !is_input, 1);
qh_refresh (fusbh200, qh);
return qh;
}
static void enable_async(struct fusbh200_hcd *fusbh200)
{
if (fusbh200->async_count++)
return;
fusbh200->enabled_hrtimer_events &= ~BIT(FUSBH200_HRTIMER_DISABLE_ASYNC);
fusbh200_poll_ASS(fusbh200);
turn_on_io_watchdog(fusbh200);
}
static void disable_async(struct fusbh200_hcd *fusbh200)
{
if (--fusbh200->async_count)
return;
WARN_ON(fusbh200->async->qh_next.qh || fusbh200->async_unlink);
fusbh200_poll_ASS(fusbh200);
}
static void qh_link_async (struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
__hc32 dma = QH_NEXT(fusbh200, qh->qh_dma);
struct fusbh200_qh *head;
if (unlikely(qh->clearing_tt))
return;
WARN_ON(qh->qh_state != QH_STATE_IDLE);
qh_refresh(fusbh200, qh);
head = fusbh200->async;
qh->qh_next = head->qh_next;
qh->hw->hw_next = head->hw->hw_next;
wmb ();
head->qh_next.qh = qh;
head->hw->hw_next = dma;
qh->xacterrs = 0;
qh->qh_state = QH_STATE_LINKED;
enable_async(fusbh200);
}
static struct fusbh200_qh *qh_append_tds (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
struct list_head *qtd_list,
int epnum,
void **ptr
)
{
struct fusbh200_qh *qh = NULL;
__hc32 qh_addr_mask = cpu_to_hc32(fusbh200, 0x7f);
qh = (struct fusbh200_qh *) *ptr;
if (unlikely (qh == NULL)) {
qh = qh_make (fusbh200, urb, GFP_ATOMIC);
*ptr = qh;
}
if (likely (qh != NULL)) {
struct fusbh200_qtd *qtd;
if (unlikely (list_empty (qtd_list)))
qtd = NULL;
else
qtd = list_entry (qtd_list->next, struct fusbh200_qtd,
qtd_list);
if (unlikely (epnum == 0)) {
if (usb_pipedevice (urb->pipe) == 0)
qh->hw->hw_info1 &= ~qh_addr_mask;
}
if (likely (qtd != NULL)) {
struct fusbh200_qtd *dummy;
dma_addr_t dma;
__hc32 token;
token = qtd->hw_token;
qtd->hw_token = HALT_BIT(fusbh200);
dummy = qh->dummy;
dma = dummy->qtd_dma;
*dummy = *qtd;
dummy->qtd_dma = dma;
list_del (&qtd->qtd_list);
list_add (&dummy->qtd_list, qtd_list);
list_splice_tail(qtd_list, &qh->qtd_list);
fusbh200_qtd_init(fusbh200, qtd, qtd->qtd_dma);
qh->dummy = qtd;
dma = qtd->qtd_dma;
qtd = list_entry (qh->qtd_list.prev,
struct fusbh200_qtd, qtd_list);
qtd->hw_next = QTD_NEXT(fusbh200, dma);
wmb ();
dummy->hw_token = token;
urb->hcpriv = qh;
}
}
return qh;
}
static int
submit_async (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
struct list_head *qtd_list,
gfp_t mem_flags
) {
int epnum;
unsigned long flags;
struct fusbh200_qh *qh = NULL;
int rc;
epnum = urb->ep->desc.bEndpointAddress;
#ifdef FUSBH200_URB_TRACE
{
struct fusbh200_qtd *qtd;
qtd = list_entry(qtd_list->next, struct fusbh200_qtd, qtd_list);
fusbh200_dbg(fusbh200,
"%s %s urb %p ep%d%s len %d, qtd %p [qh %p]\n",
__func__, urb->dev->devpath, urb,
epnum & 0x0f, (epnum & USB_DIR_IN) ? "in" : "out",
urb->transfer_buffer_length,
qtd, urb->ep->hcpriv);
}
#endif
spin_lock_irqsave (&fusbh200->lock, flags);
if (unlikely(!HCD_HW_ACCESSIBLE(fusbh200_to_hcd(fusbh200)))) {
rc = -ESHUTDOWN;
goto done;
}
rc = usb_hcd_link_urb_to_ep(fusbh200_to_hcd(fusbh200), urb);
if (unlikely(rc))
goto done;
qh = qh_append_tds(fusbh200, urb, qtd_list, epnum, &urb->ep->hcpriv);
if (unlikely(qh == NULL)) {
usb_hcd_unlink_urb_from_ep(fusbh200_to_hcd(fusbh200), urb);
rc = -ENOMEM;
goto done;
}
if (likely (qh->qh_state == QH_STATE_IDLE))
qh_link_async(fusbh200, qh);
done:
spin_unlock_irqrestore (&fusbh200->lock, flags);
if (unlikely (qh == NULL))
qtd_list_free (fusbh200, urb, qtd_list);
return rc;
}
static void single_unlink_async(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
struct fusbh200_qh *prev;
qh->qh_state = QH_STATE_UNLINK;
if (fusbh200->async_unlink)
fusbh200->async_unlink_last->unlink_next = qh;
else
fusbh200->async_unlink = qh;
fusbh200->async_unlink_last = qh;
prev = fusbh200->async;
while (prev->qh_next.qh != qh)
prev = prev->qh_next.qh;
prev->hw->hw_next = qh->hw->hw_next;
prev->qh_next = qh->qh_next;
if (fusbh200->qh_scan_next == qh)
fusbh200->qh_scan_next = qh->qh_next.qh;
}
static void start_iaa_cycle(struct fusbh200_hcd *fusbh200, bool nested)
{
if (fusbh200->async_iaa || fusbh200->async_unlinking)
return;
fusbh200->async_iaa = fusbh200->async_unlink;
fusbh200->async_unlink = NULL;
if (unlikely(fusbh200->rh_state < FUSBH200_RH_RUNNING)) {
if (!nested)
end_unlink_async(fusbh200);
} else if (likely(fusbh200->rh_state == FUSBH200_RH_RUNNING)) {
wmb();
fusbh200_writel(fusbh200, fusbh200->command | CMD_IAAD,
&fusbh200->regs->command);
fusbh200_readl(fusbh200, &fusbh200->regs->command);
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_IAA_WATCHDOG, true);
}
}
static void end_unlink_async(struct fusbh200_hcd *fusbh200)
{
struct fusbh200_qh *qh;
restart:
fusbh200->async_unlinking = true;
while (fusbh200->async_iaa) {
qh = fusbh200->async_iaa;
fusbh200->async_iaa = qh->unlink_next;
qh->unlink_next = NULL;
qh->qh_state = QH_STATE_IDLE;
qh->qh_next.qh = NULL;
qh_completions(fusbh200, qh);
if (!list_empty(&qh->qtd_list) &&
fusbh200->rh_state == FUSBH200_RH_RUNNING)
qh_link_async(fusbh200, qh);
disable_async(fusbh200);
}
fusbh200->async_unlinking = false;
if (fusbh200->async_unlink) {
start_iaa_cycle(fusbh200, true);
if (unlikely(fusbh200->rh_state < FUSBH200_RH_RUNNING))
goto restart;
}
}
static void unlink_empty_async(struct fusbh200_hcd *fusbh200)
{
struct fusbh200_qh *qh, *next;
bool stopped = (fusbh200->rh_state < FUSBH200_RH_RUNNING);
bool check_unlinks_later = false;
next = fusbh200->async->qh_next.qh;
while (next) {
qh = next;
next = qh->qh_next.qh;
if (list_empty(&qh->qtd_list) &&
qh->qh_state == QH_STATE_LINKED) {
if (!stopped && qh->unlink_cycle ==
fusbh200->async_unlink_cycle)
check_unlinks_later = true;
else
single_unlink_async(fusbh200, qh);
}
}
if (fusbh200->async_unlink)
start_iaa_cycle(fusbh200, false);
if (check_unlinks_later) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_ASYNC_UNLINKS, true);
++fusbh200->async_unlink_cycle;
}
}
static void start_unlink_async(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
if (qh->qh_state != QH_STATE_LINKED) {
if (qh->qh_state == QH_STATE_COMPLETING)
qh->needs_rescan = 1;
return;
}
single_unlink_async(fusbh200, qh);
start_iaa_cycle(fusbh200, false);
}
static void scan_async (struct fusbh200_hcd *fusbh200)
{
struct fusbh200_qh *qh;
bool check_unlinks_later = false;
fusbh200->qh_scan_next = fusbh200->async->qh_next.qh;
while (fusbh200->qh_scan_next) {
qh = fusbh200->qh_scan_next;
fusbh200->qh_scan_next = qh->qh_next.qh;
rescan:
if (!list_empty(&qh->qtd_list)) {
int temp;
temp = qh_completions(fusbh200, qh);
if (qh->needs_rescan) {
start_unlink_async(fusbh200, qh);
} else if (list_empty(&qh->qtd_list)
&& qh->qh_state == QH_STATE_LINKED) {
qh->unlink_cycle = fusbh200->async_unlink_cycle;
check_unlinks_later = true;
} else if (temp != 0)
goto rescan;
}
}
if (check_unlinks_later && fusbh200->rh_state == FUSBH200_RH_RUNNING &&
!(fusbh200->enabled_hrtimer_events &
BIT(FUSBH200_HRTIMER_ASYNC_UNLINKS))) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_ASYNC_UNLINKS, true);
++fusbh200->async_unlink_cycle;
}
}
static union fusbh200_shadow *
periodic_next_shadow(struct fusbh200_hcd *fusbh200, union fusbh200_shadow *periodic,
__hc32 tag)
{
switch (hc32_to_cpu(fusbh200, tag)) {
case Q_TYPE_QH:
return &periodic->qh->qh_next;
case Q_TYPE_FSTN:
return &periodic->fstn->fstn_next;
default:
return &periodic->itd->itd_next;
}
}
static __hc32 *
shadow_next_periodic(struct fusbh200_hcd *fusbh200, union fusbh200_shadow *periodic,
__hc32 tag)
{
switch (hc32_to_cpu(fusbh200, tag)) {
case Q_TYPE_QH:
return &periodic->qh->hw->hw_next;
default:
return periodic->hw_next;
}
}
static void periodic_unlink (struct fusbh200_hcd *fusbh200, unsigned frame, void *ptr)
{
union fusbh200_shadow *prev_p = &fusbh200->pshadow[frame];
__hc32 *hw_p = &fusbh200->periodic[frame];
union fusbh200_shadow here = *prev_p;
while (here.ptr && here.ptr != ptr) {
prev_p = periodic_next_shadow(fusbh200, prev_p,
Q_NEXT_TYPE(fusbh200, *hw_p));
hw_p = shadow_next_periodic(fusbh200, &here,
Q_NEXT_TYPE(fusbh200, *hw_p));
here = *prev_p;
}
if (!here.ptr)
return;
*prev_p = *periodic_next_shadow(fusbh200, &here,
Q_NEXT_TYPE(fusbh200, *hw_p));
*hw_p = *shadow_next_periodic(fusbh200, &here,
Q_NEXT_TYPE(fusbh200, *hw_p));
}
static unsigned short
periodic_usecs (struct fusbh200_hcd *fusbh200, unsigned frame, unsigned uframe)
{
__hc32 *hw_p = &fusbh200->periodic [frame];
union fusbh200_shadow *q = &fusbh200->pshadow [frame];
unsigned usecs = 0;
struct fusbh200_qh_hw *hw;
while (q->ptr) {
switch (hc32_to_cpu(fusbh200, Q_NEXT_TYPE(fusbh200, *hw_p))) {
case Q_TYPE_QH:
hw = q->qh->hw;
if (hw->hw_info2 & cpu_to_hc32(fusbh200, 1 << uframe))
usecs += q->qh->usecs;
if (hw->hw_info2 & cpu_to_hc32(fusbh200,
1 << (8 + uframe)))
usecs += q->qh->c_usecs;
hw_p = &hw->hw_next;
q = &q->qh->qh_next;
break;
default:
if (q->fstn->hw_prev != FUSBH200_LIST_END(fusbh200)) {
fusbh200_dbg (fusbh200, "ignoring FSTN cost ...\n");
}
hw_p = &q->fstn->hw_next;
q = &q->fstn->fstn_next;
break;
case Q_TYPE_ITD:
if (q->itd->hw_transaction[uframe])
usecs += q->itd->stream->usecs;
hw_p = &q->itd->hw_next;
q = &q->itd->itd_next;
break;
}
}
if (usecs > fusbh200->uframe_periodic_max)
fusbh200_err (fusbh200, "uframe %d sched overrun: %d usecs\n",
frame * 8 + uframe, usecs);
return usecs;
}
static int same_tt (struct usb_device *dev1, struct usb_device *dev2)
{
if (!dev1->tt || !dev2->tt)
return 0;
if (dev1->tt != dev2->tt)
return 0;
if (dev1->tt->multi)
return dev1->ttport == dev2->ttport;
else
return 1;
}
static int tt_no_collision (
struct fusbh200_hcd *fusbh200,
unsigned period,
struct usb_device *dev,
unsigned frame,
u32 uf_mask
)
{
if (period == 0)
return 0;
for (; frame < fusbh200->periodic_size; frame += period) {
union fusbh200_shadow here;
__hc32 type;
struct fusbh200_qh_hw *hw;
here = fusbh200->pshadow [frame];
type = Q_NEXT_TYPE(fusbh200, fusbh200->periodic [frame]);
while (here.ptr) {
switch (hc32_to_cpu(fusbh200, type)) {
case Q_TYPE_ITD:
type = Q_NEXT_TYPE(fusbh200, here.itd->hw_next);
here = here.itd->itd_next;
continue;
case Q_TYPE_QH:
hw = here.qh->hw;
if (same_tt (dev, here.qh->dev)) {
u32 mask;
mask = hc32_to_cpu(fusbh200,
hw->hw_info2);
mask |= mask >> 8;
if (mask & uf_mask)
break;
}
type = Q_NEXT_TYPE(fusbh200, hw->hw_next);
here = here.qh->qh_next;
continue;
default:
fusbh200_dbg (fusbh200,
"periodic frame %d bogus type %d\n",
frame, type);
}
return 0;
}
}
return 1;
}
static void enable_periodic(struct fusbh200_hcd *fusbh200)
{
if (fusbh200->periodic_count++)
return;
fusbh200->enabled_hrtimer_events &= ~BIT(FUSBH200_HRTIMER_DISABLE_PERIODIC);
fusbh200_poll_PSS(fusbh200);
turn_on_io_watchdog(fusbh200);
}
static void disable_periodic(struct fusbh200_hcd *fusbh200)
{
if (--fusbh200->periodic_count)
return;
fusbh200_poll_PSS(fusbh200);
}
static void qh_link_periodic(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
unsigned i;
unsigned period = qh->period;
dev_dbg (&qh->dev->dev,
"link qh%d-%04x/%p start %d [%d/%d us]\n",
period, hc32_to_cpup(fusbh200, &qh->hw->hw_info2)
& (QH_CMASK | QH_SMASK),
qh, qh->start, qh->usecs, qh->c_usecs);
if (period == 0)
period = 1;
for (i = qh->start; i < fusbh200->periodic_size; i += period) {
union fusbh200_shadow *prev = &fusbh200->pshadow[i];
__hc32 *hw_p = &fusbh200->periodic[i];
union fusbh200_shadow here = *prev;
__hc32 type = 0;
while (here.ptr) {
type = Q_NEXT_TYPE(fusbh200, *hw_p);
if (type == cpu_to_hc32(fusbh200, Q_TYPE_QH))
break;
prev = periodic_next_shadow(fusbh200, prev, type);
hw_p = shadow_next_periodic(fusbh200, &here, type);
here = *prev;
}
while (here.ptr && qh != here.qh) {
if (qh->period > here.qh->period)
break;
prev = &here.qh->qh_next;
hw_p = &here.qh->hw->hw_next;
here = *prev;
}
if (qh != here.qh) {
qh->qh_next = here;
if (here.qh)
qh->hw->hw_next = *hw_p;
wmb ();
prev->qh = qh;
*hw_p = QH_NEXT (fusbh200, qh->qh_dma);
}
}
qh->qh_state = QH_STATE_LINKED;
qh->xacterrs = 0;
fusbh200_to_hcd(fusbh200)->self.bandwidth_allocated += qh->period
? ((qh->usecs + qh->c_usecs) / qh->period)
: (qh->usecs * 8);
list_add(&qh->intr_node, &fusbh200->intr_qh_list);
++fusbh200->intr_count;
enable_periodic(fusbh200);
}
static void qh_unlink_periodic(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
unsigned i;
unsigned period;
if ((period = qh->period) == 0)
period = 1;
for (i = qh->start; i < fusbh200->periodic_size; i += period)
periodic_unlink (fusbh200, i, qh);
fusbh200_to_hcd(fusbh200)->self.bandwidth_allocated -= qh->period
? ((qh->usecs + qh->c_usecs) / qh->period)
: (qh->usecs * 8);
dev_dbg (&qh->dev->dev,
"unlink qh%d-%04x/%p start %d [%d/%d us]\n",
qh->period,
hc32_to_cpup(fusbh200, &qh->hw->hw_info2) & (QH_CMASK | QH_SMASK),
qh, qh->start, qh->usecs, qh->c_usecs);
qh->qh_state = QH_STATE_UNLINK;
qh->qh_next.ptr = NULL;
if (fusbh200->qh_scan_next == qh)
fusbh200->qh_scan_next = list_entry(qh->intr_node.next,
struct fusbh200_qh, intr_node);
list_del(&qh->intr_node);
}
static void start_unlink_intr(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
if (qh->qh_state != QH_STATE_LINKED) {
if (qh->qh_state == QH_STATE_COMPLETING)
qh->needs_rescan = 1;
return;
}
qh_unlink_periodic (fusbh200, qh);
wmb();
qh->unlink_cycle = fusbh200->intr_unlink_cycle;
if (fusbh200->intr_unlink)
fusbh200->intr_unlink_last->unlink_next = qh;
else
fusbh200->intr_unlink = qh;
fusbh200->intr_unlink_last = qh;
if (fusbh200->intr_unlinking)
;
else if (fusbh200->rh_state < FUSBH200_RH_RUNNING)
fusbh200_handle_intr_unlinks(fusbh200);
else if (fusbh200->intr_unlink == qh) {
fusbh200_enable_event(fusbh200, FUSBH200_HRTIMER_UNLINK_INTR, true);
++fusbh200->intr_unlink_cycle;
}
}
static void end_unlink_intr(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
struct fusbh200_qh_hw *hw = qh->hw;
int rc;
qh->qh_state = QH_STATE_IDLE;
hw->hw_next = FUSBH200_LIST_END(fusbh200);
qh_completions(fusbh200, qh);
if (!list_empty(&qh->qtd_list) && fusbh200->rh_state == FUSBH200_RH_RUNNING) {
rc = qh_schedule(fusbh200, qh);
if (rc != 0)
fusbh200_err(fusbh200, "can't reschedule qh %p, err %d\n",
qh, rc);
}
--fusbh200->intr_count;
disable_periodic(fusbh200);
}
static int check_period (
struct fusbh200_hcd *fusbh200,
unsigned frame,
unsigned uframe,
unsigned period,
unsigned usecs
) {
int claimed;
if (uframe >= 8)
return 0;
usecs = fusbh200->uframe_periodic_max - usecs;
if (unlikely (period == 0)) {
do {
for (uframe = 0; uframe < 7; uframe++) {
claimed = periodic_usecs (fusbh200, frame, uframe);
if (claimed > usecs)
return 0;
}
} while ((frame += 1) < fusbh200->periodic_size);
} else {
do {
claimed = periodic_usecs (fusbh200, frame, uframe);
if (claimed > usecs)
return 0;
} while ((frame += period) < fusbh200->periodic_size);
}
return 1;
}
static int check_intr_schedule (
struct fusbh200_hcd *fusbh200,
unsigned frame,
unsigned uframe,
const struct fusbh200_qh *qh,
__hc32 *c_maskp
)
{
int retval = -ENOSPC;
u8 mask = 0;
if (qh->c_usecs && uframe >= 6)
goto done;
if (!check_period (fusbh200, frame, uframe, qh->period, qh->usecs))
goto done;
if (!qh->c_usecs) {
retval = 0;
*c_maskp = 0;
goto done;
}
mask = 0x03 << (uframe + qh->gap_uf);
*c_maskp = cpu_to_hc32(fusbh200, mask << 8);
mask |= 1 << uframe;
if (tt_no_collision (fusbh200, qh->period, qh->dev, frame, mask)) {
if (!check_period (fusbh200, frame, uframe + qh->gap_uf + 1,
qh->period, qh->c_usecs))
goto done;
if (!check_period (fusbh200, frame, uframe + qh->gap_uf,
qh->period, qh->c_usecs))
goto done;
retval = 0;
}
done:
return retval;
}
static int qh_schedule(struct fusbh200_hcd *fusbh200, struct fusbh200_qh *qh)
{
int status;
unsigned uframe;
__hc32 c_mask;
unsigned frame;
struct fusbh200_qh_hw *hw = qh->hw;
qh_refresh(fusbh200, qh);
hw->hw_next = FUSBH200_LIST_END(fusbh200);
frame = qh->start;
if (frame < qh->period) {
uframe = ffs(hc32_to_cpup(fusbh200, &hw->hw_info2) & QH_SMASK);
status = check_intr_schedule (fusbh200, frame, --uframe,
qh, &c_mask);
} else {
uframe = 0;
c_mask = 0;
status = -ENOSPC;
}
if (status) {
if (qh->period) {
int i;
for (i = qh->period; status && i > 0; --i) {
frame = ++fusbh200->random_frame % qh->period;
for (uframe = 0; uframe < 8; uframe++) {
status = check_intr_schedule (fusbh200,
frame, uframe, qh,
&c_mask);
if (status == 0)
break;
}
}
} else {
frame = 0;
status = check_intr_schedule (fusbh200, 0, 0, qh, &c_mask);
}
if (status)
goto done;
qh->start = frame;
hw->hw_info2 &= cpu_to_hc32(fusbh200, ~(QH_CMASK | QH_SMASK));
hw->hw_info2 |= qh->period
? cpu_to_hc32(fusbh200, 1 << uframe)
: cpu_to_hc32(fusbh200, QH_SMASK);
hw->hw_info2 |= c_mask;
} else
fusbh200_dbg (fusbh200, "reused qh %p schedule\n", qh);
qh_link_periodic(fusbh200, qh);
done:
return status;
}
static int intr_submit (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
struct list_head *qtd_list,
gfp_t mem_flags
) {
unsigned epnum;
unsigned long flags;
struct fusbh200_qh *qh;
int status;
struct list_head empty;
epnum = urb->ep->desc.bEndpointAddress;
spin_lock_irqsave (&fusbh200->lock, flags);
if (unlikely(!HCD_HW_ACCESSIBLE(fusbh200_to_hcd(fusbh200)))) {
status = -ESHUTDOWN;
goto done_not_linked;
}
status = usb_hcd_link_urb_to_ep(fusbh200_to_hcd(fusbh200), urb);
if (unlikely(status))
goto done_not_linked;
INIT_LIST_HEAD (&empty);
qh = qh_append_tds(fusbh200, urb, &empty, epnum, &urb->ep->hcpriv);
if (qh == NULL) {
status = -ENOMEM;
goto done;
}
if (qh->qh_state == QH_STATE_IDLE) {
if ((status = qh_schedule (fusbh200, qh)) != 0)
goto done;
}
qh = qh_append_tds(fusbh200, urb, qtd_list, epnum, &urb->ep->hcpriv);
BUG_ON (qh == NULL);
fusbh200_to_hcd(fusbh200)->self.bandwidth_int_reqs++;
done:
if (unlikely(status))
usb_hcd_unlink_urb_from_ep(fusbh200_to_hcd(fusbh200), urb);
done_not_linked:
spin_unlock_irqrestore (&fusbh200->lock, flags);
if (status)
qtd_list_free (fusbh200, urb, qtd_list);
return status;
}
static void scan_intr(struct fusbh200_hcd *fusbh200)
{
struct fusbh200_qh *qh;
list_for_each_entry_safe(qh, fusbh200->qh_scan_next, &fusbh200->intr_qh_list,
intr_node) {
rescan:
if (!list_empty(&qh->qtd_list)) {
int temp;
temp = qh_completions(fusbh200, qh);
if (unlikely(qh->needs_rescan ||
(list_empty(&qh->qtd_list) &&
qh->qh_state == QH_STATE_LINKED)))
start_unlink_intr(fusbh200, qh);
else if (temp != 0)
goto rescan;
}
}
}
static struct fusbh200_iso_stream *
iso_stream_alloc (gfp_t mem_flags)
{
struct fusbh200_iso_stream *stream;
stream = kzalloc(sizeof *stream, mem_flags);
if (likely (stream != NULL)) {
INIT_LIST_HEAD(&stream->td_list);
INIT_LIST_HEAD(&stream->free_list);
stream->next_uframe = -1;
}
return stream;
}
static void
iso_stream_init (
struct fusbh200_hcd *fusbh200,
struct fusbh200_iso_stream *stream,
struct usb_device *dev,
int pipe,
unsigned interval
)
{
u32 buf1;
unsigned epnum, maxp;
int is_input;
long bandwidth;
unsigned multi;
epnum = usb_pipeendpoint (pipe);
is_input = usb_pipein (pipe) ? USB_DIR_IN : 0;
maxp = usb_maxpacket(dev, pipe, !is_input);
if (is_input) {
buf1 = (1 << 11);
} else {
buf1 = 0;
}
maxp = max_packet(maxp);
multi = hb_mult(maxp);
buf1 |= maxp;
maxp *= multi;
stream->buf0 = cpu_to_hc32(fusbh200, (epnum << 8) | dev->devnum);
stream->buf1 = cpu_to_hc32(fusbh200, buf1);
stream->buf2 = cpu_to_hc32(fusbh200, multi);
if (dev->speed == USB_SPEED_FULL) {
interval <<= 3;
stream->usecs = NS_TO_US(usb_calc_bus_time(dev->speed,
is_input, 1, maxp));
stream->usecs /= 8;
} else {
stream->highspeed = 1;
stream->usecs = HS_USECS_ISO (maxp);
}
bandwidth = stream->usecs * 8;
bandwidth /= interval;
stream->bandwidth = bandwidth;
stream->udev = dev;
stream->bEndpointAddress = is_input | epnum;
stream->interval = interval;
stream->maxp = maxp;
}
static struct fusbh200_iso_stream *
iso_stream_find (struct fusbh200_hcd *fusbh200, struct urb *urb)
{
unsigned epnum;
struct fusbh200_iso_stream *stream;
struct usb_host_endpoint *ep;
unsigned long flags;
epnum = usb_pipeendpoint (urb->pipe);
if (usb_pipein(urb->pipe))
ep = urb->dev->ep_in[epnum];
else
ep = urb->dev->ep_out[epnum];
spin_lock_irqsave (&fusbh200->lock, flags);
stream = ep->hcpriv;
if (unlikely (stream == NULL)) {
stream = iso_stream_alloc(GFP_ATOMIC);
if (likely (stream != NULL)) {
ep->hcpriv = stream;
stream->ep = ep;
iso_stream_init(fusbh200, stream, urb->dev, urb->pipe,
urb->interval);
}
} else if (unlikely (stream->hw != NULL)) {
fusbh200_dbg (fusbh200, "dev %s ep%d%s, not iso??\n",
urb->dev->devpath, epnum,
usb_pipein(urb->pipe) ? "in" : "out");
stream = NULL;
}
spin_unlock_irqrestore (&fusbh200->lock, flags);
return stream;
}
static struct fusbh200_iso_sched *
iso_sched_alloc (unsigned packets, gfp_t mem_flags)
{
struct fusbh200_iso_sched *iso_sched;
int size = sizeof *iso_sched;
size += packets * sizeof (struct fusbh200_iso_packet);
iso_sched = kzalloc(size, mem_flags);
if (likely (iso_sched != NULL)) {
INIT_LIST_HEAD (&iso_sched->td_list);
}
return iso_sched;
}
static inline void
itd_sched_init(
struct fusbh200_hcd *fusbh200,
struct fusbh200_iso_sched *iso_sched,
struct fusbh200_iso_stream *stream,
struct urb *urb
)
{
unsigned i;
dma_addr_t dma = urb->transfer_dma;
iso_sched->span = urb->number_of_packets * stream->interval;
for (i = 0; i < urb->number_of_packets; i++) {
struct fusbh200_iso_packet *uframe = &iso_sched->packet [i];
unsigned length;
dma_addr_t buf;
u32 trans;
length = urb->iso_frame_desc [i].length;
buf = dma + urb->iso_frame_desc [i].offset;
trans = FUSBH200_ISOC_ACTIVE;
trans |= buf & 0x0fff;
if (unlikely (((i + 1) == urb->number_of_packets))
&& !(urb->transfer_flags & URB_NO_INTERRUPT))
trans |= FUSBH200_ITD_IOC;
trans |= length << 16;
uframe->transaction = cpu_to_hc32(fusbh200, trans);
uframe->bufp = (buf & ~(u64)0x0fff);
buf += length;
if (unlikely ((uframe->bufp != (buf & ~(u64)0x0fff))))
uframe->cross = 1;
}
}
static void
iso_sched_free (
struct fusbh200_iso_stream *stream,
struct fusbh200_iso_sched *iso_sched
)
{
if (!iso_sched)
return;
list_splice (&iso_sched->td_list, &stream->free_list);
kfree (iso_sched);
}
static int
itd_urb_transaction (
struct fusbh200_iso_stream *stream,
struct fusbh200_hcd *fusbh200,
struct urb *urb,
gfp_t mem_flags
)
{
struct fusbh200_itd *itd;
dma_addr_t itd_dma;
int i;
unsigned num_itds;
struct fusbh200_iso_sched *sched;
unsigned long flags;
sched = iso_sched_alloc (urb->number_of_packets, mem_flags);
if (unlikely (sched == NULL))
return -ENOMEM;
itd_sched_init(fusbh200, sched, stream, urb);
if (urb->interval < 8)
num_itds = 1 + (sched->span + 7) / 8;
else
num_itds = urb->number_of_packets;
spin_lock_irqsave (&fusbh200->lock, flags);
for (i = 0; i < num_itds; i++) {
if (likely(!list_empty(&stream->free_list))) {
itd = list_first_entry(&stream->free_list,
struct fusbh200_itd, itd_list);
if (itd->frame == fusbh200->now_frame)
goto alloc_itd;
list_del (&itd->itd_list);
itd_dma = itd->itd_dma;
} else {
alloc_itd:
spin_unlock_irqrestore (&fusbh200->lock, flags);
itd = dma_pool_alloc (fusbh200->itd_pool, mem_flags,
&itd_dma);
spin_lock_irqsave (&fusbh200->lock, flags);
if (!itd) {
iso_sched_free(stream, sched);
spin_unlock_irqrestore(&fusbh200->lock, flags);
return -ENOMEM;
}
}
memset (itd, 0, sizeof *itd);
itd->itd_dma = itd_dma;
list_add (&itd->itd_list, &sched->td_list);
}
spin_unlock_irqrestore (&fusbh200->lock, flags);
urb->hcpriv = sched;
urb->error_count = 0;
return 0;
}
static inline int
itd_slot_ok (
struct fusbh200_hcd *fusbh200,
u32 mod,
u32 uframe,
u8 usecs,
u32 period
)
{
uframe %= period;
do {
if (periodic_usecs (fusbh200, uframe >> 3, uframe & 0x7)
> (fusbh200->uframe_periodic_max - usecs))
return 0;
uframe += period;
} while (uframe < mod);
return 1;
}
static int
iso_stream_schedule (
struct fusbh200_hcd *fusbh200,
struct urb *urb,
struct fusbh200_iso_stream *stream
)
{
u32 now, next, start, period, span;
int status;
unsigned mod = fusbh200->periodic_size << 3;
struct fusbh200_iso_sched *sched = urb->hcpriv;
period = urb->interval;
span = sched->span;
if (span > mod - SCHEDULE_SLOP) {
fusbh200_dbg (fusbh200, "iso request %p too long\n", urb);
status = -EFBIG;
goto fail;
}
now = fusbh200_read_frame_index(fusbh200) & (mod - 1);
if (likely (!list_empty (&stream->td_list))) {
u32 excess;
if (!stream->highspeed && fusbh200->fs_i_thresh)
next = now + fusbh200->i_thresh;
else
next = now;
excess = (stream->next_uframe - period - next) & (mod - 1);
if (excess >= mod - 2 * SCHEDULE_SLOP)
start = next + excess - mod + period *
DIV_ROUND_UP(mod - excess, period);
else
start = next + excess + period;
if (start - now >= mod) {
fusbh200_dbg(fusbh200, "request %p would overflow (%d+%d >= %d)\n",
urb, start - now - period, period,
mod);
status = -EFBIG;
goto fail;
}
}
else {
int done = 0;
start = SCHEDULE_SLOP + (now & ~0x07);
next = start;
start += period;
do {
start--;
if (itd_slot_ok(fusbh200, mod, start,
stream->usecs, period))
done = 1;
} while (start > next && !done);
if (!done) {
fusbh200_dbg(fusbh200, "iso resched full %p (now %d max %d)\n",
urb, now, now + mod);
status = -ENOSPC;
goto fail;
}
}
if (unlikely(start - now + span - period
>= mod - 2 * SCHEDULE_SLOP)) {
fusbh200_dbg(fusbh200, "request %p would overflow (%d+%d >= %d)\n",
urb, start - now, span - period,
mod - 2 * SCHEDULE_SLOP);
status = -EFBIG;
goto fail;
}
stream->next_uframe = start & (mod - 1);
urb->start_frame = stream->next_uframe;
if (!stream->highspeed)
urb->start_frame >>= 3;
if (fusbh200->isoc_count == 0)
fusbh200->next_frame = now >> 3;
return 0;
fail:
iso_sched_free(stream, sched);
urb->hcpriv = NULL;
return status;
}
static inline void
itd_init(struct fusbh200_hcd *fusbh200, struct fusbh200_iso_stream *stream,
struct fusbh200_itd *itd)
{
int i;
itd->hw_next = FUSBH200_LIST_END(fusbh200);
itd->hw_bufp [0] = stream->buf0;
itd->hw_bufp [1] = stream->buf1;
itd->hw_bufp [2] = stream->buf2;
for (i = 0; i < 8; i++)
itd->index[i] = -1;
}
static inline void
itd_patch(
struct fusbh200_hcd *fusbh200,
struct fusbh200_itd *itd,
struct fusbh200_iso_sched *iso_sched,
unsigned index,
u16 uframe
)
{
struct fusbh200_iso_packet *uf = &iso_sched->packet [index];
unsigned pg = itd->pg;
uframe &= 0x07;
itd->index [uframe] = index;
itd->hw_transaction[uframe] = uf->transaction;
itd->hw_transaction[uframe] |= cpu_to_hc32(fusbh200, pg << 12);
itd->hw_bufp[pg] |= cpu_to_hc32(fusbh200, uf->bufp & ~(u32)0);
itd->hw_bufp_hi[pg] |= cpu_to_hc32(fusbh200, (u32)(uf->bufp >> 32));
if (unlikely (uf->cross)) {
u64 bufp = uf->bufp + 4096;
itd->pg = ++pg;
itd->hw_bufp[pg] |= cpu_to_hc32(fusbh200, bufp & ~(u32)0);
itd->hw_bufp_hi[pg] |= cpu_to_hc32(fusbh200, (u32)(bufp >> 32));
}
}
static inline void
itd_link (struct fusbh200_hcd *fusbh200, unsigned frame, struct fusbh200_itd *itd)
{
union fusbh200_shadow *prev = &fusbh200->pshadow[frame];
__hc32 *hw_p = &fusbh200->periodic[frame];
union fusbh200_shadow here = *prev;
__hc32 type = 0;
while (here.ptr) {
type = Q_NEXT_TYPE(fusbh200, *hw_p);
if (type == cpu_to_hc32(fusbh200, Q_TYPE_QH))
break;
prev = periodic_next_shadow(fusbh200, prev, type);
hw_p = shadow_next_periodic(fusbh200, &here, type);
here = *prev;
}
itd->itd_next = here;
itd->hw_next = *hw_p;
prev->itd = itd;
itd->frame = frame;
wmb ();
*hw_p = cpu_to_hc32(fusbh200, itd->itd_dma | Q_TYPE_ITD);
}
static void itd_link_urb(
struct fusbh200_hcd *fusbh200,
struct urb *urb,
unsigned mod,
struct fusbh200_iso_stream *stream
)
{
int packet;
unsigned next_uframe, uframe, frame;
struct fusbh200_iso_sched *iso_sched = urb->hcpriv;
struct fusbh200_itd *itd;
next_uframe = stream->next_uframe & (mod - 1);
if (unlikely (list_empty(&stream->td_list))) {
fusbh200_to_hcd(fusbh200)->self.bandwidth_allocated
+= stream->bandwidth;
fusbh200_dbg(fusbh200,
"schedule devp %s ep%d%s-iso period %d start %d.%d\n",
urb->dev->devpath, stream->bEndpointAddress & 0x0f,
(stream->bEndpointAddress & USB_DIR_IN) ? "in" : "out",
urb->interval,
next_uframe >> 3, next_uframe & 0x7);
}
for (packet = 0, itd = NULL; packet < urb->number_of_packets; ) {
if (itd == NULL) {
itd = list_entry (iso_sched->td_list.next,
struct fusbh200_itd, itd_list);
list_move_tail (&itd->itd_list, &stream->td_list);
itd->stream = stream;
itd->urb = urb;
itd_init (fusbh200, stream, itd);
}
uframe = next_uframe & 0x07;
frame = next_uframe >> 3;
itd_patch(fusbh200, itd, iso_sched, packet, uframe);
next_uframe += stream->interval;
next_uframe &= mod - 1;
packet++;
if (((next_uframe >> 3) != frame)
|| packet == urb->number_of_packets) {
itd_link(fusbh200, frame & (fusbh200->periodic_size - 1), itd);
itd = NULL;
}
}
stream->next_uframe = next_uframe;
iso_sched_free (stream, iso_sched);
urb->hcpriv = NULL;
++fusbh200->isoc_count;
enable_periodic(fusbh200);
}
static bool itd_complete(struct fusbh200_hcd *fusbh200, struct fusbh200_itd *itd)
{
struct urb *urb = itd->urb;
struct usb_iso_packet_descriptor *desc;
u32 t;
unsigned uframe;
int urb_index = -1;
struct fusbh200_iso_stream *stream = itd->stream;
struct usb_device *dev;
bool retval = false;
for (uframe = 0; uframe < 8; uframe++) {
if (likely (itd->index[uframe] == -1))
continue;
urb_index = itd->index[uframe];
desc = &urb->iso_frame_desc [urb_index];
t = hc32_to_cpup(fusbh200, &itd->hw_transaction [uframe]);
itd->hw_transaction [uframe] = 0;
if (unlikely (t & ISO_ERRS)) {
urb->error_count++;
if (t & FUSBH200_ISOC_BUF_ERR)
desc->status = usb_pipein (urb->pipe)
? -ENOSR
: -ECOMM;
else if (t & FUSBH200_ISOC_BABBLE)
desc->status = -EOVERFLOW;
else
desc->status = -EPROTO;
if (!(t & FUSBH200_ISOC_BABBLE)) {
desc->actual_length = fusbh200_itdlen(urb, desc, t);
urb->actual_length += desc->actual_length;
}
} else if (likely ((t & FUSBH200_ISOC_ACTIVE) == 0)) {
desc->status = 0;
desc->actual_length = fusbh200_itdlen(urb, desc, t);
urb->actual_length += desc->actual_length;
} else {
desc->status = -EXDEV;
}
}
if (likely ((urb_index + 1) != urb->number_of_packets))
goto done;
dev = urb->dev;
fusbh200_urb_done(fusbh200, urb, 0);
retval = true;
urb = NULL;
--fusbh200->isoc_count;
disable_periodic(fusbh200);
if (unlikely(list_is_singular(&stream->td_list))) {
fusbh200_to_hcd(fusbh200)->self.bandwidth_allocated
-= stream->bandwidth;
fusbh200_dbg(fusbh200,
"deschedule devp %s ep%d%s-iso\n",
dev->devpath, stream->bEndpointAddress & 0x0f,
(stream->bEndpointAddress & USB_DIR_IN) ? "in" : "out");
}
done:
itd->urb = NULL;
list_move_tail(&itd->itd_list, &stream->free_list);
if (list_empty(&stream->td_list)) {
list_splice_tail_init(&stream->free_list,
&fusbh200->cached_itd_list);
start_free_itds(fusbh200);
}
return retval;
}
static int itd_submit (struct fusbh200_hcd *fusbh200, struct urb *urb,
gfp_t mem_flags)
{
int status = -EINVAL;
unsigned long flags;
struct fusbh200_iso_stream *stream;
stream = iso_stream_find (fusbh200, urb);
if (unlikely (stream == NULL)) {
fusbh200_dbg (fusbh200, "can't get iso stream\n");
return -ENOMEM;
}
if (unlikely (urb->interval != stream->interval &&
fusbh200_port_speed(fusbh200, 0) == USB_PORT_STAT_HIGH_SPEED)) {
fusbh200_dbg (fusbh200, "can't change iso interval %d --> %d\n",
stream->interval, urb->interval);
goto done;
}
#ifdef FUSBH200_URB_TRACE
fusbh200_dbg (fusbh200,
"%s %s urb %p ep%d%s len %d, %d pkts %d uframes [%p]\n",
__func__, urb->dev->devpath, urb,
usb_pipeendpoint (urb->pipe),
usb_pipein (urb->pipe) ? "in" : "out",
urb->transfer_buffer_length,
urb->number_of_packets, urb->interval,
stream);
#endif
status = itd_urb_transaction (stream, fusbh200, urb, mem_flags);
if (unlikely (status < 0)) {
fusbh200_dbg (fusbh200, "can't init itds\n");
goto done;
}
spin_lock_irqsave (&fusbh200->lock, flags);
if (unlikely(!HCD_HW_ACCESSIBLE(fusbh200_to_hcd(fusbh200)))) {
status = -ESHUTDOWN;
goto done_not_linked;
}
status = usb_hcd_link_urb_to_ep(fusbh200_to_hcd(fusbh200), urb);
if (unlikely(status))
goto done_not_linked;
status = iso_stream_schedule(fusbh200, urb, stream);
if (likely (status == 0))
itd_link_urb (fusbh200, urb, fusbh200->periodic_size << 3, stream);
else
usb_hcd_unlink_urb_from_ep(fusbh200_to_hcd(fusbh200), urb);
done_not_linked:
spin_unlock_irqrestore (&fusbh200->lock, flags);
done:
return status;
}
static void scan_isoc(struct fusbh200_hcd *fusbh200)
{
unsigned uf, now_frame, frame;
unsigned fmask = fusbh200->periodic_size - 1;
bool modified, live;
if (fusbh200->rh_state >= FUSBH200_RH_RUNNING) {
uf = fusbh200_read_frame_index(fusbh200);
now_frame = (uf >> 3) & fmask;
live = true;
} else {
now_frame = (fusbh200->next_frame - 1) & fmask;
live = false;
}
fusbh200->now_frame = now_frame;
frame = fusbh200->next_frame;
for (;;) {
union fusbh200_shadow q, *q_p;
__hc32 type, *hw_p;
restart:
q_p = &fusbh200->pshadow [frame];
hw_p = &fusbh200->periodic [frame];
q.ptr = q_p->ptr;
type = Q_NEXT_TYPE(fusbh200, *hw_p);
modified = false;
while (q.ptr != NULL) {
switch (hc32_to_cpu(fusbh200, type)) {
case Q_TYPE_ITD:
if (frame == now_frame && live) {
rmb();
for (uf = 0; uf < 8; uf++) {
if (q.itd->hw_transaction[uf] &
ITD_ACTIVE(fusbh200))
break;
}
if (uf < 8) {
q_p = &q.itd->itd_next;
hw_p = &q.itd->hw_next;
type = Q_NEXT_TYPE(fusbh200,
q.itd->hw_next);
q = *q_p;
break;
}
}
*q_p = q.itd->itd_next;
*hw_p = q.itd->hw_next;
type = Q_NEXT_TYPE(fusbh200, q.itd->hw_next);
wmb();
modified = itd_complete (fusbh200, q.itd);
q = *q_p;
break;
default:
fusbh200_dbg(fusbh200, "corrupt type %d frame %d shadow %p\n",
type, frame, q.ptr);
case Q_TYPE_QH:
case Q_TYPE_FSTN:
q.ptr = NULL;
break;
}
if (unlikely(modified && fusbh200->isoc_count > 0))
goto restart;
}
if (frame == now_frame)
break;
frame = (frame + 1) & fmask;
}
fusbh200->next_frame = now_frame;
}
static ssize_t show_uframe_periodic_max(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fusbh200_hcd *fusbh200;
int n;
fusbh200 = hcd_to_fusbh200(bus_to_hcd(dev_get_drvdata(dev)));
n = scnprintf(buf, PAGE_SIZE, "%d\n", fusbh200->uframe_periodic_max);
return n;
}
static ssize_t store_uframe_periodic_max(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fusbh200_hcd *fusbh200;
unsigned uframe_periodic_max;
unsigned frame, uframe;
unsigned short allocated_max;
unsigned long flags;
ssize_t ret;
fusbh200 = hcd_to_fusbh200(bus_to_hcd(dev_get_drvdata(dev)));
if (kstrtouint(buf, 0, &uframe_periodic_max) < 0)
return -EINVAL;
if (uframe_periodic_max < 100 || uframe_periodic_max >= 125) {
fusbh200_info(fusbh200, "rejecting invalid request for "
"uframe_periodic_max=%u\n", uframe_periodic_max);
return -EINVAL;
}
ret = -EINVAL;
spin_lock_irqsave (&fusbh200->lock, flags);
if (uframe_periodic_max < fusbh200->uframe_periodic_max) {
allocated_max = 0;
for (frame = 0; frame < fusbh200->periodic_size; ++frame)
for (uframe = 0; uframe < 7; ++uframe)
allocated_max = max(allocated_max,
periodic_usecs (fusbh200, frame, uframe));
if (allocated_max > uframe_periodic_max) {
fusbh200_info(fusbh200,
"cannot decrease uframe_periodic_max because "
"periodic bandwidth is already allocated "
"(%u > %u)\n",
allocated_max, uframe_periodic_max);
goto out_unlock;
}
}
fusbh200_info(fusbh200, "setting max periodic bandwidth to %u%% "
"(== %u usec/uframe)\n",
100*uframe_periodic_max/125, uframe_periodic_max);
if (uframe_periodic_max != 100)
fusbh200_warn(fusbh200, "max periodic bandwidth set is non-standard\n");
fusbh200->uframe_periodic_max = uframe_periodic_max;
ret = count;
out_unlock:
spin_unlock_irqrestore (&fusbh200->lock, flags);
return ret;
}
static inline int create_sysfs_files(struct fusbh200_hcd *fusbh200)
{
struct device *controller = fusbh200_to_hcd(fusbh200)->self.controller;
int i = 0;
if (i)
goto out;
i = device_create_file(controller, &dev_attr_uframe_periodic_max);
out:
return i;
}
static inline void remove_sysfs_files(struct fusbh200_hcd *fusbh200)
{
struct device *controller = fusbh200_to_hcd(fusbh200)->self.controller;
device_remove_file(controller, &dev_attr_uframe_periodic_max);
}
static void fusbh200_turn_off_all_ports(struct fusbh200_hcd *fusbh200)
{
u32 __iomem *status_reg = &fusbh200->regs->port_status;
fusbh200_writel(fusbh200, PORT_RWC_BITS, status_reg);
}
static void fusbh200_silence_controller(struct fusbh200_hcd *fusbh200)
{
fusbh200_halt(fusbh200);
spin_lock_irq(&fusbh200->lock);
fusbh200->rh_state = FUSBH200_RH_HALTED;
fusbh200_turn_off_all_ports(fusbh200);
spin_unlock_irq(&fusbh200->lock);
}
static void fusbh200_shutdown(struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200(hcd);
spin_lock_irq(&fusbh200->lock);
fusbh200->shutdown = true;
fusbh200->rh_state = FUSBH200_RH_STOPPING;
fusbh200->enabled_hrtimer_events = 0;
spin_unlock_irq(&fusbh200->lock);
fusbh200_silence_controller(fusbh200);
hrtimer_cancel(&fusbh200->hrtimer);
}
static void fusbh200_work (struct fusbh200_hcd *fusbh200)
{
if (fusbh200->scanning) {
fusbh200->need_rescan = true;
return;
}
fusbh200->scanning = true;
rescan:
fusbh200->need_rescan = false;
if (fusbh200->async_count)
scan_async(fusbh200);
if (fusbh200->intr_count > 0)
scan_intr(fusbh200);
if (fusbh200->isoc_count > 0)
scan_isoc(fusbh200);
if (fusbh200->need_rescan)
goto rescan;
fusbh200->scanning = false;
turn_on_io_watchdog(fusbh200);
}
static void fusbh200_stop (struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
fusbh200_dbg (fusbh200, "stop\n");
spin_lock_irq(&fusbh200->lock);
fusbh200->enabled_hrtimer_events = 0;
spin_unlock_irq(&fusbh200->lock);
fusbh200_quiesce(fusbh200);
fusbh200_silence_controller(fusbh200);
fusbh200_reset (fusbh200);
hrtimer_cancel(&fusbh200->hrtimer);
remove_sysfs_files(fusbh200);
remove_debug_files (fusbh200);
spin_lock_irq (&fusbh200->lock);
end_free_itds(fusbh200);
spin_unlock_irq (&fusbh200->lock);
fusbh200_mem_cleanup (fusbh200);
fusbh200_dbg(fusbh200, "irq normal %ld err %ld iaa %ld (lost %ld)\n",
fusbh200->stats.normal, fusbh200->stats.error, fusbh200->stats.iaa,
fusbh200->stats.lost_iaa);
fusbh200_dbg (fusbh200, "complete %ld unlink %ld\n",
fusbh200->stats.complete, fusbh200->stats.unlink);
dbg_status (fusbh200, "fusbh200_stop completed",
fusbh200_readl(fusbh200, &fusbh200->regs->status));
}
static int hcd_fusbh200_init(struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200(hcd);
u32 temp;
int retval;
u32 hcc_params;
struct fusbh200_qh_hw *hw;
spin_lock_init(&fusbh200->lock);
fusbh200->need_io_watchdog = 1;
hrtimer_init(&fusbh200->hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
fusbh200->hrtimer.function = fusbh200_hrtimer_func;
fusbh200->next_hrtimer_event = FUSBH200_HRTIMER_NO_EVENT;
hcc_params = fusbh200_readl(fusbh200, &fusbh200->caps->hcc_params);
fusbh200->uframe_periodic_max = 100;
fusbh200->periodic_size = DEFAULT_I_TDPS;
INIT_LIST_HEAD(&fusbh200->intr_qh_list);
INIT_LIST_HEAD(&fusbh200->cached_itd_list);
if (HCC_PGM_FRAMELISTLEN(hcc_params)) {
switch (FUSBH200_TUNE_FLS) {
case 0: fusbh200->periodic_size = 1024; break;
case 1: fusbh200->periodic_size = 512; break;
case 2: fusbh200->periodic_size = 256; break;
default: BUG();
}
}
if ((retval = fusbh200_mem_init(fusbh200, GFP_KERNEL)) < 0)
return retval;
fusbh200->i_thresh = 2;
fusbh200->async->qh_next.qh = NULL;
hw = fusbh200->async->hw;
hw->hw_next = QH_NEXT(fusbh200, fusbh200->async->qh_dma);
hw->hw_info1 = cpu_to_hc32(fusbh200, QH_HEAD);
hw->hw_token = cpu_to_hc32(fusbh200, QTD_STS_HALT);
hw->hw_qtd_next = FUSBH200_LIST_END(fusbh200);
fusbh200->async->qh_state = QH_STATE_LINKED;
hw->hw_alt_next = QTD_NEXT(fusbh200, fusbh200->async->dummy->qtd_dma);
if (log2_irq_thresh < 0 || log2_irq_thresh > 6)
log2_irq_thresh = 0;
temp = 1 << (16 + log2_irq_thresh);
if (HCC_CANPARK(hcc_params)) {
if (park) {
park = min(park, (unsigned) 3);
temp |= CMD_PARK;
temp |= park << 8;
}
fusbh200_dbg(fusbh200, "park %d\n", park);
}
if (HCC_PGM_FRAMELISTLEN(hcc_params)) {
temp &= ~(3 << 2);
temp |= (FUSBH200_TUNE_FLS << 2);
}
fusbh200->command = temp;
if (!(hcd->driver->flags & HCD_LOCAL_MEM))
hcd->self.sg_tablesize = ~0;
return 0;
}
static int fusbh200_run (struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
u32 temp;
u32 hcc_params;
hcd->uses_new_polling = 1;
fusbh200_writel(fusbh200, fusbh200->periodic_dma, &fusbh200->regs->frame_list);
fusbh200_writel(fusbh200, (u32)fusbh200->async->qh_dma, &fusbh200->regs->async_next);
hcc_params = fusbh200_readl(fusbh200, &fusbh200->caps->hcc_params);
fusbh200->command &= ~(CMD_IAAD|CMD_PSE|CMD_ASE|CMD_RESET);
fusbh200->command |= CMD_RUN;
fusbh200_writel(fusbh200, fusbh200->command, &fusbh200->regs->command);
dbg_cmd (fusbh200, "init", fusbh200->command);
down_write(&ehci_cf_port_reset_rwsem);
fusbh200->rh_state = FUSBH200_RH_RUNNING;
fusbh200_readl(fusbh200, &fusbh200->regs->command);
msleep(5);
up_write(&ehci_cf_port_reset_rwsem);
fusbh200->last_periodic_enable = ktime_get_real();
temp = HC_VERSION(fusbh200, fusbh200_readl(fusbh200, &fusbh200->caps->hc_capbase));
fusbh200_info (fusbh200,
"USB %x.%x started, EHCI %x.%02x\n",
((fusbh200->sbrn & 0xf0)>>4), (fusbh200->sbrn & 0x0f),
temp >> 8, temp & 0xff);
fusbh200_writel(fusbh200, INTR_MASK,
&fusbh200->regs->intr_enable);
create_debug_files(fusbh200);
create_sysfs_files(fusbh200);
return 0;
}
static int fusbh200_setup(struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200(hcd);
int retval;
fusbh200->regs = (void __iomem *)fusbh200->caps +
HC_LENGTH(fusbh200, fusbh200_readl(fusbh200, &fusbh200->caps->hc_capbase));
dbg_hcs_params(fusbh200, "reset");
dbg_hcc_params(fusbh200, "reset");
fusbh200->hcs_params = fusbh200_readl(fusbh200, &fusbh200->caps->hcs_params);
fusbh200->sbrn = HCD_USB2;
retval = hcd_fusbh200_init(hcd);
if (retval)
return retval;
retval = fusbh200_halt(fusbh200);
if (retval)
return retval;
fusbh200_reset(fusbh200);
return 0;
}
static irqreturn_t fusbh200_irq (struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
u32 status, masked_status, pcd_status = 0, cmd;
int bh;
spin_lock (&fusbh200->lock);
status = fusbh200_readl(fusbh200, &fusbh200->regs->status);
if (status == ~(u32) 0) {
fusbh200_dbg (fusbh200, "device removed\n");
goto dead;
}
masked_status = status & (INTR_MASK | STS_FLR);
if (!masked_status || unlikely(fusbh200->rh_state == FUSBH200_RH_HALTED)) {
spin_unlock(&fusbh200->lock);
return IRQ_NONE;
}
fusbh200_writel(fusbh200, masked_status, &fusbh200->regs->status);
cmd = fusbh200_readl(fusbh200, &fusbh200->regs->command);
bh = 0;
if (likely ((status & (STS_INT|STS_ERR)) != 0)) {
if (likely ((status & STS_ERR) == 0))
COUNT (fusbh200->stats.normal);
else
COUNT (fusbh200->stats.error);
bh = 1;
}
if (status & STS_IAA) {
fusbh200->enabled_hrtimer_events &= ~BIT(FUSBH200_HRTIMER_IAA_WATCHDOG);
if (fusbh200->next_hrtimer_event == FUSBH200_HRTIMER_IAA_WATCHDOG)
++fusbh200->next_hrtimer_event;
if (cmd & CMD_IAAD)
fusbh200_dbg(fusbh200, "IAA with IAAD still set?\n");
if (fusbh200->async_iaa) {
COUNT(fusbh200->stats.iaa);
end_unlink_async(fusbh200);
} else
fusbh200_dbg(fusbh200, "IAA with nothing unlinked?\n");
}
if (status & STS_PCD) {
int pstatus;
u32 __iomem *status_reg = &fusbh200->regs->port_status;
pcd_status = status;
if (fusbh200->rh_state == FUSBH200_RH_SUSPENDED)
usb_hcd_resume_root_hub(hcd);
pstatus = fusbh200_readl(fusbh200, status_reg);
if (test_bit(0, &fusbh200->suspended_ports) &&
((pstatus & PORT_RESUME) ||
!(pstatus & PORT_SUSPEND)) &&
(pstatus & PORT_PE) &&
fusbh200->reset_done[0] == 0) {
fusbh200->reset_done[0] = jiffies + msecs_to_jiffies(25);
set_bit(0, &fusbh200->resuming_ports);
fusbh200_dbg (fusbh200, "port 1 remote wakeup\n");
mod_timer(&hcd->rh_timer, fusbh200->reset_done[0]);
}
}
if (unlikely ((status & STS_FATAL) != 0)) {
fusbh200_err(fusbh200, "fatal error\n");
dbg_cmd(fusbh200, "fatal", cmd);
dbg_status(fusbh200, "fatal", status);
dead:
usb_hc_died(hcd);
fusbh200->shutdown = true;
fusbh200->rh_state = FUSBH200_RH_STOPPING;
fusbh200->command &= ~(CMD_RUN | CMD_ASE | CMD_PSE);
fusbh200_writel(fusbh200, fusbh200->command, &fusbh200->regs->command);
fusbh200_writel(fusbh200, 0, &fusbh200->regs->intr_enable);
fusbh200_handle_controller_death(fusbh200);
bh = 0;
}
if (bh)
fusbh200_work (fusbh200);
spin_unlock (&fusbh200->lock);
if (pcd_status)
usb_hcd_poll_rh_status(hcd);
return IRQ_HANDLED;
}
static int fusbh200_urb_enqueue (
struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags
) {
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
struct list_head qtd_list;
INIT_LIST_HEAD (&qtd_list);
switch (usb_pipetype (urb->pipe)) {
case PIPE_CONTROL:
if (urb->transfer_buffer_length > (16 * 1024))
return -EMSGSIZE;
default:
if (!qh_urb_transaction (fusbh200, urb, &qtd_list, mem_flags))
return -ENOMEM;
return submit_async(fusbh200, urb, &qtd_list, mem_flags);
case PIPE_INTERRUPT:
if (!qh_urb_transaction (fusbh200, urb, &qtd_list, mem_flags))
return -ENOMEM;
return intr_submit(fusbh200, urb, &qtd_list, mem_flags);
case PIPE_ISOCHRONOUS:
return itd_submit (fusbh200, urb, mem_flags);
}
}
static int fusbh200_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
struct fusbh200_qh *qh;
unsigned long flags;
int rc;
spin_lock_irqsave (&fusbh200->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (rc)
goto done;
switch (usb_pipetype (urb->pipe)) {
default:
qh = (struct fusbh200_qh *) urb->hcpriv;
if (!qh)
break;
switch (qh->qh_state) {
case QH_STATE_LINKED:
case QH_STATE_COMPLETING:
start_unlink_async(fusbh200, qh);
break;
case QH_STATE_UNLINK:
case QH_STATE_UNLINK_WAIT:
break;
case QH_STATE_IDLE:
qh_completions(fusbh200, qh);
break;
}
break;
case PIPE_INTERRUPT:
qh = (struct fusbh200_qh *) urb->hcpriv;
if (!qh)
break;
switch (qh->qh_state) {
case QH_STATE_LINKED:
case QH_STATE_COMPLETING:
start_unlink_intr(fusbh200, qh);
break;
case QH_STATE_IDLE:
qh_completions (fusbh200, qh);
break;
default:
fusbh200_dbg (fusbh200, "bogus qh %p state %d\n",
qh, qh->qh_state);
goto done;
}
break;
case PIPE_ISOCHRONOUS:
break;
}
done:
spin_unlock_irqrestore (&fusbh200->lock, flags);
return rc;
}
static void
fusbh200_endpoint_disable (struct usb_hcd *hcd, struct usb_host_endpoint *ep)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
unsigned long flags;
struct fusbh200_qh *qh, *tmp;
rescan:
spin_lock_irqsave (&fusbh200->lock, flags);
qh = ep->hcpriv;
if (!qh)
goto done;
if (qh->hw == NULL) {
struct fusbh200_iso_stream *stream = ep->hcpriv;
if (!list_empty(&stream->td_list))
goto idle_timeout;
kfree(stream);
goto done;
}
if (fusbh200->rh_state < FUSBH200_RH_RUNNING)
qh->qh_state = QH_STATE_IDLE;
switch (qh->qh_state) {
case QH_STATE_LINKED:
case QH_STATE_COMPLETING:
for (tmp = fusbh200->async->qh_next.qh;
tmp && tmp != qh;
tmp = tmp->qh_next.qh)
continue;
if (tmp)
start_unlink_async(fusbh200, qh);
case QH_STATE_UNLINK:
case QH_STATE_UNLINK_WAIT:
idle_timeout:
spin_unlock_irqrestore (&fusbh200->lock, flags);
schedule_timeout_uninterruptible(1);
goto rescan;
case QH_STATE_IDLE:
if (qh->clearing_tt)
goto idle_timeout;
if (list_empty (&qh->qtd_list)) {
qh_destroy(fusbh200, qh);
break;
}
default:
fusbh200_err (fusbh200, "qh %p (#%02x) state %d%s\n",
qh, ep->desc.bEndpointAddress, qh->qh_state,
list_empty (&qh->qtd_list) ? "" : "(has tds)");
break;
}
done:
ep->hcpriv = NULL;
spin_unlock_irqrestore (&fusbh200->lock, flags);
}
static void
fusbh200_endpoint_reset(struct usb_hcd *hcd, struct usb_host_endpoint *ep)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200(hcd);
struct fusbh200_qh *qh;
int eptype = usb_endpoint_type(&ep->desc);
int epnum = usb_endpoint_num(&ep->desc);
int is_out = usb_endpoint_dir_out(&ep->desc);
unsigned long flags;
if (eptype != USB_ENDPOINT_XFER_BULK && eptype != USB_ENDPOINT_XFER_INT)
return;
spin_lock_irqsave(&fusbh200->lock, flags);
qh = ep->hcpriv;
if (qh) {
usb_settoggle(qh->dev, epnum, is_out, 0);
if (!list_empty(&qh->qtd_list)) {
WARN_ONCE(1, "clear_halt for a busy endpoint\n");
} else if (qh->qh_state == QH_STATE_LINKED ||
qh->qh_state == QH_STATE_COMPLETING) {
if (eptype == USB_ENDPOINT_XFER_BULK)
start_unlink_async(fusbh200, qh);
else
start_unlink_intr(fusbh200, qh);
}
}
spin_unlock_irqrestore(&fusbh200->lock, flags);
}
static int fusbh200_get_frame (struct usb_hcd *hcd)
{
struct fusbh200_hcd *fusbh200 = hcd_to_fusbh200 (hcd);
return (fusbh200_read_frame_index(fusbh200) >> 3) % fusbh200->periodic_size;
}
static void fusbh200_init(struct fusbh200_hcd *fusbh200)
{
u32 reg;
reg = fusbh200_readl(fusbh200, &fusbh200->regs->bmcsr);
reg |= BMCSR_INT_POLARITY;
reg &= ~BMCSR_VBUS_OFF;
fusbh200_writel(fusbh200, reg, &fusbh200->regs->bmcsr);
reg = fusbh200_readl(fusbh200, &fusbh200->regs->bmier);
fusbh200_writel(fusbh200, reg | BMIER_OVC_EN | BMIER_VBUS_ERR_EN,
&fusbh200->regs->bmier);
}
static int fusbh200_hcd_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd;
struct resource *res;
int irq;
int retval = -ENODEV;
struct fusbh200_hcd *fusbh200;
if (usb_disabled())
return -ENODEV;
pdev->dev.power.power_state = PMSG_ON;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(dev));
return -ENODEV;
}
irq = res->start;
hcd = usb_create_hcd(&fusbh200_fusbh200_hc_driver, dev,
dev_name(dev));
if (!hcd) {
dev_err(dev, "failed to create hcd with err %d\n", retval);
retval = -ENOMEM;
goto fail_create_hcd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev,
"Found HC with no register addr. Check %s setup!\n",
dev_name(dev));
retval = -ENODEV;
goto fail_request_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->has_tt = 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
fusbh200_fusbh200_hc_driver.description)) {
dev_dbg(dev, "controller already in use\n");
retval = -EBUSY;
goto fail_request_resource;
}
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res) {
dev_err(dev,
"Found HC with no register addr. Check %s setup!\n",
dev_name(dev));
retval = -ENODEV;
goto fail_request_resource;
}
hcd->regs = ioremap_nocache(res->start, resource_size(res));
if (hcd->regs == NULL) {
dev_dbg(dev, "error mapping memory\n");
retval = -EFAULT;
goto fail_ioremap;
}
fusbh200 = hcd_to_fusbh200(hcd);
fusbh200->caps = hcd->regs;
retval = fusbh200_setup(hcd);
if (retval)
goto fail_add_hcd;
fusbh200_init(fusbh200);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval) {
dev_err(dev, "failed to add hcd with err %d\n", retval);
goto fail_add_hcd;
}
device_wakeup_enable(hcd->self.controller);
return retval;
fail_add_hcd:
iounmap(hcd->regs);
fail_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
dev_err(dev, "init %s fail, %d\n", dev_name(dev), retval);
return retval;
}
static int fusbh200_hcd_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = dev_get_drvdata(dev);
if (!hcd)
return 0;
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
static int __init fusbh200_hcd_init(void)
{
int retval = 0;
if (usb_disabled())
return -ENODEV;
printk(KERN_INFO "%s: " DRIVER_DESC "\n", hcd_name);
set_bit(USB_EHCI_LOADED, &usb_hcds_loaded);
if (test_bit(USB_UHCI_LOADED, &usb_hcds_loaded) ||
test_bit(USB_OHCI_LOADED, &usb_hcds_loaded))
printk(KERN_WARNING "Warning! fusbh200_hcd should always be loaded"
" before uhci_hcd and ohci_hcd, not after\n");
pr_debug("%s: block sizes: qh %Zd qtd %Zd itd %Zd\n",
hcd_name,
sizeof(struct fusbh200_qh), sizeof(struct fusbh200_qtd),
sizeof(struct fusbh200_itd));
fusbh200_debug_root = debugfs_create_dir("fusbh200", usb_debug_root);
if (!fusbh200_debug_root) {
retval = -ENOENT;
goto err_debug;
}
retval = platform_driver_register(&fusbh200_hcd_fusbh200_driver);
if (retval < 0)
goto clean;
return retval;
platform_driver_unregister(&fusbh200_hcd_fusbh200_driver);
clean:
debugfs_remove(fusbh200_debug_root);
fusbh200_debug_root = NULL;
err_debug:
clear_bit(USB_EHCI_LOADED, &usb_hcds_loaded);
return retval;
}
static void __exit fusbh200_hcd_cleanup(void)
{
platform_driver_unregister(&fusbh200_hcd_fusbh200_driver);
debugfs_remove(fusbh200_debug_root);
clear_bit(USB_EHCI_LOADED, &usb_hcds_loaded);
}
