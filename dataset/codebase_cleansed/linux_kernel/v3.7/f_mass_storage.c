static inline int __fsg_is_set(struct fsg_common *common,
const char *func, unsigned line)
{
if (common->fsg)
return 1;
ERROR(common, "common->fsg is NULL in %s at %u\n", func, line);
WARN_ON(1);
return 0;
}
static inline struct fsg_dev *fsg_from_func(struct usb_function *f)
{
return container_of(f, struct fsg_dev, function);
}
static int exception_in_progress(struct fsg_common *common)
{
return common->state > FSG_STATE_IDLE;
}
static void set_bulk_out_req_length(struct fsg_common *common,
struct fsg_buffhd *bh, unsigned int length)
{
unsigned int rem;
bh->bulk_out_intended_length = length;
rem = length % common->bulk_out_maxpacket;
if (rem > 0)
length += common->bulk_out_maxpacket - rem;
bh->outreq->length = length;
}
static int fsg_set_halt(struct fsg_dev *fsg, struct usb_ep *ep)
{
const char *name;
if (ep == fsg->bulk_in)
name = "bulk-in";
else if (ep == fsg->bulk_out)
name = "bulk-out";
else
name = ep->name;
DBG(fsg, "%s set halt\n", name);
return usb_ep_set_halt(ep);
}
static void wakeup_thread(struct fsg_common *common)
{
common->thread_wakeup_needed = 1;
if (common->thread_task)
wake_up_process(common->thread_task);
}
static void raise_exception(struct fsg_common *common, enum fsg_state new_state)
{
unsigned long flags;
spin_lock_irqsave(&common->lock, flags);
if (common->state <= new_state) {
common->exception_req_tag = common->ep0_req_tag;
common->state = new_state;
if (common->thread_task)
send_sig_info(SIGUSR1, SEND_SIG_FORCED,
common->thread_task);
}
spin_unlock_irqrestore(&common->lock, flags);
}
static int ep0_queue(struct fsg_common *common)
{
int rc;
rc = usb_ep_queue(common->ep0, common->ep0req, GFP_ATOMIC);
common->ep0->driver_data = common;
if (rc != 0 && rc != -ESHUTDOWN) {
WARNING(common, "error in submission: %s --> %d\n",
common->ep0->name, rc);
}
return rc;
}
static void bulk_in_complete(struct usb_ep *ep, struct usb_request *req)
{
struct fsg_common *common = ep->driver_data;
struct fsg_buffhd *bh = req->context;
if (req->status || req->actual != req->length)
DBG(common, "%s --> %d, %u/%u\n", __func__,
req->status, req->actual, req->length);
if (req->status == -ECONNRESET)
usb_ep_fifo_flush(ep);
smp_wmb();
spin_lock(&common->lock);
bh->inreq_busy = 0;
bh->state = BUF_STATE_EMPTY;
wakeup_thread(common);
spin_unlock(&common->lock);
}
static void bulk_out_complete(struct usb_ep *ep, struct usb_request *req)
{
struct fsg_common *common = ep->driver_data;
struct fsg_buffhd *bh = req->context;
dump_msg(common, "bulk-out", req->buf, req->actual);
if (req->status || req->actual != bh->bulk_out_intended_length)
DBG(common, "%s --> %d, %u/%u\n", __func__,
req->status, req->actual, bh->bulk_out_intended_length);
if (req->status == -ECONNRESET)
usb_ep_fifo_flush(ep);
smp_wmb();
spin_lock(&common->lock);
bh->outreq_busy = 0;
bh->state = BUF_STATE_FULL;
wakeup_thread(common);
spin_unlock(&common->lock);
}
static int fsg_setup(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct fsg_dev *fsg = fsg_from_func(f);
struct usb_request *req = fsg->common->ep0req;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
if (!fsg_is_set(fsg->common))
return -EOPNOTSUPP;
++fsg->common->ep0_req_tag;
req->context = NULL;
req->length = 0;
dump_msg(fsg, "ep0-setup", (u8 *) ctrl, sizeof(*ctrl));
switch (ctrl->bRequest) {
case US_BULK_RESET_REQUEST:
if (ctrl->bRequestType !=
(USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE))
break;
if (w_index != fsg->interface_number || w_value != 0 ||
w_length != 0)
return -EDOM;
DBG(fsg, "bulk reset request\n");
raise_exception(fsg->common, FSG_STATE_RESET);
return DELAYED_STATUS;
case US_BULK_GET_MAX_LUN:
if (ctrl->bRequestType !=
(USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE))
break;
if (w_index != fsg->interface_number || w_value != 0 ||
w_length != 1)
return -EDOM;
VDBG(fsg, "get max LUN\n");
*(u8 *)req->buf = fsg->common->nluns - 1;
req->length = min((u16)1, w_length);
return ep0_queue(fsg->common);
}
VDBG(fsg,
"unknown class-specific control req %02x.%02x v%04x i%04x l%u\n",
ctrl->bRequestType, ctrl->bRequest,
le16_to_cpu(ctrl->wValue), w_index, w_length);
return -EOPNOTSUPP;
}
static void start_transfer(struct fsg_dev *fsg, struct usb_ep *ep,
struct usb_request *req, int *pbusy,
enum fsg_buffer_state *state)
{
int rc;
if (ep == fsg->bulk_in)
dump_msg(fsg, "bulk-in", req->buf, req->length);
spin_lock_irq(&fsg->common->lock);
*pbusy = 1;
*state = BUF_STATE_BUSY;
spin_unlock_irq(&fsg->common->lock);
rc = usb_ep_queue(ep, req, GFP_KERNEL);
if (rc != 0) {
*pbusy = 0;
*state = BUF_STATE_EMPTY;
if (rc != -ESHUTDOWN &&
!(rc == -EOPNOTSUPP && req->length == 0))
WARNING(fsg, "error in submission: %s --> %d\n",
ep->name, rc);
}
}
static bool start_in_transfer(struct fsg_common *common, struct fsg_buffhd *bh)
{
if (!fsg_is_set(common))
return false;
start_transfer(common->fsg, common->fsg->bulk_in,
bh->inreq, &bh->inreq_busy, &bh->state);
return true;
}
static bool start_out_transfer(struct fsg_common *common, struct fsg_buffhd *bh)
{
if (!fsg_is_set(common))
return false;
start_transfer(common->fsg, common->fsg->bulk_out,
bh->outreq, &bh->outreq_busy, &bh->state);
return true;
}
static int sleep_thread(struct fsg_common *common)
{
int rc = 0;
for (;;) {
try_to_freeze();
set_current_state(TASK_INTERRUPTIBLE);
if (signal_pending(current)) {
rc = -EINTR;
break;
}
if (common->thread_wakeup_needed)
break;
schedule();
}
__set_current_state(TASK_RUNNING);
common->thread_wakeup_needed = 0;
return rc;
}
static int do_read(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
u32 lba;
struct fsg_buffhd *bh;
int rc;
u32 amount_left;
loff_t file_offset, file_offset_tmp;
unsigned int amount;
ssize_t nread;
if (common->cmnd[0] == READ_6)
lba = get_unaligned_be24(&common->cmnd[1]);
else {
lba = get_unaligned_be32(&common->cmnd[2]);
if ((common->cmnd[1] & ~0x18) != 0) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
}
if (lba >= curlun->num_sectors) {
curlun->sense_data = SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
return -EINVAL;
}
file_offset = ((loff_t) lba) << curlun->blkbits;
amount_left = common->data_size_from_cmnd;
if (unlikely(amount_left == 0))
return -EIO;
for (;;) {
amount = min(amount_left, FSG_BUFLEN);
amount = min((loff_t)amount,
curlun->file_length - file_offset);
bh = common->next_buffhd_to_fill;
while (bh->state != BUF_STATE_EMPTY) {
rc = sleep_thread(common);
if (rc)
return rc;
}
if (amount == 0) {
curlun->sense_data =
SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
curlun->sense_data_info =
file_offset >> curlun->blkbits;
curlun->info_valid = 1;
bh->inreq->length = 0;
bh->state = BUF_STATE_FULL;
break;
}
file_offset_tmp = file_offset;
nread = vfs_read(curlun->filp,
(char __user *)bh->buf,
amount, &file_offset_tmp);
VLDBG(curlun, "file read %u @ %llu -> %d\n", amount,
(unsigned long long)file_offset, (int)nread);
if (signal_pending(current))
return -EINTR;
if (nread < 0) {
LDBG(curlun, "error in file read: %d\n", (int)nread);
nread = 0;
} else if (nread < amount) {
LDBG(curlun, "partial file read: %d/%u\n",
(int)nread, amount);
nread = round_down(nread, curlun->blksize);
}
file_offset += nread;
amount_left -= nread;
common->residue -= nread;
bh->inreq->length = nread;
bh->state = BUF_STATE_FULL;
if (nread < amount) {
curlun->sense_data = SS_UNRECOVERED_READ_ERROR;
curlun->sense_data_info =
file_offset >> curlun->blkbits;
curlun->info_valid = 1;
break;
}
if (amount_left == 0)
break;
bh->inreq->zero = 0;
if (!start_in_transfer(common, bh))
return -EIO;
common->next_buffhd_to_fill = bh->next;
}
return -EIO;
}
static int do_write(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
u32 lba;
struct fsg_buffhd *bh;
int get_some_more;
u32 amount_left_to_req, amount_left_to_write;
loff_t usb_offset, file_offset, file_offset_tmp;
unsigned int amount;
ssize_t nwritten;
int rc;
if (curlun->ro) {
curlun->sense_data = SS_WRITE_PROTECTED;
return -EINVAL;
}
spin_lock(&curlun->filp->f_lock);
curlun->filp->f_flags &= ~O_SYNC;
spin_unlock(&curlun->filp->f_lock);
if (common->cmnd[0] == WRITE_6)
lba = get_unaligned_be24(&common->cmnd[1]);
else {
lba = get_unaligned_be32(&common->cmnd[2]);
if (common->cmnd[1] & ~0x18) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
if (!curlun->nofua && (common->cmnd[1] & 0x08)) {
spin_lock(&curlun->filp->f_lock);
curlun->filp->f_flags |= O_SYNC;
spin_unlock(&curlun->filp->f_lock);
}
}
if (lba >= curlun->num_sectors) {
curlun->sense_data = SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
return -EINVAL;
}
get_some_more = 1;
file_offset = usb_offset = ((loff_t) lba) << curlun->blkbits;
amount_left_to_req = common->data_size_from_cmnd;
amount_left_to_write = common->data_size_from_cmnd;
while (amount_left_to_write > 0) {
bh = common->next_buffhd_to_fill;
if (bh->state == BUF_STATE_EMPTY && get_some_more) {
amount = min(amount_left_to_req, FSG_BUFLEN);
if (usb_offset >= curlun->file_length) {
get_some_more = 0;
curlun->sense_data =
SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
curlun->sense_data_info =
usb_offset >> curlun->blkbits;
curlun->info_valid = 1;
continue;
}
usb_offset += amount;
common->usb_amount_left -= amount;
amount_left_to_req -= amount;
if (amount_left_to_req == 0)
get_some_more = 0;
set_bulk_out_req_length(common, bh, amount);
if (!start_out_transfer(common, bh))
return -EIO;
common->next_buffhd_to_fill = bh->next;
continue;
}
bh = common->next_buffhd_to_drain;
if (bh->state == BUF_STATE_EMPTY && !get_some_more)
break;
if (bh->state == BUF_STATE_FULL) {
smp_rmb();
common->next_buffhd_to_drain = bh->next;
bh->state = BUF_STATE_EMPTY;
if (bh->outreq->status != 0) {
curlun->sense_data = SS_COMMUNICATION_FAILURE;
curlun->sense_data_info =
file_offset >> curlun->blkbits;
curlun->info_valid = 1;
break;
}
amount = bh->outreq->actual;
if (curlun->file_length - file_offset < amount) {
LERROR(curlun,
"write %u @ %llu beyond end %llu\n",
amount, (unsigned long long)file_offset,
(unsigned long long)curlun->file_length);
amount = curlun->file_length - file_offset;
}
amount = min(amount, bh->bulk_out_intended_length);
amount = round_down(amount, curlun->blksize);
if (amount == 0)
goto empty_write;
file_offset_tmp = file_offset;
nwritten = vfs_write(curlun->filp,
(char __user *)bh->buf,
amount, &file_offset_tmp);
VLDBG(curlun, "file write %u @ %llu -> %d\n", amount,
(unsigned long long)file_offset, (int)nwritten);
if (signal_pending(current))
return -EINTR;
if (nwritten < 0) {
LDBG(curlun, "error in file write: %d\n",
(int)nwritten);
nwritten = 0;
} else if (nwritten < amount) {
LDBG(curlun, "partial file write: %d/%u\n",
(int)nwritten, amount);
nwritten = round_down(nwritten, curlun->blksize);
}
file_offset += nwritten;
amount_left_to_write -= nwritten;
common->residue -= nwritten;
if (nwritten < amount) {
curlun->sense_data = SS_WRITE_ERROR;
curlun->sense_data_info =
file_offset >> curlun->blkbits;
curlun->info_valid = 1;
break;
}
empty_write:
if (bh->outreq->actual < bh->bulk_out_intended_length) {
common->short_packet_received = 1;
break;
}
continue;
}
rc = sleep_thread(common);
if (rc)
return rc;
}
return -EIO;
}
static int do_synchronize_cache(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
int rc;
rc = fsg_lun_fsync_sub(curlun);
if (rc)
curlun->sense_data = SS_WRITE_ERROR;
return 0;
}
static void invalidate_sub(struct fsg_lun *curlun)
{
struct file *filp = curlun->filp;
struct inode *inode = filp->f_path.dentry->d_inode;
unsigned long rc;
rc = invalidate_mapping_pages(inode->i_mapping, 0, -1);
VLDBG(curlun, "invalidate_mapping_pages -> %ld\n", rc);
}
static int do_verify(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
u32 lba;
u32 verification_length;
struct fsg_buffhd *bh = common->next_buffhd_to_fill;
loff_t file_offset, file_offset_tmp;
u32 amount_left;
unsigned int amount;
ssize_t nread;
lba = get_unaligned_be32(&common->cmnd[2]);
if (lba >= curlun->num_sectors) {
curlun->sense_data = SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
return -EINVAL;
}
if (common->cmnd[1] & ~0x10) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
verification_length = get_unaligned_be16(&common->cmnd[7]);
if (unlikely(verification_length == 0))
return -EIO;
amount_left = verification_length << curlun->blkbits;
file_offset = ((loff_t) lba) << curlun->blkbits;
fsg_lun_fsync_sub(curlun);
if (signal_pending(current))
return -EINTR;
invalidate_sub(curlun);
if (signal_pending(current))
return -EINTR;
while (amount_left > 0) {
amount = min(amount_left, FSG_BUFLEN);
amount = min((loff_t)amount,
curlun->file_length - file_offset);
if (amount == 0) {
curlun->sense_data =
SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
curlun->sense_data_info =
file_offset >> curlun->blkbits;
curlun->info_valid = 1;
break;
}
file_offset_tmp = file_offset;
nread = vfs_read(curlun->filp,
(char __user *) bh->buf,
amount, &file_offset_tmp);
VLDBG(curlun, "file read %u @ %llu -> %d\n", amount,
(unsigned long long) file_offset,
(int) nread);
if (signal_pending(current))
return -EINTR;
if (nread < 0) {
LDBG(curlun, "error in file verify: %d\n", (int)nread);
nread = 0;
} else if (nread < amount) {
LDBG(curlun, "partial file verify: %d/%u\n",
(int)nread, amount);
nread = round_down(nread, curlun->blksize);
}
if (nread == 0) {
curlun->sense_data = SS_UNRECOVERED_READ_ERROR;
curlun->sense_data_info =
file_offset >> curlun->blkbits;
curlun->info_valid = 1;
break;
}
file_offset += nread;
amount_left -= nread;
}
return 0;
}
static int do_inquiry(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
u8 *buf = (u8 *) bh->buf;
if (!curlun) {
common->bad_lun_okay = 1;
memset(buf, 0, 36);
buf[0] = 0x7f;
buf[4] = 31;
return 36;
}
buf[0] = curlun->cdrom ? TYPE_ROM : TYPE_DISK;
buf[1] = curlun->removable ? 0x80 : 0;
buf[2] = 2;
buf[3] = 2;
buf[4] = 31;
buf[5] = 0;
buf[6] = 0;
buf[7] = 0;
memcpy(buf + 8, common->inquiry_string, sizeof common->inquiry_string);
return 36;
}
static int do_request_sense(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
u8 *buf = (u8 *) bh->buf;
u32 sd, sdinfo;
int valid;
#if 0
if (curlun && curlun->unit_attention_data != SS_NO_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
}
#endif
if (!curlun) {
common->bad_lun_okay = 1;
sd = SS_LOGICAL_UNIT_NOT_SUPPORTED;
sdinfo = 0;
valid = 0;
} else {
sd = curlun->sense_data;
sdinfo = curlun->sense_data_info;
valid = curlun->info_valid << 7;
curlun->sense_data = SS_NO_SENSE;
curlun->sense_data_info = 0;
curlun->info_valid = 0;
}
memset(buf, 0, 18);
buf[0] = valid | 0x70;
buf[2] = SK(sd);
put_unaligned_be32(sdinfo, &buf[3]);
buf[7] = 18 - 8;
buf[12] = ASC(sd);
buf[13] = ASCQ(sd);
return 18;
}
static int do_read_capacity(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
u32 lba = get_unaligned_be32(&common->cmnd[2]);
int pmi = common->cmnd[8];
u8 *buf = (u8 *)bh->buf;
if (pmi > 1 || (pmi == 0 && lba != 0)) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
put_unaligned_be32(curlun->num_sectors - 1, &buf[0]);
put_unaligned_be32(curlun->blksize, &buf[4]);
return 8;
}
static int do_read_header(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
int msf = common->cmnd[1] & 0x02;
u32 lba = get_unaligned_be32(&common->cmnd[2]);
u8 *buf = (u8 *)bh->buf;
if (common->cmnd[1] & ~0x02) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
if (lba >= curlun->num_sectors) {
curlun->sense_data = SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
return -EINVAL;
}
memset(buf, 0, 8);
buf[0] = 0x01;
store_cdrom_address(&buf[4], msf, lba);
return 8;
}
static int do_read_toc(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
int msf = common->cmnd[1] & 0x02;
int start_track = common->cmnd[6];
u8 *buf = (u8 *)bh->buf;
if ((common->cmnd[1] & ~0x02) != 0 ||
start_track > 1) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
memset(buf, 0, 20);
buf[1] = (20-2);
buf[2] = 1;
buf[3] = 1;
buf[5] = 0x16;
buf[6] = 0x01;
store_cdrom_address(&buf[8], msf, 0);
buf[13] = 0x16;
buf[14] = 0xAA;
store_cdrom_address(&buf[16], msf, curlun->num_sectors);
return 20;
}
static int do_mode_sense(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
int mscmnd = common->cmnd[0];
u8 *buf = (u8 *) bh->buf;
u8 *buf0 = buf;
int pc, page_code;
int changeable_values, all_pages;
int valid_page = 0;
int len, limit;
if ((common->cmnd[1] & ~0x08) != 0) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
pc = common->cmnd[2] >> 6;
page_code = common->cmnd[2] & 0x3f;
if (pc == 3) {
curlun->sense_data = SS_SAVING_PARAMETERS_NOT_SUPPORTED;
return -EINVAL;
}
changeable_values = (pc == 1);
all_pages = (page_code == 0x3f);
memset(buf, 0, 8);
if (mscmnd == MODE_SENSE) {
buf[2] = (curlun->ro ? 0x80 : 0x00);
buf += 4;
limit = 255;
} else {
buf[3] = (curlun->ro ? 0x80 : 0x00);
buf += 8;
limit = 65535;
}
if (page_code == 0x08 || all_pages) {
valid_page = 1;
buf[0] = 0x08;
buf[1] = 10;
memset(buf+2, 0, 10);
if (!changeable_values) {
buf[2] = 0x04;
put_unaligned_be16(0xffff, &buf[4]);
put_unaligned_be16(0xffff, &buf[8]);
put_unaligned_be16(0xffff, &buf[10]);
}
buf += 12;
}
len = buf - buf0;
if (!valid_page || len > limit) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
if (mscmnd == MODE_SENSE)
buf0[0] = len - 1;
else
put_unaligned_be16(len - 2, buf0);
return len;
}
static int do_start_stop(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
int loej, start;
if (!curlun) {
return -EINVAL;
} else if (!curlun->removable) {
curlun->sense_data = SS_INVALID_COMMAND;
return -EINVAL;
} else if ((common->cmnd[1] & ~0x01) != 0 ||
(common->cmnd[4] & ~0x03) != 0) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
loej = common->cmnd[4] & 0x02;
start = common->cmnd[4] & 0x01;
if (start) {
if (!fsg_lun_is_open(curlun)) {
curlun->sense_data = SS_MEDIUM_NOT_PRESENT;
return -EINVAL;
}
return 0;
}
if (curlun->prevent_medium_removal) {
LDBG(curlun, "unload attempt prevented\n");
curlun->sense_data = SS_MEDIUM_REMOVAL_PREVENTED;
return -EINVAL;
}
if (!loej)
return 0;
if (common->ops && common->ops->pre_eject) {
int r = common->ops->pre_eject(common, curlun,
curlun - common->luns);
if (unlikely(r < 0))
return r;
else if (r)
return 0;
}
up_read(&common->filesem);
down_write(&common->filesem);
fsg_lun_close(curlun);
up_write(&common->filesem);
down_read(&common->filesem);
return common->ops && common->ops->post_eject
? min(0, common->ops->post_eject(common, curlun,
curlun - common->luns))
: 0;
}
static int do_prevent_allow(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
int prevent;
if (!common->curlun) {
return -EINVAL;
} else if (!common->curlun->removable) {
common->curlun->sense_data = SS_INVALID_COMMAND;
return -EINVAL;
}
prevent = common->cmnd[4] & 0x01;
if ((common->cmnd[4] & ~0x01) != 0) {
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
if (curlun->prevent_medium_removal && !prevent)
fsg_lun_fsync_sub(curlun);
curlun->prevent_medium_removal = prevent;
return 0;
}
static int do_read_format_capacities(struct fsg_common *common,
struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
u8 *buf = (u8 *) bh->buf;
buf[0] = buf[1] = buf[2] = 0;
buf[3] = 8;
buf += 4;
put_unaligned_be32(curlun->num_sectors, &buf[0]);
put_unaligned_be32(curlun->blksize, &buf[4]);
buf[4] = 0x02;
return 12;
}
static int do_mode_select(struct fsg_common *common, struct fsg_buffhd *bh)
{
struct fsg_lun *curlun = common->curlun;
if (curlun)
curlun->sense_data = SS_INVALID_COMMAND;
return -EINVAL;
}
static int halt_bulk_in_endpoint(struct fsg_dev *fsg)
{
int rc;
rc = fsg_set_halt(fsg, fsg->bulk_in);
if (rc == -EAGAIN)
VDBG(fsg, "delayed bulk-in endpoint halt\n");
while (rc != 0) {
if (rc != -EAGAIN) {
WARNING(fsg, "usb_ep_set_halt -> %d\n", rc);
rc = 0;
break;
}
if (msleep_interruptible(100) != 0)
return -EINTR;
rc = usb_ep_set_halt(fsg->bulk_in);
}
return rc;
}
static int wedge_bulk_in_endpoint(struct fsg_dev *fsg)
{
int rc;
DBG(fsg, "bulk-in set wedge\n");
rc = usb_ep_set_wedge(fsg->bulk_in);
if (rc == -EAGAIN)
VDBG(fsg, "delayed bulk-in endpoint wedge\n");
while (rc != 0) {
if (rc != -EAGAIN) {
WARNING(fsg, "usb_ep_set_wedge -> %d\n", rc);
rc = 0;
break;
}
if (msleep_interruptible(100) != 0)
return -EINTR;
rc = usb_ep_set_wedge(fsg->bulk_in);
}
return rc;
}
static int throw_away_data(struct fsg_common *common)
{
struct fsg_buffhd *bh;
u32 amount;
int rc;
for (bh = common->next_buffhd_to_drain;
bh->state != BUF_STATE_EMPTY || common->usb_amount_left > 0;
bh = common->next_buffhd_to_drain) {
if (bh->state == BUF_STATE_FULL) {
smp_rmb();
bh->state = BUF_STATE_EMPTY;
common->next_buffhd_to_drain = bh->next;
if (bh->outreq->actual < bh->bulk_out_intended_length ||
bh->outreq->status != 0) {
raise_exception(common,
FSG_STATE_ABORT_BULK_OUT);
return -EINTR;
}
continue;
}
bh = common->next_buffhd_to_fill;
if (bh->state == BUF_STATE_EMPTY
&& common->usb_amount_left > 0) {
amount = min(common->usb_amount_left, FSG_BUFLEN);
set_bulk_out_req_length(common, bh, amount);
if (!start_out_transfer(common, bh))
return -EIO;
common->next_buffhd_to_fill = bh->next;
common->usb_amount_left -= amount;
continue;
}
rc = sleep_thread(common);
if (rc)
return rc;
}
return 0;
}
static int finish_reply(struct fsg_common *common)
{
struct fsg_buffhd *bh = common->next_buffhd_to_fill;
int rc = 0;
switch (common->data_dir) {
case DATA_DIR_NONE:
break;
case DATA_DIR_UNKNOWN:
if (!common->can_stall) {
} else if (fsg_is_set(common)) {
fsg_set_halt(common->fsg, common->fsg->bulk_out);
rc = halt_bulk_in_endpoint(common->fsg);
} else {
rc = -EIO;
}
break;
case DATA_DIR_TO_HOST:
if (common->data_size == 0) {
} else if (!fsg_is_set(common)) {
rc = -EIO;
} else if (common->residue == 0) {
bh->inreq->zero = 0;
if (!start_in_transfer(common, bh))
return -EIO;
common->next_buffhd_to_fill = bh->next;
} else {
bh->inreq->zero = 1;
if (!start_in_transfer(common, bh))
rc = -EIO;
common->next_buffhd_to_fill = bh->next;
if (common->can_stall)
rc = halt_bulk_in_endpoint(common->fsg);
}
break;
case DATA_DIR_FROM_HOST:
if (common->residue == 0) {
} else if (common->short_packet_received) {
raise_exception(common, FSG_STATE_ABORT_BULK_OUT);
rc = -EINTR;
#if 0
} else if (common->can_stall) {
if (fsg_is_set(common))
fsg_set_halt(common->fsg,
common->fsg->bulk_out);
raise_exception(common, FSG_STATE_ABORT_BULK_OUT);
rc = -EINTR;
#endif
} else {
rc = throw_away_data(common);
}
break;
}
return rc;
}
static int send_status(struct fsg_common *common)
{
struct fsg_lun *curlun = common->curlun;
struct fsg_buffhd *bh;
struct bulk_cs_wrap *csw;
int rc;
u8 status = US_BULK_STAT_OK;
u32 sd, sdinfo = 0;
bh = common->next_buffhd_to_fill;
while (bh->state != BUF_STATE_EMPTY) {
rc = sleep_thread(common);
if (rc)
return rc;
}
if (curlun) {
sd = curlun->sense_data;
sdinfo = curlun->sense_data_info;
} else if (common->bad_lun_okay)
sd = SS_NO_SENSE;
else
sd = SS_LOGICAL_UNIT_NOT_SUPPORTED;
if (common->phase_error) {
DBG(common, "sending phase-error status\n");
status = US_BULK_STAT_PHASE;
sd = SS_INVALID_COMMAND;
} else if (sd != SS_NO_SENSE) {
DBG(common, "sending command-failure status\n");
status = US_BULK_STAT_FAIL;
VDBG(common, " sense data: SK x%02x, ASC x%02x, ASCQ x%02x;"
" info x%x\n",
SK(sd), ASC(sd), ASCQ(sd), sdinfo);
}
csw = (void *)bh->buf;
csw->Signature = cpu_to_le32(US_BULK_CS_SIGN);
csw->Tag = common->tag;
csw->Residue = cpu_to_le32(common->residue);
csw->Status = status;
bh->inreq->length = US_BULK_CS_WRAP_LEN;
bh->inreq->zero = 0;
if (!start_in_transfer(common, bh))
return -EIO;
common->next_buffhd_to_fill = bh->next;
return 0;
}
static int check_command(struct fsg_common *common, int cmnd_size,
enum data_direction data_dir, unsigned int mask,
int needs_medium, const char *name)
{
int i;
int lun = common->cmnd[1] >> 5;
static const char dirletter[4] = {'u', 'o', 'i', 'n'};
char hdlen[20];
struct fsg_lun *curlun;
hdlen[0] = 0;
if (common->data_dir != DATA_DIR_UNKNOWN)
sprintf(hdlen, ", H%c=%u", dirletter[(int) common->data_dir],
common->data_size);
VDBG(common, "SCSI command: %s; Dc=%d, D%c=%u; Hc=%d%s\n",
name, cmnd_size, dirletter[(int) data_dir],
common->data_size_from_cmnd, common->cmnd_size, hdlen);
if (common->data_size_from_cmnd == 0)
data_dir = DATA_DIR_NONE;
if (common->data_size < common->data_size_from_cmnd) {
common->data_size_from_cmnd = common->data_size;
common->phase_error = 1;
}
common->residue = common->data_size;
common->usb_amount_left = common->data_size;
if (common->data_dir != data_dir && common->data_size_from_cmnd > 0) {
common->phase_error = 1;
return -EINVAL;
}
if (cmnd_size != common->cmnd_size) {
if (cmnd_size <= common->cmnd_size) {
DBG(common, "%s is buggy! Expected length %d "
"but we got %d\n", name,
cmnd_size, common->cmnd_size);
cmnd_size = common->cmnd_size;
} else {
common->phase_error = 1;
return -EINVAL;
}
}
if (common->lun != lun)
DBG(common, "using LUN %d from CBW, not LUN %d from CDB\n",
common->lun, lun);
curlun = common->curlun;
if (curlun) {
if (common->cmnd[0] != REQUEST_SENSE) {
curlun->sense_data = SS_NO_SENSE;
curlun->sense_data_info = 0;
curlun->info_valid = 0;
}
} else {
common->bad_lun_okay = 0;
if (common->cmnd[0] != INQUIRY &&
common->cmnd[0] != REQUEST_SENSE) {
DBG(common, "unsupported LUN %d\n", common->lun);
return -EINVAL;
}
}
if (curlun && curlun->unit_attention_data != SS_NO_SENSE &&
common->cmnd[0] != INQUIRY &&
common->cmnd[0] != REQUEST_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
return -EINVAL;
}
common->cmnd[1] &= 0x1f;
for (i = 1; i < cmnd_size; ++i) {
if (common->cmnd[i] && !(mask & (1 << i))) {
if (curlun)
curlun->sense_data = SS_INVALID_FIELD_IN_CDB;
return -EINVAL;
}
}
if (curlun && !fsg_lun_is_open(curlun) && needs_medium) {
curlun->sense_data = SS_MEDIUM_NOT_PRESENT;
return -EINVAL;
}
return 0;
}
static int check_command_size_in_blocks(struct fsg_common *common,
int cmnd_size, enum data_direction data_dir,
unsigned int mask, int needs_medium, const char *name)
{
if (common->curlun)
common->data_size_from_cmnd <<= common->curlun->blkbits;
return check_command(common, cmnd_size, data_dir,
mask, needs_medium, name);
}
static int do_scsi_command(struct fsg_common *common)
{
struct fsg_buffhd *bh;
int rc;
int reply = -EINVAL;
int i;
static char unknown[16];
dump_cdb(common);
bh = common->next_buffhd_to_fill;
common->next_buffhd_to_drain = bh;
while (bh->state != BUF_STATE_EMPTY) {
rc = sleep_thread(common);
if (rc)
return rc;
}
common->phase_error = 0;
common->short_packet_received = 0;
down_read(&common->filesem);
switch (common->cmnd[0]) {
case INQUIRY:
common->data_size_from_cmnd = common->cmnd[4];
reply = check_command(common, 6, DATA_DIR_TO_HOST,
(1<<4), 0,
"INQUIRY");
if (reply == 0)
reply = do_inquiry(common, bh);
break;
case MODE_SELECT:
common->data_size_from_cmnd = common->cmnd[4];
reply = check_command(common, 6, DATA_DIR_FROM_HOST,
(1<<1) | (1<<4), 0,
"MODE SELECT(6)");
if (reply == 0)
reply = do_mode_select(common, bh);
break;
case MODE_SELECT_10:
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command(common, 10, DATA_DIR_FROM_HOST,
(1<<1) | (3<<7), 0,
"MODE SELECT(10)");
if (reply == 0)
reply = do_mode_select(common, bh);
break;
case MODE_SENSE:
common->data_size_from_cmnd = common->cmnd[4];
reply = check_command(common, 6, DATA_DIR_TO_HOST,
(1<<1) | (1<<2) | (1<<4), 0,
"MODE SENSE(6)");
if (reply == 0)
reply = do_mode_sense(common, bh);
break;
case MODE_SENSE_10:
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command(common, 10, DATA_DIR_TO_HOST,
(1<<1) | (1<<2) | (3<<7), 0,
"MODE SENSE(10)");
if (reply == 0)
reply = do_mode_sense(common, bh);
break;
case ALLOW_MEDIUM_REMOVAL:
common->data_size_from_cmnd = 0;
reply = check_command(common, 6, DATA_DIR_NONE,
(1<<4), 0,
"PREVENT-ALLOW MEDIUM REMOVAL");
if (reply == 0)
reply = do_prevent_allow(common);
break;
case READ_6:
i = common->cmnd[4];
common->data_size_from_cmnd = (i == 0) ? 256 : i;
reply = check_command_size_in_blocks(common, 6,
DATA_DIR_TO_HOST,
(7<<1) | (1<<4), 1,
"READ(6)");
if (reply == 0)
reply = do_read(common);
break;
case READ_10:
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command_size_in_blocks(common, 10,
DATA_DIR_TO_HOST,
(1<<1) | (0xf<<2) | (3<<7), 1,
"READ(10)");
if (reply == 0)
reply = do_read(common);
break;
case READ_12:
common->data_size_from_cmnd =
get_unaligned_be32(&common->cmnd[6]);
reply = check_command_size_in_blocks(common, 12,
DATA_DIR_TO_HOST,
(1<<1) | (0xf<<2) | (0xf<<6), 1,
"READ(12)");
if (reply == 0)
reply = do_read(common);
break;
case READ_CAPACITY:
common->data_size_from_cmnd = 8;
reply = check_command(common, 10, DATA_DIR_TO_HOST,
(0xf<<2) | (1<<8), 1,
"READ CAPACITY");
if (reply == 0)
reply = do_read_capacity(common, bh);
break;
case READ_HEADER:
if (!common->curlun || !common->curlun->cdrom)
goto unknown_cmnd;
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command(common, 10, DATA_DIR_TO_HOST,
(3<<7) | (0x1f<<1), 1,
"READ HEADER");
if (reply == 0)
reply = do_read_header(common, bh);
break;
case READ_TOC:
if (!common->curlun || !common->curlun->cdrom)
goto unknown_cmnd;
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command(common, 10, DATA_DIR_TO_HOST,
(7<<6) | (1<<1), 1,
"READ TOC");
if (reply == 0)
reply = do_read_toc(common, bh);
break;
case READ_FORMAT_CAPACITIES:
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command(common, 10, DATA_DIR_TO_HOST,
(3<<7), 1,
"READ FORMAT CAPACITIES");
if (reply == 0)
reply = do_read_format_capacities(common, bh);
break;
case REQUEST_SENSE:
common->data_size_from_cmnd = common->cmnd[4];
reply = check_command(common, 6, DATA_DIR_TO_HOST,
(1<<4), 0,
"REQUEST SENSE");
if (reply == 0)
reply = do_request_sense(common, bh);
break;
case START_STOP:
common->data_size_from_cmnd = 0;
reply = check_command(common, 6, DATA_DIR_NONE,
(1<<1) | (1<<4), 0,
"START-STOP UNIT");
if (reply == 0)
reply = do_start_stop(common);
break;
case SYNCHRONIZE_CACHE:
common->data_size_from_cmnd = 0;
reply = check_command(common, 10, DATA_DIR_NONE,
(0xf<<2) | (3<<7), 1,
"SYNCHRONIZE CACHE");
if (reply == 0)
reply = do_synchronize_cache(common);
break;
case TEST_UNIT_READY:
common->data_size_from_cmnd = 0;
reply = check_command(common, 6, DATA_DIR_NONE,
0, 1,
"TEST UNIT READY");
break;
case VERIFY:
common->data_size_from_cmnd = 0;
reply = check_command(common, 10, DATA_DIR_NONE,
(1<<1) | (0xf<<2) | (3<<7), 1,
"VERIFY");
if (reply == 0)
reply = do_verify(common);
break;
case WRITE_6:
i = common->cmnd[4];
common->data_size_from_cmnd = (i == 0) ? 256 : i;
reply = check_command_size_in_blocks(common, 6,
DATA_DIR_FROM_HOST,
(7<<1) | (1<<4), 1,
"WRITE(6)");
if (reply == 0)
reply = do_write(common);
break;
case WRITE_10:
common->data_size_from_cmnd =
get_unaligned_be16(&common->cmnd[7]);
reply = check_command_size_in_blocks(common, 10,
DATA_DIR_FROM_HOST,
(1<<1) | (0xf<<2) | (3<<7), 1,
"WRITE(10)");
if (reply == 0)
reply = do_write(common);
break;
case WRITE_12:
common->data_size_from_cmnd =
get_unaligned_be32(&common->cmnd[6]);
reply = check_command_size_in_blocks(common, 12,
DATA_DIR_FROM_HOST,
(1<<1) | (0xf<<2) | (0xf<<6), 1,
"WRITE(12)");
if (reply == 0)
reply = do_write(common);
break;
case FORMAT_UNIT:
case RELEASE:
case RESERVE:
case SEND_DIAGNOSTIC:
default:
unknown_cmnd:
common->data_size_from_cmnd = 0;
sprintf(unknown, "Unknown x%02x", common->cmnd[0]);
reply = check_command(common, common->cmnd_size,
DATA_DIR_UNKNOWN, ~0, 0, unknown);
if (reply == 0) {
common->curlun->sense_data = SS_INVALID_COMMAND;
reply = -EINVAL;
}
break;
}
up_read(&common->filesem);
if (reply == -EINTR || signal_pending(current))
return -EINTR;
if (reply == -EINVAL)
reply = 0;
if (reply >= 0 && common->data_dir == DATA_DIR_TO_HOST) {
reply = min((u32)reply, common->data_size_from_cmnd);
bh->inreq->length = reply;
bh->state = BUF_STATE_FULL;
common->residue -= reply;
}
return 0;
}
static int received_cbw(struct fsg_dev *fsg, struct fsg_buffhd *bh)
{
struct usb_request *req = bh->outreq;
struct bulk_cb_wrap *cbw = req->buf;
struct fsg_common *common = fsg->common;
if (req->status || test_bit(IGNORE_BULK_OUT, &fsg->atomic_bitflags))
return -EINVAL;
if (req->actual != US_BULK_CB_WRAP_LEN ||
cbw->Signature != cpu_to_le32(
US_BULK_CB_SIGN)) {
DBG(fsg, "invalid CBW: len %u sig 0x%x\n",
req->actual,
le32_to_cpu(cbw->Signature));
wedge_bulk_in_endpoint(fsg);
set_bit(IGNORE_BULK_OUT, &fsg->atomic_bitflags);
return -EINVAL;
}
if (cbw->Lun >= FSG_MAX_LUNS || cbw->Flags & ~US_BULK_FLAG_IN ||
cbw->Length <= 0 || cbw->Length > MAX_COMMAND_SIZE) {
DBG(fsg, "non-meaningful CBW: lun = %u, flags = 0x%x, "
"cmdlen %u\n",
cbw->Lun, cbw->Flags, cbw->Length);
if (common->can_stall) {
fsg_set_halt(fsg, fsg->bulk_out);
halt_bulk_in_endpoint(fsg);
}
return -EINVAL;
}
common->cmnd_size = cbw->Length;
memcpy(common->cmnd, cbw->CDB, common->cmnd_size);
if (cbw->Flags & US_BULK_FLAG_IN)
common->data_dir = DATA_DIR_TO_HOST;
else
common->data_dir = DATA_DIR_FROM_HOST;
common->data_size = le32_to_cpu(cbw->DataTransferLength);
if (common->data_size == 0)
common->data_dir = DATA_DIR_NONE;
common->lun = cbw->Lun;
if (common->lun >= 0 && common->lun < common->nluns)
common->curlun = &common->luns[common->lun];
else
common->curlun = NULL;
common->tag = cbw->Tag;
return 0;
}
static int get_next_command(struct fsg_common *common)
{
struct fsg_buffhd *bh;
int rc = 0;
bh = common->next_buffhd_to_fill;
while (bh->state != BUF_STATE_EMPTY) {
rc = sleep_thread(common);
if (rc)
return rc;
}
set_bulk_out_req_length(common, bh, US_BULK_CB_WRAP_LEN);
if (!start_out_transfer(common, bh))
return -EIO;
while (bh->state != BUF_STATE_FULL) {
rc = sleep_thread(common);
if (rc)
return rc;
}
smp_rmb();
rc = fsg_is_set(common) ? received_cbw(common->fsg, bh) : -EIO;
bh->state = BUF_STATE_EMPTY;
return rc;
}
static int alloc_request(struct fsg_common *common, struct usb_ep *ep,
struct usb_request **preq)
{
*preq = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (*preq)
return 0;
ERROR(common, "can't allocate request for %s\n", ep->name);
return -ENOMEM;
}
static int do_set_interface(struct fsg_common *common, struct fsg_dev *new_fsg)
{
struct fsg_dev *fsg;
int i, rc = 0;
if (common->running)
DBG(common, "reset interface\n");
reset:
if (common->fsg) {
fsg = common->fsg;
for (i = 0; i < fsg_num_buffers; ++i) {
struct fsg_buffhd *bh = &common->buffhds[i];
if (bh->inreq) {
usb_ep_free_request(fsg->bulk_in, bh->inreq);
bh->inreq = NULL;
}
if (bh->outreq) {
usb_ep_free_request(fsg->bulk_out, bh->outreq);
bh->outreq = NULL;
}
}
if (fsg->bulk_in_enabled) {
usb_ep_disable(fsg->bulk_in);
fsg->bulk_in_enabled = 0;
}
if (fsg->bulk_out_enabled) {
usb_ep_disable(fsg->bulk_out);
fsg->bulk_out_enabled = 0;
}
common->fsg = NULL;
wake_up(&common->fsg_wait);
}
common->running = 0;
if (!new_fsg || rc)
return rc;
common->fsg = new_fsg;
fsg = common->fsg;
rc = config_ep_by_speed(common->gadget, &(fsg->function), fsg->bulk_in);
if (rc)
goto reset;
rc = usb_ep_enable(fsg->bulk_in);
if (rc)
goto reset;
fsg->bulk_in->driver_data = common;
fsg->bulk_in_enabled = 1;
rc = config_ep_by_speed(common->gadget, &(fsg->function),
fsg->bulk_out);
if (rc)
goto reset;
rc = usb_ep_enable(fsg->bulk_out);
if (rc)
goto reset;
fsg->bulk_out->driver_data = common;
fsg->bulk_out_enabled = 1;
common->bulk_out_maxpacket = usb_endpoint_maxp(fsg->bulk_out->desc);
clear_bit(IGNORE_BULK_OUT, &fsg->atomic_bitflags);
for (i = 0; i < fsg_num_buffers; ++i) {
struct fsg_buffhd *bh = &common->buffhds[i];
rc = alloc_request(common, fsg->bulk_in, &bh->inreq);
if (rc)
goto reset;
rc = alloc_request(common, fsg->bulk_out, &bh->outreq);
if (rc)
goto reset;
bh->inreq->buf = bh->outreq->buf = bh->buf;
bh->inreq->context = bh->outreq->context = bh;
bh->inreq->complete = bulk_in_complete;
bh->outreq->complete = bulk_out_complete;
}
common->running = 1;
for (i = 0; i < common->nluns; ++i)
common->luns[i].unit_attention_data = SS_RESET_OCCURRED;
return rc;
}
static int fsg_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct fsg_dev *fsg = fsg_from_func(f);
fsg->common->new_fsg = fsg;
raise_exception(fsg->common, FSG_STATE_CONFIG_CHANGE);
return USB_GADGET_DELAYED_STATUS;
}
static void fsg_disable(struct usb_function *f)
{
struct fsg_dev *fsg = fsg_from_func(f);
fsg->common->new_fsg = NULL;
raise_exception(fsg->common, FSG_STATE_CONFIG_CHANGE);
}
static void handle_exception(struct fsg_common *common)
{
siginfo_t info;
int i;
struct fsg_buffhd *bh;
enum fsg_state old_state;
struct fsg_lun *curlun;
unsigned int exception_req_tag;
for (;;) {
int sig =
dequeue_signal_lock(current, &current->blocked, &info);
if (!sig)
break;
if (sig != SIGUSR1) {
if (common->state < FSG_STATE_EXIT)
DBG(common, "Main thread exiting on signal\n");
raise_exception(common, FSG_STATE_EXIT);
}
}
if (likely(common->fsg)) {
for (i = 0; i < fsg_num_buffers; ++i) {
bh = &common->buffhds[i];
if (bh->inreq_busy)
usb_ep_dequeue(common->fsg->bulk_in, bh->inreq);
if (bh->outreq_busy)
usb_ep_dequeue(common->fsg->bulk_out,
bh->outreq);
}
for (;;) {
int num_active = 0;
for (i = 0; i < fsg_num_buffers; ++i) {
bh = &common->buffhds[i];
num_active += bh->inreq_busy + bh->outreq_busy;
}
if (num_active == 0)
break;
if (sleep_thread(common))
return;
}
if (common->fsg->bulk_in_enabled)
usb_ep_fifo_flush(common->fsg->bulk_in);
if (common->fsg->bulk_out_enabled)
usb_ep_fifo_flush(common->fsg->bulk_out);
}
spin_lock_irq(&common->lock);
for (i = 0; i < fsg_num_buffers; ++i) {
bh = &common->buffhds[i];
bh->state = BUF_STATE_EMPTY;
}
common->next_buffhd_to_fill = &common->buffhds[0];
common->next_buffhd_to_drain = &common->buffhds[0];
exception_req_tag = common->exception_req_tag;
old_state = common->state;
if (old_state == FSG_STATE_ABORT_BULK_OUT)
common->state = FSG_STATE_STATUS_PHASE;
else {
for (i = 0; i < common->nluns; ++i) {
curlun = &common->luns[i];
curlun->prevent_medium_removal = 0;
curlun->sense_data = SS_NO_SENSE;
curlun->unit_attention_data = SS_NO_SENSE;
curlun->sense_data_info = 0;
curlun->info_valid = 0;
}
common->state = FSG_STATE_IDLE;
}
spin_unlock_irq(&common->lock);
switch (old_state) {
case FSG_STATE_ABORT_BULK_OUT:
send_status(common);
spin_lock_irq(&common->lock);
if (common->state == FSG_STATE_STATUS_PHASE)
common->state = FSG_STATE_IDLE;
spin_unlock_irq(&common->lock);
break;
case FSG_STATE_RESET:
if (!fsg_is_set(common))
break;
if (test_and_clear_bit(IGNORE_BULK_OUT,
&common->fsg->atomic_bitflags))
usb_ep_clear_halt(common->fsg->bulk_in);
if (common->ep0_req_tag == exception_req_tag)
ep0_queue(common);
break;
case FSG_STATE_CONFIG_CHANGE:
do_set_interface(common, common->new_fsg);
if (common->new_fsg)
usb_composite_setup_continue(common->cdev);
break;
case FSG_STATE_EXIT:
case FSG_STATE_TERMINATED:
do_set_interface(common, NULL);
spin_lock_irq(&common->lock);
common->state = FSG_STATE_TERMINATED;
spin_unlock_irq(&common->lock);
break;
case FSG_STATE_INTERFACE_CHANGE:
case FSG_STATE_DISCONNECT:
case FSG_STATE_COMMAND_PHASE:
case FSG_STATE_DATA_PHASE:
case FSG_STATE_STATUS_PHASE:
case FSG_STATE_IDLE:
break;
}
}
static int fsg_main_thread(void *common_)
{
struct fsg_common *common = common_;
allow_signal(SIGINT);
allow_signal(SIGTERM);
allow_signal(SIGKILL);
allow_signal(SIGUSR1);
set_freezable();
set_fs(get_ds());
while (common->state != FSG_STATE_TERMINATED) {
if (exception_in_progress(common) || signal_pending(current)) {
handle_exception(common);
continue;
}
if (!common->running) {
sleep_thread(common);
continue;
}
if (get_next_command(common))
continue;
spin_lock_irq(&common->lock);
if (!exception_in_progress(common))
common->state = FSG_STATE_DATA_PHASE;
spin_unlock_irq(&common->lock);
if (do_scsi_command(common) || finish_reply(common))
continue;
spin_lock_irq(&common->lock);
if (!exception_in_progress(common))
common->state = FSG_STATE_STATUS_PHASE;
spin_unlock_irq(&common->lock);
if (send_status(common))
continue;
spin_lock_irq(&common->lock);
if (!exception_in_progress(common))
common->state = FSG_STATE_IDLE;
spin_unlock_irq(&common->lock);
}
spin_lock_irq(&common->lock);
common->thread_task = NULL;
spin_unlock_irq(&common->lock);
if (!common->ops || !common->ops->thread_exits
|| common->ops->thread_exits(common) < 0) {
struct fsg_lun *curlun = common->luns;
unsigned i = common->nluns;
down_write(&common->filesem);
for (; i--; ++curlun) {
if (!fsg_lun_is_open(curlun))
continue;
fsg_lun_close(curlun);
curlun->unit_attention_data = SS_MEDIUM_NOT_PRESENT;
}
up_write(&common->filesem);
}
complete_and_exit(&common->thread_notifier, 0);
}
static void fsg_lun_release(struct device *dev)
{
}
static inline void fsg_common_get(struct fsg_common *common)
{
kref_get(&common->ref);
}
static inline void fsg_common_put(struct fsg_common *common)
{
kref_put(&common->ref, fsg_common_release);
}
static struct fsg_common *fsg_common_init(struct fsg_common *common,
struct usb_composite_dev *cdev,
struct fsg_config *cfg)
{
struct usb_gadget *gadget = cdev->gadget;
struct fsg_buffhd *bh;
struct fsg_lun *curlun;
struct fsg_lun_config *lcfg;
int nluns, i, rc;
char *pathbuf;
rc = fsg_num_buffers_validate();
if (rc != 0)
return ERR_PTR(rc);
nluns = cfg->nluns;
if (nluns < 1 || nluns > FSG_MAX_LUNS) {
dev_err(&gadget->dev, "invalid number of LUNs: %u\n", nluns);
return ERR_PTR(-EINVAL);
}
if (!common) {
common = kzalloc(sizeof *common, GFP_KERNEL);
if (!common)
return ERR_PTR(-ENOMEM);
common->free_storage_on_release = 1;
} else {
memset(common, 0, sizeof *common);
common->free_storage_on_release = 0;
}
common->buffhds = kcalloc(fsg_num_buffers,
sizeof *(common->buffhds), GFP_KERNEL);
if (!common->buffhds) {
if (common->free_storage_on_release)
kfree(common);
return ERR_PTR(-ENOMEM);
}
common->ops = cfg->ops;
common->private_data = cfg->private_data;
common->gadget = gadget;
common->ep0 = gadget->ep0;
common->ep0req = cdev->req;
common->cdev = cdev;
if (fsg_strings[FSG_STRING_INTERFACE].id == 0) {
rc = usb_string_id(cdev);
if (unlikely(rc < 0))
goto error_release;
fsg_strings[FSG_STRING_INTERFACE].id = rc;
fsg_intf_desc.iInterface = rc;
}
curlun = kcalloc(nluns, sizeof(*curlun), GFP_KERNEL);
if (unlikely(!curlun)) {
rc = -ENOMEM;
goto error_release;
}
common->luns = curlun;
init_rwsem(&common->filesem);
for (i = 0, lcfg = cfg->luns; i < nluns; ++i, ++curlun, ++lcfg) {
curlun->cdrom = !!lcfg->cdrom;
curlun->ro = lcfg->cdrom || lcfg->ro;
curlun->initially_ro = curlun->ro;
curlun->removable = lcfg->removable;
curlun->dev.release = fsg_lun_release;
curlun->dev.parent = &gadget->dev;
dev_set_drvdata(&curlun->dev, &common->filesem);
dev_set_name(&curlun->dev, "lun%d", i);
rc = device_register(&curlun->dev);
if (rc) {
INFO(common, "failed to register LUN%d: %d\n", i, rc);
common->nluns = i;
put_device(&curlun->dev);
goto error_release;
}
rc = device_create_file(&curlun->dev,
curlun->cdrom
? &dev_attr_ro_cdrom
: &dev_attr_ro);
if (rc)
goto error_luns;
rc = device_create_file(&curlun->dev,
curlun->removable
? &dev_attr_file
: &dev_attr_file_nonremovable);
if (rc)
goto error_luns;
rc = device_create_file(&curlun->dev, &dev_attr_nofua);
if (rc)
goto error_luns;
if (lcfg->filename) {
rc = fsg_lun_open(curlun, lcfg->filename);
if (rc)
goto error_luns;
} else if (!curlun->removable) {
ERROR(common, "no file given for LUN%d\n", i);
rc = -EINVAL;
goto error_luns;
}
}
common->nluns = nluns;
bh = common->buffhds;
i = fsg_num_buffers;
goto buffhds_first_it;
do {
bh->next = bh + 1;
++bh;
buffhds_first_it:
bh->buf = kmalloc(FSG_BUFLEN, GFP_KERNEL);
if (unlikely(!bh->buf)) {
rc = -ENOMEM;
goto error_release;
}
} while (--i);
bh->next = common->buffhds;
i = get_default_bcdDevice();
snprintf(common->inquiry_string, sizeof common->inquiry_string,
"%-8s%-16s%04x", cfg->vendor_name ?: "Linux",
cfg->product_name ?: (common->luns->cdrom
? "File-Stor Gadget"
: "File-CD Gadget"),
i);
common->can_stall = cfg->can_stall &&
!(gadget_is_at91(common->gadget));
spin_lock_init(&common->lock);
kref_init(&common->ref);
common->thread_task =
kthread_create(fsg_main_thread, common, "file-storage");
if (IS_ERR(common->thread_task)) {
rc = PTR_ERR(common->thread_task);
goto error_release;
}
init_completion(&common->thread_notifier);
init_waitqueue_head(&common->fsg_wait);
INFO(common, FSG_DRIVER_DESC ", version: " FSG_DRIVER_VERSION "\n");
INFO(common, "Number of LUNs=%d\n", common->nluns);
pathbuf = kmalloc(PATH_MAX, GFP_KERNEL);
for (i = 0, nluns = common->nluns, curlun = common->luns;
i < nluns;
++curlun, ++i) {
char *p = "(no medium)";
if (fsg_lun_is_open(curlun)) {
p = "(error)";
if (pathbuf) {
p = d_path(&curlun->filp->f_path,
pathbuf, PATH_MAX);
if (IS_ERR(p))
p = "(error)";
}
}
LINFO(curlun, "LUN: %s%s%sfile: %s\n",
curlun->removable ? "removable " : "",
curlun->ro ? "read only " : "",
curlun->cdrom ? "CD-ROM " : "",
p);
}
kfree(pathbuf);
DBG(common, "I/O thread pid: %d\n", task_pid_nr(common->thread_task));
wake_up_process(common->thread_task);
return common;
error_luns:
common->nluns = i + 1;
error_release:
common->state = FSG_STATE_TERMINATED;
fsg_common_release(&common->ref);
return ERR_PTR(rc);
}
static void fsg_common_release(struct kref *ref)
{
struct fsg_common *common = container_of(ref, struct fsg_common, ref);
if (common->state != FSG_STATE_TERMINATED) {
raise_exception(common, FSG_STATE_EXIT);
wait_for_completion(&common->thread_notifier);
}
if (likely(common->luns)) {
struct fsg_lun *lun = common->luns;
unsigned i = common->nluns;
for (; i; --i, ++lun) {
device_remove_file(&lun->dev, &dev_attr_nofua);
device_remove_file(&lun->dev,
lun->cdrom
? &dev_attr_ro_cdrom
: &dev_attr_ro);
device_remove_file(&lun->dev,
lun->removable
? &dev_attr_file
: &dev_attr_file_nonremovable);
fsg_lun_close(lun);
device_unregister(&lun->dev);
}
kfree(common->luns);
}
{
struct fsg_buffhd *bh = common->buffhds;
unsigned i = fsg_num_buffers;
do {
kfree(bh->buf);
} while (++bh, --i);
}
kfree(common->buffhds);
if (common->free_storage_on_release)
kfree(common);
}
static void fsg_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct fsg_dev *fsg = fsg_from_func(f);
struct fsg_common *common = fsg->common;
DBG(fsg, "unbind\n");
if (fsg->common->fsg == fsg) {
fsg->common->new_fsg = NULL;
raise_exception(fsg->common, FSG_STATE_CONFIG_CHANGE);
wait_event(common->fsg_wait, common->fsg != fsg);
}
fsg_common_put(common);
usb_free_descriptors(fsg->function.descriptors);
usb_free_descriptors(fsg->function.hs_descriptors);
usb_free_descriptors(fsg->function.ss_descriptors);
kfree(fsg);
}
static int fsg_bind(struct usb_configuration *c, struct usb_function *f)
{
struct fsg_dev *fsg = fsg_from_func(f);
struct usb_gadget *gadget = c->cdev->gadget;
int i;
struct usb_ep *ep;
fsg->gadget = gadget;
i = usb_interface_id(c, f);
if (i < 0)
return i;
fsg_intf_desc.bInterfaceNumber = i;
fsg->interface_number = i;
ep = usb_ep_autoconfig(gadget, &fsg_fs_bulk_in_desc);
if (!ep)
goto autoconf_fail;
ep->driver_data = fsg->common;
fsg->bulk_in = ep;
ep = usb_ep_autoconfig(gadget, &fsg_fs_bulk_out_desc);
if (!ep)
goto autoconf_fail;
ep->driver_data = fsg->common;
fsg->bulk_out = ep;
f->descriptors = usb_copy_descriptors(fsg_fs_function);
if (unlikely(!f->descriptors))
return -ENOMEM;
if (gadget_is_dualspeed(gadget)) {
fsg_hs_bulk_in_desc.bEndpointAddress =
fsg_fs_bulk_in_desc.bEndpointAddress;
fsg_hs_bulk_out_desc.bEndpointAddress =
fsg_fs_bulk_out_desc.bEndpointAddress;
f->hs_descriptors = usb_copy_descriptors(fsg_hs_function);
if (unlikely(!f->hs_descriptors)) {
usb_free_descriptors(f->descriptors);
return -ENOMEM;
}
}
if (gadget_is_superspeed(gadget)) {
unsigned max_burst;
max_burst = min_t(unsigned, FSG_BUFLEN / 1024, 15);
fsg_ss_bulk_in_desc.bEndpointAddress =
fsg_fs_bulk_in_desc.bEndpointAddress;
fsg_ss_bulk_in_comp_desc.bMaxBurst = max_burst;
fsg_ss_bulk_out_desc.bEndpointAddress =
fsg_fs_bulk_out_desc.bEndpointAddress;
fsg_ss_bulk_out_comp_desc.bMaxBurst = max_burst;
f->ss_descriptors = usb_copy_descriptors(fsg_ss_function);
if (unlikely(!f->ss_descriptors)) {
usb_free_descriptors(f->hs_descriptors);
usb_free_descriptors(f->descriptors);
return -ENOMEM;
}
}
return 0;
autoconf_fail:
ERROR(fsg, "unable to autoconfigure all endpoints\n");
return -ENOTSUPP;
}
static int fsg_bind_config(struct usb_composite_dev *cdev,
struct usb_configuration *c,
struct fsg_common *common)
{
struct fsg_dev *fsg;
int rc;
fsg = kzalloc(sizeof *fsg, GFP_KERNEL);
if (unlikely(!fsg))
return -ENOMEM;
fsg->function.name = FSG_DRIVER_DESC;
fsg->function.strings = fsg_strings_array;
fsg->function.bind = fsg_bind;
fsg->function.unbind = fsg_unbind;
fsg->function.setup = fsg_setup;
fsg->function.set_alt = fsg_set_alt;
fsg->function.disable = fsg_disable;
fsg->common = common;
rc = usb_add_function(c, &fsg->function);
if (unlikely(rc))
kfree(fsg);
else
fsg_common_get(fsg->common);
return rc;
}
static void
fsg_config_from_params(struct fsg_config *cfg,
const struct fsg_module_parameters *params)
{
struct fsg_lun_config *lun;
unsigned i;
cfg->nluns =
min(params->luns ?: (params->file_count ?: 1u),
(unsigned)FSG_MAX_LUNS);
for (i = 0, lun = cfg->luns; i < cfg->nluns; ++i, ++lun) {
lun->ro = !!params->ro[i];
lun->cdrom = !!params->cdrom[i];
lun->removable = !!params->removable[i];
lun->filename =
params->file_count > i && params->file[i][0]
? params->file[i]
: 0;
}
cfg->vendor_name = 0;
cfg->product_name = 0;
cfg->ops = NULL;
cfg->private_data = NULL;
cfg->can_stall = params->stall;
}
static inline struct fsg_common *
fsg_common_from_params(struct fsg_common *common,
struct usb_composite_dev *cdev,
const struct fsg_module_parameters *params)
{
struct fsg_config cfg;
fsg_config_from_params(&cfg, params);
return fsg_common_init(common, cdev, &cfg);
}
