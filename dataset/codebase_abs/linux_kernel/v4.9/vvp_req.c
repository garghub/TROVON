static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( const struct V_5 * V_6 ,
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
if ( F_8 ( V_30 ) )
V_14 -> V_31 ++ ;
memcpy ( V_10 -> V_32 , F_5 ( V_12 ) -> V_33 ,
V_34 ) ;
}
static void F_9 ( const struct V_5 * V_6 ,
const struct V_2 * V_3 , int V_35 )
{
struct V_1 * V_36 ;
if ( V_35 > 0 )
F_10 ( V_3 -> V_37 , V_3 -> V_18 -> V_19 , V_35 ) ;
V_36 = F_1 ( V_3 ) ;
F_11 ( V_38 , V_36 ) ;
}
int F_12 ( const struct V_5 * V_6 , struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_36 ;
int V_43 ;
V_36 = F_13 ( V_38 , V_44 ) ;
if ( V_36 ) {
F_14 ( V_42 , & V_36 -> V_4 , V_40 , & V_45 ) ;
V_43 = 0 ;
} else {
V_43 = - V_46 ;
}
return V_43 ;
}
