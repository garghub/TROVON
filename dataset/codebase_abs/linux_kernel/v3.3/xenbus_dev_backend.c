static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( ! F_2 ( V_4 ) )
return - V_5 ;
return F_3 ( V_1 , V_3 ) ;
}
static long F_4 ( struct V_2 * V_2 , unsigned int V_6 , unsigned long V_7 )
{
if ( ! F_2 ( V_4 ) )
return - V_5 ;
switch ( V_6 ) {
case V_8 :
if ( V_9 > 0 )
return V_9 ;
return - V_10 ;
default:
return - V_11 ;
}
}
static int F_5 ( struct V_2 * V_2 , struct V_12 * V_13 )
{
T_1 V_14 = V_13 -> V_15 - V_13 -> V_16 ;
if ( ! F_2 ( V_4 ) )
return - V_5 ;
if ( ( V_14 > V_17 ) || ( V_13 -> V_18 != 0 ) )
return - V_19 ;
if ( F_6 ( V_13 , V_13 -> V_16 ,
F_7 ( V_20 ) ,
V_14 , V_13 -> V_21 ) )
return - V_22 ;
return 0 ;
}
static int T_2 F_8 ( void )
{
int V_23 ;
if ( ! F_9 () )
return - V_10 ;
V_23 = F_10 ( & V_24 ) ;
if ( V_23 )
F_11 ( V_25 L_1 ) ;
return V_23 ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_24 ) ;
}
