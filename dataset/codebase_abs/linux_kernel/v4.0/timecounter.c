void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_4 -> V_7 ( V_4 ) ;
V_2 -> V_8 = V_5 ;
V_2 -> V_9 = ( 1ULL << V_4 -> V_10 ) - 1 ;
V_2 -> V_11 = 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_2 V_12 , V_13 ;
T_1 V_14 ;
V_12 = V_2 -> V_4 -> V_7 ( V_2 -> V_4 ) ;
V_13 = ( V_12 - V_2 -> V_6 ) & V_2 -> V_4 -> V_9 ;
V_14 = F_3 ( V_2 -> V_4 , V_13 ,
V_2 -> V_9 , & V_2 -> V_11 ) ;
V_2 -> V_6 = V_12 ;
return V_14 ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_2 ( V_2 ) ;
V_8 += V_2 -> V_8 ;
V_2 -> V_8 = V_8 ;
return V_8 ;
}
static T_1 F_5 ( const struct V_3 * V_4 ,
T_2 V_15 , T_1 V_9 , T_1 V_11 )
{
T_1 V_16 = ( T_1 ) V_15 ;
V_16 = ( ( V_16 * V_4 -> V_17 ) - V_11 ) >> V_4 -> V_10 ;
return V_16 ;
}
T_1 F_6 ( struct V_1 * V_2 ,
T_2 V_18 )
{
T_1 V_19 = ( V_18 - V_2 -> V_6 ) & V_2 -> V_4 -> V_9 ;
T_1 V_8 = V_2 -> V_8 , V_11 = V_2 -> V_11 ;
if ( V_19 > V_2 -> V_4 -> V_9 / 2 ) {
V_19 = ( V_2 -> V_6 - V_18 ) & V_2 -> V_4 -> V_9 ;
V_8 -= F_5 ( V_2 -> V_4 , V_19 , V_2 -> V_9 , V_11 ) ;
} else {
V_8 += F_3 ( V_2 -> V_4 , V_19 , V_2 -> V_9 , & V_11 ) ;
}
return V_8 ;
}
