static __init bool sead3_detect(void)
{
uint32_t rev;
rev = __raw_readl((void *)MIPS_REVISION);
return (rev & MIPS_REVISION_MACHINE) == MIPS_REVISION_MACHINE_SEAD3;
}
static __init int append_memory(void *fdt)
{
return yamon_dt_append_memory(fdt, mem_regions);
}
static __init int remove_gic(void *fdt)
{
const unsigned int cpu_ehci_int = 2;
const unsigned int cpu_uart_int = 4;
const unsigned int cpu_eth_int = 6;
int gic_off, cpu_off, uart_off, eth_off, ehci_off, err;
uint32_t cfg, cpu_phandle;
cfg = __raw_readl((uint32_t *)SEAD_CONFIG);
if (cfg & SEAD_CONFIG_GIC_PRESENT)
return 0;
gic_off = fdt_node_offset_by_compatible(fdt, -1, "mti,gic");
if (gic_off < 0) {
pr_err("unable to find DT GIC node: %d\n", gic_off);
return gic_off;
}
err = fdt_nop_node(fdt, gic_off);
if (err) {
pr_err("unable to nop GIC node\n");
return err;
}
cpu_off = fdt_node_offset_by_compatible(fdt, -1,
"mti,cpu-interrupt-controller");
if (cpu_off < 0) {
pr_err("unable to find CPU intc node: %d\n", cpu_off);
return cpu_off;
}
cpu_phandle = fdt_get_phandle(fdt, cpu_off);
if (!cpu_phandle) {
pr_err("unable to get CPU intc phandle\n");
return -EINVAL;
}
uart_off = fdt_node_offset_by_compatible(fdt, -1, "ns16550a");
while (uart_off >= 0) {
err = fdt_setprop_u32(fdt, uart_off, "interrupt-parent",
cpu_phandle);
if (err) {
pr_warn("unable to set UART interrupt-parent: %d\n",
err);
return err;
}
err = fdt_setprop_u32(fdt, uart_off, "interrupts",
cpu_uart_int);
if (err) {
pr_err("unable to set UART interrupts property: %d\n",
err);
return err;
}
uart_off = fdt_node_offset_by_compatible(fdt, uart_off,
"ns16550a");
}
if (uart_off != -FDT_ERR_NOTFOUND) {
pr_err("error searching for UART DT node: %d\n", uart_off);
return uart_off;
}
eth_off = fdt_node_offset_by_compatible(fdt, -1, "smsc,lan9115");
if (eth_off < 0) {
pr_err("unable to find ethernet DT node: %d\n", eth_off);
return eth_off;
}
err = fdt_setprop_u32(fdt, eth_off, "interrupt-parent", cpu_phandle);
if (err) {
pr_err("unable to set ethernet interrupt-parent: %d\n", err);
return err;
}
err = fdt_setprop_u32(fdt, eth_off, "interrupts", cpu_eth_int);
if (err) {
pr_err("unable to set ethernet interrupts property: %d\n", err);
return err;
}
ehci_off = fdt_node_offset_by_compatible(fdt, -1, "generic-ehci");
if (ehci_off < 0) {
pr_err("unable to find EHCI DT node: %d\n", ehci_off);
return ehci_off;
}
err = fdt_setprop_u32(fdt, ehci_off, "interrupt-parent", cpu_phandle);
if (err) {
pr_err("unable to set EHCI interrupt-parent: %d\n", err);
return err;
}
err = fdt_setprop_u32(fdt, ehci_off, "interrupts", cpu_ehci_int);
if (err) {
pr_err("unable to set EHCI interrupts property: %d\n", err);
return err;
}
return 0;
}
static __init const void *sead3_fixup_fdt(const void *fdt,
const void *match_data)
{
static unsigned char fdt_buf[16 << 10] __initdata;
int err;
if (fdt_check_header(fdt))
panic("Corrupt DT");
BUG_ON(fdt_node_check_compatible(fdt, 0, "mti,sead-3"));
fw_init_cmdline();
err = apply_mips_fdt_fixups(fdt_buf, sizeof(fdt_buf),
fdt, sead3_fdt_fixups);
if (err)
panic("Unable to fixup FDT: %d", err);
return fdt_buf;
}
static __init unsigned int sead3_measure_hpt_freq(void)
{
void __iomem *status_reg = (void __iomem *)0xbf000410;
unsigned int freq, orig, tick = 0;
unsigned long flags;
local_irq_save(flags);
orig = readl(status_reg) & 0x2;
while ((readl(status_reg) & 0x2) == orig)
;
orig = orig ^ 0x2;
write_c0_count(0);
while (tick < 100) {
while ((readl(status_reg) & 0x2) == orig)
;
orig = orig ^ 0x2;
tick++;
}
freq = read_c0_count();
local_irq_restore(flags);
return freq;
}
