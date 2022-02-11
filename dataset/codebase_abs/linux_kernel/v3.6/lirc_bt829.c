static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 ,
V_4 , NULL ) ;
if ( V_2 ) {
F_3 (KERN_ERR DRIVER_NAME L_1 ,
pci_name(my_dev)) ;
V_5 = 0 ;
if ( V_2 -> V_6 [ 0 ] . V_7 & V_8 ) {
V_5 = V_2 -> V_6 [ 0 ] . V_9 ;
F_3 (KERN_INFO DRIVER_NAME L_2 ,
(unsigned int)pci_addr_phys) ;
}
if ( V_5 == 0 ) {
F_3 (KERN_ERR DRIVER_NAME L_3 ) ;
return NULL ;
}
} else {
F_3 (KERN_ERR DRIVER_NAME L_4 ) ;
return NULL ;
}
return V_2 ;
}
static int F_4 ( void * V_10 , struct V_11 * V_12 )
{
unsigned char V_13 ;
int V_14 ;
V_14 = F_5 () ;
V_13 = ( V_14 >> 8 ) & 0xFF ;
if ( V_14 & 0xFF ) {
F_6 ( L_5 , V_13 ) ;
F_7 ( V_12 , & V_13 ) ;
return 0 ;
}
return - V_15 ;
}
static int F_8 ( void * V_10 )
{
F_6 ( L_6 ) ;
return 0 ;
}
static void F_9 ( void * V_10 )
{
F_6 ( L_7 ) ;
}
int F_10 ( void )
{
struct V_1 * V_16 ;
V_16 = F_1 () ;
if ( V_16 == NULL )
return - V_17 ;
if ( ! F_11 () )
return - V_17 ;
strcpy ( V_18 . V_19 , L_8 ) ;
V_18 . V_20 = - 1 ;
V_18 . V_21 = 8 ;
V_18 . V_22 = 10 ;
V_18 . V_10 = 0 ;
V_18 . V_23 = F_4 ;
V_18 . V_24 = F_8 ;
V_18 . V_25 = F_9 ;
V_18 . V_26 = & V_16 -> V_26 ;
V_18 . V_27 = V_28 ;
V_29 = F_12 ( & V_18 ) ;
if ( V_29 < 0 ) {
F_3 (KERN_ERR DRIVER_NAME L_9 ) ;
return V_29 ;
}
F_6 ( L_10 , V_29 ) ;
return 0 ;
}
void F_13 ( void )
{
F_14 ( V_29 ) ;
}
static int F_11 ( void )
{
V_30 = F_15 ( V_5 + V_31 , 0x400 ) ;
if ( V_30 == 0 ) {
F_3 (KERN_INFO DRIVER_NAME L_11 ) ;
return 0 ;
}
return 1 ;
}
static void F_16 ( int V_32 )
{
F_17 ( V_33 * V_32 ) ;
}
static int F_5 ( void )
{
unsigned char V_34 , V_35 ;
F_18 () ;
F_19 ( 0xAA ) ;
F_19 ( 0x01 ) ;
F_18 () ;
F_19 ( 0xAB ) ;
V_35 = F_20 () ;
V_34 = F_20 () ;
F_21 () ;
return ( V_34 << 8 ) | V_35 ;
}
static void F_18 ( void )
{
F_22 ( 3 ) ;
F_16 ( 4 ) ;
F_22 ( 1 ) ;
F_16 ( 7 ) ;
F_22 ( 0 ) ;
F_16 ( 2 ) ;
}
static void F_21 ( void )
{
unsigned char V_36 ;
V_36 = F_23 () & 0xFD ;
F_22 ( V_36 ) ;
F_16 ( 1 ) ;
V_36 |= 1 ;
F_22 ( V_36 ) ;
F_16 ( 2 ) ;
V_36 |= 2 ;
F_22 ( V_36 ) ;
V_36 = 3 ;
F_22 ( V_36 ) ;
F_16 ( 2 ) ;
}
static void F_19 ( unsigned char V_37 )
{
int V_38 ;
unsigned char V_39 ;
V_39 = F_23 () ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
if ( V_37 & 0x80 )
V_39 |= 0x02 ;
else
V_39 &= 0xFD ;
F_22 ( V_39 ) ;
F_16 ( 1 ) ;
V_39 |= 1 ;
F_22 ( V_39 ) ;
F_16 ( 1 ) ;
V_39 &= 0xFE ;
F_22 ( V_39 ) ;
F_16 ( 1 ) ;
V_37 <<= 1 ;
}
F_16 ( 2 ) ;
V_39 |= 2 ;
F_22 ( V_39 ) ;
V_39 |= 1 ;
F_22 ( V_39 ) ;
F_16 ( 1 ) ;
F_23 () ;
V_39 &= 0xFE ;
F_22 ( V_39 ) ;
F_16 ( 3 ) ;
}
static unsigned char F_20 ( void )
{
int V_38 ;
int V_40 ;
unsigned char V_41 , V_42 ;
V_42 = F_23 () | 2 ;
F_22 ( V_42 ) ;
V_40 = 0 ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
V_42 &= 0xFE ;
F_22 ( V_42 ) ;
F_16 ( 2 ) ;
V_42 |= 1 ;
F_22 ( V_42 ) ;
F_16 ( 1 ) ;
V_41 = F_23 () ;
if ( V_41 & 2 )
V_40 |= 1 ;
V_40 <<= 1 ;
}
V_42 = 0 ;
if ( V_41 == 0 )
V_42 |= 2 ;
F_22 ( V_42 ) ;
F_16 ( 2 ) ;
V_42 |= 1 ;
F_22 ( V_42 ) ;
F_16 ( 3 ) ;
V_42 &= 0xFE ;
F_22 ( V_42 ) ;
F_16 ( 2 ) ;
V_40 >>= 1 ;
V_40 &= 0xFF ;
return V_40 ;
}
static void F_22 ( unsigned char V_43 )
{
int V_44 ;
V_44 = F_24 ( 0x34 ) ;
if ( V_43 & 2 ) {
V_44 &= 0xFFFFFFDF ;
V_44 |= 1 ;
} else {
V_44 &= 0xFFFFFFFE ;
V_44 |= 0x20 ;
}
V_44 |= 0x10 ;
F_25 ( 0x34 , V_44 ) ;
V_44 = F_24 ( 0x31 ) ;
if ( V_43 & 1 )
V_44 |= 0x1000000 ;
else
V_44 &= 0xFEFFFFFF ;
V_44 |= 0x8000000 ;
F_25 ( 0x31 , V_44 ) ;
}
static unsigned char F_23 ( void )
{
unsigned char V_36 ;
int V_44 ;
V_44 = F_24 ( 0x34 ) ;
V_44 |= 0x10 ;
V_44 &= 0xFFFFFFDF ;
F_25 ( 0x34 , V_44 ) ;
V_44 = F_24 ( 0x34 ) ;
V_36 = 0 ;
if ( V_44 & 8 )
V_36 |= 2 ;
else
V_36 &= 0xFD ;
V_44 = F_24 ( 0x31 ) ;
if ( V_44 & 0x1000000 )
V_36 |= 1 ;
else
V_36 &= 0xFE ;
return V_36 ;
}
static unsigned int F_24 ( unsigned char V_45 )
{
unsigned char * V_46 ;
unsigned int V_37 ;
V_46 = V_30 + ( ( V_45 & 0xFF ) << 2 ) ;
V_37 = F_26 ( V_46 ) ;
return V_37 ;
}
static void F_25 ( unsigned char V_45 , unsigned int V_44 )
{
unsigned char * V_46 ;
V_46 = V_30 + ( ( V_45 & 0xFF ) << 2 ) ;
F_27 ( V_44 , V_46 ) ;
}
