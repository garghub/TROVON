static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = F_2 ( V_2 , 0x10020c ) & 0xff000000 ;
V_2 -> V_3 . type = V_5 ;
return 0 ;
}
static int
F_3 ( struct V_6 * V_7 , struct V_6 * V_8 ,
struct V_9 * V_10 , void * V_11 , T_1 V_4 ,
struct V_6 * * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
V_15 = F_4 ( V_7 , V_8 , V_10 , & V_14 ) ;
* V_12 = F_5 ( V_14 ) ;
if ( V_15 )
return V_15 ;
V_14 -> V_16 . V_17 = V_18 ;
V_14 -> V_16 . V_3 . V_19 = F_1 ;
V_14 -> V_16 . V_20 . V_21 = 12 ;
V_14 -> V_16 . V_20 . V_19 = V_22 ;
V_14 -> V_16 . V_20 . V_23 = V_24 ;
V_14 -> V_16 . V_20 . V_25 = V_26 ;
return F_6 ( & V_14 -> V_16 ) ;
}
