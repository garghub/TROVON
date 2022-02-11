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
void F_6 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_8 ) ;
V_7 |= 0x8 ;
F_3 ( V_2 , V_7 , V_8 ) ;
}
enum V_9 F_7 ( T_1 V_10 )
{
switch ( V_10 ) {
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
case V_27 :
return V_28 ;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
return V_41 ;
default:
return V_42 ;
}
}
enum V_9 F_8 ( T_1 V_43 )
{
switch ( V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return V_41 ;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
return V_28 ;
default:
return V_42 ;
}
}
bool F_9 ( T_1 V_43 )
{
switch ( V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return true ;
}
return false ;
}
enum V_9 F_10 ( T_1 V_58 )
{
switch ( V_58 & 0xf000 ) {
case 0x1000 :
return V_28 ;
case 0x2000 :
return V_41 ;
default:
return V_42 ;
}
}
int F_11 ( T_1 V_59 , T_1 V_43 )
{
switch ( V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return ( 8 * V_59 ) >> 3 ;
case V_57 :
case V_48 :
case V_47 :
return ( 16 * V_59 ) >> 3 ;
case V_56 :
case V_55 :
return ( 24 * V_59 ) >> 3 ;
case V_54 :
case V_53 :
return ( 32 * V_59 ) >> 3 ;
default:
break;
}
return - V_60 ;
}
int F_12 ( enum V_61 * V_62 , int V_63 ,
bool V_64 , bool V_65 )
{
T_1 V_66 , V_67 , V_68 ;
switch ( V_63 ) {
case 0 :
V_67 = V_68 = V_66 = 0 ;
break;
case 90 :
V_67 = V_68 = 0 ;
V_66 = 1 ;
break;
case 180 :
V_67 = V_68 = 1 ;
V_66 = 0 ;
break;
case 270 :
V_67 = V_68 = V_66 = 1 ;
break;
default:
return - V_60 ;
}
V_68 ^= ( T_1 ) V_64 ;
V_67 ^= ( T_1 ) V_65 ;
* V_62 = (enum V_61 ) ( ( V_66 << 2 ) | ( V_68 << 1 ) | V_67 ) ;
return 0 ;
}
int F_13 ( int * V_63 , enum V_61 V_62 ,
bool V_64 , bool V_65 )
{
T_1 V_66 , V_67 , V_68 ;
V_66 = ( ( T_1 ) V_62 >> 2 ) & 0x1 ;
V_68 = ( ( T_1 ) V_62 >> 1 ) & 0x1 ;
V_67 = ( ( T_1 ) V_62 >> 0 ) & 0x1 ;
V_68 ^= ( T_1 ) V_64 ;
V_67 ^= ( T_1 ) V_65 ;
switch ( (enum V_61 ) ( ( V_66 << 2 ) | ( V_68 << 1 ) | V_67 ) ) {
case V_69 :
* V_63 = 0 ;
break;
case V_70 :
* V_63 = 90 ;
break;
case V_71 :
* V_63 = 180 ;
break;
case V_72 :
* V_63 = 270 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
struct V_73 * F_14 ( struct V_1 * V_2 , unsigned V_74 )
{
struct V_73 * V_75 ;
F_15 ( V_2 -> V_76 , L_1 , V_77 , V_74 ) ;
if ( V_74 > 63 )
return F_16 ( - V_78 ) ;
F_17 ( & V_2 -> V_79 ) ;
V_75 = & V_2 -> V_75 [ V_74 ] ;
if ( V_75 -> V_80 ) {
V_75 = F_16 ( - V_81 ) ;
goto V_82;
}
V_75 -> V_80 = true ;
V_75 -> V_74 = V_74 ;
V_82:
F_18 ( & V_2 -> V_79 ) ;
return V_75 ;
}
void F_19 ( struct V_73 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
F_15 ( V_2 -> V_76 , L_1 , V_77 , V_75 -> V_74 ) ;
F_17 ( & V_2 -> V_79 ) ;
V_75 -> V_80 = false ;
F_18 ( & V_2 -> V_79 ) ;
}
static void F_20 ( struct V_73 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned int V_83 = V_75 -> V_74 ;
F_3 ( V_2 , F_21 ( V_83 ) , F_22 ( V_83 ) ) ;
}
void F_23 ( struct V_73 * V_75 ,
bool V_84 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned long V_85 ;
T_1 V_86 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_86 = F_1 ( V_2 , F_25 ( V_75 -> V_74 ) ) ;
if ( V_84 )
V_86 |= F_21 ( V_75 -> V_74 ) ;
else
V_86 &= ~ F_21 ( V_75 -> V_74 ) ;
F_3 ( V_2 , V_86 , F_25 ( V_75 -> V_74 ) ) ;
F_20 ( V_75 ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
}
int F_27 ( struct V_73 * V_75 , int V_88 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned long V_85 ;
T_1 V_89 , V_90 ;
int V_91 ;
switch ( V_88 ) {
case 0 :
case 1 :
V_89 = 0x00 ;
break;
case 2 :
V_89 = 0x01 ;
break;
case 4 :
V_89 = 0x02 ;
break;
case 8 :
V_89 = 0x03 ;
break;
default:
return - V_60 ;
}
for ( V_91 = 0 ; V_91 < F_28 ( V_92 ) ; V_91 ++ ) {
if ( V_75 -> V_74 == V_92 [ V_91 ] . V_93 )
break;
}
if ( V_91 >= F_28 ( V_92 ) )
return - V_60 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_90 = F_29 ( V_2 , V_92 [ V_91 ] . V_86 ) ;
V_90 &= ~ ( 0x03 << V_92 [ V_91 ] . V_94 ) ;
V_90 |= ( V_89 << V_92 [ V_91 ] . V_94 ) ;
F_30 ( V_2 , V_90 , V_92 [ V_91 ] . V_86 ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_95 )
{
unsigned long V_96 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_87 , V_96 ) ;
V_7 = F_1 ( V_2 , V_97 ) ;
if ( V_95 & V_98 )
V_7 |= V_99 ;
if ( V_95 & V_100 )
V_7 |= V_101 ;
F_3 ( V_2 , V_7 , V_97 ) ;
V_7 = F_1 ( V_2 , V_102 ) ;
V_7 |= V_95 ;
F_3 ( V_2 , V_7 , V_102 ) ;
F_26 ( & V_2 -> V_87 , V_96 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_95 )
{
unsigned long V_96 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_87 , V_96 ) ;
V_7 = F_1 ( V_2 , V_102 ) ;
V_7 &= ~ V_95 ;
F_3 ( V_2 , V_7 , V_102 ) ;
V_7 = F_1 ( V_2 , V_97 ) ;
if ( V_95 & V_98 )
V_7 &= ~ V_99 ;
if ( V_95 & V_100 )
V_7 &= ~ V_101 ;
F_3 ( V_2 , V_7 , V_97 ) ;
F_26 ( & V_2 -> V_87 , V_96 ) ;
return 0 ;
}
int F_33 ( struct V_73 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned int V_83 = V_75 -> V_74 ;
return ( F_1 ( V_2 , F_22 ( V_83 ) ) & F_21 ( V_83 ) ) ? 1 : 0 ;
}
bool F_34 ( struct V_73 * V_75 , T_1 V_103 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned long V_85 ;
T_1 V_86 = 0 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
switch ( V_103 ) {
case 0 :
V_86 = F_1 ( V_2 , F_35 ( V_75 -> V_74 ) ) ;
break;
case 1 :
V_86 = F_1 ( V_2 , F_36 ( V_75 -> V_74 ) ) ;
break;
case 2 :
V_86 = F_1 ( V_2 , F_37 ( V_75 -> V_74 ) ) ;
break;
}
F_26 ( & V_2 -> V_87 , V_85 ) ;
return ( ( V_86 & F_21 ( V_75 -> V_74 ) ) != 0 ) ;
}
void F_38 ( struct V_73 * V_75 , T_1 V_103 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned int V_83 = V_75 -> V_74 ;
unsigned long V_85 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
if ( V_103 == 0 )
F_3 ( V_2 , F_21 ( V_83 ) , F_35 ( V_83 ) ) ;
else
F_3 ( V_2 , F_21 ( V_83 ) , F_36 ( V_83 ) ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
}
void F_39 ( struct V_73 * V_75 , T_1 V_103 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned int V_83 = V_75 -> V_74 ;
unsigned long V_85 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
F_3 ( V_2 , 0xF0300000 , V_104 ) ;
switch ( V_103 ) {
case 0 :
F_3 ( V_2 , F_21 ( V_83 ) , F_35 ( V_83 ) ) ;
break;
case 1 :
F_3 ( V_2 , F_21 ( V_83 ) , F_36 ( V_83 ) ) ;
break;
case 2 :
F_3 ( V_2 , F_21 ( V_83 ) , F_37 ( V_83 ) ) ;
break;
default:
break;
}
F_3 ( V_2 , 0x0 , V_104 ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
}
int F_40 ( struct V_73 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
T_1 V_7 ;
unsigned long V_85 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_7 = F_29 ( V_2 , F_41 ( V_75 -> V_74 ) ) ;
V_7 |= F_21 ( V_75 -> V_74 ) ;
F_30 ( V_2 , V_7 , F_41 ( V_75 -> V_74 ) ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
return 0 ;
}
bool F_42 ( struct V_1 * V_2 , unsigned int V_83 )
{
return ( F_29 ( V_2 , F_43 ( V_83 ) ) & F_21 ( V_83 ) ) ;
}
int F_44 ( struct V_73 * V_75 , int V_105 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned long V_106 ;
V_106 = V_107 + F_45 ( V_105 ) ;
while ( F_29 ( V_2 , F_43 ( V_75 -> V_74 ) ) &
F_21 ( V_75 -> V_74 ) ) {
if ( F_46 ( V_107 , V_106 ) )
return - V_108 ;
F_47 () ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 , int V_109 , int V_105 )
{
unsigned long V_106 ;
V_106 = V_107 + F_45 ( V_105 ) ;
F_3 ( V_2 , F_49 ( V_109 % 32 ) , F_50 ( V_109 / 32 ) ) ;
while ( ! ( F_1 ( V_2 , F_50 ( V_109 / 32 ) & F_49 ( V_109 % 32 ) ) ) ) {
if ( F_46 ( V_107 , V_106 ) )
return - V_108 ;
F_47 () ;
}
return 0 ;
}
int F_51 ( struct V_73 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
T_1 V_7 ;
unsigned long V_85 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_7 = F_29 ( V_2 , F_41 ( V_75 -> V_74 ) ) ;
V_7 &= ~ F_21 ( V_75 -> V_74 ) ;
F_30 ( V_2 , V_7 , F_41 ( V_75 -> V_74 ) ) ;
F_20 ( V_75 ) ;
F_3 ( V_2 , 0xf0000000 , V_104 ) ;
if ( F_1 ( V_2 , F_35 ( V_75 -> V_74 ) ) &
F_21 ( V_75 -> V_74 ) ) {
F_3 ( V_2 , F_21 ( V_75 -> V_74 ) ,
F_35 ( V_75 -> V_74 ) ) ;
}
if ( F_1 ( V_2 , F_36 ( V_75 -> V_74 ) ) &
F_21 ( V_75 -> V_74 ) ) {
F_3 ( V_2 , F_21 ( V_75 -> V_74 ) ,
F_36 ( V_75 -> V_74 ) ) ;
}
F_3 ( V_2 , 0x0 , V_104 ) ;
V_7 = F_1 ( V_2 , F_25 ( V_75 -> V_74 ) ) ;
V_7 &= ~ F_21 ( V_75 -> V_74 ) ;
F_3 ( V_2 , V_7 , F_25 ( V_75 -> V_74 ) ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
return 0 ;
}
void F_52 ( struct V_73 * V_75 , bool V_110 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
unsigned long V_85 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_7 = F_29 ( V_2 , F_53 ( V_75 -> V_74 ) ) ;
if ( V_110 )
V_7 |= 1 << ( V_75 -> V_74 % 32 ) ;
else
V_7 &= ~ ( 1 << ( V_75 -> V_74 % 32 ) ) ;
F_30 ( V_2 , V_7 , F_53 ( V_75 -> V_74 ) ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
unsigned long V_106 ;
F_3 ( V_2 , 0x807FFFFF , V_111 ) ;
V_106 = V_107 + F_45 ( 1000 ) ;
while ( F_1 ( V_2 , V_111 ) & 0x80000000 ) {
if ( F_46 ( V_107 , V_106 ) )
return - V_112 ;
F_47 () ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 , int V_113 , bool V_114 )
{
unsigned long V_85 ;
T_1 V_7 , V_95 ;
V_95 = ( V_113 == 1 ) ? V_115 :
V_116 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_7 = F_1 ( V_2 , V_102 ) ;
if ( V_114 )
V_7 |= V_95 ;
else
V_7 &= ~ V_95 ;
F_3 ( V_2 , V_7 , V_102 ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_113 , bool V_117 )
{
unsigned long V_85 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
V_7 = F_1 ( V_2 , V_102 ) ;
if ( V_117 ) {
V_7 |= V_118 ;
} else {
V_7 &= ~ V_118 ;
if ( V_113 == 1 )
V_7 |= V_119 ;
else
V_7 &= ~ V_119 ;
}
F_3 ( V_2 , V_7 , V_102 ) ;
F_26 ( & V_2 -> V_87 , V_85 ) ;
}
static const struct V_120 * F_57 ( int V_121 , int V_122 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < F_28 ( V_120 ) ; V_91 ++ ) {
if ( V_121 == V_120 [ V_91 ] . V_121 . V_83 &&
V_122 == V_120 [ V_91 ] . V_122 . V_83 )
return & V_120 [ V_91 ] ;
}
return NULL ;
}
int F_58 ( struct V_1 * V_2 , int V_123 , int V_124 )
{
const struct V_120 * V_125 ;
T_1 V_126 , V_127 ;
unsigned long V_85 ;
V_125 = F_57 ( V_123 , V_124 ) ;
if ( ! V_125 )
return - V_60 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
if ( V_125 -> V_121 . V_95 ) {
V_126 = F_1 ( V_2 , V_125 -> V_121 . V_86 ) ;
V_126 &= ~ V_125 -> V_121 . V_95 ;
V_126 |= V_125 -> V_121 . V_7 ;
F_3 ( V_2 , V_126 , V_125 -> V_121 . V_86 ) ;
}
if ( V_125 -> V_122 . V_95 ) {
V_127 = F_1 ( V_2 , V_125 -> V_122 . V_86 ) ;
V_127 &= ~ V_125 -> V_122 . V_95 ;
V_127 |= V_125 -> V_122 . V_7 ;
F_3 ( V_2 , V_127 , V_125 -> V_122 . V_86 ) ;
}
F_26 ( & V_2 -> V_87 , V_85 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , int V_123 , int V_124 )
{
const struct V_120 * V_125 ;
T_1 V_126 , V_127 ;
unsigned long V_85 ;
V_125 = F_57 ( V_123 , V_124 ) ;
if ( ! V_125 )
return - V_60 ;
F_24 ( & V_2 -> V_87 , V_85 ) ;
if ( V_125 -> V_121 . V_95 ) {
V_126 = F_1 ( V_2 , V_125 -> V_121 . V_86 ) ;
V_126 &= ~ V_125 -> V_121 . V_95 ;
F_3 ( V_2 , V_126 , V_125 -> V_121 . V_86 ) ;
}
if ( V_125 -> V_122 . V_95 ) {
V_127 = F_1 ( V_2 , V_125 -> V_122 . V_86 ) ;
V_127 &= ~ V_125 -> V_122 . V_95 ;
F_3 ( V_2 , V_127 , V_125 -> V_122 . V_86 ) ;
}
F_26 ( & V_2 -> V_87 , V_85 ) ;
return 0 ;
}
int F_60 ( struct V_73 * V_121 , struct V_73 * V_122 )
{
return F_58 ( V_121 -> V_2 , V_121 -> V_74 , V_122 -> V_74 ) ;
}
int F_61 ( struct V_73 * V_121 , struct V_73 * V_122 )
{
return F_59 ( V_121 -> V_2 , V_121 -> V_74 , V_122 -> V_74 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_128 * V_129 , unsigned long V_130 ,
struct V_131 * V_132 )
{
char * V_133 ;
int V_134 ;
struct V_135 * V_76 = & V_129 -> V_76 ;
const struct V_136 * V_137 = V_2 -> V_137 ;
V_134 = F_63 ( V_2 , V_76 , V_130 + V_137 -> V_138 ) ;
if ( V_134 ) {
V_133 = L_2 ;
goto V_139;
}
V_134 = F_64 ( V_2 , V_76 , 0 , V_130 + V_137 -> V_140 ,
V_141 , V_132 ) ;
if ( V_134 ) {
V_133 = L_3 ;
goto V_142;
}
V_134 = F_64 ( V_2 , V_76 , 1 , V_130 + V_137 -> V_143 ,
V_144 , V_132 ) ;
if ( V_134 ) {
V_133 = L_4 ;
goto V_145;
}
V_134 = F_65 ( V_2 , V_76 ,
V_130 + V_137 -> V_146 ,
V_130 + V_137 -> V_147 ) ;
if ( V_134 ) {
V_133 = L_5 ;
goto V_148;
}
V_134 = F_66 ( V_2 , V_76 , V_130 + V_137 -> V_149 ,
V_150 | V_151 |
V_118 ) ;
if ( V_134 ) {
V_133 = L_6 ;
goto V_152;
}
V_134 = F_67 ( V_2 , V_76 ) ;
if ( V_134 ) {
V_133 = L_7 ;
goto V_153;
}
V_134 = F_68 ( V_2 , V_76 , 0 , V_130 + V_137 -> V_154 ,
V_98 , V_132 ) ;
if ( V_134 ) {
V_133 = L_8 ;
goto V_155;
}
V_134 = F_68 ( V_2 , V_76 , 1 , V_130 + V_137 -> V_156 ,
V_100 , V_132 ) ;
if ( V_134 ) {
V_133 = L_9 ;
goto V_157;
}
V_134 = F_69 ( V_2 , V_76 , V_130 + V_137 -> V_158 +
V_159 , V_130 + V_137 -> V_160 ) ;
if ( V_134 ) {
V_133 = L_10 ;
goto V_161;
}
V_134 = F_70 ( V_2 , V_76 , V_130 +
V_137 -> V_158 + V_162 , V_132 ) ;
if ( V_134 ) {
V_133 = L_11 ;
goto V_163;
}
V_134 = F_71 ( V_2 , V_76 , V_130 + V_137 -> V_164 ) ;
if ( V_134 ) {
V_133 = L_12 ;
goto V_165;
}
V_134 = F_72 ( V_2 , V_76 , V_130 +
V_137 -> V_158 + V_166 ) ;
if ( V_134 ) {
V_133 = L_13 ;
goto V_167;
}
return 0 ;
V_167:
F_73 ( V_2 ) ;
V_165:
F_74 ( V_2 ) ;
V_163:
F_75 ( V_2 ) ;
V_161:
F_76 ( V_2 , 1 ) ;
V_157:
F_76 ( V_2 , 0 ) ;
V_155:
F_77 ( V_2 ) ;
V_153:
F_78 ( V_2 ) ;
V_152:
F_79 ( V_2 ) ;
V_148:
F_80 ( V_2 , 1 ) ;
V_145:
F_80 ( V_2 , 0 ) ;
V_142:
F_81 ( V_2 ) ;
V_139:
F_82 ( & V_129 -> V_76 , L_14 , V_133 , V_134 ) ;
return V_134 ;
}
static void F_83 ( struct V_1 * V_2 , const int * V_168 , int V_169 )
{
unsigned long V_170 ;
int V_91 , V_171 , V_109 ;
for ( V_91 = 0 ; V_91 < V_169 ; V_91 ++ ) {
V_170 = F_1 ( V_2 , F_50 ( V_168 [ V_91 ] ) ) ;
V_170 &= F_1 ( V_2 , F_84 ( V_168 [ V_91 ] ) ) ;
F_85 (bit, &status, 32 ) {
V_109 = F_86 ( V_2 -> V_172 ,
V_168 [ V_91 ] * 32 + V_171 ) ;
if ( V_109 )
F_87 ( V_109 ) ;
}
}
}
static void F_88 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = F_89 ( V_174 ) ;
struct V_175 * V_176 = F_90 ( V_174 ) ;
const int V_177 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
F_91 ( V_176 , V_174 ) ;
F_83 ( V_2 , V_177 , F_28 ( V_177 ) ) ;
F_92 ( V_176 , V_174 ) ;
}
static void F_93 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = F_89 ( V_174 ) ;
struct V_175 * V_176 = F_90 ( V_174 ) ;
const int V_177 [] = { 4 , 5 , 8 , 9 } ;
F_91 ( V_176 , V_174 ) ;
F_83 ( V_2 , V_177 , F_28 ( V_177 ) ) ;
F_92 ( V_176 , V_174 ) ;
}
int F_94 ( struct V_1 * V_2 , int V_109 )
{
int V_178 ;
V_178 = F_86 ( V_2 -> V_172 , V_109 ) ;
if ( ! V_178 )
V_178 = F_95 ( V_2 -> V_172 , V_109 ) ;
return V_178 ;
}
int F_96 ( struct V_1 * V_2 , struct V_73 * V_75 ,
enum V_179 V_180 )
{
return F_94 ( V_2 , V_180 + V_75 -> V_74 ) ;
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
static int F_99 ( struct V_135 * V_76 , void * V_181 )
{
struct V_128 * V_129 = F_100 ( V_76 ) ;
F_101 ( V_129 ) ;
return 0 ;
}
static void F_102 ( struct V_128 * V_129 )
{
F_103 ( & V_129 -> V_76 , NULL , F_99 ) ;
}
static int F_104 ( struct V_1 * V_2 , unsigned long V_130 )
{
struct V_135 * V_76 = V_2 -> V_76 ;
unsigned V_91 ;
int V_6 , V_134 ;
F_17 ( & V_182 ) ;
V_6 = V_183 ;
V_183 += F_28 ( V_184 ) ;
F_18 ( & V_182 ) ;
for ( V_91 = 0 ; V_91 < F_28 ( V_184 ) ; V_91 ++ ) {
struct V_185 * V_86 = & V_184 [ V_91 ] ;
struct V_128 * V_129 ;
struct V_186 * V_187 ;
V_187 = F_105 ( V_76 -> V_187 , V_91 ) ;
if ( ! V_187 ) {
F_106 ( V_76 ,
L_15 ,
V_91 , V_76 -> V_187 -> V_188 ,
( V_91 / 2 ) ? L_16 : L_17 , V_91 % 2 ) ;
continue;
}
V_129 = F_107 ( V_86 -> V_189 , V_6 ++ ) ;
if ( ! V_129 ) {
V_134 = - V_190 ;
goto V_191;
}
V_129 -> V_76 . V_192 = V_76 ;
V_86 -> V_193 . V_187 = V_187 ;
V_134 = F_108 ( V_129 , & V_86 -> V_193 ,
sizeof( V_86 -> V_193 ) ) ;
if ( ! V_134 )
V_134 = F_109 ( V_129 ) ;
if ( V_134 ) {
F_110 ( V_129 ) ;
goto V_191;
}
V_129 -> V_76 . V_187 = V_187 ;
}
return 0 ;
V_191:
F_102 ( F_100 ( V_76 ) ) ;
return V_134 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_194 * V_195 ;
struct V_196 * V_197 ;
unsigned long V_181 [ V_198 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_134 , V_91 ;
V_2 -> V_172 = F_112 ( V_2 -> V_76 -> V_187 , V_198 ,
& V_199 , V_2 ) ;
if ( ! V_2 -> V_172 ) {
F_82 ( V_2 -> V_76 , L_18 ) ;
return - V_78 ;
}
V_134 = F_113 ( V_2 -> V_172 , 32 , 1 , L_19 ,
V_200 , 0 , 0 , 0 ) ;
if ( V_134 < 0 ) {
F_82 ( V_2 -> V_76 , L_20 ) ;
F_114 ( V_2 -> V_172 ) ;
return V_134 ;
}
for ( V_91 = 0 ; V_91 < V_198 ; V_91 += 32 ) {
F_3 ( V_2 , 0 , F_84 ( V_91 / 32 ) ) ;
F_3 ( V_2 , ~ V_181 [ V_91 / 32 ] , F_50 ( V_91 / 32 ) ) ;
}
for ( V_91 = 0 ; V_91 < V_198 ; V_91 += 32 ) {
V_195 = F_115 ( V_2 -> V_172 , V_91 ) ;
V_195 -> V_201 = V_2 -> V_4 ;
V_195 -> V_181 = V_181 [ V_91 / 32 ] ;
V_197 = V_195 -> V_202 ;
V_197 -> V_176 . V_203 = V_204 ;
V_197 -> V_176 . V_205 = V_206 ;
V_197 -> V_176 . V_207 = V_208 ;
V_197 -> V_168 . V_209 = F_50 ( V_91 / 32 ) ;
V_197 -> V_168 . V_95 = F_84 ( V_91 / 32 ) ;
}
F_116 ( V_2 -> V_210 , F_88 , V_2 ) ;
F_116 ( V_2 -> V_211 , F_93 ,
V_2 ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_91 , V_109 ;
F_116 ( V_2 -> V_211 , NULL , NULL ) ;
F_116 ( V_2 -> V_210 , NULL , NULL ) ;
for ( V_91 = 0 ; V_91 < V_198 ; V_91 ++ ) {
V_109 = F_86 ( V_2 -> V_172 , V_91 ) ;
if ( V_109 )
F_118 ( V_109 ) ;
}
F_114 ( V_2 -> V_172 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
int V_91 ;
F_15 ( V_2 -> V_76 , L_21 ,
F_1 ( V_2 , V_102 ) ) ;
F_15 ( V_2 -> V_76 , L_22 ,
F_29 ( V_2 , V_212 ) ) ;
F_15 ( V_2 -> V_76 , L_23 ,
F_29 ( V_2 , F_41 ( 0 ) ) ) ;
F_15 ( V_2 -> V_76 , L_24 ,
F_29 ( V_2 , F_41 ( 32 ) ) ) ;
F_15 ( V_2 -> V_76 , L_25 ,
F_29 ( V_2 , F_120 ( 0 ) ) ) ;
F_15 ( V_2 -> V_76 , L_26 ,
F_29 ( V_2 , F_120 ( 32 ) ) ) ;
F_15 ( V_2 -> V_76 , L_27 ,
F_29 ( V_2 , F_121 ( 0 ) ) ) ;
F_15 ( V_2 -> V_76 , L_28 ,
F_29 ( V_2 , F_121 ( 32 ) ) ) ;
F_15 ( V_2 -> V_76 , L_29 ,
F_1 ( V_2 , F_25 ( 0 ) ) ) ;
F_15 ( V_2 -> V_76 , L_30 ,
F_1 ( V_2 , F_25 ( 32 ) ) ) ;
F_15 ( V_2 -> V_76 , L_31 ,
F_1 ( V_2 , V_213 ) ) ;
F_15 ( V_2 -> V_76 , L_32 ,
F_1 ( V_2 , V_214 ) ) ;
F_15 ( V_2 -> V_76 , L_33 ,
F_1 ( V_2 , V_215 ) ) ;
F_15 ( V_2 -> V_76 , L_34 ,
F_1 ( V_2 , V_216 ) ) ;
for ( V_91 = 0 ; V_91 < 15 ; V_91 ++ )
F_15 ( V_2 -> V_76 , L_35 , V_91 ,
F_1 ( V_2 , F_84 ( V_91 ) ) ) ;
}
static int F_122 ( struct V_128 * V_129 )
{
struct V_186 * V_217 = V_129 -> V_76 . V_187 ;
struct V_1 * V_2 ;
struct V_218 * V_219 ;
unsigned long V_130 ;
int V_91 , V_134 , V_210 , V_211 ;
const struct V_136 * V_137 ;
V_137 = F_123 ( & V_129 -> V_76 ) ;
if ( ! V_137 )
return - V_60 ;
V_210 = F_124 ( V_129 , 0 ) ;
V_211 = F_124 ( V_129 , 1 ) ;
V_219 = F_125 ( V_129 , V_220 , 0 ) ;
F_15 ( & V_129 -> V_76 , L_36 ,
V_210 , V_211 ) ;
if ( ! V_219 || V_210 < 0 || V_211 < 0 )
return - V_78 ;
V_130 = V_219 -> V_221 ;
V_2 = F_126 ( & V_129 -> V_76 , sizeof( * V_2 ) , V_222 ) ;
if ( ! V_2 )
return - V_78 ;
for ( V_91 = 0 ; V_91 < 64 ; V_91 ++ )
V_2 -> V_75 [ V_91 ] . V_2 = V_2 ;
V_2 -> V_137 = V_137 ;
V_2 -> V_223 = V_137 -> type ;
V_2 -> V_6 = F_127 ( V_217 , L_37 ) ;
F_128 ( & V_2 -> V_87 ) ;
F_129 ( & V_2 -> V_79 ) ;
F_15 ( & V_129 -> V_76 , L_38 ,
V_130 + V_137 -> V_158 ) ;
F_15 ( & V_129 -> V_76 , L_39 ,
V_130 + V_137 -> V_158 + V_224 ) ;
F_15 ( & V_129 -> V_76 , L_40 ,
V_130 + V_137 -> V_138 ) ;
F_15 ( & V_129 -> V_76 , L_41 ,
V_130 + V_137 -> V_140 ) ;
F_15 ( & V_129 -> V_76 , L_42 ,
V_130 + V_137 -> V_143 ) ;
F_15 ( & V_129 -> V_76 , L_43 ,
V_130 + V_137 -> V_146 ) ;
F_15 ( & V_129 -> V_76 , L_44 ,
V_130 + V_137 -> V_154 ) ;
F_15 ( & V_129 -> V_76 , L_45 ,
V_130 + V_137 -> V_156 ) ;
F_15 ( & V_129 -> V_76 , L_46 ,
V_130 + V_137 -> V_164 ) ;
F_15 ( & V_129 -> V_76 , L_47 ,
V_130 + V_137 -> V_147 ) ;
F_15 ( & V_129 -> V_76 , L_48 ,
V_130 + V_137 -> V_158 + V_159 ) ;
F_15 ( & V_129 -> V_76 , L_49 ,
V_130 + V_137 -> V_158 + V_225 ) ;
F_15 ( & V_129 -> V_76 , L_50 ,
V_130 + V_137 -> V_158 + V_162 ) ;
F_15 ( & V_129 -> V_76 , L_51 ,
V_130 + V_137 -> V_149 ) ;
V_2 -> V_4 = F_130 ( & V_129 -> V_76 ,
V_130 + V_137 -> V_158 , V_226 ) ;
V_2 -> V_227 = F_130 ( & V_129 -> V_76 ,
V_130 + V_137 -> V_158 + V_224 ,
V_226 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_227 )
return - V_190 ;
V_2 -> V_131 = F_131 ( & V_129 -> V_76 , L_52 ) ;
if ( F_132 ( V_2 -> V_131 ) ) {
V_134 = F_133 ( V_2 -> V_131 ) ;
F_82 ( & V_129 -> V_76 , L_53 , V_134 ) ;
return V_134 ;
}
F_134 ( V_129 , V_2 ) ;
V_134 = F_135 ( V_2 -> V_131 ) ;
if ( V_134 ) {
F_82 ( & V_129 -> V_76 , L_54 , V_134 ) ;
return V_134 ;
}
V_2 -> V_76 = & V_129 -> V_76 ;
V_2 -> V_210 = V_210 ;
V_2 -> V_211 = V_211 ;
V_134 = F_136 ( & V_129 -> V_76 ) ;
if ( V_134 ) {
F_82 ( & V_129 -> V_76 , L_55 , V_134 ) ;
goto V_228;
}
V_134 = F_54 ( V_2 ) ;
if ( V_134 )
goto V_228;
V_134 = F_111 ( V_2 ) ;
if ( V_134 )
goto V_229;
F_3 ( V_2 , 0x00400000L | ( V_230 << 18 ) ,
V_97 ) ;
V_134 = F_62 ( V_2 , V_129 , V_130 , V_2 -> V_131 ) ;
if ( V_134 )
goto V_231;
V_134 = F_104 ( V_2 , V_130 ) ;
if ( V_134 ) {
F_82 ( & V_129 -> V_76 , L_56 ,
V_134 ) ;
goto V_232;
}
F_106 ( & V_129 -> V_76 , L_57 , V_137 -> V_189 ) ;
return 0 ;
V_232:
F_97 ( V_2 ) ;
V_231:
F_117 ( V_2 ) ;
V_229:
V_228:
F_137 ( V_2 -> V_131 ) ;
return V_134 ;
}
static int F_138 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_139 ( V_129 ) ;
F_102 ( V_129 ) ;
F_97 ( V_2 ) ;
F_117 ( V_2 ) ;
F_137 ( V_2 -> V_131 ) ;
return 0 ;
}
