static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , V_12 |
V_13 | V_14 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 | V_14 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_10 , V_15 , 12288000 ,
V_16 ) ;
return V_11 ;
}
static int F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_21 ;
V_20 -> V_22 = & V_18 -> V_22 ;
return F_5 ( & V_21 ) ;
}
static int T_1 F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_7 ( V_18 ) ;
F_8 ( V_20 ) ;
return 0 ;
}
