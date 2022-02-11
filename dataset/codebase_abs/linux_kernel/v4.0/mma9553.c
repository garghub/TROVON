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
T_3 V_47 ;
T_2 V_48 ;
int V_34 ;
V_34 = F_14 ( V_18 -> V_38 , V_39 ,
V_49 , sizeof( T_3 ) ,
( T_2 * ) & V_47 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_2 ) ;
return V_34 ;
}
V_48 = V_47 & V_50 ;
* V_6 = F_1 ( V_48 , V_51 ) ;
* V_46 = V_47 >> 16 ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
T_1 V_52 = 0 , V_53 = V_39 ;
int V_34 ;
struct V_26 * V_54 ;
bool V_55 ;
V_55 =
F_7 ( V_18 , true , V_56 ) ;
V_54 =
F_6 ( V_18 , V_57 , V_16 , V_58 ) ;
if ( V_55 && V_54 -> V_25 )
V_52 = F_16 ( V_59 ) ;
else if ( V_54 -> V_25 )
V_52 = F_16 ( V_60 ) ;
else if ( V_55 )
V_52 = F_16 ( V_61 ) ;
else
V_53 = V_62 ;
if ( V_18 -> V_63 == V_52 )
return 0 ;
if ( V_55 || V_54 -> V_25 )
F_13 ( V_18 , & V_18 -> V_6 ,
& V_18 -> V_46 ) ;
V_34 = F_17 ( V_18 -> V_38 ,
V_64 ,
V_53 , V_52 , V_65 ) ;
if ( V_34 < 0 )
return V_34 ;
V_18 -> V_63 = V_52 ;
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
V_66 ,
sizeof( V_18 -> V_41 ) , ( T_2 * ) & V_18 -> V_41 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_3 ) ;
return V_34 ;
}
V_18 -> V_63 = - 1 ;
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
V_66 ,
sizeof( V_18 -> V_41 ) , ( T_2 * ) & V_18 -> V_41 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_4 ) ;
return V_34 ;
}
return F_23 ( V_18 -> V_38 , true ) ;
}
static int F_24 ( struct V_75 * V_76 ,
struct V_77 const * V_78 ,
int * V_1 , int * V_79 , long V_2 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 ;
T_2 V_80 ;
T_1 V_6 ;
bool V_81 ;
switch ( V_2 ) {
case V_82 :
switch ( V_78 -> type ) {
case V_57 :
V_81 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_83 ;
if ( ! V_81 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_84 ;
}
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_86 ,
& V_80 ) ;
F_28 ( & V_18 -> V_85 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_80 ;
return V_87 ;
case V_88 :
V_81 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_83 ;
if ( ! V_81 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_84 ;
}
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_89 ,
& V_80 ) ;
F_28 ( & V_18 -> V_85 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_80 ;
return V_87 ;
case V_56 :
V_81 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_83 ;
if ( ! V_81 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_84 ;
}
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_49 ,
& V_80 ) ;
F_28 ( & V_18 -> V_85 ) ;
if ( V_34 < 0 )
return V_34 ;
V_6 =
F_1 ( V_80 , V_51 ) ;
if ( V_78 -> V_90 == F_4 ( V_6 ) )
* V_1 = 100 ;
else
* V_1 = 0 ;
return V_87 ;
default:
return - V_84 ;
}
case V_91 :
switch ( V_78 -> type ) {
case V_92 :
if ( V_78 -> V_90 != V_93 )
return - V_84 ;
V_81 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_83 ;
if ( ! V_81 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_84 ;
}
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_94 , & V_80 ) ;
F_28 ( & V_18 -> V_85 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_80 ;
return V_87 ;
case V_95 :
V_81 =
F_7 ( V_18 , false , 0 ) ||
V_18 -> V_83 ;
if ( ! V_81 ) {
F_10 ( & V_18 -> V_38 -> V_40 ,
L_5 ) ;
return - V_84 ;
}
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_27 ( V_18 -> V_38 ,
V_39 ,
V_96 ,
& V_80 ) ;
F_28 ( & V_18 -> V_85 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_1 = V_80 ;
return V_87 ;
case V_97 :
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_29 ( V_18 -> V_38 ,
V_78 , V_1 , V_79 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
default:
return - V_84 ;
}
case V_98 :
switch ( V_78 -> type ) {
case V_92 :
if ( V_78 -> V_90 != V_93 )
return - V_84 ;
* V_1 = 0 ;
* V_79 = 277 ;
return V_99 ;
case V_95 :
* V_1 = 4184 ;
return V_87 ;
case V_97 :
return F_30 ( V_1 , V_79 ) ;
default:
return - V_84 ;
}
case V_100 :
* V_1 = V_18 -> V_83 ;
return V_87 ;
case V_101 :
V_80 = F_1 ( V_18 -> V_41 . V_102 ,
V_103 ) ;
* V_1 = V_80 / 100 ;
* V_79 = ( V_80 % 100 ) * 10000 ;
return V_99 ;
case V_104 :
* V_1 = F_1 ( V_18 -> V_41 . V_102 ,
V_105 ) ;
return V_87 ;
case V_106 :
switch ( V_78 -> type ) {
case V_57 :
* V_1 = F_1 ( V_18 -> V_41 . V_107 ,
V_108 ) ;
return V_87 ;
default:
return - V_84 ;
}
case V_109 :
switch ( V_78 -> type ) {
case V_57 :
* V_1 = F_1 ( V_18 -> V_41 . V_107 ,
V_110 ) ;
return V_87 ;
default:
return - V_84 ;
}
case V_111 :
switch ( V_78 -> type ) {
case V_92 :
if ( V_78 -> V_90 != V_93 )
return - V_84 ;
* V_1 = F_1 ( V_18 -> V_41 . V_112 ,
V_113 ) ;
return V_87 ;
default:
return - V_84 ;
}
default:
return - V_84 ;
}
}
static int F_31 ( struct V_75 * V_76 ,
struct V_77 const * V_78 ,
int V_1 , int V_79 , long V_2 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 , V_80 ;
switch ( V_2 ) {
case V_100 :
if ( V_18 -> V_83 == ! ! V_1 )
return 0 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_32 ( V_18 -> V_38 , V_1 ) ;
if ( V_34 < 0 ) {
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
}
V_18 -> V_83 = V_1 ;
F_28 ( & V_18 -> V_85 ) ;
return 0 ;
case V_101 :
V_80 = V_1 * 100 + V_79 / 10000 ;
if ( V_80 < 0 || V_80 > 255 )
return - V_84 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 ,
V_114 ,
& V_18 -> V_41 . V_102 ,
V_80 , V_103 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
case V_104 :
if ( V_1 < 0 || V_1 > 255 )
return - V_84 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 ,
V_114 ,
& V_18 -> V_41 . V_102 ,
V_1 , V_105 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
case V_106 :
switch ( V_78 -> type ) {
case V_57 :
if ( V_1 < 0 )
return - V_84 ;
if ( V_1 > 6 )
V_1 = 6 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 , V_115 ,
& V_18 -> V_41 . V_107 , V_1 ,
V_108 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
default:
return - V_84 ;
}
case V_109 :
switch ( V_78 -> type ) {
case V_57 :
if ( V_1 < 0 || V_1 > 127 )
return - V_84 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 , V_115 ,
& V_18 -> V_41 . V_107 , V_1 ,
V_110 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
default:
return - V_84 ;
}
case V_111 :
switch ( V_78 -> type ) {
case V_92 :
if ( V_78 -> V_90 != V_93 )
return - V_84 ;
if ( V_1 < 2 )
return - V_84 ;
if ( V_1 > 5 )
V_1 = 5 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 ,
V_116 ,
& V_18 -> V_41 . V_112 , V_1 ,
V_113 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
default:
return - V_84 ;
}
default:
return - V_84 ;
}
}
static int F_33 ( struct V_75 * V_76 ,
const struct V_77 * V_78 ,
enum V_117 type ,
enum V_29 V_30 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
struct V_26 * V_118 ;
V_118 = F_6 ( V_18 , V_78 -> type , V_78 -> V_90 , V_30 ) ;
if ( ! V_118 )
return - V_84 ;
return V_118 -> V_25 ;
}
static int F_34 ( struct V_75 * V_76 ,
const struct V_77 * V_78 ,
enum V_117 type ,
enum V_29 V_30 , int V_119 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
struct V_26 * V_118 ;
int V_34 ;
V_118 = F_6 ( V_18 , V_78 -> type , V_78 -> V_90 , V_30 ) ;
if ( ! V_118 )
return - V_84 ;
if ( V_118 -> V_25 == V_119 )
return 0 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_32 ( V_18 -> V_38 , V_119 ) ;
if ( V_34 < 0 )
goto V_120;
V_118 -> V_25 = V_119 ;
V_34 = F_15 ( V_18 ) ;
if ( V_34 < 0 )
goto V_121;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
V_121:
if ( V_119 ) {
V_118 -> V_25 = false ;
F_32 ( V_18 -> V_38 , false ) ;
}
V_120:
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
}
static int F_35 ( struct V_75 * V_76 ,
const struct V_77 * V_78 ,
enum V_117 type ,
enum V_29 V_30 ,
enum V_122 V_23 ,
int * V_1 , int * V_79 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
* V_79 = 0 ;
switch ( V_23 ) {
case V_123 :
switch ( V_78 -> type ) {
case V_57 :
* V_1 = F_1 ( V_18 -> V_41 . V_112 ,
V_124 ) ;
return V_87 ;
case V_56 :
* V_1 = 50 ;
return V_87 ;
default:
return - V_84 ;
}
case V_125 :
switch ( V_78 -> type ) {
case V_56 :
* V_1 = F_36 ( V_18 -> V_41 . V_126 ) ;
return V_87 ;
default:
return - V_84 ;
}
default:
return - V_84 ;
}
}
static int F_37 ( struct V_75 * V_76 ,
const struct V_77 * V_78 ,
enum V_117 type ,
enum V_29 V_30 ,
enum V_122 V_23 ,
int V_1 , int V_79 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 ;
switch ( V_23 ) {
case V_123 :
switch ( V_78 -> type ) {
case V_57 :
if ( V_1 < 0 || V_1 > 255 )
return - V_84 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 ,
V_116 ,
& V_18 -> V_41 . V_112 , V_1 ,
V_124 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
default:
return - V_84 ;
}
case V_125 :
switch ( V_78 -> type ) {
case V_56 :
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 , V_127 ,
& V_18 -> V_41 . V_126 ,
F_38
( V_1 ) , V_50 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
default:
return - V_84 ;
}
default:
return - V_84 ;
}
}
static int F_39 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
T_1 V_128 ;
V_128 = F_1 ( V_18 -> V_41 . V_107 , V_129 ) ;
return ! V_128 ;
}
static int F_40 ( struct V_75 * V_76 ,
const struct V_77 * V_78 ,
unsigned int V_130 )
{
struct V_17 * V_18 = F_25 ( V_76 ) ;
T_1 V_128 = ! V_130 ;
int V_34 ;
if ( ( V_130 != 0 ) && ( V_130 != 1 ) )
return - V_84 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_8 ( V_18 , V_115 ,
& V_18 -> V_41 . V_107 , V_128 ,
V_129 ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
}
static T_4 F_41 ( int V_131 , void * V_132 )
{
struct V_75 * V_76 = V_132 ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
V_18 -> V_133 = F_42 () ;
return V_134 ;
}
static T_4 F_43 ( int V_131 , void * V_132 )
{
struct V_75 * V_76 = V_132 ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
T_2 V_46 ;
T_1 V_6 ;
struct V_26 * V_135 , * V_136 , * V_54 ;
int V_34 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_13 ( V_18 , & V_6 , & V_46 ) ;
if ( V_34 < 0 ) {
F_28 ( & V_18 -> V_85 ) ;
return V_137 ;
}
V_136 =
F_6 ( V_18 , V_56 ,
F_4 ( V_18 -> V_6 ) ,
V_138 ) ;
V_135 =
F_6 ( V_18 , V_56 ,
F_4 ( V_6 ) ,
V_139 ) ;
V_54 =
F_6 ( V_18 , V_57 , V_16 , V_58 ) ;
if ( V_54 -> V_25 && ( V_46 != V_18 -> V_46 ) ) {
V_18 -> V_46 = V_46 ;
F_44 ( V_76 ,
F_45 ( V_57 , 0 , V_16 ,
V_58 , V_140 , 0 , 0 , 0 ) ,
V_18 -> V_133 ) ;
}
if ( V_6 != V_18 -> V_6 ) {
V_18 -> V_6 = V_6 ;
if ( V_136 && V_136 -> V_25 )
F_44 ( V_76 ,
F_45 ( V_56 , 0 ,
V_136 -> V_23 -> V_28 ,
V_138 ,
V_141 , 0 , 0 , 0 ) ,
V_18 -> V_133 ) ;
if ( V_135 && V_135 -> V_25 )
F_44 ( V_76 ,
F_45 ( V_56 , 0 ,
V_135 -> V_23 -> V_28 ,
V_139 ,
V_141 , 0 , 0 , 0 ) ,
V_18 -> V_133 ) ;
}
F_28 ( & V_18 -> V_85 ) ;
return V_137 ;
}
static int F_46 ( struct V_142 * V_38 )
{
struct V_143 * V_40 ;
struct V_144 * V_145 ;
int V_34 ;
if ( ! V_38 )
return - V_84 ;
V_40 = & V_38 -> V_40 ;
V_145 = F_47 ( V_40 , V_146 , 0 ) ;
if ( F_48 ( V_145 ) ) {
F_10 ( V_40 , L_6 ) ;
return F_49 ( V_145 ) ;
}
V_34 = F_50 ( V_145 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_51 ( V_145 ) ;
F_52 ( V_40 , L_7 , F_53 ( V_145 ) , V_34 ) ;
return V_34 ;
}
static const char * F_54 ( struct V_143 * V_40 )
{
const struct V_147 * V_148 ;
V_148 = F_55 ( V_40 -> V_149 -> V_150 , V_40 ) ;
if ( ! V_148 )
return NULL ;
return F_56 ( V_40 ) ;
}
static int F_57 ( struct V_142 * V_38 ,
const struct V_151 * V_148 )
{
struct V_17 * V_18 ;
struct V_75 * V_76 ;
const char * V_152 = NULL ;
int V_34 ;
V_76 = F_58 ( & V_38 -> V_40 , sizeof( * V_18 ) ) ;
if ( ! V_76 )
return - V_153 ;
V_18 = F_25 ( V_76 ) ;
F_59 ( V_38 , V_76 ) ;
V_18 -> V_38 = V_38 ;
if ( V_148 )
V_152 = V_148 -> V_152 ;
else if ( F_60 ( & V_38 -> V_40 ) )
V_152 = F_54 ( & V_38 -> V_40 ) ;
else
return - V_154 ;
F_61 ( & V_18 -> V_85 ) ;
F_5 ( V_18 ) ;
V_34 = F_18 ( V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
V_76 -> V_40 . V_155 = & V_38 -> V_40 ;
V_76 -> V_156 = V_157 ;
V_76 -> V_158 = F_62 ( V_157 ) ;
V_76 -> V_152 = V_152 ;
V_76 -> V_159 = V_160 ;
V_76 -> V_23 = & V_161 ;
if ( V_38 -> V_131 < 0 )
V_38 -> V_131 = F_46 ( V_38 ) ;
if ( V_38 -> V_131 >= 0 ) {
V_34 = F_63 ( & V_38 -> V_40 , V_38 -> V_131 ,
F_41 ,
F_43 ,
V_162 ,
V_163 , V_76 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_38 -> V_40 , L_8 ,
V_38 -> V_131 ) ;
goto V_164;
}
}
V_34 = F_64 ( V_76 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_38 -> V_40 , L_9 ) ;
goto V_164;
}
V_34 = F_65 ( & V_38 -> V_40 ) ;
if ( V_34 < 0 )
goto V_165;
F_66 ( & V_38 -> V_40 ) ;
F_67 ( & V_38 -> V_40 ,
V_166 ) ;
F_68 ( & V_38 -> V_40 ) ;
F_52 ( & V_76 -> V_40 , L_10 , V_152 ) ;
return 0 ;
V_165:
F_69 ( V_76 ) ;
V_164:
F_23 ( V_38 , false ) ;
return V_34 ;
}
static int F_70 ( struct V_142 * V_38 )
{
struct V_75 * V_76 = F_71 ( V_38 ) ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
F_72 ( & V_38 -> V_40 ) ;
F_73 ( & V_38 -> V_40 ) ;
F_74 ( & V_38 -> V_40 ) ;
F_69 ( V_76 ) ;
F_26 ( & V_18 -> V_85 ) ;
F_23 ( V_18 -> V_38 , false ) ;
F_28 ( & V_18 -> V_85 ) ;
return 0 ;
}
static int F_75 ( struct V_143 * V_40 )
{
struct V_75 * V_76 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_23 ( V_18 -> V_38 , false ) ;
F_28 ( & V_18 -> V_85 ) ;
if ( V_34 < 0 ) {
F_10 ( & V_18 -> V_38 -> V_40 , L_11 ) ;
return - V_167 ;
}
return 0 ;
}
static int F_77 ( struct V_143 * V_40 )
{
struct V_75 * V_76 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 ;
V_34 = F_23 ( V_18 -> V_38 , true ) ;
if ( V_34 < 0 )
return V_34 ;
F_11 ( V_45 ) ;
return 0 ;
}
static int F_78 ( struct V_143 * V_40 )
{
struct V_75 * V_76 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_23 ( V_18 -> V_38 , false ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
}
static int F_79 ( struct V_143 * V_40 )
{
struct V_75 * V_76 = F_71 ( F_76 ( V_40 ) ) ;
struct V_17 * V_18 = F_25 ( V_76 ) ;
int V_34 ;
F_26 ( & V_18 -> V_85 ) ;
V_34 = F_23 ( V_18 -> V_38 , true ) ;
F_28 ( & V_18 -> V_85 ) ;
return V_34 ;
}
