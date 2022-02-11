static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_15 * V_16 = F_3 ( V_14 ) ;
V_12 = ( 2 << 10 ) ;
if ( V_5 -> V_17 & V_18 )
V_12 |= V_19 ;
if ( V_5 -> V_17 & V_20 )
V_12 |= V_21 ;
if ( V_16 -> V_22 == 1 )
V_12 |= V_23 ;
if ( V_10 -> V_24 ) {
V_12 |= V_25 ;
V_12 |= V_26 ;
}
F_4 ( V_10 -> V_27 , V_12 ) ;
F_5 ( V_10 -> V_27 ) ;
}
static bool F_6 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
return true ;
}
static void F_7 ( struct V_1 * V_2 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 =
F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 ;
V_12 = F_5 ( V_10 -> V_27 ) ;
if ( V_4 != V_28 )
F_4 ( V_10 -> V_27 , V_12 & ~ V_29 ) ;
else
F_4 ( V_10 -> V_27 , V_12 | V_29 ) ;
F_5 ( V_10 -> V_27 ) ;
}
static void F_8 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_7 ;
struct V_8 * V_8 =
F_9 ( V_31 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
V_10 -> V_32 = F_5 ( V_10 -> V_27 ) ;
}
static void F_10 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_7 ;
struct V_8 * V_8 =
F_9 ( V_31 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_4 ( V_10 -> V_27 , V_10 -> V_32 ) ;
F_5 ( V_10 -> V_27 ) ;
}
static enum V_33 F_11 (
struct V_30 * V_31 , bool V_34 )
{
struct V_8 * V_8 =
F_9 ( V_31 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_35 * V_35 = NULL ;
enum V_33 V_36 = V_37 ;
V_35 = F_12 ( V_31 , & V_8 -> V_38 -> V_39 ) ;
V_10 -> V_40 = false ;
V_10 -> V_24 = false ;
if ( V_35 ) {
if ( V_35 -> V_41 & V_42 ) {
V_36 = V_43 ;
V_10 -> V_40 =
F_13 ( V_35 ) ;
V_10 -> V_24 =
F_14 ( V_35 ) ;
}
F_15 ( V_35 ) ;
}
return V_36 ;
}
static int F_16 ( struct V_30 * V_31 ,
struct V_44 * V_45 ,
T_2 V_46 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
if ( ! strcmp ( V_45 -> V_47 , L_1 ) && V_2 ) {
struct V_15 * V_14 = F_3 ( V_2 -> V_14 ) ;
bool V_48 ;
T_2 V_49 ;
if ( ! V_14 )
return - 1 ;
switch ( V_46 ) {
case V_50 :
break;
case V_51 :
break;
case V_52 :
break;
default:
return - 1 ;
}
if ( F_17 ( & V_31 -> V_53 ,
V_45 , & V_49 ) )
return - 1 ;
if ( V_49 == V_46 )
return 0 ;
if ( F_18 ( & V_31 -> V_53 ,
V_45 , V_46 ) )
return - 1 ;
V_48 = ( V_49 == V_51 ) ||
( V_46 == V_51 ) ;
if ( V_14 -> V_54 . V_55 != 0 &&
V_14 -> V_54 . V_56 != 0 ) {
if ( V_48 ) {
if ( ! F_19 ( V_2 -> V_14 , & V_14 -> V_54 ,
V_2 -> V_14 -> V_57 , V_2 -> V_14 -> V_58 , V_2 -> V_14 -> V_59 ) )
return - 1 ;
} else {
struct V_60 * V_61
= V_2 -> V_62 ;
V_61 -> V_63 ( V_2 , & V_14 -> V_54 ,
& V_14 -> V_64 ) ;
}
}
}
return 0 ;
}
static int F_20 ( struct V_30 * V_31 )
{
struct V_8 * V_8 =
F_9 ( V_31 ) ;
struct V_35 * V_35 = NULL ;
int V_65 = 0 ;
V_35 = F_12 ( V_31 , & V_8 -> V_38 -> V_39 ) ;
if ( V_35 ) {
F_21 ( V_31 , V_35 ) ;
V_65 = F_22 ( V_31 , V_35 ) ;
F_15 ( V_35 ) ;
}
return V_65 ;
}
static int F_23 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
if ( V_4 -> clock > 165000 )
return V_66 ;
if ( V_4 -> clock < 20000 )
return V_66 ;
if ( V_4 -> V_17 & V_67 )
return V_68 ;
if ( V_4 -> V_17 & V_69 )
return V_70 ;
return V_71 ;
}
static void F_24 ( struct V_30 * V_31 )
{
struct V_8 * V_8 =
F_9 ( V_31 ) ;
if ( V_8 -> V_38 )
F_25 ( V_8 -> V_38 ) ;
F_26 ( V_31 ) ;
F_27 ( V_31 ) ;
F_15 ( V_31 ) ;
}
void F_28 ( struct V_6 * V_7 ,
struct V_72 * V_73 , int V_74 )
{
struct V_8 * V_8 ;
struct V_75 * V_75 ;
struct V_30 * V_31 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_76 ;
V_8 = F_29 ( sizeof( struct V_8 ) ,
V_77 ) ;
if ( ! V_8 )
return;
V_75 = F_29 ( sizeof( struct V_75 ) ,
V_77 ) ;
if ( ! V_75 )
goto V_78;
V_10 = F_29 ( sizeof( struct V_9 ) , V_77 ) ;
if ( ! V_10 )
goto V_79;
V_31 = & V_75 -> V_53 ;
V_2 = & V_8 -> V_53 ;
F_30 ( V_7 , V_31 ,
& V_80 ,
V_81 ) ;
F_31 ( V_7 , V_2 , & V_82 ,
V_83 ) ;
F_32 ( V_75 ,
V_8 ) ;
V_8 -> type = V_84 ;
V_10 -> V_27 = V_74 ;
V_10 -> V_40 = false ;
V_8 -> V_11 = V_10 ;
F_33 ( V_2 , & V_85 ) ;
F_34 ( V_31 ,
& V_86 ) ;
V_31 -> V_87 . V_88 = V_89 ;
V_31 -> V_90 = false ;
V_31 -> V_91 = false ;
F_35 ( & V_31 -> V_53 ,
V_7 -> V_92 . V_93 ,
V_50 ) ;
switch ( V_74 ) {
case V_94 :
V_76 = V_95 ;
V_8 -> V_96 = V_97 ;
break;
case V_98 :
V_76 = V_99 ;
V_8 -> V_96 = V_100 ;
break;
default:
F_36 ( L_2 , V_74 ) ;
goto V_101;
break;
}
V_8 -> V_38 = F_37 ( V_7 ,
V_76 , ( V_74 == V_94 ) ? L_3 : L_4 ) ;
if ( ! V_8 -> V_38 ) {
F_38 ( V_7 -> V_7 , L_5 ) ;
goto V_101;
}
V_10 -> V_102 =
& ( V_8 -> V_38 -> V_39 ) ;
V_10 -> V_7 = V_7 ;
F_39 ( V_31 ) ;
return;
V_101:
F_40 ( V_2 ) ;
F_27 ( V_31 ) ;
V_79:
F_15 ( V_75 ) ;
V_78:
F_15 ( V_8 ) ;
}
