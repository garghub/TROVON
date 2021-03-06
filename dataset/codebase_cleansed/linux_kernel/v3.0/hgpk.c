static int hgpk_mode_from_name(const char *buf, int len)
{
int i;
for (i = 0; i < ARRAY_SIZE(hgpk_mode_names); i++) {
const char *name = hgpk_mode_names[i];
if (strlen(name) == len && !strncasecmp(name, buf, len))
return i;
}
return HGPK_MODE_INVALID;
}
static int approx_half(int curr, int prev)
{
int belowhalf, abovehalf;
if (curr < 5 || prev < 5)
return 0;
belowhalf = (prev * 8) / 20;
abovehalf = (prev * 12) / 20;
return belowhalf < curr && curr <= abovehalf;
}
static int hgpk_discard_decay_hack(struct psmouse *psmouse, int x, int y)
{
struct hgpk_data *priv = psmouse->private;
int avx, avy;
bool do_recal = false;
avx = abs(x);
avy = abs(y);
if (avx > recalib_delta ||
(avx > recalib_delta / 2 && ((avx / 4) > priv->xlast))) {
hgpk_err(psmouse, "detected %dpx jump in x\n", x);
priv->xbigj = avx;
} else if (approx_half(avx, priv->xbigj)) {
hgpk_err(psmouse, "detected secondary %dpx jump in x\n", x);
priv->xbigj = avx;
priv->xsaw_secondary++;
} else {
if (priv->xbigj && priv->xsaw_secondary > 1)
do_recal = true;
priv->xbigj = 0;
priv->xsaw_secondary = 0;
}
if (avy > recalib_delta ||
(avy > recalib_delta / 2 && ((avy / 4) > priv->ylast))) {
hgpk_err(psmouse, "detected %dpx jump in y\n", y);
priv->ybigj = avy;
} else if (approx_half(avy, priv->ybigj)) {
hgpk_err(psmouse, "detected secondary %dpx jump in y\n", y);
priv->ybigj = avy;
priv->ysaw_secondary++;
} else {
if (priv->ybigj && priv->ysaw_secondary > 1)
do_recal = true;
priv->ybigj = 0;
priv->ysaw_secondary = 0;
}
priv->xlast = avx;
priv->ylast = avy;
if (do_recal && jumpy_delay) {
hgpk_err(psmouse, "scheduling recalibration\n");
psmouse_queue_work(psmouse, &priv->recalib_wq,
msecs_to_jiffies(jumpy_delay));
}
return priv->xbigj || priv->ybigj;
}
static void hgpk_reset_spew_detection(struct hgpk_data *priv)
{
priv->spew_count = 0;
priv->dupe_count = 0;
priv->x_tally = 0;
priv->y_tally = 0;
priv->spew_flag = NO_SPEW;
}
static void hgpk_reset_hack_state(struct psmouse *psmouse)
{
struct hgpk_data *priv = psmouse->private;
priv->abs_x = priv->abs_y = -1;
priv->xlast = priv->ylast = ILLEGAL_XY;
priv->xbigj = priv->ybigj = 0;
priv->xsaw_secondary = priv->ysaw_secondary = 0;
hgpk_reset_spew_detection(priv);
}
static void hgpk_spewing_hack(struct psmouse *psmouse,
int l, int r, int x, int y)
{
struct hgpk_data *priv = psmouse->private;
if (l || r)
return;
if (!spew_delay)
return;
if (abs(x) > 3 || abs(y) > 3) {
hgpk_reset_spew_detection(priv);
return;
}
priv->x_tally += x;
priv->y_tally += y;
switch (priv->spew_flag) {
case NO_SPEW:
priv->spew_flag = MAYBE_SPEWING;
case MAYBE_SPEWING:
priv->spew_count++;
if (priv->spew_count < SPEW_WATCH_COUNT)
break;
priv->spew_flag = SPEW_DETECTED;
case SPEW_DETECTED:
if (abs(priv->x_tally) < 3 && abs(priv->y_tally) < 3) {
hgpk_err(psmouse, "packet spew detected (%d,%d)\n",
priv->x_tally, priv->y_tally);
priv->spew_flag = RECALIBRATING;
psmouse_queue_work(psmouse, &priv->recalib_wq,
msecs_to_jiffies(spew_delay));
}
break;
case RECALIBRATING:
break;
}
}
static bool hgpk_is_byte_valid(struct psmouse *psmouse, unsigned char *packet)
{
struct hgpk_data *priv = psmouse->private;
int pktcnt = psmouse->pktcnt;
bool valid;
switch (priv->mode) {
case HGPK_MODE_MOUSE:
valid = (packet[0] & 0x0C) == 0x08;
break;
case HGPK_MODE_GLIDESENSOR:
valid = pktcnt == 1 ?
packet[0] == HGPK_GS : !(packet[pktcnt - 1] & 0x80);
break;
case HGPK_MODE_PENTABLET:
valid = pktcnt == 1 ?
packet[0] == HGPK_PT : !(packet[pktcnt - 1] & 0x80);
break;
default:
valid = false;
break;
}
if (!valid)
hgpk_dbg(psmouse,
"bad data, mode %d (%d) %02x %02x %02x %02x %02x %02x\n",
priv->mode, pktcnt,
psmouse->packet[0], psmouse->packet[1],
psmouse->packet[2], psmouse->packet[3],
psmouse->packet[4], psmouse->packet[5]);
return valid;
}
static void hgpk_process_advanced_packet(struct psmouse *psmouse)
{
struct hgpk_data *priv = psmouse->private;
struct input_dev *idev = psmouse->dev;
unsigned char *packet = psmouse->packet;
int down = !!(packet[2] & 2);
int left = !!(packet[3] & 1);
int right = !!(packet[3] & 2);
int x = packet[1] | ((packet[2] & 0x78) << 4);
int y = packet[4] | ((packet[3] & 0x70) << 3);
if (priv->mode == HGPK_MODE_GLIDESENSOR) {
int pt_down = !!(packet[2] & 1);
int finger_down = !!(packet[2] & 2);
int z = packet[5];
input_report_abs(idev, ABS_PRESSURE, z);
if (tpdebug)
hgpk_dbg(psmouse, "pd=%d fd=%d z=%d",
pt_down, finger_down, z);
} else {
if (tpdebug)
hgpk_dbg(psmouse, "pd=%d ", down);
}
if (tpdebug)
hgpk_dbg(psmouse, "l=%d r=%d x=%d y=%d\n", left, right, x, y);
input_report_key(idev, BTN_TOUCH, down);
input_report_key(idev, BTN_LEFT, left);
input_report_key(idev, BTN_RIGHT, right);
if (!down) {
hgpk_reset_hack_state(psmouse);
goto done;
}
if (x == priv->abs_x && y == priv->abs_y) {
if (++priv->dupe_count > SPEW_WATCH_COUNT) {
if (tpdebug)
hgpk_dbg(psmouse, "hard spew detected\n");
priv->spew_flag = RECALIBRATING;
psmouse_queue_work(psmouse, &priv->recalib_wq,
msecs_to_jiffies(spew_delay));
}
goto done;
}
priv->dupe_count = 0;
if (priv->mode != HGPK_MODE_PENTABLET && priv->abs_x != -1) {
int x_diff = priv->abs_x - x;
int y_diff = priv->abs_y - y;
if (hgpk_discard_decay_hack(psmouse, x_diff, y_diff)) {
if (tpdebug)
hgpk_dbg(psmouse, "discarding\n");
goto done;
}
hgpk_spewing_hack(psmouse, left, right, x_diff, y_diff);
}
input_report_abs(idev, ABS_X, x);
input_report_abs(idev, ABS_Y, y);
priv->abs_x = x;
priv->abs_y = y;
done:
input_sync(idev);
}
static void hgpk_process_simple_packet(struct psmouse *psmouse)
{
struct input_dev *dev = psmouse->dev;
unsigned char *packet = psmouse->packet;
int left = packet[0] & 1;
int right = (packet[0] >> 1) & 1;
int x = packet[1] - ((packet[0] << 4) & 0x100);
int y = ((packet[0] << 3) & 0x100) - packet[2];
if (packet[0] & 0xc0)
hgpk_dbg(psmouse,
"overflow -- 0x%02x 0x%02x 0x%02x\n",
packet[0], packet[1], packet[2]);
if (hgpk_discard_decay_hack(psmouse, x, y)) {
if (tpdebug)
hgpk_dbg(psmouse, "discarding\n");
return;
}
hgpk_spewing_hack(psmouse, left, right, x, y);
if (tpdebug)
hgpk_dbg(psmouse, "l=%d r=%d x=%d y=%d\n", left, right, x, y);
input_report_key(dev, BTN_LEFT, left);
input_report_key(dev, BTN_RIGHT, right);
input_report_rel(dev, REL_X, x);
input_report_rel(dev, REL_Y, y);
input_sync(dev);
}
static psmouse_ret_t hgpk_process_byte(struct psmouse *psmouse)
{
struct hgpk_data *priv = psmouse->private;
if (!hgpk_is_byte_valid(psmouse, psmouse->packet))
return PSMOUSE_BAD_DATA;
if (psmouse->pktcnt >= psmouse->pktsize) {
if (priv->mode == HGPK_MODE_MOUSE)
hgpk_process_simple_packet(psmouse);
else
hgpk_process_advanced_packet(psmouse);
return PSMOUSE_FULL_PACKET;
}
if (priv->recalib_window) {
if (time_before(jiffies, priv->recalib_window)) {
hgpk_dbg(psmouse,
"packet inside calibration window, "
"queueing another recalibration\n");
psmouse_queue_work(psmouse, &priv->recalib_wq,
msecs_to_jiffies(post_interrupt_delay));
}
priv->recalib_window = 0;
}
return PSMOUSE_GOOD_DATA;
}
static int hgpk_select_mode(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
struct hgpk_data *priv = psmouse->private;
int i;
int cmd;
const int advanced_init[] = {
PSMOUSE_CMD_DISABLE, PSMOUSE_CMD_DISABLE,
PSMOUSE_CMD_DISABLE, PSMOUSE_CMD_DISABLE,
0xf2, 0xf2, 0xf2,
};
switch (priv->mode) {
case HGPK_MODE_MOUSE:
psmouse->pktsize = 3;
break;
case HGPK_MODE_GLIDESENSOR:
case HGPK_MODE_PENTABLET:
psmouse->pktsize = 6;
for (i = 0; i < ARRAY_SIZE(advanced_init); i++)
if (ps2_command(ps2dev, NULL, advanced_init[i]))
return -EIO;
cmd = priv->mode == HGPK_MODE_GLIDESENSOR ?
PSMOUSE_CMD_SETSCALE11 : PSMOUSE_CMD_SETSCALE21;
if (ps2_command(ps2dev, NULL, cmd))
return -EIO;
break;
default:
return -EINVAL;
}
return 0;
}
static void hgpk_setup_input_device(struct input_dev *input,
struct input_dev *old_input,
enum hgpk_mode mode)
{
if (old_input) {
input->name = old_input->name;
input->phys = old_input->phys;
input->id = old_input->id;
input->dev.parent = old_input->dev.parent;
}
memset(input->evbit, 0, sizeof(input->evbit));
memset(input->relbit, 0, sizeof(input->relbit));
memset(input->keybit, 0, sizeof(input->keybit));
__set_bit(EV_KEY, input->evbit);
__set_bit(BTN_LEFT, input->keybit);
__set_bit(BTN_RIGHT, input->keybit);
switch (mode) {
case HGPK_MODE_MOUSE:
__set_bit(EV_REL, input->evbit);
__set_bit(REL_X, input->relbit);
__set_bit(REL_Y, input->relbit);
break;
case HGPK_MODE_GLIDESENSOR:
__set_bit(BTN_TOUCH, input->keybit);
__set_bit(BTN_TOOL_FINGER, input->keybit);
__set_bit(EV_ABS, input->evbit);
input_set_abs_params(input, ABS_PRESSURE, 0, 15, 0, 0);
input_set_abs_params(input, ABS_X, 0, 399, 0, 0);
input_set_abs_params(input, ABS_Y, 0, 290, 0, 0);
input_abs_set_res(input, ABS_X, 8);
input_abs_set_res(input, ABS_Y, 8);
break;
case HGPK_MODE_PENTABLET:
__set_bit(BTN_TOUCH, input->keybit);
__set_bit(BTN_TOOL_FINGER, input->keybit);
__set_bit(EV_ABS, input->evbit);
input_set_abs_params(input, ABS_X, 0, 999, 0, 0);
input_set_abs_params(input, ABS_Y, 5, 239, 0, 0);
input_abs_set_res(input, ABS_X, 6);
input_abs_set_res(input, ABS_Y, 8);
break;
default:
BUG();
}
}
static int hgpk_reset_device(struct psmouse *psmouse, bool recalibrate)
{
int err;
psmouse_reset(psmouse);
if (recalibrate) {
struct ps2dev *ps2dev = &psmouse->ps2dev;
if (ps2_command(ps2dev, NULL, 0xf5) ||
ps2_command(ps2dev, NULL, 0xf5) ||
ps2_command(ps2dev, NULL, 0xe6) ||
ps2_command(ps2dev, NULL, 0xf5)) {
return -1;
}
msleep(150);
}
err = hgpk_select_mode(psmouse);
if (err) {
hgpk_err(psmouse, "failed to select mode\n");
return err;
}
hgpk_reset_hack_state(psmouse);
return 0;
}
static int hgpk_force_recalibrate(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
struct hgpk_data *priv = psmouse->private;
int err;
if (psmouse->model < HGPK_MODEL_C)
return 0;
if (!autorecal) {
hgpk_dbg(psmouse, "recalibrations disabled, ignoring\n");
return 0;
}
hgpk_dbg(psmouse, "recalibrating touchpad..\n");
psmouse_set_state(psmouse, PSMOUSE_INITIALIZING);
err = hgpk_reset_device(psmouse, true);
if (err)
return err;
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_ENABLE))
return -1;
psmouse_set_state(psmouse, PSMOUSE_ACTIVATED);
if (tpdebug)
hgpk_dbg(psmouse, "touchpad reactivated\n");
if (recal_guard_time)
priv->recalib_window = jiffies +
msecs_to_jiffies(recal_guard_time);
return 0;
}
static int hgpk_toggle_powersave(struct psmouse *psmouse, int enable)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
int timeo;
int err;
if (psmouse->model < HGPK_MODEL_D)
return 0;
if (enable) {
psmouse_set_state(psmouse, PSMOUSE_INITIALIZING);
for (timeo = 20; timeo > 0; timeo--) {
if (!ps2_sendbyte(&psmouse->ps2dev,
PSMOUSE_CMD_DISABLE, 20))
break;
msleep(25);
}
err = hgpk_reset_device(psmouse, false);
if (err) {
hgpk_err(psmouse, "Failed to reset device!\n");
return err;
}
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_ENABLE);
psmouse_set_state(psmouse, PSMOUSE_ACTIVATED);
hgpk_dbg(psmouse, "Touchpad powered up.\n");
} else {
hgpk_dbg(psmouse, "Powering off touchpad.\n");
if (ps2_command(ps2dev, NULL, 0xec) ||
ps2_command(ps2dev, NULL, 0xec) ||
ps2_command(ps2dev, NULL, 0xea)) {
return -1;
}
psmouse_set_state(psmouse, PSMOUSE_IGNORE);
ps2_sendbyte(&psmouse->ps2dev, 0xec, 20);
}
return 0;
}
static int hgpk_poll(struct psmouse *psmouse)
{
return -1;
}
static int hgpk_reconnect(struct psmouse *psmouse)
{
struct hgpk_data *priv = psmouse->private;
if (olpc_board_at_least(olpc_board(0xb2)))
if (psmouse->ps2dev.serio->dev.power.power_state.event !=
PM_EVENT_ON)
return 0;
priv->powered = 1;
return hgpk_reset_device(psmouse, false);
}
static ssize_t hgpk_show_powered(struct psmouse *psmouse, void *data, char *buf)
{
struct hgpk_data *priv = psmouse->private;
return sprintf(buf, "%d\n", priv->powered);
}
static ssize_t hgpk_set_powered(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
struct hgpk_data *priv = psmouse->private;
unsigned long value;
int err;
err = strict_strtoul(buf, 10, &value);
if (err || value > 1)
return -EINVAL;
if (value != priv->powered) {
err = hgpk_toggle_powersave(psmouse, value);
if (!err)
priv->powered = value;
}
return err ? err : count;
}
static ssize_t attr_show_mode(struct psmouse *psmouse, void *data, char *buf)
{
struct hgpk_data *priv = psmouse->private;
return sprintf(buf, "%s\n", hgpk_mode_names[priv->mode]);
}
static ssize_t attr_set_mode(struct psmouse *psmouse, void *data,
const char *buf, size_t len)
{
struct hgpk_data *priv = psmouse->private;
enum hgpk_mode old_mode = priv->mode;
enum hgpk_mode new_mode = hgpk_mode_from_name(buf, len);
struct input_dev *old_dev = psmouse->dev;
struct input_dev *new_dev;
int err;
if (new_mode == HGPK_MODE_INVALID)
return -EINVAL;
if (old_mode == new_mode)
return len;
new_dev = input_allocate_device();
if (!new_dev)
return -ENOMEM;
psmouse_set_state(psmouse, PSMOUSE_INITIALIZING);
priv->mode = new_mode;
err = hgpk_reset_device(psmouse, false);
if (err)
goto err_try_restore;
hgpk_setup_input_device(new_dev, old_dev, new_mode);
psmouse_set_state(psmouse, PSMOUSE_CMD_MODE);
err = input_register_device(new_dev);
if (err)
goto err_try_restore;
psmouse->dev = new_dev;
input_unregister_device(old_dev);
return len;
err_try_restore:
input_free_device(new_dev);
priv->mode = old_mode;
hgpk_reset_device(psmouse, false);
return err;
}
static ssize_t hgpk_trigger_recal_show(struct psmouse *psmouse,
void *data, char *buf)
{
return -EINVAL;
}
static ssize_t hgpk_trigger_recal(struct psmouse *psmouse, void *data,
const char *buf, size_t count)
{
struct hgpk_data *priv = psmouse->private;
unsigned long value;
int err;
err = strict_strtoul(buf, 10, &value);
if (err || value != 1)
return -EINVAL;
psmouse_queue_work(psmouse, &priv->recalib_wq, 0);
return count;
}
static void hgpk_disconnect(struct psmouse *psmouse)
{
struct hgpk_data *priv = psmouse->private;
device_remove_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_powered.dattr);
device_remove_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_hgpk_mode.dattr);
if (psmouse->model >= HGPK_MODEL_C)
device_remove_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_recalibrate.dattr);
psmouse_reset(psmouse);
kfree(priv);
}
static void hgpk_recalib_work(struct work_struct *work)
{
struct delayed_work *w = to_delayed_work(work);
struct hgpk_data *priv = container_of(w, struct hgpk_data, recalib_wq);
struct psmouse *psmouse = priv->psmouse;
if (hgpk_force_recalibrate(psmouse))
hgpk_err(psmouse, "recalibration failed!\n");
}
static int hgpk_register(struct psmouse *psmouse)
{
struct hgpk_data *priv = psmouse->private;
int err;
psmouse->protocol_handler = hgpk_process_byte;
psmouse->poll = hgpk_poll;
psmouse->disconnect = hgpk_disconnect;
psmouse->reconnect = hgpk_reconnect;
psmouse->resync_time = 0;
psmouse->resetafter = 1024;
hgpk_setup_input_device(psmouse->dev, NULL, priv->mode);
err = device_create_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_powered.dattr);
if (err) {
hgpk_err(psmouse, "Failed creating 'powered' sysfs node\n");
return err;
}
err = device_create_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_hgpk_mode.dattr);
if (err) {
hgpk_err(psmouse, "Failed creating 'hgpk_mode' sysfs node\n");
goto err_remove_powered;
}
if (psmouse->model >= HGPK_MODEL_C) {
err = device_create_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_recalibrate.dattr);
if (err) {
hgpk_err(psmouse,
"Failed creating 'recalibrate' sysfs node\n");
goto err_remove_mode;
}
}
return 0;
err_remove_mode:
device_remove_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_hgpk_mode.dattr);
err_remove_powered:
device_remove_file(&psmouse->ps2dev.serio->dev,
&psmouse_attr_powered.dattr);
return err;
}
int hgpk_init(struct psmouse *psmouse)
{
struct hgpk_data *priv;
int err;
priv = kzalloc(sizeof(struct hgpk_data), GFP_KERNEL);
if (!priv) {
err = -ENOMEM;
goto alloc_fail;
}
psmouse->private = priv;
priv->psmouse = psmouse;
priv->powered = true;
priv->mode = hgpk_default_mode;
INIT_DELAYED_WORK(&priv->recalib_wq, hgpk_recalib_work);
err = hgpk_reset_device(psmouse, false);
if (err)
goto init_fail;
err = hgpk_register(psmouse);
if (err)
goto init_fail;
return 0;
init_fail:
kfree(priv);
alloc_fail:
return err;
}
static enum hgpk_model_t hgpk_get_model(struct psmouse *psmouse)
{
struct ps2dev *ps2dev = &psmouse->ps2dev;
unsigned char param[3];
if (ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, NULL, PSMOUSE_CMD_SETSCALE21) ||
ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO)) {
return -EIO;
}
hgpk_dbg(psmouse, "ID: %02x %02x %02x\n", param[0], param[1], param[2]);
if (param[0] != 0x67 || param[1] != 0x00)
return -ENODEV;
hgpk_info(psmouse, "OLPC touchpad revision 0x%x\n", param[2]);
return param[2];
}
int hgpk_detect(struct psmouse *psmouse, bool set_properties)
{
int version;
version = hgpk_get_model(psmouse);
if (version < 0)
return version;
if (set_properties) {
psmouse->vendor = "ALPS";
psmouse->name = "HGPK";
psmouse->model = version;
}
return 0;
}
void hgpk_module_init(void)
{
hgpk_default_mode = hgpk_mode_from_name(hgpk_mode_name,
strlen(hgpk_mode_name));
if (hgpk_default_mode == HGPK_MODE_INVALID) {
hgpk_default_mode = HGPK_MODE_MOUSE;
strlcpy(hgpk_mode_name, hgpk_mode_names[HGPK_MODE_MOUSE],
sizeof(hgpk_mode_name));
}
}
