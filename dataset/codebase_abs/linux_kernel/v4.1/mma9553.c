static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
return ( V_1 & V_2 ) >> ( F_2 ( V_2 ) - 1 ) ;
}
static T_2 F_3 ( T_2 V_3 , T_2 V_1 , T_2 V_2 )
{
return ( V_3 & ~ V_2 ) | ( V_1 << ( F_2 ( V_2 ) - 1 ) ) ;
}
static enum V_4 F_4 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
default:
return V_16 ;
}
}
static void F_5 ( struct V_17 * V_18 )
{
int V_19 ;
V_18 -> V_20 = V_21 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_20 ; V_19 ++ ) {
V_18 -> V_22 [ V_19 ] . V_23 = & V_24 [ V_19 ] ;
V_18 -> V_22 [ V_19 ] . V_25 = false ;
}
}
static struct V_26 * F_6 ( struct V_17 * V_18 ,
enum V_27 type ,
enum V_4 V_28 ,
enum V_29 V_30 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_20 ; V_19 ++ )
if ( V_18 -> V_22 [ V_19 ] . V_23 -> type == type &&
V_18 -> V_22 [ V_19 ] . V_23 -> V_28 == V_28 &&
V_18 -> V_22 [ V_19 ] . V_23 -> V_30 == V_30 )
return & V_18 -> V_22 [ V_19 ] ;
return NULL ;
}
static bool F_7 ( struct V_17 * V_18 ,
bool V_31 ,
enum V_27 type )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_20 ; V_19 ++ )
if ( ( V_31 && V_18 -> V_22 [ V_19 ] . V_23 -> type == type &&
V_18 -> V_22 [ V_19 ] . V_25 ) ||
( ! V_31 && V_18 -> V_22 [ V_19 ] . V_25 ) )
return true ;
return false ;
}
static int F_8 ( struct V_17 * V_18 , T_2 V_32 ,
T_2 * V_33 , T_2 V_1 , T_2 V_2 )
{
int V_34 , V_35 ;
T_2 V_36 , V_37 ;
V_36 = * V_33 ;
if ( V_1 == F_1 ( V_36 , V_2 ) )
return 0 ;
V_36 = F_3 ( V_36 , V_1 , V_2 ) ;
V_34 = F_9 ( V_18 -> V_38 , V_39 ,
V_32 , V_36 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_1 , V_32 ) ;
return V_34 ;
}
* V_33 = V_36 ;
V_37 = F_3 ( V_18 -> V_41 . V_37 , 1 ,
V_42 ) ;
V_34 = F_9 ( V_18 -> V_38 , V_39 ,
V_43 , V_37 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_1 ,
V_43 ) ;
return V_34 ;
}
V_35 = V_44 ;
do {
F_11 ( V_45 ) ;
V_34 = F_12 ( V_18 -> V_38 ,
V_39 ,
V_43 ,
& V_37 ) ;
if ( V_34 < 0 )
return V_34 ;
} while ( F_1 ( V_37 , V_42 ) &&
-- V_35 > 0 );
return 0 ;
}
static int F_13 ( struct V_17 * V_18 ,
T_1 * V_6 , T_2 * V_46 )
{
T_2 V_47 [ 2 ] ;
int V_34 ;
V_34 = F_14 ( V_18 -> V_38 , V_39 ,
V_48 , sizeof( V_49 ) , V_47 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_2 ) ;
return V_34 ;
}
* V_6 = F_1 ( V_47 [ 0 ] , V_50 ) ;
* V_46 = V_47 [ 1 ] ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
T_1 V_51 = 0 , V_52 = V_39 ;
int V_34 ;
struct V_26 * V_53 ;
bool V_54 ;
V_54 =
F_7 ( V_18 , true , V_55 ) ;
V_53 =
F_6 ( V_18 , V_56 , V_16 , V_57 ) ;
if ( V_54 && V_53 -> V_25 )
V_51 = F_16 ( V_58 ) ;
else if ( V_53 -> V_25 )
V_51 = F_16 ( V_59 ) ;
else if ( V_54 )
V_51 = F_16 ( V_60 ) ;
else
V_52 = V_61 ;
if ( V_18 -> V_62 == V_51 )
return 0 ;
if ( V_54 || V_53 -> V_25 )
F_13 ( V_18 , & V_18 -> V_6 ,
& V_18 -> V_46 ) ;
V_34 = F_17 ( V_18 -> V_38 ,
V_63 ,
V_52 , V_51 , V_64 ) ;
if ( V_34 < 0 )
return V_34 ;
V_18 -> V_62 = V_51 ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
int V_34 ;
V_34 = F_19 ( V_18 -> V_38 ) ;
if ( V_34 )
return V_34 ;
V_34 =
F_20 ( V_18 -> V_38 , V_39 ,
V_65 ,
sizeof( V_18 -> V_41 ) , ( T_2 * ) & V_18 -> V_41 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_3 ) ;
return V_34 ;
}
V_18 -> V_62 = - 1 ;
V_34 = F_15 ( V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_21 ( V_18 -> V_38 , V_66 ) ;
if ( V_34 < 0 )
return V_34 ;
V_18 -> V_41 . V_67 = V_68 ;
V_18 -> V_41 . V_69 = V_70 ;
V_18 -> V_41 . V_71 = V_72 ;
V_18 -> V_41 . V_37 =
F_3 ( V_18 -> V_41 . V_37 , 1 , V_42 ) ;
V_18 -> V_41 . V_37 = F_3 ( V_18 -> V_41 . V_37 , 1 ,
V_73 ) ;
V_34 =
F_22 ( V_18 -> V_38 , V_39 ,
V_65 ,
sizeof( V_18 -> V_41 ) , ( T_2 * ) & V_18 -> V_41 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_4 ) ;
return V_34 ;
}
return F_23 ( V_18 -> V_38 , true ) ;
}
static int F_24 ( struct V_74 * V_75 ,
struct V_76 const * V_77 ,
int * V_1 , int * V_78 , long V_2 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 ;
T_2 V_79 ;
T_1 V_6 ;
bool V_80 ;
switch ( V_2 ) {
case V_81 :
switch ( V_77 -> type ) {
case V_56 :
V_80 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_82 ;
if ( ! V_80 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_83 ;
}
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_85 ,
& V_79 ) ;
F_28 ( & V_18 -> V_84 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_79 ;
return V_86 ;
case V_87 :
V_80 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_82 ;
if ( ! V_80 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_83 ;
}
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_88 ,
& V_79 ) ;
F_28 ( & V_18 -> V_84 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_79 ;
return V_86 ;
case V_55 :
V_80 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_82 ;
if ( ! V_80 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_83 ;
}
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_48 ,
& V_79 ) ;
F_28 ( & V_18 -> V_84 ) ;
if ( V_34 < 0 )
return V_34 ;
V_6 =
F_1 ( V_79 , V_50 ) ;
if ( V_77 -> V_89 == F_4 ( V_6 ) )
* V_1 = 100 ;
else
* V_1 = 0 ;
return V_86 ;
default:
return - V_83 ;
}
case V_90 :
switch ( V_77 -> type ) {
case V_91 :
if ( V_77 -> V_89 != V_92 )
return - V_83 ;
V_80 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_82 ;
if ( ! V_80 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_83 ;
}
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_93 , & V_79 ) ;
F_28 ( & V_18 -> V_84 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_79 ;
return V_86 ;
case V_94 :
V_80 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_82 ;
if ( ! V_80 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_83 ;
}
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_95 ,
& V_79 ) ;
F_28 ( & V_18 -> V_84 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_79 ;
return V_86 ;
case V_96 :
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_29 ( V_18 -> V_38 ,
V_77 , V_1 , V_78 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
default:
return - V_83 ;
}
case V_97 :
switch ( V_77 -> type ) {
case V_91 :
if ( V_77 -> V_89 != V_92 )
return - V_83 ;
* V_1 = 0 ;
* V_78 = 277 ;
return V_98 ;
case V_94 :
* V_1 = 4184 ;
return V_86 ;
case V_96 :
return F_30 ( V_1 , V_78 ) ;
default:
return - V_83 ;
}
case V_99 :
* V_1 = V_18 -> V_82 ;
return V_86 ;
case V_100 :
V_79 = F_1 ( V_18 -> V_41 . V_101 ,
V_102 ) ;
* V_1 = V_79 / 100 ;
* V_78 = ( V_79 % 100 ) * 10000 ;
return V_98 ;
case V_103 :
* V_1 = F_1 ( V_18 -> V_41 . V_101 ,
V_104 ) ;
return V_86 ;
case V_105 :
switch ( V_77 -> type ) {
case V_56 :
* V_1 = F_1 ( V_18 -> V_41 . V_106 ,
V_107 ) ;
return V_86 ;
default:
return - V_83 ;
}
case V_108 :
switch ( V_77 -> type ) {
case V_56 :
* V_1 = F_1 ( V_18 -> V_41 . V_106 ,
V_109 ) ;
return V_86 ;
default:
return - V_83 ;
}
case V_110 :
switch ( V_77 -> type ) {
case V_91 :
if ( V_77 -> V_89 != V_92 )
return - V_83 ;
* V_1 = F_1 ( V_18 -> V_41 . V_111 ,
V_112 ) ;
return V_86 ;
default:
return - V_83 ;
}
default:
return - V_83 ;
}
}
static int F_31 ( struct V_74 * V_75 ,
struct V_76 const * V_77 ,
int V_1 , int V_78 , long V_2 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 , V_79 ;
switch ( V_2 ) {
case V_99 :
if ( V_18 -> V_82 == ! ! V_1 )
return 0 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_32 ( V_18 -> V_38 , V_1 ) ;
if ( V_34 < 0 ) {
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
}
V_18 -> V_82 = V_1 ;
F_28 ( & V_18 -> V_84 ) ;
return 0 ;
case V_100 :
V_79 = V_1 * 100 + V_78 / 10000 ;
if ( V_79 < 0 || V_79 > 255 )
return - V_83 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 ,
V_113 ,
& V_18 -> V_41 . V_101 ,
V_79 , V_102 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
case V_103 :
if ( V_1 < 0 || V_1 > 255 )
return - V_83 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 ,
V_113 ,
& V_18 -> V_41 . V_101 ,
V_1 , V_104 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
case V_105 :
switch ( V_77 -> type ) {
case V_56 :
if ( V_1 < 0 )
return - V_83 ;
if ( V_1 > 6 )
V_1 = 6 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 , V_114 ,
& V_18 -> V_41 . V_106 , V_1 ,
V_107 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
default:
return - V_83 ;
}
case V_108 :
switch ( V_77 -> type ) {
case V_56 :
if ( V_1 < 0 || V_1 > 127 )
return - V_83 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 , V_114 ,
& V_18 -> V_41 . V_106 , V_1 ,
V_109 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
default:
return - V_83 ;
}
case V_110 :
switch ( V_77 -> type ) {
case V_91 :
if ( V_77 -> V_89 != V_92 )
return - V_83 ;
if ( V_1 < 2 )
return - V_83 ;
if ( V_1 > 5 )
V_1 = 5 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 ,
V_115 ,
& V_18 -> V_41 . V_111 , V_1 ,
V_112 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
default:
return - V_83 ;
}
default:
return - V_83 ;
}
}
static int F_33 ( struct V_74 * V_75 ,
const struct V_76 * V_77 ,
enum V_116 type ,
enum V_29 V_30 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
struct V_26 * V_117 ;
V_117 = F_6 ( V_18 , V_77 -> type , V_77 -> V_89 , V_30 ) ;
if ( ! V_117 )
return - V_83 ;
return V_117 -> V_25 ;
}
static int F_34 ( struct V_74 * V_75 ,
const struct V_76 * V_77 ,
enum V_116 type ,
enum V_29 V_30 , int V_118 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
struct V_26 * V_117 ;
int V_34 ;
V_117 = F_6 ( V_18 , V_77 -> type , V_77 -> V_89 , V_30 ) ;
if ( ! V_117 )
return - V_83 ;
if ( V_117 -> V_25 == V_118 )
return 0 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_32 ( V_18 -> V_38 , V_118 ) ;
if ( V_34 < 0 )
goto V_119;
V_117 -> V_25 = V_118 ;
V_34 = F_15 ( V_18 ) ;
if ( V_34 < 0 )
goto V_120;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
V_120:
if ( V_118 ) {
V_117 -> V_25 = false ;
F_32 ( V_18 -> V_38 , false ) ;
}
V_119:
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
}
static int F_35 ( struct V_74 * V_75 ,
const struct V_76 * V_77 ,
enum V_116 type ,
enum V_29 V_30 ,
enum V_121 V_23 ,
int * V_1 , int * V_78 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
* V_78 = 0 ;
switch ( V_23 ) {
case V_122 :
switch ( V_77 -> type ) {
case V_56 :
* V_1 = F_1 ( V_18 -> V_41 . V_111 ,
V_123 ) ;
return V_86 ;
case V_55 :
* V_1 = 50 ;
return V_86 ;
default:
return - V_83 ;
}
case V_124 :
switch ( V_77 -> type ) {
case V_55 :
* V_1 = F_36 ( V_18 -> V_41 . V_125 ) ;
return V_86 ;
default:
return - V_83 ;
}
default:
return - V_83 ;
}
}
static int F_37 ( struct V_74 * V_75 ,
const struct V_76 * V_77 ,
enum V_116 type ,
enum V_29 V_30 ,
enum V_121 V_23 ,
int V_1 , int V_78 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 ;
switch ( V_23 ) {
case V_122 :
switch ( V_77 -> type ) {
case V_56 :
if ( V_1 < 0 || V_1 > 255 )
return - V_83 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 ,
V_115 ,
& V_18 -> V_41 . V_111 , V_1 ,
V_123 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
default:
return - V_83 ;
}
case V_124 :
switch ( V_77 -> type ) {
case V_55 :
if ( V_1 < 0 || V_1 > F_36 (
V_126 ) )
return - V_83 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 , V_127 ,
& V_18 -> V_41 . V_125 ,
F_38
( V_1 ) , V_128 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
default:
return - V_83 ;
}
default:
return - V_83 ;
}
}
static int F_39 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
T_1 V_129 ;
V_129 = F_1 ( V_18 -> V_41 . V_106 , V_130 ) ;
return ! V_129 ;
}
static int F_40 ( struct V_74 * V_75 ,
const struct V_76 * V_77 ,
unsigned int V_131 )
{
struct V_17 * V_18 = F_25 ( V_75 ) ;
T_1 V_129 = ! V_131 ;
int V_34 ;
if ( ( V_131 != 0 ) && ( V_131 != 1 ) )
return - V_83 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_8 ( V_18 , V_114 ,
& V_18 -> V_41 . V_106 , V_129 ,
V_130 ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
}
static T_3 F_41 ( int V_132 , void * V_133 )
{
struct V_74 * V_75 = V_133 ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
V_18 -> V_134 = F_42 () ;
return V_135 ;
}
static T_3 F_43 ( int V_132 , void * V_133 )
{
struct V_74 * V_75 = V_133 ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
T_2 V_46 ;
T_1 V_6 ;
struct V_26 * V_136 , * V_137 , * V_53 ;
int V_34 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_13 ( V_18 , & V_6 , & V_46 ) ;
if ( V_34 < 0 ) {
F_28 ( & V_18 -> V_84 ) ;
return V_138 ;
}
V_137 =
F_6 ( V_18 , V_55 ,
F_4 ( V_18 -> V_6 ) ,
V_139 ) ;
V_136 =
F_6 ( V_18 , V_55 ,
F_4 ( V_6 ) ,
V_140 ) ;
V_53 =
F_6 ( V_18 , V_56 , V_16 , V_57 ) ;
if ( V_53 -> V_25 && ( V_46 != V_18 -> V_46 ) ) {
V_18 -> V_46 = V_46 ;
F_44 ( V_75 ,
F_45 ( V_56 , 0 , V_16 ,
V_57 , V_141 , 0 , 0 , 0 ) ,
V_18 -> V_134 ) ;
}
if ( V_6 != V_18 -> V_6 ) {
V_18 -> V_6 = V_6 ;
if ( V_137 && V_137 -> V_25 )
F_44 ( V_75 ,
F_45 ( V_55 , 0 ,
V_137 -> V_23 -> V_28 ,
V_139 ,
V_142 , 0 , 0 , 0 ) ,
V_18 -> V_134 ) ;
if ( V_136 && V_136 -> V_25 )
F_44 ( V_75 ,
F_45 ( V_55 , 0 ,
V_136 -> V_23 -> V_28 ,
V_140 ,
V_142 , 0 , 0 , 0 ) ,
V_18 -> V_134 ) ;
}
F_28 ( & V_18 -> V_84 ) ;
return V_138 ;
}
static int F_46 ( struct V_143 * V_38 )
{
struct V_144 * V_40 ;
struct V_145 * V_146 ;
int V_34 ;
if ( ! V_38 )
return - V_83 ;
V_40 = & V_38 -> V_40 ;
V_146 = F_47 ( V_40 , V_147 , 0 , V_148 ) ;
if ( F_48 ( V_146 ) ) {
F_10 ( V_40 , L_6 ) ;
return F_49 ( V_146 ) ;
}
V_34 = F_50 ( V_146 ) ;
F_51 ( V_40 , L_7 , F_52 ( V_146 ) , V_34 ) ;
return V_34 ;
}
static const char * F_53 ( struct V_144 * V_40 )
{
const struct V_149 * V_150 ;
V_150 = F_54 ( V_40 -> V_151 -> V_152 , V_40 ) ;
if ( ! V_150 )
return NULL ;
return F_55 ( V_40 ) ;
}
static int F_56 ( struct V_143 * V_38 ,
const struct V_153 * V_150 )
{
struct V_17 * V_18 ;
struct V_74 * V_75 ;
const char * V_154 = NULL ;
int V_34 ;
V_75 = F_57 ( & V_38 -> V_40 , sizeof( * V_18 ) ) ;
if ( ! V_75 )
return - V_155 ;
V_18 = F_25 ( V_75 ) ;
F_58 ( V_38 , V_75 ) ;
V_18 -> V_38 = V_38 ;
if ( V_150 )
V_154 = V_150 -> V_154 ;
else if ( F_59 ( & V_38 -> V_40 ) )
V_154 = F_53 ( & V_38 -> V_40 ) ;
else
return - V_156 ;
F_60 ( & V_18 -> V_84 ) ;
F_5 ( V_18 ) ;
V_34 = F_18 ( V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
V_75 -> V_40 . V_157 = & V_38 -> V_40 ;
V_75 -> V_158 = V_159 ;
V_75 -> V_160 = F_61 ( V_159 ) ;
V_75 -> V_154 = V_154 ;
V_75 -> V_161 = V_162 ;
V_75 -> V_23 = & V_163 ;
if ( V_38 -> V_132 < 0 )
V_38 -> V_132 = F_46 ( V_38 ) ;
if ( V_38 -> V_132 >= 0 ) {
V_34 = F_62 ( & V_38 -> V_40 , V_38 -> V_132 ,
F_41 ,
F_43 ,
V_164 ,
V_165 , V_75 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_38 -> V_40 , L_8 ,
V_38 -> V_132 ) ;
goto V_166;
}
}
V_34 = F_63 ( V_75 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_38 -> V_40 , L_9 ) ;
goto V_166;
}
V_34 = F_64 ( & V_38 -> V_40 ) ;
if ( V_34 < 0 )
goto V_167;
F_65 ( & V_38 -> V_40 ) ;
F_66 ( & V_38 -> V_40 ,
V_168 ) ;
F_67 ( & V_38 -> V_40 ) ;
F_51 ( & V_75 -> V_40 , L_10 , V_154 ) ;
return 0 ;
V_167:
F_68 ( V_75 ) ;
V_166:
F_23 ( V_38 , false ) ;
return V_34 ;
}
static int F_69 ( struct V_143 * V_38 )
{
struct V_74 * V_75 = F_70 ( V_38 ) ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
F_71 ( & V_38 -> V_40 ) ;
F_72 ( & V_38 -> V_40 ) ;
F_73 ( & V_38 -> V_40 ) ;
F_68 ( V_75 ) ;
F_26 ( & V_18 -> V_84 ) ;
F_23 ( V_18 -> V_38 , false ) ;
F_28 ( & V_18 -> V_84 ) ;
return 0 ;
}
static int F_74 ( struct V_144 * V_40 )
{
struct V_74 * V_75 = F_70 ( F_75 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_23 ( V_18 -> V_38 , false ) ;
F_28 ( & V_18 -> V_84 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 , L_11 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_76 ( struct V_144 * V_40 )
{
struct V_74 * V_75 = F_70 ( F_75 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 ;
V_34 = F_23 ( V_18 -> V_38 , true ) ;
if ( V_34 < 0 )
return V_34 ;
F_11 ( V_45 ) ;
return 0 ;
}
static int F_77 ( struct V_144 * V_40 )
{
struct V_74 * V_75 = F_70 ( F_75 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_23 ( V_18 -> V_38 , false ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
}
static int F_78 ( struct V_144 * V_40 )
{
struct V_74 * V_75 = F_70 ( F_75 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_75 ) ;
int V_34 ;
F_26 ( & V_18 -> V_84 ) ;
V_34 = F_23 ( V_18 -> V_38 , true ) ;
F_28 ( & V_18 -> V_84 ) ;
return V_34 ;
}
