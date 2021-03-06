static void __iomem *sdk7786_fpga_probe(void)
{
unsigned long area;
void __iomem *base;
for (area = PA_AREA0; area < PA_AREA7; area += SZ_64M) {
base = ioremap_nocache(area + FPGA_REGS_OFFSET, FPGA_REGS_SIZE);
if (!base) {
continue;
}
if (ioread16(base + SRSTR) == SRSTR_MAGIC)
return base;
iounmap(base);
}
return NULL;
}
void __init sdk7786_fpga_init(void)
{
u16 version, date;
sdk7786_fpga_base = sdk7786_fpga_probe();
if (unlikely(!sdk7786_fpga_base)) {
panic("FPGA detection failed.\n");
return;
}
version = fpga_read_reg(FPGAVR);
date = fpga_read_reg(FPGADR);
pr_info("\tFPGA version:\t%d.%d (built on %d/%d/%d)\n",
bcd2bin(version >> 8) & 0xf, bcd2bin(version & 0xf),
((date >> 12) & 0xf) + 2000,
(date >> 8) & 0xf, bcd2bin(date & 0xff));
}
