static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 = V_2 -> V_7 . V_8 ;
struct V_9 V_10 = {
. V_11 = V_12 ,
. V_13 = 3 ,
} ;
if ( V_2 -> V_7 . V_14 != V_15 )
V_6 = 0 ;
if ( V_2 -> V_7 . V_16 & ( V_17 | V_18 ) )
V_6 = 0 ;
V_10 . V_19 [ 0 ] = 0x01 ;
V_10 . V_19 [ 1 ] = V_6 > 0 ? 1 : 0 ;
V_10 . V_19 [ 2 ] = V_6 ;
return F_3 ( V_4 , & V_10 ) ;
}
static int F_4 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_2 ( V_21 -> V_5 . V_22 ) ;
V_2 = F_5 ( & V_21 -> V_5 , L_1 ,
& V_21 -> V_5 , V_4 , & V_23 ,
& V_24 ) ;
if ( F_6 ( V_2 ) )
return F_7 ( V_2 ) ;
F_8 ( V_21 , V_2 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
