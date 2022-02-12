static ssize_t opal_msglog_read(struct file *file, struct kobject *kobj,
struct bin_attribute *bin_attr, char *to,
loff_t pos, size_t count)
{
struct memcons *mc = bin_attr->private;
const char *conbuf;
size_t ret, first_read = 0;
uint32_t out_pos, avail;
if (!mc)
return -ENODEV;
out_pos = be32_to_cpu(ACCESS_ONCE(mc->out_pos));
smp_rmb();
conbuf = phys_to_virt(be64_to_cpu(mc->obuf_phys));
if (out_pos & MEMCONS_OUT_POS_WRAP) {
out_pos &= MEMCONS_OUT_POS_MASK;
avail = be32_to_cpu(mc->obuf_size) - out_pos;
ret = memory_read_from_buffer(to, count, &pos,
conbuf + out_pos, avail);
if (ret < 0)
goto out;
first_read = ret;
to += first_read;
count -= first_read;
pos -= avail;
}
if (out_pos > be32_to_cpu(mc->obuf_size)) {
pr_err("OPAL: memory console corruption. Aborting read.\n");
return -EINVAL;
}
ret = memory_read_from_buffer(to, count, &pos, conbuf, out_pos);
if (ret < 0)
goto out;
ret += first_read;
out:
return ret;
}
void __init opal_msglog_init(void)
{
u64 mcaddr;
struct memcons *mc;
if (of_property_read_u64(opal_node, "ibm,opal-memcons", &mcaddr)) {
pr_warn("OPAL: Property ibm,opal-memcons not found, no message log\n");
return;
}
mc = phys_to_virt(mcaddr);
if (!mc) {
pr_warn("OPAL: memory console address is invalid\n");
return;
}
if (be64_to_cpu(mc->magic) != MEMCONS_MAGIC) {
pr_warn("OPAL: memory console version is invalid\n");
return;
}
opal_msglog_attr.private = mc;
if (sysfs_create_bin_file(opal_kobj, &opal_msglog_attr) != 0)
pr_warn("OPAL: sysfs file creation failed\n");
}
