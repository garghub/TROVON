void __init bcm_kona_smc_init(void)
{
struct device_node *node;
node = of_find_matching_node(NULL, bcm_kona_smc_ids);
BUG_ON(!node);
bridge_data.buffer_addr =
be32_to_cpu(*of_get_address(node, 0, NULL, NULL));
BUG_ON(!bridge_data.buffer_addr);
bridge_data.bounce = of_iomap(node, 0);
BUG_ON(!bridge_data.bounce);
bridge_data.initialized = 1;
pr_info("Secure API initialized!\n");
}
static void __bcm_kona_smc(void *info)
{
struct bcm_kona_smc_data *data = info;
u32 *args = bridge_data.bounce;
int rc = 0;
BUG_ON(smp_processor_id() != 0);
BUG_ON(!bridge_data.initialized);
args[0] = data->arg0;
args[1] = data->arg1;
args[2] = data->arg2;
args[3] = data->arg3;
if (data->service_id != SSAPI_BRCM_START_VC_CORE)
flush_cache_all();
rc = bcm_kona_smc_asm(data->service_id, bridge_data.buffer_addr);
if (rc != SEC_ROM_RET_OK)
pr_err("Secure Monitor call failed (0x%x)!\n", rc);
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
if (get_cpu() != 0)
smp_call_function_single(0, __bcm_kona_smc, (void *)&data, 1);
else
__bcm_kona_smc(&data);
put_cpu();
return 0;
}
