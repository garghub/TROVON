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
static enum V_38
F_14 ( struct V_5 * V_6 ,
struct V_39 * V_37 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_37 -> V_21 & V_40 )
return V_41 ;
if ( V_1 -> V_42 ) {
if ( V_37 -> V_43 > V_1 -> V_42 -> V_43 )
return V_44 ;
if ( V_37 -> V_45 > V_1 -> V_42 -> V_45 )
return V_44 ;
}
return V_1 -> V_9 . V_16 -> V_46 ( & V_1 -> V_9 , V_37 ) ;
}
static bool F_15 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_39 * V_28 = & V_20 -> V_4 . V_28 ;
if ( V_1 -> V_42 != NULL ) {
#define F_16 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_16 ( V_43 ) ;
F_16 ( V_47 ) ;
F_16 ( V_48 ) ;
F_16 ( V_49 ) ;
F_16 ( V_45 ) ;
F_16 ( V_50 ) ;
F_16 ( V_51 ) ;
F_16 ( V_52 ) ;
F_16 ( clock ) ;
#undef F_16
F_17 ( V_28 , 0 ) ;
}
return true ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
struct V_39 * V_28 = & V_34 -> V_36 -> V_4 . V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_18 = V_34 -> V_18 ;
T_1 V_53 ;
T_1 V_14 = V_1 -> V_9 . V_14 , V_54 ;
switch ( V_14 ) {
case V_55 :
default:
V_54 = V_56 ;
break;
case V_57 :
V_54 = V_58 ;
break;
case V_59 :
V_54 = V_60 ;
break;
}
V_53 = F_6 ( V_14 ) &
( V_61 | V_62 ) ;
V_53 |= V_63 | V_64 |
V_65 ;
if ( V_18 == 1 )
V_53 |= V_66 ;
V_53 |= V_67 ;
if ( V_28 -> V_21 & V_23 )
V_53 |= V_22 ;
if ( V_28 -> V_21 & V_26 )
V_53 |= V_25 ;
F_11 ( V_54 ,
( V_28 -> V_43 << V_68 ) |
( V_28 -> V_45 << V_69 ) ) ;
F_11 ( V_14 , V_53 ) ;
}
static enum V_70
F_19 ( struct V_5 * V_6 , bool V_71 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_20 ( L_1 ,
V_6 -> V_4 . V_72 , V_6 -> V_73 ) ;
return V_1 -> V_9 . V_16 -> V_74 ( & V_1 -> V_9 ) ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_10 * V_11 = V_6 -> V_9 -> V_12 ;
F_22 ( V_6 ,
F_23 ( V_11 , V_75 ) ) ;
if ( ! F_24 ( & V_6 -> V_76 ) )
return 1 ;
if ( V_1 -> V_42 != NULL ) {
struct V_39 * V_37 ;
V_37 = F_25 ( V_6 -> V_9 , V_1 -> V_42 ) ;
if ( V_37 ) {
F_26 ( V_6 , V_37 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_27 ( struct V_5 * V_6 )
{
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
}
static void F_30 ( struct V_77 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_31 ( V_3 ) ) ;
if ( V_1 -> V_9 . V_16 -> V_78 )
V_1 -> V_9 . V_16 -> V_78 ( & V_1 -> V_9 ) ;
F_29 ( V_1 -> V_42 ) ;
F_32 ( V_3 ) ;
}
static struct V_39 *
F_33 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_53 = F_6 ( V_1 -> V_9 . V_14 ) ;
struct V_39 * V_37 = NULL ;
if ( V_53 & V_15 ) {
struct V_79 * V_34 ;
int V_18 = ( V_53 & V_66 ) ? 1 : 0 ;
V_34 = F_34 ( V_9 , V_18 ) ;
if ( V_34 ) {
V_37 = F_35 ( V_9 , V_34 ) ;
if ( V_37 ) {
V_37 -> type |= V_80 ;
if ( V_53 & V_22 )
V_37 -> V_21 |= V_23 ;
if ( V_53 & V_25 )
V_37 -> V_21 |= V_26 ;
}
}
}
return V_37 ;
}
void F_36 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_81 ;
int V_82 = V_83 ;
V_1 = F_37 ( sizeof( * V_1 ) , V_84 ) ;
if ( ! V_1 )
return;
V_7 = F_38 () ;
if ( ! V_7 ) {
F_29 ( V_1 ) ;
return;
}
V_2 = & V_1 -> V_4 ;
F_39 ( V_9 , & V_2 -> V_4 ,
& V_85 , V_82 ) ;
V_2 -> V_86 = F_10 ;
V_2 -> V_87 = F_12 ;
V_2 -> V_17 = F_7 ;
V_2 -> V_88 = F_9 ;
V_2 -> V_89 = F_15 ;
V_2 -> V_90 = F_18 ;
V_7 -> V_17 = F_5 ;
V_7 -> V_91 = V_92 ;
for ( V_81 = 0 ; V_81 < F_40 ( V_93 ) ; V_81 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_94 * V_95 = & V_93 [ V_81 ] ;
struct V_96 * V_97 ;
int V_98 ;
bool V_99 ;
enum V_18 V_18 ;
T_3 V_100 [ V_101 ] ;
if ( F_41 ( V_11 , V_95 -> V_98 ) )
V_98 = V_95 -> V_98 ;
else if ( V_95 -> type == V_102 )
V_98 = V_103 ;
else
V_98 = V_104 ;
V_97 = F_23 ( V_11 , V_98 ) ;
V_1 -> V_9 = * V_95 ;
F_42 ( V_97 , true ) ;
F_43 (dev_priv, pipe) {
V_100 [ V_18 ] = F_6 ( F_44 ( V_18 ) ) ;
F_11 ( F_44 ( V_18 ) , V_100 [ V_18 ] | V_105 ) ;
}
V_99 = V_95 -> V_16 -> V_106 ( & V_1 -> V_9 , V_97 ) ;
F_43 (dev_priv, pipe) {
F_11 ( F_44 ( V_18 ) , V_100 [ V_18 ] ) ;
}
F_42 ( V_97 , false ) ;
if ( ! V_99 )
continue;
V_2 -> type = V_107 ;
V_2 -> V_108 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_95 -> type ) {
case V_109 :
V_2 -> V_110 = ( 1 << V_111 ) |
( 1 << V_107 ) ;
F_45 ( V_9 , V_6 ,
& V_112 ,
V_113 ) ;
V_82 = V_114 ;
break;
case V_102 :
V_2 -> V_110 = 0 ;
F_45 ( V_9 , V_6 ,
& V_112 ,
V_115 ) ;
V_82 = V_116 ;
break;
}
F_46 ( V_6 ,
& V_117 ) ;
V_6 -> V_118 . V_119 = V_120 ;
V_6 -> V_121 = false ;
V_6 -> V_122 = false ;
F_47 ( V_7 , V_2 ) ;
if ( V_95 -> type == V_102 ) {
V_1 -> V_42 =
F_33 ( V_6 ) ;
V_1 -> V_123 = true ;
}
F_48 ( V_6 ) ;
return;
}
F_49 ( & V_2 -> V_4 ) ;
F_29 ( V_1 ) ;
F_29 ( V_7 ) ;
}
