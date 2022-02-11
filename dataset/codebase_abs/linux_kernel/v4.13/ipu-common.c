static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
void F_6 ( struct V_1 * V_2 , bool V_7 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
V_8 &= ~ V_10 ;
V_8 |= V_7 ? V_11 :
V_12 ;
F_3 ( V_2 , V_8 , V_9 ) ;
}
enum V_13 F_7 ( T_1 V_14 )
{
switch ( V_14 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return V_38 ;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return V_51 ;
default:
return V_52 ;
}
}
enum V_13 F_8 ( T_1 V_53 )
{
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return V_51 ;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
return V_38 ;
default:
return V_52 ;
}
}
bool F_9 ( T_1 V_53 )
{
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return true ;
}
return false ;
}
enum V_13 F_10 ( T_1 V_68 )
{
switch ( V_68 & 0xf000 ) {
case 0x1000 :
return V_38 ;
case 0x2000 :
return V_51 ;
default:
return V_52 ;
}
}
int F_11 ( T_1 V_69 , T_1 V_53 )
{
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return ( 8 * V_69 ) >> 3 ;
case V_67 :
case V_58 :
case V_57 :
return ( 16 * V_69 ) >> 3 ;
case V_66 :
case V_65 :
return ( 24 * V_69 ) >> 3 ;
case V_64 :
case V_63 :
return ( 32 * V_69 ) >> 3 ;
default:
break;
}
return - V_70 ;
}
int F_12 ( enum V_71 * V_72 , int V_73 ,
bool V_74 , bool V_75 )
{
T_1 V_76 , V_77 , V_78 ;
switch ( V_73 ) {
case 0 :
V_77 = V_78 = V_76 = 0 ;
break;
case 90 :
V_77 = V_78 = 0 ;
V_76 = 1 ;
break;
case 180 :
V_77 = V_78 = 1 ;
V_76 = 0 ;
break;
case 270 :
V_77 = V_78 = V_76 = 1 ;
break;
default:
return - V_70 ;
}
V_78 ^= ( T_1 ) V_74 ;
V_77 ^= ( T_1 ) V_75 ;
* V_72 = (enum V_71 ) ( ( V_76 << 2 ) | ( V_78 << 1 ) | V_77 ) ;
return 0 ;
}
int F_13 ( int * V_73 , enum V_71 V_72 ,
bool V_74 , bool V_75 )
{
T_1 V_76 , V_77 , V_78 ;
V_76 = ( ( T_1 ) V_72 >> 2 ) & 0x1 ;
V_78 = ( ( T_1 ) V_72 >> 1 ) & 0x1 ;
V_77 = ( ( T_1 ) V_72 >> 0 ) & 0x1 ;
V_78 ^= ( T_1 ) V_74 ;
V_77 ^= ( T_1 ) V_75 ;
switch ( (enum V_71 ) ( ( V_76 << 2 ) | ( V_78 << 1 ) | V_77 ) ) {
case V_79 :
* V_73 = 0 ;
break;
case V_80 :
* V_73 = 90 ;
break;
case V_81 :
* V_73 = 180 ;
break;
case V_82 :
* V_73 = 270 ;
break;
default:
return - V_70 ;
}
return 0 ;
}
struct V_83 * F_14 ( struct V_1 * V_2 , unsigned V_84 )
{
struct V_83 * V_85 ;
F_15 ( V_2 -> V_86 , L_1 , V_87 , V_84 ) ;
if ( V_84 > 63 )
return F_16 ( - V_88 ) ;
F_17 ( & V_2 -> V_89 ) ;
F_18 (channel, &ipu->channels, list) {
if ( V_85 -> V_84 == V_84 ) {
V_85 = F_16 ( - V_90 ) ;
goto V_91;
}
}
V_85 = F_19 ( sizeof( * V_85 ) , V_92 ) ;
if ( ! V_85 ) {
V_85 = F_16 ( - V_93 ) ;
goto V_91;
}
V_85 -> V_84 = V_84 ;
V_85 -> V_2 = V_2 ;
F_20 ( & V_85 -> V_94 , & V_2 -> V_95 ) ;
V_91:
F_21 ( & V_2 -> V_89 ) ;
return V_85 ;
}
void F_22 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
F_15 ( V_2 -> V_86 , L_1 , V_87 , V_85 -> V_84 ) ;
F_17 ( & V_2 -> V_89 ) ;
F_23 ( & V_85 -> V_94 ) ;
F_24 ( V_85 ) ;
F_21 ( & V_2 -> V_89 ) ;
}
static void F_25 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_96 = V_85 -> V_84 ;
F_3 ( V_2 , F_26 ( V_96 ) , F_27 ( V_96 ) ) ;
}
void F_28 ( struct V_83 * V_85 ,
bool V_97 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_98 ;
T_1 V_99 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_99 = F_1 ( V_2 , F_30 ( V_85 -> V_84 ) ) ;
if ( V_97 )
V_99 |= F_26 ( V_85 -> V_84 ) ;
else
V_99 &= ~ F_26 ( V_85 -> V_84 ) ;
F_3 ( V_2 , V_99 , F_30 ( V_85 -> V_84 ) ) ;
F_25 ( V_85 ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
}
int F_32 ( struct V_83 * V_85 , int V_101 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_98 ;
T_1 V_102 , V_103 ;
int V_104 ;
switch ( V_101 ) {
case 0 :
case 1 :
V_102 = 0x00 ;
break;
case 2 :
V_102 = 0x01 ;
break;
case 4 :
V_102 = 0x02 ;
break;
case 8 :
V_102 = 0x03 ;
break;
default:
return - V_70 ;
}
for ( V_104 = 0 ; V_104 < F_33 ( V_105 ) ; V_104 ++ ) {
if ( V_85 -> V_84 == V_105 [ V_104 ] . V_106 )
break;
}
if ( V_104 >= F_33 ( V_105 ) )
return - V_70 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_103 = F_34 ( V_2 , V_105 [ V_104 ] . V_99 ) ;
V_103 &= ~ ( 0x03 << V_105 [ V_104 ] . V_107 ) ;
V_103 |= ( V_102 << V_105 [ V_104 ] . V_107 ) ;
F_35 ( V_2 , V_103 , V_105 [ V_104 ] . V_99 ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_108 )
{
unsigned long V_109 ;
T_1 V_8 ;
F_29 ( & V_2 -> V_100 , V_109 ) ;
V_8 = F_1 ( V_2 , V_110 ) ;
if ( V_108 & V_111 )
V_8 |= V_112 ;
if ( V_108 & V_113 )
V_8 |= V_114 ;
F_3 ( V_2 , V_8 , V_110 ) ;
V_8 = F_1 ( V_2 , V_115 ) ;
V_8 |= V_108 ;
F_3 ( V_2 , V_8 , V_115 ) ;
F_31 ( & V_2 -> V_100 , V_109 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_108 )
{
unsigned long V_109 ;
T_1 V_8 ;
F_29 ( & V_2 -> V_100 , V_109 ) ;
V_8 = F_1 ( V_2 , V_115 ) ;
V_8 &= ~ V_108 ;
F_3 ( V_2 , V_8 , V_115 ) ;
V_8 = F_1 ( V_2 , V_110 ) ;
if ( V_108 & V_111 )
V_8 &= ~ V_112 ;
if ( V_108 & V_113 )
V_8 &= ~ V_114 ;
F_3 ( V_2 , V_8 , V_110 ) ;
F_31 ( & V_2 -> V_100 , V_109 ) ;
return 0 ;
}
int F_38 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_96 = V_85 -> V_84 ;
return ( F_1 ( V_2 , F_27 ( V_96 ) ) & F_26 ( V_96 ) ) ? 1 : 0 ;
}
bool F_39 ( struct V_83 * V_85 , T_1 V_116 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_98 ;
T_1 V_99 = 0 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
switch ( V_116 ) {
case 0 :
V_99 = F_1 ( V_2 , F_40 ( V_85 -> V_84 ) ) ;
break;
case 1 :
V_99 = F_1 ( V_2 , F_41 ( V_85 -> V_84 ) ) ;
break;
case 2 :
V_99 = F_1 ( V_2 , F_42 ( V_85 -> V_84 ) ) ;
break;
}
F_31 ( & V_2 -> V_100 , V_98 ) ;
return ( ( V_99 & F_26 ( V_85 -> V_84 ) ) != 0 ) ;
}
void F_43 ( struct V_83 * V_85 , T_1 V_116 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_96 = V_85 -> V_84 ;
unsigned long V_98 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
if ( V_116 == 0 )
F_3 ( V_2 , F_26 ( V_96 ) , F_40 ( V_96 ) ) ;
else
F_3 ( V_2 , F_26 ( V_96 ) , F_41 ( V_96 ) ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
}
void F_44 ( struct V_83 * V_85 , T_1 V_116 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_96 = V_85 -> V_84 ;
unsigned long V_98 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
F_3 ( V_2 , 0xF0300000 , V_117 ) ;
switch ( V_116 ) {
case 0 :
F_3 ( V_2 , F_26 ( V_96 ) , F_40 ( V_96 ) ) ;
break;
case 1 :
F_3 ( V_2 , F_26 ( V_96 ) , F_41 ( V_96 ) ) ;
break;
case 2 :
F_3 ( V_2 , F_26 ( V_96 ) , F_42 ( V_96 ) ) ;
break;
default:
break;
}
F_3 ( V_2 , 0x0 , V_117 ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
}
int F_45 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_8 ;
unsigned long V_98 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_8 = F_34 ( V_2 , F_46 ( V_85 -> V_84 ) ) ;
V_8 |= F_26 ( V_85 -> V_84 ) ;
F_35 ( V_2 , V_8 , F_46 ( V_85 -> V_84 ) ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
return 0 ;
}
bool F_47 ( struct V_1 * V_2 , unsigned int V_96 )
{
return ( F_34 ( V_2 , F_48 ( V_96 ) ) & F_26 ( V_96 ) ) ;
}
int F_49 ( struct V_83 * V_85 , int V_118 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_119 ;
V_119 = V_120 + F_50 ( V_118 ) ;
while ( F_34 ( V_2 , F_48 ( V_85 -> V_84 ) ) &
F_26 ( V_85 -> V_84 ) ) {
if ( F_51 ( V_120 , V_119 ) )
return - V_121 ;
F_52 () ;
}
return 0 ;
}
int F_53 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_8 ;
unsigned long V_98 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_8 = F_34 ( V_2 , F_46 ( V_85 -> V_84 ) ) ;
V_8 &= ~ F_26 ( V_85 -> V_84 ) ;
F_35 ( V_2 , V_8 , F_46 ( V_85 -> V_84 ) ) ;
F_25 ( V_85 ) ;
F_3 ( V_2 , 0xf0000000 , V_117 ) ;
if ( F_1 ( V_2 , F_40 ( V_85 -> V_84 ) ) &
F_26 ( V_85 -> V_84 ) ) {
F_3 ( V_2 , F_26 ( V_85 -> V_84 ) ,
F_40 ( V_85 -> V_84 ) ) ;
}
if ( F_1 ( V_2 , F_41 ( V_85 -> V_84 ) ) &
F_26 ( V_85 -> V_84 ) ) {
F_3 ( V_2 , F_26 ( V_85 -> V_84 ) ,
F_41 ( V_85 -> V_84 ) ) ;
}
F_3 ( V_2 , 0x0 , V_117 ) ;
V_8 = F_1 ( V_2 , F_30 ( V_85 -> V_84 ) ) ;
V_8 &= ~ F_26 ( V_85 -> V_84 ) ;
F_3 ( V_2 , V_8 , F_30 ( V_85 -> V_84 ) ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
return 0 ;
}
void F_54 ( struct V_83 * V_85 , bool V_122 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_98 ;
T_1 V_8 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_8 = F_34 ( V_2 , F_55 ( V_85 -> V_84 ) ) ;
if ( V_122 )
V_8 |= 1 << ( V_85 -> V_84 % 32 ) ;
else
V_8 &= ~ ( 1 << ( V_85 -> V_84 % 32 ) ) ;
F_35 ( V_2 , V_8 , F_55 ( V_85 -> V_84 ) ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
unsigned long V_119 ;
F_3 ( V_2 , 0x807FFFFF , V_123 ) ;
V_119 = V_120 + F_50 ( 1000 ) ;
while ( F_1 ( V_2 , V_123 ) & 0x80000000 ) {
if ( F_51 ( V_120 , V_119 ) )
return - V_124 ;
F_52 () ;
}
return 0 ;
}
void F_57 ( struct V_1 * V_2 , int V_125 , bool V_126 )
{
unsigned long V_98 ;
T_1 V_8 , V_108 ;
V_108 = ( V_125 == 1 ) ? V_127 :
V_128 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_8 = F_1 ( V_2 , V_115 ) ;
if ( V_126 )
V_8 |= V_108 ;
else
V_8 &= ~ V_108 ;
F_3 ( V_2 , V_8 , V_115 ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
}
void F_58 ( struct V_1 * V_2 , int V_125 , bool V_129 )
{
unsigned long V_98 ;
T_1 V_8 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
V_8 = F_1 ( V_2 , V_115 ) ;
if ( V_129 )
V_8 |= V_130 ;
else
V_8 &= ~ V_130 ;
if ( V_125 == 1 )
V_8 |= V_131 ;
else
V_8 &= ~ V_131 ;
F_3 ( V_2 , V_8 , V_115 ) ;
F_31 ( & V_2 -> V_100 , V_98 ) ;
}
static const struct V_132 * F_59 ( int V_133 , int V_134 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < F_33 ( V_132 ) ; V_104 ++ ) {
if ( V_133 == V_132 [ V_104 ] . V_133 . V_96 &&
V_134 == V_132 [ V_104 ] . V_134 . V_96 )
return & V_132 [ V_104 ] ;
}
return NULL ;
}
int F_60 ( struct V_1 * V_2 , int V_135 , int V_136 )
{
const struct V_132 * V_137 ;
T_1 V_138 , V_139 ;
unsigned long V_98 ;
V_137 = F_59 ( V_135 , V_136 ) ;
if ( ! V_137 )
return - V_70 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
if ( V_137 -> V_133 . V_108 ) {
V_138 = F_1 ( V_2 , V_137 -> V_133 . V_99 ) ;
V_138 &= ~ V_137 -> V_133 . V_108 ;
V_138 |= V_137 -> V_133 . V_8 ;
F_3 ( V_2 , V_138 , V_137 -> V_133 . V_99 ) ;
}
if ( V_137 -> V_134 . V_108 ) {
V_139 = F_1 ( V_2 , V_137 -> V_134 . V_99 ) ;
V_139 &= ~ V_137 -> V_134 . V_108 ;
V_139 |= V_137 -> V_134 . V_8 ;
F_3 ( V_2 , V_139 , V_137 -> V_134 . V_99 ) ;
}
F_31 ( & V_2 -> V_100 , V_98 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , int V_135 , int V_136 )
{
const struct V_132 * V_137 ;
T_1 V_138 , V_139 ;
unsigned long V_98 ;
V_137 = F_59 ( V_135 , V_136 ) ;
if ( ! V_137 )
return - V_70 ;
F_29 ( & V_2 -> V_100 , V_98 ) ;
if ( V_137 -> V_133 . V_108 ) {
V_138 = F_1 ( V_2 , V_137 -> V_133 . V_99 ) ;
V_138 &= ~ V_137 -> V_133 . V_108 ;
F_3 ( V_2 , V_138 , V_137 -> V_133 . V_99 ) ;
}
if ( V_137 -> V_134 . V_108 ) {
V_139 = F_1 ( V_2 , V_137 -> V_134 . V_99 ) ;
V_139 &= ~ V_137 -> V_134 . V_108 ;
F_3 ( V_2 , V_139 , V_137 -> V_134 . V_99 ) ;
}
F_31 ( & V_2 -> V_100 , V_98 ) ;
return 0 ;
}
int F_62 ( struct V_83 * V_133 , struct V_83 * V_134 )
{
return F_60 ( V_133 -> V_2 , V_133 -> V_84 , V_134 -> V_84 ) ;
}
int F_63 ( struct V_83 * V_133 , struct V_83 * V_134 )
{
return F_61 ( V_133 -> V_2 , V_133 -> V_84 , V_134 -> V_84 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_140 * V_141 , unsigned long V_142 ,
struct V_143 * V_144 )
{
char * V_145 ;
int V_146 ;
struct V_147 * V_86 = & V_141 -> V_86 ;
const struct V_148 * V_149 = V_2 -> V_149 ;
V_146 = F_65 ( V_2 , V_86 , V_142 + V_149 -> V_150 ) ;
if ( V_146 ) {
V_145 = L_2 ;
goto V_151;
}
V_146 = F_66 ( V_2 , V_86 , 0 , V_142 + V_149 -> V_152 ,
V_153 , V_144 ) ;
if ( V_146 ) {
V_145 = L_3 ;
goto V_154;
}
V_146 = F_66 ( V_2 , V_86 , 1 , V_142 + V_149 -> V_155 ,
V_156 , V_144 ) ;
if ( V_146 ) {
V_145 = L_4 ;
goto V_157;
}
V_146 = F_67 ( V_2 , V_86 ,
V_142 + V_149 -> V_158 ,
V_142 + V_149 -> V_159 ) ;
if ( V_146 ) {
V_145 = L_5 ;
goto V_160;
}
V_146 = F_68 ( V_2 , V_86 , V_142 + V_149 -> V_161 ,
V_162 | V_163 |
V_130 ) ;
if ( V_146 ) {
V_145 = L_6 ;
goto V_164;
}
V_146 = F_69 ( V_2 , V_86 ) ;
if ( V_146 ) {
V_145 = L_7 ;
goto V_165;
}
V_146 = F_70 ( V_2 , V_86 , 0 , V_142 + V_149 -> V_166 ,
V_111 , V_144 ) ;
if ( V_146 ) {
V_145 = L_8 ;
goto V_167;
}
V_146 = F_70 ( V_2 , V_86 , 1 , V_142 + V_149 -> V_168 ,
V_113 , V_144 ) ;
if ( V_146 ) {
V_145 = L_9 ;
goto V_169;
}
V_146 = F_71 ( V_2 , V_86 , V_142 + V_149 -> V_170 +
V_171 , V_142 + V_149 -> V_172 ) ;
if ( V_146 ) {
V_145 = L_10 ;
goto V_173;
}
V_146 = F_72 ( V_2 , V_86 , V_142 +
V_149 -> V_170 + V_174 , V_144 ) ;
if ( V_146 ) {
V_145 = L_11 ;
goto V_175;
}
V_146 = F_73 ( V_2 , V_86 , V_142 + V_149 -> V_176 ) ;
if ( V_146 ) {
V_145 = L_12 ;
goto V_177;
}
V_146 = F_74 ( V_2 , V_86 , V_142 +
V_149 -> V_170 + V_178 ) ;
if ( V_146 ) {
V_145 = L_13 ;
goto V_179;
}
return 0 ;
V_179:
F_75 ( V_2 ) ;
V_177:
F_76 ( V_2 ) ;
V_175:
F_77 ( V_2 ) ;
V_173:
F_78 ( V_2 , 1 ) ;
V_169:
F_78 ( V_2 , 0 ) ;
V_167:
F_79 ( V_2 ) ;
V_165:
F_80 ( V_2 ) ;
V_164:
F_81 ( V_2 ) ;
V_160:
F_82 ( V_2 , 1 ) ;
V_157:
F_82 ( V_2 , 0 ) ;
V_154:
F_83 ( V_2 ) ;
V_151:
F_84 ( & V_141 -> V_86 , L_14 , V_145 , V_146 ) ;
return V_146 ;
}
static void F_85 ( struct V_1 * V_2 , const int * V_180 , int V_181 )
{
unsigned long V_182 ;
int V_104 , V_183 , V_184 ;
for ( V_104 = 0 ; V_104 < V_181 ; V_104 ++ ) {
V_182 = F_1 ( V_2 , F_86 ( V_180 [ V_104 ] ) ) ;
V_182 &= F_1 ( V_2 , F_87 ( V_180 [ V_104 ] ) ) ;
F_88 (bit, &status, 32 ) {
V_184 = F_89 ( V_2 -> V_185 ,
V_180 [ V_104 ] * 32 + V_183 ) ;
if ( V_184 )
F_90 ( V_184 ) ;
}
}
}
static void F_91 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_92 ( V_187 ) ;
struct V_188 * V_189 = F_93 ( V_187 ) ;
const int V_190 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
F_94 ( V_189 , V_187 ) ;
F_85 ( V_2 , V_190 , F_33 ( V_190 ) ) ;
F_95 ( V_189 , V_187 ) ;
}
static void F_96 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_92 ( V_187 ) ;
struct V_188 * V_189 = F_93 ( V_187 ) ;
const int V_190 [] = { 4 , 5 , 8 , 9 } ;
F_94 ( V_189 , V_187 ) ;
F_85 ( V_2 , V_190 , F_33 ( V_190 ) ) ;
F_95 ( V_189 , V_187 ) ;
}
int F_97 ( struct V_1 * V_2 , int V_184 )
{
int V_191 ;
V_191 = F_89 ( V_2 -> V_185 , V_184 ) ;
if ( ! V_191 )
V_191 = F_98 ( V_2 -> V_185 , V_184 ) ;
return V_191 ;
}
int F_99 ( struct V_1 * V_2 , struct V_83 * V_85 ,
enum V_192 V_193 )
{
return F_97 ( V_2 , V_193 + V_85 -> V_84 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_101 ( V_2 ) ;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 1 ) ;
F_78 ( V_2 , 0 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 , 1 ) ;
F_82 ( V_2 , 0 ) ;
F_83 ( V_2 ) ;
}
static int F_102 ( struct V_147 * V_86 , void * V_194 )
{
struct V_140 * V_141 = F_103 ( V_86 ) ;
F_104 ( V_141 ) ;
return 0 ;
}
static void F_105 ( struct V_140 * V_141 )
{
F_106 ( & V_141 -> V_86 , NULL , F_102 ) ;
}
static int F_107 ( struct V_1 * V_2 , unsigned long V_142 )
{
struct V_147 * V_86 = V_2 -> V_86 ;
unsigned V_104 ;
int V_6 , V_146 ;
F_17 ( & V_195 ) ;
V_6 = V_196 ;
V_196 += F_33 ( V_197 ) ;
F_21 ( & V_195 ) ;
for ( V_104 = 0 ; V_104 < F_33 ( V_197 ) ; V_104 ++ ) {
struct V_198 * V_99 = & V_197 [ V_104 ] ;
struct V_140 * V_141 ;
struct V_199 * V_200 ;
V_200 = F_108 ( V_86 -> V_200 , V_104 ) ;
if ( ! V_200 ) {
F_109 ( V_86 ,
L_15 ,
V_104 , V_86 -> V_200 -> V_201 ,
( V_104 / 2 ) ? L_16 : L_17 , V_104 % 2 ) ;
continue;
}
V_141 = F_110 ( V_99 -> V_202 , V_6 ++ ) ;
if ( ! V_141 ) {
V_146 = - V_93 ;
goto V_203;
}
V_141 -> V_86 . V_204 = V_86 ;
V_99 -> V_205 . V_200 = V_200 ;
V_146 = F_111 ( V_141 , & V_99 -> V_205 ,
sizeof( V_99 -> V_205 ) ) ;
if ( ! V_146 )
V_146 = F_112 ( V_141 ) ;
if ( V_146 ) {
F_113 ( V_141 ) ;
goto V_203;
}
}
return 0 ;
V_203:
F_105 ( F_103 ( V_86 ) ) ;
return V_146 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_206 * V_207 ;
struct V_208 * V_209 ;
unsigned long V_194 [ V_210 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_146 , V_104 ;
V_2 -> V_185 = F_115 ( V_2 -> V_86 -> V_200 , V_210 ,
& V_211 , V_2 ) ;
if ( ! V_2 -> V_185 ) {
F_84 ( V_2 -> V_86 , L_18 ) ;
return - V_88 ;
}
V_146 = F_116 ( V_2 -> V_185 , 32 , 1 , L_19 ,
V_212 , 0 , 0 , 0 ) ;
if ( V_146 < 0 ) {
F_84 ( V_2 -> V_86 , L_20 ) ;
F_117 ( V_2 -> V_185 ) ;
return V_146 ;
}
for ( V_104 = 0 ; V_104 < V_210 ; V_104 += 32 ) {
F_3 ( V_2 , 0 , F_87 ( V_104 / 32 ) ) ;
F_3 ( V_2 , ~ V_194 [ V_104 / 32 ] , F_86 ( V_104 / 32 ) ) ;
}
for ( V_104 = 0 ; V_104 < V_210 ; V_104 += 32 ) {
V_207 = F_118 ( V_2 -> V_185 , V_104 ) ;
V_207 -> V_213 = V_2 -> V_4 ;
V_207 -> V_194 = V_194 [ V_104 / 32 ] ;
V_209 = V_207 -> V_214 ;
V_209 -> V_189 . V_215 = V_216 ;
V_209 -> V_189 . V_217 = V_218 ;
V_209 -> V_189 . V_219 = V_220 ;
V_209 -> V_180 . V_221 = F_86 ( V_104 / 32 ) ;
V_209 -> V_180 . V_108 = F_87 ( V_104 / 32 ) ;
}
F_119 ( V_2 -> V_222 , F_91 , V_2 ) ;
F_119 ( V_2 -> V_223 , F_96 ,
V_2 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 )
{
int V_104 , V_184 ;
F_119 ( V_2 -> V_223 , NULL , NULL ) ;
F_119 ( V_2 -> V_222 , NULL , NULL ) ;
for ( V_104 = 0 ; V_104 < V_210 ; V_104 ++ ) {
V_184 = F_89 ( V_2 -> V_185 , V_104 ) ;
if ( V_184 )
F_121 ( V_184 ) ;
}
F_117 ( V_2 -> V_185 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
int V_104 ;
F_15 ( V_2 -> V_86 , L_21 ,
F_1 ( V_2 , V_115 ) ) ;
F_15 ( V_2 -> V_86 , L_22 ,
F_34 ( V_2 , V_224 ) ) ;
F_15 ( V_2 -> V_86 , L_23 ,
F_34 ( V_2 , F_46 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_24 ,
F_34 ( V_2 , F_46 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_25 ,
F_34 ( V_2 , F_123 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_26 ,
F_34 ( V_2 , F_123 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_27 ,
F_34 ( V_2 , F_124 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_28 ,
F_34 ( V_2 , F_124 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_29 ,
F_1 ( V_2 , F_30 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_30 ,
F_1 ( V_2 , F_30 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_31 ,
F_1 ( V_2 , V_225 ) ) ;
F_15 ( V_2 -> V_86 , L_32 ,
F_1 ( V_2 , V_226 ) ) ;
F_15 ( V_2 -> V_86 , L_33 ,
F_1 ( V_2 , V_227 ) ) ;
F_15 ( V_2 -> V_86 , L_34 ,
F_1 ( V_2 , V_228 ) ) ;
for ( V_104 = 0 ; V_104 < 15 ; V_104 ++ )
F_15 ( V_2 -> V_86 , L_35 , V_104 ,
F_1 ( V_2 , F_87 ( V_104 ) ) ) ;
}
static int F_125 ( struct V_140 * V_141 )
{
struct V_199 * V_229 = V_141 -> V_86 . V_200 ;
struct V_1 * V_2 ;
struct V_230 * V_231 ;
unsigned long V_142 ;
int V_146 , V_222 , V_223 ;
const struct V_148 * V_149 ;
V_149 = F_126 ( & V_141 -> V_86 ) ;
if ( ! V_149 )
return - V_70 ;
V_222 = F_127 ( V_141 , 0 ) ;
V_223 = F_127 ( V_141 , 1 ) ;
V_231 = F_128 ( V_141 , V_232 , 0 ) ;
F_15 ( & V_141 -> V_86 , L_36 ,
V_222 , V_223 ) ;
if ( ! V_231 || V_222 < 0 || V_223 < 0 )
return - V_88 ;
V_142 = V_231 -> V_233 ;
V_2 = F_129 ( & V_141 -> V_86 , sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_6 = F_130 ( V_229 , L_37 ) ;
if ( F_131 ( V_229 , L_38 ) &&
F_132 ( V_234 ) ) {
V_2 -> V_235 = F_133 ( & V_141 -> V_86 ,
L_39 , V_2 -> V_6 ) ;
if ( ! V_2 -> V_235 )
return - V_236 ;
}
V_2 -> V_149 = V_149 ;
V_2 -> V_237 = V_149 -> type ;
F_134 ( & V_2 -> V_100 ) ;
F_135 ( & V_2 -> V_89 ) ;
F_136 ( & V_2 -> V_95 ) ;
F_15 ( & V_141 -> V_86 , L_40 ,
V_142 + V_149 -> V_170 ) ;
F_15 ( & V_141 -> V_86 , L_41 ,
V_142 + V_149 -> V_170 + V_238 ) ;
F_15 ( & V_141 -> V_86 , L_42 ,
V_142 + V_149 -> V_150 ) ;
F_15 ( & V_141 -> V_86 , L_43 ,
V_142 + V_149 -> V_152 ) ;
F_15 ( & V_141 -> V_86 , L_44 ,
V_142 + V_149 -> V_155 ) ;
F_15 ( & V_141 -> V_86 , L_45 ,
V_142 + V_149 -> V_158 ) ;
F_15 ( & V_141 -> V_86 , L_46 ,
V_142 + V_149 -> V_166 ) ;
F_15 ( & V_141 -> V_86 , L_47 ,
V_142 + V_149 -> V_168 ) ;
F_15 ( & V_141 -> V_86 , L_48 ,
V_142 + V_149 -> V_176 ) ;
F_15 ( & V_141 -> V_86 , L_49 ,
V_142 + V_149 -> V_159 ) ;
F_15 ( & V_141 -> V_86 , L_50 ,
V_142 + V_149 -> V_170 + V_171 ) ;
F_15 ( & V_141 -> V_86 , L_51 ,
V_142 + V_149 -> V_170 + V_239 ) ;
F_15 ( & V_141 -> V_86 , L_52 ,
V_142 + V_149 -> V_170 + V_174 ) ;
F_15 ( & V_141 -> V_86 , L_53 ,
V_142 + V_149 -> V_161 ) ;
V_2 -> V_4 = F_137 ( & V_141 -> V_86 ,
V_142 + V_149 -> V_170 , V_240 ) ;
V_2 -> V_241 = F_137 ( & V_141 -> V_86 ,
V_142 + V_149 -> V_170 + V_238 ,
V_240 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_241 )
return - V_93 ;
V_2 -> V_143 = F_138 ( & V_141 -> V_86 , L_54 ) ;
if ( F_139 ( V_2 -> V_143 ) ) {
V_146 = F_140 ( V_2 -> V_143 ) ;
F_84 ( & V_141 -> V_86 , L_55 , V_146 ) ;
return V_146 ;
}
F_141 ( V_141 , V_2 ) ;
V_146 = F_142 ( V_2 -> V_143 ) ;
if ( V_146 ) {
F_84 ( & V_141 -> V_86 , L_56 , V_146 ) ;
return V_146 ;
}
V_2 -> V_86 = & V_141 -> V_86 ;
V_2 -> V_222 = V_222 ;
V_2 -> V_223 = V_223 ;
V_146 = F_143 ( & V_141 -> V_86 ) ;
if ( V_146 ) {
F_84 ( & V_141 -> V_86 , L_57 , V_146 ) ;
goto V_242;
}
V_146 = F_56 ( V_2 ) ;
if ( V_146 )
goto V_242;
V_146 = F_114 ( V_2 ) ;
if ( V_146 )
goto V_243;
F_3 ( V_2 , 0x00400000L | ( V_244 << 18 ) ,
V_110 ) ;
V_146 = F_64 ( V_2 , V_141 , V_142 , V_2 -> V_143 ) ;
if ( V_146 )
goto V_245;
V_146 = F_107 ( V_2 , V_142 ) ;
if ( V_146 ) {
F_84 ( & V_141 -> V_86 , L_58 ,
V_146 ) ;
goto V_246;
}
F_109 ( & V_141 -> V_86 , L_59 , V_149 -> V_202 ) ;
return 0 ;
V_246:
F_100 ( V_2 ) ;
V_245:
F_120 ( V_2 ) ;
V_243:
V_242:
F_144 ( V_2 -> V_143 ) ;
return V_146 ;
}
static int F_145 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_146 ( V_141 ) ;
F_105 ( V_141 ) ;
F_100 ( V_2 ) ;
F_120 ( V_2 ) ;
F_144 ( V_2 -> V_143 ) ;
return 0 ;
}
static int T_2 F_147 ( void )
{
return F_148 ( V_247 , F_33 ( V_247 ) ) ;
}
static void T_3 F_149 ( void )
{
F_150 ( V_247 , F_33 ( V_247 ) ) ;
}
