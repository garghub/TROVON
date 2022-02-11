static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = 0 ;
V_5 = F_2 ( V_2 -> V_6 , L_1 ,
V_7 | V_8 ,
& V_9 ,
V_10 , F_3 ( V_10 ) ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , & V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
return F_6 ( V_12 , V_14 + V_12 -> V_15 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_8 ( V_17 ,
V_20 ) ;
struct V_18 * V_21 = F_8 ( V_17 ,
V_22 ) ;
struct V_23 * V_24 = F_9 ( V_17 , V_25 ) ;
V_19 -> V_26 = V_19 -> V_27 = 48000 ;
V_21 -> V_26 = V_21 -> V_27 = 2 ;
F_10 ( V_24 ) ;
F_11 ( V_24 , V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_29 * V_30 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_30 -> V_31 ;
struct V_11 * V_13 = V_2 -> V_13 ;
int V_5 ;
V_5 = F_13 ( V_13 , V_32 ,
19200000 , V_33 ) ;
if ( V_5 < 0 ) {
F_14 ( V_2 -> V_34 , L_2 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_15 ( struct V_35 * V_36 )
{
V_37 . V_34 = & V_36 -> V_34 ;
return F_16 ( & V_36 -> V_34 , & V_37 ) ;
}
