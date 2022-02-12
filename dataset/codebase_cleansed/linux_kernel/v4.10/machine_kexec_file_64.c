int arch_kexec_kernel_image_probe(struct kimage *image, void *buf,
unsigned long buf_len)
{
int i, ret = -ENOEXEC;
struct kexec_file_ops *fops;
if (image->type == KEXEC_TYPE_CRASH)
return -ENOTSUPP;
for (i = 0; i < ARRAY_SIZE(kexec_file_loaders); i++) {
fops = kexec_file_loaders[i];
if (!fops || !fops->probe)
continue;
ret = fops->probe(buf, buf_len);
if (!ret) {
image->fops = fops;
return ret;
}
}
return ret;
}
void *arch_kexec_kernel_image_load(struct kimage *image)
{
if (!image->fops || !image->fops->load)
return ERR_PTR(-ENOEXEC);
return image->fops->load(image, image->kernel_buf,
image->kernel_buf_len, image->initrd_buf,
image->initrd_buf_len, image->cmdline_buf,
image->cmdline_buf_len);
}
int arch_kimage_file_post_load_cleanup(struct kimage *image)
{
if (!image->fops || !image->fops->cleanup)
return 0;
return image->fops->cleanup(image->image_loader_data);
}
int arch_kexec_walk_mem(struct kexec_buf *kbuf, int (*func)(u64, u64, void *))
{
int ret = 0;
u64 i;
phys_addr_t mstart, mend;
if (kbuf->top_down) {
for_each_free_mem_range_reverse(i, NUMA_NO_NODE, 0,
&mstart, &mend, NULL) {
ret = func(mstart, mend - 1, kbuf);
if (ret)
break;
}
} else {
for_each_free_mem_range(i, NUMA_NO_NODE, 0, &mstart, &mend,
NULL) {
ret = func(mstart, mend - 1, kbuf);
if (ret)
break;
}
}
return ret;
}
int setup_purgatory(struct kimage *image, const void *slave_code,
const void *fdt, unsigned long kernel_load_addr,
unsigned long fdt_load_addr)
{
unsigned int *slave_code_buf, master_entry;
int ret;
slave_code_buf = kmalloc(SLAVE_CODE_SIZE, GFP_KERNEL);
if (!slave_code_buf)
return -ENOMEM;
ret = kexec_purgatory_get_set_symbol(image, "purgatory_start",
slave_code_buf, SLAVE_CODE_SIZE,
true);
if (ret) {
kfree(slave_code_buf);
return ret;
}
master_entry = slave_code_buf[0];
memcpy(slave_code_buf, slave_code, SLAVE_CODE_SIZE);
slave_code_buf[0] = master_entry;
ret = kexec_purgatory_get_set_symbol(image, "purgatory_start",
slave_code_buf, SLAVE_CODE_SIZE,
false);
kfree(slave_code_buf);
ret = kexec_purgatory_get_set_symbol(image, "kernel", &kernel_load_addr,
sizeof(kernel_load_addr), false);
if (ret)
return ret;
ret = kexec_purgatory_get_set_symbol(image, "dt_offset", &fdt_load_addr,
sizeof(fdt_load_addr), false);
if (ret)
return ret;
return 0;
}
int delete_fdt_mem_rsv(void *fdt, unsigned long start, unsigned long size)
{
int i, ret, num_rsvs = fdt_num_mem_rsv(fdt);
for (i = 0; i < num_rsvs; i++) {
uint64_t rsv_start, rsv_size;
ret = fdt_get_mem_rsv(fdt, i, &rsv_start, &rsv_size);
if (ret) {
pr_err("Malformed device tree.\n");
return -EINVAL;
}
if (rsv_start == start && rsv_size == size) {
ret = fdt_del_mem_rsv(fdt, i);
if (ret) {
pr_err("Error deleting device tree reservation.\n");
return -EINVAL;
}
return 0;
}
}
return -ENOENT;
}
int setup_new_fdt(const struct kimage *image, void *fdt,
unsigned long initrd_load_addr, unsigned long initrd_len,
const char *cmdline)
{
int ret, chosen_node;
const void *prop;
ret = delete_fdt_mem_rsv(fdt, __pa(initial_boot_params),
fdt_totalsize(initial_boot_params));
if (ret == 0)
pr_debug("Removed old device tree reservation.\n");
else if (ret != -ENOENT)
return ret;
chosen_node = fdt_path_offset(fdt, "/chosen");
if (chosen_node == -FDT_ERR_NOTFOUND) {
chosen_node = fdt_add_subnode(fdt, fdt_path_offset(fdt, "/"),
"chosen");
if (chosen_node < 0) {
pr_err("Error creating /chosen.\n");
return -EINVAL;
}
} else if (chosen_node < 0) {
pr_err("Malformed device tree: error reading /chosen.\n");
return -EINVAL;
}
prop = fdt_getprop(fdt, chosen_node, "linux,initrd-start", NULL);
if (prop) {
uint64_t tmp_start, tmp_end, tmp_size;
tmp_start = fdt64_to_cpu(*((const fdt64_t *) prop));
prop = fdt_getprop(fdt, chosen_node, "linux,initrd-end", NULL);
if (!prop) {
pr_err("Malformed device tree.\n");
return -EINVAL;
}
tmp_end = fdt64_to_cpu(*((const fdt64_t *) prop));
tmp_size = tmp_end - tmp_start;
ret = delete_fdt_mem_rsv(fdt, tmp_start, tmp_size);
if (ret == -ENOENT)
ret = delete_fdt_mem_rsv(fdt, tmp_start,
round_up(tmp_size, PAGE_SIZE));
if (ret == 0)
pr_debug("Removed old initrd reservation.\n");
else if (ret != -ENOENT)
return ret;
if (initrd_len == 0) {
ret = fdt_delprop(fdt, chosen_node,
"linux,initrd-start");
if (ret) {
pr_err("Error deleting linux,initrd-start.\n");
return -EINVAL;
}
ret = fdt_delprop(fdt, chosen_node, "linux,initrd-end");
if (ret) {
pr_err("Error deleting linux,initrd-end.\n");
return -EINVAL;
}
}
}
if (initrd_len) {
ret = fdt_setprop_u64(fdt, chosen_node,
"linux,initrd-start",
initrd_load_addr);
if (ret < 0) {
pr_err("Error setting up the new device tree.\n");
return -EINVAL;
}
ret = fdt_setprop_u64(fdt, chosen_node, "linux,initrd-end",
initrd_load_addr + initrd_len);
if (ret < 0) {
pr_err("Error setting up the new device tree.\n");
return -EINVAL;
}
ret = fdt_add_mem_rsv(fdt, initrd_load_addr, initrd_len);
if (ret) {
pr_err("Error reserving initrd memory: %s\n",
fdt_strerror(ret));
return -EINVAL;
}
}
if (cmdline != NULL) {
ret = fdt_setprop_string(fdt, chosen_node, "bootargs", cmdline);
if (ret < 0) {
pr_err("Error setting up the new device tree.\n");
return -EINVAL;
}
} else {
ret = fdt_delprop(fdt, chosen_node, "bootargs");
if (ret && ret != -FDT_ERR_NOTFOUND) {
pr_err("Error deleting bootargs.\n");
return -EINVAL;
}
}
ret = setup_ima_buffer(image, fdt, chosen_node);
if (ret) {
pr_err("Error setting up the new device tree.\n");
return ret;
}
ret = fdt_setprop(fdt, chosen_node, "linux,booted-from-kexec", NULL, 0);
if (ret) {
pr_err("Error setting up the new device tree.\n");
return -EINVAL;
}
return 0;
}
