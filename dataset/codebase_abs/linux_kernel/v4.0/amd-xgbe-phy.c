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
static int F_22 ( struct V_1 * V_2 , bool V_68 ,
bool V_69 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_70 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_71 ;
if ( V_68 )
V_3 |= V_71 ;
if ( V_69 )
V_3 |= V_72 ;
F_3 ( V_2 , V_70 , V_8 , V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , true , true ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , false , false ) ;
}
static enum V_73 F_25 ( struct V_1 * V_2 ,
enum V_74 * V_75 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_76 , V_77 , V_3 ;
* V_75 = V_78 ;
if ( ! F_19 ( V_2 ) )
return V_79 ;
V_76 = F_2 ( V_2 , V_70 , V_80 + 2 ) ;
if ( V_76 < 0 )
return V_81 ;
V_77 = F_2 ( V_2 , V_70 , V_82 + 2 ) ;
if ( V_77 < 0 )
return V_81 ;
V_3 = F_2 ( V_2 , V_4 , V_83 ) ;
if ( V_3 < 0 )
return V_81 ;
V_3 &= ~ V_84 ;
if ( ( V_76 & 0xc000 ) && ( V_77 & 0xc000 ) )
V_3 |= V_11 -> V_85 ;
F_3 ( V_2 , V_4 , V_83 , V_3 ) ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_81 ;
if ( V_3 & V_6 ) {
F_26 ( V_11 , V_86 , V_87 , 1 ) ;
V_3 |= V_88 ;
F_3 ( V_2 , V_4 , V_5 ,
V_3 ) ;
F_26 ( V_11 , V_86 , V_87 , 0 ) ;
}
return V_79 ;
}
static enum V_73 F_27 ( struct V_1 * V_2 ,
enum V_74 * V_75 )
{
T_1 V_89 ;
* V_75 = V_90 ;
V_89 = V_91 ;
V_89 |= V_92 ;
F_3 ( V_2 , V_70 , V_93 + 2 , 0 ) ;
F_3 ( V_2 , V_70 , V_93 + 1 , 0 ) ;
F_3 ( V_2 , V_70 , V_93 , V_89 ) ;
return V_79 ;
}
static enum V_73 F_28 ( struct V_1 * V_2 ,
enum V_74 * V_75 )
{
unsigned int V_94 ;
int V_3 , V_76 , V_77 ;
V_3 = F_2 ( V_2 , V_70 , V_82 + 1 ) ;
if ( V_3 < 0 )
return V_81 ;
V_94 = F_19 ( V_2 ) ? 0x80 : 0x20 ;
if ( ! ( V_3 & V_94 ) )
return V_95 ;
V_76 = F_2 ( V_2 , V_70 , V_80 ) ;
if ( V_76 < 0 )
return V_81 ;
V_77 = F_2 ( V_2 , V_70 , V_82 ) ;
if ( V_77 < 0 )
return V_81 ;
return ( ( V_76 & V_96 ) || ( V_77 & V_96 ) ) ?
F_27 ( V_2 , V_75 ) :
F_25 ( V_2 , V_75 ) ;
}
static enum V_73 F_29 ( struct V_1 * V_2 ,
enum V_74 * V_75 )
{
int V_76 , V_77 ;
V_76 = F_2 ( V_2 , V_70 , V_93 ) ;
if ( V_76 < 0 )
return V_81 ;
V_77 = F_2 ( V_2 , V_70 , V_97 ) ;
if ( V_77 < 0 )
return V_81 ;
return ( ( V_76 & V_96 ) || ( V_77 & V_96 ) ) ?
F_27 ( V_2 , V_75 ) :
F_25 ( V_2 , V_75 ) ;
}
static enum V_73 F_30 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
enum V_74 * V_75 ;
int V_3 ;
V_75 = F_19 ( V_2 ) ? & V_11 -> V_98
: & V_11 -> V_99 ;
switch ( * V_75 ) {
case V_100 :
V_3 = F_28 ( V_2 , V_75 ) ;
break;
case V_90 :
V_3 = F_29 ( V_2 , V_75 ) ;
break;
default:
V_3 = V_81 ;
}
return V_3 ;
}
static enum V_73 F_31 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
if ( F_19 ( V_2 ) ) {
V_11 -> V_98 = V_101 ;
if ( ! ( V_2 -> V_102 & V_103 ) &&
! ( V_2 -> V_102 & V_104 ) )
return V_105 ;
if ( V_11 -> V_99 != V_100 )
return V_105 ;
} else {
V_11 -> V_99 = V_101 ;
if ( ! ( V_2 -> V_102 & V_106 ) )
return V_105 ;
if ( V_11 -> V_98 != V_100 )
return V_105 ;
}
V_3 = F_24 ( V_2 ) ;
if ( V_3 )
return V_81 ;
V_3 = F_20 ( V_2 ) ;
if ( V_3 )
return V_81 ;
V_3 = F_23 ( V_2 ) ;
if ( V_3 )
return V_81 ;
return V_95 ;
}
static T_2 F_32 ( int V_107 , void * V_108 )
{
struct V_10 * V_11 = (struct V_10 * ) V_108 ;
F_33 ( V_11 -> V_109 ) ;
F_34 ( V_11 -> V_110 , & V_11 -> V_111 ) ;
return V_112 ;
}
static void F_35 ( struct V_113 * V_114 )
{
struct V_10 * V_11 = F_36 ( V_114 ,
struct V_10 ,
V_111 ) ;
F_37 ( & V_11 -> V_115 ) ;
F_34 ( V_11 -> V_110 , & V_11 -> V_115 ) ;
}
static void F_38 ( struct V_113 * V_114 )
{
struct V_10 * V_11 = F_36 ( V_114 ,
struct V_10 ,
V_115 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
enum V_73 V_116 = V_11 -> V_117 ;
int V_118 , V_119 ;
F_39 ( & V_11 -> V_120 ) ;
V_118 = F_2 ( V_2 , V_70 , V_121 ) ;
if ( ! V_118 )
goto V_122;
V_123:
if ( V_118 < 0 ) {
V_11 -> V_117 = V_81 ;
V_119 = V_124 ;
} else if ( V_118 & V_125 ) {
V_11 -> V_117 = V_79 ;
V_119 = V_125 ;
} else if ( V_118 & V_126 ) {
V_11 -> V_117 = V_95 ;
V_119 = V_126 ;
} else if ( V_118 & V_127 ) {
V_11 -> V_117 = V_128 ;
V_119 = V_127 ;
} else {
V_11 -> V_117 = V_81 ;
V_119 = 0 ;
}
V_118 &= ~ V_119 ;
F_3 ( V_2 , V_70 , V_121 , V_118 ) ;
V_11 -> V_129 = V_11 -> V_117 ;
V_130:
V_116 = V_11 -> V_117 ;
switch ( V_11 -> V_117 ) {
case V_131 :
V_11 -> V_132 = 0 ;
break;
case V_79 :
V_11 -> V_117 = F_30 ( V_2 ) ;
V_11 -> V_132 ++ ;
break;
case V_95 :
V_11 -> V_132 = 0 ;
V_11 -> V_133 = 0 ;
V_11 -> V_117 = F_31 ( V_2 ) ;
break;
case V_128 :
V_11 -> V_133 = V_11 -> V_132 ? 0 : 1 ;
F_12 ( V_2 -> V_21 , L_2 ,
V_11 -> V_132 ? L_3
: L_4 ) ;
break;
case V_105 :
break;
default:
V_11 -> V_117 = V_81 ;
}
if ( V_11 -> V_117 == V_105 ) {
V_118 = 0 ;
F_3 ( V_2 , V_70 , V_121 , 0 ) ;
} else if ( V_11 -> V_117 == V_81 ) {
F_40 ( V_2 -> V_21 ,
L_5 ,
V_116 ) ;
V_118 = 0 ;
F_3 ( V_2 , V_70 , V_121 , 0 ) ;
}
if ( V_11 -> V_117 >= V_128 ) {
V_11 -> V_129 = V_11 -> V_117 ;
V_11 -> V_117 = V_131 ;
V_11 -> V_98 = V_100 ;
V_11 -> V_99 = V_100 ;
}
if ( V_116 != V_11 -> V_117 )
goto V_130;
if ( V_118 )
goto V_123;
V_122:
F_41 ( V_11 -> V_109 ) ;
F_42 ( & V_11 -> V_120 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_70 , V_80 + 2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_102 & V_134 )
V_3 |= 0xc000 ;
else
V_3 &= ~ 0xc000 ;
F_3 ( V_2 , V_70 , V_80 + 2 , V_3 ) ;
V_3 = F_2 ( V_2 , V_70 , V_80 + 1 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_102 & V_106 )
V_3 |= 0x80 ;
else
V_3 &= ~ 0x80 ;
if ( ( V_2 -> V_102 & V_103 ) ||
( V_2 -> V_102 & V_104 ) )
V_3 |= 0x20 ;
else
V_3 &= ~ 0x20 ;
F_3 ( V_2 , V_70 , V_80 + 1 , V_3 ) ;
V_3 = F_2 ( V_2 , V_70 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_102 & V_135 )
V_3 |= 0x400 ;
else
V_3 &= ~ 0x400 ;
if ( V_2 -> V_102 & V_136 )
V_3 |= 0x800 ;
else
V_3 &= ~ 0x800 ;
V_3 &= ~ V_96 ;
F_3 ( V_2 , V_70 , V_80 , V_3 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_137 , V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 |= V_138 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_137 = 50 ;
do {
F_45 ( 20 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
} while ( ( V_3 & V_138 ) && -- V_137 );
if ( V_3 & V_138 )
return - V_139 ;
V_3 = F_24 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_70 , V_121 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_140 * V_141 = V_2 -> V_21 ;
int V_3 ;
if ( ! V_11 -> V_142 ) {
snprintf ( V_11 -> V_143 , sizeof( V_11 -> V_143 ) - 1 ,
L_6 , F_47 ( V_141 ) ) ;
V_11 -> V_110 =
F_48 ( V_11 -> V_143 ) ;
if ( ! V_11 -> V_110 ) {
F_40 ( V_141 , L_7 ) ;
return - V_144 ;
}
V_3 = F_49 ( V_11 -> V_145 , V_11 -> V_109 ,
F_32 , 0 , V_11 -> V_143 ,
V_11 ) ;
if ( V_3 ) {
F_40 ( V_141 , L_8 ) ;
F_50 ( V_11 -> V_110 ) ;
return V_3 ;
}
V_11 -> V_142 = 1 ;
}
V_3 = F_2 ( V_2 , V_4 , V_146 ) ;
if ( V_3 < 0 )
return V_3 ;
V_11 -> V_85 = V_3 & V_84 ;
V_2 -> V_102 = V_147 ;
V_2 -> V_102 |= V_135 | V_136 ;
V_2 -> V_102 |= V_148 ;
V_2 -> V_102 |= V_106 ;
switch ( V_11 -> V_65 ) {
case V_66 :
V_2 -> V_102 |= V_103 ;
break;
case V_149 :
V_2 -> V_102 |= V_104 ;
break;
}
if ( V_11 -> V_85 & V_150 )
V_2 -> V_102 |= V_134 ;
V_2 -> V_151 = V_2 -> V_102 ;
if ( V_2 -> V_102 & V_106 )
V_3 = F_14 ( V_2 ) ;
else if ( V_2 -> V_102 & V_103 )
V_3 = F_17 ( V_2 ) ;
else if ( V_2 -> V_102 & V_104 )
V_3 = F_16 ( V_2 ) ;
else
V_3 = - V_152 ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_43 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_2 , V_70 , V_153 , 0x07 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_24 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_2 -> V_154 ) {
case V_155 :
V_3 = F_21 ( V_2 , V_63 ) ;
break;
case V_156 :
case V_157 :
V_3 = F_21 ( V_2 , V_64 ) ;
break;
default:
V_3 = - V_152 ;
}
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_158 != V_159 )
return - V_152 ;
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_3 V_162 = V_2 -> V_163 . V_164 ;
int V_3 ;
if ( V_2 -> V_165 != V_166 )
return F_51 ( V_2 ) ;
if ( ! ( V_162 & V_167 ) )
return - V_152 ;
F_53 ( V_11 -> V_109 ) ;
if ( V_2 -> V_102 & V_106 )
V_3 = F_21 ( V_2 , V_63 ) ;
else if ( ( V_2 -> V_102 & V_103 ) ||
( V_2 -> V_102 & V_104 ) )
V_3 = F_21 ( V_2 , V_64 ) ;
else
V_3 = - V_152 ;
if ( V_3 < 0 ) {
F_41 ( V_11 -> V_109 ) ;
return V_3 ;
}
V_3 = F_24 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_70 , V_121 , 0 ) ;
V_11 -> V_129 = V_131 ;
V_11 -> V_117 = V_131 ;
V_11 -> V_98 = V_100 ;
V_11 -> V_99 = V_100 ;
F_41 ( V_11 -> V_109 ) ;
V_3 = F_43 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_23 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
F_39 ( & V_11 -> V_120 ) ;
V_3 = F_52 ( V_2 ) ;
F_42 ( & V_11 -> V_120 ) ;
return V_3 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
return ( V_11 -> V_129 == V_128 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
if ( V_11 -> V_117 != V_131 ) {
V_2 -> V_168 = 1 ;
return 0 ;
}
V_3 = F_2 ( V_2 , V_7 , V_169 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_7 , V_169 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_168 = ( V_3 & V_170 ) ? 1 : 0 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_3 V_162 = V_2 -> V_163 . V_164 ;
int V_3 , V_171 , V_172 ;
V_3 = F_56 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_2 -> V_165 == V_166 ) &&
! V_11 -> V_133 ) {
if ( ! ( V_162 & V_167 ) )
return - V_152 ;
if ( ! F_55 ( V_2 ) )
return 0 ;
V_171 = F_2 ( V_2 , V_70 , V_80 ) ;
if ( V_171 < 0 )
return V_171 ;
V_172 = F_2 ( V_2 , V_70 , V_82 ) ;
if ( V_172 < 0 )
return V_172 ;
V_171 &= V_172 ;
V_2 -> V_160 = ( V_171 & 0x400 ) ? 1 : 0 ;
V_2 -> V_161 = ( V_171 & 0x800 ) ? 1 : 0 ;
V_171 = F_2 ( V_2 , V_70 ,
V_80 + 1 ) ;
if ( V_171 < 0 )
return V_171 ;
V_172 = F_2 ( V_2 , V_70 , V_82 + 1 ) ;
if ( V_172 < 0 )
return V_172 ;
V_171 &= V_172 ;
if ( V_171 & 0x80 ) {
V_2 -> V_154 = V_155 ;
V_3 = F_21 ( V_2 , V_63 ) ;
if ( V_3 )
return V_3 ;
} else {
switch ( V_11 -> V_65 ) {
case V_66 :
V_2 -> V_154 = V_157 ;
break;
case V_149 :
V_2 -> V_154 = V_156 ;
break;
}
V_3 = F_21 ( V_2 , V_64 ) ;
if ( V_3 )
return V_3 ;
}
V_2 -> V_158 = V_159 ;
} else {
if ( F_19 ( V_2 ) ) {
V_2 -> V_154 = V_155 ;
} else {
switch ( V_11 -> V_65 ) {
case V_66 :
V_2 -> V_154 = V_157 ;
break;
case V_149 :
V_2 -> V_154 = V_156 ;
break;
}
}
V_2 -> V_158 = V_159 ;
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 ;
F_39 ( & V_2 -> V_173 ) ;
V_3 = F_2 ( V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
goto V_174;
V_11 -> V_175 = V_3 ;
V_3 |= V_9 ;
F_3 ( V_2 , V_7 , V_8 , V_3 ) ;
V_3 = 0 ;
V_174:
F_42 ( & V_2 -> V_173 ) ;
return V_3 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_39 ( & V_2 -> V_173 ) ;
V_11 -> V_175 &= ~ V_9 ;
F_3 ( V_2 , V_7 , V_8 , V_11 -> V_175 ) ;
F_42 ( & V_2 -> V_173 ) ;
return 0 ;
}
static unsigned int F_60 ( struct V_176 * V_177 ,
unsigned int type )
{
unsigned int V_137 ;
int V_178 ;
for ( V_178 = 0 , V_137 = 0 ; V_178 < V_177 -> V_179 ; V_178 ++ ) {
struct V_180 * V_181 = & V_177 -> V_180 [ V_178 ] ;
if ( type == F_61 ( V_181 ) )
V_137 ++ ;
}
return V_137 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_176 * V_182 ;
struct V_183 * V_145 , * V_184 ;
unsigned int V_185 , V_186 ;
int V_3 ;
if ( ! V_2 -> V_187 || ! V_2 -> V_187 -> V_188 )
return - V_152 ;
V_145 = V_2 -> V_187 -> V_188 ;
V_11 = F_63 ( V_145 , sizeof( * V_11 ) , V_189 ) ;
if ( ! V_11 )
return - V_144 ;
V_11 -> V_177 = F_64 ( V_145 ) ;
V_11 -> V_190 = F_65 ( V_145 ) ;
V_11 -> V_145 = V_145 ;
V_11 -> V_2 = V_2 ;
F_66 ( & V_11 -> V_120 ) ;
F_67 ( & V_11 -> V_111 , F_35 ) ;
F_67 ( & V_11 -> V_115 , F_38 ) ;
if ( ! V_11 -> V_190 || V_191 ) {
struct V_192 * V_193 ;
struct V_192 * V_194 ;
V_193 = V_11 -> V_145 -> V_195 ;
V_194 = F_68 ( V_193 , L_9 , 0 ) ;
if ( ! V_194 ) {
F_69 ( V_145 , L_10 ) ;
V_3 = - V_152 ;
goto V_196;
}
V_182 = F_70 ( V_194 ) ;
F_71 ( V_194 ) ;
if ( ! V_182 ) {
F_69 ( V_145 , L_11 ) ;
V_3 = - V_152 ;
goto V_196;
}
V_185 = 0 ;
V_186 = 0 ;
} else {
V_182 = V_11 -> V_177 ;
V_185 = F_60 ( V_182 ,
V_197 ) - 3 ;
V_186 = F_60 ( V_182 ,
V_198 ) - 1 ;
}
V_184 = & V_182 -> V_145 ;
V_11 -> V_199 = F_72 ( V_182 , V_197 ,
V_185 ++ ) ;
V_11 -> V_200 = F_73 ( V_145 , V_11 -> V_199 ) ;
if ( F_74 ( V_11 -> V_200 ) ) {
F_69 ( V_145 , L_12 ) ;
V_3 = F_75 ( V_11 -> V_200 ) ;
goto V_201;
}
V_11 -> V_202 = F_72 ( V_182 , V_197 ,
V_185 ++ ) ;
V_11 -> V_203 = F_73 ( V_145 , V_11 -> V_202 ) ;
if ( F_74 ( V_11 -> V_203 ) ) {
F_69 ( V_145 , L_13 ) ;
V_3 = F_75 ( V_11 -> V_203 ) ;
goto V_204;
}
V_11 -> V_205 = F_72 ( V_182 , V_197 ,
V_185 ++ ) ;
V_11 -> V_206 = F_73 ( V_145 , V_11 -> V_205 ) ;
if ( F_74 ( V_11 -> V_206 ) ) {
F_69 ( V_145 , L_14 ) ;
V_3 = F_75 ( V_11 -> V_206 ) ;
goto V_207;
}
V_3 = F_76 ( V_182 , V_186 ) ;
if ( V_3 < 0 ) {
F_69 ( V_145 , L_15 ) ;
goto V_208;
}
V_11 -> V_109 = V_3 ;
V_3 = F_77 ( V_184 , V_209 ,
& V_11 -> V_65 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_209 ) ;
goto V_208;
}
switch ( V_11 -> V_65 ) {
case V_66 :
case V_149 :
break;
default:
F_69 ( V_145 , L_16 ,
V_209 ) ;
V_3 = - V_152 ;
goto V_208;
}
if ( F_78 ( V_184 , V_210 ) ) {
V_3 = F_79 ( V_184 ,
V_210 ,
V_11 -> V_42 ,
V_211 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_210 ) ;
goto V_208;
}
} else {
memcpy ( V_11 -> V_42 , V_212 ,
sizeof( V_11 -> V_42 ) ) ;
}
if ( F_78 ( V_184 , V_213 ) ) {
V_3 = F_79 ( V_184 ,
V_213 ,
V_11 -> V_36 ,
V_211 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_213 ) ;
goto V_208;
}
} else {
memcpy ( V_11 -> V_36 , V_214 ,
sizeof( V_11 -> V_36 ) ) ;
}
if ( F_78 ( V_184 , V_215 ) ) {
V_3 = F_79 ( V_184 ,
V_215 ,
V_11 -> V_45 ,
V_211 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_215 ) ;
goto V_208;
}
} else {
memcpy ( V_11 -> V_45 , V_216 ,
sizeof( V_11 -> V_45 ) ) ;
}
if ( F_78 ( V_184 , V_217 ) ) {
V_3 = F_79 ( V_184 ,
V_217 ,
V_11 -> V_39 ,
V_211 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_217 ) ;
goto V_208;
}
} else {
memcpy ( V_11 -> V_39 , V_218 ,
sizeof( V_11 -> V_39 ) ) ;
}
if ( F_78 ( V_184 , V_219 ) ) {
V_3 = F_79 ( V_184 ,
V_219 ,
V_11 -> V_48 ,
V_211 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_219 ) ;
goto V_208;
}
} else {
memcpy ( V_11 -> V_48 ,
V_220 ,
sizeof( V_11 -> V_48 ) ) ;
}
if ( F_78 ( V_184 , V_221 ) ) {
V_3 = F_79 ( V_184 ,
V_221 ,
V_11 -> V_50 ,
V_211 ) ;
if ( V_3 ) {
F_69 ( V_145 , L_16 ,
V_221 ) ;
goto V_208;
}
} else {
memcpy ( V_11 -> V_50 ,
V_222 ,
sizeof( V_11 -> V_50 ) ) ;
}
V_2 -> V_11 = V_11 ;
if ( ! V_11 -> V_190 || V_191 )
F_80 ( V_182 ) ;
return 0 ;
V_208:
F_81 ( V_145 , V_11 -> V_206 ) ;
F_82 ( V_145 , V_11 -> V_205 -> V_223 ,
F_83 ( V_11 -> V_205 ) ) ;
V_207:
F_81 ( V_145 , V_11 -> V_203 ) ;
F_82 ( V_145 , V_11 -> V_202 -> V_223 ,
F_83 ( V_11 -> V_202 ) ) ;
V_204:
F_81 ( V_145 , V_11 -> V_200 ) ;
F_82 ( V_145 , V_11 -> V_199 -> V_223 ,
F_83 ( V_11 -> V_199 ) ) ;
V_201:
if ( ! V_11 -> V_190 || V_191 )
F_80 ( V_182 ) ;
V_196:
F_84 ( V_145 , V_11 ) ;
return V_3 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_183 * V_145 = V_11 -> V_145 ;
if ( V_11 -> V_142 ) {
F_86 ( V_145 , V_11 -> V_109 , V_11 ) ;
F_87 ( V_11 -> V_110 ) ;
F_50 ( V_11 -> V_110 ) ;
}
F_81 ( V_145 , V_11 -> V_206 ) ;
F_82 ( V_145 , V_11 -> V_205 -> V_223 ,
F_83 ( V_11 -> V_205 ) ) ;
F_81 ( V_145 , V_11 -> V_203 ) ;
F_82 ( V_145 , V_11 -> V_202 -> V_223 ,
F_83 ( V_11 -> V_202 ) ) ;
F_81 ( V_145 , V_11 -> V_200 ) ;
F_82 ( V_145 , V_11 -> V_199 -> V_223 ,
F_83 ( V_11 -> V_199 ) ) ;
F_84 ( V_145 , V_11 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
return V_2 -> V_163 . V_224 [ V_7 ] == V_225 ;
}
