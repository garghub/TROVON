static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_2 () ) {
V_5 = V_6 ;
V_7 = V_8 ;
} else {
V_5 = V_9 ;
V_7 = V_10 ;
}
F_3 ( V_5 , L_1 ) ;
F_3 ( V_7 , L_2 ) ;
F_4 ( V_5 , 0 ) ;
F_4 ( V_7 , 0 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_7 ) ;
F_6 ( V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 ;
T_1 V_13 , V_14 ;
if ( F_2 () ) {
V_12 = V_15 ;
V_11 = V_16 ;
V_14 = V_17 ;
V_13 = V_18 ;
if ( F_8 () > V_19 ) {
F_9 ( V_20 , V_21 ,
V_22 ) ;
F_9 ( V_20 , V_23 ,
V_24 ) ;
}
} else {
V_12 = V_25 ;
V_11 = V_26 ;
V_14 = V_27 ;
V_13 = V_28 ;
}
F_10 ( V_5 , 1 ) ;
F_10 ( V_7 , 1 ) ;
if ( 0 != F_9 ( V_20 , V_11 , V_12 ) )
return - V_29 ;
if ( 0 != F_9 ( V_20 , V_13 , V_14 ) )
return - V_29 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_10 ( V_5 , 0 ) ;
F_10 ( V_7 , 0 ) ;
if ( F_8 () > V_19 ) {
F_9 ( V_20 , 0x0 , V_22 ) ;
F_9 ( V_20 , 0x0 , V_24 ) ;
F_12 ( 4 ) ;
}
}
static unsigned long F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_30 * V_31 )
{
F_15 ( & V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 )
{
return 0 ;
}
static int F_17 ( struct V_30 * V_31 ,
T_2 V_33 )
{
return 0 ;
}
static int F_18 ( struct V_30 * V_31 )
{
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_34 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_34 ) ;
}
