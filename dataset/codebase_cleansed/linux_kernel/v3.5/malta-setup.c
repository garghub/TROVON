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
static void __init pci_clock_check(void)
{
unsigned int __iomem *jmpr_p =
(unsigned int *) ioremap(MALTA_JMPRS_REG, sizeof(unsigned int));
int jmpr = (__raw_readl(jmpr_p) >> 2) & 0x07;
static const int pciclocks[] __initconst = {
33, 20, 25, 30, 12, 16, 37, 10
};
int pciclock = pciclocks[jmpr];
char *argptr = prom_getcmdline();
if (pciclock != 33 && !strstr(argptr, "idebus=")) {
printk(KERN_WARNING "WARNING: PCI clock is %dMHz, "
"setting idebus\n", pciclock);
argptr += strlen(argptr);
sprintf(argptr, " idebus=%d", pciclock);
if (pciclock < 20 || pciclock > 66)
printk(KERN_WARNING "WARNING: IDE timing "
"calculations will be incorrect\n");
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
argptr = prom_getcmdline();
if (strstr(argptr, "debug")) {
BONITO_BONGENCFG |= BONITO_BONGENCFG_DEBUGMODE;
printk(KERN_INFO "Enabled Bonito debug mode\n");
} else
BONITO_BONGENCFG &= ~BONITO_BONGENCFG_DEBUGMODE;
#ifdef CONFIG_DMA_COHERENT
if (BONITO_PCICACHECTRL & BONITO_PCICACHECTRL_CPUCOH_PRES) {
BONITO_PCICACHECTRL |= BONITO_PCICACHECTRL_CPUCOH_EN;
printk(KERN_INFO "Enabled Bonito CPU coherency\n");
argptr = prom_getcmdline();
if (strstr(argptr, "iobcuncached")) {
BONITO_PCICACHECTRL &= ~BONITO_PCICACHECTRL_IOBCCOH_EN;
BONITO_PCIMEMBASECFG = BONITO_PCIMEMBASECFG &
~(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
printk(KERN_INFO "Disabled Bonito IOBC coherency\n");
} else {
BONITO_PCICACHECTRL |= BONITO_PCICACHECTRL_IOBCCOH_EN;
BONITO_PCIMEMBASECFG |=
(BONITO_PCIMEMBASECFG_MEMBASE0_CACHED |
BONITO_PCIMEMBASECFG_MEMBASE1_CACHED);
printk(KERN_INFO "Enabled Bonito IOBC coherency\n");
}
} else
panic("Hardware DMA cache coherency not supported");
#endif
}
void __init plat_mem_setup(void)
{
unsigned int i;
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
#ifdef CONFIG_BLK_DEV_IDE
pci_clock_check();
#endif
#ifdef CONFIG_BLK_DEV_FD
fd_activate();
#endif
#if defined(CONFIG_VT) && defined(CONFIG_VGA_CONSOLE)
screen_info_setup();
#endif
board_be_init = malta_be_init;
board_be_handler = malta_be_handler;
}
