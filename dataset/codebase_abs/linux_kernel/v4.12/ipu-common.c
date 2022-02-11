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
V_85 = & V_2 -> V_85 [ V_84 ] ;
if ( V_85 -> V_90 ) {
V_85 = F_16 ( - V_91 ) ;
goto V_92;
}
V_85 -> V_90 = true ;
V_85 -> V_84 = V_84 ;
V_92:
F_18 ( & V_2 -> V_89 ) ;
return V_85 ;
}
void F_19 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
F_15 ( V_2 -> V_86 , L_1 , V_87 , V_85 -> V_84 ) ;
F_17 ( & V_2 -> V_89 ) ;
V_85 -> V_90 = false ;
F_18 ( & V_2 -> V_89 ) ;
}
static void F_20 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_93 = V_85 -> V_84 ;
F_3 ( V_2 , F_21 ( V_93 ) , F_22 ( V_93 ) ) ;
}
void F_23 ( struct V_83 * V_85 ,
bool V_94 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_95 ;
T_1 V_96 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_96 = F_1 ( V_2 , F_25 ( V_85 -> V_84 ) ) ;
if ( V_94 )
V_96 |= F_21 ( V_85 -> V_84 ) ;
else
V_96 &= ~ F_21 ( V_85 -> V_84 ) ;
F_3 ( V_2 , V_96 , F_25 ( V_85 -> V_84 ) ) ;
F_20 ( V_85 ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
}
int F_27 ( struct V_83 * V_85 , int V_98 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_95 ;
T_1 V_99 , V_100 ;
int V_101 ;
switch ( V_98 ) {
case 0 :
case 1 :
V_99 = 0x00 ;
break;
case 2 :
V_99 = 0x01 ;
break;
case 4 :
V_99 = 0x02 ;
break;
case 8 :
V_99 = 0x03 ;
break;
default:
return - V_70 ;
}
for ( V_101 = 0 ; V_101 < F_28 ( V_102 ) ; V_101 ++ ) {
if ( V_85 -> V_84 == V_102 [ V_101 ] . V_103 )
break;
}
if ( V_101 >= F_28 ( V_102 ) )
return - V_70 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_100 = F_29 ( V_2 , V_102 [ V_101 ] . V_96 ) ;
V_100 &= ~ ( 0x03 << V_102 [ V_101 ] . V_104 ) ;
V_100 |= ( V_99 << V_102 [ V_101 ] . V_104 ) ;
F_30 ( V_2 , V_100 , V_102 [ V_101 ] . V_96 ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_105 )
{
unsigned long V_106 ;
T_1 V_8 ;
F_24 ( & V_2 -> V_97 , V_106 ) ;
V_8 = F_1 ( V_2 , V_107 ) ;
if ( V_105 & V_108 )
V_8 |= V_109 ;
if ( V_105 & V_110 )
V_8 |= V_111 ;
F_3 ( V_2 , V_8 , V_107 ) ;
V_8 = F_1 ( V_2 , V_112 ) ;
V_8 |= V_105 ;
F_3 ( V_2 , V_8 , V_112 ) ;
F_26 ( & V_2 -> V_97 , V_106 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_105 )
{
unsigned long V_106 ;
T_1 V_8 ;
F_24 ( & V_2 -> V_97 , V_106 ) ;
V_8 = F_1 ( V_2 , V_112 ) ;
V_8 &= ~ V_105 ;
F_3 ( V_2 , V_8 , V_112 ) ;
V_8 = F_1 ( V_2 , V_107 ) ;
if ( V_105 & V_108 )
V_8 &= ~ V_109 ;
if ( V_105 & V_110 )
V_8 &= ~ V_111 ;
F_3 ( V_2 , V_8 , V_107 ) ;
F_26 ( & V_2 -> V_97 , V_106 ) ;
return 0 ;
}
int F_33 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_93 = V_85 -> V_84 ;
return ( F_1 ( V_2 , F_22 ( V_93 ) ) & F_21 ( V_93 ) ) ? 1 : 0 ;
}
bool F_34 ( struct V_83 * V_85 , T_1 V_113 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_95 ;
T_1 V_96 = 0 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
switch ( V_113 ) {
case 0 :
V_96 = F_1 ( V_2 , F_35 ( V_85 -> V_84 ) ) ;
break;
case 1 :
V_96 = F_1 ( V_2 , F_36 ( V_85 -> V_84 ) ) ;
break;
case 2 :
V_96 = F_1 ( V_2 , F_37 ( V_85 -> V_84 ) ) ;
break;
}
F_26 ( & V_2 -> V_97 , V_95 ) ;
return ( ( V_96 & F_21 ( V_85 -> V_84 ) ) != 0 ) ;
}
void F_38 ( struct V_83 * V_85 , T_1 V_113 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_93 = V_85 -> V_84 ;
unsigned long V_95 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
if ( V_113 == 0 )
F_3 ( V_2 , F_21 ( V_93 ) , F_35 ( V_93 ) ) ;
else
F_3 ( V_2 , F_21 ( V_93 ) , F_36 ( V_93 ) ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
}
void F_39 ( struct V_83 * V_85 , T_1 V_113 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_93 = V_85 -> V_84 ;
unsigned long V_95 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
F_3 ( V_2 , 0xF0300000 , V_114 ) ;
switch ( V_113 ) {
case 0 :
F_3 ( V_2 , F_21 ( V_93 ) , F_35 ( V_93 ) ) ;
break;
case 1 :
F_3 ( V_2 , F_21 ( V_93 ) , F_36 ( V_93 ) ) ;
break;
case 2 :
F_3 ( V_2 , F_21 ( V_93 ) , F_37 ( V_93 ) ) ;
break;
default:
break;
}
F_3 ( V_2 , 0x0 , V_114 ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
}
int F_40 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_8 ;
unsigned long V_95 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_8 = F_29 ( V_2 , F_41 ( V_85 -> V_84 ) ) ;
V_8 |= F_21 ( V_85 -> V_84 ) ;
F_30 ( V_2 , V_8 , F_41 ( V_85 -> V_84 ) ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
return 0 ;
}
bool F_42 ( struct V_1 * V_2 , unsigned int V_93 )
{
return ( F_29 ( V_2 , F_43 ( V_93 ) ) & F_21 ( V_93 ) ) ;
}
int F_44 ( struct V_83 * V_85 , int V_115 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_116 ;
V_116 = V_117 + F_45 ( V_115 ) ;
while ( F_29 ( V_2 , F_43 ( V_85 -> V_84 ) ) &
F_21 ( V_85 -> V_84 ) ) {
if ( F_46 ( V_117 , V_116 ) )
return - V_118 ;
F_47 () ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 , int V_119 , int V_115 )
{
unsigned long V_116 ;
V_116 = V_117 + F_45 ( V_115 ) ;
F_3 ( V_2 , F_49 ( V_119 % 32 ) , F_50 ( V_119 / 32 ) ) ;
while ( ! ( F_1 ( V_2 , F_50 ( V_119 / 32 ) & F_49 ( V_119 % 32 ) ) ) ) {
if ( F_46 ( V_117 , V_116 ) )
return - V_118 ;
F_47 () ;
}
return 0 ;
}
int F_51 ( struct V_83 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_8 ;
unsigned long V_95 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_8 = F_29 ( V_2 , F_41 ( V_85 -> V_84 ) ) ;
V_8 &= ~ F_21 ( V_85 -> V_84 ) ;
F_30 ( V_2 , V_8 , F_41 ( V_85 -> V_84 ) ) ;
F_20 ( V_85 ) ;
F_3 ( V_2 , 0xf0000000 , V_114 ) ;
if ( F_1 ( V_2 , F_35 ( V_85 -> V_84 ) ) &
F_21 ( V_85 -> V_84 ) ) {
F_3 ( V_2 , F_21 ( V_85 -> V_84 ) ,
F_35 ( V_85 -> V_84 ) ) ;
}
if ( F_1 ( V_2 , F_36 ( V_85 -> V_84 ) ) &
F_21 ( V_85 -> V_84 ) ) {
F_3 ( V_2 , F_21 ( V_85 -> V_84 ) ,
F_36 ( V_85 -> V_84 ) ) ;
}
F_3 ( V_2 , 0x0 , V_114 ) ;
V_8 = F_1 ( V_2 , F_25 ( V_85 -> V_84 ) ) ;
V_8 &= ~ F_21 ( V_85 -> V_84 ) ;
F_3 ( V_2 , V_8 , F_25 ( V_85 -> V_84 ) ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
return 0 ;
}
void F_52 ( struct V_83 * V_85 , bool V_120 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_95 ;
T_1 V_8 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_8 = F_29 ( V_2 , F_53 ( V_85 -> V_84 ) ) ;
if ( V_120 )
V_8 |= 1 << ( V_85 -> V_84 % 32 ) ;
else
V_8 &= ~ ( 1 << ( V_85 -> V_84 % 32 ) ) ;
F_30 ( V_2 , V_8 , F_53 ( V_85 -> V_84 ) ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
unsigned long V_116 ;
F_3 ( V_2 , 0x807FFFFF , V_121 ) ;
V_116 = V_117 + F_45 ( 1000 ) ;
while ( F_1 ( V_2 , V_121 ) & 0x80000000 ) {
if ( F_46 ( V_117 , V_116 ) )
return - V_122 ;
F_47 () ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 , int V_123 , bool V_124 )
{
unsigned long V_95 ;
T_1 V_8 , V_105 ;
V_105 = ( V_123 == 1 ) ? V_125 :
V_126 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_8 = F_1 ( V_2 , V_112 ) ;
if ( V_124 )
V_8 |= V_105 ;
else
V_8 &= ~ V_105 ;
F_3 ( V_2 , V_8 , V_112 ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_123 , bool V_127 )
{
unsigned long V_95 ;
T_1 V_8 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
V_8 = F_1 ( V_2 , V_112 ) ;
if ( V_127 )
V_8 |= V_128 ;
else
V_8 &= ~ V_128 ;
if ( V_123 == 1 )
V_8 |= V_129 ;
else
V_8 &= ~ V_129 ;
F_3 ( V_2 , V_8 , V_112 ) ;
F_26 ( & V_2 -> V_97 , V_95 ) ;
}
static const struct V_130 * F_57 ( int V_131 , int V_132 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < F_28 ( V_130 ) ; V_101 ++ ) {
if ( V_131 == V_130 [ V_101 ] . V_131 . V_93 &&
V_132 == V_130 [ V_101 ] . V_132 . V_93 )
return & V_130 [ V_101 ] ;
}
return NULL ;
}
int F_58 ( struct V_1 * V_2 , int V_133 , int V_134 )
{
const struct V_130 * V_135 ;
T_1 V_136 , V_137 ;
unsigned long V_95 ;
V_135 = F_57 ( V_133 , V_134 ) ;
if ( ! V_135 )
return - V_70 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
if ( V_135 -> V_131 . V_105 ) {
V_136 = F_1 ( V_2 , V_135 -> V_131 . V_96 ) ;
V_136 &= ~ V_135 -> V_131 . V_105 ;
V_136 |= V_135 -> V_131 . V_8 ;
F_3 ( V_2 , V_136 , V_135 -> V_131 . V_96 ) ;
}
if ( V_135 -> V_132 . V_105 ) {
V_137 = F_1 ( V_2 , V_135 -> V_132 . V_96 ) ;
V_137 &= ~ V_135 -> V_132 . V_105 ;
V_137 |= V_135 -> V_132 . V_8 ;
F_3 ( V_2 , V_137 , V_135 -> V_132 . V_96 ) ;
}
F_26 ( & V_2 -> V_97 , V_95 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , int V_133 , int V_134 )
{
const struct V_130 * V_135 ;
T_1 V_136 , V_137 ;
unsigned long V_95 ;
V_135 = F_57 ( V_133 , V_134 ) ;
if ( ! V_135 )
return - V_70 ;
F_24 ( & V_2 -> V_97 , V_95 ) ;
if ( V_135 -> V_131 . V_105 ) {
V_136 = F_1 ( V_2 , V_135 -> V_131 . V_96 ) ;
V_136 &= ~ V_135 -> V_131 . V_105 ;
F_3 ( V_2 , V_136 , V_135 -> V_131 . V_96 ) ;
}
if ( V_135 -> V_132 . V_105 ) {
V_137 = F_1 ( V_2 , V_135 -> V_132 . V_96 ) ;
V_137 &= ~ V_135 -> V_132 . V_105 ;
F_3 ( V_2 , V_137 , V_135 -> V_132 . V_96 ) ;
}
F_26 ( & V_2 -> V_97 , V_95 ) ;
return 0 ;
}
int F_60 ( struct V_83 * V_131 , struct V_83 * V_132 )
{
return F_58 ( V_131 -> V_2 , V_131 -> V_84 , V_132 -> V_84 ) ;
}
int F_61 ( struct V_83 * V_131 , struct V_83 * V_132 )
{
return F_59 ( V_131 -> V_2 , V_131 -> V_84 , V_132 -> V_84 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_138 * V_139 , unsigned long V_140 ,
struct V_141 * V_142 )
{
char * V_143 ;
int V_144 ;
struct V_145 * V_86 = & V_139 -> V_86 ;
const struct V_146 * V_147 = V_2 -> V_147 ;
V_144 = F_63 ( V_2 , V_86 , V_140 + V_147 -> V_148 ) ;
if ( V_144 ) {
V_143 = L_2 ;
goto V_149;
}
V_144 = F_64 ( V_2 , V_86 , 0 , V_140 + V_147 -> V_150 ,
V_151 , V_142 ) ;
if ( V_144 ) {
V_143 = L_3 ;
goto V_152;
}
V_144 = F_64 ( V_2 , V_86 , 1 , V_140 + V_147 -> V_153 ,
V_154 , V_142 ) ;
if ( V_144 ) {
V_143 = L_4 ;
goto V_155;
}
V_144 = F_65 ( V_2 , V_86 ,
V_140 + V_147 -> V_156 ,
V_140 + V_147 -> V_157 ) ;
if ( V_144 ) {
V_143 = L_5 ;
goto V_158;
}
V_144 = F_66 ( V_2 , V_86 , V_140 + V_147 -> V_159 ,
V_160 | V_161 |
V_128 ) ;
if ( V_144 ) {
V_143 = L_6 ;
goto V_162;
}
V_144 = F_67 ( V_2 , V_86 ) ;
if ( V_144 ) {
V_143 = L_7 ;
goto V_163;
}
V_144 = F_68 ( V_2 , V_86 , 0 , V_140 + V_147 -> V_164 ,
V_108 , V_142 ) ;
if ( V_144 ) {
V_143 = L_8 ;
goto V_165;
}
V_144 = F_68 ( V_2 , V_86 , 1 , V_140 + V_147 -> V_166 ,
V_110 , V_142 ) ;
if ( V_144 ) {
V_143 = L_9 ;
goto V_167;
}
V_144 = F_69 ( V_2 , V_86 , V_140 + V_147 -> V_168 +
V_169 , V_140 + V_147 -> V_170 ) ;
if ( V_144 ) {
V_143 = L_10 ;
goto V_171;
}
V_144 = F_70 ( V_2 , V_86 , V_140 +
V_147 -> V_168 + V_172 , V_142 ) ;
if ( V_144 ) {
V_143 = L_11 ;
goto V_173;
}
V_144 = F_71 ( V_2 , V_86 , V_140 + V_147 -> V_174 ) ;
if ( V_144 ) {
V_143 = L_12 ;
goto V_175;
}
V_144 = F_72 ( V_2 , V_86 , V_140 +
V_147 -> V_168 + V_176 ) ;
if ( V_144 ) {
V_143 = L_13 ;
goto V_177;
}
return 0 ;
V_177:
F_73 ( V_2 ) ;
V_175:
F_74 ( V_2 ) ;
V_173:
F_75 ( V_2 ) ;
V_171:
F_76 ( V_2 , 1 ) ;
V_167:
F_76 ( V_2 , 0 ) ;
V_165:
F_77 ( V_2 ) ;
V_163:
F_78 ( V_2 ) ;
V_162:
F_79 ( V_2 ) ;
V_158:
F_80 ( V_2 , 1 ) ;
V_155:
F_80 ( V_2 , 0 ) ;
V_152:
F_81 ( V_2 ) ;
V_149:
F_82 ( & V_139 -> V_86 , L_14 , V_143 , V_144 ) ;
return V_144 ;
}
static void F_83 ( struct V_1 * V_2 , const int * V_178 , int V_179 )
{
unsigned long V_180 ;
int V_101 , V_181 , V_119 ;
for ( V_101 = 0 ; V_101 < V_179 ; V_101 ++ ) {
V_180 = F_1 ( V_2 , F_50 ( V_178 [ V_101 ] ) ) ;
V_180 &= F_1 ( V_2 , F_84 ( V_178 [ V_101 ] ) ) ;
F_85 (bit, &status, 32 ) {
V_119 = F_86 ( V_2 -> V_182 ,
V_178 [ V_101 ] * 32 + V_181 ) ;
if ( V_119 )
F_87 ( V_119 ) ;
}
}
}
static void F_88 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_89 ( V_184 ) ;
struct V_185 * V_186 = F_90 ( V_184 ) ;
const int V_187 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
F_91 ( V_186 , V_184 ) ;
F_83 ( V_2 , V_187 , F_28 ( V_187 ) ) ;
F_92 ( V_186 , V_184 ) ;
}
static void F_93 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_89 ( V_184 ) ;
struct V_185 * V_186 = F_90 ( V_184 ) ;
const int V_187 [] = { 4 , 5 , 8 , 9 } ;
F_91 ( V_186 , V_184 ) ;
F_83 ( V_2 , V_187 , F_28 ( V_187 ) ) ;
F_92 ( V_186 , V_184 ) ;
}
int F_94 ( struct V_1 * V_2 , int V_119 )
{
int V_188 ;
V_188 = F_86 ( V_2 -> V_182 , V_119 ) ;
if ( ! V_188 )
V_188 = F_95 ( V_2 -> V_182 , V_119 ) ;
return V_188 ;
}
int F_96 ( struct V_1 * V_2 , struct V_83 * V_85 ,
enum V_189 V_190 )
{
return F_94 ( V_2 , V_190 + V_85 -> V_84 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
F_76 ( V_2 , 1 ) ;
F_76 ( V_2 , 0 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 , 1 ) ;
F_80 ( V_2 , 0 ) ;
F_81 ( V_2 ) ;
}
static int F_99 ( struct V_145 * V_86 , void * V_191 )
{
struct V_138 * V_139 = F_100 ( V_86 ) ;
F_101 ( V_139 ) ;
return 0 ;
}
static void F_102 ( struct V_138 * V_139 )
{
F_103 ( & V_139 -> V_86 , NULL , F_99 ) ;
}
static int F_104 ( struct V_1 * V_2 , unsigned long V_140 )
{
struct V_145 * V_86 = V_2 -> V_86 ;
unsigned V_101 ;
int V_6 , V_144 ;
F_17 ( & V_192 ) ;
V_6 = V_193 ;
V_193 += F_28 ( V_194 ) ;
F_18 ( & V_192 ) ;
for ( V_101 = 0 ; V_101 < F_28 ( V_194 ) ; V_101 ++ ) {
struct V_195 * V_96 = & V_194 [ V_101 ] ;
struct V_138 * V_139 ;
struct V_196 * V_197 ;
V_197 = F_105 ( V_86 -> V_197 , V_101 ) ;
if ( ! V_197 ) {
F_106 ( V_86 ,
L_15 ,
V_101 , V_86 -> V_197 -> V_198 ,
( V_101 / 2 ) ? L_16 : L_17 , V_101 % 2 ) ;
continue;
}
V_139 = F_107 ( V_96 -> V_199 , V_6 ++ ) ;
if ( ! V_139 ) {
V_144 = - V_200 ;
goto V_201;
}
V_139 -> V_86 . V_202 = V_86 ;
V_96 -> V_203 . V_197 = V_197 ;
V_144 = F_108 ( V_139 , & V_96 -> V_203 ,
sizeof( V_96 -> V_203 ) ) ;
if ( ! V_144 )
V_144 = F_109 ( V_139 ) ;
if ( V_144 ) {
F_110 ( V_139 ) ;
goto V_201;
}
}
return 0 ;
V_201:
F_102 ( F_100 ( V_86 ) ) ;
return V_144 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_204 * V_205 ;
struct V_206 * V_207 ;
unsigned long V_191 [ V_208 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_144 , V_101 ;
V_2 -> V_182 = F_112 ( V_2 -> V_86 -> V_197 , V_208 ,
& V_209 , V_2 ) ;
if ( ! V_2 -> V_182 ) {
F_82 ( V_2 -> V_86 , L_18 ) ;
return - V_88 ;
}
V_144 = F_113 ( V_2 -> V_182 , 32 , 1 , L_19 ,
V_210 , 0 , 0 , 0 ) ;
if ( V_144 < 0 ) {
F_82 ( V_2 -> V_86 , L_20 ) ;
F_114 ( V_2 -> V_182 ) ;
return V_144 ;
}
for ( V_101 = 0 ; V_101 < V_208 ; V_101 += 32 ) {
F_3 ( V_2 , 0 , F_84 ( V_101 / 32 ) ) ;
F_3 ( V_2 , ~ V_191 [ V_101 / 32 ] , F_50 ( V_101 / 32 ) ) ;
}
for ( V_101 = 0 ; V_101 < V_208 ; V_101 += 32 ) {
V_205 = F_115 ( V_2 -> V_182 , V_101 ) ;
V_205 -> V_211 = V_2 -> V_4 ;
V_205 -> V_191 = V_191 [ V_101 / 32 ] ;
V_207 = V_205 -> V_212 ;
V_207 -> V_186 . V_213 = V_214 ;
V_207 -> V_186 . V_215 = V_216 ;
V_207 -> V_186 . V_217 = V_218 ;
V_207 -> V_178 . V_219 = F_50 ( V_101 / 32 ) ;
V_207 -> V_178 . V_105 = F_84 ( V_101 / 32 ) ;
}
F_116 ( V_2 -> V_220 , F_88 , V_2 ) ;
F_116 ( V_2 -> V_221 , F_93 ,
V_2 ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_101 , V_119 ;
F_116 ( V_2 -> V_221 , NULL , NULL ) ;
F_116 ( V_2 -> V_220 , NULL , NULL ) ;
for ( V_101 = 0 ; V_101 < V_208 ; V_101 ++ ) {
V_119 = F_86 ( V_2 -> V_182 , V_101 ) ;
if ( V_119 )
F_118 ( V_119 ) ;
}
F_114 ( V_2 -> V_182 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
int V_101 ;
F_15 ( V_2 -> V_86 , L_21 ,
F_1 ( V_2 , V_112 ) ) ;
F_15 ( V_2 -> V_86 , L_22 ,
F_29 ( V_2 , V_222 ) ) ;
F_15 ( V_2 -> V_86 , L_23 ,
F_29 ( V_2 , F_41 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_24 ,
F_29 ( V_2 , F_41 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_25 ,
F_29 ( V_2 , F_120 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_26 ,
F_29 ( V_2 , F_120 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_27 ,
F_29 ( V_2 , F_121 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_28 ,
F_29 ( V_2 , F_121 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_29 ,
F_1 ( V_2 , F_25 ( 0 ) ) ) ;
F_15 ( V_2 -> V_86 , L_30 ,
F_1 ( V_2 , F_25 ( 32 ) ) ) ;
F_15 ( V_2 -> V_86 , L_31 ,
F_1 ( V_2 , V_223 ) ) ;
F_15 ( V_2 -> V_86 , L_32 ,
F_1 ( V_2 , V_224 ) ) ;
F_15 ( V_2 -> V_86 , L_33 ,
F_1 ( V_2 , V_225 ) ) ;
F_15 ( V_2 -> V_86 , L_34 ,
F_1 ( V_2 , V_226 ) ) ;
for ( V_101 = 0 ; V_101 < 15 ; V_101 ++ )
F_15 ( V_2 -> V_86 , L_35 , V_101 ,
F_1 ( V_2 , F_84 ( V_101 ) ) ) ;
}
static int F_122 ( struct V_138 * V_139 )
{
struct V_196 * V_227 = V_139 -> V_86 . V_197 ;
struct V_1 * V_2 ;
struct V_228 * V_229 ;
unsigned long V_140 ;
int V_101 , V_144 , V_220 , V_221 ;
const struct V_146 * V_147 ;
V_147 = F_123 ( & V_139 -> V_86 ) ;
if ( ! V_147 )
return - V_70 ;
V_220 = F_124 ( V_139 , 0 ) ;
V_221 = F_124 ( V_139 , 1 ) ;
V_229 = F_125 ( V_139 , V_230 , 0 ) ;
F_15 ( & V_139 -> V_86 , L_36 ,
V_220 , V_221 ) ;
if ( ! V_229 || V_220 < 0 || V_221 < 0 )
return - V_88 ;
V_140 = V_229 -> V_231 ;
V_2 = F_126 ( & V_139 -> V_86 , sizeof( * V_2 ) , V_232 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_6 = F_127 ( V_227 , L_37 ) ;
if ( F_128 ( V_227 , L_38 ) &&
F_129 ( V_233 ) ) {
V_2 -> V_234 = F_130 ( & V_139 -> V_86 ,
L_39 , V_2 -> V_6 ) ;
if ( ! V_2 -> V_234 )
return - V_235 ;
}
for ( V_101 = 0 ; V_101 < 64 ; V_101 ++ )
V_2 -> V_85 [ V_101 ] . V_2 = V_2 ;
V_2 -> V_147 = V_147 ;
V_2 -> V_236 = V_147 -> type ;
F_131 ( & V_2 -> V_97 ) ;
F_132 ( & V_2 -> V_89 ) ;
F_15 ( & V_139 -> V_86 , L_40 ,
V_140 + V_147 -> V_168 ) ;
F_15 ( & V_139 -> V_86 , L_41 ,
V_140 + V_147 -> V_168 + V_237 ) ;
F_15 ( & V_139 -> V_86 , L_42 ,
V_140 + V_147 -> V_148 ) ;
F_15 ( & V_139 -> V_86 , L_43 ,
V_140 + V_147 -> V_150 ) ;
F_15 ( & V_139 -> V_86 , L_44 ,
V_140 + V_147 -> V_153 ) ;
F_15 ( & V_139 -> V_86 , L_45 ,
V_140 + V_147 -> V_156 ) ;
F_15 ( & V_139 -> V_86 , L_46 ,
V_140 + V_147 -> V_164 ) ;
F_15 ( & V_139 -> V_86 , L_47 ,
V_140 + V_147 -> V_166 ) ;
F_15 ( & V_139 -> V_86 , L_48 ,
V_140 + V_147 -> V_174 ) ;
F_15 ( & V_139 -> V_86 , L_49 ,
V_140 + V_147 -> V_157 ) ;
F_15 ( & V_139 -> V_86 , L_50 ,
V_140 + V_147 -> V_168 + V_169 ) ;
F_15 ( & V_139 -> V_86 , L_51 ,
V_140 + V_147 -> V_168 + V_238 ) ;
F_15 ( & V_139 -> V_86 , L_52 ,
V_140 + V_147 -> V_168 + V_172 ) ;
F_15 ( & V_139 -> V_86 , L_53 ,
V_140 + V_147 -> V_159 ) ;
V_2 -> V_4 = F_133 ( & V_139 -> V_86 ,
V_140 + V_147 -> V_168 , V_239 ) ;
V_2 -> V_240 = F_133 ( & V_139 -> V_86 ,
V_140 + V_147 -> V_168 + V_237 ,
V_239 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_240 )
return - V_200 ;
V_2 -> V_141 = F_134 ( & V_139 -> V_86 , L_54 ) ;
if ( F_135 ( V_2 -> V_141 ) ) {
V_144 = F_136 ( V_2 -> V_141 ) ;
F_82 ( & V_139 -> V_86 , L_55 , V_144 ) ;
return V_144 ;
}
F_137 ( V_139 , V_2 ) ;
V_144 = F_138 ( V_2 -> V_141 ) ;
if ( V_144 ) {
F_82 ( & V_139 -> V_86 , L_56 , V_144 ) ;
return V_144 ;
}
V_2 -> V_86 = & V_139 -> V_86 ;
V_2 -> V_220 = V_220 ;
V_2 -> V_221 = V_221 ;
V_144 = F_139 ( & V_139 -> V_86 ) ;
if ( V_144 ) {
F_82 ( & V_139 -> V_86 , L_57 , V_144 ) ;
goto V_241;
}
V_144 = F_54 ( V_2 ) ;
if ( V_144 )
goto V_241;
V_144 = F_111 ( V_2 ) ;
if ( V_144 )
goto V_242;
F_3 ( V_2 , 0x00400000L | ( V_243 << 18 ) ,
V_107 ) ;
V_144 = F_62 ( V_2 , V_139 , V_140 , V_2 -> V_141 ) ;
if ( V_144 )
goto V_244;
V_144 = F_104 ( V_2 , V_140 ) ;
if ( V_144 ) {
F_82 ( & V_139 -> V_86 , L_58 ,
V_144 ) ;
goto V_245;
}
F_106 ( & V_139 -> V_86 , L_59 , V_147 -> V_199 ) ;
return 0 ;
V_245:
F_97 ( V_2 ) ;
V_244:
F_117 ( V_2 ) ;
V_242:
V_241:
F_140 ( V_2 -> V_141 ) ;
return V_144 ;
}
static int F_141 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_142 ( V_139 ) ;
F_102 ( V_139 ) ;
F_97 ( V_2 ) ;
F_117 ( V_2 ) ;
F_140 ( V_2 -> V_141 ) ;
return 0 ;
}
static int T_2 F_143 ( void )
{
return F_144 ( V_246 , F_28 ( V_246 ) ) ;
}
static void T_3 F_145 ( void )
{
F_146 ( V_246 , F_28 ( V_246 ) ) ;
}
