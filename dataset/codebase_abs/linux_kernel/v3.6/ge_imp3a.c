void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_2 * V_4 = NULL ;
unsigned long V_5 = F_2 () ;
if ( F_3 ( V_5 , L_1 ) ) {
V_1 = F_4 ( NULL , 0 ,
V_6 |
V_7 |
V_8 ,
0 , 256 , L_2 ) ;
} else {
V_1 = F_4 ( NULL , 0 ,
V_7 |
V_8 ,
0 , 256 , L_2 ) ;
}
F_5 ( V_1 == NULL ) ;
F_6 ( V_1 ) ;
F_7 (np, L_3 )
if ( F_8 ( V_3 , L_4 ) ) {
V_4 = V_3 ;
break;
}
if ( V_4 == NULL ) {
F_9 ( V_9 L_5 ) ;
return;
}
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
}
static void T_1 F_12 ( void )
{
struct V_2 * V_10 ;
#ifdef F_13
struct V_2 * V_3 ;
struct V_11 * V_12 ;
#endif
T_2 V_13 = 0xffffffff ;
if ( V_14 . V_15 )
V_14 . V_15 ( L_6 , 0 ) ;
#ifdef F_13
F_7 (np, L_7 ) {
if ( F_8 ( V_3 , L_8 ) ||
F_8 ( V_3 , L_9 ) ||
F_8 ( V_3 , L_10 ) ) {
struct V_16 V_17 ;
F_14 ( V_3 , 0 , & V_17 ) ;
if ( ( V_17 . V_18 & 0xfffff ) == V_19 )
F_15 ( V_3 , 1 ) ;
else
F_15 ( V_3 , 0 ) ;
V_12 = F_16 ( V_3 ) ;
V_13 = F_17 ( V_13 , V_12 -> V_20 +
V_12 -> V_21 ) ;
}
}
#endif
F_18 () ;
#ifdef F_19
if ( ( F_20 () - 1 ) > V_13 ) {
V_22 = 1 ;
F_21 ( & V_23 ) ;
V_14 . V_24 = V_25 ;
}
#endif
V_10 = F_22 ( NULL , NULL , L_11 ) ;
if ( V_10 ) {
V_26 = F_23 ( V_10 , 0 ) ;
if ( V_26 == NULL )
F_9 ( V_9 L_12 ) ;
F_11 ( V_10 ) ;
}
#if F_24 ( V_27 )
F_25 () ;
#endif
F_9 ( V_28 L_13 ) ;
}
static unsigned int F_26 ( void )
{
unsigned int V_29 ;
V_29 = F_27 ( V_26 ) ;
return ( V_29 >> 8 ) & 0xff ;
}
static unsigned int F_28 ( void )
{
unsigned int V_29 ;
V_29 = F_27 ( V_26 + 0x2 ) ;
return V_29 & 0xff ;
}
static unsigned int F_29 ( void )
{
unsigned int V_29 ;
V_29 = F_27 ( V_26 + 0x2 ) ;
return ( V_29 >> 8 ) & 0xff ;
}
static unsigned int F_30 ( void )
{
unsigned int V_29 ;
V_29 = F_27 ( V_26 + 0x6 ) ;
return ( V_29 & 0x0f00 ) >> 8 ;
}
static unsigned int F_31 ( void )
{
unsigned int V_29 ;
V_29 = F_27 ( V_26 + 0x6 ) ;
return V_29 & ( 1 << 12 ) ;
}
static void F_32 ( struct V_30 * V_31 )
{
F_33 ( V_31 , L_14 ) ;
F_33 ( V_31 , L_15 , F_26 () ,
( 'A' + F_28 () - 1 ) ) ;
F_33 ( V_31 , L_16 , F_29 () ) ;
F_33 ( V_31 , L_17 , F_30 () ) ;
F_33 ( V_31 , L_18 ,
F_31 () ? L_19 : L_20 ) ;
}
static int T_1 F_34 ( void )
{
unsigned long V_5 = F_2 () ;
if ( F_3 ( V_5 , L_21 ) ) {
#ifdef F_13
V_19 = 0x9000 ;
#endif
return 1 ;
}
return 0 ;
}
