static inline int read_lpstatus(struct qcam *q)
{
return parport_read_status(q->pport);
}
static inline int read_lpdata(struct qcam *q)
{
return parport_read_data(q->pport);
}
static inline void write_lpdata(struct qcam *q, int d)
{
parport_write_data(q->pport, d);
}
static void write_lpcontrol(struct qcam *q, int d)
{
if (d & 0x20) {
parport_data_reverse(q->pport);
} else {
parport_data_forward(q->pport);
}
d &= ~0x20;
parport_write_control(q->pport, d);
}
static int qc_waithand(struct qcam *q, int val)
{
int status;
int runs = 0;
if (val) {
while (!((status = read_lpstatus(q)) & 8)) {
if (runs++ > maxpoll)
msleep_interruptible(5);
if (runs > (maxpoll + 1000))
return -1;
}
} else {
while (((status = read_lpstatus(q)) & 8)) {
if (runs++ > maxpoll)
msleep_interruptible(5);
if (runs++ > (maxpoll + 1000))
return -1;
}
}
return status;
}
static unsigned int qc_waithand2(struct qcam *q, int val)
{
unsigned int status;
int runs = 0;
do {
status = read_lpdata(q);
if (runs++ > maxpoll)
msleep_interruptible(5);
if (runs++ > (maxpoll + 1000))
return 0;
} while ((status & 1) != val);
return status;
}
static int qc_command(struct qcam *q, int command)
{
int n1, n2;
int cmd;
write_lpdata(q, command);
write_lpcontrol(q, 6);
n1 = qc_waithand(q, 1);
write_lpcontrol(q, 0xe);
n2 = qc_waithand(q, 0);
cmd = (n1 & 0xf0) | ((n2 & 0xf0) >> 4);
return cmd;
}
static int qc_readparam(struct qcam *q)
{
int n1, n2;
int cmd;
write_lpcontrol(q, 6);
n1 = qc_waithand(q, 1);
write_lpcontrol(q, 0xe);
n2 = qc_waithand(q, 0);
cmd = (n1 & 0xf0) | ((n2 & 0xf0) >> 4);
return cmd;
}
static int qc_detect(struct qcam *q)
{
int reg, lastreg;
int count = 0;
int i;
if (force_init)
return 1;
lastreg = reg = read_lpstatus(q) & 0xf0;
for (i = 0; i < 500; i++) {
reg = read_lpstatus(q) & 0xf0;
if (reg != lastreg)
count++;
lastreg = reg;
mdelay(2);
}
#if 0
printk(KERN_DEBUG "Debugging: QCam detection counter <30-200 counts as detected>: %d\n", count);
return 1;
#endif
if (count > 20 && count < 400) {
return 1;
} else {
printk(KERN_ERR "No Quickcam found on port %s\n",
q->pport->name);
printk(KERN_DEBUG "Quickcam detection counter: %u\n", count);
return 0;
}
}
static int qc_setscanmode(struct qcam *q)
{
int old_mode = q->mode;
switch (q->transfer_scale) {
case 1:
q->mode = 0;
break;
case 2:
q->mode = 4;
break;
case 4:
q->mode = 8;
break;
}
switch (q->bpp) {
case 4:
break;
case 6:
q->mode += 2;
break;
}
switch (q->port_mode & QC_MODE_MASK) {
case QC_BIDIR:
q->mode += 1;
break;
case QC_NOTSET:
case QC_UNIDIR:
break;
}
if (q->mode != old_mode)
q->status |= QC_PARAM_CHANGE;
return 0;
}
static void qc_reset(struct qcam *q)
{
switch (q->port_mode & QC_FORCE_MASK) {
case QC_FORCE_UNIDIR:
q->port_mode = (q->port_mode & ~QC_MODE_MASK) | QC_UNIDIR;
break;
case QC_FORCE_BIDIR:
q->port_mode = (q->port_mode & ~QC_MODE_MASK) | QC_BIDIR;
break;
case QC_ANY:
write_lpcontrol(q, 0x20);
write_lpdata(q, 0x75);
if (read_lpdata(q) != 0x75)
q->port_mode = (q->port_mode & ~QC_MODE_MASK) | QC_BIDIR;
else
q->port_mode = (q->port_mode & ~QC_MODE_MASK) | QC_UNIDIR;
break;
}
write_lpcontrol(q, 0xb);
udelay(250);
write_lpcontrol(q, 0xe);
qc_setscanmode(q);
}
static void qc_set(struct qcam *q)
{
int val;
int val2;
qc_reset(q);
qc_command(q, 0xb);
qc_command(q, q->brightness);
val = q->height / q->transfer_scale;
qc_command(q, 0x11);
qc_command(q, val);
if ((q->port_mode & QC_MODE_MASK) == QC_UNIDIR && q->bpp == 6) {
val = q->width;
val2 = q->transfer_scale * 4;
} else {
val = q->width * q->bpp;
val2 = (((q->port_mode & QC_MODE_MASK) == QC_BIDIR) ? 24 : 8) *
q->transfer_scale;
}
val = DIV_ROUND_UP(val, val2);
qc_command(q, 0x13);
qc_command(q, val);
qc_command(q, 0xd);
qc_command(q, q->top);
qc_command(q, 0xf);
qc_command(q, q->left / 2);
qc_command(q, 0x19);
qc_command(q, q->contrast);
qc_command(q, 0x1f);
qc_command(q, q->whitebal);
q->status &= (~QC_PARAM_CHANGE);
}
static inline int qc_readbytes(struct qcam *q, char buffer[])
{
int ret = 1;
unsigned int hi, lo;
unsigned int hi2, lo2;
static int state;
if (buffer == NULL) {
state = 0;
return 0;
}
switch (q->port_mode & QC_MODE_MASK) {
case QC_BIDIR:
write_lpcontrol(q, 0x26);
lo = (qc_waithand2(q, 1) >> 1);
hi = (read_lpstatus(q) >> 3) & 0x1f;
write_lpcontrol(q, 0x2e);
lo2 = (qc_waithand2(q, 0) >> 1);
hi2 = (read_lpstatus(q) >> 3) & 0x1f;
switch (q->bpp) {
case 4:
buffer[0] = lo & 0xf;
buffer[1] = ((lo & 0x70) >> 4) | ((hi & 1) << 3);
buffer[2] = (hi & 0x1e) >> 1;
buffer[3] = lo2 & 0xf;
buffer[4] = ((lo2 & 0x70) >> 4) | ((hi2 & 1) << 3);
buffer[5] = (hi2 & 0x1e) >> 1;
ret = 6;
break;
case 6:
buffer[0] = lo & 0x3f;
buffer[1] = ((lo & 0x40) >> 6) | (hi << 1);
buffer[2] = lo2 & 0x3f;
buffer[3] = ((lo2 & 0x40) >> 6) | (hi2 << 1);
ret = 4;
break;
}
break;
case QC_UNIDIR:
write_lpcontrol(q, 6);
lo = (qc_waithand(q, 1) & 0xf0) >> 4;
write_lpcontrol(q, 0xe);
hi = (qc_waithand(q, 0) & 0xf0) >> 4;
switch (q->bpp) {
case 4:
buffer[0] = lo;
buffer[1] = hi;
ret = 2;
break;
case 6:
switch (state) {
case 0:
buffer[0] = (lo << 2) | ((hi & 0xc) >> 2);
q->saved_bits = (hi & 3) << 4;
state = 1;
ret = 1;
break;
case 1:
buffer[0] = lo | q->saved_bits;
q->saved_bits = hi << 2;
state = 2;
ret = 1;
break;
case 2:
buffer[0] = ((lo & 0xc) >> 2) | q->saved_bits;
buffer[1] = ((lo & 3) << 4) | hi;
state = 0;
ret = 2;
break;
}
break;
}
break;
}
return ret;
}
static long qc_capture(struct qcam *q, char __user *buf, unsigned long len)
{
int i, j, k, yield;
int bytes;
int linestotrans, transperline;
int divisor;
int pixels_per_line;
int pixels_read = 0;
int got = 0;
char buffer[6];
int shift = 8 - q->bpp;
char invert;
if (q->mode == -1)
return -ENXIO;
qc_command(q, 0x7);
qc_command(q, q->mode);
if ((q->port_mode & QC_MODE_MASK) == QC_BIDIR) {
write_lpcontrol(q, 0x2e);
write_lpcontrol(q, 0x26);
qc_waithand(q, 1);
write_lpcontrol(q, 0x2e);
qc_waithand(q, 0);
}
invert = (q->bpp == 4) ? 16 : 63;
linestotrans = q->height / q->transfer_scale;
pixels_per_line = q->width / q->transfer_scale;
transperline = q->width * q->bpp;
divisor = (((q->port_mode & QC_MODE_MASK) == QC_BIDIR) ? 24 : 8) *
q->transfer_scale;
transperline = DIV_ROUND_UP(transperline, divisor);
for (i = 0, yield = yieldlines; i < linestotrans; i++) {
for (pixels_read = j = 0; j < transperline; j++) {
bytes = qc_readbytes(q, buffer);
for (k = 0; k < bytes && (pixels_read + k) < pixels_per_line; k++) {
int o;
if (buffer[k] == 0 && invert == 16) {
buffer[k] = 16;
}
o = i * pixels_per_line + pixels_read + k;
if (o < len) {
got++;
put_user((invert - buffer[k]) << shift, buf + o);
}
}
pixels_read += bytes;
}
qc_readbytes(q, NULL);
if (i >= yield) {
msleep_interruptible(5);
yield = i + yieldlines;
}
}
if ((q->port_mode & QC_MODE_MASK) == QC_BIDIR) {
write_lpcontrol(q, 2);
write_lpcontrol(q, 6);
udelay(3);
write_lpcontrol(q, 0xe);
}
if (got < len)
return got;
return len;
}
static int qcam_querycap(struct file *file, void *priv,
struct v4l2_capability *vcap)
{
struct qcam *qcam = video_drvdata(file);
strlcpy(vcap->driver, qcam->v4l2_dev.name, sizeof(vcap->driver));
strlcpy(vcap->card, "B&W Quickcam", sizeof(vcap->card));
strlcpy(vcap->bus_info, "parport", sizeof(vcap->bus_info));
vcap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_READWRITE;
return 0;
}
static int qcam_enum_input(struct file *file, void *fh, struct v4l2_input *vin)
{
if (vin->index > 0)
return -EINVAL;
strlcpy(vin->name, "Camera", sizeof(vin->name));
vin->type = V4L2_INPUT_TYPE_CAMERA;
vin->audioset = 0;
vin->tuner = 0;
vin->std = 0;
vin->status = 0;
return 0;
}
static int qcam_g_input(struct file *file, void *fh, unsigned int *inp)
{
*inp = 0;
return 0;
}
static int qcam_s_input(struct file *file, void *fh, unsigned int inp)
{
return (inp > 0) ? -EINVAL : 0;
}
static int qcam_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_BRIGHTNESS:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 180);
case V4L2_CID_CONTRAST:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 192);
case V4L2_CID_GAMMA:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 105);
}
return -EINVAL;
}
static int qcam_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct qcam *qcam = video_drvdata(file);
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ctrl->value = qcam->brightness;
break;
case V4L2_CID_CONTRAST:
ctrl->value = qcam->contrast;
break;
case V4L2_CID_GAMMA:
ctrl->value = qcam->whitebal;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int qcam_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct qcam *qcam = video_drvdata(file);
int ret = 0;
mutex_lock(&qcam->lock);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
qcam->brightness = ctrl->value;
break;
case V4L2_CID_CONTRAST:
qcam->contrast = ctrl->value;
break;
case V4L2_CID_GAMMA:
qcam->whitebal = ctrl->value;
break;
default:
ret = -EINVAL;
break;
}
if (ret == 0) {
qc_setscanmode(qcam);
qcam->status |= QC_PARAM_CHANGE;
}
mutex_unlock(&qcam->lock);
return ret;
}
static int qcam_g_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *fmt)
{
struct qcam *qcam = video_drvdata(file);
struct v4l2_pix_format *pix = &fmt->fmt.pix;
pix->width = qcam->width / qcam->transfer_scale;
pix->height = qcam->height / qcam->transfer_scale;
pix->pixelformat = (qcam->bpp == 4) ? V4L2_PIX_FMT_Y4 : V4L2_PIX_FMT_Y6;
pix->field = V4L2_FIELD_NONE;
pix->bytesperline = qcam->width;
pix->sizeimage = qcam->width * qcam->height;
pix->colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int qcam_try_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *fmt)
{
struct v4l2_pix_format *pix = &fmt->fmt.pix;
if (pix->height <= 60 || pix->width <= 80) {
pix->height = 60;
pix->width = 80;
} else if (pix->height <= 120 || pix->width <= 160) {
pix->height = 120;
pix->width = 160;
} else {
pix->height = 240;
pix->width = 320;
}
if (pix->pixelformat != V4L2_PIX_FMT_Y4 &&
pix->pixelformat != V4L2_PIX_FMT_Y6)
pix->pixelformat = V4L2_PIX_FMT_Y4;
pix->field = V4L2_FIELD_NONE;
pix->bytesperline = pix->width;
pix->sizeimage = pix->width * pix->height;
pix->colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int qcam_s_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *fmt)
{
struct qcam *qcam = video_drvdata(file);
struct v4l2_pix_format *pix = &fmt->fmt.pix;
int ret = qcam_try_fmt_vid_cap(file, fh, fmt);
if (ret)
return ret;
qcam->width = 320;
qcam->height = 240;
if (pix->height == 60)
qcam->transfer_scale = 4;
else if (pix->height == 120)
qcam->transfer_scale = 2;
else
qcam->transfer_scale = 1;
if (pix->pixelformat == V4L2_PIX_FMT_Y6)
qcam->bpp = 6;
else
qcam->bpp = 4;
mutex_lock(&qcam->lock);
qc_setscanmode(qcam);
qcam->status |= QC_PARAM_CHANGE;
mutex_unlock(&qcam->lock);
return 0;
}
static int qcam_enum_fmt_vid_cap(struct file *file, void *fh, struct v4l2_fmtdesc *fmt)
{
static struct v4l2_fmtdesc formats[] = {
{ 0, 0, 0,
"4-Bit Monochrome", V4L2_PIX_FMT_Y4,
{ 0, 0, 0, 0 }
},
{ 0, 0, 0,
"6-Bit Monochrome", V4L2_PIX_FMT_Y6,
{ 0, 0, 0, 0 }
},
};
enum v4l2_buf_type type = fmt->type;
if (fmt->index > 1)
return -EINVAL;
*fmt = formats[fmt->index];
fmt->type = type;
return 0;
}
static ssize_t qcam_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct qcam *qcam = video_drvdata(file);
int len;
parport_claim_or_block(qcam->pdev);
mutex_lock(&qcam->lock);
qc_reset(qcam);
if (qcam->status & QC_PARAM_CHANGE)
qc_set(qcam);
len = qc_capture(qcam, buf, count);
mutex_unlock(&qcam->lock);
parport_release(qcam->pdev);
return len;
}
static struct qcam *qcam_init(struct parport *port)
{
struct qcam *qcam;
struct v4l2_device *v4l2_dev;
qcam = kzalloc(sizeof(struct qcam), GFP_KERNEL);
if (qcam == NULL)
return NULL;
v4l2_dev = &qcam->v4l2_dev;
strlcpy(v4l2_dev->name, "bw-qcam", sizeof(v4l2_dev->name));
if (v4l2_device_register(NULL, v4l2_dev) < 0) {
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
kfree(qcam);
return NULL;
}
qcam->pport = port;
qcam->pdev = parport_register_device(port, "bw-qcam", NULL, NULL,
NULL, 0, NULL);
if (qcam->pdev == NULL) {
v4l2_err(v4l2_dev, "couldn't register for %s.\n", port->name);
kfree(qcam);
return NULL;
}
strlcpy(qcam->vdev.name, "Connectix QuickCam", sizeof(qcam->vdev.name));
qcam->vdev.v4l2_dev = v4l2_dev;
qcam->vdev.fops = &qcam_fops;
qcam->vdev.ioctl_ops = &qcam_ioctl_ops;
qcam->vdev.release = video_device_release_empty;
video_set_drvdata(&qcam->vdev, qcam);
mutex_init(&qcam->lock);
qcam->port_mode = (QC_ANY | QC_NOTSET);
qcam->width = 320;
qcam->height = 240;
qcam->bpp = 4;
qcam->transfer_scale = 2;
qcam->contrast = 192;
qcam->brightness = 180;
qcam->whitebal = 105;
qcam->top = 1;
qcam->left = 14;
qcam->mode = -1;
qcam->status = QC_PARAM_CHANGE;
return qcam;
}
static int qc_calibrate(struct qcam *q)
{
int value;
int count = 0;
qc_command(q, 27);
qc_command(q, 0);
do {
qc_command(q, 33);
value = qc_readparam(q);
mdelay(1);
schedule();
count++;
} while (value == 0xff && count < 2048);
q->whitebal = value;
return value;
}
static int init_bwqcam(struct parport *port)
{
struct qcam *qcam;
if (num_cams == MAX_CAMS) {
printk(KERN_ERR "Too many Quickcams (max %d)\n", MAX_CAMS);
return -ENOSPC;
}
qcam = qcam_init(port);
if (qcam == NULL)
return -ENODEV;
parport_claim_or_block(qcam->pdev);
qc_reset(qcam);
if (qc_detect(qcam) == 0) {
parport_release(qcam->pdev);
parport_unregister_device(qcam->pdev);
kfree(qcam);
return -ENODEV;
}
qc_calibrate(qcam);
parport_release(qcam->pdev);
v4l2_info(&qcam->v4l2_dev, "Connectix Quickcam on %s\n", qcam->pport->name);
if (video_register_device(&qcam->vdev, VFL_TYPE_GRABBER, video_nr) < 0) {
parport_unregister_device(qcam->pdev);
kfree(qcam);
return -ENODEV;
}
qcams[num_cams++] = qcam;
return 0;
}
static void close_bwqcam(struct qcam *qcam)
{
video_unregister_device(&qcam->vdev);
parport_unregister_device(qcam->pdev);
kfree(qcam);
}
static int accept_bwqcam(struct parport *port)
{
#ifdef MODULE
int n;
if (parport[0] && strncmp(parport[0], "auto", 4) != 0) {
for (n = 0; n < MAX_CAMS && parport[n]; n++) {
char *ep;
unsigned long r;
r = simple_strtoul(parport[n], &ep, 0);
if (ep == parport[n]) {
printk(KERN_ERR
"bw-qcam: bad port specifier \"%s\"\n",
parport[n]);
continue;
}
if (r == port->number)
return 1;
}
return 0;
}
#endif
return 1;
}
static void bwqcam_attach(struct parport *port)
{
if (accept_bwqcam(port))
init_bwqcam(port);
}
static void bwqcam_detach(struct parport *port)
{
int i;
for (i = 0; i < num_cams; i++) {
struct qcam *qcam = qcams[i];
if (qcam && qcam->pdev->port == port) {
qcams[i] = NULL;
close_bwqcam(qcam);
}
}
}
static void __exit exit_bw_qcams(void)
{
parport_unregister_driver(&bwqcam_driver);
}
static int __init init_bw_qcams(void)
{
#ifdef MODULE
if (maxpoll > 5000) {
printk(KERN_INFO "Connectix Quickcam max-poll was above 5000. Using 5000.\n");
maxpoll = 5000;
}
if (yieldlines < 1) {
printk(KERN_INFO "Connectix Quickcam yieldlines was less than 1. Using 1.\n");
yieldlines = 1;
}
#endif
return parport_register_driver(&bwqcam_driver);
}
