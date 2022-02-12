SMC37c669_CONFIG_REGS * __init SMC37c669_detect( int index )
{
int i;
SMC37c669_DEVICE_ID_REGISTER id;
for ( i = 0; SMC37c669_Addresses[i] != 0; i++ ) {
SMC37c669 = ( SMC37c669_CONFIG_REGS * )SMC37c669_Addresses[i];
SMC37c669_config_mode( TRUE );
id.as_uchar = SMC37c669_read_config( SMC37c669_DEVICE_ID_INDEX );
SMC37c669_config_mode( FALSE );
if ( id.by_field.device_id == SMC37c669_DEVICE_ID ) {
SMC37c669_irq_table = SMC37c669_irq_tables[ index ];
SMC37c669_drq_table = SMC37c669_default_drq_table;
SMC37c669_config_mode( TRUE );
SMC37c669_init_local_config( );
SMC37c669_config_mode( FALSE );
break;
}
else {
SMC37c669 = NULL;
}
}
return SMC37c669;
}
unsigned int __init SMC37c669_enable_device ( unsigned int func )
{
unsigned int ret_val = FALSE;
SMC37c669_config_mode( TRUE );
switch ( func ) {
case SERIAL_0:
{
SMC37c669_SERIAL_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_SERIAL_IRQ_REGISTER irq;
irq.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL_IRQ_INDEX );
irq.by_field.uart1_irq =
SMC37c669_RAW_DEVICE_IRQ(
SMC37c669_xlate_irq( local_config[ func ].irq )
);
SMC37c669_write_config( SMC37c669_SERIAL_IRQ_INDEX, irq.as_uchar );
base_addr.as_uchar = 0;
base_addr.by_field.addr9_3 = local_config[ func ].port1 >> 3;
SMC37c669_write_config(
SMC37c669_SERIAL0_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case SERIAL_1:
{
SMC37c669_SERIAL_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_SERIAL_IRQ_REGISTER irq;
irq.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL_IRQ_INDEX );
irq.by_field.uart2_irq =
SMC37c669_RAW_DEVICE_IRQ(
SMC37c669_xlate_irq( local_config[ func ].irq )
);
SMC37c669_write_config( SMC37c669_SERIAL_IRQ_INDEX, irq.as_uchar );
base_addr.as_uchar = 0;
base_addr.by_field.addr9_3 = local_config[ func ].port1 >> 3;
SMC37c669_write_config(
SMC37c669_SERIAL1_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case PARALLEL_0:
{
SMC37c669_PARALLEL_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_PARALLEL_FDC_IRQ_REGISTER irq;
SMC37c669_PARALLEL_FDC_DRQ_REGISTER drq;
drq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_DRQ_INDEX );
drq.by_field.ppt_drq =
SMC37c669_RAW_DEVICE_DRQ(
SMC37c669_xlate_drq( local_config[ func ].drq )
);
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_DRQ_INDEX,
drq.as_uchar
);
irq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_IRQ_INDEX );
irq.by_field.ppt_irq =
SMC37c669_RAW_DEVICE_IRQ(
SMC37c669_xlate_irq( local_config[ func ].irq )
);
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_IRQ_INDEX,
irq.as_uchar
);
base_addr.as_uchar = 0;
base_addr.by_field.addr9_2 = local_config[ func ].port1 >> 2;
SMC37c669_write_config(
SMC37c669_PARALLEL0_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case FLOPPY_0:
{
SMC37c669_FDC_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_PARALLEL_FDC_IRQ_REGISTER irq;
SMC37c669_PARALLEL_FDC_DRQ_REGISTER drq;
drq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_DRQ_INDEX );
drq.by_field.fdc_drq =
SMC37c669_RAW_DEVICE_DRQ(
SMC37c669_xlate_drq( local_config[ func ].drq )
);
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_DRQ_INDEX,
drq.as_uchar
);
irq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_IRQ_INDEX );
irq.by_field.fdc_irq =
SMC37c669_RAW_DEVICE_IRQ(
SMC37c669_xlate_irq( local_config[ func ].irq )
);
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_IRQ_INDEX,
irq.as_uchar
);
base_addr.as_uchar = 0;
base_addr.by_field.addr9_4 = local_config[ func ].port1 >> 4;
SMC37c669_write_config(
SMC37c669_FDC_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case IDE_0:
{
SMC37c669_IDE_ADDRESS_REGISTER ide_addr;
ide_addr.as_uchar = 0;
ide_addr.by_field.addr9_4 = local_config[ func ].port2 >> 4;
SMC37c669_write_config(
SMC37c669_IDE_ALTERNATE_ADDRESS_INDEX,
ide_addr.as_uchar
);
ide_addr.as_uchar = 0;
ide_addr.by_field.addr9_4 = local_config[ func ].port1 >> 4;
SMC37c669_write_config(
SMC37c669_IDE_BASE_ADDRESS_INDEX,
ide_addr.as_uchar
);
ret_val = TRUE;
break;
}
}
SMC37c669_config_mode( FALSE );
return ret_val;
}
unsigned int __init SMC37c669_disable_device ( unsigned int func )
{
unsigned int ret_val = FALSE;
SMC37c669_config_mode( TRUE );
switch ( func ) {
case SERIAL_0:
{
SMC37c669_SERIAL_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_SERIAL_IRQ_REGISTER irq;
irq.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL_IRQ_INDEX );
irq.by_field.uart1_irq = 0;
SMC37c669_write_config( SMC37c669_SERIAL_IRQ_INDEX, irq.as_uchar );
base_addr.as_uchar = 0;
SMC37c669_write_config(
SMC37c669_SERIAL0_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case SERIAL_1:
{
SMC37c669_SERIAL_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_SERIAL_IRQ_REGISTER irq;
irq.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL_IRQ_INDEX );
irq.by_field.uart2_irq = 0;
SMC37c669_write_config( SMC37c669_SERIAL_IRQ_INDEX, irq.as_uchar );
base_addr.as_uchar = 0;
SMC37c669_write_config(
SMC37c669_SERIAL1_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case PARALLEL_0:
{
SMC37c669_PARALLEL_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_PARALLEL_FDC_IRQ_REGISTER irq;
SMC37c669_PARALLEL_FDC_DRQ_REGISTER drq;
drq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_DRQ_INDEX );
drq.by_field.ppt_drq = 0;
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_DRQ_INDEX,
drq.as_uchar
);
irq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_IRQ_INDEX );
irq.by_field.ppt_irq = 0;
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_IRQ_INDEX,
irq.as_uchar
);
base_addr.as_uchar = 0;
SMC37c669_write_config(
SMC37c669_PARALLEL0_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case FLOPPY_0:
{
SMC37c669_FDC_BASE_ADDRESS_REGISTER base_addr;
SMC37c669_PARALLEL_FDC_IRQ_REGISTER irq;
SMC37c669_PARALLEL_FDC_DRQ_REGISTER drq;
drq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_DRQ_INDEX );
drq.by_field.fdc_drq = 0;
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_DRQ_INDEX,
drq.as_uchar
);
irq.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_IRQ_INDEX );
irq.by_field.fdc_irq = 0;
SMC37c669_write_config(
SMC37c669_PARALLEL_FDC_IRQ_INDEX,
irq.as_uchar
);
base_addr.as_uchar = 0;
SMC37c669_write_config(
SMC37c669_FDC_BASE_ADDRESS_INDEX,
base_addr.as_uchar
);
ret_val = TRUE;
break;
}
case IDE_0:
{
SMC37c669_IDE_ADDRESS_REGISTER ide_addr;
ide_addr.as_uchar = 0;
SMC37c669_write_config(
SMC37c669_IDE_ALTERNATE_ADDRESS_INDEX,
ide_addr.as_uchar
);
ide_addr.as_uchar = 0;
SMC37c669_write_config(
SMC37c669_IDE_BASE_ADDRESS_INDEX,
ide_addr.as_uchar
);
ret_val = TRUE;
break;
}
}
SMC37c669_config_mode( FALSE );
return ret_val;
}
unsigned int __init SMC37c669_configure_device (
unsigned int func,
int port,
int irq,
int drq )
{
struct DEVICE_CONFIG *cp;
if ( ( cp = SMC37c669_get_config ( func ) ) != NULL ) {
if ( ( drq & ~0xFF ) == 0 ) {
cp->drq = drq;
}
if ( ( irq & ~0xFF ) == 0 ) {
cp->irq = irq;
}
if ( ( port & ~0xFFFF ) == 0 ) {
cp->port1 = port;
}
if ( SMC37c669_is_device_enabled( func ) ) {
SMC37c669_enable_device( func );
}
return TRUE;
}
return FALSE;
}
static unsigned int __init SMC37c669_is_device_enabled ( unsigned int func )
{
unsigned char base_addr = 0;
unsigned int dev_ok = FALSE;
unsigned int ret_val = FALSE;
SMC37c669_config_mode( TRUE );
switch ( func ) {
case SERIAL_0:
base_addr =
SMC37c669_read_config( SMC37c669_SERIAL0_BASE_ADDRESS_INDEX );
dev_ok = TRUE;
break;
case SERIAL_1:
base_addr =
SMC37c669_read_config( SMC37c669_SERIAL1_BASE_ADDRESS_INDEX );
dev_ok = TRUE;
break;
case PARALLEL_0:
base_addr =
SMC37c669_read_config( SMC37c669_PARALLEL0_BASE_ADDRESS_INDEX );
dev_ok = TRUE;
break;
case FLOPPY_0:
base_addr =
SMC37c669_read_config( SMC37c669_FDC_BASE_ADDRESS_INDEX );
dev_ok = TRUE;
break;
case IDE_0:
base_addr =
SMC37c669_read_config( SMC37c669_IDE_BASE_ADDRESS_INDEX );
dev_ok = TRUE;
break;
}
if ( ( dev_ok ) && ( ( base_addr & 0xC0 ) != 0 ) ) {
ret_val = TRUE;
}
SMC37c669_config_mode( FALSE );
return ret_val;
}
void __init SMC37c669_display_device_info ( void )
{
if ( SMC37c669_is_device_enabled( SERIAL_0 ) ) {
printk( " Serial 0: Enabled [ Port 0x%x, IRQ %d ]\n",
local_config[ SERIAL_0 ].port1,
local_config[ SERIAL_0 ].irq
);
}
else {
printk( " Serial 0: Disabled\n" );
}
if ( SMC37c669_is_device_enabled( SERIAL_1 ) ) {
printk( " Serial 1: Enabled [ Port 0x%x, IRQ %d ]\n",
local_config[ SERIAL_1 ].port1,
local_config[ SERIAL_1 ].irq
);
}
else {
printk( " Serial 1: Disabled\n" );
}
if ( SMC37c669_is_device_enabled( PARALLEL_0 ) ) {
printk( " Parallel: Enabled [ Port 0x%x, IRQ %d/%d ]\n",
local_config[ PARALLEL_0 ].port1,
local_config[ PARALLEL_0 ].irq,
local_config[ PARALLEL_0 ].drq
);
}
else {
printk( " Parallel: Disabled\n" );
}
if ( SMC37c669_is_device_enabled( FLOPPY_0 ) ) {
printk( " Floppy Ctrl: Enabled [ Port 0x%x, IRQ %d/%d ]\n",
local_config[ FLOPPY_0 ].port1,
local_config[ FLOPPY_0 ].irq,
local_config[ FLOPPY_0 ].drq
);
}
else {
printk( " Floppy Ctrl: Disabled\n" );
}
if ( SMC37c669_is_device_enabled( IDE_0 ) ) {
printk( " IDE 0: Enabled [ Port 0x%x, IRQ %d ]\n",
local_config[ IDE_0 ].port1,
local_config[ IDE_0 ].irq
);
}
else {
printk( " IDE 0: Disabled\n" );
}
}
static void __init SMC37c669_config_mode(
unsigned int enable )
{
if ( enable ) {
spin_lock(&smc_lock);
wb( &SMC37c669->index_port, SMC37c669_CONFIG_ON_KEY );
wb( &SMC37c669->index_port, SMC37c669_CONFIG_ON_KEY );
spin_unlock(&smc_lock);
}
else {
wb( &SMC37c669->index_port, SMC37c669_CONFIG_OFF_KEY );
}
}
static unsigned char __init SMC37c669_read_config(
unsigned char index )
{
unsigned char data;
wb( &SMC37c669->index_port, index );
data = rb( &SMC37c669->data_port );
return data;
}
static void __init SMC37c669_write_config(
unsigned char index,
unsigned char data )
{
wb( &SMC37c669->index_port, index );
wb( &SMC37c669->data_port, data );
}
static void __init SMC37c669_init_local_config ( void )
{
SMC37c669_SERIAL_BASE_ADDRESS_REGISTER uart_base;
SMC37c669_SERIAL_IRQ_REGISTER uart_irqs;
SMC37c669_PARALLEL_BASE_ADDRESS_REGISTER ppt_base;
SMC37c669_PARALLEL_FDC_IRQ_REGISTER ppt_fdc_irqs;
SMC37c669_PARALLEL_FDC_DRQ_REGISTER ppt_fdc_drqs;
SMC37c669_FDC_BASE_ADDRESS_REGISTER fdc_base;
SMC37c669_IDE_ADDRESS_REGISTER ide_base;
SMC37c669_IDE_ADDRESS_REGISTER ide_alt;
uart_base.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL0_BASE_ADDRESS_INDEX );
uart_irqs.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL_IRQ_INDEX );
local_config[SERIAL_0].port1 = uart_base.by_field.addr9_3 << 3;
local_config[SERIAL_0].irq =
SMC37c669_xlate_irq(
SMC37c669_DEVICE_IRQ( uart_irqs.by_field.uart1_irq )
);
uart_base.as_uchar =
SMC37c669_read_config( SMC37c669_SERIAL1_BASE_ADDRESS_INDEX );
local_config[SERIAL_1].port1 = uart_base.by_field.addr9_3 << 3;
local_config[SERIAL_1].irq =
SMC37c669_xlate_irq(
SMC37c669_DEVICE_IRQ( uart_irqs.by_field.uart2_irq )
);
ppt_base.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL0_BASE_ADDRESS_INDEX );
ppt_fdc_irqs.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_IRQ_INDEX );
ppt_fdc_drqs.as_uchar =
SMC37c669_read_config( SMC37c669_PARALLEL_FDC_DRQ_INDEX );
local_config[PARALLEL_0].port1 = ppt_base.by_field.addr9_2 << 2;
local_config[PARALLEL_0].irq =
SMC37c669_xlate_irq(
SMC37c669_DEVICE_IRQ( ppt_fdc_irqs.by_field.ppt_irq )
);
local_config[PARALLEL_0].drq =
SMC37c669_xlate_drq(
SMC37c669_DEVICE_DRQ( ppt_fdc_drqs.by_field.ppt_drq )
);
fdc_base.as_uchar =
SMC37c669_read_config( SMC37c669_FDC_BASE_ADDRESS_INDEX );
local_config[FLOPPY_0].port1 = fdc_base.by_field.addr9_4 << 4;
local_config[FLOPPY_0].irq =
SMC37c669_xlate_irq(
SMC37c669_DEVICE_IRQ( ppt_fdc_irqs.by_field.fdc_irq )
);
local_config[FLOPPY_0].drq =
SMC37c669_xlate_drq(
SMC37c669_DEVICE_DRQ( ppt_fdc_drqs.by_field.fdc_drq )
);
ide_base.as_uchar =
SMC37c669_read_config( SMC37c669_IDE_BASE_ADDRESS_INDEX );
ide_alt.as_uchar =
SMC37c669_read_config( SMC37c669_IDE_ALTERNATE_ADDRESS_INDEX );
local_config[IDE_0].port1 = ide_base.by_field.addr9_4 << 4;
local_config[IDE_0].port2 = ide_alt.by_field.addr9_4 << 4;
local_config[IDE_0].irq = 14;
}
static struct DEVICE_CONFIG * __init SMC37c669_get_config( unsigned int func )
{
struct DEVICE_CONFIG *cp = NULL;
switch ( func ) {
case SERIAL_0:
cp = &local_config[ SERIAL_0 ];
break;
case SERIAL_1:
cp = &local_config[ SERIAL_1 ];
break;
case PARALLEL_0:
cp = &local_config[ PARALLEL_0 ];
break;
case FLOPPY_0:
cp = &local_config[ FLOPPY_0 ];
break;
case IDE_0:
cp = &local_config[ IDE_0 ];
break;
}
return cp;
}
static int __init SMC37c669_xlate_irq ( int irq )
{
int i, translated_irq = -1;
if ( SMC37c669_IS_DEVICE_IRQ( irq ) ) {
for ( i = 0; ( SMC37c669_irq_table[i].device_irq != -1 ) || ( SMC37c669_irq_table[i].isa_irq != -1 ); i++ ) {
if ( irq == SMC37c669_irq_table[i].device_irq ) {
translated_irq = SMC37c669_irq_table[i].isa_irq;
break;
}
}
}
else {
for ( i = 0; ( SMC37c669_irq_table[i].isa_irq != -1 ) || ( SMC37c669_irq_table[i].device_irq != -1 ); i++ ) {
if ( irq == SMC37c669_irq_table[i].isa_irq ) {
translated_irq = SMC37c669_irq_table[i].device_irq;
break;
}
}
}
return translated_irq;
}
static int __init SMC37c669_xlate_drq ( int drq )
{
int i, translated_drq = -1;
if ( SMC37c669_IS_DEVICE_DRQ( drq ) ) {
for ( i = 0; ( SMC37c669_drq_table[i].device_drq != -1 ) || ( SMC37c669_drq_table[i].isa_drq != -1 ); i++ ) {
if ( drq == SMC37c669_drq_table[i].device_drq ) {
translated_drq = SMC37c669_drq_table[i].isa_drq;
break;
}
}
}
else {
for ( i = 0; ( SMC37c669_drq_table[i].isa_drq != -1 ) || ( SMC37c669_drq_table[i].device_drq != -1 ); i++ ) {
if ( drq == SMC37c669_drq_table[i].isa_drq ) {
translated_drq = SMC37c669_drq_table[i].device_drq;
break;
}
}
}
return translated_drq;
}
void __init
SMC37c669_dump_registers(void)
{
int i;
for (i = 0; i <= 0x29; i++)
printk("-- CR%02x : %02x\n", i, SMC37c669_read_config(i));
}
void __init SMC669_Init ( int index )
{
SMC37c669_CONFIG_REGS *SMC_base;
unsigned long flags;
local_irq_save(flags);
if ( ( SMC_base = SMC37c669_detect( index ) ) != NULL ) {
#if SMC_DEBUG
SMC37c669_config_mode( TRUE );
SMC37c669_dump_registers( );
SMC37c669_config_mode( FALSE );
SMC37c669_display_device_info( );
#endif
SMC37c669_disable_device( SERIAL_0 );
SMC37c669_configure_device(
SERIAL_0,
COM1_BASE,
COM1_IRQ,
-1
);
SMC37c669_enable_device( SERIAL_0 );
SMC37c669_disable_device( SERIAL_1 );
SMC37c669_configure_device(
SERIAL_1,
COM2_BASE,
COM2_IRQ,
-1
);
SMC37c669_enable_device( SERIAL_1 );
SMC37c669_disable_device( PARALLEL_0 );
SMC37c669_configure_device(
PARALLEL_0,
PARP_BASE,
PARP_IRQ,
PARP_DRQ
);
SMC37c669_enable_device( PARALLEL_0 );
SMC37c669_disable_device( FLOPPY_0 );
SMC37c669_configure_device(
FLOPPY_0,
FDC_BASE,
FDC_IRQ,
FDC_DRQ
);
SMC37c669_enable_device( FLOPPY_0 );
outb(0xc, 0x3f2);
SMC37c669_disable_device( IDE_0 );
#if SMC_DEBUG
SMC37c669_config_mode( TRUE );
SMC37c669_dump_registers( );
SMC37c669_config_mode( FALSE );
SMC37c669_display_device_info( );
#endif
local_irq_restore(flags);
printk( "SMC37c669 Super I/O Controller found @ 0x%p\n",
SMC_base );
}
else {
local_irq_restore(flags);
#if SMC_DEBUG
printk( "No SMC37c669 Super I/O Controller found\n" );
#endif
}
}
