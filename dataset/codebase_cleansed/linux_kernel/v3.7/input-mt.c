static void copy_abs(struct input_dev *dev, unsigned int dst, unsigned int src)
{
if (dev->absinfo && test_bit(src, dev->absbit)) {
dev->absinfo[dst] = dev->absinfo[src];
dev->absbit[BIT_WORD(dst)] |= BIT_MASK(dst);
}
}
int input_mt_init_slots(struct input_dev *dev, unsigned int num_slots,
unsigned int flags)
{
struct input_mt *mt = dev->mt;
int i;
if (!num_slots)
return 0;
if (mt)
return mt->num_slots != num_slots ? -EINVAL : 0;
mt = kzalloc(sizeof(*mt) + num_slots * sizeof(*mt->slots), GFP_KERNEL);
if (!mt)
goto err_mem;
mt->num_slots = num_slots;
mt->flags = flags;
input_set_abs_params(dev, ABS_MT_SLOT, 0, num_slots - 1, 0, 0);
input_set_abs_params(dev, ABS_MT_TRACKING_ID, 0, TRKID_MAX, 0, 0);
if (flags & (INPUT_MT_POINTER | INPUT_MT_DIRECT)) {
__set_bit(EV_KEY, dev->evbit);
__set_bit(BTN_TOUCH, dev->keybit);
copy_abs(dev, ABS_X, ABS_MT_POSITION_X);
copy_abs(dev, ABS_Y, ABS_MT_POSITION_Y);
copy_abs(dev, ABS_PRESSURE, ABS_MT_PRESSURE);
}
if (flags & INPUT_MT_POINTER) {
__set_bit(BTN_TOOL_FINGER, dev->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, dev->keybit);
if (num_slots >= 3)
__set_bit(BTN_TOOL_TRIPLETAP, dev->keybit);
if (num_slots >= 4)
__set_bit(BTN_TOOL_QUADTAP, dev->keybit);
if (num_slots >= 5)
__set_bit(BTN_TOOL_QUINTTAP, dev->keybit);
__set_bit(INPUT_PROP_POINTER, dev->propbit);
}
if (flags & INPUT_MT_DIRECT)
__set_bit(INPUT_PROP_DIRECT, dev->propbit);
if (flags & INPUT_MT_TRACK) {
unsigned int n2 = num_slots * num_slots;
mt->red = kcalloc(n2, sizeof(*mt->red), GFP_KERNEL);
if (!mt->red)
goto err_mem;
}
for (i = 0; i < num_slots; i++)
input_mt_set_value(&mt->slots[i], ABS_MT_TRACKING_ID, -1);
dev->mt = mt;
return 0;
err_mem:
kfree(mt);
return -ENOMEM;
}
void input_mt_destroy_slots(struct input_dev *dev)
{
if (dev->mt) {
kfree(dev->mt->red);
kfree(dev->mt);
}
dev->mt = NULL;
}
void input_mt_report_slot_state(struct input_dev *dev,
unsigned int tool_type, bool active)
{
struct input_mt *mt = dev->mt;
struct input_mt_slot *slot;
int id;
if (!mt)
return;
slot = &mt->slots[mt->slot];
slot->frame = mt->frame;
if (!active) {
input_event(dev, EV_ABS, ABS_MT_TRACKING_ID, -1);
return;
}
id = input_mt_get_value(slot, ABS_MT_TRACKING_ID);
if (id < 0 || input_mt_get_value(slot, ABS_MT_TOOL_TYPE) != tool_type)
id = input_mt_new_trkid(mt);
input_event(dev, EV_ABS, ABS_MT_TRACKING_ID, id);
input_event(dev, EV_ABS, ABS_MT_TOOL_TYPE, tool_type);
}
void input_mt_report_finger_count(struct input_dev *dev, int count)
{
input_event(dev, EV_KEY, BTN_TOOL_FINGER, count == 1);
input_event(dev, EV_KEY, BTN_TOOL_DOUBLETAP, count == 2);
input_event(dev, EV_KEY, BTN_TOOL_TRIPLETAP, count == 3);
input_event(dev, EV_KEY, BTN_TOOL_QUADTAP, count == 4);
input_event(dev, EV_KEY, BTN_TOOL_QUINTTAP, count == 5);
}
void input_mt_report_pointer_emulation(struct input_dev *dev, bool use_count)
{
struct input_mt *mt = dev->mt;
struct input_mt_slot *oldest;
int oldid, count, i;
if (!mt)
return;
oldest = 0;
oldid = mt->trkid;
count = 0;
for (i = 0; i < mt->num_slots; ++i) {
struct input_mt_slot *ps = &mt->slots[i];
int id = input_mt_get_value(ps, ABS_MT_TRACKING_ID);
if (id < 0)
continue;
if ((id - oldid) & TRKID_SGN) {
oldest = ps;
oldid = id;
}
count++;
}
input_event(dev, EV_KEY, BTN_TOUCH, count > 0);
if (use_count)
input_mt_report_finger_count(dev, count);
if (oldest) {
int x = input_mt_get_value(oldest, ABS_MT_POSITION_X);
int y = input_mt_get_value(oldest, ABS_MT_POSITION_Y);
input_event(dev, EV_ABS, ABS_X, x);
input_event(dev, EV_ABS, ABS_Y, y);
if (test_bit(ABS_MT_PRESSURE, dev->absbit)) {
int p = input_mt_get_value(oldest, ABS_MT_PRESSURE);
input_event(dev, EV_ABS, ABS_PRESSURE, p);
}
} else {
if (test_bit(ABS_MT_PRESSURE, dev->absbit))
input_event(dev, EV_ABS, ABS_PRESSURE, 0);
}
}
void input_mt_sync_frame(struct input_dev *dev)
{
struct input_mt *mt = dev->mt;
struct input_mt_slot *s;
if (!mt)
return;
if (mt->flags & INPUT_MT_DROP_UNUSED) {
for (s = mt->slots; s != mt->slots + mt->num_slots; s++) {
if (s->frame == mt->frame)
continue;
input_mt_slot(dev, s - mt->slots);
input_event(dev, EV_ABS, ABS_MT_TRACKING_ID, -1);
}
}
input_mt_report_pointer_emulation(dev, (mt->flags & INPUT_MT_POINTER));
mt->frame++;
}
static int adjust_dual(int *begin, int step, int *end, int eq)
{
int f, *p, s, c;
if (begin == end)
return 0;
f = *begin;
p = begin + step;
s = p == end ? f + 1 : *p;
for (; p != end; p += step)
if (*p < f)
s = f, f = *p;
else if (*p < s)
s = *p;
c = (f + s + 1) / 2;
if (c == 0 || (c > 0 && !eq))
return 0;
if (s < 0)
c *= 2;
for (p = begin; p != end; p += step)
*p -= c;
return (c < s && s <= 0) || (f >= 0 && f < c);
}
static void find_reduced_matrix(int *w, int nr, int nc, int nrc)
{
int i, k, sum;
for (k = 0; k < nrc; k++) {
for (i = 0; i < nr; i++)
adjust_dual(w + i, nr, w + i + nrc, nr <= nc);
sum = 0;
for (i = 0; i < nrc; i += nr)
sum += adjust_dual(w + i, 1, w + i + nr, nc <= nr);
if (!sum)
break;
}
}
static int input_mt_set_matrix(struct input_mt *mt,
const struct input_mt_pos *pos, int num_pos)
{
const struct input_mt_pos *p;
struct input_mt_slot *s;
int *w = mt->red;
int x, y;
for (s = mt->slots; s != mt->slots + mt->num_slots; s++) {
if (!input_mt_is_active(s))
continue;
x = input_mt_get_value(s, ABS_MT_POSITION_X);
y = input_mt_get_value(s, ABS_MT_POSITION_Y);
for (p = pos; p != pos + num_pos; p++) {
int dx = x - p->x, dy = y - p->y;
*w++ = dx * dx + dy * dy;
}
}
return w - mt->red;
}
static void input_mt_set_slots(struct input_mt *mt,
int *slots, int num_pos)
{
struct input_mt_slot *s;
int *w = mt->red, *p;
for (p = slots; p != slots + num_pos; p++)
*p = -1;
for (s = mt->slots; s != mt->slots + mt->num_slots; s++) {
if (!input_mt_is_active(s))
continue;
for (p = slots; p != slots + num_pos; p++)
if (*w++ < 0)
*p = s - mt->slots;
}
for (s = mt->slots; s != mt->slots + mt->num_slots; s++) {
if (input_mt_is_active(s))
continue;
for (p = slots; p != slots + num_pos; p++)
if (*p < 0) {
*p = s - mt->slots;
break;
}
}
}
int input_mt_assign_slots(struct input_dev *dev, int *slots,
const struct input_mt_pos *pos, int num_pos)
{
struct input_mt *mt = dev->mt;
int nrc;
if (!mt || !mt->red)
return -ENXIO;
if (num_pos > mt->num_slots)
return -EINVAL;
if (num_pos < 1)
return 0;
nrc = input_mt_set_matrix(mt, pos, num_pos);
find_reduced_matrix(mt->red, num_pos, nrc / num_pos, nrc);
input_mt_set_slots(mt, slots, num_pos);
return 0;
}
int input_mt_get_slot_by_key(struct input_dev *dev, int key)
{
struct input_mt *mt = dev->mt;
struct input_mt_slot *s;
if (!mt)
return -1;
for (s = mt->slots; s != mt->slots + mt->num_slots; s++)
if (input_mt_is_active(s) && s->key == key)
return s - mt->slots;
for (s = mt->slots; s != mt->slots + mt->num_slots; s++)
if (!input_mt_is_active(s)) {
s->key = key;
return s - mt->slots;
}
return -1;
}
