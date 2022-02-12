static int __init lantiq_ebu_init(void)
{
if (insert_resource(&iomem_resource, &ltq_ebu_resource) < 0)
panic("Failed to insert ebu memory");
if (request_mem_region(ltq_ebu_resource.start,
resource_size(&ltq_ebu_resource), "ebu") < 0)
panic("Failed to request ebu memory");
ltq_ebu_membase = ioremap_nocache(ltq_ebu_resource.start,
resource_size(&ltq_ebu_resource));
if (!ltq_ebu_membase)
panic("Failed to remap ebu memory");
ltq_ebu_w32(ltq_ebu_r32(LTQ_EBU_BUSCON0) & ~EBU_WRDIS, LTQ_EBU_BUSCON0);
return 0;
}
