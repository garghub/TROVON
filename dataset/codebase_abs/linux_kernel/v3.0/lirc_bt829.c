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
return 1 ;
if ( ! F_11 () )
return 1 ;
strcpy ( V_17 . V_18 , L_8 ) ;
V_17 . V_19 = - 1 ;
V_17 . V_20 = 8 ;
V_17 . V_21 = 10 ;
V_17 . V_10 = 0 ;
V_17 . V_22 = F_4 ;
V_17 . V_23 = F_8 ;
V_17 . V_24 = F_9 ;
V_17 . V_25 = & V_16 -> V_25 ;
V_17 . V_26 = V_27 ;
V_28 = F_12 ( & V_17 ) ;
if ( V_28 < 0 ) {
F_3 (KERN_ERR DRIVER_NAME L_9 ) ;
return V_28 ;
}
F_6 ( L_10 , V_28 ) ;
return 0 ;
}
void F_13 ( void )
{
F_14 ( V_28 ) ;
}
static int F_11 ( void )
{
V_29 = F_15 ( V_5 + V_30 , 0x400 ) ;
if ( V_29 == 0 ) {
F_3 (KERN_INFO DRIVER_NAME L_11 ) ;
return 0 ;
}
return 1 ;
}
static void F_16 ( int V_31 )
{
F_17 ( V_32 * V_31 ) ;
}
static int F_5 ()
{
unsigned char V_33 , V_34 ;
F_18 () ;
F_19 ( 0xAA ) ;
F_19 ( 0x01 ) ;
F_18 () ;
F_19 ( 0xAB ) ;
V_34 = F_20 () ;
V_33 = F_20 () ;
F_21 () ;
return ( V_33 << 8 ) | V_34 ;
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
unsigned char V_35 ;
V_35 = F_23 () & 0xFD ;
F_22 ( V_35 ) ;
F_16 ( 1 ) ;
V_35 |= 1 ;
F_22 ( V_35 ) ;
F_16 ( 2 ) ;
V_35 |= 2 ;
F_22 ( V_35 ) ;
V_35 = 3 ;
F_22 ( V_35 ) ;
F_16 ( 2 ) ;
}
static void F_19 ( unsigned char V_36 )
{
int V_37 ;
unsigned char V_38 ;
V_38 = F_23 () ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
if ( V_36 & 0x80 )
V_38 |= 0x02 ;
else
V_38 &= 0xFD ;
F_22 ( V_38 ) ;
F_16 ( 1 ) ;
V_38 |= 1 ;
F_22 ( V_38 ) ;
F_16 ( 1 ) ;
V_38 &= 0xFE ;
F_22 ( V_38 ) ;
F_16 ( 1 ) ;
V_36 <<= 1 ;
}
F_16 ( 2 ) ;
V_38 |= 2 ;
F_22 ( V_38 ) ;
V_38 |= 1 ;
F_22 ( V_38 ) ;
F_16 ( 1 ) ;
F_23 () ;
V_38 &= 0xFE ;
F_22 ( V_38 ) ;
F_16 ( 3 ) ;
}
static unsigned char F_20 ( void )
{
int V_37 ;
int V_39 ;
unsigned char V_40 , V_41 ;
V_41 = F_23 () | 2 ;
F_22 ( V_41 ) ;
V_39 = 0 ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
V_41 &= 0xFE ;
F_22 ( V_41 ) ;
F_16 ( 2 ) ;
V_41 |= 1 ;
F_22 ( V_41 ) ;
F_16 ( 1 ) ;
V_40 = F_23 () ;
if ( V_40 & 2 )
V_39 |= 1 ;
V_39 <<= 1 ;
}
V_41 = 0 ;
if ( V_40 == 0 )
V_41 |= 2 ;
F_22 ( V_41 ) ;
F_16 ( 2 ) ;
V_41 |= 1 ;
F_22 ( V_41 ) ;
F_16 ( 3 ) ;
V_41 &= 0xFE ;
F_22 ( V_41 ) ;
F_16 ( 2 ) ;
V_39 >>= 1 ;
V_39 &= 0xFF ;
return V_39 ;
}
static void F_22 ( unsigned char V_42 )
{
int V_43 ;
V_43 = F_24 ( 0x34 ) ;
if ( V_42 & 2 ) {
V_43 &= 0xFFFFFFDF ;
V_43 |= 1 ;
} else {
V_43 &= 0xFFFFFFFE ;
V_43 |= 0x20 ;
}
V_43 |= 0x10 ;
F_25 ( 0x34 , V_43 ) ;
V_43 = F_24 ( 0x31 ) ;
if ( V_42 & 1 )
V_43 |= 0x1000000 ;
else
V_43 &= 0xFEFFFFFF ;
V_43 |= 0x8000000 ;
F_25 ( 0x31 , V_43 ) ;
}
static unsigned char F_23 ( void )
{
unsigned char V_35 ;
int V_43 ;
V_43 = F_24 ( 0x34 ) ;
V_43 |= 0x10 ;
V_43 &= 0xFFFFFFDF ;
F_25 ( 0x34 , V_43 ) ;
V_43 = F_24 ( 0x34 ) ;
V_35 = 0 ;
if ( V_43 & 8 )
V_35 |= 2 ;
else
V_35 &= 0xFD ;
V_43 = F_24 ( 0x31 ) ;
if ( V_43 & 0x1000000 )
V_35 |= 1 ;
else
V_35 &= 0xFE ;
return V_35 ;
}
static unsigned int F_24 ( unsigned char V_44 )
{
unsigned char * V_45 ;
unsigned int V_36 ;
V_45 = V_29 + ( ( V_44 & 0xFF ) << 2 ) ;
V_36 = F_26 ( V_45 ) ;
return V_36 ;
}
static void F_25 ( unsigned char V_44 , unsigned int V_43 )
{
unsigned char * V_45 ;
V_45 = V_29 + ( ( V_44 & 0xFF ) << 2 ) ;
F_27 ( V_43 , V_45 ) ;
}
