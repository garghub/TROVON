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
if (reason == KMSG_DUMP_OOPS && !dump_oops)
return;
buf = cxt->virt_addr + (cxt->count * RECORD_SIZE);
buf_orig = buf;
memset(buf, '\0', RECORD_SIZE);
res = sprintf(buf, "%s", RAMOOPS_KERNMSG_HDR);
buf += res;
do_gettimeofday(&timestamp);
res = sprintf(buf, "%lu.%lu\n", (long)timestamp.tv_sec, (long)timestamp.tv_usec);
buf += res;
hdr_size = buf - buf_orig;
l2_cpy = min(l2, RECORD_SIZE - hdr_size);
l1_cpy = min(l1, RECORD_SIZE - hdr_size - l2_cpy);
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
if (pdata) {
mem_size = pdata->mem_size;
mem_address = pdata->mem_address;
}
if (!mem_size) {
printk(KERN_ERR "ramoops: invalid size specification");
goto fail3;
}
rounddown_pow_of_two(mem_size);
if (mem_size < RECORD_SIZE) {
printk(KERN_ERR "ramoops: size too small");
goto fail3;
}
cxt->max_count = mem_size / RECORD_SIZE;
cxt->count = 0;
cxt->size = mem_size;
cxt->phys_addr = mem_address;
if (!request_mem_region(cxt->phys_addr, cxt->size, "ramoops")) {
printk(KERN_ERR "ramoops: request mem region failed");
err = -EINVAL;
goto fail3;
}
cxt->virt_addr = ioremap(cxt->phys_addr, cxt->size);
if (!cxt->virt_addr) {
printk(KERN_ERR "ramoops: ioremap failed");
goto fail2;
}
cxt->dump.dump = ramoops_do_dump;
err = kmsg_dump_register(&cxt->dump);
if (err) {
printk(KERN_ERR "ramoops: registering kmsg dumper failed");
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
printk(KERN_WARNING "ramoops: could not unregister kmsg_dumper");
iounmap(cxt->virt_addr);
release_mem_region(cxt->phys_addr, cxt->size);
return 0;
}
static int __init ramoops_init(void)
{
return platform_driver_probe(&ramoops_driver, ramoops_probe);
}
static void __exit ramoops_exit(void)
{
platform_driver_unregister(&ramoops_driver);
}
