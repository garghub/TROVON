int pmu_probe(void)
{
if (macintosh_config->adb_type == MAC_ADB_PB1) {
pmu_kind = PMU_68K_V1;
} else if (macintosh_config->adb_type == MAC_ADB_PB2) {
pmu_kind = PMU_68K_V2;
} else {
return -ENODEV;
}
pmu_state = idle;
return 0;
}
static int
pmu_init(void)
{
int timeout;
volatile struct adb_request req;
via2[B] |= TREQ;
via2[DIRB] = (via2[DIRB] | TREQ) & ~TACK;
pmu_request((struct adb_request *) &req, NULL, 2, PMU_SET_INTR_MASK, PMU_INT_ADB);
timeout = 100000;
while (!req.complete) {
if (--timeout < 0) {
printk(KERN_ERR "pmu_init: no response from PMU\n");
return -EAGAIN;
}
udelay(10);
pmu_poll();
}
timeout = 100000;
interrupt_data[0] = 1;
while (interrupt_data[0] || pmu_state != idle) {
if (--timeout < 0) {
printk(KERN_ERR "pmu_init: timed out acking intrs\n");
return -EAGAIN;
}
if (pmu_state == idle) {
adb_int_pending = 1;
pmu_interrupt(0, NULL);
}
pmu_poll();
udelay(10);
}
pmu_request((struct adb_request *) &req, NULL, 2, PMU_SET_INTR_MASK,
PMU_INT_ADB_AUTO|PMU_INT_SNDBRT|PMU_INT_ADB);
timeout = 100000;
while (!req.complete) {
if (--timeout < 0) {
printk(KERN_ERR "pmu_init: no response from PMU\n");
return -EAGAIN;
}
udelay(10);
pmu_poll();
}
bright_req_1.complete = 1;
bright_req_2.complete = 1;
bright_req_3.complete = 1;
if (request_irq(IRQ_MAC_ADB_SR, pmu_interrupt, 0, "pmu-shift",
pmu_interrupt)) {
printk(KERN_ERR "pmu_init: can't get irq %d\n",
IRQ_MAC_ADB_SR);
return -EAGAIN;
}
if (request_irq(IRQ_MAC_ADB_CL, pmu_interrupt, 0, "pmu-clock",
pmu_interrupt)) {
printk(KERN_ERR "pmu_init: can't get irq %d\n",
IRQ_MAC_ADB_CL);
free_irq(IRQ_MAC_ADB_SR, pmu_interrupt);
return -EAGAIN;
}
pmu_fully_inited = 1;
pmu_enable_backlight(1);
printk("adb: PMU 68K driver v0.5 for Unified ADB.\n");
return 0;
}
int
pmu_get_model(void)
{
return pmu_kind;
}
static int
pmu_send_request(struct adb_request *req, int sync)
{
int i, ret;
if (!pmu_fully_inited)
{
req->complete = 1;
return -ENXIO;
}
ret = -EINVAL;
switch (req->data[0]) {
case PMU_PACKET:
for (i = 0; i < req->nbytes - 1; ++i)
req->data[i] = req->data[i+1];
--req->nbytes;
if (pmu_data_len[req->data[0]][1] != 0) {
req->reply[0] = ADB_RET_OK;
req->reply_len = 1;
} else
req->reply_len = 0;
ret = pmu_queue_request(req);
break;
case CUDA_PACKET:
switch (req->data[1]) {
case CUDA_GET_TIME:
if (req->nbytes != 2)
break;
req->data[0] = PMU_READ_RTC;
req->nbytes = 1;
req->reply_len = 3;
req->reply[0] = CUDA_PACKET;
req->reply[1] = 0;
req->reply[2] = CUDA_GET_TIME;
ret = pmu_queue_request(req);
break;
case CUDA_SET_TIME:
if (req->nbytes != 6)
break;
req->data[0] = PMU_SET_RTC;
req->nbytes = 5;
for (i = 1; i <= 4; ++i)
req->data[i] = req->data[i+1];
req->reply_len = 3;
req->reply[0] = CUDA_PACKET;
req->reply[1] = 0;
req->reply[2] = CUDA_SET_TIME;
ret = pmu_queue_request(req);
break;
case CUDA_GET_PRAM:
if (req->nbytes != 4)
break;
req->data[0] = PMU_READ_NVRAM;
req->data[1] = req->data[2];
req->data[2] = req->data[3];
req->nbytes = 3;
req->reply_len = 3;
req->reply[0] = CUDA_PACKET;
req->reply[1] = 0;
req->reply[2] = CUDA_GET_PRAM;
ret = pmu_queue_request(req);
break;
case CUDA_SET_PRAM:
if (req->nbytes != 5)
break;
req->data[0] = PMU_WRITE_NVRAM;
req->data[1] = req->data[2];
req->data[2] = req->data[3];
req->data[3] = req->data[4];
req->nbytes = 4;
req->reply_len = 3;
req->reply[0] = CUDA_PACKET;
req->reply[1] = 0;
req->reply[2] = CUDA_SET_PRAM;
ret = pmu_queue_request(req);
break;
}
break;
case ADB_PACKET:
for (i = req->nbytes - 1; i > 1; --i)
req->data[i+2] = req->data[i];
req->data[3] = req->nbytes - 2;
req->data[2] = pmu_adb_flags;
req->data[0] = PMU_ADB_CMD;
req->nbytes += 2;
req->reply_expected = 1;
req->reply_len = 0;
ret = pmu_queue_request(req);
break;
}
if (ret)
{
req->complete = 1;
return ret;
}
if (sync) {
while (!req->complete)
pmu_poll();
}
return 0;
}
static int
pmu_autopoll(int devs)
{
struct adb_request req;
if (!pmu_fully_inited) return -ENXIO;
if (devs) {
adb_dev_map = devs;
pmu_request(&req, NULL, 5, PMU_ADB_CMD, 0, 0x86,
adb_dev_map >> 8, adb_dev_map);
pmu_adb_flags = 2;
} else {
pmu_request(&req, NULL, 1, PMU_ADB_POLL_OFF);
pmu_adb_flags = 0;
}
while (!req.complete)
pmu_poll();
return 0;
}
static int
pmu_reset_bus(void)
{
struct adb_request req;
long timeout;
int save_autopoll = adb_dev_map;
if (!pmu_fully_inited) return -ENXIO;
pmu_autopoll(0);
req.nbytes = 5;
req.done = NULL;
req.data[0] = PMU_ADB_CMD;
req.data[1] = 0;
req.data[2] = 3;
req.data[3] = 0;
req.data[4] = 0;
req.reply_len = 0;
req.reply_expected = 1;
if (pmu_queue_request(&req) != 0)
{
printk(KERN_ERR "pmu_adb_reset_bus: pmu_queue_request failed\n");
return -EIO;
}
while (!req.complete)
pmu_poll();
timeout = 100000;
while (!req.complete) {
if (--timeout < 0) {
printk(KERN_ERR "pmu_adb_reset_bus (reset): no response from PMU\n");
return -EIO;
}
udelay(10);
pmu_poll();
}
if (save_autopoll != 0)
pmu_autopoll(save_autopoll);
return 0;
}
int
pmu_request(struct adb_request *req, void (*done)(struct adb_request *),
int nbytes, ...)
{
va_list list;
int i;
if (nbytes < 0 || nbytes > 32) {
printk(KERN_ERR "pmu_request: bad nbytes (%d)\n", nbytes);
req->complete = 1;
return -EINVAL;
}
req->nbytes = nbytes;
req->done = done;
va_start(list, nbytes);
for (i = 0; i < nbytes; ++i)
req->data[i] = va_arg(list, int);
va_end(list);
if (pmu_data_len[req->data[0]][1] != 0) {
req->reply[0] = ADB_RET_OK;
req->reply_len = 1;
} else
req->reply_len = 0;
req->reply_expected = 0;
return pmu_queue_request(req);
}
int
pmu_queue_request(struct adb_request *req)
{
unsigned long flags;
int nsend;
if (req->nbytes <= 0) {
req->complete = 1;
return 0;
}
nsend = pmu_data_len[req->data[0]][0];
if (nsend >= 0 && req->nbytes != nsend + 1) {
req->complete = 1;
return -EINVAL;
}
req->next = NULL;
req->sent = 0;
req->complete = 0;
local_irq_save(flags);
if (current_req != 0) {
last_req->next = req;
last_req = req;
} else {
current_req = req;
last_req = req;
if (pmu_state == idle)
pmu_start();
}
local_irq_restore(flags);
return 0;
}
static void
send_byte(int x)
{
via1[ACR] |= SR_CTRL;
via1[SR] = x;
via2[B] &= ~TREQ;
}
static void
recv_byte(void)
{
char c;
via1[ACR] = (via1[ACR] | SR_EXT) & ~SR_OUT;
c = via1[SR];
via2[B] &= ~TREQ;
}
static void
pmu_start(void)
{
unsigned long flags;
struct adb_request *req;
local_irq_save(flags);
req = current_req;
if (req == 0 || pmu_state != idle
|| (req->reply_expected && req_awaiting_reply))
goto out;
pmu_state = sending;
data_index = 1;
data_len = pmu_data_len[req->data[0]][0];
send_byte(req->data[0]);
out:
local_irq_restore(flags);
}
void
pmu_poll(void)
{
unsigned long flags;
local_irq_save(flags);
if (via1[IFR] & SR_INT) {
via1[IFR] = SR_INT;
pmu_interrupt(IRQ_MAC_ADB_SR, NULL);
}
if (via1[IFR] & CB1_INT) {
via1[IFR] = CB1_INT;
pmu_interrupt(IRQ_MAC_ADB_CL, NULL);
}
local_irq_restore(flags);
}
static irqreturn_t
pmu_interrupt(int irq, void *dev_id)
{
struct adb_request *req;
int timeout, bite = 0;
#if 0
printk("pmu_interrupt: irq %d state %d acr %02X, b %02X data_index %d/%d adb_int_pending %d\n",
irq, pmu_state, (uint) via1[ACR], (uint) via2[B], data_index, data_len, adb_int_pending);
#endif
if (irq == IRQ_MAC_ADB_CL) {
adb_int_pending = 1;
} else if (irq == IRQ_MAC_ADB_SR) {
if (via2[B] & TACK) {
printk(KERN_DEBUG "PMU: SR_INT but ack still high! (%x)\n", via2[B]);
}
if ((via1[ACR] & SR_OUT) == 0) bite = via1[SR];
via2[B] |= TREQ;
timeout = 3200;
while (!(via2[B] & TACK)) {
if (--timeout < 0) {
printk(KERN_ERR "PMU not responding (!ack)\n");
goto finish;
}
udelay(10);
}
switch (pmu_state) {
case sending:
req = current_req;
if (data_len < 0) {
data_len = req->nbytes - 1;
send_byte(data_len);
break;
}
if (data_index <= data_len) {
send_byte(req->data[data_index++]);
break;
}
req->sent = 1;
data_len = pmu_data_len[req->data[0]][1];
if (data_len == 0) {
pmu_state = idle;
current_req = req->next;
if (req->reply_expected)
req_awaiting_reply = req;
else
pmu_done(req);
} else {
pmu_state = reading;
data_index = 0;
reply_ptr = req->reply + req->reply_len;
recv_byte();
}
break;
case intack:
data_index = 0;
data_len = -1;
pmu_state = reading_intr;
reply_ptr = interrupt_data;
recv_byte();
break;
case reading:
case reading_intr:
if (data_len == -1) {
data_len = bite;
if (bite > 32)
printk(KERN_ERR "PMU: bad reply len %d\n",
bite);
} else {
reply_ptr[data_index++] = bite;
}
if (data_index < data_len) {
recv_byte();
break;
}
if (pmu_state == reading_intr) {
pmu_handle_data(interrupt_data, data_index);
} else {
req = current_req;
current_req = req->next;
req->reply_len += data_index;
pmu_done(req);
}
pmu_state = idle;
break;
default:
printk(KERN_ERR "pmu_interrupt: unknown state %d?\n",
pmu_state);
}
}
finish:
if (pmu_state == idle) {
if (adb_int_pending) {
pmu_state = intack;
send_byte(PMU_INT_ACK);
adb_int_pending = 0;
} else if (current_req) {
pmu_start();
}
}
#if 0
printk("pmu_interrupt: exit state %d acr %02X, b %02X data_index %d/%d adb_int_pending %d\n",
pmu_state, (uint) via1[ACR], (uint) via2[B], data_index, data_len, adb_int_pending);
#endif
return IRQ_HANDLED;
}
static void
pmu_done(struct adb_request *req)
{
req->complete = 1;
if (req->done)
(*req->done)(req);
}
static void
pmu_handle_data(unsigned char *data, int len)
{
static int show_pmu_ints = 1;
asleep = 0;
if (len < 1) {
adb_int_pending = 0;
return;
}
if (data[0] & PMU_INT_ADB) {
if ((data[0] & PMU_INT_ADB_AUTO) == 0) {
struct adb_request *req = req_awaiting_reply;
if (req == 0) {
printk(KERN_ERR "PMU: extra ADB reply\n");
return;
}
req_awaiting_reply = NULL;
if (len <= 2)
req->reply_len = 0;
else {
memcpy(req->reply, data + 1, len - 1);
req->reply_len = len - 1;
}
pmu_done(req);
} else {
adb_input(data+1, len-1, 1);
}
} else {
if (data[0] == 0x08 && len == 3) {
pmu_set_brightness(data[1] >> 3);
set_volume(data[2]);
} else if (show_pmu_ints
&& !(data[0] == PMU_INT_TICK && len == 1)) {
int i;
printk(KERN_DEBUG "pmu intr");
for (i = 0; i < len; ++i)
printk(" %.2x", data[i]);
printk("\n");
}
}
}
static void
pmu_enable_backlight(int on)
{
struct adb_request req;
if (on) {
if (backlight_level < 0) {
switch(pmu_kind) {
case PMU_68K_V1:
case PMU_68K_V2:
pmu_request(&req, NULL, 3, PMU_READ_NVRAM, 0x14, 0xe);
while (!req.complete)
pmu_poll();
printk(KERN_DEBUG "pmu: nvram returned bright: %d\n", (int)req.reply[1]);
backlight_level = req.reply[1];
break;
default:
backlight_enabled = 0;
return;
}
}
pmu_request(&req, NULL, 2, PMU_BACKLIGHT_BRIGHT,
LEVEL_TO_BRIGHT(backlight_level));
while (!req.complete)
pmu_poll();
}
pmu_request(&req, NULL, 2, PMU_POWER_CTRL,
PMU_POW_BACKLIGHT | (on ? PMU_POW_ON : PMU_POW_OFF));
while (!req.complete)
pmu_poll();
backlight_enabled = on;
}
static void
pmu_set_brightness(int level)
{
int bright;
backlight_level = level;
bright = LEVEL_TO_BRIGHT(level);
if (!backlight_enabled)
return;
if (bright_req_1.complete)
pmu_request(&bright_req_1, NULL, 2, PMU_BACKLIGHT_BRIGHT,
bright);
if (bright_req_2.complete)
pmu_request(&bright_req_2, NULL, 2, PMU_POWER_CTRL,
PMU_POW_BACKLIGHT | (bright < 0x7f ? PMU_POW_ON : PMU_POW_OFF));
}
void
pmu_enable_irled(int on)
{
struct adb_request req;
pmu_request(&req, NULL, 2, PMU_POWER_CTRL, PMU_POW_IRLED |
(on ? PMU_POW_ON : PMU_POW_OFF));
while (!req.complete)
pmu_poll();
}
static void
set_volume(int level)
{
}
int
pmu_present(void)
{
return (pmu_kind != PMU_UNKNOWN);
}
