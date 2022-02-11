static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ,
V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
int V_10 ;
V_6 -> V_11 = V_6 -> V_12 = 48000 ;
V_8 -> V_11 = V_8 -> V_12 = 2 ;
F_3 ( V_4 , V_13 ) ;
V_10 = F_4 ( V_2 -> V_14 ,
V_15 |
V_16 |
V_17 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_18 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_6 ( V_2 -> V_14 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_18 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
return F_8 ( V_20 -> V_21 , 0 ,
V_7 ,
& V_22 ) ;
}
static int F_9 ( struct V_23 * V_24 )
{
int V_25 = 0 ;
V_26 . V_18 = & V_24 -> V_18 ;
V_25 = F_10 ( & V_24 -> V_18 , & V_26 ) ;
if ( V_25 ) {
F_5 ( & V_24 -> V_18 , L_3 ,
V_25 ) ;
return V_25 ;
}
F_11 ( V_24 , & V_26 ) ;
return V_25 ;
}
