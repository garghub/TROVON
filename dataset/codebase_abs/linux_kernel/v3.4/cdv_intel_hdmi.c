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
struct V_3 * V_4 ,
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
struct V_35 * V_35 =
F_12 ( V_31 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_36 * V_36 = NULL ;
enum V_33 V_37 = V_38 ;
V_36 = F_13 ( V_31 , & V_8 -> V_39 -> V_40 ) ;
V_10 -> V_41 = false ;
V_10 -> V_24 = false ;
if ( V_36 ) {
if ( V_36 -> V_42 & V_43 ) {
V_37 = V_44 ;
V_10 -> V_41 =
F_14 ( V_36 ) ;
V_10 -> V_24 =
F_15 ( V_36 ) ;
}
V_35 -> V_45 . V_46 . V_47 = NULL ;
F_16 ( V_36 ) ;
}
return V_37 ;
}
static int F_17 ( struct V_30 * V_31 ,
struct V_48 * V_49 ,
T_2 V_50 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
if ( ! strcmp ( V_49 -> V_51 , L_1 ) && V_2 ) {
struct V_15 * V_14 = F_3 ( V_2 -> V_14 ) ;
bool V_52 ;
T_2 V_53 ;
if ( ! V_14 )
return - 1 ;
switch ( V_50 ) {
case V_54 :
break;
case V_55 :
break;
case V_56 :
break;
default:
return - 1 ;
}
if ( F_18 ( V_31 ,
V_49 , & V_53 ) )
return - 1 ;
if ( V_53 == V_50 )
return 0 ;
if ( F_19 ( V_31 ,
V_49 , V_50 ) )
return - 1 ;
V_52 = ( V_53 == V_55 ) ||
( V_50 == V_55 ) ;
if ( V_14 -> V_57 . V_58 != 0 &&
V_14 -> V_57 . V_59 != 0 ) {
if ( V_52 ) {
if ( ! F_20 ( V_2 -> V_14 , & V_14 -> V_57 ,
V_2 -> V_14 -> V_60 , V_2 -> V_14 -> V_61 , V_2 -> V_14 -> V_62 ) )
return - 1 ;
} else {
struct V_63 * V_64
= V_2 -> V_65 ;
V_64 -> V_66 ( V_2 , & V_14 -> V_57 ,
& V_14 -> V_67 ) ;
}
}
}
return 0 ;
}
static int F_21 ( struct V_30 * V_31 )
{
struct V_8 * V_8 =
F_9 ( V_31 ) ;
struct V_36 * V_36 = NULL ;
int V_68 = 0 ;
V_36 = F_13 ( V_31 , & V_8 -> V_39 -> V_40 ) ;
if ( V_36 ) {
F_22 ( V_31 , V_36 ) ;
V_68 = F_23 ( V_31 , V_36 ) ;
F_16 ( V_36 ) ;
}
return V_68 ;
}
static int F_24 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_69 * V_11 = V_31 -> V_7 -> V_70 ;
if ( V_4 -> clock > 165000 )
return V_71 ;
if ( V_4 -> clock < 20000 )
return V_71 ;
if ( V_4 -> V_17 & V_72 )
return V_73 ;
if ( V_4 -> V_17 & V_74 )
return V_75 ;
if ( ( F_25 ( V_4 -> V_58 * 4 , 64 ) * V_4 -> V_59 ) >
V_11 -> V_76 )
return V_77 ;
return V_78 ;
}
static void F_26 ( struct V_30 * V_31 )
{
struct V_8 * V_8 =
F_9 ( V_31 ) ;
if ( V_8 -> V_39 )
F_27 ( V_8 -> V_39 ) ;
F_28 ( V_31 ) ;
F_29 ( V_31 ) ;
F_16 ( V_31 ) ;
}
void F_30 ( struct V_6 * V_7 ,
struct V_79 * V_80 , int V_81 )
{
struct V_8 * V_8 ;
struct V_35 * V_35 ;
struct V_30 * V_31 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_82 ;
V_8 = F_31 ( sizeof( struct V_8 ) ,
V_83 ) ;
if ( ! V_8 )
return;
V_35 = F_31 ( sizeof( struct V_35 ) ,
V_83 ) ;
if ( ! V_35 )
goto V_84;
V_10 = F_31 ( sizeof( struct V_9 ) , V_83 ) ;
if ( ! V_10 )
goto V_85;
V_31 = & V_35 -> V_45 ;
V_2 = & V_8 -> V_45 ;
F_32 ( V_7 , V_31 ,
& V_86 ,
V_87 ) ;
F_33 ( V_7 , V_2 , & V_88 ,
V_89 ) ;
F_34 ( V_35 ,
V_8 ) ;
V_8 -> type = V_90 ;
V_10 -> V_27 = V_81 ;
V_10 -> V_41 = false ;
V_8 -> V_11 = V_10 ;
F_35 ( V_2 , & V_91 ) ;
F_36 ( V_31 ,
& V_92 ) ;
V_31 -> V_46 . V_93 = V_94 ;
V_31 -> V_95 = false ;
V_31 -> V_96 = false ;
F_37 ( V_31 ,
V_7 -> V_97 . V_98 ,
V_54 ) ;
switch ( V_81 ) {
case V_99 :
V_82 = V_100 ;
break;
case V_101 :
V_82 = V_102 ;
break;
default:
F_38 ( L_2 , V_81 ) ;
goto V_103;
break;
}
V_8 -> V_39 = F_39 ( V_7 ,
V_82 , ( V_81 == V_99 ) ? L_3 : L_4 ) ;
if ( ! V_8 -> V_39 ) {
F_40 ( V_7 -> V_7 , L_5 ) ;
goto V_103;
}
V_10 -> V_104 =
& ( V_8 -> V_39 -> V_40 ) ;
V_10 -> V_7 = V_7 ;
F_41 ( V_31 ) ;
return;
V_103:
F_42 ( V_2 ) ;
F_29 ( V_31 ) ;
V_85:
F_16 ( V_35 ) ;
V_84:
F_16 ( V_8 ) ;
}
