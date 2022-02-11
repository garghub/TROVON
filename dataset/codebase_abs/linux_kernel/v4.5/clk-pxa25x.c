unsigned int F_1 ( int V_1 )
{
struct V_2 * V_2 ;
unsigned long V_3 [ 5 ] ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_2 = F_3 ( NULL , V_5 [ V_4 ] ) ;
if ( F_4 ( V_2 ) ) {
V_3 [ V_4 ] = 0 ;
} else {
V_3 [ V_4 ] = F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
}
if ( V_1 ) {
F_7 ( L_1 ,
V_3 [ 1 ] / 1000000 , ( V_3 [ 1 ] % 1000000 ) / 10000 ) ;
F_7 ( L_2 ,
V_3 [ 2 ] / 1000000 , ( V_3 [ 2 ] % 1000000 ) / 10000 ) ;
F_7 ( L_3 ,
V_3 [ 3 ] / 1000000 , ( V_3 [ 3 ] % 1000000 ) / 10000 ) ;
}
return ( unsigned int ) V_3 [ 0 ] / V_6 ;
}
static unsigned long F_8 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_10 = V_11 ;
unsigned int V_12 = V_13 [ ( V_10 >> 5 ) & 0x03 ] ;
return V_9 / V_12 ;
}
static T_1 F_9 ( struct V_7 * V_8 )
{
unsigned long V_14 ;
unsigned int V_15 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_15 = V_14 & ( 1 << 0 ) ;
if ( V_15 )
return V_16 ;
return V_17 ;
}
static unsigned long F_10 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
return V_9 ;
}
static unsigned long F_11 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_10 = V_11 ;
unsigned int V_18 = V_19 [ ( V_10 >> 7 ) & 0x07 ] ;
return ( V_9 / V_18 ) * 2 ;
}
static unsigned long F_12 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_14 , V_10 = V_11 ;
unsigned int V_20 , V_12 , V_18 , V_15 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_15 = V_14 & ( 1 << 0 ) ;
V_20 = V_21 [ ( V_10 >> 0 ) & 0x1f ] ;
V_12 = V_13 [ ( V_10 >> 5 ) & 0x03 ] ;
V_18 = V_19 [ ( V_10 >> 7 ) & 0x07 ] ;
if ( V_15 )
return V_12 * V_20 * V_18 * V_9 / 2 ;
return V_12 * V_20 * V_9 ;
}
static void T_2 F_13 ( void )
{
F_14 () ;
F_15 () ;
F_16 ( V_22 , L_4 , NULL ,
F_17 () ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( NULL , L_5 , NULL ,
V_23 | V_24 ,
3686400 ) ;
F_19 ( NULL , L_6 , NULL ,
V_23 | V_24 ,
32768 ) ;
F_19 ( NULL , L_7 , NULL , V_24 , 0 ) ;
F_20 ( NULL , L_8 , L_5 ,
0 , 26 , 1 ) ;
F_20 ( NULL , L_9 , L_5 ,
0 , 40 , 1 ) ;
}
static void T_2 F_21 ( void )
{
F_18 () ;
F_13 () ;
F_22 () ;
}
static void T_2 F_23 ( void )
{
struct V_2 * V_2 ;
struct V_25 * V_26 ;
const char * V_27 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_28 ) ; V_4 ++ ) {
V_26 = & V_28 [ V_4 ] ;
V_27 = V_26 -> V_29 ? V_26 -> V_29 : V_26 -> V_30 ;
V_2 = F_20 ( NULL , V_27 , V_26 -> V_31 , 0 , 1 , 1 ) ;
F_24 ( V_2 , V_26 -> V_30 , V_26 -> V_29 ) ;
}
}
int T_2 F_25 ( void )
{
F_21 () ;
F_23 () ;
return F_26 ( V_32 , F_2 ( V_32 ) ) ;
}
static void T_2 F_27 ( struct V_33 * V_34 )
{
F_25 () ;
F_28 ( V_34 ) ;
}
