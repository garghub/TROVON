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
return ( V_11 - 31 ) / 32 ;
}
unsigned int F_7 ( int V_13 )
{
struct V_14 * V_14 ;
unsigned long V_15 [ 5 ] ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 5 ; V_16 ++ ) {
V_14 = F_8 ( NULL , V_17 [ V_16 ] ) ;
if ( F_9 ( V_14 ) ) {
V_15 [ V_16 ] = 0 ;
} else {
V_15 [ V_16 ] = F_10 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
if ( V_13 ) {
F_12 ( L_1 ,
V_15 [ 1 ] / 1000000 , ( V_15 [ 1 ] % 1000000 ) / 10000 ) ;
F_12 ( L_2 ,
V_15 [ 2 ] / 1000000 , ( V_15 [ 2 ] % 1000000 ) / 10000 ) ;
F_12 ( L_3 ,
V_15 [ 3 ] / 1000000 , ( V_15 [ 3 ] % 1000000 ) / 10000 ) ;
F_12 ( L_4 ,
V_15 [ 4 ] / 1000000 , ( V_15 [ 4 ] % 1000000 ) / 10000 ) ;
}
return ( unsigned int ) V_15 [ 0 ] / V_18 ;
}
bool F_13 ( void )
{
unsigned long V_19 = F_14 ( V_20 ) ;
return V_19 & ( 1 << V_21 ) ;
}
static unsigned long F_15 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned long V_25 ;
unsigned int V_26 , V_27 ;
unsigned int V_28 , V_29 , V_30 , V_31 ;
unsigned long V_19 = F_14 ( V_20 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_26 = V_25 & ( 1 << 0 ) ;
V_27 = V_25 & ( 1 << 2 ) ;
V_28 = V_19 & V_32 ;
V_30 = ( V_19 & V_33 ) >> V_34 ;
V_29 = V_28 * V_24 ;
V_31 = ( V_29 * V_30 ) / 2 ;
return V_31 ;
}
static int F_16 ( struct V_22 * V_23 ,
struct V_35 * V_36 )
{
return F_17 ( V_36 , V_37 ,
F_18 ( V_37 ) ) ;
}
static int F_19 ( struct V_22 * V_23 , unsigned long V_38 ,
unsigned long V_24 )
{
int V_16 ;
F_20 ( L_5 , V_39 , V_38 , V_24 ) ;
for ( V_16 = 0 ; V_16 < F_18 ( V_37 ) ; V_16 ++ )
if ( V_37 [ V_16 ] . V_40 == V_38 )
break;
if ( V_16 >= F_18 ( V_37 ) )
return - V_41 ;
F_21 ( & V_37 [ V_16 ] , F_6 , V_42 , V_43 ) ;
return 0 ;
}
static unsigned long F_22 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned int V_28 , V_44 ;
unsigned long V_19 = F_14 ( V_20 ) ;
unsigned long V_45 = F_14 ( V_43 ) ;
V_28 = V_19 & V_32 ;
V_44 = V_19 & ( 1 << V_46 ) ;
if ( V_44 ) {
if ( V_45 & ( 1 << V_47 ) )
return V_24 * 2 ;
else
return V_24 ;
}
if ( V_28 <= 7 )
return V_24 ;
if ( V_28 <= 16 )
return V_24 / 2 ;
return V_24 / 4 ;
}
static T_2 F_23 ( struct V_22 * V_23 )
{
unsigned int V_44 ;
unsigned long V_19 = F_14 ( V_20 ) ;
V_44 = V_19 & ( 1 << V_46 ) ;
if ( V_44 )
return V_48 ;
else
return V_49 ;
}
static void T_3 F_24 ( void )
{
F_25 ( NULL , L_6 , NULL ,
V_50 ,
13 * V_51 ) ;
F_25 ( NULL , L_7 , NULL ,
V_50 ,
32768 * V_18 ) ;
F_25 ( NULL , L_8 , NULL , 0 , 0 ) ;
F_26 ( NULL , L_9 , L_6 , 0 , 24 , 1 ) ;
}
static T_2 F_27 ( struct V_22 * V_23 )
{
unsigned long V_25 ;
unsigned int V_26 , V_27 , V_44 ;
unsigned long V_19 = F_14 ( V_20 ) ;
V_44 = V_19 & ( 1 << V_46 ) ;
if ( V_44 )
return V_52 ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_26 = V_25 & ( 1 << 0 ) ;
V_27 = V_25 & ( 1 << 2 ) ;
if ( V_27 || V_26 )
return V_53 ;
return V_54 ;
}
static int F_28 ( struct V_22 * V_23 , T_2 V_55 )
{
if ( V_55 > V_53 )
return - V_41 ;
F_29 ( V_55 == V_53 ) ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 ,
struct V_35 * V_36 )
{
return F_31 ( V_23 , V_36 ) ;
}
static unsigned long F_32 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned long V_19 = F_14 ( V_20 ) ;
unsigned int V_30 = ( V_19 & V_33 ) >> V_34 ;
return ( V_24 / V_30 ) * 2 ;
}
static void T_3 F_33 ( void )
{
F_34 ( V_56 , L_10 , NULL ,
F_35 () ) ;
F_34 ( V_56 , L_11 , NULL ,
F_36 () ) ;
F_34 ( V_57 , L_12 , NULL ,
F_37 () ) ;
}
static unsigned long F_38 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned long V_25 ;
unsigned int V_58 , V_44 ;
unsigned long V_19 = F_14 ( V_20 ) ;
V_44 = V_19 & ( 1 << V_46 ) ;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_58 = V_25 & ( 1 << 3 ) ;
if ( V_44 )
return V_24 ;
if ( V_58 )
return V_24 ;
else
return V_24 / 2 ;
}
static T_2 F_39 ( struct V_22 * V_23 )
{
unsigned int V_44 ;
unsigned long V_19 = F_14 ( V_20 ) ;
V_44 = V_19 & ( 1 << V_46 ) ;
if ( V_44 )
return V_59 ;
else
return V_60 ;
}
static unsigned long F_40 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned int V_61 , V_28 , V_44 ;
unsigned long V_45 = F_14 ( V_43 ) ;
unsigned long V_19 = F_14 ( V_20 ) ;
V_44 = V_19 & ( 1 << V_46 ) ;
V_61 = V_45 & ( 1 << V_62 ) ;
V_28 = V_19 & V_32 ;
if ( V_44 || V_61 )
return V_24 ;
if ( V_28 <= 10 )
return V_24 ;
if ( V_28 <= 20 )
return V_24 / 2 ;
return V_24 / 4 ;
}
static T_2 F_41 ( struct V_22 * V_23 )
{
unsigned int V_44 , V_61 ;
unsigned long V_45 = F_14 ( V_43 ) ;
unsigned long V_19 = F_14 ( V_20 ) ;
V_44 = V_19 & ( 1 << V_46 ) ;
V_61 = V_45 & ( 1 << V_62 ) ;
if ( V_44 )
return V_63 ;
if ( V_61 )
return V_64 ;
else
return V_65 ;
}
static void T_3 F_42 ( void )
{
struct V_14 * V_14 ;
struct V_66 * V_67 ;
const char * V_68 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_18 ( V_69 ) ; V_16 ++ ) {
V_67 = & V_69 [ V_16 ] ;
V_68 = V_67 -> V_70 ? V_67 -> V_70 : V_67 -> V_71 ;
V_14 = F_26 ( NULL , V_68 , V_67 -> V_72 , 0 , 1 , 1 ) ;
F_43 ( V_14 , V_67 -> V_71 , V_67 -> V_70 ) ;
}
}
static void T_3 F_44 ( void )
{
F_24 () ;
F_33 () ;
F_34 ( V_56 , L_13 , NULL ,
F_45 () ) ;
F_34 ( V_56 , L_14 , NULL ,
F_46 () ) ;
F_47 () ;
}
int T_3 F_48 ( void )
{
F_44 () ;
F_42 () ;
return F_49 ( V_73 , F_18 ( V_73 ) ) ;
}
static void T_3 F_50 ( struct V_74 * V_75 )
{
F_48 () ;
F_51 ( V_75 ) ;
}
