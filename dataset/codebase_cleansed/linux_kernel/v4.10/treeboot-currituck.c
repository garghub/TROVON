static unsigned long long ibm_currituck_detect_memsize(void)
{
u32 reg;
unsigned i;
unsigned long long memsize = 0;
for(i = 0; i < MAX_RANKS; i++){
reg = mfdcrx(DDR3_MR0CF + i);
if (!(reg & 1))
continue;
reg &= 0x0000f000;
reg >>= 12;
memsize += (0x800000ULL << reg);
}
return memsize;
}
static void ibm_currituck_fixups(void)
{
void *devp = finddevice("/");
u32 dma_ranges[7];
dt_fixup_memory(0x0ULL, ibm_currituck_memsize);
while ((devp = find_node_by_devtype(devp, "pci"))) {
if (getprop(devp, "dma-ranges", dma_ranges, sizeof(dma_ranges)) < 0) {
printf("%s: Failed to get dma-ranges\r\n", __func__);
continue;
}
dma_ranges[5] = ibm_currituck_memsize >> 32;
dma_ranges[6] = ibm_currituck_memsize & 0xffffffffUL;
setprop(devp, "dma-ranges", dma_ranges, sizeof(dma_ranges));
}
}
void platform_init(void)
{
unsigned long end_of_ram, avail_ram;
u32 pir_reg;
int node, size;
const u32 *timebase;
ibm_currituck_memsize = ibm_currituck_detect_memsize();
if (ibm_currituck_memsize >> 32)
end_of_ram = ~0UL;
else
end_of_ram = ibm_currituck_memsize;
avail_ram = end_of_ram - (unsigned long)_end;
simple_alloc_init(_end, avail_ram, 128, 64);
platform_ops.fixups = ibm_currituck_fixups;
platform_ops.exit = ibm44x_dbcr_reset;
pir_reg = mfspr(SPRN_PIR);
if (fdt_check_header(_dtb_start) != 0)
fatal("Invalid device tree blob\n");
node = fdt_node_offset_by_prop_value(_dtb_start, -1, "device_type",
"cpu", sizeof("cpu"));
if (!node)
fatal("Cannot find cpu node\n");
timebase = fdt_getprop(_dtb_start, node, "timebase-frequency", &size);
if (timebase && (size == 4))
timebase_period_ns = 1000000000 / *timebase;
fdt_set_boot_cpuid_phys(_dtb_start, pir_reg);
fdt_init(_dtb_start);
serial_console_init();
}
