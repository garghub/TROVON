static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_7 ( V_6 ) ;
struct V_9 * V_10 = F_2 ( V_6 ) -> V_11 ;
int V_12 ;
if ( ! V_4 -> V_13 )
return;
F_3 ( F_4 ( V_4 -> V_13 ) , true ) ;
F_5 ( V_8 , L_1 , V_4 -> V_14 ) ;
V_12 = F_6 ( V_10 , 4 ) ;
if ( V_12 ) {
F_7 ( V_8 , L_2 ) ;
return;
}
F_8 ( V_10 , 0 , F_9 ( V_4 -> V_14 , V_15 ) , 1 ) ;
F_10 ( V_10 , 0 ) ;
F_8 ( V_10 , 0 , V_16 , 1 ) ;
F_10 ( V_10 , 0 ) ;
V_4 -> V_13 = NULL ;
}
static enum V_17
F_11 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_20 * V_21 = F_12 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
enum V_17 V_22 = V_23 ;
T_1 V_24 , V_25 , V_26 ;
int V_14 = V_4 -> V_14 ;
F_13 ( V_21 , F_14 ( V_14 ) , 0x00000001 ) ;
V_24 = F_15 ( V_21 , F_16 ( V_14 ) ) ;
F_13 ( V_21 , F_16 ( V_14 ) ,
0x00150000 | V_27 ) ;
if ( ! F_17 ( V_21 , F_16 ( V_14 ) ,
V_27 , 0 ) ) {
F_7 ( V_8 , L_3 , V_14 ) ;
F_7 ( V_8 , L_4 , V_14 ,
F_15 ( V_21 , F_16 ( V_14 ) ) ) ;
return V_22 ;
}
if ( V_8 -> V_28 . V_29 ) {
V_25 = V_8 -> V_28 . V_29 ;
F_5 ( V_8 , L_5 ,
V_25 ) ;
} else {
V_25 = 340 ;
F_5 ( V_8 , L_6 ,
V_25 ) ;
}
F_13 ( V_21 , F_18 ( V_14 ) ,
V_30 | V_25 ) ;
F_19 ( 45 ) ;
V_26 = F_15 ( V_21 , F_18 ( V_14 ) ) ;
F_13 ( V_21 , F_18 ( V_14 ) , 0 ) ;
F_13 ( V_21 , F_16 ( V_14 ) , V_24 |
V_27 ) ;
if ( ( V_26 & V_31 ) ==
V_31 )
V_22 = V_32 ;
if ( V_22 == V_32 )
F_5 ( V_8 , L_7 , V_14 ) ;
else
F_5 ( V_8 , L_8 , V_14 ) ;
return V_22 ;
}
static void
F_20 ( struct V_1 * V_2 , int V_33 )
{
struct V_20 * V_21 = F_12 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_34 ;
int V_14 = V_4 -> V_14 ;
F_5 ( V_8 , L_9 , V_14 , V_33 ) ;
if ( ! F_17 ( V_21 , F_16 ( V_14 ) ,
V_27 , 0 ) ) {
F_7 ( V_8 , L_3 , V_14 ) ;
F_7 ( V_8 , L_4 , V_14 ,
F_15 ( V_21 , F_16 ( V_14 ) ) ) ;
return;
}
V_34 = F_15 ( V_21 , F_16 ( V_14 ) ) & ~ 0x7F ;
if ( V_33 != V_35 )
V_34 |= V_36 ;
switch ( V_33 ) {
case V_37 :
V_34 |= V_38 ;
break;
case V_39 :
V_34 |= V_40 ;
break;
case V_41 :
V_34 |= V_42 ;
V_34 |= V_38 ;
V_34 |= V_40 ;
break;
default:
break;
}
F_13 ( V_21 , F_16 ( V_14 ) , V_34 |
V_27 ) ;
}
static void
F_21 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
F_7 ( V_8 , L_10 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
F_7 ( V_8 , L_10 ) ;
}
static bool
F_23 ( struct V_1 * V_2 ,
const struct V_43 * V_33 ,
struct V_43 * V_44 )
{
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_45 * V_19 ;
F_5 ( V_8 , L_11 , V_4 -> V_14 ) ;
V_19 = F_24 ( V_4 ) ;
if ( ! V_19 ) {
F_7 ( V_8 , L_12 ) ;
return false ;
}
if ( V_19 -> V_46 != V_47 &&
V_19 -> V_48 )
F_25 ( V_44 , V_19 -> V_48 ) ;
return true ;
}
static void
F_26 ( struct V_1 * V_2 )
{
}
static void
F_27 ( struct V_1 * V_2 , struct V_43 * V_33 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_9 * V_10 = F_2 ( V_6 ) -> V_11 ;
struct F_4 * V_13 = F_4 ( V_2 -> V_13 ) ;
T_1 V_49 = 0 , V_50 = 0 ;
int V_12 ;
F_5 ( V_8 , L_13 ,
V_4 -> V_14 , V_4 -> V_51 -> type , V_13 -> V_52 ) ;
F_20 ( V_2 , V_35 ) ;
if ( V_13 -> V_52 == 1 )
V_49 |= V_53 ;
else
V_49 |= V_54 ;
if ( V_4 -> V_51 -> type == V_55 )
V_49 |= 0x40 ;
else
if ( V_4 -> V_51 -> type == V_56 )
V_49 |= 0x100 ;
if ( V_44 -> V_57 & V_58 )
V_50 |= V_59 ;
if ( V_44 -> V_57 & V_60 )
V_50 |= V_61 ;
V_12 = F_6 ( V_10 , 3 ) ;
if ( V_12 ) {
F_7 ( V_8 , L_14 ) ;
return;
}
F_8 ( V_10 , 0 , F_9 ( V_4 -> V_14 , V_15 ) , 2 ) ;
F_10 ( V_10 , V_49 ) ;
F_10 ( V_10 , V_50 ) ;
V_4 -> V_13 = V_2 -> V_13 ;
}
static struct V_62 *
F_28 ( struct V_1 * V_2 )
{
return V_3 ( V_2 ) -> V_13 ;
}
static void
F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_7 * V_8 = V_7 ( V_2 -> V_6 ) ;
if ( ! V_2 )
return;
F_5 ( V_8 , L_15 ) ;
F_30 ( V_2 ) ;
F_31 ( V_4 ) ;
}
int
F_32 ( struct V_18 * V_19 , struct V_63 * V_64 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_33 ( sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return - V_66 ;
V_2 = F_34 ( V_4 ) ;
V_4 -> V_51 = V_64 ;
V_4 -> V_14 = F_35 ( V_64 -> V_14 ) - 1 ;
F_36 ( V_19 -> V_6 , V_2 , & V_67 ,
V_68 ) ;
F_37 ( V_2 , & V_69 ) ;
V_2 -> V_70 = V_64 -> V_71 ;
V_2 -> V_72 = 0 ;
F_38 ( V_19 , V_2 ) ;
return 0 ;
}
