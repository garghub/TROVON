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
#undef F_10
}
if ( V_1 -> V_10 . V_16 -> V_34 )
return V_1 -> V_10 . V_16 -> V_34 ( & V_1 -> V_10 , V_7 , V_27 ) ;
return true ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_18 * V_7 ,
struct V_18 * V_27 )
{
struct V_35 * V_10 = V_3 -> V_10 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_36 * V_36 = F_12 ( V_3 -> V_37 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_38 = V_36 -> V_38 ;
T_1 V_39 ;
T_1 V_12 = V_1 -> V_10 . V_12 , V_40 ;
int V_41 = F_13 ( V_38 ) ;
switch ( V_12 ) {
case V_42 :
default:
V_40 = V_43 ;
break;
case V_44 :
V_40 = V_45 ;
break;
case V_46 :
V_40 = V_47 ;
break;
}
V_1 -> V_10 . V_16 -> V_48 ( & V_1 -> V_10 , V_7 , V_27 ) ;
V_39 = F_6 ( V_12 ) &
( V_49 | V_50 ) ;
V_39 |= V_51 | V_52 |
V_53 ;
if ( V_38 == 1 )
V_39 |= V_54 ;
V_39 |= V_55 ;
if ( V_27 -> V_19 & V_56 )
V_39 |= V_57 ;
if ( V_27 -> V_19 & V_58 )
V_39 |= V_59 ;
F_7 ( V_41 , F_6 ( V_41 ) | V_60 ) ;
F_7 ( V_40 ,
( V_27 -> V_23 << V_61 ) |
( V_27 -> V_25 << V_62 ) ) ;
F_7 ( V_12 , V_39 ) ;
}
static enum V_63
F_14 ( struct V_5 * V_6 , bool V_64 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
return V_1 -> V_10 . V_16 -> V_65 ( & V_1 -> V_10 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 -> V_11 ;
F_16 ( V_6 ,
& V_9 -> V_66 [ V_67 ] . V_68 ) ;
if ( ! F_17 ( & V_6 -> V_69 ) )
return 1 ;
if ( V_1 -> V_22 != NULL ) {
struct V_18 * V_7 ;
V_7 = F_18 ( V_6 -> V_10 , V_1 -> V_22 ) ;
if ( V_7 ) {
F_19 ( V_6 , V_7 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
F_21 ( V_6 ) ;
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_10 . V_16 -> V_70 )
V_1 -> V_10 . V_16 -> V_70 ( & V_1 -> V_10 ) ;
F_23 ( V_1 -> V_22 ) ;
F_25 ( V_3 ) ;
}
static struct V_18 *
F_26 ( struct V_5 * V_6 )
{
struct V_35 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_39 = F_6 ( V_1 -> V_10 . V_12 ) ;
struct V_18 * V_7 = NULL ;
if ( V_39 & V_15 ) {
struct V_71 * V_37 ;
int V_38 = ( V_39 & V_54 ) ? 1 : 0 ;
V_37 = F_27 ( V_10 , V_38 ) ;
if ( V_37 ) {
V_7 = F_28 ( V_10 , V_37 ) ;
if ( V_7 ) {
V_7 -> type |= V_72 ;
if ( V_39 & V_57 )
V_7 -> V_19 |= V_56 ;
if ( V_39 & V_59 )
V_7 -> V_19 |= V_58 ;
}
}
}
return V_7 ;
}
void F_29 ( struct V_35 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_73 * V_73 ;
struct V_1 * V_1 ;
struct V_74 * V_74 ;
int V_75 ;
int V_76 = V_77 ;
V_1 = F_30 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_1 )
return;
V_74 = F_30 ( sizeof( struct V_74 ) , V_78 ) ;
if ( ! V_74 ) {
F_23 ( V_1 ) ;
return;
}
V_73 = & V_1 -> V_4 ;
F_31 ( V_10 , & V_73 -> V_4 ,
& V_79 , V_76 ) ;
for ( V_75 = 0 ; V_75 < F_32 ( V_80 ) ; V_75 ++ ) {
struct V_5 * V_6 = & V_74 -> V_4 ;
const struct V_81 * V_82 = & V_80 [ V_75 ] ;
struct V_83 * V_84 ;
int V_85 ;
if ( V_82 -> V_85 != 0 )
V_85 = V_82 -> V_85 ;
else if ( V_82 -> type == V_86 )
V_85 = V_87 ;
else
V_85 = V_88 ;
V_84 = & V_9 -> V_66 [ V_85 ] . V_68 ;
V_1 -> V_10 = * V_82 ;
if ( ! V_82 -> V_16 -> V_89 ( & V_1 -> V_10 , V_84 ) )
continue;
V_73 -> type = V_90 ;
V_73 -> V_91 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_82 -> type ) {
case V_92 :
V_73 -> V_93 =
( 1 << V_94 ) |
( 1 << V_95 ) ;
F_33 ( V_10 , V_6 ,
& V_96 ,
V_97 ) ;
V_76 = V_98 ;
break;
case V_86 :
V_73 -> V_93 =
( 1 << V_99 ) ;
F_33 ( V_10 , V_6 ,
& V_96 ,
V_100 ) ;
V_76 = V_101 ;
break;
}
F_34 ( V_6 ,
& V_102 ) ;
V_6 -> V_103 . V_104 = V_105 ;
V_6 -> V_106 = false ;
V_6 -> V_107 = false ;
F_35 ( & V_73 -> V_4 ,
& V_108 ) ;
F_36 ( V_74 , V_73 ) ;
if ( V_82 -> type == V_86 ) {
V_1 -> V_22 =
F_26 ( V_6 ) ;
V_1 -> V_109 = true ;
}
F_37 ( V_6 ) ;
return;
}
F_38 ( & V_73 -> V_4 ) ;
F_23 ( V_1 ) ;
F_23 ( V_74 ) ;
}
