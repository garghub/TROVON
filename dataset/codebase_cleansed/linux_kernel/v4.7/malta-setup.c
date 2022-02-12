const char *get_system_type(void)
{
return "MIPS Malta";
}
static void __init fd_activate(void)
{
SMSC_WRITE(SMSC_CONFIG_ENTER, SMSC_CONFIG_REG);
SMSC_WRITE(SMSC_CONFIG_DEVNUM, SMSC_CONFIG_REG);
SMSC_WRITE(SMSC_CONFIG_DEVNUM_FLOPPY, SMSC_DATA_REG);
SMSC_WRITE(SMSC_CONFIG_ACTIVATE, SMSC_CONFIG_REG);
SMSC_WRITE(SMSC_CONFIG_ACTIVATE_ENABLE, SMSC_DATA_REG);
SMSC_WRITE(SMSC_CONFIG_EXIT, SMSC_CONFIG_REG);
}
static int __init plat_enable_iocoherency(void)
{
int supported = 0;
if (mips_revision_sconid == MIPS_REVISION_SCON_BONITO) {
if (BONITO_PCICACHECTRL & BONITO_PCICACHECTRL_CPUCOH_PRES) {
BONITO_PCICACHECTRL |= BONITO_PCICACHECTRL_CPUCOH_EN;
pr_info("Enabled Bonito CPU coherency\n");
supported = 1;
}
if (strstr(fw_getcmdline(), "iobcuncached")) {
BONITO_PCICACHECTRL &= ~BONITO_PCICACHECTRL_IOBCCOH_EN;
BONITO_PCIMEMBASECFG = BONITO_PCIMEMBASECFG &
~(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
pr_info("Disabled Bonito IOBC coherency\n");
} else {
BONITO_PCICACHECTRL |= BONITO_PCICACHECTRL_IOBCCOH_EN;
BONITO_PCIMEMBASECFG |=
(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
pr_info("Enabled Bonito IOBC coherency\n");
}
} else if (mips_cm_numiocu() != 0) {
pr_info("CMP IOCU detected\n");
if ((*(unsigned int *)0xbf403000 & 0x81) != 0x81) {
pr_crit("IOCU OPERATION DISABLED BY SWITCH - DEFAULTING TO SW IO COHERENCY\n");
return 0;
}
supported = 1;
}
hw_coherentio = supported;
return supported;
}
static void __init plat_setup_iocoherency(void)
{
#ifdef CONFIG_DMA_NONCOHERENT
if (plat_enable_iocoherency()) {
if (coherentio == 0)
pr_info("Hardware DMA cache coherency disabled\n");
else
pr_info("Hardware DMA cache coherency enabled\n");
} else {
if (coherentio == 1)
pr_info("Hardware DMA cache coherency unsupported, but enabled from command line!\n");
else
pr_info("Software DMA cache coherency enabled\n");
}
#else
if (!plat_enable_iocoherency())
panic("Hardware DMA cache coherency not supported!");
#endif
}
static void __init pci_clock_check(void)
{
unsigned int __iomem *jmpr_p =
(unsigned int *) ioremap(MALTA_JMPRS_REG, sizeof(unsigned int));
int jmpr = (__raw_readl(jmpr_p) >> 2) & 0x07;
static const int pciclocks[] __initconst = {
33, 20, 25, 30, 12, 16, 37, 10
};
int pciclock = pciclocks[jmpr];
char *optptr, *argptr = fw_getcmdline();
optptr = strstr(argptr, "pci_clock=");
if (optptr && (optptr == argptr || optptr[-1] == ' '))
return;
if (pciclock != 33) {
pr_warn("WARNING: PCI clock is %dMHz, setting pci_clock\n",
pciclock);
argptr += strlen(argptr);
sprintf(argptr, " pci_clock=%d", pciclock);
if (pciclock < 20 || pciclock > 66)
pr_warn("WARNING: IDE timing calculations will be "
"incorrect\n");
}
}
static void __init screen_info_setup(void)
{
screen_info = (struct screen_info) {
.orig_x = 0,
.orig_y = 25,
.ext_mem_k = 0,
.orig_video_page = 0,
.orig_video_mode = 0,
.orig_video_cols = 80,
.unused2 = 0,
.orig_video_ega_bx = 0,
.unused3 = 0,
.orig_video_lines = 25,
.orig_video_isVGA = VIDEO_TYPE_VGAC,
.orig_video_points = 16
};
}
static void __init bonito_quirks_setup(void)
{
char *argptr;
argptr = fw_getcmdline();
if (strstr(argptr, "debug")) {
BONITO_BONGENCFG |= BONITO_BONGENCFG_DEBUGMODE;
pr_info("Enabled Bonito debug mode\n");
} else
BONITO_BONGENCFG &= ~BONITO_BONGENCFG_DEBUGMODE;
#ifdef CONFIG_DMA_COHERENT
if (BONITO_PCICACHECTRL & BONITO_PCICACHECTRL_CPUCOH_PRES) {
BONITO_PCICACHECTRL |= BONITO_PCICACHECTRL_CPUCOH_EN;
pr_info("Enabled Bonito CPU coherency\n");
argptr = fw_getcmdline();
if (strstr(argptr, "iobcuncached")) {
BONITO_PCICACHECTRL &= ~BONITO_PCICACHECTRL_IOBCCOH_EN;
BONITO_PCIMEMBASECFG = BONITO_PCIMEMBASECFG &
~(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
pr_info("Disabled Bonito IOBC coherency\n");
} else {
BONITO_PCICACHECTRL |= BONITO_PCICACHECTRL_IOBCCOH_EN;
BONITO_PCIMEMBASECFG |=
(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
pr_info("Enabled Bonito IOBC coherency\n");
}
} else
panic("Hardware DMA cache coherency not supported");
#endif
}
void __init *plat_get_fdt(void)
{
return (void *)__dtb_start;
}
void __init plat_mem_setup(void)
{
unsigned int i;
void *fdt = plat_get_fdt();
fdt = malta_dt_shim(fdt);
__dt_setup_arch(fdt);
if (config_enabled(CONFIG_EVA))
pr_info("Enhanced Virtual Addressing (EVA) activated\n");
mips_pcibios_init();
for (i = 0; i < ARRAY_SIZE(standard_io_resources); i++)
request_resource(&ioport_resource, standard_io_resources+i);
enable_dma(4);
#ifdef CONFIG_DMA_COHERENT
if (mips_revision_sconid != MIPS_REVISION_SCON_BONITO)
panic("Hardware DMA cache coherency not supported");
#endif
if (mips_revision_sconid == MIPS_REVISION_SCON_BONITO)
bonito_quirks_setup();
plat_setup_iocoherency();
pci_clock_check();
#ifdef CONFIG_BLK_DEV_FD
fd_activate();
#endif
#if defined(CONFIG_VT) && defined(CONFIG_VGA_CONSOLE)
screen_info_setup();
#endif
board_be_init = malta_be_init;
board_be_handler = malta_be_handler;
}
