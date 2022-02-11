static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
F_2 ( V_9 , 50 ) ;
V_10 = F_3 ( V_9 , V_11 ,
F_4 ( V_4 ) * 512 ,
V_12 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_6 ( V_9 , 0 , V_14 ,
F_4 ( V_4 ) * 50 ,
F_4 ( V_4 ) * 512 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_8 ( V_4 ,
V_17 ) ;
struct V_15 * V_18 = F_8 ( V_4 ,
V_19 ) ;
V_16 -> V_20 = V_16 -> V_21 = 48000 ;
V_18 -> V_20 = V_18 -> V_21 = 2 ;
F_9 ( V_4 , V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 -> V_23 , 0 ,
V_17 ,
& V_24 ) ;
}
static int F_12 ( struct V_25 * V_26 )
{
int V_27 = 0 ;
V_28 . V_13 = & V_26 -> V_13 ;
V_27 = F_13 ( & V_26 -> V_13 , & V_28 ) ;
if ( V_27 ) {
F_5 ( & V_26 -> V_13 , L_3 , V_27 ) ;
return V_27 ;
}
F_14 ( V_26 , & V_28 ) ;
return V_27 ;
}
