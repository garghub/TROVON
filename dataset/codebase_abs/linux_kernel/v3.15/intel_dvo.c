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
V_20 -> V_28 . V_29 = V_20 -> V_30 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_4 . V_8 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_17 = V_1 -> V_8 . V_17 ;
T_1 V_31 = F_7 ( V_17 ) ;
V_1 -> V_8 . V_9 -> V_32 ( & V_1 -> V_8 , false ) ;
F_11 ( V_17 , V_31 & ~ V_18 ) ;
F_7 ( V_17 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_4 . V_8 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
T_1 V_17 = V_1 -> V_8 . V_17 ;
T_1 V_31 = F_7 ( V_17 ) ;
F_11 ( V_17 , V_31 | V_18 ) ;
F_7 ( V_17 ) ;
V_1 -> V_8 . V_9 -> V_35 ( & V_1 -> V_8 ,
& V_34 -> V_36 . V_37 ,
& V_34 -> V_36 . V_28 ) ;
V_1 -> V_8 . V_9 -> V_32 ( & V_1 -> V_8 , true ) ;
}
static void F_14 ( struct V_5 * V_6 , int V_38 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_39 * V_34 ;
struct V_19 * V_36 ;
if ( V_38 != V_40 )
V_38 = V_41 ;
if ( V_38 == V_6 -> V_32 )
return;
V_6 -> V_32 = V_38 ;
V_34 = V_1 -> V_4 . V_4 . V_34 ;
if ( ! V_34 ) {
V_1 -> V_4 . V_42 = false ;
return;
}
if ( V_38 == V_40 ) {
V_36 = & F_13 ( V_34 ) -> V_36 ;
V_1 -> V_4 . V_42 = true ;
F_15 ( V_34 ) ;
V_1 -> V_8 . V_9 -> V_35 ( & V_1 -> V_8 ,
& V_36 -> V_37 ,
& V_36 -> V_28 ) ;
V_1 -> V_8 . V_9 -> V_32 ( & V_1 -> V_8 , true ) ;
} else {
V_1 -> V_8 . V_9 -> V_32 ( & V_1 -> V_8 , false ) ;
V_1 -> V_4 . V_42 = false ;
F_15 ( V_34 ) ;
}
F_16 ( V_6 -> V_8 ) ;
}
static enum V_43
F_17 ( struct V_5 * V_6 ,
struct V_44 * V_38 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_38 -> V_21 & V_45 )
return V_46 ;
if ( V_1 -> V_47 ) {
if ( V_38 -> V_48 > V_1 -> V_47 -> V_48 )
return V_49 ;
if ( V_38 -> V_50 > V_1 -> V_47 -> V_50 )
return V_49 ;
}
return V_1 -> V_8 . V_9 -> V_51 ( & V_1 -> V_8 , V_38 ) ;
}
static bool F_18 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_44 * V_28 = & V_20 -> V_28 ;
if ( V_1 -> V_47 != NULL ) {
#define F_19 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_19 ( V_48 ) ;
F_19 ( V_52 ) ;
F_19 ( V_53 ) ;
F_19 ( V_54 ) ;
F_19 ( V_50 ) ;
F_19 ( V_55 ) ;
F_19 ( V_56 ) ;
F_19 ( V_57 ) ;
F_19 ( clock ) ;
#undef F_19
F_20 ( V_28 , 0 ) ;
}
return true ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_12 * V_8 = V_3 -> V_4 . V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
struct V_44 * V_28 = & V_34 -> V_36 . V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = V_34 -> V_11 ;
T_1 V_58 ;
T_1 V_17 = V_1 -> V_8 . V_17 , V_59 ;
switch ( V_17 ) {
case V_60 :
default:
V_59 = V_61 ;
break;
case V_62 :
V_59 = V_63 ;
break;
case V_64 :
V_59 = V_65 ;
break;
}
V_58 = F_7 ( V_17 ) &
( V_66 | V_67 ) ;
V_58 |= V_68 | V_69 |
V_70 ;
if ( V_11 == 1 )
V_58 |= V_71 ;
V_58 |= V_72 ;
if ( V_28 -> V_21 & V_23 )
V_58 |= V_22 ;
if ( V_28 -> V_21 & V_26 )
V_58 |= V_25 ;
F_11 ( V_59 ,
( V_28 -> V_48 << V_73 ) |
( V_28 -> V_50 << V_74 ) ) ;
F_11 ( V_17 , V_58 ) ;
}
static enum V_75
F_22 ( struct V_5 * V_6 , bool V_76 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_23 ( L_1 ,
V_6 -> V_4 . V_77 , F_24 ( V_6 ) ) ;
return V_1 -> V_8 . V_9 -> V_78 ( & V_1 -> V_8 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_6 -> V_8 -> V_15 ;
F_26 ( V_6 ,
F_27 ( V_14 , V_79 ) ) ;
if ( ! F_28 ( & V_6 -> V_80 ) )
return 1 ;
if ( V_1 -> V_47 != NULL ) {
struct V_44 * V_38 ;
V_38 = F_29 ( V_6 -> V_8 , V_1 -> V_47 ) ;
if ( V_38 ) {
F_30 ( V_6 , V_38 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_31 ( struct V_5 * V_6 )
{
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
}
static void F_34 ( struct V_81 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_35 ( V_3 ) ) ;
if ( V_1 -> V_8 . V_9 -> V_82 )
V_1 -> V_8 . V_9 -> V_82 ( & V_1 -> V_8 ) ;
F_33 ( V_1 -> V_47 ) ;
F_36 ( V_3 ) ;
}
static struct V_44 *
F_37 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = V_6 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_58 = F_7 ( V_1 -> V_8 . V_17 ) ;
struct V_44 * V_38 = NULL ;
if ( V_58 & V_18 ) {
struct V_39 * V_34 ;
int V_11 = ( V_58 & V_71 ) ? 1 : 0 ;
V_34 = F_38 ( V_8 , V_11 ) ;
if ( V_34 ) {
V_38 = F_39 ( V_8 , V_34 ) ;
if ( V_38 ) {
V_38 -> type |= V_83 ;
if ( V_58 & V_22 )
V_38 -> V_21 |= V_23 ;
if ( V_58 & V_25 )
V_38 -> V_21 |= V_26 ;
}
}
}
return V_38 ;
}
void F_40 ( struct V_12 * V_8 )
{
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_84 ;
int V_85 = V_86 ;
V_1 = F_41 ( sizeof( * V_1 ) , V_87 ) ;
if ( ! V_1 )
return;
V_7 = F_41 ( sizeof( * V_7 ) , V_87 ) ;
if ( ! V_7 ) {
F_33 ( V_1 ) ;
return;
}
V_2 = & V_1 -> V_4 ;
F_42 ( V_8 , & V_2 -> V_4 ,
& V_88 , V_85 ) ;
V_2 -> V_89 = F_10 ;
V_2 -> V_90 = F_12 ;
V_2 -> V_10 = F_6 ;
V_2 -> V_91 = F_9 ;
V_2 -> V_92 = F_18 ;
V_2 -> V_35 = F_21 ;
V_7 -> V_10 = F_5 ;
V_7 -> V_93 = V_94 ;
for ( V_84 = 0 ; V_84 < F_43 ( V_95 ) ; V_84 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_96 * V_97 = & V_95 [ V_84 ] ;
struct V_98 * V_99 ;
int V_100 ;
bool V_101 ;
if ( F_44 ( V_97 -> V_100 ) )
V_100 = V_97 -> V_100 ;
else if ( V_97 -> type == V_102 )
V_100 = V_103 ;
else
V_100 = V_104 ;
V_99 = F_27 ( V_14 , V_100 ) ;
V_1 -> V_8 = * V_97 ;
F_45 ( V_99 , true ) ;
V_101 = V_97 -> V_9 -> V_105 ( & V_1 -> V_8 , V_99 ) ;
F_45 ( V_99 , false ) ;
if ( ! V_101 )
continue;
V_2 -> type = V_106 ;
V_2 -> V_107 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_97 -> type ) {
case V_108 :
V_2 -> V_109 = ( 1 << V_110 ) |
( 1 << V_106 ) ;
F_46 ( V_8 , V_6 ,
& V_111 ,
V_112 ) ;
V_85 = V_113 ;
break;
case V_102 :
V_2 -> V_109 = 0 ;
F_46 ( V_8 , V_6 ,
& V_111 ,
V_114 ) ;
V_85 = V_115 ;
break;
}
F_47 ( V_6 ,
& V_116 ) ;
V_6 -> V_117 . V_118 = V_119 ;
V_6 -> V_120 = false ;
V_6 -> V_121 = false ;
F_48 ( V_7 , V_2 ) ;
if ( V_97 -> type == V_102 ) {
V_1 -> V_47 =
F_37 ( V_6 ) ;
V_1 -> V_122 = true ;
}
F_49 ( V_6 ) ;
return;
}
F_50 ( & V_2 -> V_4 ) ;
F_33 ( V_1 ) ;
F_33 ( V_7 ) ;
}
