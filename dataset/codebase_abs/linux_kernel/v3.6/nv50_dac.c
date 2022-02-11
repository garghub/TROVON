static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_9 ;
int V_10 ;
if ( ! V_4 -> V_11 )
return;
F_3 ( F_4 ( V_4 -> V_11 ) , true ) ;
F_5 ( V_6 , L_1 , V_4 -> V_12 ) ;
V_10 = F_6 ( V_8 , 4 ) ;
if ( V_10 ) {
F_7 ( V_6 , L_2 ) ;
return;
}
F_8 ( V_8 , 0 , F_9 ( V_4 -> V_12 , V_13 ) , 1 ) ;
F_10 ( V_8 , 0 ) ;
F_8 ( V_8 , 0 , V_14 , 1 ) ;
F_10 ( V_8 , 0 ) ;
V_4 -> V_11 = NULL ;
}
static enum V_15
F_11 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_20 ;
enum V_15 V_21 = V_22 ;
T_1 V_23 , V_24 , V_25 ;
int V_12 = V_4 -> V_12 ;
F_12 ( V_6 , F_13 ( V_12 ) , 0x00000001 ) ;
V_23 = F_14 ( V_6 , F_15 ( V_12 ) ) ;
F_12 ( V_6 , F_15 ( V_12 ) ,
0x00150000 | V_26 ) ;
if ( ! F_16 ( V_6 , F_15 ( V_12 ) ,
V_26 , 0 ) ) {
F_7 ( V_6 , L_3 , V_12 ) ;
F_7 ( V_6 , L_4 , V_12 ,
F_14 ( V_6 , F_15 ( V_12 ) ) ) ;
return V_21 ;
}
if ( V_19 -> V_27 . V_28 ) {
V_24 = V_19 -> V_27 . V_28 ;
F_5 ( V_6 , L_5 ,
V_24 ) ;
} else {
V_24 = 340 ;
F_5 ( V_6 , L_6 ,
V_24 ) ;
}
F_12 ( V_6 , F_17 ( V_12 ) ,
V_29 | V_24 ) ;
F_18 ( 45 ) ;
V_25 = F_14 ( V_6 , F_17 ( V_12 ) ) ;
F_12 ( V_6 , F_17 ( V_12 ) , 0 ) ;
F_12 ( V_6 , F_15 ( V_12 ) , V_23 |
V_26 ) ;
if ( ( V_25 & V_30 ) ==
V_30 )
V_21 = V_31 ;
if ( V_21 == V_31 )
F_5 ( V_6 , L_7 , V_12 ) ;
else
F_5 ( V_6 , L_8 , V_12 ) ;
return V_21 ;
}
static void
F_19 ( struct V_1 * V_2 , int V_32 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_33 ;
int V_12 = V_4 -> V_12 ;
F_5 ( V_6 , L_9 , V_12 , V_32 ) ;
if ( ! F_16 ( V_6 , F_15 ( V_12 ) ,
V_26 , 0 ) ) {
F_7 ( V_6 , L_3 , V_12 ) ;
F_7 ( V_6 , L_4 , V_12 ,
F_14 ( V_6 , F_15 ( V_12 ) ) ) ;
return;
}
V_33 = F_14 ( V_6 , F_15 ( V_12 ) ) & ~ 0x7F ;
if ( V_32 != V_34 )
V_33 |= V_35 ;
switch ( V_32 ) {
case V_36 :
V_33 |= V_37 ;
break;
case V_38 :
V_33 |= V_39 ;
break;
case V_40 :
V_33 |= V_41 ;
V_33 |= V_37 ;
V_33 |= V_39 ;
break;
default:
break;
}
F_12 ( V_6 , F_15 ( V_12 ) , V_33 |
V_26 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 , L_10 ) ;
}
static void
F_21 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 , L_10 ) ;
}
static bool
F_22 ( struct V_1 * V_2 ,
const struct V_42 * V_32 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_44 * V_17 ;
F_5 ( V_2 -> V_6 , L_11 , V_4 -> V_12 ) ;
V_17 = F_23 ( V_4 ) ;
if ( ! V_17 ) {
F_7 ( V_2 -> V_6 , L_12 ) ;
return false ;
}
if ( V_17 -> V_45 != V_46 &&
V_17 -> V_47 )
F_24 ( V_43 , V_17 -> V_47 ) ;
return true ;
}
static void
F_25 ( struct V_1 * V_2 )
{
}
static void
F_26 ( struct V_1 * V_2 , struct V_42 * V_32 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_9 ;
struct F_4 * V_11 = F_4 ( V_2 -> V_11 ) ;
T_1 V_48 = 0 , V_49 = 0 ;
int V_10 ;
F_5 ( V_6 , L_13 ,
V_4 -> V_12 , V_4 -> V_50 -> type , V_11 -> V_51 ) ;
F_19 ( V_2 , V_34 ) ;
if ( V_11 -> V_51 == 1 )
V_48 |= V_52 ;
else
V_48 |= V_53 ;
if ( V_4 -> V_50 -> type == V_54 )
V_48 |= 0x40 ;
else
if ( V_4 -> V_50 -> type == V_55 )
V_48 |= 0x100 ;
if ( V_43 -> V_56 & V_57 )
V_49 |= V_58 ;
if ( V_43 -> V_56 & V_59 )
V_49 |= V_60 ;
V_10 = F_6 ( V_8 , 3 ) ;
if ( V_10 ) {
F_7 ( V_6 , L_14 ) ;
return;
}
F_8 ( V_8 , 0 , F_9 ( V_4 -> V_12 , V_13 ) , 2 ) ;
F_10 ( V_8 , V_48 ) ;
F_10 ( V_8 , V_49 ) ;
V_4 -> V_11 = V_2 -> V_11 ;
}
static struct V_61 *
F_27 ( struct V_1 * V_2 )
{
return V_3 ( V_2 ) -> V_11 ;
}
static void
F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( ! V_2 )
return;
F_5 ( V_2 -> V_6 , L_15 ) ;
F_29 ( V_2 ) ;
F_30 ( V_4 ) ;
}
int
F_31 ( struct V_16 * V_17 , struct V_62 * V_63 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_32 ( sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_2 = F_33 ( V_4 ) ;
V_4 -> V_50 = V_63 ;
V_4 -> V_12 = F_34 ( V_63 -> V_12 ) - 1 ;
F_35 ( V_17 -> V_6 , V_2 , & V_66 ,
V_67 ) ;
F_36 ( V_2 , & V_68 ) ;
V_2 -> V_69 = V_63 -> V_70 ;
V_2 -> V_71 = 0 ;
F_37 ( V_17 , V_2 ) ;
return 0 ;
}
