static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_5 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
struct V_14 * V_15 = & V_13 -> V_15 ;
if ( ! V_15 -> V_16 )
F_5 ( V_11 , V_17 ,
F_6 ( V_17 ) ) ;
if ( ! V_15 -> V_18 )
F_5 ( V_11 , V_19 ,
F_6 ( V_19 ) ) ;
return 0 ;
}
static int F_7 ( int V_20 , int V_21 )
{
int V_22 , V_23 = - V_24 ;
T_1 V_25 , V_26 = 0 ;
for ( V_22 = 0 ; V_22 < F_6 ( V_27 ) ; V_22 ++ ) {
if ( V_27 [ V_22 ] . V_21 == V_21 ) {
V_25 = V_27 [ V_22 ] . V_20 ;
if ( abs ( V_20 - V_25 ) < abs ( V_20 - V_26 ) ) {
V_26 = V_25 ;
V_23 = V_22 ;
}
}
}
return V_23 ;
}
static int F_8 ( struct V_28 * V_29 ,
int V_30 , unsigned int V_31 , int V_32 )
{
struct V_10 * V_11 = V_29 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
if ( ( V_31 >= V_33 ) && ( V_31 <= V_34 ) ) {
V_13 -> V_35 = V_31 ;
} else {
F_9 ( V_11 -> V_2 , L_1 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_10 ( struct V_28 * V_29 , unsigned int V_36 )
{
struct V_10 * V_11 = V_29 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
T_2 V_37 = 0 ;
switch ( V_36 & V_38 ) {
case V_39 :
V_37 = V_40 ;
break;
case V_41 :
V_37 = V_42 ;
break;
default:
return - V_24 ;
}
switch ( V_36 & V_43 ) {
case V_44 :
V_37 |= V_45 |
V_46 ;
break;
case V_47 :
V_37 |= V_48 ;
break;
case V_49 :
V_37 |= V_50 |
V_51 ;
break;
case V_52 :
V_37 |= V_53 ;
break;
case V_54 :
break;
default:
return - V_24 ;
}
switch ( V_36 & V_55 ) {
case V_56 :
break;
case V_57 :
V_37 |= V_58 ;
break;
case V_59 :
V_37 |= V_58 ;
break;
case V_60 :
break;
default:
return - V_24 ;
}
V_13 -> V_61 . V_62 = V_37 ;
F_11 ( V_11 , V_63 , V_13 -> V_61 . V_62 ) ;
return 0 ;
}
static int F_12 ( struct V_28 * V_64 , int V_65 )
{
struct V_10 * V_11 = V_64 -> V_11 ;
if ( V_65 )
F_13 ( V_11 , V_66 ,
V_67 ,
V_68 ) ;
else
F_13 ( V_11 , V_66 ,
V_67 ,
V_69 ) ;
return 0 ;
}
static int F_14 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_28 * V_64 )
{
struct V_10 * V_11 = V_64 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
T_3 V_74 = 0 ;
int V_75 ;
V_75 = F_7 ( V_13 -> V_35 , F_15 ( V_73 ) ) ;
if ( V_75 >= 0 ) {
V_13 -> V_35 = V_27 [ V_75 ] . V_20 ;
V_74 |= ( V_27 [ V_75 ] . V_76 << V_77 ) |
( V_27 [ V_75 ] . V_78 << V_79 ) |
( V_27 [ V_75 ] . V_80 << V_81 ) |
( V_27 [ V_75 ] . V_82 << V_83 ) |
V_27 [ V_75 ] . V_84 ;
F_11 ( V_11 , V_85 , V_74 ) ;
} else {
F_9 ( V_11 -> V_2 , L_2 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
enum V_86 V_87 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
switch ( V_87 ) {
case V_88 :
break;
case V_89 :
F_13 ( V_11 , V_90 ,
V_91 , 0 ) ;
break;
case V_92 :
if ( F_17 ( V_11 ) == V_93 ) {
F_18 ( V_13 -> V_94 , false ) ;
F_19 ( V_13 -> V_94 ) ;
}
F_11 ( V_11 , V_90 , V_95 ) ;
break;
case V_93 :
F_11 ( V_11 , V_90 , V_95 ) ;
F_18 ( V_13 -> V_94 , true ) ;
break;
}
return 0 ;
}
static void F_20 ( struct V_96 * V_97 )
{
struct V_12 * V_13 =
F_21 ( V_97 , struct V_12 , V_98 ) ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_99 * V_100 = F_22 ( V_11 ) ;
int V_22 ;
int V_101 = 0 ;
int V_102 = 0 ;
if ( V_13 -> V_103 ) {
for ( V_22 = 0 ; V_22 < F_6 ( V_104 ) ; V_22 ++ ) {
if ( abs ( V_13 -> V_103 - V_104 [ V_22 ] ) <
abs ( V_13 -> V_103 - V_104 [ V_102 ] ) )
V_102 = V_22 ;
}
F_23 ( V_11 -> V_2 , L_3 ,
V_104 [ V_102 ] , V_13 -> V_103 ) ;
V_101 = ( V_102 << V_105 ) ;
F_24 ( V_100 , L_4 ) ;
} else {
F_23 ( V_11 -> V_2 , L_5 ) ;
F_25 ( V_100 , L_4 ) ;
}
F_13 ( V_11 , V_106 ,
V_107 , V_101 ) ;
F_26 ( V_100 ) ;
}
static int F_27 ( struct V_108 * V_2 , unsigned int type ,
unsigned int V_109 , int V_110 )
{
struct V_10 * V_11 = F_28 ( V_2 ) ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
F_23 ( V_11 -> V_2 , L_6 , V_109 , V_110 ) ;
switch ( V_109 ) {
case V_111 :
if ( V_110 )
V_110 = 261 ;
case V_112 :
break;
default:
return - 1 ;
}
V_13 -> V_103 = V_110 ;
F_29 ( & V_13 -> V_98 ) ;
return 0 ;
}
static T_4 F_30 ( struct V_1 * V_2 ,
struct V_113 * V_114 ,
const char * V_115 , T_5 V_116 )
{
struct V_12 * V_13 = F_31 ( V_2 ) ;
long int time ;
int V_23 ;
V_23 = F_32 ( V_115 , 10 , & time ) ;
if ( V_23 != 0 )
return V_23 ;
F_33 ( V_13 -> V_117 , V_118 , V_112 , time ) ;
return V_116 ;
}
static void F_34 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
int V_23 ;
V_13 -> V_117 = F_35 ( V_11 -> V_2 ) ;
if ( ! V_13 -> V_117 ) {
F_9 ( V_11 -> V_2 , L_7 ) ;
return;
}
F_36 ( & V_13 -> V_98 , F_20 ) ;
V_13 -> V_103 = 0 ;
V_13 -> V_117 -> V_119 = L_8 ;
V_13 -> V_117 -> V_120 = F_37 ( V_11 -> V_2 ) ;
V_13 -> V_117 -> V_121 . V_122 = V_123 ;
V_13 -> V_117 -> V_124 [ 0 ] = F_38 ( V_118 ) ;
V_13 -> V_117 -> V_125 [ 0 ] = F_38 ( V_111 ) | F_38 ( V_112 ) ;
V_13 -> V_117 -> V_126 = F_27 ;
V_13 -> V_117 -> V_2 . V_127 = V_11 -> V_2 ;
F_39 ( V_13 -> V_117 , V_11 ) ;
V_23 = F_40 ( V_13 -> V_117 ) ;
if ( V_23 != 0 ) {
V_13 -> V_117 = NULL ;
F_9 ( V_11 -> V_2 , L_9 ) ;
}
V_23 = F_41 ( V_11 -> V_2 , & V_128 ) ;
if ( V_23 != 0 ) {
F_9 ( V_11 -> V_2 , L_10 ,
V_23 ) ;
}
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
F_43 ( V_11 -> V_2 , & V_128 ) ;
F_44 ( & V_13 -> V_98 ) ;
V_13 -> V_117 = NULL ;
F_13 ( V_11 , V_129 ,
V_130 , 0 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
F_18 ( V_13 -> V_94 , true ) ;
F_3 ( V_11 ) ;
F_34 ( V_11 ) ;
V_13 -> V_35 = V_131 ;
V_13 -> V_61 . V_62 = V_132 ;
return 0 ;
}
static int F_46 ( struct V_10 * V_11 )
{
F_42 ( V_11 ) ;
return 0 ;
}
static int F_47 ( struct V_133 * V_133 ,
const struct V_134 * V_121 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_48 ( & V_133 -> V_2 ) ;
int V_23 ;
unsigned int V_135 = 0 ;
unsigned int V_3 ;
T_3 V_136 ;
V_13 = F_49 ( & V_133 -> V_2 , sizeof( struct V_12 ) ,
V_137 ) ;
if ( V_13 == NULL )
return - V_138 ;
V_13 -> V_2 = & V_133 -> V_2 ;
V_13 -> V_94 = F_50 ( V_133 , & V_139 ) ;
if ( F_51 ( V_13 -> V_94 ) ) {
V_23 = F_52 ( V_13 -> V_94 ) ;
F_9 ( & V_133 -> V_2 , L_11 , V_23 ) ;
return V_23 ;
}
if ( V_15 ) {
V_13 -> V_15 = * V_15 ;
} else {
V_15 = F_49 ( & V_133 -> V_2 ,
sizeof( struct V_14 ) ,
V_137 ) ;
if ( ! V_15 ) {
F_9 ( & V_133 -> V_2 , L_12 ) ;
return - V_138 ;
}
if ( V_133 -> V_2 . V_140 ) {
if ( F_53 ( V_133 -> V_2 . V_140 ,
L_13 ) )
V_15 -> V_16 = true ;
if ( F_53 ( V_133 -> V_2 . V_140 ,
L_14 ) )
V_15 -> V_18 = true ;
if ( F_54 ( V_133 -> V_2 . V_140 ,
L_15 , & V_136 ) >= 0 )
V_15 -> V_141 = V_136 ;
if ( F_54 ( V_133 -> V_2 . V_140 ,
L_16 , & V_136 ) >= 0 )
V_15 -> V_142 = V_136 ;
V_15 -> V_143 =
F_55 ( V_133 -> V_2 . V_140 ,
L_17 , 0 ) ;
}
V_13 -> V_15 = * V_15 ;
}
if ( V_13 -> V_15 . V_143 ) {
V_23 = F_56 ( & V_133 -> V_2 ,
V_13 -> V_15 . V_143 ,
V_144 ,
L_18 ) ;
if ( V_23 < 0 ) {
F_9 ( & V_133 -> V_2 , L_19 ,
V_13 -> V_15 . V_143 , V_23 ) ;
return V_23 ;
}
F_57 ( V_13 -> V_15 . V_143 , 0 ) ;
F_57 ( V_13 -> V_15 . V_143 , 1 ) ;
}
F_58 ( V_133 , V_13 ) ;
V_23 = F_59 ( V_13 -> V_94 , V_145 ,
F_6 ( V_145 ) ) ;
if ( V_23 != 0 )
F_60 ( V_13 -> V_2 , L_20 ,
V_23 ) ;
V_23 = F_61 ( V_13 -> V_94 , V_4 , & V_3 ) ;
V_135 = V_3 & V_146 ;
if ( V_135 != V_147 ) {
V_23 = - V_148 ;
F_9 ( & V_133 -> V_2 ,
L_21 ,
V_135 , V_147 ) ;
return V_23 ;
}
F_62 ( & V_133 -> V_2 , L_22 ,
V_3 & V_149 ) ;
if ( V_13 -> V_15 . V_16 )
F_63 ( V_13 -> V_94 , V_150 ,
V_151 ,
V_13 -> V_15 . V_16 <<
V_152 ) ;
if ( V_13 -> V_15 . V_18 )
F_63 ( V_13 -> V_94 , V_153 ,
V_151 ,
V_13 -> V_15 . V_18 <<
V_152 ) ;
if ( V_13 -> V_15 . V_142 )
F_63 ( V_13 -> V_94 , V_5 ,
V_154 ,
V_13 -> V_15 . V_142 <<
V_155 ) ;
if ( V_13 -> V_15 . V_141 )
F_63 ( V_13 -> V_94 , V_6 ,
V_156 ,
V_13 -> V_15 . V_141 ) ;
V_23 = F_64 ( & V_133 -> V_2 ,
& V_157 , & V_158 , 1 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_65 ( struct V_133 * V_159 )
{
F_66 ( & V_159 -> V_2 ) ;
return 0 ;
}
