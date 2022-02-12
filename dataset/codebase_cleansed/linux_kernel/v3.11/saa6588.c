static inline struct saa6588 *to_saa6588(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa6588, sd);
}
static int block_to_user_buf(struct saa6588 *s, unsigned char __user *user_buf)
{
int i;
if (s->rd_index == s->wr_index) {
if (debug > 2)
dprintk(PREFIX "Read: buffer empty.\n");
return 0;
}
if (debug > 2) {
dprintk(PREFIX "Read: ");
for (i = s->rd_index; i < s->rd_index + 3; i++)
dprintk("0x%02x ", s->buffer[i]);
}
if (copy_to_user(user_buf, &s->buffer[s->rd_index], 3))
return -EFAULT;
s->rd_index += 3;
if (s->rd_index >= s->buf_size)
s->rd_index = 0;
s->block_count--;
if (debug > 2)
dprintk("%d blocks total.\n", s->block_count);
return 1;
}
static void read_from_buf(struct saa6588 *s, struct saa6588_command *a)
{
unsigned long flags;
unsigned char __user *buf_ptr = a->buffer;
unsigned int i;
unsigned int rd_blocks;
a->result = 0;
if (!a->buffer)
return;
while (!s->data_available_for_read) {
int ret = wait_event_interruptible(s->read_queue,
s->data_available_for_read);
if (ret == -ERESTARTSYS) {
a->result = -EINTR;
return;
}
}
spin_lock_irqsave(&s->lock, flags);
rd_blocks = a->block_count;
if (rd_blocks > s->block_count)
rd_blocks = s->block_count;
if (!rd_blocks) {
spin_unlock_irqrestore(&s->lock, flags);
return;
}
for (i = 0; i < rd_blocks; i++) {
if (block_to_user_buf(s, buf_ptr)) {
buf_ptr += 3;
a->result++;
} else
break;
}
a->result *= 3;
s->data_available_for_read = (s->block_count > 0);
spin_unlock_irqrestore(&s->lock, flags);
}
static void block_to_buf(struct saa6588 *s, unsigned char *blockbuf)
{
unsigned int i;
if (debug > 3)
dprintk(PREFIX "New block: ");
for (i = 0; i < 3; ++i) {
if (debug > 3)
dprintk("0x%02x ", blockbuf[i]);
s->buffer[s->wr_index] = blockbuf[i];
s->wr_index++;
}
if (s->wr_index >= s->buf_size)
s->wr_index = 0;
if (s->wr_index == s->rd_index) {
s->rd_index += 3;
if (s->rd_index >= s->buf_size)
s->rd_index = 0;
} else
s->block_count++;
if (debug > 3)
dprintk("%d blocks total.\n", s->block_count);
}
static void saa6588_i2c_poll(struct saa6588 *s)
{
struct i2c_client *client = v4l2_get_subdevdata(&s->sd);
unsigned long flags;
unsigned char tmpbuf[6];
unsigned char blocknum;
unsigned char tmp;
if (6 != i2c_master_recv(client, &tmpbuf[0], 6)) {
if (debug > 1)
dprintk(PREFIX "read error!\n");
return;
}
s->sync = tmpbuf[0] & 0x10;
if (!s->sync)
return;
blocknum = tmpbuf[0] >> 5;
if (blocknum == s->last_blocknum) {
if (debug > 3)
dprintk("Saw block %d again.\n", blocknum);
return;
}
s->last_blocknum = blocknum;
tmp = tmpbuf[2];
tmpbuf[2] = tmpbuf[0];
tmpbuf[0] = tmp;
if (blocknum == 6)
blocknum = V4L2_RDS_BLOCK_INVALID;
else if (!mmbs && blocknum == 5)
blocknum = V4L2_RDS_BLOCK_INVALID;
tmp = blocknum;
tmp |= blocknum << 3;
if ((tmpbuf[2] & 0x03) == 0x03)
tmp |= V4L2_RDS_BLOCK_ERROR;
else if ((tmpbuf[2] & 0x03) != 0x00)
tmp |= V4L2_RDS_BLOCK_CORRECTED;
tmpbuf[2] = tmp;
spin_lock_irqsave(&s->lock, flags);
block_to_buf(s, tmpbuf);
spin_unlock_irqrestore(&s->lock, flags);
s->data_available_for_read = 1;
wake_up_interruptible(&s->read_queue);
}
static void saa6588_work(struct work_struct *work)
{
struct saa6588 *s = container_of(work, struct saa6588, work.work);
saa6588_i2c_poll(s);
schedule_delayed_work(&s->work, msecs_to_jiffies(20));
}
static void saa6588_configure(struct saa6588 *s)
{
struct i2c_client *client = v4l2_get_subdevdata(&s->sd);
unsigned char buf[3];
int rc;
buf[0] = cSyncRestart;
if (mmbs)
buf[0] |= cProcessingModeRBDS;
buf[1] = cFlywheelDefault;
switch (plvl) {
case 0:
buf[1] |= cPauseLevel_11mV;
break;
case 1:
buf[1] |= cPauseLevel_17mV;
break;
case 2:
buf[1] |= cPauseLevel_27mV;
break;
case 3:
buf[1] |= cPauseLevel_43mV;
break;
default:
break;
}
buf[2] = cQualityDetectDefault | cSelectOscFreqON;
switch (xtal) {
case 0:
buf[2] |= cOscFreq_4332kHz;
break;
case 1:
buf[2] |= cOscFreq_8664kHz;
break;
case 2:
buf[2] |= cOscFreq_12996kHz;
break;
case 3:
buf[2] |= cOscFreq_17328kHz;
break;
default:
break;
}
dprintk(PREFIX "writing: 0w=0x%02x 1w=0x%02x 2w=0x%02x\n",
buf[0], buf[1], buf[2]);
rc = i2c_master_send(client, buf, 3);
if (rc != 3)
printk(PREFIX "i2c i/o error: rc == %d (should be 3)\n", rc);
}
static long saa6588_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
struct saa6588 *s = to_saa6588(sd);
struct saa6588_command *a = arg;
switch (cmd) {
case SAA6588_CMD_OPEN:
a->result = 0;
break;
case SAA6588_CMD_CLOSE:
s->data_available_for_read = 1;
wake_up_interruptible(&s->read_queue);
a->result = 0;
break;
case SAA6588_CMD_READ:
read_from_buf(s, a);
break;
case SAA6588_CMD_POLL:
a->result = 0;
if (s->data_available_for_read) {
a->result |= POLLIN | POLLRDNORM;
}
poll_wait(a->instance, &s->read_queue, a->event_list);
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int saa6588_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct saa6588 *s = to_saa6588(sd);
vt->capability |= V4L2_TUNER_CAP_RDS | V4L2_TUNER_CAP_RDS_BLOCK_IO;
if (s->sync)
vt->rxsubchans |= V4L2_TUNER_SUB_RDS;
return 0;
}
static int saa6588_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *vt)
{
struct saa6588 *s = to_saa6588(sd);
saa6588_configure(s);
return 0;
}
static int saa6588_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct saa6588 *s;
struct v4l2_subdev *sd;
v4l_info(client, "saa6588 found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
s = devm_kzalloc(&client->dev, sizeof(*s), GFP_KERNEL);
if (s == NULL)
return -ENOMEM;
s->buf_size = bufblocks * 3;
s->buffer = devm_kzalloc(&client->dev, s->buf_size, GFP_KERNEL);
if (s->buffer == NULL)
return -ENOMEM;
sd = &s->sd;
v4l2_i2c_subdev_init(sd, client, &saa6588_ops);
spin_lock_init(&s->lock);
s->block_count = 0;
s->wr_index = 0;
s->rd_index = 0;
s->last_blocknum = 0xff;
init_waitqueue_head(&s->read_queue);
s->data_available_for_read = 0;
saa6588_configure(s);
INIT_DELAYED_WORK(&s->work, saa6588_work);
schedule_delayed_work(&s->work, 0);
return 0;
}
static int saa6588_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct saa6588 *s = to_saa6588(sd);
v4l2_device_unregister_subdev(sd);
cancel_delayed_work_sync(&s->work);
return 0;
}
