static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
F_2 ( V_6 -> V_9 + V_10 , V_11 ,
( V_3 << V_12 ) ) ;
V_8 = V_13 |
( ( V_14 << V_15 ) & V_16 ) |
( ( V_4 << V_17 ) & V_18 ) |
V_19 | V_20 ;
F_3 ( V_8 , V_6 -> V_9 + V_21 ) ;
if ( F_4 ( V_6 -> V_9 + V_21 , V_8 ,
! ( V_8 & ( V_19 | V_22 ) ) ,
100 , V_23 * 100 ) )
return - V_24 ;
return ( V_8 >> V_25 ) & V_26 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 , T_2 V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
F_2 ( V_6 -> V_9 + V_10 , V_11 ,
( V_3 << V_12 ) ) ;
V_8 = V_13 |
( ( V_14 << V_15 ) & V_16 ) |
( ( V_4 << V_17 ) & V_18 ) |
( ( V_27 << V_25 ) & V_26 ) |
V_19 ;
F_3 ( V_8 , V_6 -> V_9 + V_21 ) ;
if ( F_4 ( V_6 -> V_9 + V_21 , V_8 ,
! ( V_8 & ( V_19 | V_22 ) ) , 100 ,
V_23 * 100 ) )
return - V_24 ;
return 0 ;
}
int F_6 ( struct V_28 * V_29 , struct V_5 * V_6 )
{
struct V_30 * V_31 = V_29 -> V_32 . V_33 ;
struct V_1 * V_1 ;
int V_34 ;
V_6 -> V_1 = V_1 = F_7 ( & V_29 -> V_32 ) ;
if ( ! V_1 )
return - V_35 ;
V_1 -> V_36 = L_1 ;
snprintf ( V_1 -> V_37 , V_38 , L_2 , V_29 -> V_36 ) ;
V_1 -> V_39 = F_1 ;
V_1 -> V_40 = F_5 ;
V_1 -> V_41 = & V_29 -> V_32 ;
V_1 -> V_7 = V_6 ;
if ( F_8 ( & V_29 -> V_32 ) ) {
T_1 V_42 ;
V_34 = F_9 ( V_1 ) ;
if ( V_34 ) {
F_10 ( & V_29 -> V_32 , L_3 ) ;
return V_34 ;
}
V_34 = F_11 ( & V_29 -> V_32 , L_4 ,
& V_42 ) ;
if ( V_34 )
V_6 -> V_43 = F_12 ( V_1 ) ;
else
V_6 -> V_43 = F_13 ( V_1 , V_42 ) ;
if ( V_6 -> V_43 )
F_14 ( & V_6 -> V_43 -> V_44 . V_32 ) ;
} else {
struct V_30 * V_45 ;
V_34 = F_15 ( V_1 , V_31 ) ;
if ( V_34 ) {
F_10 ( & V_29 -> V_32 , L_3 ) ;
return V_34 ;
}
V_45 = F_16 ( V_31 , L_5 , 0 ) ;
V_6 -> V_43 = F_17 ( V_45 ) ;
F_18 ( V_45 ) ;
}
if ( ! V_6 -> V_43 ) {
F_10 ( & V_29 -> V_32 , L_6 ) ;
F_19 ( V_1 ) ;
return - V_46 ;
}
return 0 ;
}
