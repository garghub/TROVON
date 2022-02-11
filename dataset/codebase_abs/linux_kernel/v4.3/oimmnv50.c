int
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 ,
const struct V_8 * V_9 , void * V_10 , T_1 V_11 ,
struct V_12 * * V_13 )
{
union {
struct V_14 V_15 ;
} * args = V_10 ;
struct V_12 * V_16 = V_9 -> V_16 ;
struct V_17 * V_18 = V_6 -> V_18 ;
int V_19 , V_20 ;
F_2 ( V_16 , L_1 , V_11 ) ;
if ( F_3 ( args -> V_15 , 0 , 0 , false ) ) {
F_2 ( V_16 , L_2 ,
args -> V_15 . V_21 , args -> V_15 . V_19 ) ;
if ( args -> V_15 . V_19 > V_18 -> V_22 . V_19 . V_23 )
return - V_24 ;
V_19 = args -> V_15 . V_19 ;
} else
return V_20 ;
return F_4 ( V_2 , V_4 , V_6 , V_7 + V_19 ,
V_19 , V_9 , V_13 ) ;
}
