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
return ( unsigned int ) V_3 [ 0 ] / V_6 ;
}
static unsigned long F_7 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_10 , V_11 ;
V_10 = V_12 ;
V_11 = V_9 / 2 ;
V_11 /= ( ( V_10 >> 12 ) & 0x7fff ) ;
V_11 *= ( V_10 & 0xfff ) ;
return V_11 ;
}
static unsigned long F_8 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_13 = V_14 ;
unsigned long V_15 = F_9 ( V_16 ) ;
return ( V_9 / 48 ) * V_17 [ ( V_13 >> 23 ) & 0x7 ] /
V_18 [ ( V_15 >> 16 ) & 0x3 ] ;
}
static bool F_10 ( void )
{
unsigned long V_13 = V_14 ;
return V_13 & V_19 ;
}
static unsigned long F_11 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_13 = V_14 ;
unsigned int V_20 = ( V_13 >> 14 ) & 0x3 ;
if ( F_10 () )
return V_9 ;
return V_9 / 48 * V_21 [ V_20 ] ;
}
static T_1 F_12 ( struct V_7 * V_8 )
{
if ( F_10 () )
return V_22 ;
else
return V_23 ;
}
static unsigned long F_13 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
return V_9 ;
}
static T_1 F_14 ( struct V_7 * V_8 )
{
unsigned long V_24 ;
unsigned int V_25 ;
if ( F_10 () )
return V_26 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_25 = V_24 & 0x1 ;
if ( V_25 )
return V_27 ;
return V_28 ;
}
static unsigned long F_15 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_13 = V_14 ;
unsigned int V_29 = ( V_13 & V_30 ) >> 8 ;
unsigned int V_25 , V_24 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_25 = V_24 & 0x1 ;
return V_25 ? ( V_9 / V_29 ) * 2 : V_9 ;
}
static unsigned long F_16 ( struct V_7 * V_8 ,
unsigned long V_9 )
{
unsigned long V_13 = V_14 ;
unsigned int V_29 = ( V_13 & V_30 ) >> 8 ;
unsigned int V_31 = V_13 & V_32 ;
unsigned int V_25 , V_24 ;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
V_25 = V_24 & 0x1 ;
F_6 ( L_5 , V_9 , V_31 , V_29 ) ;
return V_25 ? V_9 * V_31 * V_29 : V_9 * V_31 ;
}
static void T_2 F_17 ( void )
{
F_18 () ;
F_19 () ;
F_20 ( V_33 , L_6 , NULL ,
F_21 () ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( NULL , L_7 , NULL ,
V_34 | V_35 ,
13 * V_36 ) ;
F_23 ( NULL , L_8 , NULL ,
V_34 | V_35 ,
32768 ) ;
F_23 ( NULL , L_9 , NULL ,
V_34 | V_35 ,
120 * V_36 ) ;
F_23 ( NULL , L_10 , NULL , V_35 , 0 ) ;
F_24 ( NULL , L_11 , L_7 , 0 , 48 , 1 ) ;
F_24 ( NULL , L_12 , L_9 ,
0 , 1 , 2 ) ;
}
static void T_2 F_25 ( void )
{
struct V_2 * V_2 ;
struct V_37 * V_38 ;
const char * V_39 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_26 ( V_40 ) ; V_4 ++ ) {
V_38 = & V_40 [ V_4 ] ;
V_39 = V_38 -> V_41 ? V_38 -> V_41 : V_38 -> V_42 ;
V_2 = F_24 ( NULL , V_39 , V_38 -> V_43 , 0 , 1 , 1 ) ;
F_27 ( V_2 , V_38 -> V_42 , V_38 -> V_41 ) ;
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
( void V_44 * ) & V_45 , 11 , 0 , NULL ) ;
F_20 ( V_46 , L_14 , NULL ,
F_24 ( NULL , L_15 ,
L_7 , 0 , 1 , 4 ) ) ;
}
int T_2 F_33 ( void )
{
int V_47 ;
F_28 () ;
F_25 () ;
V_47 = F_34 ( V_48 , F_26 ( V_48 ) ) ;
if ( V_47 )
return V_47 ;
if ( F_35 () )
return F_34 ( V_49 ,
F_26 ( V_49 ) ) ;
if ( F_36 () || F_37 () )
return F_34 ( V_50 ,
F_26 ( V_50 ) ) ;
return F_34 ( V_51 , F_26 ( V_51 ) ) ;
}
static void T_2 F_38 ( struct V_52 * V_53 )
{
F_33 () ;
F_39 ( V_53 ) ;
}
