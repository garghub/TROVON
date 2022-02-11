static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_6 ;
F_3 ( V_2 , V_4 , V_5 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_6 ;
F_3 ( V_2 , V_4 , V_5 , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_9 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
F_6 ( 75 , 100 ) ;
V_3 &= ~ V_9 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_8 ( V_11 , V_12 , V_13 , 1 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_14 ;
T_1 V_15 ;
F_8 ( V_11 , V_12 , V_13 , 0 ) ;
V_14 = V_16 ;
while ( V_14 -- ) {
F_6 ( 50 , 75 ) ;
V_15 = F_10 ( V_11 , V_17 ) ;
if ( F_11 ( V_15 , V_17 , V_18 ) &&
F_11 ( V_15 , V_17 , V_19 ) )
goto V_20;
}
F_12 ( V_2 -> V_21 , L_1 ,
V_15 ) ;
V_20:
F_13 ( V_11 , V_22 , V_23 , 0 ) ;
F_13 ( V_11 , V_22 , V_23 , 1 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_25 ;
V_3 |= V_26 ;
F_3 ( V_2 , V_7 , V_24 , V_3 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_27 ;
V_3 |= V_28 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_7 ( V_2 ) ;
F_8 ( V_11 , V_12 , V_29 , V_30 ) ;
F_8 ( V_11 , V_12 , V_31 , V_32 ) ;
F_8 ( V_11 , V_12 , V_33 , V_34 ) ;
F_8 ( V_11 , V_12 , V_35 ,
V_11 -> V_36 [ V_37 ] ) ;
F_8 ( V_11 , V_12 , V_38 ,
V_11 -> V_39 [ V_37 ] ) ;
F_13 ( V_11 , V_40 , V_41 ,
V_11 -> V_42 [ V_37 ] ) ;
F_13 ( V_11 , V_43 , V_44 ,
V_11 -> V_45 [ V_37 ] ) ;
F_13 ( V_11 , V_46 , V_47 ,
V_11 -> V_48 [ V_37 ] ) ;
F_15 ( V_11 , V_49 ,
V_11 -> V_50 [ V_37 ] ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
V_3 = F_4 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_25 ;
V_3 |= V_51 ;
F_3 ( V_2 , V_7 , V_24 , V_3 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_27 ;
V_3 |= V_52 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_7 ( V_2 ) ;
F_8 ( V_11 , V_12 , V_29 , V_53 ) ;
F_8 ( V_11 , V_12 , V_31 , V_54 ) ;
F_8 ( V_11 , V_12 , V_33 , V_55 ) ;
F_8 ( V_11 , V_12 , V_35 ,
V_11 -> V_36 [ V_56 ] ) ;
F_8 ( V_11 , V_12 , V_38 ,
V_11 -> V_39 [ V_56 ] ) ;
F_13 ( V_11 , V_40 , V_41 ,
V_11 -> V_42 [ V_56 ] ) ;
F_13 ( V_11 , V_43 , V_44 ,
V_11 -> V_45 [ V_56 ] ) ;
F_13 ( V_11 , V_46 , V_47 ,
V_11 -> V_48 [ V_56 ] ) ;
F_15 ( V_11 , V_49 ,
V_11 -> V_50 [ V_56 ] ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
V_3 = F_4 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_25 ;
V_3 |= V_51 ;
F_3 ( V_2 , V_7 , V_24 , V_3 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_27 ;
V_3 |= V_52 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_7 ( V_2 ) ;
F_8 ( V_11 , V_12 , V_29 , V_57 ) ;
F_8 ( V_11 , V_12 , V_31 , V_58 ) ;
F_8 ( V_11 , V_12 , V_33 , V_59 ) ;
F_8 ( V_11 , V_12 , V_35 ,
V_11 -> V_36 [ V_60 ] ) ;
F_8 ( V_11 , V_12 , V_38 ,
V_11 -> V_39 [ V_60 ] ) ;
F_13 ( V_11 , V_40 , V_41 ,
V_11 -> V_42 [ V_60 ] ) ;
F_13 ( V_11 , V_43 , V_44 ,
V_11 -> V_45 [ V_60 ] ) ;
F_13 ( V_11 , V_46 , V_47 ,
V_11 -> V_48 [ V_60 ] ) ;
F_15 ( V_11 , V_49 ,
V_11 -> V_50 [ V_60 ] ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_61 * V_62 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_25 ) == V_26 )
* V_62 = V_63 ;
else
* V_62 = V_64 ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
enum V_61 V_62 ;
if ( F_18 ( V_2 , & V_62 ) )
return false ;
return ( V_62 == V_63 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
if ( F_19 ( V_2 ) ) {
if ( V_11 -> V_65 == V_66 )
V_3 = F_17 ( V_2 ) ;
else
V_3 = F_16 ( V_2 ) ;
} else {
V_3 = F_14 ( V_2 ) ;
}
return V_3 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_61 V_62 )
{
enum V_61 V_67 ;
int V_3 ;
V_3 = F_18 ( V_2 , & V_67 ) ;
if ( V_3 )
return V_3 ;
if ( V_62 != V_67 )
V_3 = F_20 ( V_2 ) ;
return V_3 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 == V_69 ) {
if ( V_2 -> V_70 & V_71 )
return true ;
} else {
if ( V_2 -> V_72 == V_73 )
return true ;
}
return false ;
}
static bool F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 == V_69 ) {
if ( V_2 -> V_70 & V_74 )
return true ;
} else {
if ( V_2 -> V_72 == V_75 )
return true ;
}
return false ;
}
static bool F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 == V_69 ) {
if ( V_2 -> V_70 & V_76 )
return true ;
} else {
if ( V_2 -> V_72 == V_77 )
return true ;
}
return false ;
}
static int F_25 ( struct V_1 * V_2 , bool V_78 ,
bool V_79 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_80 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_81 ;
if ( V_78 )
V_3 |= V_81 ;
if ( V_79 )
V_3 |= V_82 ;
F_3 ( V_2 , V_80 , V_8 , V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , true , true ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , false , false ) ;
}
static enum V_83 F_28 ( struct V_1 * V_2 ,
enum V_84 * V_85 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_86 , V_87 , V_3 ;
* V_85 = V_88 ;
if ( ! F_19 ( V_2 ) )
return V_89 ;
V_86 = F_2 ( V_2 , V_80 , V_90 + 2 ) ;
if ( V_86 < 0 )
return V_91 ;
V_87 = F_2 ( V_2 , V_80 , V_92 + 2 ) ;
if ( V_87 < 0 )
return V_91 ;
V_3 = F_2 ( V_2 , V_4 , V_93 ) ;
if ( V_3 < 0 )
return V_91 ;
V_3 &= ~ V_94 ;
if ( ( V_86 & 0xc000 ) && ( V_87 & 0xc000 ) )
V_3 |= V_11 -> V_95 ;
F_3 ( V_2 , V_4 , V_93 , V_3 ) ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_91 ;
if ( V_3 & V_6 ) {
F_29 ( V_11 , V_96 , V_97 , 1 ) ;
V_3 |= V_98 ;
F_3 ( V_2 , V_4 , V_5 ,
V_3 ) ;
F_29 ( V_11 , V_96 , V_97 , 0 ) ;
}
return V_89 ;
}
static enum V_83 F_30 ( struct V_1 * V_2 ,
enum V_84 * V_85 )
{
T_1 V_99 ;
* V_85 = V_100 ;
V_99 = V_101 ;
V_99 |= V_102 ;
F_3 ( V_2 , V_80 , V_103 + 2 , 0 ) ;
F_3 ( V_2 , V_80 , V_103 + 1 , 0 ) ;
F_3 ( V_2 , V_80 , V_103 , V_99 ) ;
return V_89 ;
}
static enum V_83 F_31 ( struct V_1 * V_2 ,
enum V_84 * V_85 )
{
unsigned int V_104 ;
int V_3 , V_86 , V_87 ;
V_3 = F_2 ( V_2 , V_80 , V_92 + 1 ) ;
if ( V_3 < 0 )
return V_91 ;
V_104 = F_19 ( V_2 ) ? 0x80 : 0x20 ;
if ( ! ( V_3 & V_104 ) )
return V_105 ;
V_86 = F_2 ( V_2 , V_80 , V_90 ) ;
if ( V_86 < 0 )
return V_91 ;
V_87 = F_2 ( V_2 , V_80 , V_92 ) ;
if ( V_87 < 0 )
return V_91 ;
return ( ( V_86 & V_106 ) || ( V_87 & V_106 ) ) ?
F_30 ( V_2 , V_85 ) :
F_28 ( V_2 , V_85 ) ;
}
static enum V_83 F_32 ( struct V_1 * V_2 ,
enum V_84 * V_85 )
{
int V_86 , V_87 ;
V_86 = F_2 ( V_2 , V_80 , V_103 ) ;
if ( V_86 < 0 )
return V_91 ;
V_87 = F_2 ( V_2 , V_80 , V_107 ) ;
if ( V_87 < 0 )
return V_91 ;
return ( ( V_86 & V_106 ) || ( V_87 & V_106 ) ) ?
F_30 ( V_2 , V_85 ) :
F_28 ( V_2 , V_85 ) ;
}
static enum V_83 F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
enum V_84 * V_85 ;
unsigned long V_108 ;
int V_3 ;
if ( ! V_11 -> V_109 ) {
V_11 -> V_109 = V_110 ;
} else {
V_108 = V_11 -> V_109 +
F_34 ( V_111 ) ;
if ( F_35 ( V_110 , V_108 ) ) {
V_11 -> V_112 = V_113 ;
V_11 -> V_114 = V_113 ;
V_11 -> V_109 = V_110 ;
}
}
V_85 = F_19 ( V_2 ) ? & V_11 -> V_112
: & V_11 -> V_114 ;
switch ( * V_85 ) {
case V_113 :
V_3 = F_31 ( V_2 , V_85 ) ;
break;
case V_100 :
V_3 = F_32 ( V_2 , V_85 ) ;
break;
default:
V_3 = V_91 ;
}
return V_3 ;
}
static enum V_83 F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
if ( F_19 ( V_2 ) ) {
V_11 -> V_112 = V_115 ;
if ( ! ( V_2 -> V_70 & V_116 ) &&
! ( V_2 -> V_70 & V_117 ) )
return V_118 ;
if ( V_11 -> V_114 != V_113 )
return V_118 ;
} else {
V_11 -> V_114 = V_115 ;
if ( ! ( V_2 -> V_70 & V_119 ) )
return V_118 ;
if ( V_11 -> V_112 != V_113 )
return V_118 ;
}
V_3 = F_27 ( V_2 ) ;
if ( V_3 )
return V_91 ;
V_3 = F_20 ( V_2 ) ;
if ( V_3 )
return V_91 ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
return V_91 ;
return V_105 ;
}
static T_2 F_37 ( int V_120 , void * V_121 )
{
struct V_10 * V_11 = (struct V_10 * ) V_121 ;
F_38 ( V_11 -> V_122 ) ;
F_39 ( V_11 -> V_123 , & V_11 -> V_124 ) ;
return V_125 ;
}
static void F_40 ( struct V_126 * V_127 )
{
struct V_10 * V_11 = F_41 ( V_127 ,
struct V_10 ,
V_124 ) ;
F_42 ( & V_11 -> V_128 ) ;
F_39 ( V_11 -> V_123 , & V_11 -> V_128 ) ;
}
static void F_43 ( struct V_126 * V_127 )
{
struct V_10 * V_11 = F_41 ( V_127 ,
struct V_10 ,
V_128 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
enum V_83 V_129 = V_11 -> V_130 ;
int V_131 , V_132 ;
F_44 ( & V_11 -> V_133 ) ;
V_131 = F_2 ( V_2 , V_80 , V_134 ) ;
if ( ! V_131 )
goto V_135;
V_136:
if ( V_131 < 0 ) {
V_11 -> V_130 = V_91 ;
V_132 = V_137 ;
} else if ( V_131 & V_138 ) {
V_11 -> V_130 = V_89 ;
V_132 = V_138 ;
} else if ( V_131 & V_139 ) {
V_11 -> V_130 = V_105 ;
V_132 = V_139 ;
} else if ( V_131 & V_140 ) {
V_11 -> V_130 = V_141 ;
V_132 = V_140 ;
} else {
V_11 -> V_130 = V_91 ;
V_132 = 0 ;
}
V_131 &= ~ V_132 ;
F_3 ( V_2 , V_80 , V_134 , V_131 ) ;
V_11 -> V_142 = V_11 -> V_130 ;
V_143:
V_129 = V_11 -> V_130 ;
switch ( V_11 -> V_130 ) {
case V_144 :
V_11 -> V_145 = 0 ;
break;
case V_89 :
V_11 -> V_130 = F_33 ( V_2 ) ;
V_11 -> V_145 ++ ;
break;
case V_105 :
V_11 -> V_145 = 0 ;
V_11 -> V_146 = 0 ;
V_11 -> V_130 = F_36 ( V_2 ) ;
break;
case V_141 :
V_11 -> V_146 = V_11 -> V_145 ? 0 : 1 ;
F_12 ( V_2 -> V_21 , L_2 ,
V_11 -> V_145 ? L_3
: L_4 ) ;
break;
case V_118 :
break;
default:
V_11 -> V_130 = V_91 ;
}
if ( V_11 -> V_130 == V_118 ) {
V_131 = 0 ;
F_3 ( V_2 , V_80 , V_134 , 0 ) ;
} else if ( V_11 -> V_130 == V_91 ) {
F_45 ( V_2 -> V_21 ,
L_5 ,
V_129 ) ;
V_131 = 0 ;
F_3 ( V_2 , V_80 , V_134 , 0 ) ;
}
if ( V_11 -> V_130 >= V_141 ) {
V_11 -> V_142 = V_11 -> V_130 ;
V_11 -> V_130 = V_144 ;
V_11 -> V_112 = V_113 ;
V_11 -> V_114 = V_113 ;
V_11 -> V_109 = 0 ;
}
if ( V_129 != V_11 -> V_130 )
goto V_143;
if ( V_131 )
goto V_136;
V_135:
F_46 ( V_11 -> V_122 ) ;
F_47 ( & V_11 -> V_133 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_80 , V_90 + 2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_70 & V_147 )
V_3 |= 0xc000 ;
else
V_3 &= ~ 0xc000 ;
F_3 ( V_2 , V_80 , V_90 + 2 , V_3 ) ;
V_3 = F_2 ( V_2 , V_80 , V_90 + 1 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_70 & V_119 )
V_3 |= 0x80 ;
else
V_3 &= ~ 0x80 ;
if ( ( V_2 -> V_70 & V_116 ) ||
( V_2 -> V_70 & V_117 ) )
V_3 |= 0x20 ;
else
V_3 &= ~ 0x20 ;
F_3 ( V_2 , V_80 , V_90 + 1 , V_3 ) ;
V_3 = F_2 ( V_2 , V_80 , V_90 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_70 & V_148 )
V_3 |= 0x400 ;
else
V_3 &= ~ 0x400 ;
if ( V_2 -> V_70 & V_149 )
V_3 |= 0x800 ;
else
V_3 &= ~ 0x800 ;
V_3 &= ~ V_106 ;
F_3 ( V_2 , V_80 , V_90 , V_3 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_150 , V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_151 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_150 = 50 ;
do {
F_50 ( 20 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
} while ( ( V_3 & V_151 ) && -- V_150 );
if ( V_3 & V_151 )
return - V_152 ;
V_3 = F_27 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_80 , V_134 , 0 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_153 * V_154 = V_2 -> V_21 ;
int V_3 ;
if ( ! V_11 -> V_155 ) {
snprintf ( V_11 -> V_156 , sizeof( V_11 -> V_156 ) - 1 ,
L_6 , F_52 ( V_154 ) ) ;
V_11 -> V_123 =
F_53 ( V_11 -> V_156 ) ;
if ( ! V_11 -> V_123 ) {
F_45 ( V_154 , L_7 ) ;
return - V_157 ;
}
V_3 = F_54 ( V_11 -> V_158 , V_11 -> V_122 ,
F_37 , 0 , V_11 -> V_156 ,
V_11 ) ;
if ( V_3 ) {
F_45 ( V_154 , L_8 ) ;
F_55 ( V_11 -> V_123 ) ;
return V_3 ;
}
V_11 -> V_155 = 1 ;
}
if ( F_22 ( V_2 ) )
V_3 = F_14 ( V_2 ) ;
else if ( F_24 ( V_2 ) )
V_3 = F_17 ( V_2 ) ;
else if ( F_23 ( V_2 ) )
V_3 = F_16 ( V_2 ) ;
else
V_3 = - V_159 ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_48 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_2 , V_80 , V_160 , 0x07 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_27 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_2 -> V_72 ) {
case V_73 :
V_3 = F_21 ( V_2 , V_63 ) ;
break;
case V_75 :
case V_77 :
V_3 = F_21 ( V_2 , V_64 ) ;
break;
default:
V_3 = - V_159 ;
}
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_161 != V_162 )
return - V_159 ;
V_2 -> V_163 = 0 ;
V_2 -> V_164 = 0 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_3 V_165 = V_2 -> V_166 . V_167 ;
int V_3 ;
if ( V_2 -> V_68 != V_69 )
return F_56 ( V_2 ) ;
if ( ! ( V_165 & V_168 ) )
return - V_159 ;
F_58 ( V_11 -> V_122 ) ;
if ( V_2 -> V_70 & V_119 )
V_3 = F_21 ( V_2 , V_63 ) ;
else if ( ( V_2 -> V_70 & V_116 ) ||
( V_2 -> V_70 & V_117 ) )
V_3 = F_21 ( V_2 , V_64 ) ;
else
V_3 = - V_159 ;
if ( V_3 < 0 ) {
F_46 ( V_11 -> V_122 ) ;
return V_3 ;
}
V_3 = F_27 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_80 , V_134 , 0 ) ;
V_11 -> V_142 = V_144 ;
V_11 -> V_130 = V_144 ;
V_11 -> V_112 = V_113 ;
V_11 -> V_114 = V_113 ;
F_46 ( V_11 -> V_122 ) ;
V_3 = F_48 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_26 ( V_2 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
F_44 ( & V_11 -> V_133 ) ;
V_3 = F_57 ( V_2 ) ;
F_47 ( & V_11 -> V_133 ) ;
return V_3 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return ( V_11 -> V_142 == V_141 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
if ( V_11 -> V_130 != V_144 ) {
V_2 -> V_169 = 1 ;
return 0 ;
}
V_3 = F_2 ( V_2 , V_7 , V_170 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_170 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_169 = ( V_3 & V_171 ) ? 1 : 0 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_3 V_165 = V_2 -> V_166 . V_167 ;
int V_3 , V_172 , V_173 ;
V_3 = F_61 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_2 -> V_68 == V_69 ) &&
! V_11 -> V_146 ) {
if ( ! ( V_165 & V_168 ) )
return - V_159 ;
if ( ! F_60 ( V_2 ) )
return 0 ;
V_172 = F_2 ( V_2 , V_80 , V_90 ) ;
if ( V_172 < 0 )
return V_172 ;
V_173 = F_2 ( V_2 , V_80 , V_92 ) ;
if ( V_173 < 0 )
return V_173 ;
V_172 &= V_173 ;
V_2 -> V_163 = ( V_172 & 0x400 ) ? 1 : 0 ;
V_2 -> V_164 = ( V_172 & 0x800 ) ? 1 : 0 ;
V_172 = F_2 ( V_2 , V_80 ,
V_90 + 1 ) ;
if ( V_172 < 0 )
return V_172 ;
V_173 = F_2 ( V_2 , V_80 , V_92 + 1 ) ;
if ( V_173 < 0 )
return V_173 ;
V_172 &= V_173 ;
if ( V_172 & 0x80 ) {
V_2 -> V_72 = V_73 ;
V_3 = F_21 ( V_2 , V_63 ) ;
if ( V_3 )
return V_3 ;
} else {
switch ( V_11 -> V_65 ) {
case V_66 :
V_2 -> V_72 = V_77 ;
break;
case V_174 :
V_2 -> V_72 = V_75 ;
break;
}
V_3 = F_21 ( V_2 , V_64 ) ;
if ( V_3 )
return V_3 ;
}
V_2 -> V_161 = V_162 ;
} else {
if ( F_19 ( V_2 ) ) {
V_2 -> V_72 = V_73 ;
} else {
switch ( V_11 -> V_65 ) {
case V_66 :
V_2 -> V_72 = V_77 ;
break;
case V_174 :
V_2 -> V_72 = V_75 ;
break;
}
}
V_2 -> V_161 = V_162 ;
V_2 -> V_163 = 0 ;
V_2 -> V_164 = 0 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
F_44 ( & V_2 -> V_175 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
goto V_176;
V_11 -> V_177 = V_3 ;
V_3 |= V_9 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_3 = 0 ;
V_176:
F_47 ( & V_2 -> V_175 ) ;
return V_3 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_44 ( & V_2 -> V_175 ) ;
V_11 -> V_177 &= ~ V_9 ;
F_3 ( V_2 , V_7 , V_8 , V_11 -> V_177 ) ;
F_47 ( & V_2 -> V_175 ) ;
return 0 ;
}
static unsigned int F_65 ( struct V_178 * V_179 ,
unsigned int type )
{
unsigned int V_150 ;
int V_180 ;
for ( V_180 = 0 , V_150 = 0 ; V_180 < V_179 -> V_181 ; V_180 ++ ) {
struct V_182 * V_183 = & V_179 -> V_182 [ V_180 ] ;
if ( type == F_66 ( V_183 ) )
V_150 ++ ;
}
return V_150 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_178 * V_184 ;
struct V_185 * V_158 , * V_186 ;
unsigned int V_187 , V_188 ;
int V_3 ;
if ( ! V_2 -> V_189 || ! V_2 -> V_189 -> V_190 )
return - V_159 ;
V_158 = V_2 -> V_189 -> V_190 ;
V_11 = F_68 ( V_158 , sizeof( * V_11 ) , V_191 ) ;
if ( ! V_11 )
return - V_157 ;
V_11 -> V_179 = F_69 ( V_158 ) ;
V_11 -> V_192 = F_70 ( V_158 ) ;
V_11 -> V_158 = V_158 ;
V_11 -> V_2 = V_2 ;
F_71 ( & V_11 -> V_133 ) ;
F_72 ( & V_11 -> V_124 , F_40 ) ;
F_72 ( & V_11 -> V_128 , F_43 ) ;
if ( ! V_11 -> V_192 || V_193 ) {
struct V_194 * V_195 ;
struct V_194 * V_196 ;
V_195 = V_11 -> V_158 -> V_197 ;
V_196 = F_73 ( V_195 , L_9 , 0 ) ;
if ( ! V_196 ) {
F_74 ( V_158 , L_10 ) ;
V_3 = - V_159 ;
goto V_198;
}
V_184 = F_75 ( V_196 ) ;
F_76 ( V_196 ) ;
if ( ! V_184 ) {
F_74 ( V_158 , L_11 ) ;
V_3 = - V_159 ;
goto V_198;
}
V_187 = 0 ;
V_188 = 0 ;
} else {
V_184 = V_11 -> V_179 ;
V_187 = F_65 ( V_184 ,
V_199 ) - 3 ;
V_188 = F_65 ( V_184 ,
V_200 ) - 1 ;
}
V_186 = & V_184 -> V_158 ;
V_11 -> V_201 = F_77 ( V_184 , V_199 ,
V_187 ++ ) ;
V_11 -> V_202 = F_78 ( V_158 , V_11 -> V_201 ) ;
if ( F_79 ( V_11 -> V_202 ) ) {
F_74 ( V_158 , L_12 ) ;
V_3 = F_80 ( V_11 -> V_202 ) ;
goto V_203;
}
V_11 -> V_204 = F_77 ( V_184 , V_199 ,
V_187 ++ ) ;
V_11 -> V_205 = F_78 ( V_158 , V_11 -> V_204 ) ;
if ( F_79 ( V_11 -> V_205 ) ) {
F_74 ( V_158 , L_13 ) ;
V_3 = F_80 ( V_11 -> V_205 ) ;
goto V_206;
}
V_11 -> V_207 = F_77 ( V_184 , V_199 ,
V_187 ++ ) ;
V_11 -> V_208 = F_78 ( V_158 , V_11 -> V_207 ) ;
if ( F_79 ( V_11 -> V_208 ) ) {
F_74 ( V_158 , L_14 ) ;
V_3 = F_80 ( V_11 -> V_208 ) ;
goto V_209;
}
V_3 = F_81 ( V_184 , V_188 ) ;
if ( V_3 < 0 ) {
F_74 ( V_158 , L_15 ) ;
goto V_210;
}
V_11 -> V_122 = V_3 ;
V_3 = F_82 ( V_186 , V_211 ,
& V_11 -> V_65 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_211 ) ;
goto V_210;
}
switch ( V_11 -> V_65 ) {
case V_66 :
case V_174 :
break;
default:
F_74 ( V_158 , L_16 ,
V_211 ) ;
V_3 = - V_159 ;
goto V_210;
}
if ( F_83 ( V_186 , V_212 ) ) {
V_3 = F_84 ( V_186 ,
V_212 ,
V_11 -> V_42 ,
V_213 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_212 ) ;
goto V_210;
}
} else {
memcpy ( V_11 -> V_42 , V_214 ,
sizeof( V_11 -> V_42 ) ) ;
}
if ( F_83 ( V_186 , V_215 ) ) {
V_3 = F_84 ( V_186 ,
V_215 ,
V_11 -> V_36 ,
V_213 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_215 ) ;
goto V_210;
}
} else {
memcpy ( V_11 -> V_36 , V_216 ,
sizeof( V_11 -> V_36 ) ) ;
}
if ( F_83 ( V_186 , V_217 ) ) {
V_3 = F_84 ( V_186 ,
V_217 ,
V_11 -> V_45 ,
V_213 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_217 ) ;
goto V_210;
}
} else {
memcpy ( V_11 -> V_45 , V_218 ,
sizeof( V_11 -> V_45 ) ) ;
}
if ( F_83 ( V_186 , V_219 ) ) {
V_3 = F_84 ( V_186 ,
V_219 ,
V_11 -> V_39 ,
V_213 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_219 ) ;
goto V_210;
}
} else {
memcpy ( V_11 -> V_39 , V_220 ,
sizeof( V_11 -> V_39 ) ) ;
}
if ( F_83 ( V_186 , V_221 ) ) {
V_3 = F_84 ( V_186 ,
V_221 ,
V_11 -> V_48 ,
V_213 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_221 ) ;
goto V_210;
}
} else {
memcpy ( V_11 -> V_48 ,
V_222 ,
sizeof( V_11 -> V_48 ) ) ;
}
if ( F_83 ( V_186 , V_223 ) ) {
V_3 = F_84 ( V_186 ,
V_223 ,
V_11 -> V_50 ,
V_213 ) ;
if ( V_3 ) {
F_74 ( V_158 , L_16 ,
V_223 ) ;
goto V_210;
}
} else {
memcpy ( V_11 -> V_50 ,
V_224 ,
sizeof( V_11 -> V_50 ) ) ;
}
V_2 -> V_225 = V_226 ;
V_2 -> V_225 |= V_148 | V_149 ;
V_2 -> V_225 |= V_227 ;
V_2 -> V_225 |= V_119 ;
switch ( V_11 -> V_65 ) {
case V_66 :
V_2 -> V_225 |= V_116 ;
break;
case V_174 :
V_2 -> V_225 |= V_117 ;
break;
}
V_3 = F_2 ( V_2 , V_4 , V_228 ) ;
if ( V_3 < 0 )
return V_3 ;
V_11 -> V_95 = V_3 & V_94 ;
if ( V_11 -> V_95 & V_229 )
V_2 -> V_225 |= V_147 ;
V_2 -> V_70 = V_2 -> V_225 ;
V_2 -> V_11 = V_11 ;
if ( ! V_11 -> V_192 || V_193 )
F_85 ( V_184 ) ;
return 0 ;
V_210:
F_86 ( V_158 , V_11 -> V_208 ) ;
F_87 ( V_158 , V_11 -> V_207 -> V_230 ,
F_88 ( V_11 -> V_207 ) ) ;
V_209:
F_86 ( V_158 , V_11 -> V_205 ) ;
F_87 ( V_158 , V_11 -> V_204 -> V_230 ,
F_88 ( V_11 -> V_204 ) ) ;
V_206:
F_86 ( V_158 , V_11 -> V_202 ) ;
F_87 ( V_158 , V_11 -> V_201 -> V_230 ,
F_88 ( V_11 -> V_201 ) ) ;
V_203:
if ( ! V_11 -> V_192 || V_193 )
F_85 ( V_184 ) ;
V_198:
F_89 ( V_158 , V_11 ) ;
return V_3 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_185 * V_158 = V_11 -> V_158 ;
if ( V_11 -> V_155 ) {
F_91 ( V_158 , V_11 -> V_122 , V_11 ) ;
F_92 ( V_11 -> V_123 ) ;
F_55 ( V_11 -> V_123 ) ;
}
F_86 ( V_158 , V_11 -> V_208 ) ;
F_87 ( V_158 , V_11 -> V_207 -> V_230 ,
F_88 ( V_11 -> V_207 ) ) ;
F_86 ( V_158 , V_11 -> V_205 ) ;
F_87 ( V_158 , V_11 -> V_204 -> V_230 ,
F_88 ( V_11 -> V_204 ) ) ;
F_86 ( V_158 , V_11 -> V_202 ) ;
F_87 ( V_158 , V_11 -> V_201 -> V_230 ,
F_88 ( V_11 -> V_201 ) ) ;
F_89 ( V_158 , V_11 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
return V_2 -> V_166 . V_231 [ V_7 ] == V_232 ;
}
