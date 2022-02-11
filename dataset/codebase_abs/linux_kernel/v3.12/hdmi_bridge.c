static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 -> V_4 ) ;
F_4 ( V_2 ) ;
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_4 = V_3 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_7 ( L_1 ) ;
V_6 -> V_7 -> V_8 ( V_6 , V_3 -> V_9 ) ;
F_8 ( V_4 , true ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static void F_10 ( struct V_1 * V_2 )
{
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_4 = V_3 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_7 ( L_2 ) ;
F_8 ( V_4 , false ) ;
V_6 -> V_7 -> V_10 ( V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_11 * V_13 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_4 = V_3 -> V_4 ;
int V_14 , V_15 , V_16 , V_17 ;
T_1 V_18 ;
V_12 = V_13 ;
V_3 -> V_9 = V_12 -> clock * 1000 ;
V_4 -> V_19 = F_13 ( V_12 ) > 1 ;
V_14 = V_12 -> V_20 - V_12 -> V_21 ;
V_15 = V_12 -> V_20 - V_12 -> V_21 + V_12 -> V_22 ;
V_16 = V_12 -> V_23 - V_12 -> V_24 - 1 ;
V_17 = V_12 -> V_23 - V_12 -> V_24 + V_12 -> V_25 - 1 ;
F_7 ( L_3 ,
V_12 -> V_20 , V_12 -> V_23 , V_14 , V_15 , V_16 , V_17 ) ;
F_14 ( V_4 , V_26 ,
F_15 ( V_12 -> V_20 - 1 ) |
F_16 ( V_12 -> V_23 - 1 ) ) ;
F_14 ( V_4 , V_27 ,
F_17 ( V_14 ) |
F_18 ( V_15 ) ) ;
F_14 ( V_4 , V_28 ,
F_19 ( V_16 ) |
F_20 ( V_17 ) ) ;
if ( V_12 -> V_29 & V_30 ) {
F_14 ( V_4 , V_31 ,
F_21 ( V_12 -> V_23 ) ) ;
F_14 ( V_4 , V_32 ,
F_22 ( V_16 + 1 ) |
F_23 ( V_17 + 1 ) ) ;
} else {
F_14 ( V_4 , V_31 ,
F_21 ( 0 ) ) ;
F_14 ( V_4 , V_32 ,
F_22 ( 0 ) |
F_23 ( 0 ) ) ;
}
V_18 = 0 ;
if ( V_12 -> V_29 & V_33 )
V_18 |= V_34 ;
if ( V_12 -> V_29 & V_35 )
V_18 |= V_36 ;
if ( V_12 -> V_29 & V_30 )
V_18 |= V_37 ;
F_7 ( L_4 , V_18 ) ;
F_14 ( V_4 , V_38 , V_18 ) ;
if ( V_4 -> V_19 )
F_14 ( V_4 , V_39 , V_40 ) ;
}
struct V_1 * F_24 ( struct V_4 * V_4 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
int V_41 ;
V_3 = F_25 ( sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 ) {
V_41 = - V_43 ;
goto V_44;
}
V_3 -> V_4 = F_26 ( V_4 ) ;
V_2 = & V_3 -> V_45 ;
F_27 ( V_4 -> V_46 , V_2 , & V_47 ) ;
return V_2 ;
V_44:
if ( V_2 )
F_1 ( V_2 ) ;
return F_28 ( V_41 ) ;
}
