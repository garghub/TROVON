static inline bool TREQ_asserted(u8 portb)
{
return !(portb & TREQ);
}
static inline void assert_TIP(void)
{
if (mcu_is_egret) {
udelay(EGRET_SESSION_DELAY);
out_8(&via[B], in_8(&via[B]) | TIP);
} else
out_8(&via[B], in_8(&via[B]) & ~TIP);
}
static inline void assert_TIP_and_TACK(void)
{
if (mcu_is_egret) {
udelay(EGRET_SESSION_DELAY);
out_8(&via[B], in_8(&via[B]) | TIP | TACK);
} else
out_8(&via[B], in_8(&via[B]) & ~(TIP | TACK));
}
static inline void assert_TACK(void)
{
if (mcu_is_egret) {
udelay(EGRET_TACK_NEGATED_DELAY);
out_8(&via[B], in_8(&via[B]) | TACK);
} else
out_8(&via[B], in_8(&via[B]) & ~TACK);
}
static inline void toggle_TACK(void)
{
out_8(&via[B], in_8(&via[B]) ^ TACK);
}
static inline void negate_TACK(void)
{
if (mcu_is_egret) {
udelay(EGRET_TACK_ASSERTED_DELAY);
out_8(&via[B], in_8(&via[B]) & ~TACK);
} else
out_8(&via[B], in_8(&via[B]) | TACK);
}
static inline void negate_TIP_and_TACK(void)
{
if (mcu_is_egret) {
udelay(EGRET_TACK_ASSERTED_DELAY);
out_8(&via[B], in_8(&via[B]) & ~(TIP | TACK));
} else
out_8(&via[B], in_8(&via[B]) | TIP | TACK);
}
int __init find_via_cuda(void)
{
struct adb_request req;
int err;
if (macintosh_config->adb_type != MAC_ADB_CUDA &&
macintosh_config->adb_type != MAC_ADB_EGRET)
return 0;
via = via1;
cuda_state = idle;
mcu_is_egret = macintosh_config->adb_type == MAC_ADB_EGRET;
err = cuda_init_via();
if (err) {
printk(KERN_ERR "cuda_init_via() failed\n");
via = NULL;
return 0;
}
cuda_request(&req, NULL, 3, CUDA_PACKET, CUDA_AUTOPOLL, 1);
while (!req.complete)
cuda_poll();
return 1;
}
int __init find_via_cuda(void)
{
struct adb_request req;
phys_addr_t taddr;
const u32 *reg;
int err;
if (vias != 0)
return 1;
vias = of_find_node_by_name(NULL, "via-cuda");
if (vias == 0)
return 0;
reg = of_get_property(vias, "reg", NULL);
if (reg == NULL) {
printk(KERN_ERR "via-cuda: No \"reg\" property !\n");
goto fail;
}
taddr = of_translate_address(vias, reg);
if (taddr == 0) {
printk(KERN_ERR "via-cuda: Can't translate address !\n");
goto fail;
}
via = ioremap(taddr, 0x2000);
if (via == NULL) {
printk(KERN_ERR "via-cuda: Can't map address !\n");
goto fail;
}
cuda_state = idle;
sys_ctrler = SYS_CTRLER_CUDA;
err = cuda_init_via();
if (err) {
printk(KERN_ERR "cuda_init_via() failed\n");
via = NULL;
return 0;
}
out_8(&via[IFR], 0x7f);
out_8(&via[IER], IER_SET|SR_INT);
cuda_request(&req, NULL, 3, CUDA_PACKET, CUDA_AUTOPOLL, 1);
while (!req.complete)
cuda_poll();
return 1;
fail:
of_node_put(vias);
vias = NULL;
return 0;
}
static int __init via_cuda_start(void)
{
if (via == NULL)
return -ENODEV;
#ifdef CONFIG_MAC
cuda_irq = IRQ_MAC_ADB;
#else
cuda_irq = irq_of_parse_and_map(vias, 0);
if (!cuda_irq) {
printk(KERN_ERR "via-cuda: can't map interrupts for %pOF\n",
vias);
return -ENODEV;
}
#endif
if (request_irq(cuda_irq, cuda_interrupt, 0, "ADB", cuda_interrupt)) {
printk(KERN_ERR "via-cuda: can't request irq %d\n", cuda_irq);
return -EAGAIN;
}
pr_info("Macintosh Cuda and Egret driver.\n");
cuda_fully_inited = 1;
return 0;
}
static int
cuda_probe(void)
{
#ifdef CONFIG_PPC
if (sys_ctrler != SYS_CTRLER_CUDA)
return -ENODEV;
#else
if (macintosh_config->adb_type != MAC_ADB_CUDA &&
macintosh_config->adb_type != MAC_ADB_EGRET)
return -ENODEV;
#endif
if (via == NULL)
return -ENODEV;
return 0;
}
static int __init sync_egret(void)
{
if (TREQ_asserted(in_8(&via[B]))) {
assert_TIP_and_TACK();
while (1) {
negate_TACK();
mdelay(1);
(void)in_8(&via[SR]);
assert_TACK();
if (!TREQ_asserted(in_8(&via[B])))
break;
}
negate_TIP_and_TACK();
} else if (in_8(&via[B]) & TIP) {
negate_TACK();
assert_TACK();
mdelay(1);
negate_TIP_and_TACK();
}
if (in_8(&via[IFR]) & SR_INT)
(void)in_8(&via[SR]);
return 0;
}
static int
__init cuda_init_via(void)
{
#ifdef CONFIG_PPC
out_8(&via[IER], 0x7f);
(void)in_8(&via[IER]);
#else
out_8(&via[IER], SR_INT);
#endif
out_8(&via[DIRB], (in_8(&via[DIRB]) | TACK | TIP) & ~TREQ);
out_8(&via[ACR], (in_8(&via[ACR]) & ~SR_CTRL) | SR_EXT);
(void)in_8(&via[SR]);
if (mcu_is_egret)
return sync_egret();
negate_TIP_and_TACK();
mdelay(4);
(void)in_8(&via[SR]);
out_8(&via[IFR], SR_INT);
assert_TACK();
WAIT_FOR(TREQ_asserted(in_8(&via[B])), "CUDA response to sync");
WAIT_FOR(in_8(&via[IFR]) & SR_INT, "CUDA response to sync (2)");
(void)in_8(&via[SR]);
out_8(&via[IFR], SR_INT);
negate_TACK();
WAIT_FOR(!TREQ_asserted(in_8(&via[B])), "CUDA response to sync (3)");
WAIT_FOR(in_8(&via[IFR]) & SR_INT, "CUDA response to sync (4)");
(void)in_8(&via[SR]);
out_8(&via[IFR], SR_INT);
return 0;
}
static int
cuda_send_request(struct adb_request *req, int sync)
{
int i;
if ((via == NULL) || !cuda_fully_inited) {
req->complete = 1;
return -ENXIO;
}
req->reply_expected = 1;
i = cuda_write(req);
if (i)
return i;
if (sync) {
while (!req->complete)
cuda_poll();
}
return 0;
}
static int
cuda_adb_autopoll(int devs)
{
struct adb_request req;
if ((via == NULL) || !cuda_fully_inited)
return -ENXIO;
cuda_request(&req, NULL, 3, CUDA_PACKET, CUDA_AUTOPOLL, (devs? 1: 0));
while (!req.complete)
cuda_poll();
return 0;
}
static int
cuda_reset_adb_bus(void)
{
struct adb_request req;
if ((via == NULL) || !cuda_fully_inited)
return -ENXIO;
cuda_request(&req, NULL, 2, ADB_PACKET, 0);
while (!req.complete)
cuda_poll();
return 0;
}
int
cuda_request(struct adb_request *req, void (*done)(struct adb_request *),
int nbytes, ...)
{
va_list list;
int i;
if (via == NULL) {
req->complete = 1;
return -ENXIO;
}
req->nbytes = nbytes;
req->done = done;
va_start(list, nbytes);
for (i = 0; i < nbytes; ++i)
req->data[i] = va_arg(list, int);
va_end(list);
req->reply_expected = 1;
return cuda_write(req);
}
static int
cuda_write(struct adb_request *req)
{
unsigned long flags;
if (req->nbytes < 2 || req->data[0] > CUDA_PACKET) {
req->complete = 1;
return -EINVAL;
}
req->next = NULL;
req->sent = 0;
req->complete = 0;
req->reply_len = 0;
spin_lock_irqsave(&cuda_lock, flags);
if (current_req != 0) {
last_req->next = req;
last_req = req;
} else {
current_req = req;
last_req = req;
if (cuda_state == idle)
cuda_start();
}
spin_unlock_irqrestore(&cuda_lock, flags);
return 0;
}
static void
cuda_start(void)
{
if (current_req == NULL)
return;
data_index = 0;
if (TREQ_asserted(in_8(&via[B])))
return;
out_8(&via[ACR], in_8(&via[ACR]) | SR_OUT);
out_8(&via[SR], current_req->data[data_index++]);
if (mcu_is_egret)
assert_TIP_and_TACK();
else
assert_TIP();
cuda_state = sent_first_byte;
}
void
cuda_poll(void)
{
cuda_interrupt(0, NULL);
}
static irqreturn_t
cuda_interrupt(int irq, void *arg)
{
unsigned long flags;
u8 status;
struct adb_request *req = NULL;
unsigned char ibuf[16];
int ibuf_len = 0;
int complete = 0;
spin_lock_irqsave(&cuda_lock, flags);
#ifdef CONFIG_MAC
if (!arg)
#endif
{
if ((in_8(&via[IFR]) & SR_INT) == 0) {
spin_unlock_irqrestore(&cuda_lock, flags);
return IRQ_NONE;
} else {
out_8(&via[IFR], SR_INT);
}
}
status = in_8(&via[B]) & (TIP | TACK | TREQ);
switch (cuda_state) {
case idle:
(void)in_8(&via[SR]);
idle_state:
assert_TIP();
cuda_state = reading;
reply_ptr = cuda_rbuf;
reading_reply = 0;
break;
case awaiting_reply:
(void)in_8(&via[SR]);
assert_TIP();
cuda_state = reading;
reply_ptr = current_req->reply;
reading_reply = 1;
break;
case sent_first_byte:
if (TREQ_asserted(status)) {
out_8(&via[ACR], in_8(&via[ACR]) & ~SR_OUT);
(void)in_8(&via[SR]);
negate_TIP_and_TACK();
cuda_state = idle;
if (mcu_is_egret)
goto idle_state;
} else {
out_8(&via[SR], current_req->data[data_index++]);
toggle_TACK();
if (mcu_is_egret)
assert_TACK();
cuda_state = sending;
}
break;
case sending:
req = current_req;
if (data_index >= req->nbytes) {
out_8(&via[ACR], in_8(&via[ACR]) & ~SR_OUT);
(void)in_8(&via[SR]);
negate_TIP_and_TACK();
req->sent = 1;
if (req->reply_expected) {
cuda_state = awaiting_reply;
} else {
current_req = req->next;
complete = 1;
cuda_state = idle;
cuda_start();
}
} else {
out_8(&via[SR], req->data[data_index++]);
toggle_TACK();
if (mcu_is_egret)
assert_TACK();
}
break;
case reading:
if (reading_reply ? ARRAY_FULL(current_req->reply, reply_ptr)
: ARRAY_FULL(cuda_rbuf, reply_ptr))
(void)in_8(&via[SR]);
else
*reply_ptr++ = in_8(&via[SR]);
if (!TREQ_asserted(status)) {
if (mcu_is_egret)
assert_TACK();
negate_TIP_and_TACK();
cuda_state = read_done;
if (mcu_is_egret)
goto read_done_state;
} else {
toggle_TACK();
if (mcu_is_egret)
negate_TACK();
}
break;
case read_done:
(void)in_8(&via[SR]);
read_done_state:
if (reading_reply) {
req = current_req;
req->reply_len = reply_ptr - req->reply;
if (req->data[0] == ADB_PACKET) {
if (req->reply_len <= 2 || (req->reply[1] & 2) != 0) {
req->reply_len = 0;
} else {
req->reply_len -= 2;
memmove(req->reply, req->reply + 2, req->reply_len);
}
}
current_req = req->next;
complete = 1;
reading_reply = 0;
} else {
ibuf_len = reply_ptr - cuda_rbuf;
memcpy(ibuf, cuda_rbuf, ibuf_len);
}
reply_ptr = cuda_rbuf;
cuda_state = idle;
cuda_start();
if (cuda_state == idle && TREQ_asserted(in_8(&via[B]))) {
assert_TIP();
cuda_state = reading;
}
break;
default:
pr_err("cuda_interrupt: unknown cuda_state %d?\n", cuda_state);
}
spin_unlock_irqrestore(&cuda_lock, flags);
if (complete && req) {
void (*done)(struct adb_request *) = req->done;
mb();
req->complete = 1;
if (done)
(*done)(req);
}
if (ibuf_len)
cuda_input(ibuf, ibuf_len);
return IRQ_HANDLED;
}
static void
cuda_input(unsigned char *buf, int nb)
{
switch (buf[0]) {
case ADB_PACKET:
#ifdef CONFIG_XMON
if (nb == 5 && buf[2] == 0x2c) {
extern int xmon_wants_key, xmon_adb_keycode;
if (xmon_wants_key) {
xmon_adb_keycode = buf[3];
return;
}
}
#endif
#ifdef CONFIG_ADB
adb_input(buf+2, nb-2, buf[1] & 0x40);
#endif
break;
case TIMER_PACKET:
break;
default:
print_hex_dump(KERN_INFO, "cuda_input: ", DUMP_PREFIX_NONE, 32, 1,
buf, nb, false);
}
}
