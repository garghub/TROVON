static int bit_parity(u32 pkt)
{
int x = pkt ^ (pkt >> 16);
x ^= x >> 8;
x ^= x >> 4;
x ^= x >> 2;
x ^= x >> 1;
return x & 1;
}
static inline int poll_until(u8 onbits, u8 offbits, int u_sec, struct gameport* gp, u8 *data)
{
int i, nloops;
nloops = gameport_time(gp, u_sec);
for (i = 0; i < nloops; i++) {
*data = gameport_read(gp);
if ((*data & onbits) == onbits &&
(~(*data) & offbits) == offbits)
return 1;
}
dbg("gameport timed out after %d microseconds.\n", u_sec);
return 0;
}
static int mp_io(struct gameport* gameport, int sendflags, int sendcode, u32 *packet)
{
u8 raw_data;
u8 data_mask;
u32 pkt;
int bits_per_read;
int portvals = 0;
int i;
*packet = 0;
raw_data = gameport_read(gameport);
if (raw_data & 1)
return IO_RETRY;
for (i = 0; i < 64; i++) {
raw_data = gameport_read(gameport);
portvals |= 1 << ((raw_data >> 4) & 3);
}
if (portvals == 1) {
raw_data = gameport_read(gameport);
portvals = raw_data & 0xf0;
if (raw_data & 0x31)
return IO_RESET;
gameport_trigger(gameport);
if (!poll_until(0x10, 0, 308, gameport, &raw_data))
return IO_RESET;
} else
return IO_RETRY;
if (raw_data & 0x20) {
portvals |= raw_data >> 4;
if (portvals != 0xb)
return 0;
data_mask = 7;
bits_per_read = 3;
pkt = (PACKET_FULL | PACKET_IO_FAST) >> 28;
} else {
data_mask = 1;
bits_per_read = 1;
pkt = (PACKET_FULL | PACKET_IO_SLOW) >> 28;
}
while (1) {
if (!poll_until(0, 0x10, 77, gameport, &raw_data))
return IO_RESET;
raw_data = (raw_data >> 5) & data_mask;
if (pkt & PACKET_FULL)
break;
pkt = (pkt << bits_per_read) | raw_data;
if (!poll_until(0x10, 0, 77, gameport, &raw_data))
return IO_RESET;
}
if (raw_data)
return IO_RESET;
if (bits_per_read == 3) {
pkt = (pkt & 0xffff0000) | ((pkt << 1) & 0xffff);
pkt = (pkt >> 2) | 0xf0000000;
}
if (bit_parity(pkt) == 1)
return IO_RESET;
if (!poll_until(0x30, 0, 77, gameport, &raw_data))
return IO_RESET;
raw_data = gameport_read(gameport);
if (raw_data & 1)
return IO_RESET;
gameport_trigger(gameport);
if (!poll_until(0, 0x20, 77, gameport, &raw_data))
return IO_RESET;
*packet = pkt;
if ((sendflags == 0) || ((sendflags & IO_RETRY) && !(pkt & PACKET_MP_DONE)))
return IO_GOT_PACKET;
if (pkt & PACKET_MP_MORE)
return IO_GOT_PACKET | IO_RETRY;
if (!poll_until(0x20, 0, 77, gameport, &raw_data))
return IO_GOT_PACKET | IO_RESET;
raw_data = gameport_read(gameport);
if (raw_data & 1)
return IO_GOT_PACKET | IO_RESET;
gameport_trigger(gameport);
do {
if (!poll_until(0x20, 0x10, 116, gameport, &raw_data))
return IO_GOT_PACKET | IO_RESET;
if (!poll_until(0x30, 0, 193, gameport, &raw_data))
return IO_GOT_PACKET | IO_RESET;
if (raw_data & 1)
return IO_GOT_PACKET | IO_RESET;
if (sendcode & 1)
gameport_trigger(gameport);
sendcode >>= 1;
} while (sendcode);
return IO_GOT_PACKET | IO_MODE_FAST;
}
static int multiport_io(struct gameport* gameport, int sendflags, int sendcode, u32 *packet)
{
int status;
unsigned long flags;
local_irq_save(flags);
status = mp_io(gameport, sendflags, sendcode, packet);
local_irq_restore(flags);
return status;
}
static int dig_mode_start(struct gameport *gameport, u32 *packet)
{
int i;
int flags, tries = 0, bads = 0;
for (i = 0; i < ARRAY_SIZE(init_seq); i++) {
if (init_seq[i])
gameport_trigger(gameport);
udelay(GRIP_INIT_DELAY);
}
for (i = 0; i < 16; i++)
udelay(GRIP_INIT_DELAY);
while (tries < 64 && bads < 8) {
flags = multiport_io(gameport, IO_RESET, 0x27, packet);
if (flags & IO_MODE_FAST)
return 1;
if (flags & IO_RETRY)
tries++;
else
bads++;
}
return 0;
}
static int get_and_decode_packet(struct grip_mp *grip, int flags)
{
struct grip_port *port;
u32 packet;
int joytype = 0;
int slot;
flags &= IO_RESET | IO_RETRY;
flags = multiport_io(grip->gameport, flags, 0, &packet);
grip->reads++;
if (packet & PACKET_MP_DONE)
flags |= IO_DONE;
if (flags && !(flags & IO_GOT_PACKET)) {
grip->bads++;
return flags;
}
slot = ((packet >> 21) & 0xf) - 1;
if ((slot < 0) || (slot > 3))
return flags;
port = grip->port[slot];
joytype = (packet >> 16) & 0x1f;
if (!joytype) {
if (port->registered) {
printk(KERN_INFO "grip_mp: removing %s, slot %d\n",
grip_name[port->mode], slot);
input_unregister_device(port->dev);
port->registered = 0;
}
dbg("Reset: grip multiport slot %d\n", slot);
port->mode = GRIP_MODE_RESET;
flags |= IO_SLOT_CHANGE;
return flags;
}
if (joytype == 0x1f) {
int dir = (packet >> 8) & 0xf;
port->buttons = (~packet) & 0xff;
port->yaxes = ((axis_map[dir] >> 2) & 3) - 1;
port->xaxes = (axis_map[dir] & 3) - 1;
port->dirty = 1;
if (port->mode == GRIP_MODE_RESET)
flags |= IO_SLOT_CHANGE;
port->mode = GRIP_MODE_GP;
if (!port->registered) {
dbg("New Grip pad in multiport slot %d.\n", slot);
if (register_slot(slot, grip)) {
port->mode = GRIP_MODE_RESET;
port->dirty = 0;
}
}
return flags;
}
{
static int strange_code = 0;
if (strange_code != joytype) {
printk(KERN_INFO "Possible non-grip pad/joystick detected.\n");
printk(KERN_INFO "Got joy type 0x%x and packet 0x%x.\n", joytype, packet);
strange_code = joytype;
}
}
return flags;
}
static int slots_valid(struct grip_mp *grip)
{
int flags, slot, invalid = 0, active = 0;
flags = get_and_decode_packet(grip, 0);
if (!(flags & IO_GOT_PACKET))
return 0;
for (slot = 0; slot < 4; slot++) {
if (grip->port[slot]->mode == GRIP_MODE_RESET)
invalid = 1;
if (grip->port[slot]->mode != GRIP_MODE_NONE)
active = 1;
}
if (!active)
return (flags & IO_DONE) ? 1 : 0;
return invalid ? 0 : 1;
}
static int multiport_init(struct grip_mp *grip)
{
int dig_mode, initialized = 0, tries = 0;
u32 packet;
dig_mode = dig_mode_start(grip->gameport, &packet);
while (!dig_mode && tries < 4) {
dig_mode = dig_mode_start(grip->gameport, &packet);
tries++;
}
if (dig_mode)
dbg("multiport_init(): digital mode activated.\n");
else {
dbg("multiport_init(): unable to activate digital mode.\n");
return 0;
}
for (tries = 0; tries < 4096; tries++) {
if (slots_valid(grip)) {
initialized = 1;
break;
}
}
dbg("multiport_init(): initialized == %d\n", initialized);
return initialized;
}
static void report_slot(struct grip_mp *grip, int slot)
{
struct grip_port *port = grip->port[slot];
int i;
for (i = 0; i < 8; i++)
input_report_key(port->dev, grip_btn_gp[i], (port->buttons >> i) & 1);
input_report_abs(port->dev, ABS_X, port->xaxes);
input_report_abs(port->dev, ABS_Y, port->yaxes);
input_sync(port->dev);
port->dirty = 0;
}
static void grip_poll(struct gameport *gameport)
{
struct grip_mp *grip = gameport_get_drvdata(gameport);
int i, npkts, flags;
for (npkts = 0; npkts < 4; npkts++) {
flags = IO_RETRY;
for (i = 0; i < 32; i++) {
flags = get_and_decode_packet(grip, flags);
if ((flags & IO_GOT_PACKET) || !(flags & IO_RETRY))
break;
}
if (flags & IO_DONE)
break;
}
for (i = 0; i < 4; i++)
if (grip->port[i]->dirty)
report_slot(grip, i);
}
static int grip_open(struct input_dev *dev)
{
struct grip_mp *grip = input_get_drvdata(dev);
gameport_start_polling(grip->gameport);
return 0;
}
static void grip_close(struct input_dev *dev)
{
struct grip_mp *grip = input_get_drvdata(dev);
gameport_stop_polling(grip->gameport);
}
static int register_slot(int slot, struct grip_mp *grip)
{
struct grip_port *port = grip->port[slot];
struct input_dev *input_dev;
int j, t;
int err;
port->dev = input_dev = input_allocate_device();
if (!input_dev)
return -ENOMEM;
input_dev->name = grip_name[port->mode];
input_dev->id.bustype = BUS_GAMEPORT;
input_dev->id.vendor = GAMEPORT_ID_VENDOR_GRAVIS;
input_dev->id.product = 0x0100 + port->mode;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &grip->gameport->dev;
input_set_drvdata(input_dev, grip);
input_dev->open = grip_open;
input_dev->close = grip_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
for (j = 0; (t = grip_abs[port->mode][j]) >= 0; j++)
input_set_abs_params(input_dev, t, -1, 1, 0, 0);
for (j = 0; (t = grip_btn[port->mode][j]) >= 0; j++)
if (t > 0)
set_bit(t, input_dev->keybit);
err = input_register_device(port->dev);
if (err) {
input_free_device(port->dev);
return err;
}
port->registered = 1;
if (port->dirty)
report_slot(grip, slot);
return 0;
}
static int grip_connect(struct gameport *gameport, struct gameport_driver *drv)
{
struct grip_mp *grip;
int err;
if (!(grip = kzalloc(sizeof(struct grip_mp), GFP_KERNEL)))
return -ENOMEM;
grip->gameport = gameport;
gameport_set_drvdata(gameport, grip);
err = gameport_open(gameport, drv, GAMEPORT_MODE_RAW);
if (err)
goto fail1;
gameport_set_poll_handler(gameport, grip_poll);
gameport_set_poll_interval(gameport, 20);
if (!multiport_init(grip)) {
err = -ENODEV;
goto fail2;
}
if (!grip->port[0]->mode && !grip->port[1]->mode && !grip->port[2]->mode && !grip->port[3]->mode) {
err = -ENODEV;
goto fail2;
}
return 0;
fail2: gameport_close(gameport);
fail1: gameport_set_drvdata(gameport, NULL);
kfree(grip);
return err;
}
static void grip_disconnect(struct gameport *gameport)
{
struct grip_mp *grip = gameport_get_drvdata(gameport);
int i;
for (i = 0; i < 4; i++)
if (grip->port[i]->registered)
input_unregister_device(grip->port[i]->dev);
gameport_close(gameport);
gameport_set_drvdata(gameport, NULL);
kfree(grip);
}
static int __init grip_init(void)
{
return gameport_register_driver(&grip_drv);
}
static void __exit grip_exit(void)
{
gameport_unregister_driver(&grip_drv);
}
