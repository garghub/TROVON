static long dmabuf_timeout(struct dma_buffparms *dmap)
{
long tmout;
tmout = (dmap->fragment_size * HZ) / dmap->data_rate;
tmout += HZ / 5;
if (tmout < (HZ / 2))
tmout = HZ / 2;
if (tmout > 20 * HZ)
tmout = 20 * HZ;
return tmout;
}
static int sound_alloc_dmap(struct dma_buffparms *dmap)
{
char *start_addr, *end_addr;
int dma_pagesize;
int sz, size;
struct page *page;
dmap->mapping_flags &= ~DMA_MAP_MAPPED;
if (dmap->raw_buf != NULL)
return 0;
if (dma_buffsize < 4096)
dma_buffsize = 4096;
dma_pagesize = (dmap->dma < 4) ? (64 * 1024) : (128 * 1024);
if(isa_dma_bridge_buggy==2)
dma_pagesize=32768;
dmap->raw_buf = NULL;
dmap->buffsize = dma_buffsize;
if (dmap->buffsize > dma_pagesize)
dmap->buffsize = dma_pagesize;
start_addr = NULL;
while (start_addr == NULL && dmap->buffsize > PAGE_SIZE) {
for (sz = 0, size = PAGE_SIZE; size < dmap->buffsize; sz++, size <<= 1);
dmap->buffsize = PAGE_SIZE * (1 << sz);
start_addr = (char *) __get_free_pages(GFP_ATOMIC|GFP_DMA|__GFP_NOWARN, sz);
if (start_addr == NULL)
dmap->buffsize /= 2;
}
if (start_addr == NULL) {
printk(KERN_WARNING "Sound error: Couldn't allocate DMA buffer\n");
return -ENOMEM;
} else {
end_addr = start_addr + dmap->buffsize - 1;
if (debugmem)
printk(KERN_DEBUG "sound: start 0x%lx, end 0x%lx\n", (long) start_addr, (long) end_addr);
if (((long) start_addr & ~(dma_pagesize - 1)) != ((long) end_addr & ~(dma_pagesize - 1))
|| end_addr >= (char *) (MAX_DMA_ADDRESS)) {
printk(KERN_ERR "sound: Got invalid address 0x%lx for %db DMA-buffer\n", (long) start_addr, dmap->buffsize);
return -EFAULT;
}
}
dmap->raw_buf = start_addr;
dmap->raw_buf_phys = virt_to_bus(start_addr);
for (page = virt_to_page(start_addr); page <= virt_to_page(end_addr); page++)
SetPageReserved(page);
return 0;
}
static void sound_free_dmap(struct dma_buffparms *dmap)
{
int sz, size;
struct page *page;
unsigned long start_addr, end_addr;
if (dmap->raw_buf == NULL)
return;
if (dmap->mapping_flags & DMA_MAP_MAPPED)
return;
for (sz = 0, size = PAGE_SIZE; size < dmap->buffsize; sz++, size <<= 1);
start_addr = (unsigned long) dmap->raw_buf;
end_addr = start_addr + dmap->buffsize;
for (page = virt_to_page(start_addr); page <= virt_to_page(end_addr); page++)
ClearPageReserved(page);
free_pages((unsigned long) dmap->raw_buf, sz);
dmap->raw_buf = NULL;
}
static int sound_start_dma(struct dma_buffparms *dmap, unsigned long physaddr, int count, int dma_mode)
{
unsigned long flags;
int chan = dmap->dma;
flags = claim_dma_lock();
disable_dma(chan);
clear_dma_ff(chan);
set_dma_mode(chan, dma_mode);
set_dma_addr(chan, physaddr);
set_dma_count(chan, count);
enable_dma(chan);
release_dma_lock(flags);
return 0;
}
static void dma_init_buffers(struct dma_buffparms *dmap)
{
dmap->qlen = dmap->qhead = dmap->qtail = dmap->user_counter = 0;
dmap->byte_counter = 0;
dmap->max_byte_counter = 8000 * 60 * 60;
dmap->bytes_in_use = dmap->buffsize;
dmap->dma_mode = DMODE_NONE;
dmap->mapping_flags = 0;
dmap->neutral_byte = 0x80;
dmap->data_rate = 8000;
dmap->cfrag = -1;
dmap->closing = 0;
dmap->nbufs = 1;
dmap->flags = DMA_BUSY;
}
static int open_dmap(struct audio_operations *adev, int mode, struct dma_buffparms *dmap)
{
int err;
if (dmap->flags & DMA_BUSY)
return -EBUSY;
if ((err = sound_alloc_dmap(dmap)) < 0)
return err;
if (dmap->raw_buf == NULL) {
printk(KERN_WARNING "Sound: DMA buffers not available\n");
return -ENOSPC;
}
if (dmap->dma >= 0 && sound_open_dma(dmap->dma, adev->name)) {
printk(KERN_WARNING "Unable to grab(2) DMA%d for the audio driver\n", dmap->dma);
return -EBUSY;
}
dma_init_buffers(dmap);
spin_lock_init(&dmap->lock);
dmap->open_mode = mode;
dmap->subdivision = dmap->underrun_count = 0;
dmap->fragment_size = 0;
dmap->max_fragments = 65536;
dmap->byte_counter = 0;
dmap->max_byte_counter = 8000 * 60 * 60;
dmap->applic_profile = APF_NORMAL;
dmap->needs_reorg = 1;
dmap->audio_callback = NULL;
dmap->callback_parm = 0;
return 0;
}
static void close_dmap(struct audio_operations *adev, struct dma_buffparms *dmap)
{
unsigned long flags;
if (dmap->dma >= 0) {
sound_close_dma(dmap->dma);
flags=claim_dma_lock();
disable_dma(dmap->dma);
release_dma_lock(flags);
}
if (dmap->flags & DMA_BUSY)
dmap->dma_mode = DMODE_NONE;
dmap->flags &= ~DMA_BUSY;
if (sound_dmap_flag == DMAP_FREE_ON_CLOSE)
sound_free_dmap(dmap);
}
static unsigned int default_set_bits(int dev, unsigned int bits)
{
mm_segment_t fs = get_fs();
set_fs(get_ds());
audio_devs[dev]->d->ioctl(dev, SNDCTL_DSP_SETFMT, (void __user *)&bits);
set_fs(fs);
return bits;
}
static int default_set_speed(int dev, int speed)
{
mm_segment_t fs = get_fs();
set_fs(get_ds());
audio_devs[dev]->d->ioctl(dev, SNDCTL_DSP_SPEED, (void __user *)&speed);
set_fs(fs);
return speed;
}
static short default_set_channels(int dev, short channels)
{
int c = channels;
mm_segment_t fs = get_fs();
set_fs(get_ds());
audio_devs[dev]->d->ioctl(dev, SNDCTL_DSP_CHANNELS, (void __user *)&c);
set_fs(fs);
return c;
}
static void check_driver(struct audio_driver *d)
{
if (d->set_speed == NULL)
d->set_speed = default_set_speed;
if (d->set_bits == NULL)
d->set_bits = default_set_bits;
if (d->set_channels == NULL)
d->set_channels = default_set_channels;
}
int DMAbuf_open(int dev, int mode)
{
struct audio_operations *adev = audio_devs[dev];
int retval;
struct dma_buffparms *dmap_in = NULL;
struct dma_buffparms *dmap_out = NULL;
if (!adev)
return -ENXIO;
if (!(adev->flags & DMA_DUPLEX))
adev->dmap_in = adev->dmap_out;
check_driver(adev->d);
if ((retval = adev->d->open(dev, mode)) < 0)
return retval;
dmap_out = adev->dmap_out;
dmap_in = adev->dmap_in;
if (dmap_in == dmap_out)
adev->flags &= ~DMA_DUPLEX;
if (mode & OPEN_WRITE) {
if ((retval = open_dmap(adev, mode, dmap_out)) < 0) {
adev->d->close(dev);
return retval;
}
}
adev->enable_bits = mode;
if (mode == OPEN_READ || (mode != OPEN_WRITE && (adev->flags & DMA_DUPLEX))) {
if ((retval = open_dmap(adev, mode, dmap_in)) < 0) {
adev->d->close(dev);
if (mode & OPEN_WRITE)
close_dmap(adev, dmap_out);
return retval;
}
}
adev->open_mode = mode;
adev->go = 1;
adev->d->set_bits(dev, 8);
adev->d->set_channels(dev, 1);
adev->d->set_speed(dev, DSP_DEFAULT_SPEED);
if (adev->dmap_out->dma_mode == DMODE_OUTPUT)
memset(adev->dmap_out->raw_buf, adev->dmap_out->neutral_byte,
adev->dmap_out->bytes_in_use);
return 0;
}
void DMAbuf_reset(int dev)
{
if (audio_devs[dev]->open_mode & OPEN_WRITE)
dma_reset_output(dev);
if (audio_devs[dev]->open_mode & OPEN_READ)
dma_reset_input(dev);
}
static void dma_reset_output(int dev)
{
struct audio_operations *adev = audio_devs[dev];
unsigned long flags,f ;
struct dma_buffparms *dmap = adev->dmap_out;
if (!(dmap->flags & DMA_STARTED))
return;
spin_lock_irqsave(&dmap->lock,flags);
adev->dmap_out->flags |= DMA_SYNCING;
adev->dmap_out->underrun_count = 0;
if (!signal_pending(current) && adev->dmap_out->qlen &&
adev->dmap_out->underrun_count == 0){
spin_unlock_irqrestore(&dmap->lock,flags);
interruptible_sleep_on_timeout(&adev->out_sleeper,
dmabuf_timeout(dmap));
spin_lock_irqsave(&dmap->lock,flags);
}
adev->dmap_out->flags &= ~(DMA_SYNCING | DMA_ACTIVE);
if (!(adev->flags & DMA_DUPLEX) || !adev->d->halt_output)
adev->d->halt_io(dev);
else
adev->d->halt_output(dev);
adev->dmap_out->flags &= ~DMA_STARTED;
f=claim_dma_lock();
clear_dma_ff(dmap->dma);
disable_dma(dmap->dma);
release_dma_lock(f);
dmap->byte_counter = 0;
reorganize_buffers(dev, adev->dmap_out, 0);
dmap->qlen = dmap->qhead = dmap->qtail = dmap->user_counter = 0;
spin_unlock_irqrestore(&dmap->lock,flags);
}
static void dma_reset_input(int dev)
{
struct audio_operations *adev = audio_devs[dev];
unsigned long flags;
struct dma_buffparms *dmap = adev->dmap_in;
spin_lock_irqsave(&dmap->lock,flags);
if (!(adev->flags & DMA_DUPLEX) || !adev->d->halt_input)
adev->d->halt_io(dev);
else
adev->d->halt_input(dev);
adev->dmap_in->flags &= ~DMA_STARTED;
dmap->qlen = dmap->qhead = dmap->qtail = dmap->user_counter = 0;
dmap->byte_counter = 0;
reorganize_buffers(dev, adev->dmap_in, 1);
spin_unlock_irqrestore(&dmap->lock,flags);
}
void DMAbuf_launch_output(int dev, struct dma_buffparms *dmap)
{
struct audio_operations *adev = audio_devs[dev];
if (!((adev->enable_bits * adev->go) & PCM_ENABLE_OUTPUT))
return;
dmap->dma_mode = DMODE_OUTPUT;
if (!(dmap->flags & DMA_ACTIVE) || !(adev->flags & DMA_AUTOMODE) || (dmap->flags & DMA_NODMA)) {
if (!(dmap->flags & DMA_STARTED)) {
reorganize_buffers(dev, dmap, 0);
if (adev->d->prepare_for_output(dev, dmap->fragment_size, dmap->nbufs))
return;
if (!(dmap->flags & DMA_NODMA))
local_start_dma(adev, dmap->raw_buf_phys, dmap->bytes_in_use,DMA_MODE_WRITE);
dmap->flags |= DMA_STARTED;
}
if (dmap->counts[dmap->qhead] == 0)
dmap->counts[dmap->qhead] = dmap->fragment_size;
dmap->dma_mode = DMODE_OUTPUT;
adev->d->output_block(dev, dmap->raw_buf_phys + dmap->qhead * dmap->fragment_size,
dmap->counts[dmap->qhead], 1);
if (adev->d->trigger)
adev->d->trigger(dev,adev->enable_bits * adev->go);
}
dmap->flags |= DMA_ACTIVE;
}
int DMAbuf_sync(int dev)
{
struct audio_operations *adev = audio_devs[dev];
unsigned long flags;
int n = 0;
struct dma_buffparms *dmap;
if (!adev->go && !(adev->enable_bits & PCM_ENABLE_OUTPUT))
return 0;
if (adev->dmap_out->dma_mode == DMODE_OUTPUT) {
dmap = adev->dmap_out;
spin_lock_irqsave(&dmap->lock,flags);
if (dmap->qlen > 0 && !(dmap->flags & DMA_ACTIVE))
DMAbuf_launch_output(dev, dmap);
adev->dmap_out->flags |= DMA_SYNCING;
adev->dmap_out->underrun_count = 0;
while (!signal_pending(current) && n++ < adev->dmap_out->nbufs &&
adev->dmap_out->qlen && adev->dmap_out->underrun_count == 0) {
long t = dmabuf_timeout(dmap);
spin_unlock_irqrestore(&dmap->lock,flags);
t = interruptible_sleep_on_timeout(&adev->out_sleeper, t);
spin_lock_irqsave(&dmap->lock,flags);
if (!t) {
adev->dmap_out->flags &= ~DMA_SYNCING;
spin_unlock_irqrestore(&dmap->lock,flags);
return adev->dmap_out->qlen;
}
}
adev->dmap_out->flags &= ~(DMA_SYNCING | DMA_ACTIVE);
if (adev->d->local_qlen) {
while (!signal_pending(current) &&
adev->d->local_qlen(dev)){
spin_unlock_irqrestore(&dmap->lock,flags);
interruptible_sleep_on_timeout(&adev->out_sleeper,
dmabuf_timeout(dmap));
spin_lock_irqsave(&dmap->lock,flags);
}
}
spin_unlock_irqrestore(&dmap->lock,flags);
}
adev->dmap_out->dma_mode = DMODE_NONE;
return adev->dmap_out->qlen;
}
int DMAbuf_release(int dev, int mode)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap;
unsigned long flags;
dmap = adev->dmap_out;
if (adev->open_mode & OPEN_WRITE)
adev->dmap_out->closing = 1;
if (adev->open_mode & OPEN_READ){
adev->dmap_in->closing = 1;
dmap = adev->dmap_in;
}
if (adev->open_mode & OPEN_WRITE)
if (!(adev->dmap_out->mapping_flags & DMA_MAP_MAPPED))
if (!signal_pending(current) && (adev->dmap_out->dma_mode == DMODE_OUTPUT))
DMAbuf_sync(dev);
if (adev->dmap_out->dma_mode == DMODE_OUTPUT)
memset(adev->dmap_out->raw_buf, adev->dmap_out->neutral_byte, adev->dmap_out->bytes_in_use);
DMAbuf_reset(dev);
spin_lock_irqsave(&dmap->lock,flags);
adev->d->close(dev);
if (adev->open_mode & OPEN_WRITE)
close_dmap(adev, adev->dmap_out);
if (adev->open_mode == OPEN_READ ||
(adev->open_mode != OPEN_WRITE &&
(adev->flags & DMA_DUPLEX)))
close_dmap(adev, adev->dmap_in);
adev->open_mode = 0;
spin_unlock_irqrestore(&dmap->lock,flags);
return 0;
}
int DMAbuf_activate_recording(int dev, struct dma_buffparms *dmap)
{
struct audio_operations *adev = audio_devs[dev];
int err;
if (!(adev->open_mode & OPEN_READ))
return 0;
if (!(adev->enable_bits & PCM_ENABLE_INPUT))
return 0;
if (dmap->dma_mode == DMODE_OUTPUT) {
spin_unlock_irq(&dmap->lock);
DMAbuf_sync(dev);
DMAbuf_reset(dev);
spin_lock_irq(&dmap->lock);
dmap->dma_mode = DMODE_NONE;
}
if (!dmap->dma_mode) {
reorganize_buffers(dev, dmap, 1);
if ((err = adev->d->prepare_for_input(dev,
dmap->fragment_size, dmap->nbufs)) < 0)
return err;
dmap->dma_mode = DMODE_INPUT;
}
if (!(dmap->flags & DMA_ACTIVE)) {
if (dmap->needs_reorg)
reorganize_buffers(dev, dmap, 0);
local_start_dma(adev, dmap->raw_buf_phys, dmap->bytes_in_use, DMA_MODE_READ);
adev->d->start_input(dev, dmap->raw_buf_phys + dmap->qtail * dmap->fragment_size,
dmap->fragment_size, 0);
dmap->flags |= DMA_ACTIVE;
if (adev->d->trigger)
adev->d->trigger(dev, adev->enable_bits * adev->go);
}
return 0;
}
int DMAbuf_getrdbuffer(int dev, char **buf, int *len, int dontblock)
{
struct audio_operations *adev = audio_devs[dev];
unsigned long flags;
int err = 0, n = 0;
struct dma_buffparms *dmap = adev->dmap_in;
int go;
if (!(adev->open_mode & OPEN_READ))
return -EIO;
spin_lock_irqsave(&dmap->lock,flags);
if (dmap->needs_reorg)
reorganize_buffers(dev, dmap, 0);
if (adev->dmap_in->mapping_flags & DMA_MAP_MAPPED) {
spin_unlock_irqrestore(&dmap->lock,flags);
return -EINVAL;
} else while (dmap->qlen <= 0 && n++ < 10) {
long timeout = MAX_SCHEDULE_TIMEOUT;
if (!(adev->enable_bits & PCM_ENABLE_INPUT) || !adev->go) {
spin_unlock_irqrestore(&dmap->lock,flags);
return -EAGAIN;
}
if ((err = DMAbuf_activate_recording(dev, dmap)) < 0) {
spin_unlock_irqrestore(&dmap->lock,flags);
return err;
}
if (dontblock) {
spin_unlock_irqrestore(&dmap->lock,flags);
return -EAGAIN;
}
if ((go = adev->go))
timeout = dmabuf_timeout(dmap);
spin_unlock_irqrestore(&dmap->lock,flags);
timeout = interruptible_sleep_on_timeout(&adev->in_sleeper,
timeout);
if (!timeout) {
err = -EIO;
printk(KERN_WARNING "Sound: DMA (input) timed out - IRQ/DRQ config error?\n");
dma_reset_input(dev);
} else
err = -EINTR;
spin_lock_irqsave(&dmap->lock,flags);
}
spin_unlock_irqrestore(&dmap->lock,flags);
if (dmap->qlen <= 0)
return err ? err : -EINTR;
*buf = &dmap->raw_buf[dmap->qhead * dmap->fragment_size + dmap->counts[dmap->qhead]];
*len = dmap->fragment_size - dmap->counts[dmap->qhead];
return dmap->qhead;
}
int DMAbuf_rmchars(int dev, int buff_no, int c)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_in;
int p = dmap->counts[dmap->qhead] + c;
if (dmap->mapping_flags & DMA_MAP_MAPPED)
{
return -EINVAL;
}
else if (dmap->qlen <= 0)
return -EIO;
else if (p >= dmap->fragment_size) {
dmap->counts[dmap->qhead] = 0;
dmap->qlen--;
dmap->qhead = (dmap->qhead + 1) % dmap->nbufs;
}
else dmap->counts[dmap->qhead] = p;
return 0;
}
int DMAbuf_get_buffer_pointer(int dev, struct dma_buffparms *dmap, int direction)
{
int pos;
unsigned long f;
if (!(dmap->flags & DMA_ACTIVE))
pos = 0;
else {
int chan = dmap->dma;
f=claim_dma_lock();
clear_dma_ff(chan);
if(!isa_dma_bridge_buggy)
disable_dma(dmap->dma);
pos = get_dma_residue(chan);
pos = dmap->bytes_in_use - pos;
if (!(dmap->mapping_flags & DMA_MAP_MAPPED)) {
if (direction == DMODE_OUTPUT) {
if (dmap->qhead == 0)
if (pos > dmap->fragment_size)
pos = 0;
} else {
if (dmap->qtail == 0)
if (pos > dmap->fragment_size)
pos = 0;
}
}
if (pos < 0)
pos = 0;
if (pos >= dmap->bytes_in_use)
pos = 0;
if(!isa_dma_bridge_buggy)
enable_dma(dmap->dma);
release_dma_lock(f);
}
return pos;
}
void DMAbuf_start_devices(unsigned int devmask)
{
struct audio_operations *adev;
int dev;
for (dev = 0; dev < num_audiodevs; dev++) {
if (!(devmask & (1 << dev)))
continue;
if (!(adev = audio_devs[dev]))
continue;
if (adev->open_mode == 0)
continue;
if (adev->go)
continue;
adev->go = 1;
if (adev->d->trigger)
adev->d->trigger(dev,adev->enable_bits * adev->go);
}
}
int DMAbuf_space_in_queue(int dev)
{
struct audio_operations *adev = audio_devs[dev];
int len, max, tmp;
struct dma_buffparms *dmap = adev->dmap_out;
int lim = dmap->nbufs;
if (lim < 2)
lim = 2;
if (dmap->qlen >= lim)
return 0;
max = dmap->max_fragments;
if (max > lim)
max = lim;
len = dmap->qlen;
if (adev->d->local_qlen) {
tmp = adev->d->local_qlen(dev);
if (tmp && len)
tmp--;
len += tmp;
}
if (dmap->byte_counter % dmap->fragment_size)
len = len + 1;
if (len >= max)
return 0;
return max - len;
}
static int output_sleep(int dev, int dontblock)
{
struct audio_operations *adev = audio_devs[dev];
int err = 0;
struct dma_buffparms *dmap = adev->dmap_out;
long timeout;
long timeout_value;
if (dontblock)
return -EAGAIN;
if (!(adev->enable_bits & PCM_ENABLE_OUTPUT))
return -EAGAIN;
if (signal_pending(current))
return -EINTR;
timeout = (adev->go && !(dmap->flags & DMA_NOTIMEOUT));
if (timeout)
timeout_value = dmabuf_timeout(dmap);
else
timeout_value = MAX_SCHEDULE_TIMEOUT;
timeout_value = interruptible_sleep_on_timeout(&adev->out_sleeper,
timeout_value);
if (timeout != MAX_SCHEDULE_TIMEOUT && !timeout_value) {
printk(KERN_WARNING "Sound: DMA (output) timed out - IRQ/DRQ config error?\n");
dma_reset_output(dev);
} else {
if (signal_pending(current))
err = -EINTR;
}
return err;
}
static int find_output_space(int dev, char **buf, int *size)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_out;
unsigned long active_offs;
long len, offs;
int maxfrags;
int occupied_bytes = (dmap->user_counter % dmap->fragment_size);
*buf = dmap->raw_buf;
if (!(maxfrags = DMAbuf_space_in_queue(dev)) && !occupied_bytes)
return 0;
#ifdef BE_CONSERVATIVE
active_offs = dmap->byte_counter + dmap->qhead * dmap->fragment_size;
#else
active_offs = max(DMAbuf_get_buffer_pointer(dev, dmap, DMODE_OUTPUT), 0);
if (active_offs >= dmap->bytes_in_use)
active_offs = 0;
active_offs += dmap->byte_counter;
#endif
offs = (dmap->user_counter % dmap->bytes_in_use) & ~SAMPLE_ROUNDUP;
if (offs < 0 || offs >= dmap->bytes_in_use) {
printk(KERN_ERR "Sound: Got unexpected offs %ld. Giving up.\n", offs);
printk("Counter = %ld, bytes=%d\n", dmap->user_counter, dmap->bytes_in_use);
return 0;
}
*buf = dmap->raw_buf + offs;
len = active_offs + dmap->bytes_in_use - dmap->user_counter;
if ((offs + len) > dmap->bytes_in_use)
len = dmap->bytes_in_use - offs;
if (len < 0) {
return 0;
}
if (len > ((maxfrags * dmap->fragment_size) - occupied_bytes))
len = (maxfrags * dmap->fragment_size) - occupied_bytes;
*size = len & ~SAMPLE_ROUNDUP;
return (*size > 0);
}
int DMAbuf_getwrbuffer(int dev, char **buf, int *size, int dontblock)
{
struct audio_operations *adev = audio_devs[dev];
unsigned long flags;
int err = -EIO;
struct dma_buffparms *dmap = adev->dmap_out;
if (dmap->mapping_flags & DMA_MAP_MAPPED) {
return -EINVAL;
}
spin_lock_irqsave(&dmap->lock,flags);
if (dmap->needs_reorg)
reorganize_buffers(dev, dmap, 0);
if (dmap->dma_mode == DMODE_INPUT) {
spin_unlock_irqrestore(&dmap->lock,flags);
DMAbuf_reset(dev);
spin_lock_irqsave(&dmap->lock,flags);
}
dmap->dma_mode = DMODE_OUTPUT;
while (find_output_space(dev, buf, size) <= 0) {
spin_unlock_irqrestore(&dmap->lock,flags);
if ((err = output_sleep(dev, dontblock)) < 0) {
return err;
}
spin_lock_irqsave(&dmap->lock,flags);
}
spin_unlock_irqrestore(&dmap->lock,flags);
return 0;
}
int DMAbuf_move_wrpointer(int dev, int l)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_out;
unsigned long ptr;
unsigned long end_ptr, p;
int post;
unsigned long flags;
spin_lock_irqsave(&dmap->lock,flags);
post= (dmap->flags & DMA_POST);
ptr = (dmap->user_counter / dmap->fragment_size) * dmap->fragment_size;
dmap->flags &= ~DMA_POST;
dmap->cfrag = -1;
dmap->user_counter += l;
dmap->flags |= DMA_DIRTY;
if (dmap->byte_counter >= dmap->max_byte_counter) {
long decr = dmap->byte_counter;
dmap->byte_counter = (dmap->byte_counter % dmap->bytes_in_use);
decr -= dmap->byte_counter;
dmap->user_counter -= decr;
}
end_ptr = (dmap->user_counter / dmap->fragment_size) * dmap->fragment_size;
p = (dmap->user_counter - 1) % dmap->bytes_in_use;
dmap->neutral_byte = dmap->raw_buf[p];
while (ptr < end_ptr) {
dmap->counts[dmap->qtail] = dmap->fragment_size;
dmap->qtail = (dmap->qtail + 1) % dmap->nbufs;
dmap->qlen++;
ptr += dmap->fragment_size;
}
dmap->counts[dmap->qtail] = dmap->user_counter - ptr;
if (adev->d->postprocess_write)
adev->d->postprocess_write(dev);
if (!(dmap->flags & DMA_ACTIVE))
if (dmap->qlen > 1 || (dmap->qlen > 0 && (post || dmap->qlen >= dmap->nbufs - 1)))
DMAbuf_launch_output(dev, dmap);
spin_unlock_irqrestore(&dmap->lock,flags);
return 0;
}
int DMAbuf_start_dma(int dev, unsigned long physaddr, int count, int dma_mode)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = (dma_mode == DMA_MODE_WRITE) ? adev->dmap_out : adev->dmap_in;
if (dmap->raw_buf == NULL) {
printk(KERN_ERR "sound: DMA buffer(1) == NULL\n");
printk("Device %d, chn=%s\n", dev, (dmap == adev->dmap_out) ? "out" : "in");
return 0;
}
if (dmap->dma < 0)
return 0;
sound_start_dma(dmap, physaddr, count, dma_mode);
return count;
}
static int local_start_dma(struct audio_operations *adev, unsigned long physaddr, int count, int dma_mode)
{
struct dma_buffparms *dmap = (dma_mode == DMA_MODE_WRITE) ? adev->dmap_out : adev->dmap_in;
if (dmap->raw_buf == NULL) {
printk(KERN_ERR "sound: DMA buffer(2) == NULL\n");
printk(KERN_ERR "Device %s, chn=%s\n", adev->name, (dmap == adev->dmap_out) ? "out" : "in");
return 0;
}
if (dmap->flags & DMA_NODMA)
return 1;
if (dmap->dma < 0)
return 0;
sound_start_dma(dmap, dmap->raw_buf_phys, dmap->bytes_in_use, dma_mode | DMA_AUTOINIT);
dmap->flags |= DMA_STARTED;
return count;
}
static void finish_output_interrupt(int dev, struct dma_buffparms *dmap)
{
struct audio_operations *adev = audio_devs[dev];
if (dmap->audio_callback != NULL)
dmap->audio_callback(dev, dmap->callback_parm);
wake_up(&adev->out_sleeper);
wake_up(&adev->poll_sleeper);
}
static void do_outputintr(int dev, int dummy)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_out;
int this_fragment;
if (dmap->raw_buf == NULL) {
printk(KERN_ERR "Sound: Error. Audio interrupt (%d) after freeing buffers.\n", dev);
return;
}
if (dmap->mapping_flags & DMA_MAP_MAPPED) {
dmap->qhead = (dmap->qhead + 1) % dmap->nbufs;
if (dmap->qhead == 0) {
dmap->byte_counter += dmap->bytes_in_use;
if (dmap->byte_counter >= dmap->max_byte_counter) {
long decr = dmap->byte_counter;
dmap->byte_counter = (dmap->byte_counter % dmap->bytes_in_use);
decr -= dmap->byte_counter;
dmap->user_counter -= decr;
}
}
dmap->qlen++;
if (!(adev->flags & DMA_AUTOMODE))
dmap->flags &= ~DMA_ACTIVE;
dmap->counts[dmap->qhead] = dmap->fragment_size;
DMAbuf_launch_output(dev, dmap);
finish_output_interrupt(dev, dmap);
return;
}
dmap->qlen--;
this_fragment = dmap->qhead;
dmap->qhead = (dmap->qhead + 1) % dmap->nbufs;
if (dmap->qhead == 0) {
dmap->byte_counter += dmap->bytes_in_use;
if (dmap->byte_counter >= dmap->max_byte_counter) {
long decr = dmap->byte_counter;
dmap->byte_counter = (dmap->byte_counter % dmap->bytes_in_use);
decr -= dmap->byte_counter;
dmap->user_counter -= decr;
}
}
if (!(adev->flags & DMA_AUTOMODE))
dmap->flags &= ~DMA_ACTIVE;
while (dmap->qlen <= -dmap->closing) {
dmap->underrun_count++;
dmap->qlen++;
if ((dmap->flags & DMA_DIRTY) && dmap->applic_profile != APF_CPUINTENS) {
dmap->flags &= ~DMA_DIRTY;
memset(adev->dmap_out->raw_buf, adev->dmap_out->neutral_byte,
adev->dmap_out->buffsize);
}
dmap->user_counter += dmap->fragment_size;
dmap->qtail = (dmap->qtail + 1) % dmap->nbufs;
}
if (dmap->qlen > 0)
DMAbuf_launch_output(dev, dmap);
finish_output_interrupt(dev, dmap);
}
void DMAbuf_outputintr(int dev, int notify_only)
{
struct audio_operations *adev = audio_devs[dev];
unsigned long flags;
struct dma_buffparms *dmap = adev->dmap_out;
spin_lock_irqsave(&dmap->lock,flags);
if (!(dmap->flags & DMA_NODMA)) {
int chan = dmap->dma, pos, n;
unsigned long f;
f=claim_dma_lock();
if(!isa_dma_bridge_buggy)
disable_dma(dmap->dma);
clear_dma_ff(chan);
pos = dmap->bytes_in_use - get_dma_residue(chan);
if(!isa_dma_bridge_buggy)
enable_dma(dmap->dma);
release_dma_lock(f);
pos = pos / dmap->fragment_size;
if (pos < 0 || pos >= dmap->nbufs)
pos = 0;
n = 0;
while (dmap->qhead != pos && n++ < dmap->nbufs)
do_outputintr(dev, notify_only);
}
else
do_outputintr(dev, notify_only);
spin_unlock_irqrestore(&dmap->lock,flags);
}
static void do_inputintr(int dev)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_in;
if (dmap->raw_buf == NULL) {
printk(KERN_ERR "Sound: Fatal error. Audio interrupt after freeing buffers.\n");
return;
}
if (dmap->mapping_flags & DMA_MAP_MAPPED) {
dmap->qtail = (dmap->qtail + 1) % dmap->nbufs;
if (dmap->qtail == 0) {
dmap->byte_counter += dmap->bytes_in_use;
if (dmap->byte_counter >= dmap->max_byte_counter) {
long decr = dmap->byte_counter;
dmap->byte_counter = (dmap->byte_counter % dmap->bytes_in_use) + dmap->bytes_in_use;
decr -= dmap->byte_counter;
dmap->user_counter -= decr;
}
}
dmap->qlen++;
if (!(adev->flags & DMA_AUTOMODE)) {
if (dmap->needs_reorg)
reorganize_buffers(dev, dmap, 0);
local_start_dma(adev, dmap->raw_buf_phys, dmap->bytes_in_use,DMA_MODE_READ);
adev->d->start_input(dev, dmap->raw_buf_phys + dmap->qtail * dmap->fragment_size,
dmap->fragment_size, 1);
if (adev->d->trigger)
adev->d->trigger(dev, adev->enable_bits * adev->go);
}
dmap->flags |= DMA_ACTIVE;
} else if (dmap->qlen >= (dmap->nbufs - 1)) {
printk(KERN_WARNING "Sound: Recording overrun\n");
dmap->underrun_count++;
dmap->qhead = (dmap->qhead + 1) % dmap->nbufs;
dmap->qtail = (dmap->qtail + 1) % dmap->nbufs;
} else if (dmap->qlen >= 0 && dmap->qlen < dmap->nbufs) {
dmap->qlen++;
dmap->qtail = (dmap->qtail + 1) % dmap->nbufs;
if (dmap->qtail == 0) {
dmap->byte_counter += dmap->bytes_in_use;
if (dmap->byte_counter >= dmap->max_byte_counter) {
long decr = dmap->byte_counter;
dmap->byte_counter = (dmap->byte_counter % dmap->bytes_in_use) + dmap->bytes_in_use;
decr -= dmap->byte_counter;
dmap->user_counter -= decr;
}
}
}
if (!(adev->flags & DMA_AUTOMODE) || (dmap->flags & DMA_NODMA)) {
local_start_dma(adev, dmap->raw_buf_phys, dmap->bytes_in_use, DMA_MODE_READ);
adev->d->start_input(dev, dmap->raw_buf_phys + dmap->qtail * dmap->fragment_size, dmap->fragment_size, 1);
if (adev->d->trigger)
adev->d->trigger(dev,adev->enable_bits * adev->go);
}
dmap->flags |= DMA_ACTIVE;
if (dmap->qlen > 0)
{
wake_up(&adev->in_sleeper);
wake_up(&adev->poll_sleeper);
}
}
void DMAbuf_inputintr(int dev)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_in;
unsigned long flags;
spin_lock_irqsave(&dmap->lock,flags);
if (!(dmap->flags & DMA_NODMA)) {
int chan = dmap->dma, pos, n;
unsigned long f;
f=claim_dma_lock();
if(!isa_dma_bridge_buggy)
disable_dma(dmap->dma);
clear_dma_ff(chan);
pos = dmap->bytes_in_use - get_dma_residue(chan);
if(!isa_dma_bridge_buggy)
enable_dma(dmap->dma);
release_dma_lock(f);
pos = pos / dmap->fragment_size;
if (pos < 0 || pos >= dmap->nbufs)
pos = 0;
n = 0;
while (dmap->qtail != pos && ++n < dmap->nbufs)
do_inputintr(dev);
} else
do_inputintr(dev);
spin_unlock_irqrestore(&dmap->lock,flags);
}
void DMAbuf_init(int dev, int dma1, int dma2)
{
struct audio_operations *adev = audio_devs[dev];
if (adev && adev->dmap_out == NULL) {
if (adev->d == NULL)
panic("OSS: audio_devs[%d]->d == NULL\n", dev);
if (adev->parent_dev) {
int parent = adev->parent_dev - 1;
adev->dmap_out = audio_devs[parent]->dmap_out;
adev->dmap_in = audio_devs[parent]->dmap_in;
} else {
adev->dmap_out = adev->dmap_in = &adev->dmaps[0];
adev->dmap_out->dma = dma1;
if (adev->flags & DMA_DUPLEX) {
adev->dmap_in = &adev->dmaps[1];
adev->dmap_in->dma = dma2;
}
}
if (sound_dmap_flag == DMAP_KEEP_ON_CLOSE) {
if (adev->dmap_in->raw_buf == NULL)
sound_alloc_dmap(adev->dmap_in);
if (adev->dmap_out->raw_buf == NULL)
sound_alloc_dmap(adev->dmap_out);
}
}
}
static unsigned int poll_input(struct file * file, int dev, poll_table *wait)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_in;
if (!(adev->open_mode & OPEN_READ))
return 0;
if (dmap->mapping_flags & DMA_MAP_MAPPED) {
if (dmap->qlen)
return POLLIN | POLLRDNORM;
return 0;
}
if (dmap->dma_mode != DMODE_INPUT) {
if (dmap->dma_mode == DMODE_NONE &&
adev->enable_bits & PCM_ENABLE_INPUT &&
!dmap->qlen && adev->go) {
unsigned long flags;
spin_lock_irqsave(&dmap->lock,flags);
DMAbuf_activate_recording(dev, dmap);
spin_unlock_irqrestore(&dmap->lock,flags);
}
return 0;
}
if (!dmap->qlen)
return 0;
return POLLIN | POLLRDNORM;
}
static unsigned int poll_output(struct file * file, int dev, poll_table *wait)
{
struct audio_operations *adev = audio_devs[dev];
struct dma_buffparms *dmap = adev->dmap_out;
if (!(adev->open_mode & OPEN_WRITE))
return 0;
if (dmap->mapping_flags & DMA_MAP_MAPPED) {
if (dmap->qlen)
return POLLOUT | POLLWRNORM;
return 0;
}
if (dmap->dma_mode == DMODE_INPUT)
return 0;
if (dmap->dma_mode == DMODE_NONE)
return POLLOUT | POLLWRNORM;
if (!DMAbuf_space_in_queue(dev))
return 0;
return POLLOUT | POLLWRNORM;
}
unsigned int DMAbuf_poll(struct file * file, int dev, poll_table *wait)
{
struct audio_operations *adev = audio_devs[dev];
poll_wait(file, &adev->poll_sleeper, wait);
return poll_input(file, dev, wait) | poll_output(file, dev, wait);
}
void DMAbuf_deinit(int dev)
{
struct audio_operations *adev = audio_devs[dev];
if (!adev)
return;
if (sound_dmap_flag == DMAP_KEEP_ON_CLOSE) {
sound_free_dmap(adev->dmap_out);
if (adev->flags & DMA_DUPLEX)
sound_free_dmap(adev->dmap_in);
}
}
