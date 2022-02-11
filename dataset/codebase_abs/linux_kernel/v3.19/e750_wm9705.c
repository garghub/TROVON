static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_7 , 0 ) ;
else if ( V_5 & V_8 )
F_2 ( V_7 , 1 ) ;
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
F_5 ( V_15 , L_1 ) ;
F_5 ( V_15 , L_2 ) ;
F_5 ( V_15 , L_3 ) ;
F_5 ( V_15 , L_4 ) ;
F_5 ( V_15 , L_5 ) ;
F_5 ( V_15 , L_6 ) ;
F_5 ( V_15 , L_7 ) ;
F_5 ( V_15 , L_8 ) ;
F_5 ( V_15 , L_9 ) ;
return 0 ;
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_20 ;
int V_21 ;
V_21 = F_7 ( V_22 ,
F_8 ( V_22 ) ) ;
if ( V_21 )
return V_21 ;
V_19 -> V_23 = & V_17 -> V_23 ;
V_21 = F_9 ( V_19 ) ;
if ( V_21 ) {
F_10 ( & V_17 -> V_23 , L_10 ,
V_21 ) ;
F_11 ( V_22 , F_8 ( V_22 ) ) ;
}
return V_21 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_13 ( V_17 ) ;
F_11 ( V_22 , F_8 ( V_22 ) ) ;
F_14 ( V_19 ) ;
return 0 ;
}
