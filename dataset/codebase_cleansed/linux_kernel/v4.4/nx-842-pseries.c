static int check_constraints(unsigned long buf, unsigned int *len, bool in)
{
if (!IS_ALIGNED(buf, nx842_pseries_constraints.alignment)) {
pr_debug("%s buffer 0x%lx not aligned to 0x%x\n",
in ? "input" : "output", buf,
nx842_pseries_constraints.alignment);
return -EINVAL;
}
if (*len % nx842_pseries_constraints.multiple) {
pr_debug("%s buffer len 0x%x not multiple of 0x%x\n",
in ? "input" : "output", *len,
nx842_pseries_constraints.multiple);
if (in)
return -EINVAL;
*len = round_down(*len, nx842_pseries_constraints.multiple);
}
if (*len < nx842_pseries_constraints.minimum) {
pr_debug("%s buffer len 0x%x under minimum 0x%x\n",
in ? "input" : "output", *len,
nx842_pseries_constraints.minimum);
return -EINVAL;
}
if (*len > nx842_pseries_constraints.maximum) {
pr_debug("%s buffer len 0x%x over maximum 0x%x\n",
in ? "input" : "output", *len,
nx842_pseries_constraints.maximum);
if (in)
return -EINVAL;
*len = nx842_pseries_constraints.maximum;
}
return 0;
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
static int nx842_build_scatterlist(unsigned long buf, int len,
struct nx842_scatterlist *sl)
{
unsigned long entrylen;
struct nx842_slentry *entry;
sl->entry_nr = 0;
entry = sl->entries;
while (len) {
entry->ptr = cpu_to_be64(nx842_get_pa((void *)buf));
entrylen = min_t(int, len,
LEN_ON_SIZE(buf, NX842_HW_PAGE_SIZE));
entry->len = cpu_to_be64(entrylen);
len -= entrylen;
buf += entrylen;
sl->entry_nr++;
entry++;
}
return 0;
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
be32_to_cpu(csb->processed_byte_count),
(unsigned long)be64_to_cpu(csb->address));
return -EIO;
}
switch (csb->completion_code) {
case 0:
break;
case 64:
dev_dbg(dev, "%s: output size larger than input size\n",
__func__);
break;
case 13:
dev_dbg(dev, "%s: Out of space in output buffer\n",
__func__);
return -ENOSPC;
case 65:
dev_dbg(dev, "%s: CRC mismatch for decompression\n",
__func__);
return -EINVAL;
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
static int nx842_pseries_compress(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlen,
void *wmem)
{
struct nx842_devdata *local_devdata;
struct device *dev = NULL;
struct nx842_workmem *workmem;
struct nx842_scatterlist slin, slout;
struct nx_csbcpb *csbcpb;
int ret = 0, max_sync_size;
unsigned long inbuf, outbuf;
struct vio_pfo_op op = {
.done = NULL,
.handle = 0,
.timeout = 0,
};
unsigned long start = get_tb();
inbuf = (unsigned long)in;
if (check_constraints(inbuf, &inlen, true))
return -EINVAL;
outbuf = (unsigned long)out;
if (check_constraints(outbuf, outlen, false))
return -EINVAL;
rcu_read_lock();
local_devdata = rcu_dereference(devdata);
if (!local_devdata || !local_devdata->dev) {
rcu_read_unlock();
return -ENODEV;
}
max_sync_size = local_devdata->max_sync_size;
dev = local_devdata->dev;
workmem = PTR_ALIGN(wmem, WORKMEM_ALIGN);
slin.entries = (struct nx842_slentry *)workmem->slin;
slout.entries = (struct nx842_slentry *)workmem->slout;
op.flags = NX842_OP_COMPRESS_CRC;
csbcpb = &workmem->csbcpb;
memset(csbcpb, 0, sizeof(*csbcpb));
op.csbcpb = nx842_get_pa(csbcpb);
if ((inbuf & NX842_HW_PAGE_MASK) ==
((inbuf + inlen - 1) & NX842_HW_PAGE_MASK)) {
op.in = nx842_get_pa((void *)inbuf);
op.inlen = inlen;
} else {
nx842_build_scatterlist(inbuf, inlen, &slin);
op.in = nx842_get_pa(slin.entries);
op.inlen = -nx842_get_scatterlist_size(&slin);
}
if ((outbuf & NX842_HW_PAGE_MASK) ==
((outbuf + *outlen - 1) & NX842_HW_PAGE_MASK)) {
op.out = nx842_get_pa((void *)outbuf);
op.outlen = *outlen;
} else {
nx842_build_scatterlist(outbuf, *outlen, &slout);
op.out = nx842_get_pa(slout.entries);
op.outlen = -nx842_get_scatterlist_size(&slout);
}
dev_dbg(dev, "%s: op.in %lx op.inlen %ld op.out %lx op.outlen %ld\n",
__func__, (unsigned long)op.in, (long)op.inlen,
(unsigned long)op.out, (long)op.outlen);
ret = vio_h_cop_sync(local_devdata->vdev, &op);
if (ret) {
dev_dbg(dev, "%s: vio_h_cop_sync error (ret=%d, hret=%ld)\n",
__func__, ret, op.hcall_err);
ret = -EIO;
goto unlock;
}
ret = nx842_validate_result(dev, &csbcpb->csb);
if (ret)
goto unlock;
*outlen = be32_to_cpu(csbcpb->csb.processed_byte_count);
dev_dbg(dev, "%s: processed_bytes=%d\n", __func__, *outlen);
unlock:
if (ret)
nx842_inc_comp_failed(local_devdata);
else {
nx842_inc_comp_complete(local_devdata);
ibm_nx842_incr_hist(local_devdata->counters->comp_times,
(get_tb() - start) / tb_ticks_per_usec);
}
rcu_read_unlock();
return ret;
}
static int nx842_pseries_decompress(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlen,
void *wmem)
{
struct nx842_devdata *local_devdata;
struct device *dev = NULL;
struct nx842_workmem *workmem;
struct nx842_scatterlist slin, slout;
struct nx_csbcpb *csbcpb;
int ret = 0, max_sync_size;
unsigned long inbuf, outbuf;
struct vio_pfo_op op = {
.done = NULL,
.handle = 0,
.timeout = 0,
};
unsigned long start = get_tb();
inbuf = (unsigned long)in;
if (check_constraints(inbuf, &inlen, true))
return -EINVAL;
outbuf = (unsigned long)out;
if (check_constraints(outbuf, outlen, false))
return -EINVAL;
rcu_read_lock();
local_devdata = rcu_dereference(devdata);
if (!local_devdata || !local_devdata->dev) {
rcu_read_unlock();
return -ENODEV;
}
max_sync_size = local_devdata->max_sync_size;
dev = local_devdata->dev;
workmem = PTR_ALIGN(wmem, WORKMEM_ALIGN);
slin.entries = (struct nx842_slentry *)workmem->slin;
slout.entries = (struct nx842_slentry *)workmem->slout;
op.flags = NX842_OP_DECOMPRESS_CRC;
csbcpb = &workmem->csbcpb;
memset(csbcpb, 0, sizeof(*csbcpb));
op.csbcpb = nx842_get_pa(csbcpb);
if ((inbuf & NX842_HW_PAGE_MASK) ==
((inbuf + inlen - 1) & NX842_HW_PAGE_MASK)) {
op.in = nx842_get_pa((void *)inbuf);
op.inlen = inlen;
} else {
nx842_build_scatterlist(inbuf, inlen, &slin);
op.in = nx842_get_pa(slin.entries);
op.inlen = -nx842_get_scatterlist_size(&slin);
}
if ((outbuf & NX842_HW_PAGE_MASK) ==
((outbuf + *outlen - 1) & NX842_HW_PAGE_MASK)) {
op.out = nx842_get_pa((void *)outbuf);
op.outlen = *outlen;
} else {
nx842_build_scatterlist(outbuf, *outlen, &slout);
op.out = nx842_get_pa(slout.entries);
op.outlen = -nx842_get_scatterlist_size(&slout);
}
dev_dbg(dev, "%s: op.in %lx op.inlen %ld op.out %lx op.outlen %ld\n",
__func__, (unsigned long)op.in, (long)op.inlen,
(unsigned long)op.out, (long)op.outlen);
ret = vio_h_cop_sync(local_devdata->vdev, &op);
if (ret) {
dev_dbg(dev, "%s: vio_h_cop_sync error (ret=%d, hret=%ld)\n",
__func__, ret, op.hcall_err);
goto unlock;
}
ret = nx842_validate_result(dev, &csbcpb->csb);
if (ret)
goto unlock;
*outlen = be32_to_cpu(csbcpb->csb.processed_byte_count);
unlock:
if (ret)
nx842_inc_decomp_failed(local_devdata);
else {
nx842_inc_decomp_complete(local_devdata);
ibm_nx842_incr_hist(local_devdata->counters->decomp_times,
(get_tb() - start) / tb_ticks_per_usec);
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
return 0;
} else
return -ENOENT;
}
static int nx842_OF_upd_status(struct property *prop)
{
const char *status = (const char *)prop->value;
if (!strncmp(status, "okay", (size_t)prop->length))
return 0;
if (!strncmp(status, "disabled", (size_t)prop->length))
return -ENODEV;
dev_info(devdata->dev, "%s: unknown status '%s'\n", __func__, status);
return -EINVAL;
}
static int nx842_OF_upd_maxsglen(struct nx842_devdata *devdata,
struct property *prop) {
int ret = 0;
const unsigned int maxsglen = of_read_number(prop->value, 1);
if (prop->length != sizeof(maxsglen)) {
dev_err(devdata->dev, "%s: unexpected format for ibm,max-sg-len property\n", __func__);
dev_dbg(devdata->dev, "%s: ibm,max-sg-len is %d bytes long, expected %lu bytes\n", __func__,
prop->length, sizeof(maxsglen));
ret = -EINVAL;
} else {
devdata->max_sg_len = min_t(unsigned int,
maxsglen, NX842_HW_PAGE_SIZE);
}
return ret;
}
static int nx842_OF_upd_maxsyncop(struct nx842_devdata *devdata,
struct property *prop) {
int ret = 0;
unsigned int comp_data_limit, decomp_data_limit;
unsigned int comp_sg_limit, decomp_sg_limit;
const struct maxsynccop_t {
__be32 comp_elements;
__be32 comp_data_limit;
__be32 comp_sg_limit;
__be32 decomp_elements;
__be32 decomp_data_limit;
__be32 decomp_sg_limit;
} *maxsynccop;
if (prop->length != sizeof(*maxsynccop)) {
dev_err(devdata->dev, "%s: unexpected format for ibm,max-sync-cop property\n", __func__);
dev_dbg(devdata->dev, "%s: ibm,max-sync-cop is %d bytes long, expected %lu bytes\n", __func__, prop->length,
sizeof(*maxsynccop));
ret = -EINVAL;
goto out;
}
maxsynccop = (const struct maxsynccop_t *)prop->value;
comp_data_limit = be32_to_cpu(maxsynccop->comp_data_limit);
comp_sg_limit = be32_to_cpu(maxsynccop->comp_sg_limit);
decomp_data_limit = be32_to_cpu(maxsynccop->decomp_data_limit);
decomp_sg_limit = be32_to_cpu(maxsynccop->decomp_sg_limit);
devdata->max_sync_size = min(comp_data_limit, decomp_data_limit);
devdata->max_sync_size = min_t(unsigned int, devdata->max_sync_size,
65536);
if (devdata->max_sync_size < 4096) {
dev_err(devdata->dev, "%s: hardware max data size (%u) is "
"less than the driver minimum, unable to use "
"the hardware device\n",
__func__, devdata->max_sync_size);
ret = -EINVAL;
goto out;
}
nx842_pseries_constraints.maximum = devdata->max_sync_size;
devdata->max_sync_sg = min(comp_sg_limit, decomp_sg_limit);
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
new_devdata = kzalloc(sizeof(*new_devdata), GFP_NOFS);
if (!new_devdata)
return -ENOMEM;
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
if (old_devdata)
of_node = old_devdata->dev->of_node;
if (!old_devdata || !of_node) {
pr_err("%s: device is not available\n", __func__);
spin_unlock_irqrestore(&devdata_mutex, flags);
kfree(new_devdata);
return -ENODEV;
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
if (new_prop && (strncmp(new_prop->name, "status", new_prop->length) ||
strncmp(new_prop->name, "ibm,max-sg-len", new_prop->length) ||
strncmp(new_prop->name, "ibm,max-sync-cop", new_prop->length)))
goto out;
ret = nx842_OF_upd_status(status);
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
void *data)
{
struct of_reconfig_data *upd = data;
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
static int nx842_pseries_crypto_init(struct crypto_tfm *tfm)
{
return nx842_crypto_init(tfm, &nx842_pseries_driver);
}
static int nx842_probe(struct vio_dev *viodev,
const struct vio_device_id *id)
{
struct nx842_devdata *old_devdata, *new_devdata = NULL;
unsigned long flags;
int ret = 0;
new_devdata = kzalloc(sizeof(*new_devdata), GFP_NOFS);
if (!new_devdata)
return -ENOMEM;
new_devdata->counters = kzalloc(sizeof(*new_devdata->counters),
GFP_NOFS);
if (!new_devdata->counters) {
kfree(new_devdata);
return -ENOMEM;
}
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
if (old_devdata && old_devdata->vdev != NULL) {
dev_err(&viodev->dev, "%s: Attempt to register more than one instance of the hardware\n", __func__);
ret = -1;
goto error_unlock;
}
dev_set_drvdata(&viodev->dev, NULL);
new_devdata->vdev = viodev;
new_devdata->dev = &viodev->dev;
nx842_OF_set_defaults(new_devdata);
rcu_assign_pointer(devdata, new_devdata);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
kfree(old_devdata);
of_reconfig_notifier_register(&nx842_of_nb);
ret = nx842_OF_upd(NULL);
if (ret)
goto error;
ret = crypto_register_alg(&nx842_pseries_alg);
if (ret) {
dev_err(&viodev->dev, "could not register comp alg: %d\n", ret);
goto error;
}
rcu_read_lock();
dev_set_drvdata(&viodev->dev, rcu_dereference(devdata));
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
static int nx842_remove(struct vio_dev *viodev)
{
struct nx842_devdata *old_devdata;
unsigned long flags;
pr_info("Removing IBM Power 842 compression device\n");
sysfs_remove_group(&viodev->dev.kobj, &nx842_attribute_group);
crypto_unregister_alg(&nx842_pseries_alg);
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
of_reconfig_notifier_unregister(&nx842_of_nb);
RCU_INIT_POINTER(devdata, NULL);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
dev_set_drvdata(&viodev->dev, NULL);
if (old_devdata)
kfree(old_devdata->counters);
kfree(old_devdata);
return 0;
}
static int __init nx842_pseries_init(void)
{
struct nx842_devdata *new_devdata;
int ret;
if (!of_find_compatible_node(NULL, NULL, "ibm,compression"))
return -ENODEV;
RCU_INIT_POINTER(devdata, NULL);
new_devdata = kzalloc(sizeof(*new_devdata), GFP_KERNEL);
if (!new_devdata) {
pr_err("Could not allocate memory for device data\n");
return -ENOMEM;
}
RCU_INIT_POINTER(devdata, new_devdata);
ret = vio_register_driver(&nx842_vio_driver);
if (ret) {
pr_err("Could not register VIO driver %d\n", ret);
kfree(new_devdata);
return ret;
}
return 0;
}
static void __exit nx842_pseries_exit(void)
{
struct nx842_devdata *old_devdata;
unsigned long flags;
crypto_unregister_alg(&nx842_pseries_alg);
spin_lock_irqsave(&devdata_mutex, flags);
old_devdata = rcu_dereference_check(devdata,
lockdep_is_held(&devdata_mutex));
RCU_INIT_POINTER(devdata, NULL);
spin_unlock_irqrestore(&devdata_mutex, flags);
synchronize_rcu();
if (old_devdata && old_devdata->dev)
dev_set_drvdata(old_devdata->dev, NULL);
kfree(old_devdata);
vio_unregister_driver(&nx842_vio_driver);
}
