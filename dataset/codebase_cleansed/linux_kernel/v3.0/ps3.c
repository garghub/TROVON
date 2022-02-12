static void prep_cmdline(void *chosen)
{
if (cmdline[0] == '\0')
getprop(chosen, "bootargs", cmdline, COMMAND_LINE_SIZE-1);
else
setprop_str(chosen, "bootargs", cmdline);
printf("cmdline: '%s'\n", cmdline);
}
static void ps3_console_write(const char *buf, int len)
{
}
static void ps3_exit(void)
{
printf("ps3_exit\n");
lv1_panic(0);
while (1);
}
static int ps3_repository_read_rm_size(u64 *rm_size)
{
int result;
u64 lpar_id;
u64 ppe_id;
u64 v2;
result = lv1_get_logical_partition_id(&lpar_id);
if (result)
return -1;
result = lv1_get_logical_ppe_id(&ppe_id);
if (result)
return -1;
result = lv1_get_repository_node_value(lpar_id, 0x0000000062690000ULL,
0x7075000000000000ULL, ppe_id, 0x726d5f73697a6500ULL, rm_size,
&v2);
printf("%s:%d: ppe_id %lu \n", __func__, __LINE__,
(unsigned long)ppe_id);
printf("%s:%d: lpar_id %lu \n", __func__, __LINE__,
(unsigned long)lpar_id);
printf("%s:%d: rm_size %llxh \n", __func__, __LINE__, *rm_size);
return result ? -1 : 0;
}
void ps3_copy_vectors(void)
{
extern char __system_reset_kernel[];
memcpy((void *)0x100, __system_reset_kernel, 512);
flush_cache((void *)0x100, 512);
}
void platform_init(unsigned long null_check)
{
const u32 heapsize = 0x1000000 - (u32)_end;
void *chosen;
unsigned long ft_addr;
u64 rm_size;
unsigned long val;
console_ops.write = ps3_console_write;
platform_ops.exit = ps3_exit;
printf("\n-- PS3 bootwrapper --\n");
simple_alloc_init(_end, heapsize, 32, 64);
fdt_init(_dtb_start);
chosen = finddevice("/chosen");
ps3_repository_read_rm_size(&rm_size);
dt_fixup_memory(0, rm_size);
if (_initrd_end > _initrd_start) {
setprop_val(chosen, "linux,initrd-start", (u32)(_initrd_start));
setprop_val(chosen, "linux,initrd-end", (u32)(_initrd_end));
}
prep_cmdline(chosen);
ft_addr = dt_ops.finalize();
ps3_copy_vectors();
printf(" flat tree at 0x%lx\n\r", ft_addr);
val = *(unsigned long *)0;
if (val != null_check)
printf("null check failed: %lx != %lx\n\r", val, null_check);
((kernel_entry_t)0)(ft_addr, 0, NULL);
ps3_exit();
}
