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
static void F_6 ( struct V_1 * V_2 , int V_4 )
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
static void F_7 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_7 ;
struct V_8 * V_8 = F_8 ( V_30 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
V_10 -> V_31 = F_5 ( V_10 -> V_26 ) ;
}
static void F_9 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_7 ;
struct V_8 * V_8 = F_8 ( V_30 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_4 ( V_10 -> V_26 , V_10 -> V_31 ) ;
F_5 ( V_10 -> V_26 ) ;
}
static enum V_32 F_10 (
struct V_29 * V_30 , bool V_33 )
{
struct V_8 * V_8 = F_8 ( V_30 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_34 * V_34 = NULL ;
enum V_32 V_35 = V_36 ;
V_34 = F_11 ( V_30 , & V_8 -> V_37 -> V_38 ) ;
V_10 -> V_39 = false ;
V_10 -> V_23 = false ;
if ( V_34 ) {
if ( V_34 -> V_40 & V_41 ) {
V_35 = V_42 ;
V_10 -> V_39 =
F_12 ( V_34 ) ;
V_10 -> V_23 =
F_13 ( V_34 ) ;
}
F_14 ( V_34 ) ;
}
return V_35 ;
}
static int F_15 ( struct V_29 * V_30 ,
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
if ( F_16 ( & V_30 -> V_52 ,
V_44 , & V_48 ) )
return - 1 ;
if ( V_48 == V_45 )
return 0 ;
if ( F_17 ( & V_30 -> V_52 ,
V_44 , V_45 ) )
return - 1 ;
V_47 = ( V_48 == V_50 ) ||
( V_45 == V_50 ) ;
if ( V_14 -> V_53 . V_54 != 0 &&
V_14 -> V_53 . V_55 != 0 ) {
if ( V_47 ) {
if ( ! F_18 ( V_2 -> V_14 , & V_14 -> V_53 ,
V_2 -> V_14 -> V_56 , V_2 -> V_14 -> V_57 , V_2 -> V_14 -> V_58 -> V_59 ) )
return - 1 ;
} else {
struct V_60 * V_61
= V_2 -> V_62 ;
V_61 -> V_63 ( V_2 , & V_14 -> V_53 ,
& V_14 -> V_64 ) ;
}
}
}
return 0 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_8 * V_8 = F_8 ( V_30 ) ;
struct V_34 * V_34 = NULL ;
int V_65 = 0 ;
V_34 = F_11 ( V_30 , & V_8 -> V_37 -> V_38 ) ;
if ( V_34 ) {
F_20 ( V_30 , V_34 ) ;
V_65 = F_21 ( V_30 , V_34 ) ;
F_14 ( V_34 ) ;
}
return V_65 ;
}
static int F_22 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
if ( V_4 -> clock > 165000 )
return V_66 ;
if ( V_4 -> clock < 20000 )
return V_66 ;
if ( V_4 -> V_16 & V_67 )
return V_68 ;
if ( V_4 -> V_16 & V_69 )
return V_70 ;
return V_71 ;
}
static void F_23 ( struct V_29 * V_30 )
{
struct V_8 * V_8 = F_8 ( V_30 ) ;
if ( V_8 -> V_37 )
F_24 ( V_8 -> V_37 ) ;
F_25 ( V_30 ) ;
F_26 ( V_30 ) ;
F_14 ( V_30 ) ;
}
void F_27 ( struct V_6 * V_7 ,
struct V_72 * V_73 , int V_74 )
{
struct V_8 * V_8 ;
struct V_75 * V_75 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_76 ;
V_8 = F_28 ( sizeof( struct V_8 ) , V_77 ) ;
if ( ! V_8 )
return;
V_75 = F_28 ( sizeof( struct V_75 ) ,
V_77 ) ;
if ( ! V_75 )
goto V_78;
V_10 = F_28 ( sizeof( struct V_9 ) , V_77 ) ;
if ( ! V_10 )
goto V_79;
V_30 = & V_75 -> V_52 ;
V_30 -> V_80 = V_81 ;
V_2 = & V_8 -> V_52 ;
F_29 ( V_7 , V_30 ,
& V_82 ,
V_83 ) ;
F_30 ( V_7 , V_2 , & V_84 ,
V_85 ) ;
F_31 ( V_75 , V_8 ) ;
V_8 -> type = V_86 ;
V_10 -> V_26 = V_74 ;
V_10 -> V_39 = false ;
V_8 -> V_11 = V_10 ;
F_32 ( V_2 , & V_87 ) ;
F_33 ( V_30 ,
& V_88 ) ;
V_30 -> V_89 . V_90 = V_91 ;
V_30 -> V_92 = false ;
V_30 -> V_93 = false ;
F_34 ( & V_30 -> V_52 ,
V_7 -> V_94 . V_95 ,
V_49 ) ;
switch ( V_74 ) {
case V_96 :
V_76 = V_97 ;
V_8 -> V_98 = V_99 ;
break;
case V_100 :
V_76 = V_101 ;
V_8 -> V_98 = V_102 ;
break;
default:
F_35 ( L_2 , V_74 ) ;
goto V_103;
break;
}
V_8 -> V_37 = F_36 ( V_7 ,
V_76 , ( V_74 == V_96 ) ? L_3 : L_4 ) ;
if ( ! V_8 -> V_37 ) {
F_37 ( V_7 -> V_7 , L_5 ) ;
goto V_103;
}
V_10 -> V_104 = & ( V_8 -> V_37 -> V_38 ) ;
V_10 -> V_7 = V_7 ;
F_38 ( V_30 ) ;
return;
V_103:
F_39 ( V_2 ) ;
F_26 ( V_30 ) ;
V_79:
F_14 ( V_75 ) ;
V_78:
F_14 ( V_8 ) ;
}
