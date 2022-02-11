static void T_1 F_1 ( void )
{
#define F_2 (AXC001_GPIO_INTC + 0x30)
#define F_3 (AXC001_GPIO_INTC + 0x34)
#define F_4 (AXC001_GPIO_INTC + 0x38)
#define F_5 (AXC001_GPIO_INTC + 0x3c)
#define F_6 12
F_7 ( ~ ( 1 << F_6 ) , ( void V_1 * ) F_3 ) ;
F_7 ( 0 , ( void V_1 * ) F_4 ) ;
F_7 ( ~ 0 , ( void V_1 * ) F_5 ) ;
F_7 ( 1 << F_6 , ( void V_1 * ) F_2 ) ;
}
static void T_1 F_8 ( unsigned int V_2 , const char * V_3 )
{
union T_2 {
struct {
#ifdef F_9
unsigned int V_4 : 11 , V_5 : 12 , V_6 : 4 , V_7 : 5 ;
#else
unsigned int V_7 : 5 , V_6 : 4 , V_5 : 12 , V_4 : 11 ;
#endif
};
unsigned int V_8 ;
} V_9 ;
V_9 . V_8 = F_10 ( ( void V_1 * ) V_2 ) ;
F_11 ( L_1 , V_3 , V_9 . V_7 , V_9 . V_6 ,
V_9 . V_5 ) ;
}
static void T_1 F_12 ( void )
{
int V_10 ;
char V_11 [ 32 ] ;
if ( F_10 ( ( void V_1 * ) V_12 ) & ( 1 << 28 ) )
V_10 = 3 ;
else
V_10 = 2 ;
F_1 () ;
F_7 ( ( 1 << 5 ) , ( void V_1 * ) V_13 ) ;
F_13 ( V_11 , 32 , L_2 , V_10 ) ;
F_8 ( V_14 , V_11 ) ;
}
static T_3 void T_1
F_14 ( void V_1 * V_15 , const struct V_16 V_17 [ 16 ] )
{
unsigned int V_18 , V_19 ;
int V_20 ;
V_18 = V_19 = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
V_18 |= V_17 [ V_20 ] . V_21 << ( V_20 << 2 ) ;
V_19 |= V_17 [ V_20 ] . V_22 << ( V_20 << 2 ) ;
}
F_7 ( V_18 , V_15 + 0x0 ) ;
F_7 ( V_19 , V_15 + 0x8 ) ;
V_18 = V_19 = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
V_18 |= V_17 [ V_20 + 8 ] . V_21 << ( V_20 << 2 ) ;
V_19 |= V_17 [ V_20 + 8 ] . V_22 << ( V_20 << 2 ) ;
}
F_7 ( V_18 , V_15 + 0x4 ) ;
F_7 ( V_19 , V_15 + 0xC ) ;
}
static void T_1 F_15 ( void )
{
int V_20 ;
F_14 ( ( void V_1 * ) V_23 , V_24 ) ;
F_7 ( 1 , ( void V_1 * ) V_25 ) ;
F_14 ( ( void V_1 * ) V_26 ,
V_27 ) ;
F_7 ( 1 , ( void V_1 * ) V_28 ) ;
for ( V_20 = V_29 ; V_20 <= V_30 ; V_20 ++ )
F_14 ( ( void V_1 * ) V_31 + ( V_20 << 4 ) ,
V_32 ) ;
F_7 ( 0x3ff , ( void V_1 * ) V_31 + 0x100 ) ;
F_7 ( 0x01 , ( void V_1 * ) V_33 ) ;
F_7 ( 0x01 , ( void V_1 * ) V_34 ) ;
F_7 ( 0x18 , ( void V_1 * ) V_13 ) ;
F_7 ( 0x52 , ( void V_1 * ) V_35 ) ;
F_12 () ;
}
static void T_1 F_16 ( void )
{
#ifdef F_17
unsigned int V_36 = ( F_18 ( V_37 ) >> 16 ) & 0x3F ;
if ( V_36 > 2 ) {
T_4 V_38 = 50 , V_39 ;
int V_40 = F_19 ( V_41 , L_3 ) ;
const struct V_42 * V_43 ;
V_43 = F_20 ( V_41 , V_40 ,
L_4 , NULL ) ;
V_39 = F_21 ( * ( T_4 * ) ( V_43 -> V_44 ) ) / 1000000 ;
if ( V_38 != V_39 ) {
V_38 = F_22 ( V_38 * 1000000 ) ;
F_23 ( V_41 , V_40 ,
L_4 , & V_38 , sizeof( V_38 ) ) ;
}
}
#endif
F_7 ( 0x01 , ( void V_1 * ) V_33 ) ;
F_7 ( ( 0x00100000U | 0x000C0000U | 0x00003322U ) ,
( void V_1 * ) V_45 ) ;
F_7 ( 12 , ( void V_1 * ) ( V_46
+ ( V_47 << 2 ) ) ) ;
F_7 ( 0x01 , ( void V_1 * ) V_34 ) ;
F_8 ( V_48 + 4088 , L_5 ) ;
F_12 () ;
}
