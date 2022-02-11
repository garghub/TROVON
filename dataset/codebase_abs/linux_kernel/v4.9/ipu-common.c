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
return V_39 ;
default:
return V_40 ;
}
}
enum V_9 F_8 ( T_1 V_41 )
{
switch ( V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return V_39 ;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
return V_28 ;
default:
return V_40 ;
}
}
bool F_9 ( T_1 V_41 )
{
switch ( V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return true ;
}
return false ;
}
enum V_9 F_10 ( T_1 V_56 )
{
switch ( V_56 & 0xf000 ) {
case 0x1000 :
return V_28 ;
case 0x2000 :
return V_39 ;
default:
return V_40 ;
}
}
int F_11 ( T_1 V_57 , T_1 V_41 )
{
switch ( V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return ( 8 * V_57 ) >> 3 ;
case V_55 :
case V_46 :
case V_45 :
return ( 16 * V_57 ) >> 3 ;
case V_54 :
case V_53 :
return ( 24 * V_57 ) >> 3 ;
case V_52 :
case V_51 :
return ( 32 * V_57 ) >> 3 ;
default:
break;
}
return - V_58 ;
}
int F_12 ( enum V_59 * V_60 , int V_61 ,
bool V_62 , bool V_63 )
{
T_1 V_64 , V_65 , V_66 ;
switch ( V_61 ) {
case 0 :
V_65 = V_66 = V_64 = 0 ;
break;
case 90 :
V_65 = V_66 = 0 ;
V_64 = 1 ;
break;
case 180 :
V_65 = V_66 = 1 ;
V_64 = 0 ;
break;
case 270 :
V_65 = V_66 = V_64 = 1 ;
break;
default:
return - V_58 ;
}
V_66 ^= ( T_1 ) V_62 ;
V_65 ^= ( T_1 ) V_63 ;
* V_60 = (enum V_59 ) ( ( V_64 << 2 ) | ( V_66 << 1 ) | V_65 ) ;
return 0 ;
}
int F_13 ( int * V_61 , enum V_59 V_60 ,
bool V_62 , bool V_63 )
{
T_1 V_64 , V_65 , V_66 ;
V_64 = ( ( T_1 ) V_60 >> 2 ) & 0x1 ;
V_66 = ( ( T_1 ) V_60 >> 1 ) & 0x1 ;
V_65 = ( ( T_1 ) V_60 >> 0 ) & 0x1 ;
V_66 ^= ( T_1 ) V_62 ;
V_65 ^= ( T_1 ) V_63 ;
switch ( (enum V_59 ) ( ( V_64 << 2 ) | ( V_66 << 1 ) | V_65 ) ) {
case V_67 :
* V_61 = 0 ;
break;
case V_68 :
* V_61 = 90 ;
break;
case V_69 :
* V_61 = 180 ;
break;
case V_70 :
* V_61 = 270 ;
break;
default:
return - V_58 ;
}
return 0 ;
}
struct V_71 * F_14 ( struct V_1 * V_2 , unsigned V_72 )
{
struct V_71 * V_73 ;
F_15 ( V_2 -> V_74 , L_1 , V_75 , V_72 ) ;
if ( V_72 > 63 )
return F_16 ( - V_76 ) ;
F_17 ( & V_2 -> V_77 ) ;
V_73 = & V_2 -> V_73 [ V_72 ] ;
if ( V_73 -> V_78 ) {
V_73 = F_16 ( - V_79 ) ;
goto V_80;
}
V_73 -> V_78 = true ;
V_73 -> V_72 = V_72 ;
V_80:
F_18 ( & V_2 -> V_77 ) ;
return V_73 ;
}
void F_19 ( struct V_71 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
F_15 ( V_2 -> V_74 , L_1 , V_75 , V_73 -> V_72 ) ;
F_17 ( & V_2 -> V_77 ) ;
V_73 -> V_78 = false ;
F_18 ( & V_2 -> V_77 ) ;
}
static void F_20 ( struct V_71 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned int V_81 = V_73 -> V_72 ;
F_3 ( V_2 , F_21 ( V_81 ) , F_22 ( V_81 ) ) ;
}
void F_23 ( struct V_71 * V_73 ,
bool V_82 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned long V_83 ;
T_1 V_84 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_84 = F_1 ( V_2 , F_25 ( V_73 -> V_72 ) ) ;
if ( V_82 )
V_84 |= F_21 ( V_73 -> V_72 ) ;
else
V_84 &= ~ F_21 ( V_73 -> V_72 ) ;
F_3 ( V_2 , V_84 , F_25 ( V_73 -> V_72 ) ) ;
F_20 ( V_73 ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
}
int F_27 ( struct V_71 * V_73 , int V_86 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned long V_83 ;
T_1 V_87 , V_88 ;
int V_89 ;
switch ( V_86 ) {
case 0 :
case 1 :
V_87 = 0x00 ;
break;
case 2 :
V_87 = 0x01 ;
break;
case 4 :
V_87 = 0x02 ;
break;
case 8 :
V_87 = 0x03 ;
break;
default:
return - V_58 ;
}
for ( V_89 = 0 ; V_89 < F_28 ( V_90 ) ; V_89 ++ ) {
if ( V_73 -> V_72 == V_90 [ V_89 ] . V_91 )
break;
}
if ( V_89 >= F_28 ( V_90 ) )
return - V_58 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_88 = F_29 ( V_2 , V_90 [ V_89 ] . V_84 ) ;
V_88 &= ~ ( 0x03 << V_90 [ V_89 ] . V_92 ) ;
V_88 |= ( V_87 << V_90 [ V_89 ] . V_92 ) ;
F_30 ( V_2 , V_88 , V_90 [ V_89 ] . V_84 ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_93 )
{
unsigned long V_94 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_85 , V_94 ) ;
V_7 = F_1 ( V_2 , V_95 ) ;
if ( V_93 & V_96 )
V_7 |= V_97 ;
if ( V_93 & V_98 )
V_7 |= V_99 ;
F_3 ( V_2 , V_7 , V_95 ) ;
V_7 = F_1 ( V_2 , V_100 ) ;
V_7 |= V_93 ;
F_3 ( V_2 , V_7 , V_100 ) ;
F_26 ( & V_2 -> V_85 , V_94 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_93 )
{
unsigned long V_94 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_85 , V_94 ) ;
V_7 = F_1 ( V_2 , V_100 ) ;
V_7 &= ~ V_93 ;
F_3 ( V_2 , V_7 , V_100 ) ;
V_7 = F_1 ( V_2 , V_95 ) ;
if ( V_93 & V_96 )
V_7 &= ~ V_97 ;
if ( V_93 & V_98 )
V_7 &= ~ V_99 ;
F_3 ( V_2 , V_7 , V_95 ) ;
F_26 ( & V_2 -> V_85 , V_94 ) ;
return 0 ;
}
int F_33 ( struct V_71 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned int V_81 = V_73 -> V_72 ;
return ( F_1 ( V_2 , F_22 ( V_81 ) ) & F_21 ( V_81 ) ) ? 1 : 0 ;
}
bool F_34 ( struct V_71 * V_73 , T_1 V_101 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned long V_83 ;
T_1 V_84 = 0 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
switch ( V_101 ) {
case 0 :
V_84 = F_1 ( V_2 , F_35 ( V_73 -> V_72 ) ) ;
break;
case 1 :
V_84 = F_1 ( V_2 , F_36 ( V_73 -> V_72 ) ) ;
break;
case 2 :
V_84 = F_1 ( V_2 , F_37 ( V_73 -> V_72 ) ) ;
break;
}
F_26 ( & V_2 -> V_85 , V_83 ) ;
return ( ( V_84 & F_21 ( V_73 -> V_72 ) ) != 0 ) ;
}
void F_38 ( struct V_71 * V_73 , T_1 V_101 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned int V_81 = V_73 -> V_72 ;
unsigned long V_83 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
if ( V_101 == 0 )
F_3 ( V_2 , F_21 ( V_81 ) , F_35 ( V_81 ) ) ;
else
F_3 ( V_2 , F_21 ( V_81 ) , F_36 ( V_81 ) ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
}
void F_39 ( struct V_71 * V_73 , T_1 V_101 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned int V_81 = V_73 -> V_72 ;
unsigned long V_83 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
F_3 ( V_2 , 0xF0300000 , V_102 ) ;
switch ( V_101 ) {
case 0 :
F_3 ( V_2 , F_21 ( V_81 ) , F_35 ( V_81 ) ) ;
break;
case 1 :
F_3 ( V_2 , F_21 ( V_81 ) , F_36 ( V_81 ) ) ;
break;
case 2 :
F_3 ( V_2 , F_21 ( V_81 ) , F_37 ( V_81 ) ) ;
break;
default:
break;
}
F_3 ( V_2 , 0x0 , V_102 ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
}
int F_40 ( struct V_71 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
T_1 V_7 ;
unsigned long V_83 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_7 = F_29 ( V_2 , F_41 ( V_73 -> V_72 ) ) ;
V_7 |= F_21 ( V_73 -> V_72 ) ;
F_30 ( V_2 , V_7 , F_41 ( V_73 -> V_72 ) ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
return 0 ;
}
bool F_42 ( struct V_1 * V_2 , unsigned int V_81 )
{
return ( F_29 ( V_2 , F_43 ( V_81 ) ) & F_21 ( V_81 ) ) ;
}
int F_44 ( struct V_71 * V_73 , int V_103 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned long V_104 ;
V_104 = V_105 + F_45 ( V_103 ) ;
while ( F_29 ( V_2 , F_43 ( V_73 -> V_72 ) ) &
F_21 ( V_73 -> V_72 ) ) {
if ( F_46 ( V_105 , V_104 ) )
return - V_106 ;
F_47 () ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 , int V_107 , int V_103 )
{
unsigned long V_104 ;
V_104 = V_105 + F_45 ( V_103 ) ;
F_3 ( V_2 , F_49 ( V_107 % 32 ) , F_50 ( V_107 / 32 ) ) ;
while ( ! ( F_1 ( V_2 , F_50 ( V_107 / 32 ) & F_49 ( V_107 % 32 ) ) ) ) {
if ( F_46 ( V_105 , V_104 ) )
return - V_106 ;
F_47 () ;
}
return 0 ;
}
int F_51 ( struct V_71 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
T_1 V_7 ;
unsigned long V_83 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_7 = F_29 ( V_2 , F_41 ( V_73 -> V_72 ) ) ;
V_7 &= ~ F_21 ( V_73 -> V_72 ) ;
F_30 ( V_2 , V_7 , F_41 ( V_73 -> V_72 ) ) ;
F_20 ( V_73 ) ;
F_3 ( V_2 , 0xf0000000 , V_102 ) ;
if ( F_1 ( V_2 , F_35 ( V_73 -> V_72 ) ) &
F_21 ( V_73 -> V_72 ) ) {
F_3 ( V_2 , F_21 ( V_73 -> V_72 ) ,
F_35 ( V_73 -> V_72 ) ) ;
}
if ( F_1 ( V_2 , F_36 ( V_73 -> V_72 ) ) &
F_21 ( V_73 -> V_72 ) ) {
F_3 ( V_2 , F_21 ( V_73 -> V_72 ) ,
F_36 ( V_73 -> V_72 ) ) ;
}
F_3 ( V_2 , 0x0 , V_102 ) ;
V_7 = F_1 ( V_2 , F_25 ( V_73 -> V_72 ) ) ;
V_7 &= ~ F_21 ( V_73 -> V_72 ) ;
F_3 ( V_2 , V_7 , F_25 ( V_73 -> V_72 ) ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
return 0 ;
}
void F_52 ( struct V_71 * V_73 , bool V_108 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
unsigned long V_83 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_7 = F_29 ( V_2 , F_53 ( V_73 -> V_72 ) ) ;
if ( V_108 )
V_7 |= 1 << ( V_73 -> V_72 % 32 ) ;
else
V_7 &= ~ ( 1 << ( V_73 -> V_72 % 32 ) ) ;
F_30 ( V_2 , V_7 , F_53 ( V_73 -> V_72 ) ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
unsigned long V_104 ;
F_3 ( V_2 , 0x807FFFFF , V_109 ) ;
V_104 = V_105 + F_45 ( 1000 ) ;
while ( F_1 ( V_2 , V_109 ) & 0x80000000 ) {
if ( F_46 ( V_105 , V_104 ) )
return - V_110 ;
F_47 () ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 , int V_111 , bool V_112 )
{
unsigned long V_83 ;
T_1 V_7 , V_93 ;
V_93 = ( V_111 == 1 ) ? V_113 :
V_114 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_7 = F_1 ( V_2 , V_100 ) ;
if ( V_112 )
V_7 |= V_93 ;
else
V_7 &= ~ V_93 ;
F_3 ( V_2 , V_7 , V_100 ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_111 , bool V_115 )
{
unsigned long V_83 ;
T_1 V_7 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
V_7 = F_1 ( V_2 , V_100 ) ;
if ( V_115 ) {
V_7 |= V_116 ;
} else {
V_7 &= ~ V_116 ;
if ( V_111 == 1 )
V_7 |= V_117 ;
else
V_7 &= ~ V_117 ;
}
F_3 ( V_2 , V_7 , V_100 ) ;
F_26 ( & V_2 -> V_85 , V_83 ) ;
}
static const struct V_118 * F_57 ( int V_119 , int V_120 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < F_28 ( V_118 ) ; V_89 ++ ) {
if ( V_119 == V_118 [ V_89 ] . V_119 . V_81 &&
V_120 == V_118 [ V_89 ] . V_120 . V_81 )
return & V_118 [ V_89 ] ;
}
return NULL ;
}
int F_58 ( struct V_1 * V_2 , int V_121 , int V_122 )
{
const struct V_118 * V_123 ;
T_1 V_124 , V_125 ;
unsigned long V_83 ;
V_123 = F_57 ( V_121 , V_122 ) ;
if ( ! V_123 )
return - V_58 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
if ( V_123 -> V_119 . V_93 ) {
V_124 = F_1 ( V_2 , V_123 -> V_119 . V_84 ) ;
V_124 &= ~ V_123 -> V_119 . V_93 ;
V_124 |= V_123 -> V_119 . V_7 ;
F_3 ( V_2 , V_124 , V_123 -> V_119 . V_84 ) ;
}
if ( V_123 -> V_120 . V_93 ) {
V_125 = F_1 ( V_2 , V_123 -> V_120 . V_84 ) ;
V_125 &= ~ V_123 -> V_120 . V_93 ;
V_125 |= V_123 -> V_120 . V_7 ;
F_3 ( V_2 , V_125 , V_123 -> V_120 . V_84 ) ;
}
F_26 ( & V_2 -> V_85 , V_83 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , int V_121 , int V_122 )
{
const struct V_118 * V_123 ;
T_1 V_124 , V_125 ;
unsigned long V_83 ;
V_123 = F_57 ( V_121 , V_122 ) ;
if ( ! V_123 )
return - V_58 ;
F_24 ( & V_2 -> V_85 , V_83 ) ;
if ( V_123 -> V_119 . V_93 ) {
V_124 = F_1 ( V_2 , V_123 -> V_119 . V_84 ) ;
V_124 &= ~ V_123 -> V_119 . V_93 ;
F_3 ( V_2 , V_124 , V_123 -> V_119 . V_84 ) ;
}
if ( V_123 -> V_120 . V_93 ) {
V_125 = F_1 ( V_2 , V_123 -> V_120 . V_84 ) ;
V_125 &= ~ V_123 -> V_120 . V_93 ;
F_3 ( V_2 , V_125 , V_123 -> V_120 . V_84 ) ;
}
F_26 ( & V_2 -> V_85 , V_83 ) ;
return 0 ;
}
int F_60 ( struct V_71 * V_119 , struct V_71 * V_120 )
{
return F_58 ( V_119 -> V_2 , V_119 -> V_72 , V_120 -> V_72 ) ;
}
int F_61 ( struct V_71 * V_119 , struct V_71 * V_120 )
{
return F_59 ( V_119 -> V_2 , V_119 -> V_72 , V_120 -> V_72 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_126 * V_127 , unsigned long V_128 ,
struct V_129 * V_130 )
{
char * V_131 ;
int V_132 ;
struct V_133 * V_74 = & V_127 -> V_74 ;
const struct V_134 * V_135 = V_2 -> V_135 ;
V_132 = F_63 ( V_2 , V_74 , V_128 + V_135 -> V_136 ) ;
if ( V_132 ) {
V_131 = L_2 ;
goto V_137;
}
V_132 = F_64 ( V_2 , V_74 , 0 , V_128 + V_135 -> V_138 ,
V_139 , V_130 ) ;
if ( V_132 ) {
V_131 = L_3 ;
goto V_140;
}
V_132 = F_64 ( V_2 , V_74 , 1 , V_128 + V_135 -> V_141 ,
V_142 , V_130 ) ;
if ( V_132 ) {
V_131 = L_4 ;
goto V_143;
}
V_132 = F_65 ( V_2 , V_74 ,
V_128 + V_135 -> V_144 ,
V_128 + V_135 -> V_145 ) ;
if ( V_132 ) {
V_131 = L_5 ;
goto V_146;
}
V_132 = F_66 ( V_2 , V_74 , V_128 + V_135 -> V_147 ,
V_148 | V_149 |
V_116 ) ;
if ( V_132 ) {
V_131 = L_6 ;
goto V_150;
}
V_132 = F_67 ( V_2 , V_74 ) ;
if ( V_132 ) {
V_131 = L_7 ;
goto V_151;
}
V_132 = F_68 ( V_2 , V_74 , 0 , V_128 + V_135 -> V_152 ,
V_96 , V_130 ) ;
if ( V_132 ) {
V_131 = L_8 ;
goto V_153;
}
V_132 = F_68 ( V_2 , V_74 , 1 , V_128 + V_135 -> V_154 ,
V_98 , V_130 ) ;
if ( V_132 ) {
V_131 = L_9 ;
goto V_155;
}
V_132 = F_69 ( V_2 , V_74 , V_128 + V_135 -> V_156 +
V_157 , V_128 + V_135 -> V_158 ) ;
if ( V_132 ) {
V_131 = L_10 ;
goto V_159;
}
V_132 = F_70 ( V_2 , V_74 , V_128 +
V_135 -> V_156 + V_160 , V_130 ) ;
if ( V_132 ) {
V_131 = L_11 ;
goto V_161;
}
V_132 = F_71 ( V_2 , V_74 , V_128 + V_135 -> V_162 ) ;
if ( V_132 ) {
V_131 = L_12 ;
goto V_163;
}
V_132 = F_72 ( V_2 , V_74 , V_128 +
V_135 -> V_156 + V_164 ) ;
if ( V_132 ) {
V_131 = L_13 ;
goto V_165;
}
return 0 ;
V_165:
F_73 ( V_2 ) ;
V_163:
F_74 ( V_2 ) ;
V_161:
F_75 ( V_2 ) ;
V_159:
F_76 ( V_2 , 1 ) ;
V_155:
F_76 ( V_2 , 0 ) ;
V_153:
F_77 ( V_2 ) ;
V_151:
F_78 ( V_2 ) ;
V_150:
F_79 ( V_2 ) ;
V_146:
F_80 ( V_2 , 1 ) ;
V_143:
F_80 ( V_2 , 0 ) ;
V_140:
F_81 ( V_2 ) ;
V_137:
F_82 ( & V_127 -> V_74 , L_14 , V_131 , V_132 ) ;
return V_132 ;
}
static void F_83 ( struct V_1 * V_2 , const int * V_166 , int V_167 )
{
unsigned long V_168 ;
int V_89 , V_169 , V_107 ;
for ( V_89 = 0 ; V_89 < V_167 ; V_89 ++ ) {
V_168 = F_1 ( V_2 , F_50 ( V_166 [ V_89 ] ) ) ;
V_168 &= F_1 ( V_2 , F_84 ( V_166 [ V_89 ] ) ) ;
F_85 (bit, &status, 32 ) {
V_107 = F_86 ( V_2 -> V_170 ,
V_166 [ V_89 ] * 32 + V_169 ) ;
if ( V_107 )
F_87 ( V_107 ) ;
}
}
}
static void F_88 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = F_89 ( V_172 ) ;
struct V_173 * V_174 = F_90 ( V_172 ) ;
const int V_175 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
F_91 ( V_174 , V_172 ) ;
F_83 ( V_2 , V_175 , F_28 ( V_175 ) ) ;
F_92 ( V_174 , V_172 ) ;
}
static void F_93 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = F_89 ( V_172 ) ;
struct V_173 * V_174 = F_90 ( V_172 ) ;
const int V_175 [] = { 4 , 5 , 8 , 9 } ;
F_91 ( V_174 , V_172 ) ;
F_83 ( V_2 , V_175 , F_28 ( V_175 ) ) ;
F_92 ( V_174 , V_172 ) ;
}
int F_94 ( struct V_1 * V_2 , int V_107 )
{
int V_176 ;
V_176 = F_86 ( V_2 -> V_170 , V_107 ) ;
if ( ! V_176 )
V_176 = F_95 ( V_2 -> V_170 , V_107 ) ;
return V_176 ;
}
int F_96 ( struct V_1 * V_2 , struct V_71 * V_73 ,
enum V_177 V_178 )
{
return F_94 ( V_2 , V_178 + V_73 -> V_72 ) ;
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
static int F_99 ( struct V_133 * V_74 , void * V_179 )
{
struct V_126 * V_127 = F_100 ( V_74 ) ;
F_101 ( V_127 ) ;
return 0 ;
}
static void F_102 ( struct V_126 * V_127 )
{
F_103 ( & V_127 -> V_74 , NULL , F_99 ) ;
}
static int F_104 ( struct V_1 * V_2 , unsigned long V_128 )
{
struct V_133 * V_74 = V_2 -> V_74 ;
unsigned V_89 ;
int V_6 , V_132 ;
F_17 ( & V_180 ) ;
V_6 = V_181 ;
V_181 += F_28 ( V_182 ) ;
F_18 ( & V_180 ) ;
for ( V_89 = 0 ; V_89 < F_28 ( V_182 ) ; V_89 ++ ) {
struct V_183 * V_84 = & V_182 [ V_89 ] ;
struct V_126 * V_127 ;
struct V_184 * V_185 ;
V_185 = F_105 ( V_74 -> V_185 , V_89 ) ;
if ( ! V_185 ) {
F_106 ( V_74 ,
L_15 ,
V_89 , V_74 -> V_185 -> V_186 ,
( V_89 / 2 ) ? L_16 : L_17 , V_89 % 2 ) ;
continue;
}
V_127 = F_107 ( V_84 -> V_187 , V_6 ++ ) ;
if ( ! V_127 ) {
V_132 = - V_188 ;
goto V_189;
}
V_127 -> V_74 . V_190 = V_74 ;
V_84 -> V_191 . V_185 = V_185 ;
V_132 = F_108 ( V_127 , & V_84 -> V_191 ,
sizeof( V_84 -> V_191 ) ) ;
if ( ! V_132 )
V_132 = F_109 ( V_127 ) ;
if ( V_132 ) {
F_110 ( V_127 ) ;
goto V_189;
}
V_127 -> V_74 . V_185 = V_185 ;
}
return 0 ;
V_189:
F_102 ( F_100 ( V_74 ) ) ;
return V_132 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_192 * V_193 ;
struct V_194 * V_195 ;
unsigned long V_179 [ V_196 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_132 , V_89 ;
V_2 -> V_170 = F_112 ( V_2 -> V_74 -> V_185 , V_196 ,
& V_197 , V_2 ) ;
if ( ! V_2 -> V_170 ) {
F_82 ( V_2 -> V_74 , L_18 ) ;
return - V_76 ;
}
V_132 = F_113 ( V_2 -> V_170 , 32 , 1 , L_19 ,
V_198 , 0 , 0 , 0 ) ;
if ( V_132 < 0 ) {
F_82 ( V_2 -> V_74 , L_20 ) ;
F_114 ( V_2 -> V_170 ) ;
return V_132 ;
}
for ( V_89 = 0 ; V_89 < V_196 ; V_89 += 32 )
F_3 ( V_2 , 0 , F_84 ( V_89 / 32 ) ) ;
for ( V_89 = 0 ; V_89 < V_196 ; V_89 += 32 ) {
V_193 = F_115 ( V_2 -> V_170 , V_89 ) ;
V_193 -> V_199 = V_2 -> V_4 ;
V_193 -> V_179 = V_179 [ V_89 / 32 ] ;
V_195 = V_193 -> V_200 ;
V_195 -> V_174 . V_201 = V_202 ;
V_195 -> V_174 . V_203 = V_204 ;
V_195 -> V_174 . V_205 = V_206 ;
V_195 -> V_166 . V_207 = F_50 ( V_89 / 32 ) ;
V_195 -> V_166 . V_93 = F_84 ( V_89 / 32 ) ;
}
F_116 ( V_2 -> V_208 , F_88 , V_2 ) ;
F_116 ( V_2 -> V_209 , F_93 ,
V_2 ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_89 , V_107 ;
F_116 ( V_2 -> V_209 , NULL , NULL ) ;
F_116 ( V_2 -> V_208 , NULL , NULL ) ;
for ( V_89 = 0 ; V_89 < V_196 ; V_89 ++ ) {
V_107 = F_86 ( V_2 -> V_170 , V_89 ) ;
if ( V_107 )
F_118 ( V_107 ) ;
}
F_114 ( V_2 -> V_170 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
int V_89 ;
F_15 ( V_2 -> V_74 , L_21 ,
F_1 ( V_2 , V_100 ) ) ;
F_15 ( V_2 -> V_74 , L_22 ,
F_29 ( V_2 , V_210 ) ) ;
F_15 ( V_2 -> V_74 , L_23 ,
F_29 ( V_2 , F_41 ( 0 ) ) ) ;
F_15 ( V_2 -> V_74 , L_24 ,
F_29 ( V_2 , F_41 ( 32 ) ) ) ;
F_15 ( V_2 -> V_74 , L_25 ,
F_29 ( V_2 , F_120 ( 0 ) ) ) ;
F_15 ( V_2 -> V_74 , L_26 ,
F_29 ( V_2 , F_120 ( 32 ) ) ) ;
F_15 ( V_2 -> V_74 , L_27 ,
F_29 ( V_2 , F_121 ( 0 ) ) ) ;
F_15 ( V_2 -> V_74 , L_28 ,
F_29 ( V_2 , F_121 ( 32 ) ) ) ;
F_15 ( V_2 -> V_74 , L_29 ,
F_1 ( V_2 , F_25 ( 0 ) ) ) ;
F_15 ( V_2 -> V_74 , L_30 ,
F_1 ( V_2 , F_25 ( 32 ) ) ) ;
F_15 ( V_2 -> V_74 , L_31 ,
F_1 ( V_2 , V_211 ) ) ;
F_15 ( V_2 -> V_74 , L_32 ,
F_1 ( V_2 , V_212 ) ) ;
F_15 ( V_2 -> V_74 , L_33 ,
F_1 ( V_2 , V_213 ) ) ;
F_15 ( V_2 -> V_74 , L_34 ,
F_1 ( V_2 , V_214 ) ) ;
for ( V_89 = 0 ; V_89 < 15 ; V_89 ++ )
F_15 ( V_2 -> V_74 , L_35 , V_89 ,
F_1 ( V_2 , F_84 ( V_89 ) ) ) ;
}
static int F_122 ( struct V_126 * V_127 )
{
struct V_184 * V_215 = V_127 -> V_74 . V_185 ;
struct V_1 * V_2 ;
struct V_216 * V_217 ;
unsigned long V_128 ;
int V_89 , V_132 , V_208 , V_209 ;
const struct V_134 * V_135 ;
V_135 = F_123 ( & V_127 -> V_74 ) ;
if ( ! V_135 )
return - V_58 ;
V_208 = F_124 ( V_127 , 0 ) ;
V_209 = F_124 ( V_127 , 1 ) ;
V_217 = F_125 ( V_127 , V_218 , 0 ) ;
F_15 ( & V_127 -> V_74 , L_36 ,
V_208 , V_209 ) ;
if ( ! V_217 || V_208 < 0 || V_209 < 0 )
return - V_76 ;
V_128 = V_217 -> V_219 ;
V_2 = F_126 ( & V_127 -> V_74 , sizeof( * V_2 ) , V_220 ) ;
if ( ! V_2 )
return - V_76 ;
for ( V_89 = 0 ; V_89 < 64 ; V_89 ++ )
V_2 -> V_73 [ V_89 ] . V_2 = V_2 ;
V_2 -> V_135 = V_135 ;
V_2 -> V_221 = V_135 -> type ;
V_2 -> V_6 = F_127 ( V_215 , L_37 ) ;
F_128 ( & V_2 -> V_85 ) ;
F_129 ( & V_2 -> V_77 ) ;
F_15 ( & V_127 -> V_74 , L_38 ,
V_128 + V_135 -> V_156 ) ;
F_15 ( & V_127 -> V_74 , L_39 ,
V_128 + V_135 -> V_156 + V_222 ) ;
F_15 ( & V_127 -> V_74 , L_40 ,
V_128 + V_135 -> V_136 ) ;
F_15 ( & V_127 -> V_74 , L_41 ,
V_128 + V_135 -> V_138 ) ;
F_15 ( & V_127 -> V_74 , L_42 ,
V_128 + V_135 -> V_141 ) ;
F_15 ( & V_127 -> V_74 , L_43 ,
V_128 + V_135 -> V_144 ) ;
F_15 ( & V_127 -> V_74 , L_44 ,
V_128 + V_135 -> V_152 ) ;
F_15 ( & V_127 -> V_74 , L_45 ,
V_128 + V_135 -> V_154 ) ;
F_15 ( & V_127 -> V_74 , L_46 ,
V_128 + V_135 -> V_162 ) ;
F_15 ( & V_127 -> V_74 , L_47 ,
V_128 + V_135 -> V_145 ) ;
F_15 ( & V_127 -> V_74 , L_48 ,
V_128 + V_135 -> V_156 + V_157 ) ;
F_15 ( & V_127 -> V_74 , L_49 ,
V_128 + V_135 -> V_156 + V_223 ) ;
F_15 ( & V_127 -> V_74 , L_50 ,
V_128 + V_135 -> V_156 + V_160 ) ;
F_15 ( & V_127 -> V_74 , L_51 ,
V_128 + V_135 -> V_147 ) ;
V_2 -> V_4 = F_130 ( & V_127 -> V_74 ,
V_128 + V_135 -> V_156 , V_224 ) ;
V_2 -> V_225 = F_130 ( & V_127 -> V_74 ,
V_128 + V_135 -> V_156 + V_222 ,
V_224 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_225 )
return - V_188 ;
V_2 -> V_129 = F_131 ( & V_127 -> V_74 , L_52 ) ;
if ( F_132 ( V_2 -> V_129 ) ) {
V_132 = F_133 ( V_2 -> V_129 ) ;
F_82 ( & V_127 -> V_74 , L_53 , V_132 ) ;
return V_132 ;
}
F_134 ( V_127 , V_2 ) ;
V_132 = F_135 ( V_2 -> V_129 ) ;
if ( V_132 ) {
F_82 ( & V_127 -> V_74 , L_54 , V_132 ) ;
return V_132 ;
}
V_2 -> V_74 = & V_127 -> V_74 ;
V_2 -> V_208 = V_208 ;
V_2 -> V_209 = V_209 ;
V_132 = F_136 ( & V_127 -> V_74 ) ;
if ( V_132 ) {
F_82 ( & V_127 -> V_74 , L_55 , V_132 ) ;
goto V_226;
}
V_132 = F_54 ( V_2 ) ;
if ( V_132 )
goto V_226;
V_132 = F_111 ( V_2 ) ;
if ( V_132 )
goto V_227;
F_3 ( V_2 , 0x00400000L | ( V_228 << 18 ) ,
V_95 ) ;
V_132 = F_62 ( V_2 , V_127 , V_128 , V_2 -> V_129 ) ;
if ( V_132 )
goto V_229;
V_132 = F_104 ( V_2 , V_128 ) ;
if ( V_132 ) {
F_82 ( & V_127 -> V_74 , L_56 ,
V_132 ) ;
goto V_230;
}
F_106 ( & V_127 -> V_74 , L_57 , V_135 -> V_187 ) ;
return 0 ;
V_230:
F_97 ( V_2 ) ;
V_229:
F_117 ( V_2 ) ;
V_227:
V_226:
F_137 ( V_2 -> V_129 ) ;
return V_132 ;
}
static int F_138 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_139 ( V_127 ) ;
F_102 ( V_127 ) ;
F_97 ( V_2 ) ;
F_117 ( V_2 ) ;
F_137 ( V_2 -> V_129 ) ;
return 0 ;
}
