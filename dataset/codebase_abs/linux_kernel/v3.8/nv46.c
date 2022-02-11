void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
if ( ! ( V_7 & 4 ) ) V_9 -> V_4 = ( 0 << 3 ) ;
else V_9 -> V_4 = ( 1 << 3 ) ;
V_9 -> V_4 |= 0x00000001 ;
V_9 -> V_4 |= V_4 ;
V_9 -> V_10 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
static int
F_3 ( struct V_11 * V_12 , struct V_11 * V_13 ,
struct V_14 * V_15 , void * V_16 , T_1 V_5 ,
struct V_11 * * V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
V_20 = F_4 ( V_12 , V_13 , V_15 , & V_19 ) ;
* V_17 = F_5 ( V_19 ) ;
if ( V_20 )
return V_20 ;
V_19 -> V_21 . V_22 = V_23 ;
V_19 -> V_21 . V_24 . V_25 = V_26 ;
V_19 -> V_21 . V_9 . V_27 = 15 ;
V_19 -> V_21 . V_9 . V_25 = F_1 ;
V_19 -> V_21 . V_9 . V_28 = V_29 ;
V_19 -> V_21 . V_9 . V_30 = V_31 ;
return F_6 ( & V_19 -> V_21 ) ;
}
