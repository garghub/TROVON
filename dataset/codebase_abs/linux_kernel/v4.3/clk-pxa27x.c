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
V_3 [ 1 ] / 1000000 , ( V_3 [ 1 ] % 1000000 ) / 10000 ) ;
F_6 ( L_2 ,
V_3 [ 2 ] / 1000000 , ( V_3 [ 2 ] % 1000000 ) / 10000 ) ;
F_6 ( L_3 ,
V_3 [ 3 ] / 1000000 , ( V_3 [ 3 ] % 1000000 ) / 10000 ) ;
F_6 ( L_4 ,
V_3 [ 4 ] / 1000000 , ( V_3 [ 4 ] % 1000000 ) / 10000 ) ;
}
return ( unsigned int ) V_3 [ 0 ] / V_6 ;
}
bool F_7 ( void )
{
unsigned long V_7 = V_8 ;
return V_7 & ( 1 << V_9 ) ;
}
static unsigned long F_8 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int V_14 , V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
unsigned long V_7 = V_8 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_14 = V_13 & ( 1 << 0 ) ;
V_15 = V_13 & ( 1 << 2 ) ;
V_16 = V_7 & V_20 ;
V_18 = ( V_7 & V_21 ) >> V_22 ;
V_17 = V_16 * V_12 ;
V_19 = ( V_17 * V_18 ) / 2 ;
return V_14 ? V_19 : V_17 ;
}
static unsigned long F_9 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned int V_16 , V_23 ;
unsigned long V_7 = V_8 ;
unsigned long V_24 = V_25 ;
V_16 = V_7 & V_20 ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 ) {
if ( V_24 & ( 1 << V_27 ) )
return V_12 * 2 ;
else
return V_12 ;
}
if ( V_16 <= 7 )
return V_12 ;
if ( V_16 <= 16 )
return V_12 / 2 ;
return V_12 / 4 ;
}
static T_1 F_10 ( struct V_10 * V_11 )
{
unsigned int V_23 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 )
return V_28 ;
else
return V_29 ;
}
static void T_2 F_11 ( void )
{
F_12 ( NULL , L_5 , NULL ,
V_30 | V_31 ,
13 * V_32 ) ;
F_12 ( NULL , L_6 , NULL ,
V_30 | V_31 ,
32768 * V_6 ) ;
F_12 ( NULL , L_7 , NULL , V_31 , 0 ) ;
F_13 ( NULL , L_8 , L_5 , 0 , 24 , 1 ) ;
}
static unsigned long F_14 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int V_14 , V_15 , V_33 , V_23 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_14 = V_13 & ( 1 << 0 ) ;
V_15 = V_13 & ( 1 << 2 ) ;
V_33 = V_13 & ( 1 << 3 ) ;
if ( V_23 )
return V_12 ;
if ( V_15 )
return V_12 / 2 ;
else
return V_12 ;
}
static T_1 F_15 ( struct V_10 * V_11 )
{
unsigned long V_13 ;
unsigned int V_14 , V_15 , V_33 , V_23 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 )
return V_34 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_14 = V_13 & ( 1 << 0 ) ;
V_15 = V_13 & ( 1 << 2 ) ;
V_33 = V_13 & ( 1 << 3 ) ;
if ( V_15 || V_14 )
return V_35 ;
return V_36 ;
}
static unsigned long F_16 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_7 = V_8 ;
unsigned int V_18 = ( V_7 & V_21 ) >> V_22 ;
return ( V_12 / V_18 ) * 2 ;
}
static void T_2 F_17 ( void )
{
F_18 () ;
F_19 () ;
F_20 ( V_37 , L_9 , NULL ,
F_21 () ) ;
}
static unsigned long F_22 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int V_33 , V_23 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_33 = V_13 & ( 1 << 3 ) ;
if ( V_23 )
return V_12 ;
if ( V_33 )
return V_12 / 2 ;
else
return V_12 ;
}
static T_1 F_23 ( struct V_10 * V_11 )
{
unsigned int V_23 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 )
return V_38 ;
else
return V_39 ;
}
static unsigned long F_24 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned int V_40 , V_16 , V_23 ;
unsigned long V_24 = V_25 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
V_40 = V_24 & ( 1 << V_41 ) ;
V_16 = V_7 & V_20 ;
if ( V_23 || V_40 )
return V_12 ;
if ( V_16 <= 10 )
return V_12 ;
if ( V_16 <= 20 )
return V_12 / 2 ;
return V_12 / 4 ;
}
static T_1 F_25 ( struct V_10 * V_11 )
{
unsigned int V_23 , V_40 ;
unsigned long V_24 = V_25 ;
unsigned long V_7 = V_8 ;
V_23 = V_7 & ( 1 << V_26 ) ;
V_40 = V_24 & ( 1 << V_41 ) ;
if ( V_23 )
return V_42 ;
if ( V_40 )
return V_43 ;
else
return V_44 ;
}
static void T_2 F_26 ( void )
{
struct V_2 * V_2 ;
struct V_45 * V_46 ;
const char * V_47 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_27 ( V_48 ) ; V_4 ++ ) {
V_46 = & V_48 [ V_4 ] ;
V_47 = V_46 -> V_49 ? V_46 -> V_49 : V_46 -> V_50 ;
V_2 = F_13 ( NULL , V_47 , V_46 -> V_51 , 0 , 1 , 1 ) ;
F_28 ( V_2 , V_46 -> V_50 , V_46 -> V_49 ) ;
}
}
static void T_2 F_29 ( void )
{
F_11 () ;
F_17 () ;
F_30 () ;
F_31 () ;
F_32 () ;
}
int T_2 F_33 ( void )
{
F_29 () ;
F_26 () ;
return F_34 ( V_52 , F_27 ( V_52 ) ) ;
}
static void T_2 F_35 ( struct V_53 * V_54 )
{
F_33 () ;
F_36 ( V_54 ) ;
}
