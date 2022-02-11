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
static void F_9 ( struct V_11 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_4 . V_8 -> V_16 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 = V_1 -> V_8 . V_18 ;
T_1 V_20 = F_7 ( V_18 ) ;
V_1 -> V_8 . V_9 -> V_21 ( & V_1 -> V_8 , false ) ;
F_10 ( V_18 , V_20 & ~ V_19 ) ;
F_7 ( V_18 ) ;
}
static void F_11 ( struct V_11 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_4 . V_8 -> V_16 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 = V_1 -> V_8 . V_18 ;
T_1 V_20 = F_7 ( V_18 ) ;
F_10 ( V_18 , V_20 | V_19 ) ;
F_7 ( V_18 ) ;
V_1 -> V_8 . V_9 -> V_21 ( & V_1 -> V_8 , true ) ;
}
static void F_12 ( struct V_5 * V_6 , int V_22 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_23 * V_24 ;
if ( V_22 != V_25 )
V_22 = V_26 ;
if ( V_22 == V_6 -> V_21 )
return;
V_6 -> V_21 = V_22 ;
V_24 = V_1 -> V_4 . V_4 . V_24 ;
if ( ! V_24 ) {
V_1 -> V_4 . V_27 = false ;
return;
}
if ( V_22 == V_25 ) {
V_1 -> V_4 . V_27 = true ;
F_13 ( V_24 ) ;
V_1 -> V_8 . V_9 -> V_21 ( & V_1 -> V_8 , true ) ;
} else {
V_1 -> V_8 . V_9 -> V_21 ( & V_1 -> V_8 , false ) ;
V_1 -> V_4 . V_27 = false ;
F_13 ( V_24 ) ;
}
F_14 ( V_6 -> V_8 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_28 * V_22 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_22 -> V_29 & V_30 )
return V_31 ;
if ( V_1 -> V_32 ) {
if ( V_22 -> V_33 > V_1 -> V_32 -> V_33 )
return V_34 ;
if ( V_22 -> V_35 > V_1 -> V_32 -> V_35 )
return V_34 ;
}
return V_1 -> V_8 . V_9 -> V_36 ( & V_1 -> V_8 , V_22 ) ;
}
static bool F_16 ( struct V_2 * V_3 ,
const struct V_28 * V_22 ,
struct V_28 * V_37 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_32 != NULL ) {
#define F_17 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_17 ( V_33 ) ;
F_17 ( V_38 ) ;
F_17 ( V_39 ) ;
F_17 ( V_40 ) ;
F_17 ( V_35 ) ;
F_17 ( V_41 ) ;
F_17 ( V_42 ) ;
F_17 ( V_43 ) ;
F_17 ( clock ) ;
#undef F_17
}
if ( V_1 -> V_8 . V_9 -> V_44 )
return V_1 -> V_8 . V_9 -> V_44 ( & V_1 -> V_8 , V_22 , V_37 ) ;
return true ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_28 * V_22 ,
struct V_28 * V_37 )
{
struct V_13 * V_8 = V_3 -> V_8 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_45 * V_45 = F_19 ( V_3 -> V_24 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_12 = V_45 -> V_12 ;
T_1 V_46 ;
T_1 V_18 = V_1 -> V_8 . V_18 , V_47 ;
int V_48 = F_20 ( V_12 ) ;
switch ( V_18 ) {
case V_49 :
default:
V_47 = V_50 ;
break;
case V_51 :
V_47 = V_52 ;
break;
case V_53 :
V_47 = V_54 ;
break;
}
V_1 -> V_8 . V_9 -> V_55 ( & V_1 -> V_8 , V_22 , V_37 ) ;
V_46 = F_7 ( V_18 ) &
( V_56 | V_57 ) ;
V_46 |= V_58 | V_59 |
V_60 ;
if ( V_12 == 1 )
V_46 |= V_61 ;
V_46 |= V_62 ;
if ( V_37 -> V_29 & V_63 )
V_46 |= V_64 ;
if ( V_37 -> V_29 & V_65 )
V_46 |= V_66 ;
F_10 ( V_48 , F_7 ( V_48 ) | V_67 ) ;
F_10 ( V_47 ,
( V_37 -> V_33 << V_68 ) |
( V_37 -> V_35 << V_69 ) ) ;
F_10 ( V_18 , V_46 ) ;
}
static enum V_70
F_21 ( struct V_5 * V_6 , bool V_71 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
return V_1 -> V_8 . V_9 -> V_72 ( & V_1 -> V_8 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_14 * V_15 = V_6 -> V_8 -> V_16 ;
F_23 ( V_6 ,
F_24 ( V_15 , V_73 ) ) ;
if ( ! F_25 ( & V_6 -> V_74 ) )
return 1 ;
if ( V_1 -> V_32 != NULL ) {
struct V_28 * V_22 ;
V_22 = F_26 ( V_6 -> V_8 , V_1 -> V_32 ) ;
if ( V_22 ) {
F_27 ( V_6 , V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_8 . V_9 -> V_75 )
V_1 -> V_8 . V_9 -> V_75 ( & V_1 -> V_8 ) ;
F_31 ( V_1 -> V_32 ) ;
F_33 ( V_3 ) ;
}
static struct V_28 *
F_34 ( struct V_5 * V_6 )
{
struct V_13 * V_8 = V_6 -> V_8 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_46 = F_7 ( V_1 -> V_8 . V_18 ) ;
struct V_28 * V_22 = NULL ;
if ( V_46 & V_19 ) {
struct V_23 * V_24 ;
int V_12 = ( V_46 & V_61 ) ? 1 : 0 ;
V_24 = F_35 ( V_8 , V_12 ) ;
if ( V_24 ) {
V_22 = F_36 ( V_8 , V_24 ) ;
if ( V_22 ) {
V_22 -> type |= V_76 ;
if ( V_46 & V_64 )
V_22 -> V_29 |= V_63 ;
if ( V_46 & V_66 )
V_22 -> V_29 |= V_65 ;
}
}
}
return V_22 ;
}
void F_37 ( struct V_13 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_11 * V_11 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_77 ;
int V_78 = V_79 ;
V_1 = F_38 ( sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_1 )
return;
V_7 = F_38 ( sizeof( struct V_7 ) , V_80 ) ;
if ( ! V_7 ) {
F_31 ( V_1 ) ;
return;
}
V_11 = & V_1 -> V_4 ;
F_39 ( V_8 , & V_11 -> V_4 ,
& V_81 , V_78 ) ;
V_11 -> V_82 = F_9 ;
V_11 -> V_83 = F_11 ;
V_11 -> V_10 = F_6 ;
V_7 -> V_10 = F_5 ;
for ( V_77 = 0 ; V_77 < F_40 ( V_84 ) ; V_77 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_85 * V_86 = & V_84 [ V_77 ] ;
struct V_87 * V_88 ;
int V_89 ;
if ( F_41 ( V_86 -> V_89 ) )
V_89 = V_86 -> V_89 ;
else if ( V_86 -> type == V_90 )
V_89 = V_91 ;
else
V_89 = V_92 ;
V_88 = F_24 ( V_15 , V_89 ) ;
V_1 -> V_8 = * V_86 ;
if ( ! V_86 -> V_9 -> V_93 ( & V_1 -> V_8 , V_88 ) )
continue;
V_11 -> type = V_94 ;
V_11 -> V_95 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_86 -> type ) {
case V_96 :
V_11 -> V_97 = true ;
F_42 ( V_8 , V_6 ,
& V_98 ,
V_99 ) ;
V_78 = V_100 ;
break;
case V_90 :
V_11 -> V_97 = false ;
F_42 ( V_8 , V_6 ,
& V_98 ,
V_101 ) ;
V_78 = V_102 ;
break;
}
F_43 ( V_6 ,
& V_103 ) ;
V_6 -> V_104 . V_105 = V_106 ;
V_6 -> V_107 = false ;
V_6 -> V_108 = false ;
F_44 ( & V_11 -> V_4 ,
& V_109 ) ;
F_45 ( V_7 , V_11 ) ;
if ( V_86 -> type == V_90 ) {
V_1 -> V_32 =
F_34 ( V_6 ) ;
V_1 -> V_110 = true ;
}
F_46 ( V_6 ) ;
return;
}
F_47 ( & V_11 -> V_4 ) ;
F_31 ( V_1 ) ;
F_31 ( V_7 ) ;
}
