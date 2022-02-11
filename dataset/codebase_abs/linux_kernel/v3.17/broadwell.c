static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ,
V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
V_6 -> V_10 = V_6 -> V_11 = 48000 ;
V_8 -> V_10 = V_8 -> V_11 = 2 ;
F_3 ( & V_4 -> V_12 [ V_13 -
V_14 ] ,
V_15 ) ;
return 0 ;
}
static int F_4 ( struct V_16 * V_17 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_21 ;
V_21 = F_5 ( V_20 , V_22 , 24000000 ,
V_23 ) ;
if ( V_21 < 0 ) {
F_6 ( V_2 -> V_24 , L_1 ) ;
return V_21 ;
}
return V_21 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_29 * V_30 = F_8 ( V_2 -> V_31 -> V_24 ) ;
struct V_32 * V_33 = V_30 -> V_34 ;
int V_21 ;
V_21 = F_9 ( V_33 , V_35 ,
V_36 ,
V_37 , 9 ) ;
if ( V_21 < 0 ) {
F_6 ( V_2 -> V_24 , L_2 ) ;
return V_21 ;
}
F_10 ( V_28 , L_3 ) ;
F_10 ( V_28 , L_4 ) ;
F_10 ( V_28 , L_5 ) ;
F_10 ( V_28 , L_6 ) ;
F_10 ( V_28 , L_7 ) ;
F_10 ( V_28 , L_8 ) ;
return 0 ;
}
static int F_11 ( struct V_38 * V_39 )
{
V_40 . V_24 = & V_39 -> V_24 ;
return F_12 ( & V_40 ) ;
}
static int F_13 ( struct V_38 * V_39 )
{
F_14 ( & V_40 ) ;
return 0 ;
}
