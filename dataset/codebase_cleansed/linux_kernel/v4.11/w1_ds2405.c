static int w1_ds2405_select(struct w1_slave *sl, bool only_active)
{
struct w1_master *dev = sl->master;
u64 dev_addr = le64_to_cpu(*(u64 *)&sl->reg_num);
unsigned int bit_ctr;
if (w1_reset_bus(dev) != 0)
return 0;
w1_write_8(dev, only_active ? W1_ALARM_SEARCH : W1_SEARCH);
for (bit_ctr = 0; bit_ctr < 64; bit_ctr++) {
int bit2send = !!(dev_addr & BIT(bit_ctr));
u8 ret;
ret = w1_triplet(dev, bit2send);
if ((ret & (BIT(0) | BIT(1))) ==
(BIT(0) | BIT(1)))
return 0;
if (!!(ret & BIT(2)) != bit2send)
return 0;
}
return 1;
}
static int w1_ds2405_read_pio(struct w1_slave *sl)
{
if (w1_ds2405_select(sl, true))
return 0;
if (w1_ds2405_select(sl, false))
return 1;
return -ENODEV;
}
static ssize_t state_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
int ret;
ssize_t f_retval;
u8 state;
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret)
return ret;
if (!w1_ds2405_select(sl, false)) {
f_retval = -ENODEV;
goto out_unlock;
}
state = w1_read_8(dev);
if (state != 0 &&
state != 0xff) {
dev_err(device, "non-consistent state %x\n", state);
f_retval = -EIO;
goto out_unlock;
}
*buf = state ? '1' : '0';
f_retval = 1;
out_unlock:
w1_reset_bus(dev);
mutex_unlock(&dev->bus_mutex);
return f_retval;
}
static ssize_t output_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
int ret;
ssize_t f_retval;
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret)
return ret;
ret = w1_ds2405_read_pio(sl);
if (ret < 0) {
f_retval = ret;
goto out_unlock;
}
*buf = ret ? '1' : '0';
f_retval = 1;
out_unlock:
w1_reset_bus(dev);
mutex_unlock(&dev->bus_mutex);
return f_retval;
}
static ssize_t output_store(struct device *device,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
int ret, current_pio;
unsigned int val;
ssize_t f_retval;
if (count < 1)
return -EINVAL;
if (sscanf(buf, " %u%n", &val, &ret) < 1)
return -EINVAL;
if (val != 0 && val != 1)
return -EINVAL;
f_retval = ret;
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret)
return ret;
current_pio = w1_ds2405_read_pio(sl);
if (current_pio < 0) {
f_retval = current_pio;
goto out_unlock;
}
if (current_pio == val)
goto out_unlock;
if (w1_reset_bus(dev) != 0) {
f_retval = -ENODEV;
goto out_unlock;
}
do {
u64 dev_addr = le64_to_cpu(*(u64 *)&sl->reg_num);
u8 cmd[9];
cmd[0] = W1_MATCH_ROM;
memcpy(&cmd[1], &dev_addr, sizeof(dev_addr));
w1_write_block(dev, cmd, sizeof(cmd));
} while (0);
out_unlock:
w1_reset_bus(dev);
mutex_unlock(&dev->bus_mutex);
return f_retval;
}
