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
return F_4 ( V_10 << 12 ) |
F_5 ( V_10 << 12 ) ;
}
static bool V_4 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
enum V_15 V_16 ,
enum V_15 V_17 ,
void T_2 * V_18 ,
T_3 V_19 )
{
T_1 V_20 ;
T_1 V_21 ;
V_20 = ( V_16 == V_22 ) ?
V_23 :
V_24 ;
V_21 = ( V_17 == V_22 ) ?
V_23 :
V_24 ;
V_14 -> V_25 = ( V_14 -> V_25 & V_26 )
| F_6 ( V_27 )
| F_7 ( V_20 )
| F_8 ( V_21 ) ;
return true ;
}
static int V_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_28 * V_29 ;
unsigned int V_30 ;
F_3 ( ! V_12 || ! V_14 ) ;
V_29 = F_9 ( V_14 ) ;
if ( V_14 -> V_25 == 0 ) {
V_14 -> V_25 =
F_6 ( V_27 ) |
F_7 ( V_23 ) |
F_8 ( V_23 ) ;
V_14 -> V_31 = 0 ;
V_14 -> V_32 = 0 ;
}
if ( V_14 -> V_33 -> V_34 -> V_35 ) {
V_30 = F_10 ( V_29 ) ;
V_14 -> V_36 = F_5 ( V_30 ) ;
V_14 -> V_25 |= V_26 ;
} else {
V_30 = F_11 ( V_29 ) ;
V_14 -> V_36 = F_2 ( V_30 ) ;
}
F_12 ( L_1 ,
V_14 -> V_33 -> V_34 -> V_35 , V_30 , V_14 -> V_36 ) ;
return 0 ;
}
static void V_9 ( struct V_11 * V_12 , struct V_37 * V_38 ,
struct V_13 * V_14 )
{
T_1 V_39 = ( 1 << V_40 ) ;
if ( V_38 -> V_34 -> V_35 )
V_39 |= ( 1 << V_41 ) |
F_10 ( F_9 ( V_14 ) ) ;
else
V_39 |= ( ( F_11 ( F_9 ( V_14 ) ) ) <<
V_42 ) &
V_43 ;
V_38 -> V_44 . V_45 = V_39 ;
}
static int V_8 ( struct V_11 * V_12 )
{
return 0 ;
}
