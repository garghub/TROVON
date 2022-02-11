static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 , L_1 , V_6 |
V_7 | V_8 | V_9 ,
& V_10 , V_11 , F_3 ( V_11 ) ) ;
F_2 ( V_2 -> V_5 , L_2 , V_12 ,
& V_13 , V_14 ,
F_3 ( V_14 ) ) ;
F_4 ( V_4 , & V_10 , V_6 ,
V_7 , V_8 , V_9 ) ;
F_5 ( V_4 , & V_10 , V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_5 = & V_18 ;
int V_19 ;
V_5 -> V_20 = & V_16 -> V_20 ;
V_19 = F_7 ( V_5 ) ;
if ( V_19 )
F_8 ( & V_16 -> V_20 , L_3 ,
V_19 ) ;
return V_19 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_5 = F_10 ( V_16 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
