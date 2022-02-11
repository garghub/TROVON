static void F_1 ( void T_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_3 & V_5 )
return;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ ) {
V_3 |= V_5 ;
F_3 ( V_3 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_3 & V_5 )
return;
F_4 ( 10 ) ;
}
F_5 ( 1 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
return F_7 ( V_7 -> V_8 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_8 ) ;
}
static T_3 F_10 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
return sprintf ( V_12 , L_1 , V_16 -> V_19 ) ;
}
static T_3 F_13 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
return sprintf ( V_12 , L_1 , V_16 -> V_20 ) ;
}
static T_3 F_14 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
return sprintf ( V_12 , L_1 , V_16 -> V_21 ) ;
}
static T_3 F_15 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_3 V_23 ;
F_6 ( V_7 ) ;
V_23 = sprintf ( V_12 , L_1 , F_2 ( V_22 + V_24 ) ) ;
F_8 ( V_7 ) ;
return V_23 ;
}
static T_3 F_17 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_25 = V_1 + V_16 -> V_26 ;
T_2 V_27 , V_28 ;
unsigned long V_29 ;
T_4 V_30 ;
int V_2 ;
F_6 ( V_7 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( ! ( V_7 -> V_29 & V_33 ) || V_27 & V_34 ||
! ( V_16 -> V_35 & V_36 ) ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_37 ;
}
if ( ! ( V_27 & V_38 ) ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_39 ;
}
if ( ! ( V_27 & V_40 ) )
V_25 += V_16 -> V_41 ;
V_30 = V_16 -> V_41 ;
if ( V_30 > V_42 ) {
if ( F_20 () )
F_21 ( V_7 ,
L_2
L_3 ,
V_16 -> V_41 , V_42 ) ;
V_30 = V_42 ;
}
for ( V_2 = 0 ; V_2 < V_30 ; V_2 += 4 ) {
V_28 = F_2 ( V_25 + V_2 ) ;
V_12 [ V_2 ] = V_28 & 0xff ;
V_12 [ V_2 + 1 ] = ( V_28 >> 8 ) & 0xff ;
V_12 [ V_2 + 2 ] = ( V_28 >> 16 ) & 0xff ;
V_12 [ V_2 + 3 ] = ( V_28 >> 24 ) & 0xff ;
}
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return V_2 ;
}
static T_3 F_22 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 , T_4 V_43 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_25 = V_1 + V_16 -> V_26 ;
const unsigned char * V_44 = V_12 ;
T_2 V_27 , V_28 ;
unsigned long V_29 ;
int V_2 ;
if ( ! ( V_7 -> V_29 & V_33 ) ||
! ( V_16 -> V_35 & V_36 ) ||
V_43 % 4 || V_43 > V_16 -> V_41 )
return - V_37 ;
F_6 ( V_7 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( V_27 & V_45 ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_46 ;
}
for ( V_2 = 0 ; V_2 < V_43 ; V_2 += 4 ) {
V_28 = V_44 [ V_2 ] | V_44 [ V_2 + 1 ] << 8 |
V_44 [ V_2 + 2 ] << 16 | V_44 [ V_2 + 3 ] << 24 ;
F_3 ( V_28 , V_25 + V_2 ) ;
}
F_3 ( V_27 | V_45 , V_1 + V_32 ) ;
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return V_43 ;
}
static T_3 F_23 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_27 ;
F_6 ( V_7 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
F_8 ( V_7 ) ;
return sprintf ( V_12 , L_4 ,
V_27 & V_47 ? L_5 : L_6 ,
V_27 & V_48 ? L_7 : L_6 ,
V_27 & V_49 ? L_8 : L_6 ,
V_27 & V_50 ? L_9 : L_6 ) ;
}
void F_24 ( struct V_9 * V_8 , struct V_15 * V_16 )
{
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_19 , V_20 , V_51 , V_52 ;
int V_2 ;
F_1 ( V_1 ) ;
V_16 -> V_53 = V_19 = F_2 ( V_1 + V_54 ) ;
V_16 -> V_55 = V_52 = F_2 ( V_1 + V_56 ) ;
V_51 = F_2 ( V_1 + V_57 ) ;
if ( ( V_51 >> 16 ) > 1 ||
( ( V_51 >> 16 ) == 1 && ( V_51 & 0xFFFF ) >= 0x200 ) )
V_16 -> V_58 = V_20 = F_2 ( V_1 + V_59 ) ;
else
V_16 -> V_58 = V_20 = 0 ;
if ( ( V_19 & V_60 ) && ( V_16 -> V_29 & V_61 ) ) {
F_25 ( V_8 , L_10 ) ;
V_19 &= ~ V_60 ;
}
if ( ( V_19 & V_62 ) && ( V_16 -> V_29 & V_63 ) ) {
F_25 ( V_8 , L_11 ) ;
V_19 &= ~ V_62 ;
}
if ( ! ( V_19 & V_62 ) && ( V_16 -> V_29 & V_64 ) ) {
F_25 ( V_8 , L_12 ) ;
V_19 |= V_62 ;
}
if ( ( V_19 & V_65 ) && ( V_16 -> V_29 & V_66 ) ) {
F_25 ( V_8 , L_13 ) ;
V_19 &= ~ V_65 ;
}
if ( ( V_19 & V_67 ) && ( V_16 -> V_29 & V_68 ) ) {
F_25 ( V_8 ,
L_14 ) ;
V_19 &= ~ V_67 ;
}
if ( ( V_20 & V_69 ) && ( V_16 -> V_29 & V_70 ) ) {
F_25 ( V_8 ,
L_15 ) ;
V_20 &= ~ V_69 ;
V_20 &= ~ V_71 ;
}
if ( ! ( V_19 & V_72 ) && ( V_16 -> V_29 & V_73 ) ) {
F_25 ( V_8 , L_16 ) ;
V_19 |= V_72 ;
}
if ( ( V_19 & V_72 ) && ( V_16 -> V_29 & V_74 ) ) {
F_25 ( V_8 , L_17 ) ;
V_19 &= ~ V_72 ;
}
if ( V_16 -> V_75 && V_52 != V_16 -> V_75 ) {
F_25 ( V_8 , L_18 ,
V_52 , V_16 -> V_75 ) ;
V_52 = V_16 -> V_75 ;
V_16 -> V_55 = V_52 ;
}
if ( V_16 -> V_76 ) {
F_26 ( V_8 , L_19 ,
V_52 ,
V_52 & V_16 -> V_76 ) ;
V_52 &= V_16 -> V_76 ;
}
if ( V_52 ) {
int V_77 = 0 ;
for ( V_2 = 0 ; V_2 < V_78 ; V_2 ++ )
if ( V_52 & ( 1 << V_2 ) )
V_77 ++ ;
if ( V_77 > F_27 ( V_19 ) ) {
F_26 ( V_8 ,
L_20 ,
V_52 , F_27 ( V_19 ) ) ;
V_52 = 0 ;
}
}
if ( ! V_52 && V_51 < 0x10300 ) {
V_52 = ( 1 << F_27 ( V_19 ) ) - 1 ;
F_26 ( V_8 , L_21 , V_52 ) ;
V_16 -> V_55 = V_52 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_21 = F_2 ( V_1 + V_57 ) ;
V_16 -> V_52 = V_52 ;
if ( ! V_16 -> V_79 )
V_16 -> V_79 = V_80 ;
if ( ! V_16 -> V_81 )
V_16 -> V_81 = V_82 ;
}
static void F_28 ( struct V_83 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_53 , V_1 + V_54 ) ;
if ( V_16 -> V_58 )
F_3 ( V_16 -> V_58 , V_1 + V_59 ) ;
F_3 ( V_16 -> V_55 , V_1 + V_56 ) ;
( void ) F_2 ( V_1 + V_56 ) ;
}
static unsigned F_29 ( struct V_6 * V_7 , unsigned int V_84 )
{
static const int V_85 [] = {
[ V_86 ] = V_87 ,
[ V_88 ] = V_89 ,
[ V_90 ] = V_91 ,
[ V_92 ] = V_93 ,
[ V_94 ] = V_95 ,
} ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
if ( V_84 < F_30 ( V_85 ) &&
( V_84 != V_94 || ( V_16 -> V_19 & V_67 ) ) )
return V_85 [ V_84 ] ;
return 0 ;
}
static int F_31 ( struct V_96 * V_97 , unsigned int V_84 , T_2 * V_98 )
{
void T_1 * V_22 = F_16 ( V_97 -> V_7 ) ;
int V_85 = F_29 ( V_97 -> V_7 , V_84 ) ;
if ( V_85 ) {
* V_98 = F_2 ( V_22 + V_85 ) ;
return 0 ;
}
return - V_37 ;
}
static int F_32 ( struct V_96 * V_97 , unsigned int V_84 , T_2 V_98 )
{
void T_1 * V_22 = F_16 ( V_97 -> V_7 ) ;
int V_85 = F_29 ( V_97 -> V_7 , V_84 ) ;
if ( V_85 ) {
F_3 ( V_98 , V_22 + V_85 ) ;
return 0 ;
}
return - V_37 ;
}
void V_80 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 |= V_99 ;
F_3 ( V_3 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
}
int F_33 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
T_2 V_3 ;
if ( ( V_16 -> V_29 & V_100 ) &&
( V_7 -> V_97 . V_101 > V_102 ) &&
F_34 ( & V_7 -> V_97 , V_102 , V_103 ) ) {
F_35 ( V_7 -> V_17 -> V_8 , L_22 ) ;
return - V_104 ;
}
V_3 = F_2 ( V_22 + V_24 ) ;
if ( ( V_3 & ( V_99 | V_105 ) ) == 0 )
return 0 ;
V_3 &= ~ V_99 ;
F_3 ( V_3 , V_22 + V_24 ) ;
V_3 = F_36 ( V_7 , V_22 + V_24 ,
V_105 , V_105 , 1 , 500 ) ;
if ( V_3 & V_105 )
return - V_104 ;
return 0 ;
}
void F_37 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_107 -> V_108 >> 16 ) >> 16 ,
V_22 + V_109 ) ;
F_3 ( V_107 -> V_108 & 0xffffffff , V_22 + V_110 ) ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_107 -> V_111 >> 16 ) >> 16 ,
V_22 + V_112 ) ;
F_3 ( V_107 -> V_111 & 0xffffffff , V_22 + V_113 ) ;
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 |= V_114 ;
F_3 ( V_3 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 &= ~ V_114 ;
F_3 ( V_3 , V_22 + V_24 ) ;
V_3 = F_36 ( V_7 , V_22 + V_24 , V_115 ,
V_115 , 10 , 1000 ) ;
if ( V_3 & V_115 )
return - V_46 ;
return 0 ;
}
static void F_39 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_116 ;
V_116 = F_2 ( V_22 + V_24 ) & ~ V_117 ;
if ( V_16 -> V_19 & V_118 ) {
V_116 |= V_119 ;
F_3 ( V_116 , V_22 + V_24 ) ;
}
F_3 ( V_116 | V_120 , V_22 + V_24 ) ;
}
static int F_34 ( struct V_96 * V_97 , enum V_121 V_122 ,
unsigned int V_123 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
if ( V_122 != V_102 ) {
V_123 &= ~ V_103 ;
V_107 -> V_124 &= ~ V_125 ;
F_3 ( V_107 -> V_124 , V_22 + V_126 ) ;
F_40 ( V_97 , V_122 , false ) ;
}
if ( V_16 -> V_19 & V_127 ) {
T_2 V_116 = F_2 ( V_22 + V_24 ) ;
if ( V_122 == V_102 || ! ( V_123 & V_128 ) ) {
if ( ! ( V_123 & V_103 ) )
V_116 &= ~ ( V_129 | V_130 ) ;
V_116 |= V_120 ;
F_3 ( V_116 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
F_41 ( V_7 , 10 ) ;
if ( V_123 & V_103 )
return 0 ;
} else {
V_116 |= V_130 ;
if ( V_122 == V_131 )
V_116 |= V_129 ;
F_3 ( V_116 , V_22 + V_24 ) ;
}
}
if ( ( V_16 -> V_20 & V_69 ) &&
( V_16 -> V_20 & V_71 ) &&
( V_97 -> V_9 -> V_29 & V_132 ) ) {
if ( V_122 == V_131 )
F_42 ( V_7 , true ) ;
else
F_42 ( V_7 , false ) ;
}
if ( V_122 == V_102 ) {
F_40 ( V_97 , V_122 , false ) ;
V_107 -> V_124 |= V_125 ;
F_3 ( V_107 -> V_124 , V_22 + V_126 ) ;
}
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_116 , V_133 ;
if ( ! ( V_16 -> V_19 & V_118 ) )
return;
V_133 = F_2 ( V_22 + V_89 ) ;
V_133 &= ~ 0xf ;
F_3 ( V_133 , V_22 + V_89 ) ;
V_116 = F_2 ( V_22 + V_24 ) & ~ V_117 ;
V_116 &= ~ V_119 ;
F_3 ( V_116 , V_22 + V_24 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_96 * V_97 ;
struct V_134 * V_135 ;
T_3 V_136 ;
int V_2 ;
F_37 ( V_7 ) ;
if ( ! ( V_16 -> V_29 & V_137 ) )
V_16 -> V_79 ( V_7 ) ;
if ( V_7 -> V_29 & V_33 ) {
F_45 (link, ap, EDGE) {
V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
for ( V_2 = 0 ; V_2 < V_140 ; V_2 ++ ) {
V_136 = V_7 -> V_141 -> V_142 ( V_7 ,
V_135 -> V_143 ,
4 ) ;
if ( V_136 == - V_46 )
F_4 ( 1 ) ;
else
break;
}
}
}
if ( V_7 -> V_29 & V_144 )
F_45 (link, ap, EDGE)
F_46 ( V_97 ) ;
}
static int F_47 ( struct V_6 * V_7 , const char * * V_145 )
{
int V_136 ;
V_136 = F_33 ( V_7 ) ;
if ( V_136 ) {
* V_145 = L_23 ;
return V_136 ;
}
V_136 = F_38 ( V_7 ) ;
if ( V_136 ) {
* V_145 = L_24 ;
return V_136 ;
}
return 0 ;
}
int F_48 ( struct V_83 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_146 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_147 ) == 0 ) {
F_3 ( V_3 | V_147 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_36 ( NULL , V_1 + V_4 , V_147 ,
V_147 , 10 , 1000 ) ;
if ( V_3 & V_147 ) {
F_35 ( V_17 -> V_8 , L_25 ,
V_3 ) ;
return - V_104 ;
}
F_1 ( V_1 ) ;
F_28 ( V_17 ) ;
} else
F_25 ( V_17 -> V_8 , L_26 ) ;
return 0 ;
}
static void F_49 ( struct V_96 * V_97 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_134 * V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
if ( ! ( V_97 -> V_29 & V_148 ) )
return;
V_135 -> V_149 ++ ;
if ( ! F_50 ( & V_135 -> V_150 ) )
F_51 ( & V_135 -> V_150 , V_151 + F_52 ( 10 ) ) ;
}
static void F_53 ( unsigned long V_152 )
{
struct V_96 * V_97 = (struct V_96 * ) V_152 ;
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_134 * V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
unsigned long V_153 = V_135 -> V_143 ;
T_2 V_154 ;
unsigned long V_29 ;
V_153 &= V_155 ;
V_153 |= V_7 -> V_156 | ( V_97 -> V_139 << 8 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
if ( V_135 -> V_157 != V_135 -> V_149 ) {
V_135 -> V_157 = V_135 -> V_149 ;
V_154 = V_153 & V_158 ;
if ( V_154 )
V_154 = 0 ;
else
V_154 = 1 ;
V_153 &= ~ V_159 ;
V_153 |= ( V_154 << 16 ) ;
F_51 ( & V_135 -> V_150 , V_151 + F_52 ( 100 ) ) ;
} else {
V_153 &= ~ V_159 ;
if ( V_135 -> V_160 == V_161 )
V_153 |= ( 1 << 16 ) ;
}
F_19 ( V_7 -> V_31 , V_29 ) ;
V_7 -> V_141 -> V_142 ( V_7 , V_153 , 4 ) ;
}
static void F_46 ( struct V_96 * V_97 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_134 * V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
V_135 -> V_157 = V_135 -> V_149 = 0 ;
F_54 ( & V_135 -> V_150 , F_53 , ( unsigned long ) V_97 ) ;
if ( V_135 -> V_160 )
V_97 -> V_29 |= V_148 ;
}
int F_55 ( struct V_83 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_27 ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( ( V_27 & V_45 ) || ( V_27 & V_162 ) )
return - V_37 ;
F_3 ( V_27 | V_162 , V_1 + V_32 ) ;
return 0 ;
}
static T_3 F_56 ( struct V_6 * V_7 , T_2 V_163 ,
T_3 V_43 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_27 ;
T_2 V_164 [] = { 0 , 0 } ;
unsigned long V_29 ;
int V_139 ;
struct V_134 * V_135 ;
V_139 = ( V_163 & V_165 ) >> 8 ;
if ( V_139 < V_166 )
V_135 = & V_107 -> V_138 [ V_139 ] ;
else
return - V_37 ;
F_6 ( V_7 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( V_27 & V_45 ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_46 ;
}
if ( V_16 -> V_35 & V_167 ) {
V_164 [ 0 ] |= ( 4 << 8 ) ;
V_164 [ 1 ] = ( ( V_163 & ~ V_168 ) | V_7 -> V_156 ) ;
F_3 ( V_164 [ 0 ] , V_1 + V_16 -> V_26 ) ;
F_3 ( V_164 [ 1 ] , V_1 + V_16 -> V_26 + 4 ) ;
F_3 ( V_27 | V_45 , V_1 + V_32 ) ;
}
V_135 -> V_143 = V_163 ;
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return V_43 ;
}
static T_3 F_57 ( struct V_6 * V_7 , char * V_12 )
{
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_96 * V_97 ;
struct V_134 * V_135 ;
int V_136 = 0 ;
F_45 (link, ap, EDGE) {
V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
V_136 += sprintf ( V_12 , L_27 , V_135 -> V_143 ) ;
}
return V_136 ;
}
static T_3 F_58 ( struct V_6 * V_7 , const char * V_12 ,
T_4 V_43 )
{
unsigned int V_163 ;
int V_139 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_134 * V_135 ;
if ( F_59 ( V_12 , 0 , & V_163 ) < 0 )
return - V_37 ;
V_139 = ( V_163 & V_165 ) >> 8 ;
if ( V_139 < V_166 )
V_135 = & V_107 -> V_138 [ V_139 ] ;
else
return - V_37 ;
if ( V_135 -> V_160 )
V_163 &= ~ V_159 ;
return V_7 -> V_141 -> V_142 ( V_7 , V_163 , V_43 ) ;
}
static T_3 F_60 ( struct V_169 * V_8 , enum V_170 V_98 )
{
struct V_96 * V_97 = V_8 -> V_97 ;
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_134 * V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
T_2 V_171 = V_135 -> V_143 ;
if ( V_98 == V_172 ) {
V_97 -> V_29 &= ~ ( V_148 ) ;
V_171 &= V_173 ;
V_171 |= ( V_7 -> V_156 | ( V_97 -> V_139 << 8 ) ) ;
V_7 -> V_141 -> V_142 ( V_7 , V_171 , 4 ) ;
} else {
V_97 -> V_29 |= V_148 ;
if ( V_98 == V_161 ) {
V_171 &= V_173 ;
V_171 |= ( V_7 -> V_156 | ( V_97 -> V_139 << 8 ) ) ;
V_171 |= V_158 ;
V_7 -> V_141 -> V_142 ( V_7 , V_171 , 4 ) ;
}
}
V_135 -> V_160 = V_98 ;
return 0 ;
}
static T_3 F_61 ( struct V_169 * V_8 , char * V_12 )
{
struct V_96 * V_97 = V_8 -> V_97 ;
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_134 * V_135 = & V_107 -> V_138 [ V_97 -> V_139 ] ;
return sprintf ( V_12 , L_28 , V_135 -> V_160 ) ;
}
static void F_62 ( struct V_9 * V_8 , struct V_6 * V_7 ,
int V_156 , void T_1 * V_1 ,
void T_1 * V_22 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
const char * V_145 = NULL ;
int V_136 ;
T_2 V_3 ;
V_136 = F_47 ( V_7 , & V_145 ) ;
if ( V_136 )
F_26 ( V_8 , L_29 , V_145 , V_136 ) ;
V_3 = F_2 ( V_22 + V_91 ) ;
F_63 ( L_30 , V_3 ) ;
F_3 ( V_3 , V_22 + V_91 ) ;
V_3 = F_2 ( V_22 + V_174 ) ;
F_63 ( L_31 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_174 ) ;
F_3 ( 1 << V_156 , V_1 + V_175 ) ;
V_3 = F_2 ( V_22 + V_24 ) ;
if ( ( V_3 & V_176 ) && ( V_16 -> V_19 & V_177 ) )
V_7 -> V_178 |= V_179 ;
}
void F_64 ( struct V_83 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_180 ; V_2 ++ ) {
struct V_6 * V_7 = V_17 -> V_181 [ V_2 ] ;
V_22 = F_16 ( V_7 ) ;
if ( F_65 ( V_7 ) )
continue;
F_62 ( V_17 -> V_8 , V_7 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_63 ( L_32 , V_3 ) ;
F_3 ( V_3 | V_182 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_63 ( L_32 , V_3 ) ;
}
static void F_66 ( struct V_169 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_97 -> V_7 -> V_17 -> V_18 ;
if ( V_16 -> V_29 & V_183 ) {
V_8 -> V_184 = 255 ;
F_67 ( V_8 ,
L_33 ) ;
}
}
unsigned int F_68 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_185 V_186 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_187 ) ;
V_186 . V_188 = ( V_3 >> 24 ) & 0xff ;
V_186 . V_189 = ( V_3 >> 16 ) & 0xff ;
V_186 . V_190 = ( V_3 >> 8 ) & 0xff ;
V_186 . V_191 = ( V_3 ) & 0xff ;
return F_69 ( & V_186 ) ;
}
void F_70 ( struct V_106 * V_107 , unsigned int V_192 ,
T_2 V_193 )
{
T_5 V_194 ;
V_194 = V_107 -> V_194 + V_192 * V_195 ;
V_107 -> V_196 [ V_192 ] . V_193 = F_71 ( V_193 ) ;
V_107 -> V_196 [ V_192 ] . V_197 = 0 ;
V_107 -> V_196 [ V_192 ] . V_198 = F_71 ( V_194 & 0xffffffff ) ;
V_107 -> V_196 [ V_192 ] . V_199 = F_71 ( ( V_194 >> 16 ) >> 16 ) ;
}
int F_72 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
T_6 V_197 = F_2 ( V_22 + V_200 ) & 0xFF ;
T_2 V_3 ;
int V_201 , V_136 ;
V_136 = F_33 ( V_7 ) ;
if ( V_136 )
goto V_202;
V_201 = V_197 & ( V_203 | V_204 ) ;
if ( ! V_201 && ! F_73 ( V_7 ) ) {
V_136 = 0 ;
goto V_202;
}
if ( ! ( V_16 -> V_19 & V_205 ) ) {
V_136 = - V_206 ;
goto V_202;
}
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 |= V_207 ;
F_3 ( V_3 , V_22 + V_24 ) ;
V_136 = 0 ;
V_3 = F_36 ( V_7 , V_22 + V_24 ,
V_207 , V_207 , 1 , 500 ) ;
if ( V_3 & V_207 )
V_136 = - V_104 ;
V_202:
V_16 -> V_79 ( V_7 ) ;
return V_136 ;
}
static int F_74 ( struct V_6 * V_7 , int V_139 ,
struct V_185 * V_186 , int V_208 , T_7 V_29 ,
unsigned long V_209 )
{
const T_2 V_210 = 5 ;
struct V_106 * V_107 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_6 * V_211 = V_107 -> V_212 ;
T_2 V_3 ;
F_75 ( V_186 , V_139 , V_208 , V_211 ) ;
F_70 ( V_107 , 0 , V_210 | V_29 | ( V_139 << 12 ) ) ;
if ( V_107 -> V_213 && V_107 -> V_214 != V_139 ) {
V_3 = F_2 ( V_22 + V_215 ) ;
V_3 &= ~ ( V_216 | V_217 ) ;
V_3 |= V_139 << V_218 ;
F_3 ( V_3 , V_22 + V_215 ) ;
V_107 -> V_214 = V_139 ;
}
F_3 ( 1 , V_22 + V_219 ) ;
if ( V_209 ) {
V_3 = F_36 ( V_7 , V_22 + V_219 ,
0x1 , 0x1 , 1 , V_209 ) ;
if ( V_3 & 0x1 ) {
F_72 ( V_7 ) ;
return - V_46 ;
}
} else
F_2 ( V_22 + V_219 ) ;
return 0 ;
}
int F_76 ( struct V_96 * V_97 , unsigned int * V_220 ,
int V_139 , unsigned long V_221 ,
int (* F_77)( struct V_96 * V_97 ) )
{
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
const char * V_222 = NULL ;
unsigned long V_223 , V_224 ;
struct V_185 V_186 ;
bool V_225 = false ;
int V_136 ;
F_78 ( L_34 ) ;
V_136 = F_72 ( V_7 ) ;
if ( V_136 && V_136 != - V_206 )
F_79 ( V_97 , L_35 , V_136 ) ;
if ( ! F_80 ( V_97 ) && V_107 -> V_213 ) {
F_81 ( V_7 ) ;
V_225 = true ;
}
F_82 ( V_97 -> V_9 , & V_186 ) ;
V_224 = 0 ;
V_223 = V_151 ;
if ( F_83 ( V_221 , V_223 ) )
V_224 = F_84 ( V_221 - V_223 ) ;
V_186 . V_226 |= V_227 ;
if ( F_74 ( V_7 , V_139 , & V_186 , 0 ,
V_228 | V_229 , V_224 ) ) {
V_136 = - V_104 ;
V_222 = L_36 ;
goto V_230;
}
F_41 ( V_7 , 1 ) ;
V_186 . V_226 &= ~ V_227 ;
F_74 ( V_7 , V_139 , & V_186 , 0 , 0 , 0 ) ;
V_136 = F_85 ( V_97 , V_221 , F_77 ) ;
if ( V_136 == - V_46 && V_16 -> V_29 & V_231 ) {
F_86 ( V_97 , L_37 ) ;
* V_220 = V_232 ;
} else if ( V_136 ) {
V_222 = L_38 ;
goto V_230;
} else
* V_220 = F_68 ( V_7 ) ;
if ( V_225 )
F_87 ( V_7 ) ;
F_78 ( L_39 , * V_220 ) ;
return 0 ;
V_230:
F_88 ( V_97 , L_40 , V_222 ) ;
return V_136 ;
}
int F_89 ( struct V_96 * V_97 )
{
void T_1 * V_22 = F_16 ( V_97 -> V_7 ) ;
T_6 V_197 = F_2 ( V_22 + V_200 ) & 0xFF ;
return F_90 ( V_197 ) ;
}
static int F_91 ( struct V_96 * V_97 , unsigned int * V_220 ,
unsigned long V_221 )
{
int V_139 = F_92 ( V_97 ) ;
F_78 ( L_34 ) ;
return F_76 ( V_97 , V_220 , V_139 , V_221 , F_89 ) ;
}
static int F_93 ( struct V_96 * V_97 )
{
void T_1 * V_22 = F_16 ( V_97 -> V_7 ) ;
T_6 V_197 = F_2 ( V_22 + V_200 ) & 0xFF ;
T_2 V_233 = F_2 ( V_22 + V_174 ) ;
if ( V_233 & V_234 )
return - V_104 ;
return F_90 ( V_197 ) ;
}
static int F_94 ( struct V_96 * V_97 , unsigned int * V_220 ,
unsigned long V_221 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
int V_139 = F_92 ( V_97 ) ;
int V_136 ;
T_2 V_235 ;
F_78 ( L_34 ) ;
V_136 = F_76 ( V_97 , V_220 , V_139 , V_221 ,
F_93 ) ;
if ( V_136 == - V_104 ) {
V_235 = F_2 ( V_22 + V_174 ) ;
if ( V_235 & V_234 ) {
F_79 ( V_97 ,
L_41
L_42 ) ;
V_136 = F_76 ( V_97 , V_220 , 0 , V_221 ,
F_89 ) ;
}
}
return V_136 ;
}
static int F_95 ( struct V_96 * V_97 , unsigned int * V_220 ,
unsigned long V_221 )
{
const unsigned long * V_236 = F_96 ( & V_97 -> V_237 ) ;
struct V_6 * V_7 = V_97 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
T_6 * V_238 = V_107 -> V_239 + V_240 ;
struct V_185 V_186 ;
bool V_241 ;
int V_136 ;
F_78 ( L_34 ) ;
F_33 ( V_7 ) ;
F_82 ( V_97 -> V_9 , & V_186 ) ;
V_186 . V_242 = V_203 ;
F_75 ( & V_186 , 0 , 0 , V_238 ) ;
V_136 = F_97 ( V_97 , V_236 , V_221 , & V_241 ,
F_89 ) ;
V_16 -> V_79 ( V_7 ) ;
if ( V_241 )
* V_220 = F_68 ( V_7 ) ;
F_78 ( L_43 , V_136 , * V_220 ) ;
return V_136 ;
}
static void F_98 ( struct V_96 * V_97 , unsigned int * V_220 )
{
struct V_6 * V_7 = V_97 -> V_7 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_243 , V_3 ;
F_99 ( V_97 , V_220 ) ;
V_243 = V_3 = F_2 ( V_22 + V_24 ) ;
if ( * V_220 == V_244 )
V_243 |= V_245 ;
else
V_243 &= ~ V_245 ;
if ( V_243 != V_3 ) {
F_3 ( V_243 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
}
}
static unsigned int F_100 ( struct V_246 * V_247 , void * V_212 )
{
struct V_248 * V_249 ;
struct V_250 * V_250 = V_212 + V_251 ;
unsigned int V_252 ;
F_63 ( L_34 ) ;
F_101 (qc->sg, sg, qc->n_elem, si) {
T_5 V_253 = F_102 ( V_249 ) ;
T_2 V_254 = F_103 ( V_249 ) ;
V_250 [ V_252 ] . V_253 = F_71 ( V_253 & 0xffffffff ) ;
V_250 [ V_252 ] . V_255 = F_71 ( ( V_253 >> 16 ) >> 16 ) ;
V_250 [ V_252 ] . V_256 = F_71 ( V_254 - 1 ) ;
}
return V_252 ;
}
static int F_104 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = V_247 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
if ( ! F_73 ( V_7 ) || V_107 -> V_213 )
return F_105 ( V_247 ) ;
else
return F_106 ( V_247 ) ;
}
static void F_107 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = V_247 -> V_7 ;
struct V_106 * V_107 = V_7 -> V_18 ;
int V_257 = F_108 ( V_247 -> V_186 . V_258 ) ;
void * V_212 ;
T_2 V_193 ;
const T_2 V_210 = 5 ;
unsigned int V_259 ;
V_212 = V_107 -> V_212 + V_247 -> V_192 * V_195 ;
F_75 ( & V_247 -> V_186 , V_247 -> V_8 -> V_97 -> V_139 , 1 , V_212 ) ;
if ( V_257 ) {
memset ( V_212 + V_260 , 0 , 32 ) ;
memcpy ( V_212 + V_260 , V_247 -> V_261 , V_247 -> V_8 -> V_262 ) ;
}
V_259 = 0 ;
if ( V_247 -> V_29 & V_263 )
V_259 = F_100 ( V_247 , V_212 ) ;
V_193 = V_210 | V_259 << 16 | ( V_247 -> V_8 -> V_97 -> V_139 << 12 ) ;
if ( V_247 -> V_186 . V_29 & V_264 )
V_193 |= V_265 ;
if ( V_257 )
V_193 |= V_266 | V_267 ;
F_70 ( V_107 , V_247 -> V_192 , V_193 ) ;
}
static void F_109 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_268 = F_2 ( V_22 + V_215 ) ;
int V_269 = 3 ;
F_78 ( L_34 ) ;
F_110 ( ! V_107 -> V_213 ) ;
F_3 ( V_268 | V_217 , V_22 + V_215 ) ;
V_268 = F_2 ( V_22 + V_215 ) ;
while ( ( V_268 & V_217 ) && V_269 -- ) {
F_111 ( 1 ) ;
V_268 = F_2 ( V_22 + V_215 ) ;
}
if ( V_268 & V_217 )
F_35 ( V_7 -> V_17 -> V_8 , L_44 ) ;
}
static void F_112 ( struct V_6 * V_7 , T_2 V_270 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_271 * V_272 = & V_7 -> V_97 . V_273 ;
struct V_96 * V_97 = NULL ;
struct V_246 * V_274 ;
struct V_271 * V_275 ;
bool V_276 = false ;
T_2 V_277 ;
if ( V_107 -> V_213 ) {
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_268 = F_2 ( V_22 + V_215 ) ;
int V_139 = V_268 >> V_278 ;
if ( ( V_268 & V_279 ) && ( V_139 < V_7 -> V_280 ) ) {
V_97 = & V_7 -> V_281 [ V_139 ] ;
V_276 = true ;
}
} else
F_45 (link, ap, EDGE)
if ( F_113 ( V_97 ) )
break;
if ( ! V_97 )
V_97 = & V_7 -> V_97 ;
V_274 = F_114 ( V_7 , V_97 -> V_282 ) ;
V_275 = & V_97 -> V_273 ;
F_115 ( V_272 ) ;
F_116 ( V_272 , L_45 , V_270 ) ;
F_31 ( & V_7 -> V_97 , V_90 , & V_277 ) ;
F_32 ( & V_7 -> V_97 , V_90 , V_277 ) ;
V_272 -> V_277 |= V_277 ;
if ( V_16 -> V_29 & V_283 )
V_270 &= ~ V_284 ;
if ( V_270 & V_285 ) {
if ( V_274 )
V_274 -> V_286 |= V_287 ;
else
V_275 -> V_286 |= V_287 ;
if ( V_16 -> V_29 & V_288 )
V_272 -> V_277 &= ~ V_289 ;
}
if ( V_270 & V_290 ) {
T_2 * V_291 = V_107 -> V_239 + V_292 ;
V_275 -> V_286 |= V_293 ;
V_275 -> V_294 |= V_295 ;
F_116 ( V_275 ,
L_46 ,
V_291 [ 0 ] , V_291 [ 1 ] , V_291 [ 2 ] , V_291 [ 3 ] ) ;
}
if ( F_73 ( V_7 ) && ( V_270 & V_234 ) ) {
V_275 -> V_286 |= V_293 ;
V_275 -> V_294 |= V_295 ;
F_116 ( V_275 , L_47 ) ;
}
if ( V_270 & ( V_296 | V_297 ) ) {
V_272 -> V_286 |= V_298 ;
V_272 -> V_294 |= V_295 ;
F_116 ( V_272 , L_48 ) ;
}
if ( V_270 & V_284 ) {
if ( V_276 )
V_275 -> V_286 |= V_287 ;
else {
V_272 -> V_286 |= V_299 ;
V_272 -> V_294 |= V_295 ;
}
F_116 ( V_272 , L_49 ) ;
}
if ( V_270 & ( V_300 | V_125 ) ) {
F_117 ( V_272 ) ;
F_116 ( V_272 , L_50 ,
V_270 & V_300 ?
L_51 : L_52 ) ;
}
if ( V_270 & V_301 )
F_118 ( V_7 ) ;
else if ( V_276 ) {
F_119 ( V_97 ) ;
F_109 ( V_7 ) ;
} else
F_120 ( V_7 ) ;
}
static void F_121 ( struct V_6 * V_7 ,
void T_1 * V_22 , T_2 V_197 )
{
struct V_271 * V_302 = & V_7 -> V_97 . V_273 ;
struct V_106 * V_107 = V_7 -> V_18 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
int V_303 = ! ! ( V_7 -> V_178 & V_304 ) ;
T_2 V_305 = 0 ;
int V_136 ;
if ( F_122 ( V_303 ) )
V_197 &= ~ V_234 ;
if ( F_123 ( & V_7 -> V_97 ) ) {
V_197 &= ~ V_125 ;
F_32 ( & V_7 -> V_97 , V_90 , V_306 ) ;
}
if ( F_122 ( V_197 & V_307 ) ) {
F_112 ( V_7 , V_197 ) ;
return;
}
if ( V_197 & V_308 ) {
if ( V_16 -> V_19 & V_67 )
F_124 ( V_7 ) ;
else {
if ( V_107 -> V_213 )
F_125 ( 1 ) ;
else {
const T_8 * V_309 = V_107 -> V_239 + V_310 ;
T_2 V_311 = F_126 ( V_309 [ 0 ] ) ;
if ( V_311 & ( 1 << 15 ) )
F_124 ( V_7 ) ;
}
}
}
if ( V_107 -> V_213 ) {
if ( V_7 -> V_305 ) {
V_305 = F_2 ( V_22 + V_93 ) ;
V_305 |= F_2 ( V_22 + V_219 ) ;
}
} else {
if ( V_7 -> V_305 && V_107 -> V_312 -> V_313 )
V_305 = F_2 ( V_22 + V_93 ) ;
else
V_305 = F_2 ( V_22 + V_219 ) ;
}
V_136 = F_127 ( V_7 , V_305 ) ;
if ( F_122 ( V_136 < 0 && ! V_303 ) ) {
V_302 -> V_286 |= V_293 ;
V_302 -> V_294 |= V_295 ;
F_118 ( V_7 ) ;
}
}
static void F_128 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_197 ;
V_197 = F_2 ( V_22 + V_174 ) ;
F_3 ( V_197 , V_22 + V_174 ) ;
F_121 ( V_7 , V_22 , V_197 ) ;
}
static T_9 F_129 ( int V_314 , void * V_315 )
{
struct V_6 * V_7 = V_315 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_197 ;
F_63 ( L_34 ) ;
V_197 = F_2 ( V_22 + V_174 ) ;
F_3 ( V_197 , V_22 + V_174 ) ;
F_130 ( V_7 -> V_31 ) ;
F_121 ( V_7 , V_22 , V_197 ) ;
F_131 ( V_7 -> V_31 ) ;
F_63 ( L_53 ) ;
return V_316 ;
}
T_2 F_132 ( struct V_83 * V_17 , T_2 V_317 )
{
unsigned int V_2 , V_318 = 0 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_180 ; V_2 ++ ) {
struct V_6 * V_7 ;
if ( ! ( V_317 & ( 1 << V_2 ) ) )
continue;
V_7 = V_17 -> V_181 [ V_2 ] ;
if ( V_7 ) {
F_128 ( V_7 ) ;
F_63 ( L_54 , V_2 ) ;
} else {
F_63 ( L_55 , V_2 ) ;
if ( F_133 () )
F_26 ( V_17 -> V_8 ,
L_56 , V_2 ) ;
}
V_318 = 1 ;
}
return V_318 ;
}
static T_9 V_82 ( int V_314 , void * V_315 )
{
struct V_83 * V_17 = V_315 ;
struct V_15 * V_16 ;
unsigned int V_136 = 0 ;
void T_1 * V_1 ;
T_2 V_270 , V_317 ;
F_63 ( L_34 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_270 = F_2 ( V_1 + V_175 ) ;
if ( ! V_270 )
return V_319 ;
V_317 = V_270 & V_16 -> V_52 ;
F_130 ( & V_17 -> V_31 ) ;
V_136 = F_132 ( V_17 , V_317 ) ;
F_3 ( V_270 , V_1 + V_175 ) ;
F_131 ( & V_17 -> V_31 ) ;
F_63 ( L_53 ) ;
return F_134 ( V_136 ) ;
}
unsigned int F_135 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = V_247 -> V_7 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_106 * V_107 = V_7 -> V_18 ;
V_107 -> V_312 = V_247 -> V_8 -> V_97 ;
if ( F_136 ( V_247 -> V_186 . V_258 ) )
F_3 ( 1 << V_247 -> V_192 , V_22 + V_93 ) ;
if ( V_107 -> V_213 && V_107 -> V_214 != V_247 -> V_8 -> V_97 -> V_139 ) {
T_2 V_268 = F_2 ( V_22 + V_215 ) ;
V_268 &= ~ ( V_216 | V_217 ) ;
V_268 |= V_247 -> V_8 -> V_97 -> V_139 << V_218 ;
F_3 ( V_268 , V_22 + V_215 ) ;
V_107 -> V_214 = V_247 -> V_8 -> V_97 -> V_139 ;
}
F_3 ( 1 << V_247 -> V_192 , V_22 + V_219 ) ;
F_49 ( V_247 -> V_8 -> V_97 ) ;
return 0 ;
}
static bool F_137 ( struct V_246 * V_247 )
{
struct V_106 * V_107 = V_247 -> V_7 -> V_18 ;
T_6 * V_239 = V_107 -> V_239 ;
if ( V_107 -> V_213 )
V_239 += V_247 -> V_8 -> V_97 -> V_139 * V_320 ;
if ( V_247 -> V_186 . V_258 == V_321 && V_247 -> V_322 == V_323 &&
! ( V_247 -> V_29 & V_324 ) ) {
F_138 ( V_239 + V_325 , & V_247 -> V_326 ) ;
V_247 -> V_326 . V_242 = ( V_239 + V_325 ) [ 15 ] ;
} else
F_138 ( V_239 + V_240 , & V_247 -> V_326 ) ;
return true ;
}
static void F_139 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
F_3 ( 0 , V_22 + V_126 ) ;
}
static void F_140 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_3 ;
struct V_106 * V_107 = V_7 -> V_18 ;
V_3 = F_2 ( V_22 + V_174 ) ;
F_3 ( V_3 , V_22 + V_174 ) ;
F_3 ( 1 << V_7 -> V_156 , V_1 + V_175 ) ;
F_3 ( V_107 -> V_124 , V_22 + V_126 ) ;
}
void F_141 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
if ( ! ( V_7 -> V_178 & V_327 ) ) {
F_33 ( V_7 ) ;
V_16 -> V_79 ( V_7 ) ;
}
F_142 ( V_7 ) ;
if ( ! F_143 ( V_7 -> V_97 . V_9 ) )
F_33 ( V_7 ) ;
}
static void F_144 ( struct V_246 * V_247 )
{
struct V_6 * V_7 = V_247 -> V_7 ;
if ( V_247 -> V_29 & V_324 )
F_72 ( V_7 ) ;
}
static void F_42 ( struct V_6 * V_7 , bool V_328 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_169 * V_8 = V_7 -> V_97 . V_9 ;
T_2 V_329 , V_330 , V_331 , V_332 , V_333 ;
int V_136 ;
unsigned int V_286 ;
V_329 = F_2 ( V_22 + V_334 ) ;
if ( ! ( V_329 & V_335 ) ) {
F_25 ( V_7 -> V_17 -> V_8 , L_57 ) ;
return;
}
if ( ! V_328 ) {
if ( V_329 & V_336 ) {
F_3 ( V_329 & ~ V_336 ,
V_22 + V_334 ) ;
V_286 = F_145 ( V_8 ,
V_337 ,
V_338 ) ;
if ( V_286 && V_286 != V_287 )
F_146 ( V_8 , L_58 ) ;
}
return;
}
if ( V_329 & V_336 )
return;
V_136 = F_33 ( V_7 ) ;
if ( V_136 )
return;
V_330 = ( V_329 & V_339 ) >> V_340 ;
V_331 = V_341 / ( V_330 + 1 ) ;
if ( V_331 > 0x3ff )
V_331 = 0x3ff ;
if ( V_8 -> V_342 [ V_343 ] &
V_344 ) {
V_332 = V_8 -> V_342 [ V_345 ] &
V_346 ;
if ( ! V_332 )
V_332 = 10 ;
V_333 = V_8 -> V_342 [ V_347 ] ;
if ( ! V_333 )
V_333 = 20 ;
} else {
V_332 = 10 ;
V_333 = 20 ;
}
V_329 |= ( ( V_331 << V_348 ) |
( V_332 << V_349 ) |
( V_333 << V_350 ) |
V_336 ) ;
F_3 ( V_329 , V_22 + V_334 ) ;
V_16 -> V_79 ( V_7 ) ;
V_286 = F_145 ( V_8 ,
V_351 ,
V_338 ) ;
if ( V_286 && V_286 != V_287 )
F_146 ( V_8 , L_59 ) ;
}
static void F_87 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_268 ;
int V_136 ;
if ( ! V_107 -> V_352 )
return;
V_268 = F_2 ( V_22 + V_215 ) ;
if ( V_268 & V_353 ) {
V_107 -> V_213 = true ;
V_107 -> V_214 = - 1 ;
return;
}
V_136 = F_33 ( V_7 ) ;
if ( V_136 )
return;
F_3 ( V_268 | V_353 , V_22 + V_215 ) ;
V_268 = F_2 ( V_22 + V_215 ) ;
if ( V_268 & V_353 ) {
F_25 ( V_7 -> V_17 -> V_8 , L_60 ) ;
V_107 -> V_213 = true ;
V_107 -> V_214 = - 1 ;
} else
F_35 ( V_7 -> V_17 -> V_8 , L_61 ) ;
V_16 -> V_79 ( V_7 ) ;
}
static void F_81 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_106 * V_107 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_268 ;
int V_136 ;
if ( ! V_107 -> V_352 )
return;
V_268 = F_2 ( V_22 + V_215 ) ;
if ( ( V_268 & V_353 ) == 0 ) {
V_107 -> V_213 = false ;
return;
}
V_136 = F_33 ( V_7 ) ;
if ( V_136 )
return;
F_3 ( V_268 & ~ V_353 , V_22 + V_215 ) ;
V_268 = F_2 ( V_22 + V_215 ) ;
if ( V_268 & V_353 )
F_35 ( V_7 -> V_17 -> V_8 , L_62 ) ;
else {
F_25 ( V_7 -> V_17 -> V_8 , L_63 ) ;
V_107 -> V_213 = false ;
}
V_16 -> V_79 ( V_7 ) ;
}
static void F_147 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_106 * V_107 = V_7 -> V_18 ;
T_2 V_116 ;
V_116 = F_2 ( V_22 + V_24 ) ;
V_116 |= V_354 ;
F_3 ( V_116 , V_22 + V_24 ) ;
F_87 ( V_7 ) ;
V_107 -> V_124 |= V_234 ;
if ( ! ( V_7 -> V_178 & V_327 ) )
F_3 ( V_107 -> V_124 , V_22 + V_126 ) ;
}
static void F_148 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_106 * V_107 = V_7 -> V_18 ;
T_2 V_116 ;
F_81 ( V_7 ) ;
V_116 = F_2 ( V_22 + V_24 ) ;
V_116 &= ~ V_354 ;
F_3 ( V_116 , V_22 + V_24 ) ;
V_107 -> V_124 &= ~ V_234 ;
if ( ! ( V_7 -> V_178 & V_327 ) )
F_3 ( V_107 -> V_124 , V_22 + V_126 ) ;
}
int F_149 ( struct V_6 * V_7 )
{
F_6 ( V_7 ) ;
F_39 ( V_7 ) ;
F_44 ( V_7 ) ;
if ( F_73 ( V_7 ) )
F_147 ( V_7 ) ;
else
F_148 ( V_7 ) ;
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , T_10 V_355 )
{
const char * V_145 = NULL ;
int V_136 ;
V_136 = F_47 ( V_7 , & V_145 ) ;
if ( V_136 == 0 )
F_43 ( V_7 ) ;
else {
F_151 ( V_7 , L_29 , V_145 , V_136 ) ;
F_118 ( V_7 ) ;
}
F_8 ( V_7 ) ;
return V_136 ;
}
static int F_152 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_9 * V_8 = V_7 -> V_17 -> V_8 ;
struct V_106 * V_107 ;
void * V_356 ;
T_5 V_357 ;
T_4 V_358 , V_359 ;
V_107 = F_153 ( V_8 , sizeof( * V_107 ) , V_360 ) ;
if ( ! V_107 )
return - V_361 ;
if ( V_7 -> V_17 -> V_180 > 1 ) {
V_107 -> V_362 = F_153 ( V_8 , 8 , V_360 ) ;
if ( ! V_107 -> V_362 ) {
F_154 ( V_8 , V_107 ) ;
return - V_361 ;
}
snprintf ( V_107 -> V_362 , 8 ,
L_64 , F_155 ( V_8 ) , V_7 -> V_156 ) ;
}
if ( ( V_16 -> V_19 & V_72 ) && F_156 ( V_7 ) ) {
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_116 = F_2 ( V_22 + V_24 ) ;
if ( V_116 & V_363 )
V_107 -> V_352 = true ;
else if ( V_16 -> V_29 & V_73 ) {
F_25 ( V_8 , L_65 ,
V_7 -> V_156 ) ;
V_107 -> V_352 = true ;
} else
F_26 ( V_8 , L_66 ,
V_7 -> V_156 ) ;
}
if ( V_107 -> V_352 ) {
V_358 = V_364 ;
V_359 = V_320 * 16 ;
} else {
V_358 = V_365 ;
V_359 = V_320 ;
}
V_356 = F_157 ( V_8 , V_358 , & V_357 , V_360 ) ;
if ( ! V_356 )
return - V_361 ;
memset ( V_356 , 0 , V_358 ) ;
V_107 -> V_196 = V_356 ;
V_107 -> V_108 = V_357 ;
V_356 += V_366 ;
V_357 += V_366 ;
V_107 -> V_239 = V_356 ;
V_107 -> V_111 = V_357 ;
V_356 += V_359 ;
V_357 += V_359 ;
V_107 -> V_212 = V_356 ;
V_107 -> V_194 = V_357 ;
V_107 -> V_124 = V_367 ;
if ( V_16 -> V_29 & V_368 ) {
F_158 ( & V_107 -> V_31 ) ;
V_7 -> V_31 = & V_107 -> V_31 ;
}
V_7 -> V_18 = V_107 ;
return F_149 ( V_7 ) ;
}
static void F_159 ( struct V_6 * V_7 )
{
const char * V_145 = NULL ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_369 = V_16 -> V_1 ;
int V_136 ;
V_136 = F_47 ( V_7 , & V_145 ) ;
if ( V_136 )
F_21 ( V_7 , L_29 , V_145 , V_136 ) ;
F_3 ( 1 << V_7 -> V_156 , V_369 + V_175 ) ;
}
void F_160 ( struct V_83 * V_17 , const char * V_370 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
T_2 V_51 , V_19 , V_20 , V_371 , V_372 ;
const char * V_373 ;
V_51 = V_16 -> V_21 ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_371 = V_16 -> V_52 ;
V_372 = ( V_19 >> 20 ) & 0xf ;
if ( V_372 == 1 )
V_373 = L_67 ;
else if ( V_372 == 2 )
V_373 = L_68 ;
else if ( V_372 == 3 )
V_373 = L_69 ;
else
V_373 = L_70 ;
F_25 ( V_17 -> V_8 ,
L_71
L_72
,
( V_51 >> 24 ) & 0xff ,
( V_51 >> 16 ) & 0xff ,
( V_51 >> 8 ) & 0xff ,
V_51 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_373 ,
V_371 ,
V_370 ) ;
F_25 ( V_17 -> V_8 ,
L_73
L_74
L_74
L_74
L_75
,
V_19 & V_60 ? L_76 : L_6 ,
V_19 & V_62 ? L_77 : L_6 ,
V_19 & V_67 ? L_78 : L_6 ,
V_19 & V_374 ? L_79 : L_6 ,
V_19 & V_118 ? L_80 : L_6 ,
V_19 & V_127 ? L_81 : L_6 ,
V_19 & V_375 ? L_5 : L_6 ,
V_19 & V_205 ? L_82 : L_6 ,
V_19 & V_376 ? L_83 : L_6 ,
V_19 & V_65 ? L_84 : L_6 ,
V_19 & V_72 ? L_85 : L_6 ,
V_19 & V_377 ? L_86 : L_6 ,
V_19 & V_378 ? L_87 : L_6 ,
V_19 & V_379 ? L_88 : L_6 ,
V_19 & V_380 ? L_89 : L_6 ,
V_19 & V_381 ? L_90 : L_6 ,
V_19 & V_177 ? L_91 : L_6 ,
V_20 & V_382 ? L_92 : L_6 ,
V_20 & V_71 ? L_93 : L_6 ,
V_20 & V_69 ? L_94 : L_6 ,
V_20 & V_383 ? L_95 : L_6 ,
V_20 & V_384 ? L_96 : L_6 ,
V_20 & V_385 ? L_97 : L_6
) ;
}
void F_161 ( struct V_15 * V_16 ,
struct V_386 * V_387 )
{
T_6 V_388 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 = F_2 ( V_1 + V_389 ) ;
T_2 V_27 = F_2 ( V_1 + V_32 ) ;
if ( ! V_390 || ! ( V_16 -> V_19 & V_381 ) )
return;
V_388 = ( V_27 & V_391 ) >> 16 ;
if ( V_388 ) {
V_16 -> V_26 = ( ( V_26 >> 16 ) * 4 ) ;
V_16 -> V_41 = ( ( V_26 & 0xff ) * 4 ) ;
V_16 -> V_35 = V_388 ;
V_387 -> V_29 |= V_33 ;
if ( ! ( V_27 & V_392 ) )
V_387 -> V_29 |= V_144 ;
}
}
static int F_162 ( struct V_83 * V_17 ,
struct V_393 * V_394 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
int V_2 , V_136 ;
V_136 = F_163 ( V_17 ) ;
if ( V_136 )
return V_136 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_180 ; V_2 ++ ) {
struct V_106 * V_107 = V_17 -> V_181 [ V_2 ] -> V_18 ;
int V_314 = V_16 -> V_395 ( V_17 , V_2 ) ;
if ( ! V_107 ) {
F_164 ( V_314 ) ;
continue;
}
V_136 = F_165 ( V_17 -> V_8 , V_314 , F_129 ,
0 , V_107 -> V_362 , V_17 -> V_181 [ V_2 ] ) ;
if ( V_136 )
return V_136 ;
F_166 ( V_17 -> V_181 [ V_2 ] , L_98 , V_314 ) ;
}
return F_167 ( V_17 , V_394 ) ;
}
int F_168 ( struct V_83 * V_17 , struct V_393 * V_394 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
int V_314 = V_16 -> V_314 ;
int V_136 ;
if ( V_16 -> V_29 & V_368 ) {
if ( V_16 -> V_81 )
F_26 ( V_17 -> V_8 ,
L_99 ) ;
if ( ! V_16 -> V_395 ) {
F_35 ( V_17 -> V_8 ,
L_100 ) ;
return - V_104 ;
}
V_136 = F_162 ( V_17 , V_394 ) ;
} else {
V_136 = F_169 ( V_17 , V_314 , V_16 -> V_81 ,
V_396 , V_394 ) ;
}
return V_136 ;
}
