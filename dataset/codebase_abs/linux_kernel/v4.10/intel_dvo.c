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
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_1 V_12 ;
V_12 = F_7 ( V_1 -> V_9 . V_13 ) ;
if ( ! ( V_12 & V_14 ) )
return false ;
return V_1 -> V_9 . V_15 -> V_16 ( & V_1 -> V_9 ) ;
}
static bool F_8 ( struct V_2 * V_3 ,
enum V_17 * V_17 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_12 ;
V_12 = F_7 ( V_1 -> V_9 . V_13 ) ;
if ( ! ( V_12 & V_14 ) )
return false ;
* V_17 = F_9 ( V_12 ) ;
return true ;
}
static void F_10 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_12 , V_20 = 0 ;
V_12 = F_7 ( V_1 -> V_9 . V_13 ) ;
if ( V_12 & V_21 )
V_20 |= V_22 ;
else
V_20 |= V_23 ;
if ( V_12 & V_24 )
V_20 |= V_25 ;
else
V_20 |= V_26 ;
V_19 -> V_4 . V_27 . V_20 |= V_20 ;
V_19 -> V_4 . V_27 . V_28 = V_19 -> V_29 ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_18 * V_30 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_13 = V_1 -> V_9 . V_13 ;
T_1 V_33 = F_7 ( V_13 ) ;
V_1 -> V_9 . V_15 -> V_34 ( & V_1 -> V_9 , false ) ;
F_12 ( V_13 , V_33 & ~ V_14 ) ;
F_7 ( V_13 ) ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_31 * V_35 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_13 = V_1 -> V_9 . V_13 ;
T_1 V_33 = F_7 ( V_13 ) ;
V_1 -> V_9 . V_15 -> V_36 ( & V_1 -> V_9 ,
& V_19 -> V_4 . V_37 ,
& V_19 -> V_4 . V_27 ) ;
F_12 ( V_13 , V_33 | V_14 ) ;
F_7 ( V_13 ) ;
V_1 -> V_9 . V_15 -> V_34 ( & V_1 -> V_9 , true ) ;
}
static enum V_38
F_14 ( struct V_5 * V_6 ,
struct V_39 * V_37 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_39 * V_40 =
F_15 ( V_6 ) -> V_41 . V_40 ;
int V_42 = F_6 ( V_6 -> V_9 ) -> V_43 ;
int V_44 = V_37 -> clock ;
if ( V_37 -> V_20 & V_45 )
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
return V_1 -> V_9 . V_15 -> V_51 ( & V_1 -> V_9 , V_37 ) ;
}
static bool F_16 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_31 * V_35 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_39 * V_40 =
V_1 -> V_52 -> V_41 . V_40 ;
struct V_39 * V_27 = & V_19 -> V_4 . V_27 ;
if ( V_40 )
F_17 ( V_40 , V_27 ) ;
return true ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_31 * V_35 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_53 * V_54 = F_19 ( V_19 -> V_4 . V_54 ) ;
const struct V_39 * V_27 = & V_19 -> V_4 . V_27 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_17 = V_54 -> V_17 ;
T_1 V_55 ;
T_2 V_13 = V_1 -> V_9 . V_13 ;
T_2 V_56 = V_1 -> V_9 . V_56 ;
V_55 = F_7 ( V_13 ) &
( V_57 | V_58 ) ;
V_55 |= V_59 | V_60 |
V_61 ;
if ( V_17 == 1 )
V_55 |= V_62 ;
V_55 |= V_63 ;
if ( V_27 -> V_20 & V_22 )
V_55 |= V_21 ;
if ( V_27 -> V_20 & V_25 )
V_55 |= V_24 ;
F_12 ( V_56 ,
( V_27 -> V_64 << V_65 ) |
( V_27 -> V_66 << V_67 ) ) ;
F_12 ( V_13 , V_55 ) ;
}
static enum V_68
F_20 ( struct V_5 * V_6 , bool V_69 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_21 ( L_1 ,
V_6 -> V_4 . V_70 , V_6 -> V_71 ) ;
return V_1 -> V_9 . V_15 -> V_72 ( & V_1 -> V_9 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_9 ) ;
const struct V_39 * V_40 =
F_15 ( V_6 ) -> V_41 . V_40 ;
F_23 ( V_6 ,
F_24 ( V_11 , V_73 ) ) ;
if ( ! F_25 ( & V_6 -> V_74 ) )
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
static void F_32 ( struct V_75 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_33 ( V_3 ) ) ;
if ( V_1 -> V_9 . V_15 -> V_76 )
V_1 -> V_9 . V_15 -> V_76 ( & V_1 -> V_9 ) ;
F_34 ( V_3 ) ;
}
static struct V_39 *
F_35 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_55 = F_7 ( V_1 -> V_9 . V_13 ) ;
struct V_39 * V_37 = NULL ;
if ( V_55 & V_14 ) {
struct V_53 * V_54 ;
int V_17 = ( V_55 & V_62 ) ? 1 : 0 ;
V_54 = F_36 ( V_11 , V_17 ) ;
if ( V_54 ) {
V_37 = F_37 ( V_9 , & V_54 -> V_4 ) ;
if ( V_37 ) {
V_37 -> type |= V_77 ;
if ( V_55 & V_21 )
V_37 -> V_20 |= V_22 ;
if ( V_55 & V_24 )
V_37 -> V_20 |= V_25 ;
}
}
}
return V_37 ;
}
static enum V_78 F_38 ( T_2 V_13 )
{
if ( F_39 ( V_13 , V_79 ) )
return V_80 ;
else if ( F_39 ( V_13 , V_81 ) )
return V_82 ;
else
return V_83 ;
}
void F_40 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_84 ;
int V_85 = V_86 ;
V_1 = F_41 ( sizeof( * V_1 ) , V_87 ) ;
if ( ! V_1 )
return;
V_7 = F_42 () ;
if ( ! V_7 ) {
F_31 ( V_1 ) ;
return;
}
V_1 -> V_52 = V_7 ;
V_2 = & V_1 -> V_4 ;
V_2 -> V_88 = F_11 ;
V_2 -> V_89 = F_13 ;
V_2 -> V_16 = F_8 ;
V_2 -> V_90 = F_10 ;
V_2 -> V_91 = F_16 ;
V_2 -> V_92 = F_18 ;
V_7 -> V_16 = F_5 ;
for ( V_84 = 0 ; V_84 < F_43 ( V_93 ) ; V_84 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_94 * V_95 = & V_93 [ V_84 ] ;
struct V_96 * V_97 ;
int V_98 ;
bool V_99 ;
enum V_17 V_17 ;
T_3 V_100 [ V_101 ] ;
enum V_78 V_78 ;
if ( F_44 ( V_11 , V_95 -> V_98 ) )
V_98 = V_95 -> V_98 ;
else if ( V_95 -> type == V_102 )
V_98 = V_103 ;
else
V_98 = V_104 ;
V_97 = F_24 ( V_11 , V_98 ) ;
V_1 -> V_9 = * V_95 ;
F_45 ( V_97 , true ) ;
F_46 (dev_priv, pipe) {
V_100 [ V_17 ] = F_7 ( F_47 ( V_17 ) ) ;
F_12 ( F_47 ( V_17 ) , V_100 [ V_17 ] | V_105 ) ;
}
V_99 = V_95 -> V_15 -> V_106 ( & V_1 -> V_9 , V_97 ) ;
F_46 (dev_priv, pipe) {
F_12 ( F_47 ( V_17 ) , V_100 [ V_17 ] ) ;
}
F_45 ( V_97 , false ) ;
if ( ! V_99 )
continue;
V_78 = F_38 ( V_95 -> V_13 ) ;
F_48 ( V_9 , & V_2 -> V_4 ,
& V_107 , V_85 ,
L_2 , F_49 ( V_78 ) ) ;
V_2 -> type = V_108 ;
V_2 -> V_78 = V_78 ;
V_2 -> V_109 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_95 -> type ) {
case V_110 :
V_2 -> V_111 = ( 1 << V_112 ) |
( 1 << V_108 ) ;
F_50 ( V_9 , V_6 ,
& V_113 ,
V_114 ) ;
V_85 = V_115 ;
break;
case V_102 :
V_2 -> V_111 = 0 ;
F_50 ( V_9 , V_6 ,
& V_113 ,
V_116 ) ;
V_85 = V_117 ;
break;
}
F_51 ( V_6 ,
& V_118 ) ;
V_6 -> V_119 . V_120 = V_121 ;
V_6 -> V_122 = false ;
V_6 -> V_123 = false ;
F_52 ( V_7 , V_2 ) ;
if ( V_95 -> type == V_102 ) {
F_53 ( & V_7 -> V_41 ,
F_35 ( V_6 ) ,
NULL ) ;
V_1 -> V_124 = true ;
}
return;
}
F_31 ( V_1 ) ;
F_31 ( V_7 ) ;
}
