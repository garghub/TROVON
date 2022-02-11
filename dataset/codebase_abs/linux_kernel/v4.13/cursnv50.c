int
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
const struct V_9 * V_10 , void * V_11 , T_1 V_12 ,
struct V_13 * * V_14 )
{
union {
struct V_15 V_16 ;
} * args = V_11 ;
struct V_13 * V_17 = V_10 -> V_17 ;
struct V_18 * V_19 = V_6 -> V_19 ;
int V_20 , V_21 = - V_22 ;
F_2 ( V_17 , L_1 , V_12 ) ;
if ( ! ( V_21 = F_3 ( V_21 , & V_11 , & V_12 , args -> V_16 , 0 , 0 , false ) ) ) {
F_2 ( V_17 , L_2 ,
args -> V_16 . V_23 , args -> V_16 . V_20 ) ;
if ( ! F_4 ( & V_19 -> V_24 , args -> V_16 . V_20 ) )
return - V_25 ;
V_20 = args -> V_16 . V_20 ;
} else
return V_21 ;
return F_5 ( V_2 , V_4 , V_6 , V_7 + V_20 , V_8 + V_20 ,
V_20 , V_10 , V_14 ) ;
}
