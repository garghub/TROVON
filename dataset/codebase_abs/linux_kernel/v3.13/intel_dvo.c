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
static int F_17 ( struct V_5 * V_6 ,
struct V_43 * V_38 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_38 -> V_21 & V_44 )
return V_45 ;
if ( V_1 -> V_46 ) {
if ( V_38 -> V_47 > V_1 -> V_46 -> V_47 )
return V_48 ;
if ( V_38 -> V_49 > V_1 -> V_46 -> V_49 )
return V_48 ;
}
return V_1 -> V_8 . V_9 -> V_50 ( & V_1 -> V_8 , V_38 ) ;
}
static bool F_18 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_43 * V_28 = & V_20 -> V_28 ;
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
struct V_12 * V_8 = V_3 -> V_4 . V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
struct V_43 * V_28 = & V_34 -> V_36 . V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = V_34 -> V_11 ;
T_1 V_57 ;
T_1 V_17 = V_1 -> V_8 . V_17 , V_58 ;
switch ( V_17 ) {
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
V_57 = F_7 ( V_17 ) &
( V_65 | V_66 ) ;
V_57 |= V_67 | V_68 |
V_69 ;
if ( V_11 == 1 )
V_57 |= V_70 ;
V_57 |= V_71 ;
if ( V_28 -> V_21 & V_23 )
V_57 |= V_22 ;
if ( V_28 -> V_21 & V_26 )
V_57 |= V_25 ;
F_11 ( V_58 ,
( V_28 -> V_47 << V_72 ) |
( V_28 -> V_49 << V_73 ) ) ;
F_11 ( V_17 , V_57 ) ;
}
static enum V_74
F_22 ( struct V_5 * V_6 , bool V_75 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_23 ( L_1 ,
V_6 -> V_4 . V_76 , F_24 ( V_6 ) ) ;
return V_1 -> V_8 . V_9 -> V_77 ( & V_1 -> V_8 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_6 -> V_8 -> V_15 ;
F_26 ( V_6 ,
F_27 ( V_14 , V_78 ) ) ;
if ( ! F_28 ( & V_6 -> V_79 ) )
return 1 ;
if ( V_1 -> V_46 != NULL ) {
struct V_43 * V_38 ;
V_38 = F_29 ( V_6 -> V_8 , V_1 -> V_46 ) ;
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
static void F_34 ( struct V_80 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_35 ( V_3 ) ) ;
if ( V_1 -> V_8 . V_9 -> V_81 )
V_1 -> V_8 . V_9 -> V_81 ( & V_1 -> V_8 ) ;
F_33 ( V_1 -> V_46 ) ;
F_36 ( V_3 ) ;
}
static struct V_43 *
F_37 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = V_6 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_57 = F_7 ( V_1 -> V_8 . V_17 ) ;
struct V_43 * V_38 = NULL ;
if ( V_57 & V_18 ) {
struct V_39 * V_34 ;
int V_11 = ( V_57 & V_70 ) ? 1 : 0 ;
V_34 = F_38 ( V_8 , V_11 ) ;
if ( V_34 ) {
V_38 = F_39 ( V_8 , V_34 ) ;
if ( V_38 ) {
V_38 -> type |= V_82 ;
if ( V_57 & V_22 )
V_38 -> V_21 |= V_23 ;
if ( V_57 & V_25 )
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
int V_83 ;
int V_84 = V_85 ;
V_1 = F_41 ( sizeof( * V_1 ) , V_86 ) ;
if ( ! V_1 )
return;
V_7 = F_41 ( sizeof( * V_7 ) , V_86 ) ;
if ( ! V_7 ) {
F_33 ( V_1 ) ;
return;
}
V_2 = & V_1 -> V_4 ;
F_42 ( V_8 , & V_2 -> V_4 ,
& V_87 , V_84 ) ;
V_2 -> V_88 = F_10 ;
V_2 -> V_89 = F_12 ;
V_2 -> V_10 = F_6 ;
V_2 -> V_90 = F_9 ;
V_2 -> V_91 = F_18 ;
V_2 -> V_35 = F_21 ;
V_7 -> V_10 = F_5 ;
for ( V_83 = 0 ; V_83 < F_43 ( V_92 ) ; V_83 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_93 * V_94 = & V_92 [ V_83 ] ;
struct V_95 * V_96 ;
int V_97 ;
bool V_98 ;
if ( F_44 ( V_94 -> V_97 ) )
V_97 = V_94 -> V_97 ;
else if ( V_94 -> type == V_99 )
V_97 = V_100 ;
else
V_97 = V_101 ;
V_96 = F_27 ( V_14 , V_97 ) ;
V_1 -> V_8 = * V_94 ;
F_45 ( V_96 , true ) ;
V_98 = V_94 -> V_9 -> V_102 ( & V_1 -> V_8 , V_96 ) ;
F_45 ( V_96 , false ) ;
if ( ! V_98 )
continue;
V_2 -> type = V_103 ;
V_2 -> V_104 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_94 -> type ) {
case V_105 :
V_2 -> V_106 = true ;
F_46 ( V_8 , V_6 ,
& V_107 ,
V_108 ) ;
V_84 = V_109 ;
break;
case V_99 :
V_2 -> V_106 = false ;
F_46 ( V_8 , V_6 ,
& V_107 ,
V_110 ) ;
V_84 = V_111 ;
break;
}
F_47 ( V_6 ,
& V_112 ) ;
V_6 -> V_113 . V_114 = V_115 ;
V_6 -> V_116 = false ;
V_6 -> V_117 = false ;
F_48 ( V_7 , V_2 ) ;
if ( V_94 -> type == V_99 ) {
V_1 -> V_46 =
F_37 ( V_6 ) ;
V_1 -> V_118 = true ;
}
F_49 ( V_6 ) ;
return;
}
F_50 ( & V_2 -> V_4 ) ;
F_33 ( V_1 ) ;
F_33 ( V_7 ) ;
}
