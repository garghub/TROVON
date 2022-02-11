static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_7 , 1 ) ;
else if ( V_5 & V_8 )
F_2 ( V_7 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_9 , 0 ) ;
else if ( V_5 & V_8 )
F_2 ( V_9 , 1 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
F_5 ( V_15 , V_16 ,
F_6 ( V_16 ) ) ;
F_7 ( V_15 , V_17 , F_6 ( V_17 ) ) ;
return 0 ;
}
static int T_1 F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_22 ;
int V_23 ;
V_23 = F_9 ( V_24 ,
F_6 ( V_24 ) ) ;
if ( V_23 )
return V_23 ;
V_21 -> V_25 = & V_19 -> V_25 ;
V_23 = F_10 ( V_21 ) ;
if ( V_23 ) {
F_11 ( & V_19 -> V_25 , L_1 ,
V_23 ) ;
F_12 ( V_24 , F_6 ( V_24 ) ) ;
}
return V_23 ;
}
static int T_2 F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_14 ( V_19 ) ;
F_12 ( V_24 , F_6 ( V_24 ) ) ;
F_15 ( V_21 ) ;
return 0 ;
}
