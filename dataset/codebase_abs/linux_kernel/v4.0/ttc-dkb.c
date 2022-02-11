static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , L_1 , V_5
| V_6 | V_7 | V_8 ,
& V_9 ) ;
F_3 ( & V_9 , F_4 ( V_10 ) ,
V_10 ) ;
F_2 ( V_4 , L_2 , V_11 ,
& V_12 ) ;
F_3 ( & V_12 , F_4 ( V_13 ) ,
V_13 ) ;
F_5 ( V_4 , & V_9 , V_5 ,
V_6 , V_7 , V_8 ) ;
F_6 ( V_4 , & V_9 , V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_18 ;
int V_19 ;
V_17 -> V_20 = & V_15 -> V_20 ;
V_19 = F_8 ( V_17 ) ;
if ( V_19 )
F_9 ( & V_15 -> V_20 , L_3 ,
V_19 ) ;
return V_19 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_12 ( V_17 ) ;
return 0 ;
}
