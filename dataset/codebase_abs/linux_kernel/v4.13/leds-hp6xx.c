static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_6 ) ;
if ( V_4 )
F_3 ( V_5 & ( ~ V_7 ) , V_6 ) ;
else
F_3 ( V_5 | V_7 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_2 V_8 ;
V_8 = F_5 ( V_9 ) ;
if ( V_4 )
F_6 ( V_8 & ( ~ V_10 ) , V_9 ) ;
else
F_6 ( V_8 | V_10 , V_9 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_8 ( & V_12 -> V_14 , & V_15 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( & V_12 -> V_14 , & V_16 ) ;
}
