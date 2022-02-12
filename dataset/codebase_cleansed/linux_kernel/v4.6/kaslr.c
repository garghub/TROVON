static __init u64 get_kaslr_seed(void *fdt)
{
int node, len;
u64 *prop;
u64 ret;
node = fdt_path_offset(fdt, "/chosen");
if (node < 0)
return 0;
prop = fdt_getprop_w(fdt, node, "kaslr-seed", &len);
if (!prop || len != sizeof(u64))
return 0;
ret = fdt64_to_cpu(*prop);
*prop = 0;
return ret;
}
static __init const u8 *get_cmdline(void *fdt)
{
static __initconst const u8 default_cmdline[] = CONFIG_CMDLINE;
if (!IS_ENABLED(CONFIG_CMDLINE_FORCE)) {
int node;
const u8 *prop;
node = fdt_path_offset(fdt, "/chosen");
if (node < 0)
goto out;
prop = fdt_getprop(fdt, node, "bootargs", NULL);
if (!prop)
goto out;
return prop;
}
out:
return default_cmdline;
}
u64 __init kaslr_early_init(u64 dt_phys)
{
void *fdt;
u64 seed, offset, mask, module_range;
const u8 *cmdline, *str;
int size;
module_alloc_base = (u64)_etext - MODULES_VSIZE;
early_fixmap_init();
fdt = __fixmap_remap_fdt(dt_phys, &size, PAGE_KERNEL);
if (!fdt)
return 0;
seed = get_kaslr_seed(fdt);
if (!seed)
return 0;
cmdline = get_cmdline(fdt);
str = strstr(cmdline, "nokaslr");
if (str == cmdline || (str > cmdline && *(str - 1) == ' '))
return 0;
mask = ((1UL << (VA_BITS - 2)) - 1) & ~(SZ_2M - 1);
offset = seed & mask;
memstart_offset_seed = seed >> 48;
if ((((u64)_text + offset) >> SWAPPER_TABLE_SHIFT) !=
(((u64)_end + offset) >> SWAPPER_TABLE_SHIFT))
offset = (offset + (u64)(_end - _text)) & mask;
if (IS_ENABLED(CONFIG_KASAN))
return offset;
if (IS_ENABLED(CONFIG_RANDOMIZE_MODULE_REGION_FULL)) {
module_range = VMALLOC_END - VMALLOC_START - MODULES_VSIZE;
module_alloc_base = VMALLOC_START;
} else {
module_range = MODULES_VSIZE - (u64)(_etext - _stext);
module_alloc_base = (u64)_etext + offset - MODULES_VSIZE;
}
module_alloc_base += (module_range * (seed & ((1 << 21) - 1))) >> 21;
module_alloc_base &= PAGE_MASK;
return offset;
}
