static void update_cs_ranges(void)
{
void *bus_node, *parent_node;
u32 *ctrl_addr;
unsigned long ctrl_size;
u32 naddr, nsize;
int len;
int i;
bus_node = finddevice("/localbus");
if (!bus_node || !dt_is_compatible(bus_node, "fsl,pq2-localbus"))
return;
dt_get_reg_format(bus_node, &naddr, &nsize);
if (naddr != 2 || nsize != 1)
goto err;
parent_node = get_parent(bus_node);
if (!parent_node)
goto err;
dt_get_reg_format(parent_node, &naddr, &nsize);
if (naddr != 1 || nsize != 1)
goto err;
if (!dt_xlate_reg(bus_node, 0, (unsigned long *)&ctrl_addr,
&ctrl_size))
goto err;
len = getprop(bus_node, "ranges", cs_ranges_buf, sizeof(cs_ranges_buf));
for (i = 0; i < len / sizeof(struct cs_range); i++) {
u32 base, option;
int cs = cs_ranges_buf[i].csnum;
if (cs >= ctrl_size / 8)
goto err;
if (cs_ranges_buf[i].base != 0)
goto err;
base = in_be32(&ctrl_addr[cs * 2]);
if (base & 1) {
base &= 0x7fff;
option = in_be32(&ctrl_addr[cs * 2 + 1]) & 0x7fff;
} else {
base = 0x1801;
option = 0x10;
}
out_be32(&ctrl_addr[cs * 2], 0);
out_be32(&ctrl_addr[cs * 2 + 1],
option | ~(cs_ranges_buf[i].size - 1));
out_be32(&ctrl_addr[cs * 2], base | cs_ranges_buf[i].addr);
}
return;
err:
printf("Bad /localbus node\r\n");
}
static void fixup_pci(void)
{
struct pci_range *mem = NULL, *mmio = NULL,
*io = NULL, *mem_base = NULL;
u32 *pci_regs[3];
u8 *soc_regs;
int i, len;
void *node, *parent_node;
u32 naddr, nsize, mem_pow2, mem_mask;
node = finddevice("/pci");
if (!node || !dt_is_compatible(node, "fsl,pq2-pci"))
return;
for (i = 0; i < 3; i++)
if (!dt_xlate_reg(node, i,
(unsigned long *)&pci_regs[i], NULL))
goto err;
soc_regs = (u8 *)fsl_get_immr();
if (!soc_regs)
goto unhandled;
dt_get_reg_format(node, &naddr, &nsize);
if (naddr != 3 || nsize != 2)
goto err;
parent_node = get_parent(node);
if (!parent_node)
goto err;
dt_get_reg_format(parent_node, &naddr, &nsize);
if (naddr != 1 || nsize != 1)
goto unhandled;
len = getprop(node, "ranges", pci_ranges_buf,
sizeof(pci_ranges_buf));
for (i = 0; i < len / sizeof(struct pci_range); i++) {
u32 flags = pci_ranges_buf[i].flags & 0x43000000;
if (flags == 0x42000000)
mem = &pci_ranges_buf[i];
else if (flags == 0x02000000)
mmio = &pci_ranges_buf[i];
else if (flags == 0x01000000)
io = &pci_ranges_buf[i];
}
if (!mem || !mmio || !io)
goto unhandled;
if (mem->size[1] != mmio->size[1])
goto unhandled;
if (mem->size[1] & (mem->size[1] - 1))
goto unhandled;
if (io->size[1] & (io->size[1] - 1))
goto unhandled;
if (mem->phys_addr + mem->size[1] == mmio->phys_addr)
mem_base = mem;
else if (mmio->phys_addr + mmio->size[1] == mem->phys_addr)
mem_base = mmio;
else
goto unhandled;
out_be32(&pci_regs[1][0], mem_base->phys_addr | 1);
out_be32(&pci_regs[2][0], ~(mem->size[1] + mmio->size[1] - 1));
out_be32(&pci_regs[1][1], io->phys_addr | 1);
out_be32(&pci_regs[2][1], ~(io->size[1] - 1));
out_le32(&pci_regs[0][0], mem->pci_addr[1] >> 12);
out_le32(&pci_regs[0][2], mem->phys_addr >> 12);
out_le32(&pci_regs[0][4], (~(mem->size[1] - 1) >> 12) | 0xa0000000);
out_le32(&pci_regs[0][6], mmio->pci_addr[1] >> 12);
out_le32(&pci_regs[0][8], mmio->phys_addr >> 12);
out_le32(&pci_regs[0][10], (~(mmio->size[1] - 1) >> 12) | 0x80000000);
out_le32(&pci_regs[0][12], io->pci_addr[1] >> 12);
out_le32(&pci_regs[0][14], io->phys_addr >> 12);
out_le32(&pci_regs[0][16], (~(io->size[1] - 1) >> 12) | 0xc0000000);
out_le32(&pci_regs[0][58], 0);
out_le32(&pci_regs[0][60], 0);
mem_pow2 = 1 << (__ilog2_u32(bd.bi_memsize - 1) + 1);
mem_mask = ~(mem_pow2 - 1) >> 12;
out_le32(&pci_regs[0][62], 0xa0000000 | mem_mask);
if (!(in_le32(&pci_regs[0][32]) & 1)) {
udelay(100000);
out_le32(&pci_regs[0][32], 1);
udelay(1020000);
}
out_le32(&pci_regs[0][64], 0x80000004);
out_le32(&pci_regs[0][65], in_le32(&pci_regs[0][65]) | 6);
out_8(&soc_regs[0x10028], 3);
out_be32((u32 *)&soc_regs[0x1002c], 0x01236745);
return;
err:
printf("Bad PCI node -- using existing firmware setup.\r\n");
return;
unhandled:
printf("Unsupported PCI node -- using existing firmware setup.\r\n");
}
static void pq2_platform_fixups(void)
{
void *node;
dt_fixup_memory(bd.bi_memstart, bd.bi_memsize);
dt_fixup_mac_addresses(bd.bi_enetaddr, bd.bi_enet1addr);
dt_fixup_cpu_clocks(bd.bi_intfreq, bd.bi_busfreq / 4, bd.bi_busfreq);
node = finddevice("/soc/cpm");
if (node)
setprop(node, "clock-frequency", &bd.bi_cpmfreq, 4);
node = finddevice("/soc/cpm/brg");
if (node)
setprop(node, "clock-frequency", &bd.bi_brgfreq, 4);
update_cs_ranges();
fixup_pci();
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
fdt_init(_dtb_start);
serial_console_init();
platform_ops.fixups = pq2_platform_fixups;
}
