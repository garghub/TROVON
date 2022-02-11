static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
V_10 = F_2 ( V_4 ) * 256 ;
return F_3 ( V_9 , 0 , V_10 , V_11 ) ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_16 ;
int V_17 ;
V_15 -> V_18 = & V_13 -> V_18 ;
V_17 = F_5 ( V_15 ) ;
if ( V_17 )
F_6 ( & V_13 -> V_18 , L_1 ,
V_17 ) ;
return V_17 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
F_9 ( V_15 ) ;
return 0 ;
}
