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
T_2 V_21 ;
F_2 ( V_16 , L_1 , V_11 ) ;
if ( F_3 ( args -> V_15 , 0 , 0 , false ) ) {
F_2 ( V_16 , L_2
L_3 ,
args -> V_15 . V_22 , args -> V_15 . V_23 , args -> V_15 . V_19 ) ;
if ( args -> V_15 . V_19 > V_18 -> V_24 . V_19 . V_25 )
return - V_26 ;
V_21 = args -> V_15 . V_23 ;
V_19 = args -> V_15 . V_19 ;
} else
return V_20 ;
return F_4 ( V_2 , V_4 , V_6 , V_7 + V_19 ,
V_19 , V_21 , V_9 , V_13 ) ;
}
