static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 -> V_4 + V_5 , V_6 , 0 ) ;
if ( ! F_3 ( V_2 -> V_4 + V_5 , V_3 ,
! ( V_3 & V_7 ) , 100 , V_8 * 100 ) )
return 0 ;
F_2 ( V_2 -> V_4 + V_5 , 0 , V_6 ) ;
return - V_9 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_4 + V_5 , 0 , V_6 ) ;
}
static int F_5 ( struct V_10 * V_11 , int V_12 , int V_13 )
{
struct V_1 * V_2 = V_11 -> V_14 ;
T_1 V_15 ;
int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_2 ( V_2 -> V_4 + V_17 , V_18 ,
( V_12 << V_19 ) ) ;
V_15 = V_20 |
( ( V_21 << V_22 ) & V_23 ) |
( ( V_13 << V_24 ) & V_25 ) |
V_26 | V_27 ;
F_6 ( V_15 , V_2 -> V_4 + V_5 ) ;
if ( F_3 ( V_2 -> V_4 + V_5 , V_15 ,
! ( V_15 & ( V_26 | V_7 ) ) ,
100 , V_8 * 100 ) )
V_16 = - V_28 ;
else
V_16 = ( V_15 >> V_29 ) & V_30 ;
F_4 ( V_2 ) ;
return V_16 ;
}
static int F_7 ( struct V_10 * V_11 , int V_12 , int V_13 , T_2 V_3 )
{
struct V_1 * V_2 = V_11 -> V_14 ;
T_1 V_15 ;
int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_2 ( V_2 -> V_4 + V_17 , V_18 ,
( V_12 << V_19 ) ) ;
V_15 = V_20 |
( ( V_21 << V_22 ) & V_23 ) |
( ( V_13 << V_24 ) & V_25 ) |
( ( V_3 << V_29 ) & V_30 ) |
V_26 ;
F_6 ( V_15 , V_2 -> V_4 + V_5 ) ;
if ( F_3 ( V_2 -> V_4 + V_5 , V_15 ,
! ( V_15 & ( V_26 | V_7 ) ) , 100 ,
V_8 * 100 ) )
V_16 = - V_28 ;
F_4 ( V_2 ) ;
return V_16 ;
}
int F_8 ( struct V_31 * V_32 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_32 -> V_35 . V_36 ;
struct V_10 * V_10 ;
int V_16 ;
V_2 -> V_10 = V_10 = F_9 ( & V_32 -> V_35 ) ;
if ( ! V_10 )
return - V_37 ;
V_10 -> V_38 = L_1 ;
snprintf ( V_10 -> V_39 , V_40 , L_2 , V_32 -> V_38 ) ;
V_10 -> V_41 = F_5 ;
V_10 -> V_42 = F_7 ;
V_10 -> V_43 = & V_32 -> V_35 ;
V_10 -> V_14 = V_2 ;
if ( F_10 ( & V_32 -> V_35 ) ) {
T_1 V_44 ;
V_16 = F_11 ( V_10 ) ;
if ( V_16 ) {
F_12 ( & V_32 -> V_35 , L_3 ) ;
return V_16 ;
}
V_16 = F_13 ( & V_32 -> V_35 , L_4 ,
& V_44 ) ;
if ( V_16 )
V_2 -> V_45 = F_14 ( V_10 ) ;
else
V_2 -> V_45 = F_15 ( V_10 , V_44 ) ;
if ( V_2 -> V_45 )
F_16 ( & V_2 -> V_45 -> V_46 . V_35 ) ;
} else {
struct V_33 * V_47 ;
V_16 = F_17 ( V_10 , V_34 ) ;
if ( V_16 ) {
F_12 ( & V_32 -> V_35 , L_3 ) ;
return V_16 ;
}
V_47 = F_18 ( V_34 , L_5 , 0 ) ;
V_2 -> V_45 = F_19 ( V_47 ) ;
F_20 ( V_47 ) ;
}
if ( ! V_2 -> V_45 ) {
F_12 ( & V_32 -> V_35 , L_6 ) ;
F_21 ( V_10 ) ;
return - V_48 ;
}
return 0 ;
}
