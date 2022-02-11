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
V_125 = F_42 ( V_14 ,
V_124 -> V_130 ,
4 ) ;
if ( V_125 == - V_45 )
F_37 ( V_14 , 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_131 )
F_41 (link, ap, EDGE)
F_43 ( V_87 ) ;
}
static int F_44 ( struct V_13 * V_14 , const char * * V_132 )
{
int V_125 ;
V_125 = F_30 ( V_14 ) ;
if ( V_125 ) {
* V_132 = L_20 ;
return V_125 ;
}
V_125 = F_33 ( V_14 ) ;
if ( V_125 ) {
* V_132 = L_21 ;
return V_125 ;
}
return 0 ;
}
int F_45 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_133 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_134 ) == 0 ) {
F_3 ( V_3 | V_134 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_31 ( NULL , V_1 + V_4 , V_134 ,
V_134 , 10 , 1000 ) ;
if ( V_3 & V_134 ) {
F_46 ( V_17 -> V_7 , L_22 ,
V_3 ) ;
return - V_91 ;
}
F_1 ( V_1 ) ;
F_24 ( V_17 ) ;
} else
F_21 ( V_17 -> V_7 , L_23 ) ;
return 0 ;
}
static void F_47 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
if ( ! ( V_87 -> V_28 & V_135 ) )
return;
V_124 -> V_136 ++ ;
if ( ! F_48 ( & V_124 -> V_137 ) )
F_49 ( & V_124 -> V_137 , V_138 + F_50 ( 10 ) ) ;
}
static void F_51 ( unsigned long V_139 )
{
struct V_86 * V_87 = (struct V_86 * ) V_139 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
unsigned long V_140 = V_124 -> V_130 ;
T_2 V_141 ;
unsigned long V_28 ;
V_140 &= V_142 ;
V_140 |= V_14 -> V_143 | ( V_87 -> V_128 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_124 -> V_144 != V_124 -> V_136 ) {
V_124 -> V_144 = V_124 -> V_136 ;
V_141 = V_140 & V_145 ;
if ( V_141 )
V_141 = 0 ;
else
V_141 = 1 ;
V_140 &= ~ V_146 ;
V_140 |= ( V_141 << 16 ) ;
F_49 ( & V_124 -> V_137 , V_138 + F_50 ( 100 ) ) ;
} else {
V_140 &= ~ V_146 ;
if ( V_124 -> V_147 == V_148 )
V_140 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
F_42 ( V_14 , V_140 , 4 ) ;
}
static void F_43 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
V_124 -> V_144 = V_124 -> V_136 = 0 ;
F_52 ( & V_124 -> V_137 , F_51 , ( unsigned long ) V_87 ) ;
if ( V_124 -> V_147 )
V_87 -> V_28 |= V_135 ;
}
int F_53 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_44 ) || ( V_26 & V_149 ) )
return - V_36 ;
F_3 ( V_26 | V_149 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_13 * V_14 , T_2 V_150 ,
T_3 V_42 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_151 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_128 ;
struct V_123 * V_124 ;
V_128 = ( V_150 & V_152 ) >> 8 ;
if ( V_128 < V_153 )
V_124 = & V_93 -> V_127 [ V_128 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
if ( V_16 -> V_34 & V_154 ) {
V_151 [ 0 ] |= ( 4 << 8 ) ;
V_151 [ 1 ] = ( ( V_150 & ~ V_155 ) | V_14 -> V_143 ) ;
F_3 ( V_151 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_151 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
}
V_124 -> V_130 = V_150 ;
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
V_125 += sprintf ( V_10 , L_24 , V_124 -> V_130 ) ;
}
return V_125 ;
}
static T_3 F_55 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_42 )
{
int V_150 ;
int V_128 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 ;
V_150 = F_56 ( V_10 , NULL , 0 ) ;
V_128 = ( V_150 & V_152 ) >> 8 ;
if ( V_128 < V_153 )
V_124 = & V_93 -> V_127 [ V_128 ] ;
else
return - V_36 ;
if ( V_124 -> V_147 )
V_150 &= ~ V_146 ;
return F_42 ( V_14 , V_150 , V_42 ) ;
}
static T_3 F_57 ( struct V_156 * V_7 , enum V_157 V_88 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
T_2 V_158 = V_124 -> V_130 ;
if ( V_88 == V_159 ) {
V_87 -> V_28 &= ~ ( V_135 ) ;
V_158 &= V_160 ;
V_158 |= ( V_14 -> V_143 | ( V_87 -> V_128 << 8 ) ) ;
F_42 ( V_14 , V_158 , 4 ) ;
} else {
V_87 -> V_28 |= V_135 ;
if ( V_88 == V_148 ) {
V_158 &= V_160 ;
V_158 |= ( V_14 -> V_143 | ( V_87 -> V_128 << 8 ) ) ;
V_158 |= V_145 ;
F_42 ( V_14 , V_158 , 4 ) ;
}
}
V_124 -> V_147 = V_88 ;
return 0 ;
}
static T_3 F_58 ( struct V_156 * V_7 , char * V_10 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_123 * V_124 = & V_93 -> V_127 [ V_87 -> V_128 ] ;
return sprintf ( V_10 , L_25 , V_124 -> V_147 ) ;
}
static void F_59 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_143 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_132 = NULL ;
int V_125 ;
T_2 V_3 ;
V_125 = F_44 ( V_14 , & V_132 ) ;
if ( V_125 )
F_22 ( V_7 , L_26 , V_132 , V_125 ) ;
V_3 = F_2 ( V_22 + V_81 ) ;
F_60 ( L_27 , V_3 ) ;
F_3 ( V_3 , V_22 + V_81 ) ;
V_3 = F_2 ( V_22 + V_161 ) ;
F_60 ( L_28 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_161 ) ;
F_3 ( 1 << V_143 , V_1 + V_162 ) ;
}
void F_61 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_163 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_164 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_62 ( V_14 ) )
continue;
F_59 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_60 ( L_29 , V_3 ) ;
F_3 ( V_3 | V_165 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_60 ( L_29 , V_3 ) ;
}
static void F_63 ( struct V_156 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_87 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_166 ) {
V_7 -> V_167 = 255 ;
F_64 ( V_7 ,
L_30 ) ;
}
}
unsigned int F_65 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_168 V_169 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_170 ) ;
V_169 . V_171 = ( V_3 >> 24 ) & 0xff ;
V_169 . V_172 = ( V_3 >> 16 ) & 0xff ;
V_169 . V_173 = ( V_3 >> 8 ) & 0xff ;
V_169 . V_174 = ( V_3 ) & 0xff ;
return F_66 ( & V_169 ) ;
}
void F_67 ( struct V_92 * V_93 , unsigned int V_175 ,
T_2 V_176 )
{
T_5 V_177 ;
V_177 = V_93 -> V_177 + V_175 * V_178 ;
V_93 -> V_179 [ V_175 ] . V_176 = F_68 ( V_176 ) ;
V_93 -> V_179 [ V_175 ] . V_180 = 0 ;
V_93 -> V_179 [ V_175 ] . V_181 = F_68 ( V_177 & 0xffffffff ) ;
V_93 -> V_179 [ V_175 ] . V_182 = F_68 ( ( V_177 >> 16 ) >> 16 ) ;
}
int F_69 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_180 = F_2 ( V_22 + V_183 ) & 0xFF ;
T_2 V_3 ;
int V_184 , V_125 ;
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
goto V_185;
V_184 = V_180 & ( V_186 | V_187 ) ;
if ( ! V_184 && ! F_70 ( V_14 ) ) {
V_125 = 0 ;
goto V_185;
}
if ( ! ( V_16 -> V_19 & V_188 ) ) {
V_125 = - V_189 ;
goto V_185;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_190 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_125 = 0 ;
V_3 = F_31 ( V_14 , V_22 + V_23 ,
V_190 , V_190 , 1 , 500 ) ;
if ( V_3 & V_190 )
V_125 = - V_91 ;
V_185:
F_29 ( V_14 ) ;
return V_125 ;
}
static int F_71 ( struct V_13 * V_14 , int V_128 ,
struct V_168 * V_169 , int V_191 , T_7 V_28 ,
unsigned long V_192 )
{
const T_2 V_193 = 5 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_194 = V_93 -> V_195 ;
T_2 V_3 ;
F_72 ( V_169 , V_128 , V_191 , V_194 ) ;
F_67 ( V_93 , 0 , V_193 | V_28 | ( V_128 << 12 ) ) ;
F_3 ( 1 , V_22 + V_196 ) ;
if ( V_192 ) {
V_3 = F_31 ( V_14 , V_22 + V_196 ,
0x1 , 0x1 , 1 , V_192 ) ;
if ( V_3 & 0x1 ) {
F_69 ( V_14 ) ;
return - V_45 ;
}
} else
F_2 ( V_22 + V_196 ) ;
return 0 ;
}
int F_73 ( struct V_86 * V_87 , unsigned int * V_197 ,
int V_128 , unsigned long V_198 ,
int (* F_74)( struct V_86 * V_87 ) )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
const char * V_199 = NULL ;
unsigned long V_200 , V_201 ;
struct V_168 V_169 ;
int V_125 ;
F_75 ( L_31 ) ;
V_125 = F_69 ( V_14 ) ;
if ( V_125 && V_125 != - V_189 )
F_76 ( V_87 , L_32 , V_125 ) ;
F_77 ( V_87 -> V_6 , & V_169 ) ;
V_201 = 0 ;
V_200 = V_138 ;
if ( F_78 ( V_198 , V_200 ) )
V_201 = F_79 ( V_198 - V_200 ) ;
V_169 . V_202 |= V_203 ;
if ( F_71 ( V_14 , V_128 , & V_169 , 0 ,
V_204 | V_205 , V_201 ) ) {
V_125 = - V_91 ;
V_199 = L_33 ;
goto V_206;
}
F_37 ( V_14 , 1 ) ;
V_169 . V_202 &= ~ V_203 ;
F_71 ( V_14 , V_128 , & V_169 , 0 , 0 , 0 ) ;
V_125 = F_80 ( V_87 , V_198 , F_74 ) ;
if ( V_125 == - V_45 && V_16 -> V_28 & V_207 ) {
F_81 ( V_87 , L_34 ) ;
* V_197 = V_208 ;
} else if ( V_125 ) {
V_199 = L_35 ;
goto V_206;
} else
* V_197 = F_65 ( V_14 ) ;
F_75 ( L_36 , * V_197 ) ;
return 0 ;
V_206:
F_82 ( V_87 , L_37 , V_199 ) ;
return V_125 ;
}
int F_83 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_180 = F_2 ( V_22 + V_183 ) & 0xFF ;
return F_84 ( V_180 ) ;
}
static int F_85 ( struct V_86 * V_87 , unsigned int * V_197 ,
unsigned long V_198 )
{
int V_128 = F_86 ( V_87 ) ;
F_75 ( L_31 ) ;
return F_73 ( V_87 , V_197 , V_128 , V_198 , F_83 ) ;
}
static int F_87 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_180 = F_2 ( V_22 + V_183 ) & 0xFF ;
T_2 V_209 = F_2 ( V_22 + V_161 ) ;
if ( V_209 & V_210 )
return - V_91 ;
return F_84 ( V_180 ) ;
}
int F_88 ( struct V_86 * V_87 , unsigned int * V_197 ,
unsigned long V_198 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
int V_128 = F_86 ( V_87 ) ;
int V_125 ;
T_2 V_211 ;
F_75 ( L_31 ) ;
V_125 = F_73 ( V_87 , V_197 , V_128 , V_198 ,
F_87 ) ;
if ( V_125 == - V_91 ) {
V_211 = F_2 ( V_22 + V_161 ) ;
if ( V_211 & V_210 ) {
F_76 ( V_87 ,
L_38
L_39 ) ;
V_125 = F_73 ( V_87 , V_197 , 0 , V_198 ,
F_83 ) ;
}
}
return V_125 ;
}
static int F_89 ( struct V_86 * V_87 , unsigned int * V_197 ,
unsigned long V_198 )
{
const unsigned long * V_212 = F_90 ( & V_87 -> V_213 ) ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_6 * V_214 = V_93 -> V_215 + V_216 ;
struct V_168 V_169 ;
bool V_217 ;
int V_125 ;
F_75 ( L_31 ) ;
F_30 ( V_14 ) ;
F_77 ( V_87 -> V_6 , & V_169 ) ;
V_169 . V_218 = 0x80 ;
F_72 ( & V_169 , 0 , 0 , V_214 ) ;
V_125 = F_91 ( V_87 , V_212 , V_198 , & V_217 ,
F_83 ) ;
F_29 ( V_14 ) ;
if ( V_217 )
* V_197 = F_65 ( V_14 ) ;
F_75 ( L_40 , V_125 , * V_197 ) ;
return V_125 ;
}
static void F_92 ( struct V_86 * V_87 , unsigned int * V_197 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_219 , V_3 ;
F_93 ( V_87 , V_197 ) ;
V_219 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_197 == V_220 )
V_219 |= V_221 ;
else
V_219 &= ~ V_221 ;
if ( V_219 != V_3 ) {
F_3 ( V_219 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_94 ( struct V_222 * V_223 , void * V_195 )
{
struct V_224 * V_225 ;
struct V_226 * V_226 = V_195 + V_227 ;
unsigned int V_228 ;
F_60 ( L_31 ) ;
F_95 (qc->sg, sg, qc->n_elem, si) {
T_5 V_229 = F_96 ( V_225 ) ;
T_2 V_230 = F_97 ( V_225 ) ;
V_226 [ V_228 ] . V_229 = F_68 ( V_229 & 0xffffffff ) ;
V_226 [ V_228 ] . V_231 = F_68 ( ( V_229 >> 16 ) >> 16 ) ;
V_226 [ V_228 ] . V_232 = F_68 ( V_230 - 1 ) ;
}
return V_228 ;
}
static int F_98 ( struct V_222 * V_223 )
{
struct V_13 * V_14 = V_223 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
if ( ! F_70 ( V_14 ) || V_93 -> V_233 )
return F_99 ( V_223 ) ;
else
return F_100 ( V_223 ) ;
}
static void F_101 ( struct V_222 * V_223 )
{
struct V_13 * V_14 = V_223 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
int V_234 = F_102 ( V_223 -> V_169 . V_235 ) ;
void * V_195 ;
T_2 V_176 ;
const T_2 V_193 = 5 ;
unsigned int V_236 ;
V_195 = V_93 -> V_195 + V_223 -> V_175 * V_178 ;
F_72 ( & V_223 -> V_169 , V_223 -> V_7 -> V_87 -> V_128 , 1 , V_195 ) ;
if ( V_234 ) {
memset ( V_195 + V_237 , 0 , 32 ) ;
memcpy ( V_195 + V_237 , V_223 -> V_238 , V_223 -> V_7 -> V_239 ) ;
}
V_236 = 0 ;
if ( V_223 -> V_28 & V_240 )
V_236 = F_94 ( V_223 , V_195 ) ;
V_176 = V_193 | V_236 << 16 | ( V_223 -> V_7 -> V_87 -> V_128 << 12 ) ;
if ( V_223 -> V_169 . V_28 & V_241 )
V_176 |= V_242 ;
if ( V_234 )
V_176 |= V_243 | V_244 ;
F_67 ( V_93 , V_223 -> V_175 , V_176 ) ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_245 = F_2 ( V_22 + V_246 ) ;
int V_247 = 3 ;
F_75 ( L_31 ) ;
F_104 ( ! V_93 -> V_233 ) ;
F_3 ( V_245 | V_248 , V_22 + V_246 ) ;
V_245 = F_2 ( V_22 + V_246 ) ;
while ( ( V_245 & V_248 ) && V_247 -- ) {
F_105 ( 1 ) ;
V_245 = F_2 ( V_22 + V_246 ) ;
}
if ( V_245 & V_248 )
F_46 ( V_14 -> V_17 -> V_7 , L_41 ) ;
}
static void F_106 ( struct V_13 * V_14 , T_2 V_249 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_250 * V_251 = & V_14 -> V_87 . V_252 ;
struct V_86 * V_87 = NULL ;
struct V_222 * V_253 ;
struct V_250 * V_254 ;
bool V_255 = false ;
T_2 V_256 ;
if ( V_93 -> V_233 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_245 = F_2 ( V_22 + V_246 ) ;
int V_128 = V_245 >> V_257 ;
if ( ( V_245 & V_258 ) && ( V_128 < V_14 -> V_259 ) &&
F_107 ( & V_14 -> V_260 [ V_128 ] ) ) {
V_87 = & V_14 -> V_260 [ V_128 ] ;
V_255 = true ;
}
} else
F_41 (link, ap, EDGE)
if ( F_108 ( V_87 ) )
break;
if ( ! V_87 )
V_87 = & V_14 -> V_87 ;
V_253 = F_109 ( V_14 , V_87 -> V_261 ) ;
V_254 = & V_87 -> V_252 ;
F_110 ( V_251 ) ;
F_111 ( V_251 , L_42 , V_249 ) ;
F_27 ( & V_14 -> V_87 , V_80 , & V_256 ) ;
F_28 ( & V_14 -> V_87 , V_80 , V_256 ) ;
V_251 -> V_256 |= V_256 ;
if ( V_16 -> V_28 & V_262 )
V_249 &= ~ V_263 ;
if ( V_249 & V_264 ) {
if ( V_253 )
V_253 -> V_265 |= V_266 ;
else
V_254 -> V_265 |= V_266 ;
if ( V_16 -> V_28 & V_267 )
V_251 -> V_256 &= ~ V_268 ;
}
if ( V_249 & V_269 ) {
T_2 * V_270 = ( T_2 * ) ( V_93 -> V_215 + V_271 ) ;
V_254 -> V_265 |= V_272 ;
V_254 -> V_273 |= V_274 ;
F_111 ( V_254 ,
L_43 ,
V_270 [ 0 ] , V_270 [ 1 ] , V_270 [ 2 ] , V_270 [ 3 ] ) ;
}
if ( F_70 ( V_14 ) && ( V_249 & V_210 ) ) {
V_254 -> V_265 |= V_272 ;
V_254 -> V_273 |= V_274 ;
F_111 ( V_254 , L_44 ) ;
}
if ( V_249 & ( V_275 | V_276 ) ) {
V_251 -> V_265 |= V_277 ;
V_251 -> V_273 |= V_274 ;
F_111 ( V_251 , L_45 ) ;
}
if ( V_249 & V_263 ) {
if ( V_255 )
V_254 -> V_265 |= V_266 ;
else {
V_251 -> V_265 |= V_278 ;
V_251 -> V_273 |= V_274 ;
}
F_111 ( V_251 , L_46 ) ;
}
if ( V_249 & ( V_279 | V_112 ) ) {
F_112 ( V_251 ) ;
F_111 ( V_251 , L_47 ,
V_249 & V_279 ?
L_48 : L_49 ) ;
}
if ( V_249 & V_280 )
F_113 ( V_14 ) ;
else if ( V_255 ) {
F_114 ( V_87 ) ;
F_103 ( V_14 ) ;
} else
F_115 ( V_14 ) ;
}
static void F_116 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_250 * V_281 = & V_14 -> V_87 . V_252 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_282 = ! ! ( V_14 -> V_283 & V_284 ) ;
T_2 V_180 , V_285 = 0 ;
int V_125 ;
V_180 = F_2 ( V_22 + V_161 ) ;
F_3 ( V_180 , V_22 + V_161 ) ;
if ( F_117 ( V_282 ) )
V_180 &= ~ V_210 ;
if ( V_14 -> V_87 . V_286 > V_110 ) {
V_180 &= ~ V_112 ;
F_28 ( & V_14 -> V_87 , V_80 , V_287 ) ;
}
if ( F_117 ( V_180 & V_288 ) ) {
F_106 ( V_14 , V_180 ) ;
return;
}
if ( V_180 & V_289 ) {
if ( V_16 -> V_19 & V_67 )
F_118 ( V_14 ) ;
else {
if ( V_93 -> V_233 )
F_119 ( 1 ) ;
else {
const T_8 * V_290 = V_93 -> V_215 + V_291 ;
T_2 V_292 = F_120 ( V_290 [ 0 ] ) ;
if ( V_292 & ( 1 << 15 ) )
F_118 ( V_14 ) ;
}
}
}
if ( V_93 -> V_233 ) {
if ( V_14 -> V_285 ) {
V_285 = F_2 ( V_22 + V_83 ) ;
V_285 |= F_2 ( V_22 + V_196 ) ;
}
} else {
if ( V_14 -> V_285 && V_93 -> V_293 -> V_294 )
V_285 = F_2 ( V_22 + V_83 ) ;
else
V_285 = F_2 ( V_22 + V_196 ) ;
}
V_125 = F_121 ( V_14 , V_285 ) ;
if ( F_117 ( V_125 < 0 && ! V_282 ) ) {
V_281 -> V_265 |= V_272 ;
V_281 -> V_273 |= V_274 ;
F_113 ( V_14 ) ;
}
}
T_9 F_122 ( int V_295 , void * V_296 )
{
struct V_73 * V_17 = V_296 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_297 = 0 ;
void T_1 * V_1 ;
T_2 V_249 , V_298 ;
F_60 ( L_31 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_249 = F_2 ( V_1 + V_162 ) ;
if ( ! V_249 )
return V_299 ;
V_298 = V_249 & V_16 -> V_53 ;
F_123 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_163 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_298 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_164 [ V_2 ] ;
if ( V_14 ) {
F_116 ( V_14 ) ;
F_60 ( L_50 , V_2 ) ;
} else {
F_60 ( L_51 , V_2 ) ;
if ( F_124 () )
F_22 ( V_17 -> V_7 ,
L_52 , V_2 ) ;
}
V_297 = 1 ;
}
F_3 ( V_249 , V_1 + V_162 ) ;
F_125 ( & V_17 -> V_30 ) ;
F_60 ( L_53 ) ;
return F_126 ( V_297 ) ;
}
static unsigned int F_127 ( struct V_222 * V_223 )
{
struct V_13 * V_14 = V_223 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_93 -> V_293 = V_223 -> V_7 -> V_87 ;
if ( V_223 -> V_169 . V_235 == V_300 )
F_3 ( 1 << V_223 -> V_175 , V_22 + V_83 ) ;
if ( V_93 -> V_233 && V_93 -> V_301 != V_223 -> V_7 -> V_87 -> V_128 ) {
T_2 V_245 = F_2 ( V_22 + V_246 ) ;
V_245 &= ~ ( V_302 | V_248 ) ;
V_245 |= V_223 -> V_7 -> V_87 -> V_128 << V_303 ;
F_3 ( V_245 , V_22 + V_246 ) ;
V_93 -> V_301 = V_223 -> V_7 -> V_87 -> V_128 ;
}
F_3 ( 1 << V_223 -> V_175 , V_22 + V_196 ) ;
F_47 ( V_223 -> V_7 -> V_87 ) ;
return 0 ;
}
static bool F_128 ( struct V_222 * V_223 )
{
struct V_92 * V_93 = V_223 -> V_14 -> V_18 ;
T_6 * V_215 = V_93 -> V_215 ;
if ( V_93 -> V_233 )
V_215 += V_223 -> V_7 -> V_87 -> V_128 * V_304 ;
if ( V_223 -> V_169 . V_235 == V_305 && V_223 -> V_306 == V_307 &&
! ( V_223 -> V_28 & V_308 ) ) {
F_129 ( V_215 + V_309 , & V_223 -> V_310 ) ;
V_223 -> V_310 . V_218 = ( V_215 + V_309 ) [ 15 ] ;
} else
F_129 ( V_215 + V_216 , & V_223 -> V_310 ) ;
return true ;
}
static void F_130 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
F_3 ( 0 , V_22 + V_113 ) ;
}
static void F_131 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_3 = F_2 ( V_22 + V_161 ) ;
F_3 ( V_3 , V_22 + V_161 ) ;
F_3 ( 1 << V_14 -> V_143 , V_1 + V_162 ) ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_132 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_283 & V_311 ) ) {
F_30 ( V_14 ) ;
F_29 ( V_14 ) ;
}
F_133 ( V_14 ) ;
if ( ! F_134 ( V_14 -> V_87 . V_6 ) )
F_30 ( V_14 ) ;
}
static void F_135 ( struct V_222 * V_223 )
{
struct V_13 * V_14 = V_223 -> V_14 ;
if ( V_223 -> V_28 & V_308 )
F_69 ( V_14 ) ;
}
static void F_38 ( struct V_13 * V_14 , bool V_312 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_156 * V_7 = V_14 -> V_87 . V_6 ;
T_2 V_313 , V_314 , V_315 , V_316 , V_317 ;
int V_125 ;
unsigned int V_265 ;
V_313 = F_2 ( V_22 + V_318 ) ;
if ( ! ( V_313 & V_319 ) ) {
F_46 ( V_14 -> V_17 -> V_7 , L_54 ) ;
return;
}
if ( ! V_312 ) {
if ( V_313 & V_320 ) {
F_3 ( V_313 & ~ V_320 ,
V_22 + V_318 ) ;
V_265 = F_136 ( V_7 ,
V_321 ,
V_322 ) ;
if ( V_265 && V_265 != V_266 )
F_137 ( V_7 , L_55 ) ;
}
return;
}
if ( V_313 & V_320 )
return;
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
return;
V_314 = ( V_313 & V_323 ) >> V_324 ;
V_315 = V_325 / ( V_314 + 1 ) ;
if ( V_315 > 0x3ff )
V_315 = 0x3ff ;
if ( V_7 -> V_326 [ V_327 ] &
V_328 ) {
V_316 = V_7 -> V_326 [ V_329 ] &
V_330 ;
if ( ! V_316 )
V_316 = 10 ;
V_317 = V_7 -> V_326 [ V_331 ] ;
if ( ! V_317 )
V_317 = 20 ;
} else {
V_316 = 10 ;
V_317 = 20 ;
}
V_313 |= ( ( V_315 << V_332 ) |
( V_316 << V_333 ) |
( V_317 << V_334 ) |
V_320 ) ;
F_3 ( V_313 , V_22 + V_318 ) ;
F_29 ( V_14 ) ;
V_265 = F_136 ( V_7 ,
V_335 ,
V_322 ) ;
if ( V_265 && V_265 != V_266 )
F_137 ( V_7 , L_56 ) ;
}
static void F_138 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_245 ;
int V_125 ;
if ( ! V_93 -> V_336 )
return;
V_245 = F_2 ( V_22 + V_246 ) ;
if ( V_245 & V_337 ) {
V_93 -> V_233 = true ;
V_93 -> V_301 = - 1 ;
return;
}
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
return;
F_3 ( V_245 | V_337 , V_22 + V_246 ) ;
V_245 = F_2 ( V_22 + V_246 ) ;
if ( V_245 & V_337 ) {
F_21 ( V_14 -> V_17 -> V_7 , L_57 ) ;
V_93 -> V_233 = true ;
V_93 -> V_301 = - 1 ;
} else
F_46 ( V_14 -> V_17 -> V_7 , L_58 ) ;
F_29 ( V_14 ) ;
}
static void F_139 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_245 ;
int V_125 ;
if ( ! V_93 -> V_336 )
return;
V_245 = F_2 ( V_22 + V_246 ) ;
if ( ( V_245 & V_337 ) == 0 ) {
V_93 -> V_233 = false ;
return;
}
V_125 = F_30 ( V_14 ) ;
if ( V_125 )
return;
F_3 ( V_245 & ~ V_337 , V_22 + V_246 ) ;
V_245 = F_2 ( V_22 + V_246 ) ;
if ( V_245 & V_337 )
F_46 ( V_14 -> V_17 -> V_7 , L_59 ) ;
else {
F_21 ( V_14 -> V_17 -> V_7 , L_60 ) ;
V_93 -> V_233 = false ;
}
F_29 ( V_14 ) ;
}
static void F_140 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 |= V_338 ;
F_3 ( V_102 , V_22 + V_23 ) ;
F_138 ( V_14 ) ;
V_93 -> V_111 |= V_210 ;
if ( ! ( V_14 -> V_283 & V_311 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_141 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
F_139 ( V_14 ) ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 &= ~ V_338 ;
F_3 ( V_102 , V_22 + V_23 ) ;
V_93 -> V_111 &= ~ V_210 ;
if ( ! ( V_14 -> V_283 & V_311 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
int F_142 ( struct V_13 * V_14 )
{
F_34 ( V_14 ) ;
F_40 ( V_14 ) ;
if ( F_70 ( V_14 ) )
F_140 ( V_14 ) ;
else
F_141 ( V_14 ) ;
return 0 ;
}
static int F_143 ( struct V_13 * V_14 , T_10 V_339 )
{
const char * V_132 = NULL ;
int V_125 ;
V_125 = F_44 ( V_14 , & V_132 ) ;
if ( V_125 == 0 )
F_39 ( V_14 ) ;
else {
F_144 ( V_14 , L_26 , V_132 , V_125 ) ;
F_113 ( V_14 ) ;
}
return V_125 ;
}
static int F_145 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_92 * V_93 ;
void * V_340 ;
T_5 V_341 ;
T_4 V_342 , V_343 ;
V_93 = F_146 ( V_7 , sizeof( * V_93 ) , V_344 ) ;
if ( ! V_93 )
return - V_345 ;
if ( ( V_16 -> V_19 & V_69 ) && F_147 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 = F_2 ( V_22 + V_23 ) ;
if ( V_102 & V_346 )
V_93 -> V_336 = true ;
else if ( V_16 -> V_28 & V_70 ) {
F_21 ( V_7 , L_61 ,
V_14 -> V_143 ) ;
V_93 -> V_336 = true ;
} else
F_22 ( V_7 , L_62 ,
V_14 -> V_143 ) ;
}
if ( V_93 -> V_336 ) {
V_342 = V_347 ;
V_343 = V_304 * 16 ;
} else {
V_342 = V_348 ;
V_343 = V_304 ;
}
V_340 = F_148 ( V_7 , V_342 , & V_341 , V_344 ) ;
if ( ! V_340 )
return - V_345 ;
memset ( V_340 , 0 , V_342 ) ;
V_93 -> V_179 = V_340 ;
V_93 -> V_94 = V_341 ;
V_340 += V_349 ;
V_341 += V_349 ;
V_93 -> V_215 = V_340 ;
V_93 -> V_97 = V_341 ;
V_340 += V_343 ;
V_341 += V_343 ;
V_93 -> V_195 = V_340 ;
V_93 -> V_177 = V_341 ;
V_93 -> V_111 = V_350 ;
V_14 -> V_18 = V_93 ;
return F_142 ( V_14 ) ;
}
static void F_149 ( struct V_13 * V_14 )
{
const char * V_132 = NULL ;
int V_125 ;
V_125 = F_44 ( V_14 , & V_132 ) ;
if ( V_125 )
F_17 ( V_14 , L_26 , V_132 , V_125 ) ;
}
void F_150 ( struct V_73 * V_17 , const char * V_351 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_52 , V_19 , V_20 , V_352 , V_353 ;
const char * V_354 ;
V_52 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_352 = V_16 -> V_53 ;
V_353 = ( V_19 >> 20 ) & 0xf ;
if ( V_353 == 1 )
V_354 = L_63 ;
else if ( V_353 == 2 )
V_354 = L_64 ;
else if ( V_353 == 3 )
V_354 = L_65 ;
else
V_354 = L_66 ;
F_21 ( V_17 -> V_7 ,
L_67
L_68
,
( V_52 >> 24 ) & 0xff ,
( V_52 >> 16 ) & 0xff ,
( V_52 >> 8 ) & 0xff ,
V_52 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_354 ,
V_352 ,
V_351 ) ;
F_21 ( V_17 -> V_7 ,
L_69
L_70
L_70
L_70
L_71
,
V_19 & V_60 ? L_72 : L_6 ,
V_19 & V_62 ? L_73 : L_6 ,
V_19 & V_67 ? L_74 : L_6 ,
V_19 & V_355 ? L_75 : L_6 ,
V_19 & V_104 ? L_76 : L_6 ,
V_19 & V_114 ? L_77 : L_6 ,
V_19 & V_356 ? L_5 : L_6 ,
V_19 & V_188 ? L_78 : L_6 ,
V_19 & V_357 ? L_79 : L_6 ,
V_19 & V_65 ? L_80 : L_6 ,
V_19 & V_69 ? L_81 : L_6 ,
V_19 & V_358 ? L_82 : L_6 ,
V_19 & V_359 ? L_83 : L_6 ,
V_19 & V_360 ? L_84 : L_6 ,
V_19 & V_361 ? L_85 : L_6 ,
V_19 & V_362 ? L_86 : L_6 ,
V_19 & V_363 ? L_87 : L_6 ,
V_20 & V_364 ? L_88 : L_6 ,
V_20 & V_120 ? L_89 : L_6 ,
V_20 & V_119 ? L_90 : L_6 ,
V_20 & V_365 ? L_91 : L_6 ,
V_20 & V_366 ? L_92 : L_6 ,
V_20 & V_367 ? L_93 : L_6
) ;
}
void F_151 ( struct V_15 * V_16 ,
struct V_368 * V_369 )
{
T_6 V_370 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_371 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_372 || ! ( V_16 -> V_19 & V_362 ) )
return;
V_370 = ( V_26 & V_373 ) >> 16 ;
if ( V_370 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_370 ;
V_369 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_374 ) )
V_369 -> V_28 |= V_131 ;
}
}
