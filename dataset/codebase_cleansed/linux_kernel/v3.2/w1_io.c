static void w1_delay(unsigned long tm)
{
udelay(tm * w1_delay_parm);
}
static u8 w1_touch_bit(struct w1_master *dev, int bit)
{
if (dev->bus_master->touch_bit)
return dev->bus_master->touch_bit(dev->bus_master->data, bit);
else if (bit)
return w1_read_bit(dev);
else {
w1_write_bit(dev, 0);
return 0;
}
}
static void w1_write_bit(struct w1_master *dev, int bit)
{
if (bit) {
dev->bus_master->write_bit(dev->bus_master->data, 0);
w1_delay(6);
dev->bus_master->write_bit(dev->bus_master->data, 1);
w1_delay(64);
} else {
dev->bus_master->write_bit(dev->bus_master->data, 0);
w1_delay(60);
dev->bus_master->write_bit(dev->bus_master->data, 1);
w1_delay(10);
}
}
static void w1_pre_write(struct w1_master *dev)
{
if (dev->pullup_duration &&
dev->enable_pullup && dev->bus_master->set_pullup) {
dev->bus_master->set_pullup(dev->bus_master->data,
dev->pullup_duration);
}
}
static void w1_post_write(struct w1_master *dev)
{
if (dev->pullup_duration) {
if (dev->enable_pullup && dev->bus_master->set_pullup)
dev->bus_master->set_pullup(dev->bus_master->data, 0);
else
msleep(dev->pullup_duration);
dev->pullup_duration = 0;
}
}
void w1_write_8(struct w1_master *dev, u8 byte)
{
int i;
if (dev->bus_master->write_byte) {
w1_pre_write(dev);
dev->bus_master->write_byte(dev->bus_master->data, byte);
}
else
for (i = 0; i < 8; ++i) {
if (i == 7)
w1_pre_write(dev);
w1_touch_bit(dev, (byte >> i) & 0x1);
}
w1_post_write(dev);
}
static u8 w1_read_bit(struct w1_master *dev)
{
int result;
unsigned long flags;
local_irq_save(flags);
dev->bus_master->write_bit(dev->bus_master->data, 0);
w1_delay(6);
dev->bus_master->write_bit(dev->bus_master->data, 1);
w1_delay(9);
result = dev->bus_master->read_bit(dev->bus_master->data);
local_irq_restore(flags);
w1_delay(55);
return result & 0x1;
}
u8 w1_triplet(struct w1_master *dev, int bdir)
{
if (dev->bus_master->triplet)
return dev->bus_master->triplet(dev->bus_master->data, bdir);
else {
u8 id_bit = w1_touch_bit(dev, 1);
u8 comp_bit = w1_touch_bit(dev, 1);
u8 retval;
if (id_bit && comp_bit)
return 0x03;
if (!id_bit && !comp_bit) {
retval = bdir ? 0x04 : 0;
} else {
bdir = id_bit;
retval = id_bit ? 0x05 : 0x02;
}
if (dev->bus_master->touch_bit)
w1_touch_bit(dev, bdir);
else
w1_write_bit(dev, bdir);
return retval;
}
}
u8 w1_read_8(struct w1_master *dev)
{
int i;
u8 res = 0;
if (dev->bus_master->read_byte)
res = dev->bus_master->read_byte(dev->bus_master->data);
else
for (i = 0; i < 8; ++i)
res |= (w1_touch_bit(dev,1) << i);
return res;
}
void w1_write_block(struct w1_master *dev, const u8 *buf, int len)
{
int i;
if (dev->bus_master->write_block) {
w1_pre_write(dev);
dev->bus_master->write_block(dev->bus_master->data, buf, len);
}
else
for (i = 0; i < len; ++i)
w1_write_8(dev, buf[i]);
w1_post_write(dev);
}
void w1_touch_block(struct w1_master *dev, u8 *buf, int len)
{
int i, j;
u8 tmp;
for (i = 0; i < len; ++i) {
tmp = 0;
for (j = 0; j < 8; ++j) {
if (j == 7)
w1_pre_write(dev);
tmp |= w1_touch_bit(dev, (buf[i] >> j) & 0x1) << j;
}
buf[i] = tmp;
}
}
u8 w1_read_block(struct w1_master *dev, u8 *buf, int len)
{
int i;
u8 ret;
if (dev->bus_master->read_block)
ret = dev->bus_master->read_block(dev->bus_master->data, buf, len);
else {
for (i = 0; i < len; ++i)
buf[i] = w1_read_8(dev);
ret = len;
}
return ret;
}
int w1_reset_bus(struct w1_master *dev)
{
int result;
if (dev->bus_master->reset_bus)
result = dev->bus_master->reset_bus(dev->bus_master->data) & 0x1;
else {
dev->bus_master->write_bit(dev->bus_master->data, 0);
w1_delay(480);
dev->bus_master->write_bit(dev->bus_master->data, 1);
w1_delay(70);
result = dev->bus_master->read_bit(dev->bus_master->data) & 0x1;
msleep(1);
}
return result;
}
u8 w1_calc_crc8(u8 * data, int len)
{
u8 crc = 0;
while (len--)
crc = w1_crc8_table[crc ^ *data++];
return crc;
}
void w1_search_devices(struct w1_master *dev, u8 search_type, w1_slave_found_callback cb)
{
dev->attempts++;
if (dev->bus_master->search)
dev->bus_master->search(dev->bus_master->data, dev,
search_type, cb);
else
w1_search(dev, search_type, cb);
}
int w1_reset_select_slave(struct w1_slave *sl)
{
if (w1_reset_bus(sl->master))
return -1;
if (sl->master->slave_count == 1)
w1_write_8(sl->master, W1_SKIP_ROM);
else {
u8 match[9] = {W1_MATCH_ROM, };
u64 rn = le64_to_cpu(*((u64*)&sl->reg_num));
memcpy(&match[1], &rn, 8);
w1_write_block(sl->master, match, 9);
}
return 0;
}
int w1_reset_resume_command(struct w1_master *dev)
{
if (w1_reset_bus(dev))
return -1;
w1_write_8(dev, W1_RESUME_CMD);
return 0;
}
void w1_next_pullup(struct w1_master *dev, int delay)
{
dev->pullup_duration = delay;
}
