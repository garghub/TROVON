static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = 0 ;
V_5 = F_2 ( V_4 , L_1 ,
V_6 | V_7 , & V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_3 ( & V_8 ,
F_4 ( V_9 ) ,
V_9 ) ;
if ( V_5 )
return V_5 ;
F_5 ( V_4 , & V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 ,
V_14 ) ;
struct V_12 * V_15 = F_7 ( V_11 ,
V_16 ) ;
V_13 -> V_17 = V_13 -> V_18 = 48000 ;
V_15 -> V_17 = V_15 -> V_18 = 2 ;
F_8 ( & V_11 -> V_19 [ V_20 -
V_21 ] ,
V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_26 * V_27 = V_2 -> V_27 ;
int V_5 ;
V_5 = F_10 ( V_27 , V_28 , 24000000 ,
V_29 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 -> V_30 , L_2 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_31 * V_32 = & V_4 -> V_32 ;
struct V_33 * V_34 = F_13 ( V_2 -> V_35 -> V_30 ) ;
struct V_36 * V_37 = V_34 -> V_38 ;
int V_5 ;
V_5 = F_14 ( V_37 , V_39 ,
V_40 ,
V_41 , 9 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 -> V_30 , L_3 ) ;
return V_5 ;
}
F_15 ( V_32 , L_4 ) ;
F_15 ( V_32 , L_5 ) ;
F_15 ( V_32 , L_6 ) ;
F_15 ( V_32 , L_7 ) ;
F_15 ( V_32 , L_8 ) ;
F_15 ( V_32 , L_9 ) ;
return 0 ;
}
static int F_16 ( struct V_42 * V_43 )
{
V_44 . V_30 = & V_43 -> V_30 ;
return F_17 ( & V_44 ) ;
}
static int F_18 ( struct V_42 * V_43 )
{
F_19 ( & V_44 ) ;
return 0 ;
}
