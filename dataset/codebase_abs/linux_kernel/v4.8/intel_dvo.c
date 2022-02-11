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
static void F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_13 = V_1 -> V_9 . V_13 ;
T_1 V_30 = F_7 ( V_13 ) ;
V_1 -> V_9 . V_15 -> V_31 ( & V_1 -> V_9 , false ) ;
F_12 ( V_13 , V_30 & ~ V_14 ) ;
F_7 ( V_13 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_6 ( V_3 -> V_4 . V_9 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_32 * V_33 = F_14 ( V_3 -> V_4 . V_33 ) ;
T_2 V_13 = V_1 -> V_9 . V_13 ;
T_1 V_30 = F_7 ( V_13 ) ;
V_1 -> V_9 . V_15 -> V_34 ( & V_1 -> V_9 ,
& V_33 -> V_35 -> V_4 . V_36 ,
& V_33 -> V_35 -> V_4 . V_27 ) ;
F_12 ( V_13 , V_30 | V_14 ) ;
F_7 ( V_13 ) ;
V_1 -> V_9 . V_15 -> V_31 ( & V_1 -> V_9 , true ) ;
}
static enum V_37
F_15 ( struct V_5 * V_6 ,
struct V_38 * V_36 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_38 * V_39 =
F_16 ( V_6 ) -> V_40 . V_39 ;
int V_41 = F_6 ( V_6 -> V_9 ) -> V_42 ;
int V_43 = V_36 -> clock ;
if ( V_36 -> V_20 & V_44 )
return V_45 ;
if ( V_39 ) {
if ( V_36 -> V_46 > V_39 -> V_46 )
return V_47 ;
if ( V_36 -> V_48 > V_39 -> V_48 )
return V_47 ;
V_43 = V_39 -> clock ;
}
if ( V_43 > V_41 )
return V_49 ;
return V_1 -> V_9 . V_15 -> V_50 ( & V_1 -> V_9 , V_36 ) ;
}
static bool F_17 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_38 * V_39 =
V_1 -> V_51 -> V_40 . V_39 ;
struct V_38 * V_27 = & V_19 -> V_4 . V_27 ;
if ( V_39 )
F_18 ( V_39 , V_27 ) ;
return true ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_4 . V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_32 * V_33 = F_14 ( V_3 -> V_4 . V_33 ) ;
const struct V_38 * V_27 = & V_33 -> V_35 -> V_4 . V_27 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_17 = V_33 -> V_17 ;
T_1 V_52 ;
T_2 V_13 = V_1 -> V_9 . V_13 ;
T_2 V_53 = V_1 -> V_9 . V_53 ;
V_52 = F_7 ( V_13 ) &
( V_54 | V_55 ) ;
V_52 |= V_56 | V_57 |
V_58 ;
if ( V_17 == 1 )
V_52 |= V_59 ;
V_52 |= V_60 ;
if ( V_27 -> V_20 & V_22 )
V_52 |= V_21 ;
if ( V_27 -> V_20 & V_25 )
V_52 |= V_24 ;
F_12 ( V_53 ,
( V_27 -> V_61 << V_62 ) |
( V_27 -> V_63 << V_64 ) ) ;
F_12 ( V_13 , V_52 ) ;
}
static enum V_65
F_20 ( struct V_5 * V_6 , bool V_66 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_21 ( L_1 ,
V_6 -> V_4 . V_67 , V_6 -> V_68 ) ;
return V_1 -> V_9 . V_15 -> V_69 ( & V_1 -> V_9 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_9 ) ;
const struct V_38 * V_39 =
F_16 ( V_6 ) -> V_40 . V_39 ;
F_23 ( V_6 ,
F_24 ( V_11 , V_70 ) ) ;
if ( ! F_25 ( & V_6 -> V_71 ) )
return 1 ;
if ( V_39 ) {
struct V_38 * V_36 ;
V_36 = F_26 ( V_6 -> V_9 , V_39 ) ;
if ( V_36 ) {
F_27 ( V_6 , V_36 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_30 ( & F_16 ( V_6 ) -> V_40 ) ;
F_31 ( V_6 ) ;
}
static void F_32 ( struct V_72 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_33 ( V_3 ) ) ;
if ( V_1 -> V_9 . V_15 -> V_73 )
V_1 -> V_9 . V_15 -> V_73 ( & V_1 -> V_9 ) ;
F_34 ( V_3 ) ;
}
static struct V_38 *
F_35 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
T_3 V_52 = F_7 ( V_1 -> V_9 . V_13 ) ;
struct V_38 * V_36 = NULL ;
if ( V_52 & V_14 ) {
struct V_74 * V_33 ;
int V_17 = ( V_52 & V_59 ) ? 1 : 0 ;
V_33 = F_36 ( V_9 , V_17 ) ;
if ( V_33 ) {
V_36 = F_37 ( V_9 , V_33 ) ;
if ( V_36 ) {
V_36 -> type |= V_75 ;
if ( V_52 & V_21 )
V_36 -> V_20 |= V_22 ;
if ( V_52 & V_24 )
V_36 -> V_20 |= V_25 ;
}
}
}
return V_36 ;
}
static char F_38 ( T_2 V_13 )
{
if ( F_39 ( V_13 , V_76 ) )
return 'A' ;
else if ( F_39 ( V_13 , V_77 ) )
return 'B' ;
else if ( F_39 ( V_13 , V_78 ) )
return 'C' ;
else
return '?' ;
}
void F_40 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_79 ;
int V_80 = V_81 ;
V_1 = F_41 ( sizeof( * V_1 ) , V_82 ) ;
if ( ! V_1 )
return;
V_7 = F_42 () ;
if ( ! V_7 ) {
F_31 ( V_1 ) ;
return;
}
V_1 -> V_51 = V_7 ;
V_2 = & V_1 -> V_4 ;
V_2 -> V_83 = F_11 ;
V_2 -> V_84 = F_13 ;
V_2 -> V_16 = F_8 ;
V_2 -> V_85 = F_10 ;
V_2 -> V_86 = F_17 ;
V_2 -> V_87 = F_19 ;
V_7 -> V_16 = F_5 ;
for ( V_79 = 0 ; V_79 < F_43 ( V_88 ) ; V_79 ++ ) {
struct V_5 * V_6 = & V_7 -> V_4 ;
const struct V_89 * V_90 = & V_88 [ V_79 ] ;
struct V_91 * V_92 ;
int V_93 ;
bool V_94 ;
enum V_17 V_17 ;
T_3 V_95 [ V_96 ] ;
if ( F_44 ( V_11 , V_90 -> V_93 ) )
V_93 = V_90 -> V_93 ;
else if ( V_90 -> type == V_97 )
V_93 = V_98 ;
else
V_93 = V_99 ;
V_92 = F_24 ( V_11 , V_93 ) ;
V_1 -> V_9 = * V_90 ;
F_45 ( V_92 , true ) ;
F_46 (dev_priv, pipe) {
V_95 [ V_17 ] = F_7 ( F_47 ( V_17 ) ) ;
F_12 ( F_47 ( V_17 ) , V_95 [ V_17 ] | V_100 ) ;
}
V_94 = V_90 -> V_15 -> V_101 ( & V_1 -> V_9 , V_92 ) ;
F_46 (dev_priv, pipe) {
F_12 ( F_47 ( V_17 ) , V_95 [ V_17 ] ) ;
}
F_45 ( V_92 , false ) ;
if ( ! V_94 )
continue;
F_48 ( V_9 , & V_2 -> V_4 ,
& V_102 , V_80 ,
L_2 , F_38 ( V_90 -> V_13 ) ) ;
V_2 -> type = V_103 ;
V_2 -> V_104 = ( 1 << 0 ) | ( 1 << 1 ) ;
switch ( V_90 -> type ) {
case V_105 :
V_2 -> V_106 = ( 1 << V_107 ) |
( 1 << V_103 ) ;
F_49 ( V_9 , V_6 ,
& V_108 ,
V_109 ) ;
V_80 = V_110 ;
break;
case V_97 :
V_2 -> V_106 = 0 ;
F_49 ( V_9 , V_6 ,
& V_108 ,
V_111 ) ;
V_80 = V_112 ;
break;
}
F_50 ( V_6 ,
& V_113 ) ;
V_6 -> V_114 . V_115 = V_116 ;
V_6 -> V_117 = false ;
V_6 -> V_118 = false ;
F_51 ( V_7 , V_2 ) ;
if ( V_90 -> type == V_97 ) {
F_52 ( & V_7 -> V_40 ,
F_35 ( V_6 ) ,
NULL ) ;
V_1 -> V_119 = true ;
}
return;
}
F_31 ( V_1 ) ;
F_31 ( V_7 ) ;
}
