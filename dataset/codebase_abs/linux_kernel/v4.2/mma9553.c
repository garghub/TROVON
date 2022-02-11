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
if ( V_54 || V_53 -> V_25 ) {
V_34 = F_13 ( V_18 , & V_18 -> V_6 ,
& V_18 -> V_46 ) ;
if ( V_34 < 0 )
return V_34 ;
}
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
V_18 -> V_62 = V_66 ;
V_34 = F_15 ( V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_21 ( V_18 -> V_38 , V_67 ) ;
if ( V_34 < 0 )
return V_34 ;
V_18 -> V_41 . V_68 = V_69 ;
V_18 -> V_41 . V_70 = V_71 ;
V_18 -> V_41 . V_72 = V_73 ;
V_18 -> V_41 . V_37 =
F_3 ( V_18 -> V_41 . V_37 , 1 , V_42 ) ;
V_18 -> V_41 . V_37 = F_3 ( V_18 -> V_41 . V_37 , 1 ,
V_74 ) ;
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
static int F_24 ( struct V_17 * V_18 , T_2 V_32 ,
T_2 * V_75 )
{
bool V_76 ;
int V_34 ;
V_76 = F_7 ( V_18 , false , 0 ) ||
V_18 -> V_77 ;
if ( ! V_76 ) {
F_10 ( & V_18 -> V_38 -> V_40 , L_5 ) ;
return - V_78 ;
}
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_26 ( V_18 -> V_38 , V_39 ,
V_32 , V_75 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
}
static int F_28 ( struct V_80 * V_81 ,
struct V_82 const * V_83 ,
int * V_1 , int * V_84 , long V_2 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 ;
T_2 V_75 ;
T_1 V_6 ;
switch ( V_2 ) {
case V_85 :
switch ( V_83 -> type ) {
case V_56 :
V_34 = F_24 ( V_18 ,
V_86 ,
& V_75 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_75 ;
return V_87 ;
case V_88 :
V_34 = F_24 ( V_18 ,
V_89 ,
& V_75 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_75 ;
return V_87 ;
case V_55 :
V_34 = F_24 ( V_18 ,
V_48 ,
& V_75 ) ;
if ( V_34 < 0 )
return V_34 ;
V_6 =
F_1 ( V_75 , V_50 ) ;
if ( V_83 -> V_90 == F_4 ( V_6 ) )
* V_1 = 100 ;
else
* V_1 = 0 ;
return V_87 ;
default:
return - V_78 ;
}
case V_91 :
switch ( V_83 -> type ) {
case V_92 :
if ( V_83 -> V_90 != V_93 )
return - V_78 ;
V_34 = F_24 ( V_18 ,
V_94 ,
& V_75 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_75 ;
return V_87 ;
case V_95 :
V_34 = F_24 ( V_18 ,
V_96 ,
& V_75 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_75 ;
return V_87 ;
case V_97 :
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_30 ( V_18 -> V_38 ,
V_83 , V_1 , V_84 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
default:
return - V_78 ;
}
case V_98 :
switch ( V_83 -> type ) {
case V_92 :
if ( V_83 -> V_90 != V_93 )
return - V_78 ;
* V_1 = 0 ;
* V_84 = 277 ;
return V_99 ;
case V_95 :
* V_1 = 4184 ;
return V_87 ;
case V_97 :
return F_31 ( V_1 , V_84 ) ;
default:
return - V_78 ;
}
case V_100 :
* V_1 = V_18 -> V_77 ;
return V_87 ;
case V_101 :
V_75 = F_1 ( V_18 -> V_41 . V_102 ,
V_103 ) ;
* V_1 = V_75 / 100 ;
* V_84 = ( V_75 % 100 ) * 10000 ;
return V_99 ;
case V_104 :
* V_1 = F_1 ( V_18 -> V_41 . V_102 ,
V_105 ) ;
return V_87 ;
case V_106 :
switch ( V_83 -> type ) {
case V_56 :
* V_1 = F_1 ( V_18 -> V_41 . V_107 ,
V_108 ) ;
return V_87 ;
default:
return - V_78 ;
}
case V_109 :
switch ( V_83 -> type ) {
case V_56 :
* V_1 = F_1 ( V_18 -> V_41 . V_107 ,
V_110 ) ;
return V_87 ;
default:
return - V_78 ;
}
case V_111 :
switch ( V_83 -> type ) {
case V_92 :
if ( V_83 -> V_90 != V_93 )
return - V_78 ;
* V_1 = F_1 ( V_18 -> V_41 . V_112 ,
V_113 ) ;
return V_87 ;
default:
return - V_78 ;
}
default:
return - V_78 ;
}
}
static int F_32 ( struct V_80 * V_81 ,
struct V_82 const * V_83 ,
int V_1 , int V_84 , long V_2 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 , V_75 ;
switch ( V_2 ) {
case V_100 :
if ( V_18 -> V_77 == ! ! V_1 )
return 0 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_33 ( V_18 -> V_38 , V_1 ) ;
if ( V_34 < 0 ) {
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
}
V_18 -> V_77 = V_1 ;
F_27 ( & V_18 -> V_79 ) ;
return 0 ;
case V_101 :
V_75 = V_1 * 100 + V_84 / 10000 ;
if ( V_75 < 0 || V_75 > 255 )
return - V_78 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 ,
V_114 ,
& V_18 -> V_41 . V_102 ,
V_75 , V_103 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
case V_104 :
if ( V_1 < 0 || V_1 > 255 )
return - V_78 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 ,
V_114 ,
& V_18 -> V_41 . V_102 ,
V_1 , V_105 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
case V_106 :
switch ( V_83 -> type ) {
case V_56 :
if ( V_1 < 0 )
return - V_78 ;
if ( V_1 > 6 )
V_1 = 6 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 , V_115 ,
& V_18 -> V_41 . V_107 , V_1 ,
V_108 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
default:
return - V_78 ;
}
case V_109 :
switch ( V_83 -> type ) {
case V_56 :
if ( V_1 < 0 || V_1 > 127 )
return - V_78 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 , V_115 ,
& V_18 -> V_41 . V_107 , V_1 ,
V_110 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
default:
return - V_78 ;
}
case V_111 :
switch ( V_83 -> type ) {
case V_92 :
if ( V_83 -> V_90 != V_93 )
return - V_78 ;
if ( V_1 < 2 )
return - V_78 ;
if ( V_1 > 5 )
V_1 = 5 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 ,
V_116 ,
& V_18 -> V_41 . V_112 , V_1 ,
V_113 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
default:
return - V_78 ;
}
default:
return - V_78 ;
}
}
static int F_34 ( struct V_80 * V_81 ,
const struct V_82 * V_83 ,
enum V_117 type ,
enum V_29 V_30 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
struct V_26 * V_118 ;
V_118 = F_6 ( V_18 , V_83 -> type , V_83 -> V_90 , V_30 ) ;
if ( ! V_118 )
return - V_78 ;
return V_118 -> V_25 ;
}
static int F_35 ( struct V_80 * V_81 ,
const struct V_82 * V_83 ,
enum V_117 type ,
enum V_29 V_30 , int V_119 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
struct V_26 * V_118 ;
int V_34 ;
V_118 = F_6 ( V_18 , V_83 -> type , V_83 -> V_90 , V_30 ) ;
if ( ! V_118 )
return - V_78 ;
if ( V_118 -> V_25 == V_119 )
return 0 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_33 ( V_18 -> V_38 , V_119 ) ;
if ( V_34 < 0 )
goto V_120;
V_118 -> V_25 = V_119 ;
V_34 = F_15 ( V_18 ) ;
if ( V_34 < 0 )
goto V_121;
F_27 ( & V_18 -> V_79 ) ;
return 0 ;
V_121:
if ( V_119 ) {
V_118 -> V_25 = false ;
F_33 ( V_18 -> V_38 , false ) ;
}
V_120:
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
}
static int F_36 ( struct V_80 * V_81 ,
const struct V_82 * V_83 ,
enum V_117 type ,
enum V_29 V_30 ,
enum V_122 V_23 ,
int * V_1 , int * V_84 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
* V_84 = 0 ;
switch ( V_23 ) {
case V_123 :
switch ( V_83 -> type ) {
case V_56 :
* V_1 = F_1 ( V_18 -> V_41 . V_112 ,
V_124 ) ;
return V_87 ;
case V_55 :
* V_1 = 50 ;
return V_87 ;
default:
return - V_78 ;
}
case V_125 :
switch ( V_83 -> type ) {
case V_55 :
* V_1 = F_37 ( V_18 -> V_41 . V_126 ) ;
return V_87 ;
default:
return - V_78 ;
}
default:
return - V_78 ;
}
}
static int F_38 ( struct V_80 * V_81 ,
const struct V_82 * V_83 ,
enum V_117 type ,
enum V_29 V_30 ,
enum V_122 V_23 ,
int V_1 , int V_84 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 ;
switch ( V_23 ) {
case V_123 :
switch ( V_83 -> type ) {
case V_56 :
if ( V_1 < 0 || V_1 > 255 )
return - V_78 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 ,
V_116 ,
& V_18 -> V_41 . V_112 , V_1 ,
V_124 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
default:
return - V_78 ;
}
case V_125 :
switch ( V_83 -> type ) {
case V_55 :
if ( V_1 < 0 || V_1 > F_37 (
V_127 ) )
return - V_78 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 , V_128 ,
& V_18 -> V_41 . V_126 ,
F_39
( V_1 ) , V_129 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
default:
return - V_78 ;
}
default:
return - V_78 ;
}
}
static int F_40 ( struct V_80 * V_81 ,
const struct V_82 * V_83 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
T_1 V_130 ;
V_130 = F_1 ( V_18 -> V_41 . V_107 , V_131 ) ;
return ! V_130 ;
}
static int F_41 ( struct V_80 * V_81 ,
const struct V_82 * V_83 ,
unsigned int V_132 )
{
struct V_17 * V_18 = F_29 ( V_81 ) ;
T_1 V_130 = ! V_132 ;
int V_34 ;
if ( ( V_132 != 0 ) && ( V_132 != 1 ) )
return - V_78 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_8 ( V_18 , V_115 ,
& V_18 -> V_41 . V_107 , V_130 ,
V_131 ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
}
static T_3 F_42 ( int V_133 , void * V_134 )
{
struct V_80 * V_81 = V_134 ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
V_18 -> V_135 = F_43 () ;
return V_136 ;
}
static T_3 F_44 ( int V_133 , void * V_134 )
{
struct V_80 * V_81 = V_134 ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
T_2 V_46 ;
T_1 V_6 ;
struct V_26 * V_137 , * V_138 , * V_53 ;
int V_34 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_13 ( V_18 , & V_6 , & V_46 ) ;
if ( V_34 < 0 ) {
F_27 ( & V_18 -> V_79 ) ;
return V_139 ;
}
V_138 =
F_6 ( V_18 , V_55 ,
F_4 ( V_18 -> V_6 ) ,
V_140 ) ;
V_137 =
F_6 ( V_18 , V_55 ,
F_4 ( V_6 ) ,
V_141 ) ;
V_53 =
F_6 ( V_18 , V_56 , V_16 , V_57 ) ;
if ( V_53 -> V_25 && ( V_46 != V_18 -> V_46 ) ) {
V_18 -> V_46 = V_46 ;
F_45 ( V_81 ,
F_46 ( V_56 , 0 , V_16 ,
V_57 , V_142 , 0 , 0 , 0 ) ,
V_18 -> V_135 ) ;
}
if ( V_6 != V_18 -> V_6 ) {
V_18 -> V_6 = V_6 ;
if ( V_138 && V_138 -> V_25 )
F_45 ( V_81 ,
F_46 ( V_55 , 0 ,
V_138 -> V_23 -> V_28 ,
V_140 ,
V_143 , 0 , 0 , 0 ) ,
V_18 -> V_135 ) ;
if ( V_137 && V_137 -> V_25 )
F_45 ( V_81 ,
F_46 ( V_55 , 0 ,
V_137 -> V_23 -> V_28 ,
V_141 ,
V_143 , 0 , 0 , 0 ) ,
V_18 -> V_135 ) ;
}
F_27 ( & V_18 -> V_79 ) ;
return V_139 ;
}
static int F_47 ( struct V_144 * V_38 )
{
struct V_145 * V_40 ;
struct V_146 * V_147 ;
int V_34 ;
if ( ! V_38 )
return - V_78 ;
V_40 = & V_38 -> V_40 ;
V_147 = F_48 ( V_40 , V_148 , 0 , V_149 ) ;
if ( F_49 ( V_147 ) ) {
F_10 ( V_40 , L_6 ) ;
return F_50 ( V_147 ) ;
}
V_34 = F_51 ( V_147 ) ;
F_52 ( V_40 , L_7 , F_53 ( V_147 ) , V_34 ) ;
return V_34 ;
}
static const char * F_54 ( struct V_145 * V_40 )
{
const struct V_150 * V_151 ;
V_151 = F_55 ( V_40 -> V_152 -> V_153 , V_40 ) ;
if ( ! V_151 )
return NULL ;
return F_56 ( V_40 ) ;
}
static int F_57 ( struct V_144 * V_38 ,
const struct V_154 * V_151 )
{
struct V_17 * V_18 ;
struct V_80 * V_81 ;
const char * V_155 = NULL ;
int V_34 ;
V_81 = F_58 ( & V_38 -> V_40 , sizeof( * V_18 ) ) ;
if ( ! V_81 )
return - V_156 ;
V_18 = F_29 ( V_81 ) ;
F_59 ( V_38 , V_81 ) ;
V_18 -> V_38 = V_38 ;
if ( V_151 )
V_155 = V_151 -> V_155 ;
else if ( F_60 ( & V_38 -> V_40 ) )
V_155 = F_54 ( & V_38 -> V_40 ) ;
else
return - V_157 ;
F_61 ( & V_18 -> V_79 ) ;
F_5 ( V_18 ) ;
V_34 = F_18 ( V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
V_81 -> V_40 . V_158 = & V_38 -> V_40 ;
V_81 -> V_159 = V_160 ;
V_81 -> V_161 = F_62 ( V_160 ) ;
V_81 -> V_155 = V_155 ;
V_81 -> V_162 = V_163 ;
V_81 -> V_23 = & V_164 ;
if ( V_38 -> V_133 < 0 )
V_38 -> V_133 = F_47 ( V_38 ) ;
if ( V_38 -> V_133 >= 0 ) {
V_34 = F_63 ( & V_38 -> V_40 , V_38 -> V_133 ,
F_42 ,
F_44 ,
V_165 ,
V_166 , V_81 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_38 -> V_40 , L_8 ,
V_38 -> V_133 ) ;
goto V_167;
}
}
V_34 = F_64 ( V_81 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_38 -> V_40 , L_9 ) ;
goto V_167;
}
V_34 = F_65 ( & V_38 -> V_40 ) ;
if ( V_34 < 0 )
goto V_168;
F_66 ( & V_38 -> V_40 ) ;
F_67 ( & V_38 -> V_40 ,
V_169 ) ;
F_68 ( & V_38 -> V_40 ) ;
F_52 ( & V_81 -> V_40 , L_10 , V_155 ) ;
return 0 ;
V_168:
F_69 ( V_81 ) ;
V_167:
F_23 ( V_38 , false ) ;
return V_34 ;
}
static int F_70 ( struct V_144 * V_38 )
{
struct V_80 * V_81 = F_71 ( V_38 ) ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
F_72 ( & V_38 -> V_40 ) ;
F_73 ( & V_38 -> V_40 ) ;
F_74 ( & V_38 -> V_40 ) ;
F_69 ( V_81 ) ;
F_25 ( & V_18 -> V_79 ) ;
F_23 ( V_18 -> V_38 , false ) ;
F_27 ( & V_18 -> V_79 ) ;
return 0 ;
}
static int F_75 ( struct V_145 * V_40 )
{
struct V_80 * V_81 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_23 ( V_18 -> V_38 , false ) ;
F_27 ( & V_18 -> V_79 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 , L_11 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_77 ( struct V_145 * V_40 )
{
struct V_80 * V_81 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 ;
V_34 = F_23 ( V_18 -> V_38 , true ) ;
if ( V_34 < 0 )
return V_34 ;
F_11 ( V_45 ) ;
return 0 ;
}
static int F_78 ( struct V_145 * V_40 )
{
struct V_80 * V_81 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_23 ( V_18 -> V_38 , false ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
}
static int F_79 ( struct V_145 * V_40 )
{
struct V_80 * V_81 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_29 ( V_81 ) ;
int V_34 ;
F_25 ( & V_18 -> V_79 ) ;
V_34 = F_23 ( V_18 -> V_38 , true ) ;
F_27 ( & V_18 -> V_79 ) ;
return V_34 ;
}
