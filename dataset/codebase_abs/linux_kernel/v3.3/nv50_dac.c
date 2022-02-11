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
F_22 ( struct V_1 * V_2 , struct V_42 * V_32 ,
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
V_17 -> V_47 ) {
int V_48 = V_43 -> V_49 . V_48 ;
* V_43 = * V_17 -> V_47 ;
V_43 -> V_49 . V_48 = V_48 ;
}
return true ;
}
static void
F_24 ( struct V_1 * V_2 )
{
}
static void
F_25 ( struct V_1 * V_2 , struct V_42 * V_32 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_9 ;
struct F_4 * V_11 = F_4 ( V_2 -> V_11 ) ;
T_1 V_50 = 0 , V_51 = 0 ;
int V_10 ;
F_5 ( V_6 , L_13 ,
V_4 -> V_12 , V_4 -> V_52 -> type , V_11 -> V_53 ) ;
F_19 ( V_2 , V_34 ) ;
if ( V_11 -> V_53 == 1 )
V_50 |= V_54 ;
else
V_50 |= V_55 ;
if ( V_4 -> V_52 -> type == V_56 )
V_50 |= 0x40 ;
else
if ( V_4 -> V_52 -> type == V_57 )
V_50 |= 0x100 ;
if ( V_43 -> V_58 & V_59 )
V_51 |= V_60 ;
if ( V_43 -> V_58 & V_61 )
V_51 |= V_62 ;
V_10 = F_6 ( V_8 , 3 ) ;
if ( V_10 ) {
F_7 ( V_6 , L_14 ) ;
return;
}
F_8 ( V_8 , 0 , F_9 ( V_4 -> V_12 , V_13 ) , 2 ) ;
F_10 ( V_8 , V_50 ) ;
F_10 ( V_8 , V_51 ) ;
V_4 -> V_11 = V_2 -> V_11 ;
}
static struct V_63 *
F_26 ( struct V_1 * V_2 )
{
return V_3 ( V_2 ) -> V_11 ;
}
static void
F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( ! V_2 )
return;
F_5 ( V_2 -> V_6 , L_15 ) ;
F_28 ( V_2 ) ;
F_29 ( V_4 ) ;
}
int
F_30 ( struct V_16 * V_17 , struct V_64 * V_65 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_31 ( sizeof( * V_4 ) , V_66 ) ;
if ( ! V_4 )
return - V_67 ;
V_2 = F_32 ( V_4 ) ;
V_4 -> V_52 = V_65 ;
V_4 -> V_12 = F_33 ( V_65 -> V_12 ) - 1 ;
F_34 ( V_17 -> V_6 , V_2 , & V_68 ,
V_69 ) ;
F_35 ( V_2 , & V_70 ) ;
V_2 -> V_71 = V_65 -> V_72 ;
V_2 -> V_73 = 0 ;
F_36 ( V_17 , V_2 ) ;
return 0 ;
}
