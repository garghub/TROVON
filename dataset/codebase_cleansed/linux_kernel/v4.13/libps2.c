int ps2_sendbyte(struct ps2dev *ps2dev, unsigned char byte, int timeout)
{
serio_pause_rx(ps2dev->serio);
ps2dev->nak = 1;
ps2dev->flags |= PS2_FLAG_ACK;
serio_continue_rx(ps2dev->serio);
if (serio_write(ps2dev->serio, byte) == 0)
wait_event_timeout(ps2dev->wait,
!(ps2dev->flags & PS2_FLAG_ACK),
msecs_to_jiffies(timeout));
serio_pause_rx(ps2dev->serio);
ps2dev->flags &= ~PS2_FLAG_ACK;
serio_continue_rx(ps2dev->serio);
return -ps2dev->nak;
}
void ps2_begin_command(struct ps2dev *ps2dev)
{
struct mutex *m = ps2dev->serio->ps2_cmd_mutex ?: &ps2dev->cmd_mutex;
mutex_lock(m);
}
void ps2_end_command(struct ps2dev *ps2dev)
{
struct mutex *m = ps2dev->serio->ps2_cmd_mutex ?: &ps2dev->cmd_mutex;
mutex_unlock(m);
}
void ps2_drain(struct ps2dev *ps2dev, int maxbytes, int timeout)
{
if (maxbytes > sizeof(ps2dev->cmdbuf)) {
WARN_ON(1);
maxbytes = sizeof(ps2dev->cmdbuf);
}
ps2_begin_command(ps2dev);
serio_pause_rx(ps2dev->serio);
ps2dev->flags = PS2_FLAG_CMD;
ps2dev->cmdcnt = maxbytes;
serio_continue_rx(ps2dev->serio);
wait_event_timeout(ps2dev->wait,
!(ps2dev->flags & PS2_FLAG_CMD),
msecs_to_jiffies(timeout));
ps2_end_command(ps2dev);
}
int ps2_is_keyboard_id(char id_byte)
{
static const char keyboard_ids[] = {
0xab,
0xac,
0x2b,
0x5d,
0x60,
0x47,
};
return memchr(keyboard_ids, id_byte, sizeof(keyboard_ids)) != NULL;
}
static int ps2_adjust_timeout(struct ps2dev *ps2dev, int command, int timeout)
{
switch (command) {
case PS2_CMD_RESET_BAT:
if (timeout > msecs_to_jiffies(100))
timeout = msecs_to_jiffies(100);
break;
case PS2_CMD_GETID:
if (ps2dev->cmdbuf[1] == 0xaa) {
serio_pause_rx(ps2dev->serio);
ps2dev->flags = 0;
serio_continue_rx(ps2dev->serio);
timeout = 0;
}
if (!ps2_is_keyboard_id(ps2dev->cmdbuf[1])) {
serio_pause_rx(ps2dev->serio);
ps2dev->flags = ps2dev->cmdcnt = 0;
serio_continue_rx(ps2dev->serio);
timeout = 0;
}
break;
default:
break;
}
return timeout;
}
int __ps2_command(struct ps2dev *ps2dev, unsigned char *param, int command)
{
int timeout;
int send = (command >> 12) & 0xf;
int receive = (command >> 8) & 0xf;
int rc = -1;
int i;
if (receive > sizeof(ps2dev->cmdbuf)) {
WARN_ON(1);
return -1;
}
if (send && !param) {
WARN_ON(1);
return -1;
}
serio_pause_rx(ps2dev->serio);
ps2dev->flags = command == PS2_CMD_GETID ? PS2_FLAG_WAITID : 0;
ps2dev->cmdcnt = receive;
if (receive && param)
for (i = 0; i < receive; i++)
ps2dev->cmdbuf[(receive - 1) - i] = param[i];
serio_continue_rx(ps2dev->serio);
if (ps2_sendbyte(ps2dev, command & 0xff,
command == PS2_CMD_RESET_BAT ? 1000 : 200)) {
serio_pause_rx(ps2dev->serio);
goto out_reset_flags;
}
for (i = 0; i < send; i++) {
if (ps2_sendbyte(ps2dev, param[i], 200)) {
serio_pause_rx(ps2dev->serio);
goto out_reset_flags;
}
}
timeout = msecs_to_jiffies(command == PS2_CMD_RESET_BAT ? 4000 : 500);
timeout = wait_event_timeout(ps2dev->wait,
!(ps2dev->flags & PS2_FLAG_CMD1), timeout);
if (ps2dev->cmdcnt && !(ps2dev->flags & PS2_FLAG_CMD1)) {
timeout = ps2_adjust_timeout(ps2dev, command, timeout);
wait_event_timeout(ps2dev->wait,
!(ps2dev->flags & PS2_FLAG_CMD), timeout);
}
serio_pause_rx(ps2dev->serio);
if (param)
for (i = 0; i < receive; i++)
param[i] = ps2dev->cmdbuf[(receive - 1) - i];
if (ps2dev->cmdcnt && (command != PS2_CMD_RESET_BAT || ps2dev->cmdcnt != 1))
goto out_reset_flags;
rc = 0;
out_reset_flags:
ps2dev->flags = 0;
serio_continue_rx(ps2dev->serio);
return rc;
}
int ps2_command(struct ps2dev *ps2dev, unsigned char *param, int command)
{
int rc;
ps2_begin_command(ps2dev);
rc = __ps2_command(ps2dev, param, command);
ps2_end_command(ps2dev);
return rc;
}
void ps2_init(struct ps2dev *ps2dev, struct serio *serio)
{
mutex_init(&ps2dev->cmd_mutex);
lockdep_set_subclass(&ps2dev->cmd_mutex, serio->depth);
init_waitqueue_head(&ps2dev->wait);
ps2dev->serio = serio;
}
int ps2_handle_ack(struct ps2dev *ps2dev, unsigned char data)
{
switch (data) {
case PS2_RET_ACK:
ps2dev->nak = 0;
break;
case PS2_RET_NAK:
ps2dev->flags |= PS2_FLAG_NAK;
ps2dev->nak = PS2_RET_NAK;
break;
case PS2_RET_ERR:
if (ps2dev->flags & PS2_FLAG_NAK) {
ps2dev->flags &= ~PS2_FLAG_NAK;
ps2dev->nak = PS2_RET_ERR;
break;
}
case 0x00:
case 0x03:
case 0x04:
if (ps2dev->flags & PS2_FLAG_WAITID) {
ps2dev->nak = 0;
break;
}
default:
return 0;
}
if (!ps2dev->nak) {
ps2dev->flags &= ~PS2_FLAG_NAK;
if (ps2dev->cmdcnt)
ps2dev->flags |= PS2_FLAG_CMD | PS2_FLAG_CMD1;
}
ps2dev->flags &= ~PS2_FLAG_ACK;
wake_up(&ps2dev->wait);
if (data != PS2_RET_ACK)
ps2_handle_response(ps2dev, data);
return 1;
}
int ps2_handle_response(struct ps2dev *ps2dev, unsigned char data)
{
if (ps2dev->cmdcnt)
ps2dev->cmdbuf[--ps2dev->cmdcnt] = data;
if (ps2dev->flags & PS2_FLAG_CMD1) {
ps2dev->flags &= ~PS2_FLAG_CMD1;
if (ps2dev->cmdcnt)
wake_up(&ps2dev->wait);
}
if (!ps2dev->cmdcnt) {
ps2dev->flags &= ~PS2_FLAG_CMD;
wake_up(&ps2dev->wait);
}
return 1;
}
void ps2_cmd_aborted(struct ps2dev *ps2dev)
{
if (ps2dev->flags & PS2_FLAG_ACK)
ps2dev->nak = 1;
if (ps2dev->flags & (PS2_FLAG_ACK | PS2_FLAG_CMD))
wake_up(&ps2dev->wait);
ps2dev->flags &= PS2_FLAG_NAK;
}
