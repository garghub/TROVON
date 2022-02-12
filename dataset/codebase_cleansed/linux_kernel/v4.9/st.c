static struct scsi_tape *scsi_tape_get(int dev)
{
struct scsi_tape *STp = NULL;
mutex_lock(&st_ref_mutex);
spin_lock(&st_index_lock);
STp = idr_find(&st_index_idr, dev);
if (!STp) goto out;
kref_get(&STp->kref);
if (!STp->device)
goto out_put;
if (scsi_device_get(STp->device))
goto out_put;
goto out;
out_put:
kref_put(&STp->kref, scsi_tape_release);
STp = NULL;
out:
spin_unlock(&st_index_lock);
mutex_unlock(&st_ref_mutex);
return STp;
}
static void scsi_tape_put(struct scsi_tape *STp)
{
struct scsi_device *sdev = STp->device;
mutex_lock(&st_ref_mutex);
kref_put(&STp->kref, scsi_tape_release);
scsi_device_put(sdev);
mutex_unlock(&st_ref_mutex);
}
static char * st_incompatible(struct scsi_device* SDp)
{
struct st_reject_data *rp;
for (rp=&(reject_list[0]); rp->vendor != NULL; rp++)
if (!strncmp(rp->vendor, SDp->vendor, strlen(rp->vendor)) &&
!strncmp(rp->model, SDp->model, strlen(rp->model)) &&
!strncmp(rp->rev, SDp->rev, strlen(rp->rev))) {
if (rp->driver_hint)
return rp->driver_hint;
else
return "unknown";
}
return NULL;
}
static inline char *tape_name(struct scsi_tape *tape)
{
return tape->disk->disk_name;
}
static void st_analyze_sense(struct st_request *SRpnt, struct st_cmdstatus *s)
{
const u8 *ucp;
const u8 *sense = SRpnt->sense;
s->have_sense = scsi_normalize_sense(SRpnt->sense,
SCSI_SENSE_BUFFERSIZE, &s->sense_hdr);
s->flags = 0;
if (s->have_sense) {
s->deferred = 0;
s->remainder_valid =
scsi_get_sense_info_fld(sense, SCSI_SENSE_BUFFERSIZE, &s->uremainder64);
switch (sense[0] & 0x7f) {
case 0x71:
s->deferred = 1;
case 0x70:
s->fixed_format = 1;
s->flags = sense[2] & 0xe0;
break;
case 0x73:
s->deferred = 1;
case 0x72:
s->fixed_format = 0;
ucp = scsi_sense_desc_find(sense, SCSI_SENSE_BUFFERSIZE, 4);
s->flags = ucp ? (ucp[3] & 0xe0) : 0;
break;
}
}
}
static int st_chk_result(struct scsi_tape *STp, struct st_request * SRpnt)
{
int result = SRpnt->result;
u8 scode;
DEB(const char *stp;)
char *name = tape_name(STp);
struct st_cmdstatus *cmdstatp;
if (!result)
return 0;
cmdstatp = &STp->buffer->cmdstat;
st_analyze_sense(SRpnt, cmdstatp);
if (cmdstatp->have_sense)
scode = STp->buffer->cmdstat.sense_hdr.sense_key;
else
scode = 0;
DEB(
if (debugging) {
st_printk(ST_DEB_MSG, STp,
"Error: %x, cmd: %x %x %x %x %x %x\n", result,
SRpnt->cmd[0], SRpnt->cmd[1], SRpnt->cmd[2],
SRpnt->cmd[3], SRpnt->cmd[4], SRpnt->cmd[5]);
if (cmdstatp->have_sense)
__scsi_print_sense(STp->device, name,
SRpnt->sense, SCSI_SENSE_BUFFERSIZE);
} )
if (!debugging) {
if (!cmdstatp->have_sense)
st_printk(KERN_WARNING, STp,
"Error %x (driver bt 0x%x, host bt 0x%x).\n",
result, driver_byte(result), host_byte(result));
else if (cmdstatp->have_sense &&
scode != NO_SENSE &&
scode != RECOVERED_ERROR &&
scode != BLANK_CHECK &&
scode != VOLUME_OVERFLOW &&
SRpnt->cmd[0] != MODE_SENSE &&
SRpnt->cmd[0] != TEST_UNIT_READY) {
__scsi_print_sense(STp->device, name,
SRpnt->sense, SCSI_SENSE_BUFFERSIZE);
}
}
if (cmdstatp->fixed_format &&
STp->cln_mode >= EXTENDED_SENSE_START) {
if (STp->cln_sense_value)
STp->cleaning_req |= ((SRpnt->sense[STp->cln_mode] &
STp->cln_sense_mask) == STp->cln_sense_value);
else
STp->cleaning_req |= ((SRpnt->sense[STp->cln_mode] &
STp->cln_sense_mask) != 0);
}
if (cmdstatp->have_sense &&
cmdstatp->sense_hdr.asc == 0 && cmdstatp->sense_hdr.ascq == 0x17)
STp->cleaning_req = 1;
STp->pos_unknown |= STp->device->was_reset;
if (cmdstatp->have_sense &&
scode == RECOVERED_ERROR
#if ST_RECOVERED_WRITE_FATAL
&& SRpnt->cmd[0] != WRITE_6
&& SRpnt->cmd[0] != WRITE_FILEMARKS
#endif
) {
STp->recover_count++;
STp->recover_reg++;
DEB(
if (debugging) {
if (SRpnt->cmd[0] == READ_6)
stp = "read";
else if (SRpnt->cmd[0] == WRITE_6)
stp = "write";
else
stp = "ioctl";
st_printk(ST_DEB_MSG, STp,
"Recovered %s error (%d).\n",
stp, STp->recover_count);
} )
if (cmdstatp->flags == 0)
return 0;
}
return (-EIO);
}
static struct st_request *st_allocate_request(struct scsi_tape *stp)
{
struct st_request *streq;
streq = kzalloc(sizeof(*streq), GFP_KERNEL);
if (streq)
streq->stp = stp;
else {
st_printk(KERN_ERR, stp,
"Can't get SCSI request.\n");
if (signal_pending(current))
stp->buffer->syscall_result = -EINTR;
else
stp->buffer->syscall_result = -EBUSY;
}
return streq;
}
static void st_release_request(struct st_request *streq)
{
kfree(streq);
}
static void st_do_stats(struct scsi_tape *STp, struct request *req)
{
ktime_t now;
now = ktime_get();
if (req->cmd[0] == WRITE_6) {
now = ktime_sub(now, STp->stats->write_time);
atomic64_add(ktime_to_ns(now), &STp->stats->tot_write_time);
atomic64_add(ktime_to_ns(now), &STp->stats->tot_io_time);
atomic64_inc(&STp->stats->write_cnt);
if (req->errors) {
atomic64_add(atomic_read(&STp->stats->last_write_size)
- STp->buffer->cmdstat.residual,
&STp->stats->write_byte_cnt);
if (STp->buffer->cmdstat.residual > 0)
atomic64_inc(&STp->stats->resid_cnt);
} else
atomic64_add(atomic_read(&STp->stats->last_write_size),
&STp->stats->write_byte_cnt);
} else if (req->cmd[0] == READ_6) {
now = ktime_sub(now, STp->stats->read_time);
atomic64_add(ktime_to_ns(now), &STp->stats->tot_read_time);
atomic64_add(ktime_to_ns(now), &STp->stats->tot_io_time);
atomic64_inc(&STp->stats->read_cnt);
if (req->errors) {
atomic64_add(atomic_read(&STp->stats->last_read_size)
- STp->buffer->cmdstat.residual,
&STp->stats->read_byte_cnt);
if (STp->buffer->cmdstat.residual > 0)
atomic64_inc(&STp->stats->resid_cnt);
} else
atomic64_add(atomic_read(&STp->stats->last_read_size),
&STp->stats->read_byte_cnt);
} else {
now = ktime_sub(now, STp->stats->other_time);
atomic64_add(ktime_to_ns(now), &STp->stats->tot_io_time);
atomic64_inc(&STp->stats->other_cnt);
}
atomic64_dec(&STp->stats->in_flight);
}
static void st_scsi_execute_end(struct request *req, int uptodate)
{
struct st_request *SRpnt = req->end_io_data;
struct scsi_tape *STp = SRpnt->stp;
struct bio *tmp;
STp->buffer->cmdstat.midlevel_result = SRpnt->result = req->errors;
STp->buffer->cmdstat.residual = req->resid_len;
st_do_stats(STp, req);
tmp = SRpnt->bio;
if (SRpnt->waiting)
complete(SRpnt->waiting);
blk_rq_unmap_user(tmp);
__blk_put_request(req->q, req);
}
static int st_scsi_execute(struct st_request *SRpnt, const unsigned char *cmd,
int data_direction, void *buffer, unsigned bufflen,
int timeout, int retries)
{
struct request *req;
struct rq_map_data *mdata = &SRpnt->stp->buffer->map_data;
int err = 0;
int write = (data_direction == DMA_TO_DEVICE);
struct scsi_tape *STp = SRpnt->stp;
req = blk_get_request(SRpnt->stp->device->request_queue, write,
GFP_KERNEL);
if (IS_ERR(req))
return DRIVER_ERROR << 24;
blk_rq_set_block_pc(req);
req->cmd_flags |= REQ_QUIET;
mdata->null_mapped = 1;
if (bufflen) {
err = blk_rq_map_user(req->q, req, mdata, NULL, bufflen,
GFP_KERNEL);
if (err) {
blk_put_request(req);
return DRIVER_ERROR << 24;
}
}
atomic64_inc(&STp->stats->in_flight);
if (cmd[0] == WRITE_6) {
atomic_set(&STp->stats->last_write_size, bufflen);
STp->stats->write_time = ktime_get();
} else if (cmd[0] == READ_6) {
atomic_set(&STp->stats->last_read_size, bufflen);
STp->stats->read_time = ktime_get();
} else {
STp->stats->other_time = ktime_get();
}
SRpnt->bio = req->bio;
req->cmd_len = COMMAND_SIZE(cmd[0]);
memset(req->cmd, 0, BLK_MAX_CDB);
memcpy(req->cmd, cmd, req->cmd_len);
req->sense = SRpnt->sense;
req->sense_len = 0;
req->timeout = timeout;
req->retries = retries;
req->end_io_data = SRpnt;
blk_execute_rq_nowait(req->q, NULL, req, 1, st_scsi_execute_end);
return 0;
}
static struct st_request *
st_do_scsi(struct st_request * SRpnt, struct scsi_tape * STp, unsigned char *cmd,
int bytes, int direction, int timeout, int retries, int do_wait)
{
struct completion *waiting;
struct rq_map_data *mdata = &STp->buffer->map_data;
int ret;
if (!do_wait && ((STp->buffer)->last_SRpnt)) {
st_printk(KERN_ERR, STp,
"Async command already active.\n");
if (signal_pending(current))
(STp->buffer)->syscall_result = (-EINTR);
else
(STp->buffer)->syscall_result = (-EBUSY);
return NULL;
}
if (!SRpnt) {
SRpnt = st_allocate_request(STp);
if (!SRpnt)
return NULL;
}
if (!do_wait)
(STp->buffer)->last_SRpnt = SRpnt;
waiting = &STp->wait;
init_completion(waiting);
SRpnt->waiting = waiting;
if (STp->buffer->do_dio) {
mdata->page_order = 0;
mdata->nr_entries = STp->buffer->sg_segs;
mdata->pages = STp->buffer->mapped_pages;
} else {
mdata->page_order = STp->buffer->reserved_page_order;
mdata->nr_entries =
DIV_ROUND_UP(bytes, PAGE_SIZE << mdata->page_order);
mdata->pages = STp->buffer->reserved_pages;
mdata->offset = 0;
}
memcpy(SRpnt->cmd, cmd, sizeof(SRpnt->cmd));
STp->buffer->cmdstat.have_sense = 0;
STp->buffer->syscall_result = 0;
ret = st_scsi_execute(SRpnt, cmd, direction, NULL, bytes, timeout,
retries);
if (ret) {
(STp->buffer)->syscall_result = (-EBUSY);
(STp->buffer)->last_SRpnt = NULL;
} else if (do_wait) {
wait_for_completion(waiting);
SRpnt->waiting = NULL;
(STp->buffer)->syscall_result = st_chk_result(STp, SRpnt);
}
return SRpnt;
}
static int write_behind_check(struct scsi_tape * STp)
{
int retval = 0;
struct st_buffer *STbuffer;
struct st_partstat *STps;
struct st_cmdstatus *cmdstatp;
struct st_request *SRpnt;
STbuffer = STp->buffer;
if (!STbuffer->writing)
return 0;
DEB(
if (STp->write_pending)
STp->nbr_waits++;
else
STp->nbr_finished++;
)
wait_for_completion(&(STp->wait));
SRpnt = STbuffer->last_SRpnt;
STbuffer->last_SRpnt = NULL;
SRpnt->waiting = NULL;
(STp->buffer)->syscall_result = st_chk_result(STp, SRpnt);
st_release_request(SRpnt);
STbuffer->buffer_bytes -= STbuffer->writing;
STps = &(STp->ps[STp->partition]);
if (STps->drv_block >= 0) {
if (STp->block_size == 0)
STps->drv_block++;
else
STps->drv_block += STbuffer->writing / STp->block_size;
}
cmdstatp = &STbuffer->cmdstat;
if (STbuffer->syscall_result) {
retval = -EIO;
if (cmdstatp->have_sense && !cmdstatp->deferred &&
(cmdstatp->flags & SENSE_EOM) &&
(cmdstatp->sense_hdr.sense_key == NO_SENSE ||
cmdstatp->sense_hdr.sense_key == RECOVERED_ERROR)) {
if (!cmdstatp->remainder_valid ||
cmdstatp->uremainder64 == 0)
retval = -ENOSPC;
}
if (retval == -EIO)
STps->drv_block = -1;
}
STbuffer->writing = 0;
DEB(if (debugging && retval)
st_printk(ST_DEB_MSG, STp,
"Async write error %x, return value %d.\n",
STbuffer->cmdstat.midlevel_result, retval);)
return retval;
}
static int cross_eof(struct scsi_tape * STp, int forward)
{
struct st_request *SRpnt;
unsigned char cmd[MAX_COMMAND_SIZE];
cmd[0] = SPACE;
cmd[1] = 0x01;
if (forward) {
cmd[2] = cmd[3] = 0;
cmd[4] = 1;
} else
cmd[2] = cmd[3] = cmd[4] = 0xff;
cmd[5] = 0;
DEBC_printk(STp, "Stepping over filemark %s.\n",
forward ? "forward" : "backward");
SRpnt = st_do_scsi(NULL, STp, cmd, 0, DMA_NONE,
STp->device->request_queue->rq_timeout,
MAX_RETRIES, 1);
if (!SRpnt)
return (STp->buffer)->syscall_result;
st_release_request(SRpnt);
SRpnt = NULL;
if ((STp->buffer)->cmdstat.midlevel_result != 0)
st_printk(KERN_ERR, STp,
"Stepping over filemark %s failed.\n",
forward ? "forward" : "backward");
return (STp->buffer)->syscall_result;
}
static int st_flush_write_buffer(struct scsi_tape * STp)
{
int transfer, blks;
int result;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
struct st_partstat *STps;
result = write_behind_check(STp);
if (result)
return result;
result = 0;
if (STp->dirty == 1) {
transfer = STp->buffer->buffer_bytes;
DEBC_printk(STp, "Flushing %d bytes.\n", transfer);
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = WRITE_6;
cmd[1] = 1;
blks = transfer / STp->block_size;
cmd[2] = blks >> 16;
cmd[3] = blks >> 8;
cmd[4] = blks;
SRpnt = st_do_scsi(NULL, STp, cmd, transfer, DMA_TO_DEVICE,
STp->device->request_queue->rq_timeout,
MAX_WRITE_RETRIES, 1);
if (!SRpnt)
return (STp->buffer)->syscall_result;
STps = &(STp->ps[STp->partition]);
if ((STp->buffer)->syscall_result != 0) {
struct st_cmdstatus *cmdstatp = &STp->buffer->cmdstat;
if (cmdstatp->have_sense && !cmdstatp->deferred &&
(cmdstatp->flags & SENSE_EOM) &&
(cmdstatp->sense_hdr.sense_key == NO_SENSE ||
cmdstatp->sense_hdr.sense_key == RECOVERED_ERROR) &&
(!cmdstatp->remainder_valid ||
cmdstatp->uremainder64 == 0)) {
STp->dirty = 0;
(STp->buffer)->buffer_bytes = 0;
if (STps->drv_block >= 0)
STps->drv_block += blks;
result = (-ENOSPC);
} else {
st_printk(KERN_ERR, STp, "Error on flush.\n");
STps->drv_block = (-1);
result = (-EIO);
}
} else {
if (STps->drv_block >= 0)
STps->drv_block += blks;
STp->dirty = 0;
(STp->buffer)->buffer_bytes = 0;
}
st_release_request(SRpnt);
SRpnt = NULL;
}
return result;
}
static int flush_buffer(struct scsi_tape *STp, int seek_next)
{
int backspace, result;
struct st_buffer *STbuffer;
struct st_partstat *STps;
STbuffer = STp->buffer;
if (STp->pos_unknown)
return (-EIO);
if (STp->ready != ST_READY)
return 0;
STps = &(STp->ps[STp->partition]);
if (STps->rw == ST_WRITING)
return st_flush_write_buffer(STp);
if (STp->block_size == 0)
return 0;
backspace = ((STp->buffer)->buffer_bytes +
(STp->buffer)->read_pointer) / STp->block_size -
((STp->buffer)->read_pointer + STp->block_size - 1) /
STp->block_size;
(STp->buffer)->buffer_bytes = 0;
(STp->buffer)->read_pointer = 0;
result = 0;
if (!seek_next) {
if (STps->eof == ST_FM_HIT) {
result = cross_eof(STp, 0);
if (!result)
STps->eof = ST_NOEOF;
else {
if (STps->drv_file >= 0)
STps->drv_file++;
STps->drv_block = 0;
}
}
if (!result && backspace > 0)
result = st_int_ioctl(STp, MTBSR, backspace);
} else if (STps->eof == ST_FM_HIT) {
if (STps->drv_file >= 0)
STps->drv_file++;
STps->drv_block = 0;
STps->eof = ST_NOEOF;
}
return result;
}
static int set_mode_densblk(struct scsi_tape * STp, struct st_modedef * STm)
{
int set_it = 0;
unsigned long arg;
if (!STp->density_changed &&
STm->default_density >= 0 &&
STm->default_density != STp->density) {
arg = STm->default_density;
set_it = 1;
} else
arg = STp->density;
arg <<= MT_ST_DENSITY_SHIFT;
if (!STp->blksize_changed &&
STm->default_blksize >= 0 &&
STm->default_blksize != STp->block_size) {
arg |= STm->default_blksize;
set_it = 1;
} else
arg |= STp->block_size;
if (set_it &&
st_int_ioctl(STp, SET_DENS_AND_BLK, arg)) {
st_printk(KERN_WARNING, STp,
"Can't set default block size to %d bytes "
"and density %x.\n",
STm->default_blksize, STm->default_density);
if (modes_defined)
return (-EINVAL);
}
return 0;
}
static int do_door_lock(struct scsi_tape * STp, int do_lock)
{
int retval;
DEBC_printk(STp, "%socking drive door.\n", do_lock ? "L" : "Unl");
retval = scsi_set_medium_removal(STp->device,
do_lock ? SCSI_REMOVAL_PREVENT : SCSI_REMOVAL_ALLOW);
if (!retval)
STp->door_locked = do_lock ? ST_LOCKED_EXPLICIT : ST_UNLOCKED;
else
STp->door_locked = ST_LOCK_FAILS;
return retval;
}
static void reset_state(struct scsi_tape *STp)
{
int i;
struct st_partstat *STps;
STp->pos_unknown = 0;
for (i = 0; i < ST_NBR_PARTITIONS; i++) {
STps = &(STp->ps[i]);
STps->rw = ST_IDLE;
STps->eof = ST_NOEOF;
STps->at_sm = 0;
STps->last_block_valid = 0;
STps->drv_block = -1;
STps->drv_file = -1;
}
if (STp->can_partitions) {
STp->partition = find_partition(STp);
if (STp->partition < 0)
STp->partition = 0;
STp->new_partition = STp->partition;
}
}
static int test_ready(struct scsi_tape *STp, int do_wait)
{
int attentions, waits, max_wait, scode;
int retval = CHKRES_READY, new_session = 0;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt = NULL;
struct st_cmdstatus *cmdstatp = &STp->buffer->cmdstat;
max_wait = do_wait ? ST_BLOCK_SECONDS : 0;
for (attentions=waits=0; ; ) {
memset((void *) &cmd[0], 0, MAX_COMMAND_SIZE);
cmd[0] = TEST_UNIT_READY;
SRpnt = st_do_scsi(SRpnt, STp, cmd, 0, DMA_NONE,
STp->long_timeout, MAX_READY_RETRIES, 1);
if (!SRpnt) {
retval = (STp->buffer)->syscall_result;
break;
}
if (cmdstatp->have_sense) {
scode = cmdstatp->sense_hdr.sense_key;
if (scode == UNIT_ATTENTION) {
new_session = 1;
if (attentions < MAX_ATTENTIONS) {
attentions++;
continue;
}
else {
retval = (-EIO);
break;
}
}
if (scode == NOT_READY) {
if (waits < max_wait) {
if (msleep_interruptible(1000)) {
retval = (-EINTR);
break;
}
waits++;
continue;
}
else {
if ((STp->device)->scsi_level >= SCSI_2 &&
cmdstatp->sense_hdr.asc == 0x3a)
retval = CHKRES_NO_TAPE;
else
retval = CHKRES_NOT_READY;
break;
}
}
}
retval = (STp->buffer)->syscall_result;
if (!retval)
retval = new_session ? CHKRES_NEW_SESSION : CHKRES_READY;
break;
}
if (SRpnt != NULL)
st_release_request(SRpnt);
return retval;
}
static int check_tape(struct scsi_tape *STp, struct file *filp)
{
int i, retval, new_session = 0, do_wait;
unsigned char cmd[MAX_COMMAND_SIZE], saved_cleaning;
unsigned short st_flags = filp->f_flags;
struct st_request *SRpnt = NULL;
struct st_modedef *STm;
struct st_partstat *STps;
struct inode *inode = file_inode(filp);
int mode = TAPE_MODE(inode);
STp->ready = ST_READY;
if (mode != STp->current_mode) {
DEBC_printk(STp, "Mode change from %d to %d.\n",
STp->current_mode, mode);
new_session = 1;
STp->current_mode = mode;
}
STm = &(STp->modes[STp->current_mode]);
saved_cleaning = STp->cleaning_req;
STp->cleaning_req = 0;
do_wait = ((filp->f_flags & O_NONBLOCK) == 0);
retval = test_ready(STp, do_wait);
if (retval < 0)
goto err_out;
if (retval == CHKRES_NEW_SESSION) {
STp->pos_unknown = 0;
STp->partition = STp->new_partition = 0;
if (STp->can_partitions)
STp->nbr_partitions = 1;
for (i = 0; i < ST_NBR_PARTITIONS; i++) {
STps = &(STp->ps[i]);
STps->rw = ST_IDLE;
STps->eof = ST_NOEOF;
STps->at_sm = 0;
STps->last_block_valid = 0;
STps->drv_block = 0;
STps->drv_file = 0;
}
new_session = 1;
}
else {
STp->cleaning_req |= saved_cleaning;
if (retval == CHKRES_NOT_READY || retval == CHKRES_NO_TAPE) {
if (retval == CHKRES_NO_TAPE)
STp->ready = ST_NO_TAPE;
else
STp->ready = ST_NOT_READY;
STp->density = 0;
STp->write_prot = 0;
STp->block_size = 0;
STp->ps[0].drv_file = STp->ps[0].drv_block = (-1);
STp->partition = STp->new_partition = 0;
STp->door_locked = ST_UNLOCKED;
return CHKRES_NOT_READY;
}
}
if (STp->omit_blklims)
STp->min_block = STp->max_block = (-1);
else {
memset((void *) &cmd[0], 0, MAX_COMMAND_SIZE);
cmd[0] = READ_BLOCK_LIMITS;
SRpnt = st_do_scsi(SRpnt, STp, cmd, 6, DMA_FROM_DEVICE,
STp->device->request_queue->rq_timeout,
MAX_READY_RETRIES, 1);
if (!SRpnt) {
retval = (STp->buffer)->syscall_result;
goto err_out;
}
if (!SRpnt->result && !STp->buffer->cmdstat.have_sense) {
STp->max_block = ((STp->buffer)->b_data[1] << 16) |
((STp->buffer)->b_data[2] << 8) | (STp->buffer)->b_data[3];
STp->min_block = ((STp->buffer)->b_data[4] << 8) |
(STp->buffer)->b_data[5];
if ( DEB( debugging || ) !STp->inited)
st_printk(KERN_INFO, STp,
"Block limits %d - %d bytes.\n",
STp->min_block, STp->max_block);
} else {
STp->min_block = STp->max_block = (-1);
DEBC_printk(STp, "Can't read block limits.\n");
}
}
memset((void *) &cmd[0], 0, MAX_COMMAND_SIZE);
cmd[0] = MODE_SENSE;
cmd[4] = 12;
SRpnt = st_do_scsi(SRpnt, STp, cmd, 12, DMA_FROM_DEVICE,
STp->device->request_queue->rq_timeout,
MAX_READY_RETRIES, 1);
if (!SRpnt) {
retval = (STp->buffer)->syscall_result;
goto err_out;
}
if ((STp->buffer)->syscall_result != 0) {
DEBC_printk(STp, "No Mode Sense.\n");
STp->block_size = ST_DEFAULT_BLOCK;
(STp->buffer)->syscall_result = 0;
STp->drv_write_prot = 0;
} else {
DEBC_printk(STp,"Mode sense. Length %d, "
"medium %x, WBS %x, BLL %d\n",
(STp->buffer)->b_data[0],
(STp->buffer)->b_data[1],
(STp->buffer)->b_data[2],
(STp->buffer)->b_data[3]);
if ((STp->buffer)->b_data[3] >= 8) {
STp->drv_buffer = ((STp->buffer)->b_data[2] >> 4) & 7;
STp->density = (STp->buffer)->b_data[4];
STp->block_size = (STp->buffer)->b_data[9] * 65536 +
(STp->buffer)->b_data[10] * 256 + (STp->buffer)->b_data[11];
DEBC_printk(STp, "Density %x, tape length: %x, "
"drv buffer: %d\n",
STp->density,
(STp->buffer)->b_data[5] * 65536 +
(STp->buffer)->b_data[6] * 256 +
(STp->buffer)->b_data[7],
STp->drv_buffer);
}
STp->drv_write_prot = ((STp->buffer)->b_data[2] & 0x80) != 0;
if (!STp->drv_buffer && STp->immediate_filemark) {
st_printk(KERN_WARNING, STp,
"non-buffered tape: disabling "
"writing immediate filemarks\n");
STp->immediate_filemark = 0;
}
}
st_release_request(SRpnt);
SRpnt = NULL;
STp->inited = 1;
if (STp->block_size > 0)
(STp->buffer)->buffer_blocks =
(STp->buffer)->buffer_size / STp->block_size;
else
(STp->buffer)->buffer_blocks = 1;
(STp->buffer)->buffer_bytes = (STp->buffer)->read_pointer = 0;
DEBC_printk(STp, "Block size: %d, buffer size: %d (%d blocks).\n",
STp->block_size, (STp->buffer)->buffer_size,
(STp->buffer)->buffer_blocks);
if (STp->drv_write_prot) {
STp->write_prot = 1;
DEBC_printk(STp, "Write protected\n");
if (do_wait &&
((st_flags & O_ACCMODE) == O_WRONLY ||
(st_flags & O_ACCMODE) == O_RDWR)) {
retval = (-EROFS);
goto err_out;
}
}
if (STp->can_partitions && STp->nbr_partitions < 1) {
DEBC_printk(STp, "Updating partition number in status.\n");
if ((STp->partition = find_partition(STp)) < 0) {
retval = STp->partition;
goto err_out;
}
STp->new_partition = STp->partition;
STp->nbr_partitions = 1;
}
if (new_session) {
STp->density_changed = STp->blksize_changed = 0;
STp->compression_changed = 0;
if (!(STm->defaults_for_writes) &&
(retval = set_mode_densblk(STp, STm)) < 0)
goto err_out;
if (STp->default_drvbuffer != 0xff) {
if (st_int_ioctl(STp, MTSETDRVBUFFER, STp->default_drvbuffer))
st_printk(KERN_WARNING, STp,
"Can't set default drive "
"buffering to %d.\n",
STp->default_drvbuffer);
}
}
return CHKRES_READY;
err_out:
return retval;
}
static int st_open(struct inode *inode, struct file *filp)
{
int i, retval = (-EIO);
int resumed = 0;
struct scsi_tape *STp;
struct st_partstat *STps;
int dev = TAPE_NR(inode);
filp->f_mode &= ~(FMODE_PREAD | FMODE_PWRITE);
if (!(STp = scsi_tape_get(dev))) {
return -ENXIO;
}
filp->private_data = STp;
spin_lock(&st_use_lock);
if (STp->in_use) {
spin_unlock(&st_use_lock);
scsi_tape_put(STp);
DEBC_printk(STp, "Device already in use.\n");
return (-EBUSY);
}
STp->in_use = 1;
spin_unlock(&st_use_lock);
STp->rew_at_close = STp->autorew_dev = (iminor(inode) & 0x80) == 0;
if (scsi_autopm_get_device(STp->device) < 0) {
retval = -EIO;
goto err_out;
}
resumed = 1;
if (!scsi_block_when_processing_errors(STp->device)) {
retval = (-ENXIO);
goto err_out;
}
if (!enlarge_buffer(STp->buffer, PAGE_SIZE, STp->restr_dma)) {
st_printk(KERN_WARNING, STp,
"Can't allocate one page tape buffer.\n");
retval = (-EOVERFLOW);
goto err_out;
}
(STp->buffer)->cleared = 0;
(STp->buffer)->writing = 0;
(STp->buffer)->syscall_result = 0;
STp->write_prot = ((filp->f_flags & O_ACCMODE) == O_RDONLY);
STp->dirty = 0;
for (i = 0; i < ST_NBR_PARTITIONS; i++) {
STps = &(STp->ps[i]);
STps->rw = ST_IDLE;
}
STp->try_dio_now = STp->try_dio;
STp->recover_count = 0;
DEB( STp->nbr_waits = STp->nbr_finished = 0;
STp->nbr_requests = STp->nbr_dio = STp->nbr_pages = 0; )
retval = check_tape(STp, filp);
if (retval < 0)
goto err_out;
if ((filp->f_flags & O_NONBLOCK) == 0 &&
retval != CHKRES_READY) {
if (STp->ready == NO_TAPE)
retval = (-ENOMEDIUM);
else
retval = (-EIO);
goto err_out;
}
return 0;
err_out:
normalize_buffer(STp->buffer);
spin_lock(&st_use_lock);
STp->in_use = 0;
spin_unlock(&st_use_lock);
if (resumed)
scsi_autopm_put_device(STp->device);
scsi_tape_put(STp);
return retval;
}
static int st_flush(struct file *filp, fl_owner_t id)
{
int result = 0, result2;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
struct scsi_tape *STp = filp->private_data;
struct st_modedef *STm = &(STp->modes[STp->current_mode]);
struct st_partstat *STps = &(STp->ps[STp->partition]);
if (file_count(filp) > 1)
return 0;
if (STps->rw == ST_WRITING && !STp->pos_unknown) {
result = st_flush_write_buffer(STp);
if (result != 0 && result != (-ENOSPC))
goto out;
}
if (STp->can_partitions &&
(result2 = switch_partition(STp)) < 0) {
DEBC_printk(STp, "switch_partition at close failed.\n");
if (result == 0)
result = result2;
goto out;
}
DEBC( if (STp->nbr_requests)
st_printk(KERN_DEBUG, STp,
"Number of r/w requests %d, dio used in %d, "
"pages %d.\n", STp->nbr_requests, STp->nbr_dio,
STp->nbr_pages));
if (STps->rw == ST_WRITING && !STp->pos_unknown) {
struct st_cmdstatus *cmdstatp = &STp->buffer->cmdstat;
#if DEBUG
DEBC_printk(STp, "Async write waits %d, finished %d.\n",
STp->nbr_waits, STp->nbr_finished);
#endif
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = WRITE_FILEMARKS;
if (STp->immediate_filemark)
cmd[1] = 1;
cmd[4] = 1 + STp->two_fm;
SRpnt = st_do_scsi(NULL, STp, cmd, 0, DMA_NONE,
STp->device->request_queue->rq_timeout,
MAX_WRITE_RETRIES, 1);
if (!SRpnt) {
result = (STp->buffer)->syscall_result;
goto out;
}
if (STp->buffer->syscall_result == 0 ||
(cmdstatp->have_sense && !cmdstatp->deferred &&
(cmdstatp->flags & SENSE_EOM) &&
(cmdstatp->sense_hdr.sense_key == NO_SENSE ||
cmdstatp->sense_hdr.sense_key == RECOVERED_ERROR) &&
(!cmdstatp->remainder_valid || cmdstatp->uremainder64 == 0))) {
st_release_request(SRpnt);
SRpnt = NULL;
if (STps->drv_file >= 0)
STps->drv_file++;
STps->drv_block = 0;
if (STp->two_fm)
cross_eof(STp, 0);
STps->eof = ST_FM;
}
else {
st_release_request(SRpnt);
SRpnt = NULL;
st_printk(KERN_ERR, STp,
"Error on write filemark.\n");
if (result == 0)
result = (-EIO);
}
DEBC_printk(STp, "Buffer flushed, %d EOF(s) written\n", cmd[4]);
} else if (!STp->rew_at_close) {
STps = &(STp->ps[STp->partition]);
if (!STm->sysv || STps->rw != ST_READING) {
if (STp->can_bsr)
result = flush_buffer(STp, 0);
else if (STps->eof == ST_FM_HIT) {
result = cross_eof(STp, 0);
if (result) {
if (STps->drv_file >= 0)
STps->drv_file++;
STps->drv_block = 0;
STps->eof = ST_FM;
} else
STps->eof = ST_NOEOF;
}
} else if ((STps->eof == ST_NOEOF &&
!(result = cross_eof(STp, 1))) ||
STps->eof == ST_FM_HIT) {
if (STps->drv_file >= 0)
STps->drv_file++;
STps->drv_block = 0;
STps->eof = ST_FM;
}
}
out:
if (STp->rew_at_close) {
result2 = st_int_ioctl(STp, MTREW, 1);
if (result == 0)
result = result2;
}
return result;
}
static int st_release(struct inode *inode, struct file *filp)
{
int result = 0;
struct scsi_tape *STp = filp->private_data;
if (STp->door_locked == ST_LOCKED_AUTO)
do_door_lock(STp, 0);
normalize_buffer(STp->buffer);
spin_lock(&st_use_lock);
STp->in_use = 0;
spin_unlock(&st_use_lock);
scsi_autopm_put_device(STp->device);
scsi_tape_put(STp);
return result;
}
static ssize_t rw_checks(struct scsi_tape *STp, struct file *filp, size_t count)
{
ssize_t retval = 0;
if (!scsi_block_when_processing_errors(STp->device)) {
retval = (-ENXIO);
goto out;
}
if (STp->ready != ST_READY) {
if (STp->ready == ST_NO_TAPE)
retval = (-ENOMEDIUM);
else
retval = (-EIO);
goto out;
}
if (! STp->modes[STp->current_mode].defined) {
retval = (-ENXIO);
goto out;
}
if (STp->pos_unknown) {
retval = (-EIO);
goto out;
}
if (count == 0)
goto out;
DEB(
if (!STp->in_use) {
st_printk(ST_DEB_MSG, STp,
"Incorrect device.\n");
retval = (-EIO);
goto out;
} )
if (STp->can_partitions &&
(retval = switch_partition(STp)) < 0)
goto out;
if (STp->block_size == 0 && STp->max_block > 0 &&
(count < STp->min_block || count > STp->max_block)) {
retval = (-EINVAL);
goto out;
}
if (STp->do_auto_lock && STp->door_locked == ST_UNLOCKED &&
!do_door_lock(STp, 1))
STp->door_locked = ST_LOCKED_AUTO;
out:
return retval;
}
static int setup_buffering(struct scsi_tape *STp, const char __user *buf,
size_t count, int is_read)
{
int i, bufsize, retval = 0;
struct st_buffer *STbp = STp->buffer;
if (is_read)
i = STp->try_dio_now && try_rdio;
else
i = STp->try_dio_now && try_wdio;
if (i && ((unsigned long)buf & queue_dma_alignment(
STp->device->request_queue)) == 0) {
i = sgl_map_user_pages(STbp, STbp->use_sg, (unsigned long)buf,
count, (is_read ? READ : WRITE));
if (i > 0) {
STbp->do_dio = i;
STbp->buffer_bytes = 0;
}
else
STbp->do_dio = 0;
STbp->sg_segs = STbp->do_dio;
DEB(
if (STbp->do_dio) {
STp->nbr_dio++;
STp->nbr_pages += STbp->do_dio;
}
)
} else
STbp->do_dio = 0;
DEB( STp->nbr_requests++; )
if (!STbp->do_dio) {
if (STp->block_size)
bufsize = STp->block_size > st_fixed_buffer_size ?
STp->block_size : st_fixed_buffer_size;
else {
bufsize = count;
if (is_read && STp->sili && !STbp->cleared)
clear_buffer(STbp);
}
if (bufsize > STbp->buffer_size &&
!enlarge_buffer(STbp, bufsize, STp->restr_dma)) {
st_printk(KERN_WARNING, STp,
"Can't allocate %d byte tape buffer.\n",
bufsize);
retval = (-EOVERFLOW);
goto out;
}
if (STp->block_size)
STbp->buffer_blocks = bufsize / STp->block_size;
}
out:
return retval;
}
static void release_buffering(struct scsi_tape *STp, int is_read)
{
struct st_buffer *STbp;
STbp = STp->buffer;
if (STbp->do_dio) {
sgl_unmap_user_pages(STbp, STbp->do_dio, is_read);
STbp->do_dio = 0;
STbp->sg_segs = 0;
}
}
static ssize_t
st_write(struct file *filp, const char __user *buf, size_t count, loff_t * ppos)
{
ssize_t total;
ssize_t i, do_count, blks, transfer;
ssize_t retval;
int undone, retry_eot = 0, scode;
int async_write;
unsigned char cmd[MAX_COMMAND_SIZE];
const char __user *b_point;
struct st_request *SRpnt = NULL;
struct scsi_tape *STp = filp->private_data;
struct st_modedef *STm;
struct st_partstat *STps;
struct st_buffer *STbp;
if (mutex_lock_interruptible(&STp->lock))
return -ERESTARTSYS;
retval = rw_checks(STp, filp, count);
if (retval || count == 0)
goto out;
if (STp->block_size != 0 && (count % STp->block_size) != 0) {
st_printk(KERN_WARNING, STp,
"Write not multiple of tape block size.\n");
retval = (-EINVAL);
goto out;
}
STm = &(STp->modes[STp->current_mode]);
STps = &(STp->ps[STp->partition]);
if (STp->write_prot) {
retval = (-EACCES);
goto out;
}
if (STps->rw == ST_READING) {
retval = flush_buffer(STp, 0);
if (retval)
goto out;
STps->rw = ST_WRITING;
} else if (STps->rw != ST_WRITING &&
STps->drv_file == 0 && STps->drv_block == 0) {
if ((retval = set_mode_densblk(STp, STm)) < 0)
goto out;
if (STm->default_compression != ST_DONT_TOUCH &&
!(STp->compression_changed)) {
if (st_compression(STp, (STm->default_compression == ST_YES))) {
st_printk(KERN_WARNING, STp,
"Can't set default compression.\n");
if (modes_defined) {
retval = (-EINVAL);
goto out;
}
}
}
}
STbp = STp->buffer;
i = write_behind_check(STp);
if (i) {
if (i == -ENOSPC)
STps->eof = ST_EOM_OK;
else
STps->eof = ST_EOM_ERROR;
}
if (STps->eof == ST_EOM_OK) {
STps->eof = ST_EOD_1;
retval = (-ENOSPC);
goto out;
}
else if (STps->eof == ST_EOM_ERROR) {
retval = (-EIO);
goto out;
}
if (STp->block_size != 0 &&
!STbp->do_dio &&
(copy_from_user(&i, buf, 1) != 0 ||
copy_from_user(&i, buf + count - 1, 1) != 0)) {
retval = (-EFAULT);
goto out;
}
retval = setup_buffering(STp, buf, count, 0);
if (retval)
goto out;
total = count;
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = WRITE_6;
cmd[1] = (STp->block_size != 0);
STps->rw = ST_WRITING;
b_point = buf;
while (count > 0 && !retry_eot) {
if (STbp->do_dio) {
do_count = count;
}
else {
if (STp->block_size == 0)
do_count = count;
else {
do_count = STbp->buffer_blocks * STp->block_size -
STbp->buffer_bytes;
if (do_count > count)
do_count = count;
}
i = append_to_buffer(b_point, STbp, do_count);
if (i) {
retval = i;
goto out;
}
}
count -= do_count;
b_point += do_count;
async_write = STp->block_size == 0 && !STbp->do_dio &&
STm->do_async_writes && STps->eof < ST_EOM_OK;
if (STp->block_size != 0 && STm->do_buffer_writes &&
!(STp->try_dio_now && try_wdio) && STps->eof < ST_EOM_OK &&
STbp->buffer_bytes < STbp->buffer_size) {
STp->dirty = 1;
if (!async_write && count == 0)
break;
}
retry_write:
if (STp->block_size == 0)
blks = transfer = do_count;
else {
if (!STbp->do_dio)
blks = STbp->buffer_bytes;
else
blks = do_count;
blks /= STp->block_size;
transfer = blks * STp->block_size;
}
cmd[2] = blks >> 16;
cmd[3] = blks >> 8;
cmd[4] = blks;
SRpnt = st_do_scsi(SRpnt, STp, cmd, transfer, DMA_TO_DEVICE,
STp->device->request_queue->rq_timeout,
MAX_WRITE_RETRIES, !async_write);
if (!SRpnt) {
retval = STbp->syscall_result;
goto out;
}
if (async_write && !STbp->syscall_result) {
STbp->writing = transfer;
STp->dirty = !(STbp->writing ==
STbp->buffer_bytes);
SRpnt = NULL;
DEB( STp->write_pending = 1; )
break;
}
if (STbp->syscall_result != 0) {
struct st_cmdstatus *cmdstatp = &STp->buffer->cmdstat;
DEBC_printk(STp, "Error on write:\n");
if (cmdstatp->have_sense && (cmdstatp->flags & SENSE_EOM)) {
scode = cmdstatp->sense_hdr.sense_key;
if (cmdstatp->remainder_valid)
undone = (int)cmdstatp->uremainder64;
else if (STp->block_size == 0 &&
scode == VOLUME_OVERFLOW)
undone = transfer;
else
undone = 0;
if (STp->block_size != 0)
undone *= STp->block_size;
if (undone <= do_count) {
count += undone;
b_point -= undone;
do_count -= undone;
if (STp->block_size)
blks = (transfer - undone) / STp->block_size;
STps->eof = ST_EOM_OK;
if (STp->block_size == 0 ||
undone > 0 || count == 0)
retval = (-ENOSPC);
DEBC_printk(STp, "EOM with %d "
"bytes unwritten.\n",
(int)count);
} else {
if (!retry_eot && !cmdstatp->deferred &&
(scode == NO_SENSE || scode == RECOVERED_ERROR)) {
move_buffer_data(STp->buffer, transfer - undone);
retry_eot = 1;
if (STps->drv_block >= 0) {
STps->drv_block += (transfer - undone) /
STp->block_size;
}
STps->eof = ST_EOM_OK;
DEBC_printk(STp, "Retry "
"write of %d "
"bytes at EOM.\n",
STp->buffer->buffer_bytes);
goto retry_write;
}
else {
count -= do_count;
blks = do_count = 0;
STps->eof = ST_EOM_ERROR;
STps->drv_block = (-1);
retval = (-EIO);
DEBC_printk(STp, "EOM with "
"lost data.\n");
}
}
} else {
count += do_count;
STps->drv_block = (-1);
retval = STbp->syscall_result;
}
}
if (STps->drv_block >= 0) {
if (STp->block_size == 0)
STps->drv_block += (do_count > 0);
else
STps->drv_block += blks;
}
STbp->buffer_bytes = 0;
STp->dirty = 0;
if (retval || retry_eot) {
if (count < total)
retval = total - count;
goto out;
}
}
if (STps->eof == ST_EOD_1)
STps->eof = ST_EOM_OK;
else if (STps->eof != ST_EOM_OK)
STps->eof = ST_NOEOF;
retval = total - count;
out:
if (SRpnt != NULL)
st_release_request(SRpnt);
release_buffering(STp, 0);
mutex_unlock(&STp->lock);
return retval;
}
static long read_tape(struct scsi_tape *STp, long count,
struct st_request ** aSRpnt)
{
int transfer, blks, bytes;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
struct st_modedef *STm;
struct st_partstat *STps;
struct st_buffer *STbp;
int retval = 0;
if (count == 0)
return 0;
STm = &(STp->modes[STp->current_mode]);
STps = &(STp->ps[STp->partition]);
if (STps->eof == ST_FM_HIT)
return 1;
STbp = STp->buffer;
if (STp->block_size == 0)
blks = bytes = count;
else {
if (!(STp->try_dio_now && try_rdio) && STm->do_read_ahead) {
blks = (STp->buffer)->buffer_blocks;
bytes = blks * STp->block_size;
} else {
bytes = count;
if (!STbp->do_dio && bytes > (STp->buffer)->buffer_size)
bytes = (STp->buffer)->buffer_size;
blks = bytes / STp->block_size;
bytes = blks * STp->block_size;
}
}
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = READ_6;
cmd[1] = (STp->block_size != 0);
if (!cmd[1] && STp->sili)
cmd[1] |= 2;
cmd[2] = blks >> 16;
cmd[3] = blks >> 8;
cmd[4] = blks;
SRpnt = *aSRpnt;
SRpnt = st_do_scsi(SRpnt, STp, cmd, bytes, DMA_FROM_DEVICE,
STp->device->request_queue->rq_timeout,
MAX_RETRIES, 1);
release_buffering(STp, 1);
*aSRpnt = SRpnt;
if (!SRpnt)
return STbp->syscall_result;
STbp->read_pointer = 0;
STps->at_sm = 0;
if (STbp->syscall_result) {
struct st_cmdstatus *cmdstatp = &STp->buffer->cmdstat;
retval = 1;
DEBC_printk(STp,
"Sense: %2x %2x %2x %2x %2x %2x %2x %2x\n",
SRpnt->sense[0], SRpnt->sense[1],
SRpnt->sense[2], SRpnt->sense[3],
SRpnt->sense[4], SRpnt->sense[5],
SRpnt->sense[6], SRpnt->sense[7]);
if (cmdstatp->have_sense) {
if (cmdstatp->sense_hdr.sense_key == BLANK_CHECK)
cmdstatp->flags &= 0xcf;
if (cmdstatp->flags != 0) {
if (cmdstatp->remainder_valid)
transfer = (int)cmdstatp->uremainder64;
else
transfer = 0;
if (cmdstatp->sense_hdr.sense_key == MEDIUM_ERROR) {
if (STp->block_size == 0)
transfer = bytes;
cmdstatp->flags &= ~SENSE_ILI;
}
if (cmdstatp->flags & SENSE_ILI) {
if (STp->block_size == 0 &&
transfer < 0) {
st_printk(KERN_NOTICE, STp,
"Failed to read %d "
"byte block with %d "
"byte transfer.\n",
bytes - transfer,
bytes);
if (STps->drv_block >= 0)
STps->drv_block += 1;
STbp->buffer_bytes = 0;
return (-ENOMEM);
} else if (STp->block_size == 0) {
STbp->buffer_bytes = bytes - transfer;
} else {
st_release_request(SRpnt);
SRpnt = *aSRpnt = NULL;
if (transfer == blks) {
st_printk(KERN_NOTICE, STp,
"Incorrect "
"block size.\n");
if (STps->drv_block >= 0)
STps->drv_block += blks - transfer + 1;
st_int_ioctl(STp, MTBSR, 1);
return (-EIO);
}
STbp->buffer_bytes = (blks - transfer) *
STp->block_size;
DEBC_printk(STp, "ILI but "
"enough data "
"received %ld "
"%d.\n", count,
STbp->buffer_bytes);
if (STps->drv_block >= 0)
STps->drv_block += 1;
if (st_int_ioctl(STp, MTBSR, 1))
return (-EIO);
}
} else if (cmdstatp->flags & SENSE_FMK) {
if (STps->eof != ST_FM_HIT)
STps->eof = ST_FM_HIT;
else
STps->eof = ST_EOD_2;
if (STp->block_size == 0)
STbp->buffer_bytes = 0;
else
STbp->buffer_bytes =
bytes - transfer * STp->block_size;
DEBC_printk(STp, "EOF detected (%d "
"bytes read).\n",
STbp->buffer_bytes);
} else if (cmdstatp->flags & SENSE_EOM) {
if (STps->eof == ST_FM)
STps->eof = ST_EOD_1;
else
STps->eof = ST_EOM_OK;
if (STp->block_size == 0)
STbp->buffer_bytes = bytes - transfer;
else
STbp->buffer_bytes =
bytes - transfer * STp->block_size;
DEBC_printk(STp, "EOM detected (%d "
"bytes read).\n",
STbp->buffer_bytes);
}
}
else {
DEBC_printk(STp, "Tape error while reading.\n");
STps->drv_block = (-1);
if (STps->eof == ST_FM &&
cmdstatp->sense_hdr.sense_key == BLANK_CHECK) {
DEBC_printk(STp, "Zero returned for "
"first BLANK CHECK "
"after EOF.\n");
STps->eof = ST_EOD_2;
} else
retval = (-EIO);
}
if (STbp->buffer_bytes < 0)
STbp->buffer_bytes = 0;
}
else {
retval = STbp->syscall_result;
}
}
else {
STbp->buffer_bytes = bytes;
if (STp->sili)
STbp->buffer_bytes -= STp->buffer->cmdstat.residual;
}
if (STps->drv_block >= 0) {
if (STp->block_size == 0)
STps->drv_block++;
else
STps->drv_block += STbp->buffer_bytes / STp->block_size;
}
return retval;
}
static ssize_t
st_read(struct file *filp, char __user *buf, size_t count, loff_t * ppos)
{
ssize_t total;
ssize_t retval = 0;
ssize_t i, transfer;
int special, do_dio = 0;
struct st_request *SRpnt = NULL;
struct scsi_tape *STp = filp->private_data;
struct st_modedef *STm;
struct st_partstat *STps;
struct st_buffer *STbp = STp->buffer;
if (mutex_lock_interruptible(&STp->lock))
return -ERESTARTSYS;
retval = rw_checks(STp, filp, count);
if (retval || count == 0)
goto out;
STm = &(STp->modes[STp->current_mode]);
if (STp->block_size != 0 && (count % STp->block_size) != 0) {
if (!STm->do_read_ahead) {
retval = (-EINVAL);
goto out;
}
STp->try_dio_now = 0;
}
STps = &(STp->ps[STp->partition]);
if (STps->rw == ST_WRITING) {
retval = flush_buffer(STp, 0);
if (retval)
goto out;
STps->rw = ST_READING;
}
DEB(
if (debugging && STps->eof != ST_NOEOF)
st_printk(ST_DEB_MSG, STp,
"EOF/EOM flag up (%d). Bytes %d\n",
STps->eof, STbp->buffer_bytes);
)
retval = setup_buffering(STp, buf, count, 1);
if (retval)
goto out;
do_dio = STbp->do_dio;
if (STbp->buffer_bytes == 0 &&
STps->eof >= ST_EOD_1) {
if (STps->eof < ST_EOD) {
STps->eof += 1;
retval = 0;
goto out;
}
retval = (-EIO);
goto out;
}
if (do_dio) {
if (copy_from_user(&i, buf, 1) != 0 ||
copy_to_user(buf, &i, 1) != 0 ||
copy_from_user(&i, buf + count - 1, 1) != 0 ||
copy_to_user(buf + count - 1, &i, 1) != 0) {
retval = (-EFAULT);
goto out;
}
}
STps->rw = ST_READING;
for (total = 0, special = 0; total < count && !special;) {
if (STbp->buffer_bytes == 0) {
special = read_tape(STp, count - total, &SRpnt);
if (special < 0) {
retval = special;
goto out;
}
}
if (STbp->buffer_bytes > 0) {
DEB(
if (debugging && STps->eof != ST_NOEOF)
st_printk(ST_DEB_MSG, STp,
"EOF up (%d). Left %d, needed %d.\n",
STps->eof, STbp->buffer_bytes,
(int)(count - total));
)
transfer = STbp->buffer_bytes < count - total ?
STbp->buffer_bytes : count - total;
if (!do_dio) {
i = from_buffer(STbp, buf, transfer);
if (i) {
retval = i;
goto out;
}
}
buf += transfer;
total += transfer;
}
if (STp->block_size == 0)
break;
}
if (total == 0) {
if (STps->eof == ST_FM_HIT) {
STps->eof = ST_FM;
STps->drv_block = 0;
if (STps->drv_file >= 0)
STps->drv_file++;
} else if (STps->eof == ST_EOD_1) {
STps->eof = ST_EOD_2;
STps->drv_block = 0;
if (STps->drv_file >= 0)
STps->drv_file++;
} else if (STps->eof == ST_EOD_2)
STps->eof = ST_EOD;
} else if (STps->eof == ST_FM)
STps->eof = ST_NOEOF;
retval = total;
out:
if (SRpnt != NULL) {
st_release_request(SRpnt);
SRpnt = NULL;
}
if (do_dio) {
release_buffering(STp, 1);
STbp->buffer_bytes = 0;
}
mutex_unlock(&STp->lock);
return retval;
}
static int st_set_options(struct scsi_tape *STp, long options)
{
int value;
long code;
struct st_modedef *STm;
struct cdev *cd0, *cd1;
struct device *d0, *d1;
STm = &(STp->modes[STp->current_mode]);
if (!STm->defined) {
cd0 = STm->cdevs[0];
cd1 = STm->cdevs[1];
d0 = STm->devs[0];
d1 = STm->devs[1];
memcpy(STm, &(STp->modes[0]), sizeof(struct st_modedef));
STm->cdevs[0] = cd0;
STm->cdevs[1] = cd1;
STm->devs[0] = d0;
STm->devs[1] = d1;
modes_defined = 1;
DEBC_printk(STp, "Initialized mode %d definition from mode 0\n",
STp->current_mode);
}
code = options & MT_ST_OPTIONS;
if (code == MT_ST_BOOLEANS) {
STm->do_buffer_writes = (options & MT_ST_BUFFER_WRITES) != 0;
STm->do_async_writes = (options & MT_ST_ASYNC_WRITES) != 0;
STm->defaults_for_writes = (options & MT_ST_DEF_WRITES) != 0;
STm->do_read_ahead = (options & MT_ST_READ_AHEAD) != 0;
STp->two_fm = (options & MT_ST_TWO_FM) != 0;
STp->fast_mteom = (options & MT_ST_FAST_MTEOM) != 0;
STp->do_auto_lock = (options & MT_ST_AUTO_LOCK) != 0;
STp->can_bsr = (options & MT_ST_CAN_BSR) != 0;
STp->omit_blklims = (options & MT_ST_NO_BLKLIMS) != 0;
if ((STp->device)->scsi_level >= SCSI_2)
STp->can_partitions = (options & MT_ST_CAN_PARTITIONS) != 0;
STp->scsi2_logical = (options & MT_ST_SCSI2LOGICAL) != 0;
STp->immediate = (options & MT_ST_NOWAIT) != 0;
STp->immediate_filemark = (options & MT_ST_NOWAIT_EOF) != 0;
STm->sysv = (options & MT_ST_SYSV) != 0;
STp->sili = (options & MT_ST_SILI) != 0;
DEB( debugging = (options & MT_ST_DEBUGGING) != 0;
st_log_options(STp, STm); )
} else if (code == MT_ST_SETBOOLEANS || code == MT_ST_CLEARBOOLEANS) {
value = (code == MT_ST_SETBOOLEANS);
if ((options & MT_ST_BUFFER_WRITES) != 0)
STm->do_buffer_writes = value;
if ((options & MT_ST_ASYNC_WRITES) != 0)
STm->do_async_writes = value;
if ((options & MT_ST_DEF_WRITES) != 0)
STm->defaults_for_writes = value;
if ((options & MT_ST_READ_AHEAD) != 0)
STm->do_read_ahead = value;
if ((options & MT_ST_TWO_FM) != 0)
STp->two_fm = value;
if ((options & MT_ST_FAST_MTEOM) != 0)
STp->fast_mteom = value;
if ((options & MT_ST_AUTO_LOCK) != 0)
STp->do_auto_lock = value;
if ((options & MT_ST_CAN_BSR) != 0)
STp->can_bsr = value;
if ((options & MT_ST_NO_BLKLIMS) != 0)
STp->omit_blklims = value;
if ((STp->device)->scsi_level >= SCSI_2 &&
(options & MT_ST_CAN_PARTITIONS) != 0)
STp->can_partitions = value;
if ((options & MT_ST_SCSI2LOGICAL) != 0)
STp->scsi2_logical = value;
if ((options & MT_ST_NOWAIT) != 0)
STp->immediate = value;
if ((options & MT_ST_NOWAIT_EOF) != 0)
STp->immediate_filemark = value;
if ((options & MT_ST_SYSV) != 0)
STm->sysv = value;
if ((options & MT_ST_SILI) != 0)
STp->sili = value;
DEB(
if ((options & MT_ST_DEBUGGING) != 0)
debugging = value;
st_log_options(STp, STm); )
} else if (code == MT_ST_WRITE_THRESHOLD) {
} else if (code == MT_ST_DEF_BLKSIZE) {
value = (options & ~MT_ST_OPTIONS);
if (value == ~MT_ST_OPTIONS) {
STm->default_blksize = (-1);
DEBC_printk(STp, "Default block size disabled.\n");
} else {
STm->default_blksize = value;
DEBC_printk(STp,"Default block size set to "
"%d bytes.\n", STm->default_blksize);
if (STp->ready == ST_READY) {
STp->blksize_changed = 0;
set_mode_densblk(STp, STm);
}
}
} else if (code == MT_ST_TIMEOUTS) {
value = (options & ~MT_ST_OPTIONS);
if ((value & MT_ST_SET_LONG_TIMEOUT) != 0) {
STp->long_timeout = (value & ~MT_ST_SET_LONG_TIMEOUT) * HZ;
DEBC_printk(STp, "Long timeout set to %d seconds.\n",
(value & ~MT_ST_SET_LONG_TIMEOUT));
} else {
blk_queue_rq_timeout(STp->device->request_queue,
value * HZ);
DEBC_printk(STp, "Normal timeout set to %d seconds.\n",
value);
}
} else if (code == MT_ST_SET_CLN) {
value = (options & ~MT_ST_OPTIONS) & 0xff;
if (value != 0 &&
(value < EXTENDED_SENSE_START ||
value >= SCSI_SENSE_BUFFERSIZE))
return (-EINVAL);
STp->cln_mode = value;
STp->cln_sense_mask = (options >> 8) & 0xff;
STp->cln_sense_value = (options >> 16) & 0xff;
st_printk(KERN_INFO, STp,
"Cleaning request mode %d, mask %02x, value %02x\n",
value, STp->cln_sense_mask, STp->cln_sense_value);
} else if (code == MT_ST_DEF_OPTIONS) {
code = (options & ~MT_ST_CLEAR_DEFAULT);
value = (options & MT_ST_CLEAR_DEFAULT);
if (code == MT_ST_DEF_DENSITY) {
if (value == MT_ST_CLEAR_DEFAULT) {
STm->default_density = (-1);
DEBC_printk(STp,
"Density default disabled.\n");
} else {
STm->default_density = value & 0xff;
DEBC_printk(STp, "Density default set to %x\n",
STm->default_density);
if (STp->ready == ST_READY) {
STp->density_changed = 0;
set_mode_densblk(STp, STm);
}
}
} else if (code == MT_ST_DEF_DRVBUFFER) {
if (value == MT_ST_CLEAR_DEFAULT) {
STp->default_drvbuffer = 0xff;
DEBC_printk(STp,
"Drive buffer default disabled.\n");
} else {
STp->default_drvbuffer = value & 7;
DEBC_printk(STp,
"Drive buffer default set to %x\n",
STp->default_drvbuffer);
if (STp->ready == ST_READY)
st_int_ioctl(STp, MTSETDRVBUFFER, STp->default_drvbuffer);
}
} else if (code == MT_ST_DEF_COMPRESSION) {
if (value == MT_ST_CLEAR_DEFAULT) {
STm->default_compression = ST_DONT_TOUCH;
DEBC_printk(STp,
"Compression default disabled.\n");
} else {
if ((value & 0xff00) != 0) {
STp->c_algo = (value & 0xff00) >> 8;
DEBC_printk(STp, "Compression "
"algorithm set to 0x%x.\n",
STp->c_algo);
}
if ((value & 0xff) != 0xff) {
STm->default_compression = (value & 1 ? ST_YES : ST_NO);
DEBC_printk(STp, "Compression default "
"set to %x\n",
(value & 1));
if (STp->ready == ST_READY) {
STp->compression_changed = 0;
st_compression(STp, (STm->default_compression == ST_YES));
}
}
}
}
} else
return (-EIO);
return 0;
}
static int read_mode_page(struct scsi_tape *STp, int page, int omit_block_descs)
{
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = MODE_SENSE;
if (omit_block_descs)
cmd[1] = MODE_SENSE_OMIT_BDESCS;
cmd[2] = page;
cmd[4] = 255;
SRpnt = st_do_scsi(NULL, STp, cmd, cmd[4], DMA_FROM_DEVICE,
STp->device->request_queue->rq_timeout, 0, 1);
if (SRpnt == NULL)
return (STp->buffer)->syscall_result;
st_release_request(SRpnt);
return STp->buffer->syscall_result;
}
static int write_mode_page(struct scsi_tape *STp, int page, int slow)
{
int pgo;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
int timeout;
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = MODE_SELECT;
cmd[1] = MODE_SELECT_PAGE_FORMAT;
pgo = MODE_HEADER_LENGTH + (STp->buffer)->b_data[MH_OFF_BDESCS_LENGTH];
cmd[4] = pgo + (STp->buffer)->b_data[pgo + MP_OFF_PAGE_LENGTH] + 2;
(STp->buffer)->b_data[MH_OFF_DATA_LENGTH] = 0;
(STp->buffer)->b_data[MH_OFF_MEDIUM_TYPE] = 0;
(STp->buffer)->b_data[MH_OFF_DEV_SPECIFIC] &= ~MH_BIT_WP;
(STp->buffer)->b_data[pgo + MP_OFF_PAGE_NBR] &= MP_MSK_PAGE_NBR;
timeout = slow ?
STp->long_timeout : STp->device->request_queue->rq_timeout;
SRpnt = st_do_scsi(NULL, STp, cmd, cmd[4], DMA_TO_DEVICE,
timeout, 0, 1);
if (SRpnt == NULL)
return (STp->buffer)->syscall_result;
st_release_request(SRpnt);
return STp->buffer->syscall_result;
}
static int st_compression(struct scsi_tape * STp, int state)
{
int retval;
int mpoffs;
unsigned char *b_data = (STp->buffer)->b_data;
if (STp->ready != ST_READY)
return (-EIO);
retval = read_mode_page(STp, COMPRESSION_PAGE, 0);
if (retval) {
DEBC_printk(STp, "Compression mode page not supported.\n");
return (-EIO);
}
mpoffs = MODE_HEADER_LENGTH + b_data[MH_OFF_BDESCS_LENGTH];
DEBC_printk(STp, "Compression state is %d.\n",
(b_data[mpoffs + CP_OFF_DCE_DCC] & DCE_MASK ? 1 : 0));
if ((b_data[mpoffs + CP_OFF_DCE_DCC] & DCC_MASK) == 0) {
DEBC_printk(STp, "Compression not supported.\n");
return (-EIO);
}
if (state) {
b_data[mpoffs + CP_OFF_DCE_DCC] |= DCE_MASK;
if (STp->c_algo != 0)
b_data[mpoffs + CP_OFF_C_ALGO] = STp->c_algo;
}
else {
b_data[mpoffs + CP_OFF_DCE_DCC] &= ~DCE_MASK;
if (STp->c_algo != 0)
b_data[mpoffs + CP_OFF_C_ALGO] = 0;
}
retval = write_mode_page(STp, COMPRESSION_PAGE, 0);
if (retval) {
DEBC_printk(STp, "Compression change failed.\n");
return (-EIO);
}
DEBC_printk(STp, "Compression state changed to %d.\n", state);
STp->compression_changed = 1;
return 0;
}
static int do_load_unload(struct scsi_tape *STp, struct file *filp, int load_code)
{
int retval = (-EIO), timeout;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_partstat *STps;
struct st_request *SRpnt;
if (STp->ready != ST_READY && !load_code) {
if (STp->ready == ST_NO_TAPE)
return (-ENOMEDIUM);
else
return (-EIO);
}
memset(cmd, 0, MAX_COMMAND_SIZE);
cmd[0] = START_STOP;
if (load_code)
cmd[4] |= 1;
if (load_code >= 1 + MT_ST_HPLOADER_OFFSET
&& load_code <= 6 + MT_ST_HPLOADER_OFFSET) {
DEBC_printk(STp, " Enhanced %sload slot %2d.\n",
(cmd[4]) ? "" : "un",
load_code - MT_ST_HPLOADER_OFFSET);
cmd[3] = load_code - MT_ST_HPLOADER_OFFSET;
}
if (STp->immediate) {
cmd[1] = 1;
timeout = STp->device->request_queue->rq_timeout;
}
else
timeout = STp->long_timeout;
DEBC(
if (!load_code)
st_printk(ST_DEB_MSG, STp, "Unloading tape.\n");
else
st_printk(ST_DEB_MSG, STp, "Loading tape.\n");
);
SRpnt = st_do_scsi(NULL, STp, cmd, 0, DMA_NONE,
timeout, MAX_RETRIES, 1);
if (!SRpnt)
return (STp->buffer)->syscall_result;
retval = (STp->buffer)->syscall_result;
st_release_request(SRpnt);
if (!retval) {
if (!load_code) {
STp->rew_at_close = 0;
STp->ready = ST_NO_TAPE;
}
else {
STp->rew_at_close = STp->autorew_dev;
retval = check_tape(STp, filp);
if (retval > 0)
retval = 0;
}
}
else {
STps = &(STp->ps[STp->partition]);
STps->drv_file = STps->drv_block = (-1);
}
return retval;
}
static void deb_space_print(struct scsi_tape *STp, int direction, char *units, unsigned char *cmd)
{
s32 sc;
if (!debugging)
return;
sc = cmd[2] & 0x80 ? 0xff000000 : 0;
sc |= (cmd[2] << 16) | (cmd[3] << 8) | cmd[4];
if (direction)
sc = -sc;
st_printk(ST_DEB_MSG, STp, "Spacing tape %s over %d %s.\n",
direction ? "backward" : "forward", sc, units);
}
static void deb_space_print(struct scsi_tape *STp, int direction, char *units, unsigned char *cmd) {}
static int st_int_ioctl(struct scsi_tape *STp, unsigned int cmd_in, unsigned long arg)
{
int timeout;
long ltmp;
int ioctl_result;
int chg_eof = 1;
unsigned char cmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
struct st_partstat *STps;
int fileno, blkno, at_sm, undone;
int datalen = 0, direction = DMA_NONE;
WARN_ON(STp->buffer->do_dio != 0);
if (STp->ready != ST_READY) {
if (STp->ready == ST_NO_TAPE)
return (-ENOMEDIUM);
else
return (-EIO);
}
timeout = STp->long_timeout;
STps = &(STp->ps[STp->partition]);
fileno = STps->drv_file;
blkno = STps->drv_block;
at_sm = STps->at_sm;
memset(cmd, 0, MAX_COMMAND_SIZE);
switch (cmd_in) {
case MTFSFM:
chg_eof = 0;
case MTFSF:
cmd[0] = SPACE;
cmd[1] = 0x01;
cmd[2] = (arg >> 16);
cmd[3] = (arg >> 8);
cmd[4] = arg;
deb_space_print(STp, ST_DEB_FORWARD, "filemarks", cmd);
if (fileno >= 0)
fileno += arg;
blkno = 0;
at_sm &= (arg == 0);
break;
case MTBSFM:
chg_eof = 0;
case MTBSF:
cmd[0] = SPACE;
cmd[1] = 0x01;
ltmp = (-arg);
cmd[2] = (ltmp >> 16);
cmd[3] = (ltmp >> 8);
cmd[4] = ltmp;
deb_space_print(STp, ST_DEB_BACKWARD, "filemarks", cmd);
if (fileno >= 0)
fileno -= arg;
blkno = (-1);
at_sm &= (arg == 0);
break;
case MTFSR:
cmd[0] = SPACE;
cmd[1] = 0x00;
cmd[2] = (arg >> 16);
cmd[3] = (arg >> 8);
cmd[4] = arg;
deb_space_print(STp, ST_DEB_FORWARD, "blocks", cmd);
if (blkno >= 0)
blkno += arg;
at_sm &= (arg == 0);
break;
case MTBSR:
cmd[0] = SPACE;
cmd[1] = 0x00;
ltmp = (-arg);
cmd[2] = (ltmp >> 16);
cmd[3] = (ltmp >> 8);
cmd[4] = ltmp;
deb_space_print(STp, ST_DEB_BACKWARD, "blocks", cmd);
if (blkno >= 0)
blkno -= arg;
at_sm &= (arg == 0);
break;
case MTFSS:
cmd[0] = SPACE;
cmd[1] = 0x04;
cmd[2] = (arg >> 16);
cmd[3] = (arg >> 8);
cmd[4] = arg;
deb_space_print(STp, ST_DEB_FORWARD, "setmarks", cmd);
if (arg != 0) {
blkno = fileno = (-1);
at_sm = 1;
}
break;
case MTBSS:
cmd[0] = SPACE;
cmd[1] = 0x04;
ltmp = (-arg);
cmd[2] = (ltmp >> 16);
cmd[3] = (ltmp >> 8);
cmd[4] = ltmp;
deb_space_print(STp, ST_DEB_BACKWARD, "setmarks", cmd);
if (arg != 0) {
blkno = fileno = (-1);
at_sm = 1;
}
break;
case MTWEOF:
case MTWEOFI:
case MTWSM:
if (STp->write_prot)
return (-EACCES);
cmd[0] = WRITE_FILEMARKS;
if (cmd_in == MTWSM)
cmd[1] = 2;
if (cmd_in == MTWEOFI ||
(cmd_in == MTWEOF && STp->immediate_filemark))
cmd[1] |= 1;
cmd[2] = (arg >> 16);
cmd[3] = (arg >> 8);
cmd[4] = arg;
timeout = STp->device->request_queue->rq_timeout;
DEBC(
if (cmd_in != MTWSM)
st_printk(ST_DEB_MSG, STp,
"Writing %d filemarks.\n",
cmd[2] * 65536 +
cmd[3] * 256 +
cmd[4]);
else
st_printk(ST_DEB_MSG, STp,
"Writing %d setmarks.\n",
cmd[2] * 65536 +
cmd[3] * 256 +
cmd[4]);
)
if (fileno >= 0)
fileno += arg;
blkno = 0;
at_sm = (cmd_in == MTWSM);
break;
case MTREW:
cmd[0] = REZERO_UNIT;
if (STp->immediate) {
cmd[1] = 1;
timeout = STp->device->request_queue->rq_timeout;
}
DEBC_printk(STp, "Rewinding tape.\n");
fileno = blkno = at_sm = 0;
break;
case MTNOP:
DEBC_printk(STp, "No op on tape.\n");
return 0;
break;
case MTRETEN:
cmd[0] = START_STOP;
if (STp->immediate) {
cmd[1] = 1;
timeout = STp->device->request_queue->rq_timeout;
}
cmd[4] = 3;
DEBC_printk(STp, "Retensioning tape.\n");
fileno = blkno = at_sm = 0;
break;
case MTEOM:
if (!STp->fast_mteom) {
ioctl_result = st_int_ioctl(STp, MTFSF, 0x7fffff);
fileno = STps->drv_file;
if (STps->eof >= ST_EOD_1)
return 0;
} else
fileno = (-1);
cmd[0] = SPACE;
cmd[1] = 3;
DEBC_printk(STp, "Spacing to end of recorded medium.\n");
blkno = -1;
at_sm = 0;
break;
case MTERASE:
if (STp->write_prot)
return (-EACCES);
cmd[0] = ERASE;
cmd[1] = (arg ? 1 : 0);
if (STp->immediate) {
cmd[1] |= 2;
timeout = STp->device->request_queue->rq_timeout;
}
else
timeout = STp->long_timeout * 8;
DEBC_printk(STp, "Erasing tape.\n");
fileno = blkno = at_sm = 0;
break;
case MTSETBLK:
case MTSETDENSITY:
case MTSETDRVBUFFER:
case SET_DENS_AND_BLK:
chg_eof = 0;
if (STp->dirty || (STp->buffer)->buffer_bytes != 0)
return (-EIO);
if ((cmd_in == MTSETBLK || cmd_in == SET_DENS_AND_BLK) &&
(arg & MT_ST_BLKSIZE_MASK) != 0 &&
STp->max_block > 0 &&
((arg & MT_ST_BLKSIZE_MASK) < STp->min_block ||
(arg & MT_ST_BLKSIZE_MASK) > STp->max_block)) {
st_printk(KERN_WARNING, STp, "Illegal block size.\n");
return (-EINVAL);
}
cmd[0] = MODE_SELECT;
if ((STp->use_pf & USE_PF))
cmd[1] = MODE_SELECT_PAGE_FORMAT;
cmd[4] = datalen = 12;
direction = DMA_TO_DEVICE;
memset((STp->buffer)->b_data, 0, 12);
if (cmd_in == MTSETDRVBUFFER)
(STp->buffer)->b_data[2] = (arg & 7) << 4;
else
(STp->buffer)->b_data[2] =
STp->drv_buffer << 4;
(STp->buffer)->b_data[3] = 8;
if (cmd_in == MTSETDENSITY) {
(STp->buffer)->b_data[4] = arg;
STp->density_changed = 1;
} else if (cmd_in == SET_DENS_AND_BLK)
(STp->buffer)->b_data[4] = arg >> 24;
else
(STp->buffer)->b_data[4] = STp->density;
if (cmd_in == MTSETBLK || cmd_in == SET_DENS_AND_BLK) {
ltmp = arg & MT_ST_BLKSIZE_MASK;
if (cmd_in == MTSETBLK)
STp->blksize_changed = 1;
} else
ltmp = STp->block_size;
(STp->buffer)->b_data[9] = (ltmp >> 16);
(STp->buffer)->b_data[10] = (ltmp >> 8);
(STp->buffer)->b_data[11] = ltmp;
timeout = STp->device->request_queue->rq_timeout;
DEBC(
if (cmd_in == MTSETBLK || cmd_in == SET_DENS_AND_BLK)
st_printk(ST_DEB_MSG, STp,
"Setting block size to %d bytes.\n",
(STp->buffer)->b_data[9] * 65536 +
(STp->buffer)->b_data[10] * 256 +
(STp->buffer)->b_data[11]);
if (cmd_in == MTSETDENSITY || cmd_in == SET_DENS_AND_BLK)
st_printk(ST_DEB_MSG, STp,
"Setting density code to %x.\n",
(STp->buffer)->b_data[4]);
if (cmd_in == MTSETDRVBUFFER)
st_printk(ST_DEB_MSG, STp,
"Setting drive buffer code to %d.\n",
((STp->buffer)->b_data[2] >> 4) & 7);
)
break;
default:
return (-ENOSYS);
}
SRpnt = st_do_scsi(NULL, STp, cmd, datalen, direction,
timeout, MAX_RETRIES, 1);
if (!SRpnt)
return (STp->buffer)->syscall_result;
ioctl_result = (STp->buffer)->syscall_result;
if (!ioctl_result) {
st_release_request(SRpnt);
SRpnt = NULL;
STps->drv_block = blkno;
STps->drv_file = fileno;
STps->at_sm = at_sm;
if (cmd_in == MTBSFM)
ioctl_result = st_int_ioctl(STp, MTFSF, 1);
else if (cmd_in == MTFSFM)
ioctl_result = st_int_ioctl(STp, MTBSF, 1);
if (cmd_in == MTSETBLK || cmd_in == SET_DENS_AND_BLK) {
STp->block_size = arg & MT_ST_BLKSIZE_MASK;
if (STp->block_size != 0) {
(STp->buffer)->buffer_blocks =
(STp->buffer)->buffer_size / STp->block_size;
}
(STp->buffer)->buffer_bytes = (STp->buffer)->read_pointer = 0;
if (cmd_in == SET_DENS_AND_BLK)
STp->density = arg >> MT_ST_DENSITY_SHIFT;
} else if (cmd_in == MTSETDRVBUFFER)
STp->drv_buffer = (arg & 7);
else if (cmd_in == MTSETDENSITY)
STp->density = arg;
if (cmd_in == MTEOM)
STps->eof = ST_EOD;
else if (cmd_in == MTFSF)
STps->eof = ST_FM;
else if (chg_eof)
STps->eof = ST_NOEOF;
if (cmd_in == MTWEOF || cmd_in == MTWEOFI)
STps->rw = ST_IDLE;
} else {
struct st_cmdstatus *cmdstatp = &STp->buffer->cmdstat;
if (cmdstatp->flags & SENSE_EOM) {
if (cmd_in != MTBSF && cmd_in != MTBSFM &&
cmd_in != MTBSR && cmd_in != MTBSS)
STps->eof = ST_EOM_OK;
STps->drv_block = 0;
}
if (cmdstatp->remainder_valid)
undone = (int)cmdstatp->uremainder64;
else
undone = 0;
if ((cmd_in == MTWEOF || cmd_in == MTWEOFI) &&
cmdstatp->have_sense &&
(cmdstatp->flags & SENSE_EOM)) {
if (cmdstatp->sense_hdr.sense_key == NO_SENSE ||
cmdstatp->sense_hdr.sense_key == RECOVERED_ERROR) {
ioctl_result = 0;
STps->eof = ST_NOEOF;
} else {
if (fileno >= 0)
fileno -= undone;
if (undone < arg)
STps->eof = ST_NOEOF;
}
STps->drv_file = fileno;
} else if ((cmd_in == MTFSF) || (cmd_in == MTFSFM)) {
if (fileno >= 0)
STps->drv_file = fileno - undone;
else
STps->drv_file = fileno;
STps->drv_block = -1;
STps->eof = ST_NOEOF;
} else if ((cmd_in == MTBSF) || (cmd_in == MTBSFM)) {
if (arg > 0 && undone < 0)
undone = (-undone);
if (STps->drv_file >= 0)
STps->drv_file = fileno + undone;
STps->drv_block = 0;
STps->eof = ST_NOEOF;
} else if (cmd_in == MTFSR) {
if (cmdstatp->flags & SENSE_FMK) {
if (STps->drv_file >= 0)
STps->drv_file++;
STps->drv_block = 0;
STps->eof = ST_FM;
} else {
if (blkno >= undone)
STps->drv_block = blkno - undone;
else
STps->drv_block = (-1);
STps->eof = ST_NOEOF;
}
} else if (cmd_in == MTBSR) {
if (cmdstatp->flags & SENSE_FMK) {
STps->drv_file--;
STps->drv_block = (-1);
} else {
if (arg > 0 && undone < 0)
undone = (-undone);
if (STps->drv_block >= 0)
STps->drv_block = blkno + undone;
}
STps->eof = ST_NOEOF;
} else if (cmd_in == MTEOM) {
STps->drv_file = (-1);
STps->drv_block = (-1);
STps->eof = ST_EOD;
} else if (cmd_in == MTSETBLK ||
cmd_in == MTSETDENSITY ||
cmd_in == MTSETDRVBUFFER ||
cmd_in == SET_DENS_AND_BLK) {
if (cmdstatp->sense_hdr.sense_key == ILLEGAL_REQUEST &&
!(STp->use_pf & PF_TESTED)) {
STp->use_pf = (STp->use_pf ^ USE_PF) | PF_TESTED;
st_release_request(SRpnt);
SRpnt = NULL;
return st_int_ioctl(STp, cmd_in, arg);
}
} else if (chg_eof)
STps->eof = ST_NOEOF;
if (cmdstatp->sense_hdr.sense_key == BLANK_CHECK)
STps->eof = ST_EOD;
st_release_request(SRpnt);
SRpnt = NULL;
}
return ioctl_result;
}
static int get_location(struct scsi_tape *STp, unsigned int *block, int *partition,
int logical)
{
int result;
unsigned char scmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
if (STp->ready != ST_READY)
return (-EIO);
memset(scmd, 0, MAX_COMMAND_SIZE);
if ((STp->device)->scsi_level < SCSI_2) {
scmd[0] = QFA_REQUEST_BLOCK;
scmd[4] = 3;
} else {
scmd[0] = READ_POSITION;
if (!logical && !STp->scsi2_logical)
scmd[1] = 1;
}
SRpnt = st_do_scsi(NULL, STp, scmd, 20, DMA_FROM_DEVICE,
STp->device->request_queue->rq_timeout,
MAX_READY_RETRIES, 1);
if (!SRpnt)
return (STp->buffer)->syscall_result;
if ((STp->buffer)->syscall_result != 0 ||
(STp->device->scsi_level >= SCSI_2 &&
((STp->buffer)->b_data[0] & 4) != 0)) {
*block = *partition = 0;
DEBC_printk(STp, " Can't read tape position.\n");
result = (-EIO);
} else {
result = 0;
if ((STp->device)->scsi_level < SCSI_2) {
*block = ((STp->buffer)->b_data[0] << 16)
+ ((STp->buffer)->b_data[1] << 8)
+ (STp->buffer)->b_data[2];
*partition = 0;
} else {
*block = ((STp->buffer)->b_data[4] << 24)
+ ((STp->buffer)->b_data[5] << 16)
+ ((STp->buffer)->b_data[6] << 8)
+ (STp->buffer)->b_data[7];
*partition = (STp->buffer)->b_data[1];
if (((STp->buffer)->b_data[0] & 0x80) &&
(STp->buffer)->b_data[1] == 0)
STp->ps[0].drv_block = STp->ps[0].drv_file = 0;
}
DEBC_printk(STp, "Got tape pos. blk %d part %d.\n",
*block, *partition);
}
st_release_request(SRpnt);
SRpnt = NULL;
return result;
}
static int set_location(struct scsi_tape *STp, unsigned int block, int partition,
int logical)
{
struct st_partstat *STps;
int result, p;
unsigned int blk;
int timeout;
unsigned char scmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
if (STp->ready != ST_READY)
return (-EIO);
timeout = STp->long_timeout;
STps = &(STp->ps[STp->partition]);
DEBC_printk(STp, "Setting block to %d and partition to %d.\n",
block, partition);
DEB(if (partition < 0)
return (-EIO); )
if ((!STp->can_partitions && partition != 0) ||
partition >= ST_NBR_PARTITIONS)
return (-EINVAL);
if (partition != STp->partition) {
if (get_location(STp, &blk, &p, 1))
STps->last_block_valid = 0;
else {
STps->last_block_valid = 1;
STps->last_block_visited = blk;
DEBC_printk(STp, "Visited block %d for "
"partition %d saved.\n",
blk, STp->partition);
}
}
memset(scmd, 0, MAX_COMMAND_SIZE);
if ((STp->device)->scsi_level < SCSI_2) {
scmd[0] = QFA_SEEK_BLOCK;
scmd[2] = (block >> 16);
scmd[3] = (block >> 8);
scmd[4] = block;
scmd[5] = 0;
} else {
scmd[0] = SEEK_10;
scmd[3] = (block >> 24);
scmd[4] = (block >> 16);
scmd[5] = (block >> 8);
scmd[6] = block;
if (!logical && !STp->scsi2_logical)
scmd[1] = 4;
if (STp->partition != partition) {
scmd[1] |= 2;
scmd[8] = partition;
DEBC_printk(STp, "Trying to change partition "
"from %d to %d\n", STp->partition,
partition);
}
}
if (STp->immediate) {
scmd[1] |= 1;
timeout = STp->device->request_queue->rq_timeout;
}
SRpnt = st_do_scsi(NULL, STp, scmd, 0, DMA_NONE,
timeout, MAX_READY_RETRIES, 1);
if (!SRpnt)
return (STp->buffer)->syscall_result;
STps->drv_block = STps->drv_file = (-1);
STps->eof = ST_NOEOF;
if ((STp->buffer)->syscall_result != 0) {
result = (-EIO);
if (STp->can_partitions &&
(STp->device)->scsi_level >= SCSI_2 &&
(p = find_partition(STp)) >= 0)
STp->partition = p;
} else {
if (STp->can_partitions) {
STp->partition = partition;
STps = &(STp->ps[partition]);
if (!STps->last_block_valid ||
STps->last_block_visited != block) {
STps->at_sm = 0;
STps->rw = ST_IDLE;
}
} else
STps->at_sm = 0;
if (block == 0)
STps->drv_block = STps->drv_file = 0;
result = 0;
}
st_release_request(SRpnt);
SRpnt = NULL;
return result;
}
static int find_partition(struct scsi_tape *STp)
{
int i, partition;
unsigned int block;
if ((i = get_location(STp, &block, &partition, 1)) < 0)
return i;
if (partition >= ST_NBR_PARTITIONS)
return (-EIO);
return partition;
}
static int switch_partition(struct scsi_tape *STp)
{
struct st_partstat *STps;
if (STp->partition == STp->new_partition)
return 0;
STps = &(STp->ps[STp->new_partition]);
if (!STps->last_block_valid)
STps->last_block_visited = 0;
return set_location(STp, STps->last_block_visited, STp->new_partition, 1);
}
static int nbr_partitions(struct scsi_tape *STp)
{
int result;
if (STp->ready != ST_READY)
return (-EIO);
result = read_mode_page(STp, PART_PAGE, 1);
if (result) {
DEBC_printk(STp, "Can't read medium partition page.\n");
result = (-EIO);
} else {
result = (STp->buffer)->b_data[MODE_HEADER_LENGTH +
PP_OFF_NBR_ADD_PARTS] + 1;
DEBC_printk(STp, "Number of partitions %d.\n", result);
}
return result;
}
static int format_medium(struct scsi_tape *STp, int format)
{
int result = 0;
int timeout = STp->long_timeout;
unsigned char scmd[MAX_COMMAND_SIZE];
struct st_request *SRpnt;
memset(scmd, 0, MAX_COMMAND_SIZE);
scmd[0] = FORMAT_UNIT;
scmd[2] = format;
if (STp->immediate) {
scmd[1] |= 1;
timeout = STp->device->request_queue->rq_timeout;
}
DEBC_printk(STp, "Sending FORMAT MEDIUM\n");
SRpnt = st_do_scsi(NULL, STp, scmd, 0, DMA_NONE,
timeout, MAX_RETRIES, 1);
if (!SRpnt)
result = STp->buffer->syscall_result;
return result;
}
static int partition_tape(struct scsi_tape *STp, int size)
{
int result;
int target_partition;
bool scsi3 = STp->device->scsi_level >= SCSI_3, needs_format = false;
int pgo, psd_cnt, psdo;
int psum = PP_MSK_PSUM_MB, units = 0;
unsigned char *bp;
result = read_mode_page(STp, PART_PAGE, 0);
if (result) {
DEBC_printk(STp, "Can't read partition mode page.\n");
return result;
}
target_partition = 1;
if (size < 0) {
target_partition = 0;
size = -size;
}
bp = (STp->buffer)->b_data;
pgo = MODE_HEADER_LENGTH + bp[MH_OFF_BDESCS_LENGTH];
DEBC_printk(STp, "Partition page length is %d bytes.\n",
bp[pgo + MP_OFF_PAGE_LENGTH] + 2);
psd_cnt = (bp[pgo + MP_OFF_PAGE_LENGTH] + 2 - PART_PAGE_FIXED_LENGTH) / 2;
if (scsi3) {
needs_format = (bp[pgo + PP_OFF_FLAGS] & PP_MSK_POFM) != 0;
if (needs_format && size == 0) {
DEBC_printk(STp, "Formatting tape with one partition.\n");
result = format_medium(STp, 0);
goto out;
}
if (needs_format)
psd_cnt = 2;
if ((bp[pgo + PP_OFF_FLAGS] & PP_MSK_PSUM_UNITS) == PP_MSK_PSUM_UNITS) {
if (size >= 1000 && (size % 1000) == 0) {
size /= 1000;
psum = PP_MSK_PSUM_UNITS;
units = 9;
}
}
if (psum == PP_MSK_PSUM_MB && size >= 65534) {
size /= 1000;
psum = PP_MSK_PSUM_UNITS;
units = 9;
}
}
if (size >= 65535 ||
(target_partition == 0 && psd_cnt < 2)) {
result = -EINVAL;
goto out;
}
psdo = pgo + PART_PAGE_FIXED_LENGTH;
if (target_partition > 0 &&
(psd_cnt > bp[pgo + PP_OFF_MAX_ADD_PARTS] ||
bp[pgo + PP_OFF_MAX_ADD_PARTS] != 1)) {
bp[psdo] = bp[psdo + 1] = 0xff;
psdo += 2;
}
memset(bp + psdo, 0, bp[pgo + PP_OFF_NBR_ADD_PARTS] * 2);
DEBC_printk(STp, "psd_cnt %d, max.parts %d, nbr_parts %d\n",
psd_cnt, bp[pgo + PP_OFF_MAX_ADD_PARTS],
bp[pgo + PP_OFF_NBR_ADD_PARTS]);
if (size == 0) {
bp[pgo + PP_OFF_NBR_ADD_PARTS] = 0;
if (psd_cnt <= bp[pgo + PP_OFF_MAX_ADD_PARTS])
bp[pgo + MP_OFF_PAGE_LENGTH] = 6;
DEBC_printk(STp, "Formatting tape with one partition.\n");
} else {
bp[psdo] = (size >> 8) & 0xff;
bp[psdo + 1] = size & 0xff;
if (target_partition == 0)
bp[psdo + 2] = bp[psdo + 3] = 0xff;
bp[pgo + 3] = 1;
if (bp[pgo + MP_OFF_PAGE_LENGTH] < 8)
bp[pgo + MP_OFF_PAGE_LENGTH] = 8;
DEBC_printk(STp,
"Formatting tape with two partitions (%i = %d MB).\n",
target_partition, units > 0 ? size * 1000 : size);
}
bp[pgo + PP_OFF_PART_UNITS] = 0;
bp[pgo + PP_OFF_RESERVED] = 0;
if (size != 1 || units != 0) {
bp[pgo + PP_OFF_FLAGS] = PP_BIT_IDP | psum |
(bp[pgo + PP_OFF_FLAGS] & 0x07);
bp[pgo + PP_OFF_PART_UNITS] = units;
} else
bp[pgo + PP_OFF_FLAGS] = PP_BIT_FDP |
(bp[pgo + PP_OFF_FLAGS] & 0x1f);
bp[pgo + MP_OFF_PAGE_LENGTH] = 6 + psd_cnt * 2;
result = write_mode_page(STp, PART_PAGE, 1);
if (!result && needs_format)
result = format_medium(STp, 1);
if (result) {
st_printk(KERN_INFO, STp, "Partitioning of tape failed.\n");
result = (-EIO);
}
out:
return result;
}
static long st_ioctl(struct file *file, unsigned int cmd_in, unsigned long arg)
{
int i, cmd_nr, cmd_type, bt;
int retval = 0;
unsigned int blk;
struct scsi_tape *STp = file->private_data;
struct st_modedef *STm;
struct st_partstat *STps;
void __user *p = (void __user *)arg;
if (mutex_lock_interruptible(&STp->lock))
return -ERESTARTSYS;
DEB(
if (debugging && !STp->in_use) {
st_printk(ST_DEB_MSG, STp, "Incorrect device.\n");
retval = (-EIO);
goto out;
} )
STm = &(STp->modes[STp->current_mode]);
STps = &(STp->ps[STp->partition]);
retval = scsi_ioctl_block_when_processing_errors(STp->device, cmd_in,
file->f_flags & O_NDELAY);
if (retval)
goto out;
cmd_type = _IOC_TYPE(cmd_in);
cmd_nr = _IOC_NR(cmd_in);
if (cmd_type == _IOC_TYPE(MTIOCTOP) && cmd_nr == _IOC_NR(MTIOCTOP)) {
struct mtop mtc;
if (_IOC_SIZE(cmd_in) != sizeof(mtc)) {
retval = (-EINVAL);
goto out;
}
i = copy_from_user(&mtc, p, sizeof(struct mtop));
if (i) {
retval = (-EFAULT);
goto out;
}
if (mtc.mt_op == MTSETDRVBUFFER && !capable(CAP_SYS_ADMIN)) {
st_printk(KERN_WARNING, STp,
"MTSETDRVBUFFER only allowed for root.\n");
retval = (-EPERM);
goto out;
}
if (!STm->defined &&
(mtc.mt_op != MTSETDRVBUFFER &&
(mtc.mt_count & MT_ST_OPTIONS) == 0)) {
retval = (-ENXIO);
goto out;
}
if (!STp->pos_unknown) {
if (STps->eof == ST_FM_HIT) {
if (mtc.mt_op == MTFSF || mtc.mt_op == MTFSFM ||
mtc.mt_op == MTEOM) {
mtc.mt_count -= 1;
if (STps->drv_file >= 0)
STps->drv_file += 1;
} else if (mtc.mt_op == MTBSF || mtc.mt_op == MTBSFM) {
mtc.mt_count += 1;
if (STps->drv_file >= 0)
STps->drv_file += 1;
}
}
if (mtc.mt_op == MTSEEK) {
i = !STp->can_partitions ||
(STp->new_partition != STp->partition);
} else {
i = mtc.mt_op == MTREW || mtc.mt_op == MTOFFL ||
mtc.mt_op == MTRETEN || mtc.mt_op == MTEOM ||
mtc.mt_op == MTLOCK || mtc.mt_op == MTLOAD ||
mtc.mt_op == MTFSF || mtc.mt_op == MTFSFM ||
mtc.mt_op == MTBSF || mtc.mt_op == MTBSFM ||
mtc.mt_op == MTCOMPRESSION;
}
i = flush_buffer(STp, i);
if (i < 0) {
retval = i;
goto out;
}
if (STps->rw == ST_WRITING &&
(mtc.mt_op == MTREW || mtc.mt_op == MTOFFL ||
mtc.mt_op == MTSEEK ||
mtc.mt_op == MTBSF || mtc.mt_op == MTBSFM)) {
i = st_int_ioctl(STp, MTWEOF, 1);
if (i < 0) {
retval = i;
goto out;
}
if (mtc.mt_op == MTBSF || mtc.mt_op == MTBSFM)
mtc.mt_count++;
STps->rw = ST_IDLE;
}
} else {
if (mtc.mt_op != MTREW &&
mtc.mt_op != MTOFFL &&
mtc.mt_op != MTRETEN &&
mtc.mt_op != MTERASE &&
mtc.mt_op != MTSEEK &&
mtc.mt_op != MTEOM) {
retval = (-EIO);
goto out;
}
reset_state(STp);
STp->device->was_reset = 0;
}
if (mtc.mt_op != MTNOP && mtc.mt_op != MTSETBLK &&
mtc.mt_op != MTSETDENSITY && mtc.mt_op != MTWSM &&
mtc.mt_op != MTSETDRVBUFFER && mtc.mt_op != MTSETPART)
STps->rw = ST_IDLE;
if (mtc.mt_op == MTOFFL && STp->door_locked != ST_UNLOCKED)
do_door_lock(STp, 0);
if (mtc.mt_op == MTSETDRVBUFFER &&
(mtc.mt_count & MT_ST_OPTIONS) != 0) {
retval = st_set_options(STp, mtc.mt_count);
goto out;
}
if (mtc.mt_op == MTSETPART) {
if (!STp->can_partitions ||
mtc.mt_count < 0 || mtc.mt_count >= ST_NBR_PARTITIONS) {
retval = (-EINVAL);
goto out;
}
if (mtc.mt_count >= STp->nbr_partitions &&
(STp->nbr_partitions = nbr_partitions(STp)) < 0) {
retval = (-EIO);
goto out;
}
if (mtc.mt_count >= STp->nbr_partitions) {
retval = (-EINVAL);
goto out;
}
STp->new_partition = mtc.mt_count;
retval = 0;
goto out;
}
if (mtc.mt_op == MTMKPART) {
if (!STp->can_partitions) {
retval = (-EINVAL);
goto out;
}
i = do_load_unload(STp, file, 1);
if (i < 0) {
retval = i;
goto out;
}
i = partition_tape(STp, mtc.mt_count);
if (i < 0) {
retval = i;
goto out;
}
for (i = 0; i < ST_NBR_PARTITIONS; i++) {
STp->ps[i].rw = ST_IDLE;
STp->ps[i].at_sm = 0;
STp->ps[i].last_block_valid = 0;
}
STp->partition = STp->new_partition = 0;
STp->nbr_partitions = mtc.mt_count != 0 ? 2 : 1;
STps->drv_block = STps->drv_file = 0;
retval = 0;
goto out;
}
if (mtc.mt_op == MTSEEK) {
i = set_location(STp, mtc.mt_count, STp->new_partition, 0);
if (!STp->can_partitions)
STp->ps[0].rw = ST_IDLE;
retval = i;
goto out;
}
if (mtc.mt_op == MTUNLOAD || mtc.mt_op == MTOFFL) {
retval = do_load_unload(STp, file, 0);
goto out;
}
if (mtc.mt_op == MTLOAD) {
retval = do_load_unload(STp, file, max(1, mtc.mt_count));
goto out;
}
if (mtc.mt_op == MTLOCK || mtc.mt_op == MTUNLOCK) {
retval = do_door_lock(STp, (mtc.mt_op == MTLOCK));
goto out;
}
if (STp->can_partitions && STp->ready == ST_READY &&
(i = switch_partition(STp)) < 0) {
retval = i;
goto out;
}
if (mtc.mt_op == MTCOMPRESSION)
retval = st_compression(STp, (mtc.mt_count & 1));
else
retval = st_int_ioctl(STp, mtc.mt_op, mtc.mt_count);
goto out;
}
if (!STm->defined) {
retval = (-ENXIO);
goto out;
}
if ((i = flush_buffer(STp, 0)) < 0) {
retval = i;
goto out;
}
if (STp->can_partitions &&
(i = switch_partition(STp)) < 0) {
retval = i;
goto out;
}
if (cmd_type == _IOC_TYPE(MTIOCGET) && cmd_nr == _IOC_NR(MTIOCGET)) {
struct mtget mt_status;
if (_IOC_SIZE(cmd_in) != sizeof(struct mtget)) {
retval = (-EINVAL);
goto out;
}
mt_status.mt_type = STp->tape_type;
mt_status.mt_dsreg =
((STp->block_size << MT_ST_BLKSIZE_SHIFT) & MT_ST_BLKSIZE_MASK) |
((STp->density << MT_ST_DENSITY_SHIFT) & MT_ST_DENSITY_MASK);
mt_status.mt_blkno = STps->drv_block;
mt_status.mt_fileno = STps->drv_file;
if (STp->block_size != 0) {
if (STps->rw == ST_WRITING)
mt_status.mt_blkno +=
(STp->buffer)->buffer_bytes / STp->block_size;
else if (STps->rw == ST_READING)
mt_status.mt_blkno -=
((STp->buffer)->buffer_bytes +
STp->block_size - 1) / STp->block_size;
}
mt_status.mt_gstat = 0;
if (STp->drv_write_prot)
mt_status.mt_gstat |= GMT_WR_PROT(0xffffffff);
if (mt_status.mt_blkno == 0) {
if (mt_status.mt_fileno == 0)
mt_status.mt_gstat |= GMT_BOT(0xffffffff);
else
mt_status.mt_gstat |= GMT_EOF(0xffffffff);
}
mt_status.mt_erreg = (STp->recover_reg << MT_ST_SOFTERR_SHIFT);
mt_status.mt_resid = STp->partition;
if (STps->eof == ST_EOM_OK || STps->eof == ST_EOM_ERROR)
mt_status.mt_gstat |= GMT_EOT(0xffffffff);
else if (STps->eof >= ST_EOM_OK)
mt_status.mt_gstat |= GMT_EOD(0xffffffff);
if (STp->density == 1)
mt_status.mt_gstat |= GMT_D_800(0xffffffff);
else if (STp->density == 2)
mt_status.mt_gstat |= GMT_D_1600(0xffffffff);
else if (STp->density == 3)
mt_status.mt_gstat |= GMT_D_6250(0xffffffff);
if (STp->ready == ST_READY)
mt_status.mt_gstat |= GMT_ONLINE(0xffffffff);
if (STp->ready == ST_NO_TAPE)
mt_status.mt_gstat |= GMT_DR_OPEN(0xffffffff);
if (STps->at_sm)
mt_status.mt_gstat |= GMT_SM(0xffffffff);
if (STm->do_async_writes ||
(STm->do_buffer_writes && STp->block_size != 0) ||
STp->drv_buffer != 0)
mt_status.mt_gstat |= GMT_IM_REP_EN(0xffffffff);
if (STp->cleaning_req)
mt_status.mt_gstat |= GMT_CLN(0xffffffff);
i = copy_to_user(p, &mt_status, sizeof(struct mtget));
if (i) {
retval = (-EFAULT);
goto out;
}
STp->recover_reg = 0;
retval = 0;
goto out;
}
if (cmd_type == _IOC_TYPE(MTIOCPOS) && cmd_nr == _IOC_NR(MTIOCPOS)) {
struct mtpos mt_pos;
if (_IOC_SIZE(cmd_in) != sizeof(struct mtpos)) {
retval = (-EINVAL);
goto out;
}
if ((i = get_location(STp, &blk, &bt, 0)) < 0) {
retval = i;
goto out;
}
mt_pos.mt_blkno = blk;
i = copy_to_user(p, &mt_pos, sizeof(struct mtpos));
if (i)
retval = (-EFAULT);
goto out;
}
mutex_unlock(&STp->lock);
switch (cmd_in) {
case SCSI_IOCTL_GET_IDLUN:
case SCSI_IOCTL_GET_BUS_NUMBER:
break;
default:
if ((cmd_in == SG_IO ||
cmd_in == SCSI_IOCTL_SEND_COMMAND ||
cmd_in == CDROM_SEND_PACKET) &&
!capable(CAP_SYS_RAWIO))
i = -EPERM;
else
i = scsi_cmd_ioctl(STp->disk->queue, STp->disk,
file->f_mode, cmd_in, p);
if (i != -ENOTTY)
return i;
break;
}
retval = scsi_ioctl(STp->device, cmd_in, p);
if (!retval && cmd_in == SCSI_IOCTL_STOP_UNIT) {
STp->rew_at_close = 0;
STp->ready = ST_NO_TAPE;
}
return retval;
out:
mutex_unlock(&STp->lock);
return retval;
}
static long st_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct scsi_tape *STp = file->private_data;
struct scsi_device *sdev = STp->device;
int ret = -ENOIOCTLCMD;
if (sdev->host->hostt->compat_ioctl) {
ret = sdev->host->hostt->compat_ioctl(sdev, cmd, (void __user *)arg);
}
return ret;
}
static struct st_buffer *new_tape_buffer(int need_dma, int max_sg)
{
struct st_buffer *tb;
tb = kzalloc(sizeof(struct st_buffer), GFP_ATOMIC);
if (!tb) {
printk(KERN_NOTICE "st: Can't allocate new tape buffer.\n");
return NULL;
}
tb->frp_segs = 0;
tb->use_sg = max_sg;
tb->dma = need_dma;
tb->buffer_size = 0;
tb->reserved_pages = kzalloc(max_sg * sizeof(struct page *),
GFP_ATOMIC);
if (!tb->reserved_pages) {
kfree(tb);
return NULL;
}
return tb;
}
static int enlarge_buffer(struct st_buffer * STbuffer, int new_size, int need_dma)
{
int segs, max_segs, b_size, order, got;
gfp_t priority;
if (new_size <= STbuffer->buffer_size)
return 1;
if (STbuffer->buffer_size <= PAGE_SIZE)
normalize_buffer(STbuffer);
max_segs = STbuffer->use_sg;
priority = GFP_KERNEL | __GFP_NOWARN;
if (need_dma)
priority |= GFP_DMA;
if (STbuffer->cleared)
priority |= __GFP_ZERO;
if (STbuffer->frp_segs) {
order = STbuffer->reserved_page_order;
b_size = PAGE_SIZE << order;
} else {
for (b_size = PAGE_SIZE, order = 0;
order < ST_MAX_ORDER &&
max_segs * (PAGE_SIZE << order) < new_size;
order++, b_size *= 2)
;
STbuffer->reserved_page_order = order;
}
if (max_segs * (PAGE_SIZE << order) < new_size) {
if (order == ST_MAX_ORDER)
return 0;
normalize_buffer(STbuffer);
return enlarge_buffer(STbuffer, new_size, need_dma);
}
for (segs = STbuffer->frp_segs, got = STbuffer->buffer_size;
segs < max_segs && got < new_size;) {
struct page *page;
page = alloc_pages(priority, order);
if (!page) {
DEB(STbuffer->buffer_size = got);
normalize_buffer(STbuffer);
return 0;
}
STbuffer->frp_segs += 1;
got += b_size;
STbuffer->buffer_size = got;
STbuffer->reserved_pages[segs] = page;
segs++;
}
STbuffer->b_data = page_address(STbuffer->reserved_pages[0]);
return 1;
}
static void clear_buffer(struct st_buffer * st_bp)
{
int i;
for (i=0; i < st_bp->frp_segs; i++)
memset(page_address(st_bp->reserved_pages[i]), 0,
PAGE_SIZE << st_bp->reserved_page_order);
st_bp->cleared = 1;
}
static void normalize_buffer(struct st_buffer * STbuffer)
{
int i, order = STbuffer->reserved_page_order;
for (i = 0; i < STbuffer->frp_segs; i++) {
__free_pages(STbuffer->reserved_pages[i], order);
STbuffer->buffer_size -= (PAGE_SIZE << order);
}
STbuffer->frp_segs = 0;
STbuffer->sg_segs = 0;
STbuffer->reserved_page_order = 0;
STbuffer->map_data.offset = 0;
}
static int append_to_buffer(const char __user *ubp, struct st_buffer * st_bp, int do_count)
{
int i, cnt, res, offset;
int length = PAGE_SIZE << st_bp->reserved_page_order;
for (i = 0, offset = st_bp->buffer_bytes;
i < st_bp->frp_segs && offset >= length; i++)
offset -= length;
if (i == st_bp->frp_segs) {
printk(KERN_WARNING "st: append_to_buffer offset overflow.\n");
return (-EIO);
}
for (; i < st_bp->frp_segs && do_count > 0; i++) {
struct page *page = st_bp->reserved_pages[i];
cnt = length - offset < do_count ? length - offset : do_count;
res = copy_from_user(page_address(page) + offset, ubp, cnt);
if (res)
return (-EFAULT);
do_count -= cnt;
st_bp->buffer_bytes += cnt;
ubp += cnt;
offset = 0;
}
if (do_count)
return (-EIO);
return 0;
}
static int from_buffer(struct st_buffer * st_bp, char __user *ubp, int do_count)
{
int i, cnt, res, offset;
int length = PAGE_SIZE << st_bp->reserved_page_order;
for (i = 0, offset = st_bp->read_pointer;
i < st_bp->frp_segs && offset >= length; i++)
offset -= length;
if (i == st_bp->frp_segs) {
printk(KERN_WARNING "st: from_buffer offset overflow.\n");
return (-EIO);
}
for (; i < st_bp->frp_segs && do_count > 0; i++) {
struct page *page = st_bp->reserved_pages[i];
cnt = length - offset < do_count ? length - offset : do_count;
res = copy_to_user(ubp, page_address(page) + offset, cnt);
if (res)
return (-EFAULT);
do_count -= cnt;
st_bp->buffer_bytes -= cnt;
st_bp->read_pointer += cnt;
ubp += cnt;
offset = 0;
}
if (do_count)
return (-EIO);
return 0;
}
static void move_buffer_data(struct st_buffer * st_bp, int offset)
{
int src_seg, dst_seg, src_offset = 0, dst_offset;
int count, total;
int length = PAGE_SIZE << st_bp->reserved_page_order;
if (offset == 0)
return;
total=st_bp->buffer_bytes - offset;
for (src_seg=0; src_seg < st_bp->frp_segs; src_seg++) {
src_offset = offset;
if (src_offset < length)
break;
offset -= length;
}
st_bp->buffer_bytes = st_bp->read_pointer = total;
for (dst_seg=dst_offset=0; total > 0; ) {
struct page *dpage = st_bp->reserved_pages[dst_seg];
struct page *spage = st_bp->reserved_pages[src_seg];
count = min(length - dst_offset, length - src_offset);
memmove(page_address(dpage) + dst_offset,
page_address(spage) + src_offset, count);
src_offset += count;
if (src_offset >= length) {
src_seg++;
src_offset = 0;
}
dst_offset += count;
if (dst_offset >= length) {
dst_seg++;
dst_offset = 0;
}
total -= count;
}
}
static void validate_options(void)
{
if (buffer_kbs > 0)
st_fixed_buffer_size = buffer_kbs * ST_KILOBYTE;
if (max_sg_segs >= ST_FIRST_SG)
st_max_sg_segs = max_sg_segs;
}
static int __init st_setup(char *str)
{
int i, len, ints[5];
char *stp;
stp = get_options(str, ARRAY_SIZE(ints), ints);
if (ints[0] > 0) {
for (i = 0; i < ints[0] && i < ARRAY_SIZE(parms); i++)
if (parms[i].val)
*parms[i].val = ints[i + 1];
} else {
while (stp != NULL) {
for (i = 0; i < ARRAY_SIZE(parms); i++) {
len = strlen(parms[i].name);
if (!strncmp(stp, parms[i].name, len) &&
(*(stp + len) == ':' || *(stp + len) == '=')) {
if (parms[i].val)
*parms[i].val =
simple_strtoul(stp + len + 1, NULL, 0);
else
printk(KERN_WARNING "st: Obsolete parameter %s\n",
parms[i].name);
break;
}
}
if (i >= ARRAY_SIZE(parms))
printk(KERN_WARNING "st: invalid parameter in '%s'\n",
stp);
stp = strchr(stp, ',');
if (stp)
stp++;
}
}
validate_options();
return 1;
}
static int create_one_cdev(struct scsi_tape *tape, int mode, int rew)
{
int i, error;
dev_t cdev_devno;
struct cdev *cdev;
struct device *dev;
struct st_modedef *STm = &(tape->modes[mode]);
char name[10];
int dev_num = tape->index;
cdev_devno = MKDEV(SCSI_TAPE_MAJOR, TAPE_MINOR(dev_num, mode, rew));
cdev = cdev_alloc();
if (!cdev) {
pr_err("st%d: out of memory. Device not attached.\n", dev_num);
error = -ENOMEM;
goto out;
}
cdev->owner = THIS_MODULE;
cdev->ops = &st_fops;
STm->cdevs[rew] = cdev;
error = cdev_add(cdev, cdev_devno, 1);
if (error) {
pr_err("st%d: Can't add %s-rewind mode %d\n", dev_num,
rew ? "non" : "auto", mode);
pr_err("st%d: Device not attached.\n", dev_num);
goto out_free;
}
i = mode << (4 - ST_NBR_MODE_BITS);
snprintf(name, 10, "%s%s%s", rew ? "n" : "",
tape->disk->disk_name, st_formats[i]);
dev = device_create(&st_sysfs_class, &tape->device->sdev_gendev,
cdev_devno, &tape->modes[mode], "%s", name);
if (IS_ERR(dev)) {
pr_err("st%d: device_create failed\n", dev_num);
error = PTR_ERR(dev);
goto out_free;
}
STm->devs[rew] = dev;
return 0;
out_free:
cdev_del(STm->cdevs[rew]);
out:
STm->cdevs[rew] = NULL;
STm->devs[rew] = NULL;
return error;
}
static int create_cdevs(struct scsi_tape *tape)
{
int mode, error;
for (mode = 0; mode < ST_NBR_MODES; ++mode) {
error = create_one_cdev(tape, mode, 0);
if (error)
return error;
error = create_one_cdev(tape, mode, 1);
if (error)
return error;
}
return sysfs_create_link(&tape->device->sdev_gendev.kobj,
&tape->modes[0].devs[0]->kobj, "tape");
}
static void remove_cdevs(struct scsi_tape *tape)
{
int mode, rew;
sysfs_remove_link(&tape->device->sdev_gendev.kobj, "tape");
for (mode = 0; mode < ST_NBR_MODES; mode++) {
struct st_modedef *STm = &(tape->modes[mode]);
for (rew = 0; rew < 2; rew++) {
if (STm->cdevs[rew])
cdev_del(STm->cdevs[rew]);
if (STm->devs[rew])
device_unregister(STm->devs[rew]);
}
}
}
static int st_probe(struct device *dev)
{
struct scsi_device *SDp = to_scsi_device(dev);
struct gendisk *disk = NULL;
struct scsi_tape *tpnt = NULL;
struct st_modedef *STm;
struct st_partstat *STps;
struct st_buffer *buffer;
int i, error;
char *stp;
if (SDp->type != TYPE_TAPE)
return -ENODEV;
if ((stp = st_incompatible(SDp))) {
sdev_printk(KERN_INFO, SDp, "Found incompatible tape\n");
sdev_printk(KERN_INFO, SDp,
"st: The suggested driver is %s.\n", stp);
return -ENODEV;
}
scsi_autopm_get_device(SDp);
i = queue_max_segments(SDp->request_queue);
if (st_max_sg_segs < i)
i = st_max_sg_segs;
buffer = new_tape_buffer((SDp->host)->unchecked_isa_dma, i);
if (buffer == NULL) {
sdev_printk(KERN_ERR, SDp,
"st: Can't allocate new tape buffer. "
"Device not attached.\n");
goto out;
}
disk = alloc_disk(1);
if (!disk) {
sdev_printk(KERN_ERR, SDp,
"st: out of memory. Device not attached.\n");
goto out_buffer_free;
}
tpnt = kzalloc(sizeof(struct scsi_tape), GFP_ATOMIC);
if (tpnt == NULL) {
sdev_printk(KERN_ERR, SDp,
"st: Can't allocate device descriptor.\n");
goto out_put_disk;
}
kref_init(&tpnt->kref);
tpnt->disk = disk;
disk->private_data = &tpnt->driver;
disk->queue = SDp->request_queue;
if (!blk_get_queue(disk->queue))
goto out_put_disk;
tpnt->driver = &st_template;
tpnt->device = SDp;
if (SDp->scsi_level <= 2)
tpnt->tape_type = MT_ISSCSI1;
else
tpnt->tape_type = MT_ISSCSI2;
tpnt->buffer = buffer;
tpnt->buffer->last_SRpnt = NULL;
tpnt->inited = 0;
tpnt->dirty = 0;
tpnt->in_use = 0;
tpnt->drv_buffer = 1;
tpnt->restr_dma = (SDp->host)->unchecked_isa_dma;
tpnt->use_pf = (SDp->scsi_level >= SCSI_2);
tpnt->density = 0;
tpnt->do_auto_lock = ST_AUTO_LOCK;
tpnt->can_bsr = (SDp->scsi_level > 2 ? 1 : ST_IN_FILE_POS);
tpnt->can_partitions = 0;
tpnt->two_fm = ST_TWO_FM;
tpnt->fast_mteom = ST_FAST_MTEOM;
tpnt->scsi2_logical = ST_SCSI2LOGICAL;
tpnt->sili = ST_SILI;
tpnt->immediate = ST_NOWAIT;
tpnt->immediate_filemark = 0;
tpnt->default_drvbuffer = 0xff;
tpnt->partition = 0;
tpnt->new_partition = 0;
tpnt->nbr_partitions = 0;
blk_queue_rq_timeout(tpnt->device->request_queue, ST_TIMEOUT);
tpnt->long_timeout = ST_LONG_TIMEOUT;
tpnt->try_dio = try_direct_io && !SDp->host->unchecked_isa_dma;
for (i = 0; i < ST_NBR_MODES; i++) {
STm = &(tpnt->modes[i]);
STm->defined = 0;
STm->sysv = ST_SYSV;
STm->defaults_for_writes = 0;
STm->do_async_writes = ST_ASYNC_WRITES;
STm->do_buffer_writes = ST_BUFFER_WRITES;
STm->do_read_ahead = ST_READ_AHEAD;
STm->default_compression = ST_DONT_TOUCH;
STm->default_blksize = (-1);
STm->default_density = (-1);
STm->tape = tpnt;
}
for (i = 0; i < ST_NBR_PARTITIONS; i++) {
STps = &(tpnt->ps[i]);
STps->rw = ST_IDLE;
STps->eof = ST_NOEOF;
STps->at_sm = 0;
STps->last_block_valid = 0;
STps->drv_block = (-1);
STps->drv_file = (-1);
}
tpnt->current_mode = 0;
tpnt->modes[0].defined = 1;
tpnt->density_changed = tpnt->compression_changed =
tpnt->blksize_changed = 0;
mutex_init(&tpnt->lock);
idr_preload(GFP_KERNEL);
spin_lock(&st_index_lock);
error = idr_alloc(&st_index_idr, tpnt, 0, ST_MAX_TAPES + 1, GFP_NOWAIT);
spin_unlock(&st_index_lock);
idr_preload_end();
if (error < 0) {
pr_warn("st: idr allocation failed: %d\n", error);
goto out_put_queue;
}
tpnt->index = error;
sprintf(disk->disk_name, "st%d", tpnt->index);
tpnt->stats = kzalloc(sizeof(struct scsi_tape_stats), GFP_KERNEL);
if (tpnt->stats == NULL) {
sdev_printk(KERN_ERR, SDp,
"st: Can't allocate statistics.\n");
goto out_idr_remove;
}
dev_set_drvdata(dev, tpnt);
error = create_cdevs(tpnt);
if (error)
goto out_remove_devs;
scsi_autopm_put_device(SDp);
sdev_printk(KERN_NOTICE, SDp,
"Attached scsi tape %s\n", tape_name(tpnt));
sdev_printk(KERN_INFO, SDp, "%s: try direct i/o: %s (alignment %d B)\n",
tape_name(tpnt), tpnt->try_dio ? "yes" : "no",
queue_dma_alignment(SDp->request_queue) + 1);
return 0;
out_remove_devs:
remove_cdevs(tpnt);
kfree(tpnt->stats);
out_idr_remove:
spin_lock(&st_index_lock);
idr_remove(&st_index_idr, tpnt->index);
spin_unlock(&st_index_lock);
out_put_queue:
blk_put_queue(disk->queue);
out_put_disk:
put_disk(disk);
kfree(tpnt);
out_buffer_free:
kfree(buffer);
out:
scsi_autopm_put_device(SDp);
return -ENODEV;
}
static int st_remove(struct device *dev)
{
struct scsi_tape *tpnt = dev_get_drvdata(dev);
int index = tpnt->index;
scsi_autopm_get_device(to_scsi_device(dev));
remove_cdevs(tpnt);
mutex_lock(&st_ref_mutex);
kref_put(&tpnt->kref, scsi_tape_release);
mutex_unlock(&st_ref_mutex);
spin_lock(&st_index_lock);
idr_remove(&st_index_idr, index);
spin_unlock(&st_index_lock);
return 0;
}
static void scsi_tape_release(struct kref *kref)
{
struct scsi_tape *tpnt = to_scsi_tape(kref);
struct gendisk *disk = tpnt->disk;
tpnt->device = NULL;
if (tpnt->buffer) {
normalize_buffer(tpnt->buffer);
kfree(tpnt->buffer->reserved_pages);
kfree(tpnt->buffer);
}
disk->private_data = NULL;
put_disk(disk);
kfree(tpnt->stats);
kfree(tpnt);
return;
}
static int __init init_st(void)
{
int err;
validate_options();
printk(KERN_INFO "st: Version %s, fixed bufsize %d, s/g segs %d\n",
verstr, st_fixed_buffer_size, st_max_sg_segs);
debugging = (debug_flag > 0) ? debug_flag : NO_DEBUG;
if (debugging) {
printk(KERN_INFO "st: Debugging enabled debug_flag = %d\n",
debugging);
}
err = class_register(&st_sysfs_class);
if (err) {
pr_err("Unable register sysfs class for SCSI tapes\n");
return err;
}
err = register_chrdev_region(MKDEV(SCSI_TAPE_MAJOR, 0),
ST_MAX_TAPE_ENTRIES, "st");
if (err) {
printk(KERN_ERR "Unable to get major %d for SCSI tapes\n",
SCSI_TAPE_MAJOR);
goto err_class;
}
err = scsi_register_driver(&st_template.gendrv);
if (err)
goto err_chrdev;
return 0;
err_chrdev:
unregister_chrdev_region(MKDEV(SCSI_TAPE_MAJOR, 0),
ST_MAX_TAPE_ENTRIES);
err_class:
class_unregister(&st_sysfs_class);
return err;
}
static void __exit exit_st(void)
{
scsi_unregister_driver(&st_template.gendrv);
unregister_chrdev_region(MKDEV(SCSI_TAPE_MAJOR, 0),
ST_MAX_TAPE_ENTRIES);
class_unregister(&st_sysfs_class);
idr_destroy(&st_index_idr);
printk(KERN_INFO "st: Unloaded.\n");
}
static ssize_t try_direct_io_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", try_direct_io);
}
static ssize_t fixed_buffer_size_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", st_fixed_buffer_size);
}
static ssize_t max_sg_segs_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", st_max_sg_segs);
}
static ssize_t version_show(struct device_driver *ddd, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "[%s]\n", verstr);
}
static ssize_t debug_flag_store(struct device_driver *ddp,
const char *buf, size_t count)
{
if (count > 0) {
if (buf[0] == '0') {
debugging = NO_DEBUG;
return count;
} else if (buf[0] == '1') {
debugging = 1;
return count;
}
}
return -EINVAL;
}
static ssize_t debug_flag_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", debugging);
}
static ssize_t
defined_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
ssize_t l = 0;
l = snprintf(buf, PAGE_SIZE, "%d\n", STm->defined);
return l;
}
static ssize_t
default_blksize_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
ssize_t l = 0;
l = snprintf(buf, PAGE_SIZE, "%d\n", STm->default_blksize);
return l;
}
static ssize_t
default_density_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
ssize_t l = 0;
char *fmt;
fmt = STm->default_density >= 0 ? "0x%02x\n" : "%d\n";
l = snprintf(buf, PAGE_SIZE, fmt, STm->default_density);
return l;
}
static ssize_t
default_compression_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
ssize_t l = 0;
l = snprintf(buf, PAGE_SIZE, "%d\n", STm->default_compression - 1);
return l;
}
static ssize_t
options_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
struct scsi_tape *STp = STm->tape;
int options;
ssize_t l = 0;
options = STm->do_buffer_writes ? MT_ST_BUFFER_WRITES : 0;
options |= STm->do_async_writes ? MT_ST_ASYNC_WRITES : 0;
options |= STm->do_read_ahead ? MT_ST_READ_AHEAD : 0;
DEB( options |= debugging ? MT_ST_DEBUGGING : 0 );
options |= STp->two_fm ? MT_ST_TWO_FM : 0;
options |= STp->fast_mteom ? MT_ST_FAST_MTEOM : 0;
options |= STm->defaults_for_writes ? MT_ST_DEF_WRITES : 0;
options |= STp->can_bsr ? MT_ST_CAN_BSR : 0;
options |= STp->omit_blklims ? MT_ST_NO_BLKLIMS : 0;
options |= STp->can_partitions ? MT_ST_CAN_PARTITIONS : 0;
options |= STp->scsi2_logical ? MT_ST_SCSI2LOGICAL : 0;
options |= STm->sysv ? MT_ST_SYSV : 0;
options |= STp->immediate ? MT_ST_NOWAIT : 0;
options |= STp->immediate_filemark ? MT_ST_NOWAIT_EOF : 0;
options |= STp->sili ? MT_ST_SILI : 0;
l = snprintf(buf, PAGE_SIZE, "0x%08x\n", options);
return l;
}
static ssize_t read_cnt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->read_cnt));
}
static ssize_t read_byte_cnt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->read_byte_cnt));
}
static ssize_t read_ns_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->tot_read_time));
}
static ssize_t write_cnt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->write_cnt));
}
static ssize_t write_byte_cnt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->write_byte_cnt));
}
static ssize_t write_ns_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->tot_write_time));
}
static ssize_t in_flight_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->in_flight));
}
static ssize_t io_ns_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->tot_io_time));
}
static ssize_t other_cnt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->other_cnt));
}
static ssize_t resid_cnt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct st_modedef *STm = dev_get_drvdata(dev);
return sprintf(buf, "%lld",
(long long)atomic64_read(&STm->tape->stats->resid_cnt));
}
static int sgl_map_user_pages(struct st_buffer *STbp,
const unsigned int max_pages, unsigned long uaddr,
size_t count, int rw)
{
unsigned long end = (uaddr + count + PAGE_SIZE - 1) >> PAGE_SHIFT;
unsigned long start = uaddr >> PAGE_SHIFT;
const int nr_pages = end - start;
int res, i, j;
struct page **pages;
struct rq_map_data *mdata = &STbp->map_data;
if ((uaddr + count) < uaddr)
return -EINVAL;
if (nr_pages > max_pages)
return -ENOMEM;
if (count == 0)
return 0;
if ((pages = kmalloc(max_pages * sizeof(*pages), GFP_KERNEL)) == NULL)
return -ENOMEM;
res = get_user_pages_unlocked(
uaddr,
nr_pages,
pages,
rw == READ ? FOLL_WRITE : 0);
if (res < nr_pages)
goto out_unmap;
for (i=0; i < nr_pages; i++) {
flush_dcache_page(pages[i]);
}
mdata->offset = uaddr & ~PAGE_MASK;
STbp->mapped_pages = pages;
return nr_pages;
out_unmap:
if (res > 0) {
for (j=0; j < res; j++)
put_page(pages[j]);
res = 0;
}
kfree(pages);
return res;
}
static int sgl_unmap_user_pages(struct st_buffer *STbp,
const unsigned int nr_pages, int dirtied)
{
int i;
for (i=0; i < nr_pages; i++) {
struct page *page = STbp->mapped_pages[i];
if (dirtied)
SetPageDirty(page);
put_page(page);
}
kfree(STbp->mapped_pages);
STbp->mapped_pages = NULL;
return 0;
}
