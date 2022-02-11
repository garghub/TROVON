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
const struct V_18 * V_7 ,
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
F_17 ( V_9 , V_66 ) ) ;
if ( ! F_18 ( & V_6 -> V_67 ) )
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
if ( V_1 -> V_10 . V_16 -> V_68 )
V_1 -> V_10 . V_16 -> V_68 ( & V_1 -> V_10 ) ;
F_24 ( V_1 -> V_22 ) ;
F_26 ( V_3 ) ;
}
static struct V_18 *
F_27 ( struct V_5 * V_6 )
{
struct V_35 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_39 = F_6 ( V_1 -> V_10 . V_12 ) ;
struct V_18 * V_7 = NULL ;
if ( V_39 & V_15 ) {
struct V_69 * V_37 ;
int V_38 = ( V_39 & V_54 ) ? 1 : 0 ;
V_37 = F_28 ( V_10 , V_38 ) ;
if ( V_37 ) {
V_7 = F_29 ( V_10 , V_37 ) ;
if ( V_7 ) {
V_7 -> type |= V_70 ;
if ( V_39 & V_57 )
V_7 -> V_19 |= V_56 ;
if ( V_39 & V_59 )
V_7 -> V_19 |= V_58 ;
}
}
}
return V_7 ;
}
void F_30 ( struct V_35 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
struct V_71 * V_71 ;
struct V_1 * V_1 ;
struct V_72 * V_72 ;
int V_73 ;
int V_74 = V_75 ;
V_1 = F_31 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_1 )
return;
V_72 = F_31 ( sizeof( struct V_72 ) , V_76 ) ;
if ( ! V_72 ) {
F_24 ( V_1 ) ;
return;
}
V_71 = & V_1 -> V_4 ;
F_32 ( V_10 , & V_71 -> V_4 ,
& V_77 , V_74 ) ;
for ( V_73 = 0 ; V_73 < F_33 ( V_78 ) ; V_73 ++ ) {
struct V_5 * V_6 = & V_72 -> V_4 ;
const struct V_79 * V_80 = & V_78 [ V_73 ] ;
struct V_81 * V_82 ;
int V_83 ;
if ( F_34 ( V_80 -> V_83 ) )
V_83 = V_80 -> V_83 ;
else if ( V_80 -> type == V_84 )
V_83 = V_85 ;
else
V_83 = V_86 ;
V_82 = F_17 ( V_9 , V_83 ) ;
V_1 -> V_10 = * V_80 ;
if ( ! V_80 -> V_16 -> V_87 ( & V_1 -> V_10 , V_82 ) )
continue;
V_71 -> type = V_88 ;
V_71 -> V_89 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_80 -> type ) {
case V_90 :
V_71 -> V_91 =
( 1 << V_92 ) |
( 1 << V_93 ) ;
F_35 ( V_10 , V_6 ,
& V_94 ,
V_95 ) ;
V_74 = V_96 ;
break;
case V_84 :
V_71 -> V_91 =
( 1 << V_97 ) ;
F_35 ( V_10 , V_6 ,
& V_94 ,
V_98 ) ;
V_74 = V_99 ;
break;
}
F_36 ( V_6 ,
& V_100 ) ;
V_6 -> V_101 . V_102 = V_103 ;
V_6 -> V_104 = false ;
V_6 -> V_105 = false ;
F_37 ( & V_71 -> V_4 ,
& V_106 ) ;
F_38 ( V_72 , V_71 ) ;
if ( V_80 -> type == V_84 ) {
V_1 -> V_22 =
F_27 ( V_6 ) ;
V_1 -> V_107 = true ;
}
F_39 ( V_6 ) ;
return;
}
F_40 ( & V_71 -> V_4 ) ;
F_24 ( V_1 ) ;
F_24 ( V_72 ) ;
}
