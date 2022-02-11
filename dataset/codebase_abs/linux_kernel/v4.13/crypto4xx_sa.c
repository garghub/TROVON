T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
union V_4 V_5 ;
if ( V_2 -> V_6 == V_7 )
V_5 . V_8 = ( (struct V_9 * ) V_2 -> V_10 ) -> V_11 ;
else
V_5 . V_8 = ( (struct V_9 * ) V_2 -> V_12 ) -> V_11 ;
V_3 = V_5 . V_13 . V_14
+ V_5 . V_13 . V_15
+ V_5 . V_13 . V_16
+ V_5 . V_13 . V_17
+ V_5 . V_13 . V_18
+ V_5 . V_13 . V_19
+ V_5 . V_13 . V_20
+ V_5 . V_13 . V_21
+ V_5 . V_13 . V_22
+ V_5 . V_13 . V_23
+ V_5 . V_13 . V_24
+ V_5 . V_13 . V_25
+ V_5 . V_13 . V_26
+ V_5 . V_13 . V_27 ;
return sizeof( struct V_9 ) + V_3 * 4 ;
}
T_1 F_2 ( struct V_1 * V_2 )
{
union V_4 V_5 ;
if ( V_2 -> V_6 == V_7 )
V_5 . V_8 = ( (struct V_9 * ) V_2 -> V_10 ) -> V_11 ;
else
V_5 . V_8 = ( (struct V_9 * ) V_2 -> V_12 ) -> V_11 ;
return ( V_5 . V_13 . V_24 + V_5 . V_13 . V_25 + V_5 . V_13 . V_26 + V_5 . V_13 . V_27 ) * 4 ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
union V_4 V_5 ;
if ( V_2 -> V_6 == V_7 )
V_5 . V_8 = ( (struct V_9 * ) V_2 -> V_10 ) -> V_11 ;
else
V_5 . V_8 = ( (struct V_9 * ) V_2 -> V_12 ) -> V_11 ;
return sizeof( struct V_9 ) ;
}
