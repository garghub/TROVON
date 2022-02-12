u32 mv64x60_cfg_read(u8 *bridge_base, u8 hose, u8 bus, u8 devfn, u8 offset)
{
out_le32((u32 *)(bridge_base + mv64x60_pci_cfgio[hose].addr),
(1 << 31) | (bus << 16) | (devfn << 8) | offset);
return in_le32((u32 *)(bridge_base + mv64x60_pci_cfgio[hose].data));
}
void mv64x60_cfg_write(u8 *bridge_base, u8 hose, u8 bus, u8 devfn, u8 offset,
u32 val)
{
out_le32((u32 *)(bridge_base + mv64x60_pci_cfgio[hose].addr),
(1 << 31) | (bus << 16) | (devfn << 8) | offset);
out_le32((u32 *)(bridge_base + mv64x60_pci_cfgio[hose].data), val);
}
void mv64x60_config_ctlr_windows(u8 *bridge_base, u8 *bridge_pbase,
u8 is_coherent)
{
u32 i, base, size, enables, prot = 0, snoop_bits = 0;
out_le32((u32 *)(bridge_base + MV64x60_ENET2MEM_BAR_ENABLE), 0x3f);
out_le32((u32 *)(bridge_base + MV64x60_MPSC2MEM_BAR_ENABLE), 0xf);
out_le32((u32 *)(bridge_base + MV64x60_ENET2MEM_BAR_ENABLE), 0xff);
if (is_coherent)
snoop_bits = 0x2 << 12;
enables = in_le32((u32 *)(bridge_base + MV64x60_CPU_BAR_ENABLE)) & 0xf;
for (i=0; i<MV64x60_CPU2MEM_WINDOWS; i++) {
if (enables & (1 << i))
continue;
base = in_le32((u32 *)(bridge_base + mv64x60_cpu2mem[i].lo))
<< 16;
base |= snoop_bits | (mv64x60_dram_selects[i] << 8);
size = in_le32((u32 *)(bridge_base + mv64x60_cpu2mem[i].size))
<< 16;
prot |= (0x3 << (i << 1));
out_le32((u32 *)(bridge_base + mv64x60_enet2mem[i].lo), base);
out_le32((u32 *)(bridge_base + mv64x60_enet2mem[i].size), size);
out_le32((u32 *)(bridge_base + mv64x60_mpsc2mem[i].lo), base);
out_le32((u32 *)(bridge_base + mv64x60_mpsc2mem[i].size), size);
out_le32((u32 *)(bridge_base + mv64x60_idma2mem[i].lo), base);
out_le32((u32 *)(bridge_base + mv64x60_idma2mem[i].size), size);
}
out_le32((u32 *)(bridge_base + MV64x60_ENET2MEM_ACC_PROT_0), prot);
out_le32((u32 *)(bridge_base + MV64x60_ENET2MEM_ACC_PROT_1), prot);
out_le32((u32 *)(bridge_base + MV64x60_ENET2MEM_ACC_PROT_2), prot);
out_le32((u32 *)(bridge_base + MV64x60_MPSC2MEM_ACC_PROT_0), prot);
out_le32((u32 *)(bridge_base + MV64x60_MPSC2MEM_ACC_PROT_1), prot);
out_le32((u32 *)(bridge_base + MV64x60_IDMA2MEM_ACC_PROT_0), prot);
out_le32((u32 *)(bridge_base + MV64x60_IDMA2MEM_ACC_PROT_1), prot);
out_le32((u32 *)(bridge_base + MV64x60_IDMA2MEM_ACC_PROT_2), prot);
out_le32((u32 *)(bridge_base + MV64x60_IDMA2MEM_ACC_PROT_3), prot);
out_le32((u32 *)(bridge_base + MV64x60_MPSC2REGS_BASE),
(u32)bridge_pbase);
out_le32((u32 *)(bridge_base + MV64x60_ENET2MEM_BAR_ENABLE), enables);
out_le32((u32 *)(bridge_base + MV64x60_MPSC2MEM_BAR_ENABLE), enables);
out_le32((u32 *)(bridge_base + MV64x60_IDMA2MEM_BAR_ENABLE), enables);
}
void mv64x60_config_pci_windows(u8 *bridge_base, u8 *bridge_pbase, u8 hose,
u8 bus, u32 mem_size, u32 acc_bits)
{
u32 i, offset, bar_enable, enables;
enables = ~(1 << 9);
bar_enable = hose ? MV64x60_PCI1_BAR_ENABLE : MV64x60_PCI0_BAR_ENABLE;
out_le32((u32 *)(bridge_base + bar_enable), enables);
for (i=0; i<MV64x60_PCI_ACC_CNTL_WINDOWS; i++)
out_le32((u32 *)(bridge_base + mv64x60_pci_acc[hose][i].lo), 0);
if (mem_size == 0)
return;
offset = hose ?
MV64x60_PCI1_PCI_DECODE_CNTL : MV64x60_PCI0_PCI_DECODE_CNTL;
i = in_le32((u32 *)(bridge_base + offset));
out_le32((u32 *)(bridge_base + offset), i & ~0x1);
mem_size = (mem_size - 1) & 0xfffff000;
mv64x60_cfg_write(bridge_base, hose, bus,
PCI_DEVFN(0, mv64x60_pci2mem[hose].fcn),
mv64x60_pci2mem[hose].hi, 0);
mv64x60_cfg_write(bridge_base, hose, bus,
PCI_DEVFN(0, mv64x60_pci2mem[hose].fcn),
mv64x60_pci2mem[hose].lo, 0);
out_le32((u32 *)(bridge_base + mv64x60_pci2mem[hose].size),mem_size);
acc_bits |= MV64x60_PCI_ACC_CNTL_ENABLE;
out_le32((u32 *)(bridge_base + mv64x60_pci_acc[hose][0].hi), 0);
out_le32((u32 *)(bridge_base + mv64x60_pci_acc[hose][0].lo), acc_bits);
out_le32((u32 *)(bridge_base + mv64x60_pci_acc[hose][0].size),mem_size);
i = (u32)bridge_base;
i &= 0xffff0000;
i |= (0x2 << 1);
mv64x60_cfg_write(bridge_base, hose, bus, PCI_DEVFN(0,0),
mv64x60_pci2reg[hose].hi, 0);
mv64x60_cfg_write(bridge_base, hose, bus, PCI_DEVFN(0,0),
mv64x60_pci2reg[hose].lo, i);
enables &= ~0x1;
out_le32((u32 *)(bridge_base + bar_enable), enables);
}
void mv64x60_config_cpu2pci_window(u8 *bridge_base, u8 hose, u32 pci_base_hi,
u32 pci_base_lo, u32 cpu_base, u32 size,
struct mv64x60_cpu2pci_win *offset_tbl)
{
cpu_base >>= 16;
cpu_base |= MV64x60_CPU2PCI_SWAP_NONE;
out_le32((u32 *)(bridge_base + offset_tbl[hose].lo), cpu_base);
if (offset_tbl[hose].remap_hi != 0)
out_le32((u32 *)(bridge_base + offset_tbl[hose].remap_hi),
pci_base_hi);
out_le32((u32 *)(bridge_base + offset_tbl[hose].remap_lo),
pci_base_lo >> 16);
size = (size - 1) >> 16;
out_le32((u32 *)(bridge_base + offset_tbl[hose].size), size);
}
u32 mv64x60_get_mem_size(u8 *bridge_base)
{
u32 enables, i, v;
u32 mem = 0;
enables = in_le32((u32 *)(bridge_base + MV64x60_CPU_BAR_ENABLE)) & 0xf;
for (i=0; i<MV64x60_CPU2MEM_WINDOWS; i++)
if (!(enables & (1<<i))) {
v = in_le32((u32*)(bridge_base
+ mv64x60_cpu2mem[i].size));
v = ((v & 0xffff) + 1) << 16;
mem += v;
}
return mem;
}
u8 *mv64x60_get_bridge_pbase(void)
{
u32 v[2];
void *devp;
devp = find_node_by_compatible(NULL, "marvell,mv64360");
if (devp == NULL)
goto err_out;
if (getprop(devp, "reg", v, sizeof(v)) != sizeof(v))
goto err_out;
return (u8 *)v[0];
err_out:
return 0;
}
u8 *mv64x60_get_bridge_base(void)
{
u32 v;
void *devp;
devp = find_node_by_compatible(NULL, "marvell,mv64360");
if (devp == NULL)
goto err_out;
if (getprop(devp, "virtual-reg", &v, sizeof(v)) != sizeof(v))
goto err_out;
return (u8 *)v;
err_out:
return 0;
}
u8 mv64x60_is_coherent(void)
{
u32 v;
void *devp;
devp = finddevice("/");
if (devp == NULL)
return 1;
if (getprop(devp, "coherency-off", &v, sizeof(v)) < 0)
return 1;
else
return 0;
}
