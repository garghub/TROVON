void T_1 * F_1 ( void * V_1 , T_2 V_2 ,
struct V_3 * V_4 )
{
void * V_5 ;
if ( ! V_1 ) {
F_2 ( V_6 L_1 , V_4 -> V_7 ) ;
return NULL ;
}
V_5 = F_3 ( V_1 , V_2 , V_8 ) ;
if ( ! V_5 ) {
F_2 ( V_6 L_2 , V_4 -> V_7 ) ;
return NULL ;
}
V_4 -> V_9 . V_10 = V_5 ;
return V_5 ;
}
void F_4 ( struct V_11 * V_1 ,
struct V_11 * V_12 )
{
V_12 -> V_13 = V_1 -> V_13 ;
V_12 -> V_14 = V_1 -> V_14 ;
V_12 -> V_15 = V_1 -> V_15 ;
V_12 -> V_16 = V_1 -> V_16 ;
V_12 -> V_17 = V_1 -> V_17 ;
if ( V_1 -> V_18 )
V_12 -> V_18 = V_1 -> V_18 ;
if ( V_1 -> V_19 )
V_12 -> V_19 = V_1 -> V_19 ;
if ( V_1 -> V_20 )
V_12 -> V_20 |= V_1 -> V_20 ;
if ( V_1 -> V_21 )
V_12 -> V_21 |= V_1 -> V_21 ;
if ( V_1 -> V_22 )
V_12 -> V_22 |= V_1 -> V_22 ;
if ( V_1 -> V_23 )
V_12 -> V_23 = V_1 -> V_23 ;
}
