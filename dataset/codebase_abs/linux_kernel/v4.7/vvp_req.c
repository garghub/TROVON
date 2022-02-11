static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void F_3 ( const struct V_5 * V_6 ,
const struct V_2 * V_3 ,
const struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_11 )
{
struct V_12 * V_12 ;
struct V_13 * V_14 ;
T_2 V_15 ;
V_14 = V_10 -> V_16 ;
V_12 = F_4 ( V_8 ) ;
V_15 = V_17 ;
if ( V_3 -> V_18 -> V_19 == V_20 ) {
if ( V_11 & V_21 ) {
V_14 -> V_22 |= V_21 ;
V_14 -> V_23 = F_5 ( V_12 ) -> V_24 ;
V_15 |= V_25 | V_26 |
V_27 | V_28 ;
}
}
F_6 ( V_14 , V_12 , V_15 & V_11 ) ;
F_7 ( V_14 , & F_5 ( V_12 ) -> V_29 ) ;
memcpy ( V_10 -> V_30 , F_5 ( V_12 ) -> V_31 ,
V_32 ) ;
}
void F_8 ( const struct V_5 * V_6 ,
const struct V_2 * V_3 , int V_33 )
{
struct V_1 * V_34 ;
if ( V_33 > 0 )
F_9 ( V_3 -> V_35 , V_3 -> V_18 -> V_19 , V_33 ) ;
V_34 = F_1 ( V_3 ) ;
F_10 ( V_36 , V_34 ) ;
}
int F_11 ( const struct V_5 * V_6 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_1 * V_34 ;
int V_41 ;
V_34 = F_12 ( V_36 , V_42 ) ;
if ( V_34 ) {
F_13 ( V_40 , & V_34 -> V_4 , V_38 , & V_43 ) ;
V_41 = 0 ;
} else {
V_41 = - V_44 ;
}
return V_41 ;
}
