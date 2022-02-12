static int ramoops_pstore_open(struct pstore_info *psi)
{
struct ramoops_context *cxt = psi->data;
cxt->dump_read_cnt = 0;
cxt->console_read_cnt = 0;
return 0;
}
static struct persistent_ram_zone *
ramoops_get_next_prz(struct persistent_ram_zone *przs[], uint *c, uint max,
u64 *id,
enum pstore_type_id *typep, enum pstore_type_id type,
bool update)
{
struct persistent_ram_zone *prz;
int i = (*c)++;
if (i >= max)
return NULL;
prz = przs[i];
if (update) {
persistent_ram_save_old(prz);
if (!persistent_ram_old_size(prz))
return NULL;
}
*typep = type;
*id = i;
return prz;
}
static ssize_t ramoops_pstore_read(u64 *id, enum pstore_type_id *type,
int *count, struct timespec *time,
char **buf, struct pstore_info *psi)
{
ssize_t size;
ssize_t ecc_notice_size;
struct ramoops_context *cxt = psi->data;
struct persistent_ram_zone *prz;
prz = ramoops_get_next_prz(cxt->przs, &cxt->dump_read_cnt,
cxt->max_dump_cnt, id, type,
PSTORE_TYPE_DMESG, 1);
if (!prz)
prz = ramoops_get_next_prz(&cxt->cprz, &cxt->console_read_cnt,
1, id, type, PSTORE_TYPE_CONSOLE, 0);
if (!prz)
prz = ramoops_get_next_prz(&cxt->fprz, &cxt->ftrace_read_cnt,
1, id, type, PSTORE_TYPE_FTRACE, 0);
if (!prz)
return 0;
time->tv_sec = 0;
time->tv_nsec = 0;
size = persistent_ram_old_size(prz);
ecc_notice_size = persistent_ram_ecc_string(prz, NULL, 0);
*buf = kmalloc(size + ecc_notice_size + 1, GFP_KERNEL);
if (*buf == NULL)
return -ENOMEM;
memcpy(*buf, persistent_ram_old(prz), size);
persistent_ram_ecc_string(prz, *buf + size, ecc_notice_size + 1);
return size + ecc_notice_size;
}
static size_t ramoops_write_kmsg_hdr(struct persistent_ram_zone *prz)
{
char *hdr;
struct timespec timestamp;
size_t len;
if (__getnstimeofday(&timestamp)) {
timestamp.tv_sec = 0;
timestamp.tv_nsec = 0;
}
hdr = kasprintf(GFP_ATOMIC, RAMOOPS_KERNMSG_HDR "%lu.%lu\n",
(long)timestamp.tv_sec, (long)(timestamp.tv_nsec / 1000));
WARN_ON_ONCE(!hdr);
len = hdr ? strlen(hdr) : 0;
persistent_ram_write(prz, hdr, len);
kfree(hdr);
return len;
}
static int notrace ramoops_pstore_write_buf(enum pstore_type_id type,
enum kmsg_dump_reason reason,
u64 *id, unsigned int part,
const char *buf,
size_t hsize, size_t size,
struct pstore_info *psi)
{
struct ramoops_context *cxt = psi->data;
struct persistent_ram_zone *prz;
size_t hlen;
if (type == PSTORE_TYPE_CONSOLE) {
if (!cxt->cprz)
return -ENOMEM;
persistent_ram_write(cxt->cprz, buf, size);
return 0;
} else if (type == PSTORE_TYPE_FTRACE) {
if (!cxt->fprz)
return -ENOMEM;
persistent_ram_write(cxt->fprz, buf, size);
return 0;
}
if (type != PSTORE_TYPE_DMESG)
return -EINVAL;
if (reason != KMSG_DUMP_OOPS &&
reason != KMSG_DUMP_PANIC)
return -EINVAL;
if (reason == KMSG_DUMP_OOPS && !cxt->dump_oops)
return -EINVAL;
if (part != 1)
return -ENOSPC;
if (!cxt->przs)
return -ENOSPC;
prz = cxt->przs[cxt->dump_write_cnt];
hlen = ramoops_write_kmsg_hdr(prz);
if (size + hlen > prz->buffer_size)
size = prz->buffer_size - hlen;
persistent_ram_write(prz, buf, size);
cxt->dump_write_cnt = (cxt->dump_write_cnt + 1) % cxt->max_dump_cnt;
return 0;
}
static int ramoops_pstore_erase(enum pstore_type_id type, u64 id, int count,
struct timespec time, struct pstore_info *psi)
{
struct ramoops_context *cxt = psi->data;
struct persistent_ram_zone *prz;
switch (type) {
case PSTORE_TYPE_DMESG:
if (id >= cxt->max_dump_cnt)
return -EINVAL;
prz = cxt->przs[id];
break;
case PSTORE_TYPE_CONSOLE:
prz = cxt->cprz;
break;
case PSTORE_TYPE_FTRACE:
prz = cxt->fprz;
break;
default:
return -EINVAL;
}
persistent_ram_free_old(prz);
persistent_ram_zap(prz);
return 0;
}
static void ramoops_free_przs(struct ramoops_context *cxt)
{
int i;
if (!cxt->przs)
return;
for (i = 0; !IS_ERR_OR_NULL(cxt->przs[i]); i++)
persistent_ram_free(cxt->przs[i]);
kfree(cxt->przs);
}
static int ramoops_init_przs(struct device *dev, struct ramoops_context *cxt,
phys_addr_t *paddr, size_t dump_mem_sz)
{
int err = -ENOMEM;
int i;
if (!cxt->record_size)
return 0;
if (*paddr + dump_mem_sz - cxt->phys_addr > cxt->size) {
dev_err(dev, "no room for dumps\n");
return -ENOMEM;
}
cxt->max_dump_cnt = dump_mem_sz / cxt->record_size;
if (!cxt->max_dump_cnt)
return -ENOMEM;
cxt->przs = kzalloc(sizeof(*cxt->przs) * cxt->max_dump_cnt,
GFP_KERNEL);
if (!cxt->przs) {
dev_err(dev, "failed to initialize a prz array for dumps\n");
return -ENOMEM;
}
for (i = 0; i < cxt->max_dump_cnt; i++) {
size_t sz = cxt->record_size;
cxt->przs[i] = persistent_ram_new(*paddr, sz, 0,
&cxt->ecc_info);
if (IS_ERR(cxt->przs[i])) {
err = PTR_ERR(cxt->przs[i]);
dev_err(dev, "failed to request mem region (0x%zx@0x%llx): %d\n",
sz, (unsigned long long)*paddr, err);
goto fail_prz;
}
*paddr += sz;
}
return 0;
fail_prz:
ramoops_free_przs(cxt);
return err;
}
static int ramoops_init_prz(struct device *dev, struct ramoops_context *cxt,
struct persistent_ram_zone **prz,
phys_addr_t *paddr, size_t sz, u32 sig)
{
if (!sz)
return 0;
if (*paddr + sz - cxt->phys_addr > cxt->size) {
dev_err(dev, "no room for mem region (0x%zx@0x%llx) in (0x%lx@0x%llx)\n",
sz, (unsigned long long)*paddr,
cxt->size, (unsigned long long)cxt->phys_addr);
return -ENOMEM;
}
*prz = persistent_ram_new(*paddr, sz, sig, &cxt->ecc_info);
if (IS_ERR(*prz)) {
int err = PTR_ERR(*prz);
dev_err(dev, "failed to request mem region (0x%zx@0x%llx): %d\n",
sz, (unsigned long long)*paddr, err);
return err;
}
persistent_ram_zap(*prz);
*paddr += sz;
return 0;
}
static int ramoops_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ramoops_platform_data *pdata = pdev->dev.platform_data;
struct ramoops_context *cxt = &oops_cxt;
size_t dump_mem_sz;
phys_addr_t paddr;
int err = -EINVAL;
if (cxt->max_dump_cnt)
goto fail_out;
if (!pdata->mem_size || (!pdata->record_size && !pdata->console_size &&
!pdata->ftrace_size)) {
pr_err("The memory size and the record/console size must be "
"non-zero\n");
goto fail_out;
}
if (!is_power_of_2(pdata->record_size))
pdata->record_size = rounddown_pow_of_two(pdata->record_size);
if (!is_power_of_2(pdata->console_size))
pdata->console_size = rounddown_pow_of_two(pdata->console_size);
if (!is_power_of_2(pdata->ftrace_size))
pdata->ftrace_size = rounddown_pow_of_two(pdata->ftrace_size);
cxt->dump_read_cnt = 0;
cxt->size = pdata->mem_size;
cxt->phys_addr = pdata->mem_address;
cxt->record_size = pdata->record_size;
cxt->console_size = pdata->console_size;
cxt->ftrace_size = pdata->ftrace_size;
cxt->dump_oops = pdata->dump_oops;
cxt->ecc_info = pdata->ecc_info;
paddr = cxt->phys_addr;
dump_mem_sz = cxt->size - cxt->console_size - cxt->ftrace_size;
err = ramoops_init_przs(dev, cxt, &paddr, dump_mem_sz);
if (err)
goto fail_out;
err = ramoops_init_prz(dev, cxt, &cxt->cprz, &paddr,
cxt->console_size, 0);
if (err)
goto fail_init_cprz;
err = ramoops_init_prz(dev, cxt, &cxt->fprz, &paddr, cxt->ftrace_size,
LINUX_VERSION_CODE);
if (err)
goto fail_init_fprz;
if (!cxt->przs && !cxt->cprz && !cxt->fprz) {
pr_err("memory size too small, minimum is %zu\n",
cxt->console_size + cxt->record_size +
cxt->ftrace_size);
err = -EINVAL;
goto fail_cnt;
}
cxt->pstore.data = cxt;
if (cxt->console_size)
cxt->pstore.bufsize = 1024;
cxt->pstore.bufsize = max(cxt->record_size, cxt->pstore.bufsize);
cxt->pstore.buf = kmalloc(cxt->pstore.bufsize, GFP_KERNEL);
spin_lock_init(&cxt->pstore.buf_lock);
if (!cxt->pstore.buf) {
pr_err("cannot allocate pstore buffer\n");
err = -ENOMEM;
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
pr_info("attached 0x%lx@0x%llx, ecc: %d/%d\n",
cxt->size, (unsigned long long)cxt->phys_addr,
cxt->ecc_info.ecc_size, cxt->ecc_info.block_size);
return 0;
fail_buf:
kfree(cxt->pstore.buf);
fail_clear:
cxt->pstore.bufsize = 0;
cxt->max_dump_cnt = 0;
fail_cnt:
kfree(cxt->fprz);
fail_init_fprz:
kfree(cxt->cprz);
fail_init_cprz:
ramoops_free_przs(cxt);
fail_out:
return err;
}
static int __exit ramoops_remove(struct platform_device *pdev)
{
#if 0
struct ramoops_context *cxt = &oops_cxt;
iounmap(cxt->virt_addr);
release_mem_region(cxt->phys_addr, cxt->size);
cxt->max_dump_cnt = 0;
kfree(cxt->pstore.buf);
cxt->pstore.bufsize = 0;
return 0;
#endif
return -EBUSY;
}
static void ramoops_register_dummy(void)
{
if (!mem_size)
return;
pr_info("using module parameters\n");
dummy_data = kzalloc(sizeof(*dummy_data), GFP_KERNEL);
if (!dummy_data) {
pr_info("could not allocate pdata\n");
return;
}
dummy_data->mem_size = mem_size;
dummy_data->mem_address = mem_address;
dummy_data->record_size = record_size;
dummy_data->console_size = ramoops_console_size;
dummy_data->ftrace_size = ramoops_ftrace_size;
dummy_data->dump_oops = dump_oops;
dummy_data->ecc_info.ecc_size = ramoops_ecc == 1 ? 16 : ramoops_ecc;
dummy = platform_device_register_data(NULL, "ramoops", -1,
dummy_data, sizeof(struct ramoops_platform_data));
if (IS_ERR(dummy)) {
pr_info("could not create platform device: %ld\n",
PTR_ERR(dummy));
}
}
static int __init ramoops_init(void)
{
ramoops_register_dummy();
return platform_driver_register(&ramoops_driver);
}
static void __exit ramoops_exit(void)
{
platform_driver_unregister(&ramoops_driver);
platform_device_unregister(dummy);
kfree(dummy_data);
}
