static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
T_2 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 &= ~ ( V_2 ) ;
F_3 ( V_3 , V_1 ) ;
}
static void F_4 ( void T_1 * V_1 , T_2 V_4 )
{
T_2 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 |= V_4 ;
F_3 ( V_3 , V_1 ) ;
}
static void F_5 ( void T_1 * V_1 , T_2 V_2 , T_2 V_4 )
{
T_2 V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 &= ~ ( V_2 ) ;
V_3 |= V_4 ;
F_3 ( V_3 , V_1 ) ;
}
static T_2 F_6 ( void T_1 * V_1 , T_3 V_5 , T_3 V_6 )
{
return ( F_2 ( V_1 ) >> V_6 ) & V_5 ;
}
static int F_7 ( struct V_7 * V_8 , void T_1 * V_9 )
{
T_2 V_3 ;
int V_10 ;
F_3 ( 0 , V_9 + V_11 ) ;
F_8 ( 5 ) ;
F_4 ( V_9 + V_12 , F_9 ( 19 ) ) ;
F_5 ( V_9 + V_13 ,
( 0x7 << 24 ) ,
( 0x5 << 24 ) | F_9 ( 23 ) | F_9 ( 18 ) ) ;
F_5 ( V_9 + V_12 ,
( 0x3 << 16 ) | ( 0x1f << 8 ) | ( 0x3 << 6 ) ,
( 0x2 << 16 ) | ( 0x6 << 8 ) | ( 0x2 << 6 ) ) ;
F_4 ( V_9 + V_12 , F_9 ( 28 ) | F_9 ( 15 ) ) ;
F_1 ( V_9 + V_12 , F_9 ( 19 ) ) ;
F_5 ( V_9 + V_13 ,
( 0x7 << 20 ) , ( 0x3 << 20 ) ) ;
F_5 ( V_9 + V_14 ,
( 0x1f << 5 ) , ( 0x19 << 5 ) ) ;
F_8 ( 5 ) ;
F_4 ( V_9 + V_13 , ( 0x1 << 19 ) ) ;
V_10 = 250 ;
do {
V_3 = F_6 ( V_9 + V_13 , 0x7 , 28 ) ;
if ( V_3 == 0x02 )
break;
if ( -- V_10 == 0 ) {
F_10 ( V_8 , L_1 ) ;
return - V_15 ;
}
F_11 ( 1 ) ;
} while ( 1 );
F_4 ( V_9 + V_14 , ( 0x1 << 24 ) ) ;
V_10 = 100 ;
do {
V_3 = F_6 ( V_9 + V_14 , 0x1 , 24 ) ;
if ( V_3 == 0x00 )
break;
if ( -- V_10 == 0 ) {
F_10 ( V_8 , L_2 ) ;
return - V_15 ;
}
F_11 ( 1 ) ;
} while ( 1 );
F_8 ( 15 ) ;
F_3 ( 0x7 , V_9 + V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_16 * V_17 )
{
void T_1 * V_18 = F_13 ( V_17 ) ;
struct V_19 * V_20 = V_17 -> V_21 -> V_22 ;
F_5 ( V_20 -> V_23 + V_24 , 0x0000ff00 , 0x00004400 ) ;
F_4 ( V_18 + V_25 , V_26 ) ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = & V_28 -> V_8 ;
struct V_19 * V_20 ;
int V_29 ;
V_20 = F_15 ( V_28 ) ;
if ( F_16 ( V_20 ) )
return F_17 ( V_20 ) ;
V_20 -> V_30 = F_12 ;
V_29 = F_18 ( V_20 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_7 ( V_8 , V_20 -> V_23 ) ;
if ( V_29 )
goto V_31;
V_20 -> V_32 = V_33 | V_34 |
V_35 ;
if ( ! V_36 )
V_20 -> V_32 |= V_37 ;
V_29 = F_19 ( V_28 , V_20 , & V_38 ,
& V_39 ) ;
if ( V_29 )
goto V_31;
return 0 ;
V_31:
F_20 ( V_20 ) ;
return V_29 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_40 * V_21 = F_22 ( V_8 ) ;
struct V_19 * V_20 = V_21 -> V_22 ;
int V_29 ;
V_29 = F_18 ( V_20 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_7 ( V_8 , V_20 -> V_23 ) ;
if ( V_29 )
goto V_31;
V_29 = F_23 ( V_8 ) ;
if ( V_29 )
goto V_31;
return 0 ;
V_31:
F_20 ( V_20 ) ;
return V_29 ;
}
