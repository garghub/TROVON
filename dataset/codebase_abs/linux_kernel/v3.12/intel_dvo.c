static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 ) ) ;
}
static bool F_5 ( struct V_7 * V_6 )
{
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
return V_1 -> V_8 . V_9 -> V_10 ( & V_1 -> V_8 ) ;
}
static bool F_6 ( struct V_2 * V_3 ,
enum V_11 * V_11 )
{
struct V_12 * V_8 = V_3 -> V_4 . V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_16 ;
V_16 = F_7 ( V_1 -> V_8 . V_17 ) ;
if ( ! ( V_16 & V_18 ) )
return false ;
* V_11 = F_8 ( V_16 ) ;
return true ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_13 * V_14 = V_3 -> V_4 . V_8 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_16 , V_21 = 0 ;
V_16 = F_7 ( V_1 -> V_8 . V_17 ) ;
if ( V_16 & V_22 )
V_21 |= V_23 ;
else
V_21 |= V_24 ;
if ( V_16 & V_25 )
V_21 |= V_26 ;
else
V_21 |= V_27 ;
V_20 -> V_28 . V_21 |= V_21 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_4 . V_8 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_17 = V_1 -> V_8 . V_17 ;
T_1 V_29 = F_7 ( V_17 ) ;
V_1 -> V_8 . V_9 -> V_30 ( & V_1 -> V_8 , false ) ;
F_11 ( V_17 , V_29 & ~ V_18 ) ;
F_7 ( V_17 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_4 . V_8 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_17 = V_1 -> V_8 . V_17 ;
T_1 V_29 = F_7 ( V_17 ) ;
F_11 ( V_17 , V_29 | V_18 ) ;
F_7 ( V_17 ) ;
V_1 -> V_8 . V_9 -> V_30 ( & V_1 -> V_8 , true ) ;
}
static void F_13 ( struct V_5 * V_6 , int V_31 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_32 * V_33 ;
if ( V_31 != V_34 )
V_31 = V_35 ;
if ( V_31 == V_6 -> V_30 )
return;
V_6 -> V_30 = V_31 ;
V_33 = V_1 -> V_4 . V_4 . V_33 ;
if ( ! V_33 ) {
V_1 -> V_4 . V_36 = false ;
return;
}
if ( V_31 == V_34 ) {
V_1 -> V_4 . V_36 = true ;
F_14 ( V_33 ) ;
V_1 -> V_8 . V_9 -> V_30 ( & V_1 -> V_8 , true ) ;
} else {
V_1 -> V_8 . V_9 -> V_30 ( & V_1 -> V_8 , false ) ;
V_1 -> V_4 . V_36 = false ;
F_14 ( V_33 ) ;
}
F_15 ( V_6 -> V_8 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_37 * V_31 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_31 -> V_21 & V_38 )
return V_39 ;
if ( V_1 -> V_40 ) {
if ( V_31 -> V_41 > V_1 -> V_40 -> V_41 )
return V_42 ;
if ( V_31 -> V_43 > V_1 -> V_40 -> V_43 )
return V_42 ;
}
return V_1 -> V_8 . V_9 -> V_44 ( & V_1 -> V_8 , V_31 ) ;
}
static bool F_17 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_37 * V_28 = & V_20 -> V_28 ;
if ( V_1 -> V_40 != NULL ) {
#define F_18 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_18 ( V_41 ) ;
F_18 ( V_45 ) ;
F_18 ( V_46 ) ;
F_18 ( V_47 ) ;
F_18 ( V_43 ) ;
F_18 ( V_48 ) ;
F_18 ( V_49 ) ;
F_18 ( V_50 ) ;
F_18 ( clock ) ;
#undef F_18
F_19 ( V_28 , 0 ) ;
}
if ( V_1 -> V_8 . V_9 -> V_51 )
return V_1 -> V_8 . V_9 -> V_51 ( & V_1 -> V_8 ,
& V_20 -> V_52 ,
V_28 ) ;
return true ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_12 * V_8 = V_3 -> V_4 . V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_53 * V_33 = F_21 ( V_3 -> V_4 . V_33 ) ;
struct V_37 * V_28 = & V_33 -> V_54 . V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = V_33 -> V_11 ;
T_1 V_55 ;
T_1 V_17 = V_1 -> V_8 . V_17 , V_56 ;
switch ( V_17 ) {
case V_57 :
default:
V_56 = V_58 ;
break;
case V_59 :
V_56 = V_60 ;
break;
case V_61 :
V_56 = V_62 ;
break;
}
V_1 -> V_8 . V_9 -> V_63 ( & V_1 -> V_8 ,
& V_33 -> V_54 . V_52 ,
V_28 ) ;
V_55 = F_7 ( V_17 ) &
( V_64 | V_65 ) ;
V_55 |= V_66 | V_67 |
V_68 ;
if ( V_11 == 1 )
V_55 |= V_69 ;
V_55 |= V_70 ;
if ( V_28 -> V_21 & V_23 )
V_55 |= V_22 ;
if ( V_28 -> V_21 & V_26 )
V_55 |= V_25 ;
F_11 ( V_56 ,
( V_28 -> V_41 << V_71 ) |
( V_28 -> V_43 << V_72 ) ) ;
F_11 ( V_17 , V_55 ) ;
}
static enum V_73
F_22 ( struct V_5 * V_6 , bool V_74 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_23 ( L_1 ,
V_6 -> V_4 . V_75 , F_24 ( V_6 ) ) ;
return V_1 -> V_8 . V_9 -> V_76 ( & V_1 -> V_8 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_6 -> V_8 -> V_15 ;
F_26 ( V_6 ,
F_27 ( V_14 , V_77 ) ) ;
if ( ! F_28 ( & V_6 -> V_78 ) )
return 1 ;
if ( V_1 -> V_40 != NULL ) {
struct V_37 * V_31 ;
V_31 = F_29 ( V_6 -> V_8 , V_1 -> V_40 ) ;
if ( V_31 ) {
F_30 ( V_6 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_31 ( struct V_5 * V_6 )
{
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
}
static void F_35 ( struct V_79 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_36 ( V_3 ) ) ;
if ( V_1 -> V_8 . V_9 -> V_80 )
V_1 -> V_8 . V_9 -> V_80 ( & V_1 -> V_8 ) ;
F_34 ( V_1 -> V_40 ) ;
F_37 ( V_3 ) ;
}
static struct V_37 *
F_38 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = V_6 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_55 = F_7 ( V_1 -> V_8 . V_17 ) ;
struct V_37 * V_31 = NULL ;
if ( V_55 & V_18 ) {
struct V_32 * V_33 ;
int V_11 = ( V_55 & V_69 ) ? 1 : 0 ;
V_33 = F_39 ( V_8 , V_11 ) ;
if ( V_33 ) {
V_31 = F_40 ( V_8 , V_33 ) ;
if ( V_31 ) {
V_31 -> type |= V_81 ;
if ( V_55 & V_22 )
V_31 -> V_21 |= V_23 ;
if ( V_55 & V_25 )
V_31 -> V_21 |= V_26 ;
}
}
}
return V_31 ;
}
void F_41 ( struct V_12 * V_8 )
{
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_82 ;
int V_83 = V_84 ;
V_1 = F_42 ( sizeof( struct V_1 ) , V_85 ) ;
if ( ! V_1 )
return;
V_7 = F_42 ( sizeof( struct V_7 ) , V_85 ) ;
if ( ! V_7 ) {
F_34 ( V_1 ) ;
return;
}
V_2 = & V_1 -> V_4 ;
F_43 ( V_8 , & V_2 -> V_4 ,
& V_86 , V_83 ) ;
V_2 -> V_87 = F_10 ;
V_2 -> V_88 = F_12 ;
V_2 -> V_10 = F_6 ;
V_2 -> V_89 = F_9 ;
V_2 -> V_90 = F_17 ;
V_2 -> V_63 = F_20 ;
V_7 -> V_10 = F_5 ;
for ( V_82 = 0 ; V_82 < F_44 ( V_91 ) ; V_82 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_92 * V_93 = & V_91 [ V_82 ] ;
struct V_94 * V_95 ;
int V_96 ;
bool V_97 ;
if ( F_45 ( V_93 -> V_96 ) )
V_96 = V_93 -> V_96 ;
else if ( V_93 -> type == V_98 )
V_96 = V_99 ;
else
V_96 = V_100 ;
V_95 = F_27 ( V_14 , V_96 ) ;
V_1 -> V_8 = * V_93 ;
F_46 ( V_95 , true ) ;
V_97 = V_93 -> V_9 -> V_101 ( & V_1 -> V_8 , V_95 ) ;
F_46 ( V_95 , false ) ;
if ( ! V_97 )
continue;
V_2 -> type = V_102 ;
V_2 -> V_103 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_93 -> type ) {
case V_104 :
V_2 -> V_105 = true ;
F_47 ( V_8 , V_6 ,
& V_106 ,
V_107 ) ;
V_83 = V_108 ;
break;
case V_98 :
V_2 -> V_105 = false ;
F_47 ( V_8 , V_6 ,
& V_106 ,
V_109 ) ;
V_83 = V_110 ;
break;
}
F_48 ( V_6 ,
& V_111 ) ;
V_6 -> V_112 . V_113 = V_114 ;
V_6 -> V_115 = false ;
V_6 -> V_116 = false ;
F_49 ( V_7 , V_2 ) ;
if ( V_93 -> type == V_98 ) {
V_1 -> V_40 =
F_38 ( V_6 ) ;
V_1 -> V_117 = true ;
}
F_50 ( V_6 ) ;
return;
}
F_51 ( & V_2 -> V_4 ) ;
F_34 ( V_1 ) ;
F_34 ( V_7 ) ;
}
