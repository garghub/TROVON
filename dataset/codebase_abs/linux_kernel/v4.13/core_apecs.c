static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 , unsigned char * V_6 )
{
unsigned long V_7 ;
T_1 V_8 = V_2 -> V_9 ;
F_2 ( ( L_1
L_2 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ) ;
if ( V_8 == 0 ) {
int V_10 = V_3 >> 3 ;
if ( V_10 > 20 ) {
F_2 ( ( L_3 ,
V_10 ) ) ;
return - 1 ;
}
* V_6 = 0 ;
V_7 = ( V_3 << 8 ) | ( V_4 ) ;
} else {
* V_6 = 1 ;
V_7 = ( V_8 << 16 ) | ( V_3 << 8 ) | ( V_4 ) ;
}
* V_5 = V_7 ;
F_2 ( ( L_4 , V_7 ) ) ;
return 0 ;
}
static unsigned int
F_3 ( unsigned long V_7 , unsigned char V_6 )
{
unsigned long V_11 ;
unsigned int V_12 , V_13 ;
unsigned int V_14 = 0 ;
F_4 ( V_11 ) ;
F_2 ( ( L_5 , V_7 , V_6 ) ) ;
V_12 = * ( V_15 ) V_16 ;
* ( V_15 ) V_16 = V_12 ;
F_5 () ;
F_2 ( ( L_6 , V_12 ) ) ;
if ( V_6 ) {
V_14 = * ( V_15 ) V_17 ;
F_5 () ;
* ( V_15 ) V_17 = V_14 | 1 ;
F_2 ( ( L_7 ) ) ;
}
F_6 () ;
F_7 ( 0 ) = 1 ;
F_8 ( 0 ) = 0 ;
F_5 () ;
asm volatile("ldl %0,%1; mb; mb" : "=r"(value) : "m"(*(vuip)addr)
: "$9", "$10", "$11", "$12", "$13", "$14", "memory");
if ( F_8 ( 0 ) ) {
F_8 ( 0 ) = 0 ;
V_13 = 0xffffffffU ;
F_5 () ;
}
F_7 ( 0 ) = 0 ;
F_5 () ;
#if 1
F_6 () ;
V_12 = * ( V_15 ) V_16 ;
F_2 ( ( L_8 , V_12 ) ) ;
if ( V_12 & 0xffe0U ) {
if ( ! ( V_12 & 0x0800 ) ) {
F_9 ( L_9 , V_12 ) ;
}
* ( V_15 ) V_16 = V_12 ;
F_5 () ;
F_10 ( 0x7 ) ;
V_13 = 0xffffffff ;
}
#endif
if ( V_6 ) {
* ( V_15 ) V_17 = V_14 & ~ 1 ;
F_5 () ;
}
F_11 ( V_11 ) ;
return V_13 ;
}
static void
F_12 ( unsigned long V_7 , unsigned int V_13 , unsigned char V_6 )
{
unsigned long V_11 ;
unsigned int V_12 ;
unsigned int V_14 = 0 ;
F_4 ( V_11 ) ;
V_12 = * ( V_15 ) V_16 ;
* ( V_15 ) V_16 = V_12 ;
F_5 () ;
if ( V_6 ) {
V_14 = * ( V_15 ) V_17 ;
F_5 () ;
* ( V_15 ) V_17 = V_14 | 1 ;
}
F_6 () ;
F_7 ( 0 ) = 1 ;
F_5 () ;
* ( V_15 ) V_7 = V_13 ;
F_5 () ;
F_5 () ;
F_7 ( 0 ) = 0 ;
F_5 () ;
#if 1
F_6 () ;
V_12 = * ( V_15 ) V_16 ;
if ( V_12 & 0xffe0U ) {
if ( ! ( V_12 & 0x0800 ) ) {
F_9 ( L_10 , V_12 ) ;
}
* ( V_15 ) V_16 = V_12 ;
F_5 () ;
F_10 ( 0x7 ) ;
}
#endif
if ( V_6 ) {
* ( V_15 ) V_17 = V_14 & ~ 1 ;
F_5 () ;
}
F_11 ( V_11 ) ;
}
static int
F_13 ( struct V_1 * V_8 , unsigned int V_18 , int V_4 ,
int V_19 , T_2 * V_13 )
{
unsigned long V_7 , V_5 ;
unsigned char V_6 ;
long V_20 ;
int V_21 ;
if ( F_1 ( V_8 , V_18 , V_4 , & V_5 , & V_6 ) )
return V_22 ;
V_20 = ( V_19 - 1 ) * 8 ;
V_21 = ( V_4 & 3 ) * 8 ;
V_7 = ( V_5 << 5 ) + V_20 + V_23 ;
* V_13 = F_3 ( V_7 , V_6 ) >> ( V_21 ) ;
return V_24 ;
}
static int
F_14 ( struct V_1 * V_8 , unsigned int V_18 , int V_4 ,
int V_19 , T_2 V_13 )
{
unsigned long V_7 , V_5 ;
unsigned char V_6 ;
long V_20 ;
if ( F_1 ( V_8 , V_18 , V_4 , & V_5 , & V_6 ) )
return V_22 ;
V_20 = ( V_19 - 1 ) * 8 ;
V_7 = ( V_5 << 5 ) + V_20 + V_23 ;
F_12 ( V_7 , V_13 << ( ( V_4 & 3 ) * 8 ) , V_6 ) ;
return V_24 ;
}
void
F_15 ( struct V_25 * V_26 , T_3 V_27 , T_3 V_28 )
{
F_16 () ;
* ( V_29 ) V_30 = 0 ;
F_5 () ;
}
void T_4
F_17 ( void )
{
struct V_25 * V_26 ;
V_31 = V_26 = F_18 () ;
V_26 -> V_32 = & V_33 ;
V_26 -> V_34 = & V_35 ;
V_26 -> V_36 = 0 ;
V_26 -> V_37 = V_38 - V_39 ;
V_26 -> V_40 = V_41 - V_39 ;
V_26 -> V_42 = V_43 - V_39 ;
V_26 -> V_44 = 0 ;
V_26 -> V_45 = F_19 ( V_26 , 0x00800000 , 0x00800000 , 0 ) ;
V_26 -> V_46 = NULL ;
V_47 = 0x40000000 ;
V_48 = 0x40000000 ;
* ( V_15 ) V_49 = V_47 | 0x00080000 ;
* ( V_15 ) V_50 = ( V_48 - 1 ) & 0xfff00000U ;
* ( V_15 ) V_51 = 0 ;
* ( V_15 ) V_52 = V_26 -> V_45 -> V_53 | 0x000c0000 ;
* ( V_15 ) V_54 = ( V_26 -> V_45 -> V_19 - 1 ) & 0xfff00000 ;
* ( V_15 ) V_55 = F_20 ( V_26 -> V_45 -> V_56 ) >> 1 ;
F_15 ( V_26 , 0 , - 1 ) ;
* ( V_15 ) V_17 = 0 ;
F_5 () ;
}
void
F_21 ( void )
{
unsigned int V_57 ;
V_57 = * ( V_15 ) V_16 ;
if ( V_57 & 0xffe0L ) {
* ( V_15 ) V_58 ;
* ( V_15 ) V_16 = V_57 | 0xffe1L ;
F_5 () ;
* ( V_15 ) V_16 ;
}
* ( V_15 ) V_30 = ( unsigned int ) V_30 ;
F_5 () ;
* ( V_15 ) V_30 ;
}
void
F_22 ( unsigned long V_59 , unsigned long V_60 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
V_62 = (struct V_61 * ) V_60 ;
V_64 = (struct V_63 * )
( V_60 + V_62 -> V_67
- sizeof( V_64 -> V_68 ) ) ;
V_66 = (struct V_65 * )
( V_60 + V_62 -> V_69 ) ;
F_5 () ;
F_5 () ;
F_6 () ;
F_21 () ;
F_10 ( 0x7 ) ;
F_5 () ;
F_23 ( V_59 , V_60 , L_11 ,
( F_7 ( 0 )
&& ( V_66 -> V_70 & 0x0c00UL ) ) ) ;
}
