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
F_17 ( V_14 , V_42 ,
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
const char * V_10 , T_4 V_43 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_24 = V_1 + V_16 -> V_25 ;
const unsigned char * V_44 = V_10 ;
T_2 V_26 , V_27 ;
unsigned long V_28 ;
int V_2 ;
if ( ! ( V_14 -> V_28 & V_32 ) ||
! ( V_16 -> V_34 & V_35 ) ||
V_43 % 4 || V_43 > V_16 -> V_40 )
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_45 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_46 ;
}
for ( V_2 = 0 ; V_2 < V_43 ; V_2 += 4 ) {
V_27 = V_44 [ V_2 ] | V_44 [ V_2 + 1 ] << 8 |
V_44 [ V_2 + 2 ] << 16 | V_44 [ V_2 + 3 ] << 24 ;
F_3 ( V_27 , V_24 + V_2 ) ;
}
F_3 ( V_26 | V_45 , V_1 + V_31 ) ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_43 ;
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
V_26 & V_47 ? L_5 : L_6 ,
V_26 & V_48 ? L_7 : L_6 ,
V_26 & V_49 ? L_8 : L_6 ,
V_26 & V_50 ? L_9 : L_6 ) ;
}
void F_20 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int V_51 ,
unsigned int V_52 )
{
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_19 , V_20 , V_53 , V_54 ;
int V_2 ;
F_1 ( V_1 ) ;
V_16 -> V_55 = V_19 = F_2 ( V_1 + V_56 ) ;
V_16 -> V_57 = V_54 = F_2 ( V_1 + V_58 ) ;
V_53 = F_2 ( V_1 + V_21 ) ;
if ( ( V_53 >> 16 ) > 1 ||
( ( V_53 >> 16 ) == 1 && ( V_53 & 0xFFFF ) >= 0x200 ) )
V_16 -> V_59 = V_20 = F_2 ( V_1 + V_60 ) ;
else
V_16 -> V_59 = V_20 = 0 ;
if ( ( V_19 & V_61 ) && ( V_16 -> V_28 & V_62 ) ) {
F_21 ( V_63 , V_7 ,
L_10 ) ;
V_19 &= ~ V_61 ;
}
if ( ( V_19 & V_64 ) && ( V_16 -> V_28 & V_65 ) ) {
F_21 ( V_63 , V_7 ,
L_11 ) ;
V_19 &= ~ V_64 ;
}
if ( ! ( V_19 & V_64 ) && ( V_16 -> V_28 & V_66 ) ) {
F_21 ( V_63 , V_7 ,
L_12 ) ;
V_19 |= V_64 ;
}
if ( ( V_19 & V_67 ) && ( V_16 -> V_28 & V_68 ) ) {
F_21 ( V_63 , V_7 ,
L_13 ) ;
V_19 &= ~ V_67 ;
}
if ( ( V_19 & V_69 ) && ( V_16 -> V_28 & V_70 ) ) {
F_21 ( V_63 , V_7 ,
L_14 ) ;
V_19 &= ~ V_69 ;
}
if ( ! ( V_19 & V_71 ) && ( V_16 -> V_28 & V_72 ) ) {
F_21 ( V_63 , V_7 ,
L_15 ) ;
V_19 |= V_71 ;
}
if ( V_51 && V_54 != V_51 ) {
F_21 ( V_63 , V_7 , L_16 ,
V_54 , V_51 ) ;
V_54 = V_51 ;
}
if ( V_52 ) {
F_21 ( V_42 , V_7 , L_17 ,
V_54 ,
V_54 & V_52 ) ;
V_54 &= V_52 ;
}
if ( V_54 ) {
int V_73 = 0 ;
for ( V_2 = 0 ; V_2 < V_74 ; V_2 ++ )
if ( V_54 & ( 1 << V_2 ) )
V_73 ++ ;
if ( V_73 > F_22 ( V_19 ) ) {
F_21 ( V_42 , V_7 ,
L_18
L_19 ,
V_54 , F_22 ( V_19 ) ) ;
V_54 = 0 ;
}
}
if ( ! V_54 ) {
V_54 = ( 1 << F_22 ( V_19 ) ) - 1 ;
F_21 ( V_42 , V_7 ,
L_20 , V_54 ) ;
V_16 -> V_57 = V_54 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_54 = V_54 ;
}
static void F_23 ( struct V_75 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_55 , V_1 + V_56 ) ;
if ( V_16 -> V_59 )
F_3 ( V_16 -> V_59 , V_1 + V_60 ) ;
F_3 ( V_16 -> V_57 , V_1 + V_58 ) ;
( void ) F_2 ( V_1 + V_58 ) ;
}
static unsigned F_24 ( struct V_13 * V_14 , unsigned int V_76 )
{
static const int V_77 [] = {
[ V_78 ] = V_79 ,
[ V_80 ] = V_81 ,
[ V_82 ] = V_83 ,
[ V_84 ] = V_85 ,
[ V_86 ] = V_87 ,
} ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( V_76 < F_25 ( V_77 ) &&
( V_76 != V_86 || ( V_16 -> V_19 & V_69 ) ) )
return V_77 [ V_76 ] ;
return 0 ;
}
static int F_26 ( struct V_88 * V_89 , unsigned int V_76 , T_2 * V_90 )
{
void T_1 * V_22 = F_12 ( V_89 -> V_14 ) ;
int V_77 = F_24 ( V_89 -> V_14 , V_76 ) ;
if ( V_77 ) {
* V_90 = F_2 ( V_22 + V_77 ) ;
return 0 ;
}
return - V_36 ;
}
static int F_27 ( struct V_88 * V_89 , unsigned int V_76 , T_2 V_90 )
{
void T_1 * V_22 = F_12 ( V_89 -> V_14 ) ;
int V_77 = F_24 ( V_89 -> V_14 , V_76 ) ;
if ( V_77 ) {
F_3 ( V_90 , V_22 + V_77 ) ;
return 0 ;
}
return - V_36 ;
}
void F_28 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_91 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
int F_29 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
if ( ( V_3 & ( V_91 | V_92 ) ) == 0 )
return 0 ;
V_3 &= ~ V_91 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_30 ( V_14 , V_22 + V_23 ,
V_92 , V_92 , 1 , 500 ) ;
if ( V_3 & V_92 )
return - V_93 ;
return 0 ;
}
static void F_31 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_94 * V_95 = V_14 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_61 )
F_3 ( ( V_95 -> V_96 >> 16 ) >> 16 ,
V_22 + V_97 ) ;
F_3 ( V_95 -> V_96 & 0xffffffff , V_22 + V_98 ) ;
if ( V_16 -> V_19 & V_61 )
F_3 ( ( V_95 -> V_99 >> 16 ) >> 16 ,
V_22 + V_100 ) ;
F_3 ( V_95 -> V_99 & 0xffffffff , V_22 + V_101 ) ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_102 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
static int F_32 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 &= ~ V_102 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_30 ( V_14 , V_22 + V_23 , V_103 ,
V_103 , 10 , 1000 ) ;
if ( V_3 & V_103 )
return - V_46 ;
return 0 ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_104 ;
V_104 = F_2 ( V_22 + V_23 ) & ~ V_105 ;
if ( V_16 -> V_19 & V_106 ) {
V_104 |= V_107 ;
F_3 ( V_104 , V_22 + V_23 ) ;
}
F_3 ( V_104 | V_108 , V_22 + V_23 ) ;
}
static int F_34 ( struct V_88 * V_89 , enum V_109 V_110 ,
unsigned int V_111 )
{
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_94 * V_95 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
if ( V_110 != V_112 ) {
V_95 -> V_113 &= ~ V_114 ;
F_3 ( V_95 -> V_113 , V_22 + V_115 ) ;
F_35 ( V_89 , V_110 , false ) ;
}
if ( V_16 -> V_19 & V_116 ) {
T_2 V_104 = F_2 ( V_22 + V_23 ) ;
if ( V_110 == V_112 || ! ( V_111 & V_117 ) ) {
V_104 &= ~ ( V_118 | V_119 ) ;
V_104 |= V_108 ;
F_3 ( V_104 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
F_36 ( V_14 , 10 ) ;
} else {
V_104 |= V_119 ;
if ( V_110 == V_120 )
V_104 |= V_118 ;
F_3 ( V_104 , V_22 + V_23 ) ;
}
}
if ( V_110 == V_112 ) {
F_35 ( V_89 , V_110 , false ) ;
V_95 -> V_113 |= V_114 ;
F_3 ( V_95 -> V_113 , V_22 + V_115 ) ;
}
return 0 ;
}
static void F_37 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_104 , V_121 ;
if ( ! ( V_16 -> V_19 & V_106 ) )
return;
V_121 = F_2 ( V_22 + V_81 ) ;
V_121 &= ~ 0xf ;
F_3 ( V_121 , V_22 + V_81 ) ;
V_104 = F_2 ( V_22 + V_23 ) & ~ V_105 ;
V_104 &= ~ V_107 ;
F_3 ( V_104 , V_22 + V_23 ) ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_88 * V_89 ;
struct V_122 * V_123 ;
T_3 V_124 ;
int V_2 ;
F_31 ( V_14 ) ;
F_28 ( V_14 ) ;
if ( V_14 -> V_28 & V_32 ) {
F_39 (link, ap, EDGE) {
V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
for ( V_2 = 0 ; V_2 < V_127 ; V_2 ++ ) {
V_124 = F_40 ( V_14 ,
V_123 -> V_128 ,
4 ) ;
if ( V_124 == - V_46 )
F_36 ( V_14 , 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_129 )
F_39 (link, ap, EDGE)
F_41 ( V_89 ) ;
}
static int F_42 ( struct V_13 * V_14 , const char * * V_130 )
{
int V_124 ;
V_124 = F_29 ( V_14 ) ;
if ( V_124 ) {
* V_130 = L_21 ;
return V_124 ;
}
V_124 = F_32 ( V_14 ) ;
if ( V_124 ) {
* V_130 = L_22 ;
return V_124 ;
}
return 0 ;
}
int F_43 ( struct V_75 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_131 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_132 ) == 0 ) {
F_3 ( V_3 | V_132 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_30 ( NULL , V_1 + V_4 , V_132 ,
V_132 , 10 , 1000 ) ;
if ( V_3 & V_132 ) {
F_21 ( V_133 , V_17 -> V_7 ,
L_23 , V_3 ) ;
return - V_93 ;
}
F_1 ( V_1 ) ;
F_23 ( V_17 ) ;
} else
F_21 ( V_63 , V_17 -> V_7 ,
L_24 ) ;
return 0 ;
}
static void F_44 ( struct V_88 * V_89 )
{
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_122 * V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
if ( ! ( V_89 -> V_28 & V_134 ) )
return;
V_123 -> V_135 ++ ;
if ( ! F_45 ( & V_123 -> V_136 ) )
F_46 ( & V_123 -> V_136 , V_137 + F_47 ( 10 ) ) ;
}
static void F_48 ( unsigned long V_138 )
{
struct V_88 * V_89 = (struct V_88 * ) V_138 ;
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_122 * V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
unsigned long V_139 = V_123 -> V_128 ;
T_2 V_140 ;
unsigned long V_28 ;
V_139 &= V_141 ;
V_139 |= V_14 -> V_142 | ( V_89 -> V_126 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_123 -> V_143 != V_123 -> V_135 ) {
V_123 -> V_143 = V_123 -> V_135 ;
V_140 = V_139 & V_144 ;
if ( V_140 )
V_140 = 0 ;
else
V_140 = 1 ;
V_139 &= ~ V_145 ;
V_139 |= ( V_140 << 16 ) ;
F_46 ( & V_123 -> V_136 , V_137 + F_47 ( 100 ) ) ;
} else {
V_139 &= ~ V_145 ;
if ( V_123 -> V_146 == V_147 )
V_139 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
F_40 ( V_14 , V_139 , 4 ) ;
}
static void F_41 ( struct V_88 * V_89 )
{
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_122 * V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
V_123 -> V_143 = V_123 -> V_135 = 0 ;
F_49 ( & V_123 -> V_136 , F_48 , ( unsigned long ) V_89 ) ;
if ( V_123 -> V_146 )
V_89 -> V_28 |= V_134 ;
}
int F_50 ( struct V_75 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_45 ) || ( V_26 & V_148 ) )
return - V_36 ;
F_3 ( V_26 | V_148 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_40 ( struct V_13 * V_14 , T_2 V_149 ,
T_3 V_43 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_94 * V_95 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_150 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_126 ;
struct V_122 * V_123 ;
V_126 = ( V_149 & V_151 ) >> 8 ;
if ( V_126 < V_152 )
V_123 = & V_95 -> V_125 [ V_126 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_45 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_46 ;
}
if ( V_16 -> V_34 & V_153 ) {
V_150 [ 0 ] |= ( 4 << 8 ) ;
V_150 [ 1 ] = ( ( V_149 & ~ V_154 ) | V_14 -> V_142 ) ;
F_3 ( V_150 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_150 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_45 , V_1 + V_31 ) ;
}
V_123 -> V_128 = V_149 ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_43 ;
}
static T_3 F_51 ( struct V_13 * V_14 , char * V_10 )
{
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_88 * V_89 ;
struct V_122 * V_123 ;
int V_124 = 0 ;
F_39 (link, ap, EDGE) {
V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
V_124 += sprintf ( V_10 , L_25 , V_123 -> V_128 ) ;
}
return V_124 ;
}
static T_3 F_52 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_43 )
{
int V_149 ;
int V_126 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_122 * V_123 ;
V_149 = F_53 ( V_10 , NULL , 0 ) ;
V_126 = ( V_149 & V_151 ) >> 8 ;
if ( V_126 < V_152 )
V_123 = & V_95 -> V_125 [ V_126 ] ;
else
return - V_36 ;
if ( V_123 -> V_146 )
V_149 &= ~ V_145 ;
return F_40 ( V_14 , V_149 , V_43 ) ;
}
static T_3 F_54 ( struct V_155 * V_7 , enum V_156 V_90 )
{
struct V_88 * V_89 = V_7 -> V_89 ;
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_122 * V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
T_2 V_157 = V_123 -> V_128 ;
if ( V_90 == V_158 ) {
V_89 -> V_28 &= ~ ( V_134 ) ;
V_157 &= V_159 ;
V_157 |= ( V_14 -> V_142 | ( V_89 -> V_126 << 8 ) ) ;
F_40 ( V_14 , V_157 , 4 ) ;
} else {
V_89 -> V_28 |= V_134 ;
if ( V_90 == V_147 ) {
V_157 &= V_159 ;
V_157 |= ( V_14 -> V_142 | ( V_89 -> V_126 << 8 ) ) ;
V_157 |= V_144 ;
F_40 ( V_14 , V_157 , 4 ) ;
}
}
V_123 -> V_146 = V_90 ;
return 0 ;
}
static T_3 F_55 ( struct V_155 * V_7 , char * V_10 )
{
struct V_88 * V_89 = V_7 -> V_89 ;
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_122 * V_123 = & V_95 -> V_125 [ V_89 -> V_126 ] ;
return sprintf ( V_10 , L_26 , V_123 -> V_146 ) ;
}
static void F_56 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_142 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_130 = NULL ;
int V_124 ;
T_2 V_3 ;
V_124 = F_42 ( V_14 , & V_130 ) ;
if ( V_124 )
F_57 ( V_7 , L_27 , V_130 , V_124 ) ;
V_3 = F_2 ( V_22 + V_83 ) ;
F_58 ( L_28 , V_3 ) ;
F_3 ( V_3 , V_22 + V_83 ) ;
V_3 = F_2 ( V_22 + V_160 ) ;
F_58 ( L_29 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_160 ) ;
F_3 ( 1 << V_142 , V_1 + V_161 ) ;
}
void F_59 ( struct V_75 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_162 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_163 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_60 ( V_14 ) )
continue;
F_56 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_58 ( L_30 , V_3 ) ;
F_3 ( V_3 | V_164 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_58 ( L_30 , V_3 ) ;
}
static void F_61 ( struct V_155 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_89 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_165 ) {
V_7 -> V_166 = 255 ;
F_62 ( V_7 , V_63 ,
L_31 ) ;
}
}
static unsigned int F_63 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_167 V_168 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_169 ) ;
V_168 . V_170 = ( V_3 >> 24 ) & 0xff ;
V_168 . V_171 = ( V_3 >> 16 ) & 0xff ;
V_168 . V_172 = ( V_3 >> 8 ) & 0xff ;
V_168 . V_173 = ( V_3 ) & 0xff ;
return F_64 ( & V_168 ) ;
}
void F_65 ( struct V_94 * V_95 , unsigned int V_174 ,
T_2 V_175 )
{
T_5 V_176 ;
V_176 = V_95 -> V_176 + V_174 * V_177 ;
V_95 -> V_178 [ V_174 ] . V_175 = F_66 ( V_175 ) ;
V_95 -> V_178 [ V_174 ] . V_179 = 0 ;
V_95 -> V_178 [ V_174 ] . V_180 = F_66 ( V_176 & 0xffffffff ) ;
V_95 -> V_178 [ V_174 ] . V_181 = F_66 ( ( V_176 >> 16 ) >> 16 ) ;
}
int F_67 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_179 = F_2 ( V_22 + V_182 ) & 0xFF ;
T_2 V_3 ;
int V_183 , V_124 ;
V_124 = F_29 ( V_14 ) ;
if ( V_124 )
goto V_184;
V_183 = V_179 & ( V_185 | V_186 ) ;
if ( ! V_183 && ! F_68 ( V_14 ) ) {
V_124 = 0 ;
goto V_184;
}
if ( ! ( V_16 -> V_19 & V_187 ) ) {
V_124 = - V_188 ;
goto V_184;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_189 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_124 = 0 ;
V_3 = F_30 ( V_14 , V_22 + V_23 ,
V_189 , V_189 , 1 , 500 ) ;
if ( V_3 & V_189 )
V_124 = - V_93 ;
V_184:
F_28 ( V_14 ) ;
return V_124 ;
}
static int F_69 ( struct V_13 * V_14 , int V_126 ,
struct V_167 * V_168 , int V_190 , T_7 V_28 ,
unsigned long V_191 )
{
const T_2 V_192 = 5 ;
struct V_94 * V_95 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_193 = V_95 -> V_194 ;
T_2 V_3 ;
F_70 ( V_168 , V_126 , V_190 , V_193 ) ;
F_65 ( V_95 , 0 , V_192 | V_28 | ( V_126 << 12 ) ) ;
F_3 ( 1 , V_22 + V_195 ) ;
if ( V_191 ) {
V_3 = F_30 ( V_14 , V_22 + V_195 ,
0x1 , 0x1 , 1 , V_191 ) ;
if ( V_3 & 0x1 ) {
F_67 ( V_14 ) ;
return - V_46 ;
}
} else
F_2 ( V_22 + V_195 ) ;
return 0 ;
}
int F_71 ( struct V_88 * V_89 , unsigned int * V_196 ,
int V_126 , unsigned long V_197 ,
int (* F_72)( struct V_88 * V_89 ) )
{
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
const char * V_198 = NULL ;
unsigned long V_199 , V_200 ;
struct V_167 V_168 ;
int V_124 ;
F_73 ( L_32 ) ;
V_124 = F_67 ( V_14 ) ;
if ( V_124 && V_124 != - V_188 )
F_74 ( V_89 , V_42 ,
L_33 , V_124 ) ;
F_75 ( V_89 -> V_6 , & V_168 ) ;
V_200 = 0 ;
V_199 = V_137 ;
if ( F_76 ( V_197 , V_199 ) )
V_200 = F_77 ( V_197 - V_199 ) ;
V_168 . V_201 |= V_202 ;
if ( F_69 ( V_14 , V_126 , & V_168 , 0 ,
V_203 | V_204 , V_200 ) ) {
V_124 = - V_93 ;
V_198 = L_34 ;
goto V_205;
}
F_36 ( V_14 , 1 ) ;
V_168 . V_201 &= ~ V_202 ;
F_69 ( V_14 , V_126 , & V_168 , 0 , 0 , 0 ) ;
V_124 = F_78 ( V_89 , V_197 , F_72 ) ;
if ( V_124 == - V_46 && V_16 -> V_28 & V_206 ) {
F_74 ( V_89 , V_63 ,
L_35 ) ;
* V_196 = V_207 ;
} else if ( V_124 ) {
V_198 = L_36 ;
goto V_205;
} else
* V_196 = F_63 ( V_14 ) ;
F_73 ( L_37 , * V_196 ) ;
return 0 ;
V_205:
F_74 ( V_89 , V_133 , L_38 , V_198 ) ;
return V_124 ;
}
int F_79 ( struct V_88 * V_89 )
{
void T_1 * V_22 = F_12 ( V_89 -> V_14 ) ;
T_6 V_179 = F_2 ( V_22 + V_182 ) & 0xFF ;
return F_80 ( V_179 ) ;
}
static int F_81 ( struct V_88 * V_89 , unsigned int * V_196 ,
unsigned long V_197 )
{
int V_126 = F_82 ( V_89 ) ;
F_73 ( L_32 ) ;
return F_71 ( V_89 , V_196 , V_126 , V_197 , F_79 ) ;
}
static int F_83 ( struct V_88 * V_89 , unsigned int * V_196 ,
unsigned long V_197 )
{
const unsigned long * V_208 = F_84 ( & V_89 -> V_209 ) ;
struct V_13 * V_14 = V_89 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
T_6 * V_210 = V_95 -> V_211 + V_212 ;
struct V_167 V_168 ;
bool V_213 ;
int V_124 ;
F_73 ( L_32 ) ;
F_29 ( V_14 ) ;
F_75 ( V_89 -> V_6 , & V_168 ) ;
V_168 . V_214 = 0x80 ;
F_70 ( & V_168 , 0 , 0 , V_210 ) ;
V_124 = F_85 ( V_89 , V_208 , V_197 , & V_213 ,
F_79 ) ;
F_28 ( V_14 ) ;
if ( V_213 )
* V_196 = F_63 ( V_14 ) ;
F_73 ( L_39 , V_124 , * V_196 ) ;
return V_124 ;
}
static void F_86 ( struct V_88 * V_89 , unsigned int * V_196 )
{
struct V_13 * V_14 = V_89 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_215 , V_3 ;
F_87 ( V_89 , V_196 ) ;
V_215 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_196 == V_216 )
V_215 |= V_217 ;
else
V_215 &= ~ V_217 ;
if ( V_215 != V_3 ) {
F_3 ( V_215 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_88 ( struct V_218 * V_219 , void * V_194 )
{
struct V_220 * V_221 ;
struct V_222 * V_222 = V_194 + V_223 ;
unsigned int V_224 ;
F_58 ( L_32 ) ;
F_89 (qc->sg, sg, qc->n_elem, si) {
T_5 V_225 = F_90 ( V_221 ) ;
T_2 V_226 = F_91 ( V_221 ) ;
V_222 [ V_224 ] . V_225 = F_66 ( V_225 & 0xffffffff ) ;
V_222 [ V_224 ] . V_227 = F_66 ( ( V_225 >> 16 ) >> 16 ) ;
V_222 [ V_224 ] . V_228 = F_66 ( V_226 - 1 ) ;
}
return V_224 ;
}
static int F_92 ( struct V_218 * V_219 )
{
struct V_13 * V_14 = V_219 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
if ( ! F_68 ( V_14 ) || V_95 -> V_229 )
return F_93 ( V_219 ) ;
else
return F_94 ( V_219 ) ;
}
static void F_95 ( struct V_218 * V_219 )
{
struct V_13 * V_14 = V_219 -> V_14 ;
struct V_94 * V_95 = V_14 -> V_18 ;
int V_230 = F_96 ( V_219 -> V_168 . V_231 ) ;
void * V_194 ;
T_2 V_175 ;
const T_2 V_192 = 5 ;
unsigned int V_232 ;
V_194 = V_95 -> V_194 + V_219 -> V_174 * V_177 ;
F_70 ( & V_219 -> V_168 , V_219 -> V_7 -> V_89 -> V_126 , 1 , V_194 ) ;
if ( V_230 ) {
memset ( V_194 + V_233 , 0 , 32 ) ;
memcpy ( V_194 + V_233 , V_219 -> V_234 , V_219 -> V_7 -> V_235 ) ;
}
V_232 = 0 ;
if ( V_219 -> V_28 & V_236 )
V_232 = F_88 ( V_219 , V_194 ) ;
V_175 = V_192 | V_232 << 16 | ( V_219 -> V_7 -> V_89 -> V_126 << 12 ) ;
if ( V_219 -> V_168 . V_28 & V_237 )
V_175 |= V_238 ;
if ( V_230 )
V_175 |= V_239 | V_240 ;
F_65 ( V_95 , V_219 -> V_174 , V_175 ) ;
}
static void F_97 ( struct V_13 * V_14 )
{
struct V_94 * V_95 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_241 = F_2 ( V_22 + V_242 ) ;
int V_243 = 3 ;
F_73 ( L_32 ) ;
F_98 ( ! V_95 -> V_229 ) ;
F_3 ( V_241 | V_244 , V_22 + V_242 ) ;
V_241 = F_2 ( V_22 + V_242 ) ;
while ( ( V_241 & V_244 ) && V_243 -- ) {
F_99 ( 1 ) ;
V_241 = F_2 ( V_22 + V_242 ) ;
}
if ( V_241 & V_244 )
F_21 ( V_133 , V_14 -> V_17 -> V_7 ,
L_40 ) ;
}
static void F_100 ( struct V_13 * V_14 , T_2 V_245 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_246 * V_247 = & V_14 -> V_89 . V_248 ;
struct V_88 * V_89 = NULL ;
struct V_218 * V_249 ;
struct V_246 * V_250 ;
bool V_251 = false ;
T_2 V_252 ;
if ( V_95 -> V_229 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_241 = F_2 ( V_22 + V_242 ) ;
int V_126 = V_241 >> V_253 ;
if ( ( V_241 & V_254 ) && ( V_126 < V_14 -> V_255 ) &&
F_101 ( & V_14 -> V_256 [ V_126 ] ) ) {
V_89 = & V_14 -> V_256 [ V_126 ] ;
V_251 = true ;
}
} else
F_39 (link, ap, EDGE)
if ( F_102 ( V_89 ) )
break;
if ( ! V_89 )
V_89 = & V_14 -> V_89 ;
V_249 = F_103 ( V_14 , V_89 -> V_257 ) ;
V_250 = & V_89 -> V_248 ;
F_104 ( V_247 ) ;
F_105 ( V_247 , L_41 , V_245 ) ;
F_26 ( & V_14 -> V_89 , V_82 , & V_252 ) ;
F_27 ( & V_14 -> V_89 , V_82 , V_252 ) ;
V_247 -> V_252 |= V_252 ;
if ( V_16 -> V_28 & V_258 )
V_245 &= ~ V_259 ;
if ( V_245 & V_260 ) {
if ( V_249 )
V_249 -> V_261 |= V_262 ;
else
V_250 -> V_261 |= V_262 ;
if ( V_16 -> V_28 & V_263 )
V_247 -> V_252 &= ~ V_264 ;
}
if ( V_245 & V_265 ) {
T_2 * V_266 = ( T_2 * ) ( V_95 -> V_211 + V_267 ) ;
V_250 -> V_261 |= V_268 ;
V_250 -> V_269 |= V_270 ;
F_105 ( V_250 ,
L_42 ,
V_266 [ 0 ] , V_266 [ 1 ] , V_266 [ 2 ] , V_266 [ 3 ] ) ;
}
if ( F_68 ( V_14 ) && ( V_245 & V_271 ) ) {
V_250 -> V_261 |= V_268 ;
V_250 -> V_269 |= V_270 ;
F_105 ( V_250 , L_43 ) ;
}
if ( V_245 & ( V_272 | V_273 ) ) {
V_247 -> V_261 |= V_274 ;
V_247 -> V_269 |= V_270 ;
F_105 ( V_247 , L_44 ) ;
}
if ( V_245 & V_259 ) {
if ( V_251 )
V_250 -> V_261 |= V_262 ;
else {
V_247 -> V_261 |= V_275 ;
V_247 -> V_269 |= V_270 ;
}
F_105 ( V_247 , L_45 ) ;
}
if ( V_245 & ( V_276 | V_114 ) ) {
F_106 ( V_247 ) ;
F_105 ( V_247 , L_46 ,
V_245 & V_276 ?
L_47 : L_48 ) ;
}
if ( V_245 & V_277 )
F_107 ( V_14 ) ;
else if ( V_251 ) {
F_108 ( V_89 ) ;
F_97 ( V_14 ) ;
} else
F_109 ( V_14 ) ;
}
static void F_110 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_246 * V_278 = & V_14 -> V_89 . V_248 ;
struct V_94 * V_95 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_279 = ! ! ( V_14 -> V_280 & V_281 ) ;
T_2 V_179 , V_282 = 0 ;
int V_124 ;
V_179 = F_2 ( V_22 + V_160 ) ;
F_3 ( V_179 , V_22 + V_160 ) ;
if ( F_111 ( V_279 ) )
V_179 &= ~ V_271 ;
if ( V_14 -> V_89 . V_283 > V_112 ) {
V_179 &= ~ V_114 ;
F_27 ( & V_14 -> V_89 , V_82 , V_284 ) ;
}
if ( F_111 ( V_179 & V_285 ) ) {
F_100 ( V_14 , V_179 ) ;
return;
}
if ( V_179 & V_286 ) {
if ( V_16 -> V_19 & V_69 )
F_112 ( V_14 ) ;
else {
if ( V_95 -> V_229 )
F_113 ( 1 ) ;
else {
const T_8 * V_287 = V_95 -> V_211 + V_288 ;
T_2 V_289 = F_114 ( V_287 [ 0 ] ) ;
if ( V_289 & ( 1 << 15 ) )
F_112 ( V_14 ) ;
}
}
}
if ( V_95 -> V_229 ) {
if ( V_14 -> V_282 ) {
V_282 = F_2 ( V_22 + V_85 ) ;
V_282 |= F_2 ( V_22 + V_195 ) ;
}
} else {
if ( V_14 -> V_282 && V_95 -> V_290 -> V_291 )
V_282 = F_2 ( V_22 + V_85 ) ;
else
V_282 = F_2 ( V_22 + V_195 ) ;
}
V_124 = F_115 ( V_14 , V_282 ) ;
if ( F_111 ( V_124 < 0 && ! V_279 ) ) {
V_278 -> V_261 |= V_268 ;
V_278 -> V_269 |= V_270 ;
F_107 ( V_14 ) ;
}
}
T_9 F_116 ( int V_292 , void * V_293 )
{
struct V_75 * V_17 = V_293 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_294 = 0 ;
void T_1 * V_1 ;
T_2 V_245 , V_295 ;
F_58 ( L_32 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_245 = F_2 ( V_1 + V_161 ) ;
if ( ! V_245 )
return V_296 ;
V_295 = V_245 & V_16 -> V_54 ;
F_117 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_162 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_295 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_163 [ V_2 ] ;
if ( V_14 ) {
F_110 ( V_14 ) ;
F_58 ( L_49 , V_2 ) ;
} else {
F_58 ( L_50 , V_2 ) ;
if ( F_118 () )
F_21 ( V_42 , V_17 -> V_7 ,
L_51 , V_2 ) ;
}
V_294 = 1 ;
}
F_3 ( V_245 , V_1 + V_161 ) ;
F_119 ( & V_17 -> V_30 ) ;
F_58 ( L_52 ) ;
return F_120 ( V_294 ) ;
}
static unsigned int F_121 ( struct V_218 * V_219 )
{
struct V_13 * V_14 = V_219 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_94 * V_95 = V_14 -> V_18 ;
V_95 -> V_290 = V_219 -> V_7 -> V_89 ;
if ( V_219 -> V_168 . V_231 == V_297 )
F_3 ( 1 << V_219 -> V_174 , V_22 + V_85 ) ;
if ( V_95 -> V_229 && V_95 -> V_298 != V_219 -> V_7 -> V_89 -> V_126 ) {
T_2 V_241 = F_2 ( V_22 + V_242 ) ;
V_241 &= ~ ( V_299 | V_244 ) ;
V_241 |= V_219 -> V_7 -> V_89 -> V_126 << V_300 ;
F_3 ( V_241 , V_22 + V_242 ) ;
V_95 -> V_298 = V_219 -> V_7 -> V_89 -> V_126 ;
}
F_3 ( 1 << V_219 -> V_174 , V_22 + V_195 ) ;
F_44 ( V_219 -> V_7 -> V_89 ) ;
return 0 ;
}
static bool F_122 ( struct V_218 * V_219 )
{
struct V_94 * V_95 = V_219 -> V_14 -> V_18 ;
T_6 * V_211 = V_95 -> V_211 ;
if ( V_95 -> V_229 )
V_211 += V_219 -> V_7 -> V_89 -> V_126 * V_301 ;
if ( V_219 -> V_168 . V_231 == V_302 && V_219 -> V_303 == V_304 &&
! ( V_219 -> V_28 & V_305 ) ) {
F_123 ( V_211 + V_306 , & V_219 -> V_307 ) ;
V_219 -> V_307 . V_214 = ( V_211 + V_306 ) [ 15 ] ;
} else
F_123 ( V_211 + V_212 , & V_219 -> V_307 ) ;
return true ;
}
static void F_124 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
F_3 ( 0 , V_22 + V_115 ) ;
}
static void F_125 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
struct V_94 * V_95 = V_14 -> V_18 ;
V_3 = F_2 ( V_22 + V_160 ) ;
F_3 ( V_3 , V_22 + V_160 ) ;
F_3 ( 1 << V_14 -> V_142 , V_1 + V_161 ) ;
F_3 ( V_95 -> V_113 , V_22 + V_115 ) ;
}
static void F_126 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_280 & V_308 ) ) {
F_29 ( V_14 ) ;
F_28 ( V_14 ) ;
}
F_127 ( V_14 ) ;
if ( ! F_128 ( V_14 -> V_89 . V_6 ) )
F_29 ( V_14 ) ;
}
static void F_129 ( struct V_218 * V_219 )
{
struct V_13 * V_14 = V_219 -> V_14 ;
if ( V_219 -> V_28 & V_305 )
F_67 ( V_14 ) ;
}
static void F_130 ( struct V_13 * V_14 )
{
struct V_94 * V_95 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_241 ;
int V_124 ;
if ( ! V_95 -> V_309 )
return;
V_241 = F_2 ( V_22 + V_242 ) ;
if ( V_241 & V_310 ) {
V_95 -> V_229 = true ;
V_95 -> V_298 = - 1 ;
return;
}
V_124 = F_29 ( V_14 ) ;
if ( V_124 )
return;
F_3 ( V_241 | V_310 , V_22 + V_242 ) ;
V_241 = F_2 ( V_22 + V_242 ) ;
if ( V_241 & V_310 ) {
F_21 ( V_63 , V_14 -> V_17 -> V_7 , L_53 ) ;
V_95 -> V_229 = true ;
V_95 -> V_298 = - 1 ;
} else
F_21 ( V_133 , V_14 -> V_17 -> V_7 , L_54 ) ;
F_28 ( V_14 ) ;
}
static void F_131 ( struct V_13 * V_14 )
{
struct V_94 * V_95 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_241 ;
int V_124 ;
if ( ! V_95 -> V_309 )
return;
V_241 = F_2 ( V_22 + V_242 ) ;
if ( ( V_241 & V_310 ) == 0 ) {
V_95 -> V_229 = false ;
return;
}
V_124 = F_29 ( V_14 ) ;
if ( V_124 )
return;
F_3 ( V_241 & ~ V_310 , V_22 + V_242 ) ;
V_241 = F_2 ( V_22 + V_242 ) ;
if ( V_241 & V_310 )
F_21 ( V_133 , V_14 -> V_17 -> V_7 , L_55 ) ;
else {
F_21 ( V_63 , V_14 -> V_17 -> V_7 , L_56 ) ;
V_95 -> V_229 = false ;
}
F_28 ( V_14 ) ;
}
static void F_132 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_94 * V_95 = V_14 -> V_18 ;
T_2 V_104 ;
V_104 = F_2 ( V_22 + V_23 ) ;
V_104 |= V_311 ;
F_3 ( V_104 , V_22 + V_23 ) ;
F_130 ( V_14 ) ;
V_95 -> V_113 |= V_271 ;
if ( ! ( V_14 -> V_280 & V_308 ) )
F_3 ( V_95 -> V_113 , V_22 + V_115 ) ;
}
static void F_133 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_94 * V_95 = V_14 -> V_18 ;
T_2 V_104 ;
F_131 ( V_14 ) ;
V_104 = F_2 ( V_22 + V_23 ) ;
V_104 &= ~ V_311 ;
F_3 ( V_104 , V_22 + V_23 ) ;
V_95 -> V_113 &= ~ V_271 ;
if ( ! ( V_14 -> V_280 & V_308 ) )
F_3 ( V_95 -> V_113 , V_22 + V_115 ) ;
}
int F_134 ( struct V_13 * V_14 )
{
F_33 ( V_14 ) ;
F_38 ( V_14 ) ;
if ( F_68 ( V_14 ) )
F_132 ( V_14 ) ;
else
F_133 ( V_14 ) ;
return 0 ;
}
static int F_135 ( struct V_13 * V_14 , T_10 V_312 )
{
const char * V_130 = NULL ;
int V_124 ;
V_124 = F_42 ( V_14 , & V_130 ) ;
if ( V_124 == 0 )
F_37 ( V_14 ) ;
else {
F_17 ( V_14 , V_133 , L_27 , V_130 , V_124 ) ;
F_38 ( V_14 ) ;
}
return V_124 ;
}
static int F_136 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_94 * V_95 ;
void * V_313 ;
T_5 V_314 ;
T_4 V_315 , V_316 ;
V_95 = F_137 ( V_7 , sizeof( * V_95 ) , V_317 ) ;
if ( ! V_95 )
return - V_318 ;
if ( ( V_16 -> V_19 & V_71 ) && F_138 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_104 = F_2 ( V_22 + V_23 ) ;
if ( V_104 & V_319 )
V_95 -> V_309 = true ;
else if ( V_16 -> V_28 & V_72 ) {
F_21 ( V_63 , V_7 ,
L_57 ,
V_14 -> V_142 ) ;
V_95 -> V_309 = true ;
} else
F_21 ( V_42 , V_7 ,
L_58 ,
V_14 -> V_142 ) ;
}
if ( V_95 -> V_309 ) {
V_315 = V_320 ;
V_316 = V_301 * 16 ;
} else {
V_315 = V_321 ;
V_316 = V_301 ;
}
V_313 = F_139 ( V_7 , V_315 , & V_314 , V_317 ) ;
if ( ! V_313 )
return - V_318 ;
memset ( V_313 , 0 , V_315 ) ;
V_95 -> V_178 = V_313 ;
V_95 -> V_96 = V_314 ;
V_313 += V_322 ;
V_314 += V_322 ;
V_95 -> V_211 = V_313 ;
V_95 -> V_99 = V_314 ;
V_313 += V_316 ;
V_314 += V_316 ;
V_95 -> V_194 = V_313 ;
V_95 -> V_176 = V_314 ;
V_95 -> V_113 = V_323 ;
V_14 -> V_18 = V_95 ;
return F_134 ( V_14 ) ;
}
static void F_140 ( struct V_13 * V_14 )
{
const char * V_130 = NULL ;
int V_124 ;
V_124 = F_42 ( V_14 , & V_130 ) ;
if ( V_124 )
F_17 ( V_14 , V_42 , L_27 , V_130 , V_124 ) ;
}
void F_141 ( struct V_75 * V_17 , const char * V_324 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_53 , V_19 , V_20 , V_325 , V_326 ;
const char * V_327 ;
V_53 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_325 = V_16 -> V_54 ;
V_326 = ( V_19 >> 20 ) & 0xf ;
if ( V_326 == 1 )
V_327 = L_59 ;
else if ( V_326 == 2 )
V_327 = L_60 ;
else if ( V_326 == 3 )
V_327 = L_61 ;
else
V_327 = L_62 ;
F_142 ( V_17 -> V_7 ,
L_63
L_64
,
( V_53 >> 24 ) & 0xff ,
( V_53 >> 16 ) & 0xff ,
( V_53 >> 8 ) & 0xff ,
V_53 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_327 ,
V_325 ,
V_324 ) ;
F_142 ( V_17 -> V_7 ,
L_65
L_66
L_66
L_67
,
V_19 & V_61 ? L_68 : L_6 ,
V_19 & V_64 ? L_69 : L_6 ,
V_19 & V_69 ? L_70 : L_6 ,
V_19 & V_328 ? L_71 : L_6 ,
V_19 & V_106 ? L_72 : L_6 ,
V_19 & V_116 ? L_73 : L_6 ,
V_19 & V_329 ? L_5 : L_6 ,
V_19 & V_187 ? L_74 : L_6 ,
V_19 & V_330 ? L_75 : L_6 ,
V_19 & V_67 ? L_76 : L_6 ,
V_19 & V_71 ? L_77 : L_6 ,
V_19 & V_331 ? L_78 : L_6 ,
V_19 & V_332 ? L_79 : L_6 ,
V_19 & V_333 ? L_80 : L_6 ,
V_19 & V_334 ? L_81 : L_6 ,
V_19 & V_335 ? L_82 : L_6 ,
V_19 & V_336 ? L_83 : L_6 ,
V_20 & V_337 ? L_84 : L_6 ,
V_20 & V_338 ? L_85 : L_6 ,
V_20 & V_339 ? L_86 : L_6
) ;
}
void F_143 ( struct V_15 * V_16 ,
struct V_340 * V_341 )
{
T_6 V_342 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_343 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_344 || ! ( V_16 -> V_19 & V_335 ) )
return;
V_342 = ( V_26 & V_345 ) >> 16 ;
if ( V_342 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_342 ;
V_341 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_346 ) )
V_341 -> V_28 |= V_129 ;
}
}
