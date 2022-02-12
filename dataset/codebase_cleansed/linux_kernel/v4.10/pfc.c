int __init sh_pfc_register(const char *name,
struct resource *resource, u32 num_resources)
{
sh_pfc_device.name = name;
sh_pfc_device.num_resources = num_resources;
sh_pfc_device.resource = resource;
return platform_device_register(&sh_pfc_device);
}
