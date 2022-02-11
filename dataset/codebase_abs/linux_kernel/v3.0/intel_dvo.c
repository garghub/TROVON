static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
static void F_5 ( struct V_2 * V_3 , int V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_12 = V_1 -> V_10 . V_12 ;
T_1 V_13 = F_6 ( V_12 ) ;
if ( V_7 == V_14 ) {
F_7 ( V_12 , V_13 | V_15 ) ;
F_6 ( V_12 ) ;
V_1 -> V_10 . V_16 -> V_17 ( & V_1 -> V_10 , V_7 ) ;
} else {
V_1 -> V_10 . V_16 -> V_17 ( & V_1 -> V_10 , V_7 ) ;
F_7 ( V_12 , V_13 & ~ V_15 ) ;
F_6 ( V_12 ) ;
}
}
static int F_8 ( struct V_5 * V_6 ,
struct V_18 * V_7 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_7 -> V_19 & V_20 )
return V_21 ;
if ( V_1 -> V_22 ) {
if ( V_7 -> V_23 > V_1 -> V_22 -> V_23 )
return V_24 ;
if ( V_7 -> V_25 > V_1 -> V_22 -> V_25 )
return V_24 ;
}
return V_1 -> V_10 . V_16 -> V_26 ( & V_1 -> V_10 , V_7 ) ;
}
static bool F_9 ( struct V_2 * V_3 ,
struct V_18 * V_7 ,
struct V_18 * V_27 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_22 != NULL ) {
#define F_10 ( T_2 ) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
F_10 ( V_23 ) ;
F_10 ( V_28 ) ;
F_10 ( V_29 ) ;
F_10 ( V_30 ) ;
F_10 ( V_25 ) ;
F_10 ( V_31 ) ;
F_10 ( V_32 ) ;
F_10 ( V_33 ) ;
F_10 ( clock ) ;
F_11 ( V_27 , V_34 ) ;
#undef F_10
}
if ( V_1 -> V_10 . V_16 -> V_35 )
return V_1 -> V_10 . V_16 -> V_35 ( & V_1 -> V_10 , V_7 , V_27 ) ;
return true ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_18 * V_7 ,
struct V_18 * V_27 )
{
struct V_36 * V_10 = V_3 -> V_10 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_37 * V_37 = F_13 ( V_3 -> V_38 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_39 = V_37 -> V_39 ;
T_1 V_40 ;
T_1 V_12 = V_1 -> V_10 . V_12 , V_41 ;
int V_42 = F_14 ( V_39 ) ;
switch ( V_12 ) {
case V_43 :
default:
V_41 = V_44 ;
break;
case V_45 :
V_41 = V_46 ;
break;
case V_47 :
V_41 = V_48 ;
break;
}
V_1 -> V_10 . V_16 -> V_49 ( & V_1 -> V_10 , V_7 , V_27 ) ;
V_40 = F_6 ( V_12 ) &
( V_50 | V_51 ) ;
V_40 |= V_52 | V_53 |
V_54 ;
if ( V_39 == 1 )
V_40 |= V_55 ;
V_40 |= V_56 ;
if ( V_27 -> V_19 & V_57 )
V_40 |= V_58 ;
if ( V_27 -> V_19 & V_59 )
V_40 |= V_60 ;
F_7 ( V_42 , F_6 ( V_42 ) | V_61 ) ;
F_7 ( V_41 ,
( V_27 -> V_23 << V_62 ) |
( V_27 -> V_25 << V_63 ) ) ;
F_7 ( V_12 , V_40 ) ;
}
static enum V_64
F_15 ( struct V_5 * V_6 , bool V_65 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
return V_1 -> V_10 . V_16 -> V_66 ( & V_1 -> V_10 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 -> V_11 ;
F_17 ( V_6 ,
& V_9 -> V_67 [ V_68 ] . V_69 ) ;
if ( ! F_18 ( & V_6 -> V_70 ) )
return 1 ;
if ( V_1 -> V_22 != NULL ) {
struct V_18 * V_7 ;
V_7 = F_19 ( V_6 -> V_10 , V_1 -> V_22 ) ;
if ( V_7 ) {
F_20 ( V_6 , V_7 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_21 ( struct V_5 * V_6 )
{
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_10 . V_16 -> V_71 )
V_1 -> V_10 . V_16 -> V_71 ( & V_1 -> V_10 ) ;
F_24 ( V_1 -> V_22 ) ;
F_26 ( V_3 ) ;
}
static struct V_18 *
F_27 ( struct V_5 * V_6 )
{
struct V_36 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_40 = F_6 ( V_1 -> V_10 . V_12 ) ;
struct V_18 * V_7 = NULL ;
if ( V_40 & V_15 ) {
struct V_72 * V_38 ;
int V_39 = ( V_40 & V_55 ) ? 1 : 0 ;
V_38 = F_28 ( V_10 , V_39 ) ;
if ( V_38 ) {
V_7 = F_29 ( V_10 , V_38 ) ;
if ( V_7 ) {
V_7 -> type |= V_73 ;
if ( V_40 & V_58 )
V_7 -> V_19 |= V_57 ;
if ( V_40 & V_60 )
V_7 -> V_19 |= V_59 ;
}
}
}
return V_7 ;
}
void F_30 ( struct V_36 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_74 * V_74 ;
struct V_1 * V_1 ;
struct V_75 * V_75 ;
int V_76 ;
int V_77 = V_78 ;
V_1 = F_31 ( sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_1 )
return;
V_75 = F_31 ( sizeof( struct V_75 ) , V_79 ) ;
if ( ! V_75 ) {
F_24 ( V_1 ) ;
return;
}
V_74 = & V_1 -> V_4 ;
F_32 ( V_10 , & V_74 -> V_4 ,
& V_80 , V_77 ) ;
for ( V_76 = 0 ; V_76 < F_33 ( V_81 ) ; V_76 ++ ) {
struct V_5 * V_6 = & V_75 -> V_4 ;
const struct V_82 * V_83 = & V_81 [ V_76 ] ;
struct V_84 * V_85 ;
int V_86 ;
if ( V_83 -> V_86 != 0 )
V_86 = V_83 -> V_86 ;
else if ( V_83 -> type == V_87 )
V_86 = V_88 ;
else
V_86 = V_89 ;
V_85 = & V_9 -> V_67 [ V_86 ] . V_69 ;
V_1 -> V_10 = * V_83 ;
if ( ! V_83 -> V_16 -> V_90 ( & V_1 -> V_10 , V_85 ) )
continue;
V_74 -> type = V_91 ;
V_74 -> V_92 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_83 -> type ) {
case V_93 :
V_74 -> V_94 =
( 1 << V_95 ) |
( 1 << V_96 ) ;
F_34 ( V_10 , V_6 ,
& V_97 ,
V_98 ) ;
V_77 = V_99 ;
break;
case V_87 :
V_74 -> V_94 =
( 1 << V_100 ) ;
F_34 ( V_10 , V_6 ,
& V_97 ,
V_101 ) ;
V_77 = V_102 ;
break;
}
F_35 ( V_6 ,
& V_103 ) ;
V_6 -> V_104 . V_105 = V_106 ;
V_6 -> V_107 = false ;
V_6 -> V_108 = false ;
F_36 ( & V_74 -> V_4 ,
& V_109 ) ;
F_37 ( V_75 , V_74 ) ;
if ( V_83 -> type == V_87 ) {
V_1 -> V_22 =
F_27 ( V_6 ) ;
V_1 -> V_110 = true ;
}
F_38 ( V_6 ) ;
return;
}
F_39 ( & V_74 -> V_4 ) ;
F_24 ( V_1 ) ;
F_24 ( V_75 ) ;
}
