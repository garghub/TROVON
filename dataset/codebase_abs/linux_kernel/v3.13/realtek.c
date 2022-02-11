static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_5 == V_6 )
V_3 = F_4 ( V_2 , V_7 ,
V_8 ) ;
else
V_3 = F_4 ( V_2 , V_7 , 0 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_5 == V_6 )
V_3 = F_4 ( V_2 , V_7 ,
V_9 ) ;
else
V_3 = F_4 ( V_2 , V_7 , 0 ) ;
return V_3 ;
}
static int T_1 F_6 ( void )
{
int V_10 ;
V_10 = F_7 ( & V_11 ) ;
if ( V_10 < 0 )
return - V_12 ;
V_10 = F_7 ( & V_13 ) ;
if ( V_10 < 0 )
return - V_12 ;
return F_7 ( & V_14 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_13 ) ;
F_9 ( & V_14 ) ;
}
