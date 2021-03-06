char *prom_getenv(char *envname)
{
int i, index=0;
i = strlen(envname);
while (prom_envp(index)) {
if(strncmp(envname, prom_envp(index), i) == 0) {
return(prom_envp(index+1));
}
index += 2;
}
return NULL;
}
static inline unsigned char str2hexnum(unsigned char c)
{
if (c >= '0' && c <= '9')
return c - '0';
if (c >= 'a' && c <= 'f')
return c - 'a' + 10;
return 0;
}
static inline void str2eaddr(unsigned char *ea, unsigned char *str)
{
int i;
for (i = 0; i < 6; i++) {
unsigned char num;
if((*str == '.') || (*str == ':'))
str++;
num = str2hexnum(*str++) << 4;
num |= (str2hexnum(*str++));
ea[i] = num;
}
}
int get_ethernet_addr(char *ethernet_addr)
{
char *ethaddr_str;
ethaddr_str = prom_getenv("ethaddr");
if (!ethaddr_str) {
printk("ethaddr not set in boot prom\n");
return -1;
}
str2eaddr(ethernet_addr, ethaddr_str);
if (init_debug > 1) {
int i;
printk("get_ethernet_addr: ");
for (i=0; i<5; i++)
printk("%02x:", (unsigned char)*(ethernet_addr+i));
printk("%02x\n", *(ethernet_addr+i));
}
return 0;
}
static void __init console_config(void)
{
char console_string[40];
int baud = 0;
char parity = '\0', bits = '\0', flow = '\0';
char *s;
if ((strstr(prom_getcmdline(), "console=")) == NULL) {
s = prom_getenv("modetty0");
if (s) {
while (*s >= '0' && *s <= '9')
baud = baud*10 + *s++ - '0';
if (*s == ',') s++;
if (*s) parity = *s++;
if (*s == ',') s++;
if (*s) bits = *s++;
if (*s == ',') s++;
if (*s == 'h') flow = 'r';
}
if (baud == 0)
baud = 38400;
if (parity != 'n' && parity != 'o' && parity != 'e')
parity = 'n';
if (bits != '7' && bits != '8')
bits = '8';
if (flow == '\0')
flow = 'r';
sprintf(console_string, " console=ttyS0,%d%c%c%c", baud, parity, bits, flow);
strcat(prom_getcmdline(), console_string);
pr_info("Config serial console:%s\n", console_string);
}
}
static void __init mips_nmi_setup(void)
{
void *base;
extern char except_vec_nmi;
base = cpu_has_veic ?
(void *)(CAC_BASE + 0xa80) :
(void *)(CAC_BASE + 0x380);
memcpy(base, &except_vec_nmi, 0x80);
flush_icache_range((unsigned long)base, (unsigned long)base + 0x80);
}
static void __init mips_ejtag_setup(void)
{
void *base;
extern char except_vec_ejtag_debug;
base = cpu_has_veic ?
(void *)(CAC_BASE + 0xa00) :
(void *)(CAC_BASE + 0x300);
memcpy(base, &except_vec_ejtag_debug, 0x80);
flush_icache_range((unsigned long)base, (unsigned long)base + 0x80);
}
void __init prom_init(void)
{
prom_argc = fw_arg0;
_prom_argv = (int *) fw_arg1;
_prom_envp = (int *) fw_arg2;
mips_display_message("LINUX");
_pcictrl_bonito = (unsigned long)ioremap(BONITO_REG_BASE, BONITO_REG_SIZE);
mips_revision_corid = MIPS_REVISION_CORID;
if (mips_revision_corid == MIPS_REVISION_CORID_CORE_EMUL) {
if (BONITO_PCIDID == 0x0001df53 ||
BONITO_PCIDID == 0x0003df53)
mips_revision_corid = MIPS_REVISION_CORID_CORE_EMUL_BON;
else
mips_revision_corid = MIPS_REVISION_CORID_CORE_EMUL_MSC;
}
mips_revision_sconid = MIPS_REVISION_SCONID;
if (mips_revision_sconid == MIPS_REVISION_SCON_OTHER) {
switch (mips_revision_corid) {
case MIPS_REVISION_CORID_QED_RM5261:
case MIPS_REVISION_CORID_CORE_LV:
case MIPS_REVISION_CORID_CORE_FPGA:
case MIPS_REVISION_CORID_CORE_FPGAR2:
mips_revision_sconid = MIPS_REVISION_SCON_GT64120;
break;
case MIPS_REVISION_CORID_CORE_EMUL_BON:
case MIPS_REVISION_CORID_BONITO64:
case MIPS_REVISION_CORID_CORE_20K:
mips_revision_sconid = MIPS_REVISION_SCON_BONITO;
break;
case MIPS_REVISION_CORID_CORE_MSC:
case MIPS_REVISION_CORID_CORE_FPGA2:
case MIPS_REVISION_CORID_CORE_24K:
mips_revision_sconid = MIPS_REVISION_SCON_SOCIT;
break;
case MIPS_REVISION_CORID_CORE_FPGA3:
case MIPS_REVISION_CORID_CORE_FPGA4:
case MIPS_REVISION_CORID_CORE_FPGA5:
case MIPS_REVISION_CORID_CORE_EMUL_MSC:
default:
mips_revision_sconid = MIPS_REVISION_SCON_ROCIT;
break;
}
}
switch (mips_revision_sconid) {
u32 start, map, mask, data;
case MIPS_REVISION_SCON_GT64120:
_pcictrl_gt64120 = (unsigned long)ioremap(MIPS_GT_BASE, 0x2000);
#ifdef CONFIG_CPU_LITTLE_ENDIAN
GT_WRITE(GT_PCI0_CMD_OFS, GT_PCI0_CMD_MBYTESWAP_BIT |
GT_PCI0_CMD_SBYTESWAP_BIT);
#else
GT_WRITE(GT_PCI0_CMD_OFS, 0);
#endif
start = GT_READ(GT_PCI0IOLD_OFS);
map = GT_READ(GT_PCI0IOREMAP_OFS);
if ((start & map) != 0) {
map &= ~start;
GT_WRITE(GT_PCI0IOREMAP_OFS, map);
}
set_io_port_base(MALTA_GT_PORT_BASE);
break;
case MIPS_REVISION_SCON_BONITO:
_pcictrl_bonito_pcicfg = (unsigned long)ioremap(BONITO_PCICFG_BASE, BONITO_PCICFG_SIZE);
BONITO_PCIMEMBASECFG = BONITO_PCIMEMBASECFG &
~(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
#ifdef CONFIG_CPU_LITTLE_ENDIAN
BONITO_BONGENCFG = BONITO_BONGENCFG &
~(BONITO_BONGENCFG_MSTRBYTESWAP |
BONITO_BONGENCFG_BYTESWAP);
#else
BONITO_BONGENCFG = BONITO_BONGENCFG |
BONITO_BONGENCFG_MSTRBYTESWAP |
BONITO_BONGENCFG_BYTESWAP;
#endif
set_io_port_base(MALTA_BONITO_PORT_BASE);
break;
case MIPS_REVISION_SCON_SOCIT:
case MIPS_REVISION_SCON_ROCIT:
_pcictrl_msc = (unsigned long)ioremap(MIPS_MSC01_PCI_REG_BASE, 0x2000);
mips_pci_controller:
mb();
MSC_READ(MSC01_PCI_CFG, data);
MSC_WRITE(MSC01_PCI_CFG, data & ~MSC01_PCI_CFG_EN_BIT);
wmb();
#ifdef CONFIG_CPU_LITTLE_ENDIAN
MSC_WRITE(MSC01_PCI_SWAP, MSC01_PCI_SWAP_NOSWAP);
#else
MSC_WRITE(MSC01_PCI_SWAP,
MSC01_PCI_SWAP_BYTESWAP << MSC01_PCI_SWAP_IO_SHF |
MSC01_PCI_SWAP_BYTESWAP << MSC01_PCI_SWAP_MEM_SHF |
MSC01_PCI_SWAP_BYTESWAP << MSC01_PCI_SWAP_BAR0_SHF);
#endif
MSC_READ(MSC01_PCI_BAR0, mask);
MSC_WRITE(MSC01_PCI_P2SCMSKL, mask & MSC01_PCI_BAR0_SIZE_MSK);
if ((data & MSC01_PCI_CFG_MAXRTRY_MSK) ==
MSC01_PCI_CFG_MAXRTRY_MSK)
data = (data & ~(MSC01_PCI_CFG_MAXRTRY_MSK <<
MSC01_PCI_CFG_MAXRTRY_SHF)) |
((MSC01_PCI_CFG_MAXRTRY_MSK - 1) <<
MSC01_PCI_CFG_MAXRTRY_SHF);
wmb();
MSC_WRITE(MSC01_PCI_CFG, data);
mb();
set_io_port_base(MALTA_MSC_PORT_BASE);
break;
case MIPS_REVISION_SCON_SOCITSC:
case MIPS_REVISION_SCON_SOCITSCP:
_pcictrl_msc = (unsigned long)ioremap(MIPS_SOCITSC_PCI_REG_BASE, 0x2000);
goto mips_pci_controller;
default:
mips_display_message("SC Error");
while (1);
}
board_nmi_handler_setup = mips_nmi_setup;
board_ejtag_handler_setup = mips_ejtag_setup;
prom_init_cmdline();
prom_meminit();
#ifdef CONFIG_SERIAL_8250_CONSOLE
console_config();
#endif
#ifdef CONFIG_MIPS_CMP
if (gcmp_probe(GCMP_BASE_ADDR, GCMP_ADDRSPACE_SZ))
register_smp_ops(&cmp_smp_ops);
else
#endif
#ifdef CONFIG_MIPS_MT_SMP
register_smp_ops(&vsmp_smp_ops);
#endif
#ifdef CONFIG_MIPS_MT_SMTC
register_smp_ops(&msmtc_smp_ops);
#endif
}
