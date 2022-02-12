static unsigned long __init SMCConfigState(unsigned long baseAddr)
{
unsigned char devId;
unsigned long configPort;
unsigned long indexPort;
unsigned long dataPort;
int i;
configPort = indexPort = baseAddr;
dataPort = configPort + 1;
#define NUM_RETRIES 5
for (i = 0; i < NUM_RETRIES; i++)
{
outb(CONFIG_ON_KEY, configPort);
outb(CONFIG_ON_KEY, configPort);
outb(DEVICE_ID, indexPort);
devId = inb(dataPort);
if (devId == VALID_DEVICE_ID) {
outb(DEVICE_REV, indexPort);
inb(dataPort);
break;
}
else
udelay(100);
}
return (i != NUM_RETRIES) ? baseAddr : 0L;
}
static void __init SMCRunState(unsigned long baseAddr)
{
outb(CONFIG_OFF_KEY, baseAddr);
}
static unsigned long __init SMCDetectUltraIO(void)
{
unsigned long baseAddr;
baseAddr = 0x3F0;
if ( ( baseAddr = SMCConfigState( baseAddr ) ) == 0x3F0 ) {
return( baseAddr );
}
baseAddr = 0x370;
if ( ( baseAddr = SMCConfigState( baseAddr ) ) == 0x370 ) {
return( baseAddr );
}
return( ( unsigned long )0 );
}
static void __init SMCEnableDevice(unsigned long baseAddr,
unsigned long device,
unsigned long portaddr,
unsigned long interrupt)
{
unsigned long indexPort;
unsigned long dataPort;
indexPort = baseAddr;
dataPort = baseAddr + 1;
outb(LOGICAL_DEVICE_NUMBER, indexPort);
outb(device, dataPort);
outb(ADDR_LO, indexPort);
outb(( portaddr & 0xFF ), dataPort);
outb(ADDR_HI, indexPort);
outb((portaddr >> 8) & 0xFF, dataPort);
outb(INTERRUPT_SEL, indexPort);
outb(interrupt, dataPort);
outb(ACTIVATE, indexPort);
outb(DEVICE_ON, dataPort);
}
static void __init SMCEnableKYBD(unsigned long baseAddr)
{
unsigned long indexPort;
unsigned long dataPort;
indexPort = baseAddr;
dataPort = baseAddr + 1;
outb(LOGICAL_DEVICE_NUMBER, indexPort);
outb(KYBD, dataPort);
outb(INTERRUPT_SEL, indexPort);
outb(KYBD_INTERRUPT, dataPort);
outb(INTERRUPT_SEL_2, indexPort);
outb(MOUS_INTERRUPT, dataPort);
outb(ACTIVATE, indexPort);
outb(DEVICE_ON, dataPort);
}
static void __init SMCEnableFDC(unsigned long baseAddr)
{
unsigned long indexPort;
unsigned long dataPort;
unsigned char oldValue;
indexPort = baseAddr;
dataPort = baseAddr + 1;
outb(LOGICAL_DEVICE_NUMBER, indexPort);
outb(FDC, dataPort);
outb(FDD_MODE_REGISTER, indexPort);
oldValue = inb(dataPort);
oldValue |= 0x0E;
outb(oldValue, dataPort);
outb(INTERRUPT_SEL, indexPort);
outb(0x06, dataPort );
outb(DMA_CHANNEL_SEL, indexPort);
outb(0x02, dataPort);
outb(ACTIVATE, indexPort);
outb(DEVICE_ON, dataPort);
}
static void __init SMCReportDeviceStatus(unsigned long baseAddr)
{
unsigned long indexPort;
unsigned long dataPort;
unsigned char currentControl;
indexPort = baseAddr;
dataPort = baseAddr + 1;
outb(POWER_CONTROL, indexPort);
currentControl = inb(dataPort);
printk(currentControl & (1 << FDC)
? "\t+FDC Enabled\n" : "\t-FDC Disabled\n");
printk(currentControl & (1 << IDE1)
? "\t+IDE1 Enabled\n" : "\t-IDE1 Disabled\n");
printk(currentControl & (1 << IDE2)
? "\t+IDE2 Enabled\n" : "\t-IDE2 Disabled\n");
printk(currentControl & (1 << PARP)
? "\t+PARP Enabled\n" : "\t-PARP Disabled\n");
printk(currentControl & (1 << SER1)
? "\t+SER1 Enabled\n" : "\t-SER1 Disabled\n");
printk(currentControl & (1 << SER2)
? "\t+SER2 Enabled\n" : "\t-SER2 Disabled\n");
printk( "\n" );
}
int __init SMC93x_Init(void)
{
unsigned long SMCUltraBase;
unsigned long flags;
local_irq_save(flags);
if ((SMCUltraBase = SMCDetectUltraIO()) != 0UL) {
#if SMC_DEBUG
SMCReportDeviceStatus(SMCUltraBase);
#endif
SMCEnableDevice(SMCUltraBase, SER1, COM1_BASE, COM1_INTERRUPT);
DBG_DEVS(("SMC FDC37C93X: SER1 done\n"));
SMCEnableDevice(SMCUltraBase, SER2, COM2_BASE, COM2_INTERRUPT);
DBG_DEVS(("SMC FDC37C93X: SER2 done\n"));
SMCEnableDevice(SMCUltraBase, PARP, PARP_BASE, PARP_INTERRUPT);
DBG_DEVS(("SMC FDC37C93X: PARP done\n"));
SMCEnableKYBD(SMCUltraBase);
DBG_DEVS(("SMC FDC37C93X: KYB done\n"));
SMCEnableFDC(SMCUltraBase);
DBG_DEVS(("SMC FDC37C93X: FDC done\n"));
#if SMC_DEBUG
SMCReportDeviceStatus(SMCUltraBase);
#endif
SMCRunState(SMCUltraBase);
local_irq_restore(flags);
printk("SMC FDC37C93X Ultra I/O Controller found @ 0x%lx\n",
SMCUltraBase);
return 1;
}
else {
local_irq_restore(flags);
DBG_DEVS(("No SMC FDC37C93X Ultra I/O Controller found\n"));
return 0;
}
}
