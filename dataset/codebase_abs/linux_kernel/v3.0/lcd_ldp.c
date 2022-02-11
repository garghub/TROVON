static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_5 , L_1 ) ;
F_2 ( V_6 , L_2 ) ;
F_2 ( V_7 , L_3 ) ;
F_2 ( V_8 , L_4 ) ;
F_3 ( V_6 , 0 ) ;
F_3 ( V_5 , 0 ) ;
F_3 ( V_7 , 0 ) ;
F_3 ( V_8 , 0 ) ;
#ifdef F_4
F_5 ( V_6 , 0 ) ;
#else
F_5 ( V_6 , 1 ) ;
#endif
F_5 ( V_5 , 1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_8 ) ;
F_7 ( V_7 ) ;
F_7 ( V_6 ) ;
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( 0 != F_9 ( V_9 , V_10 ,
V_11 ) )
return - V_12 ;
if ( 0 != F_9 ( V_9 , V_13 ,
V_14 ) )
return - V_12 ;
F_3 ( V_7 , 1 ) ;
F_3 ( V_8 , 1 ) ;
if ( 0 != F_9 ( V_9 , V_15 ,
V_16 ) )
return - V_12 ;
if ( 0 != F_9 ( V_9 , V_17 ,
V_18 ) )
return - V_12 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_3 ( V_7 , 0 ) ;
F_3 ( V_8 , 0 ) ;
F_9 ( V_9 , 0x0 , V_11 ) ;
F_9 ( V_9 , 0x0 , V_14 ) ;
F_11 ( 4 ) ;
}
static unsigned long F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_13 ( struct V_19 * V_20 )
{
F_14 ( & V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 )
{
return 0 ;
}
static int F_16 ( struct V_19 * V_20 , T_1 V_22 )
{
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
return 0 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_23 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_23 ) ;
}
