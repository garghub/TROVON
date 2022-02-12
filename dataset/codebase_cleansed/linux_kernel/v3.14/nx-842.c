static inline int nx842_header_size(const struct nx842_header *hdr)
{
return sizeof(struct nx842_header) +
hdr->blocks_nr * sizeof(hdr->sizes[0]);
}
static void ibm_nx842_incr_hist(atomic64_t *times, unsigned int time)
{
int bucket = fls(time);
if (bucket)
bucket = min((NX842_HIST_SLOTS - 1), bucket - 1);
atomic64_inc(&times[bucket]);
}
static unsigned long nx842_get_desired_dma(struct vio_dev *viodev)
{
return 0;
}
static inline unsigned long nx842_get_scatterlist_size(
struct nx842_scatterlist *sl)
{
return sl->entry_nr * sizeof(struct nx842_slentry);
}
static inline unsigned long nx842_get_pa(void *addr)
{
if (is_vmalloc_addr(addr))
return page_to_phys(vmalloc_to_page(addr))
+ offset_in_page(addr);
else
return __pa(addr);
}
static int nx842_build_scatterlist(unsigned long buf, int len,
struct nx842_scatterlist *sl)
{
unsigned long nextpage;
struct nx842_slentry *entry;
sl->entry_nr = 0;
entry = sl->entries;
while (len) {
entry->ptr = nx842_get_pa((void *)buf);
nextpage = ALIGN(buf + 1, NX842_HW_PAGE_SIZE);
if (nextpage < buf + len) {
if (IS_ALIGNED(buf, NX842_HW_PAGE_SIZE))
entry->len = NX842_HW_PAGE_SIZE;
else
entry->len = nextpage - buf;
} else {
entry->len = len;
}
len -= entry->len;
buf += entry->len;
sl->entry_nr++;
entry++;
}
return 0;
}
int nx842_get_workmem_size(void)
{
return sizeof(struct nx842_workmem) + NX842_HW_PAGE_SIZE;
}
int nx842_get_workmem_size_aligned(void)
{
return sizeof(struct nx842_workmem);
}
static int nx842_validate_result(struct device *dev,
struct cop_status_block *csb)
{
if (!NX842_CSBCBP_VALID_CHK(csb->valid)) {
dev_err(dev, "%s: cspcbp not valid upon completion.\n",
__func__);
dev_dbg(dev, "valid:0x%02x cs:0x%02x cc:0x%02x ce:0x%02x\n",
csb->valid,
csb->crb_seq_number,
csb->completion_code,
csb->completion_extension);
dev_dbg(dev, "processed_bytes:%d address:0x%016lx\n",
csb->processed_byte_count,
(unsigned long)csb->address);
return -EIO;
}
switch (csb->completion_code) {
case 0:
break;
case 64:
case 13:
dev_dbg(dev, "%s: Compression output larger than input\n",
__func__);
return -ENOSPC;
case 66:
case 67:
dev_dbg(dev, "%s: Bad data for decompression (code:%d)\n",
__func__, csb->completion_code);
return -EINVAL;
default:
dev_dbg(dev, "%s: Unspecified error (code:%d)\n",
__func__, csb->completion_code);
return -EIO;
}
if (!NX842_CSBCPB_CE2(csb->completion_extension)) {
dev_err(dev, "%s: No error returned by hardware, but "
"data returned is unusable, contact support.\n"
"(Additional info: csbcbp->processed bytes "
"does not specify processed bytes for the "
"target buffer.)\n", __func__);
return -EIO;
}
return 0;
}
int nx842_compress(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlen, void *wmem)
{
struct nx842_header *hdr;
struct nx842_devdata *local_devdata;
struct device *dev = NULL;
struct nx842_workmem *workmem;
struct nx842_scatterlist slin, slout;
struct nx_csbcpb *csbcpb;
int ret = 0, max_sync_size, i, bytesleft, size, hdrsize;
unsigned long inbuf, outbuf, padding;
struct vio_pfo_op op = {
.done = NULL,
.handle = 0,
.timeout = 0,
};
unsigned long start_time = get_tb();
inbuf = (unsigned long)in;
if (!IS_ALIGNED(inbuf, PAGE_SIZE) || inlen != PAGE_SIZE)
return -EINVAL;
rcu_read_lock();
local_devdata = rcu_dereference(devdata);
if (!local_devdata || !local_devdata->dev) {
rcu_read_unlock();
return -ENODEV;
}
max_sync_size = local_devdata->max_sync_size;
dev = local_devdata->dev;
hdr = (struct nx842_header *)out;
hdr->blocks_nr = PAGE_SIZE / max_sync_size;
hdrsize = nx842_header_size(hdr);
outbuf = (unsigned long)out + hdrsize;
bytesleft = *outlen - hdrsize;
workmem = (struct nx842_workmem *)ALIGN((unsigned long)wmem,
NX842_HW_PAGE_SIZE);
slin.entries = (struct nx842_slentry *)workmem->slin;
slout.entries = (struct nx842_slentry *)workmem->slout;
op.flags = NX842_OP_COMPRESS;
csbcpb = &workmem->csbcpb;
memset(csbcpb, 0, sizeof(*csbcpb));
op.csbcpb = nx842_get_pa(csbcpb);
op.out = nx842_get_pa(slout.entries);
for (i = 0; i < hdr->blocks_nr; i++) {
padding = ALIGN(outbuf, IO_BUFFER_ALIGN) - outbuf;
outbuf += padding;
bytesleft -= padding;
if (i == 0)
hdr->offset = padding + hdrsize;
if (bytesleft <= 0) {
ret = -ENOSPC;
goto unlock;
}
if (likely(max_sync_size == NX842_HW_PAGE_SIZE)) {
op.in = nx842_get_pa((void *)inbuf);
op.inlen = max_sync_size;
} else {
nx842_build_scatterlist(inbuf, max_sync_size, &slin);
op.in = nx842_get_pa(slin.entries);
op.inlen = -nx842_get_scatterlist_size(&slin);
}
nx842_build_scatterlist(outbuf,
min(bytesleft, max_sync_size), &slout);
op.outlen = -nx842_get_scatterlist_size(&slout);
ret = vio_h_cop_sync(local_devdata->vdev, &op);
if (ret) {
dev_dbg(dev, "%s: vio_h_cop_sync error (ret=%d, hret=%ld)\n",
__func__, ret, op.hcall_err);
ret = -EIO;
goto unlock;
}
ret = nx842_validate_result(dev, &csbcpb->csb);
if (ret && ret != -ENOSPC)
goto unlock;
if (unlikely(ret == -ENOSPC)) {
if (bytesleft < max_sync_size) {
goto unlock;
} else {
memcpy((void *)outbuf, (void *)inbuf,
max_sync_size);
hdr->sizes[i] = -max_sync_size;
outbuf += max_sync_size;
bytesleft -= max_sync_size;
ret = 0;
}
} else {
size = csbcpb->csb.processed_byte_count;
dev_dbg(dev, "%s: processed_bytes=%d\n",
__func__, size);
hdr->sizes[i] = size;
outbuf += size;
bytesleft -= size;
}
inbuf += max_sync_size;
}
*outlen = (unsigned int)(outbuf - (unsigned long)out);
unlock:
if (ret)
nx842_inc_comp_failed(local_devdata);
else {
nx842_inc_comp_complete(local_devdata);
ibm_nx842_incr_hist(local_devdata->counters->comp_times,
(get_tb() - start_time) / tb_ticks_per_usec);
}
rcu_read_unlock();
return ret;
}
int nx842_decompress(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlen, void *wmem)
{
struct nx842_header *hdr;
struct nx842_devdata *local_devdata;
struct device *dev = NULL;
struct nx842_workmem *workmem;
struct nx842_scatterlist slin, slout;
struct nx_csbcpb *csbcpb;
int ret = 0, i, size, max_sync_size;
unsigned long inbuf, outbuf;
struct vio_pfo_op op = {
.done = NULL,
.handle = 0,
.timeout = 0,
};
unsigned long start_time = get_tb();
outbuf = (unsigned long)out;
if (!IS_ALIGNED(outbuf, PAGE_SIZE) || *outlen != PAGE_SIZE)
return -EINVAL;
rcu_read_lock();
local_devdata = rcu_dereference(devdata);
if (local_devdata)
dev = local_devdata->dev;
hdr = (struct nx842_header *)in;
workmem = (struct nx842_workmem *)ALIGN((unsigned long)wmem,
NX842_HW_PAGE_SIZE);
inbuf = (unsigned long)in + hdr->offset;
if (likely(!IS_ALIGNED(inbuf, IO_BUFFER_ALIGN))) {
memcpy(workmem->bounce, in + hdr->offset, inlen - hdr->offset);
inbuf = (unsigned long)workmem->bounce;
}
slin.entries = (struct nx842_slentry *)workmem->slin;
slout.entries = (struct nx842_slentry *)workmem->slout;
op.flags = NX842_OP_DECOMPRESS;
csbcpb = &workmem->csbcpb;
memset(csbcpb, 0, sizeof(*csbcpb));
op.csbcpb = nx842_get_pa(csbcpb);
max_sync_size = PAGE_SIZE / hdr->blocks_nr;
for (i = 0; i < hdr->blocks_nr; i++) {
inbuf = ALIGN(inbuf, IO_BUFFER_ALIGN);
if (hdr->sizes[i] < 0) {
size = abs(hdr->sizes[i]);
memcpy((void *)outbuf, (void *)inbuf, size);
outbuf += size;
inbuf += size;
continue;
}
if (!dev)
goto sw;
if (likely((inbuf & NX842_HW_PAGE_MASK) ==
((inbuf + hdr->sizes[i] - 1) & NX842_HW_PAGE_MASK))) {
op.in = nx842_get_pa((void *)inbuf);
op.inlen = hdr->sizes[i];
} else {
nx842_build_scatterlist(inbuf, hdr->sizes[i] , &slin);
op.in = nx842_get_pa(slin.entries);
op.inlen = -nx842_get_scatterlist_size(&slin);
}
if (likely(max_sync_size == NX842_HW_PAGE_SIZE)) {
op.out = nx842_get_pa((void *)outbuf);
op.outlen = max_sync_size;
} else {
nx842_build_scatterlist(outbuf, max_sync_size, &slout);
op.out = nx842_get_pa(slout.entries);
op.outlen = -nx842_get_scatterlist_size(&slout);
}
ret = vio_h_cop_sync(local_devdata->vdev, &op);
if (ret) {
dev_dbg(dev, "%s: vio_h_cop_sync error (ret=%d, hret=%ld)\n",
__func__, ret, op.hcall_err);
dev = NULL;
goto sw;
}
ret = nx842_validate_result(dev, &csbcpb->csb);
if (ret) {
dev = NULL;
goto sw;
}
inbuf += hdr->sizes[i];
outbuf += csbcpb->csb.processed_byte_count;
continue;
sw:
size = max_sync_size;
ret = sw842_decompress(
(unsigned char *)inbuf, hdr->sizes[i],
(unsigned char *)outbuf, &size, wmem);
if (ret)
pr_debug("%s: sw842_decompress failed with %d\n",
__func__, ret);
if (ret) {
if (ret != -ENOSPC && ret != -EINVAL &&
ret != -EMSGSIZE)
ret = -EIO;
goto unlock;
}
inbuf += hdr->sizes[i];
outbuf += size;
}
*outlen = (unsigned int)(outbuf - (unsigned long)out);
unlock:
if (ret)
nx842_inc_decomp_failed(local_devdata);
else {
if (!dev)
nx842_inc_swdecomp(local_devdata);
nx842_inc_decomp_complete(local_devdata);
ibm_nx842_incr_hist(local_devdata->counters->decomp_times,
(get_tb() - start_time) / tb_ticks_per_usec);
}
rcu_read_unlock();
return ret;
}
static int nx842_OF_set_defaults(struct nx842_devdata *devdata)
{
if (devdata) {
devdata->max_sync_size = 0;
devdata->max_sync_sg = 0;
devdata->max_sg_len = 0;
devdata->status = UNAVAILABLE;
return 0;
} else
return -ENOENT;
}
static int nx842_OF_upd_status(struct nx842_devdata *devdata,
struct property *prop) {
int ret = 0;
const char *status = (const char *)prop->value;
if (!strncmp(status, "okay", (size_t)prop->length)) {
devdata->status = AVAILABLE;
} else {
dev_info(devdata->dev, "%s: status '%s' is not 'okay'\n",
__func__, status);
devdata->status = UNAVAILABLE;
}
return ret;
}
static int nx842_OF_upd_maxsglen(struct nx842_devdata *devdata,
struct property *prop) {
int ret = 0;
const int *maxsglen = prop->value;
if (prop->length != sizeof(*maxsglen)) {
dev_err(devdata->dev, "%s: unexpected format for ibm,max-sg-len property\n", __func__);
dev_dbg(devdata->dev, "%s: ibm,max-sg-len is %d bytes long, expected %lu bytes\n", __func__,
prop->length, sizeof(*maxsglen));
ret = -EINVAL;
} else {
devdata->max_sg_len = (unsigned int)min(*maxsglen,
(int)NX842_HW_PAGE_SIZE);
}
return ret;
}
static int nx842_OF_upd_maxsyncop(struct nx842_devdata *devdata,
struct property *prop) {
int ret = 0;
const struct maxsynccop_t {
int comp_elements;
int comp_data_limit;
int comp_sg_limit;
int decomp_elements;
int decomp_data_limit;
int decomp_sg_limit;
} *maxsynccop;
if (prop->length != sizeof(*maxsynccop)) {
dev_err(devdata->dev, "%s: unexpected format for ibm,max-sync-cop property\n", __func__);
dev_dbg(devdata->dev, "%s: ibm,max-sync-cop is %d bytes long, expected %lu bytes\n", __func__, prop->length,
sizeof(*maxsynccop));
ret = -EINVAL;
goto out;
}
maxsynccop = (const struct maxsynccop_t *)prop->value;
devdata->max_sync_size =
(unsigned int)min(maxsynccop->comp_data_limit,
maxsynccop->decomp_data_limit);
devdata->max_sync_size = min_t(unsigned int, devdata->max_sync_size,
SIZE_64K);
if (devdata->max_sync_size < SIZE_4K) {
dev_err(devdata->dev, "%s: hardware max data size (%u) is "
"less than the driver minimum, unable to use "
"the hardware device\n",
__func__, devdata->max_sync_size);
ret = -EINVAL;
goto out;
}
devdata->max_sync_sg = (unsigned int)min(maxsynccop->comp_sg_limit,
maxsynccop->decomp_sg_limit);
if (devdata->max_sync_sg < 1) {
dev_err(devdata->dev, "%s: hardware max sg size (%u) is "
"less than the driver minimum, unable to use "
"the hardware device\n",
__func__, devdata->max_sync_sg);
ret = -EINVAL;
goto out;
}
out:
return ret;
}
static int nx842_OF_upd(struct property *new_prop)
{
struct nx842_devdata *old_devdata = NULL;
struct nx842_devdata *new_devdata = NULL;
struct device_node *of_node = NULL;
struct property *status = NULL;
struct property *maxsglen = NULL;
struct property *maxsyncop = NULL;
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
if (old_devdata)
of_node = old_devdata->dev->of_node;
if (!old_devdata || !of_node) {
pr_err("%s: device is not available\n", __func__);
spin_unlock_irqrestore(&devdata_mutex, flags);
return -ENODEV;
}
new_devdata = kzalloc(sizeof(*new_devdata), GFP_NOFS);
if (!new_devdata) {
dev_err(old_devdata->dev, "%s: Could not allocate memory for device data\n", __func__);
ret = -ENOMEM;
goto error_out;
}
memcpy(new_devdata, old_devdata, sizeof(*old_devdata));
new_devdata->counters = old_devdata->counters;
status = of_find_property(of_node, "status", NULL);
maxsglen = of_find_property(of_node, "ibm,max-sg-len", NULL);
maxsyncop = of_find_property(of_node, "ibm,max-sync-cop", NULL);
if (!status || !maxsglen || !maxsyncop) {
dev_err(old_devdata->dev, "%s: Could not locate device properties\n", __func__);
ret = -EINVAL;
goto error_out;
}
if (new_prop) {
if (!strncmp(new_prop->name, "status", new_prop->length)) {
status = new_prop;
} else if (!strncmp(new_prop->name, "ibm,max-sg-len",
new_prop->length)) {
maxsglen = new_prop;
} else if (!strncmp(new_prop->name, "ibm,max-sync-cop",
new_prop->length)) {
maxsyncop = new_prop;
} else {
goto out;
}
}
ret = nx842_OF_upd_status(new_devdata, status);
if (ret)
goto error_out;
ret = nx842_OF_upd_maxsglen(new_devdata, maxsglen);
if (ret)
goto error_out;
ret = nx842_OF_upd_maxsyncop(new_devdata, maxsyncop);
if (ret)
goto error_out;
out:
dev_info(old_devdata->dev, "%s: max_sync_size new:%u old:%u\n",
__func__, new_devdata->max_sync_size,
old_devdata->max_sync_size);
dev_info(old_devdata->dev, "%s: max_sync_sg new:%u old:%u\n",
__func__, new_devdata->max_sync_sg,
old_devdata->max_sync_sg);
dev_info(old_devdata->dev, "%s: max_sg_len new:%u old:%u\n",
__func__, new_devdata->max_sg_len,
old_devdata->max_sg_len);
rcu_assign_pointer(devdata, new_devdata);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
dev_set_drvdata(new_devdata->dev, new_devdata);
kfree(old_devdata);
return 0;
error_out:
if (new_devdata) {
dev_info(old_devdata->dev, "%s: device disabled\n", __func__);
nx842_OF_set_defaults(new_devdata);
rcu_assign_pointer(devdata, new_devdata);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
dev_set_drvdata(new_devdata->dev, new_devdata);
kfree(old_devdata);
} else {
dev_err(old_devdata->dev, "%s: could not update driver from hardware\n", __func__);
spin_unlock_irqrestore(&devdata_mutex, flags);
}
if (!ret)
ret = -EINVAL;
return ret;
}
static int nx842_OF_notifier(struct notifier_block *np, unsigned long action,
void *update)
{
struct of_prop_reconfig *upd = update;
struct nx842_devdata *local_devdata;
struct device_node *node = NULL;
rcu_read_lock();
local_devdata = rcu_dereference(devdata);
if (local_devdata)
node = local_devdata->dev->of_node;
if (local_devdata &&
action == OF_RECONFIG_UPDATE_PROPERTY &&
!strcmp(upd->dn->name, node->name)) {
rcu_read_unlock();
nx842_OF_upd(upd->prop);
} else
rcu_read_unlock();
return NOTIFY_OK;
}
static ssize_t nx842_timehist_show(struct device *dev,
struct device_attribute *attr, char *buf) {
char *p = buf;
struct nx842_devdata *local_devdata;
atomic64_t *times;
int bytes_remain = PAGE_SIZE;
int bytes;
int i;
rcu_read_lock();
local_devdata = rcu_dereference(devdata);
if (!local_devdata) {
rcu_read_unlock();
return 0;
}
if (attr == &dev_attr_comp_times)
times = local_devdata->counters->comp_times;
else if (attr == &dev_attr_decomp_times)
times = local_devdata->counters->decomp_times;
else {
rcu_read_unlock();
return 0;
}
for (i = 0; i < (NX842_HIST_SLOTS - 2); i++) {
bytes = snprintf(p, bytes_remain, "%u-%uus:\t%ld\n",
i ? (2<<(i-1)) : 0, (2<<i)-1,
atomic64_read(&times[i]));
bytes_remain -= bytes;
p += bytes;
}
bytes = snprintf(p, bytes_remain, "%uus - :\t%ld\n",
2<<(NX842_HIST_SLOTS - 2),
atomic64_read(&times[(NX842_HIST_SLOTS - 1)]));
p += bytes;
rcu_read_unlock();
return p - buf;
}
static int __init nx842_probe(struct vio_dev *viodev,
const struct vio_device_id *id)
{
struct nx842_devdata *old_devdata, *new_devdata = NULL;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
if (old_devdata && old_devdata->vdev != NULL) {
dev_err(&viodev->dev, "%s: Attempt to register more than one instance of the hardware\n", __func__);
ret = -1;
goto error_unlock;
}
dev_set_drvdata(&viodev->dev, NULL);
new_devdata = kzalloc(sizeof(*new_devdata), GFP_NOFS);
if (!new_devdata) {
dev_err(&viodev->dev, "%s: Could not allocate memory for device data\n", __func__);
ret = -ENOMEM;
goto error_unlock;
}
new_devdata->counters = kzalloc(sizeof(*new_devdata->counters),
GFP_NOFS);
if (!new_devdata->counters) {
dev_err(&viodev->dev, "%s: Could not allocate memory for performance counters\n", __func__);
ret = -ENOMEM;
goto error_unlock;
}
new_devdata->vdev = viodev;
new_devdata->dev = &viodev->dev;
nx842_OF_set_defaults(new_devdata);
rcu_assign_pointer(devdata, new_devdata);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
kfree(old_devdata);
of_reconfig_notifier_register(&nx842_of_nb);
ret = nx842_OF_upd(NULL);
if (ret && ret != -ENODEV) {
dev_err(&viodev->dev, "could not parse device tree. %d\n", ret);
ret = -1;
goto error;
}
rcu_read_lock();
if (dev_set_drvdata(&viodev->dev, rcu_dereference(devdata))) {
rcu_read_unlock();
dev_err(&viodev->dev, "failed to set driver data for device\n");
ret = -1;
goto error;
}
rcu_read_unlock();
if (sysfs_create_group(&viodev->dev.kobj, &nx842_attribute_group)) {
dev_err(&viodev->dev, "could not create sysfs device attributes\n");
ret = -1;
goto error;
}
return 0;
error_unlock:
spin_unlock_irqrestore(&devdata_mutex, flags);
if (new_devdata)
kfree(new_devdata->counters);
kfree(new_devdata);
error:
return ret;
}
static int __exit nx842_remove(struct vio_dev *viodev)
{
struct nx842_devdata *old_devdata;
unsigned long flags;
pr_info("Removing IBM Power 842 compression device\n");
sysfs_remove_group(&viodev->dev.kobj, &nx842_attribute_group);
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
of_reconfig_notifier_unregister(&nx842_of_nb);
rcu_assign_pointer(devdata, NULL);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
dev_set_drvdata(&viodev->dev, NULL);
if (old_devdata)
kfree(old_devdata->counters);
kfree(old_devdata);
return 0;
}
static int __init nx842_init(void)
{
struct nx842_devdata *new_devdata;
pr_info("Registering IBM Power 842 compression driver\n");
RCU_INIT_POINTER(devdata, NULL);
new_devdata = kzalloc(sizeof(*new_devdata), GFP_KERNEL);
if (!new_devdata) {
pr_err("Could not allocate memory for device data\n");
return -ENOMEM;
}
new_devdata->status = UNAVAILABLE;
RCU_INIT_POINTER(devdata, new_devdata);
return vio_register_driver(&nx842_driver);
}
static void __exit nx842_exit(void)
{
struct nx842_devdata *old_devdata;
unsigned long flags;
pr_info("Exiting IBM Power 842 compression driver\n");
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
rcu_assign_pointer(devdata, NULL);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
if (old_devdata)
dev_set_drvdata(old_devdata->dev, NULL);
kfree(old_devdata);
vio_unregister_driver(&nx842_driver);
}
static uint8_t sw842_get_byte(const char *buf, int bit)
{
uint8_t tmpl;
uint16_t tmp;
tmp = htons(*(uint16_t *)(buf));
tmp = (uint16_t)(tmp << bit);
tmp = ntohs(tmp);
memcpy(&tmpl, &tmp, 1);
return tmpl;
}
static uint8_t sw842_get_template(const char **buf, int *bit)
{
uint8_t byte;
byte = sw842_get_byte(*buf, *bit);
byte = byte >> 3;
byte &= 0x1F;
*buf += (*bit + 5) / 8;
*bit = (*bit + 5) % 8;
return byte;
}
static uint8_t sw842_get_repeat_count(const char **buf, int *bit)
{
uint8_t byte;
byte = sw842_get_byte(*buf, *bit);
byte = byte >> 2;
byte &= 0x3F;
*buf += (*bit + 6) / 8;
*bit = (*bit + 6) % 8;
return byte;
}
static uint8_t sw842_get_ptr2(const char **buf, int *bit)
{
uint8_t ptr;
ptr = sw842_get_byte(*buf, *bit);
(*buf)++;
return ptr;
}
static uint16_t sw842_get_ptr4(const char **buf, int *bit,
struct sw842_fifo *fifo)
{
uint16_t ptr;
ptr = htons(*(uint16_t *)(*buf));
ptr = (uint16_t)(ptr << *bit);
ptr = ptr >> 7;
ptr &= 0x01FF;
*buf += (*bit + 9) / 8;
*bit = (*bit + 9) % 8;
return ptr;
}
static uint8_t sw842_get_ptr8(const char **buf, int *bit,
struct sw842_fifo *fifo)
{
return sw842_get_ptr2(buf, bit);
}
static int sw842_data8(const char **inbuf, int *inbit,
unsigned char **outbuf, struct sw842_fifo *fifo)
{
int ret;
ret = sw842_data4(inbuf, inbit, outbuf, fifo);
if (ret)
return ret;
ret = sw842_data4(inbuf, inbit, outbuf, fifo);
return ret;
}
static int sw842_data4(const char **inbuf, int *inbit,
unsigned char **outbuf, struct sw842_fifo *fifo)
{
int ret;
ret = sw842_data2(inbuf, inbit, outbuf, fifo);
if (ret)
return ret;
ret = sw842_data2(inbuf, inbit, outbuf, fifo);
return ret;
}
static int sw842_data2(const char **inbuf, int *inbit,
unsigned char **outbuf, struct sw842_fifo *fifo)
{
**outbuf = sw842_get_byte(*inbuf, *inbit);
(*inbuf)++;
(*outbuf)++;
**outbuf = sw842_get_byte(*inbuf, *inbit);
(*inbuf)++;
(*outbuf)++;
return 0;
}
static int sw842_ptr8(const char **inbuf, int *inbit,
unsigned char **outbuf, struct sw842_fifo *fifo)
{
uint8_t ptr;
ptr = sw842_get_ptr8(inbuf, inbit, fifo);
if (!fifo->f84_full && (ptr >= fifo->f8_count))
return 1;
memcpy(*outbuf, fifo->f8[ptr], 8);
*outbuf += 8;
return 0;
}
static int sw842_ptr4(const char **inbuf, int *inbit,
unsigned char **outbuf, struct sw842_fifo *fifo)
{
uint16_t ptr;
ptr = sw842_get_ptr4(inbuf, inbit, fifo);
if (!fifo->f84_full && (ptr >= fifo->f4_count))
return 1;
memcpy(*outbuf, fifo->f4[ptr], 4);
*outbuf += 4;
return 0;
}
static int sw842_ptr2(const char **inbuf, int *inbit,
unsigned char **outbuf, struct sw842_fifo *fifo)
{
uint8_t ptr;
ptr = sw842_get_ptr2(inbuf, inbit);
if (!fifo->f2_full && (ptr >= fifo->f2_count))
return 1;
memcpy(*outbuf, fifo->f2[ptr], 2);
*outbuf += 2;
return 0;
}
static void sw842_copy_to_fifo(const char *buf, struct sw842_fifo *fifo)
{
unsigned char initial_f2count = fifo->f2_count;
memcpy(fifo->f8[fifo->f8_count], buf, 8);
fifo->f4_count += 2;
fifo->f8_count += 1;
if (!fifo->f84_full && fifo->f4_count >= 512) {
fifo->f84_full = 1;
fifo->f4_count /= 512;
}
memcpy(fifo->f2[fifo->f2_count++], buf, 2);
memcpy(fifo->f2[fifo->f2_count++], buf + 2, 2);
memcpy(fifo->f2[fifo->f2_count++], buf + 4, 2);
memcpy(fifo->f2[fifo->f2_count++], buf + 6, 2);
if (fifo->f2_count < initial_f2count)
fifo->f2_full = 1;
}
static int sw842_decompress(const unsigned char *src, int srclen,
unsigned char *dst, int *destlen,
const void *wrkmem)
{
uint8_t tmpl;
const char *inbuf;
int inbit = 0;
unsigned char *outbuf, *outbuf_end, *origbuf, *prevbuf;
const char *inbuf_end;
sw842_template_op op;
int opindex;
int i, repeat_count;
struct sw842_fifo *fifo;
int ret = 0;
fifo = &((struct nx842_workmem *)(wrkmem))->swfifo;
memset(fifo, 0, sizeof(*fifo));
origbuf = NULL;
inbuf = src;
inbuf_end = src + srclen;
outbuf = dst;
outbuf_end = dst + *destlen;
while ((tmpl = sw842_get_template(&inbuf, &inbit)) != SW842_TMPL_EOF) {
if (inbuf >= inbuf_end) {
ret = -EINVAL;
goto out;
}
opindex = 0;
prevbuf = origbuf;
origbuf = outbuf;
switch (tmpl) {
case SW842_TMPL_REPEAT:
if (prevbuf == NULL) {
ret = -EINVAL;
goto out;
}
repeat_count = sw842_get_repeat_count(&inbuf,
&inbit) + 1;
if (inbuf > inbuf_end) {
ret = -EINVAL;
goto out;
}
for (i = 0; i < repeat_count; i++) {
if ((outbuf + 8) > outbuf_end) {
ret = -ENOSPC;
goto out;
}
memcpy(outbuf, prevbuf, 8);
sw842_copy_to_fifo(outbuf, fifo);
outbuf += 8;
}
break;
case SW842_TMPL_ZEROS:
if ((outbuf + 8) > outbuf_end) {
ret = -ENOSPC;
goto out;
}
memset(outbuf, 0, 8);
sw842_copy_to_fifo(outbuf, fifo);
outbuf += 8;
break;
default:
if (tmpl > 25) {
ret = -EINVAL;
goto out;
}
if ((inbuf + 2) > inbuf_end) {
ret = -EINVAL;
goto out;
}
if ((outbuf + 8) > outbuf_end) {
ret = -ENOSPC;
goto out;
}
while (opindex < 4 &&
(op = sw842_tmpl_ops[tmpl][opindex++])
!= NULL) {
ret = (*op)(&inbuf, &inbit, &outbuf, fifo);
if (ret) {
ret = -EINVAL;
goto out;
}
sw842_copy_to_fifo(origbuf, fifo);
}
}
}
out:
if (!ret)
*destlen = (unsigned int)(outbuf - dst);
else
*destlen = 0;
return ret;
}
