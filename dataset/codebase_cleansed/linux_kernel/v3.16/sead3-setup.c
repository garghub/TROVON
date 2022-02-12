const char *get_system_type(void)
{
return "MIPS SEAD3";
}
static uint32_t get_memsize_from_cmdline(void)
{
int memsize = 0;
char *p = arcs_cmdline;
char *s = "memsize=";
p = strstr(p, s);
if (p) {
p += strlen(s);
memsize = memparse(p, NULL);
}
return memsize;
}
static uint32_t get_memsize_from_env(void)
{
int memsize = 0;
char *p;
p = fw_getenv("memsize");
if (p)
memsize = memparse(p, NULL);
return memsize;
}
static uint32_t get_memsize(void)
{
uint32_t memsize;
memsize = get_memsize_from_cmdline();
if (memsize)
return memsize;
return get_memsize_from_env();
}
static void __init parse_memsize_param(void)
{
int offset;
const uint64_t *prop_value;
int prop_len;
uint32_t memsize = get_memsize();
if (!memsize)
return;
offset = fdt_path_offset(__dtb_start, "/memory");
if (offset > 0) {
uint64_t new_value;
prop_value = fdt_getprop(__dtb_start, offset, "reg", &prop_len);
new_value = be64_to_cpu(*prop_value);
new_value = (new_value & ~0xffffffffllu) | memsize;
fdt_setprop_inplace_u64(__dtb_start, offset, "reg", new_value);
}
}
void __init plat_mem_setup(void)
{
parse_memsize_param();
__dt_setup_arch(__dtb_start);
}
void __init device_tree_init(void)
{
if (!initial_boot_params)
return;
unflatten_and_copy_device_tree();
}
static int __init customize_machine(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
return 0;
}
