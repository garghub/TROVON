static int F_1 ( void )
{
static int V_1 ;
unsigned int V_2 = 0 , V_3 = 0 ;
T_1 V_4 ;
if ( V_1 )
return V_1 ;
V_4 = F_2 ( V_5 ) ;
if ( V_4 & ( V_6 | V_7 ) )
V_2 = F_3 ( V_4 ) ;
if ( V_4 & ( V_8 | V_9 ) )
V_3 = F_4 ( V_4 ) ;
V_1 = 1 << ( 11 + F_5 ( V_3 , V_2 ) ) ;
return V_1 ;
}
static T_1 F_6 ( unsigned int V_10 )
{
T_1 V_11 = V_10 * V_12 / F_1 () ;
return V_11 / 32 ;
}
unsigned int F_7 ( int V_13 )
{
struct V_14 * V_14 ;
unsigned long V_15 [ 5 ] ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_8 ( V_17 ) ; V_16 ++ ) {
V_14 = F_9 ( NULL , V_17 [ V_16 ] ) ;
if ( F_10 ( V_14 ) ) {
V_15 [ V_16 ] = 0 ;
} else {
V_15 [ V_16 ] = F_11 ( V_14 ) ;
F_12 ( V_14 ) ;
}
}
if ( V_13 ) {
F_13 ( L_1 ,
V_15 [ 1 ] / 1000000 , ( V_15 [ 1 ] % 1000000 ) / 10000 ) ;
F_13 ( L_2 ,
V_15 [ 2 ] / 1000000 , ( V_15 [ 2 ] % 1000000 ) / 10000 ) ;
F_13 ( L_3 ,
V_15 [ 3 ] / 1000000 , ( V_15 [ 3 ] % 1000000 ) / 10000 ) ;
}
return ( unsigned int ) V_15 [ 0 ] / V_18 ;
}
static unsigned long F_14 ( struct V_19 * V_20 ,
unsigned long V_21 )
{
unsigned long V_22 = F_15 ( V_23 ) ;
unsigned int V_24 = V_25 [ ( V_22 >> 5 ) & 0x03 ] ;
return V_21 / V_24 ;
}
static T_2 F_16 ( struct V_19 * V_20 )
{
unsigned long V_26 ;
unsigned int V_27 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_27 = V_26 & ( 1 << 0 ) ;
if ( V_27 )
return V_28 ;
return V_29 ;
}
static int F_17 ( struct V_19 * V_20 , T_2 V_30 )
{
if ( V_30 > V_28 )
return - V_31 ;
F_18 ( V_30 == V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 ,
struct V_32 * V_33 )
{
return F_20 ( V_20 , V_33 ) ;
}
static unsigned long F_21 ( struct V_19 * V_20 ,
unsigned long V_21 )
{
unsigned long V_22 = F_15 ( V_23 ) ;
unsigned int V_34 = V_35 [ ( V_22 >> 7 ) & 0x07 ] ;
return ( V_21 / V_34 ) * 2 ;
}
static unsigned long F_22 ( struct V_19 * V_20 ,
unsigned long V_21 )
{
unsigned long V_26 , V_22 = F_15 ( V_23 ) ;
unsigned int V_36 , V_24 , V_34 , V_27 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_27 = V_26 & ( 1 << 0 ) ;
V_36 = V_37 [ ( V_22 >> 0 ) & 0x1f ] ;
V_24 = V_25 [ ( V_22 >> 5 ) & 0x03 ] ;
V_34 = V_35 [ ( V_22 >> 7 ) & 0x07 ] ;
return V_24 * V_36 * V_34 * V_21 / 2 ;
}
static int F_23 ( struct V_19 * V_20 ,
struct V_32 * V_33 )
{
return F_24 ( V_33 , V_38 ,
F_8 ( V_38 ) ) ;
}
static int F_25 ( struct V_19 * V_20 , unsigned long V_39 ,
unsigned long V_21 )
{
int V_16 ;
F_26 ( L_4 , V_40 , V_39 , V_21 ) ;
for ( V_16 = 0 ; V_16 < F_8 ( V_38 ) ; V_16 ++ )
if ( V_38 [ V_16 ] . V_41 == V_39 )
break;
if ( V_16 >= F_8 ( V_38 ) )
return - V_31 ;
F_27 ( & V_38 [ V_16 ] , F_6 , V_42 , V_23 ) ;
return 0 ;
}
static void T_3 F_28 ( void )
{
F_29 ( V_43 , L_5 , NULL ,
F_30 () ) ;
F_29 ( V_43 , L_6 , NULL ,
F_31 () ) ;
F_29 ( V_44 , L_7 , NULL ,
F_32 () ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( NULL , L_8 , NULL ,
V_45 , 3686400 ) ;
F_34 ( NULL , L_9 , NULL ,
V_45 , 32768 ) ;
F_34 ( NULL , L_10 , NULL , 0 , 0 ) ;
F_35 ( NULL , L_11 , L_8 ,
0 , 26 , 1 ) ;
F_35 ( NULL , L_12 , L_8 ,
0 , 40 , 1 ) ;
}
static void T_3 F_36 ( void )
{
F_33 () ;
F_28 () ;
F_29 ( V_43 , L_13 , NULL ,
F_37 () ) ;
}
static void T_3 F_38 ( void )
{
struct V_14 * V_14 ;
struct V_46 * V_47 ;
const char * V_48 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_8 ( V_49 ) ; V_16 ++ ) {
V_47 = & V_49 [ V_16 ] ;
V_48 = V_47 -> V_50 ? V_47 -> V_50 : V_47 -> V_51 ;
V_14 = F_35 ( NULL , V_48 , V_47 -> V_52 , 0 , 1 , 1 ) ;
F_39 ( V_14 , V_47 -> V_51 , V_47 -> V_50 ) ;
}
}
int T_3 F_40 ( void )
{
F_36 () ;
F_38 () ;
return F_41 ( V_53 , F_8 ( V_53 ) ) ;
}
static void T_3 F_42 ( struct V_54 * V_55 )
{
F_40 () ;
F_43 ( V_55 ) ;
}
