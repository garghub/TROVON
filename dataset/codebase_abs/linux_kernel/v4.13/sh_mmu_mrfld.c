static unsigned int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return V_3 >> V_4 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
unsigned int V_6 = V_2 -> V_7 -> V_8 ;
return ( T_1 ) ( ( V_5 & ~ V_6 ) << V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned int V_5 = F_1 ( V_2 , V_3 ) ;
F_4 ( F_5 ( V_5 ) ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned int V_5 = F_1 ( V_2 , V_3 ) ;
return F_5 ( V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 () ;
}
