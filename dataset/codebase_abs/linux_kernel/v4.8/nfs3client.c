static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
goto V_5;
V_2 -> V_6 = F_2 ( V_2 -> V_7 , & V_8 , 3 ) ;
if ( F_3 ( V_2 -> V_6 ) )
goto V_5;
V_2 -> V_9 |= V_10 ;
return;
V_5:
V_2 -> V_9 &= ~ V_10 ;
}
static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
V_2 -> V_9 &= ~ V_10 ;
}
struct V_1 * F_4 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_12 , V_14 ) ;
if ( ! F_3 ( V_2 ) )
F_1 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_6 ( struct V_1 * V_15 ,
struct V_16 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 , V_17 , V_19 , V_20 ) ;
if ( ! F_3 ( V_2 ) && ! F_3 ( V_15 -> V_6 ) )
F_1 ( V_2 ) ;
return V_2 ;
}
struct V_21 * F_8 ( struct V_1 * V_22 ,
const struct V_23 * V_24 , int V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 ,
T_1 V_29 )
{
struct V_30 V_31 ;
struct V_21 * V_32 = V_22 -> V_21 ;
struct V_33 V_34 = {
. V_35 = V_24 ,
. V_36 = V_25 ,
. V_37 = V_32 -> V_38 -> V_39 ,
. V_40 = V_32 -> V_41 ,
. V_14 = & V_42 ,
. V_43 = V_26 ,
. V_44 = V_32 -> V_45 ,
. V_46 = & V_31 ,
} ;
struct V_21 * V_47 ;
char V_48 [ V_49 + 1 ] ;
if ( F_9 ( V_24 , V_48 , sizeof( V_48 ) ) <= 0 )
return F_10 ( - V_50 ) ;
V_34 . V_51 = V_48 ;
if ( V_22 -> V_3 & V_52 )
F_11 ( V_53 , & V_34 . V_54 ) ;
F_12 ( & V_31 , V_26 , V_27 , V_28 ) ;
V_47 = F_13 ( & V_34 , V_29 ) ;
return V_47 ;
}
