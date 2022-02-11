static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_15 * V_15 = F_3 ( V_14 ) ;
V_12 = ( 2 << 10 ) ;
if ( V_5 -> V_16 & V_17 )
V_12 |= V_18 ;
if ( V_5 -> V_16 & V_19 )
V_12 |= V_20 ;
if ( V_15 -> V_21 == 1 )
V_12 |= V_22 ;
if ( V_10 -> V_23 ) {
V_12 |= V_24 ;
V_12 |= V_25 ;
}
F_4 ( V_10 -> V_26 , V_12 ) ;
F_5 ( V_10 -> V_26 ) ;
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
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 ;
V_12 = F_5 ( V_10 -> V_26 ) ;
if ( V_4 != V_27 )
F_4 ( V_10 -> V_26 , V_12 & ~ V_28 ) ;
else
F_4 ( V_10 -> V_26 , V_12 | V_28 ) ;
F_5 ( V_10 -> V_26 ) ;
}
static void F_8 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_7 ;
struct V_8 * V_8 = F_9 ( V_30 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
V_10 -> V_31 = F_5 ( V_10 -> V_26 ) ;
}
static void F_10 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_7 ;
struct V_8 * V_8 = F_9 ( V_30 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_4 ( V_10 -> V_26 , V_10 -> V_31 ) ;
F_5 ( V_10 -> V_26 ) ;
}
static enum V_32 F_11 (
struct V_29 * V_30 , bool V_33 )
{
struct V_8 * V_8 = F_9 ( V_30 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_34 * V_34 = NULL ;
enum V_32 V_35 = V_36 ;
V_34 = F_12 ( V_30 , & V_8 -> V_37 -> V_38 ) ;
V_10 -> V_39 = false ;
V_10 -> V_23 = false ;
if ( V_34 ) {
if ( V_34 -> V_40 & V_41 ) {
V_35 = V_42 ;
V_10 -> V_39 =
F_13 ( V_34 ) ;
V_10 -> V_23 =
F_14 ( V_34 ) ;
}
F_15 ( V_34 ) ;
}
return V_35 ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_43 * V_44 ,
T_2 V_45 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
if ( ! strcmp ( V_44 -> V_46 , L_1 ) && V_2 ) {
struct V_15 * V_14 = F_3 ( V_2 -> V_14 ) ;
bool V_47 ;
T_2 V_48 ;
if ( ! V_14 )
return - 1 ;
switch ( V_45 ) {
case V_49 :
break;
case V_50 :
break;
case V_51 :
break;
default:
return - 1 ;
}
if ( F_17 ( & V_30 -> V_52 ,
V_44 , & V_48 ) )
return - 1 ;
if ( V_48 == V_45 )
return 0 ;
if ( F_18 ( & V_30 -> V_52 ,
V_44 , V_45 ) )
return - 1 ;
V_47 = ( V_48 == V_50 ) ||
( V_45 == V_50 ) ;
if ( V_14 -> V_53 . V_54 != 0 &&
V_14 -> V_53 . V_55 != 0 ) {
if ( V_47 ) {
if ( ! F_19 ( V_2 -> V_14 , & V_14 -> V_53 ,
V_2 -> V_14 -> V_56 , V_2 -> V_14 -> V_57 , V_2 -> V_14 -> V_58 ) )
return - 1 ;
} else {
struct V_59 * V_60
= V_2 -> V_61 ;
V_60 -> V_62 ( V_2 , & V_14 -> V_53 ,
& V_14 -> V_63 ) ;
}
}
}
return 0 ;
}
static int F_20 ( struct V_29 * V_30 )
{
struct V_8 * V_8 = F_9 ( V_30 ) ;
struct V_34 * V_34 = NULL ;
int V_64 = 0 ;
V_34 = F_12 ( V_30 , & V_8 -> V_37 -> V_38 ) ;
if ( V_34 ) {
F_21 ( V_30 , V_34 ) ;
V_64 = F_22 ( V_30 , V_34 ) ;
F_15 ( V_34 ) ;
}
return V_64 ;
}
static int F_23 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
if ( V_4 -> clock > 165000 )
return V_65 ;
if ( V_4 -> clock < 20000 )
return V_65 ;
if ( V_4 -> V_16 & V_66 )
return V_67 ;
if ( V_4 -> V_16 & V_68 )
return V_69 ;
return V_70 ;
}
static void F_24 ( struct V_29 * V_30 )
{
struct V_8 * V_8 = F_9 ( V_30 ) ;
if ( V_8 -> V_37 )
F_25 ( V_8 -> V_37 ) ;
F_26 ( V_30 ) ;
F_27 ( V_30 ) ;
F_15 ( V_30 ) ;
}
void F_28 ( struct V_6 * V_7 ,
struct V_71 * V_72 , int V_73 )
{
struct V_8 * V_8 ;
struct V_74 * V_74 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_75 ;
V_8 = F_29 ( sizeof( struct V_8 ) , V_76 ) ;
if ( ! V_8 )
return;
V_74 = F_29 ( sizeof( struct V_74 ) ,
V_76 ) ;
if ( ! V_74 )
goto V_77;
V_10 = F_29 ( sizeof( struct V_9 ) , V_76 ) ;
if ( ! V_10 )
goto V_78;
V_30 = & V_74 -> V_52 ;
V_30 -> V_79 = V_80 ;
V_2 = & V_8 -> V_52 ;
F_30 ( V_7 , V_30 ,
& V_81 ,
V_82 ) ;
F_31 ( V_7 , V_2 , & V_83 ,
V_84 ) ;
F_32 ( V_74 , V_8 ) ;
V_8 -> type = V_85 ;
V_10 -> V_26 = V_73 ;
V_10 -> V_39 = false ;
V_8 -> V_11 = V_10 ;
F_33 ( V_2 , & V_86 ) ;
F_34 ( V_30 ,
& V_87 ) ;
V_30 -> V_88 . V_89 = V_90 ;
V_30 -> V_91 = false ;
V_30 -> V_92 = false ;
F_35 ( & V_30 -> V_52 ,
V_7 -> V_93 . V_94 ,
V_49 ) ;
switch ( V_73 ) {
case V_95 :
V_75 = V_96 ;
V_8 -> V_97 = V_98 ;
break;
case V_99 :
V_75 = V_100 ;
V_8 -> V_97 = V_101 ;
break;
default:
F_36 ( L_2 , V_73 ) ;
goto V_102;
break;
}
V_8 -> V_37 = F_37 ( V_7 ,
V_75 , ( V_73 == V_95 ) ? L_3 : L_4 ) ;
if ( ! V_8 -> V_37 ) {
F_38 ( V_7 -> V_7 , L_5 ) ;
goto V_102;
}
V_10 -> V_103 = & ( V_8 -> V_37 -> V_38 ) ;
V_10 -> V_7 = V_7 ;
F_39 ( V_30 ) ;
return;
V_102:
F_40 ( V_2 ) ;
F_27 ( V_30 ) ;
V_78:
F_15 ( V_74 ) ;
V_77:
F_15 ( V_8 ) ;
}
