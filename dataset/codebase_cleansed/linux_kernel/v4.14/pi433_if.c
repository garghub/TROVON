static irqreturn_t DIO0_irq_handler(int irq, void *dev_id)
{
struct pi433_device *device = dev_id;
if (device->irq_state[DIO0] == DIO_PacketSent)
{
device->free_in_fifo = FIFO_SIZE;
printk("DIO0 irq: Packet sent\n");
wake_up_interruptible(&device->fifo_wait_queue);
}
else if (device->irq_state[DIO0] == DIO_Rssi_DIO0)
{
printk("DIO0 irq: RSSI level over threshold\n");
wake_up_interruptible(&device->rx_wait_queue);
}
else if (device->irq_state[DIO0] == DIO_PayloadReady)
{
printk("DIO0 irq: PayloadReady\n");
device->free_in_fifo = 0;
wake_up_interruptible(&device->fifo_wait_queue);
}
return IRQ_HANDLED;
}
static irqreturn_t DIO1_irq_handler(int irq, void *dev_id)
{
struct pi433_device *device = dev_id;
if (device->irq_state[DIO1] == DIO_FifoNotEmpty_DIO1)
{
device->free_in_fifo = FIFO_SIZE;
}
else if (device->irq_state[DIO1] == DIO_FifoLevel)
{
if (device->rx_active) device->free_in_fifo = FIFO_THRESHOLD - 1;
else device->free_in_fifo = FIFO_SIZE - FIFO_THRESHOLD - 1;
}
printk("DIO1 irq: %d bytes free in fifo\n", device->free_in_fifo);
wake_up_interruptible(&device->fifo_wait_queue);
return IRQ_HANDLED;
}
static int
rf69_set_rx_cfg(struct pi433_device *dev, struct pi433_rx_cfg *rx_cfg)
{
int ret;
int payload_length;
SET_CHECKED(rf69_set_frequency (dev->spi, rx_cfg->frequency));
SET_CHECKED(rf69_set_bit_rate (dev->spi, rx_cfg->bit_rate));
SET_CHECKED(rf69_set_modulation (dev->spi, rx_cfg->modulation));
SET_CHECKED(rf69_set_antenna_impedance (dev->spi, rx_cfg->antenna_impedance));
SET_CHECKED(rf69_set_rssi_threshold (dev->spi, rx_cfg->rssi_threshold));
SET_CHECKED(rf69_set_ook_threshold_dec (dev->spi, rx_cfg->thresholdDecrement));
SET_CHECKED(rf69_set_bandwidth (dev->spi, rx_cfg->bw_mantisse, rx_cfg->bw_exponent));
SET_CHECKED(rf69_set_bandwidth_during_afc(dev->spi, rx_cfg->bw_mantisse, rx_cfg->bw_exponent));
SET_CHECKED(rf69_set_dagc (dev->spi, rx_cfg->dagc));
dev->rx_bytes_to_drop = rx_cfg->bytes_to_drop;
SET_CHECKED(rf69_set_sync_enable(dev->spi, rx_cfg->enable_sync));
if (rx_cfg->enable_sync == optionOn)
{
SET_CHECKED(rf69_set_fifo_fill_condition(dev->spi, afterSyncInterrupt));
}
else
{
SET_CHECKED(rf69_set_fifo_fill_condition(dev->spi, always));
}
if (rx_cfg->enable_length_byte == optionOn) {
ret = rf69_set_packet_format(dev->spi, packetLengthVar);
if (ret < 0)
return ret;
} else {
ret = rf69_set_packet_format(dev->spi, packetLengthFix);
if (ret < 0)
return ret;
}
SET_CHECKED(rf69_set_adressFiltering(dev->spi, rx_cfg->enable_address_filtering));
SET_CHECKED(rf69_set_crc_enable (dev->spi, rx_cfg->enable_crc));
SET_CHECKED(rf69_set_sync_size(dev->spi, rx_cfg->sync_length));
if (rx_cfg->enable_length_byte == optionOn)
{
SET_CHECKED(rf69_set_payload_length(dev->spi, 0xff));
}
else if (rx_cfg->fixed_message_length != 0)
{
payload_length = rx_cfg->fixed_message_length;
if (rx_cfg->enable_length_byte == optionOn) payload_length++;
if (rx_cfg->enable_address_filtering != filteringOff) payload_length++;
SET_CHECKED(rf69_set_payload_length(dev->spi, payload_length));
}
else
{
SET_CHECKED(rf69_set_payload_length(dev->spi, 0));
}
if (rx_cfg->enable_sync == optionOn)
{
SET_CHECKED(rf69_set_sync_values(dev->spi, rx_cfg->sync_pattern));
}
if (rx_cfg->enable_address_filtering != filteringOff)
{
SET_CHECKED(rf69_set_node_address (dev->spi, rx_cfg->node_address));
SET_CHECKED(rf69_set_broadcast_address(dev->spi, rx_cfg->broadcast_address));
}
return 0;
}
static int
rf69_set_tx_cfg(struct pi433_device *dev, struct pi433_tx_cfg *tx_cfg)
{
int ret;
SET_CHECKED(rf69_set_frequency (dev->spi, tx_cfg->frequency));
SET_CHECKED(rf69_set_bit_rate (dev->spi, tx_cfg->bit_rate));
SET_CHECKED(rf69_set_modulation (dev->spi, tx_cfg->modulation));
SET_CHECKED(rf69_set_deviation (dev->spi, tx_cfg->dev_frequency));
SET_CHECKED(rf69_set_pa_ramp (dev->spi, tx_cfg->pa_ramp));
SET_CHECKED(rf69_set_modulation_shaping(dev->spi, tx_cfg->modShaping));
SET_CHECKED(rf69_set_tx_start_condition(dev->spi, tx_cfg->tx_start_condition));
if (tx_cfg->enable_preamble == optionOn)
{
SET_CHECKED(rf69_set_preamble_length(dev->spi, tx_cfg->preamble_length));
}
else
{
SET_CHECKED(rf69_set_preamble_length(dev->spi, 0));
}
SET_CHECKED(rf69_set_sync_enable (dev->spi, tx_cfg->enable_sync));
if (tx_cfg->enable_length_byte == optionOn) {
ret = rf69_set_packet_format(dev->spi, packetLengthVar);
if (ret < 0)
return ret;
} else {
ret = rf69_set_packet_format(dev->spi, packetLengthFix);
if (ret < 0)
return ret;
}
SET_CHECKED(rf69_set_crc_enable (dev->spi, tx_cfg->enable_crc));
if (tx_cfg->enable_sync == optionOn)
{
SET_CHECKED(rf69_set_sync_size(dev->spi, tx_cfg->sync_length));
SET_CHECKED(rf69_set_sync_values(dev->spi, tx_cfg->sync_pattern));
}
return 0;
}
static int
pi433_start_rx(struct pi433_device *dev)
{
int retval;
if (!dev->rx_active)
return 0;
retval = rf69_set_rx_cfg(dev, &dev->rx_cfg);
if (retval) return retval;
SET_CHECKED(rf69_set_dio_mapping(dev->spi, DIO0, DIO_Rssi_DIO0));
dev->irq_state[DIO0] = DIO_Rssi_DIO0;
irq_set_irq_type(dev->irq_num[DIO0], IRQ_TYPE_EDGE_RISING);
SET_CHECKED(rf69_set_fifo_threshold(dev->spi, FIFO_SIZE - FIFO_THRESHOLD));
SET_CHECKED(rf69_set_dio_mapping(dev->spi, DIO1, DIO_FifoLevel));
dev->irq_state[DIO1] = DIO_FifoLevel;
irq_set_irq_type(dev->irq_num[DIO1], IRQ_TYPE_EDGE_RISING);
SET_CHECKED(rf69_set_mode(dev->spi, receive));
return 0;
}
static int
pi433_receive(void *data)
{
struct pi433_device *dev = data;
struct spi_device *spi = dev->spi;
int bytes_to_read, bytes_total;
int retval;
dev->interrupt_rx_allowed = false;
dev_dbg(dev->dev,"rx: going to wait for any tx to finish");
retval = wait_event_interruptible(dev->rx_wait_queue, !dev->tx_active);
if(retval)
{
dev->interrupt_rx_allowed = true;
wake_up_interruptible(&dev->tx_wait_queue);
return retval;
}
dev->free_in_fifo = FIFO_SIZE;
dev->rx_position = 0;
dev->rx_bytes_dropped = 0;
retval = pi433_start_rx(dev);
if (retval)
return retval;
while ( !rf69_get_flag(dev->spi, rssiExceededThreshold) )
{
dev->interrupt_rx_allowed = true;
wake_up_interruptible(&dev->tx_wait_queue);
dev_dbg(dev->dev, "rx: going to wait for high RSSI level");
retval = wait_event_interruptible(dev->rx_wait_queue,
rf69_get_flag(dev->spi,
rssiExceededThreshold));
if (retval) goto abort;
dev->interrupt_rx_allowed = false;
if (!dev->tx_active) break;
}
SET_CHECKED(rf69_set_dio_mapping(spi, DIO0, DIO_PayloadReady));
dev->irq_state[DIO0] = DIO_PayloadReady;
irq_set_irq_type(dev->irq_num[DIO0], IRQ_TYPE_EDGE_RISING);
if (dev->rx_cfg.fixed_message_length != 0)
{
if (dev->rx_cfg.fixed_message_length > dev->rx_buffer_size)
{
retval = -1;
goto abort;
}
bytes_total = dev->rx_cfg.fixed_message_length;
dev_dbg(dev->dev,"rx: msg len set to %d by fixed length", bytes_total);
}
else
{
bytes_total = dev->rx_buffer_size;
dev_dbg(dev->dev, "rx: msg len set to %d as requested by read", bytes_total);
}
if (dev->rx_cfg.enable_length_byte == optionOn)
{
retval = wait_event_interruptible(dev->fifo_wait_queue,
dev->free_in_fifo < FIFO_SIZE);
if (retval) goto abort;
rf69_read_fifo(spi, (u8 *)&bytes_total, 1);
if (bytes_total > dev->rx_buffer_size)
{
retval = -1;
goto abort;
}
dev->free_in_fifo++;
dev_dbg(dev->dev, "rx: msg len reset to %d due to length byte", bytes_total);
}
if (dev->rx_cfg.enable_address_filtering != filteringOff)
{
u8 dummy;
bytes_total--;
retval = wait_event_interruptible(dev->fifo_wait_queue,
dev->free_in_fifo < FIFO_SIZE);
if (retval) goto abort;
rf69_read_fifo(spi, &dummy, 1);
dev->free_in_fifo++;
dev_dbg(dev->dev, "rx: address byte stripped off");
}
while (dev->rx_position < bytes_total)
{
if ( !rf69_get_flag(dev->spi, payloadReady) )
{
retval = wait_event_interruptible(dev->fifo_wait_queue,
dev->free_in_fifo < FIFO_SIZE);
if (retval) goto abort;
}
if (dev->rx_bytes_to_drop > dev->rx_bytes_dropped)
bytes_to_read = dev->rx_bytes_to_drop - dev->rx_bytes_dropped;
else
bytes_to_read = bytes_total - dev->rx_position;
if (bytes_to_read > FIFO_SIZE - dev->free_in_fifo)
bytes_to_read = FIFO_SIZE - dev->free_in_fifo;
retval = rf69_read_fifo(spi,
&dev->rx_buffer[dev->rx_position],
bytes_to_read);
if (retval) goto abort;
dev->free_in_fifo += bytes_to_read;
if (dev->rx_bytes_to_drop > dev->rx_bytes_dropped)
dev->rx_bytes_dropped += bytes_to_read;
else
dev->rx_position += bytes_to_read;
}
abort:
dev->interrupt_rx_allowed = true;
SET_CHECKED(rf69_set_mode(dev->spi, standby));
wake_up_interruptible(&dev->tx_wait_queue);
if (retval)
return retval;
else
return bytes_total;
}
static int
pi433_tx_thread(void *data)
{
struct pi433_device *device = data;
struct spi_device *spi = device->spi;
struct pi433_tx_cfg tx_cfg;
u8 *buffer = device->buffer;
size_t size;
bool rx_interrupted = false;
int position, repetitions;
int retval;
while (1)
{
dev_dbg(device->dev, "thread: going to wait for new messages");
wait_event_interruptible(device->tx_wait_queue,
( !kfifo_is_empty(&device->tx_fifo) ||
kthread_should_stop() ));
if ( kthread_should_stop() )
return 0;
mutex_lock(&device->tx_fifo_lock);
retval = kfifo_out(&device->tx_fifo, &tx_cfg, sizeof(tx_cfg));
if (retval != sizeof(tx_cfg))
{
dev_dbg(device->dev, "reading tx_cfg from fifo failed: got %d byte(s), expected %d", retval, (unsigned int)sizeof(tx_cfg) );
mutex_unlock(&device->tx_fifo_lock);
continue;
}
retval = kfifo_out(&device->tx_fifo, &size, sizeof(size_t));
if (retval != sizeof(size_t))
{
dev_dbg(device->dev, "reading msg size from fifo failed: got %d, expected %d", retval, (unsigned int)sizeof(size_t) );
mutex_unlock(&device->tx_fifo_lock);
continue;
}
if (tx_cfg.fixed_message_length != 0)
size = tx_cfg.fixed_message_length;
if (tx_cfg.enable_length_byte == optionOn)
size++;
if (tx_cfg.enable_address_byte == optionOn)
size++;
memset(buffer, 0, size);
position = 0;
if (tx_cfg.enable_length_byte == optionOn)
buffer[position++] = size-1;
if (tx_cfg.enable_address_byte == optionOn)
buffer[position++] = tx_cfg.address_byte;
retval = kfifo_out(&device->tx_fifo, &buffer[position], sizeof(buffer)-position );
dev_dbg(device->dev, "read %d message byte(s) from fifo queue.", retval);
mutex_unlock(&device->tx_fifo_lock);
wait_event_interruptible(device->tx_wait_queue,
!device->rx_active ||
device->interrupt_rx_allowed == true);
disable_irq(device->irq_num[DIO0]);
device->tx_active = true;
if (device->rx_active && rx_interrupted == false)
{
SET_CHECKED(rf69_set_mode(device->spi, standby));
rx_interrupted = true;
}
SET_CHECKED(rf69_set_mode(spi, standby));
SET_CHECKED(rf69_set_fifo_threshold(spi, FIFO_THRESHOLD));
if (tx_cfg.enable_length_byte == optionOn)
{
SET_CHECKED(rf69_set_payload_length(spi, size * tx_cfg.repetitions));
}
else
{
SET_CHECKED(rf69_set_payload_length(spi, 0));
}
rf69_set_tx_cfg(device, &tx_cfg);
SET_CHECKED(rf69_set_dio_mapping(spi, DIO1, DIO_FifoLevel));
device->irq_state[DIO1] = DIO_FifoLevel;
irq_set_irq_type(device->irq_num[DIO1], IRQ_TYPE_EDGE_FALLING);
SET_CHECKED(rf69_set_dio_mapping(spi, DIO0, DIO_PacketSent));
device->irq_state[DIO0] = DIO_PacketSent;
irq_set_irq_type(device->irq_num[DIO0], IRQ_TYPE_EDGE_RISING);
enable_irq(device->irq_num[DIO0]);
SET_CHECKED(rf69_set_mode(spi, transmit));
device->free_in_fifo = FIFO_SIZE;
position = 0;
repetitions = tx_cfg.repetitions;
while( (repetitions > 0) && (size > position) )
{
if ( (size - position) > device->free_in_fifo)
{
int temp = device->free_in_fifo;
device->free_in_fifo = 0;
rf69_write_fifo(spi,
&buffer[position],
temp);
position +=temp;
}
else
{
device->free_in_fifo -= size;
repetitions--;
rf69_write_fifo(spi,
&buffer[position],
(size - position) );
position = 0;
}
retval = wait_event_interruptible(device->fifo_wait_queue,
device->free_in_fifo > 0);
if (retval) { printk("ABORT\n"); goto abort; }
}
dev_dbg(device->dev, "thread: wait for packet to get sent/fifo to be empty");
wait_event_interruptible(device->fifo_wait_queue,
device->free_in_fifo == FIFO_SIZE ||
kthread_should_stop() );
if ( kthread_should_stop() ) printk("ABORT\n");
dev_dbg(device->dev, "thread: Packet sent. Set mode to stby.");
SET_CHECKED(rf69_set_mode(spi, standby));
if ( kfifo_is_empty(&device->tx_fifo) )
{
abort:
if (rx_interrupted)
{
rx_interrupted = false;
pi433_start_rx(device);
}
device->tx_active = false;
wake_up_interruptible(&device->rx_wait_queue);
}
}
}
static ssize_t
pi433_read(struct file *filp, char __user *buf, size_t size, loff_t *f_pos)
{
struct pi433_instance *instance;
struct pi433_device *device;
int bytes_received;
ssize_t retval;
if (size > MAX_MSG_SIZE)
return -EMSGSIZE;
instance = filp->private_data;
device = instance->device;
mutex_lock(&device->rx_lock);
if (device->rx_active)
{
mutex_unlock(&device->rx_lock);
return -EAGAIN;
}
else
{
device->rx_active = true;
mutex_unlock(&device->rx_lock);
}
device->rx_buffer_size = size;
bytes_received = pi433_receive(device);
mutex_lock(&device->rx_lock);
device->rx_active = false;
mutex_unlock(&device->rx_lock);
if (bytes_received > 0)
{
retval = copy_to_user(buf, device->rx_buffer, bytes_received);
if (retval)
return -EFAULT;
}
return bytes_received;
}
static ssize_t
pi433_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
struct pi433_instance *instance;
struct pi433_device *device;
int copied, retval;
instance = filp->private_data;
device = instance->device;
if (count > MAX_MSG_SIZE)
return -EMSGSIZE;
mutex_lock(&device->tx_fifo_lock);
retval = kfifo_in(&device->tx_fifo, &instance->tx_cfg, sizeof(instance->tx_cfg));
if ( retval != sizeof(instance->tx_cfg) )
goto abort;
retval = kfifo_in (&device->tx_fifo, &count, sizeof(size_t));
if ( retval != sizeof(size_t) )
goto abort;
retval = kfifo_from_user(&device->tx_fifo, buf, count, &copied);
if (retval || copied != count)
goto abort;
mutex_unlock(&device->tx_fifo_lock);
wake_up_interruptible(&device->tx_wait_queue);
dev_dbg(device->dev, "write: generated new msg with %d bytes.", copied);
return 0;
abort:
dev_dbg(device->dev, "write to fifo failed: 0x%x", retval);
kfifo_reset(&device->tx_fifo);
mutex_unlock(&device->tx_fifo_lock);
return -EAGAIN;
}
static long
pi433_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
int err = 0;
int retval = 0;
struct pi433_instance *instance;
struct pi433_device *device;
u32 tmp;
if (_IOC_TYPE(cmd) != PI433_IOC_MAGIC)
return -ENOTTY;
if (_IOC_DIR(cmd) & _IOC_READ)
err = !access_ok(VERIFY_WRITE,
(void __user *)arg,
_IOC_SIZE(cmd));
if (err == 0 && _IOC_DIR(cmd) & _IOC_WRITE)
err = !access_ok(VERIFY_READ,
(void __user *)arg,
_IOC_SIZE(cmd));
if (err)
return -EFAULT;
instance = filp->private_data;
device = instance->device;
if (device == NULL)
return -ESHUTDOWN;
switch (cmd) {
case PI433_IOC_RD_TX_CFG:
tmp = _IOC_SIZE(cmd);
if ( (tmp == 0) || ((tmp % sizeof(struct pi433_tx_cfg)) != 0) )
{
retval = -EINVAL;
break;
}
if (__copy_to_user((void __user *)arg,
&instance->tx_cfg,
tmp))
{
retval = -EFAULT;
break;
}
break;
case PI433_IOC_WR_TX_CFG:
tmp = _IOC_SIZE(cmd);
if ( (tmp == 0) || ((tmp % sizeof(struct pi433_tx_cfg)) != 0) )
{
retval = -EINVAL;
break;
}
if (__copy_from_user(&instance->tx_cfg,
(void __user *)arg,
tmp))
{
retval = -EFAULT;
break;
}
break;
case PI433_IOC_RD_RX_CFG:
tmp = _IOC_SIZE(cmd);
if ( (tmp == 0) || ((tmp % sizeof(struct pi433_rx_cfg)) != 0) ) {
retval = -EINVAL;
break;
}
if (__copy_to_user((void __user *)arg,
&device->rx_cfg,
tmp))
{
retval = -EFAULT;
break;
}
break;
case PI433_IOC_WR_RX_CFG:
tmp = _IOC_SIZE(cmd);
mutex_lock(&device->rx_lock);
if (device->rx_active) {
retval = -EAGAIN;
mutex_unlock(&device->rx_lock);
break;
}
if ( (tmp == 0) || ((tmp % sizeof(struct pi433_rx_cfg)) != 0) ) {
retval = -EINVAL;
mutex_unlock(&device->rx_lock);
break;
}
if (__copy_from_user(&device->rx_cfg,
(void __user *)arg,
tmp))
{
retval = -EFAULT;
mutex_unlock(&device->rx_lock);
break;
}
mutex_unlock(&device->rx_lock);
break;
default:
retval = -EINVAL;
}
return retval;
}
static long
pi433_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
return pi433_ioctl(filp, cmd, (unsigned long)compat_ptr(arg));
}
static int pi433_open(struct inode *inode, struct file *filp)
{
struct pi433_device *device;
struct pi433_instance *instance;
mutex_lock(&minor_lock);
device = idr_find(&pi433_idr, iminor(inode));
mutex_unlock(&minor_lock);
if (!device) {
pr_debug("device: minor %d unknown.\n", iminor(inode));
return -ENODEV;
}
if (!device->rx_buffer) {
device->rx_buffer = kmalloc(MAX_MSG_SIZE, GFP_KERNEL);
if (!device->rx_buffer)
{
dev_dbg(device->dev, "open/ENOMEM\n");
return -ENOMEM;
}
}
device->users++;
instance = kzalloc(sizeof(*instance), GFP_KERNEL);
if (!instance)
{
kfree(device->rx_buffer);
device->rx_buffer = NULL;
return -ENOMEM;
}
instance->device = device;
instance->tx_cfg.bit_rate = 4711;
filp->private_data = instance;
nonseekable_open(inode, filp);
return 0;
}
static int pi433_release(struct inode *inode, struct file *filp)
{
struct pi433_instance *instance;
struct pi433_device *device;
instance = filp->private_data;
device = instance->device;
kfree(instance);
filp->private_data = NULL;
device->users--;
if (!device->users) {
kfree(device->rx_buffer);
device->rx_buffer = NULL;
if (device->spi == NULL)
kfree(device);
}
return 0;
}
static int setup_GPIOs(struct pi433_device *device)
{
char name[5];
int retval;
int i;
const irq_handler_t DIO_irq_handler[NUM_DIO] = {
DIO0_irq_handler,
DIO1_irq_handler
};
for (i=0; i<NUM_DIO; i++)
{
snprintf(name, sizeof(name), "DIO%d", i);
device->gpiod[i] = gpiod_get(&device->spi->dev, name, 0 );
if (device->gpiod[i] == ERR_PTR(-ENOENT))
{
dev_dbg(&device->spi->dev, "Could not find entry for %s. Ignoring.", name);
continue;
}
if (device->gpiod[i] == ERR_PTR(-EBUSY))
dev_dbg(&device->spi->dev, "%s is busy.", name);
if ( IS_ERR(device->gpiod[i]) )
{
retval = PTR_ERR(device->gpiod[i]);
for (i--; i>=0; i--)
{
free_irq(device->irq_num[i], device);
gpiod_put(device->gpiod[i]);
}
return retval;
}
gpiod_unexport(device->gpiod[i]);
retval = gpiod_direction_input(device->gpiod[i]);
if (retval) return retval;
device->irq_num[i] = gpiod_to_irq(device->gpiod[i]);
if (device->irq_num[i] < 0)
{
device->gpiod[i] = ERR_PTR(-EINVAL);
return device->irq_num[i];
}
retval = request_irq(device->irq_num[i],
DIO_irq_handler[i],
0,
name,
device);
if (retval)
return retval;
dev_dbg(&device->spi->dev, "%s succesfully configured", name);
}
return 0;
}
static void free_GPIOs(struct pi433_device *device)
{
int i;
for (i=0; i<NUM_DIO; i++)
{
if ( IS_ERR(device->gpiod[i]) )
continue;
free_irq(device->irq_num[i], device);
gpiod_put(device->gpiod[i]);
}
return;
}
static int pi433_get_minor(struct pi433_device *device)
{
int retval = -ENOMEM;
mutex_lock(&minor_lock);
retval = idr_alloc(&pi433_idr, device, 0, N_PI433_MINORS, GFP_KERNEL);
if (retval >= 0) {
device->minor = retval;
retval = 0;
} else if (retval == -ENOSPC) {
dev_err(device->dev, "too many pi433 devices\n");
retval = -EINVAL;
}
mutex_unlock(&minor_lock);
return retval;
}
static void pi433_free_minor(struct pi433_device *dev)
{
mutex_lock(&minor_lock);
idr_remove(&pi433_idr, dev->minor);
mutex_unlock(&minor_lock);
}
static int pi433_probe(struct spi_device *spi)
{
struct pi433_device *device;
int retval;
spi->mode = 0x00;
spi->bits_per_word = 8;
retval = spi_setup(spi);
if (retval)
{
dev_dbg(&spi->dev, "configuration of SPI interface failed!\n");
return retval;
}
else
{
dev_dbg(&spi->dev,
"spi interface setup: mode 0x%2x, %d bits per word, %dhz max speed",
spi->mode, spi->bits_per_word, spi->max_speed_hz);
}
retval = spi_w8r8(spi, 0x10);
if (retval < 0)
return retval;
switch (retval) {
case 0x24:
dev_dbg(&spi->dev, "found pi433 (ver. 0x%x)", retval);
break;
default:
dev_dbg(&spi->dev, "unknown chip version: 0x%x", retval);
return -ENODEV;
}
device = kzalloc(sizeof(*device), GFP_KERNEL);
if (!device)
return -ENOMEM;
device->spi = spi;
device->rx_active = false;
device->tx_active = false;
device->interrupt_rx_allowed = false;
init_waitqueue_head(&device->tx_wait_queue);
init_waitqueue_head(&device->rx_wait_queue);
init_waitqueue_head(&device->fifo_wait_queue);
INIT_KFIFO(device->tx_fifo);
mutex_init(&device->tx_fifo_lock);
mutex_init(&device->rx_lock);
retval = setup_GPIOs(device);
if (retval)
{
dev_dbg(&spi->dev, "setup of GPIOs failed");
goto GPIO_failed;
}
SET_CHECKED(rf69_set_mode (spi, standby));
SET_CHECKED(rf69_set_data_mode (spi, packet));
SET_CHECKED(rf69_set_amplifier_0 (spi, optionOn));
SET_CHECKED(rf69_set_amplifier_1 (spi, optionOff));
SET_CHECKED(rf69_set_amplifier_2 (spi, optionOff));
SET_CHECKED(rf69_set_output_power_level (spi, 13));
SET_CHECKED(rf69_set_antenna_impedance (spi, fiftyOhm));
device->tx_task_struct = kthread_run(pi433_tx_thread,
device,
"pi433_tx_task");
if (IS_ERR(device->tx_task_struct))
{
dev_dbg(device->dev, "start of send thread failed");
goto send_thread_failed;
}
retval = pi433_get_minor(device);
if (retval)
{
dev_dbg(device->dev, "get of minor number failed");
goto minor_failed;
}
device->devt = MKDEV(MAJOR(pi433_dev), device->minor);
device->dev = device_create(pi433_class,
&spi->dev,
device->devt,
device,
"pi433");
if (IS_ERR(device->dev)) {
pr_err("pi433: device register failed\n");
retval = PTR_ERR(device->dev);
goto device_create_failed;
}
else {
dev_dbg(device->dev,
"created device for major %d, minor %d\n",
MAJOR(pi433_dev),
device->minor);
}
device->cdev = cdev_alloc();
device->cdev->owner = THIS_MODULE;
cdev_init(device->cdev, &pi433_fops);
retval = cdev_add(device->cdev, device->devt, 1);
if (retval)
{
dev_dbg(device->dev, "register of cdev failed");
goto cdev_failed;
}
spi_set_drvdata(spi, device);
return 0;
cdev_failed:
device_destroy(pi433_class, device->devt);
device_create_failed:
pi433_free_minor(device);
minor_failed:
kthread_stop(device->tx_task_struct);
send_thread_failed:
free_GPIOs(device);
GPIO_failed:
kfree(device);
return retval;
}
static int pi433_remove(struct spi_device *spi)
{
struct pi433_device *device = spi_get_drvdata(spi);
free_GPIOs(device);
device->spi = NULL;
kthread_stop(device->tx_task_struct);
device_destroy(pi433_class, device->devt);
cdev_del(device->cdev);
pi433_free_minor(device);
if (device->users == 0)
kfree(device);
return 0;
}
static int __init pi433_init(void)
{
int status;
if (MAX_MSG_SIZE < FIFO_SIZE)
return -EINVAL;
status = alloc_chrdev_region(&pi433_dev, 0 , N_PI433_MINORS , "pi433" );
if (status < 0)
return status;
pi433_class = class_create(THIS_MODULE, "pi433");
if (IS_ERR(pi433_class))
{
unregister_chrdev(MAJOR(pi433_dev), pi433_spi_driver.driver.name);
return PTR_ERR(pi433_class);
}
status = spi_register_driver(&pi433_spi_driver);
if (status < 0)
{
class_destroy(pi433_class);
unregister_chrdev(MAJOR(pi433_dev), pi433_spi_driver.driver.name);
}
return status;
}
static void __exit pi433_exit(void)
{
spi_unregister_driver(&pi433_spi_driver);
class_destroy(pi433_class);
unregister_chrdev(MAJOR(pi433_dev), pi433_spi_driver.driver.name);
}
