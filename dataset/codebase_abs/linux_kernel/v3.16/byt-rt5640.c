static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 ,
F_3 ( V_4 ) * 256 ,
V_12 ) ;
if ( V_10 < 0 ) {
F_4 ( V_9 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_5 ( V_9 , 0 , V_14 ,
F_3 ( V_4 ) * 64 ,
F_3 ( V_4 ) * 256 ) ;
if ( V_10 < 0 ) {
F_4 ( V_9 -> V_13 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_15 )
{
int V_10 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_20 * V_21 = V_15 -> V_21 ;
V_21 -> V_19 . V_22 = true ;
V_10 = F_7 ( V_21 , V_23 ,
F_8 ( V_23 ) ) ;
if ( V_10 ) {
F_4 ( V_21 -> V_13 , L_3 ) ;
return V_10 ;
}
F_9 ( V_19 , L_4 ) ;
F_9 ( V_19 , L_5 ) ;
F_9 ( V_19 , L_6 ) ;
F_9 ( V_19 , L_7 ) ;
F_9 ( V_19 , L_8 ) ;
F_9 ( V_19 , L_9 ) ;
return V_10 ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_20 * V_21 = & V_26 ;
V_21 -> V_13 = & V_25 -> V_13 ;
return F_11 ( & V_25 -> V_13 , V_21 ) ;
}
