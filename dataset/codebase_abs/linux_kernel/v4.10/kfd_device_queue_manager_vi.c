void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_9 ;
}
static T_1 F_2 ( unsigned int V_10 )
{
F_3 ( ( V_10 & 1 ) || V_10 > 0xE ||
V_10 == 0 ) ;
return V_10 << 12 |
( V_10 << 12 ) <<
V_11 ;
}
static bool V_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
enum V_16 V_17 ,
enum V_16 V_18 ,
void T_2 * V_19 ,
T_3 V_20 )
{
T_1 V_21 ;
T_1 V_22 ;
V_21 = ( V_17 == V_23 ) ?
V_24 :
V_25 ;
V_22 = ( V_18 == V_23 ) ?
V_24 :
V_25 ;
V_15 -> V_26 = ( V_15 -> V_26 &
V_27 ) |
V_28 <<
V_29 |
V_21 << V_30 |
V_22 << V_31 |
V_32 ;
return true ;
}
static int V_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_33 * V_34 ;
unsigned int V_35 ;
F_3 ( ! V_13 || ! V_15 ) ;
V_34 = F_4 ( V_15 ) ;
if ( V_15 -> V_26 == 0 ) {
V_15 -> V_26 =
V_28 <<
V_29 |
V_24 << V_30 |
V_24 << V_31 |
V_32 ;
V_15 -> V_36 = 0 ;
V_15 -> V_37 = 0 ;
}
if ( V_15 -> V_38 -> V_39 -> V_40 ) {
V_35 = F_5 ( V_34 ) ;
V_15 -> V_41 = V_35 << V_11 ;
V_15 -> V_26 |= V_42 <<
V_43 ;
} else {
V_35 = F_6 ( V_34 ) ;
V_15 -> V_41 = F_2 ( V_35 ) ;
V_15 -> V_26 |= V_44 <<
V_43 ;
}
F_7 ( L_1 ,
V_15 -> V_38 -> V_39 -> V_40 , V_35 , V_15 -> V_41 ) ;
return 0 ;
}
static void V_9 ( struct V_12 * V_13 , struct V_45 * V_46 ,
struct V_14 * V_15 )
{
T_1 V_47 = ( 1 << V_48 ) ;
if ( V_46 -> V_39 -> V_40 )
V_47 |= ( 1 << V_49 ) |
F_5 ( F_4 ( V_15 ) ) ;
else
V_47 |= ( ( F_6 ( F_4 ( V_15 ) ) ) <<
V_50 ) &
V_51 ;
V_46 -> V_52 . V_53 = V_47 ;
}
static int V_8 ( struct V_12 * V_13 )
{
return 0 ;
}
