static void __naked tf_generic_smc(u32 type, u32 arg1, u32 arg2)
{
asm volatile(
".arch_extension sec\n\t"
"stmfd sp!, {r4 - r11, lr}\n\t"
__asmeq("%0", "r0")
__asmeq("%1", "r1")
__asmeq("%2", "r2")
"mov r3, #0\n\t"
"mov r4, #0\n\t"
"smc #0\n\t"
"ldmfd sp!, {r4 - r11, pc}"
:
: "r" (type), "r" (arg1), "r" (arg2)
: "memory");
}
static int tf_set_cpu_boot_addr(int cpu, unsigned long boot_addr)
{
tf_generic_smc(TF_SET_CPU_BOOT_ADDR_SMC, boot_addr, 0);
return 0;
}
void register_trusted_foundations(struct trusted_foundations_platform_data *pd)
{
register_firmware_ops(&trusted_foundations_ops);
}
void of_register_trusted_foundations(void)
{
struct device_node *node;
struct trusted_foundations_platform_data pdata;
int err;
node = of_find_compatible_node(NULL, NULL, "tlm,trusted-foundations");
if (!node)
return;
err = of_property_read_u32(node, "tlm,version-major",
&pdata.version_major);
if (err != 0)
panic("Trusted Foundation: missing version-major property\n");
err = of_property_read_u32(node, "tlm,version-minor",
&pdata.version_minor);
if (err != 0)
panic("Trusted Foundation: missing version-minor property\n");
register_trusted_foundations(&pdata);
}
