static void
F_1 ( unsigned long V_1 )
{
unsigned int V_2 ;
unsigned int V_3 ;
V_2 = V_1 >> 16 ;
V_3 = ( ( V_1 & 0xffff ) - 0x800 ) >> 4 ;
V_3 += 16 ;
V_3 &= V_4 ;
V_3 |= V_2 << V_5 ;
F_2 ( V_3 ) ;
}
static volatile unsigned long *
F_3 ( unsigned int V_3 , struct V_6 * * V_7 )
{
volatile unsigned long * V_8 ;
unsigned int V_2 ;
struct V_6 * V_6 ;
V_2 = V_3 >> V_5 ;
if ( ! ( V_6 = F_4 ( V_2 ) ) ) {
F_5 ( V_9
L_1 ,
V_10 , V_3 , V_2 ) ;
return NULL ;
}
V_3 &= V_4 ;
V_3 -= 16 ;
if ( V_3 >= 0x180 ) {
F_5 ( V_9
L_2 ,
V_10 , V_2 , V_3 ) ;
return NULL ;
}
V_8 = & V_6 -> V_11 -> V_12 [ V_3 & 0xff ] . V_13 ;
if ( V_3 >= 0x80 )
V_8 = & V_6 -> V_11 -> V_14 [ ( ( V_3 - 0x80 ) >> 5 ) & 0x0f ] . V_13 ;
if ( V_7 ) * V_7 = V_6 ;
return V_8 ;
}
static void
F_6 ( struct V_15 * V_16 )
{
volatile unsigned long * V_8 ;
unsigned int V_3 = V_16 -> V_3 ;
struct V_6 * V_6 ;
V_8 = F_3 ( V_3 , & V_6 ) ;
if ( ! V_8 || ! V_6 ) {
F_5 ( V_9 L_3 ,
V_10 , V_3 ) ;
return;
}
F_7 ( & V_6 -> V_17 ) ;
* V_8 |= 1UL << 24 ;
F_8 () ;
* V_8 ;
F_9 ( & V_6 -> V_17 ) ;
}
static void
F_10 ( struct V_15 * V_16 )
{
volatile unsigned long * V_8 ;
unsigned int V_3 = V_16 -> V_3 ;
struct V_6 * V_6 ;
V_8 = F_3 ( V_3 , & V_6 ) ;
if ( ! V_8 || ! V_6 ) {
F_5 ( V_9 L_3 ,
V_10 , V_3 ) ;
return;
}
F_7 ( & V_6 -> V_17 ) ;
* V_8 &= ~ ( 1UL << 24 ) ;
F_8 () ;
* V_8 ;
F_9 ( & V_6 -> V_17 ) ;
}
static void
F_11 ( struct V_15 * V_16 )
{
return;
}
static void
F_12 ( struct V_6 * V_6 ,
volatile unsigned long * V_13 ,
unsigned int V_18 )
{
unsigned long V_19 ;
V_19 = * V_13 ;
V_19 &= ~ ( 0x1ffUL << 24 ) ;
V_19 |= ( ( unsigned long ) V_18 << 24 ) ;
* V_13 = V_19 ;
F_8 () ;
* V_13 ;
}
static void
F_13 ( struct V_6 * V_6 , unsigned int V_20 , unsigned int V_18 )
{
unsigned long V_19 ;
V_19 = V_6 -> V_11 -> V_12 [ V_20 ] . V_13 ;
V_19 &= ~ ( 0x1ffUL << 14 ) ;
V_19 |= ( ( unsigned long ) V_18 << 14 ) ;
V_6 -> V_11 -> V_12 [ V_20 ] . V_13 = V_19 ;
F_8 () ;
V_6 -> V_11 -> V_12 [ V_20 ] . V_13 ;
}
static void
F_14 ( struct V_6 * V_6 , unsigned int V_20 , unsigned int V_18 )
{
unsigned long V_19 ;
V_19 = V_6 -> V_11 -> V_14 [ V_20 ] . V_13 ;
V_19 &= ~ ( 0x1ffUL << 14 ) ;
V_19 |= ( ( unsigned long ) V_18 << 14 ) ;
V_6 -> V_11 -> V_14 [ V_20 ] . V_13 = V_19 ;
F_8 () ;
V_6 -> V_11 -> V_14 [ V_20 ] . V_13 ;
}
static void T_1
F_15 ( struct V_6 * V_6 , unsigned int V_20 , unsigned int V_18 )
{
V_6 -> V_11 -> V_12 [ V_20 ] . V_13 = ( ( unsigned long ) V_18 << 14 ) ;
F_8 () ;
V_6 -> V_11 -> V_12 [ V_20 ] . V_13 ;
}
static void T_1
F_16 ( struct V_6 * V_6 , unsigned int V_20 , unsigned int V_18 )
{
V_6 -> V_11 -> V_14 [ V_20 ] . V_13 = ( ( unsigned long ) V_18 << 14 ) ;
F_8 () ;
V_6 -> V_11 -> V_14 [ V_20 ] . V_13 ;
}
static void T_1
F_17 ( struct V_6 * V_6 ,
struct V_21 * V_22 ,
struct V_21 * V_23 )
{
long V_24 = ( V_6 -> V_25 << V_5 ) + 16 ;
long V_26 ;
F_5 ( L_4 ,
V_6 -> V_25 , V_24 ) ;
F_5 ( L_5 , V_27 ) ;
F_7 ( & V_6 -> V_17 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_28 . V_13 , V_27 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_29 . V_13 , V_27 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_30 . V_13 , V_27 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_31 . V_13 , V_27 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_32 . V_13 , V_27 ) ;
for ( V_26 = 0 ; V_26 < 128 ; ++ V_26 ) {
F_18 ( V_24 + V_26 , V_22 , V_33 ) ;
F_19 ( V_26 , V_34 ) ;
}
for ( V_26 = 0 ; V_26 < 0x60 ; ++ V_26 )
F_15 ( V_6 , V_26 , V_27 ) ;
F_15 ( V_6 , 0x74 , V_27 ) ;
F_15 ( V_6 , 0x75 , V_27 ) ;
for ( V_26 = 128 ; V_26 < ( 128 + 512 ) ; ++ V_26 ) {
F_18 ( V_24 + V_26 , V_23 , V_33 ) ;
F_19 ( V_26 , V_34 ) ;
}
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 )
F_16 ( V_6 , V_26 , V_27 ) ;
F_9 ( & V_6 -> V_17 ) ;
}
static void T_1
F_20 ( void )
{
int V_26 ;
struct V_6 * V_6 = NULL ;
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 ) {
F_18 ( V_26 , & V_35 ,
V_33 ) ;
}
for ( V_6 = NULL ; ( V_6 = F_21 ( V_6 ) ) != NULL ; )
F_17 ( V_6 , & V_36 , & V_37 ) ;
}
static int
F_22 ( const struct V_38 * V_39 , T_2 V_40 , T_2 V_41 )
{
struct V_38 * V_42 = (struct V_38 * ) V_39 ;
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_46 * V_46 = V_44 -> V_45 ;
struct V_6 * V_6 = V_46 -> V_6 ;
int V_47 , V_48 ;
T_3 V_49 ;
T_3 V_50 ;
T_2 V_51 ;
int V_3 ;
F_23 ( V_42 , V_52 , & V_51 ) ;
V_3 = V_51 ;
V_47 = F_24 ( V_42 , V_53 ) ;
V_49 = 0 ;
if ( V_47 )
F_25 ( V_42 , V_47 + V_54 , & V_49 ) ;
if ( V_49 & V_55 ) {
V_48 = V_56 ;
if ( V_49 & V_57 )
V_48 = V_58 ;
F_25 ( V_42 , V_47 + V_48 , & V_50 ) ;
V_3 = V_50 & 0x1ff ;
V_3 += 0x80 ;
#if 1
F_5 ( L_6 ,
V_42 -> V_59 -> V_60 ,
F_26 ( V_42 -> V_61 ) ,
F_27 ( V_42 -> V_61 ) ,
V_44 -> V_62 ) ;
F_5 ( L_7 ,
1 << ( ( V_49 & V_63 ) >> 4 ) ,
V_50 ) ;
F_5 ( L_8 ,
1 << ( ( V_49 & V_63 ) >> 4 ) ,
( V_3 + 16 ) | ( V_6 -> V_25 << V_5 ) ,
( V_3 + 16 ) | ( V_6 -> V_25 << V_5 ) ) ;
#endif
#if 0
pci_write_config_word(dev, msi_loc + PCI_MSI_FLAGS,
msg_ctl & ~PCI_MSI_FLAGS_ENABLE);
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &intline);
irq = intline;
printk(" forcing LSI interrupt on irq %d [0x%x]\n", irq, irq);
#endif
}
V_3 += 16 ;
V_3 |= V_6 -> V_25 << V_5 ;
return V_3 ;
}
static void T_1
F_28 ( void )
{
struct V_6 * V_6 ;
F_29 () ;
F_30 ( V_64 ) ;
F_31 () ;
F_32 ( NULL ) ;
for ( V_6 = NULL ; ( V_6 = F_21 ( V_6 ) ) != NULL ; )
F_33 ( V_6 ) ;
}
static void T_1
F_34 ( void )
{
F_35 () ;
}
static void
F_36 ( void )
{
int V_65 = F_37 () ;
struct V_6 * V_6 = F_4 ( V_65 ) ;
unsigned int V_26 ;
if ( ! V_6 )
return;
F_5 ( L_9 , V_65 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_28 . V_13 , V_65 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_29 . V_13 , V_65 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_30 . V_13 , V_65 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_31 . V_13 , V_65 ) ;
F_12 ( V_6 , & V_6 -> V_11 -> V_32 . V_13 , V_65 ) ;
for ( V_26 = 0 ; V_26 < 0x60 ; ++ V_26 )
F_13 ( V_6 , V_26 , V_65 ) ;
F_13 ( V_6 , 0x74 , V_65 ) ;
F_13 ( V_6 , 0x75 , V_65 ) ;
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 )
F_14 ( V_6 , V_26 , V_65 ) ;
}
