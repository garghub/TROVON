static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
F_3 ( & V_4 -> V_5 , L_1 , V_1 ) ;
return V_6 ;
}
static int F_4 ( struct V_3 * V_4 )
{
int V_7 ;
int V_8 = 0 ;
V_8 = F_5 ( V_4 , & V_9 ) ;
if ( V_8 < 0 )
return - V_10 ;
V_7 = F_6 ( V_4 , F_1 , L_2 , V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_4 , V_12 , F_8 ( V_12 ) ) ;
V_7 = F_9 ( V_4 , & V_9 , L_3 , 0 ) ;
if ( V_7 == - V_13 )
V_7 = 0 ;
if ( V_7 < 0 )
F_10 ( V_4 ) ;
return V_7 ;
}
static int F_11 ( struct V_3 * V_4 )
{
F_10 ( V_4 ) ;
return 0 ;
}
static int F_12 ( void )
{
int V_7 ;
V_7 = F_13 ( & V_9 ) ;
return V_7 ;
}
static void F_14 ( void )
{
F_15 ( & V_9 ) ;
}
