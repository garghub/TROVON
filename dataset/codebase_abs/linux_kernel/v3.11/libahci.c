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
static T_3 F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
return sprintf ( V_10 , L_1 , V_16 -> V_19 ) ;
}
static T_3 F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
return sprintf ( V_10 , L_1 , V_16 -> V_20 ) ;
}
static T_3 F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
return sprintf ( V_10 , L_1 , F_2 ( V_1 + V_21 ) ) ;
}
static T_3 F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
void T_1 * V_22 = F_12 ( V_14 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_22 + V_23 ) ) ;
}
static T_3 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_24 = V_1 + V_16 -> V_25 ;
T_2 V_26 , V_27 ;
unsigned long V_28 ;
T_4 V_29 ;
int V_2 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! ( V_14 -> V_28 & V_32 ) || V_26 & V_33 ||
! ( V_16 -> V_34 & V_35 ) ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_36 ;
}
if ( ! ( V_26 & V_37 ) ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_38 ;
}
if ( ! ( V_26 & V_39 ) )
V_24 += V_16 -> V_40 ;
V_29 = V_16 -> V_40 ;
if ( V_29 > V_41 ) {
if ( F_16 () )
F_17 ( V_14 ,
L_2
L_3 ,
V_16 -> V_40 , V_41 ) ;
V_29 = V_41 ;
}
for ( V_2 = 0 ; V_2 < V_29 ; V_2 += 4 ) {
V_27 = F_2 ( V_24 + V_2 ) ;
V_10 [ V_2 ] = V_27 & 0xff ;
V_10 [ V_2 + 1 ] = ( V_27 >> 8 ) & 0xff ;
V_10 [ V_2 + 2 ] = ( V_27 >> 16 ) & 0xff ;
V_10 [ V_2 + 3 ] = ( V_27 >> 24 ) & 0xff ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_2 ;
}
static T_3 F_18 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_4 V_42 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_24 = V_1 + V_16 -> V_25 ;
const unsigned char * V_43 = V_10 ;
T_2 V_26 , V_27 ;
unsigned long V_28 ;
int V_2 ;
if ( ! ( V_14 -> V_28 & V_32 ) ||
! ( V_16 -> V_34 & V_35 ) ||
V_42 % 4 || V_42 > V_16 -> V_40 )
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
for ( V_2 = 0 ; V_2 < V_42 ; V_2 += 4 ) {
V_27 = V_43 [ V_2 ] | V_43 [ V_2 + 1 ] << 8 |
V_43 [ V_2 + 2 ] << 16 | V_43 [ V_2 + 3 ] << 24 ;
F_3 ( V_27 , V_24 + V_2 ) ;
}
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_42 ;
}
static T_3 F_19 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
return sprintf ( V_10 , L_4 ,
V_26 & V_46 ? L_5 : L_6 ,
V_26 & V_47 ? L_7 : L_6 ,
V_26 & V_48 ? L_8 : L_6 ,
V_26 & V_49 ? L_9 : L_6 ) ;
}
void F_20 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int V_50 ,
unsigned int V_51 )
{
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_19 , V_20 , V_52 , V_53 ;
int V_2 ;
F_1 ( V_1 ) ;
V_16 -> V_54 = V_19 = F_2 ( V_1 + V_55 ) ;
V_16 -> V_56 = V_53 = F_2 ( V_1 + V_57 ) ;
V_52 = F_2 ( V_1 + V_21 ) ;
if ( ( V_52 >> 16 ) > 1 ||
( ( V_52 >> 16 ) == 1 && ( V_52 & 0xFFFF ) >= 0x200 ) )
V_16 -> V_58 = V_20 = F_2 ( V_1 + V_59 ) ;
else
V_16 -> V_58 = V_20 = 0 ;
if ( ( V_19 & V_60 ) && ( V_16 -> V_28 & V_61 ) ) {
F_21 ( V_7 , L_10 ) ;
V_19 &= ~ V_60 ;
}
if ( ( V_19 & V_62 ) && ( V_16 -> V_28 & V_63 ) ) {
F_21 ( V_7 , L_11 ) ;
V_19 &= ~ V_62 ;
}
if ( ! ( V_19 & V_62 ) && ( V_16 -> V_28 & V_64 ) ) {
F_21 ( V_7 , L_12 ) ;
V_19 |= V_62 ;
}
if ( ( V_19 & V_65 ) && ( V_16 -> V_28 & V_66 ) ) {
F_21 ( V_7 , L_13 ) ;
V_19 &= ~ V_65 ;
}
if ( ( V_19 & V_67 ) && ( V_16 -> V_28 & V_68 ) ) {
F_21 ( V_7 ,
L_14 ) ;
V_19 &= ~ V_67 ;
}
if ( ! ( V_19 & V_69 ) && ( V_16 -> V_28 & V_70 ) ) {
F_21 ( V_7 , L_15 ) ;
V_19 |= V_69 ;
}
if ( V_50 && V_53 != V_50 ) {
F_21 ( V_7 , L_16 ,
V_53 , V_50 ) ;
V_53 = V_50 ;
}
if ( V_51 ) {
F_22 ( V_7 , L_17 ,
V_53 ,
V_53 & V_51 ) ;
V_53 &= V_51 ;
}
if ( V_53 ) {
int V_71 = 0 ;
for ( V_2 = 0 ; V_2 < V_72 ; V_2 ++ )
if ( V_53 & ( 1 << V_2 ) )
V_71 ++ ;
if ( V_71 > F_23 ( V_19 ) ) {
F_22 ( V_7 ,
L_18 ,
V_53 , F_23 ( V_19 ) ) ;
V_53 = 0 ;
}
}
if ( ! V_53 ) {
V_53 = ( 1 << F_23 ( V_19 ) ) - 1 ;
F_22 ( V_7 , L_19 , V_53 ) ;
V_16 -> V_56 = V_53 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_53 = V_53 ;
}
static void F_24 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_54 , V_1 + V_55 ) ;
if ( V_16 -> V_58 )
F_3 ( V_16 -> V_58 , V_1 + V_59 ) ;
F_3 ( V_16 -> V_56 , V_1 + V_57 ) ;
( void ) F_2 ( V_1 + V_57 ) ;
}
static unsigned F_25 ( struct V_13 * V_14 , unsigned int V_74 )
{
static const int V_75 [] = {
[ V_76 ] = V_77 ,
[ V_78 ] = V_79 ,
[ V_80 ] = V_81 ,
[ V_82 ] = V_83 ,
[ V_84 ] = V_85 ,
} ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( V_74 < F_26 ( V_75 ) &&
( V_74 != V_84 || ( V_16 -> V_19 & V_67 ) ) )
return V_75 [ V_74 ] ;
return 0 ;
}
static int F_27 ( struct V_86 * V_87 , unsigned int V_74 , T_2 * V_88 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
int V_75 = F_25 ( V_87 -> V_14 , V_74 ) ;
if ( V_75 ) {
* V_88 = F_2 ( V_22 + V_75 ) ;
return 0 ;
}
return - V_36 ;
}
static int F_28 ( struct V_86 * V_87 , unsigned int V_74 , T_2 V_88 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
int V_75 = F_25 ( V_87 -> V_14 , V_74 ) ;
if ( V_75 ) {
F_3 ( V_88 , V_22 + V_75 ) ;
return 0 ;
}
return - V_36 ;
}
void F_29 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_89 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
int F_30 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
if ( ( V_3 & ( V_89 | V_90 ) ) == 0 )
return 0 ;
V_3 &= ~ V_89 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_31 ( V_14 , V_22 + V_23 ,
V_90 , V_90 , 1 , 500 ) ;
if ( V_3 & V_90 )
return - V_91 ;
return 0 ;
}
static void F_32 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_93 -> V_94 >> 16 ) >> 16 ,
V_22 + V_95 ) ;
F_3 ( V_93 -> V_94 & 0xffffffff , V_22 + V_96 ) ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_93 -> V_97 >> 16 ) >> 16 ,
V_22 + V_98 ) ;
F_3 ( V_93 -> V_97 & 0xffffffff , V_22 + V_99 ) ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_100 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
static int F_33 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 &= ~ V_100 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_31 ( V_14 , V_22 + V_23 , V_101 ,
V_101 , 10 , 1000 ) ;
if ( V_3 & V_101 )
return - V_45 ;
return 0 ;
}
static void F_34 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 ;
V_102 = F_2 ( V_22 + V_23 ) & ~ V_103 ;
if ( V_16 -> V_19 & V_104 ) {
V_102 |= V_105 ;
F_3 ( V_102 , V_22 + V_23 ) ;
}
F_3 ( V_102 | V_106 , V_22 + V_23 ) ;
}
static int F_35 ( struct V_86 * V_87 , enum V_107 V_108 ,
unsigned int V_109 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
if ( V_108 != V_110 ) {
V_93 -> V_111 &= ~ V_112 ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
F_36 ( V_87 , V_108 , false ) ;
}
if ( V_16 -> V_19 & V_114 ) {
T_2 V_102 = F_2 ( V_22 + V_23 ) ;
if ( V_108 == V_110 || ! ( V_109 & V_115 ) ) {
V_102 &= ~ ( V_116 | V_117 ) ;
V_102 |= V_106 ;
F_3 ( V_102 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
F_37 ( V_14 , 10 ) ;
} else {
V_102 |= V_117 ;
if ( V_108 == V_118 )
V_102 |= V_116 ;
F_3 ( V_102 , V_22 + V_23 ) ;
}
}
if ( ( V_16 -> V_20 & V_119 ) &&
( V_16 -> V_20 & V_120 ) &&
( V_87 -> V_6 -> V_28 & V_121 ) ) {
if ( V_108 == V_118 )
F_38 ( V_14 , true ) ;
else
F_38 ( V_14 , false ) ;
}
if ( V_108 == V_110 ) {
F_36 ( V_87 , V_108 , false ) ;
V_93 -> V_111 |= V_112 ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
return 0 ;
}
static void F_39 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 , V_122 ;
if ( ! ( V_16 -> V_19 & V_104 ) )
return;
V_122 = F_2 ( V_22 + V_79 ) ;
V_122 &= ~ 0xf ;
F_3 ( V_122 , V_22 + V_79 ) ;
V_102 = F_2 ( V_22 + V_23 ) & ~ V_103 ;
V_102 &= ~ V_105 ;
F_3 ( V_102 , V_22 + V_23 ) ;
}
static void F_40 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_86 * V_87 ;
struct V_123 * V_124 ;
T_3 V_125 ;
int V_2 ;
F_32 ( V_14 ) ;
if ( ! ( V_16 -> V_28 & V_126 ) )
F_29 ( V_14 ) ;
if ( V_14 -> V_28 & V_32 ) {
F_41 (link, ap, EDGE) {
V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
for ( V_2 = 0 ; V_2 < V_129 ; V_2 ++ ) {
V_125 = V_14 -> V_130 -> V_131 ( V_14 ,
V_124 -> V_132 ,
4 ) ;
if ( V_125 == - V_45 )
F_37 ( V_14 , 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_133 )
F_41 (link, ap, EDGE)
F_42 ( V_87 ) ;
}
static int F_43 ( struct V_13 * V_14 , const char * * V_134 )
{
int V_125 ;
V_125 = F_30 ( V_14 ) ;
if ( V_125 ) {
* V_134 = L_20 ;
return V_125 ;
}
V_125 = F_33 ( V_14 ) ;
if ( V_125 ) {
* V_134 = L_21 ;
return V_125 ;
}
return 0 ;
}
int F_44 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_135 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_136 ) == 0 ) {
F_3 ( V_3 | V_136 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_31 ( NULL , V_1 + V_4 , V_136 ,
V_136 , 10 , 1000 ) ;
if ( V_3 & V_136 ) {
F_45 ( V_17 -> V_7 , L_22 ,
V_3 ) ;
return - V_91 ;
}
F_1 ( V_1 ) ;
F_24 ( V_17 ) ;
} else
F_21 ( V_17 -> V_7 , L_23 ) ;
return 0 ;
}
static void F_46 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
if ( ! ( V_87 -> V_28 & V_137 ) )
return;
V_124 -> V_138 ++ ;
if ( ! F_47 ( & V_124 -> V_139 ) )
F_48 ( & V_124 -> V_139 , V_140 + F_49 ( 10 ) ) ;
}
static void F_50 ( unsigned long V_141 )
{
struct V_86 * V_87 = (struct V_86 * ) V_141 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
unsigned long V_142 = V_124 -> V_132 ;
T_2 V_143 ;
unsigned long V_28 ;
V_142 &= V_144 ;
V_142 |= V_14 -> V_145 | ( V_87 -> V_128 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_124 -> V_146 != V_124 -> V_138 ) {
V_124 -> V_146 = V_124 -> V_138 ;
V_143 = V_142 & V_147 ;
if ( V_143 )
V_143 = 0 ;
else
V_143 = 1 ;
V_142 &= ~ V_148 ;
V_142 |= ( V_143 << 16 ) ;
F_48 ( & V_124 -> V_139 , V_140 + F_49 ( 100 ) ) ;
} else {
V_142 &= ~ V_148 ;
if ( V_124 -> V_149 == V_150 )
V_142 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
V_14 -> V_130 -> V_131 ( V_14 , V_142 , 4 ) ;
}
static void F_42 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
V_124 -> V_146 = V_124 -> V_138 = 0 ;
F_51 ( & V_124 -> V_139 , F_50 , ( unsigned long ) V_87 ) ;
if ( V_124 -> V_149 )
V_87 -> V_28 |= V_137 ;
}
int F_52 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_44 ) || ( V_26 & V_151 ) )
return - V_36 ;
F_3 ( V_26 | V_151 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_53 ( struct V_13 * V_14 , T_2 V_152 ,
T_3 V_42 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_153 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_128 ;
struct V_123 * V_124 ;
V_128 = ( V_152 & V_154 ) >> 8 ;
if ( V_128 < V_155 )
V_124 = & V_93 -> V_127 [ V_128 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
if ( V_16 -> V_34 & V_156 ) {
V_153 [ 0 ] |= ( 4 << 8 ) ;
V_153 [ 1 ] = ( ( V_152 & ~ V_157 ) | V_14 -> V_145 ) ;
F_3 ( V_153 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_153 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
}
V_124 -> V_132 = V_152 ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_42 ;
}
static T_3 F_54 ( struct V_13 * V_14 , char * V_10 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_86 * V_87 ;
struct V_123 * V_124 ;
int V_125 = 0 ;
F_41 (link, ap, EDGE) {
V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
V_125 += sprintf ( V_10 , L_24 , V_124 -> V_132 ) ;
}
return V_125 ;
}
static T_3 F_55 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_42 )
{
int V_152 ;
int V_128 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 ;
V_152 = F_56 ( V_10 , NULL , 0 ) ;
V_128 = ( V_152 & V_154 ) >> 8 ;
if ( V_128 < V_155 )
V_124 = & V_93 -> V_127 [ V_128 ] ;
else
return - V_36 ;
if ( V_124 -> V_149 )
V_152 &= ~ V_148 ;
return V_14 -> V_130 -> V_131 ( V_14 , V_152 , V_42 ) ;
}
static T_3 F_57 ( struct V_158 * V_7 , enum V_159 V_88 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
T_2 V_160 = V_124 -> V_132 ;
if ( V_88 == V_161 ) {
V_87 -> V_28 &= ~ ( V_137 ) ;
V_160 &= V_162 ;
V_160 |= ( V_14 -> V_145 | ( V_87 -> V_128 << 8 ) ) ;
V_14 -> V_130 -> V_131 ( V_14 , V_160 , 4 ) ;
} else {
V_87 -> V_28 |= V_137 ;
if ( V_88 == V_150 ) {
V_160 &= V_162 ;
V_160 |= ( V_14 -> V_145 | ( V_87 -> V_128 << 8 ) ) ;
V_160 |= V_147 ;
V_14 -> V_130 -> V_131 ( V_14 , V_160 , 4 ) ;
}
}
V_124 -> V_149 = V_88 ;
return 0 ;
}
static T_3 F_58 ( struct V_158 * V_7 , char * V_10 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
return sprintf ( V_10 , L_25 , V_124 -> V_149 ) ;
}
static void F_59 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_145 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_134 = NULL ;
int V_125 ;
T_2 V_3 ;
V_125 = F_43 ( V_14 , & V_134 ) ;
if ( V_125 )
F_22 ( V_7 , L_26 , V_134 , V_125 ) ;
V_3 = F_2 ( V_22 + V_81 ) ;
F_60 ( L_27 , V_3 ) ;
F_3 ( V_3 , V_22 + V_81 ) ;
V_3 = F_2 ( V_22 + V_163 ) ;
F_60 ( L_28 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_163 ) ;
F_3 ( 1 << V_145 , V_1 + V_164 ) ;
}
void F_61 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_165 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_166 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_62 ( V_14 ) )
continue;
F_59 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_60 ( L_29 , V_3 ) ;
F_3 ( V_3 | V_167 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_60 ( L_29 , V_3 ) ;
}
static void F_63 ( struct V_158 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_87 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_168 ) {
V_7 -> V_169 = 255 ;
F_64 ( V_7 ,
L_30 ) ;
}
}
unsigned int F_65 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_170 V_171 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_172 ) ;
V_171 . V_173 = ( V_3 >> 24 ) & 0xff ;
V_171 . V_174 = ( V_3 >> 16 ) & 0xff ;
V_171 . V_175 = ( V_3 >> 8 ) & 0xff ;
V_171 . V_176 = ( V_3 ) & 0xff ;
return F_66 ( & V_171 ) ;
}
void F_67 ( struct V_92 * V_93 , unsigned int V_177 ,
T_2 V_178 )
{
T_5 V_179 ;
V_179 = V_93 -> V_179 + V_177 * V_180 ;
V_93 -> V_181 [ V_177 ] . V_178 = F_68 ( V_178 ) ;
V_93 -> V_181 [ V_177 ] . V_182 = 0 ;
V_93 -> V_181 [ V_177 ] . V_183 = F_68 ( V_179 & 0xffffffff ) ;
V_93 -> V_181 [ V_177 ] . V_184 = F_68 ( ( V_179 >> 16 ) >> 16 ) ;
}
int F_69 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_182 = F_2 ( V_22 + V_185 ) & 0xFF ;
T_2 V_3 ;
int V_186 , V_125 ;
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
goto V_187;
V_186 = V_182 & ( V_188 | V_189 ) ;
if ( ! V_186 && ! F_70 ( V_14 ) ) {
V_125 = 0 ;
goto V_187;
}
if ( ! ( V_16 -> V_19 & V_190 ) ) {
V_125 = - V_191 ;
goto V_187;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_192 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_125 = 0 ;
V_3 = F_31 ( V_14 , V_22 + V_23 ,
V_192 , V_192 , 1 , 500 ) ;
if ( V_3 & V_192 )
V_125 = - V_91 ;
V_187:
F_29 ( V_14 ) ;
return V_125 ;
}
static int F_71 ( struct V_13 * V_14 , int V_128 ,
struct V_170 * V_171 , int V_193 , T_7 V_28 ,
unsigned long V_194 )
{
const T_2 V_195 = 5 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_196 = V_93 -> V_197 ;
T_2 V_3 ;
F_72 ( V_171 , V_128 , V_193 , V_196 ) ;
F_67 ( V_93 , 0 , V_195 | V_28 | ( V_128 << 12 ) ) ;
F_3 ( 1 , V_22 + V_198 ) ;
if ( V_194 ) {
V_3 = F_31 ( V_14 , V_22 + V_198 ,
0x1 , 0x1 , 1 , V_194 ) ;
if ( V_3 & 0x1 ) {
F_69 ( V_14 ) ;
return - V_45 ;
}
} else
F_2 ( V_22 + V_198 ) ;
return 0 ;
}
int F_73 ( struct V_86 * V_87 , unsigned int * V_199 ,
int V_128 , unsigned long V_200 ,
int (* F_74)( struct V_86 * V_87 ) )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
const char * V_201 = NULL ;
unsigned long V_202 , V_203 ;
struct V_170 V_171 ;
int V_125 ;
F_75 ( L_31 ) ;
V_125 = F_69 ( V_14 ) ;
if ( V_125 && V_125 != - V_191 )
F_76 ( V_87 , L_32 , V_125 ) ;
F_77 ( V_87 -> V_6 , & V_171 ) ;
V_203 = 0 ;
V_202 = V_140 ;
if ( F_78 ( V_200 , V_202 ) )
V_203 = F_79 ( V_200 - V_202 ) ;
V_171 . V_204 |= V_205 ;
if ( F_71 ( V_14 , V_128 , & V_171 , 0 ,
V_206 | V_207 , V_203 ) ) {
V_125 = - V_91 ;
V_201 = L_33 ;
goto V_208;
}
F_37 ( V_14 , 1 ) ;
V_171 . V_204 &= ~ V_205 ;
F_71 ( V_14 , V_128 , & V_171 , 0 , 0 , 0 ) ;
V_125 = F_80 ( V_87 , V_200 , F_74 ) ;
if ( V_125 == - V_45 && V_16 -> V_28 & V_209 ) {
F_81 ( V_87 , L_34 ) ;
* V_199 = V_210 ;
} else if ( V_125 ) {
V_201 = L_35 ;
goto V_208;
} else
* V_199 = F_65 ( V_14 ) ;
F_75 ( L_36 , * V_199 ) ;
return 0 ;
V_208:
F_82 ( V_87 , L_37 , V_201 ) ;
return V_125 ;
}
int F_83 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_182 = F_2 ( V_22 + V_185 ) & 0xFF ;
return F_84 ( V_182 ) ;
}
static int F_85 ( struct V_86 * V_87 , unsigned int * V_199 ,
unsigned long V_200 )
{
int V_128 = F_86 ( V_87 ) ;
F_75 ( L_31 ) ;
return F_73 ( V_87 , V_199 , V_128 , V_200 , F_83 ) ;
}
static int F_87 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_182 = F_2 ( V_22 + V_185 ) & 0xFF ;
T_2 V_211 = F_2 ( V_22 + V_163 ) ;
if ( V_211 & V_212 )
return - V_91 ;
return F_84 ( V_182 ) ;
}
int F_88 ( struct V_86 * V_87 , unsigned int * V_199 ,
unsigned long V_200 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
int V_128 = F_86 ( V_87 ) ;
int V_125 ;
T_2 V_213 ;
F_75 ( L_31 ) ;
V_125 = F_73 ( V_87 , V_199 , V_128 , V_200 ,
F_87 ) ;
if ( V_125 == - V_91 ) {
V_213 = F_2 ( V_22 + V_163 ) ;
if ( V_213 & V_212 ) {
F_76 ( V_87 ,
L_38
L_39 ) ;
V_125 = F_73 ( V_87 , V_199 , 0 , V_200 ,
F_83 ) ;
}
}
return V_125 ;
}
static int F_89 ( struct V_86 * V_87 , unsigned int * V_199 ,
unsigned long V_200 )
{
const unsigned long * V_214 = F_90 ( & V_87 -> V_215 ) ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_6 * V_216 = V_93 -> V_217 + V_218 ;
struct V_170 V_171 ;
bool V_219 ;
int V_125 ;
F_75 ( L_31 ) ;
F_30 ( V_14 ) ;
F_77 ( V_87 -> V_6 , & V_171 ) ;
V_171 . V_220 = V_188 ;
F_72 ( & V_171 , 0 , 0 , V_216 ) ;
V_125 = F_91 ( V_87 , V_214 , V_200 , & V_219 ,
F_83 ) ;
F_29 ( V_14 ) ;
if ( V_219 )
* V_199 = F_65 ( V_14 ) ;
F_75 ( L_40 , V_125 , * V_199 ) ;
return V_125 ;
}
static void F_92 ( struct V_86 * V_87 , unsigned int * V_199 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_221 , V_3 ;
F_93 ( V_87 , V_199 ) ;
V_221 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_199 == V_222 )
V_221 |= V_223 ;
else
V_221 &= ~ V_223 ;
if ( V_221 != V_3 ) {
F_3 ( V_221 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_94 ( struct V_224 * V_225 , void * V_197 )
{
struct V_226 * V_227 ;
struct V_228 * V_228 = V_197 + V_229 ;
unsigned int V_230 ;
F_60 ( L_31 ) ;
F_95 (qc->sg, sg, qc->n_elem, si) {
T_5 V_231 = F_96 ( V_227 ) ;
T_2 V_232 = F_97 ( V_227 ) ;
V_228 [ V_230 ] . V_231 = F_68 ( V_231 & 0xffffffff ) ;
V_228 [ V_230 ] . V_233 = F_68 ( ( V_231 >> 16 ) >> 16 ) ;
V_228 [ V_230 ] . V_234 = F_68 ( V_232 - 1 ) ;
}
return V_230 ;
}
static int F_98 ( struct V_224 * V_225 )
{
struct V_13 * V_14 = V_225 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
if ( ! F_70 ( V_14 ) || V_93 -> V_235 )
return F_99 ( V_225 ) ;
else
return F_100 ( V_225 ) ;
}
static void F_101 ( struct V_224 * V_225 )
{
struct V_13 * V_14 = V_225 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
int V_236 = F_102 ( V_225 -> V_171 . V_237 ) ;
void * V_197 ;
T_2 V_178 ;
const T_2 V_195 = 5 ;
unsigned int V_238 ;
V_197 = V_93 -> V_197 + V_225 -> V_177 * V_180 ;
F_72 ( & V_225 -> V_171 , V_225 -> V_7 -> V_87 -> V_128 , 1 , V_197 ) ;
if ( V_236 ) {
memset ( V_197 + V_239 , 0 , 32 ) ;
memcpy ( V_197 + V_239 , V_225 -> V_240 , V_225 -> V_7 -> V_241 ) ;
}
V_238 = 0 ;
if ( V_225 -> V_28 & V_242 )
V_238 = F_94 ( V_225 , V_197 ) ;
V_178 = V_195 | V_238 << 16 | ( V_225 -> V_7 -> V_87 -> V_128 << 12 ) ;
if ( V_225 -> V_171 . V_28 & V_243 )
V_178 |= V_244 ;
if ( V_236 )
V_178 |= V_245 | V_246 ;
F_67 ( V_93 , V_225 -> V_177 , V_178 ) ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_247 = F_2 ( V_22 + V_248 ) ;
int V_249 = 3 ;
F_75 ( L_31 ) ;
F_104 ( ! V_93 -> V_235 ) ;
F_3 ( V_247 | V_250 , V_22 + V_248 ) ;
V_247 = F_2 ( V_22 + V_248 ) ;
while ( ( V_247 & V_250 ) && V_249 -- ) {
F_105 ( 1 ) ;
V_247 = F_2 ( V_22 + V_248 ) ;
}
if ( V_247 & V_250 )
F_45 ( V_14 -> V_17 -> V_7 , L_41 ) ;
}
static void F_106 ( struct V_13 * V_14 , T_2 V_251 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_252 * V_253 = & V_14 -> V_87 . V_254 ;
struct V_86 * V_87 = NULL ;
struct V_224 * V_255 ;
struct V_252 * V_256 ;
bool V_257 = false ;
T_2 V_258 ;
if ( V_93 -> V_235 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_247 = F_2 ( V_22 + V_248 ) ;
int V_128 = V_247 >> V_259 ;
if ( ( V_247 & V_260 ) && ( V_128 < V_14 -> V_261 ) ) {
V_87 = & V_14 -> V_262 [ V_128 ] ;
V_257 = true ;
}
} else
F_41 (link, ap, EDGE)
if ( F_107 ( V_87 ) )
break;
if ( ! V_87 )
V_87 = & V_14 -> V_87 ;
V_255 = F_108 ( V_14 , V_87 -> V_263 ) ;
V_256 = & V_87 -> V_254 ;
F_109 ( V_253 ) ;
F_110 ( V_253 , L_42 , V_251 ) ;
F_27 ( & V_14 -> V_87 , V_80 , & V_258 ) ;
F_28 ( & V_14 -> V_87 , V_80 , V_258 ) ;
V_253 -> V_258 |= V_258 ;
if ( V_16 -> V_28 & V_264 )
V_251 &= ~ V_265 ;
if ( V_251 & V_266 ) {
if ( V_255 )
V_255 -> V_267 |= V_268 ;
else
V_256 -> V_267 |= V_268 ;
if ( V_16 -> V_28 & V_269 )
V_253 -> V_258 &= ~ V_270 ;
}
if ( V_251 & V_271 ) {
T_2 * V_272 = ( T_2 * ) ( V_93 -> V_217 + V_273 ) ;
V_256 -> V_267 |= V_274 ;
V_256 -> V_275 |= V_276 ;
F_110 ( V_256 ,
L_43 ,
V_272 [ 0 ] , V_272 [ 1 ] , V_272 [ 2 ] , V_272 [ 3 ] ) ;
}
if ( F_70 ( V_14 ) && ( V_251 & V_212 ) ) {
V_256 -> V_267 |= V_274 ;
V_256 -> V_275 |= V_276 ;
F_110 ( V_256 , L_44 ) ;
}
if ( V_251 & ( V_277 | V_278 ) ) {
V_253 -> V_267 |= V_279 ;
V_253 -> V_275 |= V_276 ;
F_110 ( V_253 , L_45 ) ;
}
if ( V_251 & V_265 ) {
if ( V_257 )
V_256 -> V_267 |= V_268 ;
else {
V_253 -> V_267 |= V_280 ;
V_253 -> V_275 |= V_276 ;
}
F_110 ( V_253 , L_46 ) ;
}
if ( V_251 & ( V_281 | V_112 ) ) {
F_111 ( V_253 ) ;
F_110 ( V_253 , L_47 ,
V_251 & V_281 ?
L_48 : L_49 ) ;
}
if ( V_251 & V_282 )
F_112 ( V_14 ) ;
else if ( V_257 ) {
F_113 ( V_87 ) ;
F_103 ( V_14 ) ;
} else
F_114 ( V_14 ) ;
}
static void F_115 ( struct V_13 * V_14 ,
void T_1 * V_22 , T_2 V_182 )
{
struct V_252 * V_283 = & V_14 -> V_87 . V_254 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_284 = ! ! ( V_14 -> V_285 & V_286 ) ;
T_2 V_287 = 0 ;
int V_125 ;
if ( F_116 ( V_284 ) )
V_182 &= ~ V_212 ;
if ( V_14 -> V_87 . V_288 > V_110 ) {
V_182 &= ~ V_112 ;
F_28 ( & V_14 -> V_87 , V_80 , V_289 ) ;
}
if ( F_116 ( V_182 & V_290 ) ) {
F_106 ( V_14 , V_182 ) ;
return;
}
if ( V_182 & V_291 ) {
if ( V_16 -> V_19 & V_67 )
F_117 ( V_14 ) ;
else {
if ( V_93 -> V_235 )
F_118 ( 1 ) ;
else {
const T_8 * V_292 = V_93 -> V_217 + V_293 ;
T_2 V_294 = F_119 ( V_292 [ 0 ] ) ;
if ( V_294 & ( 1 << 15 ) )
F_117 ( V_14 ) ;
}
}
}
if ( V_93 -> V_235 ) {
if ( V_14 -> V_287 ) {
V_287 = F_2 ( V_22 + V_83 ) ;
V_287 |= F_2 ( V_22 + V_198 ) ;
}
} else {
if ( V_14 -> V_287 && V_93 -> V_295 -> V_296 )
V_287 = F_2 ( V_22 + V_83 ) ;
else
V_287 = F_2 ( V_22 + V_198 ) ;
}
V_125 = F_120 ( V_14 , V_287 ) ;
if ( F_116 ( V_125 < 0 && ! V_284 ) ) {
V_283 -> V_267 |= V_274 ;
V_283 -> V_275 |= V_276 ;
F_112 ( V_14 ) ;
}
}
void F_121 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_182 ;
V_182 = F_2 ( V_22 + V_163 ) ;
F_3 ( V_182 , V_22 + V_163 ) ;
F_115 ( V_14 , V_22 , V_182 ) ;
}
T_9 F_122 ( int V_297 , void * V_298 )
{
struct V_13 * V_14 = V_298 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
unsigned long V_28 ;
T_2 V_182 ;
F_14 ( & V_14 -> V_17 -> V_30 , V_28 ) ;
V_182 = V_93 -> V_299 ;
if ( V_182 )
V_93 -> V_299 = 0 ;
F_15 ( & V_14 -> V_17 -> V_30 , V_28 ) ;
F_123 ( V_14 -> V_30 ) ;
F_115 ( V_14 , V_22 , V_182 ) ;
F_124 ( V_14 -> V_30 ) ;
return V_300 ;
}
void F_125 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_182 ;
V_182 = F_2 ( V_22 + V_163 ) ;
F_3 ( V_182 , V_22 + V_163 ) ;
V_93 -> V_299 |= V_182 ;
}
T_9 F_126 ( int V_297 , void * V_298 )
{
struct V_13 * V_301 = V_298 ;
struct V_92 * V_93 = V_301 -> V_18 ;
struct V_73 * V_17 = V_301 -> V_17 ;
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
unsigned int V_2 ;
T_2 V_251 , V_302 ;
F_60 ( L_31 ) ;
F_127 ( & V_17 -> V_30 ) ;
V_251 = F_2 ( V_1 + V_164 ) ;
if ( ! V_251 ) {
T_2 V_182 = V_93 -> V_299 ;
F_128 ( & V_17 -> V_30 ) ;
F_60 ( L_50 ) ;
return V_182 ? V_303 : V_304 ;
}
V_302 = V_251 & V_16 -> V_53 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_165 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_302 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_166 [ V_2 ] ;
if ( V_14 ) {
F_125 ( V_14 ) ;
F_60 ( L_51 , V_2 ) ;
} else {
F_60 ( L_52 , V_2 ) ;
if ( F_129 () )
F_22 ( V_17 -> V_7 ,
L_53 , V_2 ) ;
}
}
F_3 ( V_251 , V_1 + V_164 ) ;
F_128 ( & V_17 -> V_30 ) ;
F_60 ( L_50 ) ;
return V_303 ;
}
T_9 F_130 ( int V_297 , void * V_298 )
{
struct V_73 * V_17 = V_298 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_305 = 0 ;
void T_1 * V_1 ;
T_2 V_251 , V_302 ;
F_60 ( L_31 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_251 = F_2 ( V_1 + V_164 ) ;
if ( ! V_251 )
return V_304 ;
V_302 = V_251 & V_16 -> V_53 ;
F_127 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_165 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_302 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_166 [ V_2 ] ;
if ( V_14 ) {
F_121 ( V_14 ) ;
F_60 ( L_51 , V_2 ) ;
} else {
F_60 ( L_52 , V_2 ) ;
if ( F_129 () )
F_22 ( V_17 -> V_7 ,
L_53 , V_2 ) ;
}
V_305 = 1 ;
}
F_3 ( V_251 , V_1 + V_164 ) ;
F_128 ( & V_17 -> V_30 ) ;
F_60 ( L_50 ) ;
return F_131 ( V_305 ) ;
}
static unsigned int F_132 ( struct V_224 * V_225 )
{
struct V_13 * V_14 = V_225 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_93 -> V_295 = V_225 -> V_7 -> V_87 ;
if ( V_225 -> V_171 . V_237 == V_306 )
F_3 ( 1 << V_225 -> V_177 , V_22 + V_83 ) ;
if ( V_93 -> V_235 && V_93 -> V_307 != V_225 -> V_7 -> V_87 -> V_128 ) {
T_2 V_247 = F_2 ( V_22 + V_248 ) ;
V_247 &= ~ ( V_308 | V_250 ) ;
V_247 |= V_225 -> V_7 -> V_87 -> V_128 << V_309 ;
F_3 ( V_247 , V_22 + V_248 ) ;
V_93 -> V_307 = V_225 -> V_7 -> V_87 -> V_128 ;
}
F_3 ( 1 << V_225 -> V_177 , V_22 + V_198 ) ;
F_46 ( V_225 -> V_7 -> V_87 ) ;
return 0 ;
}
static bool F_133 ( struct V_224 * V_225 )
{
struct V_92 * V_93 = V_225 -> V_14 -> V_18 ;
T_6 * V_217 = V_93 -> V_217 ;
if ( V_93 -> V_235 )
V_217 += V_225 -> V_7 -> V_87 -> V_128 * V_310 ;
if ( V_225 -> V_171 . V_237 == V_311 && V_225 -> V_312 == V_313 &&
! ( V_225 -> V_28 & V_314 ) ) {
F_134 ( V_217 + V_315 , & V_225 -> V_316 ) ;
V_225 -> V_316 . V_220 = ( V_217 + V_315 ) [ 15 ] ;
} else
F_134 ( V_217 + V_218 , & V_225 -> V_316 ) ;
return true ;
}
static void F_135 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
F_3 ( 0 , V_22 + V_113 ) ;
}
static void F_136 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_3 = F_2 ( V_22 + V_163 ) ;
F_3 ( V_3 , V_22 + V_163 ) ;
F_3 ( 1 << V_14 -> V_145 , V_1 + V_164 ) ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_137 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_285 & V_317 ) ) {
F_30 ( V_14 ) ;
F_29 ( V_14 ) ;
}
F_138 ( V_14 ) ;
if ( ! F_139 ( V_14 -> V_87 . V_6 ) )
F_30 ( V_14 ) ;
}
static void F_140 ( struct V_224 * V_225 )
{
struct V_13 * V_14 = V_225 -> V_14 ;
if ( V_225 -> V_28 & V_314 )
F_69 ( V_14 ) ;
}
static void F_38 ( struct V_13 * V_14 , bool V_318 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_158 * V_7 = V_14 -> V_87 . V_6 ;
T_2 V_319 , V_320 , V_321 , V_322 , V_323 ;
int V_125 ;
unsigned int V_267 ;
V_319 = F_2 ( V_22 + V_324 ) ;
if ( ! ( V_319 & V_325 ) ) {
F_45 ( V_14 -> V_17 -> V_7 , L_54 ) ;
return;
}
if ( ! V_318 ) {
if ( V_319 & V_326 ) {
F_3 ( V_319 & ~ V_326 ,
V_22 + V_324 ) ;
V_267 = F_141 ( V_7 ,
V_327 ,
V_328 ) ;
if ( V_267 && V_267 != V_268 )
F_142 ( V_7 , L_55 ) ;
}
return;
}
if ( V_319 & V_326 )
return;
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
return;
V_320 = ( V_319 & V_329 ) >> V_330 ;
V_321 = V_331 / ( V_320 + 1 ) ;
if ( V_321 > 0x3ff )
V_321 = 0x3ff ;
if ( V_7 -> V_332 [ V_333 ] &
V_334 ) {
V_322 = V_7 -> V_332 [ V_335 ] &
V_336 ;
if ( ! V_322 )
V_322 = 10 ;
V_323 = V_7 -> V_332 [ V_337 ] ;
if ( ! V_323 )
V_323 = 20 ;
} else {
V_322 = 10 ;
V_323 = 20 ;
}
V_319 |= ( ( V_321 << V_338 ) |
( V_322 << V_339 ) |
( V_323 << V_340 ) |
V_326 ) ;
F_3 ( V_319 , V_22 + V_324 ) ;
F_29 ( V_14 ) ;
V_267 = F_141 ( V_7 ,
V_341 ,
V_328 ) ;
if ( V_267 && V_267 != V_268 )
F_142 ( V_7 , L_56 ) ;
}
static void F_143 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_247 ;
int V_125 ;
if ( ! V_93 -> V_342 )
return;
V_247 = F_2 ( V_22 + V_248 ) ;
if ( V_247 & V_343 ) {
V_93 -> V_235 = true ;
V_93 -> V_307 = - 1 ;
return;
}
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
return;
F_3 ( V_247 | V_343 , V_22 + V_248 ) ;
V_247 = F_2 ( V_22 + V_248 ) ;
if ( V_247 & V_343 ) {
F_21 ( V_14 -> V_17 -> V_7 , L_57 ) ;
V_93 -> V_235 = true ;
V_93 -> V_307 = - 1 ;
} else
F_45 ( V_14 -> V_17 -> V_7 , L_58 ) ;
F_29 ( V_14 ) ;
}
static void F_144 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_247 ;
int V_125 ;
if ( ! V_93 -> V_342 )
return;
V_247 = F_2 ( V_22 + V_248 ) ;
if ( ( V_247 & V_343 ) == 0 ) {
V_93 -> V_235 = false ;
return;
}
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
return;
F_3 ( V_247 & ~ V_343 , V_22 + V_248 ) ;
V_247 = F_2 ( V_22 + V_248 ) ;
if ( V_247 & V_343 )
F_45 ( V_14 -> V_17 -> V_7 , L_59 ) ;
else {
F_21 ( V_14 -> V_17 -> V_7 , L_60 ) ;
V_93 -> V_235 = false ;
}
F_29 ( V_14 ) ;
}
static void F_145 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 |= V_344 ;
F_3 ( V_102 , V_22 + V_23 ) ;
F_143 ( V_14 ) ;
V_93 -> V_111 |= V_212 ;
if ( ! ( V_14 -> V_285 & V_317 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_146 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
F_144 ( V_14 ) ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 &= ~ V_344 ;
F_3 ( V_102 , V_22 + V_23 ) ;
V_93 -> V_111 &= ~ V_212 ;
if ( ! ( V_14 -> V_285 & V_317 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
int F_147 ( struct V_13 * V_14 )
{
F_34 ( V_14 ) ;
F_40 ( V_14 ) ;
if ( F_70 ( V_14 ) )
F_145 ( V_14 ) ;
else
F_146 ( V_14 ) ;
return 0 ;
}
static int F_148 ( struct V_13 * V_14 , T_10 V_345 )
{
const char * V_134 = NULL ;
int V_125 ;
V_125 = F_43 ( V_14 , & V_134 ) ;
if ( V_125 == 0 )
F_39 ( V_14 ) ;
else {
F_149 ( V_14 , L_26 , V_134 , V_125 ) ;
F_112 ( V_14 ) ;
}
return V_125 ;
}
static int F_150 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_92 * V_93 ;
void * V_346 ;
T_5 V_347 ;
T_4 V_348 , V_349 ;
V_93 = F_151 ( V_7 , sizeof( * V_93 ) , V_350 ) ;
if ( ! V_93 )
return - V_351 ;
if ( V_14 -> V_17 -> V_165 > 1 ) {
V_93 -> V_352 = F_151 ( V_7 , 8 , V_350 ) ;
if ( ! V_93 -> V_352 ) {
F_152 ( V_7 , V_93 ) ;
return - V_351 ;
}
snprintf ( V_93 -> V_352 , 8 ,
L_61 , F_153 ( V_7 ) , V_14 -> V_145 ) ;
}
if ( ( V_16 -> V_19 & V_69 ) && F_154 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 = F_2 ( V_22 + V_23 ) ;
if ( V_102 & V_353 )
V_93 -> V_342 = true ;
else if ( V_16 -> V_28 & V_70 ) {
F_21 ( V_7 , L_62 ,
V_14 -> V_145 ) ;
V_93 -> V_342 = true ;
} else
F_22 ( V_7 , L_63 ,
V_14 -> V_145 ) ;
}
if ( V_93 -> V_342 ) {
V_348 = V_354 ;
V_349 = V_310 * 16 ;
} else {
V_348 = V_355 ;
V_349 = V_310 ;
}
V_346 = F_155 ( V_7 , V_348 , & V_347 , V_350 ) ;
if ( ! V_346 )
return - V_351 ;
memset ( V_346 , 0 , V_348 ) ;
V_93 -> V_181 = V_346 ;
V_93 -> V_94 = V_347 ;
V_346 += V_356 ;
V_347 += V_356 ;
V_93 -> V_217 = V_346 ;
V_93 -> V_97 = V_347 ;
V_346 += V_349 ;
V_347 += V_349 ;
V_93 -> V_197 = V_346 ;
V_93 -> V_179 = V_347 ;
V_93 -> V_111 = V_357 ;
if ( ( V_16 -> V_28 & V_358 ) ) {
F_156 ( & V_93 -> V_30 ) ;
V_14 -> V_30 = & V_93 -> V_30 ;
}
V_14 -> V_18 = V_93 ;
return F_147 ( V_14 ) ;
}
static void F_157 ( struct V_13 * V_14 )
{
const char * V_134 = NULL ;
int V_125 ;
V_125 = F_43 ( V_14 , & V_134 ) ;
if ( V_125 )
F_17 ( V_14 , L_26 , V_134 , V_125 ) ;
}
void F_158 ( struct V_73 * V_17 , const char * V_359 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_52 , V_19 , V_20 , V_360 , V_361 ;
const char * V_362 ;
V_52 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_360 = V_16 -> V_53 ;
V_361 = ( V_19 >> 20 ) & 0xf ;
if ( V_361 == 1 )
V_362 = L_64 ;
else if ( V_361 == 2 )
V_362 = L_65 ;
else if ( V_361 == 3 )
V_362 = L_66 ;
else
V_362 = L_67 ;
F_21 ( V_17 -> V_7 ,
L_68
L_69
,
( V_52 >> 24 ) & 0xff ,
( V_52 >> 16 ) & 0xff ,
( V_52 >> 8 ) & 0xff ,
V_52 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_362 ,
V_360 ,
V_359 ) ;
F_21 ( V_17 -> V_7 ,
L_70
L_71
L_71
L_71
L_72
,
V_19 & V_60 ? L_73 : L_6 ,
V_19 & V_62 ? L_74 : L_6 ,
V_19 & V_67 ? L_75 : L_6 ,
V_19 & V_363 ? L_76 : L_6 ,
V_19 & V_104 ? L_77 : L_6 ,
V_19 & V_114 ? L_78 : L_6 ,
V_19 & V_364 ? L_5 : L_6 ,
V_19 & V_190 ? L_79 : L_6 ,
V_19 & V_365 ? L_80 : L_6 ,
V_19 & V_65 ? L_81 : L_6 ,
V_19 & V_69 ? L_82 : L_6 ,
V_19 & V_366 ? L_83 : L_6 ,
V_19 & V_367 ? L_84 : L_6 ,
V_19 & V_368 ? L_85 : L_6 ,
V_19 & V_369 ? L_86 : L_6 ,
V_19 & V_370 ? L_87 : L_6 ,
V_19 & V_371 ? L_88 : L_6 ,
V_20 & V_372 ? L_89 : L_6 ,
V_20 & V_120 ? L_90 : L_6 ,
V_20 & V_119 ? L_91 : L_6 ,
V_20 & V_373 ? L_92 : L_6 ,
V_20 & V_374 ? L_93 : L_6 ,
V_20 & V_375 ? L_94 : L_6
) ;
}
void F_159 ( struct V_15 * V_16 ,
struct V_376 * V_377 )
{
T_6 V_378 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_379 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_380 || ! ( V_16 -> V_19 & V_370 ) )
return;
V_378 = ( V_26 & V_381 ) >> 16 ;
if ( V_378 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_378 ;
V_377 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_382 ) )
V_377 -> V_28 |= V_133 ;
}
}
