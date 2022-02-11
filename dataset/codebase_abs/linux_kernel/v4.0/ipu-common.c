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
return V_22 ;
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
return V_33 ;
default:
return V_34 ;
}
}
enum V_8 F_7 ( T_1 V_35 )
{
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return V_33 ;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return V_22 ;
default:
return V_34 ;
}
}
bool F_8 ( T_1 V_35 )
{
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return true ;
}
return false ;
}
enum V_8 F_9 ( T_1 V_50 )
{
switch ( V_50 & 0xf000 ) {
case 0x1000 :
return V_22 ;
case 0x2000 :
return V_33 ;
default:
return V_34 ;
}
}
int F_10 ( T_1 V_51 , T_1 V_35 )
{
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return ( 8 * V_51 ) >> 3 ;
case V_49 :
case V_40 :
case V_39 :
return ( 16 * V_51 ) >> 3 ;
case V_48 :
case V_47 :
return ( 24 * V_51 ) >> 3 ;
case V_46 :
case V_45 :
return ( 32 * V_51 ) >> 3 ;
default:
break;
}
return - V_52 ;
}
int F_11 ( enum V_53 * V_54 , int V_55 ,
bool V_56 , bool V_57 )
{
T_1 V_58 , V_59 , V_60 ;
switch ( V_55 ) {
case 0 :
V_59 = V_60 = V_58 = 0 ;
break;
case 90 :
V_59 = V_60 = 0 ;
V_58 = 1 ;
break;
case 180 :
V_59 = V_60 = 1 ;
V_58 = 0 ;
break;
case 270 :
V_59 = V_60 = V_58 = 1 ;
break;
default:
return - V_52 ;
}
V_60 ^= ( T_1 ) V_56 ;
V_59 ^= ( T_1 ) V_57 ;
* V_54 = (enum V_53 ) ( ( V_58 << 2 ) | ( V_60 << 1 ) | V_59 ) ;
return 0 ;
}
int F_12 ( int * V_55 , enum V_53 V_54 ,
bool V_56 , bool V_57 )
{
T_1 V_58 , V_59 , V_60 ;
V_58 = ( ( T_1 ) V_54 >> 2 ) & 0x1 ;
V_60 = ( ( T_1 ) V_54 >> 1 ) & 0x1 ;
V_59 = ( ( T_1 ) V_54 >> 0 ) & 0x1 ;
V_60 ^= ( T_1 ) V_56 ;
V_59 ^= ( T_1 ) V_57 ;
switch ( (enum V_53 ) ( ( V_58 << 2 ) | ( V_60 << 1 ) | V_59 ) ) {
case V_61 :
* V_55 = 0 ;
break;
case V_62 :
* V_55 = 90 ;
break;
case V_63 :
* V_55 = 180 ;
break;
case V_64 :
* V_55 = 270 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
struct V_65 * F_13 ( struct V_1 * V_2 , unsigned V_66 )
{
struct V_65 * V_67 ;
F_14 ( V_2 -> V_68 , L_1 , V_69 , V_66 ) ;
if ( V_66 > 63 )
return F_15 ( - V_70 ) ;
F_16 ( & V_2 -> V_71 ) ;
V_67 = & V_2 -> V_67 [ V_66 ] ;
if ( V_67 -> V_72 ) {
V_67 = F_15 ( - V_73 ) ;
goto V_74;
}
V_67 -> V_72 = true ;
V_67 -> V_66 = V_66 ;
V_74:
F_17 ( & V_2 -> V_71 ) ;
return V_67 ;
}
void F_18 ( struct V_65 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
F_14 ( V_2 -> V_68 , L_1 , V_69 , V_67 -> V_66 ) ;
F_16 ( & V_2 -> V_71 ) ;
V_67 -> V_72 = false ;
F_17 ( & V_2 -> V_71 ) ;
}
static void F_19 ( struct V_65 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned int V_75 = V_67 -> V_66 ;
F_3 ( V_2 , F_20 ( V_75 ) , F_21 ( V_75 ) ) ;
}
void F_22 ( struct V_65 * V_67 ,
bool V_76 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned long V_77 ;
T_1 V_78 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_78 = F_1 ( V_2 , F_24 ( V_67 -> V_66 ) ) ;
if ( V_76 )
V_78 |= F_20 ( V_67 -> V_66 ) ;
else
V_78 &= ~ F_20 ( V_67 -> V_66 ) ;
F_3 ( V_2 , V_78 , F_24 ( V_67 -> V_66 ) ) ;
F_19 ( V_67 ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
}
int F_26 ( struct V_65 * V_67 , int V_80 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned long V_77 ;
T_1 V_81 , V_82 ;
int V_83 ;
switch ( V_80 ) {
case 0 :
case 1 :
V_81 = 0x00 ;
break;
case 2 :
V_81 = 0x01 ;
break;
case 4 :
V_81 = 0x02 ;
break;
case 8 :
V_81 = 0x03 ;
break;
default:
return - V_52 ;
}
for ( V_83 = 0 ; V_83 < F_27 ( V_84 ) ; V_83 ++ ) {
if ( V_67 -> V_66 == V_84 [ V_83 ] . V_85 )
break;
}
if ( V_83 >= F_27 ( V_84 ) )
return - V_52 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_82 = F_28 ( V_2 , V_84 [ V_83 ] . V_78 ) ;
V_82 &= ~ ( 0x03 << V_84 [ V_83 ] . V_86 ) ;
V_82 |= ( V_81 << V_84 [ V_83 ] . V_86 ) ;
F_29 ( V_2 , V_82 , V_84 [ V_83 ] . V_78 ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_87 )
{
unsigned long V_88 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_79 , V_88 ) ;
V_6 = F_1 ( V_2 , V_89 ) ;
if ( V_87 & V_90 )
V_6 |= V_91 ;
if ( V_87 & V_92 )
V_6 |= V_93 ;
F_3 ( V_2 , V_6 , V_89 ) ;
V_6 = F_1 ( V_2 , V_94 ) ;
V_6 |= V_87 ;
F_3 ( V_2 , V_6 , V_94 ) ;
F_25 ( & V_2 -> V_79 , V_88 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_87 )
{
unsigned long V_88 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_79 , V_88 ) ;
V_6 = F_1 ( V_2 , V_94 ) ;
V_6 &= ~ V_87 ;
F_3 ( V_2 , V_6 , V_94 ) ;
V_6 = F_1 ( V_2 , V_89 ) ;
if ( V_87 & V_90 )
V_6 &= ~ V_91 ;
if ( V_87 & V_92 )
V_6 &= ~ V_93 ;
F_3 ( V_2 , V_6 , V_89 ) ;
F_25 ( & V_2 -> V_79 , V_88 ) ;
return 0 ;
}
int F_32 ( struct V_65 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned int V_75 = V_67 -> V_66 ;
return ( F_1 ( V_2 , F_21 ( V_75 ) ) & F_20 ( V_75 ) ) ? 1 : 0 ;
}
bool F_33 ( struct V_65 * V_67 , T_1 V_95 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned long V_77 ;
T_1 V_78 = 0 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
switch ( V_95 ) {
case 0 :
V_78 = F_1 ( V_2 , F_34 ( V_67 -> V_66 ) ) ;
break;
case 1 :
V_78 = F_1 ( V_2 , F_35 ( V_67 -> V_66 ) ) ;
break;
case 2 :
V_78 = F_1 ( V_2 , F_36 ( V_67 -> V_66 ) ) ;
break;
}
F_25 ( & V_2 -> V_79 , V_77 ) ;
return ( ( V_78 & F_20 ( V_67 -> V_66 ) ) != 0 ) ;
}
void F_37 ( struct V_65 * V_67 , T_1 V_95 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned int V_75 = V_67 -> V_66 ;
unsigned long V_77 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
if ( V_95 == 0 )
F_3 ( V_2 , F_20 ( V_75 ) , F_34 ( V_75 ) ) ;
else
F_3 ( V_2 , F_20 ( V_75 ) , F_35 ( V_75 ) ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
}
void F_38 ( struct V_65 * V_67 , T_1 V_95 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned int V_75 = V_67 -> V_66 ;
unsigned long V_77 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
F_3 ( V_2 , 0xF0300000 , V_96 ) ;
switch ( V_95 ) {
case 0 :
F_3 ( V_2 , F_20 ( V_75 ) , F_34 ( V_75 ) ) ;
break;
case 1 :
F_3 ( V_2 , F_20 ( V_75 ) , F_35 ( V_75 ) ) ;
break;
case 2 :
F_3 ( V_2 , F_20 ( V_75 ) , F_36 ( V_75 ) ) ;
break;
default:
break;
}
F_3 ( V_2 , 0x0 , V_96 ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
}
int F_39 ( struct V_65 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
T_1 V_6 ;
unsigned long V_77 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_6 = F_28 ( V_2 , F_40 ( V_67 -> V_66 ) ) ;
V_6 |= F_20 ( V_67 -> V_66 ) ;
F_29 ( V_2 , V_6 , F_40 ( V_67 -> V_66 ) ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
return 0 ;
}
bool F_41 ( struct V_1 * V_2 , unsigned int V_75 )
{
return ( F_28 ( V_2 , F_42 ( V_75 ) ) & F_20 ( V_75 ) ) ;
}
int F_43 ( struct V_65 * V_67 , int V_97 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned long V_98 ;
V_98 = V_99 + F_44 ( V_97 ) ;
while ( F_28 ( V_2 , F_42 ( V_67 -> V_66 ) ) &
F_20 ( V_67 -> V_66 ) ) {
if ( F_45 ( V_99 , V_98 ) )
return - V_100 ;
F_46 () ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_101 , int V_97 )
{
unsigned long V_98 ;
V_98 = V_99 + F_44 ( V_97 ) ;
F_3 ( V_2 , F_48 ( V_101 % 32 ) , F_49 ( V_101 / 32 ) ) ;
while ( ! ( F_1 ( V_2 , F_49 ( V_101 / 32 ) & F_48 ( V_101 % 32 ) ) ) ) {
if ( F_45 ( V_99 , V_98 ) )
return - V_100 ;
F_46 () ;
}
return 0 ;
}
int F_50 ( struct V_65 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
T_1 V_6 ;
unsigned long V_77 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_6 = F_28 ( V_2 , F_40 ( V_67 -> V_66 ) ) ;
V_6 &= ~ F_20 ( V_67 -> V_66 ) ;
F_29 ( V_2 , V_6 , F_40 ( V_67 -> V_66 ) ) ;
F_19 ( V_67 ) ;
F_3 ( V_2 , 0xf0000000 , V_96 ) ;
if ( F_1 ( V_2 , F_34 ( V_67 -> V_66 ) ) &
F_20 ( V_67 -> V_66 ) ) {
F_3 ( V_2 , F_20 ( V_67 -> V_66 ) ,
F_34 ( V_67 -> V_66 ) ) ;
}
if ( F_1 ( V_2 , F_35 ( V_67 -> V_66 ) ) &
F_20 ( V_67 -> V_66 ) ) {
F_3 ( V_2 , F_20 ( V_67 -> V_66 ) ,
F_35 ( V_67 -> V_66 ) ) ;
}
F_3 ( V_2 , 0x0 , V_96 ) ;
V_6 = F_1 ( V_2 , F_24 ( V_67 -> V_66 ) ) ;
V_6 &= ~ F_20 ( V_67 -> V_66 ) ;
F_3 ( V_2 , V_6 , F_24 ( V_67 -> V_66 ) ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
return 0 ;
}
void F_51 ( struct V_65 * V_67 , bool V_102 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
unsigned long V_77 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_6 = F_28 ( V_2 , F_52 ( V_67 -> V_66 ) ) ;
if ( V_102 )
V_6 |= 1 << ( V_67 -> V_66 % 32 ) ;
else
V_6 &= ~ ( 1 << ( V_67 -> V_66 % 32 ) ) ;
F_29 ( V_2 , V_6 , F_52 ( V_67 -> V_66 ) ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
unsigned long V_98 ;
F_3 ( V_2 , 0x807FFFFF , V_103 ) ;
V_98 = V_99 + F_44 ( 1000 ) ;
while ( F_1 ( V_2 , V_103 ) & 0x80000000 ) {
if ( F_45 ( V_99 , V_98 ) )
return - V_104 ;
F_46 () ;
}
return 0 ;
}
void F_54 ( struct V_1 * V_2 , int V_105 , bool V_106 )
{
unsigned long V_77 ;
T_1 V_6 , V_87 ;
V_87 = ( V_105 == 1 ) ? V_107 :
V_108 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_6 = F_1 ( V_2 , V_94 ) ;
if ( V_106 )
V_6 |= V_87 ;
else
V_6 &= ~ V_87 ;
F_3 ( V_2 , V_6 , V_94 ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
}
void F_55 ( struct V_1 * V_2 , int V_105 , bool V_109 )
{
unsigned long V_77 ;
T_1 V_6 ;
F_23 ( & V_2 -> V_79 , V_77 ) ;
V_6 = F_1 ( V_2 , V_94 ) ;
if ( V_109 ) {
V_6 |= V_110 ;
} else {
V_6 &= ~ V_110 ;
if ( V_105 == 1 )
V_6 |= V_111 ;
else
V_6 &= ~ V_111 ;
}
F_3 ( V_2 , V_6 , V_94 ) ;
F_25 ( & V_2 -> V_79 , V_77 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_112 * V_113 , unsigned long V_114 ,
struct V_115 * V_116 )
{
char * V_117 ;
int V_118 ;
struct V_119 * V_68 = & V_113 -> V_68 ;
const struct V_120 * V_121 = V_2 -> V_121 ;
V_118 = F_57 ( V_2 , V_68 , V_114 + V_121 -> V_122 ) ;
if ( V_118 ) {
V_117 = L_2 ;
goto V_123;
}
V_118 = F_58 ( V_2 , V_68 , 0 , V_114 + V_121 -> V_124 ,
V_125 , V_116 ) ;
if ( V_118 ) {
V_117 = L_3 ;
goto V_126;
}
V_118 = F_58 ( V_2 , V_68 , 1 , V_114 + V_121 -> V_127 ,
V_128 , V_116 ) ;
if ( V_118 ) {
V_117 = L_4 ;
goto V_129;
}
V_118 = F_59 ( V_2 , V_68 ,
V_114 + V_121 -> V_130 ,
V_114 + V_121 -> V_131 ) ;
if ( V_118 ) {
V_117 = L_5 ;
goto V_132;
}
V_118 = F_60 ( V_2 , V_68 , 0 , V_114 + V_121 -> V_133 ,
V_90 , V_116 ) ;
if ( V_118 ) {
V_117 = L_6 ;
goto V_134;
}
V_118 = F_60 ( V_2 , V_68 , 1 , V_114 + V_121 -> V_135 ,
V_92 , V_116 ) ;
if ( V_118 ) {
V_117 = L_7 ;
goto V_136;
}
V_118 = F_61 ( V_2 , V_68 , V_114 + V_121 -> V_137 +
V_138 , V_114 + V_121 -> V_139 ) ;
if ( V_118 ) {
V_117 = L_8 ;
goto V_140;
}
V_118 = F_62 ( V_2 , V_68 , V_114 +
V_121 -> V_137 + V_141 , V_116 ) ;
if ( V_118 ) {
V_117 = L_9 ;
goto V_142;
}
V_118 = F_63 ( V_2 , V_68 , V_114 + V_121 -> V_143 ) ;
if ( V_118 ) {
V_117 = L_10 ;
goto V_144;
}
V_118 = F_64 ( V_2 , V_68 , V_114 +
V_121 -> V_137 + V_145 ) ;
if ( V_118 ) {
V_117 = L_11 ;
goto V_146;
}
return 0 ;
V_146:
F_65 ( V_2 ) ;
V_144:
F_66 ( V_2 ) ;
V_142:
F_67 ( V_2 ) ;
V_140:
F_68 ( V_2 , 1 ) ;
V_136:
F_68 ( V_2 , 0 ) ;
V_134:
F_69 ( V_2 ) ;
V_132:
F_70 ( V_2 , 1 ) ;
V_129:
F_70 ( V_2 , 0 ) ;
V_126:
F_71 ( V_2 ) ;
V_123:
F_72 ( & V_113 -> V_68 , L_12 , V_117 , V_118 ) ;
return V_118 ;
}
static void F_73 ( struct V_1 * V_2 , const int * V_147 , int V_148 )
{
unsigned long V_149 ;
int V_83 , V_150 , V_101 ;
for ( V_83 = 0 ; V_83 < V_148 ; V_83 ++ ) {
V_149 = F_1 ( V_2 , F_49 ( V_147 [ V_83 ] ) ) ;
V_149 &= F_1 ( V_2 , F_74 ( V_147 [ V_83 ] ) ) ;
F_75 (bit, &status, 32 ) {
V_101 = F_76 ( V_2 -> V_151 ,
V_147 [ V_83 ] * 32 + V_150 ) ;
if ( V_101 )
F_77 ( V_101 ) ;
}
}
}
static void F_78 ( unsigned int V_101 , struct V_152 * V_153 )
{
struct V_1 * V_2 = F_79 ( V_153 ) ;
const int V_154 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
struct V_155 * V_156 = F_80 ( V_101 ) ;
F_81 ( V_156 , V_153 ) ;
F_73 ( V_2 , V_154 , F_27 ( V_154 ) ) ;
F_82 ( V_156 , V_153 ) ;
}
static void F_83 ( unsigned int V_101 , struct V_152 * V_153 )
{
struct V_1 * V_2 = F_79 ( V_153 ) ;
const int V_154 [] = { 4 , 5 , 8 , 9 } ;
struct V_155 * V_156 = F_80 ( V_101 ) ;
F_81 ( V_156 , V_153 ) ;
F_73 ( V_2 , V_154 , F_27 ( V_154 ) ) ;
F_82 ( V_156 , V_153 ) ;
}
int F_84 ( struct V_1 * V_2 , int V_101 )
{
int V_157 ;
V_157 = F_76 ( V_2 -> V_151 , V_101 ) ;
if ( ! V_157 )
V_157 = F_85 ( V_2 -> V_151 , V_101 ) ;
return V_157 ;
}
int F_86 ( struct V_1 * V_2 , struct V_65 * V_67 ,
enum V_158 V_159 )
{
return F_84 ( V_2 , V_159 + V_67 -> V_66 ) ;
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
static int F_89 ( struct V_119 * V_68 , void * V_160 )
{
struct V_112 * V_113 = F_90 ( V_68 ) ;
F_91 ( V_113 ) ;
return 0 ;
}
static void F_92 ( struct V_112 * V_113 )
{
F_93 ( & V_113 -> V_68 , NULL , F_89 ) ;
}
static int F_94 ( struct V_1 * V_2 , unsigned long V_114 )
{
struct V_119 * V_68 = V_2 -> V_68 ;
unsigned V_83 ;
int V_161 , V_118 ;
F_16 ( & V_162 ) ;
V_161 = V_163 ;
V_163 += F_27 ( V_164 ) ;
F_17 ( & V_162 ) ;
for ( V_83 = 0 ; V_83 < F_27 ( V_164 ) ; V_83 ++ ) {
const struct V_165 * V_78 = & V_164 [ V_83 ] ;
struct V_112 * V_113 ;
struct V_166 V_167 ;
if ( V_78 -> V_168 ) {
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_77 = V_169 ;
V_167 . V_170 = V_114 + V_2 -> V_121 -> V_137 + V_78 -> V_168 ;
V_167 . V_171 = V_167 . V_170 + V_172 - 1 ;
V_113 = F_95 ( V_68 , V_78 -> V_173 ,
V_161 ++ , & V_167 , 1 , & V_78 -> V_174 , sizeof( V_78 -> V_174 ) ) ;
} else {
V_113 = F_96 ( V_68 , V_78 -> V_173 ,
V_161 ++ , & V_78 -> V_174 , sizeof( V_78 -> V_174 ) ) ;
}
if ( F_97 ( V_113 ) ) {
V_118 = F_98 ( V_113 ) ;
goto V_175;
}
}
return 0 ;
V_175:
F_92 ( F_90 ( V_68 ) ) ;
return V_118 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
unsigned long V_160 [ V_180 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_118 , V_83 ;
V_2 -> V_151 = F_100 ( V_2 -> V_68 -> V_181 , V_180 ,
& V_182 , V_2 ) ;
if ( ! V_2 -> V_151 ) {
F_72 ( V_2 -> V_68 , L_13 ) ;
return - V_70 ;
}
V_118 = F_101 ( V_2 -> V_151 , 32 , 1 , L_14 ,
V_183 , 0 ,
V_184 , 0 ) ;
if ( V_118 < 0 ) {
F_72 ( V_2 -> V_68 , L_15 ) ;
F_102 ( V_2 -> V_151 ) ;
return V_118 ;
}
for ( V_83 = 0 ; V_83 < V_180 ; V_83 += 32 ) {
V_177 = F_103 ( V_2 -> V_151 , V_83 ) ;
V_177 -> V_185 = V_2 -> V_4 ;
V_177 -> V_160 = V_160 [ V_83 / 32 ] ;
V_179 = V_177 -> V_186 ;
V_179 -> V_156 . V_187 = V_188 ;
V_179 -> V_156 . V_189 = V_190 ;
V_179 -> V_156 . V_191 = V_192 ;
V_179 -> V_147 . V_193 = F_49 ( V_83 / 32 ) ;
V_179 -> V_147 . V_87 = F_74 ( V_83 / 32 ) ;
}
F_104 ( V_2 -> V_194 , F_78 ) ;
F_105 ( V_2 -> V_194 , V_2 ) ;
F_104 ( V_2 -> V_195 , F_83 ) ;
F_105 ( V_2 -> V_195 , V_2 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
int V_83 , V_101 ;
F_104 ( V_2 -> V_195 , NULL ) ;
F_105 ( V_2 -> V_195 , NULL ) ;
F_104 ( V_2 -> V_194 , NULL ) ;
F_105 ( V_2 -> V_194 , NULL ) ;
for ( V_83 = 0 ; V_83 < V_180 ; V_83 ++ ) {
V_101 = F_76 ( V_2 -> V_151 , V_83 ) ;
if ( V_101 )
F_107 ( V_101 ) ;
}
F_102 ( V_2 -> V_151 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
int V_83 ;
F_14 ( V_2 -> V_68 , L_16 ,
F_1 ( V_2 , V_94 ) ) ;
F_14 ( V_2 -> V_68 , L_17 ,
F_28 ( V_2 , V_196 ) ) ;
F_14 ( V_2 -> V_68 , L_18 ,
F_28 ( V_2 , F_40 ( 0 ) ) ) ;
F_14 ( V_2 -> V_68 , L_19 ,
F_28 ( V_2 , F_40 ( 32 ) ) ) ;
F_14 ( V_2 -> V_68 , L_20 ,
F_28 ( V_2 , F_109 ( 0 ) ) ) ;
F_14 ( V_2 -> V_68 , L_21 ,
F_28 ( V_2 , F_109 ( 32 ) ) ) ;
F_14 ( V_2 -> V_68 , L_22 ,
F_28 ( V_2 , F_110 ( 0 ) ) ) ;
F_14 ( V_2 -> V_68 , L_23 ,
F_28 ( V_2 , F_110 ( 32 ) ) ) ;
F_14 ( V_2 -> V_68 , L_24 ,
F_1 ( V_2 , F_24 ( 0 ) ) ) ;
F_14 ( V_2 -> V_68 , L_25 ,
F_1 ( V_2 , F_24 ( 32 ) ) ) ;
F_14 ( V_2 -> V_68 , L_26 ,
F_1 ( V_2 , V_197 ) ) ;
F_14 ( V_2 -> V_68 , L_27 ,
F_1 ( V_2 , V_198 ) ) ;
F_14 ( V_2 -> V_68 , L_28 ,
F_1 ( V_2 , V_199 ) ) ;
F_14 ( V_2 -> V_68 , L_29 ,
F_1 ( V_2 , V_200 ) ) ;
for ( V_83 = 0 ; V_83 < 15 ; V_83 ++ )
F_14 ( V_2 -> V_68 , L_30 , V_83 ,
F_1 ( V_2 , F_74 ( V_83 ) ) ) ;
}
static int F_111 ( struct V_112 * V_113 )
{
const struct V_201 * V_202 =
F_112 ( V_203 , & V_113 -> V_68 ) ;
struct V_1 * V_2 ;
struct V_166 * V_167 ;
unsigned long V_114 ;
int V_83 , V_118 , V_194 , V_195 ;
const struct V_120 * V_121 ;
V_121 = V_202 -> V_204 ;
V_194 = F_113 ( V_113 , 0 ) ;
V_195 = F_113 ( V_113 , 1 ) ;
V_167 = F_114 ( V_113 , V_169 , 0 ) ;
F_14 ( & V_113 -> V_68 , L_31 ,
V_194 , V_195 ) ;
if ( ! V_167 || V_194 < 0 || V_195 < 0 )
return - V_70 ;
V_114 = V_167 -> V_170 ;
V_2 = F_115 ( & V_113 -> V_68 , sizeof( * V_2 ) , V_205 ) ;
if ( ! V_2 )
return - V_70 ;
for ( V_83 = 0 ; V_83 < 64 ; V_83 ++ )
V_2 -> V_67 [ V_83 ] . V_2 = V_2 ;
V_2 -> V_121 = V_121 ;
V_2 -> V_206 = V_121 -> type ;
F_116 ( & V_2 -> V_79 ) ;
F_117 ( & V_2 -> V_71 ) ;
F_14 ( & V_113 -> V_68 , L_32 ,
V_114 + V_121 -> V_137 ) ;
F_14 ( & V_113 -> V_68 , L_33 ,
V_114 + V_121 -> V_137 + V_207 ) ;
F_14 ( & V_113 -> V_68 , L_34 ,
V_114 + V_121 -> V_122 ) ;
F_14 ( & V_113 -> V_68 , L_35 ,
V_114 + V_121 -> V_124 ) ;
F_14 ( & V_113 -> V_68 , L_36 ,
V_114 + V_121 -> V_127 ) ;
F_14 ( & V_113 -> V_68 , L_37 ,
V_114 + V_121 -> V_130 ) ;
F_14 ( & V_113 -> V_68 , L_38 ,
V_114 + V_121 -> V_133 ) ;
F_14 ( & V_113 -> V_68 , L_39 ,
V_114 + V_121 -> V_135 ) ;
F_14 ( & V_113 -> V_68 , L_40 ,
V_114 + V_121 -> V_143 ) ;
F_14 ( & V_113 -> V_68 , L_41 ,
V_114 + V_121 -> V_131 ) ;
F_14 ( & V_113 -> V_68 , L_42 ,
V_114 + V_121 -> V_137 + V_138 ) ;
F_14 ( & V_113 -> V_68 , L_43 ,
V_114 + V_121 -> V_137 + V_208 ) ;
F_14 ( & V_113 -> V_68 , L_44 ,
V_114 + V_121 -> V_137 + V_141 ) ;
F_14 ( & V_113 -> V_68 , L_45 ,
V_114 + V_121 -> V_209 ) ;
V_2 -> V_4 = F_118 ( & V_113 -> V_68 ,
V_114 + V_121 -> V_137 , V_172 ) ;
V_2 -> V_210 = F_118 ( & V_113 -> V_68 ,
V_114 + V_121 -> V_137 + V_207 ,
V_172 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_210 )
return - V_211 ;
V_2 -> V_115 = F_119 ( & V_113 -> V_68 , L_46 ) ;
if ( F_97 ( V_2 -> V_115 ) ) {
V_118 = F_98 ( V_2 -> V_115 ) ;
F_72 ( & V_113 -> V_68 , L_47 , V_118 ) ;
return V_118 ;
}
F_120 ( V_113 , V_2 ) ;
V_118 = F_121 ( V_2 -> V_115 ) ;
if ( V_118 ) {
F_72 ( & V_113 -> V_68 , L_48 , V_118 ) ;
return V_118 ;
}
V_2 -> V_68 = & V_113 -> V_68 ;
V_2 -> V_194 = V_194 ;
V_2 -> V_195 = V_195 ;
V_118 = F_99 ( V_2 ) ;
if ( V_118 )
goto V_212;
V_118 = F_122 ( & V_113 -> V_68 ) ;
if ( V_118 ) {
F_72 ( & V_113 -> V_68 , L_49 , V_118 ) ;
goto V_213;
}
V_118 = F_53 ( V_2 ) ;
if ( V_118 )
goto V_213;
F_3 ( V_2 , 0x00400000L | ( V_214 << 18 ) ,
V_89 ) ;
V_118 = F_56 ( V_2 , V_113 , V_114 , V_2 -> V_115 ) ;
if ( V_118 )
goto V_215;
V_118 = F_94 ( V_2 , V_114 ) ;
if ( V_118 ) {
F_72 ( & V_113 -> V_68 , L_50 ,
V_118 ) ;
goto V_216;
}
F_123 ( & V_113 -> V_68 , L_51 , V_121 -> V_173 ) ;
return 0 ;
V_216:
F_87 ( V_2 ) ;
V_215:
V_213:
F_106 ( V_2 ) ;
V_212:
F_124 ( V_2 -> V_115 ) ;
return V_118 ;
}
static int F_125 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_126 ( V_113 ) ;
F_92 ( V_113 ) ;
F_87 ( V_2 ) ;
F_106 ( V_2 ) ;
F_124 ( V_2 -> V_115 ) ;
return 0 ;
}
