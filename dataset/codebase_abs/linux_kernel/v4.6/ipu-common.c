static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= 0x8 ;
F_3 ( V_2 , V_6 , V_7 ) ;
}
enum V_8 F_6 ( T_1 V_9 )
{
switch ( V_9 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
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
return V_27 ;
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
default:
return V_39 ;
}
}
enum V_8 F_7 ( T_1 V_40 )
{
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return V_38 ;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
return V_27 ;
default:
return V_39 ;
}
}
bool F_8 ( T_1 V_40 )
{
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return true ;
}
return false ;
}
enum V_8 F_9 ( T_1 V_55 )
{
switch ( V_55 & 0xf000 ) {
case 0x1000 :
return V_27 ;
case 0x2000 :
return V_38 ;
default:
return V_39 ;
}
}
int F_10 ( T_1 V_56 , T_1 V_40 )
{
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return ( 8 * V_56 ) >> 3 ;
case V_54 :
case V_45 :
case V_44 :
return ( 16 * V_56 ) >> 3 ;
case V_53 :
case V_52 :
return ( 24 * V_56 ) >> 3 ;
case V_51 :
case V_50 :
return ( 32 * V_56 ) >> 3 ;
default:
break;
}
return - V_57 ;
}
int F_11 ( enum V_58 * V_59 , int V_60 ,
bool V_61 , bool V_62 )
{
T_1 V_63 , V_64 , V_65 ;
switch ( V_60 ) {
case 0 :
V_64 = V_65 = V_63 = 0 ;
break;
case 90 :
V_64 = V_65 = 0 ;
V_63 = 1 ;
break;
case 180 :
V_64 = V_65 = 1 ;
V_63 = 0 ;
break;
case 270 :
V_64 = V_65 = V_63 = 1 ;
break;
default:
return - V_57 ;
}
V_65 ^= ( T_1 ) V_61 ;
V_64 ^= ( T_1 ) V_62 ;
* V_59 = (enum V_58 ) ( ( V_63 << 2 ) | ( V_65 << 1 ) | V_64 ) ;
return 0 ;
}
int F_12 ( int * V_60 , enum V_58 V_59 ,
bool V_61 , bool V_62 )
{
T_1 V_63 , V_64 , V_65 ;
V_63 = ( ( T_1 ) V_59 >> 2 ) & 0x1 ;
V_65 = ( ( T_1 ) V_59 >> 1 ) & 0x1 ;
V_64 = ( ( T_1 ) V_59 >> 0 ) & 0x1 ;
V_65 ^= ( T_1 ) V_61 ;
V_64 ^= ( T_1 ) V_62 ;
switch ( (enum V_58 ) ( ( V_63 << 2 ) | ( V_65 << 1 ) | V_64 ) ) {
case V_66 :
* V_60 = 0 ;
break;
case V_67 :
* V_60 = 90 ;
break;
case V_68 :
* V_60 = 180 ;
break;
case V_69 :
* V_60 = 270 ;
break;
default:
return - V_57 ;
}
return 0 ;
}
struct V_70 * F_13 ( struct V_1 * V_2 , unsigned V_71 )
{
struct V_70 * V_72 ;
F_14 ( V_2 -> V_73 , L_1 , V_74 , V_71 ) ;
if ( V_71 > 63 )
return F_15 ( - V_75 ) ;
F_16 ( & V_2 -> V_76 ) ;
V_72 = & V_2 -> V_72 [ V_71 ] ;
if ( V_72 -> V_77 ) {
V_72 = F_15 ( - V_78 ) ;
goto V_79;
}
V_72 -> V_77 = true ;
V_72 -> V_71 = V_71 ;
V_79:
F_17 ( & V_2 -> V_76 ) ;
return V_72 ;
}
void F_18 ( struct V_70 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
F_14 ( V_2 -> V_73 , L_1 , V_74 , V_72 -> V_71 ) ;
F_16 ( & V_2 -> V_76 ) ;
V_72 -> V_77 = false ;
F_17 ( & V_2 -> V_76 ) ;
}
static void F_19 ( struct V_70 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_80 = V_72 -> V_71 ;
F_3 ( V_2 , F_20 ( V_80 ) , F_21 ( V_80 ) ) ;
}
void F_22 ( struct V_70 * V_72 ,
bool V_81 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_82 ;
T_1 V_83 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_83 = F_1 ( V_2 , F_24 ( V_72 -> V_71 ) ) ;
if ( V_81 )
V_83 |= F_20 ( V_72 -> V_71 ) ;
else
V_83 &= ~ F_20 ( V_72 -> V_71 ) ;
F_3 ( V_2 , V_83 , F_24 ( V_72 -> V_71 ) ) ;
F_19 ( V_72 ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
}
int F_26 ( struct V_70 * V_72 , int V_85 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_82 ;
T_1 V_86 , V_87 ;
int V_88 ;
switch ( V_85 ) {
case 0 :
case 1 :
V_86 = 0x00 ;
break;
case 2 :
V_86 = 0x01 ;
break;
case 4 :
V_86 = 0x02 ;
break;
case 8 :
V_86 = 0x03 ;
break;
default:
return - V_57 ;
}
for ( V_88 = 0 ; V_88 < F_27 ( V_89 ) ; V_88 ++ ) {
if ( V_72 -> V_71 == V_89 [ V_88 ] . V_90 )
break;
}
if ( V_88 >= F_27 ( V_89 ) )
return - V_57 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_87 = F_28 ( V_2 , V_89 [ V_88 ] . V_83 ) ;
V_87 &= ~ ( 0x03 << V_89 [ V_88 ] . V_91 ) ;
V_87 |= ( V_86 << V_89 [ V_88 ] . V_91 ) ;
F_29 ( V_2 , V_87 , V_89 [ V_88 ] . V_83 ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_92 )
{
unsigned long V_93 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_84 , V_93 ) ;
V_6 = F_1 ( V_2 , V_94 ) ;
if ( V_92 & V_95 )
V_6 |= V_96 ;
if ( V_92 & V_97 )
V_6 |= V_98 ;
F_3 ( V_2 , V_6 , V_94 ) ;
V_6 = F_1 ( V_2 , V_99 ) ;
V_6 |= V_92 ;
F_3 ( V_2 , V_6 , V_99 ) ;
F_25 ( & V_2 -> V_84 , V_93 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_92 )
{
unsigned long V_93 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_84 , V_93 ) ;
V_6 = F_1 ( V_2 , V_99 ) ;
V_6 &= ~ V_92 ;
F_3 ( V_2 , V_6 , V_99 ) ;
V_6 = F_1 ( V_2 , V_94 ) ;
if ( V_92 & V_95 )
V_6 &= ~ V_96 ;
if ( V_92 & V_97 )
V_6 &= ~ V_98 ;
F_3 ( V_2 , V_6 , V_94 ) ;
F_25 ( & V_2 -> V_84 , V_93 ) ;
return 0 ;
}
int F_32 ( struct V_70 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_80 = V_72 -> V_71 ;
return ( F_1 ( V_2 , F_21 ( V_80 ) ) & F_20 ( V_80 ) ) ? 1 : 0 ;
}
bool F_33 ( struct V_70 * V_72 , T_1 V_100 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_82 ;
T_1 V_83 = 0 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
switch ( V_100 ) {
case 0 :
V_83 = F_1 ( V_2 , F_34 ( V_72 -> V_71 ) ) ;
break;
case 1 :
V_83 = F_1 ( V_2 , F_35 ( V_72 -> V_71 ) ) ;
break;
case 2 :
V_83 = F_1 ( V_2 , F_36 ( V_72 -> V_71 ) ) ;
break;
}
F_25 ( & V_2 -> V_84 , V_82 ) ;
return ( ( V_83 & F_20 ( V_72 -> V_71 ) ) != 0 ) ;
}
void F_37 ( struct V_70 * V_72 , T_1 V_100 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_80 = V_72 -> V_71 ;
unsigned long V_82 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
if ( V_100 == 0 )
F_3 ( V_2 , F_20 ( V_80 ) , F_34 ( V_80 ) ) ;
else
F_3 ( V_2 , F_20 ( V_80 ) , F_35 ( V_80 ) ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
}
void F_38 ( struct V_70 * V_72 , T_1 V_100 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_80 = V_72 -> V_71 ;
unsigned long V_82 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
F_3 ( V_2 , 0xF0300000 , V_101 ) ;
switch ( V_100 ) {
case 0 :
F_3 ( V_2 , F_20 ( V_80 ) , F_34 ( V_80 ) ) ;
break;
case 1 :
F_3 ( V_2 , F_20 ( V_80 ) , F_35 ( V_80 ) ) ;
break;
case 2 :
F_3 ( V_2 , F_20 ( V_80 ) , F_36 ( V_80 ) ) ;
break;
default:
break;
}
F_3 ( V_2 , 0x0 , V_101 ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
}
int F_39 ( struct V_70 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
T_1 V_6 ;
unsigned long V_82 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_6 = F_28 ( V_2 , F_40 ( V_72 -> V_71 ) ) ;
V_6 |= F_20 ( V_72 -> V_71 ) ;
F_29 ( V_2 , V_6 , F_40 ( V_72 -> V_71 ) ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
return 0 ;
}
bool F_41 ( struct V_1 * V_2 , unsigned int V_80 )
{
return ( F_28 ( V_2 , F_42 ( V_80 ) ) & F_20 ( V_80 ) ) ;
}
int F_43 ( struct V_70 * V_72 , int V_102 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_103 ;
V_103 = V_104 + F_44 ( V_102 ) ;
while ( F_28 ( V_2 , F_42 ( V_72 -> V_71 ) ) &
F_20 ( V_72 -> V_71 ) ) {
if ( F_45 ( V_104 , V_103 ) )
return - V_105 ;
F_46 () ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_106 , int V_102 )
{
unsigned long V_103 ;
V_103 = V_104 + F_44 ( V_102 ) ;
F_3 ( V_2 , F_48 ( V_106 % 32 ) , F_49 ( V_106 / 32 ) ) ;
while ( ! ( F_1 ( V_2 , F_49 ( V_106 / 32 ) & F_48 ( V_106 % 32 ) ) ) ) {
if ( F_45 ( V_104 , V_103 ) )
return - V_105 ;
F_46 () ;
}
return 0 ;
}
int F_50 ( struct V_70 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
T_1 V_6 ;
unsigned long V_82 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_6 = F_28 ( V_2 , F_40 ( V_72 -> V_71 ) ) ;
V_6 &= ~ F_20 ( V_72 -> V_71 ) ;
F_29 ( V_2 , V_6 , F_40 ( V_72 -> V_71 ) ) ;
F_19 ( V_72 ) ;
F_3 ( V_2 , 0xf0000000 , V_101 ) ;
if ( F_1 ( V_2 , F_34 ( V_72 -> V_71 ) ) &
F_20 ( V_72 -> V_71 ) ) {
F_3 ( V_2 , F_20 ( V_72 -> V_71 ) ,
F_34 ( V_72 -> V_71 ) ) ;
}
if ( F_1 ( V_2 , F_35 ( V_72 -> V_71 ) ) &
F_20 ( V_72 -> V_71 ) ) {
F_3 ( V_2 , F_20 ( V_72 -> V_71 ) ,
F_35 ( V_72 -> V_71 ) ) ;
}
F_3 ( V_2 , 0x0 , V_101 ) ;
V_6 = F_1 ( V_2 , F_24 ( V_72 -> V_71 ) ) ;
V_6 &= ~ F_20 ( V_72 -> V_71 ) ;
F_3 ( V_2 , V_6 , F_24 ( V_72 -> V_71 ) ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
return 0 ;
}
void F_51 ( struct V_70 * V_72 , bool V_107 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_82 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_6 = F_28 ( V_2 , F_52 ( V_72 -> V_71 ) ) ;
if ( V_107 )
V_6 |= 1 << ( V_72 -> V_71 % 32 ) ;
else
V_6 &= ~ ( 1 << ( V_72 -> V_71 % 32 ) ) ;
F_29 ( V_2 , V_6 , F_52 ( V_72 -> V_71 ) ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned long V_103 ;
F_3 ( V_2 , 0x807FFFFF , V_108 ) ;
V_103 = V_104 + F_44 ( 1000 ) ;
while ( F_1 ( V_2 , V_108 ) & 0x80000000 ) {
if ( F_45 ( V_104 , V_103 ) )
return - V_109 ;
F_46 () ;
}
return 0 ;
}
void F_54 ( struct V_1 * V_2 , int V_110 , bool V_111 )
{
unsigned long V_82 ;
T_1 V_6 , V_92 ;
V_92 = ( V_110 == 1 ) ? V_112 :
V_113 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_6 = F_1 ( V_2 , V_99 ) ;
if ( V_111 )
V_6 |= V_92 ;
else
V_6 &= ~ V_92 ;
F_3 ( V_2 , V_6 , V_99 ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
}
void F_55 ( struct V_1 * V_2 , int V_110 , bool V_114 )
{
unsigned long V_82 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_84 , V_82 ) ;
V_6 = F_1 ( V_2 , V_99 ) ;
if ( V_114 ) {
V_6 |= V_115 ;
} else {
V_6 &= ~ V_115 ;
if ( V_110 == 1 )
V_6 |= V_116 ;
else
V_6 &= ~ V_116 ;
}
F_3 ( V_2 , V_6 , V_99 ) ;
F_25 ( & V_2 -> V_84 , V_82 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_119 ,
struct V_120 * V_121 )
{
char * V_122 ;
int V_123 ;
struct V_124 * V_73 = & V_118 -> V_73 ;
const struct V_125 * V_126 = V_2 -> V_126 ;
V_123 = F_57 ( V_2 , V_73 , V_119 + V_126 -> V_127 ) ;
if ( V_123 ) {
V_122 = L_2 ;
goto V_128;
}
V_123 = F_58 ( V_2 , V_73 , 0 , V_119 + V_126 -> V_129 ,
V_130 , V_121 ) ;
if ( V_123 ) {
V_122 = L_3 ;
goto V_131;
}
V_123 = F_58 ( V_2 , V_73 , 1 , V_119 + V_126 -> V_132 ,
V_133 , V_121 ) ;
if ( V_123 ) {
V_122 = L_4 ;
goto V_134;
}
V_123 = F_59 ( V_2 , V_73 ,
V_119 + V_126 -> V_135 ,
V_119 + V_126 -> V_136 ) ;
if ( V_123 ) {
V_122 = L_5 ;
goto V_137;
}
V_123 = F_60 ( V_2 , V_73 , 0 , V_119 + V_126 -> V_138 ,
V_95 , V_121 ) ;
if ( V_123 ) {
V_122 = L_6 ;
goto V_139;
}
V_123 = F_60 ( V_2 , V_73 , 1 , V_119 + V_126 -> V_140 ,
V_97 , V_121 ) ;
if ( V_123 ) {
V_122 = L_7 ;
goto V_141;
}
V_123 = F_61 ( V_2 , V_73 , V_119 + V_126 -> V_142 +
V_143 , V_119 + V_126 -> V_144 ) ;
if ( V_123 ) {
V_122 = L_8 ;
goto V_145;
}
V_123 = F_62 ( V_2 , V_73 , V_119 +
V_126 -> V_142 + V_146 , V_121 ) ;
if ( V_123 ) {
V_122 = L_9 ;
goto V_147;
}
V_123 = F_63 ( V_2 , V_73 , V_119 + V_126 -> V_148 ) ;
if ( V_123 ) {
V_122 = L_10 ;
goto V_149;
}
V_123 = F_64 ( V_2 , V_73 , V_119 +
V_126 -> V_142 + V_150 ) ;
if ( V_123 ) {
V_122 = L_11 ;
goto V_151;
}
return 0 ;
V_151:
F_65 ( V_2 ) ;
V_149:
F_66 ( V_2 ) ;
V_147:
F_67 ( V_2 ) ;
V_145:
F_68 ( V_2 , 1 ) ;
V_141:
F_68 ( V_2 , 0 ) ;
V_139:
F_69 ( V_2 ) ;
V_137:
F_70 ( V_2 , 1 ) ;
V_134:
F_70 ( V_2 , 0 ) ;
V_131:
F_71 ( V_2 ) ;
V_128:
F_72 ( & V_118 -> V_73 , L_12 , V_122 , V_123 ) ;
return V_123 ;
}
static void F_73 ( struct V_1 * V_2 , const int * V_152 , int V_153 )
{
unsigned long V_154 ;
int V_88 , V_155 , V_106 ;
for ( V_88 = 0 ; V_88 < V_153 ; V_88 ++ ) {
V_154 = F_1 ( V_2 , F_49 ( V_152 [ V_88 ] ) ) ;
V_154 &= F_1 ( V_2 , F_74 ( V_152 [ V_88 ] ) ) ;
F_75 (bit, &status, 32 ) {
V_106 = F_76 ( V_2 -> V_156 ,
V_152 [ V_88 ] * 32 + V_155 ) ;
if ( V_106 )
F_77 ( V_106 ) ;
}
}
}
static void F_78 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_79 ( V_158 ) ;
struct V_159 * V_160 = F_80 ( V_158 ) ;
const int V_161 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
F_81 ( V_160 , V_158 ) ;
F_73 ( V_2 , V_161 , F_27 ( V_161 ) ) ;
F_82 ( V_160 , V_158 ) ;
}
static void F_83 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_79 ( V_158 ) ;
struct V_159 * V_160 = F_80 ( V_158 ) ;
const int V_161 [] = { 4 , 5 , 8 , 9 } ;
F_81 ( V_160 , V_158 ) ;
F_73 ( V_2 , V_161 , F_27 ( V_161 ) ) ;
F_82 ( V_160 , V_158 ) ;
}
int F_84 ( struct V_1 * V_2 , int V_106 )
{
int V_162 ;
V_162 = F_76 ( V_2 -> V_156 , V_106 ) ;
if ( ! V_162 )
V_162 = F_85 ( V_2 -> V_156 , V_106 ) ;
return V_162 ;
}
int F_86 ( struct V_1 * V_2 , struct V_70 * V_72 ,
enum V_163 V_164 )
{
return F_84 ( V_2 , V_164 + V_72 -> V_71 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_88 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 , 1 ) ;
F_68 ( V_2 , 0 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 , 1 ) ;
F_70 ( V_2 , 0 ) ;
F_71 ( V_2 ) ;
}
static int F_89 ( struct V_124 * V_73 , void * V_165 )
{
struct V_117 * V_118 = F_90 ( V_73 ) ;
F_91 ( V_118 ) ;
return 0 ;
}
static void F_92 ( struct V_117 * V_118 )
{
F_93 ( & V_118 -> V_73 , NULL , F_89 ) ;
}
static int F_94 ( struct V_1 * V_2 , unsigned long V_119 )
{
struct V_124 * V_73 = V_2 -> V_73 ;
unsigned V_88 ;
int V_166 , V_123 ;
F_16 ( & V_167 ) ;
V_166 = V_168 ;
V_168 += F_27 ( V_169 ) ;
F_17 ( & V_167 ) ;
for ( V_88 = 0 ; V_88 < F_27 ( V_169 ) ; V_88 ++ ) {
const struct V_170 * V_83 = & V_169 [ V_88 ] ;
struct V_117 * V_118 ;
struct V_171 * V_172 ;
V_172 = F_95 ( V_73 -> V_172 , V_88 ) ;
if ( ! V_172 ) {
F_96 ( V_73 ,
L_13 ,
V_88 , V_73 -> V_172 -> V_173 ,
( V_88 / 2 ) ? L_14 : L_15 , V_88 % 2 ) ;
continue;
}
V_118 = F_97 ( V_83 -> V_174 , V_166 ++ ) ;
if ( ! V_118 ) {
V_123 = - V_175 ;
goto V_176;
}
V_118 -> V_73 . V_177 = V_73 ;
V_123 = F_98 ( V_118 , & V_83 -> V_178 ,
sizeof( V_83 -> V_178 ) ) ;
if ( ! V_123 )
V_123 = F_99 ( V_118 ) ;
if ( V_123 ) {
F_100 ( V_118 ) ;
goto V_176;
}
V_118 -> V_73 . V_172 = V_172 ;
}
return 0 ;
V_176:
F_92 ( F_90 ( V_73 ) ) ;
return V_123 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_179 * V_180 ;
struct V_181 * V_182 ;
unsigned long V_165 [ V_183 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_123 , V_88 ;
V_2 -> V_156 = F_102 ( V_2 -> V_73 -> V_172 , V_183 ,
& V_184 , V_2 ) ;
if ( ! V_2 -> V_156 ) {
F_72 ( V_2 -> V_73 , L_16 ) ;
return - V_75 ;
}
V_123 = F_103 ( V_2 -> V_156 , 32 , 1 , L_17 ,
V_185 , 0 , 0 , 0 ) ;
if ( V_123 < 0 ) {
F_72 ( V_2 -> V_73 , L_18 ) ;
F_104 ( V_2 -> V_156 ) ;
return V_123 ;
}
for ( V_88 = 0 ; V_88 < V_183 ; V_88 += 32 )
F_3 ( V_2 , 0 , F_74 ( V_88 / 32 ) ) ;
for ( V_88 = 0 ; V_88 < V_183 ; V_88 += 32 ) {
V_180 = F_105 ( V_2 -> V_156 , V_88 ) ;
V_180 -> V_186 = V_2 -> V_4 ;
V_180 -> V_165 = V_165 [ V_88 / 32 ] ;
V_182 = V_180 -> V_187 ;
V_182 -> V_160 . V_188 = V_189 ;
V_182 -> V_160 . V_190 = V_191 ;
V_182 -> V_160 . V_192 = V_193 ;
V_182 -> V_152 . V_194 = F_49 ( V_88 / 32 ) ;
V_182 -> V_152 . V_92 = F_74 ( V_88 / 32 ) ;
}
F_106 ( V_2 -> V_195 , F_78 , V_2 ) ;
F_106 ( V_2 -> V_196 , F_83 ,
V_2 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_88 , V_106 ;
F_106 ( V_2 -> V_196 , NULL , NULL ) ;
F_106 ( V_2 -> V_195 , NULL , NULL ) ;
for ( V_88 = 0 ; V_88 < V_183 ; V_88 ++ ) {
V_106 = F_76 ( V_2 -> V_156 , V_88 ) ;
if ( V_106 )
F_108 ( V_106 ) ;
}
F_104 ( V_2 -> V_156 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
int V_88 ;
F_14 ( V_2 -> V_73 , L_19 ,
F_1 ( V_2 , V_99 ) ) ;
F_14 ( V_2 -> V_73 , L_20 ,
F_28 ( V_2 , V_197 ) ) ;
F_14 ( V_2 -> V_73 , L_21 ,
F_28 ( V_2 , F_40 ( 0 ) ) ) ;
F_14 ( V_2 -> V_73 , L_22 ,
F_28 ( V_2 , F_40 ( 32 ) ) ) ;
F_14 ( V_2 -> V_73 , L_23 ,
F_28 ( V_2 , F_110 ( 0 ) ) ) ;
F_14 ( V_2 -> V_73 , L_24 ,
F_28 ( V_2 , F_110 ( 32 ) ) ) ;
F_14 ( V_2 -> V_73 , L_25 ,
F_28 ( V_2 , F_111 ( 0 ) ) ) ;
F_14 ( V_2 -> V_73 , L_26 ,
F_28 ( V_2 , F_111 ( 32 ) ) ) ;
F_14 ( V_2 -> V_73 , L_27 ,
F_1 ( V_2 , F_24 ( 0 ) ) ) ;
F_14 ( V_2 -> V_73 , L_28 ,
F_1 ( V_2 , F_24 ( 32 ) ) ) ;
F_14 ( V_2 -> V_73 , L_29 ,
F_1 ( V_2 , V_198 ) ) ;
F_14 ( V_2 -> V_73 , L_30 ,
F_1 ( V_2 , V_199 ) ) ;
F_14 ( V_2 -> V_73 , L_31 ,
F_1 ( V_2 , V_200 ) ) ;
F_14 ( V_2 -> V_73 , L_32 ,
F_1 ( V_2 , V_201 ) ) ;
for ( V_88 = 0 ; V_88 < 15 ; V_88 ++ )
F_14 ( V_2 -> V_73 , L_33 , V_88 ,
F_1 ( V_2 , F_74 ( V_88 ) ) ) ;
}
static int F_112 ( struct V_117 * V_118 )
{
const struct V_202 * V_203 =
F_113 ( V_204 , & V_118 -> V_73 ) ;
struct V_1 * V_2 ;
struct V_205 * V_206 ;
unsigned long V_119 ;
int V_88 , V_123 , V_195 , V_196 ;
const struct V_125 * V_126 ;
V_126 = V_203 -> V_207 ;
V_195 = F_114 ( V_118 , 0 ) ;
V_196 = F_114 ( V_118 , 1 ) ;
V_206 = F_115 ( V_118 , V_208 , 0 ) ;
F_14 ( & V_118 -> V_73 , L_34 ,
V_195 , V_196 ) ;
if ( ! V_206 || V_195 < 0 || V_196 < 0 )
return - V_75 ;
V_119 = V_206 -> V_209 ;
V_2 = F_116 ( & V_118 -> V_73 , sizeof( * V_2 ) , V_210 ) ;
if ( ! V_2 )
return - V_75 ;
for ( V_88 = 0 ; V_88 < 64 ; V_88 ++ )
V_2 -> V_72 [ V_88 ] . V_2 = V_2 ;
V_2 -> V_126 = V_126 ;
V_2 -> V_211 = V_126 -> type ;
F_117 ( & V_2 -> V_84 ) ;
F_118 ( & V_2 -> V_76 ) ;
F_14 ( & V_118 -> V_73 , L_35 ,
V_119 + V_126 -> V_142 ) ;
F_14 ( & V_118 -> V_73 , L_36 ,
V_119 + V_126 -> V_142 + V_212 ) ;
F_14 ( & V_118 -> V_73 , L_37 ,
V_119 + V_126 -> V_127 ) ;
F_14 ( & V_118 -> V_73 , L_38 ,
V_119 + V_126 -> V_129 ) ;
F_14 ( & V_118 -> V_73 , L_39 ,
V_119 + V_126 -> V_132 ) ;
F_14 ( & V_118 -> V_73 , L_40 ,
V_119 + V_126 -> V_135 ) ;
F_14 ( & V_118 -> V_73 , L_41 ,
V_119 + V_126 -> V_138 ) ;
F_14 ( & V_118 -> V_73 , L_42 ,
V_119 + V_126 -> V_140 ) ;
F_14 ( & V_118 -> V_73 , L_43 ,
V_119 + V_126 -> V_148 ) ;
F_14 ( & V_118 -> V_73 , L_44 ,
V_119 + V_126 -> V_136 ) ;
F_14 ( & V_118 -> V_73 , L_45 ,
V_119 + V_126 -> V_142 + V_143 ) ;
F_14 ( & V_118 -> V_73 , L_46 ,
V_119 + V_126 -> V_142 + V_213 ) ;
F_14 ( & V_118 -> V_73 , L_47 ,
V_119 + V_126 -> V_142 + V_146 ) ;
F_14 ( & V_118 -> V_73 , L_48 ,
V_119 + V_126 -> V_214 ) ;
V_2 -> V_4 = F_119 ( & V_118 -> V_73 ,
V_119 + V_126 -> V_142 , V_215 ) ;
V_2 -> V_216 = F_119 ( & V_118 -> V_73 ,
V_119 + V_126 -> V_142 + V_212 ,
V_215 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_216 )
return - V_175 ;
V_2 -> V_120 = F_120 ( & V_118 -> V_73 , L_49 ) ;
if ( F_121 ( V_2 -> V_120 ) ) {
V_123 = F_122 ( V_2 -> V_120 ) ;
F_72 ( & V_118 -> V_73 , L_50 , V_123 ) ;
return V_123 ;
}
F_123 ( V_118 , V_2 ) ;
V_123 = F_124 ( V_2 -> V_120 ) ;
if ( V_123 ) {
F_72 ( & V_118 -> V_73 , L_51 , V_123 ) ;
return V_123 ;
}
V_2 -> V_73 = & V_118 -> V_73 ;
V_2 -> V_195 = V_195 ;
V_2 -> V_196 = V_196 ;
V_123 = F_125 ( & V_118 -> V_73 ) ;
if ( V_123 ) {
F_72 ( & V_118 -> V_73 , L_52 , V_123 ) ;
goto V_217;
}
V_123 = F_53 ( V_2 ) ;
if ( V_123 )
goto V_217;
V_123 = F_101 ( V_2 ) ;
if ( V_123 )
goto V_218;
F_3 ( V_2 , 0x00400000L | ( V_219 << 18 ) ,
V_94 ) ;
V_123 = F_56 ( V_2 , V_118 , V_119 , V_2 -> V_120 ) ;
if ( V_123 )
goto V_220;
V_123 = F_94 ( V_2 , V_119 ) ;
if ( V_123 ) {
F_72 ( & V_118 -> V_73 , L_53 ,
V_123 ) ;
goto V_221;
}
F_96 ( & V_118 -> V_73 , L_54 , V_126 -> V_174 ) ;
return 0 ;
V_221:
F_87 ( V_2 ) ;
V_220:
F_107 ( V_2 ) ;
V_218:
V_217:
F_126 ( V_2 -> V_120 ) ;
return V_123 ;
}
static int F_127 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_128 ( V_118 ) ;
F_92 ( V_118 ) ;
F_87 ( V_2 ) ;
F_107 ( V_2 ) ;
F_126 ( V_2 -> V_120 ) ;
return 0 ;
}
