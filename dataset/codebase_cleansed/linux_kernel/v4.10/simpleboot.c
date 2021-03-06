void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
const u32 *na, *ns, *reg, *timebase;
u64 memsize64;
int node, size, i;
if (fdt_check_header(_dtb_start) != 0)
fatal("Invalid device tree blob\n");
node = fdt_path_offset(_dtb_start, "/");
if (node < 0)
fatal("Cannot find root node\n");
na = fdt_getprop(_dtb_start, node, "#address-cells", &size);
if (!na || (size != 4))
fatal("Cannot find #address-cells property");
ns = fdt_getprop(_dtb_start, node, "#size-cells", &size);
if (!ns || (size != 4))
fatal("Cannot find #size-cells property");
node = fdt_node_offset_by_prop_value(_dtb_start, -1, "device_type",
"memory", sizeof("memory"));
if (node < 0)
fatal("Cannot find memory node\n");
reg = fdt_getprop(_dtb_start, node, "reg", &size);
if (size < (*na+*ns) * sizeof(u32))
fatal("cannot get memory range\n");
for (i = 0; i < *na; i++)
if (*reg++ != 0)
fatal("Memory range is not based at address 0\n");
memsize64 = 0;
for (i = 0; i < *ns; i++)
memsize64 = (memsize64 << 32) | *reg++;
if (sizeof(void *) == 4 && memsize64 >= 0x100000000ULL)
memsize64 = 0xffffffff;
node = fdt_node_offset_by_prop_value(_dtb_start, -1, "device_type",
"cpu", sizeof("cpu"));
if (!node)
fatal("Cannot find cpu node\n");
timebase = fdt_getprop(_dtb_start, node, "timebase-frequency", &size);
if (timebase && (size == 4))
timebase_period_ns = 1000000000 / *timebase;
simple_alloc_init(_end, memsize64 - (unsigned long)_end, 32, 64);
fdt_init(_dtb_start);
if (platform_specific_init)
platform_specific_init();
serial_console_init();
}
