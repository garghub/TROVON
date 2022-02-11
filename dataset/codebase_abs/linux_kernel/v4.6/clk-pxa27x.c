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
unsigned long V_7 = F_8 ( V_8 ) ;
return V_7 & ( 1 << V_9 ) ;
}
static unsigned long F_9 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int V_14 , V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
unsigned long V_7 = F_8 ( V_8 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_14 = V_13 & ( 1 << 0 ) ;
V_15 = V_13 & ( 1 << 2 ) ;
V_16 = V_7 & V_20 ;
V_18 = ( V_7 & V_21 ) >> V_22 ;
V_17 = V_16 * V_12 ;
V_19 = ( V_17 * V_18 ) / 2 ;
return V_14 ? V_19 : V_17 ;
}
static unsigned long F_10 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned int V_16 , V_23 ;
unsigned long V_7 = F_8 ( V_8 ) ;
unsigned long V_24 = F_8 ( V_25 ) ;
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
static T_1 F_11 ( struct V_10 * V_11 )
{
unsigned int V_23 ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 )
return V_28 ;
else
return V_29 ;
}
static void T_2 F_12 ( void )
{
F_13 ( NULL , L_5 , NULL ,
V_30 ,
13 * V_31 ) ;
F_13 ( NULL , L_6 , NULL ,
V_30 ,
32768 * V_6 ) ;
F_13 ( NULL , L_7 , NULL , 0 , 0 ) ;
F_14 ( NULL , L_8 , L_5 , 0 , 24 , 1 ) ;
}
static unsigned long F_15 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int V_14 , V_15 , V_32 , V_23 ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_14 = V_13 & ( 1 << 0 ) ;
V_15 = V_13 & ( 1 << 2 ) ;
V_32 = V_13 & ( 1 << 3 ) ;
if ( V_23 )
return V_12 ;
if ( V_15 )
return V_12 / 2 ;
else
return V_12 ;
}
static T_1 F_16 ( struct V_10 * V_11 )
{
unsigned long V_13 ;
unsigned int V_14 , V_15 , V_32 , V_23 ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 )
return V_33 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_14 = V_13 & ( 1 << 0 ) ;
V_15 = V_13 & ( 1 << 2 ) ;
V_32 = V_13 & ( 1 << 3 ) ;
if ( V_15 || V_14 )
return V_34 ;
return V_35 ;
}
static unsigned long F_17 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_7 = F_8 ( V_8 ) ;
unsigned int V_18 = ( V_7 & V_21 ) >> V_22 ;
return ( V_12 / V_18 ) * 2 ;
}
static void T_2 F_18 ( void )
{
F_19 () ;
F_20 () ;
F_21 ( V_36 , L_9 , NULL ,
F_22 () ) ;
}
static unsigned long F_23 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
unsigned int V_32 , V_23 ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_32 = V_13 & ( 1 << 3 ) ;
if ( V_23 )
return V_12 ;
if ( V_32 )
return V_12 / 2 ;
else
return V_12 ;
}
static T_1 F_24 ( struct V_10 * V_11 )
{
unsigned int V_23 ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
if ( V_23 )
return V_37 ;
else
return V_38 ;
}
static unsigned long F_25 ( struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned int V_39 , V_16 , V_23 ;
unsigned long V_24 = F_8 ( V_25 ) ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
V_39 = V_24 & ( 1 << V_40 ) ;
V_16 = V_7 & V_20 ;
if ( V_23 || V_39 )
return V_12 ;
if ( V_16 <= 10 )
return V_12 ;
if ( V_16 <= 20 )
return V_12 / 2 ;
return V_12 / 4 ;
}
static T_1 F_26 ( struct V_10 * V_11 )
{
unsigned int V_23 , V_39 ;
unsigned long V_24 = F_8 ( V_25 ) ;
unsigned long V_7 = F_8 ( V_8 ) ;
V_23 = V_7 & ( 1 << V_26 ) ;
V_39 = V_24 & ( 1 << V_40 ) ;
if ( V_23 )
return V_41 ;
if ( V_39 )
return V_42 ;
else
return V_43 ;
}
static void T_2 F_27 ( void )
{
struct V_2 * V_2 ;
struct V_44 * V_45 ;
const char * V_46 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_28 ( V_47 ) ; V_4 ++ ) {
V_45 = & V_47 [ V_4 ] ;
V_46 = V_45 -> V_48 ? V_45 -> V_48 : V_45 -> V_49 ;
V_2 = F_14 ( NULL , V_46 , V_45 -> V_50 , 0 , 1 , 1 ) ;
F_29 ( V_2 , V_45 -> V_49 , V_45 -> V_48 ) ;
}
}
static void T_2 F_30 ( void )
{
F_12 () ;
F_18 () ;
F_31 () ;
F_32 () ;
F_33 () ;
}
int T_2 F_34 ( void )
{
F_30 () ;
F_27 () ;
return F_35 ( V_51 , F_28 ( V_51 ) ) ;
}
static void T_2 F_36 ( struct V_52 * V_53 )
{
F_34 () ;
F_37 ( V_53 ) ;
}
