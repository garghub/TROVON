static int ramoops_pstore_open(struct pstore_info *psi)
{
struct ramoops_context *cxt = psi->data;
cxt->read_count = 0;
return 0;
}
static ssize_t ramoops_pstore_read(u64 *id, enum pstore_type_id *type,
struct timespec *time,
char **buf,
struct pstore_info *psi)
{
ssize_t size;
struct ramoops_context *cxt = psi->data;
struct persistent_ram_zone *prz;
if (cxt->read_count >= cxt->max_count)
return -EINVAL;
*id = cxt->read_count++;
prz = cxt->przs[*id];
*type = PSTORE_TYPE_DMESG;
time->tv_sec = 0;
time->tv_nsec = 0;
persistent_ram_save_old(prz);
size = persistent_ram_old_size(prz);
*buf = kmalloc(size, GFP_KERNEL);
if (*buf == NULL)
return -ENOMEM;
memcpy(*buf, persistent_ram_old(prz), size);
return size;
}
static size_t ramoops_write_kmsg_hdr(struct persistent_ram_zone *prz)
{
char *hdr;
struct timeval timestamp;
size_t len;
do_gettimeofday(&timestamp);
hdr = kasprintf(GFP_ATOMIC, RAMOOPS_KERNMSG_HDR "%lu.%lu\n",
(long)timestamp.tv_sec, (long)timestamp.tv_usec);
WARN_ON_ONCE(!hdr);
len = hdr ? strlen(hdr) : 0;
persistent_ram_write(prz, hdr, len);
kfree(hdr);
return len;
}
static int ramoops_pstore_write(enum pstore_type_id type,
enum kmsg_dump_reason reason,
u64 *id,
unsigned int part,
size_t size, struct pstore_info *psi)
{
struct ramoops_context *cxt = psi->data;
struct persistent_ram_zone *prz = cxt->przs[cxt->count];
size_t hlen;
if (type != PSTORE_TYPE_DMESG)
return -EINVAL;
if (reason != KMSG_DUMP_OOPS &&
reason != KMSG_DUMP_PANIC)
return -EINVAL;
if (reason == KMSG_DUMP_OOPS && !cxt->dump_oops)
return -EINVAL;
if (part != 1)
return -ENOSPC;
hlen = ramoops_write_kmsg_hdr(prz);
if (size + hlen > prz->buffer_size)
size = prz->buffer_size - hlen;
persistent_ram_write(prz, cxt->pstore.buf, size);
cxt->count = (cxt->count + 1) % cxt->max_count;
return 0;
}
static int ramoops_pstore_erase(enum pstore_type_id type, u64 id,
struct pstore_info *psi)
{
struct ramoops_context *cxt = psi->data;
if (id >= cxt->max_count)
return -EINVAL;
persistent_ram_free_old(cxt->przs[id]);
persistent_ram_zap(cxt->przs[id]);
return 0;
}
static int __init ramoops_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ramoops_platform_data *pdata = pdev->dev.platform_data;
struct ramoops_context *cxt = &oops_cxt;
int err = -EINVAL;
int i;
if (cxt->max_count)
goto fail_out;
if (!pdata->mem_size || !pdata->record_size) {
pr_err("The memory size and the record size must be "
"non-zero\n");
goto fail_out;
}
pdata->mem_size = rounddown_pow_of_two(pdata->mem_size);
pdata->record_size = rounddown_pow_of_two(pdata->record_size);
if (pdata->mem_size < MIN_MEM_SIZE &&
pdata->record_size < MIN_MEM_SIZE) {
pr_err("memory size too small, minimum is %lu\n",
MIN_MEM_SIZE);
goto fail_out;
}
if (pdata->mem_size < pdata->record_size) {
pr_err("The memory size must be larger than the "
"records size\n");
goto fail_out;
}
cxt->max_count = pdata->mem_size / pdata->record_size;
cxt->count = 0;
cxt->size = pdata->mem_size;
cxt->phys_addr = pdata->mem_address;
cxt->record_size = pdata->record_size;
cxt->dump_oops = pdata->dump_oops;
cxt->ecc = pdata->ecc;
cxt->przs = kzalloc(sizeof(*cxt->przs) * cxt->max_count, GFP_KERNEL);
if (!cxt->przs) {
err = -ENOMEM;
dev_err(dev, "failed to initialize a prz array\n");
goto fail_out;
}
for (i = 0; i < cxt->max_count; i++) {
size_t sz = cxt->record_size;
phys_addr_t start = cxt->phys_addr + sz * i;
cxt->przs[i] = persistent_ram_new(start, sz, cxt->ecc);
if (IS_ERR(cxt->przs[i])) {
err = PTR_ERR(cxt->przs[i]);
dev_err(dev, "failed to request mem region (0x%zx@0x%llx): %d\n",
sz, (unsigned long long)start, err);
goto fail_przs;
}
}
cxt->pstore.data = cxt;
cxt->pstore.bufsize = cxt->przs[0]->buffer_size;
cxt->pstore.buf = kmalloc(cxt->pstore.bufsize, GFP_KERNEL);
spin_lock_init(&cxt->pstore.buf_lock);
if (!cxt->pstore.buf) {
pr_err("cannot allocate pstore buffer\n");
goto fail_clear;
}
err = pstore_register(&cxt->pstore);
if (err) {
pr_err("registering with pstore failed\n");
goto fail_buf;
}
mem_size = pdata->mem_size;
mem_address = pdata->mem_address;
record_size = pdata->record_size;
dump_oops = pdata->dump_oops;
pr_info("attached 0x%lx@0x%llx (%ux0x%zx), ecc: %s\n",
cxt->size, (unsigned long long)cxt->phys_addr,
cxt->max_count, cxt->record_size,
ramoops_ecc ? "on" : "off");
return 0;
fail_buf:
kfree(cxt->pstore.buf);
fail_clear:
cxt->pstore.bufsize = 0;
cxt->max_count = 0;
fail_przs:
for (i = 0; cxt->przs[i]; i++)
persistent_ram_free(cxt->przs[i]);
kfree(cxt->przs);
fail_out:
return err;
}
static int __exit ramoops_remove(struct platform_device *pdev)
{
#if 0
struct ramoops_context *cxt = &oops_cxt;
iounmap(cxt->virt_addr);
release_mem_region(cxt->phys_addr, cxt->size);
cxt->max_count = 0;
kfree(cxt->pstore.buf);
cxt->pstore.bufsize = 0;
return 0;
#endif
return -EBUSY;
}
static int __init ramoops_init(void)
{
int ret;
ret = platform_driver_probe(&ramoops_driver, ramoops_probe);
if (ret == -ENODEV) {
pr_info("platform device not found, using module parameters\n");
dummy_data = kzalloc(sizeof(struct ramoops_platform_data),
GFP_KERNEL);
if (!dummy_data)
return -ENOMEM;
dummy_data->mem_size = mem_size;
dummy_data->mem_address = mem_address;
dummy_data->record_size = record_size;
dummy_data->dump_oops = dump_oops;
dummy_data->ecc = ramoops_ecc;
dummy = platform_create_bundle(&ramoops_driver, ramoops_probe,
NULL, 0, dummy_data,
sizeof(struct ramoops_platform_data));
if (IS_ERR(dummy))
ret = PTR_ERR(dummy);
else
ret = 0;
}
return ret;
}
static void __exit ramoops_exit(void)
{
platform_driver_unregister(&ramoops_driver);
kfree(dummy_data);
}
