static int w1_ds2438_get_page(struct w1_slave *sl, int pageno, u8 *buf)
{
unsigned int retries = W1_DS2438_RETRIES;
u8 w1_buf[2];
u8 crc;
size_t count;
while (retries--) {
crc = 0;
if (w1_reset_select_slave(sl))
continue;
w1_buf[0] = W1_DS2438_RECALL_MEMORY;
w1_buf[1] = 0x00;
w1_write_block(sl->master, w1_buf, 2);
if (w1_reset_select_slave(sl))
continue;
w1_buf[0] = W1_DS2438_READ_SCRATCH;
w1_buf[1] = 0x00;
w1_write_block(sl->master, w1_buf, 2);
count = w1_read_block(sl->master, buf, DS2438_PAGE_SIZE + 1);
if (count == DS2438_PAGE_SIZE + 1) {
crc = w1_calc_crc8(buf, DS2438_PAGE_SIZE);
if ((u8)buf[DS2438_PAGE_SIZE] == crc)
return 0;
}
}
return -1;
}
static int w1_ds2438_get_temperature(struct w1_slave *sl, int16_t *temperature)
{
unsigned int retries = W1_DS2438_RETRIES;
u8 w1_buf[DS2438_PAGE_SIZE + 1 ];
unsigned int tm = DS2438_MAX_CONVERSION_TIME;
unsigned long sleep_rem;
int ret;
mutex_lock(&sl->master->bus_mutex);
while (retries--) {
if (w1_reset_select_slave(sl))
continue;
w1_write_8(sl->master, W1_DS2438_CONVERT_TEMP);
mutex_unlock(&sl->master->bus_mutex);
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0) {
ret = -1;
goto post_unlock;
}
if (mutex_lock_interruptible(&sl->master->bus_mutex) != 0) {
ret = -1;
goto post_unlock;
}
break;
}
if (w1_ds2438_get_page(sl, 0, w1_buf) == 0) {
*temperature = (((int16_t) w1_buf[DS2438_TEMP_MSB]) << 8) | ((uint16_t) w1_buf[DS2438_TEMP_LSB]);
ret = 0;
} else
ret = -1;
mutex_unlock(&sl->master->bus_mutex);
post_unlock:
return ret;
}
static int w1_ds2438_change_config_bit(struct w1_slave *sl, u8 mask, u8 value)
{
unsigned int retries = W1_DS2438_RETRIES;
u8 w1_buf[3];
u8 status;
int perform_write = 0;
while (retries--) {
if (w1_reset_select_slave(sl))
continue;
w1_buf[0] = W1_DS2438_RECALL_MEMORY;
w1_buf[1] = 0x00;
w1_write_block(sl->master, w1_buf, 2);
if (w1_reset_select_slave(sl))
continue;
w1_buf[0] = W1_DS2438_READ_SCRATCH;
w1_buf[1] = 0x00;
w1_write_block(sl->master, w1_buf, 2);
status = w1_read_8(sl->master);
if (value)
value = mask;
if ((status & mask) == value)
return 0;
else {
status ^= mask;
perform_write = 1;
}
break;
}
if (perform_write) {
retries = W1_DS2438_RETRIES;
while (retries--) {
if (w1_reset_select_slave(sl))
continue;
w1_buf[0] = W1_DS2438_WRITE_SCRATCH;
w1_buf[1] = 0x00;
w1_buf[2] = status;
w1_write_block(sl->master, w1_buf, 3);
if (w1_reset_select_slave(sl))
continue;
w1_buf[0] = W1_DS2438_COPY_SCRATCH;
w1_buf[1] = 0x00;
w1_write_block(sl->master, w1_buf, 2);
return 0;
}
}
return -1;
}
static uint16_t w1_ds2438_get_voltage(struct w1_slave *sl,
int adc_input, uint16_t *voltage)
{
unsigned int retries = W1_DS2438_RETRIES;
u8 w1_buf[DS2438_PAGE_SIZE + 1 ];
unsigned int tm = DS2438_MAX_CONVERSION_TIME;
unsigned long sleep_rem;
int ret;
mutex_lock(&sl->master->bus_mutex);
if (w1_ds2438_change_config_bit(sl, DS2438_STATUS_AD, adc_input)) {
ret = -1;
goto pre_unlock;
}
while (retries--) {
if (w1_reset_select_slave(sl))
continue;
w1_write_8(sl->master, W1_DS2438_CONVERT_VOLTAGE);
mutex_unlock(&sl->master->bus_mutex);
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0) {
ret = -1;
goto post_unlock;
}
if (mutex_lock_interruptible(&sl->master->bus_mutex) != 0) {
ret = -1;
goto post_unlock;
}
break;
}
if (w1_ds2438_get_page(sl, 0, w1_buf) == 0) {
*voltage = (((uint16_t) w1_buf[DS2438_VOLTAGE_MSB]) << 8) | ((uint16_t) w1_buf[DS2438_VOLTAGE_LSB]);
ret = 0;
} else
ret = -1;
pre_unlock:
mutex_unlock(&sl->master->bus_mutex);
post_unlock:
return ret;
}
static ssize_t iad_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int ret;
if (count != 1 || off != 0)
return -EFAULT;
mutex_lock(&sl->master->bus_mutex);
if (w1_ds2438_change_config_bit(sl, DS2438_STATUS_IAD, *buf & 0x01) == 0)
ret = 1;
else
ret = -EIO;
mutex_unlock(&sl->master->bus_mutex);
return ret;
}
static ssize_t page0_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int ret;
u8 w1_buf[DS2438_PAGE_SIZE + 1 ];
if (off != 0)
return 0;
if (!buf)
return -EINVAL;
mutex_lock(&sl->master->bus_mutex);
if (w1_ds2438_get_page(sl, 0, w1_buf) == 0) {
memcpy(buf, &w1_buf, DS2438_PAGE_SIZE);
ret = DS2438_PAGE_SIZE;
} else
ret = -EIO;
mutex_unlock(&sl->master->bus_mutex);
return ret;
}
static ssize_t temperature_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int ret;
ssize_t c = PAGE_SIZE;
int16_t temp;
if (off != 0)
return 0;
if (!buf)
return -EINVAL;
if (w1_ds2438_get_temperature(sl, &temp) == 0) {
c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", temp);
ret = PAGE_SIZE - c;
} else
ret = -EIO;
return ret;
}
static ssize_t vad_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int ret;
ssize_t c = PAGE_SIZE;
uint16_t voltage;
if (off != 0)
return 0;
if (!buf)
return -EINVAL;
if (w1_ds2438_get_voltage(sl, DS2438_ADC_INPUT_VAD, &voltage) == 0) {
c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", voltage);
ret = PAGE_SIZE - c;
} else
ret = -EIO;
return ret;
}
static ssize_t vdd_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct w1_slave *sl = kobj_to_w1_slave(kobj);
int ret;
ssize_t c = PAGE_SIZE;
uint16_t voltage;
if (off != 0)
return 0;
if (!buf)
return -EINVAL;
if (w1_ds2438_get_voltage(sl, DS2438_ADC_INPUT_VDD, &voltage) == 0) {
c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", voltage);
ret = PAGE_SIZE - c;
} else
ret = -EIO;
return ret;
}
