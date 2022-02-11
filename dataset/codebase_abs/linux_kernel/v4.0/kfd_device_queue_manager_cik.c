void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
}
static T_1 F_2 ( unsigned int V_9 )
{
F_3 ( ( V_9 & 1 ) || V_9 > 0xE ||
V_9 == 0 ) ;
return F_4 ( V_9 << 12 ) |
F_5 ( V_9 << 12 ) ;
}
static bool V_4 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
enum V_14 V_15 ,
enum V_14 V_16 ,
void T_2 * V_17 ,
T_3 V_18 )
{
T_1 V_19 ;
T_1 V_20 ;
V_19 = ( V_15 == V_21 ) ?
V_22 :
V_23 ;
V_20 = ( V_16 == V_21 ) ?
V_22 :
V_23 ;
V_13 -> V_24 = ( V_13 -> V_24 & V_25 )
| F_6 ( V_26 )
| F_7 ( V_19 )
| F_8 ( V_20 ) ;
return true ;
}
static int V_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_27 * V_28 ;
unsigned int V_29 ;
F_3 ( ! V_11 || ! V_13 ) ;
V_28 = F_9 ( V_13 ) ;
if ( V_13 -> V_24 == 0 ) {
V_13 -> V_24 =
F_6 ( V_26 ) |
F_7 ( V_22 ) |
F_8 ( V_22 ) ;
V_13 -> V_30 = 0 ;
V_13 -> V_31 = 0 ;
}
if ( V_13 -> V_32 -> V_33 -> V_34 ) {
V_29 = F_10 ( V_28 ) ;
V_13 -> V_35 = F_5 ( V_29 ) ;
V_13 -> V_24 |= V_25 ;
} else {
V_29 = F_11 ( V_28 ) ;
V_13 -> V_35 = F_2 ( V_29 ) ;
}
F_12 ( L_1 ,
V_13 -> V_32 -> V_33 -> V_34 , V_29 , V_13 -> V_35 ) ;
return 0 ;
}
static int V_8 ( struct V_10 * V_11 )
{
return F_13 ( V_11 , F_14 ( V_11 ) , F_15 ( V_11 ) ) ;
}
