static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
static bool F_5 ( struct V_7 * V_6 )
{
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
return V_1 -> V_8 . V_9 -> V_10 ( & V_1 -> V_8 ) ;
}
static bool F_6 ( struct V_11 * V_3 ,
enum V_12 * V_12 )
{
struct V_13 * V_8 = V_3 -> V_4 . V_8 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_17 ;
V_17 = F_7 ( V_1 -> V_8 . V_18 ) ;
if ( ! ( V_17 & V_19 ) )
return false ;
* V_12 = F_8 ( V_17 ) ;
return true ;
}
static void F_9 ( struct V_11 * V_3 ,
struct V_20 * V_21 )
{
struct V_14 * V_15 = V_3 -> V_4 . V_8 -> V_16 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_17 , V_22 = 0 ;
V_17 = F_7 ( V_1 -> V_8 . V_18 ) ;
if ( V_17 & V_23 )
V_22 |= V_24 ;
else
V_22 |= V_25 ;
if ( V_17 & V_26 )
V_22 |= V_27 ;
else
V_22 |= V_28 ;
V_21 -> V_29 . V_22 |= V_22 ;
}
static void F_10 ( struct V_11 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_4 . V_8 -> V_16 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 = V_1 -> V_8 . V_18 ;
T_1 V_30 = F_7 ( V_18 ) ;
V_1 -> V_8 . V_9 -> V_31 ( & V_1 -> V_8 , false ) ;
F_11 ( V_18 , V_30 & ~ V_19 ) ;
F_7 ( V_18 ) ;
}
static void F_12 ( struct V_11 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_4 . V_8 -> V_16 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 = V_1 -> V_8 . V_18 ;
T_1 V_30 = F_7 ( V_18 ) ;
F_11 ( V_18 , V_30 | V_19 ) ;
F_7 ( V_18 ) ;
V_1 -> V_8 . V_9 -> V_31 ( & V_1 -> V_8 , true ) ;
}
static void F_13 ( struct V_5 * V_6 , int V_32 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_33 * V_34 ;
if ( V_32 != V_35 )
V_32 = V_36 ;
if ( V_32 == V_6 -> V_31 )
return;
V_6 -> V_31 = V_32 ;
V_34 = V_1 -> V_4 . V_4 . V_34 ;
if ( ! V_34 ) {
V_1 -> V_4 . V_37 = false ;
return;
}
if ( V_32 == V_35 ) {
V_1 -> V_4 . V_37 = true ;
F_14 ( V_34 ) ;
V_1 -> V_8 . V_9 -> V_31 ( & V_1 -> V_8 , true ) ;
} else {
V_1 -> V_8 . V_9 -> V_31 ( & V_1 -> V_8 , false ) ;
V_1 -> V_4 . V_37 = false ;
F_14 ( V_34 ) ;
}
F_15 ( V_6 -> V_8 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_38 * V_32 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_32 -> V_22 & V_39 )
return V_40 ;
if ( V_1 -> V_41 ) {
if ( V_32 -> V_42 > V_1 -> V_41 -> V_42 )
return V_43 ;
if ( V_32 -> V_44 > V_1 -> V_41 -> V_44 )
return V_43 ;
}
return V_1 -> V_8 . V_9 -> V_45 ( & V_1 -> V_8 , V_32 ) ;
}
static bool F_17 ( struct V_2 * V_3 ,
const struct V_38 * V_32 ,
struct V_38 * V_29 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_41 != NULL ) {
#define F_18 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_18 ( V_42 ) ;
F_18 ( V_46 ) ;
F_18 ( V_47 ) ;
F_18 ( V_48 ) ;
F_18 ( V_44 ) ;
F_18 ( V_49 ) ;
F_18 ( V_50 ) ;
F_18 ( V_51 ) ;
F_18 ( clock ) ;
#undef F_18
}
if ( V_1 -> V_8 . V_9 -> V_52 )
return V_1 -> V_8 . V_9 -> V_52 ( & V_1 -> V_8 , V_32 , V_29 ) ;
return true ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_38 * V_32 ,
struct V_38 * V_29 )
{
struct V_13 * V_8 = V_3 -> V_8 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_53 * V_53 = F_20 ( V_3 -> V_34 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_12 = V_53 -> V_12 ;
T_1 V_54 ;
T_1 V_18 = V_1 -> V_8 . V_18 , V_55 ;
int V_56 = F_21 ( V_12 ) ;
switch ( V_18 ) {
case V_57 :
default:
V_55 = V_58 ;
break;
case V_59 :
V_55 = V_60 ;
break;
case V_61 :
V_55 = V_62 ;
break;
}
V_1 -> V_8 . V_9 -> V_63 ( & V_1 -> V_8 , V_32 , V_29 ) ;
V_54 = F_7 ( V_18 ) &
( V_64 | V_65 ) ;
V_54 |= V_66 | V_67 |
V_68 ;
if ( V_12 == 1 )
V_54 |= V_69 ;
V_54 |= V_70 ;
if ( V_29 -> V_22 & V_24 )
V_54 |= V_23 ;
if ( V_29 -> V_22 & V_27 )
V_54 |= V_26 ;
F_11 ( V_56 , F_7 ( V_56 ) | V_71 ) ;
F_11 ( V_55 ,
( V_29 -> V_42 << V_72 ) |
( V_29 -> V_44 << V_73 ) ) ;
F_11 ( V_18 , V_54 ) ;
}
static enum V_74
F_22 ( struct V_5 * V_6 , bool V_75 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
return V_1 -> V_8 . V_9 -> V_76 ( & V_1 -> V_8 ) ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_14 * V_15 = V_6 -> V_8 -> V_16 ;
F_24 ( V_6 ,
F_25 ( V_15 , V_77 ) ) ;
if ( ! F_26 ( & V_6 -> V_78 ) )
return 1 ;
if ( V_1 -> V_41 != NULL ) {
struct V_38 * V_32 ;
V_32 = F_27 ( V_6 -> V_8 , V_1 -> V_41 ) ;
if ( V_32 ) {
F_28 ( V_6 , V_32 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_29 ( struct V_5 * V_6 )
{
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_8 . V_9 -> V_79 )
V_1 -> V_8 . V_9 -> V_79 ( & V_1 -> V_8 ) ;
F_32 ( V_1 -> V_41 ) ;
F_34 ( V_3 ) ;
}
static struct V_38 *
F_35 ( struct V_5 * V_6 )
{
struct V_13 * V_8 = V_6 -> V_8 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_54 = F_7 ( V_1 -> V_8 . V_18 ) ;
struct V_38 * V_32 = NULL ;
if ( V_54 & V_19 ) {
struct V_33 * V_34 ;
int V_12 = ( V_54 & V_69 ) ? 1 : 0 ;
V_34 = F_36 ( V_8 , V_12 ) ;
if ( V_34 ) {
V_32 = F_37 ( V_8 , V_34 ) ;
if ( V_32 ) {
V_32 -> type |= V_80 ;
if ( V_54 & V_23 )
V_32 -> V_22 |= V_24 ;
if ( V_54 & V_26 )
V_32 -> V_22 |= V_27 ;
}
}
}
return V_32 ;
}
void F_38 ( struct V_13 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_11 * V_11 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_81 ;
int V_82 = V_83 ;
V_1 = F_39 ( sizeof( struct V_1 ) , V_84 ) ;
if ( ! V_1 )
return;
V_7 = F_39 ( sizeof( struct V_7 ) , V_84 ) ;
if ( ! V_7 ) {
F_32 ( V_1 ) ;
return;
}
V_11 = & V_1 -> V_4 ;
F_40 ( V_8 , & V_11 -> V_4 ,
& V_85 , V_82 ) ;
V_11 -> V_86 = F_10 ;
V_11 -> V_87 = F_12 ;
V_11 -> V_10 = F_6 ;
V_11 -> V_88 = F_9 ;
V_7 -> V_10 = F_5 ;
for ( V_81 = 0 ; V_81 < F_41 ( V_89 ) ; V_81 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_90 * V_91 = & V_89 [ V_81 ] ;
struct V_92 * V_93 ;
int V_94 ;
bool V_95 ;
if ( F_42 ( V_91 -> V_94 ) )
V_94 = V_91 -> V_94 ;
else if ( V_91 -> type == V_96 )
V_94 = V_97 ;
else
V_94 = V_98 ;
V_93 = F_25 ( V_15 , V_94 ) ;
V_1 -> V_8 = * V_91 ;
F_43 ( V_93 , true ) ;
V_95 = V_91 -> V_9 -> V_99 ( & V_1 -> V_8 , V_93 ) ;
F_43 ( V_93 , false ) ;
if ( ! V_95 )
continue;
V_11 -> type = V_100 ;
V_11 -> V_101 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_91 -> type ) {
case V_102 :
V_11 -> V_103 = true ;
F_44 ( V_8 , V_6 ,
& V_104 ,
V_105 ) ;
V_82 = V_106 ;
break;
case V_96 :
V_11 -> V_103 = false ;
F_44 ( V_8 , V_6 ,
& V_104 ,
V_107 ) ;
V_82 = V_108 ;
break;
}
F_45 ( V_6 ,
& V_109 ) ;
V_6 -> V_110 . V_111 = V_112 ;
V_6 -> V_113 = false ;
V_6 -> V_114 = false ;
F_46 ( & V_11 -> V_4 ,
& V_115 ) ;
F_47 ( V_7 , V_11 ) ;
if ( V_91 -> type == V_96 ) {
V_1 -> V_41 =
F_35 ( V_6 ) ;
V_1 -> V_116 = true ;
}
F_48 ( V_6 ) ;
return;
}
F_49 ( & V_11 -> V_4 ) ;
F_32 ( V_1 ) ;
F_32 ( V_7 ) ;
}
