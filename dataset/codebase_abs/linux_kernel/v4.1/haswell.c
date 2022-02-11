static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ,
V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
V_6 -> V_10 = V_6 -> V_11 = 48000 ;
V_8 -> V_10 = V_8 -> V_11 = 2 ;
F_3 ( V_4 , V_12 ) ;
return 0 ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_16 * V_17 = V_2 -> V_17 ;
int V_18 ;
V_18 = F_5 ( V_17 , V_19 , 12288000 ,
V_20 ) ;
if ( V_18 < 0 ) {
F_6 ( V_2 -> V_21 , L_1 ) ;
return V_18 ;
}
F_7 ( V_2 -> V_22 , 0x83 , 0xffff , 0x8000 ) ;
return V_18 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_9 ( V_2 -> V_25 -> V_21 ) ;
struct V_26 * V_27 = V_24 -> V_28 ;
int V_18 ;
V_18 = F_10 ( V_27 , V_29 ,
V_30 ,
V_31 , 9 ) ;
if ( V_18 < 0 ) {
F_6 ( V_2 -> V_21 , L_2 ) ;
return V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_32 * V_33 )
{
V_34 . V_21 = & V_33 -> V_21 ;
return F_12 ( & V_33 -> V_21 , & V_34 ) ;
}
