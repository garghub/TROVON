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
const struct V_39 * V_40 =
F_15 ( V_6 ) -> V_41 . V_40 ;
int V_42 = F_16 ( V_6 -> V_9 ) -> V_43 ;
int V_44 = V_37 -> clock ;
if ( V_37 -> V_21 & V_45 )
return V_46 ;
if ( V_40 ) {
if ( V_37 -> V_47 > V_40 -> V_47 )
return V_48 ;
if ( V_37 -> V_49 > V_40 -> V_49 )
return V_48 ;
V_44 = V_40 -> clock ;
}
if ( V_44 > V_42 )
return V_50 ;
return V_1 -> V_9 . V_16 -> V_51 ( & V_1 -> V_9 , V_37 ) ;
}
static bool F_17 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_39 * V_40 =
V_1 -> V_52 -> V_41 . V_40 ;
struct V_39 * V_28 = & V_20 -> V_4 . V_28 ;
if ( V_40 )
F_18 ( V_40 , V_28 ) ;
return true ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_33 * V_34 = F_13 ( V_3 -> V_4 . V_34 ) ;
const struct V_39 * V_28 = & V_34 -> V_36 -> V_4 . V_28 ;
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
( V_28 -> V_68 << V_69 ) |
( V_28 -> V_70 << V_71 ) ) ;
F_11 ( V_14 , V_53 ) ;
}
static enum V_72
F_20 ( struct V_5 * V_6 , bool V_73 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_21 ( L_1 ,
V_6 -> V_4 . V_74 , V_6 -> V_75 ) ;
return V_1 -> V_9 . V_16 -> V_76 ( & V_1 -> V_9 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_9 -> V_12 ;
const struct V_39 * V_40 =
F_15 ( V_6 ) -> V_41 . V_40 ;
F_23 ( V_6 ,
F_24 ( V_11 , V_77 ) ) ;
if ( ! F_25 ( & V_6 -> V_78 ) )
return 1 ;
if ( V_40 ) {
struct V_39 * V_37 ;
V_37 = F_26 ( V_6 -> V_9 , V_40 ) ;
if ( V_37 ) {
F_27 ( V_6 , V_37 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_30 ( & F_15 ( V_6 ) -> V_41 ) ;
F_31 ( V_6 ) ;
}
static void F_32 ( struct V_79 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_33 ( V_3 ) ) ;
if ( V_1 -> V_9 . V_16 -> V_80 )
V_1 -> V_9 . V_16 -> V_80 ( & V_1 -> V_9 ) ;
F_34 ( V_3 ) ;
}
static struct V_39 *
F_35 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_2 V_53 = F_6 ( V_1 -> V_9 . V_14 ) ;
struct V_39 * V_37 = NULL ;
if ( V_53 & V_15 ) {
struct V_81 * V_34 ;
int V_18 = ( V_53 & V_66 ) ? 1 : 0 ;
V_34 = F_36 ( V_9 , V_18 ) ;
if ( V_34 ) {
V_37 = F_37 ( V_9 , V_34 ) ;
if ( V_37 ) {
V_37 -> type |= V_82 ;
if ( V_53 & V_22 )
V_37 -> V_21 |= V_23 ;
if ( V_53 & V_25 )
V_37 -> V_21 |= V_26 ;
}
}
}
return V_37 ;
}
void F_38 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_83 ;
int V_84 = V_85 ;
V_1 = F_39 ( sizeof( * V_1 ) , V_86 ) ;
if ( ! V_1 )
return;
V_7 = F_40 () ;
if ( ! V_7 ) {
F_31 ( V_1 ) ;
return;
}
V_1 -> V_52 = V_7 ;
V_2 = & V_1 -> V_4 ;
F_41 ( V_9 , & V_2 -> V_4 ,
& V_87 , V_84 ) ;
V_2 -> V_88 = F_10 ;
V_2 -> V_89 = F_12 ;
V_2 -> V_17 = F_7 ;
V_2 -> V_90 = F_9 ;
V_2 -> V_91 = F_17 ;
V_2 -> V_92 = F_19 ;
V_7 -> V_17 = F_5 ;
V_7 -> V_93 = V_94 ;
for ( V_83 = 0 ; V_83 < F_42 ( V_95 ) ; V_83 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_96 * V_97 = & V_95 [ V_83 ] ;
struct V_98 * V_99 ;
int V_100 ;
bool V_101 ;
enum V_18 V_18 ;
T_2 V_102 [ V_103 ] ;
if ( F_43 ( V_11 , V_97 -> V_100 ) )
V_100 = V_97 -> V_100 ;
else if ( V_97 -> type == V_104 )
V_100 = V_105 ;
else
V_100 = V_106 ;
V_99 = F_24 ( V_11 , V_100 ) ;
V_1 -> V_9 = * V_97 ;
F_44 ( V_99 , true ) ;
F_45 (dev_priv, pipe) {
V_102 [ V_18 ] = F_6 ( F_46 ( V_18 ) ) ;
F_11 ( F_46 ( V_18 ) , V_102 [ V_18 ] | V_107 ) ;
}
V_101 = V_97 -> V_16 -> V_108 ( & V_1 -> V_9 , V_99 ) ;
F_45 (dev_priv, pipe) {
F_11 ( F_46 ( V_18 ) , V_102 [ V_18 ] ) ;
}
F_44 ( V_99 , false ) ;
if ( ! V_101 )
continue;
V_2 -> type = V_109 ;
V_2 -> V_110 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_97 -> type ) {
case V_111 :
V_2 -> V_112 = ( 1 << V_113 ) |
( 1 << V_109 ) ;
F_47 ( V_9 , V_6 ,
& V_114 ,
V_115 ) ;
V_84 = V_116 ;
break;
case V_104 :
V_2 -> V_112 = 0 ;
F_47 ( V_9 , V_6 ,
& V_114 ,
V_117 ) ;
V_84 = V_118 ;
break;
}
F_48 ( V_6 ,
& V_119 ) ;
V_6 -> V_120 . V_121 = V_122 ;
V_6 -> V_123 = false ;
V_6 -> V_124 = false ;
F_49 ( V_7 , V_2 ) ;
if ( V_97 -> type == V_104 ) {
F_50 ( & V_7 -> V_41 ,
F_35 ( V_6 ) ,
NULL ) ;
V_1 -> V_125 = true ;
}
F_51 ( V_6 ) ;
return;
}
F_52 ( & V_2 -> V_4 ) ;
F_31 ( V_1 ) ;
F_31 ( V_7 ) ;
}
