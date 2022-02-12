static void dvb_ca_private_free(struct dvb_ca_private *ca)
{
unsigned int i;
dvb_free_device(ca->dvbdev);
for (i = 0; i < ca->slot_count; i++)
vfree(ca->slot_info[i].rx_buffer.data);
kfree(ca->slot_info);
kfree(ca);
}
static void dvb_ca_private_release(struct kref *ref)
{
struct dvb_ca_private *ca = container_of(ref, struct dvb_ca_private, refcount);
dvb_ca_private_free(ca);
}
static void dvb_ca_private_get(struct dvb_ca_private *ca)
{
kref_get(&ca->refcount);
}
static void dvb_ca_private_put(struct dvb_ca_private *ca)
{
kref_put(&ca->refcount, dvb_ca_private_release);
}
static char *findstr(char * haystack, int hlen, char * needle, int nlen)
{
int i;
if (hlen < nlen)
return NULL;
for (i = 0; i <= hlen - nlen; i++) {
if (!strncmp(haystack + i, needle, nlen))
return haystack + i;
}
return NULL;
}
static int dvb_ca_en50221_check_camstatus(struct dvb_ca_private *ca, int slot)
{
int slot_status;
int cam_present_now;
int cam_changed;
if (ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE) {
return (atomic_read(&ca->slot_info[slot].camchange_count) != 0);
}
slot_status = ca->pub->poll_slot_status(ca->pub, slot, ca->open);
cam_present_now = (slot_status & DVB_CA_EN50221_POLL_CAM_PRESENT) ? 1 : 0;
cam_changed = (slot_status & DVB_CA_EN50221_POLL_CAM_CHANGED) ? 1 : 0;
if (!cam_changed) {
int cam_present_old = (ca->slot_info[slot].slot_state != DVB_CA_SLOTSTATE_NONE);
cam_changed = (cam_present_now != cam_present_old);
}
if (cam_changed) {
if (!cam_present_now) {
ca->slot_info[slot].camchange_type = DVB_CA_EN50221_CAMCHANGE_REMOVED;
} else {
ca->slot_info[slot].camchange_type = DVB_CA_EN50221_CAMCHANGE_INSERTED;
}
atomic_set(&ca->slot_info[slot].camchange_count, 1);
} else {
if ((ca->slot_info[slot].slot_state == DVB_CA_SLOTSTATE_WAITREADY) &&
(slot_status & DVB_CA_EN50221_POLL_CAM_READY)) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_VALIDATE;
}
}
return cam_changed;
}
static int dvb_ca_en50221_wait_if_status(struct dvb_ca_private *ca, int slot,
u8 waitfor, int timeout_hz)
{
unsigned long timeout;
unsigned long start;
dprintk("%s\n", __func__);
start = jiffies;
timeout = jiffies + timeout_hz;
while (1) {
int res = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS);
if (res < 0)
return -EIO;
if (res & waitfor) {
dprintk("%s succeeded timeout:%lu\n",
__func__, jiffies - start);
return 0;
}
if (time_after(jiffies, timeout)) {
break;
}
msleep(1);
}
dprintk("%s failed timeout:%lu\n", __func__, jiffies - start);
return -ETIMEDOUT;
}
static int dvb_ca_en50221_link_init(struct dvb_ca_private *ca, int slot)
{
int ret;
int buf_size;
u8 buf[2];
dprintk("%s\n", __func__);
ca->slot_info[slot].da_irq_supported = 0;
ca->slot_info[slot].link_buf_size = 2;
if ((ret = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_COMMAND, IRQEN | CMDREG_SR)) != 0)
return ret;
if ((ret = dvb_ca_en50221_wait_if_status(ca, slot, STATUSREG_DA, HZ / 10)) != 0)
return ret;
if ((ret = dvb_ca_en50221_read_data(ca, slot, buf, 2)) != 2)
return -EIO;
if ((ret = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_COMMAND, IRQEN)) != 0)
return ret;
buf_size = (buf[0] << 8) | buf[1];
if (buf_size > HOST_LINK_BUF_SIZE)
buf_size = HOST_LINK_BUF_SIZE;
ca->slot_info[slot].link_buf_size = buf_size;
buf[0] = buf_size >> 8;
buf[1] = buf_size & 0xff;
dprintk("Chosen link buffer size of %i\n", buf_size);
if ((ret = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_COMMAND, IRQEN | CMDREG_SW)) != 0)
return ret;
if ((ret = dvb_ca_en50221_wait_if_status(ca, slot, STATUSREG_FR, HZ / 10)) != 0)
return ret;
if ((ret = dvb_ca_en50221_write_data(ca, slot, buf, 2)) != 2)
return -EIO;
if ((ret = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_COMMAND, IRQEN)) != 0)
return ret;
return 0;
}
static int dvb_ca_en50221_read_tuple(struct dvb_ca_private *ca, int slot,
int *address, int *tupleType, int *tupleLength, u8 * tuple)
{
int i;
int _tupleType;
int _tupleLength;
int _address = *address;
if ((_tupleType = ca->pub->read_attribute_mem(ca->pub, slot, _address)) < 0)
return _tupleType;
if (_tupleType == 0xff) {
dprintk("END OF CHAIN TUPLE type:0x%x\n", _tupleType);
*address += 2;
*tupleType = _tupleType;
*tupleLength = 0;
return 0;
}
if ((_tupleLength = ca->pub->read_attribute_mem(ca->pub, slot, _address + 2)) < 0)
return _tupleLength;
_address += 4;
dprintk("TUPLE type:0x%x length:%i\n", _tupleType, _tupleLength);
for (i = 0; i < _tupleLength; i++) {
tuple[i] = ca->pub->read_attribute_mem(ca->pub, slot, _address + (i * 2));
dprintk(" 0x%02x: 0x%02x %c\n",
i, tuple[i] & 0xff,
((tuple[i] > 31) && (tuple[i] < 127)) ? tuple[i] : '.');
}
_address += (_tupleLength * 2);
*tupleType = _tupleType;
*tupleLength = _tupleLength;
*address = _address;
return 0;
}
static int dvb_ca_en50221_parse_attributes(struct dvb_ca_private *ca, int slot)
{
int address = 0;
int tupleLength;
int tupleType;
u8 tuple[257];
char *dvb_str;
int rasz;
int status;
int got_cftableentry = 0;
int end_chain = 0;
int i;
u16 manfid = 0;
u16 devid = 0;
if ((status =
dvb_ca_en50221_read_tuple(ca, slot, &address, &tupleType, &tupleLength, tuple)) < 0)
return status;
if (tupleType != 0x1D)
return -EINVAL;
if ((status =
dvb_ca_en50221_read_tuple(ca, slot, &address, &tupleType, &tupleLength, tuple)) < 0)
return status;
if (tupleType != 0x1C)
return -EINVAL;
if ((status =
dvb_ca_en50221_read_tuple(ca, slot, &address, &tupleType, &tupleLength, tuple)) < 0)
return status;
if (tupleType != 0x15)
return -EINVAL;
if ((status = dvb_ca_en50221_read_tuple(ca, slot, &address, &tupleType,
&tupleLength, tuple)) < 0)
return status;
if (tupleType != 0x20)
return -EINVAL;
if (tupleLength != 4)
return -EINVAL;
manfid = (tuple[1] << 8) | tuple[0];
devid = (tuple[3] << 8) | tuple[2];
if ((status = dvb_ca_en50221_read_tuple(ca, slot, &address, &tupleType,
&tupleLength, tuple)) < 0)
return status;
if (tupleType != 0x1A)
return -EINVAL;
if (tupleLength < 3)
return -EINVAL;
rasz = tuple[0] & 3;
if (tupleLength < (3 + rasz + 14))
return -EINVAL;
ca->slot_info[slot].config_base = 0;
for (i = 0; i < rasz + 1; i++) {
ca->slot_info[slot].config_base |= (tuple[2 + i] << (8 * i));
}
dvb_str = findstr((char *)tuple, tupleLength, "DVB_CI_V", 8);
if (dvb_str == NULL)
return -EINVAL;
if (tupleLength < ((dvb_str - (char *) tuple) + 12))
return -EINVAL;
if (strncmp(dvb_str + 8, "1.00", 4)) {
pr_err("dvb_ca adapter %d: Unsupported DVB CAM module version %c%c%c%c\n",
ca->dvbdev->adapter->num, dvb_str[8], dvb_str[9],
dvb_str[10], dvb_str[11]);
return -EINVAL;
}
while ((!end_chain) && (address < 0x1000)) {
if ((status = dvb_ca_en50221_read_tuple(ca, slot, &address, &tupleType,
&tupleLength, tuple)) < 0)
return status;
switch (tupleType) {
case 0x1B:
if (tupleLength < (2 + 11 + 17))
break;
if (got_cftableentry)
break;
ca->slot_info[slot].config_option = tuple[0] & 0x3f;
if ((findstr((char *)tuple, tupleLength, "DVB_HOST", 8) == NULL) ||
(findstr((char *)tuple, tupleLength, "DVB_CI_MODULE", 13) == NULL))
break;
got_cftableentry = 1;
break;
case 0x14:
break;
case 0xFF:
end_chain = 1;
break;
default:
dprintk("dvb_ca: Skipping unknown tuple type:0x%x length:0x%x\n",
tupleType, tupleLength);
break;
}
}
if ((address > 0x1000) || (!got_cftableentry))
return -EINVAL;
dprintk("Valid DVB CAM detected MANID:%x DEVID:%x CONFIGBASE:0x%x CONFIGOPTION:0x%x\n",
manfid, devid, ca->slot_info[slot].config_base,
ca->slot_info[slot].config_option);
return 0;
}
static int dvb_ca_en50221_set_configoption(struct dvb_ca_private *ca, int slot)
{
int configoption;
dprintk("%s\n", __func__);
ca->pub->write_attribute_mem(ca->pub, slot,
ca->slot_info[slot].config_base,
ca->slot_info[slot].config_option);
configoption = ca->pub->read_attribute_mem(ca->pub, slot, ca->slot_info[slot].config_base);
dprintk("Set configoption 0x%x, read configoption 0x%x\n",
ca->slot_info[slot].config_option, configoption & 0x3f);
return 0;
}
static int dvb_ca_en50221_read_data(struct dvb_ca_private *ca, int slot, u8 * ebuf, int ecount)
{
int bytes_read;
int status;
u8 buf[HOST_LINK_BUF_SIZE];
int i;
dprintk("%s\n", __func__);
if (ebuf == NULL) {
int buf_free;
if (ca->slot_info[slot].rx_buffer.data == NULL) {
status = -EIO;
goto exit;
}
buf_free = dvb_ringbuffer_free(&ca->slot_info[slot].rx_buffer);
if (buf_free < (ca->slot_info[slot].link_buf_size + DVB_RINGBUFFER_PKTHDRSIZE)) {
status = -EAGAIN;
goto exit;
}
}
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS)) < 0)
goto exit;
if (!(status & STATUSREG_DA)) {
status = 0;
goto exit;
}
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_SIZE_HIGH)) < 0)
goto exit;
bytes_read = status << 8;
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_SIZE_LOW)) < 0)
goto exit;
bytes_read |= status;
if (ebuf == NULL) {
if (bytes_read > ca->slot_info[slot].link_buf_size) {
pr_err("dvb_ca adapter %d: CAM tried to send a buffer larger than the link buffer size (%i > %i)!\n",
ca->dvbdev->adapter->num, bytes_read,
ca->slot_info[slot].link_buf_size);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_LINKINIT;
status = -EIO;
goto exit;
}
if (bytes_read < 2) {
pr_err("dvb_ca adapter %d: CAM sent a buffer that was less than 2 bytes!\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_LINKINIT;
status = -EIO;
goto exit;
}
} else {
if (bytes_read > ecount) {
pr_err("dvb_ca adapter %d: CAM tried to send a buffer larger than the ecount size!\n",
ca->dvbdev->adapter->num);
status = -EIO;
goto exit;
}
}
for (i = 0; i < bytes_read; i++) {
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_DATA)) < 0)
goto exit;
buf[i] = status;
}
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS)) < 0)
goto exit;
if (status & STATUSREG_RE) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_LINKINIT;
status = -EIO;
goto exit;
}
if (ebuf == NULL) {
if (ca->slot_info[slot].rx_buffer.data == NULL) {
status = -EIO;
goto exit;
}
dvb_ringbuffer_pkt_write(&ca->slot_info[slot].rx_buffer, buf, bytes_read);
} else {
memcpy(ebuf, buf, bytes_read);
}
dprintk("Received CA packet for slot %i connection id 0x%x last_frag:%i size:0x%x\n", slot,
buf[0], (buf[1] & 0x80) == 0, bytes_read);
if ((buf[1] & 0x80) == 0x00) {
wake_up_interruptible(&ca->wait_queue);
}
status = bytes_read;
exit:
return status;
}
static int dvb_ca_en50221_write_data(struct dvb_ca_private *ca, int slot, u8 * buf, int bytes_write)
{
int status;
int i;
dprintk("%s\n", __func__);
if (bytes_write > ca->slot_info[slot].link_buf_size)
return -EINVAL;
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS)) < 0)
goto exitnowrite;
if (status & (STATUSREG_DA | STATUSREG_RE)) {
if (status & STATUSREG_DA)
dvb_ca_en50221_thread_wakeup(ca);
status = -EAGAIN;
goto exitnowrite;
}
if ((status = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_COMMAND,
IRQEN | CMDREG_HC)) != 0)
goto exit;
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS)) < 0)
goto exit;
if (!(status & STATUSREG_FR)) {
status = -EAGAIN;
goto exit;
}
if ((status = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_SIZE_HIGH, bytes_write >> 8)) != 0)
goto exit;
if ((status = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_SIZE_LOW,
bytes_write & 0xff)) != 0)
goto exit;
for (i = 0; i < bytes_write; i++) {
if ((status = ca->pub->write_cam_control(ca->pub, slot, CTRLIF_DATA, buf[i])) != 0)
goto exit;
}
if ((status = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS)) < 0)
goto exit;
if (status & STATUSREG_WE) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_LINKINIT;
status = -EIO;
goto exit;
}
status = bytes_write;
dprintk("Wrote CA packet for slot %i, connection id 0x%x last_frag:%i size:0x%x\n", slot,
buf[0], (buf[1] & 0x80) == 0, bytes_write);
exit:
ca->pub->write_cam_control(ca->pub, slot, CTRLIF_COMMAND, IRQEN);
exitnowrite:
return status;
}
static int dvb_ca_en50221_slot_shutdown(struct dvb_ca_private *ca, int slot)
{
dprintk("%s\n", __func__);
ca->pub->slot_shutdown(ca->pub, slot);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_NONE;
wake_up_interruptible(&ca->wait_queue);
dprintk("Slot %i shutdown\n", slot);
return 0;
}
void dvb_ca_en50221_camchange_irq(struct dvb_ca_en50221 *pubca, int slot, int change_type)
{
struct dvb_ca_private *ca = pubca->private;
dprintk("CAMCHANGE IRQ slot:%i change_type:%i\n", slot, change_type);
switch (change_type) {
case DVB_CA_EN50221_CAMCHANGE_REMOVED:
case DVB_CA_EN50221_CAMCHANGE_INSERTED:
break;
default:
return;
}
ca->slot_info[slot].camchange_type = change_type;
atomic_inc(&ca->slot_info[slot].camchange_count);
dvb_ca_en50221_thread_wakeup(ca);
}
void dvb_ca_en50221_camready_irq(struct dvb_ca_en50221 *pubca, int slot)
{
struct dvb_ca_private *ca = pubca->private;
dprintk("CAMREADY IRQ slot:%i\n", slot);
if (ca->slot_info[slot].slot_state == DVB_CA_SLOTSTATE_WAITREADY) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_VALIDATE;
dvb_ca_en50221_thread_wakeup(ca);
}
}
void dvb_ca_en50221_frda_irq(struct dvb_ca_en50221 *pubca, int slot)
{
struct dvb_ca_private *ca = pubca->private;
int flags;
dprintk("FR/DA IRQ slot:%i\n", slot);
switch (ca->slot_info[slot].slot_state) {
case DVB_CA_SLOTSTATE_LINKINIT:
flags = ca->pub->read_cam_control(pubca, slot, CTRLIF_STATUS);
if (flags & STATUSREG_DA) {
dprintk("CAM supports DA IRQ\n");
ca->slot_info[slot].da_irq_supported = 1;
}
break;
case DVB_CA_SLOTSTATE_RUNNING:
if (ca->open)
dvb_ca_en50221_thread_wakeup(ca);
break;
}
}
static void dvb_ca_en50221_thread_wakeup(struct dvb_ca_private *ca)
{
dprintk("%s\n", __func__);
ca->wakeup = 1;
mb();
wake_up_process(ca->thread);
}
static void dvb_ca_en50221_thread_update_delay(struct dvb_ca_private *ca)
{
int delay;
int curdelay = 100000000;
int slot;
for (slot = 0; slot < ca->slot_count; slot++) {
switch (ca->slot_info[slot].slot_state) {
default:
case DVB_CA_SLOTSTATE_NONE:
delay = HZ * 60;
if (!(ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE))
delay = HZ * 5;
break;
case DVB_CA_SLOTSTATE_INVALID:
delay = HZ * 60;
if (!(ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE))
delay = HZ / 10;
break;
case DVB_CA_SLOTSTATE_UNINITIALISED:
case DVB_CA_SLOTSTATE_WAITREADY:
case DVB_CA_SLOTSTATE_VALIDATE:
case DVB_CA_SLOTSTATE_WAITFR:
case DVB_CA_SLOTSTATE_LINKINIT:
delay = HZ / 10;
break;
case DVB_CA_SLOTSTATE_RUNNING:
delay = HZ * 60;
if (!(ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE))
delay = HZ / 10;
if (ca->open) {
if ((!ca->slot_info[slot].da_irq_supported) ||
(!(ca->flags & DVB_CA_EN50221_FLAG_IRQ_DA)))
delay = HZ / 10;
}
break;
}
if (delay < curdelay)
curdelay = delay;
}
ca->delay = curdelay;
}
static int dvb_ca_en50221_thread(void *data)
{
struct dvb_ca_private *ca = data;
int slot;
int flags;
int status;
int pktcount;
void *rxbuf;
dprintk("%s\n", __func__);
dvb_ca_en50221_thread_update_delay(ca);
while (!kthread_should_stop()) {
if (!ca->wakeup) {
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(ca->delay);
if (kthread_should_stop())
return 0;
}
ca->wakeup = 0;
for (slot = 0; slot < ca->slot_count; slot++) {
mutex_lock(&ca->slot_info[slot].slot_lock);
while (dvb_ca_en50221_check_camstatus(ca, slot)) {
if (ca->slot_info[slot].slot_state != DVB_CA_SLOTSTATE_NONE)
dvb_ca_en50221_slot_shutdown(ca, slot);
if (ca->slot_info[slot].camchange_type == DVB_CA_EN50221_CAMCHANGE_INSERTED) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_UNINITIALISED;
}
dvb_ca_en50221_thread_update_delay(ca);
atomic_dec(&ca->slot_info[slot].camchange_count);
}
switch (ca->slot_info[slot].slot_state) {
case DVB_CA_SLOTSTATE_NONE:
case DVB_CA_SLOTSTATE_INVALID:
break;
case DVB_CA_SLOTSTATE_UNINITIALISED:
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_WAITREADY;
ca->pub->slot_reset(ca->pub, slot);
ca->slot_info[slot].timeout = jiffies + (INIT_TIMEOUT_SECS * HZ);
break;
case DVB_CA_SLOTSTATE_WAITREADY:
if (time_after(jiffies, ca->slot_info[slot].timeout)) {
pr_err("dvb_ca adaptor %d: PC card did not respond :(\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
break;
case DVB_CA_SLOTSTATE_VALIDATE:
if (dvb_ca_en50221_parse_attributes(ca, slot) != 0) {
if ((!(ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE)) &&
(ca->pub->poll_slot_status)) {
status = ca->pub->poll_slot_status(ca->pub, slot, 0);
if (!(status & DVB_CA_EN50221_POLL_CAM_PRESENT)) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_NONE;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
}
pr_err("dvb_ca adapter %d: Invalid PC card inserted :(\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
if (dvb_ca_en50221_set_configoption(ca, slot) != 0) {
pr_err("dvb_ca adapter %d: Unable to initialise CAM :(\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
if (ca->pub->write_cam_control(ca->pub, slot,
CTRLIF_COMMAND, CMDREG_RS) != 0) {
pr_err("dvb_ca adapter %d: Unable to reset CAM IF\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
dprintk("DVB CAM validated successfully\n");
ca->slot_info[slot].timeout = jiffies + (INIT_TIMEOUT_SECS * HZ);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_WAITFR;
ca->wakeup = 1;
break;
case DVB_CA_SLOTSTATE_WAITFR:
if (time_after(jiffies, ca->slot_info[slot].timeout)) {
pr_err("dvb_ca adapter %d: DVB CAM did not respond :(\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
flags = ca->pub->read_cam_control(ca->pub, slot, CTRLIF_STATUS);
if (flags & STATUSREG_FR) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_LINKINIT;
ca->wakeup = 1;
}
break;
case DVB_CA_SLOTSTATE_LINKINIT:
if (dvb_ca_en50221_link_init(ca, slot) != 0) {
if ((!(ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE)) &&
(ca->pub->poll_slot_status)) {
status = ca->pub->poll_slot_status(ca->pub, slot, 0);
if (!(status & DVB_CA_EN50221_POLL_CAM_PRESENT)) {
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_NONE;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
}
pr_err("dvb_ca adapter %d: DVB CAM link initialisation failed :(\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
if (ca->slot_info[slot].rx_buffer.data == NULL) {
rxbuf = vmalloc(RX_BUFFER_SIZE);
if (rxbuf == NULL) {
pr_err("dvb_ca adapter %d: Unable to allocate CAM rx buffer :(\n",
ca->dvbdev->adapter->num);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_INVALID;
dvb_ca_en50221_thread_update_delay(ca);
break;
}
dvb_ringbuffer_init(&ca->slot_info[slot].rx_buffer, rxbuf, RX_BUFFER_SIZE);
}
ca->pub->slot_ts_enable(ca->pub, slot);
ca->slot_info[slot].slot_state = DVB_CA_SLOTSTATE_RUNNING;
dvb_ca_en50221_thread_update_delay(ca);
pr_err("dvb_ca adapter %d: DVB CAM detected and initialised successfully\n",
ca->dvbdev->adapter->num);
break;
case DVB_CA_SLOTSTATE_RUNNING:
if (!ca->open)
break;
pktcount = 0;
while ((status = dvb_ca_en50221_read_data(ca, slot, NULL, 0)) > 0) {
if (!ca->open)
break;
if (dvb_ca_en50221_check_camstatus(ca, slot)) {
ca->wakeup = 1;
break;
}
if (++pktcount >= MAX_RX_PACKETS_PER_ITERATION) {
ca->wakeup = 1;
break;
}
}
break;
}
mutex_unlock(&ca->slot_info[slot].slot_lock);
}
}
return 0;
}
static int dvb_ca_en50221_io_do_ioctl(struct file *file,
unsigned int cmd, void *parg)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_ca_private *ca = dvbdev->priv;
int err = 0;
int slot;
dprintk("%s\n", __func__);
if (mutex_lock_interruptible(&ca->ioctl_mutex))
return -ERESTARTSYS;
switch (cmd) {
case CA_RESET:
for (slot = 0; slot < ca->slot_count; slot++) {
mutex_lock(&ca->slot_info[slot].slot_lock);
if (ca->slot_info[slot].slot_state != DVB_CA_SLOTSTATE_NONE) {
dvb_ca_en50221_slot_shutdown(ca, slot);
if (ca->flags & DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE)
dvb_ca_en50221_camchange_irq(ca->pub,
slot,
DVB_CA_EN50221_CAMCHANGE_INSERTED);
}
mutex_unlock(&ca->slot_info[slot].slot_lock);
}
ca->next_read_slot = 0;
dvb_ca_en50221_thread_wakeup(ca);
break;
case CA_GET_CAP: {
struct ca_caps *caps = parg;
caps->slot_num = ca->slot_count;
caps->slot_type = CA_CI_LINK;
caps->descr_num = 0;
caps->descr_type = 0;
break;
}
case CA_GET_SLOT_INFO: {
struct ca_slot_info *info = parg;
if ((info->num > ca->slot_count) || (info->num < 0)) {
err = -EINVAL;
goto out_unlock;
}
info->type = CA_CI_LINK;
info->flags = 0;
if ((ca->slot_info[info->num].slot_state != DVB_CA_SLOTSTATE_NONE)
&& (ca->slot_info[info->num].slot_state != DVB_CA_SLOTSTATE_INVALID)) {
info->flags = CA_CI_MODULE_PRESENT;
}
if (ca->slot_info[info->num].slot_state == DVB_CA_SLOTSTATE_RUNNING) {
info->flags |= CA_CI_MODULE_READY;
}
break;
}
default:
err = -EINVAL;
break;
}
out_unlock:
mutex_unlock(&ca->ioctl_mutex);
return err;
}
static long dvb_ca_en50221_io_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
return dvb_usercopy(file, cmd, arg, dvb_ca_en50221_io_do_ioctl);
}
static ssize_t dvb_ca_en50221_io_write(struct file *file,
const char __user * buf, size_t count, loff_t * ppos)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_ca_private *ca = dvbdev->priv;
u8 slot, connection_id;
int status;
u8 fragbuf[HOST_LINK_BUF_SIZE];
int fragpos = 0;
int fraglen;
unsigned long timeout;
int written;
dprintk("%s\n", __func__);
if (count < 2)
return -EINVAL;
if (copy_from_user(&slot, buf, 1))
return -EFAULT;
if (copy_from_user(&connection_id, buf + 1, 1))
return -EFAULT;
buf += 2;
count -= 2;
if (ca->slot_info[slot].slot_state != DVB_CA_SLOTSTATE_RUNNING)
return -EINVAL;
while (fragpos < count) {
fraglen = ca->slot_info[slot].link_buf_size - 2;
if (fraglen < 0)
break;
if (fraglen > HOST_LINK_BUF_SIZE - 2)
fraglen = HOST_LINK_BUF_SIZE - 2;
if ((count - fragpos) < fraglen)
fraglen = count - fragpos;
fragbuf[0] = connection_id;
fragbuf[1] = ((fragpos + fraglen) < count) ? 0x80 : 0x00;
status = copy_from_user(fragbuf + 2, buf + fragpos, fraglen);
if (status) {
status = -EFAULT;
goto exit;
}
timeout = jiffies + HZ / 2;
written = 0;
while (!time_after(jiffies, timeout)) {
if (ca->slot_info[slot].slot_state != DVB_CA_SLOTSTATE_RUNNING) {
status = -EIO;
goto exit;
}
mutex_lock(&ca->slot_info[slot].slot_lock);
status = dvb_ca_en50221_write_data(ca, slot, fragbuf, fraglen + 2);
mutex_unlock(&ca->slot_info[slot].slot_lock);
if (status == (fraglen + 2)) {
written = 1;
break;
}
if (status != -EAGAIN)
goto exit;
msleep(1);
}
if (!written) {
status = -EIO;
goto exit;
}
fragpos += fraglen;
}
status = count + 2;
exit:
return status;
}
static int dvb_ca_en50221_io_read_condition(struct dvb_ca_private *ca,
int *result, int *_slot)
{
int slot;
int slot_count = 0;
int idx;
size_t fraglen;
int connection_id = -1;
int found = 0;
u8 hdr[2];
slot = ca->next_read_slot;
while ((slot_count < ca->slot_count) && (!found)) {
if (ca->slot_info[slot].slot_state != DVB_CA_SLOTSTATE_RUNNING)
goto nextslot;
if (ca->slot_info[slot].rx_buffer.data == NULL) {
return 0;
}
idx = dvb_ringbuffer_pkt_next(&ca->slot_info[slot].rx_buffer, -1, &fraglen);
while (idx != -1) {
dvb_ringbuffer_pkt_read(&ca->slot_info[slot].rx_buffer, idx, 0, hdr, 2);
if (connection_id == -1)
connection_id = hdr[0];
if ((hdr[0] == connection_id) && ((hdr[1] & 0x80) == 0)) {
*_slot = slot;
found = 1;
break;
}
idx = dvb_ringbuffer_pkt_next(&ca->slot_info[slot].rx_buffer, idx, &fraglen);
}
nextslot:
slot = (slot + 1) % ca->slot_count;
slot_count++;
}
ca->next_read_slot = slot;
return found;
}
static ssize_t dvb_ca_en50221_io_read(struct file *file, char __user * buf,
size_t count, loff_t * ppos)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_ca_private *ca = dvbdev->priv;
int status;
int result = 0;
u8 hdr[2];
int slot;
int connection_id = -1;
size_t idx, idx2;
int last_fragment = 0;
size_t fraglen;
int pktlen;
int dispose = 0;
dprintk("%s\n", __func__);
if (count < 2)
return -EINVAL;
if ((status = dvb_ca_en50221_io_read_condition(ca, &result, &slot)) == 0) {
if (file->f_flags & O_NONBLOCK)
return -EWOULDBLOCK;
status = wait_event_interruptible(ca->wait_queue,
dvb_ca_en50221_io_read_condition
(ca, &result, &slot));
}
if ((status < 0) || (result < 0)) {
if (result)
return result;
return status;
}
idx = dvb_ringbuffer_pkt_next(&ca->slot_info[slot].rx_buffer, -1, &fraglen);
pktlen = 2;
do {
if (idx == -1) {
pr_err("dvb_ca adapter %d: BUG: read packet ended before last_fragment encountered\n",
ca->dvbdev->adapter->num);
status = -EIO;
goto exit;
}
dvb_ringbuffer_pkt_read(&ca->slot_info[slot].rx_buffer, idx, 0, hdr, 2);
if (connection_id == -1)
connection_id = hdr[0];
if (hdr[0] == connection_id) {
if (pktlen < count) {
if ((pktlen + fraglen - 2) > count) {
fraglen = count - pktlen;
} else {
fraglen -= 2;
}
if ((status = dvb_ringbuffer_pkt_read_user(&ca->slot_info[slot].rx_buffer, idx, 2,
buf + pktlen, fraglen)) < 0) {
goto exit;
}
pktlen += fraglen;
}
if ((hdr[1] & 0x80) == 0)
last_fragment = 1;
dispose = 1;
}
idx2 = dvb_ringbuffer_pkt_next(&ca->slot_info[slot].rx_buffer, idx, &fraglen);
if (dispose)
dvb_ringbuffer_pkt_dispose(&ca->slot_info[slot].rx_buffer, idx);
idx = idx2;
dispose = 0;
} while (!last_fragment);
hdr[0] = slot;
hdr[1] = connection_id;
status = copy_to_user(buf, hdr, 2);
if (status) {
status = -EFAULT;
goto exit;
}
status = pktlen;
exit:
return status;
}
static int dvb_ca_en50221_io_open(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_ca_private *ca = dvbdev->priv;
int err;
int i;
dprintk("%s\n", __func__);
if (!try_module_get(ca->pub->owner))
return -EIO;
err = dvb_generic_open(inode, file);
if (err < 0) {
module_put(ca->pub->owner);
return err;
}
for (i = 0; i < ca->slot_count; i++) {
if (ca->slot_info[i].slot_state == DVB_CA_SLOTSTATE_RUNNING) {
if (ca->slot_info[i].rx_buffer.data != NULL) {
dvb_ringbuffer_flush(&ca->slot_info[i].rx_buffer);
}
}
}
ca->open = 1;
dvb_ca_en50221_thread_update_delay(ca);
dvb_ca_en50221_thread_wakeup(ca);
dvb_ca_private_get(ca);
return 0;
}
static int dvb_ca_en50221_io_release(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_ca_private *ca = dvbdev->priv;
int err;
dprintk("%s\n", __func__);
ca->open = 0;
dvb_ca_en50221_thread_update_delay(ca);
err = dvb_generic_release(inode, file);
module_put(ca->pub->owner);
dvb_ca_private_put(ca);
return err;
}
static unsigned int dvb_ca_en50221_io_poll(struct file *file, poll_table * wait)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_ca_private *ca = dvbdev->priv;
unsigned int mask = 0;
int slot;
int result = 0;
dprintk("%s\n", __func__);
if (dvb_ca_en50221_io_read_condition(ca, &result, &slot) == 1) {
mask |= POLLIN;
}
if (mask)
return mask;
poll_wait(file, &ca->wait_queue, wait);
if (dvb_ca_en50221_io_read_condition(ca, &result, &slot) == 1) {
mask |= POLLIN;
}
return mask;
}
int dvb_ca_en50221_init(struct dvb_adapter *dvb_adapter,
struct dvb_ca_en50221 *pubca, int flags, int slot_count)
{
int ret;
struct dvb_ca_private *ca = NULL;
int i;
dprintk("%s\n", __func__);
if (slot_count < 1)
return -EINVAL;
if ((ca = kzalloc(sizeof(struct dvb_ca_private), GFP_KERNEL)) == NULL) {
ret = -ENOMEM;
goto exit;
}
kref_init(&ca->refcount);
ca->pub = pubca;
ca->flags = flags;
ca->slot_count = slot_count;
if ((ca->slot_info = kcalloc(slot_count, sizeof(struct dvb_ca_slot), GFP_KERNEL)) == NULL) {
ret = -ENOMEM;
goto free_ca;
}
init_waitqueue_head(&ca->wait_queue);
ca->open = 0;
ca->wakeup = 0;
ca->next_read_slot = 0;
pubca->private = ca;
ret = dvb_register_device(dvb_adapter, &ca->dvbdev, &dvbdev_ca, ca, DVB_DEVICE_CA, 0);
if (ret)
goto free_slot_info;
for (i = 0; i < slot_count; i++) {
memset(&ca->slot_info[i], 0, sizeof(struct dvb_ca_slot));
ca->slot_info[i].slot_state = DVB_CA_SLOTSTATE_NONE;
atomic_set(&ca->slot_info[i].camchange_count, 0);
ca->slot_info[i].camchange_type = DVB_CA_EN50221_CAMCHANGE_REMOVED;
mutex_init(&ca->slot_info[i].slot_lock);
}
mutex_init(&ca->ioctl_mutex);
if (signal_pending(current)) {
ret = -EINTR;
goto unregister_device;
}
mb();
ca->thread = kthread_run(dvb_ca_en50221_thread, ca, "kdvb-ca-%i:%i",
ca->dvbdev->adapter->num, ca->dvbdev->id);
if (IS_ERR(ca->thread)) {
ret = PTR_ERR(ca->thread);
pr_err("dvb_ca_init: failed to start kernel_thread (%d)\n",
ret);
goto unregister_device;
}
return 0;
unregister_device:
dvb_unregister_device(ca->dvbdev);
free_slot_info:
kfree(ca->slot_info);
free_ca:
kfree(ca);
exit:
pubca->private = NULL;
return ret;
}
void dvb_ca_en50221_release(struct dvb_ca_en50221 *pubca)
{
struct dvb_ca_private *ca = pubca->private;
int i;
dprintk("%s\n", __func__);
kthread_stop(ca->thread);
for (i = 0; i < ca->slot_count; i++) {
dvb_ca_en50221_slot_shutdown(ca, i);
}
dvb_remove_device(ca->dvbdev);
dvb_ca_private_put(ca);
pubca->private = NULL;
}
