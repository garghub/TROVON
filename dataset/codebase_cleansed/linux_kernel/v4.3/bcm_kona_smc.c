int __init bcm_kona_smc_init(void)
{
struct device_node *node;
const __be32 *prop_val;
u64 prop_size = 0;
unsigned long buffer_size;
u32 buffer_phys;
node = of_find_matching_node(NULL, bcm_kona_smc_ids);
if (!node)
return -ENODEV;
prop_val = of_get_address(node, 0, &prop_size, NULL);
if (!prop_val)
return -EINVAL;
if (prop_size < 4 * sizeof(u32) || prop_size > (u64)ULONG_MAX)
return -EINVAL;
buffer_size = (unsigned long)prop_size;
buffer_phys = be32_to_cpup(prop_val);
if (!buffer_phys)
return -EINVAL;
bcm_smc_buffer = ioremap(buffer_phys, buffer_size);
if (!bcm_smc_buffer)
return -ENOMEM;
bcm_smc_buffer_phys = buffer_phys;
pr_info("Kona Secure API initialized\n");
return 0;
}
static int bcm_kona_do_smc(u32 service_id, u32 buffer_phys)
{
register u32 ip asm("ip");
register u32 r0 asm("r0");
register u32 r4 asm("r4");
register u32 r5 asm("r5");
register u32 r6 asm("r6");
r4 = service_id;
r5 = 0x3;
r6 = buffer_phys;
asm volatile (
__asmeq("%0", "ip")
__asmeq("%1", "r0")
__asmeq("%2", "r4")
__asmeq("%3", "r5")
__asmeq("%4", "r6")
#ifdef REQUIRES_SEC
".arch_extension sec\n"
#endif
" smc #0\n"
: "=r" (ip), "=r" (r0)
: "r" (r4), "r" (r5), "r" (r6)
: "r1", "r2", "r3", "r7", "lr");
BUG_ON(ip != SEC_EXIT_NORMAL);
return r0;
}
static void __bcm_kona_smc(void *info)
{
struct bcm_kona_smc_data *data = info;
u32 *args = bcm_smc_buffer;
BUG_ON(smp_processor_id() != 0);
BUG_ON(!args);
writel_relaxed(data->arg0, args++);
writel_relaxed(data->arg1, args++);
writel_relaxed(data->arg2, args++);
writel(data->arg3, args);
flush_cache_all();
data->result = bcm_kona_do_smc(data->service_id, bcm_smc_buffer_phys);
}
unsigned bcm_kona_smc(unsigned service_id, unsigned arg0, unsigned arg1,
unsigned arg2, unsigned arg3)
{
struct bcm_kona_smc_data data;
data.service_id = service_id;
data.arg0 = arg0;
data.arg1 = arg1;
data.arg2 = arg2;
data.arg3 = arg3;
data.result = 0;
smp_call_function_single(0, __bcm_kona_smc, &data, 1);
return data.result;
}
