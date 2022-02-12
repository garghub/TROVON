static int __init epapr_paravirt_init(void)
{
struct device_node *hyper_node;
const u32 *insts;
int len, i;
hyper_node = of_find_node_by_path("/hypervisor");
if (!hyper_node)
return -ENODEV;
insts = of_get_property(hyper_node, "hcall-instructions", &len);
if (!insts)
return -ENODEV;
if (len % 4 || len > (4 * 4))
return -ENODEV;
for (i = 0; i < (len / 4); i++)
patch_instruction(epapr_hypercall_start + i, insts[i]);
epapr_paravirt_enabled = true;
return 0;
}
