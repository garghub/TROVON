unsigned int F_1 ( int V_1 )
{
struct V_2 * V_2 ;
unsigned long V_3 [ 5 ] ;
int V_4 ;
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ ) {
V_2 = F_2 ( NULL , V_5 [ V_4 ] ) ;
if ( F_3 ( V_2 ) ) {
V_3 [ V_4 ] = 0 ;
} else {
V_3 [ V_4 ] = F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
}
if ( V_1 ) {
F_6 ( L_1 ,
V_3 [ 1 ] / 1000000 , ( V_3 [ 0 ] % 1000000 ) / 10000 ) ;
F_6 ( L_2 ,
V_3 [ 2 ] / 1000000 , ( V_3 [ 1 ] % 1000000 ) / 10000 ) ;
F_6 ( L_3 ,
V_3 [ 3 ] / 1000000 , ( V_3 [ 2 ] % 1000000 ) / 10000 ) ;
F_6 ( L_4 ,
V_3 [ 4 ] / 1000000 , ( V_3 [ 4 ] % 1000000 ) / 10000 ) ;
}
return ( unsigned int ) V_3 [ 0 ] ;
}
static unsigned long F_7 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
unsigned long V_9 , V_10 ;
V_9 = V_11 ;
V_10 = V_8 / 2 ;
V_10 /= ( ( V_9 >> 12 ) & 0x7fff ) ;
V_10 *= ( V_9 & 0xfff ) ;
return V_10 ;
}
static unsigned long F_8 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
unsigned long V_12 = V_13 ;
unsigned long V_14 = F_9 ( V_15 ) ;
return ( V_8 / 48 ) * V_16 [ ( V_12 >> 23 ) & 0x7 ] /
V_17 [ ( V_14 >> 16 ) & 0x3 ] ;
}
static bool F_10 ( void )
{
unsigned long V_12 = V_13 ;
return V_12 & V_18 ;
}
static unsigned long F_11 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
unsigned long V_12 = V_13 ;
unsigned int V_19 = ( V_12 >> 14 ) & 0x3 ;
if ( F_10 () )
return V_8 ;
return V_8 / 48 * V_20 [ V_19 ] ;
}
static T_1 F_12 ( struct V_6 * V_7 )
{
if ( F_10 () )
return V_21 ;
else
return V_22 ;
}
static unsigned long F_13 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
return V_8 ;
}
static T_1 F_14 ( struct V_6 * V_7 )
{
unsigned long V_23 ;
unsigned int V_24 ;
if ( F_10 () )
return V_25 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_24 = V_23 & 0x1 ;
if ( V_24 )
return V_26 ;
return V_27 ;
}
static unsigned long F_15 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
unsigned long V_12 = V_13 ;
unsigned int V_28 = ( V_12 & V_29 ) >> 8 ;
unsigned int V_24 , V_23 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_24 = V_23 & 0x1 ;
return V_24 ? ( V_8 / V_28 ) * 2 : V_8 ;
}
static unsigned long F_16 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
unsigned long V_12 = V_13 ;
unsigned int V_28 = ( V_12 & V_29 ) >> 8 ;
unsigned int V_30 = V_12 & V_31 ;
unsigned int V_24 , V_23 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_24 = V_23 & 0x1 ;
F_6 ( L_5 , V_8 , V_30 , V_28 ) ;
return V_24 ? V_8 * V_30 * V_28 : V_8 * V_30 ;
}
static void T_2 F_17 ( void )
{
F_18 () ;
F_19 () ;
F_20 ( V_32 , L_6 , NULL ,
F_21 () ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( NULL , L_7 , NULL ,
V_33 | V_34 ,
13 * V_35 ) ;
F_23 ( NULL , L_8 , NULL ,
V_33 | V_34 ,
32768 ) ;
F_23 ( NULL , L_9 , NULL ,
V_33 | V_34 ,
120 * V_35 ) ;
F_23 ( NULL , L_10 , NULL , V_34 , 0 ) ;
F_24 ( NULL , L_11 , L_7 , 0 , 48 , 1 ) ;
F_24 ( NULL , L_12 , L_9 ,
0 , 1 , 2 ) ;
}
static void T_2 F_25 ( void )
{
struct V_2 * V_2 ;
struct V_36 * V_37 ;
const char * V_38 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_26 ( V_39 ) ; V_4 ++ ) {
V_37 = & V_39 [ V_4 ] ;
V_38 = V_37 -> V_40 ? V_37 -> V_40 : V_37 -> V_41 ;
V_2 = F_24 ( NULL , V_38 , V_37 -> V_42 , 0 , 1 , 1 ) ;
F_27 ( V_2 , V_37 -> V_41 , V_37 -> V_40 ) ;
}
}
static void T_2 F_28 ( void )
{
F_22 () ;
F_17 () ;
F_29 () ;
F_30 () ;
F_31 () ;
F_32 ( NULL , L_13 , L_7 , 0 ,
( void V_43 * ) & V_44 , 11 , 0 , NULL ) ;
F_20 ( V_45 , L_14 , NULL ,
F_24 ( NULL , L_15 ,
L_7 , 0 , 1 , 4 ) ) ;
}
int T_2 F_33 ( void )
{
int V_46 ;
F_28 () ;
F_25 () ;
V_46 = F_34 ( V_47 , F_26 ( V_47 ) ) ;
if ( V_46 )
return V_46 ;
if ( F_35 () )
return F_34 ( V_48 ,
F_26 ( V_48 ) ) ;
if ( F_36 () || F_37 () )
return F_34 ( V_49 ,
F_26 ( V_49 ) ) ;
return F_34 ( V_50 , F_26 ( V_50 ) ) ;
}
static void T_2 F_38 ( struct V_51 * V_52 )
{
F_33 () ;
F_39 ( V_52 ) ;
}
