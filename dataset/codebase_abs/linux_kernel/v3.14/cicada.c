static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ,
V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_6 ,
V_7 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_8 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_9 == V_10 )
V_3 = F_2 ( V_2 , V_11 ,
V_12 ) ;
else
V_3 = F_2 ( V_2 , V_11 , 0 ) ;
return V_3 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( V_13 ,
F_8 ( V_13 ) ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( V_13 ,
F_8 ( V_13 ) ) ;
}
