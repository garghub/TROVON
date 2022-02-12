static void ramoops_do_dump(struct kmsg_dumper *dumper,
enum kmsg_dump_reason reason, const char *s1, unsigned long l1,
const char *s2, unsigned long l2)
{
struct ramoops_context *cxt = container_of(dumper,
struct ramoops_context, dump);
unsigned long s1_start, s2_start;
unsigned long l1_cpy, l2_cpy;
int res, hdr_size;
char *buf, *buf_orig;
struct timeval timestamp;
if (reason != KMSG_DUMP_OOPS &&
reason != KMSG_DUMP_PANIC &&
reason != KMSG_DUMP_KEXEC)
return;
if (reason == KMSG_DUMP_OOPS && !cxt->dump_oops)
return;
buf = cxt->virt_addr + (cxt->count * cxt->record_size);
buf_orig = buf;
memset(buf, '\0', cxt->record_size);
res = sprintf(buf, "%s", RAMOOPS_KERNMSG_HDR);
buf += res;
do_gettimeofday(&timestamp);
res = sprintf(buf, "%lu.%lu\n", (long)timestamp.tv_sec, (long)timestamp.tv_usec);
buf += res;
hdr_size = buf - buf_orig;
l2_cpy = min(l2, cxt->record_size - hdr_size);
l1_cpy = min(l1, cxt->record_size - hdr_size - l2_cpy);
s2_start = l2 - l2_cpy;
s1_start = l1 - l1_cpy;
memcpy(buf, s1 + s1_start, l1_cpy);
memcpy(buf + l1_cpy, s2 + s2_start, l2_cpy);
cxt->count = (cxt->count + 1) % cxt->max_count;
}
static int __init ramoops_probe(struct platform_device *pdev)
{
struct ramoops_platform_data *pdata = pdev->dev.platform_data;
struct ramoops_context *cxt = &oops_cxt;
int err = -EINVAL;
if (!pdata->mem_size || !pdata->record_size) {
pr_err("The memory size and the record size must be "
"non-zero\n");
goto fail3;
}
rounddown_pow_of_two(pdata->mem_size);
rounddown_pow_of_two(pdata->record_size);
if (pdata->mem_size < MIN_MEM_SIZE &&
pdata->record_size < MIN_MEM_SIZE) {
pr_err("memory size too small, minium is %lu\n", MIN_MEM_SIZE);
goto fail3;
}
if (pdata->mem_size < pdata->record_size) {
pr_err("The memory size must be larger than the "
"records size\n");
goto fail3;
}
cxt->max_count = pdata->mem_size / pdata->record_size;
cxt->count = 0;
cxt->size = pdata->mem_size;
cxt->phys_addr = pdata->mem_address;
cxt->record_size = pdata->record_size;
cxt->dump_oops = pdata->dump_oops;
mem_size = pdata->mem_size;
mem_address = pdata->mem_address;
record_size = pdata->record_size;
dump_oops = pdata->dump_oops;
if (!request_mem_region(cxt->phys_addr, cxt->size, "ramoops")) {
pr_err("request mem region failed\n");
err = -EINVAL;
goto fail3;
}
cxt->virt_addr = ioremap(cxt->phys_addr, cxt->size);
if (!cxt->virt_addr) {
pr_err("ioremap failed\n");
goto fail2;
}
cxt->dump.dump = ramoops_do_dump;
err = kmsg_dump_register(&cxt->dump);
if (err) {
pr_err("registering kmsg dumper failed\n");
goto fail1;
}
return 0;
fail1:
iounmap(cxt->virt_addr);
fail2:
release_mem_region(cxt->phys_addr, cxt->size);
fail3:
return err;
}
static int __exit ramoops_remove(struct platform_device *pdev)
{
struct ramoops_context *cxt = &oops_cxt;
if (kmsg_dump_unregister(&cxt->dump) < 0)
pr_warn("could not unregister kmsg_dumper\n");
iounmap(cxt->virt_addr);
release_mem_region(cxt->phys_addr, cxt->size);
return 0;
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
