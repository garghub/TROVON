static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
V_4 -> V_5 -> V_6 ( V_4 ) ;
F_2 ( & V_4 -> V_7 , L_1 , V_1 ) ;
return V_8 ;
}
static int F_3 ( struct V_3 * V_4 )
{
int V_9 ;
int V_10 = 0 ;
if ( V_4 -> V_5 -> V_11 )
V_10 = V_4 -> V_5 -> V_11 ( V_4 , & V_12 ) ;
if ( V_10 < 0 )
return - V_13 ;
V_9 = V_4 -> V_5 -> V_14 ( V_4 , F_1 , L_2 , V_15 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_5 -> V_16 ( V_4 , V_17 , F_4 ( V_17 ) ) ;
V_9 = - V_18 ;
if ( V_4 -> V_5 -> V_19 )
V_9 = V_4 -> V_5 -> V_19 ( V_4 , & V_12 , L_3 ) ;
if ( V_9 == - V_18 )
V_9 = 0 ;
if ( V_9 < 0 )
V_4 -> V_5 -> V_20 ( V_4 ) ;
return V_9 ;
}
static int F_5 ( struct V_3 * V_4 )
{
V_4 -> V_5 -> V_20 ( V_4 ) ;
return 0 ;
}
static int F_6 ( void )
{
int V_9 ;
V_9 = F_7 ( & V_12 ) ;
return V_9 ;
}
static void F_8 ( void )
{
F_9 ( & V_12 ) ;
}
