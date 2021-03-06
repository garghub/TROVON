static void __init
enable_board( int board_num, unsigned short port )
{
outb( 0xbc + board_num, MASTER_ADDRESS_PTR );
outb( port >> 2, MASTER_ADDRESS_PTR );
}
static void __init
init_board( unsigned short io_port, int irq, int force_irq )
{
unsigned int tmp;
unsigned int pas_irq_code;
outb( 0x30, io_port + P_TIMEOUT_COUNTER_REG );
outb( 0x01, io_port + P_TIMEOUT_STATUS_REG_OFFSET );
outb( 0x01, io_port + WAIT_STATE );
NCR5380_read( RESET_PARITY_INTERRUPT_REG );
pas_irq_code = ( irq < 16 ) ? scsi_irq_translate[irq] : 0;
tmp = inb( io_port + IO_CONFIG_3 );
if( (( tmp & 0x0f ) == pas_irq_code) && pas_irq_code > 0
&& !force_irq )
{
printk( "pas16: WARNING: Can't use same irq as sound "
"driver -- interrupts disabled\n" );
outb( 0x4d, io_port + SYS_CONFIG_4 );
}
else
{
tmp = ( tmp & 0x0f ) | ( pas_irq_code << 4 );
outb( tmp, io_port + IO_CONFIG_3 );
outb( 0x6d, io_port + SYS_CONFIG_4 );
}
}
static int __init
pas16_hw_detect( unsigned short board_num )
{
unsigned char board_rev, tmp;
unsigned short io_port = bases[ board_num ].io_port;
enable_board( board_num, io_port );
board_rev = inb( io_port + PCB_CONFIG );
if( board_rev == 0xff )
return 0;
tmp = board_rev ^ 0xe0;
outb( tmp, io_port + PCB_CONFIG );
tmp = inb( io_port + PCB_CONFIG );
outb( board_rev, io_port + PCB_CONFIG );
if( board_rev != tmp )
return 0;
if( ( inb( io_port + OPERATION_MODE_1 ) & 0x03 ) != 0x03 )
return 0;
outb( 0x01, io_port + WAIT_STATE );
NCR5380_write( MODE_REG, 0x20 );
if( NCR5380_read( MODE_REG ) != 0x20 )
return 0;
NCR5380_write( MODE_REG, 0x00 );
if( NCR5380_read( MODE_REG ) != 0x00 )
return 0;
return 1;
}
static int __init pas16_setup(char *str)
{
static int commandline_current = 0;
int i;
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
if (ints[0] != 2)
printk("pas16_setup : usage pas16=io_port,irq\n");
else
if (commandline_current < NO_OVERRIDES) {
overrides[commandline_current].io_port = (unsigned short) ints[1];
overrides[commandline_current].irq = ints[2];
for (i = 0; i < NO_BASES; ++i)
if (bases[i].io_port == (unsigned short) ints[1]) {
bases[i].noauto = 1;
break;
}
++commandline_current;
}
return 1;
}
static int __init pas16_detect(struct scsi_host_template *tpnt)
{
static int current_override = 0;
static unsigned short current_base = 0;
struct Scsi_Host *instance;
unsigned short io_port;
int count;
if (pas16_addr != 0) {
overrides[0].io_port = pas16_addr;
for (count = 0; count < NO_BASES; ++count)
if (bases[count].io_port == pas16_addr) {
bases[count].noauto = 1;
break;
}
}
if (pas16_irq != 0)
overrides[0].irq = pas16_irq;
for (count = 0; current_override < NO_OVERRIDES; ++current_override) {
io_port = 0;
if (overrides[current_override].io_port)
{
io_port = overrides[current_override].io_port;
enable_board( current_override, io_port );
init_board( io_port, overrides[current_override].irq, 1 );
}
else
for (; !io_port && (current_base < NO_BASES); ++current_base) {
#if (PDEBUG & PDEBUG_INIT)
printk("scsi-pas16 : probing io_port %04x\n", (unsigned int) bases[current_base].io_port);
#endif
if ( !bases[current_base].noauto &&
pas16_hw_detect( current_base ) ){
io_port = bases[current_base].io_port;
init_board( io_port, default_irqs[ current_base ], 0 );
#if (PDEBUG & PDEBUG_INIT)
printk("scsi-pas16 : detected board.\n");
#endif
}
}
#if defined(PDEBUG) && (PDEBUG & PDEBUG_INIT)
printk("scsi-pas16 : io_port = %04x\n", (unsigned int) io_port);
#endif
if (!io_port)
break;
instance = scsi_register (tpnt, sizeof(struct NCR5380_hostdata));
if(instance == NULL)
break;
instance->io_port = io_port;
NCR5380_init(instance, 0);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, PAS16_IRQS);
if (instance->irq == 255)
instance->irq = NO_IRQ;
if (instance->irq != NO_IRQ)
if (request_irq(instance->irq, pas16_intr, 0,
"pas16", instance)) {
printk("scsi%d : IRQ%d not free, interrupts disabled\n",
instance->host_no, instance->irq);
instance->irq = NO_IRQ;
}
if (instance->irq == NO_IRQ) {
printk("scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk("scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
outb( 0x4d, io_port + SYS_CONFIG_4 );
outb( (inb(io_port + IO_CONFIG_3) & 0x0f), io_port + IO_CONFIG_3 );
}
#if defined(PDEBUG) && (PDEBUG & PDEBUG_INIT)
printk("scsi%d : irq = %d\n", instance->host_no, instance->irq);
#endif
++current_override;
++count;
}
return count;
}
static int pas16_biosparam(struct scsi_device *sdev, struct block_device *dev,
sector_t capacity, int *ip)
{
int size = capacity;
ip[0] = 64;
ip[1] = 32;
ip[2] = size >> 11;
if( ip[2] > 1024 ) {
ip[0]=255;
ip[1]=63;
ip[2]=size/(63*255);
if( ip[2] > 1023 )
ip[2] = 1023;
}
return 0;
}
static inline int NCR5380_pread (struct Scsi_Host *instance, unsigned char *dst,
int len) {
register unsigned char *d = dst;
register unsigned short reg = (unsigned short) (instance->io_port +
P_DATA_REG_OFFSET);
register int i = len;
int ii = 0;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
while ( !(inb(instance->io_port + P_STATUS_REG_OFFSET) & P_ST_RDY) )
++ii;
insb( reg, d, i );
if ( inb(instance->io_port + P_TIMEOUT_STATUS_REG_OFFSET) & P_TS_TIM) {
outb( P_TS_CT, instance->io_port + P_TIMEOUT_STATUS_REG_OFFSET);
printk("scsi%d : watchdog timer fired in NCR5380_pread()\n",
instance->host_no);
return -1;
}
if (ii > hostdata->spin_max_r)
hostdata->spin_max_r = ii;
return 0;
}
static inline int NCR5380_pwrite (struct Scsi_Host *instance, unsigned char *src,
int len) {
register unsigned char *s = src;
register unsigned short reg = (instance->io_port + P_DATA_REG_OFFSET);
register int i = len;
int ii = 0;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
while ( !((inb(instance->io_port + P_STATUS_REG_OFFSET)) & P_ST_RDY) )
++ii;
outsb( reg, s, i );
if (inb(instance->io_port + P_TIMEOUT_STATUS_REG_OFFSET) & P_TS_TIM) {
outb( P_TS_CT, instance->io_port + P_TIMEOUT_STATUS_REG_OFFSET);
printk("scsi%d : watchdog timer fired in NCR5380_pwrite()\n",
instance->host_no);
return -1;
}
if (ii > hostdata->spin_max_w)
hostdata->spin_max_w = ii;
return 0;
}
static int pas16_release(struct Scsi_Host *shost)
{
if (shost->irq != NO_IRQ)
free_irq(shost->irq, shost);
NCR5380_exit(shost);
if (shost->io_port && shost->n_io_port)
release_region(shost->io_port, shost->n_io_port);
scsi_unregister(shost);
return 0;
}
