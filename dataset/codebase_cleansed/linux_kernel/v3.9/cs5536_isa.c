static void divil_lbar_enable(void)
{
u32 hi, lo;
int offset;
for (offset = DIVIL_LBAR_SMB; offset <= DIVIL_LBAR_PMS; offset++) {
_rdmsr(DIVIL_MSR_REG(offset), &hi, &lo);
hi |= 0x01;
_wrmsr(DIVIL_MSR_REG(offset), hi, lo);
}
}
static void divil_lbar_disable(void)
{
u32 hi, lo;
int offset;
for (offset = DIVIL_LBAR_SMB; offset <= DIVIL_LBAR_PMS; offset++) {
_rdmsr(DIVIL_MSR_REG(offset), &hi, &lo);
hi &= ~0x01;
_wrmsr(DIVIL_MSR_REG(offset), hi, lo);
}
}
void pci_isa_write_bar(int n, u32 value)
{
u32 hi = 0, lo = value;
if (value == PCI_BAR_RANGE_MASK) {
_rdmsr(GLCP_MSR_REG(GLCP_SOFT_COM), &hi, &lo);
lo |= soft_bar_flag[n];
_wrmsr(GLCP_MSR_REG(GLCP_SOFT_COM), hi, lo);
} else if (value & 0x01) {
hi = 0x0000f001;
lo &= bar_space_range[n];
_wrmsr(divil_msr_reg[n], hi, lo);
hi = ((value & 0x000ffffc) << 12) |
((bar_space_len[n] - 4) << 12) | 0x01;
lo = ((value & 0x000ffffc) << 12) | 0x01;
_wrmsr(sb_msr_reg[n], hi, lo);
}
}
u32 pci_isa_read_bar(int n)
{
u32 conf_data = 0;
u32 hi, lo;
_rdmsr(GLCP_MSR_REG(GLCP_SOFT_COM), &hi, &lo);
if (lo & soft_bar_flag[n]) {
conf_data = bar_space_range[n] | PCI_BASE_ADDRESS_SPACE_IO;
lo &= ~soft_bar_flag[n];
_wrmsr(GLCP_MSR_REG(GLCP_SOFT_COM), hi, lo);
} else {
_rdmsr(divil_msr_reg[n], &hi, &lo);
conf_data = lo & bar_space_range[n];
conf_data |= 0x01;
conf_data &= ~0x02;
}
return conf_data;
}
void pci_isa_write_reg(int reg, u32 value)
{
u32 hi = 0, lo = value;
u32 temp;
switch (reg) {
case PCI_COMMAND:
if (value & PCI_COMMAND_IO)
divil_lbar_enable();
else
divil_lbar_disable();
break;
case PCI_STATUS:
_rdmsr(SB_MSR_REG(SB_ERROR), &hi, &lo);
temp = lo & 0x0000ffff;
if ((value & PCI_STATUS_SIG_TARGET_ABORT) &&
(lo & SB_TAS_ERR_EN))
temp |= SB_TAS_ERR_FLAG;
if ((value & PCI_STATUS_REC_TARGET_ABORT) &&
(lo & SB_TAR_ERR_EN))
temp |= SB_TAR_ERR_FLAG;
if ((value & PCI_STATUS_REC_MASTER_ABORT)
&& (lo & SB_MAR_ERR_EN))
temp |= SB_MAR_ERR_FLAG;
if ((value & PCI_STATUS_DETECTED_PARITY)
&& (lo & SB_PARE_ERR_EN))
temp |= SB_PARE_ERR_FLAG;
lo = temp;
_wrmsr(SB_MSR_REG(SB_ERROR), hi, lo);
break;
case PCI_CACHE_LINE_SIZE:
value &= 0x0000ff00;
_rdmsr(SB_MSR_REG(SB_CTRL), &hi, &lo);
hi &= 0xffffff00;
hi |= (value >> 8);
_wrmsr(SB_MSR_REG(SB_CTRL), hi, lo);
break;
case PCI_BAR0_REG:
pci_isa_write_bar(0, value);
break;
case PCI_BAR1_REG:
pci_isa_write_bar(1, value);
break;
case PCI_BAR2_REG:
pci_isa_write_bar(2, value);
break;
case PCI_BAR3_REG:
pci_isa_write_bar(3, value);
break;
case PCI_BAR4_REG:
pci_isa_write_bar(4, value);
break;
case PCI_BAR5_REG:
pci_isa_write_bar(5, value);
break;
case PCI_UART1_INT_REG:
_rdmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), &hi, &lo);
lo &= ~(0xf << 24);
if (value)
lo |= (CS5536_UART1_INTR << 24);
_wrmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), hi, lo);
break;
case PCI_UART2_INT_REG:
_rdmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), &hi, &lo);
lo &= ~(0xf << 28);
if (value)
lo |= (CS5536_UART2_INTR << 28);
_wrmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), hi, lo);
break;
case PCI_ISA_FIXUP_REG:
if (value) {
_rdmsr(SB_MSR_REG(SB_ERROR), &hi, &lo);
lo |= 0x00000063;
_wrmsr(SB_MSR_REG(SB_ERROR), hi, lo);
}
default:
break;
}
}
u32 pci_isa_read_reg(int reg)
{
u32 conf_data = 0;
u32 hi, lo;
switch (reg) {
case PCI_VENDOR_ID:
conf_data =
CFG_PCI_VENDOR_ID(CS5536_ISA_DEVICE_ID, CS5536_VENDOR_ID);
break;
case PCI_COMMAND:
_rdmsr(DIVIL_MSR_REG(DIVIL_LBAR_SMB), &hi, &lo);
if (hi & 0x01)
conf_data |= PCI_COMMAND_IO;
break;
case PCI_STATUS:
conf_data |= PCI_STATUS_66MHZ;
conf_data |= PCI_STATUS_DEVSEL_MEDIUM;
conf_data |= PCI_STATUS_FAST_BACK;
_rdmsr(SB_MSR_REG(SB_ERROR), &hi, &lo);
if (lo & SB_TAS_ERR_FLAG)
conf_data |= PCI_STATUS_SIG_TARGET_ABORT;
if (lo & SB_TAR_ERR_FLAG)
conf_data |= PCI_STATUS_REC_TARGET_ABORT;
if (lo & SB_MAR_ERR_FLAG)
conf_data |= PCI_STATUS_REC_MASTER_ABORT;
if (lo & SB_PARE_ERR_FLAG)
conf_data |= PCI_STATUS_DETECTED_PARITY;
break;
case PCI_CLASS_REVISION:
_rdmsr(GLCP_MSR_REG(GLCP_CHIP_REV_ID), &hi, &lo);
conf_data = lo & 0x000000ff;
conf_data |= (CS5536_ISA_CLASS_CODE << 8);
break;
case PCI_CACHE_LINE_SIZE:
_rdmsr(SB_MSR_REG(SB_CTRL), &hi, &lo);
hi &= 0x000000f8;
conf_data = CFG_PCI_CACHE_LINE_SIZE(PCI_BRIDGE_HEADER_TYPE, hi);
break;
case PCI_BAR0_REG:
return pci_isa_read_bar(0);
break;
case PCI_BAR1_REG:
return pci_isa_read_bar(1);
break;
case PCI_BAR2_REG:
return pci_isa_read_bar(2);
break;
case PCI_BAR3_REG:
break;
case PCI_BAR4_REG:
return pci_isa_read_bar(4);
break;
case PCI_BAR5_REG:
return pci_isa_read_bar(5);
break;
case PCI_CARDBUS_CIS:
conf_data = PCI_CARDBUS_CIS_POINTER;
break;
case PCI_SUBSYSTEM_VENDOR_ID:
conf_data =
CFG_PCI_VENDOR_ID(CS5536_ISA_SUB_ID, CS5536_SUB_VENDOR_ID);
break;
case PCI_ROM_ADDRESS:
conf_data = PCI_EXPANSION_ROM_BAR;
break;
case PCI_CAPABILITY_LIST:
conf_data = PCI_CAPLIST_POINTER;
break;
case PCI_INTERRUPT_LINE:
conf_data = CFG_PCI_INTERRUPT_LINE(0x00, 0x00);
break;
default:
break;
}
return conf_data;
}
