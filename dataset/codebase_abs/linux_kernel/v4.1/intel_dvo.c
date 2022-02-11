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
struct V_8 * V_9 = V_6 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_1 V_13 ;
V_13 = F_6 ( V_1 -> V_9 . V_14 ) ;
if ( ! ( V_13 & V_15 ) )
return false ;
return V_1 -> V_9 . V_16 -> V_17 ( & V_1 -> V_9 ) ;
}
static bool F_7 ( struct V_2 * V_3 ,
enum V_18 * V_18 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_13 ;
V_13 = F_6 ( V_1 -> V_9 . V_14 ) ;
if ( ! ( V_13 & V_15 ) )
return false ;
* V_18 = F_8 ( V_13 ) ;
return true ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_13 , V_21 = 0 ;
V_13 = F_6 ( V_1 -> V_9 . V_14 ) ;
if ( V_13 & V_22 )
V_21 |= V_23 ;
else
V_21 |= V_24 ;
if ( V_13 & V_25 )
V_21 |= V_26 ;
else
V_21 |= V_27 ;
V_20 -> V_4 . V_28 . V_21 |= V_21 ;
V_20 -> V_4 . V_28 . V_29 = V_20 -> V_30 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_14 = V_1 -> V_9 . V_14 ;
T_1 V_31 = F_6 ( V_14 ) ;
V_1 -> V_9 . V_16 -> V_32 ( & V_1 -> V_9 , false ) ;
F_11 ( V_14 , V_31 & ~ V_15 ) ;
F_6 ( V_14 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_9 -> V_12 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
T_1 V_14 = V_1 -> V_9 . V_14 ;
T_1 V_31 = F_6 ( V_14 ) ;
V_1 -> V_9 . V_16 -> V_35 ( & V_1 -> V_9 ,
& V_34 -> V_36 -> V_4 . V_37 ,
& V_34 -> V_36 -> V_4 . V_28 ) ;
F_11 ( V_14 , V_31 | V_15 ) ;
F_6 ( V_14 ) ;
V_1 -> V_9 . V_16 -> V_32 ( & V_1 -> V_9 , true ) ;
}
static void F_14 ( struct V_5 * V_6 , int V_37 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_38 * V_34 ;
struct V_19 * V_36 ;
if ( V_37 != V_39 )
V_37 = V_40 ;
if ( V_37 == V_6 -> V_32 )
return;
V_6 -> V_32 = V_37 ;
V_34 = V_1 -> V_4 . V_4 . V_34 ;
if ( ! V_34 ) {
V_1 -> V_4 . V_41 = false ;
return;
}
if ( V_37 == V_39 ) {
V_36 = F_13 ( V_34 ) -> V_36 ;
V_1 -> V_4 . V_41 = true ;
F_15 ( V_34 ) ;
V_1 -> V_9 . V_16 -> V_32 ( & V_1 -> V_9 , true ) ;
} else {
V_1 -> V_9 . V_16 -> V_32 ( & V_1 -> V_9 , false ) ;
V_1 -> V_4 . V_41 = false ;
F_15 ( V_34 ) ;
}
F_16 ( V_6 -> V_9 ) ;
}
static enum V_42
F_17 ( struct V_5 * V_6 ,
struct V_43 * V_37 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_37 -> V_21 & V_44 )
return V_45 ;
if ( V_1 -> V_46 ) {
if ( V_37 -> V_47 > V_1 -> V_46 -> V_47 )
return V_48 ;
if ( V_37 -> V_49 > V_1 -> V_46 -> V_49 )
return V_48 ;
}
return V_1 -> V_9 . V_16 -> V_50 ( & V_1 -> V_9 , V_37 ) ;
}
static bool F_18 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_43 * V_28 = & V_20 -> V_4 . V_28 ;
if ( V_1 -> V_46 != NULL ) {
#define F_19 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_19 ( V_47 ) ;
F_19 ( V_51 ) ;
F_19 ( V_52 ) ;
F_19 ( V_53 ) ;
F_19 ( V_49 ) ;
F_19 ( V_54 ) ;
F_19 ( V_55 ) ;
F_19 ( V_56 ) ;
F_19 ( clock ) ;
#undef F_19
F_20 ( V_28 , 0 ) ;
}
return true ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
struct V_43 * V_28 = & V_34 -> V_36 -> V_4 . V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_18 = V_34 -> V_18 ;
T_1 V_57 ;
T_1 V_14 = V_1 -> V_9 . V_14 , V_58 ;
switch ( V_14 ) {
case V_59 :
default:
V_58 = V_60 ;
break;
case V_61 :
V_58 = V_62 ;
break;
case V_63 :
V_58 = V_64 ;
break;
}
V_57 = F_6 ( V_14 ) &
( V_65 | V_66 ) ;
V_57 |= V_67 | V_68 |
V_69 ;
if ( V_18 == 1 )
V_57 |= V_70 ;
V_57 |= V_71 ;
if ( V_28 -> V_21 & V_23 )
V_57 |= V_22 ;
if ( V_28 -> V_21 & V_26 )
V_57 |= V_25 ;
F_11 ( V_58 ,
( V_28 -> V_47 << V_72 ) |
( V_28 -> V_49 << V_73 ) ) ;
F_11 ( V_14 , V_57 ) ;
}
static enum V_74
F_22 ( struct V_5 * V_6 , bool V_75 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_23 ( L_1 ,
V_6 -> V_4 . V_76 , V_6 -> V_77 ) ;
return V_1 -> V_9 . V_16 -> V_78 ( & V_1 -> V_9 ) ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_9 -> V_12 ;
F_25 ( V_6 ,
F_26 ( V_11 , V_79 ) ) ;
if ( ! F_27 ( & V_6 -> V_80 ) )
return 1 ;
if ( V_1 -> V_46 != NULL ) {
struct V_43 * V_37 ;
V_37 = F_28 ( V_6 -> V_9 , V_1 -> V_46 ) ;
if ( V_37 ) {
F_29 ( V_6 , V_37 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_30 ( struct V_5 * V_6 )
{
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static void F_33 ( struct V_81 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_34 ( V_3 ) ) ;
if ( V_1 -> V_9 . V_16 -> V_82 )
V_1 -> V_9 . V_16 -> V_82 ( & V_1 -> V_9 ) ;
F_32 ( V_1 -> V_46 ) ;
F_35 ( V_3 ) ;
}
static struct V_43 *
F_36 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_57 = F_6 ( V_1 -> V_9 . V_14 ) ;
struct V_43 * V_37 = NULL ;
if ( V_57 & V_15 ) {
struct V_38 * V_34 ;
int V_18 = ( V_57 & V_70 ) ? 1 : 0 ;
V_34 = F_37 ( V_9 , V_18 ) ;
if ( V_34 ) {
V_37 = F_38 ( V_9 , V_34 ) ;
if ( V_37 ) {
V_37 -> type |= V_83 ;
if ( V_57 & V_22 )
V_37 -> V_21 |= V_23 ;
if ( V_57 & V_25 )
V_37 -> V_21 |= V_26 ;
}
}
}
return V_37 ;
}
void F_39 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_84 ;
int V_85 = V_86 ;
V_1 = F_40 ( sizeof( * V_1 ) , V_87 ) ;
if ( ! V_1 )
return;
V_7 = F_41 () ;
if ( ! V_7 ) {
F_32 ( V_1 ) ;
return;
}
V_2 = & V_1 -> V_4 ;
F_42 ( V_9 , & V_2 -> V_4 ,
& V_88 , V_85 ) ;
V_2 -> V_89 = F_10 ;
V_2 -> V_90 = F_12 ;
V_2 -> V_17 = F_7 ;
V_2 -> V_91 = F_9 ;
V_2 -> V_92 = F_18 ;
V_2 -> V_93 = F_21 ;
V_7 -> V_17 = F_5 ;
V_7 -> V_94 = V_95 ;
for ( V_84 = 0 ; V_84 < F_43 ( V_96 ) ; V_84 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_97 * V_98 = & V_96 [ V_84 ] ;
struct V_99 * V_100 ;
int V_101 ;
bool V_102 ;
if ( F_44 ( V_98 -> V_101 ) )
V_101 = V_98 -> V_101 ;
else if ( V_98 -> type == V_103 )
V_101 = V_104 ;
else
V_101 = V_105 ;
V_100 = F_26 ( V_11 , V_101 ) ;
V_1 -> V_9 = * V_98 ;
F_45 ( V_100 , true ) ;
V_102 = V_98 -> V_16 -> V_106 ( & V_1 -> V_9 , V_100 ) ;
F_45 ( V_100 , false ) ;
if ( ! V_102 )
continue;
V_2 -> type = V_107 ;
V_2 -> V_108 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_98 -> type ) {
case V_109 :
V_2 -> V_110 = ( 1 << V_111 ) |
( 1 << V_107 ) ;
F_46 ( V_9 , V_6 ,
& V_112 ,
V_113 ) ;
V_85 = V_114 ;
break;
case V_103 :
V_2 -> V_110 = 0 ;
F_46 ( V_9 , V_6 ,
& V_112 ,
V_115 ) ;
V_85 = V_116 ;
break;
}
F_47 ( V_6 ,
& V_117 ) ;
V_6 -> V_118 . V_119 = V_120 ;
V_6 -> V_121 = false ;
V_6 -> V_122 = false ;
F_48 ( V_7 , V_2 ) ;
if ( V_98 -> type == V_103 ) {
V_1 -> V_46 =
F_36 ( V_6 ) ;
V_1 -> V_123 = true ;
}
F_49 ( V_6 ) ;
return;
}
F_50 ( & V_2 -> V_4 ) ;
F_32 ( V_1 ) ;
F_32 ( V_7 ) ;
}
