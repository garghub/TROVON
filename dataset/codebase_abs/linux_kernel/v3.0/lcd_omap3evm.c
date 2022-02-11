static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_5 , L_1 ) ;
F_2 ( V_6 , L_2 ) ;
F_2 ( V_7 , L_3 ) ;
F_2 ( V_8 , L_4 ) ;
F_2 ( V_9 , L_5 ) ;
F_3 ( V_8 , 1 ) ;
F_3 ( V_7 , 1 ) ;
F_3 ( V_9 , 0 ) ;
F_3 ( V_5 , 1 ) ;
F_3 ( V_6 , 1 ) ;
F_4 ( V_10 , 0x11 , V_11 ) ;
F_4 ( V_12 , 0x01 , V_13 ) ;
F_4 ( V_12 , 0x02 , V_14 ) ;
V_15 = 100 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_9 ) ;
F_6 ( V_8 ) ;
F_6 ( V_7 ) ;
F_6 ( V_6 ) ;
F_6 ( V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_16 , 0 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_8 ( V_16 , 1 ) ;
}
static unsigned long F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
T_1 V_18 ;
if ( ( V_17 >= 0 ) && ( V_17 <= 100 ) ) {
V_18 = ( 125 * ( 100 - V_17 ) ) / 100 + 2 ;
F_4 ( V_12 , V_18 , V_14 ) ;
V_15 = V_17 ;
}
return 0 ;
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
return V_15 ;
}
static unsigned int F_13 ( struct V_1 * V_2 )
{
return 100 ;
}
static int F_14 ( struct V_19 * V_20 )
{
F_15 ( & V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 )
{
return 0 ;
}
static int F_17 ( struct V_19 * V_20 ,
T_2 V_22 )
{
return 0 ;
}
static int F_18 ( struct V_19 * V_20 )
{
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_23 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_23 ) ;
}
