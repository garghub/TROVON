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
static inline void T_1
F_8 ( T_2 V_2 , void V_1 * V_3 , void V_1 * V_4 )
{
unsigned int V_5 = 128 * 1024 , V_6 ;
F_7 ( V_2 , V_3 ) ;
V_6 = V_5 ;
while ( ( ( F_9 ( V_4 ) & 1 ) == 1 ) && V_6 -- )
F_10 () ;
V_6 = V_5 ;
while ( ( ( F_9 ( V_4 ) & 1 ) == 0 ) && V_6 -- )
F_10 () ;
}
static void T_1 F_11 ( unsigned int V_7 , const char * V_8 )
{
union T_3 {
struct {
#ifdef F_12
unsigned int V_9 : 11 , V_10 : 12 , V_11 : 4 , V_12 : 5 ;
#else
unsigned int V_12 : 5 , V_11 : 4 , V_10 : 12 , V_9 : 11 ;
#endif
};
unsigned int V_13 ;
} V_14 ;
V_14 . V_13 = F_9 ( ( void V_1 * ) V_7 ) ;
F_13 ( L_1 , V_8 , V_14 . V_12 , V_14 . V_11 ,
V_14 . V_10 ) ;
}
static void T_1 F_14 ( void )
{
int V_15 ;
char V_16 [ 32 ] ;
if ( F_9 ( ( void V_1 * ) V_17 ) & ( 1 << 28 ) )
V_15 = 3 ;
else
V_15 = 2 ;
F_1 () ;
F_15 ( V_16 , 32 , L_2 , V_15 ) ;
F_11 ( V_18 , V_16 ) ;
}
static T_4 void T_1
F_16 ( void V_1 * V_19 , const struct V_20 V_21 [ 16 ] )
{
unsigned int V_22 , V_23 ;
int V_24 ;
V_22 = V_23 = 0 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
V_22 |= V_21 [ V_24 ] . V_25 << ( V_24 << 2 ) ;
V_23 |= V_21 [ V_24 ] . V_26 << ( V_24 << 2 ) ;
}
F_7 ( V_22 , V_19 + 0x0 ) ;
F_7 ( V_23 , V_19 + 0x8 ) ;
V_22 = V_23 = 0 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
V_22 |= V_21 [ V_24 + 8 ] . V_25 << ( V_24 << 2 ) ;
V_23 |= V_21 [ V_24 + 8 ] . V_26 << ( V_24 << 2 ) ;
}
F_7 ( V_22 , V_19 + 0x4 ) ;
F_7 ( V_23 , V_19 + 0xC ) ;
}
static void T_1 F_17 ( void )
{
int V_24 ;
F_16 ( ( void V_1 * ) V_27 , V_28 ) ;
F_7 ( 1 , ( void V_1 * ) V_29 ) ;
F_16 ( ( void V_1 * ) V_30 ,
V_31 ) ;
F_7 ( 1 , ( void V_1 * ) V_32 ) ;
for ( V_24 = V_33 ; V_24 <= V_34 ; V_24 ++ )
F_16 ( ( void V_1 * ) V_35 + ( V_24 << 4 ) ,
V_36 ) ;
F_7 ( 0x3ff , ( void V_1 * ) V_35 + 0x100 ) ;
F_7 ( 0x01 , ( void V_1 * ) V_37 ) ;
F_7 ( 0x01 , ( void V_1 * ) V_38 ) ;
F_7 ( 0x18 , ( void V_1 * ) V_39 ) ;
F_7 ( 0x52 , ( void V_1 * ) V_40 ) ;
F_14 () ;
}
static unsigned int T_1 F_18 ( void )
{
union V_41 V_42 , V_43 , V_44 ;
unsigned int V_45 = 33333333 ;
V_42 . V_13 = F_9 ( ( void V_1 * ) V_46 + 0x80 + 0 ) ;
V_43 . V_13 = F_9 ( ( void V_1 * ) V_46 + 0x80 + 4 ) ;
V_44 . V_13 = F_9 ( ( void V_1 * ) V_46 + 0x80 + 8 ) ;
if ( V_42 . V_47 != 1 )
V_45 = V_45 / ( V_42 . V_48 + V_42 . V_49 ) ;
if ( V_43 . V_47 != 1 )
V_45 = V_45 * ( V_43 . V_48 + V_43 . V_49 ) ;
if ( V_44 . V_47 != 1 )
V_45 = V_45 / ( V_44 . V_48 + V_44 . V_49 ) ;
V_45 = ( V_45 + 500000 ) / 1000000 ;
return V_45 ;
}
static inline unsigned int T_1 F_19 ( unsigned int V_50 , int V_51 )
{
union V_41 div ;
div . V_13 = 0 ;
div . V_52 = ! V_51 ;
div . V_47 = V_50 == 1 ? 1 : 0 ;
div . V_53 = ( V_50 % 2 == 0 ) ? 0 : 1 ;
div . V_48 = ( V_50 % 2 == 0 ) ? V_50 >> 1 : ( V_50 >> 1 ) + 1 ;
div . V_49 = V_50 >> 1 ;
return div . V_13 ;
}
T_4 static void T_1
F_20 ( unsigned int V_50 , unsigned int V_54 , unsigned int V_55 )
{
F_8 ( F_19 ( V_50 , 0 ) ,
( void V_1 * ) V_46 + 0x80 + 0 ,
( void V_1 * ) V_46 + 0x110 ) ;
F_8 ( F_19 ( V_54 , 0 ) ,
( void V_1 * ) V_46 + 0x80 + 4 ,
( void V_1 * ) V_46 + 0x110 ) ;
F_8 ( F_19 ( V_55 , 1 ) ,
( void V_1 * ) V_46 + 0x80 + 8 ,
( void V_1 * ) V_46 + 0x110 ) ;
}
static void T_1 F_21 ( void )
{
int V_56 = F_22 ( V_57 , L_3 ) ;
const struct V_58 * V_59 = F_23 ( V_57 ,
V_56 ,
L_4 ,
NULL ) ;
T_5 V_60 = F_24 ( * ( T_5 * ) ( V_59 -> V_61 ) ) / 1000000 , V_62 = V_60 ;
#ifdef F_25
unsigned int V_63 = ( F_26 ( V_64 ) >> 16 ) & 0x3F ;
if ( V_63 > 2 )
V_60 = 50 ;
#endif
switch ( V_60 ) {
case 33 :
F_20 ( 1 , 1 , 1 ) ;
break;
case 50 :
F_20 ( 1 , 30 , 20 ) ;
break;
case 75 :
F_20 ( 2 , 45 , 10 ) ;
break;
case 90 :
F_20 ( 2 , 54 , 10 ) ;
break;
case 100 :
F_20 ( 1 , 30 , 10 ) ;
break;
case 125 :
F_20 ( 2 , 45 , 6 ) ;
break;
default:
V_60 = F_18 () ;
break;
}
F_13 ( L_5 , V_60 ) ;
if ( V_60 != V_62 ) {
V_60 = F_27 ( V_60 * 1000000 ) ;
F_28 ( V_57 , V_56 ,
L_4 , & V_60 , sizeof( V_60 ) ) ;
}
F_7 ( 0x01 , ( void V_1 * ) V_37 ) ;
F_7 ( ( 0x00100000U | 0x000C0000U | 0x00003322U ) ,
( void V_1 * ) V_65 ) ;
F_7 ( 12 , ( void V_1 * ) ( V_66
+ ( V_67 << 2 ) ) ) ;
F_7 ( 0x01 , ( void V_1 * ) V_38 ) ;
F_11 ( V_68 + 4088 , L_6 ) ;
F_14 () ;
}
